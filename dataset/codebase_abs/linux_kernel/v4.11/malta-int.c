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
static void F_12 ( void )
{
F_13 ( V_44 + V_45 ) ;
}
static void F_14 ( void )
{
F_13 ( V_44 + V_46 ) ;
}
static T_1 F_15 ( int V_1 , void * V_42 )
{
#ifdef F_16
if ( V_47 )
V_47 () ;
#endif
F_17 () ;
return V_43 ;
}
static T_1 F_18 ( int V_1 , void * V_42 )
{
F_19 () ;
return V_43 ;
}
void T_2 F_20 ( int V_1 , struct V_48 * V_49 )
{
F_21 ( V_1 , V_49 ) ;
F_22 ( V_1 , V_50 ) ;
}
void T_2 F_23 ( void )
{
int V_51 ;
F_24 ( F_25 ( V_52 , V_52 ,
16 , F_26 () ) < 0 ,
L_16 , V_52 ) ;
F_27 ( F_1 ) ;
F_28 () ;
switch ( V_2 ) {
case V_3 :
case V_4 :
if ( V_53 )
F_29 ( V_54 ,
V_55 , V_56 ,
V_57 ) ;
else
F_29 ( V_54 ,
V_58 , V_59 ,
V_60 ) ;
break;
case V_5 :
case V_6 :
if ( V_53 )
F_29 ( V_61 ,
V_55 , V_56 ,
V_57 ) ;
else
F_29 ( V_61 ,
V_58 , V_59 ,
V_60 ) ;
}
if ( V_62 ) {
V_51 = V_44 + V_63 ;
} else {
#if F_30 ( V_64 )
if ( V_53 ) {
F_31 ( V_65 , F_12 ) ;
F_31 ( V_66 , F_14 ) ;
V_67 = V_65 ;
V_68 = V_66 ;
} else {
V_67 = V_44 +
V_45 ;
V_68 = V_44 +
V_46 ;
}
F_20 ( V_67 , & V_69 ) ;
F_20 ( V_68 , & V_70 ) ;
#endif
if ( V_53 ) {
F_31 ( V_71 ,
F_7 ) ;
V_51 = V_55 + V_71 ;
} else {
V_51 = V_44 + V_63 ;
}
}
F_21 ( V_51 , & V_72 ) ;
}
