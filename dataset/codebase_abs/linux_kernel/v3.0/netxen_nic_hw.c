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
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 = V_119 | ( ( T_1 ) V_5 -> V_19 << 16 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_86 . V_93 [ 0 ] = F_47 ( V_118 ) ;
V_115 = F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
if ( V_115 != 0 ) {
F_53 ( V_102 L_2
L_4 ) ;
}
return V_115 ;
}
int F_66 ( struct V_4 * V_5 , int V_118 )
{
T_6 V_86 ;
T_1 V_88 ;
int V_115 = 0 ;
if ( ! ! ( V_5 -> V_58 & V_120 ) == V_118 )
return V_115 ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 = V_121 |
( ( T_1 ) V_5 -> V_19 << 16 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_86 . V_93 [ 0 ] = F_47 ( V_118 ) ;
V_115 = F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
if ( V_115 != 0 ) {
F_53 ( V_102 L_2
L_5 ) ;
}
V_5 -> V_58 ^= V_120 ;
return V_115 ;
}
int F_67 ( struct V_4 * V_5 , int V_118 )
{
T_6 V_86 ;
T_1 V_88 ;
int V_57 , V_115 ;
static const T_1 V_122 [] = {
0xbeac01fa6a42b73bULL , 0x8030f20c77cb2da3ULL ,
0xae7b30b4d0ca2bcbULL , 0x43a38fb04167253dULL ,
0x255b0ec26d5a56daULL
} ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 = V_123 | ( ( T_1 ) V_5 -> V_19 << 16 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_88 = ( ( T_1 ) ( V_124 & 0x3 ) << 4 ) |
( ( T_1 ) ( V_124 & 0x3 ) << 6 ) |
( ( T_1 ) ( V_118 & 0x1 ) << 8 ) |
( ( 0x7ULL ) << 48 ) ;
V_86 . V_93 [ 0 ] = F_47 ( V_88 ) ;
for ( V_57 = 0 ; V_57 < F_68 ( V_122 ) ; V_57 ++ )
V_86 . V_93 [ V_57 + 1 ] = F_47 ( V_122 [ V_57 ] ) ;
V_115 = F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
if ( V_115 != 0 ) {
F_53 ( V_102 L_6 ,
V_5 -> V_53 -> V_103 ) ;
}
return V_115 ;
}
int F_69 ( struct V_4 * V_5 , V_3 V_125 , int V_126 )
{
T_6 V_86 ;
T_1 V_88 ;
int V_115 ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 = V_127 | ( ( T_1 ) V_5 -> V_19 << 16 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_86 . V_93 [ 0 ] = F_47 ( V_126 ) ;
V_86 . V_93 [ 1 ] = F_47 ( V_125 ) ;
V_115 = F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
if ( V_115 != 0 ) {
F_53 ( V_102 L_7 ,
V_5 -> V_53 -> V_103 ,
( V_126 == V_128 ) ? L_8 : L_9 , V_125 ) ;
}
return V_115 ;
}
int F_70 ( struct V_4 * V_5 , int V_118 )
{
T_6 V_86 ;
T_1 V_88 ;
int V_115 ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 = V_129 | ( ( T_1 ) V_5 -> V_19 << 16 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_86 . V_93 [ 0 ] = F_47 ( V_118 | ( V_118 << 8 ) ) ;
V_115 = F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
if ( V_115 != 0 ) {
F_53 ( V_102 L_10 ,
V_5 -> V_53 -> V_103 ) ;
}
return V_115 ;
}
int F_71 ( struct V_4 * V_5 )
{
T_6 V_86 ;
T_1 V_88 ;
int V_115 ;
memset ( & V_86 , 0 , sizeof( T_6 ) ) ;
V_86 . V_89 = F_47 ( V_113 << 23 ) ;
V_88 = V_130 |
( ( T_1 ) V_5 -> V_19 << 16 ) |
( ( T_1 ) V_131 << 56 ) ;
V_86 . V_92 = F_47 ( V_88 ) ;
V_115 = F_37 ( V_5 , (struct V_64 * ) & V_86 , 1 ) ;
if ( V_115 != 0 ) {
F_53 ( V_102 L_11 ,
V_5 -> V_53 -> V_103 ) ;
}
return V_115 ;
}
int F_72 ( struct V_52 * V_53 , int V_132 )
{
struct V_4 * V_5 = F_33 ( V_53 ) ;
int V_133 ;
int V_134 = 0 ;
if ( F_21 ( V_5 -> V_21 . V_22 ) )
V_133 = V_135 ;
else
V_133 = V_136 ;
if ( V_132 > V_133 ) {
F_53 ( V_102 L_12 ,
V_53 -> V_103 , V_133 ) ;
return - V_28 ;
}
if ( V_5 -> V_137 )
V_134 = V_5 -> V_137 ( V_5 , V_132 ) ;
if ( ! V_134 )
V_53 -> V_132 = V_132 ;
return V_134 ;
}
static int F_73 ( struct V_4 * V_5 , int V_138 ,
int V_139 , T_9 * V_140 )
{
int V_57 , V_141 , V_1 ;
T_9 * V_142 ;
V_1 = V_138 ;
V_142 = V_140 ;
for ( V_57 = 0 ; V_57 < V_139 / sizeof( V_3 ) ; V_57 ++ ) {
if ( F_74 ( V_5 , V_1 , & V_141 ) == - 1 )
return - 1 ;
* V_142 = F_75 ( V_141 ) ;
V_142 ++ ;
V_1 += sizeof( V_3 ) ;
}
if ( ( char * ) V_140 + V_139 > ( char * ) V_142 ) {
T_9 V_143 ;
if ( F_74 ( V_5 , V_1 , & V_141 ) == - 1 )
return - 1 ;
V_143 = F_75 ( V_141 ) ;
memcpy ( V_142 , & V_143 , ( char * ) V_140 + V_139 - ( char * ) V_142 ) ;
}
return 0 ;
}
int F_76 ( struct V_4 * V_5 , T_1 * V_144 )
{
T_9 * V_145 = ( T_9 * ) V_144 ;
V_3 V_146 ;
V_146 = V_147 + ( V_5 -> V_19 * sizeof( T_1 ) ) ;
if ( F_73 ( V_5 , V_146 , sizeof( T_1 ) , V_145 ) == - 1 )
return - 1 ;
if ( * V_144 == F_47 ( ~ 0ULL ) ) {
V_146 = V_148 +
( V_5 -> V_19 * sizeof( T_1 ) ) ;
if ( F_73 ( V_5 ,
V_146 , sizeof( T_1 ) , V_145 ) == - 1 )
return - 1 ;
if ( * V_144 == F_47 ( ~ 0ULL ) )
return - 1 ;
}
return 0 ;
}
int F_77 ( struct V_4 * V_5 , T_1 * V_144 )
{
T_10 V_149 , V_39 , V_40 ;
int V_150 = V_5 -> V_21 . V_150 ;
V_149 = V_151 +
( 4 * ( ( V_150 / 2 ) * 3 ) ) + ( 4 * ( V_150 & 1 ) ) ;
V_40 = F_11 ( V_5 , V_149 ) ;
V_39 = F_11 ( V_5 , V_149 + 4 ) ;
if ( V_150 & 1 )
* V_144 = F_78 ( ( V_40 >> 16 ) | ( ( T_1 ) V_39 << 16 ) ) ;
else
* V_144 = F_78 ( ( T_1 ) V_40 | ( ( T_1 ) V_39 << 32 ) ) ;
return 0 ;
}
static void
F_79 ( struct V_4 * V_5 ,
V_3 V_152 )
{
void T_2 * V_146 ;
int V_153 = 10 ;
T_5 V_154 = V_5 -> V_21 . V_150 ;
if ( V_5 -> V_21 . V_155 == V_152 )
return;
V_146 = F_8 ( V_5 ,
F_80 ( F_81 ( V_154 ) ) ) ;
F_4 ( V_152 , V_146 ) ;
do {
if ( V_152 == F_2 ( V_146 ) )
break;
if ( F_82 () )
F_83 ( & V_5 -> V_156 -> V_157 ,
L_13 ,
( V_152 == V_158 ) ) ;
F_84 ( 1 ) ;
} while ( -- V_153 > 0 );
if ( V_153 > 0 )
V_5 -> V_21 . V_155 = V_152 ;
}
static int
F_85 ( struct V_4 * V_5 ,
T_11 V_6 , void T_2 * * V_1 )
{
T_12 * V_159 ;
if ( ( V_6 >= V_160 ) || ( V_6 < V_161 ) )
return - V_28 ;
V_6 -= V_161 ;
V_159 = & V_162 [ F_86 ( V_6 ) ] . V_163 [ F_87 ( V_6 ) ] ;
if ( V_159 -> V_164 && ( V_159 -> V_165 <= V_6 ) && ( V_159 -> V_166 > V_6 ) ) {
* V_1 = V_5 -> V_21 . V_167 + V_159 -> V_168 +
( V_6 - V_159 -> V_165 ) ;
return 0 ;
}
* V_1 = V_5 -> V_21 . V_167 + V_169 +
( V_6 & F_88 ( 16 ) ) ;
return 1 ;
}
static void
F_89 ( struct V_4 * V_5 , T_11 V_6 )
{
V_3 V_152 ;
void T_2 * V_1 = V_5 -> V_21 . V_167 + V_170 ;
V_6 -= V_161 ;
V_152 = F_90 ( V_6 ) ;
F_4 ( V_152 , V_1 ) ;
if ( F_2 ( V_1 ) != V_152 ) {
if ( F_82 () )
F_83 ( & V_5 -> V_156 -> V_157 ,
L_14 ,
V_152 , V_6 ) ;
}
}
static void T_2 *
F_91 ( struct V_4 * V_5 ,
T_11 V_171 , void T_2 * * V_172 )
{
T_11 V_6 = V_171 ;
void T_2 * V_1 ;
T_13 V_173 ;
if ( F_92 ( V_171 ) )
V_6 = F_93 ( V_171 ) ;
V_1 = F_5 ( V_5 , V_6 ) ;
if ( V_1 )
return V_1 ;
if ( V_5 -> V_21 . V_174 == 0 )
V_6 -= V_161 ;
V_173 = F_94 ( V_5 -> V_156 , 0 ) ;
* V_172 = F_95 ( V_173 + ( V_6 & V_175 ) , V_176 ) ;
if ( * V_172 )
V_1 = * V_172 + ( V_6 & ( V_176 - 1 ) ) ;
return V_1 ;
}
static int
F_96 ( struct V_4 * V_5 , T_11 V_6 , V_3 V_177 )
{
unsigned long V_58 ;
void T_2 * V_1 , * V_172 = NULL ;
V_1 = F_91 ( V_5 , V_6 , & V_172 ) ;
if ( ! V_1 )
return - V_18 ;
if ( F_92 ( V_6 ) ) {
F_97 ( V_5 , V_1 , V_177 ) ;
} else {
F_98 ( & V_5 -> V_21 . V_178 , V_58 ) ;
F_79 ( V_5 , 0 ) ;
F_4 ( V_177 , V_1 ) ;
F_79 ( V_5 ,
V_158 ) ;
F_99 ( & V_5 -> V_21 . V_178 , V_58 ) ;
}
if ( V_172 )
F_100 ( V_172 ) ;
return 0 ;
}
static V_3
F_101 ( struct V_4 * V_5 , T_11 V_6 )
{
unsigned long V_58 ;
void T_2 * V_1 , * V_172 = NULL ;
V_3 V_177 ;
V_1 = F_91 ( V_5 , V_6 , & V_172 ) ;
if ( ! V_1 )
return - V_18 ;
if ( F_92 ( V_6 ) ) {
V_177 = F_102 ( V_5 , V_1 ) ;
} else {
F_98 ( & V_5 -> V_21 . V_178 , V_58 ) ;
F_79 ( V_5 , 0 ) ;
V_177 = F_2 ( V_1 ) ;
F_79 ( V_5 ,
V_158 ) ;
F_99 ( & V_5 -> V_21 . V_178 , V_58 ) ;
}
if ( V_172 )
F_100 ( V_172 ) ;
return V_177 ;
}
static int
F_103 ( struct V_4 * V_5 , T_11 V_6 , V_3 V_177 )
{
unsigned long V_58 ;
int V_115 ;
void T_2 * V_1 = NULL ;
V_115 = F_85 ( V_5 , V_6 , & V_1 ) ;
if ( V_115 == 0 ) {
F_4 ( V_177 , V_1 ) ;
return 0 ;
}
if ( V_115 > 0 ) {
F_98 ( & V_5 -> V_21 . V_178 , V_58 ) ;
F_104 ( V_5 ) ;
F_89 ( V_5 , V_6 ) ;
F_4 ( V_177 , V_1 ) ;
F_105 ( V_5 ) ;
F_99 ( & V_5 -> V_21 . V_178 , V_58 ) ;
return 0 ;
}
F_106 ( & V_5 -> V_156 -> V_157 ,
L_15 , V_179 , V_6 ) ;
F_107 () ;
return - V_18 ;
}
static V_3
F_108 ( struct V_4 * V_5 , T_11 V_6 )
{
unsigned long V_58 ;
int V_115 ;
V_3 V_177 ;
void T_2 * V_1 = NULL ;
V_115 = F_85 ( V_5 , V_6 , & V_1 ) ;
if ( V_115 == 0 )
return F_2 ( V_1 ) ;
if ( V_115 > 0 ) {
F_98 ( & V_5 -> V_21 . V_178 , V_58 ) ;
F_104 ( V_5 ) ;
F_89 ( V_5 , V_6 ) ;
V_177 = F_2 ( V_1 ) ;
F_105 ( V_5 ) ;
F_99 ( & V_5 -> V_21 . V_178 , V_58 ) ;
return V_177 ;
}
F_106 ( & V_5 -> V_156 -> V_157 ,
L_15 , V_179 , V_6 ) ;
F_107 () ;
return - 1 ;
}
static void F_97 ( struct V_4 * V_5 ,
void T_2 * V_1 , V_3 V_177 )
{
F_109 ( & V_5 -> V_21 . V_178 ) ;
F_4 ( V_177 , V_1 ) ;
F_110 ( & V_5 -> V_21 . V_178 ) ;
}
static V_3 F_102 ( struct V_4 * V_5 ,
void T_2 * V_1 )
{
V_3 V_2 ;
F_109 ( & V_5 -> V_21 . V_178 ) ;
V_2 = F_2 ( V_1 ) ;
F_110 ( & V_5 -> V_21 . V_178 ) ;
return V_2 ;
}
static void F_111 ( struct V_4 * V_5 ,
void T_2 * V_1 , V_3 V_177 )
{
F_4 ( V_177 , V_1 ) ;
}
static V_3 F_112 ( struct V_4 * V_5 ,
void T_2 * V_1 )
{
return F_2 ( V_1 ) ;
}
void T_2 *
F_113 ( struct V_4 * V_5 , V_3 V_146 )
{
void T_2 * V_1 = NULL ;
if ( F_19 ( V_5 -> V_21 . V_22 ) ) {
if ( ( V_146 < V_180 ) &&
( V_146 > V_181 ) )
V_1 = F_8 ( V_5 , V_146 ) ;
else
V_1 = F_114 ( V_5 , V_146 ) ;
} else {
F_115 ( F_85 ( V_5 ,
V_146 , & V_1 ) ) ;
}
return V_1 ;
}
static int
F_116 ( struct V_4 * V_5 ,
T_1 V_1 , V_3 * V_182 )
{
if ( F_6 ( V_1 , V_183 , V_184 ) ) {
* V_182 = ( V_1 - V_183 + V_185 ) ;
return 0 ;
} else if ( F_6 ( V_1 ,
V_186 , V_187 ) ) {
* V_182 = ( V_1 - V_186 + V_188 ) ;
return 0 ;
}
return - V_18 ;
}
static int
F_117 ( struct V_4 * V_5 ,
T_1 V_1 , V_3 * V_182 )
{
V_3 V_152 ;
V_152 = F_118 ( V_1 ) ;
F_4 ( V_152 , V_5 -> V_21 . V_189 ) ;
F_2 ( V_5 -> V_21 . V_189 ) ;
V_5 -> V_21 . V_190 = V_152 ;
* V_182 = V_191 + F_119 ( V_1 ) ;
return 0 ;
}
static int
F_120 ( struct V_4 * V_5 , T_1 V_6 ,
T_1 * V_177 , int V_85 )
{
void T_2 * V_1 , * V_172 = NULL ;
T_13 V_173 ;
int V_192 ;
V_3 V_182 ;
F_121 ( & V_5 -> V_21 . V_193 ) ;
V_192 = V_5 -> V_194 ( V_5 , V_6 , & V_182 ) ;
if ( V_192 != 0 )
goto V_195;
if ( F_21 ( V_5 -> V_21 . V_22 ) ) {
V_1 = V_5 -> V_21 . V_167 + V_182 ;
} else {
V_1 = F_5 ( V_5 , V_182 ) ;
if ( V_1 )
goto V_196;
V_173 = F_94 ( V_5 -> V_156 , 0 ) +
( V_182 & V_175 ) ;
V_172 = F_95 ( V_173 , V_176 ) ;
if ( V_172 == NULL ) {
V_192 = - V_18 ;
goto V_195;
}
V_1 = V_172 + ( V_182 & ( V_176 - 1 ) ) ;
}
V_196:
if ( V_85 == 0 )
* V_177 = F_1 ( V_1 ) ;
else
F_3 ( * V_177 , V_1 ) ;
V_195:
F_122 ( & V_5 -> V_21 . V_193 ) ;
if ( V_172 )
F_100 ( V_172 ) ;
return V_192 ;
}
void
F_123 ( struct V_4 * V_5 , T_1 V_6 , T_1 * V_177 )
{
void T_2 * V_1 = V_5 -> V_21 . V_167 +
V_197 + ( V_6 - V_198 ) ;
F_121 ( & V_5 -> V_21 . V_193 ) ;
* V_177 = F_1 ( V_1 ) ;
F_122 ( & V_5 -> V_21 . V_193 ) ;
}
void
F_124 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_177 )
{
void T_2 * V_1 = V_5 -> V_21 . V_167 +
V_197 + ( V_6 - V_198 ) ;
F_121 ( & V_5 -> V_21 . V_193 ) ;
F_3 ( V_177 , V_1 ) ;
F_122 ( & V_5 -> V_21 . V_193 ) ;
}
static int
F_125 ( struct V_4 * V_5 ,
T_1 V_6 , T_1 V_177 )
{
int V_199 , V_192 ;
V_3 V_200 , V_201 , V_202 , V_203 , V_204 , V_205 ;
void T_2 * V_206 ;
if ( V_6 & 7 )
return - V_18 ;
if ( F_6 ( V_6 , V_207 ,
V_208 ) ) {
V_206 = F_5 ( V_5 ,
V_209 + V_210 ) ;
V_203 = V_211 ;
V_205 = V_212 ;
V_204 = V_213 ;
V_201 = V_6 & V_214 ;
V_202 = F_126 ( V_6 ) ;
goto V_215;
}
if ( F_6 ( V_6 , V_216 , V_217 ) ) {
V_206 = F_5 ( V_5 ,
V_218 + V_219 ) ;
V_203 = V_220 ;
V_205 = V_221 ;
V_204 = V_222 ;
V_201 = V_6 & V_223 ;
V_202 = 0 ;
goto V_215;
}
if ( F_6 ( V_6 , V_183 , V_184 ) ||
F_6 ( V_6 , V_186 , V_187 ) ) {
if ( V_5 -> V_21 . V_174 != 0 ) {
return F_120 ( V_5 ,
V_6 , & V_177 , 1 ) ;
}
}
return - V_18 ;
V_215:
F_121 ( & V_5 -> V_21 . V_193 ) ;
F_79 ( V_5 , 0 ) ;
F_4 ( V_201 , ( V_206 + V_224 ) ) ;
F_4 ( V_202 , ( V_206 + V_203 ) ) ;
F_4 ( V_177 & 0xffffffff , ( V_206 + V_205 ) ) ;
F_4 ( ( V_177 >> 32 ) & 0xffffffff , ( V_206 + V_204 ) ) ;
F_4 ( ( V_225 | V_226 ) , ( V_206 + V_227 ) ) ;
F_4 ( ( V_228 | V_225 | V_226 ) ,
( V_206 + V_227 ) ) ;
for ( V_199 = 0 ; V_199 < V_229 ; V_199 ++ ) {
V_200 = F_2 ( ( V_206 + V_227 ) ) ;
if ( ( V_200 & V_230 ) == 0 )
break;
}
if ( V_199 >= V_229 ) {
if ( F_82 () )
F_106 ( & V_5 -> V_156 -> V_157 ,
L_16 ) ;
V_192 = - V_18 ;
} else
V_192 = 0 ;
F_79 ( V_5 , V_158 ) ;
F_122 ( & V_5 -> V_21 . V_193 ) ;
return V_192 ;
}
static int
F_127 ( struct V_4 * V_5 ,
T_1 V_6 , T_1 * V_177 )
{
int V_199 , V_192 ;
V_3 V_200 , V_201 , V_202 , V_203 , V_204 , V_205 ;
T_1 V_2 ;
void T_2 * V_206 ;
if ( V_6 & 7 )
return - V_18 ;
if ( F_6 ( V_6 , V_207 ,
V_208 ) ) {
V_206 = F_5 ( V_5 ,
V_209 + V_210 ) ;
V_203 = V_211 ;
V_205 = V_231 ;
V_204 = V_232 ;
V_201 = V_6 & V_214 ;
V_202 = F_126 ( V_6 ) ;
goto V_215;
}
if ( F_6 ( V_6 , V_216 , V_217 ) ) {
V_206 = F_5 ( V_5 ,
V_218 + V_219 ) ;
V_203 = V_220 ;
V_205 = V_233 ;
V_204 = V_234 ;
V_201 = V_6 & V_223 ;
V_202 = 0 ;
goto V_215;
}
if ( F_6 ( V_6 , V_183 , V_184 ) ||
F_6 ( V_6 , V_186 , V_187 ) ) {
if ( V_5 -> V_21 . V_174 != 0 ) {
return F_120 ( V_5 ,
V_6 , V_177 , 0 ) ;
}
}
return - V_18 ;
V_215:
F_121 ( & V_5 -> V_21 . V_193 ) ;
F_79 ( V_5 , 0 ) ;
F_4 ( V_201 , ( V_206 + V_224 ) ) ;
F_4 ( V_202 , ( V_206 + V_203 ) ) ;
F_4 ( V_225 , ( V_206 + V_227 ) ) ;
F_4 ( ( V_228 | V_225 ) , ( V_206 + V_227 ) ) ;
for ( V_199 = 0 ; V_199 < V_229 ; V_199 ++ ) {
V_200 = F_2 ( V_206 + V_227 ) ;
if ( ( V_200 & V_230 ) == 0 )
break;
}
if ( V_199 >= V_229 ) {
if ( F_82 () )
F_106 ( & V_5 -> V_156 -> V_157 ,
L_17 ) ;
V_192 = - V_18 ;
} else {
V_200 = F_2 ( V_206 + V_204 ) ;
V_2 = ( ( T_1 ) V_200 << 32 ) ;
V_2 |= F_2 ( V_206 + V_205 ) ;
* V_177 = V_2 ;
V_192 = 0 ;
}
F_79 ( V_5 , V_158 ) ;
F_122 ( & V_5 -> V_21 . V_193 ) ;
return V_192 ;
}
static int
F_128 ( struct V_4 * V_5 ,
T_1 V_6 , T_1 V_177 )
{
int V_199 , V_192 ;
V_3 V_200 , V_235 ;
void T_2 * V_206 ;
if ( V_6 & 7 )
return - V_18 ;
if ( F_6 ( V_6 , V_207 ,
V_236 ) ) {
V_206 = F_113 ( V_5 ,
V_209 + V_219 ) ;
goto V_215;
}
if ( F_6 ( V_6 , V_216 , V_217 ) ) {
V_206 = F_113 ( V_5 ,
V_218 + V_219 ) ;
goto V_215;
}
if ( F_6 ( V_6 , V_183 , V_184 ) )
return F_120 ( V_5 , V_6 , & V_177 , 1 ) ;
return - V_18 ;
V_215:
V_235 = V_6 & 0xfffffff8 ;
F_121 ( & V_5 -> V_21 . V_193 ) ;
F_4 ( V_235 , ( V_206 + V_224 ) ) ;
F_4 ( 0 , ( V_206 + V_220 ) ) ;
F_4 ( V_177 & 0xffffffff ,
V_206 + V_221 ) ;
F_4 ( ( V_177 >> 32 ) & 0xffffffff ,
V_206 + V_222 ) ;
F_4 ( ( V_225 | V_226 ) , ( V_206 + V_227 ) ) ;
F_4 ( ( V_228 | V_225 | V_226 ) ,
( V_206 + V_227 ) ) ;
for ( V_199 = 0 ; V_199 < V_229 ; V_199 ++ ) {
V_200 = F_2 ( V_206 + V_227 ) ;
if ( ( V_200 & V_230 ) == 0 )
break;
}
if ( V_199 >= V_229 ) {
if ( F_82 () )
F_106 ( & V_5 -> V_156 -> V_157 ,
L_16 ) ;
V_192 = - V_18 ;
} else
V_192 = 0 ;
F_122 ( & V_5 -> V_21 . V_193 ) ;
return V_192 ;
}
static int
F_129 ( struct V_4 * V_5 ,
T_1 V_6 , T_1 * V_177 )
{
int V_199 , V_192 ;
V_3 V_200 , V_235 ;
T_1 V_2 ;
void T_2 * V_206 ;
if ( V_6 & 7 )
return - V_18 ;
if ( F_6 ( V_6 , V_207 ,
V_236 ) ) {
V_206 = F_113 ( V_5 ,
V_209 + V_219 ) ;
goto V_215;
}
if ( F_6 ( V_6 , V_216 , V_217 ) ) {
V_206 = F_113 ( V_5 ,
V_218 + V_219 ) ;
goto V_215;
}
if ( F_6 ( V_6 , V_183 , V_184 ) ) {
return F_120 ( V_5 ,
V_6 , V_177 , 0 ) ;
}
return - V_18 ;
V_215:
V_235 = V_6 & 0xfffffff8 ;
F_121 ( & V_5 -> V_21 . V_193 ) ;
F_4 ( V_235 , ( V_206 + V_224 ) ) ;
F_4 ( 0 , ( V_206 + V_220 ) ) ;
F_4 ( V_225 , ( V_206 + V_227 ) ) ;
F_4 ( ( V_228 | V_225 ) , ( V_206 + V_227 ) ) ;
for ( V_199 = 0 ; V_199 < V_229 ; V_199 ++ ) {
V_200 = F_2 ( V_206 + V_227 ) ;
if ( ( V_200 & V_230 ) == 0 )
break;
}
if ( V_199 >= V_229 ) {
if ( F_82 () )
F_106 ( & V_5 -> V_156 -> V_157 ,
L_17 ) ;
V_192 = - V_18 ;
} else {
V_2 = ( T_1 ) ( F_2 ( V_206 + V_234 ) ) << 32 ;
V_2 |= F_2 ( V_206 + V_233 ) ;
* V_177 = V_2 ;
V_192 = 0 ;
}
F_122 ( & V_5 -> V_21 . V_193 ) ;
return V_192 ;
}
void
F_130 ( struct V_4 * V_5 )
{
V_5 -> V_237 = F_18 ;
V_5 -> V_238 = F_20 ;
if ( F_19 ( V_5 -> V_21 . V_22 ) ) {
V_5 -> V_239 = F_101 ,
V_5 -> V_240 = F_96 ,
V_5 -> V_194 = F_116 ,
V_5 -> V_241 = F_127 ,
V_5 -> V_242 = F_125 ,
V_5 -> V_243 = F_102 ,
V_5 -> V_244 = F_97 ,
V_5 -> V_245 = F_24 ;
V_5 -> V_246 = F_32 ;
V_5 -> V_137 = V_247 ;
V_5 -> V_60 = F_22 ;
} else {
V_5 -> V_239 = F_108 ,
V_5 -> V_240 = F_103 ,
V_5 -> V_194 = F_117 ,
V_5 -> V_241 = F_129 ,
V_5 -> V_242 = F_128 ,
V_5 -> V_243 = F_112 ,
V_5 -> V_244 = F_111 ,
V_5 -> V_137 = V_248 ;
V_5 -> V_60 = F_61 ;
V_5 -> V_245 = F_63 ;
V_5 -> V_246 = F_55 ;
V_5 -> V_249 = V_250 ;
V_5 -> V_251 = V_252 ;
}
}
int F_131 ( struct V_4 * V_5 )
{
int V_146 , V_32 , V_253 ;
struct V_254 * V_156 = V_5 -> V_156 ;
V_146 = V_255 ;
if ( F_74 ( V_5 , V_146 , & V_253 ) )
return - V_18 ;
if ( V_253 != V_256 ) {
F_106 ( & V_156 -> V_157 , L_18 ,
V_253 ) ;
return - V_18 ;
}
V_146 = V_257 ;
if ( F_74 ( V_5 , V_146 , & V_32 ) )
return - V_18 ;
if ( V_32 == V_258 ) {
V_3 V_259 = F_11 ( V_5 , V_260 ) ;
if ( ( V_259 & 0x8000 ) == 0 )
V_32 = V_261 ;
}
V_5 -> V_21 . V_32 = V_32 ;
switch ( V_32 ) {
case V_262 :
V_5 -> V_21 . V_263 = V_264 ;
break;
case V_265 :
case V_33 :
case V_34 :
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_272 :
case V_273 :
case V_274 :
case V_275 :
case V_276 :
V_5 -> V_21 . V_263 = V_277 ;
break;
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_258 :
V_5 -> V_21 . V_263 = V_264 ;
break;
case V_261 :
V_5 -> V_21 . V_263 = ( V_5 -> V_19 < 2 ) ?
V_277 : V_264 ;
break;
default:
F_106 ( & V_156 -> V_157 , L_19 , V_32 ) ;
V_5 -> V_21 . V_263 = V_277 ;
break;
}
return 0 ;
}
static int V_247 ( struct V_4 * V_5 , int V_284 )
{
V_284 += V_285 ;
if ( V_5 -> V_26 == 0 )
F_15 ( V_5 , V_286 , V_284 ) ;
else
F_15 ( V_5 , V_287 , V_284 ) ;
return 0 ;
}
void F_132 ( struct V_4 * V_5 )
{
T_3 V_288 ;
T_3 V_289 ;
T_3 V_290 ;
if ( ! F_133 ( V_5 -> V_53 ) ) {
V_5 -> V_291 = 0 ;
V_5 -> V_292 = - 1 ;
V_5 -> V_293 = V_294 ;
return;
}
if ( V_5 -> V_21 . V_263 == V_264 ) {
V_290 = F_11 ( V_5 , V_295 ) ;
if ( V_290 == V_296 ) {
V_5 -> V_291 = V_297 ;
V_5 -> V_292 = V_298 ;
V_5 -> V_293 = V_299 ;
return;
}
if ( V_5 -> V_249 &&
V_5 -> V_249 ( V_5 ,
V_300 ,
& V_288 ) == 0 ) {
if ( F_134 ( V_288 ) ) {
switch ( F_135 ( V_288 ) ) {
case 0 :
V_5 -> V_291 = V_301 ;
break;
case 1 :
V_5 -> V_291 = V_302 ;
break;
case 2 :
V_5 -> V_291 = V_297 ;
break;
default:
V_5 -> V_291 = 0 ;
break;
}
switch ( F_136 ( V_288 ) ) {
case 0 :
V_5 -> V_292 = V_303 ;
break;
case 1 :
V_5 -> V_292 = V_298 ;
break;
default:
V_5 -> V_292 = - 1 ;
break;
}
if ( V_5 -> V_249 &&
V_5 -> V_249 ( V_5 ,
V_304 ,
& V_289 ) != 0 )
V_5 -> V_293 = V_289 ;
} else
goto V_305;
} else {
V_305:
V_5 -> V_291 = 0 ;
V_5 -> V_292 = - 1 ;
}
}
}
int
F_137 ( struct V_4 * V_5 )
{
V_3 V_306 ;
if ( F_19 ( V_5 -> V_21 . V_22 ) )
return 0 ;
V_306 = F_11 ( V_5 , V_307 ) ;
if ( V_306 & ( 1UL << V_5 -> V_19 ) ) {
V_306 = F_11 ( V_5 , V_308 ) ;
if ( V_306 & ( 1 << V_5 -> V_19 ) )
return 1 ;
}
return 0 ;
}
