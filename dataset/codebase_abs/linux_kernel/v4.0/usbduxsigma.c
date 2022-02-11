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
T_1 V_21 ;
int V_22 ;
int V_4 ;
V_9 -> V_23 -- ;
if ( V_9 -> V_23 == 0 ) {
V_9 -> V_23 = V_9 -> V_24 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_25 ; V_4 ++ ) {
V_21 = F_8 ( V_9 -> V_26 [ V_4 + 1 ] ) ;
V_21 &= 0x00ffffff ;
V_21 ^= 0x00800000 ;
if ( ! F_9 ( V_15 , & V_21 , 1 ) )
return;
}
if ( V_20 -> V_27 == V_28 &&
V_18 -> V_29 >= V_20 -> V_30 )
V_18 -> V_31 |= V_32 ;
}
if ( ! ( V_18 -> V_31 & V_33 ) ) {
V_1 -> V_6 = F_10 ( V_6 ) ;
V_22 = F_11 ( V_1 , V_34 ) ;
if ( V_22 < 0 ) {
F_12 ( V_6 -> V_35 ,
L_1 ,
V_36 , V_22 ) ;
if ( V_22 == - V_37 )
F_12 ( V_6 -> V_35 ,
L_2 ) ;
V_18 -> V_31 |= V_38 ;
}
}
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_39 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_14 * V_15 = V_6 -> V_40 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! V_9 -> V_13 )
return;
switch ( V_1 -> V_41 ) {
case 0 :
memcpy ( V_9 -> V_26 , V_1 -> V_42 , V_43 ) ;
F_7 ( V_6 , V_15 , V_1 ) ;
break;
case - V_44 :
F_14 ( V_6 -> V_35 , L_3 ) ;
F_7 ( V_6 , V_15 , V_1 ) ;
break;
case - V_45 :
case - V_46 :
case - V_47 :
case - V_48 :
V_18 -> V_31 |= V_38 ;
break;
default:
F_12 ( V_6 -> V_35 , L_4 ,
V_36 , V_1 -> V_41 ) ;
V_18 -> V_31 |= V_38 ;
break;
}
if ( V_18 -> V_31 & V_33 )
F_3 ( V_6 , 0 ) ;
F_15 ( V_6 , V_15 ) ;
}
static void F_16 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 && V_9 -> V_49 )
F_1 ( V_9 -> V_49 , V_9 -> V_50 ) ;
V_9 -> V_51 = 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_16 ) ;
F_16 ( V_6 , V_9 -> V_51 ) ;
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
T_2 * V_52 ;
int V_22 ;
int V_4 ;
V_9 -> V_53 -- ;
if ( V_9 -> V_53 == 0 ) {
V_9 -> V_53 = V_9 -> V_54 ;
if ( V_20 -> V_27 == V_28 &&
V_18 -> V_29 >= V_20 -> V_30 ) {
V_18 -> V_31 |= V_32 ;
return;
}
V_52 = V_1 -> V_42 ;
* V_52 ++ = V_20 -> V_25 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_25 ; V_4 ++ ) {
unsigned int V_55 = F_19 ( V_20 -> V_56 [ V_4 ] ) ;
unsigned short V_21 ;
if ( ! F_20 ( V_15 , & V_21 , 1 ) ) {
F_12 ( V_6 -> V_35 , L_5 ) ;
V_18 -> V_31 |= V_57 ;
return;
}
* V_52 ++ = V_21 ;
* V_52 ++ = V_55 ;
V_15 -> V_58 [ V_55 ] = V_21 ;
}
}
if ( ! ( V_18 -> V_31 & V_33 ) ) {
V_1 -> V_59 = V_60 ;
V_1 -> V_6 = F_10 ( V_6 ) ;
V_1 -> V_41 = 0 ;
if ( V_9 -> V_61 )
V_1 -> V_62 = 8 ;
else
V_1 -> V_62 = 1 ;
V_1 -> V_63 = 1 ;
V_1 -> V_64 [ 0 ] . V_65 = 0 ;
V_1 -> V_64 [ 0 ] . V_66 = V_60 ;
V_1 -> V_64 [ 0 ] . V_41 = 0 ;
V_22 = F_11 ( V_1 , V_34 ) ;
if ( V_22 < 0 ) {
F_12 ( V_6 -> V_35 ,
L_1 ,
V_36 , V_22 ) ;
if ( V_22 == - V_37 )
F_12 ( V_6 -> V_35 ,
L_2 ) ;
V_18 -> V_31 |= V_38 ;
}
}
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_39 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_14 * V_15 = V_6 -> V_67 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! V_9 -> V_51 )
return;
switch ( V_1 -> V_41 ) {
case 0 :
F_18 ( V_6 , V_15 , V_1 ) ;
break;
case - V_45 :
case - V_46 :
case - V_47 :
case - V_48 :
V_18 -> V_31 |= V_38 ;
break;
default:
F_12 ( V_6 -> V_35 , L_4 ,
V_36 , V_1 -> V_41 ) ;
V_18 -> V_31 |= V_38 ;
break;
}
if ( V_18 -> V_31 & V_33 )
F_16 ( V_6 , 0 ) ;
F_15 ( V_6 , V_15 ) ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_1 * * V_2 , int V_3 ,
int V_68 )
{
struct V_69 * V_70 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_22 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_1 = V_2 [ V_4 ] ;
if ( V_68 )
V_1 -> V_62 = V_9 -> V_71 ;
V_1 -> V_39 = V_6 ;
V_1 -> V_6 = V_70 ;
V_1 -> V_41 = 0 ;
V_1 -> V_72 = V_73 ;
V_22 = F_11 ( V_1 , V_34 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_23 ( int V_74 )
{
if ( V_74 <= 2 )
return 2 ;
if ( V_74 <= 8 )
return 4 ;
return 8 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_19 * V_20 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_61 = V_9 -> V_61 ;
int V_62 = F_23 ( V_20 -> V_25 ) ;
int V_75 = 0 ;
V_75 |= F_25 ( & V_20 -> V_76 , V_77 | V_78 ) ;
V_75 |= F_25 ( & V_20 -> V_79 , V_80 ) ;
V_75 |= F_25 ( & V_20 -> V_81 , V_77 ) ;
V_75 |= F_25 ( & V_20 -> V_82 , V_28 ) ;
V_75 |= F_25 ( & V_20 -> V_27 , V_28 | V_83 ) ;
if ( V_75 )
return 1 ;
V_75 |= F_26 ( V_20 -> V_76 ) ;
V_75 |= F_26 ( V_20 -> V_27 ) ;
if ( V_75 )
return 2 ;
V_75 |= F_27 ( & V_20 -> V_84 , 0 ) ;
if ( V_20 -> V_79 == V_85 )
V_75 |= F_27 ( & V_20 -> V_86 , 0 ) ;
if ( V_20 -> V_79 == V_80 ) {
unsigned int V_87 ;
if ( V_61 ) {
V_75 |= F_28 ( & V_20 -> V_86 ,
( 1000000 / 8 * V_62 ) ) ;
V_87 = ( V_20 -> V_86 / 125000 ) * 125000 ;
} else {
V_75 |= F_28 ( & V_20 -> V_86 ,
1000000 ) ;
V_87 = ( V_20 -> V_86 / 1000000 ) * 1000000 ;
}
V_75 |= F_27 ( & V_20 -> V_86 , V_87 ) ;
}
V_75 |= F_27 ( & V_20 -> V_88 , V_20 -> V_25 ) ;
if ( V_20 -> V_27 == V_28 )
V_75 |= F_28 ( & V_20 -> V_30 , 1 ) ;
else
V_75 |= F_27 ( & V_20 -> V_30 , 0 ) ;
if ( V_75 )
return 3 ;
if ( V_61 ) {
V_9 -> V_71 = V_62 ;
V_9 -> V_24 = V_20 -> V_86 / ( 125000 * V_62 ) ;
} else {
V_9 -> V_71 = 1 ;
V_9 -> V_24 = V_20 -> V_86 / 1000000 ;
}
if ( V_9 -> V_24 < 1 )
V_75 |= - V_89 ;
if ( V_75 )
return 4 ;
return 0 ;
}
static void F_29 ( unsigned int V_55 ,
T_2 * V_90 ,
T_2 * V_91 )
{
if ( V_55 < 8 )
( * V_90 ) = ( * V_90 ) | ( 1 << V_55 ) ;
else if ( V_55 < 16 )
( * V_91 ) = ( * V_91 ) | ( 1 << ( V_55 - 8 ) ) ;
}
static int F_30 ( struct V_5 * V_6 , int V_92 )
{
struct V_69 * V_70 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_93 ;
V_9 -> V_94 [ 0 ] = V_92 ;
return F_31 ( V_70 , F_32 ( V_70 , 1 ) ,
V_9 -> V_94 , V_95 ,
& V_93 , V_96 ) ;
}
static int F_33 ( struct V_5 * V_6 , int V_97 )
{
struct V_69 * V_70 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_98 ;
int V_22 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_99 ; V_4 ++ ) {
V_22 = F_31 ( V_70 , F_34 ( V_70 , 8 ) ,
V_9 -> V_100 , V_101 ,
& V_98 , V_96 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_9 -> V_100 [ 0 ] == V_97 )
return 0 ;
}
return - V_102 ;
}
static int F_35 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_103 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_22 ;
if ( V_103 != V_20 -> V_84 )
return - V_89 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_13 ) {
V_9 -> V_13 = 1 ;
V_22 = F_22 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_22 < 0 ) {
V_9 -> V_13 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_15 -> V_18 -> V_104 = NULL ;
}
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
static int F_36 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
unsigned int V_105 = V_20 -> V_25 ;
T_2 V_90 = 0 ;
T_2 V_91 = 0 ;
T_2 V_106 = 0 ;
int V_22 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
for ( V_4 = 0 ; V_4 < V_105 ; V_4 ++ ) {
unsigned int V_55 = F_19 ( V_20 -> V_56 [ V_4 ] ) ;
F_29 ( V_55 , & V_90 , & V_91 ) ;
}
V_9 -> V_94 [ 1 ] = V_105 ;
V_9 -> V_94 [ 2 ] = 0x12 ;
V_9 -> V_94 [ 3 ] = 0x03 ;
V_9 -> V_94 [ 4 ] = 0x00 ;
V_9 -> V_94 [ 5 ] = V_90 ;
V_9 -> V_94 [ 6 ] = V_91 ;
V_9 -> V_94 [ 7 ] = V_106 ;
V_22 = F_30 ( V_6 , V_107 ) ;
if ( V_22 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_9 -> V_23 = V_9 -> V_24 ;
if ( V_20 -> V_76 == V_77 ) {
V_9 -> V_13 = 1 ;
V_22 = F_22 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_22 < 0 ) {
V_9 -> V_13 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_15 -> V_18 -> V_104 = NULL ;
} else {
V_15 -> V_18 -> V_104 = F_35 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_55 = F_19 ( V_109 -> V_111 ) ;
T_2 V_90 = 0 ;
T_2 V_91 = 0 ;
T_2 V_106 = 0 ;
int V_22 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_112 ;
}
F_29 ( V_55 , & V_90 , & V_91 ) ;
V_9 -> V_94 [ 1 ] = 0x16 ;
V_9 -> V_94 [ 2 ] = 0x80 ;
V_9 -> V_94 [ 3 ] = 0x00 ;
V_9 -> V_94 [ 4 ] = V_90 ;
V_9 -> V_94 [ 5 ] = V_91 ;
V_9 -> V_94 [ 6 ] = V_106 ;
V_22 = F_30 ( V_6 , V_113 ) ;
if ( V_22 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
for ( V_4 = 0 ; V_4 < V_109 -> V_114 ; V_4 ++ ) {
T_1 V_21 ;
V_22 = F_33 ( V_6 , V_113 ) ;
if ( V_22 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_21 = F_8 ( F_38 ( ( V_115
* ) ( V_9 -> V_100 + 1 ) ) ) ;
V_21 &= 0x00ffffff ;
V_21 ^= 0x00800000 ;
V_110 [ V_4 ] = V_21 ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_109 -> V_114 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_22 ;
F_5 ( & V_9 -> V_16 ) ;
V_22 = F_40 ( V_6 , V_15 , V_109 , V_110 ) ;
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_55 = F_19 ( V_109 -> V_111 ) ;
int V_22 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_51 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_112 ;
}
for ( V_4 = 0 ; V_4 < V_109 -> V_114 ; V_4 ++ ) {
V_9 -> V_94 [ 1 ] = 1 ;
V_9 -> V_94 [ 2 ] = V_110 [ V_4 ] ;
V_9 -> V_94 [ 3 ] = V_55 ;
V_22 = F_30 ( V_6 , V_116 ) ;
if ( V_22 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_15 -> V_58 [ V_55 ] = V_110 [ V_4 ] ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_109 -> V_114 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_103 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_22 ;
if ( V_103 != V_20 -> V_84 )
return - V_89 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_51 ) {
V_9 -> V_51 = 1 ;
V_22 = F_22 ( V_6 , V_9 -> V_49 ,
V_9 -> V_50 , 0 ) ;
if ( V_22 < 0 ) {
V_9 -> V_51 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_15 -> V_18 -> V_104 = NULL ;
}
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_19 * V_20 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_75 = 0 ;
int V_61 ;
unsigned int V_117 ;
V_61 = 0 ;
V_75 |= F_25 ( & V_20 -> V_76 , V_77 | V_78 ) ;
if ( V_61 ) {
V_117 = V_85 ;
} else {
V_117 = V_80 ;
}
V_75 |= F_25 ( & V_20 -> V_79 , V_117 ) ;
V_75 |= F_25 ( & V_20 -> V_81 , V_77 ) ;
V_75 |= F_25 ( & V_20 -> V_82 , V_28 ) ;
V_75 |= F_25 ( & V_20 -> V_27 , V_28 | V_83 ) ;
if ( V_75 ) {
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
V_75 |= F_26 ( V_20 -> V_76 ) ;
V_75 |= F_26 ( V_20 -> V_27 ) ;
if ( V_75 )
return 2 ;
V_75 |= F_27 ( & V_20 -> V_84 , 0 ) ;
if ( V_20 -> V_79 == V_85 )
V_75 |= F_27 ( & V_20 -> V_86 , 0 ) ;
if ( V_20 -> V_79 == V_80 )
V_75 |= F_28 ( & V_20 -> V_86 ,
1000000 ) ;
if ( V_20 -> V_81 == V_80 )
V_75 |= F_28 ( & V_20 -> V_118 , 125000 ) ;
V_75 |= F_27 ( & V_20 -> V_88 , V_20 -> V_25 ) ;
if ( V_20 -> V_27 == V_28 )
V_75 |= F_28 ( & V_20 -> V_30 , 1 ) ;
else
V_75 |= F_27 ( & V_20 -> V_30 , 0 ) ;
if ( V_75 )
return 3 ;
if ( V_61 ) {
V_9 -> V_54 = V_20 -> V_118 / 125000 ;
} else {
V_9 -> V_54 = V_20 -> V_86 / 1000000 ;
}
if ( V_9 -> V_54 < 1 )
V_75 |= - V_89 ;
if ( V_75 )
return 4 ;
return 0 ;
}
static int F_44 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_22 ;
F_5 ( & V_9 -> V_16 ) ;
V_9 -> V_53 = V_9 -> V_54 ;
if ( V_20 -> V_76 == V_77 ) {
V_9 -> V_51 = 1 ;
V_22 = F_22 ( V_6 , V_9 -> V_49 ,
V_9 -> V_50 , 0 ) ;
if ( V_22 < 0 ) {
V_9 -> V_51 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_15 -> V_18 -> V_104 = NULL ;
} else {
V_15 -> V_18 -> V_104 = F_42 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
int V_22 ;
V_22 = F_46 ( V_6 , V_15 , V_109 , V_110 , 0 ) ;
if ( V_22 )
return V_22 ;
return V_109 -> V_114 ;
}
static int F_47 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_22 ;
F_5 ( & V_9 -> V_16 ) ;
F_48 ( V_15 , V_110 ) ;
V_9 -> V_94 [ 1 ] = V_15 -> V_119 & 0xff ;
V_9 -> V_94 [ 4 ] = V_15 -> V_120 & 0xff ;
V_9 -> V_94 [ 2 ] = ( V_15 -> V_119 >> 8 ) & 0xff ;
V_9 -> V_94 [ 5 ] = ( V_15 -> V_120 >> 8 ) & 0xff ;
V_9 -> V_94 [ 3 ] = ( V_15 -> V_119 >> 16 ) & 0xff ;
V_9 -> V_94 [ 6 ] = ( V_15 -> V_120 >> 16 ) & 0xff ;
V_22 = F_30 ( V_6 , V_121 ) ;
if ( V_22 < 0 )
goto V_122;
V_22 = F_33 ( V_6 , V_121 ) ;
if ( V_22 < 0 )
goto V_122;
V_15 -> V_120 = V_9 -> V_100 [ 1 ] |
( V_9 -> V_100 [ 2 ] << 8 ) |
( V_9 -> V_100 [ 3 ] << 16 ) ;
V_110 [ 1 ] = V_15 -> V_120 ;
V_22 = V_109 -> V_114 ;
V_122:
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
static void F_49 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 ) {
if ( V_9 -> V_123 )
F_2 ( V_9 -> V_123 ) ;
}
V_9 -> V_124 = 0 ;
}
static int F_50 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_49 ( V_6 , V_9 -> V_124 ) ;
return F_30 ( V_6 , V_125 ) ;
}
static void F_51 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_39 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_22 ;
switch ( V_1 -> V_41 ) {
case 0 :
break;
case - V_45 :
case - V_46 :
case - V_47 :
case - V_48 :
if ( V_9 -> V_124 )
F_49 ( V_6 , 0 ) ;
return;
default:
if ( V_9 -> V_124 ) {
F_12 ( V_6 -> V_35 ,
L_4 ,
V_36 , V_1 -> V_41 ) ;
F_49 ( V_6 , 0 ) ;
}
return;
}
if ( ! V_9 -> V_124 )
return;
V_1 -> V_59 = V_9 -> V_126 ;
V_1 -> V_6 = F_10 ( V_6 ) ;
V_1 -> V_41 = 0 ;
V_22 = F_11 ( V_1 , V_34 ) ;
if ( V_22 < 0 ) {
F_12 ( V_6 -> V_35 , L_1 ,
V_36 , V_22 ) ;
if ( V_22 == - V_37 )
F_12 ( V_6 -> V_35 ,
L_2 ) ;
F_49 ( V_6 , 0 ) ;
}
}
static int F_52 ( struct V_5 * V_6 )
{
struct V_69 * V_70 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 = V_9 -> V_123 ;
F_53 ( V_1 , V_70 , F_32 ( V_70 , 4 ) ,
V_1 -> V_42 , V_9 -> V_126 ,
F_51 , V_6 ) ;
return F_11 ( V_1 , V_34 ) ;
}
static int F_54 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_127 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_128 = 255 ;
if ( V_127 < V_129 )
return - V_130 ;
V_128 = ( V_127 / ( 6 * 512 * 1000 / 33 ) ) - 6 ;
if ( V_128 > 255 )
return - V_130 ;
V_9 -> V_131 = V_128 ;
V_9 -> V_132 = V_127 ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_22 ;
if ( V_9 -> V_124 )
return 0 ;
V_9 -> V_94 [ 1 ] = V_9 -> V_131 ;
V_22 = F_30 ( V_6 , V_133 ) ;
if ( V_22 < 0 )
return V_22 ;
memset ( V_9 -> V_123 -> V_42 , 0 , V_9 -> V_126 ) ;
V_9 -> V_124 = 1 ;
V_22 = F_52 ( V_6 ) ;
if ( V_22 < 0 ) {
V_9 -> V_124 = 0 ;
return V_22 ;
}
return 0 ;
}
static void F_56 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_55 ,
unsigned int V_134 ,
unsigned int V_135 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
char V_136 = ( 1 << V_55 ) ;
char V_137 = ( 16 << V_55 ) ;
char * V_138 = ( char * ) ( V_9 -> V_123 -> V_42 ) ;
int V_139 = V_9 -> V_126 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_139 ; V_4 ++ ) {
char V_140 = * V_138 ;
V_140 &= ~ V_136 ;
if ( V_4 < V_134 )
V_140 |= V_136 ;
if ( ! V_135 )
V_140 &= ~ V_137 ;
else
V_140 |= V_137 ;
* V_138 ++ = V_140 ;
}
}
static int F_57 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
unsigned int V_55 = F_19 ( V_109 -> V_111 ) ;
if ( V_109 -> V_114 != 1 )
return - V_89 ;
F_56 ( V_6 , V_15 , V_55 , V_110 [ 0 ] , 0 ) ;
return V_109 -> V_114 ;
}
static int F_58 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_55 = F_19 ( V_109 -> V_111 ) ;
switch ( V_110 [ 0 ] ) {
case V_141 :
if ( V_110 [ 1 ] != 0 )
return - V_89 ;
return F_55 ( V_6 , V_15 ) ;
case V_142 :
return F_50 ( V_6 , V_15 ) ;
case V_143 :
V_110 [ 1 ] = V_9 -> V_124 ;
return 0 ;
case V_144 :
return F_54 ( V_6 , V_15 , V_110 [ 1 ] ) ;
case V_145 :
V_110 [ 1 ] = V_9 -> V_132 ;
return 0 ;
case V_146 :
F_56 ( V_6 , V_15 , V_55 , V_110 [ 1 ] , ( V_110 [ 2 ] != 0 ) ) ;
return 0 ;
case V_147 :
return - V_89 ;
}
return - V_89 ;
}
static int F_59 ( struct V_5 * V_6 , int V_55 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_106 ;
T_1 V_21 ;
int V_22 ;
switch ( V_55 ) {
default:
case 0 :
V_106 = 0 ;
break;
case 1 :
V_106 = 1 ;
break;
case 2 :
V_106 = 4 ;
break;
case 3 :
V_106 = 8 ;
break;
case 4 :
V_106 = 16 ;
break;
case 5 :
V_106 = 32 ;
break;
}
V_9 -> V_94 [ 1 ] = 0x12 ;
V_9 -> V_94 [ 2 ] = 0x80 ;
V_9 -> V_94 [ 3 ] = 0x00 ;
V_9 -> V_94 [ 4 ] = 0 ;
V_9 -> V_94 [ 5 ] = 0 ;
V_9 -> V_94 [ 6 ] = V_106 ;
V_22 = F_30 ( V_6 , V_113 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_33 ( V_6 , V_113 ) ;
if ( V_22 < 0 )
return V_22 ;
V_21 = F_8 ( F_38 ( ( V_115 * ) ( V_9 -> V_100 + 1 ) ) ) ;
V_21 &= 0x00ffffff ;
V_21 ^= 0x00800000 ;
return ( int ) V_21 ;
}
static int F_60 ( struct V_5 * V_6 ,
const T_3 * V_110 , T_4 V_148 ,
unsigned long V_39 )
{
struct V_69 * V_70 = F_10 ( V_6 ) ;
T_2 * V_138 ;
T_2 * V_87 ;
int V_22 ;
if ( ! V_110 )
return 0 ;
if ( V_148 > V_149 ) {
F_12 ( V_6 -> V_35 , L_6 ) ;
return - V_150 ;
}
V_138 = F_61 ( V_110 , V_148 , V_151 ) ;
if ( ! V_138 )
return - V_150 ;
V_87 = F_62 ( 1 , V_151 ) ;
if ( ! V_87 ) {
F_63 ( V_138 ) ;
return - V_150 ;
}
* V_87 = 1 ;
V_22 = F_64 ( V_70 , F_65 ( V_70 , 0 ) ,
V_152 ,
V_153 ,
V_154 , 0x0000 ,
V_87 , 1 ,
V_96 ) ;
if ( V_22 < 0 ) {
F_12 ( V_6 -> V_35 , L_7 ) ;
goto V_122;
}
V_22 = F_64 ( V_70 , F_65 ( V_70 , 0 ) ,
V_152 ,
V_153 ,
0 , 0x0000 ,
V_138 , V_148 ,
V_96 ) ;
if ( V_22 < 0 ) {
F_12 ( V_6 -> V_35 , L_8 ) ;
goto V_122;
}
* V_87 = 0 ;
V_22 = F_64 ( V_70 , F_65 ( V_70 , 0 ) ,
V_152 ,
V_153 ,
V_154 , 0x0000 ,
V_87 , 1 ,
V_96 ) ;
if ( V_22 < 0 )
F_12 ( V_6 -> V_35 , L_9 ) ;
V_122:
F_63 ( V_87 ) ;
F_63 ( V_138 ) ;
return V_22 ;
}
static int F_66 ( struct V_5 * V_6 )
{
struct V_69 * V_70 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_9 -> V_94 = F_67 ( V_95 , V_151 ) ;
V_9 -> V_26 = F_67 ( V_43 , V_151 ) ;
V_9 -> V_100 = F_67 ( V_101 , V_151 ) ;
V_9 -> V_11 = F_68 ( V_9 -> V_12 , sizeof( V_1 ) , V_151 ) ;
V_9 -> V_49 = F_68 ( V_9 -> V_50 , sizeof( V_1 ) , V_151 ) ;
if ( ! V_9 -> V_94 || ! V_9 -> V_26 || ! V_9 -> V_100 ||
! V_9 -> V_11 || ! V_9 -> V_49 )
return - V_150 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = F_69 ( 1 , V_151 ) ;
if ( ! V_1 )
return - V_150 ;
V_9 -> V_11 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_70 ;
V_1 -> V_39 = NULL ;
V_1 -> V_155 = F_70 ( V_70 , 6 ) ;
V_1 -> V_72 = V_73 ;
V_1 -> V_42 = F_67 ( V_43 , V_151 ) ;
if ( ! V_1 -> V_42 )
return - V_150 ;
V_1 -> V_156 = F_13 ;
V_1 -> V_63 = 1 ;
V_1 -> V_59 = V_43 ;
V_1 -> V_64 [ 0 ] . V_65 = 0 ;
V_1 -> V_64 [ 0 ] . V_66 = V_43 ;
}
for ( V_4 = 0 ; V_4 < V_9 -> V_50 ; V_4 ++ ) {
V_1 = F_69 ( 1 , V_151 ) ;
if ( ! V_1 )
return - V_150 ;
V_9 -> V_49 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_70 ;
V_1 -> V_39 = NULL ;
V_1 -> V_155 = F_71 ( V_70 , 2 ) ;
V_1 -> V_72 = V_73 ;
V_1 -> V_42 = F_67 ( V_60 , V_151 ) ;
if ( ! V_1 -> V_42 )
return - V_150 ;
V_1 -> V_156 = F_21 ;
V_1 -> V_63 = 1 ;
V_1 -> V_59 = V_60 ;
V_1 -> V_64 [ 0 ] . V_65 = 0 ;
V_1 -> V_64 [ 0 ] . V_66 = V_60 ;
if ( V_9 -> V_61 )
V_1 -> V_62 = 8 ;
else
V_1 -> V_62 = 1 ;
}
if ( V_9 -> V_126 ) {
V_1 = F_69 ( 0 , V_151 ) ;
if ( ! V_1 )
return - V_150 ;
V_9 -> V_123 = V_1 ;
V_1 -> V_42 = F_67 ( V_9 -> V_126 ,
V_151 ) ;
if ( ! V_1 -> V_42 )
return - V_150 ;
}
return 0 ;
}
static void F_72 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_1 = V_9 -> V_123 ;
if ( V_1 ) {
F_63 ( V_1 -> V_42 ) ;
F_73 ( V_1 ) ;
}
if ( V_9 -> V_49 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_50 ; V_4 ++ ) {
V_1 = V_9 -> V_49 [ V_4 ] ;
if ( V_1 ) {
F_63 ( V_1 -> V_42 ) ;
F_73 ( V_1 ) ;
}
}
F_63 ( V_9 -> V_49 ) ;
}
if ( V_9 -> V_11 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = V_9 -> V_11 [ V_4 ] ;
if ( V_1 ) {
F_63 ( V_1 -> V_42 ) ;
F_73 ( V_1 ) ;
}
}
F_63 ( V_9 -> V_11 ) ;
}
F_63 ( V_9 -> V_100 ) ;
F_63 ( V_9 -> V_26 ) ;
F_63 ( V_9 -> V_94 ) ;
}
static int F_74 ( struct V_5 * V_6 ,
unsigned long V_157 )
{
struct V_158 * V_159 = F_75 ( V_6 ) ;
struct V_69 * V_70 = F_10 ( V_6 ) ;
struct V_8 * V_9 ;
struct V_14 * V_15 ;
int V_65 ;
int V_22 ;
V_9 = F_76 ( V_6 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_150 ;
F_77 ( & V_9 -> V_16 , 1 ) ;
F_78 ( V_159 , V_9 ) ;
V_9 -> V_61 = ( V_70 -> V_160 == V_161 ) ;
if ( V_9 -> V_61 ) {
V_9 -> V_12 = V_162 ;
V_9 -> V_50 = V_163 ;
V_9 -> V_126 = 512 ;
} else {
V_9 -> V_12 = V_164 ;
V_9 -> V_50 = V_165 ;
}
V_22 = F_66 ( V_6 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_79 ( V_70 , V_159 -> V_166 -> V_167 . V_168 ,
3 ) ;
if ( V_22 < 0 ) {
F_12 ( V_6 -> V_35 ,
L_10 ) ;
return V_22 ;
}
V_22 = F_80 ( V_6 , & V_70 -> V_6 , V_169 ,
F_60 , 0 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_81 ( V_6 , ( V_9 -> V_61 ) ? 4 : 3 ) ;
if ( V_22 )
return V_22 ;
V_15 = & V_6 -> V_170 [ 0 ] ;
V_6 -> V_40 = V_15 ;
V_15 -> type = V_171 ;
V_15 -> V_172 = V_173 | V_174 | V_175 | V_176 ;
V_15 -> V_177 = V_178 ;
V_15 -> V_179 = V_178 ;
V_15 -> V_180 = 0x00ffffff ;
V_15 -> V_181 = & V_182 ;
V_15 -> V_183 = F_37 ;
V_15 -> V_184 = F_24 ;
V_15 -> V_185 = F_36 ;
V_15 -> V_186 = F_4 ;
V_15 = & V_6 -> V_170 [ 1 ] ;
V_6 -> V_67 = V_15 ;
V_15 -> type = V_187 ;
V_15 -> V_172 = V_188 | V_174 | V_189 ;
V_15 -> V_177 = 4 ;
V_15 -> V_179 = V_15 -> V_177 ;
V_15 -> V_180 = 0x00ff ;
V_15 -> V_181 = & V_190 ;
V_15 -> V_191 = F_41 ;
V_15 -> V_183 = F_39 ;
V_15 -> V_184 = F_43 ;
V_15 -> V_185 = F_44 ;
V_15 -> V_186 = F_17 ;
V_22 = F_82 ( V_15 ) ;
if ( V_22 )
return V_22 ;
V_15 = & V_6 -> V_170 [ 2 ] ;
V_15 -> type = V_192 ;
V_15 -> V_172 = V_173 | V_188 ;
V_15 -> V_177 = 24 ;
V_15 -> V_180 = 1 ;
V_15 -> V_181 = & V_193 ;
V_15 -> V_194 = F_47 ;
V_15 -> V_195 = F_45 ;
if ( V_9 -> V_61 ) {
V_15 = & V_6 -> V_170 [ 3 ] ;
V_15 -> type = V_196 ;
V_15 -> V_172 = V_188 | V_197 ;
V_15 -> V_177 = 8 ;
V_15 -> V_180 = V_9 -> V_126 ;
V_15 -> V_191 = F_57 ;
V_15 -> V_195 = F_58 ;
F_54 ( V_6 , V_15 , V_198 ) ;
}
V_65 = F_59 ( V_6 , 0 ) ;
if ( V_65 < 0 ) {
F_12 ( V_6 -> V_35 ,
L_11 ) ;
return V_65 ;
}
F_83 ( V_6 -> V_35 , L_12 , V_65 ) ;
return 0 ;
}
static void F_84 ( struct V_5 * V_6 )
{
struct V_158 * V_159 = F_75 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_78 ( V_159 , NULL ) ;
if ( ! V_9 )
return;
F_5 ( & V_9 -> V_16 ) ;
F_3 ( V_6 , 1 ) ;
F_16 ( V_6 , 1 ) ;
F_49 ( V_6 , 1 ) ;
F_72 ( V_6 ) ;
F_6 ( & V_9 -> V_16 ) ;
}
static int F_85 ( struct V_158 * V_159 ,
const struct V_199 * V_200 )
{
return F_86 ( V_159 , & V_201 , 0 ) ;
}
