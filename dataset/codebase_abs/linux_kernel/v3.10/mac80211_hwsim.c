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
if ( V_44 -> V_148 . V_126 [ 0 ] . V_42 & V_149 ) {
V_143 . V_150 =
F_57 ( & V_44 -> V_148 . V_126 [ 0 ] ) ;
V_143 . V_151 =
F_58 ( & V_44 -> V_148 . V_126 [ 0 ] ) ;
V_143 . V_144 |= V_152 ;
} else {
V_143 . V_150 = V_44 -> V_148 . V_126 [ 0 ] . V_124 ;
if ( V_44 -> V_148 . V_126 [ 0 ] . V_42 & V_153 )
V_143 . V_144 |= V_154 ;
}
if ( V_44 -> V_148 . V_126 [ 0 ] . V_42 & V_155 )
V_143 . V_144 |= V_156 ;
if ( V_44 -> V_148 . V_126 [ 0 ] . V_42 & V_157 )
V_143 . V_144 |= V_158 ;
V_143 . signal = V_26 -> V_159 - 50 ;
if ( V_26 -> V_84 != V_85 )
V_41 -> V_78 |= F_29 ( V_105 ) ;
F_59 ( V_21 ) ;
F_60 ( V_21 ) ;
V_21 -> V_160 = 0 ;
F_61 ( V_21 ) ;
F_62 ( V_21 ) ;
if ( F_63 ( V_41 -> V_78 ) ||
F_64 ( V_41 -> V_78 ) )
V_27 = V_26 -> V_161 ;
else
V_27 = F_14 () ;
F_65 ( & V_162 ) ;
F_66 (data2, &hwsim_radios, list) {
struct V_20 * V_163 ;
struct V_135 V_135 = {
. V_139 = false ,
. V_137 = V_39 ,
} ;
if ( V_26 == V_140 )
continue;
if ( ! V_140 -> V_164 || ( V_140 -> V_165 && ! V_140 -> V_166 ) ||
! F_37 ( V_140 , V_21 ) )
continue;
if ( ! ( V_26 -> V_167 & V_140 -> V_167 ) )
continue;
if ( ! F_53 ( V_39 , V_140 -> V_166 ) &&
! F_53 ( V_39 , V_140 -> V_137 ) ) {
F_40 (
V_140 -> V_30 , V_96 ,
F_54 , & V_135 ) ;
if ( ! V_135 . V_139 )
continue;
}
if ( V_21 -> V_118 < V_168 && V_169 ) {
struct V_170 * V_170 = F_67 ( V_48 ) ;
if ( ! V_170 )
continue;
V_163 = F_35 ( 128 ) ;
if ( ! V_163 ) {
F_68 ( V_170 ) ;
continue;
}
memcpy ( F_69 ( V_170 ) , V_21 -> V_26 , V_21 -> V_118 ) ;
F_70 ( V_163 , 0 , V_170 , 0 , V_21 -> V_118 , V_21 -> V_118 ) ;
} else {
V_163 = F_71 ( V_21 , V_48 ) ;
if ( ! V_163 )
continue;
}
if ( F_39 ( V_140 , V_41 -> V_82 ) )
V_141 = true ;
V_143 . V_171 = V_27 + V_140 -> V_28 ;
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
memcpy ( F_72 ( V_163 ) , & V_143 , sizeof( V_143 ) ) ;
F_73 ( V_140 -> V_30 , V_163 ) ;
}
F_74 ( & V_162 ) ;
return V_141 ;
}
static void F_75 ( struct V_29 * V_30 ,
struct V_172 * V_148 ,
struct V_20 * V_21 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
struct V_43 * V_173 = F_24 ( V_21 ) ;
struct V_15 * V_136 ;
struct V_38 * V_137 ;
bool V_141 ;
T_4 V_174 ;
if ( F_6 ( V_21 -> V_118 < 10 ) ) {
F_13 ( V_21 ) ;
return;
}
if ( V_175 == 1 ) {
V_137 = V_26 -> V_137 ;
} else if ( V_173 -> V_176 == 4 ) {
V_137 = V_26 -> V_166 ;
} else {
V_136 = F_55 ( V_173 -> V_148 . V_2 -> V_136 ) ;
if ( V_136 )
V_137 = V_136 -> V_138 . V_39 ;
else
V_137 = NULL ;
}
if ( F_2 ( ! V_137 , L_4 , V_173 -> V_176 ) ) {
F_13 ( V_21 ) ;
return;
}
if ( V_26 -> V_165 && ! V_26 -> V_166 ) {
F_76 ( V_30 -> V_90 , L_5 ) ;
F_13 ( V_21 ) ;
return;
}
if ( V_173 -> V_148 . V_2 )
F_1 ( V_173 -> V_148 . V_2 ) ;
if ( V_148 -> V_11 )
F_5 ( V_148 -> V_11 ) ;
if ( V_177 )
F_77 ( V_173 -> V_148 . V_2 , V_148 -> V_11 , V_21 ,
V_173 -> V_148 . V_126 ,
F_78 ( V_173 -> V_148 . V_126 ) ) ;
V_173 -> V_178 [ 0 ] = V_137 ;
F_23 ( V_30 , V_21 , V_137 ) ;
V_174 = F_79 ( V_179 ) ;
if ( V_174 )
return F_41 ( V_30 , V_21 , V_174 ) ;
V_141 = F_56 ( V_30 , V_21 , V_137 ) ;
if ( V_141 && V_21 -> V_118 >= 16 ) {
struct V_76 * V_41 = (struct V_76 * ) V_21 -> V_26 ;
F_34 ( V_137 , V_41 -> V_180 ) ;
}
F_80 ( V_173 ) ;
V_173 -> V_148 . V_126 [ 0 ] . V_127 = 1 ;
V_173 -> V_148 . V_126 [ 1 ] . V_124 = - 1 ;
if ( ! ( V_173 -> V_42 & V_121 ) && V_141 )
V_173 -> V_42 |= V_181 ;
F_81 ( V_30 , V_21 ) ;
}
static int F_82 ( struct V_29 * V_30 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
F_76 ( V_30 -> V_90 , L_6 , V_131 ) ;
V_26 -> V_164 = true ;
return 0 ;
}
static void F_83 ( struct V_29 * V_30 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
V_26 -> V_164 = false ;
F_84 ( & V_26 -> V_182 ) ;
F_76 ( V_30 -> V_90 , L_6 , V_131 ) ;
}
static int F_85 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
F_76 ( V_30 -> V_90 , L_7 ,
V_131 , F_86 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_183 = 0 ;
V_2 -> V_176 [ V_184 ] = 0 ;
V_2 -> V_176 [ V_185 ] = 1 ;
V_2 -> V_176 [ V_186 ] = 2 ;
V_2 -> V_176 [ V_187 ] = 3 ;
return 0 ;
}
static int F_87 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
enum V_188 V_189 ,
bool V_190 )
{
V_189 = F_88 ( V_189 , V_190 ) ;
F_76 ( V_30 -> V_90 ,
L_8 ,
V_131 , F_86 ( V_2 ) ,
V_189 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
V_2 -> V_183 = 0 ;
return 0 ;
}
static void F_89 (
struct V_29 * V_30 , struct V_1 * V_2 )
{
F_76 ( V_30 -> V_90 , L_7 ,
V_131 , F_86 ( V_2 ) ,
V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_90 ( struct V_29 * V_30 ,
struct V_20 * V_21 ,
struct V_38 * V_39 )
{
T_4 V_191 = F_79 ( V_179 ) ;
if ( V_177 ) {
struct V_43 * V_173 = F_24 ( V_21 ) ;
F_77 ( V_173 -> V_148 . V_2 , NULL , V_21 ,
V_173 -> V_148 . V_126 ,
F_78 ( V_173 -> V_148 . V_126 ) ) ;
}
F_23 ( V_30 , V_21 , V_39 ) ;
if ( V_191 )
return F_41 ( V_30 , V_21 , V_191 ) ;
F_56 ( V_30 , V_21 , V_39 ) ;
F_13 ( V_21 ) ;
}
static void F_91 ( void * V_192 , T_7 * V_92 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_192 ;
struct V_29 * V_30 = V_26 -> V_30 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_193 * V_194 ;
struct V_20 * V_21 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_195 &&
V_2 -> type != V_196 &&
V_2 -> type != V_197 )
return;
V_21 = F_92 ( V_30 , V_2 ) ;
if ( V_21 == NULL )
return;
V_44 = F_24 ( V_21 ) ;
if ( V_177 )
F_77 ( V_2 , NULL , V_21 ,
V_44 -> V_148 . V_126 ,
F_78 ( V_44 -> V_148 . V_126 ) ) ;
V_46 = F_25 ( V_30 , V_44 ) ;
V_194 = (struct V_193 * ) V_21 -> V_26 ;
V_26 -> V_161 = F_14 () ;
V_194 -> V_198 . V_199 . V_200 = F_18 ( V_26 -> V_161 +
V_26 -> V_28 +
24 * 8 * 10 / V_46 -> V_61 ) ;
F_90 ( V_30 , V_21 ,
F_55 ( V_2 -> V_136 ) -> V_138 . V_39 ) ;
}
static enum V_201
F_93 ( struct V_202 * V_203 )
{
struct V_25 * V_26 =
F_94 ( V_203 , struct V_25 ,
V_182 . V_203 ) ;
struct V_29 * V_30 = V_26 -> V_30 ;
T_2 V_33 = V_26 -> V_34 ;
T_8 V_204 ;
if ( ! V_26 -> V_164 )
goto V_205;
F_40 (
V_30 , V_96 ,
F_91 , V_26 ) ;
if ( V_26 -> V_36 ) {
V_33 -= V_26 -> V_36 ;
V_26 -> V_36 = 0 ;
}
V_204 = F_95 ( F_96 ( V_203 ) ,
F_97 ( V_33 * 1000 ) ) ;
F_98 ( & V_26 -> V_182 , V_204 , V_206 ) ;
V_205:
return V_207 ;
}
static int F_99 ( struct V_29 * V_30 , T_4 V_208 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
struct V_209 * V_210 = & V_30 -> V_210 ;
static const char * V_211 [ V_212 ] = {
[ V_213 ] = L_9 ,
[ V_214 ] = L_10 ,
[ V_215 ] = L_11 ,
[ V_216 ] = L_12 ,
} ;
if ( V_210 -> V_217 . V_39 )
F_76 ( V_30 -> V_90 ,
L_13 ,
V_131 ,
V_210 -> V_217 . V_39 -> V_63 ,
V_210 -> V_217 . V_218 ,
V_210 -> V_217 . V_219 ,
V_220 [ V_210 -> V_217 . V_221 ] ,
! ! ( V_210 -> V_42 & V_222 ) ,
! ! ( V_210 -> V_42 & V_223 ) ,
V_211 [ V_210 -> V_224 ] ) ;
else
F_76 ( V_30 -> V_90 ,
L_14 ,
V_131 ,
! ! ( V_210 -> V_42 & V_222 ) ,
! ! ( V_210 -> V_42 & V_223 ) ,
V_211 [ V_210 -> V_224 ] ) ;
V_26 -> V_165 = ! ! ( V_210 -> V_42 & V_222 ) ;
V_26 -> V_137 = V_210 -> V_217 . V_39 ;
F_6 ( V_26 -> V_137 && V_175 > 1 ) ;
V_26 -> V_159 = V_210 -> V_159 ;
if ( ! V_26 -> V_164 || ! V_26 -> V_34 )
F_84 ( & V_26 -> V_182 ) ;
else if ( ! F_100 ( & V_26 -> V_182 . V_203 ) ) {
T_2 V_32 = F_19 ( V_30 , NULL ) ;
T_4 V_33 = V_26 -> V_34 ;
T_2 V_225 = V_33 - F_22 ( V_32 , V_33 ) ;
F_98 ( & V_26 -> V_182 ,
F_97 ( V_225 * 1000 ) ,
V_226 ) ;
}
return 0 ;
}
static void F_101 ( struct V_29 * V_30 ,
unsigned int V_227 ,
unsigned int * V_228 , T_2 V_229 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
F_76 ( V_30 -> V_90 , L_6 , V_131 ) ;
V_26 -> V_230 = 0 ;
if ( * V_228 & V_231 )
V_26 -> V_230 |= V_231 ;
if ( * V_228 & V_232 )
V_26 -> V_230 |= V_232 ;
* V_228 = V_26 -> V_230 ;
}
static void F_102 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_233 * V_44 ,
T_4 V_208 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_25 * V_26 = V_30 -> V_31 ;
F_1 ( V_2 ) ;
F_76 ( V_30 -> V_90 , L_15 , V_131 , V_208 ) ;
if ( V_208 & V_234 ) {
F_76 ( V_30 -> V_90 , L_16 ,
V_131 , V_44 -> V_235 ) ;
memcpy ( V_4 -> V_235 , V_44 -> V_235 , V_83 ) ;
}
if ( V_208 & V_236 ) {
F_76 ( V_30 -> V_90 , L_17 ,
V_44 -> V_237 , V_44 -> V_238 ) ;
V_4 -> V_237 = V_44 -> V_237 ;
V_4 -> V_238 = V_44 -> V_238 ;
}
if ( V_208 & V_239 ) {
F_76 ( V_30 -> V_90 , L_18 , V_44 -> V_34 ) ;
V_26 -> V_34 = V_44 -> V_34 * 1024 ;
}
if ( V_208 & V_240 ) {
F_76 ( V_30 -> V_90 , L_19 , V_44 -> V_241 ) ;
if ( V_26 -> V_164 &&
! F_100 ( & V_26 -> V_182 . V_203 ) &&
V_44 -> V_241 ) {
T_2 V_32 , V_225 ;
T_4 V_33 ;
if ( F_6 ( ! V_26 -> V_34 ) )
V_26 -> V_34 = 1000 * 1024 ;
V_32 = F_19 ( V_30 , V_2 ) ;
V_33 = V_26 -> V_34 ;
V_225 = V_33 - F_22 ( V_32 , V_33 ) ;
F_98 ( & V_26 -> V_182 ,
F_97 ( V_225 * 1000 ) ,
V_226 ) ;
} else if ( ! V_44 -> V_241 )
F_84 ( & V_26 -> V_182 ) ;
}
if ( V_208 & V_242 ) {
F_76 ( V_30 -> V_90 , L_20 ,
V_44 -> V_243 ) ;
}
if ( V_208 & V_244 ) {
F_76 ( V_30 -> V_90 , L_21 ,
V_44 -> V_245 ) ;
}
if ( V_208 & V_246 ) {
F_76 ( V_30 -> V_90 , L_22 , V_44 -> V_247 ) ;
}
if ( V_208 & V_248 ) {
F_76 ( V_30 -> V_90 , L_23 ,
V_44 -> V_249 ) ;
}
if ( V_208 & V_250 ) {
F_76 ( V_30 -> V_90 , L_24 ,
( unsigned long long ) V_44 -> V_251 ) ;
}
if ( V_208 & V_252 )
F_76 ( V_30 -> V_90 , L_25 , V_44 -> V_253 ) ;
}
static int F_103 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_104 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_105 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
enum V_254 V_255 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_255 ) {
case V_256 :
case V_257 :
break;
default:
F_2 ( 1 , L_26 , V_255 ) ;
break;
}
}
static int F_106 ( struct V_29 * V_30 ,
struct V_10 * V_11 ,
bool V_258 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_107 (
struct V_29 * V_30 ,
struct V_1 * V_2 , T_6 V_259 ,
const struct V_260 * V_261 )
{
F_76 ( V_30 -> V_90 ,
L_27 ,
V_131 , V_259 ,
V_261 -> V_262 , V_261 -> V_263 ,
V_261 -> V_264 , V_261 -> V_265 ) ;
return 0 ;
}
static int F_108 (
struct V_29 * V_30 , int V_124 ,
struct V_266 * V_267 )
{
struct V_209 * V_210 = & V_30 -> V_210 ;
F_76 ( V_30 -> V_90 , L_28 , V_131 , V_124 ) ;
if ( V_124 != 0 )
return - V_268 ;
V_267 -> V_137 = V_210 -> V_217 . V_39 ;
V_267 -> V_269 = V_270 ;
V_267 -> V_271 = - 92 ;
return 0 ;
}
static int F_109 ( struct V_29 * V_30 ,
void * V_26 , int V_118 )
{
struct V_25 * V_272 = V_30 -> V_31 ;
struct V_273 * V_274 [ V_275 + 1 ] ;
struct V_20 * V_21 ;
int V_276 , V_84 ;
V_276 = F_110 ( V_274 , V_275 , V_26 , V_118 ,
V_277 ) ;
if ( V_276 )
return V_276 ;
if ( ! V_274 [ V_278 ] )
return - V_279 ;
switch ( F_111 ( V_274 [ V_278 ] ) ) {
case V_280 :
if ( ! V_274 [ V_281 ] )
return - V_279 ;
V_84 = F_111 ( V_274 [ V_281 ] ) ;
return F_112 ( V_272 , V_84 ) ;
case V_282 :
V_21 = F_113 ( V_30 -> V_90 ,
F_114 ( sizeof( T_4 ) ) ) ;
if ( ! V_21 )
return - V_283 ;
if ( F_48 ( V_21 , V_281 , V_272 -> V_84 ) )
goto V_110;
return F_115 ( V_21 ) ;
case V_284 :
F_116 ( V_30 ) ;
return 0 ;
case V_285 :
F_117 ( V_30 ) ;
return 0 ;
default:
return - V_286 ;
}
V_110:
F_118 ( V_21 ) ;
return - V_287 ;
}
static int F_119 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
enum V_288 V_289 ,
struct V_10 * V_11 , T_6 V_290 , T_6 * V_291 ,
T_7 V_292 )
{
switch ( V_289 ) {
case V_293 :
F_120 ( V_2 , V_11 -> V_8 , V_290 ) ;
break;
case V_294 :
case V_295 :
case V_296 :
F_121 ( V_2 , V_11 -> V_8 , V_290 ) ;
break;
case V_297 :
break;
case V_298 :
case V_299 :
break;
default:
return - V_286 ;
}
return 0 ;
}
static void F_122 ( struct V_29 * V_30 , T_4 V_300 , bool V_301 )
{
}
static void F_123 ( struct V_302 * V_303 )
{
struct V_25 * V_272 =
F_94 ( V_303 , struct V_25 , V_304 . V_303 ) ;
struct V_305 * V_306 = V_272 -> V_307 ;
int V_308 , V_101 ;
F_124 ( & V_272 -> V_309 ) ;
if ( V_272 -> V_310 >= V_306 -> V_311 ) {
F_76 ( V_272 -> V_30 -> V_90 , L_29 ) ;
F_125 ( V_272 -> V_30 , false ) ;
V_272 -> V_307 = NULL ;
V_272 -> V_312 = NULL ;
V_272 -> V_166 = NULL ;
F_126 ( & V_272 -> V_309 ) ;
return;
}
F_76 ( V_272 -> V_30 -> V_90 , L_30 ,
V_306 -> V_175 [ V_272 -> V_310 ] -> V_63 ) ;
V_272 -> V_166 = V_306 -> V_175 [ V_272 -> V_310 ] ;
if ( V_272 -> V_166 -> V_42 & V_313 ||
! V_306 -> V_314 ) {
V_308 = 120 ;
} else {
V_308 = 30 ;
for ( V_101 = 0 ; V_101 < V_306 -> V_314 ; V_101 ++ ) {
struct V_20 * V_315 ;
V_315 = F_127 ( V_272 -> V_30 ,
V_272 -> V_312 ,
V_306 -> V_316 [ V_101 ] . V_317 ,
V_306 -> V_316 [ V_101 ] . V_318 ,
V_306 -> V_319 ) ;
if ( ! V_315 )
continue;
if ( V_306 -> V_319 )
memcpy ( F_36 ( V_315 , V_306 -> V_319 ) , V_306 -> V_320 ,
V_306 -> V_319 ) ;
F_128 () ;
F_90 ( V_272 -> V_30 , V_315 ,
V_272 -> V_166 ) ;
F_129 () ;
}
}
F_130 ( V_272 -> V_30 , & V_272 -> V_304 ,
F_131 ( V_308 ) ) ;
V_272 -> V_310 ++ ;
F_126 ( & V_272 -> V_309 ) ;
}
static int F_132 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_305 * V_306 )
{
struct V_25 * V_272 = V_30 -> V_31 ;
F_124 ( & V_272 -> V_309 ) ;
if ( F_6 ( V_272 -> V_166 || V_272 -> V_307 ) ) {
F_126 ( & V_272 -> V_309 ) ;
return - V_321 ;
}
V_272 -> V_307 = V_306 ;
V_272 -> V_312 = V_2 ;
V_272 -> V_310 = 0 ;
F_126 ( & V_272 -> V_309 ) ;
F_76 ( V_30 -> V_90 , L_31 ) ;
F_130 ( V_272 -> V_30 , & V_272 -> V_304 , 0 ) ;
return 0 ;
}
static void F_133 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
struct V_25 * V_272 = V_30 -> V_31 ;
F_76 ( V_30 -> V_90 , L_32 ) ;
F_134 ( & V_272 -> V_304 ) ;
F_124 ( & V_272 -> V_309 ) ;
F_125 ( V_272 -> V_30 , true ) ;
V_272 -> V_166 = NULL ;
V_272 -> V_307 = NULL ;
V_272 -> V_312 = NULL ;
F_126 ( & V_272 -> V_309 ) ;
}
static void F_135 ( struct V_29 * V_30 )
{
struct V_25 * V_272 = V_30 -> V_31 ;
F_124 ( & V_272 -> V_309 ) ;
if ( V_272 -> V_322 ) {
F_46 ( V_113 L_33 ) ;
goto V_205;
}
F_46 ( V_113 L_34 ) ;
V_272 -> V_322 = true ;
V_205:
F_126 ( & V_272 -> V_309 ) ;
}
static void F_136 ( struct V_29 * V_30 )
{
struct V_25 * V_272 = V_30 -> V_31 ;
F_124 ( & V_272 -> V_309 ) ;
F_46 ( V_113 L_35 ) ;
V_272 -> V_322 = false ;
F_126 ( & V_272 -> V_309 ) ;
}
static void F_137 ( struct V_302 * V_303 )
{
struct V_25 * V_272 =
F_94 ( V_303 , struct V_25 , V_323 . V_303 ) ;
F_124 ( & V_272 -> V_309 ) ;
F_138 ( V_272 -> V_30 ) ;
V_272 -> V_166 = NULL ;
F_126 ( & V_272 -> V_309 ) ;
F_76 ( V_272 -> V_30 -> V_90 , L_36 ) ;
}
static int F_139 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_38 * V_39 ,
int V_324 ,
enum V_325 type )
{
struct V_25 * V_272 = V_30 -> V_31 ;
F_124 ( & V_272 -> V_309 ) ;
if ( F_6 ( V_272 -> V_166 || V_272 -> V_307 ) ) {
F_126 ( & V_272 -> V_309 ) ;
return - V_321 ;
}
V_272 -> V_166 = V_39 ;
F_126 ( & V_272 -> V_309 ) ;
F_76 ( V_30 -> V_90 , L_37 ,
V_39 -> V_63 , V_324 ) ;
F_140 ( V_30 ) ;
F_130 ( V_30 , & V_272 -> V_323 ,
F_131 ( V_324 ) ) ;
return 0 ;
}
static int F_141 ( struct V_29 * V_30 )
{
struct V_25 * V_272 = V_30 -> V_31 ;
F_134 ( & V_272 -> V_323 ) ;
F_124 ( & V_272 -> V_309 ) ;
V_272 -> V_166 = NULL ;
F_126 ( & V_272 -> V_309 ) ;
F_76 ( V_30 -> V_90 , L_38 ) ;
return 0 ;
}
static int F_142 ( struct V_29 * V_30 ,
struct V_15 * V_326 )
{
F_10 ( V_326 ) ;
F_76 ( V_30 -> V_90 ,
L_39 ,
V_326 -> V_138 . V_39 -> V_63 , V_326 -> V_138 . V_221 ,
V_326 -> V_138 . V_218 , V_326 -> V_138 . V_219 ) ;
return 0 ;
}
static void F_143 ( struct V_29 * V_30 ,
struct V_15 * V_326 )
{
F_76 ( V_30 -> V_90 ,
L_40 ,
V_326 -> V_138 . V_39 -> V_63 , V_326 -> V_138 . V_221 ,
V_326 -> V_138 . V_218 , V_326 -> V_138 . V_219 ) ;
F_9 ( V_326 ) ;
F_11 ( V_326 ) ;
}
static void F_144 ( struct V_29 * V_30 ,
struct V_15 * V_326 ,
T_4 V_208 )
{
F_9 ( V_326 ) ;
F_76 ( V_30 -> V_90 ,
L_41 ,
V_326 -> V_138 . V_39 -> V_63 , V_326 -> V_138 . V_221 ,
V_326 -> V_138 . V_218 , V_326 -> V_138 . V_219 ) ;
}
static int F_145 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_15 * V_326 )
{
F_1 ( V_2 ) ;
F_9 ( V_326 ) ;
return 0 ;
}
static void F_146 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_15 * V_326 )
{
F_1 ( V_2 ) ;
F_9 ( V_326 ) ;
}
static void F_147 ( void )
{
struct V_327 V_328 , * V_101 , * V_329 ;
struct V_25 * V_26 , * V_330 ;
F_148 ( & V_328 ) ;
F_149 ( & V_162 ) ;
F_150 (i, tmp, &hwsim_radios)
F_151 ( V_101 , & V_328 ) ;
F_152 ( & V_162 ) ;
F_153 (data, tmpdata, &tmplist, list) {
F_154 ( V_26 -> V_331 ) ;
F_154 ( V_26 -> V_332 ) ;
F_154 ( V_26 -> V_333 ) ;
F_155 ( V_26 -> V_30 ) ;
F_156 ( V_26 -> V_23 ) ;
F_157 ( V_26 -> V_23 ) ;
F_158 ( V_26 -> V_30 ) ;
}
F_159 ( V_334 ) ;
}
static void F_160 ( struct V_22 * V_23 )
{
V_23 -> V_335 = & V_336 ;
V_23 -> V_337 = V_338 ;
F_161 ( V_23 ) ;
V_23 -> V_339 = 0 ;
V_23 -> type = V_340 ;
memset ( V_23 -> V_341 , 0 , V_83 ) ;
V_23 -> V_341 [ 0 ] = 0x12 ;
}
static void F_162 ( void * V_342 , T_7 * V_92 , struct V_1 * V_2 )
{
struct V_25 * V_26 = V_342 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_343 * V_344 ;
if ( ! V_4 -> V_237 )
return;
F_76 ( V_26 -> V_30 -> V_90 ,
L_42 ,
V_131 , V_4 -> V_235 , V_4 -> V_238 ) ;
V_21 = F_35 ( sizeof( * V_344 ) ) ;
if ( ! V_21 )
return;
V_344 = ( void * ) F_36 ( V_21 , sizeof( * V_344 ) ) ;
V_344 -> V_78 = F_29 ( V_79 |
V_345 |
V_105 ) ;
V_344 -> V_238 = F_29 ( 0xc000 | V_4 -> V_238 ) ;
memcpy ( V_344 -> V_235 , V_4 -> V_235 , V_83 ) ;
memcpy ( V_344 -> V_346 , V_92 , V_83 ) ;
F_163 () ;
F_90 ( V_26 -> V_30 , V_21 ,
F_55 ( V_2 -> V_136 ) -> V_138 . V_39 ) ;
F_164 () ;
}
static void F_165 ( struct V_25 * V_26 , T_7 * V_92 ,
struct V_1 * V_2 , int V_84 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_76 * V_41 ;
if ( ! V_4 -> V_237 )
return;
F_76 ( V_26 -> V_30 -> V_90 ,
L_43 ,
V_131 , V_4 -> V_235 , V_84 ) ;
V_21 = F_35 ( sizeof( * V_41 ) ) ;
if ( ! V_21 )
return;
V_41 = ( void * ) F_36 ( V_21 , sizeof( * V_41 ) - V_83 ) ;
V_41 -> V_78 = F_29 ( V_347 |
V_348 |
( V_84 ? V_105 : 0 ) ) ;
V_41 -> V_81 = F_29 ( 0 ) ;
memcpy ( V_41 -> V_82 , V_4 -> V_235 , V_83 ) ;
memcpy ( V_41 -> V_180 , V_92 , V_83 ) ;
memcpy ( V_41 -> V_349 , V_4 -> V_235 , V_83 ) ;
F_163 () ;
F_90 ( V_26 -> V_30 , V_21 ,
F_55 ( V_2 -> V_136 ) -> V_138 . V_39 ) ;
F_164 () ;
}
static void F_166 ( void * V_342 , T_7 * V_92 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_342 ;
F_165 ( V_26 , V_92 , V_2 , 1 ) ;
}
static void F_167 ( void * V_342 , T_7 * V_92 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_342 ;
F_165 ( V_26 , V_92 , V_2 , 0 ) ;
}
static int F_168 ( void * V_342 , T_2 * V_350 )
{
struct V_25 * V_26 = V_342 ;
* V_350 = V_26 -> V_84 ;
return 0 ;
}
static int F_112 ( void * V_342 , T_2 V_350 )
{
struct V_25 * V_26 = V_342 ;
enum V_351 V_352 ;
if ( V_350 != V_85 && V_350 != V_86 && V_350 != V_87 &&
V_350 != V_88 )
return - V_279 ;
V_352 = V_26 -> V_84 ;
V_26 -> V_84 = V_350 ;
if ( V_350 == V_88 ) {
F_169 ( V_26 -> V_30 ,
V_96 ,
F_162 , V_26 ) ;
V_26 -> V_89 = true ;
} else if ( V_352 == V_85 && V_350 != V_85 ) {
F_169 ( V_26 -> V_30 ,
V_96 ,
F_166 ,
V_26 ) ;
} else if ( V_352 != V_85 && V_350 == V_85 ) {
F_169 ( V_26 -> V_30 ,
V_96 ,
F_167 ,
V_26 ) ;
}
return 0 ;
}
static int F_170 ( void * V_342 , T_2 * V_350 )
{
struct V_25 * V_26 = V_342 ;
* V_350 = V_26 -> V_167 ;
return 0 ;
}
static int F_171 ( void * V_342 , T_2 V_350 )
{
struct V_25 * V_26 = V_342 ;
V_26 -> V_167 = V_350 ;
return 0 ;
}
static struct V_25 * F_172 (
struct V_115 * V_8 )
{
struct V_25 * V_26 ;
bool V_353 = false ;
F_149 ( & V_162 ) ;
F_66 (data, &hwsim_radios, list) {
if ( memcmp ( V_26 -> V_116 [ 1 ] . V_8 , V_8 ,
sizeof( struct V_115 ) ) == 0 ) {
V_353 = true ;
break;
}
}
F_152 ( & V_162 ) ;
if ( ! V_353 )
return NULL ;
return V_26 ;
}
static int F_173 ( struct V_20 * V_354 ,
struct V_355 * V_44 )
{
struct V_76 * V_41 ;
struct V_25 * V_140 ;
struct V_43 * V_173 ;
struct V_102 * V_103 ;
unsigned long V_356 ;
struct V_20 * V_21 , * V_329 ;
struct V_115 * V_357 ;
unsigned int V_100 ;
int V_101 ;
bool V_358 = false ;
if ( ! V_44 -> V_359 [ V_114 ] ||
! V_44 -> V_359 [ V_123 ] ||
! V_44 -> V_359 [ V_129 ] ||
! V_44 -> V_359 [ V_128 ] )
goto V_205;
V_357 = (struct V_115 * ) F_174 (
V_44 -> V_359 [ V_114 ] ) ;
V_100 = F_111 ( V_44 -> V_359 [ V_123 ] ) ;
V_356 = F_175 ( V_44 -> V_359 [ V_129 ] ) ;
V_140 = F_172 ( V_357 ) ;
if ( V_140 == NULL )
goto V_205;
F_176 (&data2->pending, skb, tmp) {
if ( ( unsigned long ) V_21 == V_356 ) {
F_177 ( V_21 , & V_140 -> V_106 ) ;
V_358 = true ;
break;
}
}
if ( ! V_358 )
goto V_205;
V_103 = (struct V_102 * ) F_174 (
V_44 -> V_359 [ V_128 ] ) ;
V_173 = F_24 ( V_21 ) ;
F_80 ( V_173 ) ;
for ( V_101 = 0 ; V_101 < V_104 ; V_101 ++ ) {
V_173 -> V_125 . V_126 [ V_101 ] . V_124 = V_103 [ V_101 ] . V_124 ;
V_173 -> V_125 . V_126 [ V_101 ] . V_127 = V_103 [ V_101 ] . V_127 ;
}
V_173 -> V_125 . V_360 = F_111 ( V_44 -> V_359 [ V_361 ] ) ;
if ( ! ( V_100 & V_122 ) &&
( V_100 & V_362 ) ) {
if ( V_21 -> V_118 >= 16 ) {
V_41 = (struct V_76 * ) V_21 -> V_26 ;
F_34 ( V_173 -> V_178 [ 0 ] ,
V_41 -> V_180 ) ;
}
V_173 -> V_42 |= V_181 ;
}
F_81 ( V_140 -> V_30 , V_21 ) ;
return 0 ;
V_205:
return - V_279 ;
}
static int F_178 ( struct V_20 * V_354 ,
struct V_355 * V_44 )
{
struct V_25 * V_140 ;
struct V_142 V_143 ;
struct V_115 * V_363 ;
int V_364 ;
char * V_365 ;
struct V_20 * V_21 = NULL ;
if ( ! V_44 -> V_359 [ V_366 ] ||
! V_44 -> V_359 [ V_117 ] ||
! V_44 -> V_359 [ V_367 ] ||
! V_44 -> V_359 [ V_361 ] )
goto V_205;
V_363 = (struct V_115 * ) F_174 (
V_44 -> V_359 [ V_366 ] ) ;
V_364 = F_179 ( V_44 -> V_359 [ V_117 ] ) ;
V_365 = ( char * ) F_174 ( V_44 -> V_359 [ V_117 ] ) ;
V_21 = F_180 ( V_364 , V_368 ) ;
if ( V_21 == NULL )
goto V_276;
if ( V_364 <= V_369 ) {
memcpy ( F_36 ( V_21 , V_364 ) , V_365 ,
V_364 ) ;
} else
goto V_276;
V_140 = F_172 ( V_363 ) ;
if ( V_140 == NULL )
goto V_205;
if ( V_140 -> V_165 || ! V_140 -> V_164 )
goto V_205;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
V_143 . V_146 = V_140 -> V_137 -> V_63 ;
V_143 . V_147 = V_140 -> V_137 -> V_147 ;
V_143 . V_150 = F_111 ( V_44 -> V_359 [ V_367 ] ) ;
V_143 . signal = F_111 ( V_44 -> V_359 [ V_361 ] ) ;
memcpy ( F_72 ( V_21 ) , & V_143 , sizeof( V_143 ) ) ;
F_73 ( V_140 -> V_30 , V_21 ) ;
return 0 ;
V_276:
F_46 ( V_113 L_3 , V_131 ) ;
goto V_205;
V_205:
F_13 ( V_21 ) ;
return - V_279 ;
}
static int F_181 ( struct V_20 * V_354 ,
struct V_355 * V_44 )
{
if ( V_44 == NULL )
goto V_205;
V_179 = V_44 -> V_370 ;
F_46 ( V_113 L_44
L_45 , V_44 -> V_370 ) ;
return 0 ;
V_205:
F_46 ( V_113 L_3 , V_131 ) ;
return - V_279 ;
}
static int F_182 ( struct V_371 * V_372 ,
unsigned long V_373 ,
void * V_374 )
{
struct V_375 * V_376 = V_374 ;
if ( V_373 != V_377 )
return V_378 ;
if ( V_376 -> V_379 == V_179 ) {
F_46 ( V_380 L_46
L_47 ) ;
V_179 = 0 ;
}
return V_378 ;
}
static int F_183 ( void )
{
int V_381 ;
if ( V_175 > 1 )
return 0 ;
F_46 ( V_380 L_48 ) ;
V_381 = F_184 ( & V_111 ,
V_382 , F_78 ( V_382 ) ) ;
if ( V_381 )
goto V_383;
V_381 = F_185 ( & V_384 ) ;
if ( V_381 )
goto V_383;
return 0 ;
V_383:
F_46 ( V_113 L_3 , V_131 ) ;
return - V_279 ;
}
static void F_186 ( void )
{
int V_95 ;
if ( V_175 > 1 )
return;
F_46 ( V_380 L_49 ) ;
F_187 ( & V_384 ) ;
V_95 = F_188 ( & V_111 ) ;
if ( V_95 )
F_46 ( V_113 L_50
L_51 , V_95 ) ;
}
static int T_9 F_189 ( void )
{
int V_101 , V_276 = 0 ;
T_7 V_8 [ V_83 ] ;
struct V_25 * V_26 ;
struct V_29 * V_30 ;
enum V_385 V_147 ;
if ( V_386 < 1 || V_386 > 100 )
return - V_279 ;
if ( V_175 < 1 )
return - V_279 ;
if ( V_175 > 1 ) {
V_387 . V_388 = V_175 ;
V_389 . V_304 = F_132 ;
V_389 . V_390 =
F_133 ;
V_389 . V_391 = NULL ;
V_389 . V_392 = NULL ;
V_389 . V_393 =
F_139 ;
V_389 . V_394 =
F_141 ;
V_389 . V_395 =
F_142 ;
V_389 . V_396 =
F_143 ;
V_389 . V_397 =
F_144 ;
V_389 . V_398 =
F_145 ;
V_389 . V_399 =
F_146 ;
}
F_190 ( & V_162 ) ;
F_148 ( & V_400 ) ;
V_276 = F_191 ( & V_401 ) ;
if ( V_276 )
return V_276 ;
V_334 = F_192 ( V_402 , L_52 ) ;
if ( F_193 ( V_334 ) ) {
V_276 = F_194 ( V_334 ) ;
goto V_403;
}
memset ( V_8 , 0 , V_83 ) ;
V_8 [ 0 ] = 0x02 ;
for ( V_101 = 0 ; V_101 < V_386 ; V_101 ++ ) {
F_46 ( V_113 L_53 ,
V_101 ) ;
V_30 = F_195 ( sizeof( * V_26 ) , & V_389 ) ;
if ( ! V_30 ) {
F_46 ( V_113 L_54
L_55 ) ;
V_276 = - V_283 ;
goto V_404;
}
V_26 = V_30 -> V_31 ;
V_26 -> V_30 = V_30 ;
V_26 -> V_23 = F_196 ( V_334 , NULL , 0 , V_30 ,
L_56 , V_101 ) ;
if ( F_193 ( V_26 -> V_23 ) ) {
F_46 ( V_113
L_57 ,
F_194 ( V_26 -> V_23 ) ) ;
V_276 = - V_283 ;
goto V_405;
}
V_26 -> V_23 -> V_406 = & V_401 . V_406 ;
V_276 = F_197 ( V_26 -> V_23 ) ;
if ( V_276 != 0 ) {
F_46 ( V_113
L_58 ,
V_276 ) ;
goto V_407;
}
F_198 ( & V_26 -> V_106 ) ;
F_199 ( V_30 , V_26 -> V_23 ) ;
V_8 [ 3 ] = V_101 >> 8 ;
V_8 [ 4 ] = V_101 ;
memcpy ( V_26 -> V_116 [ 0 ] . V_8 , V_8 , V_83 ) ;
memcpy ( V_26 -> V_116 [ 1 ] . V_8 , V_8 , V_83 ) ;
V_26 -> V_116 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_30 -> V_90 -> V_408 = 2 ;
V_30 -> V_90 -> V_116 = V_26 -> V_116 ;
V_30 -> V_90 -> V_409 = & V_387 ;
V_30 -> V_90 -> V_410 = 1 ;
if ( V_175 > 1 ) {
V_30 -> V_90 -> V_411 = 255 ;
V_30 -> V_90 -> V_412 = V_369 ;
V_30 -> V_90 -> V_413 = 1000 ;
}
F_200 ( & V_26 -> V_323 , F_137 ) ;
F_200 ( & V_26 -> V_304 , F_123 ) ;
V_30 -> V_414 = 1 ;
V_30 -> V_300 = 5 ;
V_30 -> V_415 = 4 ;
V_30 -> V_90 -> V_416 =
F_201 ( V_417 ) |
F_201 ( V_195 ) |
F_201 ( V_418 ) |
F_201 ( V_419 ) |
F_201 ( V_197 ) |
F_201 ( V_196 ) |
F_201 ( V_420 ) ;
V_30 -> V_42 = V_421 |
V_422 |
V_423 |
V_424 |
V_425 |
V_426 |
V_427 ;
if ( V_177 )
V_30 -> V_42 |= V_428 ;
V_30 -> V_90 -> V_42 |= V_429 |
V_430 ;
V_30 -> V_431 = sizeof( struct V_3 ) ;
V_30 -> V_432 = sizeof( struct V_12 ) ;
V_30 -> V_433 = sizeof( struct V_17 ) ;
memcpy ( V_26 -> V_434 , V_435 ,
sizeof( V_435 ) ) ;
memcpy ( V_26 -> V_436 , V_437 ,
sizeof( V_437 ) ) ;
memcpy ( V_26 -> V_126 , V_438 , sizeof( V_438 ) ) ;
for ( V_147 = V_439 ; V_147 < V_440 ; V_147 ++ ) {
struct V_441 * V_442 = & V_26 -> V_443 [ V_147 ] ;
switch ( V_147 ) {
case V_439 :
V_442 -> V_175 = V_26 -> V_434 ;
V_442 -> V_311 =
F_78 ( V_435 ) ;
V_442 -> V_444 = V_26 -> V_126 ;
V_442 -> V_445 = F_78 ( V_438 ) ;
break;
case V_446 :
V_442 -> V_175 = V_26 -> V_436 ;
V_442 -> V_311 =
F_78 ( V_437 ) ;
V_442 -> V_444 = V_26 -> V_126 + 4 ;
V_442 -> V_445 = F_78 ( V_438 ) - 4 ;
break;
default:
continue;
}
V_442 -> V_447 . V_448 = true ;
V_442 -> V_447 . V_449 = V_450 |
V_451 |
V_452 |
V_453 ;
V_442 -> V_447 . V_454 = 0x3 ;
V_442 -> V_447 . V_455 = 0x6 ;
memset ( & V_442 -> V_447 . V_456 , 0 ,
sizeof( V_442 -> V_447 . V_456 ) ) ;
V_442 -> V_447 . V_456 . V_457 [ 0 ] = 0xff ;
V_442 -> V_447 . V_456 . V_457 [ 1 ] = 0xff ;
V_442 -> V_447 . V_456 . V_458 = V_459 ;
V_30 -> V_90 -> V_443 [ V_147 ] = V_442 ;
V_442 -> V_460 . V_461 = true ;
V_442 -> V_460 . V_449 =
V_462 |
V_463 |
V_464 |
V_465 |
V_466 |
V_467 |
V_468 |
V_469 |
V_470 |
V_471 |
V_472 ;
V_442 -> V_460 . V_473 . V_474 =
F_29 ( V_475 << 0 |
V_475 << 2 |
V_476 << 4 |
V_475 << 6 |
V_475 << 8 |
V_476 << 10 |
V_476 << 12 |
V_475 << 14 ) ;
V_442 -> V_460 . V_473 . V_477 =
V_442 -> V_460 . V_473 . V_474 ;
}
V_26 -> V_167 = 1 ;
F_202 ( & V_26 -> V_309 ) ;
V_30 -> V_478 = 4 ;
V_30 -> V_479 = 11 ;
switch ( V_480 ) {
case V_481 :
case V_482 :
case V_483 :
case V_484 :
break;
case V_485 :
if ( V_101 == 0 ) {
V_30 -> V_90 -> V_42 |= V_486 ;
F_203 ( V_30 -> V_90 ,
& V_487 ) ;
}
break;
case V_488 :
V_30 -> V_90 -> V_42 |= V_486 ;
F_203 ( V_30 -> V_90 ,
& V_487 ) ;
break;
case V_489 :
if ( V_101 == 0 ) {
V_30 -> V_90 -> V_42 |= V_486 ;
F_203 ( V_30 -> V_90 ,
& V_487 ) ;
} else if ( V_101 == 1 ) {
V_30 -> V_90 -> V_42 |= V_486 ;
F_203 ( V_30 -> V_90 ,
& V_490 ) ;
}
break;
case V_491 :
V_30 -> V_90 -> V_42 |= V_492 ;
break;
case V_493 :
case V_494 :
if ( V_101 == 0 )
V_30 -> V_90 -> V_42 |= V_492 ;
break;
case V_495 :
if ( V_101 == 0 ) {
V_30 -> V_90 -> V_42 |= V_486 ;
F_203 ( V_30 -> V_90 ,
& V_487 ) ;
} else if ( V_101 == 1 ) {
V_30 -> V_90 -> V_42 |= V_486 ;
F_203 ( V_30 -> V_90 ,
& V_490 ) ;
} else if ( V_101 == 4 )
V_30 -> V_90 -> V_42 |= V_492 ;
break;
default:
break;
}
if ( V_480 )
F_204 ( 1 ) ;
V_276 = F_205 ( V_30 ) ;
if ( V_276 < 0 ) {
F_46 ( V_113 L_50
L_59 , V_276 ) ;
goto V_407;
}
switch ( V_480 ) {
case V_485 :
case V_481 :
break;
case V_482 :
if ( ! V_101 )
F_206 ( V_30 -> V_90 , V_496 [ 0 ] ) ;
break;
case V_483 :
case V_491 :
F_206 ( V_30 -> V_90 , V_496 [ 0 ] ) ;
break;
case V_484 :
if ( V_101 < F_78 ( V_496 ) )
F_206 ( V_30 -> V_90 , V_496 [ V_101 ] ) ;
break;
case V_488 :
case V_489 :
break;
case V_493 :
if ( V_101 == 0 )
F_206 ( V_30 -> V_90 , V_496 [ 0 ] ) ;
break;
case V_494 :
if ( V_101 == 0 )
F_206 ( V_30 -> V_90 , V_496 [ 0 ] ) ;
else if ( V_101 == 1 )
F_206 ( V_30 -> V_90 , V_496 [ 1 ] ) ;
break;
case V_495 :
if ( V_101 == 2 )
F_206 ( V_30 -> V_90 , V_496 [ 0 ] ) ;
else if ( V_101 == 3 )
F_206 ( V_30 -> V_90 , V_496 [ 1 ] ) ;
else if ( V_101 == 4 )
F_206 ( V_30 -> V_90 , V_496 [ 2 ] ) ;
break;
default:
break;
}
F_76 ( V_30 -> V_90 , L_60 ,
V_30 -> V_90 -> V_91 ) ;
V_26 -> V_333 = F_207 ( L_61 ,
V_30 -> V_90 -> V_497 ) ;
V_26 -> V_332 = F_208 ( L_62 , 0666 ,
V_26 -> V_333 , V_26 ,
& V_498 ) ;
V_26 -> V_331 = F_208 ( L_63 , 0666 ,
V_26 -> V_333 , V_26 ,
& V_499 ) ;
F_209 ( & V_26 -> V_182 ,
F_93 ,
V_500 , V_206 ) ;
F_210 ( & V_26 -> V_501 , & V_400 ) ;
}
V_47 = F_211 ( 0 , L_56 , F_160 ) ;
if ( V_47 == NULL )
goto V_404;
F_212 () ;
V_276 = F_213 ( V_47 , V_47 -> V_502 ) ;
if ( V_276 < 0 )
goto V_503;
V_276 = F_214 ( V_47 ) ;
if ( V_276 < 0 )
goto V_503;
F_215 () ;
V_276 = F_183 () ;
if ( V_276 < 0 )
goto V_504;
return 0 ;
V_504:
F_46 ( V_113 L_64 ) ;
return V_276 ;
V_503:
F_215 () ;
V_338 ( V_47 ) ;
F_147 () ;
return V_276 ;
V_407:
F_157 ( V_26 -> V_23 ) ;
V_405:
F_158 ( V_30 ) ;
V_404:
F_147 () ;
V_403:
F_216 ( & V_401 ) ;
return V_276 ;
}
static void T_10 F_217 ( void )
{
F_46 ( V_113 L_65 ) ;
F_186 () ;
F_147 () ;
F_218 ( V_47 ) ;
F_216 ( & V_401 ) ;
}
