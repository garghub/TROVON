static inline int F_1 ( void )
{
int V_1 ;
switch ( V_2 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
F_2 ( V_7 , V_1 ) ;
V_1 &= 0xff ;
break;
case V_8 :
V_1 = F_3 ( V_9 ) ;
V_1 &= 0xff ;
break;
case V_10 :
V_11 = 0x20000 ;
( void ) V_11 ;
F_4 () ;
V_1 = F_5 ( ( V_12 * ) V_13 ) ;
F_4 () ;
V_1 &= 0xff ;
V_11 = 0 ;
break;
default:
F_6 ( L_1 ) ;
return - 1 ;
}
return V_1 ;
}
static void F_7 ( void )
{
unsigned int V_14 , V_15 , V_16 , V_17 ;
unsigned int V_18 , V_19 , V_20 , V_21 ;
unsigned int V_22 , V_23 , V_24 ;
struct V_25 * V_26 = F_8 () ;
F_6 ( L_2 ) ;
F_6 ( L_3
L_4 ,
V_26 -> V_27 , V_26 -> V_28 ,
V_26 -> V_29 , V_26 -> V_30 ) ;
switch ( V_2 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
F_9 () ;
break;
case V_8 :
V_22 = F_3 ( V_31 ) ;
V_23 = F_3 ( V_32 ) ;
V_24 = F_3 ( V_33 ) ;
F_6 ( L_5 , V_22 ) ;
F_6 ( L_6 ,
V_24 , V_23 ) ;
break;
case V_10 :
V_17 = V_34 ;
V_18 = V_35 ;
V_19 = V_36 ;
V_20 = V_37 ;
V_21 = V_38 ;
V_14 = V_39 ;
V_15 = V_40 ;
V_16 = V_41 ;
F_6 ( L_7 , V_19 ) ;
F_6 ( L_8 , V_20 ) ;
F_6 ( L_9 , V_21 ) ;
F_6 ( L_10 , V_14 ) ;
F_6 ( L_11 , V_15 ) ;
F_6 ( L_12 , V_16 ) ;
F_6 ( L_13 , V_17 ) ;
F_6 ( L_14 , V_18 ) ;
break;
}
F_10 ( L_15 , V_26 ) ;
}
static T_1 F_11 ( int V_1 , void * V_42 )
{
F_7 () ;
return V_43 ;
}
void T_2 F_12 ( void )
{
int V_44 ;
F_13 ( F_14 ( V_45 , V_45 ,
16 , F_15 () ) < 0 ,
L_16 , V_45 ) ;
F_16 ( F_1 ) ;
F_17 () ;
switch ( V_2 ) {
case V_3 :
case V_4 :
if ( V_46 )
F_18 ( V_47 ,
V_48 , V_49 ,
V_50 ) ;
else
F_18 ( V_47 ,
V_51 , V_52 ,
V_53 ) ;
break;
case V_5 :
case V_6 :
if ( V_46 )
F_18 ( V_54 ,
V_48 , V_49 ,
V_50 ) ;
else
F_18 ( V_54 ,
V_51 , V_52 ,
V_53 ) ;
}
if ( V_55 ) {
V_44 = V_56 + V_57 ;
} else if ( V_46 ) {
F_19 ( V_58 , F_7 ) ;
V_44 = V_48 + V_58 ;
} else {
V_44 = V_56 + V_57 ;
}
F_20 ( V_44 , & V_59 ) ;
}
