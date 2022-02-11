static void
F_1 ( T_1 * V_1 , short V_2 , short V_3 ,
short V_4 , short V_5 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
F_2 ( V_6 -> V_7 ,
F_3 ( V_1 -> V_8 , V_1 -> V_9 , V_10 ) , V_2 ) ;
F_2 ( V_6 -> V_7 ,
F_3 ( V_1 -> V_8 , V_1 -> V_9 , V_11 ) , V_3 ) ;
F_2 ( V_6 -> V_7 ,
F_3 ( V_1 -> V_8 , V_1 -> V_9 , V_12 ) , V_4 ) ;
F_2 ( V_6 -> V_7 ,
F_3 ( V_1 -> V_8 , V_1 -> V_9 , V_13 ) , V_5 ) ;
}
static void
F_4 ( T_1 * V_1 , short V_14 , short V_15 , short V_16 , short V_17 ,
short V_18 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
F_2 ( V_6 -> V_7 ,
F_5 ( V_1 -> V_8 , V_1 -> V_9 , V_19 ) ,
( V_18 << 0x10 ) | V_17 ) ;
F_2 ( V_6 -> V_7 ,
F_5 ( V_1 -> V_8 , V_1 -> V_9 , V_20 ) ,
( V_15 << 0x10 ) | V_14 ) ;
F_2 ( V_6 -> V_7 ,
F_5 ( V_1 -> V_8 , V_1 -> V_9 , V_21 ) , V_16 ) ;
}
static void
F_6 ( T_1 * V_1 , short V_14 , short V_15 , short V_16 , short V_17 ,
short V_18 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
F_2 ( V_6 -> V_7 ,
F_5 ( V_1 -> V_8 , V_1 -> V_9 , V_22 ) ,
( V_18 << 0x10 ) | V_17 ) ;
F_2 ( V_6 -> V_7 ,
F_5 ( V_1 -> V_8 , V_1 -> V_9 , V_23 ) ,
( V_15 << 0x10 ) | V_14 ) ;
F_2 ( V_6 -> V_7 ,
F_5 ( V_1 -> V_8 , V_1 -> V_9 , V_24 ) , V_16 ) ;
}
static void
F_7 ( T_1 * V_1 , short V_25 , short V_26 , short y1 , short V_27 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
F_2 ( V_6 -> V_7 , F_3 ( V_1 -> V_8 , V_1 -> V_9 , V_28 ) , V_25 ) ;
F_2 ( V_6 -> V_7 , F_3 ( V_1 -> V_8 , V_1 -> V_9 , V_29 ) , V_26 ) ;
F_2 ( V_6 -> V_7 , F_3 ( V_1 -> V_8 , V_1 -> V_9 , V_30 ) , y1 ) ;
F_2 ( V_6 -> V_7 , F_3 ( V_1 -> V_8 , V_1 -> V_9 , V_31 ) , V_27 ) ;
}
static void
F_8 ( T_1 * V_1 , T_3 const V_14 , T_3 const V_15 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
F_2 ( V_6 -> V_7 ,
F_5 ( V_1 -> V_8 , V_1 -> V_9 ,
V_34 ) + ( V_32 << 2 ) ,
( V_15 [ V_32 ] << 0x10 ) | V_14 [ V_32 ] ) ;
}
static void
F_9 ( T_1 * V_1 , T_3 const V_14 , T_3 const V_15 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
F_2 ( V_6 -> V_7 ,
F_5 ( V_1 -> V_8 , V_1 -> V_9 ,
V_35 ) + ( V_32 << 2 ) ,
( V_15 [ V_32 ] << 0x10 ) | V_14 [ V_32 ] ) ;
}
static void
F_10 ( T_1 * V_1 , T_3 const V_14 , T_3 const V_15 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
F_2 ( V_6 -> V_7 ,
F_5 ( V_1 -> V_8 , V_1 -> V_9 ,
V_36 ) + ( V_32 << 2 ) ,
( V_15 [ V_32 ] << 0x10 ) | V_14 [ V_32 ] ) ;
}
static void F_11 ( T_1 * V_1 , short V_37 , short V_38 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
F_2 ( V_6 -> V_7 ,
F_3 ( V_1 -> V_8 , V_1 -> V_9 , V_39 ) , V_37 ) ;
F_2 ( V_6 -> V_7 ,
F_3 ( V_1 -> V_8 , V_1 -> V_9 , V_40 ) , V_38 ) ;
}
static void F_12 ( T_1 * V_1 , short V_41 , short V_42 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
if ( V_41 < 0 )
V_41 = 0 ;
if ( V_41 > 0x57FF )
V_41 = 0x57FF ;
if ( V_42 < 0 )
V_42 = 0 ;
if ( V_42 > 0x57FF )
V_42 = 0x57FF ;
F_2 ( V_6 -> V_7 ,
F_5 ( V_1 -> V_8 , V_1 -> V_9 , V_43 ) ,
( V_42 << 0x10 ) | V_41 ) ;
}
static void F_13 ( T_1 * V_1 , short V_41 , short V_42 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
if ( V_41 < 0 )
V_41 = 0 ;
if ( V_41 > 0x57FF )
V_41 = 0x57FF ;
if ( V_42 < 0 )
V_42 = 0 ;
if ( V_42 > 0x57FF )
V_42 = 0x57FF ;
F_2 ( V_6 -> V_7 ,
F_5 ( V_1 -> V_8 , V_1 -> V_9 , V_44 ) ,
( V_42 << 0x10 ) | V_41 ) ;
}
static void F_14 ( T_1 * V_1 , T_4 const V_45 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_46 ; V_32 ++ )
F_2 ( V_6 -> V_7 ,
F_3 ( V_1 -> V_8 , V_1 -> V_9 ,
V_47 ) + ( V_32 << 2 ) , V_45 [ V_32 ] ) ;
}
static void F_15 ( T_1 * V_1 , short V_37 , short V_38 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
F_2 ( V_6 -> V_7 ,
F_5 ( V_1 -> V_8 , V_1 -> V_9 , V_48 ) ,
( V_38 << 0x10 ) | V_37 ) ;
}
static void F_16 ( T_1 * V_1 , short V_37 , short V_38 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
F_2 ( V_6 -> V_7 ,
F_5 ( V_1 -> V_8 , V_1 -> V_9 , V_49 ) ,
( V_38 << 0x10 ) | V_37 ) ;
}
static void F_17 ( T_1 * V_1 , int V_50 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
int V_51 = 0 ;
V_51 = ( ( ( V_51 & 0x7fffffff ) | 0xB8000000 ) & 0x7 ) | ( ( V_50 & 0x1f ) << 3 ) ;
F_2 ( V_6 -> V_7 , V_52 + ( ( V_1 -> V_8 ) << 0xd ) , V_51 ) ;
}
static void F_18 ( T_1 * V_1 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
F_2 ( V_6 -> V_7 , V_52 + ( ( V_1 -> V_8 ) << 0xd ) ,
0xF0000001 ) ;
}
static void F_19 ( T_1 * V_1 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
F_2 ( V_6 -> V_7 , V_52 + ( ( V_1 -> V_8 ) << 0xd ) ,
0xF0000000 ) ;
}
static void F_20 ( T_1 * V_1 , unsigned long V_53 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
F_2 ( V_6 -> V_7 , V_52 + ( ( V_1 -> V_8 ) << 0xd ) , V_53 ) ;
}
static void F_21 ( T_1 * V_1 , unsigned long V_54 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
F_2 ( V_6 -> V_7 , V_55 + ( ( V_1 -> V_8 ) << 0xd ) , V_54 ) ;
}
static void F_22 ( T_1 * V_1 )
{
T_2 * V_6 = ( T_2 * ) ( V_1 -> V_6 ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < 8 ; V_32 ++ )
F_2 ( V_6 -> V_7 ,
V_56 +
( ( ( ( V_1 -> V_8 ) << 0xb ) + V_32 ) << 2 ) , 0 ) ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ )
F_2 ( V_6 -> V_7 ,
V_57 +
( ( ( ( V_1 -> V_8 ) << 0xb ) + V_32 ) << 2 ) , 0 ) ;
}
static void F_23 ( T_1 * V_1 )
{
F_7 ( V_1 , 0 , 0 , 0 , 0 ) ;
F_10 ( V_1 , V_58 , V_58 ) ;
F_14 ( V_1 , V_59 ) ;
F_11 ( V_1 , 0 , 0 ) ;
F_1 ( V_1 , 0 , 0 , 0 , 0 ) ;
F_6 ( V_1 , 0 , 0 , 0 , 0 , 0 ) ;
F_4 ( V_1 , 0 , 0 , 0 , 0 , 0 ) ;
F_13 ( V_1 , 0 , 0 ) ;
F_12 ( V_1 , 0 , 0 ) ;
F_16 ( V_1 , 0 , 0 ) ;
F_15 ( V_1 , 0 , 0 ) ;
F_9 ( V_1 , V_58 , V_58 ) ;
F_8 ( V_1 , V_58 , V_58 ) ;
}
static void F_24 ( T_1 * V_1 )
{
int V_32 , V_60 , V_61 ;
if ( ( V_1 -> V_6 ) == NULL ) {
F_25 ( V_62 L_1 ) ;
return;
}
F_20 ( V_1 , 0 ) ;
F_21 ( V_1 , 0 ) ;
V_60 = V_1 -> V_8 ;
V_61 = V_1 -> V_9 ;
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
V_1 -> V_8 = V_32 ;
F_22 ( V_1 ) ;
}
V_1 -> V_9 = V_61 ;
V_1 -> V_8 = V_60 ;
}
static void F_26 ( T_1 * V_1 )
{
F_1 ( V_1 , 0 , 0 , 0 , 0 ) ;
F_6 ( V_1 , 0 , 0x4000 , 0 , 0 , 0 ) ;
F_4 ( V_1 , 0x4000 , 0 , 0 , 0 , 0 ) ;
F_13 ( V_1 , 0 , 0 ) ;
F_12 ( V_1 , 0 , 0 ) ;
F_16 ( V_1 , 0x7fff , 0x7fff ) ;
F_15 ( V_1 , 0x7fff , 0x7fff ) ;
F_9 ( V_1 , V_63 , V_63 ) ;
F_8 ( V_1 , V_63 , V_63 ) ;
}
static void F_27 ( T_2 * V_64 , int V_9 , int V_8 )
{
T_1 * V_65 = & ( V_64 -> V_66 [ V_9 + ( V_8 * 4 ) ] ) ;
V_65 -> V_6 = ( void * ) V_64 ;
V_65 -> V_9 = V_9 ;
V_65 -> V_8 = V_8 ;
F_23 ( V_65 ) ;
F_17 ( V_65 , 0x11 ) ;
}
static int F_28 ( T_2 * V_64 , unsigned short V_67 )
{
V_64 -> V_68 = V_67 ;
F_29 ( V_64 ) ;
F_30 ( V_64 ) ;
switch ( V_64 -> V_68 ) {
case V_69 :
F_31 ( V_64 ) ;
break;
case V_70 :
F_32 ( V_64 ) ;
break;
default:
case V_71 :
F_33 ( V_64 ) ;
break;
case V_72 :
F_34 ( V_64 ) ;
break;
}
F_35 ( V_64 , 0x11 ) ;
F_36 ( V_64 ) ;
return 0 ;
}
static void F_37 ( T_2 * V_64 )
{
int V_32 ;
F_28 ( V_64 , V_71 ) ;
for ( V_32 = 0 ; V_32 < V_73 ; V_32 ++ ) {
F_27 ( V_64 , V_32 % 4 , V_32 >> 2 ) ;
F_24 ( & ( V_64 -> V_66 [ 0 ] ) ) ;
}
F_38 ( V_64 ) ;
}
static void F_39 ( T_2 * V_64 )
{
F_40 ( V_64 ) ;
F_41 ( V_64 ) ;
}
static void F_42 ( T_2 * V_64 , int V_74 )
{
int V_32 ;
#ifdef F_43
return;
#endif
#if 1
V_64 -> V_75 [ 0 ] =
F_44 ( V_64 , V_64 -> V_76 , V_74 , V_77 ) ;
if ( V_64 -> V_75 [ 0 ] < 0 ) {
F_25
( L_2 ) ;
return;
}
V_64 -> V_75 [ 1 ] =
F_44 ( V_64 , V_64 -> V_76 , V_74 , V_77 ) ;
if ( V_64 -> V_75 [ 1 ] < 0 ) {
F_25
( L_2 ) ;
return;
}
#endif
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
F_45 ( V_64 , V_74 , 0x11 , F_46 ( V_32 * 2 ) , F_47 ( V_32 ) ) ;
F_45 ( V_64 , V_74 , 0x11 , F_46 ( V_32 * 2 ) + 1 , F_47 ( 5 + V_32 ) ) ;
}
#if 0
vortex_route(v, en, 0x11, ADB_XTALKOUT(0), ADB_EQIN(2));
vortex_route(v, en, 0x11, ADB_XTALKOUT(1), ADB_EQIN(3));
#else
F_45 ( V_64 , V_74 , 0x11 , F_48 ( 0 ) , F_49 ( V_64 -> V_75 [ 0 ] ) ) ;
F_45 ( V_64 , V_74 , 0x11 , F_48 ( 1 ) , F_49 ( V_64 -> V_75 [ 1 ] ) ) ;
F_50 ( V_64 , V_74 , V_64 -> V_75 [ 0 ] , V_64 -> V_78 [ 0 ] , 0 ) ;
F_50 ( V_64 , V_74 , V_64 -> V_75 [ 1 ] , V_64 -> V_78 [ 1 ] , 0 ) ;
F_51 ( V_64 , V_64 -> V_78 [ 0 ] , V_64 -> V_75 [ 0 ] ,
V_74 ? V_79 : V_80 ) ;
F_51 ( V_64 , V_64 -> V_78 [ 1 ] , V_64 -> V_75 [ 1 ] ,
V_74 ? V_79 : V_80 ) ;
if ( F_52 ( V_64 ) ) {
F_50 ( V_64 , V_74 , V_64 -> V_75 [ 0 ] ,
V_64 -> V_78 [ 2 ] , 0 ) ;
F_50 ( V_64 , V_74 , V_64 -> V_75 [ 1 ] ,
V_64 -> V_78 [ 3 ] , 0 ) ;
F_51 ( V_64 , V_64 -> V_78 [ 2 ] ,
V_64 -> V_75 [ 0 ] ,
V_74 ? V_79 : V_80 ) ;
F_51 ( V_64 , V_64 -> V_78 [ 3 ] ,
V_64 -> V_75 [ 1 ] ,
V_74 ? V_79 : V_80 ) ;
}
#endif
}
static void F_53 ( T_1 * V_1 , int V_74 )
{
if ( V_1 -> V_6 == NULL ) {
F_25
( L_3 ) ;
return;
}
if ( V_74 ) {
F_26 ( V_1 ) ;
F_17 ( V_1 , 0x11 ) ;
F_1 ( V_1 , V_81 ,
V_82 , V_83 ,
V_84 ) ;
F_18 ( V_1 ) ;
} else {
F_19 ( V_1 ) ;
F_23 ( V_1 ) ;
}
}
static void F_54 ( T_3 V_85 , int * V_86 )
{
}
static void F_55 ( T_5 V_87 , int * V_86 )
{
}
static void F_56 ( T_6 V_88 , int V_37 , int V_38 )
{
}
static void F_57 ( T_7 V_89 , int * V_90 )
{
}
static int
F_58 ( struct V_91 * V_92 , struct V_93 * V_94 )
{
V_94 -> type = V_95 ;
V_94 -> V_96 = 6 ;
V_94 -> V_97 . integer . V_98 = 0x00000000 ;
V_94 -> V_97 . integer . V_99 = 0xffffffff ;
return 0 ;
}
static int
F_59 ( struct V_91 * V_92 , struct V_93 * V_94 )
{
V_94 -> type = V_95 ;
V_94 -> V_96 = 2 ;
V_94 -> V_97 . integer . V_98 = 0x00000000 ;
V_94 -> V_97 . integer . V_99 = 0xffffffff ;
return 0 ;
}
static int
F_60 ( struct V_91 * V_92 , struct V_93 * V_94 )
{
V_94 -> type = V_95 ;
V_94 -> V_96 = 2 ;
V_94 -> V_97 . integer . V_98 = 0x00000000 ;
V_94 -> V_97 . integer . V_99 = 0xffffffff ;
return 0 ;
}
static int
F_61 ( struct V_91 * V_92 ,
struct V_93 * V_94 )
{
V_94 -> type = V_95 ;
V_94 -> V_96 = 4 ;
V_94 -> V_97 . integer . V_98 = 0x00000000 ;
V_94 -> V_97 . integer . V_99 = 0xffffffff ;
return 0 ;
}
static int
F_62 ( struct V_91 * V_92 , struct V_100 * V_101 )
{
return 0 ;
}
static int
F_63 ( struct V_91 * V_92 ,
struct V_100 * V_101 )
{
T_1 * V_1 = V_92 -> V_102 ;
int V_103 = 1 , V_32 ;
int V_86 [ 6 ] ;
for ( V_32 = 0 ; V_32 < 6 ; V_32 ++ )
V_86 [ V_32 ] = V_101 -> V_97 . integer . V_97 [ V_32 ] ;
F_54 ( V_1 -> V_85 [ 0 ] , V_86 ) ;
F_54 ( V_1 -> V_85 [ 1 ] , V_86 ) ;
F_8 ( V_1 , V_1 -> V_85 [ 0 ] , V_1 -> V_85 [ 1 ] ) ;
F_9 ( V_1 , V_1 -> V_85 [ 0 ] , V_1 -> V_85 [ 1 ] ) ;
return V_103 ;
}
static int
F_64 ( struct V_91 * V_92 ,
struct V_100 * V_101 )
{
T_1 * V_1 = V_92 -> V_102 ;
int V_86 [ 6 ] ;
int V_32 , V_103 = 1 ;
for ( V_32 = 0 ; V_32 < 6 ; V_32 ++ )
V_86 [ V_32 ] = V_101 -> V_97 . integer . V_97 [ V_32 ] ;
F_55 ( V_1 -> V_85 [ 0 ] , V_86 ) ;
F_55 ( V_1 -> V_85 [ 1 ] , V_86 ) ;
F_12 ( V_1 , V_1 -> V_87 [ 0 ] , V_1 -> V_87 [ 1 ] ) ;
F_13 ( V_1 , V_1 -> V_87 [ 0 ] , V_1 -> V_87 [ 1 ] ) ;
F_14 ( V_1 , V_1 -> V_45 ) ;
return V_103 ;
}
static int
F_65 ( struct V_91 * V_92 ,
struct V_100 * V_101 )
{
T_1 * V_1 = V_92 -> V_102 ;
int V_103 = 1 ;
int V_104 , V_105 ;
V_104 = V_101 -> V_97 . integer . V_97 [ 0 ] ;
V_105 = V_101 -> V_97 . integer . V_97 [ 1 ] ;
F_56 ( V_1 -> V_88 , V_104 , V_105 ) ;
F_15 ( V_1 , V_104 , V_105 ) ;
F_16 ( V_1 , V_104 , V_105 ) ;
return V_103 ;
}
static int
F_66 ( struct V_91 * V_92 ,
struct V_100 * V_101 )
{
T_1 * V_1 = V_92 -> V_102 ;
int V_32 , V_103 = 1 ;
int V_90 [ 6 ] ;
for ( V_32 = 0 ; V_32 < 6 ; V_32 ++ )
V_90 [ V_32 ] = V_101 -> V_97 . integer . V_97 [ V_32 ] ;
F_57 ( V_1 -> V_89 , V_90 ) ;
F_4 ( V_1 , V_1 -> V_89 [ 0 ] ,
V_1 -> V_89 [ 1 ] , V_1 -> V_89 [ 2 ] ,
V_1 -> V_89 [ 3 ] , V_1 -> V_89 [ 4 ] ) ;
F_6 ( V_1 , V_1 -> V_89 [ 0 ] ,
V_1 -> V_89 [ 1 ] , V_1 -> V_89 [ 2 ] ,
V_1 -> V_89 [ 3 ] , V_1 -> V_89 [ 4 ] ) ;
return V_103 ;
}
static int F_38 ( T_2 * V_6 )
{
struct V_91 * V_92 ;
int V_106 , V_32 ;
for ( V_32 = 0 ; V_32 < V_73 ; V_32 ++ ) {
if ( ( V_92 =
F_67 ( & V_107 , & V_6 -> V_66 [ V_32 ] ) ) == NULL )
return - V_108 ;
V_92 -> V_109 . V_110 = V_111 ;
V_92 -> V_112 = F_58 ;
V_92 -> V_113 = F_63 ;
if ( ( V_106 = F_68 ( V_6 -> V_114 , V_92 ) ) < 0 )
return V_106 ;
}
for ( V_32 = 0 ; V_32 < V_73 ; V_32 ++ ) {
if ( ( V_92 =
F_67 ( & V_107 , & V_6 -> V_66 [ V_32 ] ) ) == NULL )
return - V_108 ;
V_92 -> V_109 . V_110 = V_115 ;
V_92 -> V_112 = F_59 ;
V_92 -> V_113 = F_64 ;
if ( ( V_106 = F_68 ( V_6 -> V_114 , V_92 ) ) < 0 )
return V_106 ;
}
for ( V_32 = 0 ; V_32 < V_73 ; V_32 ++ ) {
if ( ( V_92 =
F_67 ( & V_107 , & V_6 -> V_66 [ V_32 ] ) ) == NULL )
return - V_108 ;
V_92 -> V_109 . V_110 = V_116 ;
V_92 -> V_112 = F_60 ;
V_92 -> V_113 = F_65 ;
if ( ( V_106 = F_68 ( V_6 -> V_114 , V_92 ) ) < 0 )
return V_106 ;
}
for ( V_32 = 0 ; V_32 < V_73 ; V_32 ++ ) {
if ( ( V_92 =
F_67 ( & V_107 , & V_6 -> V_66 [ V_32 ] ) ) == NULL )
return - V_108 ;
V_92 -> V_109 . V_110 = V_117 ;
V_92 -> V_112 = F_61 ;
V_92 -> V_113 = F_66 ;
if ( ( V_106 = F_68 ( V_6 -> V_114 , V_92 ) ) < 0 )
return V_106 ;
}
return 0 ;
}
static void F_41 ( T_2 * V_6 )
{
}
