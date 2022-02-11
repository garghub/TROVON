bool F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 . V_6 -> V_7 ;
T_1 V_8 [] = { 0x0 , 0x0 } ;
T_1 V_9 [ 2 ] ;
struct V_10 V_11 [] = {
{
. V_12 = V_13 ,
. V_14 = 0 ,
. V_15 = 1 ,
. V_9 = V_8 ,
} ,
{
. V_12 = V_13 ,
. V_14 = V_16 ,
. V_15 = 1 ,
. V_9 = V_9 ,
}
} ;
return F_2 ( F_3 ( V_4 , V_2 ) ,
V_11 , 2 ) == 2 ;
}
int F_4 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_21 ;
int V_22 = 0 ;
V_21 = F_5 ( V_18 , V_20 ) ;
if ( V_21 ) {
F_6 ( V_18 , V_21 ) ;
V_22 = F_7 ( V_18 , V_21 ) ;
F_8 ( V_18 , V_21 ) ;
V_18 -> V_23 . V_24 = NULL ;
F_9 ( V_21 ) ;
}
return V_22 ;
}
void
F_10 ( struct V_17 * V_18 )
{
struct V_25 * V_6 = V_18 -> V_6 ;
struct V_3 * V_4 = V_6 -> V_7 ;
struct V_26 * V_27 ;
V_27 = V_4 -> V_28 ;
if ( V_27 == NULL ) {
V_27 = F_11 ( V_6 , 0 ,
L_1 ,
V_29 ,
F_12 ( V_29 ) ) ;
if ( V_27 == NULL )
return;
V_4 -> V_28 = V_27 ;
}
F_13 ( V_18 , V_27 , 0 ) ;
}
void
F_14 ( struct V_17 * V_18 )
{
struct V_25 * V_6 = V_18 -> V_6 ;
struct V_3 * V_4 = V_6 -> V_7 ;
struct V_26 * V_27 ;
V_27 = V_4 -> V_30 ;
if ( V_27 == NULL ) {
V_27 = F_11 ( V_6 , V_31 ,
L_2 ,
V_32 ,
F_12 ( V_32 ) ) ;
if ( V_27 == NULL )
return;
V_4 -> V_30 = V_27 ;
}
F_13 ( V_18 , V_27 , 0 ) ;
}
