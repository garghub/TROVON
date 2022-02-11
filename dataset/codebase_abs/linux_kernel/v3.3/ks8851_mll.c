static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_4 ;
T_1 V_5 = V_3 & 0x03 ;
T_1 V_6 = ( V_3 & 1 ) << 3 ;
V_2 -> V_7 = ( T_2 ) V_3 | ( T_2 ) ( V_8 << V_5 ) ;
F_2 ( V_2 -> V_7 , V_2 -> V_9 ) ;
V_4 = F_3 ( V_2 -> V_10 ) ;
return ( T_1 ) ( V_4 >> V_6 ) ;
}
static T_2 F_4 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_7 = ( T_2 ) V_3 | ( ( V_11 | V_8 ) << ( V_3 & 0x02 ) ) ;
F_2 ( V_2 -> V_7 , V_2 -> V_9 ) ;
return F_3 ( V_2 -> V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_12 )
{
T_1 V_5 = ( V_3 & 0x03 ) ;
T_2 V_13 = ( T_2 ) ( V_12 << ( ( V_3 & 1 ) << 3 ) ) ;
V_2 -> V_7 = ( T_2 ) V_3 | ( V_8 << V_5 ) ;
F_2 ( V_2 -> V_7 , V_2 -> V_9 ) ;
F_2 ( V_13 , V_2 -> V_10 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 , T_2 V_12 )
{
V_2 -> V_7 = ( T_2 ) V_3 | ( ( V_11 | V_8 ) << ( V_3 & 0x02 ) ) ;
F_2 ( V_2 -> V_7 , V_2 -> V_9 ) ;
F_2 ( V_12 , V_2 -> V_10 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_2 * V_14 , T_3 V_15 )
{
V_15 >>= 1 ;
while ( V_15 -- )
* V_14 ++ = ( T_2 ) F_3 ( V_2 -> V_10 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_2 * V_14 , T_3 V_15 )
{
V_15 >>= 1 ;
while ( V_15 -- )
F_2 ( * V_14 ++ , V_2 -> V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_16 , 0x0000 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_16 , V_2 -> V_17 ) ;
}
static inline T_2 F_11 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_18 ) & 0x1fff ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
V_2 -> V_19 = V_2 -> V_7 ;
}
static inline void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_7 = V_2 -> V_19 ;
F_2 ( V_2 -> V_7 , V_2 -> V_9 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned V_20 )
{
unsigned V_21 ;
F_15 ( V_2 , V_22 , V_2 -> V_23 , L_1 , V_20 ) ;
F_4 ( V_2 , V_24 ) ;
V_21 = F_4 ( V_2 , V_25 ) ;
V_21 &= ~ V_26 ;
V_21 |= V_20 ;
F_6 ( V_2 , V_25 , V_21 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_2 V_27 = 0 ;
V_27 = F_1 ( V_2 , V_28 ) & 0x00FF ;
V_27 |= F_1 ( V_2 , V_28 + 1 ) << 8 ;
V_2 -> V_29 = ( V_27 & V_30 ) == V_30 ;
if ( V_27 & V_31 ) {
V_2 -> V_32 = V_33 ;
V_2 -> V_34 = 1 ;
} else if ( V_27 & V_35 ) {
V_2 -> V_32 = V_36 ;
V_2 -> V_34 = 2 ;
} else {
V_2 -> V_32 = V_37 ;
V_2 -> V_34 = 4 ;
}
}
static void F_17 ( struct V_1 * V_2 , unsigned V_38 )
{
F_6 ( V_2 , V_16 , 0x0000 ) ;
F_6 ( V_2 , V_24 , V_38 ) ;
F_18 ( 10 ) ;
F_6 ( V_2 , V_24 , 0 ) ;
F_18 ( 1 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
T_2 V_39 ;
V_39 = F_4 ( V_2 , V_40 ) ;
F_6 ( V_2 , V_40 , V_39 | V_41 ) ;
V_39 = F_4 ( V_2 , V_42 ) ;
F_6 ( V_2 , V_42 , V_39 | V_43 ) ;
V_39 = F_4 ( V_2 , V_44 ) ;
F_6 ( V_2 , V_44 , V_39 | V_45 ) ;
V_2 -> V_46 = true ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_2 V_39 ;
V_39 = F_4 ( V_2 , V_40 ) ;
V_39 &= ~ V_41 ;
F_6 ( V_2 , V_40 , V_39 ) ;
V_39 = F_4 ( V_2 , V_44 ) ;
V_39 &= ~ V_45 ;
F_6 ( V_2 , V_44 , V_39 ) ;
V_2 -> V_46 = false ;
}
static inline void F_21 ( struct V_1 * V_2 , T_2 * V_47 , T_3 V_15 )
{
T_3 V_48 = V_2 -> V_34 & 0x1 ;
T_3 V_39 = V_2 -> V_34 - V_48 ;
F_6 ( V_2 , V_49 , V_50 ) ;
F_5 ( V_2 , V_42 , ( V_2 -> V_51 | V_52 ) & 0xff ) ;
if ( F_22 ( V_48 ) )
F_23 ( V_2 -> V_10 ) ;
F_7 ( V_2 , V_47 , V_39 + 2 + 2 ) ;
F_7 ( V_2 , V_47 , F_24 ( V_15 , 4 ) ) ;
F_5 ( V_2 , V_42 , V_2 -> V_51 ) ;
}
static void F_25 ( struct V_1 * V_2 , struct V_53 * V_23 )
{
T_3 V_54 ;
struct V_55 * V_56 = V_2 -> V_57 ;
struct V_58 * V_59 ;
V_2 -> V_60 = F_4 ( V_2 , V_61 ) >> 8 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_60 ; V_54 ++ ) {
V_56 -> V_62 = F_4 ( V_2 , V_63 ) ;
V_56 -> V_15 = F_4 ( V_2 , V_64 ) ;
V_56 ++ ;
}
V_56 = V_2 -> V_57 ;
while ( V_2 -> V_60 -- ) {
V_59 = F_26 ( V_56 -> V_15 + 16 ) ;
if ( F_27 ( V_59 && ( V_56 -> V_62 & V_65 ) &&
( V_56 -> V_15 < V_66 ) && V_56 -> V_15 ) ) {
F_28 ( V_59 , 2 ) ;
F_21 ( V_2 , ( T_2 * ) V_59 -> V_4 , V_56 -> V_15 ) ;
F_29 ( V_59 , V_56 -> V_15 ) ;
V_59 -> V_67 = F_30 ( V_59 , V_23 ) ;
F_31 ( V_59 ) ;
} else {
F_32 ( L_2 , V_68 ) ;
F_6 ( V_2 , V_42 , ( V_2 -> V_51 | V_69 ) ) ;
if ( V_59 )
F_33 ( V_59 ) ;
}
V_56 ++ ;
}
}
static void F_34 ( struct V_53 * V_23 , struct V_1 * V_2 )
{
T_3 V_70 ;
if ( F_4 ( V_2 , V_71 ) & V_72 ) {
F_35 ( V_23 ) ;
V_70 = true ;
} else {
F_36 ( V_23 ) ;
V_70 = false ;
}
F_15 ( V_2 , V_73 , V_2 -> V_23 ,
L_3 , V_68 , V_70 ? L_4 : L_5 ) ;
}
static T_4 F_37 ( int V_74 , void * V_75 )
{
struct V_53 * V_23 = V_75 ;
struct V_1 * V_2 = F_38 ( V_23 ) ;
T_2 V_76 ;
F_12 ( V_2 ) ;
V_76 = F_4 ( V_2 , V_77 ) ;
if ( F_22 ( ! V_76 ) ) {
F_13 ( V_2 ) ;
return V_78 ;
}
F_6 ( V_2 , V_77 , V_76 ) ;
if ( F_27 ( V_76 & V_79 ) )
F_25 ( V_2 , V_23 ) ;
if ( F_22 ( V_76 & V_80 ) )
F_34 ( V_23 , V_2 ) ;
if ( F_22 ( V_76 & V_81 ) )
F_39 ( V_23 ) ;
if ( F_22 ( V_76 & V_82 ) ) {
T_2 V_21 = F_4 ( V_2 , V_25 ) ;
V_21 &= ~ V_83 ;
F_6 ( V_2 , V_25 , V_21 | V_84 ) ;
}
F_13 ( V_2 ) ;
return V_85 ;
}
static int F_40 ( struct V_53 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_86 ;
#define F_41 (IRQF_DISABLED|IRQF_TRIGGER_LOW)
F_15 ( V_2 , V_87 , V_2 -> V_23 , L_6 , V_68 ) ;
V_86 = F_42 ( V_23 -> V_74 , F_37 , F_41 , V_88 , V_23 ) ;
if ( V_86 ) {
F_32 ( L_7 , V_23 -> V_74 , V_86 ) ;
return V_86 ;
}
F_14 ( V_2 , V_89 ) ;
F_18 ( 1 ) ;
F_6 ( V_2 , V_77 , 0xffff ) ;
F_10 ( V_2 ) ;
F_19 ( V_2 ) ;
F_43 ( V_2 -> V_23 ) ;
F_15 ( V_2 , V_87 , V_2 -> V_23 , L_8 ) ;
return 0 ;
}
static int F_44 ( struct V_53 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_45 ( V_2 , V_90 , V_23 , L_9 ) ;
F_46 ( V_23 ) ;
F_47 ( & V_2 -> V_91 ) ;
F_6 ( V_2 , V_16 , 0x0000 ) ;
F_6 ( V_2 , V_77 , 0xffff ) ;
F_20 ( V_2 ) ;
F_14 ( V_2 , V_92 ) ;
F_48 ( V_23 -> V_74 , V_23 ) ;
F_49 ( & V_2 -> V_91 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 , T_1 * V_93 , T_2 V_15 )
{
V_2 -> V_94 . V_95 [ 0 ] = 0 ;
V_2 -> V_94 . V_95 [ 1 ] = F_51 ( V_15 ) ;
F_5 ( V_2 , V_42 , ( V_2 -> V_51 | V_52 ) & 0xff ) ;
F_8 ( V_2 , V_2 -> V_94 . V_95 , 4 ) ;
F_8 ( V_2 , ( T_2 * ) V_93 , F_24 ( V_15 , 4 ) ) ;
F_5 ( V_2 , V_42 , V_2 -> V_51 ) ;
F_6 ( V_2 , V_96 , V_97 ) ;
while ( F_4 ( V_2 , V_96 ) & V_97 )
;
}
static int F_52 ( struct V_58 * V_59 , struct V_53 * V_23 )
{
int V_98 = V_99 ;
struct V_1 * V_2 = F_38 ( V_23 ) ;
F_53 ( V_23 -> V_74 ) ;
F_9 ( V_2 ) ;
F_54 ( & V_2 -> V_100 ) ;
if ( F_27 ( F_11 ( V_2 ) >= V_59 -> V_15 + 12 ) ) {
F_50 ( V_2 , V_59 -> V_4 , V_59 -> V_15 ) ;
F_55 ( V_59 ) ;
} else
V_98 = V_101 ;
F_56 ( & V_2 -> V_100 ) ;
F_10 ( V_2 ) ;
F_57 ( V_23 -> V_74 ) ;
return V_98 ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_2 V_102 ;
V_102 = F_4 ( V_2 , V_44 ) ;
V_102 |= V_45 ;
F_6 ( V_2 , V_44 , V_102 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
T_2 V_102 ;
V_102 = F_4 ( V_2 , V_44 ) ;
V_102 &= ~ V_45 ;
F_6 ( V_2 , V_44 , V_102 ) ;
}
static unsigned long F_60 ( int V_103 , T_1 * V_4 )
{
long V_104 = - 1 ;
while ( -- V_103 >= 0 ) {
T_1 V_105 = * V_4 ++ ;
int V_106 ;
for ( V_106 = 0 ; V_106 < 8 ; V_106 ++ , V_105 >>= 1 ) {
V_104 = ( V_104 << 1 ) ^
( ( V_104 < 0 ) ^ ( V_105 & 1 ) ?
V_107 : 0 ) ;
}
}
return ( unsigned long ) V_104 ;
}
static void F_61 ( struct V_1 * V_2 )
{
T_1 V_54 ;
T_3 V_108 , V_109 , V_12 ;
memset ( V_2 -> V_110 , 0 , sizeof( T_1 ) * V_111 ) ;
for ( V_54 = 0 ; V_54 < V_2 -> V_112 ; V_54 ++ ) {
V_109 = ( F_60 ( 6 , V_2 -> V_113 [ V_54 ] ) >> 26 ) & 0x3f ;
V_108 = V_109 >> 3 ;
V_12 = 1 << ( V_109 & 7 ) ;
V_2 -> V_110 [ V_108 ] |= ( T_1 ) V_12 ;
}
for ( V_54 = 0 ; V_54 < V_111 ; V_54 ++ ) {
if ( V_54 & 1 ) {
F_6 ( V_2 , ( T_2 ) ( ( V_114 + V_54 ) & ~ 1 ) ,
( V_2 -> V_110 [ V_54 ] << 8 ) |
V_2 -> V_110 [ V_54 - 1 ] ) ;
}
}
}
static void F_62 ( struct V_1 * V_2 )
{
T_2 V_54 , V_115 ;
for ( V_54 = 0 ; V_54 < V_111 ; V_54 ++ )
V_2 -> V_110 [ V_54 ] = 0 ;
V_115 = V_111 >> 2 ;
for ( V_54 = 0 ; V_54 < V_115 ; V_54 ++ )
F_6 ( V_2 , V_114 + ( 2 * V_54 ) , 0 ) ;
}
static void F_63 ( struct V_1 * V_2 , T_2 V_116 )
{
T_2 V_102 ;
V_2 -> V_117 = V_116 ;
F_59 ( V_2 ) ;
V_102 = F_4 ( V_2 , V_44 ) ;
V_102 &= ~ V_118 ;
if ( V_116 )
V_102 |= V_119 | V_120 ;
else
V_102 |= V_121 ;
F_6 ( V_2 , V_44 , V_102 ) ;
if ( V_2 -> V_46 )
F_58 ( V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 , T_2 V_122 )
{
T_2 V_102 ;
V_2 -> V_123 = V_122 ;
F_59 ( V_2 ) ;
V_102 = F_4 ( V_2 , V_44 ) ;
V_102 &= ~ V_118 ;
if ( V_122 )
V_102 |= ( V_119 | V_124 | V_121 ) ;
else
V_102 |= V_121 ;
F_6 ( V_2 , V_44 , V_102 ) ;
if ( V_2 -> V_46 )
F_58 ( V_2 ) ;
}
static void F_65 ( struct V_53 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_125 * V_126 ;
if ( ( V_23 -> V_127 & V_128 ) == V_128 )
F_63 ( V_2 ,
( T_2 ) ( ( V_23 -> V_127 & V_128 ) == V_128 ) ) ;
else if ( ( V_23 -> V_127 & V_129 ) == V_129 )
F_64 ( V_2 ,
( T_2 ) ( ( V_23 -> V_127 & V_129 ) == V_129 ) ) ;
else
F_63 ( V_2 , false ) ;
if ( ( V_23 -> V_127 & V_130 ) && F_66 ( V_23 ) ) {
if ( F_66 ( V_23 ) <= V_131 ) {
int V_54 = 0 ;
F_67 (ha, netdev) {
if ( V_54 >= V_131 )
break;
memcpy ( V_2 -> V_113 [ V_54 ++ ] , V_126 -> V_132 , V_133 ) ;
}
V_2 -> V_112 = ( T_1 ) V_54 ;
F_61 ( V_2 ) ;
} else {
V_2 -> V_112 = V_131 ;
F_64 ( V_2 , true ) ;
}
} else {
V_2 -> V_112 = 0 ;
F_62 ( V_2 ) ;
}
}
static void F_68 ( struct V_1 * V_2 , T_1 * V_4 )
{
T_2 * V_75 = ( T_2 * ) V_4 ;
T_2 V_39 , V_134 ;
F_59 ( V_2 ) ;
V_134 = * V_75 ++ ;
V_39 = ( ( V_134 & 0xFF ) << 8 ) | ( ( V_134 >> 8 ) & 0xFF ) ;
F_6 ( V_2 , V_135 , V_39 ) ;
V_134 = * V_75 ++ ;
V_39 = ( ( V_134 & 0xFF ) << 8 ) | ( ( V_134 >> 8 ) & 0xFF ) ;
F_6 ( V_2 , V_136 , V_39 ) ;
V_134 = * V_75 ;
V_39 = ( ( V_134 & 0xFF ) << 8 ) | ( ( V_134 >> 8 ) & 0xFF ) ;
F_6 ( V_2 , V_137 , V_39 ) ;
memcpy ( V_2 -> V_138 , V_4 , 6 ) ;
if ( V_2 -> V_46 )
F_58 ( V_2 ) ;
}
static int F_69 ( struct V_53 * V_23 , void * V_139 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_140 * V_132 = V_139 ;
T_1 * V_141 ;
memcpy ( V_23 -> V_142 , V_132 -> V_143 , V_23 -> V_144 ) ;
V_141 = ( T_1 * ) V_23 -> V_142 ;
F_68 ( V_2 , V_141 ) ;
return 0 ;
}
static int F_70 ( struct V_53 * V_23 , struct V_145 * V_146 , int V_147 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
if ( ! F_71 ( V_23 ) )
return - V_148 ;
return F_72 ( & V_2 -> V_149 , F_73 ( V_146 ) , V_147 , NULL ) ;
}
static void F_74 ( struct V_53 * V_23 ,
struct V_150 * V_151 )
{
F_75 ( V_151 -> V_152 , V_88 , sizeof( V_151 -> V_152 ) ) ;
F_75 ( V_151 -> V_153 , L_10 , sizeof( V_151 -> V_153 ) ) ;
F_75 ( V_151 -> V_154 , F_76 ( V_23 -> V_155 . V_156 ) ,
sizeof( V_151 -> V_154 ) ) ;
}
static T_3 F_77 ( struct V_53 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
return V_2 -> V_157 ;
}
static void F_78 ( struct V_53 * V_23 , T_3 V_158 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
V_2 -> V_157 = V_158 ;
}
static int F_79 ( struct V_53 * V_23 , struct V_159 * V_147 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
return F_80 ( & V_2 -> V_149 , V_147 ) ;
}
static int F_81 ( struct V_53 * V_23 , struct V_159 * V_147 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
return F_82 ( & V_2 -> V_149 , V_147 ) ;
}
static T_3 F_83 ( struct V_53 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
return F_84 ( & V_2 -> V_149 ) ;
}
static int F_85 ( struct V_53 * V_23 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
return F_86 ( & V_2 -> V_149 ) ;
}
static int F_87 ( int V_160 )
{
switch ( V_160 ) {
case V_161 :
return V_162 ;
case V_163 :
return V_164 ;
case V_165 :
return V_166 ;
case V_167 :
return V_168 ;
case V_169 :
return V_170 ;
case V_171 :
return V_172 ;
}
return 0x0 ;
}
static int F_88 ( struct V_53 * V_23 , int V_173 , int V_160 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_174 ;
int V_175 ;
V_174 = F_87 ( V_160 ) ;
if ( ! V_174 )
return 0x0 ;
F_47 ( & V_2 -> V_91 ) ;
V_175 = F_4 ( V_2 , V_174 ) ;
F_49 ( & V_2 -> V_91 ) ;
return V_175 ;
}
static void F_89 ( struct V_53 * V_23 ,
int V_176 , int V_160 , int V_12 )
{
struct V_1 * V_2 = F_38 ( V_23 ) ;
int V_174 ;
V_174 = F_87 ( V_160 ) ;
if ( V_174 ) {
F_47 ( & V_2 -> V_91 ) ;
F_6 ( V_2 , V_174 , V_12 ) ;
F_49 ( & V_2 -> V_91 ) ;
}
}
static int F_90 ( struct V_1 * V_2 )
{
unsigned V_177 = V_178 | V_179 ;
int V_180 = 0 ;
unsigned V_181 ;
V_181 = F_4 ( V_2 , V_182 ) ;
if ( ( V_181 & V_177 ) != V_177 ) {
F_91 ( V_2 -> V_23 , L_11 ) ;
return 0 ;
}
if ( V_181 & V_183 ) {
F_92 ( V_2 -> V_23 , L_12 ) ;
V_180 |= 1 ;
}
if ( V_181 & V_184 ) {
F_92 ( V_2 -> V_23 , L_13 ) ;
V_180 |= 2 ;
}
F_93 ( V_2 -> V_23 , L_14 ) ;
return V_180 ;
}
static void F_94 ( struct V_1 * V_2 )
{
T_2 V_39 ;
F_6 ( V_2 , V_185 , V_186 ) ;
F_6 ( V_2 , V_49 , V_50 ) ;
F_6 ( V_2 , V_61 , 1 & V_187 ) ;
V_2 -> V_51 = V_188 ;
F_6 ( V_2 , V_42 , V_2 -> V_51 ) ;
V_39 = F_4 ( V_2 , V_162 ) ;
V_39 &= ~ V_189 ;
F_6 ( V_2 , V_162 , V_39 ) ;
V_39 = V_190 | V_191 | V_192 | V_193 ;
F_6 ( V_2 , V_40 , V_39 ) ;
V_39 = V_194 | V_195 | V_196 | V_197 | V_198 ;
if ( V_2 -> V_117 )
V_39 |= ( V_119 | V_120 ) ;
else if ( V_2 -> V_123 )
V_39 |= ( V_119 | V_124 | V_121 ) ;
else
V_39 |= V_121 ;
F_6 ( V_2 , V_44 , V_39 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
V_2 -> V_17 = 0x00 ;
F_6 ( V_2 , V_77 , 0xffff ) ;
V_2 -> V_17 = ( V_80 | V_81 | V_79 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
#define F_97 (sizeof(struct type_frame_head) * MAX_RECV_FRAMES)
V_2 -> V_117 = 0 ;
V_2 -> V_123 = 0 ;
V_2 -> V_112 = 0 ;
V_2 -> V_57 = F_98 ( F_97 , V_199 ) ;
if ( ! V_2 -> V_57 ) {
F_32 ( L_15 ) ;
return false ;
}
F_68 ( V_2 , V_200 ) ;
return true ;
}
static int T_5 F_99 ( struct V_201 * V_202 )
{
int V_86 = - V_203 ;
struct V_204 * V_205 , * V_206 ;
struct V_53 * V_23 ;
struct V_1 * V_2 ;
T_2 V_207 , V_4 ;
V_205 = F_100 ( V_202 , V_208 , 0 ) ;
V_206 = F_100 ( V_202 , V_208 , 1 ) ;
if ( ! F_101 ( V_205 -> V_209 , F_102 ( V_205 ) , V_88 ) )
goto V_210;
if ( ! F_101 ( V_206 -> V_209 , F_102 ( V_206 ) , V_88 ) )
goto V_211;
V_23 = F_103 ( sizeof( struct V_1 ) ) ;
if ( ! V_23 )
goto V_212;
F_104 ( V_23 , & V_202 -> V_155 ) ;
V_2 = F_38 ( V_23 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_10 = F_105 ( V_205 -> V_209 , F_102 ( V_205 ) ) ;
if ( ! V_2 -> V_10 )
goto V_213;
V_2 -> V_9 = F_105 ( V_206 -> V_209 , F_102 ( V_206 ) ) ;
if ( ! V_2 -> V_9 )
goto V_214;
V_23 -> V_74 = F_106 ( V_202 , 0 ) ;
if ( ( int ) V_23 -> V_74 < 0 ) {
V_86 = V_23 -> V_74 ;
goto V_215;
}
V_2 -> V_202 = V_202 ;
F_107 ( & V_2 -> V_91 ) ;
F_108 ( & V_2 -> V_100 ) ;
V_23 -> V_216 = & V_217 ;
V_23 -> V_218 = & V_219 ;
V_2 -> V_149 . V_155 = V_23 ;
V_2 -> V_149 . V_220 = 1 ,
V_2 -> V_149 . V_221 = 1 ;
V_2 -> V_149 . V_222 = 0xf ;
V_2 -> V_149 . V_223 = F_88 ;
V_2 -> V_149 . V_224 = F_89 ;
F_93 ( V_23 , L_16 , V_157 ) ;
V_2 -> V_157 = F_109 ( V_157 , ( V_225 |
V_226 |
V_227 ) ) ;
F_16 ( V_2 ) ;
if ( ( F_4 ( V_2 , V_228 ) & ~ V_229 ) != V_230 ) {
F_92 ( V_23 , L_17 ) ;
V_86 = - V_231 ;
goto V_232;
}
if ( F_90 ( V_2 ) ) {
F_92 ( V_23 , L_17 ) ;
V_86 = - V_231 ;
goto V_232;
}
V_86 = F_110 ( V_23 ) ;
if ( V_86 )
goto V_232;
F_111 ( V_202 , V_23 ) ;
F_17 ( V_2 , V_233 ) ;
F_96 ( V_2 ) ;
F_20 ( V_2 ) ;
F_94 ( V_2 ) ;
F_95 ( V_2 ) ;
memcpy ( V_23 -> V_142 , V_2 -> V_138 , 6 ) ;
V_4 = F_4 ( V_2 , V_234 ) ;
F_6 ( V_2 , V_234 , V_4 | V_235 ) ;
F_112 ( V_23 -> V_142 ) ;
F_68 ( V_2 , V_23 -> V_142 ) ;
V_207 = F_4 ( V_2 , V_228 ) ;
F_93 ( V_23 , L_18 ,
( V_207 >> 8 ) & 0xff , ( V_207 >> 4 ) & 0xf , ( V_207 >> 1 ) & 0x7 ) ;
return 0 ;
V_232:
V_215:
F_113 ( V_2 -> V_9 ) ;
V_214:
F_113 ( V_2 -> V_10 ) ;
V_213:
F_114 ( V_23 ) ;
V_212:
F_115 ( V_206 -> V_209 , F_102 ( V_206 ) ) ;
V_211:
F_115 ( V_205 -> V_209 , F_102 ( V_205 ) ) ;
V_210:
return V_86 ;
}
static int T_6 F_116 ( struct V_201 * V_202 )
{
struct V_53 * V_23 = F_117 ( V_202 ) ;
struct V_1 * V_2 = F_38 ( V_23 ) ;
struct V_204 * V_236 = F_100 ( V_202 , V_208 , 0 ) ;
F_118 ( V_2 -> V_57 ) ;
F_119 ( V_23 ) ;
F_113 ( V_2 -> V_10 ) ;
F_114 ( V_23 ) ;
F_115 ( V_236 -> V_209 , F_102 ( V_236 ) ) ;
F_111 ( V_202 , NULL ) ;
return 0 ;
}
