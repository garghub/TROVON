static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
F_2 ( V_4 -> V_6 != V_7 ,
L_1 ,
V_2 , V_4 -> V_6 , V_2 -> V_8 , V_2 -> type , V_2 -> V_9 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
V_4 -> V_6 = V_7 ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
V_4 -> V_6 = 0 ;
}
static inline void F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 -> V_5 ;
F_6 ( V_13 -> V_6 != V_14 ) ;
}
static inline void F_7 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 -> V_5 ;
V_13 -> V_6 = V_14 ;
}
static inline void F_8 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = ( void * ) V_11 -> V_5 ;
V_13 -> V_6 = 0 ;
}
static inline void F_9 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = ( void * ) V_16 -> V_5 ;
F_6 ( V_18 -> V_6 != V_19 ) ;
}
static inline void F_10 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = ( void * ) V_16 -> V_5 ;
V_18 -> V_6 = V_19 ;
}
static inline void F_11 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = ( void * ) V_16 -> V_5 ;
V_18 -> V_6 = 0 ;
}
static T_1 F_12 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
F_13 ( V_21 ) ;
return V_24 ;
}
static T_2 F_14 ( struct V_25 * V_26 )
{
struct V_27 V_28 = F_15 ( F_16 () ) ;
T_3 V_29 = V_28 . V_30 * V_31 + V_28 . V_32 ;
return F_17 ( V_29 + V_26 -> V_33 ) ;
}
static T_3 F_18 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_35 -> V_36 ;
return F_19 ( F_14 ( V_26 ) ) ;
}
static void F_20 ( struct V_34 * V_35 ,
struct V_1 * V_2 , T_3 V_37 )
{
struct V_25 * V_26 = V_35 -> V_36 ;
struct V_27 V_28 = F_15 ( F_16 () ) ;
T_3 V_29 = V_28 . V_30 * V_31 + V_28 . V_32 ;
V_26 -> V_33 = V_37 - V_29 ;
}
static void F_21 ( struct V_34 * V_35 ,
struct V_20 * V_38 ,
struct V_39 * V_40 )
{
struct V_25 * V_26 = V_35 -> V_36 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
T_4 V_43 ;
struct V_44 * V_45 = F_22 ( V_38 ) ;
struct V_46 * V_47 = F_23 ( V_35 , V_45 ) ;
if ( ! F_24 ( V_48 ) )
return;
V_21 = F_25 ( V_38 , sizeof( * V_42 ) , 0 , V_49 ) ;
if ( V_21 == NULL )
return;
V_42 = (struct V_41 * ) F_26 ( V_21 , sizeof( * V_42 ) ) ;
V_42 -> V_42 . V_50 = V_51 ;
V_42 -> V_42 . V_52 = 0 ;
V_42 -> V_42 . V_53 = F_27 ( sizeof( * V_42 ) ) ;
V_42 -> V_42 . V_54 = F_28 ( ( 1 << V_55 ) |
( 1 << V_56 ) |
( 1 << V_57 ) |
( 1 << V_58 ) ) ;
V_42 -> V_59 = F_14 ( V_26 ) ;
V_42 -> V_60 = 0 ;
V_42 -> V_61 = V_47 -> V_62 / 5 ;
V_42 -> V_63 = F_27 ( V_40 -> V_64 ) ;
V_43 = V_65 ;
if ( V_47 -> V_43 & V_66 )
V_43 |= V_67 ;
else
V_43 |= V_68 ;
V_42 -> V_69 = F_27 ( V_43 ) ;
V_21 -> V_23 = V_48 ;
F_29 ( V_21 , 0 ) ;
V_21 -> V_70 = V_71 ;
V_21 -> V_72 = V_73 ;
V_21 -> V_74 = F_30 ( V_75 ) ;
memset ( V_21 -> V_76 , 0 , sizeof( V_21 -> V_76 ) ) ;
F_31 ( V_21 ) ;
}
static void F_32 ( struct V_39 * V_40 ,
const T_5 * V_8 )
{
struct V_20 * V_21 ;
struct V_41 * V_42 ;
T_4 V_43 ;
struct V_77 * V_78 ;
if ( ! F_24 ( V_48 ) )
return;
V_21 = F_33 ( 100 ) ;
if ( V_21 == NULL )
return;
V_42 = (struct V_41 * ) F_34 ( V_21 , sizeof( * V_42 ) ) ;
V_42 -> V_42 . V_50 = V_51 ;
V_42 -> V_42 . V_52 = 0 ;
V_42 -> V_42 . V_53 = F_27 ( sizeof( * V_42 ) ) ;
V_42 -> V_42 . V_54 = F_28 ( ( 1 << V_55 ) |
( 1 << V_58 ) ) ;
V_42 -> V_60 = 0 ;
V_42 -> V_61 = 0 ;
V_42 -> V_63 = F_27 ( V_40 -> V_64 ) ;
V_43 = V_65 ;
V_42 -> V_69 = F_27 ( V_43 ) ;
V_78 = (struct V_77 * ) F_34 ( V_21 , 10 ) ;
V_78 -> V_79 = F_27 ( V_80 |
V_81 ) ;
V_78 -> V_82 = F_27 ( 0 ) ;
memcpy ( V_78 -> V_83 , V_8 , V_84 ) ;
V_21 -> V_23 = V_48 ;
F_29 ( V_21 , 0 ) ;
V_21 -> V_70 = V_71 ;
V_21 -> V_72 = V_73 ;
V_21 -> V_74 = F_30 ( V_75 ) ;
memset ( V_21 -> V_76 , 0 , sizeof( V_21 -> V_76 ) ) ;
F_31 ( V_21 ) ;
}
static bool F_35 ( struct V_25 * V_26 ,
struct V_20 * V_21 )
{
switch ( V_26 -> V_85 ) {
case V_86 :
return true ;
case V_87 :
return false ;
case V_88 :
return true ;
case V_89 :
if ( V_26 -> V_90 &&
memcmp ( V_26 -> V_35 -> V_91 -> V_92 , V_21 -> V_26 + 4 ,
V_84 ) == 0 ) {
V_26 -> V_90 = false ;
return true ;
}
return false ;
}
return true ;
}
static void F_36 ( void * V_26 , T_5 * V_93 ,
struct V_1 * V_2 )
{
struct V_94 * V_95 = V_26 ;
if ( memcmp ( V_93 , V_95 -> V_8 , V_84 ) == 0 )
V_95 -> V_96 = true ;
}
static bool F_37 ( struct V_25 * V_26 ,
const T_5 * V_8 )
{
struct V_94 V_95 ;
if ( memcmp ( V_8 , V_26 -> V_35 -> V_91 -> V_92 , V_84 ) == 0 )
return true ;
V_95 . V_96 = false ;
V_95 . V_8 = V_8 ;
F_38 ( V_26 -> V_35 ,
V_97 ,
F_36 ,
& V_95 ) ;
return V_95 . V_96 ;
}
static void F_39 ( struct V_34 * V_35 ,
struct V_20 * V_98 ,
int V_99 )
{
struct V_20 * V_21 ;
struct V_25 * V_26 = V_35 -> V_36 ;
struct V_77 * V_42 = (struct V_77 * ) V_98 -> V_26 ;
struct V_44 * V_45 = F_22 ( V_98 ) ;
void * V_100 ;
unsigned int V_101 = 0 ;
int V_102 ;
struct V_103 V_104 [ V_105 ] ;
if ( V_26 -> V_85 != V_86 )
V_42 -> V_79 |= F_27 ( V_106 ) ;
if ( F_40 ( & V_26 -> V_107 ) >= V_108 ) {
while ( F_40 ( & V_26 -> V_107 ) >= V_109 )
F_41 ( & V_26 -> V_107 ) ;
}
V_21 = F_42 ( V_110 , V_49 ) ;
if ( V_21 == NULL )
goto V_111;
V_100 = F_43 ( V_21 , 0 , 0 , & V_112 , 0 ,
V_113 ) ;
if ( V_100 == NULL ) {
F_44 ( V_114 L_2 ) ;
goto V_111;
}
if ( F_45 ( V_21 , V_115 ,
sizeof( struct V_116 ) , V_26 -> V_117 [ 1 ] . V_8 ) )
goto V_111;
if ( F_45 ( V_21 , V_118 , V_98 -> V_119 , V_98 -> V_26 ) )
goto V_111;
if ( V_45 -> V_43 & V_120 )
V_101 |= V_121 ;
if ( V_45 -> V_43 & V_122 )
V_101 |= V_123 ;
if ( F_46 ( V_21 , V_124 , V_101 ) )
goto V_111;
for ( V_102 = 0 ; V_102 < V_105 ; V_102 ++ ) {
V_104 [ V_102 ] . V_125 = V_45 -> V_126 . V_127 [ V_102 ] . V_125 ;
V_104 [ V_102 ] . V_128 = V_45 -> V_126 . V_127 [ V_102 ] . V_128 ;
}
if ( F_45 ( V_21 , V_129 ,
sizeof( struct V_103 ) * V_105 ,
V_104 ) )
goto V_111;
if ( F_47 ( V_21 , V_130 , ( unsigned long ) V_98 ) )
goto V_111;
F_48 ( V_21 , V_100 ) ;
F_49 ( & V_131 , V_21 , V_99 ) ;
F_50 ( & V_26 -> V_107 , V_98 ) ;
return;
V_111:
F_44 ( V_114 L_3 , V_132 ) ;
}
static bool F_51 ( struct V_39 * V_133 ,
struct V_39 * V_134 )
{
if ( ! V_133 || ! V_134 )
return false ;
return V_133 -> V_64 == V_134 -> V_64 ;
}
static void F_52 ( void * V_135 , T_5 * V_8 ,
struct V_1 * V_2 )
{
struct V_136 * V_26 = V_135 ;
if ( ! V_2 -> V_137 )
return;
if ( ! F_51 ( V_26 -> V_138 ,
F_53 ( V_2 -> V_137 ) -> V_139 . V_40 ) )
return;
V_26 -> V_140 = true ;
}
static bool F_54 ( struct V_34 * V_35 ,
struct V_20 * V_21 ,
struct V_39 * V_40 )
{
struct V_25 * V_26 = V_35 -> V_36 , * V_141 ;
bool V_142 = false ;
struct V_77 * V_42 = (struct V_77 * ) V_21 -> V_26 ;
struct V_44 * V_45 = F_22 ( V_21 ) ;
struct V_143 V_144 ;
struct V_46 * V_47 = F_23 ( V_35 , V_45 ) ;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_144 . V_145 |= V_146 ;
V_144 . V_147 = V_40 -> V_64 ;
V_144 . V_148 = V_40 -> V_148 ;
V_144 . V_149 = V_45 -> V_150 . V_127 [ 0 ] . V_125 ;
if ( V_45 -> V_150 . V_127 [ 0 ] . V_43 & V_151 )
V_144 . V_145 |= V_152 ;
if ( V_45 -> V_150 . V_127 [ 0 ] . V_43 & V_153 )
V_144 . V_145 |= V_154 ;
if ( V_45 -> V_150 . V_127 [ 0 ] . V_43 & V_155 )
V_144 . V_145 |= V_156 ;
V_144 . signal = V_26 -> V_157 - 50 ;
if ( V_26 -> V_85 != V_86 )
V_42 -> V_79 |= F_27 ( V_106 ) ;
F_55 ( V_21 ) ;
F_56 ( V_21 ) ;
V_21 -> V_158 = 0 ;
F_57 ( V_21 ) ;
F_58 ( V_21 ) ;
F_59 ( & V_159 ) ;
F_60 (data2, &hwsim_radios, list) {
struct V_20 * V_160 ;
struct V_161 * V_162 ;
struct V_136 V_136 = {
. V_140 = false ,
. V_138 = V_40 ,
} ;
if ( V_26 == V_141 )
continue;
if ( ! V_141 -> V_163 || ( V_141 -> V_164 && ! V_141 -> V_165 ) ||
! F_35 ( V_141 , V_21 ) )
continue;
if ( ! ( V_26 -> V_166 & V_141 -> V_166 ) )
continue;
if ( ! F_51 ( V_40 , V_141 -> V_165 ) &&
! F_51 ( V_40 , V_141 -> V_138 ) ) {
F_38 (
V_141 -> V_35 , V_97 ,
F_52 , & V_136 ) ;
if ( ! V_136 . V_140 )
continue;
}
V_160 = F_25 ( V_21 , 64 , 0 , V_49 ) ;
if ( V_160 == NULL )
continue;
if ( F_37 ( V_141 , V_42 -> V_83 ) )
V_142 = true ;
V_144 . V_167 =
F_19 ( F_14 ( V_141 ) ) ;
V_162 = (struct V_161 * ) V_160 -> V_26 ;
if ( F_61 ( V_162 -> V_79 ) ||
F_62 ( V_162 -> V_79 ) )
V_162 -> V_168 . V_169 . V_170 = F_17 (
V_144 . V_167 +
( V_26 -> V_33 - V_141 -> V_33 ) +
24 * 8 * 10 / V_47 -> V_62 ) ;
#if 0
rx_status.vendor_radiotap_oui[0] = 0x00;
rx_status.vendor_radiotap_oui[1] = 0x00;
rx_status.vendor_radiotap_oui[2] = 0x00;
rx_status.vendor_radiotap_subns = 127;
rx_status.vendor_radiotap_bitmap = BIT(0);
rx_status.vendor_radiotap_len = 8;
rx_status.vendor_radiotap_align = 8;
memcpy(skb_push(nskb, 8), "ABCDEFGH", 8);
#endif
memcpy ( F_63 ( V_160 ) , & V_144 , sizeof( V_144 ) ) ;
F_64 ( V_141 -> V_35 , V_160 ) ;
}
F_65 ( & V_159 ) ;
return V_142 ;
}
static void F_66 ( struct V_34 * V_35 ,
struct V_171 * V_150 ,
struct V_20 * V_21 )
{
struct V_25 * V_26 = V_35 -> V_36 ;
struct V_44 * V_172 = F_22 ( V_21 ) ;
struct V_15 * V_137 ;
struct V_39 * V_138 ;
bool V_142 ;
T_6 V_173 ;
if ( F_6 ( V_21 -> V_119 < 10 ) ) {
F_13 ( V_21 ) ;
return;
}
if ( V_174 == 1 ) {
V_138 = V_26 -> V_138 ;
} else if ( V_172 -> V_175 == 4 ) {
V_138 = V_26 -> V_165 ;
} else {
V_137 = F_53 ( V_172 -> V_150 . V_2 -> V_137 ) ;
if ( V_137 )
V_138 = V_137 -> V_139 . V_40 ;
else
V_138 = NULL ;
}
if ( F_2 ( ! V_138 , L_4 , V_172 -> V_175 ) ) {
F_13 ( V_21 ) ;
return;
}
if ( V_26 -> V_164 && ! V_26 -> V_165 ) {
F_67 ( V_35 -> V_91 , L_5 ) ;
F_13 ( V_21 ) ;
return;
}
if ( V_172 -> V_150 . V_2 )
F_1 ( V_172 -> V_150 . V_2 ) ;
if ( V_150 -> V_11 )
F_5 ( V_150 -> V_11 ) ;
V_172 -> V_176 [ 0 ] = V_138 ;
F_21 ( V_35 , V_21 , V_138 ) ;
V_173 = F_68 ( V_177 ) ;
if ( V_173 )
return F_39 ( V_35 , V_21 , V_173 ) ;
V_142 = F_54 ( V_35 , V_21 , V_138 ) ;
if ( V_142 && V_21 -> V_119 >= 16 ) {
struct V_77 * V_42 = (struct V_77 * ) V_21 -> V_26 ;
F_32 ( V_138 , V_42 -> V_178 ) ;
}
F_69 ( V_172 ) ;
V_172 -> V_150 . V_127 [ 0 ] . V_128 = 1 ;
V_172 -> V_150 . V_127 [ 1 ] . V_125 = - 1 ;
if ( ! ( V_172 -> V_43 & V_122 ) && V_142 )
V_172 -> V_43 |= V_179 ;
F_70 ( V_35 , V_21 ) ;
}
static int F_71 ( struct V_34 * V_35 )
{
struct V_25 * V_26 = V_35 -> V_36 ;
F_67 ( V_35 -> V_91 , L_6 , V_132 ) ;
V_26 -> V_163 = true ;
return 0 ;
}
static void F_72 ( struct V_34 * V_35 )
{
struct V_25 * V_26 = V_35 -> V_36 ;
V_26 -> V_163 = false ;
F_73 ( & V_26 -> V_180 ) ;
F_67 ( V_35 -> V_91 , L_6 , V_132 ) ;
}
static int F_74 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
F_67 ( V_35 -> V_91 , L_7 ,
V_132 , F_75 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_181 = 0 ;
V_2 -> V_175 [ V_182 ] = 0 ;
V_2 -> V_175 [ V_183 ] = 1 ;
V_2 -> V_175 [ V_184 ] = 2 ;
V_2 -> V_175 [ V_185 ] = 3 ;
return 0 ;
}
static int F_76 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
enum V_186 V_187 ,
bool V_188 )
{
V_187 = F_77 ( V_187 , V_188 ) ;
F_67 ( V_35 -> V_91 ,
L_8 ,
V_132 , F_75 ( V_2 ) ,
V_187 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_78 (
struct V_34 * V_35 , struct V_1 * V_2 )
{
F_67 ( V_35 -> V_91 , L_7 ,
V_132 , F_75 ( V_2 ) ,
V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_79 ( struct V_34 * V_35 ,
struct V_20 * V_21 ,
struct V_39 * V_40 )
{
T_6 V_189 = F_68 ( V_177 ) ;
F_21 ( V_35 , V_21 , V_40 ) ;
if ( V_189 )
return F_39 ( V_35 , V_21 , V_189 ) ;
F_54 ( V_35 , V_21 , V_40 ) ;
F_13 ( V_21 ) ;
}
static void F_80 ( void * V_190 , T_5 * V_93 ,
struct V_1 * V_2 )
{
struct V_34 * V_35 = V_190 ;
struct V_20 * V_21 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_191 &&
V_2 -> type != V_192 &&
V_2 -> type != V_193 )
return;
V_21 = F_81 ( V_35 , V_2 ) ;
if ( V_21 == NULL )
return;
F_79 ( V_35 , V_21 ,
F_53 ( V_2 -> V_137 ) -> V_139 . V_40 ) ;
}
static void F_82 ( unsigned long V_190 )
{
struct V_34 * V_35 = (struct V_34 * ) V_190 ;
struct V_25 * V_26 = V_35 -> V_36 ;
if ( ! V_26 -> V_163 )
return;
F_38 (
V_35 , V_97 ,
F_80 , V_35 ) ;
V_26 -> V_180 . V_194 = V_195 + V_26 -> V_196 ;
F_83 ( & V_26 -> V_180 ) ;
}
static int F_84 ( struct V_34 * V_35 , T_6 V_197 )
{
struct V_25 * V_26 = V_35 -> V_36 ;
struct V_198 * V_199 = & V_35 -> V_199 ;
static const char * V_200 [ V_201 ] = {
[ V_202 ] = L_9 ,
[ V_203 ] = L_10 ,
[ V_204 ] = L_11 ,
[ V_205 ] = L_12 ,
} ;
F_67 ( V_35 -> V_91 ,
L_13 ,
V_132 ,
V_199 -> V_138 ? V_199 -> V_138 -> V_64 : 0 ,
V_206 [ V_199 -> V_207 ] ,
! ! ( V_199 -> V_43 & V_208 ) ,
! ! ( V_199 -> V_43 & V_209 ) ,
V_200 [ V_199 -> V_210 ] ) ;
V_26 -> V_164 = ! ! ( V_199 -> V_43 & V_208 ) ;
V_26 -> V_138 = V_199 -> V_138 ;
F_6 ( V_26 -> V_138 && V_174 > 1 ) ;
V_26 -> V_157 = V_199 -> V_157 ;
if ( ! V_26 -> V_163 || ! V_26 -> V_196 )
F_73 ( & V_26 -> V_180 ) ;
else
F_85 ( & V_26 -> V_180 , V_195 + V_26 -> V_196 ) ;
return 0 ;
}
static void F_86 ( struct V_34 * V_35 ,
unsigned int V_211 ,
unsigned int * V_212 , T_3 V_213 )
{
struct V_25 * V_26 = V_35 -> V_36 ;
F_67 ( V_35 -> V_91 , L_6 , V_132 ) ;
V_26 -> V_214 = 0 ;
if ( * V_212 & V_215 )
V_26 -> V_214 |= V_215 ;
if ( * V_212 & V_216 )
V_26 -> V_214 |= V_216 ;
* V_212 = V_26 -> V_214 ;
}
static void F_87 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
struct V_217 * V_45 ,
T_6 V_197 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_25 * V_26 = V_35 -> V_36 ;
F_1 ( V_2 ) ;
F_67 ( V_35 -> V_91 , L_14 , V_132 , V_197 ) ;
if ( V_197 & V_218 ) {
F_67 ( V_35 -> V_91 , L_15 ,
V_132 , V_45 -> V_219 ) ;
memcpy ( V_4 -> V_219 , V_45 -> V_219 , V_84 ) ;
}
if ( V_197 & V_220 ) {
F_67 ( V_35 -> V_91 , L_16 ,
V_45 -> V_221 , V_45 -> V_222 ) ;
V_4 -> V_221 = V_45 -> V_221 ;
V_4 -> V_222 = V_45 -> V_222 ;
}
if ( V_197 & V_223 ) {
F_67 ( V_35 -> V_91 , L_17 , V_45 -> V_196 ) ;
V_26 -> V_196 = 1024 * V_45 -> V_196 / 1000 * V_224 / 1000 ;
if ( F_6 ( ! V_26 -> V_196 ) )
V_26 -> V_196 = 1 ;
if ( V_26 -> V_163 )
F_85 ( & V_26 -> V_180 ,
V_195 + V_26 -> V_196 ) ;
}
if ( V_197 & V_225 ) {
F_67 ( V_35 -> V_91 , L_18 ,
V_45 -> V_226 ) ;
}
if ( V_197 & V_227 ) {
F_67 ( V_35 -> V_91 , L_19 ,
V_45 -> V_228 ) ;
}
if ( V_197 & V_229 ) {
F_67 ( V_35 -> V_91 , L_20 , V_45 -> V_230 ) ;
}
if ( V_197 & V_231 ) {
F_67 ( V_35 -> V_91 , L_21 ,
V_45 -> V_232 ) ;
}
if ( V_197 & V_233 ) {
F_67 ( V_35 -> V_91 , L_22 ,
( unsigned long long ) V_45 -> V_234 ) ;
}
if ( V_197 & V_235 )
F_67 ( V_35 -> V_91 , L_23 , V_45 -> V_236 ) ;
}
static int F_88 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_89 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_90 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
enum V_237 V_238 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_238 ) {
case V_239 :
case V_240 :
break;
default:
F_2 ( 1 , L_24 , V_238 ) ;
break;
}
}
static int F_91 ( struct V_34 * V_35 ,
struct V_10 * V_11 ,
bool V_241 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_92 (
struct V_34 * V_35 ,
struct V_1 * V_2 , T_4 V_242 ,
const struct V_243 * V_244 )
{
F_67 ( V_35 -> V_91 ,
L_25 ,
V_132 , V_242 ,
V_244 -> V_245 , V_244 -> V_246 ,
V_244 -> V_247 , V_244 -> V_248 ) ;
return 0 ;
}
static int F_93 (
struct V_34 * V_35 , int V_125 ,
struct V_249 * V_250 )
{
struct V_198 * V_199 = & V_35 -> V_199 ;
F_67 ( V_35 -> V_91 , L_26 , V_132 , V_125 ) ;
if ( V_125 != 0 )
return - V_251 ;
V_250 -> V_138 = V_199 -> V_138 ;
V_250 -> V_252 = V_253 ;
V_250 -> V_254 = - 92 ;
return 0 ;
}
static int F_94 ( struct V_34 * V_35 ,
void * V_26 , int V_119 )
{
struct V_25 * V_255 = V_35 -> V_36 ;
struct V_256 * V_257 [ V_258 + 1 ] ;
struct V_20 * V_21 ;
int V_259 , V_85 ;
V_259 = F_95 ( V_257 , V_258 , V_26 , V_119 ,
V_260 ) ;
if ( V_259 )
return V_259 ;
if ( ! V_257 [ V_261 ] )
return - V_262 ;
switch ( F_96 ( V_257 [ V_261 ] ) ) {
case V_263 :
if ( ! V_257 [ V_264 ] )
return - V_262 ;
V_85 = F_96 ( V_257 [ V_264 ] ) ;
return F_97 ( V_255 , V_85 ) ;
case V_265 :
V_21 = F_98 ( V_35 -> V_91 ,
F_99 ( sizeof( T_6 ) ) ) ;
if ( ! V_21 )
return - V_266 ;
if ( F_46 ( V_21 , V_264 , V_255 -> V_85 ) )
goto V_111;
return F_100 ( V_21 ) ;
case V_267 :
F_101 ( V_35 ) ;
return 0 ;
case V_268 :
F_102 ( V_35 ) ;
return 0 ;
default:
return - V_269 ;
}
V_111:
F_103 ( V_21 ) ;
return - V_270 ;
}
static int F_104 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
enum V_271 V_272 ,
struct V_10 * V_11 , T_4 V_273 , T_4 * V_274 ,
T_5 V_275 )
{
switch ( V_272 ) {
case V_276 :
F_105 ( V_2 , V_11 -> V_8 , V_273 ) ;
break;
case V_277 :
F_106 ( V_2 , V_11 -> V_8 , V_273 ) ;
break;
case V_278 :
break;
case V_279 :
case V_280 :
break;
default:
return - V_269 ;
}
return 0 ;
}
static void F_107 ( struct V_34 * V_35 , bool V_281 )
{
}
static void F_108 ( struct V_282 * V_283 )
{
struct V_25 * V_255 =
F_109 ( V_283 , struct V_25 , V_284 . V_283 ) ;
struct V_285 * V_286 = V_255 -> V_287 ;
int V_288 , V_102 ;
F_110 ( & V_255 -> V_289 ) ;
if ( V_255 -> V_290 >= V_286 -> V_291 ) {
F_67 ( V_255 -> V_35 -> V_91 , L_27 ) ;
F_111 ( V_255 -> V_35 , false ) ;
V_255 -> V_287 = NULL ;
V_255 -> V_292 = NULL ;
V_255 -> V_165 = NULL ;
F_112 ( & V_255 -> V_289 ) ;
return;
}
F_67 ( V_255 -> V_35 -> V_91 , L_28 ,
V_286 -> V_174 [ V_255 -> V_290 ] -> V_64 ) ;
V_255 -> V_165 = V_286 -> V_174 [ V_255 -> V_290 ] ;
if ( V_255 -> V_165 -> V_43 & V_293 ||
! V_286 -> V_294 ) {
V_288 = 120 ;
} else {
V_288 = 30 ;
for ( V_102 = 0 ; V_102 < V_286 -> V_294 ; V_102 ++ ) {
struct V_20 * V_295 ;
V_295 = F_113 ( V_255 -> V_35 ,
V_255 -> V_292 ,
V_286 -> V_296 [ V_102 ] . V_297 ,
V_286 -> V_296 [ V_102 ] . V_298 ,
V_286 -> V_299 ) ;
if ( ! V_295 )
continue;
if ( V_286 -> V_299 )
memcpy ( F_34 ( V_295 , V_286 -> V_299 ) , V_286 -> V_300 ,
V_286 -> V_299 ) ;
F_114 () ;
F_79 ( V_255 -> V_35 , V_295 ,
V_255 -> V_165 ) ;
F_115 () ;
}
}
F_116 ( V_255 -> V_35 , & V_255 -> V_284 ,
F_117 ( V_288 ) ) ;
V_255 -> V_290 ++ ;
F_112 ( & V_255 -> V_289 ) ;
}
static int F_118 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
struct V_285 * V_286 )
{
struct V_25 * V_255 = V_35 -> V_36 ;
F_110 ( & V_255 -> V_289 ) ;
if ( F_6 ( V_255 -> V_165 || V_255 -> V_287 ) ) {
F_112 ( & V_255 -> V_289 ) ;
return - V_301 ;
}
V_255 -> V_287 = V_286 ;
V_255 -> V_292 = V_2 ;
V_255 -> V_290 = 0 ;
F_112 ( & V_255 -> V_289 ) ;
F_67 ( V_35 -> V_91 , L_29 ) ;
F_116 ( V_255 -> V_35 , & V_255 -> V_284 , 0 ) ;
return 0 ;
}
static void F_119 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
struct V_25 * V_255 = V_35 -> V_36 ;
F_67 ( V_35 -> V_91 , L_30 ) ;
F_120 ( & V_255 -> V_284 ) ;
F_110 ( & V_255 -> V_289 ) ;
F_111 ( V_255 -> V_35 , true ) ;
V_255 -> V_165 = NULL ;
V_255 -> V_287 = NULL ;
V_255 -> V_292 = NULL ;
F_112 ( & V_255 -> V_289 ) ;
}
static void F_121 ( struct V_34 * V_35 )
{
struct V_25 * V_255 = V_35 -> V_36 ;
F_110 ( & V_255 -> V_289 ) ;
if ( V_255 -> V_302 ) {
F_44 ( V_114 L_31 ) ;
goto V_303;
}
F_44 ( V_114 L_32 ) ;
V_255 -> V_302 = true ;
V_303:
F_112 ( & V_255 -> V_289 ) ;
}
static void F_122 ( struct V_34 * V_35 )
{
struct V_25 * V_255 = V_35 -> V_36 ;
F_110 ( & V_255 -> V_289 ) ;
F_44 ( V_114 L_33 ) ;
V_255 -> V_302 = false ;
F_112 ( & V_255 -> V_289 ) ;
}
static void F_123 ( struct V_282 * V_283 )
{
struct V_25 * V_255 =
F_109 ( V_283 , struct V_25 , V_304 . V_283 ) ;
F_110 ( & V_255 -> V_289 ) ;
F_124 ( V_255 -> V_35 ) ;
V_255 -> V_165 = NULL ;
F_112 ( & V_255 -> V_289 ) ;
F_67 ( V_255 -> V_35 -> V_91 , L_34 ) ;
}
static int F_125 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
struct V_39 * V_40 ,
int V_305 )
{
struct V_25 * V_255 = V_35 -> V_36 ;
F_110 ( & V_255 -> V_289 ) ;
if ( F_6 ( V_255 -> V_165 || V_255 -> V_287 ) ) {
F_112 ( & V_255 -> V_289 ) ;
return - V_301 ;
}
V_255 -> V_165 = V_40 ;
F_112 ( & V_255 -> V_289 ) ;
F_67 ( V_35 -> V_91 , L_35 ,
V_40 -> V_64 , V_305 ) ;
F_126 ( V_35 ) ;
F_116 ( V_35 , & V_255 -> V_304 ,
F_117 ( V_305 ) ) ;
return 0 ;
}
static int F_127 ( struct V_34 * V_35 )
{
struct V_25 * V_255 = V_35 -> V_36 ;
F_120 ( & V_255 -> V_304 ) ;
F_110 ( & V_255 -> V_289 ) ;
V_255 -> V_165 = NULL ;
F_112 ( & V_255 -> V_289 ) ;
F_67 ( V_35 -> V_91 , L_36 ) ;
return 0 ;
}
static int F_128 ( struct V_34 * V_35 ,
struct V_15 * V_306 )
{
F_10 ( V_306 ) ;
F_67 ( V_35 -> V_91 ,
L_37 ,
V_306 -> V_139 . V_40 -> V_64 , V_306 -> V_139 . V_307 ,
V_306 -> V_139 . V_308 , V_306 -> V_139 . V_309 ) ;
return 0 ;
}
static void F_129 ( struct V_34 * V_35 ,
struct V_15 * V_306 )
{
F_67 ( V_35 -> V_91 ,
L_38 ,
V_306 -> V_139 . V_40 -> V_64 , V_306 -> V_139 . V_307 ,
V_306 -> V_139 . V_308 , V_306 -> V_139 . V_309 ) ;
F_9 ( V_306 ) ;
F_11 ( V_306 ) ;
}
static void F_130 ( struct V_34 * V_35 ,
struct V_15 * V_306 ,
T_6 V_197 )
{
F_9 ( V_306 ) ;
F_67 ( V_35 -> V_91 ,
L_39 ,
V_306 -> V_139 . V_40 -> V_64 , V_306 -> V_139 . V_307 ,
V_306 -> V_139 . V_308 , V_306 -> V_139 . V_309 ) ;
}
static int F_131 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
struct V_15 * V_306 )
{
F_1 ( V_2 ) ;
F_9 ( V_306 ) ;
return 0 ;
}
static void F_132 ( struct V_34 * V_35 ,
struct V_1 * V_2 ,
struct V_15 * V_306 )
{
F_1 ( V_2 ) ;
F_9 ( V_306 ) ;
}
static void F_133 ( void )
{
struct V_310 V_311 , * V_102 , * V_312 ;
struct V_25 * V_26 , * V_313 ;
F_134 ( & V_311 ) ;
F_135 ( & V_159 ) ;
F_136 (i, tmp, &hwsim_radios)
F_137 ( V_102 , & V_311 ) ;
F_138 ( & V_159 ) ;
F_139 (data, tmpdata, &tmplist, list) {
F_140 ( V_26 -> V_314 ) ;
F_140 ( V_26 -> V_315 ) ;
F_140 ( V_26 -> V_316 ) ;
F_141 ( V_26 -> V_35 ) ;
F_142 ( V_26 -> V_23 ) ;
F_143 ( V_26 -> V_35 ) ;
}
F_144 ( V_317 ) ;
}
static void F_145 ( struct V_22 * V_23 )
{
V_23 -> V_318 = & V_319 ;
V_23 -> V_320 = V_321 ;
F_146 ( V_23 ) ;
V_23 -> V_322 = 0 ;
V_23 -> type = V_323 ;
memset ( V_23 -> V_324 , 0 , V_84 ) ;
V_23 -> V_324 [ 0 ] = 0x12 ;
}
static void F_147 ( void * V_325 , T_5 * V_93 , struct V_1 * V_2 )
{
struct V_25 * V_26 = V_325 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_326 * V_327 ;
if ( ! V_4 -> V_221 )
return;
F_67 ( V_26 -> V_35 -> V_91 ,
L_40 ,
V_132 , V_4 -> V_219 , V_4 -> V_222 ) ;
V_21 = F_33 ( sizeof( * V_327 ) ) ;
if ( ! V_21 )
return;
V_327 = ( void * ) F_34 ( V_21 , sizeof( * V_327 ) ) ;
V_327 -> V_79 = F_27 ( V_80 |
V_328 |
V_106 ) ;
V_327 -> V_222 = F_27 ( 0xc000 | V_4 -> V_222 ) ;
memcpy ( V_327 -> V_219 , V_4 -> V_219 , V_84 ) ;
memcpy ( V_327 -> V_329 , V_93 , V_84 ) ;
F_148 () ;
F_79 ( V_26 -> V_35 , V_21 ,
F_53 ( V_2 -> V_137 ) -> V_139 . V_40 ) ;
F_149 () ;
}
static void F_150 ( struct V_25 * V_26 , T_5 * V_93 ,
struct V_1 * V_2 , int V_85 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_77 * V_42 ;
if ( ! V_4 -> V_221 )
return;
F_67 ( V_26 -> V_35 -> V_91 ,
L_41 ,
V_132 , V_4 -> V_219 , V_85 ) ;
V_21 = F_33 ( sizeof( * V_42 ) ) ;
if ( ! V_21 )
return;
V_42 = ( void * ) F_34 ( V_21 , sizeof( * V_42 ) - V_84 ) ;
V_42 -> V_79 = F_27 ( V_330 |
V_331 |
( V_85 ? V_106 : 0 ) ) ;
V_42 -> V_82 = F_27 ( 0 ) ;
memcpy ( V_42 -> V_83 , V_4 -> V_219 , V_84 ) ;
memcpy ( V_42 -> V_178 , V_93 , V_84 ) ;
memcpy ( V_42 -> V_332 , V_4 -> V_219 , V_84 ) ;
F_148 () ;
F_79 ( V_26 -> V_35 , V_21 ,
F_53 ( V_2 -> V_137 ) -> V_139 . V_40 ) ;
F_149 () ;
}
static void F_151 ( void * V_325 , T_5 * V_93 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_325 ;
F_150 ( V_26 , V_93 , V_2 , 1 ) ;
}
static void F_152 ( void * V_325 , T_5 * V_93 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_325 ;
F_150 ( V_26 , V_93 , V_2 , 0 ) ;
}
static int F_153 ( void * V_325 , T_3 * V_333 )
{
struct V_25 * V_26 = V_325 ;
* V_333 = V_26 -> V_85 ;
return 0 ;
}
static int F_97 ( void * V_325 , T_3 V_333 )
{
struct V_25 * V_26 = V_325 ;
enum V_334 V_335 ;
if ( V_333 != V_86 && V_333 != V_87 && V_333 != V_88 &&
V_333 != V_89 )
return - V_262 ;
V_335 = V_26 -> V_85 ;
V_26 -> V_85 = V_333 ;
if ( V_333 == V_89 ) {
F_154 ( V_26 -> V_35 ,
V_97 ,
F_147 , V_26 ) ;
V_26 -> V_90 = true ;
} else if ( V_335 == V_86 && V_333 != V_86 ) {
F_154 ( V_26 -> V_35 ,
V_97 ,
F_151 ,
V_26 ) ;
} else if ( V_335 != V_86 && V_333 == V_86 ) {
F_154 ( V_26 -> V_35 ,
V_97 ,
F_152 ,
V_26 ) ;
}
return 0 ;
}
static int F_155 ( void * V_325 , T_3 * V_333 )
{
struct V_25 * V_26 = V_325 ;
* V_333 = V_26 -> V_166 ;
return 0 ;
}
static int F_156 ( void * V_325 , T_3 V_333 )
{
struct V_25 * V_26 = V_325 ;
V_26 -> V_166 = V_333 ;
return 0 ;
}
static struct V_25 * F_157 (
struct V_116 * V_8 )
{
struct V_25 * V_26 ;
bool V_336 = false ;
F_135 ( & V_159 ) ;
F_60 (data, &hwsim_radios, list) {
if ( memcmp ( V_26 -> V_117 [ 1 ] . V_8 , V_8 ,
sizeof( struct V_116 ) ) == 0 ) {
V_336 = true ;
break;
}
}
F_138 ( & V_159 ) ;
if ( ! V_336 )
return NULL ;
return V_26 ;
}
static int F_158 ( struct V_20 * V_337 ,
struct V_338 * V_45 )
{
struct V_77 * V_42 ;
struct V_25 * V_141 ;
struct V_44 * V_172 ;
struct V_103 * V_104 ;
unsigned long V_339 ;
struct V_20 * V_21 , * V_312 ;
struct V_116 * V_340 ;
unsigned int V_101 ;
int V_102 ;
bool V_341 = false ;
if ( ! V_45 -> V_342 [ V_115 ] ||
! V_45 -> V_342 [ V_124 ] ||
! V_45 -> V_342 [ V_130 ] ||
! V_45 -> V_342 [ V_129 ] )
goto V_303;
V_340 = (struct V_116 * ) F_159 (
V_45 -> V_342 [ V_115 ] ) ;
V_101 = F_96 ( V_45 -> V_342 [ V_124 ] ) ;
V_339 = F_160 ( V_45 -> V_342 [ V_130 ] ) ;
V_141 = F_157 ( V_340 ) ;
if ( V_141 == NULL )
goto V_303;
F_161 (&data2->pending, skb, tmp) {
if ( ( unsigned long ) V_21 == V_339 ) {
F_162 ( V_21 , & V_141 -> V_107 ) ;
V_341 = true ;
break;
}
}
if ( ! V_341 )
goto V_303;
V_104 = (struct V_103 * ) F_159 (
V_45 -> V_342 [ V_129 ] ) ;
V_172 = F_22 ( V_21 ) ;
F_69 ( V_172 ) ;
for ( V_102 = 0 ; V_102 < V_105 ; V_102 ++ ) {
V_172 -> V_126 . V_127 [ V_102 ] . V_125 = V_104 [ V_102 ] . V_125 ;
V_172 -> V_126 . V_127 [ V_102 ] . V_128 = V_104 [ V_102 ] . V_128 ;
}
V_172 -> V_126 . V_343 = F_96 ( V_45 -> V_342 [ V_344 ] ) ;
if ( ! ( V_101 & V_123 ) &&
( V_101 & V_345 ) ) {
if ( V_21 -> V_119 >= 16 ) {
V_42 = (struct V_77 * ) V_21 -> V_26 ;
F_32 ( V_172 -> V_176 [ 0 ] ,
V_42 -> V_178 ) ;
}
V_172 -> V_43 |= V_179 ;
}
F_70 ( V_141 -> V_35 , V_21 ) ;
return 0 ;
V_303:
return - V_262 ;
}
static int F_163 ( struct V_20 * V_337 ,
struct V_338 * V_45 )
{
struct V_25 * V_141 ;
struct V_143 V_144 ;
struct V_116 * V_346 ;
int V_347 ;
char * V_348 ;
struct V_20 * V_21 = NULL ;
if ( ! V_45 -> V_342 [ V_349 ] ||
! V_45 -> V_342 [ V_118 ] ||
! V_45 -> V_342 [ V_350 ] ||
! V_45 -> V_342 [ V_344 ] )
goto V_303;
V_346 = (struct V_116 * ) F_159 (
V_45 -> V_342 [ V_349 ] ) ;
V_347 = F_164 ( V_45 -> V_342 [ V_118 ] ) ;
V_348 = ( char * ) F_159 ( V_45 -> V_342 [ V_118 ] ) ;
V_21 = F_165 ( V_347 , V_351 ) ;
if ( V_21 == NULL )
goto V_259;
if ( V_347 <= V_352 ) {
memcpy ( F_34 ( V_21 , V_347 ) , V_348 ,
V_347 ) ;
} else
goto V_259;
V_141 = F_157 ( V_346 ) ;
if ( V_141 == NULL )
goto V_303;
if ( V_141 -> V_164 || ! V_141 -> V_163 )
goto V_303;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_144 . V_147 = V_141 -> V_138 -> V_64 ;
V_144 . V_148 = V_141 -> V_138 -> V_148 ;
V_144 . V_149 = F_96 ( V_45 -> V_342 [ V_350 ] ) ;
V_144 . signal = F_96 ( V_45 -> V_342 [ V_344 ] ) ;
memcpy ( F_63 ( V_21 ) , & V_144 , sizeof( V_144 ) ) ;
F_64 ( V_141 -> V_35 , V_21 ) ;
return 0 ;
V_259:
F_44 ( V_114 L_3 , V_132 ) ;
goto V_303;
V_303:
F_13 ( V_21 ) ;
return - V_262 ;
}
static int F_166 ( struct V_20 * V_337 ,
struct V_338 * V_45 )
{
if ( V_45 == NULL )
goto V_303;
V_177 = V_45 -> V_353 ;
F_44 ( V_114 L_42
L_43 , V_45 -> V_353 ) ;
return 0 ;
V_303:
F_44 ( V_114 L_3 , V_132 ) ;
return - V_262 ;
}
static int F_167 ( struct V_354 * V_355 ,
unsigned long V_356 ,
void * V_357 )
{
struct V_358 * V_359 = V_357 ;
if ( V_356 != V_360 )
return V_361 ;
if ( V_359 -> V_362 == V_177 ) {
F_44 ( V_363 L_44
L_45 ) ;
V_177 = 0 ;
}
return V_361 ;
}
static int F_168 ( void )
{
int V_364 ;
if ( V_174 > 1 )
return 0 ;
F_44 ( V_363 L_46 ) ;
V_364 = F_169 ( & V_112 ,
V_365 , F_170 ( V_365 ) ) ;
if ( V_364 )
goto V_366;
V_364 = F_171 ( & V_367 ) ;
if ( V_364 )
goto V_366;
return 0 ;
V_366:
F_44 ( V_114 L_3 , V_132 ) ;
return - V_262 ;
}
static void F_172 ( void )
{
int V_96 ;
if ( V_174 > 1 )
return;
F_44 ( V_363 L_47 ) ;
F_173 ( & V_367 ) ;
V_96 = F_174 ( & V_112 ) ;
if ( V_96 )
F_44 ( V_114 L_48
L_49 , V_96 ) ;
}
static int T_7 F_175 ( void )
{
int V_102 , V_259 = 0 ;
T_5 V_8 [ V_84 ] ;
struct V_25 * V_26 ;
struct V_34 * V_35 ;
enum V_368 V_148 ;
if ( V_369 < 1 || V_369 > 100 )
return - V_262 ;
if ( V_174 < 1 )
return - V_262 ;
if ( V_174 > 1 ) {
V_370 . V_371 = V_174 ;
V_372 . V_284 = F_118 ;
V_372 . V_373 =
F_119 ;
V_372 . V_374 = NULL ;
V_372 . V_375 = NULL ;
V_372 . V_376 =
F_125 ;
V_372 . V_377 =
F_127 ;
V_372 . V_378 =
F_128 ;
V_372 . V_379 =
F_129 ;
V_372 . V_380 =
F_130 ;
V_372 . V_381 =
F_131 ;
V_372 . V_382 =
F_132 ;
}
F_176 ( & V_159 ) ;
F_134 ( & V_383 ) ;
V_317 = F_177 ( V_384 , L_50 ) ;
if ( F_178 ( V_317 ) )
return F_179 ( V_317 ) ;
memset ( V_8 , 0 , V_84 ) ;
V_8 [ 0 ] = 0x02 ;
for ( V_102 = 0 ; V_102 < V_369 ; V_102 ++ ) {
F_44 ( V_114 L_51 ,
V_102 ) ;
V_35 = F_180 ( sizeof( * V_26 ) , & V_372 ) ;
if ( ! V_35 ) {
F_44 ( V_114 L_52
L_53 ) ;
V_259 = - V_266 ;
goto V_385;
}
V_26 = V_35 -> V_36 ;
V_26 -> V_35 = V_35 ;
V_26 -> V_23 = F_181 ( V_317 , NULL , 0 , V_35 ,
L_54 , V_102 ) ;
if ( F_178 ( V_26 -> V_23 ) ) {
F_44 ( V_114
L_55
L_56 , F_179 ( V_26 -> V_23 ) ) ;
V_259 = - V_266 ;
goto V_386;
}
V_26 -> V_23 -> V_387 = & V_388 ;
F_182 ( & V_26 -> V_107 ) ;
F_183 ( V_35 , V_26 -> V_23 ) ;
V_8 [ 3 ] = V_102 >> 8 ;
V_8 [ 4 ] = V_102 ;
memcpy ( V_26 -> V_117 [ 0 ] . V_8 , V_8 , V_84 ) ;
memcpy ( V_26 -> V_117 [ 1 ] . V_8 , V_8 , V_84 ) ;
V_26 -> V_117 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_35 -> V_91 -> V_389 = 2 ;
V_35 -> V_91 -> V_117 = V_26 -> V_117 ;
V_35 -> V_91 -> V_390 = & V_370 ;
V_35 -> V_91 -> V_391 = 1 ;
if ( V_174 > 1 ) {
V_35 -> V_91 -> V_392 = 255 ;
V_35 -> V_91 -> V_393 = V_352 ;
V_35 -> V_91 -> V_394 = 1000 ;
}
F_184 ( & V_26 -> V_304 , F_123 ) ;
F_184 ( & V_26 -> V_284 , F_108 ) ;
V_35 -> V_395 = 1 ;
V_35 -> V_396 = 5 ;
V_35 -> V_397 = 4 ;
V_35 -> V_91 -> V_398 =
F_185 ( V_399 ) |
F_185 ( V_191 ) |
F_185 ( V_400 ) |
F_185 ( V_401 ) |
F_185 ( V_193 ) |
F_185 ( V_192 ) |
F_185 ( V_402 ) ;
V_35 -> V_43 = V_403 |
V_404 |
V_405 |
V_406 |
V_407 |
V_408 |
V_409 ;
V_35 -> V_91 -> V_43 |= V_410 |
V_411 ;
V_35 -> V_412 = sizeof( struct V_3 ) ;
V_35 -> V_413 = sizeof( struct V_12 ) ;
memcpy ( V_26 -> V_414 , V_415 ,
sizeof( V_415 ) ) ;
memcpy ( V_26 -> V_416 , V_417 ,
sizeof( V_417 ) ) ;
memcpy ( V_26 -> V_127 , V_418 , sizeof( V_418 ) ) ;
for ( V_148 = V_419 ; V_148 < V_420 ; V_148 ++ ) {
struct V_421 * V_422 = & V_26 -> V_423 [ V_148 ] ;
switch ( V_148 ) {
case V_419 :
V_422 -> V_174 = V_26 -> V_414 ;
V_422 -> V_291 =
F_170 ( V_415 ) ;
V_422 -> V_424 = V_26 -> V_127 ;
V_422 -> V_425 = F_170 ( V_418 ) ;
break;
case V_426 :
V_422 -> V_174 = V_26 -> V_416 ;
V_422 -> V_291 =
F_170 ( V_417 ) ;
V_422 -> V_424 = V_26 -> V_127 + 4 ;
V_422 -> V_425 = F_170 ( V_418 ) - 4 ;
break;
default:
continue;
}
V_422 -> V_427 . V_428 = true ;
V_422 -> V_427 . V_429 = V_430 |
V_431 |
V_432 |
V_433 ;
V_422 -> V_427 . V_434 = 0x3 ;
V_422 -> V_427 . V_435 = 0x6 ;
memset ( & V_422 -> V_427 . V_436 , 0 ,
sizeof( V_422 -> V_427 . V_436 ) ) ;
V_422 -> V_427 . V_436 . V_437 [ 0 ] = 0xff ;
V_422 -> V_427 . V_436 . V_437 [ 1 ] = 0xff ;
V_422 -> V_427 . V_436 . V_438 = V_439 ;
V_35 -> V_91 -> V_423 [ V_148 ] = V_422 ;
if ( V_174 == 1 )
continue;
V_422 -> V_440 . V_441 = true ;
V_422 -> V_440 . V_429 =
V_442 |
V_443 |
V_444 |
V_445 |
V_446 |
V_447 |
V_448 |
V_449 |
V_450 |
V_451 |
V_452 ;
V_422 -> V_440 . V_453 . V_454 =
F_27 ( V_455 << 0 |
V_455 << 2 |
V_456 << 4 |
V_455 << 6 |
V_455 << 8 |
V_456 << 10 |
V_456 << 12 |
V_455 << 14 ) ;
V_422 -> V_440 . V_453 . V_457 =
V_422 -> V_440 . V_453 . V_454 ;
}
V_26 -> V_166 = 1 ;
F_186 ( & V_26 -> V_289 ) ;
V_35 -> V_458 = 4 ;
V_35 -> V_459 = 11 ;
switch ( V_460 ) {
case V_461 :
case V_462 :
case V_463 :
case V_464 :
break;
case V_465 :
if ( V_102 == 0 ) {
V_35 -> V_91 -> V_43 |= V_466 ;
F_187 ( V_35 -> V_91 ,
& V_467 ) ;
}
break;
case V_468 :
V_35 -> V_91 -> V_43 |= V_466 ;
F_187 ( V_35 -> V_91 ,
& V_467 ) ;
break;
case V_469 :
if ( V_102 == 0 ) {
V_35 -> V_91 -> V_43 |= V_466 ;
F_187 ( V_35 -> V_91 ,
& V_467 ) ;
} else if ( V_102 == 1 ) {
V_35 -> V_91 -> V_43 |= V_466 ;
F_187 ( V_35 -> V_91 ,
& V_470 ) ;
}
break;
case V_471 :
V_35 -> V_91 -> V_43 |= V_472 ;
break;
case V_473 :
case V_474 :
if ( V_102 == 0 )
V_35 -> V_91 -> V_43 |= V_472 ;
break;
case V_475 :
if ( V_102 == 0 ) {
V_35 -> V_91 -> V_43 |= V_466 ;
F_187 ( V_35 -> V_91 ,
& V_467 ) ;
} else if ( V_102 == 1 ) {
V_35 -> V_91 -> V_43 |= V_466 ;
F_187 ( V_35 -> V_91 ,
& V_470 ) ;
} else if ( V_102 == 4 )
V_35 -> V_91 -> V_43 |= V_472 ;
break;
default:
break;
}
if ( V_460 )
F_188 ( 1 ) ;
V_259 = F_189 ( V_35 ) ;
if ( V_259 < 0 ) {
F_44 ( V_114 L_48
L_57 , V_259 ) ;
goto V_476;
}
switch ( V_460 ) {
case V_465 :
case V_461 :
break;
case V_462 :
if ( ! V_102 )
F_190 ( V_35 -> V_91 , V_477 [ 0 ] ) ;
break;
case V_463 :
case V_471 :
F_190 ( V_35 -> V_91 , V_477 [ 0 ] ) ;
break;
case V_464 :
if ( V_102 < F_170 ( V_477 ) )
F_190 ( V_35 -> V_91 , V_477 [ V_102 ] ) ;
break;
case V_468 :
case V_469 :
break;
case V_473 :
if ( V_102 == 0 )
F_190 ( V_35 -> V_91 , V_477 [ 0 ] ) ;
break;
case V_474 :
if ( V_102 == 0 )
F_190 ( V_35 -> V_91 , V_477 [ 0 ] ) ;
else if ( V_102 == 1 )
F_190 ( V_35 -> V_91 , V_477 [ 1 ] ) ;
break;
case V_475 :
if ( V_102 == 2 )
F_190 ( V_35 -> V_91 , V_477 [ 0 ] ) ;
else if ( V_102 == 3 )
F_190 ( V_35 -> V_91 , V_477 [ 1 ] ) ;
else if ( V_102 == 4 )
F_190 ( V_35 -> V_91 , V_477 [ 2 ] ) ;
break;
default:
break;
}
F_67 ( V_35 -> V_91 , L_58 ,
V_35 -> V_91 -> V_92 ) ;
V_26 -> V_316 = F_191 ( L_59 ,
V_35 -> V_91 -> V_478 ) ;
V_26 -> V_315 = F_192 ( L_60 , 0666 ,
V_26 -> V_316 , V_26 ,
& V_479 ) ;
V_26 -> V_314 = F_192 ( L_61 , 0666 ,
V_26 -> V_316 , V_26 ,
& V_480 ) ;
F_193 ( & V_26 -> V_180 , F_82 ,
( unsigned long ) V_35 ) ;
F_194 ( & V_26 -> V_481 , & V_383 ) ;
}
V_48 = F_195 ( 0 , L_54 , F_145 ) ;
if ( V_48 == NULL )
goto V_385;
F_196 () ;
V_259 = F_197 ( V_48 , V_48 -> V_482 ) ;
if ( V_259 < 0 )
goto V_483;
V_259 = F_198 ( V_48 ) ;
if ( V_259 < 0 )
goto V_483;
F_199 () ;
V_259 = F_168 () ;
if ( V_259 < 0 )
goto V_484;
return 0 ;
V_484:
F_44 ( V_114 L_62 ) ;
return V_259 ;
V_483:
F_199 () ;
V_321 ( V_48 ) ;
F_133 () ;
return V_259 ;
V_476:
F_142 ( V_26 -> V_23 ) ;
V_386:
F_143 ( V_35 ) ;
V_385:
F_133 () ;
return V_259 ;
}
static void T_8 F_200 ( void )
{
F_44 ( V_114 L_63 ) ;
F_172 () ;
F_133 () ;
F_201 ( V_48 ) ;
}
