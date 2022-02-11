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
F_7 ( V_6 -> V_12 , V_4 -> V_13 ) ;
break;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_14 , const void * V_15 ,
unsigned int V_16 )
{
struct V_17 * V_18 = V_17 ( V_4 ) ;
struct V_19 * V_20 ;
unsigned int V_21 = 0 ;
T_1 V_22 = 0 ;
int V_23 ;
if ( ! ( V_18 -> V_24 & V_25 ) ) {
V_20 = (struct V_19 * ) F_9 ( V_2 , V_26 ) ;
V_22 = V_18 -> V_27 ;
V_22 |= F_10 ( V_4 , V_2 -> V_28 ) ;
V_20 -> V_29 = F_3 ( V_22 ) ;
if ( type != V_30 && type != V_31 )
V_20 -> V_8 = F_3 ( type ) ;
else
V_20 -> V_8 = F_3 ( V_16 ) ;
V_2 -> V_32 = V_18 -> V_33 ;
type = F_6 ( V_18 -> V_33 ) ;
V_21 = V_26 ;
}
if ( V_15 == NULL )
V_15 = V_4 -> V_13 ;
V_4 = V_18 -> V_34 ;
V_23 = F_11 ( V_2 , V_4 , type , V_14 , V_15 , V_16 + V_21 ) ;
if ( V_23 > 0 )
V_23 += V_21 ;
return V_23 ;
}
static inline T_2 F_12 ( struct V_17 * V_18 , struct V_1 * V_2 )
{
#ifdef F_13
if ( V_18 -> V_35 )
F_14 ( V_18 -> V_35 , V_2 ) ;
#else
F_15 () ;
#endif
return V_36 ;
}
static T_2 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_17 * V_18 = V_17 ( V_4 ) ;
struct V_5 * V_6 = (struct V_5 * ) ( V_2 -> V_7 ) ;
unsigned int V_16 ;
int V_37 ;
if ( V_6 -> V_38 != V_18 -> V_33 ||
V_18 -> V_24 & V_25 ) {
T_1 V_22 ;
V_22 = V_18 -> V_27 ;
V_22 |= F_10 ( V_4 , V_2 -> V_28 ) ;
V_2 = F_17 ( V_2 , V_18 -> V_33 , V_22 ) ;
}
V_2 -> V_4 = V_18 -> V_34 ;
V_16 = V_2 -> V_16 ;
if ( F_18 ( F_19 ( V_4 ) ) )
return F_12 ( V_18 , V_2 ) ;
V_37 = F_20 ( V_2 ) ;
if ( F_21 ( V_37 == V_39 || V_37 == V_40 ) ) {
struct V_41 * V_42 ;
V_42 = F_22 ( V_18 -> V_41 ) ;
F_23 ( & V_42 -> V_43 ) ;
V_42 -> V_44 ++ ;
V_42 -> V_45 += V_16 ;
F_24 ( & V_42 -> V_43 ) ;
} else {
F_25 ( V_18 -> V_41 -> V_46 ) ;
}
return V_37 ;
}
static int F_26 ( struct V_3 * V_4 , int V_47 )
{
if ( V_17 ( V_4 ) -> V_34 -> V_48 < V_47 )
return - V_49 ;
V_4 -> V_48 = V_47 ;
return 0 ;
}
void F_27 ( const struct V_3 * V_4 ,
T_3 V_50 , T_1 V_51 )
{
struct V_17 * V_18 = V_17 ( V_4 ) ;
if ( V_18 -> V_52 [ V_51 & 0x7 ] && ! V_50 )
V_18 -> V_53 -- ;
else if ( ! V_18 -> V_52 [ V_51 & 0x7 ] && V_50 )
V_18 -> V_53 ++ ;
V_18 -> V_52 [ V_51 & 0x7 ] = V_50 ;
}
int F_28 ( const struct V_3 * V_4 ,
T_3 V_50 , T_1 V_51 )
{
struct V_17 * V_18 = V_17 ( V_4 ) ;
struct V_54 * V_55 = NULL ;
struct V_54 * V_56 ;
T_3 V_57 = ( V_51 << V_58 ) & V_59 ;
V_55 = V_18 -> V_60 [ V_50 & 0xF ] ;
while ( V_55 ) {
if ( V_55 -> V_28 == V_50 ) {
if ( V_55 -> V_57 && ! V_57 )
V_18 -> V_61 -- ;
else if ( ! V_55 -> V_57 && V_57 )
V_18 -> V_61 ++ ;
V_55 -> V_57 = V_57 ;
return 0 ;
}
V_55 = V_55 -> V_62 ;
}
V_55 = V_18 -> V_60 [ V_50 & 0xF ] ;
V_56 = F_29 ( sizeof( struct V_54 ) , V_63 ) ;
if ( ! V_56 )
return - V_64 ;
V_56 -> V_62 = V_55 ;
V_56 -> V_28 = V_50 ;
V_56 -> V_57 = V_57 ;
F_30 () ;
V_18 -> V_60 [ V_50 & 0xF ] = V_56 ;
if ( V_57 )
V_18 -> V_61 ++ ;
return 0 ;
}
int F_31 ( const struct V_3 * V_4 , T_3 V_24 , T_3 V_65 )
{
struct V_17 * V_18 = V_17 ( V_4 ) ;
T_3 V_66 = V_18 -> V_24 ;
if ( V_65 & ~ ( V_25 | V_67 |
V_68 | V_69 ) )
return - V_70 ;
V_18 -> V_24 = ( V_66 & ~ V_65 ) | ( V_24 & V_65 ) ;
if ( F_32 ( V_4 ) && ( V_18 -> V_24 ^ V_66 ) & V_67 ) {
if ( V_18 -> V_24 & V_67 )
F_33 ( V_4 ) ;
else
F_34 ( V_4 ) ;
}
if ( F_32 ( V_4 ) && ( V_18 -> V_24 ^ V_66 ) & V_69 ) {
if ( V_18 -> V_24 & V_69 )
F_35 ( V_4 ) ;
else
F_36 ( V_4 ) ;
}
return 0 ;
}
void F_37 ( const struct V_3 * V_4 , char * V_71 )
{
strncpy ( V_71 , V_17 ( V_4 ) -> V_34 -> V_11 , 23 ) ;
}
static int F_38 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = V_17 ( V_4 ) ;
struct V_3 * V_34 = V_18 -> V_34 ;
int V_72 ;
if ( ! ( V_34 -> V_24 & V_73 ) &&
! ( V_18 -> V_24 & V_68 ) )
return - V_74 ;
if ( ! F_39 ( V_4 -> V_13 , V_34 -> V_13 ) ) {
V_72 = F_40 ( V_34 , V_4 -> V_13 ) ;
if ( V_72 < 0 )
goto V_75;
}
if ( V_4 -> V_24 & V_76 ) {
V_72 = F_41 ( V_34 , 1 ) ;
if ( V_72 < 0 )
goto V_77;
}
if ( V_4 -> V_24 & V_78 ) {
V_72 = F_42 ( V_34 , 1 ) ;
if ( V_72 < 0 )
goto V_79;
}
F_7 ( V_18 -> V_80 , V_34 -> V_13 ) ;
if ( V_18 -> V_24 & V_67 )
F_33 ( V_4 ) ;
if ( V_18 -> V_24 & V_69 )
F_35 ( V_4 ) ;
if ( F_43 ( V_34 ) )
F_44 ( V_4 ) ;
return 0 ;
V_79:
if ( V_4 -> V_24 & V_76 )
F_41 ( V_34 , - 1 ) ;
V_77:
if ( ! F_39 ( V_4 -> V_13 , V_34 -> V_13 ) )
F_45 ( V_34 , V_4 -> V_13 ) ;
V_75:
F_46 ( V_4 ) ;
return V_72 ;
}
static int F_47 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = V_17 ( V_4 ) ;
struct V_3 * V_34 = V_18 -> V_34 ;
F_48 ( V_34 , V_4 ) ;
F_49 ( V_34 , V_4 ) ;
if ( V_4 -> V_24 & V_76 )
F_41 ( V_34 , - 1 ) ;
if ( V_4 -> V_24 & V_78 )
F_42 ( V_34 , - 1 ) ;
if ( ! F_39 ( V_4 -> V_13 , V_34 -> V_13 ) )
F_45 ( V_34 , V_4 -> V_13 ) ;
F_46 ( V_4 ) ;
return 0 ;
}
static int F_50 ( struct V_3 * V_4 , void * V_81 )
{
struct V_3 * V_34 = V_17 ( V_4 ) -> V_34 ;
struct V_82 * V_83 = V_81 ;
int V_72 ;
if ( ! F_51 ( V_83 -> V_84 ) )
return - V_85 ;
if ( ! ( V_4 -> V_24 & V_73 ) )
goto V_75;
if ( ! F_39 ( V_83 -> V_84 , V_34 -> V_13 ) ) {
V_72 = F_40 ( V_34 , V_83 -> V_84 ) ;
if ( V_72 < 0 )
return V_72 ;
}
if ( ! F_39 ( V_4 -> V_13 , V_34 -> V_13 ) )
F_45 ( V_34 , V_4 -> V_13 ) ;
V_75:
F_7 ( V_4 -> V_13 , V_83 -> V_84 ) ;
return 0 ;
}
static int F_52 ( struct V_3 * V_4 , struct V_86 * V_87 , int V_88 )
{
struct V_3 * V_34 = V_17 ( V_4 ) -> V_34 ;
const struct V_89 * V_90 = V_34 -> V_91 ;
struct V_86 V_92 ;
int V_72 = - V_93 ;
strncpy ( V_92 . V_94 , V_34 -> V_11 , V_95 ) ;
V_92 . V_96 = V_87 -> V_96 ;
switch ( V_88 ) {
case V_97 :
case V_98 :
case V_99 :
if ( F_53 ( V_34 ) && V_90 -> V_100 )
V_72 = V_90 -> V_100 ( V_34 , & V_92 , V_88 ) ;
break;
}
if ( ! V_72 )
V_87 -> V_96 = V_92 . V_96 ;
return V_72 ;
}
static int F_54 ( struct V_3 * V_4 , struct V_101 * V_102 )
{
struct V_3 * V_34 = V_17 ( V_4 ) -> V_34 ;
const struct V_89 * V_90 = V_34 -> V_91 ;
int V_72 = 0 ;
if ( F_53 ( V_34 ) && V_90 -> V_103 )
V_72 = V_90 -> V_103 ( V_34 , V_102 ) ;
return V_72 ;
}
static int F_55 ( struct V_3 * V_4 , T_1 V_104 ,
struct V_105 * V_106 , unsigned int V_107 )
{
struct V_3 * V_34 = V_17 ( V_4 ) -> V_34 ;
const struct V_89 * V_90 = V_34 -> V_91 ;
int V_23 = 0 ;
if ( V_90 -> V_108 )
V_23 = V_90 -> V_108 ( V_34 , V_104 , V_106 , V_107 ) ;
return V_23 ;
}
static int F_56 ( struct V_3 * V_4 , T_1 V_104 )
{
struct V_3 * V_34 = V_17 ( V_4 ) -> V_34 ;
const struct V_89 * V_90 = V_34 -> V_91 ;
int V_16 = 0 ;
if ( V_90 -> V_109 )
V_16 = V_90 -> V_109 ( V_34 , V_104 ) ;
return V_16 ;
}
static int F_57 ( struct V_3 * V_4 )
{
struct V_3 * V_34 = V_17 ( V_4 ) -> V_34 ;
const struct V_89 * V_90 = V_34 -> V_91 ;
int V_23 = - V_70 ;
if ( V_90 -> V_110 )
V_23 = V_90 -> V_110 ( V_34 ) ;
return V_23 ;
}
static int F_58 ( struct V_3 * V_4 )
{
struct V_3 * V_34 = V_17 ( V_4 ) -> V_34 ;
const struct V_89 * V_90 = V_34 -> V_91 ;
int V_23 = - V_70 ;
if ( V_90 -> V_111 )
V_23 = V_90 -> V_111 ( V_34 ) ;
return V_23 ;
}
static int F_59 ( struct V_3 * V_4 , T_4 * V_112 , int type )
{
struct V_3 * V_34 = V_17 ( V_4 ) -> V_34 ;
const struct V_89 * V_90 = V_34 -> V_91 ;
int V_23 = - V_70 ;
if ( V_90 -> V_113 )
V_23 = V_90 -> V_113 ( V_34 , V_112 , type ) ;
return V_23 ;
}
static int F_60 ( struct V_3 * V_4 , T_1 V_104 ,
struct V_105 * V_106 , unsigned int V_107 )
{
struct V_3 * V_34 = V_17 ( V_4 ) -> V_34 ;
const struct V_89 * V_90 = V_34 -> V_91 ;
int V_23 = 0 ;
if ( V_90 -> V_114 )
V_23 = V_90 -> V_114 ( V_34 , V_104 , V_106 , V_107 ) ;
return V_23 ;
}
static void F_61 ( struct V_3 * V_4 , int V_115 )
{
struct V_3 * V_34 = V_17 ( V_4 ) -> V_34 ;
if ( V_4 -> V_24 & V_73 ) {
if ( V_115 & V_76 )
F_41 ( V_34 , V_4 -> V_24 & V_76 ? 1 : - 1 ) ;
if ( V_115 & V_78 )
F_42 ( V_34 , V_4 -> V_24 & V_78 ? 1 : - 1 ) ;
}
}
static void F_62 ( struct V_3 * V_116 )
{
F_63 ( V_17 ( V_116 ) -> V_34 , V_116 ) ;
F_64 ( V_17 ( V_116 ) -> V_34 , V_116 ) ;
}
static void F_65 ( struct V_3 * V_4 ,
struct V_117 * V_118 ,
void * V_119 )
{
F_66 ( & V_118 -> V_120 ,
& V_121 ,
* ( int * ) V_119 ) ;
}
static void F_67 ( struct V_3 * V_4 , int V_122 )
{
F_66 ( & V_4 -> V_123 ,
& V_124 ,
V_122 ) ;
F_68 ( V_4 , F_65 , & V_122 ) ;
}
static int F_69 ( struct V_3 * V_4 )
{
return V_17 ( V_4 ) -> V_125 ;
}
static int F_70 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_14 , const void * V_15 ,
unsigned int V_16 )
{
struct V_17 * V_18 = V_17 ( V_4 ) ;
struct V_3 * V_34 = V_18 -> V_34 ;
if ( V_15 == NULL )
V_15 = V_4 -> V_13 ;
return F_11 ( V_2 , V_34 , type , V_14 , V_15 , V_16 ) ;
}
static int F_71 ( struct V_3 * V_4 )
{
struct V_3 * V_34 = V_17 ( V_4 ) -> V_34 ;
F_46 ( V_4 ) ;
V_4 -> V_24 = V_34 -> V_24 & ~ ( V_73 | V_78 | V_76 |
V_126 | V_127 ) ;
V_4 -> V_128 = V_34 -> V_129 ;
V_4 -> V_130 = ( V_34 -> V_130 & ( ( 1 << V_131 ) |
( 1 << V_132 ) ) ) |
( 1 << V_133 ) ;
V_4 -> V_134 = V_135 | V_136 |
V_137 | V_138 |
V_139 | V_140 |
V_141 ;
V_4 -> V_142 |= V_34 -> V_143 | V_144 ;
V_4 -> V_145 = V_34 -> V_145 ;
if ( V_4 -> V_142 & V_146 )
F_72 ( V_34 , L_2 ) ;
V_4 -> V_147 = V_34 -> V_147 ;
if ( F_73 ( V_4 -> V_13 ) )
F_74 ( V_4 , V_34 ) ;
if ( F_73 ( V_4 -> V_148 ) )
memcpy ( V_4 -> V_148 , V_34 -> V_148 , V_4 -> V_149 ) ;
#if F_75 ( V_150 )
V_4 -> V_151 = V_34 -> V_151 ;
#endif
V_4 -> V_152 = V_34 -> V_152 ;
if ( F_76 ( V_34 -> V_142 ,
V_17 ( V_4 ) -> V_33 ) ) {
V_4 -> V_153 = & V_154 ;
V_4 -> V_155 = V_34 -> V_155 ;
} else {
V_4 -> V_153 = & V_156 ;
V_4 -> V_155 = V_34 -> V_155 + V_26 ;
}
V_4 -> V_91 = & V_157 ;
F_77 ( V_4 , & V_158 ) ;
F_67 ( V_4 , F_69 ( V_4 ) ) ;
V_17 ( V_4 ) -> V_41 = F_78 ( struct V_41 ) ;
if ( ! V_17 ( V_4 ) -> V_41 )
return - V_159 ;
return 0 ;
}
static void F_79 ( struct V_3 * V_4 )
{
struct V_54 * V_160 ;
struct V_17 * V_18 = V_17 ( V_4 ) ;
int V_161 ;
F_80 ( V_18 -> V_41 ) ;
V_18 -> V_41 = NULL ;
for ( V_161 = 0 ; V_161 < F_81 ( V_18 -> V_60 ) ; V_161 ++ ) {
while ( ( V_160 = V_18 -> V_60 [ V_161 ] ) != NULL ) {
V_18 -> V_60 [ V_161 ] = V_160 -> V_62 ;
F_82 ( V_160 ) ;
}
}
}
static T_5 F_83 ( struct V_3 * V_4 ,
T_5 V_142 )
{
struct V_3 * V_34 = V_17 ( V_4 ) -> V_34 ;
T_5 V_162 = V_142 ;
V_142 &= V_34 -> V_143 ;
V_142 |= V_163 ;
V_142 &= V_34 -> V_142 ;
V_142 |= V_162 & V_164 ;
V_142 |= V_144 ;
return V_142 ;
}
static int F_84 ( struct V_3 * V_4 ,
struct V_165 * V_88 )
{
const struct V_17 * V_18 = V_17 ( V_4 ) ;
return F_85 ( V_18 -> V_34 , V_88 ) ;
}
static void F_86 ( struct V_3 * V_4 ,
struct V_166 * V_167 )
{
F_87 ( V_167 -> V_168 , V_169 , sizeof( V_167 -> V_168 ) ) ;
F_87 ( V_167 -> V_170 , V_171 , sizeof( V_167 -> V_170 ) ) ;
F_87 ( V_167 -> V_172 , L_3 , sizeof( V_167 -> V_172 ) ) ;
}
static struct V_173 * F_88 ( struct V_3 * V_4 , struct V_173 * V_42 )
{
if ( V_17 ( V_4 ) -> V_41 ) {
struct V_41 * V_81 ;
T_3 V_174 = 0 , V_46 = 0 ;
int V_161 ;
F_89 (i) {
T_4 V_175 , V_176 , V_177 , V_178 , V_179 ;
unsigned int V_180 ;
V_81 = F_90 ( V_17 ( V_4 ) -> V_41 , V_161 ) ;
do {
V_180 = F_91 ( & V_81 -> V_43 ) ;
V_175 = V_81 -> V_181 ;
V_176 = V_81 -> V_182 ;
V_177 = V_81 -> V_183 ;
V_178 = V_81 -> V_44 ;
V_179 = V_81 -> V_45 ;
} while ( F_92 ( & V_81 -> V_43 , V_180 ) );
V_42 -> V_181 += V_175 ;
V_42 -> V_182 += V_176 ;
V_42 -> V_184 += V_177 ;
V_42 -> V_44 += V_178 ;
V_42 -> V_45 += V_179 ;
V_174 += V_81 -> V_174 ;
V_46 += V_81 -> V_46 ;
}
V_42 -> V_174 = V_174 ;
V_42 -> V_46 = V_46 ;
}
return V_42 ;
}
static void F_93 ( struct V_3 * V_4 )
{
return;
}
static int F_94 ( struct V_3 * V_4 , struct V_185 * V_186 )
{
struct V_17 * V_18 = V_17 ( V_4 ) ;
struct V_3 * V_34 = V_18 -> V_34 ;
struct V_35 * V_35 ;
int V_72 = 0 ;
V_35 = F_95 ( sizeof( * V_35 ) , V_63 ) ;
V_72 = - V_159 ;
if ( ! V_35 )
goto V_75;
V_72 = F_96 ( V_35 , V_34 ) ;
if ( V_72 ) {
F_82 ( V_35 ) ;
goto V_75;
}
V_18 -> V_35 = V_35 ;
V_75:
return V_72 ;
}
static void F_97 ( struct V_3 * V_4 )
{
struct V_17 * V_18 = V_17 ( V_4 ) ;
struct V_35 * V_35 = V_18 -> V_35 ;
if ( ! V_35 )
return;
V_18 -> V_35 = NULL ;
F_98 ( V_35 ) ;
}
void F_99 ( struct V_3 * V_4 )
{
F_100 ( V_4 ) ;
V_4 -> V_187 |= V_188 ;
V_4 -> V_187 &= ~ ( V_189 | V_190 ) ;
V_4 -> V_191 = 0 ;
V_4 -> V_91 = & V_157 ;
V_4 -> V_192 = V_193 ;
V_4 -> V_194 = & V_195 ;
memset ( V_4 -> V_148 , 0 , V_196 ) ;
}
