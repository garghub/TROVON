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
V_32 = & V_10 -> V_32 [ 0 ] ;
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
memcpy ( V_50 -> V_59 , V_1 , V_60 ) ;
V_52 = (struct V_51 * ) & V_48 . V_58 [ 1 ] ;
V_52 -> V_45 = F_33 ( V_45 ) ;
return F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
}
int F_34 ( struct V_9 * V_10 , const T_3 * V_1 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
int V_14 = - V_65 ;
F_35 (head, &adapter->mac_list) {
V_64 = F_36 ( V_62 , struct V_63 , V_66 ) ;
if ( memcmp ( V_1 , V_64 -> V_59 , V_60 ) == 0 ) {
V_14 = F_37 ( V_10 , V_64 -> V_59 ,
0 , V_67 ) ;
if ( V_14 )
return V_14 ;
F_38 ( & V_64 -> V_66 ) ;
F_39 ( V_64 ) ;
return V_14 ;
}
}
return V_14 ;
}
int F_40 ( struct V_9 * V_10 , const T_3 * V_1 , T_4 V_68 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
F_35 (head, &adapter->mac_list) {
V_64 = F_36 ( V_62 , struct V_63 , V_66 ) ;
if ( memcmp ( V_1 , V_64 -> V_59 , V_60 ) == 0 )
return 0 ;
}
V_64 = F_41 ( sizeof( struct V_63 ) , V_69 ) ;
if ( V_64 == NULL )
return - V_70 ;
memcpy ( V_64 -> V_59 , V_1 , V_60 ) ;
if ( F_37 ( V_10 ,
V_64 -> V_59 , V_68 , V_71 ) ) {
F_39 ( V_64 ) ;
return - V_19 ;
}
F_42 ( & V_64 -> V_66 , & V_10 -> V_72 ) ;
return 0 ;
}
void F_43 ( struct V_73 * V_74 , T_4 V_68 )
{
struct V_9 * V_10 = F_44 ( V_74 ) ;
struct V_75 * V_21 = V_10 -> V_21 ;
struct V_76 * V_77 ;
static const T_3 V_78 [ V_60 ] = {
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
struct V_63 * V_64 ;
if ( ! F_22 ( V_33 , & V_10 -> V_34 ) )
return;
if ( F_45 ( V_10 ) ) {
if ( ! F_47 ( V_74 ) ) {
F_48 (ha, netdev) {
V_64 = F_41 ( sizeof( struct V_63 ) ,
V_69 ) ;
if ( V_64 == NULL )
break;
memcpy ( V_64 -> V_59 ,
V_77 -> V_1 , V_60 ) ;
F_42 ( & V_64 -> V_66 , & V_10 -> V_91 ) ;
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
struct V_63 * V_64 ;
struct V_61 * V_62 = & V_10 -> V_72 ;
while ( ! F_59 ( V_62 ) ) {
V_64 = F_36 ( V_62 -> V_94 , struct V_63 , V_66 ) ;
F_37 ( V_10 ,
V_64 -> V_59 , 0 , V_67 ) ;
F_38 ( & V_64 -> V_66 ) ;
F_39 ( V_64 ) ;
}
}
void F_60 ( struct V_9 * V_10 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_99 * V_62 ;
int V_26 ;
unsigned long time ;
T_3 V_100 ;
for ( V_26 = 0 ; V_26 < V_10 -> V_101 . V_102 ; V_26 ++ ) {
V_62 = & ( V_10 -> V_101 . V_103 [ V_26 ] ) ;
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
V_62 = & ( V_10 -> V_113 . V_103 [ V_26 ] ) ;
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
struct V_99 * V_62 ;
int V_26 ;
T_3 V_100 ;
for ( V_26 = 0 ; V_26 < V_10 -> V_101 . V_102 ; V_26 ++ ) {
V_62 = & ( V_10 -> V_101 . V_103 [ V_26 ] ) ;
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
int F_69 ( struct V_9 * V_10 )
{
T_3 V_118 [ V_60 ] ;
int V_119 ;
V_119 = F_70 ( V_10 , V_118 ,
V_10 -> V_21 -> V_120 ) ;
if ( V_119 )
return V_119 ;
memcpy ( V_10 -> V_21 -> V_121 , V_118 , V_60 ) ;
V_10 -> V_81 |= V_122 ;
return 0 ;
}
void F_71 ( struct V_9 * V_10 )
{
struct V_47 V_48 ;
int V_116 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_48 . V_57 = F_32 ( V_123 |
( ( T_1 ) V_10 -> V_20 << 16 ) ) ;
V_48 . V_58 [ 0 ] = F_32 ( ( ( T_1 ) V_10 -> V_21 -> V_124 . V_115 ) << 32 ) ;
V_48 . V_58 [ 2 ] = F_32 ( V_10 -> V_21 -> V_124 . V_125 |
( ( T_1 ) V_10 -> V_21 -> V_124 . V_126 ) << 16 ) ;
V_48 . V_58 [ 5 ] = F_32 ( V_10 -> V_21 -> V_124 . V_127 |
( ( T_1 ) V_10 -> V_21 -> V_124 . type ) << 32 |
( ( T_1 ) V_10 -> V_21 -> V_124 . V_128 ) << 40 ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_5 ) ;
}
int F_72 ( struct V_9 * V_10 , int V_129 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_116 ;
if ( ! F_22 ( V_33 , & V_10 -> V_34 ) )
return 0 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_130 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_53 = 0 ;
if ( V_129 ) {
V_53 = V_131 ;
if ( V_10 -> V_21 -> V_132 [ 0 ] &
V_133 )
V_53 |= V_134 ;
}
V_48 . V_58 [ 0 ] = F_32 ( V_53 ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_6 ) ;
return V_116 ;
}
int F_73 ( struct V_9 * V_10 , V_3 V_129 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_116 ;
if ( ! ! ( V_10 -> V_81 & V_135 ) == V_129 )
return 0 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_136 |
( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( V_129 ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_7 ) ;
V_10 -> V_81 ^= V_135 ;
return V_116 ;
}
int F_74 ( struct V_9 * V_10 , int V_129 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_26 , V_116 ;
static const T_1 V_137 [] = {
0xbeac01fa6a42b73bULL , 0x8030f20c77cb2da3ULL ,
0xae7b30b4d0ca2bcbULL , 0x43a38fb04167253dULL ,
0x255b0ec26d5a56daULL
} ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_138 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_53 = ( ( T_1 ) ( V_139 & 0x3 ) << 4 ) |
( ( T_1 ) ( V_139 & 0x3 ) << 6 ) |
( ( T_1 ) ( V_129 & 0x1 ) << 8 ) |
( ( T_1 ) V_140 << 48 ) |
( T_1 ) V_141 |
( T_1 ) V_142 ;
V_48 . V_58 [ 0 ] = F_32 ( V_53 ) ;
for ( V_26 = 0 ; V_26 < 5 ; V_26 ++ )
V_48 . V_58 [ V_26 + 1 ] = F_32 ( V_137 [ V_26 ] ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 , L_8 ) ;
return V_116 ;
}
void F_75 ( struct V_9 * V_10 ,
T_5 V_143 , int V_100 )
{
struct V_47 V_48 ;
struct V_144 * V_145 ;
T_1 V_53 ;
int V_116 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_146 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( V_100 ) ;
V_145 = (struct V_144 * ) & V_48 . V_58 [ 1 ] ;
V_145 -> V_147 = V_143 ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_9 ,
( V_100 == V_148 ) ? L_10 : L_11 , V_143 ) ;
}
int F_76 ( struct V_9 * V_10 , int V_129 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_116 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_149 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( V_129 | ( V_129 << 8 ) ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_12 ) ;
return V_116 ;
}
int F_77 ( struct V_9 * V_10 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_116 ;
if ( ! F_22 ( V_33 , & V_10 -> V_34 ) )
return 0 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_150 |
( ( T_1 ) V_10 -> V_20 << 16 ) |
( ( T_1 ) V_151 << 56 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_13 ) ;
return V_116 ;
}
int F_78 ( struct V_73 * V_74 , int V_152 )
{
struct V_9 * V_10 = F_44 ( V_74 ) ;
int V_153 = 0 ;
if ( V_152 < V_154 || V_152 > V_155 ) {
F_12 ( & V_10 -> V_74 -> V_18 , L_14
L_15 , V_155 , V_154 ) ;
return - V_65 ;
}
V_153 = F_79 ( V_10 , V_152 ) ;
if ( ! V_153 )
V_74 -> V_152 = V_152 ;
return V_153 ;
}
static T_6 F_80 ( struct V_9 * V_10 ,
T_6 V_156 )
{
V_3 V_157 = V_10 -> V_157 ;
if ( V_157 & V_158 ) {
V_156 |= V_159 | V_160 |
V_161 ;
V_10 -> V_162 = 1 ;
if ( F_81 ( V_10 ) ) {
if ( ! ( V_157 & V_163 ) )
V_156 &= ~ V_164 ;
else
V_156 |= V_164 ;
if ( ! ( V_157 & V_165 ) )
V_156 &= ~ V_166 ;
else
V_156 |= V_166 ;
}
} else {
V_156 &= ~ ( V_159 |
V_160 |
V_161 ) ;
if ( F_81 ( V_10 ) )
V_156 &= ~ ( V_164 | V_166 ) ;
V_10 -> V_162 = 0 ;
}
return V_156 ;
}
T_6 F_82 ( struct V_73 * V_74 ,
T_6 V_156 )
{
struct V_9 * V_10 = F_44 ( V_74 ) ;
T_6 V_167 ;
if ( F_18 ( V_10 ) &&
( V_10 -> V_81 & V_168 ) ) {
if ( V_10 -> V_81 & V_169 ) {
V_156 = F_80 ( V_10 , V_156 ) ;
} else {
V_167 = V_156 ^ V_74 -> V_156 ;
V_156 ^= V_167 & ( V_159 |
V_160 |
V_161 |
V_164 |
V_166 ) ;
}
}
if ( ! ( V_156 & V_159 ) )
V_156 &= ~ V_170 ;
return V_156 ;
}
int F_83 ( struct V_73 * V_74 , T_6 V_156 )
{
struct V_9 * V_10 = F_44 ( V_74 ) ;
T_6 V_167 = V_74 -> V_156 ^ V_156 ;
int V_171 = ( V_156 & V_170 ) ? V_172 : 0 ;
if ( ! ( V_167 & V_170 ) )
return 0 ;
V_74 -> V_156 ^= V_170 ;
if ( F_84 ( V_10 , V_171 ) )
return - V_19 ;
if ( ! V_171 && F_18 ( V_10 ) ) {
if ( F_77 ( V_10 ) )
return - V_19 ;
}
return 0 ;
}
static int F_85 ( struct V_75 * V_21 ,
T_7 V_173 , void T_2 * * V_1 )
{
const struct V_174 * V_175 ;
if ( ( V_173 >= V_176 ) || ( V_173 < V_177 ) )
return - V_65 ;
V_173 -= V_177 ;
V_175 = & V_178 [ F_86 ( V_173 ) ] . V_179 [ F_87 ( V_173 ) ] ;
if ( V_175 -> V_180 && ( V_175 -> V_181 <= V_173 ) && ( V_175 -> V_182 > V_173 ) ) {
* V_1 = V_21 -> V_22 + V_175 -> V_183 +
( V_173 - V_175 -> V_181 ) ;
return 0 ;
}
* V_1 = V_21 -> V_22 + V_184 + ( V_173 & F_88 ( 16 ) ) ;
return 1 ;
}
static int
F_89 ( struct V_9 * V_10 , T_7 V_173 )
{
V_3 V_185 ;
void T_2 * V_1 = V_10 -> V_21 -> V_22 + V_186 ;
V_173 -= V_177 ;
V_185 = F_90 ( V_173 ) ;
if ( V_185 == 0 ) {
F_12 ( & V_10 -> V_17 -> V_18 , L_16 , V_173 ) ;
return - V_19 ;
}
F_4 ( V_185 , V_1 ) ;
if ( F_2 ( V_1 ) != V_185 ) {
if ( F_91 () )
F_92 ( & V_10 -> V_17 -> V_18 ,
L_17 ,
V_185 , V_173 ) ;
return - V_19 ;
}
return 0 ;
}
int F_93 ( struct V_9 * V_10 , T_7 V_173 ,
V_3 V_5 )
{
unsigned long V_81 ;
int V_116 ;
void T_2 * V_1 = NULL ;
V_116 = F_85 ( V_10 -> V_21 , V_173 , & V_1 ) ;
if ( V_116 == 0 ) {
F_4 ( V_5 , V_1 ) ;
return 0 ;
}
if ( V_116 > 0 ) {
F_94 ( & V_10 -> V_21 -> V_187 , V_81 ) ;
F_95 ( V_10 ) ;
V_116 = F_89 ( V_10 , V_173 ) ;
if ( ! V_116 )
F_4 ( V_5 , V_1 ) ;
F_96 ( V_10 ) ;
F_97 ( & V_10 -> V_21 -> V_187 , V_81 ) ;
return V_116 ;
}
F_12 ( & V_10 -> V_17 -> V_18 ,
L_18 , V_188 , V_173 ) ;
F_98 () ;
return - V_19 ;
}
int F_99 ( struct V_9 * V_10 , T_7 V_173 ,
int * V_14 )
{
unsigned long V_81 ;
int V_116 ;
V_3 V_5 = - 1 ;
void T_2 * V_1 = NULL ;
V_116 = F_85 ( V_10 -> V_21 , V_173 , & V_1 ) ;
if ( V_116 == 0 )
return F_2 ( V_1 ) ;
if ( V_116 > 0 ) {
F_94 ( & V_10 -> V_21 -> V_187 , V_81 ) ;
F_95 ( V_10 ) ;
if ( ! F_89 ( V_10 , V_173 ) )
V_5 = F_2 ( V_1 ) ;
F_96 ( V_10 ) ;
F_97 ( & V_10 -> V_21 -> V_187 , V_81 ) ;
return V_5 ;
}
F_12 ( & V_10 -> V_17 -> V_18 ,
L_18 , V_188 , V_173 ) ;
F_98 () ;
return - 1 ;
}
void T_2 * F_100 ( struct V_75 * V_21 ,
V_3 V_189 )
{
void T_2 * V_1 = NULL ;
F_101 ( F_85 ( V_21 , V_189 , & V_1 ) ) ;
return V_1 ;
}
static int F_102 ( struct V_9 * V_10 ,
V_3 V_185 , T_1 V_173 , T_1 * V_5 , int V_46 )
{
void T_2 * V_1 ;
V_3 V_190 ;
F_103 ( & V_10 -> V_21 -> V_191 ) ;
F_4 ( V_185 , V_10 -> V_21 -> V_192 ) ;
F_2 ( V_10 -> V_21 -> V_192 ) ;
V_190 = V_193 + V_173 ;
V_1 = V_10 -> V_21 -> V_22 + V_190 ;
if ( V_46 == 0 )
* V_5 = F_1 ( V_1 ) ;
else
F_3 ( * V_5 , V_1 ) ;
F_4 ( 0 , V_10 -> V_21 -> V_192 ) ;
F_2 ( V_10 -> V_21 -> V_192 ) ;
F_104 ( & V_10 -> V_21 -> V_191 ) ;
return 0 ;
}
void
F_105 ( struct V_9 * V_10 , T_1 V_173 , T_1 * V_5 )
{
void T_2 * V_1 = V_10 -> V_21 -> V_22 +
V_194 + ( V_173 - V_195 ) ;
F_103 ( & V_10 -> V_21 -> V_191 ) ;
* V_5 = F_1 ( V_1 ) ;
F_104 ( & V_10 -> V_21 -> V_191 ) ;
}
void
F_106 ( struct V_9 * V_10 , T_1 V_173 , T_1 V_5 )
{
void T_2 * V_1 = V_10 -> V_21 -> V_22 +
V_194 + ( V_173 - V_195 ) ;
F_103 ( & V_10 -> V_21 -> V_191 ) ;
F_3 ( V_5 , V_1 ) ;
F_104 ( & V_10 -> V_21 -> V_191 ) ;
}
static void F_107 ( struct V_9 * V_10 , T_1 V_173 ,
struct V_196 * V_197 )
{
V_197 -> V_198 = V_199 ;
V_197 -> V_200 = V_201 ;
V_197 -> V_202 = V_203 ;
if ( V_173 & 0xf ) {
V_197 -> V_204 [ 0 ] = V_205 ;
V_197 -> V_206 [ 0 ] = V_207 ;
V_197 -> V_204 [ 1 ] = V_208 ;
V_197 -> V_206 [ 1 ] = V_209 ;
V_197 -> V_204 [ 2 ] = V_210 ;
V_197 -> V_204 [ 3 ] = V_211 ;
V_197 -> V_206 [ 2 ] = V_212 ;
V_197 -> V_206 [ 3 ] = V_213 ;
} else {
V_197 -> V_204 [ 0 ] = V_210 ;
V_197 -> V_206 [ 0 ] = V_212 ;
V_197 -> V_204 [ 1 ] = V_211 ;
V_197 -> V_206 [ 1 ] = V_213 ;
V_197 -> V_204 [ 2 ] = V_205 ;
V_197 -> V_204 [ 3 ] = V_208 ;
V_197 -> V_206 [ 2 ] = V_207 ;
V_197 -> V_206 [ 3 ] = V_209 ;
}
V_197 -> V_214 = F_108 ( V_173 ) ;
V_197 -> V_173 = F_109 ( V_173 ) ;
}
int F_110 ( struct V_9 * V_10 , T_1 V_173 , T_1 V_5 )
{
int V_215 , V_119 = 0 ;
V_3 V_216 , V_217 ;
struct V_196 V_197 ;
if ( V_173 & 7 )
return - V_19 ;
memset ( & V_197 , 0 , sizeof( struct V_196 ) ) ;
if ( ! ( F_111 ( V_173 , V_218 ,
V_219 ) ||
F_111 ( V_173 , V_220 ,
V_221 ) ) )
return - V_19 ;
F_107 ( V_10 , V_173 , & V_197 ) ;
if ( F_111 ( V_173 , V_222 , V_223 ) )
return F_102 ( V_10 , V_197 . V_214 ,
V_197 . V_173 , & V_5 , 1 ) ;
V_217 = V_173 & ~ 0xf ;
F_103 ( & V_10 -> V_21 -> V_191 ) ;
F_19 ( V_10 , V_197 . V_200 , V_217 ) ;
F_19 ( V_10 , V_197 . V_202 , 0 ) ;
F_19 ( V_10 , V_197 . V_198 , V_224 ) ;
F_19 ( V_10 , V_197 . V_198 , V_225 ) ;
for ( V_215 = 0 ; V_215 < V_226 ; V_215 ++ ) {
V_216 = F_17 ( V_10 , V_197 . V_198 ) ;
if ( ( V_216 & V_227 ) == 0 )
break;
}
if ( V_215 >= V_226 ) {
V_119 = - V_19 ;
goto V_15;
}
F_19 ( V_10 , V_197 . V_204 [ 0 ] , F_17 ( V_10 , V_197 . V_206 [ 0 ] ) ) ;
F_19 ( V_10 , V_197 . V_204 [ 1 ] , F_17 ( V_10 , V_197 . V_206 [ 1 ] ) ) ;
F_19 ( V_10 , V_197 . V_204 [ 2 ] , V_5 & 0xffffffff ) ;
F_19 ( V_10 , V_197 . V_204 [ 3 ] , ( V_5 >> 32 ) & 0xffffffff ) ;
F_19 ( V_10 , V_197 . V_198 , V_228 ) ;
F_19 ( V_10 , V_197 . V_198 , V_229 ) ;
for ( V_215 = 0 ; V_215 < V_226 ; V_215 ++ ) {
V_216 = F_17 ( V_10 , V_197 . V_198 ) ;
if ( ( V_216 & V_227 ) == 0 )
break;
}
if ( V_215 >= V_226 ) {
if ( F_91 () )
F_12 ( & V_10 -> V_17 -> V_18 ,
L_19 ) ;
V_119 = - V_19 ;
} else
V_119 = 0 ;
V_15:
F_104 ( & V_10 -> V_21 -> V_191 ) ;
return V_119 ;
}
int F_112 ( struct V_9 * V_10 , T_1 V_173 , T_1 * V_5 )
{
int V_215 , V_119 ;
V_3 V_216 , V_217 ;
T_1 V_2 ;
struct V_196 V_197 ;
if ( V_173 & 7 )
return - V_19 ;
if ( ! ( F_111 ( V_173 , V_218 ,
V_219 ) ||
F_111 ( V_173 , V_220 ,
V_221 ) ) )
return - V_19 ;
memset ( & V_197 , 0 , sizeof( struct V_196 ) ) ;
F_107 ( V_10 , V_173 , & V_197 ) ;
if ( F_111 ( V_173 , V_222 , V_223 ) )
return F_102 ( V_10 , V_197 . V_214 ,
V_197 . V_173 , V_5 , 0 ) ;
F_103 ( & V_10 -> V_21 -> V_191 ) ;
V_217 = V_173 & ~ 0xf ;
F_19 ( V_10 , V_197 . V_200 , V_217 ) ;
F_19 ( V_10 , V_197 . V_202 , 0 ) ;
F_19 ( V_10 , V_197 . V_198 , V_224 ) ;
F_19 ( V_10 , V_197 . V_198 , V_225 ) ;
for ( V_215 = 0 ; V_215 < V_226 ; V_215 ++ ) {
V_216 = F_17 ( V_10 , V_197 . V_198 ) ;
if ( ( V_216 & V_227 ) == 0 )
break;
}
if ( V_215 >= V_226 ) {
if ( F_91 () )
F_12 ( & V_10 -> V_17 -> V_18 ,
L_20 ) ;
V_119 = - V_19 ;
} else {
V_216 = F_17 ( V_10 , V_197 . V_206 [ 3 ] ) ;
V_2 = ( T_1 ) V_216 << 32 ;
V_2 |= F_17 ( V_10 , V_197 . V_206 [ 2 ] ) ;
* V_5 = V_2 ;
V_119 = 0 ;
}
F_104 ( & V_10 -> V_21 -> V_191 ) ;
return V_119 ;
}
int F_113 ( struct V_9 * V_10 )
{
int V_189 , V_230 , V_231 , V_14 = 0 ;
struct V_232 * V_17 = V_10 -> V_17 ;
V_189 = V_233 ;
if ( F_114 ( V_10 , V_189 , & V_231 ) )
return - V_19 ;
if ( V_231 != V_234 ) {
F_12 ( & V_17 -> V_18 , L_21 ,
V_231 ) ;
return - V_19 ;
}
V_189 = V_235 ;
if ( F_114 ( V_10 , V_189 , & V_230 ) )
return - V_19 ;
V_10 -> V_21 -> V_230 = V_230 ;
if ( V_230 == V_236 ) {
V_3 V_237 = F_9 ( V_10 , V_238 , & V_14 ) ;
if ( V_14 == - V_19 )
return V_14 ;
if ( ( V_237 & 0x8000 ) == 0 )
V_230 = V_239 ;
}
switch ( V_230 ) {
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
case V_248 :
case V_249 :
V_10 -> V_21 -> V_250 = V_251 ;
break;
case V_252 :
case V_253 :
case V_236 :
V_10 -> V_21 -> V_250 = V_254 ;
break;
case V_239 :
V_10 -> V_21 -> V_250 = ( V_10 -> V_20 < 2 ) ?
V_251 : V_254 ;
break;
default:
F_12 ( & V_17 -> V_18 , L_22 , V_230 ) ;
V_10 -> V_21 -> V_250 = V_251 ;
break;
}
return 0 ;
}
int
F_115 ( struct V_9 * V_10 )
{
V_3 V_255 ;
int V_14 = 0 ;
V_255 = F_9 ( V_10 , V_256 , & V_14 ) ;
if ( V_255 & ( 1UL << V_10 -> V_20 ) ) {
V_255 = F_9 ( V_10 , V_257 , & V_14 ) ;
if ( V_14 == - V_19 )
return V_14 ;
if ( V_255 & ( 1 << V_10 -> V_20 ) )
return 1 ;
}
return 0 ;
}
int F_116 ( struct V_9 * V_10 , V_3 V_34 , V_3 V_258 )
{
struct V_47 V_48 ;
int V_116 ;
T_1 V_53 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_92 << 23 ) ;
V_53 = V_259 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( ( ( T_1 ) V_258 << 32 ) | V_10 -> V_20 ) ;
V_48 . V_58 [ 1 ] = F_32 ( V_34 ) ;
V_116 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_116 )
F_12 ( & V_10 -> V_17 -> V_18 , L_23 ) ;
return V_116 ;
}
int F_117 ( struct V_9 * V_10 , T_3 * V_260 )
{
struct V_261 V_100 ;
int V_14 ;
V_14 = F_118 ( & V_100 , V_10 , V_262 ) ;
if ( ! V_14 ) {
V_14 = F_119 ( V_10 , & V_100 ) ;
if ( ! V_14 )
* V_260 = V_100 . V_263 . V_264 [ 1 ] ;
}
F_120 ( & V_100 ) ;
return V_14 ;
}
void F_121 ( struct V_9 * V_10 )
{
void T_2 * V_265 ;
V_3 V_266 ;
V_3 V_267 ;
F_122 ( V_10 -> V_17 , V_268 , & V_266 ) ;
V_265 = V_10 -> V_21 -> V_22 + V_269 ;
V_267 = F_2 ( V_265 ) ;
V_266 = ( V_266 - V_267 ) / V_270 ;
V_10 -> V_21 -> V_271 = V_266 ;
}
void F_123 ( struct V_9 * V_10 , char * V_272 ,
T_8 V_189 , T_9 V_273 )
{
int V_14 = 0 ;
V_3 V_5 ;
T_1 V_274 ;
if ( F_111 ( V_189 , V_195 , V_275 ) ) {
F_105 ( V_10 , V_189 , & V_274 ) ;
memcpy ( V_272 , & V_274 , V_273 ) ;
} else {
V_5 = F_9 ( V_10 , V_189 , & V_14 ) ;
memcpy ( V_272 , & V_5 , V_273 ) ;
}
}
void F_124 ( struct V_9 * V_10 , char * V_272 ,
T_8 V_189 , T_9 V_273 )
{
V_3 V_5 ;
T_1 V_274 ;
if ( F_111 ( V_189 , V_195 , V_275 ) ) {
memcpy ( & V_274 , V_272 , V_273 ) ;
F_106 ( V_10 , V_189 , V_274 ) ;
} else {
memcpy ( & V_5 , V_272 , V_273 ) ;
F_14 ( V_10 , V_189 , V_5 ) ;
}
}
int F_125 ( struct V_9 * V_10 )
{
return F_8 ( V_10 , 5 , 0 ) ;
}
void F_126 ( struct V_9 * V_10 )
{
F_15 ( V_10 , 5 ) ;
}
int F_127 ( struct V_232 * V_17 )
{
struct V_9 * V_10 = F_128 ( V_17 ) ;
struct V_73 * V_74 = V_10 -> V_74 ;
int V_276 ;
F_129 ( V_74 ) ;
F_130 ( V_10 ) ;
if ( F_131 ( V_74 ) )
F_132 ( V_10 , V_74 ) ;
F_133 ( V_10 , 0 ) ;
F_134 ( V_277 , & V_10 -> V_34 ) ;
V_276 = F_135 ( V_17 ) ;
if ( V_276 )
return V_276 ;
if ( F_115 ( V_10 ) ) {
F_136 ( V_17 , V_278 , 1 ) ;
F_136 ( V_17 , V_279 , 1 ) ;
}
return 0 ;
}
int F_137 ( struct V_9 * V_10 )
{
struct V_73 * V_74 = V_10 -> V_74 ;
int V_14 ;
V_14 = F_138 ( V_10 ) ;
if ( V_14 ) {
F_12 ( & V_10 -> V_17 -> V_18 , L_24 ) ;
return V_14 ;
}
if ( F_131 ( V_74 ) ) {
V_14 = F_139 ( V_10 , V_74 ) ;
if ( ! V_14 )
F_140 ( V_74 , V_280 ) ;
}
F_141 ( V_74 ) ;
F_142 ( V_10 , V_281 , V_282 ) ;
return V_14 ;
}
