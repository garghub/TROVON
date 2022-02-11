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
int V_13 = 0 ;
int V_14 = 0 ;
V_3 V_15 = 0 ;
while ( ! V_15 ) {
V_15 = F_9 ( V_10 , F_10 ( F_11 ( V_11 ) ) ,
& V_14 ) ;
if ( V_15 == 1 )
break;
if ( ++ V_13 >= V_16 ) {
F_12 ( & V_10 -> V_17 -> V_18 ,
L_1 ,
V_11 ,
V_12 ? F_9 ( V_10 , V_12 , & V_14 ) : - 1 ) ;
return - V_19 ;
}
F_13 ( 1 ) ;
}
if ( V_12 )
F_14 ( V_10 , V_12 , V_10 -> V_20 ) ;
return 0 ;
}
void
F_15 ( struct V_9 * V_10 , int V_11 )
{
int V_14 = 0 ;
F_9 ( V_10 , F_10 ( F_16 ( V_11 ) ) , & V_14 ) ;
}
int F_17 ( struct V_9 * V_10 , V_3 V_1 )
{
int V_14 = 0 ;
V_3 V_5 ;
if ( F_18 ( V_10 ) )
F_5 ( V_1 , V_10 -> V_21 -> V_22 , & V_5 ) ;
else {
V_5 = F_9 ( V_10 , V_1 , & V_14 ) ;
if ( V_14 == - V_19 )
return V_14 ;
}
return V_5 ;
}
void F_19 ( struct V_9 * V_10 , V_3 V_1 , V_3 V_5 )
{
if ( F_18 ( V_10 ) )
F_7 ( V_1 , V_10 -> V_21 -> V_22 , V_5 ) ;
else
F_20 ( V_10 , V_1 , V_5 ) ;
}
static int
F_21 ( struct V_9 * V_10 ,
struct V_23 * V_24 , int V_25 )
{
V_3 V_26 , V_27 ;
struct V_28 * V_29 ;
struct V_23 * V_30 ;
struct V_31 * V_32 ;
V_26 = 0 ;
if ( ! F_22 ( V_33 , & V_10 -> V_34 ) )
return - V_19 ;
V_32 = V_10 -> V_32 ;
F_23 ( V_32 -> V_35 ) ;
V_27 = V_32 -> V_27 ;
if ( V_25 >= F_24 ( V_32 ) ) {
F_25 ( V_32 -> V_35 ) ;
F_26 () ;
if ( F_24 ( V_32 ) > V_25 ) {
if ( F_24 ( V_32 ) > V_36 )
F_27 ( V_32 -> V_35 ) ;
} else {
V_10 -> V_37 . V_38 ++ ;
F_28 ( V_32 -> V_35 ) ;
return - V_39 ;
}
}
do {
V_30 = & V_24 [ V_26 ] ;
V_29 = & V_32 -> V_40 [ V_27 ] ;
V_29 -> V_41 = NULL ;
V_29 -> V_42 = 0 ;
memcpy ( & V_32 -> V_43 [ V_27 ] ,
V_30 , sizeof( struct V_23 ) ) ;
V_27 = F_29 ( V_27 , V_32 -> V_44 ) ;
V_26 ++ ;
} while ( V_26 != V_25 );
V_32 -> V_27 = V_27 ;
F_30 ( V_32 ) ;
F_28 ( V_32 -> V_35 ) ;
return 0 ;
}
int F_31 ( struct V_9 * V_10 , T_3 * V_1 ,
T_4 V_45 , T_3 V_46 )
{
struct V_47 V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
T_1 V_53 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_55 << 23 ) ;
V_53 = V_56 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_50 = (struct V_49 * ) & V_48 . V_58 [ 0 ] ;
V_50 -> V_46 = V_46 ;
memcpy ( V_50 -> V_59 , V_1 , 6 ) ;
V_52 = (struct V_51 * ) & V_48 . V_58 [ 1 ] ;
V_52 -> V_45 = F_33 ( V_45 ) ;
return F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
}
int F_34 ( struct V_9 * V_10 , const T_3 * V_1 )
{
struct V_60 * V_61 ;
struct V_62 * V_63 ;
int V_14 = - V_64 ;
F_35 (head, &adapter->mac_list) {
V_63 = F_36 ( V_61 , struct V_62 , V_65 ) ;
if ( memcmp ( V_1 , V_63 -> V_59 , V_66 ) == 0 ) {
V_14 = F_37 ( V_10 , V_63 -> V_59 ,
0 , V_67 ) ;
if ( V_14 )
return V_14 ;
F_38 ( & V_63 -> V_65 ) ;
F_39 ( V_63 ) ;
return V_14 ;
}
}
return V_14 ;
}
int F_40 ( struct V_9 * V_10 , const T_3 * V_1 , T_4 V_68 )
{
struct V_60 * V_61 ;
struct V_62 * V_63 ;
F_35 (head, &adapter->mac_list) {
V_63 = F_36 ( V_61 , struct V_62 , V_65 ) ;
if ( memcmp ( V_1 , V_63 -> V_59 , V_66 ) == 0 )
return 0 ;
}
V_63 = F_41 ( sizeof( struct V_62 ) , V_69 ) ;
if ( V_63 == NULL )
return - V_70 ;
memcpy ( V_63 -> V_59 , V_1 , V_66 ) ;
if ( F_37 ( V_10 ,
V_63 -> V_59 , V_68 , V_71 ) ) {
F_39 ( V_63 ) ;
return - V_19 ;
}
F_42 ( & V_63 -> V_65 , & V_10 -> V_72 ) ;
return 0 ;
}
void F_43 ( struct V_73 * V_74 , T_4 V_68 )
{
struct V_9 * V_10 = F_44 ( V_74 ) ;
struct V_75 * V_21 = V_10 -> V_21 ;
struct V_76 * V_77 ;
static const T_3 V_78 [ V_66 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
V_3 V_79 = V_80 ;
if ( ! F_22 ( V_33 , & V_10 -> V_34 ) )
return;
if ( ! F_45 ( V_10 ) )
F_40 ( V_10 , V_10 -> V_59 , V_68 ) ;
F_40 ( V_10 , V_78 , V_68 ) ;
if ( V_74 -> V_81 & V_82 ) {
if ( ! ( V_10 -> V_81 & V_83 ) )
V_79 = V_84 ;
} else if ( ( V_74 -> V_81 & V_85 ) ||
( F_46 ( V_74 ) > V_21 -> V_86 ) ) {
V_79 = V_87 ;
} else if ( ! F_47 ( V_74 ) &&
! F_45 ( V_10 ) ) {
F_48 (ha, netdev)
F_40 ( V_10 , V_77 -> V_1 , V_68 ) ;
}
if ( F_45 ( V_10 ) )
F_49 ( V_74 , V_68 ) ;
if ( F_50 ( V_74 ) > V_21 -> V_88 ) {
V_79 = V_84 ;
} else if ( ! F_51 ( V_74 ) ) {
F_52 (ha, netdev)
F_40 ( V_10 , V_77 -> V_1 , V_68 ) ;
}
if ( ! F_45 ( V_10 ) ) {
if ( V_79 == V_84 &&
! V_10 -> V_89 ) {
F_53 ( V_10 ) ;
V_10 -> V_90 = true ;
} else {
V_10 -> V_90 = false ;
}
}
F_54 ( V_10 , V_79 ) ;
}
void F_55 ( struct V_73 * V_74 )
{
struct V_9 * V_10 = F_44 ( V_74 ) ;
struct V_76 * V_77 ;
struct V_62 * V_63 ;
if ( ! F_22 ( V_33 , & V_10 -> V_34 ) )
return;
if ( F_45 ( V_10 ) ) {
if ( ! F_47 ( V_74 ) ) {
F_48 (ha, netdev) {
V_63 = F_41 ( sizeof( struct V_62 ) ,
V_69 ) ;
if ( V_63 == NULL )
break;
memcpy ( V_63 -> V_59 ,
V_77 -> V_1 , V_66 ) ;
F_42 ( & V_63 -> V_65 , & V_10 -> V_91 ) ;
}
}
F_56 ( V_10 -> V_74 ) ;
return;
}
F_43 ( V_74 , 0 ) ;
}
int F_57 ( struct V_9 * V_10 , V_3 V_79 )
{
struct V_47 V_48 ;
T_1 V_53 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_93 |
( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( V_79 ) ;
return F_21 ( V_10 ,
(struct V_23 * ) & V_48 , 1 ) ;
}
void F_58 ( struct V_9 * V_10 )
{
struct V_62 * V_63 ;
struct V_60 * V_61 = & V_10 -> V_72 ;
while ( ! F_59 ( V_61 ) ) {
V_63 = F_36 ( V_61 -> V_94 , struct V_62 , V_65 ) ;
F_37 ( V_10 ,
V_63 -> V_59 , 0 , V_67 ) ;
F_38 ( & V_63 -> V_65 ) ;
F_39 ( V_63 ) ;
}
}
void F_60 ( struct V_9 * V_10 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_99 * V_61 ;
int V_26 ;
unsigned long time ;
T_3 V_100 ;
for ( V_26 = 0 ; V_26 < V_10 -> V_101 . V_102 ; V_26 ++ ) {
V_61 = & ( V_10 -> V_101 . V_103 [ V_26 ] ) ;
F_61 (tmp_fil, n, head, fnode) {
V_100 = V_96 -> V_45 ? V_104 :
V_67 ;
time = V_96 -> V_105 ;
if ( V_106 > ( V_107 * V_108 + time ) ) {
F_37 ( V_10 ,
V_96 -> V_109 ,
V_96 -> V_45 ,
V_100 ) ;
F_62 ( & V_10 -> V_110 ) ;
V_10 -> V_101 . V_111 -- ;
F_63 ( & V_96 -> V_112 ) ;
F_64 ( & V_10 -> V_110 ) ;
F_39 ( V_96 ) ;
}
}
}
for ( V_26 = 0 ; V_26 < V_10 -> V_113 . V_102 ; V_26 ++ ) {
V_61 = & ( V_10 -> V_113 . V_103 [ V_26 ] ) ;
F_61 (tmp_fil, n, head, fnode)
{
time = V_96 -> V_105 ;
if ( V_106 > ( V_107 * V_108 + time ) ) {
F_62 ( & V_10 -> V_114 ) ;
V_10 -> V_113 . V_111 -- ;
F_63 ( & V_96 -> V_112 ) ;
F_64 ( & V_10 -> V_114 ) ;
F_39 ( V_96 ) ;
}
}
}
}
void F_65 ( struct V_9 * V_10 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_99 * V_61 ;
int V_26 ;
T_3 V_100 ;
for ( V_26 = 0 ; V_26 < V_10 -> V_101 . V_102 ; V_26 ++ ) {
V_61 = & ( V_10 -> V_101 . V_103 [ V_26 ] ) ;
F_61 (tmp_fil, n, head, fnode) {
V_100 = V_96 -> V_45 ? V_104 :
V_67 ;
F_37 ( V_10 ,
V_96 -> V_109 ,
V_96 -> V_45 ,
V_100 ) ;
F_62 ( & V_10 -> V_110 ) ;
V_10 -> V_101 . V_111 -- ;
F_63 ( & V_96 -> V_112 ) ;
F_64 ( & V_10 -> V_110 ) ;
F_39 ( V_96 ) ;
}
}
}
static int F_66 ( struct V_9 * V_10 , T_3 V_115 )
{
struct V_47 V_48 ;
int V_116 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_48 . V_57 = F_32 ( V_117 |
( ( T_1 ) V_10 -> V_20 << 16 ) | ( ( T_1 ) 0x1 << 32 ) ) ;
V_48 . V_58 [ 0 ] = F_32 ( V_115 ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_17 -> V_18 , L_2 ,
V_115 ? L_3 : L_4 ) ;
return V_116 ;
}
int F_67 ( struct V_9 * V_10 , T_3 V_79 )
{
if ( F_66 ( V_10 , V_79 ) )
return - V_19 ;
if ( F_54 ( V_10 ,
V_84 ) ) {
F_66 ( V_10 , 0 ) ;
return - V_19 ;
}
F_13 ( 1000 ) ;
return 0 ;
}
int F_68 ( struct V_9 * V_10 , T_3 V_79 )
{
struct V_73 * V_74 = V_10 -> V_74 ;
V_79 = V_80 ;
F_66 ( V_10 , 0 ) ;
if ( V_74 -> V_81 & V_82 )
V_79 = V_84 ;
else if ( V_74 -> V_81 & V_85 )
V_79 = V_87 ;
F_54 ( V_10 , V_79 ) ;
F_13 ( 1000 ) ;
return 0 ;
}
void F_69 ( struct V_9 * V_10 )
{
struct V_47 V_48 ;
int V_116 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_48 . V_57 = F_32 ( V_118 |
( ( T_1 ) V_10 -> V_20 << 16 ) ) ;
V_48 . V_58 [ 0 ] = F_32 ( ( ( T_1 ) V_10 -> V_21 -> V_119 . V_115 ) << 32 ) ;
V_48 . V_58 [ 2 ] = F_32 ( V_10 -> V_21 -> V_119 . V_120 |
( ( T_1 ) V_10 -> V_21 -> V_119 . V_121 ) << 16 ) ;
V_48 . V_58 [ 5 ] = F_32 ( V_10 -> V_21 -> V_119 . V_122 |
( ( T_1 ) V_10 -> V_21 -> V_119 . type ) << 32 |
( ( T_1 ) V_10 -> V_21 -> V_119 . V_123 ) << 40 ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_5 ) ;
}
int F_70 ( struct V_9 * V_10 , int V_124 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_116 ;
if ( ! F_22 ( V_33 , & V_10 -> V_34 ) )
return 0 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_125 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_53 = 0 ;
if ( V_124 ) {
V_53 = V_126 | V_127 ;
if ( V_10 -> V_21 -> V_128 [ 0 ] &
V_129 )
V_53 |= V_130 |
V_131 ;
}
V_48 . V_58 [ 0 ] = F_32 ( V_53 ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_6 ) ;
return V_116 ;
}
int F_71 ( struct V_9 * V_10 , V_3 V_124 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_116 ;
if ( ! ! ( V_10 -> V_81 & V_132 ) == V_124 )
return 0 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_133 |
( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( V_124 ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_7 ) ;
V_10 -> V_81 ^= V_132 ;
return V_116 ;
}
int F_72 ( struct V_9 * V_10 , int V_124 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_26 , V_116 ;
static const T_1 V_134 [] = {
0xbeac01fa6a42b73bULL , 0x8030f20c77cb2da3ULL ,
0xae7b30b4d0ca2bcbULL , 0x43a38fb04167253dULL ,
0x255b0ec26d5a56daULL
} ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_135 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_53 = ( ( T_1 ) ( V_136 & 0x3 ) << 4 ) |
( ( T_1 ) ( V_136 & 0x3 ) << 6 ) |
( ( T_1 ) ( V_124 & 0x1 ) << 8 ) |
( ( T_1 ) V_137 << 48 ) |
( T_1 ) V_138 |
( T_1 ) V_139 ;
V_48 . V_58 [ 0 ] = F_32 ( V_53 ) ;
for ( V_26 = 0 ; V_26 < 5 ; V_26 ++ )
V_48 . V_58 [ V_26 + 1 ] = F_32 ( V_134 [ V_26 ] ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 , L_8 ) ;
return V_116 ;
}
void F_73 ( struct V_9 * V_10 ,
T_5 V_140 , int V_100 )
{
struct V_47 V_48 ;
struct V_141 * V_142 ;
T_1 V_53 ;
int V_116 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_143 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( V_100 ) ;
V_142 = (struct V_141 * ) & V_48 . V_58 [ 1 ] ;
V_142 -> V_144 = V_140 ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_9 ,
( V_100 == V_145 ) ? L_10 : L_11 , V_140 ) ;
}
int F_74 ( struct V_9 * V_10 , int V_124 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_116 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_146 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( V_124 | ( V_124 << 8 ) ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_12 ) ;
return V_116 ;
}
int F_75 ( struct V_9 * V_10 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_116 ;
if ( ! F_22 ( V_33 , & V_10 -> V_34 ) )
return 0 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_147 |
( ( T_1 ) V_10 -> V_20 << 16 ) |
( ( T_1 ) V_148 << 56 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_13 ) ;
return V_116 ;
}
int F_76 ( struct V_73 * V_74 , int V_149 )
{
struct V_9 * V_10 = F_44 ( V_74 ) ;
int V_150 = 0 ;
if ( V_149 < V_151 || V_149 > V_152 ) {
F_12 ( & V_10 -> V_74 -> V_18 , L_14
L_15 , V_152 , V_151 ) ;
return - V_64 ;
}
V_150 = F_77 ( V_10 , V_149 ) ;
if ( ! V_150 )
V_74 -> V_149 = V_149 ;
return V_150 ;
}
static T_6 F_78 ( struct V_9 * V_10 ,
T_6 V_153 )
{
V_3 V_154 = V_10 -> V_154 ;
if ( V_154 & V_155 ) {
V_153 |= V_156 | V_157 |
V_158 ;
V_10 -> V_159 = 1 ;
if ( F_79 ( V_10 ) ) {
if ( ! ( V_154 & V_160 ) )
V_153 &= ~ V_161 ;
else
V_153 |= V_161 ;
if ( ! ( V_154 & V_162 ) )
V_153 &= ~ V_163 ;
else
V_153 |= V_163 ;
}
} else {
V_153 &= ~ ( V_156 |
V_157 |
V_158 ) ;
if ( F_79 ( V_10 ) )
V_153 &= ~ ( V_161 | V_163 ) ;
V_10 -> V_159 = 0 ;
}
return V_153 ;
}
T_6 F_80 ( struct V_73 * V_74 ,
T_6 V_153 )
{
struct V_9 * V_10 = F_44 ( V_74 ) ;
T_6 V_164 ;
if ( F_18 ( V_10 ) &&
( V_10 -> V_81 & V_165 ) ) {
if ( V_10 -> V_81 & V_166 ) {
V_153 = F_78 ( V_10 , V_153 ) ;
} else {
V_164 = V_153 ^ V_74 -> V_153 ;
V_153 ^= V_164 & ( V_156 |
V_157 |
V_158 |
V_161 |
V_163 ) ;
}
}
if ( ! ( V_153 & V_156 ) )
V_153 &= ~ V_167 ;
return V_153 ;
}
int F_81 ( struct V_73 * V_74 , T_6 V_153 )
{
struct V_9 * V_10 = F_44 ( V_74 ) ;
T_6 V_164 = V_74 -> V_153 ^ V_153 ;
int V_168 = ( V_153 & V_167 ) ? V_169 : 0 ;
if ( ! ( V_164 & V_167 ) )
return 0 ;
V_74 -> V_153 ^= V_167 ;
if ( F_82 ( V_10 , V_168 ) )
return - V_19 ;
if ( ! V_168 && F_18 ( V_10 ) ) {
if ( F_75 ( V_10 ) )
return - V_19 ;
}
return 0 ;
}
static int F_83 ( struct V_75 * V_21 ,
T_7 V_170 , void T_2 * * V_1 )
{
const struct V_171 * V_172 ;
if ( ( V_170 >= V_173 ) || ( V_170 < V_174 ) )
return - V_64 ;
V_170 -= V_174 ;
V_172 = & V_175 [ F_84 ( V_170 ) ] . V_176 [ F_85 ( V_170 ) ] ;
if ( V_172 -> V_177 && ( V_172 -> V_178 <= V_170 ) && ( V_172 -> V_179 > V_170 ) ) {
* V_1 = V_21 -> V_22 + V_172 -> V_180 +
( V_170 - V_172 -> V_178 ) ;
return 0 ;
}
* V_1 = V_21 -> V_22 + V_181 + ( V_170 & F_86 ( 16 ) ) ;
return 1 ;
}
static int
F_87 ( struct V_9 * V_10 , T_7 V_170 )
{
V_3 V_182 ;
void T_2 * V_1 = V_10 -> V_21 -> V_22 + V_183 ;
V_170 -= V_174 ;
V_182 = F_88 ( V_170 ) ;
if ( V_182 == 0 ) {
F_12 ( & V_10 -> V_17 -> V_18 , L_16 , V_170 ) ;
return - V_19 ;
}
F_4 ( V_182 , V_1 ) ;
if ( F_2 ( V_1 ) != V_182 ) {
if ( F_89 () )
F_90 ( & V_10 -> V_17 -> V_18 ,
L_17 ,
V_182 , V_170 ) ;
return - V_19 ;
}
return 0 ;
}
int F_91 ( struct V_9 * V_10 , T_7 V_170 ,
V_3 V_5 )
{
unsigned long V_81 ;
int V_116 ;
void T_2 * V_1 = NULL ;
V_116 = F_83 ( V_10 -> V_21 , V_170 , & V_1 ) ;
if ( V_116 == 0 ) {
F_4 ( V_5 , V_1 ) ;
return 0 ;
}
if ( V_116 > 0 ) {
F_92 ( & V_10 -> V_21 -> V_184 , V_81 ) ;
F_93 ( V_10 ) ;
V_116 = F_87 ( V_10 , V_170 ) ;
if ( ! V_116 )
F_4 ( V_5 , V_1 ) ;
F_94 ( V_10 ) ;
F_95 ( & V_10 -> V_21 -> V_184 , V_81 ) ;
return V_116 ;
}
F_12 ( & V_10 -> V_17 -> V_18 ,
L_18 , V_185 , V_170 ) ;
F_96 () ;
return - V_19 ;
}
int F_97 ( struct V_9 * V_10 , T_7 V_170 ,
int * V_14 )
{
unsigned long V_81 ;
int V_116 ;
V_3 V_5 = - 1 ;
void T_2 * V_1 = NULL ;
V_116 = F_83 ( V_10 -> V_21 , V_170 , & V_1 ) ;
if ( V_116 == 0 )
return F_2 ( V_1 ) ;
if ( V_116 > 0 ) {
F_92 ( & V_10 -> V_21 -> V_184 , V_81 ) ;
F_93 ( V_10 ) ;
if ( ! F_87 ( V_10 , V_170 ) )
V_5 = F_2 ( V_1 ) ;
F_94 ( V_10 ) ;
F_95 ( & V_10 -> V_21 -> V_184 , V_81 ) ;
return V_5 ;
}
F_12 ( & V_10 -> V_17 -> V_18 ,
L_18 , V_185 , V_170 ) ;
F_96 () ;
return - 1 ;
}
void T_2 * F_98 ( struct V_75 * V_21 ,
V_3 V_186 )
{
void T_2 * V_1 = NULL ;
F_99 ( F_83 ( V_21 , V_186 , & V_1 ) ) ;
return V_1 ;
}
static int F_100 ( struct V_9 * V_10 ,
V_3 V_182 , T_1 V_170 , T_1 * V_5 , int V_46 )
{
void T_2 * V_1 ;
V_3 V_187 ;
F_101 ( & V_10 -> V_21 -> V_188 ) ;
F_4 ( V_182 , V_10 -> V_21 -> V_189 ) ;
F_2 ( V_10 -> V_21 -> V_189 ) ;
V_187 = V_190 + V_170 ;
V_1 = V_10 -> V_21 -> V_22 + V_187 ;
if ( V_46 == 0 )
* V_5 = F_1 ( V_1 ) ;
else
F_3 ( * V_5 , V_1 ) ;
F_4 ( 0 , V_10 -> V_21 -> V_189 ) ;
F_2 ( V_10 -> V_21 -> V_189 ) ;
F_102 ( & V_10 -> V_21 -> V_188 ) ;
return 0 ;
}
void
F_103 ( struct V_9 * V_10 , T_1 V_170 , T_1 * V_5 )
{
void T_2 * V_1 = V_10 -> V_21 -> V_22 +
V_191 + ( V_170 - V_192 ) ;
F_101 ( & V_10 -> V_21 -> V_188 ) ;
* V_5 = F_1 ( V_1 ) ;
F_102 ( & V_10 -> V_21 -> V_188 ) ;
}
void
F_104 ( struct V_9 * V_10 , T_1 V_170 , T_1 V_5 )
{
void T_2 * V_1 = V_10 -> V_21 -> V_22 +
V_191 + ( V_170 - V_192 ) ;
F_101 ( & V_10 -> V_21 -> V_188 ) ;
F_3 ( V_5 , V_1 ) ;
F_102 ( & V_10 -> V_21 -> V_188 ) ;
}
static void F_105 ( struct V_9 * V_10 , T_1 V_170 ,
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
V_194 -> V_211 = F_106 ( V_170 ) ;
V_194 -> V_170 = F_107 ( V_170 ) ;
}
int F_108 ( struct V_9 * V_10 , T_1 V_170 , T_1 V_5 )
{
int V_212 , V_213 = 0 ;
V_3 V_214 , V_215 ;
struct V_193 V_194 ;
if ( V_170 & 7 )
return - V_19 ;
memset ( & V_194 , 0 , sizeof( struct V_193 ) ) ;
if ( ! ( F_109 ( V_170 , V_216 ,
V_217 ) ||
F_109 ( V_170 , V_218 ,
V_219 ) ) )
return - V_19 ;
F_105 ( V_10 , V_170 , & V_194 ) ;
if ( F_109 ( V_170 , V_220 , V_221 ) )
return F_100 ( V_10 , V_194 . V_211 ,
V_194 . V_170 , & V_5 , 1 ) ;
V_215 = V_170 & ~ 0xf ;
F_101 ( & V_10 -> V_21 -> V_188 ) ;
F_19 ( V_10 , V_194 . V_197 , V_215 ) ;
F_19 ( V_10 , V_194 . V_199 , 0 ) ;
F_19 ( V_10 , V_194 . V_195 , V_222 ) ;
F_19 ( V_10 , V_194 . V_195 , V_223 ) ;
for ( V_212 = 0 ; V_212 < V_224 ; V_212 ++ ) {
V_214 = F_17 ( V_10 , V_194 . V_195 ) ;
if ( ( V_214 & V_225 ) == 0 )
break;
}
if ( V_212 >= V_224 ) {
V_213 = - V_19 ;
goto V_15;
}
F_19 ( V_10 , V_194 . V_201 [ 0 ] , F_17 ( V_10 , V_194 . V_203 [ 0 ] ) ) ;
F_19 ( V_10 , V_194 . V_201 [ 1 ] , F_17 ( V_10 , V_194 . V_203 [ 1 ] ) ) ;
F_19 ( V_10 , V_194 . V_201 [ 2 ] , V_5 & 0xffffffff ) ;
F_19 ( V_10 , V_194 . V_201 [ 3 ] , ( V_5 >> 32 ) & 0xffffffff ) ;
F_19 ( V_10 , V_194 . V_195 , V_226 ) ;
F_19 ( V_10 , V_194 . V_195 , V_227 ) ;
for ( V_212 = 0 ; V_212 < V_224 ; V_212 ++ ) {
V_214 = F_17 ( V_10 , V_194 . V_195 ) ;
if ( ( V_214 & V_225 ) == 0 )
break;
}
if ( V_212 >= V_224 ) {
if ( F_89 () )
F_12 ( & V_10 -> V_17 -> V_18 ,
L_19 ) ;
V_213 = - V_19 ;
} else
V_213 = 0 ;
V_15:
F_102 ( & V_10 -> V_21 -> V_188 ) ;
return V_213 ;
}
int F_110 ( struct V_9 * V_10 , T_1 V_170 , T_1 * V_5 )
{
int V_212 , V_213 ;
V_3 V_214 , V_215 ;
T_1 V_2 ;
struct V_193 V_194 ;
if ( V_170 & 7 )
return - V_19 ;
if ( ! ( F_109 ( V_170 , V_216 ,
V_217 ) ||
F_109 ( V_170 , V_218 ,
V_219 ) ) )
return - V_19 ;
memset ( & V_194 , 0 , sizeof( struct V_193 ) ) ;
F_105 ( V_10 , V_170 , & V_194 ) ;
if ( F_109 ( V_170 , V_220 , V_221 ) )
return F_100 ( V_10 , V_194 . V_211 ,
V_194 . V_170 , V_5 , 0 ) ;
F_101 ( & V_10 -> V_21 -> V_188 ) ;
V_215 = V_170 & ~ 0xf ;
F_19 ( V_10 , V_194 . V_197 , V_215 ) ;
F_19 ( V_10 , V_194 . V_199 , 0 ) ;
F_19 ( V_10 , V_194 . V_195 , V_222 ) ;
F_19 ( V_10 , V_194 . V_195 , V_223 ) ;
for ( V_212 = 0 ; V_212 < V_224 ; V_212 ++ ) {
V_214 = F_17 ( V_10 , V_194 . V_195 ) ;
if ( ( V_214 & V_225 ) == 0 )
break;
}
if ( V_212 >= V_224 ) {
if ( F_89 () )
F_12 ( & V_10 -> V_17 -> V_18 ,
L_20 ) ;
V_213 = - V_19 ;
} else {
V_214 = F_17 ( V_10 , V_194 . V_203 [ 3 ] ) ;
V_2 = ( T_1 ) V_214 << 32 ;
V_2 |= F_17 ( V_10 , V_194 . V_203 [ 2 ] ) ;
* V_5 = V_2 ;
V_213 = 0 ;
}
F_102 ( & V_10 -> V_21 -> V_188 ) ;
return V_213 ;
}
int F_111 ( struct V_9 * V_10 )
{
int V_186 , V_228 , V_229 , V_14 = 0 ;
struct V_230 * V_17 = V_10 -> V_17 ;
V_186 = V_231 ;
if ( F_112 ( V_10 , V_186 , & V_229 ) )
return - V_19 ;
if ( V_229 != V_232 ) {
F_12 ( & V_17 -> V_18 , L_21 ,
V_229 ) ;
return - V_19 ;
}
V_186 = V_233 ;
if ( F_112 ( V_10 , V_186 , & V_228 ) )
return - V_19 ;
V_10 -> V_21 -> V_228 = V_228 ;
if ( V_228 == V_234 ) {
V_3 V_235 = F_9 ( V_10 , V_236 , & V_14 ) ;
if ( V_14 == - V_19 )
return V_14 ;
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
V_10 -> V_21 -> V_248 = V_249 ;
break;
case V_250 :
case V_251 :
case V_234 :
V_10 -> V_21 -> V_248 = V_252 ;
break;
case V_237 :
V_10 -> V_21 -> V_248 = ( V_10 -> V_20 < 2 ) ?
V_249 : V_252 ;
break;
default:
F_12 ( & V_17 -> V_18 , L_22 , V_228 ) ;
V_10 -> V_21 -> V_248 = V_249 ;
break;
}
return 0 ;
}
int
F_113 ( struct V_9 * V_10 )
{
V_3 V_253 ;
int V_14 = 0 ;
V_253 = F_9 ( V_10 , V_254 , & V_14 ) ;
if ( V_253 & ( 1UL << V_10 -> V_20 ) ) {
V_253 = F_9 ( V_10 , V_255 , & V_14 ) ;
if ( V_14 == - V_19 )
return V_14 ;
if ( V_253 & ( 1 << V_10 -> V_20 ) )
return 1 ;
}
return 0 ;
}
int F_114 ( struct V_9 * V_10 , V_3 V_34 , V_3 V_256 )
{
struct V_47 V_48 ;
int V_116 ;
T_1 V_53 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_257 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( ( ( T_1 ) V_256 << 32 ) | V_10 -> V_20 ) ;
V_48 . V_58 [ 1 ] = F_32 ( V_34 ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 )
F_12 ( & V_10 -> V_17 -> V_18 , L_23 ) ;
return V_116 ;
}
int F_115 ( struct V_9 * V_10 , T_3 * V_258 )
{
struct V_259 V_100 ;
int V_14 ;
V_14 = F_116 ( & V_100 , V_10 , V_260 ) ;
if ( ! V_14 ) {
V_14 = F_117 ( V_10 , & V_100 ) ;
if ( ! V_14 )
* V_258 = V_100 . V_261 . V_262 [ 1 ] ;
}
F_118 ( & V_100 ) ;
return V_14 ;
}
void F_119 ( struct V_9 * V_10 )
{
void T_2 * V_263 ;
V_3 V_264 ;
V_3 V_265 ;
F_120 ( V_10 -> V_17 , V_266 , & V_264 ) ;
V_263 = V_10 -> V_21 -> V_22 + V_267 ;
V_265 = F_2 ( V_263 ) ;
V_264 = ( V_264 - V_265 ) / V_268 ;
V_10 -> V_21 -> V_269 = V_264 ;
}
void F_121 ( struct V_9 * V_10 , char * V_270 ,
T_8 V_186 , T_9 V_271 )
{
int V_14 = 0 ;
V_3 V_5 ;
T_1 V_272 ;
if ( F_109 ( V_186 , V_192 , V_273 ) ) {
F_103 ( V_10 , V_186 , & V_272 ) ;
memcpy ( V_270 , & V_272 , V_271 ) ;
} else {
V_5 = F_9 ( V_10 , V_186 , & V_14 ) ;
memcpy ( V_270 , & V_5 , V_271 ) ;
}
}
void F_122 ( struct V_9 * V_10 , char * V_270 ,
T_8 V_186 , T_9 V_271 )
{
V_3 V_5 ;
T_1 V_272 ;
if ( F_109 ( V_186 , V_192 , V_273 ) ) {
memcpy ( & V_272 , V_270 , V_271 ) ;
F_104 ( V_10 , V_186 , V_272 ) ;
} else {
memcpy ( & V_5 , V_270 , V_271 ) ;
F_14 ( V_10 , V_186 , V_5 ) ;
}
}
int F_123 ( struct V_9 * V_10 )
{
return F_8 ( V_10 , 5 , 0 ) ;
}
void F_124 ( struct V_9 * V_10 )
{
F_15 ( V_10 , 5 ) ;
}
int F_125 ( struct V_230 * V_17 )
{
struct V_9 * V_10 = F_126 ( V_17 ) ;
struct V_73 * V_74 = V_10 -> V_74 ;
int V_274 ;
F_127 ( V_74 ) ;
F_128 ( V_10 ) ;
if ( F_129 ( V_74 ) )
F_130 ( V_10 , V_74 ) ;
F_131 ( V_10 , 0 ) ;
F_132 ( V_275 , & V_10 -> V_34 ) ;
V_274 = F_133 ( V_17 ) ;
if ( V_274 )
return V_274 ;
if ( F_113 ( V_10 ) ) {
F_134 ( V_17 , V_276 , 1 ) ;
F_134 ( V_17 , V_277 , 1 ) ;
}
return 0 ;
}
int F_135 ( struct V_9 * V_10 )
{
struct V_73 * V_74 = V_10 -> V_74 ;
int V_14 ;
V_14 = F_136 ( V_10 ) ;
if ( V_14 ) {
F_12 ( & V_10 -> V_17 -> V_18 , L_24 ) ;
return V_14 ;
}
if ( F_129 ( V_74 ) ) {
V_14 = F_137 ( V_10 , V_74 ) ;
if ( ! V_14 )
F_138 ( V_74 , V_278 ) ;
}
F_139 ( V_74 ) ;
F_140 ( V_10 , V_279 , V_280 ) ;
return V_14 ;
}
