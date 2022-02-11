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
V_21 = F_16 ( V_15 , & V_20 , sizeof( T_1 ) ) ;
if ( F_11 ( V_21 == 0 ) ) {
F_3 ( V_6 , 0 ) ;
return;
}
}
V_15 -> V_32 -> V_33 |= ( V_45 | V_46 ) ;
F_9 ( V_6 , V_15 ) ;
}
static void F_17 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 && V_9 -> V_47 )
F_1 ( V_9 -> V_47 , V_9 -> V_48 ) ;
V_9 -> V_49 = 0 ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_16 ) ;
F_17 ( V_6 , V_9 -> V_49 ) ;
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_17 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_14 * V_15 = V_6 -> V_50 ;
T_2 * V_51 ;
int V_52 ;
int V_21 ;
int V_4 ;
switch ( V_1 -> V_22 ) {
case 0 :
break;
case - V_28 :
case - V_29 :
case - V_30 :
case - V_31 :
if ( V_9 -> V_49 ) {
F_17 ( V_6 , 0 ) ;
V_15 -> V_32 -> V_33 |= V_34 ;
F_9 ( V_6 , V_15 ) ;
}
return;
default:
if ( V_9 -> V_49 ) {
F_10 ( V_6 -> V_27 ,
L_2 ,
V_36 , V_1 -> V_22 ) ;
F_17 ( V_6 , 0 ) ;
V_15 -> V_32 -> V_33 |= ( V_35 | V_34 ) ;
F_9 ( V_6 , V_15 ) ;
}
return;
}
if ( ! V_9 -> V_49 )
return;
V_9 -> V_53 -- ;
if ( ( int ) V_9 -> V_53 <= 0 ) {
V_9 -> V_53 = V_9 -> V_54 ;
if ( ! V_9 -> V_55 ) {
V_9 -> V_56 -- ;
if ( V_9 -> V_56 < 0 ) {
F_17 ( V_6 , 0 ) ;
V_15 -> V_32 -> V_33 |= V_34 ;
F_9 ( V_6 , V_15 ) ;
return;
}
}
V_51 = V_1 -> V_24 ;
V_52 = V_15 -> V_32 -> V_43 . V_44 ;
* V_51 ++ = V_52 ;
for ( V_4 = 0 ; V_4 < V_52 ; V_4 ++ ) {
unsigned int V_57 = V_9 -> V_58 [ V_4 ] ;
unsigned short V_20 ;
V_21 = F_20 ( V_15 -> V_32 , & V_20 ) ;
if ( V_21 < 0 ) {
F_10 ( V_6 -> V_27 , L_5 ) ;
V_15 -> V_32 -> V_33 |= ( V_34 |
V_59 ) ;
}
* V_51 ++ = V_20 ;
* V_51 ++ = V_57 ;
V_9 -> V_60 [ V_57 ] = V_20 ;
V_15 -> V_32 -> V_33 |= V_45 ;
F_9 ( V_6 , V_15 ) ;
}
}
V_1 -> V_61 = V_62 ;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_1 -> V_22 = 0 ;
if ( V_9 -> V_63 )
V_1 -> V_64 = 8 ;
else
V_1 -> V_64 = 1 ;
V_1 -> V_65 = 1 ;
V_1 -> V_66 [ 0 ] . V_67 = 0 ;
V_1 -> V_66 [ 0 ] . V_68 = V_62 ;
V_1 -> V_66 [ 0 ] . V_22 = 0 ;
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
int V_69 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_21 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_1 = V_2 [ V_4 ] ;
if ( V_69 )
V_1 -> V_64 = V_9 -> V_72 ;
V_1 -> V_17 = V_6 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_22 = 0 ;
V_1 -> V_73 = V_74 ;
V_21 = F_13 ( V_1 , V_37 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_22 ( int V_75 )
{
if ( V_75 <= 2 )
return 2 ;
if ( V_75 <= 8 )
return 4 ;
return 8 ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_76 * V_43 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_63 = V_9 -> V_63 ;
int V_64 = F_22 ( V_43 -> V_44 ) ;
int V_77 = 0 ;
V_77 |= F_24 ( & V_43 -> V_78 , V_79 | V_80 ) ;
V_77 |= F_24 ( & V_43 -> V_81 , V_82 ) ;
V_77 |= F_24 ( & V_43 -> V_83 , V_79 ) ;
V_77 |= F_24 ( & V_43 -> V_84 , V_85 ) ;
V_77 |= F_24 ( & V_43 -> V_86 , V_85 | V_87 ) ;
if ( V_77 )
return 1 ;
V_77 |= F_25 ( V_43 -> V_78 ) ;
V_77 |= F_25 ( V_43 -> V_86 ) ;
if ( V_77 )
return 2 ;
V_77 |= F_26 ( & V_43 -> V_88 , 0 ) ;
if ( V_43 -> V_81 == V_89 )
V_77 |= F_26 ( & V_43 -> V_90 , 0 ) ;
if ( V_43 -> V_81 == V_82 ) {
unsigned int V_91 ;
if ( V_63 ) {
V_77 |= F_27 ( & V_43 -> V_90 ,
( 1000000 / 8 * V_64 ) ) ;
V_91 = ( V_43 -> V_90 / 125000 ) * 125000 ;
} else {
V_77 |= F_27 ( & V_43 -> V_90 ,
1000000 ) ;
V_91 = ( V_43 -> V_90 / 1000000 ) * 1000000 ;
}
V_77 |= F_26 ( & V_43 -> V_90 , V_91 ) ;
}
V_77 |= F_26 ( & V_43 -> V_92 , V_43 -> V_44 ) ;
if ( V_43 -> V_86 == V_85 ) {
} else {
V_77 |= F_26 ( & V_43 -> V_93 , 0 ) ;
}
if ( V_77 )
return 3 ;
if ( V_63 ) {
V_9 -> V_72 = V_64 ;
V_9 -> V_40 = V_43 -> V_90 / ( 125000 * V_64 ) ;
} else {
V_9 -> V_72 = 1 ;
V_9 -> V_40 = V_43 -> V_90 / 1000000 ;
}
if ( V_9 -> V_40 < 1 )
V_77 |= - V_94 ;
if ( V_43 -> V_86 == V_85 ) {
V_9 -> V_42 = V_43 -> V_93 ;
V_9 -> V_41 = 0 ;
} else {
V_9 -> V_41 = 1 ;
V_9 -> V_42 = 0 ;
}
if ( V_77 )
return 4 ;
return 0 ;
}
static void F_28 ( unsigned int V_57 ,
T_2 * V_95 ,
T_2 * V_96 )
{
if ( V_57 < 8 )
( * V_95 ) = ( * V_95 ) | ( 1 << V_57 ) ;
else if ( V_57 < 16 )
( * V_96 ) = ( * V_96 ) | ( 1 << ( V_57 - 8 ) ) ;
}
static int F_29 ( struct V_5 * V_6 , int V_97 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_98 ;
V_9 -> V_99 [ 0 ] = V_97 ;
return F_30 ( V_71 , F_31 ( V_71 , 1 ) ,
V_9 -> V_99 , V_100 ,
& V_98 , V_101 ) ;
}
static int F_32 ( struct V_5 * V_6 , int V_102 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_103 ;
int V_21 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_104 ; V_4 ++ ) {
V_21 = F_30 ( V_71 , F_33 ( V_71 , 8 ) ,
V_9 -> V_105 , V_106 ,
& V_103 , V_101 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_9 -> V_105 [ 0 ] == V_102 )
return 0 ;
}
return - V_107 ;
}
static int F_34 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_108 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
if ( V_108 != 0 )
return - V_94 ;
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
V_15 -> V_32 -> V_109 = NULL ;
}
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
static int F_35 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_76 * V_43 = & V_15 -> V_32 -> V_43 ;
unsigned int V_52 = V_43 -> V_44 ;
T_2 V_95 = 0 ;
T_2 V_96 = 0 ;
T_2 V_110 = 0 ;
int V_21 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
V_15 -> V_32 -> V_111 = 0 ;
for ( V_4 = 0 ; V_4 < V_52 ; V_4 ++ ) {
unsigned int V_57 = F_36 ( V_43 -> V_112 [ V_4 ] ) ;
F_28 ( V_57 , & V_95 , & V_96 ) ;
}
V_9 -> V_99 [ 1 ] = V_52 ;
V_9 -> V_99 [ 2 ] = 0x12 ;
V_9 -> V_99 [ 3 ] = 0x03 ;
V_9 -> V_99 [ 4 ] = 0x00 ;
V_9 -> V_99 [ 5 ] = V_95 ;
V_9 -> V_99 [ 6 ] = V_96 ;
V_9 -> V_99 [ 7 ] = V_110 ;
V_21 = F_29 ( V_6 , V_113 ) ;
if ( V_21 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
V_9 -> V_39 = V_9 -> V_40 ;
if ( V_43 -> V_78 == V_79 ) {
V_9 -> V_13 = 1 ;
V_21 = F_21 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_21 < 0 ) {
V_9 -> V_13 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
V_15 -> V_32 -> V_109 = NULL ;
} else {
V_15 -> V_32 -> V_109 = F_34 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_114 * V_115 ,
unsigned int * V_116 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_57 = F_36 ( V_115 -> V_117 ) ;
T_2 V_95 = 0 ;
T_2 V_96 = 0 ;
T_2 V_110 = 0 ;
int V_21 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_118 ;
}
F_28 ( V_57 , & V_95 , & V_96 ) ;
V_9 -> V_99 [ 1 ] = 0x16 ;
V_9 -> V_99 [ 2 ] = 0x80 ;
V_9 -> V_99 [ 3 ] = 0x00 ;
V_9 -> V_99 [ 4 ] = V_95 ;
V_9 -> V_99 [ 5 ] = V_96 ;
V_9 -> V_99 [ 6 ] = V_110 ;
V_21 = F_29 ( V_6 , V_119 ) ;
if ( V_21 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
for ( V_4 = 0 ; V_4 < V_115 -> V_120 ; V_4 ++ ) {
T_1 V_20 ;
V_21 = F_32 ( V_6 , V_119 ) ;
if ( V_21 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
V_20 = F_14 ( * ( ( T_1 * ) ( ( V_9 -> V_105 ) + 1 ) ) ) ;
V_20 &= 0x00ffffff ;
V_20 ^= 0x00800000 ;
V_116 [ V_4 ] = V_20 ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_115 -> V_120 ;
}
static int F_38 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_114 * V_115 ,
unsigned int * V_116 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_57 = F_36 ( V_115 -> V_117 ) ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
for ( V_4 = 0 ; V_4 < V_115 -> V_120 ; V_4 ++ )
V_116 [ V_4 ] = V_9 -> V_60 [ V_57 ] ;
F_6 ( & V_9 -> V_16 ) ;
return V_115 -> V_120 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_114 * V_115 ,
unsigned int * V_116 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_57 = F_36 ( V_115 -> V_117 ) ;
int V_21 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_49 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_118 ;
}
for ( V_4 = 0 ; V_4 < V_115 -> V_120 ; V_4 ++ ) {
V_9 -> V_99 [ 1 ] = 1 ;
V_9 -> V_99 [ 2 ] = V_116 [ V_4 ] ;
V_9 -> V_99 [ 3 ] = V_57 ;
V_21 = F_29 ( V_6 , V_121 ) ;
if ( V_21 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
V_9 -> V_60 [ V_57 ] = V_116 [ V_4 ] ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_115 -> V_120 ;
}
static int F_40 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_108 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
if ( V_108 != 0 )
return - V_94 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_49 ) {
V_9 -> V_49 = 1 ;
V_21 = F_21 ( V_6 , V_9 -> V_47 ,
V_9 -> V_48 , 0 ) ;
if ( V_21 < 0 ) {
V_9 -> V_49 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
V_15 -> V_32 -> V_109 = NULL ;
}
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_76 * V_43 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_77 = 0 ;
int V_63 ;
unsigned int V_122 ;
V_63 = 0 ;
V_77 |= F_24 ( & V_43 -> V_78 , V_79 | V_80 ) ;
if ( V_63 ) {
V_122 = V_89 ;
} else {
V_122 = V_82 ;
}
V_77 |= F_24 ( & V_43 -> V_81 , V_122 ) ;
V_77 |= F_24 ( & V_43 -> V_83 , V_79 ) ;
V_77 |= F_24 ( & V_43 -> V_84 , V_85 ) ;
V_77 |= F_24 ( & V_43 -> V_86 , V_85 | V_87 ) ;
if ( V_77 ) {
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
V_77 |= F_25 ( V_43 -> V_78 ) ;
V_77 |= F_25 ( V_43 -> V_86 ) ;
if ( V_77 )
return 2 ;
V_77 |= F_26 ( & V_43 -> V_88 , 0 ) ;
if ( V_43 -> V_81 == V_89 )
V_77 |= F_26 ( & V_43 -> V_90 , 0 ) ;
if ( V_43 -> V_81 == V_82 )
V_77 |= F_27 ( & V_43 -> V_90 ,
1000000 ) ;
if ( V_43 -> V_83 == V_82 )
V_77 |= F_27 ( & V_43 -> V_123 , 125000 ) ;
V_77 |= F_26 ( & V_43 -> V_92 , V_43 -> V_44 ) ;
if ( V_43 -> V_86 == V_85 ) {
} else {
V_77 |= F_26 ( & V_43 -> V_93 , 0 ) ;
}
if ( V_77 )
return 3 ;
if ( V_63 ) {
V_9 -> V_54 = V_43 -> V_123 / 125000 ;
} else {
V_9 -> V_54 = V_43 -> V_90 / 1000000 ;
}
if ( V_9 -> V_54 < 1 )
V_77 |= - V_94 ;
if ( V_43 -> V_86 == V_85 ) {
if ( V_63 ) {
V_9 -> V_56 = V_43 -> V_93 *
V_43 -> V_92 ;
} else {
V_9 -> V_56 = V_43 -> V_93 ;
}
V_9 -> V_55 = 0 ;
} else {
V_9 -> V_55 = 1 ;
V_9 -> V_56 = 0 ;
}
if ( V_77 )
return 4 ;
return 0 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_76 * V_43 = & V_15 -> V_32 -> V_43 ;
int V_21 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
V_15 -> V_32 -> V_111 = 0 ;
for ( V_4 = 0 ; V_4 < V_43 -> V_44 ; ++ V_4 )
V_9 -> V_58 [ V_4 ] = F_36 ( V_43 -> V_112 [ V_4 ] ) ;
V_9 -> V_53 = V_9 -> V_54 ;
if ( V_43 -> V_78 == V_79 ) {
V_9 -> V_49 = 1 ;
V_21 = F_21 ( V_6 , V_9 -> V_47 ,
V_9 -> V_48 , 0 ) ;
if ( V_21 < 0 ) {
V_9 -> V_49 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
V_15 -> V_32 -> V_109 = NULL ;
} else {
V_15 -> V_32 -> V_109 = F_40 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_114 * V_115 ,
unsigned int * V_116 )
{
int V_21 ;
V_21 = F_44 ( V_6 , V_15 , V_115 , V_116 , 0 ) ;
if ( V_21 )
return V_21 ;
return V_115 -> V_120 ;
}
static int F_45 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_114 * V_115 ,
unsigned int * V_116 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
F_5 ( & V_9 -> V_16 ) ;
F_46 ( V_15 , V_116 ) ;
V_9 -> V_99 [ 1 ] = V_15 -> V_124 & 0xff ;
V_9 -> V_99 [ 4 ] = V_15 -> V_125 & 0xff ;
V_9 -> V_99 [ 2 ] = ( V_15 -> V_124 >> 8 ) & 0xff ;
V_9 -> V_99 [ 5 ] = ( V_15 -> V_125 >> 8 ) & 0xff ;
V_9 -> V_99 [ 3 ] = ( V_15 -> V_124 >> 16 ) & 0xff ;
V_9 -> V_99 [ 6 ] = ( V_15 -> V_125 >> 16 ) & 0xff ;
V_21 = F_29 ( V_6 , V_126 ) ;
if ( V_21 < 0 )
goto V_127;
V_21 = F_32 ( V_6 , V_126 ) ;
if ( V_21 < 0 )
goto V_127;
V_15 -> V_125 = V_9 -> V_105 [ 1 ] |
( V_9 -> V_105 [ 2 ] << 8 ) |
( V_9 -> V_105 [ 3 ] << 16 ) ;
V_116 [ 1 ] = V_15 -> V_125 ;
V_21 = V_115 -> V_120 ;
V_127:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static void F_47 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 ) {
if ( V_9 -> V_128 )
F_2 ( V_9 -> V_128 ) ;
}
V_9 -> V_129 = 0 ;
}
static int F_48 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_47 ( V_6 , V_9 -> V_129 ) ;
return F_29 ( V_6 , V_130 ) ;
}
static void F_49 ( struct V_1 * V_1 )
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
if ( V_9 -> V_129 )
F_47 ( V_6 , 0 ) ;
return;
default:
if ( V_9 -> V_129 ) {
F_10 ( V_6 -> V_27 ,
L_2 ,
V_36 , V_1 -> V_22 ) ;
F_47 ( V_6 , 0 ) ;
}
return;
}
if ( ! V_9 -> V_129 )
return;
V_1 -> V_61 = V_9 -> V_131 ;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_1 -> V_22 = 0 ;
V_21 = F_13 ( V_1 , V_37 ) ;
if ( V_21 < 0 ) {
F_10 ( V_6 -> V_27 , L_3 ,
V_36 , V_21 ) ;
if ( V_21 == V_38 )
F_10 ( V_6 -> V_27 ,
L_4 ) ;
F_47 ( V_6 , 0 ) ;
}
}
static int F_50 ( struct V_5 * V_6 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 = V_9 -> V_128 ;
F_51 ( V_1 , V_71 , F_31 ( V_71 , 4 ) ,
V_1 -> V_24 , V_9 -> V_131 ,
F_49 , V_6 ) ;
return F_13 ( V_1 , V_37 ) ;
}
static int F_52 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_132 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_133 = 255 ;
if ( V_132 < V_134 ) {
return - V_135 ;
} else {
V_133 = ( V_132 / ( 6 * 512 * 1000 / 33 ) ) - 6 ;
if ( V_133 > 255 )
return - V_135 ;
}
V_9 -> V_136 = V_133 ;
V_9 -> V_137 = V_132 ;
return 0 ;
}
static int F_53 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
if ( V_9 -> V_129 )
return 0 ;
V_9 -> V_99 [ 1 ] = V_9 -> V_136 ;
V_21 = F_29 ( V_6 , V_138 ) ;
if ( V_21 < 0 )
return V_21 ;
memset ( V_9 -> V_128 -> V_24 , 0 , V_9 -> V_131 ) ;
V_9 -> V_129 = 1 ;
V_21 = F_50 ( V_6 ) ;
if ( V_21 < 0 ) {
V_9 -> V_129 = 0 ;
return V_21 ;
}
return 0 ;
}
static void F_54 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_57 ,
unsigned int V_139 ,
unsigned int V_140 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
char V_141 = ( 1 << V_57 ) ;
char V_142 = ( 16 << V_57 ) ;
char * V_143 = ( char * ) ( V_9 -> V_128 -> V_24 ) ;
int V_144 = V_9 -> V_131 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_144 ; V_4 ++ ) {
char V_145 = * V_143 ;
V_145 &= ~ V_141 ;
if ( V_4 < V_139 )
V_145 |= V_141 ;
if ( ! V_140 )
V_145 &= ~ V_142 ;
else
V_145 |= V_142 ;
* V_143 ++ = V_145 ;
}
}
static int F_55 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_114 * V_115 ,
unsigned int * V_116 )
{
unsigned int V_57 = F_36 ( V_115 -> V_117 ) ;
if ( V_115 -> V_120 != 1 )
return - V_94 ;
F_54 ( V_6 , V_15 , V_57 , V_116 [ 0 ] , 0 ) ;
return V_115 -> V_120 ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_114 * V_115 ,
unsigned int * V_116 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_57 = F_36 ( V_115 -> V_117 ) ;
switch ( V_116 [ 0 ] ) {
case V_146 :
if ( V_116 [ 1 ] != 0 )
return - V_94 ;
return F_53 ( V_6 , V_15 ) ;
case V_147 :
return F_48 ( V_6 , V_15 ) ;
case V_148 :
V_116 [ 1 ] = V_9 -> V_129 ;
return 0 ;
case V_149 :
return F_52 ( V_6 , V_15 , V_116 [ 1 ] ) ;
case V_150 :
V_116 [ 1 ] = V_9 -> V_137 ;
return 0 ;
case V_151 :
F_54 ( V_6 , V_15 , V_57 , V_116 [ 1 ] , ( V_116 [ 2 ] != 0 ) ) ;
return 0 ;
case V_152 :
return - V_94 ;
}
return - V_94 ;
}
static int F_57 ( struct V_5 * V_6 , int V_57 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_110 ;
T_1 V_20 ;
int V_21 ;
switch ( V_57 ) {
default:
case 0 :
V_110 = 0 ;
break;
case 1 :
V_110 = 1 ;
break;
case 2 :
V_110 = 4 ;
break;
case 3 :
V_110 = 8 ;
break;
case 4 :
V_110 = 16 ;
break;
case 5 :
V_110 = 32 ;
break;
}
V_9 -> V_99 [ 1 ] = 0x12 ;
V_9 -> V_99 [ 2 ] = 0x80 ;
V_9 -> V_99 [ 3 ] = 0x00 ;
V_9 -> V_99 [ 4 ] = 0 ;
V_9 -> V_99 [ 5 ] = 0 ;
V_9 -> V_99 [ 6 ] = V_110 ;
V_21 = F_29 ( V_6 , V_119 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_32 ( V_6 , V_119 ) ;
if ( V_21 < 0 )
return V_21 ;
V_20 = F_14 ( * ( ( T_1 * ) ( ( V_9 -> V_105 ) + 1 ) ) ) ;
V_20 &= 0x00ffffff ;
V_20 ^= 0x00800000 ;
return ( int ) V_20 ;
}
static int F_58 ( struct V_5 * V_6 ,
const T_3 * V_116 , T_4 V_153 ,
unsigned long V_17 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
T_2 * V_143 ;
T_2 * V_91 ;
int V_21 ;
if ( ! V_116 )
return 0 ;
if ( V_153 > V_154 ) {
F_10 ( V_6 -> V_27 , L_6 ) ;
return - V_155 ;
}
V_143 = F_59 ( V_116 , V_153 , V_156 ) ;
if ( ! V_143 )
return - V_155 ;
V_91 = F_60 ( 1 , V_156 ) ;
if ( ! V_91 ) {
F_61 ( V_143 ) ;
return - V_155 ;
}
* V_91 = 1 ;
V_21 = F_62 ( V_71 , F_63 ( V_71 , 0 ) ,
V_157 ,
V_158 ,
V_159 , 0x0000 ,
V_91 , 1 ,
V_101 ) ;
if ( V_21 < 0 ) {
F_10 ( V_6 -> V_27 , L_7 ) ;
goto V_127;
}
V_21 = F_62 ( V_71 , F_63 ( V_71 , 0 ) ,
V_157 ,
V_158 ,
0 , 0x0000 ,
V_143 , V_153 ,
V_101 ) ;
if ( V_21 < 0 ) {
F_10 ( V_6 -> V_27 , L_8 ) ;
goto V_127;
}
* V_91 = 0 ;
V_21 = F_62 ( V_71 , F_63 ( V_71 , 0 ) ,
V_157 ,
V_158 ,
V_159 , 0x0000 ,
V_91 , 1 ,
V_101 ) ;
if ( V_21 < 0 )
F_10 ( V_6 -> V_27 , L_9 ) ;
V_127:
F_61 ( V_91 ) ;
F_61 ( V_143 ) ;
return V_21 ;
}
static int F_64 ( struct V_5 * V_6 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_9 -> V_99 = F_65 ( V_100 , V_156 ) ;
V_9 -> V_23 = F_65 ( V_25 , V_156 ) ;
V_9 -> V_105 = F_65 ( V_106 , V_156 ) ;
V_9 -> V_11 = F_66 ( V_9 -> V_12 , sizeof( * V_1 ) ,
V_156 ) ;
V_9 -> V_47 = F_66 ( V_9 -> V_48 , sizeof( * V_1 ) ,
V_156 ) ;
if ( ! V_9 -> V_99 || ! V_9 -> V_23 || ! V_9 -> V_105 ||
! V_9 -> V_11 || ! V_9 -> V_47 )
return - V_155 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = F_67 ( 1 , V_156 ) ;
if ( ! V_1 )
return - V_155 ;
V_9 -> V_11 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_17 = NULL ;
V_1 -> V_160 = F_68 ( V_71 , 6 ) ;
V_1 -> V_73 = V_74 ;
V_1 -> V_24 = F_65 ( V_25 , V_156 ) ;
if ( ! V_1 -> V_24 )
return - V_155 ;
V_1 -> V_161 = F_7 ;
V_1 -> V_65 = 1 ;
V_1 -> V_61 = V_25 ;
V_1 -> V_66 [ 0 ] . V_67 = 0 ;
V_1 -> V_66 [ 0 ] . V_68 = V_25 ;
}
for ( V_4 = 0 ; V_4 < V_9 -> V_48 ; V_4 ++ ) {
V_1 = F_67 ( 1 , V_156 ) ;
if ( ! V_1 )
return - V_155 ;
V_9 -> V_47 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_17 = NULL ;
V_1 -> V_160 = F_69 ( V_71 , 2 ) ;
V_1 -> V_73 = V_74 ;
V_1 -> V_24 = F_65 ( V_62 , V_156 ) ;
if ( ! V_1 -> V_24 )
return - V_155 ;
V_1 -> V_161 = F_19 ;
V_1 -> V_65 = 1 ;
V_1 -> V_61 = V_62 ;
V_1 -> V_66 [ 0 ] . V_67 = 0 ;
V_1 -> V_66 [ 0 ] . V_68 = V_62 ;
if ( V_9 -> V_63 )
V_1 -> V_64 = 8 ;
else
V_1 -> V_64 = 1 ;
}
if ( V_9 -> V_131 ) {
V_1 = F_67 ( 0 , V_156 ) ;
if ( ! V_1 )
return - V_155 ;
V_9 -> V_128 = V_1 ;
V_1 -> V_24 = F_65 ( V_9 -> V_131 ,
V_156 ) ;
if ( ! V_1 -> V_24 )
return - V_155 ;
}
return 0 ;
}
static void F_70 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_1 = V_9 -> V_128 ;
if ( V_1 ) {
F_61 ( V_1 -> V_24 ) ;
F_71 ( V_1 ) ;
}
if ( V_9 -> V_47 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_48 ; V_4 ++ ) {
V_1 = V_9 -> V_47 [ V_4 ] ;
if ( V_1 ) {
F_61 ( V_1 -> V_24 ) ;
F_71 ( V_1 ) ;
}
}
F_61 ( V_9 -> V_47 ) ;
}
if ( V_9 -> V_11 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = V_9 -> V_11 [ V_4 ] ;
if ( V_1 ) {
F_61 ( V_1 -> V_24 ) ;
F_71 ( V_1 ) ;
}
}
F_61 ( V_9 -> V_11 ) ;
}
F_61 ( V_9 -> V_105 ) ;
F_61 ( V_9 -> V_23 ) ;
F_61 ( V_9 -> V_99 ) ;
}
static int F_72 ( struct V_5 * V_6 ,
unsigned long V_162 )
{
struct V_163 * V_164 = F_73 ( V_6 ) ;
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 ;
struct V_14 * V_15 ;
int V_67 ;
int V_21 ;
V_9 = F_74 ( V_6 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_155 ;
F_75 ( & V_9 -> V_16 , 1 ) ;
F_76 ( V_164 , V_9 ) ;
V_9 -> V_63 = ( V_71 -> V_165 == V_166 ) ;
if ( V_9 -> V_63 ) {
V_9 -> V_12 = V_167 ;
V_9 -> V_48 = V_168 ;
V_9 -> V_131 = 512 ;
} else {
V_9 -> V_12 = V_169 ;
V_9 -> V_48 = V_170 ;
}
V_21 = F_64 ( V_6 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_77 ( V_71 , V_164 -> V_171 -> V_172 . V_173 ,
3 ) ;
if ( V_21 < 0 ) {
F_10 ( V_6 -> V_27 ,
L_10 ) ;
return V_21 ;
}
V_21 = F_78 ( V_6 , & V_71 -> V_6 , V_174 ,
F_58 , 0 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_79 ( V_6 , ( V_9 -> V_63 ) ? 4 : 3 ) ;
if ( V_21 )
return V_21 ;
V_15 = & V_6 -> V_175 [ 0 ] ;
V_6 -> V_18 = V_15 ;
V_15 -> type = V_176 ;
V_15 -> V_177 = V_178 | V_179 | V_180 | V_181 ;
V_15 -> V_182 = V_183 ;
V_15 -> V_184 = V_183 ;
V_15 -> V_185 = 0x00ffffff ;
V_15 -> V_186 = & V_187 ;
V_15 -> V_188 = F_37 ;
V_15 -> V_189 = F_23 ;
V_15 -> V_190 = F_35 ;
V_15 -> V_191 = F_4 ;
V_15 = & V_6 -> V_175 [ 1 ] ;
V_6 -> V_50 = V_15 ;
V_15 -> type = V_192 ;
V_15 -> V_177 = V_193 | V_179 | V_194 ;
V_15 -> V_182 = V_195 ;
V_15 -> V_184 = V_15 -> V_182 ;
V_15 -> V_185 = 0x00ff ;
V_15 -> V_186 = & V_196 ;
V_15 -> V_197 = F_39 ;
V_15 -> V_188 = F_38 ;
V_15 -> V_189 = F_41 ;
V_15 -> V_190 = F_42 ;
V_15 -> V_191 = F_18 ;
V_15 = & V_6 -> V_175 [ 2 ] ;
V_15 -> type = V_198 ;
V_15 -> V_177 = V_178 | V_193 ;
V_15 -> V_182 = 24 ;
V_15 -> V_185 = 1 ;
V_15 -> V_186 = & V_199 ;
V_15 -> V_200 = F_45 ;
V_15 -> V_201 = F_43 ;
if ( V_9 -> V_63 ) {
V_15 = & V_6 -> V_175 [ 3 ] ;
V_15 -> type = V_202 ;
V_15 -> V_177 = V_193 | V_203 ;
V_15 -> V_182 = 8 ;
V_15 -> V_185 = V_9 -> V_131 ;
V_15 -> V_197 = F_55 ;
V_15 -> V_201 = F_56 ;
F_52 ( V_6 , V_15 , V_204 ) ;
}
V_67 = F_57 ( V_6 , 0 ) ;
if ( V_67 < 0 )
F_10 ( V_6 -> V_27 ,
L_11 ) ;
F_80 ( V_6 -> V_27 , L_12 , V_67 ) ;
return 0 ;
}
static void F_81 ( struct V_5 * V_6 )
{
struct V_163 * V_164 = F_73 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_76 ( V_164 , NULL ) ;
if ( ! V_9 )
return;
F_5 ( & V_9 -> V_16 ) ;
F_3 ( V_6 , 1 ) ;
F_17 ( V_6 , 1 ) ;
F_47 ( V_6 , 1 ) ;
F_70 ( V_6 ) ;
F_6 ( & V_9 -> V_16 ) ;
}
static int F_82 ( struct V_163 * V_164 ,
const struct V_205 * V_206 )
{
return F_83 ( V_164 , & V_207 , 0 ) ;
}
