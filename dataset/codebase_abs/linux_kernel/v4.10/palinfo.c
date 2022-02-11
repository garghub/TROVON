static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 , V_5 ;
static const char * V_6 [] = { L_1 , L_2 , L_3 , L_4 , L_5 } ;
for ( V_4 = 0 , V_5 = 0 ; V_4 < 64 ; V_4 ++ , V_5 = V_4 / 10 ) {
if ( V_3 & 0x1 )
F_2 ( V_2 , L_6 , 1 << ( V_4 - V_5 * 10 ) , V_6 [ V_5 ] ) ;
V_3 >>= 1 ;
}
}
static void F_3 ( struct V_1 * V_2 , T_1 * V_7 , int V_8 )
{
int V_4 , V_9 , V_10 = 0 ;
T_1 V_11 = V_7 [ 0 ] ;
V_11 >>= V_4 = V_9 = F_4 ( V_11 ) - 1 ;
for(; V_4 < V_8 ; V_4 ++ ) {
if ( V_4 != 0 && ( V_4 % 64 ) == 0 ) V_11 = * ++ V_7 ;
if ( ( V_11 & 0x1 ) == 0 && V_10 == 0 ) {
if ( V_9 <= V_4 - 2 )
F_2 ( V_2 , L_7 , V_9 , V_4 - 1 ) ;
else
F_2 ( V_2 , L_8 , V_4 - 1 ) ;
V_10 = 1 ;
V_9 = - 1 ;
} else if ( ( V_11 & 0x1 ) && V_10 == 1 ) {
V_10 = 0 ;
V_9 = V_4 ;
}
V_11 >>= 1 ;
}
if ( V_9 > - 1 ) {
if ( V_9 < 127 )
F_2 ( V_2 , L_9 , V_9 ) ;
else
F_5 ( V_2 , L_10 ) ;
}
}
static int F_6 ( struct V_1 * V_2 )
{
T_2 V_12 ;
T_1 V_13 [ 8 ] ;
T_3 * V_14 = ( T_3 * ) V_13 ;
int V_4 ;
V_12 = F_7 ( V_14 ) ;
if ( V_12 != 0 ) return 0 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
if ( V_14 [ V_4 ] . V_15 . V_16 == 1 ) {
F_2 ( V_2 ,
L_11
L_12
L_13
L_14
L_15 , V_4 ,
V_14 [ V_4 ] . V_15 . V_17 ,
V_14 [ V_4 ] . V_15 . V_18 ,
V_14 [ V_4 ] . V_15 . V_19 ,
V_14 [ V_4 ] . V_15 . V_20 ? L_16 : L_17 ) ;
} else {
F_2 ( V_2 , L_18 , V_4 ) ;
}
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned long V_4 , V_21 , V_22 ;
T_4 V_23 ;
int V_5 , V_24 ;
long V_12 ;
if ( ( V_12 = F_9 ( & V_21 , & V_22 ) ) != 0 ) {
F_10 ( V_25 L_19 , V_12 ) ;
return 0 ;
}
F_2 ( V_2 , L_20 ,
V_21 , V_22 ) ;
for ( V_4 = 0 ; V_4 < V_21 ; V_4 ++ ) {
for ( V_5 = 2 ; V_5 > 0 ; V_5 -- ) {
if ( ( V_12 = F_11 ( V_4 , V_5 , & V_23 ) ) != 0 )
continue;
F_2 ( V_2 ,
L_21
L_22
L_23 ,
V_26 [ V_5 + V_23 . V_27 ] , V_4 + 1 ,
V_23 . V_28 ) ;
if ( V_23 . V_27 )
F_5 ( V_2 , L_24 ) ;
F_2 ( V_2 , L_25 , V_29 [ V_23 . V_30 ] ) ;
F_2 ( V_2 ,
L_26
L_27
L_28 ,
V_23 . V_31 ,
1 << V_23 . V_32 ,
1 << V_23 . V_33 ) ;
if ( V_5 == 1 )
F_5 ( V_2 , L_29 ) ;
else
F_2 ( V_2 , L_30 ,
V_23 . V_34 ) ;
F_2 ( V_2 ,
L_31
L_32 , V_23 . V_35 ) ;
for( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
if ( V_23 . V_36 & 0x1 )
F_2 ( V_2 , L_33 , V_37 [ V_24 ] ) ;
V_23 . V_36 >>= 1 ;
}
F_5 ( V_2 , L_34 ) ;
for( V_24 = 0 ; V_24 < 8 ; V_24 ++ ) {
if ( V_23 . V_38 & 0x1 )
F_2 ( V_2 , L_33 , V_39 [ V_24 ] ) ;
V_23 . V_38 >>= 1 ;
}
F_2 ( V_2 ,
L_35
L_36
L_37 ,
1 << V_23 . V_40 , V_23 . V_41 ,
V_23 . V_42 ) ;
if ( V_23 . V_27 )
break;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_43 = 0 , V_44 = 0 , V_45 ;
T_1 V_46 ;
T_5 V_47 ;
T_6 V_48 ;
T_7 V_49 ;
T_8 V_50 ;
const char * V_51 ;
int V_4 , V_5 ;
long V_12 ;
if ( ( V_12 = F_13 ( & V_47 , & V_48 ) ) != 0 ) {
F_10 ( V_25 L_38 , V_12 ) ;
} else {
F_2 ( V_2 ,
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
F_5 ( V_2 , L_46 ) ;
else
F_2 ( V_2 , L_47 ,
V_48 . V_54 . V_60 ?
V_48 . V_54 . V_60 : 1 ) ;
}
if ( F_14 ( & V_46 ) == 0 ) {
F_5 ( V_2 , L_48 ) ;
V_51 = L_1 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
if ( V_46 & ( 1 << V_4 ) ) {
F_2 ( V_2 , L_49 , V_51 , V_62 [ V_4 ] ) ;
V_51 = L_50 ;
}
}
F_15 ( V_2 , '\n' ) ;
}
if ( ( V_12 = F_16 ( & V_43 , & V_44 ) ) != 0 ) {
F_10 ( V_25 L_51 , V_12 ) ;
} else {
F_2 ( V_2 ,
L_52
L_53
L_54
L_55 ,
V_47 . V_52 . V_63 ? L_1 : L_56 ,
V_47 . V_52 . V_64 + 1 ,
V_47 . V_52 . V_65 + 1 ) ;
F_1 ( V_2 , V_43 ) ;
F_5 ( V_2 , L_57 ) ;
F_1 ( V_2 , V_44 ) ;
}
if ( ( V_12 = F_17 ( & V_50 ) ) != 0 ) {
F_10 ( V_25 L_58 , V_12 ) ;
} else {
F_2 ( V_2 ,
L_59
L_60
L_61
L_62
L_63 ,
V_50 . V_66 , V_50 . V_67 [ 0 ] , V_50 . V_67 [ 1 ] ,
V_50 . V_68 [ 0 ] , V_50 . V_68 [ 1 ] ) ;
F_2 ( V_2 ,
L_64
L_65 ,
V_47 . V_52 . V_69 ,
V_47 . V_52 . V_70 ) ;
for( V_4 = 0 ; V_4 < V_47 . V_52 . V_69 ; V_4 ++ ) {
for ( V_5 = 2 ; V_5 > 0 ; V_5 -- ) {
V_45 = 0 ;
if ( ( V_12 = F_18 ( V_4 , V_5 , & V_49 , & V_45 ) ) != 0 )
continue;
F_2 ( V_2 ,
L_66
L_67
L_68
L_69
L_70 ,
V_26 [ V_5 + V_49 . V_71 ] , V_4 + 1 ,
V_49 . V_72 ,
V_49 . V_73 ,
V_49 . V_74 ) ;
if ( V_49 . V_75 )
F_5 ( V_2 , L_71 ) ;
if ( V_49 . V_71 )
F_5 ( V_2 , L_24 ) ;
if ( V_49 . V_76 )
F_5 ( V_2 , L_72 ) ;
F_5 ( V_2 , L_73 ) ;
F_1 ( V_2 , V_45 ) ;
if ( V_49 . V_71 )
break;
}
}
}
F_15 ( V_2 , '\n' ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
T_1 V_7 [ 2 ] ;
T_1 V_77 ;
unsigned long V_78 ;
T_9 V_79 ;
unsigned long V_80 , V_81 ;
static const char * const V_82 [] = {
L_74 ,
L_75 ,
L_76 ,
L_77 ,
} ;
for( V_77 = 0 ; V_77 < 4 ; V_77 ++ ) {
if ( F_20 ( V_77 , & V_7 [ 0 ] , & V_7 [ 1 ] ) != 0 )
return 0 ;
F_2 ( V_2 , L_78 , V_82 [ V_77 ] ) ;
F_3 ( V_2 , V_7 , 128 ) ;
F_15 ( V_2 , '\n' ) ;
}
if ( F_21 ( & V_78 , & V_79 ) == 0 )
F_2 ( V_2 ,
L_79
L_80 ,
V_78 , V_79 . V_83 ,
V_79 . V_83 < V_84 ? V_85 [ V_79 . V_83 ] : L_81 ) ;
if ( F_22 ( & V_80 , & V_81 ) )
return 0 ;
F_2 ( V_2 ,
L_82
L_83 , V_80 , V_81 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_86 , T_1 V_12 , T_1 V_87 ,
unsigned long V_88 )
{
const char * const * V_89 , * const * V_90 ;
int V_4 ;
V_89 = V_90 = V_91 [ V_88 ] ;
for( V_4 = 0 ; V_4 < 64 ; V_4 ++ , V_86 >>= 1 , V_12 >>= 1 , V_87 >>= 1 ) {
if ( ! ( V_87 ) )
break;
if ( ! ( V_86 & 0x1 ) )
continue;
if ( V_89 )
V_90 = V_89 + V_4 ;
if ( V_90 && * V_90 ) {
F_2 ( V_2 , L_84 , * V_90 ,
V_86 & 0x1 ? ( V_12 & 0x1 ?
L_85 : L_86 ) : L_1 ,
V_86 & 0x1 ? ( V_87 & 0x1 ?
L_87 : L_88 ) : L_1 ) ;
} else {
F_2 ( V_2 , L_89
L_90 ,
V_88 , V_4 ,
V_86 & 0x1 ? ( V_12 & 0x1 ?
L_85 : L_86 ) : L_1 ,
V_86 & 0x1 ? ( V_87 & 0x1 ?
L_87 : L_88 ) : L_1 ) ;
}
}
}
static int F_24 ( struct V_1 * V_2 )
{
T_1 V_86 = 1 , V_12 = 1 , V_87 = 1 , V_92 = 0 ;
T_2 V_93 ;
do {
V_93 = F_25 ( & V_86 , & V_12 , & V_87 ,
V_92 ) ;
if ( V_93 < 0 )
return 0 ;
if ( V_93 == 1 ) {
V_92 ++ ;
continue;
}
F_23 ( V_2 , V_86 , V_12 , V_87 , V_92 ) ;
V_92 ++ ;
} while( 1 );
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
const char * const * V_90 = V_94 ;
T_10 V_95 , V_96 , V_97 ;
T_1 V_86 , V_12 , V_87 ;
int V_4 ;
T_2 V_93 ;
if ( ( V_93 = F_27 ( & V_95 , & V_96 , & V_97 ) ) != 0 )
return 0 ;
V_86 = V_95 . V_98 ;
V_12 = V_96 . V_98 ;
V_87 = V_97 . V_98 ;
for( V_4 = 0 ; V_4 < 64 ; V_4 ++ , V_90 ++ , V_86 >>= 1 , V_12 >>= 1 , V_87 >>= 1 ) {
if ( ! * V_90 )
continue;
F_2 ( V_2 , L_91 , * V_90 ,
V_86 & 0x1 ? L_1 : L_92 ,
V_86 & 0x1 ? ( V_12 & 0x1 ? L_93 : L_86 ) : L_1 ,
V_86 & 0x1 ? ( V_87 & 0x1 ? L_87 : L_88 ) : L_1 ) ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_11 V_99 , V_100 ;
if ( F_29 ( & V_99 , & V_100 ) != 0 )
return 0 ;
F_2 ( V_2 ,
L_94
L_95
L_96 ,
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
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_107 [ 16 ] ;
T_12 V_108 ;
if ( F_31 ( V_107 , & V_108 ) != 0 )
return 0 ;
F_2 ( V_2 ,
L_97
L_98
L_99
L_100
L_101 ,
V_108 . V_109 . V_110 ,
V_108 . V_109 . V_111 ,
V_108 . V_109 . V_112 ,
V_108 . V_109 . V_113 ) ;
F_3 ( V_2 , V_107 , 256 ) ;
F_5 ( V_2 , L_102 ) ;
F_3 ( V_2 , V_107 + 4 , 256 ) ;
F_5 ( V_2 , L_103 ) ;
F_3 ( V_2 , V_107 + 8 , 256 ) ;
F_5 ( V_2 , L_104 ) ;
#ifdef F_32
if ( V_107 [ 12 ] == 0x10 )
V_107 [ 12 ] = 0x30 ;
#endif
F_3 ( V_2 , V_107 + 12 , 256 ) ;
F_15 ( V_2 , '\n' ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_114 V_115 , V_116 , V_117 ;
unsigned long V_66 ;
if ( F_34 ( & V_66 ) == - 1 )
F_5 ( V_2 , L_105 ) ;
else
F_2 ( V_2 , L_106 , V_66 ) ;
if ( F_35 ( & V_115 , & V_117 , & V_116 ) != 0 ) return 0 ;
F_2 ( V_2 ,
L_107
L_108
L_109 ,
V_115 . V_118 , V_115 . V_119 , V_117 . V_118 , V_117 . V_119 , V_116 . V_118 , V_116 . V_119 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
long V_12 ;
T_13 V_120 ;
T_1 V_121 [ 4 ] ;
T_5 V_47 ;
T_6 V_48 ;
unsigned long V_4 , V_5 ;
unsigned long V_8 [ 3 ] , V_122 ;
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
unsigned long V_133 : 1 ;
unsigned long V_128 : 1 ;
unsigned long V_134 : 3 ;
unsigned long V_135 : 1 ;
unsigned long V_136 : 1 ;
unsigned long V_137 : 2 ;
unsigned long V_138 : 3 ;
unsigned long V_139 : 38 ;
unsigned long V_131 : 2 ;
unsigned long V_140 : 1 ;
unsigned long V_125 : 11 ;
} * V_132 ;
struct V_141 {
unsigned long V_142 : 1 ;
unsigned long V_128 : 1 ;
unsigned long V_143 : 6 ;
unsigned long V_144 : 24 ;
unsigned long V_131 : 32 ;
} * V_141 ;
if ( ( V_12 = F_13 ( & V_47 , & V_48 ) ) != 0 ) {
F_10 ( V_25 L_38 , V_12 ) ;
return 0 ;
}
V_8 [ 0 ] = V_47 . V_52 . V_65 + 1 ;
V_8 [ 1 ] = V_47 . V_52 . V_64 + 1 ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
for ( V_5 = 0 ; V_5 < V_8 [ V_4 ] ; V_5 ++ ) {
V_12 = F_37 ( V_5 , V_4 , V_121 , & V_120 ) ;
if ( V_12 != 0 ) {
F_10 ( V_25 L_110 ,
V_4 , V_5 , V_12 ) ;
continue;
}
V_123 = (struct V_123 * ) & V_121 [ 2 ] ;
if ( V_123 -> V_124 == 0 )
continue;
V_132 = (struct V_132 * ) V_121 ;
V_127 = (struct V_127 * ) & V_121 [ 1 ] ;
V_141 = (struct V_141 * ) & V_121 [ 3 ] ;
V_122 = - 1 << ( V_127 -> V_129 - 12 ) ;
F_2 ( V_2 ,
L_111
L_112
L_113
L_114 ,
L_115 [ V_4 ] , V_5 ,
V_120 . V_145 . V_146 ,
V_120 . V_145 . V_147 ,
V_120 . V_145 . V_148 ,
V_120 . V_145 . V_149 ,
( V_132 -> V_139 & V_122 ) << 12 , ( V_123 -> V_126 & V_122 ) << 12 ) ;
F_1 ( V_2 , 1 << V_127 -> V_129 ) ;
F_2 ( V_2 ,
L_116
L_117
L_118
L_119
L_120
L_121 ,
V_132 -> V_137 , V_132 -> V_138 , V_141 -> V_144 , V_132 -> V_133 , V_132 -> V_134 ,
V_132 -> V_136 ) ;
}
}
return 0 ;
}
static void
F_38 ( void * V_77 )
{
T_14 * V_150 = ( T_14 * ) V_77 ;
V_150 -> V_93 = (* V_150 -> V_151 )( V_150 -> V_2 ) ;
}
static
int F_39 ( struct V_1 * V_2 , T_15 * V_152 )
{
T_14 V_153 ;
int V_93 ;
V_153 . V_151 = V_154 [ V_152 -> V_155 ] . V_156 ;
V_153 . V_2 = V_2 ;
V_153 . V_93 = 0 ;
if ( ( V_93 = F_40 ( V_152 -> V_157 , F_38 , & V_153 , 1 ) ) ) {
F_10 ( V_25 L_122
L_123 , F_41 () , V_152 -> V_157 , V_152 -> V_155 , V_93 ) ;
return 0 ;
}
return V_153 . V_93 ;
}
static
int F_39 ( struct V_1 * V_2 , T_15 * V_152 )
{
F_10 ( V_25 L_124 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , void * V_90 )
{
T_15 * V_152 = ( T_15 * ) & V_2 -> V_158 ;
if ( V_152 -> V_157 == F_43 () )
( * V_154 [ V_152 -> V_155 ] . V_156 ) ( V_2 ) ;
else
F_39 ( V_2 , V_152 ) ;
F_44 () ;
return 0 ;
}
static int F_45 ( struct V_159 * V_159 , struct V_160 * V_160 )
{
return F_46 ( V_160 , F_42 , F_47 ( V_159 ) ) ;
}
static int F_48 ( unsigned int V_161 )
{
T_15 V_152 ;
struct V_162 * V_163 ;
int V_5 ;
char V_164 [ 3 + 4 + 1 ] ;
sprintf ( V_164 , L_125 , V_161 ) ;
V_163 = F_49 ( V_164 , V_165 ) ;
if ( ! V_163 )
return - V_166 ;
V_152 . V_157 = V_161 ;
for ( V_5 = 0 ; V_5 < V_167 ; V_5 ++ ) {
V_152 . V_155 = V_5 ;
F_50 ( V_154 [ V_5 ] . V_168 , 0 , V_163 ,
& V_169 , ( void * ) V_152 . V_11 ) ;
}
return 0 ;
}
static int F_51 ( unsigned int V_170 )
{
char V_164 [ 3 + 4 + 1 ] ;
sprintf ( V_164 , L_125 , V_170 ) ;
F_52 ( V_164 , V_165 ) ;
return 0 ;
}
static int T_16 F_53 ( void )
{
int V_4 = 0 ;
F_10 ( V_171 L_126 , V_172 ) ;
V_165 = F_49 ( L_127 , NULL ) ;
if ( ! V_165 )
return - V_173 ;
V_4 = F_54 ( V_174 , L_128 ,
F_48 , F_51 ) ;
if ( V_4 < 0 ) {
F_52 ( L_127 , NULL ) ;
return V_4 ;
}
V_175 = V_4 ;
return 0 ;
}
static void T_17 F_55 ( void )
{
F_56 ( V_175 ) ;
F_52 ( L_127 , NULL ) ;
}
