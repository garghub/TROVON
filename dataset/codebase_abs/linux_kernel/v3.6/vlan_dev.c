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
static inline T_2 F_12 ( struct F_8 * V_39 , struct V_1 * V_2 )
{
#ifdef F_13
if ( V_39 -> V_40 )
F_14 ( V_39 -> V_40 , V_2 ) ;
#else
F_15 () ;
#endif
return V_41 ;
}
static T_2 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct F_8 * V_39 = F_8 ( V_4 ) ;
struct V_5 * V_6 = (struct V_5 * ) ( V_2 -> V_7 ) ;
unsigned int V_23 ;
int V_42 ;
if ( V_6 -> V_43 != F_3 ( V_37 ) ||
V_39 -> V_29 & V_30 ) {
T_1 V_27 ;
V_27 = V_39 -> V_32 ;
V_27 |= F_7 ( V_4 , V_2 ) ;
V_2 = F_17 ( V_2 , V_27 ) ;
}
V_2 -> V_4 = V_39 -> V_38 ;
V_23 = V_2 -> V_23 ;
if ( F_18 ( F_19 ( V_4 ) ) )
return F_12 ( V_39 , V_2 ) ;
V_42 = F_20 ( V_2 ) ;
if ( F_21 ( V_42 == V_44 || V_42 == V_45 ) ) {
struct V_46 * V_47 ;
V_47 = F_22 ( V_39 -> V_46 ) ;
F_23 ( & V_47 -> V_48 ) ;
V_47 -> V_49 ++ ;
V_47 -> V_50 += V_23 ;
F_24 ( & V_47 -> V_48 ) ;
} else {
F_25 ( V_39 -> V_46 -> V_51 ) ;
}
return V_42 ;
}
static int F_26 ( struct V_3 * V_4 , int V_52 )
{
if ( F_8 ( V_4 ) -> V_38 -> V_53 < V_52 )
return - V_54 ;
V_4 -> V_53 = V_52 ;
return 0 ;
}
void F_27 ( const struct V_3 * V_4 ,
T_3 V_55 , T_1 V_56 )
{
struct F_8 * V_39 = F_8 ( V_4 ) ;
if ( V_39 -> V_57 [ V_56 & 0x7 ] && ! V_55 )
V_39 -> V_58 -- ;
else if ( ! V_39 -> V_57 [ V_56 & 0x7 ] && V_55 )
V_39 -> V_58 ++ ;
V_39 -> V_57 [ V_56 & 0x7 ] = V_55 ;
}
int F_28 ( const struct V_3 * V_4 ,
T_3 V_55 , T_1 V_56 )
{
struct F_8 * V_39 = F_8 ( V_4 ) ;
struct V_15 * V_16 = NULL ;
struct V_15 * V_59 ;
T_3 V_19 = ( V_56 << V_60 ) & V_61 ;
V_16 = V_39 -> V_17 [ V_55 & 0xF ] ;
while ( V_16 ) {
if ( V_16 -> V_18 == V_55 ) {
if ( V_16 -> V_19 && ! V_19 )
V_39 -> V_62 -- ;
else if ( ! V_16 -> V_19 && V_19 )
V_39 -> V_62 ++ ;
V_16 -> V_19 = V_19 ;
return 0 ;
}
V_16 = V_16 -> V_20 ;
}
V_16 = V_39 -> V_17 [ V_55 & 0xF ] ;
V_59 = F_29 ( sizeof( struct V_15 ) , V_63 ) ;
if ( ! V_59 )
return - V_64 ;
V_59 -> V_20 = V_16 ;
V_59 -> V_18 = V_55 ;
V_59 -> V_19 = V_19 ;
V_39 -> V_17 [ V_55 & 0xF ] = V_59 ;
if ( V_19 )
V_39 -> V_62 ++ ;
return 0 ;
}
int F_30 ( const struct V_3 * V_4 , T_3 V_29 , T_3 V_65 )
{
struct F_8 * V_39 = F_8 ( V_4 ) ;
T_3 V_66 = V_39 -> V_29 ;
if ( V_65 & ~ ( V_30 | V_67 |
V_68 ) )
return - V_69 ;
V_39 -> V_29 = ( V_66 & ~ V_65 ) | ( V_29 & V_65 ) ;
if ( F_31 ( V_4 ) && ( V_39 -> V_29 ^ V_66 ) & V_67 ) {
if ( V_39 -> V_29 & V_67 )
F_32 ( V_4 ) ;
else
F_33 ( V_4 ) ;
}
return 0 ;
}
void F_34 ( const struct V_3 * V_4 , char * V_70 )
{
strncpy ( V_70 , F_8 ( V_4 ) -> V_38 -> V_11 , 23 ) ;
}
static int F_35 ( struct V_3 * V_4 )
{
struct F_8 * V_39 = F_8 ( V_4 ) ;
struct V_3 * V_38 = V_39 -> V_38 ;
int V_71 ;
if ( ! ( V_38 -> V_29 & V_72 ) &&
! ( V_39 -> V_29 & V_68 ) )
return - V_73 ;
if ( ! F_36 ( V_4 -> V_13 , V_38 -> V_13 ) ) {
V_71 = F_37 ( V_38 , V_4 -> V_13 ) ;
if ( V_71 < 0 )
goto V_74;
}
if ( V_4 -> V_29 & V_75 ) {
V_71 = F_38 ( V_38 , 1 ) ;
if ( V_71 < 0 )
goto V_76;
}
if ( V_4 -> V_29 & V_77 ) {
V_71 = F_39 ( V_38 , 1 ) ;
if ( V_71 < 0 )
goto V_78;
}
memcpy ( V_39 -> V_79 , V_38 -> V_13 , V_14 ) ;
if ( V_39 -> V_29 & V_67 )
F_32 ( V_4 ) ;
if ( F_40 ( V_38 ) )
F_41 ( V_4 ) ;
return 0 ;
V_78:
if ( V_4 -> V_29 & V_75 )
F_38 ( V_38 , - 1 ) ;
V_76:
if ( ! F_36 ( V_4 -> V_13 , V_38 -> V_13 ) )
F_42 ( V_38 , V_4 -> V_13 ) ;
V_74:
F_43 ( V_4 ) ;
return V_71 ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct F_8 * V_39 = F_8 ( V_4 ) ;
struct V_3 * V_38 = V_39 -> V_38 ;
F_45 ( V_38 , V_4 ) ;
F_46 ( V_38 , V_4 ) ;
if ( V_4 -> V_29 & V_75 )
F_38 ( V_38 , - 1 ) ;
if ( V_4 -> V_29 & V_77 )
F_39 ( V_38 , - 1 ) ;
if ( ! F_36 ( V_4 -> V_13 , V_38 -> V_13 ) )
F_42 ( V_38 , V_4 -> V_13 ) ;
F_43 ( V_4 ) ;
return 0 ;
}
static int F_47 ( struct V_3 * V_4 , void * V_80 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
struct V_81 * V_82 = V_80 ;
int V_71 ;
if ( ! F_48 ( V_82 -> V_83 ) )
return - V_84 ;
if ( ! ( V_4 -> V_29 & V_72 ) )
goto V_74;
if ( ! F_36 ( V_82 -> V_83 , V_38 -> V_13 ) ) {
V_71 = F_37 ( V_38 , V_82 -> V_83 ) ;
if ( V_71 < 0 )
return V_71 ;
}
if ( ! F_36 ( V_4 -> V_13 , V_38 -> V_13 ) )
F_42 ( V_38 , V_4 -> V_13 ) ;
V_74:
memcpy ( V_4 -> V_13 , V_82 -> V_83 , V_14 ) ;
return 0 ;
}
static int F_49 ( struct V_3 * V_4 , struct V_85 * V_86 , int V_87 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_90 ;
struct V_85 V_91 ;
int V_71 = - V_92 ;
strncpy ( V_91 . V_93 , V_38 -> V_11 , V_94 ) ;
V_91 . V_95 = V_86 -> V_95 ;
switch ( V_87 ) {
case V_96 :
case V_97 :
case V_98 :
if ( F_50 ( V_38 ) && V_89 -> V_99 )
V_71 = V_89 -> V_99 ( V_38 , & V_91 , V_87 ) ;
break;
}
if ( ! V_71 )
V_86 -> V_95 = V_91 . V_95 ;
return V_71 ;
}
static int F_51 ( struct V_3 * V_4 , struct V_100 * V_101 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_90 ;
int V_71 = 0 ;
if ( F_50 ( V_38 ) && V_89 -> V_102 )
V_71 = V_89 -> V_102 ( V_38 , V_101 ) ;
return V_71 ;
}
static int F_52 ( struct V_3 * V_4 , T_1 V_103 ,
struct V_104 * V_105 , unsigned int V_106 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_90 ;
int V_28 = 0 ;
if ( V_89 -> V_107 )
V_28 = V_89 -> V_107 ( V_38 , V_103 , V_105 , V_106 ) ;
return V_28 ;
}
static int F_53 ( struct V_3 * V_4 , T_1 V_103 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_90 ;
int V_23 = 0 ;
if ( V_89 -> V_108 )
V_23 = V_89 -> V_108 ( V_38 , V_103 ) ;
return V_23 ;
}
static int F_54 ( struct V_3 * V_4 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_90 ;
int V_28 = - V_69 ;
if ( V_89 -> V_109 )
V_28 = V_89 -> V_109 ( V_38 ) ;
return V_28 ;
}
static int F_55 ( struct V_3 * V_4 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_90 ;
int V_28 = - V_69 ;
if ( V_89 -> V_110 )
V_28 = V_89 -> V_110 ( V_38 ) ;
return V_28 ;
}
static int F_56 ( struct V_3 * V_4 , T_4 * V_111 , int type )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_90 ;
int V_28 = - V_69 ;
if ( V_89 -> V_112 )
V_28 = V_89 -> V_112 ( V_38 , V_111 , type ) ;
return V_28 ;
}
static int F_57 ( struct V_3 * V_4 , T_1 V_103 ,
struct V_104 * V_105 , unsigned int V_106 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
const struct V_88 * V_89 = V_38 -> V_90 ;
int V_28 = 0 ;
if ( V_89 -> V_113 )
V_28 = V_89 -> V_113 ( V_38 , V_103 , V_105 , V_106 ) ;
return V_28 ;
}
static void F_58 ( struct V_3 * V_4 , int V_114 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
if ( V_4 -> V_29 & V_72 ) {
if ( V_114 & V_75 )
F_38 ( V_38 , V_4 -> V_29 & V_75 ? 1 : - 1 ) ;
if ( V_114 & V_77 )
F_39 ( V_38 , V_4 -> V_29 & V_77 ? 1 : - 1 ) ;
}
}
static void F_59 ( struct V_3 * V_115 )
{
F_60 ( F_8 ( V_115 ) -> V_38 , V_115 ) ;
F_61 ( F_8 ( V_115 ) -> V_38 , V_115 ) ;
}
static void F_62 ( struct V_3 * V_4 ,
struct V_116 * V_117 ,
void * V_118 )
{
F_63 ( & V_117 -> V_119 ,
& V_120 ,
* ( int * ) V_118 ) ;
}
static void F_64 ( struct V_3 * V_4 , int V_121 )
{
F_63 ( & V_4 -> V_122 ,
& V_123 ,
V_121 ) ;
F_65 ( V_4 , F_62 , & V_121 ) ;
}
static int F_66 ( struct V_3 * V_4 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
int V_121 = 0 ;
F_43 ( V_4 ) ;
V_4 -> V_29 = V_38 -> V_29 & ~ ( V_72 | V_77 | V_75 |
V_124 | V_125 ) ;
V_4 -> V_126 = V_38 -> V_127 ;
V_4 -> V_128 = ( V_38 -> V_128 & ( ( 1 << V_129 ) |
( 1 << V_130 ) ) ) |
( 1 << V_131 ) ;
V_4 -> V_132 = V_133 | V_134 |
V_135 | V_136 |
V_137 | V_138 |
V_139 ;
V_4 -> V_140 |= V_38 -> V_141 | V_142 ;
V_4 -> V_143 = V_38 -> V_143 ;
V_4 -> V_144 = V_38 -> V_144 ;
if ( F_67 ( V_4 -> V_13 ) )
memcpy ( V_4 -> V_13 , V_38 -> V_13 , V_4 -> V_145 ) ;
if ( F_67 ( V_4 -> V_146 ) )
memcpy ( V_4 -> V_146 , V_38 -> V_146 , V_4 -> V_145 ) ;
#if F_68 ( V_147 ) || F_68 ( V_148 )
V_4 -> V_149 = V_38 -> V_149 ;
#endif
V_4 -> V_150 = V_38 -> V_150 ;
if ( V_38 -> V_140 & V_151 ) {
V_4 -> V_152 = V_38 -> V_152 ;
V_4 -> V_153 = V_38 -> V_153 ;
} else {
V_4 -> V_152 = & V_154 ;
V_4 -> V_153 = V_38 -> V_153 + V_31 ;
}
V_4 -> V_90 = & V_155 ;
if ( F_69 ( V_38 ) )
V_121 = 1 ;
F_64 ( V_4 , V_121 ) ;
F_8 ( V_4 ) -> V_46 = F_70 ( struct V_46 ) ;
if ( ! F_8 ( V_4 ) -> V_46 )
return - V_156 ;
return 0 ;
}
static void F_71 ( struct V_3 * V_4 )
{
struct V_15 * V_157 ;
struct F_8 * V_39 = F_8 ( V_4 ) ;
int V_158 ;
F_72 ( V_39 -> V_46 ) ;
V_39 -> V_46 = NULL ;
for ( V_158 = 0 ; V_158 < F_73 ( V_39 -> V_17 ) ; V_158 ++ ) {
while ( ( V_157 = V_39 -> V_17 [ V_158 ] ) != NULL ) {
V_39 -> V_17 [ V_158 ] = V_157 -> V_20 ;
F_74 ( V_157 ) ;
}
}
}
static T_5 F_75 ( struct V_3 * V_4 ,
T_5 V_140 )
{
struct V_3 * V_38 = F_8 ( V_4 ) -> V_38 ;
T_3 V_159 = V_140 ;
V_140 &= V_38 -> V_141 ;
V_140 |= V_160 ;
V_140 &= V_38 -> V_140 ;
V_140 |= V_159 & V_161 ;
V_140 |= V_142 ;
return V_140 ;
}
static int F_76 ( struct V_3 * V_4 ,
struct V_162 * V_87 )
{
const struct F_8 * V_39 = F_8 ( V_4 ) ;
return F_77 ( V_39 -> V_38 , V_87 ) ;
}
static void F_78 ( struct V_3 * V_4 ,
struct V_163 * V_164 )
{
strcpy ( V_164 -> V_165 , V_166 ) ;
strcpy ( V_164 -> V_167 , V_168 ) ;
strcpy ( V_164 -> V_169 , L_2 ) ;
}
static struct V_170 * F_79 ( struct V_3 * V_4 , struct V_170 * V_47 )
{
if ( F_8 ( V_4 ) -> V_46 ) {
struct V_46 * V_80 ;
T_3 V_171 = 0 , V_51 = 0 ;
int V_158 ;
F_80 (i) {
T_4 V_172 , V_173 , V_174 , V_175 , V_176 ;
unsigned int V_177 ;
V_80 = F_81 ( F_8 ( V_4 ) -> V_46 , V_158 ) ;
do {
V_177 = F_82 ( & V_80 -> V_48 ) ;
V_172 = V_80 -> V_178 ;
V_173 = V_80 -> V_179 ;
V_174 = V_80 -> V_180 ;
V_175 = V_80 -> V_49 ;
V_176 = V_80 -> V_50 ;
} while ( F_83 ( & V_80 -> V_48 , V_177 ) );
V_47 -> V_178 += V_172 ;
V_47 -> V_179 += V_173 ;
V_47 -> V_181 += V_174 ;
V_47 -> V_49 += V_175 ;
V_47 -> V_50 += V_176 ;
V_171 += V_80 -> V_171 ;
V_51 += V_80 -> V_51 ;
}
V_47 -> V_171 = V_171 ;
V_47 -> V_51 = V_51 ;
}
return V_47 ;
}
static void F_84 ( struct V_3 * V_4 )
{
return;
}
static int F_85 ( struct V_3 * V_4 , struct V_182 * V_183 ,
T_6 V_184 )
{
struct F_8 * V_39 = F_8 ( V_4 ) ;
struct V_3 * V_38 = V_39 -> V_38 ;
struct V_40 * V_40 ;
int V_71 = 0 ;
V_40 = F_86 ( sizeof( * V_40 ) , V_184 ) ;
V_71 = - V_156 ;
if ( ! V_40 )
goto V_74;
V_71 = F_87 ( V_40 , V_38 , V_184 ) ;
if ( V_71 ) {
F_74 ( V_40 ) ;
goto V_74;
}
V_39 -> V_40 = V_40 ;
V_74:
return V_71 ;
}
static void F_88 ( struct V_3 * V_4 )
{
struct F_8 * V_39 = F_8 ( V_4 ) ;
struct V_40 * V_40 = V_39 -> V_40 ;
if ( ! V_40 )
return;
V_39 -> V_40 = NULL ;
F_89 ( V_40 ) ;
}
void F_90 ( struct V_3 * V_4 )
{
F_91 ( V_4 ) ;
V_4 -> V_185 |= V_186 ;
V_4 -> V_185 &= ~ ( V_187 | V_188 ) ;
V_4 -> V_189 = 0 ;
V_4 -> V_90 = & V_155 ;
V_4 -> V_190 = V_191 ;
V_4 -> V_192 = & V_193 ;
memset ( V_4 -> V_146 , 0 , V_14 ) ;
}
