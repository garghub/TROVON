static int F_1 ( T_1 V_1 )
{
int V_2 = F_2 ( V_1 ) ;
return V_2 ? V_2 - 1 : 32 ;
}
static inline int F_3 ( int V_3 , int V_4 )
{
return V_3 + ( V_4 ? 16 : 0 ) ;
}
static T_1 F_4 ( T_1 V_5 , T_1 V_6 )
{
return F_5 ( V_5 + V_7 . abs ) & V_6 ;
}
static void F_6 ( T_1 V_5 , T_1 V_6 , T_1 V_8 )
{
F_7 ( F_4 ( V_5 , ~ V_6 ) | ( V_8 & V_6 ) ,
V_5 + V_7 . abs ) ;
}
static T_1 F_8 ( T_1 V_5 , T_1 V_6 )
{
return F_5 ( V_5 + V_7 . V_9 ) & V_6 ;
}
static void F_9 ( T_1 V_5 , T_1 V_6 , T_1 V_8 )
{
F_7 ( F_8 ( V_5 , ~ V_6 ) | ( V_8 & V_6 ) ,
V_5 + V_7 . V_9 ) ;
}
static T_1 F_10 ( T_1 V_5 , T_1 V_6 )
{
T_1 V_10 = F_8 ( V_5 , V_6 ) ;
F_7 ( V_10 , V_5 + V_7 . V_9 ) ;
return V_10 ;
}
static T_1 F_11 ( T_1 V_5 , T_1 V_6 , T_1 V_8 )
{
T_1 V_10 = F_8 ( V_5 , ~ 0 ) ;
F_7 ( ( V_10 & ~ V_6 ) | ( V_8 & V_6 ) , V_5 + V_7 . V_9 ) ;
return ( V_10 & V_6 ) >> F_1 ( V_6 ) ;
}
static int F_12 ( void T_2 * V_11 )
{
T_1 V_10 ;
V_7 . abs = V_11 ;
V_7 . V_9 = V_7 . abs ;
V_7 . V_9 += V_12 ;
V_7 . V_9 += F_13 ( V_7 . V_9 ) ;
V_10 = F_4 ( V_13 , V_14 ) >> F_1 ( V_14 ) ;
V_7 . V_15 = V_10 ;
V_7 . V_16 = V_7 . V_9 - V_7 . abs ;
V_7 . V_16 += V_17 ;
V_7 . V_16 /= sizeof( T_1 ) ;
V_10 = F_4 ( V_18 , V_19 ) >> F_1 ( V_19 ) ;
V_20 = V_10 * 2 ;
if ( V_20 == 0 || V_20 > V_21 )
return - V_22 ;
return 0 ;
}
static int F_14 ( struct V_23 * V_24 )
{
F_9 ( V_25 , ~ 0 , ~ 0 ) ;
F_9 ( V_26 , V_27 , 0 ) ;
F_9 ( V_26 , V_28 , V_28 ) ;
while ( F_8 ( V_26 , V_28 ) )
F_15 ( 10 ) ;
if ( V_24 -> V_29 -> V_30 )
V_24 -> V_29 -> V_30 ( V_24 ,
V_31 ) ;
if ( V_24 -> V_29 -> V_32 & V_33 )
F_9 ( V_34 , V_35 , V_35 ) ;
F_9 ( V_34 , V_36 , V_37 ) ;
F_9 ( V_34 , V_36 , V_38 ) ;
F_9 ( V_34 , V_39 , V_39 ) ;
if ( F_8 ( V_34 , V_36 ) != V_38 ) {
F_16 ( L_1 ) ;
F_16 ( L_2 , V_7 . V_15 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_17 ( T_1 V_40 )
{
if ( V_40 ) {
F_9 ( V_41 , ~ 0 , V_40 ) ;
F_9 ( V_42 , ~ 0 ,
V_43 | V_44 | V_45 | V_46 | V_47 ) ;
F_9 ( V_26 , V_27 , V_27 ) ;
} else {
F_9 ( V_26 , V_27 , 0 ) ;
F_9 ( V_42 , ~ 0 , 0 ) ;
}
return 0 ;
}
static int F_18 ( int V_3 , int V_4 )
{
int V_2 = F_3 ( V_3 , V_4 ) ;
do {
F_9 ( V_25 , F_19 ( V_2 ) , F_19 ( V_2 ) ) ;
while ( F_8 ( V_25 , F_19 ( V_2 ) ) )
F_20 () ;
} while ( F_8 ( V_48 , F_19 ( V_2 ) ) );
return 0 ;
}
static int F_21 ( int V_3 , int V_4 )
{
F_18 ( V_3 , V_4 ) ;
F_9 ( V_49 + V_3 * sizeof( T_1 ) ,
V_4 ? V_50 : V_51 , 0 ) ;
return 0 ;
}
static int F_22 ( int V_3 , int V_4 , int type )
{
T_1 V_6 , V_8 ;
if ( V_4 ) {
V_6 = V_52 ;
V_8 = type << F_1 ( V_6 ) ;
V_6 |= V_53 ;
V_6 |= V_54 ;
V_8 |= V_54 ;
V_6 |= V_50 ;
V_8 |= V_50 ;
} else {
V_6 = V_55 ;
V_8 = type << F_1 ( V_6 ) ;
V_6 |= V_56 ;
V_6 |= V_57 ;
V_8 |= V_57 ;
V_6 |= V_51 ;
V_8 |= V_51 ;
}
F_9 ( V_49 + V_3 * sizeof( T_1 ) , V_6 , V_8 ) ;
return 0 ;
}
static int F_23 ( int V_3 , int V_4 )
{
T_1 V_6 = V_4 ? V_53 : V_56 ;
return F_8 ( V_49 + V_3 * sizeof( T_1 ) , V_6 ) ? 1 : 0 ;
}
static int F_24 ( int V_2 )
{
return F_10 ( V_58 , F_19 ( V_2 ) ) ;
}
static int F_25 ( int V_3 , int V_4 , int V_59 )
{
int V_2 = F_3 ( V_3 , V_4 ) ;
if ( V_59 && V_4 == V_60 && F_8 ( V_58 , F_19 ( V_3 ) ) )
return - V_61 ;
F_9 ( V_62 , F_19 ( V_2 ) , F_19 ( V_2 ) ) ;
while ( F_8 ( V_62 , F_19 ( V_2 ) ) )
F_20 () ;
if ( V_59 && V_4 == V_60 && F_8 ( V_58 , F_19 ( V_3 ) ) )
return - V_61 ;
return 0 ;
}
static int F_26 ( int V_3 , int V_4 , int V_63 )
{
if ( V_63 != 0 && V_63 != 1 )
return - V_64 ;
do {
T_1 V_5 = V_49 + V_3 * sizeof( T_1 ) ;
T_1 V_65 = V_4 ? V_53 : V_56 ;
T_1 V_66 = V_4 ? V_54 : V_57 ;
F_9 ( V_5 , V_65 | V_66 , V_63 ? V_65 : V_66 ) ;
} while ( V_63 != F_23 ( V_3 , V_4 ) );
return 0 ;
}
static int F_27 ( int V_2 )
{
if ( V_2 >= V_67 )
return - V_64 ;
F_9 ( V_42 , F_19 ( V_2 ) , 0 ) ;
F_9 ( V_68 , F_19 ( V_2 ) , F_19 ( V_2 ) ) ;
return 0 ;
}
static int F_28 ( int V_2 )
{
if ( V_2 >= V_67 )
return - V_64 ;
F_6 ( V_69 , V_70 , V_70 ) ;
F_9 ( V_42 , F_19 ( V_2 ) , F_19 ( V_2 ) ) ;
F_9 ( V_68 , F_19 ( V_2 ) , F_19 ( V_2 ) ) ;
F_6 ( V_69 , V_70 , 0 ) ;
return 0 ;
}
static int F_29 ( void )
{
return V_7 . V_15 ? F_8 ( V_71 , V_72 ) :
F_8 ( V_73 , V_74 ) ;
}
static T_3 F_30 ( void )
{
return F_8 ( V_73 , V_75 ) >> F_1 ( V_75 ) ;
}
static int F_31 ( T_3 V_76 )
{
const T_3 V_77 = 7 ;
if ( V_76 > V_77 )
return - V_64 ;
F_9 ( V_73 , V_75 , V_76 << F_1 ( V_75 ) ) ;
return 0 ;
}
static T_1 F_32 ( void )
{
return F_8 ( V_42 , ~ 0 ) ;
}
static T_1 F_33 ( void )
{
return F_8 ( V_68 , ~ 0 ) ;
}
static T_4 F_34 ( T_1 * V_78 , T_4 V_16 )
{
unsigned V_79 ;
if ( V_16 > V_7 . V_16 )
V_16 = V_7 . V_16 ;
for ( V_79 = 0 ; V_79 < V_16 ; V_79 ++ )
V_78 [ V_79 ] = F_4 ( V_79 * sizeof( T_1 ) , ~ 0 ) ;
return V_16 ;
}
static int F_35 ( T_5 V_5 , T_1 V_8 )
{
V_5 /= sizeof( T_1 ) ;
if ( V_5 >= V_7 . V_16 )
return - V_64 ;
V_5 *= sizeof( T_1 ) ;
F_6 ( V_5 , ~ 0 , V_8 ) ;
return 0 ;
}
static int F_36 ( int V_2 )
{
return F_10 ( V_80 , F_19 ( V_2 ) ) ;
}
static T_1 F_37 ( void )
{
T_1 V_10 = F_33 () & F_32 () ;
F_9 ( V_68 , ~ 0 , V_10 ) ;
return V_10 ;
}
static int F_38 ( void )
{
return F_11 ( V_26 , V_81 , 0 ) ;
}
static int F_39 ( void )
{
return F_11 ( V_26 , V_81 , V_81 ) ;
}
static int F_40 ( T_3 V_63 )
{
F_9 ( V_82 , V_83 | V_84 ,
V_63 << F_1 ( V_83 ) | V_84 ) ;
return 0 ;
}
static int F_41 ( void )
{
F_40 ( 0 ) ;
F_9 ( V_25 , ~ 0 , ~ 0 ) ;
F_9 ( V_58 , 0 , 0 ) ;
F_9 ( V_80 , 0 , 0 ) ;
while ( F_8 ( V_62 , ~ 0 ) )
F_15 ( 10 ) ;
return 0 ;
}
static T_6 F_42 ( struct V_85 * V_86 , struct V_87 * V_88 ,
char * V_78 )
{
struct V_23 * V_24 = F_43 ( V_86 , struct V_23 , V_89 . V_86 ) ;
struct V_90 * V_89 = & V_24 -> V_89 ;
int V_2 = 0 ;
F_44 ( L_3 , V_91 , V_78 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
return 0 ;
}
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_5 ,
V_89 -> V_93 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_6 ,
V_89 -> V_94 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_7 ,
V_89 -> V_95 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_8 ,
V_89 -> V_96 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_9 ,
V_89 -> V_97 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_10 ,
V_89 -> V_98 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_11 ,
V_89 -> V_99 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_12 ,
( V_89 -> V_100 ? V_89 -> V_100 : L_13 ) ) ;
return V_2 ;
}
static T_6 F_47 ( struct V_85 * V_86 , struct V_87 * V_88 ,
char * V_78 )
{
struct V_23 * V_24 = F_43 ( V_86 , struct V_23 , V_89 . V_86 ) ;
struct V_101 * V_102 = V_24 -> V_102 ;
int V_2 = 0 ;
F_44 ( L_3 , V_91 , V_78 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
return 0 ;
}
if ( V_102 == NULL )
return F_46 ( V_78 , V_92 ,
L_14 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_15 ,
( V_102 -> V_103 ? V_102 -> V_103 : L_13 ) ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_16 ,
V_102 -> V_93 ) ;
return V_2 ;
}
static void F_48 ( unsigned * V_104 )
{
* V_104 = ( * V_104 - 1 ) & ( V_105 - 1 ) ;
}
static void F_49 ( unsigned * V_104 )
{
* V_104 = ( * V_104 + 1 ) & ( V_105 - 1 ) ;
}
static void F_50 ( T_3 V_5 , const char * V_100 , int V_106 , const char * V_107 )
{
struct V_108 V_109 ;
unsigned int V_110 ;
unsigned long V_32 ;
F_51 ( & V_111 . V_112 , V_32 ) ;
F_52 ( & V_109 ) ;
V_110 = V_109 . V_113 & 0xFFFF ;
V_110 = V_110 * 1000000 + V_109 . V_114 ;
F_46 ( V_111 . V_78 [ V_111 . V_104 ] , V_115 ,
L_17 ,
V_110 , V_5 , V_100 , V_106 , V_107 ) ;
F_49 ( & V_111 . V_104 ) ;
F_53 ( & V_111 . V_112 , V_32 ) ;
if ( V_111 . V_116 != 0 )
F_54 ( L_17 ,
V_110 , V_5 , V_100 , V_106 , V_107 ) ;
}
static void F_55 ( T_3 V_5 , const T_1 V_117 , int V_106 )
{
char V_118 [ V_115 ] ;
F_46 ( V_118 , sizeof( V_118 ) , L_18 ,
( int ) ( V_117 & V_119 ) >> F_1 ( V_119 ) ,
( int ) ( V_117 & V_120 ) >> F_1 ( V_120 ) ) ;
F_50 ( V_5 , L_19 , V_106 , V_118 ) ;
}
static void F_56 ( T_3 V_5 , const char * V_100 , int V_106 )
{
if ( V_100 != NULL )
F_50 ( V_5 , V_100 , V_106 , L_13 ) ;
}
static void F_57 ( T_3 V_5 , const struct V_121 * V_122 , int V_106 )
{
char V_118 [ V_115 ] ;
if ( V_122 != NULL ) {
F_46 ( V_118 , sizeof( V_118 ) ,
L_20 , ! V_122 -> V_123 , V_122 -> V_124 ) ;
F_50 ( V_5 , L_21 , V_106 , V_118 ) ;
}
}
static void F_58 ( T_3 V_5 , const struct V_125 * V_122 )
{
char V_118 [ V_115 ] ;
if ( V_122 != NULL ) {
F_46 ( V_118 , sizeof( V_118 ) ,
L_22 , V_122 -> V_126 ,
V_122 -> V_127 , F_59 ( V_122 -> V_128 ) ,
F_59 ( V_122 -> V_129 ) , F_59 ( V_122 -> V_130 ) ) ;
F_50 ( V_5 , L_23 , 0 , V_118 ) ;
}
}
static T_6 F_60 ( struct V_85 * V_86 , struct V_87 * V_88 ,
char * V_78 )
{
unsigned long V_32 ;
unsigned V_79 , V_131 , V_2 = 0 ;
F_44 ( L_3 , V_91 , V_78 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
return 0 ;
}
F_61 ( & V_111 . V_112 , V_32 ) ;
V_79 = V_111 . V_104 ;
for ( F_48 ( & V_79 ) ; V_79 != V_111 . V_104 ; F_48 ( & V_79 ) ) {
V_2 += strlen ( V_111 . V_78 [ V_79 ] ) ;
if ( V_2 >= V_92 ) {
V_2 -= strlen ( V_111 . V_78 [ V_79 ] ) ;
break;
}
}
for ( V_131 = 0 , F_49 ( & V_79 ) ; V_131 < V_2 ; F_49 ( & V_79 ) )
V_131 += F_46 ( V_78 + V_131 , V_92 - V_131 ,
L_24 , V_111 . V_78 [ V_79 ] ) ;
F_62 ( & V_111 . V_112 , V_32 ) ;
return V_2 ;
}
static T_6 F_63 ( struct V_85 * V_86 , struct V_87 * V_88 ,
const char * V_78 , T_4 V_132 )
{
unsigned V_116 ;
F_44 ( L_25 , V_91 , V_78 , V_132 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
goto V_133;
}
if ( sscanf ( V_78 , L_26 , & V_116 ) != 1 || V_116 > 1 ) {
F_45 ( V_86 , L_27 ) ;
goto V_133;
}
V_111 . V_116 = V_116 ;
F_64 ( V_86 , L_28 , V_111 . V_116 ) ;
V_133:
return V_132 ;
}
static T_6 F_65 ( struct V_85 * V_86 , struct V_87 * V_88 ,
char * V_78 )
{
struct V_23 * V_24 = F_43 ( V_86 , struct V_23 , V_89 . V_86 ) ;
unsigned long V_32 ;
T_1 V_134 ;
unsigned V_79 , V_131 , V_2 = 0 ;
F_44 ( L_3 , V_91 , V_78 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
return 0 ;
}
F_66 ( V_24 -> V_135 , V_32 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 ,
L_29 , F_33 () ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 ,
L_30 , F_32 () ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_31 ,
V_136 . V_137 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_32 ,
V_136 . V_138 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_33 ,
V_136 . V_139 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_34 ,
V_136 . V_140 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_35 ,
V_136 . V_141 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_36 ,
V_136 . V_142 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_37 ,
V_136 . V_143 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_38 ,
V_136 . V_144 . V_145 ) ;
for ( V_79 = V_136 . V_144 . V_104 , V_131 = 0 ; V_131 <= V_146 ; V_131 ++ , V_79 ++ ) {
V_79 &= V_146 ;
V_134 = V_136 . V_144 . V_78 [ V_79 ] ;
if ( V_43 & V_134 )
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_39 ) ;
V_134 &= ~ V_43 ;
if ( V_44 & V_134 )
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_40 ) ;
V_134 &= ~ V_44 ;
if ( V_45 & V_134 )
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_41 ) ;
V_134 &= ~ V_45 ;
if ( V_46 & V_134 )
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_42 ) ;
V_134 &= ~ V_46 ;
if ( V_47 & V_134 )
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_43 ) ;
V_134 &= ~ V_47 ;
if ( V_134 )
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_44 ) ;
if ( V_136 . V_144 . V_78 [ V_79 ] )
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 , L_45 ) ;
}
F_67 ( V_24 -> V_135 , V_32 ) ;
return V_2 ;
}
static T_6 F_68 ( struct V_85 * V_86 , struct V_87 * V_88 ,
const char * V_78 , T_4 V_132 )
{
struct V_23 * V_24 = F_43 ( V_86 , struct V_23 , V_89 . V_86 ) ;
unsigned long V_32 ;
unsigned V_147 , V_148 ;
F_44 ( L_25 , V_91 , V_78 , V_132 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
goto V_133;
}
if ( sscanf ( V_78 , L_46 , & V_147 , & V_148 ) != 2 || V_147 > 1 ) {
F_45 ( V_86 , L_47 ) ;
goto V_133;
}
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( V_147 ) {
if ( F_28 ( V_148 ) )
F_45 ( V_86 , L_48 ) ;
else
V_136 . V_137 ++ ;
} else {
if ( F_27 ( V_148 ) )
F_45 ( V_86 , L_48 ) ;
}
F_67 ( V_24 -> V_135 , V_32 ) ;
V_133:
return V_132 ;
}
static T_6 F_69 ( struct V_85 * V_86 ,
struct V_87 * V_88 , char * V_78 )
{
struct V_23 * V_24 = F_43 ( V_86 , struct V_23 , V_89 . V_86 ) ;
unsigned long V_32 ;
unsigned V_76 ;
F_44 ( L_3 , V_91 , V_78 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
return 0 ;
}
F_66 ( V_24 -> V_135 , V_32 ) ;
V_76 = F_30 () ;
F_67 ( V_24 -> V_135 , V_32 ) ;
return F_46 ( V_78 , V_92 , L_49 , V_76 ) ;
}
static T_6 F_70 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
const char * V_78 , T_4 V_132 )
{
struct V_23 * V_24 = F_43 ( V_86 , struct V_23 , V_89 . V_86 ) ;
unsigned long V_32 ;
unsigned V_76 ;
F_44 ( L_25 , V_91 , V_78 , V_132 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
goto V_133;
}
if ( sscanf ( V_78 , L_26 , & V_76 ) != 1 ) {
F_45 ( V_86 , L_50 ) ;
goto V_133;
}
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( F_31 ( V_76 ) )
F_45 ( V_86 , L_51 ) ;
F_67 ( V_24 -> V_135 , V_32 ) ;
V_133:
return V_132 ;
}
static T_6 F_71 ( struct V_85 * V_86 , struct V_87 * V_88 ,
char * V_78 )
{
struct V_23 * V_24 = F_43 ( V_86 , struct V_23 , V_89 . V_86 ) ;
unsigned long V_32 ;
unsigned V_79 , V_131 , V_2 = 0 ;
F_44 ( L_3 , V_91 , V_78 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
return 0 ;
}
F_66 ( V_24 -> V_135 , V_32 ) ;
for ( V_79 = 0 ; V_79 < V_20 / 2 ; V_79 ++ ) {
struct V_149 * V_150 = & V_24 -> V_149 [ V_79 ] ;
struct V_149 * V_151 = & V_24 -> V_149 [ V_79 + V_20 / 2 ] ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 ,
L_52 ,
V_79 , ( T_1 ) V_150 -> V_152 . V_40 , ( T_1 ) V_151 -> V_152 . V_40 ) ;
for ( V_131 = 0 ; V_131 < ( sizeof( struct V_153 ) / sizeof( T_1 ) ) ; V_131 ++ ) {
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 ,
L_53 , V_131 ,
* ( ( T_1 * ) V_150 -> V_152 . V_154 + V_131 ) ,
* ( ( T_1 * ) V_151 -> V_152 . V_154 + V_131 ) ) ;
}
}
F_67 ( V_24 -> V_135 , V_32 ) ;
return V_2 ;
}
static T_6 F_72 ( struct V_85 * V_86 ,
struct V_87 * V_88 , char * V_78 )
{
struct V_23 * V_24 = F_43 ( V_86 , struct V_23 , V_89 . V_86 ) ;
unsigned long V_32 ;
T_1 V_155 [ 512 ] ;
unsigned V_79 , V_156 , V_2 = 0 ;
F_44 ( L_3 , V_91 , V_78 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
return 0 ;
}
F_66 ( V_24 -> V_135 , V_32 ) ;
V_156 = F_34 ( V_155 , sizeof( V_155 ) / sizeof( T_1 ) ) ;
F_67 ( V_24 -> V_135 , V_32 ) ;
for ( V_79 = 0 ; V_79 < V_156 ; V_79 ++ ) {
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 ,
L_54 ,
V_79 * ( unsigned ) sizeof( T_1 ) , V_155 [ V_79 ] ) ;
}
return V_2 ;
}
static T_6 F_73 ( struct V_85 * V_86 ,
struct V_87 * V_88 ,
const char * V_78 , T_4 V_132 )
{
struct V_23 * V_24 = F_43 ( V_86 , struct V_23 , V_89 . V_86 ) ;
unsigned long V_5 , V_8 , V_32 ;
F_44 ( L_25 , V_91 , V_78 , V_132 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
goto V_133;
}
if ( sscanf ( V_78 , L_55 , & V_5 , & V_8 ) != 2 ) {
F_45 ( V_86 , L_56 ) ;
goto V_133;
}
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( F_35 ( V_5 , V_8 ) )
F_45 ( V_86 , L_57 ) ;
F_67 ( V_24 -> V_135 , V_32 ) ;
V_133:
return V_132 ;
}
static T_6 F_74 ( struct V_85 * V_86 , struct V_87 * V_88 ,
char * V_78 )
{
struct V_23 * V_24 = F_43 ( V_86 , struct V_23 , V_89 . V_86 ) ;
unsigned long V_32 ;
struct V_157 * V_154 = NULL ;
struct V_158 * V_122 = NULL ;
unsigned V_79 , V_131 , V_2 = 0 , V_159 = sizeof( struct V_160 ) / sizeof( T_1 ) ;
F_44 ( L_3 , V_91 , V_78 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
return 0 ;
}
F_66 ( V_24 -> V_135 , V_32 ) ;
for ( V_79 = 0 ; V_79 < V_20 ; V_79 ++ )
F_75 (ptr, &udc->ci13xxx_ep[i].qh.queue)
{
V_122 = F_76 ( V_154 , struct V_158 , V_161 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 ,
L_58 ,
V_79 % V_20 / 2 , ( T_1 ) V_122 -> V_40 ,
( ( V_79 < V_20 / 2 ) ? L_59 : L_60 ) ) ;
for ( V_131 = 0 ; V_131 < V_159 ; V_131 ++ )
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 ,
L_61 , V_131 ,
* ( ( T_1 * ) V_122 -> V_154 + V_131 ) ) ;
}
F_67 ( V_24 -> V_135 , V_32 ) ;
return V_2 ;
}
T_7 static int F_77 ( struct V_85 * V_86 )
{
int V_162 = 0 ;
if ( V_86 == NULL )
return - V_64 ;
V_162 = F_78 ( V_86 , & V_163 ) ;
if ( V_162 )
goto V_133;
V_162 = F_78 ( V_86 , & V_164 ) ;
if ( V_162 )
goto V_165;
V_162 = F_78 ( V_86 , & V_166 ) ;
if ( V_162 )
goto V_167;
V_162 = F_78 ( V_86 , & V_168 ) ;
if ( V_162 )
goto V_169;
V_162 = F_78 ( V_86 , & V_170 ) ;
if ( V_162 )
goto V_171;
V_162 = F_78 ( V_86 , & V_172 ) ;
if ( V_162 )
goto V_173;
V_162 = F_78 ( V_86 , & V_174 ) ;
if ( V_162 )
goto V_175;
V_162 = F_78 ( V_86 , & V_176 ) ;
if ( V_162 )
goto V_177;
return 0 ;
V_177:
F_79 ( V_86 , & V_174 ) ;
V_175:
F_79 ( V_86 , & V_172 ) ;
V_173:
F_79 ( V_86 , & V_170 ) ;
V_171:
F_79 ( V_86 , & V_168 ) ;
V_169:
F_79 ( V_86 , & V_166 ) ;
V_167:
F_79 ( V_86 , & V_164 ) ;
V_165:
F_79 ( V_86 , & V_163 ) ;
V_133:
return V_162 ;
}
T_7 static int F_80 ( struct V_85 * V_86 )
{
if ( V_86 == NULL )
return - V_64 ;
F_79 ( V_86 , & V_176 ) ;
F_79 ( V_86 , & V_174 ) ;
F_79 ( V_86 , & V_172 ) ;
F_79 ( V_86 , & V_170 ) ;
F_79 ( V_86 , & V_168 ) ;
F_79 ( V_86 , & V_166 ) ;
F_79 ( V_86 , & V_164 ) ;
F_79 ( V_86 , & V_163 ) ;
return 0 ;
}
static inline T_3 F_81 ( struct V_149 * V_178 )
{
return ( ( V_178 -> V_4 == V_179 ) ? V_180 : 0 ) | V_178 -> V_3 ;
}
static int F_82 ( struct V_149 * V_181 , struct V_158 * V_182 )
{
unsigned V_79 ;
int V_183 = 0 ;
unsigned V_124 = V_182 -> V_122 . V_124 ;
F_83 ( L_62 , V_181 , V_182 ) ;
if ( V_182 -> V_122 . V_106 == - V_184 )
return - V_184 ;
V_182 -> V_122 . V_106 = - V_184 ;
if ( V_124 && ! V_182 -> V_122 . V_40 ) {
V_182 -> V_122 . V_40 = \
F_84 ( V_181 -> V_85 , V_182 -> V_122 . V_78 ,
V_124 , V_181 -> V_4 ? V_185 :
V_186 ) ;
if ( V_182 -> V_122 . V_40 == 0 )
return - V_187 ;
V_182 -> V_188 = 1 ;
}
if ( V_182 -> V_122 . V_189 && V_124 && ( V_124 % V_181 -> V_178 . V_190 == 0 ) ) {
V_182 -> V_191 = F_85 ( V_181 -> V_192 , V_193 ,
& V_182 -> V_194 ) ;
if ( V_182 -> V_191 == NULL ) {
if ( V_182 -> V_188 ) {
F_86 ( V_181 -> V_85 , V_182 -> V_122 . V_40 ,
V_124 , V_181 -> V_4 ? V_185 :
V_186 ) ;
V_182 -> V_122 . V_40 = 0 ;
V_182 -> V_188 = 0 ;
}
return - V_187 ;
}
memset ( V_182 -> V_191 , 0 , sizeof( * V_182 -> V_191 ) ) ;
V_182 -> V_191 -> V_195 = V_196 ;
V_182 -> V_191 -> V_117 = V_197 ;
if ( ! V_182 -> V_122 . V_123 )
V_182 -> V_191 -> V_117 |= V_198 ;
}
memset ( V_182 -> V_154 , 0 , sizeof( * V_182 -> V_154 ) ) ;
V_182 -> V_154 -> V_117 = V_124 << F_1 ( V_119 ) ;
V_182 -> V_154 -> V_117 &= V_119 ;
V_182 -> V_154 -> V_117 |= V_197 ;
if ( V_182 -> V_191 ) {
V_182 -> V_154 -> V_195 = V_182 -> V_194 ;
} else {
V_182 -> V_154 -> V_195 = V_196 ;
if ( ! V_182 -> V_122 . V_123 )
V_182 -> V_154 -> V_117 |= V_198 ;
}
V_182 -> V_154 -> V_199 [ 0 ] = V_182 -> V_122 . V_40 ;
for ( V_79 = 1 ; V_79 < 5 ; V_79 ++ )
V_182 -> V_154 -> V_199 [ V_79 ] =
( V_182 -> V_122 . V_40 + V_79 * V_200 ) & ~ V_201 ;
if ( ! F_87 ( & V_181 -> V_152 . V_161 ) ) {
struct V_158 * V_202 ;
int V_2 = F_3 ( V_181 -> V_3 , V_181 -> V_4 ) ;
int V_203 ;
V_202 = F_76 ( V_181 -> V_152 . V_161 . V_204 ,
struct V_158 , V_161 ) ;
if ( V_202 -> V_191 )
V_202 -> V_191 -> V_195 = V_182 -> V_40 & V_205 ;
else
V_202 -> V_154 -> V_195 = V_182 -> V_40 & V_205 ;
F_88 () ;
if ( F_8 ( V_62 , F_19 ( V_2 ) ) )
goto V_133;
do {
F_9 ( V_26 , V_206 , V_206 ) ;
V_203 = F_8 ( V_48 , F_19 ( V_2 ) ) ;
} while ( ! F_8 ( V_26 , V_206 ) );
F_9 ( V_26 , V_206 , 0 ) ;
if ( V_203 )
goto V_133;
}
V_181 -> V_152 . V_154 -> V_207 . V_195 = V_182 -> V_40 ;
V_181 -> V_152 . V_154 -> V_207 . V_117 &= ~ V_120 ;
V_181 -> V_152 . V_154 -> V_9 |= V_208 ;
F_88 () ;
V_183 = F_25 ( V_181 -> V_3 , V_181 -> V_4 ,
V_181 -> type == V_209 ) ;
V_133:
return V_183 ;
}
static int F_89 ( struct V_149 * V_181 , struct V_158 * V_182 )
{
F_83 ( L_62 , V_181 , V_182 ) ;
if ( V_182 -> V_122 . V_106 != - V_184 )
return - V_64 ;
if ( ( V_197 & V_182 -> V_154 -> V_117 ) != 0 )
return - V_210 ;
if ( V_182 -> V_191 ) {
if ( ( V_197 & V_182 -> V_191 -> V_117 ) != 0 )
return - V_210 ;
F_90 ( V_181 -> V_192 , V_182 -> V_191 , V_182 -> V_194 ) ;
V_182 -> V_191 = NULL ;
}
V_182 -> V_122 . V_106 = 0 ;
if ( V_182 -> V_188 ) {
F_86 ( V_181 -> V_85 , V_182 -> V_122 . V_40 , V_182 -> V_122 . V_124 ,
V_181 -> V_4 ? V_185 : V_186 ) ;
V_182 -> V_122 . V_40 = 0 ;
V_182 -> V_188 = 0 ;
}
V_182 -> V_122 . V_106 = V_182 -> V_154 -> V_117 & V_120 ;
if ( ( V_211 & V_182 -> V_122 . V_106 ) != 0 )
V_182 -> V_122 . V_106 = - 1 ;
else if ( ( V_212 & V_182 -> V_122 . V_106 ) != 0 )
V_182 -> V_122 . V_106 = - 1 ;
else if ( ( V_213 & V_182 -> V_122 . V_106 ) != 0 )
V_182 -> V_122 . V_106 = - 1 ;
V_182 -> V_122 . V_214 = V_182 -> V_154 -> V_117 & V_119 ;
V_182 -> V_122 . V_214 >>= F_1 ( V_119 ) ;
V_182 -> V_122 . V_214 = V_182 -> V_122 . V_124 - V_182 -> V_122 . V_214 ;
V_182 -> V_122 . V_214 = V_182 -> V_122 . V_106 ? 0 : V_182 -> V_122 . V_214 ;
return V_182 -> V_122 . V_214 ;
}
static int F_91 ( struct V_149 * V_181 )
__releases( V_181 -> V_135 )
__acquires( V_181 -> V_135 )
{
F_83 ( L_63 , V_181 ) ;
if ( V_181 == NULL )
return - V_64 ;
F_18 ( V_181 -> V_3 , V_181 -> V_4 ) ;
while ( ! F_87 ( & V_181 -> V_152 . V_161 ) ) {
struct V_158 * V_182 = \
F_76 ( V_181 -> V_152 . V_161 . V_195 ,
struct V_158 , V_161 ) ;
F_92 ( & V_182 -> V_161 ) ;
V_182 -> V_122 . V_106 = - V_215 ;
if ( V_182 -> V_122 . V_216 != NULL ) {
F_93 ( V_181 -> V_135 ) ;
V_182 -> V_122 . V_216 ( & V_181 -> V_178 , & V_182 -> V_122 ) ;
F_94 ( V_181 -> V_135 ) ;
}
}
return 0 ;
}
static int F_95 ( struct V_90 * V_89 )
{
struct V_217 * V_178 ;
struct V_23 * V_24 = F_43 ( V_89 , struct V_23 , V_89 ) ;
unsigned long V_32 ;
F_83 ( L_63 , V_89 ) ;
if ( V_89 == NULL )
return - V_64 ;
F_66 ( V_24 -> V_135 , V_32 ) ;
V_24 -> V_89 . V_93 = V_218 ;
V_24 -> V_219 = 0 ;
V_24 -> V_220 = 0 ;
F_67 ( V_24 -> V_135 , V_32 ) ;
F_96 (ep, gadget) {
F_97 ( V_178 ) ;
}
F_97 ( & V_24 -> V_221 . V_178 ) ;
F_97 ( & V_24 -> V_222 . V_178 ) ;
V_24 -> V_102 -> V_223 ( V_89 ) ;
F_96 (ep, gadget) {
F_98 ( V_178 ) ;
}
if ( V_24 -> V_106 != NULL ) {
F_99 ( & V_24 -> V_222 . V_178 , V_24 -> V_106 ) ;
V_24 -> V_106 = NULL ;
}
return 0 ;
}
static void F_100 ( struct V_23 * V_24 )
__releases( V_24 -> V_135 )
__acquires( V_24 -> V_135 )
{
int V_162 ;
F_83 ( L_63 , V_24 ) ;
if ( V_24 == NULL ) {
F_101 ( L_64 ) ;
return;
}
F_56 ( 0xFF , L_65 , 0 ) ;
F_93 ( V_24 -> V_135 ) ;
V_162 = F_95 ( & V_24 -> V_89 ) ;
if ( V_162 )
goto V_133;
V_162 = F_41 () ;
if ( V_162 )
goto V_133;
V_24 -> V_106 = F_102 ( & V_24 -> V_222 . V_178 , V_193 ) ;
if ( V_24 -> V_106 == NULL )
V_162 = - V_187 ;
F_94 ( V_24 -> V_135 ) ;
V_133:
if ( V_162 )
F_101 ( L_66 , V_162 ) ;
}
static void F_103 ( struct V_217 * V_178 , struct V_121 * V_122 )
{
F_83 ( L_62 , V_178 , V_122 ) ;
if ( V_178 == NULL || V_122 == NULL ) {
F_101 ( L_64 ) ;
return;
}
F_104 ( V_122 -> V_78 ) ;
F_99 ( V_178 , V_122 ) ;
}
static int F_105 ( struct V_23 * V_24 ,
struct V_125 * V_224 )
__releases( V_181 -> V_135 )
__acquires( V_181 -> V_135 )
{
struct V_149 * V_181 = & V_24 -> V_222 ;
struct V_121 * V_122 = NULL ;
T_8 V_225 = V_193 ;
int V_4 , V_3 , V_162 ;
F_83 ( L_62 , V_181 , V_224 ) ;
if ( V_181 == NULL || V_224 == NULL )
return - V_64 ;
F_93 ( V_181 -> V_135 ) ;
V_122 = F_102 ( & V_181 -> V_178 , V_225 ) ;
F_94 ( V_181 -> V_135 ) ;
if ( V_122 == NULL )
return - V_187 ;
V_122 -> V_216 = F_103 ;
V_122 -> V_124 = 2 ;
V_122 -> V_78 = F_106 ( V_122 -> V_124 , V_225 ) ;
if ( V_122 -> V_78 == NULL ) {
V_162 = - V_187 ;
goto V_226;
}
if ( ( V_224 -> V_126 & V_227 ) == V_228 ) {
* ( ( T_5 * ) V_122 -> V_78 ) = V_229 -> V_219 << 1 ;
V_162 = 0 ;
} else if ( ( V_224 -> V_126 & V_227 ) \
== V_230 ) {
V_4 = ( F_59 ( V_224 -> V_129 ) & V_180 ) ?
V_179 : V_60 ;
V_3 = F_59 ( V_224 -> V_129 ) & V_231 ;
* ( ( T_5 * ) V_122 -> V_78 ) = F_23 ( V_3 , V_4 ) ;
}
F_93 ( V_181 -> V_135 ) ;
V_162 = F_107 ( & V_181 -> V_178 , V_122 , V_225 ) ;
F_94 ( V_181 -> V_135 ) ;
if ( V_162 )
goto V_232;
return 0 ;
V_232:
F_104 ( V_122 -> V_78 ) ;
V_226:
F_93 ( V_181 -> V_135 ) ;
F_99 ( & V_181 -> V_178 , V_122 ) ;
F_94 ( V_181 -> V_135 ) ;
return V_162 ;
}
static void
F_108 ( struct V_217 * V_178 , struct V_121 * V_122 )
{
struct V_23 * V_24 = V_122 -> V_233 ;
unsigned long V_32 ;
F_83 ( L_62 , V_178 , V_122 ) ;
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( V_24 -> V_234 )
F_31 ( V_24 -> V_234 ) ;
F_67 ( V_24 -> V_135 , V_32 ) ;
}
static int F_109 ( struct V_23 * V_24 )
__releases( V_181 -> V_135 )
__acquires( V_181 -> V_135 )
{
int V_162 ;
struct V_149 * V_181 ;
F_83 ( L_63 , V_24 ) ;
V_181 = ( V_24 -> V_235 == V_179 ) ? & V_24 -> V_221 : & V_24 -> V_222 ;
V_24 -> V_106 -> V_233 = V_24 ;
V_24 -> V_106 -> V_216 = F_108 ;
F_93 ( V_181 -> V_135 ) ;
V_162 = F_107 ( & V_181 -> V_178 , V_24 -> V_106 , V_193 ) ;
F_94 ( V_181 -> V_135 ) ;
return V_162 ;
}
static int F_110 ( struct V_149 * V_181 )
__releases( V_181 -> V_135 )
__acquires( V_181 -> V_135 )
{
struct V_158 * V_182 , * V_236 ;
struct V_149 * V_237 = V_181 ;
int V_238 ( V_162 ) ;
F_83 ( L_63 , V_181 ) ;
if ( F_87 ( & V_181 -> V_152 . V_161 ) )
return - V_64 ;
F_111 (mReq, mReqTemp, &mEp->qh.queue,
queue) {
V_162 = F_89 ( V_181 , V_182 ) ;
if ( V_162 < 0 )
break;
F_92 ( & V_182 -> V_161 ) ;
F_55 ( F_81 ( V_181 ) , V_182 -> V_154 -> V_117 , V_162 ) ;
if ( V_182 -> V_122 . V_216 != NULL ) {
F_93 ( V_181 -> V_135 ) ;
if ( ( V_181 -> type == V_209 ) &&
V_182 -> V_122 . V_124 )
V_237 = & V_229 -> V_222 ;
V_182 -> V_122 . V_216 ( & V_237 -> V_178 , & V_182 -> V_122 ) ;
F_94 ( V_181 -> V_135 ) ;
}
}
if ( V_162 == - V_210 )
V_162 = 0 ;
if ( V_162 < 0 )
F_56 ( F_81 ( V_181 ) , L_19 , V_162 ) ;
return V_162 ;
}
static void F_112 ( struct V_23 * V_24 )
__releases( V_24 -> V_135 )
__acquires( V_24 -> V_135 )
{
unsigned V_79 ;
T_3 V_239 = 0 ;
F_83 ( L_63 , V_24 ) ;
if ( V_24 == NULL ) {
F_101 ( L_64 ) ;
return;
}
for ( V_79 = 0 ; V_79 < V_20 ; V_79 ++ ) {
struct V_149 * V_181 = & V_24 -> V_149 [ V_79 ] ;
int type , V_3 , V_4 , F_101 = - V_64 ;
struct V_125 V_122 ;
if ( V_181 -> V_240 == NULL )
continue;
if ( F_36 ( V_79 ) ) {
F_101 = F_110 ( V_181 ) ;
if ( V_181 -> type == V_209 ) {
if ( F_101 > 0 )
F_101 = F_109 ( V_24 ) ;
if ( F_101 < 0 ) {
F_56 ( F_81 ( V_181 ) ,
L_67 , F_101 ) ;
F_93 ( V_24 -> V_135 ) ;
if ( F_113 ( & V_181 -> V_178 ) )
F_101 ( L_68 ) ;
F_94 ( V_24 -> V_135 ) ;
}
}
}
if ( V_181 -> type != V_209 ||
! F_24 ( V_79 ) )
continue;
if ( V_79 != 0 ) {
F_114 ( L_69 ) ;
continue;
}
F_91 ( & V_24 -> V_221 ) ;
F_91 ( & V_24 -> V_222 ) ;
do {
F_39 () ;
memcpy ( & V_122 , & V_181 -> V_152 . V_154 -> V_224 , sizeof( V_122 ) ) ;
} while ( ! F_38 () );
type = V_122 . V_126 ;
V_24 -> V_235 = ( type & V_241 ) ? V_179 : V_60 ;
F_58 ( F_81 ( V_181 ) , & V_122 ) ;
switch ( V_122 . V_127 ) {
case V_242 :
if ( type == ( V_243 | V_230 ) &&
F_59 ( V_122 . V_128 ) ==
V_244 ) {
if ( V_122 . V_130 != 0 )
break;
V_3 = F_59 ( V_122 . V_129 ) ;
V_4 = V_3 & V_180 ;
V_3 &= V_231 ;
if ( V_4 )
V_3 += V_20 / 2 ;
if ( ! V_24 -> V_149 [ V_3 ] . V_245 ) {
F_93 ( V_24 -> V_135 ) ;
F_101 = F_115 (
& V_24 -> V_149 [ V_3 ] . V_178 ) ;
F_94 ( V_24 -> V_135 ) ;
if ( F_101 )
break;
}
F_101 = F_109 ( V_24 ) ;
} else if ( type == ( V_243 | V_228 ) &&
F_59 ( V_122 . V_128 ) ==
V_246 ) {
if ( V_122 . V_130 != 0 )
break;
V_24 -> V_219 = 0 ;
F_101 = F_109 ( V_24 ) ;
} else {
goto V_247;
}
break;
case V_248 :
if ( type != ( V_241 | V_228 ) &&
type != ( V_241 | V_230 ) &&
type != ( V_241 | V_249 ) )
goto V_247;
if ( F_59 ( V_122 . V_130 ) != 2 ||
F_59 ( V_122 . V_128 ) != 0 )
break;
F_101 = F_105 ( V_24 , & V_122 ) ;
break;
case V_250 :
if ( type != ( V_243 | V_228 ) )
goto V_247;
if ( F_59 ( V_122 . V_130 ) != 0 ||
F_59 ( V_122 . V_129 ) != 0 )
break;
F_101 = F_40 ( ( T_3 ) F_59 ( V_122 . V_128 ) ) ;
if ( F_101 )
break;
F_101 = F_109 ( V_24 ) ;
break;
case V_251 :
if ( type == ( V_243 | V_230 ) &&
F_59 ( V_122 . V_128 ) ==
V_244 ) {
if ( V_122 . V_130 != 0 )
break;
V_3 = F_59 ( V_122 . V_129 ) ;
V_4 = V_3 & V_180 ;
V_3 &= V_231 ;
if ( V_4 )
V_3 += V_20 / 2 ;
F_93 ( V_24 -> V_135 ) ;
F_101 = F_113 ( & V_24 -> V_149 [ V_3 ] . V_178 ) ;
F_94 ( V_24 -> V_135 ) ;
if ( ! F_101 )
F_109 ( V_24 ) ;
} else if ( type == ( V_243 | V_228 ) ) {
if ( V_122 . V_130 != 0 )
break;
switch ( F_59 ( V_122 . V_128 ) ) {
case V_246 :
V_24 -> V_219 = 1 ;
F_101 = F_109 ( V_24 ) ;
break;
case V_252 :
V_239 = F_59 ( V_122 . V_129 ) >> 8 ;
switch ( V_239 ) {
case V_253 :
case V_254 :
case V_255 :
case V_256 :
case V_257 :
V_24 -> V_234 = V_239 ;
F_101 = F_109 (
V_24 ) ;
break;
default:
break;
}
default:
goto V_247;
}
} else {
goto V_247;
}
break;
default:
V_247:
if ( V_122 . V_130 == 0 )
V_24 -> V_235 = V_179 ;
F_93 ( V_24 -> V_135 ) ;
F_101 = V_24 -> V_102 -> V_224 ( & V_24 -> V_89 , & V_122 ) ;
F_94 ( V_24 -> V_135 ) ;
break;
}
if ( F_101 < 0 ) {
F_56 ( F_81 ( V_181 ) , L_67 , F_101 ) ;
F_93 ( V_24 -> V_135 ) ;
if ( F_113 ( & V_181 -> V_178 ) )
F_101 ( L_68 ) ;
F_94 ( V_24 -> V_135 ) ;
}
}
}
static int F_116 ( struct V_217 * V_178 ,
const struct V_258 * V_240 )
{
struct V_149 * V_181 = F_43 ( V_178 , struct V_149 , V_178 ) ;
int V_162 = 0 ;
unsigned long V_32 ;
F_83 ( L_62 , V_178 , V_240 ) ;
if ( V_178 == NULL || V_240 == NULL )
return - V_64 ;
F_66 ( V_181 -> V_135 , V_32 ) ;
V_181 -> V_240 = V_240 ;
if ( ! F_87 ( & V_181 -> V_152 . V_161 ) )
F_114 ( L_70 ) ;
V_181 -> V_4 = F_117 ( V_240 ) ? V_179 : V_60 ;
V_181 -> V_3 = F_118 ( V_240 ) ;
V_181 -> type = F_119 ( V_240 ) ;
V_181 -> V_178 . V_190 = F_120 ( V_240 -> V_259 ) ;
F_56 ( F_81 ( V_181 ) , L_71 , 0 ) ;
V_181 -> V_152 . V_154 -> V_9 = 0 ;
if ( V_181 -> type == V_209 )
V_181 -> V_152 . V_154 -> V_9 |= V_260 ;
else if ( V_181 -> type == V_261 )
V_181 -> V_152 . V_154 -> V_9 &= ~ V_262 ;
else
V_181 -> V_152 . V_154 -> V_9 &= ~ V_208 ;
V_181 -> V_152 . V_154 -> V_9 |=
( V_181 -> V_178 . V_190 << F_1 ( V_263 ) ) & V_263 ;
V_181 -> V_152 . V_154 -> V_207 . V_195 |= V_196 ;
if ( V_181 -> V_3 )
V_162 |= F_22 ( V_181 -> V_3 , V_181 -> V_4 , V_181 -> type ) ;
F_67 ( V_181 -> V_135 , V_32 ) ;
return V_162 ;
}
static int F_121 ( struct V_217 * V_178 )
{
struct V_149 * V_181 = F_43 ( V_178 , struct V_149 , V_178 ) ;
int V_264 , V_162 = 0 ;
unsigned long V_32 ;
F_83 ( L_63 , V_178 ) ;
if ( V_178 == NULL )
return - V_64 ;
else if ( V_181 -> V_240 == NULL )
return - V_210 ;
F_66 ( V_181 -> V_135 , V_32 ) ;
V_264 = V_181 -> V_4 ;
do {
F_56 ( F_81 ( V_181 ) , L_72 , 0 ) ;
V_162 |= F_91 ( V_181 ) ;
V_162 |= F_21 ( V_181 -> V_3 , V_181 -> V_4 ) ;
if ( V_181 -> type == V_209 )
V_181 -> V_4 = ( V_181 -> V_4 == V_179 ) ? V_60 : V_179 ;
} while ( V_181 -> V_4 != V_264 );
V_181 -> V_240 = NULL ;
F_67 ( V_181 -> V_135 , V_32 ) ;
return V_162 ;
}
static struct V_121 * F_122 ( struct V_217 * V_178 , T_8 V_225 )
{
struct V_149 * V_181 = F_43 ( V_178 , struct V_149 , V_178 ) ;
struct V_158 * V_182 = NULL ;
F_83 ( L_73 , V_178 , V_225 ) ;
if ( V_178 == NULL ) {
F_101 ( L_64 ) ;
return NULL ;
}
V_182 = F_106 ( sizeof( struct V_158 ) , V_225 ) ;
if ( V_182 != NULL ) {
F_123 ( & V_182 -> V_161 ) ;
V_182 -> V_154 = F_85 ( V_181 -> V_192 , V_225 ,
& V_182 -> V_40 ) ;
if ( V_182 -> V_154 == NULL ) {
F_104 ( V_182 ) ;
V_182 = NULL ;
}
}
F_56 ( F_81 ( V_181 ) , L_74 , V_182 == NULL ) ;
return ( V_182 == NULL ) ? NULL : & V_182 -> V_122 ;
}
static void F_124 ( struct V_217 * V_178 , struct V_121 * V_122 )
{
struct V_149 * V_181 = F_43 ( V_178 , struct V_149 , V_178 ) ;
struct V_158 * V_182 = F_43 ( V_122 , struct V_158 , V_122 ) ;
unsigned long V_32 ;
F_83 ( L_62 , V_178 , V_122 ) ;
if ( V_178 == NULL || V_122 == NULL ) {
F_101 ( L_64 ) ;
return;
} else if ( ! F_87 ( & V_182 -> V_161 ) ) {
F_101 ( L_75 ) ;
return;
}
F_66 ( V_181 -> V_135 , V_32 ) ;
if ( V_182 -> V_154 )
F_90 ( V_181 -> V_192 , V_182 -> V_154 , V_182 -> V_40 ) ;
F_104 ( V_182 ) ;
F_56 ( F_81 ( V_181 ) , L_76 , 0 ) ;
F_67 ( V_181 -> V_135 , V_32 ) ;
}
static int F_125 ( struct V_217 * V_178 , struct V_121 * V_122 ,
T_8 T_7 V_225 )
{
struct V_149 * V_181 = F_43 ( V_178 , struct V_149 , V_178 ) ;
struct V_158 * V_182 = F_43 ( V_122 , struct V_158 , V_122 ) ;
int V_162 = 0 ;
unsigned long V_32 ;
F_83 ( L_77 , V_178 , V_122 , V_225 ) ;
if ( V_178 == NULL || V_122 == NULL || V_181 -> V_240 == NULL )
return - V_64 ;
F_66 ( V_181 -> V_135 , V_32 ) ;
if ( V_181 -> type == V_209 ) {
if ( V_122 -> V_124 )
V_181 = ( V_229 -> V_235 == V_60 ) ?
& V_229 -> V_221 : & V_229 -> V_222 ;
if ( ! F_87 ( & V_181 -> V_152 . V_161 ) ) {
F_91 ( V_181 ) ;
V_162 = - V_265 ;
F_114 ( L_78 , F_81 ( V_181 ) ) ;
}
}
if ( ! F_87 ( & V_182 -> V_161 ) ) {
V_162 = - V_210 ;
F_101 ( L_79 ) ;
goto V_133;
}
if ( V_122 -> V_124 > ( 4 * V_200 ) ) {
V_122 -> V_124 = ( 4 * V_200 ) ;
V_162 = - V_266 ;
F_114 ( L_80 ) ;
}
F_57 ( F_81 ( V_181 ) , V_122 , V_162 ) ;
V_182 -> V_122 . V_106 = - V_267 ;
V_182 -> V_122 . V_214 = 0 ;
V_162 = F_82 ( V_181 , V_182 ) ;
if ( V_162 == - V_184 ) {
F_56 ( F_81 ( V_181 ) , L_21 , V_162 ) ;
V_162 = 0 ;
}
if ( ! V_162 )
F_126 ( & V_182 -> V_161 , & V_181 -> V_152 . V_161 ) ;
V_133:
F_67 ( V_181 -> V_135 , V_32 ) ;
return V_162 ;
}
static int F_127 ( struct V_217 * V_178 , struct V_121 * V_122 )
{
struct V_149 * V_181 = F_43 ( V_178 , struct V_149 , V_178 ) ;
struct V_158 * V_182 = F_43 ( V_122 , struct V_158 , V_122 ) ;
unsigned long V_32 ;
F_83 ( L_62 , V_178 , V_122 ) ;
if ( V_178 == NULL || V_122 == NULL || V_182 -> V_122 . V_106 != - V_184 ||
V_181 -> V_240 == NULL || F_87 ( & V_182 -> V_161 ) ||
F_87 ( & V_181 -> V_152 . V_161 ) )
return - V_64 ;
F_66 ( V_181 -> V_135 , V_32 ) ;
F_56 ( F_81 ( V_181 ) , L_81 , 0 ) ;
F_18 ( V_181 -> V_3 , V_181 -> V_4 ) ;
F_92 ( & V_182 -> V_161 ) ;
if ( V_182 -> V_188 ) {
F_86 ( V_181 -> V_85 , V_182 -> V_122 . V_40 , V_182 -> V_122 . V_124 ,
V_181 -> V_4 ? V_185 : V_186 ) ;
V_182 -> V_122 . V_40 = 0 ;
V_182 -> V_188 = 0 ;
}
V_122 -> V_106 = - V_268 ;
if ( V_182 -> V_122 . V_216 != NULL ) {
F_93 ( V_181 -> V_135 ) ;
V_182 -> V_122 . V_216 ( & V_181 -> V_178 , & V_182 -> V_122 ) ;
F_94 ( V_181 -> V_135 ) ;
}
F_67 ( V_181 -> V_135 , V_32 ) ;
return 0 ;
}
static int F_128 ( struct V_217 * V_178 , int V_63 )
{
struct V_149 * V_181 = F_43 ( V_178 , struct V_149 , V_178 ) ;
int V_264 , V_162 = 0 ;
unsigned long V_32 ;
F_83 ( L_73 , V_178 , V_63 ) ;
if ( V_178 == NULL || V_181 -> V_240 == NULL )
return - V_64 ;
F_66 ( V_181 -> V_135 , V_32 ) ;
#ifndef F_129
if ( V_63 && V_181 -> type == V_269 && V_181 -> V_4 == V_179 &&
! F_87 ( & V_181 -> V_152 . V_161 ) ) {
F_67 ( V_181 -> V_135 , V_32 ) ;
return - V_61 ;
}
#endif
V_264 = V_181 -> V_4 ;
do {
F_56 ( F_81 ( V_181 ) , L_82 , V_63 ) ;
V_162 |= F_26 ( V_181 -> V_3 , V_181 -> V_4 , V_63 ) ;
if ( ! V_63 )
V_181 -> V_245 = 0 ;
if ( V_181 -> type == V_209 )
V_181 -> V_4 = ( V_181 -> V_4 == V_179 ) ? V_60 : V_179 ;
} while ( V_181 -> V_4 != V_264 );
F_67 ( V_181 -> V_135 , V_32 ) ;
return V_162 ;
}
static int F_130 ( struct V_217 * V_178 )
{
struct V_149 * V_181 = F_43 ( V_178 , struct V_149 , V_178 ) ;
unsigned long V_32 ;
F_83 ( L_63 , V_178 ) ;
if ( V_178 == NULL || V_181 -> V_240 == NULL )
return - V_64 ;
F_66 ( V_181 -> V_135 , V_32 ) ;
F_56 ( F_81 ( V_181 ) , L_83 , 0 ) ;
V_181 -> V_245 = 1 ;
F_67 ( V_181 -> V_135 , V_32 ) ;
return F_113 ( V_178 ) ;
}
static void F_131 ( struct V_217 * V_178 )
{
struct V_149 * V_181 = F_43 ( V_178 , struct V_149 , V_178 ) ;
unsigned long V_32 ;
F_83 ( L_63 , V_178 ) ;
if ( V_178 == NULL ) {
F_101 ( L_84 , F_81 ( V_181 ) ) ;
return;
}
F_66 ( V_181 -> V_135 , V_32 ) ;
F_56 ( F_81 ( V_181 ) , L_85 , 0 ) ;
F_18 ( V_181 -> V_3 , V_181 -> V_4 ) ;
F_67 ( V_181 -> V_135 , V_32 ) ;
}
static int F_132 ( struct V_90 * V_270 , int V_271 )
{
struct V_23 * V_24 = F_43 ( V_270 , struct V_23 , V_89 ) ;
unsigned long V_32 ;
int V_272 = 0 ;
if ( ! ( V_24 -> V_29 -> V_32 & V_273 ) )
return - V_274 ;
F_66 ( V_24 -> V_135 , V_32 ) ;
V_24 -> V_275 = V_271 ;
if ( V_24 -> V_102 )
V_272 = 1 ;
F_67 ( V_24 -> V_135 , V_32 ) ;
if ( V_272 ) {
if ( V_271 ) {
F_133 ( & V_270 -> V_86 ) ;
F_14 ( V_24 ) ;
F_17 ( V_24 -> V_221 . V_152 . V_40 ) ;
} else {
F_17 ( 0 ) ;
if ( V_24 -> V_29 -> V_30 )
V_24 -> V_29 -> V_30 ( V_24 ,
V_276 ) ;
F_95 ( & V_24 -> V_89 ) ;
F_134 ( & V_270 -> V_86 ) ;
}
}
return 0 ;
}
static int F_135 ( struct V_90 * V_270 )
{
struct V_23 * V_24 = F_43 ( V_270 , struct V_23 , V_89 ) ;
unsigned long V_32 ;
int V_183 = 0 ;
F_83 () ;
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( ! V_24 -> V_219 ) {
V_183 = - V_274 ;
F_44 ( L_86 ) ;
goto V_277;
}
if ( ! F_8 ( V_73 , V_278 ) ) {
V_183 = - V_64 ;
F_44 ( L_87 ) ;
goto V_277;
}
F_9 ( V_73 , V_279 , V_279 ) ;
V_277:
F_67 ( V_24 -> V_135 , V_32 ) ;
return V_183 ;
}
static int F_136 ( struct V_90 * V_270 , unsigned V_280 )
{
struct V_23 * V_24 = F_43 ( V_270 , struct V_23 , V_89 ) ;
if ( V_24 -> V_281 )
return F_137 ( V_24 -> V_281 , V_280 ) ;
return - V_282 ;
}
int F_138 ( struct V_101 * V_102 ,
int (* F_139)( struct V_90 * ) )
{
struct V_23 * V_24 = V_229 ;
unsigned long V_32 ;
int V_79 , V_131 ;
int V_162 = - V_187 ;
F_83 ( L_63 , V_102 ) ;
if ( V_102 == NULL ||
F_139 == NULL ||
V_102 -> V_224 == NULL ||
V_102 -> V_223 == NULL ||
V_102 -> V_283 == NULL ||
V_102 -> V_284 == NULL )
return - V_64 ;
else if ( V_24 == NULL )
return - V_22 ;
else if ( V_24 -> V_102 != NULL )
return - V_210 ;
V_24 -> V_285 = F_140 ( L_88 , & V_24 -> V_89 . V_86 ,
sizeof( struct V_153 ) ,
64 , V_200 ) ;
if ( V_24 -> V_285 == NULL )
return - V_187 ;
V_24 -> V_192 = F_140 ( L_89 , & V_24 -> V_89 . V_86 ,
sizeof( struct V_160 ) ,
64 , V_200 ) ;
if ( V_24 -> V_192 == NULL ) {
F_141 ( V_24 -> V_285 ) ;
V_24 -> V_285 = NULL ;
return - V_187 ;
}
F_66 ( V_24 -> V_135 , V_32 ) ;
F_142 ( L_90 , V_20 ) ;
V_24 -> V_89 . V_86 . V_102 = NULL ;
V_162 = 0 ;
for ( V_79 = 0 ; V_79 < V_20 / 2 ; V_79 ++ ) {
for ( V_131 = V_60 ; V_131 <= V_179 ; V_131 ++ ) {
int V_156 = V_79 + V_131 * V_20 / 2 ;
struct V_149 * V_181 = & V_24 -> V_149 [ V_156 ] ;
F_46 ( V_181 -> V_100 , sizeof( V_181 -> V_100 ) , L_91 , V_79 ,
( V_131 == V_179 ) ? L_92 : L_93 ) ;
V_181 -> V_135 = V_24 -> V_135 ;
V_181 -> V_85 = & V_24 -> V_89 . V_86 ;
V_181 -> V_192 = V_24 -> V_192 ;
V_181 -> V_178 . V_100 = V_181 -> V_100 ;
V_181 -> V_178 . V_286 = & V_287 ;
V_181 -> V_178 . V_190 = V_288 ;
F_123 ( & V_181 -> V_152 . V_161 ) ;
F_67 ( V_24 -> V_135 , V_32 ) ;
V_181 -> V_152 . V_154 = F_85 ( V_24 -> V_285 , V_289 ,
& V_181 -> V_152 . V_40 ) ;
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( V_181 -> V_152 . V_154 == NULL )
V_162 = - V_187 ;
else
memset ( V_181 -> V_152 . V_154 , 0 , sizeof( * V_181 -> V_152 . V_154 ) ) ;
if ( V_79 == 0 )
continue;
F_126 ( & V_181 -> V_178 . V_290 , & V_24 -> V_89 . V_290 ) ;
}
}
if ( V_162 )
goto V_133;
F_67 ( V_24 -> V_135 , V_32 ) ;
V_162 = F_143 ( & V_24 -> V_221 . V_178 , & V_291 ) ;
if ( V_162 )
return V_162 ;
V_162 = F_143 ( & V_24 -> V_222 . V_178 , & V_292 ) ;
if ( V_162 )
return V_162 ;
F_66 ( V_24 -> V_135 , V_32 ) ;
V_24 -> V_89 . V_293 = & V_24 -> V_222 . V_178 ;
V_102 -> V_102 . V_294 = NULL ;
V_24 -> V_89 . V_86 . V_102 = & V_102 -> V_102 ;
F_67 ( V_24 -> V_135 , V_32 ) ;
V_162 = F_139 ( & V_24 -> V_89 ) ;
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( V_162 ) {
V_24 -> V_89 . V_86 . V_102 = NULL ;
goto V_133;
}
V_24 -> V_102 = V_102 ;
F_133 ( & V_24 -> V_89 . V_86 ) ;
if ( V_24 -> V_29 -> V_32 & V_273 ) {
if ( V_24 -> V_275 ) {
if ( V_24 -> V_29 -> V_32 & V_295 )
F_14 ( V_24 ) ;
} else {
F_134 ( & V_24 -> V_89 . V_86 ) ;
goto V_133;
}
}
V_162 = F_17 ( V_24 -> V_221 . V_152 . V_40 ) ;
if ( V_162 )
F_134 ( & V_24 -> V_89 . V_86 ) ;
V_133:
F_67 ( V_24 -> V_135 , V_32 ) ;
return V_162 ;
}
int F_144 ( struct V_101 * V_102 )
{
struct V_23 * V_24 = V_229 ;
unsigned long V_79 , V_32 ;
F_83 ( L_63 , V_102 ) ;
if ( V_102 == NULL ||
V_102 -> V_296 == NULL ||
V_102 -> V_224 == NULL ||
V_102 -> V_223 == NULL ||
V_102 -> V_283 == NULL ||
V_102 -> V_284 == NULL ||
V_102 != V_24 -> V_102 )
return - V_64 ;
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( ! ( V_24 -> V_29 -> V_32 & V_273 ) ||
V_24 -> V_275 ) {
F_17 ( 0 ) ;
if ( V_24 -> V_29 -> V_30 )
V_24 -> V_29 -> V_30 ( V_24 ,
V_276 ) ;
F_95 ( & V_24 -> V_89 ) ;
F_145 ( & V_24 -> V_89 . V_86 ) ;
}
F_67 ( V_24 -> V_135 , V_32 ) ;
V_102 -> V_296 ( & V_24 -> V_89 ) ;
F_66 ( V_24 -> V_135 , V_32 ) ;
V_24 -> V_89 . V_86 . V_102 = NULL ;
for ( V_79 = 0 ; V_79 < V_20 ; V_79 ++ ) {
struct V_149 * V_181 = & V_24 -> V_149 [ V_79 ] ;
if ( ! F_87 ( & V_181 -> V_178 . V_290 ) )
F_92 ( & V_181 -> V_178 . V_290 ) ;
if ( V_181 -> V_152 . V_154 != NULL )
F_90 ( V_24 -> V_285 , V_181 -> V_152 . V_154 , V_181 -> V_152 . V_40 ) ;
}
V_24 -> V_89 . V_293 = NULL ;
V_24 -> V_102 = NULL ;
F_67 ( V_24 -> V_135 , V_32 ) ;
if ( V_24 -> V_192 != NULL ) {
F_141 ( V_24 -> V_192 ) ;
V_24 -> V_192 = NULL ;
}
if ( V_24 -> V_285 != NULL ) {
F_141 ( V_24 -> V_285 ) ;
V_24 -> V_285 = NULL ;
}
return 0 ;
}
static T_9 F_146 ( void )
{
struct V_23 * V_24 = V_229 ;
T_9 V_162 ;
T_1 V_134 ;
F_83 () ;
if ( V_24 == NULL ) {
F_101 ( L_94 ) ;
return V_297 ;
}
F_94 ( V_24 -> V_135 ) ;
if ( V_24 -> V_29 -> V_32 & V_295 ) {
if ( F_8 ( V_34 , V_36 ) !=
V_38 ) {
F_93 ( V_24 -> V_135 ) ;
return V_298 ;
}
}
V_134 = F_37 () ;
if ( V_134 ) {
V_136 . V_144 . V_78 [ V_136 . V_144 . V_104 ++ ] = V_134 ;
V_136 . V_144 . V_104 &= V_146 ;
V_136 . V_144 . V_145 ++ ;
if ( V_46 & V_134 ) {
V_136 . V_141 ++ ;
F_100 ( V_24 ) ;
}
if ( V_45 & V_134 ) {
V_136 . V_140 ++ ;
V_24 -> V_89 . V_93 = F_29 () ?
V_299 : V_300 ;
if ( V_24 -> V_220 ) {
F_93 ( V_24 -> V_135 ) ;
V_24 -> V_102 -> V_284 ( & V_24 -> V_89 ) ;
F_94 ( V_24 -> V_135 ) ;
V_24 -> V_220 = 0 ;
}
}
if ( V_44 & V_134 )
V_136 . V_139 ++ ;
if ( V_43 & V_134 ) {
V_136 . V_138 ++ ;
F_112 ( V_24 ) ;
}
if ( V_47 & V_134 ) {
if ( V_24 -> V_89 . V_93 != V_218 ) {
V_24 -> V_220 = 1 ;
F_93 ( V_24 -> V_135 ) ;
V_24 -> V_102 -> V_283 ( & V_24 -> V_89 ) ;
F_94 ( V_24 -> V_135 ) ;
}
V_136 . V_142 ++ ;
}
V_162 = V_297 ;
} else {
V_136 . V_143 ++ ;
V_162 = V_298 ;
}
F_93 ( V_24 -> V_135 ) ;
return V_162 ;
}
static void F_147 ( struct V_85 * V_86 )
{
F_83 ( L_63 , V_86 ) ;
if ( V_86 == NULL )
F_101 ( L_64 ) ;
}
static int F_148 ( struct V_301 * V_102 , struct V_85 * V_86 ,
void T_2 * V_302 )
{
struct V_23 * V_24 ;
int V_162 = 0 ;
F_83 ( L_95 , V_86 , V_302 , V_100 ) ;
if ( V_86 == NULL || V_302 == NULL || V_102 == NULL ||
V_102 -> V_100 == NULL )
return - V_64 ;
V_24 = F_106 ( sizeof( struct V_23 ) , V_289 ) ;
if ( V_24 == NULL )
return - V_187 ;
V_24 -> V_135 = & V_303 ;
V_24 -> V_302 = V_302 ;
V_24 -> V_29 = V_102 ;
V_24 -> V_89 . V_286 = & V_304 ;
V_24 -> V_89 . V_93 = V_218 ;
V_24 -> V_89 . V_94 = 1 ;
V_24 -> V_89 . V_95 = 0 ;
V_24 -> V_89 . V_100 = V_102 -> V_100 ;
F_123 ( & V_24 -> V_89 . V_290 ) ;
V_24 -> V_89 . V_293 = NULL ;
F_149 ( & V_24 -> V_89 . V_86 , L_96 ) ;
V_24 -> V_89 . V_86 . V_305 = V_86 -> V_305 ;
V_24 -> V_89 . V_86 . V_306 = V_86 -> V_306 ;
V_24 -> V_89 . V_86 . V_307 = V_86 ;
V_24 -> V_89 . V_86 . V_308 = F_147 ;
V_162 = F_12 ( V_302 ) ;
if ( V_162 < 0 )
goto V_309;
V_24 -> V_281 = F_150 () ;
if ( V_24 -> V_29 -> V_32 & V_310 ) {
if ( V_24 -> V_281 == NULL ) {
V_162 = - V_22 ;
goto V_309;
}
}
if ( ! ( V_24 -> V_29 -> V_32 & V_295 ) ) {
V_162 = F_14 ( V_24 ) ;
if ( V_162 )
goto V_311;
}
V_162 = F_151 ( & V_24 -> V_89 . V_86 ) ;
if ( V_162 ) {
F_152 ( & V_24 -> V_89 . V_86 ) ;
goto V_311;
}
#ifdef F_153
V_162 = F_77 ( & V_24 -> V_89 . V_86 ) ;
#endif
if ( V_162 )
goto V_312;
if ( V_24 -> V_281 ) {
V_162 = F_154 ( V_24 -> V_281 , & V_24 -> V_89 ) ;
if ( V_162 )
goto V_313;
}
F_155 ( & V_24 -> V_89 . V_86 ) ;
F_156 ( & V_24 -> V_89 . V_86 ) ;
V_229 = V_24 ;
return V_162 ;
F_101 ( L_97 , V_162 ) ;
V_313:
#ifdef F_153
F_80 ( & V_24 -> V_89 . V_86 ) ;
#endif
V_312:
F_157 ( & V_24 -> V_89 . V_86 ) ;
V_311:
if ( V_24 -> V_281 )
F_158 ( V_24 -> V_281 ) ;
V_309:
F_104 ( V_24 ) ;
V_229 = NULL ;
return V_162 ;
}
static void F_159 ( void )
{
struct V_23 * V_24 = V_229 ;
if ( V_24 == NULL ) {
F_101 ( L_64 ) ;
return;
}
if ( V_24 -> V_281 ) {
F_154 ( V_24 -> V_281 , & V_24 -> V_89 ) ;
F_158 ( V_24 -> V_281 ) ;
}
#ifdef F_153
F_80 ( & V_24 -> V_89 . V_86 ) ;
#endif
F_157 ( & V_24 -> V_89 . V_86 ) ;
F_104 ( V_24 ) ;
V_229 = NULL ;
}
