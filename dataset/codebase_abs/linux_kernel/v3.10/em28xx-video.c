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
if ( V_2 -> V_112 ++ == 0 ) {
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
goto V_116;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_117 = V_2 -> V_118 ;
if ( V_92 -> V_119 && V_92 -> V_119 -> V_120 -> V_121 == V_122 )
V_110 . type = V_123 ;
else
V_110 . type = V_124 ;
F_32 ( & V_2 -> V_125 , 0 , V_126 , V_127 , & V_110 ) ;
}
V_116:
return V_111 ;
}
static int F_33 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_92 ) ;
struct V_43 * V_54 = & V_2 -> V_54 ;
unsigned long V_128 = 0 ;
F_20 ( L_24 , V_107 ) ;
F_21 ( V_2 , V_92 -> type ) ;
if ( V_2 -> V_112 -- == 1 ) {
F_34 ( V_2 , V_113 ) ;
}
F_35 ( & V_2 -> V_129 , V_128 ) ;
while ( ! F_9 ( & V_54 -> V_45 ) ) {
struct V_3 * V_4 ;
V_4 = F_10 ( V_54 -> V_45 . V_46 , struct V_3 , V_47 ) ;
F_11 ( & V_4 -> V_47 ) ;
F_4 ( & V_4 -> V_6 , V_130 ) ;
}
V_2 -> V_51 . V_52 = NULL ;
F_36 ( & V_2 -> V_129 , V_128 ) ;
return 0 ;
}
int F_37 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_23 ( V_92 ) ;
struct V_43 * V_56 = & V_2 -> V_56 ;
unsigned long V_128 = 0 ;
F_20 ( L_24 , V_107 ) ;
F_21 ( V_2 , V_92 -> type ) ;
if ( V_2 -> V_112 -- == 1 ) {
F_34 ( V_2 , V_113 ) ;
}
F_35 ( & V_2 -> V_129 , V_128 ) ;
while ( ! F_9 ( & V_56 -> V_45 ) ) {
struct V_3 * V_4 ;
V_4 = F_10 ( V_56 -> V_45 . V_46 , struct V_3 , V_47 ) ;
F_11 ( & V_4 -> V_47 ) ;
F_4 ( & V_4 -> V_6 , V_130 ) ;
}
V_2 -> V_51 . V_53 = NULL ;
F_36 ( & V_2 -> V_129 , V_128 ) ;
return 0 ;
}
static void
F_38 ( struct V_106 * V_6 )
{
struct V_1 * V_2 = F_23 ( V_6 -> V_91 ) ;
struct V_3 * V_4 = F_25 ( V_6 , struct V_3 , V_6 ) ;
struct V_43 * V_54 = & V_2 -> V_54 ;
unsigned long V_128 = 0 ;
F_20 ( L_24 , V_107 ) ;
V_4 -> V_48 = F_39 ( V_6 , 0 ) ;
V_4 -> V_27 = F_26 ( V_6 , 0 ) ;
F_35 ( & V_2 -> V_129 , V_128 ) ;
F_40 ( & V_4 -> V_47 , & V_54 -> V_45 ) ;
F_36 ( & V_2 -> V_129 , V_128 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
int V_111 ;
struct V_91 * V_131 ;
V_131 = & V_2 -> V_132 ;
V_131 -> type = V_84 ;
V_131 -> V_133 = V_134 | V_135 | V_136 | V_137 ;
V_131 -> V_138 = V_139 ;
V_131 -> V_140 = V_2 ;
V_131 -> V_141 = sizeof( struct V_3 ) ;
V_131 -> V_142 = & V_143 ;
V_131 -> V_144 = & V_145 ;
V_111 = F_42 ( V_131 ) ;
if ( V_111 < 0 )
return V_111 ;
V_131 = & V_2 -> V_146 ;
V_131 -> type = V_86 ;
V_131 -> V_133 = V_134 | V_135 | V_136 ;
V_131 -> V_138 = V_139 ;
V_131 -> V_140 = V_2 ;
V_131 -> V_141 = sizeof( struct V_3 ) ;
V_131 -> V_142 = & V_147 ;
V_131 -> V_144 = & V_145 ;
V_111 = F_42 ( V_131 ) ;
if ( V_111 < 0 )
return V_111 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 , int V_148 )
{
V_2 -> V_149 = V_148 ;
V_2 -> V_150 = F_44 ( V_148 ) -> V_151 ;
V_2 -> V_152 = F_44 ( V_148 ) -> V_153 ;
if ( ! V_2 -> V_152 )
V_2 -> V_152 = V_154 ;
F_32 ( & V_2 -> V_125 , 0 , V_155 , V_156 ,
F_44 ( V_148 ) -> V_157 , 0 , 0 ) ;
if ( V_2 -> V_158 . V_159 ) {
if ( V_2 -> V_160 ) {
F_32 ( & V_2 -> V_125 , 0 , V_161 ,
V_162 , V_2 -> V_160 ) ;
}
F_32 ( & V_2 -> V_125 , 0 , V_161 , V_156 ,
V_2 -> V_150 , F_45 ( V_163 ) , 0 ) ;
}
if ( V_2 -> V_158 . V_164 != V_165 ) {
F_32 ( & V_2 -> V_125 , 0 , V_161 , V_156 ,
V_2 -> V_150 , V_2 -> V_152 , 0 ) ;
}
F_46 ( V_2 ) ;
}
void F_47 ( struct V_166 * V_167 , void * V_168 )
{
struct V_1 * V_2 = V_168 ;
switch ( V_167 -> V_169 ) {
case V_170 :
V_2 -> V_171 = V_167 -> V_172 ;
F_46 ( V_2 ) ;
break;
case V_173 :
V_2 -> V_174 = V_167 -> V_172 ;
F_46 ( V_2 ) ;
break;
}
}
static int F_48 ( struct V_166 * V_167 )
{
struct V_1 * V_2 = F_25 ( V_167 -> V_175 , struct V_1 , V_176 ) ;
int V_177 = - V_105 ;
switch ( V_167 -> V_169 ) {
case V_170 :
V_2 -> V_171 = V_167 -> V_172 ;
V_177 = F_46 ( V_2 ) ;
break;
case V_173 :
V_2 -> V_174 = V_167 -> V_172 ;
V_177 = F_46 ( V_2 ) ;
break;
case V_178 :
V_177 = F_49 ( V_2 , V_179 , V_167 -> V_172 ) ;
break;
case V_180 :
V_177 = F_49 ( V_2 , V_181 , V_167 -> V_172 ) ;
break;
case V_182 :
V_177 = F_49 ( V_2 , V_183 , V_167 -> V_172 ) ;
break;
case V_184 :
V_177 = F_49 ( V_2 , V_185 , V_167 -> V_172 ) ;
break;
case V_186 :
V_177 = F_49 ( V_2 , V_187 , V_167 -> V_172 ) ;
break;
case V_188 :
V_177 = F_49 ( V_2 , V_189 , V_167 -> V_172 ) ;
break;
}
return ( V_177 < 0 ) ? V_177 : 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
unsigned int V_25 , unsigned int V_102 ,
unsigned int * V_190 , unsigned int * V_191 )
{
unsigned int V_192 = F_51 ( V_2 ) ;
unsigned int V_193 = F_52 ( V_2 ) ;
* V_190 = ( ( ( unsigned long ) V_192 ) << 12 ) / V_25 - 4096L ;
if ( * V_190 > V_194 )
* V_190 = V_194 ;
* V_191 = ( ( ( unsigned long ) V_193 ) << 12 ) / V_102 - 4096L ;
if ( * V_191 > V_194 )
* V_191 = V_194 ;
}
static void F_53 ( struct V_1 * V_2 ,
unsigned int V_190 , unsigned int V_191 ,
unsigned int * V_25 , unsigned int * V_102 )
{
unsigned int V_192 = F_51 ( V_2 ) ;
unsigned int V_193 = F_52 ( V_2 ) ;
* V_25 = ( ( ( unsigned long ) V_192 ) << 12 ) / ( V_190 + 4096L ) ;
* V_102 = ( ( ( unsigned long ) V_193 ) << 12 ) / ( V_191 + 4096L ) ;
}
static int F_54 ( struct V_195 * V_195 , void * V_168 ,
struct V_93 * V_110 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
V_110 -> V_94 . V_100 . V_25 = V_2 -> V_25 ;
V_110 -> V_94 . V_100 . V_102 = V_2 -> V_102 ;
V_110 -> V_94 . V_100 . V_198 = V_2 -> V_103 -> V_199 ;
V_110 -> V_94 . V_100 . V_24 = ( V_2 -> V_25 * V_2 -> V_103 -> V_104 + 7 ) >> 3 ;
V_110 -> V_94 . V_100 . V_101 = V_110 -> V_94 . V_100 . V_24 * V_2 -> V_102 ;
V_110 -> V_94 . V_100 . V_200 = V_201 ;
if ( V_2 -> V_28 )
V_110 -> V_94 . V_100 . V_10 = V_202 ;
else
V_110 -> V_94 . V_100 . V_10 = V_2 -> V_203 ?
V_11 : V_204 ;
return 0 ;
}
static struct V_205 * F_55 ( unsigned int V_199 )
{
unsigned int V_71 ;
for ( V_71 = 0 ; V_71 < F_56 ( V_103 ) ; V_71 ++ )
if ( V_103 [ V_71 ] . V_199 == V_199 )
return & V_103 [ V_71 ] ;
return NULL ;
}
static int F_57 ( struct V_195 * V_195 , void * V_168 ,
struct V_93 * V_110 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
unsigned int V_25 = V_110 -> V_94 . V_100 . V_25 ;
unsigned int V_102 = V_110 -> V_94 . V_100 . V_102 ;
unsigned int V_192 = F_51 ( V_2 ) ;
unsigned int V_193 = F_52 ( V_2 ) ;
unsigned int V_190 , V_191 ;
struct V_205 * V_94 ;
V_94 = F_55 ( V_110 -> V_94 . V_100 . V_198 ) ;
if ( ! V_94 ) {
F_20 ( L_25 ,
V_110 -> V_94 . V_100 . V_198 ) ;
return - V_105 ;
}
if ( V_2 -> V_158 . V_206 ) {
V_102 = V_102 > ( 3 * V_193 / 4 ) ? V_193 : V_193 / 2 ;
V_25 = V_25 > ( 3 * V_192 / 4 ) ? V_192 : V_192 / 2 ;
if ( V_25 == V_192 && V_102 == V_193 )
V_25 /= 2 ;
} else {
F_58 ( & V_25 , 48 , V_192 , 1 , & V_102 , 32 , V_193 ,
1 , 0 ) ;
}
F_50 ( V_2 , V_25 , V_102 , & V_190 , & V_191 ) ;
F_53 ( V_2 , V_190 , V_191 , & V_25 , & V_102 ) ;
V_110 -> V_94 . V_100 . V_25 = V_25 ;
V_110 -> V_94 . V_100 . V_102 = V_102 ;
V_110 -> V_94 . V_100 . V_198 = V_94 -> V_199 ;
V_110 -> V_94 . V_100 . V_24 = ( V_25 * V_94 -> V_104 + 7 ) >> 3 ;
V_110 -> V_94 . V_100 . V_101 = V_110 -> V_94 . V_100 . V_24 * V_102 ;
V_110 -> V_94 . V_100 . V_200 = V_201 ;
if ( V_2 -> V_28 )
V_110 -> V_94 . V_100 . V_10 = V_202 ;
else
V_110 -> V_94 . V_100 . V_10 = V_2 -> V_203 ?
V_11 : V_204 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , unsigned int V_199 ,
unsigned V_25 , unsigned V_102 )
{
struct V_205 * V_94 ;
V_94 = F_55 ( V_199 ) ;
if ( ! V_94 )
return - V_105 ;
V_2 -> V_103 = V_94 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_102 = V_102 ;
F_50 ( V_2 , V_2 -> V_25 , V_2 -> V_102 , & V_2 -> V_190 , & V_2 -> V_191 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_195 * V_195 , void * V_168 ,
struct V_93 * V_110 )
{
struct V_1 * V_2 = F_62 ( V_195 ) ;
if ( V_2 -> V_112 > 0 )
return - V_90 ;
F_57 ( V_195 , V_168 , V_110 ) ;
return F_59 ( V_2 , V_110 -> V_94 . V_100 . V_198 ,
V_110 -> V_94 . V_100 . V_25 , V_110 -> V_94 . V_100 . V_102 ) ;
}
static int F_63 ( struct V_195 * V_195 , void * V_168 , T_1 * V_207 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
* V_207 = V_2 -> V_207 ;
return 0 ;
}
static int F_64 ( struct V_195 * V_195 , void * V_168 , T_1 * V_207 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
F_32 ( & V_2 -> V_125 , 0 , V_155 , V_208 , V_207 ) ;
return 0 ;
}
static int F_65 ( struct V_195 * V_195 , void * V_168 , T_1 V_207 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
struct V_93 V_110 ;
if ( V_207 == V_2 -> V_207 )
return 0 ;
if ( V_2 -> V_112 > 0 )
return - V_90 ;
V_2 -> V_207 = V_207 ;
V_110 . V_94 . V_100 . V_25 = 720 ;
V_110 . V_94 . V_100 . V_102 = ( V_207 & V_209 ) ? 480 : 576 ;
F_57 ( V_195 , V_168 , & V_110 ) ;
V_2 -> V_25 = V_110 . V_94 . V_100 . V_25 ;
V_2 -> V_102 = V_110 . V_94 . V_100 . V_102 ;
F_50 ( V_2 , V_2 -> V_25 , V_2 -> V_102 , & V_2 -> V_190 , & V_2 -> V_191 ) ;
F_60 ( V_2 ) ;
F_32 ( & V_2 -> V_125 , 0 , V_210 , V_211 , V_2 -> V_207 ) ;
return 0 ;
}
static int F_66 ( struct V_195 * V_195 , void * V_168 ,
struct V_212 * V_213 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
int V_111 = 0 ;
V_213 -> V_214 . V_215 . V_216 = V_217 ;
if ( V_2 -> V_158 . V_218 )
V_111 = F_67 ( & V_2 -> V_125 , 0 ,
V_155 , V_219 , V_213 ) ;
else
F_68 ( V_2 -> V_207 ,
& V_213 -> V_214 . V_215 . V_220 ) ;
return V_111 ;
}
static int F_69 ( struct V_195 * V_195 , void * V_168 ,
struct V_212 * V_213 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
V_213 -> V_214 . V_215 . V_216 = V_217 ;
return F_67 ( & V_2 -> V_125 , 0 , V_155 , V_221 , V_213 ) ;
}
static int F_70 ( struct V_195 * V_195 , void * V_168 ,
struct V_222 * V_71 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
unsigned int V_223 ;
V_223 = V_71 -> V_148 ;
if ( V_223 >= V_224 )
return - V_105 ;
if ( 0 == F_44 ( V_223 ) -> type )
return - V_105 ;
V_71 -> V_148 = V_223 ;
V_71 -> type = V_225 ;
strcpy ( V_71 -> V_226 , V_227 [ F_44 ( V_223 ) -> type ] ) ;
if ( ( V_228 == F_44 ( V_223 ) -> type ) ||
( V_229 == F_44 ( V_223 ) -> type ) )
V_71 -> type = V_230 ;
V_71 -> V_231 = V_2 -> V_120 -> V_232 ;
if ( V_2 -> V_158 . V_218 )
V_71 -> V_233 = 0 ;
return 0 ;
}
static int F_71 ( struct V_195 * V_195 , void * V_168 , unsigned int * V_71 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
* V_71 = V_2 -> V_149 ;
return 0 ;
}
static int F_72 ( struct V_195 * V_195 , void * V_168 , unsigned int V_71 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
if ( V_71 >= V_224 )
return - V_105 ;
if ( 0 == F_44 ( V_71 ) -> type )
return - V_105 ;
F_43 ( V_2 , V_71 ) ;
return 0 ;
}
static int F_73 ( struct V_195 * V_195 , void * V_168 , struct V_234 * V_235 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
switch ( V_235 -> V_148 ) {
case V_236 :
strcpy ( V_235 -> V_226 , L_26 ) ;
break;
case V_237 :
strcpy ( V_235 -> V_226 , L_27 ) ;
break;
case V_238 :
strcpy ( V_235 -> V_226 , L_28 ) ;
break;
case V_239 :
strcpy ( V_235 -> V_226 , L_29 ) ;
break;
case V_240 :
strcpy ( V_235 -> V_226 , L_30 ) ;
break;
case V_241 :
strcpy ( V_235 -> V_226 , L_31 ) ;
break;
case V_242 :
strcpy ( V_235 -> V_226 , L_32 ) ;
break;
case V_243 :
strcpy ( V_235 -> V_226 , L_33 ) ;
break;
default:
return - V_105 ;
}
V_235 -> V_148 = V_2 -> V_150 ;
V_235 -> V_244 = V_245 ;
return 0 ;
}
static int F_74 ( struct V_195 * V_195 , void * V_168 , const struct V_234 * V_235 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
if ( V_235 -> V_148 >= V_224 )
return - V_105 ;
if ( 0 == F_44 ( V_235 -> V_148 ) -> type )
return - V_105 ;
V_2 -> V_150 = F_44 ( V_235 -> V_148 ) -> V_151 ;
V_2 -> V_152 = F_44 ( V_235 -> V_148 ) -> V_153 ;
if ( ! V_2 -> V_152 )
V_2 -> V_152 = V_154 ;
return 0 ;
}
static int F_75 ( struct V_195 * V_195 , void * V_168 ,
struct V_246 * V_247 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
if ( 0 != V_247 -> V_148 )
return - V_105 ;
strcpy ( V_247 -> V_226 , L_34 ) ;
F_32 ( & V_2 -> V_125 , 0 , V_126 , V_248 , V_247 ) ;
return 0 ;
}
static int F_76 ( struct V_195 * V_195 , void * V_168 ,
const struct V_246 * V_247 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
if ( 0 != V_247 -> V_148 )
return - V_105 ;
F_32 ( & V_2 -> V_125 , 0 , V_126 , V_249 , V_247 ) ;
return 0 ;
}
static int F_77 ( struct V_195 * V_195 , void * V_168 ,
struct V_109 * V_110 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
if ( 0 != V_110 -> V_126 )
return - V_105 ;
V_110 -> V_117 = V_2 -> V_118 ;
return 0 ;
}
static int F_78 ( struct V_195 * V_195 , void * V_168 ,
const struct V_109 * V_110 )
{
struct V_109 V_250 = * V_110 ;
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
if ( 0 != V_110 -> V_126 )
return - V_105 ;
F_32 ( & V_2 -> V_125 , 0 , V_126 , V_127 , V_110 ) ;
F_32 ( & V_2 -> V_125 , 0 , V_126 , V_251 , & V_250 ) ;
V_2 -> V_118 = V_250 . V_117 ;
return 0 ;
}
static int F_79 ( struct V_195 * V_195 , void * V_168 ,
struct V_252 * V_253 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
V_253 -> V_254 = V_255 ;
V_253 -> V_256 = 0 ;
if ( V_253 -> V_257 . type == V_258 ) {
if ( V_253 -> V_257 . V_259 > 1 )
return - V_105 ;
return 0 ;
}
if ( V_253 -> V_257 . type != V_260 &&
V_253 -> V_257 . type != V_261 )
return - V_105 ;
F_32 ( & V_2 -> V_125 , 0 , V_210 , V_262 , V_253 ) ;
return 0 ;
}
static int F_80 ( struct V_195 * V_195 , void * V_168 ,
struct V_263 * V_253 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
if ( V_253 -> V_257 . V_259 > 1 )
return - V_105 ;
if ( V_253 -> V_257 . V_259 == 1 )
F_81 ( V_253 -> V_226 , L_35 , sizeof( V_253 -> V_226 ) ) ;
else
F_81 ( V_253 -> V_226 , V_2 -> V_125 . V_226 , sizeof( V_253 -> V_226 ) ) ;
return 0 ;
}
static int F_82 ( int V_264 )
{
switch ( V_264 ) {
case V_265 :
case V_266 :
case V_267 :
return 2 ;
default:
return 1 ;
}
}
static int F_83 ( struct V_195 * V_195 , void * V_168 ,
struct V_268 * V_264 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
int V_177 ;
switch ( V_264 -> V_257 . type ) {
case V_258 :
if ( V_264 -> V_257 . V_259 > 1 )
return - V_105 ;
if ( ! V_264 -> V_257 . V_259 )
break;
case V_269 :
V_177 = F_84 ( V_2 , V_264 -> V_264 ) ;
if ( V_177 < 0 )
return V_177 ;
V_264 -> V_172 = V_177 ;
V_264 -> V_99 = 1 ;
return 0 ;
case V_260 :
F_32 ( & V_2 -> V_125 , 0 , V_210 , V_270 , V_264 ) ;
return 0 ;
case V_261 :
F_32 ( & V_2 -> V_125 , 0 , V_210 , V_270 , V_264 ) ;
return 0 ;
default:
return - V_105 ;
}
V_264 -> V_99 = F_82 ( V_264 -> V_264 ) ;
if ( V_264 -> V_99 == 1 ) {
V_177 = F_85 ( V_2 , V_264 -> V_264 ) ;
if ( V_177 < 0 )
return V_177 ;
V_264 -> V_172 = V_177 ;
} else {
T_2 V_172 = 0 ;
V_177 = F_86 ( V_2 , V_271 ,
V_264 -> V_264 , ( char * ) & V_172 , 2 ) ;
if ( V_177 < 0 )
return V_177 ;
V_264 -> V_172 = F_87 ( V_172 ) ;
}
return 0 ;
}
static int F_88 ( struct V_195 * V_195 , void * V_168 ,
const struct V_268 * V_264 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
T_2 V_4 ;
switch ( V_264 -> V_257 . type ) {
case V_258 :
if ( V_264 -> V_257 . V_259 > 1 )
return - V_105 ;
if ( ! V_264 -> V_257 . V_259 )
break;
case V_269 :
return F_89 ( V_2 , V_264 -> V_264 , V_264 -> V_172 ) ;
case V_260 :
F_32 ( & V_2 -> V_125 , 0 , V_210 , V_272 , V_264 ) ;
return 0 ;
case V_261 :
F_32 ( & V_2 -> V_125 , 0 , V_210 , V_272 , V_264 ) ;
return 0 ;
default:
return - V_105 ;
}
V_4 = F_90 ( V_264 -> V_172 ) ;
return F_91 ( V_2 , V_264 -> V_264 , ( char * ) & V_4 ,
F_82 ( V_264 -> V_264 ) ) ;
}
static int F_92 ( struct V_195 * V_195 , void * V_168 ,
struct V_273 * V_274 )
{
struct V_275 * V_120 = F_93 ( V_195 ) ;
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
F_81 ( V_274 -> V_276 , L_36 , sizeof( V_274 -> V_276 ) ) ;
F_81 ( V_274 -> V_277 , V_278 [ V_2 -> V_279 ] . V_226 , sizeof( V_274 -> V_277 ) ) ;
F_94 ( V_2 -> V_280 , V_274 -> V_281 , sizeof( V_274 -> V_281 ) ) ;
if ( V_120 -> V_121 == V_282 )
V_274 -> V_283 = V_284 |
V_285 | V_286 ;
else if ( V_120 -> V_121 == V_122 )
V_274 -> V_283 = V_287 ;
else
V_274 -> V_283 = V_284 | V_288 ;
if ( V_2 -> V_289 . V_290 )
V_274 -> V_283 |= V_291 ;
if ( V_2 -> V_292 != V_293 )
V_274 -> V_283 |= V_294 ;
V_274 -> V_233 = V_274 -> V_283 | V_295 |
V_284 | V_285 | V_286 ;
if ( V_2 -> V_296 )
V_274 -> V_233 |= V_288 ;
if ( V_2 -> V_297 )
V_274 -> V_233 |= V_287 ;
return 0 ;
}
static int F_95 ( struct V_195 * V_195 , void * V_168 ,
struct V_298 * V_110 )
{
if ( F_96 ( V_110 -> V_148 >= F_56 ( V_103 ) ) )
return - V_105 ;
F_81 ( V_110 -> V_299 , V_103 [ V_110 -> V_148 ] . V_226 , sizeof( V_110 -> V_299 ) ) ;
V_110 -> V_198 = V_103 [ V_110 -> V_148 ] . V_199 ;
return 0 ;
}
static int F_97 ( struct V_195 * V_195 , void * V_168 ,
struct V_300 * V_301 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
struct V_205 * V_94 ;
unsigned int V_192 = F_51 ( V_2 ) ;
unsigned int V_193 = F_52 ( V_2 ) ;
V_94 = F_55 ( V_301 -> V_302 ) ;
if ( ! V_94 ) {
F_20 ( L_25 ,
V_301 -> V_302 ) ;
return - V_105 ;
}
if ( V_2 -> V_158 . V_206 ) {
if ( V_301 -> V_148 > 1 )
return - V_105 ;
V_301 -> type = V_303 ;
V_301 -> V_304 . V_25 = V_192 / ( 1 + V_301 -> V_148 ) ;
V_301 -> V_304 . V_102 = V_193 / ( 1 + V_301 -> V_148 ) ;
return 0 ;
}
if ( V_301 -> V_148 != 0 )
return - V_105 ;
V_301 -> type = V_305 ;
F_53 ( V_2 , V_194 , V_194 ,
& V_301 -> V_306 . V_307 , & V_301 -> V_306 . V_308 ) ;
if ( V_301 -> V_306 . V_307 < 48 )
V_301 -> V_306 . V_307 = 48 ;
if ( V_301 -> V_306 . V_308 < 38 )
V_301 -> V_306 . V_308 = 38 ;
V_301 -> V_306 . V_309 = V_192 ;
V_301 -> V_306 . V_310 = V_193 ;
V_301 -> V_306 . V_311 = 1 ;
V_301 -> V_306 . V_312 = 1 ;
return 0 ;
}
static int F_98 ( struct V_195 * V_195 , void * V_168 ,
struct V_93 * V_103 )
{
struct V_196 * V_197 = V_168 ;
struct V_1 * V_2 = V_197 -> V_2 ;
V_103 -> V_94 . V_313 . V_314 = V_2 -> V_30 ;
V_103 -> V_94 . V_313 . V_315 = V_316 ;
V_103 -> V_94 . V_313 . V_21 = 0 ;
V_103 -> V_94 . V_313 . V_128 = 0 ;
V_103 -> V_94 . V_313 . V_317 = 6750000 * 4 / 2 ;
V_103 -> V_94 . V_313 . V_108 [ 0 ] = V_2 -> V_31 ;
V_103 -> V_94 . V_313 . V_108 [ 1 ] = V_2 -> V_31 ;
memset ( V_103 -> V_94 . V_313 . V_318 , 0 , sizeof( V_103 -> V_94 . V_313 . V_318 ) ) ;
if ( V_2 -> V_207 & V_209 ) {
V_103 -> V_94 . V_313 . V_319 [ 0 ] = 10 ;
V_103 -> V_94 . V_313 . V_319 [ 1 ] = 273 ;
} else if ( V_2 -> V_207 & V_320 ) {
V_103 -> V_94 . V_313 . V_319 [ 0 ] = 6 ;
V_103 -> V_94 . V_313 . V_319 [ 1 ] = 318 ;
}
return 0 ;
}
static int F_99 ( struct V_195 * V_195 , void * V_168 ,
struct V_246 * V_247 )
{
struct V_1 * V_2 = ( (struct V_196 * ) V_168 ) -> V_2 ;
if ( F_96 ( V_247 -> V_148 > 0 ) )
return - V_105 ;
strcpy ( V_247 -> V_226 , L_37 ) ;
F_32 ( & V_2 -> V_125 , 0 , V_126 , V_248 , V_247 ) ;
return 0 ;
}
static int F_100 ( struct V_195 * V_195 , void * V_168 ,
const struct V_246 * V_247 )
{
struct V_1 * V_2 = ( (struct V_196 * ) V_168 ) -> V_2 ;
if ( 0 != V_247 -> V_148 )
return - V_105 ;
F_32 ( & V_2 -> V_125 , 0 , V_126 , V_249 , V_247 ) ;
return 0 ;
}
static int F_101 ( struct V_195 * V_321 )
{
struct V_275 * V_120 = F_93 ( V_321 ) ;
struct V_1 * V_2 = F_62 ( V_321 ) ;
enum V_82 V_322 = 0 ;
struct V_196 * V_197 ;
switch ( V_120 -> V_121 ) {
case V_282 :
V_322 = V_84 ;
break;
case V_323 :
V_322 = V_86 ;
break;
}
F_20 ( L_38 ,
F_102 ( V_120 ) , V_324 [ V_322 ] ,
V_2 -> V_325 ) ;
if ( F_103 ( & V_2 -> V_326 ) )
return - V_327 ;
V_197 = F_104 ( sizeof( struct V_196 ) , V_328 ) ;
if ( ! V_197 ) {
F_105 ( L_39 ) ;
F_106 ( & V_2 -> V_326 ) ;
return - V_329 ;
}
F_107 ( & V_197 -> V_197 , V_120 ) ;
V_197 -> V_2 = V_2 ;
V_197 -> type = V_322 ;
V_321 -> V_330 = V_197 ;
if ( V_197 -> type == V_84 && V_2 -> V_325 == 0 ) {
F_108 ( V_2 , V_113 ) ;
F_60 ( V_2 ) ;
F_30 ( V_2 ) ;
}
if ( V_120 -> V_121 == V_122 ) {
F_20 ( L_40 ) ;
F_32 ( & V_2 -> V_125 , 0 , V_126 , V_331 ) ;
}
V_2 -> V_325 ++ ;
F_106 ( & V_2 -> V_326 ) ;
F_109 ( & V_197 -> V_197 ) ;
return 0 ;
}
void F_110 ( struct V_1 * V_2 )
{
if ( V_2 -> V_297 ) {
if ( F_111 ( V_2 -> V_297 ) )
F_112 ( V_2 -> V_297 ) ;
else
F_113 ( V_2 -> V_297 ) ;
V_2 -> V_297 = NULL ;
}
if ( V_2 -> V_296 ) {
F_114 ( L_41 ,
F_102 ( V_2 -> V_296 ) ) ;
if ( F_111 ( V_2 -> V_296 ) )
F_112 ( V_2 -> V_296 ) ;
else
F_113 ( V_2 -> V_296 ) ;
V_2 -> V_296 = NULL ;
}
if ( V_2 -> V_120 ) {
F_114 ( L_41 ,
F_102 ( V_2 -> V_120 ) ) ;
if ( F_111 ( V_2 -> V_120 ) )
F_112 ( V_2 -> V_120 ) ;
else
F_113 ( V_2 -> V_120 ) ;
V_2 -> V_120 = NULL ;
}
}
static int F_115 ( struct V_195 * V_321 )
{
struct V_196 * V_197 = V_321 -> V_330 ;
struct V_1 * V_2 = V_197 -> V_2 ;
int V_332 ;
F_20 ( L_42 , V_2 -> V_325 ) ;
F_116 ( & V_2 -> V_326 ) ;
F_117 ( V_321 ) ;
if ( V_2 -> V_325 == 1 ) {
if ( V_2 -> V_74 ) {
F_118 ( V_2 ) ;
F_119 ( V_2 -> V_333 ) ;
F_106 ( & V_2 -> V_326 ) ;
F_119 ( V_2 ) ;
return 0 ;
}
F_32 ( & V_2 -> V_125 , 0 , V_210 , V_334 , 0 ) ;
F_108 ( V_2 , V_335 ) ;
V_2 -> V_336 = 0 ;
F_20 ( L_43 ) ;
V_332 = F_120 ( V_2 -> V_280 , 0 , 0 ) ;
if ( V_332 < 0 ) {
F_105 ( L_44
L_45 , V_332 ) ;
}
}
V_2 -> V_325 -- ;
F_106 ( & V_2 -> V_326 ) ;
return 0 ;
}
static struct V_275 * F_121 ( struct V_1 * V_2 ,
const struct V_275 * V_337 ,
const char * V_338 )
{
struct V_275 * V_339 ;
V_339 = F_122 () ;
if ( NULL == V_339 )
return NULL ;
* V_339 = * V_337 ;
V_339 -> V_125 = & V_2 -> V_125 ;
V_339 -> V_340 = V_341 ;
V_339 -> V_326 = & V_2 -> V_326 ;
F_123 ( V_342 , & V_339 -> V_128 ) ;
if ( V_2 -> V_158 . V_218 )
V_339 -> V_232 = 0 ;
snprintf ( V_339 -> V_226 , sizeof( V_339 -> V_226 ) , L_46 ,
V_2 -> V_226 , V_338 ) ;
F_124 ( V_339 , V_2 ) ;
return V_339 ;
}
int F_125 ( struct V_1 * V_2 )
{
T_3 V_172 ;
int V_177 ;
unsigned int V_192 ;
F_126 ( V_343 L_47 ,
V_2 -> V_226 , V_344 ) ;
V_2 -> V_207 = V_345 ;
F_32 ( & V_2 -> V_125 , 0 , V_210 , V_211 , V_2 -> V_207 ) ;
V_2 -> V_203 = V_346 ;
V_2 -> V_103 = & V_103 [ 0 ] ;
V_192 = F_51 ( V_2 ) ;
if ( V_2 -> V_158 . V_206 )
V_192 /= 2 ;
F_59 ( V_2 , V_103 [ 0 ] . V_199 ,
V_192 , F_52 ( V_2 ) ) ;
F_43 ( V_2 , 0 ) ;
V_2 -> V_171 = 1 ;
V_2 -> V_174 = 0x1f ;
V_172 = ( T_3 ) F_85 ( V_2 , V_347 ) ;
F_49 ( V_2 , V_347 ,
( V_348 | V_172 ) ) ;
F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
if ( NULL == F_129 ( & V_2 -> V_176 , V_178 ) )
F_130 ( & V_2 -> V_176 , & V_349 ,
V_178 ,
0 , 0x1f , 1 , V_350 ) ;
if ( NULL == F_129 ( & V_2 -> V_176 , V_180 ) )
F_130 ( & V_2 -> V_176 , & V_349 ,
V_180 ,
- 0x80 , 0x7f , 1 , V_351 ) ;
if ( NULL == F_129 ( & V_2 -> V_176 , V_182 ) )
F_130 ( & V_2 -> V_176 , & V_349 ,
V_182 ,
0 , 0x1f , 1 , V_352 ) ;
if ( NULL == F_129 ( & V_2 -> V_176 , V_184 ) )
F_130 ( & V_2 -> V_176 , & V_349 ,
V_184 ,
- 0x30 , 0x30 , 1 , V_353 ) ;
if ( NULL == F_129 ( & V_2 -> V_176 , V_186 ) )
F_130 ( & V_2 -> V_176 , & V_349 ,
V_186 ,
- 0x30 , 0x30 , 1 , V_354 ) ;
if ( NULL == F_129 ( & V_2 -> V_176 , V_188 ) )
F_130 ( & V_2 -> V_176 , & V_349 ,
V_188 ,
0 , 0x0f , 1 , V_355 ) ;
F_131 ( V_2 ) ;
F_132 ( & V_2 -> V_176 ) ;
if ( V_2 -> V_176 . error )
return V_2 -> V_176 . error ;
V_2 -> V_120 = F_121 ( V_2 , & V_356 , L_48 ) ;
if ( ! V_2 -> V_120 ) {
F_105 ( L_49 ) ;
return - V_357 ;
}
V_2 -> V_120 -> V_358 = & V_2 -> V_132 ;
V_2 -> V_120 -> V_358 -> V_326 = & V_2 -> V_359 ;
if ( V_2 -> V_158 . V_218 ) {
F_133 ( V_2 -> V_120 , V_360 ) ;
F_133 ( V_2 -> V_120 , V_361 ) ;
F_133 ( V_2 -> V_120 , V_362 ) ;
} else {
F_133 ( V_2 -> V_120 , V_363 ) ;
}
if ( V_2 -> V_292 == V_293 ) {
F_133 ( V_2 -> V_120 , V_364 ) ;
F_133 ( V_2 -> V_120 , V_365 ) ;
F_133 ( V_2 -> V_120 , V_366 ) ;
F_133 ( V_2 -> V_120 , V_367 ) ;
}
if ( ! V_2 -> V_289 . V_290 ) {
F_133 ( V_2 -> V_120 , V_368 ) ;
F_133 ( V_2 -> V_120 , V_369 ) ;
}
V_177 = F_134 ( V_2 -> V_120 , V_282 ,
V_370 [ V_2 -> V_371 ] ) ;
if ( V_177 ) {
F_105 ( L_50 ,
V_177 ) ;
return V_177 ;
}
if ( F_135 ( V_2 ) == 1 ) {
V_2 -> V_296 = F_121 ( V_2 , & V_356 ,
L_51 ) ;
V_2 -> V_296 -> V_358 = & V_2 -> V_146 ;
V_2 -> V_296 -> V_358 -> V_326 = & V_2 -> V_372 ;
F_133 ( V_2 -> V_120 , V_363 ) ;
if ( V_2 -> V_292 == V_293 ) {
F_133 ( V_2 -> V_296 , V_364 ) ;
F_133 ( V_2 -> V_296 , V_365 ) ;
F_133 ( V_2 -> V_296 , V_366 ) ;
F_133 ( V_2 -> V_296 , V_367 ) ;
}
if ( ! V_2 -> V_289 . V_290 ) {
F_133 ( V_2 -> V_296 , V_368 ) ;
F_133 ( V_2 -> V_296 , V_369 ) ;
}
V_177 = F_134 ( V_2 -> V_296 , V_323 ,
V_373 [ V_2 -> V_371 ] ) ;
if ( V_177 < 0 ) {
F_105 ( L_52 ) ;
return V_177 ;
}
}
if ( V_278 [ V_2 -> V_279 ] . V_374 . type == V_375 ) {
V_2 -> V_297 = F_121 ( V_2 , & V_376 ,
L_53 ) ;
if ( ! V_2 -> V_297 ) {
F_105 ( L_49 ) ;
return - V_357 ;
}
V_177 = F_134 ( V_2 -> V_297 , V_122 ,
V_377 [ V_2 -> V_371 ] ) ;
if ( V_177 < 0 ) {
F_105 ( L_54 ) ;
return V_177 ;
}
F_114 ( L_55 ,
F_102 ( V_2 -> V_297 ) ) ;
}
F_114 ( L_56 ,
F_102 ( V_2 -> V_120 ) ) ;
if ( V_2 -> V_296 )
F_114 ( L_57 ,
F_102 ( V_2 -> V_296 ) ) ;
return 0 ;
}
