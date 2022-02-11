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
V_13 = F_10 ( V_14 ,
F_11 ( V_14 ) ) ;
if ( V_13 )
F_12 ( V_15 L_1 ) ;
}
static int F_13 ( struct V_16 * V_17 )
{
if ( V_18 ) {
F_12 ( V_15 L_2 ) ;
return - V_19 ;
}
F_14 ( V_20 , 0 ) ;
if ( F_1 () >= V_8 )
F_15 ( V_21 , 0 ) ;
else
F_15 ( V_21 , 1 ) ;
V_22 = 1 ;
return 0 ;
}
static void F_16 ( struct V_16 * V_17 )
{
F_14 ( V_20 , 1 ) ;
if ( F_1 () >= V_8 )
F_15 ( V_21 , 1 ) ;
else
F_15 ( V_21 , 0 ) ;
V_22 = 0 ;
}
static int F_17 ( struct V_16 * V_17 )
{
return 0 ;
}
static void F_18 ( struct V_16 * V_17 )
{
}
static int F_19 ( struct V_23 * V_24 ,
unsigned V_25 , unsigned V_26 )
{
int V_13 , V_27 ;
V_28 [ 0 ] . V_29 = V_25 + 0 ;
F_20 ( V_28 ) ;
V_27 = F_1 () >= V_8 ?
V_30 : V_31 ;
V_13 = F_21 ( V_25 + V_32 , V_27 , L_3 ) ;
if ( V_13 )
F_12 ( V_15 L_4 ) ;
F_21 ( V_25 + 7 , V_31 , L_5 ) ;
V_33 [ 0 ] . V_25 = V_25 + V_32 + 1 ;
F_22 ( & V_34 ) ;
#ifdef F_23
if ( F_1 () >= V_8 ) {
T_1 V_35 ;
F_24 ( V_36 , & V_35 , V_37 ) ;
V_35 |= 0x04 ;
F_25 ( V_36 , V_35 , V_37 ) ;
}
#endif
return 0 ;
}
static int T_2 F_26 ( void )
{
F_27 ( & V_38 ,
V_39 | V_40 |
V_41 ,
V_42 | V_43 ) ;
V_38 . V_44 -> V_45 . V_46 = true ;
V_38 . V_47 -> V_45 . V_46 = true ;
F_28 ( L_6 , & V_38 ) ;
F_29 ( 2 , 400 , NULL , 0 ) ;
F_29 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_2 F_30 ( void )
{
#ifdef F_31
int V_48 ;
V_49 . V_50 = F_32 ( V_51 ) ;
V_48 = F_33 ( & V_49 ) ;
if ( V_48 )
F_34 ( L_7 , V_48 ) ;
V_48 = F_22 ( & V_52 ) ;
if ( V_48 )
F_34 ( L_8 , V_48 ) ;
#endif
}
static void T_2 F_35 ( void )
{
struct V_53 * V_54 ;
F_2 () ;
F_36 ( 0 , V_55 , F_11 ( V_55 ) ) ;
V_54 = ( F_37 () ) ? V_56 : V_57 ;
F_38 ( V_54 , V_58 ) ;
F_39 ( 63 , V_59 ) ;
F_40 ( V_28 ) ;
if ( F_1 () >= V_8 )
V_38 . V_60 = & V_61 ;
F_26 () ;
F_41 ( & V_62 ) ;
F_42 () ;
F_43 ( V_63 , NULL ) ;
F_44 () ;
if ( F_1 () >= V_8 ) {
F_39 ( V_64 , V_65 ) ;
F_39 ( V_66 ,
V_65 ) ;
F_10 ( V_67 ,
F_11 ( V_67 ) ) ;
F_39 ( 21 , V_65 ) ;
V_68 . V_69 [ 1 ] = 21 ;
V_70 . V_71 = 500 ;
V_70 . V_72 = 1 ;
} else {
F_39 ( 135 , V_73 ) ;
V_68 . V_69 [ 1 ] = 135 ;
}
F_45 ( & V_70 ) ;
F_46 ( & V_68 ) ;
F_47 ( V_74 , V_75 ,
F_11 ( V_75 ) ) ;
F_48 ( 1 , V_76 , 310 , NULL ) ;
F_6 () ;
F_9 () ;
F_30 () ;
F_49 ( L_9 ) ;
}
