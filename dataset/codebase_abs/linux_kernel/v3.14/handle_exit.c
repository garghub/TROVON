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
if ( F_15 ( V_2 ) & V_7 )
F_19 ( V_2 ) ;
else
F_20 ( V_2 ) ;
return 1 ;
}
static T_1 F_21 ( struct V_1 * V_2 )
{
T_2 V_8 = F_22 ( V_2 ) ;
if ( V_8 >= F_23 ( V_9 ) ||
! V_9 [ V_8 ] ) {
F_13 ( L_4 ,
( unsigned int ) F_15 ( V_2 ) ) ;
F_3 () ;
}
return V_9 [ V_8 ] ;
}
int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_10 )
{
T_1 V_11 ;
switch ( V_10 ) {
case V_12 :
return 1 ;
case V_13 :
F_13 ( L_5 ,
F_25 ( V_2 ) ) ;
F_3 () ;
F_26 ( L_6 ) ;
case V_14 :
case V_15 :
case V_16 :
if ( ! F_27 ( V_2 ) ) {
F_28 ( V_2 , F_29 ( V_2 ) ) ;
return 1 ;
}
V_11 = F_21 ( V_2 ) ;
return V_11 ( V_2 , V_4 ) ;
default:
F_30 ( L_7 ,
V_10 ) ;
V_4 -> V_17 = V_18 ;
return 0 ;
}
}
