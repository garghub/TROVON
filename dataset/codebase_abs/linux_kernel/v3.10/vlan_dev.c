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
static inline T_1
F_7 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_15 * V_16 ;
V_16 = F_8 ( V_4 ) -> V_17 [ ( V_2 -> V_18 & 0xF ) ] ;
while ( V_16 ) {
if ( V_16 -> V_18 == V_2 -> V_18 ) {
return V_16 -> V_19 ;
}
V_16 = V_16 -> V_20 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_21 , const void * V_22 ,
unsigned int V_23 )
{
struct F_8 * V_24 = F_8 ( V_4 ) ;
struct V_25 * V_26 ;
unsigned int V_27 = 0 ;
T_1 V_28 = 0 ;
int V_29 ;
if ( ! ( F_8 ( V_4 ) -> V_30 & V_31 ) ) {
V_26 = (struct V_25 * ) F_10 ( V_2 , V_32 ) ;
V_28 = F_8 ( V_4 ) -> V_33 ;
V_28 |= F_7 ( V_4 , V_2 ) ;
V_26 -> V_34 = F_3 ( V_28 ) ;
if ( type != V_35 && type != V_36 )
V_26 -> V_8 = F_3 ( type ) ;
else
V_26 -> V_8 = F_3 ( V_23 ) ;
V_2 -> V_37 = V_24 -> V_38 ;
type = F_6 ( V_24 -> V_38 ) ;
V_27 = V_32 ;
}
if ( V_22 == NULL )
V_22 = V_4 -> V_13 ;
V_4 = F_8 ( V_4 ) -> V_39 ;
V_29 = F_11 ( V_2 , V_4 , type , V_21 , V_22 , V_23 + V_27 ) ;
if ( V_29 > 0 )
V_29 += V_27 ;
return V_29 ;
}
static inline T_2 F_12 ( struct F_8 * V_24 , struct V_1 * V_2 )
{
#ifdef F_13
if ( V_24 -> V_40 )
F_14 ( V_24 -> V_40 , V_2 ) ;
#else
F_15 () ;
#endif
return V_41 ;
}
static T_2 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct F_8 * V_24 = F_8 ( V_4 ) ;
struct V_5 * V_6 = (struct V_5 * ) ( V_2 -> V_7 ) ;
unsigned int V_23 ;
int V_42 ;
if ( V_6 -> V_43 != V_24 -> V_38 ||
V_24 -> V_30 & V_31 ) {
T_1 V_28 ;
V_28 = V_24 -> V_33 ;
V_28 |= F_7 ( V_4 , V_2 ) ;
V_2 = F_17 ( V_2 , V_24 -> V_38 , V_28 ) ;
}
V_2 -> V_4 = V_24 -> V_39 ;
V_23 = V_2 -> V_23 ;
if ( F_18 ( F_19 ( V_4 ) ) )
return F_12 ( V_24 , V_2 ) ;
V_42 = F_20 ( V_2 ) ;
if ( F_21 ( V_42 == V_44 || V_42 == V_45 ) ) {
struct V_46 * V_47 ;
V_47 = F_22 ( V_24 -> V_46 ) ;
F_23 ( & V_47 -> V_48 ) ;
V_47 -> V_49 ++ ;
V_47 -> V_50 += V_23 ;
F_24 ( & V_47 -> V_48 ) ;
} else {
F_25 ( V_24 -> V_46 -> V_51 ) ;
}
return V_42 ;
}
static int F_26 ( struct V_3 * V_4 , int V_52 )
{
if ( F_8 ( V_4 ) -> V_39 -> V_53 < V_52 )
return - V_54 ;
V_4 -> V_53 = V_52 ;
return 0 ;
}
void F_27 ( const struct V_3 * V_4 ,
T_3 V_55 , T_1 V_56 )
{
struct F_8 * V_24 = F_8 ( V_4 ) ;
if ( V_24 -> V_57 [ V_56 & 0x7 ] && ! V_55 )
V_24 -> V_58 -- ;
else if ( ! V_24 -> V_57 [ V_56 & 0x7 ] && V_55 )
V_24 -> V_58 ++ ;
V_24 -> V_57 [ V_56 & 0x7 ] = V_55 ;
}
int F_28 ( const struct V_3 * V_4 ,
T_3 V_55 , T_1 V_56 )
{
struct F_8 * V_24 = F_8 ( V_4 ) ;
struct V_15 * V_16 = NULL ;
struct V_15 * V_59 ;
T_3 V_19 = ( V_56 << V_60 ) & V_61 ;
V_16 = V_24 -> V_17 [ V_55 & 0xF ] ;
while ( V_16 ) {
if ( V_16 -> V_18 == V_55 ) {
if ( V_16 -> V_19 && ! V_19 )
V_24 -> V_62 -- ;
else if ( ! V_16 -> V_19 && V_19 )
V_24 -> V_62 ++ ;
V_16 -> V_19 = V_19 ;
return 0 ;
}
V_16 = V_16 -> V_20 ;
}
V_16 = V_24 -> V_17 [ V_55 & 0xF ] ;
V_59 = F_29 ( sizeof( struct V_15 ) , V_63 ) ;
if ( ! V_59 )
return - V_64 ;
V_59 -> V_20 = V_16 ;
V_59 -> V_18 = V_55 ;
V_59 -> V_19 = V_19 ;
V_24 -> V_17 [ V_55 & 0xF ] = V_59 ;
if ( V_19 )
V_24 -> V_62 ++ ;
return 0 ;
}
int F_30 ( const struct V_3 * V_4 , T_3 V_30 , T_3 V_65 )
{
struct F_8 * V_24 = F_8 ( V_4 ) ;
T_3 V_66 = V_24 -> V_30 ;
if ( V_65 & ~ ( V_31 | V_67 |
V_68 | V_69 ) )
return - V_70 ;
V_24 -> V_30 = ( V_66 & ~ V_65 ) | ( V_30 & V_65 ) ;
if ( F_31 ( V_4 ) && ( V_24 -> V_30 ^ V_66 ) & V_67 ) {
if ( V_24 -> V_30 & V_67 )
F_32 ( V_4 ) ;
else
F_33 ( V_4 ) ;
}
if ( F_31 ( V_4 ) && ( V_24 -> V_30 ^ V_66 ) & V_69 ) {
if ( V_24 -> V_30 & V_69 )
F_34 ( V_4 ) ;
else
F_35 ( V_4 ) ;
}
return 0 ;
}
void F_36 ( const struct V_3 * V_4 , char * V_71 )
{
strncpy ( V_71 , F_8 ( V_4 ) -> V_39 -> V_11 , 23 ) ;
}
static int F_37 ( struct V_3 * V_4 )
{
struct F_8 * V_24 = F_8 ( V_4 ) ;
struct V_3 * V_39 = V_24 -> V_39 ;
int V_72 ;
if ( ! ( V_39 -> V_30 & V_73 ) &&
! ( V_24 -> V_30 & V_68 ) )
return - V_74 ;
if ( ! F_38 ( V_4 -> V_13 , V_39 -> V_13 ) ) {
V_72 = F_39 ( V_39 , V_4 -> V_13 ) ;
if ( V_72 < 0 )
goto V_75;
}
if ( V_4 -> V_30 & V_76 ) {
V_72 = F_40 ( V_39 , 1 ) ;
if ( V_72 < 0 )
goto V_77;
}
if ( V_4 -> V_30 & V_78 ) {
V_72 = F_41 ( V_39 , 1 ) ;
if ( V_72 < 0 )
goto V_79;
}
memcpy ( V_24 -> V_80 , V_39 -> V_13 , V_14 ) ;
if ( V_24 -> V_30 & V_67 )
F_32 ( V_4 ) ;
if ( V_24 -> V_30 & V_69 )
F_34 ( V_4 ) ;
if ( F_42 ( V_39 ) )
F_43 ( V_4 ) ;
return 0 ;
V_79:
if ( V_4 -> V_30 & V_76 )
F_40 ( V_39 , - 1 ) ;
V_77:
if ( ! F_38 ( V_4 -> V_13 , V_39 -> V_13 ) )
F_44 ( V_39 , V_4 -> V_13 ) ;
V_75:
F_45 ( V_4 ) ;
return V_72 ;
}
static int F_46 ( struct V_3 * V_4 )
{
struct F_8 * V_24 = F_8 ( V_4 ) ;
struct V_3 * V_39 = V_24 -> V_39 ;
F_47 ( V_39 , V_4 ) ;
F_48 ( V_39 , V_4 ) ;
if ( V_4 -> V_30 & V_76 )
F_40 ( V_39 , - 1 ) ;
if ( V_4 -> V_30 & V_78 )
F_41 ( V_39 , - 1 ) ;
if ( ! F_38 ( V_4 -> V_13 , V_39 -> V_13 ) )
F_44 ( V_39 , V_4 -> V_13 ) ;
F_45 ( V_4 ) ;
return 0 ;
}
static int F_49 ( struct V_3 * V_4 , void * V_81 )
{
struct V_3 * V_39 = F_8 ( V_4 ) -> V_39 ;
struct V_82 * V_83 = V_81 ;
int V_72 ;
if ( ! F_50 ( V_83 -> V_84 ) )
return - V_85 ;
if ( ! ( V_4 -> V_30 & V_73 ) )
goto V_75;
if ( ! F_38 ( V_83 -> V_84 , V_39 -> V_13 ) ) {
V_72 = F_39 ( V_39 , V_83 -> V_84 ) ;
if ( V_72 < 0 )
return V_72 ;
}
if ( ! F_38 ( V_4 -> V_13 , V_39 -> V_13 ) )
F_44 ( V_39 , V_4 -> V_13 ) ;
V_75:
memcpy ( V_4 -> V_13 , V_83 -> V_84 , V_14 ) ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 , struct V_86 * V_87 , int V_88 )
{
struct V_3 * V_39 = F_8 ( V_4 ) -> V_39 ;
const struct V_89 * V_90 = V_39 -> V_91 ;
struct V_86 V_92 ;
int V_72 = - V_93 ;
strncpy ( V_92 . V_94 , V_39 -> V_11 , V_95 ) ;
V_92 . V_96 = V_87 -> V_96 ;
switch ( V_88 ) {
case V_97 :
case V_98 :
case V_99 :
if ( F_52 ( V_39 ) && V_90 -> V_100 )
V_72 = V_90 -> V_100 ( V_39 , & V_92 , V_88 ) ;
break;
}
if ( ! V_72 )
V_87 -> V_96 = V_92 . V_96 ;
return V_72 ;
}
static int F_53 ( struct V_3 * V_4 , struct V_101 * V_102 )
{
struct V_3 * V_39 = F_8 ( V_4 ) -> V_39 ;
const struct V_89 * V_90 = V_39 -> V_91 ;
int V_72 = 0 ;
if ( F_52 ( V_39 ) && V_90 -> V_103 )
V_72 = V_90 -> V_103 ( V_39 , V_102 ) ;
return V_72 ;
}
static int F_54 ( struct V_3 * V_4 , T_1 V_104 ,
struct V_105 * V_106 , unsigned int V_107 )
{
struct V_3 * V_39 = F_8 ( V_4 ) -> V_39 ;
const struct V_89 * V_90 = V_39 -> V_91 ;
int V_29 = 0 ;
if ( V_90 -> V_108 )
V_29 = V_90 -> V_108 ( V_39 , V_104 , V_106 , V_107 ) ;
return V_29 ;
}
static int F_55 ( struct V_3 * V_4 , T_1 V_104 )
{
struct V_3 * V_39 = F_8 ( V_4 ) -> V_39 ;
const struct V_89 * V_90 = V_39 -> V_91 ;
int V_23 = 0 ;
if ( V_90 -> V_109 )
V_23 = V_90 -> V_109 ( V_39 , V_104 ) ;
return V_23 ;
}
static int F_56 ( struct V_3 * V_4 )
{
struct V_3 * V_39 = F_8 ( V_4 ) -> V_39 ;
const struct V_89 * V_90 = V_39 -> V_91 ;
int V_29 = - V_70 ;
if ( V_90 -> V_110 )
V_29 = V_90 -> V_110 ( V_39 ) ;
return V_29 ;
}
static int F_57 ( struct V_3 * V_4 )
{
struct V_3 * V_39 = F_8 ( V_4 ) -> V_39 ;
const struct V_89 * V_90 = V_39 -> V_91 ;
int V_29 = - V_70 ;
if ( V_90 -> V_111 )
V_29 = V_90 -> V_111 ( V_39 ) ;
return V_29 ;
}
static int F_58 ( struct V_3 * V_4 , T_4 * V_112 , int type )
{
struct V_3 * V_39 = F_8 ( V_4 ) -> V_39 ;
const struct V_89 * V_90 = V_39 -> V_91 ;
int V_29 = - V_70 ;
if ( V_90 -> V_113 )
V_29 = V_90 -> V_113 ( V_39 , V_112 , type ) ;
return V_29 ;
}
static int F_59 ( struct V_3 * V_4 , T_1 V_104 ,
struct V_105 * V_106 , unsigned int V_107 )
{
struct V_3 * V_39 = F_8 ( V_4 ) -> V_39 ;
const struct V_89 * V_90 = V_39 -> V_91 ;
int V_29 = 0 ;
if ( V_90 -> V_114 )
V_29 = V_90 -> V_114 ( V_39 , V_104 , V_106 , V_107 ) ;
return V_29 ;
}
static void F_60 ( struct V_3 * V_4 , int V_115 )
{
struct V_3 * V_39 = F_8 ( V_4 ) -> V_39 ;
if ( V_4 -> V_30 & V_73 ) {
if ( V_115 & V_76 )
F_40 ( V_39 , V_4 -> V_30 & V_76 ? 1 : - 1 ) ;
if ( V_115 & V_78 )
F_41 ( V_39 , V_4 -> V_30 & V_78 ? 1 : - 1 ) ;
}
}
static void F_61 ( struct V_3 * V_116 )
{
F_62 ( F_8 ( V_116 ) -> V_39 , V_116 ) ;
F_63 ( F_8 ( V_116 ) -> V_39 , V_116 ) ;
}
static void F_64 ( struct V_3 * V_4 ,
struct V_117 * V_118 ,
void * V_119 )
{
F_65 ( & V_118 -> V_120 ,
& V_121 ,
* ( int * ) V_119 ) ;
}
static void F_66 ( struct V_3 * V_4 , int V_122 )
{
F_65 ( & V_4 -> V_123 ,
& V_124 ,
V_122 ) ;
F_67 ( V_4 , F_64 , & V_122 ) ;
}
static int F_68 ( struct V_3 * V_4 )
{
struct V_3 * V_39 = F_8 ( V_4 ) -> V_39 ;
int V_122 = 0 ;
F_45 ( V_4 ) ;
V_4 -> V_30 = V_39 -> V_30 & ~ ( V_73 | V_78 | V_76 |
V_125 | V_126 ) ;
V_4 -> V_127 = V_39 -> V_128 ;
V_4 -> V_129 = ( V_39 -> V_129 & ( ( 1 << V_130 ) |
( 1 << V_131 ) ) ) |
( 1 << V_132 ) ;
V_4 -> V_133 = V_134 | V_135 |
V_136 | V_137 |
V_138 | V_139 |
V_140 ;
V_4 -> V_141 |= V_39 -> V_142 | V_143 ;
V_4 -> V_144 = V_39 -> V_144 ;
V_4 -> V_145 = V_39 -> V_145 ;
if ( F_69 ( V_4 -> V_13 ) )
memcpy ( V_4 -> V_13 , V_39 -> V_13 , V_4 -> V_146 ) ;
if ( F_69 ( V_4 -> V_147 ) )
memcpy ( V_4 -> V_147 , V_39 -> V_147 , V_4 -> V_146 ) ;
#if F_70 ( V_148 )
V_4 -> V_149 = V_39 -> V_149 ;
#endif
V_4 -> V_150 = V_39 -> V_150 ;
if ( V_39 -> V_141 & V_151 ) {
V_4 -> V_152 = V_39 -> V_152 ;
V_4 -> V_153 = V_39 -> V_153 ;
} else {
V_4 -> V_152 = & V_154 ;
V_4 -> V_153 = V_39 -> V_153 + V_32 ;
}
V_4 -> V_91 = & V_155 ;
F_71 ( V_4 , & V_156 ) ;
if ( F_72 ( V_39 ) )
V_122 = 1 ;
F_66 ( V_4 , V_122 ) ;
F_8 ( V_4 ) -> V_46 = F_73 ( struct V_46 ) ;
if ( ! F_8 ( V_4 ) -> V_46 )
return - V_157 ;
return 0 ;
}
static void F_74 ( struct V_3 * V_4 )
{
struct V_15 * V_158 ;
struct F_8 * V_24 = F_8 ( V_4 ) ;
int V_159 ;
F_75 ( V_24 -> V_46 ) ;
V_24 -> V_46 = NULL ;
for ( V_159 = 0 ; V_159 < F_76 ( V_24 -> V_17 ) ; V_159 ++ ) {
while ( ( V_158 = V_24 -> V_17 [ V_159 ] ) != NULL ) {
V_24 -> V_17 [ V_159 ] = V_158 -> V_20 ;
F_77 ( V_158 ) ;
}
}
}
static T_5 F_78 ( struct V_3 * V_4 ,
T_5 V_141 )
{
struct V_3 * V_39 = F_8 ( V_4 ) -> V_39 ;
T_5 V_160 = V_141 ;
V_141 &= V_39 -> V_142 ;
V_141 |= V_161 ;
V_141 &= V_39 -> V_141 ;
V_141 |= V_160 & V_162 ;
V_141 |= V_143 ;
return V_141 ;
}
static int F_79 ( struct V_3 * V_4 ,
struct V_163 * V_88 )
{
const struct F_8 * V_24 = F_8 ( V_4 ) ;
return F_80 ( V_24 -> V_39 , V_88 ) ;
}
static void F_81 ( struct V_3 * V_4 ,
struct V_164 * V_165 )
{
F_82 ( V_165 -> V_166 , V_167 , sizeof( V_165 -> V_166 ) ) ;
F_82 ( V_165 -> V_168 , V_169 , sizeof( V_165 -> V_168 ) ) ;
F_82 ( V_165 -> V_170 , L_2 , sizeof( V_165 -> V_170 ) ) ;
}
static struct V_171 * F_83 ( struct V_3 * V_4 , struct V_171 * V_47 )
{
if ( F_8 ( V_4 ) -> V_46 ) {
struct V_46 * V_81 ;
T_3 V_172 = 0 , V_51 = 0 ;
int V_159 ;
F_84 (i) {
T_4 V_173 , V_174 , V_175 , V_176 , V_177 ;
unsigned int V_178 ;
V_81 = F_85 ( F_8 ( V_4 ) -> V_46 , V_159 ) ;
do {
V_178 = F_86 ( & V_81 -> V_48 ) ;
V_173 = V_81 -> V_179 ;
V_174 = V_81 -> V_180 ;
V_175 = V_81 -> V_181 ;
V_176 = V_81 -> V_49 ;
V_177 = V_81 -> V_50 ;
} while ( F_87 ( & V_81 -> V_48 , V_178 ) );
V_47 -> V_179 += V_173 ;
V_47 -> V_180 += V_174 ;
V_47 -> V_182 += V_175 ;
V_47 -> V_49 += V_176 ;
V_47 -> V_50 += V_177 ;
V_172 += V_81 -> V_172 ;
V_51 += V_81 -> V_51 ;
}
V_47 -> V_172 = V_172 ;
V_47 -> V_51 = V_51 ;
}
return V_47 ;
}
static void F_88 ( struct V_3 * V_4 )
{
return;
}
static int F_89 ( struct V_3 * V_4 , struct V_183 * V_184 ,
T_6 V_185 )
{
struct F_8 * V_24 = F_8 ( V_4 ) ;
struct V_3 * V_39 = V_24 -> V_39 ;
struct V_40 * V_40 ;
int V_72 = 0 ;
V_40 = F_90 ( sizeof( * V_40 ) , V_185 ) ;
V_72 = - V_157 ;
if ( ! V_40 )
goto V_75;
V_72 = F_91 ( V_40 , V_39 , V_185 ) ;
if ( V_72 ) {
F_77 ( V_40 ) ;
goto V_75;
}
V_24 -> V_40 = V_40 ;
V_75:
return V_72 ;
}
static void F_92 ( struct V_3 * V_4 )
{
struct F_8 * V_24 = F_8 ( V_4 ) ;
struct V_40 * V_40 = V_24 -> V_40 ;
if ( ! V_40 )
return;
V_24 -> V_40 = NULL ;
F_93 ( V_40 ) ;
}
void F_94 ( struct V_3 * V_4 )
{
F_95 ( V_4 ) ;
V_4 -> V_186 |= V_187 ;
V_4 -> V_186 &= ~ ( V_188 | V_189 ) ;
V_4 -> V_190 = 0 ;
V_4 -> V_91 = & V_155 ;
V_4 -> V_191 = V_192 ;
V_4 -> V_193 = & V_194 ;
memset ( V_4 -> V_147 , 0 , V_14 ) ;
}
