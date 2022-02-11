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
static int F_22 ( struct V_28 * V_29 )
{
int V_30 ;
V_30 = F_23 ( V_31 , L_1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_24 ( V_31 , 1 ) ;
if ( V_30 ) {
F_25 ( V_31 ) ;
return V_30 ;
}
return 0 ;
}
static int F_26 ( int V_32 )
{
F_27 ( V_31 , ! V_32 ) ;
return 0 ;
}
static void F_28 ( int V_33 )
{
T_2 V_34 = F_9 ( V_35 ) ;
if ( V_33 )
V_34 |= V_36 ;
else
V_34 &= ~ V_36 ;
F_5 ( V_34 , V_35 ) ;
}
static int F_29 ( struct V_37 * V_38 )
{
int V_30 ;
if ( ( V_30 = F_23 ( V_39 , L_2 ) ) ) {
F_30 ( V_38 , L_3 ) ;
return V_30 ;
}
if ( ( V_30 = F_24 ( V_39 , 1 ) ) ) {
F_25 ( V_39 ) ;
F_30 ( V_38 , L_4 ) ;
return V_30 ;
}
V_40 = V_41 | V_42 | V_43 | V_44 ;
return 0 ;
}
static void F_31 ( struct V_37 * V_38 )
{
F_24 ( V_39 , 0 ) ;
F_25 ( V_39 ) ;
}
static void F_32 ( int V_45 , struct V_46 * V_47 )
{
F_27 ( V_48 , V_45 ) ;
}
static void F_33 ( int V_45 )
{
F_27 ( V_49 , V_45 ) ;
}
static int F_34 ( void )
{
int V_30 ;
if ( ( V_30 = F_23 ( V_48 , L_5 ) ) )
goto V_50;
if ( ( V_30 = F_24 ( V_48 , 0 ) ) )
goto V_51;
if ( ( V_30 = F_23 ( V_49 , L_6 ) ) )
goto V_51;
if ( ( V_30 = F_24 ( V_49 , 0 ) ) )
goto V_52;
return 0 ;
V_52:
F_25 ( V_49 ) ;
V_51:
F_25 ( V_48 ) ;
V_50:
return V_30 ;
}
static void F_35 ( int V_53 )
{
switch ( V_53 ) {
case V_54 :
F_36 ( L_7 ) ;
V_40 = V_41 | V_42 | V_43 | V_44 ;
break;
case V_55 :
F_36 ( L_8 ) ;
V_40 = V_41 | V_56 ;
break;
}
}
static void F_37 ( void )
{
F_38 () ;
F_39 ( V_57 , V_58 ) ;
}
static void F_40 ( struct V_59 * V_60 )
{
V_60 -> V_61 = V_62 ;
V_60 -> V_63 = V_64 ;
V_60 -> V_65 = V_66 ;
}
static inline void F_41 ( void )
{
V_67 = F_40 ;
}
static inline void F_41 ( void )
{
}
static int F_42 ( struct V_68 * V_69 , unsigned V_70 ,
unsigned V_71 , void * V_72 )
{
int V_73 ;
T_3 V_74 = 0 ;
for ( V_73 = 0 ; V_73 < 8 ; V_73 ++ ) {
int V_75 = V_70 + V_73 + 8 ;
if ( F_23 ( V_75 , L_9 ) ) {
F_30 ( & V_69 -> V_38 , L_10 , V_73 ) ;
continue;
}
if ( F_43 ( V_75 ) ) {
F_30 ( & V_69 -> V_38 , L_11 , V_73 ) ;
F_25 ( V_75 ) ;
continue;
}
V_74 |= ! ! F_44 ( V_75 ) << V_73 ;
F_25 ( V_75 ) ;
}
F_45 ( & V_69 -> V_38 , L_12 ,
V_74 >> 4 , V_74 & 0xf ) ;
return 0 ;
}
static void T_1 F_46 ( void )
{
T_2 V_76 = V_77 ;
T_4 V_78 , V_79 ;
V_80 = F_9 ( V_81 ) ;
F_36 ( L_13 , ( V_80 & 0xf0 ) >> 4 , ( V_80 & 0x0f ) ) ;
V_78 = ( F_47 ( V_82 ) & 0x0000ffff ) | ( V_76 << 16 ) ;
V_79 = ( F_47 ( V_83 ) & 0xffff0000 ) | V_76 ;
F_48 ( V_78 , V_82 ) ;
F_48 ( V_79 , V_83 ) ;
V_84 = F_37 ;
F_41 () ;
F_49 ( F_50 ( V_85 ) ) ;
F_51 ( V_86 , F_18 ( V_86 ) ) ;
F_52 ( & V_87 ) ;
if ( F_34 () )
F_53 ( L_14 ) ;
else
F_54 ( NULL , & V_88 ) ;
F_55 ( & V_89 ) ;
F_56 ( & V_90 ) ;
F_57 ( & V_91 ) ;
F_58 ( NULL ) ;
F_59 ( 0 , F_50 ( V_92 ) ) ;
F_60 ( 3 , & V_93 ) ;
F_61 ( V_94 , F_18 ( V_94 ) ) ;
}
static void T_1 F_62 ( void )
{
F_63 () ;
F_64 ( V_95 , F_18 ( V_95 ) ) ;
V_96 = V_97 = 0 ;
V_98 |= V_99 ;
V_100 = V_101 | V_102 | V_103 | V_104 ;
}
