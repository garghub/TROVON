static void F_1 ( struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
if ( V_3 != V_7 ) {
if ( V_4 & V_8 )
F_3 ( V_6 -> V_9 , V_10 , V_3 ) ;
else if ( V_4 & V_11 )
F_3 ( V_6 -> V_9 , V_12 , V_3 ) ;
else
F_3 ( V_6 -> V_9 , V_13 , V_3 ) ;
}
}
static void F_4 ( struct V_1 * V_2 , T_1 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
F_5 ( V_17 -> V_19 , V_14 , V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 , const T_1 * V_14 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
T_1 * V_20 = ( T_1 * ) V_14 ;
T_2 V_21 = 0 ;
while ( V_15 -- ) {
F_7 ( * V_20 ++ , V_6 -> V_17 . V_22 ) ;
do {
V_21 = F_8 ( V_23 ) ;
} while ( ! V_21 );
}
}
static void F_9 ( struct V_1 * V_2 , T_1 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
F_10 ( V_17 -> V_19 , V_14 , V_15 / 2 ) ;
}
static void F_11 ( struct V_1 * V_2 , const T_1 * V_14 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
T_3 * V_20 = ( T_3 * ) V_14 ;
T_2 V_21 = 0 ;
V_15 >>= 1 ;
while ( V_15 -- ) {
F_12 ( * V_20 ++ , V_6 -> V_17 . V_22 ) ;
do {
V_21 = F_8 ( V_23 ) ;
} while ( ! V_21 );
}
}
static void F_13 ( struct V_1 * V_2 , T_1 * V_14 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
T_4 V_24 = 0 ;
int V_25 = 0 ;
T_2 * V_20 = ( T_2 * ) V_14 ;
if ( V_15 % 4 ) {
if ( V_6 -> V_17 . V_26 & V_27 )
F_9 ( V_2 , V_14 , V_15 % 4 ) ;
else
F_4 ( V_2 , V_14 , V_15 % 4 ) ;
V_20 = ( T_2 * ) ( V_14 + V_15 % 4 ) ;
V_15 -= V_15 % 4 ;
}
V_25 = F_14 ( V_6 -> V_9 ,
V_28 , 0x0 , V_15 , 0x0 ) ;
if ( V_25 ) {
if ( V_6 -> V_17 . V_26 & V_27 )
F_9 ( V_2 , ( T_1 * ) V_20 , V_15 ) ;
else
F_4 ( V_2 , ( T_1 * ) V_20 , V_15 ) ;
} else {
do {
V_24 = F_8 ( V_29 ) ;
V_24 = V_24 >> 2 ;
F_15 ( V_6 -> V_17 . V_19 , V_20 , V_24 ) ;
V_20 += V_24 ;
V_15 -= V_24 << 2 ;
} while ( V_15 );
F_16 ( V_6 -> V_9 ) ;
}
}
static void F_17 ( struct V_1 * V_2 ,
const T_1 * V_14 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
T_4 V_30 = 0 ;
int V_31 = 0 , V_25 = 0 ;
T_3 * V_20 = ( T_3 * ) V_14 ;
unsigned long V_32 , V_33 ;
if ( V_15 % 2 != 0 ) {
F_18 ( * V_14 , V_6 -> V_17 . V_22 ) ;
V_20 = ( T_3 * ) ( V_14 + 1 ) ;
V_15 -- ;
}
V_25 = F_14 ( V_6 -> V_9 ,
V_28 , 0x0 , V_15 , 0x1 ) ;
if ( V_25 ) {
if ( V_6 -> V_17 . V_26 & V_27 )
F_11 ( V_2 , ( T_1 * ) V_20 , V_15 ) ;
else
F_6 ( V_2 , ( T_1 * ) V_20 , V_15 ) ;
} else {
while ( V_15 ) {
V_30 = F_8 ( V_29 ) ;
V_30 = V_30 >> 1 ;
for ( V_31 = 0 ; ( V_31 < V_30 ) && V_15 ; V_31 ++ , V_15 -= 2 )
F_12 ( * V_20 ++ , V_6 -> V_17 . V_22 ) ;
}
V_32 = 0 ;
V_33 = ( V_34 *
F_19 ( V_35 ) ) ;
while ( F_8 ( V_36 ) && ( V_32 ++ < V_33 ) )
F_20 () ;
F_16 ( V_6 -> V_9 ) ;
}
}
static void F_21 ( int V_37 , T_3 V_38 , void * V_39 )
{
F_22 ( (struct V_40 * ) V_39 ) ;
}
static inline int F_23 ( struct V_1 * V_2 , void * V_41 ,
unsigned int V_15 , int V_42 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
enum V_43 V_44 = V_42 ? V_45 :
V_46 ;
T_5 V_47 ;
int V_25 ;
unsigned long V_32 , V_33 ;
int V_48 = V_15 >> 6 ;
if ( V_41 >= V_49 ) {
struct V_50 * V_51 ;
if ( ( ( V_52 ) V_41 & V_53 ) !=
( ( V_52 ) ( V_41 + V_15 - 1 ) & V_53 ) )
goto V_54;
V_51 = F_24 ( V_41 ) ;
if ( ! V_51 )
goto V_54;
V_41 = F_25 ( V_51 ) + ( ( V_52 ) V_41 & ~ V_53 ) ;
}
V_47 = F_26 ( & V_6 -> V_55 -> V_56 , V_41 , V_15 , V_44 ) ;
if ( F_27 ( & V_6 -> V_55 -> V_56 , V_47 ) ) {
F_28 ( & V_6 -> V_55 -> V_56 ,
L_1 , V_15 ) ;
goto V_54;
}
if ( V_42 ) {
F_29 ( V_6 -> V_57 , 0 , V_58 ,
V_6 -> V_59 , 0 , 0 ) ;
F_30 ( V_6 -> V_57 , 0 , V_60 ,
V_47 , 0 , 0 ) ;
F_31 ( V_6 -> V_57 , V_61 ,
0x10 , V_48 , V_62 ,
V_63 , V_64 ) ;
} else {
F_30 ( V_6 -> V_57 , 0 , V_58 ,
V_6 -> V_59 , 0 , 0 ) ;
F_29 ( V_6 -> V_57 , 0 , V_60 ,
V_47 , 0 , 0 ) ;
F_31 ( V_6 -> V_57 , V_61 ,
0x10 , V_48 , V_62 ,
V_63 , V_65 ) ;
}
V_25 = F_14 ( V_6 -> V_9 ,
V_28 , 0x1 , V_15 , V_42 ) ;
if ( V_25 )
goto V_54;
F_32 ( & V_6 -> V_66 ) ;
F_33 ( V_6 -> V_57 ) ;
F_34 ( & V_6 -> V_66 ) ;
V_32 = 0 ;
V_33 = ( V_34 * F_19 ( V_35 ) ) ;
while ( F_8 ( V_36 ) && ( V_32 ++ < V_33 ) )
F_20 () ;
F_16 ( V_6 -> V_9 ) ;
F_35 ( & V_6 -> V_55 -> V_56 , V_47 , V_15 , V_44 ) ;
return 0 ;
V_54:
if ( V_6 -> V_17 . V_26 & V_27 )
V_42 == 0 ? F_9 ( V_2 , ( T_1 * ) V_41 , V_15 )
: F_11 ( V_2 , ( T_1 * ) V_41 , V_15 ) ;
else
V_42 == 0 ? F_4 ( V_2 , ( T_1 * ) V_41 , V_15 )
: F_6 ( V_2 , ( T_1 * ) V_41 , V_15 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , T_1 * V_14 , int V_15 )
{
if ( V_15 <= V_2 -> V_67 )
F_13 ( V_2 , V_14 , V_15 ) ;
else
F_23 ( V_2 , V_14 , V_15 , 0x0 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
const T_1 * V_14 , int V_15 )
{
if ( V_15 <= V_2 -> V_67 )
F_17 ( V_2 , V_14 , V_15 ) ;
else
F_23 ( V_2 , ( T_1 * ) V_14 , V_15 , 0x1 ) ;
}
static T_6 F_38 ( int V_68 , void * V_56 )
{
struct V_5 * V_6 = (struct V_5 * ) V_56 ;
T_2 V_69 ;
T_2 V_70 ;
V_70 = F_8 ( V_71 ) ;
V_69 = F_8 ( V_29 ) ;
V_69 = V_69 & 0xFFFC ;
if ( V_6 -> V_72 == V_73 ) {
if ( V_70 & 0x2 )
goto V_74;
if ( V_6 -> V_48 && ( V_6 -> V_48 < V_69 ) )
V_69 = V_6 -> V_48 ;
else if ( ! V_6 -> V_48 )
V_69 = 0 ;
F_39 ( V_6 -> V_17 . V_22 ,
( T_2 * ) V_6 -> V_14 , V_69 >> 2 ) ;
V_6 -> V_14 = V_6 -> V_14 + V_69 ;
V_6 -> V_48 -= V_69 ;
} else {
F_15 ( V_6 -> V_17 . V_19 ,
( T_2 * ) V_6 -> V_14 , V_69 >> 2 ) ;
V_6 -> V_14 = V_6 -> V_14 + V_69 ;
if ( V_70 & 0x2 )
goto V_74;
}
F_40 ( V_6 -> V_9 , V_75 , V_70 ) ;
return V_76 ;
V_74:
F_22 ( & V_6 -> V_66 ) ;
F_40 ( V_6 -> V_9 , V_77 , 0 ) ;
F_40 ( V_6 -> V_9 , V_75 , V_70 ) ;
return V_76 ;
}
static void F_41 ( struct V_1 * V_2 , T_1 * V_14 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
int V_25 = 0 ;
if ( V_15 <= V_2 -> V_67 ) {
F_13 ( V_2 , V_14 , V_15 ) ;
return;
}
V_6 -> V_72 = V_78 ;
V_6 -> V_14 = V_14 ;
F_32 ( & V_6 -> V_66 ) ;
V_25 = F_14 ( V_6 -> V_9 ,
V_28 / 2 , 0x0 , V_15 , 0x0 ) ;
if ( V_25 )
goto V_54;
V_6 -> V_48 = V_15 ;
F_40 ( V_6 -> V_9 , V_77 ,
( V_79 | V_80 ) ) ;
F_34 ( & V_6 -> V_66 ) ;
F_16 ( V_6 -> V_9 ) ;
return;
V_54:
if ( V_6 -> V_17 . V_26 & V_27 )
F_9 ( V_2 , V_14 , V_15 ) ;
else
F_4 ( V_2 , V_14 , V_15 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
const T_1 * V_14 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
int V_25 = 0 ;
unsigned long V_32 , V_33 ;
if ( V_15 <= V_2 -> V_67 ) {
F_17 ( V_2 , V_14 , V_15 ) ;
return;
}
V_6 -> V_72 = V_73 ;
V_6 -> V_14 = ( T_1 * ) V_14 ;
F_32 ( & V_6 -> V_66 ) ;
V_25 = F_14 ( V_6 -> V_9 ,
( V_28 * 3 ) / 8 , 0x0 , V_15 , 0x1 ) ;
if ( V_25 )
goto V_54;
V_6 -> V_48 = V_15 ;
F_40 ( V_6 -> V_9 , V_77 ,
( V_79 | V_80 ) ) ;
F_34 ( & V_6 -> V_66 ) ;
V_32 = 0 ;
V_33 = ( V_34 * F_19 ( V_35 ) ) ;
while ( F_8 ( V_36 ) && ( V_32 ++ < V_33 ) )
F_20 () ;
F_16 ( V_6 -> V_9 ) ;
return;
V_54:
if ( V_6 -> V_17 . V_26 & V_27 )
F_11 ( V_2 , V_14 , V_15 ) ;
else
F_6 ( V_2 , V_14 , V_15 ) ;
}
static int F_43 ( struct V_1 * V_2 , const T_1 * V_14 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
T_3 * V_20 = ( T_3 * ) V_14 ;
V_15 >>= 1 ;
while ( V_15 -- ) {
if ( * V_20 ++ != F_44 ( F_45 ( V_6 -> V_17 . V_19 ) ) )
return - V_81 ;
}
return 0 ;
}
static void F_46 ( T_7 * V_82 )
{
T_2 V_83 = V_82 [ 0 ] | ( V_82 [ 1 ] << 16 ) |
( ( V_82 [ 2 ] & 0xF0 ) << 20 ) | ( ( V_82 [ 2 ] & 0x0F ) << 8 ) ;
V_82 [ 0 ] = ~ ( F_47 ( V_83 ) | F_48 ( V_83 ) | F_49 ( V_83 ) | F_50 ( V_83 ) |
F_51 ( V_83 ) | F_52 ( V_83 ) | F_53 ( V_83 ) | F_54 ( V_83 ) ) ;
V_82 [ 1 ] = ~ ( F_55 ( V_83 ) | F_56 ( V_83 ) | F_57 ( V_83 ) | F_58 ( V_83 ) |
F_59 ( V_83 ) | F_60 ( V_83 ) | F_61 ( V_83 ) | F_62 ( V_83 ) ) ;
V_82 [ 2 ] = ~ ( F_63 ( V_83 ) | F_64 ( V_83 ) | F_65 ( V_83 ) | F_66 ( V_83 ) | F_67 ( V_83 ) |
F_68 ( V_83 ) | F_69 ( V_83 ) | F_70 ( V_83 ) ) ;
}
static int F_71 ( T_7 * V_84 ,
T_7 * V_85 ,
T_7 * V_86 )
{
T_8 V_31 ;
T_7 V_87 [ 8 ] , V_88 [ 8 ] , V_89 [ 8 ] ;
T_7 V_90 [ 8 ] , V_91 [ 8 ] , V_92 [ 8 ] ;
T_7 V_93 [ 24 ] ;
T_7 V_94 = 0 ;
T_7 V_95 = 0 ;
T_8 V_96 = 0 ;
int V_97 ;
V_97 = ( ( * ( T_2 * ) V_84 & 0xFFFFFF ) == 0xFFFFFF ) ;
F_46 ( V_84 ) ;
F_46 ( V_85 ) ;
for ( V_31 = 0 ; V_31 <= 2 ; V_31 ++ ) {
* ( V_84 + V_31 ) = ~ ( * ( V_84 + V_31 ) ) ;
* ( V_85 + V_31 ) = ~ ( * ( V_85 + V_31 ) ) ;
}
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
V_87 [ V_31 ] = * V_84 % 2 ;
* V_84 = * V_84 / 2 ;
}
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
V_88 [ V_31 ] = * ( V_84 + 1 ) % 2 ;
* ( V_84 + 1 ) = * ( V_84 + 1 ) / 2 ;
}
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
V_89 [ V_31 ] = * ( V_84 + 2 ) % 2 ;
* ( V_84 + 2 ) = * ( V_84 + 2 ) / 2 ;
}
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
V_90 [ V_31 ] = * V_85 % 2 ;
* V_85 = * V_85 / 2 ;
}
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
V_91 [ V_31 ] = * ( V_85 + 1 ) % 2 ;
* ( V_85 + 1 ) = * ( V_85 + 1 ) / 2 ;
}
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
V_92 [ V_31 ] = * ( V_85 + 2 ) % 2 ;
* ( V_85 + 2 ) = * ( V_85 + 2 ) / 2 ;
}
for ( V_31 = 0 ; V_31 < 6 ; V_31 ++ )
V_93 [ V_31 ] = V_89 [ V_31 + 2 ] ^ V_92 [ V_31 + 2 ] ;
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ )
V_93 [ V_31 + 6 ] = V_87 [ V_31 ] ^ V_90 [ V_31 ] ;
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ )
V_93 [ V_31 + 14 ] = V_88 [ V_31 ] ^ V_91 [ V_31 ] ;
V_93 [ 22 ] = V_89 [ 0 ] ^ V_92 [ 0 ] ;
V_93 [ 23 ] = V_89 [ 1 ] ^ V_92 [ 1 ] ;
for ( V_31 = 0 ; V_31 < 24 ; V_31 ++ )
V_94 += V_93 [ V_31 ] ;
switch ( V_94 ) {
case 0 :
return 0 ;
case 1 :
F_72 ( V_98 , L_2 ) ;
return - 1 ;
case 11 :
F_72 ( V_98 , L_3 ) ;
return - 1 ;
case 12 :
V_96 = ( V_93 [ 23 ] << 8 ) +
( V_93 [ 21 ] << 7 ) +
( V_93 [ 19 ] << 6 ) +
( V_93 [ 17 ] << 5 ) +
( V_93 [ 15 ] << 4 ) +
( V_93 [ 13 ] << 3 ) +
( V_93 [ 11 ] << 2 ) +
( V_93 [ 9 ] << 1 ) +
V_93 [ 7 ] ;
V_95 = ( V_93 [ 5 ] << 2 ) + ( V_93 [ 3 ] << 1 ) + V_93 [ 1 ] ;
F_72 ( V_98 , L_4
L_5 , V_96 , V_95 ) ;
V_86 [ V_96 ] ^= ( 1 << V_95 ) ;
return 1 ;
default:
if ( V_97 ) {
if ( V_85 [ 0 ] == 0 &&
V_85 [ 1 ] == 0 &&
V_85 [ 2 ] == 0 )
return 0 ;
}
F_72 ( V_98 , L_6 ) ;
return - 1 ;
}
}
static int F_73 ( struct V_1 * V_2 , T_1 * V_99 ,
T_1 * V_100 , T_1 * V_101 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
int V_102 = 0 , V_31 = 0 , V_25 = 0 ;
int V_103 = 0 ;
if ( ( V_6 -> V_17 . V_104 . V_105 == V_106 ) &&
( V_6 -> V_17 . V_104 . V_107 == 2048 ) )
V_102 = 4 ;
else
V_102 = 1 ;
for ( V_31 = 0 ; V_31 < V_102 ; V_31 ++ ) {
if ( memcmp ( V_100 , V_101 , 3 ) != 0 ) {
V_25 = F_71 ( V_100 , V_101 , V_99 ) ;
if ( V_25 < 0 )
return V_25 ;
V_103 += V_25 ;
}
V_100 += 3 ;
V_101 += 3 ;
V_99 += 512 ;
}
return V_103 ;
}
static int F_74 ( struct V_1 * V_2 , const T_1 * V_99 ,
T_1 * V_108 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
return F_75 ( V_6 -> V_9 , V_99 , V_108 ) ;
}
static void F_76 ( struct V_1 * V_2 , int V_105 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
struct V_16 * V_109 = V_2 -> V_18 ;
unsigned int V_110 = ( V_109 -> V_26 & V_27 ) ? 1 : 0 ;
F_77 ( V_6 -> V_9 , V_105 , V_110 , V_6 -> V_17 . V_104 . V_107 ) ;
}
static int F_78 ( struct V_1 * V_2 , struct V_16 * V_109 )
{
struct V_16 * V_111 = V_2 -> V_18 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
unsigned long V_112 = V_113 ;
int V_21 = V_114 , V_115 = V_111 -> V_115 ;
if ( V_115 == V_116 )
V_112 += ( V_117 * 400 ) / 1000 ;
else
V_112 += ( V_117 * 20 ) / 1000 ;
F_3 ( V_6 -> V_9 ,
V_10 , ( V_118 & 0xFF ) ) ;
while ( F_79 ( V_113 , V_112 ) ) {
V_21 = F_80 ( V_6 -> V_9 , V_13 ) ;
if ( V_21 & V_119 )
break;
F_81 () ;
}
return V_21 ;
}
static int F_82 ( struct V_1 * V_2 )
{
unsigned int V_120 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
V_120 = F_8 ( V_71 ) ;
if ( ( V_120 & 0x100 ) == 0x100 ) {
V_120 |= 0x100 ;
V_120 &= ~ ( 0x0 ) ;
F_40 ( V_6 -> V_9 , V_75 , V_120 ) ;
} else {
unsigned int V_121 = 0 ;
while ( V_121 ++ < 0x1FF ) {
if ( ( V_120 & 0x100 ) == 0x100 )
return 0 ;
V_120 = F_8 ( V_71 ) ;
}
}
return 1 ;
}
static int T_9 F_83 ( struct V_122 * V_55 )
{
struct V_5 * V_6 ;
struct V_123 * V_124 ;
int V_125 ;
int V_31 , V_126 ;
V_124 = V_55 -> V_56 . V_127 ;
if ( V_124 == NULL ) {
F_28 ( & V_55 -> V_56 , L_7 ) ;
return - V_128 ;
}
V_6 = F_84 ( sizeof( struct V_5 ) , V_129 ) ;
if ( ! V_6 )
return - V_130 ;
F_85 ( V_55 , V_6 ) ;
F_86 ( & V_6 -> V_131 . V_132 ) ;
F_87 ( & V_6 -> V_131 . V_133 ) ;
V_6 -> V_55 = V_55 ;
V_6 -> V_9 = V_124 -> V_134 ;
V_6 -> V_59 = V_124 -> V_59 ;
V_6 -> V_2 . V_18 = & V_6 -> V_17 ;
V_6 -> V_2 . V_135 = F_88 ( & V_55 -> V_56 ) ;
V_6 -> V_2 . V_136 = V_137 ;
V_6 -> V_17 . V_26 = V_124 -> V_138 ;
V_6 -> V_17 . V_26 |= V_139 ;
F_40 ( V_6 -> V_9 , V_140 , 0 ) ;
if ( ! F_89 ( V_6 -> V_59 , V_141 ,
V_55 -> V_56 . V_142 -> V_135 ) ) {
V_125 = - V_143 ;
goto V_144;
}
V_6 -> V_17 . V_19 = F_90 ( V_6 -> V_59 , V_141 ) ;
if ( ! V_6 -> V_17 . V_19 ) {
V_125 = - V_130 ;
goto V_145;
}
V_6 -> V_17 . V_131 = & V_6 -> V_131 ;
V_6 -> V_17 . V_22 = V_6 -> V_17 . V_19 ;
V_6 -> V_17 . V_146 = F_1 ;
if ( V_124 -> V_147 ) {
V_6 -> V_17 . V_147 = F_82 ;
V_6 -> V_17 . V_148 = 0 ;
} else {
V_6 -> V_17 . V_149 = F_78 ;
V_6 -> V_17 . V_148 = 50 ;
}
switch ( V_124 -> V_150 ) {
case V_151 :
V_6 -> V_17 . V_152 = F_13 ;
V_6 -> V_17 . V_153 = F_17 ;
break;
case V_154 :
if ( V_6 -> V_17 . V_26 & V_27 ) {
V_6 -> V_17 . V_152 = F_9 ;
V_6 -> V_17 . V_153 = F_11 ;
} else {
V_6 -> V_17 . V_152 = F_4 ;
V_6 -> V_17 . V_153 = F_6 ;
}
break;
case V_155 :
V_125 = F_91 ( V_63 , L_8 ,
F_21 , & V_6 -> V_66 , & V_6 -> V_57 ) ;
if ( V_125 < 0 ) {
V_6 -> V_57 = - 1 ;
F_28 ( & V_55 -> V_56 , L_9 ) ;
goto V_145;
} else {
F_92 ( V_6 -> V_57 ,
V_156 ) ;
F_93 ( V_6 -> V_57 ,
V_156 ) ;
V_6 -> V_17 . V_152 = F_36 ;
V_6 -> V_17 . V_153 = F_37 ;
}
break;
case V_157 :
V_125 = F_94 ( V_124 -> V_158 ,
F_38 , V_159 , L_10 , V_6 ) ;
if ( V_125 ) {
F_28 ( & V_55 -> V_56 , L_11 ,
V_124 -> V_158 , V_125 ) ;
goto V_145;
} else {
V_6 -> V_158 = V_124 -> V_158 ;
V_6 -> V_17 . V_152 = F_41 ;
V_6 -> V_17 . V_153 = F_42 ;
}
break;
default:
F_28 ( & V_55 -> V_56 ,
L_12 , V_124 -> V_150 ) ;
V_125 = - V_160 ;
goto V_145;
}
V_6 -> V_17 . V_161 = F_43 ;
if ( V_124 -> V_162 == V_163 )
V_6 -> V_17 . V_104 . V_105 = V_164 ;
else if ( ( V_124 -> V_162 == V_165 ) ||
( V_124 -> V_162 == V_166 ) ) {
V_6 -> V_17 . V_104 . V_69 = 3 ;
V_6 -> V_17 . V_104 . V_107 = 512 ;
V_6 -> V_17 . V_104 . V_167 = F_74 ;
V_6 -> V_17 . V_104 . V_168 = F_76 ;
V_6 -> V_17 . V_104 . V_169 = F_73 ;
V_6 -> V_17 . V_104 . V_105 = V_106 ;
}
if ( F_95 ( & V_6 -> V_2 , 1 , NULL ) ) {
V_6 -> V_17 . V_26 ^= V_27 ;
if ( F_95 ( & V_6 -> V_2 , 1 , NULL ) ) {
V_125 = - V_170 ;
goto V_145;
}
}
if ( V_124 -> V_162 == V_166 ) {
if ( V_6 -> V_17 . V_26 & V_27 )
V_126 = 2 ;
else {
V_126 = 1 ;
V_6 -> V_17 . V_171 = & V_172 ;
}
V_173 . V_174 = 3 * ( V_6 -> V_2 . V_67 / 16 ) ;
for ( V_31 = 0 ; V_31 < V_173 . V_174 ; V_31 ++ )
V_173 . V_175 [ V_31 ] = V_31 + V_126 ;
V_173 . V_176 -> V_126 = V_126 + V_173 . V_174 ;
V_173 . V_176 -> V_177 = V_6 -> V_2 . V_67 -
( V_126 + V_173 . V_174 ) ;
V_6 -> V_17 . V_104 . V_178 = & V_173 ;
}
if ( F_96 ( & V_6 -> V_2 ) ) {
V_125 = - V_170 ;
goto V_145;
}
V_125 = F_97 ( & V_6 -> V_2 , V_179 , & V_6 -> V_180 , 0 ) ;
if ( V_125 > 0 )
F_98 ( & V_6 -> V_2 , V_6 -> V_180 , V_125 ) ;
else if ( V_124 -> V_180 )
F_98 ( & V_6 -> V_2 , V_124 -> V_180 , V_124 -> V_181 ) ;
else
F_98 ( & V_6 -> V_2 , NULL , 0 ) ;
F_85 ( V_55 , & V_6 -> V_2 ) ;
return 0 ;
V_145:
F_99 ( V_6 -> V_59 , V_141 ) ;
V_144:
F_100 ( V_6 ) ;
return V_125 ;
}
static int F_101 ( struct V_122 * V_55 )
{
struct V_1 * V_2 = F_102 ( V_55 ) ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
F_85 ( V_55 , NULL ) ;
if ( V_6 -> V_57 != - 1 )
F_103 ( V_6 -> V_57 ) ;
if ( V_6 -> V_158 )
F_104 ( V_6 -> V_158 , V_6 ) ;
F_105 ( & V_6 -> V_2 ) ;
F_106 ( V_6 -> V_17 . V_19 ) ;
F_100 ( & V_6 -> V_2 ) ;
return 0 ;
}
static int T_10 F_107 ( void )
{
F_108 ( L_13 , V_182 ) ;
return F_109 ( & V_183 ) ;
}
static void T_11 F_110 ( void )
{
F_111 ( & V_183 ) ;
}
