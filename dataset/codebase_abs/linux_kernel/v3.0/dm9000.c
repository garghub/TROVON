static inline T_1 * F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ;
}
static void
F_3 ( T_1 * V_3 )
{
F_4 ( V_3 -> V_2 , L_1 ) ;
F_5 ( V_4 , V_3 -> V_5 ) ;
F_6 ( 200 ) ;
F_5 ( V_6 , V_3 -> V_7 ) ;
F_6 ( 200 ) ;
}
static T_2
F_7 ( T_1 * V_3 , int V_8 )
{
F_5 ( V_8 , V_3 -> V_5 ) ;
return F_8 ( V_3 -> V_7 ) ;
}
static void
F_9 ( T_1 * V_3 , int V_8 , int V_9 )
{
F_5 ( V_8 , V_3 -> V_5 ) ;
F_5 ( V_9 , V_3 -> V_7 ) ;
}
static void F_10 ( void T_3 * V_8 , void * V_10 , int V_11 )
{
F_11 ( V_8 , V_10 , V_11 ) ;
}
static void F_12 ( void T_3 * V_8 , void * V_10 , int V_11 )
{
F_13 ( V_8 , V_10 , ( V_11 + 1 ) >> 1 ) ;
}
static void F_14 ( void T_3 * V_8 , void * V_10 , int V_11 )
{
F_15 ( V_8 , V_10 , ( V_11 + 3 ) >> 2 ) ;
}
static void F_16 ( void T_3 * V_8 , void * V_10 , int V_11 )
{
F_17 ( V_8 , V_10 , V_11 ) ;
}
static void F_18 ( void T_3 * V_8 , void * V_10 , int V_11 )
{
F_19 ( V_8 , V_10 , ( V_11 + 1 ) >> 1 ) ;
}
static void F_20 ( void T_3 * V_8 , void * V_10 , int V_11 )
{
F_21 ( V_8 , V_10 , ( V_11 + 3 ) >> 2 ) ;
}
static void F_22 ( void T_3 * V_8 , int V_11 )
{
int V_12 ;
int V_13 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_13 = F_8 ( V_8 ) ;
}
static void F_23 ( void T_3 * V_8 , int V_11 )
{
int V_12 ;
int V_13 ;
V_11 = ( V_11 + 1 ) >> 1 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_13 = F_24 ( V_8 ) ;
}
static void F_25 ( void T_3 * V_8 , int V_11 )
{
int V_12 ;
int V_13 ;
V_11 = ( V_11 + 3 ) >> 2 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
V_13 = F_26 ( V_8 ) ;
}
static void F_27 ( struct V_14 * V_3 , int V_15 )
{
switch ( V_15 ) {
case 1 :
V_3 -> V_16 = F_22 ;
V_3 -> V_17 = F_10 ;
V_3 -> V_18 = F_16 ;
break;
case 3 :
F_4 ( V_3 -> V_2 , L_2 ) ;
case 2 :
V_3 -> V_16 = F_23 ;
V_3 -> V_17 = F_12 ;
V_3 -> V_18 = F_18 ;
break;
case 4 :
default:
V_3 -> V_16 = F_25 ;
V_3 -> V_17 = F_14 ;
V_3 -> V_18 = F_20 ;
break;
}
}
static void F_28 ( T_1 * V_3 )
{
if ( V_3 -> type == V_19 )
F_29 ( & V_3 -> V_20 , V_21 * 2 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_22 * V_23 , int V_24 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
if ( ! F_31 ( V_2 ) )
return - V_26 ;
return F_32 ( & V_25 -> V_27 , F_33 ( V_23 ) , V_24 , NULL ) ;
}
static unsigned int
F_34 ( T_1 * V_3 , int V_8 )
{
unsigned long V_28 ;
unsigned int V_29 ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_29 = F_7 ( V_3 , V_8 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
return V_29 ;
}
static int F_37 ( T_1 * V_3 )
{
unsigned int V_31 ;
int V_32 = 8 ;
while ( 1 ) {
V_31 = F_34 ( V_3 , V_33 ) ;
if ( ( V_31 & V_34 ) == 0 )
break;
F_38 ( 1 ) ;
if ( V_32 -- < 0 ) {
F_4 ( V_3 -> V_2 , L_3 ) ;
break;
}
}
return 0 ;
}
static void
F_39 ( T_1 * V_3 , int V_35 , T_2 * V_36 )
{
unsigned long V_28 ;
if ( V_3 -> V_28 & V_37 ) {
V_36 [ 0 ] = 0xff ;
V_36 [ 1 ] = 0xff ;
return;
}
F_40 ( & V_3 -> V_38 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
F_9 ( V_3 , V_39 , V_35 ) ;
F_9 ( V_3 , V_33 , V_40 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_37 ( V_3 ) ;
F_38 ( 1 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
F_9 ( V_3 , V_33 , 0x0 ) ;
V_36 [ 0 ] = F_7 ( V_3 , V_41 ) ;
V_36 [ 1 ] = F_7 ( V_3 , V_42 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_41 ( & V_3 -> V_38 ) ;
}
static void
F_42 ( T_1 * V_3 , int V_35 , T_2 * V_10 )
{
unsigned long V_28 ;
if ( V_3 -> V_28 & V_37 )
return;
F_40 ( & V_3 -> V_38 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
F_9 ( V_3 , V_39 , V_35 ) ;
F_9 ( V_3 , V_42 , V_10 [ 1 ] ) ;
F_9 ( V_3 , V_41 , V_10 [ 0 ] ) ;
F_9 ( V_3 , V_33 , V_43 | V_44 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_37 ( V_3 ) ;
F_43 ( 1 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
F_9 ( V_3 , V_33 , 0 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_41 ( & V_3 -> V_38 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
strcpy ( V_46 -> V_47 , V_48 ) ;
strcpy ( V_46 -> V_49 , V_50 ) ;
strcpy ( V_46 -> V_51 , F_45 ( V_25 -> V_2 ) -> V_52 ) ;
}
static T_4 F_46 ( struct V_1 * V_2 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
return V_25 -> V_53 ;
}
static void F_47 ( struct V_1 * V_2 , T_4 V_9 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
V_25 -> V_53 = V_9 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_54 * V_24 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
F_49 ( & V_25 -> V_27 , V_24 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , struct V_54 * V_24 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
return F_51 ( & V_25 -> V_27 , V_24 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
return F_53 ( & V_25 -> V_27 ) ;
}
static int F_54 ( struct V_1 * V_2 , T_4 V_55 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
T_4 V_56 = V_2 -> V_55 ^ V_55 ;
unsigned long V_28 ;
if ( ! ( V_56 & V_57 ) )
return 0 ;
F_35 ( & V_25 -> V_30 , V_28 ) ;
F_9 ( V_25 , V_58 , ( V_55 & V_57 ) ? V_59 : 0 ) ;
F_36 ( & V_25 -> V_30 , V_28 ) ;
return 0 ;
}
static T_4 F_55 ( struct V_1 * V_2 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
T_4 V_29 ;
if ( V_25 -> V_28 & V_60 )
V_29 = F_56 ( & V_25 -> V_27 ) ;
else
V_29 = F_34 ( V_25 , V_61 ) & V_62 ? 1 : 0 ;
return V_29 ;
}
static int F_57 ( struct V_1 * V_2 )
{
return 128 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_63 * V_64 , T_2 * V_10 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
int V_35 = V_64 -> V_35 ;
int V_65 = V_64 -> V_65 ;
int V_12 ;
if ( ( V_65 & 1 ) != 0 || ( V_35 & 1 ) != 0 )
return - V_26 ;
if ( V_25 -> V_28 & V_37 )
return - V_66 ;
V_64 -> V_67 = V_68 ;
for ( V_12 = 0 ; V_12 < V_65 ; V_12 += 2 )
F_39 ( V_25 , ( V_35 + V_12 ) / 2 , V_10 + V_12 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_63 * V_64 , T_2 * V_10 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
int V_35 = V_64 -> V_35 ;
int V_65 = V_64 -> V_65 ;
int V_12 ;
if ( ( V_65 & 1 ) != 0 || ( V_35 & 1 ) != 0 )
return - V_26 ;
if ( V_25 -> V_28 & V_37 )
return - V_66 ;
if ( V_64 -> V_67 != V_68 )
return - V_26 ;
for ( V_12 = 0 ; V_12 < V_65 ; V_12 += 2 )
F_42 ( V_25 , ( V_35 + V_12 ) / 2 , V_10 + V_12 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
memset ( V_70 , 0 , sizeof( struct V_69 ) ) ;
V_70 -> V_71 = V_25 -> V_72 ? V_73 : 0 ;
V_70 -> V_74 = V_25 -> V_75 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_69 * V_70 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
unsigned long V_28 ;
T_4 V_76 = V_70 -> V_74 ;
T_4 V_77 = 0 ;
if ( ! V_25 -> V_72 )
return - V_78 ;
if ( V_76 & ~ V_73 )
return - V_26 ;
if ( V_76 & V_73 )
V_77 |= V_79 ;
F_40 ( & V_25 -> V_38 ) ;
F_35 ( & V_25 -> V_30 , V_28 ) ;
F_9 ( V_25 , V_80 , V_77 ) ;
F_36 ( & V_25 -> V_30 , V_28 ) ;
F_41 ( & V_25 -> V_38 ) ;
if ( V_25 -> V_75 != V_76 ) {
if ( ! V_25 -> V_75 )
F_62 ( V_25 -> V_81 , 1 ) ;
else if ( V_25 -> V_75 & ! V_76 )
F_62 ( V_25 -> V_81 , 0 ) ;
}
V_25 -> V_75 = V_76 ;
return 0 ;
}
static void F_63 ( T_1 * V_3 ,
unsigned V_82 , unsigned V_83 )
{
struct V_1 * V_84 = V_3 -> V_84 ;
unsigned V_85 = F_34 ( V_3 , V_4 ) ;
if ( V_82 )
F_64 ( V_3 -> V_2 , L_4 ,
V_84 -> V_52 , ( V_83 & V_86 ) ? 10 : 100 ,
( V_85 & V_87 ) ? L_5 : L_6 ) ;
else
F_64 ( V_3 -> V_2 , L_7 , V_84 -> V_52 ) ;
}
static void
F_65 ( struct V_88 * V_70 )
{
struct V_89 * V_90 = F_66 ( V_70 ) ;
T_1 * V_3 = F_67 ( V_90 , T_1 , V_20 ) ;
struct V_1 * V_84 = V_3 -> V_84 ;
if ( V_3 -> V_28 & V_91 &&
! ( V_3 -> V_28 & V_60 ) ) {
unsigned V_83 = F_34 ( V_3 , V_61 ) ;
unsigned V_92 = F_68 ( V_84 ) ? 1 : 0 ;
unsigned V_93 ;
V_93 = ( V_83 & V_62 ) ? 1 : 0 ;
if ( V_92 != V_93 ) {
if ( F_69 ( V_3 ) )
F_63 ( V_3 , V_93 , V_83 ) ;
if ( ! V_93 )
F_70 ( V_84 ) ;
else
F_71 ( V_84 ) ;
}
} else
F_72 ( & V_3 -> V_27 , F_69 ( V_3 ) , 0 ) ;
if ( F_31 ( V_84 ) )
F_28 ( V_3 ) ;
}
static void
F_73 ( struct V_94 * V_95 , struct V_14 * V_3 )
{
F_74 ( V_3 -> V_5 ) ;
F_74 ( V_3 -> V_7 ) ;
F_75 ( V_3 -> V_96 ) ;
F_76 ( V_3 -> V_96 ) ;
F_75 ( V_3 -> V_97 ) ;
F_76 ( V_3 -> V_97 ) ;
}
static unsigned char F_77 ( enum V_98 type )
{
switch ( type ) {
case V_19 : return 'e' ;
case V_99 : return 'a' ;
case V_100 : return 'b' ;
}
return '?' ;
}
static void
F_78 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
struct V_101 * V_102 ;
int V_12 , V_103 ;
T_4 V_104 ;
T_5 V_105 [ 4 ] ;
T_2 V_106 = V_107 | V_108 | V_109 ;
F_79 ( V_3 , 1 , L_8 , V_110 ) ;
for ( V_12 = 0 , V_103 = V_111 ; V_12 < 6 ; V_12 ++ , V_103 ++ )
F_9 ( V_3 , V_103 , V_2 -> V_112 [ V_12 ] ) ;
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
V_105 [ V_12 ] = 0x0 ;
V_105 [ 3 ] = 0x8000 ;
if ( V_2 -> V_28 & V_113 )
V_106 |= V_114 ;
if ( V_2 -> V_28 & V_115 )
V_106 |= V_116 ;
F_80 (ha, dev) {
V_104 = F_81 ( 6 , V_102 -> V_117 ) & 0x3f ;
V_105 [ V_104 / 16 ] |= ( T_5 ) 1 << ( V_104 % 16 ) ;
}
for ( V_12 = 0 , V_103 = V_118 ; V_12 < 4 ; V_12 ++ ) {
F_9 ( V_3 , V_103 ++ , V_105 [ V_12 ] ) ;
F_9 ( V_3 , V_103 ++ , V_105 [ V_12 ] >> 8 ) ;
}
F_9 ( V_3 , V_119 , V_106 ) ;
}
static void
F_82 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_28 ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
F_78 ( V_2 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
}
static void
F_83 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned int V_120 ;
unsigned int V_85 ;
F_79 ( V_3 , 1 , L_8 , V_110 ) ;
V_3 -> V_121 = F_7 ( V_3 , V_122 ) >> 6 ;
if ( V_2 -> V_123 & V_57 )
F_9 ( V_3 , V_58 ,
( V_2 -> V_55 & V_57 ) ? V_59 : 0 ) ;
F_9 ( V_3 , V_124 , V_125 ) ;
V_85 = ( V_3 -> V_28 & V_60 ) ? V_126 : 0 ;
if ( V_3 -> V_72 )
V_85 |= V_127 ;
F_9 ( V_3 , V_4 , V_85 ) ;
F_9 ( V_3 , V_128 , 0 ) ;
F_9 ( V_3 , V_129 , 0x3f ) ;
F_9 ( V_3 , V_130 , 0xff ) ;
F_9 ( V_3 , V_131 , 0 ) ;
F_9 ( V_3 , V_61 , V_132 | V_133 | V_134 ) ;
F_9 ( V_3 , V_122 , V_135 ) ;
F_78 ( V_2 ) ;
V_120 = V_136 | V_137 | V_138 ;
if ( V_3 -> type != V_19 )
V_120 |= V_139 ;
V_3 -> V_140 = V_120 ;
F_9 ( V_3 , V_141 , V_120 ) ;
V_3 -> V_142 = 0 ;
V_3 -> V_143 = 0 ;
V_2 -> V_144 = V_145 ;
}
static void F_84 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
T_2 V_146 ;
unsigned long V_28 ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_146 = F_8 ( V_3 -> V_5 ) ;
F_85 ( V_2 ) ;
F_3 ( V_3 ) ;
F_83 ( V_2 ) ;
V_2 -> V_144 = V_145 ;
F_86 ( V_2 ) ;
F_5 ( V_146 , V_3 -> V_5 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
int V_147 ,
T_5 V_148 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
if ( V_25 -> V_147 != V_147 ) {
if ( V_147 == V_149 )
F_9 ( V_25 , V_150 , 0 ) ;
else
F_9 ( V_25 , V_150 , V_151 | V_152 | V_153 ) ;
V_25 -> V_147 = V_147 ;
}
F_9 ( V_25 , V_154 , V_148 ) ;
F_9 ( V_25 , V_155 , V_148 >> 8 ) ;
F_9 ( V_25 , V_128 , V_156 ) ;
}
static int
F_88 ( struct V_157 * V_158 , struct V_1 * V_2 )
{
unsigned long V_28 ;
T_1 * V_3 = F_2 ( V_2 ) ;
F_79 ( V_3 , 3 , L_9 , V_110 ) ;
if ( V_3 -> V_142 > 1 )
return V_159 ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
F_5 ( V_160 , V_3 -> V_5 ) ;
( V_3 -> V_17 ) ( V_3 -> V_7 , V_158 -> V_10 , V_158 -> V_65 ) ;
V_2 -> V_161 . V_162 += V_158 -> V_65 ;
V_3 -> V_142 ++ ;
if ( V_3 -> V_142 == 1 ) {
F_87 ( V_2 , V_158 -> V_147 , V_158 -> V_65 ) ;
} else {
V_3 -> V_143 = V_158 -> V_65 ;
V_3 -> V_163 = V_158 -> V_147 ;
F_85 ( V_2 ) ;
}
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_89 ( V_158 ) ;
return V_164 ;
}
static void F_90 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_165 = F_7 ( V_3 , V_61 ) ;
if ( V_165 & ( V_133 | V_134 ) ) {
V_3 -> V_142 -- ;
V_2 -> V_161 . V_166 ++ ;
if ( F_91 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_10 , V_165 ) ;
if ( V_3 -> V_142 > 0 )
F_87 ( V_2 , V_3 -> V_163 ,
V_3 -> V_143 ) ;
F_86 ( V_2 ) ;
}
}
static void
F_92 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
struct V_167 V_168 ;
struct V_157 * V_158 ;
T_2 V_169 , * V_170 ;
bool V_171 ;
int V_172 ;
do {
F_7 ( V_3 , V_173 ) ;
V_169 = F_8 ( V_3 -> V_7 ) ;
if ( V_169 & V_174 ) {
F_93 ( V_3 -> V_2 , L_11 , V_169 ) ;
F_9 ( V_3 , V_119 , 0x00 ) ;
F_9 ( V_3 , V_122 , V_136 ) ;
return;
}
if ( ! ( V_169 & V_175 ) )
return;
V_171 = true ;
F_5 ( V_176 , V_3 -> V_5 ) ;
( V_3 -> V_18 ) ( V_3 -> V_7 , & V_168 , sizeof( V_168 ) ) ;
V_172 = F_94 ( V_168 . V_172 ) ;
if ( F_95 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_12 ,
V_168 . V_177 , V_172 ) ;
if ( V_172 < 0x40 ) {
V_171 = false ;
if ( F_96 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_13 ) ;
}
if ( V_172 > V_178 ) {
F_4 ( V_3 -> V_2 , L_14 , V_172 ) ;
}
if ( V_168 . V_177 & ( V_179 | V_180 | V_181 |
V_182 | V_183 |
V_184 | V_185 ) ) {
V_171 = false ;
if ( V_168 . V_177 & V_179 ) {
if ( F_96 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_15 ) ;
V_2 -> V_161 . V_186 ++ ;
}
if ( V_168 . V_177 & V_180 ) {
if ( F_96 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_16 ) ;
V_2 -> V_161 . V_187 ++ ;
}
if ( V_168 . V_177 & V_185 ) {
if ( F_96 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_17 ) ;
V_2 -> V_161 . V_188 ++ ;
}
}
if ( V_171 &&
( ( V_158 = F_97 ( V_172 + 4 ) ) != NULL ) ) {
F_98 ( V_158 , 2 ) ;
V_170 = ( T_2 * ) F_99 ( V_158 , V_172 - 4 ) ;
( V_3 -> V_18 ) ( V_3 -> V_7 , V_170 , V_172 ) ;
V_2 -> V_161 . V_189 += V_172 ;
V_158 -> V_190 = F_100 ( V_158 , V_2 ) ;
if ( V_2 -> V_55 & V_57 ) {
if ( ( ( ( V_169 & 0x1c ) << 3 ) & V_169 ) == 0 )
V_158 -> V_147 = V_191 ;
else
F_101 ( V_158 ) ;
}
F_102 ( V_158 ) ;
V_2 -> V_161 . V_192 ++ ;
} else {
( V_3 -> V_16 ) ( V_3 -> V_7 , V_172 ) ;
}
} while ( V_169 & V_175 );
}
static T_6 F_103 ( int V_193 , void * V_194 )
{
struct V_1 * V_2 = V_194 ;
T_1 * V_3 = F_2 ( V_2 ) ;
int V_195 ;
unsigned long V_28 ;
T_2 V_146 ;
F_79 ( V_3 , 3 , L_8 , V_110 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_146 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_141 , V_136 ) ;
V_195 = F_7 ( V_3 , V_122 ) ;
F_9 ( V_3 , V_122 , V_195 ) ;
if ( F_104 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_18 , V_195 ) ;
if ( V_195 & V_196 )
F_92 ( V_2 ) ;
if ( V_195 & V_197 )
F_90 ( V_2 , V_3 ) ;
if ( V_3 -> type != V_19 ) {
if ( V_195 & V_198 ) {
F_29 ( & V_3 -> V_20 , 1 ) ;
}
}
F_9 ( V_3 , V_141 , V_3 -> V_140 ) ;
F_5 ( V_146 , V_3 -> V_5 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
return V_199 ;
}
static T_6 F_105 ( int V_193 , void * V_194 )
{
struct V_1 * V_2 = V_194 ;
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_28 ;
unsigned V_83 , V_77 ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_83 = F_7 ( V_3 , V_61 ) ;
V_77 = F_7 ( V_3 , V_80 ) ;
F_4 ( V_3 -> V_2 , L_19 , V_110 , V_83 , V_77 ) ;
if ( V_83 & V_132 ) {
F_9 ( V_3 , V_61 , V_132 ) ;
if ( V_77 & V_200 )
F_64 ( V_3 -> V_2 , L_20 ) ;
if ( V_77 & V_201 )
F_64 ( V_3 -> V_2 , L_21 ) ;
if ( V_77 & V_202 )
F_64 ( V_3 -> V_2 , L_22 ) ;
if ( ! ( V_77 & ( V_200 | V_201 | V_202 ) ) )
F_106 ( V_3 -> V_2 , L_23
L_24 , V_83 , V_77 ) ;
}
F_36 ( & V_3 -> V_30 , V_28 ) ;
return ( V_83 & V_132 ) ? V_199 : V_203 ;
}
static void F_107 ( struct V_1 * V_2 )
{
F_108 ( V_2 -> V_193 ) ;
F_103 ( V_2 -> V_193 , V_2 ) ;
F_109 ( V_2 -> V_193 ) ;
}
static int
F_110 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_204 = V_3 -> V_205 -> V_28 & V_206 ;
if ( F_111 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_25 , V_2 -> V_52 ) ;
if ( V_204 == V_207 )
F_93 ( V_3 -> V_2 , L_26 ) ;
V_204 |= V_208 ;
F_9 ( V_3 , V_209 , 0 ) ;
F_43 ( 1 ) ;
F_3 ( V_3 ) ;
F_83 ( V_2 ) ;
if ( F_112 ( V_2 -> V_193 , F_103 , V_204 , V_2 -> V_52 , V_2 ) )
return - V_210 ;
V_3 -> V_211 = 0 ;
F_72 ( & V_3 -> V_27 , F_69 ( V_3 ) , 1 ) ;
F_113 ( V_2 ) ;
F_28 ( V_3 ) ;
return 0 ;
}
static void F_114 ( T_1 * V_3 , unsigned int V_212 )
{
if ( V_3 -> V_213 )
F_43 ( V_212 ) ;
else
F_38 ( V_212 ) ;
}
static int
F_115 ( struct V_1 * V_2 , int V_214 , int V_8 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_28 ;
unsigned int V_146 ;
int V_29 ;
F_40 ( & V_3 -> V_38 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_146 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_39 , V_215 | V_8 ) ;
F_9 ( V_3 , V_33 , V_40 | V_216 ) ;
F_5 ( V_146 , V_3 -> V_5 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_114 ( V_3 , 1 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_146 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_33 , 0x0 ) ;
V_29 = ( F_7 ( V_3 , V_42 ) << 8 ) | F_7 ( V_3 , V_41 ) ;
F_5 ( V_146 , V_3 -> V_5 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_41 ( & V_3 -> V_38 ) ;
F_79 ( V_3 , 5 , L_27 , V_8 , V_29 ) ;
return V_29 ;
}
static void
F_116 ( struct V_1 * V_2 ,
int V_217 , int V_8 , int V_9 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_28 ;
unsigned long V_146 ;
F_79 ( V_3 , 5 , L_28 , V_8 , V_9 ) ;
F_40 ( & V_3 -> V_38 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_146 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_39 , V_215 | V_8 ) ;
F_9 ( V_3 , V_41 , V_9 ) ;
F_9 ( V_3 , V_42 , V_9 >> 8 ) ;
F_9 ( V_3 , V_33 , V_216 | V_44 ) ;
F_5 ( V_146 , V_3 -> V_5 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_114 ( V_3 , 1 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_146 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_33 , 0x0 ) ;
F_5 ( V_146 , V_3 -> V_5 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_41 ( & V_3 -> V_38 ) ;
}
static void
F_117 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
F_116 ( V_2 , 0 , V_218 , V_219 ) ;
F_9 ( V_3 , V_209 , 0x01 ) ;
F_9 ( V_3 , V_141 , V_136 ) ;
F_9 ( V_3 , V_119 , 0x00 ) ;
}
static int
F_118 ( struct V_1 * V_84 )
{
T_1 * V_3 = F_2 ( V_84 ) ;
if ( F_119 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_29 , V_84 -> V_52 ) ;
F_120 ( & V_3 -> V_20 ) ;
F_85 ( V_84 ) ;
F_70 ( V_84 ) ;
F_121 ( V_84 -> V_193 , V_84 ) ;
F_117 ( V_84 ) ;
return 0 ;
}
static int T_7
F_122 ( struct V_94 * V_95 )
{
struct V_220 * V_221 = V_95 -> V_2 . V_222 ;
struct V_14 * V_3 ;
struct V_1 * V_84 ;
const unsigned char * V_223 ;
int V_29 = 0 ;
int V_224 ;
int V_12 ;
T_4 V_225 ;
V_84 = F_123 ( sizeof( struct V_14 ) ) ;
if ( ! V_84 ) {
F_106 ( & V_95 -> V_2 , L_30 ) ;
return - V_226 ;
}
F_124 ( V_84 , & V_95 -> V_2 ) ;
F_4 ( & V_95 -> V_2 , L_31 ) ;
V_3 = F_2 ( V_84 ) ;
V_3 -> V_2 = & V_95 -> V_2 ;
V_3 -> V_84 = V_84 ;
F_125 ( & V_3 -> V_30 ) ;
F_126 ( & V_3 -> V_38 ) ;
F_127 ( & V_3 -> V_20 , F_65 ) ;
V_3 -> V_227 = F_128 ( V_95 , V_228 , 0 ) ;
V_3 -> V_229 = F_128 ( V_95 , V_228 , 1 ) ;
V_3 -> V_205 = F_128 ( V_95 , V_230 , 0 ) ;
if ( V_3 -> V_227 == NULL || V_3 -> V_229 == NULL ||
V_3 -> V_205 == NULL ) {
F_106 ( V_3 -> V_2 , L_32 ) ;
V_29 = - V_66 ;
goto V_231;
}
V_3 -> V_81 = F_129 ( V_95 , 1 ) ;
if ( V_3 -> V_81 >= 0 ) {
F_4 ( V_3 -> V_2 , L_33 , V_3 -> V_81 ) ;
V_29 = F_112 ( V_3 -> V_81 , F_105 ,
V_208 , F_130 ( V_3 -> V_2 ) , V_84 ) ;
if ( V_29 ) {
F_106 ( V_3 -> V_2 , L_34 , V_29 ) ;
} else {
V_29 = F_62 ( V_3 -> V_81 , 1 ) ;
if ( V_29 ) {
F_106 ( V_3 -> V_2 , L_35 ,
V_3 -> V_81 , V_29 ) ;
V_29 = 0 ;
} else {
F_62 ( V_3 -> V_81 , 0 ) ;
V_3 -> V_72 = 1 ;
}
}
}
V_224 = F_131 ( V_3 -> V_227 ) ;
V_3 -> V_97 = F_132 ( V_3 -> V_227 -> V_232 , V_224 ,
V_95 -> V_52 ) ;
if ( V_3 -> V_97 == NULL ) {
F_106 ( V_3 -> V_2 , L_36 ) ;
V_29 = - V_233 ;
goto V_231;
}
V_3 -> V_5 = F_133 ( V_3 -> V_227 -> V_232 , V_224 ) ;
if ( V_3 -> V_5 == NULL ) {
F_106 ( V_3 -> V_2 , L_37 ) ;
V_29 = - V_26 ;
goto V_231;
}
V_224 = F_131 ( V_3 -> V_229 ) ;
V_3 -> V_96 = F_132 ( V_3 -> V_229 -> V_232 , V_224 ,
V_95 -> V_52 ) ;
if ( V_3 -> V_96 == NULL ) {
F_106 ( V_3 -> V_2 , L_38 ) ;
V_29 = - V_233 ;
goto V_231;
}
V_3 -> V_7 = F_133 ( V_3 -> V_229 -> V_232 , V_224 ) ;
if ( V_3 -> V_7 == NULL ) {
F_106 ( V_3 -> V_2 , L_39 ) ;
V_29 = - V_26 ;
goto V_231;
}
V_84 -> V_234 = ( unsigned long ) V_3 -> V_5 ;
V_84 -> V_193 = V_3 -> V_205 -> V_232 ;
F_27 ( V_3 , V_224 ) ;
if ( V_221 != NULL ) {
if ( V_221 -> V_28 & V_235 )
F_27 ( V_3 , 1 ) ;
if ( V_221 -> V_28 & V_236 )
F_27 ( V_3 , 2 ) ;
if ( V_221 -> V_28 & V_237 )
F_27 ( V_3 , 4 ) ;
if ( V_221 -> V_18 != NULL )
V_3 -> V_18 = V_221 -> V_18 ;
if ( V_221 -> V_17 != NULL )
V_3 -> V_17 = V_221 -> V_17 ;
if ( V_221 -> V_16 != NULL )
V_3 -> V_16 = V_221 -> V_16 ;
V_3 -> V_28 = V_221 -> V_28 ;
}
#ifdef F_134
V_3 -> V_28 |= V_91 ;
#endif
F_3 ( V_3 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_225 = F_7 ( V_3 , V_238 ) ;
V_225 |= ( T_4 ) F_7 ( V_3 , V_239 ) << 8 ;
V_225 |= ( T_4 ) F_7 ( V_3 , V_240 ) << 16 ;
V_225 |= ( T_4 ) F_7 ( V_3 , V_241 ) << 24 ;
if ( V_225 == V_242 )
break;
F_106 ( V_3 -> V_2 , L_40 , V_225 ) ;
}
if ( V_225 != V_242 ) {
F_106 ( V_3 -> V_2 , L_41 , V_225 ) ;
V_29 = - V_243 ;
goto V_231;
}
V_225 = F_7 ( V_3 , V_244 ) ;
F_4 ( V_3 -> V_2 , L_42 , V_225 ) ;
switch ( V_225 ) {
case V_245 :
V_3 -> type = V_99 ;
break;
case V_246 :
V_3 -> type = V_100 ;
break;
default:
F_4 ( V_3 -> V_2 , L_43 , V_225 ) ;
V_3 -> type = V_19 ;
}
if ( V_3 -> type == V_99 || V_3 -> type == V_100 ) {
V_84 -> V_123 = V_57 | V_247 ;
V_84 -> V_55 |= V_84 -> V_123 ;
}
F_135 ( V_84 ) ;
V_84 -> V_248 = & V_249 ;
V_84 -> V_250 = F_136 ( V_251 ) ;
V_84 -> V_252 = & V_253 ;
V_3 -> V_53 = V_254 ;
V_3 -> V_27 . V_255 = 0x1f ;
V_3 -> V_27 . V_256 = 0x1f ;
V_3 -> V_27 . V_257 = 0 ;
V_3 -> V_27 . V_258 = 0 ;
V_3 -> V_27 . V_2 = V_84 ;
V_3 -> V_27 . V_259 = F_115 ;
V_3 -> V_27 . V_260 = F_116 ;
V_223 = L_44 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 += 2 )
F_39 ( V_3 , V_12 / 2 , V_84 -> V_112 + V_12 ) ;
if ( ! F_137 ( V_84 -> V_112 ) && V_221 != NULL ) {
V_223 = L_45 ;
memcpy ( V_84 -> V_112 , V_221 -> V_112 , 6 ) ;
}
if ( ! F_137 ( V_84 -> V_112 ) ) {
V_223 = L_46 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ )
V_84 -> V_112 [ V_12 ] = F_7 ( V_3 , V_12 + V_111 ) ;
}
if ( ! F_137 ( V_84 -> V_112 ) ) {
F_93 ( V_3 -> V_2 , L_47
L_48 , V_84 -> V_52 ) ;
F_138 ( V_84 -> V_112 ) ;
V_223 = L_49 ;
}
F_139 ( V_95 , V_84 ) ;
V_29 = F_140 ( V_84 ) ;
if ( V_29 == 0 )
F_141 ( V_261 L_50 ,
V_84 -> V_52 , F_77 ( V_3 -> type ) ,
V_3 -> V_5 , V_3 -> V_7 , V_84 -> V_193 ,
V_84 -> V_112 , V_223 ) ;
return 0 ;
V_231:
F_106 ( V_3 -> V_2 , L_51 , V_29 ) ;
F_73 ( V_95 , V_3 ) ;
F_142 ( V_84 ) ;
return V_29 ;
}
static int
F_143 ( struct V_262 * V_2 )
{
struct V_94 * V_95 = F_45 ( V_2 ) ;
struct V_1 * V_84 = F_144 ( V_95 ) ;
T_1 * V_3 ;
if ( V_84 ) {
V_3 = F_2 ( V_84 ) ;
V_3 -> V_213 = 1 ;
if ( ! F_31 ( V_84 ) )
return 0 ;
F_145 ( V_84 ) ;
if ( ! V_3 -> V_75 )
F_117 ( V_84 ) ;
}
return 0 ;
}
static int
F_146 ( struct V_262 * V_2 )
{
struct V_94 * V_95 = F_45 ( V_2 ) ;
struct V_1 * V_84 = F_144 ( V_95 ) ;
T_1 * V_3 = F_2 ( V_84 ) ;
if ( V_84 ) {
if ( F_31 ( V_84 ) ) {
if ( ! V_3 -> V_75 ) {
F_3 ( V_3 ) ;
F_83 ( V_84 ) ;
}
F_147 ( V_84 ) ;
}
V_3 -> V_213 = 0 ;
}
return 0 ;
}
static int T_8
F_148 ( struct V_94 * V_95 )
{
struct V_1 * V_84 = F_144 ( V_95 ) ;
F_139 ( V_95 , NULL ) ;
F_149 ( V_84 ) ;
F_73 ( V_95 , F_2 ( V_84 ) ) ;
F_142 ( V_84 ) ;
F_4 ( & V_95 -> V_2 , L_52 ) ;
return 0 ;
}
static int T_9
F_150 ( void )
{
F_141 ( V_261 L_53 , V_48 , V_50 ) ;
return F_151 ( & V_263 ) ;
}
static void T_10
F_152 ( void )
{
F_153 ( & V_263 ) ;
}
