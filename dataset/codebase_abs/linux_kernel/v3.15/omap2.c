static int F_1 ( int V_1 , int V_2 , int V_3 ,
unsigned int V_4 , int V_5 , struct V_6 * V_7 )
{
T_1 V_8 ;
if ( V_2 > V_9 )
return - 1 ;
if ( F_2 ( V_7 -> V_10 . V_11 ) )
return - V_12 ;
F_3 ( V_4 , V_7 -> V_10 . V_13 ) ;
V_8 = ( ( V_1 << V_14 ) |
F_4 ( V_2 ) | V_15 |
( V_3 << V_16 ) | ( 0x1 & V_5 ) ) ;
F_3 ( V_8 , V_7 -> V_10 . V_17 ) ;
F_3 ( 0x1 , V_7 -> V_10 . V_11 ) ;
return 0 ;
}
static int F_5 ( int V_1 , struct V_6 * V_7 )
{
T_1 V_18 ;
V_18 = F_2 ( V_7 -> V_10 . V_17 ) ;
if ( ( ( V_18 >> V_14 ) & V_19 ) != V_1 )
return - V_20 ;
F_3 ( 0x0 , V_7 -> V_10 . V_11 ) ;
F_3 ( 0x0 , V_7 -> V_10 . V_17 ) ;
return 0 ;
}
static void F_6 ( struct V_21 * V_22 , int V_23 , unsigned int V_24 )
{
struct V_6 * V_7 = F_7 ( V_22 ,
struct V_6 , V_22 ) ;
if ( V_23 != V_25 ) {
if ( V_24 & V_26 )
F_8 ( V_23 , V_7 -> V_10 . V_27 ) ;
else if ( V_24 & V_28 )
F_8 ( V_23 , V_7 -> V_10 . V_29 ) ;
else
F_8 ( V_23 , V_7 -> V_10 . V_30 ) ;
}
}
static void F_9 ( struct V_21 * V_22 , T_2 * V_31 , int V_32 )
{
struct V_33 * V_34 = V_22 -> V_35 ;
F_10 ( V_34 -> V_36 , V_31 , V_32 ) ;
}
static void F_11 ( struct V_21 * V_22 , const T_2 * V_31 , int V_32 )
{
struct V_6 * V_7 = F_7 ( V_22 ,
struct V_6 , V_22 ) ;
T_2 * V_37 = ( T_2 * ) V_31 ;
T_1 V_38 = 0 ;
while ( V_32 -- ) {
F_12 ( * V_37 ++ , V_7 -> V_34 . V_39 ) ;
do {
V_38 = F_2 ( V_7 -> V_10 . V_40 ) &
V_41 ;
} while ( ! V_38 );
}
}
static void F_13 ( struct V_21 * V_22 , T_2 * V_31 , int V_32 )
{
struct V_33 * V_34 = V_22 -> V_35 ;
F_14 ( V_34 -> V_36 , V_31 , V_32 / 2 ) ;
}
static void F_15 ( struct V_21 * V_22 , const T_2 * V_31 , int V_32 )
{
struct V_6 * V_7 = F_7 ( V_22 ,
struct V_6 , V_22 ) ;
T_3 * V_37 = ( T_3 * ) V_31 ;
T_1 V_38 = 0 ;
V_32 >>= 1 ;
while ( V_32 -- ) {
F_16 ( * V_37 ++ , V_7 -> V_34 . V_39 ) ;
do {
V_38 = F_2 ( V_7 -> V_10 . V_40 ) &
V_41 ;
} while ( ! V_38 );
}
}
static void F_17 ( struct V_21 * V_22 , T_2 * V_31 , int V_32 )
{
struct V_6 * V_7 = F_7 ( V_22 ,
struct V_6 , V_22 ) ;
T_4 V_42 = 0 ;
int V_43 = 0 ;
T_1 * V_37 = ( T_1 * ) V_31 ;
if ( V_32 % 4 ) {
if ( V_7 -> V_34 . V_44 & V_45 )
F_13 ( V_22 , V_31 , V_32 % 4 ) ;
else
F_9 ( V_22 , V_31 , V_32 % 4 ) ;
V_37 = ( T_1 * ) ( V_31 + V_32 % 4 ) ;
V_32 -= V_32 % 4 ;
}
V_43 = F_1 ( V_7 -> V_46 ,
V_9 , 0x0 , V_32 , 0x0 , V_7 ) ;
if ( V_43 ) {
if ( V_7 -> V_34 . V_44 & V_45 )
F_13 ( V_22 , ( T_2 * ) V_37 , V_32 ) ;
else
F_9 ( V_22 , ( T_2 * ) V_37 , V_32 ) ;
} else {
do {
V_42 = F_2 ( V_7 -> V_10 . V_47 ) ;
V_42 = F_18 ( V_42 ) ;
V_42 = V_42 >> 2 ;
F_19 ( V_7 -> V_34 . V_36 , V_37 , V_42 ) ;
V_37 += V_42 ;
V_32 -= V_42 << 2 ;
} while ( V_32 );
F_5 ( V_7 -> V_46 , V_7 ) ;
}
}
static void F_20 ( struct V_21 * V_22 ,
const T_2 * V_31 , int V_32 )
{
struct V_6 * V_7 = F_7 ( V_22 ,
struct V_6 , V_22 ) ;
T_4 V_48 = 0 ;
int V_49 = 0 , V_43 = 0 ;
T_3 * V_37 = ( T_3 * ) V_31 ;
unsigned long V_50 , V_51 ;
T_1 V_8 ;
if ( V_32 % 2 != 0 ) {
F_8 ( * V_31 , V_7 -> V_34 . V_39 ) ;
V_37 = ( T_3 * ) ( V_31 + 1 ) ;
V_32 -- ;
}
V_43 = F_1 ( V_7 -> V_46 ,
V_9 , 0x0 , V_32 , 0x1 , V_7 ) ;
if ( V_43 ) {
if ( V_7 -> V_34 . V_44 & V_45 )
F_15 ( V_22 , ( T_2 * ) V_37 , V_32 ) ;
else
F_11 ( V_22 , ( T_2 * ) V_37 , V_32 ) ;
} else {
while ( V_32 ) {
V_48 = F_2 ( V_7 -> V_10 . V_47 ) ;
V_48 = F_18 ( V_48 ) ;
V_48 = V_48 >> 1 ;
for ( V_49 = 0 ; ( V_49 < V_48 ) && V_32 ; V_49 ++ , V_32 -= 2 )
F_16 ( * V_37 ++ , V_7 -> V_34 . V_39 ) ;
}
V_50 = 0 ;
V_51 = ( V_52 *
F_21 ( V_53 ) ) ;
do {
F_22 () ;
V_8 = F_2 ( V_7 -> V_10 . V_47 ) ;
V_8 = F_23 ( V_8 ) ;
} while ( V_8 && ( V_50 ++ < V_51 ) );
F_5 ( V_7 -> V_46 , V_7 ) ;
}
}
static void F_24 ( void * V_54 )
{
F_25 ( (struct V_55 * ) V_54 ) ;
}
static inline int F_26 ( struct V_21 * V_22 , void * V_56 ,
unsigned int V_32 , int V_5 )
{
struct V_6 * V_7 = F_7 ( V_22 ,
struct V_6 , V_22 ) ;
struct V_57 * V_58 ;
enum V_59 V_60 = V_5 ? V_61 :
V_62 ;
struct V_63 V_64 ;
unsigned long V_50 , V_51 ;
unsigned V_65 ;
int V_43 ;
T_1 V_8 ;
if ( V_56 >= V_66 ) {
struct V_67 * V_68 ;
if ( ( ( V_69 ) V_56 & V_70 ) !=
( ( V_69 ) ( V_56 + V_32 - 1 ) & V_70 ) )
goto V_71;
V_68 = F_27 ( V_56 ) ;
if ( ! V_68 )
goto V_71;
V_56 = F_28 ( V_68 ) + ( ( V_69 ) V_56 & ~ V_70 ) ;
}
F_29 ( & V_64 , V_56 , V_32 ) ;
V_65 = F_30 ( V_7 -> V_72 -> V_73 -> V_74 , & V_64 , 1 , V_60 ) ;
if ( V_65 == 0 ) {
F_31 ( & V_7 -> V_75 -> V_74 ,
L_1 , V_32 ) ;
goto V_71;
}
V_58 = F_32 ( V_7 -> V_72 , & V_64 , V_65 ,
V_5 ? V_76 : V_77 ,
V_78 | V_79 ) ;
if ( ! V_58 )
goto V_80;
V_58 -> V_81 = F_24 ;
V_58 -> V_82 = & V_7 -> V_83 ;
F_33 ( V_58 ) ;
V_43 = F_1 ( V_7 -> V_46 ,
V_9 , 0x1 , V_32 , V_5 , V_7 ) ;
if ( V_43 )
goto V_80;
F_34 ( & V_7 -> V_83 ) ;
F_35 ( V_7 -> V_72 ) ;
F_36 ( & V_7 -> V_83 ) ;
V_50 = 0 ;
V_51 = ( V_52 * F_21 ( V_53 ) ) ;
do {
F_22 () ;
V_8 = F_2 ( V_7 -> V_10 . V_47 ) ;
V_8 = F_23 ( V_8 ) ;
} while ( V_8 && ( V_50 ++ < V_51 ) );
F_5 ( V_7 -> V_46 , V_7 ) ;
F_37 ( V_7 -> V_72 -> V_73 -> V_74 , & V_64 , 1 , V_60 ) ;
return 0 ;
V_80:
F_37 ( V_7 -> V_72 -> V_73 -> V_74 , & V_64 , 1 , V_60 ) ;
V_71:
if ( V_7 -> V_34 . V_44 & V_45 )
V_5 == 0 ? F_13 ( V_22 , ( T_2 * ) V_56 , V_32 )
: F_15 ( V_22 , ( T_2 * ) V_56 , V_32 ) ;
else
V_5 == 0 ? F_9 ( V_22 , ( T_2 * ) V_56 , V_32 )
: F_11 ( V_22 , ( T_2 * ) V_56 , V_32 ) ;
return 0 ;
}
static void F_38 ( struct V_21 * V_22 , T_2 * V_31 , int V_32 )
{
if ( V_32 <= V_22 -> V_84 )
F_17 ( V_22 , V_31 , V_32 ) ;
else
F_26 ( V_22 , V_31 , V_32 , 0x0 ) ;
}
static void F_39 ( struct V_21 * V_22 ,
const T_2 * V_31 , int V_32 )
{
if ( V_32 <= V_22 -> V_84 )
F_20 ( V_22 , V_31 , V_32 ) ;
else
F_26 ( V_22 , ( T_2 * ) V_31 , V_32 , 0x1 ) ;
}
static T_5 F_40 ( int V_85 , void * V_74 )
{
struct V_6 * V_7 = (struct V_6 * ) V_74 ;
T_1 V_86 ;
V_86 = F_2 ( V_7 -> V_10 . V_47 ) ;
V_86 = F_18 ( V_86 ) ;
V_86 = V_86 & 0xFFFC ;
if ( V_7 -> V_87 == V_88 ) {
if ( V_85 == V_7 -> V_89 )
goto V_90;
if ( V_7 -> V_91 && ( V_7 -> V_91 < V_86 ) )
V_86 = V_7 -> V_91 ;
else if ( ! V_7 -> V_91 )
V_86 = 0 ;
F_41 ( V_7 -> V_34 . V_39 ,
( T_1 * ) V_7 -> V_31 , V_86 >> 2 ) ;
V_7 -> V_31 = V_7 -> V_31 + V_86 ;
V_7 -> V_91 -= V_86 ;
} else {
F_19 ( V_7 -> V_34 . V_36 ,
( T_1 * ) V_7 -> V_31 , V_86 >> 2 ) ;
V_7 -> V_31 = V_7 -> V_31 + V_86 ;
if ( V_85 == V_7 -> V_89 )
goto V_90;
}
return V_92 ;
V_90:
F_25 ( & V_7 -> V_83 ) ;
F_42 ( V_7 -> V_93 ) ;
F_42 ( V_7 -> V_89 ) ;
return V_92 ;
}
static void F_43 ( struct V_21 * V_22 , T_2 * V_31 , int V_32 )
{
struct V_6 * V_7 = F_7 ( V_22 ,
struct V_6 , V_22 ) ;
int V_43 = 0 ;
if ( V_32 <= V_22 -> V_84 ) {
F_17 ( V_22 , V_31 , V_32 ) ;
return;
}
V_7 -> V_87 = V_94 ;
V_7 -> V_31 = V_31 ;
F_34 ( & V_7 -> V_83 ) ;
V_43 = F_1 ( V_7 -> V_46 ,
V_9 / 2 , 0x0 , V_32 , 0x0 , V_7 ) ;
if ( V_43 )
goto V_71;
V_7 -> V_91 = V_32 ;
F_44 ( V_7 -> V_89 ) ;
F_44 ( V_7 -> V_93 ) ;
F_36 ( & V_7 -> V_83 ) ;
F_5 ( V_7 -> V_46 , V_7 ) ;
return;
V_71:
if ( V_7 -> V_34 . V_44 & V_45 )
F_13 ( V_22 , V_31 , V_32 ) ;
else
F_9 ( V_22 , V_31 , V_32 ) ;
}
static void F_45 ( struct V_21 * V_22 ,
const T_2 * V_31 , int V_32 )
{
struct V_6 * V_7 = F_7 ( V_22 ,
struct V_6 , V_22 ) ;
int V_43 = 0 ;
unsigned long V_50 , V_51 ;
T_1 V_8 ;
if ( V_32 <= V_22 -> V_84 ) {
F_20 ( V_22 , V_31 , V_32 ) ;
return;
}
V_7 -> V_87 = V_88 ;
V_7 -> V_31 = ( T_2 * ) V_31 ;
F_34 ( & V_7 -> V_83 ) ;
V_43 = F_1 ( V_7 -> V_46 ,
( V_9 * 3 ) / 8 , 0x0 , V_32 , 0x1 , V_7 ) ;
if ( V_43 )
goto V_71;
V_7 -> V_91 = V_32 ;
F_44 ( V_7 -> V_89 ) ;
F_44 ( V_7 -> V_93 ) ;
F_36 ( & V_7 -> V_83 ) ;
V_50 = 0 ;
V_51 = ( V_52 * F_21 ( V_53 ) ) ;
do {
V_8 = F_2 ( V_7 -> V_10 . V_47 ) ;
V_8 = F_23 ( V_8 ) ;
F_22 () ;
} while ( V_8 && ( V_50 ++ < V_51 ) );
F_5 ( V_7 -> V_46 , V_7 ) ;
return;
V_71:
if ( V_7 -> V_34 . V_44 & V_45 )
F_15 ( V_22 , V_31 , V_32 ) ;
else
F_11 ( V_22 , V_31 , V_32 ) ;
}
static void F_46 ( T_6 * V_95 )
{
T_1 V_96 = V_95 [ 0 ] | ( V_95 [ 1 ] << 16 ) |
( ( V_95 [ 2 ] & 0xF0 ) << 20 ) | ( ( V_95 [ 2 ] & 0x0F ) << 8 ) ;
V_95 [ 0 ] = ~ ( F_47 ( V_96 ) | F_48 ( V_96 ) | F_49 ( V_96 ) | F_50 ( V_96 ) |
F_51 ( V_96 ) | F_52 ( V_96 ) | F_53 ( V_96 ) | F_54 ( V_96 ) ) ;
V_95 [ 1 ] = ~ ( F_55 ( V_96 ) | F_56 ( V_96 ) | F_57 ( V_96 ) | F_58 ( V_96 ) |
F_59 ( V_96 ) | F_60 ( V_96 ) | F_61 ( V_96 ) | F_62 ( V_96 ) ) ;
V_95 [ 2 ] = ~ ( F_63 ( V_96 ) | F_64 ( V_96 ) | F_65 ( V_96 ) | F_66 ( V_96 ) | F_67 ( V_96 ) |
F_68 ( V_96 ) | F_69 ( V_96 ) | F_70 ( V_96 ) ) ;
}
static int F_71 ( T_6 * V_97 ,
T_6 * V_98 ,
T_6 * V_99 )
{
T_7 V_49 ;
T_6 V_100 [ 8 ] , V_101 [ 8 ] , V_102 [ 8 ] ;
T_6 V_103 [ 8 ] , V_104 [ 8 ] , V_105 [ 8 ] ;
T_6 V_106 [ 24 ] ;
T_6 V_107 = 0 ;
T_6 V_108 = 0 ;
T_7 V_109 = 0 ;
int V_110 ;
V_110 = ( ( * ( T_1 * ) V_97 & 0xFFFFFF ) == 0xFFFFFF ) ;
F_46 ( V_97 ) ;
F_46 ( V_98 ) ;
for ( V_49 = 0 ; V_49 <= 2 ; V_49 ++ ) {
* ( V_97 + V_49 ) = ~ ( * ( V_97 + V_49 ) ) ;
* ( V_98 + V_49 ) = ~ ( * ( V_98 + V_49 ) ) ;
}
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_100 [ V_49 ] = * V_97 % 2 ;
* V_97 = * V_97 / 2 ;
}
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_101 [ V_49 ] = * ( V_97 + 1 ) % 2 ;
* ( V_97 + 1 ) = * ( V_97 + 1 ) / 2 ;
}
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_102 [ V_49 ] = * ( V_97 + 2 ) % 2 ;
* ( V_97 + 2 ) = * ( V_97 + 2 ) / 2 ;
}
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_103 [ V_49 ] = * V_98 % 2 ;
* V_98 = * V_98 / 2 ;
}
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_104 [ V_49 ] = * ( V_98 + 1 ) % 2 ;
* ( V_98 + 1 ) = * ( V_98 + 1 ) / 2 ;
}
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ ) {
V_105 [ V_49 ] = * ( V_98 + 2 ) % 2 ;
* ( V_98 + 2 ) = * ( V_98 + 2 ) / 2 ;
}
for ( V_49 = 0 ; V_49 < 6 ; V_49 ++ )
V_106 [ V_49 ] = V_102 [ V_49 + 2 ] ^ V_105 [ V_49 + 2 ] ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ )
V_106 [ V_49 + 6 ] = V_100 [ V_49 ] ^ V_103 [ V_49 ] ;
for ( V_49 = 0 ; V_49 < 8 ; V_49 ++ )
V_106 [ V_49 + 14 ] = V_101 [ V_49 ] ^ V_104 [ V_49 ] ;
V_106 [ 22 ] = V_102 [ 0 ] ^ V_105 [ 0 ] ;
V_106 [ 23 ] = V_102 [ 1 ] ^ V_105 [ 1 ] ;
for ( V_49 = 0 ; V_49 < 24 ; V_49 ++ )
V_107 += V_106 [ V_49 ] ;
switch ( V_107 ) {
case 0 :
return 0 ;
case 1 :
F_72 ( L_2 ) ;
return - 1 ;
case 11 :
F_72 ( L_3 ) ;
return - 1 ;
case 12 :
V_109 = ( V_106 [ 23 ] << 8 ) +
( V_106 [ 21 ] << 7 ) +
( V_106 [ 19 ] << 6 ) +
( V_106 [ 17 ] << 5 ) +
( V_106 [ 15 ] << 4 ) +
( V_106 [ 13 ] << 3 ) +
( V_106 [ 11 ] << 2 ) +
( V_106 [ 9 ] << 1 ) +
V_106 [ 7 ] ;
V_108 = ( V_106 [ 5 ] << 2 ) + ( V_106 [ 3 ] << 1 ) + V_106 [ 1 ] ;
F_72 ( L_4
L_5 , V_109 , V_108 ) ;
V_99 [ V_109 ] ^= ( 1 << V_108 ) ;
return 1 ;
default:
if ( V_110 ) {
if ( V_98 [ 0 ] == 0 &&
V_98 [ 1 ] == 0 &&
V_98 [ 2 ] == 0 )
return 0 ;
}
F_72 ( L_6 ) ;
return - 1 ;
}
}
static int F_73 ( struct V_21 * V_22 , T_2 * V_111 ,
T_2 * V_112 , T_2 * V_113 )
{
struct V_6 * V_7 = F_7 ( V_22 , struct V_6 ,
V_22 ) ;
int V_114 = 0 , V_49 = 0 , V_43 = 0 ;
int V_115 = 0 ;
if ( ( V_7 -> V_34 . V_116 . V_117 == V_118 ) &&
( V_7 -> V_34 . V_116 . V_119 == 2048 ) )
V_114 = 4 ;
else
V_114 = 1 ;
for ( V_49 = 0 ; V_49 < V_114 ; V_49 ++ ) {
if ( memcmp ( V_112 , V_113 , 3 ) != 0 ) {
V_43 = F_71 ( V_112 , V_113 , V_111 ) ;
if ( V_43 < 0 )
return V_43 ;
V_115 += V_43 ;
}
V_112 += 3 ;
V_113 += 3 ;
V_111 += 512 ;
}
return V_115 ;
}
static int F_74 ( struct V_21 * V_22 , const T_2 * V_111 ,
T_2 * V_120 )
{
struct V_6 * V_7 = F_7 ( V_22 , struct V_6 ,
V_22 ) ;
T_1 V_8 ;
V_8 = F_2 ( V_7 -> V_10 . V_121 ) ;
if ( ( ( V_8 >> V_122 ) & ~ V_19 ) != V_7 -> V_46 )
return - V_20 ;
V_8 = F_2 ( V_7 -> V_10 . V_123 ) ;
* V_120 ++ = V_8 ;
* V_120 ++ = V_8 >> 16 ;
* V_120 ++ = ( ( V_8 >> 8 ) & 0x0f ) | ( ( V_8 >> 20 ) & 0xf0 ) ;
return 0 ;
}
static void F_75 ( struct V_21 * V_22 , int V_117 )
{
struct V_6 * V_7 = F_7 ( V_22 , struct V_6 ,
V_22 ) ;
struct V_33 * V_124 = V_22 -> V_35 ;
unsigned int V_125 = ( V_124 -> V_44 & V_45 ) ? 1 : 0 ;
T_1 V_8 ;
V_8 = V_126 | V_127 ;
F_3 ( V_8 , V_7 -> V_10 . V_128 ) ;
V_8 = ( ( ( ( V_7 -> V_34 . V_116 . V_119 >> 1 ) - 1 ) << V_129 ) |
V_130 ) ;
F_3 ( V_8 , V_7 -> V_10 . V_131 ) ;
switch ( V_117 ) {
case V_132 :
case V_133 :
F_3 ( V_126 | V_127 , V_7 -> V_10 . V_128 ) ;
break;
case V_134 :
F_3 ( V_126 , V_7 -> V_10 . V_128 ) ;
break;
default:
F_76 ( & V_7 -> V_75 -> V_74 ,
L_7 , V_117 ) ;
break;
}
V_8 = ( V_125 << 7 ) | ( V_7 -> V_46 << 1 ) | ( 0x1 ) ;
F_3 ( V_8 , V_7 -> V_10 . V_121 ) ;
}
static int F_77 ( struct V_21 * V_22 , struct V_33 * V_124 )
{
struct V_33 * V_135 = V_22 -> V_35 ;
struct V_6 * V_7 = F_7 ( V_22 , struct V_6 ,
V_22 ) ;
unsigned long V_136 = V_137 ;
int V_38 , V_138 = V_135 -> V_138 ;
if ( V_138 == V_139 )
V_136 += F_21 ( 400 ) ;
else
V_136 += F_21 ( 20 ) ;
F_8 ( V_140 & 0xFF , V_7 -> V_10 . V_27 ) ;
while ( F_78 ( V_137 , V_136 ) ) {
V_38 = F_79 ( V_7 -> V_10 . V_30 ) ;
if ( V_38 & V_141 )
break;
F_80 () ;
}
V_38 = F_79 ( V_7 -> V_10 . V_30 ) ;
return V_38 ;
}
static int F_81 ( struct V_21 * V_22 )
{
unsigned int V_8 = 0 ;
struct V_6 * V_7 = F_7 ( V_22 , struct V_6 ,
V_22 ) ;
V_8 = F_2 ( V_7 -> V_10 . V_40 ) ;
if ( ( V_8 & 0x100 ) == 0x100 ) {
return 1 ;
} else {
return 0 ;
}
}
static void T_8 F_82 ( struct V_21 * V_22 , int V_117 )
{
unsigned int V_142 ;
unsigned int V_125 , V_143 ;
struct V_6 * V_7 = F_7 ( V_22 , struct V_6 ,
V_22 ) ;
enum V_144 V_145 = V_7 -> V_145 ;
struct V_33 * V_124 = V_22 -> V_35 ;
T_1 V_8 , V_146 ;
unsigned int V_147 , V_148 ;
switch ( V_145 ) {
case V_149 :
V_142 = 0 ;
V_143 = 1 ;
if ( V_117 == V_132 ) {
V_146 = V_150 ;
V_148 = V_151 ;
V_147 = V_152 ;
} else {
V_146 = V_150 ;
V_148 = V_151 ;
V_147 = V_152 ;
}
break;
case V_153 :
V_142 = 0 ;
V_143 = V_124 -> V_116 . V_154 ;
if ( V_117 == V_132 ) {
V_146 = V_155 ;
V_148 = V_156 ;
V_147 = V_157 ;
} else {
V_146 = V_150 ;
V_148 = V_151 ;
V_147 = V_152 ;
}
break;
case V_158 :
V_142 = 1 ;
V_143 = 1 ;
if ( V_117 == V_132 ) {
V_146 = V_150 ;
V_148 = V_151 ;
V_147 = V_152 ;
} else {
V_146 = V_150 ;
V_148 = V_151 ;
V_147 = V_152 ;
}
break;
case V_159 :
V_142 = 1 ;
V_143 = V_124 -> V_116 . V_154 ;
if ( V_117 == V_132 ) {
V_146 = V_155 ;
V_148 = V_160 ;
V_147 = V_161 ;
} else {
V_146 = V_150 ;
V_148 = V_151 ;
V_147 = V_152 ;
}
break;
default:
return;
}
F_3 ( V_127 , V_7 -> V_10 . V_128 ) ;
V_8 = ( V_147 << V_129 ) | ( V_148 << V_162 ) ;
F_3 ( V_8 , V_7 -> V_10 . V_131 ) ;
V_125 = ( V_124 -> V_44 & V_45 ) ? 1 : 0 ;
V_8 = ( ( 1 << 16 ) |
( V_142 << 12 ) |
( V_146 << 8 ) |
( V_125 << 7 ) |
( ( ( V_143 - 1 ) & 0x7 ) << 4 ) |
( V_7 -> V_46 << 1 ) |
( 0x1 ) ) ;
F_3 ( V_8 , V_7 -> V_10 . V_121 ) ;
F_3 ( V_126 | V_127 , V_7 -> V_10 . V_128 ) ;
}
static int T_8 F_83 ( struct V_21 * V_22 ,
const T_2 * V_111 , T_2 * V_163 )
{
struct V_6 * V_7 = F_7 ( V_22 , struct V_6 ,
V_22 ) ;
int V_164 = V_7 -> V_34 . V_116 . V_86 ;
struct V_165 * V_166 = & V_7 -> V_10 ;
T_6 * V_120 ;
unsigned long V_143 , V_167 , V_168 , V_169 , V_170 ;
int V_49 ;
V_143 = ( ( F_2 ( V_7 -> V_10 . V_121 ) >> 4 ) & 0x7 ) + 1 ;
for ( V_49 = 0 ; V_49 < V_143 ; V_49 ++ ) {
V_120 = V_163 ;
switch ( V_7 -> V_145 ) {
case V_158 :
case V_159 :
V_167 = F_2 ( V_166 -> V_171 [ V_49 ] ) ;
V_168 = F_2 ( V_166 -> V_172 [ V_49 ] ) ;
V_169 = F_2 ( V_166 -> V_173 [ V_49 ] ) ;
V_170 = F_2 ( V_166 -> V_174 [ V_49 ] ) ;
* V_120 ++ = ( V_170 & 0xFF ) ;
* V_120 ++ = ( ( V_169 >> 24 ) & 0xFF ) ;
* V_120 ++ = ( ( V_169 >> 16 ) & 0xFF ) ;
* V_120 ++ = ( ( V_169 >> 8 ) & 0xFF ) ;
* V_120 ++ = ( V_169 & 0xFF ) ;
* V_120 ++ = ( ( V_168 >> 24 ) & 0xFF ) ;
* V_120 ++ = ( ( V_168 >> 16 ) & 0xFF ) ;
* V_120 ++ = ( ( V_168 >> 8 ) & 0xFF ) ;
* V_120 ++ = ( V_168 & 0xFF ) ;
* V_120 ++ = ( ( V_167 >> 24 ) & 0xFF ) ;
* V_120 ++ = ( ( V_167 >> 16 ) & 0xFF ) ;
* V_120 ++ = ( ( V_167 >> 8 ) & 0xFF ) ;
* V_120 ++ = ( V_167 & 0xFF ) ;
break;
case V_149 :
case V_153 :
V_167 = F_2 ( V_166 -> V_171 [ V_49 ] ) ;
V_168 = F_2 ( V_166 -> V_172 [ V_49 ] ) ;
* V_120 ++ = ( ( V_168 >> 12 ) & 0xFF ) ;
* V_120 ++ = ( ( V_168 >> 4 ) & 0xFF ) ;
* V_120 ++ = ( ( V_168 & 0xF ) << 4 ) |
( ( V_167 >> 28 ) & 0xF ) ;
* V_120 ++ = ( ( V_167 >> 20 ) & 0xFF ) ;
* V_120 ++ = ( ( V_167 >> 12 ) & 0xFF ) ;
* V_120 ++ = ( ( V_167 >> 4 ) & 0xFF ) ;
* V_120 ++ = ( ( V_167 & 0xF ) << 4 ) ;
break;
default:
return - V_20 ;
}
switch ( V_7 -> V_145 ) {
case V_149 :
for ( V_49 = 0 ; V_49 < V_164 ; V_49 ++ )
V_163 [ V_49 ] ^= V_175 [ V_49 ] ;
break;
case V_153 :
V_163 [ V_164 - 1 ] = 0x0 ;
break;
case V_158 :
for ( V_49 = 0 ; V_49 < V_164 ; V_49 ++ )
V_163 [ V_49 ] ^= V_176 [ V_49 ] ;
break;
case V_159 :
V_163 [ V_164 - 1 ] = 0x0 ;
break;
default:
return - V_20 ;
}
V_163 += V_164 ;
}
return 0 ;
}
static int F_84 ( T_2 * V_54 , T_2 * V_177 ,
struct V_6 * V_7 )
{
int V_178 = 0 , V_49 ;
for ( V_49 = 0 ; V_49 < V_7 -> V_34 . V_116 . V_119 ; V_49 ++ ) {
V_178 += F_85 ( ~ V_54 [ V_49 ] ) ;
if ( V_178 > V_7 -> V_34 . V_116 . V_179 )
return 0 ;
}
for ( V_49 = 0 ; V_49 < V_7 -> V_34 . V_116 . V_86 - 1 ; V_49 ++ ) {
V_178 += F_85 ( ~ V_177 [ V_49 ] ) ;
if ( V_178 > V_7 -> V_34 . V_116 . V_179 )
return 0 ;
}
if ( V_178 ) {
memset ( V_54 , 0xFF , V_7 -> V_34 . V_116 . V_119 ) ;
memset ( V_177 , 0xFF , V_7 -> V_34 . V_116 . V_86 ) ;
}
return V_178 ;
}
static int F_86 ( struct V_21 * V_22 , T_2 * V_54 ,
T_2 * V_112 , T_2 * V_113 )
{
struct V_6 * V_7 = F_7 ( V_22 , struct V_6 ,
V_22 ) ;
struct V_180 * V_116 = & V_7 -> V_34 . V_116 ;
int V_181 = V_7 -> V_34 . V_116 . V_154 ;
int V_49 , V_182 , V_115 = 0 ;
int V_183 , V_184 ;
struct V_185 V_186 [ V_187 ] ;
T_2 * V_188 = V_113 ;
T_2 * V_189 = V_112 ;
T_2 * V_190 ;
T_2 * V_31 ;
int V_191 ;
bool V_192 = false ;
T_1 V_193 , V_194 , V_195 , V_196 ;
int V_197 ;
switch ( V_7 -> V_145 ) {
case V_153 :
V_184 = V_116 -> V_86 - 1 ;
V_190 = V_198 ;
break;
case V_159 :
V_184 = V_116 -> V_86 - 1 ;
V_190 = V_199 ;
break;
default:
F_87 ( L_8 ) ;
return - V_20 ;
}
memset ( V_186 , 0 , sizeof( V_186 ) ) ;
for ( V_49 = 0 ; V_49 < V_181 ; V_49 ++ ) {
V_183 = 0 ;
for ( V_182 = 0 ; V_182 < V_184 ; V_182 ++ ) {
if ( V_113 [ V_182 ] != 0 ) {
V_183 = 1 ;
break;
}
}
if ( V_183 == 1 ) {
if ( memcmp ( V_113 , V_190 ,
V_184 ) == 0 ) {
} else {
V_31 = & V_54 [ V_7 -> V_34 . V_116 . V_119 * V_49 ] ;
V_191 = F_84 (
V_31 , V_112 , V_7 ) ;
if ( V_191 ) {
V_115 += V_191 ;
} else {
V_186 [ V_49 ] . V_200 = true ;
V_192 = true ;
}
}
}
V_113 += V_116 -> V_86 ;
V_112 += V_116 -> V_86 ;
}
if ( ! V_192 )
return 0 ;
F_88 ( V_7 -> V_201 , V_188 , V_186 ) ;
V_197 = 0 ;
for ( V_49 = 0 ; V_49 < V_181 ; V_49 ++ ) {
if ( V_186 [ V_49 ] . V_202 ) {
F_87 ( L_9 ) ;
V_197 = - V_203 ;
} else if ( V_186 [ V_49 ] . V_200 ) {
for ( V_182 = 0 ; V_182 < V_186 [ V_49 ] . V_204 ; V_182 ++ ) {
switch ( V_7 -> V_145 ) {
case V_153 :
V_196 = V_186 [ V_49 ] . V_205 [ V_182 ] +
V_206 ;
break;
case V_159 :
V_196 = V_186 [ V_49 ] . V_205 [ V_182 ] ;
break;
default:
return - V_20 ;
}
V_195 = ( V_116 -> V_119 + V_184 ) * 8 ;
V_193 = V_196 % 8 ;
V_194 = ( V_195 - V_196 - 1 ) / 8 ;
if ( V_196 < V_195 ) {
if ( V_194 < 512 ) {
F_72 ( L_10 ,
V_194 , V_54 [ V_194 ] ) ;
V_54 [ V_194 ] ^= 1 << V_193 ;
} else {
F_72 ( L_11 ,
( V_194 - 512 ) ,
V_189 [ V_194 - 512 ] ) ;
V_189 [ V_194 - 512 ] ^=
1 << V_193 ;
}
} else {
F_87 ( L_12 ,
V_194 , V_193 ) ;
V_197 = - V_203 ;
}
}
}
V_115 += V_186 [ V_49 ] . V_204 ;
V_54 += V_116 -> V_119 ;
V_189 += V_116 -> V_86 ;
}
return ( V_197 ) ? V_197 : V_115 ;
}
static int F_89 ( struct V_21 * V_22 , struct V_33 * V_124 ,
const T_9 * V_31 , int V_207 )
{
int V_49 ;
T_9 * V_163 = V_124 -> V_208 -> V_209 ;
T_4 * V_210 = V_124 -> V_116 . V_211 -> V_210 ;
V_124 -> V_116 . V_212 ( V_22 , V_133 ) ;
V_124 -> V_213 ( V_22 , V_31 , V_22 -> V_214 ) ;
V_124 -> V_116 . V_215 ( V_22 , V_31 , & V_163 [ 0 ] ) ;
for ( V_49 = 0 ; V_49 < V_124 -> V_116 . V_216 ; V_49 ++ )
V_124 -> V_217 [ V_210 [ V_49 ] ] = V_163 [ V_49 ] ;
V_124 -> V_213 ( V_22 , V_124 -> V_217 , V_22 -> V_84 ) ;
return 0 ;
}
static int F_90 ( struct V_21 * V_22 , struct V_33 * V_124 ,
T_9 * V_31 , int V_207 , int V_67 )
{
T_9 * V_163 = V_124 -> V_208 -> V_209 ;
T_9 * V_120 = V_124 -> V_208 -> V_218 ;
T_4 * V_210 = V_124 -> V_116 . V_211 -> V_210 ;
T_9 * V_177 = & V_124 -> V_217 [ V_210 [ 0 ] ] ;
T_4 V_219 = V_22 -> V_214 + V_124 -> V_116 . V_211 -> V_210 [ 0 ] ;
int V_115 ;
unsigned int V_220 = 0 ;
V_124 -> V_116 . V_212 ( V_22 , V_132 ) ;
V_124 -> V_221 ( V_22 , V_31 , V_22 -> V_214 ) ;
V_124 -> V_222 ( V_22 , V_223 , V_219 , - 1 ) ;
V_124 -> V_221 ( V_22 , V_177 , V_124 -> V_116 . V_216 ) ;
V_124 -> V_116 . V_215 ( V_22 , V_31 , V_163 ) ;
memcpy ( V_120 , & V_124 -> V_217 [ V_210 [ 0 ] ] , V_124 -> V_116 . V_216 ) ;
V_115 = V_124 -> V_116 . V_224 ( V_22 , V_31 , V_120 , V_163 ) ;
if ( V_115 < 0 ) {
V_22 -> V_225 . V_226 ++ ;
} else {
V_22 -> V_225 . V_227 += V_115 ;
V_220 = F_91 (unsigned int, max_bitflips, stat) ;
}
return V_220 ;
}
static int F_92 ( struct V_6 * V_7 ,
struct V_228 * V_229 , enum V_230 V_142 )
{
struct V_231 * V_75 ;
struct V_180 * V_116 = & V_7 -> V_34 . V_116 ;
int V_197 ;
if ( ! V_229 ) {
F_87 ( L_13 ) ;
return - V_232 ;
}
V_75 = F_93 ( V_229 ) ;
if ( ! V_75 ) {
F_87 ( L_14 ) ;
return - V_232 ;
}
V_7 -> V_201 = & V_75 -> V_74 ;
V_197 = F_94 ( V_7 -> V_201 , V_142 ,
( V_7 -> V_22 . V_214 / V_116 -> V_119 ) , V_116 -> V_119 , V_116 -> V_86 ) ;
return V_197 ;
}
static int F_95 ( struct V_231 * V_75 )
{
struct V_6 * V_7 ;
struct V_233 * V_234 ;
struct V_21 * V_22 ;
struct V_33 * V_33 ;
struct V_235 * V_236 ;
int V_197 ;
int V_49 ;
T_10 V_237 ;
unsigned V_238 ;
unsigned V_239 ;
struct V_240 * V_241 ;
struct V_242 V_243 = {} ;
V_234 = F_96 ( & V_75 -> V_74 ) ;
if ( V_234 == NULL ) {
F_31 ( & V_75 -> V_74 , L_15 ) ;
return - V_232 ;
}
V_7 = F_97 ( & V_75 -> V_74 , sizeof( struct V_6 ) ,
V_244 ) ;
if ( ! V_7 )
return - V_245 ;
F_98 ( V_75 , V_7 ) ;
F_99 ( & V_7 -> V_246 . V_247 ) ;
F_100 ( & V_7 -> V_246 . V_248 ) ;
V_7 -> V_75 = V_75 ;
V_7 -> V_46 = V_234 -> V_1 ;
V_7 -> V_10 = V_234 -> V_10 ;
V_7 -> V_249 = V_234 -> V_249 ;
V_7 -> V_145 = V_234 -> V_145 ;
V_22 = & V_7 -> V_22 ;
V_22 -> V_35 = & V_7 -> V_34 ;
V_22 -> V_250 = F_101 ( & V_75 -> V_74 ) ;
V_22 -> V_251 = V_252 ;
V_33 = & V_7 -> V_34 ;
V_33 -> V_116 . V_35 = NULL ;
V_33 -> V_44 |= V_253 ;
V_241 = F_102 ( V_75 , V_254 , 0 ) ;
V_33 -> V_36 = F_103 ( & V_75 -> V_74 , V_241 ) ;
if ( F_104 ( V_33 -> V_36 ) )
return F_105 ( V_33 -> V_36 ) ;
V_7 -> V_255 = V_241 -> V_256 ;
V_33 -> V_246 = & V_7 -> V_246 ;
V_33 -> V_39 = V_33 -> V_36 ;
V_33 -> V_257 = F_6 ;
if ( V_234 -> V_258 ) {
V_33 -> V_258 = F_81 ;
V_33 -> V_259 = 0 ;
} else {
V_33 -> V_260 = F_77 ;
V_33 -> V_259 = 50 ;
}
V_33 -> V_44 |= V_234 -> V_261 & V_45 ;
if ( F_106 ( V_22 , 1 , NULL ) ) {
F_87 ( L_16 ) ;
V_197 = - V_262 ;
goto V_263;
}
if ( ( V_22 -> V_84 < 64 ) && ( V_234 -> V_145 != V_264 ) ) {
F_87 ( L_17 ) ;
V_197 = - V_20 ;
goto V_263;
}
switch ( V_234 -> V_265 ) {
case V_266 :
V_33 -> V_221 = F_17 ;
V_33 -> V_213 = F_20 ;
break;
case V_267 :
break;
case V_268 :
F_107 ( V_237 ) ;
F_108 ( V_269 , V_237 ) ;
V_238 = V_270 ;
V_7 -> V_72 = F_109 ( V_237 , V_271 , & V_238 ) ;
if ( ! V_7 -> V_72 ) {
F_31 ( & V_75 -> V_74 , L_18 ) ;
V_197 = - V_262 ;
goto V_263;
} else {
struct V_272 V_273 ;
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
V_273 . V_274 = V_7 -> V_255 ;
V_273 . V_275 = V_7 -> V_255 ;
V_273 . V_276 = V_277 ;
V_273 . V_278 = V_277 ;
V_273 . V_279 = 16 ;
V_273 . V_280 = 16 ;
V_197 = F_110 ( V_7 -> V_72 , & V_273 ) ;
if ( V_197 ) {
F_31 ( & V_75 -> V_74 , L_19 ,
V_197 ) ;
goto V_263;
}
V_33 -> V_221 = F_38 ;
V_33 -> V_213 = F_39 ;
}
break;
case V_281 :
V_7 -> V_93 = F_111 ( V_75 , 0 ) ;
if ( V_7 -> V_93 <= 0 ) {
F_31 ( & V_75 -> V_74 , L_20 ) ;
V_197 = - V_232 ;
goto V_263;
}
V_197 = F_112 ( & V_75 -> V_74 , V_7 -> V_93 ,
F_40 , V_282 ,
L_21 , V_7 ) ;
if ( V_197 ) {
F_31 ( & V_75 -> V_74 , L_22 ,
V_7 -> V_93 , V_197 ) ;
V_7 -> V_93 = 0 ;
goto V_263;
}
V_7 -> V_89 = F_111 ( V_75 , 1 ) ;
if ( V_7 -> V_89 <= 0 ) {
F_31 ( & V_75 -> V_74 , L_23 ) ;
V_197 = - V_232 ;
goto V_263;
}
V_197 = F_112 ( & V_75 -> V_74 , V_7 -> V_89 ,
F_40 , V_282 ,
L_24 , V_7 ) ;
if ( V_197 ) {
F_31 ( & V_75 -> V_74 , L_22 ,
V_7 -> V_89 , V_197 ) ;
V_7 -> V_89 = 0 ;
goto V_263;
}
V_33 -> V_221 = F_43 ;
V_33 -> V_213 = F_45 ;
break;
default:
F_31 ( & V_75 -> V_74 ,
L_25 , V_234 -> V_265 ) ;
V_197 = - V_20 ;
goto V_263;
}
V_33 -> V_116 . V_211 = & V_283 ;
V_236 = & V_283 ;
switch ( V_7 -> V_145 ) {
case V_264 :
F_113 ( L_26 ) ;
V_33 -> V_116 . V_117 = V_118 ;
V_33 -> V_116 . V_86 = 3 ;
V_33 -> V_116 . V_119 = 512 ;
V_33 -> V_116 . V_179 = 1 ;
V_33 -> V_116 . V_215 = F_74 ;
V_33 -> V_116 . V_212 = F_75 ;
V_33 -> V_116 . V_224 = F_73 ;
V_236 -> V_164 = V_33 -> V_116 . V_86 *
( V_22 -> V_214 /
V_33 -> V_116 . V_119 ) ;
if ( V_33 -> V_44 & V_45 )
V_239 = V_284 ;
else
V_239 = 1 ;
for ( V_49 = 0 ; V_49 < V_236 -> V_164 ; V_49 ++ , V_239 ++ )
V_236 -> V_210 [ V_49 ] = V_239 ;
V_236 -> V_285 -> V_286 =
V_236 -> V_210 [ V_236 -> V_164 - 1 ] + 1 ;
break;
case V_149 :
#ifdef F_114
F_113 ( L_27 ) ;
V_33 -> V_116 . V_117 = V_118 ;
V_33 -> V_116 . V_119 = 512 ;
V_33 -> V_116 . V_86 = 7 ;
V_33 -> V_116 . V_179 = 4 ;
V_33 -> V_116 . V_212 = F_82 ;
V_33 -> V_116 . V_224 = V_287 ;
V_33 -> V_116 . V_215 = F_83 ;
V_236 -> V_164 = V_33 -> V_116 . V_86 *
( V_22 -> V_214 /
V_33 -> V_116 . V_119 ) ;
V_239 = V_284 ;
for ( V_49 = 0 ; V_49 < V_236 -> V_164 ; V_49 ++ , V_239 ++ ) {
V_236 -> V_210 [ V_49 ] = V_239 ;
if ( ( ( V_49 + 1 ) % V_33 -> V_116 . V_86 ) == 0 )
V_239 ++ ;
}
V_236 -> V_285 -> V_286 = 1 +
V_236 -> V_210 [ V_236 -> V_164 - 1 ] + 1 ;
V_33 -> V_116 . V_35 = F_115 ( V_22 ,
V_33 -> V_116 . V_119 ,
V_33 -> V_116 . V_86 ,
& V_33 -> V_116 . V_211 ) ;
if ( ! V_33 -> V_116 . V_35 ) {
F_87 ( L_28 ) ;
V_197 = - V_20 ;
}
break;
#else
F_87 ( L_29 ) ;
V_197 = - V_20 ;
goto V_263;
#endif
case V_153 :
#ifdef F_116
F_113 ( L_30 ) ;
V_33 -> V_116 . V_117 = V_118 ;
V_33 -> V_116 . V_119 = 512 ;
V_33 -> V_116 . V_86 = 7 + 1 ;
V_33 -> V_116 . V_179 = 4 ;
V_33 -> V_116 . V_212 = F_82 ;
V_33 -> V_116 . V_224 = F_86 ;
V_33 -> V_116 . V_215 = F_83 ;
V_33 -> V_116 . V_288 = F_90 ;
V_33 -> V_116 . V_289 = F_89 ;
V_236 -> V_164 = V_33 -> V_116 . V_86 *
( V_22 -> V_214 /
V_33 -> V_116 . V_119 ) ;
V_239 = V_284 ;
for ( V_49 = 0 ; V_49 < V_236 -> V_164 ; V_49 ++ , V_239 ++ )
V_236 -> V_210 [ V_49 ] = V_239 ;
V_236 -> V_285 -> V_286 =
V_236 -> V_210 [ V_236 -> V_164 - 1 ] + 1 ;
if ( F_92 ( V_7 , V_234 -> V_290 , V_291 ) < 0 ) {
F_87 ( L_31 ) ;
V_197 = - V_232 ;
goto V_263;
}
break;
#else
F_87 ( L_32 ) ;
V_197 = - V_20 ;
goto V_263;
#endif
case V_158 :
#ifdef F_114
F_113 ( L_33 ) ;
V_33 -> V_116 . V_117 = V_118 ;
V_33 -> V_116 . V_119 = 512 ;
V_33 -> V_116 . V_86 = 13 ;
V_33 -> V_116 . V_179 = 8 ;
V_33 -> V_116 . V_212 = F_82 ;
V_33 -> V_116 . V_224 = V_287 ;
V_33 -> V_116 . V_215 = F_83 ;
V_236 -> V_164 = V_33 -> V_116 . V_86 *
( V_22 -> V_214 /
V_33 -> V_116 . V_119 ) ;
V_239 = V_284 ;
for ( V_49 = 0 ; V_49 < V_236 -> V_164 ; V_49 ++ , V_239 ++ ) {
V_236 -> V_210 [ V_49 ] = V_239 ;
if ( ( ( V_49 + 1 ) % V_33 -> V_116 . V_86 ) == 0 )
V_239 ++ ;
}
V_236 -> V_285 -> V_286 = 1 +
V_236 -> V_210 [ V_236 -> V_164 - 1 ] + 1 ;
V_33 -> V_116 . V_35 = F_115 ( V_22 ,
V_33 -> V_116 . V_119 ,
V_33 -> V_116 . V_86 ,
& V_33 -> V_116 . V_211 ) ;
if ( ! V_33 -> V_116 . V_35 ) {
F_87 ( L_28 ) ;
V_197 = - V_20 ;
goto V_263;
}
break;
#else
F_87 ( L_29 ) ;
V_197 = - V_20 ;
goto V_263;
#endif
case V_159 :
#ifdef F_116
F_113 ( L_34 ) ;
V_33 -> V_116 . V_117 = V_118 ;
V_33 -> V_116 . V_119 = 512 ;
V_33 -> V_116 . V_86 = 13 + 1 ;
V_33 -> V_116 . V_179 = 8 ;
V_33 -> V_116 . V_212 = F_82 ;
V_33 -> V_116 . V_224 = F_86 ;
V_33 -> V_116 . V_215 = F_83 ;
V_33 -> V_116 . V_288 = F_90 ;
V_33 -> V_116 . V_289 = F_89 ;
V_197 = F_92 ( V_7 , V_234 -> V_290 , V_292 ) ;
if ( V_197 < 0 ) {
F_87 ( L_31 ) ;
goto V_263;
}
V_236 -> V_164 = V_33 -> V_116 . V_86 *
( V_22 -> V_214 /
V_33 -> V_116 . V_119 ) ;
V_239 = V_284 ;
for ( V_49 = 0 ; V_49 < V_236 -> V_164 ; V_49 ++ , V_239 ++ )
V_236 -> V_210 [ V_49 ] = V_239 ;
V_236 -> V_285 -> V_286 =
V_236 -> V_210 [ V_236 -> V_164 - 1 ] + 1 ;
break;
#else
F_87 ( L_32 ) ;
V_197 = - V_20 ;
goto V_263;
#endif
default:
F_87 ( L_35 ) ;
V_197 = - V_20 ;
goto V_263;
}
V_236 -> V_285 -> V_293 = V_22 -> V_84 - V_236 -> V_285 -> V_286 ;
if ( V_22 -> V_84 < ( V_236 -> V_164 + V_284 ) ) {
F_87 ( L_36 ,
V_236 -> V_164 , V_22 -> V_84 ) ;
V_197 = - V_20 ;
goto V_263;
}
if ( F_117 ( V_22 ) ) {
V_197 = - V_262 ;
goto V_263;
}
V_243 . V_249 = V_234 -> V_249 ;
F_118 ( V_22 , NULL , & V_243 , V_234 -> V_294 ,
V_234 -> V_295 ) ;
F_98 ( V_75 , V_22 ) ;
return 0 ;
V_263:
if ( V_7 -> V_72 )
F_119 ( V_7 -> V_72 ) ;
if ( V_33 -> V_116 . V_35 ) {
F_120 ( V_33 -> V_116 . V_35 ) ;
V_33 -> V_116 . V_35 = NULL ;
}
return V_197 ;
}
static int F_121 ( struct V_231 * V_75 )
{
struct V_21 * V_22 = F_122 ( V_75 ) ;
struct V_33 * V_33 = V_22 -> V_35 ;
struct V_6 * V_7 = F_7 ( V_22 , struct V_6 ,
V_22 ) ;
if ( V_33 -> V_116 . V_35 ) {
F_120 ( V_33 -> V_116 . V_35 ) ;
V_33 -> V_116 . V_35 = NULL ;
}
if ( V_7 -> V_72 )
F_119 ( V_7 -> V_72 ) ;
F_123 ( V_22 ) ;
return 0 ;
}
