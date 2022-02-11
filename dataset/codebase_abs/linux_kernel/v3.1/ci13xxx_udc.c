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
T_1 * V_155 ;
unsigned V_79 , V_156 , V_2 = 0 ;
F_44 ( L_3 , V_91 , V_78 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
return 0 ;
}
V_155 = F_73 ( sizeof( T_1 ) * V_157 , V_158 ) ;
if ( ! V_155 ) {
F_45 ( V_86 , L_54 , V_91 ) ;
return 0 ;
}
F_66 ( V_24 -> V_135 , V_32 ) ;
V_156 = F_34 ( V_155 , V_157 ) ;
F_67 ( V_24 -> V_135 , V_32 ) ;
for ( V_79 = 0 ; V_79 < V_156 ; V_79 ++ ) {
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 ,
L_55 ,
V_79 * ( unsigned ) sizeof( T_1 ) , V_155 [ V_79 ] ) ;
}
F_74 ( V_155 ) ;
return V_2 ;
}
static T_6 F_75 ( struct V_85 * V_86 ,
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
if ( sscanf ( V_78 , L_56 , & V_5 , & V_8 ) != 2 ) {
F_45 ( V_86 , L_57 ) ;
goto V_133;
}
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( F_35 ( V_5 , V_8 ) )
F_45 ( V_86 , L_58 ) ;
F_67 ( V_24 -> V_135 , V_32 ) ;
V_133:
return V_132 ;
}
static T_6 F_76 ( struct V_85 * V_86 , struct V_87 * V_88 ,
char * V_78 )
{
struct V_23 * V_24 = F_43 ( V_86 , struct V_23 , V_89 . V_86 ) ;
unsigned long V_32 ;
struct V_159 * V_154 = NULL ;
struct V_160 * V_122 = NULL ;
unsigned V_79 , V_131 , V_2 = 0 , V_161 = sizeof( struct V_162 ) / sizeof( T_1 ) ;
F_44 ( L_3 , V_91 , V_78 ) ;
if ( V_88 == NULL || V_78 == NULL ) {
F_45 ( V_86 , L_4 , V_91 ) ;
return 0 ;
}
F_66 ( V_24 -> V_135 , V_32 ) ;
for ( V_79 = 0 ; V_79 < V_20 ; V_79 ++ )
F_77 (ptr, &udc->ci13xxx_ep[i].qh.queue)
{
V_122 = F_78 ( V_154 , struct V_160 , V_163 ) ;
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 ,
L_59 ,
V_79 % V_20 / 2 , ( T_1 ) V_122 -> V_40 ,
( ( V_79 < V_20 / 2 ) ? L_60 : L_61 ) ) ;
for ( V_131 = 0 ; V_131 < V_161 ; V_131 ++ )
V_2 += F_46 ( V_78 + V_2 , V_92 - V_2 ,
L_62 , V_131 ,
* ( ( T_1 * ) V_122 -> V_154 + V_131 ) ) ;
}
F_67 ( V_24 -> V_135 , V_32 ) ;
return V_2 ;
}
T_7 static int F_79 ( struct V_85 * V_86 )
{
int V_164 = 0 ;
if ( V_86 == NULL )
return - V_64 ;
V_164 = F_80 ( V_86 , & V_165 ) ;
if ( V_164 )
goto V_133;
V_164 = F_80 ( V_86 , & V_166 ) ;
if ( V_164 )
goto V_167;
V_164 = F_80 ( V_86 , & V_168 ) ;
if ( V_164 )
goto V_169;
V_164 = F_80 ( V_86 , & V_170 ) ;
if ( V_164 )
goto V_171;
V_164 = F_80 ( V_86 , & V_172 ) ;
if ( V_164 )
goto V_173;
V_164 = F_80 ( V_86 , & V_174 ) ;
if ( V_164 )
goto V_175;
V_164 = F_80 ( V_86 , & V_176 ) ;
if ( V_164 )
goto V_177;
V_164 = F_80 ( V_86 , & V_178 ) ;
if ( V_164 )
goto V_179;
return 0 ;
V_179:
F_81 ( V_86 , & V_176 ) ;
V_177:
F_81 ( V_86 , & V_174 ) ;
V_175:
F_81 ( V_86 , & V_172 ) ;
V_173:
F_81 ( V_86 , & V_170 ) ;
V_171:
F_81 ( V_86 , & V_168 ) ;
V_169:
F_81 ( V_86 , & V_166 ) ;
V_167:
F_81 ( V_86 , & V_165 ) ;
V_133:
return V_164 ;
}
T_7 static int F_82 ( struct V_85 * V_86 )
{
if ( V_86 == NULL )
return - V_64 ;
F_81 ( V_86 , & V_178 ) ;
F_81 ( V_86 , & V_176 ) ;
F_81 ( V_86 , & V_174 ) ;
F_81 ( V_86 , & V_172 ) ;
F_81 ( V_86 , & V_170 ) ;
F_81 ( V_86 , & V_168 ) ;
F_81 ( V_86 , & V_166 ) ;
F_81 ( V_86 , & V_165 ) ;
return 0 ;
}
static inline T_3 F_83 ( struct V_149 * V_180 )
{
return ( ( V_180 -> V_4 == V_181 ) ? V_182 : 0 ) | V_180 -> V_3 ;
}
static int F_84 ( struct V_149 * V_183 , struct V_160 * V_184 )
{
unsigned V_79 ;
int V_185 = 0 ;
unsigned V_124 = V_184 -> V_122 . V_124 ;
F_85 ( L_63 , V_183 , V_184 ) ;
if ( V_184 -> V_122 . V_106 == - V_186 )
return - V_186 ;
V_184 -> V_122 . V_106 = - V_186 ;
if ( V_124 && ! V_184 -> V_122 . V_40 ) {
V_184 -> V_122 . V_40 = \
F_86 ( V_183 -> V_85 , V_184 -> V_122 . V_78 ,
V_124 , V_183 -> V_4 ? V_187 :
V_188 ) ;
if ( V_184 -> V_122 . V_40 == 0 )
return - V_189 ;
V_184 -> V_190 = 1 ;
}
if ( V_184 -> V_122 . V_191 && V_124 && ( V_124 % V_183 -> V_180 . V_192 == 0 ) ) {
V_184 -> V_193 = F_87 ( V_183 -> V_194 , V_195 ,
& V_184 -> V_196 ) ;
if ( V_184 -> V_193 == NULL ) {
if ( V_184 -> V_190 ) {
F_88 ( V_183 -> V_85 , V_184 -> V_122 . V_40 ,
V_124 , V_183 -> V_4 ? V_187 :
V_188 ) ;
V_184 -> V_122 . V_40 = 0 ;
V_184 -> V_190 = 0 ;
}
return - V_189 ;
}
memset ( V_184 -> V_193 , 0 , sizeof( * V_184 -> V_193 ) ) ;
V_184 -> V_193 -> V_197 = V_198 ;
V_184 -> V_193 -> V_117 = V_199 ;
if ( ! V_184 -> V_122 . V_123 )
V_184 -> V_193 -> V_117 |= V_200 ;
}
memset ( V_184 -> V_154 , 0 , sizeof( * V_184 -> V_154 ) ) ;
V_184 -> V_154 -> V_117 = V_124 << F_1 ( V_119 ) ;
V_184 -> V_154 -> V_117 &= V_119 ;
V_184 -> V_154 -> V_117 |= V_199 ;
if ( V_184 -> V_193 ) {
V_184 -> V_154 -> V_197 = V_184 -> V_196 ;
} else {
V_184 -> V_154 -> V_197 = V_198 ;
if ( ! V_184 -> V_122 . V_123 )
V_184 -> V_154 -> V_117 |= V_200 ;
}
V_184 -> V_154 -> V_201 [ 0 ] = V_184 -> V_122 . V_40 ;
for ( V_79 = 1 ; V_79 < 5 ; V_79 ++ )
V_184 -> V_154 -> V_201 [ V_79 ] =
( V_184 -> V_122 . V_40 + V_79 * V_202 ) & ~ V_203 ;
if ( ! F_89 ( & V_183 -> V_152 . V_163 ) ) {
struct V_160 * V_204 ;
int V_2 = F_3 ( V_183 -> V_3 , V_183 -> V_4 ) ;
int V_205 ;
V_204 = F_78 ( V_183 -> V_152 . V_163 . V_206 ,
struct V_160 , V_163 ) ;
if ( V_204 -> V_193 )
V_204 -> V_193 -> V_197 = V_184 -> V_40 & V_207 ;
else
V_204 -> V_154 -> V_197 = V_184 -> V_40 & V_207 ;
F_90 () ;
if ( F_8 ( V_62 , F_19 ( V_2 ) ) )
goto V_133;
do {
F_9 ( V_26 , V_208 , V_208 ) ;
V_205 = F_8 ( V_48 , F_19 ( V_2 ) ) ;
} while ( ! F_8 ( V_26 , V_208 ) );
F_9 ( V_26 , V_208 , 0 ) ;
if ( V_205 )
goto V_133;
}
V_183 -> V_152 . V_154 -> V_209 . V_197 = V_184 -> V_40 ;
V_183 -> V_152 . V_154 -> V_209 . V_117 &= ~ V_120 ;
V_183 -> V_152 . V_154 -> V_9 |= V_210 ;
F_90 () ;
V_185 = F_25 ( V_183 -> V_3 , V_183 -> V_4 ,
V_183 -> type == V_211 ) ;
V_133:
return V_185 ;
}
static int F_91 ( struct V_149 * V_183 , struct V_160 * V_184 )
{
F_85 ( L_63 , V_183 , V_184 ) ;
if ( V_184 -> V_122 . V_106 != - V_186 )
return - V_64 ;
if ( ( V_199 & V_184 -> V_154 -> V_117 ) != 0 )
return - V_212 ;
if ( V_184 -> V_193 ) {
if ( ( V_199 & V_184 -> V_193 -> V_117 ) != 0 )
return - V_212 ;
F_92 ( V_183 -> V_194 , V_184 -> V_193 , V_184 -> V_196 ) ;
V_184 -> V_193 = NULL ;
}
V_184 -> V_122 . V_106 = 0 ;
if ( V_184 -> V_190 ) {
F_88 ( V_183 -> V_85 , V_184 -> V_122 . V_40 , V_184 -> V_122 . V_124 ,
V_183 -> V_4 ? V_187 : V_188 ) ;
V_184 -> V_122 . V_40 = 0 ;
V_184 -> V_190 = 0 ;
}
V_184 -> V_122 . V_106 = V_184 -> V_154 -> V_117 & V_120 ;
if ( ( V_213 & V_184 -> V_122 . V_106 ) != 0 )
V_184 -> V_122 . V_106 = - 1 ;
else if ( ( V_214 & V_184 -> V_122 . V_106 ) != 0 )
V_184 -> V_122 . V_106 = - 1 ;
else if ( ( V_215 & V_184 -> V_122 . V_106 ) != 0 )
V_184 -> V_122 . V_106 = - 1 ;
V_184 -> V_122 . V_216 = V_184 -> V_154 -> V_117 & V_119 ;
V_184 -> V_122 . V_216 >>= F_1 ( V_119 ) ;
V_184 -> V_122 . V_216 = V_184 -> V_122 . V_124 - V_184 -> V_122 . V_216 ;
V_184 -> V_122 . V_216 = V_184 -> V_122 . V_106 ? 0 : V_184 -> V_122 . V_216 ;
return V_184 -> V_122 . V_216 ;
}
static int F_93 ( struct V_149 * V_183 )
__releases( V_183 -> V_135 )
__acquires( V_183 -> V_135 )
{
F_85 ( L_64 , V_183 ) ;
if ( V_183 == NULL )
return - V_64 ;
F_18 ( V_183 -> V_3 , V_183 -> V_4 ) ;
while ( ! F_89 ( & V_183 -> V_152 . V_163 ) ) {
struct V_160 * V_184 = \
F_78 ( V_183 -> V_152 . V_163 . V_197 ,
struct V_160 , V_163 ) ;
F_94 ( & V_184 -> V_163 ) ;
V_184 -> V_122 . V_106 = - V_217 ;
if ( V_184 -> V_122 . V_218 != NULL ) {
F_95 ( V_183 -> V_135 ) ;
V_184 -> V_122 . V_218 ( & V_183 -> V_180 , & V_184 -> V_122 ) ;
F_96 ( V_183 -> V_135 ) ;
}
}
return 0 ;
}
static int F_97 ( struct V_90 * V_89 )
{
struct V_219 * V_180 ;
struct V_23 * V_24 = F_43 ( V_89 , struct V_23 , V_89 ) ;
unsigned long V_32 ;
F_85 ( L_64 , V_89 ) ;
if ( V_89 == NULL )
return - V_64 ;
F_66 ( V_24 -> V_135 , V_32 ) ;
V_24 -> V_89 . V_93 = V_220 ;
V_24 -> V_221 = 0 ;
V_24 -> V_222 = 0 ;
F_67 ( V_24 -> V_135 , V_32 ) ;
F_98 (ep, gadget) {
F_99 ( V_180 ) ;
}
F_99 ( & V_24 -> V_223 . V_180 ) ;
F_99 ( & V_24 -> V_224 . V_180 ) ;
V_24 -> V_102 -> V_225 ( V_89 ) ;
F_98 (ep, gadget) {
F_100 ( V_180 ) ;
}
if ( V_24 -> V_106 != NULL ) {
F_101 ( & V_24 -> V_224 . V_180 , V_24 -> V_106 ) ;
V_24 -> V_106 = NULL ;
}
return 0 ;
}
static void F_102 ( struct V_23 * V_24 )
__releases( V_24 -> V_135 )
__acquires( V_24 -> V_135 )
{
int V_164 ;
F_85 ( L_64 , V_24 ) ;
if ( V_24 == NULL ) {
F_103 ( L_65 ) ;
return;
}
F_56 ( 0xFF , L_66 , 0 ) ;
F_95 ( V_24 -> V_135 ) ;
V_164 = F_97 ( & V_24 -> V_89 ) ;
if ( V_164 )
goto V_133;
V_164 = F_41 () ;
if ( V_164 )
goto V_133;
V_24 -> V_106 = F_104 ( & V_24 -> V_224 . V_180 , V_195 ) ;
if ( V_24 -> V_106 == NULL )
V_164 = - V_189 ;
F_96 ( V_24 -> V_135 ) ;
V_133:
if ( V_164 )
F_103 ( L_67 , V_164 ) ;
}
static void F_105 ( struct V_219 * V_180 , struct V_121 * V_122 )
{
F_85 ( L_63 , V_180 , V_122 ) ;
if ( V_180 == NULL || V_122 == NULL ) {
F_103 ( L_65 ) ;
return;
}
F_74 ( V_122 -> V_78 ) ;
F_101 ( V_180 , V_122 ) ;
}
static int F_106 ( struct V_23 * V_24 ,
struct V_125 * V_226 )
__releases( V_183 -> V_135 )
__acquires( V_183 -> V_135 )
{
struct V_149 * V_183 = & V_24 -> V_224 ;
struct V_121 * V_122 = NULL ;
T_8 V_227 = V_195 ;
int V_4 , V_3 , V_164 ;
F_85 ( L_63 , V_183 , V_226 ) ;
if ( V_183 == NULL || V_226 == NULL )
return - V_64 ;
F_95 ( V_183 -> V_135 ) ;
V_122 = F_104 ( & V_183 -> V_180 , V_227 ) ;
F_96 ( V_183 -> V_135 ) ;
if ( V_122 == NULL )
return - V_189 ;
V_122 -> V_218 = F_105 ;
V_122 -> V_124 = 2 ;
V_122 -> V_78 = F_107 ( V_122 -> V_124 , V_227 ) ;
if ( V_122 -> V_78 == NULL ) {
V_164 = - V_189 ;
goto V_228;
}
if ( ( V_226 -> V_126 & V_229 ) == V_230 ) {
* ( ( T_5 * ) V_122 -> V_78 ) = V_231 -> V_221 << 1 ;
V_164 = 0 ;
} else if ( ( V_226 -> V_126 & V_229 ) \
== V_232 ) {
V_4 = ( F_59 ( V_226 -> V_129 ) & V_182 ) ?
V_181 : V_60 ;
V_3 = F_59 ( V_226 -> V_129 ) & V_233 ;
* ( ( T_5 * ) V_122 -> V_78 ) = F_23 ( V_3 , V_4 ) ;
}
F_95 ( V_183 -> V_135 ) ;
V_164 = F_108 ( & V_183 -> V_180 , V_122 , V_227 ) ;
F_96 ( V_183 -> V_135 ) ;
if ( V_164 )
goto V_234;
return 0 ;
V_234:
F_74 ( V_122 -> V_78 ) ;
V_228:
F_95 ( V_183 -> V_135 ) ;
F_101 ( & V_183 -> V_180 , V_122 ) ;
F_96 ( V_183 -> V_135 ) ;
return V_164 ;
}
static void
F_109 ( struct V_219 * V_180 , struct V_121 * V_122 )
{
struct V_23 * V_24 = V_122 -> V_235 ;
unsigned long V_32 ;
F_85 ( L_63 , V_180 , V_122 ) ;
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( V_24 -> V_236 )
F_31 ( V_24 -> V_236 ) ;
F_67 ( V_24 -> V_135 , V_32 ) ;
}
static int F_110 ( struct V_23 * V_24 )
__releases( V_183 -> V_135 )
__acquires( V_183 -> V_135 )
{
int V_164 ;
struct V_149 * V_183 ;
F_85 ( L_64 , V_24 ) ;
V_183 = ( V_24 -> V_237 == V_181 ) ? & V_24 -> V_223 : & V_24 -> V_224 ;
V_24 -> V_106 -> V_235 = V_24 ;
V_24 -> V_106 -> V_218 = F_109 ;
F_95 ( V_183 -> V_135 ) ;
V_164 = F_108 ( & V_183 -> V_180 , V_24 -> V_106 , V_195 ) ;
F_96 ( V_183 -> V_135 ) ;
return V_164 ;
}
static int F_111 ( struct V_149 * V_183 )
__releases( V_183 -> V_135 )
__acquires( V_183 -> V_135 )
{
struct V_160 * V_184 , * V_238 ;
struct V_149 * V_239 = V_183 ;
int V_240 ( V_164 ) ;
F_85 ( L_64 , V_183 ) ;
if ( F_89 ( & V_183 -> V_152 . V_163 ) )
return - V_64 ;
F_112 (mReq, mReqTemp, &mEp->qh.queue,
queue) {
V_164 = F_91 ( V_183 , V_184 ) ;
if ( V_164 < 0 )
break;
F_94 ( & V_184 -> V_163 ) ;
F_55 ( F_83 ( V_183 ) , V_184 -> V_154 -> V_117 , V_164 ) ;
if ( V_184 -> V_122 . V_218 != NULL ) {
F_95 ( V_183 -> V_135 ) ;
if ( ( V_183 -> type == V_211 ) &&
V_184 -> V_122 . V_124 )
V_239 = & V_231 -> V_224 ;
V_184 -> V_122 . V_218 ( & V_239 -> V_180 , & V_184 -> V_122 ) ;
F_96 ( V_183 -> V_135 ) ;
}
}
if ( V_164 == - V_212 )
V_164 = 0 ;
if ( V_164 < 0 )
F_56 ( F_83 ( V_183 ) , L_19 , V_164 ) ;
return V_164 ;
}
static void F_113 ( struct V_23 * V_24 )
__releases( V_24 -> V_135 )
__acquires( V_24 -> V_135 )
{
unsigned V_79 ;
T_3 V_241 = 0 ;
F_85 ( L_64 , V_24 ) ;
if ( V_24 == NULL ) {
F_103 ( L_65 ) ;
return;
}
for ( V_79 = 0 ; V_79 < V_20 ; V_79 ++ ) {
struct V_149 * V_183 = & V_24 -> V_149 [ V_79 ] ;
int type , V_3 , V_4 , F_103 = - V_64 ;
struct V_125 V_122 ;
if ( V_183 -> V_242 == NULL )
continue;
if ( F_36 ( V_79 ) ) {
F_103 = F_111 ( V_183 ) ;
if ( V_183 -> type == V_211 ) {
if ( F_103 > 0 )
F_103 = F_110 ( V_24 ) ;
if ( F_103 < 0 ) {
F_56 ( F_83 ( V_183 ) ,
L_68 , F_103 ) ;
F_95 ( V_24 -> V_135 ) ;
if ( F_114 ( & V_183 -> V_180 ) )
F_103 ( L_69 ) ;
F_96 ( V_24 -> V_135 ) ;
}
}
}
if ( V_183 -> type != V_211 ||
! F_24 ( V_79 ) )
continue;
if ( V_79 != 0 ) {
F_115 ( L_70 ) ;
continue;
}
F_93 ( & V_24 -> V_223 ) ;
F_93 ( & V_24 -> V_224 ) ;
do {
F_39 () ;
memcpy ( & V_122 , & V_183 -> V_152 . V_154 -> V_226 , sizeof( V_122 ) ) ;
} while ( ! F_38 () );
type = V_122 . V_126 ;
V_24 -> V_237 = ( type & V_243 ) ? V_181 : V_60 ;
F_58 ( F_83 ( V_183 ) , & V_122 ) ;
switch ( V_122 . V_127 ) {
case V_244 :
if ( type == ( V_245 | V_232 ) &&
F_59 ( V_122 . V_128 ) ==
V_246 ) {
if ( V_122 . V_130 != 0 )
break;
V_3 = F_59 ( V_122 . V_129 ) ;
V_4 = V_3 & V_182 ;
V_3 &= V_233 ;
if ( V_4 )
V_3 += V_20 / 2 ;
if ( ! V_24 -> V_149 [ V_3 ] . V_247 ) {
F_95 ( V_24 -> V_135 ) ;
F_103 = F_116 (
& V_24 -> V_149 [ V_3 ] . V_180 ) ;
F_96 ( V_24 -> V_135 ) ;
if ( F_103 )
break;
}
F_103 = F_110 ( V_24 ) ;
} else if ( type == ( V_245 | V_230 ) &&
F_59 ( V_122 . V_128 ) ==
V_248 ) {
if ( V_122 . V_130 != 0 )
break;
V_24 -> V_221 = 0 ;
F_103 = F_110 ( V_24 ) ;
} else {
goto V_249;
}
break;
case V_250 :
if ( type != ( V_243 | V_230 ) &&
type != ( V_243 | V_232 ) &&
type != ( V_243 | V_251 ) )
goto V_249;
if ( F_59 ( V_122 . V_130 ) != 2 ||
F_59 ( V_122 . V_128 ) != 0 )
break;
F_103 = F_106 ( V_24 , & V_122 ) ;
break;
case V_252 :
if ( type != ( V_245 | V_230 ) )
goto V_249;
if ( F_59 ( V_122 . V_130 ) != 0 ||
F_59 ( V_122 . V_129 ) != 0 )
break;
F_103 = F_40 ( ( T_3 ) F_59 ( V_122 . V_128 ) ) ;
if ( F_103 )
break;
F_103 = F_110 ( V_24 ) ;
break;
case V_253 :
if ( type == ( V_245 | V_232 ) &&
F_59 ( V_122 . V_128 ) ==
V_246 ) {
if ( V_122 . V_130 != 0 )
break;
V_3 = F_59 ( V_122 . V_129 ) ;
V_4 = V_3 & V_182 ;
V_3 &= V_233 ;
if ( V_4 )
V_3 += V_20 / 2 ;
F_95 ( V_24 -> V_135 ) ;
F_103 = F_114 ( & V_24 -> V_149 [ V_3 ] . V_180 ) ;
F_96 ( V_24 -> V_135 ) ;
if ( ! F_103 )
F_110 ( V_24 ) ;
} else if ( type == ( V_245 | V_230 ) ) {
if ( V_122 . V_130 != 0 )
break;
switch ( F_59 ( V_122 . V_128 ) ) {
case V_248 :
V_24 -> V_221 = 1 ;
F_103 = F_110 ( V_24 ) ;
break;
case V_254 :
V_241 = F_59 ( V_122 . V_129 ) >> 8 ;
switch ( V_241 ) {
case V_255 :
case V_256 :
case V_257 :
case V_258 :
case V_259 :
V_24 -> V_236 = V_241 ;
F_103 = F_110 (
V_24 ) ;
break;
default:
break;
}
default:
goto V_249;
}
} else {
goto V_249;
}
break;
default:
V_249:
if ( V_122 . V_130 == 0 )
V_24 -> V_237 = V_181 ;
F_95 ( V_24 -> V_135 ) ;
F_103 = V_24 -> V_102 -> V_226 ( & V_24 -> V_89 , & V_122 ) ;
F_96 ( V_24 -> V_135 ) ;
break;
}
if ( F_103 < 0 ) {
F_56 ( F_83 ( V_183 ) , L_68 , F_103 ) ;
F_95 ( V_24 -> V_135 ) ;
if ( F_114 ( & V_183 -> V_180 ) )
F_103 ( L_69 ) ;
F_96 ( V_24 -> V_135 ) ;
}
}
}
static int F_117 ( struct V_219 * V_180 ,
const struct V_260 * V_242 )
{
struct V_149 * V_183 = F_43 ( V_180 , struct V_149 , V_180 ) ;
int V_164 = 0 ;
unsigned long V_32 ;
F_85 ( L_63 , V_180 , V_242 ) ;
if ( V_180 == NULL || V_242 == NULL )
return - V_64 ;
F_66 ( V_183 -> V_135 , V_32 ) ;
V_183 -> V_242 = V_242 ;
if ( ! F_89 ( & V_183 -> V_152 . V_163 ) )
F_115 ( L_71 ) ;
V_183 -> V_4 = F_118 ( V_242 ) ? V_181 : V_60 ;
V_183 -> V_3 = F_119 ( V_242 ) ;
V_183 -> type = F_120 ( V_242 ) ;
V_183 -> V_180 . V_192 = F_121 ( V_242 -> V_261 ) ;
F_56 ( F_83 ( V_183 ) , L_72 , 0 ) ;
V_183 -> V_152 . V_154 -> V_9 = 0 ;
if ( V_183 -> type == V_211 )
V_183 -> V_152 . V_154 -> V_9 |= V_262 ;
else if ( V_183 -> type == V_263 )
V_183 -> V_152 . V_154 -> V_9 &= ~ V_264 ;
else
V_183 -> V_152 . V_154 -> V_9 &= ~ V_210 ;
V_183 -> V_152 . V_154 -> V_9 |=
( V_183 -> V_180 . V_192 << F_1 ( V_265 ) ) & V_265 ;
V_183 -> V_152 . V_154 -> V_209 . V_197 |= V_198 ;
if ( V_183 -> V_3 )
V_164 |= F_22 ( V_183 -> V_3 , V_183 -> V_4 , V_183 -> type ) ;
F_67 ( V_183 -> V_135 , V_32 ) ;
return V_164 ;
}
static int F_122 ( struct V_219 * V_180 )
{
struct V_149 * V_183 = F_43 ( V_180 , struct V_149 , V_180 ) ;
int V_266 , V_164 = 0 ;
unsigned long V_32 ;
F_85 ( L_64 , V_180 ) ;
if ( V_180 == NULL )
return - V_64 ;
else if ( V_183 -> V_242 == NULL )
return - V_212 ;
F_66 ( V_183 -> V_135 , V_32 ) ;
V_266 = V_183 -> V_4 ;
do {
F_56 ( F_83 ( V_183 ) , L_73 , 0 ) ;
V_164 |= F_93 ( V_183 ) ;
V_164 |= F_21 ( V_183 -> V_3 , V_183 -> V_4 ) ;
if ( V_183 -> type == V_211 )
V_183 -> V_4 = ( V_183 -> V_4 == V_181 ) ? V_60 : V_181 ;
} while ( V_183 -> V_4 != V_266 );
V_183 -> V_242 = NULL ;
F_67 ( V_183 -> V_135 , V_32 ) ;
return V_164 ;
}
static struct V_121 * F_123 ( struct V_219 * V_180 , T_8 V_227 )
{
struct V_149 * V_183 = F_43 ( V_180 , struct V_149 , V_180 ) ;
struct V_160 * V_184 = NULL ;
F_85 ( L_74 , V_180 , V_227 ) ;
if ( V_180 == NULL ) {
F_103 ( L_65 ) ;
return NULL ;
}
V_184 = F_107 ( sizeof( struct V_160 ) , V_227 ) ;
if ( V_184 != NULL ) {
F_124 ( & V_184 -> V_163 ) ;
V_184 -> V_154 = F_87 ( V_183 -> V_194 , V_227 ,
& V_184 -> V_40 ) ;
if ( V_184 -> V_154 == NULL ) {
F_74 ( V_184 ) ;
V_184 = NULL ;
}
}
F_56 ( F_83 ( V_183 ) , L_75 , V_184 == NULL ) ;
return ( V_184 == NULL ) ? NULL : & V_184 -> V_122 ;
}
static void F_125 ( struct V_219 * V_180 , struct V_121 * V_122 )
{
struct V_149 * V_183 = F_43 ( V_180 , struct V_149 , V_180 ) ;
struct V_160 * V_184 = F_43 ( V_122 , struct V_160 , V_122 ) ;
unsigned long V_32 ;
F_85 ( L_63 , V_180 , V_122 ) ;
if ( V_180 == NULL || V_122 == NULL ) {
F_103 ( L_65 ) ;
return;
} else if ( ! F_89 ( & V_184 -> V_163 ) ) {
F_103 ( L_76 ) ;
return;
}
F_66 ( V_183 -> V_135 , V_32 ) ;
if ( V_184 -> V_154 )
F_92 ( V_183 -> V_194 , V_184 -> V_154 , V_184 -> V_40 ) ;
F_74 ( V_184 ) ;
F_56 ( F_83 ( V_183 ) , L_77 , 0 ) ;
F_67 ( V_183 -> V_135 , V_32 ) ;
}
static int F_126 ( struct V_219 * V_180 , struct V_121 * V_122 ,
T_8 T_7 V_227 )
{
struct V_149 * V_183 = F_43 ( V_180 , struct V_149 , V_180 ) ;
struct V_160 * V_184 = F_43 ( V_122 , struct V_160 , V_122 ) ;
int V_164 = 0 ;
unsigned long V_32 ;
F_85 ( L_78 , V_180 , V_122 , V_227 ) ;
if ( V_180 == NULL || V_122 == NULL || V_183 -> V_242 == NULL )
return - V_64 ;
F_66 ( V_183 -> V_135 , V_32 ) ;
if ( V_183 -> type == V_211 ) {
if ( V_122 -> V_124 )
V_183 = ( V_231 -> V_237 == V_60 ) ?
& V_231 -> V_223 : & V_231 -> V_224 ;
if ( ! F_89 ( & V_183 -> V_152 . V_163 ) ) {
F_93 ( V_183 ) ;
V_164 = - V_267 ;
F_115 ( L_79 , F_83 ( V_183 ) ) ;
}
}
if ( ! F_89 ( & V_184 -> V_163 ) ) {
V_164 = - V_212 ;
F_103 ( L_80 ) ;
goto V_133;
}
if ( V_122 -> V_124 > ( 4 * V_202 ) ) {
V_122 -> V_124 = ( 4 * V_202 ) ;
V_164 = - V_268 ;
F_115 ( L_81 ) ;
}
F_57 ( F_83 ( V_183 ) , V_122 , V_164 ) ;
V_184 -> V_122 . V_106 = - V_269 ;
V_184 -> V_122 . V_216 = 0 ;
V_164 = F_84 ( V_183 , V_184 ) ;
if ( V_164 == - V_186 ) {
F_56 ( F_83 ( V_183 ) , L_21 , V_164 ) ;
V_164 = 0 ;
}
if ( ! V_164 )
F_127 ( & V_184 -> V_163 , & V_183 -> V_152 . V_163 ) ;
V_133:
F_67 ( V_183 -> V_135 , V_32 ) ;
return V_164 ;
}
static int F_128 ( struct V_219 * V_180 , struct V_121 * V_122 )
{
struct V_149 * V_183 = F_43 ( V_180 , struct V_149 , V_180 ) ;
struct V_160 * V_184 = F_43 ( V_122 , struct V_160 , V_122 ) ;
unsigned long V_32 ;
F_85 ( L_63 , V_180 , V_122 ) ;
if ( V_180 == NULL || V_122 == NULL || V_184 -> V_122 . V_106 != - V_186 ||
V_183 -> V_242 == NULL || F_89 ( & V_184 -> V_163 ) ||
F_89 ( & V_183 -> V_152 . V_163 ) )
return - V_64 ;
F_66 ( V_183 -> V_135 , V_32 ) ;
F_56 ( F_83 ( V_183 ) , L_82 , 0 ) ;
F_18 ( V_183 -> V_3 , V_183 -> V_4 ) ;
F_94 ( & V_184 -> V_163 ) ;
if ( V_184 -> V_190 ) {
F_88 ( V_183 -> V_85 , V_184 -> V_122 . V_40 , V_184 -> V_122 . V_124 ,
V_183 -> V_4 ? V_187 : V_188 ) ;
V_184 -> V_122 . V_40 = 0 ;
V_184 -> V_190 = 0 ;
}
V_122 -> V_106 = - V_270 ;
if ( V_184 -> V_122 . V_218 != NULL ) {
F_95 ( V_183 -> V_135 ) ;
V_184 -> V_122 . V_218 ( & V_183 -> V_180 , & V_184 -> V_122 ) ;
F_96 ( V_183 -> V_135 ) ;
}
F_67 ( V_183 -> V_135 , V_32 ) ;
return 0 ;
}
static int F_129 ( struct V_219 * V_180 , int V_63 )
{
struct V_149 * V_183 = F_43 ( V_180 , struct V_149 , V_180 ) ;
int V_266 , V_164 = 0 ;
unsigned long V_32 ;
F_85 ( L_74 , V_180 , V_63 ) ;
if ( V_180 == NULL || V_183 -> V_242 == NULL )
return - V_64 ;
F_66 ( V_183 -> V_135 , V_32 ) ;
#ifndef F_130
if ( V_63 && V_183 -> type == V_271 && V_183 -> V_4 == V_181 &&
! F_89 ( & V_183 -> V_152 . V_163 ) ) {
F_67 ( V_183 -> V_135 , V_32 ) ;
return - V_61 ;
}
#endif
V_266 = V_183 -> V_4 ;
do {
F_56 ( F_83 ( V_183 ) , L_83 , V_63 ) ;
V_164 |= F_26 ( V_183 -> V_3 , V_183 -> V_4 , V_63 ) ;
if ( ! V_63 )
V_183 -> V_247 = 0 ;
if ( V_183 -> type == V_211 )
V_183 -> V_4 = ( V_183 -> V_4 == V_181 ) ? V_60 : V_181 ;
} while ( V_183 -> V_4 != V_266 );
F_67 ( V_183 -> V_135 , V_32 ) ;
return V_164 ;
}
static int F_131 ( struct V_219 * V_180 )
{
struct V_149 * V_183 = F_43 ( V_180 , struct V_149 , V_180 ) ;
unsigned long V_32 ;
F_85 ( L_64 , V_180 ) ;
if ( V_180 == NULL || V_183 -> V_242 == NULL )
return - V_64 ;
F_66 ( V_183 -> V_135 , V_32 ) ;
F_56 ( F_83 ( V_183 ) , L_84 , 0 ) ;
V_183 -> V_247 = 1 ;
F_67 ( V_183 -> V_135 , V_32 ) ;
return F_114 ( V_180 ) ;
}
static void F_132 ( struct V_219 * V_180 )
{
struct V_149 * V_183 = F_43 ( V_180 , struct V_149 , V_180 ) ;
unsigned long V_32 ;
F_85 ( L_64 , V_180 ) ;
if ( V_180 == NULL ) {
F_103 ( L_85 , F_83 ( V_183 ) ) ;
return;
}
F_66 ( V_183 -> V_135 , V_32 ) ;
F_56 ( F_83 ( V_183 ) , L_86 , 0 ) ;
F_18 ( V_183 -> V_3 , V_183 -> V_4 ) ;
F_67 ( V_183 -> V_135 , V_32 ) ;
}
static int F_133 ( struct V_90 * V_272 , int V_273 )
{
struct V_23 * V_24 = F_43 ( V_272 , struct V_23 , V_89 ) ;
unsigned long V_32 ;
int V_274 = 0 ;
if ( ! ( V_24 -> V_29 -> V_32 & V_275 ) )
return - V_276 ;
F_66 ( V_24 -> V_135 , V_32 ) ;
V_24 -> V_277 = V_273 ;
if ( V_24 -> V_102 )
V_274 = 1 ;
F_67 ( V_24 -> V_135 , V_32 ) ;
if ( V_274 ) {
if ( V_273 ) {
F_134 ( & V_272 -> V_86 ) ;
F_14 ( V_24 ) ;
F_17 ( V_24 -> V_223 . V_152 . V_40 ) ;
} else {
F_17 ( 0 ) ;
if ( V_24 -> V_29 -> V_30 )
V_24 -> V_29 -> V_30 ( V_24 ,
V_278 ) ;
F_97 ( & V_24 -> V_89 ) ;
F_135 ( & V_272 -> V_86 ) ;
}
}
return 0 ;
}
static int F_136 ( struct V_90 * V_272 )
{
struct V_23 * V_24 = F_43 ( V_272 , struct V_23 , V_89 ) ;
unsigned long V_32 ;
int V_185 = 0 ;
F_85 () ;
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( ! V_24 -> V_221 ) {
V_185 = - V_276 ;
F_44 ( L_87 ) ;
goto V_279;
}
if ( ! F_8 ( V_73 , V_280 ) ) {
V_185 = - V_64 ;
F_44 ( L_88 ) ;
goto V_279;
}
F_9 ( V_73 , V_281 , V_281 ) ;
V_279:
F_67 ( V_24 -> V_135 , V_32 ) ;
return V_185 ;
}
static int F_137 ( struct V_90 * V_272 , unsigned V_282 )
{
struct V_23 * V_24 = F_43 ( V_272 , struct V_23 , V_89 ) ;
if ( V_24 -> V_283 )
return F_138 ( V_24 -> V_283 , V_282 ) ;
return - V_284 ;
}
static int F_139 ( struct V_101 * V_102 ,
int (* F_140)( struct V_90 * ) )
{
struct V_23 * V_24 = V_231 ;
unsigned long V_32 ;
int V_79 , V_131 ;
int V_164 = - V_189 ;
F_85 ( L_64 , V_102 ) ;
if ( V_102 == NULL ||
F_140 == NULL ||
V_102 -> V_226 == NULL ||
V_102 -> V_225 == NULL ||
V_102 -> V_285 == NULL ||
V_102 -> V_286 == NULL )
return - V_64 ;
else if ( V_24 == NULL )
return - V_22 ;
else if ( V_24 -> V_102 != NULL )
return - V_212 ;
V_24 -> V_287 = F_141 ( L_89 , & V_24 -> V_89 . V_86 ,
sizeof( struct V_153 ) ,
64 , V_202 ) ;
if ( V_24 -> V_287 == NULL )
return - V_189 ;
V_24 -> V_194 = F_141 ( L_90 , & V_24 -> V_89 . V_86 ,
sizeof( struct V_162 ) ,
64 , V_202 ) ;
if ( V_24 -> V_194 == NULL ) {
F_142 ( V_24 -> V_287 ) ;
V_24 -> V_287 = NULL ;
return - V_189 ;
}
F_66 ( V_24 -> V_135 , V_32 ) ;
F_143 ( L_91 , V_20 ) ;
V_24 -> V_89 . V_86 . V_102 = NULL ;
V_164 = 0 ;
for ( V_79 = 0 ; V_79 < V_20 / 2 ; V_79 ++ ) {
for ( V_131 = V_60 ; V_131 <= V_181 ; V_131 ++ ) {
int V_156 = V_79 + V_131 * V_20 / 2 ;
struct V_149 * V_183 = & V_24 -> V_149 [ V_156 ] ;
F_46 ( V_183 -> V_100 , sizeof( V_183 -> V_100 ) , L_92 , V_79 ,
( V_131 == V_181 ) ? L_93 : L_94 ) ;
V_183 -> V_135 = V_24 -> V_135 ;
V_183 -> V_85 = & V_24 -> V_89 . V_86 ;
V_183 -> V_194 = V_24 -> V_194 ;
V_183 -> V_180 . V_100 = V_183 -> V_100 ;
V_183 -> V_180 . V_288 = & V_289 ;
V_183 -> V_180 . V_192 = V_290 ;
F_124 ( & V_183 -> V_152 . V_163 ) ;
F_67 ( V_24 -> V_135 , V_32 ) ;
V_183 -> V_152 . V_154 = F_87 ( V_24 -> V_287 , V_158 ,
& V_183 -> V_152 . V_40 ) ;
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( V_183 -> V_152 . V_154 == NULL )
V_164 = - V_189 ;
else
memset ( V_183 -> V_152 . V_154 , 0 , sizeof( * V_183 -> V_152 . V_154 ) ) ;
if ( V_79 == 0 )
continue;
F_127 ( & V_183 -> V_180 . V_291 , & V_24 -> V_89 . V_291 ) ;
}
}
if ( V_164 )
goto V_133;
F_67 ( V_24 -> V_135 , V_32 ) ;
V_24 -> V_223 . V_180 . V_242 = & V_292 ;
V_164 = F_144 ( & V_24 -> V_223 . V_180 ) ;
if ( V_164 )
return V_164 ;
V_24 -> V_224 . V_180 . V_242 = & V_293 ;
V_164 = F_144 ( & V_24 -> V_224 . V_180 ) ;
if ( V_164 )
return V_164 ;
F_66 ( V_24 -> V_135 , V_32 ) ;
V_24 -> V_89 . V_294 = & V_24 -> V_224 . V_180 ;
V_102 -> V_102 . V_295 = NULL ;
V_24 -> V_89 . V_86 . V_102 = & V_102 -> V_102 ;
F_67 ( V_24 -> V_135 , V_32 ) ;
V_164 = F_140 ( & V_24 -> V_89 ) ;
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( V_164 ) {
V_24 -> V_89 . V_86 . V_102 = NULL ;
goto V_133;
}
V_24 -> V_102 = V_102 ;
F_134 ( & V_24 -> V_89 . V_86 ) ;
if ( V_24 -> V_29 -> V_32 & V_275 ) {
if ( V_24 -> V_277 ) {
if ( V_24 -> V_29 -> V_32 & V_296 )
F_14 ( V_24 ) ;
} else {
F_135 ( & V_24 -> V_89 . V_86 ) ;
goto V_133;
}
}
V_164 = F_17 ( V_24 -> V_223 . V_152 . V_40 ) ;
if ( V_164 )
F_135 ( & V_24 -> V_89 . V_86 ) ;
V_133:
F_67 ( V_24 -> V_135 , V_32 ) ;
return V_164 ;
}
static int F_145 ( struct V_101 * V_102 )
{
struct V_23 * V_24 = V_231 ;
unsigned long V_79 , V_32 ;
F_85 ( L_64 , V_102 ) ;
if ( V_102 == NULL ||
V_102 -> V_297 == NULL ||
V_102 -> V_226 == NULL ||
V_102 -> V_225 == NULL ||
V_102 -> V_285 == NULL ||
V_102 -> V_286 == NULL ||
V_102 != V_24 -> V_102 )
return - V_64 ;
F_66 ( V_24 -> V_135 , V_32 ) ;
if ( ! ( V_24 -> V_29 -> V_32 & V_275 ) ||
V_24 -> V_277 ) {
F_17 ( 0 ) ;
if ( V_24 -> V_29 -> V_30 )
V_24 -> V_29 -> V_30 ( V_24 ,
V_278 ) ;
F_97 ( & V_24 -> V_89 ) ;
F_146 ( & V_24 -> V_89 . V_86 ) ;
}
F_67 ( V_24 -> V_135 , V_32 ) ;
V_102 -> V_297 ( & V_24 -> V_89 ) ;
F_66 ( V_24 -> V_135 , V_32 ) ;
V_24 -> V_89 . V_86 . V_102 = NULL ;
for ( V_79 = 0 ; V_79 < V_20 ; V_79 ++ ) {
struct V_149 * V_183 = & V_24 -> V_149 [ V_79 ] ;
if ( ! F_89 ( & V_183 -> V_180 . V_291 ) )
F_94 ( & V_183 -> V_180 . V_291 ) ;
if ( V_183 -> V_152 . V_154 != NULL )
F_92 ( V_24 -> V_287 , V_183 -> V_152 . V_154 , V_183 -> V_152 . V_40 ) ;
}
V_24 -> V_89 . V_294 = NULL ;
V_24 -> V_102 = NULL ;
F_67 ( V_24 -> V_135 , V_32 ) ;
if ( V_24 -> V_194 != NULL ) {
F_142 ( V_24 -> V_194 ) ;
V_24 -> V_194 = NULL ;
}
if ( V_24 -> V_287 != NULL ) {
F_142 ( V_24 -> V_287 ) ;
V_24 -> V_287 = NULL ;
}
return 0 ;
}
static T_9 F_147 ( void )
{
struct V_23 * V_24 = V_231 ;
T_9 V_164 ;
T_1 V_134 ;
F_85 () ;
if ( V_24 == NULL ) {
F_103 ( L_95 ) ;
return V_298 ;
}
F_96 ( V_24 -> V_135 ) ;
if ( V_24 -> V_29 -> V_32 & V_296 ) {
if ( F_8 ( V_34 , V_36 ) !=
V_38 ) {
F_95 ( V_24 -> V_135 ) ;
return V_299 ;
}
}
V_134 = F_37 () ;
if ( V_134 ) {
V_136 . V_144 . V_78 [ V_136 . V_144 . V_104 ++ ] = V_134 ;
V_136 . V_144 . V_104 &= V_146 ;
V_136 . V_144 . V_145 ++ ;
if ( V_46 & V_134 ) {
V_136 . V_141 ++ ;
F_102 ( V_24 ) ;
}
if ( V_45 & V_134 ) {
V_136 . V_140 ++ ;
V_24 -> V_89 . V_93 = F_29 () ?
V_300 : V_301 ;
if ( V_24 -> V_222 ) {
F_95 ( V_24 -> V_135 ) ;
V_24 -> V_102 -> V_286 ( & V_24 -> V_89 ) ;
F_96 ( V_24 -> V_135 ) ;
V_24 -> V_222 = 0 ;
}
}
if ( V_44 & V_134 )
V_136 . V_139 ++ ;
if ( V_43 & V_134 ) {
V_136 . V_138 ++ ;
F_113 ( V_24 ) ;
}
if ( V_47 & V_134 ) {
if ( V_24 -> V_89 . V_93 != V_220 ) {
V_24 -> V_222 = 1 ;
F_95 ( V_24 -> V_135 ) ;
V_24 -> V_102 -> V_285 ( & V_24 -> V_89 ) ;
F_96 ( V_24 -> V_135 ) ;
}
V_136 . V_142 ++ ;
}
V_164 = V_298 ;
} else {
V_136 . V_143 ++ ;
V_164 = V_299 ;
}
F_95 ( V_24 -> V_135 ) ;
return V_164 ;
}
static void F_148 ( struct V_85 * V_86 )
{
F_85 ( L_64 , V_86 ) ;
if ( V_86 == NULL )
F_103 ( L_65 ) ;
}
static int F_149 ( struct V_302 * V_102 , struct V_85 * V_86 ,
void T_2 * V_303 )
{
struct V_23 * V_24 ;
int V_164 = 0 ;
F_85 ( L_96 , V_86 , V_303 , V_100 ) ;
if ( V_86 == NULL || V_303 == NULL || V_102 == NULL ||
V_102 -> V_100 == NULL )
return - V_64 ;
V_24 = F_107 ( sizeof( struct V_23 ) , V_158 ) ;
if ( V_24 == NULL )
return - V_189 ;
V_24 -> V_135 = & V_304 ;
V_24 -> V_303 = V_303 ;
V_24 -> V_29 = V_102 ;
V_24 -> V_89 . V_288 = & V_305 ;
V_24 -> V_89 . V_93 = V_220 ;
V_24 -> V_89 . V_94 = 1 ;
V_24 -> V_89 . V_95 = 0 ;
V_24 -> V_89 . V_100 = V_102 -> V_100 ;
F_124 ( & V_24 -> V_89 . V_291 ) ;
V_24 -> V_89 . V_294 = NULL ;
F_150 ( & V_24 -> V_89 . V_86 , L_97 ) ;
V_24 -> V_89 . V_86 . V_306 = V_86 -> V_306 ;
V_24 -> V_89 . V_86 . V_307 = V_86 -> V_307 ;
V_24 -> V_89 . V_86 . V_308 = V_86 ;
V_24 -> V_89 . V_86 . V_309 = F_148 ;
V_164 = F_12 ( V_303 ) ;
if ( V_164 < 0 )
goto V_310;
V_24 -> V_283 = F_151 () ;
if ( V_24 -> V_29 -> V_32 & V_311 ) {
if ( V_24 -> V_283 == NULL ) {
V_164 = - V_22 ;
goto V_310;
}
}
if ( ! ( V_24 -> V_29 -> V_32 & V_296 ) ) {
V_164 = F_14 ( V_24 ) ;
if ( V_164 )
goto V_312;
}
V_164 = F_152 ( & V_24 -> V_89 . V_86 ) ;
if ( V_164 ) {
F_153 ( & V_24 -> V_89 . V_86 ) ;
goto V_312;
}
#ifdef F_154
V_164 = F_79 ( & V_24 -> V_89 . V_86 ) ;
#endif
if ( V_164 )
goto V_313;
if ( V_24 -> V_283 ) {
V_164 = F_155 ( V_24 -> V_283 , & V_24 -> V_89 ) ;
if ( V_164 )
goto V_314;
}
V_164 = F_156 ( V_86 , & V_24 -> V_89 ) ;
if ( V_164 )
goto V_315;
F_157 ( & V_24 -> V_89 . V_86 ) ;
F_158 ( & V_24 -> V_89 . V_86 ) ;
V_231 = V_24 ;
return V_164 ;
V_315:
if ( V_24 -> V_283 ) {
F_155 ( V_24 -> V_283 , & V_24 -> V_89 ) ;
F_159 ( V_24 -> V_283 ) ;
}
F_103 ( L_98 , V_164 ) ;
V_314:
#ifdef F_154
F_82 ( & V_24 -> V_89 . V_86 ) ;
#endif
V_313:
F_160 ( & V_24 -> V_89 . V_86 ) ;
V_312:
if ( V_24 -> V_283 )
F_159 ( V_24 -> V_283 ) ;
V_310:
F_74 ( V_24 ) ;
V_231 = NULL ;
return V_164 ;
}
static void F_161 ( void )
{
struct V_23 * V_24 = V_231 ;
if ( V_24 == NULL ) {
F_103 ( L_65 ) ;
return;
}
F_162 ( & V_24 -> V_89 ) ;
if ( V_24 -> V_283 ) {
F_155 ( V_24 -> V_283 , & V_24 -> V_89 ) ;
F_159 ( V_24 -> V_283 ) ;
}
#ifdef F_154
F_82 ( & V_24 -> V_89 . V_86 ) ;
#endif
F_160 ( & V_24 -> V_89 . V_86 ) ;
F_74 ( V_24 ) ;
V_231 = NULL ;
}
