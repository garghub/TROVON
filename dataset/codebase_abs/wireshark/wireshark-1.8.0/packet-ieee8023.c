void
F_1 ( volatile int V_1 , T_1 V_2 , T_2 * V_3 ,
int V_4 , T_3 * V_5 , T_4 * V_6 ,
T_4 * V_7 , int V_8 , int V_9 ,
int V_10 )
{
T_5 * V_11 ;
T_2 * volatile V_12 = NULL ;
T_2 * volatile V_13 = NULL ;
const char * V_14 ;
T_6 V_15 , V_16 ;
void * V_17 ;
V_11 = F_2 ( V_7 , V_8 , V_3 ,
V_4 - 2 , 2 , V_1 ) ;
V_16 = F_3 ( V_3 , V_4 ) ;
if ( V_10 > 0 ) {
if ( V_16 >= V_10 )
V_16 -= V_10 ;
}
if ( V_1 > V_16 ) {
V_1 = V_16 ;
F_4 ( V_5 , V_11 , V_18 , V_19 ,
L_1 ) ;
}
V_15 = F_5 ( V_3 , V_4 ) ;
if ( V_15 > V_1 )
V_15 = V_1 ;
V_12 = F_6 ( V_3 , V_4 , V_15 , V_1 ) ;
F_7 {
V_13 = F_8 ( V_3 , V_4 + V_1 ) ;
}
F_9 (BoundsError, ReportedBoundsError) {
V_13 = NULL ;
}
V_20 ;
V_14 = V_5 -> V_21 ;
V_17 = V_5 -> V_22 ;
F_7 {
if ( V_2 )
F_10 ( V_23 , V_12 , V_5 , V_6 ) ;
else {
if ( F_11 ( V_12 , 0 , 3 ) == 7 )
F_10 ( V_24 , V_12 , V_5 , V_6 ) ;
else
F_10 ( V_25 , V_12 , V_5 , V_6 ) ;
}
}
F_12 (BoundsError) {
V_26 ;
}
F_13 {
V_5 -> V_22 = V_17 ;
F_14 ( V_12 , V_5 , V_6 , V_27 , V_28 ) ;
V_5 -> V_21 = V_14 ;
}
V_20 ;
F_15 ( V_5 , V_6 , V_7 , V_9 , V_3 , V_13 , V_10 ) ;
}
void
F_16 ( void )
{
V_24 = F_17 ( L_2 ) ;
V_23 = F_17 ( L_3 ) ;
V_25 = F_17 ( L_4 ) ;
}
