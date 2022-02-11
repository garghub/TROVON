static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = (struct V_5 * ) ( V_2 -> V_7 ) ;
switch ( V_6 -> V_8 ) {
#ifdef F_2
case F_3 ( V_9 ) :
return F_4 ( V_6 -> V_10 , V_2 ) ;
#endif
default:
F_5 ( L_1 ,
V_4 -> V_11 , F_6 ( V_6 -> V_8 ) ) ;
memcpy ( V_6 -> V_12 , V_4 -> V_13 , V_14 ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_15 , const void * V_16 ,
unsigned int V_17 )
{
struct V_18 * V_19 = V_18 ( V_4 ) ;
struct V_20 * V_21 ;
unsigned int V_22 = 0 ;
T_1 V_23 = 0 ;
int V_24 ;
if ( ! ( V_19 -> V_25 & V_26 ) ) {
V_21 = (struct V_20 * ) F_8 ( V_2 , V_27 ) ;
V_23 = V_19 -> V_28 ;
V_23 |= F_9 ( V_4 , V_2 -> V_29 ) ;
V_21 -> V_30 = F_3 ( V_23 ) ;
if ( type != V_31 && type != V_32 )
V_21 -> V_8 = F_3 ( type ) ;
else
V_21 -> V_8 = F_3 ( V_17 ) ;
V_2 -> V_33 = V_19 -> V_34 ;
type = F_6 ( V_19 -> V_34 ) ;
V_22 = V_27 ;
}
if ( V_16 == NULL )
V_16 = V_4 -> V_13 ;
V_4 = V_19 -> V_35 ;
V_24 = F_10 ( V_2 , V_4 , type , V_15 , V_16 , V_17 + V_22 ) ;
if ( V_24 > 0 )
V_24 += V_22 ;
return V_24 ;
}
static inline T_2 F_11 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
#ifdef F_12
if ( V_19 -> V_36 )
F_13 ( V_19 -> V_36 , V_2 ) ;
#else
F_14 () ;
#endif
return V_37 ;
}
static T_2 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_18 * V_19 = V_18 ( V_4 ) ;
struct V_5 * V_6 = (struct V_5 * ) ( V_2 -> V_7 ) ;
unsigned int V_17 ;
int V_38 ;
if ( V_6 -> V_39 != V_19 -> V_34 ||
V_19 -> V_25 & V_26 ) {
T_1 V_23 ;
V_23 = V_19 -> V_28 ;
V_23 |= F_9 ( V_4 , V_2 -> V_29 ) ;
V_2 = F_16 ( V_2 , V_19 -> V_34 , V_23 ) ;
}
V_2 -> V_4 = V_19 -> V_35 ;
V_17 = V_2 -> V_17 ;
if ( F_17 ( F_18 ( V_4 ) ) )
return F_11 ( V_19 , V_2 ) ;
V_38 = F_19 ( V_2 ) ;
if ( F_20 ( V_38 == V_40 || V_38 == V_41 ) ) {
struct V_42 * V_43 ;
V_43 = F_21 ( V_19 -> V_42 ) ;
F_22 ( & V_43 -> V_44 ) ;
V_43 -> V_45 ++ ;
V_43 -> V_46 += V_17 ;
F_23 ( & V_43 -> V_44 ) ;
} else {
F_24 ( V_19 -> V_42 -> V_47 ) ;
}
return V_38 ;
}
static int F_25 ( struct V_3 * V_4 , int V_48 )
{
if ( V_18 ( V_4 ) -> V_35 -> V_49 < V_48 )
return - V_50 ;
V_4 -> V_49 = V_48 ;
return 0 ;
}
void F_26 ( const struct V_3 * V_4 ,
T_3 V_51 , T_1 V_52 )
{
struct V_18 * V_19 = V_18 ( V_4 ) ;
if ( V_19 -> V_53 [ V_52 & 0x7 ] && ! V_51 )
V_19 -> V_54 -- ;
else if ( ! V_19 -> V_53 [ V_52 & 0x7 ] && V_51 )
V_19 -> V_54 ++ ;
V_19 -> V_53 [ V_52 & 0x7 ] = V_51 ;
}
int F_27 ( const struct V_3 * V_4 ,
T_3 V_51 , T_1 V_52 )
{
struct V_18 * V_19 = V_18 ( V_4 ) ;
struct V_55 * V_56 = NULL ;
struct V_55 * V_57 ;
T_3 V_58 = ( V_52 << V_59 ) & V_60 ;
V_56 = V_19 -> V_61 [ V_51 & 0xF ] ;
while ( V_56 ) {
if ( V_56 -> V_29 == V_51 ) {
if ( V_56 -> V_58 && ! V_58 )
V_19 -> V_62 -- ;
else if ( ! V_56 -> V_58 && V_58 )
V_19 -> V_62 ++ ;
V_56 -> V_58 = V_58 ;
return 0 ;
}
V_56 = V_56 -> V_63 ;
}
V_56 = V_19 -> V_61 [ V_51 & 0xF ] ;
V_57 = F_28 ( sizeof( struct V_55 ) , V_64 ) ;
if ( ! V_57 )
return - V_65 ;
V_57 -> V_63 = V_56 ;
V_57 -> V_29 = V_51 ;
V_57 -> V_58 = V_58 ;
F_29 () ;
V_19 -> V_61 [ V_51 & 0xF ] = V_57 ;
if ( V_58 )
V_19 -> V_62 ++ ;
return 0 ;
}
int F_30 ( const struct V_3 * V_4 , T_3 V_25 , T_3 V_66 )
{
struct V_18 * V_19 = V_18 ( V_4 ) ;
T_3 V_67 = V_19 -> V_25 ;
if ( V_66 & ~ ( V_26 | V_68 |
V_69 | V_70 ) )
return - V_71 ;
V_19 -> V_25 = ( V_67 & ~ V_66 ) | ( V_25 & V_66 ) ;
if ( F_31 ( V_4 ) && ( V_19 -> V_25 ^ V_67 ) & V_68 ) {
if ( V_19 -> V_25 & V_68 )
F_32 ( V_4 ) ;
else
F_33 ( V_4 ) ;
}
if ( F_31 ( V_4 ) && ( V_19 -> V_25 ^ V_67 ) & V_70 ) {
if ( V_19 -> V_25 & V_70 )
F_34 ( V_4 ) ;
else
F_35 ( V_4 ) ;
}
return 0 ;
}
void F_36 ( const struct V_3 * V_4 , char * V_72 )
{
strncpy ( V_72 , V_18 ( V_4 ) -> V_35 -> V_11 , 23 ) ;
}
static int F_37 ( struct V_3 * V_4 )
{
struct V_18 * V_19 = V_18 ( V_4 ) ;
struct V_3 * V_35 = V_19 -> V_35 ;
int V_73 ;
if ( ! ( V_35 -> V_25 & V_74 ) &&
! ( V_19 -> V_25 & V_69 ) )
return - V_75 ;
if ( ! F_38 ( V_4 -> V_13 , V_35 -> V_13 ) ) {
V_73 = F_39 ( V_35 , V_4 -> V_13 ) ;
if ( V_73 < 0 )
goto V_76;
}
if ( V_4 -> V_25 & V_77 ) {
V_73 = F_40 ( V_35 , 1 ) ;
if ( V_73 < 0 )
goto V_78;
}
if ( V_4 -> V_25 & V_79 ) {
V_73 = F_41 ( V_35 , 1 ) ;
if ( V_73 < 0 )
goto V_80;
}
memcpy ( V_19 -> V_81 , V_35 -> V_13 , V_14 ) ;
if ( V_19 -> V_25 & V_68 )
F_32 ( V_4 ) ;
if ( V_19 -> V_25 & V_70 )
F_34 ( V_4 ) ;
if ( F_42 ( V_35 ) )
F_43 ( V_4 ) ;
return 0 ;
V_80:
if ( V_4 -> V_25 & V_77 )
F_40 ( V_35 , - 1 ) ;
V_78:
if ( ! F_38 ( V_4 -> V_13 , V_35 -> V_13 ) )
F_44 ( V_35 , V_4 -> V_13 ) ;
V_76:
F_45 ( V_4 ) ;
return V_73 ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct V_18 * V_19 = V_18 ( V_4 ) ;
struct V_3 * V_35 = V_19 -> V_35 ;
F_47 ( V_35 , V_4 ) ;
F_48 ( V_35 , V_4 ) ;
if ( V_4 -> V_25 & V_77 )
F_40 ( V_35 , - 1 ) ;
if ( V_4 -> V_25 & V_79 )
F_41 ( V_35 , - 1 ) ;
if ( ! F_38 ( V_4 -> V_13 , V_35 -> V_13 ) )
F_44 ( V_35 , V_4 -> V_13 ) ;
F_45 ( V_4 ) ;
return 0 ;
}
static int F_49 ( struct V_3 * V_4 , void * V_82 )
{
struct V_3 * V_35 = V_18 ( V_4 ) -> V_35 ;
struct V_83 * V_84 = V_82 ;
int V_73 ;
if ( ! F_50 ( V_84 -> V_85 ) )
return - V_86 ;
if ( ! ( V_4 -> V_25 & V_74 ) )
goto V_76;
if ( ! F_38 ( V_84 -> V_85 , V_35 -> V_13 ) ) {
V_73 = F_39 ( V_35 , V_84 -> V_85 ) ;
if ( V_73 < 0 )
return V_73 ;
}
if ( ! F_38 ( V_4 -> V_13 , V_35 -> V_13 ) )
F_44 ( V_35 , V_4 -> V_13 ) ;
V_76:
memcpy ( V_4 -> V_13 , V_84 -> V_85 , V_14 ) ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 , struct V_87 * V_88 , int V_89 )
{
struct V_3 * V_35 = V_18 ( V_4 ) -> V_35 ;
const struct V_90 * V_91 = V_35 -> V_92 ;
struct V_87 V_93 ;
int V_73 = - V_94 ;
strncpy ( V_93 . V_95 , V_35 -> V_11 , V_96 ) ;
V_93 . V_97 = V_88 -> V_97 ;
switch ( V_89 ) {
case V_98 :
case V_99 :
case V_100 :
if ( F_52 ( V_35 ) && V_91 -> V_101 )
V_73 = V_91 -> V_101 ( V_35 , & V_93 , V_89 ) ;
break;
}
if ( ! V_73 )
V_88 -> V_97 = V_93 . V_97 ;
return V_73 ;
}
static int F_53 ( struct V_3 * V_4 , struct V_102 * V_103 )
{
struct V_3 * V_35 = V_18 ( V_4 ) -> V_35 ;
const struct V_90 * V_91 = V_35 -> V_92 ;
int V_73 = 0 ;
if ( F_52 ( V_35 ) && V_91 -> V_104 )
V_73 = V_91 -> V_104 ( V_35 , V_103 ) ;
return V_73 ;
}
static int F_54 ( struct V_3 * V_4 , T_1 V_105 ,
struct V_106 * V_107 , unsigned int V_108 )
{
struct V_3 * V_35 = V_18 ( V_4 ) -> V_35 ;
const struct V_90 * V_91 = V_35 -> V_92 ;
int V_24 = 0 ;
if ( V_91 -> V_109 )
V_24 = V_91 -> V_109 ( V_35 , V_105 , V_107 , V_108 ) ;
return V_24 ;
}
static int F_55 ( struct V_3 * V_4 , T_1 V_105 )
{
struct V_3 * V_35 = V_18 ( V_4 ) -> V_35 ;
const struct V_90 * V_91 = V_35 -> V_92 ;
int V_17 = 0 ;
if ( V_91 -> V_110 )
V_17 = V_91 -> V_110 ( V_35 , V_105 ) ;
return V_17 ;
}
static int F_56 ( struct V_3 * V_4 )
{
struct V_3 * V_35 = V_18 ( V_4 ) -> V_35 ;
const struct V_90 * V_91 = V_35 -> V_92 ;
int V_24 = - V_71 ;
if ( V_91 -> V_111 )
V_24 = V_91 -> V_111 ( V_35 ) ;
return V_24 ;
}
static int F_57 ( struct V_3 * V_4 )
{
struct V_3 * V_35 = V_18 ( V_4 ) -> V_35 ;
const struct V_90 * V_91 = V_35 -> V_92 ;
int V_24 = - V_71 ;
if ( V_91 -> V_112 )
V_24 = V_91 -> V_112 ( V_35 ) ;
return V_24 ;
}
static int F_58 ( struct V_3 * V_4 , T_4 * V_113 , int type )
{
struct V_3 * V_35 = V_18 ( V_4 ) -> V_35 ;
const struct V_90 * V_91 = V_35 -> V_92 ;
int V_24 = - V_71 ;
if ( V_91 -> V_114 )
V_24 = V_91 -> V_114 ( V_35 , V_113 , type ) ;
return V_24 ;
}
static int F_59 ( struct V_3 * V_4 , T_1 V_105 ,
struct V_106 * V_107 , unsigned int V_108 )
{
struct V_3 * V_35 = V_18 ( V_4 ) -> V_35 ;
const struct V_90 * V_91 = V_35 -> V_92 ;
int V_24 = 0 ;
if ( V_91 -> V_115 )
V_24 = V_91 -> V_115 ( V_35 , V_105 , V_107 , V_108 ) ;
return V_24 ;
}
static void F_60 ( struct V_3 * V_4 , int V_116 )
{
struct V_3 * V_35 = V_18 ( V_4 ) -> V_35 ;
if ( V_4 -> V_25 & V_74 ) {
if ( V_116 & V_77 )
F_40 ( V_35 , V_4 -> V_25 & V_77 ? 1 : - 1 ) ;
if ( V_116 & V_79 )
F_41 ( V_35 , V_4 -> V_25 & V_79 ? 1 : - 1 ) ;
}
}
static void F_61 ( struct V_3 * V_117 )
{
F_62 ( V_18 ( V_117 ) -> V_35 , V_117 ) ;
F_63 ( V_18 ( V_117 ) -> V_35 , V_117 ) ;
}
static void F_64 ( struct V_3 * V_4 ,
struct V_118 * V_119 ,
void * V_120 )
{
F_65 ( & V_119 -> V_121 ,
& V_122 ,
* ( int * ) V_120 ) ;
}
static void F_66 ( struct V_3 * V_4 , int V_123 )
{
F_65 ( & V_4 -> V_124 ,
& V_125 ,
V_123 ) ;
F_67 ( V_4 , F_64 , & V_123 ) ;
}
static int F_68 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_15 , const void * V_16 ,
unsigned int V_17 )
{
struct V_18 * V_19 = V_18 ( V_4 ) ;
struct V_3 * V_35 = V_19 -> V_35 ;
return F_10 ( V_2 , V_35 , type , V_15 , V_16 , V_17 ) ;
}
static int F_69 ( struct V_3 * V_4 )
{
struct V_3 * V_35 = V_18 ( V_4 ) -> V_35 ;
int V_123 = 0 , V_126 ;
F_45 ( V_4 ) ;
V_4 -> V_25 = V_35 -> V_25 & ~ ( V_74 | V_79 | V_77 |
V_127 | V_128 ) ;
V_4 -> V_129 = V_35 -> V_130 ;
V_4 -> V_131 = ( V_35 -> V_131 & ( ( 1 << V_132 ) |
( 1 << V_133 ) ) ) |
( 1 << V_134 ) ;
V_4 -> V_135 = V_136 | V_137 |
V_138 | V_139 |
V_140 | V_141 |
V_142 ;
V_4 -> V_143 |= V_35 -> V_144 | V_145 ;
V_4 -> V_146 = V_35 -> V_146 ;
V_4 -> V_147 = V_35 -> V_147 ;
if ( F_70 ( V_4 -> V_13 ) )
F_71 ( V_4 , V_35 ) ;
if ( F_70 ( V_4 -> V_148 ) )
memcpy ( V_4 -> V_148 , V_35 -> V_148 , V_4 -> V_149 ) ;
#if F_72 ( V_150 )
V_4 -> V_151 = V_35 -> V_151 ;
#endif
V_4 -> V_152 = V_35 -> V_152 ;
if ( V_35 -> V_143 & V_153 ) {
V_4 -> V_154 = & V_155 ;
V_4 -> V_156 = V_35 -> V_156 ;
} else {
V_4 -> V_154 = & V_157 ;
V_4 -> V_156 = V_35 -> V_156 + V_27 ;
}
V_4 -> V_92 = & V_158 ;
F_73 ( V_4 , & V_159 ) ;
if ( F_74 ( V_35 ) )
V_123 = 1 ;
F_66 ( V_4 , V_123 ) ;
V_18 ( V_4 ) -> V_42 = F_75 ( struct V_42 ) ;
if ( ! V_18 ( V_4 ) -> V_42 )
return - V_160 ;
F_76 (i) {
struct V_42 * V_161 ;
V_161 = F_77 ( V_18 ( V_4 ) -> V_42 , V_126 ) ;
F_78 ( & V_161 -> V_44 ) ;
}
return 0 ;
}
static void F_79 ( struct V_3 * V_4 )
{
struct V_55 * V_162 ;
struct V_18 * V_19 = V_18 ( V_4 ) ;
int V_126 ;
F_80 ( V_19 -> V_42 ) ;
V_19 -> V_42 = NULL ;
for ( V_126 = 0 ; V_126 < F_81 ( V_19 -> V_61 ) ; V_126 ++ ) {
while ( ( V_162 = V_19 -> V_61 [ V_126 ] ) != NULL ) {
V_19 -> V_61 [ V_126 ] = V_162 -> V_63 ;
F_82 ( V_162 ) ;
}
}
}
static T_5 F_83 ( struct V_3 * V_4 ,
T_5 V_143 )
{
struct V_3 * V_35 = V_18 ( V_4 ) -> V_35 ;
T_5 V_163 = V_143 ;
V_143 &= V_35 -> V_144 ;
V_143 |= V_164 ;
V_143 &= V_35 -> V_143 ;
V_143 |= V_163 & V_165 ;
V_143 |= V_145 ;
return V_143 ;
}
static int F_84 ( struct V_3 * V_4 ,
struct V_166 * V_89 )
{
const struct V_18 * V_19 = V_18 ( V_4 ) ;
return F_85 ( V_19 -> V_35 , V_89 ) ;
}
static void F_86 ( struct V_3 * V_4 ,
struct V_167 * V_168 )
{
F_87 ( V_168 -> V_169 , V_170 , sizeof( V_168 -> V_169 ) ) ;
F_87 ( V_168 -> V_171 , V_172 , sizeof( V_168 -> V_171 ) ) ;
F_87 ( V_168 -> V_173 , L_2 , sizeof( V_168 -> V_173 ) ) ;
}
static struct V_174 * F_88 ( struct V_3 * V_4 , struct V_174 * V_43 )
{
if ( V_18 ( V_4 ) -> V_42 ) {
struct V_42 * V_82 ;
T_3 V_175 = 0 , V_47 = 0 ;
int V_126 ;
F_76 (i) {
T_4 V_176 , V_177 , V_178 , V_179 , V_180 ;
unsigned int V_181 ;
V_82 = F_77 ( V_18 ( V_4 ) -> V_42 , V_126 ) ;
do {
V_181 = F_89 ( & V_82 -> V_44 ) ;
V_176 = V_82 -> V_182 ;
V_177 = V_82 -> V_183 ;
V_178 = V_82 -> V_184 ;
V_179 = V_82 -> V_45 ;
V_180 = V_82 -> V_46 ;
} while ( F_90 ( & V_82 -> V_44 , V_181 ) );
V_43 -> V_182 += V_176 ;
V_43 -> V_183 += V_177 ;
V_43 -> V_185 += V_178 ;
V_43 -> V_45 += V_179 ;
V_43 -> V_46 += V_180 ;
V_175 += V_82 -> V_175 ;
V_47 += V_82 -> V_47 ;
}
V_43 -> V_175 = V_175 ;
V_43 -> V_47 = V_47 ;
}
return V_43 ;
}
static void F_91 ( struct V_3 * V_4 )
{
return;
}
static int F_92 ( struct V_3 * V_4 , struct V_186 * V_187 ,
T_6 V_188 )
{
struct V_18 * V_19 = V_18 ( V_4 ) ;
struct V_3 * V_35 = V_19 -> V_35 ;
struct V_36 * V_36 ;
int V_73 = 0 ;
V_36 = F_93 ( sizeof( * V_36 ) , V_188 ) ;
V_73 = - V_160 ;
if ( ! V_36 )
goto V_76;
V_73 = F_94 ( V_36 , V_35 , V_188 ) ;
if ( V_73 ) {
F_82 ( V_36 ) ;
goto V_76;
}
V_19 -> V_36 = V_36 ;
V_76:
return V_73 ;
}
static void F_95 ( struct V_3 * V_4 )
{
struct V_18 * V_19 = V_18 ( V_4 ) ;
struct V_36 * V_36 = V_19 -> V_36 ;
if ( ! V_36 )
return;
V_19 -> V_36 = NULL ;
F_96 ( V_36 ) ;
}
void F_97 ( struct V_3 * V_4 )
{
F_98 ( V_4 ) ;
V_4 -> V_189 |= V_190 ;
V_4 -> V_189 &= ~ ( V_191 | V_192 ) ;
V_4 -> V_193 = 0 ;
V_4 -> V_92 = & V_158 ;
V_4 -> V_194 = V_195 ;
V_4 -> V_196 = & V_197 ;
memset ( V_4 -> V_148 , 0 , V_14 ) ;
}
