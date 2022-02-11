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
const struct V_14 * V_15 )
{
struct V_16 * V_17 = V_13 -> V_18 ->
V_19 ;
struct V_20 * V_21 ;
int V_22 = 0 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_17 -> V_24 . V_25 ; V_23 ++ ) {
V_21 = & V_17 -> V_21 [ V_23 ] . V_24 ;
if ( F_5 ( V_21 ) ) {
F_6 ( & V_13 -> V_26 -> V_26 ,
L_1 , V_23 ) ;
++ V_22 ;
}
}
if ( V_22 == 0 ) {
F_6 ( & V_13 -> V_26 -> V_26 , L_2 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_28 , char * V_29 , int V_30 )
{
if ( V_28 ) {
V_30 -= V_8 ;
V_29 += V_8 ;
}
if ( V_30 <= 0 ) {
F_6 ( & V_2 -> V_26 , L_3 , V_31 ) ;
return 0 ;
}
F_8 ( & V_2 -> V_2 , V_29 , V_30 ) ;
return V_30 ;
}
static void F_9 ( struct V_32 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_33 ;
char * V_34 = ( char * ) V_32 -> V_35 ;
int V_28 ;
int V_5 ;
int V_30 ;
int V_23 ;
V_28 = ( V_32 -> V_36 > 2 && V_34 [ 0 ] == V_37 ) ;
V_5 = 0 ;
for ( V_23 = 0 ; V_23 < V_32 -> V_36 ; V_23 += V_38 ) {
V_30 = F_10 ( int , V_32 -> V_36 - V_23 , V_38 ) ;
V_5 += F_7 ( V_2 , V_28 ,
& V_34 [ V_23 ] , V_30 ) ;
}
if ( V_5 )
F_11 ( & V_2 -> V_2 ) ;
}
