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
static void F_7 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_1 * V_1 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
unsigned int V_21 ;
T_1 V_22 ;
int V_23 ;
int V_4 ;
V_9 -> V_24 -- ;
if ( V_9 -> V_24 == 0 ) {
V_9 -> V_24 = V_9 -> V_25 ;
V_21 = F_8 ( V_9 -> V_26 [ 0 ] ) ;
for ( V_4 = 0 ; V_4 < V_20 -> V_27 ; V_4 ++ ) {
V_22 = F_8 ( V_9 -> V_26 [ V_4 + 1 ] ) ;
V_22 &= 0x00ffffff ;
V_22 ^= 0x00800000 ;
if ( ! F_9 ( V_15 , & V_22 , 1 ) )
return;
}
if ( V_20 -> V_28 == V_29 &&
V_18 -> V_30 >= V_20 -> V_31 )
V_18 -> V_32 |= V_33 ;
}
if ( ! ( V_18 -> V_32 & V_34 ) ) {
V_1 -> V_6 = F_10 ( V_6 ) ;
V_23 = F_11 ( V_1 , V_35 ) ;
if ( V_23 < 0 ) {
F_12 ( V_6 -> V_36 ,
L_1 ,
V_37 , V_23 ) ;
if ( V_23 == - V_38 )
F_12 ( V_6 -> V_36 ,
L_2 ) ;
V_18 -> V_32 |= V_39 ;
}
}
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_40 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_14 * V_15 = V_6 -> V_41 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! V_9 -> V_13 )
return;
switch ( V_1 -> V_42 ) {
case 0 :
memcpy ( V_9 -> V_26 , V_1 -> V_43 , V_44 ) ;
F_7 ( V_6 , V_15 , V_1 ) ;
break;
case - V_45 :
F_14 ( V_6 -> V_36 , L_3 ) ;
F_7 ( V_6 , V_15 , V_1 ) ;
break;
case - V_46 :
case - V_47 :
case - V_48 :
case - V_49 :
V_18 -> V_32 |= V_39 ;
break;
default:
F_12 ( V_6 -> V_36 , L_4 ,
V_37 , V_1 -> V_42 ) ;
V_18 -> V_32 |= V_39 ;
break;
}
if ( V_18 -> V_32 & V_34 )
F_3 ( V_6 , 0 ) ;
F_15 ( V_6 , V_15 ) ;
}
static void F_16 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 && V_9 -> V_50 )
F_1 ( V_9 -> V_50 , V_9 -> V_51 ) ;
V_9 -> V_52 = 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_16 ) ;
F_16 ( V_6 , V_9 -> V_52 ) ;
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static void F_18 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_1 * V_1 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
T_2 * V_53 ;
int V_23 ;
int V_4 ;
V_9 -> V_54 -- ;
if ( V_9 -> V_54 == 0 ) {
V_9 -> V_54 = V_9 -> V_55 ;
if ( V_20 -> V_28 == V_29 &&
V_18 -> V_30 >= V_20 -> V_31 ) {
V_18 -> V_32 |= V_33 ;
return;
}
V_53 = V_1 -> V_43 ;
* V_53 ++ = V_20 -> V_27 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_27 ; V_4 ++ ) {
unsigned int V_56 = F_19 ( V_20 -> V_57 [ V_4 ] ) ;
unsigned short V_22 ;
if ( ! F_20 ( V_15 , & V_22 , 1 ) ) {
F_12 ( V_6 -> V_36 , L_5 ) ;
V_18 -> V_32 |= V_58 ;
return;
}
* V_53 ++ = V_22 ;
* V_53 ++ = V_56 ;
V_15 -> V_59 [ V_56 ] = V_22 ;
}
}
if ( ! ( V_18 -> V_32 & V_34 ) ) {
V_1 -> V_60 = V_61 ;
V_1 -> V_6 = F_10 ( V_6 ) ;
V_1 -> V_42 = 0 ;
if ( V_9 -> V_62 )
V_1 -> V_63 = 8 ;
else
V_1 -> V_63 = 1 ;
V_1 -> V_64 = 1 ;
V_1 -> V_65 [ 0 ] . V_66 = 0 ;
V_1 -> V_65 [ 0 ] . V_67 = V_61 ;
V_1 -> V_65 [ 0 ] . V_42 = 0 ;
V_23 = F_11 ( V_1 , V_35 ) ;
if ( V_23 < 0 ) {
F_12 ( V_6 -> V_36 ,
L_1 ,
V_37 , V_23 ) ;
if ( V_23 == - V_38 )
F_12 ( V_6 -> V_36 ,
L_2 ) ;
V_18 -> V_32 |= V_39 ;
}
}
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_40 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_14 * V_15 = V_6 -> V_68 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! V_9 -> V_52 )
return;
switch ( V_1 -> V_42 ) {
case 0 :
F_18 ( V_6 , V_15 , V_1 ) ;
break;
case - V_46 :
case - V_47 :
case - V_48 :
case - V_49 :
V_18 -> V_32 |= V_39 ;
break;
default:
F_12 ( V_6 -> V_36 , L_4 ,
V_37 , V_1 -> V_42 ) ;
V_18 -> V_32 |= V_39 ;
break;
}
if ( V_18 -> V_32 & V_34 )
F_16 ( V_6 , 0 ) ;
F_15 ( V_6 , V_15 ) ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_1 * * V_2 , int V_3 ,
int V_69 )
{
struct V_70 * V_71 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_23 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_1 = V_2 [ V_4 ] ;
if ( V_69 )
V_1 -> V_63 = V_9 -> V_72 ;
V_1 -> V_40 = V_6 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_42 = 0 ;
V_1 -> V_73 = V_74 ;
V_23 = F_11 ( V_1 , V_35 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static int F_23 ( int V_75 )
{
if ( V_75 <= 2 )
return 2 ;
if ( V_75 <= 8 )
return 4 ;
return 8 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_19 * V_20 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_62 = V_9 -> V_62 ;
int V_63 = F_23 ( V_20 -> V_27 ) ;
int V_76 = 0 ;
V_76 |= F_25 ( & V_20 -> V_77 , V_78 | V_79 ) ;
V_76 |= F_25 ( & V_20 -> V_80 , V_81 ) ;
V_76 |= F_25 ( & V_20 -> V_82 , V_78 ) ;
V_76 |= F_25 ( & V_20 -> V_83 , V_29 ) ;
V_76 |= F_25 ( & V_20 -> V_28 , V_29 | V_84 ) ;
if ( V_76 )
return 1 ;
V_76 |= F_26 ( V_20 -> V_77 ) ;
V_76 |= F_26 ( V_20 -> V_28 ) ;
if ( V_76 )
return 2 ;
V_76 |= F_27 ( & V_20 -> V_85 , 0 ) ;
if ( V_20 -> V_80 == V_86 )
V_76 |= F_27 ( & V_20 -> V_87 , 0 ) ;
if ( V_20 -> V_80 == V_81 ) {
unsigned int V_88 ;
if ( V_62 ) {
V_76 |= F_28 ( & V_20 -> V_87 ,
( 1000000 / 8 * V_63 ) ) ;
V_88 = ( V_20 -> V_87 / 125000 ) * 125000 ;
} else {
V_76 |= F_28 ( & V_20 -> V_87 ,
1000000 ) ;
V_88 = ( V_20 -> V_87 / 1000000 ) * 1000000 ;
}
V_76 |= F_27 ( & V_20 -> V_87 , V_88 ) ;
}
V_76 |= F_27 ( & V_20 -> V_89 , V_20 -> V_27 ) ;
if ( V_20 -> V_28 == V_29 )
V_76 |= F_28 ( & V_20 -> V_31 , 1 ) ;
else
V_76 |= F_27 ( & V_20 -> V_31 , 0 ) ;
if ( V_76 )
return 3 ;
if ( V_62 ) {
V_9 -> V_72 = V_63 ;
V_9 -> V_25 = V_20 -> V_87 / ( 125000 * V_63 ) ;
} else {
V_9 -> V_72 = 1 ;
V_9 -> V_25 = V_20 -> V_87 / 1000000 ;
}
if ( V_9 -> V_25 < 1 )
V_76 |= - V_90 ;
if ( V_76 )
return 4 ;
return 0 ;
}
static void F_29 ( unsigned int V_56 ,
T_2 * V_91 ,
T_2 * V_92 )
{
if ( V_56 < 8 )
( * V_91 ) = ( * V_91 ) | ( 1 << V_56 ) ;
else if ( V_56 < 16 )
( * V_92 ) = ( * V_92 ) | ( 1 << ( V_56 - 8 ) ) ;
}
static int F_30 ( struct V_5 * V_6 , int V_93 )
{
struct V_70 * V_71 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_94 ;
V_9 -> V_95 [ 0 ] = V_93 ;
return F_31 ( V_71 , F_32 ( V_71 , 1 ) ,
V_9 -> V_95 , V_96 ,
& V_94 , V_97 ) ;
}
static int F_33 ( struct V_5 * V_6 , int V_98 )
{
struct V_70 * V_71 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_99 ;
int V_23 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_100 ; V_4 ++ ) {
V_23 = F_31 ( V_71 , F_34 ( V_71 , 8 ) ,
V_9 -> V_101 , V_102 ,
& V_99 , V_97 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_9 -> V_101 [ 0 ] == V_98 )
return 0 ;
}
return - V_103 ;
}
static int F_35 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_104 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_23 ;
if ( V_104 != V_20 -> V_85 )
return - V_90 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_13 ) {
V_9 -> V_13 = 1 ;
V_23 = F_22 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_23 < 0 ) {
V_9 -> V_13 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_23 ;
}
V_15 -> V_18 -> V_105 = NULL ;
}
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
static int F_36 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
unsigned int V_106 = V_20 -> V_27 ;
T_2 V_91 = 0 ;
T_2 V_92 = 0 ;
T_2 V_107 = 0 ;
int V_23 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
for ( V_4 = 0 ; V_4 < V_106 ; V_4 ++ ) {
unsigned int V_56 = F_19 ( V_20 -> V_57 [ V_4 ] ) ;
F_29 ( V_56 , & V_91 , & V_92 ) ;
}
V_9 -> V_95 [ 1 ] = V_106 ;
V_9 -> V_95 [ 2 ] = 0x12 ;
V_9 -> V_95 [ 3 ] = 0x03 ;
V_9 -> V_95 [ 4 ] = 0x00 ;
V_9 -> V_95 [ 5 ] = V_91 ;
V_9 -> V_95 [ 6 ] = V_92 ;
V_9 -> V_95 [ 7 ] = V_107 ;
V_23 = F_30 ( V_6 , V_108 ) ;
if ( V_23 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_23 ;
}
V_9 -> V_24 = V_9 -> V_25 ;
if ( V_20 -> V_77 == V_78 ) {
V_9 -> V_13 = 1 ;
V_23 = F_22 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_23 < 0 ) {
V_9 -> V_13 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_23 ;
}
V_15 -> V_18 -> V_105 = NULL ;
} else {
V_15 -> V_18 -> V_105 = F_35 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_109 * V_110 ,
unsigned int * V_111 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_56 = F_19 ( V_110 -> V_112 ) ;
T_2 V_91 = 0 ;
T_2 V_92 = 0 ;
T_2 V_107 = 0 ;
int V_23 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_113 ;
}
F_29 ( V_56 , & V_91 , & V_92 ) ;
V_9 -> V_95 [ 1 ] = 0x16 ;
V_9 -> V_95 [ 2 ] = 0x80 ;
V_9 -> V_95 [ 3 ] = 0x00 ;
V_9 -> V_95 [ 4 ] = V_91 ;
V_9 -> V_95 [ 5 ] = V_92 ;
V_9 -> V_95 [ 6 ] = V_107 ;
V_23 = F_30 ( V_6 , V_114 ) ;
if ( V_23 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_23 ;
}
for ( V_4 = 0 ; V_4 < V_110 -> V_115 ; V_4 ++ ) {
T_1 V_22 ;
V_23 = F_33 ( V_6 , V_114 ) ;
if ( V_23 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_23 ;
}
V_22 = F_8 ( F_38 ( ( V_116
* ) ( V_9 -> V_101 + 1 ) ) ) ;
V_22 &= 0x00ffffff ;
V_22 ^= 0x00800000 ;
V_111 [ V_4 ] = V_22 ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_110 -> V_115 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_109 * V_110 ,
unsigned int * V_111 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_23 ;
F_5 ( & V_9 -> V_16 ) ;
V_23 = F_40 ( V_6 , V_15 , V_110 , V_111 ) ;
F_6 ( & V_9 -> V_16 ) ;
return V_23 ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_109 * V_110 ,
unsigned int * V_111 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_56 = F_19 ( V_110 -> V_112 ) ;
int V_23 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_52 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_113 ;
}
for ( V_4 = 0 ; V_4 < V_110 -> V_115 ; V_4 ++ ) {
V_9 -> V_95 [ 1 ] = 1 ;
V_9 -> V_95 [ 2 ] = V_111 [ V_4 ] ;
V_9 -> V_95 [ 3 ] = V_56 ;
V_23 = F_30 ( V_6 , V_117 ) ;
if ( V_23 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_23 ;
}
V_15 -> V_59 [ V_56 ] = V_111 [ V_4 ] ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_110 -> V_115 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_104 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_23 ;
if ( V_104 != V_20 -> V_85 )
return - V_90 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_52 ) {
V_9 -> V_52 = 1 ;
V_23 = F_22 ( V_6 , V_9 -> V_50 ,
V_9 -> V_51 , 0 ) ;
if ( V_23 < 0 ) {
V_9 -> V_52 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_23 ;
}
V_15 -> V_18 -> V_105 = NULL ;
}
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_19 * V_20 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_76 = 0 ;
int V_62 ;
unsigned int V_118 ;
V_62 = 0 ;
V_76 |= F_25 ( & V_20 -> V_77 , V_78 | V_79 ) ;
if ( V_62 ) {
V_118 = V_86 ;
} else {
V_118 = V_81 ;
}
V_76 |= F_25 ( & V_20 -> V_80 , V_118 ) ;
V_76 |= F_25 ( & V_20 -> V_82 , V_78 ) ;
V_76 |= F_25 ( & V_20 -> V_83 , V_29 ) ;
V_76 |= F_25 ( & V_20 -> V_28 , V_29 | V_84 ) ;
if ( V_76 ) {
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
V_76 |= F_26 ( V_20 -> V_77 ) ;
V_76 |= F_26 ( V_20 -> V_28 ) ;
if ( V_76 )
return 2 ;
V_76 |= F_27 ( & V_20 -> V_85 , 0 ) ;
if ( V_20 -> V_80 == V_86 )
V_76 |= F_27 ( & V_20 -> V_87 , 0 ) ;
if ( V_20 -> V_80 == V_81 )
V_76 |= F_28 ( & V_20 -> V_87 ,
1000000 ) ;
if ( V_20 -> V_82 == V_81 )
V_76 |= F_28 ( & V_20 -> V_119 , 125000 ) ;
V_76 |= F_27 ( & V_20 -> V_89 , V_20 -> V_27 ) ;
if ( V_20 -> V_28 == V_29 )
V_76 |= F_28 ( & V_20 -> V_31 , 1 ) ;
else
V_76 |= F_27 ( & V_20 -> V_31 , 0 ) ;
if ( V_76 )
return 3 ;
if ( V_62 ) {
V_9 -> V_55 = V_20 -> V_119 / 125000 ;
} else {
V_9 -> V_55 = V_20 -> V_87 / 1000000 ;
}
if ( V_9 -> V_55 < 1 )
V_76 |= - V_90 ;
if ( V_76 )
return 4 ;
return 0 ;
}
static int F_44 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_23 ;
F_5 ( & V_9 -> V_16 ) ;
V_9 -> V_54 = V_9 -> V_55 ;
if ( V_20 -> V_77 == V_78 ) {
V_9 -> V_52 = 1 ;
V_23 = F_22 ( V_6 , V_9 -> V_50 ,
V_9 -> V_51 , 0 ) ;
if ( V_23 < 0 ) {
V_9 -> V_52 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_23 ;
}
V_15 -> V_18 -> V_105 = NULL ;
} else {
V_15 -> V_18 -> V_105 = F_42 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_109 * V_110 ,
unsigned int * V_111 )
{
int V_23 ;
V_23 = F_46 ( V_6 , V_15 , V_110 , V_111 , 0 ) ;
if ( V_23 )
return V_23 ;
return V_110 -> V_115 ;
}
static int F_47 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_109 * V_110 ,
unsigned int * V_111 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_23 ;
F_5 ( & V_9 -> V_16 ) ;
F_48 ( V_15 , V_111 ) ;
V_9 -> V_95 [ 1 ] = V_15 -> V_120 & 0xff ;
V_9 -> V_95 [ 4 ] = V_15 -> V_121 & 0xff ;
V_9 -> V_95 [ 2 ] = ( V_15 -> V_120 >> 8 ) & 0xff ;
V_9 -> V_95 [ 5 ] = ( V_15 -> V_121 >> 8 ) & 0xff ;
V_9 -> V_95 [ 3 ] = ( V_15 -> V_120 >> 16 ) & 0xff ;
V_9 -> V_95 [ 6 ] = ( V_15 -> V_121 >> 16 ) & 0xff ;
V_23 = F_30 ( V_6 , V_122 ) ;
if ( V_23 < 0 )
goto V_123;
V_23 = F_33 ( V_6 , V_122 ) ;
if ( V_23 < 0 )
goto V_123;
V_15 -> V_121 = V_9 -> V_101 [ 1 ] |
( V_9 -> V_101 [ 2 ] << 8 ) |
( V_9 -> V_101 [ 3 ] << 16 ) ;
V_111 [ 1 ] = V_15 -> V_121 ;
V_23 = V_110 -> V_115 ;
V_123:
F_6 ( & V_9 -> V_16 ) ;
return V_23 ;
}
static void F_49 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 ) {
if ( V_9 -> V_124 )
F_2 ( V_9 -> V_124 ) ;
}
V_9 -> V_125 = 0 ;
}
static int F_50 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_49 ( V_6 , V_9 -> V_125 ) ;
return F_30 ( V_6 , V_126 ) ;
}
static void F_51 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_40 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_23 ;
switch ( V_1 -> V_42 ) {
case 0 :
break;
case - V_46 :
case - V_47 :
case - V_48 :
case - V_49 :
if ( V_9 -> V_125 )
F_49 ( V_6 , 0 ) ;
return;
default:
if ( V_9 -> V_125 ) {
F_12 ( V_6 -> V_36 ,
L_4 ,
V_37 , V_1 -> V_42 ) ;
F_49 ( V_6 , 0 ) ;
}
return;
}
if ( ! V_9 -> V_125 )
return;
V_1 -> V_60 = V_9 -> V_127 ;
V_1 -> V_6 = F_10 ( V_6 ) ;
V_1 -> V_42 = 0 ;
V_23 = F_11 ( V_1 , V_35 ) ;
if ( V_23 < 0 ) {
F_12 ( V_6 -> V_36 , L_1 ,
V_37 , V_23 ) ;
if ( V_23 == - V_38 )
F_12 ( V_6 -> V_36 ,
L_2 ) ;
F_49 ( V_6 , 0 ) ;
}
}
static int F_52 ( struct V_5 * V_6 )
{
struct V_70 * V_71 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 = V_9 -> V_124 ;
F_53 ( V_1 , V_71 , F_32 ( V_71 , 4 ) ,
V_1 -> V_43 , V_9 -> V_127 ,
F_51 , V_6 ) ;
return F_11 ( V_1 , V_35 ) ;
}
static int F_54 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_128 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_129 = 255 ;
if ( V_128 < V_130 )
return - V_131 ;
V_129 = ( V_128 / ( 6 * 512 * 1000 / 33 ) ) - 6 ;
if ( V_129 > 255 )
return - V_131 ;
V_9 -> V_132 = V_129 ;
V_9 -> V_133 = V_128 ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_23 ;
if ( V_9 -> V_125 )
return 0 ;
V_9 -> V_95 [ 1 ] = V_9 -> V_132 ;
V_23 = F_30 ( V_6 , V_134 ) ;
if ( V_23 < 0 )
return V_23 ;
memset ( V_9 -> V_124 -> V_43 , 0 , V_9 -> V_127 ) ;
V_9 -> V_125 = 1 ;
V_23 = F_52 ( V_6 ) ;
if ( V_23 < 0 ) {
V_9 -> V_125 = 0 ;
return V_23 ;
}
return 0 ;
}
static void F_56 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_56 ,
unsigned int V_135 ,
unsigned int V_136 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
char V_137 = ( 1 << V_56 ) ;
char V_138 = ( 16 << V_56 ) ;
char * V_139 = ( char * ) ( V_9 -> V_124 -> V_43 ) ;
int V_140 = V_9 -> V_127 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_140 ; V_4 ++ ) {
char V_141 = * V_139 ;
V_141 &= ~ V_137 ;
if ( V_4 < V_135 )
V_141 |= V_137 ;
if ( ! V_136 )
V_141 &= ~ V_138 ;
else
V_141 |= V_138 ;
* V_139 ++ = V_141 ;
}
}
static int F_57 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_109 * V_110 ,
unsigned int * V_111 )
{
unsigned int V_56 = F_19 ( V_110 -> V_112 ) ;
if ( V_110 -> V_115 != 1 )
return - V_90 ;
F_56 ( V_6 , V_15 , V_56 , V_111 [ 0 ] , 0 ) ;
return V_110 -> V_115 ;
}
static int F_58 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_109 * V_110 ,
unsigned int * V_111 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_56 = F_19 ( V_110 -> V_112 ) ;
switch ( V_111 [ 0 ] ) {
case V_142 :
if ( V_111 [ 1 ] != 0 )
return - V_90 ;
return F_55 ( V_6 , V_15 ) ;
case V_143 :
return F_50 ( V_6 , V_15 ) ;
case V_144 :
V_111 [ 1 ] = V_9 -> V_125 ;
return 0 ;
case V_145 :
return F_54 ( V_6 , V_15 , V_111 [ 1 ] ) ;
case V_146 :
V_111 [ 1 ] = V_9 -> V_133 ;
return 0 ;
case V_147 :
F_56 ( V_6 , V_15 , V_56 , V_111 [ 1 ] , ( V_111 [ 2 ] != 0 ) ) ;
return 0 ;
case V_148 :
return - V_90 ;
}
return - V_90 ;
}
static int F_59 ( struct V_5 * V_6 , int V_56 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_107 ;
T_1 V_22 ;
int V_23 ;
switch ( V_56 ) {
default:
case 0 :
V_107 = 0 ;
break;
case 1 :
V_107 = 1 ;
break;
case 2 :
V_107 = 4 ;
break;
case 3 :
V_107 = 8 ;
break;
case 4 :
V_107 = 16 ;
break;
case 5 :
V_107 = 32 ;
break;
}
V_9 -> V_95 [ 1 ] = 0x12 ;
V_9 -> V_95 [ 2 ] = 0x80 ;
V_9 -> V_95 [ 3 ] = 0x00 ;
V_9 -> V_95 [ 4 ] = 0 ;
V_9 -> V_95 [ 5 ] = 0 ;
V_9 -> V_95 [ 6 ] = V_107 ;
V_23 = F_30 ( V_6 , V_114 ) ;
if ( V_23 < 0 )
return V_23 ;
V_23 = F_33 ( V_6 , V_114 ) ;
if ( V_23 < 0 )
return V_23 ;
V_22 = F_8 ( F_38 ( ( V_116 * ) ( V_9 -> V_101 + 1 ) ) ) ;
V_22 &= 0x00ffffff ;
V_22 ^= 0x00800000 ;
return ( int ) V_22 ;
}
static int F_60 ( struct V_5 * V_6 ,
const T_3 * V_111 , T_4 V_149 ,
unsigned long V_40 )
{
struct V_70 * V_71 = F_10 ( V_6 ) ;
T_2 * V_139 ;
T_2 * V_88 ;
int V_23 ;
if ( ! V_111 )
return 0 ;
if ( V_149 > V_150 ) {
F_12 ( V_6 -> V_36 , L_6 ) ;
return - V_151 ;
}
V_139 = F_61 ( V_111 , V_149 , V_152 ) ;
if ( ! V_139 )
return - V_151 ;
V_88 = F_62 ( 1 , V_152 ) ;
if ( ! V_88 ) {
F_63 ( V_139 ) ;
return - V_151 ;
}
* V_88 = 1 ;
V_23 = F_64 ( V_71 , F_65 ( V_71 , 0 ) ,
V_153 ,
V_154 ,
V_155 , 0x0000 ,
V_88 , 1 ,
V_97 ) ;
if ( V_23 < 0 ) {
F_12 ( V_6 -> V_36 , L_7 ) ;
goto V_123;
}
V_23 = F_64 ( V_71 , F_65 ( V_71 , 0 ) ,
V_153 ,
V_154 ,
0 , 0x0000 ,
V_139 , V_149 ,
V_97 ) ;
if ( V_23 < 0 ) {
F_12 ( V_6 -> V_36 , L_8 ) ;
goto V_123;
}
* V_88 = 0 ;
V_23 = F_64 ( V_71 , F_65 ( V_71 , 0 ) ,
V_153 ,
V_154 ,
V_155 , 0x0000 ,
V_88 , 1 ,
V_97 ) ;
if ( V_23 < 0 )
F_12 ( V_6 -> V_36 , L_9 ) ;
V_123:
F_63 ( V_88 ) ;
F_63 ( V_139 ) ;
return V_23 ;
}
static int F_66 ( struct V_5 * V_6 )
{
struct V_70 * V_71 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_9 -> V_95 = F_67 ( V_96 , V_152 ) ;
V_9 -> V_26 = F_67 ( V_44 , V_152 ) ;
V_9 -> V_101 = F_67 ( V_102 , V_152 ) ;
V_9 -> V_11 = F_68 ( V_9 -> V_12 , sizeof( V_1 ) , V_152 ) ;
V_9 -> V_50 = F_68 ( V_9 -> V_51 , sizeof( V_1 ) , V_152 ) ;
if ( ! V_9 -> V_95 || ! V_9 -> V_26 || ! V_9 -> V_101 ||
! V_9 -> V_11 || ! V_9 -> V_50 )
return - V_151 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = F_69 ( 1 , V_152 ) ;
if ( ! V_1 )
return - V_151 ;
V_9 -> V_11 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_40 = NULL ;
V_1 -> V_156 = F_70 ( V_71 , 6 ) ;
V_1 -> V_73 = V_74 ;
V_1 -> V_43 = F_67 ( V_44 , V_152 ) ;
if ( ! V_1 -> V_43 )
return - V_151 ;
V_1 -> V_157 = F_13 ;
V_1 -> V_64 = 1 ;
V_1 -> V_60 = V_44 ;
V_1 -> V_65 [ 0 ] . V_66 = 0 ;
V_1 -> V_65 [ 0 ] . V_67 = V_44 ;
}
for ( V_4 = 0 ; V_4 < V_9 -> V_51 ; V_4 ++ ) {
V_1 = F_69 ( 1 , V_152 ) ;
if ( ! V_1 )
return - V_151 ;
V_9 -> V_50 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_40 = NULL ;
V_1 -> V_156 = F_71 ( V_71 , 2 ) ;
V_1 -> V_73 = V_74 ;
V_1 -> V_43 = F_67 ( V_61 , V_152 ) ;
if ( ! V_1 -> V_43 )
return - V_151 ;
V_1 -> V_157 = F_21 ;
V_1 -> V_64 = 1 ;
V_1 -> V_60 = V_61 ;
V_1 -> V_65 [ 0 ] . V_66 = 0 ;
V_1 -> V_65 [ 0 ] . V_67 = V_61 ;
if ( V_9 -> V_62 )
V_1 -> V_63 = 8 ;
else
V_1 -> V_63 = 1 ;
}
if ( V_9 -> V_127 ) {
V_1 = F_69 ( 0 , V_152 ) ;
if ( ! V_1 )
return - V_151 ;
V_9 -> V_124 = V_1 ;
V_1 -> V_43 = F_67 ( V_9 -> V_127 ,
V_152 ) ;
if ( ! V_1 -> V_43 )
return - V_151 ;
}
return 0 ;
}
static void F_72 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_1 = V_9 -> V_124 ;
if ( V_1 ) {
F_63 ( V_1 -> V_43 ) ;
F_73 ( V_1 ) ;
}
if ( V_9 -> V_50 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_51 ; V_4 ++ ) {
V_1 = V_9 -> V_50 [ V_4 ] ;
if ( V_1 ) {
F_63 ( V_1 -> V_43 ) ;
F_73 ( V_1 ) ;
}
}
F_63 ( V_9 -> V_50 ) ;
}
if ( V_9 -> V_11 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = V_9 -> V_11 [ V_4 ] ;
if ( V_1 ) {
F_63 ( V_1 -> V_43 ) ;
F_73 ( V_1 ) ;
}
}
F_63 ( V_9 -> V_11 ) ;
}
F_63 ( V_9 -> V_101 ) ;
F_63 ( V_9 -> V_26 ) ;
F_63 ( V_9 -> V_95 ) ;
}
static int F_74 ( struct V_5 * V_6 ,
unsigned long V_158 )
{
struct V_159 * V_160 = F_75 ( V_6 ) ;
struct V_70 * V_71 = F_10 ( V_6 ) ;
struct V_8 * V_9 ;
struct V_14 * V_15 ;
int V_66 ;
int V_23 ;
V_9 = F_76 ( V_6 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_151 ;
F_77 ( & V_9 -> V_16 , 1 ) ;
F_78 ( V_160 , V_9 ) ;
V_9 -> V_62 = ( V_71 -> V_161 == V_162 ) ;
if ( V_9 -> V_62 ) {
V_9 -> V_12 = V_163 ;
V_9 -> V_51 = V_164 ;
V_9 -> V_127 = 512 ;
} else {
V_9 -> V_12 = V_165 ;
V_9 -> V_51 = V_166 ;
}
V_23 = F_66 ( V_6 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_79 ( V_71 , V_160 -> V_167 -> V_168 . V_169 ,
3 ) ;
if ( V_23 < 0 ) {
F_12 ( V_6 -> V_36 ,
L_10 ) ;
return V_23 ;
}
V_23 = F_80 ( V_6 , & V_71 -> V_6 , V_170 ,
F_60 , 0 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_81 ( V_6 , ( V_9 -> V_62 ) ? 4 : 3 ) ;
if ( V_23 )
return V_23 ;
V_15 = & V_6 -> V_171 [ 0 ] ;
V_6 -> V_41 = V_15 ;
V_15 -> type = V_172 ;
V_15 -> V_173 = V_174 | V_175 | V_176 | V_177 ;
V_15 -> V_178 = V_179 ;
V_15 -> V_180 = V_179 ;
V_15 -> V_181 = 0x00ffffff ;
V_15 -> V_182 = & V_183 ;
V_15 -> V_184 = F_37 ;
V_15 -> V_185 = F_24 ;
V_15 -> V_186 = F_36 ;
V_15 -> V_187 = F_4 ;
V_15 = & V_6 -> V_171 [ 1 ] ;
V_6 -> V_68 = V_15 ;
V_15 -> type = V_188 ;
V_15 -> V_173 = V_189 | V_175 | V_190 ;
V_15 -> V_178 = 4 ;
V_15 -> V_180 = V_15 -> V_178 ;
V_15 -> V_181 = 0x00ff ;
V_15 -> V_182 = & V_191 ;
V_15 -> V_192 = F_41 ;
V_15 -> V_184 = F_39 ;
V_15 -> V_185 = F_43 ;
V_15 -> V_186 = F_44 ;
V_15 -> V_187 = F_17 ;
V_23 = F_82 ( V_15 ) ;
if ( V_23 )
return V_23 ;
V_15 = & V_6 -> V_171 [ 2 ] ;
V_15 -> type = V_193 ;
V_15 -> V_173 = V_174 | V_189 ;
V_15 -> V_178 = 24 ;
V_15 -> V_181 = 1 ;
V_15 -> V_182 = & V_194 ;
V_15 -> V_195 = F_47 ;
V_15 -> V_196 = F_45 ;
if ( V_9 -> V_62 ) {
V_15 = & V_6 -> V_171 [ 3 ] ;
V_15 -> type = V_197 ;
V_15 -> V_173 = V_189 | V_198 ;
V_15 -> V_178 = 8 ;
V_15 -> V_181 = V_9 -> V_127 ;
V_15 -> V_192 = F_57 ;
V_15 -> V_196 = F_58 ;
F_54 ( V_6 , V_15 , V_199 ) ;
}
V_66 = F_59 ( V_6 , 0 ) ;
if ( V_66 < 0 ) {
F_12 ( V_6 -> V_36 ,
L_11 ) ;
return V_66 ;
}
F_83 ( V_6 -> V_36 , L_12 , V_66 ) ;
return 0 ;
}
static void F_84 ( struct V_5 * V_6 )
{
struct V_159 * V_160 = F_75 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_78 ( V_160 , NULL ) ;
if ( ! V_9 )
return;
F_5 ( & V_9 -> V_16 ) ;
F_3 ( V_6 , 1 ) ;
F_16 ( V_6 , 1 ) ;
F_49 ( V_6 , 1 ) ;
F_72 ( V_6 ) ;
F_6 ( & V_9 -> V_16 ) ;
}
static int F_85 ( struct V_159 * V_160 ,
const struct V_200 * V_201 )
{
return F_86 ( V_160 , & V_202 , 0 ) ;
}
