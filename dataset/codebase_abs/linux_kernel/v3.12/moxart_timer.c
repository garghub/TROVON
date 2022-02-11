static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
switch ( V_2 ) {
case V_5 :
case V_6 :
F_2 ( V_7 , V_8 + V_9 ) ;
F_2 ( ~ 0 , V_8 + V_10 + V_11 ) ;
break;
case V_12 :
F_2 ( V_13 , V_8 + V_10 + V_11 ) ;
F_2 ( V_14 , V_8 + V_9 ) ;
break;
case V_15 :
case V_16 :
default:
F_2 ( V_7 , V_8 + V_9 ) ;
break;
}
}
static int F_3 ( unsigned long V_17 ,
struct V_3 * V_18 )
{
T_1 V_19 ;
F_2 ( V_7 , V_8 + V_9 ) ;
V_19 = F_4 ( V_8 + V_10 + V_20 ) - V_17 ;
F_2 ( V_19 , V_8 + V_10 + V_21 ) ;
F_2 ( V_14 , V_8 + V_9 ) ;
return 0 ;
}
static T_2 F_5 ( int V_22 , void * V_23 )
{
struct V_3 * V_24 = V_23 ;
V_24 -> V_25 ( V_24 ) ;
return V_26 ;
}
static void T_3 F_6 ( struct V_27 * V_28 )
{
int V_29 , V_22 ;
unsigned long V_30 ;
struct V_4 * V_4 ;
V_8 = F_7 ( V_28 , 0 ) ;
if ( ! V_8 )
F_8 ( L_1 , V_28 -> V_31 ) ;
V_22 = F_9 ( V_28 , 0 ) ;
if ( V_22 <= 0 )
F_8 ( L_2 , V_28 -> V_31 ) ;
V_29 = F_10 ( V_22 , & V_32 ) ;
if ( V_29 )
F_8 ( L_3 , V_28 -> V_31 ) ;
V_4 = F_11 ( V_28 , 0 ) ;
if ( F_12 ( V_4 ) )
F_8 ( L_4 , V_28 -> V_31 ) ;
V_30 = F_13 ( V_4 ) ;
if ( F_14 ( V_8 + V_33 + V_20 ,
L_5 , V_30 , 200 , 32 ,
V_34 ) )
F_8 ( L_6 , V_28 -> V_31 ) ;
V_13 = F_15 ( V_30 , V_35 ) ;
F_2 ( ~ 0 , V_8 + V_33 + V_11 ) ;
F_2 ( V_36 , V_8 + V_9 ) ;
V_37 . V_38 = F_16 ( 0 ) ;
V_37 . V_22 = V_22 ;
F_17 ( & V_37 , V_30 ,
0x4 , 0xfffffffe ) ;
}
