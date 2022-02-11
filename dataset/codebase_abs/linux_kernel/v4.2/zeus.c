static inline int F_1 ( unsigned int V_1 )
{
return V_2 [ V_1 - F_2 ( 0 ) ] ;
}
static inline int F_3 ( int V_3 )
{
return V_4 [ V_3 ] + F_2 ( 0 ) ;
}
static void F_4 ( struct V_5 * V_6 )
{
F_5 ( F_1 ( V_6 -> V_1 ) , V_7 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
V_8 &= ~ ( F_1 ( V_6 -> V_1 ) ) ;
}
static void F_7 ( struct V_5 * V_6 )
{
V_8 |= F_1 ( V_6 -> V_1 ) ;
}
static inline unsigned long F_8 ( void )
{
return F_9 ( V_7 ) & V_8 ;
}
static void F_10 ( unsigned int V_1 , struct V_9 * V_10 )
{
unsigned long V_11 ;
V_11 = F_8 () ;
do {
V_10 -> V_5 . V_12 -> V_13 ( & V_10 -> V_5 ) ;
if ( F_11 ( V_11 ) ) {
V_1 = F_3 ( F_12 ( V_11 ) ) ;
F_13 ( V_1 ) ;
}
V_11 = F_8 () ;
} while ( V_11 );
}
static void T_1 F_14 ( void )
{
int V_14 ;
int V_15 ;
F_15 () ;
F_16 ( F_17 ( V_16 ) , V_17 ) ;
F_16 ( F_17 ( V_18 ) , V_17 ) ;
F_16 ( F_17 ( V_19 ) , V_17 ) ;
F_16 ( F_17 ( V_20 ) ,
V_21 ) ;
F_16 ( F_17 ( V_22 ) , V_21 ) ;
for ( V_14 = 0 ; V_14 < F_18 ( V_4 ) ; V_14 ++ ) {
V_15 = F_3 ( V_14 ) ;
F_19 ( V_15 , & V_23 ,
V_24 ) ;
F_20 ( V_15 , V_25 | V_26 ) ;
}
F_16 ( F_17 ( V_27 ) , V_17 ) ;
F_21 ( F_17 ( V_27 ) , F_10 ) ;
}
static void F_22 ( int V_28 )
{
T_2 V_29 = F_9 ( V_30 ) ;
if ( V_28 )
V_29 |= V_31 ;
else
V_29 &= ~ V_31 ;
F_5 ( V_29 , V_30 ) ;
}
static void F_23 ( void )
{
V_32 = V_33 | V_34 | V_35 | V_36 ;
F_24 ( & V_37 ) ;
}
static void F_25 ( int V_38 , struct V_39 * V_40 )
{
F_26 ( V_41 , V_38 ) ;
}
static void F_27 ( int V_38 )
{
F_26 ( V_42 , V_38 ) ;
}
static int F_28 ( void )
{
int V_43 ;
if ( ( V_43 = F_29 ( V_41 , L_1 ) ) )
goto V_44;
if ( ( V_43 = F_30 ( V_41 , 0 ) ) )
goto V_45;
if ( ( V_43 = F_29 ( V_42 , L_2 ) ) )
goto V_45;
if ( ( V_43 = F_30 ( V_42 , 0 ) ) )
goto V_46;
return 0 ;
V_46:
F_31 ( V_42 ) ;
V_45:
F_31 ( V_41 ) ;
V_44:
return V_43 ;
}
static void F_32 ( int V_47 )
{
switch ( V_47 ) {
case V_48 :
F_33 ( L_3 ) ;
V_32 = V_33 | V_34 | V_35 | V_36 ;
break;
case V_49 :
F_33 ( L_4 ) ;
V_32 = V_33 | V_50 ;
break;
}
}
static void F_34 ( void )
{
F_35 () ;
F_36 ( V_51 , V_52 ) ;
}
static void F_37 ( struct V_53 * V_54 )
{
V_54 -> V_55 = V_56 ;
V_54 -> V_57 = V_58 ;
V_54 -> V_59 = V_60 ;
}
static inline void F_38 ( void )
{
V_61 = F_37 ;
}
static inline void F_38 ( void )
{
}
static int F_39 ( struct V_62 * V_63 , unsigned V_64 ,
unsigned V_65 , void * V_66 )
{
int V_67 ;
T_3 V_68 = 0 ;
for ( V_67 = 0 ; V_67 < 8 ; V_67 ++ ) {
int V_69 = V_64 + V_67 + 8 ;
if ( F_29 ( V_69 , L_5 ) ) {
F_40 ( & V_63 -> V_70 , L_6 , V_67 ) ;
continue;
}
if ( F_41 ( V_69 ) ) {
F_40 ( & V_63 -> V_70 , L_7 , V_67 ) ;
F_31 ( V_69 ) ;
continue;
}
V_68 |= ! ! F_42 ( V_69 ) << V_67 ;
F_31 ( V_69 ) ;
}
F_43 ( & V_63 -> V_70 , L_8 ,
V_68 >> 4 , V_68 & 0xf ) ;
return 0 ;
}
static void T_1 F_44 ( void )
{
T_2 V_71 = V_72 ;
T_4 V_73 , V_74 ;
V_75 = F_9 ( V_76 ) ;
F_33 ( L_9 , ( V_75 & 0xf0 ) >> 4 , ( V_75 & 0x0f ) ) ;
V_73 = ( F_45 ( V_77 ) & 0x0000ffff ) | ( V_71 << 16 ) ;
V_74 = ( F_45 ( V_78 ) & 0xffff0000 ) | V_71 ;
F_46 ( V_73 , V_77 ) ;
F_46 ( V_74 , V_78 ) ;
V_79 = F_34 ;
F_38 () ;
F_47 ( F_48 ( V_80 ) ) ;
F_49 ( V_81 , F_18 ( V_81 ) ) ;
F_23 () ;
if ( F_28 () )
F_50 ( L_10 ) ;
else
F_51 ( NULL , & V_82 ) ;
F_52 ( & V_83 ) ;
F_53 ( & V_84 ) ;
F_54 ( & V_85 ) ;
F_55 ( NULL ) ;
F_56 ( 0 , F_48 ( V_86 ) ) ;
F_57 ( 3 , & V_87 ) ;
F_58 ( V_88 , F_18 ( V_88 ) ) ;
F_59 () ;
}
static void T_1 F_60 ( void )
{
F_61 () ;
F_62 ( V_89 , F_18 ( V_89 ) ) ;
V_90 = V_91 = 0 ;
V_92 |= V_93 ;
V_94 = V_95 | V_96 | V_97 | V_98 ;
}
