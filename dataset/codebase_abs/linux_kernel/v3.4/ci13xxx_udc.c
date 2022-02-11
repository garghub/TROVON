static int F_1 ( T_1 V_1 )
{
int V_2 = F_2 ( V_1 ) ;
return V_2 ? V_2 - 1 : 32 ;
}
static inline int F_3 ( int V_3 , int V_4 )
{
return V_3 + ( V_4 ? 16 : 0 ) ;
}
static int F_4 ( int V_2 )
{
int V_5 = 16 - V_6 / 2 ;
if ( V_2 >= V_6 / 2 )
V_2 += V_5 ;
return V_2 ;
}
static T_1 F_5 ( T_1 V_7 , T_1 V_8 )
{
return F_6 ( V_7 + V_9 . abs ) & V_8 ;
}
static void F_7 ( T_1 V_7 , T_1 V_8 , T_1 V_10 )
{
F_8 ( F_5 ( V_7 , ~ V_8 ) | ( V_10 & V_8 ) ,
V_7 + V_9 . abs ) ;
}
static T_1 F_9 ( T_1 V_7 , T_1 V_8 )
{
return F_6 ( V_7 + V_9 . V_11 ) & V_8 ;
}
static void F_10 ( T_1 V_7 , T_1 V_8 , T_1 V_10 )
{
F_8 ( F_9 ( V_7 , ~ V_8 ) | ( V_10 & V_8 ) ,
V_7 + V_9 . V_11 ) ;
}
static T_1 F_11 ( T_1 V_7 , T_1 V_8 )
{
T_1 V_12 = F_9 ( V_7 , V_8 ) ;
F_8 ( V_12 , V_7 + V_9 . V_11 ) ;
return V_12 ;
}
static T_1 F_12 ( T_1 V_7 , T_1 V_8 , T_1 V_10 )
{
T_1 V_12 = F_9 ( V_7 , ~ 0 ) ;
F_8 ( ( V_12 & ~ V_8 ) | ( V_10 & V_8 ) , V_7 + V_9 . V_11 ) ;
return ( V_12 & V_8 ) >> F_1 ( V_8 ) ;
}
static int F_13 ( void T_2 * V_13 )
{
T_1 V_12 ;
V_9 . abs = V_13 ;
V_9 . V_11 = V_9 . abs ;
V_9 . V_11 += V_14 ;
V_9 . V_11 += F_14 ( V_9 . V_11 ) ;
V_12 = F_5 ( V_15 , V_16 ) >> F_1 ( V_16 ) ;
V_9 . V_17 = V_12 ;
V_9 . V_18 = V_9 . V_11 - V_9 . abs ;
V_9 . V_18 += V_19 ;
V_9 . V_18 /= sizeof( T_1 ) ;
V_12 = F_5 ( V_20 , V_21 ) >> F_1 ( V_21 ) ;
V_6 = V_12 * 2 ;
if ( V_6 == 0 || V_6 > V_22 )
return - V_23 ;
return 0 ;
}
static int F_15 ( struct V_24 * V_25 )
{
F_10 ( V_26 , ~ 0 , ~ 0 ) ;
F_10 ( V_27 , V_28 , 0 ) ;
F_10 ( V_27 , V_29 , V_29 ) ;
while ( F_9 ( V_27 , V_29 ) )
F_16 ( 10 ) ;
if ( V_25 -> V_30 -> V_31 )
V_25 -> V_30 -> V_31 ( V_25 ,
V_32 ) ;
if ( V_25 -> V_30 -> V_33 & V_34 )
F_10 ( V_35 , V_36 , V_36 ) ;
F_10 ( V_35 , V_37 , V_38 ) ;
F_10 ( V_35 , V_37 , V_39 ) ;
F_10 ( V_35 , V_40 , V_40 ) ;
if ( F_9 ( V_35 , V_37 ) != V_39 ) {
F_17 ( L_1 ) ;
F_17 ( L_2 , V_9 . V_17 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_18 ( T_1 V_41 )
{
if ( V_41 ) {
F_10 ( V_42 , ~ 0 , V_41 ) ;
F_10 ( V_43 , ~ 0 ,
V_44 | V_45 | V_46 | V_47 | V_48 ) ;
F_10 ( V_27 , V_28 , V_28 ) ;
} else {
F_10 ( V_27 , V_28 , 0 ) ;
F_10 ( V_43 , ~ 0 , 0 ) ;
}
return 0 ;
}
static int F_19 ( int V_3 , int V_4 )
{
int V_2 = F_3 ( V_3 , V_4 ) ;
do {
F_10 ( V_26 , F_20 ( V_2 ) , F_20 ( V_2 ) ) ;
while ( F_9 ( V_26 , F_20 ( V_2 ) ) )
F_21 () ;
} while ( F_9 ( V_49 , F_20 ( V_2 ) ) );
return 0 ;
}
static int F_22 ( int V_3 , int V_4 )
{
F_19 ( V_3 , V_4 ) ;
F_10 ( V_50 + V_3 * sizeof( T_1 ) ,
V_4 ? V_51 : V_52 , 0 ) ;
return 0 ;
}
static int F_23 ( int V_3 , int V_4 , int type )
{
T_1 V_8 , V_10 ;
if ( V_4 ) {
V_8 = V_53 ;
V_10 = type << F_1 ( V_8 ) ;
V_8 |= V_54 ;
V_8 |= V_55 ;
V_10 |= V_55 ;
V_8 |= V_51 ;
V_10 |= V_51 ;
} else {
V_8 = V_56 ;
V_10 = type << F_1 ( V_8 ) ;
V_8 |= V_57 ;
V_8 |= V_58 ;
V_10 |= V_58 ;
V_8 |= V_52 ;
V_10 |= V_52 ;
}
F_10 ( V_50 + V_3 * sizeof( T_1 ) , V_8 , V_10 ) ;
return 0 ;
}
static int F_24 ( int V_3 , int V_4 )
{
T_1 V_8 = V_4 ? V_54 : V_57 ;
return F_9 ( V_50 + V_3 * sizeof( T_1 ) , V_8 ) ? 1 : 0 ;
}
static int F_25 ( int V_2 )
{
V_2 = F_4 ( V_2 ) ;
return F_11 ( V_59 , F_20 ( V_2 ) ) ;
}
static int F_26 ( int V_3 , int V_4 , int V_60 )
{
int V_2 = F_3 ( V_3 , V_4 ) ;
if ( V_60 && V_4 == V_61 && F_9 ( V_59 , F_20 ( V_3 ) ) )
return - V_62 ;
F_10 ( V_63 , F_20 ( V_2 ) , F_20 ( V_2 ) ) ;
while ( F_9 ( V_63 , F_20 ( V_2 ) ) )
F_21 () ;
if ( V_60 && V_4 == V_61 && F_9 ( V_59 , F_20 ( V_3 ) ) )
return - V_62 ;
return 0 ;
}
static int F_27 ( int V_3 , int V_4 , int V_64 )
{
if ( V_64 != 0 && V_64 != 1 )
return - V_65 ;
do {
T_1 V_7 = V_50 + V_3 * sizeof( T_1 ) ;
T_1 V_66 = V_4 ? V_54 : V_57 ;
T_1 V_67 = V_4 ? V_55 : V_58 ;
F_10 ( V_7 , V_66 | V_67 , V_64 ? V_66 : V_67 ) ;
} while ( V_64 != F_24 ( V_3 , V_4 ) );
return 0 ;
}
static int F_28 ( int V_2 )
{
if ( V_2 >= V_68 )
return - V_65 ;
F_10 ( V_43 , F_20 ( V_2 ) , 0 ) ;
F_10 ( V_69 , F_20 ( V_2 ) , F_20 ( V_2 ) ) ;
return 0 ;
}
static int F_29 ( int V_2 )
{
if ( V_2 >= V_68 )
return - V_65 ;
F_7 ( V_70 , V_71 , V_71 ) ;
F_10 ( V_43 , F_20 ( V_2 ) , F_20 ( V_2 ) ) ;
F_10 ( V_69 , F_20 ( V_2 ) , F_20 ( V_2 ) ) ;
F_7 ( V_70 , V_71 , 0 ) ;
return 0 ;
}
static int F_30 ( void )
{
return V_9 . V_17 ? F_9 ( V_72 , V_73 ) :
F_9 ( V_74 , V_75 ) ;
}
static T_3 F_31 ( void )
{
return F_9 ( V_74 , V_76 ) >> F_1 ( V_76 ) ;
}
static int F_32 ( T_3 V_77 )
{
const T_3 V_78 = 7 ;
if ( V_77 > V_78 )
return - V_65 ;
F_10 ( V_74 , V_76 , V_77 << F_1 ( V_76 ) ) ;
return 0 ;
}
static T_1 F_33 ( void )
{
return F_9 ( V_43 , ~ 0 ) ;
}
static T_1 F_34 ( void )
{
return F_9 ( V_69 , ~ 0 ) ;
}
static T_4 F_35 ( T_1 * V_79 , T_4 V_18 )
{
unsigned V_80 ;
if ( V_18 > V_9 . V_18 )
V_18 = V_9 . V_18 ;
for ( V_80 = 0 ; V_80 < V_18 ; V_80 ++ )
V_79 [ V_80 ] = F_5 ( V_80 * sizeof( T_1 ) , ~ 0 ) ;
return V_18 ;
}
static int F_36 ( T_5 V_7 , T_1 V_10 )
{
V_7 /= sizeof( T_1 ) ;
if ( V_7 >= V_9 . V_18 )
return - V_65 ;
V_7 *= sizeof( T_1 ) ;
F_7 ( V_7 , ~ 0 , V_10 ) ;
return 0 ;
}
static int F_37 ( int V_2 )
{
V_2 = F_4 ( V_2 ) ;
return F_11 ( V_81 , F_20 ( V_2 ) ) ;
}
static T_1 F_38 ( void )
{
T_1 V_12 = F_34 () & F_33 () ;
F_10 ( V_69 , ~ 0 , V_12 ) ;
return V_12 ;
}
static int F_39 ( void )
{
return F_12 ( V_27 , V_82 , 0 ) ;
}
static int F_40 ( void )
{
return F_12 ( V_27 , V_82 , V_82 ) ;
}
static int F_41 ( T_3 V_64 )
{
F_10 ( V_83 , V_84 | V_85 ,
V_64 << F_1 ( V_84 ) | V_85 ) ;
return 0 ;
}
static int F_42 ( void )
{
F_41 ( 0 ) ;
F_10 ( V_26 , ~ 0 , ~ 0 ) ;
F_10 ( V_59 , 0 , 0 ) ;
F_10 ( V_81 , 0 , 0 ) ;
while ( F_9 ( V_63 , ~ 0 ) )
F_16 ( 10 ) ;
return 0 ;
}
static T_6 F_43 ( struct V_86 * V_87 , struct V_88 * V_89 ,
char * V_79 )
{
struct V_24 * V_25 = F_44 ( V_87 , struct V_24 , V_90 . V_87 ) ;
struct V_91 * V_90 = & V_25 -> V_90 ;
int V_2 = 0 ;
F_45 ( L_3 , V_92 , V_79 ) ;
if ( V_89 == NULL || V_79 == NULL ) {
F_46 ( V_87 , L_4 , V_92 ) ;
return 0 ;
}
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_5 ,
V_90 -> V_94 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_6 ,
V_90 -> V_95 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_7 ,
F_48 ( V_90 ) ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_8 ,
V_90 -> V_96 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_9 ,
V_90 -> V_97 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_10 ,
V_90 -> V_98 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_11 ,
V_90 -> V_99 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_12 ,
V_90 -> V_100 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_13 ,
( V_90 -> V_101 ? V_90 -> V_101 : L_14 ) ) ;
return V_2 ;
}
static T_6 F_49 ( struct V_86 * V_87 , struct V_88 * V_89 ,
char * V_79 )
{
struct V_24 * V_25 = F_44 ( V_87 , struct V_24 , V_90 . V_87 ) ;
struct V_102 * V_103 = V_25 -> V_103 ;
int V_2 = 0 ;
F_45 ( L_3 , V_92 , V_79 ) ;
if ( V_89 == NULL || V_79 == NULL ) {
F_46 ( V_87 , L_4 , V_92 ) ;
return 0 ;
}
if ( V_103 == NULL )
return F_47 ( V_79 , V_93 ,
L_15 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_16 ,
( V_103 -> V_104 ? V_103 -> V_104 : L_14 ) ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_17 ,
V_103 -> V_95 ) ;
return V_2 ;
}
static void F_50 ( unsigned * V_105 )
{
* V_105 = ( * V_105 - 1 ) & ( V_106 - 1 ) ;
}
static void F_51 ( unsigned * V_105 )
{
* V_105 = ( * V_105 + 1 ) & ( V_106 - 1 ) ;
}
static void F_52 ( T_3 V_7 , const char * V_101 , int V_107 , const char * V_108 )
{
struct V_109 V_110 ;
unsigned int V_111 ;
unsigned long V_33 ;
F_53 ( & V_112 . V_113 , V_33 ) ;
F_54 ( & V_110 ) ;
V_111 = V_110 . V_114 & 0xFFFF ;
V_111 = V_111 * 1000000 + V_110 . V_115 ;
F_47 ( V_112 . V_79 [ V_112 . V_105 ] , V_116 ,
L_18 ,
V_111 , V_7 , V_101 , V_107 , V_108 ) ;
F_51 ( & V_112 . V_105 ) ;
F_55 ( & V_112 . V_113 , V_33 ) ;
if ( V_112 . V_117 != 0 )
F_56 ( L_18 ,
V_111 , V_7 , V_101 , V_107 , V_108 ) ;
}
static void F_57 ( T_3 V_7 , const T_1 V_118 , int V_107 )
{
char V_119 [ V_116 ] ;
F_47 ( V_119 , sizeof( V_119 ) , L_19 ,
( int ) ( V_118 & V_120 ) >> F_1 ( V_120 ) ,
( int ) ( V_118 & V_121 ) >> F_1 ( V_121 ) ) ;
F_52 ( V_7 , L_20 , V_107 , V_119 ) ;
}
static void F_58 ( T_3 V_7 , const char * V_101 , int V_107 )
{
if ( V_101 != NULL )
F_52 ( V_7 , V_101 , V_107 , L_14 ) ;
}
static void F_59 ( T_3 V_7 , const struct V_122 * V_123 , int V_107 )
{
char V_119 [ V_116 ] ;
if ( V_123 != NULL ) {
F_47 ( V_119 , sizeof( V_119 ) ,
L_21 , ! V_123 -> V_124 , V_123 -> V_125 ) ;
F_52 ( V_7 , L_22 , V_107 , V_119 ) ;
}
}
static void F_60 ( T_3 V_7 , const struct V_126 * V_123 )
{
char V_119 [ V_116 ] ;
if ( V_123 != NULL ) {
F_47 ( V_119 , sizeof( V_119 ) ,
L_23 , V_123 -> V_127 ,
V_123 -> V_128 , F_61 ( V_123 -> V_129 ) ,
F_61 ( V_123 -> V_130 ) , F_61 ( V_123 -> V_131 ) ) ;
F_52 ( V_7 , L_24 , 0 , V_119 ) ;
}
}
static T_6 F_62 ( struct V_86 * V_87 , struct V_88 * V_89 ,
char * V_79 )
{
unsigned long V_33 ;
unsigned V_80 , V_132 , V_2 = 0 ;
F_45 ( L_3 , V_92 , V_79 ) ;
if ( V_89 == NULL || V_79 == NULL ) {
F_46 ( V_87 , L_4 , V_92 ) ;
return 0 ;
}
F_63 ( & V_112 . V_113 , V_33 ) ;
V_80 = V_112 . V_105 ;
for ( F_50 ( & V_80 ) ; V_80 != V_112 . V_105 ; F_50 ( & V_80 ) ) {
V_2 += strlen ( V_112 . V_79 [ V_80 ] ) ;
if ( V_2 >= V_93 ) {
V_2 -= strlen ( V_112 . V_79 [ V_80 ] ) ;
break;
}
}
for ( V_132 = 0 , F_51 ( & V_80 ) ; V_132 < V_2 ; F_51 ( & V_80 ) )
V_132 += F_47 ( V_79 + V_132 , V_93 - V_132 ,
L_25 , V_112 . V_79 [ V_80 ] ) ;
F_64 ( & V_112 . V_113 , V_33 ) ;
return V_2 ;
}
static T_6 F_65 ( struct V_86 * V_87 , struct V_88 * V_89 ,
const char * V_79 , T_4 V_133 )
{
unsigned V_117 ;
F_45 ( L_26 , V_92 , V_79 , V_133 ) ;
if ( V_89 == NULL || V_79 == NULL ) {
F_46 ( V_87 , L_4 , V_92 ) ;
goto V_134;
}
if ( sscanf ( V_79 , L_27 , & V_117 ) != 1 || V_117 > 1 ) {
F_46 ( V_87 , L_28 ) ;
goto V_134;
}
V_112 . V_117 = V_117 ;
F_66 ( V_87 , L_29 , V_112 . V_117 ) ;
V_134:
return V_133 ;
}
static T_6 F_67 ( struct V_86 * V_87 , struct V_88 * V_89 ,
char * V_79 )
{
struct V_24 * V_25 = F_44 ( V_87 , struct V_24 , V_90 . V_87 ) ;
unsigned long V_33 ;
T_1 V_135 ;
unsigned V_80 , V_132 , V_2 = 0 ;
F_45 ( L_3 , V_92 , V_79 ) ;
if ( V_89 == NULL || V_79 == NULL ) {
F_46 ( V_87 , L_4 , V_92 ) ;
return 0 ;
}
F_68 ( V_25 -> V_136 , V_33 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 ,
L_30 , F_34 () ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 ,
L_31 , F_33 () ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_32 ,
V_137 . V_138 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_33 ,
V_137 . V_139 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_34 ,
V_137 . V_140 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_35 ,
V_137 . V_141 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_36 ,
V_137 . V_142 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_37 ,
V_137 . V_143 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_38 ,
V_137 . V_144 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_39 ,
V_137 . V_145 . V_146 ) ;
for ( V_80 = V_137 . V_145 . V_105 , V_132 = 0 ; V_132 <= V_147 ; V_132 ++ , V_80 ++ ) {
V_80 &= V_147 ;
V_135 = V_137 . V_145 . V_79 [ V_80 ] ;
if ( V_44 & V_135 )
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_40 ) ;
V_135 &= ~ V_44 ;
if ( V_45 & V_135 )
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_41 ) ;
V_135 &= ~ V_45 ;
if ( V_46 & V_135 )
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_42 ) ;
V_135 &= ~ V_46 ;
if ( V_47 & V_135 )
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_43 ) ;
V_135 &= ~ V_47 ;
if ( V_48 & V_135 )
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_44 ) ;
V_135 &= ~ V_48 ;
if ( V_135 )
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_45 ) ;
if ( V_137 . V_145 . V_79 [ V_80 ] )
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 , L_46 ) ;
}
F_69 ( V_25 -> V_136 , V_33 ) ;
return V_2 ;
}
static T_6 F_70 ( struct V_86 * V_87 , struct V_88 * V_89 ,
const char * V_79 , T_4 V_133 )
{
struct V_24 * V_25 = F_44 ( V_87 , struct V_24 , V_90 . V_87 ) ;
unsigned long V_33 ;
unsigned V_148 , V_149 ;
F_45 ( L_26 , V_92 , V_79 , V_133 ) ;
if ( V_89 == NULL || V_79 == NULL ) {
F_46 ( V_87 , L_4 , V_92 ) ;
goto V_134;
}
if ( sscanf ( V_79 , L_47 , & V_148 , & V_149 ) != 2 || V_148 > 1 ) {
F_46 ( V_87 , L_48 ) ;
goto V_134;
}
F_68 ( V_25 -> V_136 , V_33 ) ;
if ( V_148 ) {
if ( F_29 ( V_149 ) )
F_46 ( V_87 , L_49 ) ;
else
V_137 . V_138 ++ ;
} else {
if ( F_28 ( V_149 ) )
F_46 ( V_87 , L_49 ) ;
}
F_69 ( V_25 -> V_136 , V_33 ) ;
V_134:
return V_133 ;
}
static T_6 F_71 ( struct V_86 * V_87 ,
struct V_88 * V_89 , char * V_79 )
{
struct V_24 * V_25 = F_44 ( V_87 , struct V_24 , V_90 . V_87 ) ;
unsigned long V_33 ;
unsigned V_77 ;
F_45 ( L_3 , V_92 , V_79 ) ;
if ( V_89 == NULL || V_79 == NULL ) {
F_46 ( V_87 , L_4 , V_92 ) ;
return 0 ;
}
F_68 ( V_25 -> V_136 , V_33 ) ;
V_77 = F_31 () ;
F_69 ( V_25 -> V_136 , V_33 ) ;
return F_47 ( V_79 , V_93 , L_50 , V_77 ) ;
}
static T_6 F_72 ( struct V_86 * V_87 ,
struct V_88 * V_89 ,
const char * V_79 , T_4 V_133 )
{
struct V_24 * V_25 = F_44 ( V_87 , struct V_24 , V_90 . V_87 ) ;
unsigned long V_33 ;
unsigned V_77 ;
F_45 ( L_26 , V_92 , V_79 , V_133 ) ;
if ( V_89 == NULL || V_79 == NULL ) {
F_46 ( V_87 , L_4 , V_92 ) ;
goto V_134;
}
if ( sscanf ( V_79 , L_27 , & V_77 ) != 1 ) {
F_46 ( V_87 , L_51 ) ;
goto V_134;
}
F_68 ( V_25 -> V_136 , V_33 ) ;
if ( F_32 ( V_77 ) )
F_46 ( V_87 , L_52 ) ;
F_69 ( V_25 -> V_136 , V_33 ) ;
V_134:
return V_133 ;
}
static T_6 F_73 ( struct V_86 * V_87 , struct V_88 * V_89 ,
char * V_79 )
{
struct V_24 * V_25 = F_44 ( V_87 , struct V_24 , V_90 . V_87 ) ;
unsigned long V_33 ;
unsigned V_80 , V_132 , V_2 = 0 ;
F_45 ( L_3 , V_92 , V_79 ) ;
if ( V_89 == NULL || V_79 == NULL ) {
F_46 ( V_87 , L_4 , V_92 ) ;
return 0 ;
}
F_68 ( V_25 -> V_136 , V_33 ) ;
for ( V_80 = 0 ; V_80 < V_6 / 2 ; V_80 ++ ) {
struct V_150 * V_151 = & V_25 -> V_150 [ V_80 ] ;
struct V_150 * V_152 = & V_25 -> V_150 [ V_80 + V_6 / 2 ] ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 ,
L_53 ,
V_80 , ( T_1 ) V_151 -> V_153 . V_41 , ( T_1 ) V_152 -> V_153 . V_41 ) ;
for ( V_132 = 0 ; V_132 < ( sizeof( struct V_154 ) / sizeof( T_1 ) ) ; V_132 ++ ) {
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 ,
L_54 , V_132 ,
* ( ( T_1 * ) V_151 -> V_153 . V_155 + V_132 ) ,
* ( ( T_1 * ) V_152 -> V_153 . V_155 + V_132 ) ) ;
}
}
F_69 ( V_25 -> V_136 , V_33 ) ;
return V_2 ;
}
static T_6 F_74 ( struct V_86 * V_87 ,
struct V_88 * V_89 , char * V_79 )
{
struct V_24 * V_25 = F_44 ( V_87 , struct V_24 , V_90 . V_87 ) ;
unsigned long V_33 ;
T_1 * V_156 ;
unsigned V_80 , V_157 , V_2 = 0 ;
F_45 ( L_3 , V_92 , V_79 ) ;
if ( V_89 == NULL || V_79 == NULL ) {
F_46 ( V_87 , L_4 , V_92 ) ;
return 0 ;
}
V_156 = F_75 ( sizeof( T_1 ) * V_158 , V_159 ) ;
if ( ! V_156 ) {
F_46 ( V_87 , L_55 , V_92 ) ;
return 0 ;
}
F_68 ( V_25 -> V_136 , V_33 ) ;
V_157 = F_35 ( V_156 , V_158 ) ;
F_69 ( V_25 -> V_136 , V_33 ) ;
for ( V_80 = 0 ; V_80 < V_157 ; V_80 ++ ) {
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 ,
L_56 ,
V_80 * ( unsigned ) sizeof( T_1 ) , V_156 [ V_80 ] ) ;
}
F_76 ( V_156 ) ;
return V_2 ;
}
static T_6 F_77 ( struct V_86 * V_87 ,
struct V_88 * V_89 ,
const char * V_79 , T_4 V_133 )
{
struct V_24 * V_25 = F_44 ( V_87 , struct V_24 , V_90 . V_87 ) ;
unsigned long V_7 , V_10 , V_33 ;
F_45 ( L_26 , V_92 , V_79 , V_133 ) ;
if ( V_89 == NULL || V_79 == NULL ) {
F_46 ( V_87 , L_4 , V_92 ) ;
goto V_134;
}
if ( sscanf ( V_79 , L_57 , & V_7 , & V_10 ) != 2 ) {
F_46 ( V_87 , L_58 ) ;
goto V_134;
}
F_68 ( V_25 -> V_136 , V_33 ) ;
if ( F_36 ( V_7 , V_10 ) )
F_46 ( V_87 , L_59 ) ;
F_69 ( V_25 -> V_136 , V_33 ) ;
V_134:
return V_133 ;
}
static T_6 F_78 ( struct V_86 * V_87 , struct V_88 * V_89 ,
char * V_79 )
{
struct V_24 * V_25 = F_44 ( V_87 , struct V_24 , V_90 . V_87 ) ;
unsigned long V_33 ;
struct V_160 * V_155 = NULL ;
struct V_161 * V_123 = NULL ;
unsigned V_80 , V_132 , V_2 = 0 , V_162 = sizeof( struct V_163 ) / sizeof( T_1 ) ;
F_45 ( L_3 , V_92 , V_79 ) ;
if ( V_89 == NULL || V_79 == NULL ) {
F_46 ( V_87 , L_4 , V_92 ) ;
return 0 ;
}
F_68 ( V_25 -> V_136 , V_33 ) ;
for ( V_80 = 0 ; V_80 < V_6 ; V_80 ++ )
F_79 (ptr, &udc->ci13xxx_ep[i].qh.queue)
{
V_123 = F_80 ( V_155 , struct V_161 , V_164 ) ;
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 ,
L_60 ,
V_80 % V_6 / 2 , ( T_1 ) V_123 -> V_41 ,
( ( V_80 < V_6 / 2 ) ? L_61 : L_62 ) ) ;
for ( V_132 = 0 ; V_132 < V_162 ; V_132 ++ )
V_2 += F_47 ( V_79 + V_2 , V_93 - V_2 ,
L_63 , V_132 ,
* ( ( T_1 * ) V_123 -> V_155 + V_132 ) ) ;
}
F_69 ( V_25 -> V_136 , V_33 ) ;
return V_2 ;
}
T_7 static int F_81 ( struct V_86 * V_87 )
{
int V_165 = 0 ;
if ( V_87 == NULL )
return - V_65 ;
V_165 = F_82 ( V_87 , & V_166 ) ;
if ( V_165 )
goto V_134;
V_165 = F_82 ( V_87 , & V_167 ) ;
if ( V_165 )
goto V_168;
V_165 = F_82 ( V_87 , & V_169 ) ;
if ( V_165 )
goto V_170;
V_165 = F_82 ( V_87 , & V_171 ) ;
if ( V_165 )
goto V_172;
V_165 = F_82 ( V_87 , & V_173 ) ;
if ( V_165 )
goto V_174;
V_165 = F_82 ( V_87 , & V_175 ) ;
if ( V_165 )
goto V_176;
V_165 = F_82 ( V_87 , & V_177 ) ;
if ( V_165 )
goto V_178;
V_165 = F_82 ( V_87 , & V_179 ) ;
if ( V_165 )
goto V_180;
return 0 ;
V_180:
F_83 ( V_87 , & V_177 ) ;
V_178:
F_83 ( V_87 , & V_175 ) ;
V_176:
F_83 ( V_87 , & V_173 ) ;
V_174:
F_83 ( V_87 , & V_171 ) ;
V_172:
F_83 ( V_87 , & V_169 ) ;
V_170:
F_83 ( V_87 , & V_167 ) ;
V_168:
F_83 ( V_87 , & V_166 ) ;
V_134:
return V_165 ;
}
T_7 static int F_84 ( struct V_86 * V_87 )
{
if ( V_87 == NULL )
return - V_65 ;
F_83 ( V_87 , & V_179 ) ;
F_83 ( V_87 , & V_177 ) ;
F_83 ( V_87 , & V_175 ) ;
F_83 ( V_87 , & V_173 ) ;
F_83 ( V_87 , & V_171 ) ;
F_83 ( V_87 , & V_169 ) ;
F_83 ( V_87 , & V_167 ) ;
F_83 ( V_87 , & V_166 ) ;
return 0 ;
}
static inline T_3 F_85 ( struct V_150 * V_181 )
{
return ( ( V_181 -> V_4 == V_182 ) ? V_183 : 0 ) | V_181 -> V_3 ;
}
static int F_86 ( struct V_150 * V_184 , struct V_161 * V_185 )
{
unsigned V_80 ;
int V_186 = 0 ;
unsigned V_125 = V_185 -> V_123 . V_125 ;
F_87 ( L_64 , V_184 , V_185 ) ;
if ( V_185 -> V_123 . V_107 == - V_187 )
return - V_187 ;
V_185 -> V_123 . V_107 = - V_187 ;
if ( V_125 && V_185 -> V_123 . V_41 == V_188 ) {
V_185 -> V_123 . V_41 = \
F_88 ( V_184 -> V_86 , V_185 -> V_123 . V_79 ,
V_125 , V_184 -> V_4 ? V_189 :
V_190 ) ;
if ( V_185 -> V_123 . V_41 == 0 )
return - V_191 ;
V_185 -> V_192 = 1 ;
}
if ( V_185 -> V_123 . V_193 && V_125 && ( V_125 % V_184 -> V_181 . V_194 == 0 ) ) {
V_185 -> V_195 = F_89 ( V_184 -> V_196 , V_197 ,
& V_185 -> V_198 ) ;
if ( V_185 -> V_195 == NULL ) {
if ( V_185 -> V_192 ) {
F_90 ( V_184 -> V_86 , V_185 -> V_123 . V_41 ,
V_125 , V_184 -> V_4 ? V_189 :
V_190 ) ;
V_185 -> V_123 . V_41 = V_188 ;
V_185 -> V_192 = 0 ;
}
return - V_191 ;
}
memset ( V_185 -> V_195 , 0 , sizeof( * V_185 -> V_195 ) ) ;
V_185 -> V_195 -> V_199 = V_200 ;
V_185 -> V_195 -> V_118 = V_201 ;
if ( ! V_185 -> V_123 . V_124 )
V_185 -> V_195 -> V_118 |= V_202 ;
}
memset ( V_185 -> V_155 , 0 , sizeof( * V_185 -> V_155 ) ) ;
V_185 -> V_155 -> V_118 = V_125 << F_1 ( V_120 ) ;
V_185 -> V_155 -> V_118 &= V_120 ;
V_185 -> V_155 -> V_118 |= V_201 ;
if ( V_185 -> V_195 ) {
V_185 -> V_155 -> V_199 = V_185 -> V_198 ;
} else {
V_185 -> V_155 -> V_199 = V_200 ;
if ( ! V_185 -> V_123 . V_124 )
V_185 -> V_155 -> V_118 |= V_202 ;
}
V_185 -> V_155 -> V_203 [ 0 ] = V_185 -> V_123 . V_41 ;
for ( V_80 = 1 ; V_80 < 5 ; V_80 ++ )
V_185 -> V_155 -> V_203 [ V_80 ] =
( V_185 -> V_123 . V_41 + V_80 * V_204 ) & ~ V_205 ;
if ( ! F_91 ( & V_184 -> V_153 . V_164 ) ) {
struct V_161 * V_206 ;
int V_2 = F_3 ( V_184 -> V_3 , V_184 -> V_4 ) ;
int V_207 ;
V_206 = F_80 ( V_184 -> V_153 . V_164 . V_208 ,
struct V_161 , V_164 ) ;
if ( V_206 -> V_195 )
V_206 -> V_195 -> V_199 = V_185 -> V_41 & V_209 ;
else
V_206 -> V_155 -> V_199 = V_185 -> V_41 & V_209 ;
F_92 () ;
if ( F_9 ( V_63 , F_20 ( V_2 ) ) )
goto V_134;
do {
F_10 ( V_27 , V_210 , V_210 ) ;
V_207 = F_9 ( V_49 , F_20 ( V_2 ) ) ;
} while ( ! F_9 ( V_27 , V_210 ) );
F_10 ( V_27 , V_210 , 0 ) ;
if ( V_207 )
goto V_134;
}
V_184 -> V_153 . V_155 -> V_211 . V_199 = V_185 -> V_41 ;
V_184 -> V_153 . V_155 -> V_211 . V_118 &= ~ V_121 ;
V_184 -> V_153 . V_155 -> V_11 |= V_212 ;
F_92 () ;
V_186 = F_26 ( V_184 -> V_3 , V_184 -> V_4 ,
V_184 -> type == V_213 ) ;
V_134:
return V_186 ;
}
static int F_93 ( struct V_150 * V_184 , struct V_161 * V_185 )
{
F_87 ( L_64 , V_184 , V_185 ) ;
if ( V_185 -> V_123 . V_107 != - V_187 )
return - V_65 ;
if ( ( V_201 & V_185 -> V_155 -> V_118 ) != 0 )
return - V_214 ;
if ( V_185 -> V_195 ) {
if ( ( V_201 & V_185 -> V_195 -> V_118 ) != 0 )
return - V_214 ;
F_94 ( V_184 -> V_196 , V_185 -> V_195 , V_185 -> V_198 ) ;
V_185 -> V_195 = NULL ;
}
V_185 -> V_123 . V_107 = 0 ;
if ( V_185 -> V_192 ) {
F_90 ( V_184 -> V_86 , V_185 -> V_123 . V_41 , V_185 -> V_123 . V_125 ,
V_184 -> V_4 ? V_189 : V_190 ) ;
V_185 -> V_123 . V_41 = V_188 ;
V_185 -> V_192 = 0 ;
}
V_185 -> V_123 . V_107 = V_185 -> V_155 -> V_118 & V_121 ;
if ( ( V_215 & V_185 -> V_123 . V_107 ) != 0 )
V_185 -> V_123 . V_107 = - 1 ;
else if ( ( V_216 & V_185 -> V_123 . V_107 ) != 0 )
V_185 -> V_123 . V_107 = - 1 ;
else if ( ( V_217 & V_185 -> V_123 . V_107 ) != 0 )
V_185 -> V_123 . V_107 = - 1 ;
V_185 -> V_123 . V_218 = V_185 -> V_155 -> V_118 & V_120 ;
V_185 -> V_123 . V_218 >>= F_1 ( V_120 ) ;
V_185 -> V_123 . V_218 = V_185 -> V_123 . V_125 - V_185 -> V_123 . V_218 ;
V_185 -> V_123 . V_218 = V_185 -> V_123 . V_107 ? 0 : V_185 -> V_123 . V_218 ;
return V_185 -> V_123 . V_218 ;
}
static int F_95 ( struct V_150 * V_184 )
__releases( V_184 -> V_136 )
__acquires( V_184 -> V_136 )
{
F_87 ( L_65 , V_184 ) ;
if ( V_184 == NULL )
return - V_65 ;
F_19 ( V_184 -> V_3 , V_184 -> V_4 ) ;
while ( ! F_91 ( & V_184 -> V_153 . V_164 ) ) {
struct V_161 * V_185 = \
F_80 ( V_184 -> V_153 . V_164 . V_199 ,
struct V_161 , V_164 ) ;
F_96 ( & V_185 -> V_164 ) ;
V_185 -> V_123 . V_107 = - V_219 ;
if ( V_185 -> V_123 . V_220 != NULL ) {
F_97 ( V_184 -> V_136 ) ;
V_185 -> V_123 . V_220 ( & V_184 -> V_181 , & V_185 -> V_123 ) ;
F_98 ( V_184 -> V_136 ) ;
}
}
return 0 ;
}
static int F_99 ( struct V_91 * V_90 )
{
struct V_221 * V_181 ;
struct V_24 * V_25 = F_44 ( V_90 , struct V_24 , V_90 ) ;
unsigned long V_33 ;
F_87 ( L_65 , V_90 ) ;
if ( V_90 == NULL )
return - V_65 ;
F_68 ( V_25 -> V_136 , V_33 ) ;
V_25 -> V_90 . V_94 = V_222 ;
V_25 -> V_223 = 0 ;
V_25 -> V_224 = 0 ;
F_69 ( V_25 -> V_136 , V_33 ) ;
F_100 (ep, gadget) {
F_101 ( V_181 ) ;
}
F_101 ( & V_25 -> V_225 . V_181 ) ;
F_101 ( & V_25 -> V_226 . V_181 ) ;
V_25 -> V_103 -> V_227 ( V_90 ) ;
F_100 (ep, gadget) {
F_102 ( V_181 ) ;
}
if ( V_25 -> V_107 != NULL ) {
F_103 ( & V_25 -> V_226 . V_181 , V_25 -> V_107 ) ;
V_25 -> V_107 = NULL ;
}
return 0 ;
}
static void F_104 ( struct V_24 * V_25 )
__releases( V_25 -> V_136 )
__acquires( V_25 -> V_136 )
{
int V_165 ;
F_87 ( L_65 , V_25 ) ;
if ( V_25 == NULL ) {
F_105 ( L_66 ) ;
return;
}
F_58 ( 0xFF , L_67 , 0 ) ;
F_97 ( V_25 -> V_136 ) ;
V_165 = F_99 ( & V_25 -> V_90 ) ;
if ( V_165 )
goto V_134;
V_165 = F_42 () ;
if ( V_165 )
goto V_134;
V_25 -> V_107 = F_106 ( & V_25 -> V_226 . V_181 , V_197 ) ;
if ( V_25 -> V_107 == NULL )
V_165 = - V_191 ;
F_98 ( V_25 -> V_136 ) ;
V_134:
if ( V_165 )
F_105 ( L_68 , V_165 ) ;
}
static void F_107 ( struct V_221 * V_181 , struct V_122 * V_123 )
{
F_87 ( L_64 , V_181 , V_123 ) ;
if ( V_181 == NULL || V_123 == NULL ) {
F_105 ( L_66 ) ;
return;
}
F_76 ( V_123 -> V_79 ) ;
F_103 ( V_181 , V_123 ) ;
}
static int F_108 ( struct V_24 * V_25 ,
struct V_126 * V_228 )
__releases( V_184 -> V_136 )
__acquires( V_184 -> V_136 )
{
struct V_150 * V_184 = & V_25 -> V_226 ;
struct V_122 * V_123 = NULL ;
T_8 V_229 = V_197 ;
int V_4 , V_3 , V_165 ;
F_87 ( L_64 , V_184 , V_228 ) ;
if ( V_184 == NULL || V_228 == NULL )
return - V_65 ;
F_97 ( V_184 -> V_136 ) ;
V_123 = F_106 ( & V_184 -> V_181 , V_229 ) ;
F_98 ( V_184 -> V_136 ) ;
if ( V_123 == NULL )
return - V_191 ;
V_123 -> V_220 = F_107 ;
V_123 -> V_125 = 2 ;
V_123 -> V_79 = F_109 ( V_123 -> V_125 , V_229 ) ;
if ( V_123 -> V_79 == NULL ) {
V_165 = - V_191 ;
goto V_230;
}
if ( ( V_228 -> V_127 & V_231 ) == V_232 ) {
* ( ( T_5 * ) V_123 -> V_79 ) = V_233 -> V_223 << 1 ;
V_165 = 0 ;
} else if ( ( V_228 -> V_127 & V_231 ) \
== V_234 ) {
V_4 = ( F_61 ( V_228 -> V_130 ) & V_183 ) ?
V_182 : V_61 ;
V_3 = F_61 ( V_228 -> V_130 ) & V_235 ;
* ( ( T_5 * ) V_123 -> V_79 ) = F_24 ( V_3 , V_4 ) ;
}
F_97 ( V_184 -> V_136 ) ;
V_165 = F_110 ( & V_184 -> V_181 , V_123 , V_229 ) ;
F_98 ( V_184 -> V_136 ) ;
if ( V_165 )
goto V_236;
return 0 ;
V_236:
F_76 ( V_123 -> V_79 ) ;
V_230:
F_97 ( V_184 -> V_136 ) ;
F_103 ( & V_184 -> V_181 , V_123 ) ;
F_98 ( V_184 -> V_136 ) ;
return V_165 ;
}
static void
F_111 ( struct V_221 * V_181 , struct V_122 * V_123 )
{
struct V_24 * V_25 = V_123 -> V_237 ;
unsigned long V_33 ;
F_87 ( L_64 , V_181 , V_123 ) ;
F_68 ( V_25 -> V_136 , V_33 ) ;
if ( V_25 -> V_238 )
F_32 ( V_25 -> V_238 ) ;
F_69 ( V_25 -> V_136 , V_33 ) ;
}
static int F_112 ( struct V_24 * V_25 )
__releases( V_184 -> V_136 )
__acquires( V_184 -> V_136 )
{
int V_165 ;
struct V_150 * V_184 ;
F_87 ( L_65 , V_25 ) ;
V_184 = ( V_25 -> V_239 == V_182 ) ? & V_25 -> V_225 : & V_25 -> V_226 ;
V_25 -> V_107 -> V_237 = V_25 ;
V_25 -> V_107 -> V_220 = F_111 ;
F_97 ( V_184 -> V_136 ) ;
V_165 = F_110 ( & V_184 -> V_181 , V_25 -> V_107 , V_197 ) ;
F_98 ( V_184 -> V_136 ) ;
return V_165 ;
}
static int F_113 ( struct V_150 * V_184 )
__releases( V_184 -> V_136 )
__acquires( V_184 -> V_136 )
{
struct V_161 * V_185 , * V_240 ;
struct V_150 * V_241 = V_184 ;
int V_242 ( V_165 ) ;
F_87 ( L_65 , V_184 ) ;
if ( F_91 ( & V_184 -> V_153 . V_164 ) )
return - V_65 ;
F_114 (mReq, mReqTemp, &mEp->qh.queue,
queue) {
V_165 = F_93 ( V_184 , V_185 ) ;
if ( V_165 < 0 )
break;
F_96 ( & V_185 -> V_164 ) ;
F_57 ( F_85 ( V_184 ) , V_185 -> V_155 -> V_118 , V_165 ) ;
if ( V_185 -> V_123 . V_220 != NULL ) {
F_97 ( V_184 -> V_136 ) ;
if ( ( V_184 -> type == V_213 ) &&
V_185 -> V_123 . V_125 )
V_241 = & V_233 -> V_226 ;
V_185 -> V_123 . V_220 ( & V_241 -> V_181 , & V_185 -> V_123 ) ;
F_98 ( V_184 -> V_136 ) ;
}
}
if ( V_165 == - V_214 )
V_165 = 0 ;
if ( V_165 < 0 )
F_58 ( F_85 ( V_184 ) , L_20 , V_165 ) ;
return V_165 ;
}
static void F_115 ( struct V_24 * V_25 )
__releases( V_25 -> V_136 )
__acquires( V_25 -> V_136 )
{
unsigned V_80 ;
T_3 V_243 = 0 ;
F_87 ( L_65 , V_25 ) ;
if ( V_25 == NULL ) {
F_105 ( L_66 ) ;
return;
}
for ( V_80 = 0 ; V_80 < V_6 ; V_80 ++ ) {
struct V_150 * V_184 = & V_25 -> V_150 [ V_80 ] ;
int type , V_3 , V_4 , F_105 = - V_65 ;
struct V_126 V_123 ;
if ( V_184 -> V_244 == NULL )
continue;
if ( F_37 ( V_80 ) ) {
F_105 = F_113 ( V_184 ) ;
if ( V_184 -> type == V_213 ) {
if ( F_105 > 0 )
F_105 = F_112 ( V_25 ) ;
if ( F_105 < 0 ) {
F_58 ( F_85 ( V_184 ) ,
L_69 , F_105 ) ;
F_97 ( V_25 -> V_136 ) ;
if ( F_116 ( & V_184 -> V_181 ) )
F_105 ( L_70 ) ;
F_98 ( V_25 -> V_136 ) ;
}
}
}
if ( V_184 -> type != V_213 ||
! F_25 ( V_80 ) )
continue;
if ( V_80 != 0 ) {
F_117 ( L_71 ) ;
continue;
}
F_95 ( & V_25 -> V_225 ) ;
F_95 ( & V_25 -> V_226 ) ;
do {
F_40 () ;
memcpy ( & V_123 , & V_184 -> V_153 . V_155 -> V_228 , sizeof( V_123 ) ) ;
} while ( ! F_39 () );
type = V_123 . V_127 ;
V_25 -> V_239 = ( type & V_245 ) ? V_182 : V_61 ;
F_60 ( F_85 ( V_184 ) , & V_123 ) ;
switch ( V_123 . V_128 ) {
case V_246 :
if ( type == ( V_247 | V_234 ) &&
F_61 ( V_123 . V_129 ) ==
V_248 ) {
if ( V_123 . V_131 != 0 )
break;
V_3 = F_61 ( V_123 . V_130 ) ;
V_4 = V_3 & V_183 ;
V_3 &= V_235 ;
if ( V_4 )
V_3 += V_6 / 2 ;
if ( ! V_25 -> V_150 [ V_3 ] . V_249 ) {
F_97 ( V_25 -> V_136 ) ;
F_105 = F_118 (
& V_25 -> V_150 [ V_3 ] . V_181 ) ;
F_98 ( V_25 -> V_136 ) ;
if ( F_105 )
break;
}
F_105 = F_112 ( V_25 ) ;
} else if ( type == ( V_247 | V_232 ) &&
F_61 ( V_123 . V_129 ) ==
V_250 ) {
if ( V_123 . V_131 != 0 )
break;
V_25 -> V_223 = 0 ;
F_105 = F_112 ( V_25 ) ;
} else {
goto V_251;
}
break;
case V_252 :
if ( type != ( V_245 | V_232 ) &&
type != ( V_245 | V_234 ) &&
type != ( V_245 | V_253 ) )
goto V_251;
if ( F_61 ( V_123 . V_131 ) != 2 ||
F_61 ( V_123 . V_129 ) != 0 )
break;
F_105 = F_108 ( V_25 , & V_123 ) ;
break;
case V_254 :
if ( type != ( V_247 | V_232 ) )
goto V_251;
if ( F_61 ( V_123 . V_131 ) != 0 ||
F_61 ( V_123 . V_130 ) != 0 )
break;
F_105 = F_41 ( ( T_3 ) F_61 ( V_123 . V_129 ) ) ;
if ( F_105 )
break;
F_105 = F_112 ( V_25 ) ;
break;
case V_255 :
if ( type == ( V_247 | V_234 ) &&
F_61 ( V_123 . V_129 ) ==
V_248 ) {
if ( V_123 . V_131 != 0 )
break;
V_3 = F_61 ( V_123 . V_130 ) ;
V_4 = V_3 & V_183 ;
V_3 &= V_235 ;
if ( V_4 )
V_3 += V_6 / 2 ;
F_97 ( V_25 -> V_136 ) ;
F_105 = F_116 ( & V_25 -> V_150 [ V_3 ] . V_181 ) ;
F_98 ( V_25 -> V_136 ) ;
if ( ! F_105 )
F_112 ( V_25 ) ;
} else if ( type == ( V_247 | V_232 ) ) {
if ( V_123 . V_131 != 0 )
break;
switch ( F_61 ( V_123 . V_129 ) ) {
case V_250 :
V_25 -> V_223 = 1 ;
F_105 = F_112 ( V_25 ) ;
break;
case V_256 :
V_243 = F_61 ( V_123 . V_130 ) >> 8 ;
switch ( V_243 ) {
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
V_25 -> V_238 = V_243 ;
F_105 = F_112 (
V_25 ) ;
break;
default:
break;
}
default:
goto V_251;
}
} else {
goto V_251;
}
break;
default:
V_251:
if ( V_123 . V_131 == 0 )
V_25 -> V_239 = V_182 ;
F_97 ( V_25 -> V_136 ) ;
F_105 = V_25 -> V_103 -> V_228 ( & V_25 -> V_90 , & V_123 ) ;
F_98 ( V_25 -> V_136 ) ;
break;
}
if ( F_105 < 0 ) {
F_58 ( F_85 ( V_184 ) , L_69 , F_105 ) ;
F_97 ( V_25 -> V_136 ) ;
if ( F_116 ( & V_184 -> V_181 ) )
F_105 ( L_70 ) ;
F_98 ( V_25 -> V_136 ) ;
}
}
}
static int F_119 ( struct V_221 * V_181 ,
const struct V_262 * V_244 )
{
struct V_150 * V_184 = F_44 ( V_181 , struct V_150 , V_181 ) ;
int V_165 = 0 ;
unsigned long V_33 ;
F_87 ( L_64 , V_181 , V_244 ) ;
if ( V_181 == NULL || V_244 == NULL )
return - V_65 ;
F_68 ( V_184 -> V_136 , V_33 ) ;
V_184 -> V_244 = V_244 ;
if ( ! F_91 ( & V_184 -> V_153 . V_164 ) )
F_117 ( L_72 ) ;
V_184 -> V_4 = F_120 ( V_244 ) ? V_182 : V_61 ;
V_184 -> V_3 = F_121 ( V_244 ) ;
V_184 -> type = F_122 ( V_244 ) ;
V_184 -> V_181 . V_194 = F_123 ( V_244 ) ;
F_58 ( F_85 ( V_184 ) , L_73 , 0 ) ;
V_184 -> V_153 . V_155 -> V_11 = 0 ;
if ( V_184 -> type == V_213 )
V_184 -> V_153 . V_155 -> V_11 |= V_263 ;
else if ( V_184 -> type == V_264 )
V_184 -> V_153 . V_155 -> V_11 &= ~ V_265 ;
else
V_184 -> V_153 . V_155 -> V_11 &= ~ V_212 ;
V_184 -> V_153 . V_155 -> V_11 |=
( V_184 -> V_181 . V_194 << F_1 ( V_266 ) ) & V_266 ;
V_184 -> V_153 . V_155 -> V_211 . V_199 |= V_200 ;
if ( V_184 -> V_3 )
V_165 |= F_23 ( V_184 -> V_3 , V_184 -> V_4 , V_184 -> type ) ;
F_69 ( V_184 -> V_136 , V_33 ) ;
return V_165 ;
}
static int F_124 ( struct V_221 * V_181 )
{
struct V_150 * V_184 = F_44 ( V_181 , struct V_150 , V_181 ) ;
int V_267 , V_165 = 0 ;
unsigned long V_33 ;
F_87 ( L_65 , V_181 ) ;
if ( V_181 == NULL )
return - V_65 ;
else if ( V_184 -> V_244 == NULL )
return - V_214 ;
F_68 ( V_184 -> V_136 , V_33 ) ;
V_267 = V_184 -> V_4 ;
do {
F_58 ( F_85 ( V_184 ) , L_74 , 0 ) ;
V_165 |= F_95 ( V_184 ) ;
V_165 |= F_22 ( V_184 -> V_3 , V_184 -> V_4 ) ;
if ( V_184 -> type == V_213 )
V_184 -> V_4 = ( V_184 -> V_4 == V_182 ) ? V_61 : V_182 ;
} while ( V_184 -> V_4 != V_267 );
V_184 -> V_244 = NULL ;
V_184 -> V_181 . V_244 = NULL ;
F_69 ( V_184 -> V_136 , V_33 ) ;
return V_165 ;
}
static struct V_122 * F_125 ( struct V_221 * V_181 , T_8 V_229 )
{
struct V_150 * V_184 = F_44 ( V_181 , struct V_150 , V_181 ) ;
struct V_161 * V_185 = NULL ;
F_87 ( L_75 , V_181 , V_229 ) ;
if ( V_181 == NULL ) {
F_105 ( L_66 ) ;
return NULL ;
}
V_185 = F_109 ( sizeof( struct V_161 ) , V_229 ) ;
if ( V_185 != NULL ) {
F_126 ( & V_185 -> V_164 ) ;
V_185 -> V_123 . V_41 = V_188 ;
V_185 -> V_155 = F_89 ( V_184 -> V_196 , V_229 ,
& V_185 -> V_41 ) ;
if ( V_185 -> V_155 == NULL ) {
F_76 ( V_185 ) ;
V_185 = NULL ;
}
}
F_58 ( F_85 ( V_184 ) , L_76 , V_185 == NULL ) ;
return ( V_185 == NULL ) ? NULL : & V_185 -> V_123 ;
}
static void F_127 ( struct V_221 * V_181 , struct V_122 * V_123 )
{
struct V_150 * V_184 = F_44 ( V_181 , struct V_150 , V_181 ) ;
struct V_161 * V_185 = F_44 ( V_123 , struct V_161 , V_123 ) ;
unsigned long V_33 ;
F_87 ( L_64 , V_181 , V_123 ) ;
if ( V_181 == NULL || V_123 == NULL ) {
F_105 ( L_66 ) ;
return;
} else if ( ! F_91 ( & V_185 -> V_164 ) ) {
F_105 ( L_77 ) ;
return;
}
F_68 ( V_184 -> V_136 , V_33 ) ;
if ( V_185 -> V_155 )
F_94 ( V_184 -> V_196 , V_185 -> V_155 , V_185 -> V_41 ) ;
F_76 ( V_185 ) ;
F_58 ( F_85 ( V_184 ) , L_78 , 0 ) ;
F_69 ( V_184 -> V_136 , V_33 ) ;
}
static int F_128 ( struct V_221 * V_181 , struct V_122 * V_123 ,
T_8 T_7 V_229 )
{
struct V_150 * V_184 = F_44 ( V_181 , struct V_150 , V_181 ) ;
struct V_161 * V_185 = F_44 ( V_123 , struct V_161 , V_123 ) ;
int V_165 = 0 ;
unsigned long V_33 ;
F_87 ( L_79 , V_181 , V_123 , V_229 ) ;
if ( V_181 == NULL || V_123 == NULL || V_184 -> V_244 == NULL )
return - V_65 ;
F_68 ( V_184 -> V_136 , V_33 ) ;
if ( V_184 -> type == V_213 ) {
if ( V_123 -> V_125 )
V_184 = ( V_233 -> V_239 == V_61 ) ?
& V_233 -> V_225 : & V_233 -> V_226 ;
if ( ! F_91 ( & V_184 -> V_153 . V_164 ) ) {
F_95 ( V_184 ) ;
V_165 = - V_268 ;
F_117 ( L_80 , F_85 ( V_184 ) ) ;
}
}
if ( ! F_91 ( & V_185 -> V_164 ) ) {
V_165 = - V_214 ;
F_105 ( L_81 ) ;
goto V_134;
}
if ( V_123 -> V_125 > ( 4 * V_204 ) ) {
V_123 -> V_125 = ( 4 * V_204 ) ;
V_165 = - V_269 ;
F_117 ( L_82 ) ;
}
F_59 ( F_85 ( V_184 ) , V_123 , V_165 ) ;
V_185 -> V_123 . V_107 = - V_270 ;
V_185 -> V_123 . V_218 = 0 ;
V_165 = F_86 ( V_184 , V_185 ) ;
if ( V_165 == - V_187 ) {
F_58 ( F_85 ( V_184 ) , L_22 , V_165 ) ;
V_165 = 0 ;
}
if ( ! V_165 )
F_129 ( & V_185 -> V_164 , & V_184 -> V_153 . V_164 ) ;
V_134:
F_69 ( V_184 -> V_136 , V_33 ) ;
return V_165 ;
}
static int F_130 ( struct V_221 * V_181 , struct V_122 * V_123 )
{
struct V_150 * V_184 = F_44 ( V_181 , struct V_150 , V_181 ) ;
struct V_161 * V_185 = F_44 ( V_123 , struct V_161 , V_123 ) ;
unsigned long V_33 ;
F_87 ( L_64 , V_181 , V_123 ) ;
if ( V_181 == NULL || V_123 == NULL || V_185 -> V_123 . V_107 != - V_187 ||
V_184 -> V_244 == NULL || F_91 ( & V_185 -> V_164 ) ||
F_91 ( & V_184 -> V_153 . V_164 ) )
return - V_65 ;
F_68 ( V_184 -> V_136 , V_33 ) ;
F_58 ( F_85 ( V_184 ) , L_83 , 0 ) ;
F_19 ( V_184 -> V_3 , V_184 -> V_4 ) ;
F_96 ( & V_185 -> V_164 ) ;
if ( V_185 -> V_192 ) {
F_90 ( V_184 -> V_86 , V_185 -> V_123 . V_41 , V_185 -> V_123 . V_125 ,
V_184 -> V_4 ? V_189 : V_190 ) ;
V_185 -> V_123 . V_41 = V_188 ;
V_185 -> V_192 = 0 ;
}
V_123 -> V_107 = - V_271 ;
if ( V_185 -> V_123 . V_220 != NULL ) {
F_97 ( V_184 -> V_136 ) ;
V_185 -> V_123 . V_220 ( & V_184 -> V_181 , & V_185 -> V_123 ) ;
F_98 ( V_184 -> V_136 ) ;
}
F_69 ( V_184 -> V_136 , V_33 ) ;
return 0 ;
}
static int F_131 ( struct V_221 * V_181 , int V_64 )
{
struct V_150 * V_184 = F_44 ( V_181 , struct V_150 , V_181 ) ;
int V_267 , V_165 = 0 ;
unsigned long V_33 ;
F_87 ( L_75 , V_181 , V_64 ) ;
if ( V_181 == NULL || V_184 -> V_244 == NULL )
return - V_65 ;
F_68 ( V_184 -> V_136 , V_33 ) ;
#ifndef F_132
if ( V_64 && V_184 -> type == V_272 && V_184 -> V_4 == V_182 &&
! F_91 ( & V_184 -> V_153 . V_164 ) ) {
F_69 ( V_184 -> V_136 , V_33 ) ;
return - V_62 ;
}
#endif
V_267 = V_184 -> V_4 ;
do {
F_58 ( F_85 ( V_184 ) , L_84 , V_64 ) ;
V_165 |= F_27 ( V_184 -> V_3 , V_184 -> V_4 , V_64 ) ;
if ( ! V_64 )
V_184 -> V_249 = 0 ;
if ( V_184 -> type == V_213 )
V_184 -> V_4 = ( V_184 -> V_4 == V_182 ) ? V_61 : V_182 ;
} while ( V_184 -> V_4 != V_267 );
F_69 ( V_184 -> V_136 , V_33 ) ;
return V_165 ;
}
static int F_133 ( struct V_221 * V_181 )
{
struct V_150 * V_184 = F_44 ( V_181 , struct V_150 , V_181 ) ;
unsigned long V_33 ;
F_87 ( L_65 , V_181 ) ;
if ( V_181 == NULL || V_184 -> V_244 == NULL )
return - V_65 ;
F_68 ( V_184 -> V_136 , V_33 ) ;
F_58 ( F_85 ( V_184 ) , L_85 , 0 ) ;
V_184 -> V_249 = 1 ;
F_69 ( V_184 -> V_136 , V_33 ) ;
return F_116 ( V_181 ) ;
}
static void F_134 ( struct V_221 * V_181 )
{
struct V_150 * V_184 = F_44 ( V_181 , struct V_150 , V_181 ) ;
unsigned long V_33 ;
F_87 ( L_65 , V_181 ) ;
if ( V_181 == NULL ) {
F_105 ( L_86 , F_85 ( V_184 ) ) ;
return;
}
F_68 ( V_184 -> V_136 , V_33 ) ;
F_58 ( F_85 ( V_184 ) , L_87 , 0 ) ;
F_19 ( V_184 -> V_3 , V_184 -> V_4 ) ;
F_69 ( V_184 -> V_136 , V_33 ) ;
}
static int F_135 ( struct V_91 * V_273 , int V_274 )
{
struct V_24 * V_25 = F_44 ( V_273 , struct V_24 , V_90 ) ;
unsigned long V_33 ;
int V_275 = 0 ;
if ( ! ( V_25 -> V_30 -> V_33 & V_276 ) )
return - V_277 ;
F_68 ( V_25 -> V_136 , V_33 ) ;
V_25 -> V_278 = V_274 ;
if ( V_25 -> V_103 )
V_275 = 1 ;
F_69 ( V_25 -> V_136 , V_33 ) ;
if ( V_275 ) {
if ( V_274 ) {
F_136 ( & V_273 -> V_87 ) ;
F_15 ( V_25 ) ;
F_18 ( V_25 -> V_225 . V_153 . V_41 ) ;
} else {
F_18 ( 0 ) ;
if ( V_25 -> V_30 -> V_31 )
V_25 -> V_30 -> V_31 ( V_25 ,
V_279 ) ;
F_99 ( & V_25 -> V_90 ) ;
F_137 ( & V_273 -> V_87 ) ;
}
}
return 0 ;
}
static int F_138 ( struct V_91 * V_273 )
{
struct V_24 * V_25 = F_44 ( V_273 , struct V_24 , V_90 ) ;
unsigned long V_33 ;
int V_186 = 0 ;
F_87 () ;
F_68 ( V_25 -> V_136 , V_33 ) ;
if ( ! V_25 -> V_223 ) {
V_186 = - V_277 ;
F_87 ( L_88 ) ;
goto V_280;
}
if ( ! F_9 ( V_74 , V_281 ) ) {
V_186 = - V_65 ;
F_87 ( L_89 ) ;
goto V_280;
}
F_10 ( V_74 , V_282 , V_282 ) ;
V_280:
F_69 ( V_25 -> V_136 , V_33 ) ;
return V_186 ;
}
static int F_139 ( struct V_91 * V_273 , unsigned V_283 )
{
struct V_24 * V_25 = F_44 ( V_273 , struct V_24 , V_90 ) ;
if ( V_25 -> V_284 )
return F_140 ( V_25 -> V_284 , V_283 ) ;
return - V_285 ;
}
static int F_141 ( struct V_102 * V_103 ,
int (* F_142)( struct V_91 * ) )
{
struct V_24 * V_25 = V_233 ;
unsigned long V_33 ;
int V_80 , V_132 ;
int V_165 = - V_191 ;
F_87 ( L_65 , V_103 ) ;
if ( V_103 == NULL ||
F_142 == NULL ||
V_103 -> V_228 == NULL ||
V_103 -> V_227 == NULL )
return - V_65 ;
else if ( V_25 == NULL )
return - V_23 ;
else if ( V_25 -> V_103 != NULL )
return - V_214 ;
V_25 -> V_286 = F_143 ( L_90 , & V_25 -> V_90 . V_87 ,
sizeof( struct V_154 ) ,
64 , V_204 ) ;
if ( V_25 -> V_286 == NULL )
return - V_191 ;
V_25 -> V_196 = F_143 ( L_91 , & V_25 -> V_90 . V_87 ,
sizeof( struct V_163 ) ,
64 , V_204 ) ;
if ( V_25 -> V_196 == NULL ) {
F_144 ( V_25 -> V_286 ) ;
V_25 -> V_286 = NULL ;
return - V_191 ;
}
F_68 ( V_25 -> V_136 , V_33 ) ;
F_145 ( L_92 , V_6 ) ;
V_25 -> V_90 . V_87 . V_103 = NULL ;
V_165 = 0 ;
for ( V_80 = 0 ; V_80 < V_6 / 2 ; V_80 ++ ) {
for ( V_132 = V_61 ; V_132 <= V_182 ; V_132 ++ ) {
int V_157 = V_80 + V_132 * V_6 / 2 ;
struct V_150 * V_184 = & V_25 -> V_150 [ V_157 ] ;
F_47 ( V_184 -> V_101 , sizeof( V_184 -> V_101 ) , L_93 , V_80 ,
( V_132 == V_182 ) ? L_94 : L_95 ) ;
V_184 -> V_136 = V_25 -> V_136 ;
V_184 -> V_86 = & V_25 -> V_90 . V_87 ;
V_184 -> V_196 = V_25 -> V_196 ;
V_184 -> V_181 . V_101 = V_184 -> V_101 ;
V_184 -> V_181 . V_287 = & V_288 ;
V_184 -> V_181 . V_194 = V_289 ;
F_126 ( & V_184 -> V_153 . V_164 ) ;
F_69 ( V_25 -> V_136 , V_33 ) ;
V_184 -> V_153 . V_155 = F_89 ( V_25 -> V_286 , V_159 ,
& V_184 -> V_153 . V_41 ) ;
F_68 ( V_25 -> V_136 , V_33 ) ;
if ( V_184 -> V_153 . V_155 == NULL )
V_165 = - V_191 ;
else
memset ( V_184 -> V_153 . V_155 , 0 , sizeof( * V_184 -> V_153 . V_155 ) ) ;
if ( V_80 == 0 )
continue;
F_129 ( & V_184 -> V_181 . V_290 , & V_25 -> V_90 . V_290 ) ;
}
}
if ( V_165 )
goto V_134;
F_69 ( V_25 -> V_136 , V_33 ) ;
V_25 -> V_225 . V_181 . V_244 = & V_291 ;
V_165 = F_146 ( & V_25 -> V_225 . V_181 ) ;
if ( V_165 )
return V_165 ;
V_25 -> V_226 . V_181 . V_244 = & V_292 ;
V_165 = F_146 ( & V_25 -> V_226 . V_181 ) ;
if ( V_165 )
return V_165 ;
F_68 ( V_25 -> V_136 , V_33 ) ;
V_25 -> V_90 . V_293 = & V_25 -> V_226 . V_181 ;
V_103 -> V_103 . V_294 = NULL ;
V_25 -> V_90 . V_87 . V_103 = & V_103 -> V_103 ;
F_69 ( V_25 -> V_136 , V_33 ) ;
V_165 = F_142 ( & V_25 -> V_90 ) ;
F_68 ( V_25 -> V_136 , V_33 ) ;
if ( V_165 ) {
V_25 -> V_90 . V_87 . V_103 = NULL ;
goto V_134;
}
V_25 -> V_103 = V_103 ;
F_136 ( & V_25 -> V_90 . V_87 ) ;
if ( V_25 -> V_30 -> V_33 & V_276 ) {
if ( V_25 -> V_278 ) {
if ( V_25 -> V_30 -> V_33 & V_295 )
F_15 ( V_25 ) ;
} else {
F_137 ( & V_25 -> V_90 . V_87 ) ;
goto V_134;
}
}
V_165 = F_18 ( V_25 -> V_225 . V_153 . V_41 ) ;
if ( V_165 )
F_137 ( & V_25 -> V_90 . V_87 ) ;
V_134:
F_69 ( V_25 -> V_136 , V_33 ) ;
return V_165 ;
}
static int F_147 ( struct V_102 * V_103 )
{
struct V_24 * V_25 = V_233 ;
unsigned long V_80 , V_33 ;
F_87 ( L_65 , V_103 ) ;
if ( V_103 == NULL ||
V_103 -> V_296 == NULL ||
V_103 -> V_228 == NULL ||
V_103 -> V_227 == NULL ||
V_103 != V_25 -> V_103 )
return - V_65 ;
F_68 ( V_25 -> V_136 , V_33 ) ;
if ( ! ( V_25 -> V_30 -> V_33 & V_276 ) ||
V_25 -> V_278 ) {
F_18 ( 0 ) ;
if ( V_25 -> V_30 -> V_31 )
V_25 -> V_30 -> V_31 ( V_25 ,
V_279 ) ;
F_69 ( V_25 -> V_136 , V_33 ) ;
F_99 ( & V_25 -> V_90 ) ;
F_68 ( V_25 -> V_136 , V_33 ) ;
F_148 ( & V_25 -> V_90 . V_87 ) ;
}
F_69 ( V_25 -> V_136 , V_33 ) ;
V_103 -> V_296 ( & V_25 -> V_90 ) ;
F_68 ( V_25 -> V_136 , V_33 ) ;
V_25 -> V_90 . V_87 . V_103 = NULL ;
for ( V_80 = 0 ; V_80 < V_6 ; V_80 ++ ) {
struct V_150 * V_184 = & V_25 -> V_150 [ V_80 ] ;
if ( ! F_91 ( & V_184 -> V_181 . V_290 ) )
F_96 ( & V_184 -> V_181 . V_290 ) ;
if ( V_184 -> V_153 . V_155 != NULL )
F_94 ( V_25 -> V_286 , V_184 -> V_153 . V_155 , V_184 -> V_153 . V_41 ) ;
}
V_25 -> V_90 . V_293 = NULL ;
V_25 -> V_103 = NULL ;
F_69 ( V_25 -> V_136 , V_33 ) ;
if ( V_25 -> V_196 != NULL ) {
F_144 ( V_25 -> V_196 ) ;
V_25 -> V_196 = NULL ;
}
if ( V_25 -> V_286 != NULL ) {
F_144 ( V_25 -> V_286 ) ;
V_25 -> V_286 = NULL ;
}
return 0 ;
}
static T_9 F_149 ( void )
{
struct V_24 * V_25 = V_233 ;
T_9 V_165 ;
T_1 V_135 ;
F_87 () ;
if ( V_25 == NULL ) {
F_105 ( L_96 ) ;
return V_297 ;
}
F_98 ( V_25 -> V_136 ) ;
if ( V_25 -> V_30 -> V_33 & V_295 ) {
if ( F_9 ( V_35 , V_37 ) !=
V_39 ) {
F_97 ( V_25 -> V_136 ) ;
return V_298 ;
}
}
V_135 = F_38 () ;
if ( V_135 ) {
V_137 . V_145 . V_79 [ V_137 . V_145 . V_105 ++ ] = V_135 ;
V_137 . V_145 . V_105 &= V_147 ;
V_137 . V_145 . V_146 ++ ;
if ( V_47 & V_135 ) {
V_137 . V_142 ++ ;
F_104 ( V_25 ) ;
}
if ( V_46 & V_135 ) {
V_137 . V_141 ++ ;
V_25 -> V_90 . V_94 = F_30 () ?
V_299 : V_300 ;
if ( V_25 -> V_224 && V_25 -> V_103 -> V_301 ) {
F_97 ( V_25 -> V_136 ) ;
V_25 -> V_103 -> V_301 ( & V_25 -> V_90 ) ;
F_98 ( V_25 -> V_136 ) ;
V_25 -> V_224 = 0 ;
}
}
if ( V_45 & V_135 )
V_137 . V_140 ++ ;
if ( V_44 & V_135 ) {
V_137 . V_139 ++ ;
F_115 ( V_25 ) ;
}
if ( V_48 & V_135 ) {
if ( V_25 -> V_90 . V_94 != V_222 &&
V_25 -> V_103 -> V_302 ) {
V_25 -> V_224 = 1 ;
F_97 ( V_25 -> V_136 ) ;
V_25 -> V_103 -> V_302 ( & V_25 -> V_90 ) ;
F_98 ( V_25 -> V_136 ) ;
}
V_137 . V_143 ++ ;
}
V_165 = V_297 ;
} else {
V_137 . V_144 ++ ;
V_165 = V_298 ;
}
F_97 ( V_25 -> V_136 ) ;
return V_165 ;
}
static void F_150 ( struct V_86 * V_87 )
{
F_87 ( L_65 , V_87 ) ;
if ( V_87 == NULL )
F_105 ( L_66 ) ;
}
static int F_151 ( struct V_303 * V_103 , struct V_86 * V_87 ,
void T_2 * V_304 )
{
struct V_24 * V_25 ;
int V_165 = 0 ;
F_87 ( L_97 , V_87 , V_304 , V_103 -> V_101 ) ;
if ( V_87 == NULL || V_304 == NULL || V_103 == NULL ||
V_103 -> V_101 == NULL )
return - V_65 ;
V_25 = F_109 ( sizeof( struct V_24 ) , V_159 ) ;
if ( V_25 == NULL )
return - V_191 ;
V_25 -> V_136 = & V_305 ;
V_25 -> V_304 = V_304 ;
V_25 -> V_30 = V_103 ;
V_25 -> V_90 . V_287 = & V_306 ;
V_25 -> V_90 . V_94 = V_222 ;
V_25 -> V_90 . V_95 = V_299 ;
V_25 -> V_90 . V_96 = 0 ;
V_25 -> V_90 . V_101 = V_103 -> V_101 ;
F_126 ( & V_25 -> V_90 . V_290 ) ;
V_25 -> V_90 . V_293 = NULL ;
F_152 ( & V_25 -> V_90 . V_87 , L_98 ) ;
V_25 -> V_90 . V_87 . V_307 = V_87 -> V_307 ;
V_25 -> V_90 . V_87 . V_308 = V_87 -> V_308 ;
V_25 -> V_90 . V_87 . V_309 = V_87 ;
V_25 -> V_90 . V_87 . V_310 = F_150 ;
V_165 = F_13 ( V_304 ) ;
if ( V_165 < 0 )
goto V_311;
V_25 -> V_284 = F_153 () ;
if ( V_25 -> V_30 -> V_33 & V_312 ) {
if ( V_25 -> V_284 == NULL ) {
V_165 = - V_23 ;
goto V_311;
}
}
if ( ! ( V_25 -> V_30 -> V_33 & V_295 ) ) {
V_165 = F_15 ( V_25 ) ;
if ( V_165 )
goto V_313;
}
V_165 = F_154 ( & V_25 -> V_90 . V_87 ) ;
if ( V_165 ) {
F_155 ( & V_25 -> V_90 . V_87 ) ;
goto V_313;
}
#ifdef F_156
V_165 = F_81 ( & V_25 -> V_90 . V_87 ) ;
#endif
if ( V_165 )
goto V_314;
if ( V_25 -> V_284 ) {
V_165 = F_157 ( V_25 -> V_284 -> V_315 ,
& V_25 -> V_90 ) ;
if ( V_165 )
goto V_316;
}
V_165 = F_158 ( V_87 , & V_25 -> V_90 ) ;
if ( V_165 )
goto V_317;
F_159 ( & V_25 -> V_90 . V_87 ) ;
F_160 ( & V_25 -> V_90 . V_87 ) ;
V_233 = V_25 ;
return V_165 ;
V_317:
if ( V_25 -> V_284 ) {
F_157 ( V_25 -> V_284 -> V_315 , & V_25 -> V_90 ) ;
F_161 ( V_25 -> V_284 ) ;
}
F_105 ( L_99 , V_165 ) ;
V_316:
#ifdef F_156
F_84 ( & V_25 -> V_90 . V_87 ) ;
#endif
V_314:
F_162 ( & V_25 -> V_90 . V_87 ) ;
V_313:
if ( V_25 -> V_284 )
F_161 ( V_25 -> V_284 ) ;
V_311:
F_76 ( V_25 ) ;
V_233 = NULL ;
return V_165 ;
}
static void F_163 ( void )
{
struct V_24 * V_25 = V_233 ;
if ( V_25 == NULL ) {
F_105 ( L_66 ) ;
return;
}
F_164 ( & V_25 -> V_90 ) ;
if ( V_25 -> V_284 ) {
F_157 ( V_25 -> V_284 -> V_315 , & V_25 -> V_90 ) ;
F_161 ( V_25 -> V_284 ) ;
}
#ifdef F_156
F_84 ( & V_25 -> V_90 . V_87 ) ;
#endif
F_162 ( & V_25 -> V_90 . V_87 ) ;
F_76 ( V_25 ) ;
V_233 = NULL ;
}
