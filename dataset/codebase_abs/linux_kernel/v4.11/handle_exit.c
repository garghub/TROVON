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
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_11 = F_10 ( V_2 ) ;
F_17 ( L_1 ,
V_11 ) ;
F_7 ( V_2 ) ;
return 1 ;
}
static T_2 F_18 ( struct V_1 * V_2 )
{
T_3 V_12 = F_19 ( V_2 ) ;
return V_13 [ V_12 ] ;
}
int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_14 )
{
T_2 V_15 ;
if ( F_21 ( V_14 ) ) {
T_3 V_12 = F_19 ( V_2 ) ;
if ( V_12 == V_16 || V_12 == V_17 ) {
T_1 V_18 = F_15 ( V_2 ) ? 4 : 2 ;
* F_3 ( V_2 ) -= V_18 ;
}
F_22 ( V_2 ) ;
return 1 ;
}
V_14 = F_23 ( V_14 ) ;
switch ( V_14 ) {
case V_19 :
return 1 ;
case V_20 :
if ( ! F_24 ( V_2 ) ) {
F_14 ( V_2 , F_15 ( V_2 ) ) ;
return 1 ;
}
V_15 = F_18 ( V_2 ) ;
return V_15 ( V_2 , V_4 ) ;
case V_21 :
F_22 ( V_2 ) ;
return 1 ;
default:
F_17 ( L_2 ,
V_14 ) ;
V_4 -> V_22 = V_23 ;
return 0 ;
}
}
