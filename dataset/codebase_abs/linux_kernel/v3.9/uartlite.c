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
int V_86 ;
T_4 V_2 ;
for ( V_86 = 0 ; V_86 < 100000 ; V_86 ++ ) {
V_2 = F_9 ( V_48 , V_5 ) ;
if ( ( V_2 & V_36 ) == 0 )
break;
F_50 () ;
}
}
static void F_52 ( struct V_4 * V_5 , int V_16 )
{
F_51 ( V_5 ) ;
F_10 ( V_16 , V_38 , V_5 ) ;
}
static void F_53 ( struct V_87 * V_88 , const char * V_89 ,
unsigned int V_90 )
{
struct V_4 * V_5 = & V_91 [ V_88 -> V_92 ] ;
unsigned long V_51 ;
unsigned int V_93 ;
int V_94 = 1 ;
if ( V_95 ) {
V_94 = F_54 ( & V_5 -> V_53 , V_51 ) ;
} else
F_21 ( & V_5 -> V_53 , V_51 ) ;
V_93 = F_9 ( V_48 , V_5 ) & V_96 ;
F_10 ( 0 , V_64 , V_5 ) ;
F_55 ( V_5 , V_89 , V_90 , F_52 ) ;
F_51 ( V_5 ) ;
if ( V_93 )
F_10 ( V_65 , V_64 , V_5 ) ;
if ( V_94 )
F_22 ( & V_5 -> V_53 , V_51 ) ;
}
static int F_56 ( struct V_87 * V_88 , char * V_97 )
{
struct V_4 * V_5 ;
int V_69 = 9600 ;
int V_98 = 8 ;
int V_26 = 'n' ;
int V_99 = 'n' ;
if ( V_88 -> V_92 < 0 || V_88 -> V_92 >= V_100 )
return - V_84 ;
V_5 = & V_91 [ V_88 -> V_92 ] ;
if ( ! V_5 -> V_76 ) {
F_42 ( L_5 , V_88 -> V_92 ) ;
return - V_101 ;
}
if ( ! V_5 -> V_10 ) {
if ( F_41 ( V_5 ) )
return - V_101 ;
}
if ( V_97 )
F_57 ( V_97 , & V_69 , & V_26 , & V_98 , & V_99 ) ;
return F_58 ( V_5 , V_88 , V_69 , V_26 , V_98 , V_99 ) ;
}
static int T_5 F_59 ( void )
{
F_60 ( & V_102 ) ;
return 0 ;
}
static int F_61 ( struct V_103 * V_78 , int V_104 , T_1 V_105 , int V_44 )
{
struct V_4 * V_5 ;
int V_106 ;
if ( V_104 < 0 ) {
for ( V_104 = 0 ; V_104 < V_100 ; V_104 ++ )
if ( V_91 [ V_104 ] . V_76 == 0 )
break;
}
if ( V_104 < 0 || V_104 >= V_100 ) {
F_44 ( V_78 , L_6 , V_107 , V_104 ) ;
return - V_84 ;
}
if ( ( V_91 [ V_104 ] . V_76 ) && ( V_91 [ V_104 ] . V_76 != V_105 ) ) {
F_44 ( V_78 , L_7 ,
V_107 , V_104 ) ;
return - V_79 ;
}
V_5 = & V_91 [ V_104 ] ;
F_62 ( & V_5 -> V_53 ) ;
V_5 -> V_108 = 16 ;
V_5 -> V_109 = 2 ;
V_5 -> V_110 = V_111 ;
V_5 -> V_112 = 1 ;
V_5 -> V_76 = V_105 ;
V_5 -> V_10 = NULL ;
V_5 -> V_113 = & V_114 ;
V_5 -> V_44 = V_44 ;
V_5 -> V_51 = V_115 ;
V_5 -> V_78 = V_78 ;
V_5 -> type = V_116 ;
V_5 -> line = V_104 ;
F_63 ( V_78 , V_5 ) ;
V_106 = F_64 ( & V_117 , V_5 ) ;
if ( V_106 ) {
F_44 ( V_78 , L_8 , V_106 ) ;
V_5 -> V_76 = 0 ;
F_63 ( V_78 , NULL ) ;
return V_106 ;
}
return 0 ;
}
static int F_65 ( struct V_103 * V_78 )
{
struct V_4 * V_5 = F_66 ( V_78 ) ;
int V_106 = 0 ;
if ( V_5 ) {
V_106 = F_67 ( & V_117 , V_5 ) ;
F_63 ( V_78 , NULL ) ;
V_5 -> V_76 = 0 ;
}
return V_106 ;
}
static int F_68 ( struct V_118 * V_119 )
{
struct V_120 * V_121 , * V_122 ;
int V_104 = V_119 -> V_104 ;
#ifdef F_69
const T_6 * V_123 ;
V_123 = F_70 ( V_119 -> V_78 . V_124 , L_9 , NULL ) ;
if ( V_123 )
V_104 = F_71 ( V_123 ) ;
#endif
V_121 = F_72 ( V_119 , V_125 , 0 ) ;
if ( ! V_121 )
return - V_101 ;
V_122 = F_72 ( V_119 , V_126 , 0 ) ;
if ( ! V_122 )
return - V_101 ;
return F_61 ( & V_119 -> V_78 , V_104 , V_121 -> V_127 , V_122 -> V_127 ) ;
}
static int F_73 ( struct V_118 * V_119 )
{
return F_65 ( & V_119 -> V_78 ) ;
}
static int T_5 F_74 ( void )
{
int V_52 ;
F_42 ( L_10 ) ;
V_52 = F_75 ( & V_117 ) ;
if ( V_52 )
goto V_128;
F_42 ( L_11 ) ;
V_52 = F_76 ( & V_129 ) ;
if ( V_52 )
goto V_130;
return 0 ;
V_130:
F_77 ( & V_117 ) ;
V_128:
F_78 ( L_12 , V_52 ) ;
return V_52 ;
}
static void T_7 F_79 ( void )
{
F_80 ( & V_129 ) ;
F_77 ( & V_117 ) ;
}
