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
static inline T_2 F_14 ( void )
{
return F_15 ( F_16 () ) ;
}
static T_3 F_17 ( struct V_25 * V_26 )
{
T_2 V_27 = F_14 () ;
return F_18 ( V_27 + V_26 -> V_28 ) ;
}
static T_2 F_19 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
return F_20 ( F_17 ( V_26 ) ) ;
}
static void F_21 ( struct V_29 * V_30 ,
struct V_1 * V_2 , T_2 V_32 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
T_2 V_27 = F_19 ( V_30 , V_2 ) ;
T_4 V_33 = V_26 -> V_34 ;
T_5 V_35 = V_32 - V_27 ;
V_26 -> V_28 += V_35 ;
V_26 -> V_36 = F_22 ( V_35 , V_33 ) ;
}
static void F_23 ( struct V_29 * V_30 ,
struct V_20 * V_37 ,
struct V_38 * V_39 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
struct V_20 * V_21 ;
struct V_40 * V_41 ;
T_6 V_42 ;
struct V_43 * V_44 = F_24 ( V_37 ) ;
struct V_45 * V_46 = F_25 ( V_30 , V_44 ) ;
if ( ! F_26 ( V_47 ) )
return;
V_21 = F_27 ( V_37 , sizeof( * V_41 ) , 0 , V_48 ) ;
if ( V_21 == NULL )
return;
V_41 = (struct V_40 * ) F_28 ( V_21 , sizeof( * V_41 ) ) ;
V_41 -> V_41 . V_49 = V_50 ;
V_41 -> V_41 . V_51 = 0 ;
V_41 -> V_41 . V_52 = F_29 ( sizeof( * V_41 ) ) ;
V_41 -> V_41 . V_53 = F_30 ( ( 1 << V_54 ) |
( 1 << V_55 ) |
( 1 << V_56 ) |
( 1 << V_57 ) ) ;
V_41 -> V_58 = F_17 ( V_26 ) ;
V_41 -> V_59 = 0 ;
V_41 -> V_60 = V_46 -> V_61 / 5 ;
V_41 -> V_62 = F_29 ( V_39 -> V_63 ) ;
V_42 = V_64 ;
if ( V_46 -> V_42 & V_65 )
V_42 |= V_66 ;
else
V_42 |= V_67 ;
V_41 -> V_68 = F_29 ( V_42 ) ;
V_21 -> V_23 = V_47 ;
F_31 ( V_21 , 0 ) ;
V_21 -> V_69 = V_70 ;
V_21 -> V_71 = V_72 ;
V_21 -> V_73 = F_32 ( V_74 ) ;
memset ( V_21 -> V_75 , 0 , sizeof( V_21 -> V_75 ) ) ;
F_33 ( V_21 ) ;
}
static void F_34 ( struct V_38 * V_39 ,
const T_7 * V_8 )
{
struct V_20 * V_21 ;
struct V_40 * V_41 ;
T_6 V_42 ;
struct V_76 * V_77 ;
if ( ! F_26 ( V_47 ) )
return;
V_21 = F_35 ( 100 ) ;
if ( V_21 == NULL )
return;
V_41 = (struct V_40 * ) F_36 ( V_21 , sizeof( * V_41 ) ) ;
V_41 -> V_41 . V_49 = V_50 ;
V_41 -> V_41 . V_51 = 0 ;
V_41 -> V_41 . V_52 = F_29 ( sizeof( * V_41 ) ) ;
V_41 -> V_41 . V_53 = F_30 ( ( 1 << V_54 ) |
( 1 << V_57 ) ) ;
V_41 -> V_59 = 0 ;
V_41 -> V_60 = 0 ;
V_41 -> V_62 = F_29 ( V_39 -> V_63 ) ;
V_42 = V_64 ;
V_41 -> V_68 = F_29 ( V_42 ) ;
V_77 = (struct V_76 * ) F_36 ( V_21 , 10 ) ;
V_77 -> V_78 = F_29 ( V_79 |
V_80 ) ;
V_77 -> V_81 = F_29 ( 0 ) ;
memcpy ( V_77 -> V_82 , V_8 , V_83 ) ;
V_21 -> V_23 = V_47 ;
F_31 ( V_21 , 0 ) ;
V_21 -> V_69 = V_70 ;
V_21 -> V_71 = V_72 ;
V_21 -> V_73 = F_32 ( V_74 ) ;
memset ( V_21 -> V_75 , 0 , sizeof( V_21 -> V_75 ) ) ;
F_33 ( V_21 ) ;
}
static bool F_37 ( struct V_25 * V_26 ,
struct V_20 * V_21 )
{
switch ( V_26 -> V_84 ) {
case V_85 :
return true ;
case V_86 :
return false ;
case V_87 :
return true ;
case V_88 :
if ( V_26 -> V_89 &&
memcmp ( V_26 -> V_30 -> V_90 -> V_91 , V_21 -> V_26 + 4 ,
V_83 ) == 0 ) {
V_26 -> V_89 = false ;
return true ;
}
return false ;
}
return true ;
}
static void F_38 ( void * V_26 , T_7 * V_92 ,
struct V_1 * V_2 )
{
struct V_93 * V_94 = V_26 ;
if ( memcmp ( V_92 , V_94 -> V_8 , V_83 ) == 0 )
V_94 -> V_95 = true ;
}
static bool F_39 ( struct V_25 * V_26 ,
const T_7 * V_8 )
{
struct V_93 V_94 ;
if ( memcmp ( V_8 , V_26 -> V_30 -> V_90 -> V_91 , V_83 ) == 0 )
return true ;
V_94 . V_95 = false ;
V_94 . V_8 = V_8 ;
F_40 ( V_26 -> V_30 ,
V_96 ,
F_38 ,
& V_94 ) ;
return V_94 . V_95 ;
}
static void F_41 ( struct V_29 * V_30 ,
struct V_20 * V_97 ,
int V_98 )
{
struct V_20 * V_21 ;
struct V_25 * V_26 = V_30 -> V_31 ;
struct V_76 * V_41 = (struct V_76 * ) V_97 -> V_26 ;
struct V_43 * V_44 = F_24 ( V_97 ) ;
void * V_99 ;
unsigned int V_100 = 0 ;
int V_101 ;
struct V_102 V_103 [ V_104 ] ;
if ( V_26 -> V_84 != V_85 )
V_41 -> V_78 |= F_29 ( V_105 ) ;
if ( F_42 ( & V_26 -> V_106 ) >= V_107 ) {
while ( F_42 ( & V_26 -> V_106 ) >= V_108 )
F_43 ( & V_26 -> V_106 ) ;
}
V_21 = F_44 ( V_109 , V_48 ) ;
if ( V_21 == NULL )
goto V_110;
V_99 = F_45 ( V_21 , 0 , 0 , & V_111 , 0 ,
V_112 ) ;
if ( V_99 == NULL ) {
F_46 ( V_113 L_2 ) ;
goto V_110;
}
if ( F_47 ( V_21 , V_114 ,
sizeof( struct V_115 ) , V_26 -> V_116 [ 1 ] . V_8 ) )
goto V_110;
if ( F_47 ( V_21 , V_117 , V_97 -> V_118 , V_97 -> V_26 ) )
goto V_110;
if ( V_44 -> V_42 & V_119 )
V_100 |= V_120 ;
if ( V_44 -> V_42 & V_121 )
V_100 |= V_122 ;
if ( F_48 ( V_21 , V_123 , V_100 ) )
goto V_110;
for ( V_101 = 0 ; V_101 < V_104 ; V_101 ++ ) {
V_103 [ V_101 ] . V_124 = V_44 -> V_125 . V_126 [ V_101 ] . V_124 ;
V_103 [ V_101 ] . V_127 = V_44 -> V_125 . V_126 [ V_101 ] . V_127 ;
}
if ( F_47 ( V_21 , V_128 ,
sizeof( struct V_102 ) * V_104 ,
V_103 ) )
goto V_110;
if ( F_49 ( V_21 , V_129 , ( unsigned long ) V_97 ) )
goto V_110;
F_50 ( V_21 , V_99 ) ;
F_51 ( & V_130 , V_21 , V_98 ) ;
F_52 ( & V_26 -> V_106 , V_97 ) ;
return;
V_110:
F_46 ( V_113 L_3 , V_131 ) ;
}
static bool F_53 ( struct V_38 * V_132 ,
struct V_38 * V_133 )
{
if ( ! V_132 || ! V_133 )
return false ;
return V_132 -> V_63 == V_133 -> V_63 ;
}
static void F_54 ( void * V_134 , T_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_135 * V_26 = V_134 ;
if ( ! V_2 -> V_136 )
return;
if ( ! F_53 ( V_26 -> V_137 ,
F_55 ( V_2 -> V_136 ) -> V_138 . V_39 ) )
return;
V_26 -> V_139 = true ;
}
static bool F_56 ( struct V_29 * V_30 ,
struct V_20 * V_21 ,
struct V_38 * V_39 )
{
struct V_25 * V_26 = V_30 -> V_31 , * V_140 ;
bool V_141 = false ;
struct V_76 * V_41 = (struct V_76 * ) V_21 -> V_26 ;
struct V_43 * V_44 = F_24 ( V_21 ) ;
struct V_142 V_143 ;
T_2 V_27 ;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
V_143 . V_144 |= V_145 ;
V_143 . V_146 = V_39 -> V_63 ;
V_143 . V_147 = V_39 -> V_147 ;
V_143 . V_148 = V_44 -> V_149 . V_126 [ 0 ] . V_124 ;
if ( V_44 -> V_149 . V_126 [ 0 ] . V_42 & V_150 )
V_143 . V_144 |= V_151 ;
if ( V_44 -> V_149 . V_126 [ 0 ] . V_42 & V_152 )
V_143 . V_144 |= V_153 ;
if ( V_44 -> V_149 . V_126 [ 0 ] . V_42 & V_154 )
V_143 . V_144 |= V_155 ;
V_143 . signal = V_26 -> V_156 - 50 ;
if ( V_26 -> V_84 != V_85 )
V_41 -> V_78 |= F_29 ( V_105 ) ;
F_57 ( V_21 ) ;
F_58 ( V_21 ) ;
V_21 -> V_157 = 0 ;
F_59 ( V_21 ) ;
F_60 ( V_21 ) ;
if ( F_61 ( V_41 -> V_78 ) ||
F_62 ( V_41 -> V_78 ) )
V_27 = V_26 -> V_158 ;
else
V_27 = F_14 () ;
F_63 ( & V_159 ) ;
F_64 (data2, &hwsim_radios, list) {
struct V_20 * V_160 ;
struct V_135 V_135 = {
. V_139 = false ,
. V_137 = V_39 ,
} ;
if ( V_26 == V_140 )
continue;
if ( ! V_140 -> V_161 || ( V_140 -> V_162 && ! V_140 -> V_163 ) ||
! F_37 ( V_140 , V_21 ) )
continue;
if ( ! ( V_26 -> V_164 & V_140 -> V_164 ) )
continue;
if ( ! F_53 ( V_39 , V_140 -> V_163 ) &&
! F_53 ( V_39 , V_140 -> V_137 ) ) {
F_40 (
V_140 -> V_30 , V_96 ,
F_54 , & V_135 ) ;
if ( ! V_135 . V_139 )
continue;
}
if ( V_21 -> V_118 < V_165 && V_166 ) {
struct V_167 * V_167 = F_65 ( V_48 ) ;
if ( ! V_167 )
continue;
V_160 = F_35 ( 128 ) ;
if ( ! V_160 ) {
F_66 ( V_167 ) ;
continue;
}
memcpy ( F_67 ( V_167 ) , V_21 -> V_26 , V_21 -> V_118 ) ;
F_68 ( V_160 , 0 , V_167 , 0 , V_21 -> V_118 , V_21 -> V_118 ) ;
} else {
V_160 = F_69 ( V_21 , V_48 ) ;
if ( ! V_160 )
continue;
}
if ( F_39 ( V_140 , V_41 -> V_82 ) )
V_141 = true ;
V_143 . V_168 = V_27 + V_140 -> V_28 ;
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
memcpy ( F_70 ( V_160 ) , & V_143 , sizeof( V_143 ) ) ;
F_71 ( V_140 -> V_30 , V_160 ) ;
}
F_72 ( & V_159 ) ;
return V_141 ;
}
static void F_73 ( struct V_29 * V_30 ,
struct V_169 * V_149 ,
struct V_20 * V_21 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
struct V_43 * V_170 = F_24 ( V_21 ) ;
struct V_15 * V_136 ;
struct V_38 * V_137 ;
bool V_141 ;
T_4 V_171 ;
if ( F_6 ( V_21 -> V_118 < 10 ) ) {
F_13 ( V_21 ) ;
return;
}
if ( V_172 == 1 ) {
V_137 = V_26 -> V_137 ;
} else if ( V_170 -> V_173 == 4 ) {
V_137 = V_26 -> V_163 ;
} else {
V_136 = F_55 ( V_170 -> V_149 . V_2 -> V_136 ) ;
if ( V_136 )
V_137 = V_136 -> V_138 . V_39 ;
else
V_137 = NULL ;
}
if ( F_2 ( ! V_137 , L_4 , V_170 -> V_173 ) ) {
F_13 ( V_21 ) ;
return;
}
if ( V_26 -> V_162 && ! V_26 -> V_163 ) {
F_74 ( V_30 -> V_90 , L_5 ) ;
F_13 ( V_21 ) ;
return;
}
if ( V_170 -> V_149 . V_2 )
F_1 ( V_170 -> V_149 . V_2 ) ;
if ( V_149 -> V_11 )
F_5 ( V_149 -> V_11 ) ;
V_170 -> V_174 [ 0 ] = V_137 ;
F_23 ( V_30 , V_21 , V_137 ) ;
V_171 = F_75 ( V_175 ) ;
if ( V_171 )
return F_41 ( V_30 , V_21 , V_171 ) ;
V_141 = F_56 ( V_30 , V_21 , V_137 ) ;
if ( V_141 && V_21 -> V_118 >= 16 ) {
struct V_76 * V_41 = (struct V_76 * ) V_21 -> V_26 ;
F_34 ( V_137 , V_41 -> V_176 ) ;
}
F_76 ( V_170 ) ;
V_170 -> V_149 . V_126 [ 0 ] . V_127 = 1 ;
V_170 -> V_149 . V_126 [ 1 ] . V_124 = - 1 ;
if ( ! ( V_170 -> V_42 & V_121 ) && V_141 )
V_170 -> V_42 |= V_177 ;
F_77 ( V_30 , V_21 ) ;
}
static int F_78 ( struct V_29 * V_30 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
F_74 ( V_30 -> V_90 , L_6 , V_131 ) ;
V_26 -> V_161 = true ;
return 0 ;
}
static void F_79 ( struct V_29 * V_30 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
V_26 -> V_161 = false ;
F_80 ( & V_26 -> V_178 ) ;
F_74 ( V_30 -> V_90 , L_6 , V_131 ) ;
}
static int F_81 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
F_74 ( V_30 -> V_90 , L_7 ,
V_131 , F_82 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_179 = 0 ;
V_2 -> V_173 [ V_180 ] = 0 ;
V_2 -> V_173 [ V_181 ] = 1 ;
V_2 -> V_173 [ V_182 ] = 2 ;
V_2 -> V_173 [ V_183 ] = 3 ;
return 0 ;
}
static int F_83 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
enum V_184 V_185 ,
bool V_186 )
{
V_185 = F_84 ( V_185 , V_186 ) ;
F_74 ( V_30 -> V_90 ,
L_8 ,
V_131 , F_82 ( V_2 ) ,
V_185 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_85 (
struct V_29 * V_30 , struct V_1 * V_2 )
{
F_74 ( V_30 -> V_90 , L_7 ,
V_131 , F_82 ( V_2 ) ,
V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_86 ( struct V_29 * V_30 ,
struct V_20 * V_21 ,
struct V_38 * V_39 )
{
T_4 V_187 = F_75 ( V_175 ) ;
F_23 ( V_30 , V_21 , V_39 ) ;
if ( V_187 )
return F_41 ( V_30 , V_21 , V_187 ) ;
F_56 ( V_30 , V_21 , V_39 ) ;
F_13 ( V_21 ) ;
}
static void F_87 ( void * V_188 , T_7 * V_92 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_188 ;
struct V_29 * V_30 = V_26 -> V_30 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_189 * V_190 ;
struct V_20 * V_21 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_191 &&
V_2 -> type != V_192 &&
V_2 -> type != V_193 )
return;
V_21 = F_88 ( V_30 , V_2 ) ;
if ( V_21 == NULL )
return;
V_44 = F_24 ( V_21 ) ;
V_46 = F_25 ( V_30 , V_44 ) ;
V_190 = (struct V_189 * ) V_21 -> V_26 ;
V_26 -> V_158 = F_14 () ;
V_190 -> V_194 . V_195 . V_196 = F_18 ( V_26 -> V_158 +
V_26 -> V_28 +
24 * 8 * 10 / V_46 -> V_61 ) ;
F_86 ( V_30 , V_21 ,
F_55 ( V_2 -> V_136 ) -> V_138 . V_39 ) ;
}
static enum V_197
F_89 ( struct V_198 * V_199 )
{
struct V_25 * V_26 =
F_90 ( V_199 , struct V_25 ,
V_178 . V_199 ) ;
struct V_29 * V_30 = V_26 -> V_30 ;
T_2 V_33 = V_26 -> V_34 ;
T_8 V_200 ;
if ( ! V_26 -> V_161 )
goto V_201;
F_40 (
V_30 , V_96 ,
F_87 , V_26 ) ;
if ( V_26 -> V_36 ) {
V_33 -= V_26 -> V_36 ;
V_26 -> V_36 = 0 ;
}
V_200 = F_91 ( F_92 ( V_199 ) ,
F_93 ( V_33 * 1000 ) ) ;
F_94 ( & V_26 -> V_178 , V_200 , V_202 ) ;
V_201:
return V_203 ;
}
static int F_95 ( struct V_29 * V_30 , T_4 V_204 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
struct V_205 * V_206 = & V_30 -> V_206 ;
static const char * V_207 [ V_208 ] = {
[ V_209 ] = L_9 ,
[ V_210 ] = L_10 ,
[ V_211 ] = L_11 ,
[ V_212 ] = L_12 ,
} ;
F_74 ( V_30 -> V_90 ,
L_13 ,
V_131 ,
V_206 -> V_137 ? V_206 -> V_137 -> V_63 : 0 ,
V_213 [ V_206 -> V_214 ] ,
! ! ( V_206 -> V_42 & V_215 ) ,
! ! ( V_206 -> V_42 & V_216 ) ,
V_207 [ V_206 -> V_217 ] ) ;
V_26 -> V_162 = ! ! ( V_206 -> V_42 & V_215 ) ;
V_26 -> V_137 = V_206 -> V_137 ;
F_6 ( V_26 -> V_137 && V_172 > 1 ) ;
V_26 -> V_156 = V_206 -> V_156 ;
if ( ! V_26 -> V_161 || ! V_26 -> V_34 )
F_80 ( & V_26 -> V_178 ) ;
else if ( ! F_96 ( & V_26 -> V_178 . V_199 ) ) {
T_2 V_32 = F_19 ( V_30 , NULL ) ;
T_4 V_33 = V_26 -> V_34 ;
T_2 V_218 = V_33 - F_22 ( V_32 , V_33 ) ;
F_94 ( & V_26 -> V_178 ,
F_93 ( V_218 * 1000 ) ,
V_219 ) ;
}
return 0 ;
}
static void F_97 ( struct V_29 * V_30 ,
unsigned int V_220 ,
unsigned int * V_221 , T_2 V_222 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
F_74 ( V_30 -> V_90 , L_6 , V_131 ) ;
V_26 -> V_223 = 0 ;
if ( * V_221 & V_224 )
V_26 -> V_223 |= V_224 ;
if ( * V_221 & V_225 )
V_26 -> V_223 |= V_225 ;
* V_221 = V_26 -> V_223 ;
}
static void F_98 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_226 * V_44 ,
T_4 V_204 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_25 * V_26 = V_30 -> V_31 ;
F_1 ( V_2 ) ;
F_74 ( V_30 -> V_90 , L_14 , V_131 , V_204 ) ;
if ( V_204 & V_227 ) {
F_74 ( V_30 -> V_90 , L_15 ,
V_131 , V_44 -> V_228 ) ;
memcpy ( V_4 -> V_228 , V_44 -> V_228 , V_83 ) ;
}
if ( V_204 & V_229 ) {
F_74 ( V_30 -> V_90 , L_16 ,
V_44 -> V_230 , V_44 -> V_231 ) ;
V_4 -> V_230 = V_44 -> V_230 ;
V_4 -> V_231 = V_44 -> V_231 ;
}
if ( V_204 & V_232 ) {
F_74 ( V_30 -> V_90 , L_17 , V_44 -> V_34 ) ;
V_26 -> V_34 = V_44 -> V_34 * 1024 ;
}
if ( V_204 & V_233 ) {
F_74 ( V_30 -> V_90 , L_18 , V_44 -> V_234 ) ;
if ( V_26 -> V_161 &&
! F_96 ( & V_26 -> V_178 . V_199 ) &&
V_44 -> V_234 ) {
T_2 V_32 , V_218 ;
T_4 V_33 ;
if ( F_6 ( ! V_26 -> V_34 ) )
V_26 -> V_34 = 1000 * 1024 ;
V_32 = F_19 ( V_30 , V_2 ) ;
V_33 = V_26 -> V_34 ;
V_218 = V_33 - F_22 ( V_32 , V_33 ) ;
F_94 ( & V_26 -> V_178 ,
F_93 ( V_218 * 1000 ) ,
V_219 ) ;
} else if ( ! V_44 -> V_234 )
F_80 ( & V_26 -> V_178 ) ;
}
if ( V_204 & V_235 ) {
F_74 ( V_30 -> V_90 , L_19 ,
V_44 -> V_236 ) ;
}
if ( V_204 & V_237 ) {
F_74 ( V_30 -> V_90 , L_20 ,
V_44 -> V_238 ) ;
}
if ( V_204 & V_239 ) {
F_74 ( V_30 -> V_90 , L_21 , V_44 -> V_240 ) ;
}
if ( V_204 & V_241 ) {
F_74 ( V_30 -> V_90 , L_22 ,
V_44 -> V_242 ) ;
}
if ( V_204 & V_243 ) {
F_74 ( V_30 -> V_90 , L_23 ,
( unsigned long long ) V_44 -> V_244 ) ;
}
if ( V_204 & V_245 )
F_74 ( V_30 -> V_90 , L_24 , V_44 -> V_246 ) ;
}
static int F_99 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_100 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_101 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
enum V_247 V_248 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_248 ) {
case V_249 :
case V_250 :
break;
default:
F_2 ( 1 , L_25 , V_248 ) ;
break;
}
}
static int F_102 ( struct V_29 * V_30 ,
struct V_10 * V_11 ,
bool V_251 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_103 (
struct V_29 * V_30 ,
struct V_1 * V_2 , T_6 V_252 ,
const struct V_253 * V_254 )
{
F_74 ( V_30 -> V_90 ,
L_26 ,
V_131 , V_252 ,
V_254 -> V_255 , V_254 -> V_256 ,
V_254 -> V_257 , V_254 -> V_258 ) ;
return 0 ;
}
static int F_104 (
struct V_29 * V_30 , int V_124 ,
struct V_259 * V_260 )
{
struct V_205 * V_206 = & V_30 -> V_206 ;
F_74 ( V_30 -> V_90 , L_27 , V_131 , V_124 ) ;
if ( V_124 != 0 )
return - V_261 ;
V_260 -> V_137 = V_206 -> V_137 ;
V_260 -> V_262 = V_263 ;
V_260 -> V_264 = - 92 ;
return 0 ;
}
static int F_105 ( struct V_29 * V_30 ,
void * V_26 , int V_118 )
{
struct V_25 * V_265 = V_30 -> V_31 ;
struct V_266 * V_267 [ V_268 + 1 ] ;
struct V_20 * V_21 ;
int V_269 , V_84 ;
V_269 = F_106 ( V_267 , V_268 , V_26 , V_118 ,
V_270 ) ;
if ( V_269 )
return V_269 ;
if ( ! V_267 [ V_271 ] )
return - V_272 ;
switch ( F_107 ( V_267 [ V_271 ] ) ) {
case V_273 :
if ( ! V_267 [ V_274 ] )
return - V_272 ;
V_84 = F_107 ( V_267 [ V_274 ] ) ;
return F_108 ( V_265 , V_84 ) ;
case V_275 :
V_21 = F_109 ( V_30 -> V_90 ,
F_110 ( sizeof( T_4 ) ) ) ;
if ( ! V_21 )
return - V_276 ;
if ( F_48 ( V_21 , V_274 , V_265 -> V_84 ) )
goto V_110;
return F_111 ( V_21 ) ;
case V_277 :
F_112 ( V_30 ) ;
return 0 ;
case V_278 :
F_113 ( V_30 ) ;
return 0 ;
default:
return - V_279 ;
}
V_110:
F_114 ( V_21 ) ;
return - V_280 ;
}
static int F_115 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
enum V_281 V_282 ,
struct V_10 * V_11 , T_6 V_283 , T_6 * V_284 ,
T_7 V_285 )
{
switch ( V_282 ) {
case V_286 :
F_116 ( V_2 , V_11 -> V_8 , V_283 ) ;
break;
case V_287 :
case V_288 :
case V_289 :
F_117 ( V_2 , V_11 -> V_8 , V_283 ) ;
break;
case V_290 :
break;
case V_291 :
case V_292 :
break;
default:
return - V_279 ;
}
return 0 ;
}
static void F_118 ( struct V_29 * V_30 , bool V_293 )
{
}
static void F_119 ( struct V_294 * V_295 )
{
struct V_25 * V_265 =
F_90 ( V_295 , struct V_25 , V_296 . V_295 ) ;
struct V_297 * V_298 = V_265 -> V_299 ;
int V_300 , V_101 ;
F_120 ( & V_265 -> V_301 ) ;
if ( V_265 -> V_302 >= V_298 -> V_303 ) {
F_74 ( V_265 -> V_30 -> V_90 , L_28 ) ;
F_121 ( V_265 -> V_30 , false ) ;
V_265 -> V_299 = NULL ;
V_265 -> V_304 = NULL ;
V_265 -> V_163 = NULL ;
F_122 ( & V_265 -> V_301 ) ;
return;
}
F_74 ( V_265 -> V_30 -> V_90 , L_29 ,
V_298 -> V_172 [ V_265 -> V_302 ] -> V_63 ) ;
V_265 -> V_163 = V_298 -> V_172 [ V_265 -> V_302 ] ;
if ( V_265 -> V_163 -> V_42 & V_305 ||
! V_298 -> V_306 ) {
V_300 = 120 ;
} else {
V_300 = 30 ;
for ( V_101 = 0 ; V_101 < V_298 -> V_306 ; V_101 ++ ) {
struct V_20 * V_307 ;
V_307 = F_123 ( V_265 -> V_30 ,
V_265 -> V_304 ,
V_298 -> V_308 [ V_101 ] . V_309 ,
V_298 -> V_308 [ V_101 ] . V_310 ,
V_298 -> V_311 ) ;
if ( ! V_307 )
continue;
if ( V_298 -> V_311 )
memcpy ( F_36 ( V_307 , V_298 -> V_311 ) , V_298 -> V_312 ,
V_298 -> V_311 ) ;
F_124 () ;
F_86 ( V_265 -> V_30 , V_307 ,
V_265 -> V_163 ) ;
F_125 () ;
}
}
F_126 ( V_265 -> V_30 , & V_265 -> V_296 ,
F_127 ( V_300 ) ) ;
V_265 -> V_302 ++ ;
F_122 ( & V_265 -> V_301 ) ;
}
static int F_128 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_297 * V_298 )
{
struct V_25 * V_265 = V_30 -> V_31 ;
F_120 ( & V_265 -> V_301 ) ;
if ( F_6 ( V_265 -> V_163 || V_265 -> V_299 ) ) {
F_122 ( & V_265 -> V_301 ) ;
return - V_313 ;
}
V_265 -> V_299 = V_298 ;
V_265 -> V_304 = V_2 ;
V_265 -> V_302 = 0 ;
F_122 ( & V_265 -> V_301 ) ;
F_74 ( V_30 -> V_90 , L_30 ) ;
F_126 ( V_265 -> V_30 , & V_265 -> V_296 , 0 ) ;
return 0 ;
}
static void F_129 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
struct V_25 * V_265 = V_30 -> V_31 ;
F_74 ( V_30 -> V_90 , L_31 ) ;
F_130 ( & V_265 -> V_296 ) ;
F_120 ( & V_265 -> V_301 ) ;
F_121 ( V_265 -> V_30 , true ) ;
V_265 -> V_163 = NULL ;
V_265 -> V_299 = NULL ;
V_265 -> V_304 = NULL ;
F_122 ( & V_265 -> V_301 ) ;
}
static void F_131 ( struct V_29 * V_30 )
{
struct V_25 * V_265 = V_30 -> V_31 ;
F_120 ( & V_265 -> V_301 ) ;
if ( V_265 -> V_314 ) {
F_46 ( V_113 L_32 ) ;
goto V_201;
}
F_46 ( V_113 L_33 ) ;
V_265 -> V_314 = true ;
V_201:
F_122 ( & V_265 -> V_301 ) ;
}
static void F_132 ( struct V_29 * V_30 )
{
struct V_25 * V_265 = V_30 -> V_31 ;
F_120 ( & V_265 -> V_301 ) ;
F_46 ( V_113 L_34 ) ;
V_265 -> V_314 = false ;
F_122 ( & V_265 -> V_301 ) ;
}
static void F_133 ( struct V_294 * V_295 )
{
struct V_25 * V_265 =
F_90 ( V_295 , struct V_25 , V_315 . V_295 ) ;
F_120 ( & V_265 -> V_301 ) ;
F_134 ( V_265 -> V_30 ) ;
V_265 -> V_163 = NULL ;
F_122 ( & V_265 -> V_301 ) ;
F_74 ( V_265 -> V_30 -> V_90 , L_35 ) ;
}
static int F_135 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_38 * V_39 ,
int V_316 )
{
struct V_25 * V_265 = V_30 -> V_31 ;
F_120 ( & V_265 -> V_301 ) ;
if ( F_6 ( V_265 -> V_163 || V_265 -> V_299 ) ) {
F_122 ( & V_265 -> V_301 ) ;
return - V_313 ;
}
V_265 -> V_163 = V_39 ;
F_122 ( & V_265 -> V_301 ) ;
F_74 ( V_30 -> V_90 , L_36 ,
V_39 -> V_63 , V_316 ) ;
F_136 ( V_30 ) ;
F_126 ( V_30 , & V_265 -> V_315 ,
F_127 ( V_316 ) ) ;
return 0 ;
}
static int F_137 ( struct V_29 * V_30 )
{
struct V_25 * V_265 = V_30 -> V_31 ;
F_130 ( & V_265 -> V_315 ) ;
F_120 ( & V_265 -> V_301 ) ;
V_265 -> V_163 = NULL ;
F_122 ( & V_265 -> V_301 ) ;
F_74 ( V_30 -> V_90 , L_37 ) ;
return 0 ;
}
static int F_138 ( struct V_29 * V_30 ,
struct V_15 * V_317 )
{
F_10 ( V_317 ) ;
F_74 ( V_30 -> V_90 ,
L_38 ,
V_317 -> V_138 . V_39 -> V_63 , V_317 -> V_138 . V_318 ,
V_317 -> V_138 . V_319 , V_317 -> V_138 . V_320 ) ;
return 0 ;
}
static void F_139 ( struct V_29 * V_30 ,
struct V_15 * V_317 )
{
F_74 ( V_30 -> V_90 ,
L_39 ,
V_317 -> V_138 . V_39 -> V_63 , V_317 -> V_138 . V_318 ,
V_317 -> V_138 . V_319 , V_317 -> V_138 . V_320 ) ;
F_9 ( V_317 ) ;
F_11 ( V_317 ) ;
}
static void F_140 ( struct V_29 * V_30 ,
struct V_15 * V_317 ,
T_4 V_204 )
{
F_9 ( V_317 ) ;
F_74 ( V_30 -> V_90 ,
L_40 ,
V_317 -> V_138 . V_39 -> V_63 , V_317 -> V_138 . V_318 ,
V_317 -> V_138 . V_319 , V_317 -> V_138 . V_320 ) ;
}
static int F_141 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_15 * V_317 )
{
F_1 ( V_2 ) ;
F_9 ( V_317 ) ;
return 0 ;
}
static void F_142 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_15 * V_317 )
{
F_1 ( V_2 ) ;
F_9 ( V_317 ) ;
}
static void F_143 ( void )
{
struct V_321 V_322 , * V_101 , * V_323 ;
struct V_25 * V_26 , * V_324 ;
F_144 ( & V_322 ) ;
F_145 ( & V_159 ) ;
F_146 (i, tmp, &hwsim_radios)
F_147 ( V_101 , & V_322 ) ;
F_148 ( & V_159 ) ;
F_149 (data, tmpdata, &tmplist, list) {
F_150 ( V_26 -> V_325 ) ;
F_150 ( V_26 -> V_326 ) ;
F_150 ( V_26 -> V_327 ) ;
F_151 ( V_26 -> V_30 ) ;
F_152 ( V_26 -> V_23 ) ;
F_153 ( V_26 -> V_30 ) ;
}
F_154 ( V_328 ) ;
}
static void F_155 ( struct V_22 * V_23 )
{
V_23 -> V_329 = & V_330 ;
V_23 -> V_331 = V_332 ;
F_156 ( V_23 ) ;
V_23 -> V_333 = 0 ;
V_23 -> type = V_334 ;
memset ( V_23 -> V_335 , 0 , V_83 ) ;
V_23 -> V_335 [ 0 ] = 0x12 ;
}
static void F_157 ( void * V_336 , T_7 * V_92 , struct V_1 * V_2 )
{
struct V_25 * V_26 = V_336 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_337 * V_338 ;
if ( ! V_4 -> V_230 )
return;
F_74 ( V_26 -> V_30 -> V_90 ,
L_41 ,
V_131 , V_4 -> V_228 , V_4 -> V_231 ) ;
V_21 = F_35 ( sizeof( * V_338 ) ) ;
if ( ! V_21 )
return;
V_338 = ( void * ) F_36 ( V_21 , sizeof( * V_338 ) ) ;
V_338 -> V_78 = F_29 ( V_79 |
V_339 |
V_105 ) ;
V_338 -> V_231 = F_29 ( 0xc000 | V_4 -> V_231 ) ;
memcpy ( V_338 -> V_228 , V_4 -> V_228 , V_83 ) ;
memcpy ( V_338 -> V_340 , V_92 , V_83 ) ;
F_158 () ;
F_86 ( V_26 -> V_30 , V_21 ,
F_55 ( V_2 -> V_136 ) -> V_138 . V_39 ) ;
F_159 () ;
}
static void F_160 ( struct V_25 * V_26 , T_7 * V_92 ,
struct V_1 * V_2 , int V_84 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_76 * V_41 ;
if ( ! V_4 -> V_230 )
return;
F_74 ( V_26 -> V_30 -> V_90 ,
L_42 ,
V_131 , V_4 -> V_228 , V_84 ) ;
V_21 = F_35 ( sizeof( * V_41 ) ) ;
if ( ! V_21 )
return;
V_41 = ( void * ) F_36 ( V_21 , sizeof( * V_41 ) - V_83 ) ;
V_41 -> V_78 = F_29 ( V_341 |
V_342 |
( V_84 ? V_105 : 0 ) ) ;
V_41 -> V_81 = F_29 ( 0 ) ;
memcpy ( V_41 -> V_82 , V_4 -> V_228 , V_83 ) ;
memcpy ( V_41 -> V_176 , V_92 , V_83 ) ;
memcpy ( V_41 -> V_343 , V_4 -> V_228 , V_83 ) ;
F_158 () ;
F_86 ( V_26 -> V_30 , V_21 ,
F_55 ( V_2 -> V_136 ) -> V_138 . V_39 ) ;
F_159 () ;
}
static void F_161 ( void * V_336 , T_7 * V_92 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_336 ;
F_160 ( V_26 , V_92 , V_2 , 1 ) ;
}
static void F_162 ( void * V_336 , T_7 * V_92 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_336 ;
F_160 ( V_26 , V_92 , V_2 , 0 ) ;
}
static int F_163 ( void * V_336 , T_2 * V_344 )
{
struct V_25 * V_26 = V_336 ;
* V_344 = V_26 -> V_84 ;
return 0 ;
}
static int F_108 ( void * V_336 , T_2 V_344 )
{
struct V_25 * V_26 = V_336 ;
enum V_345 V_346 ;
if ( V_344 != V_85 && V_344 != V_86 && V_344 != V_87 &&
V_344 != V_88 )
return - V_272 ;
V_346 = V_26 -> V_84 ;
V_26 -> V_84 = V_344 ;
if ( V_344 == V_88 ) {
F_164 ( V_26 -> V_30 ,
V_96 ,
F_157 , V_26 ) ;
V_26 -> V_89 = true ;
} else if ( V_346 == V_85 && V_344 != V_85 ) {
F_164 ( V_26 -> V_30 ,
V_96 ,
F_161 ,
V_26 ) ;
} else if ( V_346 != V_85 && V_344 == V_85 ) {
F_164 ( V_26 -> V_30 ,
V_96 ,
F_162 ,
V_26 ) ;
}
return 0 ;
}
static int F_165 ( void * V_336 , T_2 * V_344 )
{
struct V_25 * V_26 = V_336 ;
* V_344 = V_26 -> V_164 ;
return 0 ;
}
static int F_166 ( void * V_336 , T_2 V_344 )
{
struct V_25 * V_26 = V_336 ;
V_26 -> V_164 = V_344 ;
return 0 ;
}
static struct V_25 * F_167 (
struct V_115 * V_8 )
{
struct V_25 * V_26 ;
bool V_347 = false ;
F_145 ( & V_159 ) ;
F_64 (data, &hwsim_radios, list) {
if ( memcmp ( V_26 -> V_116 [ 1 ] . V_8 , V_8 ,
sizeof( struct V_115 ) ) == 0 ) {
V_347 = true ;
break;
}
}
F_148 ( & V_159 ) ;
if ( ! V_347 )
return NULL ;
return V_26 ;
}
static int F_168 ( struct V_20 * V_348 ,
struct V_349 * V_44 )
{
struct V_76 * V_41 ;
struct V_25 * V_140 ;
struct V_43 * V_170 ;
struct V_102 * V_103 ;
unsigned long V_350 ;
struct V_20 * V_21 , * V_323 ;
struct V_115 * V_351 ;
unsigned int V_100 ;
int V_101 ;
bool V_352 = false ;
if ( ! V_44 -> V_353 [ V_114 ] ||
! V_44 -> V_353 [ V_123 ] ||
! V_44 -> V_353 [ V_129 ] ||
! V_44 -> V_353 [ V_128 ] )
goto V_201;
V_351 = (struct V_115 * ) F_169 (
V_44 -> V_353 [ V_114 ] ) ;
V_100 = F_107 ( V_44 -> V_353 [ V_123 ] ) ;
V_350 = F_170 ( V_44 -> V_353 [ V_129 ] ) ;
V_140 = F_167 ( V_351 ) ;
if ( V_140 == NULL )
goto V_201;
F_171 (&data2->pending, skb, tmp) {
if ( ( unsigned long ) V_21 == V_350 ) {
F_172 ( V_21 , & V_140 -> V_106 ) ;
V_352 = true ;
break;
}
}
if ( ! V_352 )
goto V_201;
V_103 = (struct V_102 * ) F_169 (
V_44 -> V_353 [ V_128 ] ) ;
V_170 = F_24 ( V_21 ) ;
F_76 ( V_170 ) ;
for ( V_101 = 0 ; V_101 < V_104 ; V_101 ++ ) {
V_170 -> V_125 . V_126 [ V_101 ] . V_124 = V_103 [ V_101 ] . V_124 ;
V_170 -> V_125 . V_126 [ V_101 ] . V_127 = V_103 [ V_101 ] . V_127 ;
}
V_170 -> V_125 . V_354 = F_107 ( V_44 -> V_353 [ V_355 ] ) ;
if ( ! ( V_100 & V_122 ) &&
( V_100 & V_356 ) ) {
if ( V_21 -> V_118 >= 16 ) {
V_41 = (struct V_76 * ) V_21 -> V_26 ;
F_34 ( V_170 -> V_174 [ 0 ] ,
V_41 -> V_176 ) ;
}
V_170 -> V_42 |= V_177 ;
}
F_77 ( V_140 -> V_30 , V_21 ) ;
return 0 ;
V_201:
return - V_272 ;
}
static int F_173 ( struct V_20 * V_348 ,
struct V_349 * V_44 )
{
struct V_25 * V_140 ;
struct V_142 V_143 ;
struct V_115 * V_357 ;
int V_358 ;
char * V_359 ;
struct V_20 * V_21 = NULL ;
if ( ! V_44 -> V_353 [ V_360 ] ||
! V_44 -> V_353 [ V_117 ] ||
! V_44 -> V_353 [ V_361 ] ||
! V_44 -> V_353 [ V_355 ] )
goto V_201;
V_357 = (struct V_115 * ) F_169 (
V_44 -> V_353 [ V_360 ] ) ;
V_358 = F_174 ( V_44 -> V_353 [ V_117 ] ) ;
V_359 = ( char * ) F_169 ( V_44 -> V_353 [ V_117 ] ) ;
V_21 = F_175 ( V_358 , V_362 ) ;
if ( V_21 == NULL )
goto V_269;
if ( V_358 <= V_363 ) {
memcpy ( F_36 ( V_21 , V_358 ) , V_359 ,
V_358 ) ;
} else
goto V_269;
V_140 = F_167 ( V_357 ) ;
if ( V_140 == NULL )
goto V_201;
if ( V_140 -> V_162 || ! V_140 -> V_161 )
goto V_201;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
V_143 . V_146 = V_140 -> V_137 -> V_63 ;
V_143 . V_147 = V_140 -> V_137 -> V_147 ;
V_143 . V_148 = F_107 ( V_44 -> V_353 [ V_361 ] ) ;
V_143 . signal = F_107 ( V_44 -> V_353 [ V_355 ] ) ;
memcpy ( F_70 ( V_21 ) , & V_143 , sizeof( V_143 ) ) ;
F_71 ( V_140 -> V_30 , V_21 ) ;
return 0 ;
V_269:
F_46 ( V_113 L_3 , V_131 ) ;
goto V_201;
V_201:
F_13 ( V_21 ) ;
return - V_272 ;
}
static int F_176 ( struct V_20 * V_348 ,
struct V_349 * V_44 )
{
if ( V_44 == NULL )
goto V_201;
V_175 = V_44 -> V_364 ;
F_46 ( V_113 L_43
L_44 , V_44 -> V_364 ) ;
return 0 ;
V_201:
F_46 ( V_113 L_3 , V_131 ) ;
return - V_272 ;
}
static int F_177 ( struct V_365 * V_366 ,
unsigned long V_367 ,
void * V_368 )
{
struct V_369 * V_370 = V_368 ;
if ( V_367 != V_371 )
return V_372 ;
if ( V_370 -> V_373 == V_175 ) {
F_46 ( V_374 L_45
L_46 ) ;
V_175 = 0 ;
}
return V_372 ;
}
static int F_178 ( void )
{
int V_375 ;
if ( V_172 > 1 )
return 0 ;
F_46 ( V_374 L_47 ) ;
V_375 = F_179 ( & V_111 ,
V_376 , F_180 ( V_376 ) ) ;
if ( V_375 )
goto V_377;
V_375 = F_181 ( & V_378 ) ;
if ( V_375 )
goto V_377;
return 0 ;
V_377:
F_46 ( V_113 L_3 , V_131 ) ;
return - V_272 ;
}
static void F_182 ( void )
{
int V_95 ;
if ( V_172 > 1 )
return;
F_46 ( V_374 L_48 ) ;
F_183 ( & V_378 ) ;
V_95 = F_184 ( & V_111 ) ;
if ( V_95 )
F_46 ( V_113 L_49
L_50 , V_95 ) ;
}
static int T_9 F_185 ( void )
{
int V_101 , V_269 = 0 ;
T_7 V_8 [ V_83 ] ;
struct V_25 * V_26 ;
struct V_29 * V_30 ;
enum V_379 V_147 ;
if ( V_380 < 1 || V_380 > 100 )
return - V_272 ;
if ( V_172 < 1 )
return - V_272 ;
if ( V_172 > 1 ) {
V_381 . V_382 = V_172 ;
V_383 . V_296 = F_128 ;
V_383 . V_384 =
F_129 ;
V_383 . V_385 = NULL ;
V_383 . V_386 = NULL ;
V_383 . V_387 =
F_135 ;
V_383 . V_388 =
F_137 ;
V_383 . V_389 =
F_138 ;
V_383 . V_390 =
F_139 ;
V_383 . V_391 =
F_140 ;
V_383 . V_392 =
F_141 ;
V_383 . V_393 =
F_142 ;
}
F_186 ( & V_159 ) ;
F_144 ( & V_394 ) ;
V_328 = F_187 ( V_395 , L_51 ) ;
if ( F_188 ( V_328 ) )
return F_189 ( V_328 ) ;
memset ( V_8 , 0 , V_83 ) ;
V_8 [ 0 ] = 0x02 ;
for ( V_101 = 0 ; V_101 < V_380 ; V_101 ++ ) {
F_46 ( V_113 L_52 ,
V_101 ) ;
V_30 = F_190 ( sizeof( * V_26 ) , & V_383 ) ;
if ( ! V_30 ) {
F_46 ( V_113 L_53
L_54 ) ;
V_269 = - V_276 ;
goto V_396;
}
V_26 = V_30 -> V_31 ;
V_26 -> V_30 = V_30 ;
V_26 -> V_23 = F_191 ( V_328 , NULL , 0 , V_30 ,
L_55 , V_101 ) ;
if ( F_188 ( V_26 -> V_23 ) ) {
F_46 ( V_113
L_56
L_57 , F_189 ( V_26 -> V_23 ) ) ;
V_269 = - V_276 ;
goto V_397;
}
V_26 -> V_23 -> V_398 = & V_399 ;
F_192 ( & V_26 -> V_106 ) ;
F_193 ( V_30 , V_26 -> V_23 ) ;
V_8 [ 3 ] = V_101 >> 8 ;
V_8 [ 4 ] = V_101 ;
memcpy ( V_26 -> V_116 [ 0 ] . V_8 , V_8 , V_83 ) ;
memcpy ( V_26 -> V_116 [ 1 ] . V_8 , V_8 , V_83 ) ;
V_26 -> V_116 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_30 -> V_90 -> V_400 = 2 ;
V_30 -> V_90 -> V_116 = V_26 -> V_116 ;
V_30 -> V_90 -> V_401 = & V_381 ;
V_30 -> V_90 -> V_402 = 1 ;
if ( V_172 > 1 ) {
V_30 -> V_90 -> V_403 = 255 ;
V_30 -> V_90 -> V_404 = V_363 ;
V_30 -> V_90 -> V_405 = 1000 ;
}
F_194 ( & V_26 -> V_315 , F_133 ) ;
F_194 ( & V_26 -> V_296 , F_119 ) ;
V_30 -> V_406 = 1 ;
V_30 -> V_407 = 5 ;
V_30 -> V_408 = 4 ;
V_30 -> V_90 -> V_409 =
F_195 ( V_410 ) |
F_195 ( V_191 ) |
F_195 ( V_411 ) |
F_195 ( V_412 ) |
F_195 ( V_193 ) |
F_195 ( V_192 ) |
F_195 ( V_413 ) ;
V_30 -> V_42 = V_414 |
V_415 |
V_416 |
V_417 |
V_418 |
V_419 |
V_420 ;
V_30 -> V_90 -> V_42 |= V_421 |
V_422 ;
V_30 -> V_423 = sizeof( struct V_3 ) ;
V_30 -> V_424 = sizeof( struct V_12 ) ;
V_30 -> V_425 = sizeof( struct V_17 ) ;
memcpy ( V_26 -> V_426 , V_427 ,
sizeof( V_427 ) ) ;
memcpy ( V_26 -> V_428 , V_429 ,
sizeof( V_429 ) ) ;
memcpy ( V_26 -> V_126 , V_430 , sizeof( V_430 ) ) ;
for ( V_147 = V_431 ; V_147 < V_432 ; V_147 ++ ) {
struct V_433 * V_434 = & V_26 -> V_435 [ V_147 ] ;
switch ( V_147 ) {
case V_431 :
V_434 -> V_172 = V_26 -> V_426 ;
V_434 -> V_303 =
F_180 ( V_427 ) ;
V_434 -> V_436 = V_26 -> V_126 ;
V_434 -> V_437 = F_180 ( V_430 ) ;
break;
case V_438 :
V_434 -> V_172 = V_26 -> V_428 ;
V_434 -> V_303 =
F_180 ( V_429 ) ;
V_434 -> V_436 = V_26 -> V_126 + 4 ;
V_434 -> V_437 = F_180 ( V_430 ) - 4 ;
break;
default:
continue;
}
V_434 -> V_439 . V_440 = true ;
V_434 -> V_439 . V_441 = V_442 |
V_443 |
V_444 |
V_445 ;
V_434 -> V_439 . V_446 = 0x3 ;
V_434 -> V_439 . V_447 = 0x6 ;
memset ( & V_434 -> V_439 . V_448 , 0 ,
sizeof( V_434 -> V_439 . V_448 ) ) ;
V_434 -> V_439 . V_448 . V_449 [ 0 ] = 0xff ;
V_434 -> V_439 . V_448 . V_449 [ 1 ] = 0xff ;
V_434 -> V_439 . V_448 . V_450 = V_451 ;
V_30 -> V_90 -> V_435 [ V_147 ] = V_434 ;
if ( V_172 == 1 )
continue;
V_434 -> V_452 . V_453 = true ;
V_434 -> V_452 . V_441 =
V_454 |
V_455 |
V_456 |
V_457 |
V_458 |
V_459 |
V_460 |
V_461 |
V_462 |
V_463 |
V_464 ;
V_434 -> V_452 . V_465 . V_466 =
F_29 ( V_467 << 0 |
V_467 << 2 |
V_468 << 4 |
V_467 << 6 |
V_467 << 8 |
V_468 << 10 |
V_468 << 12 |
V_467 << 14 ) ;
V_434 -> V_452 . V_465 . V_469 =
V_434 -> V_452 . V_465 . V_466 ;
}
V_26 -> V_164 = 1 ;
F_196 ( & V_26 -> V_301 ) ;
V_30 -> V_470 = 4 ;
V_30 -> V_471 = 11 ;
switch ( V_472 ) {
case V_473 :
case V_474 :
case V_475 :
case V_476 :
break;
case V_477 :
if ( V_101 == 0 ) {
V_30 -> V_90 -> V_42 |= V_478 ;
F_197 ( V_30 -> V_90 ,
& V_479 ) ;
}
break;
case V_480 :
V_30 -> V_90 -> V_42 |= V_478 ;
F_197 ( V_30 -> V_90 ,
& V_479 ) ;
break;
case V_481 :
if ( V_101 == 0 ) {
V_30 -> V_90 -> V_42 |= V_478 ;
F_197 ( V_30 -> V_90 ,
& V_479 ) ;
} else if ( V_101 == 1 ) {
V_30 -> V_90 -> V_42 |= V_478 ;
F_197 ( V_30 -> V_90 ,
& V_482 ) ;
}
break;
case V_483 :
V_30 -> V_90 -> V_42 |= V_484 ;
break;
case V_485 :
case V_486 :
if ( V_101 == 0 )
V_30 -> V_90 -> V_42 |= V_484 ;
break;
case V_487 :
if ( V_101 == 0 ) {
V_30 -> V_90 -> V_42 |= V_478 ;
F_197 ( V_30 -> V_90 ,
& V_479 ) ;
} else if ( V_101 == 1 ) {
V_30 -> V_90 -> V_42 |= V_478 ;
F_197 ( V_30 -> V_90 ,
& V_482 ) ;
} else if ( V_101 == 4 )
V_30 -> V_90 -> V_42 |= V_484 ;
break;
default:
break;
}
if ( V_472 )
F_198 ( 1 ) ;
V_269 = F_199 ( V_30 ) ;
if ( V_269 < 0 ) {
F_46 ( V_113 L_49
L_58 , V_269 ) ;
goto V_488;
}
switch ( V_472 ) {
case V_477 :
case V_473 :
break;
case V_474 :
if ( ! V_101 )
F_200 ( V_30 -> V_90 , V_489 [ 0 ] ) ;
break;
case V_475 :
case V_483 :
F_200 ( V_30 -> V_90 , V_489 [ 0 ] ) ;
break;
case V_476 :
if ( V_101 < F_180 ( V_489 ) )
F_200 ( V_30 -> V_90 , V_489 [ V_101 ] ) ;
break;
case V_480 :
case V_481 :
break;
case V_485 :
if ( V_101 == 0 )
F_200 ( V_30 -> V_90 , V_489 [ 0 ] ) ;
break;
case V_486 :
if ( V_101 == 0 )
F_200 ( V_30 -> V_90 , V_489 [ 0 ] ) ;
else if ( V_101 == 1 )
F_200 ( V_30 -> V_90 , V_489 [ 1 ] ) ;
break;
case V_487 :
if ( V_101 == 2 )
F_200 ( V_30 -> V_90 , V_489 [ 0 ] ) ;
else if ( V_101 == 3 )
F_200 ( V_30 -> V_90 , V_489 [ 1 ] ) ;
else if ( V_101 == 4 )
F_200 ( V_30 -> V_90 , V_489 [ 2 ] ) ;
break;
default:
break;
}
F_74 ( V_30 -> V_90 , L_59 ,
V_30 -> V_90 -> V_91 ) ;
V_26 -> V_327 = F_201 ( L_60 ,
V_30 -> V_90 -> V_490 ) ;
V_26 -> V_326 = F_202 ( L_61 , 0666 ,
V_26 -> V_327 , V_26 ,
& V_491 ) ;
V_26 -> V_325 = F_202 ( L_62 , 0666 ,
V_26 -> V_327 , V_26 ,
& V_492 ) ;
F_203 ( & V_26 -> V_178 ,
F_89 ,
V_493 , V_202 ) ;
F_204 ( & V_26 -> V_494 , & V_394 ) ;
}
V_47 = F_205 ( 0 , L_55 , F_155 ) ;
if ( V_47 == NULL )
goto V_396;
F_206 () ;
V_269 = F_207 ( V_47 , V_47 -> V_495 ) ;
if ( V_269 < 0 )
goto V_496;
V_269 = F_208 ( V_47 ) ;
if ( V_269 < 0 )
goto V_496;
F_209 () ;
V_269 = F_178 () ;
if ( V_269 < 0 )
goto V_497;
return 0 ;
V_497:
F_46 ( V_113 L_63 ) ;
return V_269 ;
V_496:
F_209 () ;
V_332 ( V_47 ) ;
F_143 () ;
return V_269 ;
V_488:
F_152 ( V_26 -> V_23 ) ;
V_397:
F_153 ( V_30 ) ;
V_396:
F_143 () ;
return V_269 ;
}
static void T_10 F_210 ( void )
{
F_46 ( V_113 L_64 ) ;
F_182 () ;
F_143 () ;
F_211 ( V_47 ) ;
}
