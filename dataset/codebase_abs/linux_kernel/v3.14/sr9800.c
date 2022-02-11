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
return V_13 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_34 * V_34 )
{
struct V_35 * V_36 ;
int V_37 ;
if ( V_34 -> V_38 < 8 )
return;
V_36 = V_34 -> V_39 ;
V_37 = V_36 -> V_37 & 0x01 ;
if ( F_25 ( V_2 -> V_16 ) != V_37 ) {
F_26 ( V_2 , V_37 , 1 ) ;
F_27 ( V_2 -> V_16 , L_4 , V_37 ) ;
}
return;
}
static inline int F_28 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_3 ( V_2 , V_41 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_40 < 0 )
F_9 ( V_2 -> V_16 , L_5 ) ;
return V_40 ;
}
static inline int F_29 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_3 ( V_2 , V_42 , 0x0000 , 0 , 0 , NULL ) ;
if ( V_40 < 0 )
F_9 ( V_2 -> V_16 , L_6 ) ;
return V_40 ;
}
static inline int F_30 ( struct V_1 * V_2 )
{
T_1 V_43 [ 2 ] ;
int V_40 ;
V_40 = F_1 ( V_2 , V_44 , 0 , 0 , 2 , V_43 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_7 ,
V_21 , V_40 ) ;
goto V_45;
}
F_27 ( V_2 -> V_16 , L_8 , V_21 ,
* ( ( V_46 * ) V_43 ) ) ;
V_40 = V_43 [ 1 ] ;
V_45:
return V_40 ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_25 )
{
int V_40 ;
V_40 = F_3 ( V_2 , V_47 , V_25 , 0 , 0 , NULL ) ;
if ( V_40 < 0 )
F_9 ( V_2 -> V_16 , L_9 ,
V_40 ) ;
return V_40 ;
}
static T_2 F_32 ( struct V_1 * V_2 )
{
V_46 V_48 ;
int V_40 ;
V_40 = F_1 ( V_2 , V_49 , 0 , 0 , 2 , & V_48 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_10 ,
V_40 ) ;
goto V_45;
}
V_40 = F_33 ( V_48 ) ;
V_45:
return V_40 ;
}
static int F_34 ( struct V_1 * V_2 , T_2 V_50 )
{
int V_40 ;
F_27 ( V_2 -> V_16 , L_11 , V_21 , V_50 ) ;
V_40 = F_3 ( V_2 , V_51 , V_50 , 0 , 0 , NULL ) ;
if ( V_40 < 0 )
F_9 ( V_2 -> V_16 ,
L_12 ,
V_50 , V_40 ) ;
return V_40 ;
}
static T_2 F_35 ( struct V_1 * V_2 )
{
V_46 V_48 ;
int V_40 ;
V_40 = F_1 ( V_2 , V_52 , 0 , 0 , 2 , & V_48 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 ,
L_13 , V_40 ) ;
return V_40 ;
}
return F_33 ( V_48 ) ;
}
static int F_36 ( struct V_1 * V_2 , T_2 V_50 )
{
int V_40 ;
F_27 ( V_2 -> V_16 , L_11 , V_21 , V_50 ) ;
V_40 = F_3 ( V_2 , V_53 , V_50 , 0 , 0 , NULL ) ;
if ( V_40 < 0 )
F_9 ( V_2 -> V_16 ,
L_14 ,
V_50 , V_40 ) ;
return V_40 ;
}
static int F_37 ( struct V_1 * V_2 , T_2 V_4 , int V_54 )
{
int V_40 ;
F_27 ( V_2 -> V_16 , L_15 , V_21 , V_4 ) ;
V_40 = F_3 ( V_2 , V_55 , V_4 , 0 , 0 , NULL ) ;
if ( V_40 < 0 )
F_9 ( V_2 -> V_16 , L_16 ,
V_4 , V_40 ) ;
if ( V_54 )
F_38 ( V_54 ) ;
return V_40 ;
}
static void F_39 ( struct V_56 * V_16 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
struct V_57 * V_7 = (struct V_57 * ) & V_2 -> V_7 ;
T_2 V_58 = V_59 ;
if ( V_16 -> V_25 & V_60 ) {
V_58 |= V_61 ;
} else if ( V_16 -> V_25 & V_62 ||
F_41 ( V_16 ) > V_63 ) {
V_58 |= V_64 ;
} else if ( F_42 ( V_16 ) ) {
} else {
struct V_65 * V_66 ;
V_18 V_67 ;
memset ( V_7 -> V_68 , 0 , V_69 ) ;
F_43 (ha, net) {
V_67 = F_44 ( V_70 , V_66 -> V_71 ) >> 26 ;
V_7 -> V_68 [ V_67 >> 3 ] |=
1 << ( V_67 & 7 ) ;
}
F_5 ( V_2 , V_72 , 0 , 0 ,
V_69 , V_7 -> V_68 ) ;
V_58 |= V_73 ;
}
F_5 ( V_2 , V_51 , V_58 , 0 , 0 , NULL ) ;
}
static int F_45 ( struct V_56 * V_16 , int V_74 , int V_75 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
V_46 V_76 ;
F_46 ( & V_2 -> V_77 ) ;
F_28 ( V_2 ) ;
F_1 ( V_2 , V_78 , V_74 , ( V_79 ) V_75 , 2 , & V_76 ) ;
F_29 ( V_2 ) ;
F_47 ( & V_2 -> V_77 ) ;
F_27 ( V_2 -> V_16 ,
L_17 , V_21 ,
V_74 , V_75 , F_33 ( V_76 ) ) ;
return F_33 ( V_76 ) ;
}
static void
F_48 ( struct V_56 * V_16 , int V_74 , int V_75 , int V_80 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
V_46 V_76 = F_49 ( V_80 ) ;
F_27 ( V_2 -> V_16 ,
L_18 , V_21 ,
V_74 , V_75 , V_80 ) ;
F_46 ( & V_2 -> V_77 ) ;
F_28 ( V_2 ) ;
F_3 ( V_2 , V_81 , V_74 , ( V_79 ) V_75 , 2 , & V_76 ) ;
F_29 ( V_2 ) ;
F_47 ( & V_2 -> V_77 ) ;
}
static V_18 F_50 ( struct V_1 * V_2 )
{
int V_82 ;
V_18 V_74 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < 100 ; V_83 ++ ) {
V_82 = F_45 ( V_2 -> V_16 , V_2 -> V_84 . V_74 , V_85 ) ;
if ( V_82 != 0 && V_82 != 0xFFFF )
break;
F_51 ( 1 ) ;
}
if ( V_82 <= 0 || V_82 == 0xFFFF )
return 0 ;
V_74 = ( V_82 & 0xffff ) << 16 ;
V_82 = F_45 ( V_2 -> V_16 , V_2 -> V_84 . V_74 , V_86 ) ;
if ( V_82 < 0 )
return 0 ;
V_74 |= ( V_82 & 0xffff ) ;
return V_74 ;
}
static void
F_52 ( struct V_56 * V_16 , struct V_87 * V_88 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
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
F_53 ( struct V_56 * V_16 , struct V_87 * V_88 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
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
static int F_54 ( struct V_56 * V_16 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
struct V_57 * V_7 = (struct V_57 * ) & V_2 -> V_7 ;
return V_7 -> V_98 ;
}
static int F_55 ( struct V_56 * V_16 ,
struct V_99 * V_100 , T_1 * V_7 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
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
static void F_56 ( struct V_56 * V_16 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
struct V_57 * V_7 = (struct V_57 * ) & V_2 -> V_7 ;
F_57 ( V_16 , V_106 ) ;
strncpy ( V_106 -> V_107 , V_108 , sizeof( V_106 -> V_107 ) ) ;
strncpy ( V_106 -> V_109 , V_110 , sizeof( V_106 -> V_109 ) ) ;
V_106 -> V_111 = V_7 -> V_98 ;
}
static V_18 F_58 ( struct V_56 * V_16 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
return F_59 ( & V_2 -> V_84 ) ;
}
static int F_60 ( struct V_56 * V_16 , struct V_112 * V_113 , int V_3 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
return F_61 ( & V_2 -> V_84 , F_62 ( V_113 ) , V_3 , NULL ) ;
}
static int F_63 ( struct V_56 * V_16 , void * V_114 )
{
struct V_1 * V_2 = F_40 ( V_16 ) ;
struct V_57 * V_7 = (struct V_57 * ) & V_2 -> V_7 ;
struct V_115 * V_71 = V_114 ;
if ( F_64 ( V_16 ) )
return - V_116 ;
if ( ! F_65 ( V_71 -> V_117 ) )
return - V_118 ;
memcpy ( V_16 -> V_119 , V_71 -> V_117 , V_70 ) ;
memcpy ( V_7 -> V_120 , V_71 -> V_117 , V_70 ) ;
F_5 ( V_2 , V_121 , 0 , 0 , V_70 ,
V_7 -> V_120 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_122 V_123 = { . V_3 = V_124 } ;
T_2 V_50 ;
F_67 ( & V_2 -> V_84 , 1 , 1 ) ;
F_68 ( & V_2 -> V_84 , & V_123 ) ;
V_50 = V_125 ;
if ( F_69 ( & V_123 ) != V_126 )
V_50 &= ~ V_127 ;
if ( V_123 . V_128 != V_129 )
V_50 &= ~ V_130 ;
F_27 ( V_2 -> V_16 , L_19 ,
V_21 , F_69 ( & V_123 ) , V_123 . V_128 , V_50 ) ;
F_36 ( V_2 , V_50 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
T_2 V_58 ;
int V_40 ;
F_48 ( V_2 -> V_16 , V_2 -> V_84 . V_74 , V_131 , V_132 ) ;
F_48 ( V_2 -> V_16 , V_2 -> V_84 . V_74 , V_133 ,
V_134 | V_135 ) ;
F_71 ( & V_2 -> V_84 ) ;
V_40 = F_36 ( V_2 , V_125 ) ;
if ( V_40 < 0 )
goto V_45;
V_40 = F_3 ( V_2 , V_136 ,
V_137 | V_138 ,
V_139 , 0 , NULL ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_16 , L_20 , V_40 ) ;
goto V_45;
}
V_40 = F_34 ( V_2 , V_59 ) ;
if ( V_40 < 0 )
goto V_45;
V_58 = F_32 ( V_2 ) ;
F_27 ( V_2 -> V_16 , L_21 ,
V_58 ) ;
V_58 = F_35 ( V_2 ) ;
F_27 ( V_2 -> V_16 , L_22 ,
V_58 ) ;
return 0 ;
V_45:
return V_40 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_57 * V_7 = (struct V_57 * ) & V_2 -> V_7 ;
int V_40 , V_140 ;
T_2 V_58 ;
V_40 = F_37 ( V_2 ,
V_141 | V_142 | V_143 , 5 ) ;
if ( V_40 < 0 )
goto V_45;
V_140 = ( ( F_30 ( V_2 ) & 0x1f ) == 0x10 ? 1 : 0 ) ;
V_40 = F_3 ( V_2 , V_144 , V_140 , 0 , 0 , NULL ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_16 , L_23 , V_40 ) ;
goto V_45;
}
V_40 = F_31 ( V_2 , V_145 | V_146 ) ;
if ( V_40 < 0 )
goto V_45;
F_38 ( 150 ) ;
V_40 = F_31 ( V_2 , V_147 ) ;
if ( V_40 < 0 )
goto V_45;
F_38 ( 150 ) ;
if ( V_140 ) {
V_40 = F_31 ( V_2 , V_148 ) ;
if ( V_40 < 0 )
goto V_45;
} else {
V_40 = F_31 ( V_2 , V_149 ) ;
if ( V_40 < 0 )
goto V_45;
}
F_38 ( 150 ) ;
V_58 = F_32 ( V_2 ) ;
F_27 ( V_2 -> V_16 , L_24 , V_58 ) ;
V_40 = F_34 ( V_2 , 0x0000 ) ;
if ( V_40 < 0 )
goto V_45;
V_58 = F_32 ( V_2 ) ;
F_27 ( V_2 -> V_16 , L_25 , V_58 ) ;
V_40 = F_31 ( V_2 , V_146 ) ;
if ( V_40 < 0 )
goto V_45;
F_38 ( 150 ) ;
V_40 = F_31 ( V_2 , V_148 | V_146 ) ;
if ( V_40 < 0 )
goto V_45;
F_38 ( 150 ) ;
V_40 = F_70 ( V_2 ) ;
if ( V_40 < 0 )
goto V_45;
memcpy ( V_7 -> V_120 , V_2 -> V_16 -> V_119 , V_70 ) ;
V_40 = F_3 ( V_2 , V_121 , 0 , 0 , V_70 ,
V_7 -> V_120 ) ;
if ( V_40 < 0 )
goto V_45;
return 0 ;
V_45:
return V_40 ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_40 ;
V_40 = F_31 ( V_2 , V_145 | V_148 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_26 , V_40 ) ;
return V_40 ;
}
F_38 ( 20 ) ;
V_40 = F_31 ( V_2 , V_148 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_27 , V_40 ) ;
return V_40 ;
}
F_38 ( 600 ) ;
V_40 = F_31 ( V_2 , V_147 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_28 , V_40 ) ;
return V_40 ;
}
F_38 ( 20 ) ;
V_40 = F_31 ( V_2 , V_148 ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_27 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
struct V_57 * V_7 = (struct V_57 * ) & V_2 -> V_7 ;
T_2 V_152 , V_153 ;
int V_40 , V_140 ;
V_18 V_154 ;
T_2 V_58 ;
V_7 -> V_98 = V_155 ;
F_75 ( V_2 , V_151 ) ;
V_152 = ( V_156 << 8 ) | V_157 ;
V_153 = ( V_156 << 8 ) | V_158 ;
V_40 = F_3 ( V_2 , V_159 , V_152 , V_153 , 0 , NULL ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_29 , V_40 ) ;
goto V_45;
}
V_40 = F_1 ( V_2 , V_160 , 0 , 0 , V_70 ,
V_2 -> V_16 -> V_119 ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_16 , L_30 , V_40 ) ;
return V_40 ;
}
F_27 ( V_2 -> V_16 , L_31 , V_2 -> V_16 -> V_119 ) ;
V_2 -> V_84 . V_2 = V_2 -> V_16 ;
V_2 -> V_84 . V_161 = F_45 ;
V_2 -> V_84 . V_162 = F_48 ;
V_2 -> V_84 . V_163 = 0x1f ;
V_2 -> V_84 . V_164 = 0x1f ;
V_2 -> V_84 . V_74 = F_30 ( V_2 ) ;
V_2 -> V_16 -> V_165 = & V_166 ;
V_2 -> V_16 -> V_167 = & V_168 ;
V_140 = ( ( V_2 -> V_84 . V_74 & 0x1f ) == 0x10 ? 1 : 0 ) ;
V_40 = F_3 ( V_2 , V_144 , V_140 , 0 , 0 , NULL ) ;
if ( V_40 < 0 ) {
F_27 ( V_2 -> V_16 , L_23 , V_40 ) ;
return V_40 ;
}
V_40 = F_73 ( V_2 ) ;
if ( V_40 < 0 )
goto V_45;
V_58 = F_32 ( V_2 ) ;
F_27 ( V_2 -> V_16 , L_24 , V_58 ) ;
V_40 = F_34 ( V_2 , 0x0000 ) ;
if ( V_40 < 0 )
goto V_45;
V_58 = F_32 ( V_2 ) ;
F_27 ( V_2 -> V_16 , L_25 , V_58 ) ;
V_154 = F_50 ( V_2 ) ;
F_27 ( V_2 -> V_16 , L_32 , V_154 ) ;
V_40 = F_70 ( V_2 ) ;
if ( V_40 < 0 )
goto V_45;
if ( V_2 -> V_169 -> V_170 == V_171 ) {
V_40 = F_3 ( V_2 , V_172 ,
V_173 [ V_174 ] . V_175 ,
V_173 [ V_174 ] . V_176 ,
0 , NULL ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_33 , V_40 ) ;
goto V_45;
}
V_2 -> V_177 =
V_173 [ V_174 ] . V_6 ;
} else {
V_40 = F_3 ( V_2 , V_172 ,
V_173 [ V_178 ] . V_175 ,
V_173 [ V_178 ] . V_176 ,
0 , NULL ) ;
if ( V_40 < 0 ) {
F_9 ( V_2 -> V_16 , L_33 , V_40 ) ;
goto V_45;
}
V_2 -> V_177 =
V_173 [ V_178 ] . V_6 ;
}
F_27 ( V_2 -> V_16 , L_34 , V_21 ,
V_2 -> V_177 ) ;
return 0 ;
V_45:
return V_40 ;
}
