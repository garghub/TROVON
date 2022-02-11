static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_1 , V_4 , V_4 -> V_5 ) ;
V_4 -> V_6 . V_7 . V_8 = V_2 -> V_9 ++ ;
V_4 -> V_6 . V_7 . V_10 = V_11 ;
F_3 ( & V_4 -> V_6 . V_7 . V_12 ) ;
F_4 ( & V_4 -> V_6 , V_13 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char * V_14 ,
unsigned long V_15 )
{
void * V_16 , * V_17 , * V_18 ;
int V_19 , V_20 , V_21 , V_22 , V_23 ;
int V_24 = V_2 -> V_25 << 1 ;
if ( V_4 -> V_26 + V_15 > V_4 -> V_27 )
V_15 = V_4 -> V_27 - V_4 -> V_26 ;
V_18 = V_14 ;
V_23 = V_15 ;
if ( V_2 -> V_28 || V_4 -> V_5 )
V_16 = V_4 -> V_29 ;
else
V_16 = V_4 -> V_29 + V_24 ;
V_19 = V_4 -> V_26 / V_24 ;
V_20 = V_4 -> V_26 % V_24 ;
if ( V_2 -> V_28 )
V_21 = V_19 * V_24 + V_20 ;
else
V_21 = V_19 * V_24 * 2 + V_20 ;
V_17 = V_16 + V_21 ;
V_22 = V_24 - V_20 ;
V_22 = V_22 > V_23 ? V_23 : V_22 ;
if ( ( char * ) V_17 + V_22 > ( char * ) V_4 -> V_29 + V_4 -> V_27 ) {
F_2 ( L_2 ,
( ( char * ) V_17 + V_22 ) -
( ( char * ) V_4 -> V_29 + V_4 -> V_27 ) ) ;
V_23 = ( char * ) V_4 -> V_29 + V_4 -> V_27 -
( char * ) V_17 ;
V_22 = V_23 ;
}
if ( V_22 <= 0 )
return;
memcpy ( V_17 , V_18 , V_22 ) ;
V_23 -= V_22 ;
while ( V_23 > 0 ) {
if ( V_2 -> V_28 )
V_17 += V_22 ;
else
V_17 += V_22 + V_24 ;
V_18 += V_22 ;
if ( V_24 > V_23 )
V_22 = V_23 ;
else
V_22 = V_24 ;
if ( ( char * ) V_17 + V_22 > ( char * ) V_4 -> V_29 +
V_4 -> V_27 ) {
F_2 ( L_3
L_4 ,
( ( char * ) V_17 + V_22 ) -
( ( char * ) V_4 -> V_29 + V_4 -> V_27 ) ) ;
V_22 = V_23 = ( char * ) V_4 -> V_29 + V_4 -> V_27 -
( char * ) V_17 ;
}
if ( V_22 <= 0 )
break;
memcpy ( V_17 , V_18 , V_22 ) ;
V_23 -= V_22 ;
}
V_4 -> V_26 += V_15 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char * V_14 ,
unsigned long V_15 )
{
unsigned int V_21 ;
if ( V_4 -> V_26 + V_15 > V_4 -> V_27 )
V_15 = V_4 -> V_27 - V_4 -> V_26 ;
V_21 = V_4 -> V_26 ;
if ( V_4 -> V_5 == 0 )
V_21 += V_2 -> V_30 * V_2 -> V_31 ;
memcpy ( V_4 -> V_29 + V_21 , V_14 , V_15 ) ;
V_4 -> V_26 += V_15 ;
}
static inline void F_7 ( struct V_1 * V_2 ,
int V_32 , int V_33 )
{
char * V_34 = L_5 ;
switch ( V_33 ) {
case - V_35 :
V_34 = L_6 ;
break;
case - V_36 :
V_34 = L_7 ;
break;
case - V_37 :
V_34 = L_8 ;
break;
case - V_38 :
V_34 = L_9 ;
break;
case - V_39 :
V_34 = L_10 ;
break;
case - V_40 :
V_34 = L_11 ;
break;
case - V_41 :
V_34 = L_12 ;
break;
case - V_42 :
V_34 = L_13 ;
break;
}
if ( V_32 < 0 ) {
F_2 ( L_14 , V_33 , V_34 ) ;
} else {
F_2 ( L_15 ,
V_32 , V_33 , V_34 ) ;
}
}
static inline struct V_3 * F_8 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_3 * V_4 ;
if ( F_9 ( & V_44 -> V_45 ) ) {
F_2 ( L_16 ) ;
return NULL ;
}
V_4 = F_10 ( V_44 -> V_45 . V_46 , struct V_3 , V_47 ) ;
F_11 ( & V_4 -> V_47 ) ;
V_4 -> V_26 = 0 ;
V_4 -> V_29 = V_4 -> V_48 ;
return V_4 ;
}
static struct V_3 *
F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_43 * V_44 )
{
if ( V_2 -> V_28 || V_2 -> V_5 ) {
if ( V_4 != NULL )
F_1 ( V_2 , V_4 ) ;
V_4 = F_8 ( V_2 , V_44 ) ;
}
if ( V_4 != NULL ) {
V_4 -> V_5 = V_2 -> V_5 ;
V_4 -> V_26 = 0 ;
}
return V_4 ;
}
static inline void F_13 ( struct V_1 * V_2 ,
unsigned char * V_49 ,
unsigned int V_50 )
{
struct V_3 * V_4 = V_2 -> V_51 . V_52 ;
struct V_3 * V_53 = V_2 -> V_51 . V_53 ;
struct V_43 * V_44 = & V_2 -> V_54 ;
struct V_43 * V_55 = & V_2 -> V_56 ;
if ( V_50 >= 4 ) {
if ( V_49 [ 0 ] == 0x88 && V_49 [ 1 ] == 0x88 &&
V_49 [ 2 ] == 0x88 && V_49 [ 3 ] == 0x88 ) {
V_49 += 4 ;
V_50 -= 4 ;
} else if ( V_49 [ 0 ] == 0x33 && V_49 [ 1 ] == 0x95 ) {
V_2 -> V_57 = 0 ;
V_2 -> V_58 = 0 ;
F_2 ( L_17 ) ;
V_2 -> V_5 = ! ( V_49 [ 2 ] & 1 ) ;
V_49 += 4 ;
V_50 -= 4 ;
} else if ( V_49 [ 0 ] == 0x22 && V_49 [ 1 ] == 0x5a ) {
V_2 -> V_57 = 2 ;
F_2 ( L_18 ) ;
V_2 -> V_5 = ! ( V_49 [ 2 ] & 1 ) ;
V_49 += 4 ;
V_50 -= 4 ;
}
}
if ( V_2 -> V_57 == 0 ) {
V_53 = F_12 ( V_2 , V_53 , V_55 ) ;
V_2 -> V_51 . V_53 = V_53 ;
V_2 -> V_57 = 1 ;
}
if ( V_2 -> V_57 == 1 ) {
int V_59 = V_2 -> V_30 * V_2 -> V_31 ;
int V_60 = ( ( V_2 -> V_58 + V_50 ) > V_59 ) ?
( V_59 - V_2 -> V_58 ) : V_50 ;
if ( V_53 != NULL )
F_6 ( V_2 , V_53 , V_49 , V_60 ) ;
V_2 -> V_58 += V_60 ;
if ( V_60 < V_50 ) {
V_2 -> V_57 = 2 ;
V_49 += V_60 ;
V_50 -= V_60 ;
}
}
if ( V_2 -> V_57 == 2 ) {
V_4 = F_12 ( V_2 , V_4 , V_44 ) ;
V_2 -> V_51 . V_52 = V_4 ;
V_2 -> V_57 = 3 ;
}
if ( V_2 -> V_57 == 3 && V_4 != NULL && V_50 > 0 )
F_5 ( V_2 , V_4 , V_49 , V_50 ) ;
}
static inline void F_14 ( struct V_1 * V_2 ,
unsigned char * V_49 ,
unsigned int V_50 )
{
struct V_3 * V_4 = V_2 -> V_51 . V_52 ;
struct V_43 * V_61 = & V_2 -> V_54 ;
bool V_62 = 0 ;
if ( V_50 >= 2 ) {
if ( ( V_49 [ 0 ] == V_63 ) &&
( ( V_49 [ 1 ] & ~ V_64 ) == 0x00 ) ) {
V_2 -> V_5 = ! ( V_49 [ 1 ] &
V_65 ) ;
V_62 = V_49 [ 1 ] &
V_66 ;
V_49 += 2 ;
V_50 -= 2 ;
}
if ( V_2 -> V_67 && V_62 ) {
V_4 = F_12 ( V_2 , V_4 , V_61 ) ;
V_2 -> V_51 . V_52 = V_4 ;
}
}
if ( V_4 != NULL && V_50 > 0 )
F_5 ( V_2 , V_4 , V_49 , V_50 ) ;
if ( ! V_2 -> V_67 && V_62 ) {
V_4 = F_12 ( V_2 , V_4 , V_61 ) ;
V_2 -> V_51 . V_52 = V_4 ;
}
}
static inline int F_15 ( struct V_1 * V_2 , struct V_68 * V_68 )
{
int V_69 , V_70 , V_71 ;
unsigned char * V_72 ;
unsigned int V_73 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_74 )
return 0 ;
if ( V_68 -> V_33 < 0 )
F_7 ( V_2 , - 1 , V_68 -> V_33 ) ;
V_69 = F_16 ( V_68 -> V_75 ) ;
if ( V_69 )
V_70 = 1 ;
else
V_70 = V_68 -> V_76 ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ ) {
if ( V_69 ) {
V_73 = V_68 -> V_77 ;
V_72 = V_68 -> V_78 ;
} else {
if ( V_68 -> V_79 [ V_71 ] . V_33 < 0 ) {
F_7 ( V_2 , V_71 ,
V_68 -> V_79 [ V_71 ] . V_33 ) ;
if ( V_68 -> V_79 [ V_71 ] . V_33 != - V_40 )
continue;
}
V_73 = V_68 -> V_79 [ V_71 ] . V_77 ;
if ( V_73 > V_2 -> V_80 ) {
F_2 ( L_19 ) ;
continue;
}
V_72 = V_68 -> V_78 +
V_68 -> V_79 [ V_71 ] . V_21 ;
}
if ( V_73 == 0 ) {
continue;
}
if ( V_2 -> V_81 )
F_14 ( V_2 ,
V_72 , V_73 ) ;
else
F_13 ( V_2 ,
V_72 , V_73 ) ;
}
return 1 ;
}
static int F_17 ( enum V_82 V_83 )
{
switch ( V_83 ) {
case V_84 :
return V_85 ;
case V_86 :
return V_87 ;
default:
F_18 () ;
return 0 ;
}
}
static int F_19 ( struct V_1 * V_2 , enum V_82 V_83 )
{
int V_88 = F_17 ( V_83 ) ;
if ( V_2 -> V_89 & V_88 ) {
return - V_90 ;
}
V_2 -> V_89 |= V_88 ;
F_20 ( L_20 , V_88 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , enum V_82 V_83 )
{
int V_88 = F_17 ( V_83 ) ;
V_2 -> V_89 &= ~ V_88 ;
F_20 ( L_21 , V_88 ) ;
}
static int F_22 ( struct V_91 * V_92 , const struct V_93 * V_94 ,
unsigned int * V_95 , unsigned int * V_96 ,
unsigned int V_97 [] , void * V_98 [] )
{
struct V_1 * V_2 = F_23 ( V_92 ) ;
unsigned long V_99 ;
if ( V_94 )
V_99 = V_94 -> V_94 . V_100 . V_101 ;
else
V_99 = ( V_2 -> V_25 * V_2 -> V_102 * V_2 -> V_103 -> V_104 + 7 ) >> 3 ;
if ( V_99 == 0 )
return - V_105 ;
if ( 0 == * V_95 )
* V_95 = 32 ;
* V_96 = 1 ;
V_97 [ 0 ] = V_99 ;
return 0 ;
}
static int
F_24 ( struct V_106 * V_6 )
{
struct V_1 * V_2 = F_23 ( V_6 -> V_91 ) ;
struct V_3 * V_4 = F_25 ( V_6 , struct V_3 , V_6 ) ;
unsigned long V_99 ;
F_20 ( L_22 , V_107 , V_6 -> V_7 . V_10 ) ;
V_99 = ( V_2 -> V_25 * V_2 -> V_102 * V_2 -> V_103 -> V_104 + 7 ) >> 3 ;
if ( F_26 ( V_6 , 0 ) < V_99 ) {
F_20 ( L_23 ,
V_107 , F_26 ( V_6 , 0 ) , V_99 ) ;
return - V_105 ;
}
F_27 ( & V_4 -> V_6 , 0 , V_99 ) ;
return 0 ;
}
int F_28 ( struct V_91 * V_92 , unsigned int V_108 )
{
struct V_1 * V_2 = F_23 ( V_92 ) ;
struct V_109 V_110 ;
int V_111 = 0 ;
F_20 ( L_24 , V_107 ) ;
V_111 = F_19 ( V_2 , V_92 -> type ) ;
if ( V_111 )
return V_111 ;
if ( V_2 -> V_112 == 0 ) {
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
V_2 -> V_57 = - 1 ;
V_111 = F_31 ( V_2 , V_113 ,
V_2 -> V_67 ,
V_114 ,
V_2 -> V_80 ,
V_2 -> V_115 ,
F_15 ) ;
if ( V_111 < 0 )
return V_111 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_116 = V_2 -> V_117 ;
if ( V_92 -> V_118 && V_92 -> V_118 -> V_119 -> V_120 == V_121 )
V_110 . type = V_122 ;
else
V_110 . type = V_123 ;
F_32 ( & V_2 -> V_124 , 0 , V_125 , V_126 , & V_110 ) ;
}
V_2 -> V_112 ++ ;
return V_111 ;
}
static int F_33 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_92 ) ;
struct V_43 * V_54 = & V_2 -> V_54 ;
unsigned long V_127 = 0 ;
F_20 ( L_24 , V_107 ) ;
F_21 ( V_2 , V_92 -> type ) ;
if ( V_2 -> V_112 -- == 1 ) {
F_34 ( V_2 , V_113 ) ;
}
F_35 ( & V_2 -> V_128 , V_127 ) ;
while ( ! F_9 ( & V_54 -> V_45 ) ) {
struct V_3 * V_4 ;
V_4 = F_10 ( V_54 -> V_45 . V_46 , struct V_3 , V_47 ) ;
F_11 ( & V_4 -> V_47 ) ;
F_4 ( & V_4 -> V_6 , V_129 ) ;
}
V_2 -> V_51 . V_52 = NULL ;
F_36 ( & V_2 -> V_128 , V_127 ) ;
return 0 ;
}
int F_37 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_92 ) ;
struct V_43 * V_56 = & V_2 -> V_56 ;
unsigned long V_127 = 0 ;
F_20 ( L_24 , V_107 ) ;
F_21 ( V_2 , V_92 -> type ) ;
if ( V_2 -> V_112 -- == 1 ) {
F_34 ( V_2 , V_113 ) ;
}
F_35 ( & V_2 -> V_128 , V_127 ) ;
while ( ! F_9 ( & V_56 -> V_45 ) ) {
struct V_3 * V_4 ;
V_4 = F_10 ( V_56 -> V_45 . V_46 , struct V_3 , V_47 ) ;
F_11 ( & V_4 -> V_47 ) ;
F_4 ( & V_4 -> V_6 , V_129 ) ;
}
V_2 -> V_51 . V_53 = NULL ;
F_36 ( & V_2 -> V_128 , V_127 ) ;
return 0 ;
}
static void
F_38 ( struct V_106 * V_6 )
{
struct V_1 * V_2 = F_23 ( V_6 -> V_91 ) ;
struct V_3 * V_4 = F_25 ( V_6 , struct V_3 , V_6 ) ;
struct V_43 * V_54 = & V_2 -> V_54 ;
unsigned long V_127 = 0 ;
F_20 ( L_24 , V_107 ) ;
V_4 -> V_48 = F_39 ( V_6 , 0 ) ;
V_4 -> V_27 = F_26 ( V_6 , 0 ) ;
F_35 ( & V_2 -> V_128 , V_127 ) ;
F_40 ( & V_4 -> V_47 , & V_54 -> V_45 ) ;
F_36 ( & V_2 -> V_128 , V_127 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
int V_111 ;
struct V_91 * V_130 ;
V_130 = & V_2 -> V_131 ;
V_130 -> type = V_84 ;
V_130 -> V_132 = V_133 | V_134 | V_135 | V_136 ;
V_130 -> V_137 = V_138 ;
V_130 -> V_139 = V_2 ;
V_130 -> V_140 = sizeof( struct V_3 ) ;
V_130 -> V_141 = & V_142 ;
V_130 -> V_143 = & V_144 ;
V_111 = F_42 ( V_130 ) ;
if ( V_111 < 0 )
return V_111 ;
V_130 = & V_2 -> V_145 ;
V_130 -> type = V_86 ;
V_130 -> V_132 = V_133 | V_134 | V_135 ;
V_130 -> V_137 = V_138 ;
V_130 -> V_139 = V_2 ;
V_130 -> V_140 = sizeof( struct V_3 ) ;
V_130 -> V_141 = & V_146 ;
V_130 -> V_143 = & V_144 ;
V_111 = F_42 ( V_130 ) ;
if ( V_111 < 0 )
return V_111 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 , int V_147 )
{
V_2 -> V_148 = V_147 ;
V_2 -> V_149 = F_44 ( V_147 ) -> V_150 ;
V_2 -> V_151 = F_44 ( V_147 ) -> V_152 ;
if ( ! V_2 -> V_151 )
V_2 -> V_151 = V_153 ;
F_32 ( & V_2 -> V_124 , 0 , V_154 , V_155 ,
F_44 ( V_147 ) -> V_156 , 0 , 0 ) ;
if ( V_2 -> V_157 . V_158 ) {
if ( V_2 -> V_159 ) {
F_32 ( & V_2 -> V_124 , 0 , V_160 ,
V_161 , V_2 -> V_159 ) ;
}
F_32 ( & V_2 -> V_124 , 0 , V_160 , V_155 ,
V_2 -> V_149 , F_45 ( V_162 ) , 0 ) ;
}
if ( V_2 -> V_157 . V_163 != V_164 ) {
F_32 ( & V_2 -> V_124 , 0 , V_160 , V_155 ,
V_2 -> V_149 , V_2 -> V_151 , 0 ) ;
}
F_46 ( V_2 ) ;
}
void F_47 ( struct V_165 * V_166 , void * V_167 )
{
struct V_1 * V_2 = V_167 ;
switch ( V_166 -> V_168 ) {
case V_169 :
V_2 -> V_170 = V_166 -> V_171 ;
F_46 ( V_2 ) ;
break;
case V_172 :
V_2 -> V_173 = V_166 -> V_171 ;
F_46 ( V_2 ) ;
break;
}
}
static int F_48 ( struct V_165 * V_166 )
{
struct V_1 * V_2 = F_25 ( V_166 -> V_174 , struct V_1 , V_175 ) ;
int V_176 = - V_105 ;
switch ( V_166 -> V_168 ) {
case V_169 :
V_2 -> V_170 = V_166 -> V_171 ;
V_176 = F_46 ( V_2 ) ;
break;
case V_172 :
V_2 -> V_173 = V_166 -> V_171 ;
V_176 = F_46 ( V_2 ) ;
break;
case V_177 :
V_176 = F_49 ( V_2 , V_178 , V_166 -> V_171 ) ;
break;
case V_179 :
V_176 = F_49 ( V_2 , V_180 , V_166 -> V_171 ) ;
break;
case V_181 :
V_176 = F_49 ( V_2 , V_182 , V_166 -> V_171 ) ;
break;
case V_183 :
V_176 = F_49 ( V_2 , V_184 , V_166 -> V_171 ) ;
break;
case V_185 :
V_176 = F_49 ( V_2 , V_186 , V_166 -> V_171 ) ;
break;
case V_187 :
V_176 = F_49 ( V_2 , V_188 , V_166 -> V_171 ) ;
break;
}
return ( V_176 < 0 ) ? V_176 : 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
unsigned int V_25 , unsigned int V_102 ,
unsigned int * V_189 , unsigned int * V_190 )
{
unsigned int V_191 = F_51 ( V_2 ) ;
unsigned int V_192 = F_52 ( V_2 ) ;
* V_189 = ( ( ( unsigned long ) V_191 ) << 12 ) / V_25 - 4096L ;
if ( * V_189 > V_193 )
* V_189 = V_193 ;
* V_190 = ( ( ( unsigned long ) V_192 ) << 12 ) / V_102 - 4096L ;
if ( * V_190 > V_193 )
* V_190 = V_193 ;
}
static void F_53 ( struct V_1 * V_2 ,
unsigned int V_189 , unsigned int V_190 ,
unsigned int * V_25 , unsigned int * V_102 )
{
unsigned int V_191 = F_51 ( V_2 ) ;
unsigned int V_192 = F_52 ( V_2 ) ;
* V_25 = ( ( ( unsigned long ) V_191 ) << 12 ) / ( V_189 + 4096L ) ;
* V_102 = ( ( ( unsigned long ) V_192 ) << 12 ) / ( V_190 + 4096L ) ;
}
static int F_54 ( struct V_194 * V_194 , void * V_167 ,
struct V_93 * V_110 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
V_110 -> V_94 . V_100 . V_25 = V_2 -> V_25 ;
V_110 -> V_94 . V_100 . V_102 = V_2 -> V_102 ;
V_110 -> V_94 . V_100 . V_197 = V_2 -> V_103 -> V_198 ;
V_110 -> V_94 . V_100 . V_24 = ( V_2 -> V_25 * V_2 -> V_103 -> V_104 + 7 ) >> 3 ;
V_110 -> V_94 . V_100 . V_101 = V_110 -> V_94 . V_100 . V_24 * V_2 -> V_102 ;
V_110 -> V_94 . V_100 . V_199 = V_200 ;
if ( V_2 -> V_28 )
V_110 -> V_94 . V_100 . V_10 = V_201 ;
else
V_110 -> V_94 . V_100 . V_10 = V_2 -> V_202 ?
V_11 : V_203 ;
return 0 ;
}
static struct V_204 * F_55 ( unsigned int V_198 )
{
unsigned int V_71 ;
for ( V_71 = 0 ; V_71 < F_56 ( V_103 ) ; V_71 ++ )
if ( V_103 [ V_71 ] . V_198 == V_198 )
return & V_103 [ V_71 ] ;
return NULL ;
}
static int F_57 ( struct V_194 * V_194 , void * V_167 ,
struct V_93 * V_110 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
unsigned int V_25 = V_110 -> V_94 . V_100 . V_25 ;
unsigned int V_102 = V_110 -> V_94 . V_100 . V_102 ;
unsigned int V_191 = F_51 ( V_2 ) ;
unsigned int V_192 = F_52 ( V_2 ) ;
unsigned int V_189 , V_190 ;
struct V_204 * V_94 ;
V_94 = F_55 ( V_110 -> V_94 . V_100 . V_197 ) ;
if ( ! V_94 ) {
F_20 ( L_25 ,
V_110 -> V_94 . V_100 . V_197 ) ;
return - V_105 ;
}
if ( V_2 -> V_157 . V_205 ) {
V_102 = V_102 > ( 3 * V_192 / 4 ) ? V_192 : V_192 / 2 ;
V_25 = V_25 > ( 3 * V_191 / 4 ) ? V_191 : V_191 / 2 ;
if ( V_25 == V_191 && V_102 == V_192 )
V_25 /= 2 ;
} else {
F_58 ( & V_25 , 48 , V_191 , 1 , & V_102 , 32 , V_192 ,
1 , 0 ) ;
}
F_50 ( V_2 , V_25 , V_102 , & V_189 , & V_190 ) ;
F_53 ( V_2 , V_189 , V_190 , & V_25 , & V_102 ) ;
V_110 -> V_94 . V_100 . V_25 = V_25 ;
V_110 -> V_94 . V_100 . V_102 = V_102 ;
V_110 -> V_94 . V_100 . V_197 = V_94 -> V_198 ;
V_110 -> V_94 . V_100 . V_24 = ( V_25 * V_94 -> V_104 + 7 ) >> 3 ;
V_110 -> V_94 . V_100 . V_101 = V_110 -> V_94 . V_100 . V_24 * V_102 ;
V_110 -> V_94 . V_100 . V_199 = V_200 ;
if ( V_2 -> V_28 )
V_110 -> V_94 . V_100 . V_10 = V_201 ;
else
V_110 -> V_94 . V_100 . V_10 = V_2 -> V_202 ?
V_11 : V_203 ;
V_110 -> V_94 . V_100 . V_167 = 0 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned int V_198 ,
unsigned V_25 , unsigned V_102 )
{
struct V_204 * V_94 ;
V_94 = F_55 ( V_198 ) ;
if ( ! V_94 )
return - V_105 ;
V_2 -> V_103 = V_94 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_102 = V_102 ;
F_50 ( V_2 , V_2 -> V_25 , V_2 -> V_102 , & V_2 -> V_189 , & V_2 -> V_190 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_194 * V_194 , void * V_167 ,
struct V_93 * V_110 )
{
struct V_1 * V_2 = F_62 ( V_194 ) ;
if ( V_2 -> V_112 > 0 )
return - V_90 ;
F_57 ( V_194 , V_167 , V_110 ) ;
return F_59 ( V_2 , V_110 -> V_94 . V_100 . V_197 ,
V_110 -> V_94 . V_100 . V_25 , V_110 -> V_94 . V_100 . V_102 ) ;
}
static int F_63 ( struct V_194 * V_194 , void * V_167 , T_1 * V_206 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
* V_206 = V_2 -> V_206 ;
return 0 ;
}
static int F_64 ( struct V_194 * V_194 , void * V_167 , T_1 * V_206 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
F_32 ( & V_2 -> V_124 , 0 , V_154 , V_207 , V_206 ) ;
return 0 ;
}
static int F_65 ( struct V_194 * V_194 , void * V_167 , T_1 V_206 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
struct V_93 V_110 ;
if ( V_206 == V_2 -> V_206 )
return 0 ;
if ( V_2 -> V_112 > 0 )
return - V_90 ;
V_2 -> V_206 = V_206 ;
V_110 . V_94 . V_100 . V_25 = 720 ;
V_110 . V_94 . V_100 . V_102 = ( V_206 & V_208 ) ? 480 : 576 ;
F_57 ( V_194 , V_167 , & V_110 ) ;
V_2 -> V_25 = V_110 . V_94 . V_100 . V_25 ;
V_2 -> V_102 = V_110 . V_94 . V_100 . V_102 ;
F_50 ( V_2 , V_2 -> V_25 , V_2 -> V_102 , & V_2 -> V_189 , & V_2 -> V_190 ) ;
F_60 ( V_2 ) ;
F_32 ( & V_2 -> V_124 , 0 , V_209 , V_210 , V_2 -> V_206 ) ;
return 0 ;
}
static int F_66 ( struct V_194 * V_194 , void * V_167 ,
struct V_211 * V_212 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
int V_111 = 0 ;
V_212 -> V_213 . V_214 . V_215 = V_216 ;
if ( V_2 -> V_157 . V_217 )
V_111 = F_67 ( & V_2 -> V_124 , 0 ,
V_154 , V_218 , V_212 ) ;
else
F_68 ( V_2 -> V_206 ,
& V_212 -> V_213 . V_214 . V_219 ) ;
return V_111 ;
}
static int F_69 ( struct V_194 * V_194 , void * V_167 ,
struct V_211 * V_212 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
V_212 -> V_213 . V_214 . V_215 = V_216 ;
return F_67 ( & V_2 -> V_124 , 0 , V_154 , V_220 , V_212 ) ;
}
static int F_70 ( struct V_194 * V_194 , void * V_167 ,
struct V_221 * V_71 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
unsigned int V_222 ;
V_222 = V_71 -> V_147 ;
if ( V_222 >= V_223 )
return - V_105 ;
if ( 0 == F_44 ( V_222 ) -> type )
return - V_105 ;
V_71 -> V_147 = V_222 ;
V_71 -> type = V_224 ;
strcpy ( V_71 -> V_225 , V_226 [ F_44 ( V_222 ) -> type ] ) ;
if ( ( V_227 == F_44 ( V_222 ) -> type ) ||
( V_228 == F_44 ( V_222 ) -> type ) )
V_71 -> type = V_229 ;
V_71 -> V_230 = V_2 -> V_119 -> V_231 ;
if ( V_2 -> V_157 . V_217 )
V_71 -> V_232 = 0 ;
return 0 ;
}
static int F_71 ( struct V_194 * V_194 , void * V_167 , unsigned int * V_71 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
* V_71 = V_2 -> V_148 ;
return 0 ;
}
static int F_72 ( struct V_194 * V_194 , void * V_167 , unsigned int V_71 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
if ( V_71 >= V_223 )
return - V_105 ;
if ( 0 == F_44 ( V_71 ) -> type )
return - V_105 ;
F_43 ( V_2 , V_71 ) ;
return 0 ;
}
static int F_73 ( struct V_194 * V_194 , void * V_167 , struct V_233 * V_234 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
switch ( V_234 -> V_147 ) {
case V_235 :
strcpy ( V_234 -> V_225 , L_26 ) ;
break;
case V_236 :
strcpy ( V_234 -> V_225 , L_27 ) ;
break;
case V_237 :
strcpy ( V_234 -> V_225 , L_28 ) ;
break;
case V_238 :
strcpy ( V_234 -> V_225 , L_29 ) ;
break;
case V_239 :
strcpy ( V_234 -> V_225 , L_30 ) ;
break;
case V_240 :
strcpy ( V_234 -> V_225 , L_31 ) ;
break;
case V_241 :
strcpy ( V_234 -> V_225 , L_32 ) ;
break;
case V_242 :
strcpy ( V_234 -> V_225 , L_33 ) ;
break;
default:
return - V_105 ;
}
V_234 -> V_147 = V_2 -> V_149 ;
V_234 -> V_243 = V_244 ;
return 0 ;
}
static int F_74 ( struct V_194 * V_194 , void * V_167 , const struct V_233 * V_234 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
if ( V_234 -> V_147 >= V_223 )
return - V_105 ;
if ( 0 == F_44 ( V_234 -> V_147 ) -> type )
return - V_105 ;
V_2 -> V_149 = F_44 ( V_234 -> V_147 ) -> V_150 ;
V_2 -> V_151 = F_44 ( V_234 -> V_147 ) -> V_152 ;
if ( ! V_2 -> V_151 )
V_2 -> V_151 = V_153 ;
return 0 ;
}
static int F_75 ( struct V_194 * V_194 , void * V_167 ,
struct V_245 * V_246 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
if ( 0 != V_246 -> V_147 )
return - V_105 ;
strcpy ( V_246 -> V_225 , L_34 ) ;
F_32 ( & V_2 -> V_124 , 0 , V_125 , V_247 , V_246 ) ;
return 0 ;
}
static int F_76 ( struct V_194 * V_194 , void * V_167 ,
const struct V_245 * V_246 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
if ( 0 != V_246 -> V_147 )
return - V_105 ;
F_32 ( & V_2 -> V_124 , 0 , V_125 , V_248 , V_246 ) ;
return 0 ;
}
static int F_77 ( struct V_194 * V_194 , void * V_167 ,
struct V_109 * V_110 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
if ( 0 != V_110 -> V_125 )
return - V_105 ;
V_110 -> V_116 = V_2 -> V_117 ;
return 0 ;
}
static int F_78 ( struct V_194 * V_194 , void * V_167 ,
const struct V_109 * V_110 )
{
struct V_109 V_249 = * V_110 ;
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
if ( 0 != V_110 -> V_125 )
return - V_105 ;
F_32 ( & V_2 -> V_124 , 0 , V_125 , V_126 , V_110 ) ;
F_32 ( & V_2 -> V_124 , 0 , V_125 , V_250 , & V_249 ) ;
V_2 -> V_117 = V_249 . V_116 ;
return 0 ;
}
static int F_79 ( struct V_194 * V_194 , void * V_167 ,
struct V_251 * V_252 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
if ( V_252 -> V_253 . V_254 > 1 )
return - V_105 ;
if ( V_252 -> V_253 . V_254 == 1 )
F_80 ( V_252 -> V_225 , L_35 , sizeof( V_252 -> V_225 ) ) ;
else
F_80 ( V_252 -> V_225 , V_2 -> V_124 . V_225 , sizeof( V_252 -> V_225 ) ) ;
return 0 ;
}
static int F_81 ( int V_255 )
{
switch ( V_255 ) {
case V_256 :
case V_257 :
case V_258 :
return 2 ;
default:
return 1 ;
}
}
static int F_82 ( struct V_194 * V_194 , void * V_167 ,
struct V_259 * V_255 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
int V_176 ;
if ( V_255 -> V_253 . V_254 > 1 )
return - V_105 ;
if ( V_255 -> V_253 . V_254 ) {
V_176 = F_83 ( V_2 , V_255 -> V_255 ) ;
if ( V_176 < 0 )
return V_176 ;
V_255 -> V_171 = V_176 ;
V_255 -> V_99 = 1 ;
return 0 ;
}
V_255 -> V_99 = F_81 ( V_255 -> V_255 ) ;
if ( V_255 -> V_99 == 1 ) {
V_176 = F_84 ( V_2 , V_255 -> V_255 ) ;
if ( V_176 < 0 )
return V_176 ;
V_255 -> V_171 = V_176 ;
} else {
T_2 V_171 = 0 ;
V_176 = F_85 ( V_2 , V_260 ,
V_255 -> V_255 , ( char * ) & V_171 , 2 ) ;
if ( V_176 < 0 )
return V_176 ;
V_255 -> V_171 = F_86 ( V_171 ) ;
}
return 0 ;
}
static int F_87 ( struct V_194 * V_194 , void * V_167 ,
const struct V_259 * V_255 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
T_2 V_4 ;
if ( V_255 -> V_253 . V_254 > 1 )
return - V_105 ;
if ( V_255 -> V_253 . V_254 )
return F_88 ( V_2 , V_255 -> V_255 , V_255 -> V_171 ) ;
V_4 = F_89 ( V_255 -> V_171 ) ;
return F_90 ( V_2 , V_255 -> V_255 , ( char * ) & V_4 ,
F_81 ( V_255 -> V_255 ) ) ;
}
static int F_91 ( struct V_194 * V_194 , void * V_167 ,
struct V_261 * V_262 )
{
struct V_263 * V_119 = F_92 ( V_194 ) ;
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
F_80 ( V_262 -> V_264 , L_36 , sizeof( V_262 -> V_264 ) ) ;
F_80 ( V_262 -> V_265 , V_266 [ V_2 -> V_267 ] . V_225 , sizeof( V_262 -> V_265 ) ) ;
F_93 ( V_2 -> V_268 , V_262 -> V_269 , sizeof( V_262 -> V_269 ) ) ;
if ( V_119 -> V_120 == V_270 )
V_262 -> V_271 = V_272 |
V_273 | V_274 ;
else if ( V_119 -> V_120 == V_121 )
V_262 -> V_271 = V_275 ;
else
V_262 -> V_271 = V_272 | V_276 ;
if ( V_2 -> V_277 . V_278 )
V_262 -> V_271 |= V_279 ;
if ( V_2 -> V_280 != V_281 )
V_262 -> V_271 |= V_282 ;
V_262 -> V_232 = V_262 -> V_271 | V_283 |
V_272 | V_273 | V_274 ;
if ( V_2 -> V_284 )
V_262 -> V_232 |= V_276 ;
if ( V_2 -> V_285 )
V_262 -> V_232 |= V_275 ;
return 0 ;
}
static int F_94 ( struct V_194 * V_194 , void * V_167 ,
struct V_286 * V_110 )
{
if ( F_95 ( V_110 -> V_147 >= F_56 ( V_103 ) ) )
return - V_105 ;
F_80 ( V_110 -> V_287 , V_103 [ V_110 -> V_147 ] . V_225 , sizeof( V_110 -> V_287 ) ) ;
V_110 -> V_197 = V_103 [ V_110 -> V_147 ] . V_198 ;
return 0 ;
}
static int F_96 ( struct V_194 * V_194 , void * V_167 ,
struct V_288 * V_289 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
struct V_204 * V_94 ;
unsigned int V_191 = F_51 ( V_2 ) ;
unsigned int V_192 = F_52 ( V_2 ) ;
V_94 = F_55 ( V_289 -> V_290 ) ;
if ( ! V_94 ) {
F_20 ( L_25 ,
V_289 -> V_290 ) ;
return - V_105 ;
}
if ( V_2 -> V_157 . V_205 ) {
if ( V_289 -> V_147 > 1 )
return - V_105 ;
V_289 -> type = V_291 ;
V_289 -> V_292 . V_25 = V_191 / ( 1 + V_289 -> V_147 ) ;
V_289 -> V_292 . V_102 = V_192 / ( 1 + V_289 -> V_147 ) ;
return 0 ;
}
if ( V_289 -> V_147 != 0 )
return - V_105 ;
V_289 -> type = V_293 ;
F_53 ( V_2 , V_193 , V_193 ,
& V_289 -> V_294 . V_295 , & V_289 -> V_294 . V_296 ) ;
if ( V_289 -> V_294 . V_295 < 48 )
V_289 -> V_294 . V_295 = 48 ;
if ( V_289 -> V_294 . V_296 < 38 )
V_289 -> V_294 . V_296 = 38 ;
V_289 -> V_294 . V_297 = V_191 ;
V_289 -> V_294 . V_298 = V_192 ;
V_289 -> V_294 . V_299 = 1 ;
V_289 -> V_294 . V_300 = 1 ;
return 0 ;
}
static int F_97 ( struct V_194 * V_194 , void * V_167 ,
struct V_93 * V_103 )
{
struct V_195 * V_196 = V_167 ;
struct V_1 * V_2 = V_196 -> V_2 ;
V_103 -> V_94 . V_301 . V_302 = V_2 -> V_30 ;
V_103 -> V_94 . V_301 . V_303 = V_304 ;
V_103 -> V_94 . V_301 . V_21 = 0 ;
V_103 -> V_94 . V_301 . V_127 = 0 ;
V_103 -> V_94 . V_301 . V_305 = 6750000 * 4 / 2 ;
V_103 -> V_94 . V_301 . V_108 [ 0 ] = V_2 -> V_31 ;
V_103 -> V_94 . V_301 . V_108 [ 1 ] = V_2 -> V_31 ;
memset ( V_103 -> V_94 . V_301 . V_306 , 0 , sizeof( V_103 -> V_94 . V_301 . V_306 ) ) ;
if ( V_2 -> V_206 & V_208 ) {
V_103 -> V_94 . V_301 . V_307 [ 0 ] = 10 ;
V_103 -> V_94 . V_301 . V_307 [ 1 ] = 273 ;
} else if ( V_2 -> V_206 & V_308 ) {
V_103 -> V_94 . V_301 . V_307 [ 0 ] = 6 ;
V_103 -> V_94 . V_301 . V_307 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_98 ( struct V_194 * V_194 , void * V_167 ,
struct V_245 * V_246 )
{
struct V_1 * V_2 = ( (struct V_195 * ) V_167 ) -> V_2 ;
if ( F_95 ( V_246 -> V_147 > 0 ) )
return - V_105 ;
strcpy ( V_246 -> V_225 , L_37 ) ;
F_32 ( & V_2 -> V_124 , 0 , V_125 , V_247 , V_246 ) ;
return 0 ;
}
static int F_99 ( struct V_194 * V_194 , void * V_167 ,
const struct V_245 * V_246 )
{
struct V_1 * V_2 = ( (struct V_195 * ) V_167 ) -> V_2 ;
if ( 0 != V_246 -> V_147 )
return - V_105 ;
F_32 ( & V_2 -> V_124 , 0 , V_125 , V_248 , V_246 ) ;
return 0 ;
}
static int F_100 ( struct V_194 * V_309 )
{
struct V_263 * V_119 = F_92 ( V_309 ) ;
struct V_1 * V_2 = F_62 ( V_309 ) ;
enum V_82 V_310 = 0 ;
struct V_195 * V_196 ;
switch ( V_119 -> V_120 ) {
case V_270 :
V_310 = V_84 ;
break;
case V_311 :
V_310 = V_86 ;
break;
}
F_20 ( L_38 ,
F_101 ( V_119 ) , V_312 [ V_310 ] ,
V_2 -> V_313 ) ;
if ( F_102 ( & V_2 -> V_314 ) )
return - V_315 ;
V_196 = F_103 ( sizeof( struct V_195 ) , V_316 ) ;
if ( ! V_196 ) {
F_104 ( L_39 ) ;
F_105 ( & V_2 -> V_314 ) ;
return - V_317 ;
}
F_106 ( & V_196 -> V_196 , V_119 ) ;
V_196 -> V_2 = V_2 ;
V_196 -> type = V_310 ;
V_309 -> V_318 = V_196 ;
if ( V_196 -> type == V_84 && V_2 -> V_313 == 0 ) {
F_107 ( V_2 , V_113 ) ;
F_60 ( V_2 ) ;
F_30 ( V_2 ) ;
}
if ( V_119 -> V_120 == V_121 ) {
F_20 ( L_40 ) ;
F_32 ( & V_2 -> V_124 , 0 , V_125 , V_319 ) ;
}
V_2 -> V_313 ++ ;
F_105 ( & V_2 -> V_314 ) ;
F_108 ( & V_196 -> V_196 ) ;
return 0 ;
}
void F_109 ( struct V_1 * V_2 )
{
if ( V_2 -> V_285 ) {
if ( F_110 ( V_2 -> V_285 ) )
F_111 ( V_2 -> V_285 ) ;
else
F_112 ( V_2 -> V_285 ) ;
V_2 -> V_285 = NULL ;
}
if ( V_2 -> V_284 ) {
F_113 ( L_41 ,
F_101 ( V_2 -> V_284 ) ) ;
if ( F_110 ( V_2 -> V_284 ) )
F_111 ( V_2 -> V_284 ) ;
else
F_112 ( V_2 -> V_284 ) ;
V_2 -> V_284 = NULL ;
}
if ( V_2 -> V_119 ) {
F_113 ( L_41 ,
F_101 ( V_2 -> V_119 ) ) ;
if ( F_110 ( V_2 -> V_119 ) )
F_111 ( V_2 -> V_119 ) ;
else
F_112 ( V_2 -> V_119 ) ;
V_2 -> V_119 = NULL ;
}
}
static int F_114 ( struct V_194 * V_309 )
{
struct V_195 * V_196 = V_309 -> V_318 ;
struct V_1 * V_2 = V_196 -> V_2 ;
int V_320 ;
F_20 ( L_42 , V_2 -> V_313 ) ;
F_115 ( V_309 ) ;
F_116 ( & V_2 -> V_314 ) ;
if ( V_2 -> V_313 == 1 ) {
if ( V_2 -> V_74 ) {
F_117 ( V_2 ) ;
F_118 ( V_2 -> V_321 ) ;
F_105 ( & V_2 -> V_314 ) ;
F_118 ( V_2 ) ;
return 0 ;
}
F_32 ( & V_2 -> V_124 , 0 , V_209 , V_322 , 0 ) ;
F_107 ( V_2 , V_323 ) ;
V_2 -> V_324 = 0 ;
F_20 ( L_43 ) ;
V_320 = F_119 ( V_2 -> V_268 , 0 , 0 ) ;
if ( V_320 < 0 ) {
F_104 ( L_44
L_45 , V_320 ) ;
}
}
V_2 -> V_313 -- ;
F_105 ( & V_2 -> V_314 ) ;
return 0 ;
}
static struct V_263 * F_120 ( struct V_1 * V_2 ,
const struct V_263 * V_325 ,
const char * V_326 )
{
struct V_263 * V_327 ;
V_327 = F_121 () ;
if ( NULL == V_327 )
return NULL ;
* V_327 = * V_325 ;
V_327 -> V_124 = & V_2 -> V_124 ;
V_327 -> V_328 = V_329 ;
V_327 -> V_314 = & V_2 -> V_314 ;
F_122 ( V_330 , & V_327 -> V_127 ) ;
if ( V_2 -> V_157 . V_217 )
V_327 -> V_231 = 0 ;
snprintf ( V_327 -> V_225 , sizeof( V_327 -> V_225 ) , L_46 ,
V_2 -> V_225 , V_326 ) ;
F_123 ( V_327 , V_2 ) ;
return V_327 ;
}
int F_124 ( struct V_1 * V_2 )
{
T_3 V_171 ;
int V_176 ;
unsigned int V_191 ;
F_125 ( V_331 L_47 ,
V_2 -> V_225 , V_332 ) ;
V_2 -> V_206 = V_333 ;
F_32 ( & V_2 -> V_124 , 0 , V_209 , V_210 , V_2 -> V_206 ) ;
V_2 -> V_202 = V_334 ;
V_2 -> V_103 = & V_103 [ 0 ] ;
V_191 = F_51 ( V_2 ) ;
if ( V_2 -> V_157 . V_205 )
V_191 /= 2 ;
F_59 ( V_2 , V_103 [ 0 ] . V_198 ,
V_191 , F_52 ( V_2 ) ) ;
F_43 ( V_2 , 0 ) ;
V_2 -> V_170 = 1 ;
V_2 -> V_173 = 0x1f ;
V_171 = ( T_3 ) F_84 ( V_2 , V_335 ) ;
F_49 ( V_2 , V_335 ,
( V_336 | V_171 ) ) ;
F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
if ( NULL == F_128 ( & V_2 -> V_175 , V_177 ) )
F_129 ( & V_2 -> V_175 , & V_337 ,
V_177 ,
0 , 0x1f , 1 , V_338 ) ;
if ( NULL == F_128 ( & V_2 -> V_175 , V_179 ) )
F_129 ( & V_2 -> V_175 , & V_337 ,
V_179 ,
- 0x80 , 0x7f , 1 , V_339 ) ;
if ( NULL == F_128 ( & V_2 -> V_175 , V_181 ) )
F_129 ( & V_2 -> V_175 , & V_337 ,
V_181 ,
0 , 0x1f , 1 , V_340 ) ;
if ( NULL == F_128 ( & V_2 -> V_175 , V_183 ) )
F_129 ( & V_2 -> V_175 , & V_337 ,
V_183 ,
- 0x30 , 0x30 , 1 , V_341 ) ;
if ( NULL == F_128 ( & V_2 -> V_175 , V_185 ) )
F_129 ( & V_2 -> V_175 , & V_337 ,
V_185 ,
- 0x30 , 0x30 , 1 , V_342 ) ;
if ( NULL == F_128 ( & V_2 -> V_175 , V_187 ) )
F_129 ( & V_2 -> V_175 , & V_337 ,
V_187 ,
0 , 0x0f , 1 , V_343 ) ;
F_130 ( V_2 ) ;
F_131 ( & V_2 -> V_175 ) ;
if ( V_2 -> V_175 . error )
return V_2 -> V_175 . error ;
V_2 -> V_119 = F_120 ( V_2 , & V_344 , L_48 ) ;
if ( ! V_2 -> V_119 ) {
F_104 ( L_49 ) ;
return - V_345 ;
}
V_2 -> V_119 -> V_346 = & V_2 -> V_131 ;
V_2 -> V_119 -> V_346 -> V_314 = & V_2 -> V_347 ;
if ( V_2 -> V_157 . V_217 ) {
F_132 ( V_2 -> V_119 , V_348 ) ;
F_132 ( V_2 -> V_119 , V_349 ) ;
F_132 ( V_2 -> V_119 , V_350 ) ;
} else {
F_132 ( V_2 -> V_119 , V_351 ) ;
}
if ( V_2 -> V_280 == V_281 ) {
F_132 ( V_2 -> V_119 , V_352 ) ;
F_132 ( V_2 -> V_119 , V_353 ) ;
F_132 ( V_2 -> V_119 , V_354 ) ;
F_132 ( V_2 -> V_119 , V_355 ) ;
}
if ( ! V_2 -> V_277 . V_278 ) {
F_132 ( V_2 -> V_119 , V_356 ) ;
F_132 ( V_2 -> V_119 , V_357 ) ;
}
V_176 = F_133 ( V_2 -> V_119 , V_270 ,
V_358 [ V_2 -> V_359 ] ) ;
if ( V_176 ) {
F_104 ( L_50 ,
V_176 ) ;
return V_176 ;
}
if ( F_134 ( V_2 ) == 1 ) {
V_2 -> V_284 = F_120 ( V_2 , & V_344 ,
L_51 ) ;
V_2 -> V_284 -> V_346 = & V_2 -> V_145 ;
V_2 -> V_284 -> V_346 -> V_314 = & V_2 -> V_360 ;
F_132 ( V_2 -> V_119 , V_351 ) ;
if ( V_2 -> V_280 == V_281 ) {
F_132 ( V_2 -> V_284 , V_352 ) ;
F_132 ( V_2 -> V_284 , V_353 ) ;
F_132 ( V_2 -> V_284 , V_354 ) ;
F_132 ( V_2 -> V_284 , V_355 ) ;
}
if ( ! V_2 -> V_277 . V_278 ) {
F_132 ( V_2 -> V_284 , V_356 ) ;
F_132 ( V_2 -> V_284 , V_357 ) ;
}
V_176 = F_133 ( V_2 -> V_284 , V_311 ,
V_361 [ V_2 -> V_359 ] ) ;
if ( V_176 < 0 ) {
F_104 ( L_52 ) ;
return V_176 ;
}
}
if ( V_266 [ V_2 -> V_267 ] . V_362 . type == V_363 ) {
V_2 -> V_285 = F_120 ( V_2 , & V_364 ,
L_53 ) ;
if ( ! V_2 -> V_285 ) {
F_104 ( L_49 ) ;
return - V_345 ;
}
V_176 = F_133 ( V_2 -> V_285 , V_121 ,
V_365 [ V_2 -> V_359 ] ) ;
if ( V_176 < 0 ) {
F_104 ( L_54 ) ;
return V_176 ;
}
F_113 ( L_55 ,
F_101 ( V_2 -> V_285 ) ) ;
}
F_113 ( L_56 ,
F_101 ( V_2 -> V_119 ) ) ;
if ( V_2 -> V_284 )
F_113 ( L_57 ,
F_101 ( V_2 -> V_284 ) ) ;
return 0 ;
}
