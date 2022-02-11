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
struct V_9 * V_10 ;
unsigned int V_11 ;
V_10 = F_7 ( NULL , L_1 ) ;
if ( F_8 ( V_10 ) )
V_11 = 100000000 ;
else
V_11 = F_9 ( V_10 ) ;
if ( F_10 () ) {
if ( F_1 () == V_7 )
V_12 . V_13 = V_14 ;
else
V_12 . V_13 = V_15 ;
}
F_11 ( & V_12 ) ;
}
static inline void T_2 F_6 ( void ) { return; }
static void T_2 F_12 ( void )
{
int V_16 ;
V_16 = F_13 ( V_17 ,
F_14 ( V_17 ) ) ;
if ( V_16 )
F_15 ( V_18 L_2 ) ;
}
static int F_16 ( struct V_19 * V_20 )
{
if ( V_21 ) {
F_15 ( V_18 L_3 ) ;
return - V_22 ;
}
F_17 ( V_23 , 0 ) ;
if ( F_1 () >= V_8 )
F_18 ( V_24 , 0 ) ;
else
F_18 ( V_24 , 1 ) ;
V_25 = 1 ;
return 0 ;
}
static void F_19 ( struct V_19 * V_20 )
{
F_17 ( V_23 , 1 ) ;
if ( F_1 () >= V_8 )
F_18 ( V_24 , 1 ) ;
else
F_18 ( V_24 , 0 ) ;
V_25 = 0 ;
}
static int F_20 ( struct V_19 * V_20 )
{
return 0 ;
}
static void F_21 ( struct V_19 * V_20 )
{
}
static int F_22 ( struct V_19 * V_20 )
{
if ( V_25 ) {
F_15 ( V_18 L_4 ) ;
return - V_22 ;
}
F_18 ( V_26 , 1 ) ;
V_21 = 1 ;
return 0 ;
}
static void F_23 ( struct V_19 * V_20 )
{
F_18 ( V_26 , 0 ) ;
V_21 = 0 ;
}
static int F_24 ( struct V_27 * V_28 ,
unsigned V_29 , unsigned V_30 )
{
int V_16 , V_31 ;
F_25 ( 63 , V_32 ) ;
V_33 [ 0 ] . V_34 = V_29 + 0 ;
F_26 ( V_33 ) ;
V_31 = F_1 () >= V_8 ?
V_35 : V_36 ;
V_16 = F_27 ( V_29 + V_37 , V_31 , L_5 ) ;
if ( V_16 )
F_15 ( V_18 L_6 ) ;
F_27 ( V_29 + 7 , V_36 , L_7 ) ;
V_38 [ 2 ] . V_29 = V_29 + V_37 + 1 ;
F_28 ( & V_39 ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
F_30 ( & V_40 ,
V_41 | V_42 |
V_43 ,
V_44 | V_45 ) ;
V_40 . V_46 -> V_47 . V_48 = true ;
V_40 . V_49 -> V_47 . V_48 = true ;
F_31 ( L_8 , & V_40 ) ;
F_32 ( 2 , 400 , NULL , 0 ) ;
F_32 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_2 F_33 ( void )
{
F_2 () ;
if ( F_34 () )
F_35 ( V_50 , V_51 ) ;
else
F_35 ( V_52 , V_51 ) ;
V_53 = V_54 ;
V_55 = F_14 ( V_54 ) ;
F_29 () ;
F_36 ( & V_56 ) ;
F_37 () ;
F_38 ( V_57 , NULL ) ;
F_39 () ;
if ( F_1 () >= V_8 ) {
F_25 ( V_58 , V_59 ) ;
F_25 ( V_60 ,
V_59 ) ;
F_13 ( V_61 ,
F_14 ( V_61 ) ) ;
F_25 ( 21 , V_59 ) ;
V_62 . V_63 [ 1 ] = 21 ;
V_64 . V_65 = 500 ;
V_64 . V_66 = 1 ;
} else {
F_25 ( 135 , V_67 ) ;
V_62 . V_63 [ 1 ] = 135 ;
}
F_40 ( & V_64 ) ;
F_41 ( & V_62 ) ;
F_42 ( 1 , V_68 , 310 , NULL ) ;
F_6 () ;
F_12 () ;
#ifdef F_43
if ( F_44 ( & V_69 ) )
F_45 ( L_9 ) ;
F_28 ( & V_70 ) ;
#endif
}
