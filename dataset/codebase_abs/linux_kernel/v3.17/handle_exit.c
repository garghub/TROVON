static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( L_1 ) ;
F_3 () ;
return - V_5 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_6 ;
F_5 ( * F_6 ( V_2 ) , * F_7 ( V_2 , 0 ) ,
F_8 ( V_2 ) ) ;
V_6 = F_9 ( V_2 ) ;
if ( V_6 < 0 ) {
F_10 ( V_2 ) ;
return 1 ;
}
return V_6 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_10 ( V_2 ) ;
return 1 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_13 ( L_2 ,
F_14 ( V_2 ) , F_15 ( V_2 ) ) ;
return - V_7 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_13 ( L_3 ,
F_14 ( V_2 ) , F_15 ( V_2 ) ) ;
return - V_7 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_18 ( * F_6 ( V_2 ) ) ;
if ( F_15 ( V_2 ) & V_8 )
F_19 ( V_2 ) ;
else
F_20 ( V_2 ) ;
F_21 ( V_2 , F_22 ( V_2 ) ) ;
return 1 ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
T_2 V_9 = F_24 ( V_2 ) ;
if ( V_9 >= F_25 ( V_10 ) ||
! V_10 [ V_9 ] ) {
F_13 ( L_4 ,
( unsigned int ) F_15 ( V_2 ) ) ;
F_3 () ;
}
return V_10 [ V_9 ] ;
}
int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_11 )
{
T_1 V_12 ;
switch ( V_11 ) {
case V_13 :
return 1 ;
case V_14 :
F_13 ( L_5 ,
F_27 ( V_2 ) ) ;
F_3 () ;
F_28 ( L_6 ) ;
case V_15 :
case V_16 :
case V_17 :
if ( ! F_29 ( V_2 ) ) {
F_21 ( V_2 , F_22 ( V_2 ) ) ;
return 1 ;
}
V_12 = F_23 ( V_2 ) ;
return V_12 ( V_2 , V_4 ) ;
default:
F_30 ( L_7 ,
V_11 ) ;
V_4 -> V_18 = V_19 ;
return 0 ;
}
}
