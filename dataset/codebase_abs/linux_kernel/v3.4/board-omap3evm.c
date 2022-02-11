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
static int F_19 ( struct V_16 * V_17 )
{
if ( V_22 ) {
F_12 ( V_15 L_3 ) ;
return - V_19 ;
}
F_15 ( V_23 , 1 ) ;
V_18 = 1 ;
return 0 ;
}
static void F_20 ( struct V_16 * V_17 )
{
F_15 ( V_23 , 0 ) ;
V_18 = 0 ;
}
static int F_21 ( struct V_24 * V_25 ,
unsigned V_26 , unsigned V_27 )
{
int V_13 , V_28 ;
V_29 [ 0 ] . V_30 = V_26 + 0 ;
F_22 ( V_29 ) ;
V_28 = F_1 () >= V_8 ?
V_31 : V_32 ;
V_13 = F_23 ( V_26 + V_33 , V_28 , L_4 ) ;
if ( V_13 )
F_12 ( V_15 L_5 ) ;
F_23 ( V_26 + 7 , V_32 , L_6 ) ;
V_34 [ 0 ] . V_26 = V_26 + V_33 + 1 ;
F_24 ( & V_35 ) ;
return 0 ;
}
static int T_2 F_25 ( void )
{
F_26 ( & V_36 ,
V_37 | V_38 |
V_39 ,
V_40 | V_41 ) ;
V_36 . V_42 -> V_43 . V_44 = true ;
V_36 . V_45 -> V_43 . V_44 = true ;
F_27 ( L_7 , & V_36 ) ;
F_28 ( 2 , 400 , NULL , 0 ) ;
F_28 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_2 F_29 ( void )
{
#ifdef F_30
int V_46 ;
V_47 . V_48 = F_31 ( V_49 ) ;
V_46 = F_32 ( & V_47 ) ;
if ( V_46 )
F_33 ( L_8 , V_46 ) ;
V_46 = F_24 ( & V_50 ) ;
if ( V_46 )
F_33 ( L_9 , V_46 ) ;
#endif
}
static void T_2 F_34 ( void )
{
F_2 () ;
F_35 ( 0 , V_51 , F_11 ( V_51 ) ) ;
if ( F_36 () )
F_37 ( V_52 , V_53 ) ;
else
F_37 ( V_54 , V_53 ) ;
V_55 = V_56 ;
V_57 = F_11 ( V_56 ) ;
F_38 ( 63 , V_58 ) ;
F_39 ( V_29 ) ;
F_25 () ;
F_40 ( & V_59 ) ;
F_41 () ;
F_42 ( V_60 , NULL ) ;
F_43 () ;
if ( F_1 () >= V_8 ) {
F_38 ( V_61 , V_62 ) ;
F_38 ( V_63 ,
V_62 ) ;
F_10 ( V_64 ,
F_11 ( V_64 ) ) ;
F_38 ( 21 , V_62 ) ;
V_65 . V_66 [ 1 ] = 21 ;
V_67 . V_68 = 500 ;
V_67 . V_69 = 1 ;
} else {
F_38 ( 135 , V_70 ) ;
V_65 . V_66 [ 1 ] = 135 ;
}
F_44 ( & V_67 ) ;
F_45 ( & V_65 ) ;
F_46 ( 1 , V_71 , 310 , NULL ) ;
F_6 () ;
F_9 () ;
F_29 () ;
}
