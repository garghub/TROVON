static int F_1 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 )
{
int V_5 ;
unsigned char * V_6 = V_3 ;
V_5 = F_2 ( & V_2 -> V_7 , V_6 + V_8 ,
V_4 - V_8 , & V_2 -> V_9 ) ;
V_6 [ 0 ] = V_10 ;
V_6 [ 1 ] = V_11 ;
F_3 ( V_5 , & V_6 [ 2 ] ) ;
return V_5 + V_8 ;
}
static int F_4 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
if ( V_15 -> V_16 == 0 ) {
F_5 ( & V_13 -> V_17 -> V_18 ,
L_1 ) ;
return - V_19 ;
}
return 1 ;
}
static int F_6 ( struct V_1 * V_2 ,
int V_20 , char * V_21 , int V_22 )
{
if ( V_20 ) {
V_22 -= V_8 ;
V_21 += V_8 ;
}
if ( V_22 <= 0 ) {
F_5 ( & V_2 -> V_18 , L_2 , V_23 ) ;
return 0 ;
}
F_7 ( & V_2 -> V_2 , V_21 , V_22 ) ;
return V_22 ;
}
static void F_8 ( struct V_24 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
char * V_26 = ( char * ) V_24 -> V_27 ;
int V_20 ;
int V_5 ;
int V_22 ;
int V_28 ;
V_20 = ( V_24 -> V_29 > 2 && V_26 [ 0 ] == V_30 ) ;
V_5 = 0 ;
for ( V_28 = 0 ; V_28 < V_24 -> V_29 ; V_28 += V_31 ) {
V_22 = F_9 ( int , V_24 -> V_29 - V_28 , V_31 ) ;
V_5 += F_6 ( V_2 , V_20 ,
& V_26 [ V_28 ] , V_22 ) ;
}
if ( V_5 )
F_10 ( & V_2 -> V_2 ) ;
}
