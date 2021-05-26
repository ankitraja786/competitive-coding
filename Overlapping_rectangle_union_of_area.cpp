#define MAX 1000
//https://www.hackerearth.com/practice/math/geometry/line-sweep-technique/tutorial/
struct event 
{
    int ind; // Index of rectangle in rects
    bool type; // Type of event: 0 = Lower-left ; 1 = Upper-right
    event() {};
    event(int ind, int type) : ind(ind), type(type) {};
};
struct point 
{
    int x, y;
};
point rects [MAX][12]; // Each rectangle consists of 2 points: [0] = lower-left ; [1] = upper-right
bool compare_x(event a, event b) { return rects[a.ind][a.type].x<rects[b.ind][b.type].x; }
bool compare_y(event a, event b) { return rects[a.ind][a.type].y<rects[b.ind][b.type].y; }
int union_area(event events_v[],event events_h[],int n,int e)
{
       //n is the number of rectangles, e=2*n , e is the number of points (each rectangle has two points as described in declaration of rects)
        bool in_set[MAX]={0};int area=0;
        sort(events_v, events_v+e, compare_x);  //Pre-sort of vertical edges
        sort(events_h, events_h+e, compare_y); // Pre-sort set of horizontal edges
        in_set[events_v[0].ind] = 1;
        for (int i=1;i<e;++i) 
        { // Vertical sweep line
                event c = events_v[i];
                int cnt = 0; // Counter to indicate how many rectangles are currently overlapping
                // Delta_x: Distance between current sweep line and previous sweep line
                int delta_x = rects[c.ind][c.type].x - rects[events_v[i-1].ind][events_v[i-1].type].x;
                int begin_y;
                if (delta_x==0){
                        in_set[c.ind] = (c.type==0);
                        continue;
                }
                for (int j=0;j<e;++j)
                        if (in_set[events_h[j].ind]==1)                 //Horizontal sweep line for active rectangle
                        {
                                if (events_h[j].type==0)                //If it is a bottom edge of rectangle
                                {
                                        if (cnt==0) begin_y = rects[events_h[j].ind][0].y; // Block starts
                                        ++cnt;                          //incrementing number of overlapping rectangles
                                }
                                else                                    //If it is a top edge
                                {
                                        --cnt;                          //the rectangle is no more overlapping, so remove it
                                        if (cnt==0)                     //Block ends
                                        {
                                                int delta_y = (rects[events_h[j].ind][13].y-begin_y);//length of the vertical sweep line cut by rectangles
                                                area+=delta_x * delta_y;
                                        }
                                }
                        }
                in_set[c.ind] = (c.type==0);//If it is a left edge, the rectangle is in the active set else not
        }
    return area;
}