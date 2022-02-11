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
static void F_27 ( T_1 * V_3 , unsigned int V_14 )
{
if ( V_3 -> V_15 )
F_28 ( V_14 ) ;
else
F_29 ( V_14 ) ;
}
static int
F_30 ( struct V_1 * V_2 , int V_16 , int V_8 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_17 ;
unsigned int V_18 ;
int V_19 ;
F_31 ( & V_3 -> V_20 ) ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
V_18 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_22 , V_23 | V_8 ) ;
F_9 ( V_3 , V_24 , V_25 | V_26 ) ;
F_5 ( V_18 , V_3 -> V_5 ) ;
F_33 ( & V_3 -> V_21 , V_17 ) ;
F_27 ( V_3 , 1 ) ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
V_18 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_24 , 0x0 ) ;
V_19 = ( F_7 ( V_3 , V_27 ) << 8 ) | F_7 ( V_3 , V_28 ) ;
F_5 ( V_18 , V_3 -> V_5 ) ;
F_33 ( & V_3 -> V_21 , V_17 ) ;
F_34 ( & V_3 -> V_20 ) ;
F_35 ( V_3 , 5 , L_2 , V_8 , V_19 ) ;
return V_19 ;
}
static void
F_36 ( struct V_1 * V_2 ,
int V_29 , int V_8 , int V_9 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_17 ;
unsigned long V_18 ;
F_35 ( V_3 , 5 , L_3 , V_8 , V_9 ) ;
F_31 ( & V_3 -> V_20 ) ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
V_18 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_22 , V_23 | V_8 ) ;
F_9 ( V_3 , V_28 , V_9 ) ;
F_9 ( V_3 , V_27 , V_9 >> 8 ) ;
F_9 ( V_3 , V_24 , V_26 | V_30 ) ;
F_5 ( V_18 , V_3 -> V_5 ) ;
F_33 ( & V_3 -> V_21 , V_17 ) ;
F_27 ( V_3 , 1 ) ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
V_18 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_24 , 0x0 ) ;
F_5 ( V_18 , V_3 -> V_5 ) ;
F_33 ( & V_3 -> V_21 , V_17 ) ;
F_34 ( & V_3 -> V_20 ) ;
}
static void F_37 ( struct V_31 * V_3 , int V_32 )
{
switch ( V_32 ) {
case 1 :
V_3 -> V_33 = F_22 ;
V_3 -> V_34 = F_10 ;
V_3 -> V_35 = F_16 ;
break;
case 3 :
F_4 ( V_3 -> V_2 , L_4 ) ;
case 2 :
V_3 -> V_33 = F_23 ;
V_3 -> V_34 = F_12 ;
V_3 -> V_35 = F_18 ;
break;
case 4 :
default:
V_3 -> V_33 = F_25 ;
V_3 -> V_34 = F_14 ;
V_3 -> V_35 = F_20 ;
break;
}
}
static void F_38 ( T_1 * V_3 )
{
if ( V_3 -> type == V_36 )
F_39 ( & V_3 -> V_37 , V_38 * 2 ) ;
}
static int F_40 ( struct V_1 * V_2 , struct V_39 * V_40 , int V_41 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
if ( ! F_41 ( V_2 ) )
return - V_43 ;
return F_42 ( & V_42 -> V_44 , F_43 ( V_40 ) , V_41 , NULL ) ;
}
static unsigned int
F_44 ( T_1 * V_3 , int V_8 )
{
unsigned long V_17 ;
unsigned int V_19 ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
V_19 = F_7 ( V_3 , V_8 ) ;
F_33 ( & V_3 -> V_21 , V_17 ) ;
return V_19 ;
}
static int F_45 ( T_1 * V_3 )
{
unsigned int V_45 ;
int V_46 = 8 ;
while ( 1 ) {
V_45 = F_44 ( V_3 , V_24 ) ;
if ( ( V_45 & V_47 ) == 0 )
break;
F_29 ( 1 ) ;
if ( V_46 -- < 0 ) {
F_4 ( V_3 -> V_2 , L_5 ) ;
break;
}
}
return 0 ;
}
static void
F_46 ( T_1 * V_3 , int V_48 , T_2 * V_49 )
{
unsigned long V_17 ;
if ( V_3 -> V_17 & V_50 ) {
V_49 [ 0 ] = 0xff ;
V_49 [ 1 ] = 0xff ;
return;
}
F_31 ( & V_3 -> V_20 ) ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
F_9 ( V_3 , V_22 , V_48 ) ;
F_9 ( V_3 , V_24 , V_25 ) ;
F_33 ( & V_3 -> V_21 , V_17 ) ;
F_45 ( V_3 ) ;
F_29 ( 1 ) ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
F_9 ( V_3 , V_24 , 0x0 ) ;
V_49 [ 0 ] = F_7 ( V_3 , V_28 ) ;
V_49 [ 1 ] = F_7 ( V_3 , V_27 ) ;
F_33 ( & V_3 -> V_21 , V_17 ) ;
F_34 ( & V_3 -> V_20 ) ;
}
static void
F_47 ( T_1 * V_3 , int V_48 , T_2 * V_10 )
{
unsigned long V_17 ;
if ( V_3 -> V_17 & V_50 )
return;
F_31 ( & V_3 -> V_20 ) ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
F_9 ( V_3 , V_22 , V_48 ) ;
F_9 ( V_3 , V_27 , V_10 [ 1 ] ) ;
F_9 ( V_3 , V_28 , V_10 [ 0 ] ) ;
F_9 ( V_3 , V_24 , V_51 | V_30 ) ;
F_33 ( & V_3 -> V_21 , V_17 ) ;
F_45 ( V_3 ) ;
F_28 ( 1 ) ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
F_9 ( V_3 , V_24 , 0 ) ;
F_33 ( & V_3 -> V_21 , V_17 ) ;
F_34 ( & V_3 -> V_20 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
F_49 ( V_53 -> V_54 , V_55 , sizeof( V_53 -> V_54 ) ) ;
F_49 ( V_53 -> V_56 , V_57 , sizeof( V_53 -> V_56 ) ) ;
F_49 ( V_53 -> V_58 , F_50 ( V_42 -> V_2 ) -> V_59 ,
sizeof( V_53 -> V_58 ) ) ;
}
static T_4 F_51 ( struct V_1 * V_2 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
return V_42 -> V_60 ;
}
static void F_52 ( struct V_1 * V_2 , T_4 V_9 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
V_42 -> V_60 = V_9 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_61 * V_41 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
F_54 ( & V_42 -> V_44 , V_41 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , struct V_61 * V_41 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
return F_56 ( & V_42 -> V_44 , V_41 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
return F_58 ( & V_42 -> V_44 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
T_5 V_62 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
T_5 V_63 = V_2 -> V_62 ^ V_62 ;
unsigned long V_17 ;
if ( ! ( V_63 & V_64 ) )
return 0 ;
F_32 ( & V_42 -> V_21 , V_17 ) ;
F_9 ( V_42 , V_65 , ( V_62 & V_64 ) ? V_66 : 0 ) ;
F_33 ( & V_42 -> V_21 , V_17 ) ;
return 0 ;
}
static T_4 F_60 ( struct V_1 * V_2 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
T_4 V_19 ;
if ( V_42 -> V_17 & V_67 )
V_19 = F_61 ( & V_42 -> V_44 ) ;
else
V_19 = F_44 ( V_42 , V_68 ) & V_69 ? 1 : 0 ;
return V_19 ;
}
static int F_62 ( struct V_1 * V_2 )
{
return 128 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_70 * V_71 , T_2 * V_10 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
int V_48 = V_71 -> V_48 ;
int V_72 = V_71 -> V_72 ;
int V_12 ;
if ( ( V_72 & 1 ) != 0 || ( V_48 & 1 ) != 0 )
return - V_43 ;
if ( V_42 -> V_17 & V_50 )
return - V_73 ;
V_71 -> V_74 = V_75 ;
for ( V_12 = 0 ; V_12 < V_72 ; V_12 += 2 )
F_46 ( V_42 , ( V_48 + V_12 ) / 2 , V_10 + V_12 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_70 * V_71 , T_2 * V_10 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
int V_48 = V_71 -> V_48 ;
int V_72 = V_71 -> V_72 ;
int V_76 ;
if ( V_42 -> V_17 & V_50 )
return - V_73 ;
if ( V_71 -> V_74 != V_75 )
return - V_43 ;
while ( V_72 > 0 ) {
if ( V_72 & 1 || V_48 & 1 ) {
int V_77 = V_48 & 1 ;
T_2 V_13 [ 2 ] ;
F_46 ( V_42 , V_48 / 2 , V_13 ) ;
V_13 [ V_77 ] = * V_10 ;
F_47 ( V_42 , V_48 / 2 , V_13 ) ;
V_76 = 1 ;
} else {
F_47 ( V_42 , V_48 / 2 , V_10 ) ;
V_76 = 2 ;
}
V_10 += V_76 ;
V_48 += V_76 ;
V_72 -= V_76 ;
}
return 0 ;
}
static void F_65 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
memset ( V_79 , 0 , sizeof( struct V_78 ) ) ;
V_79 -> V_80 = V_42 -> V_81 ? V_82 : 0 ;
V_79 -> V_83 = V_42 -> V_84 ;
}
static int F_66 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
unsigned long V_17 ;
T_4 V_85 = V_79 -> V_83 ;
T_4 V_86 = 0 ;
if ( ! V_42 -> V_81 )
return - V_87 ;
if ( V_85 & ~ V_82 )
return - V_43 ;
if ( V_85 & V_82 )
V_86 |= V_88 ;
F_31 ( & V_42 -> V_20 ) ;
F_32 ( & V_42 -> V_21 , V_17 ) ;
F_9 ( V_42 , V_89 , V_86 ) ;
F_33 ( & V_42 -> V_21 , V_17 ) ;
F_34 ( & V_42 -> V_20 ) ;
if ( V_42 -> V_84 != V_85 ) {
if ( ! V_42 -> V_84 )
F_67 ( V_42 -> V_90 , 1 ) ;
else if ( V_42 -> V_84 && ! V_85 )
F_67 ( V_42 -> V_90 , 0 ) ;
}
V_42 -> V_84 = V_85 ;
return 0 ;
}
static void F_68 ( T_1 * V_3 ,
unsigned V_91 , unsigned V_92 )
{
struct V_1 * V_93 = V_3 -> V_93 ;
unsigned V_94 = F_44 ( V_3 , V_4 ) ;
if ( V_91 )
F_69 ( V_3 -> V_2 , L_6 ,
V_93 -> V_59 , ( V_92 & V_95 ) ? 10 : 100 ,
( V_94 & V_96 ) ? L_7 : L_8 ) ;
else
F_69 ( V_3 -> V_2 , L_9 , V_93 -> V_59 ) ;
}
static void
F_70 ( struct V_97 * V_79 )
{
struct V_98 * V_99 = F_71 ( V_79 ) ;
T_1 * V_3 = F_72 ( V_99 , T_1 , V_37 ) ;
struct V_1 * V_93 = V_3 -> V_93 ;
if ( V_3 -> V_17 & V_100 &&
! ( V_3 -> V_17 & V_67 ) ) {
unsigned V_92 = F_44 ( V_3 , V_68 ) ;
unsigned V_101 = F_73 ( V_93 ) ? 1 : 0 ;
unsigned V_102 ;
V_102 = ( V_92 & V_69 ) ? 1 : 0 ;
if ( V_101 != V_102 ) {
if ( F_74 ( V_3 ) )
F_68 ( V_3 , V_102 , V_92 ) ;
if ( ! V_102 )
F_75 ( V_93 ) ;
else
F_76 ( V_93 ) ;
}
} else
F_77 ( & V_3 -> V_44 , F_74 ( V_3 ) , 0 ) ;
if ( F_41 ( V_93 ) )
F_38 ( V_3 ) ;
}
static void
F_78 ( struct V_103 * V_104 , struct V_31 * V_3 )
{
F_79 ( V_3 -> V_5 ) ;
F_79 ( V_3 -> V_7 ) ;
F_80 ( V_3 -> V_105 ) ;
F_81 ( V_3 -> V_105 ) ;
F_80 ( V_3 -> V_106 ) ;
F_81 ( V_3 -> V_106 ) ;
}
static unsigned char F_82 ( enum V_107 type )
{
switch ( type ) {
case V_36 : return 'e' ;
case V_108 : return 'a' ;
case V_109 : return 'b' ;
}
return '?' ;
}
static void
F_83 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
struct V_110 * V_111 ;
int V_12 , V_112 ;
T_4 V_113 ;
T_6 V_114 [ 4 ] ;
T_2 V_115 = V_116 | V_117 | V_118 ;
F_35 ( V_3 , 1 , L_10 , V_119 ) ;
for ( V_12 = 0 , V_112 = V_120 ; V_12 < 6 ; V_12 ++ , V_112 ++ )
F_9 ( V_3 , V_112 , V_2 -> V_121 [ V_12 ] ) ;
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ )
V_114 [ V_12 ] = 0x0 ;
V_114 [ 3 ] = 0x8000 ;
if ( V_2 -> V_17 & V_122 )
V_115 |= V_123 ;
if ( V_2 -> V_17 & V_124 )
V_115 |= V_125 ;
F_84 (ha, dev) {
V_113 = F_85 ( 6 , V_111 -> V_126 ) & 0x3f ;
V_114 [ V_113 / 16 ] |= ( T_6 ) 1 << ( V_113 % 16 ) ;
}
for ( V_12 = 0 , V_112 = V_127 ; V_12 < 4 ; V_12 ++ ) {
F_9 ( V_3 , V_112 ++ , V_114 [ V_12 ] ) ;
F_9 ( V_3 , V_112 ++ , V_114 [ V_12 ] >> 8 ) ;
}
F_9 ( V_3 , V_128 , V_115 ) ;
}
static void
F_86 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_17 ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
F_83 ( V_2 ) ;
F_33 ( & V_3 -> V_21 , V_17 ) ;
}
static void
F_87 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned int V_129 ;
unsigned int V_94 ;
F_35 ( V_3 , 1 , L_10 , V_119 ) ;
V_3 -> V_130 = F_7 ( V_3 , V_131 ) >> 6 ;
if ( V_2 -> V_132 & V_64 )
F_9 ( V_3 , V_65 ,
( V_2 -> V_62 & V_64 ) ? V_66 : 0 ) ;
F_9 ( V_3 , V_133 , V_134 ) ;
F_36 ( V_2 , 0 , V_135 , V_136 ) ;
F_36 ( V_2 , 0 , V_137 , V_138 ) ;
V_94 = ( V_3 -> V_17 & V_67 ) ? V_139 : 0 ;
if ( V_3 -> V_81 )
V_94 |= V_140 ;
F_9 ( V_3 , V_4 , V_94 ) ;
F_9 ( V_3 , V_141 , 0 ) ;
F_9 ( V_3 , V_142 , 0x3f ) ;
F_9 ( V_3 , V_143 , 0xff ) ;
F_9 ( V_3 , V_144 , 0 ) ;
F_9 ( V_3 , V_68 , V_145 | V_146 | V_147 ) ;
F_9 ( V_3 , V_131 , V_148 ) ;
F_83 ( V_2 ) ;
V_129 = V_149 | V_150 | V_151 ;
if ( V_3 -> type != V_36 )
V_129 |= V_152 ;
V_3 -> V_153 = V_129 ;
F_9 ( V_3 , V_154 , V_129 ) ;
V_3 -> V_155 = 0 ;
V_3 -> V_156 = 0 ;
V_2 -> V_157 = V_158 ;
}
static void F_88 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
T_2 V_18 ;
unsigned long V_17 ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
V_18 = F_8 ( V_3 -> V_5 ) ;
F_89 ( V_2 ) ;
F_3 ( V_3 ) ;
F_87 ( V_2 ) ;
V_2 -> V_157 = V_158 ;
F_90 ( V_2 ) ;
F_5 ( V_18 , V_3 -> V_5 ) ;
F_33 ( & V_3 -> V_21 , V_17 ) ;
}
static void F_91 ( struct V_1 * V_2 ,
int V_159 ,
T_6 V_160 )
{
T_1 * V_42 = F_1 ( V_2 ) ;
if ( V_42 -> V_159 != V_159 ) {
if ( V_159 == V_161 )
F_9 ( V_42 , V_162 , 0 ) ;
else
F_9 ( V_42 , V_162 , V_163 | V_164 | V_165 ) ;
V_42 -> V_159 = V_159 ;
}
F_9 ( V_42 , V_166 , V_160 ) ;
F_9 ( V_42 , V_167 , V_160 >> 8 ) ;
F_9 ( V_42 , V_141 , V_168 ) ;
}
static int
F_92 ( struct V_169 * V_170 , struct V_1 * V_2 )
{
unsigned long V_17 ;
T_1 * V_3 = F_2 ( V_2 ) ;
F_35 ( V_3 , 3 , L_11 , V_119 ) ;
if ( V_3 -> V_155 > 1 )
return V_171 ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
F_5 ( V_172 , V_3 -> V_5 ) ;
( V_3 -> V_34 ) ( V_3 -> V_7 , V_170 -> V_10 , V_170 -> V_72 ) ;
V_2 -> V_173 . V_174 += V_170 -> V_72 ;
V_3 -> V_155 ++ ;
if ( V_3 -> V_155 == 1 ) {
F_91 ( V_2 , V_170 -> V_159 , V_170 -> V_72 ) ;
} else {
V_3 -> V_156 = V_170 -> V_72 ;
V_3 -> V_175 = V_170 -> V_159 ;
F_89 ( V_2 ) ;
}
F_33 ( & V_3 -> V_21 , V_17 ) ;
F_93 ( V_170 ) ;
return V_176 ;
}
static void F_94 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_177 = F_7 ( V_3 , V_68 ) ;
if ( V_177 & ( V_146 | V_147 ) ) {
V_3 -> V_155 -- ;
V_2 -> V_173 . V_178 ++ ;
if ( F_95 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_12 , V_177 ) ;
if ( V_3 -> V_155 > 0 )
F_91 ( V_2 , V_3 -> V_175 ,
V_3 -> V_156 ) ;
F_90 ( V_2 ) ;
}
}
static void
F_96 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
struct V_179 V_180 ;
struct V_169 * V_170 ;
T_2 V_181 , * V_182 ;
bool V_183 ;
int V_184 ;
do {
F_7 ( V_3 , V_185 ) ;
V_181 = F_8 ( V_3 -> V_7 ) ;
if ( V_181 & V_186 ) {
F_97 ( V_3 -> V_2 , L_13 , V_181 ) ;
F_9 ( V_3 , V_128 , 0x00 ) ;
F_9 ( V_3 , V_131 , V_149 ) ;
return;
}
if ( ! ( V_181 & V_187 ) )
return;
V_183 = true ;
F_5 ( V_188 , V_3 -> V_5 ) ;
( V_3 -> V_35 ) ( V_3 -> V_7 , & V_180 , sizeof( V_180 ) ) ;
V_184 = F_98 ( V_180 . V_184 ) ;
if ( F_99 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_14 ,
V_180 . V_189 , V_184 ) ;
if ( V_184 < 0x40 ) {
V_183 = false ;
if ( F_100 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_15 ) ;
}
if ( V_184 > V_190 ) {
F_4 ( V_3 -> V_2 , L_16 , V_184 ) ;
}
if ( V_180 . V_189 & ( V_191 | V_192 | V_193 |
V_194 | V_195 |
V_196 | V_197 ) ) {
V_183 = false ;
if ( V_180 . V_189 & V_191 ) {
if ( F_100 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_17 ) ;
V_2 -> V_173 . V_198 ++ ;
}
if ( V_180 . V_189 & V_192 ) {
if ( F_100 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_18 ) ;
V_2 -> V_173 . V_199 ++ ;
}
if ( V_180 . V_189 & V_197 ) {
if ( F_100 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_19 ) ;
V_2 -> V_173 . V_200 ++ ;
}
}
if ( V_183 &&
( ( V_170 = F_101 ( V_2 , V_184 + 4 ) ) != NULL ) ) {
F_102 ( V_170 , 2 ) ;
V_182 = ( T_2 * ) F_103 ( V_170 , V_184 - 4 ) ;
( V_3 -> V_35 ) ( V_3 -> V_7 , V_182 , V_184 ) ;
V_2 -> V_173 . V_201 += V_184 ;
V_170 -> V_202 = F_104 ( V_170 , V_2 ) ;
if ( V_2 -> V_62 & V_64 ) {
if ( ( ( ( V_181 & 0x1c ) << 3 ) & V_181 ) == 0 )
V_170 -> V_159 = V_203 ;
else
F_105 ( V_170 ) ;
}
F_106 ( V_170 ) ;
V_2 -> V_173 . V_204 ++ ;
} else {
( V_3 -> V_33 ) ( V_3 -> V_7 , V_184 ) ;
}
} while ( V_181 & V_187 );
}
static T_7 F_107 ( int V_205 , void * V_206 )
{
struct V_1 * V_2 = V_206 ;
T_1 * V_3 = F_2 ( V_2 ) ;
int V_207 ;
unsigned long V_17 ;
T_2 V_18 ;
F_35 ( V_3 , 3 , L_10 , V_119 ) ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
V_18 = F_8 ( V_3 -> V_5 ) ;
F_9 ( V_3 , V_154 , V_149 ) ;
V_207 = F_7 ( V_3 , V_131 ) ;
F_9 ( V_3 , V_131 , V_207 ) ;
if ( F_108 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_20 , V_207 ) ;
if ( V_207 & V_208 )
F_96 ( V_2 ) ;
if ( V_207 & V_209 )
F_94 ( V_2 , V_3 ) ;
if ( V_3 -> type != V_36 ) {
if ( V_207 & V_210 ) {
F_39 ( & V_3 -> V_37 , 1 ) ;
}
}
F_9 ( V_3 , V_154 , V_3 -> V_153 ) ;
F_5 ( V_18 , V_3 -> V_5 ) ;
F_33 ( & V_3 -> V_21 , V_17 ) ;
return V_211 ;
}
static T_7 F_109 ( int V_205 , void * V_206 )
{
struct V_1 * V_2 = V_206 ;
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_17 ;
unsigned V_92 , V_86 ;
F_32 ( & V_3 -> V_21 , V_17 ) ;
V_92 = F_7 ( V_3 , V_68 ) ;
V_86 = F_7 ( V_3 , V_89 ) ;
F_4 ( V_3 -> V_2 , L_21 , V_119 , V_92 , V_86 ) ;
if ( V_92 & V_145 ) {
F_9 ( V_3 , V_68 , V_145 ) ;
if ( V_86 & V_212 )
F_69 ( V_3 -> V_2 , L_22 ) ;
if ( V_86 & V_213 )
F_69 ( V_3 -> V_2 , L_23 ) ;
if ( V_86 & V_214 )
F_69 ( V_3 -> V_2 , L_24 ) ;
if ( ! ( V_86 & ( V_212 | V_213 | V_214 ) ) )
F_110 ( V_3 -> V_2 , L_25
L_26 , V_92 , V_86 ) ;
}
F_33 ( & V_3 -> V_21 , V_17 ) ;
return ( V_92 & V_145 ) ? V_211 : V_215 ;
}
static void F_111 ( struct V_1 * V_2 )
{
F_112 ( V_2 -> V_205 ) ;
F_107 ( V_2 -> V_205 , V_2 ) ;
F_113 ( V_2 -> V_205 ) ;
}
static int
F_114 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_216 = V_3 -> V_217 -> V_17 & V_218 ;
if ( F_115 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_27 , V_2 -> V_59 ) ;
if ( V_216 == V_219 )
F_97 ( V_3 -> V_2 , L_28 ) ;
V_216 |= V_220 ;
F_9 ( V_3 , V_221 , 0 ) ;
F_28 ( 1 ) ;
F_3 ( V_3 ) ;
F_87 ( V_2 ) ;
if ( F_116 ( V_2 -> V_205 , F_107 , V_216 , V_2 -> V_59 , V_2 ) )
return - V_222 ;
V_3 -> V_223 = 0 ;
F_77 ( & V_3 -> V_44 , F_74 ( V_3 ) , 1 ) ;
F_117 ( V_2 ) ;
F_38 ( V_3 ) ;
return 0 ;
}
static void
F_118 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
F_36 ( V_2 , 0 , V_135 , V_136 ) ;
F_9 ( V_3 , V_221 , 0x01 ) ;
F_9 ( V_3 , V_154 , V_149 ) ;
F_9 ( V_3 , V_128 , 0x00 ) ;
}
static int
F_119 ( struct V_1 * V_93 )
{
T_1 * V_3 = F_2 ( V_93 ) ;
if ( F_120 ( V_3 ) )
F_4 ( V_3 -> V_2 , L_29 , V_93 -> V_59 ) ;
F_121 ( & V_3 -> V_37 ) ;
F_89 ( V_93 ) ;
F_75 ( V_93 ) ;
F_122 ( V_93 -> V_205 , V_93 ) ;
F_118 ( V_93 ) ;
return 0 ;
}
static int
F_123 ( struct V_103 * V_104 )
{
struct V_224 * V_225 = V_104 -> V_2 . V_226 ;
struct V_31 * V_3 ;
struct V_1 * V_93 ;
const unsigned char * V_227 ;
int V_19 = 0 ;
int V_228 ;
int V_12 ;
T_4 V_229 ;
V_93 = F_124 ( sizeof( struct V_31 ) ) ;
if ( ! V_93 )
return - V_230 ;
F_125 ( V_93 , & V_104 -> V_2 ) ;
F_4 ( & V_104 -> V_2 , L_30 ) ;
V_3 = F_2 ( V_93 ) ;
V_3 -> V_2 = & V_104 -> V_2 ;
V_3 -> V_93 = V_93 ;
F_126 ( & V_3 -> V_21 ) ;
F_127 ( & V_3 -> V_20 ) ;
F_128 ( & V_3 -> V_37 , F_70 ) ;
V_3 -> V_231 = F_129 ( V_104 , V_232 , 0 ) ;
V_3 -> V_233 = F_129 ( V_104 , V_232 , 1 ) ;
V_3 -> V_217 = F_129 ( V_104 , V_234 , 0 ) ;
if ( V_3 -> V_231 == NULL || V_3 -> V_233 == NULL ||
V_3 -> V_217 == NULL ) {
F_110 ( V_3 -> V_2 , L_31 ) ;
V_19 = - V_73 ;
goto V_235;
}
V_3 -> V_90 = F_130 ( V_104 , 1 ) ;
if ( V_3 -> V_90 >= 0 ) {
F_4 ( V_3 -> V_2 , L_32 , V_3 -> V_90 ) ;
V_19 = F_116 ( V_3 -> V_90 , F_109 ,
V_220 , F_131 ( V_3 -> V_2 ) , V_93 ) ;
if ( V_19 ) {
F_110 ( V_3 -> V_2 , L_33 , V_19 ) ;
} else {
V_19 = F_67 ( V_3 -> V_90 , 1 ) ;
if ( V_19 ) {
F_110 ( V_3 -> V_2 , L_34 ,
V_3 -> V_90 , V_19 ) ;
V_19 = 0 ;
} else {
F_67 ( V_3 -> V_90 , 0 ) ;
V_3 -> V_81 = 1 ;
}
}
}
V_228 = F_132 ( V_3 -> V_231 ) ;
V_3 -> V_106 = F_133 ( V_3 -> V_231 -> V_236 , V_228 ,
V_104 -> V_59 ) ;
if ( V_3 -> V_106 == NULL ) {
F_110 ( V_3 -> V_2 , L_35 ) ;
V_19 = - V_237 ;
goto V_235;
}
V_3 -> V_5 = F_134 ( V_3 -> V_231 -> V_236 , V_228 ) ;
if ( V_3 -> V_5 == NULL ) {
F_110 ( V_3 -> V_2 , L_36 ) ;
V_19 = - V_43 ;
goto V_235;
}
V_228 = F_132 ( V_3 -> V_233 ) ;
V_3 -> V_105 = F_133 ( V_3 -> V_233 -> V_236 , V_228 ,
V_104 -> V_59 ) ;
if ( V_3 -> V_105 == NULL ) {
F_110 ( V_3 -> V_2 , L_37 ) ;
V_19 = - V_237 ;
goto V_235;
}
V_3 -> V_7 = F_134 ( V_3 -> V_233 -> V_236 , V_228 ) ;
if ( V_3 -> V_7 == NULL ) {
F_110 ( V_3 -> V_2 , L_38 ) ;
V_19 = - V_43 ;
goto V_235;
}
V_93 -> V_238 = ( unsigned long ) V_3 -> V_5 ;
V_93 -> V_205 = V_3 -> V_217 -> V_236 ;
F_37 ( V_3 , V_228 ) ;
if ( V_225 != NULL ) {
if ( V_225 -> V_17 & V_239 )
F_37 ( V_3 , 1 ) ;
if ( V_225 -> V_17 & V_240 )
F_37 ( V_3 , 2 ) ;
if ( V_225 -> V_17 & V_241 )
F_37 ( V_3 , 4 ) ;
if ( V_225 -> V_35 != NULL )
V_3 -> V_35 = V_225 -> V_35 ;
if ( V_225 -> V_34 != NULL )
V_3 -> V_34 = V_225 -> V_34 ;
if ( V_225 -> V_33 != NULL )
V_3 -> V_33 = V_225 -> V_33 ;
V_3 -> V_17 = V_225 -> V_17 ;
}
#ifdef F_135
V_3 -> V_17 |= V_100 ;
#endif
F_9 ( V_3 , V_4 , V_242 | V_6 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_229 = F_7 ( V_3 , V_243 ) ;
V_229 |= ( T_4 ) F_7 ( V_3 , V_244 ) << 8 ;
V_229 |= ( T_4 ) F_7 ( V_3 , V_245 ) << 16 ;
V_229 |= ( T_4 ) F_7 ( V_3 , V_246 ) << 24 ;
if ( V_229 == V_247 )
break;
F_110 ( V_3 -> V_2 , L_39 , V_229 ) ;
}
if ( V_229 != V_247 ) {
F_110 ( V_3 -> V_2 , L_40 , V_229 ) ;
V_19 = - V_248 ;
goto V_235;
}
V_229 = F_7 ( V_3 , V_249 ) ;
F_4 ( V_3 -> V_2 , L_41 , V_229 ) ;
switch ( V_229 ) {
case V_250 :
V_3 -> type = V_108 ;
break;
case V_251 :
V_3 -> type = V_109 ;
break;
default:
F_4 ( V_3 -> V_2 , L_42 , V_229 ) ;
V_3 -> type = V_36 ;
}
if ( V_3 -> type == V_108 || V_3 -> type == V_109 ) {
V_93 -> V_132 = V_64 | V_252 ;
V_93 -> V_62 |= V_93 -> V_132 ;
}
F_136 ( V_93 ) ;
V_93 -> V_253 = & V_254 ;
V_93 -> V_255 = F_137 ( V_256 ) ;
V_93 -> V_257 = & V_258 ;
V_3 -> V_60 = V_259 ;
V_3 -> V_44 . V_260 = 0x1f ;
V_3 -> V_44 . V_261 = 0x1f ;
V_3 -> V_44 . V_262 = 0 ;
V_3 -> V_44 . V_263 = 0 ;
V_3 -> V_44 . V_2 = V_93 ;
V_3 -> V_44 . V_264 = F_30 ;
V_3 -> V_44 . V_265 = F_36 ;
V_227 = L_43 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 += 2 )
F_46 ( V_3 , V_12 / 2 , V_93 -> V_121 + V_12 ) ;
if ( ! F_138 ( V_93 -> V_121 ) && V_225 != NULL ) {
V_227 = L_44 ;
memcpy ( V_93 -> V_121 , V_225 -> V_121 , 6 ) ;
}
if ( ! F_138 ( V_93 -> V_121 ) ) {
V_227 = L_45 ;
for ( V_12 = 0 ; V_12 < 6 ; V_12 ++ )
V_93 -> V_121 [ V_12 ] = F_7 ( V_3 , V_12 + V_120 ) ;
}
if ( ! F_138 ( V_93 -> V_121 ) ) {
F_97 ( V_3 -> V_2 , L_46
L_47 , V_93 -> V_59 ) ;
F_139 ( V_93 ) ;
V_227 = L_48 ;
}
F_140 ( V_104 , V_93 ) ;
V_19 = F_141 ( V_93 ) ;
if ( V_19 == 0 )
F_142 ( V_266 L_49 ,
V_93 -> V_59 , F_82 ( V_3 -> type ) ,
V_3 -> V_5 , V_3 -> V_7 , V_93 -> V_205 ,
V_93 -> V_121 , V_227 ) ;
return 0 ;
V_235:
F_110 ( V_3 -> V_2 , L_50 , V_19 ) ;
F_78 ( V_104 , V_3 ) ;
F_143 ( V_93 ) ;
return V_19 ;
}
static int
F_144 ( struct V_267 * V_2 )
{
struct V_103 * V_104 = F_50 ( V_2 ) ;
struct V_1 * V_93 = F_145 ( V_104 ) ;
T_1 * V_3 ;
if ( V_93 ) {
V_3 = F_2 ( V_93 ) ;
V_3 -> V_15 = 1 ;
if ( ! F_41 ( V_93 ) )
return 0 ;
F_146 ( V_93 ) ;
if ( ! V_3 -> V_84 )
F_118 ( V_93 ) ;
}
return 0 ;
}
static int
F_147 ( struct V_267 * V_2 )
{
struct V_103 * V_104 = F_50 ( V_2 ) ;
struct V_1 * V_93 = F_145 ( V_104 ) ;
T_1 * V_3 = F_2 ( V_93 ) ;
if ( V_93 ) {
if ( F_41 ( V_93 ) ) {
if ( ! V_3 -> V_84 ) {
F_3 ( V_3 ) ;
F_87 ( V_93 ) ;
}
F_148 ( V_93 ) ;
}
V_3 -> V_15 = 0 ;
}
return 0 ;
}
static int
F_149 ( struct V_103 * V_104 )
{
struct V_1 * V_93 = F_145 ( V_104 ) ;
F_140 ( V_104 , NULL ) ;
F_150 ( V_93 ) ;
F_78 ( V_104 , F_2 ( V_93 ) ) ;
F_143 ( V_93 ) ;
F_4 ( & V_104 -> V_2 , L_51 ) ;
return 0 ;
}
static int T_8
F_151 ( void )
{
F_142 ( V_266 L_52 , V_55 , V_57 ) ;
return F_152 ( & V_268 ) ;
}
static void T_9
F_153 ( void )
{
F_154 ( & V_268 ) ;
}
