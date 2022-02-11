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
static void F_12 ( void * V_20 , T_1 * V_21 , struct V_1 * V_2 )
{
struct V_22 * V_23 = V_20 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
if ( ! V_4 -> V_28 )
return;
F_13 ( V_23 -> V_29 -> V_30 ,
L_2 ,
V_31 , V_4 -> V_32 , V_4 -> V_33 ) ;
V_25 = F_14 ( sizeof( * V_27 ) ) ;
if ( ! V_25 )
return;
V_27 = ( void * ) F_15 ( V_25 , sizeof( * V_27 ) ) ;
V_27 -> V_34 = F_16 ( V_35 |
V_36 |
V_37 ) ;
V_27 -> V_33 = F_16 ( 0xc000 | V_4 -> V_33 ) ;
memcpy ( V_27 -> V_32 , V_4 -> V_32 , V_38 ) ;
memcpy ( V_27 -> V_39 , V_21 , V_38 ) ;
F_17 () ;
F_18 ( V_23 -> V_29 , V_25 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) ;
F_20 () ;
}
static void F_21 ( struct V_22 * V_23 , T_1 * V_21 ,
struct V_1 * V_2 , int V_43 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_24 * V_25 ;
struct V_44 * V_45 ;
if ( ! V_4 -> V_28 )
return;
F_13 ( V_23 -> V_29 -> V_30 ,
L_3 ,
V_31 , V_4 -> V_32 , V_43 ) ;
V_25 = F_14 ( sizeof( * V_45 ) ) ;
if ( ! V_25 )
return;
V_45 = ( void * ) F_15 ( V_25 , sizeof( * V_45 ) - V_38 ) ;
V_45 -> V_34 = F_16 ( V_46 |
V_47 |
( V_43 ? V_37 : 0 ) ) ;
V_45 -> V_48 = F_16 ( 0 ) ;
memcpy ( V_45 -> V_49 , V_4 -> V_32 , V_38 ) ;
memcpy ( V_45 -> V_50 , V_21 , V_38 ) ;
memcpy ( V_45 -> V_51 , V_4 -> V_32 , V_38 ) ;
F_17 () ;
F_18 ( V_23 -> V_29 , V_25 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) ;
F_20 () ;
}
static void F_22 ( void * V_20 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_20 ;
F_21 ( V_23 , V_21 , V_2 , 1 ) ;
}
static void F_23 ( void * V_20 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_20 ;
F_21 ( V_23 , V_21 , V_2 , 0 ) ;
}
static int F_24 ( void * V_20 , T_2 * V_52 )
{
struct V_22 * V_23 = V_20 ;
* V_52 = V_23 -> V_43 ;
return 0 ;
}
static int F_25 ( void * V_20 , T_2 V_52 )
{
struct V_22 * V_23 = V_20 ;
enum V_53 V_54 ;
if ( V_52 != V_55 && V_52 != V_56 && V_52 != V_57 &&
V_52 != V_58 )
return - V_59 ;
V_54 = V_23 -> V_43 ;
V_23 -> V_43 = V_52 ;
if ( V_52 == V_58 ) {
F_26 ( V_23 -> V_29 ,
V_60 ,
F_12 , V_23 ) ;
V_23 -> V_61 = true ;
} else if ( V_54 == V_55 && V_52 != V_55 ) {
F_26 ( V_23 -> V_29 ,
V_60 ,
F_22 ,
V_23 ) ;
} else if ( V_54 != V_55 && V_52 == V_55 ) {
F_26 ( V_23 -> V_29 ,
V_60 ,
F_23 ,
V_23 ) ;
}
return 0 ;
}
static int F_27 ( void * V_20 , T_2 V_52 )
{
struct V_22 * V_23 = V_20 ;
F_28 ( V_23 -> V_29 ) ;
return 0 ;
}
static int F_29 ( void * V_20 , T_2 * V_52 )
{
struct V_22 * V_23 = V_20 ;
* V_52 = V_23 -> V_62 ;
return 0 ;
}
static int F_30 ( void * V_20 , T_2 V_52 )
{
struct V_22 * V_23 = V_20 ;
V_23 -> V_62 = V_52 ;
return 0 ;
}
static T_3 F_31 ( struct V_24 * V_25 ,
struct V_63 * V_64 )
{
F_32 ( V_25 ) ;
return V_65 ;
}
static inline T_2 F_33 ( void )
{
return F_34 ( F_35 () ) ;
}
static T_4 F_36 ( struct V_22 * V_23 )
{
T_2 V_66 = F_33 () ;
return F_37 ( V_66 + V_23 -> V_67 ) ;
}
static T_2 F_38 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
return F_39 ( F_36 ( V_23 ) ) ;
}
static void F_40 ( struct V_68 * V_29 ,
struct V_1 * V_2 , T_2 V_70 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
T_2 V_66 = F_38 ( V_29 , V_2 ) ;
T_5 V_71 = V_23 -> V_72 ;
T_6 V_73 = V_70 - V_66 ;
V_23 -> V_67 += V_73 ;
V_23 -> V_74 = F_41 ( V_73 , V_71 ) ;
}
static void F_42 ( struct V_68 * V_29 ,
struct V_24 * V_75 ,
struct V_76 * V_42 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_24 * V_25 ;
struct V_77 * V_45 ;
T_7 V_78 ;
struct V_79 * V_80 = F_43 ( V_75 ) ;
struct V_81 * V_82 = F_44 ( V_29 , V_80 ) ;
if ( ! F_45 ( V_83 ) )
return;
V_25 = F_46 ( V_75 , sizeof( * V_45 ) , 0 , V_84 ) ;
if ( V_25 == NULL )
return;
V_45 = (struct V_77 * ) F_47 ( V_25 , sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_85 = V_86 ;
V_45 -> V_45 . V_87 = 0 ;
V_45 -> V_45 . V_88 = F_16 ( sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_89 = F_48 ( ( 1 << V_90 ) |
( 1 << V_91 ) |
( 1 << V_92 ) |
( 1 << V_93 ) ) ;
V_45 -> V_94 = F_36 ( V_23 ) ;
V_45 -> V_95 = 0 ;
V_45 -> V_96 = V_82 -> V_97 / 5 ;
V_45 -> V_98 = F_16 ( V_42 -> V_99 ) ;
V_78 = V_100 ;
if ( V_82 -> V_78 & V_101 )
V_78 |= V_102 ;
else
V_78 |= V_103 ;
V_45 -> V_104 = F_16 ( V_78 ) ;
V_25 -> V_64 = V_83 ;
F_49 ( V_25 , 0 ) ;
V_25 -> V_105 = V_106 ;
V_25 -> V_107 = V_108 ;
V_25 -> V_109 = F_50 ( V_110 ) ;
memset ( V_25 -> V_111 , 0 , sizeof( V_25 -> V_111 ) ) ;
F_51 ( V_25 ) ;
}
static void F_52 ( struct V_76 * V_42 ,
const T_1 * V_8 )
{
struct V_24 * V_25 ;
struct V_112 * V_45 ;
T_7 V_78 ;
struct V_44 * V_113 ;
if ( ! F_45 ( V_83 ) )
return;
V_25 = F_14 ( 100 ) ;
if ( V_25 == NULL )
return;
V_45 = (struct V_112 * ) F_15 ( V_25 , sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_85 = V_86 ;
V_45 -> V_45 . V_87 = 0 ;
V_45 -> V_45 . V_88 = F_16 ( sizeof( * V_45 ) ) ;
V_45 -> V_45 . V_89 = F_48 ( ( 1 << V_90 ) |
( 1 << V_93 ) ) ;
V_45 -> V_95 = 0 ;
V_45 -> V_114 = 0 ;
V_45 -> V_98 = F_16 ( V_42 -> V_99 ) ;
V_78 = V_100 ;
V_45 -> V_104 = F_16 ( V_78 ) ;
V_113 = (struct V_44 * ) F_15 ( V_25 , 10 ) ;
V_113 -> V_34 = F_16 ( V_35 |
V_115 ) ;
V_113 -> V_48 = F_16 ( 0 ) ;
memcpy ( V_113 -> V_49 , V_8 , V_38 ) ;
V_25 -> V_64 = V_83 ;
F_49 ( V_25 , 0 ) ;
V_25 -> V_105 = V_106 ;
V_25 -> V_107 = V_108 ;
V_25 -> V_109 = F_50 ( V_110 ) ;
memset ( V_25 -> V_111 , 0 , sizeof( V_25 -> V_111 ) ) ;
F_51 ( V_25 ) ;
}
static bool F_53 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
switch ( V_23 -> V_43 ) {
case V_55 :
return true ;
case V_56 :
return false ;
case V_57 :
return true ;
case V_58 :
if ( V_23 -> V_61 &&
memcmp ( V_23 -> V_29 -> V_30 -> V_116 , V_25 -> V_23 + 4 ,
V_38 ) == 0 ) {
V_23 -> V_61 = false ;
return true ;
}
return false ;
}
return true ;
}
static void F_54 ( void * V_23 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_117 * V_118 = V_23 ;
if ( memcmp ( V_21 , V_118 -> V_8 , V_38 ) == 0 )
V_118 -> V_119 = true ;
}
static bool F_55 ( struct V_22 * V_23 ,
const T_1 * V_8 )
{
struct V_117 V_118 ;
if ( memcmp ( V_8 , V_23 -> V_29 -> V_30 -> V_116 , V_38 ) == 0 )
return true ;
V_118 . V_119 = false ;
V_118 . V_8 = V_8 ;
F_56 ( V_23 -> V_29 ,
V_60 ,
F_54 ,
& V_118 ) ;
return V_118 . V_119 ;
}
static void F_57 ( struct V_68 * V_29 ,
struct V_24 * V_120 ,
int V_121 )
{
struct V_24 * V_25 ;
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_44 * V_45 = (struct V_44 * ) V_120 -> V_23 ;
struct V_79 * V_80 = F_43 ( V_120 ) ;
void * V_122 ;
unsigned int V_123 = 0 ;
int V_124 ;
struct V_125 V_126 [ V_127 ] ;
if ( V_23 -> V_43 != V_55 )
V_45 -> V_34 |= F_16 ( V_37 ) ;
if ( F_58 ( & V_23 -> V_128 ) >= V_129 ) {
while ( F_58 ( & V_23 -> V_128 ) >= V_130 )
F_59 ( & V_23 -> V_128 ) ;
}
V_25 = F_60 ( V_131 , V_84 ) ;
if ( V_25 == NULL )
goto V_132;
V_122 = F_61 ( V_25 , 0 , 0 , & V_133 , 0 ,
V_134 ) ;
if ( V_122 == NULL ) {
F_62 ( V_135 L_4 ) ;
goto V_132;
}
if ( F_63 ( V_25 , V_136 ,
V_38 , V_23 -> V_137 [ 1 ] . V_8 ) )
goto V_132;
if ( F_63 ( V_25 , V_138 , V_120 -> V_139 , V_120 -> V_23 ) )
goto V_132;
if ( V_80 -> V_78 & V_140 )
V_123 |= V_141 ;
if ( V_80 -> V_78 & V_142 )
V_123 |= V_143 ;
if ( F_64 ( V_25 , V_144 , V_123 ) )
goto V_132;
for ( V_124 = 0 ; V_124 < V_127 ; V_124 ++ ) {
V_126 [ V_124 ] . V_145 = V_80 -> V_146 . V_147 [ V_124 ] . V_145 ;
V_126 [ V_124 ] . V_148 = V_80 -> V_146 . V_147 [ V_124 ] . V_148 ;
}
if ( F_63 ( V_25 , V_149 ,
sizeof( struct V_125 ) * V_127 ,
V_126 ) )
goto V_132;
if ( F_65 ( V_25 , V_150 , ( unsigned long ) V_120 ) )
goto V_132;
F_66 ( V_25 , V_122 ) ;
F_67 ( & V_151 , V_25 , V_121 ) ;
F_68 ( & V_23 -> V_128 , V_120 ) ;
return;
V_132:
F_62 ( V_135 L_5 , V_31 ) ;
}
static bool F_69 ( struct V_76 * V_152 ,
struct V_76 * V_153 )
{
if ( ! V_152 || ! V_153 )
return false ;
return V_152 -> V_99 == V_153 -> V_99 ;
}
static void F_70 ( void * V_154 , T_1 * V_8 ,
struct V_1 * V_2 )
{
struct V_155 * V_23 = V_154 ;
if ( ! V_2 -> V_40 )
return;
if ( ! F_69 ( V_23 -> V_156 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) )
return;
V_23 -> V_157 = true ;
}
static bool F_71 ( struct V_68 * V_29 ,
struct V_24 * V_25 ,
struct V_76 * V_42 )
{
struct V_22 * V_23 = V_29 -> V_69 , * V_158 ;
bool V_159 = false ;
struct V_44 * V_45 = (struct V_44 * ) V_25 -> V_23 ;
struct V_79 * V_80 = F_43 ( V_25 ) ;
struct V_160 V_161 ;
T_2 V_66 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_162 |= V_163 ;
V_161 . V_164 = V_42 -> V_99 ;
V_161 . V_165 = V_42 -> V_165 ;
if ( V_80 -> V_166 . V_147 [ 0 ] . V_78 & V_167 ) {
V_161 . V_168 =
F_72 ( & V_80 -> V_166 . V_147 [ 0 ] ) ;
V_161 . V_169 =
F_73 ( & V_80 -> V_166 . V_147 [ 0 ] ) ;
V_161 . V_162 |= V_170 ;
} else {
V_161 . V_168 = V_80 -> V_166 . V_147 [ 0 ] . V_145 ;
if ( V_80 -> V_166 . V_147 [ 0 ] . V_78 & V_171 )
V_161 . V_162 |= V_172 ;
}
if ( V_80 -> V_166 . V_147 [ 0 ] . V_78 & V_173 )
V_161 . V_162 |= V_174 ;
if ( V_80 -> V_166 . V_147 [ 0 ] . V_78 & V_175 )
V_161 . V_162 |= V_176 ;
V_161 . signal = V_23 -> V_177 - 50 ;
if ( V_23 -> V_43 != V_55 )
V_45 -> V_34 |= F_16 ( V_37 ) ;
F_74 ( V_25 ) ;
F_75 ( V_25 ) ;
V_25 -> V_178 = 0 ;
F_76 ( V_25 ) ;
F_77 ( V_25 ) ;
if ( F_78 ( V_45 -> V_34 ) ||
F_79 ( V_45 -> V_34 ) )
V_66 = V_23 -> V_179 ;
else
V_66 = F_33 () ;
F_80 ( & V_180 ) ;
F_81 (data2, &hwsim_radios, list) {
struct V_24 * V_181 ;
struct V_155 V_155 = {
. V_157 = false ,
. V_156 = V_42 ,
} ;
if ( V_23 == V_158 )
continue;
if ( ! V_158 -> V_182 || ( V_158 -> V_183 && ! V_158 -> V_184 ) ||
! F_53 ( V_158 , V_25 ) )
continue;
if ( ! ( V_23 -> V_62 & V_158 -> V_62 ) )
continue;
if ( ! F_69 ( V_42 , V_158 -> V_184 ) &&
! F_69 ( V_42 , V_158 -> V_156 ) ) {
F_56 (
V_158 -> V_29 , V_60 ,
F_70 , & V_155 ) ;
if ( ! V_155 . V_157 )
continue;
}
if ( V_25 -> V_139 < V_185 && V_186 ) {
struct V_187 * V_187 = F_82 ( V_84 ) ;
if ( ! V_187 )
continue;
V_181 = F_14 ( 128 ) ;
if ( ! V_181 ) {
F_83 ( V_187 ) ;
continue;
}
memcpy ( F_84 ( V_187 ) , V_25 -> V_23 , V_25 -> V_139 ) ;
F_85 ( V_181 , 0 , V_187 , 0 , V_25 -> V_139 , V_25 -> V_139 ) ;
} else {
V_181 = F_86 ( V_25 , V_84 ) ;
if ( ! V_181 )
continue;
}
if ( F_55 ( V_158 , V_45 -> V_49 ) )
V_159 = true ;
V_161 . V_188 = V_66 + V_158 -> V_67 ;
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
memcpy ( F_87 ( V_181 ) , & V_161 , sizeof( V_161 ) ) ;
F_88 ( V_158 -> V_29 , V_181 ) ;
}
F_89 ( & V_180 ) ;
return V_159 ;
}
static void F_90 ( struct V_68 * V_29 ,
struct V_189 * V_166 ,
struct V_24 * V_25 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_79 * V_190 = F_43 ( V_25 ) ;
struct V_15 * V_40 ;
struct V_76 * V_156 ;
bool V_159 ;
T_5 V_191 ;
if ( F_6 ( V_25 -> V_139 < 10 ) ) {
F_91 ( V_29 , V_25 ) ;
return;
}
if ( V_23 -> V_192 == 1 ) {
V_156 = V_23 -> V_156 ;
} else if ( V_190 -> V_193 == 4 ) {
V_156 = V_23 -> V_184 ;
} else {
V_40 = F_19 ( V_190 -> V_166 . V_2 -> V_40 ) ;
if ( V_40 )
V_156 = V_40 -> V_41 . V_42 ;
else
V_156 = NULL ;
}
if ( F_2 ( ! V_156 , L_6 , V_190 -> V_193 ) ) {
F_91 ( V_29 , V_25 ) ;
return;
}
if ( V_23 -> V_183 && ! V_23 -> V_184 ) {
F_13 ( V_29 -> V_30 , L_7 ) ;
F_91 ( V_29 , V_25 ) ;
return;
}
if ( V_190 -> V_166 . V_2 )
F_1 ( V_190 -> V_166 . V_2 ) ;
if ( V_166 -> V_11 )
F_5 ( V_166 -> V_11 ) ;
if ( V_29 -> V_78 & V_194 )
F_92 ( V_190 -> V_166 . V_2 , V_166 -> V_11 , V_25 ,
V_190 -> V_166 . V_147 ,
F_93 ( V_190 -> V_166 . V_147 ) ) ;
V_190 -> V_195 [ 0 ] = V_156 ;
F_42 ( V_29 , V_25 , V_156 ) ;
V_191 = F_94 ( V_196 ) ;
if ( V_191 )
return F_57 ( V_29 , V_25 , V_191 ) ;
V_159 = F_71 ( V_29 , V_25 , V_156 ) ;
if ( V_159 && V_25 -> V_139 >= 16 ) {
struct V_44 * V_45 = (struct V_44 * ) V_25 -> V_23 ;
F_52 ( V_156 , V_45 -> V_50 ) ;
}
F_95 ( V_190 ) ;
V_190 -> V_166 . V_147 [ 0 ] . V_148 = 1 ;
V_190 -> V_166 . V_147 [ 1 ] . V_145 = - 1 ;
if ( ! ( V_190 -> V_78 & V_142 ) && V_159 )
V_190 -> V_78 |= V_197 ;
F_96 ( V_29 , V_25 ) ;
}
static int F_97 ( struct V_68 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_8 , V_31 ) ;
V_23 -> V_182 = true ;
return 0 ;
}
static void F_98 ( struct V_68 * V_29 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
V_23 -> V_182 = false ;
F_99 ( & V_23 -> V_198 ) ;
F_13 ( V_29 -> V_30 , L_8 , V_31 ) ;
}
static int F_100 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
F_13 ( V_29 -> V_30 , L_9 ,
V_31 , F_101 ( V_2 ) ,
V_2 -> V_8 ) ;
F_3 ( V_2 ) ;
V_2 -> V_199 = 0 ;
V_2 -> V_193 [ V_200 ] = 0 ;
V_2 -> V_193 [ V_201 ] = 1 ;
V_2 -> V_193 [ V_202 ] = 2 ;
V_2 -> V_193 [ V_203 ] = 3 ;
return 0 ;
}
static int F_102 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_204 V_205 ,
bool V_206 )
{
V_205 = F_103 ( V_205 , V_206 ) ;
F_13 ( V_29 -> V_30 ,
L_10 ,
V_31 , F_101 ( V_2 ) ,
V_205 , V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
V_2 -> V_199 = 0 ;
return 0 ;
}
static void F_104 (
struct V_68 * V_29 , struct V_1 * V_2 )
{
F_13 ( V_29 -> V_30 , L_9 ,
V_31 , F_101 ( V_2 ) ,
V_2 -> V_8 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static void F_18 ( struct V_68 * V_29 ,
struct V_24 * V_25 ,
struct V_76 * V_42 )
{
T_5 V_207 = F_94 ( V_196 ) ;
if ( V_29 -> V_78 & V_194 ) {
struct V_79 * V_190 = F_43 ( V_25 ) ;
F_92 ( V_190 -> V_166 . V_2 , NULL , V_25 ,
V_190 -> V_166 . V_147 ,
F_93 ( V_190 -> V_166 . V_147 ) ) ;
}
F_42 ( V_29 , V_25 , V_42 ) ;
if ( V_207 )
return F_57 ( V_29 , V_25 , V_207 ) ;
F_71 ( V_29 , V_25 , V_42 ) ;
F_32 ( V_25 ) ;
}
static void F_105 ( void * V_208 , T_1 * V_21 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = V_208 ;
struct V_68 * V_29 = V_23 -> V_29 ;
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_209 * V_210 ;
struct V_24 * V_25 ;
F_1 ( V_2 ) ;
if ( V_2 -> type != V_211 &&
V_2 -> type != V_212 &&
V_2 -> type != V_213 )
return;
V_25 = F_106 ( V_29 , V_2 ) ;
if ( V_25 == NULL )
return;
V_80 = F_43 ( V_25 ) ;
if ( V_29 -> V_78 & V_194 )
F_92 ( V_2 , NULL , V_25 ,
V_80 -> V_166 . V_147 ,
F_93 ( V_80 -> V_166 . V_147 ) ) ;
V_82 = F_44 ( V_29 , V_80 ) ;
V_210 = (struct V_209 * ) V_25 -> V_23 ;
V_23 -> V_179 = F_33 () ;
V_210 -> V_214 . V_215 . V_216 = F_37 ( V_23 -> V_179 +
V_23 -> V_67 +
24 * 8 * 10 / V_82 -> V_97 ) ;
F_18 ( V_29 , V_25 ,
F_19 ( V_2 -> V_40 ) -> V_41 . V_42 ) ;
}
static enum V_217
F_107 ( struct V_218 * V_219 )
{
struct V_22 * V_23 =
F_108 ( V_219 , struct V_22 ,
V_198 . V_219 ) ;
struct V_68 * V_29 = V_23 -> V_29 ;
T_2 V_71 = V_23 -> V_72 ;
T_8 V_220 ;
if ( ! V_23 -> V_182 )
goto V_221;
F_56 (
V_29 , V_60 ,
F_105 , V_23 ) ;
if ( V_23 -> V_74 ) {
V_71 -= V_23 -> V_74 ;
V_23 -> V_74 = 0 ;
}
V_220 = F_109 ( F_110 ( V_219 ) ,
F_111 ( V_71 * 1000 ) ) ;
F_112 ( & V_23 -> V_198 , V_220 , V_222 ) ;
V_221:
return V_223 ;
}
static int F_113 ( struct V_68 * V_29 , T_5 V_224 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
struct V_225 * V_226 = & V_29 -> V_226 ;
static const char * V_227 [ V_228 ] = {
[ V_229 ] = L_11 ,
[ V_230 ] = L_12 ,
[ V_231 ] = L_13 ,
[ V_232 ] = L_14 ,
} ;
if ( V_226 -> V_233 . V_42 )
F_13 ( V_29 -> V_30 ,
L_15 ,
V_31 ,
V_226 -> V_233 . V_42 -> V_99 ,
V_226 -> V_233 . V_234 ,
V_226 -> V_233 . V_235 ,
V_236 [ V_226 -> V_233 . V_237 ] ,
! ! ( V_226 -> V_78 & V_238 ) ,
! ! ( V_226 -> V_78 & V_239 ) ,
V_227 [ V_226 -> V_240 ] ) ;
else
F_13 ( V_29 -> V_30 ,
L_16 ,
V_31 ,
! ! ( V_226 -> V_78 & V_238 ) ,
! ! ( V_226 -> V_78 & V_239 ) ,
V_227 [ V_226 -> V_240 ] ) ;
V_23 -> V_183 = ! ! ( V_226 -> V_78 & V_238 ) ;
V_23 -> V_156 = V_226 -> V_233 . V_42 ;
F_6 ( V_23 -> V_156 && V_23 -> V_192 > 1 ) ;
V_23 -> V_177 = V_226 -> V_177 ;
if ( ! V_23 -> V_182 || ! V_23 -> V_72 )
F_99 ( & V_23 -> V_198 ) ;
else if ( ! F_114 ( & V_23 -> V_198 . V_219 ) ) {
T_2 V_70 = F_38 ( V_29 , NULL ) ;
T_5 V_71 = V_23 -> V_72 ;
T_2 V_241 = V_71 - F_41 ( V_70 , V_71 ) ;
F_112 ( & V_23 -> V_198 ,
F_111 ( V_241 * 1000 ) ,
V_242 ) ;
}
return 0 ;
}
static void F_115 ( struct V_68 * V_29 ,
unsigned int V_243 ,
unsigned int * V_244 , T_2 V_245 )
{
struct V_22 * V_23 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_8 , V_31 ) ;
V_23 -> V_246 = 0 ;
if ( * V_244 & V_247 )
V_23 -> V_246 |= V_247 ;
if ( * V_244 & V_248 )
V_23 -> V_246 |= V_248 ;
* V_244 = V_23 -> V_246 ;
}
static void F_116 ( void * V_23 , T_1 * V_21 ,
struct V_1 * V_2 )
{
unsigned int * V_148 = V_23 ;
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
if ( V_4 -> V_249 )
( * V_148 ) ++ ;
}
static void F_117 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_250 * V_80 ,
T_5 V_224 )
{
struct V_3 * V_4 = ( void * ) V_2 -> V_5 ;
struct V_22 * V_23 = V_29 -> V_69 ;
F_1 ( V_2 ) ;
F_13 ( V_29 -> V_30 , L_17 ,
V_31 , V_224 , V_2 -> V_8 ) ;
if ( V_224 & V_251 ) {
F_13 ( V_29 -> V_30 , L_18 ,
V_31 , V_80 -> V_32 ) ;
memcpy ( V_4 -> V_32 , V_80 -> V_32 , V_38 ) ;
}
if ( V_224 & V_252 ) {
F_13 ( V_29 -> V_30 , L_19 ,
V_80 -> V_28 , V_80 -> V_33 ) ;
V_4 -> V_28 = V_80 -> V_28 ;
V_4 -> V_33 = V_80 -> V_33 ;
}
if ( V_224 & V_253 ) {
F_13 ( V_29 -> V_30 , L_20 , V_80 -> V_72 ) ;
V_23 -> V_72 = V_80 -> V_72 * 1024 ;
}
if ( V_224 & V_254 ) {
F_13 ( V_29 -> V_30 , L_21 , V_80 -> V_255 ) ;
V_4 -> V_249 = V_80 -> V_255 ;
if ( V_23 -> V_182 &&
! F_114 ( & V_23 -> V_198 . V_219 ) &&
V_80 -> V_255 ) {
T_2 V_70 , V_241 ;
T_5 V_71 ;
if ( F_6 ( ! V_23 -> V_72 ) )
V_23 -> V_72 = 1000 * 1024 ;
V_70 = F_38 ( V_29 , V_2 ) ;
V_71 = V_23 -> V_72 ;
V_241 = V_71 - F_41 ( V_70 , V_71 ) ;
F_112 ( & V_23 -> V_198 ,
F_111 ( V_241 * 1000 ) ,
V_242 ) ;
} else if ( ! V_80 -> V_255 ) {
unsigned int V_148 = 0 ;
F_56 (
V_23 -> V_29 , V_60 ,
F_116 , & V_148 ) ;
F_13 ( V_29 -> V_30 , L_22 ,
V_148 ) ;
if ( V_148 == 0 )
F_99 ( & V_23 -> V_198 ) ;
}
}
if ( V_224 & V_256 ) {
F_13 ( V_29 -> V_30 , L_23 ,
V_80 -> V_257 ) ;
}
if ( V_224 & V_258 ) {
F_13 ( V_29 -> V_30 , L_24 ,
V_80 -> V_259 ) ;
}
if ( V_224 & V_260 ) {
F_13 ( V_29 -> V_30 , L_25 , V_80 -> V_261 ) ;
}
if ( V_224 & V_262 ) {
F_13 ( V_29 -> V_30 , L_26 ,
V_80 -> V_263 ) ;
}
if ( V_224 & V_264 ) {
F_13 ( V_29 -> V_30 , L_27 ,
( unsigned long long ) V_80 -> V_265 ) ;
}
if ( V_224 & V_266 )
F_13 ( V_29 -> V_30 , L_28 , V_80 -> V_267 ) ;
}
static int F_118 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
static int F_119 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
F_8 ( V_11 ) ;
return 0 ;
}
static void F_120 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_268 V_269 ,
struct V_10 * V_11 )
{
F_1 ( V_2 ) ;
switch ( V_269 ) {
case V_270 :
case V_271 :
break;
default:
F_2 ( 1 , L_29 , V_269 ) ;
break;
}
}
static int F_121 ( struct V_68 * V_29 ,
struct V_10 * V_11 ,
bool V_272 )
{
F_5 ( V_11 ) ;
return 0 ;
}
static int F_122 (
struct V_68 * V_29 ,
struct V_1 * V_2 , T_7 V_273 ,
const struct V_274 * V_275 )
{
F_13 ( V_29 -> V_30 ,
L_30 ,
V_31 , V_273 ,
V_275 -> V_276 , V_275 -> V_277 ,
V_275 -> V_278 , V_275 -> V_279 ) ;
return 0 ;
}
static int F_123 (
struct V_68 * V_29 , int V_145 ,
struct V_280 * V_281 )
{
struct V_225 * V_226 = & V_29 -> V_226 ;
F_13 ( V_29 -> V_30 , L_31 , V_31 , V_145 ) ;
if ( V_145 != 0 )
return - V_282 ;
V_281 -> V_156 = V_226 -> V_233 . V_42 ;
V_281 -> V_283 = V_284 ;
V_281 -> V_285 = - 92 ;
return 0 ;
}
static int F_124 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
void * V_23 , int V_139 )
{
struct V_22 * V_286 = V_29 -> V_69 ;
struct V_287 * V_288 [ V_289 + 1 ] ;
struct V_24 * V_25 ;
int V_290 , V_43 ;
V_290 = F_125 ( V_288 , V_289 , V_23 , V_139 ,
V_291 ) ;
if ( V_290 )
return V_290 ;
if ( ! V_288 [ V_292 ] )
return - V_59 ;
switch ( F_126 ( V_288 [ V_292 ] ) ) {
case V_293 :
if ( ! V_288 [ V_294 ] )
return - V_59 ;
V_43 = F_126 ( V_288 [ V_294 ] ) ;
return F_25 ( V_286 , V_43 ) ;
case V_295 :
V_25 = F_127 ( V_29 -> V_30 ,
F_128 ( sizeof( T_5 ) ) ) ;
if ( ! V_25 )
return - V_296 ;
if ( F_64 ( V_25 , V_294 , V_286 -> V_43 ) )
goto V_132;
return F_129 ( V_25 ) ;
case V_297 :
F_130 ( V_29 ) ;
return 0 ;
case V_298 :
F_131 ( V_29 ) ;
return 0 ;
default:
return - V_299 ;
}
V_132:
F_132 ( V_25 ) ;
return - V_300 ;
}
static int F_133 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
enum V_301 V_302 ,
struct V_10 * V_11 , T_7 V_303 , T_7 * V_304 ,
T_1 V_305 )
{
switch ( V_302 ) {
case V_306 :
F_134 ( V_2 , V_11 -> V_8 , V_303 ) ;
break;
case V_307 :
case V_308 :
case V_309 :
F_135 ( V_2 , V_11 -> V_8 , V_303 ) ;
break;
case V_310 :
break;
case V_311 :
case V_312 :
break;
default:
return - V_299 ;
}
return 0 ;
}
static void F_136 ( struct V_68 * V_29 , T_5 V_313 , bool V_314 )
{
}
static void F_137 ( struct V_315 * V_316 )
{
struct V_22 * V_286 =
F_108 ( V_316 , struct V_22 , V_317 . V_316 ) ;
struct V_318 * V_319 = V_286 -> V_320 ;
int V_321 , V_124 ;
F_138 ( & V_286 -> V_322 ) ;
if ( V_286 -> V_323 >= V_319 -> V_324 ) {
F_13 ( V_286 -> V_29 -> V_30 , L_32 ) ;
F_139 ( V_286 -> V_29 , false ) ;
V_286 -> V_320 = NULL ;
V_286 -> V_325 = NULL ;
V_286 -> V_184 = NULL ;
F_140 ( & V_286 -> V_322 ) ;
return;
}
F_13 ( V_286 -> V_29 -> V_30 , L_33 ,
V_319 -> V_192 [ V_286 -> V_323 ] -> V_99 ) ;
V_286 -> V_184 = V_319 -> V_192 [ V_286 -> V_323 ] ;
if ( V_286 -> V_184 -> V_78 & V_326 ||
! V_319 -> V_327 ) {
V_321 = 120 ;
} else {
V_321 = 30 ;
for ( V_124 = 0 ; V_124 < V_319 -> V_327 ; V_124 ++ ) {
struct V_24 * V_328 ;
V_328 = F_141 ( V_286 -> V_29 ,
V_286 -> V_325 ,
V_319 -> V_329 [ V_124 ] . V_330 ,
V_319 -> V_329 [ V_124 ] . V_331 ,
V_319 -> V_332 ) ;
if ( ! V_328 )
continue;
if ( V_319 -> V_332 )
memcpy ( F_15 ( V_328 , V_319 -> V_332 ) , V_319 -> V_333 ,
V_319 -> V_332 ) ;
F_142 () ;
F_18 ( V_286 -> V_29 , V_328 ,
V_286 -> V_184 ) ;
F_143 () ;
}
}
F_144 ( V_286 -> V_29 , & V_286 -> V_317 ,
F_145 ( V_321 ) ) ;
V_286 -> V_323 ++ ;
F_140 ( & V_286 -> V_322 ) ;
}
static int F_146 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_318 * V_319 )
{
struct V_22 * V_286 = V_29 -> V_69 ;
F_138 ( & V_286 -> V_322 ) ;
if ( F_6 ( V_286 -> V_184 || V_286 -> V_320 ) ) {
F_140 ( & V_286 -> V_322 ) ;
return - V_334 ;
}
V_286 -> V_320 = V_319 ;
V_286 -> V_325 = V_2 ;
V_286 -> V_323 = 0 ;
F_140 ( & V_286 -> V_322 ) ;
F_13 ( V_29 -> V_30 , L_34 ) ;
F_144 ( V_286 -> V_29 , & V_286 -> V_317 , 0 ) ;
return 0 ;
}
static void F_147 ( struct V_68 * V_29 ,
struct V_1 * V_2 )
{
struct V_22 * V_286 = V_29 -> V_69 ;
F_13 ( V_29 -> V_30 , L_35 ) ;
F_148 ( & V_286 -> V_317 ) ;
F_138 ( & V_286 -> V_322 ) ;
F_139 ( V_286 -> V_29 , true ) ;
V_286 -> V_184 = NULL ;
V_286 -> V_320 = NULL ;
V_286 -> V_325 = NULL ;
F_140 ( & V_286 -> V_322 ) ;
}
static void F_149 ( struct V_68 * V_29 )
{
struct V_22 * V_286 = V_29 -> V_69 ;
F_138 ( & V_286 -> V_322 ) ;
if ( V_286 -> V_335 ) {
F_62 ( V_135 L_36 ) ;
goto V_221;
}
F_62 ( V_135 L_37 ) ;
V_286 -> V_335 = true ;
V_221:
F_140 ( & V_286 -> V_322 ) ;
}
static void F_150 ( struct V_68 * V_29 )
{
struct V_22 * V_286 = V_29 -> V_69 ;
F_138 ( & V_286 -> V_322 ) ;
F_62 ( V_135 L_38 ) ;
V_286 -> V_335 = false ;
F_140 ( & V_286 -> V_322 ) ;
}
static void F_151 ( struct V_315 * V_316 )
{
struct V_22 * V_286 =
F_108 ( V_316 , struct V_22 , V_336 . V_316 ) ;
F_138 ( & V_286 -> V_322 ) ;
F_152 ( V_286 -> V_29 ) ;
V_286 -> V_184 = NULL ;
F_140 ( & V_286 -> V_322 ) ;
F_13 ( V_286 -> V_29 -> V_30 , L_39 ) ;
}
static int F_153 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_76 * V_42 ,
int V_337 ,
enum V_338 type )
{
struct V_22 * V_286 = V_29 -> V_69 ;
F_138 ( & V_286 -> V_322 ) ;
if ( F_6 ( V_286 -> V_184 || V_286 -> V_320 ) ) {
F_140 ( & V_286 -> V_322 ) ;
return - V_334 ;
}
V_286 -> V_184 = V_42 ;
F_140 ( & V_286 -> V_322 ) ;
F_13 ( V_29 -> V_30 , L_40 ,
V_42 -> V_99 , V_337 ) ;
F_154 ( V_29 ) ;
F_144 ( V_29 , & V_286 -> V_336 ,
F_145 ( V_337 ) ) ;
return 0 ;
}
static int F_155 ( struct V_68 * V_29 )
{
struct V_22 * V_286 = V_29 -> V_69 ;
F_148 ( & V_286 -> V_336 ) ;
F_138 ( & V_286 -> V_322 ) ;
V_286 -> V_184 = NULL ;
F_140 ( & V_286 -> V_322 ) ;
F_13 ( V_29 -> V_30 , L_41 ) ;
return 0 ;
}
static int F_156 ( struct V_68 * V_29 ,
struct V_15 * V_339 )
{
F_10 ( V_339 ) ;
F_13 ( V_29 -> V_30 ,
L_42 ,
V_339 -> V_41 . V_42 -> V_99 , V_339 -> V_41 . V_237 ,
V_339 -> V_41 . V_234 , V_339 -> V_41 . V_235 ) ;
return 0 ;
}
static void F_157 ( struct V_68 * V_29 ,
struct V_15 * V_339 )
{
F_13 ( V_29 -> V_30 ,
L_43 ,
V_339 -> V_41 . V_42 -> V_99 , V_339 -> V_41 . V_237 ,
V_339 -> V_41 . V_234 , V_339 -> V_41 . V_235 ) ;
F_9 ( V_339 ) ;
F_11 ( V_339 ) ;
}
static void F_158 ( struct V_68 * V_29 ,
struct V_15 * V_339 ,
T_5 V_224 )
{
F_9 ( V_339 ) ;
F_13 ( V_29 -> V_30 ,
L_44 ,
V_339 -> V_41 . V_42 -> V_99 , V_339 -> V_41 . V_237 ,
V_339 -> V_41 . V_234 , V_339 -> V_41 . V_235 ) ;
}
static int F_159 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_15 * V_339 )
{
F_1 ( V_2 ) ;
F_9 ( V_339 ) ;
return 0 ;
}
static void F_160 ( struct V_68 * V_29 ,
struct V_1 * V_2 ,
struct V_15 * V_339 )
{
F_1 ( V_2 ) ;
F_9 ( V_339 ) ;
}
static int F_161 ( int V_192 , const char * V_340 ,
const struct V_341 * V_342 ,
bool V_343 )
{
int V_290 ;
T_1 V_8 [ V_38 ] ;
struct V_22 * V_23 ;
struct V_68 * V_29 ;
enum V_344 V_165 ;
const struct V_345 * V_346 = & V_347 ;
int V_145 ;
F_162 ( & V_180 ) ;
V_145 = V_348 ++ ;
F_163 ( & V_180 ) ;
if ( V_192 > 1 )
V_346 = & V_349 ;
V_29 = F_164 ( sizeof( * V_23 ) , V_346 ) ;
if ( ! V_29 ) {
F_62 ( V_135 L_45 ) ;
V_290 = - V_296 ;
goto V_350;
}
V_23 = V_29 -> V_69 ;
V_23 -> V_29 = V_29 ;
V_23 -> V_64 = F_165 ( V_351 , NULL , 0 , V_29 , L_46 , V_145 ) ;
if ( F_166 ( V_23 -> V_64 ) ) {
F_62 ( V_135
L_47 ,
F_167 ( V_23 -> V_64 ) ) ;
V_290 = - V_296 ;
goto V_352;
}
V_23 -> V_64 -> V_353 = & V_354 . V_353 ;
V_290 = F_168 ( V_23 -> V_64 ) ;
if ( V_290 != 0 ) {
F_62 ( V_135 L_48 ,
V_290 ) ;
goto V_355;
}
F_169 ( & V_23 -> V_128 ) ;
F_170 ( V_29 , V_23 -> V_64 ) ;
memset ( V_8 , 0 , V_38 ) ;
V_8 [ 0 ] = 0x02 ;
V_8 [ 3 ] = V_145 >> 8 ;
V_8 [ 4 ] = V_145 ;
memcpy ( V_23 -> V_137 [ 0 ] . V_8 , V_8 , V_38 ) ;
memcpy ( V_23 -> V_137 [ 1 ] . V_8 , V_8 , V_38 ) ;
V_23 -> V_137 [ 1 ] . V_8 [ 0 ] |= 0x40 ;
V_29 -> V_30 -> V_356 = 2 ;
V_29 -> V_30 -> V_137 = V_23 -> V_137 ;
V_23 -> V_192 = V_192 ;
V_23 -> V_145 = V_145 ;
if ( V_23 -> V_192 > 1 ) {
V_29 -> V_30 -> V_357 = 255 ;
V_29 -> V_30 -> V_358 = V_359 ;
V_29 -> V_30 -> V_360 = 1000 ;
V_29 -> V_30 -> V_361 = 1 ;
V_29 -> V_30 -> V_362 = & V_23 -> V_363 ;
V_23 -> V_363 = V_364 [ 0 ] ;
V_23 -> V_363 . V_365 = V_23 -> V_192 ;
} else {
V_29 -> V_30 -> V_362 = V_364 ;
V_29 -> V_30 -> V_361 = F_93 ( V_364 ) ;
}
F_171 ( & V_23 -> V_336 , F_151 ) ;
F_171 ( & V_23 -> V_317 , F_137 ) ;
V_29 -> V_313 = 5 ;
V_29 -> V_366 = 4 ;
V_29 -> V_30 -> V_367 = F_172 ( V_368 ) |
F_172 ( V_211 ) |
F_172 ( V_369 ) |
F_172 ( V_370 ) |
F_172 ( V_213 ) |
F_172 ( V_212 ) |
F_172 ( V_371 ) ;
V_29 -> V_78 = V_372 |
V_373 |
V_374 |
V_375 |
V_376 |
V_377 |
V_378 |
V_379 ;
if ( V_380 )
V_29 -> V_78 |= V_194 ;
V_29 -> V_30 -> V_78 |= V_381 |
V_382 |
V_383 ;
V_29 -> V_30 -> V_384 |= V_385 ;
V_29 -> V_386 = sizeof( struct V_3 ) ;
V_29 -> V_387 = sizeof( struct V_12 ) ;
V_29 -> V_388 = sizeof( struct V_17 ) ;
memcpy ( V_23 -> V_389 , V_390 ,
sizeof( V_390 ) ) ;
memcpy ( V_23 -> V_391 , V_392 ,
sizeof( V_392 ) ) ;
memcpy ( V_23 -> V_147 , V_393 , sizeof( V_393 ) ) ;
for ( V_165 = V_394 ; V_165 < V_395 ; V_165 ++ ) {
struct V_396 * V_397 = & V_23 -> V_398 [ V_165 ] ;
switch ( V_165 ) {
case V_394 :
V_397 -> V_192 = V_23 -> V_389 ;
V_397 -> V_324 = F_93 ( V_390 ) ;
V_397 -> V_399 = V_23 -> V_147 ;
V_397 -> V_400 = F_93 ( V_393 ) ;
break;
case V_401 :
V_397 -> V_192 = V_23 -> V_391 ;
V_397 -> V_324 = F_93 ( V_392 ) ;
V_397 -> V_399 = V_23 -> V_147 + 4 ;
V_397 -> V_400 = F_93 ( V_393 ) - 4 ;
break;
default:
continue;
}
V_397 -> V_402 . V_403 = true ;
V_397 -> V_402 . V_404 = V_405 |
V_406 |
V_407 |
V_408 ;
V_397 -> V_402 . V_409 = 0x3 ;
V_397 -> V_402 . V_410 = 0x6 ;
memset ( & V_397 -> V_402 . V_411 , 0 ,
sizeof( V_397 -> V_402 . V_411 ) ) ;
V_397 -> V_402 . V_411 . V_412 [ 0 ] = 0xff ;
V_397 -> V_402 . V_411 . V_412 [ 1 ] = 0xff ;
V_397 -> V_402 . V_411 . V_413 = V_414 ;
V_29 -> V_30 -> V_398 [ V_165 ] = V_397 ;
V_397 -> V_415 . V_416 = true ;
V_397 -> V_415 . V_404 =
V_417 |
V_418 |
V_419 |
V_420 |
V_421 |
V_422 |
V_423 |
V_424 |
V_425 |
V_426 |
V_427 |
V_428 ;
V_397 -> V_415 . V_429 . V_430 =
F_16 ( V_431 << 0 |
V_431 << 2 |
V_432 << 4 |
V_431 << 6 |
V_431 << 8 |
V_432 << 10 |
V_432 << 12 |
V_431 << 14 ) ;
V_397 -> V_415 . V_429 . V_433 =
V_397 -> V_415 . V_429 . V_430 ;
}
V_23 -> V_62 = 1 ;
F_173 ( & V_23 -> V_322 ) ;
V_29 -> V_434 = 4 ;
V_29 -> V_435 = 11 ;
if ( V_343 )
V_29 -> V_30 -> V_436 |= V_437 ;
if ( V_342 ) {
V_29 -> V_30 -> V_436 |= V_438 ;
F_174 ( V_29 -> V_30 , V_342 ) ;
F_175 ( 1 ) ;
}
V_290 = F_176 ( V_29 ) ;
if ( V_290 < 0 ) {
F_62 ( V_135 L_49 ,
V_290 ) ;
goto V_355;
}
F_13 ( V_29 -> V_30 , L_50 , V_29 -> V_30 -> V_116 ) ;
if ( V_340 )
F_177 ( V_29 -> V_30 , V_340 ) ;
V_23 -> V_439 = F_178 ( L_51 , V_29 -> V_30 -> V_440 ) ;
F_179 ( L_52 , 0666 , V_23 -> V_439 , V_23 , & V_441 ) ;
F_179 ( L_53 , 0666 , V_23 -> V_439 , V_23 ,
& V_442 ) ;
if ( V_23 -> V_192 == 1 )
F_179 ( L_54 , 0222 ,
V_23 -> V_439 ,
V_23 , & V_443 ) ;
F_180 ( & V_23 -> V_198 ,
F_107 ,
V_444 , V_222 ) ;
F_162 ( & V_180 ) ;
F_181 ( & V_23 -> V_445 , & V_446 ) ;
F_163 ( & V_180 ) ;
return V_145 ;
V_355:
F_182 ( V_23 -> V_64 ) ;
V_352:
F_183 ( V_29 ) ;
V_350:
return V_290 ;
}
static void F_184 ( struct V_22 * V_23 )
{
F_185 ( V_23 -> V_439 ) ;
F_186 ( V_23 -> V_29 ) ;
F_187 ( V_23 -> V_64 ) ;
F_182 ( V_23 -> V_64 ) ;
F_183 ( V_23 -> V_29 ) ;
}
static void F_188 ( void )
{
struct V_22 * V_23 ;
F_162 ( & V_180 ) ;
while ( ( V_23 = F_189 ( & V_446 ,
struct V_22 ,
V_445 ) ) ) {
F_190 ( & V_23 -> V_445 ) ;
F_163 ( & V_180 ) ;
F_184 ( V_23 ) ;
F_162 ( & V_180 ) ;
}
F_163 ( & V_180 ) ;
F_191 ( V_351 ) ;
}
static void F_192 ( struct V_63 * V_64 )
{
V_64 -> V_447 = & V_448 ;
V_64 -> V_449 = V_450 ;
F_193 ( V_64 ) ;
V_64 -> V_451 = 0 ;
V_64 -> type = V_452 ;
memset ( V_64 -> V_453 , 0 , V_38 ) ;
V_64 -> V_453 [ 0 ] = 0x12 ;
}
static struct V_22 * F_194 ( const T_1 * V_8 )
{
struct V_22 * V_23 ;
bool V_454 = false ;
F_162 ( & V_180 ) ;
F_81 (data, &hwsim_radios, list) {
if ( memcmp ( V_23 -> V_137 [ 1 ] . V_8 , V_8 , V_38 ) == 0 ) {
V_454 = true ;
break;
}
}
F_163 ( & V_180 ) ;
if ( ! V_454 )
return NULL ;
return V_23 ;
}
static int F_195 ( struct V_24 * V_455 ,
struct V_456 * V_80 )
{
struct V_44 * V_45 ;
struct V_22 * V_158 ;
struct V_79 * V_190 ;
struct V_125 * V_126 ;
unsigned long V_457 ;
struct V_24 * V_25 , * V_458 ;
const T_1 * V_459 ;
unsigned int V_123 ;
int V_124 ;
bool V_460 = false ;
if ( V_80 -> V_461 != V_196 )
return - V_59 ;
if ( ! V_80 -> V_462 [ V_136 ] ||
! V_80 -> V_462 [ V_144 ] ||
! V_80 -> V_462 [ V_150 ] ||
! V_80 -> V_462 [ V_149 ] )
goto V_221;
V_459 = ( void * ) F_196 ( V_80 -> V_462 [ V_136 ] ) ;
V_123 = F_126 ( V_80 -> V_462 [ V_144 ] ) ;
V_457 = F_197 ( V_80 -> V_462 [ V_150 ] ) ;
V_158 = F_194 ( V_459 ) ;
if ( ! V_158 )
goto V_221;
F_198 (&data2->pending, skb, tmp) {
if ( ( unsigned long ) V_25 == V_457 ) {
F_199 ( V_25 , & V_158 -> V_128 ) ;
V_460 = true ;
break;
}
}
if ( ! V_460 )
goto V_221;
V_126 = (struct V_125 * ) F_196 (
V_80 -> V_462 [ V_149 ] ) ;
V_190 = F_43 ( V_25 ) ;
F_95 ( V_190 ) ;
for ( V_124 = 0 ; V_124 < V_127 ; V_124 ++ ) {
V_190 -> V_146 . V_147 [ V_124 ] . V_145 = V_126 [ V_124 ] . V_145 ;
V_190 -> V_146 . V_147 [ V_124 ] . V_148 = V_126 [ V_124 ] . V_148 ;
}
V_190 -> V_146 . V_463 = F_126 ( V_80 -> V_462 [ V_464 ] ) ;
if ( ! ( V_123 & V_143 ) &&
( V_123 & V_465 ) ) {
if ( V_25 -> V_139 >= 16 ) {
V_45 = (struct V_44 * ) V_25 -> V_23 ;
F_52 ( V_158 -> V_156 ,
V_45 -> V_50 ) ;
}
V_190 -> V_78 |= V_197 ;
}
F_96 ( V_158 -> V_29 , V_25 ) ;
return 0 ;
V_221:
return - V_59 ;
}
static int F_200 ( struct V_24 * V_455 ,
struct V_456 * V_80 )
{
struct V_22 * V_158 ;
struct V_160 V_161 ;
const T_1 * V_466 ;
int V_467 ;
void * V_468 ;
struct V_24 * V_25 = NULL ;
if ( V_80 -> V_461 != V_196 )
return - V_59 ;
if ( ! V_80 -> V_462 [ V_469 ] ||
! V_80 -> V_462 [ V_138 ] ||
! V_80 -> V_462 [ V_470 ] ||
! V_80 -> V_462 [ V_464 ] )
goto V_221;
V_466 = ( void * ) F_196 ( V_80 -> V_462 [ V_469 ] ) ;
V_467 = F_201 ( V_80 -> V_462 [ V_138 ] ) ;
V_468 = ( void * ) F_196 ( V_80 -> V_462 [ V_138 ] ) ;
V_25 = F_202 ( V_467 , V_471 ) ;
if ( V_25 == NULL )
goto V_290;
if ( V_467 > V_359 )
goto V_290;
memcpy ( F_15 ( V_25 , V_467 ) , V_468 , V_467 ) ;
V_158 = F_194 ( V_466 ) ;
if ( ! V_158 )
goto V_221;
if ( V_158 -> V_183 || ! V_158 -> V_182 )
goto V_221;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_164 = V_158 -> V_156 -> V_99 ;
V_161 . V_165 = V_158 -> V_156 -> V_165 ;
V_161 . V_168 = F_126 ( V_80 -> V_462 [ V_470 ] ) ;
V_161 . signal = F_126 ( V_80 -> V_462 [ V_464 ] ) ;
memcpy ( F_87 ( V_25 ) , & V_161 , sizeof( V_161 ) ) ;
F_88 ( V_158 -> V_29 , V_25 ) ;
return 0 ;
V_290:
F_62 ( V_135 L_5 , V_31 ) ;
goto V_221;
V_221:
F_32 ( V_25 ) ;
return - V_59 ;
}
static int F_203 ( struct V_24 * V_455 ,
struct V_456 * V_80 )
{
struct V_22 * V_23 ;
int V_472 = 1 ;
F_162 ( & V_180 ) ;
F_81 (data, &hwsim_radios, list)
V_472 = F_204 ( V_472 , V_23 -> V_192 ) ;
F_163 ( & V_180 ) ;
if ( V_472 > 1 )
return - V_299 ;
if ( V_196 )
return - V_334 ;
V_196 = V_80 -> V_461 ;
F_62 ( V_135 L_55
L_56 , V_80 -> V_461 ) ;
return 0 ;
}
static int F_205 ( struct V_24 * V_473 , struct V_456 * V_80 )
{
unsigned int V_472 = V_192 ;
const char * V_474 = NULL ;
const struct V_341 * V_342 = NULL ;
bool V_343 = V_80 -> V_462 [ V_475 ] ;
if ( V_80 -> V_462 [ V_476 ] )
V_472 = F_126 ( V_80 -> V_462 [ V_476 ] ) ;
if ( V_80 -> V_462 [ V_477 ] )
V_474 = F_196 ( V_80 -> V_462 [ V_477 ] ) ;
if ( V_80 -> V_462 [ V_478 ] ) {
T_5 V_145 = F_126 ( V_80 -> V_462 [ V_478 ] ) ;
if ( V_145 >= F_93 ( V_479 ) )
return - V_59 ;
V_342 = V_479 [ V_145 ] ;
}
return F_161 ( V_472 , V_474 , V_342 , V_343 ) ;
}
static int F_206 ( struct V_24 * V_473 , struct V_456 * V_80 )
{
struct V_22 * V_23 ;
int V_145 ;
if ( ! V_80 -> V_462 [ V_480 ] )
return - V_59 ;
V_145 = F_126 ( V_80 -> V_462 [ V_480 ] ) ;
F_162 ( & V_180 ) ;
F_81 (data, &hwsim_radios, list) {
if ( V_23 -> V_145 != V_145 )
continue;
F_190 ( & V_23 -> V_445 ) ;
F_163 ( & V_180 ) ;
F_184 ( V_23 ) ;
return 0 ;
}
F_163 ( & V_180 ) ;
return - V_481 ;
}
static int F_207 ( struct V_482 * V_483 ,
unsigned long V_484 ,
void * V_485 )
{
struct V_486 * V_487 = V_485 ;
if ( V_484 != V_488 )
return V_489 ;
if ( V_487 -> V_490 == V_196 ) {
F_62 ( V_491 L_57
L_58 ) ;
V_196 = 0 ;
}
return V_489 ;
}
static int F_208 ( void )
{
int V_492 ;
F_62 ( V_491 L_59 ) ;
V_492 = F_209 ( & V_133 , V_493 ) ;
if ( V_492 )
goto V_494;
V_492 = F_210 ( & V_495 ) ;
if ( V_492 )
goto V_494;
return 0 ;
V_494:
F_62 ( V_135 L_5 , V_31 ) ;
return - V_59 ;
}
static void F_211 ( void )
{
F_212 ( & V_495 ) ;
F_213 ( & V_133 ) ;
}
static int T_9 F_214 ( void )
{
int V_124 , V_290 ;
if ( V_496 < 0 || V_496 > 100 )
return - V_59 ;
if ( V_192 < 1 )
return - V_59 ;
V_349 = V_347 ;
V_349 . V_317 = F_146 ;
V_349 . V_497 = F_147 ;
V_349 . V_498 = NULL ;
V_349 . V_499 = NULL ;
V_349 . V_500 = F_153 ;
V_349 . V_501 = F_155 ;
V_349 . V_502 = F_156 ;
V_349 . V_503 = F_157 ;
V_349 . V_504 = F_158 ;
V_349 . V_505 =
F_159 ;
V_349 . V_506 =
F_160 ;
F_215 ( & V_180 ) ;
F_216 ( & V_446 ) ;
V_290 = F_217 ( & V_354 ) ;
if ( V_290 )
return V_290 ;
V_351 = F_218 ( V_507 , L_60 ) ;
if ( F_166 ( V_351 ) ) {
V_290 = F_167 ( V_351 ) ;
goto V_508;
}
for ( V_124 = 0 ; V_124 < V_496 ; V_124 ++ ) {
const char * V_340 = NULL ;
const struct V_341 * V_342 = NULL ;
bool V_343 = false ;
switch ( V_509 ) {
case V_510 :
if ( V_124 < F_93 ( V_511 ) )
V_340 = V_511 [ V_124 ] ;
break;
case V_512 :
if ( ! V_124 )
V_340 = V_511 [ 0 ] ;
break;
case V_513 :
V_343 = true ;
case V_514 :
V_340 = V_511 [ 0 ] ;
break;
case V_515 :
if ( V_124 == 0 )
V_342 = & V_516 ;
break;
case V_517 :
V_342 = & V_516 ;
break;
case V_518 :
if ( V_124 == 0 )
V_342 = & V_516 ;
else if ( V_124 == 1 )
V_342 = & V_519 ;
break;
case V_520 :
if ( V_124 == 0 ) {
V_343 = true ;
V_340 = V_511 [ 0 ] ;
}
break;
case V_521 :
if ( V_124 == 0 ) {
V_343 = true ;
V_340 = V_511 [ 0 ] ;
} else if ( V_124 == 1 ) {
V_340 = V_511 [ 1 ] ;
}
break;
case V_522 :
switch ( V_124 ) {
case 0 :
V_342 = & V_516 ;
break;
case 1 :
V_342 = & V_519 ;
break;
case 2 :
V_340 = V_511 [ 0 ] ;
break;
case 3 :
V_340 = V_511 [ 1 ] ;
break;
case 4 :
V_343 = true ;
V_340 = V_511 [ 2 ] ;
break;
}
break;
default:
break;
}
V_290 = F_161 ( V_192 , V_340 ,
V_342 , V_343 ) ;
if ( V_290 < 0 )
goto V_523;
}
V_83 = F_219 ( 0 , L_46 , F_192 ) ;
if ( V_83 == NULL ) {
V_290 = - V_296 ;
goto V_523;
}
F_220 () ;
V_290 = F_221 ( V_83 , V_83 -> V_524 ) ;
if ( V_290 < 0 ) {
F_222 () ;
goto V_523;
}
V_290 = F_223 ( V_83 ) ;
if ( V_290 < 0 ) {
F_222 () ;
goto V_525;
}
F_222 () ;
V_290 = F_208 () ;
if ( V_290 < 0 )
goto V_525;
return 0 ;
V_525:
V_450 ( V_83 ) ;
V_523:
F_188 () ;
V_508:
F_224 ( & V_354 ) ;
return V_290 ;
}
static void T_10 F_225 ( void )
{
F_62 ( V_135 L_61 ) ;
F_211 () ;
F_188 () ;
F_226 ( V_83 ) ;
F_224 ( & V_354 ) ;
}
