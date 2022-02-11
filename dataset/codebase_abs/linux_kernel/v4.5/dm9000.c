static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static T_1
F_3 ( struct V_1 * V_4 , int V_5 )
{
F_4 ( V_5 , V_4 -> V_6 ) ;
return F_5 ( V_4 -> V_7 ) ;
}
static void
F_6 ( struct V_1 * V_4 , int V_5 , int V_8 )
{
F_4 ( V_5 , V_4 -> V_6 ) ;
F_4 ( V_8 , V_4 -> V_7 ) ;
}
static void
F_7 ( struct V_1 * V_4 )
{
F_8 ( V_4 -> V_3 , L_1 ) ;
F_6 ( V_4 , V_9 , V_10 | V_11 ) ;
F_9 ( 100 ) ;
if ( F_3 ( V_4 , V_9 ) & 1 )
F_10 ( V_4 -> V_3 , L_2 ) ;
F_6 ( V_4 , V_9 , 0 ) ;
F_6 ( V_4 , V_9 , V_10 | V_11 ) ;
F_9 ( 100 ) ;
if ( F_3 ( V_4 , V_9 ) & 1 )
F_10 ( V_4 -> V_3 , L_3 ) ;
}
static void F_11 ( void T_2 * V_5 , void * V_12 , int V_13 )
{
F_12 ( V_5 , V_12 , V_13 ) ;
}
static void F_13 ( void T_2 * V_5 , void * V_12 , int V_13 )
{
F_14 ( V_5 , V_12 , ( V_13 + 1 ) >> 1 ) ;
}
static void F_15 ( void T_2 * V_5 , void * V_12 , int V_13 )
{
F_16 ( V_5 , V_12 , ( V_13 + 3 ) >> 2 ) ;
}
static void F_17 ( void T_2 * V_5 , void * V_12 , int V_13 )
{
F_18 ( V_5 , V_12 , V_13 ) ;
}
static void F_19 ( void T_2 * V_5 , void * V_12 , int V_13 )
{
F_20 ( V_5 , V_12 , ( V_13 + 1 ) >> 1 ) ;
}
static void F_21 ( void T_2 * V_5 , void * V_12 , int V_13 )
{
F_22 ( V_5 , V_12 , ( V_13 + 3 ) >> 2 ) ;
}
static void F_23 ( void T_2 * V_5 , int V_13 )
{
int V_14 ;
int V_15 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
V_15 = F_5 ( V_5 ) ;
}
static void F_24 ( void T_2 * V_5 , int V_13 )
{
int V_14 ;
int V_15 ;
V_13 = ( V_13 + 1 ) >> 1 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
V_15 = F_25 ( V_5 ) ;
}
static void F_26 ( void T_2 * V_5 , int V_13 )
{
int V_14 ;
int V_15 ;
V_13 = ( V_13 + 3 ) >> 2 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ )
V_15 = F_27 ( V_5 ) ;
}
static void F_28 ( struct V_1 * V_4 , unsigned int V_16 )
{
if ( V_4 -> V_17 || V_4 -> V_18 )
F_29 ( V_16 ) ;
else
F_30 ( V_16 ) ;
}
static int
F_31 ( struct V_2 * V_3 , int V_19 , int V_5 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned long V_20 ;
unsigned int V_21 ;
int V_22 ;
F_32 ( & V_4 -> V_23 ) ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
V_21 = F_5 ( V_4 -> V_6 ) ;
F_6 ( V_4 , V_25 , V_26 | V_5 ) ;
F_6 ( V_4 , V_27 , V_28 | V_29 ) ;
F_4 ( V_21 , V_4 -> V_6 ) ;
F_34 ( & V_4 -> V_24 , V_20 ) ;
F_28 ( V_4 , 1 ) ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
V_21 = F_5 ( V_4 -> V_6 ) ;
F_6 ( V_4 , V_27 , 0x0 ) ;
V_22 = ( F_3 ( V_4 , V_30 ) << 8 ) | F_3 ( V_4 , V_31 ) ;
F_4 ( V_21 , V_4 -> V_6 ) ;
F_34 ( & V_4 -> V_24 , V_20 ) ;
F_35 ( & V_4 -> V_23 ) ;
F_36 ( V_4 , 5 , L_4 , V_5 , V_22 ) ;
return V_22 ;
}
static void
F_37 ( struct V_2 * V_3 ,
int V_32 , int V_5 , int V_8 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned long V_20 ;
unsigned long V_21 ;
F_36 ( V_4 , 5 , L_5 , V_5 , V_8 ) ;
if ( ! V_4 -> V_18 )
F_32 ( & V_4 -> V_23 ) ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
V_21 = F_5 ( V_4 -> V_6 ) ;
F_6 ( V_4 , V_25 , V_26 | V_5 ) ;
F_6 ( V_4 , V_31 , V_8 ) ;
F_6 ( V_4 , V_30 , V_8 >> 8 ) ;
F_6 ( V_4 , V_27 , V_29 | V_33 ) ;
F_4 ( V_21 , V_4 -> V_6 ) ;
F_34 ( & V_4 -> V_24 , V_20 ) ;
F_28 ( V_4 , 1 ) ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
V_21 = F_5 ( V_4 -> V_6 ) ;
F_6 ( V_4 , V_27 , 0x0 ) ;
F_4 ( V_21 , V_4 -> V_6 ) ;
F_34 ( & V_4 -> V_24 , V_20 ) ;
if ( ! V_4 -> V_18 )
F_35 ( & V_4 -> V_23 ) ;
}
static void F_38 ( struct V_1 * V_4 , int V_34 )
{
switch ( V_34 ) {
case 1 :
V_4 -> V_35 = F_23 ;
V_4 -> V_36 = F_11 ;
V_4 -> V_37 = F_17 ;
break;
case 3 :
F_8 ( V_4 -> V_3 , L_6 ) ;
case 2 :
V_4 -> V_35 = F_24 ;
V_4 -> V_36 = F_13 ;
V_4 -> V_37 = F_19 ;
break;
case 4 :
default:
V_4 -> V_35 = F_26 ;
V_4 -> V_36 = F_15 ;
V_4 -> V_37 = F_21 ;
break;
}
}
static void F_39 ( struct V_1 * V_4 )
{
if ( V_4 -> type == V_38 )
F_40 ( & V_4 -> V_39 , V_40 * 2 ) ;
}
static int F_41 ( struct V_2 * V_3 , struct V_41 * V_42 , int V_43 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
if ( ! F_42 ( V_3 ) )
return - V_45 ;
return F_43 ( & V_44 -> V_46 , F_44 ( V_42 ) , V_43 , NULL ) ;
}
static unsigned int
F_45 ( struct V_1 * V_4 , int V_5 )
{
unsigned long V_20 ;
unsigned int V_22 ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
V_22 = F_3 ( V_4 , V_5 ) ;
F_34 ( & V_4 -> V_24 , V_20 ) ;
return V_22 ;
}
static int F_46 ( struct V_1 * V_4 )
{
unsigned int V_47 ;
int V_48 = 8 ;
while ( 1 ) {
V_47 = F_45 ( V_4 , V_27 ) ;
if ( ( V_47 & V_49 ) == 0 )
break;
F_30 ( 1 ) ;
if ( V_48 -- < 0 ) {
F_8 ( V_4 -> V_3 , L_7 ) ;
break;
}
}
return 0 ;
}
static void
F_47 ( struct V_1 * V_4 , int V_50 , T_1 * V_51 )
{
unsigned long V_20 ;
if ( V_4 -> V_20 & V_52 ) {
V_51 [ 0 ] = 0xff ;
V_51 [ 1 ] = 0xff ;
return;
}
F_32 ( & V_4 -> V_23 ) ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
F_6 ( V_4 , V_25 , V_50 ) ;
F_6 ( V_4 , V_27 , V_28 ) ;
F_34 ( & V_4 -> V_24 , V_20 ) ;
F_46 ( V_4 ) ;
F_30 ( 1 ) ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
F_6 ( V_4 , V_27 , 0x0 ) ;
V_51 [ 0 ] = F_3 ( V_4 , V_31 ) ;
V_51 [ 1 ] = F_3 ( V_4 , V_30 ) ;
F_34 ( & V_4 -> V_24 , V_20 ) ;
F_35 ( & V_4 -> V_23 ) ;
}
static void
F_48 ( struct V_1 * V_4 , int V_50 , T_1 * V_12 )
{
unsigned long V_20 ;
if ( V_4 -> V_20 & V_52 )
return;
F_32 ( & V_4 -> V_23 ) ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
F_6 ( V_4 , V_25 , V_50 ) ;
F_6 ( V_4 , V_30 , V_12 [ 1 ] ) ;
F_6 ( V_4 , V_31 , V_12 [ 0 ] ) ;
F_6 ( V_4 , V_27 , V_53 | V_33 ) ;
F_34 ( & V_4 -> V_24 , V_20 ) ;
F_46 ( V_4 ) ;
F_29 ( 1 ) ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
F_6 ( V_4 , V_27 , 0 ) ;
F_34 ( & V_4 -> V_24 , V_20 ) ;
F_35 ( & V_4 -> V_23 ) ;
}
static void F_49 ( struct V_2 * V_3 ,
struct V_54 * V_55 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
F_50 ( V_55 -> V_56 , V_57 , sizeof( V_55 -> V_56 ) ) ;
F_50 ( V_55 -> V_58 , V_59 , sizeof( V_55 -> V_58 ) ) ;
F_50 ( V_55 -> V_60 , F_51 ( V_44 -> V_3 ) -> V_61 ,
sizeof( V_55 -> V_60 ) ) ;
}
static T_3 F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
return V_44 -> V_62 ;
}
static void F_53 ( struct V_2 * V_3 , T_3 V_8 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
V_44 -> V_62 = V_8 ;
}
static int F_54 ( struct V_2 * V_3 , struct V_63 * V_43 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
F_55 ( & V_44 -> V_46 , V_43 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 , struct V_63 * V_43 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
return F_57 ( & V_44 -> V_46 , V_43 ) ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
return F_59 ( & V_44 -> V_46 ) ;
}
static int F_60 ( struct V_2 * V_3 ,
T_4 V_64 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
T_4 V_65 = V_3 -> V_64 ^ V_64 ;
unsigned long V_20 ;
if ( ! ( V_65 & V_66 ) )
return 0 ;
F_33 ( & V_44 -> V_24 , V_20 ) ;
F_6 ( V_44 , V_67 , ( V_64 & V_66 ) ? V_68 : 0 ) ;
F_34 ( & V_44 -> V_24 , V_20 ) ;
return 0 ;
}
static T_3 F_61 ( struct V_2 * V_3 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
T_3 V_22 ;
if ( V_44 -> V_20 & V_69 )
V_22 = F_62 ( & V_44 -> V_46 ) ;
else
V_22 = F_45 ( V_44 , V_70 ) & V_71 ? 1 : 0 ;
return V_22 ;
}
static int F_63 ( struct V_2 * V_3 )
{
return 128 ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_72 * V_73 , T_1 * V_12 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
int V_50 = V_73 -> V_50 ;
int V_74 = V_73 -> V_74 ;
int V_14 ;
if ( ( V_74 & 1 ) != 0 || ( V_50 & 1 ) != 0 )
return - V_45 ;
if ( V_44 -> V_20 & V_52 )
return - V_75 ;
V_73 -> V_76 = V_77 ;
for ( V_14 = 0 ; V_14 < V_74 ; V_14 += 2 )
F_47 ( V_44 , ( V_50 + V_14 ) / 2 , V_12 + V_14 ) ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_72 * V_73 , T_1 * V_12 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
int V_50 = V_73 -> V_50 ;
int V_74 = V_73 -> V_74 ;
int V_78 ;
if ( V_44 -> V_20 & V_52 )
return - V_75 ;
if ( V_73 -> V_76 != V_77 )
return - V_45 ;
while ( V_74 > 0 ) {
if ( V_74 & 1 || V_50 & 1 ) {
int V_79 = V_50 & 1 ;
T_1 V_15 [ 2 ] ;
F_47 ( V_44 , V_50 / 2 , V_15 ) ;
V_15 [ V_79 ] = * V_12 ;
F_48 ( V_44 , V_50 / 2 , V_15 ) ;
V_78 = 1 ;
} else {
F_48 ( V_44 , V_50 / 2 , V_12 ) ;
V_78 = 2 ;
}
V_12 += V_78 ;
V_50 += V_78 ;
V_74 -= V_78 ;
}
return 0 ;
}
static void F_66 ( struct V_2 * V_3 , struct V_80 * V_81 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
memset ( V_81 , 0 , sizeof( struct V_80 ) ) ;
V_81 -> V_82 = V_44 -> V_83 ? V_84 : 0 ;
V_81 -> V_85 = V_44 -> V_86 ;
}
static int F_67 ( struct V_2 * V_3 , struct V_80 * V_81 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
unsigned long V_20 ;
T_3 V_87 = V_81 -> V_85 ;
T_3 V_88 = 0 ;
if ( ! V_44 -> V_83 )
return - V_89 ;
if ( V_87 & ~ V_84 )
return - V_45 ;
if ( V_87 & V_84 )
V_88 |= V_90 ;
F_32 ( & V_44 -> V_23 ) ;
F_33 ( & V_44 -> V_24 , V_20 ) ;
F_6 ( V_44 , V_91 , V_88 ) ;
F_34 ( & V_44 -> V_24 , V_20 ) ;
F_35 ( & V_44 -> V_23 ) ;
if ( V_44 -> V_86 != V_87 ) {
if ( ! V_44 -> V_86 )
F_68 ( V_44 -> V_92 , 1 ) ;
else if ( V_44 -> V_86 && ! V_87 )
F_68 ( V_44 -> V_92 , 0 ) ;
}
V_44 -> V_86 = V_87 ;
return 0 ;
}
static void F_69 ( struct V_1 * V_4 ,
unsigned V_93 , unsigned V_94 )
{
int V_95 ;
struct V_2 * V_96 = V_4 -> V_96 ;
struct V_97 * V_46 = & V_4 -> V_46 ;
unsigned V_98 = F_45 ( V_4 , V_9 ) ;
if ( V_93 ) {
V_95 = V_46 -> V_99 ( V_46 -> V_3 , V_46 -> V_100 , V_101 ) ;
F_70 ( V_4 -> V_3 ,
L_8 ,
V_96 -> V_61 , ( V_94 & V_102 ) ? 10 : 100 ,
( V_98 & V_103 ) ? L_9 : L_10 , V_95 ) ;
} else {
F_70 ( V_4 -> V_3 , L_11 , V_96 -> V_61 ) ;
}
}
static void
F_71 ( struct V_104 * V_81 )
{
struct V_105 * V_106 = F_72 ( V_81 ) ;
struct V_1 * V_4 = F_73 ( V_106 , struct V_1 , V_39 ) ;
struct V_2 * V_96 = V_4 -> V_96 ;
if ( V_4 -> V_20 & V_107 &&
! ( V_4 -> V_20 & V_69 ) ) {
unsigned V_94 = F_45 ( V_4 , V_70 ) ;
unsigned V_108 = F_74 ( V_96 ) ? 1 : 0 ;
unsigned V_109 ;
V_109 = ( V_94 & V_71 ) ? 1 : 0 ;
if ( V_108 != V_109 ) {
if ( F_75 ( V_4 ) )
F_69 ( V_4 , V_109 , V_94 ) ;
if ( ! V_109 )
F_76 ( V_96 ) ;
else
F_77 ( V_96 ) ;
}
} else
F_78 ( & V_4 -> V_46 , F_75 ( V_4 ) , 0 ) ;
if ( F_42 ( V_96 ) )
F_39 ( V_4 ) ;
}
static void
F_79 ( struct V_110 * V_111 , struct V_1 * V_4 )
{
F_80 ( V_4 -> V_6 ) ;
F_80 ( V_4 -> V_7 ) ;
if ( V_4 -> V_112 )
F_81 ( V_4 -> V_112 ) ;
F_82 ( V_4 -> V_112 ) ;
if ( V_4 -> V_113 )
F_81 ( V_4 -> V_113 ) ;
F_82 ( V_4 -> V_113 ) ;
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
F_84 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_117 * V_118 ;
int V_14 , V_119 ;
T_3 V_120 ;
T_5 V_121 [ 4 ] = { 0 , 0 , 0 , 0x8000 } ;
T_1 V_122 = V_123 | V_124 | V_125 ;
F_36 ( V_4 , 1 , L_12 , V_126 ) ;
for ( V_14 = 0 , V_119 = V_127 ; V_14 < 6 ; V_14 ++ , V_119 ++ )
F_6 ( V_4 , V_119 , V_3 -> V_128 [ V_14 ] ) ;
if ( V_3 -> V_20 & V_129 )
V_122 |= V_130 ;
if ( V_3 -> V_20 & V_131 )
V_122 |= V_132 ;
F_85 (ha, dev) {
V_120 = F_86 ( 6 , V_118 -> V_133 ) & 0x3f ;
V_121 [ V_120 / 16 ] |= ( T_5 ) 1 << ( V_120 % 16 ) ;
}
for ( V_14 = 0 , V_119 = V_134 ; V_14 < 4 ; V_14 ++ ) {
F_6 ( V_4 , V_119 ++ , V_121 [ V_14 ] ) ;
F_6 ( V_4 , V_119 ++ , V_121 [ V_14 ] >> 8 ) ;
}
F_6 ( V_4 , V_135 , V_122 ) ;
}
static void
F_87 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned long V_20 ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
F_84 ( V_3 ) ;
F_34 ( & V_4 -> V_24 , V_20 ) ;
}
static void
F_88 ( struct V_1 * V_4 )
{
F_6 ( V_4 , V_136 , V_137 ) ;
}
static void
F_89 ( struct V_1 * V_4 )
{
F_6 ( V_4 , V_136 , V_4 -> V_138 ) ;
}
static void
F_90 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned int V_139 ;
unsigned int V_98 ;
F_36 ( V_4 , 1 , L_12 , V_126 ) ;
F_7 ( V_4 ) ;
F_88 ( V_4 ) ;
V_4 -> V_140 = F_3 ( V_4 , V_141 ) >> 6 ;
if ( V_3 -> V_142 & V_66 )
F_6 ( V_4 , V_67 ,
( V_3 -> V_64 & V_66 ) ? V_68 : 0 ) ;
F_6 ( V_4 , V_143 , V_144 ) ;
F_6 ( V_4 , V_145 , 0 ) ;
if ( V_4 -> type == V_116 ) {
F_37 ( V_3 , 0 , V_146 , V_147 ) ;
F_37 ( V_3 , 0 , V_148 , V_149 ) ;
}
V_98 = ( V_4 -> V_20 & V_69 ) ? V_150 : 0 ;
if ( V_4 -> V_83 )
V_98 |= V_151 ;
F_6 ( V_4 , V_9 , V_98 ) ;
F_6 ( V_4 , V_152 , 0 ) ;
F_6 ( V_4 , V_153 , 0x3f ) ;
F_6 ( V_4 , V_154 , 0xff ) ;
F_6 ( V_4 , V_155 , 0 ) ;
F_6 ( V_4 , V_70 , V_156 | V_157 | V_158 ) ;
F_6 ( V_4 , V_141 , V_159 ) ;
F_84 ( V_3 ) ;
V_139 = V_137 | V_160 | V_161 ;
if ( V_4 -> type != V_38 )
V_139 |= V_162 ;
V_4 -> V_138 = V_139 ;
V_4 -> V_163 = 0 ;
V_4 -> V_164 = 0 ;
V_3 -> V_165 = V_166 ;
}
static void F_91 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
T_1 V_21 ;
unsigned long V_20 ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
V_4 -> V_18 = 1 ;
V_21 = F_5 ( V_4 -> V_6 ) ;
F_92 ( V_3 ) ;
F_90 ( V_3 ) ;
F_89 ( V_4 ) ;
V_3 -> V_165 = V_166 ;
F_93 ( V_3 ) ;
F_4 ( V_21 , V_4 -> V_6 ) ;
V_4 -> V_18 = 0 ;
F_34 ( & V_4 -> V_24 , V_20 ) ;
}
static void F_94 ( struct V_2 * V_3 ,
int V_167 ,
T_5 V_168 )
{
struct V_1 * V_44 = F_1 ( V_3 ) ;
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
F_95 ( struct V_177 * V_178 , struct V_2 * V_3 )
{
unsigned long V_20 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_36 ( V_4 , 3 , L_13 , V_126 ) ;
if ( V_4 -> V_163 > 1 )
return V_179 ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
F_4 ( V_180 , V_4 -> V_6 ) ;
( V_4 -> V_36 ) ( V_4 -> V_7 , V_178 -> V_12 , V_178 -> V_74 ) ;
V_3 -> V_181 . V_182 += V_178 -> V_74 ;
V_4 -> V_163 ++ ;
if ( V_4 -> V_163 == 1 ) {
F_94 ( V_3 , V_178 -> V_167 , V_178 -> V_74 ) ;
} else {
V_4 -> V_164 = V_178 -> V_74 ;
V_4 -> V_183 = V_178 -> V_167 ;
F_92 ( V_3 ) ;
}
F_34 ( & V_4 -> V_24 , V_20 ) ;
F_96 ( V_178 ) ;
return V_184 ;
}
static void F_97 ( struct V_2 * V_3 , struct V_1 * V_4 )
{
int V_185 = F_3 ( V_4 , V_70 ) ;
if ( V_185 & ( V_157 | V_158 ) ) {
V_4 -> V_163 -- ;
V_3 -> V_181 . V_186 ++ ;
if ( F_98 ( V_4 ) )
F_8 ( V_4 -> V_3 , L_14 , V_185 ) ;
if ( V_4 -> V_163 > 0 )
F_94 ( V_3 , V_4 -> V_183 ,
V_4 -> V_164 ) ;
F_93 ( V_3 ) ;
}
}
static void
F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_187 V_188 ;
struct V_177 * V_178 ;
T_1 V_189 , * V_190 ;
bool V_191 ;
int V_192 ;
do {
F_3 ( V_4 , V_193 ) ;
V_189 = F_5 ( V_4 -> V_7 ) ;
if ( V_189 & V_194 ) {
F_100 ( V_4 -> V_3 , L_15 , V_189 ) ;
F_6 ( V_4 , V_135 , 0x00 ) ;
return;
}
if ( ! ( V_189 & V_195 ) )
return;
V_191 = true ;
F_4 ( V_196 , V_4 -> V_6 ) ;
( V_4 -> V_37 ) ( V_4 -> V_7 , & V_188 , sizeof( V_188 ) ) ;
V_192 = F_101 ( V_188 . V_192 ) ;
if ( F_102 ( V_4 ) )
F_8 ( V_4 -> V_3 , L_16 ,
V_188 . V_197 , V_192 ) ;
if ( V_192 < 0x40 ) {
V_191 = false ;
if ( F_103 ( V_4 ) )
F_8 ( V_4 -> V_3 , L_17 ) ;
}
if ( V_192 > V_198 ) {
F_8 ( V_4 -> V_3 , L_18 , V_192 ) ;
}
if ( V_188 . V_197 & ( V_199 | V_200 | V_201 |
V_202 | V_203 |
V_204 | V_205 ) ) {
V_191 = false ;
if ( V_188 . V_197 & V_199 ) {
if ( F_103 ( V_4 ) )
F_8 ( V_4 -> V_3 , L_19 ) ;
V_3 -> V_181 . V_206 ++ ;
}
if ( V_188 . V_197 & V_200 ) {
if ( F_103 ( V_4 ) )
F_8 ( V_4 -> V_3 , L_20 ) ;
V_3 -> V_181 . V_207 ++ ;
}
if ( V_188 . V_197 & V_205 ) {
if ( F_103 ( V_4 ) )
F_8 ( V_4 -> V_3 , L_21 ) ;
V_3 -> V_181 . V_208 ++ ;
}
}
if ( V_191 &&
( ( V_178 = F_104 ( V_3 , V_192 + 4 ) ) != NULL ) ) {
F_105 ( V_178 , 2 ) ;
V_190 = ( T_1 * ) F_106 ( V_178 , V_192 - 4 ) ;
( V_4 -> V_37 ) ( V_4 -> V_7 , V_190 , V_192 ) ;
V_3 -> V_181 . V_209 += V_192 ;
V_178 -> V_210 = F_107 ( V_178 , V_3 ) ;
if ( V_3 -> V_64 & V_66 ) {
if ( ( ( ( V_189 & 0x1c ) << 3 ) & V_189 ) == 0 )
V_178 -> V_167 = V_211 ;
else
F_108 ( V_178 ) ;
}
F_109 ( V_178 ) ;
V_3 -> V_181 . V_212 ++ ;
} else {
( V_4 -> V_35 ) ( V_4 -> V_7 , V_192 ) ;
}
} while ( V_189 & V_195 );
}
static T_6 F_110 ( int V_213 , void * V_214 )
{
struct V_2 * V_3 = V_214 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
int V_215 ;
unsigned long V_20 ;
T_1 V_21 ;
F_36 ( V_4 , 3 , L_12 , V_126 ) ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
V_21 = F_5 ( V_4 -> V_6 ) ;
F_88 ( V_4 ) ;
V_215 = F_3 ( V_4 , V_141 ) ;
F_6 ( V_4 , V_141 , V_215 ) ;
if ( F_111 ( V_4 ) )
F_8 ( V_4 -> V_3 , L_22 , V_215 ) ;
if ( V_215 & V_216 )
F_99 ( V_3 ) ;
if ( V_215 & V_217 )
F_97 ( V_3 , V_4 ) ;
if ( V_4 -> type != V_38 ) {
if ( V_215 & V_218 ) {
F_40 ( & V_4 -> V_39 , 1 ) ;
}
}
F_89 ( V_4 ) ;
F_4 ( V_21 , V_4 -> V_6 ) ;
F_34 ( & V_4 -> V_24 , V_20 ) ;
return V_219 ;
}
static T_6 F_112 ( int V_213 , void * V_214 )
{
struct V_2 * V_3 = V_214 ;
struct V_1 * V_4 = F_2 ( V_3 ) ;
unsigned long V_20 ;
unsigned V_94 , V_88 ;
F_33 ( & V_4 -> V_24 , V_20 ) ;
V_94 = F_3 ( V_4 , V_70 ) ;
V_88 = F_3 ( V_4 , V_91 ) ;
F_8 ( V_4 -> V_3 , L_23 , V_126 , V_94 , V_88 ) ;
if ( V_94 & V_156 ) {
F_6 ( V_4 , V_70 , V_156 ) ;
if ( V_88 & V_220 )
F_70 ( V_4 -> V_3 , L_24 ) ;
if ( V_88 & V_221 )
F_70 ( V_4 -> V_3 , L_25 ) ;
if ( V_88 & V_222 )
F_70 ( V_4 -> V_3 , L_26 ) ;
if ( ! ( V_88 & ( V_220 | V_221 | V_222 ) ) )
F_10 ( V_4 -> V_3 , L_27
L_28 , V_94 , V_88 ) ;
}
F_34 ( & V_4 -> V_24 , V_20 ) ;
return ( V_94 & V_156 ) ? V_219 : V_223 ;
}
static void F_113 ( struct V_2 * V_3 )
{
F_114 ( V_3 -> V_213 ) ;
F_110 ( V_3 -> V_213 , V_3 ) ;
F_115 ( V_3 -> V_213 ) ;
}
static int
F_116 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
if ( F_117 ( V_4 ) )
F_8 ( V_4 -> V_3 , L_29 , V_3 -> V_61 ) ;
if ( F_118 ( V_3 -> V_213 ) == V_224 )
F_100 ( V_4 -> V_3 , L_30 ) ;
F_6 ( V_4 , V_145 , 0 ) ;
F_29 ( 1 ) ;
F_90 ( V_3 ) ;
if ( F_119 ( V_3 -> V_213 , F_110 , V_225 ,
V_3 -> V_61 , V_3 ) )
return - V_226 ;
F_89 ( V_4 ) ;
V_4 -> V_227 = 0 ;
F_78 ( & V_4 -> V_46 , F_75 ( V_4 ) , 1 ) ;
F_120 ( V_3 ) ;
F_40 ( & V_4 -> V_39 , 1 ) ;
return 0 ;
}
static void
F_121 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
F_37 ( V_3 , 0 , V_146 , V_147 ) ;
F_6 ( V_4 , V_145 , 0x01 ) ;
F_88 ( V_4 ) ;
F_6 ( V_4 , V_135 , 0x00 ) ;
}
static int
F_122 ( struct V_2 * V_96 )
{
struct V_1 * V_4 = F_2 ( V_96 ) ;
if ( F_123 ( V_4 ) )
F_8 ( V_4 -> V_3 , L_31 , V_96 -> V_61 ) ;
F_124 ( & V_4 -> V_39 ) ;
F_92 ( V_96 ) ;
F_76 ( V_96 ) ;
F_125 ( V_96 -> V_213 , V_96 ) ;
F_121 ( V_96 ) ;
return 0 ;
}
static struct V_228 * F_126 ( struct V_229 * V_3 )
{
struct V_228 * V_230 ;
struct V_231 * V_232 = V_3 -> V_233 ;
const void * V_234 ;
if ( ! F_127 ( V_235 ) || ! V_232 )
return F_128 ( - V_236 ) ;
V_230 = F_129 ( V_3 , sizeof( * V_230 ) , V_237 ) ;
if ( ! V_230 )
return F_128 ( - V_238 ) ;
if ( F_130 ( V_232 , L_32 , NULL ) )
V_230 -> V_20 |= V_69 ;
if ( F_130 ( V_232 , L_33 , NULL ) )
V_230 -> V_20 |= V_52 ;
V_234 = F_131 ( V_232 ) ;
if ( V_234 )
memcpy ( V_230 -> V_128 , V_234 , sizeof( V_230 -> V_128 ) ) ;
return V_230 ;
}
static int
F_132 ( struct V_110 * V_111 )
{
struct V_228 * V_230 = F_133 ( & V_111 -> V_3 ) ;
struct V_1 * V_4 ;
struct V_2 * V_96 ;
struct V_229 * V_3 = & V_111 -> V_3 ;
const unsigned char * V_239 ;
int V_22 = 0 ;
int V_240 ;
int V_14 ;
T_3 V_241 ;
int V_242 ;
enum V_243 V_20 ;
struct V_244 * V_245 ;
V_245 = F_134 ( V_3 , L_34 ) ;
if ( F_135 ( V_245 ) ) {
if ( F_136 ( V_245 ) == - V_246 )
return - V_246 ;
F_8 ( V_3 , L_35 ) ;
} else {
V_22 = F_137 ( V_245 ) ;
if ( V_22 != 0 ) {
F_10 ( V_3 ,
L_36 , V_22 ) ;
return V_22 ;
}
F_8 ( V_3 , L_37 ) ;
}
V_242 = F_138 ( V_3 -> V_233 , L_38 , 0 ,
& V_20 ) ;
if ( F_139 ( V_242 ) ) {
V_22 = F_140 ( V_3 , V_242 , V_20 ,
L_39 ) ;
if ( V_22 ) {
F_10 ( V_3 , L_40 ,
V_242 , V_22 ) ;
return - V_247 ;
}
F_30 ( 2 ) ;
F_141 ( V_242 , 1 ) ;
F_30 ( 4 ) ;
}
if ( ! V_230 ) {
V_230 = F_126 ( & V_111 -> V_3 ) ;
if ( F_135 ( V_230 ) )
return F_136 ( V_230 ) ;
}
V_96 = F_142 ( sizeof( struct V_1 ) ) ;
if ( ! V_96 )
return - V_238 ;
F_143 ( V_96 , & V_111 -> V_3 ) ;
F_8 ( & V_111 -> V_3 , L_41 ) ;
V_4 = F_2 ( V_96 ) ;
V_4 -> V_3 = & V_111 -> V_3 ;
V_4 -> V_96 = V_96 ;
F_144 ( & V_4 -> V_24 ) ;
F_145 ( & V_4 -> V_23 ) ;
F_146 ( & V_4 -> V_39 , F_71 ) ;
V_4 -> V_248 = F_147 ( V_111 , V_249 , 0 ) ;
V_4 -> V_250 = F_147 ( V_111 , V_249 , 1 ) ;
if ( ! V_4 -> V_248 || ! V_4 -> V_250 ) {
F_10 ( V_4 -> V_3 , L_42 ,
V_4 -> V_248 , V_4 -> V_250 ) ;
V_22 = - V_75 ;
goto V_251;
}
V_96 -> V_213 = F_148 ( V_111 , 0 ) ;
if ( V_96 -> V_213 < 0 ) {
F_10 ( V_4 -> V_3 , L_43 ,
V_96 -> V_213 ) ;
V_22 = V_96 -> V_213 ;
goto V_251;
}
V_4 -> V_92 = F_148 ( V_111 , 1 ) ;
if ( V_4 -> V_92 >= 0 ) {
F_8 ( V_4 -> V_3 , L_44 , V_4 -> V_92 ) ;
V_22 = F_119 ( V_4 -> V_92 , F_112 ,
V_225 , F_149 ( V_4 -> V_3 ) , V_96 ) ;
if ( V_22 ) {
F_10 ( V_4 -> V_3 , L_45 , V_22 ) ;
} else {
V_22 = F_68 ( V_4 -> V_92 , 1 ) ;
if ( V_22 ) {
F_10 ( V_4 -> V_3 , L_46 ,
V_4 -> V_92 , V_22 ) ;
V_22 = 0 ;
} else {
F_68 ( V_4 -> V_92 , 0 ) ;
V_4 -> V_83 = 1 ;
}
}
}
V_240 = F_150 ( V_4 -> V_248 ) ;
V_4 -> V_113 = F_151 ( V_4 -> V_248 -> V_252 , V_240 ,
V_111 -> V_61 ) ;
if ( V_4 -> V_113 == NULL ) {
F_10 ( V_4 -> V_3 , L_47 ) ;
V_22 = - V_253 ;
goto V_251;
}
V_4 -> V_6 = F_152 ( V_4 -> V_248 -> V_252 , V_240 ) ;
if ( V_4 -> V_6 == NULL ) {
F_10 ( V_4 -> V_3 , L_48 ) ;
V_22 = - V_45 ;
goto V_251;
}
V_240 = F_150 ( V_4 -> V_250 ) ;
V_4 -> V_112 = F_151 ( V_4 -> V_250 -> V_252 , V_240 ,
V_111 -> V_61 ) ;
if ( V_4 -> V_112 == NULL ) {
F_10 ( V_4 -> V_3 , L_49 ) ;
V_22 = - V_253 ;
goto V_251;
}
V_4 -> V_7 = F_152 ( V_4 -> V_250 -> V_252 , V_240 ) ;
if ( V_4 -> V_7 == NULL ) {
F_10 ( V_4 -> V_3 , L_50 ) ;
V_22 = - V_45 ;
goto V_251;
}
V_96 -> V_254 = ( unsigned long ) V_4 -> V_6 ;
F_38 ( V_4 , V_240 ) ;
if ( V_230 != NULL ) {
if ( V_230 -> V_20 & V_255 )
F_38 ( V_4 , 1 ) ;
if ( V_230 -> V_20 & V_256 )
F_38 ( V_4 , 2 ) ;
if ( V_230 -> V_20 & V_257 )
F_38 ( V_4 , 4 ) ;
if ( V_230 -> V_37 != NULL )
V_4 -> V_37 = V_230 -> V_37 ;
if ( V_230 -> V_36 != NULL )
V_4 -> V_36 = V_230 -> V_36 ;
if ( V_230 -> V_35 != NULL )
V_4 -> V_35 = V_230 -> V_35 ;
V_4 -> V_20 = V_230 -> V_20 ;
}
#ifdef F_153
V_4 -> V_20 |= V_107 ;
#endif
F_7 ( V_4 ) ;
for ( V_14 = 0 ; V_14 < 8 ; V_14 ++ ) {
V_241 = F_3 ( V_4 , V_258 ) ;
V_241 |= ( T_3 ) F_3 ( V_4 , V_259 ) << 8 ;
V_241 |= ( T_3 ) F_3 ( V_4 , V_260 ) << 16 ;
V_241 |= ( T_3 ) F_3 ( V_4 , V_261 ) << 24 ;
if ( V_241 == V_262 )
break;
F_10 ( V_4 -> V_3 , L_51 , V_241 ) ;
}
if ( V_241 != V_262 ) {
F_10 ( V_4 -> V_3 , L_52 , V_241 ) ;
V_22 = - V_247 ;
goto V_251;
}
V_241 = F_3 ( V_4 , V_263 ) ;
F_8 ( V_4 -> V_3 , L_53 , V_241 ) ;
switch ( V_241 ) {
case V_264 :
V_4 -> type = V_115 ;
break;
case V_265 :
V_4 -> type = V_116 ;
break;
default:
F_8 ( V_4 -> V_3 , L_54 , V_241 ) ;
V_4 -> type = V_38 ;
}
if ( V_4 -> type == V_115 || V_4 -> type == V_116 ) {
V_96 -> V_142 = V_66 | V_266 ;
V_96 -> V_64 |= V_96 -> V_142 ;
}
V_96 -> V_267 = & V_268 ;
V_96 -> V_269 = F_154 ( V_270 ) ;
V_96 -> V_271 = & V_272 ;
V_4 -> V_62 = V_273 ;
V_4 -> V_46 . V_274 = 0x1f ;
V_4 -> V_46 . V_275 = 0x1f ;
V_4 -> V_46 . V_276 = 0 ;
V_4 -> V_46 . V_277 = 0 ;
V_4 -> V_46 . V_3 = V_96 ;
V_4 -> V_46 . V_99 = F_31 ;
V_4 -> V_46 . V_278 = F_37 ;
V_239 = L_55 ;
for ( V_14 = 0 ; V_14 < 6 ; V_14 += 2 )
F_47 ( V_4 , V_14 / 2 , V_96 -> V_128 + V_14 ) ;
if ( ! F_155 ( V_96 -> V_128 ) && V_230 != NULL ) {
V_239 = L_56 ;
memcpy ( V_96 -> V_128 , V_230 -> V_128 , V_279 ) ;
}
if ( ! F_155 ( V_96 -> V_128 ) ) {
V_239 = L_57 ;
for ( V_14 = 0 ; V_14 < 6 ; V_14 ++ )
V_96 -> V_128 [ V_14 ] = F_3 ( V_4 , V_14 + V_127 ) ;
}
if ( ! F_155 ( V_96 -> V_128 ) ) {
F_100 ( V_4 -> V_3 , L_58
L_59 , V_96 -> V_61 ) ;
F_156 ( V_96 ) ;
V_239 = L_60 ;
}
F_157 ( V_111 , V_96 ) ;
V_22 = F_158 ( V_96 ) ;
if ( V_22 == 0 )
F_159 ( V_280 L_61 ,
V_96 -> V_61 , F_83 ( V_4 -> type ) ,
V_4 -> V_6 , V_4 -> V_7 , V_96 -> V_213 ,
V_96 -> V_128 , V_239 ) ;
return 0 ;
V_251:
F_10 ( V_4 -> V_3 , L_62 , V_22 ) ;
F_79 ( V_111 , V_4 ) ;
F_160 ( V_96 ) ;
return V_22 ;
}
static int
F_161 ( struct V_229 * V_3 )
{
struct V_110 * V_111 = F_51 ( V_3 ) ;
struct V_2 * V_96 = F_162 ( V_111 ) ;
struct V_1 * V_4 ;
if ( V_96 ) {
V_4 = F_2 ( V_96 ) ;
V_4 -> V_17 = 1 ;
if ( ! F_42 ( V_96 ) )
return 0 ;
F_163 ( V_96 ) ;
if ( ! V_4 -> V_86 )
F_121 ( V_96 ) ;
}
return 0 ;
}
static int
F_164 ( struct V_229 * V_3 )
{
struct V_110 * V_111 = F_51 ( V_3 ) ;
struct V_2 * V_96 = F_162 ( V_111 ) ;
struct V_1 * V_4 = F_2 ( V_96 ) ;
if ( V_96 ) {
if ( F_42 ( V_96 ) ) {
if ( ! V_4 -> V_86 ) {
F_90 ( V_96 ) ;
F_89 ( V_4 ) ;
}
F_165 ( V_96 ) ;
}
V_4 -> V_17 = 0 ;
}
return 0 ;
}
static int
F_166 ( struct V_110 * V_111 )
{
struct V_2 * V_96 = F_162 ( V_111 ) ;
F_167 ( V_96 ) ;
F_79 ( V_111 , F_2 ( V_96 ) ) ;
F_160 ( V_96 ) ;
F_8 ( & V_111 -> V_3 , L_63 ) ;
return 0 ;
}
