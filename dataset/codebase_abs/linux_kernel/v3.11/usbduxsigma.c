static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 ) {
int V_7 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_8 ; V_7 ++ ) {
if ( V_5 -> V_9 [ V_7 ] )
F_2 ( V_5 -> V_9 [ V_7 ] ) ;
}
}
V_5 -> V_10 = 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_4 ( & V_5 -> V_13 ) ;
F_1 ( V_2 , V_5 -> V_10 ) ;
F_5 ( & V_5 -> V_13 ) ;
return 0 ;
}
static void F_6 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_11 * V_12 = V_2 -> V_16 ;
unsigned int V_17 ;
T_1 V_18 ;
int V_19 ;
int V_7 ;
switch ( V_14 -> V_20 ) {
case 0 :
memcpy ( V_5 -> V_21 , V_14 -> V_22 , V_23 ) ;
break;
case - V_24 :
F_7 ( V_2 -> V_25 , L_1 ) ;
break;
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
if ( V_5 -> V_10 ) {
F_1 ( V_2 , 0 ) ;
V_12 -> V_30 -> V_31 |= ( V_32 | V_33 ) ;
F_8 ( V_2 , V_12 ) ;
}
return;
default:
if ( V_5 -> V_10 ) {
F_9 ( V_2 -> V_25 ,
L_2 ,
V_34 , V_14 -> V_20 ) ;
F_1 ( V_2 , 0 ) ;
V_12 -> V_30 -> V_31 |= ( V_32 | V_33 ) ;
F_8 ( V_2 , V_12 ) ;
}
return;
}
if ( F_10 ( ! V_5 -> V_10 ) )
return;
V_14 -> V_2 = F_11 ( V_2 ) ;
V_19 = F_12 ( V_14 , V_35 ) ;
if ( F_10 ( V_19 < 0 ) ) {
F_9 ( V_2 -> V_25 , L_3 ,
V_34 , V_19 ) ;
if ( V_19 == - V_36 )
F_9 ( V_2 -> V_25 ,
L_4 ) ;
F_1 ( V_2 , 0 ) ;
V_12 -> V_30 -> V_31 |= ( V_32 | V_33 ) ;
F_8 ( V_2 , V_12 ) ;
return;
}
V_17 = F_13 ( V_5 -> V_21 [ 0 ] ) ;
V_5 -> V_37 -- ;
if ( F_14 ( V_5 -> V_37 > 0 ) )
return;
V_5 -> V_37 = V_5 -> V_38 ;
if ( ! V_5 -> V_39 ) {
V_5 -> V_40 -- ;
if ( V_5 -> V_40 < 0 ) {
F_1 ( V_2 , 0 ) ;
V_12 -> V_30 -> V_31 |= V_32 ;
F_8 ( V_2 , V_12 ) ;
return;
}
}
for ( V_7 = 0 ; V_7 < V_12 -> V_30 -> V_41 . V_42 ; V_7 ++ ) {
V_18 = F_13 ( V_5 -> V_21 [ V_7 + 1 ] ) ;
V_18 &= 0x00ffffff ;
V_18 ^= 0x00800000 ;
V_19 = F_15 ( V_12 , & V_18 , sizeof( V_43 ) ) ;
if ( F_10 ( V_19 == 0 ) ) {
F_1 ( V_2 , 0 ) ;
return;
}
}
V_12 -> V_30 -> V_31 |= ( V_44 | V_45 ) ;
F_8 ( V_2 , V_12 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 ) {
int V_7 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_46 ; V_7 ++ ) {
if ( V_5 -> V_47 [ V_7 ] )
F_2 ( V_5 -> V_47 [ V_7 ] ) ;
}
}
V_5 -> V_48 = 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_4 ( & V_5 -> V_13 ) ;
F_16 ( V_2 , V_5 -> V_48 ) ;
F_5 ( & V_5 -> V_13 ) ;
return 0 ;
}
static void F_18 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_11 * V_12 = V_2 -> V_49 ;
T_2 * V_50 ;
int V_51 ;
int V_19 ;
int V_7 ;
switch ( V_14 -> V_20 ) {
case 0 :
break;
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
if ( V_5 -> V_48 ) {
F_16 ( V_2 , 0 ) ;
V_12 -> V_30 -> V_31 |= V_32 ;
F_8 ( V_2 , V_12 ) ;
}
return;
default:
if ( V_5 -> V_48 ) {
F_9 ( V_2 -> V_25 ,
L_2 ,
V_34 , V_14 -> V_20 ) ;
F_16 ( V_2 , 0 ) ;
V_12 -> V_30 -> V_31 |= ( V_33 | V_32 ) ;
F_8 ( V_2 , V_12 ) ;
}
return;
}
if ( ! V_5 -> V_48 )
return;
V_5 -> V_52 -- ;
if ( ( int ) V_5 -> V_52 <= 0 ) {
V_5 -> V_52 = V_5 -> V_53 ;
if ( ! V_5 -> V_54 ) {
V_5 -> V_55 -- ;
if ( V_5 -> V_55 < 0 ) {
F_16 ( V_2 , 0 ) ;
V_12 -> V_30 -> V_31 |= V_32 ;
F_8 ( V_2 , V_12 ) ;
return;
}
}
V_50 = V_14 -> V_22 ;
V_51 = V_12 -> V_30 -> V_41 . V_42 ;
* V_50 ++ = V_51 ;
for ( V_7 = 0 ; V_7 < V_51 ; V_7 ++ ) {
unsigned int V_56 = V_5 -> V_57 [ V_7 ] ;
short V_18 ;
V_19 = F_19 ( V_12 -> V_30 , & V_18 ) ;
if ( V_19 < 0 ) {
F_9 ( V_2 -> V_25 , L_5 ) ;
V_12 -> V_30 -> V_31 |= ( V_32 |
V_58 ) ;
}
* V_50 ++ = V_18 ;
* V_50 ++ = V_56 ;
V_5 -> V_59 [ V_56 ] = V_18 ;
V_12 -> V_30 -> V_31 |= V_44 ;
F_8 ( V_2 , V_12 ) ;
}
}
V_14 -> V_60 = V_61 ;
V_14 -> V_2 = F_11 ( V_2 ) ;
V_14 -> V_20 = 0 ;
if ( V_5 -> V_62 )
V_14 -> V_63 = 8 ;
else
V_14 -> V_63 = 1 ;
V_14 -> V_64 = 1 ;
V_14 -> V_65 [ 0 ] . V_66 = 0 ;
V_14 -> V_65 [ 0 ] . V_67 = V_61 ;
V_14 -> V_65 [ 0 ] . V_20 = 0 ;
V_19 = F_12 ( V_14 , V_35 ) ;
if ( V_19 < 0 ) {
F_9 ( V_2 -> V_25 ,
L_3 ,
V_34 , V_19 ) ;
if ( V_19 == V_36 )
F_9 ( V_2 -> V_25 ,
L_4 ) ;
F_16 ( V_2 , 0 ) ;
V_12 -> V_30 -> V_31 |= ( V_32 | V_33 ) ;
F_8 ( V_2 , V_12 ) ;
}
}
static int F_20 ( struct V_1 * V_2 ,
struct V_14 * * V_68 , int V_69 ,
int V_70 )
{
struct V_71 * V_72 = F_11 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_14 * V_14 ;
int V_19 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_69 ; V_7 ++ ) {
V_14 = V_68 [ V_7 ] ;
if ( V_70 )
V_14 -> V_63 = V_5 -> V_73 ;
V_14 -> V_15 = V_2 ;
V_14 -> V_2 = V_72 ;
V_14 -> V_20 = 0 ;
V_14 -> V_74 = V_75 ;
V_19 = F_12 ( V_14 , V_35 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_21 ( int V_76 )
{
if ( V_76 <= 2 )
return 2 ;
if ( V_76 <= 8 )
return 4 ;
return 8 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_77 * V_41 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_62 = V_5 -> V_62 ;
int V_63 = F_21 ( V_41 -> V_42 ) ;
int V_78 = 0 ;
V_78 |= F_23 ( & V_41 -> V_79 , V_80 | V_81 ) ;
V_78 |= F_23 ( & V_41 -> V_82 , V_83 ) ;
V_78 |= F_23 ( & V_41 -> V_84 , V_80 ) ;
V_78 |= F_23 ( & V_41 -> V_85 , V_86 ) ;
V_78 |= F_23 ( & V_41 -> V_87 , V_86 | V_88 ) ;
if ( V_78 )
return 1 ;
V_78 |= F_24 ( V_41 -> V_79 ) ;
V_78 |= F_24 ( V_41 -> V_87 ) ;
if ( V_78 )
return 2 ;
V_78 |= F_25 ( & V_41 -> V_89 , 0 ) ;
if ( V_41 -> V_82 == V_90 )
V_78 |= F_25 ( & V_41 -> V_91 , 0 ) ;
if ( V_41 -> V_82 == V_83 ) {
unsigned int V_92 ;
if ( V_62 ) {
V_78 |= F_26 ( & V_41 -> V_91 ,
( 1000000 / 8 * V_63 ) ) ;
V_92 = ( V_41 -> V_91 / 125000 ) * 125000 ;
} else {
V_78 |= F_26 ( & V_41 -> V_91 ,
1000000 ) ;
V_92 = ( V_41 -> V_91 / 1000000 ) * 1000000 ;
}
V_78 |= F_25 ( & V_41 -> V_91 , V_92 ) ;
}
V_78 |= F_25 ( & V_41 -> V_93 , V_41 -> V_42 ) ;
if ( V_41 -> V_87 == V_86 ) {
} else {
V_78 |= F_25 ( & V_41 -> V_94 , 0 ) ;
}
if ( V_78 )
return 3 ;
if ( V_62 ) {
V_5 -> V_73 = V_63 ;
V_5 -> V_38 = V_41 -> V_91 / ( 125000 * V_63 ) ;
} else {
V_5 -> V_73 = 1 ;
V_5 -> V_38 = V_41 -> V_91 / 1000000 ;
}
if ( V_5 -> V_38 < 1 )
V_78 |= - V_95 ;
if ( V_41 -> V_87 == V_86 ) {
V_5 -> V_40 = V_41 -> V_94 ;
V_5 -> V_39 = 0 ;
} else {
V_5 -> V_39 = 1 ;
V_5 -> V_40 = 0 ;
}
if ( V_78 )
return 4 ;
return 0 ;
}
static void F_27 ( unsigned int V_56 ,
T_2 * V_96 ,
T_2 * V_97 )
{
if ( V_56 < 8 )
( * V_96 ) = ( * V_96 ) | ( 1 << V_56 ) ;
else if ( V_56 < 16 )
( * V_97 ) = ( * V_97 ) | ( 1 << ( V_56 - 8 ) ) ;
}
static int F_28 ( struct V_1 * V_2 , int V_98 )
{
struct V_71 * V_72 = F_11 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_99 ;
V_5 -> V_100 [ 0 ] = V_98 ;
return F_29 ( V_72 , F_30 ( V_72 , V_101 ) ,
V_5 -> V_100 , V_102 ,
& V_99 , V_103 ) ;
}
static int F_31 ( struct V_1 * V_2 , int V_104 )
{
struct V_71 * V_72 = F_11 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_105 ;
int V_19 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_106 ; V_7 ++ ) {
V_19 = F_29 ( V_72 ,
F_32 ( V_72 , V_107 ) ,
V_5 -> V_108 , V_109 ,
& V_105 , V_103 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_5 -> V_108 [ 0 ] == V_104 )
return 0 ;
}
return - V_110 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
unsigned int V_111 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_19 ;
if ( V_111 != 0 )
return - V_95 ;
F_4 ( & V_5 -> V_13 ) ;
if ( ! V_5 -> V_10 ) {
V_19 = F_20 ( V_2 , V_5 -> V_9 ,
V_5 -> V_8 , 1 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_5 -> V_13 ) ;
return V_19 ;
}
V_5 -> V_10 = 1 ;
V_12 -> V_30 -> V_112 = NULL ;
}
F_5 ( & V_5 -> V_13 ) ;
return 1 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_77 * V_41 = & V_12 -> V_30 -> V_41 ;
unsigned int V_51 = V_41 -> V_42 ;
T_2 V_96 = 0 ;
T_2 V_97 = 0 ;
T_2 V_113 = 0 ;
int V_19 ;
int V_7 ;
F_4 ( & V_5 -> V_13 ) ;
V_12 -> V_30 -> V_114 = 0 ;
for ( V_7 = 0 ; V_7 < V_51 ; V_7 ++ ) {
unsigned int V_56 = F_35 ( V_41 -> V_115 [ V_7 ] ) ;
F_27 ( V_56 , & V_96 , & V_97 ) ;
}
V_5 -> V_100 [ 1 ] = V_51 ;
V_5 -> V_100 [ 2 ] = 0x12 ;
V_5 -> V_100 [ 3 ] = 0x03 ;
V_5 -> V_100 [ 4 ] = 0x00 ;
V_5 -> V_100 [ 5 ] = V_96 ;
V_5 -> V_100 [ 6 ] = V_97 ;
V_5 -> V_100 [ 7 ] = V_113 ;
V_19 = F_28 ( V_2 , V_116 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_5 -> V_13 ) ;
return V_19 ;
}
V_5 -> V_37 = V_5 -> V_38 ;
if ( V_41 -> V_79 == V_80 ) {
V_19 = F_20 ( V_2 , V_5 -> V_9 ,
V_5 -> V_8 , 1 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_5 -> V_13 ) ;
return V_19 ;
}
V_12 -> V_30 -> V_112 = NULL ;
V_5 -> V_10 = 1 ;
} else {
V_12 -> V_30 -> V_112 = F_33 ;
}
F_5 ( & V_5 -> V_13 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_56 = F_35 ( V_118 -> V_120 ) ;
T_2 V_96 = 0 ;
T_2 V_97 = 0 ;
T_2 V_113 = 0 ;
int V_19 ;
int V_7 ;
F_4 ( & V_5 -> V_13 ) ;
if ( V_5 -> V_10 ) {
F_5 ( & V_5 -> V_13 ) ;
return - V_121 ;
}
F_27 ( V_56 , & V_96 , & V_97 ) ;
V_5 -> V_100 [ 1 ] = 0x16 ;
V_5 -> V_100 [ 2 ] = 0x80 ;
V_5 -> V_100 [ 3 ] = 0x00 ;
V_5 -> V_100 [ 4 ] = V_96 ;
V_5 -> V_100 [ 5 ] = V_97 ;
V_5 -> V_100 [ 6 ] = V_113 ;
V_19 = F_28 ( V_2 , V_122 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_5 -> V_13 ) ;
return V_19 ;
}
for ( V_7 = 0 ; V_7 < V_118 -> V_123 ; V_7 ++ ) {
T_1 V_18 ;
V_19 = F_31 ( V_2 , V_122 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_5 -> V_13 ) ;
return V_19 ;
}
V_18 = F_13 ( * ( ( T_1 * ) ( ( V_5 -> V_108 ) + 1 ) ) ) ;
V_18 &= 0x00ffffff ;
V_18 ^= 0x00800000 ;
V_119 [ V_7 ] = V_18 ;
}
F_5 ( & V_5 -> V_13 ) ;
return V_118 -> V_123 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_56 = F_35 ( V_118 -> V_120 ) ;
int V_7 ;
F_4 ( & V_5 -> V_13 ) ;
for ( V_7 = 0 ; V_7 < V_118 -> V_123 ; V_7 ++ )
V_119 [ V_7 ] = V_5 -> V_59 [ V_56 ] ;
F_5 ( & V_5 -> V_13 ) ;
return V_118 -> V_123 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_56 = F_35 ( V_118 -> V_120 ) ;
int V_19 ;
int V_7 ;
F_4 ( & V_5 -> V_13 ) ;
if ( V_5 -> V_48 ) {
F_5 ( & V_5 -> V_13 ) ;
return - V_121 ;
}
for ( V_7 = 0 ; V_7 < V_118 -> V_123 ; V_7 ++ ) {
V_5 -> V_100 [ 1 ] = 1 ;
V_5 -> V_100 [ 2 ] = V_119 [ V_7 ] ;
V_5 -> V_100 [ 3 ] = V_56 ;
V_19 = F_28 ( V_2 , V_124 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_5 -> V_13 ) ;
return V_19 ;
}
V_5 -> V_59 [ V_56 ] = V_119 [ V_7 ] ;
}
F_5 ( & V_5 -> V_13 ) ;
return V_118 -> V_123 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
unsigned int V_111 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_19 ;
if ( V_111 != 0 )
return - V_95 ;
F_4 ( & V_5 -> V_13 ) ;
if ( ! V_5 -> V_48 ) {
V_19 = F_20 ( V_2 , V_5 -> V_47 ,
V_5 -> V_46 , 0 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_5 -> V_13 ) ;
return V_19 ;
}
V_5 -> V_48 = 1 ;
V_12 -> V_30 -> V_112 = NULL ;
}
F_5 ( & V_5 -> V_13 ) ;
return 1 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_77 * V_41 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_78 = 0 ;
int V_62 ;
unsigned int V_125 ;
V_62 = 0 ;
V_78 |= F_23 ( & V_41 -> V_79 , V_80 | V_81 ) ;
if ( V_62 ) {
V_125 = V_90 ;
} else {
V_125 = V_83 ;
}
V_78 |= F_23 ( & V_41 -> V_82 , V_125 ) ;
V_78 |= F_23 ( & V_41 -> V_84 , V_80 ) ;
V_78 |= F_23 ( & V_41 -> V_85 , V_86 ) ;
V_78 |= F_23 ( & V_41 -> V_87 , V_86 | V_88 ) ;
if ( V_78 ) {
F_5 ( & V_5 -> V_13 ) ;
return 1 ;
}
V_78 |= F_24 ( V_41 -> V_79 ) ;
V_78 |= F_24 ( V_41 -> V_87 ) ;
if ( V_78 )
return 2 ;
V_78 |= F_25 ( & V_41 -> V_89 , 0 ) ;
if ( V_41 -> V_82 == V_90 )
V_78 |= F_25 ( & V_41 -> V_91 , 0 ) ;
if ( V_41 -> V_82 == V_83 )
V_78 |= F_26 ( & V_41 -> V_91 ,
1000000 ) ;
if ( V_41 -> V_84 == V_83 )
V_78 |= F_26 ( & V_41 -> V_126 , 125000 ) ;
V_78 |= F_25 ( & V_41 -> V_93 , V_41 -> V_42 ) ;
if ( V_41 -> V_87 == V_86 ) {
} else {
V_78 |= F_25 ( & V_41 -> V_94 , 0 ) ;
}
if ( V_78 )
return 3 ;
if ( V_62 ) {
V_5 -> V_53 = V_41 -> V_126 / 125000 ;
} else {
V_5 -> V_53 = V_41 -> V_91 / 1000000 ;
}
if ( V_5 -> V_53 < 1 )
V_78 |= - V_95 ;
if ( V_41 -> V_87 == V_86 ) {
if ( V_62 ) {
V_5 -> V_55 = V_41 -> V_94 *
V_41 -> V_93 ;
} else {
V_5 -> V_55 = V_41 -> V_94 ;
}
V_5 -> V_54 = 0 ;
} else {
V_5 -> V_54 = 1 ;
V_5 -> V_55 = 0 ;
}
if ( V_78 )
return 4 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_77 * V_41 = & V_12 -> V_30 -> V_41 ;
int V_19 ;
int V_7 ;
F_4 ( & V_5 -> V_13 ) ;
V_12 -> V_30 -> V_114 = 0 ;
for ( V_7 = 0 ; V_7 < V_41 -> V_42 ; ++ V_7 )
V_5 -> V_57 [ V_7 ] = F_35 ( V_41 -> V_115 [ V_7 ] ) ;
V_5 -> V_52 = V_5 -> V_53 ;
if ( V_41 -> V_79 == V_80 ) {
V_19 = F_20 ( V_2 , V_5 -> V_47 ,
V_5 -> V_46 , 0 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_5 -> V_13 ) ;
return V_19 ;
}
V_12 -> V_30 -> V_112 = NULL ;
V_5 -> V_48 = 1 ;
} else {
V_12 -> V_30 -> V_112 = F_39 ;
}
F_5 ( & V_5 -> V_13 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
unsigned int V_56 = F_35 ( V_118 -> V_120 ) ;
unsigned int V_127 = 1 << V_56 ;
switch ( V_119 [ 0 ] ) {
case V_128 :
V_12 -> V_129 |= V_127 ;
break;
case V_130 :
V_12 -> V_129 &= ~ V_127 ;
break;
case V_131 :
V_119 [ 1 ] = ( V_12 -> V_129 & V_127 ) ? V_132 : V_133 ;
break;
default:
return - V_95 ;
break;
}
return V_118 -> V_123 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_127 = V_119 [ 0 ] ;
unsigned int V_134 = V_119 [ 1 ] ;
int V_19 ;
F_4 ( & V_5 -> V_13 ) ;
V_12 -> V_135 &= ~ V_127 ;
V_12 -> V_135 |= ( V_134 & V_127 ) ;
V_5 -> V_100 [ 1 ] = V_12 -> V_129 & 0xff ;
V_5 -> V_100 [ 4 ] = V_12 -> V_135 & 0xff ;
V_5 -> V_100 [ 2 ] = ( V_12 -> V_129 >> 8 ) & 0xff ;
V_5 -> V_100 [ 5 ] = ( V_12 -> V_135 >> 8 ) & 0xff ;
V_5 -> V_100 [ 3 ] = ( V_12 -> V_129 >> 16 ) & 0xff ;
V_5 -> V_100 [ 6 ] = ( V_12 -> V_135 >> 16 ) & 0xff ;
V_19 = F_28 ( V_2 , V_136 ) ;
if ( V_19 < 0 )
goto V_137;
V_19 = F_31 ( V_2 , V_136 ) ;
if ( V_19 < 0 )
goto V_137;
V_12 -> V_135 = V_5 -> V_108 [ 1 ] |
( V_5 -> V_108 [ 2 ] << 8 ) |
( V_5 -> V_108 [ 3 ] << 16 ) ;
V_119 [ 1 ] = V_12 -> V_135 ;
V_19 = V_118 -> V_123 ;
V_137:
F_5 ( & V_5 -> V_13 ) ;
return V_19 ;
}
static void F_44 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 ) {
if ( V_5 -> V_138 )
F_2 ( V_5 -> V_138 ) ;
}
V_5 -> V_139 = 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_44 ( V_2 , V_5 -> V_139 ) ;
return F_28 ( V_2 , V_140 ) ;
}
static void F_46 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_19 ;
switch ( V_14 -> V_20 ) {
case 0 :
break;
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
if ( V_5 -> V_139 )
F_44 ( V_2 , 0 ) ;
return;
default:
if ( V_5 -> V_139 ) {
F_9 ( V_2 -> V_25 ,
L_2 ,
V_34 , V_14 -> V_20 ) ;
F_44 ( V_2 , 0 ) ;
}
return;
}
if ( ! V_5 -> V_139 )
return;
V_14 -> V_60 = V_5 -> V_141 ;
V_14 -> V_2 = F_11 ( V_2 ) ;
V_14 -> V_20 = 0 ;
V_19 = F_12 ( V_14 , V_35 ) ;
if ( V_19 < 0 ) {
F_9 ( V_2 -> V_25 , L_3 ,
V_34 , V_19 ) ;
if ( V_19 == V_36 )
F_9 ( V_2 -> V_25 ,
L_4 ) ;
F_44 ( V_2 , 0 ) ;
}
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = F_11 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_14 * V_14 = V_5 -> V_138 ;
F_48 ( V_14 ,
V_72 , F_30 ( V_72 , V_142 ) ,
V_14 -> V_22 , V_5 -> V_141 ,
F_46 , V_2 ) ;
return F_12 ( V_14 , V_35 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
unsigned int V_143 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_144 = 255 ;
if ( V_143 < V_145 ) {
return - V_146 ;
} else {
V_144 = ( V_143 / ( 6 * 512 * 1000 / 33 ) ) - 6 ;
if ( V_144 > 255 )
return - V_146 ;
}
V_5 -> V_147 = V_144 ;
V_5 -> V_148 = V_143 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_19 ;
if ( V_5 -> V_139 )
return 0 ;
V_5 -> V_100 [ 1 ] = V_5 -> V_147 ;
V_19 = F_28 ( V_2 , V_149 ) ;
if ( V_19 < 0 )
return V_19 ;
memset ( V_5 -> V_138 -> V_22 , 0 , V_5 -> V_141 ) ;
V_19 = F_47 ( V_2 ) ;
if ( V_19 < 0 )
return V_19 ;
V_5 -> V_139 = 1 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
unsigned int V_56 ,
unsigned int V_150 ,
unsigned int V_151 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
char V_152 = ( 1 << V_56 ) ;
char V_153 = ( 16 << V_56 ) ;
char * V_154 = ( char * ) ( V_5 -> V_138 -> V_22 ) ;
int V_155 = V_5 -> V_141 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_155 ; V_7 ++ ) {
char V_156 = * V_154 ;
V_156 &= ~ V_152 ;
if ( V_7 < V_150 )
V_156 |= V_152 ;
if ( ! V_151 )
V_156 &= ~ V_153 ;
else
V_156 |= V_153 ;
* V_154 ++ = V_156 ;
}
return 1 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
unsigned int V_56 = F_35 ( V_118 -> V_120 ) ;
if ( V_118 -> V_123 != 1 )
return - V_95 ;
return F_51 ( V_2 , V_12 , V_56 , V_119 [ 0 ] , 0 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_56 = F_35 ( V_118 -> V_120 ) ;
switch ( V_119 [ 0 ] ) {
case V_157 :
if ( V_119 [ 1 ] != 0 )
return - V_95 ;
return F_50 ( V_2 , V_12 ) ;
case V_158 :
return F_45 ( V_2 , V_12 ) ;
case V_159 :
V_119 [ 1 ] = V_5 -> V_139 ;
return 0 ;
case V_160 :
return F_49 ( V_2 , V_12 , V_119 [ 1 ] ) ;
case V_161 :
V_119 [ 1 ] = V_5 -> V_148 ;
return 0 ;
case V_162 :
return F_51 ( V_2 , V_12 , V_56 ,
V_119 [ 1 ] , ( V_119 [ 2 ] != 0 ) ) ;
case V_163 :
return - V_95 ;
}
return - V_95 ;
}
static int F_54 ( struct V_1 * V_2 , int V_56 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_113 ;
V_43 V_18 ;
int V_19 ;
switch ( V_56 ) {
default:
case 0 :
V_113 = 0 ;
break;
case 1 :
V_113 = 1 ;
break;
case 2 :
V_113 = 4 ;
break;
case 3 :
V_113 = 8 ;
break;
case 4 :
V_113 = 16 ;
break;
case 5 :
V_113 = 32 ;
break;
}
V_5 -> V_100 [ 1 ] = 0x12 ;
V_5 -> V_100 [ 2 ] = 0x80 ;
V_5 -> V_100 [ 3 ] = 0x00 ;
V_5 -> V_100 [ 4 ] = 0 ;
V_5 -> V_100 [ 5 ] = 0 ;
V_5 -> V_100 [ 6 ] = V_113 ;
V_19 = F_28 ( V_2 , V_122 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_31 ( V_2 , V_122 ) ;
if ( V_19 < 0 )
return V_19 ;
V_18 = F_13 ( * ( ( T_1 * ) ( ( V_5 -> V_108 ) + 1 ) ) ) ;
V_18 &= 0x00ffffff ;
V_18 ^= 0x00800000 ;
return ( int ) V_18 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_11 * V_12 ;
int V_164 ;
int V_66 ;
int V_19 ;
F_4 ( & V_5 -> V_13 ) ;
if ( V_5 -> V_62 )
V_164 = 4 ;
else
V_164 = 3 ;
V_19 = F_56 ( V_2 , V_164 ) ;
if ( V_19 ) {
F_5 ( & V_5 -> V_13 ) ;
return V_19 ;
}
V_12 = & V_2 -> V_165 [ 0 ] ;
V_2 -> V_16 = V_12 ;
V_12 -> type = V_166 ;
V_12 -> V_167 = V_168 | V_169 | V_170 | V_171 ;
V_12 -> V_172 = V_173 ;
V_12 -> V_174 = V_173 ;
V_12 -> V_175 = 0x00ffffff ;
V_12 -> V_176 = & V_177 ;
V_12 -> V_178 = F_36 ;
V_12 -> V_179 = F_22 ;
V_12 -> V_180 = F_34 ;
V_12 -> V_181 = F_3 ;
V_12 = & V_2 -> V_165 [ 1 ] ;
V_2 -> V_49 = V_12 ;
V_12 -> type = V_182 ;
V_12 -> V_167 = V_183 | V_169 | V_184 ;
V_12 -> V_172 = V_185 ;
V_12 -> V_174 = V_12 -> V_172 ;
V_12 -> V_175 = 0x00ff ;
V_12 -> V_176 = & V_186 ;
V_12 -> V_187 = F_38 ;
V_12 -> V_178 = F_37 ;
V_12 -> V_179 = F_40 ;
V_12 -> V_180 = F_41 ;
V_12 -> V_181 = F_17 ;
V_12 = & V_2 -> V_165 [ 2 ] ;
V_12 -> type = V_188 ;
V_12 -> V_167 = V_168 | V_183 ;
V_12 -> V_172 = 24 ;
V_12 -> V_175 = 1 ;
V_12 -> V_176 = & V_189 ;
V_12 -> V_190 = F_43 ;
V_12 -> V_191 = F_42 ;
if ( V_5 -> V_62 ) {
V_12 = & V_2 -> V_165 [ 3 ] ;
V_12 -> type = V_192 ;
V_12 -> V_167 = V_183 | V_193 ;
V_12 -> V_172 = 8 ;
V_12 -> V_175 = V_5 -> V_141 ;
V_12 -> V_187 = F_52 ;
V_12 -> V_191 = F_53 ;
F_49 ( V_2 , V_12 , V_194 ) ;
}
F_5 ( & V_5 -> V_13 ) ;
V_66 = F_54 ( V_2 , 0 ) ;
if ( V_66 < 0 )
F_9 ( V_2 -> V_25 ,
L_6 ) ;
F_57 ( V_2 -> V_25 , L_7 , V_66 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
const T_3 * V_119 , T_4 V_195 ,
unsigned long V_15 )
{
struct V_71 * V_72 = F_11 ( V_2 ) ;
T_2 * V_154 ;
T_2 * V_92 ;
int V_19 ;
if ( ! V_119 )
return 0 ;
if ( V_195 > V_196 ) {
F_9 ( V_2 -> V_25 , L_8 ) ;
return - V_197 ;
}
V_154 = F_59 ( V_119 , V_195 , V_198 ) ;
if ( ! V_154 )
return - V_197 ;
V_92 = F_60 ( 1 , V_198 ) ;
if ( ! V_92 ) {
F_61 ( V_154 ) ;
return - V_197 ;
}
* V_92 = 1 ;
V_19 = F_62 ( V_72 , F_63 ( V_72 , 0 ) ,
V_199 ,
V_200 ,
V_201 , 0x0000 ,
V_92 , 1 ,
V_103 ) ;
if ( V_19 < 0 ) {
F_9 ( V_2 -> V_25 , L_9 ) ;
goto V_137;
}
V_19 = F_62 ( V_72 , F_63 ( V_72 , 0 ) ,
V_199 ,
V_200 ,
0 , 0x0000 ,
V_154 , V_195 ,
V_103 ) ;
if ( V_19 < 0 ) {
F_9 ( V_2 -> V_25 , L_10 ) ;
goto V_137;
}
* V_92 = 0 ;
V_19 = F_62 ( V_72 , F_63 ( V_72 , 0 ) ,
V_199 ,
V_200 ,
V_201 , 0x0000 ,
V_92 , 1 ,
V_103 ) ;
if ( V_19 < 0 )
F_9 ( V_2 -> V_25 , L_11 ) ;
V_137:
F_61 ( V_92 ) ;
F_61 ( V_154 ) ;
return V_19 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = F_11 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_14 * V_14 ;
int V_7 ;
V_5 -> V_57 = F_65 ( V_202 , V_198 ) ;
V_5 -> V_100 = F_65 ( V_102 , V_198 ) ;
V_5 -> V_21 = F_65 ( V_23 , V_198 ) ;
V_5 -> V_108 = F_65 ( V_109 , V_198 ) ;
V_5 -> V_9 = F_66 ( V_5 -> V_8 , sizeof( * V_14 ) ,
V_198 ) ;
V_5 -> V_47 = F_66 ( V_5 -> V_46 , sizeof( * V_14 ) ,
V_198 ) ;
if ( ! V_5 -> V_57 || ! V_5 -> V_100 ||
! V_5 -> V_21 || ! V_5 -> V_108 ||
! V_5 -> V_9 || ! V_5 -> V_47 )
return - V_197 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_8 ; V_7 ++ ) {
V_14 = F_67 ( 1 , V_198 ) ;
if ( ! V_14 )
return - V_197 ;
V_5 -> V_9 [ V_7 ] = V_14 ;
V_14 -> V_2 = V_72 ;
V_14 -> V_15 = NULL ;
V_14 -> V_203 = F_68 ( V_72 , V_204 ) ;
V_14 -> V_74 = V_75 ;
V_14 -> V_22 = F_65 ( V_23 , V_198 ) ;
if ( ! V_14 -> V_22 )
return - V_197 ;
V_14 -> V_205 = F_6 ;
V_14 -> V_64 = 1 ;
V_14 -> V_60 = V_23 ;
V_14 -> V_65 [ 0 ] . V_66 = 0 ;
V_14 -> V_65 [ 0 ] . V_67 = V_23 ;
}
for ( V_7 = 0 ; V_7 < V_5 -> V_46 ; V_7 ++ ) {
V_14 = F_67 ( 1 , V_198 ) ;
if ( ! V_14 )
return - V_197 ;
V_5 -> V_47 [ V_7 ] = V_14 ;
V_14 -> V_2 = V_72 ;
V_14 -> V_15 = NULL ;
V_14 -> V_203 = F_69 ( V_72 , V_206 ) ;
V_14 -> V_74 = V_75 ;
V_14 -> V_22 = F_65 ( V_61 , V_198 ) ;
if ( ! V_14 -> V_22 )
return - V_197 ;
V_14 -> V_205 = F_18 ;
V_14 -> V_64 = 1 ;
V_14 -> V_60 = V_61 ;
V_14 -> V_65 [ 0 ] . V_66 = 0 ;
V_14 -> V_65 [ 0 ] . V_67 = V_61 ;
if ( V_5 -> V_62 )
V_14 -> V_63 = 8 ;
else
V_14 -> V_63 = 1 ;
}
if ( V_5 -> V_62 ) {
V_5 -> V_141 = 512 ;
V_14 = F_67 ( 0 , V_198 ) ;
if ( ! V_14 )
return - V_197 ;
V_5 -> V_138 = V_14 ;
V_14 -> V_22 = F_65 ( V_5 -> V_141 , V_198 ) ;
if ( ! V_14 -> V_22 )
return - V_197 ;
} else {
V_5 -> V_138 = NULL ;
V_5 -> V_141 = 0 ;
}
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_14 * V_14 ;
int V_7 ;
F_1 ( V_2 , 1 ) ;
F_16 ( V_2 , 1 ) ;
F_44 ( V_2 , 1 ) ;
V_14 = V_5 -> V_138 ;
if ( V_14 ) {
F_61 ( V_14 -> V_22 ) ;
F_71 ( V_14 ) ;
}
if ( V_5 -> V_47 ) {
for ( V_7 = 0 ; V_7 < V_5 -> V_46 ; V_7 ++ ) {
V_14 = V_5 -> V_47 [ V_7 ] ;
if ( V_14 ) {
F_61 ( V_14 -> V_22 ) ;
F_71 ( V_14 ) ;
}
}
F_61 ( V_5 -> V_47 ) ;
}
if ( V_5 -> V_9 ) {
for ( V_7 = 0 ; V_7 < V_5 -> V_8 ; V_7 ++ ) {
V_14 = V_5 -> V_9 [ V_7 ] ;
if ( V_14 ) {
F_61 ( V_14 -> V_22 ) ;
F_71 ( V_14 ) ;
}
}
F_61 ( V_5 -> V_9 ) ;
}
F_61 ( V_5 -> V_108 ) ;
F_61 ( V_5 -> V_21 ) ;
F_61 ( V_5 -> V_100 ) ;
F_61 ( V_5 -> V_57 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
unsigned long V_207 )
{
struct V_208 * V_209 = F_73 ( V_2 ) ;
struct V_71 * V_72 = F_11 ( V_2 ) ;
struct V_4 * V_5 ;
int V_19 ;
V_5 = F_65 ( sizeof( * V_5 ) , V_198 ) ;
if ( ! V_5 )
return - V_197 ;
V_2 -> V_6 = V_5 ;
F_74 ( & V_5 -> V_13 , 1 ) ;
F_75 ( V_209 , V_5 ) ;
V_19 = F_76 ( V_72 ,
V_209 -> V_210 -> V_211 . V_212 , 3 ) ;
if ( V_19 < 0 ) {
F_9 ( V_2 -> V_25 ,
L_12 ) ;
return - V_213 ;
}
V_5 -> V_62 = ( V_72 -> V_214 == V_215 ) ;
if ( V_5 -> V_62 ) {
V_5 -> V_8 = V_216 ;
V_5 -> V_46 = V_217 ;
} else {
V_5 -> V_8 = V_218 ;
V_5 -> V_46 = V_219 ;
}
V_19 = F_64 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_77 ( V_2 , & V_72 -> V_2 , V_220 ,
F_58 , 0 ) ;
if ( V_19 )
return V_19 ;
return F_55 ( V_2 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_208 * V_209 = F_73 ( V_2 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_5 )
return;
F_75 ( V_209 , NULL ) ;
F_4 ( & V_5 -> V_13 ) ;
F_70 ( V_2 ) ;
F_5 ( & V_5 -> V_13 ) ;
}
static int F_79 ( struct V_208 * V_209 ,
const struct V_221 * V_222 )
{
return F_80 ( V_209 , & V_223 , 0 ) ;
}
