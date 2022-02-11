static void F_1 ( struct V_1 * * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
F_2 ( V_2 [ V_4 ] ) ;
}
static void F_3 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 && V_9 -> V_11 )
F_1 ( V_9 -> V_11 , V_9 -> V_12 ) ;
V_9 -> V_13 = 0 ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_16 ) ;
F_3 ( V_6 , V_9 -> V_13 ) ;
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_17 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_14 * V_15 = V_6 -> V_18 ;
unsigned int V_19 ;
T_1 V_20 ;
int V_21 ;
int V_4 ;
switch ( V_1 -> V_22 ) {
case 0 :
memcpy ( V_9 -> V_23 , V_1 -> V_24 , V_25 ) ;
break;
case - V_26 :
F_8 ( V_6 -> V_27 , L_1 ) ;
break;
case - V_28 :
case - V_29 :
case - V_30 :
case - V_31 :
if ( V_9 -> V_13 ) {
F_3 ( V_6 , 0 ) ;
V_15 -> V_32 -> V_33 |= ( V_34 | V_35 ) ;
F_9 ( V_6 , V_15 ) ;
}
return;
default:
if ( V_9 -> V_13 ) {
F_10 ( V_6 -> V_27 ,
L_2 ,
V_36 , V_1 -> V_22 ) ;
F_3 ( V_6 , 0 ) ;
V_15 -> V_32 -> V_33 |= ( V_34 | V_35 ) ;
F_9 ( V_6 , V_15 ) ;
}
return;
}
if ( F_11 ( ! V_9 -> V_13 ) )
return;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_21 = F_13 ( V_1 , V_37 ) ;
if ( F_11 ( V_21 < 0 ) ) {
F_10 ( V_6 -> V_27 , L_3 ,
V_36 , V_21 ) ;
if ( V_21 == - V_38 )
F_10 ( V_6 -> V_27 ,
L_4 ) ;
F_3 ( V_6 , 0 ) ;
V_15 -> V_32 -> V_33 |= ( V_34 | V_35 ) ;
F_9 ( V_6 , V_15 ) ;
return;
}
V_19 = F_14 ( V_9 -> V_23 [ 0 ] ) ;
V_9 -> V_39 -- ;
if ( F_15 ( V_9 -> V_39 > 0 ) )
return;
V_9 -> V_39 = V_9 -> V_40 ;
if ( ! V_9 -> V_41 ) {
V_9 -> V_42 -- ;
if ( V_9 -> V_42 < 0 ) {
F_3 ( V_6 , 0 ) ;
V_15 -> V_32 -> V_33 |= V_34 ;
F_9 ( V_6 , V_15 ) ;
return;
}
}
for ( V_4 = 0 ; V_4 < V_15 -> V_32 -> V_43 . V_44 ; V_4 ++ ) {
V_20 = F_14 ( V_9 -> V_23 [ V_4 + 1 ] ) ;
V_20 &= 0x00ffffff ;
V_20 ^= 0x00800000 ;
V_21 = F_16 ( V_15 , & V_20 , sizeof( V_45 ) ) ;
if ( F_11 ( V_21 == 0 ) ) {
F_3 ( V_6 , 0 ) ;
return;
}
}
V_15 -> V_32 -> V_33 |= ( V_46 | V_47 ) ;
F_9 ( V_6 , V_15 ) ;
}
static void F_17 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 && V_9 -> V_48 )
F_1 ( V_9 -> V_48 , V_9 -> V_49 ) ;
V_9 -> V_50 = 0 ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_16 ) ;
F_17 ( V_6 , V_9 -> V_50 ) ;
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_17 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_14 * V_15 = V_6 -> V_51 ;
T_2 * V_52 ;
int V_53 ;
int V_21 ;
int V_4 ;
switch ( V_1 -> V_22 ) {
case 0 :
break;
case - V_28 :
case - V_29 :
case - V_30 :
case - V_31 :
if ( V_9 -> V_50 ) {
F_17 ( V_6 , 0 ) ;
V_15 -> V_32 -> V_33 |= V_34 ;
F_9 ( V_6 , V_15 ) ;
}
return;
default:
if ( V_9 -> V_50 ) {
F_10 ( V_6 -> V_27 ,
L_2 ,
V_36 , V_1 -> V_22 ) ;
F_17 ( V_6 , 0 ) ;
V_15 -> V_32 -> V_33 |= ( V_35 | V_34 ) ;
F_9 ( V_6 , V_15 ) ;
}
return;
}
if ( ! V_9 -> V_50 )
return;
V_9 -> V_54 -- ;
if ( ( int ) V_9 -> V_54 <= 0 ) {
V_9 -> V_54 = V_9 -> V_55 ;
if ( ! V_9 -> V_56 ) {
V_9 -> V_57 -- ;
if ( V_9 -> V_57 < 0 ) {
F_17 ( V_6 , 0 ) ;
V_15 -> V_32 -> V_33 |= V_34 ;
F_9 ( V_6 , V_15 ) ;
return;
}
}
V_52 = V_1 -> V_24 ;
V_53 = V_15 -> V_32 -> V_43 . V_44 ;
* V_52 ++ = V_53 ;
for ( V_4 = 0 ; V_4 < V_53 ; V_4 ++ ) {
unsigned int V_58 = V_9 -> V_59 [ V_4 ] ;
short V_20 ;
V_21 = F_20 ( V_15 -> V_32 , & V_20 ) ;
if ( V_21 < 0 ) {
F_10 ( V_6 -> V_27 , L_5 ) ;
V_15 -> V_32 -> V_33 |= ( V_34 |
V_60 ) ;
}
* V_52 ++ = V_20 ;
* V_52 ++ = V_58 ;
V_9 -> V_61 [ V_58 ] = V_20 ;
V_15 -> V_32 -> V_33 |= V_46 ;
F_9 ( V_6 , V_15 ) ;
}
}
V_1 -> V_62 = V_63 ;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_1 -> V_22 = 0 ;
if ( V_9 -> V_64 )
V_1 -> V_65 = 8 ;
else
V_1 -> V_65 = 1 ;
V_1 -> V_66 = 1 ;
V_1 -> V_67 [ 0 ] . V_68 = 0 ;
V_1 -> V_67 [ 0 ] . V_69 = V_63 ;
V_1 -> V_67 [ 0 ] . V_22 = 0 ;
V_21 = F_13 ( V_1 , V_37 ) ;
if ( V_21 < 0 ) {
F_10 ( V_6 -> V_27 ,
L_3 ,
V_36 , V_21 ) ;
if ( V_21 == V_38 )
F_10 ( V_6 -> V_27 ,
L_4 ) ;
F_17 ( V_6 , 0 ) ;
V_15 -> V_32 -> V_33 |= ( V_34 | V_35 ) ;
F_9 ( V_6 , V_15 ) ;
}
}
static int F_21 ( struct V_5 * V_6 ,
struct V_1 * * V_2 , int V_3 ,
int V_70 )
{
struct V_71 * V_72 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_21 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_1 = V_2 [ V_4 ] ;
if ( V_70 )
V_1 -> V_65 = V_9 -> V_73 ;
V_1 -> V_17 = V_6 ;
V_1 -> V_6 = V_72 ;
V_1 -> V_22 = 0 ;
V_1 -> V_74 = V_75 ;
V_21 = F_13 ( V_1 , V_37 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_22 ( int V_76 )
{
if ( V_76 <= 2 )
return 2 ;
if ( V_76 <= 8 )
return 4 ;
return 8 ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_77 * V_43 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_64 = V_9 -> V_64 ;
int V_65 = F_22 ( V_43 -> V_44 ) ;
int V_78 = 0 ;
V_78 |= F_24 ( & V_43 -> V_79 , V_80 | V_81 ) ;
V_78 |= F_24 ( & V_43 -> V_82 , V_83 ) ;
V_78 |= F_24 ( & V_43 -> V_84 , V_80 ) ;
V_78 |= F_24 ( & V_43 -> V_85 , V_86 ) ;
V_78 |= F_24 ( & V_43 -> V_87 , V_86 | V_88 ) ;
if ( V_78 )
return 1 ;
V_78 |= F_25 ( V_43 -> V_79 ) ;
V_78 |= F_25 ( V_43 -> V_87 ) ;
if ( V_78 )
return 2 ;
V_78 |= F_26 ( & V_43 -> V_89 , 0 ) ;
if ( V_43 -> V_82 == V_90 )
V_78 |= F_26 ( & V_43 -> V_91 , 0 ) ;
if ( V_43 -> V_82 == V_83 ) {
unsigned int V_92 ;
if ( V_64 ) {
V_78 |= F_27 ( & V_43 -> V_91 ,
( 1000000 / 8 * V_65 ) ) ;
V_92 = ( V_43 -> V_91 / 125000 ) * 125000 ;
} else {
V_78 |= F_27 ( & V_43 -> V_91 ,
1000000 ) ;
V_92 = ( V_43 -> V_91 / 1000000 ) * 1000000 ;
}
V_78 |= F_26 ( & V_43 -> V_91 , V_92 ) ;
}
V_78 |= F_26 ( & V_43 -> V_93 , V_43 -> V_44 ) ;
if ( V_43 -> V_87 == V_86 ) {
} else {
V_78 |= F_26 ( & V_43 -> V_94 , 0 ) ;
}
if ( V_78 )
return 3 ;
if ( V_64 ) {
V_9 -> V_73 = V_65 ;
V_9 -> V_40 = V_43 -> V_91 / ( 125000 * V_65 ) ;
} else {
V_9 -> V_73 = 1 ;
V_9 -> V_40 = V_43 -> V_91 / 1000000 ;
}
if ( V_9 -> V_40 < 1 )
V_78 |= - V_95 ;
if ( V_43 -> V_87 == V_86 ) {
V_9 -> V_42 = V_43 -> V_94 ;
V_9 -> V_41 = 0 ;
} else {
V_9 -> V_41 = 1 ;
V_9 -> V_42 = 0 ;
}
if ( V_78 )
return 4 ;
return 0 ;
}
static void F_28 ( unsigned int V_58 ,
T_2 * V_96 ,
T_2 * V_97 )
{
if ( V_58 < 8 )
( * V_96 ) = ( * V_96 ) | ( 1 << V_58 ) ;
else if ( V_58 < 16 )
( * V_97 ) = ( * V_97 ) | ( 1 << ( V_58 - 8 ) ) ;
}
static int F_29 ( struct V_5 * V_6 , int V_98 )
{
struct V_71 * V_72 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_99 ;
V_9 -> V_100 [ 0 ] = V_98 ;
return F_30 ( V_72 , F_31 ( V_72 , 1 ) ,
V_9 -> V_100 , V_101 ,
& V_99 , V_102 ) ;
}
static int F_32 ( struct V_5 * V_6 , int V_103 )
{
struct V_71 * V_72 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_104 ;
int V_21 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_105 ; V_4 ++ ) {
V_21 = F_30 ( V_72 , F_33 ( V_72 , 8 ) ,
V_9 -> V_106 , V_107 ,
& V_104 , V_102 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_9 -> V_106 [ 0 ] == V_103 )
return 0 ;
}
return - V_108 ;
}
static int F_34 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_109 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
if ( V_109 != 0 )
return - V_95 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_13 ) {
V_9 -> V_13 = 1 ;
V_21 = F_21 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_21 < 0 ) {
V_9 -> V_13 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
V_15 -> V_32 -> V_110 = NULL ;
}
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
static int F_35 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_77 * V_43 = & V_15 -> V_32 -> V_43 ;
unsigned int V_53 = V_43 -> V_44 ;
T_2 V_96 = 0 ;
T_2 V_97 = 0 ;
T_2 V_111 = 0 ;
int V_21 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
V_15 -> V_32 -> V_112 = 0 ;
for ( V_4 = 0 ; V_4 < V_53 ; V_4 ++ ) {
unsigned int V_58 = F_36 ( V_43 -> V_113 [ V_4 ] ) ;
F_28 ( V_58 , & V_96 , & V_97 ) ;
}
V_9 -> V_100 [ 1 ] = V_53 ;
V_9 -> V_100 [ 2 ] = 0x12 ;
V_9 -> V_100 [ 3 ] = 0x03 ;
V_9 -> V_100 [ 4 ] = 0x00 ;
V_9 -> V_100 [ 5 ] = V_96 ;
V_9 -> V_100 [ 6 ] = V_97 ;
V_9 -> V_100 [ 7 ] = V_111 ;
V_21 = F_29 ( V_6 , V_114 ) ;
if ( V_21 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
V_9 -> V_39 = V_9 -> V_40 ;
if ( V_43 -> V_79 == V_80 ) {
V_9 -> V_13 = 1 ;
V_21 = F_21 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_21 < 0 ) {
V_9 -> V_13 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
V_15 -> V_32 -> V_110 = NULL ;
} else {
V_15 -> V_32 -> V_110 = F_34 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_115 * V_116 ,
unsigned int * V_117 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_58 = F_36 ( V_116 -> V_118 ) ;
T_2 V_96 = 0 ;
T_2 V_97 = 0 ;
T_2 V_111 = 0 ;
int V_21 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_119 ;
}
F_28 ( V_58 , & V_96 , & V_97 ) ;
V_9 -> V_100 [ 1 ] = 0x16 ;
V_9 -> V_100 [ 2 ] = 0x80 ;
V_9 -> V_100 [ 3 ] = 0x00 ;
V_9 -> V_100 [ 4 ] = V_96 ;
V_9 -> V_100 [ 5 ] = V_97 ;
V_9 -> V_100 [ 6 ] = V_111 ;
V_21 = F_29 ( V_6 , V_120 ) ;
if ( V_21 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
for ( V_4 = 0 ; V_4 < V_116 -> V_121 ; V_4 ++ ) {
T_1 V_20 ;
V_21 = F_32 ( V_6 , V_120 ) ;
if ( V_21 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
V_20 = F_14 ( * ( ( T_1 * ) ( ( V_9 -> V_106 ) + 1 ) ) ) ;
V_20 &= 0x00ffffff ;
V_20 ^= 0x00800000 ;
V_117 [ V_4 ] = V_20 ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_116 -> V_121 ;
}
static int F_38 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_115 * V_116 ,
unsigned int * V_117 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_58 = F_36 ( V_116 -> V_118 ) ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
for ( V_4 = 0 ; V_4 < V_116 -> V_121 ; V_4 ++ )
V_117 [ V_4 ] = V_9 -> V_61 [ V_58 ] ;
F_6 ( & V_9 -> V_16 ) ;
return V_116 -> V_121 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_115 * V_116 ,
unsigned int * V_117 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_58 = F_36 ( V_116 -> V_118 ) ;
int V_21 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_50 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_119 ;
}
for ( V_4 = 0 ; V_4 < V_116 -> V_121 ; V_4 ++ ) {
V_9 -> V_100 [ 1 ] = 1 ;
V_9 -> V_100 [ 2 ] = V_117 [ V_4 ] ;
V_9 -> V_100 [ 3 ] = V_58 ;
V_21 = F_29 ( V_6 , V_122 ) ;
if ( V_21 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
V_9 -> V_61 [ V_58 ] = V_117 [ V_4 ] ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_116 -> V_121 ;
}
static int F_40 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_109 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
if ( V_109 != 0 )
return - V_95 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_50 ) {
V_9 -> V_50 = 1 ;
V_21 = F_21 ( V_6 , V_9 -> V_48 ,
V_9 -> V_49 , 0 ) ;
if ( V_21 < 0 ) {
V_9 -> V_50 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
V_15 -> V_32 -> V_110 = NULL ;
}
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_77 * V_43 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_78 = 0 ;
int V_64 ;
unsigned int V_123 ;
V_64 = 0 ;
V_78 |= F_24 ( & V_43 -> V_79 , V_80 | V_81 ) ;
if ( V_64 ) {
V_123 = V_90 ;
} else {
V_123 = V_83 ;
}
V_78 |= F_24 ( & V_43 -> V_82 , V_123 ) ;
V_78 |= F_24 ( & V_43 -> V_84 , V_80 ) ;
V_78 |= F_24 ( & V_43 -> V_85 , V_86 ) ;
V_78 |= F_24 ( & V_43 -> V_87 , V_86 | V_88 ) ;
if ( V_78 ) {
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
V_78 |= F_25 ( V_43 -> V_79 ) ;
V_78 |= F_25 ( V_43 -> V_87 ) ;
if ( V_78 )
return 2 ;
V_78 |= F_26 ( & V_43 -> V_89 , 0 ) ;
if ( V_43 -> V_82 == V_90 )
V_78 |= F_26 ( & V_43 -> V_91 , 0 ) ;
if ( V_43 -> V_82 == V_83 )
V_78 |= F_27 ( & V_43 -> V_91 ,
1000000 ) ;
if ( V_43 -> V_84 == V_83 )
V_78 |= F_27 ( & V_43 -> V_124 , 125000 ) ;
V_78 |= F_26 ( & V_43 -> V_93 , V_43 -> V_44 ) ;
if ( V_43 -> V_87 == V_86 ) {
} else {
V_78 |= F_26 ( & V_43 -> V_94 , 0 ) ;
}
if ( V_78 )
return 3 ;
if ( V_64 ) {
V_9 -> V_55 = V_43 -> V_124 / 125000 ;
} else {
V_9 -> V_55 = V_43 -> V_91 / 1000000 ;
}
if ( V_9 -> V_55 < 1 )
V_78 |= - V_95 ;
if ( V_43 -> V_87 == V_86 ) {
if ( V_64 ) {
V_9 -> V_57 = V_43 -> V_94 *
V_43 -> V_93 ;
} else {
V_9 -> V_57 = V_43 -> V_94 ;
}
V_9 -> V_56 = 0 ;
} else {
V_9 -> V_56 = 1 ;
V_9 -> V_57 = 0 ;
}
if ( V_78 )
return 4 ;
return 0 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_77 * V_43 = & V_15 -> V_32 -> V_43 ;
int V_21 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
V_15 -> V_32 -> V_112 = 0 ;
for ( V_4 = 0 ; V_4 < V_43 -> V_44 ; ++ V_4 )
V_9 -> V_59 [ V_4 ] = F_36 ( V_43 -> V_113 [ V_4 ] ) ;
V_9 -> V_54 = V_9 -> V_55 ;
if ( V_43 -> V_79 == V_80 ) {
V_9 -> V_50 = 1 ;
V_21 = F_21 ( V_6 , V_9 -> V_48 ,
V_9 -> V_49 , 0 ) ;
if ( V_21 < 0 ) {
V_9 -> V_50 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
V_15 -> V_32 -> V_110 = NULL ;
} else {
V_15 -> V_32 -> V_110 = F_40 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_115 * V_116 ,
unsigned int * V_117 )
{
int V_21 ;
V_21 = F_44 ( V_6 , V_15 , V_116 , V_117 , 0 ) ;
if ( V_21 )
return V_21 ;
return V_116 -> V_121 ;
}
static int F_45 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_115 * V_116 ,
unsigned int * V_117 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_125 = V_117 [ 0 ] ;
unsigned int V_126 = V_117 [ 1 ] ;
int V_21 ;
F_5 ( & V_9 -> V_16 ) ;
V_15 -> V_127 &= ~ V_125 ;
V_15 -> V_127 |= ( V_126 & V_125 ) ;
V_9 -> V_100 [ 1 ] = V_15 -> V_128 & 0xff ;
V_9 -> V_100 [ 4 ] = V_15 -> V_127 & 0xff ;
V_9 -> V_100 [ 2 ] = ( V_15 -> V_128 >> 8 ) & 0xff ;
V_9 -> V_100 [ 5 ] = ( V_15 -> V_127 >> 8 ) & 0xff ;
V_9 -> V_100 [ 3 ] = ( V_15 -> V_128 >> 16 ) & 0xff ;
V_9 -> V_100 [ 6 ] = ( V_15 -> V_127 >> 16 ) & 0xff ;
V_21 = F_29 ( V_6 , V_129 ) ;
if ( V_21 < 0 )
goto V_130;
V_21 = F_32 ( V_6 , V_129 ) ;
if ( V_21 < 0 )
goto V_130;
V_15 -> V_127 = V_9 -> V_106 [ 1 ] |
( V_9 -> V_106 [ 2 ] << 8 ) |
( V_9 -> V_106 [ 3 ] << 16 ) ;
V_117 [ 1 ] = V_15 -> V_127 ;
V_21 = V_116 -> V_121 ;
V_130:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static void F_46 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 ) {
if ( V_9 -> V_131 )
F_2 ( V_9 -> V_131 ) ;
}
V_9 -> V_132 = 0 ;
}
static int F_47 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_46 ( V_6 , V_9 -> V_132 ) ;
return F_29 ( V_6 , V_133 ) ;
}
static void F_48 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_17 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
switch ( V_1 -> V_22 ) {
case 0 :
break;
case - V_28 :
case - V_29 :
case - V_30 :
case - V_31 :
if ( V_9 -> V_132 )
F_46 ( V_6 , 0 ) ;
return;
default:
if ( V_9 -> V_132 ) {
F_10 ( V_6 -> V_27 ,
L_2 ,
V_36 , V_1 -> V_22 ) ;
F_46 ( V_6 , 0 ) ;
}
return;
}
if ( ! V_9 -> V_132 )
return;
V_1 -> V_62 = V_9 -> V_134 ;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_1 -> V_22 = 0 ;
V_21 = F_13 ( V_1 , V_37 ) ;
if ( V_21 < 0 ) {
F_10 ( V_6 -> V_27 , L_3 ,
V_36 , V_21 ) ;
if ( V_21 == V_38 )
F_10 ( V_6 -> V_27 ,
L_4 ) ;
F_46 ( V_6 , 0 ) ;
}
}
static int F_49 ( struct V_5 * V_6 )
{
struct V_71 * V_72 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 = V_9 -> V_131 ;
F_50 ( V_1 , V_72 , F_31 ( V_72 , 4 ) ,
V_1 -> V_24 , V_9 -> V_134 ,
F_48 , V_6 ) ;
return F_13 ( V_1 , V_37 ) ;
}
static int F_51 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_135 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_136 = 255 ;
if ( V_135 < V_137 ) {
return - V_138 ;
} else {
V_136 = ( V_135 / ( 6 * 512 * 1000 / 33 ) ) - 6 ;
if ( V_136 > 255 )
return - V_138 ;
}
V_9 -> V_139 = V_136 ;
V_9 -> V_140 = V_135 ;
return 0 ;
}
static int F_52 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
if ( V_9 -> V_132 )
return 0 ;
V_9 -> V_100 [ 1 ] = V_9 -> V_139 ;
V_21 = F_29 ( V_6 , V_141 ) ;
if ( V_21 < 0 )
return V_21 ;
memset ( V_9 -> V_131 -> V_24 , 0 , V_9 -> V_134 ) ;
V_9 -> V_132 = 1 ;
V_21 = F_49 ( V_6 ) ;
if ( V_21 < 0 ) {
V_9 -> V_132 = 0 ;
return V_21 ;
}
return 0 ;
}
static void F_53 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_58 ,
unsigned int V_142 ,
unsigned int V_143 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
char V_144 = ( 1 << V_58 ) ;
char V_145 = ( 16 << V_58 ) ;
char * V_146 = ( char * ) ( V_9 -> V_131 -> V_24 ) ;
int V_147 = V_9 -> V_134 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_147 ; V_4 ++ ) {
char V_148 = * V_146 ;
V_148 &= ~ V_144 ;
if ( V_4 < V_142 )
V_148 |= V_144 ;
if ( ! V_143 )
V_148 &= ~ V_145 ;
else
V_148 |= V_145 ;
* V_146 ++ = V_148 ;
}
}
static int F_54 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_115 * V_116 ,
unsigned int * V_117 )
{
unsigned int V_58 = F_36 ( V_116 -> V_118 ) ;
if ( V_116 -> V_121 != 1 )
return - V_95 ;
F_53 ( V_6 , V_15 , V_58 , V_117 [ 0 ] , 0 ) ;
return V_116 -> V_121 ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_115 * V_116 ,
unsigned int * V_117 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_58 = F_36 ( V_116 -> V_118 ) ;
switch ( V_117 [ 0 ] ) {
case V_149 :
if ( V_117 [ 1 ] != 0 )
return - V_95 ;
return F_52 ( V_6 , V_15 ) ;
case V_150 :
return F_47 ( V_6 , V_15 ) ;
case V_151 :
V_117 [ 1 ] = V_9 -> V_132 ;
return 0 ;
case V_152 :
return F_51 ( V_6 , V_15 , V_117 [ 1 ] ) ;
case V_153 :
V_117 [ 1 ] = V_9 -> V_140 ;
return 0 ;
case V_154 :
F_53 ( V_6 , V_15 , V_58 , V_117 [ 1 ] , ( V_117 [ 2 ] != 0 ) ) ;
return 0 ;
case V_155 :
return - V_95 ;
}
return - V_95 ;
}
static int F_56 ( struct V_5 * V_6 , int V_58 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_111 ;
V_45 V_20 ;
int V_21 ;
switch ( V_58 ) {
default:
case 0 :
V_111 = 0 ;
break;
case 1 :
V_111 = 1 ;
break;
case 2 :
V_111 = 4 ;
break;
case 3 :
V_111 = 8 ;
break;
case 4 :
V_111 = 16 ;
break;
case 5 :
V_111 = 32 ;
break;
}
V_9 -> V_100 [ 1 ] = 0x12 ;
V_9 -> V_100 [ 2 ] = 0x80 ;
V_9 -> V_100 [ 3 ] = 0x00 ;
V_9 -> V_100 [ 4 ] = 0 ;
V_9 -> V_100 [ 5 ] = 0 ;
V_9 -> V_100 [ 6 ] = V_111 ;
V_21 = F_29 ( V_6 , V_120 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_32 ( V_6 , V_120 ) ;
if ( V_21 < 0 )
return V_21 ;
V_20 = F_14 ( * ( ( T_1 * ) ( ( V_9 -> V_106 ) + 1 ) ) ) ;
V_20 &= 0x00ffffff ;
V_20 ^= 0x00800000 ;
return ( int ) V_20 ;
}
static int F_57 ( struct V_5 * V_6 ,
const T_3 * V_117 , T_4 V_156 ,
unsigned long V_17 )
{
struct V_71 * V_72 = F_12 ( V_6 ) ;
T_2 * V_146 ;
T_2 * V_92 ;
int V_21 ;
if ( ! V_117 )
return 0 ;
if ( V_156 > V_157 ) {
F_10 ( V_6 -> V_27 , L_6 ) ;
return - V_158 ;
}
V_146 = F_58 ( V_117 , V_156 , V_159 ) ;
if ( ! V_146 )
return - V_158 ;
V_92 = F_59 ( 1 , V_159 ) ;
if ( ! V_92 ) {
F_60 ( V_146 ) ;
return - V_158 ;
}
* V_92 = 1 ;
V_21 = F_61 ( V_72 , F_62 ( V_72 , 0 ) ,
V_160 ,
V_161 ,
V_162 , 0x0000 ,
V_92 , 1 ,
V_102 ) ;
if ( V_21 < 0 ) {
F_10 ( V_6 -> V_27 , L_7 ) ;
goto V_130;
}
V_21 = F_61 ( V_72 , F_62 ( V_72 , 0 ) ,
V_160 ,
V_161 ,
0 , 0x0000 ,
V_146 , V_156 ,
V_102 ) ;
if ( V_21 < 0 ) {
F_10 ( V_6 -> V_27 , L_8 ) ;
goto V_130;
}
* V_92 = 0 ;
V_21 = F_61 ( V_72 , F_62 ( V_72 , 0 ) ,
V_160 ,
V_161 ,
V_162 , 0x0000 ,
V_92 , 1 ,
V_102 ) ;
if ( V_21 < 0 )
F_10 ( V_6 -> V_27 , L_9 ) ;
V_130:
F_60 ( V_92 ) ;
F_60 ( V_146 ) ;
return V_21 ;
}
static int F_63 ( struct V_5 * V_6 )
{
struct V_71 * V_72 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_9 -> V_100 = F_64 ( V_101 , V_159 ) ;
V_9 -> V_23 = F_64 ( V_25 , V_159 ) ;
V_9 -> V_106 = F_64 ( V_107 , V_159 ) ;
V_9 -> V_11 = F_65 ( V_9 -> V_12 , sizeof( * V_1 ) ,
V_159 ) ;
V_9 -> V_48 = F_65 ( V_9 -> V_49 , sizeof( * V_1 ) ,
V_159 ) ;
if ( ! V_9 -> V_100 || ! V_9 -> V_23 || ! V_9 -> V_106 ||
! V_9 -> V_11 || ! V_9 -> V_48 )
return - V_158 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = F_66 ( 1 , V_159 ) ;
if ( ! V_1 )
return - V_158 ;
V_9 -> V_11 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_72 ;
V_1 -> V_17 = NULL ;
V_1 -> V_163 = F_67 ( V_72 , 6 ) ;
V_1 -> V_74 = V_75 ;
V_1 -> V_24 = F_64 ( V_25 , V_159 ) ;
if ( ! V_1 -> V_24 )
return - V_158 ;
V_1 -> V_164 = F_7 ;
V_1 -> V_66 = 1 ;
V_1 -> V_62 = V_25 ;
V_1 -> V_67 [ 0 ] . V_68 = 0 ;
V_1 -> V_67 [ 0 ] . V_69 = V_25 ;
}
for ( V_4 = 0 ; V_4 < V_9 -> V_49 ; V_4 ++ ) {
V_1 = F_66 ( 1 , V_159 ) ;
if ( ! V_1 )
return - V_158 ;
V_9 -> V_48 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_72 ;
V_1 -> V_17 = NULL ;
V_1 -> V_163 = F_68 ( V_72 , 2 ) ;
V_1 -> V_74 = V_75 ;
V_1 -> V_24 = F_64 ( V_63 , V_159 ) ;
if ( ! V_1 -> V_24 )
return - V_158 ;
V_1 -> V_164 = F_19 ;
V_1 -> V_66 = 1 ;
V_1 -> V_62 = V_63 ;
V_1 -> V_67 [ 0 ] . V_68 = 0 ;
V_1 -> V_67 [ 0 ] . V_69 = V_63 ;
if ( V_9 -> V_64 )
V_1 -> V_65 = 8 ;
else
V_1 -> V_65 = 1 ;
}
if ( V_9 -> V_134 ) {
V_1 = F_66 ( 0 , V_159 ) ;
if ( ! V_1 )
return - V_158 ;
V_9 -> V_131 = V_1 ;
V_1 -> V_24 = F_64 ( V_9 -> V_134 ,
V_159 ) ;
if ( ! V_1 -> V_24 )
return - V_158 ;
}
return 0 ;
}
static void F_69 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_1 = V_9 -> V_131 ;
if ( V_1 ) {
F_60 ( V_1 -> V_24 ) ;
F_70 ( V_1 ) ;
}
if ( V_9 -> V_48 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_49 ; V_4 ++ ) {
V_1 = V_9 -> V_48 [ V_4 ] ;
if ( V_1 ) {
F_60 ( V_1 -> V_24 ) ;
F_70 ( V_1 ) ;
}
}
F_60 ( V_9 -> V_48 ) ;
}
if ( V_9 -> V_11 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = V_9 -> V_11 [ V_4 ] ;
if ( V_1 ) {
F_60 ( V_1 -> V_24 ) ;
F_70 ( V_1 ) ;
}
}
F_60 ( V_9 -> V_11 ) ;
}
F_60 ( V_9 -> V_106 ) ;
F_60 ( V_9 -> V_23 ) ;
F_60 ( V_9 -> V_100 ) ;
}
static int F_71 ( struct V_5 * V_6 ,
unsigned long V_165 )
{
struct V_166 * V_167 = F_72 ( V_6 ) ;
struct V_71 * V_72 = F_12 ( V_6 ) ;
struct V_8 * V_9 ;
struct V_14 * V_15 ;
int V_68 ;
int V_21 ;
V_9 = F_73 ( V_6 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_158 ;
F_74 ( & V_9 -> V_16 , 1 ) ;
F_75 ( V_167 , V_9 ) ;
V_9 -> V_64 = ( V_72 -> V_168 == V_169 ) ;
if ( V_9 -> V_64 ) {
V_9 -> V_12 = V_170 ;
V_9 -> V_49 = V_171 ;
V_9 -> V_134 = 512 ;
} else {
V_9 -> V_12 = V_172 ;
V_9 -> V_49 = V_173 ;
}
V_21 = F_63 ( V_6 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_76 ( V_72 , V_167 -> V_174 -> V_175 . V_176 ,
3 ) ;
if ( V_21 < 0 ) {
F_10 ( V_6 -> V_27 ,
L_10 ) ;
return V_21 ;
}
V_21 = F_77 ( V_6 , & V_72 -> V_6 , V_177 ,
F_57 , 0 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_78 ( V_6 , ( V_9 -> V_64 ) ? 4 : 3 ) ;
if ( V_21 )
return V_21 ;
V_15 = & V_6 -> V_178 [ 0 ] ;
V_6 -> V_18 = V_15 ;
V_15 -> type = V_179 ;
V_15 -> V_180 = V_181 | V_182 | V_183 | V_184 ;
V_15 -> V_185 = V_186 ;
V_15 -> V_187 = V_186 ;
V_15 -> V_188 = 0x00ffffff ;
V_15 -> V_189 = & V_190 ;
V_15 -> V_191 = F_37 ;
V_15 -> V_192 = F_23 ;
V_15 -> V_193 = F_35 ;
V_15 -> V_194 = F_4 ;
V_15 = & V_6 -> V_178 [ 1 ] ;
V_6 -> V_51 = V_15 ;
V_15 -> type = V_195 ;
V_15 -> V_180 = V_196 | V_182 | V_197 ;
V_15 -> V_185 = V_198 ;
V_15 -> V_187 = V_15 -> V_185 ;
V_15 -> V_188 = 0x00ff ;
V_15 -> V_189 = & V_199 ;
V_15 -> V_200 = F_39 ;
V_15 -> V_191 = F_38 ;
V_15 -> V_192 = F_41 ;
V_15 -> V_193 = F_42 ;
V_15 -> V_194 = F_18 ;
V_15 = & V_6 -> V_178 [ 2 ] ;
V_15 -> type = V_201 ;
V_15 -> V_180 = V_181 | V_196 ;
V_15 -> V_185 = 24 ;
V_15 -> V_188 = 1 ;
V_15 -> V_189 = & V_202 ;
V_15 -> V_203 = F_45 ;
V_15 -> V_204 = F_43 ;
if ( V_9 -> V_64 ) {
V_15 = & V_6 -> V_178 [ 3 ] ;
V_15 -> type = V_205 ;
V_15 -> V_180 = V_196 | V_206 ;
V_15 -> V_185 = 8 ;
V_15 -> V_188 = V_9 -> V_134 ;
V_15 -> V_200 = F_54 ;
V_15 -> V_204 = F_55 ;
F_51 ( V_6 , V_15 , V_207 ) ;
}
V_68 = F_56 ( V_6 , 0 ) ;
if ( V_68 < 0 )
F_10 ( V_6 -> V_27 ,
L_11 ) ;
F_79 ( V_6 -> V_27 , L_12 , V_68 ) ;
return 0 ;
}
static void F_80 ( struct V_5 * V_6 )
{
struct V_166 * V_167 = F_72 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_75 ( V_167 , NULL ) ;
if ( ! V_9 )
return;
F_5 ( & V_9 -> V_16 ) ;
F_3 ( V_6 , 1 ) ;
F_17 ( V_6 , 1 ) ;
F_46 ( V_6 , 1 ) ;
F_69 ( V_6 ) ;
F_6 ( & V_9 -> V_16 ) ;
}
static int F_81 ( struct V_166 * V_167 ,
const struct V_208 * V_209 )
{
return F_82 ( V_167 , & V_210 , 0 ) ;
}
