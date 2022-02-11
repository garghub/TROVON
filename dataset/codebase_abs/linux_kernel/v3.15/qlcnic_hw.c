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
int V_13 = 0 , V_14 = 0 , V_15 = 0 ;
while ( ! V_15 ) {
V_15 = F_9 ( V_10 , F_10 ( F_11 ( V_11 ) ) ,
& V_14 ) ;
if ( V_15 == 1 )
break;
if ( ++ V_13 >= V_16 ) {
if ( V_12 ) {
V_15 = F_9 ( V_10 , V_12 , & V_14 ) ;
if ( V_15 != - 1 )
F_12 ( & V_10 -> V_17 -> V_18 ,
L_1 ,
V_11 , V_15 ) ;
else
F_12 ( & V_10 -> V_17 -> V_18 ,
L_2 ,
V_11 ) ;
} else {
F_12 ( & V_10 -> V_17 -> V_18 ,
L_2 , V_11 ) ;
}
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
V_62 = F_36 ( V_64 , struct V_61 , V_66 ) ;
if ( F_37 ( V_1 , V_62 -> V_59 ) ) {
V_14 = F_38 ( V_10 , V_62 -> V_59 ,
0 , V_67 ) ;
if ( V_14 )
return V_14 ;
F_39 ( & V_62 -> V_66 ) ;
F_40 ( V_62 ) ;
return V_14 ;
}
}
return V_14 ;
}
int F_41 ( struct V_9 * V_10 , const T_3 * V_1 , T_4 V_68 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
F_35 (head, &adapter->mac_list) {
V_62 = F_36 ( V_64 , struct V_61 , V_66 ) ;
if ( F_37 ( V_1 , V_62 -> V_59 ) &&
V_62 -> V_45 == V_68 )
return 0 ;
}
V_62 = F_42 ( sizeof( * V_62 ) , V_69 ) ;
if ( V_62 == NULL )
return - V_70 ;
memcpy ( V_62 -> V_59 , V_1 , V_60 ) ;
if ( F_38 ( V_10 ,
V_62 -> V_59 , V_68 , V_71 ) ) {
F_40 ( V_62 ) ;
return - V_19 ;
}
V_62 -> V_45 = V_68 ;
F_43 ( & V_62 -> V_66 , & V_10 -> V_72 ) ;
return 0 ;
}
static void F_44 ( struct V_73 * V_74 , T_4 V_68 )
{
struct V_9 * V_10 = F_45 ( V_74 ) ;
struct V_75 * V_21 = V_10 -> V_21 ;
struct V_76 * V_77 ;
static const T_3 V_78 [ V_60 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
V_3 V_79 = V_80 ;
if ( ! F_22 ( V_33 , & V_10 -> V_34 ) )
return;
F_41 ( V_10 , V_10 -> V_59 , V_68 ) ;
F_41 ( V_10 , V_78 , V_68 ) ;
if ( V_74 -> V_81 & V_82 ) {
if ( ! ( V_10 -> V_81 & V_83 ) )
V_79 = V_84 ;
} else if ( ( V_74 -> V_81 & V_85 ) ||
( F_46 ( V_74 ) > V_21 -> V_86 ) ) {
V_79 = V_87 ;
} else if ( ! F_47 ( V_74 ) ) {
F_48 (ha, netdev)
F_41 ( V_10 , V_77 -> V_1 , V_68 ) ;
}
if ( F_49 ( V_74 ) > V_21 -> V_88 ) {
V_79 = V_84 ;
} else if ( ! F_50 ( V_74 ) ) {
F_51 (ha, netdev)
F_41 ( V_10 , V_77 -> V_1 , V_68 ) ;
}
if ( V_79 == V_84 &&
! V_10 -> V_89 ) {
F_52 ( V_10 ) ;
V_10 -> V_90 = 1 ;
if ( V_10 -> V_81 & V_91 )
V_10 -> V_92 = true ;
} else {
V_10 -> V_90 = 0 ;
V_10 -> V_92 = false ;
}
F_53 ( V_10 , V_79 ) ;
}
void F_54 ( struct V_73 * V_74 )
{
struct V_9 * V_10 = F_45 ( V_74 ) ;
struct V_61 * V_62 ;
struct V_76 * V_77 ;
T_5 V_93 ;
if ( ! F_22 ( V_33 , & V_10 -> V_34 ) )
return;
if ( F_55 ( V_10 ) ) {
if ( ! F_47 ( V_74 ) ) {
F_48 (ha, netdev) {
V_93 = sizeof( struct V_61 ) ;
V_62 = F_42 ( V_93 , V_69 ) ;
if ( V_62 == NULL )
break;
memcpy ( V_62 -> V_59 ,
V_77 -> V_1 , V_60 ) ;
F_43 ( & V_62 -> V_66 , & V_10 -> V_94 ) ;
}
}
F_56 ( V_10 -> V_74 ) ;
return;
}
F_44 ( V_74 , 0 ) ;
}
int F_57 ( struct V_9 * V_10 , V_3 V_79 )
{
struct V_47 V_48 ;
T_1 V_53 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_95 << 23 ) ;
V_53 = V_96 |
( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( V_79 ) ;
return F_21 ( V_10 ,
(struct V_23 * ) & V_48 , 1 ) ;
}
void F_58 ( struct V_9 * V_10 )
{
struct V_63 * V_64 = & V_10 -> V_72 ;
struct V_61 * V_62 ;
while ( ! F_59 ( V_64 ) ) {
V_62 = F_36 ( V_64 -> V_97 , struct V_61 , V_66 ) ;
F_38 ( V_10 ,
V_62 -> V_59 , 0 , V_67 ) ;
F_39 ( & V_62 -> V_66 ) ;
F_40 ( V_62 ) ;
}
}
void F_60 ( struct V_9 * V_10 )
{
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_102 * V_64 ;
int V_26 ;
unsigned long time ;
T_3 V_103 ;
for ( V_26 = 0 ; V_26 < V_10 -> V_104 . V_105 ; V_26 ++ ) {
V_64 = & ( V_10 -> V_104 . V_106 [ V_26 ] ) ;
F_61 (tmp_fil, n, head, fnode) {
V_103 = V_99 -> V_45 ? V_107 :
V_67 ;
time = V_99 -> V_108 ;
if ( V_109 > ( V_110 * V_111 + time ) ) {
F_38 ( V_10 ,
V_99 -> V_112 ,
V_99 -> V_45 ,
V_103 ) ;
F_62 ( & V_10 -> V_113 ) ;
V_10 -> V_104 . V_114 -- ;
F_63 ( & V_99 -> V_115 ) ;
F_64 ( & V_10 -> V_113 ) ;
F_40 ( V_99 ) ;
}
}
}
for ( V_26 = 0 ; V_26 < V_10 -> V_116 . V_105 ; V_26 ++ ) {
V_64 = & ( V_10 -> V_116 . V_106 [ V_26 ] ) ;
F_61 (tmp_fil, n, head, fnode)
{
time = V_99 -> V_108 ;
if ( V_109 > ( V_110 * V_111 + time ) ) {
F_62 ( & V_10 -> V_117 ) ;
V_10 -> V_116 . V_114 -- ;
F_63 ( & V_99 -> V_115 ) ;
F_64 ( & V_10 -> V_117 ) ;
F_40 ( V_99 ) ;
}
}
}
}
void F_65 ( struct V_9 * V_10 )
{
struct V_98 * V_99 ;
struct V_100 * V_101 ;
struct V_102 * V_64 ;
int V_26 ;
T_3 V_103 ;
for ( V_26 = 0 ; V_26 < V_10 -> V_104 . V_105 ; V_26 ++ ) {
V_64 = & ( V_10 -> V_104 . V_106 [ V_26 ] ) ;
F_61 (tmp_fil, n, head, fnode) {
V_103 = V_99 -> V_45 ? V_107 :
V_67 ;
F_38 ( V_10 ,
V_99 -> V_112 ,
V_99 -> V_45 ,
V_103 ) ;
F_62 ( & V_10 -> V_113 ) ;
V_10 -> V_104 . V_114 -- ;
F_63 ( & V_99 -> V_115 ) ;
F_64 ( & V_10 -> V_113 ) ;
F_40 ( V_99 ) ;
}
}
}
static int F_66 ( struct V_9 * V_10 , T_3 V_118 )
{
struct V_47 V_48 ;
int V_119 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_95 << 23 ) ;
V_48 . V_57 = F_32 ( V_120 |
( ( T_1 ) V_10 -> V_20 << 16 ) | ( ( T_1 ) 0x1 << 32 ) ) ;
V_48 . V_58 [ 0 ] = F_32 ( V_118 ) ;
V_119 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_119 != 0 )
F_12 ( & V_10 -> V_17 -> V_18 , L_3 ,
V_118 ? L_4 : L_5 ) ;
return V_119 ;
}
int F_67 ( struct V_9 * V_10 , T_3 V_79 )
{
if ( F_66 ( V_10 , V_79 ) )
return - V_19 ;
if ( F_53 ( V_10 ,
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
F_53 ( V_10 , V_79 ) ;
F_13 ( 1000 ) ;
return 0 ;
}
int F_69 ( struct V_9 * V_10 )
{
T_3 V_121 [ V_60 ] ;
int V_122 ;
V_122 = F_70 ( V_10 , V_121 ,
V_10 -> V_21 -> V_123 ) ;
if ( V_122 )
return V_122 ;
memcpy ( V_10 -> V_21 -> V_124 , V_121 , V_60 ) ;
V_10 -> V_81 |= V_125 ;
return 0 ;
}
int F_71 ( struct V_9 * V_10 )
{
struct V_47 V_48 ;
int V_119 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_95 << 23 ) ;
V_48 . V_57 = F_32 ( V_126 |
( ( T_1 ) V_10 -> V_20 << 16 ) ) ;
V_48 . V_58 [ 0 ] = F_32 ( ( ( T_1 ) V_10 -> V_21 -> V_127 . V_118 ) << 32 ) ;
V_48 . V_58 [ 2 ] = F_32 ( V_10 -> V_21 -> V_127 . V_128 |
( ( T_1 ) V_10 -> V_21 -> V_127 . V_129 ) << 16 ) ;
V_48 . V_58 [ 5 ] = F_32 ( V_10 -> V_21 -> V_127 . V_130 |
( ( T_1 ) V_10 -> V_21 -> V_127 . type ) << 32 |
( ( T_1 ) V_10 -> V_21 -> V_127 . V_131 ) << 40 ) ;
V_119 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_119 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_6 ) ;
return V_119 ;
}
int F_72 ( struct V_9 * V_10 ,
struct V_132 * V_133 )
{
struct V_134 * V_127 = & V_10 -> V_21 -> V_127 ;
int V_119 ;
V_127 -> V_118 = V_135 ;
V_127 -> V_129 = V_133 -> V_136 ;
V_127 -> V_128 = V_133 -> V_137 ;
V_119 = F_71 ( V_10 ) ;
if ( V_119 )
F_73 ( V_10 -> V_74 ,
L_7 ) ;
return V_119 ;
}
int F_74 ( struct V_9 * V_10 , int V_138 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_119 ;
if ( ! F_22 ( V_33 , & V_10 -> V_34 ) )
return 0 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_95 << 23 ) ;
V_53 = V_139 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_53 = 0 ;
if ( V_138 ) {
V_53 = V_140 ;
if ( V_10 -> V_21 -> V_141 [ 0 ] &
V_142 )
V_53 |= V_143 ;
}
V_48 . V_58 [ 0 ] = F_32 ( V_53 ) ;
V_119 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_119 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_8 ) ;
return V_119 ;
}
int F_75 ( struct V_9 * V_10 , V_3 V_138 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_119 ;
if ( ! ! ( V_10 -> V_81 & V_144 ) == V_138 )
return 0 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_95 << 23 ) ;
V_53 = V_145 |
( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( V_138 ) ;
V_119 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_119 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_9 ) ;
V_10 -> V_81 ^= V_144 ;
return V_119 ;
}
int F_76 ( struct V_9 * V_10 , int V_138 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_26 , V_119 ;
static const T_1 V_146 [] = {
0xbeac01fa6a42b73bULL , 0x8030f20c77cb2da3ULL ,
0xae7b30b4d0ca2bcbULL , 0x43a38fb04167253dULL ,
0x255b0ec26d5a56daULL
} ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_95 << 23 ) ;
V_53 = V_147 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_53 = ( ( T_1 ) ( V_148 & 0x3 ) << 4 ) |
( ( T_1 ) ( V_148 & 0x3 ) << 6 ) |
( ( T_1 ) ( V_138 & 0x1 ) << 8 ) |
( ( T_1 ) V_149 << 48 ) |
( T_1 ) V_150 |
( T_1 ) V_151 ;
V_48 . V_58 [ 0 ] = F_32 ( V_53 ) ;
for ( V_26 = 0 ; V_26 < 5 ; V_26 ++ )
V_48 . V_58 [ V_26 + 1 ] = F_32 ( V_146 [ V_26 ] ) ;
V_119 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_119 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 , L_10 ) ;
return V_119 ;
}
void F_77 ( struct V_9 * V_10 ,
T_6 V_152 , int V_103 )
{
struct V_47 V_48 ;
struct V_153 * V_154 ;
T_1 V_53 ;
int V_119 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_95 << 23 ) ;
V_53 = V_155 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( V_103 ) ;
V_154 = (struct V_153 * ) & V_48 . V_58 [ 1 ] ;
V_154 -> V_156 = V_152 ;
V_119 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_119 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_11 ,
( V_103 == V_157 ) ? L_12 : L_13 , V_152 ) ;
}
int F_78 ( struct V_9 * V_10 , int V_138 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_119 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_95 << 23 ) ;
V_53 = V_158 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( V_138 | ( V_138 << 8 ) ) ;
V_119 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_119 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_14 ) ;
return V_119 ;
}
static int F_79 ( struct V_9 * V_10 )
{
struct V_47 V_48 ;
T_1 V_53 ;
int V_119 ;
if ( ! F_22 ( V_33 , & V_10 -> V_34 ) )
return 0 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_95 << 23 ) ;
V_53 = V_159 |
( ( T_1 ) V_10 -> V_20 << 16 ) |
( ( T_1 ) V_160 << 56 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_119 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_119 != 0 )
F_12 ( & V_10 -> V_74 -> V_18 ,
L_15 ) ;
return V_119 ;
}
int F_80 ( struct V_73 * V_74 , int V_161 )
{
struct V_9 * V_10 = F_45 ( V_74 ) ;
int V_162 = 0 ;
if ( V_161 < V_163 || V_161 > V_164 ) {
F_12 ( & V_10 -> V_74 -> V_18 , L_16
L_17 , V_164 , V_163 ) ;
return - V_65 ;
}
V_162 = F_81 ( V_10 , V_161 ) ;
if ( ! V_162 )
V_74 -> V_161 = V_161 ;
return V_162 ;
}
static T_7 F_82 ( struct V_9 * V_10 ,
T_7 V_165 )
{
V_3 V_166 = V_10 -> V_166 ;
if ( V_166 & V_167 ) {
V_165 |= V_168 | V_169 |
V_170 ;
V_10 -> V_171 = 1 ;
if ( F_83 ( V_10 ) ) {
if ( ! ( V_166 & V_172 ) )
V_165 &= ~ V_173 ;
else
V_165 |= V_173 ;
if ( ! ( V_166 & V_174 ) )
V_165 &= ~ V_175 ;
else
V_165 |= V_175 ;
}
} else {
V_165 &= ~ ( V_168 |
V_169 |
V_170 ) ;
if ( F_83 ( V_10 ) )
V_165 &= ~ ( V_173 | V_175 ) ;
V_10 -> V_171 = 0 ;
}
return V_165 ;
}
T_7 F_84 ( struct V_73 * V_74 ,
T_7 V_165 )
{
struct V_9 * V_10 = F_45 ( V_74 ) ;
T_7 V_176 ;
if ( F_18 ( V_10 ) &&
( V_10 -> V_81 & V_91 ) ) {
if ( V_10 -> V_81 & V_177 ) {
V_165 = F_82 ( V_10 , V_165 ) ;
} else {
V_176 = V_165 ^ V_74 -> V_165 ;
V_165 ^= V_176 & ( V_168 |
V_169 |
V_170 |
V_173 |
V_175 ) ;
}
}
if ( ! ( V_165 & V_168 ) )
V_165 &= ~ V_178 ;
return V_165 ;
}
int F_85 ( struct V_73 * V_74 , T_7 V_165 )
{
struct V_9 * V_10 = F_45 ( V_74 ) ;
T_7 V_176 = V_74 -> V_165 ^ V_165 ;
int V_179 = ( V_165 & V_178 ) ? V_180 : 0 ;
if ( ! ( V_176 & V_178 ) )
return 0 ;
V_74 -> V_165 ^= V_178 ;
if ( F_86 ( V_10 , V_179 ) )
return - V_19 ;
if ( ! V_179 && F_18 ( V_10 ) ) {
if ( F_79 ( V_10 ) )
return - V_19 ;
}
return 0 ;
}
static int F_87 ( struct V_75 * V_21 ,
T_8 V_181 , void T_2 * * V_1 )
{
const struct V_182 * V_183 ;
if ( ( V_181 >= V_184 ) || ( V_181 < V_185 ) )
return - V_65 ;
V_181 -= V_185 ;
V_183 = & V_186 [ F_88 ( V_181 ) ] . V_187 [ F_89 ( V_181 ) ] ;
if ( V_183 -> V_188 && ( V_183 -> V_189 <= V_181 ) && ( V_183 -> V_190 > V_181 ) ) {
* V_1 = V_21 -> V_22 + V_183 -> V_191 +
( V_181 - V_183 -> V_189 ) ;
return 0 ;
}
* V_1 = V_21 -> V_22 + V_192 + ( V_181 & F_90 ( 16 ) ) ;
return 1 ;
}
static int
F_91 ( struct V_9 * V_10 , T_8 V_181 )
{
V_3 V_193 ;
void T_2 * V_1 = V_10 -> V_21 -> V_22 + V_194 ;
V_181 -= V_185 ;
V_193 = F_92 ( V_181 ) ;
if ( V_193 == 0 ) {
F_12 ( & V_10 -> V_17 -> V_18 , L_18 , V_181 ) ;
return - V_19 ;
}
F_4 ( V_193 , V_1 ) ;
if ( F_2 ( V_1 ) != V_193 ) {
if ( F_93 () )
F_94 ( & V_10 -> V_17 -> V_18 ,
L_19 ,
V_193 , V_181 ) ;
return - V_19 ;
}
return 0 ;
}
int F_95 ( struct V_9 * V_10 , T_8 V_181 ,
V_3 V_5 )
{
unsigned long V_81 ;
int V_119 ;
void T_2 * V_1 = NULL ;
V_119 = F_87 ( V_10 -> V_21 , V_181 , & V_1 ) ;
if ( V_119 == 0 ) {
F_4 ( V_5 , V_1 ) ;
return 0 ;
}
if ( V_119 > 0 ) {
F_96 ( & V_10 -> V_21 -> V_195 , V_81 ) ;
F_97 ( V_10 ) ;
V_119 = F_91 ( V_10 , V_181 ) ;
if ( ! V_119 )
F_4 ( V_5 , V_1 ) ;
F_98 ( V_10 ) ;
F_99 ( & V_10 -> V_21 -> V_195 , V_81 ) ;
return V_119 ;
}
F_12 ( & V_10 -> V_17 -> V_18 ,
L_20 , V_196 , V_181 ) ;
F_100 () ;
return - V_19 ;
}
int F_101 ( struct V_9 * V_10 , T_8 V_181 ,
int * V_14 )
{
unsigned long V_81 ;
int V_119 ;
V_3 V_5 = - 1 ;
void T_2 * V_1 = NULL ;
V_119 = F_87 ( V_10 -> V_21 , V_181 , & V_1 ) ;
if ( V_119 == 0 )
return F_2 ( V_1 ) ;
if ( V_119 > 0 ) {
F_96 ( & V_10 -> V_21 -> V_195 , V_81 ) ;
F_97 ( V_10 ) ;
if ( ! F_91 ( V_10 , V_181 ) )
V_5 = F_2 ( V_1 ) ;
F_98 ( V_10 ) ;
F_99 ( & V_10 -> V_21 -> V_195 , V_81 ) ;
return V_5 ;
}
F_12 ( & V_10 -> V_17 -> V_18 ,
L_20 , V_196 , V_181 ) ;
F_100 () ;
return - 1 ;
}
void T_2 * F_102 ( struct V_75 * V_21 ,
V_3 V_197 )
{
void T_2 * V_1 = NULL ;
F_103 ( F_87 ( V_21 , V_197 , & V_1 ) ) ;
return V_1 ;
}
static int F_104 ( struct V_9 * V_10 ,
V_3 V_193 , T_1 V_181 , T_1 * V_5 , int V_46 )
{
void T_2 * V_1 ;
V_3 V_198 ;
F_105 ( & V_10 -> V_21 -> V_199 ) ;
F_4 ( V_193 , V_10 -> V_21 -> V_200 ) ;
F_2 ( V_10 -> V_21 -> V_200 ) ;
V_198 = V_201 + V_181 ;
V_1 = V_10 -> V_21 -> V_22 + V_198 ;
if ( V_46 == 0 )
* V_5 = F_1 ( V_1 ) ;
else
F_3 ( * V_5 , V_1 ) ;
F_4 ( 0 , V_10 -> V_21 -> V_200 ) ;
F_2 ( V_10 -> V_21 -> V_200 ) ;
F_106 ( & V_10 -> V_21 -> V_199 ) ;
return 0 ;
}
static void
F_107 ( struct V_9 * V_10 , T_1 V_181 , T_1 * V_5 )
{
void T_2 * V_1 = V_10 -> V_21 -> V_22 +
V_202 + ( V_181 - V_203 ) ;
F_105 ( & V_10 -> V_21 -> V_199 ) ;
* V_5 = F_1 ( V_1 ) ;
F_106 ( & V_10 -> V_21 -> V_199 ) ;
}
static void
F_108 ( struct V_9 * V_10 , T_1 V_181 , T_1 V_5 )
{
void T_2 * V_1 = V_10 -> V_21 -> V_22 +
V_202 + ( V_181 - V_203 ) ;
F_105 ( & V_10 -> V_21 -> V_199 ) ;
F_3 ( V_5 , V_1 ) ;
F_106 ( & V_10 -> V_21 -> V_199 ) ;
}
static void F_109 ( struct V_9 * V_10 , T_1 V_181 ,
struct V_204 * V_205 )
{
V_205 -> V_206 = V_207 ;
V_205 -> V_208 = V_209 ;
V_205 -> V_210 = V_211 ;
if ( V_181 & 0xf ) {
V_205 -> V_212 [ 0 ] = V_213 ;
V_205 -> V_214 [ 0 ] = V_215 ;
V_205 -> V_212 [ 1 ] = V_216 ;
V_205 -> V_214 [ 1 ] = V_217 ;
V_205 -> V_212 [ 2 ] = V_218 ;
V_205 -> V_212 [ 3 ] = V_219 ;
V_205 -> V_214 [ 2 ] = V_220 ;
V_205 -> V_214 [ 3 ] = V_221 ;
} else {
V_205 -> V_212 [ 0 ] = V_218 ;
V_205 -> V_214 [ 0 ] = V_220 ;
V_205 -> V_212 [ 1 ] = V_219 ;
V_205 -> V_214 [ 1 ] = V_221 ;
V_205 -> V_212 [ 2 ] = V_213 ;
V_205 -> V_212 [ 3 ] = V_216 ;
V_205 -> V_214 [ 2 ] = V_215 ;
V_205 -> V_214 [ 3 ] = V_217 ;
}
V_205 -> V_222 = F_110 ( V_181 ) ;
V_205 -> V_181 = F_111 ( V_181 ) ;
}
int F_112 ( struct V_9 * V_10 , T_1 V_181 , T_1 V_5 )
{
int V_223 , V_122 = 0 ;
V_3 V_93 , V_224 ;
struct V_204 V_205 ;
if ( V_181 & 7 )
return - V_19 ;
memset ( & V_205 , 0 , sizeof( struct V_204 ) ) ;
if ( ! ( F_113 ( V_181 , V_225 ,
V_226 ) ||
F_113 ( V_181 , V_227 ,
V_228 ) ) )
return - V_19 ;
F_109 ( V_10 , V_181 , & V_205 ) ;
if ( F_113 ( V_181 , V_229 , V_230 ) )
return F_104 ( V_10 , V_205 . V_222 ,
V_205 . V_181 , & V_5 , 1 ) ;
V_224 = V_181 & ~ 0xf ;
F_105 ( & V_10 -> V_21 -> V_199 ) ;
F_19 ( V_10 , V_205 . V_208 , V_224 ) ;
F_19 ( V_10 , V_205 . V_210 , 0 ) ;
F_19 ( V_10 , V_205 . V_206 , V_231 ) ;
F_19 ( V_10 , V_205 . V_206 , V_232 ) ;
for ( V_223 = 0 ; V_223 < V_233 ; V_223 ++ ) {
V_93 = F_17 ( V_10 , V_205 . V_206 ) ;
if ( ( V_93 & V_234 ) == 0 )
break;
}
if ( V_223 >= V_233 ) {
V_122 = - V_19 ;
goto V_15;
}
F_19 ( V_10 , V_205 . V_212 [ 0 ] , F_17 ( V_10 , V_205 . V_214 [ 0 ] ) ) ;
F_19 ( V_10 , V_205 . V_212 [ 1 ] , F_17 ( V_10 , V_205 . V_214 [ 1 ] ) ) ;
F_19 ( V_10 , V_205 . V_212 [ 2 ] , V_5 & 0xffffffff ) ;
F_19 ( V_10 , V_205 . V_212 [ 3 ] , ( V_5 >> 32 ) & 0xffffffff ) ;
F_19 ( V_10 , V_205 . V_206 , V_235 ) ;
F_19 ( V_10 , V_205 . V_206 , V_236 ) ;
for ( V_223 = 0 ; V_223 < V_233 ; V_223 ++ ) {
V_93 = F_17 ( V_10 , V_205 . V_206 ) ;
if ( ( V_93 & V_234 ) == 0 )
break;
}
if ( V_223 >= V_233 ) {
if ( F_93 () )
F_12 ( & V_10 -> V_17 -> V_18 ,
L_21 ) ;
V_122 = - V_19 ;
} else
V_122 = 0 ;
V_15:
F_106 ( & V_10 -> V_21 -> V_199 ) ;
return V_122 ;
}
int F_114 ( struct V_9 * V_10 , T_1 V_181 , T_1 * V_5 )
{
int V_223 , V_122 ;
V_3 V_93 , V_224 ;
T_1 V_2 ;
struct V_204 V_205 ;
if ( V_181 & 7 )
return - V_19 ;
if ( ! ( F_113 ( V_181 , V_225 ,
V_226 ) ||
F_113 ( V_181 , V_227 ,
V_228 ) ) )
return - V_19 ;
memset ( & V_205 , 0 , sizeof( struct V_204 ) ) ;
F_109 ( V_10 , V_181 , & V_205 ) ;
if ( F_113 ( V_181 , V_229 , V_230 ) )
return F_104 ( V_10 , V_205 . V_222 ,
V_205 . V_181 , V_5 , 0 ) ;
F_105 ( & V_10 -> V_21 -> V_199 ) ;
V_224 = V_181 & ~ 0xf ;
F_19 ( V_10 , V_205 . V_208 , V_224 ) ;
F_19 ( V_10 , V_205 . V_210 , 0 ) ;
F_19 ( V_10 , V_205 . V_206 , V_231 ) ;
F_19 ( V_10 , V_205 . V_206 , V_232 ) ;
for ( V_223 = 0 ; V_223 < V_233 ; V_223 ++ ) {
V_93 = F_17 ( V_10 , V_205 . V_206 ) ;
if ( ( V_93 & V_234 ) == 0 )
break;
}
if ( V_223 >= V_233 ) {
if ( F_93 () )
F_12 ( & V_10 -> V_17 -> V_18 ,
L_22 ) ;
V_122 = - V_19 ;
} else {
V_93 = F_17 ( V_10 , V_205 . V_214 [ 3 ] ) ;
V_2 = ( T_1 ) V_93 << 32 ;
V_2 |= F_17 ( V_10 , V_205 . V_214 [ 2 ] ) ;
* V_5 = V_2 ;
V_122 = 0 ;
}
F_106 ( & V_10 -> V_21 -> V_199 ) ;
return V_122 ;
}
int F_115 ( struct V_9 * V_10 )
{
int V_197 , V_237 , V_238 , V_14 = 0 ;
struct V_239 * V_17 = V_10 -> V_17 ;
V_197 = V_240 ;
if ( F_116 ( V_10 , V_197 , & V_238 ) )
return - V_19 ;
if ( V_238 != V_241 ) {
F_12 ( & V_17 -> V_18 , L_23 ,
V_238 ) ;
return - V_19 ;
}
V_197 = V_242 ;
if ( F_116 ( V_10 , V_197 , & V_237 ) )
return - V_19 ;
V_10 -> V_21 -> V_237 = V_237 ;
if ( V_237 == V_243 ) {
V_3 V_244 = F_9 ( V_10 , V_245 , & V_14 ) ;
if ( V_14 == - V_19 )
return V_14 ;
if ( ( V_244 & 0x8000 ) == 0 )
V_237 = V_246 ;
}
switch ( V_237 ) {
case V_247 :
case V_248 :
case V_249 :
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
V_10 -> V_21 -> V_257 = V_258 ;
break;
case V_259 :
case V_260 :
case V_243 :
V_10 -> V_21 -> V_257 = V_261 ;
break;
case V_246 :
V_10 -> V_21 -> V_257 = ( V_10 -> V_20 < 2 ) ?
V_258 : V_261 ;
break;
default:
F_12 ( & V_17 -> V_18 , L_24 , V_237 ) ;
V_10 -> V_21 -> V_257 = V_258 ;
break;
}
return 0 ;
}
static int
F_117 ( struct V_9 * V_10 )
{
V_3 V_262 ;
int V_14 = 0 ;
V_262 = F_9 ( V_10 , V_263 , & V_14 ) ;
if ( V_262 & ( 1UL << V_10 -> V_20 ) ) {
V_262 = F_9 ( V_10 , V_264 , & V_14 ) ;
if ( V_14 == - V_19 )
return V_14 ;
if ( V_262 & ( 1 << V_10 -> V_20 ) )
return 1 ;
}
return 0 ;
}
int F_118 ( struct V_9 * V_10 , V_3 V_34 , V_3 V_265 )
{
struct V_47 V_48 ;
int V_119 ;
T_1 V_53 ;
memset ( & V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 . V_54 = F_32 ( V_95 << 23 ) ;
V_53 = V_266 | ( ( T_1 ) V_10 -> V_20 << 16 ) ;
V_48 . V_57 = F_32 ( V_53 ) ;
V_48 . V_58 [ 0 ] = F_32 ( ( ( T_1 ) V_265 << 32 ) | V_10 -> V_20 ) ;
V_48 . V_58 [ 1 ] = F_32 ( V_34 ) ;
V_119 = F_21 ( V_10 , (struct V_23 * ) & V_48 , 1 ) ;
if ( V_119 )
F_12 ( & V_10 -> V_17 -> V_18 , L_25 ) ;
return V_119 ;
}
void F_119 ( struct V_9 * V_10 )
{
struct V_75 * V_21 = V_10 -> V_21 ;
struct V_267 V_103 ;
T_3 V_268 ;
int V_14 = 0 ;
if ( V_21 -> V_141 [ 0 ] & V_269 ) {
V_14 = F_120 ( & V_103 , V_10 ,
V_270 ) ;
if ( ! V_14 ) {
V_14 = F_121 ( V_10 , & V_103 ) ;
if ( V_14 ) {
F_73 ( V_10 -> V_74 ,
L_26 ,
V_14 ) ;
} else {
V_268 = V_103 . V_271 . V_272 [ 1 ] ;
if ( V_268 == V_273 )
V_21 -> V_268 = V_274 ;
else if ( V_268 == V_275 )
V_21 -> V_268 = V_276 ;
}
}
F_122 ( & V_103 ) ;
}
return;
}
void F_123 ( struct V_9 * V_10 )
{
void T_2 * V_277 ;
V_3 V_278 ;
V_3 V_279 ;
F_124 ( V_10 -> V_17 , V_280 , & V_278 ) ;
V_277 = V_10 -> V_21 -> V_22 + V_281 ;
V_279 = F_2 ( V_277 ) ;
V_278 = ( V_278 - V_279 ) / V_282 ;
V_10 -> V_21 -> V_283 = V_278 ;
}
void F_125 ( struct V_9 * V_10 , char * V_284 ,
T_9 V_197 , T_5 V_285 )
{
int V_14 = 0 ;
V_3 V_5 ;
T_1 V_286 ;
if ( F_113 ( V_197 , V_203 , V_287 ) ) {
F_107 ( V_10 , V_197 , & V_286 ) ;
memcpy ( V_284 , & V_286 , V_285 ) ;
} else {
V_5 = F_9 ( V_10 , V_197 , & V_14 ) ;
memcpy ( V_284 , & V_5 , V_285 ) ;
}
}
void F_126 ( struct V_9 * V_10 , char * V_284 ,
T_9 V_197 , T_5 V_285 )
{
V_3 V_5 ;
T_1 V_286 ;
if ( F_113 ( V_197 , V_203 , V_287 ) ) {
memcpy ( & V_286 , V_284 , V_285 ) ;
F_108 ( V_10 , V_197 , V_286 ) ;
} else {
memcpy ( & V_5 , V_284 , V_285 ) ;
F_14 ( V_10 , V_197 , V_5 ) ;
}
}
int F_127 ( struct V_9 * V_10 )
{
return F_8 ( V_10 , 5 , 0 ) ;
}
void F_128 ( struct V_9 * V_10 )
{
F_15 ( V_10 , 5 ) ;
}
int F_129 ( struct V_239 * V_17 )
{
struct V_9 * V_10 = F_130 ( V_17 ) ;
struct V_73 * V_74 = V_10 -> V_74 ;
int V_288 ;
F_131 ( V_74 ) ;
F_132 ( V_10 ) ;
if ( F_133 ( V_74 ) )
F_134 ( V_10 , V_74 ) ;
F_135 ( V_10 , 0 ) ;
F_136 ( V_289 , & V_10 -> V_34 ) ;
V_288 = F_137 ( V_17 ) ;
if ( V_288 )
return V_288 ;
if ( F_117 ( V_10 ) ) {
F_138 ( V_17 , V_290 , 1 ) ;
F_138 ( V_17 , V_291 , 1 ) ;
}
return 0 ;
}
int F_139 ( struct V_9 * V_10 )
{
struct V_73 * V_74 = V_10 -> V_74 ;
int V_14 ;
V_14 = F_140 ( V_10 ) ;
if ( V_14 ) {
F_12 ( & V_10 -> V_17 -> V_18 , L_27 ) ;
return V_14 ;
}
if ( F_133 ( V_74 ) ) {
V_14 = F_141 ( V_10 , V_74 ) ;
if ( ! V_14 )
F_142 ( V_74 , V_292 ) ;
}
F_143 ( V_74 ) ;
F_144 ( V_10 , V_293 , V_294 ) ;
return V_14 ;
}
