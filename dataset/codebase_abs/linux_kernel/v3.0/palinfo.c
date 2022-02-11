static char *
F_1 ( char * V_1 , T_1 V_2 )
{
int V_3 , V_4 ;
const char * V_5 [] = { L_1 , L_2 , L_3 , L_4 , L_5 } ;
for ( V_3 = 0 , V_4 = 0 ; V_3 < 64 ; V_3 ++ , V_4 = V_3 / 10 ) {
if ( V_2 & 0x1 ) {
V_1 += sprintf ( V_1 , L_6 , 1 << ( V_3 - V_4 * 10 ) , V_5 [ V_4 ] ) ;
}
V_2 >>= 1 ;
}
return V_1 ;
}
static char *
F_2 ( char * V_1 , T_1 * V_6 , int V_7 )
{
int V_3 , V_8 , V_9 = 0 ;
T_1 V_10 = V_6 [ 0 ] ;
V_10 >>= V_3 = V_8 = F_3 ( V_10 ) - 1 ;
for(; V_3 < V_7 ; V_3 ++ ) {
if ( V_3 != 0 && ( V_3 % 64 ) == 0 ) V_10 = * ++ V_6 ;
if ( ( V_10 & 0x1 ) == 0 && V_9 == 0 ) {
if ( V_8 <= V_3 - 2 )
V_1 += sprintf ( V_1 , L_7 , V_8 , V_3 - 1 ) ;
else
V_1 += sprintf ( V_1 , L_8 , V_3 - 1 ) ;
V_9 = 1 ;
V_8 = - 1 ;
} else if ( ( V_10 & 0x1 ) && V_9 == 1 ) {
V_9 = 0 ;
V_8 = V_3 ;
}
V_10 >>= 1 ;
}
if ( V_8 > - 1 ) {
if ( V_8 < 127 )
V_1 += sprintf ( V_1 , L_9 , V_8 ) ;
else
V_1 += sprintf ( V_1 , L_10 ) ;
}
return V_1 ;
}
static int
F_4 ( char * V_11 )
{
T_2 V_12 ;
char * V_1 = V_11 ;
T_1 V_13 [ 8 ] ;
T_3 * V_14 = ( T_3 * ) V_13 ;
int V_3 ;
V_12 = F_5 ( V_14 ) ;
if ( V_12 != 0 ) return 0 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( V_14 [ V_3 ] . V_15 . V_16 == 1 ) {
V_1 += sprintf ( V_1 , L_11
L_12
L_13
L_14
L_15 , V_3 ,
V_14 [ V_3 ] . V_15 . V_17 ,
V_14 [ V_3 ] . V_15 . V_18 ,
V_14 [ V_3 ] . V_15 . V_19 ,
V_14 [ V_3 ] . V_15 . V_20 ? L_16 : L_17 ) ;
} else {
V_1 += sprintf ( V_1 , L_18 , V_3 ) ;
}
}
return V_1 - V_11 ;
}
static int
F_6 ( char * V_11 )
{
char * V_1 = V_11 ;
unsigned long V_3 , V_21 , V_22 ;
T_4 V_23 ;
int V_4 , V_24 ;
long V_12 ;
if ( ( V_12 = F_7 ( & V_21 , & V_22 ) ) != 0 ) {
F_8 ( V_25 L_19 , V_12 ) ;
return 0 ;
}
V_1 += sprintf ( V_1 , L_20 , V_21 , V_22 ) ;
for ( V_3 = 0 ; V_3 < V_21 ; V_3 ++ ) {
for ( V_4 = 2 ; V_4 > 0 ; V_4 -- ) {
if ( ( V_12 = F_9 ( V_3 , V_4 , & V_23 ) ) != 0 ) {
continue;
}
V_1 += sprintf ( V_1 ,
L_21
L_22
L_23 ,
V_26 [ V_4 + V_23 . V_27 ] , V_3 + 1 ,
V_23 . V_28 ) ;
if ( V_23 . V_27 ) V_1 += sprintf ( V_1 , L_24 ) ;
V_1 += sprintf ( V_1 , L_25 , V_29 [ V_23 . V_30 ] ) ;
V_1 += sprintf ( V_1 ,
L_26
L_27
L_28 ,
V_23 . V_31 , 1 << V_23 . V_32 , 1 << V_23 . V_33 ) ;
if ( V_4 == 1 )
V_1 += sprintf ( V_1 , L_29 ) ;
else
V_1 += sprintf ( V_1 , L_30 ,
V_23 . V_34 ) ;
V_1 += sprintf ( V_1 ,
L_31
L_32 , V_23 . V_35 ) ;
for( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
if ( V_23 . V_36 & 0x1 )
V_1 += sprintf ( V_1 , L_33 , V_37 [ V_24 ] ) ;
V_23 . V_36 >>= 1 ;
}
V_1 += sprintf ( V_1 , L_34 ) ;
for( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
if ( V_23 . V_38 & 0x1 )
V_1 += sprintf ( V_1 , L_33 , V_39 [ V_24 ] ) ;
V_23 . V_38 >>= 1 ;
}
V_1 += sprintf ( V_1 ,
L_35
L_36
L_37 ,
1 << V_23 . V_40 , V_23 . V_41 ,
V_23 . V_42 ) ;
if ( V_23 . V_27 ) break;
}
}
return V_1 - V_11 ;
}
static int
F_10 ( char * V_11 )
{
char * V_1 = V_11 ;
T_1 V_43 = 0 , V_44 = 0 , V_45 ;
T_1 V_46 ;
T_5 V_47 ;
T_6 V_48 ;
T_7 V_49 ;
T_8 V_50 ;
const char * V_51 ;
int V_3 , V_4 ;
long V_12 ;
if ( ( V_12 = F_11 ( & V_47 , & V_48 ) ) != 0 ) {
F_8 ( V_25 L_38 , V_12 ) ;
} else {
V_1 += sprintf ( V_1 ,
L_39
L_40
L_41
L_42
L_43
L_44
L_45 ,
V_47 . V_52 . V_53 ,
V_48 . V_54 . V_55 + 1 ,
V_47 . V_52 . V_56 + 1 ,
V_47 . V_52 . V_57 ,
V_47 . V_52 . V_58 ,
V_48 . V_54 . V_59 ) ;
if ( V_48 . V_54 . V_60 == V_61 )
V_1 += sprintf ( V_1 , L_46 ) ;
else
V_1 += sprintf ( V_1 , L_47 ,
V_48 . V_54 . V_60 ?
V_48 . V_54 . V_60 : 1 ) ;
}
if ( F_12 ( & V_46 ) == 0 ) {
V_1 += sprintf ( V_1 , L_48 ) ;
V_51 = L_1 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( V_46 & ( 1 << V_3 ) ) {
V_1 += sprintf ( V_1 , L_49 , V_51 , V_62 [ V_3 ] ) ;
V_51 = L_50 ;
}
}
V_1 += sprintf ( V_1 , L_51 ) ;
}
if ( ( V_12 = F_13 ( & V_43 , & V_44 ) ) != 0 ) {
F_8 ( V_25 L_52 , V_12 ) ;
} else {
V_1 += sprintf ( V_1 ,
L_53
L_54
L_55
L_56 ,
V_47 . V_52 . V_63 ? L_1 : L_57 ,
V_47 . V_52 . V_64 + 1 ,
V_47 . V_52 . V_65 + 1 ) ;
V_1 = F_1 ( V_1 , V_43 ) ;
V_1 += sprintf ( V_1 , L_58 ) ;
V_1 = F_1 ( V_1 , V_44 ) ;
}
if ( ( V_12 = F_14 ( & V_50 ) ) != 0 ) {
F_8 ( V_25 L_59 , V_12 ) ;
} else {
V_1 += sprintf ( V_1 ,
L_60
L_61
L_62
L_63
L_64 ,
V_50 . V_66 , V_50 . V_67 [ 0 ] , V_50 . V_67 [ 1 ] ,
V_50 . V_68 [ 0 ] , V_50 . V_68 [ 1 ] ) ;
V_1 += sprintf ( V_1 ,
L_65
L_66 ,
V_47 . V_52 . V_69 ,
V_47 . V_52 . V_70 ) ;
for( V_3 = 0 ; V_3 < V_47 . V_52 . V_69 ; V_3 ++ ) {
for ( V_4 = 2 ; V_4 > 0 ; V_4 -- ) {
V_45 = 0 ;
if ( ( V_12 = F_15 ( V_3 , V_4 , & V_49 , & V_45 ) ) != 0 ) {
continue;
}
V_1 += sprintf ( V_1 ,
L_67
L_68
L_69
L_70
L_71 ,
V_26 [ V_4 + V_49 . V_71 ] , V_3 + 1 ,
V_49 . V_72 ,
V_49 . V_73 ,
V_49 . V_74 ) ;
if ( V_49 . V_75 )
V_1 += sprintf ( V_1 , L_72 ) ;
if ( V_49 . V_71 )
V_1 += sprintf ( V_1 , L_24 ) ;
if ( V_49 . V_76 )
V_1 += sprintf ( V_1 , L_73 ) ;
V_1 += sprintf ( V_1 , L_74 ) ;
V_1 = F_1 ( V_1 , V_45 ) ;
if ( V_49 . V_71 )
break;
}
}
}
V_1 += sprintf ( V_1 , L_51 ) ;
return V_1 - V_11 ;
}
static int
F_16 ( char * V_11 )
{
char * V_1 = V_11 ;
T_1 V_6 [ 2 ] ;
T_1 V_77 ;
unsigned long V_78 ;
T_9 V_79 ;
unsigned long V_80 , V_81 ;
static const char * const V_82 [] = {
L_75 ,
L_76 ,
L_77 ,
L_78 ,
} ;
for( V_77 = 0 ; V_77 < 4 ; V_77 ++ ) {
if ( F_17 ( V_77 , & V_6 [ 0 ] , & V_6 [ 1 ] ) != 0 ) return 0 ;
V_1 += sprintf ( V_1 , L_79 , V_82 [ V_77 ] ) ;
V_1 = F_2 ( V_1 , V_6 , 128 ) ;
V_1 += sprintf ( V_1 , L_51 ) ;
}
if ( F_18 ( & V_78 , & V_79 ) == 0 ) {
V_1 += sprintf ( V_1 ,
L_80
L_81 ,
V_78 , V_79 . V_83 ,
V_79 . V_83 < V_84 ? V_85 [ V_79 . V_83 ] : L_82 ) ;
}
if ( F_19 ( & V_80 , & V_81 ) )
return 0 ;
V_1 += sprintf ( V_1 ,
L_83
L_84 , V_80 , V_81 ) ;
return V_1 - V_11 ;
}
static char * F_20 ( char * V_11 , T_1 V_86 , T_1 V_12 , T_1 V_87 ,
unsigned long V_88 )
{
char * V_1 = V_11 ;
char * * V_89 , * * V_90 ;
int V_3 ;
V_89 = V_90 = V_91 [ V_88 ] ;
for( V_3 = 0 ; V_3 < 64 ; V_3 ++ , V_86 >>= 1 , V_12 >>= 1 , V_87 >>= 1 ) {
if ( ! ( V_87 ) )
break;
if ( ! ( V_86 & 0x1 ) )
continue;
if ( V_89 )
V_90 = V_89 + V_3 ;
if ( V_90 && * V_90 ) {
V_1 += sprintf ( V_1 , L_85 , * V_90 ,
V_86 & 0x1 ? ( V_12 & 0x1 ?
L_86 : L_87 ) : L_1 ,
V_86 & 0x1 ? ( V_87 & 0x1 ?
L_88 : L_89 ) : L_1 ) ;
} else {
V_1 += sprintf ( V_1 , L_90
L_91 ,
V_88 , V_3 ,
V_86 & 0x1 ? ( V_12 & 0x1 ?
L_86 : L_87 ) : L_1 ,
V_86 & 0x1 ? ( V_87 & 0x1 ?
L_88 : L_89 ) : L_1 ) ;
}
}
return V_1 ;
}
static int
F_21 ( char * V_11 )
{
char * V_1 = V_11 ;
T_1 V_86 = 1 , V_12 = 1 , V_87 = 1 , V_92 = 0 ;
T_2 V_93 ;
do {
V_93 = F_22 ( & V_86 , & V_12 , & V_87 ,
V_92 ) ;
if ( V_93 < 0 ) {
return V_1 - V_11 ;
}
if ( V_93 == 1 ) {
V_92 ++ ;
continue;
}
V_1 = F_20 ( V_1 , V_86 , V_12 , V_87 , V_92 ) ;
V_92 ++ ;
} while( 1 );
return V_1 - V_11 ;
}
static int
F_23 ( char * V_11 )
{
char * V_1 = V_11 ;
const char * * V_90 = V_94 ;
T_10 V_95 , V_96 , V_97 ;
T_1 V_86 , V_12 , V_87 ;
int V_3 ;
T_2 V_93 ;
if ( ( V_93 = F_24 ( & V_95 , & V_96 , & V_97 ) ) != 0 ) return 0 ;
V_86 = V_95 . V_98 ;
V_12 = V_96 . V_98 ;
V_87 = V_97 . V_98 ;
for( V_3 = 0 ; V_3 < 64 ; V_3 ++ , V_90 ++ , V_86 >>= 1 , V_12 >>= 1 , V_87 >>= 1 ) {
if ( ! * V_90 ) continue;
V_1 += sprintf ( V_1 , L_92 , * V_90 ,
V_86 & 0x1 ? L_1 : L_93 ,
V_86 & 0x1 ? ( V_12 & 0x1 ? L_94 : L_87 ) : L_1 ,
V_86 & 0x1 ? ( V_87 & 0x1 ? L_88 : L_89 ) : L_1 ) ;
}
return V_1 - V_11 ;
}
static int
F_25 ( char * V_11 )
{
T_11 V_99 , V_100 ;
char * V_1 = V_11 ;
if ( F_26 ( & V_99 , & V_100 ) != 0 )
return 0 ;
V_1 += sprintf ( V_1 ,
L_95
L_96
L_97 ,
V_100 . V_101 . V_102 ,
V_99 . V_101 . V_102 ,
V_100 . V_101 . V_103 ,
V_100 . V_101 . V_104 ,
V_99 . V_101 . V_103 ,
V_99 . V_101 . V_104 ,
V_100 . V_101 . V_105 ,
V_100 . V_101 . V_106 ,
V_99 . V_101 . V_105 ,
V_99 . V_101 . V_106 ) ;
return V_1 - V_11 ;
}
static int
F_27 ( char * V_11 )
{
char * V_1 = V_11 ;
T_1 V_107 [ 16 ] ;
T_12 V_108 ;
if ( F_28 ( V_107 , & V_108 ) != 0 ) return 0 ;
V_1 += sprintf ( V_1 ,
L_98
L_99
L_100
L_101
L_102 ,
V_108 . V_109 . V_110 , V_108 . V_109 . V_111 ,
V_108 . V_109 . V_112 , V_108 . V_109 . V_113 ) ;
V_1 = F_2 ( V_1 , V_107 , 256 ) ;
V_1 += sprintf ( V_1 , L_103 ) ;
V_1 = F_2 ( V_1 , V_107 + 4 , 256 ) ;
V_1 += sprintf ( V_1 , L_104 ) ;
V_1 = F_2 ( V_1 , V_107 + 8 , 256 ) ;
V_1 += sprintf ( V_1 , L_105 ) ;
#ifdef F_29
if ( V_107 [ 12 ] == 0x10 ) V_107 [ 12 ] = 0x30 ;
#endif
V_1 = F_2 ( V_1 , V_107 + 12 , 256 ) ;
V_1 += sprintf ( V_1 , L_51 ) ;
return V_1 - V_11 ;
}
static int
F_30 ( char * V_11 )
{
char * V_1 = V_11 ;
struct V_114 V_115 , V_116 , V_117 ;
unsigned long V_66 ;
if ( F_31 ( & V_66 ) == - 1 )
V_1 += sprintf ( V_1 , L_106 ) ;
else
V_1 += sprintf ( V_1 , L_107 , V_66 ) ;
if ( F_32 ( & V_115 , & V_117 , & V_116 ) != 0 ) return 0 ;
V_1 += sprintf ( V_1 ,
L_108
L_109
L_110 ,
V_115 . V_118 , V_115 . V_119 , V_117 . V_118 , V_117 . V_119 , V_116 . V_118 , V_116 . V_119 ) ;
return V_1 - V_11 ;
}
static int
F_33 ( char * V_11 )
{
char * V_1 = V_11 ;
long V_12 ;
T_13 V_120 ;
T_1 V_121 [ 4 ] ;
T_5 V_47 ;
T_6 V_48 ;
unsigned long V_3 , V_4 ;
unsigned long V_7 [ 3 ] , V_122 ;
struct V_123 {
unsigned long V_124 : 1 ;
unsigned long V_125 : 11 ;
unsigned long V_126 : 52 ;
} * V_123 ;
struct V_127 {
unsigned long V_128 : 2 ;
unsigned long V_129 : 6 ;
unsigned long V_130 : 24 ;
unsigned long V_131 : 32 ;
} * V_127 ;
struct V_132 {
unsigned long V_1 : 1 ;
unsigned long V_128 : 1 ;
unsigned long V_133 : 3 ;
unsigned long V_134 : 1 ;
unsigned long V_135 : 1 ;
unsigned long V_136 : 2 ;
unsigned long V_137 : 3 ;
unsigned long V_138 : 38 ;
unsigned long V_131 : 2 ;
unsigned long V_139 : 1 ;
unsigned long V_125 : 11 ;
} * V_132 ;
struct V_140 {
unsigned long V_141 : 1 ;
unsigned long V_128 : 1 ;
unsigned long V_142 : 6 ;
unsigned long V_143 : 24 ;
unsigned long V_131 : 32 ;
} * V_140 ;
if ( ( V_12 = F_11 ( & V_47 , & V_48 ) ) != 0 ) {
F_8 ( V_25 L_38 , V_12 ) ;
return 0 ;
}
V_7 [ 0 ] = V_47 . V_52 . V_65 + 1 ;
V_7 [ 1 ] = V_47 . V_52 . V_64 + 1 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
for ( V_4 = 0 ; V_4 < V_7 [ V_3 ] ; V_4 ++ ) {
V_12 = F_34 ( V_4 , V_3 , V_121 , & V_120 ) ;
if ( V_12 != 0 ) {
F_8 ( V_25 L_111 ,
V_3 , V_4 , V_12 ) ;
continue;
}
V_123 = (struct V_123 * ) & V_121 [ 2 ] ;
if ( V_123 -> V_124 == 0 ) continue;
V_132 = (struct V_132 * ) V_121 ;
V_127 = (struct V_127 * ) & V_121 [ 1 ] ;
V_140 = (struct V_140 * ) & V_121 [ 3 ] ;
V_122 = - 1 << ( V_127 -> V_129 - 12 ) ;
V_1 += sprintf ( V_1 ,
L_112
L_113
L_114
L_115 ,
L_116 [ V_3 ] , V_4 ,
V_120 . V_144 . V_145 ,
V_120 . V_144 . V_146 ,
V_120 . V_144 . V_147 ,
V_120 . V_144 . V_148 ,
( V_132 -> V_138 & V_122 ) << 12 , ( V_123 -> V_126 & V_122 ) << 12 ) ;
V_1 = F_1 ( V_1 , 1 << V_127 -> V_129 ) ;
V_1 += sprintf ( V_1 ,
L_117
L_118
L_119
L_120
L_121
L_122 ,
V_132 -> V_136 , V_132 -> V_137 , V_140 -> V_143 , V_132 -> V_1 , V_132 -> V_133 ,
V_132 -> V_135 ) ;
}
}
return V_1 - V_11 ;
}
static void
F_35 ( void * V_77 )
{
T_14 * V_149 = ( T_14 * ) V_77 ;
V_149 -> V_93 = (* V_149 -> V_150 )( V_149 -> V_11 ) ;
}
static
int F_36 ( T_15 * V_151 , char * V_11 )
{
T_14 V_152 ;
int V_93 ;
V_152 . V_150 = V_153 [ V_151 -> V_154 ] . V_155 ;
V_152 . V_11 = V_11 ;
V_152 . V_93 = 0 ;
if ( ( V_93 = F_37 ( V_151 -> V_156 , F_35 , & V_152 , 1 ) ) ) {
F_8 ( V_25 L_123
L_124 , F_38 () , V_151 -> V_156 , V_151 -> V_154 , V_93 ) ;
return 0 ;
}
return V_152 . V_93 ;
}
static
int F_36 ( T_15 * V_151 , char * V_11 )
{
F_8 ( V_25 L_125 ) ;
return 0 ;
}
static int
F_39 ( char * V_11 , char * * V_157 , T_16 V_158 , int V_67 , int * V_159 , void * V_149 )
{
int V_160 = 0 ;
T_15 * V_151 = ( T_15 * ) & V_149 ;
if ( V_151 -> V_156 == F_40 () )
V_160 = ( * V_153 [ V_151 -> V_154 ] . V_155 ) ( V_11 ) ;
else
V_160 = F_36 ( V_151 , V_11 ) ;
F_41 () ;
if ( V_160 <= V_158 + V_67 ) * V_159 = 1 ;
* V_157 = V_11 + V_158 ;
V_160 -= V_158 ;
if ( V_160 > V_67 ) V_160 = V_67 ;
if ( V_160 < 0 ) V_160 = 0 ;
return V_160 ;
}
static void T_17
F_42 ( unsigned int V_161 )
{
# define F_43 "cpu%d"
T_15 V_151 ;
struct V_162 * * V_163 ;
struct V_162 * V_164 ;
int V_4 ;
char V_165 [ sizeof( F_43 ) ] ;
sprintf ( V_165 , F_43 , V_161 ) ;
V_164 = F_44 ( V_165 , V_166 ) ;
V_151 . V_156 = V_161 ;
V_163 = & V_167 [ V_161 * ( V_168 + 1 ) ] ;
* V_163 ++ = V_164 ;
for ( V_4 = 0 ; V_4 < V_168 ; V_4 ++ ) {
V_151 . V_154 = V_4 ;
* V_163 = F_45 (
V_153 [ V_4 ] . V_169 , 0 , V_164 ,
F_39 , ( void * ) V_151 . V_10 ) ;
V_163 ++ ;
}
}
static void
F_46 ( unsigned int V_170 )
{
int V_4 ;
struct V_162 * V_164 , * * V_163 ;
V_163 = & V_167 [ V_170 * ( V_168 + 1 ) ] ;
V_164 = * V_163 ;
* V_163 ++ = NULL ;
for ( V_4 = 0 ; V_4 < ( V_168 ) ; V_4 ++ ) {
if ( ( * V_163 ) ) {
F_47 ( ( * V_163 ) -> V_169 , V_164 ) ;
* V_163 ++ = NULL ;
}
}
if ( V_164 ) {
F_47 ( V_164 -> V_169 , V_166 ) ;
}
}
static int T_17 F_48 ( struct V_171 * V_172 ,
unsigned long V_173 , void * V_170 )
{
unsigned int V_174 = ( unsigned long ) V_170 ;
switch ( V_173 ) {
case V_175 :
case V_176 :
F_42 ( V_174 ) ;
break;
case V_177 :
case V_178 :
F_46 ( V_174 ) ;
break;
}
return V_179 ;
}
static int T_18
F_49 ( void )
{
int V_3 = 0 ;
F_8 ( V_180 L_126 , V_181 ) ;
V_166 = F_44 ( L_127 , NULL ) ;
F_50 (i) {
F_42 ( V_3 ) ;
}
F_51 ( & V_182 ) ;
return 0 ;
}
static void T_19
F_52 ( void )
{
int V_3 = 0 ;
F_50 (i) {
F_46 ( V_3 ) ;
}
F_47 ( V_166 -> V_169 , NULL ) ;
F_53 ( & V_182 ) ;
}
