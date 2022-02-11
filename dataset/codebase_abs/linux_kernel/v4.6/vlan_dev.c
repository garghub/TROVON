static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_5 , const void * V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_10 * V_11 ;
unsigned int V_12 = 0 ;
T_1 V_13 = 0 ;
int V_14 ;
if ( ! ( V_9 -> V_15 & V_16 ) ) {
V_11 = (struct V_10 * ) F_2 ( V_2 , V_17 ) ;
V_13 = V_9 -> V_18 ;
V_13 |= F_3 ( V_4 , V_2 -> V_19 ) ;
V_11 -> V_20 = F_4 ( V_13 ) ;
if ( type != V_21 && type != V_22 )
V_11 -> V_23 = F_4 ( type ) ;
else
V_11 -> V_23 = F_4 ( V_7 ) ;
V_2 -> V_24 = V_9 -> V_25 ;
type = F_5 ( V_9 -> V_25 ) ;
V_12 = V_17 ;
}
if ( V_6 == NULL )
V_6 = V_4 -> V_26 ;
V_4 = V_9 -> V_27 ;
V_14 = F_6 ( V_2 , V_4 , type , V_5 , V_6 , V_7 + V_12 ) ;
if ( V_14 > 0 )
V_14 += V_12 ;
return V_14 ;
}
static inline T_2 F_7 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
#ifdef F_8
if ( V_9 -> V_28 )
F_9 ( V_9 -> V_28 , V_2 ) ;
#else
F_10 () ;
#endif
return V_29 ;
}
static T_2 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_30 * V_31 = (struct V_30 * ) ( V_2 -> V_32 ) ;
unsigned int V_7 ;
int V_33 ;
if ( V_31 -> V_34 != V_9 -> V_25 ||
V_9 -> V_15 & V_16 ) {
T_1 V_13 ;
V_13 = V_9 -> V_18 ;
V_13 |= F_3 ( V_4 , V_2 -> V_19 ) ;
F_12 ( V_2 , V_9 -> V_25 , V_13 ) ;
}
V_2 -> V_4 = V_9 -> V_27 ;
V_7 = V_2 -> V_7 ;
if ( F_13 ( F_14 ( V_4 ) ) )
return F_7 ( V_9 , V_2 ) ;
V_33 = F_15 ( V_2 ) ;
if ( F_16 ( V_33 == V_35 || V_33 == V_36 ) ) {
struct V_37 * V_38 ;
V_38 = F_17 ( V_9 -> V_37 ) ;
F_18 ( & V_38 -> V_39 ) ;
V_38 -> V_40 ++ ;
V_38 -> V_41 += V_7 ;
F_19 ( & V_38 -> V_39 ) ;
} else {
F_20 ( V_9 -> V_37 -> V_42 ) ;
}
return V_33 ;
}
static int F_21 ( struct V_3 * V_4 , int V_43 )
{
if ( V_8 ( V_4 ) -> V_27 -> V_44 < V_43 )
return - V_45 ;
V_4 -> V_44 = V_43 ;
return 0 ;
}
void F_22 ( const struct V_3 * V_4 ,
T_3 V_46 , T_1 V_47 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
if ( V_9 -> V_48 [ V_47 & 0x7 ] && ! V_46 )
V_9 -> V_49 -- ;
else if ( ! V_9 -> V_48 [ V_47 & 0x7 ] && V_46 )
V_9 -> V_49 ++ ;
V_9 -> V_48 [ V_47 & 0x7 ] = V_46 ;
}
int F_23 ( const struct V_3 * V_4 ,
T_3 V_46 , T_1 V_47 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_50 * V_51 = NULL ;
struct V_50 * V_52 ;
T_3 V_53 = ( V_47 << V_54 ) & V_55 ;
V_51 = V_9 -> V_56 [ V_46 & 0xF ] ;
while ( V_51 ) {
if ( V_51 -> V_19 == V_46 ) {
if ( V_51 -> V_53 && ! V_53 )
V_9 -> V_57 -- ;
else if ( ! V_51 -> V_53 && V_53 )
V_9 -> V_57 ++ ;
V_51 -> V_53 = V_53 ;
return 0 ;
}
V_51 = V_51 -> V_58 ;
}
V_51 = V_9 -> V_56 [ V_46 & 0xF ] ;
V_52 = F_24 ( sizeof( struct V_50 ) , V_59 ) ;
if ( ! V_52 )
return - V_60 ;
V_52 -> V_58 = V_51 ;
V_52 -> V_19 = V_46 ;
V_52 -> V_53 = V_53 ;
F_25 () ;
V_9 -> V_56 [ V_46 & 0xF ] = V_52 ;
if ( V_53 )
V_9 -> V_57 ++ ;
return 0 ;
}
int F_26 ( const struct V_3 * V_4 , T_3 V_15 , T_3 V_61 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
T_3 V_62 = V_9 -> V_15 ;
if ( V_61 & ~ ( V_16 | V_63 |
V_64 | V_65 ) )
return - V_66 ;
V_9 -> V_15 = ( V_62 & ~ V_61 ) | ( V_15 & V_61 ) ;
if ( F_27 ( V_4 ) && ( V_9 -> V_15 ^ V_62 ) & V_63 ) {
if ( V_9 -> V_15 & V_63 )
F_28 ( V_4 ) ;
else
F_29 ( V_4 ) ;
}
if ( F_27 ( V_4 ) && ( V_9 -> V_15 ^ V_62 ) & V_65 ) {
if ( V_9 -> V_15 & V_65 )
F_30 ( V_4 ) ;
else
F_31 ( V_4 ) ;
}
return 0 ;
}
void F_32 ( const struct V_3 * V_4 , char * V_67 )
{
strncpy ( V_67 , V_8 ( V_4 ) -> V_27 -> V_68 , 23 ) ;
}
static int F_33 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_3 * V_27 = V_9 -> V_27 ;
int V_69 ;
if ( ! ( V_27 -> V_15 & V_70 ) &&
! ( V_9 -> V_15 & V_64 ) )
return - V_71 ;
if ( ! F_34 ( V_4 -> V_26 , V_27 -> V_26 ) ) {
V_69 = F_35 ( V_27 , V_4 -> V_26 ) ;
if ( V_69 < 0 )
goto V_72;
}
if ( V_4 -> V_15 & V_73 ) {
V_69 = F_36 ( V_27 , 1 ) ;
if ( V_69 < 0 )
goto V_74;
}
if ( V_4 -> V_15 & V_75 ) {
V_69 = F_37 ( V_27 , 1 ) ;
if ( V_69 < 0 )
goto V_76;
}
F_38 ( V_9 -> V_77 , V_27 -> V_26 ) ;
if ( V_9 -> V_15 & V_63 )
F_28 ( V_4 ) ;
if ( V_9 -> V_15 & V_65 )
F_30 ( V_4 ) ;
if ( F_39 ( V_27 ) )
F_40 ( V_4 ) ;
return 0 ;
V_76:
if ( V_4 -> V_15 & V_73 )
F_36 ( V_27 , - 1 ) ;
V_74:
if ( ! F_34 ( V_4 -> V_26 , V_27 -> V_26 ) )
F_41 ( V_27 , V_4 -> V_26 ) ;
V_72:
F_42 ( V_4 ) ;
return V_69 ;
}
static int F_43 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_3 * V_27 = V_9 -> V_27 ;
F_44 ( V_27 , V_4 ) ;
F_45 ( V_27 , V_4 ) ;
if ( V_4 -> V_15 & V_73 )
F_36 ( V_27 , - 1 ) ;
if ( V_4 -> V_15 & V_75 )
F_37 ( V_27 , - 1 ) ;
if ( ! F_34 ( V_4 -> V_26 , V_27 -> V_26 ) )
F_41 ( V_27 , V_4 -> V_26 ) ;
F_42 ( V_4 ) ;
return 0 ;
}
static int F_46 ( struct V_3 * V_4 , void * V_78 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
struct V_79 * V_80 = V_78 ;
int V_69 ;
if ( ! F_47 ( V_80 -> V_81 ) )
return - V_82 ;
if ( ! ( V_4 -> V_15 & V_70 ) )
goto V_72;
if ( ! F_34 ( V_80 -> V_81 , V_27 -> V_26 ) ) {
V_69 = F_35 ( V_27 , V_80 -> V_81 ) ;
if ( V_69 < 0 )
return V_69 ;
}
if ( ! F_34 ( V_4 -> V_26 , V_27 -> V_26 ) )
F_41 ( V_27 , V_4 -> V_26 ) ;
V_72:
F_38 ( V_4 -> V_26 , V_80 -> V_81 ) ;
return 0 ;
}
static int F_48 ( struct V_3 * V_4 , struct V_83 * V_84 , int V_85 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_86 * V_87 = V_27 -> V_88 ;
struct V_83 V_89 ;
int V_69 = - V_90 ;
strncpy ( V_89 . V_91 , V_27 -> V_68 , V_92 ) ;
V_89 . V_93 = V_84 -> V_93 ;
switch ( V_85 ) {
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
if ( F_49 ( V_27 ) && V_87 -> V_99 )
V_69 = V_87 -> V_99 ( V_27 , & V_89 , V_85 ) ;
break;
}
if ( ! V_69 )
V_84 -> V_93 = V_89 . V_93 ;
return V_69 ;
}
static int F_50 ( struct V_3 * V_4 , struct V_100 * V_101 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_86 * V_87 = V_27 -> V_88 ;
int V_69 = 0 ;
if ( F_49 ( V_27 ) && V_87 -> V_102 )
V_69 = V_87 -> V_102 ( V_27 , V_101 ) ;
return V_69 ;
}
static int F_51 ( struct V_3 * V_4 , T_1 V_103 ,
struct V_104 * V_105 , unsigned int V_106 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_86 * V_87 = V_27 -> V_88 ;
int V_14 = 0 ;
if ( V_87 -> V_107 )
V_14 = V_87 -> V_107 ( V_27 , V_103 , V_105 , V_106 ) ;
return V_14 ;
}
static int F_52 ( struct V_3 * V_4 , T_1 V_103 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_86 * V_87 = V_27 -> V_88 ;
int V_7 = 0 ;
if ( V_87 -> V_108 )
V_7 = V_87 -> V_108 ( V_27 , V_103 ) ;
return V_7 ;
}
static int F_53 ( struct V_3 * V_4 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_86 * V_87 = V_27 -> V_88 ;
int V_14 = - V_66 ;
if ( V_87 -> V_109 )
V_14 = V_87 -> V_109 ( V_27 ) ;
return V_14 ;
}
static int F_54 ( struct V_3 * V_4 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_86 * V_87 = V_27 -> V_88 ;
int V_14 = - V_66 ;
if ( V_87 -> V_110 )
V_14 = V_87 -> V_110 ( V_27 ) ;
return V_14 ;
}
static int F_55 ( struct V_3 * V_4 , T_4 * V_111 , int type )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_86 * V_87 = V_27 -> V_88 ;
int V_14 = - V_66 ;
if ( V_87 -> V_112 )
V_14 = V_87 -> V_112 ( V_27 , V_111 , type ) ;
return V_14 ;
}
static int F_56 ( struct V_3 * V_4 , T_1 V_103 ,
struct V_104 * V_105 , unsigned int V_106 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
const struct V_86 * V_87 = V_27 -> V_88 ;
int V_14 = 0 ;
if ( V_87 -> V_113 )
V_14 = V_87 -> V_113 ( V_27 , V_103 , V_105 , V_106 ) ;
return V_14 ;
}
static void F_57 ( struct V_3 * V_4 , int V_114 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
if ( V_4 -> V_15 & V_70 ) {
if ( V_114 & V_73 )
F_36 ( V_27 , V_4 -> V_15 & V_73 ? 1 : - 1 ) ;
if ( V_114 & V_75 )
F_37 ( V_27 , V_4 -> V_15 & V_75 ? 1 : - 1 ) ;
}
}
static void F_58 ( struct V_3 * V_115 )
{
F_59 ( V_8 ( V_115 ) -> V_27 , V_115 ) ;
F_60 ( V_8 ( V_115 ) -> V_27 , V_115 ) ;
}
static void F_61 ( struct V_3 * V_4 ,
struct V_116 * V_117 ,
void * V_118 )
{
F_62 ( & V_117 -> V_119 ,
& V_120 ,
* ( int * ) V_118 ) ;
}
static void F_63 ( struct V_3 * V_4 , int V_121 )
{
F_62 ( & V_4 -> V_122 ,
& V_123 ,
V_121 ) ;
F_64 ( V_4 , F_61 , & V_121 ) ;
}
static int F_65 ( struct V_3 * V_4 )
{
return V_8 ( V_4 ) -> V_124 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned short type ,
const void * V_5 , const void * V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_3 * V_27 = V_9 -> V_27 ;
if ( V_6 == NULL )
V_6 = V_4 -> V_26 ;
return F_6 ( V_2 , V_27 , type , V_5 , V_6 , V_7 ) ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
F_42 ( V_4 ) ;
V_4 -> V_15 = V_27 -> V_15 & ~ ( V_70 | V_75 | V_73 |
V_125 | V_126 ) ;
V_4 -> V_127 = ( V_27 -> V_127 & ( ( 1 << V_128 ) |
( 1 << V_129 ) ) ) |
( 1 << V_130 ) ;
V_4 -> V_131 = V_132 | V_133 |
V_134 | V_135 |
V_136 | V_137 |
V_138 ;
V_4 -> V_139 |= V_27 -> V_140 | V_141 |
V_135 ;
V_4 -> V_142 = V_27 -> V_142 ;
V_4 -> V_143 = V_27 -> V_143 ;
if ( V_4 -> V_139 & V_144 )
F_68 ( V_27 , L_1 ) ;
V_4 -> V_140 = V_27 -> V_140 & ~ V_138 ;
V_4 -> V_145 = V_27 -> V_145 ;
if ( F_69 ( V_4 -> V_26 ) )
F_70 ( V_4 , V_27 ) ;
if ( F_69 ( V_4 -> V_146 ) )
memcpy ( V_4 -> V_146 , V_27 -> V_146 , V_4 -> V_147 ) ;
#if F_71 ( V_148 )
V_4 -> V_149 = V_27 -> V_149 ;
#endif
V_4 -> V_150 = V_27 -> V_150 ;
if ( F_72 ( V_27 -> V_139 ,
V_8 ( V_4 ) -> V_25 ) ) {
V_4 -> V_151 = & V_152 ;
V_4 -> V_153 = V_27 -> V_153 ;
} else {
V_4 -> V_151 = & V_154 ;
V_4 -> V_153 = V_27 -> V_153 + V_17 ;
}
V_4 -> V_88 = & V_155 ;
F_73 ( V_4 , & V_156 ) ;
F_63 ( V_4 , F_65 ( V_4 ) ) ;
V_8 ( V_4 ) -> V_37 = F_74 ( struct V_37 ) ;
if ( ! V_8 ( V_4 ) -> V_37 )
return - V_157 ;
return 0 ;
}
static void F_75 ( struct V_3 * V_4 )
{
struct V_50 * V_158 ;
struct V_8 * V_9 = V_8 ( V_4 ) ;
int V_159 ;
for ( V_159 = 0 ; V_159 < F_76 ( V_9 -> V_56 ) ; V_159 ++ ) {
while ( ( V_158 = V_9 -> V_56 [ V_159 ] ) != NULL ) {
V_9 -> V_56 [ V_159 ] = V_158 -> V_58 ;
F_77 ( V_158 ) ;
}
}
}
static T_5 F_78 ( struct V_3 * V_4 ,
T_5 V_139 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
T_5 V_160 = V_139 ;
V_139 = F_79 ( V_139 , V_27 -> V_140 ) ;
V_139 |= V_161 ;
V_139 = F_79 ( V_139 , V_27 -> V_139 ) ;
V_139 |= V_160 & ( V_162 | V_135 ) ;
V_139 |= V_141 ;
return V_139 ;
}
static int F_80 ( struct V_3 * V_4 ,
struct V_163 * V_85 )
{
const struct V_8 * V_9 = V_8 ( V_4 ) ;
return F_81 ( V_9 -> V_27 , V_85 ) ;
}
static void F_82 ( struct V_3 * V_4 ,
struct V_164 * V_165 )
{
F_83 ( V_165 -> V_166 , V_167 , sizeof( V_165 -> V_166 ) ) ;
F_83 ( V_165 -> V_168 , V_169 , sizeof( V_165 -> V_168 ) ) ;
F_83 ( V_165 -> V_170 , L_2 , sizeof( V_165 -> V_170 ) ) ;
}
static int F_84 ( struct V_3 * V_4 ,
struct V_171 * V_165 )
{
const struct V_8 * V_9 = V_8 ( V_4 ) ;
const struct V_172 * V_87 = V_9 -> V_27 -> V_172 ;
if ( V_87 -> V_173 ) {
return V_87 -> V_173 ( V_9 -> V_27 , V_165 ) ;
} else {
V_165 -> V_174 = V_175 |
V_176 ;
V_165 -> V_177 = - 1 ;
}
return 0 ;
}
static struct V_178 * F_85 ( struct V_3 * V_4 , struct V_178 * V_38 )
{
struct V_37 * V_78 ;
T_3 V_179 = 0 , V_42 = 0 ;
int V_159 ;
F_86 (i) {
T_4 V_180 , V_181 , V_182 , V_183 , V_184 ;
unsigned int V_185 ;
V_78 = F_87 ( V_8 ( V_4 ) -> V_37 , V_159 ) ;
do {
V_185 = F_88 ( & V_78 -> V_39 ) ;
V_180 = V_78 -> V_186 ;
V_181 = V_78 -> V_187 ;
V_182 = V_78 -> V_188 ;
V_183 = V_78 -> V_40 ;
V_184 = V_78 -> V_41 ;
} while ( F_89 ( & V_78 -> V_39 , V_185 ) );
V_38 -> V_186 += V_180 ;
V_38 -> V_187 += V_181 ;
V_38 -> V_189 += V_182 ;
V_38 -> V_40 += V_183 ;
V_38 -> V_41 += V_184 ;
V_179 += V_78 -> V_179 ;
V_42 += V_78 -> V_42 ;
}
V_38 -> V_179 = V_179 ;
V_38 -> V_42 = V_42 ;
return V_38 ;
}
static void F_90 ( struct V_3 * V_4 )
{
return;
}
static int F_91 ( struct V_3 * V_4 , struct V_190 * V_191 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_3 * V_27 = V_9 -> V_27 ;
struct V_28 * V_28 ;
int V_69 = 0 ;
V_28 = F_92 ( sizeof( * V_28 ) , V_59 ) ;
V_69 = - V_157 ;
if ( ! V_28 )
goto V_72;
V_69 = F_93 ( V_28 , V_27 ) ;
if ( V_69 ) {
F_77 ( V_28 ) ;
goto V_72;
}
V_9 -> V_28 = V_28 ;
V_72:
return V_69 ;
}
static void F_94 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
struct V_28 * V_28 = V_9 -> V_28 ;
if ( ! V_28 )
return;
V_9 -> V_28 = NULL ;
F_95 ( V_28 ) ;
}
static int F_96 ( const struct V_3 * V_4 )
{
struct V_3 * V_27 = V_8 ( V_4 ) -> V_27 ;
return V_27 -> V_192 ;
}
static void F_97 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_8 ( V_4 ) ;
F_98 ( V_9 -> V_37 ) ;
V_9 -> V_37 = NULL ;
F_99 ( V_4 ) ;
}
void F_100 ( struct V_3 * V_4 )
{
F_101 ( V_4 ) ;
V_4 -> V_193 |= V_194 | V_195 ;
V_4 -> V_193 |= V_196 ;
V_4 -> V_193 &= ~ V_197 ;
F_102 ( V_4 ) ;
V_4 -> V_88 = & V_155 ;
V_4 -> V_198 = F_97 ;
V_4 -> V_172 = & V_199 ;
F_103 ( V_4 -> V_146 ) ;
}
