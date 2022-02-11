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
static int F_7 ( struct V_28 * V_29 ,
struct V_1 * V_2 , int V_30 ,
char * V_31 , int V_32 )
{
if ( V_30 ) {
V_32 -= V_8 ;
V_31 += V_8 ;
}
if ( V_32 <= 0 ) {
F_6 ( & V_2 -> V_26 , L_3 , V_33 ) ;
return 0 ;
}
F_8 ( V_29 , V_31 , V_32 ) ;
return V_32 ;
}
static void F_9 ( struct V_34 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
char * V_36 = ( char * ) V_34 -> V_37 ;
struct V_28 * V_29 ;
int V_30 ;
int V_5 ;
int V_32 ;
int V_23 ;
V_29 = F_10 ( & V_2 -> V_2 ) ;
if ( ! V_29 )
return;
V_30 = ( V_34 -> V_38 > 2 && V_36 [ 0 ] == V_39 ) ;
V_5 = 0 ;
for ( V_23 = 0 ; V_23 < V_34 -> V_38 ; V_23 += V_40 ) {
V_32 = F_11 ( int , V_34 -> V_38 - V_23 , V_40 ) ;
V_5 += F_7 ( V_29 , V_2 , V_30 ,
& V_36 [ V_23 ] , V_32 ) ;
}
if ( V_5 )
F_12 ( V_29 ) ;
F_13 ( V_29 ) ;
}
