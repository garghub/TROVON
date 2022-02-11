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
static int F_54 ( struct V_1 * V_2 ,
T_5 V_55 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
T_5 V_56 = V_2 -> V_55 ^ V_55 ;
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
int V_69 ;
if ( V_25 -> V_28 & V_37 )
return - V_66 ;
if ( V_64 -> V_67 != V_68 )
return - V_26 ;
while ( V_65 > 0 ) {
if ( V_65 & 1 || V_35 & 1 ) {
int V_70 = V_35 & 1 ;
T_2 V_13 [ 2 ] ;
F_39 ( V_25 , V_35 / 2 , V_13 ) ;
V_13 [ V_70 ] = * V_10 ;
F_42 ( V_25 , V_35 / 2 , V_13 ) ;
V_69 = 1 ;
} else {
F_42 ( V_25 , V_35 / 2 , V_10 ) ;
V_69 = 2 ;
}
V_10 += V_69 ;
V_35 += V_69 ;
V_65 -= V_69 ;
}
return 0 ;
}
static void F_60 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
memset ( V_72 , 0 , sizeof( struct V_71 ) ) ;
V_72 -> V_73 = V_25 -> V_74 ? V_75 : 0 ;
V_72 -> V_76 = V_25 -> V_77 ;
}
static int F_61 ( struct V_1 * V_2 , struct V_71 * V_72 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
unsigned long V_28 ;
T_4 V_78 = V_72 -> V_76 ;
T_4 V_79 = 0 ;
if ( ! V_25 -> V_74 )
return - V_80 ;
if ( V_78 & ~ V_75 )
return - V_26 ;
if ( V_78 & V_75 )
V_79 |= V_81 ;
F_40 ( & V_25 -> V_38 ) ;
F_35 ( & V_25 -> V_30 , V_28 ) ;
F_9 ( V_25 , V_82 , V_79 ) ;
F_36 ( & V_25 -> V_30 , V_28 ) ;
F_41 ( & V_25 -> V_38 ) ;
if ( V_25 -> V_77 != V_78 ) {
if ( ! V_25 -> V_77 )
F_62 ( V_25 -> V_83 , 1 ) ;
else if ( V_25 -> V_77 && ! V_78 )
F_62 ( V_25 -> V_83 , 0 ) ;
}
V_25 -> V_77 = V_78 ;
return 0 ;
}
static void F_63 ( T_1 * V_3 ,
unsigned V_84 , unsigned V_85 )
{
struct V_1 * V_86 = V_3 -> V_86 ;
unsigned V_87 = F_34 ( V_3 , V_4 ) ;
if ( V_84 )
F_64 ( V_3 -> V_2 , L_4 ,
V_86 -> V_52 , ( V_85 & V_88 ) ? 10 : 100 ,
( V_87 & V_89 ) ? L_5 : L_6 ) ;
else
F_64 ( V_3 -> V_2 , L_7 , V_86 -> V_52 ) ;
}
static void
F_65 ( struct V_90 * V_72 )
{
struct V_91 * V_92 = F_66 ( V_72 ) ;
T_1 * V_3 = F_67 ( V_92 , T_1 , V_20 ) ;
struct V_1 * V_86 = V_3 -> V_86 ;
if ( V_3 -> V_28 & V_93 &&
! ( V_3 -> V_28 & V_60 ) ) {
unsigned V_85 = F_34 ( V_3 , V_61 ) ;
unsigned V_94 = F_68 ( V_86 ) ? 1 : 0 ;
unsigned V_95 ;
V_95 = ( V_85 & V_62 ) ? 1 : 0 ;
if ( V_94 != V_95 ) {
if ( F_69 ( V_3 ) )
F_63 ( V_3 , V_95 , V_85 ) ;
if ( ! V_95 )
F_70 ( V_86 ) ;
else
F_71 ( V_86 ) ;
}
} else
F_72 ( & V_3 -> V_27 , F_69 ( V_3 ) , 0 ) ;
if ( F_31 ( V_86 ) )
F_28 ( V_3 ) ;
}
static void
F_73 ( struct V_96 * V_97 , struct V_14 * V_3 )
{
F_74 ( V_3 -> V_5 ) ;
F_74 ( V_3 -> V_7 ) ;
F_75 ( V_3 -> V_98 ) ;
F_76 ( V_3 -> V_98 ) ;
F_75 ( V_3 -> V_99 ) ;
F_76 ( V_3 -> V_99 ) ;
}
static unsigned char F_77 ( enum V_100 type )
{
switch ( type ) {
case V_19 : return 'e' ;
case V_101 : return 'a' ;
case V_102 : return 'b' ;
}
return '?' ;
}
static void
F_78 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
struct V_103 * V_104 ;
int V_12 , V_105 ;
T_4 V_106 ;
T_6 V_107 [ 4 ] ;
T_2 V_108 = V_109 | V_110 | V_111 ;
F_79 ( V_3 , 1 , L_8 , V_112 ) ;
for ( V_12 = 0 , V_105 = V_113 ; V_12 < 6 ; V_12 ++ , V_105 ++ )
F_9 ( V_3 , V_105 , V_2 -> V_114 [ V_12 ] ) ;
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
V_107 [ V_12 ] = 0x0 ;
V_107 [ 3 ] = 0x8000 ;
if ( V_2 -> V_28 & V_115 )
V_108 |= V_116 ;
if ( V_2 -> V_28 & V_117 )
V_108 |= V_118 ;
F_80 (ha, dev) {
V_106 = F_81 ( 6 , V_104 -> V_119 ) & 0x3f ;
V_107 [ V_106 / 16 ] |= ( T_6 ) 1 << ( V_106 % 16 ) ;
}
for ( V_12 = 0 , V_105 = V_120 ; V_12 < 4 ; V_12 ++ ) {
F_9 ( V_3 , V_105 ++ , V_107 [ V_12 ] ) ;
F_9 ( V_3 , V_105 ++ , V_107 [ V_12 ] >> 8 ) ;
}
F_9 ( V_3 , V_121 , V_108 ) ;
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
unsigned int V_122 ;
unsigned int V_87 ;
F_79 ( V_3 , 1 , L_8 , V_112 ) ;
V_3 -> V_123 = F_7 ( V_3 , V_124 ) >> 6 ;
if ( V_2 -> V_125 & V_57 )
F_9 ( V_3 , V_58 ,
( V_2 -> V_55 & V_57 ) ? V_59 : 0 ) ;
F_9 ( V_3 , V_126 , V_127 ) ;
V_87 = ( V_3 -> V_28 & V_60 ) ? V_128 : 0 ;
if ( V_3 -> V_74 )
V_87 |= V_129 ;
F_9 ( V_3 , V_4 , V_87 ) ;
F_9 ( V_3 , V_130 , 0 ) ;
F_9 ( V_3 , V_131 , 0x3f ) ;
F_9 ( V_3 , V_132 , 0xff ) ;
F_9 ( V_3 , V_133 , 0 ) ;
F_9 ( V_3 , V_61 , V_134 | V_135 | V_136 ) ;
F_9 ( V_3 , V_124 , V_137 ) ;
F_78 ( V_2 ) ;
V_122 = V_138 | V_139 | V_140 ;
if ( V_3 -> type != V_19 )
V_122 |= V_141 ;
V_3 -> V_142 = V_122 ;
F_9 ( V_3 , V_143 , V_122 ) ;
V_3 -> V_144 = 0 ;
V_3 -> V_145 = 0 ;
V_2 -> V_146 = V_147 ;
}
static void F_84 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
T_2 V_148 ;
unsigned long V_28 ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_148 = F_8 ( V_3 -> V_5 ) ;
F_85 ( V_2 ) ;
F_3 ( V_3 ) ;
F_83 ( V_2 ) ;
V_2 -> V_146 = V_147 ;
F_86 ( V_2 ) ;
F_5 ( V_148 , V_3 -> V_5 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
}
static void F_87 ( struct V_1 * V_2 ,
int V_149 ,
T_6 V_150 )
{
T_1 * V_25 = F_1 ( V_2 ) ;
if ( V_25 -> V_149 != V_149 ) {
if ( V_149 == V_151 )
F_9 ( V_25 , V_152 , 0 ) ;
else
F_9 ( V_25 , V_152 , V_153 | V_154 | V_155 ) ;
V_25 -> V_149 = V_149 ;
}
F_9 ( V_25 , V_156 , V_150 ) ;
F_9 ( V_25 , V_157 , V_150 >> 8 ) ;
F_9 ( V_25 , V_130 , V_158 ) ;
}
static int
F_88 ( struct V_159 * V_160 , struct V_1 * V_2 )
{
unsigned long V_28 ;
T_1 * V_3 = F_2 ( V_2 ) ;
F_79 ( V_3 , 3 , L_9 , V_112 ) ;
if ( V_3 -> V_144 > 1 )
return V_161 ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
F_5 ( V_162 , V_3 -> V_5 ) ;
( V_3 -> V_17 ) ( V_3 -> V_7 , V_160 -> V_10 , V_160 -> V_65 ) ;
V_2 -> V_163 . V_164 += V_160 -> V_65 ;
V_3 -> V_144 ++ ;
if ( V_3 -> V_144 == 1 ) {
F_87 ( V_2 , V_160 -> V_149 , V_160 -> V_65 ) ;
} else {
V_3 -> V_145 = V_160 -> V_65 ;
V_3 -> V_165 = V_160 -> V_149 ;
F_85 ( V_2 ) ;
}
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_89 ( V_160 ) ;
return V_166 ;
}
static void F_90 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_167 = F_7 ( V_3 , V_61 ) ;
if ( V_167 & ( V_135 | V_136 ) ) {
V_3 -> V_144 -- ;
V_2 -> V_163 . V_168 ++ ;
if ( F_91 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_10 , V_167 ) ;
if ( V_3 -> V_144 > 0 )
F_87 ( V_2 , V_3 -> V_165 ,
V_3 -> V_145 ) ;
F_86 ( V_2 ) ;
}
}
static void
F_92 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
struct V_169 V_170 ;
struct V_159 * V_160 ;
T_2 V_171 , * V_172 ;
bool V_173 ;
int V_174 ;
do {
F_7 ( V_3 , V_175 ) ;
V_171 = F_8 ( V_3 -> V_7 ) ;
if ( V_171 & V_176 ) {
F_93 ( V_3 -> V_2 , L_11 , V_171 ) ;
F_9 ( V_3 , V_121 , 0x00 ) ;
F_9 ( V_3 , V_124 , V_138 ) ;
return;
}
if ( ! ( V_171 & V_177 ) )
return;
V_173 = true ;
F_5 ( V_178 , V_3 -> V_5 ) ;
( V_3 -> V_18 ) ( V_3 -> V_7 , & V_170 , sizeof( V_170 ) ) ;
V_174 = F_94 ( V_170 . V_174 ) ;
if ( F_95 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_12 ,
V_170 . V_179 , V_174 ) ;
if ( V_174 < 0x40 ) {
V_173 = false ;
if ( F_96 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_13 ) ;
}
if ( V_174 > V_180 ) {
F_4 ( V_3 -> V_2 , L_14 , V_174 ) ;
}
if ( V_170 . V_179 & ( V_181 | V_182 | V_183 |
V_184 | V_185 |
V_186 | V_187 ) ) {
V_173 = false ;
if ( V_170 . V_179 & V_181 ) {
if ( F_96 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_15 ) ;
V_2 -> V_163 . V_188 ++ ;
}
if ( V_170 . V_179 & V_182 ) {
if ( F_96 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_16 ) ;
V_2 -> V_163 . V_189 ++ ;
}
if ( V_170 . V_179 & V_187 ) {
if ( F_96 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_17 ) ;
V_2 -> V_163 . V_190 ++ ;
}
}
if ( V_173 &&
( ( V_160 = F_97 ( V_174 + 4 ) ) != NULL ) ) {
F_98 ( V_160 , 2 ) ;
V_172 = ( T_2 * ) F_99 ( V_160 , V_174 - 4 ) ;
( V_3 -> V_18 ) ( V_3 -> V_7 , V_172 , V_174 ) ;
V_2 -> V_163 . V_191 += V_174 ;
V_160 -> V_192 = F_100 ( V_160 , V_2 ) ;
if ( V_2 -> V_55 & V_57 ) {
if ( ( ( ( V_171 & 0x1c ) << 3 ) & V_171 ) == 0 )
V_160 -> V_149 = V_193 ;
else
F_101 ( V_160 ) ;
}
F_102 ( V_160 ) ;
V_2 -> V_163 . V_194 ++ ;
} else {
( V_3 -> V_16 ) ( V_3 -> V_7 , V_174 ) ;
}
} while ( V_171 & V_177 );
}
static T_7 F_103 ( int V_195 , void * V_196 )
{
struct V_1 * V_2 = V_196 ;
T_1 * V_3 = F_2 ( V_2 ) ;
int V_197 ;
unsigned long V_28 ;
T_2 V_148 ;
F_79 ( V_3 , 3 , L_8 , V_112 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_148 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_143 , V_138 ) ;
V_197 = F_7 ( V_3 , V_124 ) ;
F_9 ( V_3 , V_124 , V_197 ) ;
if ( F_104 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_18 , V_197 ) ;
if ( V_197 & V_198 )
F_92 ( V_2 ) ;
if ( V_197 & V_199 )
F_90 ( V_2 , V_3 ) ;
if ( V_3 -> type != V_19 ) {
if ( V_197 & V_200 ) {
F_29 ( & V_3 -> V_20 , 1 ) ;
}
}
F_9 ( V_3 , V_143 , V_3 -> V_142 ) ;
F_5 ( V_148 , V_3 -> V_5 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
return V_201 ;
}
static T_7 F_105 ( int V_195 , void * V_196 )
{
struct V_1 * V_2 = V_196 ;
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_28 ;
unsigned V_85 , V_79 ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_85 = F_7 ( V_3 , V_61 ) ;
V_79 = F_7 ( V_3 , V_82 ) ;
F_4 ( V_3 -> V_2 , L_19 , V_112 , V_85 , V_79 ) ;
if ( V_85 & V_134 ) {
F_9 ( V_3 , V_61 , V_134 ) ;
if ( V_79 & V_202 )
F_64 ( V_3 -> V_2 , L_20 ) ;
if ( V_79 & V_203 )
F_64 ( V_3 -> V_2 , L_21 ) ;
if ( V_79 & V_204 )
F_64 ( V_3 -> V_2 , L_22 ) ;
if ( ! ( V_79 & ( V_202 | V_203 | V_204 ) ) )
F_106 ( V_3 -> V_2 , L_23
L_24 , V_85 , V_79 ) ;
}
F_36 ( & V_3 -> V_30 , V_28 ) ;
return ( V_85 & V_134 ) ? V_201 : V_205 ;
}
static void F_107 ( struct V_1 * V_2 )
{
F_108 ( V_2 -> V_195 ) ;
F_103 ( V_2 -> V_195 , V_2 ) ;
F_109 ( V_2 -> V_195 ) ;
}
static int
F_110 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_206 = V_3 -> V_207 -> V_28 & V_208 ;
if ( F_111 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_25 , V_2 -> V_52 ) ;
if ( V_206 == V_209 )
F_93 ( V_3 -> V_2 , L_26 ) ;
V_206 |= V_210 ;
F_9 ( V_3 , V_211 , 0 ) ;
F_43 ( 1 ) ;
F_3 ( V_3 ) ;
F_83 ( V_2 ) ;
if ( F_112 ( V_2 -> V_195 , F_103 , V_206 , V_2 -> V_52 , V_2 ) )
return - V_212 ;
V_3 -> V_213 = 0 ;
F_72 ( & V_3 -> V_27 , F_69 ( V_3 ) , 1 ) ;
F_113 ( V_2 ) ;
F_28 ( V_3 ) ;
return 0 ;
}
static void F_114 ( T_1 * V_3 , unsigned int V_214 )
{
if ( V_3 -> V_215 )
F_43 ( V_214 ) ;
else
F_38 ( V_214 ) ;
}
static int
F_115 ( struct V_1 * V_2 , int V_216 , int V_8 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_28 ;
unsigned int V_148 ;
int V_29 ;
F_40 ( & V_3 -> V_38 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_148 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_39 , V_217 | V_8 ) ;
F_9 ( V_3 , V_33 , V_40 | V_218 ) ;
F_5 ( V_148 , V_3 -> V_5 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_114 ( V_3 , 1 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_148 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_33 , 0x0 ) ;
V_29 = ( F_7 ( V_3 , V_42 ) << 8 ) | F_7 ( V_3 , V_41 ) ;
F_5 ( V_148 , V_3 -> V_5 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_41 ( & V_3 -> V_38 ) ;
F_79 ( V_3 , 5 , L_27 , V_8 , V_29 ) ;
return V_29 ;
}
static void
F_116 ( struct V_1 * V_2 ,
int V_219 , int V_8 , int V_9 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_28 ;
unsigned long V_148 ;
F_79 ( V_3 , 5 , L_28 , V_8 , V_9 ) ;
F_40 ( & V_3 -> V_38 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_148 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_39 , V_217 | V_8 ) ;
F_9 ( V_3 , V_41 , V_9 ) ;
F_9 ( V_3 , V_42 , V_9 >> 8 ) ;
F_9 ( V_3 , V_33 , V_218 | V_44 ) ;
F_5 ( V_148 , V_3 -> V_5 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_114 ( V_3 , 1 ) ;
F_35 ( & V_3 -> V_30 , V_28 ) ;
V_148 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_33 , 0x0 ) ;
F_5 ( V_148 , V_3 -> V_5 ) ;
F_36 ( & V_3 -> V_30 , V_28 ) ;
F_41 ( & V_3 -> V_38 ) ;
}
static void
F_117 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
F_116 ( V_2 , 0 , V_220 , V_221 ) ;
F_9 ( V_3 , V_211 , 0x01 ) ;
F_9 ( V_3 , V_143 , V_138 ) ;
F_9 ( V_3 , V_121 , 0x00 ) ;
}
static int
F_118 ( struct V_1 * V_86 )
{
T_1 * V_3 = F_2 ( V_86 ) ;
if ( F_119 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_29 , V_86 -> V_52 ) ;
F_120 ( & V_3 -> V_20 ) ;
F_85 ( V_86 ) ;
F_70 ( V_86 ) ;
F_121 ( V_86 -> V_195 , V_86 ) ;
F_117 ( V_86 ) ;
return 0 ;
}
static int T_8
F_122 ( struct V_96 * V_97 )
{
struct V_222 * V_223 = V_97 -> V_2 . V_224 ;
struct V_14 * V_3 ;
struct V_1 * V_86 ;
const unsigned char * V_225 ;
int V_29 = 0 ;
int V_226 ;
int V_12 ;
T_4 V_227 ;
V_86 = F_123 ( sizeof( struct V_14 ) ) ;
if ( ! V_86 ) {
F_106 ( & V_97 -> V_2 , L_30 ) ;
return - V_228 ;
}
F_124 ( V_86 , & V_97 -> V_2 ) ;
F_4 ( & V_97 -> V_2 , L_31 ) ;
V_3 = F_2 ( V_86 ) ;
V_3 -> V_2 = & V_97 -> V_2 ;
V_3 -> V_86 = V_86 ;
F_125 ( & V_3 -> V_30 ) ;
F_126 ( & V_3 -> V_38 ) ;
F_127 ( & V_3 -> V_20 , F_65 ) ;
V_3 -> V_229 = F_128 ( V_97 , V_230 , 0 ) ;
V_3 -> V_231 = F_128 ( V_97 , V_230 , 1 ) ;
V_3 -> V_207 = F_128 ( V_97 , V_232 , 0 ) ;
if ( V_3 -> V_229 == NULL || V_3 -> V_231 == NULL ||
V_3 -> V_207 == NULL ) {
F_106 ( V_3 -> V_2 , L_32 ) ;
V_29 = - V_66 ;
goto V_233;
}
V_3 -> V_83 = F_129 ( V_97 , 1 ) ;
if ( V_3 -> V_83 >= 0 ) {
F_4 ( V_3 -> V_2 , L_33 , V_3 -> V_83 ) ;
V_29 = F_112 ( V_3 -> V_83 , F_105 ,
V_210 , F_130 ( V_3 -> V_2 ) , V_86 ) ;
if ( V_29 ) {
F_106 ( V_3 -> V_2 , L_34 , V_29 ) ;
} else {
V_29 = F_62 ( V_3 -> V_83 , 1 ) ;
if ( V_29 ) {
F_106 ( V_3 -> V_2 , L_35 ,
V_3 -> V_83 , V_29 ) ;
V_29 = 0 ;
} else {
F_62 ( V_3 -> V_83 , 0 ) ;
V_3 -> V_74 = 1 ;
}
}
}
V_226 = F_131 ( V_3 -> V_229 ) ;
V_3 -> V_99 = F_132 ( V_3 -> V_229 -> V_234 , V_226 ,
V_97 -> V_52 ) ;
if ( V_3 -> V_99 == NULL ) {
F_106 ( V_3 -> V_2 , L_36 ) ;
V_29 = - V_235 ;
goto V_233;
}
V_3 -> V_5 = F_133 ( V_3 -> V_229 -> V_234 , V_226 ) ;
if ( V_3 -> V_5 == NULL ) {
F_106 ( V_3 -> V_2 , L_37 ) ;
V_29 = - V_26 ;
goto V_233;
}
V_226 = F_131 ( V_3 -> V_231 ) ;
V_3 -> V_98 = F_132 ( V_3 -> V_231 -> V_234 , V_226 ,
V_97 -> V_52 ) ;
if ( V_3 -> V_98 == NULL ) {
F_106 ( V_3 -> V_2 , L_38 ) ;
V_29 = - V_235 ;
goto V_233;
}
V_3 -> V_7 = F_133 ( V_3 -> V_231 -> V_234 , V_226 ) ;
if ( V_3 -> V_7 == NULL ) {
F_106 ( V_3 -> V_2 , L_39 ) ;
V_29 = - V_26 ;
goto V_233;
}
V_86 -> V_236 = ( unsigned long ) V_3 -> V_5 ;
V_86 -> V_195 = V_3 -> V_207 -> V_234 ;
F_27 ( V_3 , V_226 ) ;
if ( V_223 != NULL ) {
if ( V_223 -> V_28 & V_237 )
F_27 ( V_3 , 1 ) ;
if ( V_223 -> V_28 & V_238 )
F_27 ( V_3 , 2 ) ;
if ( V_223 -> V_28 & V_239 )
F_27 ( V_3 , 4 ) ;
if ( V_223 -> V_18 != NULL )
V_3 -> V_18 = V_223 -> V_18 ;
if ( V_223 -> V_17 != NULL )
V_3 -> V_17 = V_223 -> V_17 ;
if ( V_223 -> V_16 != NULL )
V_3 -> V_16 = V_223 -> V_16 ;
V_3 -> V_28 = V_223 -> V_28 ;
}
#ifdef F_134
V_3 -> V_28 |= V_93 ;
#endif
F_3 ( V_3 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_227 = F_7 ( V_3 , V_240 ) ;
V_227 |= ( T_4 ) F_7 ( V_3 , V_241 ) << 8 ;
V_227 |= ( T_4 ) F_7 ( V_3 , V_242 ) << 16 ;
V_227 |= ( T_4 ) F_7 ( V_3 , V_243 ) << 24 ;
if ( V_227 == V_244 )
break;
F_106 ( V_3 -> V_2 , L_40 , V_227 ) ;
}
if ( V_227 != V_244 ) {
F_106 ( V_3 -> V_2 , L_41 , V_227 ) ;
V_29 = - V_245 ;
goto V_233;
}
V_227 = F_7 ( V_3 , V_246 ) ;
F_4 ( V_3 -> V_2 , L_42 , V_227 ) ;
switch ( V_227 ) {
case V_247 :
V_3 -> type = V_101 ;
break;
case V_248 :
V_3 -> type = V_102 ;
break;
default:
F_4 ( V_3 -> V_2 , L_43 , V_227 ) ;
V_3 -> type = V_19 ;
}
if ( V_3 -> type == V_101 || V_3 -> type == V_102 ) {
V_86 -> V_125 = V_57 | V_249 ;
V_86 -> V_55 |= V_86 -> V_125 ;
}
F_135 ( V_86 ) ;
V_86 -> V_250 = & V_251 ;
V_86 -> V_252 = F_136 ( V_253 ) ;
V_86 -> V_254 = & V_255 ;
V_3 -> V_53 = V_256 ;
V_3 -> V_27 . V_257 = 0x1f ;
V_3 -> V_27 . V_258 = 0x1f ;
V_3 -> V_27 . V_259 = 0 ;
V_3 -> V_27 . V_260 = 0 ;
V_3 -> V_27 . V_2 = V_86 ;
V_3 -> V_27 . V_261 = F_115 ;
V_3 -> V_27 . V_262 = F_116 ;
V_225 = L_44 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 += 2 )
F_39 ( V_3 , V_12 / 2 , V_86 -> V_114 + V_12 ) ;
if ( ! F_137 ( V_86 -> V_114 ) && V_223 != NULL ) {
V_225 = L_45 ;
memcpy ( V_86 -> V_114 , V_223 -> V_114 , 6 ) ;
}
if ( ! F_137 ( V_86 -> V_114 ) ) {
V_225 = L_46 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ )
V_86 -> V_114 [ V_12 ] = F_7 ( V_3 , V_12 + V_113 ) ;
}
if ( ! F_137 ( V_86 -> V_114 ) ) {
F_93 ( V_3 -> V_2 , L_47
L_48 , V_86 -> V_52 ) ;
F_138 ( V_86 -> V_114 ) ;
V_225 = L_49 ;
}
F_139 ( V_97 , V_86 ) ;
V_29 = F_140 ( V_86 ) ;
if ( V_29 == 0 )
F_141 ( V_263 L_50 ,
V_86 -> V_52 , F_77 ( V_3 -> type ) ,
V_3 -> V_5 , V_3 -> V_7 , V_86 -> V_195 ,
V_86 -> V_114 , V_225 ) ;
return 0 ;
V_233:
F_106 ( V_3 -> V_2 , L_51 , V_29 ) ;
F_73 ( V_97 , V_3 ) ;
F_142 ( V_86 ) ;
return V_29 ;
}
static int
F_143 ( struct V_264 * V_2 )
{
struct V_96 * V_97 = F_45 ( V_2 ) ;
struct V_1 * V_86 = F_144 ( V_97 ) ;
T_1 * V_3 ;
if ( V_86 ) {
V_3 = F_2 ( V_86 ) ;
V_3 -> V_215 = 1 ;
if ( ! F_31 ( V_86 ) )
return 0 ;
F_145 ( V_86 ) ;
if ( ! V_3 -> V_77 )
F_117 ( V_86 ) ;
}
return 0 ;
}
static int
F_146 ( struct V_264 * V_2 )
{
struct V_96 * V_97 = F_45 ( V_2 ) ;
struct V_1 * V_86 = F_144 ( V_97 ) ;
T_1 * V_3 = F_2 ( V_86 ) ;
if ( V_86 ) {
if ( F_31 ( V_86 ) ) {
if ( ! V_3 -> V_77 ) {
F_3 ( V_3 ) ;
F_83 ( V_86 ) ;
}
F_147 ( V_86 ) ;
}
V_3 -> V_215 = 0 ;
}
return 0 ;
}
static int T_9
F_148 ( struct V_96 * V_97 )
{
struct V_1 * V_86 = F_144 ( V_97 ) ;
F_139 ( V_97 , NULL ) ;
F_149 ( V_86 ) ;
F_73 ( V_97 , F_2 ( V_86 ) ) ;
F_142 ( V_86 ) ;
F_4 ( & V_97 -> V_2 , L_52 ) ;
return 0 ;
}
static int T_10
F_150 ( void )
{
F_141 ( V_263 L_53 , V_48 , V_50 ) ;
return F_151 ( & V_265 ) ;
}
static void T_11
F_152 ( void )
{
F_153 ( & V_265 ) ;
}
