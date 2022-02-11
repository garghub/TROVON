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
return F_2 ( & V_4 -> V_17 [ V_2 ] . V_18 , V_11 , 2 ) == 2 ;
}
int F_3 ( struct V_19 * V_20 ,
struct V_21 * V_18 )
{
struct V_22 * V_22 ;
int V_23 = 0 ;
V_22 = F_4 ( V_20 , V_18 ) ;
if ( V_22 ) {
F_5 ( V_20 , V_22 ) ;
V_23 = F_6 ( V_20 , V_22 ) ;
F_7 ( V_20 , V_22 ) ;
V_20 -> V_24 . V_25 = NULL ;
F_8 ( V_22 ) ;
}
return V_23 ;
}
void
F_9 ( struct V_19 * V_20 )
{
struct V_26 * V_6 = V_20 -> V_6 ;
struct V_3 * V_4 = V_6 -> V_7 ;
struct V_27 * V_28 ;
V_28 = V_4 -> V_29 ;
if ( V_28 == NULL ) {
V_28 = F_10 ( V_6 , 0 ,
L_1 ,
V_30 ,
F_11 ( V_30 ) ) ;
if ( V_28 == NULL )
return;
V_4 -> V_29 = V_28 ;
}
F_12 ( V_20 , V_28 , 0 ) ;
}
void
F_13 ( struct V_19 * V_20 )
{
struct V_26 * V_6 = V_20 -> V_6 ;
struct V_3 * V_4 = V_6 -> V_7 ;
struct V_27 * V_28 ;
V_28 = V_4 -> V_31 ;
if ( V_28 == NULL ) {
V_28 = F_10 ( V_6 , V_32 ,
L_2 ,
V_33 ,
F_11 ( V_33 ) ) ;
if ( V_28 == NULL )
return;
V_4 -> V_31 = V_28 ;
}
F_12 ( V_20 , V_28 , 0 ) ;
}
