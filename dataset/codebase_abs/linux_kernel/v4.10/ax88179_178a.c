static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 , int V_8 )
{
int V_9 ;
int (* F_2)( struct V_1 * , T_1 , T_1 , T_2 , T_2 , void * , T_2 );
F_3 ( ! V_2 ) ;
if ( ! V_8 )
F_2 = V_10 ;
else
F_2 = V_11 ;
V_9 = F_2 ( V_2 , V_3 , V_12 | V_13 | V_14 ,
V_4 , V_5 , V_7 , V_6 ) ;
if ( F_4 ( V_9 < 0 ) )
F_5 ( V_2 -> V_15 , L_1 ,
V_5 , V_9 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 , int V_8 )
{
int V_9 ;
int (* F_2)( struct V_1 * , T_1 , T_1 , T_2 , T_2 , const void * , T_2 );
F_3 ( ! V_2 ) ;
if ( ! V_8 )
F_2 = V_16 ;
else
F_2 = V_17 ;
V_9 = F_2 ( V_2 , V_3 , V_18 | V_13 | V_14 ,
V_4 , V_5 , V_7 , V_6 ) ;
if ( F_4 ( V_9 < 0 ) )
F_5 ( V_2 -> V_15 , L_2 ,
V_5 , V_9 ) ;
return V_9 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 , void * V_7 )
{
T_2 V_19 ;
if ( 2 == V_6 ) {
V_19 = * ( ( T_2 * ) V_7 ) ;
F_8 ( & V_19 ) ;
F_9 ( V_2 , V_3 , V_18 | V_13 |
V_14 , V_4 , V_5 , & V_19 ,
V_6 ) ;
} else {
F_9 ( V_2 , V_3 , V_18 | V_13 |
V_14 , V_4 , V_5 , V_7 ,
V_6 ) ;
}
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 , void * V_7 )
{
int V_9 ;
if ( 2 == V_6 ) {
T_2 V_19 ;
V_9 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , & V_19 , 1 ) ;
F_11 ( & V_19 ) ;
* ( ( T_2 * ) V_7 ) = V_19 ;
} else if ( 4 == V_6 ) {
T_3 V_19 ;
V_9 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , & V_19 , 1 ) ;
F_12 ( & V_19 ) ;
* ( ( T_3 * ) V_7 ) = V_19 ;
} else {
V_9 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 , 1 ) ;
}
return V_9 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 ,
T_2 V_5 , T_2 V_6 , void * V_7 )
{
int V_9 ;
if ( 2 == V_6 ) {
T_2 V_19 ;
V_19 = * ( ( T_2 * ) V_7 ) ;
F_8 ( & V_19 ) ;
V_9 = F_6 ( V_2 , V_3 , V_4 , V_5 ,
V_6 , & V_19 , 1 ) ;
} else {
V_9 = F_6 ( V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 , 1 ) ;
}
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
int V_9 ;
if ( 2 == V_6 ) {
T_2 V_19 ;
V_9 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , & V_19 , 0 ) ;
F_11 ( & V_19 ) ;
* ( ( T_2 * ) V_7 ) = V_19 ;
} else if ( 4 == V_6 ) {
T_3 V_19 ;
V_9 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , & V_19 , 0 ) ;
F_12 ( & V_19 ) ;
* ( ( T_3 * ) V_7 ) = V_19 ;
} else {
V_9 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 , 0 ) ;
}
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_6 , void * V_7 )
{
int V_9 ;
if ( 2 == V_6 ) {
T_2 V_19 ;
V_19 = * ( ( T_2 * ) V_7 ) ;
F_8 ( & V_19 ) ;
V_9 = F_6 ( V_2 , V_3 , V_4 , V_5 ,
V_6 , & V_19 , 0 ) ;
} else {
V_9 = F_6 ( V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 , 0 ) ;
}
return V_9 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_21 * V_22 ;
T_3 V_23 ;
if ( V_20 -> V_24 < 8 )
return;
V_22 = V_20 -> V_25 ;
F_12 ( ( void * ) & V_22 -> V_26 ) ;
V_23 = ( ( ( V_27 T_3 ) V_22 -> V_26 ) & V_28 ) >> 16 ;
if ( F_17 ( V_2 -> V_15 ) != V_23 ) {
F_18 ( V_2 , V_23 , 1 ) ;
F_19 ( V_2 -> V_15 , L_3 , V_23 ) ;
}
}
static int F_20 ( struct V_29 * V_30 , int V_31 , int V_32 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
T_2 V_33 ;
F_14 ( V_2 , V_34 , V_31 , ( V_35 ) V_32 , 2 , & V_33 ) ;
return V_33 ;
}
static void F_22 ( struct V_29 * V_30 , int V_31 , int V_32 ,
int V_36 )
{
struct V_1 * V_2 = F_21 ( V_30 ) ;
T_2 V_33 = ( T_2 ) V_36 ;
F_15 ( V_2 , V_34 , V_31 , ( V_35 ) V_32 , 2 , & V_33 ) ;
}
static inline int F_23 ( struct V_1 * V_2 , T_2 V_37 ,
T_2 V_38 )
{
T_2 V_39 ;
int V_9 ;
V_39 = V_38 ;
V_9 = F_15 ( V_2 , V_34 , V_40 ,
V_41 , 2 , & V_39 ) ;
V_39 = V_37 ;
V_9 = F_15 ( V_2 , V_34 , V_40 ,
V_42 , 2 , & V_39 ) ;
V_39 = V_38 | V_43 ;
V_9 = F_15 ( V_2 , V_34 , V_40 ,
V_41 , 2 , & V_39 ) ;
return V_9 ;
}
static int
F_24 ( struct V_1 * V_2 , T_2 V_37 , T_2 V_38 )
{
int V_9 ;
T_2 V_39 ;
F_23 ( V_2 , V_37 , V_38 ) ;
V_9 = F_14 ( V_2 , V_34 , V_40 ,
V_42 , 2 , & V_39 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_39 ;
}
static int
F_25 ( struct V_1 * V_2 , T_2 V_37 , T_2 V_38 ,
T_2 V_7 )
{
int V_9 ;
F_23 ( V_2 , V_37 , V_38 ) ;
V_9 = F_15 ( V_2 , V_34 , V_40 ,
V_42 , 2 , & V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static int F_26 ( struct V_44 * V_45 , T_4 V_46 )
{
struct V_1 * V_2 = F_27 ( V_45 ) ;
T_2 V_39 ;
T_1 V_47 ;
F_28 ( V_45 , V_46 ) ;
F_10 ( V_2 , V_48 , V_49 ,
2 , 2 , & V_39 ) ;
V_39 &= ~ V_50 ;
F_13 ( V_2 , V_48 , V_49 ,
2 , 2 , & V_39 ) ;
F_10 ( V_2 , V_48 , V_51 ,
2 , 2 , & V_39 ) ;
V_39 |= V_52 | V_53 ;
F_13 ( V_2 , V_48 , V_51 ,
2 , 2 , & V_39 ) ;
V_47 = 0 ;
F_13 ( V_2 , V_48 , V_54 , 1 , 1 , & V_47 ) ;
V_39 = V_55 ;
F_13 ( V_2 , V_48 , V_56 , 2 , 2 , & V_39 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , int V_8 )
{
T_2 V_39 ;
T_1 V_47 ;
int (* F_30)( struct V_1 * , T_1 , T_2 , T_2 , T_2 , void * );
int (* F_31)( struct V_1 * , T_1 , T_2 , T_2 , T_2 , void * );
if ( ! V_8 ) {
F_30 = F_14 ;
F_31 = F_15 ;
} else {
F_30 = F_10 ;
F_31 = F_13 ;
}
if ( F_30 ( V_2 , V_57 , 0x43 , 1 , 2 , & V_39 ) < 0 )
return 0 ;
if ( ( V_39 == 0xFFFF ) || ( ! ( V_39 & 0x0100 ) ) )
return 0 ;
V_47 = 0 ;
F_30 ( V_2 , V_48 , V_54 , 1 , 1 , & V_47 ) ;
V_47 |= V_58 ;
F_31 ( V_2 , V_48 , V_54 , 1 , 1 , & V_47 ) ;
F_30 ( V_2 , V_48 , V_51 , 2 , 2 , & V_39 ) ;
V_39 |= V_59 ;
F_31 ( V_2 , V_48 , V_51 , 2 , 2 , & V_39 ) ;
return 0 ;
}
static int F_32 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_27 ( V_45 ) ;
T_2 V_39 ;
T_1 V_47 ;
F_18 ( V_2 , 0 , 0 ) ;
V_39 = 0 ;
F_13 ( V_2 , V_48 , V_51 ,
2 , 2 , & V_39 ) ;
F_33 ( 1000 ) ;
V_39 = V_53 ;
F_13 ( V_2 , V_48 , V_51 ,
2 , 2 , & V_39 ) ;
F_34 ( 200 ) ;
F_29 ( V_2 , 1 ) ;
F_10 ( V_2 , V_48 , V_54 , 1 , 1 , & V_47 ) ;
V_47 |= V_60 | V_61 ;
F_13 ( V_2 , V_48 , V_54 , 1 , 1 , & V_47 ) ;
F_34 ( 100 ) ;
V_39 = V_62 | V_63 | V_64 |
V_65 | V_66 | V_67 ;
F_13 ( V_2 , V_48 , V_56 , 2 , 2 , & V_39 ) ;
return F_35 ( V_45 ) ;
}
static void
F_36 ( struct V_29 * V_15 , struct V_68 * V_69 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
T_1 V_70 ;
if ( F_14 ( V_2 , V_48 , V_71 ,
1 , 1 , & V_70 ) < 0 ) {
V_69 -> V_72 = 0 ;
V_69 -> V_73 = 0 ;
return;
}
V_69 -> V_72 = V_74 | V_75 ;
V_69 -> V_73 = 0 ;
if ( V_70 & V_76 )
V_69 -> V_73 |= V_74 ;
if ( V_70 & V_77 )
V_69 -> V_73 |= V_75 ;
}
static int
F_37 ( struct V_29 * V_15 , struct V_68 * V_69 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
T_1 V_70 = 0 ;
if ( V_69 -> V_73 & V_74 )
V_70 |= V_76 ;
if ( V_69 -> V_73 & V_75 )
V_70 |= V_77 ;
if ( F_15 ( V_2 , V_48 , V_71 ,
1 , 1 , & V_70 ) < 0 )
return - V_78 ;
return 0 ;
}
static int F_38 ( struct V_29 * V_15 )
{
return V_79 ;
}
static int
F_39 ( struct V_29 * V_15 , struct V_80 * V_81 ,
T_1 * V_7 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
T_2 * V_82 ;
int V_83 , V_84 ;
int V_85 , V_9 ;
if ( V_81 -> V_86 == 0 )
return - V_78 ;
V_81 -> V_87 = V_88 ;
V_83 = V_81 -> V_89 >> 1 ;
V_84 = ( V_81 -> V_89 + V_81 -> V_86 - 1 ) >> 1 ;
V_82 = F_40 ( sizeof( T_2 ) * ( V_84 - V_83 + 1 ) ,
V_90 ) ;
if ( ! V_82 )
return - V_91 ;
for ( V_85 = V_83 ; V_85 <= V_84 ; V_85 ++ ) {
V_9 = F_1 ( V_2 , V_57 , V_85 , 1 , 2 ,
& V_82 [ V_85 - V_83 ] ,
0 ) ;
if ( V_9 < 0 ) {
F_41 ( V_82 ) ;
return - V_92 ;
}
}
memcpy ( V_7 , ( T_1 * ) V_82 + ( V_81 -> V_89 & 1 ) , V_81 -> V_86 ) ;
F_41 ( V_82 ) ;
return 0 ;
}
static int F_42 ( struct V_29 * V_15 , struct V_93 * V_3 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
return F_43 ( & V_2 -> V_94 , V_3 ) ;
}
static int F_44 ( struct V_29 * V_15 , struct V_93 * V_3 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
return F_45 ( & V_2 -> V_94 , V_3 ) ;
}
static int
F_46 ( struct V_1 * V_2 , struct V_95 * V_7 )
{
int V_36 ;
V_36 = F_24 ( V_2 , V_96 ,
V_97 ) ;
if ( V_36 < 0 )
return V_36 ;
V_7 -> V_72 = F_47 ( V_36 ) ;
V_36 = F_24 ( V_2 , V_98 ,
V_99 ) ;
if ( V_36 < 0 )
return V_36 ;
V_7 -> V_100 = F_48 ( V_36 ) ;
V_36 = F_24 ( V_2 , V_101 ,
V_99 ) ;
if ( V_36 < 0 )
return V_36 ;
V_7 -> V_102 = F_48 ( V_36 ) ;
return 0 ;
}
static int
F_49 ( struct V_1 * V_2 , struct V_95 * V_7 )
{
T_2 V_39 = F_50 ( V_7 -> V_100 ) ;
return F_25 ( V_2 , V_98 ,
V_99 , V_39 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_93 V_103 = { . V_3 = V_104 } ;
struct V_105 * V_106 = (struct V_105 * ) V_2 -> V_7 ;
F_43 ( & V_2 -> V_94 , & V_103 ) ;
if ( V_103 . V_107 & V_108 ) {
int V_109 , V_110 , V_111 ;
T_3 V_112 , V_113 , V_114 , V_72 = 0 ;
V_110 = F_24 ( V_2 ,
V_96 ,
V_97 ) ;
if ( V_110 < 0 ) {
V_106 -> V_115 = 0 ;
return false ;
}
V_113 = F_47 ( V_110 ) ;
if ( ! V_113 ) {
V_106 -> V_115 = 0 ;
return false ;
}
V_109 = F_24 ( V_2 ,
V_101 ,
V_99 ) ;
if ( V_109 < 0 ) {
V_106 -> V_115 = 0 ;
return false ;
}
V_111 = F_24 ( V_2 ,
V_98 ,
V_99 ) ;
if ( V_111 < 0 ) {
V_106 -> V_115 = 0 ;
return false ;
}
V_114 = F_48 ( V_111 ) ;
V_112 = F_48 ( V_109 ) ;
V_72 = ( V_103 . V_116 == V_117 ) ?
V_118 :
V_119 ;
if ( ! ( V_112 & V_114 & V_72 ) ) {
V_106 -> V_115 = 0 ;
return false ;
}
V_106 -> V_115 = 1 ;
return true ;
}
V_106 -> V_115 = 0 ;
return false ;
}
static void F_52 ( struct V_1 * V_2 )
{
T_2 V_39 ;
V_39 = V_120 ;
F_15 ( V_2 , V_34 , V_40 ,
V_121 , 2 , & V_39 ) ;
V_39 = 0x3246 ;
F_15 ( V_2 , V_34 , V_40 ,
V_122 , 2 , & V_39 ) ;
V_39 = V_123 ;
F_15 ( V_2 , V_34 , V_40 ,
V_121 , 2 , & V_39 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
T_2 V_39 ;
V_39 = V_120 ;
F_15 ( V_2 , V_34 , V_40 ,
V_121 , 2 , & V_39 ) ;
V_39 = 0x3247 ;
F_15 ( V_2 , V_34 , V_40 ,
V_122 , 2 , & V_39 ) ;
V_39 = V_124 ;
F_15 ( V_2 , V_34 , V_40 ,
V_121 , 2 , & V_39 ) ;
V_39 = 0x0680 ;
F_15 ( V_2 , V_34 , V_40 ,
V_125 , 2 , & V_39 ) ;
V_39 = V_123 ;
F_15 ( V_2 , V_34 , V_40 ,
V_121 , 2 , & V_39 ) ;
}
static int F_54 ( struct V_29 * V_15 , struct V_95 * V_126 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
struct V_105 * V_106 = (struct V_105 * ) V_2 -> V_7 ;
V_126 -> V_127 = V_106 -> V_127 ;
V_126 -> V_115 = V_106 -> V_115 ;
return F_46 ( V_2 , V_126 ) ;
}
static int F_55 ( struct V_29 * V_15 , struct V_95 * V_126 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
struct V_105 * V_106 = (struct V_105 * ) V_2 -> V_7 ;
int V_9 = - V_128 ;
V_106 -> V_127 = V_126 -> V_127 ;
if ( ! V_106 -> V_127 ) {
F_52 ( V_2 ) ;
} else {
V_106 -> V_127 = F_51 ( V_2 ) ;
if ( ! V_106 -> V_127 )
return - V_128 ;
F_53 ( V_2 ) ;
}
V_9 = F_49 ( V_2 , V_126 ) ;
if ( V_9 )
return V_9 ;
F_56 ( & V_2 -> V_94 ) ;
F_18 ( V_2 , 0 , 0 ) ;
return V_9 ;
}
static int F_57 ( struct V_29 * V_15 , struct V_129 * V_130 , int V_3 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
return F_58 ( & V_2 -> V_94 , F_59 ( V_130 ) , V_3 , NULL ) ;
}
static void F_60 ( struct V_29 * V_15 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
struct V_105 * V_7 = (struct V_105 * ) V_2 -> V_7 ;
T_1 * V_131 = ( ( T_1 * ) V_2 -> V_7 ) + 12 ;
V_7 -> V_132 = ( V_64 | V_67 | V_63 ) ;
if ( V_15 -> V_133 & V_134 ) {
V_7 -> V_132 |= V_135 ;
} else if ( V_15 -> V_133 & V_136 ||
F_61 ( V_15 ) > V_137 ) {
V_7 -> V_132 |= V_66 ;
} else if ( F_62 ( V_15 ) ) {
} else {
T_3 V_138 ;
struct V_139 * V_140 ;
memset ( V_131 , 0 , V_141 ) ;
F_63 (ha, net) {
V_138 = F_64 ( V_142 , V_140 -> V_143 ) >> 26 ;
* ( V_131 + ( V_138 >> 3 ) ) |= ( 1 << ( V_138 & 7 ) ) ;
}
F_7 ( V_2 , V_48 , V_144 ,
V_141 , V_141 ,
V_131 ) ;
V_7 -> V_132 |= V_145 ;
}
F_7 ( V_2 , V_48 , V_56 ,
2 , 2 , & V_7 -> V_132 ) ;
}
static int
F_65 ( struct V_29 * V_15 , T_5 V_146 )
{
T_1 V_147 ;
struct V_1 * V_2 = F_21 ( V_15 ) ;
T_5 V_148 = V_15 -> V_146 ^ V_146 ;
if ( V_148 & V_149 ) {
F_14 ( V_2 , V_48 , V_150 , 1 , 1 , & V_147 ) ;
V_147 ^= V_151 | V_152 ;
F_15 ( V_2 , V_48 , V_150 , 1 , 1 , & V_147 ) ;
}
if ( V_148 & V_153 ) {
F_14 ( V_2 , V_48 , V_150 , 1 , 1 , & V_147 ) ;
V_147 ^= V_154 | V_155 ;
F_15 ( V_2 , V_48 , V_150 , 1 , 1 , & V_147 ) ;
}
if ( V_148 & V_156 ) {
F_14 ( V_2 , V_48 , V_157 , 1 , 1 , & V_147 ) ;
V_147 ^= V_158 | V_159 | V_160 |
V_161 | V_162 ;
F_15 ( V_2 , V_48 , V_157 , 1 , 1 , & V_147 ) ;
}
return 0 ;
}
static int F_66 ( struct V_29 * V_15 , int V_163 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
T_2 V_39 ;
V_15 -> V_164 = V_163 ;
V_2 -> V_165 = V_15 -> V_164 + V_15 -> V_166 ;
if ( V_15 -> V_164 > 1500 ) {
F_14 ( V_2 , V_48 , V_49 ,
2 , 2 , & V_39 ) ;
V_39 |= V_167 ;
F_15 ( V_2 , V_48 , V_49 ,
2 , 2 , & V_39 ) ;
} else {
F_14 ( V_2 , V_48 , V_49 ,
2 , 2 , & V_39 ) ;
V_39 &= ~ V_167 ;
F_15 ( V_2 , V_48 , V_49 ,
2 , 2 , & V_39 ) ;
}
F_67 ( V_2 ) ;
return 0 ;
}
static int F_68 ( struct V_29 * V_15 , void * V_168 )
{
struct V_1 * V_2 = F_21 ( V_15 ) ;
struct V_169 * V_143 = V_168 ;
int V_9 ;
if ( F_69 ( V_15 ) )
return - V_170 ;
if ( ! F_70 ( V_143 -> V_171 ) )
return - V_172 ;
memcpy ( V_15 -> V_173 , V_143 -> V_171 , V_142 ) ;
V_9 = F_15 ( V_2 , V_48 , V_174 , V_142 ,
V_142 , V_15 -> V_173 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
T_1 V_85 , V_19 , V_81 [ 20 ] ;
T_2 V_175 , V_176 = V_177 / 10 ;
unsigned long V_178 ;
for ( V_85 = 0 ; V_85 < 6 ; V_85 ++ ) {
V_19 = V_85 ;
if ( F_15 ( V_2 , V_48 , V_179 ,
1 , 1 , & V_19 ) < 0 )
return - V_78 ;
V_19 = V_180 ;
if ( F_15 ( V_2 , V_48 , V_181 ,
1 , 1 , & V_19 ) < 0 )
return - V_78 ;
V_178 = V_182 + V_176 ;
do {
F_14 ( V_2 , V_48 , V_181 ,
1 , 1 , & V_19 ) ;
if ( F_72 ( V_182 , V_178 ) )
return - V_78 ;
} while ( V_19 & V_183 );
F_1 ( V_2 , V_48 , V_184 ,
2 , 2 , & V_81 [ V_85 * 2 ] , 0 ) ;
if ( ( V_85 == 0 ) && ( V_81 [ 0 ] == 0xFF ) )
return - V_78 ;
}
V_175 = V_81 [ 6 ] + V_81 [ 7 ] + V_81 [ 8 ] + V_81 [ 9 ] ;
V_175 = ( V_175 >> 8 ) + ( V_175 & 0xff ) ;
if ( ( V_175 + V_81 [ 10 ] ) != 0xff )
return - V_78 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , T_2 * V_185 )
{
T_1 V_85 ;
T_1 V_186 [ 64 ] ;
T_2 V_175 = 0 ;
if ( F_14 ( V_2 , V_187 , 0 , 64 , 64 , V_186 ) < 0 )
return - V_78 ;
if ( * V_186 == 0xFF )
return - V_78 ;
for ( V_85 = 0 ; V_85 < 64 ; V_85 ++ )
V_175 = V_175 + V_186 [ V_85 ] ;
while ( V_175 > 255 )
V_175 = ( V_175 & 0x00FF ) + ( ( V_175 >> 8 ) & 0x00FF ) ;
if ( V_175 != 0xFF )
return - V_78 ;
* V_185 = ( V_186 [ 51 ] << 8 ) | V_186 [ 52 ] ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , T_2 * V_188 )
{
T_2 V_189 ;
if ( F_14 ( V_2 , V_57 , 0x3C , 1 , 2 , & V_189 ) < 0 )
return - V_78 ;
V_189 >>= 8 ;
switch ( V_189 ) {
case 0xFF :
V_189 = V_190 | V_191 | V_192 |
V_193 | V_194 | V_195 |
V_196 | V_197 | V_198 ;
break;
case 0xFE :
V_189 = V_190 | V_193 | V_196 | V_198 ;
break;
case 0xFD :
V_189 = V_190 | V_193 | V_196 |
V_195 | V_198 ;
break;
case 0xFC :
V_189 = V_190 | V_199 | V_193 | V_194 |
V_196 | V_195 | V_198 ;
break;
default:
V_189 = V_190 | V_191 | V_192 |
V_193 | V_194 | V_195 |
V_196 | V_197 | V_198 ;
break;
}
* V_188 = V_189 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
T_1 V_200 , V_4 = 0 ;
T_2 V_147 , V_201 , V_202 , V_188 = 0 , V_176 = V_177 / 10 ;
unsigned long V_178 ;
F_14 ( V_2 , V_48 , V_203 , 1 , 1 , & V_4 ) ;
if ( ! ( V_4 & V_204 ) ) {
V_4 = V_205 | V_206 |
V_207 ;
if ( F_15 ( V_2 , V_48 , V_208 ,
1 , 1 , & V_4 ) < 0 )
return - V_78 ;
}
if ( ! F_71 ( V_2 ) ) {
V_4 = 0x42 ;
if ( F_15 ( V_2 , V_48 , V_179 ,
1 , 1 , & V_4 ) < 0 )
return - V_78 ;
V_4 = V_180 ;
if ( F_15 ( V_2 , V_48 , V_181 ,
1 , 1 , & V_4 ) < 0 )
return - V_78 ;
V_178 = V_182 + V_176 ;
do {
F_14 ( V_2 , V_48 , V_181 ,
1 , 1 , & V_4 ) ;
if ( F_72 ( V_182 , V_178 ) )
return - V_78 ;
} while ( V_4 & V_183 );
F_14 ( V_2 , V_48 , V_209 ,
1 , 1 , & V_4 ) ;
V_188 = ( V_4 << 8 ) ;
F_14 ( V_2 , V_48 , V_184 ,
1 , 1 , & V_4 ) ;
V_188 |= V_4 ;
if ( ( V_188 == 0xFFFF ) || ( ( V_188 & V_198 ) == 0 ) )
F_74 ( V_2 , & V_188 ) ;
} else if ( ! F_73 ( V_2 , & V_188 ) ) {
if ( ( V_188 == 0xFFFF ) || ( ( V_188 & V_198 ) == 0 ) )
F_74 ( V_2 , & V_188 ) ;
} else {
F_74 ( V_2 , & V_188 ) ;
}
V_147 = V_210 ;
F_15 ( V_2 , V_34 , V_40 ,
V_121 , 2 , & V_147 ) ;
V_147 = 0x2c ;
F_15 ( V_2 , V_34 , V_40 ,
V_211 , 2 , & V_147 ) ;
F_14 ( V_2 , V_34 , V_40 ,
V_212 , 2 , & V_201 ) ;
F_14 ( V_2 , V_34 , V_40 ,
V_213 , 2 , & V_202 ) ;
V_201 &= V_214 ;
V_202 &= V_215 ;
if ( V_188 & V_190 )
V_201 |= V_216 ;
if ( V_188 & V_199 )
V_201 |= V_217 ;
if ( V_188 & V_194 )
V_201 |= V_218 ;
if ( V_188 & V_219 )
V_202 |= V_220 ;
if ( V_188 & V_191 )
V_202 |= V_221 ;
if ( V_188 & V_195 )
V_202 |= V_222 ;
if ( V_188 & V_223 )
V_202 |= V_224 ;
if ( V_188 & V_192 )
V_202 |= V_225 ;
if ( V_188 & V_196 )
V_202 |= V_226 ;
if ( V_188 & V_227 )
V_202 |= V_228 ;
if ( V_188 & V_193 )
V_202 |= V_229 ;
if ( V_188 & V_197 )
V_202 |= V_230 ;
V_147 = V_201 ;
F_15 ( V_2 , V_34 , V_40 ,
V_212 , 2 , & V_147 ) ;
V_147 = V_202 ;
F_15 ( V_2 , V_34 , V_40 ,
V_213 , 2 , & V_147 ) ;
V_147 = V_123 ;
F_15 ( V_2 , V_34 , V_40 ,
V_121 , 2 , & V_147 ) ;
V_200 = 0 ;
if ( V_188 & V_231 )
V_200 |= 0x01 ;
else if ( ( V_188 & V_232 ) == 0 )
V_200 |= 0x02 ;
if ( V_188 & V_233 )
V_200 |= 0x04 ;
else if ( ( V_188 & V_234 ) == 0 )
V_200 |= 0x08 ;
if ( V_188 & V_235 )
V_200 |= 0x10 ;
else if ( ( V_188 & V_236 ) == 0 )
V_200 |= 0x20 ;
F_15 ( V_2 , V_48 , V_237 , 1 , 1 , & V_200 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
T_1 V_19 [ 5 ] ;
T_2 * V_39 ;
T_1 * V_147 ;
struct V_105 * V_238 = (struct V_105 * ) V_2 -> V_7 ;
struct V_95 V_239 ;
F_77 ( V_2 , V_45 ) ;
V_39 = ( T_2 * ) V_19 ;
V_147 = ( T_1 * ) V_19 ;
memset ( V_238 , 0 , sizeof( * V_238 ) ) ;
* V_39 = 0 ;
F_15 ( V_2 , V_48 , V_51 , 2 , 2 , V_39 ) ;
* V_39 = V_53 ;
F_15 ( V_2 , V_48 , V_51 , 2 , 2 , V_39 ) ;
F_34 ( 200 ) ;
* V_147 = V_60 | V_61 ;
F_15 ( V_2 , V_48 , V_54 , 1 , 1 , V_147 ) ;
F_34 ( 100 ) ;
F_14 ( V_2 , V_48 , V_174 , V_142 ,
V_142 , V_2 -> V_15 -> V_173 ) ;
memcpy ( V_2 -> V_15 -> V_240 , V_2 -> V_15 -> V_173 , V_142 ) ;
memcpy ( V_147 , & V_241 [ 0 ] , 5 ) ;
F_15 ( V_2 , V_48 , V_242 , 5 , 5 , V_147 ) ;
V_2 -> V_243 = 1024 * 20 ;
* V_147 = 0x34 ;
F_15 ( V_2 , V_48 , V_244 , 1 , 1 , V_147 ) ;
* V_147 = 0x52 ;
F_15 ( V_2 , V_48 , V_245 ,
1 , 1 , V_147 ) ;
V_2 -> V_15 -> V_246 = & V_247 ;
V_2 -> V_15 -> V_248 = & V_249 ;
V_2 -> V_15 -> V_250 = 8 ;
V_2 -> V_15 -> V_251 = 4088 ;
V_2 -> V_94 . V_2 = V_2 -> V_15 ;
V_2 -> V_94 . V_252 = F_20 ;
V_2 -> V_94 . V_253 = F_22 ;
V_2 -> V_94 . V_254 = 0xff ;
V_2 -> V_94 . V_255 = 0xff ;
V_2 -> V_94 . V_31 = 0x03 ;
V_2 -> V_94 . V_256 = 1 ;
V_2 -> V_15 -> V_146 |= V_149 | V_153 |
V_156 ;
V_2 -> V_15 -> V_257 |= V_149 | V_153 |
V_156 ;
* V_147 = V_158 | V_159 | V_160 |
V_161 | V_162 ;
F_15 ( V_2 , V_48 , V_157 , 1 , 1 , V_147 ) ;
* V_147 = V_258 | V_151 | V_152 |
V_154 | V_155 ;
F_15 ( V_2 , V_48 , V_150 , 1 , 1 , V_147 ) ;
* V_39 = V_62 | V_63 | V_64 |
V_65 | V_66 | V_67 ;
F_15 ( V_2 , V_48 , V_56 , 2 , 2 , V_39 ) ;
* V_147 = V_259 | V_260 |
V_77 ;
F_15 ( V_2 , V_48 , V_71 , 1 , 1 , V_147 ) ;
* V_39 = V_50 | V_261 |
V_262 | V_263 |
V_264 ;
F_15 ( V_2 , V_48 , V_49 ,
2 , 2 , V_39 ) ;
F_75 ( V_2 ) ;
V_238 -> V_127 = 0 ;
V_238 -> V_115 = 0 ;
F_52 ( V_2 ) ;
F_46 ( V_2 , & V_239 ) ;
V_239 . V_100 = 0 ;
F_49 ( V_2 , & V_239 ) ;
F_56 ( & V_2 -> V_94 ) ;
F_18 ( V_2 , 0 , 0 ) ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
T_2 V_39 ;
V_39 = V_55 ;
F_15 ( V_2 , V_48 , V_56 , 2 , 2 , & V_39 ) ;
V_39 = 0 ;
F_15 ( V_2 , V_48 , V_54 , 1 , 1 , & V_39 ) ;
V_39 = 0 ;
F_15 ( V_2 , V_48 , V_51 , 2 , 2 , & V_39 ) ;
}
static void
F_79 ( struct V_265 * V_266 , T_3 * V_267 )
{
V_266 -> V_268 = V_269 ;
if ( ( * V_267 & V_270 ) ||
( * V_267 & V_271 ) )
return;
if ( ( ( * V_267 & V_272 ) == V_273 ) ||
( ( * V_267 & V_272 ) == V_274 ) )
V_266 -> V_268 = V_275 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_265 * V_266 )
{
struct V_265 * V_276 ;
int V_277 ;
T_3 V_278 ;
T_2 V_279 ;
T_3 * V_267 ;
if ( V_266 -> V_86 < V_2 -> V_15 -> V_166 )
return 0 ;
F_81 ( V_266 , V_266 -> V_86 - 4 ) ;
memcpy ( & V_278 , F_82 ( V_266 ) , 4 ) ;
F_12 ( & V_278 ) ;
V_277 = ( T_2 ) V_278 ;
V_279 = ( T_2 ) ( V_278 >> 16 ) ;
V_267 = ( T_3 * ) ( V_266 -> V_7 + V_279 ) ;
while ( V_277 -- ) {
T_2 V_280 ;
F_12 ( V_267 ) ;
V_280 = ( * V_267 >> 16 ) & 0x1fff ;
if ( ( * V_267 & V_281 ) ||
( * V_267 & V_282 ) ) {
F_83 ( V_266 , ( V_280 + 7 ) & 0xFFF8 ) ;
V_267 ++ ;
continue;
}
if ( V_277 == 0 ) {
F_83 ( V_266 , 2 ) ;
V_266 -> V_86 = V_280 ;
F_84 ( V_266 , V_280 ) ;
V_266 -> V_283 = V_280 + sizeof( struct V_265 ) ;
F_79 ( V_266 , V_267 ) ;
return 1 ;
}
V_276 = F_85 ( V_266 , V_284 ) ;
if ( V_276 ) {
V_276 -> V_86 = V_280 ;
V_276 -> V_7 = V_266 -> V_7 + 2 ;
F_84 ( V_276 , V_280 ) ;
V_276 -> V_283 = V_280 + sizeof( struct V_265 ) ;
F_79 ( V_276 , V_267 ) ;
F_86 ( V_2 , V_276 ) ;
} else {
return 0 ;
}
F_83 ( V_266 , ( V_280 + 7 ) & 0xFFF8 ) ;
V_267 ++ ;
}
return 1 ;
}
static struct V_265 *
F_87 ( struct V_1 * V_2 , struct V_265 * V_266 , T_6 V_133 )
{
T_3 V_285 , V_286 ;
int V_287 = V_2 -> V_288 ;
int V_289 = F_88 ( V_266 ) -> V_290 ;
int V_291 ;
V_285 = V_266 -> V_86 ;
V_286 = V_289 ;
if ( ( ( V_266 -> V_86 + 8 ) % V_287 ) == 0 )
V_286 |= 0x80008000 ;
V_291 = F_89 ( V_266 ) - 8 ;
if ( ( F_90 ( V_266 ) || V_291 < 0 ) &&
F_91 ( V_266 , V_291 < 0 ? 8 : 0 , 0 , V_284 ) ) {
F_92 ( V_266 ) ;
return NULL ;
}
F_93 ( V_266 , 4 ) ;
F_94 ( & V_286 ) ;
F_95 ( V_266 , & V_286 , 4 ) ;
F_93 ( V_266 , 4 ) ;
F_94 ( & V_285 ) ;
F_95 ( V_266 , & V_285 , 4 ) ;
return V_266 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_105 * V_238 = (struct V_105 * ) V_2 -> V_7 ;
T_1 V_147 [ 5 ] , V_292 ;
T_2 V_293 , V_39 , V_176 = V_177 / 10 ;
T_3 V_294 = 0x40000000 ;
unsigned long V_178 ;
V_178 = V_182 + V_176 ;
while ( V_294 & 0x40000000 ) {
V_293 = 0 ;
F_15 ( V_2 , V_48 , V_56 , 2 , 2 , & V_293 ) ;
F_15 ( V_2 , V_48 , V_56 , 2 , 2 ,
& V_238 -> V_132 ) ;
F_14 ( V_2 , 0x81 , 0x8c , 0 , 4 , & V_294 ) ;
if ( F_72 ( V_182 , V_178 ) )
return 0 ;
}
V_293 = V_50 | V_261 |
V_262 ;
F_14 ( V_2 , V_48 , V_295 ,
1 , 1 , & V_292 ) ;
F_14 ( V_2 , V_34 , V_40 ,
V_296 , 2 , & V_39 ) ;
if ( ! ( V_39 & V_297 ) ) {
return 0 ;
} else if ( V_298 == ( V_39 & V_299 ) ) {
V_293 |= V_264 | V_300 ;
if ( V_2 -> V_15 -> V_164 > 1500 )
V_293 |= V_167 ;
if ( V_292 & V_301 )
memcpy ( V_147 , & V_241 [ 0 ] , 5 ) ;
else if ( V_292 & V_302 )
memcpy ( V_147 , & V_241 [ 1 ] , 5 ) ;
else
memcpy ( V_147 , & V_241 [ 3 ] , 5 ) ;
} else if ( V_303 == ( V_39 & V_299 ) ) {
V_293 |= V_304 ;
if ( V_292 & ( V_301 | V_302 ) )
memcpy ( V_147 , & V_241 [ 2 ] , 5 ) ;
else
memcpy ( V_147 , & V_241 [ 3 ] , 5 ) ;
} else {
memcpy ( V_147 , & V_241 [ 3 ] , 5 ) ;
}
F_15 ( V_2 , V_48 , V_242 , 5 , 5 , V_147 ) ;
V_2 -> V_243 = ( 1024 * ( V_147 [ 3 ] + 2 ) ) ;
if ( V_39 & V_305 )
V_293 |= V_263 ;
F_15 ( V_2 , V_48 , V_49 ,
2 , 2 , & V_293 ) ;
V_238 -> V_127 = F_51 ( V_2 ) ;
F_97 ( V_2 -> V_15 ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 )
{
T_1 V_19 [ 5 ] ;
T_2 * V_39 ;
T_1 * V_147 ;
struct V_105 * V_238 = (struct V_105 * ) V_2 -> V_7 ;
struct V_95 V_239 ;
V_39 = ( T_2 * ) V_19 ;
V_147 = ( T_1 * ) V_19 ;
* V_39 = 0 ;
F_15 ( V_2 , V_48 , V_51 , 2 , 2 , V_39 ) ;
* V_39 = V_53 ;
F_15 ( V_2 , V_48 , V_51 , 2 , 2 , V_39 ) ;
F_34 ( 200 ) ;
* V_147 = V_60 | V_61 ;
F_15 ( V_2 , V_48 , V_54 , 1 , 1 , V_147 ) ;
F_34 ( 100 ) ;
F_29 ( V_2 , 0 ) ;
F_14 ( V_2 , V_48 , V_174 , V_142 , V_142 ,
V_2 -> V_15 -> V_173 ) ;
memcpy ( V_2 -> V_15 -> V_240 , V_2 -> V_15 -> V_173 , V_142 ) ;
memcpy ( V_147 , & V_241 [ 0 ] , 5 ) ;
F_15 ( V_2 , V_48 , V_242 , 5 , 5 , V_147 ) ;
V_2 -> V_243 = 1024 * 20 ;
* V_147 = 0x34 ;
F_15 ( V_2 , V_48 , V_244 , 1 , 1 , V_147 ) ;
* V_147 = 0x52 ;
F_15 ( V_2 , V_48 , V_245 ,
1 , 1 , V_147 ) ;
V_2 -> V_15 -> V_146 |= V_149 | V_153 |
V_156 ;
V_2 -> V_15 -> V_257 |= V_149 | V_153 |
V_156 ;
* V_147 = V_158 | V_159 | V_160 |
V_161 | V_162 ;
F_15 ( V_2 , V_48 , V_157 , 1 , 1 , V_147 ) ;
* V_147 = V_258 | V_151 | V_152 |
V_154 | V_155 ;
F_15 ( V_2 , V_48 , V_150 , 1 , 1 , V_147 ) ;
* V_39 = V_62 | V_63 | V_64 |
V_65 | V_66 | V_67 ;
F_15 ( V_2 , V_48 , V_56 , 2 , 2 , V_39 ) ;
* V_147 = V_259 | V_260 |
V_77 ;
F_15 ( V_2 , V_48 , V_71 , 1 , 1 , V_147 ) ;
* V_39 = V_50 | V_261 |
V_262 | V_263 |
V_264 ;
F_15 ( V_2 , V_48 , V_49 ,
2 , 2 , V_39 ) ;
F_75 ( V_2 ) ;
V_238 -> V_127 = 0 ;
V_238 -> V_115 = 0 ;
F_52 ( V_2 ) ;
F_46 ( V_2 , & V_239 ) ;
V_239 . V_100 = 0 ;
F_49 ( V_2 , & V_239 ) ;
F_56 ( & V_2 -> V_94 ) ;
F_18 ( V_2 , 0 , 0 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
T_2 V_39 ;
F_14 ( V_2 , V_48 , V_49 ,
2 , 2 , & V_39 ) ;
V_39 &= ~ V_50 ;
F_15 ( V_2 , V_48 , V_49 ,
2 , 2 , & V_39 ) ;
return 0 ;
}
