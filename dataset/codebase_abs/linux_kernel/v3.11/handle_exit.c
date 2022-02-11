static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( L_1 ) ;
F_3 () ;
return - V_5 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_5 ( * F_6 ( V_2 ) , * F_7 ( V_2 , 0 ) ,
F_8 ( V_2 ) ) ;
if ( F_9 ( V_2 ) )
return 1 ;
F_10 ( V_2 ) ;
return 1 ;
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
return - V_6 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_13 ( L_3 ,
F_14 ( V_2 ) , F_15 ( V_2 ) ) ;
return - V_6 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_18 ( * F_6 ( V_2 ) ) ;
F_19 ( V_2 ) ;
return 1 ;
}
static T_1 F_20 ( struct V_1 * V_2 )
{
T_2 V_7 = F_21 ( V_2 ) ;
if ( V_7 >= F_22 ( V_8 ) ||
! V_8 [ V_7 ] ) {
F_13 ( L_4 ,
( unsigned int ) F_15 ( V_2 ) ) ;
F_3 () ;
}
return V_8 [ V_7 ] ;
}
int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_9 )
{
T_1 V_10 ;
switch ( V_9 ) {
case V_11 :
return 1 ;
case V_12 :
F_13 ( L_5 ,
F_24 ( V_2 ) ) ;
F_3 () ;
F_25 ( L_6 ) ;
case V_13 :
case V_14 :
case V_15 :
if ( ! F_26 ( V_2 ) ) {
F_27 ( V_2 , F_28 ( V_2 ) ) ;
return 1 ;
}
V_10 = F_20 ( V_2 ) ;
return V_10 ( V_2 , V_4 ) ;
default:
F_29 ( L_7 ,
V_9 ) ;
V_4 -> V_16 = V_17 ;
return 0 ;
}
}
