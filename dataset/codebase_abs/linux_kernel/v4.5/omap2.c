static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static int F_4 ( int V_5 , int V_6 , int V_7 ,
unsigned int V_8 , int V_9 , struct V_1 * V_10 )
{
T_1 V_11 ;
if ( V_6 > V_12 )
return - 1 ;
if ( F_5 ( V_10 -> V_13 . V_14 ) )
return - V_15 ;
F_6 ( V_8 , V_10 -> V_13 . V_16 ) ;
V_11 = ( ( V_5 << V_17 ) |
F_7 ( V_6 ) | V_18 |
( V_7 << V_19 ) | ( 0x1 & V_9 ) ) ;
F_6 ( V_11 , V_10 -> V_13 . V_20 ) ;
F_6 ( 0x1 , V_10 -> V_13 . V_14 ) ;
return 0 ;
}
static int F_8 ( int V_5 , struct V_1 * V_10 )
{
T_1 V_21 ;
V_21 = F_5 ( V_10 -> V_13 . V_20 ) ;
if ( ( ( V_21 >> V_17 ) & V_22 ) != V_5 )
return - V_23 ;
F_6 ( 0x0 , V_10 -> V_13 . V_14 ) ;
F_6 ( 0x0 , V_10 -> V_13 . V_20 ) ;
return 0 ;
}
static void F_9 ( struct V_2 * V_3 , int V_24 , unsigned int V_25 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( V_24 != V_26 ) {
if ( V_25 & V_27 )
F_10 ( V_24 , V_10 -> V_13 . V_28 ) ;
else if ( V_25 & V_29 )
F_10 ( V_24 , V_10 -> V_13 . V_30 ) ;
else
F_10 ( V_24 , V_10 -> V_13 . V_31 ) ;
}
}
static void F_11 ( struct V_2 * V_3 , T_2 * V_32 , int V_33 )
{
struct V_34 * V_4 = F_3 ( V_3 ) ;
F_12 ( V_4 -> V_35 , V_32 , V_33 ) ;
}
static void F_13 ( struct V_2 * V_3 , const T_2 * V_32 , int V_33 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
T_2 * V_36 = ( T_2 * ) V_32 ;
T_1 V_37 = 0 ;
while ( V_33 -- ) {
F_14 ( * V_36 ++ , V_10 -> V_4 . V_38 ) ;
do {
V_37 = F_5 ( V_10 -> V_13 . V_39 ) &
V_40 ;
} while ( ! V_37 );
}
}
static void F_15 ( struct V_2 * V_3 , T_2 * V_32 , int V_33 )
{
struct V_34 * V_4 = F_3 ( V_3 ) ;
F_16 ( V_4 -> V_35 , V_32 , V_33 / 2 ) ;
}
static void F_17 ( struct V_2 * V_3 , const T_2 * V_32 , int V_33 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
T_3 * V_36 = ( T_3 * ) V_32 ;
T_1 V_37 = 0 ;
V_33 >>= 1 ;
while ( V_33 -- ) {
F_18 ( * V_36 ++ , V_10 -> V_4 . V_38 ) ;
do {
V_37 = F_5 ( V_10 -> V_13 . V_39 ) &
V_40 ;
} while ( ! V_37 );
}
}
static void F_19 ( struct V_2 * V_3 , T_2 * V_32 , int V_33 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
T_4 V_41 = 0 ;
int V_42 = 0 ;
T_1 * V_36 = ( T_1 * ) V_32 ;
if ( V_33 % 4 ) {
if ( V_10 -> V_4 . V_43 & V_44 )
F_15 ( V_3 , V_32 , V_33 % 4 ) ;
else
F_11 ( V_3 , V_32 , V_33 % 4 ) ;
V_36 = ( T_1 * ) ( V_32 + V_33 % 4 ) ;
V_33 -= V_33 % 4 ;
}
V_42 = F_4 ( V_10 -> V_45 ,
V_12 , 0x0 , V_33 , 0x0 , V_10 ) ;
if ( V_42 ) {
if ( V_10 -> V_4 . V_43 & V_44 )
F_15 ( V_3 , ( T_2 * ) V_36 , V_33 ) ;
else
F_11 ( V_3 , ( T_2 * ) V_36 , V_33 ) ;
} else {
do {
V_41 = F_5 ( V_10 -> V_13 . V_46 ) ;
V_41 = F_20 ( V_41 ) ;
V_41 = V_41 >> 2 ;
F_21 ( V_10 -> V_4 . V_35 , V_36 , V_41 ) ;
V_36 += V_41 ;
V_33 -= V_41 << 2 ;
} while ( V_33 );
F_8 ( V_10 -> V_45 , V_10 ) ;
}
}
static void F_22 ( struct V_2 * V_3 ,
const T_2 * V_32 , int V_33 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
T_4 V_47 = 0 ;
int V_48 = 0 , V_42 = 0 ;
T_3 * V_36 = ( T_3 * ) V_32 ;
unsigned long V_49 , V_50 ;
T_1 V_11 ;
if ( V_33 % 2 != 0 ) {
F_10 ( * V_32 , V_10 -> V_4 . V_38 ) ;
V_36 = ( T_3 * ) ( V_32 + 1 ) ;
V_33 -- ;
}
V_42 = F_4 ( V_10 -> V_45 ,
V_12 , 0x0 , V_33 , 0x1 , V_10 ) ;
if ( V_42 ) {
if ( V_10 -> V_4 . V_43 & V_44 )
F_17 ( V_3 , ( T_2 * ) V_36 , V_33 ) ;
else
F_13 ( V_3 , ( T_2 * ) V_36 , V_33 ) ;
} else {
while ( V_33 ) {
V_47 = F_5 ( V_10 -> V_13 . V_46 ) ;
V_47 = F_20 ( V_47 ) ;
V_47 = V_47 >> 1 ;
for ( V_48 = 0 ; ( V_48 < V_47 ) && V_33 ; V_48 ++ , V_33 -= 2 )
F_18 ( * V_36 ++ , V_10 -> V_4 . V_38 ) ;
}
V_49 = 0 ;
V_50 = ( V_51 *
F_23 ( V_52 ) ) ;
do {
F_24 () ;
V_11 = F_5 ( V_10 -> V_13 . V_46 ) ;
V_11 = F_25 ( V_11 ) ;
} while ( V_11 && ( V_49 ++ < V_50 ) );
F_8 ( V_10 -> V_45 , V_10 ) ;
}
}
static void F_26 ( void * V_53 )
{
F_27 ( (struct V_54 * ) V_53 ) ;
}
static inline int F_28 ( struct V_2 * V_3 , void * V_55 ,
unsigned int V_33 , int V_9 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_56 * V_57 ;
enum V_58 V_59 = V_9 ? V_60 :
V_61 ;
struct V_62 V_63 ;
unsigned long V_49 , V_50 ;
unsigned V_64 ;
int V_42 ;
T_1 V_11 ;
if ( V_55 >= V_65 ) {
struct V_66 * V_67 ;
if ( ( ( V_68 ) V_55 & V_69 ) !=
( ( V_68 ) ( V_55 + V_33 - 1 ) & V_69 ) )
goto V_70;
V_67 = F_29 ( V_55 ) ;
if ( ! V_67 )
goto V_70;
V_55 = F_30 ( V_67 ) + ( ( V_68 ) V_55 & ~ V_69 ) ;
}
F_31 ( & V_63 , V_55 , V_33 ) ;
V_64 = F_32 ( V_10 -> V_71 -> V_72 -> V_73 , & V_63 , 1 , V_59 ) ;
if ( V_64 == 0 ) {
F_33 ( & V_10 -> V_74 -> V_73 ,
L_1 , V_33 ) ;
goto V_70;
}
V_57 = F_34 ( V_10 -> V_71 , & V_63 , V_64 ,
V_9 ? V_75 : V_76 ,
V_77 | V_78 ) ;
if ( ! V_57 )
goto V_79;
V_57 -> V_80 = F_26 ;
V_57 -> V_81 = & V_10 -> V_82 ;
F_35 ( V_57 ) ;
V_42 = F_4 ( V_10 -> V_45 ,
V_12 , 0x1 , V_33 , V_9 , V_10 ) ;
if ( V_42 )
goto V_79;
F_36 ( & V_10 -> V_82 ) ;
F_37 ( V_10 -> V_71 ) ;
F_38 ( & V_10 -> V_82 ) ;
V_49 = 0 ;
V_50 = ( V_51 * F_23 ( V_52 ) ) ;
do {
F_24 () ;
V_11 = F_5 ( V_10 -> V_13 . V_46 ) ;
V_11 = F_25 ( V_11 ) ;
} while ( V_11 && ( V_49 ++ < V_50 ) );
F_8 ( V_10 -> V_45 , V_10 ) ;
F_39 ( V_10 -> V_71 -> V_72 -> V_73 , & V_63 , 1 , V_59 ) ;
return 0 ;
V_79:
F_39 ( V_10 -> V_71 -> V_72 -> V_73 , & V_63 , 1 , V_59 ) ;
V_70:
if ( V_10 -> V_4 . V_43 & V_44 )
V_9 == 0 ? F_15 ( V_3 , ( T_2 * ) V_55 , V_33 )
: F_17 ( V_3 , ( T_2 * ) V_55 , V_33 ) ;
else
V_9 == 0 ? F_11 ( V_3 , ( T_2 * ) V_55 , V_33 )
: F_13 ( V_3 , ( T_2 * ) V_55 , V_33 ) ;
return 0 ;
}
static void F_40 ( struct V_2 * V_3 , T_2 * V_32 , int V_33 )
{
if ( V_33 <= V_3 -> V_83 )
F_19 ( V_3 , V_32 , V_33 ) ;
else
F_28 ( V_3 , V_32 , V_33 , 0x0 ) ;
}
static void F_41 ( struct V_2 * V_3 ,
const T_2 * V_32 , int V_33 )
{
if ( V_33 <= V_3 -> V_83 )
F_22 ( V_3 , V_32 , V_33 ) ;
else
F_28 ( V_3 , ( T_2 * ) V_32 , V_33 , 0x1 ) ;
}
static T_5 F_42 ( int V_84 , void * V_73 )
{
struct V_1 * V_10 = (struct V_1 * ) V_73 ;
T_1 V_85 ;
V_85 = F_5 ( V_10 -> V_13 . V_46 ) ;
V_85 = F_20 ( V_85 ) ;
V_85 = V_85 & 0xFFFC ;
if ( V_10 -> V_86 == V_87 ) {
if ( V_84 == V_10 -> V_88 )
goto V_89;
if ( V_10 -> V_90 && ( V_10 -> V_90 < V_85 ) )
V_85 = V_10 -> V_90 ;
else if ( ! V_10 -> V_90 )
V_85 = 0 ;
F_43 ( V_10 -> V_4 . V_38 ,
( T_1 * ) V_10 -> V_32 , V_85 >> 2 ) ;
V_10 -> V_32 = V_10 -> V_32 + V_85 ;
V_10 -> V_90 -= V_85 ;
} else {
F_21 ( V_10 -> V_4 . V_35 ,
( T_1 * ) V_10 -> V_32 , V_85 >> 2 ) ;
V_10 -> V_32 = V_10 -> V_32 + V_85 ;
if ( V_84 == V_10 -> V_88 )
goto V_89;
}
return V_91 ;
V_89:
F_27 ( & V_10 -> V_82 ) ;
F_44 ( V_10 -> V_92 ) ;
F_44 ( V_10 -> V_88 ) ;
return V_91 ;
}
static void F_45 ( struct V_2 * V_3 , T_2 * V_32 , int V_33 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_42 = 0 ;
if ( V_33 <= V_3 -> V_83 ) {
F_19 ( V_3 , V_32 , V_33 ) ;
return;
}
V_10 -> V_86 = V_93 ;
V_10 -> V_32 = V_32 ;
F_36 ( & V_10 -> V_82 ) ;
V_42 = F_4 ( V_10 -> V_45 ,
V_12 / 2 , 0x0 , V_33 , 0x0 , V_10 ) ;
if ( V_42 )
goto V_70;
V_10 -> V_90 = V_33 ;
F_46 ( V_10 -> V_88 ) ;
F_46 ( V_10 -> V_92 ) ;
F_38 ( & V_10 -> V_82 ) ;
F_8 ( V_10 -> V_45 , V_10 ) ;
return;
V_70:
if ( V_10 -> V_4 . V_43 & V_44 )
F_15 ( V_3 , V_32 , V_33 ) ;
else
F_11 ( V_3 , V_32 , V_33 ) ;
}
static void F_47 ( struct V_2 * V_3 ,
const T_2 * V_32 , int V_33 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_42 = 0 ;
unsigned long V_49 , V_50 ;
T_1 V_11 ;
if ( V_33 <= V_3 -> V_83 ) {
F_22 ( V_3 , V_32 , V_33 ) ;
return;
}
V_10 -> V_86 = V_87 ;
V_10 -> V_32 = ( T_2 * ) V_32 ;
F_36 ( & V_10 -> V_82 ) ;
V_42 = F_4 ( V_10 -> V_45 ,
( V_12 * 3 ) / 8 , 0x0 , V_33 , 0x1 , V_10 ) ;
if ( V_42 )
goto V_70;
V_10 -> V_90 = V_33 ;
F_46 ( V_10 -> V_88 ) ;
F_46 ( V_10 -> V_92 ) ;
F_38 ( & V_10 -> V_82 ) ;
V_49 = 0 ;
V_50 = ( V_51 * F_23 ( V_52 ) ) ;
do {
V_11 = F_5 ( V_10 -> V_13 . V_46 ) ;
V_11 = F_25 ( V_11 ) ;
F_24 () ;
} while ( V_11 && ( V_49 ++ < V_50 ) );
F_8 ( V_10 -> V_45 , V_10 ) ;
return;
V_70:
if ( V_10 -> V_4 . V_43 & V_44 )
F_17 ( V_3 , V_32 , V_33 ) ;
else
F_13 ( V_3 , V_32 , V_33 ) ;
}
static void F_48 ( T_6 * V_94 )
{
T_1 V_95 = V_94 [ 0 ] | ( V_94 [ 1 ] << 16 ) |
( ( V_94 [ 2 ] & 0xF0 ) << 20 ) | ( ( V_94 [ 2 ] & 0x0F ) << 8 ) ;
V_94 [ 0 ] = ~ ( F_49 ( V_95 ) | F_50 ( V_95 ) | F_51 ( V_95 ) | F_52 ( V_95 ) |
F_53 ( V_95 ) | F_54 ( V_95 ) | F_55 ( V_95 ) | F_56 ( V_95 ) ) ;
V_94 [ 1 ] = ~ ( F_57 ( V_95 ) | F_58 ( V_95 ) | F_59 ( V_95 ) | F_60 ( V_95 ) |
F_61 ( V_95 ) | F_62 ( V_95 ) | F_63 ( V_95 ) | F_64 ( V_95 ) ) ;
V_94 [ 2 ] = ~ ( F_65 ( V_95 ) | F_66 ( V_95 ) | F_67 ( V_95 ) | F_68 ( V_95 ) | F_69 ( V_95 ) |
F_70 ( V_95 ) | F_71 ( V_95 ) | F_72 ( V_95 ) ) ;
}
static int F_73 ( T_6 * V_96 ,
T_6 * V_97 ,
T_6 * V_98 )
{
T_7 V_48 ;
T_6 V_99 [ 8 ] , V_100 [ 8 ] , V_101 [ 8 ] ;
T_6 V_102 [ 8 ] , V_103 [ 8 ] , V_104 [ 8 ] ;
T_6 V_105 [ 24 ] ;
T_6 V_106 = 0 ;
T_6 V_107 = 0 ;
T_7 V_108 = 0 ;
int V_109 ;
V_109 = ( ( * ( T_1 * ) V_96 & 0xFFFFFF ) == 0xFFFFFF ) ;
F_48 ( V_96 ) ;
F_48 ( V_97 ) ;
for ( V_48 = 0 ; V_48 <= 2 ; V_48 ++ ) {
* ( V_96 + V_48 ) = ~ ( * ( V_96 + V_48 ) ) ;
* ( V_97 + V_48 ) = ~ ( * ( V_97 + V_48 ) ) ;
}
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_99 [ V_48 ] = * V_96 % 2 ;
* V_96 = * V_96 / 2 ;
}
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_100 [ V_48 ] = * ( V_96 + 1 ) % 2 ;
* ( V_96 + 1 ) = * ( V_96 + 1 ) / 2 ;
}
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_101 [ V_48 ] = * ( V_96 + 2 ) % 2 ;
* ( V_96 + 2 ) = * ( V_96 + 2 ) / 2 ;
}
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_102 [ V_48 ] = * V_97 % 2 ;
* V_97 = * V_97 / 2 ;
}
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_103 [ V_48 ] = * ( V_97 + 1 ) % 2 ;
* ( V_97 + 1 ) = * ( V_97 + 1 ) / 2 ;
}
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ ) {
V_104 [ V_48 ] = * ( V_97 + 2 ) % 2 ;
* ( V_97 + 2 ) = * ( V_97 + 2 ) / 2 ;
}
for ( V_48 = 0 ; V_48 < 6 ; V_48 ++ )
V_105 [ V_48 ] = V_101 [ V_48 + 2 ] ^ V_104 [ V_48 + 2 ] ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ )
V_105 [ V_48 + 6 ] = V_99 [ V_48 ] ^ V_102 [ V_48 ] ;
for ( V_48 = 0 ; V_48 < 8 ; V_48 ++ )
V_105 [ V_48 + 14 ] = V_100 [ V_48 ] ^ V_103 [ V_48 ] ;
V_105 [ 22 ] = V_101 [ 0 ] ^ V_104 [ 0 ] ;
V_105 [ 23 ] = V_101 [ 1 ] ^ V_104 [ 1 ] ;
for ( V_48 = 0 ; V_48 < 24 ; V_48 ++ )
V_106 += V_105 [ V_48 ] ;
switch ( V_106 ) {
case 0 :
return 0 ;
case 1 :
F_74 ( L_2 ) ;
return - V_110 ;
case 11 :
F_74 ( L_3 ) ;
return - V_110 ;
case 12 :
V_108 = ( V_105 [ 23 ] << 8 ) +
( V_105 [ 21 ] << 7 ) +
( V_105 [ 19 ] << 6 ) +
( V_105 [ 17 ] << 5 ) +
( V_105 [ 15 ] << 4 ) +
( V_105 [ 13 ] << 3 ) +
( V_105 [ 11 ] << 2 ) +
( V_105 [ 9 ] << 1 ) +
V_105 [ 7 ] ;
V_107 = ( V_105 [ 5 ] << 2 ) + ( V_105 [ 3 ] << 1 ) + V_105 [ 1 ] ;
F_74 ( L_4
L_5 , V_108 , V_107 ) ;
V_98 [ V_108 ] ^= ( 1 << V_107 ) ;
return 1 ;
default:
if ( V_109 ) {
if ( V_97 [ 0 ] == 0 &&
V_97 [ 1 ] == 0 &&
V_97 [ 2 ] == 0 )
return 0 ;
}
F_74 ( L_6 ) ;
return - V_110 ;
}
}
static int F_75 ( struct V_2 * V_3 , T_2 * V_111 ,
T_2 * V_112 , T_2 * V_113 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_114 = 0 , V_48 = 0 , V_42 = 0 ;
int V_115 = 0 ;
if ( ( V_10 -> V_4 . V_116 . V_117 == V_118 ) &&
( V_10 -> V_4 . V_116 . V_119 == 2048 ) )
V_114 = 4 ;
else
V_114 = 1 ;
for ( V_48 = 0 ; V_48 < V_114 ; V_48 ++ ) {
if ( memcmp ( V_112 , V_113 , 3 ) != 0 ) {
V_42 = F_73 ( V_112 , V_113 , V_111 ) ;
if ( V_42 < 0 )
return V_42 ;
V_115 += V_42 ;
}
V_112 += 3 ;
V_113 += 3 ;
V_111 += 512 ;
}
return V_115 ;
}
static int F_76 ( struct V_2 * V_3 , const T_2 * V_111 ,
T_2 * V_120 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
T_1 V_11 ;
V_11 = F_5 ( V_10 -> V_13 . V_121 ) ;
if ( ( ( V_11 >> V_122 ) & V_22 ) != V_10 -> V_45 )
return - V_23 ;
V_11 = F_5 ( V_10 -> V_13 . V_123 ) ;
* V_120 ++ = V_11 ;
* V_120 ++ = V_11 >> 16 ;
* V_120 ++ = ( ( V_11 >> 8 ) & 0x0f ) | ( ( V_11 >> 20 ) & 0xf0 ) ;
return 0 ;
}
static void F_77 ( struct V_2 * V_3 , int V_117 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_34 * V_124 = F_3 ( V_3 ) ;
unsigned int V_125 = ( V_124 -> V_43 & V_44 ) ? 1 : 0 ;
T_1 V_11 ;
V_11 = V_126 | V_127 ;
F_6 ( V_11 , V_10 -> V_13 . V_128 ) ;
V_11 = ( ( ( ( V_10 -> V_4 . V_116 . V_119 >> 1 ) - 1 ) << V_129 ) |
V_130 ) ;
F_6 ( V_11 , V_10 -> V_13 . V_131 ) ;
switch ( V_117 ) {
case V_132 :
case V_133 :
F_6 ( V_126 | V_127 , V_10 -> V_13 . V_128 ) ;
break;
case V_134 :
F_6 ( V_126 , V_10 -> V_13 . V_128 ) ;
break;
default:
F_78 ( & V_10 -> V_74 -> V_73 ,
L_7 , V_117 ) ;
break;
}
V_11 = ( V_125 << 7 ) | ( V_10 -> V_45 << 1 ) | ( 0x1 ) ;
F_6 ( V_11 , V_10 -> V_13 . V_121 ) ;
}
static int F_79 ( struct V_2 * V_3 , struct V_34 * V_124 )
{
struct V_34 * V_135 = F_3 ( V_3 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
unsigned long V_136 = V_137 ;
int V_37 , V_138 = V_135 -> V_138 ;
if ( V_138 == V_139 )
V_136 += F_23 ( 400 ) ;
else
V_136 += F_23 ( 20 ) ;
F_10 ( V_140 & 0xFF , V_10 -> V_13 . V_28 ) ;
while ( F_80 ( V_137 , V_136 ) ) {
V_37 = F_81 ( V_10 -> V_13 . V_31 ) ;
if ( V_37 & V_141 )
break;
F_82 () ;
}
V_37 = F_81 ( V_10 -> V_13 . V_31 ) ;
return V_37 ;
}
static int F_83 ( struct V_2 * V_3 )
{
unsigned int V_11 = 0 ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
V_11 = F_5 ( V_10 -> V_13 . V_39 ) ;
if ( ( V_11 & 0x100 ) == 0x100 ) {
return 1 ;
} else {
return 0 ;
}
}
static void T_8 F_84 ( struct V_2 * V_3 , int V_117 )
{
unsigned int V_142 ;
unsigned int V_125 , V_143 ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
enum V_144 V_145 = V_10 -> V_145 ;
struct V_34 * V_124 = F_3 ( V_3 ) ;
T_1 V_11 , V_146 ;
unsigned int V_147 , V_148 ;
switch ( V_145 ) {
case V_149 :
V_142 = 0 ;
V_143 = 1 ;
V_146 = V_150 ;
V_148 = V_151 ;
V_147 = V_152 ;
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
V_146 = V_150 ;
V_148 = V_151 ;
V_147 = V_152 ;
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
case V_162 :
V_142 = 0x2 ;
V_143 = V_124 -> V_116 . V_154 ;
if ( V_117 == V_132 ) {
V_146 = 0x01 ;
V_148 = 52 ;
V_147 = 0 ;
} else {
V_146 = 0x01 ;
V_148 = 0 ;
V_147 = 52 ;
}
break;
default:
return;
}
F_6 ( V_127 , V_10 -> V_13 . V_128 ) ;
V_11 = ( V_147 << V_129 ) | ( V_148 << V_163 ) ;
F_6 ( V_11 , V_10 -> V_13 . V_131 ) ;
V_125 = ( V_124 -> V_43 & V_44 ) ? 1 : 0 ;
V_11 = ( ( 1 << 16 ) |
( V_142 << 12 ) |
( V_146 << 8 ) |
( V_125 << 7 ) |
( ( ( V_143 - 1 ) & 0x7 ) << 4 ) |
( V_10 -> V_45 << 1 ) |
( 0x1 ) ) ;
F_6 ( V_11 , V_10 -> V_13 . V_121 ) ;
F_6 ( V_126 | V_127 , V_10 -> V_13 . V_128 ) ;
}
static int T_8 F_85 ( struct V_2 * V_3 ,
const T_2 * V_111 , T_2 * V_164 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
int V_165 = V_10 -> V_4 . V_116 . V_85 ;
struct V_166 * V_167 = & V_10 -> V_13 ;
T_6 * V_120 ;
unsigned long V_143 , V_168 , V_169 , V_170 , V_171 ;
T_1 V_11 ;
int V_48 , V_172 ;
V_143 = ( ( F_5 ( V_10 -> V_13 . V_121 ) >> 4 ) & 0x7 ) + 1 ;
for ( V_48 = 0 ; V_48 < V_143 ; V_48 ++ ) {
V_120 = V_164 ;
switch ( V_10 -> V_145 ) {
case V_158 :
case V_159 :
V_168 = F_5 ( V_167 -> V_173 [ V_48 ] ) ;
V_169 = F_5 ( V_167 -> V_174 [ V_48 ] ) ;
V_170 = F_5 ( V_167 -> V_175 [ V_48 ] ) ;
V_171 = F_5 ( V_167 -> V_176 [ V_48 ] ) ;
* V_120 ++ = ( V_171 & 0xFF ) ;
* V_120 ++ = ( ( V_170 >> 24 ) & 0xFF ) ;
* V_120 ++ = ( ( V_170 >> 16 ) & 0xFF ) ;
* V_120 ++ = ( ( V_170 >> 8 ) & 0xFF ) ;
* V_120 ++ = ( V_170 & 0xFF ) ;
* V_120 ++ = ( ( V_169 >> 24 ) & 0xFF ) ;
* V_120 ++ = ( ( V_169 >> 16 ) & 0xFF ) ;
* V_120 ++ = ( ( V_169 >> 8 ) & 0xFF ) ;
* V_120 ++ = ( V_169 & 0xFF ) ;
* V_120 ++ = ( ( V_168 >> 24 ) & 0xFF ) ;
* V_120 ++ = ( ( V_168 >> 16 ) & 0xFF ) ;
* V_120 ++ = ( ( V_168 >> 8 ) & 0xFF ) ;
* V_120 ++ = ( V_168 & 0xFF ) ;
break;
case V_149 :
case V_153 :
V_168 = F_5 ( V_167 -> V_173 [ V_48 ] ) ;
V_169 = F_5 ( V_167 -> V_174 [ V_48 ] ) ;
* V_120 ++ = ( ( V_169 >> 12 ) & 0xFF ) ;
* V_120 ++ = ( ( V_169 >> 4 ) & 0xFF ) ;
* V_120 ++ = ( ( V_169 & 0xF ) << 4 ) |
( ( V_168 >> 28 ) & 0xF ) ;
* V_120 ++ = ( ( V_168 >> 20 ) & 0xFF ) ;
* V_120 ++ = ( ( V_168 >> 12 ) & 0xFF ) ;
* V_120 ++ = ( ( V_168 >> 4 ) & 0xFF ) ;
* V_120 ++ = ( ( V_168 & 0xF ) << 4 ) ;
break;
case V_162 :
V_11 = F_5 ( V_167 -> V_177 [ V_48 ] ) ;
V_120 [ 0 ] = ( ( V_11 >> 8 ) & 0xFF ) ;
V_120 [ 1 ] = ( ( V_11 >> 0 ) & 0xFF ) ;
V_11 = F_5 ( V_167 -> V_178 [ V_48 ] ) ;
V_120 [ 2 ] = ( ( V_11 >> 24 ) & 0xFF ) ;
V_120 [ 3 ] = ( ( V_11 >> 16 ) & 0xFF ) ;
V_120 [ 4 ] = ( ( V_11 >> 8 ) & 0xFF ) ;
V_120 [ 5 ] = ( ( V_11 >> 0 ) & 0xFF ) ;
V_11 = F_5 ( V_167 -> V_179 [ V_48 ] ) ;
V_120 [ 6 ] = ( ( V_11 >> 24 ) & 0xFF ) ;
V_120 [ 7 ] = ( ( V_11 >> 16 ) & 0xFF ) ;
V_120 [ 8 ] = ( ( V_11 >> 8 ) & 0xFF ) ;
V_120 [ 9 ] = ( ( V_11 >> 0 ) & 0xFF ) ;
V_11 = F_5 ( V_167 -> V_176 [ V_48 ] ) ;
V_120 [ 10 ] = ( ( V_11 >> 24 ) & 0xFF ) ;
V_120 [ 11 ] = ( ( V_11 >> 16 ) & 0xFF ) ;
V_120 [ 12 ] = ( ( V_11 >> 8 ) & 0xFF ) ;
V_120 [ 13 ] = ( ( V_11 >> 0 ) & 0xFF ) ;
V_11 = F_5 ( V_167 -> V_175 [ V_48 ] ) ;
V_120 [ 14 ] = ( ( V_11 >> 24 ) & 0xFF ) ;
V_120 [ 15 ] = ( ( V_11 >> 16 ) & 0xFF ) ;
V_120 [ 16 ] = ( ( V_11 >> 8 ) & 0xFF ) ;
V_120 [ 17 ] = ( ( V_11 >> 0 ) & 0xFF ) ;
V_11 = F_5 ( V_167 -> V_174 [ V_48 ] ) ;
V_120 [ 18 ] = ( ( V_11 >> 24 ) & 0xFF ) ;
V_120 [ 19 ] = ( ( V_11 >> 16 ) & 0xFF ) ;
V_120 [ 20 ] = ( ( V_11 >> 8 ) & 0xFF ) ;
V_120 [ 21 ] = ( ( V_11 >> 0 ) & 0xFF ) ;
V_11 = F_5 ( V_167 -> V_173 [ V_48 ] ) ;
V_120 [ 22 ] = ( ( V_11 >> 24 ) & 0xFF ) ;
V_120 [ 23 ] = ( ( V_11 >> 16 ) & 0xFF ) ;
V_120 [ 24 ] = ( ( V_11 >> 8 ) & 0xFF ) ;
V_120 [ 25 ] = ( ( V_11 >> 0 ) & 0xFF ) ;
break;
default:
return - V_23 ;
}
switch ( V_10 -> V_145 ) {
case V_149 :
for ( V_172 = 0 ; V_172 < V_165 ; V_172 ++ )
V_164 [ V_172 ] ^= V_180 [ V_172 ] ;
break;
case V_153 :
V_164 [ V_165 - 1 ] = 0x0 ;
break;
case V_158 :
for ( V_172 = 0 ; V_172 < V_165 ; V_172 ++ )
V_164 [ V_172 ] ^= V_181 [ V_172 ] ;
break;
case V_159 :
V_164 [ V_165 - 1 ] = 0x0 ;
break;
case V_162 :
break;
default:
return - V_23 ;
}
V_164 += V_165 ;
}
return 0 ;
}
static int F_86 ( T_2 * V_53 , T_2 * V_182 ,
struct V_1 * V_10 )
{
int V_183 = 0 , V_48 ;
for ( V_48 = 0 ; V_48 < V_10 -> V_4 . V_116 . V_119 ; V_48 ++ ) {
V_183 += F_87 ( ~ V_53 [ V_48 ] ) ;
if ( V_183 > V_10 -> V_4 . V_116 . V_184 )
return 0 ;
}
for ( V_48 = 0 ; V_48 < V_10 -> V_4 . V_116 . V_85 - 1 ; V_48 ++ ) {
V_183 += F_87 ( ~ V_182 [ V_48 ] ) ;
if ( V_183 > V_10 -> V_4 . V_116 . V_184 )
return 0 ;
}
if ( V_183 ) {
memset ( V_53 , 0xFF , V_10 -> V_4 . V_116 . V_119 ) ;
memset ( V_182 , 0xFF , V_10 -> V_4 . V_116 . V_85 ) ;
}
return V_183 ;
}
static int F_88 ( struct V_2 * V_3 , T_2 * V_53 ,
T_2 * V_112 , T_2 * V_113 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
struct V_185 * V_116 = & V_10 -> V_4 . V_116 ;
int V_186 = V_10 -> V_4 . V_116 . V_154 ;
int V_48 , V_172 , V_115 = 0 ;
int V_187 , V_188 ;
struct V_189 V_190 [ V_191 ] ;
T_2 * V_192 = V_113 ;
T_2 * V_193 = V_112 ;
T_2 * V_194 ;
T_2 * V_32 ;
int V_195 ;
bool V_196 = false ;
T_1 V_197 , V_198 , V_199 , V_200 ;
int V_201 ;
switch ( V_10 -> V_145 ) {
case V_153 :
V_188 = V_116 -> V_85 - 1 ;
V_194 = V_202 ;
break;
case V_159 :
V_188 = V_116 -> V_85 - 1 ;
V_194 = V_203 ;
break;
case V_162 :
V_188 = V_116 -> V_85 ;
V_194 = V_204 ;
break;
default:
F_33 ( & V_10 -> V_74 -> V_73 , L_8 ) ;
return - V_23 ;
}
memset ( V_190 , 0 , sizeof( V_190 ) ) ;
for ( V_48 = 0 ; V_48 < V_186 ; V_48 ++ ) {
V_187 = 0 ;
for ( V_172 = 0 ; V_172 < V_188 ; V_172 ++ ) {
if ( V_113 [ V_172 ] != 0 ) {
V_187 = 1 ;
break;
}
}
if ( V_187 == 1 ) {
if ( memcmp ( V_113 , V_194 ,
V_188 ) == 0 ) {
} else {
V_32 = & V_53 [ V_10 -> V_4 . V_116 . V_119 * V_48 ] ;
V_195 = F_86 (
V_32 , V_112 , V_10 ) ;
if ( V_195 ) {
V_115 += V_195 ;
} else {
V_190 [ V_48 ] . V_205 = true ;
V_196 = true ;
}
}
}
V_113 += V_116 -> V_85 ;
V_112 += V_116 -> V_85 ;
}
if ( ! V_196 )
return V_115 ;
F_89 ( V_10 -> V_206 , V_192 , V_190 ) ;
V_201 = 0 ;
for ( V_48 = 0 ; V_48 < V_186 ; V_48 ++ ) {
if ( V_190 [ V_48 ] . V_207 ) {
F_33 ( & V_10 -> V_74 -> V_73 ,
L_9 ) ;
V_201 = - V_110 ;
} else if ( V_190 [ V_48 ] . V_205 ) {
for ( V_172 = 0 ; V_172 < V_190 [ V_48 ] . V_208 ; V_172 ++ ) {
switch ( V_10 -> V_145 ) {
case V_153 :
V_200 = V_190 [ V_48 ] . V_209 [ V_172 ] +
V_210 ;
break;
case V_159 :
case V_162 :
V_200 = V_190 [ V_48 ] . V_209 [ V_172 ] ;
break;
default:
return - V_23 ;
}
V_199 = ( V_116 -> V_119 + V_188 ) * 8 ;
V_197 = V_200 % 8 ;
V_198 = ( V_199 - V_200 - 1 ) / 8 ;
if ( V_200 < V_199 ) {
if ( V_198 < 512 ) {
F_74 ( L_10 ,
V_198 , V_53 [ V_198 ] ) ;
V_53 [ V_198 ] ^= 1 << V_197 ;
} else {
F_74 ( L_11 ,
( V_198 - 512 ) ,
V_193 [ V_198 - 512 ] ) ;
V_193 [ V_198 - 512 ] ^=
1 << V_197 ;
}
} else {
F_33 ( & V_10 -> V_74 -> V_73 ,
L_12 ,
V_198 , V_197 ) ;
V_201 = - V_110 ;
}
}
}
V_115 += V_190 [ V_48 ] . V_208 ;
V_53 += V_116 -> V_119 ;
V_193 += V_116 -> V_85 ;
}
return ( V_201 ) ? V_201 : V_115 ;
}
static int F_90 ( struct V_2 * V_3 , struct V_34 * V_124 ,
const T_9 * V_32 , int V_211 , int V_66 )
{
int V_48 ;
T_9 * V_164 = V_124 -> V_212 -> V_213 ;
T_4 * V_214 = V_124 -> V_116 . V_215 -> V_214 ;
V_124 -> V_116 . V_216 ( V_3 , V_133 ) ;
V_124 -> V_217 ( V_3 , V_32 , V_3 -> V_218 ) ;
V_124 -> V_116 . V_219 ( V_3 , V_32 , & V_164 [ 0 ] ) ;
for ( V_48 = 0 ; V_48 < V_124 -> V_116 . V_220 ; V_48 ++ )
V_124 -> V_221 [ V_214 [ V_48 ] ] = V_164 [ V_48 ] ;
V_124 -> V_217 ( V_3 , V_124 -> V_221 , V_3 -> V_83 ) ;
return 0 ;
}
static int F_91 ( struct V_2 * V_3 , struct V_34 * V_124 ,
T_9 * V_32 , int V_211 , int V_66 )
{
T_9 * V_164 = V_124 -> V_212 -> V_213 ;
T_9 * V_120 = V_124 -> V_212 -> V_222 ;
T_4 * V_214 = V_124 -> V_116 . V_215 -> V_214 ;
T_9 * V_182 = & V_124 -> V_221 [ V_214 [ 0 ] ] ;
T_4 V_223 = V_3 -> V_218 + V_124 -> V_116 . V_215 -> V_214 [ 0 ] ;
int V_115 ;
unsigned int V_224 = 0 ;
V_124 -> V_116 . V_216 ( V_3 , V_132 ) ;
V_124 -> V_225 ( V_3 , V_32 , V_3 -> V_218 ) ;
V_124 -> V_226 ( V_3 , V_227 , V_223 , - 1 ) ;
V_124 -> V_225 ( V_3 , V_182 , V_124 -> V_116 . V_220 ) ;
V_124 -> V_116 . V_219 ( V_3 , V_32 , V_164 ) ;
memcpy ( V_120 , & V_124 -> V_221 [ V_214 [ 0 ] ] , V_124 -> V_116 . V_220 ) ;
V_115 = V_124 -> V_116 . V_228 ( V_3 , V_32 , V_120 , V_164 ) ;
if ( V_115 < 0 ) {
V_3 -> V_229 . V_230 ++ ;
} else {
V_3 -> V_229 . V_231 += V_115 ;
V_224 = F_92 (unsigned int, max_bitflips, stat) ;
}
return V_224 ;
}
static bool F_93 ( struct V_1 * V_10 ,
struct V_232 * V_233 )
{
struct V_234 * V_74 ;
if ( ! V_233 ) {
F_33 ( & V_10 -> V_74 -> V_73 , L_13 ) ;
return false ;
}
V_74 = F_94 ( V_233 ) ;
if ( ! V_74 ) {
F_33 ( & V_10 -> V_74 -> V_73 , L_14 ) ;
return false ;
}
V_10 -> V_206 = & V_74 -> V_73 ;
return true ;
}
static bool F_95 ( struct V_1 * V_10 ,
struct V_235 * V_236 )
{
bool V_237 , V_238 , V_239 ;
switch ( V_10 -> V_145 ) {
case V_149 :
case V_158 :
V_238 = false ;
V_237 = true ;
V_239 = false ;
break;
case V_153 :
case V_159 :
case V_162 :
V_238 = true ;
V_237 = false ;
V_239 = true ;
break;
default:
V_238 = false ;
V_237 = false ;
V_239 = false ;
break;
}
if ( V_237 && ! F_96 ( V_240 ) ) {
F_33 ( & V_10 -> V_74 -> V_73 ,
L_15 ) ;
return false ;
}
if ( V_238 && ! F_96 ( V_241 ) ) {
F_33 ( & V_10 -> V_74 -> V_73 ,
L_16 ) ;
return false ;
}
if ( V_239 && ! F_93 ( V_10 , V_236 -> V_242 ) ) {
F_33 ( & V_10 -> V_74 -> V_73 , L_17 ) ;
return false ;
}
return true ;
}
static int F_97 ( struct V_234 * V_74 )
{
struct V_1 * V_10 ;
struct V_235 * V_236 ;
struct V_2 * V_3 ;
struct V_34 * V_34 ;
struct V_243 * V_244 ;
int V_201 ;
int V_48 ;
T_10 V_245 ;
unsigned V_246 ;
unsigned V_247 ;
struct V_248 * V_249 ;
V_236 = F_98 ( & V_74 -> V_73 ) ;
if ( V_236 == NULL ) {
F_33 ( & V_74 -> V_73 , L_18 ) ;
return - V_250 ;
}
V_10 = F_99 ( & V_74 -> V_73 , sizeof( struct V_1 ) ,
V_251 ) ;
if ( ! V_10 )
return - V_252 ;
F_100 ( V_74 , V_10 ) ;
V_10 -> V_74 = V_74 ;
V_10 -> V_45 = V_236 -> V_5 ;
V_10 -> V_13 = V_236 -> V_13 ;
V_10 -> V_253 = V_236 -> V_253 ;
V_10 -> V_145 = V_236 -> V_145 ;
V_34 = & V_10 -> V_4 ;
V_3 = F_101 ( V_34 ) ;
V_3 -> V_73 . V_254 = & V_74 -> V_73 ;
V_34 -> V_116 . V_255 = NULL ;
F_102 ( V_34 , V_236 -> V_253 ) ;
V_249 = F_103 ( V_74 , V_256 , 0 ) ;
V_34 -> V_35 = F_104 ( & V_74 -> V_73 , V_249 ) ;
if ( F_105 ( V_34 -> V_35 ) )
return F_106 ( V_34 -> V_35 ) ;
V_10 -> V_257 = V_249 -> V_258 ;
V_34 -> V_259 = & V_260 ;
V_34 -> V_38 = V_34 -> V_35 ;
V_34 -> V_261 = F_9 ;
if ( V_236 -> V_262 ) {
V_34 -> V_262 = F_83 ;
V_34 -> V_263 = 0 ;
} else {
V_34 -> V_264 = F_79 ;
V_34 -> V_263 = 50 ;
}
if ( V_236 -> V_265 )
V_34 -> V_266 |= V_267 | V_268 ;
else
V_34 -> V_43 |= V_269 ;
V_34 -> V_43 |= V_236 -> V_270 & V_44 ;
if ( F_107 ( V_3 , 1 , NULL ) ) {
F_33 ( & V_10 -> V_74 -> V_73 , L_19 ) ;
V_201 = - V_271 ;
goto V_272;
}
switch ( V_236 -> V_273 ) {
case V_274 :
V_34 -> V_225 = F_19 ;
V_34 -> V_217 = F_22 ;
break;
case V_275 :
break;
case V_276 :
F_108 ( V_245 ) ;
F_109 ( V_277 , V_245 ) ;
V_246 = V_278 ;
V_10 -> V_71 = F_110 ( V_245 , V_279 , & V_246 ) ;
if ( ! V_10 -> V_71 ) {
F_33 ( & V_74 -> V_73 , L_20 ) ;
V_201 = - V_271 ;
goto V_272;
} else {
struct V_280 V_281 ;
memset ( & V_281 , 0 , sizeof( V_281 ) ) ;
V_281 . V_282 = V_10 -> V_257 ;
V_281 . V_283 = V_10 -> V_257 ;
V_281 . V_284 = V_285 ;
V_281 . V_286 = V_285 ;
V_281 . V_287 = 16 ;
V_281 . V_288 = 16 ;
V_201 = F_111 ( V_10 -> V_71 , & V_281 ) ;
if ( V_201 ) {
F_33 ( & V_74 -> V_73 , L_21 ,
V_201 ) ;
goto V_272;
}
V_34 -> V_225 = F_40 ;
V_34 -> V_217 = F_41 ;
}
break;
case V_289 :
V_10 -> V_92 = F_112 ( V_74 , 0 ) ;
if ( V_10 -> V_92 <= 0 ) {
F_33 ( & V_74 -> V_73 , L_22 ) ;
V_201 = - V_250 ;
goto V_272;
}
V_201 = F_113 ( & V_74 -> V_73 , V_10 -> V_92 ,
F_42 , V_290 ,
L_23 , V_10 ) ;
if ( V_201 ) {
F_33 ( & V_74 -> V_73 , L_24 ,
V_10 -> V_92 , V_201 ) ;
V_10 -> V_92 = 0 ;
goto V_272;
}
V_10 -> V_88 = F_112 ( V_74 , 1 ) ;
if ( V_10 -> V_88 <= 0 ) {
F_33 ( & V_74 -> V_73 , L_25 ) ;
V_201 = - V_250 ;
goto V_272;
}
V_201 = F_113 ( & V_74 -> V_73 , V_10 -> V_88 ,
F_42 , V_290 ,
L_26 , V_10 ) ;
if ( V_201 ) {
F_33 ( & V_74 -> V_73 , L_24 ,
V_10 -> V_88 , V_201 ) ;
V_10 -> V_88 = 0 ;
goto V_272;
}
V_34 -> V_225 = F_45 ;
V_34 -> V_217 = F_47 ;
break;
default:
F_33 ( & V_74 -> V_73 ,
L_27 , V_236 -> V_273 ) ;
V_201 = - V_23 ;
goto V_272;
}
if ( ! F_95 ( V_10 , V_236 ) ) {
V_201 = - V_23 ;
goto V_272;
}
V_244 = & V_10 -> V_291 ;
switch ( V_10 -> V_145 ) {
case V_292 :
V_34 -> V_116 . V_117 = V_293 ;
break;
case V_294 :
F_114 ( L_28 ) ;
V_34 -> V_116 . V_117 = V_118 ;
V_34 -> V_116 . V_85 = 3 ;
V_34 -> V_116 . V_119 = 512 ;
V_34 -> V_116 . V_184 = 1 ;
V_34 -> V_116 . V_219 = F_76 ;
V_34 -> V_116 . V_216 = F_77 ;
V_34 -> V_116 . V_228 = F_75 ;
V_244 -> V_165 = V_34 -> V_116 . V_85 *
( V_3 -> V_218 /
V_34 -> V_116 . V_119 ) ;
if ( V_34 -> V_43 & V_44 )
V_247 = V_295 ;
else
V_247 = 1 ;
for ( V_48 = 0 ; V_48 < V_244 -> V_165 ; V_48 ++ , V_247 ++ )
V_244 -> V_214 [ V_48 ] = V_247 ;
V_244 -> V_296 -> V_297 =
V_244 -> V_214 [ V_244 -> V_165 - 1 ] + 1 ;
break;
case V_149 :
F_114 ( L_29 ) ;
V_34 -> V_116 . V_117 = V_118 ;
V_34 -> V_116 . V_119 = 512 ;
V_34 -> V_116 . V_85 = 7 ;
V_34 -> V_116 . V_184 = 4 ;
V_34 -> V_116 . V_216 = F_84 ;
V_34 -> V_116 . V_228 = V_298 ;
V_34 -> V_116 . V_219 = F_85 ;
V_244 -> V_165 = V_34 -> V_116 . V_85 *
( V_3 -> V_218 /
V_34 -> V_116 . V_119 ) ;
V_247 = V_295 ;
for ( V_48 = 0 ; V_48 < V_244 -> V_165 ; V_48 ++ , V_247 ++ ) {
V_244 -> V_214 [ V_48 ] = V_247 ;
if ( ( ( V_48 + 1 ) % V_34 -> V_116 . V_85 ) == 0 )
V_247 ++ ;
}
V_244 -> V_296 -> V_297 = 1 +
V_244 -> V_214 [ V_244 -> V_165 - 1 ] + 1 ;
V_34 -> V_116 . V_255 = F_115 ( V_3 ,
V_34 -> V_116 . V_119 ,
V_34 -> V_116 . V_85 ,
& V_244 ) ;
if ( ! V_34 -> V_116 . V_255 ) {
F_33 ( & V_10 -> V_74 -> V_73 , L_30 ) ;
V_201 = - V_23 ;
goto V_272;
}
break;
case V_153 :
F_114 ( L_31 ) ;
V_34 -> V_116 . V_117 = V_118 ;
V_34 -> V_116 . V_119 = 512 ;
V_34 -> V_116 . V_85 = 7 + 1 ;
V_34 -> V_116 . V_184 = 4 ;
V_34 -> V_116 . V_216 = F_84 ;
V_34 -> V_116 . V_228 = F_88 ;
V_34 -> V_116 . V_219 = F_85 ;
V_34 -> V_116 . V_299 = F_91 ;
V_34 -> V_116 . V_300 = F_90 ;
V_244 -> V_165 = V_34 -> V_116 . V_85 *
( V_3 -> V_218 /
V_34 -> V_116 . V_119 ) ;
V_247 = V_295 ;
for ( V_48 = 0 ; V_48 < V_244 -> V_165 ; V_48 ++ , V_247 ++ )
V_244 -> V_214 [ V_48 ] = V_247 ;
V_244 -> V_296 -> V_297 =
V_244 -> V_214 [ V_244 -> V_165 - 1 ] + 1 ;
V_201 = F_116 ( V_10 -> V_206 , V_301 ,
V_3 -> V_218 / V_34 -> V_116 . V_119 ,
V_34 -> V_116 . V_119 , V_34 -> V_116 . V_85 ) ;
if ( V_201 < 0 )
goto V_272;
break;
case V_158 :
F_114 ( L_32 ) ;
V_34 -> V_116 . V_117 = V_118 ;
V_34 -> V_116 . V_119 = 512 ;
V_34 -> V_116 . V_85 = 13 ;
V_34 -> V_116 . V_184 = 8 ;
V_34 -> V_116 . V_216 = F_84 ;
V_34 -> V_116 . V_228 = V_298 ;
V_34 -> V_116 . V_219 = F_85 ;
V_244 -> V_165 = V_34 -> V_116 . V_85 *
( V_3 -> V_218 /
V_34 -> V_116 . V_119 ) ;
V_247 = V_295 ;
for ( V_48 = 0 ; V_48 < V_244 -> V_165 ; V_48 ++ , V_247 ++ ) {
V_244 -> V_214 [ V_48 ] = V_247 ;
if ( ( ( V_48 + 1 ) % V_34 -> V_116 . V_85 ) == 0 )
V_247 ++ ;
}
V_244 -> V_296 -> V_297 = 1 +
V_244 -> V_214 [ V_244 -> V_165 - 1 ] + 1 ;
V_34 -> V_116 . V_255 = F_115 ( V_3 ,
V_34 -> V_116 . V_119 ,
V_34 -> V_116 . V_85 ,
& V_244 ) ;
if ( ! V_34 -> V_116 . V_255 ) {
F_33 ( & V_10 -> V_74 -> V_73 , L_30 ) ;
V_201 = - V_23 ;
goto V_272;
}
break;
case V_159 :
F_114 ( L_33 ) ;
V_34 -> V_116 . V_117 = V_118 ;
V_34 -> V_116 . V_119 = 512 ;
V_34 -> V_116 . V_85 = 13 + 1 ;
V_34 -> V_116 . V_184 = 8 ;
V_34 -> V_116 . V_216 = F_84 ;
V_34 -> V_116 . V_228 = F_88 ;
V_34 -> V_116 . V_219 = F_85 ;
V_34 -> V_116 . V_299 = F_91 ;
V_34 -> V_116 . V_300 = F_90 ;
V_201 = F_116 ( V_10 -> V_206 , V_302 ,
V_3 -> V_218 / V_34 -> V_116 . V_119 ,
V_34 -> V_116 . V_119 , V_34 -> V_116 . V_85 ) ;
if ( V_201 < 0 )
goto V_272;
V_244 -> V_165 = V_34 -> V_116 . V_85 *
( V_3 -> V_218 /
V_34 -> V_116 . V_119 ) ;
V_247 = V_295 ;
for ( V_48 = 0 ; V_48 < V_244 -> V_165 ; V_48 ++ , V_247 ++ )
V_244 -> V_214 [ V_48 ] = V_247 ;
V_244 -> V_296 -> V_297 =
V_244 -> V_214 [ V_244 -> V_165 - 1 ] + 1 ;
break;
case V_162 :
F_114 ( L_34 ) ;
V_34 -> V_116 . V_117 = V_118 ;
V_34 -> V_116 . V_119 = 512 ;
V_34 -> V_116 . V_85 = 26 ;
V_34 -> V_116 . V_184 = 16 ;
V_34 -> V_116 . V_216 = F_84 ;
V_34 -> V_116 . V_228 = F_88 ;
V_34 -> V_116 . V_219 = F_85 ;
V_34 -> V_116 . V_299 = F_91 ;
V_34 -> V_116 . V_300 = F_90 ;
V_201 = F_116 ( V_10 -> V_206 , V_303 ,
V_3 -> V_218 / V_34 -> V_116 . V_119 ,
V_34 -> V_116 . V_119 , V_34 -> V_116 . V_85 ) ;
if ( V_201 < 0 )
goto V_272;
V_244 -> V_165 = V_34 -> V_116 . V_85 *
( V_3 -> V_218 /
V_34 -> V_116 . V_119 ) ;
V_247 = V_295 ;
for ( V_48 = 0 ; V_48 < V_244 -> V_165 ; V_48 ++ , V_247 ++ )
V_244 -> V_214 [ V_48 ] = V_247 ;
V_244 -> V_296 -> V_297 =
V_244 -> V_214 [ V_244 -> V_165 - 1 ] + 1 ;
break;
default:
F_33 ( & V_10 -> V_74 -> V_73 , L_35 ) ;
V_201 = - V_23 ;
goto V_272;
}
if ( V_10 -> V_145 == V_292 )
goto V_304;
V_244 -> V_296 -> V_305 = V_3 -> V_83 - V_244 -> V_296 -> V_297 ;
if ( V_3 -> V_83 < ( V_244 -> V_165 + V_295 ) ) {
F_33 ( & V_10 -> V_74 -> V_73 ,
L_36 ,
V_244 -> V_165 , V_3 -> V_83 ) ;
V_201 = - V_23 ;
goto V_272;
}
V_34 -> V_116 . V_215 = V_244 ;
V_304:
if ( F_117 ( V_3 ) ) {
V_201 = - V_271 ;
goto V_272;
}
F_118 ( V_3 , V_236 -> V_306 , V_236 -> V_307 ) ;
F_100 ( V_74 , V_3 ) ;
return 0 ;
V_272:
if ( V_10 -> V_71 )
F_119 ( V_10 -> V_71 ) ;
if ( V_34 -> V_116 . V_255 ) {
F_120 ( V_34 -> V_116 . V_255 ) ;
V_34 -> V_116 . V_255 = NULL ;
}
return V_201 ;
}
static int F_121 ( struct V_234 * V_74 )
{
struct V_2 * V_3 = F_122 ( V_74 ) ;
struct V_34 * V_34 = F_3 ( V_3 ) ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
if ( V_34 -> V_116 . V_255 ) {
F_120 ( V_34 -> V_116 . V_255 ) ;
V_34 -> V_116 . V_255 = NULL ;
}
if ( V_10 -> V_71 )
F_119 ( V_10 -> V_71 ) ;
F_123 ( V_3 ) ;
return 0 ;
}
