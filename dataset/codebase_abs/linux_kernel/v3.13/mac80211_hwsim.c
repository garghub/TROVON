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
struct V_76 * V_41 ;
T_6 V_42 ;
struct V_77 * V_78 ;
if ( ! F_26 ( V_47 ) )
return;
V_21 = F_35 ( 100 ) ;
if ( V_21 == NULL )
return;
V_41 = (struct V_76 * ) F_36 ( V_21 , sizeof( * V_41 ) ) ;
V_41 -> V_41 . V_49 = V_50 ;
V_41 -> V_41 . V_51 = 0 ;
V_41 -> V_41 . V_52 = F_29 ( sizeof( * V_41 ) ) ;
V_41 -> V_41 . V_53 = F_30 ( ( 1 << V_54 ) |
( 1 << V_57 ) ) ;
V_41 -> V_59 = 0 ;
V_41 -> V_79 = 0 ;
V_41 -> V_62 = F_29 ( V_39 -> V_63 ) ;
V_42 = V_64 ;
V_41 -> V_68 = F_29 ( V_42 ) ;
V_78 = (struct V_77 * ) F_36 ( V_21 , 10 ) ;
V_78 -> V_80 = F_29 ( V_81 |
V_82 ) ;
V_78 -> V_83 = F_29 ( 0 ) ;
memcpy ( V_78 -> V_84 , V_8 , V_85 ) ;
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
switch ( V_26 -> V_86 ) {
case V_87 :
return true ;
case V_88 :
return false ;
case V_89 :
return true ;
case V_90 :
if ( V_26 -> V_91 &&
memcmp ( V_26 -> V_30 -> V_92 -> V_93 , V_21 -> V_26 + 4 ,
V_85 ) == 0 ) {
V_26 -> V_91 = false ;
return true ;
}
return false ;
}
return true ;
}
static void F_38 ( void * V_26 , T_7 * V_94 ,
struct V_1 * V_2 )
{
struct V_95 * V_96 = V_26 ;
if ( memcmp ( V_94 , V_96 -> V_8 , V_85 ) == 0 )
V_96 -> V_97 = true ;
}
static bool F_39 ( struct V_25 * V_26 ,
const T_7 * V_8 )
{
struct V_95 V_96 ;
if ( memcmp ( V_8 , V_26 -> V_30 -> V_92 -> V_93 , V_85 ) == 0 )
return true ;
V_96 . V_97 = false ;
V_96 . V_8 = V_8 ;
F_40 ( V_26 -> V_30 ,
V_98 ,
F_38 ,
& V_96 ) ;
return V_96 . V_97 ;
}
static void F_41 ( struct V_29 * V_30 ,
struct V_20 * V_99 ,
int V_100 )
{
struct V_20 * V_21 ;
struct V_25 * V_26 = V_30 -> V_31 ;
struct V_77 * V_41 = (struct V_77 * ) V_99 -> V_26 ;
struct V_43 * V_44 = F_24 ( V_99 ) ;
void * V_101 ;
unsigned int V_102 = 0 ;
int V_103 ;
struct V_104 V_105 [ V_106 ] ;
if ( V_26 -> V_86 != V_87 )
V_41 -> V_80 |= F_29 ( V_107 ) ;
if ( F_42 ( & V_26 -> V_108 ) >= V_109 ) {
while ( F_42 ( & V_26 -> V_108 ) >= V_110 )
F_43 ( & V_26 -> V_108 ) ;
}
V_21 = F_44 ( V_111 , V_48 ) ;
if ( V_21 == NULL )
goto V_112;
V_101 = F_45 ( V_21 , 0 , 0 , & V_113 , 0 ,
V_114 ) ;
if ( V_101 == NULL ) {
F_46 ( V_115 L_2 ) ;
goto V_112;
}
if ( F_47 ( V_21 , V_116 ,
sizeof( struct V_117 ) , V_26 -> V_118 [ 1 ] . V_8 ) )
goto V_112;
if ( F_47 ( V_21 , V_119 , V_99 -> V_120 , V_99 -> V_26 ) )
goto V_112;
if ( V_44 -> V_42 & V_121 )
V_102 |= V_122 ;
if ( V_44 -> V_42 & V_123 )
V_102 |= V_124 ;
if ( F_48 ( V_21 , V_125 , V_102 ) )
goto V_112;
for ( V_103 = 0 ; V_103 < V_106 ; V_103 ++ ) {
V_105 [ V_103 ] . V_126 = V_44 -> V_127 . V_128 [ V_103 ] . V_126 ;
V_105 [ V_103 ] . V_129 = V_44 -> V_127 . V_128 [ V_103 ] . V_129 ;
}
if ( F_47 ( V_21 , V_130 ,
sizeof( struct V_104 ) * V_106 ,
V_105 ) )
goto V_112;
if ( F_49 ( V_21 , V_131 , ( unsigned long ) V_99 ) )
goto V_112;
F_50 ( V_21 , V_101 ) ;
F_51 ( & V_132 , V_21 , V_100 ) ;
F_52 ( & V_26 -> V_108 , V_99 ) ;
return;
V_112:
F_46 ( V_115 L_3 , V_133 ) ;
}
static bool F_53 ( struct V_38 * V_134 ,
struct V_38 * V_135 )
{
if ( ! V_134 || ! V_135 )
return false ;
return V_134 -> V_63 == V_135 -> V_63 ;
}
static void F_54 ( void * V_136 , T_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_137 * V_26 = V_136 ;
if ( ! V_2 -> V_138 )
return;
if ( ! F_53 ( V_26 -> V_139 ,
F_55 ( V_2 -> V_138 ) -> V_140 . V_39 ) )
return;
V_26 -> V_141 = true ;
}
static bool F_56 ( struct V_29 * V_30 ,
struct V_20 * V_21 ,
struct V_38 * V_39 )
{
struct V_25 * V_26 = V_30 -> V_31 , * V_142 ;
bool V_143 = false ;
struct V_77 * V_41 = (struct V_77 * ) V_21 -> V_26 ;
struct V_43 * V_44 = F_24 ( V_21 ) ;
struct V_144 V_145 ;
T_2 V_27 ;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
V_145 . V_146 |= V_147 ;
V_145 . V_148 = V_39 -> V_63 ;
V_145 . V_149 = V_39 -> V_149 ;
if ( V_44 -> V_150 . V_128 [ 0 ] . V_42 & V_151 ) {
V_145 . V_152 =
F_57 ( & V_44 -> V_150 . V_128 [ 0 ] ) ;
V_145 . V_153 =
F_58 ( & V_44 -> V_150 . V_128 [ 0 ] ) ;
V_145 . V_146 |= V_154 ;
} else {
V_145 . V_152 = V_44 -> V_150 . V_128 [ 0 ] . V_126 ;
if ( V_44 -> V_150 . V_128 [ 0 ] . V_42 & V_155 )
V_145 . V_146 |= V_156 ;
}
if ( V_44 -> V_150 . V_128 [ 0 ] . V_42 & V_157 )
V_145 . V_146 |= V_158 ;
if ( V_44 -> V_150 . V_128 [ 0 ] . V_42 & V_159 )
V_145 . V_146 |= V_160 ;
V_145 . signal = V_26 -> V_161 - 50 ;
if ( V_26 -> V_86 != V_87 )
V_41 -> V_80 |= F_29 ( V_107 ) ;
F_59 ( V_21 ) ;
F_60 ( V_21 ) ;
V_21 -> V_162 = 0 ;
F_61 ( V_21 ) ;
F_62 ( V_21 ) ;
if ( F_63 ( V_41 -> V_80 ) ||
F_64 ( V_41 -> V_80 ) )
V_27 = V_26 -> V_163 ;
else
V_27 = F_14 () ;
F_65 ( & V_164 ) ;
F_66 (data2, &hwsim_radios, list) {
struct V_20 * V_165 ;
struct V_137 V_137 = {
. V_141 = false ,
. V_139 = V_39 ,
} ;
if ( V_26 == V_142 )
continue;
if ( ! V_142 -> V_166 || ( V_142 -> V_167 && ! V_142 -> V_168 ) ||
! F_37 ( V_142 , V_21 ) )
continue;
if ( ! ( V_26 -> V_169 & V_142 -> V_169 ) )
continue;
if ( ! F_53 ( V_39 , V_142 -> V_168 ) &&
! F_53 ( V_39 , V_142 -> V_139 ) ) {
F_40 (
V_142 -> V_30 , V_98 ,
F_54 , & V_137 ) ;
if ( ! V_137 . V_141 )
continue;
}
if ( V_21 -> V_120 < V_170 && V_171 ) {
struct V_172 * V_172 = F_67 ( V_48 ) ;
if ( ! V_172 )
continue;
V_165 = F_35 ( 128 ) ;
if ( ! V_165 ) {
F_68 ( V_172 ) ;
continue;
}
memcpy ( F_69 ( V_172 ) , V_21 -> V_26 , V_21 -> V_120 ) ;
F_70 ( V_165 , 0 , V_172 , 0 , V_21 -> V_120 , V_21 -> V_120 ) ;
} else {
V_165 = F_71 ( V_21 , V_48 ) ;
if ( ! V_165 )
continue;
}
if ( F_39 ( V_142 , V_41 -> V_84 ) )
V_143 = true ;
V_145 . V_173 = V_27 + V_142 -> V_28 ;
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
memcpy ( F_72 ( V_165 ) , & V_145 , sizeof( V_145 ) ) ;
F_73 ( V_142 -> V_30 , V_165 ) ;
}
F_74 ( & V_164 ) ;
return V_143 ;
}
static void F_75 ( struct V_29 * V_30 ,
struct V_174 * V_150 ,
struct V_20 * V_21 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
struct V_43 * V_175 = F_24 ( V_21 ) ;
struct V_15 * V_138 ;
struct V_38 * V_139 ;
bool V_143 ;
T_4 V_176 ;
if ( F_6 ( V_21 -> V_120 < 10 ) ) {
F_76 ( V_30 , V_21 ) ;
return;
}
if ( V_177 == 1 ) {
V_139 = V_26 -> V_139 ;
} else if ( V_175 -> V_178 == 4 ) {
V_139 = V_26 -> V_168 ;
} else {
V_138 = F_55 ( V_175 -> V_150 . V_2 -> V_138 ) ;
if ( V_138 )
V_139 = V_138 -> V_140 . V_39 ;
else
V_139 = NULL ;
}
if ( F_2 ( ! V_139 , L_4 , V_175 -> V_178 ) ) {
F_76 ( V_30 , V_21 ) ;
return;
}
if ( V_26 -> V_167 && ! V_26 -> V_168 ) {
F_77 ( V_30 -> V_92 , L_5 ) ;
F_76 ( V_30 , V_21 ) ;
return;
}
if ( V_175 -> V_150 . V_2 )
F_1 ( V_175 -> V_150 . V_2 ) ;
if ( V_150 -> V_11 )
F_5 ( V_150 -> V_11 ) ;
if ( V_179 )
F_78 ( V_175 -> V_150 . V_2 , V_150 -> V_11 , V_21 ,
V_175 -> V_150 . V_128 ,
F_79 ( V_175 -> V_150 . V_128 ) ) ;
V_175 -> V_180 [ 0 ] = V_139 ;
F_23 ( V_30 , V_21 , V_139 ) ;
V_176 = F_80 ( V_181 ) ;
if ( V_176 )
return F_41 ( V_30 , V_21 , V_176 ) ;
V_143 = F_56 ( V_30 , V_21 , V_139 ) ;
if ( V_143 && V_21 -> V_120 >= 16 ) {
struct V_77 * V_41 = (struct V_77 * ) V_21 -> V_26 ;
F_34 ( V_139 , V_41 -> V_182 ) ;
}
F_81 ( V_175 ) ;
V_175 -> V_150 . V_128 [ 0 ] . V_129 = 1 ;
V_175 -> V_150 . V_128 [ 1 ] . V_126 = - 1 ;
if ( ! ( V_175 -> V_42 & V_123 ) && V_143 )
V_175 -> V_42 |= V_183 ;
F_82 ( V_30 , V_21 ) ;
}
static int F_83 ( struct V_29 * V_30 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
F_77 ( V_30 -> V_92 , L_6 , V_133 ) ;
V_26 -> V_166 = true ;
return 0 ;
}
static void F_84 ( struct V_29 * V_30 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
V_26 -> V_166 = false ;
F_85 ( & V_26 -> V_184 ) ;
F_77 ( V_30 -> V_92 , L_6 , V_133 ) ;
}
static int F_86 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
F_77 ( V_30 -> V_92 , L_7 ,
V_133 , F_87 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_185 = 0 ;
V_2 -> V_178 [ V_186 ] = 0 ;
V_2 -> V_178 [ V_187 ] = 1 ;
V_2 -> V_178 [ V_188 ] = 2 ;
V_2 -> V_178 [ V_189 ] = 3 ;
return 0 ;
}
static int F_88 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
enum V_190 V_191 ,
bool V_192 )
{
V_191 = F_89 ( V_191 , V_192 ) ;
F_77 ( V_30 -> V_92 ,
L_8 ,
V_133 , F_87 ( V_2 ) ,
V_191 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
V_2 -> V_185 = 0 ;
return 0 ;
}
static void F_90 (
struct V_29 * V_30 , struct V_1 * V_2 )
{
F_77 ( V_30 -> V_92 , L_7 ,
V_133 , F_87 ( V_2 ) ,
V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_91 ( struct V_29 * V_30 ,
struct V_20 * V_21 ,
struct V_38 * V_39 )
{
T_4 V_193 = F_80 ( V_181 ) ;
if ( V_179 ) {
struct V_43 * V_175 = F_24 ( V_21 ) ;
F_78 ( V_175 -> V_150 . V_2 , NULL , V_21 ,
V_175 -> V_150 . V_128 ,
F_79 ( V_175 -> V_150 . V_128 ) ) ;
}
F_23 ( V_30 , V_21 , V_39 ) ;
if ( V_193 )
return F_41 ( V_30 , V_21 , V_193 ) ;
F_56 ( V_30 , V_21 , V_39 ) ;
F_13 ( V_21 ) ;
}
static void F_92 ( void * V_194 , T_7 * V_94 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_194 ;
struct V_29 * V_30 = V_26 -> V_30 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_195 * V_196 ;
struct V_20 * V_21 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_197 &&
V_2 -> type != V_198 &&
V_2 -> type != V_199 )
return;
V_21 = F_93 ( V_30 , V_2 ) ;
if ( V_21 == NULL )
return;
V_44 = F_24 ( V_21 ) ;
if ( V_179 )
F_78 ( V_2 , NULL , V_21 ,
V_44 -> V_150 . V_128 ,
F_79 ( V_44 -> V_150 . V_128 ) ) ;
V_46 = F_25 ( V_30 , V_44 ) ;
V_196 = (struct V_195 * ) V_21 -> V_26 ;
V_26 -> V_163 = F_14 () ;
V_196 -> V_200 . V_201 . V_202 = F_18 ( V_26 -> V_163 +
V_26 -> V_28 +
24 * 8 * 10 / V_46 -> V_61 ) ;
F_91 ( V_30 , V_21 ,
F_55 ( V_2 -> V_138 ) -> V_140 . V_39 ) ;
}
static enum V_203
F_94 ( struct V_204 * V_205 )
{
struct V_25 * V_26 =
F_95 ( V_205 , struct V_25 ,
V_184 . V_205 ) ;
struct V_29 * V_30 = V_26 -> V_30 ;
T_2 V_33 = V_26 -> V_34 ;
T_8 V_206 ;
if ( ! V_26 -> V_166 )
goto V_207;
F_40 (
V_30 , V_98 ,
F_92 , V_26 ) ;
if ( V_26 -> V_36 ) {
V_33 -= V_26 -> V_36 ;
V_26 -> V_36 = 0 ;
}
V_206 = F_96 ( F_97 ( V_205 ) ,
F_98 ( V_33 * 1000 ) ) ;
F_99 ( & V_26 -> V_184 , V_206 , V_208 ) ;
V_207:
return V_209 ;
}
static int F_100 ( struct V_29 * V_30 , T_4 V_210 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
struct V_211 * V_212 = & V_30 -> V_212 ;
static const char * V_213 [ V_214 ] = {
[ V_215 ] = L_9 ,
[ V_216 ] = L_10 ,
[ V_217 ] = L_11 ,
[ V_218 ] = L_12 ,
} ;
if ( V_212 -> V_219 . V_39 )
F_77 ( V_30 -> V_92 ,
L_13 ,
V_133 ,
V_212 -> V_219 . V_39 -> V_63 ,
V_212 -> V_219 . V_220 ,
V_212 -> V_219 . V_221 ,
V_222 [ V_212 -> V_219 . V_223 ] ,
! ! ( V_212 -> V_42 & V_224 ) ,
! ! ( V_212 -> V_42 & V_225 ) ,
V_213 [ V_212 -> V_226 ] ) ;
else
F_77 ( V_30 -> V_92 ,
L_14 ,
V_133 ,
! ! ( V_212 -> V_42 & V_224 ) ,
! ! ( V_212 -> V_42 & V_225 ) ,
V_213 [ V_212 -> V_226 ] ) ;
V_26 -> V_167 = ! ! ( V_212 -> V_42 & V_224 ) ;
V_26 -> V_139 = V_212 -> V_219 . V_39 ;
F_6 ( V_26 -> V_139 && V_177 > 1 ) ;
V_26 -> V_161 = V_212 -> V_161 ;
if ( ! V_26 -> V_166 || ! V_26 -> V_34 )
F_85 ( & V_26 -> V_184 ) ;
else if ( ! F_101 ( & V_26 -> V_184 . V_205 ) ) {
T_2 V_32 = F_19 ( V_30 , NULL ) ;
T_4 V_33 = V_26 -> V_34 ;
T_2 V_227 = V_33 - F_22 ( V_32 , V_33 ) ;
F_99 ( & V_26 -> V_184 ,
F_98 ( V_227 * 1000 ) ,
V_228 ) ;
}
return 0 ;
}
static void F_102 ( struct V_29 * V_30 ,
unsigned int V_229 ,
unsigned int * V_230 , T_2 V_231 )
{
struct V_25 * V_26 = V_30 -> V_31 ;
F_77 ( V_30 -> V_92 , L_6 , V_133 ) ;
V_26 -> V_232 = 0 ;
if ( * V_230 & V_233 )
V_26 -> V_232 |= V_233 ;
if ( * V_230 & V_234 )
V_26 -> V_232 |= V_234 ;
* V_230 = V_26 -> V_232 ;
}
static void F_103 ( void * V_26 , T_7 * V_94 ,
struct V_1 * V_2 )
{
unsigned int * V_129 = V_26 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
if ( V_4 -> V_235 )
( * V_129 ) ++ ;
}
static void F_104 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_236 * V_44 ,
T_4 V_210 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_25 * V_26 = V_30 -> V_31 ;
F_1 ( V_2 ) ;
F_77 ( V_30 -> V_92 , L_15 ,
V_133 , V_210 , V_2 -> V_8 ) ;
if ( V_210 & V_237 ) {
F_77 ( V_30 -> V_92 , L_16 ,
V_133 , V_44 -> V_238 ) ;
memcpy ( V_4 -> V_238 , V_44 -> V_238 , V_85 ) ;
}
if ( V_210 & V_239 ) {
F_77 ( V_30 -> V_92 , L_17 ,
V_44 -> V_240 , V_44 -> V_241 ) ;
V_4 -> V_240 = V_44 -> V_240 ;
V_4 -> V_241 = V_44 -> V_241 ;
}
if ( V_210 & V_242 ) {
F_77 ( V_30 -> V_92 , L_18 , V_44 -> V_34 ) ;
V_26 -> V_34 = V_44 -> V_34 * 1024 ;
}
if ( V_210 & V_243 ) {
F_77 ( V_30 -> V_92 , L_19 , V_44 -> V_244 ) ;
V_4 -> V_235 = V_44 -> V_244 ;
if ( V_26 -> V_166 &&
! F_101 ( & V_26 -> V_184 . V_205 ) &&
V_44 -> V_244 ) {
T_2 V_32 , V_227 ;
T_4 V_33 ;
if ( F_6 ( ! V_26 -> V_34 ) )
V_26 -> V_34 = 1000 * 1024 ;
V_32 = F_19 ( V_30 , V_2 ) ;
V_33 = V_26 -> V_34 ;
V_227 = V_33 - F_22 ( V_32 , V_33 ) ;
F_99 ( & V_26 -> V_184 ,
F_98 ( V_227 * 1000 ) ,
V_228 ) ;
} else if ( ! V_44 -> V_244 ) {
unsigned int V_129 = 0 ;
F_40 (
V_26 -> V_30 , V_98 ,
F_103 , & V_129 ) ;
F_77 ( V_30 -> V_92 , L_20 ,
V_129 ) ;
if ( V_129 == 0 )
F_85 ( & V_26 -> V_184 ) ;
}
}
if ( V_210 & V_245 ) {
F_77 ( V_30 -> V_92 , L_21 ,
V_44 -> V_246 ) ;
}
if ( V_210 & V_247 ) {
F_77 ( V_30 -> V_92 , L_22 ,
V_44 -> V_248 ) ;
}
if ( V_210 & V_249 ) {
F_77 ( V_30 -> V_92 , L_23 , V_44 -> V_250 ) ;
}
if ( V_210 & V_251 ) {
F_77 ( V_30 -> V_92 , L_24 ,
V_44 -> V_252 ) ;
}
if ( V_210 & V_253 ) {
F_77 ( V_30 -> V_92 , L_25 ,
( unsigned long long ) V_44 -> V_254 ) ;
}
if ( V_210 & V_255 )
F_77 ( V_30 -> V_92 , L_26 , V_44 -> V_256 ) ;
}
static int F_105 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_106 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_107 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
enum V_257 V_258 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_258 ) {
case V_259 :
case V_260 :
break;
default:
F_2 ( 1 , L_27 , V_258 ) ;
break;
}
}
static int F_108 ( struct V_29 * V_30 ,
struct V_10 * V_11 ,
bool V_261 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_109 (
struct V_29 * V_30 ,
struct V_1 * V_2 , T_6 V_262 ,
const struct V_263 * V_264 )
{
F_77 ( V_30 -> V_92 ,
L_28 ,
V_133 , V_262 ,
V_264 -> V_265 , V_264 -> V_266 ,
V_264 -> V_267 , V_264 -> V_268 ) ;
return 0 ;
}
static int F_110 (
struct V_29 * V_30 , int V_126 ,
struct V_269 * V_270 )
{
struct V_211 * V_212 = & V_30 -> V_212 ;
F_77 ( V_30 -> V_92 , L_29 , V_133 , V_126 ) ;
if ( V_126 != 0 )
return - V_271 ;
V_270 -> V_139 = V_212 -> V_219 . V_39 ;
V_270 -> V_272 = V_273 ;
V_270 -> V_274 = - 92 ;
return 0 ;
}
static int F_111 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
void * V_26 , int V_120 )
{
struct V_25 * V_275 = V_30 -> V_31 ;
struct V_276 * V_277 [ V_278 + 1 ] ;
struct V_20 * V_21 ;
int V_279 , V_86 ;
V_279 = F_112 ( V_277 , V_278 , V_26 , V_120 ,
V_280 ) ;
if ( V_279 )
return V_279 ;
if ( ! V_277 [ V_281 ] )
return - V_282 ;
switch ( F_113 ( V_277 [ V_281 ] ) ) {
case V_283 :
if ( ! V_277 [ V_284 ] )
return - V_282 ;
V_86 = F_113 ( V_277 [ V_284 ] ) ;
return F_114 ( V_275 , V_86 ) ;
case V_285 :
V_21 = F_115 ( V_30 -> V_92 ,
F_116 ( sizeof( T_4 ) ) ) ;
if ( ! V_21 )
return - V_286 ;
if ( F_48 ( V_21 , V_284 , V_275 -> V_86 ) )
goto V_112;
return F_117 ( V_21 ) ;
case V_287 :
F_118 ( V_30 ) ;
return 0 ;
case V_288 :
F_119 ( V_30 ) ;
return 0 ;
default:
return - V_289 ;
}
V_112:
F_120 ( V_21 ) ;
return - V_290 ;
}
static int F_121 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
enum V_291 V_292 ,
struct V_10 * V_11 , T_6 V_293 , T_6 * V_294 ,
T_7 V_295 )
{
switch ( V_292 ) {
case V_296 :
F_122 ( V_2 , V_11 -> V_8 , V_293 ) ;
break;
case V_297 :
case V_298 :
case V_299 :
F_123 ( V_2 , V_11 -> V_8 , V_293 ) ;
break;
case V_300 :
break;
case V_301 :
case V_302 :
break;
default:
return - V_289 ;
}
return 0 ;
}
static void F_124 ( struct V_29 * V_30 , T_4 V_303 , bool V_304 )
{
}
static void F_125 ( struct V_305 * V_306 )
{
struct V_25 * V_275 =
F_95 ( V_306 , struct V_25 , V_307 . V_306 ) ;
struct V_308 * V_309 = V_275 -> V_310 ;
int V_311 , V_103 ;
F_126 ( & V_275 -> V_312 ) ;
if ( V_275 -> V_313 >= V_309 -> V_314 ) {
F_77 ( V_275 -> V_30 -> V_92 , L_30 ) ;
F_127 ( V_275 -> V_30 , false ) ;
V_275 -> V_310 = NULL ;
V_275 -> V_315 = NULL ;
V_275 -> V_168 = NULL ;
F_128 ( & V_275 -> V_312 ) ;
return;
}
F_77 ( V_275 -> V_30 -> V_92 , L_31 ,
V_309 -> V_177 [ V_275 -> V_313 ] -> V_63 ) ;
V_275 -> V_168 = V_309 -> V_177 [ V_275 -> V_313 ] ;
if ( V_275 -> V_168 -> V_42 & V_316 ||
! V_309 -> V_317 ) {
V_311 = 120 ;
} else {
V_311 = 30 ;
for ( V_103 = 0 ; V_103 < V_309 -> V_317 ; V_103 ++ ) {
struct V_20 * V_318 ;
V_318 = F_129 ( V_275 -> V_30 ,
V_275 -> V_315 ,
V_309 -> V_319 [ V_103 ] . V_320 ,
V_309 -> V_319 [ V_103 ] . V_321 ,
V_309 -> V_322 ) ;
if ( ! V_318 )
continue;
if ( V_309 -> V_322 )
memcpy ( F_36 ( V_318 , V_309 -> V_322 ) , V_309 -> V_323 ,
V_309 -> V_322 ) ;
F_130 () ;
F_91 ( V_275 -> V_30 , V_318 ,
V_275 -> V_168 ) ;
F_131 () ;
}
}
F_132 ( V_275 -> V_30 , & V_275 -> V_307 ,
F_133 ( V_311 ) ) ;
V_275 -> V_313 ++ ;
F_128 ( & V_275 -> V_312 ) ;
}
static int F_134 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_308 * V_309 )
{
struct V_25 * V_275 = V_30 -> V_31 ;
F_126 ( & V_275 -> V_312 ) ;
if ( F_6 ( V_275 -> V_168 || V_275 -> V_310 ) ) {
F_128 ( & V_275 -> V_312 ) ;
return - V_324 ;
}
V_275 -> V_310 = V_309 ;
V_275 -> V_315 = V_2 ;
V_275 -> V_313 = 0 ;
F_128 ( & V_275 -> V_312 ) ;
F_77 ( V_30 -> V_92 , L_32 ) ;
F_132 ( V_275 -> V_30 , & V_275 -> V_307 , 0 ) ;
return 0 ;
}
static void F_135 ( struct V_29 * V_30 ,
struct V_1 * V_2 )
{
struct V_25 * V_275 = V_30 -> V_31 ;
F_77 ( V_30 -> V_92 , L_33 ) ;
F_136 ( & V_275 -> V_307 ) ;
F_126 ( & V_275 -> V_312 ) ;
F_127 ( V_275 -> V_30 , true ) ;
V_275 -> V_168 = NULL ;
V_275 -> V_310 = NULL ;
V_275 -> V_315 = NULL ;
F_128 ( & V_275 -> V_312 ) ;
}
static void F_137 ( struct V_29 * V_30 )
{
struct V_25 * V_275 = V_30 -> V_31 ;
F_126 ( & V_275 -> V_312 ) ;
if ( V_275 -> V_325 ) {
F_46 ( V_115 L_34 ) ;
goto V_207;
}
F_46 ( V_115 L_35 ) ;
V_275 -> V_325 = true ;
V_207:
F_128 ( & V_275 -> V_312 ) ;
}
static void F_138 ( struct V_29 * V_30 )
{
struct V_25 * V_275 = V_30 -> V_31 ;
F_126 ( & V_275 -> V_312 ) ;
F_46 ( V_115 L_36 ) ;
V_275 -> V_325 = false ;
F_128 ( & V_275 -> V_312 ) ;
}
static void F_139 ( struct V_305 * V_306 )
{
struct V_25 * V_275 =
F_95 ( V_306 , struct V_25 , V_326 . V_306 ) ;
F_126 ( & V_275 -> V_312 ) ;
F_140 ( V_275 -> V_30 ) ;
V_275 -> V_168 = NULL ;
F_128 ( & V_275 -> V_312 ) ;
F_77 ( V_275 -> V_30 -> V_92 , L_37 ) ;
}
static int F_141 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_38 * V_39 ,
int V_327 ,
enum V_328 type )
{
struct V_25 * V_275 = V_30 -> V_31 ;
F_126 ( & V_275 -> V_312 ) ;
if ( F_6 ( V_275 -> V_168 || V_275 -> V_310 ) ) {
F_128 ( & V_275 -> V_312 ) ;
return - V_324 ;
}
V_275 -> V_168 = V_39 ;
F_128 ( & V_275 -> V_312 ) ;
F_77 ( V_30 -> V_92 , L_38 ,
V_39 -> V_63 , V_327 ) ;
F_142 ( V_30 ) ;
F_132 ( V_30 , & V_275 -> V_326 ,
F_133 ( V_327 ) ) ;
return 0 ;
}
static int F_143 ( struct V_29 * V_30 )
{
struct V_25 * V_275 = V_30 -> V_31 ;
F_136 ( & V_275 -> V_326 ) ;
F_126 ( & V_275 -> V_312 ) ;
V_275 -> V_168 = NULL ;
F_128 ( & V_275 -> V_312 ) ;
F_77 ( V_30 -> V_92 , L_39 ) ;
return 0 ;
}
static int F_144 ( struct V_29 * V_30 ,
struct V_15 * V_329 )
{
F_10 ( V_329 ) ;
F_77 ( V_30 -> V_92 ,
L_40 ,
V_329 -> V_140 . V_39 -> V_63 , V_329 -> V_140 . V_223 ,
V_329 -> V_140 . V_220 , V_329 -> V_140 . V_221 ) ;
return 0 ;
}
static void F_145 ( struct V_29 * V_30 ,
struct V_15 * V_329 )
{
F_77 ( V_30 -> V_92 ,
L_41 ,
V_329 -> V_140 . V_39 -> V_63 , V_329 -> V_140 . V_223 ,
V_329 -> V_140 . V_220 , V_329 -> V_140 . V_221 ) ;
F_9 ( V_329 ) ;
F_11 ( V_329 ) ;
}
static void F_146 ( struct V_29 * V_30 ,
struct V_15 * V_329 ,
T_4 V_210 )
{
F_9 ( V_329 ) ;
F_77 ( V_30 -> V_92 ,
L_42 ,
V_329 -> V_140 . V_39 -> V_63 , V_329 -> V_140 . V_223 ,
V_329 -> V_140 . V_220 , V_329 -> V_140 . V_221 ) ;
}
static int F_147 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_15 * V_329 )
{
F_1 ( V_2 ) ;
F_9 ( V_329 ) ;
return 0 ;
}
static void F_148 ( struct V_29 * V_30 ,
struct V_1 * V_2 ,
struct V_15 * V_329 )
{
F_1 ( V_2 ) ;
F_9 ( V_329 ) ;
}
static void F_149 ( void )
{
struct V_330 V_331 , * V_103 , * V_332 ;
struct V_25 * V_26 , * V_333 ;
F_150 ( & V_331 ) ;
F_151 ( & V_164 ) ;
F_152 (i, tmp, &hwsim_radios)
F_153 ( V_103 , & V_331 ) ;
F_154 ( & V_164 ) ;
F_155 (data, tmpdata, &tmplist, list) {
F_156 ( V_26 -> V_334 ) ;
F_156 ( V_26 -> V_335 ) ;
F_156 ( V_26 -> V_336 ) ;
F_157 ( V_26 -> V_30 ) ;
F_158 ( V_26 -> V_23 ) ;
F_159 ( V_26 -> V_23 ) ;
F_160 ( V_26 -> V_30 ) ;
}
F_161 ( V_337 ) ;
}
static void F_162 ( struct V_22 * V_23 )
{
V_23 -> V_338 = & V_339 ;
V_23 -> V_340 = V_341 ;
F_163 ( V_23 ) ;
V_23 -> V_342 = 0 ;
V_23 -> type = V_343 ;
memset ( V_23 -> V_344 , 0 , V_85 ) ;
V_23 -> V_344 [ 0 ] = 0x12 ;
}
static void F_164 ( void * V_345 , T_7 * V_94 , struct V_1 * V_2 )
{
struct V_25 * V_26 = V_345 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_346 * V_347 ;
if ( ! V_4 -> V_240 )
return;
F_77 ( V_26 -> V_30 -> V_92 ,
L_43 ,
V_133 , V_4 -> V_238 , V_4 -> V_241 ) ;
V_21 = F_35 ( sizeof( * V_347 ) ) ;
if ( ! V_21 )
return;
V_347 = ( void * ) F_36 ( V_21 , sizeof( * V_347 ) ) ;
V_347 -> V_80 = F_29 ( V_81 |
V_348 |
V_107 ) ;
V_347 -> V_241 = F_29 ( 0xc000 | V_4 -> V_241 ) ;
memcpy ( V_347 -> V_238 , V_4 -> V_238 , V_85 ) ;
memcpy ( V_347 -> V_349 , V_94 , V_85 ) ;
F_165 () ;
F_91 ( V_26 -> V_30 , V_21 ,
F_55 ( V_2 -> V_138 ) -> V_140 . V_39 ) ;
F_166 () ;
}
static void F_167 ( struct V_25 * V_26 , T_7 * V_94 ,
struct V_1 * V_2 , int V_86 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_20 * V_21 ;
struct V_77 * V_41 ;
if ( ! V_4 -> V_240 )
return;
F_77 ( V_26 -> V_30 -> V_92 ,
L_44 ,
V_133 , V_4 -> V_238 , V_86 ) ;
V_21 = F_35 ( sizeof( * V_41 ) ) ;
if ( ! V_21 )
return;
V_41 = ( void * ) F_36 ( V_21 , sizeof( * V_41 ) - V_85 ) ;
V_41 -> V_80 = F_29 ( V_350 |
V_351 |
( V_86 ? V_107 : 0 ) ) ;
V_41 -> V_83 = F_29 ( 0 ) ;
memcpy ( V_41 -> V_84 , V_4 -> V_238 , V_85 ) ;
memcpy ( V_41 -> V_182 , V_94 , V_85 ) ;
memcpy ( V_41 -> V_352 , V_4 -> V_238 , V_85 ) ;
F_165 () ;
F_91 ( V_26 -> V_30 , V_21 ,
F_55 ( V_2 -> V_138 ) -> V_140 . V_39 ) ;
F_166 () ;
}
static void F_168 ( void * V_345 , T_7 * V_94 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_345 ;
F_167 ( V_26 , V_94 , V_2 , 1 ) ;
}
static void F_169 ( void * V_345 , T_7 * V_94 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_345 ;
F_167 ( V_26 , V_94 , V_2 , 0 ) ;
}
static int F_170 ( void * V_345 , T_2 * V_353 )
{
struct V_25 * V_26 = V_345 ;
* V_353 = V_26 -> V_86 ;
return 0 ;
}
static int F_114 ( void * V_345 , T_2 V_353 )
{
struct V_25 * V_26 = V_345 ;
enum V_354 V_355 ;
if ( V_353 != V_87 && V_353 != V_88 && V_353 != V_89 &&
V_353 != V_90 )
return - V_282 ;
V_355 = V_26 -> V_86 ;
V_26 -> V_86 = V_353 ;
if ( V_353 == V_90 ) {
F_171 ( V_26 -> V_30 ,
V_98 ,
F_164 , V_26 ) ;
V_26 -> V_91 = true ;
} else if ( V_355 == V_87 && V_353 != V_87 ) {
F_171 ( V_26 -> V_30 ,
V_98 ,
F_168 ,
V_26 ) ;
} else if ( V_355 != V_87 && V_353 == V_87 ) {
F_171 ( V_26 -> V_30 ,
V_98 ,
F_169 ,
V_26 ) ;
}
return 0 ;
}
static int F_172 ( void * V_345 , T_2 * V_353 )
{
struct V_25 * V_26 = V_345 ;
* V_353 = V_26 -> V_169 ;
return 0 ;
}
static int F_173 ( void * V_345 , T_2 V_353 )
{
struct V_25 * V_26 = V_345 ;
V_26 -> V_169 = V_353 ;
return 0 ;
}
static struct V_25 * F_174 (
struct V_117 * V_8 )
{
struct V_25 * V_26 ;
bool V_356 = false ;
F_151 ( & V_164 ) ;
F_66 (data, &hwsim_radios, list) {
if ( memcmp ( V_26 -> V_118 [ 1 ] . V_8 , V_8 ,
sizeof( struct V_117 ) ) == 0 ) {
V_356 = true ;
break;
}
}
F_154 ( & V_164 ) ;
if ( ! V_356 )
return NULL ;
return V_26 ;
}
static int F_175 ( struct V_20 * V_357 ,
struct V_358 * V_44 )
{
struct V_77 * V_41 ;
struct V_25 * V_142 ;
struct V_43 * V_175 ;
struct V_104 * V_105 ;
unsigned long V_359 ;
struct V_20 * V_21 , * V_332 ;
struct V_117 * V_360 ;
unsigned int V_102 ;
int V_103 ;
bool V_361 = false ;
if ( ! V_44 -> V_362 [ V_116 ] ||
! V_44 -> V_362 [ V_125 ] ||
! V_44 -> V_362 [ V_131 ] ||
! V_44 -> V_362 [ V_130 ] )
goto V_207;
V_360 = (struct V_117 * ) F_176 (
V_44 -> V_362 [ V_116 ] ) ;
V_102 = F_113 ( V_44 -> V_362 [ V_125 ] ) ;
V_359 = F_177 ( V_44 -> V_362 [ V_131 ] ) ;
V_142 = F_174 ( V_360 ) ;
if ( V_142 == NULL )
goto V_207;
F_178 (&data2->pending, skb, tmp) {
if ( ( unsigned long ) V_21 == V_359 ) {
F_179 ( V_21 , & V_142 -> V_108 ) ;
V_361 = true ;
break;
}
}
if ( ! V_361 )
goto V_207;
V_105 = (struct V_104 * ) F_176 (
V_44 -> V_362 [ V_130 ] ) ;
V_175 = F_24 ( V_21 ) ;
F_81 ( V_175 ) ;
for ( V_103 = 0 ; V_103 < V_106 ; V_103 ++ ) {
V_175 -> V_127 . V_128 [ V_103 ] . V_126 = V_105 [ V_103 ] . V_126 ;
V_175 -> V_127 . V_128 [ V_103 ] . V_129 = V_105 [ V_103 ] . V_129 ;
}
V_175 -> V_127 . V_363 = F_113 ( V_44 -> V_362 [ V_364 ] ) ;
if ( ! ( V_102 & V_124 ) &&
( V_102 & V_365 ) ) {
if ( V_21 -> V_120 >= 16 ) {
V_41 = (struct V_77 * ) V_21 -> V_26 ;
F_34 ( V_142 -> V_139 ,
V_41 -> V_182 ) ;
}
V_175 -> V_42 |= V_183 ;
}
F_82 ( V_142 -> V_30 , V_21 ) ;
return 0 ;
V_207:
return - V_282 ;
}
static int F_180 ( struct V_20 * V_357 ,
struct V_358 * V_44 )
{
struct V_25 * V_142 ;
struct V_144 V_145 ;
struct V_117 * V_366 ;
int V_367 ;
char * V_368 ;
struct V_20 * V_21 = NULL ;
if ( ! V_44 -> V_362 [ V_369 ] ||
! V_44 -> V_362 [ V_119 ] ||
! V_44 -> V_362 [ V_370 ] ||
! V_44 -> V_362 [ V_364 ] )
goto V_207;
V_366 = (struct V_117 * ) F_176 (
V_44 -> V_362 [ V_369 ] ) ;
V_367 = F_181 ( V_44 -> V_362 [ V_119 ] ) ;
V_368 = ( char * ) F_176 ( V_44 -> V_362 [ V_119 ] ) ;
V_21 = F_182 ( V_367 , V_371 ) ;
if ( V_21 == NULL )
goto V_279;
if ( V_367 <= V_372 ) {
memcpy ( F_36 ( V_21 , V_367 ) , V_368 ,
V_367 ) ;
} else
goto V_279;
V_142 = F_174 ( V_366 ) ;
if ( V_142 == NULL )
goto V_207;
if ( V_142 -> V_167 || ! V_142 -> V_166 )
goto V_207;
memset ( & V_145 , 0 , sizeof( V_145 ) ) ;
V_145 . V_148 = V_142 -> V_139 -> V_63 ;
V_145 . V_149 = V_142 -> V_139 -> V_149 ;
V_145 . V_152 = F_113 ( V_44 -> V_362 [ V_370 ] ) ;
V_145 . signal = F_113 ( V_44 -> V_362 [ V_364 ] ) ;
memcpy ( F_72 ( V_21 ) , & V_145 , sizeof( V_145 ) ) ;
F_73 ( V_142 -> V_30 , V_21 ) ;
return 0 ;
V_279:
F_46 ( V_115 L_3 , V_133 ) ;
goto V_207;
V_207:
F_13 ( V_21 ) ;
return - V_282 ;
}
static int F_183 ( struct V_20 * V_357 ,
struct V_358 * V_44 )
{
if ( V_44 == NULL )
goto V_207;
V_181 = V_44 -> V_373 ;
F_46 ( V_115 L_45
L_46 , V_44 -> V_373 ) ;
return 0 ;
V_207:
F_46 ( V_115 L_3 , V_133 ) ;
return - V_282 ;
}
static int F_184 ( struct V_374 * V_375 ,
unsigned long V_376 ,
void * V_377 )
{
struct V_378 * V_379 = V_377 ;
if ( V_376 != V_380 )
return V_381 ;
if ( V_379 -> V_382 == V_181 ) {
F_46 ( V_383 L_47
L_48 ) ;
V_181 = 0 ;
}
return V_381 ;
}
static int F_185 ( void )
{
int V_384 ;
if ( V_177 > 1 )
return 0 ;
F_46 ( V_383 L_49 ) ;
V_384 = F_186 ( & V_113 , V_385 ) ;
if ( V_384 )
goto V_386;
V_384 = F_187 ( & V_387 ) ;
if ( V_384 )
goto V_386;
return 0 ;
V_386:
F_46 ( V_115 L_3 , V_133 ) ;
return - V_282 ;
}
static void F_188 ( void )
{
int V_97 ;
if ( V_177 > 1 )
return;
F_46 ( V_383 L_50 ) ;
F_189 ( & V_387 ) ;
V_97 = F_190 ( & V_113 ) ;
if ( V_97 )
F_46 ( V_115 L_51
L_52 , V_97 ) ;
}
static int T_9 F_191 ( void )
{
int V_103 , V_279 = 0 ;
T_7 V_8 [ V_85 ] ;
struct V_25 * V_26 ;
struct V_29 * V_30 ;
enum V_388 V_149 ;
if ( V_389 < 1 || V_389 > 100 )
return - V_282 ;
if ( V_177 < 1 )
return - V_282 ;
if ( V_177 > 1 ) {
V_390 . V_391 = V_177 ;
V_392 . V_307 = F_134 ;
V_392 . V_393 =
F_135 ;
V_392 . V_394 = NULL ;
V_392 . V_395 = NULL ;
V_392 . V_396 =
F_141 ;
V_392 . V_397 =
F_143 ;
V_392 . V_398 =
F_144 ;
V_392 . V_399 =
F_145 ;
V_392 . V_400 =
F_146 ;
V_392 . V_401 =
F_147 ;
V_392 . V_402 =
F_148 ;
}
F_192 ( & V_164 ) ;
F_150 ( & V_403 ) ;
V_279 = F_193 ( & V_404 ) ;
if ( V_279 )
return V_279 ;
V_337 = F_194 ( V_405 , L_53 ) ;
if ( F_195 ( V_337 ) ) {
V_279 = F_196 ( V_337 ) ;
goto V_406;
}
memset ( V_8 , 0 , V_85 ) ;
V_8 [ 0 ] = 0x02 ;
for ( V_103 = 0 ; V_103 < V_389 ; V_103 ++ ) {
F_46 ( V_115 L_54 ,
V_103 ) ;
V_30 = F_197 ( sizeof( * V_26 ) , & V_392 ) ;
if ( ! V_30 ) {
F_46 ( V_115 L_55
L_56 ) ;
V_279 = - V_286 ;
goto V_407;
}
V_26 = V_30 -> V_31 ;
V_26 -> V_30 = V_30 ;
V_26 -> V_23 = F_198 ( V_337 , NULL , 0 , V_30 ,
L_57 , V_103 ) ;
if ( F_195 ( V_26 -> V_23 ) ) {
F_46 ( V_115
L_58 ,
F_196 ( V_26 -> V_23 ) ) ;
V_279 = - V_286 ;
goto V_408;
}
V_26 -> V_23 -> V_409 = & V_404 . V_409 ;
V_279 = F_199 ( V_26 -> V_23 ) ;
if ( V_279 != 0 ) {
F_46 ( V_115
L_59 ,
V_279 ) ;
goto V_410;
}
F_200 ( & V_26 -> V_108 ) ;
F_201 ( V_30 , V_26 -> V_23 ) ;
V_8 [ 3 ] = V_103 >> 8 ;
V_8 [ 4 ] = V_103 ;
memcpy ( V_26 -> V_118 [ 0 ] . V_8 , V_8 , V_85 ) ;
memcpy ( V_26 -> V_118 [ 1 ] . V_8 , V_8 , V_85 ) ;
V_26 -> V_118 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_30 -> V_92 -> V_411 = 2 ;
V_30 -> V_92 -> V_118 = V_26 -> V_118 ;
V_30 -> V_92 -> V_412 = & V_390 ;
V_30 -> V_92 -> V_413 = 1 ;
if ( V_177 > 1 ) {
V_30 -> V_92 -> V_414 = 255 ;
V_30 -> V_92 -> V_415 = V_372 ;
V_30 -> V_92 -> V_416 = 1000 ;
}
F_202 ( & V_26 -> V_326 , F_139 ) ;
F_202 ( & V_26 -> V_307 , F_125 ) ;
V_30 -> V_417 = 1 ;
V_30 -> V_303 = 5 ;
V_30 -> V_418 = 4 ;
V_30 -> V_92 -> V_419 =
F_203 ( V_420 ) |
F_203 ( V_197 ) |
F_203 ( V_421 ) |
F_203 ( V_422 ) |
F_203 ( V_199 ) |
F_203 ( V_198 ) |
F_203 ( V_423 ) ;
V_30 -> V_42 = V_424 |
V_425 |
V_426 |
V_427 |
V_428 |
V_429 |
V_430 ;
if ( V_179 )
V_30 -> V_42 |= V_431 ;
V_30 -> V_92 -> V_42 |= V_432 |
V_433 |
V_434 ;
V_30 -> V_92 -> V_435 |= V_436 ;
V_30 -> V_437 = sizeof( struct V_3 ) ;
V_30 -> V_438 = sizeof( struct V_12 ) ;
V_30 -> V_439 = sizeof( struct V_17 ) ;
memcpy ( V_26 -> V_440 , V_441 ,
sizeof( V_441 ) ) ;
memcpy ( V_26 -> V_442 , V_443 ,
sizeof( V_443 ) ) ;
memcpy ( V_26 -> V_128 , V_444 , sizeof( V_444 ) ) ;
for ( V_149 = V_445 ; V_149 < V_446 ; V_149 ++ ) {
struct V_447 * V_448 = & V_26 -> V_449 [ V_149 ] ;
switch ( V_149 ) {
case V_445 :
V_448 -> V_177 = V_26 -> V_440 ;
V_448 -> V_314 =
F_79 ( V_441 ) ;
V_448 -> V_450 = V_26 -> V_128 ;
V_448 -> V_451 = F_79 ( V_444 ) ;
break;
case V_452 :
V_448 -> V_177 = V_26 -> V_442 ;
V_448 -> V_314 =
F_79 ( V_443 ) ;
V_448 -> V_450 = V_26 -> V_128 + 4 ;
V_448 -> V_451 = F_79 ( V_444 ) - 4 ;
break;
default:
continue;
}
V_448 -> V_453 . V_454 = true ;
V_448 -> V_453 . V_455 = V_456 |
V_457 |
V_458 |
V_459 ;
V_448 -> V_453 . V_460 = 0x3 ;
V_448 -> V_453 . V_461 = 0x6 ;
memset ( & V_448 -> V_453 . V_462 , 0 ,
sizeof( V_448 -> V_453 . V_462 ) ) ;
V_448 -> V_453 . V_462 . V_463 [ 0 ] = 0xff ;
V_448 -> V_453 . V_462 . V_463 [ 1 ] = 0xff ;
V_448 -> V_453 . V_462 . V_464 = V_465 ;
V_30 -> V_92 -> V_449 [ V_149 ] = V_448 ;
V_448 -> V_466 . V_467 = true ;
V_448 -> V_466 . V_455 =
V_468 |
V_469 |
V_470 |
V_471 |
V_472 |
V_473 |
V_474 |
V_475 |
V_476 |
V_477 |
V_478 ;
V_448 -> V_466 . V_479 . V_480 =
F_29 ( V_481 << 0 |
V_481 << 2 |
V_482 << 4 |
V_481 << 6 |
V_481 << 8 |
V_482 << 10 |
V_482 << 12 |
V_481 << 14 ) ;
V_448 -> V_466 . V_479 . V_483 =
V_448 -> V_466 . V_479 . V_480 ;
}
V_26 -> V_169 = 1 ;
F_204 ( & V_26 -> V_312 ) ;
V_30 -> V_484 = 4 ;
V_30 -> V_485 = 11 ;
switch ( V_486 ) {
case V_487 :
case V_488 :
case V_489 :
case V_490 :
break;
case V_491 :
if ( V_103 == 0 ) {
V_30 -> V_92 -> V_42 |= V_492 ;
F_205 ( V_30 -> V_92 ,
& V_493 ) ;
}
break;
case V_494 :
V_30 -> V_92 -> V_42 |= V_492 ;
F_205 ( V_30 -> V_92 ,
& V_493 ) ;
break;
case V_495 :
if ( V_103 == 0 ) {
V_30 -> V_92 -> V_42 |= V_492 ;
F_205 ( V_30 -> V_92 ,
& V_493 ) ;
} else if ( V_103 == 1 ) {
V_30 -> V_92 -> V_42 |= V_492 ;
F_205 ( V_30 -> V_92 ,
& V_496 ) ;
}
break;
case V_497 :
V_30 -> V_92 -> V_42 |= V_498 ;
break;
case V_499 :
case V_500 :
if ( V_103 == 0 )
V_30 -> V_92 -> V_42 |= V_498 ;
break;
case V_501 :
if ( V_103 == 0 ) {
V_30 -> V_92 -> V_42 |= V_492 ;
F_205 ( V_30 -> V_92 ,
& V_493 ) ;
} else if ( V_103 == 1 ) {
V_30 -> V_92 -> V_42 |= V_492 ;
F_205 ( V_30 -> V_92 ,
& V_496 ) ;
} else if ( V_103 == 4 )
V_30 -> V_92 -> V_42 |= V_498 ;
break;
default:
break;
}
if ( V_486 )
F_206 ( 1 ) ;
V_279 = F_207 ( V_30 ) ;
if ( V_279 < 0 ) {
F_46 ( V_115 L_51
L_60 , V_279 ) ;
goto V_410;
}
switch ( V_486 ) {
case V_491 :
case V_487 :
break;
case V_488 :
if ( ! V_103 )
F_208 ( V_30 -> V_92 , V_502 [ 0 ] ) ;
break;
case V_489 :
case V_497 :
F_208 ( V_30 -> V_92 , V_502 [ 0 ] ) ;
break;
case V_490 :
if ( V_103 < F_79 ( V_502 ) )
F_208 ( V_30 -> V_92 , V_502 [ V_103 ] ) ;
break;
case V_494 :
case V_495 :
break;
case V_499 :
if ( V_103 == 0 )
F_208 ( V_30 -> V_92 , V_502 [ 0 ] ) ;
break;
case V_500 :
if ( V_103 == 0 )
F_208 ( V_30 -> V_92 , V_502 [ 0 ] ) ;
else if ( V_103 == 1 )
F_208 ( V_30 -> V_92 , V_502 [ 1 ] ) ;
break;
case V_501 :
if ( V_103 == 2 )
F_208 ( V_30 -> V_92 , V_502 [ 0 ] ) ;
else if ( V_103 == 3 )
F_208 ( V_30 -> V_92 , V_502 [ 1 ] ) ;
else if ( V_103 == 4 )
F_208 ( V_30 -> V_92 , V_502 [ 2 ] ) ;
break;
default:
break;
}
F_77 ( V_30 -> V_92 , L_61 ,
V_30 -> V_92 -> V_93 ) ;
V_26 -> V_336 = F_209 ( L_62 ,
V_30 -> V_92 -> V_503 ) ;
V_26 -> V_335 = F_210 ( L_63 , 0666 ,
V_26 -> V_336 , V_26 ,
& V_504 ) ;
V_26 -> V_334 = F_210 ( L_64 , 0666 ,
V_26 -> V_336 , V_26 ,
& V_505 ) ;
F_211 ( & V_26 -> V_184 ,
F_94 ,
V_506 , V_208 ) ;
F_212 ( & V_26 -> V_507 , & V_403 ) ;
}
V_47 = F_213 ( 0 , L_57 , F_162 ) ;
if ( V_47 == NULL ) {
V_279 = - V_286 ;
goto V_407;
}
F_214 () ;
V_279 = F_215 ( V_47 , V_47 -> V_508 ) ;
if ( V_279 < 0 )
goto V_509;
V_279 = F_216 ( V_47 ) ;
if ( V_279 < 0 )
goto V_509;
F_217 () ;
V_279 = F_185 () ;
if ( V_279 < 0 )
goto V_510;
return 0 ;
V_510:
F_46 ( V_115 L_65 ) ;
return V_279 ;
V_509:
F_217 () ;
V_341 ( V_47 ) ;
F_149 () ;
return V_279 ;
V_410:
F_159 ( V_26 -> V_23 ) ;
V_408:
F_160 ( V_30 ) ;
V_407:
F_149 () ;
V_406:
F_218 ( & V_404 ) ;
return V_279 ;
}
static void T_10 F_219 ( void )
{
F_46 ( V_115 L_66 ) ;
F_188 () ;
F_149 () ;
F_220 ( V_47 ) ;
F_218 ( & V_404 ) ;
}
