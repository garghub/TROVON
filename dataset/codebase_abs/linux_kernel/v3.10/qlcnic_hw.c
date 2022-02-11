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
V_51 -> V_44 = F_34 ( V_44 ) ;
return F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
}
int F_35 ( struct V_9 * V_10 , const T_3 * V_1 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 ;
int V_63 = - V_64 ;
F_36 (head, &adapter->mac_list) {
V_62 = F_37 ( V_60 , struct V_61 , V_65 ) ;
if ( memcmp ( V_1 , V_62 -> V_58 , V_66 ) == 0 ) {
V_63 = F_38 ( V_10 , V_62 -> V_58 ,
0 , V_67 ) ;
if ( V_63 )
return V_63 ;
F_39 ( & V_62 -> V_65 ) ;
F_40 ( V_62 ) ;
return V_63 ;
}
}
return V_63 ;
}
int F_41 ( struct V_9 * V_10 , const T_3 * V_1 , T_4 V_68 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 ;
F_36 (head, &adapter->mac_list) {
V_62 = F_37 ( V_60 , struct V_61 , V_65 ) ;
if ( memcmp ( V_1 , V_62 -> V_58 , V_66 ) == 0 )
return 0 ;
}
V_62 = F_42 ( sizeof( struct V_61 ) , V_69 ) ;
if ( V_62 == NULL )
return - V_70 ;
memcpy ( V_62 -> V_58 , V_1 , V_66 ) ;
if ( F_38 ( V_10 ,
V_62 -> V_58 , V_68 , V_71 ) ) {
F_40 ( V_62 ) ;
return - V_18 ;
}
F_43 ( & V_62 -> V_65 , & V_10 -> V_72 ) ;
return 0 ;
}
void F_44 ( struct V_73 * V_74 , T_4 V_68 )
{
struct V_9 * V_10 = F_45 ( V_74 ) ;
struct V_75 * V_76 ;
static const T_3 V_77 [ V_66 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
V_3 V_78 = V_79 ;
if ( ! F_23 ( V_32 , & V_10 -> V_33 ) )
return;
if ( ! F_46 ( V_10 ) )
F_41 ( V_10 , V_10 -> V_58 , V_68 ) ;
F_41 ( V_10 , V_77 , V_68 ) ;
if ( V_74 -> V_80 & V_81 ) {
if ( ! ( V_10 -> V_80 & V_82 ) )
V_78 = V_83 ;
goto V_84;
}
if ( ( V_74 -> V_80 & V_85 ) ||
( F_47 ( V_74 ) > V_10 -> V_20 -> V_86 ) ) {
V_78 = V_87 ;
goto V_84;
}
if ( ! F_48 ( V_74 ) && ! F_46 ( V_10 ) ) {
F_49 (ha, netdev) {
F_41 ( V_10 , V_76 -> V_1 , V_68 ) ;
}
}
if ( F_46 ( V_10 ) )
F_50 ( V_74 , V_68 ) ;
V_84:
if ( ! F_46 ( V_10 ) ) {
if ( V_78 == V_83 &&
! V_10 -> V_88 ) {
F_51 ( V_10 ) ;
V_10 -> V_89 = true ;
} else {
V_10 -> V_89 = false ;
}
}
F_52 ( V_10 , V_78 ) ;
}
void F_53 ( struct V_73 * V_74 )
{
struct V_9 * V_10 = F_45 ( V_74 ) ;
struct V_75 * V_76 ;
struct V_61 * V_62 ;
if ( ! F_23 ( V_32 , & V_10 -> V_33 ) )
return;
if ( F_46 ( V_10 ) ) {
if ( ! F_48 ( V_74 ) ) {
F_49 (ha, netdev) {
V_62 = F_42 ( sizeof( struct V_61 ) ,
V_69 ) ;
if ( V_62 == NULL )
break;
memcpy ( V_62 -> V_58 ,
V_76 -> V_1 , V_66 ) ;
F_43 ( & V_62 -> V_65 , & V_10 -> V_90 ) ;
}
}
F_54 ( V_10 -> V_74 ) ;
return;
}
F_44 ( V_74 , 0 ) ;
}
int F_55 ( struct V_9 * V_10 , V_3 V_78 )
{
struct V_46 V_47 ;
T_1 V_52 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_91 << 23 ) ;
V_52 = V_92 |
( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_33 ( V_78 ) ;
return F_22 ( V_10 ,
(struct V_22 * ) & V_47 , 1 ) ;
}
void F_56 ( struct V_9 * V_10 )
{
struct V_61 * V_62 ;
struct V_59 * V_60 = & V_10 -> V_72 ;
while ( ! F_57 ( V_60 ) ) {
V_62 = F_37 ( V_60 -> V_93 , struct V_61 , V_65 ) ;
F_38 ( V_10 ,
V_62 -> V_58 , 0 , V_67 ) ;
F_39 ( & V_62 -> V_65 ) ;
F_40 ( V_62 ) ;
}
}
void F_58 ( struct V_9 * V_10 )
{
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_60 ;
int V_25 ;
unsigned long time ;
T_3 V_99 ;
for ( V_25 = 0 ; V_25 < V_10 -> V_100 . V_101 ; V_25 ++ ) {
V_60 = & ( V_10 -> V_100 . V_102 [ V_25 ] ) ;
F_59 (tmp_fil, n, head, fnode) {
V_99 = V_95 -> V_44 ? V_103 :
V_67 ;
time = V_95 -> V_104 ;
if ( V_105 > ( V_106 * V_107 + time ) ) {
F_38 ( V_10 ,
V_95 -> V_108 ,
V_95 -> V_44 ,
V_99 ) ;
F_60 ( & V_10 -> V_109 ) ;
V_10 -> V_100 . V_110 -- ;
F_61 ( & V_95 -> V_111 ) ;
F_62 ( & V_10 -> V_109 ) ;
F_40 ( V_95 ) ;
}
}
}
for ( V_25 = 0 ; V_25 < V_10 -> V_112 . V_101 ; V_25 ++ ) {
V_60 = & ( V_10 -> V_112 . V_102 [ V_25 ] ) ;
F_59 (tmp_fil, n, head, fnode)
{
time = V_95 -> V_104 ;
if ( V_105 > ( V_106 * V_107 + time ) ) {
F_60 ( & V_10 -> V_113 ) ;
V_10 -> V_112 . V_110 -- ;
F_61 ( & V_95 -> V_111 ) ;
F_62 ( & V_10 -> V_113 ) ;
F_40 ( V_95 ) ;
}
}
}
}
void F_63 ( struct V_9 * V_10 )
{
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_60 ;
int V_25 ;
T_3 V_99 ;
for ( V_25 = 0 ; V_25 < V_10 -> V_100 . V_101 ; V_25 ++ ) {
V_60 = & ( V_10 -> V_100 . V_102 [ V_25 ] ) ;
F_59 (tmp_fil, n, head, fnode) {
V_99 = V_95 -> V_44 ? V_103 :
V_67 ;
F_38 ( V_10 ,
V_95 -> V_108 ,
V_95 -> V_44 ,
V_99 ) ;
F_60 ( & V_10 -> V_109 ) ;
V_10 -> V_100 . V_110 -- ;
F_61 ( & V_95 -> V_111 ) ;
F_62 ( & V_10 -> V_109 ) ;
F_40 ( V_95 ) ;
}
}
}
static int F_64 ( struct V_9 * V_10 , T_3 V_114 )
{
struct V_46 V_47 ;
int V_115 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_91 << 23 ) ;
V_47 . V_56 = F_33 ( V_116 |
( ( T_1 ) V_10 -> V_19 << 16 ) | ( ( T_1 ) 0x1 << 32 ) ) ;
V_47 . V_57 [ 0 ] = F_33 ( V_114 ) ;
V_115 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_115 != 0 )
F_12 ( & V_10 -> V_16 -> V_17 , L_2 ,
V_114 ? L_3 : L_4 ) ;
return V_115 ;
}
int F_65 ( struct V_9 * V_10 , T_3 V_78 )
{
if ( F_64 ( V_10 , V_78 ) )
return - V_18 ;
if ( F_52 ( V_10 ,
V_83 ) ) {
F_64 ( V_10 , 0 ) ;
return - V_18 ;
}
F_13 ( 1000 ) ;
return 0 ;
}
int F_66 ( struct V_9 * V_10 , T_3 V_78 )
{
struct V_73 * V_74 = V_10 -> V_74 ;
V_78 = V_79 ;
F_64 ( V_10 , 0 ) ;
if ( V_74 -> V_80 & V_81 )
V_78 = V_83 ;
else if ( V_74 -> V_80 & V_85 )
V_78 = V_87 ;
F_52 ( V_10 , V_78 ) ;
F_13 ( 1000 ) ;
return 0 ;
}
void F_67 ( struct V_9 * V_10 )
{
struct V_46 V_47 ;
int V_115 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_91 << 23 ) ;
V_47 . V_56 = F_33 ( V_117 |
( ( T_1 ) V_10 -> V_19 << 16 ) ) ;
V_47 . V_57 [ 0 ] = F_33 ( ( ( T_1 ) V_10 -> V_20 -> V_118 . V_114 ) << 32 ) ;
V_47 . V_57 [ 2 ] = F_33 ( V_10 -> V_20 -> V_118 . V_119 |
( ( T_1 ) V_10 -> V_20 -> V_118 . V_120 ) << 16 ) ;
V_47 . V_57 [ 5 ] = F_33 ( V_10 -> V_20 -> V_118 . V_121 |
( ( T_1 ) V_10 -> V_20 -> V_118 . type ) << 32 |
( ( T_1 ) V_10 -> V_20 -> V_118 . V_122 ) << 40 ) ;
V_115 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_115 != 0 )
F_12 ( & V_10 -> V_74 -> V_17 ,
L_5 ) ;
}
int F_68 ( struct V_9 * V_10 , int V_123 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_115 ;
if ( ! F_23 ( V_32 , & V_10 -> V_33 ) )
return 0 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_91 << 23 ) ;
V_52 = V_124 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_52 = 0 ;
if ( V_123 ) {
V_52 = V_125 | V_126 ;
if ( V_10 -> V_20 -> V_127 & V_128 )
V_52 |= V_129 |
V_130 ;
}
V_47 . V_57 [ 0 ] = F_33 ( V_52 ) ;
V_115 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_115 != 0 )
F_12 ( & V_10 -> V_74 -> V_17 ,
L_6 ) ;
return V_115 ;
}
int F_69 ( struct V_9 * V_10 , V_3 V_123 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_115 ;
if ( ! ! ( V_10 -> V_80 & V_131 ) == V_123 )
return 0 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_91 << 23 ) ;
V_52 = V_132 |
( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_33 ( V_123 ) ;
V_115 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_115 != 0 )
F_12 ( & V_10 -> V_74 -> V_17 ,
L_7 ) ;
V_10 -> V_80 ^= V_131 ;
return V_115 ;
}
int F_70 ( struct V_9 * V_10 , int V_123 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_25 , V_115 ;
static const T_1 V_133 [] = {
0xbeac01fa6a42b73bULL , 0x8030f20c77cb2da3ULL ,
0xae7b30b4d0ca2bcbULL , 0x43a38fb04167253dULL ,
0x255b0ec26d5a56daULL
} ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_91 << 23 ) ;
V_52 = V_134 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_52 = ( ( T_1 ) ( V_135 & 0x3 ) << 4 ) |
( ( T_1 ) ( V_135 & 0x3 ) << 6 ) |
( ( T_1 ) ( V_123 & 0x1 ) << 8 ) |
( ( T_1 ) V_136 << 48 ) |
( T_1 ) V_137 |
( T_1 ) V_138 ;
V_47 . V_57 [ 0 ] = F_33 ( V_52 ) ;
for ( V_25 = 0 ; V_25 < 5 ; V_25 ++ )
V_47 . V_57 [ V_25 + 1 ] = F_33 ( V_133 [ V_25 ] ) ;
V_115 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_115 != 0 )
F_12 ( & V_10 -> V_74 -> V_17 , L_8 ) ;
return V_115 ;
}
void F_71 ( struct V_9 * V_10 ,
T_5 V_139 , int V_99 )
{
struct V_46 V_47 ;
struct V_140 * V_141 ;
T_1 V_52 ;
int V_115 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_91 << 23 ) ;
V_52 = V_142 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_33 ( V_99 ) ;
V_141 = (struct V_140 * ) & V_47 . V_57 [ 1 ] ;
V_141 -> V_143 = V_139 ;
V_115 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_115 != 0 )
F_12 ( & V_10 -> V_74 -> V_17 ,
L_9 ,
( V_99 == V_144 ) ? L_10 : L_11 , V_139 ) ;
}
int F_72 ( struct V_9 * V_10 , int V_123 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_115 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_91 << 23 ) ;
V_52 = V_145 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_33 ( V_123 | ( V_123 << 8 ) ) ;
V_115 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_115 != 0 )
F_12 ( & V_10 -> V_74 -> V_17 ,
L_12 ) ;
return V_115 ;
}
int F_73 ( struct V_9 * V_10 )
{
struct V_46 V_47 ;
T_1 V_52 ;
int V_115 ;
if ( ! F_23 ( V_32 , & V_10 -> V_33 ) )
return 0 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_91 << 23 ) ;
V_52 = V_146 |
( ( T_1 ) V_10 -> V_19 << 16 ) |
( ( T_1 ) V_147 << 56 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_115 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_115 != 0 )
F_12 ( & V_10 -> V_74 -> V_17 ,
L_13 ) ;
return V_115 ;
}
int F_74 ( struct V_73 * V_74 , int V_148 )
{
struct V_9 * V_10 = F_45 ( V_74 ) ;
int V_149 = 0 ;
if ( V_148 < V_150 || V_148 > V_151 ) {
F_12 ( & V_10 -> V_74 -> V_17 , L_14
L_15 , V_151 , V_150 ) ;
return - V_64 ;
}
V_149 = F_75 ( V_10 , V_148 ) ;
if ( ! V_149 )
V_74 -> V_148 = V_148 ;
return V_149 ;
}
static T_6 F_76 ( struct V_9 * V_10 ,
T_6 V_152 )
{
V_3 V_153 = V_10 -> V_153 ;
if ( V_153 & V_154 ) {
V_152 |= V_155 | V_156 |
V_157 ;
V_10 -> V_158 = 1 ;
if ( F_77 ( V_10 ) ) {
if ( ! ( V_153 & V_159 ) )
V_152 &= ~ V_160 ;
else
V_152 |= V_160 ;
if ( ! ( V_153 & V_161 ) )
V_152 &= ~ V_162 ;
else
V_152 |= V_162 ;
}
} else {
V_152 &= ~ ( V_155 |
V_156 |
V_157 ) ;
if ( F_77 ( V_10 ) )
V_152 &= ~ ( V_160 | V_162 ) ;
V_10 -> V_158 = 0 ;
}
return V_152 ;
}
T_6 F_78 ( struct V_73 * V_74 ,
T_6 V_152 )
{
struct V_9 * V_10 = F_45 ( V_74 ) ;
T_6 V_163 ;
if ( F_18 ( V_10 ) &&
( V_10 -> V_80 & V_164 ) ) {
if ( V_10 -> V_80 & V_165 ) {
V_152 = F_76 ( V_10 , V_152 ) ;
} else {
V_163 = V_152 ^ V_74 -> V_152 ;
V_152 ^= V_163 & ( V_155 |
V_156 |
V_157 |
V_160 |
V_162 ) ;
}
}
if ( ! ( V_152 & V_155 ) )
V_152 &= ~ V_166 ;
return V_152 ;
}
int F_79 ( struct V_73 * V_74 , T_6 V_152 )
{
struct V_9 * V_10 = F_45 ( V_74 ) ;
T_6 V_163 = V_74 -> V_152 ^ V_152 ;
int V_167 = ( V_152 & V_166 ) ? V_168 : 0 ;
if ( ! ( V_163 & V_166 ) )
return 0 ;
V_74 -> V_152 ^= V_166 ;
if ( F_80 ( V_10 , V_167 ) )
return - V_18 ;
if ( ! V_167 && F_18 ( V_10 ) ) {
if ( F_73 ( V_10 ) )
return - V_18 ;
}
return 0 ;
}
static int F_81 ( struct V_169 * V_20 ,
T_7 V_170 , void T_2 * * V_1 )
{
const struct V_171 * V_172 ;
if ( ( V_170 >= V_173 ) || ( V_170 < V_174 ) )
return - V_64 ;
V_170 -= V_174 ;
V_172 = & V_175 [ F_82 ( V_170 ) ] . V_176 [ F_83 ( V_170 ) ] ;
if ( V_172 -> V_177 && ( V_172 -> V_178 <= V_170 ) && ( V_172 -> V_179 > V_170 ) ) {
* V_1 = V_20 -> V_21 + V_172 -> V_180 +
( V_170 - V_172 -> V_178 ) ;
return 0 ;
}
* V_1 = V_20 -> V_21 + V_181 + ( V_170 & F_84 ( 16 ) ) ;
return 1 ;
}
static int
F_85 ( struct V_9 * V_10 , T_7 V_170 )
{
V_3 V_182 ;
void T_2 * V_1 = V_10 -> V_20 -> V_21 + V_183 ;
V_170 -= V_174 ;
V_182 = F_86 ( V_170 ) ;
if ( V_182 == 0 ) {
F_12 ( & V_10 -> V_16 -> V_17 , L_16 , V_170 ) ;
return - V_18 ;
}
F_4 ( V_182 , V_1 ) ;
if ( F_2 ( V_1 ) != V_182 ) {
if ( F_87 () )
F_88 ( & V_10 -> V_16 -> V_17 ,
L_17 ,
V_182 , V_170 ) ;
return - V_18 ;
}
return 0 ;
}
int F_89 ( struct V_9 * V_10 , T_7 V_170 ,
V_3 V_5 )
{
unsigned long V_80 ;
int V_115 ;
void T_2 * V_1 = NULL ;
V_115 = F_81 ( V_10 -> V_20 , V_170 , & V_1 ) ;
if ( V_115 == 0 ) {
F_4 ( V_5 , V_1 ) ;
return 0 ;
}
if ( V_115 > 0 ) {
F_90 ( & V_10 -> V_20 -> V_184 , V_80 ) ;
F_91 ( V_10 ) ;
V_115 = F_85 ( V_10 , V_170 ) ;
if ( ! V_115 )
F_4 ( V_5 , V_1 ) ;
F_92 ( V_10 ) ;
F_93 ( & V_10 -> V_20 -> V_184 , V_80 ) ;
return V_115 ;
}
F_12 ( & V_10 -> V_16 -> V_17 ,
L_18 , V_185 , V_170 ) ;
F_94 () ;
return - V_18 ;
}
int F_95 ( struct V_9 * V_10 , T_7 V_170 )
{
unsigned long V_80 ;
int V_115 ;
V_3 V_5 = - 1 ;
void T_2 * V_1 = NULL ;
V_115 = F_81 ( V_10 -> V_20 , V_170 , & V_1 ) ;
if ( V_115 == 0 )
return F_2 ( V_1 ) ;
if ( V_115 > 0 ) {
F_90 ( & V_10 -> V_20 -> V_184 , V_80 ) ;
F_91 ( V_10 ) ;
if ( ! F_85 ( V_10 , V_170 ) )
V_5 = F_2 ( V_1 ) ;
F_92 ( V_10 ) ;
F_93 ( & V_10 -> V_20 -> V_184 , V_80 ) ;
return V_5 ;
}
F_12 ( & V_10 -> V_16 -> V_17 ,
L_18 , V_185 , V_170 ) ;
F_94 () ;
return - 1 ;
}
void T_2 * F_96 ( struct V_169 * V_20 ,
V_3 V_186 )
{
void T_2 * V_1 = NULL ;
F_97 ( F_81 ( V_20 , V_186 , & V_1 ) ) ;
return V_1 ;
}
static int F_98 ( struct V_9 * V_10 ,
V_3 V_182 , T_1 V_170 , T_1 * V_5 , int V_45 )
{
void T_2 * V_1 ;
V_3 V_187 ;
F_99 ( & V_10 -> V_20 -> V_188 ) ;
F_4 ( V_182 , V_10 -> V_20 -> V_189 ) ;
F_2 ( V_10 -> V_20 -> V_189 ) ;
V_187 = V_190 + V_170 ;
V_1 = V_10 -> V_20 -> V_21 + V_187 ;
if ( V_45 == 0 )
* V_5 = F_1 ( V_1 ) ;
else
F_3 ( * V_5 , V_1 ) ;
F_4 ( 0 , V_10 -> V_20 -> V_189 ) ;
F_2 ( V_10 -> V_20 -> V_189 ) ;
F_100 ( & V_10 -> V_20 -> V_188 ) ;
return 0 ;
}
void
F_101 ( struct V_9 * V_10 , T_1 V_170 , T_1 * V_5 )
{
void T_2 * V_1 = V_10 -> V_20 -> V_21 +
V_191 + ( V_170 - V_192 ) ;
F_99 ( & V_10 -> V_20 -> V_188 ) ;
* V_5 = F_1 ( V_1 ) ;
F_100 ( & V_10 -> V_20 -> V_188 ) ;
}
void
F_102 ( struct V_9 * V_10 , T_1 V_170 , T_1 V_5 )
{
void T_2 * V_1 = V_10 -> V_20 -> V_21 +
V_191 + ( V_170 - V_192 ) ;
F_99 ( & V_10 -> V_20 -> V_188 ) ;
F_3 ( V_5 , V_1 ) ;
F_100 ( & V_10 -> V_20 -> V_188 ) ;
}
static void F_103 ( struct V_9 * V_10 , T_1 V_170 ,
struct V_193 * V_194 )
{
V_194 -> V_195 = V_196 ;
V_194 -> V_197 = V_198 ;
V_194 -> V_199 = V_200 ;
if ( V_170 & 0xf ) {
V_194 -> V_201 [ 0 ] = V_202 ;
V_194 -> V_203 [ 0 ] = V_204 ;
V_194 -> V_201 [ 1 ] = V_205 ;
V_194 -> V_203 [ 1 ] = V_206 ;
V_194 -> V_201 [ 2 ] = V_207 ;
V_194 -> V_201 [ 3 ] = V_208 ;
V_194 -> V_203 [ 2 ] = V_209 ;
V_194 -> V_203 [ 3 ] = V_210 ;
} else {
V_194 -> V_201 [ 0 ] = V_207 ;
V_194 -> V_203 [ 0 ] = V_209 ;
V_194 -> V_201 [ 1 ] = V_208 ;
V_194 -> V_203 [ 1 ] = V_210 ;
V_194 -> V_201 [ 2 ] = V_202 ;
V_194 -> V_201 [ 3 ] = V_205 ;
V_194 -> V_203 [ 2 ] = V_204 ;
V_194 -> V_203 [ 3 ] = V_206 ;
}
V_194 -> V_211 = F_104 ( V_170 ) ;
V_194 -> V_170 = F_105 ( V_170 ) ;
}
int F_106 ( struct V_9 * V_10 , T_1 V_170 , T_1 V_5 )
{
int V_212 , V_213 = 0 ;
V_3 V_214 , V_215 ;
struct V_193 V_194 ;
if ( V_170 & 7 )
return - V_18 ;
memset ( & V_194 , 0 , sizeof( struct V_193 ) ) ;
if ( ! ( F_107 ( V_170 , V_216 ,
V_217 ) ||
F_107 ( V_170 , V_218 ,
V_219 ) ) )
return - V_18 ;
F_103 ( V_10 , V_170 , & V_194 ) ;
if ( F_107 ( V_170 , V_220 , V_221 ) )
return F_98 ( V_10 , V_194 . V_211 ,
V_194 . V_170 , & V_5 , 1 ) ;
V_215 = V_170 & ~ 0xf ;
F_99 ( & V_10 -> V_20 -> V_188 ) ;
F_20 ( V_10 , V_194 . V_197 , V_215 ) ;
F_20 ( V_10 , V_194 . V_199 , 0 ) ;
F_20 ( V_10 , V_194 . V_195 , V_222 ) ;
F_20 ( V_10 , V_194 . V_195 , V_223 ) ;
for ( V_212 = 0 ; V_212 < V_224 ; V_212 ++ ) {
V_214 = F_17 ( V_10 , V_194 . V_195 ) ;
if ( ( V_214 & V_225 ) == 0 )
break;
}
if ( V_212 >= V_224 ) {
V_213 = - V_18 ;
goto V_13;
}
F_20 ( V_10 , V_194 . V_201 [ 0 ] , F_17 ( V_10 , V_194 . V_203 [ 0 ] ) ) ;
F_20 ( V_10 , V_194 . V_201 [ 1 ] , F_17 ( V_10 , V_194 . V_203 [ 1 ] ) ) ;
F_20 ( V_10 , V_194 . V_201 [ 2 ] , V_5 & 0xffffffff ) ;
F_20 ( V_10 , V_194 . V_201 [ 3 ] , ( V_5 >> 32 ) & 0xffffffff ) ;
F_20 ( V_10 , V_194 . V_195 , V_226 ) ;
F_20 ( V_10 , V_194 . V_195 , V_227 ) ;
for ( V_212 = 0 ; V_212 < V_224 ; V_212 ++ ) {
V_214 = F_17 ( V_10 , V_194 . V_195 ) ;
if ( ( V_214 & V_225 ) == 0 )
break;
}
if ( V_212 >= V_224 ) {
if ( F_87 () )
F_12 ( & V_10 -> V_16 -> V_17 ,
L_19 ) ;
V_213 = - V_18 ;
} else
V_213 = 0 ;
V_13:
F_100 ( & V_10 -> V_20 -> V_188 ) ;
return V_213 ;
}
int F_108 ( struct V_9 * V_10 , T_1 V_170 , T_1 * V_5 )
{
int V_212 , V_213 ;
V_3 V_214 , V_215 ;
T_1 V_2 ;
struct V_193 V_194 ;
if ( V_170 & 7 )
return - V_18 ;
if ( ! ( F_107 ( V_170 , V_216 ,
V_217 ) ||
F_107 ( V_170 , V_218 ,
V_219 ) ) )
return - V_18 ;
memset ( & V_194 , 0 , sizeof( struct V_193 ) ) ;
F_103 ( V_10 , V_170 , & V_194 ) ;
if ( F_107 ( V_170 , V_220 , V_221 ) )
return F_98 ( V_10 , V_194 . V_211 ,
V_194 . V_170 , V_5 , 0 ) ;
F_99 ( & V_10 -> V_20 -> V_188 ) ;
V_215 = V_170 & ~ 0xf ;
F_20 ( V_10 , V_194 . V_197 , V_215 ) ;
F_20 ( V_10 , V_194 . V_199 , 0 ) ;
F_20 ( V_10 , V_194 . V_195 , V_222 ) ;
F_20 ( V_10 , V_194 . V_195 , V_223 ) ;
for ( V_212 = 0 ; V_212 < V_224 ; V_212 ++ ) {
V_214 = F_17 ( V_10 , V_194 . V_195 ) ;
if ( ( V_214 & V_225 ) == 0 )
break;
}
if ( V_212 >= V_224 ) {
if ( F_87 () )
F_12 ( & V_10 -> V_16 -> V_17 ,
L_20 ) ;
V_213 = - V_18 ;
} else {
V_214 = F_17 ( V_10 , V_194 . V_203 [ 3 ] ) ;
V_2 = ( T_1 ) V_214 << 32 ;
V_2 |= F_17 ( V_10 , V_194 . V_203 [ 2 ] ) ;
* V_5 = V_2 ;
V_213 = 0 ;
}
F_100 ( & V_10 -> V_20 -> V_188 ) ;
return V_213 ;
}
int F_109 ( struct V_9 * V_10 )
{
int V_186 , V_228 , V_229 ;
struct V_230 * V_16 = V_10 -> V_16 ;
V_186 = V_231 ;
if ( F_110 ( V_10 , V_186 , & V_229 ) )
return - V_18 ;
if ( V_229 != V_232 ) {
F_12 ( & V_16 -> V_17 , L_21 ,
V_229 ) ;
return - V_18 ;
}
V_186 = V_233 ;
if ( F_110 ( V_10 , V_186 , & V_228 ) )
return - V_18 ;
V_10 -> V_20 -> V_228 = V_228 ;
if ( V_228 == V_234 ) {
V_3 V_235 = F_9 ( V_10 , V_236 ) ;
if ( ( V_235 & 0x8000 ) == 0 )
V_228 = V_237 ;
}
switch ( V_228 ) {
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
V_10 -> V_20 -> V_248 = V_249 ;
break;
case V_250 :
case V_251 :
case V_234 :
V_10 -> V_20 -> V_248 = V_252 ;
break;
case V_237 :
V_10 -> V_20 -> V_248 = ( V_10 -> V_19 < 2 ) ?
V_249 : V_252 ;
break;
default:
F_12 ( & V_16 -> V_17 , L_22 , V_228 ) ;
V_10 -> V_20 -> V_248 = V_249 ;
break;
}
return 0 ;
}
int
F_111 ( struct V_9 * V_10 )
{
V_3 V_253 ;
V_253 = F_9 ( V_10 , V_254 ) ;
if ( V_253 & ( 1UL << V_10 -> V_19 ) ) {
V_253 = F_9 ( V_10 , V_255 ) ;
if ( V_253 & ( 1 << V_10 -> V_19 ) )
return 1 ;
}
return 0 ;
}
int F_112 ( struct V_9 * V_10 , V_3 V_33 , V_3 V_256 )
{
struct V_46 V_47 ;
int V_115 ;
T_1 V_52 ;
memset ( & V_47 , 0 , sizeof( struct V_46 ) ) ;
V_47 . V_53 = F_33 ( V_91 << 23 ) ;
V_52 = V_257 | ( ( T_1 ) V_10 -> V_19 << 16 ) ;
V_47 . V_56 = F_33 ( V_52 ) ;
V_47 . V_57 [ 0 ] = F_33 ( ( ( T_1 ) V_256 << 32 ) | V_10 -> V_19 ) ;
V_47 . V_57 [ 1 ] = F_33 ( V_33 ) ;
V_115 = F_22 ( V_10 , (struct V_22 * ) & V_47 , 1 ) ;
if ( V_115 )
F_12 ( & V_10 -> V_16 -> V_17 , L_23 ) ;
return V_115 ;
}
void F_113 ( struct V_9 * V_10 )
{
void T_2 * V_258 ;
V_3 V_259 ;
V_3 V_260 ;
F_114 ( V_10 -> V_16 , V_261 , & V_259 ) ;
V_258 = V_10 -> V_20 -> V_21 + V_262 ;
V_260 = F_2 ( V_258 ) ;
V_259 = ( V_259 - V_260 ) / V_263 ;
V_10 -> V_20 -> V_264 = V_259 ;
}
void F_115 ( struct V_9 * V_10 , char * V_265 ,
T_8 V_186 , T_9 V_266 )
{
V_3 V_5 ;
T_1 V_267 ;
if ( F_107 ( V_186 , V_192 , V_268 ) ) {
F_101 ( V_10 , V_186 , & V_267 ) ;
memcpy ( V_265 , & V_267 , V_266 ) ;
} else {
V_5 = F_9 ( V_10 , V_186 ) ;
memcpy ( V_265 , & V_5 , V_266 ) ;
}
}
void F_116 ( struct V_9 * V_10 , char * V_265 ,
T_8 V_186 , T_9 V_266 )
{
V_3 V_5 ;
T_1 V_267 ;
if ( F_107 ( V_186 , V_192 , V_268 ) ) {
memcpy ( & V_267 , V_265 , V_266 ) ;
F_102 ( V_10 , V_186 , V_267 ) ;
} else {
memcpy ( & V_5 , V_265 , V_266 ) ;
F_14 ( V_10 , V_186 , V_5 ) ;
}
}
int F_117 ( struct V_9 * V_10 )
{
return F_8 ( V_10 , 5 , 0 ) ;
}
void F_118 ( struct V_9 * V_10 )
{
F_15 ( V_10 , 5 ) ;
}
