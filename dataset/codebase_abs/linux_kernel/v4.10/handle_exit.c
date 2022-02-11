static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
F_2 ( * F_3 ( V_2 ) , * F_4 ( V_2 , 0 ) ,
F_5 ( V_2 ) ) ;
V_2 -> V_6 . V_7 ++ ;
V_5 = F_6 ( V_2 ) ;
if ( V_5 < 0 ) {
F_7 ( V_2 ) ;
return 1 ;
}
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_7 ( V_2 ) ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_10 ( V_2 ) & V_8 ) {
F_11 ( * F_3 ( V_2 ) , true ) ;
V_2 -> V_6 . V_9 ++ ;
F_12 ( V_2 ) ;
} else {
F_11 ( * F_3 ( V_2 ) , false ) ;
V_2 -> V_6 . V_10 ++ ;
F_13 ( V_2 ) ;
}
F_14 ( V_2 , F_15 ( V_2 ) ) ;
return 1 ;
}
static T_1 F_16 ( struct V_1 * V_2 )
{
T_2 V_11 = F_17 ( V_2 ) ;
if ( V_11 >= F_18 ( V_12 ) ||
! V_12 [ V_11 ] ) {
F_19 ( L_1 ,
( unsigned int ) F_10 ( V_2 ) ) ;
F_20 () ;
}
return V_12 [ V_11 ] ;
}
int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_13 )
{
T_1 V_14 ;
if ( F_22 ( V_13 ) ) {
T_2 V_11 = F_17 ( V_2 ) ;
if ( V_11 == V_15 || V_11 == V_16 ) {
T_3 V_17 = F_15 ( V_2 ) ? 4 : 2 ;
* F_3 ( V_2 ) -= V_17 ;
}
F_23 ( V_2 ) ;
return 1 ;
}
V_13 = F_24 ( V_13 ) ;
switch ( V_13 ) {
case V_18 :
return 1 ;
case V_19 :
if ( ! F_25 ( V_2 ) ) {
F_14 ( V_2 , F_15 ( V_2 ) ) ;
return 1 ;
}
V_14 = F_16 ( V_2 ) ;
return V_14 ( V_2 , V_4 ) ;
case V_20 :
F_23 ( V_2 ) ;
return 1 ;
default:
F_26 ( L_2 ,
V_13 ) ;
V_4 -> V_21 = V_22 ;
return 0 ;
}
}
