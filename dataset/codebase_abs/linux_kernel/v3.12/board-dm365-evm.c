static inline int F_1 ( void )
{
return 0 ;
}
static inline int F_2 ( void )
{
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_3 ) ;
}
static int F_5 ( int V_4 )
{
if ( ! V_5 )
return - V_6 ;
return ! ( F_6 ( V_5 + V_7 ) & F_7 ( V_4 ? 4 : 0 ) ) ;
}
static int F_8 ( int V_4 )
{
if ( ! V_5 )
return - V_6 ;
return ! ! ( F_6 ( V_5 + V_7 ) & F_7 ( V_4 ? 5 : 1 ) ) ;
}
static void F_9 ( void )
{
F_4 ( V_8 ) ;
F_4 ( V_9 ) ;
F_4 ( V_10 ) ;
F_4 ( V_11 ) ;
F_4 ( V_12 ) ;
F_4 ( V_13 ) ;
F_4 ( V_14 ) ;
F_4 ( V_15 ) ;
F_4 ( V_16 ) ;
F_4 ( V_17 ) ;
F_4 ( V_18 ) ;
F_4 ( V_19 ) ;
F_4 ( V_20 ) ;
F_4 ( V_21 ) ;
F_4 ( V_22 ) ;
F_4 ( V_23 ) ;
F_4 ( V_24 ) ;
F_4 ( V_25 ) ;
F_4 ( V_26 ) ;
F_4 ( V_27 ) ;
F_4 ( V_28 ) ;
}
static void F_10 ( void )
{
F_4 ( V_29 ) ;
F_4 ( V_30 ) ;
F_4 ( V_31 ) ;
F_4 ( V_32 ) ;
F_4 ( V_33 ) ;
F_4 ( V_34 ) ;
}
static void T_1 F_11 ( void )
{
F_12 ( & V_35 ) ;
F_13 ( 1 , V_36 , F_14 ( V_36 ) ) ;
}
static inline int F_15 ( void )
{
#ifdef F_16
return 1 ;
#else
return 0 ;
#endif
}
static void F_17 ( struct V_37 * V_38 , enum V_39 V_40 )
{
struct V_41 * V_42 = F_18 ( V_38 , struct V_41 , V_38 ) ;
T_2 V_43 = F_6 ( V_5 + V_44 ) ;
if ( V_40 != V_45 )
V_43 &= ~ V_42 -> V_46 ;
else
V_43 |= V_42 -> V_46 ;
F_19 ( V_43 , V_5 + V_44 ) ;
}
static enum V_39 F_20 ( struct V_37 * V_38 )
{
struct V_41 * V_42 = F_18 ( V_38 , struct V_41 , V_38 ) ;
T_2 V_43 = F_6 ( V_5 + V_44 ) ;
return ( V_43 & V_42 -> V_46 ) ? V_45 : V_47 ;
}
static int T_1 F_21 ( void )
{
int V_48 ;
if ( ! F_15 () || ! V_5 )
return 0 ;
F_19 ( 0xff , V_5 + V_44 ) ;
for ( V_48 = 0 ; V_48 < F_14 ( V_49 ) ; V_48 ++ ) {
struct V_41 * V_42 ;
V_42 = F_22 ( sizeof( * V_42 ) , V_50 ) ;
if ( ! V_42 )
break;
V_42 -> V_38 . V_51 = V_49 [ V_48 ] . V_51 ;
V_42 -> V_38 . V_52 = F_17 ;
V_42 -> V_38 . V_53 = F_20 ;
V_42 -> V_38 . V_54 = V_49 [ V_48 ] . V_55 ;
V_42 -> V_46 = F_7 ( V_48 ) ;
if ( F_23 ( NULL , & V_42 -> V_38 ) < 0 ) {
F_24 ( V_42 ) ;
break;
}
}
return 0 ;
}
static void T_1 F_25 ( void )
{
T_2 V_56 , V_57 ;
const char * V_58 ;
struct V_59 * V_60 ;
V_60 = F_26 ( NULL , L_1 ) ;
if ( F_27 ( V_60 ) )
return;
F_28 ( V_60 ) ;
if ( F_29 ( V_61 , V_62 ,
L_2 ) == NULL )
goto V_63;
V_5 = F_30 ( V_61 , V_62 ) ;
if ( ! V_5 ) {
F_31 ( V_61 ,
V_62 ) ;
V_63:
F_32 ( L_3 ) ;
F_33 ( V_60 ) ;
return;
}
V_56 = 0 ;
if ( ( F_6 ( V_5 + V_64 ) & F_7 ( 5 ) ) == 0 ) {
V_56 |= F_7 ( 7 ) ;
F_34 ( V_65 ,
F_14 ( V_65 ) ) ;
} else {
}
V_57 = F_7 ( 3 ) | F_7 ( 2 ) | F_7 ( 1 ) | F_7 ( 0 ) ;
if ( F_1 () ) {
V_58 = L_4 ;
V_56 |= 2 ;
V_56 |= F_7 ( 6 ) | F_7 ( 5 ) | F_7 ( 3 ) ;
} else {
struct V_66 * V_67 = & V_66 ;
F_10 () ;
F_35 ( 1 , & V_68 ) ;
F_9 () ;
V_67 -> V_69 -> V_70 = V_71 ;
V_57 &= ~ F_7 ( 3 ) ;
V_57 &= ~ F_7 ( 1 ) ;
if ( F_2 () ) {
V_56 |= 1 ;
V_57 &= ~ F_7 ( 2 ) ;
V_58 = L_5 ;
} else {
V_56 |= 5 ;
V_57 &= ~ F_7 ( 0 ) ;
V_58 = L_6 ;
}
}
F_19 ( V_56 , V_5 + V_72 ) ;
F_19 ( V_57 , V_5 + V_73 ) ;
F_36 ( L_7 , V_58 ) ;
}
static void T_1 F_37 ( void )
{
F_38 () ;
}
static T_1 void F_39 ( void )
{
F_11 () ;
F_40 ( V_74 ) ;
F_9 () ;
F_10 () ;
F_35 ( 0 , & V_68 ) ;
F_41 ( & V_75 , & V_76 ) ;
F_25 () ;
#ifdef F_42
F_43 ( & V_77 ) ;
#elif F_44 ( V_78 )
F_45 ( & V_77 ) ;
#endif
F_46 () ;
F_47 ( & V_79 ) ;
F_48 ( F_7 ( 0 ) , V_80 ,
F_14 ( V_80 ) ) ;
}
