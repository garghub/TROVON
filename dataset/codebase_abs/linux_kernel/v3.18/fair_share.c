static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
unsigned long V_4 ;
enum V_5 V_6 ;
if ( V_2 -> V_7 == 0 || ! V_2 -> V_8 -> V_9 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
V_2 -> V_8 -> V_9 ( V_2 , V_3 , & V_4 ) ;
if ( V_2 -> V_10 < V_4 )
break;
}
if ( V_3 > 0 ) {
V_2 -> V_8 -> V_11 ( V_2 , V_3 - 1 , & V_6 ) ;
F_2 ( V_2 , V_3 - 1 , V_6 ) ;
}
return V_3 ;
}
static long F_3 ( struct V_1 * V_2 ,
struct V_12 * V_13 , int V_14 , int V_15 )
{
unsigned long V_16 ;
V_13 -> V_8 -> V_17 ( V_13 , & V_16 ) ;
return ( long ) ( V_14 * V_15 * V_16 ) / ( 100 * V_2 -> V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_18 )
{
const struct V_19 * V_20 ;
struct V_12 * V_13 ;
struct V_21 * V_22 ;
int V_23 ;
int V_24 = F_1 ( V_2 ) ;
if ( ! V_2 -> V_20 || ! V_2 -> V_20 -> V_25 )
return - V_26 ;
V_20 = V_2 -> V_20 ;
for ( V_23 = 0 ; V_23 < V_20 -> V_27 ; V_23 ++ ) {
if ( ! V_20 -> V_25 [ V_23 ] . V_13 )
continue;
V_13 = V_20 -> V_25 [ V_23 ] . V_13 ;
V_22 = F_5 ( V_2 , V_13 , V_18 ) ;
if ( ! V_22 )
continue;
V_22 -> V_28 = F_3 ( V_2 , V_13 ,
V_20 -> V_25 [ V_23 ] . V_14 , V_24 ) ;
V_22 -> V_13 -> V_29 = false ;
F_6 ( V_13 ) ;
}
return 0 ;
}
int F_7 ( void )
{
return F_8 ( & V_30 ) ;
}
void F_9 ( void )
{
F_10 ( & V_30 ) ;
}
