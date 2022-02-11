static T_1 F_1 ( void )
{
return V_1 ;
}
static void T_2 F_2 ( void )
{
void T_3 * V_2 ;
unsigned int V_3 ;
V_2 = F_3 ( V_4 , V_5 ) ;
if ( ! V_2 )
return;
V_3 = F_4 ( V_2 + V_6 ) & 0xFFFF0000 ;
F_5 ( V_2 ) ;
switch ( V_3 ) {
case 0x01150000 :
V_1 = V_7 ;
break;
case 0x92200000 :
default:
V_1 = V_8 ;
}
}
static inline void T_2 F_6 ( void )
{
if ( F_7 () ) {
if ( F_1 () == V_7 )
V_9 . V_10 = V_11 ;
else
V_9 . V_10 = V_12 ;
}
F_8 ( & V_9 ) ;
}
static inline void T_2 F_6 ( void ) { return; }
static void T_2 F_9 ( void )
{
int V_13 ;
V_13 = F_10 ( V_14 , V_15 ,
L_1 ) ;
if ( V_13 )
F_11 ( L_2 ) ;
V_13 = F_10 ( V_16 ,
V_15 , L_3 ) ;
if ( V_13 )
F_11 ( L_4 ) ;
if ( F_1 () >= V_8 )
F_12 ( V_16 , 0 ) ;
else
F_12 ( V_16 , 1 ) ;
}
static int F_13 ( struct V_17 * V_18 ,
unsigned V_19 , unsigned V_20 )
{
int V_13 , V_21 ;
V_22 [ 0 ] . V_23 = V_19 + 0 ;
F_14 ( V_22 ) ;
V_21 = F_1 () >= V_8 ?
V_24 : V_15 ;
V_13 = F_10 ( V_19 + V_25 , V_21 , L_5 ) ;
if ( V_13 )
F_15 ( V_26 L_6 ) ;
F_10 ( V_19 + 7 , V_15 , L_7 ) ;
V_27 [ 0 ] . V_19 = V_19 + V_25 + 1 ;
F_16 ( & V_28 ) ;
#ifdef F_17
if ( F_1 () >= V_8 ) {
T_1 V_29 ;
F_18 ( V_30 , & V_29 , V_31 ) ;
V_29 |= 0x04 ;
F_19 ( V_30 , V_29 , V_31 ) ;
}
#endif
return 0 ;
}
static int T_2 F_20 ( void )
{
F_21 ( & V_32 ,
V_33 | V_34 |
V_35 ,
V_36 | V_37 ) ;
V_32 . V_38 -> V_39 . V_40 = true ;
V_32 . V_41 -> V_39 . V_40 = true ;
F_22 ( L_8 , & V_32 ) ;
F_23 ( 2 , 400 , NULL , 0 ) ;
F_23 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_2 F_24 ( void )
{
#ifdef F_25
int V_42 ;
V_43 . V_44 = F_26 ( V_45 ) ;
V_42 = F_27 ( & V_43 ) ;
if ( V_42 )
F_11 ( L_9 , V_42 ) ;
V_42 = F_16 ( & V_46 ) ;
if ( V_42 )
F_11 ( L_10 , V_42 ) ;
#endif
}
static void T_2 F_28 ( void )
{
struct V_47 * V_48 ;
F_2 () ;
F_29 ( 0 , V_49 , F_30 ( V_49 ) ) ;
V_48 = ( F_31 () ) ? V_50 : V_51 ;
F_32 ( V_48 , V_52 ) ;
F_33 ( 63 , V_53 ) ;
F_34 ( V_22 ) ;
if ( F_1 () >= V_8 )
V_32 . V_54 = & V_55 ;
F_20 () ;
F_35 ( & V_56 ) ;
F_16 ( & V_57 ) ;
F_16 ( & V_58 ) ;
F_16 ( & V_59 ) ;
F_16 ( & V_60 ) ;
F_36 () ;
F_37 ( V_61 , NULL ) ;
F_38 () ;
if ( F_1 () >= V_8 ) {
F_33 ( V_62 , V_63 ) ;
F_33 ( V_64 ,
V_63 ) ;
F_39 ( V_65 ,
F_30 ( V_65 ) ) ;
F_33 ( 21 , V_63 ) ;
V_66 [ 0 ] . V_67 = 21 ;
V_68 . V_69 = 500 ;
V_68 . V_70 = 1 ;
} else {
F_33 ( 135 , V_71 ) ;
V_66 [ 0 ] . V_67 = 135 ;
}
F_40 ( L_11 , 0 , L_12 ) ;
F_41 ( & V_68 ) ;
F_42 ( V_66 , F_30 ( V_66 ) ) ;
F_43 ( & V_72 ) ;
F_44 ( V_73 ,
F_30 ( V_73 ) , V_74 ,
V_75 , NULL ) ;
F_45 ( 1 , V_76 , 310 , NULL ) ;
F_6 () ;
#ifdef F_46
F_9 () ;
#endif
F_24 () ;
F_47 ( L_13 , NULL ) ;
}
