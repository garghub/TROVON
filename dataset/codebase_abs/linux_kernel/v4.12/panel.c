static void F_1 ( unsigned int V_1 , int * V_2 )
{
unsigned int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
V_4 = F_2 ( V_3 , V_6 ) ? V_7 : V_8 ;
* V_2 &= V_9 [ V_1 ] [ V_3 ] [ V_10 ] ;
* V_2 |= V_9 [ V_1 ] [ V_3 ] [ V_4 ] ;
}
}
static int F_3 ( void )
{
int V_2 ;
V_2 = F_4 ( V_11 ) ;
F_1 ( V_12 , & V_2 ) ;
F_5 ( V_11 , V_2 ) ;
return V_2 ;
}
static int F_6 ( void )
{
int V_2 ;
V_2 = F_7 ( V_11 ) ;
F_1 ( V_13 , & V_2 ) ;
F_8 ( V_11 , V_2 ) ;
return V_2 ;
}
static void F_9 ( void )
{
F_3 () ;
F_6 () ;
}
static void F_10 ( int V_14 , unsigned char * V_15 , unsigned char * V_16 )
{
int V_17 , V_18 , V_19 ;
V_15 [ 0 ] = 0 ;
V_16 [ 0 ] = 0 ;
V_15 [ 1 ] = 0 ;
V_16 [ 1 ] = 0 ;
V_15 [ 2 ] = 0xFF ;
V_16 [ 2 ] = 0xFF ;
if ( V_14 == 0 )
return;
V_19 = ( V_14 < 0 ) ;
if ( V_19 )
V_14 = - V_14 ;
V_17 = 0 ;
V_18 = 0 ;
switch ( V_14 ) {
case V_20 :
V_18 = V_21 ;
V_19 = ! V_19 ;
break;
case V_22 ... V_23 :
V_17 = 1 << ( V_14 - 2 ) ;
break;
case V_24 :
V_18 = V_25 ;
V_19 = ! V_19 ;
break;
case V_26 :
V_18 = V_27 ;
break;
case V_28 :
V_18 = V_29 ;
V_19 = ! V_19 ;
break;
default:
break;
}
if ( V_18 ) {
V_16 [ 2 ] &= ~ V_18 ;
V_16 [ ! V_19 ] = V_18 ;
} else if ( V_17 ) {
V_15 [ 2 ] &= ~ V_17 ;
V_15 [ ! V_19 ] = V_17 ;
}
}
static void F_11 ( int V_30 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
F_12 ( V_31 , V_6 ) ;
F_9 () ;
if ( V_30 & 1 ) {
F_13 ( V_32 , V_6 ) ;
} else {
F_12 ( V_32 , V_6 ) ;
}
F_9 () ;
F_14 ( 2 ) ;
F_13 ( V_31 , V_6 ) ;
F_9 () ;
F_14 ( 1 ) ;
V_30 >>= 1 ;
}
}
static void F_15 ( struct V_33 * V_33 , int V_34 )
{
if ( V_35 . V_36 . V_37 == V_38 )
return;
F_16 ( & V_39 ) ;
if ( V_34 )
F_13 ( V_40 , V_6 ) ;
else
F_12 ( V_40 , V_6 ) ;
F_9 () ;
F_17 ( & V_39 ) ;
}
static void F_18 ( struct V_33 * V_33 , int V_41 )
{
F_16 ( & V_39 ) ;
F_11 ( 0x1F ) ;
F_11 ( V_41 & 0x0F ) ;
F_11 ( ( V_41 >> 4 ) & 0x0F ) ;
F_14 ( 40 ) ;
F_17 ( & V_39 ) ;
}
static void F_19 ( struct V_33 * V_33 , int V_42 )
{
F_16 ( & V_39 ) ;
F_11 ( 0x5F ) ;
F_11 ( V_42 & 0x0F ) ;
F_11 ( ( V_42 >> 4 ) & 0x0F ) ;
F_14 ( 40 ) ;
F_17 ( & V_39 ) ;
}
static void F_20 ( struct V_33 * V_33 , int V_41 )
{
F_16 ( & V_39 ) ;
F_5 ( V_11 , V_41 ) ;
F_14 ( 20 ) ;
F_13 ( V_43 , V_6 ) ;
F_12 ( V_44 , V_6 ) ;
F_12 ( V_45 , V_6 ) ;
F_6 () ;
F_14 ( 40 ) ;
F_12 ( V_43 , V_6 ) ;
F_6 () ;
F_14 ( 120 ) ;
F_17 ( & V_39 ) ;
}
static void F_21 ( struct V_33 * V_33 , int V_42 )
{
F_16 ( & V_39 ) ;
F_5 ( V_11 , V_42 ) ;
F_14 ( 20 ) ;
F_13 ( V_43 , V_6 ) ;
F_13 ( V_44 , V_6 ) ;
F_12 ( V_45 , V_6 ) ;
F_6 () ;
F_14 ( 40 ) ;
F_12 ( V_43 , V_6 ) ;
F_6 () ;
F_14 ( 45 ) ;
F_17 ( & V_39 ) ;
}
static void F_22 ( struct V_33 * V_33 , int V_41 )
{
F_16 ( & V_39 ) ;
F_8 ( V_11 , V_41 ) ;
F_14 ( 60 ) ;
F_17 ( & V_39 ) ;
}
static void F_23 ( struct V_33 * V_33 , int V_42 )
{
F_16 ( & V_39 ) ;
F_5 ( V_11 , V_42 ) ;
F_14 ( 60 ) ;
F_17 ( & V_39 ) ;
}
static void F_24 ( struct V_33 * V_33 )
{
int V_46 ;
F_16 ( & V_39 ) ;
for ( V_46 = 0 ; V_46 < V_33 -> V_47 * V_33 -> V_48 ; V_46 ++ ) {
F_11 ( 0x5F ) ;
F_11 ( ' ' & 0x0F ) ;
F_11 ( ( ' ' >> 4 ) & 0x0F ) ;
F_14 ( 40 ) ;
}
F_17 ( & V_39 ) ;
}
static void F_25 ( struct V_33 * V_33 )
{
int V_46 ;
F_16 ( & V_39 ) ;
for ( V_46 = 0 ; V_46 < V_33 -> V_47 * V_33 -> V_48 ; V_46 ++ ) {
F_5 ( V_11 , ' ' ) ;
F_14 ( 20 ) ;
F_13 ( V_43 , V_6 ) ;
F_13 ( V_44 , V_6 ) ;
F_12 ( V_45 , V_6 ) ;
F_6 () ;
F_14 ( 40 ) ;
F_12 ( V_43 , V_6 ) ;
F_6 () ;
F_14 ( 45 ) ;
}
F_17 ( & V_39 ) ;
}
static void F_26 ( struct V_33 * V_33 )
{
int V_46 ;
F_16 ( & V_39 ) ;
for ( V_46 = 0 ; V_46 < V_33 -> V_47 * V_33 -> V_48 ; V_46 ++ ) {
F_5 ( V_11 , ' ' ) ;
F_14 ( 60 ) ;
}
F_17 ( & V_39 ) ;
}
static void F_27 ( void )
{
struct V_33 * V_33 ;
V_33 = F_28 ( 0 ) ;
if ( ! V_33 )
return;
V_33 -> V_47 = V_49 ;
V_33 -> V_50 = V_51 ;
V_33 -> V_52 = V_53 ;
V_33 -> V_48 = V_54 ;
switch ( V_55 ) {
case V_56 :
V_35 . V_57 = V_58 ;
V_35 . V_59 = V_60 ;
V_35 . V_36 . V_61 = V_20 ;
V_35 . V_36 . V_62 = V_24 ;
V_33 -> V_50 = 40 ;
V_33 -> V_52 = 40 ;
V_33 -> V_48 = 64 ;
V_33 -> V_47 = 2 ;
break;
case V_63 :
V_35 . V_57 = V_64 ;
V_35 . V_59 = V_65 ;
V_35 . V_36 . V_37 = V_24 ;
V_35 . V_36 . V_66 = V_20 ;
V_35 . V_36 . V_67 = V_22 ;
V_33 -> V_50 = 16 ;
V_33 -> V_52 = 40 ;
V_33 -> V_48 = 16 ;
V_33 -> V_47 = 2 ;
break;
case V_68 :
V_35 . V_57 = V_58 ;
V_35 . V_59 = V_60 ;
V_35 . V_36 . V_61 = V_24 ;
V_35 . V_36 . V_62 = V_28 ;
V_35 . V_36 . V_69 = V_26 ;
V_33 -> V_50 = 16 ;
V_33 -> V_52 = 40 ;
V_33 -> V_48 = 64 ;
V_33 -> V_47 = 2 ;
break;
case V_70 :
V_35 . V_57 = V_71 ;
V_35 . V_59 = V_72 ;
break;
case V_73 :
default:
V_35 . V_57 = V_58 ;
V_35 . V_59 = V_60 ;
V_35 . V_36 . V_61 = V_20 ;
V_35 . V_36 . V_62 = V_28 ;
V_33 -> V_50 = 16 ;
V_33 -> V_52 = 40 ;
V_33 -> V_48 = 64 ;
V_33 -> V_47 = 2 ;
break;
}
if ( V_49 != V_74 )
V_33 -> V_47 = V_49 ;
if ( V_51 != V_74 )
V_33 -> V_50 = V_51 ;
if ( V_53 != V_74 )
V_33 -> V_52 = V_53 ;
if ( V_54 != V_74 )
V_33 -> V_48 = V_54 ;
if ( V_75 != V_74 )
V_35 . V_59 = V_75 ;
if ( V_76 != V_74 )
V_35 . V_57 = V_76 ;
if ( V_77 != V_78 )
V_35 . V_36 . V_61 = V_77 ;
if ( V_79 != V_78 )
V_35 . V_36 . V_62 = V_79 ;
if ( V_80 != V_78 )
V_35 . V_36 . V_69 = V_80 ;
if ( V_81 != V_78 )
V_35 . V_36 . V_66 = V_81 ;
if ( V_82 != V_78 )
V_35 . V_36 . V_67 = V_82 ;
if ( V_83 != V_78 )
V_35 . V_36 . V_37 = V_83 ;
if ( V_33 -> V_50 <= 0 )
V_33 -> V_50 = V_84 ;
if ( V_33 -> V_52 <= 0 )
V_33 -> V_52 = V_85 ;
if ( V_33 -> V_48 <= 0 )
V_33 -> V_48 = V_86 ;
if ( V_33 -> V_47 <= 0 )
V_33 -> V_47 = V_87 ;
if ( V_35 . V_57 == V_64 ) {
V_33 -> V_88 = & V_89 ;
if ( V_35 . V_36 . V_66 == V_78 )
V_35 . V_36 . V_66 = V_90 ;
if ( V_35 . V_36 . V_67 == V_78 )
V_35 . V_36 . V_67 = V_91 ;
} else if ( V_35 . V_57 == V_58 ) {
V_33 -> V_88 = & V_92 ;
if ( V_35 . V_36 . V_61 == V_78 )
V_35 . V_36 . V_61 = V_93 ;
if ( V_35 . V_36 . V_62 == V_78 )
V_35 . V_36 . V_62 = V_94 ;
if ( V_35 . V_36 . V_69 == V_78 )
V_35 . V_36 . V_69 = V_95 ;
} else {
V_33 -> V_88 = & V_96 ;
}
if ( V_35 . V_36 . V_37 == V_78 )
V_35 . V_36 . V_37 = V_97 ;
if ( V_35 . V_36 . V_61 == V_78 )
V_35 . V_36 . V_61 = V_38 ;
if ( V_35 . V_36 . V_62 == V_78 )
V_35 . V_36 . V_62 = V_38 ;
if ( V_35 . V_36 . V_69 == V_78 )
V_35 . V_36 . V_69 = V_38 ;
if ( V_35 . V_36 . V_37 == V_78 )
V_35 . V_36 . V_37 = V_38 ;
if ( V_35 . V_36 . V_66 == V_78 )
V_35 . V_36 . V_66 = V_38 ;
if ( V_35 . V_36 . V_67 == V_78 )
V_35 . V_36 . V_67 = V_38 ;
if ( V_35 . V_59 == V_74 )
V_35 . V_59 = V_72 ;
if ( V_35 . V_59 == V_65 )
V_33 -> V_98 = V_99 ;
else
V_33 -> V_98 = NULL ;
F_10 ( V_35 . V_36 . V_61 , V_9 [ V_12 ] [ V_43 ] ,
V_9 [ V_13 ] [ V_43 ] ) ;
F_10 ( V_35 . V_36 . V_62 , V_9 [ V_12 ] [ V_44 ] ,
V_9 [ V_13 ] [ V_44 ] ) ;
F_10 ( V_35 . V_36 . V_69 , V_9 [ V_12 ] [ V_45 ] ,
V_9 [ V_13 ] [ V_45 ] ) ;
F_10 ( V_35 . V_36 . V_37 , V_9 [ V_12 ] [ V_40 ] ,
V_9 [ V_13 ] [ V_40 ] ) ;
F_10 ( V_35 . V_36 . V_66 , V_9 [ V_12 ] [ V_31 ] ,
V_9 [ V_13 ] [ V_31 ] ) ;
F_10 ( V_35 . V_36 . V_67 , V_9 [ V_12 ] [ V_32 ] ,
V_9 [ V_13 ] [ V_32 ] ) ;
V_35 . V_33 = V_33 ;
V_35 . V_100 = true ;
}
static T_1 F_29 ( struct V_101 * V_101 ,
char T_2 * V_102 , T_3 V_103 , T_4 * V_104 )
{
unsigned V_105 = * V_104 ;
char T_2 * V_106 = V_102 ;
if ( V_107 == 0 ) {
if ( V_101 -> V_108 & V_109 )
return - V_110 ;
if ( F_30 ( V_111 ,
V_107 != 0 ) )
return - V_112 ;
}
for (; V_103 -- > 0 && ( V_107 > 0 ) ;
++ V_105 , ++ V_106 , -- V_107 ) {
F_31 ( V_113 [ V_114 ] , V_106 ) ;
V_114 = ( V_114 + 1 ) % V_115 ;
}
* V_104 = V_105 ;
return V_106 - V_102 ;
}
static int F_32 ( struct V_116 * V_116 , struct V_101 * V_101 )
{
if ( ! F_33 ( & V_117 ) )
return - V_118 ;
if ( V_101 -> V_119 & V_120 )
return - V_121 ;
V_107 = 0 ;
return 0 ;
}
static int F_34 ( struct V_116 * V_116 , struct V_101 * V_101 )
{
F_35 ( & V_117 ) ;
return 0 ;
}
static void F_36 ( const char * string , int V_122 )
{
if ( ! F_37 ( & V_117 ) ) {
while ( V_122 -- && V_107 < V_115 && * string ) {
V_113 [ ( V_114 + V_107 ++ ) %
V_115 ] = * string ++ ;
}
F_38 ( & V_111 ) ;
}
}
static void F_39 ( void )
{
int V_3 , V_123 ;
char V_124 ;
char V_125 ;
char V_126 ;
V_127 = V_128 ;
V_129 = V_130 ;
V_130 = 0 ;
V_124 = F_4 ( V_11 ) | V_131 ;
F_5 ( V_11 , V_124 & ~ V_131 ) ;
V_125 = F_40 ( F_41 ( V_11 ) ) & V_132 ;
F_5 ( V_11 , V_124 ) ;
V_126 = F_40 ( F_41 ( V_11 ) ) & V_132 ;
V_130 |= ( V_133 ) V_126 << 40 ;
if ( V_125 != V_126 ) {
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_123 = F_42 ( V_3 ) ;
if ( ! ( V_131 & V_123 ) )
continue;
F_5 ( V_11 , V_124 & ~ V_123 ) ;
V_125 = F_40 ( F_41 ( V_11 ) ) & ~ V_126 ;
V_130 |= ( V_133 ) V_125 << ( 5 * V_3 ) ;
}
F_5 ( V_11 , V_124 ) ;
}
V_128 = ( V_127 & ( V_130 ^ V_129 ) ) |
( V_130 & ~ ( V_130 ^ V_129 ) ) ;
}
static inline int F_43 ( struct V_134 * V_135 )
{
#if 0
if (((phys_prev & input->mask) == input->value) &&
((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return 1;
}
#endif
if ( ( V_128 & V_135 -> V_136 ) == V_135 -> V_137 ) {
if ( ( V_135 -> type == V_138 ) &&
( V_135 -> V_139 == 0 ) ) {
V_135 -> V_139 ++ ;
if ( V_135 -> V_140 . V_141 . V_142 )
V_135 -> V_140 . V_141 . V_142 ( V_135 -> V_140 . V_141 . V_143 ) ;
} else if ( V_135 -> type == V_144 ) {
V_145 = 1 ;
if ( V_135 -> V_139 == 0 ) {
char * V_146 = V_135 -> V_140 . V_147 . V_146 ;
if ( V_146 [ 0 ] ) {
int V_148 = sizeof( V_135 -> V_140 . V_147 . V_146 ) ;
F_36 ( V_146 , V_148 ) ;
}
}
if ( V_135 -> V_140 . V_147 . V_149 [ 0 ] ) {
char * V_149 = V_135 -> V_140 . V_147 . V_149 ;
if ( V_135 -> V_139 >= V_150 ) {
int V_148 = sizeof( V_135 -> V_140 . V_147 . V_149 ) ;
V_135 -> V_139 -= V_151 ;
F_36 ( V_149 , V_148 ) ;
}
V_152 = 0 ;
}
if ( V_135 -> V_139 < 255 )
V_135 -> V_139 ++ ;
}
return 1 ;
}
V_135 -> V_4 = V_153 ;
V_135 -> V_154 = 0 ;
return 0 ;
}
static inline void F_44 ( struct V_134 * V_135 )
{
#if 0
if (((phys_prev & input->mask) == input->value) &&
((phys_curr & input->mask) > input->value)) {
input->state = INPUT_ST_LOW;
return;
}
#endif
if ( ( V_128 & V_135 -> V_136 ) == V_135 -> V_137 ) {
if ( V_135 -> type == V_144 ) {
V_145 = 1 ;
if ( V_135 -> V_140 . V_147 . V_149 [ 0 ] ) {
char * V_149 = V_135 -> V_140 . V_147 . V_149 ;
if ( V_135 -> V_139 >= V_150 ) {
int V_148 = sizeof( V_135 -> V_140 . V_147 . V_149 ) ;
V_135 -> V_139 -= V_151 ;
F_36 ( V_149 , V_148 ) ;
}
V_152 = 0 ;
}
if ( V_135 -> V_139 < 255 )
V_135 -> V_139 ++ ;
}
V_135 -> V_4 = V_155 ;
} else if ( V_135 -> V_154 >= V_135 -> V_156 ) {
if ( V_135 -> type == V_138 ) {
void (* F_45)( int ) = V_135 -> V_140 . V_141 . F_45 ;
if ( F_45 )
F_45 ( V_135 -> V_140 . V_141 . V_157 ) ;
} else if ( V_135 -> type == V_144 ) {
char * V_158 = V_135 -> V_140 . V_147 . V_158 ;
if ( V_158 [ 0 ] ) {
int V_148 = sizeof( V_135 -> V_140 . V_147 . V_158 ) ;
F_36 ( V_158 , V_148 ) ;
}
}
V_135 -> V_4 = V_159 ;
} else {
V_135 -> V_154 ++ ;
V_152 = 0 ;
}
}
static void F_46 ( void )
{
struct V_160 * V_161 ;
struct V_134 * V_135 ;
V_145 = 0 ;
V_152 = 1 ;
F_47 (item, &logical_inputs) {
V_135 = F_48 ( V_161 , struct V_134 , V_162 ) ;
switch ( V_135 -> V_4 ) {
case V_159 :
if ( ( V_128 & V_135 -> V_136 ) != V_135 -> V_137 )
break;
if ( ( V_127 & V_135 -> V_136 ) == V_135 -> V_137 )
break;
V_135 -> V_163 = 0 ;
V_135 -> V_4 = V_164 ;
case V_164 :
if ( ( V_128 & V_135 -> V_136 ) != V_135 -> V_137 ) {
V_135 -> V_4 = V_159 ;
break;
}
if ( V_135 -> V_163 < V_135 -> V_165 ) {
V_152 = 0 ;
V_135 -> V_163 ++ ;
break;
}
V_135 -> V_139 = 0 ;
V_135 -> V_4 = V_155 ;
case V_155 :
if ( F_43 ( V_135 ) )
break;
case V_153 :
F_44 ( V_135 ) ;
}
}
}
static void F_49 ( void )
{
if ( V_166 . V_167 && V_168 ) {
if ( F_50 ( & V_39 ) ) {
F_39 () ;
F_17 ( & V_39 ) ;
}
if ( ! V_152 || V_128 != V_127 )
F_46 () ;
}
if ( V_145 && V_35 . V_167 && V_35 . V_100 )
F_51 ( V_35 . V_33 ) ;
F_52 ( & V_169 , V_170 + V_171 ) ;
}
static void F_53 ( void )
{
if ( V_169 . V_172 )
return;
F_54 ( & V_169 , ( void * ) & F_49 , 0 ) ;
V_169 . V_173 = V_170 + V_171 ;
F_55 ( & V_169 ) ;
}
static T_5 F_56 ( const char * V_174 , V_133 * V_136 , V_133 * V_137 ,
T_5 * V_175 , T_5 * V_176 )
{
const char V_177 [] = L_1 ;
T_5 V_178 , V_179 ;
V_133 V_180 , V_181 ;
V_179 = 0 ;
V_178 = 0 ;
V_180 = 0ULL ;
V_181 = 0ULL ;
while ( * V_174 ) {
int V_182 , V_183 , V_3 , V_184 ;
const char * V_185 ;
V_185 = strchr ( V_177 , * V_174 ) ;
if ( ! V_185 )
return 0 ;
V_182 = V_185 - V_177 ;
V_184 = ( V_182 & 1 ) ;
V_182 >>= 1 ;
V_178 |= F_42 ( V_182 ) ;
V_174 ++ ;
if ( * V_174 >= '0' && * V_174 <= '7' ) {
V_183 = * V_174 - '0' ;
V_179 |= F_42 ( V_183 ) ;
} else if ( * V_174 == '-' ) {
V_183 = 8 ;
} else {
return 0 ;
}
V_3 = ( V_183 * 5 ) + V_182 ;
V_180 |= 1ULL << V_3 ;
if ( ! V_184 )
V_181 |= 1ULL << V_3 ;
V_174 ++ ;
}
* V_136 = V_180 ;
* V_137 = V_181 ;
if ( V_175 )
* V_175 |= V_178 ;
if ( V_176 )
* V_176 |= V_179 ;
return 1 ;
}
static struct V_134 * F_57 ( const char * V_174 , const char * V_186 ,
const char * V_187 ,
const char * V_188 )
{
struct V_134 * V_189 ;
V_189 = F_58 ( sizeof( * V_189 ) , V_190 ) ;
if ( ! V_189 )
return NULL ;
if ( ! F_56 ( V_174 , & V_189 -> V_136 , & V_189 -> V_137 , & V_132 ,
& V_131 ) ) {
F_59 ( V_189 ) ;
return NULL ;
}
V_189 -> type = V_144 ;
V_189 -> V_4 = V_159 ;
V_189 -> V_165 = 1 ;
V_189 -> V_156 = 1 ;
strncpy ( V_189 -> V_140 . V_147 . V_146 , V_186 , sizeof( V_189 -> V_140 . V_147 . V_146 ) ) ;
strncpy ( V_189 -> V_140 . V_147 . V_149 , V_187 , sizeof( V_189 -> V_140 . V_147 . V_149 ) ) ;
strncpy ( V_189 -> V_140 . V_147 . V_158 , V_188 ,
sizeof( V_189 -> V_140 . V_147 . V_158 ) ) ;
F_60 ( & V_189 -> V_162 , & V_191 ) ;
return V_189 ;
}
static void F_61 ( void )
{
int V_192 ;
F_62 ( & V_111 ) ;
V_107 = 0 ;
for ( V_192 = 0 ; V_193 [ V_192 ] [ 0 ] [ 0 ] ; V_192 ++ ) {
F_57 ( V_193 [ V_192 ] [ 0 ] ,
V_193 [ V_192 ] [ 1 ] ,
V_193 [ V_192 ] [ 2 ] ,
V_193 [ V_192 ] [ 3 ] ) ;
}
F_53 () ;
V_168 = 1 ;
}
static void F_63 ( struct V_194 * V_1 )
{
struct V_195 V_196 ;
if ( V_1 -> V_197 != V_194 )
return;
if ( V_11 ) {
F_64 ( L_2 ,
V_198 , V_1 -> V_197 , V_194 ) ;
return;
}
memset ( & V_196 , 0 , sizeof( V_196 ) ) ;
V_196 . V_199 = & V_11 ;
V_11 = F_65 ( V_1 , L_3 , & V_196 , 0 ) ;
if ( ! V_11 ) {
F_64 ( L_4 ,
V_198 , V_1 -> V_197 , V_194 ) ;
return;
}
if ( F_66 ( V_11 ) ) {
F_64 ( L_5 ,
V_194 ) ;
goto V_200;
}
if ( V_35 . V_167 ) {
F_27 () ;
if ( ! V_35 . V_33 || F_67 ( V_35 . V_33 ) )
goto V_200;
}
if ( V_166 . V_167 ) {
F_61 () ;
if ( F_68 ( & V_201 ) )
goto V_202;
}
return;
V_202:
if ( V_35 . V_167 )
F_69 ( V_35 . V_33 ) ;
V_200:
F_59 ( V_35 . V_33 ) ;
V_35 . V_33 = NULL ;
F_70 ( V_11 ) ;
V_11 = NULL ;
}
static void F_71 ( struct V_194 * V_1 )
{
if ( V_1 -> V_197 != V_194 )
return;
if ( ! V_11 ) {
F_64 ( L_6 ,
V_198 , V_1 -> V_197 , V_194 ) ;
return;
}
if ( V_169 . V_172 )
F_72 ( & V_169 ) ;
if ( V_166 . V_167 ) {
F_73 ( & V_201 ) ;
V_168 = 0 ;
}
if ( V_35 . V_167 ) {
F_69 ( V_35 . V_33 ) ;
V_35 . V_100 = false ;
F_59 ( V_35 . V_33 ) ;
V_35 . V_33 = NULL ;
}
F_74 ( V_11 ) ;
F_70 ( V_11 ) ;
V_11 = NULL ;
}
static int T_6 F_75 ( void )
{
int V_203 = V_74 , V_204 ;
switch ( V_205 ) {
case V_206 :
V_203 = V_207 ;
V_55 = V_208 ;
break;
case V_209 :
V_203 = V_210 ;
V_55 = V_56 ;
if ( V_51 == V_74 )
V_51 = 16 ;
if ( V_54 == V_74 )
V_54 = 16 ;
break;
case V_211 :
V_203 = V_212 ;
V_55 = V_63 ;
break;
case V_213 :
V_203 = V_214 ;
V_55 = V_73 ;
break;
case V_215 :
V_203 = V_216 ;
V_55 = V_68 ;
break;
case V_217 :
V_203 = V_210 ;
V_55 = V_56 ;
break;
}
if ( V_218 != V_74 )
V_203 = V_218 ;
if ( V_219 != V_74 )
V_203 = V_219 ;
V_166 . V_167 = ( V_203 > 0 ) ;
if ( V_220 != V_74 )
V_55 = V_220 ;
if ( V_221 != V_74 )
V_55 = V_221 ;
V_35 . V_167 = ( V_55 > 0 ) ;
if ( V_35 . V_167 ) {
V_35 . V_59 = V_75 ;
V_35 . V_57 = V_76 ;
V_35 . V_36 . V_61 = V_77 ;
V_35 . V_36 . V_62 = V_79 ;
V_35 . V_36 . V_69 = V_80 ;
V_35 . V_36 . V_66 = V_81 ;
V_35 . V_36 . V_67 = V_82 ;
V_35 . V_36 . V_37 = V_83 ;
}
switch ( V_203 ) {
case V_210 :
V_193 = V_222 ;
break;
case V_212 :
V_193 = V_223 ;
break;
case V_216 :
V_193 = V_224 ;
break;
default:
V_193 = NULL ;
break;
}
if ( ! V_35 . V_167 && ! V_166 . V_167 ) {
F_64 ( L_7 ) ;
return - V_225 ;
}
V_204 = F_76 ( & V_226 ) ;
if ( V_204 ) {
F_64 ( L_8 ) ;
return V_204 ;
}
if ( V_11 )
F_77 ( L_9 ,
V_194 , V_11 -> V_1 -> V_227 ) ;
else
F_77 ( L_10 ) ;
return 0 ;
}
static void T_7 F_78 ( void )
{
F_79 ( & V_226 ) ;
}
