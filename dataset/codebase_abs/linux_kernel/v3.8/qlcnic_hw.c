static inline T_1 F_1 ( void T_2 * V_1 )
{
return F_2 ( V_1 ) | ( ( ( T_1 ) F_2 ( V_1 + 4 ) ) << 32LL ) ;
}
static inline void F_3 ( T_1 V_2 , void T_2 * V_1 )
{
F_4 ( ( ( V_3 ) ( V_2 ) ) , ( V_1 ) ) ;
F_4 ( ( ( V_3 ) ( V_2 >> 32 ) ) , ( V_1 + 4 ) ) ;
}
static void F_5 ( V_3 V_1 , void T_2 * V_4 , V_3 * V_5 )
{
V_3 V_6 ;
void T_2 * V_2 ;
V_6 = V_1 & 0xFFFF0000 ;
V_2 = V_4 + V_7 ;
F_4 ( V_6 , V_2 ) ;
F_2 ( V_2 ) ;
V_2 = V_4 + V_8 + F_6 ( V_1 ) ;
* V_5 = F_2 ( V_2 ) ;
}
static void F_7 ( V_3 V_1 , void T_2 * V_4 , V_3 V_5 )
{
V_3 V_6 ;
void T_2 * V_2 ;
V_6 = V_1 & 0xFFFF0000 ;
V_2 = V_4 + V_7 ;
F_4 ( V_6 , V_2 ) ;
F_2 ( V_2 ) ;
V_2 = V_4 + V_8 + F_6 ( V_1 ) ;
F_4 ( V_5 , V_2 ) ;
F_2 ( V_2 ) ;
}
int
F_8 ( struct V_9 * V_10 , int V_11 , V_3 V_12 )
{
int V_13 = 0 , V_14 = 0 ;
while ( ! V_13 ) {
V_13 = F_9 ( V_10 , F_10 ( F_11 ( V_11 ) ) ) ;
if ( V_13 == 1 )
break;
if ( ++ V_14 >= V_15 ) {
F_12 ( & V_10 -> V_16 -> V_17 ,
L_1 ,
V_11 , V_12 ? F_9 ( V_10 , V_12 ) : - 1 ) ;
return - V_18 ;
}
F_13 ( 1 ) ;
}
if ( V_12 )
F_14 ( V_10 , V_12 , V_10 -> V_19 ) ;
return 0 ;
}
void
F_15 ( struct V_9 * V_10 , int V_11 )
{
F_9 ( V_10 , F_10 ( F_16 ( V_11 ) ) ) ;
}
static int F_17 ( struct V_9 * V_10 , V_3 V_1 )
{
V_3 V_5 ;
if ( F_18 ( V_10 ) )
F_5 ( V_1 , V_10 -> V_20 -> V_21 , & V_5 ) ;
else
return - V_18 ;
return V_5 ;
}
static void F_19 ( struct V_9 * V_10 , V_3 V_1 , V_3 V_5 )
{
if ( F_18 ( V_10 ) )
F_7 ( V_1 , V_10 -> V_20 -> V_21 , V_5 ) ;
}
static int
F_20 ( struct V_9 * V_10 ,
struct V_22 * V_23 , int V_24 )
{
V_3 V_25 , V_26 ;
struct V_27 * V_28 ;
struct V_22 * V_29 ;
struct V_30 * V_31 ;
V_25 = 0 ;
if ( ! F_21 ( V_32 , & V_10 -> V_33 ) )
return - V_18 ;
V_31 = V_10 -> V_31 ;
F_22 ( V_31 -> V_34 ) ;
V_26 = V_31 -> V_26 ;
if ( V_24 >= F_23 ( V_31 ) ) {
F_24 ( V_31 -> V_34 ) ;
F_25 () ;
if ( F_23 ( V_31 ) > V_24 ) {
if ( F_23 ( V_31 ) > V_35 )
F_26 ( V_31 -> V_34 ) ;
} else {
V_10 -> V_36 . V_37 ++ ;
F_27 ( V_31 -> V_34 ) ;
return - V_38 ;
}
}
do {
V_29 = & V_23 [ V_25 ] ;
V_28 = & V_31 -> V_39 [ V_26 ] ;
V_28 -> V_40 = NULL ;
V_28 -> V_41 = 0 ;
memcpy ( & V_31 -> V_42 [ V_26 ] ,
V_29 , sizeof( struct V_22 ) ) ;
V_26 = F_28 ( V_26 , V_31 -> V_43 ) ;
V_25 ++ ;
} while ( V_25 != V_24 );
V_31 -> V_26 = V_26 ;
F_29 ( V_31 ) ;
F_27 ( V_31 -> V_34 ) ;
return 0 ;
}
static int
F_30 ( struct V_9 * V_10 , T_3 * V_1 ,
T_4 V_44 , unsigned V_45 )
{
struct V_46 V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
T_1 V_52 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_31 ( V_54 << 23 ) ;
V_52 = V_55 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_31 ( V_52 ) ;
V_49 = (struct V_48 * ) & V_47 . V_57 [ 0 ] ;
V_49 -> V_45 = V_45 ;
memcpy ( V_49 -> V_58 , V_1 , 6 ) ;
V_51 = (struct V_50 * ) & V_47 . V_57 [ 1 ] ;
V_51 -> V_44 = V_44 ;
return F_20 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
}
static int F_32 ( struct V_9 * V_10 , const T_3 * V_1 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 ;
F_33 (head, &adapter->mac_list) {
V_62 = F_34 ( V_60 , struct V_61 , V_63 ) ;
if ( memcmp ( V_1 , V_62 -> V_58 , V_64 ) == 0 )
return 0 ;
}
V_62 = F_35 ( sizeof( struct V_61 ) , V_65 ) ;
if ( V_62 == NULL ) {
F_12 ( & V_10 -> V_66 -> V_17 ,
L_2 ) ;
return - V_67 ;
}
memcpy ( V_62 -> V_58 , V_1 , V_64 ) ;
if ( F_30 ( V_10 ,
V_62 -> V_58 , 0 , V_68 ) ) {
F_36 ( V_62 ) ;
return - V_18 ;
}
F_37 ( & V_62 -> V_63 , & V_10 -> V_69 ) ;
return 0 ;
}
void F_38 ( struct V_70 * V_66 )
{
struct V_9 * V_10 = F_39 ( V_66 ) ;
struct V_71 * V_72 ;
static const T_3 V_73 [ V_64 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
V_3 V_74 = V_75 ;
if ( ! F_21 ( V_32 , & V_10 -> V_33 ) )
return;
F_32 ( V_10 , V_10 -> V_58 ) ;
F_32 ( V_10 , V_73 ) ;
if ( V_66 -> V_76 & V_77 ) {
if ( ! ( V_10 -> V_76 & V_78 ) )
V_74 = V_79 ;
goto V_80;
}
if ( ( V_66 -> V_76 & V_81 ) ||
( F_40 ( V_66 ) > V_10 -> V_20 -> V_82 ) ) {
V_74 = V_83 ;
goto V_80;
}
if ( ! F_41 ( V_66 ) ) {
F_42 (ha, netdev) {
F_32 ( V_10 , V_72 -> V_1 ) ;
}
}
V_80:
if ( V_74 == V_79 ) {
F_43 ( V_10 ) ;
V_10 -> V_84 = 1 ;
} else {
V_10 -> V_84 = 0 ;
}
F_44 ( V_10 , V_74 ) ;
}
int F_44 ( struct V_9 * V_10 , V_3 V_74 )
{
struct V_46 V_47 ;
T_1 V_52 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_31 ( V_85 << 23 ) ;
V_52 = V_86 |
( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_31 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_31 ( V_74 ) ;
return F_20 ( V_10 ,
(struct V_22 * ) & V_47 , 1 ) ;
}
void F_45 ( struct V_9 * V_10 )
{
struct V_61 * V_62 ;
struct V_59 * V_60 = & V_10 -> V_69 ;
while ( ! F_46 ( V_60 ) ) {
V_62 = F_34 ( V_60 -> V_87 , struct V_61 , V_63 ) ;
F_30 ( V_10 ,
V_62 -> V_58 , 0 , V_88 ) ;
F_47 ( & V_62 -> V_63 ) ;
F_36 ( V_62 ) ;
}
}
void F_48 ( struct V_9 * V_10 )
{
struct V_89 * V_90 ;
struct V_91 * V_92 , * V_93 ;
struct V_94 * V_60 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_10 -> V_95 . V_96 ; V_25 ++ ) {
V_60 = & ( V_10 -> V_95 . V_97 [ V_25 ] ) ;
F_49 (tmp_fil, tmp_hnode, n, head, fnode)
{
if ( V_98 >
( V_99 * V_100 + V_90 -> V_101 ) ) {
F_30 ( V_10 ,
V_90 -> V_102 , V_90 -> V_44 ,
V_90 -> V_44 ? V_103 :
V_88 ) ;
F_50 ( & V_10 -> V_104 ) ;
V_10 -> V_95 . V_105 -- ;
F_51 ( & V_90 -> V_106 ) ;
F_52 ( & V_10 -> V_104 ) ;
F_36 ( V_90 ) ;
}
}
}
}
void F_53 ( struct V_9 * V_10 )
{
struct V_89 * V_90 ;
struct V_91 * V_92 , * V_93 ;
struct V_94 * V_60 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_10 -> V_95 . V_96 ; V_25 ++ ) {
V_60 = & ( V_10 -> V_95 . V_97 [ V_25 ] ) ;
F_49 (tmp_fil, tmp_hnode, n, head, fnode) {
F_30 ( V_10 , V_90 -> V_102 ,
V_90 -> V_44 , V_90 -> V_44 ?
V_103 : V_88 ) ;
F_50 ( & V_10 -> V_104 ) ;
V_10 -> V_95 . V_105 -- ;
F_51 ( & V_90 -> V_106 ) ;
F_52 ( & V_10 -> V_104 ) ;
F_36 ( V_90 ) ;
}
}
}
static int F_54 ( struct V_9 * V_10 , T_3 V_107 )
{
struct V_46 V_47 ;
int V_108 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_31 ( V_85 << 23 ) ;
V_47 . V_56 = F_31 ( V_109 |
( ( T_1 ) V_10 -> V_19 << 16 ) | ( ( T_1 ) 0x1 << 32 ) ) ;
V_47 . V_57 [ 0 ] = F_31 ( V_107 ) ;
V_108 = F_20 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_108 != 0 )
F_12 ( & V_10 -> V_16 -> V_17 , L_3 ,
V_107 ? L_4 : L_5 ) ;
return V_108 ;
}
int F_55 ( struct V_9 * V_10 , T_3 V_74 )
{
if ( F_54 ( V_10 , V_74 ) )
return - V_18 ;
if ( F_44 ( V_10 , V_79 ) ) {
F_54 ( V_10 , 0 ) ;
return - V_18 ;
}
F_13 ( 1000 ) ;
return 0 ;
}
void F_56 ( struct V_9 * V_10 )
{
int V_74 = V_75 ;
struct V_70 * V_66 = V_10 -> V_66 ;
F_54 ( V_10 , 0 ) ;
if ( V_66 -> V_76 & V_77 )
V_74 = V_79 ;
else if ( V_66 -> V_76 & V_81 )
V_74 = V_83 ;
F_44 ( V_10 , V_74 ) ;
F_13 ( 1000 ) ;
}
int F_57 ( struct V_9 * V_10 )
{
struct V_46 V_47 ;
int V_108 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_31 ( V_85 << 23 ) ;
V_47 . V_56 = F_31 ( V_110 |
( ( T_1 ) V_10 -> V_19 << 16 ) ) ;
V_47 . V_57 [ 0 ] = F_31 ( ( ( T_1 ) V_10 -> V_20 -> V_111 . V_107 ) << 32 ) ;
V_47 . V_57 [ 2 ] = F_31 ( V_10 -> V_20 -> V_111 . V_112 |
( ( T_1 ) V_10 -> V_20 -> V_111 . V_113 ) << 16 ) ;
V_47 . V_57 [ 5 ] = F_31 ( V_10 -> V_20 -> V_111 . V_114 |
( ( T_1 ) V_10 -> V_20 -> V_111 . type ) << 32 |
( ( T_1 ) V_10 -> V_20 -> V_111 . V_115 ) << 40 ) ;
V_108 = F_20 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_108 != 0 )
F_12 ( & V_10 -> V_66 -> V_17 ,
L_6 ) ;
return V_108 ;
}
int F_58 ( struct V_9 * V_10 , int V_116 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_108 ;
if ( ! F_21 ( V_32 , & V_10 -> V_33 ) )
return 0 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_31 ( V_85 << 23 ) ;
V_52 = V_117 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_31 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_31 ( V_116 ) ;
V_108 = F_20 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_108 != 0 )
F_12 ( & V_10 -> V_66 -> V_17 ,
L_7 ) ;
return V_108 ;
}
int F_59 ( struct V_9 * V_10 , V_3 V_116 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_108 ;
if ( ! ! ( V_10 -> V_76 & V_118 ) == V_116 )
return 0 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_31 ( V_85 << 23 ) ;
V_52 = V_119 |
( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_31 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_31 ( V_116 ) ;
V_108 = F_20 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_108 != 0 )
F_12 ( & V_10 -> V_66 -> V_17 ,
L_8 ) ;
V_10 -> V_76 ^= V_118 ;
return V_108 ;
}
int F_60 ( struct V_9 * V_10 , int V_116 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_25 , V_108 ;
static const T_1 V_120 [] = {
0xbeac01fa6a42b73bULL , 0x8030f20c77cb2da3ULL ,
0xae7b30b4d0ca2bcbULL , 0x43a38fb04167253dULL ,
0x255b0ec26d5a56daULL
} ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_31 ( V_85 << 23 ) ;
V_52 = V_121 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_31 ( V_52 ) ;
V_52 = ( ( T_1 ) ( V_122 & 0x3 ) << 4 ) |
( ( T_1 ) ( V_122 & 0x3 ) << 6 ) |
( ( T_1 ) ( V_116 & 0x1 ) << 8 ) |
( ( 0x7ULL ) << 48 ) ;
V_47 . V_57 [ 0 ] = F_31 ( V_52 ) ;
for ( V_25 = 0 ; V_25 < 5 ; V_25 ++ )
V_47 . V_57 [ V_25 + 1 ] = F_31 ( V_120 [ V_25 ] ) ;
V_108 = F_20 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_108 != 0 )
F_12 ( & V_10 -> V_66 -> V_17 , L_9 ) ;
return V_108 ;
}
int F_61 ( struct V_9 * V_10 , T_5 V_123 , int V_124 )
{
struct V_46 V_47 ;
struct V_125 * V_126 ;
T_1 V_52 ;
int V_108 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_31 ( V_85 << 23 ) ;
V_52 = V_127 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_31 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_31 ( V_124 ) ;
V_126 = (struct V_125 * ) & V_47 . V_57 [ 1 ] ;
V_126 -> V_128 = V_123 ;
V_108 = F_20 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_108 != 0 )
F_12 ( & V_10 -> V_66 -> V_17 ,
L_10 ,
( V_124 == V_129 ) ? L_11 : L_12 , V_123 ) ;
return V_108 ;
}
int F_62 ( struct V_9 * V_10 , int V_116 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_108 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_31 ( V_85 << 23 ) ;
V_52 = V_130 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_31 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_31 ( V_116 | ( V_116 << 8 ) ) ;
V_108 = F_20 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_108 != 0 )
F_12 ( & V_10 -> V_66 -> V_17 ,
L_13 ) ;
return V_108 ;
}
int F_63 ( struct V_9 * V_10 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_108 ;
if ( ! F_21 ( V_32 , & V_10 -> V_33 ) )
return 0 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_31 ( V_85 << 23 ) ;
V_52 = V_131 |
( ( T_1 ) V_10 -> V_19 << 16 ) |
( ( T_1 ) V_132 << 56 ) ;
V_47 . V_56 = F_31 ( V_52 ) ;
V_108 = F_20 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_108 != 0 )
F_12 ( & V_10 -> V_66 -> V_17 ,
L_14 ) ;
return V_108 ;
}
int F_64 ( struct V_70 * V_66 , int V_133 )
{
struct V_9 * V_10 = F_39 ( V_66 ) ;
int V_134 = 0 ;
if ( V_133 < V_135 || V_133 > V_136 ) {
F_12 ( & V_10 -> V_66 -> V_17 , L_15
L_16 , V_136 , V_135 ) ;
return - V_137 ;
}
V_134 = F_65 ( V_10 , V_133 ) ;
if ( ! V_134 )
V_66 -> V_133 = V_133 ;
return V_134 ;
}
T_6 F_66 ( struct V_70 * V_66 ,
T_6 V_138 )
{
struct V_9 * V_10 = F_39 ( V_66 ) ;
if ( ( V_10 -> V_76 & V_139 ) ) {
T_6 V_140 = V_138 ^ V_66 -> V_138 ;
V_138 ^= V_140 & ( V_141 | V_142 ) ;
}
if ( ! ( V_138 & V_142 ) )
V_138 &= ~ V_143 ;
return V_138 ;
}
int F_67 ( struct V_70 * V_66 , T_6 V_138 )
{
struct V_9 * V_10 = F_39 ( V_66 ) ;
T_6 V_140 = V_66 -> V_138 ^ V_138 ;
int V_144 = ( V_138 & V_143 ) ? V_145 : 0 ;
if ( ! ( V_140 & V_143 ) )
return 0 ;
V_66 -> V_138 = V_138 ^ V_143 ;
if ( F_58 ( V_10 , V_144 ) )
return - V_18 ;
if ( ( V_144 == 0 ) && F_63 ( V_10 ) )
return - V_18 ;
return 0 ;
}
static int F_68 ( struct V_146 * V_20 ,
T_7 V_147 , void T_2 * * V_1 )
{
const struct V_148 * V_149 ;
if ( ( V_147 >= V_150 ) || ( V_147 < V_151 ) )
return - V_137 ;
V_147 -= V_151 ;
V_149 = & V_152 [ F_69 ( V_147 ) ] . V_153 [ F_70 ( V_147 ) ] ;
if ( V_149 -> V_154 && ( V_149 -> V_155 <= V_147 ) && ( V_149 -> V_156 > V_147 ) ) {
* V_1 = V_20 -> V_21 + V_149 -> V_157 +
( V_147 - V_149 -> V_155 ) ;
return 0 ;
}
* V_1 = V_20 -> V_21 + V_158 + ( V_147 & F_71 ( 16 ) ) ;
return 1 ;
}
static int
F_72 ( struct V_9 * V_10 , T_7 V_147 )
{
V_3 V_159 ;
void T_2 * V_1 = V_10 -> V_20 -> V_21 + V_160 ;
V_147 -= V_151 ;
V_159 = F_73 ( V_147 ) ;
if ( V_159 == 0 ) {
F_12 ( & V_10 -> V_16 -> V_17 , L_17 , V_147 ) ;
return - V_18 ;
}
F_4 ( V_159 , V_1 ) ;
if ( F_2 ( V_1 ) != V_159 ) {
if ( F_74 () )
F_75 ( & V_10 -> V_16 -> V_17 ,
L_18 ,
V_159 , V_147 ) ;
return - V_18 ;
}
return 0 ;
}
int
F_76 ( struct V_9 * V_10 , T_7 V_147 , V_3 V_5 )
{
unsigned long V_76 ;
int V_108 ;
void T_2 * V_1 = NULL ;
V_108 = F_68 ( V_10 -> V_20 , V_147 , & V_1 ) ;
if ( V_108 == 0 ) {
F_4 ( V_5 , V_1 ) ;
return 0 ;
}
if ( V_108 > 0 ) {
F_77 ( & V_10 -> V_20 -> V_161 , V_76 ) ;
F_78 ( V_10 ) ;
V_108 = F_72 ( V_10 , V_147 ) ;
if ( ! V_108 )
F_4 ( V_5 , V_1 ) ;
F_79 ( V_10 ) ;
F_80 ( & V_10 -> V_20 -> V_161 , V_76 ) ;
return V_108 ;
}
F_12 ( & V_10 -> V_16 -> V_17 ,
L_19 , V_162 , V_147 ) ;
F_81 () ;
return - V_18 ;
}
int F_82 ( struct V_9 * V_10 , T_7 V_147 )
{
unsigned long V_76 ;
int V_108 ;
V_3 V_5 = - 1 ;
void T_2 * V_1 = NULL ;
V_108 = F_68 ( V_10 -> V_20 , V_147 , & V_1 ) ;
if ( V_108 == 0 )
return F_2 ( V_1 ) ;
if ( V_108 > 0 ) {
F_77 ( & V_10 -> V_20 -> V_161 , V_76 ) ;
F_78 ( V_10 ) ;
if ( ! F_72 ( V_10 , V_147 ) )
V_5 = F_2 ( V_1 ) ;
F_79 ( V_10 ) ;
F_80 ( & V_10 -> V_20 -> V_161 , V_76 ) ;
return V_5 ;
}
F_12 ( & V_10 -> V_16 -> V_17 ,
L_19 , V_162 , V_147 ) ;
F_81 () ;
return - 1 ;
}
void T_2 * F_83 ( struct V_146 * V_20 ,
V_3 V_163 )
{
void T_2 * V_1 = NULL ;
F_84 ( F_68 ( V_20 , V_163 , & V_1 ) ) ;
return V_1 ;
}
static int F_85 ( struct V_9 * V_10 ,
V_3 V_159 , T_1 V_147 , T_1 * V_5 , int V_45 )
{
void T_2 * V_1 ;
V_3 V_164 ;
F_86 ( & V_10 -> V_20 -> V_165 ) ;
F_4 ( V_159 , V_10 -> V_20 -> V_166 ) ;
F_2 ( V_10 -> V_20 -> V_166 ) ;
V_164 = V_167 + V_147 ;
V_1 = V_10 -> V_20 -> V_21 + V_164 ;
if ( V_45 == 0 )
* V_5 = F_1 ( V_1 ) ;
else
F_3 ( * V_5 , V_1 ) ;
F_4 ( 0 , V_10 -> V_20 -> V_166 ) ;
F_2 ( V_10 -> V_20 -> V_166 ) ;
F_87 ( & V_10 -> V_20 -> V_165 ) ;
return 0 ;
}
void
F_88 ( struct V_9 * V_10 , T_1 V_147 , T_1 * V_5 )
{
void T_2 * V_1 = V_10 -> V_20 -> V_21 +
V_168 + ( V_147 - V_169 ) ;
F_86 ( & V_10 -> V_20 -> V_165 ) ;
* V_5 = F_1 ( V_1 ) ;
F_87 ( & V_10 -> V_20 -> V_165 ) ;
}
void
F_89 ( struct V_9 * V_10 , T_1 V_147 , T_1 V_5 )
{
void T_2 * V_1 = V_10 -> V_20 -> V_21 +
V_168 + ( V_147 - V_169 ) ;
F_86 ( & V_10 -> V_20 -> V_165 ) ;
F_3 ( V_5 , V_1 ) ;
F_87 ( & V_10 -> V_20 -> V_165 ) ;
}
static void F_90 ( struct V_9 * V_10 , T_1 V_147 ,
struct V_170 * V_171 )
{
V_171 -> V_172 = V_173 ;
V_171 -> V_174 = V_175 ;
V_171 -> V_176 = V_177 ;
if ( V_147 & 0xf ) {
V_171 -> V_178 [ 0 ] = V_179 ;
V_171 -> V_180 [ 0 ] = V_181 ;
V_171 -> V_178 [ 1 ] = V_182 ;
V_171 -> V_180 [ 1 ] = V_183 ;
V_171 -> V_178 [ 2 ] = V_184 ;
V_171 -> V_178 [ 3 ] = V_185 ;
V_171 -> V_180 [ 2 ] = V_186 ;
V_171 -> V_180 [ 3 ] = V_187 ;
} else {
V_171 -> V_178 [ 0 ] = V_184 ;
V_171 -> V_180 [ 0 ] = V_186 ;
V_171 -> V_178 [ 1 ] = V_185 ;
V_171 -> V_180 [ 1 ] = V_187 ;
V_171 -> V_178 [ 2 ] = V_179 ;
V_171 -> V_178 [ 3 ] = V_182 ;
V_171 -> V_180 [ 2 ] = V_181 ;
V_171 -> V_180 [ 3 ] = V_183 ;
}
V_171 -> V_188 = F_91 ( V_147 ) ;
V_171 -> V_147 = F_92 ( V_147 ) ;
}
int F_93 ( struct V_9 * V_10 , T_1 V_147 , T_1 V_5 )
{
int V_189 , V_190 = 0 ;
V_3 V_191 , V_192 ;
struct V_170 V_171 ;
if ( V_147 & 7 )
return - V_18 ;
memset ( & V_171 , 0 , sizeof( struct V_170 ) ) ;
if ( ! ( F_94 ( V_147 , V_193 ,
V_194 ) ||
F_94 ( V_147 , V_195 ,
V_196 ) ) )
return - V_18 ;
F_90 ( V_10 , V_147 , & V_171 ) ;
if ( F_94 ( V_147 , V_197 , V_198 ) )
return F_85 ( V_10 , V_171 . V_188 ,
V_171 . V_147 , & V_5 , 1 ) ;
V_192 = V_147 & ~ 0xf ;
F_86 ( & V_10 -> V_20 -> V_165 ) ;
F_19 ( V_10 , V_171 . V_174 , V_192 ) ;
F_19 ( V_10 , V_171 . V_176 , 0 ) ;
F_19 ( V_10 , V_171 . V_172 , V_199 ) ;
F_19 ( V_10 , V_171 . V_172 , V_200 ) ;
for ( V_189 = 0 ; V_189 < V_201 ; V_189 ++ ) {
V_191 = F_17 ( V_10 , V_171 . V_172 ) ;
if ( ( V_191 & V_202 ) == 0 )
break;
}
if ( V_189 >= V_201 ) {
V_190 = - V_18 ;
goto V_13;
}
F_19 ( V_10 , V_171 . V_178 [ 0 ] , F_17 ( V_10 , V_171 . V_180 [ 0 ] ) ) ;
F_19 ( V_10 , V_171 . V_178 [ 1 ] , F_17 ( V_10 , V_171 . V_180 [ 1 ] ) ) ;
F_19 ( V_10 , V_171 . V_178 [ 2 ] , V_5 & 0xffffffff ) ;
F_19 ( V_10 , V_171 . V_178 [ 3 ] , ( V_5 >> 32 ) & 0xffffffff ) ;
F_19 ( V_10 , V_171 . V_172 , V_203 ) ;
F_19 ( V_10 , V_171 . V_172 , V_204 ) ;
for ( V_189 = 0 ; V_189 < V_201 ; V_189 ++ ) {
V_191 = F_17 ( V_10 , V_171 . V_172 ) ;
if ( ( V_191 & V_202 ) == 0 )
break;
}
if ( V_189 >= V_201 ) {
if ( F_74 () )
F_12 ( & V_10 -> V_16 -> V_17 ,
L_20 ) ;
V_190 = - V_18 ;
} else
V_190 = 0 ;
V_13:
F_87 ( & V_10 -> V_20 -> V_165 ) ;
return V_190 ;
}
int F_95 ( struct V_9 * V_10 , T_1 V_147 , T_1 * V_5 )
{
int V_189 , V_190 ;
V_3 V_191 , V_192 ;
T_1 V_2 ;
struct V_170 V_171 ;
if ( V_147 & 7 )
return - V_18 ;
if ( ! ( F_94 ( V_147 , V_193 ,
V_194 ) ||
F_94 ( V_147 , V_195 ,
V_196 ) ) )
return - V_18 ;
memset ( & V_171 , 0 , sizeof( struct V_170 ) ) ;
F_90 ( V_10 , V_147 , & V_171 ) ;
if ( F_94 ( V_147 , V_197 , V_198 ) )
return F_85 ( V_10 , V_171 . V_188 ,
V_171 . V_147 , V_5 , 0 ) ;
F_86 ( & V_10 -> V_20 -> V_165 ) ;
V_192 = V_147 & ~ 0xf ;
F_19 ( V_10 , V_171 . V_174 , V_192 ) ;
F_19 ( V_10 , V_171 . V_176 , 0 ) ;
F_19 ( V_10 , V_171 . V_172 , V_199 ) ;
F_19 ( V_10 , V_171 . V_172 , V_200 ) ;
for ( V_189 = 0 ; V_189 < V_201 ; V_189 ++ ) {
V_191 = F_17 ( V_10 , V_171 . V_172 ) ;
if ( ( V_191 & V_202 ) == 0 )
break;
}
if ( V_189 >= V_201 ) {
if ( F_74 () )
F_12 ( & V_10 -> V_16 -> V_17 ,
L_21 ) ;
V_190 = - V_18 ;
} else {
V_191 = F_17 ( V_10 , V_171 . V_180 [ 3 ] ) ;
V_2 = ( T_1 ) V_191 << 32 ;
V_2 |= F_17 ( V_10 , V_171 . V_180 [ 2 ] ) ;
* V_5 = V_2 ;
V_190 = 0 ;
}
F_87 ( & V_10 -> V_20 -> V_165 ) ;
return V_190 ;
}
int F_96 ( struct V_9 * V_10 )
{
int V_163 , V_205 , V_206 ;
struct V_207 * V_16 = V_10 -> V_16 ;
V_163 = V_208 ;
if ( F_97 ( V_10 , V_163 , & V_206 ) )
return - V_18 ;
if ( V_206 != V_209 ) {
F_12 ( & V_16 -> V_17 , L_22 ,
V_206 ) ;
return - V_18 ;
}
V_163 = V_210 ;
if ( F_97 ( V_10 , V_163 , & V_205 ) )
return - V_18 ;
V_10 -> V_20 -> V_205 = V_205 ;
if ( V_205 == V_211 ) {
V_3 V_212 = F_9 ( V_10 , V_213 ) ;
if ( ( V_212 & 0x8000 ) == 0 )
V_205 = V_214 ;
}
switch ( V_205 ) {
case V_215 :
case V_216 :
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
V_10 -> V_20 -> V_225 = V_226 ;
break;
case V_227 :
case V_228 :
case V_211 :
V_10 -> V_20 -> V_225 = V_229 ;
break;
case V_214 :
V_10 -> V_20 -> V_225 = ( V_10 -> V_19 < 2 ) ?
V_226 : V_229 ;
break;
default:
F_12 ( & V_16 -> V_17 , L_23 , V_205 ) ;
V_10 -> V_20 -> V_225 = V_226 ;
break;
}
return 0 ;
}
int
F_98 ( struct V_9 * V_10 )
{
V_3 V_230 ;
V_230 = F_9 ( V_10 , V_231 ) ;
if ( V_230 & ( 1UL << V_10 -> V_19 ) ) {
V_230 = F_9 ( V_10 , V_232 ) ;
if ( V_230 & ( 1 << V_10 -> V_19 ) )
return 1 ;
}
return 0 ;
}
int F_99 ( struct V_9 * V_10 , V_3 V_33 , V_3 V_233 )
{
struct V_46 V_47 ;
int V_108 ;
T_1 V_52 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_31 ( V_85 << 23 ) ;
V_52 = V_234 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_31 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_31 ( ( T_1 ) V_233 << 32 ) ;
V_47 . V_57 [ 1 ] = F_31 ( V_33 ) ;
V_108 = F_20 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_108 )
F_12 ( & V_10 -> V_16 -> V_17 , L_24 ) ;
return V_108 ;
}
