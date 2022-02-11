static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
int V_8 ;
V_8 = F_2 ( V_2 , V_3 , V_9 , V_4 , V_5 ,
V_7 , V_6 ) ;
if ( ( V_8 != V_6 ) && ( V_8 >= 0 ) )
V_8 = - V_10 ;
return V_8 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
int V_8 ;
V_8 = F_4 ( V_2 , V_3 , V_11 , V_4 , V_5 ,
V_7 , V_6 ) ;
if ( ( V_8 != V_6 ) && ( V_8 >= 0 ) )
V_8 = - V_10 ;
return V_8 ;
}
static void
F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
F_6 ( V_2 , V_3 , V_11 , V_4 , V_5 , V_7 ,
V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
int V_14 = 0 ;
if ( V_13 -> V_15 < V_2 -> V_16 -> V_17 )
return 0 ;
while ( V_14 + sizeof( V_18 ) < V_13 -> V_15 ) {
struct V_12 * V_19 ;
T_2 V_6 ;
V_18 V_20 = F_8 ( V_13 -> V_7 + V_14 ) ;
V_14 += sizeof( V_18 ) ;
V_6 = ( T_2 ) ( V_20 & 0x7ff ) ;
if ( V_6 != ( ( ~ V_20 >> 16 ) & 0x07ff ) ) {
F_9 ( V_2 -> V_16 , L_1 ,
V_21 ) ;
return 0 ;
}
if ( ( V_6 > V_2 -> V_16 -> V_22 + V_23 + V_24 ) ||
( V_6 + V_14 > V_13 -> V_15 ) ) {
F_9 ( V_2 -> V_16 , L_2 ,
V_21 , V_6 ) ;
return 0 ;
}
V_19 = F_10 ( V_2 -> V_16 , V_6 ) ;
if ( ! V_19 )
return 0 ;
F_11 ( V_19 , V_6 ) ;
memcpy ( V_19 -> V_7 , V_13 -> V_7 + V_14 , V_6 ) ;
F_12 ( V_2 , V_19 ) ;
V_14 += ( V_6 + 1 ) & 0xfffe ;
}
if ( V_13 -> V_15 != V_14 ) {
F_9 ( V_2 -> V_16 , L_3 , V_21 ,
V_13 -> V_15 ) ;
return 0 ;
}
return 1 ;
}
static struct V_12 * F_13 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_3 V_25 )
{
int V_26 = F_14 ( V_13 ) ;
int V_27 = F_15 ( V_13 ) ;
V_18 V_28 = 0xffff0000 ;
V_18 V_29 ;
int V_30 ;
V_30 = ( ( V_13 -> V_15 + 4 ) % ( V_2 -> V_31 - 1 ) ) ? 0 : 4 ;
if ( ( ! F_16 ( V_13 ) ) && ( ( V_26 + V_27 ) >= ( 4 + V_30 ) ) ) {
if ( ( V_26 < 4 ) || ( V_27 < V_30 ) ) {
V_13 -> V_7 = memmove ( V_13 -> V_32 + 4 , V_13 -> V_7 ,
V_13 -> V_15 ) ;
F_17 ( V_13 , V_13 -> V_15 ) ;
}
} else {
struct V_12 * V_33 ;
V_33 = F_18 ( V_13 , 4 , V_30 , V_25 ) ;
F_19 ( V_13 ) ;
V_13 = V_33 ;
if ( ! V_13 )
return NULL ;
}
F_20 ( V_13 , 4 ) ;
V_29 = ( ( ( V_13 -> V_15 - 4 ) ^ 0x0000ffff ) << 16 ) + ( V_13 -> V_15 - 4 ) ;
F_21 ( & V_29 ) ;
F_22 ( V_13 , & V_29 , sizeof( V_29 ) ) ;
if ( V_30 ) {
F_21 ( & V_28 ) ;
memcpy ( F_23 ( V_13 ) , & V_28 , sizeof( V_28 ) ) ;
F_11 ( V_13 , sizeof( V_28 ) ) ;
}
F_24 ( V_13 , 1 , 0 ) ;
return V_13 ;
}
static void F_25 ( struct V_1 * V_2 , struct V_34 * V_34 )
{
struct V_35 * V_36 ;
int V_37 ;
if ( V_34 -> V_38 < 8 )
return;
V_36 = V_34 -> V_39 ;
V_37 = V_36 -> V_37 & 0x01 ;
if ( F_26 ( V_2 -> V_16 ) != V_37 ) {
F_27 ( V_2 , V_37 , 1 ) ;
F_28 ( V_2 -> V_16 , L_4 , V_37 ) ;
}
return;
}
static inline int F_29 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_3 ( V_2 , V_41 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_40 < 0 )
F_9 ( V_2 -> V_16 , L_5 ) ;
return V_40 ;
}
static inline int F_30 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_3 ( V_2 , V_42 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_40 < 0 )
F_9 ( V_2 -> V_16 , L_6 ) ;
return V_40 ;
}
static inline int F_31 ( struct V_1 * V_2 )
{
T_1 V_43 [ 2 ] ;
int V_40 ;
V_40 = F_1 ( V_2 , V_44 , 0 , 0 , 2 , V_43 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_7 ,
V_21 , V_40 ) ;
goto V_45;
}
F_28 ( V_2 -> V_16 , L_8 , V_21 ,
* ( ( V_46 * ) V_43 ) ) ;
V_40 = V_43 [ 1 ] ;
V_45:
return V_40 ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_25 )
{
int V_40 ;
V_40 = F_3 ( V_2 , V_47 , V_25 , 0 , 0 , NULL ) ;
if ( V_40 < 0 )
F_9 ( V_2 -> V_16 , L_9 ,
V_40 ) ;
return V_40 ;
}
static T_2 F_33 ( struct V_1 * V_2 )
{
V_46 V_48 ;
int V_40 ;
V_40 = F_1 ( V_2 , V_49 , 0 , 0 , 2 , & V_48 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_10 ,
V_40 ) ;
goto V_45;
}
V_40 = F_34 ( V_48 ) ;
V_45:
return V_40 ;
}
static int F_35 ( struct V_1 * V_2 , T_2 V_50 )
{
int V_40 ;
F_28 ( V_2 -> V_16 , L_11 , V_21 , V_50 ) ;
V_40 = F_3 ( V_2 , V_51 , V_50 , 0 , 0 , NULL ) ;
if ( V_40 < 0 )
F_9 ( V_2 -> V_16 ,
L_12 ,
V_50 , V_40 ) ;
return V_40 ;
}
static T_2 F_36 ( struct V_1 * V_2 )
{
V_46 V_48 ;
int V_40 ;
V_40 = F_1 ( V_2 , V_52 , 0 , 0 , 2 , & V_48 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 ,
L_13 , V_40 ) ;
return V_40 ;
}
return F_34 ( V_48 ) ;
}
static int F_37 ( struct V_1 * V_2 , T_2 V_50 )
{
int V_40 ;
F_28 ( V_2 -> V_16 , L_11 , V_21 , V_50 ) ;
V_40 = F_3 ( V_2 , V_53 , V_50 , 0 , 0 , NULL ) ;
if ( V_40 < 0 )
F_9 ( V_2 -> V_16 ,
L_14 ,
V_50 , V_40 ) ;
return V_40 ;
}
static int F_38 ( struct V_1 * V_2 , T_2 V_4 , int V_54 )
{
int V_40 ;
F_28 ( V_2 -> V_16 , L_15 , V_21 , V_4 ) ;
V_40 = F_3 ( V_2 , V_55 , V_4 , 0 , 0 , NULL ) ;
if ( V_40 < 0 )
F_9 ( V_2 -> V_16 , L_16 ,
V_4 , V_40 ) ;
if ( V_54 )
F_39 ( V_54 ) ;
return V_40 ;
}
static void F_40 ( struct V_56 * V_16 )
{
struct V_1 * V_2 = F_41 ( V_16 ) ;
struct V_57 * V_7 = (struct V_57 * ) & V_2 -> V_7 ;
T_2 V_58 = V_59 ;
if ( V_16 -> V_25 & V_60 ) {
V_58 |= V_61 ;
} else if ( V_16 -> V_25 & V_62 ||
F_42 ( V_16 ) > V_63 ) {
V_58 |= V_64 ;
} else if ( F_43 ( V_16 ) ) {
} else {
struct V_65 * V_66 ;
V_18 V_67 ;
memset ( V_7 -> V_68 , 0 , V_69 ) ;
F_44 (ha, net) {
V_67 = F_45 ( V_70 , V_66 -> V_71 ) >> 26 ;
V_7 -> V_68 [ V_67 >> 3 ] |=
1 << ( V_67 & 7 ) ;
}
F_5 ( V_2 , V_72 , 0 , 0 ,
V_69 , V_7 -> V_68 ) ;
V_58 |= V_73 ;
}
F_5 ( V_2 , V_51 , V_58 , 0 , 0 , NULL ) ;
}
static int F_46 ( struct V_56 * V_16 , int V_74 , int V_75 )
{
struct V_1 * V_2 = F_41 ( V_16 ) ;
V_46 V_76 ;
F_47 ( & V_2 -> V_77 ) ;
F_29 ( V_2 ) ;
F_1 ( V_2 , V_78 , V_74 , ( V_79 ) V_75 , 2 , & V_76 ) ;
F_30 ( V_2 ) ;
F_48 ( & V_2 -> V_77 ) ;
F_28 ( V_2 -> V_16 ,
L_17 , V_21 ,
V_74 , V_75 , F_34 ( V_76 ) ) ;
return F_34 ( V_76 ) ;
}
static void
F_49 ( struct V_56 * V_16 , int V_74 , int V_75 , int V_80 )
{
struct V_1 * V_2 = F_41 ( V_16 ) ;
V_46 V_76 = F_50 ( V_80 ) ;
F_28 ( V_2 -> V_16 ,
L_18 , V_21 ,
V_74 , V_75 , V_80 ) ;
F_47 ( & V_2 -> V_77 ) ;
F_29 ( V_2 ) ;
F_3 ( V_2 , V_81 , V_74 , ( V_79 ) V_75 , 2 , & V_76 ) ;
F_30 ( V_2 ) ;
F_48 ( & V_2 -> V_77 ) ;
}
static V_18 F_51 ( struct V_1 * V_2 )
{
int V_82 ;
V_18 V_74 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < 100 ; V_83 ++ ) {
V_82 = F_46 ( V_2 -> V_16 , V_2 -> V_84 . V_74 , V_85 ) ;
if ( V_82 != 0 && V_82 != 0xFFFF )
break;
F_52 ( 1 ) ;
}
if ( V_82 <= 0 || V_82 == 0xFFFF )
return 0 ;
V_74 = ( V_82 & 0xffff ) << 16 ;
V_82 = F_46 ( V_2 -> V_16 , V_2 -> V_84 . V_74 , V_86 ) ;
if ( V_82 < 0 )
return 0 ;
V_74 |= ( V_82 & 0xffff ) ;
return V_74 ;
}
static void
F_53 ( struct V_56 * V_16 , struct V_87 * V_88 )
{
struct V_1 * V_2 = F_41 ( V_16 ) ;
T_1 V_89 ;
if ( F_1 ( V_2 , V_90 , 0 , 0 , 1 , & V_89 ) < 0 ) {
V_88 -> V_91 = 0 ;
V_88 -> V_92 = 0 ;
return;
}
V_88 -> V_91 = V_93 | V_94 ;
V_88 -> V_92 = 0 ;
if ( V_89 & V_95 )
V_88 -> V_92 |= V_93 ;
if ( V_89 & V_96 )
V_88 -> V_92 |= V_94 ;
}
static int
F_54 ( struct V_56 * V_16 , struct V_87 * V_88 )
{
struct V_1 * V_2 = F_41 ( V_16 ) ;
T_1 V_89 = 0 ;
if ( V_88 -> V_92 & V_93 )
V_89 |= V_95 ;
if ( V_88 -> V_92 & V_94 )
V_89 |= V_96 ;
if ( F_3 ( V_2 , V_97 ,
V_89 , 0 , 0 , NULL ) < 0 )
return - V_10 ;
return 0 ;
}
static int F_55 ( struct V_56 * V_16 )
{
struct V_1 * V_2 = F_41 ( V_16 ) ;
struct V_57 * V_7 = (struct V_57 * ) & V_2 -> V_7 ;
return V_7 -> V_98 ;
}
static int F_56 ( struct V_56 * V_16 ,
struct V_99 * V_100 , T_1 * V_7 )
{
struct V_1 * V_2 = F_41 ( V_16 ) ;
V_46 * V_101 = ( V_46 * ) V_7 ;
int V_40 ;
int V_83 ;
if ( V_100 -> V_15 % 2 )
return - V_10 ;
V_100 -> V_102 = V_103 ;
for ( V_83 = 0 ; V_83 < V_100 -> V_15 / 2 ; V_83 ++ ) {
V_40 = F_1 ( V_2 , V_104 , V_100 -> V_14 + V_83 ,
0 , 2 , & V_101 [ V_83 ] ) ;
if ( V_40 < 0 )
return - V_10 ;
}
return 0 ;
}
static void F_57 ( struct V_56 * V_16 ,
struct V_105 * V_106 )
{
F_58 ( V_16 , V_106 ) ;
strncpy ( V_106 -> V_107 , V_108 , sizeof( V_106 -> V_107 ) ) ;
strncpy ( V_106 -> V_109 , V_110 , sizeof( V_106 -> V_109 ) ) ;
}
static V_18 F_59 ( struct V_56 * V_16 )
{
struct V_1 * V_2 = F_41 ( V_16 ) ;
return F_60 ( & V_2 -> V_84 ) ;
}
static int F_61 ( struct V_56 * V_16 , struct V_111 * V_112 , int V_3 )
{
struct V_1 * V_2 = F_41 ( V_16 ) ;
return F_62 ( & V_2 -> V_84 , F_63 ( V_112 ) , V_3 , NULL ) ;
}
static int F_64 ( struct V_56 * V_16 , void * V_113 )
{
struct V_1 * V_2 = F_41 ( V_16 ) ;
struct V_57 * V_7 = (struct V_57 * ) & V_2 -> V_7 ;
struct V_114 * V_71 = V_113 ;
if ( F_65 ( V_16 ) )
return - V_115 ;
if ( ! F_66 ( V_71 -> V_116 ) )
return - V_117 ;
memcpy ( V_16 -> V_118 , V_71 -> V_116 , V_70 ) ;
memcpy ( V_7 -> V_119 , V_71 -> V_116 , V_70 ) ;
F_5 ( V_2 , V_120 , 0 , 0 , V_70 ,
V_7 -> V_119 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_121 V_122 = { . V_3 = V_123 } ;
T_2 V_50 ;
F_68 ( & V_2 -> V_84 , 1 , 1 ) ;
F_69 ( & V_2 -> V_84 , & V_122 ) ;
V_50 = V_124 ;
if ( F_70 ( & V_122 ) != V_125 )
V_50 &= ~ V_126 ;
if ( V_122 . V_127 != V_128 )
V_50 &= ~ V_129 ;
F_28 ( V_2 -> V_16 , L_19 ,
V_21 , F_70 ( & V_122 ) , V_122 . V_127 , V_50 ) ;
F_37 ( V_2 , V_50 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
T_2 V_58 ;
int V_40 ;
F_49 ( V_2 -> V_16 , V_2 -> V_84 . V_74 , V_130 , V_131 ) ;
F_49 ( V_2 -> V_16 , V_2 -> V_84 . V_74 , V_132 ,
V_133 | V_134 ) ;
F_72 ( & V_2 -> V_84 ) ;
V_40 = F_37 ( V_2 , V_124 ) ;
if ( V_40 < 0 )
goto V_45;
V_40 = F_3 ( V_2 , V_135 ,
V_136 | V_137 ,
V_138 , 0 , NULL ) ;
if ( V_40 < 0 ) {
F_28 ( V_2 -> V_16 , L_20 , V_40 ) ;
goto V_45;
}
V_40 = F_35 ( V_2 , V_59 ) ;
if ( V_40 < 0 )
goto V_45;
V_58 = F_33 ( V_2 ) ;
F_28 ( V_2 -> V_16 , L_21 ,
V_58 ) ;
V_58 = F_36 ( V_2 ) ;
F_28 ( V_2 -> V_16 , L_22 ,
V_58 ) ;
return 0 ;
V_45:
return V_40 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_57 * V_7 = (struct V_57 * ) & V_2 -> V_7 ;
int V_40 , V_139 ;
T_2 V_58 ;
V_40 = F_38 ( V_2 ,
V_140 | V_141 | V_142 , 5 ) ;
if ( V_40 < 0 )
goto V_45;
V_139 = ( ( F_31 ( V_2 ) & 0x1f ) == 0x10 ? 1 : 0 ) ;
V_40 = F_3 ( V_2 , V_143 , V_139 , 0 , 0 , NULL ) ;
if ( V_40 < 0 ) {
F_28 ( V_2 -> V_16 , L_23 , V_40 ) ;
goto V_45;
}
V_40 = F_32 ( V_2 , V_144 | V_145 ) ;
if ( V_40 < 0 )
goto V_45;
F_39 ( 150 ) ;
V_40 = F_32 ( V_2 , V_146 ) ;
if ( V_40 < 0 )
goto V_45;
F_39 ( 150 ) ;
if ( V_139 ) {
V_40 = F_32 ( V_2 , V_147 ) ;
if ( V_40 < 0 )
goto V_45;
} else {
V_40 = F_32 ( V_2 , V_148 ) ;
if ( V_40 < 0 )
goto V_45;
}
F_39 ( 150 ) ;
V_58 = F_33 ( V_2 ) ;
F_28 ( V_2 -> V_16 , L_24 , V_58 ) ;
V_40 = F_35 ( V_2 , 0x0000 ) ;
if ( V_40 < 0 )
goto V_45;
V_58 = F_33 ( V_2 ) ;
F_28 ( V_2 -> V_16 , L_25 , V_58 ) ;
V_40 = F_32 ( V_2 , V_145 ) ;
if ( V_40 < 0 )
goto V_45;
F_39 ( 150 ) ;
V_40 = F_32 ( V_2 , V_147 | V_145 ) ;
if ( V_40 < 0 )
goto V_45;
F_39 ( 150 ) ;
V_40 = F_71 ( V_2 ) ;
if ( V_40 < 0 )
goto V_45;
memcpy ( V_7 -> V_119 , V_2 -> V_16 -> V_118 , V_70 ) ;
V_40 = F_3 ( V_2 , V_120 , 0 , 0 , V_70 ,
V_7 -> V_119 ) ;
if ( V_40 < 0 )
goto V_45;
return 0 ;
V_45:
return V_40 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_32 ( V_2 , V_144 | V_147 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_26 , V_40 ) ;
return V_40 ;
}
F_39 ( 20 ) ;
V_40 = F_32 ( V_2 , V_147 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_27 , V_40 ) ;
return V_40 ;
}
F_39 ( 600 ) ;
V_40 = F_32 ( V_2 , V_146 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_28 , V_40 ) ;
return V_40 ;
}
F_39 ( 20 ) ;
V_40 = F_32 ( V_2 , V_147 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_27 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_149 * V_150 )
{
struct V_57 * V_7 = (struct V_57 * ) & V_2 -> V_7 ;
T_2 V_151 , V_152 ;
int V_40 , V_139 ;
V_18 V_153 ;
T_2 V_58 ;
V_7 -> V_98 = V_154 ;
F_76 ( V_2 , V_150 ) ;
V_151 = ( V_155 << 8 ) | V_156 ;
V_152 = ( V_155 << 8 ) | V_157 ;
V_40 = F_3 ( V_2 , V_158 , V_151 , V_152 , 0 , NULL ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_29 , V_40 ) ;
goto V_45;
}
V_40 = F_1 ( V_2 , V_159 , 0 , 0 , V_70 ,
V_2 -> V_16 -> V_118 ) ;
if ( V_40 < 0 ) {
F_28 ( V_2 -> V_16 , L_30 , V_40 ) ;
return V_40 ;
}
F_28 ( V_2 -> V_16 , L_31 , V_2 -> V_16 -> V_118 ) ;
V_2 -> V_84 . V_2 = V_2 -> V_16 ;
V_2 -> V_84 . V_160 = F_46 ;
V_2 -> V_84 . V_161 = F_49 ;
V_2 -> V_84 . V_162 = 0x1f ;
V_2 -> V_84 . V_163 = 0x1f ;
V_2 -> V_84 . V_74 = F_31 ( V_2 ) ;
V_2 -> V_16 -> V_164 = & V_165 ;
V_2 -> V_16 -> V_166 = & V_167 ;
V_139 = ( ( V_2 -> V_84 . V_74 & 0x1f ) == 0x10 ? 1 : 0 ) ;
V_40 = F_3 ( V_2 , V_143 , V_139 , 0 , 0 , NULL ) ;
if ( V_40 < 0 ) {
F_28 ( V_2 -> V_16 , L_23 , V_40 ) ;
return V_40 ;
}
V_40 = F_74 ( V_2 ) ;
if ( V_40 < 0 )
goto V_45;
V_58 = F_33 ( V_2 ) ;
F_28 ( V_2 -> V_16 , L_24 , V_58 ) ;
V_40 = F_35 ( V_2 , 0x0000 ) ;
if ( V_40 < 0 )
goto V_45;
V_58 = F_33 ( V_2 ) ;
F_28 ( V_2 -> V_16 , L_25 , V_58 ) ;
V_153 = F_51 ( V_2 ) ;
F_28 ( V_2 -> V_16 , L_32 , V_153 ) ;
V_40 = F_71 ( V_2 ) ;
if ( V_40 < 0 )
goto V_45;
if ( V_2 -> V_168 -> V_169 == V_170 ) {
V_40 = F_3 ( V_2 , V_171 ,
V_172 [ V_173 ] . V_174 ,
V_172 [ V_173 ] . V_175 ,
0 , NULL ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_33 , V_40 ) ;
goto V_45;
}
V_2 -> V_176 =
V_172 [ V_173 ] . V_6 ;
} else {
V_40 = F_3 ( V_2 , V_171 ,
V_172 [ V_177 ] . V_174 ,
V_172 [ V_177 ] . V_175 ,
0 , NULL ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_33 , V_40 ) ;
goto V_45;
}
V_2 -> V_176 =
V_172 [ V_177 ] . V_6 ;
}
F_28 ( V_2 -> V_16 , L_34 , V_21 ,
V_2 -> V_176 ) ;
return 0 ;
V_45:
return V_40 ;
}
