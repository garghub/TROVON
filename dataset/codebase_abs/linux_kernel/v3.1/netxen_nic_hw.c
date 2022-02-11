static inline T_1 F_1 ( void T_2 * V_1 )
{
return F_2 ( V_1 ) | ( ( ( T_1 ) F_2 ( V_1 + 4 ) ) << 32LL ) ;
}
static inline void F_3 ( T_1 V_2 , void T_2 * V_1 )
{
F_4 ( ( ( V_3 ) ( V_2 ) ) , ( V_1 ) ) ;
F_4 ( ( ( V_3 ) ( V_2 >> 32 ) ) , ( V_1 + 4 ) ) ;
}
static void T_2 * F_5 ( struct V_4 * V_5 ,
unsigned long V_6 )
{
if ( F_6 ( V_6 , V_7 , V_8 ) )
return F_7 ( V_5 , V_6 ) ;
if ( F_6 ( V_6 , V_9 , V_10 ) )
return F_8 ( V_5 , V_6 ) ;
if ( F_6 ( V_6 , V_11 , V_12 ) )
return F_9 ( V_5 , V_6 ) ;
return NULL ;
}
int
F_10 ( struct V_4 * V_5 , int V_13 , V_3 V_14 )
{
int V_15 = 0 , V_16 = 0 ;
while ( ! V_15 ) {
V_15 = F_11 ( V_5 , F_12 ( F_13 ( V_13 ) ) ) ;
if ( V_15 == 1 )
break;
if ( ++ V_16 >= V_17 )
return - V_18 ;
F_14 ( 1 ) ;
}
if ( V_14 )
F_15 ( V_5 , V_14 , V_5 -> V_19 ) ;
return 0 ;
}
void
F_16 ( struct V_4 * V_5 , int V_13 )
{
F_11 ( V_5 , F_12 ( F_17 ( V_13 ) ) ) ;
}
static int F_18 ( struct V_4 * V_5 , int V_20 )
{
if ( F_19 ( V_5 -> V_21 . V_22 ) ) {
F_15 ( V_5 , V_23 + ( 0x10000 * V_20 ) , 0x1447 ) ;
F_15 ( V_5 , V_24 + ( 0x10000 * V_20 ) , 0x5 ) ;
}
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
T_3 V_25 ;
V_3 V_20 = V_5 -> V_26 ;
if ( F_21 ( V_5 -> V_21 . V_22 ) )
return 0 ;
if ( V_20 > V_27 )
return - V_28 ;
V_25 = 0 ;
if ( F_15 ( V_5 ,
V_24 + ( 0x10000 * V_20 ) , V_25 ) )
return - V_18 ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 , V_3 V_29 )
{
V_3 V_25 ;
V_3 V_30 = 0 ;
T_3 V_31 = 0x0200 ;
V_3 V_20 = V_5 -> V_26 ;
T_4 V_32 = V_5 -> V_21 . V_32 ;
if ( V_20 > V_27 )
return - V_28 ;
V_25 = F_11 ( V_5 , V_24 + ( 0x10000 * V_20 ) ) ;
V_25 &= ~ 0x4 ;
F_15 ( V_5 , V_24 + ( 0x10000 * V_20 ) , V_25 ) ;
if ( ( V_32 == V_33 ) ||
( V_32 == V_34 ) )
V_31 = ( 0x20 << V_20 ) ;
F_15 ( V_5 , V_35 , V_31 ) ;
F_23 ( 10 ) ;
while ( F_11 ( V_5 , V_36 ) && ++ V_30 < 20 )
F_23 ( 10 ) ;
if ( V_30 < 20 ) {
V_31 = F_11 ( V_5 ,
V_23 + ( 0x10000 * V_20 ) ) ;
if ( V_29 == V_37 )
V_31 = ( V_31 | 0x2000UL ) ;
else
V_31 = ( V_31 & ~ 0x2000UL ) ;
if ( V_29 == V_38 )
V_31 = ( V_31 | 0x1000UL ) ;
else
V_31 = ( V_31 & ~ 0x1000UL ) ;
F_15 ( V_5 ,
V_23 + ( 0x10000 * V_20 ) , V_31 ) ;
}
V_25 |= 0x4 ;
F_15 ( V_5 , V_24 + ( 0x10000 * V_20 ) , V_25 ) ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 , T_5 * V_1 )
{
V_3 V_39 , V_40 ;
V_3 V_41 , V_42 ;
T_5 V_43 = V_5 -> V_26 ;
if ( V_43 >= V_27 )
return - V_28 ;
V_40 = ( ( V_3 ) V_1 [ 0 ] << 16 ) | ( ( V_3 ) V_1 [ 1 ] << 24 ) ;
V_39 = V_1 [ 2 ] | ( ( V_3 ) V_1 [ 3 ] << 8 ) |
( ( V_3 ) V_1 [ 4 ] << 16 ) | ( ( V_3 ) V_1 [ 5 ] << 24 ) ;
V_42 = V_44 + ( 0x10000 * V_43 ) ;
V_41 = V_45 + ( 0x10000 * V_43 ) ;
if ( F_15 ( V_5 , V_42 , V_40 ) || F_15 ( V_5 , V_41 , V_39 ) )
return - V_18 ;
if ( F_15 ( V_5 , V_42 , V_40 ) || F_15 ( V_5 , V_41 , V_39 ) )
return - V_18 ;
return 0 ;
}
static int
F_25 ( struct V_4 * V_5 )
{
V_3 V_2 = 0 ;
T_4 V_20 = V_5 -> V_26 ;
T_5 * V_1 = V_5 -> V_46 ;
if ( V_5 -> V_47 )
return 0 ;
V_2 = F_11 ( V_5 , V_48 ) ;
V_2 |= ( 1UL << ( 28 + V_20 ) ) ;
F_15 ( V_5 , V_48 , V_2 ) ;
V_2 = 0xffffff ;
F_15 ( V_5 , F_26 ( V_20 , 0 ) , V_2 ) ;
F_15 ( V_5 , F_26 ( V_20 , 0 ) + 4 , V_2 ) ;
V_2 = F_27 ( V_1 ) ;
F_15 ( V_5 , F_26 ( V_20 , 1 ) , V_2 ) ;
V_2 = F_28 ( V_1 ) ;
F_15 ( V_5 , F_26 ( V_20 , 1 ) + 4 , V_2 ) ;
V_5 -> V_47 = 1 ;
return 0 ;
}
static int
F_29 ( struct V_4 * V_5 )
{
V_3 V_2 = 0 ;
T_4 V_20 = V_5 -> V_26 ;
T_5 * V_1 = V_5 -> V_46 ;
if ( ! V_5 -> V_47 )
return 0 ;
V_2 = F_11 ( V_5 , V_48 ) ;
V_2 &= ~ ( 1UL << ( 28 + V_20 ) ) ;
F_15 ( V_5 , V_48 , V_2 ) ;
V_2 = F_27 ( V_1 ) ;
F_15 ( V_5 , F_26 ( V_20 , 0 ) , V_2 ) ;
V_2 = F_28 ( V_1 ) ;
F_15 ( V_5 , F_26 ( V_20 , 0 ) + 4 , V_2 ) ;
F_15 ( V_5 , F_26 ( V_20 , 1 ) , 0 ) ;
F_15 ( V_5 , F_26 ( V_20 , 1 ) + 4 , 0 ) ;
V_5 -> V_47 = 0 ;
return 0 ;
}
static int
F_30 ( struct V_4 * V_5 ,
int V_49 , T_5 * V_1 )
{
V_3 V_50 = 0 , V_51 = 0 ;
T_4 V_20 = V_5 -> V_26 ;
V_51 = F_28 ( V_1 ) ;
V_50 = F_27 ( V_1 ) ;
F_15 ( V_5 , F_31 ( V_20 , V_49 ) , V_50 ) ;
F_15 ( V_5 , F_31 ( V_20 , V_49 ) + 4 , V_51 ) ;
return 0 ;
}
static void F_32 ( struct V_52 * V_53 )
{
struct V_4 * V_5 = F_33 ( V_53 ) ;
struct V_54 * V_55 ;
T_5 V_56 [ 6 ] ;
int V_57 ;
memset ( V_56 , 0 , 6 ) ;
if ( V_53 -> V_58 & V_59 ) {
V_5 -> V_60 ( V_5 ,
V_37 ) ;
F_29 ( V_5 ) ;
return;
}
if ( F_34 ( V_53 ) ) {
V_5 -> V_60 ( V_5 ,
V_61 ) ;
F_29 ( V_5 ) ;
return;
}
V_5 -> V_60 ( V_5 , V_38 ) ;
if ( V_53 -> V_58 & V_62 ||
F_35 ( V_53 ) > V_5 -> V_63 ) {
F_29 ( V_5 ) ;
return;
}
F_25 ( V_5 ) ;
V_57 = 0 ;
F_36 (ha, netdev)
F_30 ( V_5 , V_57 ++ , V_55 -> V_1 ) ;
while ( V_57 < V_5 -> V_63 )
F_30 ( V_5 , V_57 ++ , V_56 ) ;
}
static int
F_37 ( struct V_4 * V_5 ,
struct V_64 * V_65 , int V_66 )
{
V_3 V_57 , V_67 , V_68 ;
struct V_69 * V_70 ;
struct V_64 * V_71 ;
struct V_72 * V_73 ;
V_57 = 0 ;
if ( V_5 -> V_74 != V_75 )
return - V_18 ;
V_73 = V_5 -> V_73 ;
F_38 ( V_73 -> V_76 ) ;
V_67 = V_73 -> V_67 ;
V_68 = V_73 -> V_77 ;
if ( V_66 >= F_39 ( V_73 ) ) {
F_40 ( V_73 -> V_76 ) ;
F_41 () ;
if ( F_39 ( V_73 ) > V_66 ) {
if ( F_39 ( V_73 ) > V_78 )
F_42 ( V_73 -> V_76 ) ;
} else {
F_43 ( V_73 -> V_76 ) ;
return - V_79 ;
}
}
do {
V_71 = & V_65 [ V_57 ] ;
V_70 = & V_73 -> V_80 [ V_67 ] ;
V_70 -> V_81 = NULL ;
V_70 -> V_82 = 0 ;
memcpy ( & V_73 -> V_83 [ V_67 ] ,
& V_65 [ V_57 ] , sizeof( struct V_64 ) ) ;
V_67 = F_44 ( V_67 , V_73 -> V_84 ) ;
V_57 ++ ;
} while ( V_57 != V_66 );
V_73 -> V_67 = V_67 ;
F_45 ( V_5 , V_73 ) ;
F_43 ( V_73 -> V_76 ) ;
return 0 ;
}
static int
F_46 ( struct V_4 * V_5 , T_5 * V_1 , unsigned V_85 )
{
T_6 V_86 ;
T_7 * V_87 ;
T_1 V_88 ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_90 << 23 ) ;
V_88 = V_91 | ( ( T_1 ) V_5 -> V_19 << 16 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_87 = ( T_7 * ) & V_86 . V_93 [ 0 ] ;
V_87 -> V_85 = V_85 ;
memcpy ( V_87 -> V_46 , V_1 , 6 ) ;
return F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
}
static int F_48 ( struct V_4 * V_5 ,
const T_5 * V_1 , struct V_94 * V_95 )
{
struct V_94 * V_96 ;
T_8 * V_97 ;
F_49 (head, del_list) {
V_97 = F_50 ( V_96 , T_8 , V_98 ) ;
if ( memcmp ( V_1 , V_97 -> V_46 , V_99 ) == 0 ) {
F_51 ( V_96 , & V_5 -> V_100 ) ;
return 0 ;
}
}
V_97 = F_52 ( sizeof( T_8 ) , V_101 ) ;
if ( V_97 == NULL ) {
F_53 ( V_102 L_1 ,
V_5 -> V_53 -> V_103 ) ;
return - V_104 ;
}
memcpy ( V_97 -> V_46 , V_1 , V_99 ) ;
F_54 ( & V_97 -> V_98 , & V_5 -> V_100 ) ;
return F_46 ( V_5 ,
V_97 -> V_46 , V_105 ) ;
}
static void F_55 ( struct V_52 * V_53 )
{
struct V_4 * V_5 = F_33 ( V_53 ) ;
struct V_54 * V_55 ;
static const T_5 V_106 [ V_99 ] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
V_3 V_29 = V_107 ;
F_56 ( V_95 ) ;
struct V_94 * V_96 ;
T_8 * V_97 ;
if ( V_5 -> V_74 != V_75 )
return;
F_57 ( & V_5 -> V_100 , & V_95 ) ;
F_48 ( V_5 , V_5 -> V_46 , & V_95 ) ;
F_48 ( V_5 , V_106 , & V_95 ) ;
if ( V_53 -> V_58 & V_59 ) {
V_29 = V_108 ;
goto V_109;
}
if ( ( V_53 -> V_58 & V_62 ) ||
( F_35 ( V_53 ) > V_5 -> V_63 ) ) {
V_29 = V_110 ;
goto V_109;
}
if ( ! F_34 ( V_53 ) ) {
F_36 (ha, netdev)
F_48 ( V_5 , V_55 -> V_1 , & V_95 ) ;
}
V_109:
V_5 -> V_60 ( V_5 , V_29 ) ;
V_96 = & V_95 ;
while ( ! F_58 ( V_96 ) ) {
V_97 = F_50 ( V_96 -> V_111 , T_8 , V_98 ) ;
F_46 ( V_5 ,
V_97 -> V_46 , V_112 ) ;
F_59 ( & V_97 -> V_98 ) ;
F_60 ( V_97 ) ;
}
}
static int F_61 ( struct V_4 * V_5 , V_3 V_29 )
{
T_6 V_86 ;
T_1 V_88 ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 = V_114 |
( ( T_1 ) V_5 -> V_19 << 16 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_86 . V_93 [ 0 ] = F_47 ( V_29 ) ;
return F_37 ( V_5 ,
(struct V_64 * ) & V_86 , 1 ) ;
}
void F_62 ( struct V_4 * V_5 )
{
T_8 * V_97 ;
struct V_94 * V_96 = & V_5 -> V_100 ;
while ( ! F_58 ( V_96 ) ) {
V_97 = F_50 ( V_96 -> V_111 , T_8 , V_98 ) ;
F_46 ( V_5 ,
V_97 -> V_46 , V_112 ) ;
F_59 ( & V_97 -> V_98 ) ;
F_60 ( V_97 ) ;
}
}
static int F_63 ( struct V_4 * V_5 , T_5 * V_1 )
{
F_55 ( V_5 -> V_53 ) ;
return 0 ;
}
int F_64 ( struct V_4 * V_5 )
{
T_6 V_86 ;
T_1 V_88 [ 6 ] ;
int V_115 , V_57 ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
memset ( V_88 , 0 , sizeof( V_88 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 [ 0 ] = V_116 | ( ( T_1 ) V_5 -> V_19 << 16 ) ;
V_86 . V_92 = F_47 ( V_88 [ 0 ] ) ;
memcpy ( & V_88 [ 0 ] , & V_5 -> V_117 , sizeof( V_5 -> V_117 ) ) ;
for ( V_57 = 0 ; V_57 < 6 ; V_57 ++ )
V_86 . V_93 [ V_57 ] = F_47 ( V_88 [ V_57 ] ) ;
V_115 = F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
if ( V_115 != 0 ) {
F_53 ( V_102 L_2
L_3 ) ;
}
return V_115 ;
}
int F_65 ( struct V_4 * V_5 , int V_118 )
{
T_6 V_86 ;
T_1 V_88 ;
int V_115 = 0 ;
if ( ! F_66 ( V_119 , & V_5 -> V_120 ) )
return 0 ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 = V_121 | ( ( T_1 ) V_5 -> V_19 << 16 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_86 . V_93 [ 0 ] = F_47 ( V_118 ) ;
V_115 = F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
if ( V_115 != 0 ) {
F_53 ( V_102 L_2
L_4 ) ;
}
return V_115 ;
}
int F_67 ( struct V_4 * V_5 , int V_118 )
{
T_6 V_86 ;
T_1 V_88 ;
int V_115 = 0 ;
if ( ! ! ( V_5 -> V_58 & V_122 ) == V_118 )
return V_115 ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 = V_123 |
( ( T_1 ) V_5 -> V_19 << 16 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_86 . V_93 [ 0 ] = F_47 ( V_118 ) ;
V_115 = F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
if ( V_115 != 0 ) {
F_53 ( V_102 L_2
L_5 ) ;
}
V_5 -> V_58 ^= V_122 ;
return V_115 ;
}
int F_68 ( struct V_4 * V_5 , int V_118 )
{
T_6 V_86 ;
T_1 V_88 ;
int V_57 , V_115 ;
static const T_1 V_124 [] = {
0xbeac01fa6a42b73bULL , 0x8030f20c77cb2da3ULL ,
0xae7b30b4d0ca2bcbULL , 0x43a38fb04167253dULL ,
0x255b0ec26d5a56daULL
} ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 = V_125 | ( ( T_1 ) V_5 -> V_19 << 16 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_88 = ( ( T_1 ) ( V_126 & 0x3 ) << 4 ) |
( ( T_1 ) ( V_126 & 0x3 ) << 6 ) |
( ( T_1 ) ( V_118 & 0x1 ) << 8 ) |
( ( 0x7ULL ) << 48 ) ;
V_86 . V_93 [ 0 ] = F_47 ( V_88 ) ;
for ( V_57 = 0 ; V_57 < F_69 ( V_124 ) ; V_57 ++ )
V_86 . V_93 [ V_57 + 1 ] = F_47 ( V_124 [ V_57 ] ) ;
V_115 = F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
if ( V_115 != 0 ) {
F_53 ( V_102 L_6 ,
V_5 -> V_53 -> V_103 ) ;
}
return V_115 ;
}
int F_70 ( struct V_4 * V_5 , V_3 V_127 , int V_128 )
{
T_6 V_86 ;
T_1 V_88 ;
int V_115 ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 = V_129 | ( ( T_1 ) V_5 -> V_19 << 16 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_86 . V_93 [ 0 ] = F_47 ( V_128 ) ;
V_86 . V_93 [ 1 ] = F_47 ( V_127 ) ;
V_115 = F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
if ( V_115 != 0 ) {
F_53 ( V_102 L_7 ,
V_5 -> V_53 -> V_103 ,
( V_128 == V_130 ) ? L_8 : L_9 , V_127 ) ;
}
return V_115 ;
}
int F_71 ( struct V_4 * V_5 , int V_118 )
{
T_6 V_86 ;
T_1 V_88 ;
int V_115 ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 = V_131 | ( ( T_1 ) V_5 -> V_19 << 16 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_86 . V_93 [ 0 ] = F_47 ( V_118 | ( V_118 << 8 ) ) ;
V_115 = F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
if ( V_115 != 0 ) {
F_53 ( V_102 L_10 ,
V_5 -> V_53 -> V_103 ) ;
}
return V_115 ;
}
int F_72 ( struct V_4 * V_5 )
{
T_6 V_86 ;
T_1 V_88 ;
int V_115 ;
if ( ! F_66 ( V_119 , & V_5 -> V_120 ) )
return 0 ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 = V_132 |
( ( T_1 ) V_5 -> V_19 << 16 ) |
( ( T_1 ) V_133 << 56 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_115 = F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
if ( V_115 != 0 ) {
F_53 ( V_102 L_11 ,
V_5 -> V_53 -> V_103 ) ;
}
return V_115 ;
}
int F_73 ( struct V_52 * V_53 , int V_134 )
{
struct V_4 * V_5 = F_33 ( V_53 ) ;
int V_135 ;
int V_136 = 0 ;
if ( F_21 ( V_5 -> V_21 . V_22 ) )
V_135 = V_137 ;
else
V_135 = V_138 ;
if ( V_134 > V_135 ) {
F_53 ( V_102 L_12 ,
V_53 -> V_103 , V_135 ) ;
return - V_28 ;
}
if ( V_5 -> V_139 )
V_136 = V_5 -> V_139 ( V_5 , V_134 ) ;
if ( ! V_136 )
V_53 -> V_134 = V_134 ;
return V_136 ;
}
static int F_74 ( struct V_4 * V_5 , int V_140 ,
int V_141 , T_9 * V_142 )
{
int V_57 , V_143 , V_1 ;
T_9 * V_144 ;
V_1 = V_140 ;
V_144 = V_142 ;
for ( V_57 = 0 ; V_57 < V_141 / sizeof( V_3 ) ; V_57 ++ ) {
if ( F_75 ( V_5 , V_1 , & V_143 ) == - 1 )
return - 1 ;
* V_144 = F_76 ( V_143 ) ;
V_144 ++ ;
V_1 += sizeof( V_3 ) ;
}
if ( ( char * ) V_142 + V_141 > ( char * ) V_144 ) {
T_9 V_145 ;
if ( F_75 ( V_5 , V_1 , & V_143 ) == - 1 )
return - 1 ;
V_145 = F_76 ( V_143 ) ;
memcpy ( V_144 , & V_145 , ( char * ) V_142 + V_141 - ( char * ) V_144 ) ;
}
return 0 ;
}
int F_77 ( struct V_4 * V_5 , T_1 * V_146 )
{
T_9 * V_147 = ( T_9 * ) V_146 ;
V_3 V_148 ;
V_148 = V_149 + ( V_5 -> V_19 * sizeof( T_1 ) ) ;
if ( F_74 ( V_5 , V_148 , sizeof( T_1 ) , V_147 ) == - 1 )
return - 1 ;
if ( * V_146 == F_47 ( ~ 0ULL ) ) {
V_148 = V_150 +
( V_5 -> V_19 * sizeof( T_1 ) ) ;
if ( F_74 ( V_5 ,
V_148 , sizeof( T_1 ) , V_147 ) == - 1 )
return - 1 ;
if ( * V_146 == F_47 ( ~ 0ULL ) )
return - 1 ;
}
return 0 ;
}
int F_78 ( struct V_4 * V_5 , T_1 * V_146 )
{
T_10 V_151 , V_39 , V_40 ;
int V_152 = V_5 -> V_21 . V_152 ;
V_151 = V_153 +
( 4 * ( ( V_152 / 2 ) * 3 ) ) + ( 4 * ( V_152 & 1 ) ) ;
V_40 = F_11 ( V_5 , V_151 ) ;
V_39 = F_11 ( V_5 , V_151 + 4 ) ;
if ( V_152 & 1 )
* V_146 = F_79 ( ( V_40 >> 16 ) | ( ( T_1 ) V_39 << 16 ) ) ;
else
* V_146 = F_79 ( ( T_1 ) V_40 | ( ( T_1 ) V_39 << 32 ) ) ;
return 0 ;
}
static void
F_80 ( struct V_4 * V_5 ,
V_3 V_154 )
{
void T_2 * V_148 ;
int V_155 = 10 ;
T_5 V_156 = V_5 -> V_21 . V_152 ;
if ( V_5 -> V_21 . V_157 == V_154 )
return;
V_148 = F_8 ( V_5 ,
F_81 ( F_82 ( V_156 ) ) ) ;
F_4 ( V_154 , V_148 ) ;
do {
if ( V_154 == F_2 ( V_148 ) )
break;
if ( F_83 () )
F_84 ( & V_5 -> V_158 -> V_159 ,
L_13 ,
( V_154 == V_160 ) ) ;
F_85 ( 1 ) ;
} while ( -- V_155 > 0 );
if ( V_155 > 0 )
V_5 -> V_21 . V_157 = V_154 ;
}
static int
F_86 ( struct V_4 * V_5 ,
T_11 V_6 , void T_2 * * V_1 )
{
T_12 * V_161 ;
if ( ( V_6 >= V_162 ) || ( V_6 < V_163 ) )
return - V_28 ;
V_6 -= V_163 ;
V_161 = & V_164 [ F_87 ( V_6 ) ] . V_165 [ F_88 ( V_6 ) ] ;
if ( V_161 -> V_166 && ( V_161 -> V_167 <= V_6 ) && ( V_161 -> V_168 > V_6 ) ) {
* V_1 = V_5 -> V_21 . V_169 + V_161 -> V_170 +
( V_6 - V_161 -> V_167 ) ;
return 0 ;
}
* V_1 = V_5 -> V_21 . V_169 + V_171 +
( V_6 & F_89 ( 16 ) ) ;
return 1 ;
}
static void
F_90 ( struct V_4 * V_5 , T_11 V_6 )
{
V_3 V_154 ;
void T_2 * V_1 = V_5 -> V_21 . V_169 + V_172 ;
V_6 -= V_163 ;
V_154 = F_91 ( V_6 ) ;
F_4 ( V_154 , V_1 ) ;
if ( F_2 ( V_1 ) != V_154 ) {
if ( F_83 () )
F_84 ( & V_5 -> V_158 -> V_159 ,
L_14 ,
V_154 , V_6 ) ;
}
}
static void T_2 *
F_92 ( struct V_4 * V_5 ,
T_11 V_173 , void T_2 * * V_174 )
{
T_11 V_6 = V_173 ;
void T_2 * V_1 ;
T_13 V_175 ;
if ( F_93 ( V_173 ) )
V_6 = F_94 ( V_173 ) ;
V_1 = F_5 ( V_5 , V_6 ) ;
if ( V_1 )
return V_1 ;
if ( V_5 -> V_21 . V_176 == 0 )
V_6 -= V_163 ;
V_175 = F_95 ( V_5 -> V_158 , 0 ) ;
* V_174 = F_96 ( V_175 + ( V_6 & V_177 ) , V_178 ) ;
if ( * V_174 )
V_1 = * V_174 + ( V_6 & ( V_178 - 1 ) ) ;
return V_1 ;
}
static int
F_97 ( struct V_4 * V_5 , T_11 V_6 , V_3 V_179 )
{
unsigned long V_58 ;
void T_2 * V_1 , * V_174 = NULL ;
V_1 = F_92 ( V_5 , V_6 , & V_174 ) ;
if ( ! V_1 )
return - V_18 ;
if ( F_93 ( V_6 ) ) {
F_98 ( V_5 , V_1 , V_179 ) ;
} else {
F_99 ( & V_5 -> V_21 . V_180 , V_58 ) ;
F_80 ( V_5 , 0 ) ;
F_4 ( V_179 , V_1 ) ;
F_80 ( V_5 ,
V_160 ) ;
F_100 ( & V_5 -> V_21 . V_180 , V_58 ) ;
}
if ( V_174 )
F_101 ( V_174 ) ;
return 0 ;
}
static V_3
F_102 ( struct V_4 * V_5 , T_11 V_6 )
{
unsigned long V_58 ;
void T_2 * V_1 , * V_174 = NULL ;
V_3 V_179 ;
V_1 = F_92 ( V_5 , V_6 , & V_174 ) ;
if ( ! V_1 )
return - V_18 ;
if ( F_93 ( V_6 ) ) {
V_179 = F_103 ( V_5 , V_1 ) ;
} else {
F_99 ( & V_5 -> V_21 . V_180 , V_58 ) ;
F_80 ( V_5 , 0 ) ;
V_179 = F_2 ( V_1 ) ;
F_80 ( V_5 ,
V_160 ) ;
F_100 ( & V_5 -> V_21 . V_180 , V_58 ) ;
}
if ( V_174 )
F_101 ( V_174 ) ;
return V_179 ;
}
static int
F_104 ( struct V_4 * V_5 , T_11 V_6 , V_3 V_179 )
{
unsigned long V_58 ;
int V_115 ;
void T_2 * V_1 = NULL ;
V_115 = F_86 ( V_5 , V_6 , & V_1 ) ;
if ( V_115 == 0 ) {
F_4 ( V_179 , V_1 ) ;
return 0 ;
}
if ( V_115 > 0 ) {
F_99 ( & V_5 -> V_21 . V_180 , V_58 ) ;
F_105 ( V_5 ) ;
F_90 ( V_5 , V_6 ) ;
F_4 ( V_179 , V_1 ) ;
F_106 ( V_5 ) ;
F_100 ( & V_5 -> V_21 . V_180 , V_58 ) ;
return 0 ;
}
F_107 ( & V_5 -> V_158 -> V_159 ,
L_15 , V_181 , V_6 ) ;
F_108 () ;
return - V_18 ;
}
static V_3
F_109 ( struct V_4 * V_5 , T_11 V_6 )
{
unsigned long V_58 ;
int V_115 ;
V_3 V_179 ;
void T_2 * V_1 = NULL ;
V_115 = F_86 ( V_5 , V_6 , & V_1 ) ;
if ( V_115 == 0 )
return F_2 ( V_1 ) ;
if ( V_115 > 0 ) {
F_99 ( & V_5 -> V_21 . V_180 , V_58 ) ;
F_105 ( V_5 ) ;
F_90 ( V_5 , V_6 ) ;
V_179 = F_2 ( V_1 ) ;
F_106 ( V_5 ) ;
F_100 ( & V_5 -> V_21 . V_180 , V_58 ) ;
return V_179 ;
}
F_107 ( & V_5 -> V_158 -> V_159 ,
L_15 , V_181 , V_6 ) ;
F_108 () ;
return - 1 ;
}
static void F_98 ( struct V_4 * V_5 ,
void T_2 * V_1 , V_3 V_179 )
{
F_110 ( & V_5 -> V_21 . V_180 ) ;
F_4 ( V_179 , V_1 ) ;
F_111 ( & V_5 -> V_21 . V_180 ) ;
}
static V_3 F_103 ( struct V_4 * V_5 ,
void T_2 * V_1 )
{
V_3 V_2 ;
F_110 ( & V_5 -> V_21 . V_180 ) ;
V_2 = F_2 ( V_1 ) ;
F_111 ( & V_5 -> V_21 . V_180 ) ;
return V_2 ;
}
static void F_112 ( struct V_4 * V_5 ,
void T_2 * V_1 , V_3 V_179 )
{
F_4 ( V_179 , V_1 ) ;
}
static V_3 F_113 ( struct V_4 * V_5 ,
void T_2 * V_1 )
{
return F_2 ( V_1 ) ;
}
void T_2 *
F_114 ( struct V_4 * V_5 , V_3 V_148 )
{
void T_2 * V_1 = NULL ;
if ( F_19 ( V_5 -> V_21 . V_22 ) ) {
if ( ( V_148 < V_182 ) &&
( V_148 > V_183 ) )
V_1 = F_8 ( V_5 , V_148 ) ;
else
V_1 = F_115 ( V_5 , V_148 ) ;
} else {
F_116 ( F_86 ( V_5 ,
V_148 , & V_1 ) ) ;
}
return V_1 ;
}
static int
F_117 ( struct V_4 * V_5 ,
T_1 V_1 , V_3 * V_184 )
{
if ( F_6 ( V_1 , V_185 , V_186 ) ) {
* V_184 = ( V_1 - V_185 + V_187 ) ;
return 0 ;
} else if ( F_6 ( V_1 ,
V_188 , V_189 ) ) {
* V_184 = ( V_1 - V_188 + V_190 ) ;
return 0 ;
}
return - V_18 ;
}
static int
F_118 ( struct V_4 * V_5 ,
T_1 V_1 , V_3 * V_184 )
{
V_3 V_154 ;
V_154 = F_119 ( V_1 ) ;
F_4 ( V_154 , V_5 -> V_21 . V_191 ) ;
F_2 ( V_5 -> V_21 . V_191 ) ;
V_5 -> V_21 . V_192 = V_154 ;
* V_184 = V_193 + F_120 ( V_1 ) ;
return 0 ;
}
static int
F_121 ( struct V_4 * V_5 , T_1 V_6 ,
T_1 * V_179 , int V_85 )
{
void T_2 * V_1 , * V_174 = NULL ;
T_13 V_175 ;
int V_194 ;
V_3 V_184 ;
F_122 ( & V_5 -> V_21 . V_195 ) ;
V_194 = V_5 -> V_196 ( V_5 , V_6 , & V_184 ) ;
if ( V_194 != 0 )
goto V_197;
if ( F_21 ( V_5 -> V_21 . V_22 ) ) {
V_1 = V_5 -> V_21 . V_169 + V_184 ;
} else {
V_1 = F_5 ( V_5 , V_184 ) ;
if ( V_1 )
goto V_198;
V_175 = F_95 ( V_5 -> V_158 , 0 ) +
( V_184 & V_177 ) ;
V_174 = F_96 ( V_175 , V_178 ) ;
if ( V_174 == NULL ) {
V_194 = - V_18 ;
goto V_197;
}
V_1 = V_174 + ( V_184 & ( V_178 - 1 ) ) ;
}
V_198:
if ( V_85 == 0 )
* V_179 = F_1 ( V_1 ) ;
else
F_3 ( * V_179 , V_1 ) ;
V_197:
F_123 ( & V_5 -> V_21 . V_195 ) ;
if ( V_174 )
F_101 ( V_174 ) ;
return V_194 ;
}
void
F_124 ( struct V_4 * V_5 , T_1 V_6 , T_1 * V_179 )
{
void T_2 * V_1 = V_5 -> V_21 . V_169 +
V_199 + ( V_6 - V_200 ) ;
F_122 ( & V_5 -> V_21 . V_195 ) ;
* V_179 = F_1 ( V_1 ) ;
F_123 ( & V_5 -> V_21 . V_195 ) ;
}
void
F_125 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_179 )
{
void T_2 * V_1 = V_5 -> V_21 . V_169 +
V_199 + ( V_6 - V_200 ) ;
F_122 ( & V_5 -> V_21 . V_195 ) ;
F_3 ( V_179 , V_1 ) ;
F_123 ( & V_5 -> V_21 . V_195 ) ;
}
static int
F_126 ( struct V_4 * V_5 ,
T_1 V_6 , T_1 V_179 )
{
int V_201 , V_194 ;
V_3 V_202 , V_203 , V_204 , V_205 , V_206 , V_207 ;
void T_2 * V_208 ;
if ( V_6 & 7 )
return - V_18 ;
if ( F_6 ( V_6 , V_209 ,
V_210 ) ) {
V_208 = F_5 ( V_5 ,
V_211 + V_212 ) ;
V_205 = V_213 ;
V_207 = V_214 ;
V_206 = V_215 ;
V_203 = V_6 & V_216 ;
V_204 = F_127 ( V_6 ) ;
goto V_217;
}
if ( F_6 ( V_6 , V_218 , V_219 ) ) {
V_208 = F_5 ( V_5 ,
V_220 + V_221 ) ;
V_205 = V_222 ;
V_207 = V_223 ;
V_206 = V_224 ;
V_203 = V_6 & V_225 ;
V_204 = 0 ;
goto V_217;
}
if ( F_6 ( V_6 , V_185 , V_186 ) ||
F_6 ( V_6 , V_188 , V_189 ) ) {
if ( V_5 -> V_21 . V_176 != 0 ) {
return F_121 ( V_5 ,
V_6 , & V_179 , 1 ) ;
}
}
return - V_18 ;
V_217:
F_122 ( & V_5 -> V_21 . V_195 ) ;
F_80 ( V_5 , 0 ) ;
F_4 ( V_203 , ( V_208 + V_226 ) ) ;
F_4 ( V_204 , ( V_208 + V_205 ) ) ;
F_4 ( V_179 & 0xffffffff , ( V_208 + V_207 ) ) ;
F_4 ( ( V_179 >> 32 ) & 0xffffffff , ( V_208 + V_206 ) ) ;
F_4 ( ( V_227 | V_228 ) , ( V_208 + V_229 ) ) ;
F_4 ( ( V_230 | V_227 | V_228 ) ,
( V_208 + V_229 ) ) ;
for ( V_201 = 0 ; V_201 < V_231 ; V_201 ++ ) {
V_202 = F_2 ( ( V_208 + V_229 ) ) ;
if ( ( V_202 & V_232 ) == 0 )
break;
}
if ( V_201 >= V_231 ) {
if ( F_83 () )
F_107 ( & V_5 -> V_158 -> V_159 ,
L_16 ) ;
V_194 = - V_18 ;
} else
V_194 = 0 ;
F_80 ( V_5 , V_160 ) ;
F_123 ( & V_5 -> V_21 . V_195 ) ;
return V_194 ;
}
static int
F_128 ( struct V_4 * V_5 ,
T_1 V_6 , T_1 * V_179 )
{
int V_201 , V_194 ;
V_3 V_202 , V_203 , V_204 , V_205 , V_206 , V_207 ;
T_1 V_2 ;
void T_2 * V_208 ;
if ( V_6 & 7 )
return - V_18 ;
if ( F_6 ( V_6 , V_209 ,
V_210 ) ) {
V_208 = F_5 ( V_5 ,
V_211 + V_212 ) ;
V_205 = V_213 ;
V_207 = V_233 ;
V_206 = V_234 ;
V_203 = V_6 & V_216 ;
V_204 = F_127 ( V_6 ) ;
goto V_217;
}
if ( F_6 ( V_6 , V_218 , V_219 ) ) {
V_208 = F_5 ( V_5 ,
V_220 + V_221 ) ;
V_205 = V_222 ;
V_207 = V_235 ;
V_206 = V_236 ;
V_203 = V_6 & V_225 ;
V_204 = 0 ;
goto V_217;
}
if ( F_6 ( V_6 , V_185 , V_186 ) ||
F_6 ( V_6 , V_188 , V_189 ) ) {
if ( V_5 -> V_21 . V_176 != 0 ) {
return F_121 ( V_5 ,
V_6 , V_179 , 0 ) ;
}
}
return - V_18 ;
V_217:
F_122 ( & V_5 -> V_21 . V_195 ) ;
F_80 ( V_5 , 0 ) ;
F_4 ( V_203 , ( V_208 + V_226 ) ) ;
F_4 ( V_204 , ( V_208 + V_205 ) ) ;
F_4 ( V_227 , ( V_208 + V_229 ) ) ;
F_4 ( ( V_230 | V_227 ) , ( V_208 + V_229 ) ) ;
for ( V_201 = 0 ; V_201 < V_231 ; V_201 ++ ) {
V_202 = F_2 ( V_208 + V_229 ) ;
if ( ( V_202 & V_232 ) == 0 )
break;
}
if ( V_201 >= V_231 ) {
if ( F_83 () )
F_107 ( & V_5 -> V_158 -> V_159 ,
L_17 ) ;
V_194 = - V_18 ;
} else {
V_202 = F_2 ( V_208 + V_206 ) ;
V_2 = ( ( T_1 ) V_202 << 32 ) ;
V_2 |= F_2 ( V_208 + V_207 ) ;
* V_179 = V_2 ;
V_194 = 0 ;
}
F_80 ( V_5 , V_160 ) ;
F_123 ( & V_5 -> V_21 . V_195 ) ;
return V_194 ;
}
static int
F_129 ( struct V_4 * V_5 ,
T_1 V_6 , T_1 V_179 )
{
int V_201 , V_194 ;
V_3 V_202 , V_237 ;
void T_2 * V_208 ;
if ( V_6 & 7 )
return - V_18 ;
if ( F_6 ( V_6 , V_209 ,
V_238 ) ) {
V_208 = F_114 ( V_5 ,
V_211 + V_221 ) ;
goto V_217;
}
if ( F_6 ( V_6 , V_218 , V_219 ) ) {
V_208 = F_114 ( V_5 ,
V_220 + V_221 ) ;
goto V_217;
}
if ( F_6 ( V_6 , V_185 , V_186 ) )
return F_121 ( V_5 , V_6 , & V_179 , 1 ) ;
return - V_18 ;
V_217:
V_237 = V_6 & 0xfffffff8 ;
F_122 ( & V_5 -> V_21 . V_195 ) ;
F_4 ( V_237 , ( V_208 + V_226 ) ) ;
F_4 ( 0 , ( V_208 + V_222 ) ) ;
F_4 ( V_179 & 0xffffffff ,
V_208 + V_223 ) ;
F_4 ( ( V_179 >> 32 ) & 0xffffffff ,
V_208 + V_224 ) ;
F_4 ( ( V_227 | V_228 ) , ( V_208 + V_229 ) ) ;
F_4 ( ( V_230 | V_227 | V_228 ) ,
( V_208 + V_229 ) ) ;
for ( V_201 = 0 ; V_201 < V_231 ; V_201 ++ ) {
V_202 = F_2 ( V_208 + V_229 ) ;
if ( ( V_202 & V_232 ) == 0 )
break;
}
if ( V_201 >= V_231 ) {
if ( F_83 () )
F_107 ( & V_5 -> V_158 -> V_159 ,
L_16 ) ;
V_194 = - V_18 ;
} else
V_194 = 0 ;
F_123 ( & V_5 -> V_21 . V_195 ) ;
return V_194 ;
}
static int
F_130 ( struct V_4 * V_5 ,
T_1 V_6 , T_1 * V_179 )
{
int V_201 , V_194 ;
V_3 V_202 , V_237 ;
T_1 V_2 ;
void T_2 * V_208 ;
if ( V_6 & 7 )
return - V_18 ;
if ( F_6 ( V_6 , V_209 ,
V_238 ) ) {
V_208 = F_114 ( V_5 ,
V_211 + V_221 ) ;
goto V_217;
}
if ( F_6 ( V_6 , V_218 , V_219 ) ) {
V_208 = F_114 ( V_5 ,
V_220 + V_221 ) ;
goto V_217;
}
if ( F_6 ( V_6 , V_185 , V_186 ) ) {
return F_121 ( V_5 ,
V_6 , V_179 , 0 ) ;
}
return - V_18 ;
V_217:
V_237 = V_6 & 0xfffffff8 ;
F_122 ( & V_5 -> V_21 . V_195 ) ;
F_4 ( V_237 , ( V_208 + V_226 ) ) ;
F_4 ( 0 , ( V_208 + V_222 ) ) ;
F_4 ( V_227 , ( V_208 + V_229 ) ) ;
F_4 ( ( V_230 | V_227 ) , ( V_208 + V_229 ) ) ;
for ( V_201 = 0 ; V_201 < V_231 ; V_201 ++ ) {
V_202 = F_2 ( V_208 + V_229 ) ;
if ( ( V_202 & V_232 ) == 0 )
break;
}
if ( V_201 >= V_231 ) {
if ( F_83 () )
F_107 ( & V_5 -> V_158 -> V_159 ,
L_17 ) ;
V_194 = - V_18 ;
} else {
V_2 = ( T_1 ) ( F_2 ( V_208 + V_236 ) ) << 32 ;
V_2 |= F_2 ( V_208 + V_235 ) ;
* V_179 = V_2 ;
V_194 = 0 ;
}
F_123 ( & V_5 -> V_21 . V_195 ) ;
return V_194 ;
}
void
F_131 ( struct V_4 * V_5 )
{
V_5 -> V_239 = F_18 ;
V_5 -> V_240 = F_20 ;
if ( F_19 ( V_5 -> V_21 . V_22 ) ) {
V_5 -> V_241 = F_102 ,
V_5 -> V_242 = F_97 ,
V_5 -> V_196 = F_117 ,
V_5 -> V_243 = F_128 ,
V_5 -> V_244 = F_126 ,
V_5 -> V_245 = F_103 ,
V_5 -> V_246 = F_98 ,
V_5 -> V_247 = F_24 ;
V_5 -> V_248 = F_32 ;
V_5 -> V_139 = V_249 ;
V_5 -> V_60 = F_22 ;
} else {
V_5 -> V_241 = F_109 ,
V_5 -> V_242 = F_104 ,
V_5 -> V_196 = F_118 ,
V_5 -> V_243 = F_130 ,
V_5 -> V_244 = F_129 ,
V_5 -> V_245 = F_113 ,
V_5 -> V_246 = F_112 ,
V_5 -> V_139 = V_250 ;
V_5 -> V_60 = F_61 ;
V_5 -> V_247 = F_63 ;
V_5 -> V_248 = F_55 ;
V_5 -> V_251 = V_252 ;
V_5 -> V_253 = V_254 ;
}
}
int F_132 ( struct V_4 * V_5 )
{
int V_148 , V_32 , V_255 ;
struct V_256 * V_158 = V_5 -> V_158 ;
V_148 = V_257 ;
if ( F_75 ( V_5 , V_148 , & V_255 ) )
return - V_18 ;
if ( V_255 != V_258 ) {
F_107 ( & V_158 -> V_159 , L_18 ,
V_255 ) ;
return - V_18 ;
}
V_148 = V_259 ;
if ( F_75 ( V_5 , V_148 , & V_32 ) )
return - V_18 ;
if ( V_32 == V_260 ) {
V_3 V_261 = F_11 ( V_5 , V_262 ) ;
if ( ( V_261 & 0x8000 ) == 0 )
V_32 = V_263 ;
}
V_5 -> V_21 . V_32 = V_32 ;
switch ( V_32 ) {
case V_264 :
V_5 -> V_21 . V_265 = V_266 ;
break;
case V_267 :
case V_33 :
case V_34 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
case V_277 :
case V_278 :
V_5 -> V_21 . V_265 = V_279 ;
break;
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_260 :
V_5 -> V_21 . V_265 = V_266 ;
break;
case V_263 :
V_5 -> V_21 . V_265 = ( V_5 -> V_19 < 2 ) ?
V_279 : V_266 ;
break;
default:
F_107 ( & V_158 -> V_159 , L_19 , V_32 ) ;
V_5 -> V_21 . V_265 = V_279 ;
break;
}
return 0 ;
}
static int V_249 ( struct V_4 * V_5 , int V_286 )
{
V_286 += V_287 ;
if ( V_5 -> V_26 == 0 )
F_15 ( V_5 , V_288 , V_286 ) ;
else
F_15 ( V_5 , V_289 , V_286 ) ;
return 0 ;
}
void F_133 ( struct V_4 * V_5 )
{
T_3 V_290 ;
T_3 V_291 ;
T_3 V_292 ;
if ( ! F_134 ( V_5 -> V_53 ) ) {
V_5 -> V_293 = 0 ;
V_5 -> V_294 = - 1 ;
V_5 -> V_295 = V_296 ;
return;
}
if ( V_5 -> V_21 . V_265 == V_266 ) {
V_292 = F_11 ( V_5 , V_297 ) ;
if ( V_292 == V_298 ) {
V_5 -> V_293 = V_299 ;
V_5 -> V_294 = V_300 ;
V_5 -> V_295 = V_301 ;
return;
}
if ( V_5 -> V_251 &&
V_5 -> V_251 ( V_5 ,
V_302 ,
& V_290 ) == 0 ) {
if ( F_135 ( V_290 ) ) {
switch ( F_136 ( V_290 ) ) {
case 0 :
V_5 -> V_293 = V_303 ;
break;
case 1 :
V_5 -> V_293 = V_304 ;
break;
case 2 :
V_5 -> V_293 = V_299 ;
break;
default:
V_5 -> V_293 = 0 ;
break;
}
switch ( F_137 ( V_290 ) ) {
case 0 :
V_5 -> V_294 = V_305 ;
break;
case 1 :
V_5 -> V_294 = V_300 ;
break;
default:
V_5 -> V_294 = - 1 ;
break;
}
if ( V_5 -> V_251 &&
V_5 -> V_251 ( V_5 ,
V_306 ,
& V_291 ) != 0 )
V_5 -> V_295 = V_291 ;
} else
goto V_307;
} else {
V_307:
V_5 -> V_293 = 0 ;
V_5 -> V_294 = - 1 ;
}
}
}
int
F_138 ( struct V_4 * V_5 )
{
V_3 V_308 ;
if ( F_19 ( V_5 -> V_21 . V_22 ) )
return 0 ;
V_308 = F_11 ( V_5 , V_309 ) ;
if ( V_308 & ( 1UL << V_5 -> V_19 ) ) {
V_308 = F_11 ( V_5 , V_310 ) ;
if ( V_308 & ( 1 << V_5 -> V_19 ) )
return 1 ;
}
return 0 ;
}
