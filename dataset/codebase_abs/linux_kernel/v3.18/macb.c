static unsigned int F_1 ( unsigned int V_1 )
{
return V_1 & ( V_2 - 1 ) ;
}
static struct V_3 * F_2 ( struct V_4 * V_5 , unsigned int V_1 )
{
return & V_5 -> V_6 [ F_1 ( V_1 ) ] ;
}
static struct V_7 * V_7 ( struct V_4 * V_5 , unsigned int V_1 )
{
return & V_5 -> V_8 [ F_1 ( V_1 ) ] ;
}
static T_1 F_3 ( struct V_4 * V_5 , unsigned int V_1 )
{
T_1 V_9 ;
V_9 = F_1 ( V_1 ) * sizeof( struct V_3 ) ;
return V_5 -> V_10 + V_9 ;
}
static unsigned int F_4 ( unsigned int V_1 )
{
return V_1 & ( V_11 - 1 ) ;
}
static struct V_3 * F_5 ( struct V_4 * V_5 , unsigned int V_1 )
{
return & V_5 -> V_12 [ F_4 ( V_1 ) ] ;
}
static void * F_6 ( struct V_4 * V_5 , unsigned int V_1 )
{
return V_5 -> V_13 + V_5 -> V_14 * F_4 ( V_1 ) ;
}
void F_7 ( struct V_4 * V_5 )
{
T_2 V_15 ;
T_3 V_16 ;
V_15 = F_8 ( * ( ( T_2 * ) V_5 -> V_17 -> V_18 ) ) ;
F_9 ( V_5 , V_19 , V_15 ) ;
V_16 = F_10 ( * ( ( T_3 * ) ( V_5 -> V_17 -> V_18 + 4 ) ) ) ;
F_9 ( V_5 , V_20 , V_16 ) ;
F_9 ( V_5 , V_21 , 0 ) ;
F_9 ( V_5 , V_22 , 0 ) ;
F_9 ( V_5 , V_23 , 0 ) ;
F_9 ( V_5 , V_24 , 0 ) ;
F_9 ( V_5 , V_25 , 0 ) ;
F_9 ( V_5 , V_26 , 0 ) ;
}
void F_11 ( struct V_4 * V_5 )
{
struct V_27 * V_28 ;
T_2 V_15 ;
T_3 V_16 ;
T_4 V_29 [ 6 ] ;
int V_30 ;
V_28 = F_12 ( & V_5 -> V_31 -> V_17 ) ;
for ( V_30 = 0 ; V_30 < 4 ; V_30 ++ ) {
V_15 = F_13 ( V_5 , V_19 + V_30 * 8 ) ;
V_16 = F_13 ( V_5 , V_20 + V_30 * 8 ) ;
if ( V_28 && V_28 -> V_32 ) {
V_29 [ 5 ] = V_15 & 0xff ;
V_29 [ 4 ] = ( V_15 >> 8 ) & 0xff ;
V_29 [ 3 ] = ( V_15 >> 16 ) & 0xff ;
V_29 [ 2 ] = ( V_15 >> 24 ) & 0xff ;
V_29 [ 1 ] = V_16 & 0xff ;
V_29 [ 0 ] = ( V_16 & 0xff00 ) >> 8 ;
} else {
V_29 [ 0 ] = V_15 & 0xff ;
V_29 [ 1 ] = ( V_15 >> 8 ) & 0xff ;
V_29 [ 2 ] = ( V_15 >> 16 ) & 0xff ;
V_29 [ 3 ] = ( V_15 >> 24 ) & 0xff ;
V_29 [ 4 ] = V_16 & 0xff ;
V_29 [ 5 ] = ( V_16 >> 8 ) & 0xff ;
}
if ( F_14 ( V_29 ) ) {
memcpy ( V_5 -> V_17 -> V_18 , V_29 , sizeof( V_29 ) ) ;
return;
}
}
F_15 ( V_5 -> V_17 , L_1 ) ;
F_16 ( V_5 -> V_17 ) ;
}
static int F_17 ( struct V_33 * V_34 , int V_35 , int V_36 )
{
struct V_4 * V_5 = V_34 -> V_37 ;
int V_38 ;
F_18 ( V_5 , V_39 , ( F_19 ( V_40 , V_41 )
| F_19 ( V_42 , V_43 )
| F_19 ( V_44 , V_35 )
| F_19 ( V_45 , V_36 )
| F_19 ( V_46 , V_47 ) ) ) ;
while ( ! F_20 ( V_48 , F_21 ( V_5 , V_49 ) ) )
F_22 () ;
V_38 = F_20 ( V_50 , F_21 ( V_5 , V_39 ) ) ;
return V_38 ;
}
static int F_23 ( struct V_33 * V_34 , int V_35 , int V_36 ,
T_3 V_38 )
{
struct V_4 * V_5 = V_34 -> V_37 ;
F_18 ( V_5 , V_39 , ( F_19 ( V_40 , V_41 )
| F_19 ( V_42 , V_51 )
| F_19 ( V_44 , V_35 )
| F_19 ( V_45 , V_36 )
| F_19 ( V_46 , V_47 )
| F_19 ( V_50 , V_38 ) ) ) ;
while ( ! F_20 ( V_48 , F_21 ( V_5 , V_49 ) ) )
F_22 () ;
return 0 ;
}
static void F_24 ( struct V_52 * V_52 , int V_53 , struct V_54 * V_17 )
{
long V_55 , V_56 , V_57 ;
switch ( V_53 ) {
case V_58 :
V_56 = 2500000 ;
break;
case V_59 :
V_56 = 25000000 ;
break;
case V_60 :
V_56 = 125000000 ;
break;
default:
return;
}
V_57 = F_25 ( V_52 , V_56 ) ;
if ( V_57 < 0 )
return;
V_55 = abs ( V_57 - V_56 ) ;
V_55 = F_26 ( V_55 , V_56 / 100000 ) ;
if ( V_55 > 5 )
F_27 ( V_17 , L_2 ,
V_56 ) ;
if ( F_28 ( V_52 , V_57 ) )
F_29 ( V_17 , L_3 ) ;
}
static void F_30 ( struct V_54 * V_17 )
{
struct V_4 * V_5 = F_31 ( V_17 ) ;
struct V_61 * V_62 = V_5 -> V_63 ;
unsigned long V_64 ;
int V_65 = 0 ;
F_32 ( & V_5 -> V_66 , V_64 ) ;
if ( V_62 -> V_67 ) {
if ( ( V_5 -> V_53 != V_62 -> V_53 ) ||
( V_5 -> V_68 != V_62 -> V_68 ) ) {
T_2 V_69 ;
V_69 = F_21 ( V_5 , V_70 ) ;
V_69 &= ~ ( F_33 ( V_71 ) | F_33 ( V_72 ) ) ;
if ( F_34 ( V_5 ) )
V_69 &= ~ F_35 ( V_73 ) ;
if ( V_62 -> V_68 )
V_69 |= F_33 ( V_72 ) ;
if ( V_62 -> V_53 == V_59 )
V_69 |= F_33 ( V_71 ) ;
if ( V_62 -> V_53 == V_60 &&
V_5 -> V_74 & V_75 )
V_69 |= F_35 ( V_73 ) ;
F_9 ( V_5 , V_70 , V_69 ) ;
V_5 -> V_53 = V_62 -> V_53 ;
V_5 -> V_68 = V_62 -> V_68 ;
V_65 = 1 ;
}
}
if ( V_62 -> V_67 != V_5 -> V_67 ) {
if ( ! V_62 -> V_67 ) {
V_5 -> V_53 = 0 ;
V_5 -> V_68 = - 1 ;
}
V_5 -> V_67 = V_62 -> V_67 ;
V_65 = 1 ;
}
F_36 ( & V_5 -> V_66 , V_64 ) ;
if ( ! F_37 ( V_5 -> V_76 ) )
F_24 ( V_5 -> V_76 , V_62 -> V_53 , V_17 ) ;
if ( V_65 ) {
if ( V_62 -> V_67 ) {
F_38 ( V_17 ) ;
F_15 ( V_17 , L_4 ,
V_62 -> V_53 ,
V_62 -> V_68 == V_77 ?
L_5 : L_6 ) ;
} else {
F_39 ( V_17 ) ;
F_15 ( V_17 , L_7 ) ;
}
}
}
static int F_40 ( struct V_54 * V_17 )
{
struct V_4 * V_5 = F_31 ( V_17 ) ;
struct V_27 * V_28 ;
struct V_61 * V_62 ;
int V_78 ;
int V_79 ;
V_62 = F_41 ( V_5 -> V_33 ) ;
if ( ! V_62 ) {
F_29 ( V_17 , L_8 ) ;
return - V_80 ;
}
V_28 = F_12 ( & V_5 -> V_31 -> V_17 ) ;
if ( V_28 && F_42 ( V_28 -> V_81 ) ) {
V_79 = F_43 ( & V_5 -> V_31 -> V_17 , V_28 -> V_81 , L_9 ) ;
if ( ! V_79 ) {
V_78 = F_44 ( V_28 -> V_81 ) ;
V_62 -> V_82 = ( V_78 < 0 ) ? V_83 : V_78 ;
}
}
V_79 = F_45 ( V_17 , V_62 , & F_30 ,
V_5 -> V_84 ) ;
if ( V_79 ) {
F_29 ( V_17 , L_10 ) ;
return V_79 ;
}
if ( F_34 ( V_5 ) && V_5 -> V_74 & V_75 )
V_62 -> V_85 &= V_86 ;
else
V_62 -> V_85 &= V_87 ;
V_62 -> V_88 = V_62 -> V_85 ;
V_5 -> V_67 = 0 ;
V_5 -> V_53 = 0 ;
V_5 -> V_68 = - 1 ;
V_5 -> V_63 = V_62 ;
return 0 ;
}
int F_46 ( struct V_4 * V_5 )
{
struct V_27 * V_28 ;
struct V_89 * V_90 ;
int V_91 = - V_80 , V_30 ;
F_18 ( V_5 , V_92 , F_33 ( V_93 ) ) ;
V_5 -> V_33 = F_47 () ;
if ( V_5 -> V_33 == NULL ) {
V_91 = - V_94 ;
goto V_95;
}
V_5 -> V_33 -> V_96 = L_11 ;
V_5 -> V_33 -> V_97 = & F_17 ;
V_5 -> V_33 -> V_98 = & F_23 ;
snprintf ( V_5 -> V_33 -> V_99 , V_100 , L_12 ,
V_5 -> V_31 -> V_96 , V_5 -> V_31 -> V_99 ) ;
V_5 -> V_33 -> V_37 = V_5 ;
V_5 -> V_33 -> V_101 = & V_5 -> V_17 -> V_17 ;
V_28 = F_12 ( & V_5 -> V_31 -> V_17 ) ;
V_5 -> V_33 -> V_82 = F_48 ( sizeof( int ) * V_102 , V_103 ) ;
if ( ! V_5 -> V_33 -> V_82 ) {
V_91 = - V_94 ;
goto V_104;
}
F_49 ( & V_5 -> V_17 -> V_17 , V_5 -> V_33 ) ;
V_90 = V_5 -> V_31 -> V_17 . V_105 ;
if ( V_90 ) {
V_91 = F_50 ( V_5 -> V_33 , V_90 ) ;
if ( ! V_91 && ! F_41 ( V_5 -> V_33 ) ) {
for ( V_30 = 0 ; V_30 < V_102 ; V_30 ++ ) {
struct V_61 * V_62 ;
V_62 = F_51 ( V_5 -> V_33 , V_30 ) ;
if ( F_37 ( V_62 ) ) {
V_91 = F_52 ( V_62 ) ;
break;
}
}
if ( V_91 )
goto V_106;
}
} else {
for ( V_30 = 0 ; V_30 < V_102 ; V_30 ++ )
V_5 -> V_33 -> V_82 [ V_30 ] = V_83 ;
if ( V_28 )
V_5 -> V_33 -> V_107 = V_28 -> V_107 ;
V_91 = F_53 ( V_5 -> V_33 ) ;
}
if ( V_91 )
goto V_108;
V_91 = F_40 ( V_5 -> V_17 ) ;
if ( V_91 )
goto V_106;
return 0 ;
V_106:
F_54 ( V_5 -> V_33 ) ;
V_108:
F_55 ( V_5 -> V_33 -> V_82 ) ;
V_104:
F_56 ( V_5 -> V_33 ) ;
V_95:
return V_91 ;
}
static void F_57 ( struct V_4 * V_5 )
{
T_2 T_5 * V_69 = V_5 -> V_109 + V_110 ;
T_2 * V_111 = & V_5 -> V_112 . V_4 . V_113 ;
T_2 * V_114 = & V_5 -> V_112 . V_4 . V_115 + 1 ;
F_58 ( ( unsigned long ) ( V_114 - V_111 - 1 ) != ( V_116 - V_110 ) / 4 ) ;
for(; V_111 < V_114 ; V_111 ++ , V_69 ++ )
* V_111 += F_59 ( V_69 ) ;
}
static int F_60 ( struct V_4 * V_5 )
{
unsigned long V_117 , V_118 ;
T_2 V_119 ;
F_18 ( V_5 , V_92 , F_21 ( V_5 , V_92 ) | F_33 ( V_120 ) ) ;
V_118 = V_121 + F_61 ( V_122 ) ;
do {
V_117 = V_121 ;
V_119 = F_21 ( V_5 , V_123 ) ;
if ( ! ( V_119 & F_33 ( V_124 ) ) )
return 0 ;
F_62 ( 10 , 250 ) ;
} while ( F_63 ( V_117 , V_118 ) );
return - V_125 ;
}
static void F_64 ( struct V_4 * V_5 , struct V_7 * V_8 )
{
if ( V_8 -> V_126 ) {
if ( V_8 -> V_127 )
F_65 ( & V_5 -> V_31 -> V_17 , V_8 -> V_126 ,
V_8 -> V_128 , V_129 ) ;
else
F_66 ( & V_5 -> V_31 -> V_17 , V_8 -> V_126 ,
V_8 -> V_128 , V_129 ) ;
V_8 -> V_126 = 0 ;
}
if ( V_8 -> V_130 ) {
F_67 ( V_8 -> V_130 ) ;
V_8 -> V_130 = NULL ;
}
}
static void F_68 ( struct V_131 * V_132 )
{
struct V_4 * V_5 = F_69 ( V_132 , struct V_4 , V_133 ) ;
struct V_7 * V_8 ;
struct V_134 * V_130 ;
unsigned int V_135 ;
F_70 ( V_5 -> V_17 , L_13 ,
V_5 -> V_136 , V_5 -> V_137 ) ;
F_71 ( V_5 -> V_17 ) ;
if ( F_60 ( V_5 ) )
F_29 ( V_5 -> V_17 , L_14 ) ;
for ( V_135 = V_5 -> V_136 ; V_135 != V_5 -> V_137 ; V_135 ++ ) {
struct V_3 * V_138 ;
T_2 V_139 ;
V_138 = F_2 ( V_5 , V_135 ) ;
V_139 = V_138 -> V_139 ;
V_8 = V_7 ( V_5 , V_135 ) ;
V_130 = V_8 -> V_130 ;
if ( V_139 & F_33 ( V_140 ) ) {
while ( ! V_130 ) {
F_64 ( V_5 , V_8 ) ;
V_135 ++ ;
V_8 = V_7 ( V_5 , V_135 ) ;
V_130 = V_8 -> V_130 ;
}
if ( ! ( V_139 & F_33 ( V_141 ) ) ) {
F_70 ( V_5 -> V_17 , L_15 ,
F_1 ( V_135 ) , V_130 -> V_142 ) ;
V_5 -> V_143 . V_144 ++ ;
V_5 -> V_143 . V_145 += V_130 -> V_146 ;
}
} else {
if ( V_139 & F_33 ( V_141 ) )
F_29 ( V_5 -> V_17 ,
L_16 ) ;
V_138 -> V_139 = V_139 | F_33 ( V_140 ) ;
}
F_64 ( V_5 , V_8 ) ;
}
F_72 () ;
F_18 ( V_5 , V_147 , V_5 -> V_10 ) ;
V_5 -> V_137 = V_5 -> V_136 = 0 ;
F_73 ( V_5 -> V_17 ) ;
F_18 ( V_5 , V_123 , F_21 ( V_5 , V_123 ) ) ;
F_18 ( V_5 , V_148 , V_149 ) ;
}
static void F_74 ( struct V_4 * V_5 )
{
unsigned int V_135 ;
unsigned int V_150 ;
T_2 V_119 ;
V_119 = F_21 ( V_5 , V_123 ) ;
F_18 ( V_5 , V_123 , V_119 ) ;
if ( V_5 -> V_74 & V_151 )
F_18 ( V_5 , V_152 , F_33 ( V_153 ) ) ;
F_70 ( V_5 -> V_17 , L_17 ,
( unsigned long ) V_119 ) ;
V_150 = V_5 -> V_137 ;
for ( V_135 = V_5 -> V_136 ; V_135 != V_150 ; V_135 ++ ) {
struct V_7 * V_8 ;
struct V_134 * V_130 ;
struct V_3 * V_138 ;
T_2 V_139 ;
V_138 = F_2 ( V_5 , V_135 ) ;
F_75 () ;
V_139 = V_138 -> V_139 ;
if ( ! ( V_139 & F_33 ( V_140 ) ) )
break;
for (; ; V_135 ++ ) {
V_8 = V_7 ( V_5 , V_135 ) ;
V_130 = V_8 -> V_130 ;
if ( V_130 ) {
F_70 ( V_5 -> V_17 , L_18 ,
F_1 ( V_135 ) , V_130 -> V_142 ) ;
V_5 -> V_143 . V_144 ++ ;
V_5 -> V_143 . V_145 += V_130 -> V_146 ;
}
F_64 ( V_5 , V_8 ) ;
if ( V_130 )
break;
}
}
V_5 -> V_136 = V_135 ;
if ( F_76 ( V_5 -> V_17 )
&& F_77 ( V_5 -> V_137 , V_5 -> V_136 ,
V_2 ) <= V_154 )
F_73 ( V_5 -> V_17 ) ;
}
static void F_78 ( struct V_4 * V_5 )
{
unsigned int V_155 ;
struct V_134 * V_130 ;
T_1 V_156 ;
while ( F_79 ( V_5 -> V_157 , V_5 -> V_158 , V_11 ) > 0 ) {
V_155 = F_4 ( V_5 -> V_157 ) ;
F_75 () ;
V_5 -> V_157 ++ ;
if ( V_5 -> V_159 [ V_155 ] == NULL ) {
V_130 = F_80 ( V_5 -> V_17 , V_5 -> V_14 ) ;
if ( F_81 ( V_130 == NULL ) ) {
F_29 ( V_5 -> V_17 ,
L_19 ) ;
break;
}
V_156 = F_82 ( & V_5 -> V_31 -> V_17 , V_130 -> V_142 ,
V_5 -> V_14 , V_160 ) ;
if ( F_83 ( & V_5 -> V_31 -> V_17 , V_156 ) ) {
F_84 ( V_130 ) ;
break;
}
V_5 -> V_159 [ V_155 ] = V_130 ;
if ( V_155 == V_11 - 1 )
V_156 |= F_33 ( V_161 ) ;
V_5 -> V_12 [ V_155 ] . V_29 = V_156 ;
V_5 -> V_12 [ V_155 ] . V_139 = 0 ;
F_85 ( V_130 , V_162 ) ;
}
}
F_72 () ;
F_70 ( V_5 -> V_17 , L_20 ,
V_5 -> V_157 , V_5 -> V_158 ) ;
}
static void F_86 ( struct V_4 * V_5 , unsigned int V_163 ,
unsigned int V_114 )
{
unsigned int V_164 ;
for ( V_164 = V_163 ; V_164 != V_114 ; V_164 ++ ) {
struct V_3 * V_138 = F_5 ( V_5 , V_164 ) ;
V_138 -> V_29 &= ~ F_33 ( V_165 ) ;
}
F_72 () ;
}
static int F_87 ( struct V_4 * V_5 , int V_166 )
{
unsigned int V_146 ;
unsigned int V_155 ;
struct V_134 * V_130 ;
struct V_3 * V_138 ;
int V_167 = 0 ;
while ( V_167 < V_166 ) {
T_2 V_29 , V_139 ;
V_155 = F_4 ( V_5 -> V_158 ) ;
V_138 = & V_5 -> V_12 [ V_155 ] ;
F_75 () ;
V_29 = V_138 -> V_29 ;
V_139 = V_138 -> V_139 ;
if ( ! ( V_29 & F_33 ( V_165 ) ) )
break;
V_5 -> V_158 ++ ;
V_167 ++ ;
if ( ! ( V_139 & F_33 ( V_168 ) && V_139 & F_33 ( V_169 ) ) ) {
F_29 ( V_5 -> V_17 ,
L_21 ) ;
V_5 -> V_143 . V_170 ++ ;
break;
}
V_130 = V_5 -> V_159 [ V_155 ] ;
if ( F_81 ( ! V_130 ) ) {
F_29 ( V_5 -> V_17 ,
L_22 ) ;
V_5 -> V_143 . V_170 ++ ;
break;
}
V_5 -> V_159 [ V_155 ] = NULL ;
V_146 = F_20 ( V_171 , V_139 ) ;
F_70 ( V_5 -> V_17 , L_23 , V_155 , V_146 ) ;
F_88 ( V_130 , V_146 ) ;
V_29 = F_19 ( V_172 , F_20 ( V_172 , V_29 ) ) ;
F_66 ( & V_5 -> V_31 -> V_17 , V_29 ,
V_5 -> V_14 , V_160 ) ;
V_130 -> V_173 = F_89 ( V_130 , V_5 -> V_17 ) ;
F_90 ( V_130 ) ;
if ( V_5 -> V_17 -> V_174 & V_175 &&
! ( V_5 -> V_17 -> V_64 & V_176 ) &&
F_91 ( V_177 , V_139 ) & V_178 )
V_130 -> V_179 = V_180 ;
V_5 -> V_143 . V_181 ++ ;
V_5 -> V_143 . V_182 += V_130 -> V_146 ;
#if F_92 ( V_183 ) && F_92 ( V_184 )
F_70 ( V_5 -> V_17 , L_24 ,
V_130 -> V_146 , V_130 -> V_185 ) ;
F_93 ( V_186 , L_25 , V_187 , 16 , 1 ,
V_130 -> V_188 , 16 , true ) ;
F_93 ( V_186 , L_26 , V_187 , 16 , 1 ,
V_130 -> V_142 , 32 , true ) ;
#endif
F_94 ( V_130 ) ;
}
F_78 ( V_5 ) ;
return V_167 ;
}
static int F_95 ( struct V_4 * V_5 , unsigned int V_189 ,
unsigned int V_190 )
{
unsigned int V_146 ;
unsigned int V_164 ;
unsigned int V_9 ;
struct V_134 * V_130 ;
struct V_3 * V_138 ;
V_138 = F_5 ( V_5 , V_190 ) ;
V_146 = F_20 ( V_171 , V_138 -> V_139 ) ;
F_70 ( V_5 -> V_17 , L_27 ,
F_4 ( V_189 ) ,
F_4 ( V_190 ) , V_146 ) ;
V_130 = F_80 ( V_5 -> V_17 , V_146 + V_162 ) ;
if ( ! V_130 ) {
V_5 -> V_143 . V_170 ++ ;
for ( V_164 = V_189 ; ; V_164 ++ ) {
V_138 = F_5 ( V_5 , V_164 ) ;
V_138 -> V_29 &= ~ F_33 ( V_165 ) ;
if ( V_164 == V_190 )
break;
}
F_72 () ;
return 1 ;
}
V_9 = 0 ;
V_146 += V_162 ;
F_90 ( V_130 ) ;
F_88 ( V_130 , V_146 ) ;
for ( V_164 = V_189 ; ; V_164 ++ ) {
unsigned int V_191 = V_5 -> V_14 ;
if ( V_9 + V_191 > V_146 ) {
F_96 ( V_164 != V_190 ) ;
V_191 = V_146 - V_9 ;
}
F_97 ( V_130 , V_9 ,
F_6 ( V_5 , V_164 ) , V_191 ) ;
V_9 += V_5 -> V_14 ;
V_138 = F_5 ( V_5 , V_164 ) ;
V_138 -> V_29 &= ~ F_33 ( V_165 ) ;
if ( V_164 == V_190 )
break;
}
F_72 () ;
F_98 ( V_130 , V_162 ) ;
V_130 -> V_173 = F_89 ( V_130 , V_5 -> V_17 ) ;
V_5 -> V_143 . V_181 ++ ;
V_5 -> V_143 . V_182 += V_130 -> V_146 ;
F_70 ( V_5 -> V_17 , L_24 ,
V_130 -> V_146 , V_130 -> V_185 ) ;
F_94 ( V_130 ) ;
return 0 ;
}
static int F_99 ( struct V_4 * V_5 , int V_166 )
{
int V_192 = 0 ;
unsigned int V_135 ;
int V_189 = - 1 ;
for ( V_135 = V_5 -> V_158 ; V_166 > 0 ; V_135 ++ ) {
struct V_3 * V_138 = F_5 ( V_5 , V_135 ) ;
T_2 V_29 , V_139 ;
F_75 () ;
V_29 = V_138 -> V_29 ;
V_139 = V_138 -> V_139 ;
if ( ! ( V_29 & F_33 ( V_165 ) ) )
break;
if ( V_139 & F_33 ( V_168 ) ) {
if ( V_189 != - 1 )
F_86 ( V_5 , V_189 , V_135 ) ;
V_189 = V_135 ;
}
if ( V_139 & F_33 ( V_169 ) ) {
int V_193 ;
F_96 ( V_189 == - 1 ) ;
V_193 = F_95 ( V_5 , V_189 , V_135 ) ;
V_189 = - 1 ;
if ( ! V_193 ) {
V_192 ++ ;
V_166 -- ;
}
}
}
if ( V_189 != - 1 )
V_5 -> V_158 = V_189 ;
else
V_5 -> V_158 = V_135 ;
return V_192 ;
}
static int F_100 ( struct V_194 * V_195 , int V_166 )
{
struct V_4 * V_5 = F_69 ( V_195 , struct V_4 , V_195 ) ;
int V_196 ;
T_2 V_119 ;
V_119 = F_21 ( V_5 , V_197 ) ;
F_18 ( V_5 , V_197 , V_119 ) ;
V_196 = 0 ;
F_70 ( V_5 -> V_17 , L_28 ,
( unsigned long ) V_119 , V_166 ) ;
V_196 = V_5 -> V_198 . V_199 ( V_5 , V_166 ) ;
if ( V_196 < V_166 ) {
F_101 ( V_195 ) ;
V_119 = F_21 ( V_5 , V_197 ) ;
if ( V_119 ) {
if ( V_5 -> V_74 & V_151 )
F_18 ( V_5 , V_152 , F_33 ( V_200 ) ) ;
F_102 ( V_195 ) ;
} else {
F_18 ( V_5 , V_148 , V_201 ) ;
}
}
return V_196 ;
}
static T_6 F_103 ( int V_82 , void * V_202 )
{
struct V_54 * V_17 = V_202 ;
struct V_4 * V_5 = F_31 ( V_17 ) ;
T_2 V_119 ;
V_119 = F_21 ( V_5 , V_152 ) ;
if ( F_81 ( ! V_119 ) )
return V_203 ;
F_104 ( & V_5 -> V_66 ) ;
while ( V_119 ) {
if ( F_81 ( ! F_105 ( V_17 ) ) ) {
F_18 ( V_5 , V_204 , - 1 ) ;
break;
}
F_70 ( V_5 -> V_17 , L_29 , ( unsigned long ) V_119 ) ;
if ( V_119 & V_201 ) {
F_18 ( V_5 , V_204 , V_201 ) ;
if ( V_5 -> V_74 & V_151 )
F_18 ( V_5 , V_152 , F_33 ( V_200 ) ) ;
if ( F_106 ( & V_5 -> V_195 ) ) {
F_70 ( V_5 -> V_17 , L_30 ) ;
F_107 ( & V_5 -> V_195 ) ;
}
}
if ( F_81 ( V_119 & ( V_205 ) ) ) {
F_18 ( V_5 , V_204 , V_149 ) ;
F_108 ( & V_5 -> V_133 ) ;
if ( V_5 -> V_74 & V_151 )
F_18 ( V_5 , V_152 , V_205 ) ;
break;
}
if ( V_119 & F_33 ( V_153 ) )
F_74 ( V_5 ) ;
if ( V_119 & F_33 ( V_206 ) ) {
if ( F_34 ( V_5 ) )
V_5 -> V_112 . V_207 . V_208 ++ ;
else
V_5 -> V_112 . V_4 . V_208 ++ ;
if ( V_5 -> V_74 & V_151 )
F_18 ( V_5 , V_152 , F_33 ( V_206 ) ) ;
}
if ( V_119 & F_33 ( V_209 ) ) {
F_29 ( V_17 , L_31 ) ;
if ( V_5 -> V_74 & V_151 )
F_18 ( V_5 , V_152 , F_33 ( V_209 ) ) ;
}
V_119 = F_21 ( V_5 , V_152 ) ;
}
F_109 ( & V_5 -> V_66 ) ;
return V_210 ;
}
static void F_110 ( struct V_54 * V_17 )
{
unsigned long V_64 ;
F_111 ( V_64 ) ;
F_103 ( V_17 -> V_82 , V_17 ) ;
F_112 ( V_64 ) ;
}
static inline unsigned int F_113 ( struct V_4 * V_5 ,
unsigned int V_146 )
{
return ( V_146 + V_5 -> V_211 - 1 ) / V_5 -> V_211 ;
}
static unsigned int F_114 ( struct V_4 * V_5 ,
struct V_134 * V_130 )
{
T_1 V_126 ;
unsigned int V_146 , V_155 , V_30 , V_137 = V_5 -> V_137 ;
struct V_7 * V_8 = NULL ;
struct V_3 * V_138 ;
unsigned int V_9 , V_128 , V_167 = 0 ;
unsigned int V_212 , V_213 = F_115 ( V_130 ) -> V_213 ;
unsigned int V_214 = 1 ;
T_2 V_139 ;
V_146 = F_116 ( V_130 ) ;
V_9 = 0 ;
while ( V_146 ) {
V_128 = F_117 ( V_146 , V_5 -> V_211 ) ;
V_155 = F_1 ( V_137 ) ;
V_8 = & V_5 -> V_8 [ V_155 ] ;
V_126 = F_82 ( & V_5 -> V_31 -> V_17 ,
V_130 -> V_142 + V_9 ,
V_128 , V_129 ) ;
if ( F_83 ( & V_5 -> V_31 -> V_17 , V_126 ) )
goto V_215;
V_8 -> V_130 = NULL ;
V_8 -> V_126 = V_126 ;
V_8 -> V_128 = V_128 ;
V_8 -> V_127 = false ;
V_146 -= V_128 ;
V_9 += V_128 ;
V_167 ++ ;
V_137 ++ ;
}
for ( V_212 = 0 ; V_212 < V_213 ; V_212 ++ ) {
const T_7 * V_164 = & F_115 ( V_130 ) -> V_216 [ V_212 ] ;
V_146 = F_118 ( V_164 ) ;
V_9 = 0 ;
while ( V_146 ) {
V_128 = F_117 ( V_146 , V_5 -> V_211 ) ;
V_155 = F_1 ( V_137 ) ;
V_8 = & V_5 -> V_8 [ V_155 ] ;
V_126 = F_119 ( & V_5 -> V_31 -> V_17 , V_164 ,
V_9 , V_128 , V_129 ) ;
if ( F_83 ( & V_5 -> V_31 -> V_17 , V_126 ) )
goto V_215;
V_8 -> V_130 = NULL ;
V_8 -> V_126 = V_126 ;
V_8 -> V_128 = V_128 ;
V_8 -> V_127 = true ;
V_146 -= V_128 ;
V_9 += V_128 ;
V_167 ++ ;
V_137 ++ ;
}
}
if ( F_81 ( V_8 == NULL ) ) {
F_29 ( V_5 -> V_17 , L_32 ) ;
return 0 ;
}
V_8 -> V_130 = V_130 ;
V_30 = V_137 ;
V_155 = F_1 ( V_30 ) ;
V_139 = F_33 ( V_140 ) ;
V_138 = & V_5 -> V_6 [ V_155 ] ;
V_138 -> V_139 = V_139 ;
do {
V_30 -- ;
V_155 = F_1 ( V_30 ) ;
V_8 = & V_5 -> V_8 [ V_155 ] ;
V_138 = & V_5 -> V_6 [ V_155 ] ;
V_139 = ( T_2 ) V_8 -> V_128 ;
if ( V_214 ) {
V_139 |= F_33 ( V_217 ) ;
V_214 = 0 ;
}
if ( F_81 ( V_155 == ( V_2 - 1 ) ) )
V_139 |= F_33 ( V_218 ) ;
V_138 -> V_29 = V_8 -> V_126 ;
F_72 () ;
V_138 -> V_139 = V_139 ;
} while ( V_30 != V_5 -> V_137 );
V_5 -> V_137 = V_137 ;
return V_167 ;
V_215:
F_29 ( V_5 -> V_17 , L_33 ) ;
for ( V_30 = V_5 -> V_137 ; V_30 != V_137 ; V_30 ++ ) {
V_8 = V_7 ( V_5 , V_30 ) ;
F_64 ( V_5 , V_8 ) ;
}
return 0 ;
}
static int F_120 ( struct V_134 * V_130 , struct V_54 * V_17 )
{
struct V_4 * V_5 = F_31 ( V_17 ) ;
unsigned long V_64 ;
unsigned int V_167 , V_213 , V_219 , V_212 ;
#if F_92 ( V_183 ) && F_92 ( V_184 )
F_70 ( V_5 -> V_17 ,
L_34 ,
V_130 -> V_146 , V_130 -> V_150 , V_130 -> V_142 ,
F_121 ( V_130 ) , F_122 ( V_130 ) ) ;
F_93 ( V_186 , L_26 , V_220 , 16 , 1 ,
V_130 -> V_142 , 16 , true ) ;
#endif
V_167 = F_113 ( V_5 , F_116 ( V_130 ) ) ;
V_213 = F_115 ( V_130 ) -> V_213 ;
for ( V_212 = 0 ; V_212 < V_213 ; V_212 ++ ) {
V_219 = F_118 ( & F_115 ( V_130 ) -> V_216 [ V_212 ] ) ;
V_167 += F_113 ( V_5 , V_219 ) ;
}
F_32 ( & V_5 -> V_66 , V_64 ) ;
if ( F_79 ( V_5 -> V_137 , V_5 -> V_136 , V_2 ) < V_167 ) {
F_71 ( V_17 ) ;
F_36 ( & V_5 -> V_66 , V_64 ) ;
F_123 ( V_5 -> V_17 , L_35 ,
V_5 -> V_137 , V_5 -> V_136 ) ;
return V_221 ;
}
if ( ! F_114 ( V_5 , V_130 ) ) {
F_67 ( V_130 ) ;
goto V_222;
}
F_72 () ;
F_124 ( V_130 ) ;
F_18 ( V_5 , V_92 , F_21 ( V_5 , V_92 ) | F_33 ( V_223 ) ) ;
if ( F_79 ( V_5 -> V_137 , V_5 -> V_136 , V_2 ) < 1 )
F_71 ( V_17 ) ;
V_222:
F_36 ( & V_5 -> V_66 , V_64 ) ;
return V_224 ;
}
static void F_125 ( struct V_4 * V_5 , T_8 V_128 )
{
if ( ! F_34 ( V_5 ) ) {
V_5 -> V_14 = V_225 ;
} else {
V_5 -> V_14 = V_128 ;
if ( V_5 -> V_14 % V_226 ) {
F_123 ( V_5 -> V_17 ,
L_36 ,
V_226 ) ;
V_5 -> V_14 =
F_126 ( V_5 -> V_14 , V_226 ) ;
}
}
F_123 ( V_5 -> V_17 , L_37 ,
V_5 -> V_17 -> V_227 , V_5 -> V_14 ) ;
}
static void F_127 ( struct V_4 * V_5 )
{
struct V_134 * V_130 ;
struct V_3 * V_138 ;
T_1 V_29 ;
int V_30 ;
if ( ! V_5 -> V_159 )
return;
for ( V_30 = 0 ; V_30 < V_11 ; V_30 ++ ) {
V_130 = V_5 -> V_159 [ V_30 ] ;
if ( V_130 == NULL )
continue;
V_138 = & V_5 -> V_12 [ V_30 ] ;
V_29 = F_19 ( V_172 , F_20 ( V_172 , V_138 -> V_29 ) ) ;
F_66 ( & V_5 -> V_31 -> V_17 , V_29 , V_5 -> V_14 ,
V_160 ) ;
F_67 ( V_130 ) ;
V_130 = NULL ;
}
F_55 ( V_5 -> V_159 ) ;
V_5 -> V_159 = NULL ;
}
static void F_128 ( struct V_4 * V_5 )
{
if ( V_5 -> V_13 ) {
F_129 ( & V_5 -> V_31 -> V_17 ,
V_11 * V_5 -> V_14 ,
V_5 -> V_13 , V_5 -> V_228 ) ;
V_5 -> V_13 = NULL ;
}
}
static void F_130 ( struct V_4 * V_5 )
{
if ( V_5 -> V_8 ) {
F_55 ( V_5 -> V_8 ) ;
V_5 -> V_8 = NULL ;
}
V_5 -> V_198 . V_229 ( V_5 ) ;
if ( V_5 -> V_12 ) {
F_129 ( & V_5 -> V_31 -> V_17 , V_230 ,
V_5 -> V_12 , V_5 -> V_231 ) ;
V_5 -> V_12 = NULL ;
}
if ( V_5 -> V_6 ) {
F_129 ( & V_5 -> V_31 -> V_17 , V_232 ,
V_5 -> V_6 , V_5 -> V_10 ) ;
V_5 -> V_6 = NULL ;
}
}
static int F_131 ( struct V_4 * V_5 )
{
int V_128 ;
V_128 = V_11 * sizeof( struct V_134 * ) ;
V_5 -> V_159 = F_132 ( V_128 , V_103 ) ;
if ( ! V_5 -> V_159 )
return - V_94 ;
else
F_123 ( V_5 -> V_17 ,
L_38 ,
V_11 , V_5 -> V_159 ) ;
return 0 ;
}
static int F_133 ( struct V_4 * V_5 )
{
int V_128 ;
V_128 = V_11 * V_5 -> V_14 ;
V_5 -> V_13 = F_134 ( & V_5 -> V_31 -> V_17 , V_128 ,
& V_5 -> V_228 , V_103 ) ;
if ( ! V_5 -> V_13 )
return - V_94 ;
else
F_123 ( V_5 -> V_17 ,
L_39 ,
V_128 , ( unsigned long ) V_5 -> V_228 , V_5 -> V_13 ) ;
return 0 ;
}
static int F_135 ( struct V_4 * V_5 )
{
int V_128 ;
V_128 = V_2 * sizeof( struct V_7 ) ;
V_5 -> V_8 = F_48 ( V_128 , V_103 ) ;
if ( ! V_5 -> V_8 )
goto V_233;
V_128 = V_230 ;
V_5 -> V_12 = F_134 ( & V_5 -> V_31 -> V_17 , V_128 ,
& V_5 -> V_231 , V_103 ) ;
if ( ! V_5 -> V_12 )
goto V_233;
F_123 ( V_5 -> V_17 ,
L_40 ,
V_128 , ( unsigned long ) V_5 -> V_231 , V_5 -> V_12 ) ;
V_128 = V_232 ;
V_5 -> V_6 = F_134 ( & V_5 -> V_31 -> V_17 , V_128 ,
& V_5 -> V_10 , V_103 ) ;
if ( ! V_5 -> V_6 )
goto V_233;
F_123 ( V_5 -> V_17 ,
L_41 ,
V_128 , ( unsigned long ) V_5 -> V_10 , V_5 -> V_6 ) ;
if ( V_5 -> V_198 . V_234 ( V_5 ) )
goto V_233;
return 0 ;
V_233:
F_130 ( V_5 ) ;
return - V_94 ;
}
static void F_136 ( struct V_4 * V_5 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_2 ; V_30 ++ ) {
V_5 -> V_6 [ V_30 ] . V_29 = 0 ;
V_5 -> V_6 [ V_30 ] . V_139 = F_33 ( V_140 ) ;
}
V_5 -> V_6 [ V_2 - 1 ] . V_139 |= F_33 ( V_218 ) ;
V_5 -> V_158 = V_5 -> V_157 = V_5 -> V_137 = V_5 -> V_136 = 0 ;
F_78 ( V_5 ) ;
}
static void F_137 ( struct V_4 * V_5 )
{
int V_30 ;
T_1 V_29 ;
V_29 = V_5 -> V_228 ;
for ( V_30 = 0 ; V_30 < V_11 ; V_30 ++ ) {
V_5 -> V_12 [ V_30 ] . V_29 = V_29 ;
V_5 -> V_12 [ V_30 ] . V_139 = 0 ;
V_29 += V_5 -> V_14 ;
}
V_5 -> V_12 [ V_11 - 1 ] . V_29 |= F_33 ( V_161 ) ;
for ( V_30 = 0 ; V_30 < V_2 ; V_30 ++ ) {
V_5 -> V_6 [ V_30 ] . V_29 = 0 ;
V_5 -> V_6 [ V_30 ] . V_139 = F_33 ( V_140 ) ;
}
V_5 -> V_6 [ V_2 - 1 ] . V_139 |= F_33 ( V_218 ) ;
V_5 -> V_158 = V_5 -> V_137 = V_5 -> V_136 = 0 ;
}
static void F_138 ( struct V_4 * V_5 )
{
F_18 ( V_5 , V_92 , 0 ) ;
F_18 ( V_5 , V_92 , F_33 ( V_235 ) ) ;
F_18 ( V_5 , V_123 , - 1 ) ;
F_18 ( V_5 , V_197 , - 1 ) ;
F_18 ( V_5 , V_204 , - 1 ) ;
F_21 ( V_5 , V_152 ) ;
}
static T_2 F_139 ( struct V_4 * V_5 )
{
T_2 V_236 ;
unsigned long V_237 = F_140 ( V_5 -> V_238 ) ;
if ( V_237 <= 20000000 )
V_236 = F_141 ( V_239 , V_240 ) ;
else if ( V_237 <= 40000000 )
V_236 = F_141 ( V_239 , V_241 ) ;
else if ( V_237 <= 80000000 )
V_236 = F_141 ( V_239 , V_242 ) ;
else if ( V_237 <= 120000000 )
V_236 = F_141 ( V_239 , V_243 ) ;
else if ( V_237 <= 160000000 )
V_236 = F_141 ( V_239 , V_244 ) ;
else
V_236 = F_141 ( V_239 , V_245 ) ;
return V_236 ;
}
static T_2 F_142 ( struct V_4 * V_5 )
{
T_2 V_236 ;
unsigned long V_237 ;
if ( F_34 ( V_5 ) )
return F_139 ( V_5 ) ;
V_237 = F_140 ( V_5 -> V_238 ) ;
if ( V_237 <= 20000000 )
V_236 = F_19 ( V_239 , V_246 ) ;
else if ( V_237 <= 40000000 )
V_236 = F_19 ( V_239 , V_247 ) ;
else if ( V_237 <= 80000000 )
V_236 = F_19 ( V_239 , V_248 ) ;
else
V_236 = F_19 ( V_239 , V_249 ) ;
return V_236 ;
}
static T_2 F_143 ( struct V_4 * V_5 )
{
if ( ! F_34 ( V_5 ) )
return 0 ;
switch ( F_91 ( V_250 , F_144 ( V_5 , V_251 ) ) ) {
case 4 :
return F_141 ( V_252 , V_253 ) ;
case 2 :
return F_141 ( V_252 , V_254 ) ;
case 1 :
default:
return F_141 ( V_252 , V_255 ) ;
}
}
static void F_145 ( struct V_4 * V_5 )
{
T_2 V_256 ;
if ( F_34 ( V_5 ) ) {
V_256 = F_144 ( V_5 , V_257 ) & ~ F_141 ( V_258 , - 1L ) ;
V_256 |= F_141 ( V_258 , V_5 -> V_14 / V_226 ) ;
if ( V_5 -> V_259 )
V_256 = F_146 ( V_260 , V_5 -> V_259 , V_256 ) ;
V_256 |= F_35 ( V_261 ) | F_141 ( V_262 , - 1L ) ;
V_256 &= ~ F_35 ( V_263 ) ;
if ( V_5 -> V_17 -> V_174 & V_264 )
V_256 |= F_35 ( V_265 ) ;
else
V_256 &= ~ F_35 ( V_265 ) ;
F_123 ( V_5 -> V_17 , L_42 ,
V_256 ) ;
F_147 ( V_5 , V_257 , V_256 ) ;
}
}
static void F_148 ( struct V_4 * V_5 )
{
T_2 V_236 ;
F_138 ( V_5 ) ;
F_7 ( V_5 ) ;
V_236 = F_142 ( V_5 ) ;
V_236 |= F_19 ( V_266 , V_162 ) ;
V_236 |= F_33 ( V_267 ) ;
V_236 |= F_33 ( V_268 ) ;
V_236 |= F_33 ( V_269 ) ;
if ( V_5 -> V_17 -> V_64 & V_176 )
V_236 |= F_33 ( V_270 ) ;
else if ( F_34 ( V_5 ) && V_5 -> V_17 -> V_174 & V_175 )
V_236 |= F_35 ( V_271 ) ;
if ( ! ( V_5 -> V_17 -> V_64 & V_272 ) )
V_236 |= F_33 ( V_273 ) ;
V_236 |= F_143 ( V_5 ) ;
F_18 ( V_5 , V_70 , V_236 ) ;
V_5 -> V_53 = V_58 ;
V_5 -> V_68 = V_274 ;
F_145 ( V_5 ) ;
F_18 ( V_5 , V_275 , V_5 -> V_231 ) ;
F_18 ( V_5 , V_147 , V_5 -> V_10 ) ;
F_18 ( V_5 , V_92 , F_33 ( V_276 ) | F_33 ( V_277 ) | F_33 ( V_93 ) ) ;
F_18 ( V_5 , V_148 , ( V_201
| V_149
| F_33 ( V_209 ) ) ) ;
}
static inline int F_149 ( int V_278 , T_9 * V_29 )
{
if ( V_29 [ V_278 / 8 ] & ( 1 << ( V_278 % 8 ) ) )
return 1 ;
return 0 ;
}
static int F_150 ( T_9 * V_29 )
{
int V_30 , V_279 , V_280 ;
int V_281 = 0 ;
for ( V_279 = 0 ; V_279 < 6 ; V_279 ++ ) {
for ( V_30 = 0 , V_280 = 0 ; V_30 < 8 ; V_30 ++ )
V_280 ^= F_149 ( V_30 * 6 + V_279 , V_29 ) ;
V_281 |= ( V_280 << V_279 ) ;
}
return V_281 ;
}
static void F_151 ( struct V_54 * V_17 )
{
struct V_282 * V_283 ;
unsigned long V_284 [ 2 ] ;
unsigned int V_278 ;
struct V_4 * V_5 = F_31 ( V_17 ) ;
V_284 [ 0 ] = V_284 [ 1 ] = 0 ;
F_152 (ha, dev) {
V_278 = F_150 ( V_283 -> V_29 ) ;
V_284 [ V_278 >> 5 ] |= 1 << ( V_278 & 31 ) ;
}
F_9 ( V_5 , V_285 , V_284 [ 0 ] ) ;
F_9 ( V_5 , V_286 , V_284 [ 1 ] ) ;
}
void F_153 ( struct V_54 * V_17 )
{
unsigned long V_287 ;
struct V_4 * V_5 = F_31 ( V_17 ) ;
V_287 = F_21 ( V_5 , V_70 ) ;
if ( V_17 -> V_64 & V_176 ) {
V_287 |= F_33 ( V_270 ) ;
if ( F_34 ( V_5 ) )
V_287 &= ~ F_35 ( V_271 ) ;
} else {
V_287 &= ~ F_33 ( V_270 ) ;
if ( F_34 ( V_5 ) && V_17 -> V_174 & V_175 )
V_287 |= F_35 ( V_271 ) ;
}
if ( V_17 -> V_64 & V_288 ) {
F_9 ( V_5 , V_285 , - 1 ) ;
F_9 ( V_5 , V_286 , - 1 ) ;
V_287 |= F_33 ( V_289 ) ;
} else if ( ! F_154 ( V_17 ) ) {
F_151 ( V_17 ) ;
V_287 |= F_33 ( V_289 ) ;
} else if ( V_17 -> V_64 & ( ~ V_288 ) ) {
F_9 ( V_5 , V_285 , 0 ) ;
F_9 ( V_5 , V_286 , 0 ) ;
V_287 &= ~ F_33 ( V_289 ) ;
}
F_18 ( V_5 , V_70 , V_287 ) ;
}
static int F_155 ( struct V_54 * V_17 )
{
struct V_4 * V_5 = F_31 ( V_17 ) ;
T_8 V_290 = V_17 -> V_227 + V_291 + V_292 + V_162 ;
int V_91 ;
F_123 ( V_5 -> V_17 , L_43 ) ;
F_39 ( V_17 ) ;
if ( ! V_5 -> V_63 )
return - V_293 ;
F_125 ( V_5 , V_290 ) ;
V_91 = F_135 ( V_5 ) ;
if ( V_91 ) {
F_29 ( V_17 , L_44 ,
V_91 ) ;
return V_91 ;
}
F_156 ( & V_5 -> V_195 ) ;
V_5 -> V_198 . V_294 ( V_5 ) ;
F_148 ( V_5 ) ;
F_157 ( V_5 -> V_63 ) ;
F_158 ( V_17 ) ;
return 0 ;
}
static int F_159 ( struct V_54 * V_17 )
{
struct V_4 * V_5 = F_31 ( V_17 ) ;
unsigned long V_64 ;
F_71 ( V_17 ) ;
F_160 ( & V_5 -> V_195 ) ;
if ( V_5 -> V_63 )
F_161 ( V_5 -> V_63 ) ;
F_32 ( & V_5 -> V_66 , V_64 ) ;
F_138 ( V_5 ) ;
F_39 ( V_17 ) ;
F_36 ( & V_5 -> V_66 , V_64 ) ;
F_130 ( V_5 ) ;
return 0 ;
}
static void F_162 ( struct V_4 * V_5 )
{
T_2 T_5 * V_69 = V_5 -> V_109 + V_295 ;
T_2 * V_111 = & V_5 -> V_112 . V_207 . V_296 ;
T_2 * V_114 = & V_5 -> V_112 . V_207 . V_297 + 1 ;
for (; V_111 < V_114 ; V_111 ++ , V_69 ++ )
* V_111 += F_59 ( V_69 ) ;
}
static struct V_298 * F_163 ( struct V_4 * V_5 )
{
struct V_299 * V_300 = & V_5 -> V_112 . V_207 ;
struct V_298 * V_301 = & V_5 -> V_143 ;
F_162 ( V_5 ) ;
V_301 -> V_302 = ( V_300 -> V_303 +
V_300 -> V_304 +
V_300 -> V_305 +
V_300 -> V_208 +
V_300 -> V_306 +
V_300 -> V_307 +
V_300 -> V_308 +
V_300 -> V_309 ) ;
V_301 -> V_310 = ( V_300 -> V_311 +
V_300 -> V_312 +
V_300 -> V_313 +
V_300 -> V_314 ) ;
V_301 -> V_315 = V_300 -> V_316 ;
V_301 -> V_317 = ( V_300 -> V_318 +
V_300 -> V_319 +
V_300 -> V_312 ) ;
V_301 -> V_320 = ( V_300 -> V_306 +
V_300 -> V_307 +
V_300 -> V_308 +
V_300 -> V_309 ) ;
V_301 -> V_321 = V_300 -> V_305 ;
V_301 -> V_322 = V_300 -> V_303 ;
V_301 -> V_323 = V_300 -> V_304 ;
V_301 -> V_324 = V_300 -> V_208 ;
V_301 -> V_325 = V_300 -> V_312 ;
V_301 -> V_326 = V_300 -> V_314 ;
V_301 -> V_327 = V_300 -> V_313 ;
return V_301 ;
}
struct V_298 * F_164 ( struct V_54 * V_17 )
{
struct V_4 * V_5 = F_31 ( V_17 ) ;
struct V_298 * V_301 = & V_5 -> V_143 ;
struct V_328 * V_300 = & V_5 -> V_112 . V_4 ;
if ( F_34 ( V_5 ) )
return F_163 ( V_5 ) ;
F_57 ( V_5 ) ;
V_301 -> V_302 = ( V_300 -> V_329 +
V_300 -> V_330 +
V_300 -> V_305 +
V_300 -> V_208 +
V_300 -> V_331 +
V_300 -> V_307 +
V_300 -> V_332 +
V_300 -> V_333 +
V_300 -> V_334 ) ;
V_301 -> V_310 = ( V_300 -> V_335 +
V_300 -> V_336 +
V_300 -> V_337 +
V_300 -> V_326 ) ;
V_301 -> V_317 = ( V_300 -> V_338 +
V_300 -> V_339 +
V_300 -> V_336 ) ;
V_301 -> V_320 = ( V_300 -> V_331 +
V_300 -> V_307 +
V_300 -> V_332 +
V_300 -> V_334 ) ;
V_301 -> V_321 = V_300 -> V_305 +
V_300 -> V_208 ;
V_301 -> V_322 = V_300 -> V_329 ;
V_301 -> V_323 = V_300 -> V_330 ;
V_301 -> V_324 = V_300 -> V_208 ;
V_301 -> V_325 = V_300 -> V_336 ;
V_301 -> V_326 = V_300 -> V_326 ;
V_301 -> V_327 = V_300 -> V_337 ;
return V_301 ;
}
static int F_165 ( struct V_54 * V_17 , struct V_340 * V_341 )
{
struct V_4 * V_5 = F_31 ( V_17 ) ;
struct V_61 * V_62 = V_5 -> V_63 ;
if ( ! V_62 )
return - V_342 ;
return F_166 ( V_62 , V_341 ) ;
}
static int F_167 ( struct V_54 * V_17 , struct V_340 * V_341 )
{
struct V_4 * V_5 = F_31 ( V_17 ) ;
struct V_61 * V_62 = V_5 -> V_63 ;
if ( ! V_62 )
return - V_342 ;
return F_168 ( V_62 , V_341 ) ;
}
static int F_169 ( struct V_54 * V_343 )
{
return V_344 * sizeof( T_2 ) ;
}
static void F_170 ( struct V_54 * V_17 , struct V_345 * V_109 ,
void * V_111 )
{
struct V_4 * V_5 = F_31 ( V_17 ) ;
unsigned int V_135 , V_150 ;
T_2 * V_346 = V_111 ;
V_109 -> V_347 = ( F_21 ( V_5 , V_348 ) & ( ( 1 << V_349 ) - 1 ) )
| V_350 ;
V_135 = F_1 ( V_5 -> V_136 ) ;
V_150 = F_1 ( V_5 -> V_137 ) ;
V_346 [ 0 ] = F_21 ( V_5 , V_92 ) ;
V_346 [ 1 ] = F_13 ( V_5 , V_70 ) ;
V_346 [ 2 ] = F_21 ( V_5 , V_49 ) ;
V_346 [ 3 ] = F_21 ( V_5 , V_123 ) ;
V_346 [ 4 ] = F_21 ( V_5 , V_275 ) ;
V_346 [ 5 ] = F_21 ( V_5 , V_147 ) ;
V_346 [ 6 ] = F_21 ( V_5 , V_197 ) ;
V_346 [ 7 ] = F_21 ( V_5 , V_351 ) ;
V_346 [ 8 ] = V_135 ;
V_346 [ 9 ] = V_150 ;
V_346 [ 10 ] = F_3 ( V_5 , V_135 ) ;
V_346 [ 11 ] = F_3 ( V_5 , V_150 ) ;
if ( F_34 ( V_5 ) ) {
V_346 [ 12 ] = F_144 ( V_5 , V_352 ) ;
V_346 [ 13 ] = F_144 ( V_5 , V_257 ) ;
}
}
int F_171 ( struct V_54 * V_17 , struct V_353 * V_354 , int V_341 )
{
struct V_4 * V_5 = F_31 ( V_17 ) ;
struct V_61 * V_62 = V_5 -> V_63 ;
if ( ! F_105 ( V_17 ) )
return - V_355 ;
if ( ! V_62 )
return - V_342 ;
return F_172 ( V_62 , V_354 , V_341 ) ;
}
static int F_173 ( struct V_54 * V_343 ,
T_10 V_174 )
{
struct V_4 * V_5 = F_31 ( V_343 ) ;
T_10 V_356 = V_174 ^ V_343 -> V_174 ;
if ( ( V_356 & V_264 ) && F_34 ( V_5 ) ) {
T_2 V_256 ;
V_256 = F_144 ( V_5 , V_257 ) ;
if ( V_174 & V_264 )
V_256 |= F_35 ( V_265 ) ;
else
V_256 &= ~ F_35 ( V_265 ) ;
F_147 ( V_5 , V_257 , V_256 ) ;
}
if ( ( V_356 & V_175 ) && F_34 ( V_5 ) ) {
T_2 V_357 ;
V_357 = F_144 ( V_5 , V_70 ) ;
if ( V_174 & V_175 &&
! ( V_343 -> V_64 & V_176 ) )
V_357 |= F_35 ( V_271 ) ;
else
V_357 &= ~ F_35 ( V_271 ) ;
F_147 ( V_5 , V_70 , V_357 ) ;
}
return 0 ;
}
static void F_174 ( struct V_4 * V_5 )
{
T_2 V_358 ;
const struct V_359 * V_360 ;
const struct V_361 * V_236 ;
if ( V_5 -> V_31 -> V_17 . V_105 ) {
V_360 = F_175 ( V_362 , V_5 -> V_31 -> V_17 . V_105 ) ;
if ( V_360 && V_360 -> V_142 ) {
V_236 = ( const struct V_361 * ) V_360 -> V_142 ;
V_5 -> V_74 = V_236 -> V_74 ;
V_5 -> V_259 = V_236 -> V_259 ;
}
}
if ( F_20 ( V_363 , F_21 ( V_5 , V_348 ) ) == 0x2 )
V_5 -> V_74 |= V_364 ;
if ( F_34 ( V_5 ) ) {
V_358 = F_144 ( V_5 , V_251 ) ;
if ( F_91 ( V_365 , V_358 ) == 0 )
V_5 -> V_74 |= V_151 ;
V_358 = F_144 ( V_5 , V_366 ) ;
if ( ( V_358 & ( F_35 ( V_367 ) | F_35 ( V_368 ) ) ) == 0 )
V_5 -> V_74 |= V_369 ;
}
F_123 ( V_5 -> V_17 , L_45 , V_5 -> V_74 ) ;
}
static int T_11 F_176 ( struct V_370 * V_31 )
{
struct V_27 * V_28 ;
struct V_371 * V_109 ;
struct V_54 * V_17 ;
struct V_4 * V_5 ;
struct V_61 * V_62 ;
T_2 V_236 ;
int V_91 = - V_80 ;
const char * V_372 ;
V_109 = F_177 ( V_31 , V_373 , 0 ) ;
if ( ! V_109 ) {
F_178 ( & V_31 -> V_17 , L_46 ) ;
goto V_95;
}
V_91 = - V_94 ;
V_17 = F_179 ( sizeof( * V_5 ) ) ;
if ( ! V_17 )
goto V_95;
F_180 ( V_17 , & V_31 -> V_17 ) ;
V_5 = F_31 ( V_17 ) ;
V_5 -> V_31 = V_31 ;
V_5 -> V_17 = V_17 ;
F_181 ( & V_5 -> V_66 ) ;
F_182 ( & V_5 -> V_133 , F_68 ) ;
V_5 -> V_238 = F_183 ( & V_31 -> V_17 , L_47 ) ;
if ( F_37 ( V_5 -> V_238 ) ) {
V_91 = F_52 ( V_5 -> V_238 ) ;
F_178 ( & V_31 -> V_17 , L_48 , V_91 ) ;
goto V_374;
}
V_5 -> V_375 = F_183 ( & V_31 -> V_17 , L_49 ) ;
if ( F_37 ( V_5 -> V_375 ) ) {
V_91 = F_52 ( V_5 -> V_375 ) ;
F_178 ( & V_31 -> V_17 , L_50 , V_91 ) ;
goto V_374;
}
V_5 -> V_76 = F_183 ( & V_31 -> V_17 , L_51 ) ;
V_91 = F_184 ( V_5 -> V_238 ) ;
if ( V_91 ) {
F_178 ( & V_31 -> V_17 , L_52 , V_91 ) ;
goto V_374;
}
V_91 = F_184 ( V_5 -> V_375 ) ;
if ( V_91 ) {
F_178 ( & V_31 -> V_17 , L_53 , V_91 ) ;
goto V_376;
}
if ( ! F_37 ( V_5 -> V_76 ) ) {
V_91 = F_184 ( V_5 -> V_76 ) ;
if ( V_91 ) {
F_178 ( & V_31 -> V_17 , L_54 ,
V_91 ) ;
goto V_377;
}
}
V_5 -> V_109 = F_185 ( & V_31 -> V_17 , V_109 -> V_378 , F_186 ( V_109 ) ) ;
if ( ! V_5 -> V_109 ) {
F_178 ( & V_31 -> V_17 , L_55 ) ;
V_91 = - V_94 ;
goto V_379;
}
V_17 -> V_82 = F_187 ( V_31 , 0 ) ;
V_91 = F_188 ( & V_31 -> V_17 , V_17 -> V_82 , F_103 , 0 ,
V_17 -> V_96 , V_17 ) ;
if ( V_91 ) {
F_178 ( & V_31 -> V_17 , L_56 ,
V_17 -> V_82 , V_91 ) ;
goto V_379;
}
V_17 -> V_380 = & V_381 ;
F_189 ( V_17 , & V_5 -> V_195 , F_100 , 64 ) ;
V_17 -> V_382 = & V_383 ;
V_17 -> V_384 = V_109 -> V_378 ;
F_174 ( V_5 ) ;
if ( F_34 ( V_5 ) ) {
V_5 -> V_211 = V_385 ;
V_5 -> V_198 . V_234 = F_131 ;
V_5 -> V_198 . V_229 = F_127 ;
V_5 -> V_198 . V_294 = F_136 ;
V_5 -> V_198 . V_199 = F_87 ;
} else {
V_5 -> V_211 = V_386 ;
V_5 -> V_198 . V_234 = F_133 ;
V_5 -> V_198 . V_229 = F_128 ;
V_5 -> V_198 . V_294 = F_137 ;
V_5 -> V_198 . V_199 = F_99 ;
}
V_17 -> V_387 = V_388 ;
if ( F_34 ( V_5 ) && ! ( V_5 -> V_74 & V_369 ) )
V_17 -> V_387 |= V_264 | V_175 ;
if ( V_5 -> V_74 & V_389 )
V_17 -> V_387 &= ~ V_388 ;
V_17 -> V_174 = V_17 -> V_387 ;
V_236 = F_142 ( V_5 ) ;
V_236 |= F_143 ( V_5 ) ;
F_18 ( V_5 , V_70 , V_236 ) ;
V_372 = F_190 ( V_31 -> V_17 . V_105 ) ;
if ( V_372 )
memcpy ( V_5 -> V_17 -> V_18 , V_372 , V_390 ) ;
else
F_11 ( V_5 ) ;
V_91 = F_191 ( V_31 -> V_17 . V_105 ) ;
if ( V_91 < 0 ) {
V_28 = F_12 ( & V_31 -> V_17 ) ;
if ( V_28 && V_28 -> V_391 )
V_5 -> V_84 = V_392 ;
else
V_5 -> V_84 = V_393 ;
} else {
V_5 -> V_84 = V_91 ;
}
if ( V_5 -> V_84 == V_394 )
F_9 ( V_5 , V_352 , F_35 ( V_395 ) ) ;
else if ( V_5 -> V_84 == V_392 )
#if F_92 ( V_396 )
F_9 ( V_5 , V_352 , ( F_33 ( V_397 ) |
F_33 ( V_398 ) ) ) ;
#else
F_9 ( V_5 , V_352 , 0 ) ;
#endif
else
#if F_92 ( V_396 )
F_9 ( V_5 , V_352 , F_33 ( V_398 ) ) ;
#else
F_9 ( V_5 , V_352 , F_33 ( V_399 ) ) ;
#endif
V_91 = F_192 ( V_17 ) ;
if ( V_91 ) {
F_178 ( & V_31 -> V_17 , L_57 ) ;
goto V_379;
}
V_91 = F_46 ( V_5 ) ;
if ( V_91 )
goto V_400;
F_193 ( V_31 , V_17 ) ;
F_39 ( V_17 ) ;
F_15 ( V_17 , L_58 ,
F_34 ( V_5 ) ? L_59 : L_60 , F_21 ( V_5 , V_348 ) ,
V_17 -> V_384 , V_17 -> V_82 , V_17 -> V_18 ) ;
V_62 = V_5 -> V_63 ;
F_15 ( V_17 , L_61 ,
V_62 -> V_401 -> V_96 , F_194 ( & V_62 -> V_17 ) , V_62 -> V_82 ) ;
return 0 ;
V_400:
F_195 ( V_17 ) ;
V_379:
if ( ! F_37 ( V_5 -> V_76 ) )
F_196 ( V_5 -> V_76 ) ;
V_377:
F_196 ( V_5 -> V_375 ) ;
V_376:
F_196 ( V_5 -> V_238 ) ;
V_374:
F_197 ( V_17 ) ;
V_95:
return V_91 ;
}
static int T_12 F_198 ( struct V_370 * V_31 )
{
struct V_54 * V_17 ;
struct V_4 * V_5 ;
V_17 = F_199 ( V_31 ) ;
if ( V_17 ) {
V_5 = F_31 ( V_17 ) ;
if ( V_5 -> V_63 )
F_200 ( V_5 -> V_63 ) ;
F_54 ( V_5 -> V_33 ) ;
F_55 ( V_5 -> V_33 -> V_82 ) ;
F_56 ( V_5 -> V_33 ) ;
F_195 ( V_17 ) ;
if ( ! F_37 ( V_5 -> V_76 ) )
F_196 ( V_5 -> V_76 ) ;
F_196 ( V_5 -> V_375 ) ;
F_196 ( V_5 -> V_238 ) ;
F_197 ( V_17 ) ;
}
return 0 ;
}
static int F_201 ( struct V_402 * V_17 )
{
struct V_370 * V_31 = F_202 ( V_17 ) ;
struct V_54 * V_343 = F_199 ( V_31 ) ;
struct V_4 * V_5 = F_31 ( V_343 ) ;
F_39 ( V_343 ) ;
F_203 ( V_343 ) ;
if ( ! F_37 ( V_5 -> V_76 ) )
F_196 ( V_5 -> V_76 ) ;
F_196 ( V_5 -> V_375 ) ;
F_196 ( V_5 -> V_238 ) ;
return 0 ;
}
static int F_204 ( struct V_402 * V_17 )
{
struct V_370 * V_31 = F_202 ( V_17 ) ;
struct V_54 * V_343 = F_199 ( V_31 ) ;
struct V_4 * V_5 = F_31 ( V_343 ) ;
F_184 ( V_5 -> V_238 ) ;
F_184 ( V_5 -> V_375 ) ;
if ( ! F_37 ( V_5 -> V_76 ) )
F_184 ( V_5 -> V_76 ) ;
F_205 ( V_343 ) ;
return 0 ;
}
