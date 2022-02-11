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
F_6 ( V_3 , V_8 , V_9 | V_10 ) ;
F_9 ( 100 ) ;
if ( F_3 ( V_3 , V_8 ) & 1 )
F_10 ( V_3 -> V_2 , L_2 ) ;
F_6 ( V_3 , V_8 , 0 ) ;
F_6 ( V_3 , V_8 , V_9 | V_10 ) ;
F_9 ( 100 ) ;
if ( F_3 ( V_3 , V_8 ) & 1 )
F_10 ( V_3 -> V_2 , L_3 ) ;
}
static void F_11 ( void T_3 * V_4 , void * V_11 , int V_12 )
{
F_12 ( V_4 , V_11 , V_12 ) ;
}
static void F_13 ( void T_3 * V_4 , void * V_11 , int V_12 )
{
F_14 ( V_4 , V_11 , ( V_12 + 1 ) >> 1 ) ;
}
static void F_15 ( void T_3 * V_4 , void * V_11 , int V_12 )
{
F_16 ( V_4 , V_11 , ( V_12 + 3 ) >> 2 ) ;
}
static void F_17 ( void T_3 * V_4 , void * V_11 , int V_12 )
{
F_18 ( V_4 , V_11 , V_12 ) ;
}
static void F_19 ( void T_3 * V_4 , void * V_11 , int V_12 )
{
F_20 ( V_4 , V_11 , ( V_12 + 1 ) >> 1 ) ;
}
static void F_21 ( void T_3 * V_4 , void * V_11 , int V_12 )
{
F_22 ( V_4 , V_11 , ( V_12 + 3 ) >> 2 ) ;
}
static void F_23 ( void T_3 * V_4 , int V_12 )
{
int V_13 ;
int V_14 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
V_14 = F_5 ( V_4 ) ;
}
static void F_24 ( void T_3 * V_4 , int V_12 )
{
int V_13 ;
int V_14 ;
V_12 = ( V_12 + 1 ) >> 1 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
V_14 = F_25 ( V_4 ) ;
}
static void F_26 ( void T_3 * V_4 , int V_12 )
{
int V_13 ;
int V_14 ;
V_12 = ( V_12 + 3 ) >> 2 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
V_14 = F_27 ( V_4 ) ;
}
static void F_28 ( T_1 * V_3 , unsigned int V_15 )
{
if ( V_3 -> V_16 || V_3 -> V_17 )
F_29 ( V_15 ) ;
else
F_30 ( V_15 ) ;
}
static int
F_31 ( struct V_1 * V_2 , int V_18 , int V_4 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_19 ;
unsigned int V_20 ;
int V_21 ;
F_32 ( & V_3 -> V_22 ) ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
V_20 = F_5 ( V_3 -> V_5 ) ;
F_6 ( V_3 , V_24 , V_25 | V_4 ) ;
F_6 ( V_3 , V_26 , V_27 | V_28 ) ;
F_4 ( V_20 , V_3 -> V_5 ) ;
F_34 ( & V_3 -> V_23 , V_19 ) ;
F_28 ( V_3 , 1 ) ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
V_20 = F_5 ( V_3 -> V_5 ) ;
F_6 ( V_3 , V_26 , 0x0 ) ;
V_21 = ( F_3 ( V_3 , V_29 ) << 8 ) | F_3 ( V_3 , V_30 ) ;
F_4 ( V_20 , V_3 -> V_5 ) ;
F_34 ( & V_3 -> V_23 , V_19 ) ;
F_35 ( & V_3 -> V_22 ) ;
F_36 ( V_3 , 5 , L_4 , V_4 , V_21 ) ;
return V_21 ;
}
static void
F_37 ( struct V_1 * V_2 ,
int V_31 , int V_4 , int V_7 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_19 ;
unsigned long V_20 ;
F_36 ( V_3 , 5 , L_5 , V_4 , V_7 ) ;
if ( ! V_3 -> V_17 )
F_32 ( & V_3 -> V_22 ) ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
V_20 = F_5 ( V_3 -> V_5 ) ;
F_6 ( V_3 , V_24 , V_25 | V_4 ) ;
F_6 ( V_3 , V_30 , V_7 ) ;
F_6 ( V_3 , V_29 , V_7 >> 8 ) ;
F_6 ( V_3 , V_26 , V_28 | V_32 ) ;
F_4 ( V_20 , V_3 -> V_5 ) ;
F_34 ( & V_3 -> V_23 , V_19 ) ;
F_28 ( V_3 , 1 ) ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
V_20 = F_5 ( V_3 -> V_5 ) ;
F_6 ( V_3 , V_26 , 0x0 ) ;
F_4 ( V_20 , V_3 -> V_5 ) ;
F_34 ( & V_3 -> V_23 , V_19 ) ;
if ( ! V_3 -> V_17 )
F_35 ( & V_3 -> V_22 ) ;
}
static void F_38 ( struct V_33 * V_3 , int V_34 )
{
switch ( V_34 ) {
case 1 :
V_3 -> V_35 = F_23 ;
V_3 -> V_36 = F_11 ;
V_3 -> V_37 = F_17 ;
break;
case 3 :
F_8 ( V_3 -> V_2 , L_6 ) ;
case 2 :
V_3 -> V_35 = F_24 ;
V_3 -> V_36 = F_13 ;
V_3 -> V_37 = F_19 ;
break;
case 4 :
default:
V_3 -> V_35 = F_26 ;
V_3 -> V_36 = F_15 ;
V_3 -> V_37 = F_21 ;
break;
}
}
static void F_39 ( T_1 * V_3 )
{
if ( V_3 -> type == V_38 )
F_40 ( & V_3 -> V_39 , V_40 * 2 ) ;
}
static int F_41 ( struct V_1 * V_2 , struct V_41 * V_42 , int V_43 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
if ( ! F_42 ( V_2 ) )
return - V_45 ;
return F_43 ( & V_44 -> V_46 , F_44 ( V_42 ) , V_43 , NULL ) ;
}
static unsigned int
F_45 ( T_1 * V_3 , int V_4 )
{
unsigned long V_19 ;
unsigned int V_21 ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
V_21 = F_3 ( V_3 , V_4 ) ;
F_34 ( & V_3 -> V_23 , V_19 ) ;
return V_21 ;
}
static int F_46 ( T_1 * V_3 )
{
unsigned int V_47 ;
int V_48 = 8 ;
while ( 1 ) {
V_47 = F_45 ( V_3 , V_26 ) ;
if ( ( V_47 & V_49 ) == 0 )
break;
F_30 ( 1 ) ;
if ( V_48 -- < 0 ) {
F_8 ( V_3 -> V_2 , L_7 ) ;
break;
}
}
return 0 ;
}
static void
F_47 ( T_1 * V_3 , int V_50 , T_2 * V_51 )
{
unsigned long V_19 ;
if ( V_3 -> V_19 & V_52 ) {
V_51 [ 0 ] = 0xff ;
V_51 [ 1 ] = 0xff ;
return;
}
F_32 ( & V_3 -> V_22 ) ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
F_6 ( V_3 , V_24 , V_50 ) ;
F_6 ( V_3 , V_26 , V_27 ) ;
F_34 ( & V_3 -> V_23 , V_19 ) ;
F_46 ( V_3 ) ;
F_30 ( 1 ) ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
F_6 ( V_3 , V_26 , 0x0 ) ;
V_51 [ 0 ] = F_3 ( V_3 , V_30 ) ;
V_51 [ 1 ] = F_3 ( V_3 , V_29 ) ;
F_34 ( & V_3 -> V_23 , V_19 ) ;
F_35 ( & V_3 -> V_22 ) ;
}
static void
F_48 ( T_1 * V_3 , int V_50 , T_2 * V_11 )
{
unsigned long V_19 ;
if ( V_3 -> V_19 & V_52 )
return;
F_32 ( & V_3 -> V_22 ) ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
F_6 ( V_3 , V_24 , V_50 ) ;
F_6 ( V_3 , V_29 , V_11 [ 1 ] ) ;
F_6 ( V_3 , V_30 , V_11 [ 0 ] ) ;
F_6 ( V_3 , V_26 , V_53 | V_32 ) ;
F_34 ( & V_3 -> V_23 , V_19 ) ;
F_46 ( V_3 ) ;
F_29 ( 1 ) ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
F_6 ( V_3 , V_26 , 0 ) ;
F_34 ( & V_3 -> V_23 , V_19 ) ;
F_35 ( & V_3 -> V_22 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
F_50 ( V_55 -> V_56 , V_57 , sizeof( V_55 -> V_56 ) ) ;
F_50 ( V_55 -> V_58 , V_59 , sizeof( V_55 -> V_58 ) ) ;
F_50 ( V_55 -> V_60 , F_51 ( V_44 -> V_2 ) -> V_61 ,
sizeof( V_55 -> V_60 ) ) ;
}
static T_4 F_52 ( struct V_1 * V_2 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
return V_44 -> V_62 ;
}
static void F_53 ( struct V_1 * V_2 , T_4 V_7 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
V_44 -> V_62 = V_7 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_63 * V_43 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
F_55 ( & V_44 -> V_46 , V_43 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_63 * V_43 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
return F_57 ( & V_44 -> V_46 , V_43 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
return F_59 ( & V_44 -> V_46 ) ;
}
static int F_60 ( struct V_1 * V_2 ,
T_5 V_64 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
T_5 V_65 = V_2 -> V_64 ^ V_64 ;
unsigned long V_19 ;
if ( ! ( V_65 & V_66 ) )
return 0 ;
F_33 ( & V_44 -> V_23 , V_19 ) ;
F_6 ( V_44 , V_67 , ( V_64 & V_66 ) ? V_68 : 0 ) ;
F_34 ( & V_44 -> V_23 , V_19 ) ;
return 0 ;
}
static T_4 F_61 ( struct V_1 * V_2 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
T_4 V_21 ;
if ( V_44 -> V_19 & V_69 )
V_21 = F_62 ( & V_44 -> V_46 ) ;
else
V_21 = F_45 ( V_44 , V_70 ) & V_71 ? 1 : 0 ;
return V_21 ;
}
static int F_63 ( struct V_1 * V_2 )
{
return 128 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_72 * V_73 , T_2 * V_11 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
int V_50 = V_73 -> V_50 ;
int V_74 = V_73 -> V_74 ;
int V_13 ;
if ( ( V_74 & 1 ) != 0 || ( V_50 & 1 ) != 0 )
return - V_45 ;
if ( V_44 -> V_19 & V_52 )
return - V_75 ;
V_73 -> V_76 = V_77 ;
for ( V_13 = 0 ; V_13 < V_74 ; V_13 += 2 )
F_47 ( V_44 , ( V_50 + V_13 ) / 2 , V_11 + V_13 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_72 * V_73 , T_2 * V_11 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
int V_50 = V_73 -> V_50 ;
int V_74 = V_73 -> V_74 ;
int V_78 ;
if ( V_44 -> V_19 & V_52 )
return - V_75 ;
if ( V_73 -> V_76 != V_77 )
return - V_45 ;
while ( V_74 > 0 ) {
if ( V_74 & 1 || V_50 & 1 ) {
int V_79 = V_50 & 1 ;
T_2 V_14 [ 2 ] ;
F_47 ( V_44 , V_50 / 2 , V_14 ) ;
V_14 [ V_79 ] = * V_11 ;
F_48 ( V_44 , V_50 / 2 , V_14 ) ;
V_78 = 1 ;
} else {
F_48 ( V_44 , V_50 / 2 , V_11 ) ;
V_78 = 2 ;
}
V_11 += V_78 ;
V_50 += V_78 ;
V_74 -= V_78 ;
}
return 0 ;
}
static void F_66 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
memset ( V_81 , 0 , sizeof( struct V_80 ) ) ;
V_81 -> V_82 = V_44 -> V_83 ? V_84 : 0 ;
V_81 -> V_85 = V_44 -> V_86 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
unsigned long V_19 ;
T_4 V_87 = V_81 -> V_85 ;
T_4 V_88 = 0 ;
if ( ! V_44 -> V_83 )
return - V_89 ;
if ( V_87 & ~ V_84 )
return - V_45 ;
if ( V_87 & V_84 )
V_88 |= V_90 ;
F_32 ( & V_44 -> V_22 ) ;
F_33 ( & V_44 -> V_23 , V_19 ) ;
F_6 ( V_44 , V_91 , V_88 ) ;
F_34 ( & V_44 -> V_23 , V_19 ) ;
F_35 ( & V_44 -> V_22 ) ;
if ( V_44 -> V_86 != V_87 ) {
if ( ! V_44 -> V_86 )
F_68 ( V_44 -> V_92 , 1 ) ;
else if ( V_44 -> V_86 && ! V_87 )
F_68 ( V_44 -> V_92 , 0 ) ;
}
V_44 -> V_86 = V_87 ;
return 0 ;
}
static void F_69 ( T_1 * V_3 ,
unsigned V_93 , unsigned V_94 )
{
int V_95 ;
struct V_1 * V_96 = V_3 -> V_96 ;
struct V_97 * V_46 = & V_3 -> V_46 ;
unsigned V_98 = F_45 ( V_3 , V_8 ) ;
if ( V_93 ) {
V_95 = V_46 -> V_99 ( V_46 -> V_2 , V_46 -> V_100 , V_101 ) ;
F_70 ( V_3 -> V_2 ,
L_8 ,
V_96 -> V_61 , ( V_94 & V_102 ) ? 10 : 100 ,
( V_98 & V_103 ) ? L_9 : L_10 , V_95 ) ;
} else {
F_70 ( V_3 -> V_2 , L_11 , V_96 -> V_61 ) ;
}
}
static void
F_71 ( struct V_104 * V_81 )
{
struct V_105 * V_106 = F_72 ( V_81 ) ;
T_1 * V_3 = F_73 ( V_106 , T_1 , V_39 ) ;
struct V_1 * V_96 = V_3 -> V_96 ;
if ( V_3 -> V_19 & V_107 &&
! ( V_3 -> V_19 & V_69 ) ) {
unsigned V_94 = F_45 ( V_3 , V_70 ) ;
unsigned V_108 = F_74 ( V_96 ) ? 1 : 0 ;
unsigned V_109 ;
V_109 = ( V_94 & V_71 ) ? 1 : 0 ;
if ( V_108 != V_109 ) {
if ( F_75 ( V_3 ) )
F_69 ( V_3 , V_109 , V_94 ) ;
if ( ! V_109 )
F_76 ( V_96 ) ;
else
F_77 ( V_96 ) ;
}
} else
F_78 ( & V_3 -> V_46 , F_75 ( V_3 ) , 0 ) ;
if ( F_42 ( V_96 ) )
F_39 ( V_3 ) ;
}
static void
F_79 ( struct V_110 * V_111 , struct V_33 * V_3 )
{
F_80 ( V_3 -> V_5 ) ;
F_80 ( V_3 -> V_6 ) ;
F_81 ( V_3 -> V_112 ) ;
F_82 ( V_3 -> V_112 ) ;
F_81 ( V_3 -> V_113 ) ;
F_82 ( V_3 -> V_113 ) ;
}
static unsigned char F_83 ( enum V_114 type )
{
switch ( type ) {
case V_38 : return 'e' ;
case V_115 : return 'a' ;
case V_116 : return 'b' ;
}
return '?' ;
}
static void
F_84 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
struct V_117 * V_118 ;
int V_13 , V_119 ;
T_4 V_120 ;
T_6 V_121 [ 4 ] = { 0 , 0 , 0 , 0x8000 } ;
T_2 V_122 = V_123 | V_124 | V_125 ;
F_36 ( V_3 , 1 , L_12 , V_126 ) ;
for ( V_13 = 0 , V_119 = V_127 ; V_13 < 6 ; V_13 ++ , V_119 ++ )
F_6 ( V_3 , V_119 , V_2 -> V_128 [ V_13 ] ) ;
if ( V_2 -> V_19 & V_129 )
V_122 |= V_130 ;
if ( V_2 -> V_19 & V_131 )
V_122 |= V_132 ;
F_85 (ha, dev) {
V_120 = F_86 ( 6 , V_118 -> V_133 ) & 0x3f ;
V_121 [ V_120 / 16 ] |= ( T_6 ) 1 << ( V_120 % 16 ) ;
}
for ( V_13 = 0 , V_119 = V_134 ; V_13 < 4 ; V_13 ++ ) {
F_6 ( V_3 , V_119 ++ , V_121 [ V_13 ] ) ;
F_6 ( V_3 , V_119 ++ , V_121 [ V_13 ] >> 8 ) ;
}
F_6 ( V_3 , V_135 , V_122 ) ;
}
static void
F_87 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_19 ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
F_84 ( V_2 ) ;
F_34 ( & V_3 -> V_23 , V_19 ) ;
}
static void
F_88 ( T_1 * V_3 )
{
F_6 ( V_3 , V_136 , V_137 ) ;
}
static void
F_89 ( T_1 * V_3 )
{
F_6 ( V_3 , V_136 , V_3 -> V_138 ) ;
}
static void
F_90 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned int V_139 ;
unsigned int V_98 ;
F_36 ( V_3 , 1 , L_12 , V_126 ) ;
F_7 ( V_3 ) ;
F_88 ( V_3 ) ;
V_3 -> V_140 = F_3 ( V_3 , V_141 ) >> 6 ;
if ( V_2 -> V_142 & V_66 )
F_6 ( V_3 , V_67 ,
( V_2 -> V_64 & V_66 ) ? V_68 : 0 ) ;
F_6 ( V_3 , V_143 , V_144 ) ;
F_6 ( V_3 , V_145 , 0 ) ;
if ( V_3 -> type == V_116 ) {
F_37 ( V_2 , 0 , V_146 , V_147 ) ;
F_37 ( V_2 , 0 , V_148 , V_149 ) ;
}
V_98 = ( V_3 -> V_19 & V_69 ) ? V_150 : 0 ;
if ( V_3 -> V_83 )
V_98 |= V_151 ;
F_6 ( V_3 , V_8 , V_98 ) ;
F_6 ( V_3 , V_152 , 0 ) ;
F_6 ( V_3 , V_153 , 0x3f ) ;
F_6 ( V_3 , V_154 , 0xff ) ;
F_6 ( V_3 , V_155 , 0 ) ;
F_6 ( V_3 , V_70 , V_156 | V_157 | V_158 ) ;
F_6 ( V_3 , V_141 , V_159 ) ;
F_84 ( V_2 ) ;
V_139 = V_137 | V_160 | V_161 ;
if ( V_3 -> type != V_38 )
V_139 |= V_162 ;
V_3 -> V_138 = V_139 ;
V_3 -> V_163 = 0 ;
V_3 -> V_164 = 0 ;
V_2 -> V_165 = V_166 ;
}
static void F_91 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
T_2 V_20 ;
unsigned long V_19 ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
V_3 -> V_17 = 1 ;
V_20 = F_5 ( V_3 -> V_5 ) ;
F_92 ( V_2 ) ;
F_90 ( V_2 ) ;
F_89 ( V_3 ) ;
V_2 -> V_165 = V_166 ;
F_93 ( V_2 ) ;
F_4 ( V_20 , V_3 -> V_5 ) ;
V_3 -> V_17 = 0 ;
F_34 ( & V_3 -> V_23 , V_19 ) ;
}
static void F_94 ( struct V_1 * V_2 ,
int V_167 ,
T_6 V_168 )
{
T_1 * V_44 = F_1 ( V_2 ) ;
if ( V_44 -> V_167 != V_167 ) {
if ( V_167 == V_169 )
F_6 ( V_44 , V_170 , 0 ) ;
else
F_6 ( V_44 , V_170 , V_171 | V_172 | V_173 ) ;
V_44 -> V_167 = V_167 ;
}
F_6 ( V_44 , V_174 , V_168 ) ;
F_6 ( V_44 , V_175 , V_168 >> 8 ) ;
F_6 ( V_44 , V_152 , V_176 ) ;
}
static int
F_95 ( struct V_177 * V_178 , struct V_1 * V_2 )
{
unsigned long V_19 ;
T_1 * V_3 = F_2 ( V_2 ) ;
F_36 ( V_3 , 3 , L_13 , V_126 ) ;
if ( V_3 -> V_163 > 1 )
return V_179 ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
F_4 ( V_180 , V_3 -> V_5 ) ;
( V_3 -> V_36 ) ( V_3 -> V_6 , V_178 -> V_11 , V_178 -> V_74 ) ;
V_2 -> V_181 . V_182 += V_178 -> V_74 ;
V_3 -> V_163 ++ ;
if ( V_3 -> V_163 == 1 ) {
F_94 ( V_2 , V_178 -> V_167 , V_178 -> V_74 ) ;
} else {
V_3 -> V_164 = V_178 -> V_74 ;
V_3 -> V_183 = V_178 -> V_167 ;
F_92 ( V_2 ) ;
}
F_34 ( & V_3 -> V_23 , V_19 ) ;
F_96 ( V_178 ) ;
return V_184 ;
}
static void F_97 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_185 = F_3 ( V_3 , V_70 ) ;
if ( V_185 & ( V_157 | V_158 ) ) {
V_3 -> V_163 -- ;
V_2 -> V_181 . V_186 ++ ;
if ( F_98 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_14 , V_185 ) ;
if ( V_3 -> V_163 > 0 )
F_94 ( V_2 , V_3 -> V_183 ,
V_3 -> V_164 ) ;
F_93 ( V_2 ) ;
}
}
static void
F_99 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
struct V_187 V_188 ;
struct V_177 * V_178 ;
T_2 V_189 , * V_190 ;
bool V_191 ;
int V_192 ;
do {
F_3 ( V_3 , V_193 ) ;
V_189 = F_5 ( V_3 -> V_6 ) ;
if ( V_189 & V_194 ) {
F_100 ( V_3 -> V_2 , L_15 , V_189 ) ;
F_6 ( V_3 , V_135 , 0x00 ) ;
return;
}
if ( ! ( V_189 & V_195 ) )
return;
V_191 = true ;
F_4 ( V_196 , V_3 -> V_5 ) ;
( V_3 -> V_37 ) ( V_3 -> V_6 , & V_188 , sizeof( V_188 ) ) ;
V_192 = F_101 ( V_188 . V_192 ) ;
if ( F_102 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_16 ,
V_188 . V_197 , V_192 ) ;
if ( V_192 < 0x40 ) {
V_191 = false ;
if ( F_103 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_17 ) ;
}
if ( V_192 > V_198 ) {
F_8 ( V_3 -> V_2 , L_18 , V_192 ) ;
}
if ( V_188 . V_197 & ( V_199 | V_200 | V_201 |
V_202 | V_203 |
V_204 | V_205 ) ) {
V_191 = false ;
if ( V_188 . V_197 & V_199 ) {
if ( F_103 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_19 ) ;
V_2 -> V_181 . V_206 ++ ;
}
if ( V_188 . V_197 & V_200 ) {
if ( F_103 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_20 ) ;
V_2 -> V_181 . V_207 ++ ;
}
if ( V_188 . V_197 & V_205 ) {
if ( F_103 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_21 ) ;
V_2 -> V_181 . V_208 ++ ;
}
}
if ( V_191 &&
( ( V_178 = F_104 ( V_2 , V_192 + 4 ) ) != NULL ) ) {
F_105 ( V_178 , 2 ) ;
V_190 = ( T_2 * ) F_106 ( V_178 , V_192 - 4 ) ;
( V_3 -> V_37 ) ( V_3 -> V_6 , V_190 , V_192 ) ;
V_2 -> V_181 . V_209 += V_192 ;
V_178 -> V_210 = F_107 ( V_178 , V_2 ) ;
if ( V_2 -> V_64 & V_66 ) {
if ( ( ( ( V_189 & 0x1c ) << 3 ) & V_189 ) == 0 )
V_178 -> V_167 = V_211 ;
else
F_108 ( V_178 ) ;
}
F_109 ( V_178 ) ;
V_2 -> V_181 . V_212 ++ ;
} else {
( V_3 -> V_35 ) ( V_3 -> V_6 , V_192 ) ;
}
} while ( V_189 & V_195 );
}
static T_7 F_110 ( int V_213 , void * V_214 )
{
struct V_1 * V_2 = V_214 ;
T_1 * V_3 = F_2 ( V_2 ) ;
int V_215 ;
unsigned long V_19 ;
T_2 V_20 ;
F_36 ( V_3 , 3 , L_12 , V_126 ) ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
V_20 = F_5 ( V_3 -> V_5 ) ;
F_88 ( V_3 ) ;
V_215 = F_3 ( V_3 , V_141 ) ;
F_6 ( V_3 , V_141 , V_215 ) ;
if ( F_111 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_22 , V_215 ) ;
if ( V_215 & V_216 )
F_99 ( V_2 ) ;
if ( V_215 & V_217 )
F_97 ( V_2 , V_3 ) ;
if ( V_3 -> type != V_38 ) {
if ( V_215 & V_218 ) {
F_40 ( & V_3 -> V_39 , 1 ) ;
}
}
F_89 ( V_3 ) ;
F_4 ( V_20 , V_3 -> V_5 ) ;
F_34 ( & V_3 -> V_23 , V_19 ) ;
return V_219 ;
}
static T_7 F_112 ( int V_213 , void * V_214 )
{
struct V_1 * V_2 = V_214 ;
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_19 ;
unsigned V_94 , V_88 ;
F_33 ( & V_3 -> V_23 , V_19 ) ;
V_94 = F_3 ( V_3 , V_70 ) ;
V_88 = F_3 ( V_3 , V_91 ) ;
F_8 ( V_3 -> V_2 , L_23 , V_126 , V_94 , V_88 ) ;
if ( V_94 & V_156 ) {
F_6 ( V_3 , V_70 , V_156 ) ;
if ( V_88 & V_220 )
F_70 ( V_3 -> V_2 , L_24 ) ;
if ( V_88 & V_221 )
F_70 ( V_3 -> V_2 , L_25 ) ;
if ( V_88 & V_222 )
F_70 ( V_3 -> V_2 , L_26 ) ;
if ( ! ( V_88 & ( V_220 | V_221 | V_222 ) ) )
F_10 ( V_3 -> V_2 , L_27
L_28 , V_94 , V_88 ) ;
}
F_34 ( & V_3 -> V_23 , V_19 ) ;
return ( V_94 & V_156 ) ? V_219 : V_223 ;
}
static void F_113 ( struct V_1 * V_2 )
{
F_114 ( V_2 -> V_213 ) ;
F_110 ( V_2 -> V_213 , V_2 ) ;
F_115 ( V_2 -> V_213 ) ;
}
static int
F_116 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
unsigned long V_224 = V_3 -> V_225 -> V_19 & V_226 ;
if ( F_117 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_29 , V_2 -> V_61 ) ;
if ( V_224 == V_227 )
V_224 = F_118 ( V_2 -> V_213 ) ;
if ( V_224 == V_227 )
F_100 ( V_3 -> V_2 , L_30 ) ;
V_224 |= V_228 ;
F_6 ( V_3 , V_145 , 0 ) ;
F_29 ( 1 ) ;
F_90 ( V_2 ) ;
if ( F_119 ( V_2 -> V_213 , F_110 , V_224 , V_2 -> V_61 , V_2 ) )
return - V_229 ;
F_89 ( V_3 ) ;
V_3 -> V_230 = 0 ;
F_78 ( & V_3 -> V_46 , F_75 ( V_3 ) , 1 ) ;
F_120 ( V_2 ) ;
F_40 ( & V_3 -> V_39 , 1 ) ;
return 0 ;
}
static void
F_121 ( struct V_1 * V_2 )
{
T_1 * V_3 = F_2 ( V_2 ) ;
F_37 ( V_2 , 0 , V_146 , V_147 ) ;
F_6 ( V_3 , V_145 , 0x01 ) ;
F_88 ( V_3 ) ;
F_6 ( V_3 , V_135 , 0x00 ) ;
}
static int
F_122 ( struct V_1 * V_96 )
{
T_1 * V_3 = F_2 ( V_96 ) ;
if ( F_123 ( V_3 ) )
F_8 ( V_3 -> V_2 , L_31 , V_96 -> V_61 ) ;
F_124 ( & V_3 -> V_39 ) ;
F_92 ( V_96 ) ;
F_76 ( V_96 ) ;
F_125 ( V_96 -> V_213 , V_96 ) ;
F_121 ( V_96 ) ;
return 0 ;
}
static struct V_231 * F_126 ( struct V_232 * V_2 )
{
struct V_231 * V_233 ;
struct V_234 * V_235 = V_2 -> V_236 ;
const void * V_237 ;
if ( ! F_127 ( V_238 ) || ! V_235 )
return NULL ;
V_233 = F_128 ( V_2 , sizeof( * V_233 ) , V_239 ) ;
if ( ! V_233 )
return F_129 ( - V_240 ) ;
if ( F_130 ( V_235 , L_32 , NULL ) )
V_233 -> V_19 |= V_69 ;
if ( F_130 ( V_235 , L_33 , NULL ) )
V_233 -> V_19 |= V_52 ;
V_237 = F_131 ( V_235 ) ;
if ( V_237 )
memcpy ( V_233 -> V_128 , V_237 , sizeof( V_233 -> V_128 ) ) ;
return V_233 ;
}
static int
F_132 ( struct V_110 * V_111 )
{
struct V_231 * V_233 = F_133 ( & V_111 -> V_2 ) ;
struct V_33 * V_3 ;
struct V_1 * V_96 ;
const unsigned char * V_241 ;
int V_21 = 0 ;
int V_242 ;
int V_13 ;
T_4 V_243 ;
if ( ! V_233 ) {
V_233 = F_126 ( & V_111 -> V_2 ) ;
if ( F_134 ( V_233 ) )
return F_135 ( V_233 ) ;
}
V_96 = F_136 ( sizeof( struct V_33 ) ) ;
if ( ! V_96 )
return - V_240 ;
F_137 ( V_96 , & V_111 -> V_2 ) ;
F_8 ( & V_111 -> V_2 , L_34 ) ;
V_3 = F_2 ( V_96 ) ;
V_3 -> V_2 = & V_111 -> V_2 ;
V_3 -> V_96 = V_96 ;
F_138 ( & V_3 -> V_23 ) ;
F_139 ( & V_3 -> V_22 ) ;
F_140 ( & V_3 -> V_39 , F_71 ) ;
V_3 -> V_244 = F_141 ( V_111 , V_245 , 0 ) ;
V_3 -> V_246 = F_141 ( V_111 , V_245 , 1 ) ;
V_3 -> V_225 = F_141 ( V_111 , V_247 , 0 ) ;
if ( V_3 -> V_244 == NULL || V_3 -> V_246 == NULL ||
V_3 -> V_225 == NULL ) {
F_10 ( V_3 -> V_2 , L_35 ) ;
V_21 = - V_75 ;
goto V_248;
}
V_3 -> V_92 = F_142 ( V_111 , 1 ) ;
if ( V_3 -> V_92 >= 0 ) {
F_8 ( V_3 -> V_2 , L_36 , V_3 -> V_92 ) ;
V_21 = F_119 ( V_3 -> V_92 , F_112 ,
V_228 , F_143 ( V_3 -> V_2 ) , V_96 ) ;
if ( V_21 ) {
F_10 ( V_3 -> V_2 , L_37 , V_21 ) ;
} else {
V_21 = F_68 ( V_3 -> V_92 , 1 ) ;
if ( V_21 ) {
F_10 ( V_3 -> V_2 , L_38 ,
V_3 -> V_92 , V_21 ) ;
V_21 = 0 ;
} else {
F_68 ( V_3 -> V_92 , 0 ) ;
V_3 -> V_83 = 1 ;
}
}
}
V_242 = F_144 ( V_3 -> V_244 ) ;
V_3 -> V_113 = F_145 ( V_3 -> V_244 -> V_249 , V_242 ,
V_111 -> V_61 ) ;
if ( V_3 -> V_113 == NULL ) {
F_10 ( V_3 -> V_2 , L_39 ) ;
V_21 = - V_250 ;
goto V_248;
}
V_3 -> V_5 = F_146 ( V_3 -> V_244 -> V_249 , V_242 ) ;
if ( V_3 -> V_5 == NULL ) {
F_10 ( V_3 -> V_2 , L_40 ) ;
V_21 = - V_45 ;
goto V_248;
}
V_242 = F_144 ( V_3 -> V_246 ) ;
V_3 -> V_112 = F_145 ( V_3 -> V_246 -> V_249 , V_242 ,
V_111 -> V_61 ) ;
if ( V_3 -> V_112 == NULL ) {
F_10 ( V_3 -> V_2 , L_41 ) ;
V_21 = - V_250 ;
goto V_248;
}
V_3 -> V_6 = F_146 ( V_3 -> V_246 -> V_249 , V_242 ) ;
if ( V_3 -> V_6 == NULL ) {
F_10 ( V_3 -> V_2 , L_42 ) ;
V_21 = - V_45 ;
goto V_248;
}
V_96 -> V_251 = ( unsigned long ) V_3 -> V_5 ;
V_96 -> V_213 = V_3 -> V_225 -> V_249 ;
F_38 ( V_3 , V_242 ) ;
if ( V_233 != NULL ) {
if ( V_233 -> V_19 & V_252 )
F_38 ( V_3 , 1 ) ;
if ( V_233 -> V_19 & V_253 )
F_38 ( V_3 , 2 ) ;
if ( V_233 -> V_19 & V_254 )
F_38 ( V_3 , 4 ) ;
if ( V_233 -> V_37 != NULL )
V_3 -> V_37 = V_233 -> V_37 ;
if ( V_233 -> V_36 != NULL )
V_3 -> V_36 = V_233 -> V_36 ;
if ( V_233 -> V_35 != NULL )
V_3 -> V_35 = V_233 -> V_35 ;
V_3 -> V_19 = V_233 -> V_19 ;
}
#ifdef F_147
V_3 -> V_19 |= V_107 ;
#endif
F_7 ( V_3 ) ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
V_243 = F_3 ( V_3 , V_255 ) ;
V_243 |= ( T_4 ) F_3 ( V_3 , V_256 ) << 8 ;
V_243 |= ( T_4 ) F_3 ( V_3 , V_257 ) << 16 ;
V_243 |= ( T_4 ) F_3 ( V_3 , V_258 ) << 24 ;
if ( V_243 == V_259 )
break;
F_10 ( V_3 -> V_2 , L_43 , V_243 ) ;
}
if ( V_243 != V_259 ) {
F_10 ( V_3 -> V_2 , L_44 , V_243 ) ;
V_21 = - V_260 ;
goto V_248;
}
V_243 = F_3 ( V_3 , V_261 ) ;
F_8 ( V_3 -> V_2 , L_45 , V_243 ) ;
switch ( V_243 ) {
case V_262 :
V_3 -> type = V_115 ;
break;
case V_263 :
V_3 -> type = V_116 ;
break;
default:
F_8 ( V_3 -> V_2 , L_46 , V_243 ) ;
V_3 -> type = V_38 ;
}
if ( V_3 -> type == V_115 || V_3 -> type == V_116 ) {
V_96 -> V_142 = V_66 | V_264 ;
V_96 -> V_64 |= V_96 -> V_142 ;
}
F_148 ( V_96 ) ;
V_96 -> V_265 = & V_266 ;
V_96 -> V_267 = F_149 ( V_268 ) ;
V_96 -> V_269 = & V_270 ;
V_3 -> V_62 = V_271 ;
V_3 -> V_46 . V_272 = 0x1f ;
V_3 -> V_46 . V_273 = 0x1f ;
V_3 -> V_46 . V_274 = 0 ;
V_3 -> V_46 . V_275 = 0 ;
V_3 -> V_46 . V_2 = V_96 ;
V_3 -> V_46 . V_99 = F_31 ;
V_3 -> V_46 . V_276 = F_37 ;
V_241 = L_47 ;
for ( V_13 = 0 ; V_13 < 6 ; V_13 += 2 )
F_47 ( V_3 , V_13 / 2 , V_96 -> V_128 + V_13 ) ;
if ( ! F_150 ( V_96 -> V_128 ) && V_233 != NULL ) {
V_241 = L_48 ;
memcpy ( V_96 -> V_128 , V_233 -> V_128 , V_277 ) ;
}
if ( ! F_150 ( V_96 -> V_128 ) ) {
V_241 = L_49 ;
for ( V_13 = 0 ; V_13 < 6 ; V_13 ++ )
V_96 -> V_128 [ V_13 ] = F_3 ( V_3 , V_13 + V_127 ) ;
}
if ( ! F_150 ( V_96 -> V_128 ) ) {
F_100 ( V_3 -> V_2 , L_50
L_51 , V_96 -> V_61 ) ;
F_151 ( V_96 ) ;
V_241 = L_52 ;
}
F_152 ( V_111 , V_96 ) ;
V_21 = F_153 ( V_96 ) ;
if ( V_21 == 0 )
F_154 ( V_278 L_53 ,
V_96 -> V_61 , F_83 ( V_3 -> type ) ,
V_3 -> V_5 , V_3 -> V_6 , V_96 -> V_213 ,
V_96 -> V_128 , V_241 ) ;
return 0 ;
V_248:
F_10 ( V_3 -> V_2 , L_54 , V_21 ) ;
F_79 ( V_111 , V_3 ) ;
F_155 ( V_96 ) ;
return V_21 ;
}
static int
F_156 ( struct V_232 * V_2 )
{
struct V_110 * V_111 = F_51 ( V_2 ) ;
struct V_1 * V_96 = F_157 ( V_111 ) ;
T_1 * V_3 ;
if ( V_96 ) {
V_3 = F_2 ( V_96 ) ;
V_3 -> V_16 = 1 ;
if ( ! F_42 ( V_96 ) )
return 0 ;
F_158 ( V_96 ) ;
if ( ! V_3 -> V_86 )
F_121 ( V_96 ) ;
}
return 0 ;
}
static int
F_159 ( struct V_232 * V_2 )
{
struct V_110 * V_111 = F_51 ( V_2 ) ;
struct V_1 * V_96 = F_157 ( V_111 ) ;
T_1 * V_3 = F_2 ( V_96 ) ;
if ( V_96 ) {
if ( F_42 ( V_96 ) ) {
if ( ! V_3 -> V_86 ) {
F_90 ( V_96 ) ;
F_89 ( V_3 ) ;
}
F_160 ( V_96 ) ;
}
V_3 -> V_16 = 0 ;
}
return 0 ;
}
static int
F_161 ( struct V_110 * V_111 )
{
struct V_1 * V_96 = F_157 ( V_111 ) ;
F_162 ( V_96 ) ;
F_79 ( V_111 , F_2 ( V_96 ) ) ;
F_155 ( V_96 ) ;
F_8 ( & V_111 -> V_2 , L_55 ) ;
return 0 ;
}
