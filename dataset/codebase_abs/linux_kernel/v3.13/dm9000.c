static inline T_1 * F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ;
}
static T_2
F_3 ( T_1 * V_3 , int V_4 )
{
F_4 ( V_4 , V_3 -> V_5 ) ;
return F_5 ( V_3 -> V_6 ) ;
}
static void
F_6 ( T_1 * V_3 , int V_4 , int V_7 )
{
F_4 ( V_4 , V_3 -> V_5 ) ;
F_4 ( V_7 , V_3 -> V_6 ) ;
}
static void
F_7 ( T_1 * V_3 )
{
F_8 ( V_3 -> V_2 , L_1 ) ;
F_6 ( V_3 , V_8 , 0x03 ) ;
F_9 ( 100 ) ;
if ( F_3 ( V_3 , V_8 ) & 1 )
F_10 ( V_3 -> V_2 , L_2 ) ;
F_6 ( V_3 , V_8 , 0 ) ;
F_6 ( V_3 , V_8 , 0x03 ) ;
F_9 ( 100 ) ;
if ( F_3 ( V_3 , V_8 ) & 1 )
F_10 ( V_3 -> V_2 , L_3 ) ;
}
static void F_11 ( void T_3 * V_4 , void * V_9 , int V_10 )
{
F_12 ( V_4 , V_9 , V_10 ) ;
}
static void F_13 ( void T_3 * V_4 , void * V_9 , int V_10 )
{
F_14 ( V_4 , V_9 , ( V_10 + 1 ) >> 1 ) ;
}
static void F_15 ( void T_3 * V_4 , void * V_9 , int V_10 )
{
F_16 ( V_4 , V_9 , ( V_10 + 3 ) >> 2 ) ;
}
static void F_17 ( void T_3 * V_4 , void * V_9 , int V_10 )
{
F_18 ( V_4 , V_9 , V_10 ) ;
}
static void F_19 ( void T_3 * V_4 , void * V_9 , int V_10 )
{
F_20 ( V_4 , V_9 , ( V_10 + 1 ) >> 1 ) ;
}
static void F_21 ( void T_3 * V_4 , void * V_9 , int V_10 )
{
F_22 ( V_4 , V_9 , ( V_10 + 3 ) >> 2 ) ;
}
static void F_23 ( void T_3 * V_4 , int V_10 )
{
int V_11 ;
int V_12 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
V_12 = F_5 ( V_4 ) ;
}
static void F_24 ( void T_3 * V_4 , int V_10 )
{
int V_11 ;
int V_12 ;
V_10 = ( V_10 + 1 ) >> 1 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
V_12 = F_25 ( V_4 ) ;
}
static void F_26 ( void T_3 * V_4 , int V_10 )
{
int V_11 ;
int V_12 ;
V_10 = ( V_10 + 3 ) >> 2 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
V_12 = F_27 ( V_4 ) ;
}
static void F_28 ( T_1 * V_3 , unsigned int V_13 )
{
if ( V_3 -> V_14 )
F_29 ( V_13 ) ;
else
F_30 ( V_13 ) ;
}
static int
F_31 ( struct V_1 * V_2 , int V_15 , int V_4 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_16 ;
unsigned int V_17 ;
int V_18 ;
F_32 ( & V_3 -> V_19 ) ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
V_17 = F_5 ( V_3 -> V_5 ) ;
F_6 ( V_3 , V_21 , V_22 | V_4 ) ;
F_6 ( V_3 , V_23 , V_24 | V_25 ) ;
F_4 ( V_17 , V_3 -> V_5 ) ;
F_34 ( & V_3 -> V_20 , V_16 ) ;
F_28 ( V_3 , 1 ) ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
V_17 = F_5 ( V_3 -> V_5 ) ;
F_6 ( V_3 , V_23 , 0x0 ) ;
V_18 = ( F_3 ( V_3 , V_26 ) << 8 ) | F_3 ( V_3 , V_27 ) ;
F_4 ( V_17 , V_3 -> V_5 ) ;
F_34 ( & V_3 -> V_20 , V_16 ) ;
F_35 ( & V_3 -> V_19 ) ;
F_36 ( V_3 , 5 , L_4 , V_4 , V_18 ) ;
return V_18 ;
}
static void
F_37 ( struct V_1 * V_2 ,
int V_28 , int V_4 , int V_7 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_16 ;
unsigned long V_17 ;
F_36 ( V_3 , 5 , L_5 , V_4 , V_7 ) ;
F_32 ( & V_3 -> V_19 ) ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
V_17 = F_5 ( V_3 -> V_5 ) ;
F_6 ( V_3 , V_21 , V_22 | V_4 ) ;
F_6 ( V_3 , V_27 , V_7 ) ;
F_6 ( V_3 , V_26 , V_7 >> 8 ) ;
F_6 ( V_3 , V_23 , V_25 | V_29 ) ;
F_4 ( V_17 , V_3 -> V_5 ) ;
F_34 ( & V_3 -> V_20 , V_16 ) ;
F_28 ( V_3 , 1 ) ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
V_17 = F_5 ( V_3 -> V_5 ) ;
F_6 ( V_3 , V_23 , 0x0 ) ;
F_4 ( V_17 , V_3 -> V_5 ) ;
F_34 ( & V_3 -> V_20 , V_16 ) ;
F_35 ( & V_3 -> V_19 ) ;
}
static void F_38 ( struct V_30 * V_3 , int V_31 )
{
switch ( V_31 ) {
case 1 :
V_3 -> V_32 = F_23 ;
V_3 -> V_33 = F_11 ;
V_3 -> V_34 = F_17 ;
break;
case 3 :
F_8 ( V_3 -> V_2 , L_6 ) ;
case 2 :
V_3 -> V_32 = F_24 ;
V_3 -> V_33 = F_13 ;
V_3 -> V_34 = F_19 ;
break;
case 4 :
default:
V_3 -> V_32 = F_26 ;
V_3 -> V_33 = F_15 ;
V_3 -> V_34 = F_21 ;
break;
}
}
static void F_39 ( T_1 * V_3 )
{
if ( V_3 -> type == V_35 )
F_40 ( & V_3 -> V_36 , V_37 * 2 ) ;
}
static int F_41 ( struct V_1 * V_2 , struct V_38 * V_39 , int V_40 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
if ( ! F_42 ( V_2 ) )
return - V_42 ;
return F_43 ( & V_41 -> V_43 , F_44 ( V_39 ) , V_40 , NULL ) ;
}
static unsigned int
F_45 ( T_1 * V_3 , int V_4 )
{
unsigned long V_16 ;
unsigned int V_18 ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
V_18 = F_3 ( V_3 , V_4 ) ;
F_34 ( & V_3 -> V_20 , V_16 ) ;
return V_18 ;
}
static int F_46 ( T_1 * V_3 )
{
unsigned int V_44 ;
int V_45 = 8 ;
while ( 1 ) {
V_44 = F_45 ( V_3 , V_23 ) ;
if ( ( V_44 & V_46 ) == 0 )
break;
F_30 ( 1 ) ;
if ( V_45 -- < 0 ) {
F_8 ( V_3 -> V_2 , L_7 ) ;
break;
}
}
return 0 ;
}
static void
F_47 ( T_1 * V_3 , int V_47 , T_2 * V_48 )
{
unsigned long V_16 ;
if ( V_3 -> V_16 & V_49 ) {
V_48 [ 0 ] = 0xff ;
V_48 [ 1 ] = 0xff ;
return;
}
F_32 ( & V_3 -> V_19 ) ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
F_6 ( V_3 , V_21 , V_47 ) ;
F_6 ( V_3 , V_23 , V_24 ) ;
F_34 ( & V_3 -> V_20 , V_16 ) ;
F_46 ( V_3 ) ;
F_30 ( 1 ) ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
F_6 ( V_3 , V_23 , 0x0 ) ;
V_48 [ 0 ] = F_3 ( V_3 , V_27 ) ;
V_48 [ 1 ] = F_3 ( V_3 , V_26 ) ;
F_34 ( & V_3 -> V_20 , V_16 ) ;
F_35 ( & V_3 -> V_19 ) ;
}
static void
F_48 ( T_1 * V_3 , int V_47 , T_2 * V_9 )
{
unsigned long V_16 ;
if ( V_3 -> V_16 & V_49 )
return;
F_32 ( & V_3 -> V_19 ) ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
F_6 ( V_3 , V_21 , V_47 ) ;
F_6 ( V_3 , V_26 , V_9 [ 1 ] ) ;
F_6 ( V_3 , V_27 , V_9 [ 0 ] ) ;
F_6 ( V_3 , V_23 , V_50 | V_29 ) ;
F_34 ( & V_3 -> V_20 , V_16 ) ;
F_46 ( V_3 ) ;
F_29 ( 1 ) ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
F_6 ( V_3 , V_23 , 0 ) ;
F_34 ( & V_3 -> V_20 , V_16 ) ;
F_35 ( & V_3 -> V_19 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
F_50 ( V_52 -> V_53 , V_54 , sizeof( V_52 -> V_53 ) ) ;
F_50 ( V_52 -> V_55 , V_56 , sizeof( V_52 -> V_55 ) ) ;
F_50 ( V_52 -> V_57 , F_51 ( V_41 -> V_2 ) -> V_58 ,
sizeof( V_52 -> V_57 ) ) ;
}
static T_4 F_52 ( struct V_1 * V_2 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
return V_41 -> V_59 ;
}
static void F_53 ( struct V_1 * V_2 , T_4 V_7 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
V_41 -> V_59 = V_7 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_60 * V_40 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
F_55 ( & V_41 -> V_43 , V_40 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_60 * V_40 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
return F_57 ( & V_41 -> V_43 , V_40 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
return F_59 ( & V_41 -> V_43 ) ;
}
static int F_60 ( struct V_1 * V_2 ,
T_5 V_61 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
T_5 V_62 = V_2 -> V_61 ^ V_61 ;
unsigned long V_16 ;
if ( ! ( V_62 & V_63 ) )
return 0 ;
F_33 ( & V_41 -> V_20 , V_16 ) ;
F_6 ( V_41 , V_64 , ( V_61 & V_63 ) ? V_65 : 0 ) ;
F_34 ( & V_41 -> V_20 , V_16 ) ;
return 0 ;
}
static T_4 F_61 ( struct V_1 * V_2 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
T_4 V_18 ;
if ( V_41 -> V_16 & V_66 )
V_18 = F_62 ( & V_41 -> V_43 ) ;
else
V_18 = F_45 ( V_41 , V_67 ) & V_68 ? 1 : 0 ;
return V_18 ;
}
static int F_63 ( struct V_1 * V_2 )
{
return 128 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_69 * V_70 , T_2 * V_9 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
int V_47 = V_70 -> V_47 ;
int V_71 = V_70 -> V_71 ;
int V_11 ;
if ( ( V_71 & 1 ) != 0 || ( V_47 & 1 ) != 0 )
return - V_42 ;
if ( V_41 -> V_16 & V_49 )
return - V_72 ;
V_70 -> V_73 = V_74 ;
for ( V_11 = 0 ; V_11 < V_71 ; V_11 += 2 )
F_47 ( V_41 , ( V_47 + V_11 ) / 2 , V_9 + V_11 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_69 * V_70 , T_2 * V_9 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
int V_47 = V_70 -> V_47 ;
int V_71 = V_70 -> V_71 ;
int V_75 ;
if ( V_41 -> V_16 & V_49 )
return - V_72 ;
if ( V_70 -> V_73 != V_74 )
return - V_42 ;
while ( V_71 > 0 ) {
if ( V_71 & 1 || V_47 & 1 ) {
int V_76 = V_47 & 1 ;
T_2 V_12 [ 2 ] ;
F_47 ( V_41 , V_47 / 2 , V_12 ) ;
V_12 [ V_76 ] = * V_9 ;
F_48 ( V_41 , V_47 / 2 , V_12 ) ;
V_75 = 1 ;
} else {
F_48 ( V_41 , V_47 / 2 , V_9 ) ;
V_75 = 2 ;
}
V_9 += V_75 ;
V_47 += V_75 ;
V_71 -= V_75 ;
}
return 0 ;
}
static void F_66 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
memset ( V_78 , 0 , sizeof( struct V_77 ) ) ;
V_78 -> V_79 = V_41 -> V_80 ? V_81 : 0 ;
V_78 -> V_82 = V_41 -> V_83 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_77 * V_78 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
unsigned long V_16 ;
T_4 V_84 = V_78 -> V_82 ;
T_4 V_85 = 0 ;
if ( ! V_41 -> V_80 )
return - V_86 ;
if ( V_84 & ~ V_81 )
return - V_42 ;
if ( V_84 & V_81 )
V_85 |= V_87 ;
F_32 ( & V_41 -> V_19 ) ;
F_33 ( & V_41 -> V_20 , V_16 ) ;
F_6 ( V_41 , V_88 , V_85 ) ;
F_34 ( & V_41 -> V_20 , V_16 ) ;
F_35 ( & V_41 -> V_19 ) ;
if ( V_41 -> V_83 != V_84 ) {
if ( ! V_41 -> V_83 )
F_68 ( V_41 -> V_89 , 1 ) ;
else if ( V_41 -> V_83 && ! V_84 )
F_68 ( V_41 -> V_89 , 0 ) ;
}
V_41 -> V_83 = V_84 ;
return 0 ;
}
static void F_69 ( T_1 * V_3 ,
unsigned V_90 , unsigned V_91 )
{
int V_92 ;
struct V_1 * V_93 = V_3 -> V_93 ;
struct V_94 * V_43 = & V_3 -> V_43 ;
unsigned V_95 = F_45 ( V_3 , V_8 ) ;
if ( V_90 ) {
V_92 = V_43 -> V_96 ( V_43 -> V_2 , V_43 -> V_97 , V_98 ) ;
F_70 ( V_3 -> V_2 ,
L_8 ,
V_93 -> V_58 , ( V_91 & V_99 ) ? 10 : 100 ,
( V_95 & V_100 ) ? L_9 : L_10 , V_92 ) ;
} else {
F_70 ( V_3 -> V_2 , L_11 , V_93 -> V_58 ) ;
}
}
static void
F_71 ( struct V_101 * V_78 )
{
struct V_102 * V_103 = F_72 ( V_78 ) ;
T_1 * V_3 = F_73 ( V_103 , T_1 , V_36 ) ;
struct V_1 * V_93 = V_3 -> V_93 ;
if ( V_3 -> V_16 & V_104 &&
! ( V_3 -> V_16 & V_66 ) ) {
unsigned V_91 = F_45 ( V_3 , V_67 ) ;
unsigned V_105 = F_74 ( V_93 ) ? 1 : 0 ;
unsigned V_106 ;
V_106 = ( V_91 & V_68 ) ? 1 : 0 ;
if ( V_105 != V_106 ) {
if ( F_75 ( V_3 ) )
F_69 ( V_3 , V_106 , V_91 ) ;
if ( ! V_106 )
F_76 ( V_93 ) ;
else
F_77 ( V_93 ) ;
}
} else
F_78 ( & V_3 -> V_43 , F_75 ( V_3 ) , 0 ) ;
if ( F_42 ( V_93 ) )
F_39 ( V_3 ) ;
}
static void
F_79 ( struct V_107 * V_108 , struct V_30 * V_3 )
{
F_80 ( V_3 -> V_5 ) ;
F_80 ( V_3 -> V_6 ) ;
F_81 ( V_3 -> V_109 ) ;
F_82 ( V_3 -> V_109 ) ;
F_81 ( V_3 -> V_110 ) ;
F_82 ( V_3 -> V_110 ) ;
}
static unsigned char F_83 ( enum V_111 type )
{
switch ( type ) {
case V_35 : return 'e' ;
case V_112 : return 'a' ;
case V_113 : return 'b' ;
}
return '?' ;
}
static void
F_84 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
struct V_114 * V_115 ;
int V_11 , V_116 ;
T_4 V_117 ;
T_6 V_118 [ 4 ] = { 0 , 0 , 0 , 0x8000 } ;
T_2 V_119 = V_120 | V_121 | V_122 ;
F_36 ( V_3 , 1 , L_12 , V_123 ) ;
for ( V_11 = 0 , V_116 = V_124 ; V_11 < 6 ; V_11 ++ , V_116 ++ )
F_6 ( V_3 , V_116 , V_2 -> V_125 [ V_11 ] ) ;
if ( V_2 -> V_16 & V_126 )
V_119 |= V_127 ;
if ( V_2 -> V_16 & V_128 )
V_119 |= V_129 ;
F_85 (ha, dev) {
V_117 = F_86 ( 6 , V_115 -> V_130 ) & 0x3f ;
V_118 [ V_117 / 16 ] |= ( T_6 ) 1 << ( V_117 % 16 ) ;
}
for ( V_11 = 0 , V_116 = V_131 ; V_11 < 4 ; V_11 ++ ) {
F_6 ( V_3 , V_116 ++ , V_118 [ V_11 ] ) ;
F_6 ( V_3 , V_116 ++ , V_118 [ V_11 ] >> 8 ) ;
}
F_6 ( V_3 , V_132 , V_119 ) ;
}
static void
F_87 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_16 ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
F_84 ( V_2 ) ;
F_34 ( & V_3 -> V_20 , V_16 ) ;
}
static void
F_88 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned int V_133 ;
unsigned int V_95 ;
F_36 ( V_3 , 1 , L_12 , V_123 ) ;
V_3 -> V_134 = F_3 ( V_3 , V_135 ) >> 6 ;
if ( V_2 -> V_136 & V_63 )
F_6 ( V_3 , V_64 ,
( V_2 -> V_61 & V_63 ) ? V_65 : 0 ) ;
F_6 ( V_3 , V_137 , V_138 ) ;
F_6 ( V_3 , V_139 , 0 ) ;
if ( V_3 -> type == V_113 ) {
F_37 ( V_2 , 0 , V_140 , V_141 ) ;
F_37 ( V_2 , 0 , V_142 , V_143 ) ;
}
V_95 = ( V_3 -> V_16 & V_66 ) ? V_144 : 0 ;
if ( V_3 -> V_80 )
V_95 |= V_145 ;
F_6 ( V_3 , V_8 , V_95 ) ;
F_6 ( V_3 , V_146 , 0 ) ;
F_6 ( V_3 , V_147 , 0x3f ) ;
F_6 ( V_3 , V_148 , 0xff ) ;
F_6 ( V_3 , V_149 , 0 ) ;
F_6 ( V_3 , V_67 , V_150 | V_151 | V_152 ) ;
F_6 ( V_3 , V_135 , V_153 ) ;
F_84 ( V_2 ) ;
V_133 = V_154 | V_155 | V_156 ;
if ( V_3 -> type != V_35 )
V_133 |= V_157 ;
V_3 -> V_158 = V_133 ;
F_6 ( V_3 , V_159 , V_133 ) ;
V_3 -> V_160 = 0 ;
V_3 -> V_161 = 0 ;
V_2 -> V_162 = V_163 ;
}
static void F_89 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
T_2 V_17 ;
unsigned long V_16 ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
V_17 = F_5 ( V_3 -> V_5 ) ;
F_90 ( V_2 ) ;
F_7 ( V_3 ) ;
F_88 ( V_2 ) ;
V_2 -> V_162 = V_163 ;
F_91 ( V_2 ) ;
F_4 ( V_17 , V_3 -> V_5 ) ;
F_34 ( & V_3 -> V_20 , V_16 ) ;
}
static void F_92 ( struct V_1 * V_2 ,
int V_164 ,
T_6 V_165 )
{
T_1 * V_41 = F_1 ( V_2 ) ;
if ( V_41 -> V_164 != V_164 ) {
if ( V_164 == V_166 )
F_6 ( V_41 , V_167 , 0 ) ;
else
F_6 ( V_41 , V_167 , V_168 | V_169 | V_170 ) ;
V_41 -> V_164 = V_164 ;
}
F_6 ( V_41 , V_171 , V_165 ) ;
F_6 ( V_41 , V_172 , V_165 >> 8 ) ;
F_6 ( V_41 , V_146 , V_173 ) ;
}
static int
F_93 ( struct V_174 * V_175 , struct V_1 * V_2 )
{
unsigned long V_16 ;
T_1 * V_3 = F_2 ( V_2 ) ;
F_36 ( V_3 , 3 , L_13 , V_123 ) ;
if ( V_3 -> V_160 > 1 )
return V_176 ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
F_4 ( V_177 , V_3 -> V_5 ) ;
( V_3 -> V_33 ) ( V_3 -> V_6 , V_175 -> V_9 , V_175 -> V_71 ) ;
V_2 -> V_178 . V_179 += V_175 -> V_71 ;
V_3 -> V_160 ++ ;
if ( V_3 -> V_160 == 1 ) {
F_92 ( V_2 , V_175 -> V_164 , V_175 -> V_71 ) ;
} else {
V_3 -> V_161 = V_175 -> V_71 ;
V_3 -> V_180 = V_175 -> V_164 ;
F_90 ( V_2 ) ;
}
F_34 ( & V_3 -> V_20 , V_16 ) ;
F_94 ( V_175 ) ;
return V_181 ;
}
static void F_95 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_182 = F_3 ( V_3 , V_67 ) ;
if ( V_182 & ( V_151 | V_152 ) ) {
V_3 -> V_160 -- ;
V_2 -> V_178 . V_183 ++ ;
if ( F_96 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_14 , V_182 ) ;
if ( V_3 -> V_160 > 0 )
F_92 ( V_2 , V_3 -> V_180 ,
V_3 -> V_161 ) ;
F_91 ( V_2 ) ;
}
}
static void
F_97 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
struct V_184 V_185 ;
struct V_174 * V_175 ;
T_2 V_186 , * V_187 ;
bool V_188 ;
int V_189 ;
do {
F_3 ( V_3 , V_190 ) ;
V_186 = F_5 ( V_3 -> V_6 ) ;
if ( V_186 & V_191 ) {
F_98 ( V_3 -> V_2 , L_15 , V_186 ) ;
F_6 ( V_3 , V_132 , 0x00 ) ;
F_6 ( V_3 , V_135 , V_154 ) ;
return;
}
if ( ! ( V_186 & V_192 ) )
return;
V_188 = true ;
F_4 ( V_193 , V_3 -> V_5 ) ;
( V_3 -> V_34 ) ( V_3 -> V_6 , & V_185 , sizeof( V_185 ) ) ;
V_189 = F_99 ( V_185 . V_189 ) ;
if ( F_100 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_16 ,
V_185 . V_194 , V_189 ) ;
if ( V_189 < 0x40 ) {
V_188 = false ;
if ( F_101 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_17 ) ;
}
if ( V_189 > V_195 ) {
F_8 ( V_3 -> V_2 , L_18 , V_189 ) ;
}
if ( V_185 . V_194 & ( V_196 | V_197 | V_198 |
V_199 | V_200 |
V_201 | V_202 ) ) {
V_188 = false ;
if ( V_185 . V_194 & V_196 ) {
if ( F_101 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_19 ) ;
V_2 -> V_178 . V_203 ++ ;
}
if ( V_185 . V_194 & V_197 ) {
if ( F_101 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_20 ) ;
V_2 -> V_178 . V_204 ++ ;
}
if ( V_185 . V_194 & V_202 ) {
if ( F_101 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_21 ) ;
V_2 -> V_178 . V_205 ++ ;
}
}
if ( V_188 &&
( ( V_175 = F_102 ( V_2 , V_189 + 4 ) ) != NULL ) ) {
F_103 ( V_175 , 2 ) ;
V_187 = ( T_2 * ) F_104 ( V_175 , V_189 - 4 ) ;
( V_3 -> V_34 ) ( V_3 -> V_6 , V_187 , V_189 ) ;
V_2 -> V_178 . V_206 += V_189 ;
V_175 -> V_207 = F_105 ( V_175 , V_2 ) ;
if ( V_2 -> V_61 & V_63 ) {
if ( ( ( ( V_186 & 0x1c ) << 3 ) & V_186 ) == 0 )
V_175 -> V_164 = V_208 ;
else
F_106 ( V_175 ) ;
}
F_107 ( V_175 ) ;
V_2 -> V_178 . V_209 ++ ;
} else {
( V_3 -> V_32 ) ( V_3 -> V_6 , V_189 ) ;
}
} while ( V_186 & V_192 );
}
static T_7 F_108 ( int V_210 , void * V_211 )
{
struct V_1 * V_2 = V_211 ;
T_1 * V_3 = F_2 ( V_2 ) ;
int V_212 ;
unsigned long V_16 ;
T_2 V_17 ;
F_36 ( V_3 , 3 , L_12 , V_123 ) ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
V_17 = F_5 ( V_3 -> V_5 ) ;
F_6 ( V_3 , V_159 , V_154 ) ;
V_212 = F_3 ( V_3 , V_135 ) ;
F_6 ( V_3 , V_135 , V_212 ) ;
if ( F_109 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_22 , V_212 ) ;
if ( V_212 & V_213 )
F_97 ( V_2 ) ;
if ( V_212 & V_214 )
F_95 ( V_2 , V_3 ) ;
if ( V_3 -> type != V_35 ) {
if ( V_212 & V_215 ) {
F_40 ( & V_3 -> V_36 , 1 ) ;
}
}
F_6 ( V_3 , V_159 , V_3 -> V_158 ) ;
F_4 ( V_17 , V_3 -> V_5 ) ;
F_34 ( & V_3 -> V_20 , V_16 ) ;
return V_216 ;
}
static T_7 F_110 ( int V_210 , void * V_211 )
{
struct V_1 * V_2 = V_211 ;
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_16 ;
unsigned V_91 , V_85 ;
F_33 ( & V_3 -> V_20 , V_16 ) ;
V_91 = F_3 ( V_3 , V_67 ) ;
V_85 = F_3 ( V_3 , V_88 ) ;
F_8 ( V_3 -> V_2 , L_23 , V_123 , V_91 , V_85 ) ;
if ( V_91 & V_150 ) {
F_6 ( V_3 , V_67 , V_150 ) ;
if ( V_85 & V_217 )
F_70 ( V_3 -> V_2 , L_24 ) ;
if ( V_85 & V_218 )
F_70 ( V_3 -> V_2 , L_25 ) ;
if ( V_85 & V_219 )
F_70 ( V_3 -> V_2 , L_26 ) ;
if ( ! ( V_85 & ( V_217 | V_218 | V_219 ) ) )
F_10 ( V_3 -> V_2 , L_27
L_28 , V_91 , V_85 ) ;
}
F_34 ( & V_3 -> V_20 , V_16 ) ;
return ( V_91 & V_150 ) ? V_216 : V_220 ;
}
static void F_111 ( struct V_1 * V_2 )
{
F_112 ( V_2 -> V_210 ) ;
F_108 ( V_2 -> V_210 , V_2 ) ;
F_113 ( V_2 -> V_210 ) ;
}
static int
F_114 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_221 = V_3 -> V_222 -> V_16 & V_223 ;
if ( F_115 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_29 , V_2 -> V_58 ) ;
if ( V_221 == V_224 )
F_98 ( V_3 -> V_2 , L_30 ) ;
V_221 |= V_225 ;
F_6 ( V_3 , V_139 , 0 ) ;
F_29 ( 1 ) ;
F_7 ( V_3 ) ;
F_88 ( V_2 ) ;
if ( F_116 ( V_2 -> V_210 , F_108 , V_221 , V_2 -> V_58 , V_2 ) )
return - V_226 ;
V_3 -> V_227 = 0 ;
F_78 ( & V_3 -> V_43 , F_75 ( V_3 ) , 1 ) ;
F_117 ( V_2 ) ;
F_39 ( V_3 ) ;
return 0 ;
}
static void
F_118 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
F_37 ( V_2 , 0 , V_140 , V_141 ) ;
F_6 ( V_3 , V_139 , 0x01 ) ;
F_6 ( V_3 , V_159 , V_154 ) ;
F_6 ( V_3 , V_132 , 0x00 ) ;
}
static int
F_119 ( struct V_1 * V_93 )
{
T_1 * V_3 = F_2 ( V_93 ) ;
if ( F_120 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_31 , V_93 -> V_58 ) ;
F_121 ( & V_3 -> V_36 ) ;
F_90 ( V_93 ) ;
F_76 ( V_93 ) ;
F_122 ( V_93 -> V_210 , V_93 ) ;
F_118 ( V_93 ) ;
return 0 ;
}
static struct V_228 * F_123 ( struct V_229 * V_2 )
{
struct V_228 * V_230 ;
struct V_231 * V_232 = V_2 -> V_233 ;
const void * V_234 ;
if ( ! F_124 ( V_235 ) || ! V_232 )
return NULL ;
V_230 = F_125 ( V_2 , sizeof( * V_230 ) , V_236 ) ;
if ( ! V_230 )
return F_126 ( - V_237 ) ;
if ( F_127 ( V_232 , L_32 , NULL ) )
V_230 -> V_16 |= V_66 ;
if ( F_127 ( V_232 , L_33 , NULL ) )
V_230 -> V_16 |= V_49 ;
V_234 = F_128 ( V_232 ) ;
if ( V_234 )
memcpy ( V_230 -> V_125 , V_234 , sizeof( V_230 -> V_125 ) ) ;
return V_230 ;
}
static int
F_129 ( struct V_107 * V_108 )
{
struct V_228 * V_230 = F_130 ( & V_108 -> V_2 ) ;
struct V_30 * V_3 ;
struct V_1 * V_93 ;
const unsigned char * V_238 ;
int V_18 = 0 ;
int V_239 ;
int V_11 ;
T_4 V_240 ;
if ( ! V_230 ) {
V_230 = F_123 ( & V_108 -> V_2 ) ;
if ( F_131 ( V_230 ) )
return F_132 ( V_230 ) ;
}
V_93 = F_133 ( sizeof( struct V_30 ) ) ;
if ( ! V_93 )
return - V_237 ;
F_134 ( V_93 , & V_108 -> V_2 ) ;
F_8 ( & V_108 -> V_2 , L_34 ) ;
V_3 = F_2 ( V_93 ) ;
V_3 -> V_2 = & V_108 -> V_2 ;
V_3 -> V_93 = V_93 ;
F_135 ( & V_3 -> V_20 ) ;
F_136 ( & V_3 -> V_19 ) ;
F_137 ( & V_3 -> V_36 , F_71 ) ;
V_3 -> V_241 = F_138 ( V_108 , V_242 , 0 ) ;
V_3 -> V_243 = F_138 ( V_108 , V_242 , 1 ) ;
V_3 -> V_222 = F_138 ( V_108 , V_244 , 0 ) ;
if ( V_3 -> V_241 == NULL || V_3 -> V_243 == NULL ||
V_3 -> V_222 == NULL ) {
F_10 ( V_3 -> V_2 , L_35 ) ;
V_18 = - V_72 ;
goto V_245;
}
V_3 -> V_89 = F_139 ( V_108 , 1 ) ;
if ( V_3 -> V_89 >= 0 ) {
F_8 ( V_3 -> V_2 , L_36 , V_3 -> V_89 ) ;
V_18 = F_116 ( V_3 -> V_89 , F_110 ,
V_225 , F_140 ( V_3 -> V_2 ) , V_93 ) ;
if ( V_18 ) {
F_10 ( V_3 -> V_2 , L_37 , V_18 ) ;
} else {
V_18 = F_68 ( V_3 -> V_89 , 1 ) ;
if ( V_18 ) {
F_10 ( V_3 -> V_2 , L_38 ,
V_3 -> V_89 , V_18 ) ;
V_18 = 0 ;
} else {
F_68 ( V_3 -> V_89 , 0 ) ;
V_3 -> V_80 = 1 ;
}
}
}
V_239 = F_141 ( V_3 -> V_241 ) ;
V_3 -> V_110 = F_142 ( V_3 -> V_241 -> V_246 , V_239 ,
V_108 -> V_58 ) ;
if ( V_3 -> V_110 == NULL ) {
F_10 ( V_3 -> V_2 , L_39 ) ;
V_18 = - V_247 ;
goto V_245;
}
V_3 -> V_5 = F_143 ( V_3 -> V_241 -> V_246 , V_239 ) ;
if ( V_3 -> V_5 == NULL ) {
F_10 ( V_3 -> V_2 , L_40 ) ;
V_18 = - V_42 ;
goto V_245;
}
V_239 = F_141 ( V_3 -> V_243 ) ;
V_3 -> V_109 = F_142 ( V_3 -> V_243 -> V_246 , V_239 ,
V_108 -> V_58 ) ;
if ( V_3 -> V_109 == NULL ) {
F_10 ( V_3 -> V_2 , L_41 ) ;
V_18 = - V_247 ;
goto V_245;
}
V_3 -> V_6 = F_143 ( V_3 -> V_243 -> V_246 , V_239 ) ;
if ( V_3 -> V_6 == NULL ) {
F_10 ( V_3 -> V_2 , L_42 ) ;
V_18 = - V_42 ;
goto V_245;
}
V_93 -> V_248 = ( unsigned long ) V_3 -> V_5 ;
V_93 -> V_210 = V_3 -> V_222 -> V_246 ;
F_38 ( V_3 , V_239 ) ;
if ( V_230 != NULL ) {
if ( V_230 -> V_16 & V_249 )
F_38 ( V_3 , 1 ) ;
if ( V_230 -> V_16 & V_250 )
F_38 ( V_3 , 2 ) ;
if ( V_230 -> V_16 & V_251 )
F_38 ( V_3 , 4 ) ;
if ( V_230 -> V_34 != NULL )
V_3 -> V_34 = V_230 -> V_34 ;
if ( V_230 -> V_33 != NULL )
V_3 -> V_33 = V_230 -> V_33 ;
if ( V_230 -> V_32 != NULL )
V_3 -> V_32 = V_230 -> V_32 ;
V_3 -> V_16 = V_230 -> V_16 ;
}
#ifdef F_144
V_3 -> V_16 |= V_104 ;
#endif
F_6 ( V_3 , V_8 , V_252 | V_253 ) ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_240 = F_3 ( V_3 , V_254 ) ;
V_240 |= ( T_4 ) F_3 ( V_3 , V_255 ) << 8 ;
V_240 |= ( T_4 ) F_3 ( V_3 , V_256 ) << 16 ;
V_240 |= ( T_4 ) F_3 ( V_3 , V_257 ) << 24 ;
if ( V_240 == V_258 )
break;
F_10 ( V_3 -> V_2 , L_43 , V_240 ) ;
}
if ( V_240 != V_258 ) {
F_10 ( V_3 -> V_2 , L_44 , V_240 ) ;
V_18 = - V_259 ;
goto V_245;
}
V_240 = F_3 ( V_3 , V_260 ) ;
F_8 ( V_3 -> V_2 , L_45 , V_240 ) ;
switch ( V_240 ) {
case V_261 :
V_3 -> type = V_112 ;
break;
case V_262 :
V_3 -> type = V_113 ;
break;
default:
F_8 ( V_3 -> V_2 , L_46 , V_240 ) ;
V_3 -> type = V_35 ;
}
if ( V_3 -> type == V_112 || V_3 -> type == V_113 ) {
V_93 -> V_136 = V_63 | V_263 ;
V_93 -> V_61 |= V_93 -> V_136 ;
}
F_145 ( V_93 ) ;
V_93 -> V_264 = & V_265 ;
V_93 -> V_266 = F_146 ( V_267 ) ;
V_93 -> V_268 = & V_269 ;
V_3 -> V_59 = V_270 ;
V_3 -> V_43 . V_271 = 0x1f ;
V_3 -> V_43 . V_272 = 0x1f ;
V_3 -> V_43 . V_273 = 0 ;
V_3 -> V_43 . V_274 = 0 ;
V_3 -> V_43 . V_2 = V_93 ;
V_3 -> V_43 . V_96 = F_31 ;
V_3 -> V_43 . V_275 = F_37 ;
V_238 = L_47 ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 += 2 )
F_47 ( V_3 , V_11 / 2 , V_93 -> V_125 + V_11 ) ;
if ( ! F_147 ( V_93 -> V_125 ) && V_230 != NULL ) {
V_238 = L_48 ;
memcpy ( V_93 -> V_125 , V_230 -> V_125 , V_276 ) ;
}
if ( ! F_147 ( V_93 -> V_125 ) ) {
V_238 = L_49 ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ )
V_93 -> V_125 [ V_11 ] = F_3 ( V_3 , V_11 + V_124 ) ;
}
if ( ! F_147 ( V_93 -> V_125 ) ) {
F_98 ( V_3 -> V_2 , L_50
L_51 , V_93 -> V_58 ) ;
F_148 ( V_93 ) ;
V_238 = L_52 ;
}
F_149 ( V_108 , V_93 ) ;
V_18 = F_150 ( V_93 ) ;
if ( V_18 == 0 )
F_151 ( V_277 L_53 ,
V_93 -> V_58 , F_83 ( V_3 -> type ) ,
V_3 -> V_5 , V_3 -> V_6 , V_93 -> V_210 ,
V_93 -> V_125 , V_238 ) ;
return 0 ;
V_245:
F_10 ( V_3 -> V_2 , L_54 , V_18 ) ;
F_79 ( V_108 , V_3 ) ;
F_152 ( V_93 ) ;
return V_18 ;
}
static int
F_153 ( struct V_229 * V_2 )
{
struct V_107 * V_108 = F_51 ( V_2 ) ;
struct V_1 * V_93 = F_154 ( V_108 ) ;
T_1 * V_3 ;
if ( V_93 ) {
V_3 = F_2 ( V_93 ) ;
V_3 -> V_14 = 1 ;
if ( ! F_42 ( V_93 ) )
return 0 ;
F_155 ( V_93 ) ;
if ( ! V_3 -> V_83 )
F_118 ( V_93 ) ;
}
return 0 ;
}
static int
F_156 ( struct V_229 * V_2 )
{
struct V_107 * V_108 = F_51 ( V_2 ) ;
struct V_1 * V_93 = F_154 ( V_108 ) ;
T_1 * V_3 = F_2 ( V_93 ) ;
if ( V_93 ) {
if ( F_42 ( V_93 ) ) {
if ( ! V_3 -> V_83 ) {
F_7 ( V_3 ) ;
F_88 ( V_93 ) ;
}
F_157 ( V_93 ) ;
}
V_3 -> V_14 = 0 ;
}
return 0 ;
}
static int
F_158 ( struct V_107 * V_108 )
{
struct V_1 * V_93 = F_154 ( V_108 ) ;
F_159 ( V_93 ) ;
F_79 ( V_108 , F_2 ( V_93 ) ) ;
F_152 ( V_93 ) ;
F_8 ( & V_108 -> V_2 , L_55 ) ;
return 0 ;
}
