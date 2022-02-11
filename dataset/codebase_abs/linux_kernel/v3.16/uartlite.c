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
struct V_6 * V_7 = V_5 -> V_8 ;
return V_7 -> V_9 ( V_5 -> V_10 + V_3 ) ;
}
static inline void F_10 ( T_1 V_2 , T_1 V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
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
int V_46 , V_47 = 0 ;
do {
int V_12 = F_9 ( V_48 , V_5 ) ;
V_46 = F_11 ( V_5 , V_12 ) ;
V_46 |= F_13 ( V_5 , V_12 ) ;
V_47 ++ ;
} while ( V_46 );
if ( V_47 > 1 ) {
F_19 ( & V_5 -> V_15 -> V_5 ) ;
return V_49 ;
} else {
return V_50 ;
}
}
static unsigned int F_20 ( struct V_4 * V_5 )
{
unsigned long V_51 ;
unsigned int V_52 ;
F_21 ( & V_5 -> V_53 , V_51 ) ;
V_52 = F_9 ( V_48 , V_5 ) ;
F_22 ( & V_5 -> V_53 , V_51 ) ;
return V_52 & V_54 ? V_55 : 0 ;
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
F_13 ( V_5 , F_9 ( V_48 , V_5 ) ) ;
}
static void F_27 ( struct V_4 * V_5 )
{
V_5 -> V_29 = V_19 | V_25
| V_21 | V_20 ;
}
static void F_28 ( struct V_4 * V_5 )
{
}
static void F_29 ( struct V_4 * V_5 , int V_60 )
{
}
static int F_30 ( struct V_4 * V_5 )
{
int V_52 ;
V_52 = F_31 ( V_5 -> V_44 , F_18 , V_61 , L_1 , V_5 ) ;
if ( V_52 )
return V_52 ;
F_10 ( V_62 | V_63 ,
V_64 , V_5 ) ;
F_10 ( V_65 , V_64 , V_5 ) ;
return 0 ;
}
static void F_32 ( struct V_4 * V_5 )
{
F_10 ( 0 , V_64 , V_5 ) ;
F_9 ( V_64 , V_5 ) ;
F_33 ( V_5 -> V_44 , V_5 ) ;
}
static void F_34 ( struct V_4 * V_5 , struct V_66 * V_67 ,
struct V_66 * V_68 )
{
unsigned long V_51 ;
unsigned int V_69 ;
F_21 ( & V_5 -> V_53 , V_51 ) ;
V_5 -> V_30 = V_19 | V_20
| V_36 ;
if ( V_67 -> V_70 & V_71 )
V_5 -> V_30 |=
V_25 | V_21 ;
V_5 -> V_29 = 0 ;
if ( V_67 -> V_70 & V_72 )
V_5 -> V_29 |= V_25
| V_21 | V_20 ;
if ( ( V_67 -> V_73 & V_74 ) == 0 )
V_5 -> V_29 |=
V_19 | V_25
| V_21 | V_20 ;
V_69 = F_35 ( V_5 , V_67 , V_68 , 0 , 460800 ) ;
F_36 ( V_5 , V_67 -> V_73 , V_69 ) ;
F_22 ( & V_5 -> V_53 , V_51 ) ;
}
static const char * F_37 ( struct V_4 * V_5 )
{
return V_5 -> type == V_75 ? L_1 : NULL ;
}
static void F_38 ( struct V_4 * V_5 )
{
F_39 ( V_5 -> V_76 , V_77 ) ;
F_40 ( V_5 -> V_10 ) ;
V_5 -> V_10 = NULL ;
}
static int F_41 ( struct V_4 * V_5 )
{
int V_52 ;
F_42 ( L_2 ,
V_5 , ( unsigned long long ) V_5 -> V_76 ) ;
if ( ! F_43 ( V_5 -> V_76 , V_77 , L_1 ) ) {
F_44 ( V_5 -> V_78 , L_3 ) ;
return - V_79 ;
}
V_5 -> V_10 = F_45 ( V_5 -> V_76 , V_77 ) ;
if ( ! V_5 -> V_10 ) {
F_44 ( V_5 -> V_78 , L_4 ) ;
F_39 ( V_5 -> V_76 , V_77 ) ;
return - V_79 ;
}
V_5 -> V_8 = & V_80 ;
V_52 = F_9 ( V_64 , V_5 ) ;
F_10 ( V_63 , V_64 , V_5 ) ;
V_52 = F_9 ( V_48 , V_5 ) ;
if ( ( V_52 & V_54 ) != V_54 )
V_5 -> V_8 = & V_81 ;
return 0 ;
}
static void F_46 ( struct V_4 * V_5 , int V_51 )
{
if ( ! F_41 ( V_5 ) )
V_5 -> type = V_75 ;
}
static int F_47 ( struct V_4 * V_5 , struct V_82 * V_83 )
{
return - V_84 ;
}
static int F_48 ( struct V_4 * V_5 )
{
if ( ! ( F_9 ( V_48 , V_5 ) & V_19 ) )
return V_85 ;
return F_9 ( V_24 , V_5 ) ;
}
static void F_49 ( struct V_4 * V_5 , unsigned char V_16 )
{
while ( F_9 ( V_48 , V_5 ) & V_36 )
F_50 () ;
F_10 ( V_16 , V_38 , V_5 ) ;
}
static void F_51 ( struct V_4 * V_5 )
{
T_4 V_2 ;
unsigned long V_86 ;
V_86 = V_87 + F_52 ( 1000 ) ;
while ( 1 ) {
V_2 = F_9 ( V_48 , V_5 ) ;
if ( ( V_2 & V_36 ) == 0 )
break;
if ( F_53 ( V_87 , V_86 ) ) {
F_54 ( V_5 -> V_78 ,
L_5 ) ;
break;
}
F_50 () ;
}
}
static void F_55 ( struct V_4 * V_5 , int V_16 )
{
F_51 ( V_5 ) ;
F_10 ( V_16 , V_38 , V_5 ) ;
}
static void F_56 ( struct V_88 * V_89 , const char * V_90 ,
unsigned int V_91 )
{
struct V_4 * V_5 = & V_92 [ V_89 -> V_93 ] ;
unsigned long V_51 ;
unsigned int V_94 ;
int V_95 = 1 ;
if ( V_96 ) {
V_95 = F_57 ( & V_5 -> V_53 , V_51 ) ;
} else
F_21 ( & V_5 -> V_53 , V_51 ) ;
V_94 = F_9 ( V_48 , V_5 ) & V_97 ;
F_10 ( 0 , V_64 , V_5 ) ;
F_58 ( V_5 , V_90 , V_91 , F_55 ) ;
F_51 ( V_5 ) ;
if ( V_94 )
F_10 ( V_65 , V_64 , V_5 ) ;
if ( V_95 )
F_22 ( & V_5 -> V_53 , V_51 ) ;
}
static int F_59 ( struct V_88 * V_89 , char * V_98 )
{
struct V_4 * V_5 ;
int V_69 = 9600 ;
int V_99 = 8 ;
int V_26 = 'n' ;
int V_100 = 'n' ;
if ( V_89 -> V_93 < 0 || V_89 -> V_93 >= V_101 )
return - V_84 ;
V_5 = & V_92 [ V_89 -> V_93 ] ;
if ( ! V_5 -> V_76 ) {
F_42 ( L_6 , V_89 -> V_93 ) ;
return - V_102 ;
}
if ( ! V_5 -> V_10 ) {
if ( F_41 ( V_5 ) )
return - V_102 ;
}
if ( V_98 )
F_60 ( V_98 , & V_69 , & V_26 , & V_99 , & V_100 ) ;
return F_61 ( V_5 , V_89 , V_69 , V_26 , V_99 , V_100 ) ;
}
static int T_5 F_62 ( void )
{
F_63 ( & V_103 ) ;
return 0 ;
}
static int F_64 ( struct V_104 * V_78 , int V_105 , T_1 V_106 , int V_44 )
{
struct V_4 * V_5 ;
int V_107 ;
if ( V_105 < 0 ) {
for ( V_105 = 0 ; V_105 < V_101 ; V_105 ++ )
if ( V_92 [ V_105 ] . V_76 == 0 )
break;
}
if ( V_105 < 0 || V_105 >= V_101 ) {
F_44 ( V_78 , L_7 , V_108 , V_105 ) ;
return - V_84 ;
}
if ( ( V_92 [ V_105 ] . V_76 ) && ( V_92 [ V_105 ] . V_76 != V_106 ) ) {
F_44 ( V_78 , L_8 ,
V_108 , V_105 ) ;
return - V_79 ;
}
V_5 = & V_92 [ V_105 ] ;
F_65 ( & V_5 -> V_53 ) ;
V_5 -> V_109 = 16 ;
V_5 -> V_110 = 2 ;
V_5 -> V_111 = V_112 ;
V_5 -> V_113 = 1 ;
V_5 -> V_76 = V_106 ;
V_5 -> V_10 = NULL ;
V_5 -> V_114 = & V_115 ;
V_5 -> V_44 = V_44 ;
V_5 -> V_51 = V_116 ;
V_5 -> V_78 = V_78 ;
V_5 -> type = V_117 ;
V_5 -> line = V_105 ;
F_66 ( V_78 , V_5 ) ;
V_107 = F_67 ( & V_118 , V_5 ) ;
if ( V_107 ) {
F_44 ( V_78 , L_9 , V_107 ) ;
V_5 -> V_76 = 0 ;
F_66 ( V_78 , NULL ) ;
return V_107 ;
}
return 0 ;
}
static int F_68 ( struct V_104 * V_78 )
{
struct V_4 * V_5 = F_69 ( V_78 ) ;
int V_107 = 0 ;
if ( V_5 ) {
V_107 = F_70 ( & V_118 , V_5 ) ;
F_66 ( V_78 , NULL ) ;
V_5 -> V_76 = 0 ;
}
return V_107 ;
}
static int F_71 ( struct V_119 * V_120 )
{
struct V_121 * V_122 , * V_123 ;
int V_105 = V_120 -> V_105 ;
#ifdef F_72
const T_6 * V_124 ;
V_124 = F_73 ( V_120 -> V_78 . V_125 , L_10 , NULL ) ;
if ( V_124 )
V_105 = F_74 ( V_124 ) ;
#endif
V_122 = F_75 ( V_120 , V_126 , 0 ) ;
if ( ! V_122 )
return - V_102 ;
V_123 = F_75 ( V_120 , V_127 , 0 ) ;
if ( ! V_123 )
return - V_102 ;
return F_64 ( & V_120 -> V_78 , V_105 , V_122 -> V_128 , V_123 -> V_128 ) ;
}
static int F_76 ( struct V_119 * V_120 )
{
return F_68 ( & V_120 -> V_78 ) ;
}
static int T_5 F_77 ( void )
{
int V_52 ;
F_42 ( L_11 ) ;
V_52 = F_78 ( & V_118 ) ;
if ( V_52 )
goto V_129;
F_42 ( L_12 ) ;
V_52 = F_79 ( & V_130 ) ;
if ( V_52 )
goto V_131;
return 0 ;
V_131:
F_80 ( & V_118 ) ;
V_129:
F_81 ( L_13 , V_52 ) ;
return V_52 ;
}
static void T_7 F_82 ( void )
{
F_83 ( & V_130 ) ;
F_80 ( & V_118 ) ;
}
