static int T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 ,
T_2 * V_4 )
{
T_2 * V_5 = F_2 ( 4 , V_6 ) ;
int V_7 ;
F_3 ( ! V_2 ) ;
if ( ! V_5 )
return - V_8 ;
V_7 = F_4 ( V_2 -> V_9 , F_5 ( V_2 -> V_9 , 0 ) ,
V_10 ,
V_11 | V_12 | V_13 ,
00 , V_3 , V_5 , 4 , V_14 ) ;
if ( F_6 ( V_7 < 0 ) )
F_7 ( V_2 -> V_15 , L_1 , V_3 ) ;
F_8 ( V_5 ) ;
* V_4 = * V_5 ;
F_9 ( V_5 ) ;
return V_7 ;
}
static int T_1 F_10 ( struct V_1 * V_2 , T_2 V_3 ,
T_2 V_4 )
{
T_2 * V_5 = F_2 ( 4 , V_6 ) ;
int V_7 ;
F_3 ( ! V_2 ) ;
if ( ! V_5 )
return - V_8 ;
* V_5 = V_4 ;
F_11 ( V_5 ) ;
V_7 = F_4 ( V_2 -> V_9 , F_12 ( V_2 -> V_9 , 0 ) ,
V_16 ,
V_17 | V_12 | V_13 ,
00 , V_3 , V_5 , 4 , V_18 ) ;
if ( F_6 ( V_7 < 0 ) )
F_7 ( V_2 -> V_15 , L_2 , V_3 ) ;
F_9 ( V_5 ) ;
return V_7 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_19 )
{
if ( F_14 ( ! V_2 ) )
return - V_20 ;
F_11 ( & V_19 ) ;
return F_4 ( V_2 -> V_9 , F_12 ( V_2 -> V_9 , 0 ) ,
V_21 , V_13 , V_19 , 0 , NULL , 0 ,
V_18 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_19 )
{
if ( F_14 ( ! V_2 ) )
return - V_20 ;
F_11 ( & V_19 ) ;
return F_4 ( V_2 -> V_9 , F_12 ( V_2 -> V_9 , 0 ) ,
V_22 , V_13 , V_19 , 0 , NULL , 0 ,
V_18 ) ;
}
static int T_1 F_16 ( struct V_1 * V_2 )
{
unsigned long V_23 = V_24 ;
T_2 V_25 ;
int V_7 ;
do {
V_7 = F_1 ( V_2 , V_26 , & V_25 ) ;
F_17 ( V_7 , L_3 ) ;
if ( ! ( V_25 & V_27 ) )
return 0 ;
} while ( ! F_18 ( V_24 , V_23 + V_28 ) );
return - V_29 ;
}
static int F_19 ( struct V_30 * V_31 , int V_32 , int V_33 )
{
struct V_1 * V_2 = F_20 ( V_31 ) ;
T_2 V_25 , V_34 ;
int V_7 ;
F_21 ( & V_2 -> V_35 ) ;
V_7 = F_16 ( V_2 ) ;
F_22 ( V_7 , L_4 ) ;
V_32 &= V_2 -> V_36 . V_37 ;
V_33 &= V_2 -> V_36 . V_38 ;
V_34 = ( V_32 << 11 ) | ( V_33 << 6 ) | V_39 | V_27 ;
V_7 = F_10 ( V_2 , V_26 , V_34 ) ;
F_22 ( V_7 , L_5 ) ;
V_7 = F_16 ( V_2 ) ;
F_22 ( V_7 , L_6 , V_33 ) ;
V_7 = F_1 ( V_2 , V_40 , & V_25 ) ;
F_22 ( V_7 , L_7 ) ;
V_7 = ( V_41 ) ( V_25 & 0xFFFF ) ;
V_42:
F_23 ( & V_2 -> V_35 ) ;
return V_7 ;
}
static void F_24 ( struct V_30 * V_31 , int V_32 , int V_33 ,
int V_43 )
{
struct V_1 * V_2 = F_20 ( V_31 ) ;
T_2 V_25 , V_34 ;
int V_7 ;
F_21 ( & V_2 -> V_35 ) ;
V_7 = F_16 ( V_2 ) ;
F_22 ( V_7 , L_8 ) ;
V_25 = V_43 ;
V_7 = F_10 ( V_2 , V_40 , V_25 ) ;
F_22 ( V_7 , L_9 ) ;
V_32 &= V_2 -> V_36 . V_37 ;
V_33 &= V_2 -> V_36 . V_38 ;
V_34 = ( V_32 << 11 ) | ( V_33 << 6 ) | V_44 | V_27 ;
V_7 = F_10 ( V_2 , V_26 , V_34 ) ;
F_22 ( V_7 , L_5 ) ;
V_7 = F_16 ( V_2 ) ;
F_22 ( V_7 , L_10 , V_33 ) ;
V_42:
F_23 ( & V_2 -> V_35 ) ;
}
static int T_1 F_25 ( struct V_1 * V_2 )
{
unsigned long V_23 = V_24 ;
T_2 V_25 ;
int V_7 ;
do {
V_7 = F_1 ( V_2 , V_45 , & V_25 ) ;
F_17 ( V_7 , L_11 ) ;
if ( ! ( V_25 & V_46 ) || ( V_25 & V_47 ) )
break;
F_26 ( 40 ) ;
} while ( ! F_18 ( V_24 , V_23 + V_28 ) );
if ( V_25 & ( V_47 | V_46 ) ) {
F_7 ( V_2 -> V_15 , L_12 ) ;
return - V_29 ;
}
return 0 ;
}
static int T_1 F_27 ( struct V_1 * V_2 )
{
unsigned long V_23 = V_24 ;
T_2 V_25 ;
int V_7 ;
do {
V_7 = F_1 ( V_2 , V_45 , & V_25 ) ;
F_17 ( V_7 , L_11 ) ;
if ( ! ( V_25 & V_46 ) )
return 0 ;
F_26 ( 40 ) ;
} while ( ! F_18 ( V_24 , V_23 + V_28 ) );
F_7 ( V_2 -> V_15 , L_13 ) ;
return - V_29 ;
}
static int F_28 ( struct V_1 * V_2 , T_2 V_48 , T_2 V_49 ,
T_3 * V_4 )
{
T_2 V_25 ;
int V_50 , V_7 ;
F_3 ( ! V_2 ) ;
F_3 ( ! V_4 ) ;
V_7 = F_27 ( V_2 ) ;
if ( V_7 )
return V_7 ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ ) {
V_25 = V_46 | V_51 | ( V_48 & V_52 ) ;
V_7 = F_10 ( V_2 , V_45 , V_25 ) ;
F_17 ( V_7 , L_14 ) ;
V_7 = F_25 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_53 , & V_25 ) ;
F_17 ( V_7 , L_15 ) ;
V_4 [ V_50 ] = V_25 & 0xFF ;
V_48 ++ ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , T_2 V_48 , T_2 V_49 ,
T_3 * V_4 )
{
T_2 V_25 ;
int V_50 , V_7 ;
F_3 ( ! V_2 ) ;
F_3 ( ! V_4 ) ;
V_7 = F_27 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_25 = V_46 | V_54 ;
V_7 = F_10 ( V_2 , V_45 , V_25 ) ;
F_17 ( V_7 , L_16 ) ;
V_7 = F_25 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ ) {
V_25 = V_4 [ V_50 ] ;
V_7 = F_10 ( V_2 , V_53 , V_25 ) ;
F_17 ( V_7 , L_16 ) ;
V_25 = V_46 | V_55 | ( V_48 & V_52 ) ;
V_7 = F_10 ( V_2 , V_45 , V_25 ) ;
F_17 ( V_7 , L_14 ) ;
V_7 = F_25 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_48 ++ ;
}
return 0 ;
}
static void F_30 ( struct V_56 * V_56 )
{
struct V_57 * V_57 = V_56 -> V_58 ;
struct V_1 * V_2 = V_57 -> V_2 ;
int V_59 = V_56 -> V_59 ;
F_31 ( V_59 , L_17 , V_59 ) ;
F_9 ( V_57 ) ;
F_32 ( V_56 ) ;
}
static int T_1 F_33 ( struct V_1 * V_2 , V_41 V_3 ,
T_2 * V_4 )
{
struct V_57 * V_57 ;
int V_59 ;
struct V_56 * V_56 ;
const V_41 V_60 = 4 ;
V_56 = F_34 ( 0 , V_61 ) ;
if ( ! V_56 ) {
F_7 ( V_2 -> V_15 , L_18 ) ;
return - V_8 ;
}
V_57 = F_2 ( sizeof( struct V_57 ) , V_61 ) ;
if ( V_57 == NULL ) {
F_7 ( V_2 -> V_15 , L_19 ) ;
F_32 ( V_56 ) ;
return - V_8 ;
}
V_57 -> V_62 . V_63 =
V_17 | V_12 | V_13 ;
V_57 -> V_62 . V_64 = V_16 ;
V_57 -> V_62 . V_65 = 00 ;
V_57 -> V_62 . V_66 = F_35 ( V_3 ) ;
V_57 -> V_62 . V_67 = F_35 ( V_60 ) ;
F_36 ( V_56 , V_2 -> V_9 , F_12 ( V_2 -> V_9 , 0 ) ,
( void * ) & V_57 -> V_62 , V_4 , V_60 ,
F_30 ,
( void * ) V_57 ) ;
V_59 = F_37 ( V_56 , V_61 ) ;
if ( V_59 < 0 ) {
F_7 ( V_2 -> V_15 , L_20 ,
V_59 ) ;
F_9 ( V_57 ) ;
F_32 ( V_56 ) ;
}
return V_59 ;
}
static unsigned int F_38 ( char V_34 [ V_68 ] )
{
return ( F_39 ( V_68 , V_34 ) >> 26 ) & 0x3f ;
}
static void F_40 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_20 ( V_31 ) ;
struct V_69 * V_70 = (struct V_69 * ) ( V_2 -> V_4 [ 0 ] ) ;
unsigned long V_71 ;
int V_7 ;
V_70 -> V_72 = 0 ;
V_70 -> V_73 = 0 ;
F_41 ( & V_70 -> V_74 , V_71 ) ;
if ( V_2 -> V_15 -> V_71 & V_75 ) {
F_42 ( V_2 , V_76 , V_2 -> V_15 , L_21 ) ;
V_70 -> V_77 |= V_78 ;
V_70 -> V_77 &= ~ ( V_79 | V_80 ) ;
} else if ( V_2 -> V_15 -> V_71 & V_81 ) {
F_42 ( V_2 , V_76 , V_2 -> V_15 , L_22 ) ;
V_70 -> V_77 |= V_79 ;
V_70 -> V_77 &= ~ ( V_78 | V_80 ) ;
} else if ( ! F_43 ( V_2 -> V_15 ) ) {
struct V_82 * V_83 ;
V_70 -> V_77 |= V_80 ;
V_70 -> V_77 &= ~ ( V_78 | V_79 ) ;
F_44 (ha, netdev) {
T_2 V_84 = F_38 ( V_83 -> V_34 ) ;
T_2 V_85 = 0x01 << ( V_84 & 0x1F ) ;
if ( V_84 & 0x20 )
V_70 -> V_72 |= V_85 ;
else
V_70 -> V_73 |= V_85 ;
}
F_42 ( V_2 , V_76 , V_2 -> V_15 , L_23 ,
V_70 -> V_72 , V_70 -> V_73 ) ;
} else {
F_42 ( V_2 , V_76 , V_2 -> V_15 , L_24 ) ;
V_70 -> V_77 &=
~ ( V_78 | V_79 | V_80 ) ;
}
F_45 ( & V_70 -> V_74 , V_71 ) ;
V_7 = F_33 ( V_2 , V_86 , & V_70 -> V_72 ) ;
F_31 ( V_7 , L_25 ) ;
V_7 = F_33 ( V_2 , V_87 , & V_70 -> V_73 ) ;
F_31 ( V_7 , L_26 ) ;
V_7 = F_33 ( V_2 , V_88 , & V_70 -> V_77 ) ;
F_31 ( V_7 , L_27 ) ;
}
static int F_46 ( struct V_1 * V_2 , T_3 V_89 ,
V_41 V_90 , V_41 V_91 )
{
T_2 V_92 , V_93 = 0 ;
int V_7 = F_1 ( V_2 , V_94 , & V_93 ) ;
F_17 ( V_7 , L_28 ) ;
if ( V_89 == V_95 ) {
T_3 V_96 = F_47 ( V_90 , V_91 ) ;
if ( V_96 & V_97 )
V_92 = 0xFFFF0002 ;
else
V_92 = 0 ;
if ( V_96 & V_98 )
V_93 |= 0xF ;
else
V_93 &= ~ 0xF ;
F_42 ( V_2 , V_99 , V_2 -> V_15 , L_29 ,
V_96 & V_97 ? L_30 : L_31 ,
V_96 & V_98 ? L_30 : L_31 ) ;
} else {
F_42 ( V_2 , V_99 , V_2 -> V_15 , L_32 ) ;
V_92 = 0 ;
V_93 |= 0xF ;
}
V_7 = F_10 ( V_2 , V_100 , V_92 ) ;
F_17 ( V_7 , L_33 ) ;
V_7 = F_10 ( V_2 , V_94 , V_93 ) ;
F_17 ( V_7 , L_34 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = (struct V_69 * ) ( V_2 -> V_4 [ 0 ] ) ;
struct V_101 * V_36 = & V_2 -> V_36 ;
struct V_102 V_103 = { . V_104 = V_105 } ;
unsigned long V_71 ;
V_41 V_90 , V_91 ;
int V_7 ;
V_7 = F_19 ( V_2 -> V_15 , V_36 -> V_32 , V_106 ) ;
F_17 ( V_7 , L_35 ) ;
V_7 = F_10 ( V_2 , V_107 , V_108 ) ;
F_17 ( V_7 , L_36 ) ;
F_49 ( V_36 , 1 , 1 ) ;
F_50 ( & V_2 -> V_36 , & V_103 ) ;
V_90 = F_19 ( V_2 -> V_15 , V_36 -> V_32 , V_109 ) ;
V_91 = F_19 ( V_2 -> V_15 , V_36 -> V_32 , V_110 ) ;
F_42 ( V_2 , V_99 , V_2 -> V_15 ,
L_37 ,
F_51 ( & V_103 ) , V_103 . V_89 , V_90 , V_91 ) ;
F_41 ( & V_70 -> V_74 , V_71 ) ;
if ( V_103 . V_89 != V_95 ) {
V_70 -> V_77 &= ~ V_111 ;
V_70 -> V_77 |= V_112 ;
} else {
V_70 -> V_77 &= ~ V_112 ;
V_70 -> V_77 |= V_111 ;
}
F_45 ( & V_70 -> V_74 , V_71 ) ;
V_7 = F_10 ( V_2 , V_88 , V_70 -> V_77 ) ;
F_17 ( V_7 , L_38 ) ;
V_7 = F_46 ( V_2 , V_103 . V_89 , V_90 , V_91 ) ;
F_17 ( V_7 , L_39 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 , struct V_56 * V_56 )
{
T_2 V_113 ;
if ( V_56 -> V_114 != 4 ) {
F_7 ( V_2 -> V_15 , L_40 ,
V_56 -> V_114 ) ;
return;
}
memcpy ( & V_113 , V_56 -> V_115 , 4 ) ;
F_8 ( & V_113 ) ;
F_42 ( V_2 , V_99 , V_2 -> V_15 , L_41 , V_113 ) ;
if ( V_113 & V_116 )
F_53 ( V_2 , V_117 ) ;
else
F_7 ( V_2 -> V_15 , L_42 ,
V_113 ) ;
}
static int F_54 ( struct V_30 * V_31 ,
T_4 V_118 )
{
struct V_1 * V_2 = F_20 ( V_31 ) ;
T_2 V_119 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_120 , & V_119 ) ;
F_17 ( V_7 , L_43 , V_7 ) ;
if ( V_118 & V_121 )
V_119 |= V_122 ;
else
V_119 &= ~ V_122 ;
if ( V_118 & V_123 )
V_119 |= V_124 ;
else
V_119 &= ~ V_124 ;
V_7 = F_10 ( V_2 , V_120 , V_119 ) ;
F_17 ( V_7 , L_44 , V_7 ) ;
F_42 ( V_2 , V_125 , V_2 -> V_15 , L_45 , V_119 ) ;
return 0 ;
}
static int F_55 ( struct V_30 * V_15 )
{
return V_126 ;
}
static int F_56 ( struct V_30 * V_31 ,
struct V_127 * V_128 , T_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_31 ) ;
V_128 -> V_129 = V_130 ;
return F_28 ( V_2 , V_128 -> V_48 , V_128 -> V_131 , V_4 ) ;
}
static int F_57 ( struct V_30 * V_31 ,
struct V_127 * V_128 , T_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_31 ) ;
if ( V_128 -> V_129 != V_130 ) {
F_7 ( V_2 -> V_15 , L_46 ,
V_128 -> V_129 ) ;
return - V_20 ;
}
return F_29 ( V_2 , V_128 -> V_48 , V_128 -> V_131 , V_4 ) ;
}
static int F_58 ( struct V_30 * V_31 )
{
return V_120 - V_132 + 1 ;
}
static void
F_59 ( struct V_30 * V_31 , struct V_133 * V_134 ,
void * V_5 )
{
struct V_1 * V_2 = F_20 ( V_31 ) ;
unsigned int V_50 , V_135 ;
int V_136 ;
T_2 * V_4 = V_5 ;
V_136 = F_1 ( V_2 , V_132 , & V_134 -> V_137 ) ;
if ( V_136 < 0 ) {
F_7 ( V_31 , L_47 ) ;
return;
}
for ( V_50 = V_132 , V_135 = 0 ; V_50 <= V_120 ; V_50 += ( sizeof( T_2 ) ) , V_135 ++ ) {
V_136 = F_1 ( V_2 , V_50 , & V_4 [ V_135 ] ) ;
if ( V_136 < 0 ) {
F_7 ( V_31 , L_48 , V_50 ) ;
return;
}
}
}
static void F_60 ( struct V_30 * V_15 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = F_20 ( V_15 ) ;
struct V_69 * V_70 = (struct V_69 * ) ( V_2 -> V_4 [ 0 ] ) ;
V_139 -> V_140 = V_141 ;
V_139 -> V_142 = V_70 -> V_142 ;
}
static int F_61 ( struct V_30 * V_15 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = F_20 ( V_15 ) ;
struct V_69 * V_70 = (struct V_69 * ) ( V_2 -> V_4 [ 0 ] ) ;
V_70 -> V_142 = V_139 -> V_142 & V_141 ;
return 0 ;
}
static int F_62 ( struct V_30 * V_31 , struct V_143 * V_144 , int V_104 )
{
struct V_1 * V_2 = F_20 ( V_31 ) ;
if ( ! F_63 ( V_31 ) )
return - V_20 ;
return F_64 ( & V_2 -> V_36 , F_65 ( V_144 ) , V_104 , NULL ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
if ( F_28 ( V_2 , V_145 , V_68 ,
V_2 -> V_15 -> V_146 ) == 0 ) {
if ( F_67 ( V_2 -> V_15 -> V_146 ) ) {
F_42 ( V_2 , V_147 , V_2 -> V_15 , L_49 ) ;
return;
}
}
F_68 ( V_2 -> V_15 ) ;
F_42 ( V_2 , V_147 , V_2 -> V_15 , L_50 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
T_2 V_148 = V_2 -> V_15 -> V_146 [ 0 ] | V_2 -> V_15 -> V_146 [ 1 ] << 8 |
V_2 -> V_15 -> V_146 [ 2 ] << 16 | V_2 -> V_15 -> V_146 [ 3 ] << 24 ;
T_2 V_149 = V_2 -> V_15 -> V_146 [ 4 ] | V_2 -> V_15 -> V_146 [ 5 ] << 8 ;
int V_7 ;
V_7 = F_10 ( V_2 , V_150 , V_148 ) ;
F_17 ( V_7 , L_51 , V_7 ) ;
V_7 = F_10 ( V_2 , V_151 , V_149 ) ;
F_17 ( V_7 , L_52 , V_7 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = (struct V_69 * ) ( V_2 -> V_4 [ 0 ] ) ;
unsigned long V_71 ;
int V_7 ;
F_41 ( & V_70 -> V_74 , V_71 ) ;
V_70 -> V_77 |= V_152 ;
F_45 ( & V_70 -> V_74 , V_71 ) ;
V_7 = F_10 ( V_2 , V_88 , V_70 -> V_77 ) ;
F_17 ( V_7 , L_53 , V_7 ) ;
V_7 = F_10 ( V_2 , V_153 , V_154 ) ;
F_17 ( V_7 , L_54 , V_7 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = (struct V_69 * ) ( V_2 -> V_4 [ 0 ] ) ;
unsigned long V_71 ;
int V_7 ;
F_41 ( & V_70 -> V_74 , V_71 ) ;
V_70 -> V_77 |= V_155 ;
F_45 ( & V_70 -> V_74 , V_71 ) ;
V_7 = F_10 ( V_2 , V_88 , V_70 -> V_77 ) ;
F_17 ( V_7 , L_53 , V_7 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_156 , V_7 , V_157 = 0 ;
V_2 -> V_36 . V_2 = V_2 -> V_15 ;
V_2 -> V_36 . V_158 = F_19 ;
V_2 -> V_36 . V_159 = F_24 ;
V_2 -> V_36 . V_37 = 0x1f ;
V_2 -> V_36 . V_38 = 0x1f ;
V_2 -> V_36 . V_32 = V_160 ;
F_24 ( V_2 -> V_15 , V_2 -> V_36 . V_32 , V_161 , V_162 ) ;
do {
F_73 ( 10 ) ;
V_156 = F_19 ( V_2 -> V_15 , V_2 -> V_36 . V_32 , V_161 ) ;
V_157 ++ ;
} while ( ( V_156 & V_162 ) && ( V_157 < 100 ) );
if ( V_157 >= 100 ) {
F_7 ( V_2 -> V_15 , L_55 ) ;
return - V_29 ;
}
F_24 ( V_2 -> V_15 , V_2 -> V_36 . V_32 , V_109 ,
V_163 | V_164 | V_165 |
V_166 ) ;
V_7 = F_19 ( V_2 -> V_15 , V_2 -> V_36 . V_32 , V_106 ) ;
F_17 ( V_7 , L_56 ) ;
F_24 ( V_2 -> V_15 , V_2 -> V_36 . V_32 , V_167 ,
V_168 ) ;
F_74 ( & V_2 -> V_36 ) ;
F_42 ( V_2 , V_147 , V_2 -> V_15 , L_57 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = (struct V_69 * ) ( V_2 -> V_4 [ 0 ] ) ;
T_2 V_119 , V_169 , V_170 ;
int V_7 = 0 , V_157 ;
F_42 ( V_2 , V_147 , V_2 -> V_15 , L_58 ) ;
V_7 = F_10 ( V_2 , V_171 , V_172 ) ;
F_17 ( V_7 , L_59 ) ;
V_157 = 0 ;
do {
F_73 ( 10 ) ;
V_7 = F_1 ( V_2 , V_171 , & V_119 ) ;
F_17 ( V_7 , L_60 , V_7 ) ;
V_157 ++ ;
} while ( ( V_119 & V_172 ) && ( V_157 < 100 ) );
if ( V_157 >= 100 ) {
F_7 ( V_2 -> V_15 , L_61 ) ;
return V_7 ;
}
V_7 = F_10 ( V_2 , V_173 , V_174 ) ;
F_17 ( V_7 , L_62 , V_7 ) ;
V_157 = 0 ;
do {
F_73 ( 10 ) ;
V_7 = F_1 ( V_2 , V_173 , & V_119 ) ;
F_17 ( V_7 , L_63 , V_7 ) ;
V_157 ++ ;
} while ( ( V_119 & V_174 ) && ( V_157 < 100 ) );
if ( V_157 >= 100 ) {
F_7 ( V_2 -> V_15 , L_64 ) ;
return V_7 ;
}
V_7 = F_69 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
F_42 ( V_2 , V_147 , V_2 -> V_15 ,
L_65 , V_2 -> V_15 -> V_146 ) ;
V_7 = F_1 ( V_2 , V_171 , & V_119 ) ;
F_17 ( V_7 , L_60 , V_7 ) ;
F_42 ( V_2 , V_147 , V_2 -> V_15 ,
L_66 , V_119 ) ;
V_119 |= V_175 ;
V_7 = F_10 ( V_2 , V_171 , V_119 ) ;
F_17 ( V_7 , L_67 ) ;
V_7 = F_1 ( V_2 , V_171 , & V_119 ) ;
F_17 ( V_7 , L_60 , V_7 ) ;
F_42 ( V_2 , V_147 , V_2 -> V_15 ,
L_68 ,
V_119 ) ;
if ( ! V_176 ) {
V_170 = 0 ;
V_2 -> V_177 = V_178 ;
} else if ( V_2 -> V_9 -> V_179 == V_180 ) {
V_170 = V_181 / V_182 ;
V_2 -> V_177 = V_181 ;
} else {
V_170 = V_183 / V_184 ;
V_2 -> V_177 = V_183 ;
}
F_42 ( V_2 , V_147 , V_2 -> V_15 ,
L_69 , ( V_185 ) V_2 -> V_177 ) ;
V_7 = F_10 ( V_2 , V_186 , V_170 ) ;
F_17 ( V_7 , L_70 , V_7 ) ;
V_7 = F_1 ( V_2 , V_186 , & V_119 ) ;
F_17 ( V_7 , L_71 , V_7 ) ;
F_42 ( V_2 , V_147 , V_2 -> V_15 ,
L_72 ,
V_119 ) ;
V_7 = F_10 ( V_2 , V_187 , V_188 ) ;
F_17 ( V_7 , L_73 , V_7 ) ;
V_7 = F_1 ( V_2 , V_187 , & V_119 ) ;
F_17 ( V_7 , L_74 , V_7 ) ;
F_42 ( V_2 , V_147 , V_2 -> V_15 ,
L_75 ,
V_119 ) ;
V_7 = F_1 ( V_2 , V_171 , & V_119 ) ;
F_17 ( V_7 , L_60 , V_7 ) ;
F_42 ( V_2 , V_147 , V_2 -> V_15 ,
L_76 , V_119 ) ;
if ( V_176 )
V_119 |= ( V_189 | V_190 ) ;
V_119 &= ~ V_191 ;
V_119 |= V_192 << 9 ;
V_7 = F_10 ( V_2 , V_171 , V_119 ) ;
F_17 ( V_7 , L_77 , V_7 ) ;
V_7 = F_1 ( V_2 , V_171 , & V_119 ) ;
F_17 ( V_7 , L_60 , V_7 ) ;
F_42 ( V_2 , V_147 , V_2 -> V_15 ,
L_78 , V_119 ) ;
V_7 = F_10 ( V_2 , V_107 , V_108 ) ;
F_17 ( V_7 , L_79 , V_7 ) ;
V_7 = F_1 ( V_2 , V_132 , & V_119 ) ;
F_17 ( V_7 , L_80 , V_7 ) ;
F_42 ( V_2 , V_147 , V_2 -> V_15 , L_81 , V_119 ) ;
V_169 = V_193 | V_194 |
V_195 ;
V_7 = F_10 ( V_2 , V_196 , V_169 ) ;
F_17 ( V_7 , L_82 , V_7 ) ;
V_7 = F_10 ( V_2 , V_100 , 0 ) ;
F_17 ( V_7 , L_83 , V_7 ) ;
V_7 = F_10 ( V_2 , V_94 , V_197 ) ;
F_17 ( V_7 , L_84 , V_7 ) ;
V_7 = F_1 ( V_2 , V_88 , & V_70 -> V_77 ) ;
F_17 ( V_7 , L_85 , V_7 ) ;
V_7 = F_10 ( V_2 , V_198 , ( T_2 ) V_199 ) ;
F_17 ( V_7 , L_86 , V_7 ) ;
V_7 = F_54 ( V_2 -> V_15 , V_2 -> V_15 -> V_118 ) ;
F_17 ( V_7 , L_87 ) ;
F_40 ( V_2 -> V_15 ) ;
V_7 = F_72 ( V_2 ) ;
F_17 ( V_7 , L_88 ) ;
V_7 = F_1 ( V_2 , V_200 , & V_119 ) ;
F_17 ( V_7 , L_89 , V_7 ) ;
V_119 |= V_201 ;
V_7 = F_10 ( V_2 , V_200 , V_119 ) ;
F_17 ( V_7 , L_90 , V_7 ) ;
V_7 = F_70 ( V_2 ) ;
F_17 ( V_7 , L_91 ) ;
V_7 = F_71 ( V_2 ) ;
F_17 ( V_7 , L_92 ) ;
F_42 ( V_2 , V_147 , V_2 -> V_15 , L_93 ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_202 * V_203 )
{
struct V_69 * V_70 = NULL ;
int V_7 ;
F_77 (KERN_INFO SMSC_CHIPNAME L_94 SMSC_DRIVER_VERSION L_95 ) ;
V_7 = F_78 ( V_2 , V_203 ) ;
F_17 ( V_7 , L_96 , V_7 ) ;
V_2 -> V_4 [ 0 ] = ( unsigned long ) F_79 ( sizeof( struct V_69 ) ,
V_6 ) ;
V_70 = (struct V_69 * ) ( V_2 -> V_4 [ 0 ] ) ;
if ( ! V_70 ) {
F_7 ( V_2 -> V_15 , L_97 ) ;
return - V_8 ;
}
F_80 ( & V_70 -> V_74 ) ;
if ( V_204 )
V_2 -> V_15 -> V_118 |= V_121 ;
if ( V_205 )
V_2 -> V_15 -> V_118 |= V_123 ;
V_2 -> V_15 -> V_206 = V_121 | V_123 ;
F_66 ( V_2 ) ;
V_7 = F_75 ( V_2 ) ;
V_2 -> V_15 -> V_207 = & V_208 ;
V_2 -> V_15 -> V_209 = & V_210 ;
V_2 -> V_15 -> V_71 |= V_211 ;
V_2 -> V_15 -> V_212 += V_213 ;
V_2 -> V_214 = V_2 -> V_15 -> V_215 + V_2 -> V_15 -> V_212 ;
return 0 ;
}
static void F_81 ( struct V_1 * V_2 , struct V_202 * V_203 )
{
struct V_69 * V_70 = (struct V_69 * ) ( V_2 -> V_4 [ 0 ] ) ;
if ( V_70 ) {
F_42 ( V_2 , V_216 , V_2 -> V_15 , L_98 ) ;
F_9 ( V_70 ) ;
V_70 = NULL ;
V_2 -> V_4 [ 0 ] = 0 ;
}
}
static int F_82 ( struct V_202 * V_203 , T_5 V_217 )
{
struct V_1 * V_2 = F_83 ( V_203 ) ;
struct V_69 * V_70 = (struct V_69 * ) ( V_2 -> V_4 [ 0 ] ) ;
int V_7 ;
T_2 V_25 ;
V_7 = F_84 ( V_203 , V_217 ) ;
F_17 ( V_7 , L_99 ) ;
if ( ! ( V_70 -> V_142 & V_141 ) ) {
F_85 ( V_2 -> V_15 , L_100 ) ;
V_7 = F_1 ( V_2 , V_218 , & V_25 ) ;
F_17 ( V_7 , L_101 ) ;
V_25 &= ~ ( V_219 | V_220 ) ;
V_7 = F_10 ( V_2 , V_218 , V_25 ) ;
F_17 ( V_7 , L_102 ) ;
V_7 = F_1 ( V_2 , V_173 , & V_25 ) ;
F_17 ( V_7 , L_103 ) ;
V_25 &= ~ ( V_221 | V_222 ) ;
V_7 = F_10 ( V_2 , V_173 , V_25 ) ;
F_17 ( V_7 , L_104 ) ;
V_7 = F_1 ( V_2 , V_173 , & V_25 ) ;
F_17 ( V_7 , L_103 ) ;
V_25 &= ~ ( V_223 | V_224 | V_174 ) ;
V_25 |= V_225 ;
V_7 = F_10 ( V_2 , V_173 , V_25 ) ;
F_17 ( V_7 , L_104 ) ;
return 0 ;
}
if ( V_70 -> V_142 & V_226 ) {
V_7 = F_1 ( V_2 , V_218 , & V_25 ) ;
F_17 ( V_7 , L_101 ) ;
V_25 |= V_227 ;
V_7 = F_10 ( V_2 , V_218 , V_25 ) ;
F_17 ( V_7 , L_102 ) ;
}
V_7 = F_1 ( V_2 , V_218 , & V_25 ) ;
F_17 ( V_7 , L_101 ) ;
if ( V_70 -> V_142 & V_226 ) {
F_85 ( V_2 -> V_15 , L_105 ) ;
V_25 |= V_219 ;
} else {
F_85 ( V_2 -> V_15 , L_106 ) ;
V_25 &= ~ V_219 ;
}
V_7 = F_10 ( V_2 , V_218 , V_25 ) ;
F_17 ( V_7 , L_102 ) ;
V_7 = F_1 ( V_2 , V_173 , & V_25 ) ;
F_17 ( V_7 , L_103 ) ;
V_25 |= V_222 ;
V_7 = F_10 ( V_2 , V_173 , V_25 ) ;
F_17 ( V_7 , L_104 ) ;
F_71 ( V_2 ) ;
F_85 ( V_2 -> V_15 , L_107 ) ;
V_7 = F_1 ( V_2 , V_173 , & V_25 ) ;
F_17 ( V_7 , L_103 ) ;
V_25 &= ( ~ ( V_223 | V_224 | V_174 ) ) ;
V_25 |= V_228 ;
V_7 = F_10 ( V_2 , V_173 , V_25 ) ;
F_17 ( V_7 , L_104 ) ;
V_25 &= ~ V_224 ;
V_25 |= V_229 ;
V_7 = F_10 ( V_2 , V_173 , V_25 ) ;
F_17 ( V_7 , L_104 ) ;
V_7 = F_1 ( V_2 , V_173 , & V_25 ) ;
F_17 ( V_7 , L_103 ) ;
F_13 ( V_2 , V_230 ) ;
return 0 ;
}
static int F_86 ( struct V_202 * V_203 )
{
struct V_1 * V_2 = F_83 ( V_203 ) ;
struct V_69 * V_70 = (struct V_69 * ) ( V_2 -> V_4 [ 0 ] ) ;
int V_7 ;
T_2 V_25 ;
F_3 ( ! V_2 ) ;
if ( V_70 -> V_142 & V_226 ) {
F_15 ( V_2 , V_230 ) ;
V_7 = F_1 ( V_2 , V_218 , & V_25 ) ;
F_17 ( V_7 , L_101 ) ;
V_25 &= ~ V_219 ;
V_7 = F_10 ( V_2 , V_218 , V_25 ) ;
F_17 ( V_7 , L_102 ) ;
V_7 = F_1 ( V_2 , V_173 , & V_25 ) ;
F_17 ( V_7 , L_103 ) ;
V_25 &= ~ V_222 ;
V_25 |= V_224 ;
V_7 = F_10 ( V_2 , V_173 , V_25 ) ;
F_17 ( V_7 , L_104 ) ;
}
return F_87 ( V_203 ) ;
F_17 ( V_7 , L_108 ) ;
return 0 ;
}
static void F_88 ( struct V_231 * V_232 )
{
V_232 -> V_233 = * ( V_41 * ) ( F_89 ( V_232 ) - 2 ) ;
V_232 -> V_234 = V_235 ;
F_90 ( V_232 , V_232 -> V_131 - 2 ) ;
}
static int F_91 ( struct V_1 * V_2 , struct V_231 * V_232 )
{
while ( V_232 -> V_131 > 0 ) {
T_2 V_236 , V_237 ;
struct V_231 * V_238 ;
unsigned char * V_239 ;
V_41 V_60 ;
memcpy ( & V_236 , V_232 -> V_4 , sizeof( V_236 ) ) ;
F_8 ( & V_236 ) ;
F_92 ( V_232 , 4 + V_192 ) ;
V_239 = V_232 -> V_4 ;
V_60 = ( V_41 ) ( ( V_236 & V_240 ) >> 16 ) ;
V_237 = ( 4 - ( ( V_60 + V_192 ) % 4 ) ) % 4 ;
if ( F_6 ( V_236 & V_241 ) ) {
F_42 ( V_2 , V_242 , V_2 -> V_15 ,
L_109 , V_236 ) ;
V_2 -> V_15 -> V_243 . V_244 ++ ;
V_2 -> V_15 -> V_243 . V_245 ++ ;
if ( V_236 & V_246 ) {
V_2 -> V_15 -> V_243 . V_247 ++ ;
} else {
if ( V_236 & ( V_248 | V_249 ) )
V_2 -> V_15 -> V_243 . V_250 ++ ;
if ( ( V_236 & V_251 ) &&
( ! ( V_236 & V_252 ) ) )
V_2 -> V_15 -> V_243 . V_253 ++ ;
}
} else {
if ( F_6 ( V_60 > ( V_254 + 12 ) ) ) {
F_42 ( V_2 , V_242 , V_2 -> V_15 ,
L_110 , V_236 ) ;
return 0 ;
}
if ( V_232 -> V_131 == V_60 ) {
if ( V_2 -> V_15 -> V_118 & V_123 )
F_88 ( V_232 ) ;
F_90 ( V_232 , V_232 -> V_131 - 4 ) ;
V_232 -> V_255 = V_60 + sizeof( struct V_231 ) ;
return 1 ;
}
V_238 = F_93 ( V_232 , V_61 ) ;
if ( F_6 ( ! V_238 ) ) {
F_7 ( V_2 -> V_15 , L_111 ) ;
return 0 ;
}
V_238 -> V_131 = V_60 ;
V_238 -> V_4 = V_239 ;
F_94 ( V_238 , V_60 ) ;
if ( V_2 -> V_15 -> V_118 & V_123 )
F_88 ( V_238 ) ;
F_90 ( V_238 , V_238 -> V_131 - 4 ) ;
V_238 -> V_255 = V_60 + sizeof( struct V_231 ) ;
F_95 ( V_2 , V_238 ) ;
}
F_92 ( V_232 , V_60 ) ;
if ( V_232 -> V_131 )
F_92 ( V_232 , V_237 ) ;
}
if ( F_6 ( V_232 -> V_131 < 0 ) ) {
F_7 ( V_2 -> V_15 , L_112 , V_232 -> V_131 ) ;
return 0 ;
}
return 1 ;
}
static T_2 F_96 ( struct V_231 * V_232 )
{
V_41 V_256 = ( V_41 ) F_97 ( V_232 ) ;
V_41 V_257 = V_256 + V_232 -> V_258 ;
return ( V_257 << 16 ) | V_256 ;
}
static struct V_231 * F_98 ( struct V_1 * V_2 ,
struct V_231 * V_232 , T_6 V_71 )
{
bool V_233 = V_232 -> V_234 == V_259 ;
int V_260 = V_233 ? V_213 : V_261 ;
T_2 V_262 , V_263 ;
F_3 ( F_99 ( V_232 ) -> V_264 ) ;
if ( F_100 ( V_232 ) < V_260 ) {
struct V_231 * V_265 = F_101 ( V_232 ,
V_260 , 0 , V_71 ) ;
F_102 ( V_232 ) ;
V_232 = V_265 ;
if ( ! V_232 )
return NULL ;
}
if ( V_233 ) {
if ( V_232 -> V_131 <= 45 ) {
long V_266 = F_97 ( V_232 ) ;
T_7 V_267 = F_103 ( V_232 -> V_4 + V_266 ,
V_232 -> V_131 - V_266 , 0 ) ;
* ( ( V_268 * ) ( V_232 -> V_4 + V_266
+ V_232 -> V_258 ) ) = F_104 ( V_267 ) ;
V_233 = false ;
} else {
T_2 V_269 = F_96 ( V_232 ) ;
F_105 ( V_232 , 4 ) ;
F_11 ( & V_269 ) ;
memcpy ( V_232 -> V_4 , & V_269 , 4 ) ;
}
}
F_105 ( V_232 , 4 ) ;
V_263 = ( T_2 ) ( V_232 -> V_131 - 4 ) ;
if ( V_233 )
V_263 |= V_270 ;
F_11 ( & V_263 ) ;
memcpy ( V_232 -> V_4 , & V_263 , 4 ) ;
F_105 ( V_232 , 4 ) ;
V_262 = ( T_2 ) ( V_232 -> V_131 - 8 ) | V_271 |
V_272 ;
F_11 ( & V_262 ) ;
memcpy ( V_232 -> V_4 , & V_262 , 4 ) ;
return V_232 ;
}
