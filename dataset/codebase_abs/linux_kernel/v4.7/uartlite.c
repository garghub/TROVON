static T_1 F_1 ( void T_2 * V_1 )
{
return F_2 ( V_1 ) ;
}
static void F_3 ( T_1 V_2 , void T_2 * V_1 )
{
F_4 ( V_2 , V_1 ) ;
}
static T_1 F_5 ( void T_2 * V_1 )
{
return F_6 ( V_1 ) ;
}
static void F_7 ( T_1 V_2 , void T_2 * V_1 )
{
F_8 ( V_2 , V_1 ) ;
}
static inline T_1 F_9 ( T_1 V_3 , struct V_4 * V_5 )
{
const struct V_6 * V_7 = V_5 -> V_8 ;
return V_7 -> V_9 ( V_5 -> V_10 + V_3 ) ;
}
static inline void F_10 ( T_1 V_2 , T_1 V_3 , struct V_4 * V_5 )
{
const struct V_6 * V_7 = V_5 -> V_8 ;
V_7 -> V_11 ( V_2 , V_5 -> V_10 + V_3 ) ;
}
static int F_11 ( struct V_4 * V_5 , int V_12 )
{
struct V_13 * V_14 = & V_5 -> V_15 -> V_5 ;
unsigned char V_16 = 0 ;
char V_17 = V_18 ;
if ( ( V_12 & ( V_19 | V_20
| V_21 ) ) == 0 )
return 0 ;
if ( V_12 & V_19 ) {
V_5 -> V_22 . V_23 ++ ;
V_16 = F_9 ( V_24 , V_5 ) ;
if ( V_12 & V_25 )
V_5 -> V_22 . V_26 ++ ;
}
if ( V_12 & V_20 )
V_5 -> V_22 . V_27 ++ ;
if ( V_12 & V_21 )
V_5 -> V_22 . V_28 ++ ;
if ( V_12 & V_5 -> V_29 & V_25 )
V_12 &= ~ V_19 ;
V_12 &= V_5 -> V_30 ;
if ( V_12 & V_25 )
V_17 = V_31 ;
V_12 &= ~ V_5 -> V_29 ;
if ( V_12 & V_19 )
F_12 ( V_14 , V_16 , V_17 ) ;
if ( V_12 & V_21 )
F_12 ( V_14 , 0 , V_32 ) ;
if ( V_12 & V_20 )
F_12 ( V_14 , 0 , V_33 ) ;
return 1 ;
}
static int F_13 ( struct V_4 * V_5 , int V_12 )
{
struct V_34 * V_35 = & V_5 -> V_15 -> V_35 ;
if ( V_12 & V_36 )
return 0 ;
if ( V_5 -> V_37 ) {
F_10 ( V_5 -> V_37 , V_38 , V_5 ) ;
V_5 -> V_37 = 0 ;
V_5 -> V_22 . V_39 ++ ;
return 1 ;
}
if ( F_14 ( V_35 ) || F_15 ( V_5 ) )
return 0 ;
F_10 ( V_35 -> V_40 [ V_35 -> V_41 ] , V_38 , V_5 ) ;
V_35 -> V_41 = ( V_35 -> V_41 + 1 ) & ( V_42 - 1 ) ;
V_5 -> V_22 . V_39 ++ ;
if ( F_16 ( V_35 ) < V_43 )
F_17 ( V_5 ) ;
return 1 ;
}
static T_3 F_18 ( int V_44 , void * V_45 )
{
struct V_4 * V_5 = V_45 ;
int V_12 , V_46 , V_47 = 0 ;
unsigned long V_48 ;
do {
F_19 ( & V_5 -> V_49 , V_48 ) ;
V_12 = F_9 ( V_50 , V_5 ) ;
V_46 = F_11 ( V_5 , V_12 ) ;
V_46 |= F_13 ( V_5 , V_12 ) ;
F_20 ( & V_5 -> V_49 , V_48 ) ;
V_47 ++ ;
} while ( V_46 );
if ( V_47 > 1 ) {
F_21 ( & V_5 -> V_15 -> V_5 ) ;
return V_51 ;
} else {
return V_52 ;
}
}
static unsigned int F_22 ( struct V_4 * V_5 )
{
unsigned long V_48 ;
unsigned int V_53 ;
F_19 ( & V_5 -> V_49 , V_48 ) ;
V_53 = F_9 ( V_50 , V_5 ) ;
F_20 ( & V_5 -> V_49 , V_48 ) ;
return V_53 & V_54 ? V_55 : 0 ;
}
static unsigned int F_23 ( struct V_4 * V_5 )
{
return V_56 | V_57 | V_58 ;
}
static void F_24 ( struct V_4 * V_5 , unsigned int V_59 )
{
}
static void F_25 ( struct V_4 * V_5 )
{
}
static void F_26 ( struct V_4 * V_5 )
{
F_13 ( V_5 , F_9 ( V_50 , V_5 ) ) ;
}
static void F_27 ( struct V_4 * V_5 )
{
V_5 -> V_29 = V_19 | V_25
| V_21 | V_20 ;
}
static void F_28 ( struct V_4 * V_5 , int V_60 )
{
}
static int F_29 ( struct V_4 * V_5 )
{
int V_53 ;
V_53 = F_30 ( V_5 -> V_44 , F_18 , V_61 | V_62 ,
L_1 , V_5 ) ;
if ( V_53 )
return V_53 ;
F_10 ( V_63 | V_64 ,
V_65 , V_5 ) ;
F_10 ( V_66 , V_65 , V_5 ) ;
return 0 ;
}
static void F_31 ( struct V_4 * V_5 )
{
F_10 ( 0 , V_65 , V_5 ) ;
F_9 ( V_65 , V_5 ) ;
F_32 ( V_5 -> V_44 , V_5 ) ;
}
static void F_33 ( struct V_4 * V_5 , struct V_67 * V_68 ,
struct V_67 * V_69 )
{
unsigned long V_48 ;
unsigned int V_70 ;
F_19 ( & V_5 -> V_49 , V_48 ) ;
V_5 -> V_30 = V_19 | V_20
| V_36 ;
if ( V_68 -> V_71 & V_72 )
V_5 -> V_30 |=
V_25 | V_21 ;
V_5 -> V_29 = 0 ;
if ( V_68 -> V_71 & V_73 )
V_5 -> V_29 |= V_25
| V_21 | V_20 ;
if ( ( V_68 -> V_74 & V_75 ) == 0 )
V_5 -> V_29 |=
V_19 | V_25
| V_21 | V_20 ;
V_70 = F_34 ( V_5 , V_68 , V_69 , 0 , 460800 ) ;
F_35 ( V_5 , V_68 -> V_74 , V_70 ) ;
F_20 ( & V_5 -> V_49 , V_48 ) ;
}
static const char * F_36 ( struct V_4 * V_5 )
{
return V_5 -> type == V_76 ? L_1 : NULL ;
}
static void F_37 ( struct V_4 * V_5 )
{
F_38 ( V_5 -> V_77 , V_78 ) ;
F_39 ( V_5 -> V_10 ) ;
V_5 -> V_10 = NULL ;
}
static int F_40 ( struct V_4 * V_5 )
{
int V_53 ;
F_41 ( L_2 ,
V_5 , ( unsigned long long ) V_5 -> V_77 ) ;
if ( ! F_42 ( V_5 -> V_77 , V_78 , L_1 ) ) {
F_43 ( V_5 -> V_79 , L_3 ) ;
return - V_80 ;
}
V_5 -> V_10 = F_44 ( V_5 -> V_77 , V_78 ) ;
if ( ! V_5 -> V_10 ) {
F_43 ( V_5 -> V_79 , L_4 ) ;
F_38 ( V_5 -> V_77 , V_78 ) ;
return - V_80 ;
}
V_5 -> V_8 = ( void * ) & V_81 ;
V_53 = F_9 ( V_65 , V_5 ) ;
F_10 ( V_64 , V_65 , V_5 ) ;
V_53 = F_9 ( V_50 , V_5 ) ;
if ( ( V_53 & V_54 ) != V_54 )
V_5 -> V_8 = ( void * ) & V_82 ;
return 0 ;
}
static void F_45 ( struct V_4 * V_5 , int V_48 )
{
if ( ! F_40 ( V_5 ) )
V_5 -> type = V_76 ;
}
static int F_46 ( struct V_4 * V_5 , struct V_83 * V_84 )
{
return - V_85 ;
}
static int F_47 ( struct V_4 * V_5 )
{
if ( ! ( F_9 ( V_50 , V_5 ) & V_19 ) )
return V_86 ;
return F_9 ( V_24 , V_5 ) ;
}
static void F_48 ( struct V_4 * V_5 , unsigned char V_16 )
{
while ( F_9 ( V_50 , V_5 ) & V_36 )
F_49 () ;
F_10 ( V_16 , V_38 , V_5 ) ;
}
static void F_50 ( struct V_4 * V_5 )
{
T_4 V_2 ;
unsigned long V_87 ;
V_87 = V_88 + F_51 ( 1000 ) ;
while ( 1 ) {
V_2 = F_9 ( V_50 , V_5 ) ;
if ( ( V_2 & V_36 ) == 0 )
break;
if ( F_52 ( V_88 , V_87 ) ) {
F_53 ( V_5 -> V_79 ,
L_5 ) ;
break;
}
F_49 () ;
}
}
static void F_54 ( struct V_4 * V_5 , int V_16 )
{
F_50 ( V_5 ) ;
F_10 ( V_16 , V_38 , V_5 ) ;
}
static void F_55 ( struct V_89 * V_90 , const char * V_91 ,
unsigned int V_92 )
{
struct V_4 * V_5 = & V_93 [ V_90 -> V_94 ] ;
unsigned long V_48 ;
unsigned int V_95 ;
int V_96 = 1 ;
if ( V_97 ) {
V_96 = F_56 ( & V_5 -> V_49 , V_48 ) ;
} else
F_19 ( & V_5 -> V_49 , V_48 ) ;
V_95 = F_9 ( V_50 , V_5 ) & V_98 ;
F_10 ( 0 , V_65 , V_5 ) ;
F_57 ( V_5 , V_91 , V_92 , F_54 ) ;
F_50 ( V_5 ) ;
if ( V_95 )
F_10 ( V_66 , V_65 , V_5 ) ;
if ( V_96 )
F_20 ( & V_5 -> V_49 , V_48 ) ;
}
static int F_58 ( struct V_89 * V_90 , char * V_99 )
{
struct V_4 * V_5 ;
int V_70 = 9600 ;
int V_100 = 8 ;
int V_26 = 'n' ;
int V_101 = 'n' ;
if ( V_90 -> V_94 < 0 || V_90 -> V_94 >= V_102 )
return - V_85 ;
V_5 = & V_93 [ V_90 -> V_94 ] ;
if ( ! V_5 -> V_77 ) {
F_41 ( L_6 , V_90 -> V_94 ) ;
return - V_103 ;
}
if ( ! V_5 -> V_10 ) {
if ( F_40 ( V_5 ) )
return - V_103 ;
}
if ( V_99 )
F_59 ( V_99 , & V_70 , & V_26 , & V_100 , & V_101 ) ;
return F_60 ( V_5 , V_90 , V_70 , V_26 , V_100 , V_101 ) ;
}
static int T_5 F_61 ( void )
{
F_62 ( & V_104 ) ;
return 0 ;
}
static void F_63 ( struct V_4 * V_5 , int V_105 )
{
unsigned V_106 = 1000000 ;
while ( -- V_106 && ( F_64 ( V_5 -> V_10 + 8 ) & ( 1 << 3 ) ) )
;
if ( V_106 )
F_65 ( V_105 & 0xff , V_5 -> V_10 + 4 ) ;
}
static void F_66 ( struct V_89 * V_89 ,
const char * V_91 , unsigned V_47 )
{
struct V_107 * V_108 = V_89 -> V_109 ;
F_57 ( & V_108 -> V_5 , V_91 , V_47 , F_63 ) ;
}
static int T_5 F_67 ( struct V_107 * V_108 ,
const char * V_99 )
{
if ( ! V_108 -> V_5 . V_10 )
return - V_103 ;
V_108 -> V_110 -> V_111 = F_66 ;
return 0 ;
}
static int F_68 ( struct V_108 * V_79 , int V_112 , T_1 V_113 , int V_44 )
{
struct V_4 * V_5 ;
int V_114 ;
if ( V_112 < 0 ) {
for ( V_112 = 0 ; V_112 < V_102 ; V_112 ++ )
if ( V_93 [ V_112 ] . V_77 == 0 )
break;
}
if ( V_112 < 0 || V_112 >= V_102 ) {
F_43 ( V_79 , L_7 , V_115 , V_112 ) ;
return - V_85 ;
}
if ( ( V_93 [ V_112 ] . V_77 ) && ( V_93 [ V_112 ] . V_77 != V_113 ) ) {
F_43 ( V_79 , L_8 ,
V_115 , V_112 ) ;
return - V_80 ;
}
V_5 = & V_93 [ V_112 ] ;
F_69 ( & V_5 -> V_49 ) ;
V_5 -> V_116 = 16 ;
V_5 -> V_117 = 2 ;
V_5 -> V_118 = V_119 ;
V_5 -> V_120 = 1 ;
V_5 -> V_77 = V_113 ;
V_5 -> V_10 = NULL ;
V_5 -> V_121 = & V_122 ;
V_5 -> V_44 = V_44 ;
V_5 -> V_48 = V_123 ;
V_5 -> V_79 = V_79 ;
V_5 -> type = V_124 ;
V_5 -> line = V_112 ;
F_70 ( V_79 , V_5 ) ;
V_114 = F_71 ( & V_125 , V_5 ) ;
if ( V_114 ) {
F_43 ( V_79 , L_9 , V_114 ) ;
V_5 -> V_77 = 0 ;
F_70 ( V_79 , NULL ) ;
return V_114 ;
}
return 0 ;
}
static int F_72 ( struct V_108 * V_79 )
{
struct V_4 * V_5 = F_73 ( V_79 ) ;
int V_114 = 0 ;
if ( V_5 ) {
V_114 = F_74 ( & V_125 , V_5 ) ;
F_70 ( V_79 , NULL ) ;
V_5 -> V_77 = 0 ;
}
return V_114 ;
}
static int F_75 ( struct V_126 * V_127 )
{
struct V_128 * V_129 ;
int V_44 ;
int V_112 = V_127 -> V_112 ;
#ifdef F_76
const T_6 * V_130 ;
V_130 = F_77 ( V_127 -> V_79 . V_131 , L_10 , NULL ) ;
if ( V_130 )
V_112 = F_78 ( V_130 ) ;
#endif
V_129 = F_79 ( V_127 , V_132 , 0 ) ;
if ( ! V_129 )
return - V_103 ;
V_44 = F_80 ( V_127 , 0 ) ;
if ( V_44 <= 0 )
return - V_133 ;
return F_68 ( & V_127 -> V_79 , V_112 , V_129 -> V_134 , V_44 ) ;
}
static int F_81 ( struct V_126 * V_127 )
{
return F_72 ( & V_127 -> V_79 ) ;
}
static int T_5 F_82 ( void )
{
int V_53 ;
F_41 ( L_11 ) ;
V_53 = F_83 ( & V_125 ) ;
if ( V_53 )
goto V_135;
F_41 ( L_12 ) ;
V_53 = F_84 ( & V_136 ) ;
if ( V_53 )
goto V_137;
return 0 ;
V_137:
F_85 ( & V_125 ) ;
V_135:
F_86 ( L_13 , V_53 ) ;
return V_53 ;
}
static void T_7 F_87 ( void )
{
F_88 ( & V_136 ) ;
F_85 ( & V_125 ) ;
}
