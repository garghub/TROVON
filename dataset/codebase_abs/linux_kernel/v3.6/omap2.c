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
static void F_21 ( void * V_37 )
{
F_22 ( (struct V_38 * ) V_37 ) ;
}
static inline int F_23 ( struct V_1 * V_2 , void * V_39 ,
unsigned int V_15 , int V_40 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
struct V_41 * V_42 ;
enum V_43 V_44 = V_40 ? V_45 :
V_46 ;
struct V_47 V_48 ;
unsigned long V_32 , V_33 ;
unsigned V_49 ;
int V_25 ;
if ( V_39 >= V_50 ) {
struct V_51 * V_52 ;
if ( ( ( V_53 ) V_39 & V_54 ) !=
( ( V_53 ) ( V_39 + V_15 - 1 ) & V_54 ) )
goto V_55;
V_52 = F_24 ( V_39 ) ;
if ( ! V_52 )
goto V_55;
V_39 = F_25 ( V_52 ) + ( ( V_53 ) V_39 & ~ V_54 ) ;
}
F_26 ( & V_48 , V_39 , V_15 ) ;
V_49 = F_27 ( V_6 -> V_56 -> V_57 -> V_58 , & V_48 , 1 , V_44 ) ;
if ( V_49 == 0 ) {
F_28 ( & V_6 -> V_59 -> V_58 ,
L_1 , V_15 ) ;
goto V_55;
}
V_42 = F_29 ( V_6 -> V_56 , & V_48 , V_49 ,
V_40 ? V_60 : V_61 ,
V_62 | V_63 ) ;
if ( ! V_42 )
goto V_64;
V_42 -> V_65 = F_21 ;
V_42 -> V_66 = & V_6 -> V_67 ;
F_30 ( V_42 ) ;
V_25 = F_14 ( V_6 -> V_9 ,
V_28 , 0x1 , V_15 , V_40 ) ;
if ( V_25 )
goto V_64;
F_31 ( & V_6 -> V_67 ) ;
F_32 ( V_6 -> V_56 ) ;
F_33 ( & V_6 -> V_67 ) ;
V_32 = 0 ;
V_33 = ( V_34 * F_19 ( V_35 ) ) ;
while ( F_8 ( V_36 ) && ( V_32 ++ < V_33 ) )
F_20 () ;
F_16 ( V_6 -> V_9 ) ;
F_34 ( V_6 -> V_56 -> V_57 -> V_58 , & V_48 , 1 , V_44 ) ;
return 0 ;
V_64:
F_34 ( V_6 -> V_56 -> V_57 -> V_58 , & V_48 , 1 , V_44 ) ;
V_55:
if ( V_6 -> V_17 . V_26 & V_27 )
V_40 == 0 ? F_9 ( V_2 , ( T_1 * ) V_39 , V_15 )
: F_11 ( V_2 , ( T_1 * ) V_39 , V_15 ) ;
else
V_40 == 0 ? F_4 ( V_2 , ( T_1 * ) V_39 , V_15 )
: F_6 ( V_2 , ( T_1 * ) V_39 , V_15 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 , T_1 * V_14 , int V_15 )
{
if ( V_15 <= V_2 -> V_68 )
F_13 ( V_2 , V_14 , V_15 ) ;
else
F_23 ( V_2 , V_14 , V_15 , 0x0 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
const T_1 * V_14 , int V_15 )
{
if ( V_15 <= V_2 -> V_68 )
F_17 ( V_2 , V_14 , V_15 ) ;
else
F_23 ( V_2 , ( T_1 * ) V_14 , V_15 , 0x1 ) ;
}
static T_5 F_37 ( int V_69 , void * V_58 )
{
struct V_5 * V_6 = (struct V_5 * ) V_58 ;
T_2 V_70 ;
T_2 V_71 ;
V_71 = F_8 ( V_72 ) ;
V_70 = F_8 ( V_29 ) ;
V_70 = V_70 & 0xFFFC ;
if ( V_6 -> V_73 == V_74 ) {
if ( V_71 & 0x2 )
goto V_75;
if ( V_6 -> V_76 && ( V_6 -> V_76 < V_70 ) )
V_70 = V_6 -> V_76 ;
else if ( ! V_6 -> V_76 )
V_70 = 0 ;
F_38 ( V_6 -> V_17 . V_22 ,
( T_2 * ) V_6 -> V_14 , V_70 >> 2 ) ;
V_6 -> V_14 = V_6 -> V_14 + V_70 ;
V_6 -> V_76 -= V_70 ;
} else {
F_15 ( V_6 -> V_17 . V_19 ,
( T_2 * ) V_6 -> V_14 , V_70 >> 2 ) ;
V_6 -> V_14 = V_6 -> V_14 + V_70 ;
if ( V_71 & 0x2 )
goto V_75;
}
F_39 ( V_6 -> V_9 , V_77 , V_71 ) ;
return V_78 ;
V_75:
F_22 ( & V_6 -> V_67 ) ;
F_39 ( V_6 -> V_9 , V_79 , 0 ) ;
F_39 ( V_6 -> V_9 , V_77 , V_71 ) ;
return V_78 ;
}
static void F_40 ( struct V_1 * V_2 , T_1 * V_14 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
int V_25 = 0 ;
if ( V_15 <= V_2 -> V_68 ) {
F_13 ( V_2 , V_14 , V_15 ) ;
return;
}
V_6 -> V_73 = V_80 ;
V_6 -> V_14 = V_14 ;
F_31 ( & V_6 -> V_67 ) ;
V_25 = F_14 ( V_6 -> V_9 ,
V_28 / 2 , 0x0 , V_15 , 0x0 ) ;
if ( V_25 )
goto V_55;
V_6 -> V_76 = V_15 ;
F_39 ( V_6 -> V_9 , V_79 ,
( V_81 | V_82 ) ) ;
F_33 ( & V_6 -> V_67 ) ;
F_16 ( V_6 -> V_9 ) ;
return;
V_55:
if ( V_6 -> V_17 . V_26 & V_27 )
F_9 ( V_2 , V_14 , V_15 ) ;
else
F_4 ( V_2 , V_14 , V_15 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
const T_1 * V_14 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ,
struct V_5 , V_2 ) ;
int V_25 = 0 ;
unsigned long V_32 , V_33 ;
if ( V_15 <= V_2 -> V_68 ) {
F_17 ( V_2 , V_14 , V_15 ) ;
return;
}
V_6 -> V_73 = V_74 ;
V_6 -> V_14 = ( T_1 * ) V_14 ;
F_31 ( & V_6 -> V_67 ) ;
V_25 = F_14 ( V_6 -> V_9 ,
( V_28 * 3 ) / 8 , 0x0 , V_15 , 0x1 ) ;
if ( V_25 )
goto V_55;
V_6 -> V_76 = V_15 ;
F_39 ( V_6 -> V_9 , V_79 ,
( V_81 | V_82 ) ) ;
F_33 ( & V_6 -> V_67 ) ;
V_32 = 0 ;
V_33 = ( V_34 * F_19 ( V_35 ) ) ;
while ( F_8 ( V_36 ) && ( V_32 ++ < V_33 ) )
F_20 () ;
F_16 ( V_6 -> V_9 ) ;
return;
V_55:
if ( V_6 -> V_17 . V_26 & V_27 )
F_11 ( V_2 , V_14 , V_15 ) ;
else
F_6 ( V_2 , V_14 , V_15 ) ;
}
static int F_42 ( struct V_1 * V_2 , const T_1 * V_14 , int V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
T_3 * V_20 = ( T_3 * ) V_14 ;
V_15 >>= 1 ;
while ( V_15 -- ) {
if ( * V_20 ++ != F_43 ( F_44 ( V_6 -> V_17 . V_19 ) ) )
return - V_83 ;
}
return 0 ;
}
static void F_45 ( T_6 * V_84 )
{
T_2 V_85 = V_84 [ 0 ] | ( V_84 [ 1 ] << 16 ) |
( ( V_84 [ 2 ] & 0xF0 ) << 20 ) | ( ( V_84 [ 2 ] & 0x0F ) << 8 ) ;
V_84 [ 0 ] = ~ ( F_46 ( V_85 ) | F_47 ( V_85 ) | F_48 ( V_85 ) | F_49 ( V_85 ) |
F_50 ( V_85 ) | F_51 ( V_85 ) | F_52 ( V_85 ) | F_53 ( V_85 ) ) ;
V_84 [ 1 ] = ~ ( F_54 ( V_85 ) | F_55 ( V_85 ) | F_56 ( V_85 ) | F_57 ( V_85 ) |
F_58 ( V_85 ) | F_59 ( V_85 ) | F_60 ( V_85 ) | F_61 ( V_85 ) ) ;
V_84 [ 2 ] = ~ ( F_62 ( V_85 ) | F_63 ( V_85 ) | F_64 ( V_85 ) | F_65 ( V_85 ) | F_66 ( V_85 ) |
F_67 ( V_85 ) | F_68 ( V_85 ) | F_69 ( V_85 ) ) ;
}
static int F_70 ( T_6 * V_86 ,
T_6 * V_87 ,
T_6 * V_88 )
{
T_7 V_31 ;
T_6 V_89 [ 8 ] , V_90 [ 8 ] , V_91 [ 8 ] ;
T_6 V_92 [ 8 ] , V_93 [ 8 ] , V_94 [ 8 ] ;
T_6 V_95 [ 24 ] ;
T_6 V_96 = 0 ;
T_6 V_97 = 0 ;
T_7 V_98 = 0 ;
int V_99 ;
V_99 = ( ( * ( T_2 * ) V_86 & 0xFFFFFF ) == 0xFFFFFF ) ;
F_45 ( V_86 ) ;
F_45 ( V_87 ) ;
for ( V_31 = 0 ; V_31 <= 2 ; V_31 ++ ) {
* ( V_86 + V_31 ) = ~ ( * ( V_86 + V_31 ) ) ;
* ( V_87 + V_31 ) = ~ ( * ( V_87 + V_31 ) ) ;
}
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
V_89 [ V_31 ] = * V_86 % 2 ;
* V_86 = * V_86 / 2 ;
}
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
V_90 [ V_31 ] = * ( V_86 + 1 ) % 2 ;
* ( V_86 + 1 ) = * ( V_86 + 1 ) / 2 ;
}
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
V_91 [ V_31 ] = * ( V_86 + 2 ) % 2 ;
* ( V_86 + 2 ) = * ( V_86 + 2 ) / 2 ;
}
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
V_92 [ V_31 ] = * V_87 % 2 ;
* V_87 = * V_87 / 2 ;
}
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
V_93 [ V_31 ] = * ( V_87 + 1 ) % 2 ;
* ( V_87 + 1 ) = * ( V_87 + 1 ) / 2 ;
}
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ ) {
V_94 [ V_31 ] = * ( V_87 + 2 ) % 2 ;
* ( V_87 + 2 ) = * ( V_87 + 2 ) / 2 ;
}
for ( V_31 = 0 ; V_31 < 6 ; V_31 ++ )
V_95 [ V_31 ] = V_91 [ V_31 + 2 ] ^ V_94 [ V_31 + 2 ] ;
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ )
V_95 [ V_31 + 6 ] = V_89 [ V_31 ] ^ V_92 [ V_31 ] ;
for ( V_31 = 0 ; V_31 < 8 ; V_31 ++ )
V_95 [ V_31 + 14 ] = V_90 [ V_31 ] ^ V_93 [ V_31 ] ;
V_95 [ 22 ] = V_91 [ 0 ] ^ V_94 [ 0 ] ;
V_95 [ 23 ] = V_91 [ 1 ] ^ V_94 [ 1 ] ;
for ( V_31 = 0 ; V_31 < 24 ; V_31 ++ )
V_96 += V_95 [ V_31 ] ;
switch ( V_96 ) {
case 0 :
return 0 ;
case 1 :
F_71 ( L_2 ) ;
return - 1 ;
case 11 :
F_71 ( L_3 ) ;
return - 1 ;
case 12 :
V_98 = ( V_95 [ 23 ] << 8 ) +
( V_95 [ 21 ] << 7 ) +
( V_95 [ 19 ] << 6 ) +
( V_95 [ 17 ] << 5 ) +
( V_95 [ 15 ] << 4 ) +
( V_95 [ 13 ] << 3 ) +
( V_95 [ 11 ] << 2 ) +
( V_95 [ 9 ] << 1 ) +
V_95 [ 7 ] ;
V_97 = ( V_95 [ 5 ] << 2 ) + ( V_95 [ 3 ] << 1 ) + V_95 [ 1 ] ;
F_71 ( L_4
L_5 , V_98 , V_97 ) ;
V_88 [ V_98 ] ^= ( 1 << V_97 ) ;
return 1 ;
default:
if ( V_99 ) {
if ( V_87 [ 0 ] == 0 &&
V_87 [ 1 ] == 0 &&
V_87 [ 2 ] == 0 )
return 0 ;
}
F_71 ( L_6 ) ;
return - 1 ;
}
}
static int F_72 ( struct V_1 * V_2 , T_1 * V_100 ,
T_1 * V_101 , T_1 * V_102 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
int V_103 = 0 , V_31 = 0 , V_25 = 0 ;
int V_104 = 0 ;
if ( ( V_6 -> V_17 . V_105 . V_106 == V_107 ) &&
( V_6 -> V_17 . V_105 . V_108 == 2048 ) )
V_103 = 4 ;
else
V_103 = 1 ;
for ( V_31 = 0 ; V_31 < V_103 ; V_31 ++ ) {
if ( memcmp ( V_101 , V_102 , 3 ) != 0 ) {
V_25 = F_70 ( V_101 , V_102 , V_100 ) ;
if ( V_25 < 0 )
return V_25 ;
V_104 += V_25 ;
}
V_101 += 3 ;
V_102 += 3 ;
V_100 += 512 ;
}
return V_104 ;
}
static int F_73 ( struct V_1 * V_2 , const T_1 * V_100 ,
T_1 * V_109 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
return F_74 ( V_6 -> V_9 , V_100 , V_109 ) ;
}
static void F_75 ( struct V_1 * V_2 , int V_106 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
struct V_16 * V_110 = V_2 -> V_18 ;
unsigned int V_111 = ( V_110 -> V_26 & V_27 ) ? 1 : 0 ;
F_76 ( V_6 -> V_9 , V_106 , V_111 , V_6 -> V_17 . V_105 . V_108 ) ;
}
static int F_77 ( struct V_1 * V_2 , struct V_16 * V_110 )
{
struct V_16 * V_112 = V_2 -> V_18 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
unsigned long V_113 = V_114 ;
int V_21 , V_115 = V_112 -> V_115 ;
if ( V_115 == V_116 )
V_113 += ( V_117 * 400 ) / 1000 ;
else
V_113 += ( V_117 * 20 ) / 1000 ;
F_3 ( V_6 -> V_9 ,
V_10 , ( V_118 & 0xFF ) ) ;
while ( F_78 ( V_114 , V_113 ) ) {
V_21 = F_79 ( V_6 -> V_9 , V_13 ) ;
if ( V_21 & V_119 )
break;
F_80 () ;
}
V_21 = F_79 ( V_6 -> V_9 , V_13 ) ;
return V_21 ;
}
static int F_81 ( struct V_1 * V_2 )
{
unsigned int V_120 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
V_120 = F_8 ( V_72 ) ;
if ( ( V_120 & 0x100 ) == 0x100 ) {
V_120 |= 0x100 ;
V_120 &= ~ ( 0x0 ) ;
F_39 ( V_6 -> V_9 , V_77 , V_120 ) ;
} else {
unsigned int V_121 = 0 ;
while ( V_121 ++ < 0x1FF ) {
if ( ( V_120 & 0x100 ) == 0x100 )
return 0 ;
V_120 = F_8 ( V_72 ) ;
}
}
return 1 ;
}
static void F_82 ( struct V_1 * V_2 , int V_106 )
{
int V_122 ;
unsigned int V_111 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
struct V_16 * V_110 = V_2 -> V_18 ;
V_122 = ( V_6 -> V_17 . V_105 . V_70 == 13 ) ? 8 : 4 ;
V_111 = ( V_110 -> V_26 & V_27 ) ? 1 : 0 ;
( void ) F_83 ( V_6 -> V_9 , V_106 , V_111 , 1 , V_122 ) ;
}
static int F_84 ( struct V_1 * V_2 , const T_1 * V_100 ,
T_1 * V_109 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
return F_85 ( V_6 -> V_9 , V_100 , V_109 ) ;
}
static int F_86 ( struct V_1 * V_2 , const T_1 * V_100 ,
T_1 * V_109 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
return F_87 ( V_6 -> V_9 , V_100 , V_109 ) ;
}
static int F_88 ( struct V_1 * V_2 , T_1 * V_37 ,
T_1 * V_101 , T_1 * V_102 )
{
int V_31 , V_123 ;
unsigned int V_124 [ 8 ] ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
V_123 = F_89 ( V_6 -> V_125 , NULL , 512 , V_101 , V_102 , NULL ,
V_124 ) ;
if ( V_123 > 0 ) {
for ( V_31 = 0 ; V_31 < V_123 ; V_31 ++ ) {
if ( V_124 [ V_31 ] < 8 * 512 )
V_37 [ V_124 [ V_31 ] / 8 ] ^= 1 << ( V_124 [ V_31 ] & 7 ) ;
F_71 ( L_7 , V_124 [ V_31 ] ) ;
}
} else if ( V_123 < 0 ) {
F_90 ( L_8 ) ;
}
return V_123 ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
if ( V_6 -> V_125 ) {
F_92 ( V_6 -> V_125 ) ;
V_6 -> V_125 = NULL ;
}
}
static int F_93 ( struct V_1 * V_2 , int V_126 )
{
int V_25 , V_127 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
#ifdef F_94
const int V_128 = 8 ;
#else
const int V_128 = 4 ;
#endif
V_6 -> V_125 = NULL ;
V_127 = ( V_126 == V_129 ) ? 8 : 4 ;
if ( V_127 != V_128 ) {
F_90 ( L_9 ,
V_127 , V_128 ) ;
goto V_130;
}
V_25 = F_95 ( V_6 -> V_9 , 1 , V_127 ) ;
if ( V_25 )
goto V_130;
V_6 -> V_125 = F_96 ( 13 , V_127 , 0x201b ) ;
if ( ! V_6 -> V_125 )
goto V_130;
V_6 -> V_17 . V_105 . V_108 = 512 ;
V_6 -> V_17 . V_105 . V_131 = F_82 ;
V_6 -> V_17 . V_105 . V_132 = F_88 ;
V_6 -> V_17 . V_105 . V_106 = V_107 ;
if ( V_127 == 8 ) {
V_6 -> V_17 . V_105 . V_133 = 8 ;
V_6 -> V_17 . V_105 . V_70 = 13 ;
V_6 -> V_17 . V_105 . V_134 = F_86 ;
} else {
V_6 -> V_17 . V_105 . V_133 = 4 ;
V_6 -> V_17 . V_105 . V_70 = 7 ;
V_6 -> V_17 . V_105 . V_134 = F_84 ;
}
F_97 ( L_10 , V_127 ) ;
return 0 ;
V_130:
F_91 ( V_2 ) ;
return - 1 ;
}
static int F_98 ( struct V_1 * V_2 )
{
int V_31 , V_135 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
struct V_136 * V_137 = & V_6 -> V_138 ;
V_135 = V_2 -> V_139 / V_6 -> V_17 . V_105 . V_108 ;
V_137 -> V_140 = V_135 * V_6 -> V_17 . V_105 . V_70 ;
if ( V_2 -> V_68 < 64 ) {
F_90 ( L_11 ) ;
goto V_130;
}
if ( V_137 -> V_140 + 2 > V_2 -> V_68 ) {
F_90 ( L_12 ,
V_2 -> V_68 , V_137 -> V_140 ) ;
goto V_130;
}
for ( V_31 = 0 ; V_31 < V_137 -> V_140 ; V_31 ++ )
V_137 -> V_141 [ V_31 ] = V_2 -> V_68 - V_137 -> V_140 + V_31 ;
V_137 -> V_142 [ 0 ] . V_143 = 2 ;
V_137 -> V_142 [ 0 ] . V_144 = V_2 -> V_68 - 2 - V_137 -> V_140 ;
V_6 -> V_17 . V_105 . V_137 = V_137 ;
if ( ! ( V_6 -> V_17 . V_26 & V_27 ) )
V_6 -> V_17 . V_145 = & V_146 ;
return 0 ;
V_130:
F_91 ( V_2 ) ;
return - 1 ;
}
static int F_93 ( struct V_1 * V_2 , int V_126 )
{
F_90 ( L_13 ) ;
return - 1 ;
}
static int F_98 ( struct V_1 * V_2 )
{
return - 1 ;
}
static void F_91 ( struct V_1 * V_2 )
{
}
static int T_8 F_99 ( struct V_147 * V_59 )
{
struct V_5 * V_6 ;
struct V_148 * V_149 ;
int V_150 ;
int V_31 , V_143 ;
T_9 V_151 ;
unsigned V_152 ;
V_149 = V_59 -> V_58 . V_153 ;
if ( V_149 == NULL ) {
F_28 ( & V_59 -> V_58 , L_14 ) ;
return - V_154 ;
}
V_6 = F_100 ( sizeof( struct V_5 ) , V_155 ) ;
if ( ! V_6 )
return - V_156 ;
F_101 ( V_59 , V_6 ) ;
F_102 ( & V_6 -> V_157 . V_158 ) ;
F_103 ( & V_6 -> V_157 . V_159 ) ;
V_6 -> V_59 = V_59 ;
V_6 -> V_9 = V_149 -> V_160 ;
V_6 -> V_161 = V_149 -> V_161 ;
V_6 -> V_2 . V_18 = & V_6 -> V_17 ;
V_6 -> V_2 . V_162 = F_104 ( & V_59 -> V_58 ) ;
V_6 -> V_2 . V_163 = V_164 ;
V_6 -> V_17 . V_26 = V_149 -> V_165 ;
V_6 -> V_17 . V_26 |= V_166 ;
F_39 ( V_6 -> V_9 , V_167 , 0 ) ;
if ( ! F_105 ( V_6 -> V_161 , V_168 ,
V_59 -> V_58 . V_169 -> V_162 ) ) {
V_150 = - V_170 ;
goto V_171;
}
V_6 -> V_17 . V_19 = F_106 ( V_6 -> V_161 , V_168 ) ;
if ( ! V_6 -> V_17 . V_19 ) {
V_150 = - V_156 ;
goto V_172;
}
V_6 -> V_17 . V_157 = & V_6 -> V_157 ;
V_6 -> V_17 . V_22 = V_6 -> V_17 . V_19 ;
V_6 -> V_17 . V_173 = F_1 ;
if ( V_149 -> V_174 ) {
V_6 -> V_17 . V_174 = F_81 ;
V_6 -> V_17 . V_175 = 0 ;
} else {
V_6 -> V_17 . V_176 = F_77 ;
V_6 -> V_17 . V_175 = 50 ;
}
switch ( V_149 -> V_177 ) {
case V_178 :
V_6 -> V_17 . V_179 = F_13 ;
V_6 -> V_17 . V_180 = F_17 ;
break;
case V_181 :
if ( V_6 -> V_17 . V_26 & V_27 ) {
V_6 -> V_17 . V_179 = F_9 ;
V_6 -> V_17 . V_180 = F_11 ;
} else {
V_6 -> V_17 . V_179 = F_4 ;
V_6 -> V_17 . V_180 = F_6 ;
}
break;
case V_182 :
F_107 ( V_151 ) ;
F_108 ( V_183 , V_151 ) ;
V_152 = V_184 ;
V_6 -> V_56 = F_109 ( V_151 , V_185 , & V_152 ) ;
if ( ! V_6 -> V_56 ) {
F_28 ( & V_59 -> V_58 , L_15 ) ;
V_150 = - V_186 ;
goto V_172;
} else {
struct V_187 V_188 ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_188 . V_189 = V_6 -> V_161 ;
V_188 . V_190 = V_6 -> V_161 ;
V_188 . V_191 = V_192 ;
V_188 . V_193 = V_192 ;
V_188 . V_194 = 16 ;
V_188 . V_195 = 16 ;
V_150 = F_110 ( V_6 -> V_56 , & V_188 ) ;
if ( V_150 ) {
F_28 ( & V_59 -> V_58 , L_16 ,
V_150 ) ;
goto V_172;
}
V_6 -> V_17 . V_179 = F_35 ;
V_6 -> V_17 . V_180 = F_36 ;
}
break;
case V_196 :
V_150 = F_111 ( V_149 -> V_197 ,
F_37 , V_198 , L_17 , V_6 ) ;
if ( V_150 ) {
F_28 ( & V_59 -> V_58 , L_18 ,
V_149 -> V_197 , V_150 ) ;
goto V_172;
} else {
V_6 -> V_197 = V_149 -> V_197 ;
V_6 -> V_17 . V_179 = F_40 ;
V_6 -> V_17 . V_180 = F_41 ;
}
break;
default:
F_28 ( & V_59 -> V_58 ,
L_19 , V_149 -> V_177 ) ;
V_150 = - V_199 ;
goto V_172;
}
V_6 -> V_17 . V_200 = F_42 ;
if ( V_149 -> V_126 == V_201 )
V_6 -> V_17 . V_105 . V_106 = V_202 ;
else if ( ( V_149 -> V_126 == V_203 ) ||
( V_149 -> V_126 == V_204 ) ) {
V_6 -> V_17 . V_105 . V_70 = 3 ;
V_6 -> V_17 . V_105 . V_108 = 512 ;
V_6 -> V_17 . V_105 . V_133 = 1 ;
V_6 -> V_17 . V_105 . V_134 = F_73 ;
V_6 -> V_17 . V_105 . V_131 = F_75 ;
V_6 -> V_17 . V_105 . V_132 = F_72 ;
V_6 -> V_17 . V_105 . V_106 = V_107 ;
} else if ( ( V_149 -> V_126 == V_205 ) ||
( V_149 -> V_126 == V_129 ) ) {
V_150 = F_93 ( & V_6 -> V_2 , V_149 -> V_126 ) ;
if ( V_150 ) {
V_150 = - V_199 ;
goto V_172;
}
}
if ( F_112 ( & V_6 -> V_2 , 1 , NULL ) ) {
V_6 -> V_17 . V_26 ^= V_27 ;
if ( F_112 ( & V_6 -> V_2 , 1 , NULL ) ) {
V_150 = - V_186 ;
goto V_172;
}
}
if ( V_149 -> V_126 == V_204 ) {
if ( V_6 -> V_17 . V_26 & V_27 )
V_143 = 2 ;
else {
V_143 = 1 ;
V_6 -> V_17 . V_145 = & V_146 ;
}
V_206 . V_140 = 3 * ( V_6 -> V_2 . V_68 / 16 ) ;
for ( V_31 = 0 ; V_31 < V_206 . V_140 ; V_31 ++ )
V_206 . V_141 [ V_31 ] = V_31 + V_143 ;
V_206 . V_142 -> V_143 = V_143 + V_206 . V_140 ;
V_206 . V_142 -> V_144 = V_6 -> V_2 . V_68 -
( V_143 + V_206 . V_140 ) ;
V_6 -> V_17 . V_105 . V_137 = & V_206 ;
} else if ( ( V_149 -> V_126 == V_205 ) ||
( V_149 -> V_126 == V_129 ) ) {
V_150 = F_98 ( & V_6 -> V_2 ) ;
if ( V_150 ) {
V_150 = - V_199 ;
goto V_172;
}
}
if ( F_113 ( & V_6 -> V_2 ) ) {
V_150 = - V_186 ;
goto V_172;
}
F_114 ( & V_6 -> V_2 , NULL , NULL , V_149 -> V_207 ,
V_149 -> V_208 ) ;
F_101 ( V_59 , & V_6 -> V_2 ) ;
return 0 ;
V_172:
if ( V_6 -> V_56 )
F_115 ( V_6 -> V_56 ) ;
F_116 ( V_6 -> V_161 , V_168 ) ;
V_171:
F_117 ( V_6 ) ;
return V_150 ;
}
static int F_118 ( struct V_147 * V_59 )
{
struct V_1 * V_2 = F_119 ( V_59 ) ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 ,
V_2 ) ;
F_91 ( & V_6 -> V_2 ) ;
F_101 ( V_59 , NULL ) ;
if ( V_6 -> V_56 )
F_115 ( V_6 -> V_56 ) ;
if ( V_6 -> V_197 )
F_120 ( V_6 -> V_197 , V_6 ) ;
F_121 ( & V_6 -> V_2 ) ;
F_122 ( V_6 -> V_17 . V_19 ) ;
F_117 ( & V_6 -> V_2 ) ;
return 0 ;
}
