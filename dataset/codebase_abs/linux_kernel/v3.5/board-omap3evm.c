T_1 F_1 ( void )
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
return 0 ;
}
static int T_2 F_23 ( void )
{
F_24 ( & V_35 ,
V_36 | V_37 |
V_38 ,
V_39 | V_40 ) ;
V_35 . V_41 -> V_42 . V_43 = true ;
V_35 . V_44 -> V_42 . V_43 = true ;
F_25 ( L_6 , & V_35 ) ;
F_26 ( 2 , 400 , NULL , 0 ) ;
F_26 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_2 F_27 ( void )
{
#ifdef F_28
int V_45 ;
V_46 . V_47 = F_29 ( V_48 ) ;
V_45 = F_30 ( & V_46 ) ;
if ( V_45 )
F_31 ( L_7 , V_45 ) ;
V_45 = F_22 ( & V_49 ) ;
if ( V_45 )
F_31 ( L_8 , V_45 ) ;
#endif
}
static void T_2 F_32 ( void )
{
struct V_50 * V_51 ;
F_2 () ;
F_33 ( 0 , V_52 , F_11 ( V_52 ) ) ;
V_51 = ( F_34 () ) ? V_53 : V_54 ;
F_35 ( V_51 , V_55 ) ;
V_56 = V_57 ;
V_58 = F_11 ( V_57 ) ;
F_36 ( 63 , V_59 ) ;
F_37 ( V_28 ) ;
F_23 () ;
F_38 ( & V_60 ) ;
F_39 () ;
F_40 ( V_61 , NULL ) ;
F_41 () ;
if ( F_1 () >= V_8 ) {
F_36 ( V_62 , V_63 ) ;
F_36 ( V_64 ,
V_63 ) ;
F_10 ( V_65 ,
F_11 ( V_65 ) ) ;
F_36 ( 21 , V_63 ) ;
V_66 . V_67 [ 1 ] = 21 ;
V_68 . V_69 = 500 ;
V_68 . V_70 = 1 ;
} else {
F_36 ( 135 , V_71 ) ;
V_66 . V_67 [ 1 ] = 135 ;
}
F_42 ( & V_68 ) ;
F_43 ( & V_66 ) ;
F_44 ( 1 , V_72 , 310 , NULL ) ;
F_6 () ;
F_9 () ;
F_27 () ;
}
