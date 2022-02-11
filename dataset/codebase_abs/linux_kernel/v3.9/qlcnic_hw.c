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
int F_17 ( struct V_9 * V_10 , V_3 V_1 )
{
V_3 V_5 ;
if ( F_18 ( V_10 ) )
F_5 ( V_1 , V_10 -> V_20 -> V_21 , & V_5 ) ;
else {
V_5 = F_19 ( V_10 , V_1 ) ;
if ( V_5 == - V_18 )
return - V_18 ;
}
return V_5 ;
}
void F_20 ( struct V_9 * V_10 , V_3 V_1 , V_3 V_5 )
{
if ( F_18 ( V_10 ) )
F_7 ( V_1 , V_10 -> V_20 -> V_21 , V_5 ) ;
else
F_21 ( V_10 , V_1 , V_5 ) ;
}
static int
F_22 ( struct V_9 * V_10 ,
struct V_22 * V_23 , int V_24 )
{
V_3 V_25 , V_26 ;
struct V_27 * V_28 ;
struct V_22 * V_29 ;
struct V_30 * V_31 ;
V_25 = 0 ;
if ( ! F_23 ( V_32 , & V_10 -> V_33 ) )
return - V_18 ;
V_31 = V_10 -> V_31 ;
F_24 ( V_31 -> V_34 ) ;
V_26 = V_31 -> V_26 ;
if ( V_24 >= F_25 ( V_31 ) ) {
F_26 ( V_31 -> V_34 ) ;
F_27 () ;
if ( F_25 ( V_31 ) > V_24 ) {
if ( F_25 ( V_31 ) > V_35 )
F_28 ( V_31 -> V_34 ) ;
} else {
V_10 -> V_36 . V_37 ++ ;
F_29 ( V_31 -> V_34 ) ;
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
V_26 = F_30 ( V_26 , V_31 -> V_43 ) ;
V_25 ++ ;
} while ( V_25 != V_24 );
V_31 -> V_26 = V_26 ;
F_31 ( V_31 ) ;
F_29 ( V_31 -> V_34 ) ;
return 0 ;
}
int F_32 ( struct V_9 * V_10 , T_3 * V_1 ,
T_4 V_44 , T_3 V_45 )
{
struct V_46 V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
T_1 V_52 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_54 << 23 ) ;
V_52 = V_55 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_49 = (struct V_48 * ) & V_47 . V_57 [ 0 ] ;
V_49 -> V_45 = V_45 ;
memcpy ( V_49 -> V_58 , V_1 , 6 ) ;
V_51 = (struct V_50 * ) & V_47 . V_57 [ 1 ] ;
V_51 -> V_44 = V_44 ;
return F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
}
int F_34 ( struct V_9 * V_10 , const T_3 * V_1 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 ;
int V_63 = - V_64 ;
F_35 (head, &adapter->mac_list) {
V_62 = F_36 ( V_60 , struct V_61 , V_65 ) ;
if ( memcmp ( V_1 , V_62 -> V_58 , V_66 ) == 0 ) {
V_63 = F_37 ( V_10 , V_62 -> V_58 ,
0 , V_67 ) ;
if ( V_63 )
return V_63 ;
F_38 ( & V_62 -> V_65 ) ;
F_39 ( V_62 ) ;
return V_63 ;
}
}
return V_63 ;
}
int F_40 ( struct V_9 * V_10 , const T_3 * V_1 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 ;
F_35 (head, &adapter->mac_list) {
V_62 = F_36 ( V_60 , struct V_61 , V_65 ) ;
if ( memcmp ( V_1 , V_62 -> V_58 , V_66 ) == 0 )
return 0 ;
}
V_62 = F_41 ( sizeof( struct V_61 ) , V_68 ) ;
if ( V_62 == NULL )
return - V_69 ;
memcpy ( V_62 -> V_58 , V_1 , V_66 ) ;
if ( F_37 ( V_10 ,
V_62 -> V_58 , 0 , V_70 ) ) {
F_39 ( V_62 ) ;
return - V_18 ;
}
F_42 ( & V_62 -> V_65 , & V_10 -> V_71 ) ;
return 0 ;
}
void F_43 ( struct V_72 * V_73 )
{
struct V_9 * V_10 = F_44 ( V_73 ) ;
struct V_74 * V_75 ;
static const T_3 V_76 [ V_66 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
V_3 V_77 = V_78 ;
if ( ! F_23 ( V_32 , & V_10 -> V_33 ) )
return;
F_40 ( V_10 , V_10 -> V_58 ) ;
F_40 ( V_10 , V_76 ) ;
if ( V_73 -> V_79 & V_80 ) {
if ( ! ( V_10 -> V_79 & V_81 ) )
V_77 = V_82 ;
goto V_83;
}
if ( ( V_73 -> V_79 & V_84 ) ||
( F_45 ( V_73 ) > V_10 -> V_20 -> V_85 ) ) {
V_77 = V_86 ;
goto V_83;
}
if ( ! F_46 ( V_73 ) ) {
F_47 (ha, netdev) {
F_40 ( V_10 , V_75 -> V_1 ) ;
}
}
V_83:
if ( V_77 == V_82 && ! V_10 -> V_87 ) {
F_48 ( V_10 ) ;
V_10 -> V_88 = true ;
} else {
V_10 -> V_88 = false ;
}
F_49 ( V_10 , V_77 ) ;
}
int F_50 ( struct V_9 * V_10 , V_3 V_77 )
{
struct V_46 V_47 ;
T_1 V_52 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_89 << 23 ) ;
V_52 = V_90 |
( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_33 ( V_77 ) ;
return F_22 ( V_10 ,
(struct V_22 * ) & V_47 , 1 ) ;
}
void F_51 ( struct V_9 * V_10 )
{
struct V_61 * V_62 ;
struct V_59 * V_60 = & V_10 -> V_71 ;
while ( ! F_52 ( V_60 ) ) {
V_62 = F_36 ( V_60 -> V_91 , struct V_61 , V_65 ) ;
F_37 ( V_10 ,
V_62 -> V_58 , 0 , V_67 ) ;
F_38 ( & V_62 -> V_65 ) ;
F_39 ( V_62 ) ;
}
}
void F_53 ( struct V_9 * V_10 )
{
struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_60 ;
int V_25 ;
unsigned long time ;
T_3 V_97 ;
for ( V_25 = 0 ; V_25 < V_10 -> V_98 . V_99 ; V_25 ++ ) {
V_60 = & ( V_10 -> V_98 . V_100 [ V_25 ] ) ;
F_54 (tmp_fil, n, head, fnode) {
V_97 = V_93 -> V_44 ? V_101 :
V_67 ;
time = V_93 -> V_102 ;
if ( V_103 > ( V_104 * V_105 + time ) ) {
F_37 ( V_10 ,
V_93 -> V_106 ,
V_93 -> V_44 ,
V_97 ) ;
F_55 ( & V_10 -> V_107 ) ;
V_10 -> V_98 . V_108 -- ;
F_56 ( & V_93 -> V_109 ) ;
F_57 ( & V_10 -> V_107 ) ;
F_39 ( V_93 ) ;
}
}
}
for ( V_25 = 0 ; V_25 < V_10 -> V_110 . V_99 ; V_25 ++ ) {
V_60 = & ( V_10 -> V_110 . V_100 [ V_25 ] ) ;
F_54 (tmp_fil, n, head, fnode)
{
time = V_93 -> V_102 ;
if ( V_103 > ( V_104 * V_105 + time ) ) {
F_55 ( & V_10 -> V_111 ) ;
V_10 -> V_110 . V_108 -- ;
F_56 ( & V_93 -> V_109 ) ;
F_57 ( & V_10 -> V_111 ) ;
F_39 ( V_93 ) ;
}
}
}
}
void F_58 ( struct V_9 * V_10 )
{
struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_60 ;
int V_25 ;
T_3 V_97 ;
for ( V_25 = 0 ; V_25 < V_10 -> V_98 . V_99 ; V_25 ++ ) {
V_60 = & ( V_10 -> V_98 . V_100 [ V_25 ] ) ;
F_54 (tmp_fil, n, head, fnode) {
V_97 = V_93 -> V_44 ? V_101 :
V_67 ;
F_37 ( V_10 ,
V_93 -> V_106 ,
V_93 -> V_44 ,
V_97 ) ;
F_55 ( & V_10 -> V_107 ) ;
V_10 -> V_98 . V_108 -- ;
F_56 ( & V_93 -> V_109 ) ;
F_57 ( & V_10 -> V_107 ) ;
F_39 ( V_93 ) ;
}
}
}
static int F_59 ( struct V_9 * V_10 , T_3 V_112 )
{
struct V_46 V_47 ;
int V_113 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_89 << 23 ) ;
V_47 . V_56 = F_33 ( V_114 |
( ( T_1 ) V_10 -> V_19 << 16 ) | ( ( T_1 ) 0x1 << 32 ) ) ;
V_47 . V_57 [ 0 ] = F_33 ( V_112 ) ;
V_113 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_113 != 0 )
F_12 ( & V_10 -> V_16 -> V_17 , L_2 ,
V_112 ? L_3 : L_4 ) ;
return V_113 ;
}
int F_60 ( struct V_9 * V_10 , T_3 V_77 )
{
if ( F_59 ( V_10 , V_77 ) )
return - V_18 ;
if ( F_49 ( V_10 ,
V_82 ) ) {
F_59 ( V_10 , 0 ) ;
return - V_18 ;
}
F_13 ( 1000 ) ;
return 0 ;
}
int F_61 ( struct V_9 * V_10 , T_3 V_77 )
{
struct V_72 * V_73 = V_10 -> V_73 ;
V_77 = V_78 ;
F_59 ( V_10 , 0 ) ;
if ( V_73 -> V_79 & V_80 )
V_77 = V_82 ;
else if ( V_73 -> V_79 & V_84 )
V_77 = V_86 ;
F_49 ( V_10 , V_77 ) ;
F_13 ( 1000 ) ;
return 0 ;
}
void F_62 ( struct V_9 * V_10 )
{
struct V_46 V_47 ;
int V_113 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_89 << 23 ) ;
V_47 . V_56 = F_33 ( V_115 |
( ( T_1 ) V_10 -> V_19 << 16 ) ) ;
V_47 . V_57 [ 0 ] = F_33 ( ( ( T_1 ) V_10 -> V_20 -> V_116 . V_112 ) << 32 ) ;
V_47 . V_57 [ 2 ] = F_33 ( V_10 -> V_20 -> V_116 . V_117 |
( ( T_1 ) V_10 -> V_20 -> V_116 . V_118 ) << 16 ) ;
V_47 . V_57 [ 5 ] = F_33 ( V_10 -> V_20 -> V_116 . V_119 |
( ( T_1 ) V_10 -> V_20 -> V_116 . type ) << 32 |
( ( T_1 ) V_10 -> V_20 -> V_116 . V_120 ) << 40 ) ;
V_113 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_113 != 0 )
F_12 ( & V_10 -> V_73 -> V_17 ,
L_5 ) ;
}
int F_63 ( struct V_9 * V_10 , int V_121 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_113 ;
if ( ! F_23 ( V_32 , & V_10 -> V_33 ) )
return 0 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_89 << 23 ) ;
V_52 = V_122 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_52 = 0 ;
if ( V_121 ) {
V_52 = V_123 | V_124 ;
if ( V_10 -> V_20 -> V_125 & V_126 )
V_52 |= V_127 |
V_128 ;
}
V_47 . V_57 [ 0 ] = F_33 ( V_52 ) ;
V_113 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_113 != 0 )
F_12 ( & V_10 -> V_73 -> V_17 ,
L_6 ) ;
return V_113 ;
}
int F_64 ( struct V_9 * V_10 , V_3 V_121 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_113 ;
if ( ! ! ( V_10 -> V_79 & V_129 ) == V_121 )
return 0 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_89 << 23 ) ;
V_52 = V_130 |
( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_33 ( V_121 ) ;
V_113 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_113 != 0 )
F_12 ( & V_10 -> V_73 -> V_17 ,
L_7 ) ;
V_10 -> V_79 ^= V_129 ;
return V_113 ;
}
int F_65 ( struct V_9 * V_10 , int V_121 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_25 , V_113 ;
static const T_1 V_131 [] = {
0xbeac01fa6a42b73bULL , 0x8030f20c77cb2da3ULL ,
0xae7b30b4d0ca2bcbULL , 0x43a38fb04167253dULL ,
0x255b0ec26d5a56daULL
} ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_89 << 23 ) ;
V_52 = V_132 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_52 = ( ( T_1 ) ( V_133 & 0x3 ) << 4 ) |
( ( T_1 ) ( V_133 & 0x3 ) << 6 ) |
( ( T_1 ) ( V_121 & 0x1 ) << 8 ) |
( ( T_1 ) V_134 << 48 ) |
( T_1 ) V_135 |
( T_1 ) V_136 ;
V_47 . V_57 [ 0 ] = F_33 ( V_52 ) ;
for ( V_25 = 0 ; V_25 < 5 ; V_25 ++ )
V_47 . V_57 [ V_25 + 1 ] = F_33 ( V_131 [ V_25 ] ) ;
V_113 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_113 != 0 )
F_12 ( & V_10 -> V_73 -> V_17 , L_8 ) ;
return V_113 ;
}
void F_66 ( struct V_9 * V_10 ,
T_5 V_137 , int V_97 )
{
struct V_46 V_47 ;
struct V_138 * V_139 ;
T_1 V_52 ;
int V_113 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_89 << 23 ) ;
V_52 = V_140 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_33 ( V_97 ) ;
V_139 = (struct V_138 * ) & V_47 . V_57 [ 1 ] ;
V_139 -> V_141 = V_137 ;
V_113 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_113 != 0 )
F_12 ( & V_10 -> V_73 -> V_17 ,
L_9 ,
( V_97 == V_142 ) ? L_10 : L_11 , V_137 ) ;
}
int F_67 ( struct V_9 * V_10 , int V_121 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_113 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_89 << 23 ) ;
V_52 = V_143 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_33 ( V_121 | ( V_121 << 8 ) ) ;
V_113 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_113 != 0 )
F_12 ( & V_10 -> V_73 -> V_17 ,
L_12 ) ;
return V_113 ;
}
int F_68 ( struct V_9 * V_10 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_113 ;
if ( ! F_23 ( V_32 , & V_10 -> V_33 ) )
return 0 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_89 << 23 ) ;
V_52 = V_144 |
( ( T_1 ) V_10 -> V_19 << 16 ) |
( ( T_1 ) V_145 << 56 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_113 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_113 != 0 )
F_12 ( & V_10 -> V_73 -> V_17 ,
L_13 ) ;
return V_113 ;
}
int F_69 ( struct V_72 * V_73 , int V_146 )
{
struct V_9 * V_10 = F_44 ( V_73 ) ;
int V_147 = 0 ;
if ( V_146 < V_148 || V_146 > V_149 ) {
F_12 ( & V_10 -> V_73 -> V_17 , L_14
L_15 , V_149 , V_148 ) ;
return - V_64 ;
}
V_147 = F_70 ( V_10 , V_146 ) ;
if ( ! V_147 )
V_73 -> V_146 = V_146 ;
return V_147 ;
}
T_6 F_71 ( struct V_72 * V_73 ,
T_6 V_150 )
{
struct V_9 * V_10 = F_44 ( V_73 ) ;
if ( ( V_10 -> V_79 & V_151 ) &&
F_18 ( V_10 ) ) {
T_6 V_152 = V_150 ^ V_73 -> V_150 ;
V_150 ^= V_152 & ( V_153 | V_154 ) ;
}
if ( ! ( V_150 & V_154 ) )
V_150 &= ~ V_155 ;
return V_150 ;
}
int F_72 ( struct V_72 * V_73 , T_6 V_150 )
{
struct V_9 * V_10 = F_44 ( V_73 ) ;
T_6 V_152 = V_73 -> V_150 ^ V_150 ;
int V_156 = ( V_150 & V_155 ) ? V_157 : 0 ;
if ( ! ( V_152 & V_155 ) )
return 0 ;
V_73 -> V_150 ^= V_155 ;
if ( F_73 ( V_10 , V_156 ) )
return - V_18 ;
if ( ! V_156 && F_18 ( V_10 ) ) {
if ( F_68 ( V_10 ) )
return - V_18 ;
}
return 0 ;
}
static int F_74 ( struct V_158 * V_20 ,
T_7 V_159 , void T_2 * * V_1 )
{
const struct V_160 * V_161 ;
if ( ( V_159 >= V_162 ) || ( V_159 < V_163 ) )
return - V_64 ;
V_159 -= V_163 ;
V_161 = & V_164 [ F_75 ( V_159 ) ] . V_165 [ F_76 ( V_159 ) ] ;
if ( V_161 -> V_166 && ( V_161 -> V_167 <= V_159 ) && ( V_161 -> V_168 > V_159 ) ) {
* V_1 = V_20 -> V_21 + V_161 -> V_169 +
( V_159 - V_161 -> V_167 ) ;
return 0 ;
}
* V_1 = V_20 -> V_21 + V_170 + ( V_159 & F_77 ( 16 ) ) ;
return 1 ;
}
static int
F_78 ( struct V_9 * V_10 , T_7 V_159 )
{
V_3 V_171 ;
void T_2 * V_1 = V_10 -> V_20 -> V_21 + V_172 ;
V_159 -= V_163 ;
V_171 = F_79 ( V_159 ) ;
if ( V_171 == 0 ) {
F_12 ( & V_10 -> V_16 -> V_17 , L_16 , V_159 ) ;
return - V_18 ;
}
F_4 ( V_171 , V_1 ) ;
if ( F_2 ( V_1 ) != V_171 ) {
if ( F_80 () )
F_81 ( & V_10 -> V_16 -> V_17 ,
L_17 ,
V_171 , V_159 ) ;
return - V_18 ;
}
return 0 ;
}
int F_82 ( struct V_9 * V_10 , T_7 V_159 ,
V_3 V_5 )
{
unsigned long V_79 ;
int V_113 ;
void T_2 * V_1 = NULL ;
V_113 = F_74 ( V_10 -> V_20 , V_159 , & V_1 ) ;
if ( V_113 == 0 ) {
F_4 ( V_5 , V_1 ) ;
return 0 ;
}
if ( V_113 > 0 ) {
F_83 ( & V_10 -> V_20 -> V_173 , V_79 ) ;
F_84 ( V_10 ) ;
V_113 = F_78 ( V_10 , V_159 ) ;
if ( ! V_113 )
F_4 ( V_5 , V_1 ) ;
F_85 ( V_10 ) ;
F_86 ( & V_10 -> V_20 -> V_173 , V_79 ) ;
return V_113 ;
}
F_12 ( & V_10 -> V_16 -> V_17 ,
L_18 , V_174 , V_159 ) ;
F_87 () ;
return - V_18 ;
}
int F_88 ( struct V_9 * V_10 , T_7 V_159 )
{
unsigned long V_79 ;
int V_113 ;
V_3 V_5 = - 1 ;
void T_2 * V_1 = NULL ;
V_113 = F_74 ( V_10 -> V_20 , V_159 , & V_1 ) ;
if ( V_113 == 0 )
return F_2 ( V_1 ) ;
if ( V_113 > 0 ) {
F_83 ( & V_10 -> V_20 -> V_173 , V_79 ) ;
F_84 ( V_10 ) ;
if ( ! F_78 ( V_10 , V_159 ) )
V_5 = F_2 ( V_1 ) ;
F_85 ( V_10 ) ;
F_86 ( & V_10 -> V_20 -> V_173 , V_79 ) ;
return V_5 ;
}
F_12 ( & V_10 -> V_16 -> V_17 ,
L_18 , V_174 , V_159 ) ;
F_87 () ;
return - 1 ;
}
void T_2 * F_89 ( struct V_158 * V_20 ,
V_3 V_175 )
{
void T_2 * V_1 = NULL ;
F_90 ( F_74 ( V_20 , V_175 , & V_1 ) ) ;
return V_1 ;
}
static int F_91 ( struct V_9 * V_10 ,
V_3 V_171 , T_1 V_159 , T_1 * V_5 , int V_45 )
{
void T_2 * V_1 ;
V_3 V_176 ;
F_92 ( & V_10 -> V_20 -> V_177 ) ;
F_4 ( V_171 , V_10 -> V_20 -> V_178 ) ;
F_2 ( V_10 -> V_20 -> V_178 ) ;
V_176 = V_179 + V_159 ;
V_1 = V_10 -> V_20 -> V_21 + V_176 ;
if ( V_45 == 0 )
* V_5 = F_1 ( V_1 ) ;
else
F_3 ( * V_5 , V_1 ) ;
F_4 ( 0 , V_10 -> V_20 -> V_178 ) ;
F_2 ( V_10 -> V_20 -> V_178 ) ;
F_93 ( & V_10 -> V_20 -> V_177 ) ;
return 0 ;
}
void
F_94 ( struct V_9 * V_10 , T_1 V_159 , T_1 * V_5 )
{
void T_2 * V_1 = V_10 -> V_20 -> V_21 +
V_180 + ( V_159 - V_181 ) ;
F_92 ( & V_10 -> V_20 -> V_177 ) ;
* V_5 = F_1 ( V_1 ) ;
F_93 ( & V_10 -> V_20 -> V_177 ) ;
}
void
F_95 ( struct V_9 * V_10 , T_1 V_159 , T_1 V_5 )
{
void T_2 * V_1 = V_10 -> V_20 -> V_21 +
V_180 + ( V_159 - V_181 ) ;
F_92 ( & V_10 -> V_20 -> V_177 ) ;
F_3 ( V_5 , V_1 ) ;
F_93 ( & V_10 -> V_20 -> V_177 ) ;
}
static void F_96 ( struct V_9 * V_10 , T_1 V_159 ,
struct V_182 * V_183 )
{
V_183 -> V_184 = V_185 ;
V_183 -> V_186 = V_187 ;
V_183 -> V_188 = V_189 ;
if ( V_159 & 0xf ) {
V_183 -> V_190 [ 0 ] = V_191 ;
V_183 -> V_192 [ 0 ] = V_193 ;
V_183 -> V_190 [ 1 ] = V_194 ;
V_183 -> V_192 [ 1 ] = V_195 ;
V_183 -> V_190 [ 2 ] = V_196 ;
V_183 -> V_190 [ 3 ] = V_197 ;
V_183 -> V_192 [ 2 ] = V_198 ;
V_183 -> V_192 [ 3 ] = V_199 ;
} else {
V_183 -> V_190 [ 0 ] = V_196 ;
V_183 -> V_192 [ 0 ] = V_198 ;
V_183 -> V_190 [ 1 ] = V_197 ;
V_183 -> V_192 [ 1 ] = V_199 ;
V_183 -> V_190 [ 2 ] = V_191 ;
V_183 -> V_190 [ 3 ] = V_194 ;
V_183 -> V_192 [ 2 ] = V_193 ;
V_183 -> V_192 [ 3 ] = V_195 ;
}
V_183 -> V_200 = F_97 ( V_159 ) ;
V_183 -> V_159 = F_98 ( V_159 ) ;
}
int F_99 ( struct V_9 * V_10 , T_1 V_159 , T_1 V_5 )
{
int V_201 , V_202 = 0 ;
V_3 V_203 , V_204 ;
struct V_182 V_183 ;
if ( V_159 & 7 )
return - V_18 ;
memset ( & V_183 , 0 , sizeof( struct V_182 ) ) ;
if ( ! ( F_100 ( V_159 , V_205 ,
V_206 ) ||
F_100 ( V_159 , V_207 ,
V_208 ) ) )
return - V_18 ;
F_96 ( V_10 , V_159 , & V_183 ) ;
if ( F_100 ( V_159 , V_209 , V_210 ) )
return F_91 ( V_10 , V_183 . V_200 ,
V_183 . V_159 , & V_5 , 1 ) ;
V_204 = V_159 & ~ 0xf ;
F_92 ( & V_10 -> V_20 -> V_177 ) ;
F_20 ( V_10 , V_183 . V_186 , V_204 ) ;
F_20 ( V_10 , V_183 . V_188 , 0 ) ;
F_20 ( V_10 , V_183 . V_184 , V_211 ) ;
F_20 ( V_10 , V_183 . V_184 , V_212 ) ;
for ( V_201 = 0 ; V_201 < V_213 ; V_201 ++ ) {
V_203 = F_17 ( V_10 , V_183 . V_184 ) ;
if ( ( V_203 & V_214 ) == 0 )
break;
}
if ( V_201 >= V_213 ) {
V_202 = - V_18 ;
goto V_13;
}
F_20 ( V_10 , V_183 . V_190 [ 0 ] , F_17 ( V_10 , V_183 . V_192 [ 0 ] ) ) ;
F_20 ( V_10 , V_183 . V_190 [ 1 ] , F_17 ( V_10 , V_183 . V_192 [ 1 ] ) ) ;
F_20 ( V_10 , V_183 . V_190 [ 2 ] , V_5 & 0xffffffff ) ;
F_20 ( V_10 , V_183 . V_190 [ 3 ] , ( V_5 >> 32 ) & 0xffffffff ) ;
F_20 ( V_10 , V_183 . V_184 , V_215 ) ;
F_20 ( V_10 , V_183 . V_184 , V_216 ) ;
for ( V_201 = 0 ; V_201 < V_213 ; V_201 ++ ) {
V_203 = F_17 ( V_10 , V_183 . V_184 ) ;
if ( ( V_203 & V_214 ) == 0 )
break;
}
if ( V_201 >= V_213 ) {
if ( F_80 () )
F_12 ( & V_10 -> V_16 -> V_17 ,
L_19 ) ;
V_202 = - V_18 ;
} else
V_202 = 0 ;
V_13:
F_93 ( & V_10 -> V_20 -> V_177 ) ;
return V_202 ;
}
int F_101 ( struct V_9 * V_10 , T_1 V_159 , T_1 * V_5 )
{
int V_201 , V_202 ;
V_3 V_203 , V_204 ;
T_1 V_2 ;
struct V_182 V_183 ;
if ( V_159 & 7 )
return - V_18 ;
if ( ! ( F_100 ( V_159 , V_205 ,
V_206 ) ||
F_100 ( V_159 , V_207 ,
V_208 ) ) )
return - V_18 ;
memset ( & V_183 , 0 , sizeof( struct V_182 ) ) ;
F_96 ( V_10 , V_159 , & V_183 ) ;
if ( F_100 ( V_159 , V_209 , V_210 ) )
return F_91 ( V_10 , V_183 . V_200 ,
V_183 . V_159 , V_5 , 0 ) ;
F_92 ( & V_10 -> V_20 -> V_177 ) ;
V_204 = V_159 & ~ 0xf ;
F_20 ( V_10 , V_183 . V_186 , V_204 ) ;
F_20 ( V_10 , V_183 . V_188 , 0 ) ;
F_20 ( V_10 , V_183 . V_184 , V_211 ) ;
F_20 ( V_10 , V_183 . V_184 , V_212 ) ;
for ( V_201 = 0 ; V_201 < V_213 ; V_201 ++ ) {
V_203 = F_17 ( V_10 , V_183 . V_184 ) ;
if ( ( V_203 & V_214 ) == 0 )
break;
}
if ( V_201 >= V_213 ) {
if ( F_80 () )
F_12 ( & V_10 -> V_16 -> V_17 ,
L_20 ) ;
V_202 = - V_18 ;
} else {
V_203 = F_17 ( V_10 , V_183 . V_192 [ 3 ] ) ;
V_2 = ( T_1 ) V_203 << 32 ;
V_2 |= F_17 ( V_10 , V_183 . V_192 [ 2 ] ) ;
* V_5 = V_2 ;
V_202 = 0 ;
}
F_93 ( & V_10 -> V_20 -> V_177 ) ;
return V_202 ;
}
int F_102 ( struct V_9 * V_10 )
{
int V_175 , V_217 , V_218 ;
struct V_219 * V_16 = V_10 -> V_16 ;
V_175 = V_220 ;
if ( F_103 ( V_10 , V_175 , & V_218 ) )
return - V_18 ;
if ( V_218 != V_221 ) {
F_12 ( & V_16 -> V_17 , L_21 ,
V_218 ) ;
return - V_18 ;
}
V_175 = V_222 ;
if ( F_103 ( V_10 , V_175 , & V_217 ) )
return - V_18 ;
V_10 -> V_20 -> V_217 = V_217 ;
if ( V_217 == V_223 ) {
V_3 V_224 = F_9 ( V_10 , V_225 ) ;
if ( ( V_224 & 0x8000 ) == 0 )
V_217 = V_226 ;
}
switch ( V_217 ) {
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
V_10 -> V_20 -> V_237 = V_238 ;
break;
case V_239 :
case V_240 :
case V_223 :
V_10 -> V_20 -> V_237 = V_241 ;
break;
case V_226 :
V_10 -> V_20 -> V_237 = ( V_10 -> V_19 < 2 ) ?
V_238 : V_241 ;
break;
default:
F_12 ( & V_16 -> V_17 , L_22 , V_217 ) ;
V_10 -> V_20 -> V_237 = V_238 ;
break;
}
return 0 ;
}
int
F_104 ( struct V_9 * V_10 )
{
V_3 V_242 ;
V_242 = F_9 ( V_10 , V_243 ) ;
if ( V_242 & ( 1UL << V_10 -> V_19 ) ) {
V_242 = F_9 ( V_10 , V_244 ) ;
if ( V_242 & ( 1 << V_10 -> V_19 ) )
return 1 ;
}
return 0 ;
}
int F_105 ( struct V_9 * V_10 , V_3 V_33 , V_3 V_245 )
{
struct V_46 V_47 ;
int V_113 ;
T_1 V_52 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_89 << 23 ) ;
V_52 = V_246 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_33 ( ( ( T_1 ) V_245 << 32 ) | V_10 -> V_19 ) ;
V_47 . V_57 [ 1 ] = F_33 ( V_33 ) ;
V_113 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_113 )
F_12 ( & V_10 -> V_16 -> V_17 , L_23 ) ;
return V_113 ;
}
void F_106 ( struct V_9 * V_10 )
{
void T_2 * V_247 ;
V_3 V_248 ;
V_3 V_249 ;
F_107 ( V_10 -> V_16 , V_250 , & V_248 ) ;
V_247 = V_10 -> V_20 -> V_21 + V_251 ;
V_249 = F_2 ( V_247 ) ;
V_248 = ( V_248 - V_249 ) / V_252 ;
V_10 -> V_20 -> V_253 = V_248 ;
}
void F_108 ( struct V_9 * V_10 , char * V_254 ,
T_8 V_175 , T_9 V_255 )
{
V_3 V_5 ;
T_1 V_256 ;
if ( F_100 ( V_175 , V_181 , V_257 ) ) {
F_94 ( V_10 , V_175 , & V_256 ) ;
memcpy ( V_254 , & V_256 , V_255 ) ;
} else {
V_5 = F_9 ( V_10 , V_175 ) ;
memcpy ( V_254 , & V_5 , V_255 ) ;
}
}
void F_109 ( struct V_9 * V_10 , char * V_254 ,
T_8 V_175 , T_9 V_255 )
{
V_3 V_5 ;
T_1 V_256 ;
if ( F_100 ( V_175 , V_181 , V_257 ) ) {
memcpy ( & V_256 , V_254 , V_255 ) ;
F_95 ( V_10 , V_175 , V_256 ) ;
} else {
memcpy ( & V_5 , V_254 , V_255 ) ;
F_14 ( V_10 , V_175 , V_5 ) ;
}
}
int F_110 ( struct V_9 * V_10 )
{
return F_8 ( V_10 , 5 , 0 ) ;
}
void F_111 ( struct V_9 * V_10 )
{
F_15 ( V_10 , 5 ) ;
}
