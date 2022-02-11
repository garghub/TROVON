static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( ( V_3 ) V_1 * ( V_3 ) V_2 ) >> V_4 ;
}
static inline T_1 F_2 ( T_2 V_1 , T_2 V_2 )
{
return F_3 ( ( V_3 ) V_1 << V_4 , V_2 ) ;
}
static inline int F_4 ( T_1 V_1 )
{
int V_5 , V_6 ;
V_6 = F_5 ( V_1 ) ;
V_5 = ( 1 << V_4 ) - 1 ;
if ( V_1 & V_5 )
V_6 += 1 ;
return V_6 ;
}
static inline T_1 F_6 ( int V_7 )
{
return F_2 ( V_7 , 100 ) ;
}
static inline T_3 F_7 ( T_3 V_1 , T_3 V_2 )
{
return ( V_1 * V_2 ) >> V_8 ;
}
static inline T_3 F_8 ( T_3 V_1 , T_3 V_2 )
{
return F_9 ( V_1 << V_8 , V_2 ) ;
}
static inline T_1 F_10 ( int V_7 )
{
return F_8 ( V_7 , 100 ) ;
}
static bool F_11 ( void )
{
if ( V_9 . V_10 == V_11 ||
V_9 . V_10 == V_12 )
return true ;
return V_13 ;
}
static void F_12 ( struct V_14 * V_15 )
{
F_13 () ;
}
static void F_14 ( int V_16 )
{
struct V_17 V_18 ;
static T_4 V_19 = 0 , V_20 = V_21 ;
int V_6 ;
V_6 = F_15 ( V_16 , & V_18 ) ;
if ( V_6 )
return;
F_16 ( V_18 . V_22 , V_16 ) ;
if ( V_19 <= V_20 ) {
if ( V_18 . V_22 > V_19 )
V_19 = V_18 . V_22 ;
if ( V_18 . V_22 < V_20 )
V_20 = V_18 . V_22 ;
if ( V_19 > V_20 ) {
F_17 ( & V_23 ) ;
}
}
}
static void F_14 ( int V_16 )
{
}
static void F_18 ( struct V_24 * V_25 )
{
struct V_26 * V_16 ;
int V_6 ;
int V_27 ;
if ( V_28 ) {
F_14 ( V_25 -> V_16 ) ;
return;
}
if ( ! F_11 () )
return;
V_16 = V_29 [ V_25 -> V_16 ] ;
V_6 = F_19 ( & V_16 -> V_30 ,
V_25 -> V_16 ) ;
if ( V_6 )
return;
if ( V_16 -> V_30 . V_31 . V_32 !=
V_33 )
goto V_34;
if ( V_16 -> V_30 . V_35 < 2 )
goto V_34;
F_20 ( L_1 , V_25 -> V_16 ) ;
for ( V_27 = 0 ; V_27 < V_16 -> V_30 . V_35 ; V_27 ++ ) {
F_20 ( L_2 ,
( V_27 == V_16 -> V_30 . V_36 ? '*' : ' ' ) , V_27 ,
( T_4 ) V_16 -> V_30 . V_37 [ V_27 ] . V_38 ,
( T_4 ) V_16 -> V_30 . V_37 [ V_27 ] . V_39 ,
( T_4 ) V_16 -> V_30 . V_37 [ V_27 ] . V_40 ) ;
}
if ( ! V_41 . V_42 )
V_16 -> V_30 . V_37 [ 0 ] . V_38 =
V_25 -> V_43 . V_44 / 1000 ;
V_16 -> V_45 = true ;
F_20 ( L_3 ) ;
return;
V_34:
V_16 -> V_45 = false ;
F_21 ( V_25 -> V_16 ) ;
}
static void F_22 ( struct V_24 * V_25 )
{
struct V_26 * V_16 ;
V_16 = V_29 [ V_25 -> V_16 ] ;
if ( ! V_16 -> V_45 )
return;
F_21 ( V_25 -> V_16 ) ;
}
static inline void F_18 ( struct V_24 * V_25 )
{
}
static inline void F_22 ( struct V_24 * V_25 )
{
}
static signed int F_23 ( struct V_46 * V_47 , T_1 V_48 )
{
signed int V_49 ;
T_1 V_50 , V_51 , V_52 ;
T_1 V_53 ;
V_52 = V_47 -> V_54 - V_48 ;
if ( abs ( V_52 ) <= V_47 -> V_55 )
return 0 ;
V_50 = F_1 ( V_47 -> V_56 , V_52 ) ;
V_47 -> V_57 += V_52 ;
V_53 = F_24 ( 30 ) ;
if ( V_47 -> V_57 > V_53 )
V_47 -> V_57 = V_53 ;
if ( V_47 -> V_57 < - V_53 )
V_47 -> V_57 = - V_53 ;
V_51 = F_1 ( V_47 -> V_58 , V_52 - V_47 -> V_59 ) ;
V_47 -> V_59 = V_52 ;
V_49 = V_50 + F_1 ( V_47 -> V_57 , V_47 -> V_60 ) + V_51 ;
V_49 = V_49 + ( 1 << ( V_4 - 1 ) ) ;
return ( signed int ) F_5 ( V_49 ) ;
}
static inline void F_25 ( struct V_26 * V_16 )
{
struct V_46 * V_47 = & V_16 -> V_47 ;
V_47 -> V_56 = F_6 ( V_61 . V_62 ) ;
V_47 -> V_58 = F_6 ( V_61 . V_63 ) ;
V_47 -> V_60 = F_6 ( V_61 . V_64 ) ;
V_47 -> V_54 = F_24 ( V_61 . V_54 ) ;
V_47 -> V_59 = V_47 -> V_54 - F_24 ( 100 ) ;
V_47 -> V_55 = F_24 ( V_61 . V_55 ) ;
V_47 -> V_57 = 0 ;
}
static inline void F_26 ( void )
{
T_3 V_65 ;
struct V_26 * V_16 ;
V_16 = V_29 [ 0 ] ;
F_27 ( V_66 , V_65 ) ;
V_41 . V_42 =
( V_65 & V_67 ||
V_16 -> V_68 . V_69 == V_16 -> V_68 . V_70 ) ;
}
static int F_28 ( void )
{
struct V_26 * V_16 = V_29 [ 0 ] ;
int V_70 = V_16 -> V_68 . V_70 ;
return V_70 ?
( V_16 -> V_68 . V_71 * 100 / V_70 ) : 0 ;
}
static T_5 F_29 ( struct V_26 * V_72 )
{
T_3 V_73 ;
int V_6 ;
if ( ! F_30 ( V_74 ) )
return - V_75 ;
V_6 = F_31 ( V_72 -> V_16 , V_76 , & V_73 ) ;
if ( V_6 )
return ( T_5 ) V_6 ;
return ( T_5 ) ( V_73 & 0x0f ) ;
}
static T_5 F_32 ( struct V_26 * V_72 , T_3 V_77 )
{
T_5 V_78 ;
if ( F_30 ( V_79 ) ) {
if ( ! V_77 ) {
V_78 = F_31 ( V_72 -> V_16 , V_80 ,
& V_77 ) ;
if ( V_78 )
return V_78 ;
}
V_78 = ( V_77 >> 24 ) & 0xff ;
} else {
V_78 = F_29 ( V_72 ) ;
}
return V_78 ;
}
static int F_33 ( int V_16 , T_5 V_81 )
{
T_3 V_73 ;
int V_6 ;
if ( ! F_30 ( V_74 ) )
return - V_75 ;
V_6 = F_31 ( V_16 , V_76 , & V_73 ) ;
if ( V_6 )
return V_6 ;
V_73 = ( V_73 & ~ 0x0f ) | V_81 ;
F_34 ( V_16 , V_76 , V_73 ) ;
return 0 ;
}
static int F_35 ( struct V_26 * V_72 )
{
T_5 V_78 ;
int V_82 = - V_83 ;
V_78 = F_32 ( V_72 , 0 ) ;
if ( V_78 < 0 )
return V_78 ;
if ( F_30 ( V_79 ) ) {
if ( V_78 == V_84 )
return 1 ;
if ( V_78 <= V_85 )
return 2 ;
if ( V_78 <= V_86 )
return 3 ;
else
return 4 ;
} else if ( F_30 ( V_74 ) ) {
V_82 = ( V_78 >> 2 ) + 1 ;
}
return V_82 ;
}
static int F_36 ( struct V_26 * V_72 ,
int V_87 )
{
int V_78 = - V_83 ;
int V_6 ;
if ( ! V_87 )
V_78 = V_72 -> V_88 ;
F_37 ( & V_89 ) ;
if ( F_30 ( V_79 ) ) {
T_3 V_90 ;
V_6 = F_31 ( V_72 -> V_16 , V_80 , & V_90 ) ;
if ( V_6 )
goto V_91;
V_90 &= ~ F_38 ( 31 , 24 ) ;
if ( V_78 == - V_83 )
V_78 = V_92 [ V_87 - 1 ] ;
V_90 |= ( T_3 ) V_78 << 24 ;
V_6 = F_34 ( V_72 -> V_16 , V_80 , V_90 ) ;
} else {
if ( V_78 == - V_83 )
V_78 = ( V_87 - 1 ) << 2 ;
V_6 = F_33 ( V_72 -> V_16 , V_78 ) ;
}
V_91:
F_39 ( & V_89 ) ;
return V_6 ;
}
static T_6 F_40 (
struct V_24 * V_25 , char * V_93 )
{
int V_27 = 0 ;
int V_6 = 0 ;
while ( V_94 [ V_27 ] != NULL )
V_6 += sprintf ( & V_93 [ V_6 ] , L_4 , V_94 [ V_27 ++ ] ) ;
V_6 += sprintf ( & V_93 [ V_6 ] , L_5 ) ;
return V_6 ;
}
static T_6 F_41 (
struct V_24 * V_25 , const char * V_93 , T_7 V_95 )
{
struct V_26 * V_72 = V_29 [ V_25 -> V_16 ] ;
char V_96 [ 21 ] ;
int V_6 , V_27 = 0 ;
V_6 = sscanf ( V_93 , L_6 , V_96 ) ;
if ( V_6 != 1 )
return - V_83 ;
while ( V_94 [ V_27 ] != NULL ) {
if ( ! strcmp ( V_96 , V_94 [ V_27 ] ) ) {
F_36 ( V_72 , V_27 ) ;
return V_95 ;
}
++ V_27 ;
}
return - V_83 ;
}
static T_6 F_42 (
struct V_24 * V_25 , char * V_93 )
{
struct V_26 * V_72 = V_29 [ V_25 -> V_16 ] ;
int V_97 ;
V_97 = F_35 ( V_72 ) ;
if ( V_97 < 0 )
return V_97 ;
return sprintf ( V_93 , L_7 , V_94 [ V_97 ] ) ;
}
static void F_43 ( unsigned int V_16 , int * V_98 ,
int * V_99 )
{
T_3 V_100 ;
F_31 ( V_16 , V_101 , & V_100 ) ;
if ( V_41 . V_102 )
* V_99 = F_44 ( V_100 ) ;
else
* V_99 = F_45 ( V_100 ) ;
* V_98 = F_45 ( V_100 ) ;
}
static void F_46 ( unsigned int V_16 )
{
struct V_26 * V_72 = V_29 [ V_16 ] ;
int V_103 , V_104 ;
T_3 V_90 ;
T_5 V_78 ;
V_103 = V_72 -> V_105 ;
V_104 = V_72 -> V_106 ;
if ( V_72 -> V_25 == V_107 )
V_104 = V_103 ;
F_31 ( V_16 , V_80 , & V_90 ) ;
V_90 &= ~ F_47 ( ~ 0L ) ;
V_90 |= F_47 ( V_104 ) ;
V_90 &= ~ F_48 ( ~ 0L ) ;
V_90 |= F_48 ( V_103 ) ;
if ( V_72 -> V_108 == V_72 -> V_25 )
goto V_109;
V_72 -> V_108 = V_72 -> V_25 ;
if ( V_72 -> V_110 >= 0 ) {
V_78 = V_72 -> V_110 ;
V_72 -> V_110 = - V_83 ;
goto V_111;
}
if ( V_72 -> V_25 == V_107 ) {
V_78 = F_32 ( V_72 , V_90 ) ;
V_72 -> V_112 = V_78 ;
if ( V_78 < 0 )
goto V_109;
V_78 = 0 ;
} else {
if ( V_72 -> V_112 < 0 )
goto V_109;
V_78 = F_32 ( V_72 , V_90 ) ;
if ( V_78 )
goto V_109;
V_78 = V_72 -> V_112 ;
}
V_111:
if ( F_30 ( V_79 ) ) {
V_90 &= ~ F_38 ( 31 , 24 ) ;
V_90 |= ( T_3 ) V_78 << 24 ;
} else {
F_33 ( V_16 , V_78 ) ;
}
V_109:
F_34 ( V_16 , V_80 , V_90 ) ;
}
static int F_49 ( struct V_24 * V_25 )
{
struct V_26 * V_72 = V_29 [ V_25 -> V_16 ] ;
if ( ! V_28 )
return 0 ;
V_72 -> V_110 = F_32 ( V_72 , 0 ) ;
return 0 ;
}
static int F_50 ( struct V_24 * V_25 )
{
if ( ! V_28 )
return 0 ;
F_37 ( & V_89 ) ;
V_29 [ V_25 -> V_16 ] -> V_108 = 0 ;
F_46 ( V_25 -> V_16 ) ;
F_39 ( & V_89 ) ;
return 0 ;
}
static void F_51 ( void )
{
int V_16 ;
F_52 (cpu)
F_53 ( V_16 ) ;
}
static int F_54 ( void * V_113 , T_3 V_114 )
{
unsigned int V_16 ;
* ( T_4 * ) V_113 = V_114 ;
V_61 . V_115 = V_61 . V_116 * V_117 ;
F_52 (cpu)
if ( V_29 [ V_16 ] )
F_25 ( V_29 [ V_16 ] ) ;
return 0 ;
}
static int F_55 ( void * V_113 , T_3 * V_114 )
{
* V_114 = * ( T_4 * ) V_113 ;
return 0 ;
}
static void F_56 ( void )
{
int V_27 ;
V_118 = F_57 ( L_8 , NULL ) ;
if ( F_58 ( V_118 ) )
return;
for ( V_27 = 0 ; V_119 [ V_27 ] . V_120 ; V_27 ++ ) {
struct V_121 * V_121 ;
V_121 = F_59 ( V_119 [ V_27 ] . V_120 , 0660 ,
V_118 , V_119 [ V_27 ] . V_90 ,
& V_122 ) ;
if ( ! F_60 ( V_121 ) )
V_119 [ V_27 ] . V_121 = V_121 ;
}
}
static void F_61 ( void )
{
int V_27 ;
if ( F_58 ( V_118 ) )
return;
for ( V_27 = 0 ; V_119 [ V_27 ] . V_120 ; V_27 ++ ) {
F_62 ( V_119 [ V_27 ] . V_121 ) ;
V_119 [ V_27 ] . V_121 = NULL ;
}
F_62 ( V_118 ) ;
V_118 = NULL ;
}
static T_6 F_63 ( struct V_123 * V_124 ,
struct V_125 * V_126 , char * V_93 )
{
T_6 V_6 ;
F_37 ( & V_127 ) ;
V_6 = F_64 ( V_93 ) ;
F_39 ( & V_127 ) ;
return V_6 ;
}
static T_6 F_65 ( struct V_123 * V_128 , struct V_125 * V_129 ,
const char * V_93 , T_7 V_95 )
{
char * V_130 = memchr ( V_93 , '\n' , V_95 ) ;
int V_6 ;
F_37 ( & V_127 ) ;
V_6 = F_66 ( V_93 , V_130 ? V_130 - V_93 : V_95 ) ;
F_39 ( & V_127 ) ;
return V_6 < 0 ? V_6 : V_95 ;
}
static T_6 F_67 ( struct V_123 * V_124 ,
struct V_125 * V_126 , char * V_93 )
{
struct V_26 * V_16 ;
int V_131 , V_102 , V_132 ;
T_8 V_133 ;
F_37 ( & V_127 ) ;
if ( ! V_134 ) {
F_39 ( & V_127 ) ;
return - V_135 ;
}
V_16 = V_29 [ 0 ] ;
V_131 = V_16 -> V_68 . V_70 - V_16 -> V_68 . V_71 + 1 ;
V_102 = V_16 -> V_68 . V_69 - V_16 -> V_68 . V_71 + 1 ;
V_133 = F_2 ( V_102 , V_131 ) ;
V_132 = 100 - F_5 ( F_1 ( V_133 , F_24 ( 100 ) ) ) ;
F_39 ( & V_127 ) ;
return sprintf ( V_93 , L_9 , V_132 ) ;
}
static T_6 F_68 ( struct V_123 * V_124 ,
struct V_125 * V_126 , char * V_93 )
{
struct V_26 * V_16 ;
int V_131 ;
F_37 ( & V_127 ) ;
if ( ! V_134 ) {
F_39 ( & V_127 ) ;
return - V_135 ;
}
V_16 = V_29 [ 0 ] ;
V_131 = V_16 -> V_68 . V_70 - V_16 -> V_68 . V_71 + 1 ;
F_39 ( & V_127 ) ;
return sprintf ( V_93 , L_9 , V_131 ) ;
}
static T_6 F_69 ( struct V_123 * V_124 ,
struct V_125 * V_126 , char * V_93 )
{
T_6 V_6 ;
F_37 ( & V_127 ) ;
if ( ! V_134 ) {
F_39 ( & V_127 ) ;
return - V_135 ;
}
F_26 () ;
if ( V_41 . V_42 )
V_6 = sprintf ( V_93 , L_9 , V_41 . V_42 ) ;
else
V_6 = sprintf ( V_93 , L_9 , V_41 . V_102 ) ;
F_39 ( & V_127 ) ;
return V_6 ;
}
static T_6 F_70 ( struct V_123 * V_128 , struct V_125 * V_129 ,
const char * V_93 , T_7 V_95 )
{
unsigned int V_136 ;
int V_6 ;
V_6 = sscanf ( V_93 , L_10 , & V_136 ) ;
if ( V_6 != 1 )
return - V_83 ;
F_37 ( & V_127 ) ;
if ( ! V_134 ) {
F_39 ( & V_127 ) ;
return - V_135 ;
}
F_37 ( & V_89 ) ;
F_26 () ;
if ( V_41 . V_42 ) {
F_71 ( L_11 ) ;
F_39 ( & V_89 ) ;
F_39 ( & V_127 ) ;
return - V_137 ;
}
V_41 . V_102 = F_72 ( int , V_136 , 0 , 1 ) ;
if ( V_41 . V_102 ) {
struct V_26 * V_16 = V_29 [ 0 ] ;
int V_138 = V_16 -> V_68 . V_69 * 100 / V_16 -> V_68 . V_70 ;
if ( V_41 . V_139 > V_138 )
V_41 . V_139 = V_138 ;
}
F_39 ( & V_89 ) ;
F_51 () ;
F_39 ( & V_127 ) ;
return V_95 ;
}
static T_6 F_73 ( struct V_123 * V_128 , struct V_125 * V_129 ,
const char * V_93 , T_7 V_95 )
{
unsigned int V_136 ;
int V_6 ;
V_6 = sscanf ( V_93 , L_10 , & V_136 ) ;
if ( V_6 != 1 )
return - V_83 ;
F_37 ( & V_127 ) ;
if ( ! V_134 ) {
F_39 ( & V_127 ) ;
return - V_135 ;
}
F_37 ( & V_89 ) ;
V_41 . V_140 = F_72 ( int , V_136 , V_41 . V_139 , 100 ) ;
F_39 ( & V_89 ) ;
F_51 () ;
F_39 ( & V_127 ) ;
return V_95 ;
}
static T_6 F_74 ( struct V_123 * V_128 , struct V_125 * V_129 ,
const char * V_93 , T_7 V_95 )
{
unsigned int V_136 ;
int V_6 ;
V_6 = sscanf ( V_93 , L_10 , & V_136 ) ;
if ( V_6 != 1 )
return - V_83 ;
F_37 ( & V_127 ) ;
if ( ! V_134 ) {
F_39 ( & V_127 ) ;
return - V_135 ;
}
F_37 ( & V_89 ) ;
V_41 . V_139 = F_72 ( int , V_136 ,
F_28 () , V_41 . V_140 ) ;
F_39 ( & V_89 ) ;
F_51 () ;
F_39 ( & V_127 ) ;
return V_95 ;
}
static void T_9 F_75 ( void )
{
struct V_123 * V_141 ;
int V_142 ;
V_141 = F_76 ( L_12 ,
& V_143 . V_144 -> V_124 ) ;
if ( F_77 ( ! V_141 ) )
return;
V_142 = F_78 ( V_141 , & V_145 ) ;
if ( F_77 ( V_142 ) )
return;
if ( V_146 )
return;
V_142 = F_79 ( V_141 , & V_140 . V_126 ) ;
F_77 ( V_142 ) ;
V_142 = F_79 ( V_141 , & V_139 . V_126 ) ;
F_77 ( V_142 ) ;
}
static void F_80 ( struct V_26 * V_26 )
{
if ( F_30 ( V_147 ) )
F_34 ( V_26 -> V_16 , V_148 , 0x00 ) ;
F_34 ( V_26 -> V_16 , V_149 , 0x1 ) ;
V_26 -> V_108 = 0 ;
if ( V_26 -> V_88 == - V_83 )
V_26 -> V_88 = F_32 ( V_26 , 0 ) ;
}
static void F_81 ( int V_16 )
{
T_3 V_150 ;
int V_6 ;
V_6 = F_31 ( V_16 , V_151 , & V_150 ) ;
if ( V_6 )
return;
if ( ! ( V_150 & F_82 ( V_152 ) ) ) {
F_83 ( L_13 ) ;
V_150 |= F_82 ( V_152 ) ;
F_34 ( V_16 , V_151 , V_150 ) ;
}
}
static int F_84 ( void )
{
T_3 V_90 ;
F_27 ( V_153 , V_90 ) ;
return ( V_90 >> 8 ) & 0x7F ;
}
static int F_85 ( void )
{
T_3 V_90 ;
F_27 ( V_153 , V_90 ) ;
return ( V_90 >> 16 ) & 0x7F ;
}
static int F_86 ( void )
{
T_3 V_90 ;
F_27 ( V_154 , V_90 ) ;
return V_90 & 0x7F ;
}
static T_3 F_87 ( struct V_26 * V_26 , int V_68 )
{
T_3 V_114 ;
T_1 V_155 ;
T_4 V_156 ;
V_114 = ( T_3 ) V_68 << 8 ;
if ( V_41 . V_102 && ! V_41 . V_42 )
V_114 |= ( T_3 ) 1 << 32 ;
V_155 = V_26 -> V_156 . V_104 + F_1 (
F_24 ( V_68 - V_26 -> V_68 . V_71 ) ,
V_26 -> V_156 . V_157 ) ;
V_155 = F_72 ( T_1 , V_155 , V_26 -> V_156 . V_104 , V_26 -> V_156 . V_103 ) ;
V_156 = F_4 ( V_155 ) ;
if ( V_68 > V_26 -> V_68 . V_69 )
V_156 = V_26 -> V_156 . V_158 ;
return V_114 | V_156 ;
}
static int F_88 ( void )
{
T_3 V_90 ;
int V_27 ;
static int V_159 [] = {
83300 , 100000 , 133300 , 116700 , 80000 } ;
F_27 ( V_160 , V_90 ) ;
V_27 = V_90 & 0x7 ;
F_77 ( V_27 > 4 ) ;
return V_159 [ V_27 ] ;
}
static int F_89 ( void )
{
T_3 V_90 ;
int V_27 ;
static int V_161 [] = {
83300 , 100000 , 133300 , 116700 , 80000 ,
93300 , 90000 , 88900 , 87500 } ;
F_27 ( V_160 , V_90 ) ;
V_27 = V_90 & 0xF ;
F_77 ( V_27 > 8 ) ;
return V_161 [ V_27 ] ;
}
static void F_90 ( struct V_26 * V_26 )
{
T_3 V_90 ;
F_27 ( V_162 , V_90 ) ;
V_26 -> V_156 . V_104 = F_24 ( ( V_90 >> 8 ) & 0x7f ) ;
V_26 -> V_156 . V_103 = F_24 ( ( V_90 >> 16 ) & 0x7f ) ;
V_26 -> V_156 . V_157 = F_2 (
V_26 -> V_156 . V_103 - V_26 -> V_156 . V_104 ,
F_24 ( V_26 -> V_68 . V_69 -
V_26 -> V_68 . V_71 ) ) ;
F_27 ( V_163 , V_90 ) ;
V_26 -> V_156 . V_158 = V_90 & 0x7f ;
}
static int F_91 ( void )
{
T_3 V_90 ;
F_27 ( V_164 , V_90 ) ;
return ( V_90 >> 40 ) & 0xFF ;
}
static int F_92 ( void )
{
T_3 V_90 ;
F_27 ( V_164 , V_90 ) ;
return ( V_90 >> 8 ) & 0xFF ;
}
static int F_93 ( T_3 V_165 )
{
if ( V_165 & 0x600000000 ) {
T_3 V_166 ;
T_3 V_167 ;
int V_168 ;
int V_34 ;
V_34 = F_94 ( V_169 , & V_166 ) ;
if ( V_34 )
return V_34 ;
V_168 = V_170 + ( V_166 & 0x03 ) ;
V_34 = F_94 ( V_168 , & V_167 ) ;
if ( V_34 )
return V_34 ;
if ( V_166 & 0x03 )
V_167 >>= 16 ;
V_167 &= 0xff ;
F_20 ( L_14 , ( int ) V_167 ) ;
return ( int ) V_167 ;
}
return - V_75 ;
}
static int F_95 ( void )
{
T_3 V_171 ;
T_3 V_165 ;
int V_69 ;
int V_167 ;
int V_34 ;
F_27 ( V_164 , V_165 ) ;
V_69 = ( V_165 >> 8 ) & 0xFF ;
V_167 = F_93 ( V_165 ) ;
if ( V_167 <= 0 )
return V_69 ;
if ( V_28 ) {
return V_167 ;
}
V_34 = F_94 ( V_172 , & V_171 ) ;
if ( ! V_34 ) {
int V_173 ;
V_173 = V_171 & 0xff ;
if ( V_167 - 1 == V_173 ) {
V_69 = V_173 ;
F_20 ( L_15 , V_69 ) ;
}
}
return V_69 ;
}
static int F_96 ( void )
{
T_3 V_90 ;
int V_174 , V_6 ;
F_27 ( V_175 , V_90 ) ;
V_174 = F_95 () ;
V_6 = ( V_90 ) & 255 ;
if ( V_6 <= V_174 )
V_6 = V_174 ;
return V_6 ;
}
static inline int F_97 ( void )
{
return 100000 ;
}
static T_3 F_98 ( struct V_26 * V_26 , int V_68 )
{
T_3 V_114 ;
V_114 = ( T_3 ) V_68 << 8 ;
if ( V_41 . V_102 && ! V_41 . V_42 )
V_114 |= ( T_3 ) 1 << 32 ;
return V_114 ;
}
static int F_99 ( void )
{
return 10 ;
}
static int F_100 ( void )
{
T_3 V_90 ;
int V_174 , V_6 ;
F_27 ( V_175 , V_90 ) ;
V_174 = F_95 () ;
V_6 = ( ( ( V_90 ) >> 8 ) & 0xFF ) ;
if ( V_6 <= V_174 )
V_6 = V_174 ;
return V_6 ;
}
static int F_101 ( struct V_26 * V_16 )
{
return V_41 . V_102 || V_41 . V_42 ?
V_16 -> V_68 . V_69 : V_16 -> V_68 . V_70 ;
}
static void F_102 ( struct V_26 * V_16 , int V_68 )
{
F_103 ( V_68 * V_16 -> V_68 . V_176 , V_16 -> V_16 ) ;
V_16 -> V_68 . V_177 = V_68 ;
F_34 ( V_16 -> V_16 , V_178 ,
V_179 . V_180 ( V_16 , V_68 ) ) ;
}
static void F_104 ( struct V_26 * V_16 )
{
F_102 ( V_16 , V_16 -> V_68 . V_71 ) ;
}
static void F_105 ( struct V_26 * V_16 )
{
int V_68 ;
F_26 () ;
V_68 = F_101 ( V_16 ) ;
V_68 = V_103 ( V_16 -> V_68 . V_71 , V_16 -> V_105 ) ;
F_102 ( V_16 , V_68 ) ;
}
static void F_106 ( struct V_26 * V_16 )
{
V_16 -> V_68 . V_71 = V_179 . V_181 () ;
V_16 -> V_68 . V_69 = V_179 . V_182 () ;
V_16 -> V_68 . V_183 = V_179 . V_184 () ;
V_16 -> V_68 . V_70 = V_179 . V_185 () ;
V_16 -> V_68 . V_176 = V_179 . V_186 () ;
V_16 -> V_68 . V_44 = V_16 -> V_68 . V_69 * V_16 -> V_68 . V_176 ;
V_16 -> V_68 . V_187 = V_16 -> V_68 . V_70 * V_16 -> V_68 . V_176 ;
if ( V_179 . V_188 )
V_16 -> V_189 = V_179 . V_188 () ;
if ( V_179 . V_190 )
V_179 . V_190 ( V_16 ) ;
F_104 ( V_16 ) ;
}
static inline void F_107 ( struct V_26 * V_16 )
{
struct V_191 * V_191 = & V_16 -> V_191 ;
V_191 -> V_192 = F_8 ( V_191 -> V_193 , V_191 -> V_194 ) ;
}
static inline bool F_108 ( struct V_26 * V_16 , T_3 time )
{
T_3 V_193 , V_194 ;
unsigned long V_195 ;
T_3 V_196 ;
F_109 ( V_195 ) ;
F_27 ( V_197 , V_193 ) ;
F_27 ( V_198 , V_194 ) ;
V_196 = F_110 () ;
if ( V_16 -> V_199 == V_194 || V_16 -> V_200 == V_196 ) {
F_111 ( V_195 ) ;
return false ;
}
F_111 ( V_195 ) ;
V_16 -> V_201 = V_16 -> V_191 . time ;
V_16 -> V_191 . time = time ;
V_16 -> V_191 . V_193 = V_193 ;
V_16 -> V_191 . V_194 = V_194 ;
V_16 -> V_191 . V_196 = V_196 ;
V_16 -> V_191 . V_193 -= V_16 -> V_202 ;
V_16 -> V_191 . V_194 -= V_16 -> V_199 ;
V_16 -> V_191 . V_196 -= V_16 -> V_200 ;
V_16 -> V_202 = V_193 ;
V_16 -> V_199 = V_194 ;
V_16 -> V_200 = V_196 ;
if ( V_16 -> V_201 ) {
F_107 ( V_16 ) ;
return true ;
}
return false ;
}
static inline T_1 F_112 ( struct V_26 * V_16 )
{
return F_7 ( V_16 -> V_191 . V_192 , V_203 ) ;
}
static inline T_1 F_113 ( struct V_26 * V_16 )
{
return F_7 ( V_16 -> V_68 . V_183 ,
V_16 -> V_191 . V_192 ) ;
}
static inline T_1 F_114 ( struct V_26 * V_16 )
{
struct V_191 * V_191 = & V_16 -> V_191 ;
T_1 V_204 , V_205 ;
int V_206 , V_207 ;
V_204 = F_2 ( V_191 -> V_194 << V_16 -> V_189 ,
V_191 -> V_196 ) ;
V_205 = V_16 -> V_208 ;
V_16 -> V_208 >>= 1 ;
if ( V_204 < V_205 )
V_204 = V_205 ;
V_191 -> V_209 = V_204 * 100 ;
V_206 = V_41 . V_102 || V_41 . V_42 ?
V_16 -> V_68 . V_69 : V_16 -> V_68 . V_70 ;
V_206 += V_206 >> 2 ;
V_206 = F_1 ( V_206 , V_204 ) ;
if ( V_206 < V_16 -> V_68 . V_71 )
V_206 = V_16 -> V_68 . V_71 ;
V_207 = F_113 ( V_16 ) ;
if ( V_207 > V_206 )
V_206 += ( V_207 - V_206 ) >> 1 ;
return V_206 ;
}
static inline T_1 F_115 ( struct V_26 * V_16 )
{
T_1 V_210 , V_69 , V_177 , V_211 ;
T_3 V_212 ;
V_69 = V_16 -> V_68 . V_183 ;
V_177 = V_16 -> V_68 . V_177 ;
V_210 = F_7 ( V_16 -> V_191 . V_192 ,
F_2 ( 100 * V_69 , V_177 ) ) ;
V_212 = V_16 -> V_191 . time - V_16 -> V_201 ;
if ( ( T_2 ) V_212 > V_61 . V_115 * 3 ) {
V_211 = F_2 ( V_61 . V_115 , V_212 ) ;
V_210 = F_1 ( V_210 , V_211 ) ;
} else {
V_211 = F_2 ( 100 * ( V_16 -> V_191 . V_194 << V_16 -> V_189 ) ,
V_16 -> V_191 . V_196 ) ;
if ( V_211 < F_24 ( 1 ) )
V_210 = 0 ;
}
V_16 -> V_191 . V_209 = V_210 ;
return V_16 -> V_68 . V_177 - F_23 ( & V_16 -> V_47 , V_210 ) ;
}
static int F_116 ( struct V_26 * V_16 , int V_68 )
{
int V_69 = F_101 ( V_16 ) ;
int V_71 ;
V_71 = V_103 ( V_16 -> V_68 . V_71 , V_16 -> V_106 ) ;
V_69 = V_103 ( V_71 , V_16 -> V_105 ) ;
return F_72 ( int , V_68 , V_71 , V_69 ) ;
}
static void F_117 ( struct V_26 * V_16 , int V_68 )
{
if ( V_68 == V_16 -> V_68 . V_177 )
return;
V_16 -> V_68 . V_177 = V_68 ;
F_118 ( V_178 , V_179 . V_180 ( V_16 , V_68 ) ) ;
}
static void F_119 ( struct V_26 * V_16 , int V_213 )
{
int V_214 = V_16 -> V_68 . V_177 ;
struct V_191 * V_191 ;
F_26 () ;
V_213 = F_116 ( V_16 , V_213 ) ;
F_103 ( V_213 * V_16 -> V_68 . V_176 , V_16 -> V_16 ) ;
F_117 ( V_16 , V_213 ) ;
V_191 = & V_16 -> V_191 ;
F_120 ( F_7 ( 100 , V_191 -> V_192 ) ,
F_5 ( V_191 -> V_209 ) ,
V_214 ,
V_16 -> V_68 . V_177 ,
V_191 -> V_194 ,
V_191 -> V_193 ,
V_191 -> V_196 ,
F_112 ( V_16 ) ,
F_5 ( V_16 -> V_208 * 100 ) ) ;
}
static void F_121 ( struct V_215 * V_113 ,
T_3 time , unsigned int V_195 )
{
struct V_26 * V_16 = F_122 ( V_113 , struct V_26 , V_216 ) ;
T_3 V_217 = time - V_16 -> V_191 . time ;
if ( ( T_2 ) V_217 < V_61 . V_115 )
return;
if ( F_108 ( V_16 , time ) ) {
int V_213 ;
V_213 = F_115 ( V_16 ) ;
F_119 ( V_16 , V_213 ) ;
}
}
static void F_123 ( struct V_215 * V_113 , T_3 time ,
unsigned int V_195 )
{
struct V_26 * V_16 = F_122 ( V_113 , struct V_26 , V_216 ) ;
T_3 V_217 ;
if ( V_195 & V_218 ) {
V_16 -> V_208 = F_24 ( 1 ) ;
} else if ( V_16 -> V_208 ) {
V_217 = time - V_16 -> V_219 ;
if ( V_217 > V_220 )
V_16 -> V_208 = 0 ;
}
V_16 -> V_219 = time ;
V_217 = time - V_16 -> V_191 . time ;
if ( ( T_2 ) V_217 < V_221 )
return;
if ( F_108 ( V_16 , time ) ) {
int V_213 ;
V_213 = F_114 ( V_16 ) ;
F_119 ( V_16 , V_213 ) ;
}
}
static int F_124 ( unsigned int V_222 )
{
struct V_26 * V_16 ;
V_16 = V_29 [ V_222 ] ;
if ( ! V_16 ) {
V_16 = F_125 ( sizeof( * V_16 ) , V_223 ) ;
if ( ! V_16 )
return - V_224 ;
V_29 [ V_222 ] = V_16 ;
V_16 -> V_88 = - V_83 ;
V_16 -> V_112 = - V_83 ;
V_16 -> V_110 = - V_83 ;
}
V_16 = V_29 [ V_222 ] ;
V_16 -> V_16 = V_222 ;
if ( V_28 ) {
const struct V_225 * V_226 ;
V_226 = F_126 ( V_227 ) ;
if ( V_226 )
F_81 ( V_222 ) ;
F_80 ( V_16 ) ;
} else if ( F_127 () ) {
F_25 ( V_16 ) ;
}
F_106 ( V_16 ) ;
F_20 ( L_16 , V_222 ) ;
return 0 ;
}
static void F_128 ( unsigned int V_228 )
{
struct V_26 * V_16 = V_29 [ V_228 ] ;
if ( V_28 )
return;
if ( V_16 -> V_229 )
return;
V_16 -> V_191 . time = 0 ;
F_129 ( V_228 , & V_16 -> V_216 ,
V_179 . V_216 ) ;
V_16 -> V_229 = true ;
}
static void F_130 ( unsigned int V_16 )
{
struct V_26 * V_72 = V_29 [ V_16 ] ;
if ( ! V_72 -> V_229 )
return;
F_131 ( V_16 ) ;
V_72 -> V_229 = false ;
F_132 () ;
}
static int F_133 ( struct V_26 * V_16 )
{
return V_41 . V_42 || V_41 . V_102 ?
V_16 -> V_68 . V_44 : V_16 -> V_68 . V_187 ;
}
static void F_134 ( struct V_24 * V_25 ,
struct V_26 * V_16 )
{
int V_44 = F_133 ( V_16 ) ;
T_1 V_230 , V_231 ;
int V_232 , V_233 ;
if ( V_28 ) {
F_43 ( V_16 -> V_16 , & V_233 , & V_232 ) ;
} else {
V_232 = F_101 ( V_16 ) ;
V_233 = V_16 -> V_68 . V_70 ;
}
V_230 = V_232 * V_25 -> V_103 / V_44 ;
if ( V_25 -> V_103 == V_25 -> V_104 ) {
V_231 = V_230 ;
} else {
V_231 = V_232 * V_25 -> V_104 / V_44 ;
V_231 = F_72 ( T_1 , V_231 ,
0 , V_230 ) ;
}
F_20 ( L_17 ,
V_25 -> V_16 , V_232 ,
V_231 , V_230 ) ;
if ( V_146 ) {
V_16 -> V_106 = V_231 ;
V_16 -> V_105 = V_230 ;
} else {
T_1 V_234 , V_235 ;
V_235 = F_135 ( V_233 * V_41 . V_140 , 100 ) ;
V_234 = F_135 ( V_233 * V_41 . V_139 , 100 ) ;
V_234 = F_72 ( T_1 , V_234 , 0 , V_235 ) ;
F_20 ( L_18 , V_25 -> V_16 ,
V_234 , V_235 ) ;
V_16 -> V_106 = V_103 ( V_231 , V_234 ) ;
V_16 -> V_106 = V_104 ( V_16 -> V_106 , V_230 ) ;
V_16 -> V_105 = V_104 ( V_230 , V_235 ) ;
V_16 -> V_105 = V_103 ( V_231 , V_16 -> V_105 ) ;
V_16 -> V_106 = V_104 ( V_16 -> V_106 ,
V_16 -> V_105 ) ;
}
F_20 ( L_19 , V_25 -> V_16 ,
V_16 -> V_105 ,
V_16 -> V_106 ) ;
}
static int F_136 ( struct V_24 * V_25 )
{
struct V_26 * V_16 ;
if ( ! V_25 -> V_43 . V_44 )
return - V_236 ;
F_20 ( L_20 ,
V_25 -> V_43 . V_44 , V_25 -> V_103 ) ;
V_16 = V_29 [ V_25 -> V_16 ] ;
V_16 -> V_25 = V_25 -> V_25 ;
F_37 ( & V_89 ) ;
F_134 ( V_25 , V_16 ) ;
if ( V_16 -> V_25 == V_107 ) {
F_130 ( V_25 -> V_16 ) ;
F_105 ( V_16 ) ;
} else {
F_128 ( V_25 -> V_16 ) ;
}
if ( V_28 )
F_46 ( V_25 -> V_16 ) ;
F_39 ( & V_89 ) ;
return 0 ;
}
static void F_137 ( struct V_24 * V_25 ,
struct V_26 * V_16 )
{
if ( V_16 -> V_68 . V_183 > V_16 -> V_68 . V_69 &&
V_25 -> V_103 < V_25 -> V_43 . V_44 &&
V_25 -> V_103 > V_16 -> V_68 . V_44 ) {
F_20 ( L_21 ) ;
V_25 -> V_103 = V_25 -> V_43 . V_44 ;
}
}
static int F_138 ( struct V_24 * V_25 )
{
struct V_26 * V_16 = V_29 [ V_25 -> V_16 ] ;
F_26 () ;
F_139 ( V_25 , V_25 -> V_43 . V_237 ,
F_133 ( V_16 ) ) ;
if ( V_25 -> V_25 != V_238 &&
V_25 -> V_25 != V_107 )
return - V_83 ;
F_137 ( V_25 , V_16 ) ;
return 0 ;
}
static void F_140 ( struct V_24 * V_25 )
{
F_104 ( V_29 [ V_25 -> V_16 ] ) ;
}
static void F_141 ( struct V_24 * V_25 )
{
F_20 ( L_22 , V_25 -> V_16 ) ;
F_130 ( V_25 -> V_16 ) ;
if ( V_28 )
F_49 ( V_25 ) ;
else
F_140 ( V_25 ) ;
}
static int F_142 ( struct V_24 * V_25 )
{
F_22 ( V_25 ) ;
V_25 -> V_239 = false ;
return 0 ;
}
static int F_143 ( struct V_24 * V_25 )
{
struct V_26 * V_16 ;
int V_142 ;
V_142 = F_124 ( V_25 -> V_16 ) ;
if ( V_142 )
return V_142 ;
V_16 = V_29 [ V_25 -> V_16 ] ;
V_16 -> V_105 = 0xFF ;
V_16 -> V_106 = 0 ;
V_25 -> V_104 = V_16 -> V_68 . V_71 * V_16 -> V_68 . V_176 ;
V_25 -> V_103 = V_16 -> V_68 . V_70 * V_16 -> V_68 . V_176 ;
V_25 -> V_43 . V_237 = V_16 -> V_68 . V_71 * V_16 -> V_68 . V_176 ;
F_26 () ;
V_25 -> V_43 . V_44 = V_41 . V_42 ?
V_16 -> V_68 . V_69 : V_16 -> V_68 . V_70 ;
V_25 -> V_43 . V_44 *= V_16 -> V_68 . V_176 ;
F_18 ( V_25 ) ;
F_144 ( V_25 -> V_16 , V_25 -> V_240 ) ;
V_25 -> V_239 = true ;
return 0 ;
}
static int F_145 ( struct V_24 * V_25 )
{
int V_6 = F_143 ( V_25 ) ;
if ( V_6 )
return V_6 ;
V_25 -> V_43 . V_241 = V_242 ;
if ( F_146 ( V_243 ) )
V_25 -> V_25 = V_107 ;
else
V_25 -> V_25 = V_238 ;
return 0 ;
}
static int F_147 ( struct V_24 * V_25 )
{
struct V_26 * V_16 = V_29 [ V_25 -> V_16 ] ;
F_26 () ;
F_139 ( V_25 , V_25 -> V_43 . V_237 ,
F_133 ( V_16 ) ) ;
F_137 ( V_25 , V_16 ) ;
F_134 ( V_25 , V_16 ) ;
return 0 ;
}
static int F_148 ( struct V_24 * V_25 ,
unsigned int V_244 ,
unsigned int V_245 )
{
struct V_26 * V_16 = V_29 [ V_25 -> V_16 ] ;
struct V_246 V_247 ;
int V_213 ;
F_26 () ;
V_247 . V_248 = V_25 -> V_249 ;
V_247 . V_250 = V_244 ;
F_149 ( V_25 , & V_247 ) ;
switch ( V_245 ) {
case V_251 :
V_213 = F_135 ( V_247 . V_250 , V_16 -> V_68 . V_176 ) ;
break;
case V_252 :
V_213 = V_247 . V_250 / V_16 -> V_68 . V_176 ;
break;
default:
V_213 = F_150 ( V_247 . V_250 , V_16 -> V_68 . V_176 ) ;
break;
}
V_213 = F_116 ( V_16 , V_213 ) ;
if ( V_213 != V_16 -> V_68 . V_177 ) {
V_16 -> V_68 . V_177 = V_213 ;
F_34 ( V_25 -> V_16 , V_178 ,
V_179 . V_180 ( V_16 , V_213 ) ) ;
}
V_247 . V_250 = V_213 * V_16 -> V_68 . V_176 ;
F_151 ( V_25 , & V_247 , false ) ;
return 0 ;
}
static unsigned int F_152 ( struct V_24 * V_25 ,
unsigned int V_244 )
{
struct V_26 * V_16 = V_29 [ V_25 -> V_16 ] ;
int V_213 ;
F_26 () ;
V_213 = F_135 ( V_244 , V_16 -> V_68 . V_176 ) ;
V_213 = F_116 ( V_16 , V_213 ) ;
F_117 ( V_16 , V_213 ) ;
return V_213 * V_16 -> V_68 . V_176 ;
}
static int F_153 ( struct V_24 * V_25 )
{
int V_6 = F_143 ( V_25 ) ;
if ( V_6 )
return V_6 ;
V_25 -> V_43 . V_241 = V_253 ;
V_25 -> V_254 = V_255 ;
V_25 -> V_249 = V_25 -> V_43 . V_237 ;
return 0 ;
}
static bool F_127 ( void )
{
return V_134 == & V_256 &&
V_179 . V_216 == F_121 ;
}
static void F_154 ( void )
{
unsigned int V_16 ;
F_155 () ;
F_156 (cpu) {
if ( V_29 [ V_16 ] ) {
if ( V_134 == & V_256 )
F_130 ( V_16 ) ;
F_157 ( V_29 [ V_16 ] ) ;
V_29 [ V_16 ] = NULL ;
}
}
F_158 () ;
V_134 = NULL ;
}
static int F_159 ( struct V_257 * V_258 )
{
int V_6 ;
memset ( & V_41 , 0 , sizeof( V_41 ) ) ;
V_41 . V_140 = 100 ;
V_134 = V_258 ;
V_6 = F_160 ( V_134 ) ;
if ( V_6 ) {
F_154 () ;
return V_6 ;
}
V_41 . V_139 = F_28 () ;
if ( F_127 () )
F_56 () ;
return 0 ;
}
static int F_161 ( void )
{
if ( V_28 )
return - V_259 ;
if ( F_127 () )
F_61 () ;
F_162 ( V_134 ) ;
F_154 () ;
return 0 ;
}
static T_6 F_64 ( char * V_93 )
{
if ( ! V_134 )
return sprintf ( V_93 , L_23 ) ;
return sprintf ( V_93 , L_7 , V_134 == & V_256 ?
L_24 : L_25 ) ;
}
static int F_66 ( const char * V_93 , T_7 V_260 )
{
int V_6 ;
if ( V_260 == 3 && ! strncmp ( V_93 , L_26 , V_260 ) )
return V_134 ?
F_161 () : - V_83 ;
if ( V_260 == 6 && ! strncmp ( V_93 , L_24 , V_260 ) ) {
if ( V_134 ) {
if ( V_134 == & V_256 )
return 0 ;
V_6 = F_161 () ;
if ( V_6 )
return V_6 ;
}
return F_159 ( & V_256 ) ;
}
if ( V_260 == 7 && ! strncmp ( V_93 , L_25 , V_260 ) ) {
if ( V_134 ) {
if ( V_134 == & V_261 )
return 0 ;
V_6 = F_161 () ;
if ( V_6 )
return V_6 ;
}
return F_159 ( & V_261 ) ;
}
return - V_83 ;
}
static int T_9 F_163 ( void )
{
if ( ! V_179 . V_182 () ||
! V_179 . V_181 () ||
! V_179 . V_185 () )
return - V_236 ;
return 0 ;
}
static void F_164 ( void )
{
switch ( V_9 . V_10 ) {
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
V_179 . V_216 = F_123 ;
}
}
static void F_164 ( void )
{
}
static void T_9 F_165 ( struct V_179 * V_267 )
{
V_179 . V_182 = V_267 -> V_182 ;
V_179 . V_184 = V_267 -> V_184 ;
V_179 . V_181 = V_267 -> V_181 ;
V_179 . V_185 = V_267 -> V_185 ;
V_179 . V_186 = V_267 -> V_186 ;
V_179 . V_180 = V_267 -> V_180 ;
V_179 . V_190 = V_267 -> V_190 ;
V_179 . V_216 = V_267 -> V_216 ;
V_179 . V_188 = V_267 -> V_188 ;
F_164 () ;
}
static bool T_9 F_166 ( void )
{
int V_27 ;
F_52 (i) {
T_10 V_268 ;
union V_269 * V_270 ;
struct V_271 V_272 = { V_273 , NULL } ;
struct V_274 * V_275 = F_167 ( V_276 , V_27 ) ;
if ( ! V_275 )
continue;
V_268 = F_168 ( V_275 -> V_277 , L_27 , NULL , & V_272 ) ;
if ( F_169 ( V_268 ) )
continue;
V_270 = V_272 . V_278 ;
if ( V_270 && V_270 -> type == V_279 ) {
F_157 ( V_270 ) ;
return false ;
}
F_157 ( V_270 ) ;
}
return true ;
}
static bool T_9 F_170 ( void )
{
int V_27 ;
F_52 (i) {
struct V_274 * V_275 = F_167 ( V_276 , V_27 ) ;
if ( ! V_275 )
continue;
if ( F_171 ( V_275 -> V_277 , L_28 ) )
return true ;
}
return false ;
}
static bool T_9 F_172 ( void )
{
struct V_280 V_281 ;
struct V_282 * V_283 ;
const struct V_225 * V_226 ;
T_3 V_284 ;
V_226 = F_126 ( V_285 ) ;
if ( V_226 ) {
F_27 ( V_286 , V_284 ) ;
if ( V_284 & ( 1 << 8 ) )
return true ;
}
if ( V_287 ||
F_169 ( F_173 ( V_288 , 0 , & V_281 ) ) )
return false ;
for ( V_283 = V_289 ; V_283 -> V_290 ; V_283 ++ ) {
if ( ! strncmp ( V_281 . V_291 , V_283 -> V_291 , V_292 ) &&
! strncmp ( V_281 . V_293 , V_283 -> V_293 ,
V_294 ) )
switch ( V_283 -> V_295 ) {
case V_296 :
return F_166 () ;
case V_297 :
return F_170 () &&
( ! V_298 ) ;
}
}
return false ;
}
static void F_174 ( void )
{
if ( V_13 )
F_175 () ;
}
static inline bool F_172 ( void ) { return false ; }
static inline bool F_170 ( void ) { return false ; }
static inline void F_174 ( void ) {}
static int T_9 F_176 ( void )
{
int V_142 ;
if ( V_299 )
return - V_236 ;
if ( F_126 ( V_300 ) ) {
F_165 ( & V_301 ) ;
if ( V_302 ) {
V_179 . V_216 = F_123 ;
} else {
V_28 ++ ;
V_256 . V_126 = V_303 ;
goto V_304;
}
} else {
const struct V_225 * V_226 ;
V_226 = F_126 ( V_305 ) ;
if ( ! V_226 )
return - V_236 ;
F_165 ( (struct V_179 * ) V_226 -> V_306 ) ;
}
if ( F_163 () )
return - V_236 ;
V_304:
if ( F_172 () )
return - V_236 ;
if ( ! V_28 && V_307 )
return - V_308 ;
F_83 ( L_29 ) ;
V_29 = F_177 ( sizeof( void * ) * F_178 () ) ;
if ( ! V_29 )
return - V_224 ;
F_174 () ;
F_75 () ;
F_37 ( & V_127 ) ;
V_142 = F_159 ( V_309 ) ;
F_39 ( & V_127 ) ;
if ( V_142 )
return V_142 ;
if ( V_28 )
F_83 ( L_30 ) ;
return 0 ;
}
static int T_9 F_179 ( char * V_310 )
{
if ( ! V_310 )
return - V_83 ;
if ( ! strcmp ( V_310 , L_31 ) ) {
V_299 = 1 ;
} else if ( ! strcmp ( V_310 , L_25 ) ) {
F_83 ( L_32 ) ;
V_309 = & V_261 ;
V_302 = 1 ;
}
if ( ! strcmp ( V_310 , L_33 ) ) {
F_83 ( L_34 ) ;
V_302 = 1 ;
}
if ( ! strcmp ( V_310 , L_35 ) )
V_298 = 1 ;
if ( ! strcmp ( V_310 , L_36 ) )
V_307 = 1 ;
if ( ! strcmp ( V_310 , L_37 ) )
V_146 = true ;
#ifdef F_180
if ( ! strcmp ( V_310 , L_38 ) )
V_13 = true ;
#endif
return 0 ;
}
