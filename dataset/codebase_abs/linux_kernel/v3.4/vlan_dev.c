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
struct V_24 * V_25 ;
unsigned int V_26 = 0 ;
T_1 V_27 = 0 ;
int V_28 ;
if ( ! ( F_8 ( V_4 ) -> V_29 & V_30 ) ) {
V_25 = (struct V_24 * ) F_10 ( V_2 , V_31 ) ;
V_27 = F_8 ( V_4 ) -> V_32 ;
V_27 |= F_7 ( V_4 , V_2 ) ;
V_25 -> V_33 = F_3 ( V_27 ) ;
if ( type != V_34 && type != V_35 )
V_25 -> V_8 = F_3 ( type ) ;
else
V_25 -> V_8 = F_3 ( V_23 ) ;
V_2 -> V_36 = F_3 ( V_37 ) ;
type = V_37 ;
V_26 = V_31 ;
}
if ( V_22 == NULL )
V_22 = V_4 -> V_13 ;
V_4 = F_8 ( V_4 ) -> V_38 ;
V_28 = F_11 ( V_2 , V_4 , type , V_21 , V_22 , V_23 + V_26 ) ;
if ( V_28 > 0 )
V_28 += V_26 ;
return V_28 ;
}
static T_2 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) ( V_2 -> V_7 ) ;
unsigned int V_23 ;
int V_39 ;
if ( V_6 -> V_40 != F_3 ( V_37 ) ||
F_8 ( V_4 ) -> V_29 & V_30 ) {
T_1 V_27 ;
V_27 = F_8 ( V_4 ) -> V_32 ;
V_27 |= F_7 ( V_4 , V_2 ) ;
V_2 = F_13 ( V_2 , V_27 ) ;
}
V_2 -> V_4 = F_8 ( V_4 ) -> V_38 ;
V_23 = V_2 -> V_23 ;
if ( F_14 ( V_4 ) )
return V_2 -> V_4 -> V_41 -> V_42 ( V_2 , V_2 -> V_4 ) ;
V_39 = F_15 ( V_2 ) ;
if ( F_16 ( V_39 == V_43 || V_39 == V_44 ) ) {
struct V_45 * V_46 ;
V_46 = F_17 ( F_8 ( V_4 ) -> V_45 ) ;
F_18 ( & V_46 -> V_47 ) ;
V_46 -> V_48 ++ ;
V_46 -> V_49 += V_23 ;
F_19 ( & V_46 -> V_47 ) ;
} else {
F_20 ( F_8 ( V_4 ) -> V_45 -> V_50 ) ;
}
return V_39 ;
}
static int F_21 ( struct V_3 * V_4 , int V_51 )
{
if ( F_8 ( V_4 ) -> V_38 -> V_52 < V_51 )
return - V_53 ;
V_4 -> V_52 = V_51 ;
return 0 ;
}
void F_22 ( const struct V_3 * V_4 ,
T_3 V_54 , T_1 V_55 )
{
struct F_8 * V_56 = F_8 ( V_4 ) ;
if ( V_56 -> V_57 [ V_55 & 0x7 ] && ! V_54 )
V_56 -> V_58 -- ;
else if ( ! V_56 -> V_57 [ V_55 & 0x7 ] && V_54 )
V_56 -> V_58 ++ ;
V_56 -> V_57 [ V_55 & 0x7 ] = V_54 ;
}
int F_23 ( const struct V_3 * V_4 ,
T_3 V_54 , T_1 V_55 )
{
struct F_8 * V_56 = F_8 ( V_4 ) ;
struct V_15 * V_16 = NULL ;
struct V_15 * V_59 ;
T_3 V_19 = ( V_55 << V_60 ) & V_61 ;
V_16 = V_56 -> V_17 [ V_54 & 0xF ] ;
while ( V_16 ) {
if ( V_16 -> V_18 == V_54 ) {
if ( V_16 -> V_19 && ! V_19 )
V_56 -> V_62 -- ;
else if ( ! V_16 -> V_19 && V_19 )
V_56 -> V_62 ++ ;
V_16 -> V_19 = V_19 ;
return 0 ;
}
V_16 = V_16 -> V_20 ;
}
V_16 = V_56 -> V_17 [ V_54 & 0xF ] ;
V_59 = F_24 ( sizeof( struct V_15 ) , V_63 ) ;
if ( ! V_59 )
return - V_64 ;
V_59 -> V_20 = V_16 ;
V_59 -> V_18 = V_54 ;
V_59 -> V_19 = V_19 ;
V_56 -> V_17 [ V_54 & 0xF ] = V_59 ;
if ( V_19 )
V_56 -> V_62 ++ ;
return 0 ;
}
int F_25 ( const struct V_3 * V_4 , T_3 V_29 , T_3 V_65 )
{
struct F_8 * V_56 = F_8 ( V_4 ) ;
T_3 V_66 = V_56 -> V_29 ;
if ( V_65 & ~ ( V_30 | V_67 |
V_68 ) )
return - V_69 ;
V_56 -> V_29 = ( V_66 & ~ V_65 ) | ( V_29 & V_65 ) ;
if ( F_26 ( V_4 ) && ( V_56 -> V_29 ^ V_66 ) & V_67 ) {
if ( V_56 -> V_29 & V_67 )
F_27 ( V_4 ) ;
else
F_28 ( V_4 ) ;
}
return 0 ;
}
void F_29 ( const struct V_3 * V_4 , char * V_70 )
{
strncpy ( V_70 , F_8 ( V_4 ) -> V_38 -> V_11 , 23 ) ;
}
static int F_30 ( struct V_3 * V_4 )
{
struct F_8 * V_56 = F_8 ( V_4 ) ;
struct V_3 * V_38 = V_56 -> V_38 ;
int V_71 ;
if ( ! ( V_38 -> V_29 & V_72 ) &&
! ( V_56 -> V_29 & V_68 ) )
return - V_73 ;
if ( F_31 ( V_4 -> V_13 , V_38 -> V_13 ) ) {
V_71 = F_32 ( V_38 , V_4 -> V_13 ) ;
if ( V_71 < 0 )
goto V_74;
}
if ( V_4 -> V_29 & V_75 ) {
V_71 = F_33 ( V_38 , 1 ) ;
if ( V_71 < 0 )
goto V_76;
}
if ( V_4 -> V_29 & V_77 ) {
V_71 = F_34 ( V_38 , 1 ) ;
if ( V_71 < 0 )
goto V_78;
}
memcpy ( V_56 -> V_79 , V_38 -> V_13 , V_14 ) ;
if ( V_56 -> V_29 & V_67 )
F_27 ( V_4 ) ;
if ( F_35 ( V_38 ) )
F_36 ( V_4 ) ;
return 0 ;
V_78:
if ( V_4 -> V_29 & V_75 )
F_33 ( V_38 , - 1 ) ;
V_76:
if ( F_31 ( V_4 -> V_13 , V_38 -> V_13 ) )
F_37 ( V_38 , V_4 -> V_13 ) ;
V_74:
F_38 ( V_4 ) ;
return V_71 ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct F_8 * V_56 = F_8 ( V_4 ) ;
struct V_3 * V_38 = V_56 -> V_38 ;
F_40 ( V_38 , V_4 ) ;
F_41 ( V_38 , V_4 ) ;
if ( V_4 -> V_29 & V_75 )
F_33 ( V_38 , - 1 ) ;
if ( V_4 -> V_29 & V_77 )
F_34 ( V_38 , - 1 ) ;
if ( F_31 ( V_4 -> V_13 , V_38 -> V_13 ) )
F_37 ( V_38 , V_4 -> V_13 ) ;
F_38 ( V_4 ) ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , void * V_80 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
struct V_81 * V_82 = V_80 ;
int V_71 ;
if ( ! F_43 ( V_82 -> V_83 ) )
return - V_84 ;
if ( ! ( V_4 -> V_29 & V_72 ) )
goto V_74;
if ( F_31 ( V_82 -> V_83 , V_38 -> V_13 ) ) {
V_71 = F_32 ( V_38 , V_82 -> V_83 ) ;
if ( V_71 < 0 )
return V_71 ;
}
if ( F_31 ( V_4 -> V_13 , V_38 -> V_13 ) )
F_37 ( V_38 , V_4 -> V_13 ) ;
V_74:
memcpy ( V_4 -> V_13 , V_82 -> V_83 , V_14 ) ;
return 0 ;
}
static int F_44 ( struct V_3 * V_4 , struct V_85 * V_86 , int V_87 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_41 ;
struct V_85 V_90 ;
int V_71 = - V_91 ;
strncpy ( V_90 . V_92 , V_38 -> V_11 , V_93 ) ;
V_90 . V_94 = V_86 -> V_94 ;
switch ( V_87 ) {
case V_95 :
case V_96 :
case V_97 :
if ( F_45 ( V_38 ) && V_89 -> V_98 )
V_71 = V_89 -> V_98 ( V_38 , & V_90 , V_87 ) ;
break;
}
if ( ! V_71 )
V_86 -> V_94 = V_90 . V_94 ;
return V_71 ;
}
static int F_46 ( struct V_3 * V_4 , struct V_99 * V_100 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_41 ;
int V_71 = 0 ;
if ( F_45 ( V_38 ) && V_89 -> V_101 )
V_71 = V_89 -> V_101 ( V_38 , V_100 ) ;
return V_71 ;
}
static int F_47 ( struct V_3 * V_4 , T_1 V_102 ,
struct V_103 * V_104 , unsigned int V_105 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_41 ;
int V_28 = 0 ;
if ( V_89 -> V_106 )
V_28 = V_89 -> V_106 ( V_38 , V_102 , V_104 , V_105 ) ;
return V_28 ;
}
static int F_48 ( struct V_3 * V_4 , T_1 V_102 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_41 ;
int V_23 = 0 ;
if ( V_89 -> V_107 )
V_23 = V_89 -> V_107 ( V_38 , V_102 ) ;
return V_23 ;
}
static int F_49 ( struct V_3 * V_4 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_41 ;
int V_28 = - V_69 ;
if ( V_89 -> V_108 )
V_28 = V_89 -> V_108 ( V_38 ) ;
return V_28 ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_41 ;
int V_28 = - V_69 ;
if ( V_89 -> V_109 )
V_28 = V_89 -> V_109 ( V_38 ) ;
return V_28 ;
}
static int F_51 ( struct V_3 * V_4 , T_4 * V_110 , int type )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_41 ;
int V_28 = - V_69 ;
if ( V_89 -> V_111 )
V_28 = V_89 -> V_111 ( V_38 , V_110 , type ) ;
return V_28 ;
}
static int F_52 ( struct V_3 * V_4 , T_1 V_102 ,
struct V_103 * V_104 , unsigned int V_105 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_41 ;
int V_28 = 0 ;
if ( V_89 -> V_112 )
V_28 = V_89 -> V_112 ( V_38 , V_102 , V_104 , V_105 ) ;
return V_28 ;
}
static void F_53 ( struct V_3 * V_4 , int V_113 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
if ( V_4 -> V_29 & V_72 ) {
if ( V_113 & V_75 )
F_33 ( V_38 , V_4 -> V_29 & V_75 ? 1 : - 1 ) ;
if ( V_113 & V_77 )
F_34 ( V_38 , V_4 -> V_29 & V_77 ? 1 : - 1 ) ;
}
}
static void F_54 ( struct V_3 * V_114 )
{
F_55 ( F_8 ( V_114 ) -> V_38 , V_114 ) ;
F_56 ( F_8 ( V_114 ) -> V_38 , V_114 ) ;
}
static void F_57 ( struct V_3 * V_4 ,
struct V_115 * V_116 ,
void * V_117 )
{
F_58 ( & V_116 -> V_118 ,
& V_119 ,
* ( int * ) V_117 ) ;
}
static void F_59 ( struct V_3 * V_4 , int V_120 )
{
F_58 ( & V_4 -> V_121 ,
& V_122 ,
V_120 ) ;
F_60 ( V_4 , F_57 , & V_120 ) ;
}
static int F_61 ( struct V_3 * V_4 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
int V_120 = 0 ;
F_38 ( V_4 ) ;
V_4 -> V_29 = V_38 -> V_29 & ~ ( V_72 | V_77 | V_75 |
V_123 | V_124 ) ;
V_4 -> V_125 = V_38 -> V_126 ;
V_4 -> V_127 = ( V_38 -> V_127 & ( ( 1 << V_128 ) |
( 1 << V_129 ) ) ) |
( 1 << V_130 ) ;
V_4 -> V_131 = V_132 | V_133 |
V_134 | V_135 |
V_136 | V_137 |
V_138 ;
V_4 -> V_139 |= V_38 -> V_140 | V_141 ;
V_4 -> V_142 = V_38 -> V_142 ;
V_4 -> V_143 = V_38 -> V_143 ;
if ( F_62 ( V_4 -> V_13 ) )
memcpy ( V_4 -> V_13 , V_38 -> V_13 , V_4 -> V_144 ) ;
if ( F_62 ( V_4 -> V_145 ) )
memcpy ( V_4 -> V_145 , V_38 -> V_145 , V_4 -> V_144 ) ;
#if F_63 ( V_146 ) || F_63 ( V_147 )
V_4 -> V_148 = V_38 -> V_148 ;
#endif
V_4 -> V_149 = V_38 -> V_149 ;
if ( V_38 -> V_139 & V_150 ) {
V_4 -> V_151 = V_38 -> V_151 ;
V_4 -> V_152 = V_38 -> V_152 ;
} else {
V_4 -> V_151 = & V_153 ;
V_4 -> V_152 = V_38 -> V_152 + V_31 ;
}
V_4 -> V_41 = & V_154 ;
if ( F_64 ( V_38 ) )
V_120 = 1 ;
F_59 ( V_4 , V_120 ) ;
F_8 ( V_4 ) -> V_45 = F_65 ( struct V_45 ) ;
if ( ! F_8 ( V_4 ) -> V_45 )
return - V_155 ;
return 0 ;
}
static void F_66 ( struct V_3 * V_4 )
{
struct V_15 * V_156 ;
struct F_8 * V_56 = F_8 ( V_4 ) ;
int V_157 ;
F_67 ( V_56 -> V_45 ) ;
V_56 -> V_45 = NULL ;
for ( V_157 = 0 ; V_157 < F_68 ( V_56 -> V_17 ) ; V_157 ++ ) {
while ( ( V_156 = V_56 -> V_17 [ V_157 ] ) != NULL ) {
V_56 -> V_17 [ V_157 ] = V_156 -> V_20 ;
F_69 ( V_156 ) ;
}
}
}
static T_5 F_70 ( struct V_3 * V_4 ,
T_5 V_139 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
T_3 V_158 = V_139 ;
V_139 &= V_38 -> V_140 ;
V_139 |= V_159 ;
V_139 &= V_38 -> V_139 ;
V_139 |= V_158 & V_160 ;
V_139 |= V_141 ;
return V_139 ;
}
static int F_71 ( struct V_3 * V_4 ,
struct V_161 * V_87 )
{
const struct F_8 * V_56 = F_8 ( V_4 ) ;
return F_72 ( V_56 -> V_38 , V_87 ) ;
}
static void F_73 ( struct V_3 * V_4 ,
struct V_162 * V_163 )
{
strcpy ( V_163 -> V_164 , V_165 ) ;
strcpy ( V_163 -> V_166 , V_167 ) ;
strcpy ( V_163 -> V_168 , L_2 ) ;
}
static struct V_169 * F_74 ( struct V_3 * V_4 , struct V_169 * V_46 )
{
if ( F_8 ( V_4 ) -> V_45 ) {
struct V_45 * V_80 ;
T_3 V_170 = 0 , V_50 = 0 ;
int V_157 ;
F_75 (i) {
T_4 V_171 , V_172 , V_173 , V_174 , V_175 ;
unsigned int V_176 ;
V_80 = F_76 ( F_8 ( V_4 ) -> V_45 , V_157 ) ;
do {
V_176 = F_77 ( & V_80 -> V_47 ) ;
V_171 = V_80 -> V_177 ;
V_172 = V_80 -> V_178 ;
V_173 = V_80 -> V_179 ;
V_174 = V_80 -> V_48 ;
V_175 = V_80 -> V_49 ;
} while ( F_78 ( & V_80 -> V_47 , V_176 ) );
V_46 -> V_177 += V_171 ;
V_46 -> V_178 += V_172 ;
V_46 -> V_180 += V_173 ;
V_46 -> V_48 += V_174 ;
V_46 -> V_49 += V_175 ;
V_170 += V_80 -> V_170 ;
V_50 += V_80 -> V_50 ;
}
V_46 -> V_170 = V_170 ;
V_46 -> V_50 = V_50 ;
}
return V_46 ;
}
static void F_79 ( struct V_3 * V_4 )
{
return;
}
static int F_80 ( struct V_3 * V_4 , struct V_181 * V_182 )
{
struct F_8 * V_163 = F_8 ( V_4 ) ;
struct V_3 * V_38 = V_163 -> V_38 ;
struct V_183 * V_183 ;
int V_71 = 0 ;
V_183 = F_81 ( sizeof( * V_183 ) , V_63 ) ;
V_71 = - V_155 ;
if ( ! V_183 )
goto V_74;
V_183 -> V_4 = V_38 ;
F_82 ( V_183 -> V_184 , V_38 -> V_11 , V_93 ) ;
V_71 = F_83 ( V_183 ) ;
if ( V_71 ) {
F_69 ( V_183 ) ;
goto V_74;
}
V_163 -> V_183 = V_183 ;
V_74:
return V_71 ;
}
static void F_84 ( struct V_3 * V_4 )
{
struct F_8 * V_163 = F_8 ( V_4 ) ;
struct V_183 * V_183 = V_163 -> V_183 ;
if ( ! V_183 )
return;
V_163 -> V_183 = NULL ;
F_85 () ;
F_86 ( V_183 ) ;
F_69 ( V_183 ) ;
}
void F_87 ( struct V_3 * V_4 )
{
F_88 ( V_4 ) ;
V_4 -> V_185 |= V_186 ;
V_4 -> V_185 &= ~ ( V_187 | V_188 ) ;
V_4 -> V_189 = 0 ;
V_4 -> V_41 = & V_154 ;
V_4 -> V_190 = V_191 ;
V_4 -> V_192 = & V_193 ;
memset ( V_4 -> V_145 , 0 , V_14 ) ;
}
