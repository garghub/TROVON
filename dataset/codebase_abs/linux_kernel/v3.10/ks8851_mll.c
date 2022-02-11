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
if ( F_22 ( ! ( V_56 -> V_62 & V_65 ) ||
V_56 -> V_15 >= V_66 ||
V_56 -> V_15 <= 0 ) ) {
F_6 ( V_2 , V_42 , ( V_2 -> V_51 | V_67 ) ) ;
V_23 -> V_68 . V_69 ++ ;
if ( ! ( V_56 -> V_62 & V_65 ) )
V_23 -> V_68 . V_70 ++ ;
else
V_23 -> V_68 . V_71 ++ ;
V_56 ++ ;
continue;
}
V_59 = F_26 ( V_23 , V_56 -> V_15 + 16 ) ;
if ( F_27 ( V_59 ) ) {
F_28 ( V_59 , 2 ) ;
F_21 ( V_2 , ( T_2 * ) V_59 -> V_4 , V_56 -> V_15 ) ;
F_29 ( V_59 , V_56 -> V_15 - 4 ) ;
V_59 -> V_72 = F_30 ( V_59 , V_23 ) ;
F_31 ( V_59 ) ;
V_23 -> V_68 . V_73 += V_56 -> V_15 - 4 ;
V_23 -> V_68 . V_74 ++ ;
} else {
F_6 ( V_2 , V_42 , ( V_2 -> V_51 | V_67 ) ) ;
V_23 -> V_68 . V_69 ++ ;
}
V_56 ++ ;
}
}
static void F_32 ( struct V_53 * V_23 , struct V_1 * V_2 )
{
T_3 V_75 ;
if ( F_4 ( V_2 , V_76 ) & V_77 ) {
F_33 ( V_23 ) ;
V_75 = true ;
} else {
F_34 ( V_23 ) ;
V_75 = false ;
}
F_15 ( V_2 , V_78 , V_2 -> V_23 ,
L_2 , V_79 , V_75 ? L_3 : L_4 ) ;
}
static T_4 F_35 ( int V_80 , void * V_81 )
{
struct V_53 * V_23 = V_81 ;
struct V_1 * V_2 = F_36 ( V_23 ) ;
T_2 V_82 ;
F_12 ( V_2 ) ;
V_82 = F_4 ( V_2 , V_83 ) ;
if ( F_22 ( ! V_82 ) ) {
F_13 ( V_2 ) ;
return V_84 ;
}
F_6 ( V_2 , V_83 , V_82 ) ;
if ( F_27 ( V_82 & V_85 ) )
F_25 ( V_2 , V_23 ) ;
if ( F_22 ( V_82 & V_86 ) )
F_32 ( V_23 , V_2 ) ;
if ( F_22 ( V_82 & V_87 ) )
F_37 ( V_23 ) ;
if ( F_22 ( V_82 & V_88 ) ) {
T_2 V_21 = F_4 ( V_2 , V_25 ) ;
V_21 &= ~ V_89 ;
F_6 ( V_2 , V_25 , V_21 | V_90 ) ;
}
if ( F_22 ( V_82 & V_91 ) )
V_2 -> V_23 -> V_68 . V_92 ++ ;
F_13 ( V_2 ) ;
return V_93 ;
}
static int F_38 ( struct V_53 * V_23 )
{
struct V_1 * V_2 = F_36 ( V_23 ) ;
int V_94 ;
#define F_39 (IRQF_DISABLED|IRQF_TRIGGER_LOW)
F_15 ( V_2 , V_95 , V_2 -> V_23 , L_5 , V_79 ) ;
V_94 = F_40 ( V_23 -> V_80 , F_35 , F_39 , V_96 , V_23 ) ;
if ( V_94 ) {
F_41 ( L_6 , V_23 -> V_80 , V_94 ) ;
return V_94 ;
}
F_14 ( V_2 , V_97 ) ;
F_18 ( 1 ) ;
F_6 ( V_2 , V_83 , 0xffff ) ;
F_10 ( V_2 ) ;
F_19 ( V_2 ) ;
F_42 ( V_2 -> V_23 ) ;
F_15 ( V_2 , V_95 , V_2 -> V_23 , L_7 ) ;
return 0 ;
}
static int F_43 ( struct V_53 * V_23 )
{
struct V_1 * V_2 = F_36 ( V_23 ) ;
F_44 ( V_2 , V_98 , V_23 , L_8 ) ;
F_45 ( V_23 ) ;
F_46 ( & V_2 -> V_99 ) ;
F_6 ( V_2 , V_16 , 0x0000 ) ;
F_6 ( V_2 , V_83 , 0xffff ) ;
F_20 ( V_2 ) ;
F_14 ( V_2 , V_100 ) ;
F_47 ( V_23 -> V_80 , V_23 ) ;
F_48 ( & V_2 -> V_99 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 , T_1 * V_101 , T_2 V_15 )
{
V_2 -> V_102 . V_103 [ 0 ] = 0 ;
V_2 -> V_102 . V_103 [ 1 ] = F_50 ( V_15 ) ;
F_5 ( V_2 , V_42 , ( V_2 -> V_51 | V_52 ) & 0xff ) ;
F_8 ( V_2 , V_2 -> V_102 . V_103 , 4 ) ;
F_8 ( V_2 , ( T_2 * ) V_101 , F_24 ( V_15 , 4 ) ) ;
F_5 ( V_2 , V_42 , V_2 -> V_51 ) ;
F_6 ( V_2 , V_104 , V_105 ) ;
while ( F_4 ( V_2 , V_104 ) & V_105 )
;
}
static int F_51 ( struct V_58 * V_59 , struct V_53 * V_23 )
{
int V_106 = V_107 ;
struct V_1 * V_2 = F_36 ( V_23 ) ;
F_52 ( V_23 -> V_80 ) ;
F_9 ( V_2 ) ;
F_53 ( & V_2 -> V_108 ) ;
if ( F_27 ( F_11 ( V_2 ) >= V_59 -> V_15 + 12 ) ) {
F_49 ( V_2 , V_59 -> V_4 , V_59 -> V_15 ) ;
V_23 -> V_68 . V_109 += V_59 -> V_15 ;
V_23 -> V_68 . V_110 ++ ;
F_54 ( V_59 ) ;
} else
V_106 = V_111 ;
F_55 ( & V_2 -> V_108 ) ;
F_10 ( V_2 ) ;
F_56 ( V_23 -> V_80 ) ;
return V_106 ;
}
static void F_57 ( struct V_1 * V_2 )
{
T_2 V_112 ;
V_112 = F_4 ( V_2 , V_44 ) ;
V_112 |= V_45 ;
F_6 ( V_2 , V_44 , V_112 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_2 V_112 ;
V_112 = F_4 ( V_2 , V_44 ) ;
V_112 &= ~ V_45 ;
F_6 ( V_2 , V_44 , V_112 ) ;
}
static unsigned long F_59 ( int V_113 , T_1 * V_4 )
{
long V_114 = - 1 ;
while ( -- V_113 >= 0 ) {
T_1 V_115 = * V_4 ++ ;
int V_116 ;
for ( V_116 = 0 ; V_116 < 8 ; V_116 ++ , V_115 >>= 1 ) {
V_114 = ( V_114 << 1 ) ^
( ( V_114 < 0 ) ^ ( V_115 & 1 ) ?
V_117 : 0 ) ;
}
}
return ( unsigned long ) V_114 ;
}
static void F_60 ( struct V_1 * V_2 )
{
T_1 V_54 ;
T_3 V_118 , V_119 , V_12 ;
memset ( V_2 -> V_120 , 0 , sizeof( T_1 ) * V_121 ) ;
for ( V_54 = 0 ; V_54 < V_2 -> V_122 ; V_54 ++ ) {
V_119 = ( F_59 ( 6 , V_2 -> V_123 [ V_54 ] ) >> 26 ) & 0x3f ;
V_118 = V_119 >> 3 ;
V_12 = 1 << ( V_119 & 7 ) ;
V_2 -> V_120 [ V_118 ] |= ( T_1 ) V_12 ;
}
for ( V_54 = 0 ; V_54 < V_121 ; V_54 ++ ) {
if ( V_54 & 1 ) {
F_6 ( V_2 , ( T_2 ) ( ( V_124 + V_54 ) & ~ 1 ) ,
( V_2 -> V_120 [ V_54 ] << 8 ) |
V_2 -> V_120 [ V_54 - 1 ] ) ;
}
}
}
static void F_61 ( struct V_1 * V_2 )
{
T_2 V_54 , V_125 ;
for ( V_54 = 0 ; V_54 < V_121 ; V_54 ++ )
V_2 -> V_120 [ V_54 ] = 0 ;
V_125 = V_121 >> 2 ;
for ( V_54 = 0 ; V_54 < V_125 ; V_54 ++ )
F_6 ( V_2 , V_124 + ( 2 * V_54 ) , 0 ) ;
}
static void F_62 ( struct V_1 * V_2 , T_2 V_126 )
{
T_2 V_112 ;
V_2 -> V_127 = V_126 ;
F_58 ( V_2 ) ;
V_112 = F_4 ( V_2 , V_44 ) ;
V_112 &= ~ V_128 ;
if ( V_126 )
V_112 |= V_129 | V_130 ;
else
V_112 |= V_131 ;
F_6 ( V_2 , V_44 , V_112 ) ;
if ( V_2 -> V_46 )
F_57 ( V_2 ) ;
}
static void F_63 ( struct V_1 * V_2 , T_2 V_132 )
{
T_2 V_112 ;
V_2 -> V_133 = V_132 ;
F_58 ( V_2 ) ;
V_112 = F_4 ( V_2 , V_44 ) ;
V_112 &= ~ V_128 ;
if ( V_132 )
V_112 |= ( V_129 | V_134 | V_131 ) ;
else
V_112 |= V_131 ;
F_6 ( V_2 , V_44 , V_112 ) ;
if ( V_2 -> V_46 )
F_57 ( V_2 ) ;
}
static void F_64 ( struct V_53 * V_23 )
{
struct V_1 * V_2 = F_36 ( V_23 ) ;
struct V_135 * V_136 ;
if ( ( V_23 -> V_137 & V_138 ) == V_138 )
F_62 ( V_2 ,
( T_2 ) ( ( V_23 -> V_137 & V_138 ) == V_138 ) ) ;
else if ( ( V_23 -> V_137 & V_139 ) == V_139 )
F_63 ( V_2 ,
( T_2 ) ( ( V_23 -> V_137 & V_139 ) == V_139 ) ) ;
else
F_62 ( V_2 , false ) ;
if ( ( V_23 -> V_137 & V_140 ) && F_65 ( V_23 ) ) {
if ( F_65 ( V_23 ) <= V_141 ) {
int V_54 = 0 ;
F_66 (ha, netdev) {
if ( V_54 >= V_141 )
break;
memcpy ( V_2 -> V_123 [ V_54 ++ ] , V_136 -> V_142 , V_143 ) ;
}
V_2 -> V_122 = ( T_1 ) V_54 ;
F_60 ( V_2 ) ;
} else {
V_2 -> V_122 = V_141 ;
F_63 ( V_2 , true ) ;
}
} else {
V_2 -> V_122 = 0 ;
F_61 ( V_2 ) ;
}
}
static void F_67 ( struct V_1 * V_2 , T_1 * V_4 )
{
T_2 * V_81 = ( T_2 * ) V_4 ;
T_2 V_39 , V_144 ;
F_58 ( V_2 ) ;
V_144 = * V_81 ++ ;
V_39 = ( ( V_144 & 0xFF ) << 8 ) | ( ( V_144 >> 8 ) & 0xFF ) ;
F_6 ( V_2 , V_145 , V_39 ) ;
V_144 = * V_81 ++ ;
V_39 = ( ( V_144 & 0xFF ) << 8 ) | ( ( V_144 >> 8 ) & 0xFF ) ;
F_6 ( V_2 , V_146 , V_39 ) ;
V_144 = * V_81 ;
V_39 = ( ( V_144 & 0xFF ) << 8 ) | ( ( V_144 >> 8 ) & 0xFF ) ;
F_6 ( V_2 , V_147 , V_39 ) ;
memcpy ( V_2 -> V_148 , V_4 , 6 ) ;
if ( V_2 -> V_46 )
F_57 ( V_2 ) ;
}
static int F_68 ( struct V_53 * V_23 , void * V_149 )
{
struct V_1 * V_2 = F_36 ( V_23 ) ;
struct V_150 * V_142 = V_149 ;
T_1 * V_151 ;
memcpy ( V_23 -> V_152 , V_142 -> V_153 , V_23 -> V_154 ) ;
V_151 = ( T_1 * ) V_23 -> V_152 ;
F_67 ( V_2 , V_151 ) ;
return 0 ;
}
static int F_69 ( struct V_53 * V_23 , struct V_155 * V_156 , int V_157 )
{
struct V_1 * V_2 = F_36 ( V_23 ) ;
if ( ! F_70 ( V_23 ) )
return - V_158 ;
return F_71 ( & V_2 -> V_159 , F_72 ( V_156 ) , V_157 , NULL ) ;
}
static void F_73 ( struct V_53 * V_23 ,
struct V_160 * V_161 )
{
F_74 ( V_161 -> V_162 , V_96 , sizeof( V_161 -> V_162 ) ) ;
F_74 ( V_161 -> V_163 , L_9 , sizeof( V_161 -> V_163 ) ) ;
F_74 ( V_161 -> V_164 , F_75 ( V_23 -> V_165 . V_166 ) ,
sizeof( V_161 -> V_164 ) ) ;
}
static T_3 F_76 ( struct V_53 * V_23 )
{
struct V_1 * V_2 = F_36 ( V_23 ) ;
return V_2 -> V_167 ;
}
static void F_77 ( struct V_53 * V_23 , T_3 V_168 )
{
struct V_1 * V_2 = F_36 ( V_23 ) ;
V_2 -> V_167 = V_168 ;
}
static int F_78 ( struct V_53 * V_23 , struct V_169 * V_157 )
{
struct V_1 * V_2 = F_36 ( V_23 ) ;
return F_79 ( & V_2 -> V_159 , V_157 ) ;
}
static int F_80 ( struct V_53 * V_23 , struct V_169 * V_157 )
{
struct V_1 * V_2 = F_36 ( V_23 ) ;
return F_81 ( & V_2 -> V_159 , V_157 ) ;
}
static T_3 F_82 ( struct V_53 * V_23 )
{
struct V_1 * V_2 = F_36 ( V_23 ) ;
return F_83 ( & V_2 -> V_159 ) ;
}
static int F_84 ( struct V_53 * V_23 )
{
struct V_1 * V_2 = F_36 ( V_23 ) ;
return F_85 ( & V_2 -> V_159 ) ;
}
static int F_86 ( int V_170 )
{
switch ( V_170 ) {
case V_171 :
return V_172 ;
case V_173 :
return V_174 ;
case V_175 :
return V_176 ;
case V_177 :
return V_178 ;
case V_179 :
return V_180 ;
case V_181 :
return V_182 ;
}
return 0x0 ;
}
static int F_87 ( struct V_53 * V_23 , int V_183 , int V_170 )
{
struct V_1 * V_2 = F_36 ( V_23 ) ;
int V_184 ;
int V_185 ;
V_184 = F_86 ( V_170 ) ;
if ( ! V_184 )
return 0x0 ;
F_46 ( & V_2 -> V_99 ) ;
V_185 = F_4 ( V_2 , V_184 ) ;
F_48 ( & V_2 -> V_99 ) ;
return V_185 ;
}
static void F_88 ( struct V_53 * V_23 ,
int V_186 , int V_170 , int V_12 )
{
struct V_1 * V_2 = F_36 ( V_23 ) ;
int V_184 ;
V_184 = F_86 ( V_170 ) ;
if ( V_184 ) {
F_46 ( & V_2 -> V_99 ) ;
F_6 ( V_2 , V_184 , V_12 ) ;
F_48 ( & V_2 -> V_99 ) ;
}
}
static int F_89 ( struct V_1 * V_2 )
{
unsigned V_187 = V_188 | V_189 ;
int V_190 = 0 ;
unsigned V_191 ;
V_191 = F_4 ( V_2 , V_192 ) ;
if ( ( V_191 & V_187 ) != V_187 ) {
F_90 ( V_2 -> V_23 , L_10 ) ;
return 0 ;
}
if ( V_191 & V_193 ) {
F_91 ( V_2 -> V_23 , L_11 ) ;
V_190 |= 1 ;
}
if ( V_191 & V_194 ) {
F_91 ( V_2 -> V_23 , L_12 ) ;
V_190 |= 2 ;
}
F_92 ( V_2 -> V_23 , L_13 ) ;
return V_190 ;
}
static void F_93 ( struct V_1 * V_2 )
{
T_2 V_39 ;
F_6 ( V_2 , V_195 , V_196 ) ;
F_6 ( V_2 , V_49 , V_50 ) ;
F_6 ( V_2 , V_61 , 1 & V_197 ) ;
V_2 -> V_51 = V_198 ;
F_6 ( V_2 , V_42 , V_2 -> V_51 ) ;
V_39 = F_4 ( V_2 , V_172 ) ;
V_39 &= ~ V_199 ;
F_6 ( V_2 , V_172 , V_39 ) ;
V_39 = V_200 | V_201 | V_202 | V_203 ;
F_6 ( V_2 , V_40 , V_39 ) ;
V_39 = V_204 | V_205 | V_206 | V_207 | V_208 ;
if ( V_2 -> V_127 )
V_39 |= ( V_129 | V_130 ) ;
else if ( V_2 -> V_133 )
V_39 |= ( V_129 | V_134 | V_131 ) ;
else
V_39 |= V_131 ;
F_6 ( V_2 , V_44 , V_39 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
V_2 -> V_17 = 0x00 ;
F_6 ( V_2 , V_83 , 0xffff ) ;
V_2 -> V_17 = ( V_86 | V_87 | V_85 ) ;
}
static int F_95 ( struct V_1 * V_2 )
{
#define F_96 (sizeof(struct type_frame_head) * MAX_RECV_FRAMES)
V_2 -> V_127 = 0 ;
V_2 -> V_133 = 0 ;
V_2 -> V_122 = 0 ;
V_2 -> V_57 = F_97 ( F_96 , V_209 ) ;
if ( ! V_2 -> V_57 )
return false ;
F_67 ( V_2 , V_210 ) ;
return true ;
}
static int F_98 ( struct V_211 * V_212 )
{
int V_94 = - V_213 ;
struct V_214 * V_215 , * V_216 ;
struct V_53 * V_23 ;
struct V_1 * V_2 ;
T_2 V_217 , V_4 ;
struct V_218 * V_101 ;
V_215 = F_99 ( V_212 , V_219 , 0 ) ;
V_216 = F_99 ( V_212 , V_219 , 1 ) ;
if ( ! F_100 ( V_215 -> V_220 , F_101 ( V_215 ) , V_96 ) )
goto V_221;
if ( ! F_100 ( V_216 -> V_220 , F_101 ( V_216 ) , V_96 ) )
goto V_222;
V_23 = F_102 ( sizeof( struct V_1 ) ) ;
if ( ! V_23 )
goto V_223;
F_103 ( V_23 , & V_212 -> V_165 ) ;
V_2 = F_36 ( V_23 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_10 = F_104 ( V_215 -> V_220 , F_101 ( V_215 ) ) ;
if ( ! V_2 -> V_10 )
goto V_224;
V_2 -> V_9 = F_104 ( V_216 -> V_220 , F_101 ( V_216 ) ) ;
if ( ! V_2 -> V_9 )
goto V_225;
V_23 -> V_80 = F_105 ( V_212 , 0 ) ;
if ( ( int ) V_23 -> V_80 < 0 ) {
V_94 = V_23 -> V_80 ;
goto V_226;
}
V_2 -> V_212 = V_212 ;
F_106 ( & V_2 -> V_99 ) ;
F_107 ( & V_2 -> V_108 ) ;
V_23 -> V_227 = & V_228 ;
V_23 -> V_229 = & V_230 ;
V_2 -> V_159 . V_165 = V_23 ;
V_2 -> V_159 . V_231 = 1 ,
V_2 -> V_159 . V_232 = 1 ;
V_2 -> V_159 . V_233 = 0xf ;
V_2 -> V_159 . V_234 = F_87 ;
V_2 -> V_159 . V_235 = F_88 ;
F_92 ( V_23 , L_14 , V_167 ) ;
V_2 -> V_167 = F_108 ( V_167 , ( V_236 |
V_237 |
V_238 ) ) ;
F_16 ( V_2 ) ;
if ( ( F_4 ( V_2 , V_239 ) & ~ V_240 ) != V_241 ) {
F_91 ( V_23 , L_15 ) ;
V_94 = - V_242 ;
goto V_243;
}
if ( F_89 ( V_2 ) ) {
F_91 ( V_23 , L_15 ) ;
V_94 = - V_242 ;
goto V_243;
}
V_94 = F_109 ( V_23 ) ;
if ( V_94 )
goto V_243;
F_110 ( V_212 , V_23 ) ;
F_17 ( V_2 , V_244 ) ;
F_95 ( V_2 ) ;
F_20 ( V_2 ) ;
F_93 ( V_2 ) ;
F_94 ( V_2 ) ;
V_4 = F_4 ( V_2 , V_245 ) ;
F_6 ( V_2 , V_245 , V_4 | V_246 ) ;
V_101 = V_212 -> V_165 . V_247 ;
if ( ! V_101 ) {
F_91 ( V_23 , L_16 ) ;
V_94 = - V_242 ;
goto V_248;
}
memcpy ( V_2 -> V_148 , V_101 -> V_148 , 6 ) ;
if ( ! F_111 ( V_2 -> V_148 ) ) {
F_112 ( V_2 -> V_148 ) ;
F_92 ( V_23 , L_17 ) ;
}
F_92 ( V_23 , L_18 , V_2 -> V_148 ) ;
memcpy ( V_23 -> V_152 , V_2 -> V_148 , 6 ) ;
F_67 ( V_2 , V_23 -> V_152 ) ;
V_217 = F_4 ( V_2 , V_239 ) ;
F_92 ( V_23 , L_19 ,
( V_217 >> 8 ) & 0xff , ( V_217 >> 4 ) & 0xf , ( V_217 >> 1 ) & 0x7 ) ;
return 0 ;
V_248:
F_113 ( V_23 ) ;
V_243:
V_226:
F_114 ( V_2 -> V_9 ) ;
V_225:
F_114 ( V_2 -> V_10 ) ;
V_224:
F_115 ( V_23 ) ;
V_223:
F_116 ( V_216 -> V_220 , F_101 ( V_216 ) ) ;
V_222:
F_116 ( V_215 -> V_220 , F_101 ( V_215 ) ) ;
V_221:
return V_94 ;
}
static int F_117 ( struct V_211 * V_212 )
{
struct V_53 * V_23 = F_118 ( V_212 ) ;
struct V_1 * V_2 = F_36 ( V_23 ) ;
struct V_214 * V_249 = F_99 ( V_212 , V_219 , 0 ) ;
F_119 ( V_2 -> V_57 ) ;
F_113 ( V_23 ) ;
F_114 ( V_2 -> V_10 ) ;
F_115 ( V_23 ) ;
F_116 ( V_249 -> V_220 , F_101 ( V_249 ) ) ;
F_110 ( V_212 , NULL ) ;
return 0 ;
}
