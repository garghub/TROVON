static inline T_1 F_1 ( void T_2 * V_1 )
{
return F_2 ( V_1 ) | ( ( ( T_1 ) F_2 ( V_1 + 4 ) ) << 32LL ) ;
}
static inline void F_3 ( T_1 V_2 , void T_2 * V_1 )
{
F_4 ( ( ( V_3 ) ( V_2 ) ) , ( V_1 ) ) ;
F_4 ( ( ( V_3 ) ( V_2 >> 32 ) ) , ( V_1 + 4 ) ) ;
}
int
F_5 ( struct V_4 * V_5 , int V_6 , V_3 V_7 )
{
int V_8 = 0 , V_9 = 0 ;
while ( ! V_8 ) {
V_8 = F_6 ( V_5 , F_7 ( F_8 ( V_6 ) ) ) ;
if ( V_8 == 1 )
break;
if ( ++ V_9 >= V_10 ) {
F_9 ( & V_5 -> V_11 -> V_12 ,
L_1 ,
V_6 , V_7 ? F_6 ( V_5 , V_7 ) : - 1 ) ;
return - V_13 ;
}
F_10 ( 1 ) ;
}
if ( V_7 )
F_11 ( V_5 , V_7 , V_5 -> V_14 ) ;
return 0 ;
}
void
F_12 ( struct V_4 * V_5 , int V_6 )
{
F_6 ( V_5 , F_7 ( F_13 ( V_6 ) ) ) ;
}
static int
F_14 ( struct V_4 * V_5 ,
struct V_15 * V_16 , int V_17 )
{
V_3 V_18 , V_19 , V_20 ;
struct V_21 * V_22 ;
struct V_15 * V_23 ;
struct V_24 * V_25 ;
V_18 = 0 ;
if ( ! F_15 ( V_26 , & V_5 -> V_27 ) )
return - V_13 ;
V_25 = V_5 -> V_25 ;
F_16 ( V_25 -> V_28 ) ;
V_19 = V_25 -> V_19 ;
V_20 = V_25 -> V_29 ;
if ( V_17 >= F_17 ( V_25 ) ) {
F_18 ( V_25 -> V_28 ) ;
F_19 () ;
if ( F_17 ( V_25 ) > V_17 ) {
if ( F_17 ( V_25 ) > V_30 )
F_20 ( V_25 -> V_28 ) ;
} else {
V_5 -> V_31 . V_32 ++ ;
F_21 ( V_25 -> V_28 ) ;
return - V_33 ;
}
}
do {
V_23 = & V_16 [ V_18 ] ;
V_22 = & V_25 -> V_34 [ V_19 ] ;
V_22 -> V_35 = NULL ;
V_22 -> V_36 = 0 ;
memcpy ( & V_25 -> V_37 [ V_19 ] ,
& V_16 [ V_18 ] , sizeof( struct V_15 ) ) ;
V_19 = F_22 ( V_19 , V_25 -> V_38 ) ;
V_18 ++ ;
} while ( V_18 != V_17 );
V_25 -> V_19 = V_19 ;
F_23 ( V_5 , V_25 ) ;
F_21 ( V_25 -> V_28 ) ;
return 0 ;
}
static int
F_24 ( struct V_4 * V_5 , T_3 * V_1 ,
T_4 V_39 , unsigned V_40 )
{
struct V_41 V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
T_1 V_47 ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 . V_48 = F_25 ( V_49 << 23 ) ;
V_47 = V_50 | ( ( T_1 ) V_5 -> V_14 << 16 ) ;
V_42 . V_51 = F_25 ( V_47 ) ;
V_44 = (struct V_43 * ) & V_42 . V_52 [ 0 ] ;
V_44 -> V_40 = V_40 ;
memcpy ( V_44 -> V_53 , V_1 , 6 ) ;
V_46 = (struct V_45 * ) & V_42 . V_52 [ 1 ] ;
V_46 -> V_39 = V_39 ;
return F_14 ( V_5 , (struct V_15 * ) & V_42 , 1 ) ;
}
static int F_26 ( struct V_4 * V_5 , const T_3 * V_1 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
F_27 (head, &adapter->mac_list) {
V_57 = F_28 ( V_55 , struct V_56 , V_58 ) ;
if ( memcmp ( V_1 , V_57 -> V_53 , V_59 ) == 0 )
return 0 ;
}
V_57 = F_29 ( sizeof( struct V_56 ) , V_60 ) ;
if ( V_57 == NULL ) {
F_9 ( & V_5 -> V_61 -> V_12 ,
L_2 ) ;
return - V_62 ;
}
memcpy ( V_57 -> V_53 , V_1 , V_59 ) ;
if ( F_24 ( V_5 ,
V_57 -> V_53 , 0 , V_63 ) ) {
F_30 ( V_57 ) ;
return - V_13 ;
}
F_31 ( & V_57 -> V_58 , & V_5 -> V_64 ) ;
return 0 ;
}
void F_32 ( struct V_65 * V_61 )
{
struct V_4 * V_5 = F_33 ( V_61 ) ;
struct V_66 * V_67 ;
static const T_3 V_68 [ V_59 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
V_3 V_69 = V_70 ;
if ( ! F_15 ( V_26 , & V_5 -> V_27 ) )
return;
F_26 ( V_5 , V_5 -> V_53 ) ;
F_26 ( V_5 , V_68 ) ;
if ( V_61 -> V_71 & V_72 ) {
if ( ! ( V_5 -> V_71 & V_73 ) )
V_69 = V_74 ;
goto V_75;
}
if ( ( V_61 -> V_71 & V_76 ) ||
( F_34 ( V_61 ) > V_5 -> V_77 ) ) {
V_69 = V_78 ;
goto V_75;
}
if ( ! F_35 ( V_61 ) ) {
F_36 (ha, netdev) {
F_26 ( V_5 , V_67 -> V_1 ) ;
}
}
V_75:
if ( V_69 == V_74 ) {
F_37 ( V_5 ) ;
V_5 -> V_79 = 1 ;
} else {
V_5 -> V_79 = 0 ;
}
F_38 ( V_5 , V_69 ) ;
}
int F_38 ( struct V_4 * V_5 , V_3 V_69 )
{
struct V_41 V_42 ;
T_1 V_47 ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 . V_48 = F_25 ( V_80 << 23 ) ;
V_47 = V_81 |
( ( T_1 ) V_5 -> V_14 << 16 ) ;
V_42 . V_51 = F_25 ( V_47 ) ;
V_42 . V_52 [ 0 ] = F_25 ( V_69 ) ;
return F_14 ( V_5 ,
(struct V_15 * ) & V_42 , 1 ) ;
}
void F_39 ( struct V_4 * V_5 )
{
struct V_56 * V_57 ;
struct V_54 * V_55 = & V_5 -> V_64 ;
while ( ! F_40 ( V_55 ) ) {
V_57 = F_28 ( V_55 -> V_82 , struct V_56 , V_58 ) ;
F_24 ( V_5 ,
V_57 -> V_53 , 0 , V_83 ) ;
F_41 ( & V_57 -> V_58 ) ;
F_30 ( V_57 ) ;
}
}
void F_42 ( struct V_4 * V_5 )
{
struct V_84 * V_85 ;
struct V_86 * V_87 , * V_88 ;
struct V_89 * V_55 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_5 -> V_90 . V_91 ; V_18 ++ ) {
V_55 = & ( V_5 -> V_90 . V_92 [ V_18 ] ) ;
F_43 (tmp_fil, tmp_hnode, n, head, fnode)
{
if ( V_93 >
( V_94 * V_95 + V_85 -> V_96 ) ) {
F_24 ( V_5 ,
V_85 -> V_97 , V_85 -> V_39 ,
V_85 -> V_39 ? V_98 :
V_83 ) ;
F_44 ( & V_5 -> V_99 ) ;
V_5 -> V_90 . V_100 -- ;
F_45 ( & V_85 -> V_101 ) ;
F_46 ( & V_5 -> V_99 ) ;
F_30 ( V_85 ) ;
}
}
}
}
void F_47 ( struct V_4 * V_5 )
{
struct V_84 * V_85 ;
struct V_86 * V_87 , * V_88 ;
struct V_89 * V_55 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_5 -> V_90 . V_91 ; V_18 ++ ) {
V_55 = & ( V_5 -> V_90 . V_92 [ V_18 ] ) ;
F_43 (tmp_fil, tmp_hnode, n, head, fnode) {
F_24 ( V_5 , V_85 -> V_97 ,
V_85 -> V_39 , V_85 -> V_39 ?
V_98 : V_83 ) ;
F_44 ( & V_5 -> V_99 ) ;
V_5 -> V_90 . V_100 -- ;
F_45 ( & V_85 -> V_101 ) ;
F_46 ( & V_5 -> V_99 ) ;
F_30 ( V_85 ) ;
}
}
}
int F_48 ( struct V_4 * V_5 , T_3 V_102 )
{
struct V_41 V_42 ;
int V_103 ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 . V_48 = F_25 ( V_80 << 23 ) ;
V_42 . V_51 = F_25 ( V_104 |
( ( T_1 ) V_5 -> V_14 << 16 ) | ( ( T_1 ) 0x1 << 32 ) ) ;
V_42 . V_52 [ 0 ] = F_25 ( V_102 ) ;
V_103 = F_14 ( V_5 , (struct V_15 * ) & V_42 , 1 ) ;
if ( V_103 != 0 )
F_9 ( & V_5 -> V_11 -> V_12 , L_3 ,
V_102 ? L_4 : L_5 ) ;
return V_103 ;
}
int F_49 ( struct V_4 * V_5 , T_3 V_69 )
{
if ( F_48 ( V_5 , V_69 ) )
return - V_13 ;
if ( F_38 ( V_5 , V_74 ) ) {
F_48 ( V_5 , 0 ) ;
return - V_13 ;
}
F_10 ( 1000 ) ;
return 0 ;
}
void F_50 ( struct V_4 * V_5 )
{
int V_69 = V_70 ;
struct V_65 * V_61 = V_5 -> V_61 ;
F_48 ( V_5 , 0 ) ;
if ( V_61 -> V_71 & V_72 )
V_69 = V_74 ;
else if ( V_61 -> V_71 & V_76 )
V_69 = V_78 ;
F_38 ( V_5 , V_69 ) ;
F_10 ( 1000 ) ;
}
int F_51 ( struct V_4 * V_5 )
{
struct V_41 V_42 ;
int V_103 ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 . V_48 = F_25 ( V_80 << 23 ) ;
V_42 . V_51 = F_25 ( V_105 |
( ( T_1 ) V_5 -> V_14 << 16 ) ) ;
V_42 . V_52 [ 0 ] = F_25 ( ( ( T_1 ) V_5 -> V_106 -> V_107 . V_102 ) << 32 ) ;
V_42 . V_52 [ 2 ] = F_25 ( V_5 -> V_106 -> V_107 . V_108 |
( ( T_1 ) V_5 -> V_106 -> V_107 . V_109 ) << 16 ) ;
V_42 . V_52 [ 5 ] = F_25 ( V_5 -> V_106 -> V_107 . V_110 |
( ( T_1 ) V_5 -> V_106 -> V_107 . type ) << 32 |
( ( T_1 ) V_5 -> V_106 -> V_107 . V_111 ) << 40 ) ;
V_103 = F_14 ( V_5 , (struct V_15 * ) & V_42 , 1 ) ;
if ( V_103 != 0 )
F_9 ( & V_5 -> V_61 -> V_12 ,
L_6 ) ;
return V_103 ;
}
int F_52 ( struct V_4 * V_5 , int V_112 )
{
struct V_41 V_42 ;
T_1 V_47 ;
int V_103 ;
if ( ! F_15 ( V_26 , & V_5 -> V_27 ) )
return 0 ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 . V_48 = F_25 ( V_80 << 23 ) ;
V_47 = V_113 | ( ( T_1 ) V_5 -> V_14 << 16 ) ;
V_42 . V_51 = F_25 ( V_47 ) ;
V_42 . V_52 [ 0 ] = F_25 ( V_112 ) ;
V_103 = F_14 ( V_5 , (struct V_15 * ) & V_42 , 1 ) ;
if ( V_103 != 0 )
F_9 ( & V_5 -> V_61 -> V_12 ,
L_7 ) ;
return V_103 ;
}
int F_53 ( struct V_4 * V_5 , V_3 V_112 )
{
struct V_41 V_42 ;
T_1 V_47 ;
int V_103 ;
if ( ! ! ( V_5 -> V_71 & V_114 ) == V_112 )
return 0 ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 . V_48 = F_25 ( V_80 << 23 ) ;
V_47 = V_115 |
( ( T_1 ) V_5 -> V_14 << 16 ) ;
V_42 . V_51 = F_25 ( V_47 ) ;
V_42 . V_52 [ 0 ] = F_25 ( V_112 ) ;
V_103 = F_14 ( V_5 , (struct V_15 * ) & V_42 , 1 ) ;
if ( V_103 != 0 )
F_9 ( & V_5 -> V_61 -> V_12 ,
L_8 ) ;
V_5 -> V_71 ^= V_114 ;
return V_103 ;
}
int F_54 ( struct V_4 * V_5 , int V_112 )
{
struct V_41 V_42 ;
T_1 V_47 ;
int V_18 , V_103 ;
static const T_1 V_116 [] = {
0xbeac01fa6a42b73bULL , 0x8030f20c77cb2da3ULL ,
0xae7b30b4d0ca2bcbULL , 0x43a38fb04167253dULL ,
0x255b0ec26d5a56daULL
} ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 . V_48 = F_25 ( V_80 << 23 ) ;
V_47 = V_117 | ( ( T_1 ) V_5 -> V_14 << 16 ) ;
V_42 . V_51 = F_25 ( V_47 ) ;
V_47 = ( ( T_1 ) ( V_118 & 0x3 ) << 4 ) |
( ( T_1 ) ( V_118 & 0x3 ) << 6 ) |
( ( T_1 ) ( V_112 & 0x1 ) << 8 ) |
( ( 0x7ULL ) << 48 ) ;
V_42 . V_52 [ 0 ] = F_25 ( V_47 ) ;
for ( V_18 = 0 ; V_18 < 5 ; V_18 ++ )
V_42 . V_52 [ V_18 + 1 ] = F_25 ( V_116 [ V_18 ] ) ;
V_103 = F_14 ( V_5 , (struct V_15 * ) & V_42 , 1 ) ;
if ( V_103 != 0 )
F_9 ( & V_5 -> V_61 -> V_12 , L_9 ) ;
return V_103 ;
}
int F_55 ( struct V_4 * V_5 , T_5 V_119 , int V_120 )
{
struct V_41 V_42 ;
struct V_121 * V_122 ;
T_1 V_47 ;
int V_103 ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 . V_48 = F_25 ( V_80 << 23 ) ;
V_47 = V_123 | ( ( T_1 ) V_5 -> V_14 << 16 ) ;
V_42 . V_51 = F_25 ( V_47 ) ;
V_42 . V_52 [ 0 ] = F_25 ( V_120 ) ;
V_122 = (struct V_121 * ) & V_42 . V_52 [ 1 ] ;
V_122 -> V_124 = V_119 ;
V_103 = F_14 ( V_5 , (struct V_15 * ) & V_42 , 1 ) ;
if ( V_103 != 0 )
F_9 ( & V_5 -> V_61 -> V_12 ,
L_10 ,
( V_120 == V_125 ) ? L_11 : L_12 , V_119 ) ;
return V_103 ;
}
int F_56 ( struct V_4 * V_5 , int V_112 )
{
struct V_41 V_42 ;
T_1 V_47 ;
int V_103 ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 . V_48 = F_25 ( V_80 << 23 ) ;
V_47 = V_126 | ( ( T_1 ) V_5 -> V_14 << 16 ) ;
V_42 . V_51 = F_25 ( V_47 ) ;
V_42 . V_52 [ 0 ] = F_25 ( V_112 | ( V_112 << 8 ) ) ;
V_103 = F_14 ( V_5 , (struct V_15 * ) & V_42 , 1 ) ;
if ( V_103 != 0 )
F_9 ( & V_5 -> V_61 -> V_12 ,
L_13 ) ;
return V_103 ;
}
int F_57 ( struct V_4 * V_5 )
{
struct V_41 V_42 ;
T_1 V_47 ;
int V_103 ;
if ( ! F_15 ( V_26 , & V_5 -> V_27 ) )
return 0 ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 . V_48 = F_25 ( V_80 << 23 ) ;
V_47 = V_127 |
( ( T_1 ) V_5 -> V_14 << 16 ) |
( ( T_1 ) V_128 << 56 ) ;
V_42 . V_51 = F_25 ( V_47 ) ;
V_103 = F_14 ( V_5 , (struct V_15 * ) & V_42 , 1 ) ;
if ( V_103 != 0 )
F_9 ( & V_5 -> V_61 -> V_12 ,
L_14 ) ;
return V_103 ;
}
int F_58 ( struct V_65 * V_61 , int V_129 )
{
struct V_4 * V_5 = F_33 ( V_61 ) ;
int V_130 = 0 ;
if ( V_129 < V_131 || V_129 > V_132 ) {
F_9 ( & V_5 -> V_61 -> V_12 , L_15
L_16 , V_132 , V_131 ) ;
return - V_133 ;
}
V_130 = F_59 ( V_5 , V_129 ) ;
if ( ! V_130 )
V_61 -> V_129 = V_129 ;
return V_130 ;
}
T_6 F_60 ( struct V_65 * V_61 ,
T_6 V_134 )
{
struct V_4 * V_5 = F_33 ( V_61 ) ;
if ( ( V_5 -> V_71 & V_135 ) ) {
T_6 V_136 = V_134 ^ V_61 -> V_134 ;
V_134 ^= V_136 & ( V_137 | V_138 ) ;
}
if ( ! ( V_134 & V_138 ) )
V_134 &= ~ V_139 ;
return V_134 ;
}
int F_61 ( struct V_65 * V_61 , T_6 V_134 )
{
struct V_4 * V_5 = F_33 ( V_61 ) ;
T_6 V_136 = V_61 -> V_134 ^ V_134 ;
int V_140 = ( V_134 & V_139 ) ? V_141 : 0 ;
if ( ! ( V_136 & V_139 ) )
return 0 ;
V_61 -> V_134 = V_134 ^ V_139 ;
if ( F_52 ( V_5 , V_140 ) )
return - V_13 ;
if ( ( V_140 == 0 ) && F_57 ( V_5 ) )
return - V_13 ;
return 0 ;
}
static int
F_62 ( struct V_4 * V_5 ,
T_7 V_142 , void T_2 * * V_1 )
{
const struct V_143 * V_144 ;
if ( ( V_142 >= V_145 ) || ( V_142 < V_146 ) )
return - V_133 ;
V_142 -= V_146 ;
V_144 = & V_147 [ F_63 ( V_142 ) ] . V_148 [ F_64 ( V_142 ) ] ;
if ( V_144 -> V_149 && ( V_144 -> V_150 <= V_142 ) && ( V_144 -> V_151 > V_142 ) ) {
* V_1 = V_5 -> V_106 -> V_152 + V_144 -> V_153 +
( V_142 - V_144 -> V_150 ) ;
return 0 ;
}
* V_1 = V_5 -> V_106 -> V_152 + V_154 + ( V_142 & F_65 ( 16 ) ) ;
return 1 ;
}
static int
F_66 ( struct V_4 * V_5 , T_7 V_142 )
{
V_3 V_155 ;
void T_2 * V_1 = V_5 -> V_106 -> V_152 + V_156 ;
V_142 -= V_146 ;
V_155 = F_67 ( V_142 ) ;
if ( V_155 == 0 ) {
F_9 ( & V_5 -> V_11 -> V_12 , L_17 , V_142 ) ;
return - V_13 ;
}
F_4 ( V_155 , V_1 ) ;
if ( F_2 ( V_1 ) != V_155 ) {
if ( F_68 () )
F_69 ( & V_5 -> V_11 -> V_12 ,
L_18 ,
V_155 , V_142 ) ;
return - V_13 ;
}
return 0 ;
}
int
F_70 ( struct V_4 * V_5 , T_7 V_142 , V_3 V_157 )
{
unsigned long V_71 ;
int V_103 ;
void T_2 * V_1 = NULL ;
V_103 = F_62 ( V_5 , V_142 , & V_1 ) ;
if ( V_103 == 0 ) {
F_4 ( V_157 , V_1 ) ;
return 0 ;
}
if ( V_103 > 0 ) {
F_71 ( & V_5 -> V_106 -> V_158 , V_71 ) ;
F_72 ( V_5 ) ;
V_103 = F_66 ( V_5 , V_142 ) ;
if ( ! V_103 )
F_4 ( V_157 , V_1 ) ;
F_73 ( V_5 ) ;
F_74 ( & V_5 -> V_106 -> V_158 , V_71 ) ;
return V_103 ;
}
F_9 ( & V_5 -> V_11 -> V_12 ,
L_19 , V_159 , V_142 ) ;
F_75 () ;
return - V_13 ;
}
V_3
F_76 ( struct V_4 * V_5 , T_7 V_142 )
{
unsigned long V_71 ;
int V_103 ;
V_3 V_157 = - 1 ;
void T_2 * V_1 = NULL ;
V_103 = F_62 ( V_5 , V_142 , & V_1 ) ;
if ( V_103 == 0 )
return F_2 ( V_1 ) ;
if ( V_103 > 0 ) {
F_71 ( & V_5 -> V_106 -> V_158 , V_71 ) ;
F_72 ( V_5 ) ;
if ( ! F_66 ( V_5 , V_142 ) )
V_157 = F_2 ( V_1 ) ;
F_73 ( V_5 ) ;
F_74 ( & V_5 -> V_106 -> V_158 , V_71 ) ;
return V_157 ;
}
F_9 ( & V_5 -> V_11 -> V_12 ,
L_19 , V_159 , V_142 ) ;
F_75 () ;
return - 1 ;
}
void T_2 *
F_77 ( struct V_4 * V_5 , V_3 V_160 )
{
void T_2 * V_1 = NULL ;
F_78 ( F_62 ( V_5 , V_160 , & V_1 ) ) ;
return V_1 ;
}
static int
F_79 ( struct V_4 * V_5 ,
T_1 V_1 , V_3 * V_161 )
{
V_3 V_155 ;
V_155 = F_80 ( V_1 ) ;
F_4 ( V_155 , V_5 -> V_106 -> V_162 ) ;
F_2 ( V_5 -> V_106 -> V_162 ) ;
* V_161 = V_163 + F_81 ( V_1 ) ;
return 0 ;
}
static int
F_82 ( struct V_4 * V_5 , T_1 V_142 ,
T_1 * V_157 , int V_40 )
{
void T_2 * V_1 ;
int V_164 ;
V_3 V_161 ;
F_83 ( & V_5 -> V_106 -> V_165 ) ;
V_164 = F_79 ( V_5 , V_142 , & V_161 ) ;
if ( V_164 != 0 )
goto V_166;
V_1 = V_5 -> V_106 -> V_152 + V_161 ;
if ( V_40 == 0 )
* V_157 = F_1 ( V_1 ) ;
else
F_3 ( * V_157 , V_1 ) ;
V_166:
F_84 ( & V_5 -> V_106 -> V_165 ) ;
return V_164 ;
}
void
F_85 ( struct V_4 * V_5 , T_1 V_142 , T_1 * V_157 )
{
void T_2 * V_1 = V_5 -> V_106 -> V_152 +
V_167 + ( V_142 - V_168 ) ;
F_83 ( & V_5 -> V_106 -> V_165 ) ;
* V_157 = F_1 ( V_1 ) ;
F_84 ( & V_5 -> V_106 -> V_165 ) ;
}
void
F_86 ( struct V_4 * V_5 , T_1 V_142 , T_1 V_157 )
{
void T_2 * V_1 = V_5 -> V_106 -> V_152 +
V_167 + ( V_142 - V_168 ) ;
F_83 ( & V_5 -> V_106 -> V_165 ) ;
F_3 ( V_157 , V_1 ) ;
F_84 ( & V_5 -> V_106 -> V_165 ) ;
}
int
F_87 ( struct V_4 * V_5 ,
T_1 V_142 , T_1 V_157 )
{
int V_18 , V_169 , V_164 ;
V_3 V_170 , V_171 ;
void T_2 * V_172 ;
if ( V_142 & 7 )
return - V_13 ;
if ( F_88 ( V_142 , V_173 ,
V_174 ) ) {
V_172 = F_77 ( V_5 ,
V_175 + V_176 ) ;
goto V_177;
}
if ( F_88 ( V_142 , V_178 , V_179 ) ) {
V_172 = F_77 ( V_5 ,
V_180 + V_176 ) ;
goto V_177;
}
if ( F_88 ( V_142 , V_181 , V_182 ) )
return F_82 ( V_5 , V_142 , & V_157 , 1 ) ;
return - V_13 ;
V_177:
V_171 = V_142 & ~ 0xf ;
F_83 ( & V_5 -> V_106 -> V_165 ) ;
F_4 ( V_171 , ( V_172 + V_183 ) ) ;
F_4 ( 0 , ( V_172 + V_184 ) ) ;
V_18 = 0 ;
F_4 ( V_185 , ( V_172 + V_186 ) ) ;
F_4 ( ( V_187 | V_185 ) ,
( V_172 + V_186 ) ) ;
for ( V_169 = 0 ; V_169 < V_188 ; V_169 ++ ) {
V_170 = F_2 ( V_172 + V_186 ) ;
if ( ( V_170 & V_189 ) == 0 )
break;
}
if ( V_169 >= V_188 ) {
V_164 = - V_13 ;
goto V_8;
}
V_18 = ( V_142 & 0xf ) ? 0 : 2 ;
F_4 ( F_2 ( V_172 + F_89 ( V_18 ) ) ,
V_172 + F_90 ( V_18 ) ) ;
F_4 ( F_2 ( V_172 + F_89 ( V_18 + 1 ) ) ,
V_172 + F_90 ( V_18 + 1 ) ) ;
V_18 = ( V_142 & 0xf ) ? 2 : 0 ;
F_4 ( V_157 & 0xffffffff ,
V_172 + F_90 ( V_18 ) ) ;
F_4 ( ( V_157 >> 32 ) & 0xffffffff ,
V_172 + F_90 ( V_18 + 1 ) ) ;
F_4 ( ( V_185 | V_190 ) , ( V_172 + V_186 ) ) ;
F_4 ( ( V_187 | V_185 | V_190 ) ,
( V_172 + V_186 ) ) ;
for ( V_169 = 0 ; V_169 < V_188 ; V_169 ++ ) {
V_170 = F_2 ( V_172 + V_186 ) ;
if ( ( V_170 & V_189 ) == 0 )
break;
}
if ( V_169 >= V_188 ) {
if ( F_68 () )
F_9 ( & V_5 -> V_11 -> V_12 ,
L_20 ) ;
V_164 = - V_13 ;
} else
V_164 = 0 ;
V_8:
F_84 ( & V_5 -> V_106 -> V_165 ) ;
return V_164 ;
}
int
F_91 ( struct V_4 * V_5 ,
T_1 V_142 , T_1 * V_157 )
{
int V_169 , V_164 ;
V_3 V_170 , V_171 ;
T_1 V_2 ;
void T_2 * V_172 ;
if ( V_142 & 7 )
return - V_13 ;
if ( F_88 ( V_142 , V_173 ,
V_174 ) ) {
V_172 = F_77 ( V_5 ,
V_175 + V_176 ) ;
goto V_177;
}
if ( F_88 ( V_142 , V_178 , V_179 ) ) {
V_172 = F_77 ( V_5 ,
V_180 + V_176 ) ;
goto V_177;
}
if ( F_88 ( V_142 , V_181 , V_182 ) ) {
return F_82 ( V_5 ,
V_142 , V_157 , 0 ) ;
}
return - V_13 ;
V_177:
V_171 = V_142 & ~ 0xf ;
F_83 ( & V_5 -> V_106 -> V_165 ) ;
F_4 ( V_171 , ( V_172 + V_183 ) ) ;
F_4 ( 0 , ( V_172 + V_184 ) ) ;
F_4 ( V_185 , ( V_172 + V_186 ) ) ;
F_4 ( ( V_187 | V_185 ) , ( V_172 + V_186 ) ) ;
for ( V_169 = 0 ; V_169 < V_188 ; V_169 ++ ) {
V_170 = F_2 ( V_172 + V_186 ) ;
if ( ( V_170 & V_189 ) == 0 )
break;
}
if ( V_169 >= V_188 ) {
if ( F_68 () )
F_9 ( & V_5 -> V_11 -> V_12 ,
L_21 ) ;
V_164 = - V_13 ;
} else {
V_171 = V_191 ;
if ( V_142 & 0xf )
V_171 = V_192 ;
V_170 = F_2 ( V_172 + V_171 + 4 ) ;
V_2 = ( T_1 ) V_170 << 32 ;
V_2 |= F_2 ( V_172 + V_171 ) ;
* V_157 = V_2 ;
V_164 = 0 ;
}
F_84 ( & V_5 -> V_106 -> V_165 ) ;
return V_164 ;
}
int F_92 ( struct V_4 * V_5 )
{
int V_160 , V_193 , V_194 ;
struct V_195 * V_11 = V_5 -> V_11 ;
V_160 = V_196 ;
if ( F_93 ( V_5 , V_160 , & V_194 ) )
return - V_13 ;
if ( V_194 != V_197 ) {
F_9 ( & V_11 -> V_12 , L_22 ,
V_194 ) ;
return - V_13 ;
}
V_160 = V_198 ;
if ( F_93 ( V_5 , V_160 , & V_193 ) )
return - V_13 ;
V_5 -> V_106 -> V_193 = V_193 ;
if ( V_193 == V_199 ) {
V_3 V_200 = F_6 ( V_5 , V_201 ) ;
if ( ( V_200 & 0x8000 ) == 0 )
V_193 = V_202 ;
}
switch ( V_193 ) {
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
V_5 -> V_106 -> V_213 = V_214 ;
break;
case V_215 :
case V_216 :
case V_199 :
V_5 -> V_106 -> V_213 = V_217 ;
break;
case V_202 :
V_5 -> V_106 -> V_213 = ( V_5 -> V_14 < 2 ) ?
V_214 : V_217 ;
break;
default:
F_9 ( & V_11 -> V_12 , L_23 , V_193 ) ;
V_5 -> V_106 -> V_213 = V_214 ;
break;
}
return 0 ;
}
int
F_94 ( struct V_4 * V_5 )
{
V_3 V_218 ;
V_218 = F_6 ( V_5 , V_219 ) ;
if ( V_218 & ( 1UL << V_5 -> V_14 ) ) {
V_218 = F_6 ( V_5 , V_220 ) ;
if ( V_218 & ( 1 << V_5 -> V_14 ) )
return 1 ;
}
return 0 ;
}
int F_95 ( struct V_4 * V_5 , V_3 V_27 , V_3 V_221 )
{
struct V_41 V_42 ;
int V_103 ;
T_1 V_47 ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
V_42 . V_48 = F_25 ( V_80 << 23 ) ;
V_47 = V_222 | ( ( T_1 ) V_5 -> V_14 << 16 ) ;
V_42 . V_51 = F_25 ( V_47 ) ;
V_42 . V_52 [ 0 ] = F_25 ( ( T_1 ) V_221 << 32 ) ;
V_42 . V_52 [ 1 ] = F_25 ( V_27 ) ;
V_103 = F_14 ( V_5 , (struct V_15 * ) & V_42 , 1 ) ;
if ( V_103 )
F_9 ( & V_5 -> V_11 -> V_12 , L_24 ) ;
return V_103 ;
}
static V_3
F_96 ( struct V_4 * V_5 , struct V_223 * V_224 ,
V_3 * V_225 )
{
int V_18 ;
V_3 V_1 , V_157 ;
struct V_226 * V_227 = & V_224 -> V_228 . V_227 ;
void T_2 * V_229 = V_5 -> V_106 -> V_152 ;
V_1 = V_227 -> V_1 ;
for ( V_18 = 0 ; V_18 < V_227 -> V_230 ; V_18 ++ ) {
F_97 ( V_1 , V_229 , & V_157 ) ;
* V_225 ++ = F_98 ( V_1 ) ;
* V_225 ++ = F_98 ( V_157 ) ;
V_1 += V_227 -> V_231 ;
}
return V_227 -> V_230 * 2 * sizeof( V_3 ) ;
}
static V_3
F_99 ( struct V_4 * V_5 ,
struct V_223 * V_224 , V_3 * V_225 )
{
int V_18 , V_232 , V_9 = 0 ;
void T_2 * V_229 = V_5 -> V_106 -> V_152 ;
V_3 V_1 , V_157 ;
T_3 V_233 , V_230 ;
struct V_234 * V_235 = & V_224 -> V_228 . V_236 ;
struct V_237 * V_238 = V_5 -> V_106 -> V_239 . V_240 ;
V_1 = V_235 -> V_1 ;
V_230 = V_235 -> V_230 ;
for ( V_18 = 0 ; V_18 < V_230 ; V_18 ++ ) {
V_232 = 0 ;
V_233 = 0 ;
for ( V_232 = 0 ; V_232 < 8 ; V_232 ++ ) {
if ( ! ( V_235 -> V_233 & ( 1 << V_232 ) ) )
continue;
switch ( 1 << V_232 ) {
case V_241 :
F_100 ( V_1 , V_229 , V_235 -> V_242 ) ;
break;
case V_243 :
F_97 ( V_1 , V_229 , & V_157 ) ;
F_100 ( V_1 , V_229 , V_157 ) ;
break;
case V_244 :
F_97 ( V_1 , V_229 , & V_157 ) ;
F_100 ( V_1 , V_229 ,
( V_157 & V_235 -> V_245 ) ) ;
break;
case V_246 :
F_97 ( V_1 , V_229 , & V_157 ) ;
F_100 ( V_1 , V_229 ,
( V_157 | V_235 -> V_247 ) ) ;
break;
case V_248 :
while ( V_9 <= V_235 -> V_9 ) {
F_97 ( V_1 , V_229 , & V_157 ) ;
if ( ( V_157 & V_235 -> V_245 ) == V_235 -> V_242 )
break;
F_10 ( 1 ) ;
V_9 ++ ;
}
if ( V_9 > V_235 -> V_9 ) {
F_101 ( & V_5 -> V_11 -> V_12 ,
L_25 ) ;
return - V_133 ;
}
break;
case V_249 :
if ( V_235 -> V_250 )
V_1 = V_238 -> V_251 [ V_235 -> V_250 ] ;
F_97 ( V_1 , V_229 , & V_157 ) ;
V_238 -> V_251 [ V_235 -> V_252 ] = V_157 ;
break;
case V_253 :
if ( V_235 -> V_252 )
V_157 = V_238 -> V_251 [ V_235 -> V_252 ] ;
else
V_157 = V_235 -> V_242 ;
if ( V_235 -> V_250 )
V_1 = V_238 -> V_251 [ V_235 -> V_250 ] ;
F_100 ( V_1 , V_229 , V_157 ) ;
break;
case V_254 :
V_157 = V_238 -> V_251 [ V_235 -> V_252 ] ;
V_157 <<= V_235 -> V_255 ;
V_157 >>= V_235 -> V_256 ;
if ( V_235 -> V_245 )
V_157 &= V_235 -> V_245 ;
V_157 |= V_235 -> V_247 ;
V_157 += V_235 -> V_242 ;
V_238 -> V_251 [ V_235 -> V_252 ] = V_157 ;
break;
default:
F_101 ( & V_5 -> V_11 -> V_12 ,
L_26 ) ;
break;
}
}
V_1 += V_235 -> V_231 ;
}
return 0 ;
}
static V_3
F_102 ( struct V_4 * V_5 , struct V_223 * V_224 ,
V_3 * V_225 )
{
int V_257 ;
V_3 V_2 , V_157 = 0 ;
struct V_258 * V_259 = & V_224 -> V_228 . V_259 ;
void T_2 * V_229 = V_5 -> V_106 -> V_152 ;
V_2 = V_259 -> V_2 ;
for ( V_257 = 0 ; V_257 < V_259 -> V_230 ; V_257 ++ ) {
F_100 ( V_259 -> V_1 , V_229 , V_2 ) ;
F_97 ( V_259 -> V_260 , V_229 , & V_157 ) ;
* V_225 ++ = F_98 ( V_2 ) ;
* V_225 ++ = F_98 ( V_157 ) ;
V_2 += V_259 -> V_261 ;
}
return 2 * V_259 -> V_230 * sizeof( V_3 ) ;
}
static V_3
F_103 ( struct V_4 * V_5 , struct V_223 * V_224 ,
V_3 * V_225 )
{
int V_18 , V_257 ;
V_3 V_262 , V_1 , V_157 , V_263 = 0 ;
void T_2 * V_229 = V_5 -> V_106 -> V_152 ;
struct V_264 * V_265 = & V_224 -> V_228 . V_265 ;
V_1 = V_265 -> V_260 ;
V_262 = V_265 -> V_266 ;
for ( V_257 = 0 ; V_257 < V_265 -> V_230 ; V_257 ++ ) {
F_100 ( V_265 -> V_267 , V_229 , V_263 ) ;
V_1 = V_265 -> V_260 ;
for ( V_18 = 0 ; V_18 < V_262 ; V_18 ++ ) {
F_97 ( V_1 , V_229 , & V_157 ) ;
* V_225 ++ = F_98 ( V_157 ) ;
V_1 += V_265 -> V_268 ;
}
V_263 += V_265 -> V_231 ;
}
return V_265 -> V_230 * V_262 * sizeof( V_3 ) ;
}
static V_3
F_104 ( struct V_4 * V_5 , struct V_223 * V_224 ,
V_3 * V_225 )
{
int V_18 ;
V_3 V_157 ;
void T_2 * V_1 ;
struct V_269 * V_270 = & V_224 -> V_228 . V_270 ;
V_1 = V_5 -> V_106 -> V_152 + V_270 -> V_260 ;
for ( V_18 = 0 ; V_18 < V_270 -> V_230 ; V_18 ++ ) {
V_157 = F_2 ( V_1 ) ;
* V_225 ++ = F_98 ( V_157 ) ;
V_1 += V_270 -> V_268 ;
}
return V_270 -> V_230 * sizeof( V_3 ) ;
}
static V_3
F_105 ( struct V_4 * V_5 , struct V_223 * V_224 ,
V_3 * V_225 )
{
int V_18 , V_271 = 0 ;
V_3 V_272 , V_273 , V_2 , V_274 , V_1 ;
struct V_275 * V_276 = & V_224 -> V_228 . V_277 ;
void T_2 * V_229 = V_5 -> V_106 -> V_152 ;
V_272 = V_276 -> V_1 ;
V_273 = V_276 -> V_273 / 4 ;
V_278:
V_274 = F_2 ( V_229 + V_279 ) ;
if ( ! V_274 && V_271 < V_188 ) {
F_10 ( 10 ) ;
V_271 ++ ;
goto V_278;
}
F_4 ( V_5 -> V_106 -> V_280 , ( V_229 + V_281 ) ) ;
for ( V_18 = 0 ; V_18 < V_273 ; V_18 ++ ) {
V_1 = V_272 & 0xFFFF0000 ;
F_100 ( V_282 , V_229 , V_1 ) ;
V_1 = F_106 ( V_272 ) + V_283 ;
F_97 ( V_1 , V_229 , & V_2 ) ;
V_272 += 4 ;
* V_225 ++ = F_98 ( V_2 ) ;
}
F_2 ( V_229 + V_284 ) ;
return V_276 -> V_273 ;
}
static V_3
F_107 ( struct V_4 * V_5 ,
struct V_223 * V_224 , V_3 * V_225 )
{
int V_18 ;
V_3 V_262 , V_2 , V_157 , V_1 ;
void T_2 * V_229 = V_5 -> V_106 -> V_152 ;
struct V_285 * V_286 = & V_224 -> V_228 . V_287 ;
V_2 = V_286 -> V_288 ;
for ( V_18 = 0 ; V_18 < V_286 -> V_230 ; V_18 ++ ) {
F_100 ( V_286 -> V_1 , V_229 , V_2 ) ;
F_100 ( V_286 -> V_289 , V_229 , F_106 ( V_286 -> V_290 ) ) ;
V_1 = V_286 -> V_260 ;
V_262 = V_286 -> V_291 ;
while ( V_262 ) {
F_97 ( V_1 , V_229 , & V_157 ) ;
* V_225 ++ = F_98 ( V_157 ) ;
V_1 += V_286 -> V_268 ;
V_262 -- ;
}
V_2 += V_286 -> V_231 ;
}
return V_286 -> V_230 * V_286 -> V_291 * sizeof( V_3 ) ;
}
static V_3
F_108 ( struct V_4 * V_5 ,
struct V_223 * V_224 , V_3 * V_225 )
{
int V_18 ;
V_3 V_262 , V_2 , V_157 , V_1 ;
T_3 V_292 , V_293 , V_294 = 0 ;
void T_2 * V_229 = V_5 -> V_106 -> V_152 ;
struct V_285 * V_295 = & V_224 -> V_228 . V_287 ;
V_2 = V_295 -> V_288 ;
V_292 = F_109 ( F_110 ( V_295 -> V_290 ) ) ;
V_293 = F_111 ( F_110 ( V_295 -> V_290 ) ) ;
for ( V_18 = 0 ; V_18 < V_295 -> V_230 ; V_18 ++ ) {
F_100 ( V_295 -> V_1 , V_229 , V_2 ) ;
if ( F_106 ( V_295 -> V_290 ) )
F_100 ( V_295 -> V_289 , V_229 ,
F_106 ( V_295 -> V_290 ) ) ;
if ( ! V_292 )
goto V_296;
do {
F_97 ( V_295 -> V_289 , V_229 , & V_157 ) ;
if ( ! ( V_157 & V_292 ) )
break;
F_10 ( 1 ) ;
V_294 ++ ;
} while ( V_294 <= V_293 );
if ( V_294 > V_293 ) {
F_9 ( & V_5 -> V_11 -> V_12 ,
L_27 ,
V_159 ) ;
return - V_133 ;
}
V_296:
V_1 = V_295 -> V_260 ;
V_262 = V_295 -> V_291 ;
while ( V_262 ) {
F_97 ( V_1 , V_229 , & V_157 ) ;
* V_225 ++ = F_98 ( V_157 ) ;
V_1 += V_295 -> V_268 ;
V_262 -- ;
}
V_2 += V_295 -> V_231 ;
}
return V_295 -> V_230 * V_295 -> V_291 * sizeof( V_3 ) ;
}
static V_3
F_112 ( struct V_4 * V_5 ,
struct V_223 * V_224 , V_3 * V_225 )
{
V_3 V_1 , V_157 , V_297 , V_164 = 0 ;
int V_18 , V_298 ;
struct V_275 * V_277 = & V_224 -> V_228 . V_277 ;
void T_2 * V_229 = V_5 -> V_106 -> V_152 ;
V_298 = V_277 -> V_273 ;
V_1 = V_277 -> V_1 ;
if ( ( V_1 & 0xf ) || ( V_298 % 16 ) ) {
F_101 ( & V_5 -> V_11 -> V_12 ,
L_28 ,
V_1 , V_298 ) ;
return - V_133 ;
}
F_83 ( & V_5 -> V_106 -> V_165 ) ;
while ( V_298 != 0 ) {
F_100 ( V_299 , V_229 , V_1 ) ;
F_100 ( V_300 , V_229 , 0 ) ;
F_100 ( V_301 , V_229 ,
V_185 | V_187 ) ;
for ( V_18 = 0 ; V_18 < V_188 ; V_18 ++ ) {
F_97 ( V_301 , V_229 , & V_297 ) ;
if ( ! ( V_297 & V_189 ) )
break;
}
if ( V_18 == V_188 ) {
if ( F_68 () ) {
F_9 ( & V_5 -> V_11 -> V_12 ,
L_21 ) ;
V_164 = - V_133 ;
goto V_302;
}
}
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
F_97 ( V_303 [ V_18 ] , V_229 , & V_157 ) ;
* V_225 ++ = F_98 ( V_157 ) ;
}
V_1 += 16 ;
V_298 -= 16 ;
V_164 += 16 ;
}
V_302:
F_84 ( & V_5 -> V_106 -> V_165 ) ;
return V_277 -> V_273 ;
}
static V_3
F_113 ( struct V_4 * V_5 ,
struct V_223 * V_224 , V_3 * V_225 )
{
V_224 -> V_304 . V_71 |= V_305 ;
return 0 ;
}
static int
F_114 ( struct V_306 * V_12 , struct V_223 * V_224 ,
V_3 V_273 )
{
int V_164 = 1 ;
if ( V_273 != V_224 -> V_304 . V_307 ) {
F_101 ( V_12 ,
L_29 ,
V_224 -> V_304 . type , V_224 -> V_304 . V_308 , V_273 , V_224 -> V_304 . V_307 ) ;
F_101 ( V_12 , L_30 ) ;
V_164 = 0 ;
}
return V_164 ;
}
int F_115 ( struct V_4 * V_5 )
{
V_3 * V_225 ;
char V_309 [ 64 ] ;
char * V_310 [] = { V_309 , NULL } ;
int V_18 , V_232 , V_311 , V_312 , V_313 = 0 ;
V_3 V_314 , V_315 , V_316 , V_317 = 0 ;
struct V_223 * V_224 ;
struct V_318 * V_239 = & V_5 -> V_106 -> V_239 ;
struct V_237 * V_240 = V_239 -> V_240 ;
if ( V_239 -> V_319 ) {
F_101 ( & V_5 -> V_11 -> V_12 ,
L_31 ) ;
return - V_13 ;
}
for ( V_18 = 2 , V_232 = 1 ; ( V_18 & V_320 ) ; V_18 <<= 1 , V_232 ++ )
if ( V_18 & V_240 -> V_321 )
V_313 += V_240 -> V_322 [ V_232 ] ;
if ( ! V_313 )
return - V_13 ;
V_239 -> V_157 = F_116 ( V_313 ) ;
if ( ! V_239 -> V_157 ) {
F_101 ( & V_5 -> V_11 -> V_12 ,
L_32 ,
V_313 / 1024 ) ;
return - V_62 ;
}
V_225 = V_239 -> V_157 ;
V_239 -> V_273 = V_313 ;
V_316 = V_240 -> V_323 ;
V_311 = F_117 ( V_324 ) ;
V_314 = V_240 -> V_160 ;
V_240 -> V_325 [ 0 ] = V_326 ;
V_240 -> V_325 [ 1 ] = V_5 -> V_327 ;
for ( V_18 = 0 ; V_18 < V_316 ; V_18 ++ ) {
V_224 = ( void * ) V_240 + V_314 ;
if ( ! ( V_224 -> V_304 . V_308 & V_240 -> V_321 ) ) {
V_224 -> V_304 . V_71 |= V_305 ;
V_314 += V_224 -> V_304 . V_160 ;
continue;
}
V_312 = 0 ;
while ( V_312 < V_311 ) {
if ( V_224 -> V_304 . type == V_324 [ V_312 ] . V_233 )
break;
V_312 ++ ;
}
if ( V_312 == V_311 ) {
F_101 ( & V_5 -> V_11 -> V_12 ,
L_33 ,
V_224 -> V_304 . type ) ;
goto error;
}
V_315 = V_324 [ V_312 ] . F_118 ( V_5 , V_224 , V_225 ) ;
if ( V_315 && ! F_114 ( & V_5 -> V_11 -> V_12 , V_224 ,
V_315 ) )
V_224 -> V_304 . V_71 |= V_305 ;
V_317 += V_224 -> V_304 . V_307 ;
V_314 += V_224 -> V_304 . V_160 ;
V_225 = V_239 -> V_157 + V_317 ;
}
if ( V_313 != V_317 ) {
F_101 ( & V_5 -> V_11 -> V_12 ,
L_34 ,
V_317 , V_313 ) ;
goto error;
} else {
V_239 -> V_319 = 1 ;
snprintf ( V_309 , sizeof( V_309 ) , L_35 ,
V_5 -> V_61 -> V_328 ) ;
F_101 ( & V_5 -> V_11 -> V_12 , L_36 ,
V_239 -> V_273 ) ;
F_119 ( & V_5 -> V_11 -> V_12 . V_329 , V_330 , V_310 ) ;
return 0 ;
}
error:
F_120 ( V_239 -> V_157 ) ;
return - V_133 ;
}
