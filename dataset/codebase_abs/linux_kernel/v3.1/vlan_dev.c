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
F_14 ( V_2 , F_8 ( V_4 ) -> V_38 ) ;
V_23 = V_2 -> V_23 ;
V_39 = F_15 ( V_2 ) ;
if ( F_16 ( V_39 == V_41 || V_39 == V_42 ) ) {
struct V_43 * V_44 ;
V_44 = F_17 ( F_8 ( V_4 ) -> V_43 ) ;
F_18 ( & V_44 -> V_45 ) ;
V_44 -> V_46 ++ ;
V_44 -> V_47 += V_23 ;
F_19 ( & V_44 -> V_45 ) ;
} else {
F_20 ( F_8 ( V_4 ) -> V_43 -> V_48 ) ;
}
return V_39 ;
}
static int F_21 ( struct V_3 * V_4 , int V_49 )
{
if ( F_8 ( V_4 ) -> V_38 -> V_50 < V_49 )
return - V_51 ;
V_4 -> V_50 = V_49 ;
return 0 ;
}
void F_22 ( const struct V_3 * V_4 ,
T_3 V_52 , T_1 V_53 )
{
struct F_8 * V_54 = F_8 ( V_4 ) ;
if ( V_54 -> V_55 [ V_53 & 0x7 ] && ! V_52 )
V_54 -> V_56 -- ;
else if ( ! V_54 -> V_55 [ V_53 & 0x7 ] && V_52 )
V_54 -> V_56 ++ ;
V_54 -> V_55 [ V_53 & 0x7 ] = V_52 ;
}
int F_23 ( const struct V_3 * V_4 ,
T_3 V_52 , T_1 V_53 )
{
struct F_8 * V_54 = F_8 ( V_4 ) ;
struct V_15 * V_16 = NULL ;
struct V_15 * V_57 ;
T_3 V_19 = ( V_53 << V_58 ) & V_59 ;
V_16 = V_54 -> V_17 [ V_52 & 0xF ] ;
while ( V_16 ) {
if ( V_16 -> V_18 == V_52 ) {
if ( V_16 -> V_19 && ! V_19 )
V_54 -> V_60 -- ;
else if ( ! V_16 -> V_19 && V_19 )
V_54 -> V_60 ++ ;
V_16 -> V_19 = V_19 ;
return 0 ;
}
V_16 = V_16 -> V_20 ;
}
V_16 = V_54 -> V_17 [ V_52 & 0xF ] ;
V_57 = F_24 ( sizeof( struct V_15 ) , V_61 ) ;
if ( ! V_57 )
return - V_62 ;
V_57 -> V_20 = V_16 ;
V_57 -> V_18 = V_52 ;
V_57 -> V_19 = V_19 ;
V_54 -> V_17 [ V_52 & 0xF ] = V_57 ;
if ( V_19 )
V_54 -> V_60 ++ ;
return 0 ;
}
int F_25 ( const struct V_3 * V_4 , T_3 V_29 , T_3 V_63 )
{
struct F_8 * V_54 = F_8 ( V_4 ) ;
T_3 V_64 = V_54 -> V_29 ;
if ( V_63 & ~ ( V_30 | V_65 |
V_66 ) )
return - V_67 ;
V_54 -> V_29 = ( V_64 & ~ V_63 ) | ( V_29 & V_63 ) ;
if ( F_26 ( V_4 ) && ( V_54 -> V_29 ^ V_64 ) & V_65 ) {
if ( V_54 -> V_29 & V_65 )
F_27 ( V_4 ) ;
else
F_28 ( V_4 ) ;
}
return 0 ;
}
void F_29 ( const struct V_3 * V_4 , char * V_68 )
{
strncpy ( V_68 , F_8 ( V_4 ) -> V_38 -> V_11 , 23 ) ;
}
static int F_30 ( struct V_3 * V_4 )
{
struct F_8 * V_54 = F_8 ( V_4 ) ;
struct V_3 * V_38 = V_54 -> V_38 ;
int V_69 ;
if ( ! ( V_38 -> V_29 & V_70 ) &&
! ( V_54 -> V_29 & V_66 ) )
return - V_71 ;
if ( F_31 ( V_4 -> V_13 , V_38 -> V_13 ) ) {
V_69 = F_32 ( V_38 , V_4 -> V_13 ) ;
if ( V_69 < 0 )
goto V_72;
}
if ( V_4 -> V_29 & V_73 ) {
V_69 = F_33 ( V_38 , 1 ) ;
if ( V_69 < 0 )
goto V_74;
}
if ( V_4 -> V_29 & V_75 ) {
V_69 = F_34 ( V_38 , 1 ) ;
if ( V_69 < 0 )
goto V_76;
}
memcpy ( V_54 -> V_77 , V_38 -> V_13 , V_14 ) ;
if ( V_54 -> V_29 & V_65 )
F_27 ( V_4 ) ;
if ( F_35 ( V_38 ) )
F_36 ( V_4 ) ;
return 0 ;
V_76:
if ( V_4 -> V_29 & V_73 )
F_33 ( V_38 , - 1 ) ;
V_74:
if ( F_31 ( V_4 -> V_13 , V_38 -> V_13 ) )
F_37 ( V_38 , V_4 -> V_13 ) ;
V_72:
F_38 ( V_4 ) ;
return V_69 ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct F_8 * V_54 = F_8 ( V_4 ) ;
struct V_3 * V_38 = V_54 -> V_38 ;
F_40 ( V_38 , V_4 ) ;
F_41 ( V_38 , V_4 ) ;
if ( V_4 -> V_29 & V_73 )
F_33 ( V_38 , - 1 ) ;
if ( V_4 -> V_29 & V_75 )
F_34 ( V_38 , - 1 ) ;
if ( F_31 ( V_4 -> V_13 , V_38 -> V_13 ) )
F_37 ( V_38 , V_4 -> V_13 ) ;
F_38 ( V_4 ) ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , void * V_78 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
struct V_79 * V_80 = V_78 ;
int V_69 ;
if ( ! F_43 ( V_80 -> V_81 ) )
return - V_82 ;
if ( ! ( V_4 -> V_29 & V_70 ) )
goto V_72;
if ( F_31 ( V_80 -> V_81 , V_38 -> V_13 ) ) {
V_69 = F_32 ( V_38 , V_80 -> V_81 ) ;
if ( V_69 < 0 )
return V_69 ;
}
if ( F_31 ( V_4 -> V_13 , V_38 -> V_13 ) )
F_37 ( V_38 , V_4 -> V_13 ) ;
V_72:
memcpy ( V_4 -> V_13 , V_80 -> V_81 , V_14 ) ;
return 0 ;
}
static int F_44 ( struct V_3 * V_4 , struct V_83 * V_84 , int V_85 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_86 * V_87 = V_38 -> V_88 ;
struct V_83 V_89 ;
int V_69 = - V_90 ;
strncpy ( V_89 . V_91 , V_38 -> V_11 , V_92 ) ;
V_89 . V_93 = V_84 -> V_93 ;
switch ( V_85 ) {
case V_94 :
case V_95 :
case V_96 :
if ( F_45 ( V_38 ) && V_87 -> V_97 )
V_69 = V_87 -> V_97 ( V_38 , & V_89 , V_85 ) ;
break;
}
if ( ! V_69 )
V_84 -> V_93 = V_89 . V_93 ;
return V_69 ;
}
static int F_46 ( struct V_3 * V_4 , struct V_98 * V_99 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_86 * V_87 = V_38 -> V_88 ;
int V_69 = 0 ;
if ( F_45 ( V_38 ) && V_87 -> V_100 )
V_69 = V_87 -> V_100 ( V_38 , V_99 ) ;
return V_69 ;
}
static int F_47 ( struct V_3 * V_4 , T_1 V_101 ,
struct V_102 * V_103 , unsigned int V_104 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_86 * V_87 = V_38 -> V_88 ;
int V_28 = 0 ;
if ( V_87 -> V_105 )
V_28 = V_87 -> V_105 ( V_38 , V_101 , V_103 , V_104 ) ;
return V_28 ;
}
static int F_48 ( struct V_3 * V_4 , T_1 V_101 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_86 * V_87 = V_38 -> V_88 ;
int V_23 = 0 ;
if ( V_87 -> V_106 )
V_23 = V_87 -> V_106 ( V_38 , V_101 ) ;
return V_23 ;
}
static int F_49 ( struct V_3 * V_4 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_86 * V_87 = V_38 -> V_88 ;
int V_28 = - V_67 ;
if ( V_87 -> V_107 )
V_28 = V_87 -> V_107 ( V_38 ) ;
return V_28 ;
}
static int F_50 ( struct V_3 * V_4 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_86 * V_87 = V_38 -> V_88 ;
int V_28 = - V_67 ;
if ( V_87 -> V_108 )
V_28 = V_87 -> V_108 ( V_38 ) ;
return V_28 ;
}
static int F_51 ( struct V_3 * V_4 , T_4 * V_109 , int type )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_86 * V_87 = V_38 -> V_88 ;
int V_28 = - V_67 ;
if ( V_87 -> V_110 )
V_28 = V_87 -> V_110 ( V_38 , V_109 , type ) ;
return V_28 ;
}
static int F_52 ( struct V_3 * V_4 , T_1 V_101 ,
struct V_102 * V_103 , unsigned int V_104 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_86 * V_87 = V_38 -> V_88 ;
int V_28 = 0 ;
if ( V_87 -> V_111 )
V_28 = V_87 -> V_111 ( V_38 , V_101 , V_103 , V_104 ) ;
return V_28 ;
}
static void F_53 ( struct V_3 * V_4 , int V_112 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
if ( V_112 & V_73 )
F_33 ( V_38 , V_4 -> V_29 & V_73 ? 1 : - 1 ) ;
if ( V_112 & V_75 )
F_34 ( V_38 , V_4 -> V_29 & V_75 ? 1 : - 1 ) ;
}
static void F_54 ( struct V_3 * V_113 )
{
F_55 ( F_8 ( V_113 ) -> V_38 , V_113 ) ;
F_56 ( F_8 ( V_113 ) -> V_38 , V_113 ) ;
}
static void F_57 ( struct V_3 * V_4 ,
struct V_114 * V_115 ,
void * V_116 )
{
F_58 ( & V_115 -> V_117 ,
& V_118 ,
* ( int * ) V_116 ) ;
}
static void F_59 ( struct V_3 * V_4 , int V_119 )
{
F_58 ( & V_4 -> V_120 ,
& V_121 ,
V_119 ) ;
F_60 ( V_4 , F_57 , & V_119 ) ;
}
static int F_61 ( struct V_3 * V_4 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
int V_119 = 0 ;
F_38 ( V_4 ) ;
V_4 -> V_29 = V_38 -> V_29 & ~ ( V_70 | V_75 | V_73 |
V_122 | V_123 ) ;
V_4 -> V_124 = V_38 -> V_125 ;
V_4 -> V_126 = ( V_38 -> V_126 & ( ( 1 << V_127 ) |
( 1 << V_128 ) ) ) |
( 1 << V_129 ) ;
V_4 -> V_130 = V_131 | V_132 |
V_133 | V_134 |
V_135 | V_136 |
V_137 ;
V_4 -> V_138 |= V_38 -> V_139 | V_140 ;
V_4 -> V_141 = V_38 -> V_141 ;
V_4 -> V_142 = V_38 -> V_142 ;
if ( F_62 ( V_4 -> V_13 ) )
memcpy ( V_4 -> V_13 , V_38 -> V_13 , V_4 -> V_143 ) ;
if ( F_62 ( V_4 -> V_144 ) )
memcpy ( V_4 -> V_144 , V_38 -> V_144 , V_4 -> V_143 ) ;
#if F_63 ( V_145 ) || F_63 ( V_146 )
V_4 -> V_147 = V_38 -> V_147 ;
#endif
V_4 -> V_148 = V_38 -> V_148 ;
if ( V_38 -> V_138 & V_149 ) {
V_4 -> V_150 = V_38 -> V_150 ;
V_4 -> V_151 = V_38 -> V_151 ;
} else {
V_4 -> V_150 = & V_152 ;
V_4 -> V_151 = V_38 -> V_151 + V_31 ;
}
V_4 -> V_88 = & V_153 ;
if ( F_64 ( V_38 ) )
V_119 = 1 ;
F_59 ( V_4 , V_119 ) ;
F_8 ( V_4 ) -> V_43 = F_65 ( struct V_43 ) ;
if ( ! F_8 ( V_4 ) -> V_43 )
return - V_154 ;
return 0 ;
}
static void F_66 ( struct V_3 * V_4 )
{
struct V_15 * V_155 ;
struct F_8 * V_54 = F_8 ( V_4 ) ;
int V_156 ;
F_67 ( V_54 -> V_43 ) ;
V_54 -> V_43 = NULL ;
for ( V_156 = 0 ; V_156 < F_68 ( V_54 -> V_17 ) ; V_156 ++ ) {
while ( ( V_155 = V_54 -> V_17 [ V_156 ] ) != NULL ) {
V_54 -> V_17 [ V_156 ] = V_155 -> V_20 ;
F_69 ( V_155 ) ;
}
}
}
static T_3 F_70 ( struct V_3 * V_4 , T_3 V_138 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
T_3 V_157 = V_138 ;
V_138 &= V_38 -> V_138 ;
V_138 &= V_38 -> V_139 ;
V_138 |= V_157 & V_158 ;
if ( F_71 ( V_38 ) )
V_138 |= V_159 ;
V_138 |= V_140 ;
return V_138 ;
}
static int F_72 ( struct V_3 * V_4 ,
struct V_160 * V_85 )
{
const struct F_8 * V_54 = F_8 ( V_4 ) ;
return F_73 ( V_54 -> V_38 , V_85 ) ;
}
static void F_74 ( struct V_3 * V_4 ,
struct V_161 * V_162 )
{
strcpy ( V_162 -> V_163 , V_164 ) ;
strcpy ( V_162 -> V_165 , V_166 ) ;
strcpy ( V_162 -> V_167 , L_2 ) ;
}
static struct V_168 * F_75 ( struct V_3 * V_4 , struct V_168 * V_44 )
{
if ( F_8 ( V_4 ) -> V_43 ) {
struct V_43 * V_78 ;
T_3 V_169 = 0 , V_48 = 0 ;
int V_156 ;
F_76 (i) {
T_4 V_170 , V_171 , V_172 , V_173 , V_174 ;
unsigned int V_175 ;
V_78 = F_77 ( F_8 ( V_4 ) -> V_43 , V_156 ) ;
do {
V_175 = F_78 ( & V_78 -> V_45 ) ;
V_170 = V_78 -> V_176 ;
V_171 = V_78 -> V_177 ;
V_172 = V_78 -> V_178 ;
V_173 = V_78 -> V_46 ;
V_174 = V_78 -> V_47 ;
} while ( F_79 ( & V_78 -> V_45 , V_175 ) );
V_44 -> V_176 += V_170 ;
V_44 -> V_177 += V_171 ;
V_44 -> V_179 += V_172 ;
V_44 -> V_46 += V_173 ;
V_44 -> V_47 += V_174 ;
V_169 += V_78 -> V_169 ;
V_48 += V_78 -> V_48 ;
}
V_44 -> V_169 = V_169 ;
V_44 -> V_48 = V_48 ;
}
return V_44 ;
}
void F_80 ( struct V_3 * V_4 )
{
F_81 ( V_4 ) ;
V_4 -> V_180 |= V_181 ;
V_4 -> V_180 &= ~ ( V_182 | V_183 ) ;
V_4 -> V_184 = 0 ;
V_4 -> V_88 = & V_153 ;
V_4 -> V_185 = V_186 ;
V_4 -> V_187 = & V_188 ;
memset ( V_4 -> V_144 , 0 , V_14 ) ;
}
