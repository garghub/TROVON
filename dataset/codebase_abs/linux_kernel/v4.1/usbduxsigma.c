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
F_12 ( V_6 -> V_35 , L_1 ,
V_22 ) ;
if ( V_22 == - V_36 )
F_12 ( V_6 -> V_35 ,
L_2 ) ;
V_18 -> V_31 |= V_37 ;
}
}
}
static void F_13 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_38 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_14 * V_15 = V_6 -> V_39 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! V_9 -> V_13 )
return;
switch ( V_1 -> V_40 ) {
case 0 :
memcpy ( V_9 -> V_26 , V_1 -> V_41 , V_42 ) ;
F_7 ( V_6 , V_15 , V_1 ) ;
break;
case - V_43 :
F_14 ( V_6 -> V_35 , L_3 ) ;
F_7 ( V_6 , V_15 , V_1 ) ;
break;
case - V_44 :
case - V_45 :
case - V_46 :
case - V_47 :
V_18 -> V_31 |= V_37 ;
break;
default:
F_12 ( V_6 -> V_35 , L_4 ,
V_1 -> V_40 ) ;
V_18 -> V_31 |= V_37 ;
break;
}
if ( V_18 -> V_31 & V_33 )
F_3 ( V_6 , 0 ) ;
F_15 ( V_6 , V_15 ) ;
}
static void F_16 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 && V_9 -> V_48 )
F_1 ( V_9 -> V_48 , V_9 -> V_49 ) ;
V_9 -> V_50 = 0 ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_16 ) ;
F_16 ( V_6 , V_9 -> V_50 ) ;
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
T_2 * V_51 ;
int V_22 ;
int V_4 ;
V_9 -> V_52 -- ;
if ( V_9 -> V_52 == 0 ) {
V_9 -> V_52 = V_9 -> V_53 ;
if ( V_20 -> V_27 == V_28 &&
V_18 -> V_29 >= V_20 -> V_30 ) {
V_18 -> V_31 |= V_32 ;
return;
}
V_51 = V_1 -> V_41 ;
* V_51 ++ = V_20 -> V_25 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_25 ; V_4 ++ ) {
unsigned int V_54 = F_19 ( V_20 -> V_55 [ V_4 ] ) ;
unsigned short V_21 ;
if ( ! F_20 ( V_15 , & V_21 , 1 ) ) {
F_12 ( V_6 -> V_35 , L_5 ) ;
V_18 -> V_31 |= V_56 ;
return;
}
* V_51 ++ = V_21 ;
* V_51 ++ = V_54 ;
V_15 -> V_57 [ V_54 ] = V_21 ;
}
}
if ( ! ( V_18 -> V_31 & V_33 ) ) {
V_1 -> V_58 = V_59 ;
V_1 -> V_6 = F_10 ( V_6 ) ;
V_1 -> V_40 = 0 ;
if ( V_9 -> V_60 )
V_1 -> V_61 = 8 ;
else
V_1 -> V_61 = 1 ;
V_1 -> V_62 = 1 ;
V_1 -> V_63 [ 0 ] . V_64 = 0 ;
V_1 -> V_63 [ 0 ] . V_65 = V_59 ;
V_1 -> V_63 [ 0 ] . V_40 = 0 ;
V_22 = F_11 ( V_1 , V_34 ) ;
if ( V_22 < 0 ) {
F_12 ( V_6 -> V_35 , L_1 ,
V_22 ) ;
if ( V_22 == - V_36 )
F_12 ( V_6 -> V_35 ,
L_2 ) ;
V_18 -> V_31 |= V_37 ;
}
}
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_38 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_14 * V_15 = V_6 -> V_66 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! V_9 -> V_50 )
return;
switch ( V_1 -> V_40 ) {
case 0 :
F_18 ( V_6 , V_15 , V_1 ) ;
break;
case - V_44 :
case - V_45 :
case - V_46 :
case - V_47 :
V_18 -> V_31 |= V_37 ;
break;
default:
F_12 ( V_6 -> V_35 , L_4 ,
V_1 -> V_40 ) ;
V_18 -> V_31 |= V_37 ;
break;
}
if ( V_18 -> V_31 & V_33 )
F_16 ( V_6 , 0 ) ;
F_15 ( V_6 , V_15 ) ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_1 * * V_2 , int V_3 ,
int V_67 )
{
struct V_68 * V_69 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_22 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_1 = V_2 [ V_4 ] ;
if ( V_67 )
V_1 -> V_61 = V_9 -> V_70 ;
V_1 -> V_38 = V_6 ;
V_1 -> V_6 = V_69 ;
V_1 -> V_40 = 0 ;
V_1 -> V_71 = V_72 ;
V_22 = F_11 ( V_1 , V_34 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_23 ( int V_73 )
{
if ( V_73 <= 2 )
return 2 ;
if ( V_73 <= 8 )
return 4 ;
return 8 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_19 * V_20 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_60 = V_9 -> V_60 ;
int V_61 = F_23 ( V_20 -> V_25 ) ;
int V_74 = 0 ;
V_74 |= F_25 ( & V_20 -> V_75 , V_76 | V_77 ) ;
V_74 |= F_25 ( & V_20 -> V_78 , V_79 ) ;
V_74 |= F_25 ( & V_20 -> V_80 , V_76 ) ;
V_74 |= F_25 ( & V_20 -> V_81 , V_28 ) ;
V_74 |= F_25 ( & V_20 -> V_27 , V_28 | V_82 ) ;
if ( V_74 )
return 1 ;
V_74 |= F_26 ( V_20 -> V_75 ) ;
V_74 |= F_26 ( V_20 -> V_27 ) ;
if ( V_74 )
return 2 ;
V_74 |= F_27 ( & V_20 -> V_83 , 0 ) ;
if ( V_20 -> V_78 == V_84 )
V_74 |= F_27 ( & V_20 -> V_85 , 0 ) ;
if ( V_20 -> V_78 == V_79 ) {
unsigned int V_86 ;
if ( V_60 ) {
V_74 |= F_28 ( & V_20 ->
V_85 ,
( 1000000 / 8 *
V_61 ) ) ;
V_86 = ( V_20 -> V_85 / 125000 ) * 125000 ;
} else {
V_74 |= F_28 ( & V_20 ->
V_85 ,
1000000 ) ;
V_86 = ( V_20 -> V_85 / 1000000 ) * 1000000 ;
}
V_74 |= F_27 ( & V_20 -> V_85 , V_86 ) ;
}
V_74 |= F_27 ( & V_20 -> V_87 ,
V_20 -> V_25 ) ;
if ( V_20 -> V_27 == V_28 )
V_74 |= F_28 ( & V_20 -> V_30 , 1 ) ;
else
V_74 |= F_27 ( & V_20 -> V_30 , 0 ) ;
if ( V_74 )
return 3 ;
if ( V_60 ) {
V_9 -> V_70 = V_61 ;
V_9 -> V_24 = V_20 -> V_85 / ( 125000 * V_61 ) ;
} else {
V_9 -> V_70 = 1 ;
V_9 -> V_24 = V_20 -> V_85 / 1000000 ;
}
if ( V_9 -> V_24 < 1 )
V_74 |= - V_88 ;
if ( V_74 )
return 4 ;
return 0 ;
}
static void F_29 ( unsigned int V_54 ,
T_2 * V_89 ,
T_2 * V_90 )
{
if ( V_54 < 8 )
( * V_89 ) = ( * V_89 ) | ( 1 << V_54 ) ;
else if ( V_54 < 16 )
( * V_90 ) = ( * V_90 ) | ( 1 << ( V_54 - 8 ) ) ;
}
static int F_30 ( struct V_5 * V_6 , int V_91 )
{
struct V_68 * V_69 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_92 ;
V_9 -> V_93 [ 0 ] = V_91 ;
return F_31 ( V_69 , F_32 ( V_69 , 1 ) ,
V_9 -> V_93 , V_94 ,
& V_92 , V_95 ) ;
}
static int F_33 ( struct V_5 * V_6 , int V_96 )
{
struct V_68 * V_69 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_97 ;
int V_22 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_98 ; V_4 ++ ) {
V_22 = F_31 ( V_69 , F_34 ( V_69 , 8 ) ,
V_9 -> V_99 , V_100 ,
& V_97 , V_95 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_9 -> V_99 [ 0 ] == V_96 )
return 0 ;
}
return - V_101 ;
}
static int F_35 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_102 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_22 ;
if ( V_102 != V_20 -> V_83 )
return - V_88 ;
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
V_15 -> V_18 -> V_103 = NULL ;
}
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
static int F_36 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
unsigned int V_104 = V_20 -> V_25 ;
T_2 V_89 = 0 ;
T_2 V_90 = 0 ;
T_2 V_105 = 0 ;
int V_22 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
for ( V_4 = 0 ; V_4 < V_104 ; V_4 ++ ) {
unsigned int V_54 = F_19 ( V_20 -> V_55 [ V_4 ] ) ;
F_29 ( V_54 , & V_89 , & V_90 ) ;
}
V_9 -> V_93 [ 1 ] = V_104 ;
V_9 -> V_93 [ 2 ] = 0x12 ;
V_9 -> V_93 [ 3 ] = 0x03 ;
V_9 -> V_93 [ 4 ] = 0x00 ;
V_9 -> V_93 [ 5 ] = V_89 ;
V_9 -> V_93 [ 6 ] = V_90 ;
V_9 -> V_93 [ 7 ] = V_105 ;
V_22 = F_30 ( V_6 , V_106 ) ;
if ( V_22 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_9 -> V_23 = V_9 -> V_24 ;
if ( V_20 -> V_75 == V_76 ) {
V_9 -> V_13 = 1 ;
V_22 = F_22 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_22 < 0 ) {
V_9 -> V_13 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_15 -> V_18 -> V_103 = NULL ;
} else {
V_15 -> V_18 -> V_103 = F_35 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_107 * V_108 ,
unsigned int * V_109 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_54 = F_19 ( V_108 -> V_110 ) ;
T_2 V_89 = 0 ;
T_2 V_90 = 0 ;
T_2 V_105 = 0 ;
int V_22 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_111 ;
}
F_29 ( V_54 , & V_89 , & V_90 ) ;
V_9 -> V_93 [ 1 ] = 0x16 ;
V_9 -> V_93 [ 2 ] = 0x80 ;
V_9 -> V_93 [ 3 ] = 0x00 ;
V_9 -> V_93 [ 4 ] = V_89 ;
V_9 -> V_93 [ 5 ] = V_90 ;
V_9 -> V_93 [ 6 ] = V_105 ;
V_22 = F_30 ( V_6 , V_112 ) ;
if ( V_22 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
for ( V_4 = 0 ; V_4 < V_108 -> V_113 ; V_4 ++ ) {
T_1 V_21 ;
V_22 = F_33 ( V_6 , V_112 ) ;
if ( V_22 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_21 = F_8 ( F_38 ( ( V_114
* ) ( V_9 -> V_99 + 1 ) ) ) ;
V_21 &= 0x00ffffff ;
V_21 ^= 0x00800000 ;
V_109 [ V_4 ] = V_21 ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_108 -> V_113 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_107 * V_108 ,
unsigned int * V_109 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_22 ;
F_5 ( & V_9 -> V_16 ) ;
V_22 = F_40 ( V_6 , V_15 , V_108 , V_109 ) ;
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_107 * V_108 ,
unsigned int * V_109 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_54 = F_19 ( V_108 -> V_110 ) ;
int V_22 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_50 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_111 ;
}
for ( V_4 = 0 ; V_4 < V_108 -> V_113 ; V_4 ++ ) {
V_9 -> V_93 [ 1 ] = 1 ;
V_9 -> V_93 [ 2 ] = V_109 [ V_4 ] ;
V_9 -> V_93 [ 3 ] = V_54 ;
V_22 = F_30 ( V_6 , V_115 ) ;
if ( V_22 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_15 -> V_57 [ V_54 ] = V_109 [ V_4 ] ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_108 -> V_113 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_102 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_22 ;
if ( V_102 != V_20 -> V_83 )
return - V_88 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_50 ) {
V_9 -> V_50 = 1 ;
V_22 = F_22 ( V_6 , V_9 -> V_48 ,
V_9 -> V_49 , 0 ) ;
if ( V_22 < 0 ) {
V_9 -> V_50 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_15 -> V_18 -> V_103 = NULL ;
}
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_19 * V_20 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_74 = 0 ;
int V_60 ;
unsigned int V_116 ;
V_60 = 0 ;
V_74 |= F_25 ( & V_20 -> V_75 , V_76 | V_77 ) ;
if ( V_60 ) {
V_116 = V_84 ;
} else {
V_116 = V_79 ;
}
V_74 |= F_25 ( & V_20 -> V_78 , V_116 ) ;
V_74 |= F_25 ( & V_20 -> V_80 , V_76 ) ;
V_74 |= F_25 ( & V_20 -> V_81 , V_28 ) ;
V_74 |= F_25 ( & V_20 -> V_27 , V_28 | V_82 ) ;
if ( V_74 ) {
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
V_74 |= F_26 ( V_20 -> V_75 ) ;
V_74 |= F_26 ( V_20 -> V_27 ) ;
if ( V_74 )
return 2 ;
V_74 |= F_27 ( & V_20 -> V_83 , 0 ) ;
if ( V_20 -> V_78 == V_84 )
V_74 |= F_27 ( & V_20 -> V_85 , 0 ) ;
if ( V_20 -> V_78 == V_79 ) {
V_74 |= F_28 ( & V_20 -> V_85 ,
1000000 ) ;
}
if ( V_20 -> V_80 == V_79 )
V_74 |= F_28 ( & V_20 -> V_117 , 125000 ) ;
V_74 |= F_27 ( & V_20 -> V_87 ,
V_20 -> V_25 ) ;
if ( V_20 -> V_27 == V_28 )
V_74 |= F_28 ( & V_20 -> V_30 , 1 ) ;
else
V_74 |= F_27 ( & V_20 -> V_30 , 0 ) ;
if ( V_74 )
return 3 ;
if ( V_60 ) {
V_9 -> V_53 = V_20 -> V_117 / 125000 ;
} else {
V_9 -> V_53 = V_20 -> V_85 / 1000000 ;
}
if ( V_9 -> V_53 < 1 )
V_74 |= - V_88 ;
if ( V_74 )
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
V_9 -> V_52 = V_9 -> V_53 ;
if ( V_20 -> V_75 == V_76 ) {
V_9 -> V_50 = 1 ;
V_22 = F_22 ( V_6 , V_9 -> V_48 ,
V_9 -> V_49 , 0 ) ;
if ( V_22 < 0 ) {
V_9 -> V_50 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_15 -> V_18 -> V_103 = NULL ;
} else {
V_15 -> V_18 -> V_103 = F_42 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_107 * V_108 ,
unsigned int * V_109 )
{
int V_22 ;
V_22 = F_46 ( V_6 , V_15 , V_108 , V_109 , 0 ) ;
if ( V_22 )
return V_22 ;
return V_108 -> V_113 ;
}
static int F_47 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_107 * V_108 ,
unsigned int * V_109 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_22 ;
F_5 ( & V_9 -> V_16 ) ;
F_48 ( V_15 , V_109 ) ;
V_9 -> V_93 [ 1 ] = V_15 -> V_118 & 0xff ;
V_9 -> V_93 [ 4 ] = V_15 -> V_119 & 0xff ;
V_9 -> V_93 [ 2 ] = ( V_15 -> V_118 >> 8 ) & 0xff ;
V_9 -> V_93 [ 5 ] = ( V_15 -> V_119 >> 8 ) & 0xff ;
V_9 -> V_93 [ 3 ] = ( V_15 -> V_118 >> 16 ) & 0xff ;
V_9 -> V_93 [ 6 ] = ( V_15 -> V_119 >> 16 ) & 0xff ;
V_22 = F_30 ( V_6 , V_120 ) ;
if ( V_22 < 0 )
goto V_121;
V_22 = F_33 ( V_6 , V_120 ) ;
if ( V_22 < 0 )
goto V_121;
V_15 -> V_119 = V_9 -> V_99 [ 1 ] |
( V_9 -> V_99 [ 2 ] << 8 ) |
( V_9 -> V_99 [ 3 ] << 16 ) ;
V_109 [ 1 ] = V_15 -> V_119 ;
V_22 = V_108 -> V_113 ;
V_121:
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
static void F_49 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 ) {
if ( V_9 -> V_122 )
F_2 ( V_9 -> V_122 ) ;
}
V_9 -> V_123 = 0 ;
}
static int F_50 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_49 ( V_6 , V_9 -> V_123 ) ;
return F_30 ( V_6 , V_124 ) ;
}
static void F_51 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_38 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_22 ;
switch ( V_1 -> V_40 ) {
case 0 :
break;
case - V_44 :
case - V_45 :
case - V_46 :
case - V_47 :
if ( V_9 -> V_123 )
F_49 ( V_6 , 0 ) ;
return;
default:
if ( V_9 -> V_123 ) {
F_12 ( V_6 -> V_35 , L_4 ,
V_1 -> V_40 ) ;
F_49 ( V_6 , 0 ) ;
}
return;
}
if ( ! V_9 -> V_123 )
return;
V_1 -> V_58 = V_9 -> V_125 ;
V_1 -> V_6 = F_10 ( V_6 ) ;
V_1 -> V_40 = 0 ;
V_22 = F_11 ( V_1 , V_34 ) ;
if ( V_22 < 0 ) {
F_12 ( V_6 -> V_35 , L_1 , V_22 ) ;
if ( V_22 == - V_36 )
F_12 ( V_6 -> V_35 ,
L_2 ) ;
F_49 ( V_6 , 0 ) ;
}
}
static int F_52 ( struct V_5 * V_6 )
{
struct V_68 * V_69 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 = V_9 -> V_122 ;
F_53 ( V_1 , V_69 , F_32 ( V_69 , 4 ) ,
V_1 -> V_41 , V_9 -> V_125 ,
F_51 , V_6 ) ;
return F_11 ( V_1 , V_34 ) ;
}
static int F_54 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_126 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_127 = 255 ;
if ( V_126 < V_128 )
return - V_129 ;
V_127 = ( V_126 / ( 6 * 512 * 1000 / 33 ) ) - 6 ;
if ( V_127 > 255 )
return - V_129 ;
V_9 -> V_130 = V_127 ;
V_9 -> V_131 = V_126 ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_22 ;
if ( V_9 -> V_123 )
return 0 ;
V_9 -> V_93 [ 1 ] = V_9 -> V_130 ;
V_22 = F_30 ( V_6 , V_132 ) ;
if ( V_22 < 0 )
return V_22 ;
memset ( V_9 -> V_122 -> V_41 , 0 , V_9 -> V_125 ) ;
V_9 -> V_123 = 1 ;
V_22 = F_52 ( V_6 ) ;
if ( V_22 < 0 ) {
V_9 -> V_123 = 0 ;
return V_22 ;
}
return 0 ;
}
static void F_56 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_54 ,
unsigned int V_133 ,
unsigned int V_134 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
char V_135 = ( 1 << V_54 ) ;
char V_136 = ( 16 << V_54 ) ;
char * V_137 = ( char * ) ( V_9 -> V_122 -> V_41 ) ;
int V_138 = V_9 -> V_125 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_138 ; V_4 ++ ) {
char V_139 = * V_137 ;
V_139 &= ~ V_135 ;
if ( V_4 < V_133 )
V_139 |= V_135 ;
if ( ! V_134 )
V_139 &= ~ V_136 ;
else
V_139 |= V_136 ;
* V_137 ++ = V_139 ;
}
}
static int F_57 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_107 * V_108 ,
unsigned int * V_109 )
{
unsigned int V_54 = F_19 ( V_108 -> V_110 ) ;
if ( V_108 -> V_113 != 1 )
return - V_88 ;
F_56 ( V_6 , V_15 , V_54 , V_109 [ 0 ] , 0 ) ;
return V_108 -> V_113 ;
}
static int F_58 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_107 * V_108 ,
unsigned int * V_109 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_54 = F_19 ( V_108 -> V_110 ) ;
switch ( V_109 [ 0 ] ) {
case V_140 :
if ( V_109 [ 1 ] != 0 )
return - V_88 ;
return F_55 ( V_6 , V_15 ) ;
case V_141 :
return F_50 ( V_6 , V_15 ) ;
case V_142 :
V_109 [ 1 ] = V_9 -> V_123 ;
return 0 ;
case V_143 :
return F_54 ( V_6 , V_15 , V_109 [ 1 ] ) ;
case V_144 :
V_109 [ 1 ] = V_9 -> V_131 ;
return 0 ;
case V_145 :
F_56 ( V_6 , V_15 , V_54 , V_109 [ 1 ] , ( V_109 [ 2 ] != 0 ) ) ;
return 0 ;
case V_146 :
return - V_88 ;
}
return - V_88 ;
}
static int F_59 ( struct V_5 * V_6 , int V_54 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_105 ;
T_1 V_21 ;
int V_22 ;
switch ( V_54 ) {
default:
case 0 :
V_105 = 0 ;
break;
case 1 :
V_105 = 1 ;
break;
case 2 :
V_105 = 4 ;
break;
case 3 :
V_105 = 8 ;
break;
case 4 :
V_105 = 16 ;
break;
case 5 :
V_105 = 32 ;
break;
}
V_9 -> V_93 [ 1 ] = 0x12 ;
V_9 -> V_93 [ 2 ] = 0x80 ;
V_9 -> V_93 [ 3 ] = 0x00 ;
V_9 -> V_93 [ 4 ] = 0 ;
V_9 -> V_93 [ 5 ] = 0 ;
V_9 -> V_93 [ 6 ] = V_105 ;
V_22 = F_30 ( V_6 , V_112 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_33 ( V_6 , V_112 ) ;
if ( V_22 < 0 )
return V_22 ;
V_21 = F_8 ( F_38 ( ( V_114 * ) ( V_9 -> V_99 + 1 ) ) ) ;
V_21 &= 0x00ffffff ;
V_21 ^= 0x00800000 ;
return ( int ) V_21 ;
}
static int F_60 ( struct V_5 * V_6 ,
const T_3 * V_109 , T_4 V_147 ,
unsigned long V_38 )
{
struct V_68 * V_69 = F_10 ( V_6 ) ;
T_2 * V_137 ;
T_2 * V_86 ;
int V_22 ;
if ( ! V_109 )
return 0 ;
if ( V_147 > V_148 ) {
F_12 ( V_6 -> V_35 , L_6 ) ;
return - V_149 ;
}
V_137 = F_61 ( V_109 , V_147 , V_150 ) ;
if ( ! V_137 )
return - V_149 ;
V_86 = F_62 ( 1 , V_150 ) ;
if ( ! V_86 ) {
F_63 ( V_137 ) ;
return - V_149 ;
}
* V_86 = 1 ;
V_22 = F_64 ( V_69 , F_65 ( V_69 , 0 ) ,
V_151 ,
V_152 ,
V_153 , 0x0000 ,
V_86 , 1 ,
V_95 ) ;
if ( V_22 < 0 ) {
F_12 ( V_6 -> V_35 , L_7 ) ;
goto V_121;
}
V_22 = F_64 ( V_69 , F_65 ( V_69 , 0 ) ,
V_151 ,
V_152 ,
0 , 0x0000 ,
V_137 , V_147 ,
V_95 ) ;
if ( V_22 < 0 ) {
F_12 ( V_6 -> V_35 , L_8 ) ;
goto V_121;
}
* V_86 = 0 ;
V_22 = F_64 ( V_69 , F_65 ( V_69 , 0 ) ,
V_151 ,
V_152 ,
V_153 , 0x0000 ,
V_86 , 1 ,
V_95 ) ;
if ( V_22 < 0 )
F_12 ( V_6 -> V_35 , L_9 ) ;
V_121:
F_63 ( V_86 ) ;
F_63 ( V_137 ) ;
return V_22 ;
}
static int F_66 ( struct V_5 * V_6 )
{
struct V_68 * V_69 = F_10 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_9 -> V_93 = F_67 ( V_94 , V_150 ) ;
V_9 -> V_26 = F_67 ( V_42 , V_150 ) ;
V_9 -> V_99 = F_67 ( V_100 , V_150 ) ;
V_9 -> V_11 = F_68 ( V_9 -> V_12 , sizeof( V_1 ) , V_150 ) ;
V_9 -> V_48 = F_68 ( V_9 -> V_49 , sizeof( V_1 ) , V_150 ) ;
if ( ! V_9 -> V_93 || ! V_9 -> V_26 || ! V_9 -> V_99 ||
! V_9 -> V_11 || ! V_9 -> V_48 )
return - V_149 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = F_69 ( 1 , V_150 ) ;
if ( ! V_1 )
return - V_149 ;
V_9 -> V_11 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_69 ;
V_1 -> V_38 = NULL ;
V_1 -> V_154 = F_70 ( V_69 , 6 ) ;
V_1 -> V_71 = V_72 ;
V_1 -> V_41 = F_67 ( V_42 , V_150 ) ;
if ( ! V_1 -> V_41 )
return - V_149 ;
V_1 -> V_155 = F_13 ;
V_1 -> V_62 = 1 ;
V_1 -> V_58 = V_42 ;
V_1 -> V_63 [ 0 ] . V_64 = 0 ;
V_1 -> V_63 [ 0 ] . V_65 = V_42 ;
}
for ( V_4 = 0 ; V_4 < V_9 -> V_49 ; V_4 ++ ) {
V_1 = F_69 ( 1 , V_150 ) ;
if ( ! V_1 )
return - V_149 ;
V_9 -> V_48 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_69 ;
V_1 -> V_38 = NULL ;
V_1 -> V_154 = F_71 ( V_69 , 2 ) ;
V_1 -> V_71 = V_72 ;
V_1 -> V_41 = F_67 ( V_59 , V_150 ) ;
if ( ! V_1 -> V_41 )
return - V_149 ;
V_1 -> V_155 = F_21 ;
V_1 -> V_62 = 1 ;
V_1 -> V_58 = V_59 ;
V_1 -> V_63 [ 0 ] . V_64 = 0 ;
V_1 -> V_63 [ 0 ] . V_65 = V_59 ;
if ( V_9 -> V_60 )
V_1 -> V_61 = 8 ;
else
V_1 -> V_61 = 1 ;
}
if ( V_9 -> V_125 ) {
V_1 = F_69 ( 0 , V_150 ) ;
if ( ! V_1 )
return - V_149 ;
V_9 -> V_122 = V_1 ;
V_1 -> V_41 = F_67 ( V_9 -> V_125 ,
V_150 ) ;
if ( ! V_1 -> V_41 )
return - V_149 ;
}
return 0 ;
}
static void F_72 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_1 = V_9 -> V_122 ;
if ( V_1 ) {
F_63 ( V_1 -> V_41 ) ;
F_73 ( V_1 ) ;
}
if ( V_9 -> V_48 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_49 ; V_4 ++ ) {
V_1 = V_9 -> V_48 [ V_4 ] ;
if ( V_1 ) {
F_63 ( V_1 -> V_41 ) ;
F_73 ( V_1 ) ;
}
}
F_63 ( V_9 -> V_48 ) ;
}
if ( V_9 -> V_11 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = V_9 -> V_11 [ V_4 ] ;
if ( V_1 ) {
F_63 ( V_1 -> V_41 ) ;
F_73 ( V_1 ) ;
}
}
F_63 ( V_9 -> V_11 ) ;
}
F_63 ( V_9 -> V_99 ) ;
F_63 ( V_9 -> V_26 ) ;
F_63 ( V_9 -> V_93 ) ;
}
static int F_74 ( struct V_5 * V_6 ,
unsigned long V_156 )
{
struct V_157 * V_158 = F_75 ( V_6 ) ;
struct V_68 * V_69 = F_10 ( V_6 ) ;
struct V_8 * V_9 ;
struct V_14 * V_15 ;
int V_64 ;
int V_22 ;
V_9 = F_76 ( V_6 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_149 ;
F_77 ( & V_9 -> V_16 , 1 ) ;
F_78 ( V_158 , V_9 ) ;
V_9 -> V_60 = ( V_69 -> V_159 == V_160 ) ;
if ( V_9 -> V_60 ) {
V_9 -> V_12 = V_161 ;
V_9 -> V_49 = V_162 ;
V_9 -> V_125 = 512 ;
} else {
V_9 -> V_12 = V_163 ;
V_9 -> V_49 = V_164 ;
}
V_22 = F_66 ( V_6 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_79 ( V_69 , V_158 -> V_165 -> V_166 . V_167 ,
3 ) ;
if ( V_22 < 0 ) {
F_12 ( V_6 -> V_35 ,
L_10 ) ;
return V_22 ;
}
V_22 = F_80 ( V_6 , & V_69 -> V_6 , V_168 ,
F_60 , 0 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_81 ( V_6 , ( V_9 -> V_60 ) ? 4 : 3 ) ;
if ( V_22 )
return V_22 ;
V_15 = & V_6 -> V_169 [ 0 ] ;
V_6 -> V_39 = V_15 ;
V_15 -> type = V_170 ;
V_15 -> V_171 = V_172 | V_173 | V_174 | V_175 ;
V_15 -> V_176 = V_177 ;
V_15 -> V_178 = V_177 ;
V_15 -> V_179 = 0x00ffffff ;
V_15 -> V_180 = & V_181 ;
V_15 -> V_182 = F_37 ;
V_15 -> V_183 = F_24 ;
V_15 -> V_184 = F_36 ;
V_15 -> V_185 = F_4 ;
V_15 = & V_6 -> V_169 [ 1 ] ;
V_6 -> V_66 = V_15 ;
V_15 -> type = V_186 ;
V_15 -> V_171 = V_187 | V_173 | V_188 ;
V_15 -> V_176 = 4 ;
V_15 -> V_178 = V_15 -> V_176 ;
V_15 -> V_179 = 0x00ff ;
V_15 -> V_180 = & V_189 ;
V_15 -> V_190 = F_41 ;
V_15 -> V_182 = F_39 ;
V_15 -> V_183 = F_43 ;
V_15 -> V_184 = F_44 ;
V_15 -> V_185 = F_17 ;
V_22 = F_82 ( V_15 ) ;
if ( V_22 )
return V_22 ;
V_15 = & V_6 -> V_169 [ 2 ] ;
V_15 -> type = V_191 ;
V_15 -> V_171 = V_172 | V_187 ;
V_15 -> V_176 = 24 ;
V_15 -> V_179 = 1 ;
V_15 -> V_180 = & V_192 ;
V_15 -> V_193 = F_47 ;
V_15 -> V_194 = F_45 ;
if ( V_9 -> V_60 ) {
V_15 = & V_6 -> V_169 [ 3 ] ;
V_15 -> type = V_195 ;
V_15 -> V_171 = V_187 | V_196 ;
V_15 -> V_176 = 8 ;
V_15 -> V_179 = V_9 -> V_125 ;
V_15 -> V_190 = F_57 ;
V_15 -> V_194 = F_58 ;
F_54 ( V_6 , V_15 , V_197 ) ;
}
V_64 = F_59 ( V_6 , 0 ) ;
if ( V_64 < 0 ) {
F_12 ( V_6 -> V_35 ,
L_11 ) ;
return V_64 ;
}
F_83 ( V_6 -> V_35 , L_12 , V_64 ) ;
return 0 ;
}
static void F_84 ( struct V_5 * V_6 )
{
struct V_157 * V_158 = F_75 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_78 ( V_158 , NULL ) ;
if ( ! V_9 )
return;
F_5 ( & V_9 -> V_16 ) ;
F_3 ( V_6 , 1 ) ;
F_16 ( V_6 , 1 ) ;
F_49 ( V_6 , 1 ) ;
F_72 ( V_6 ) ;
F_6 ( & V_9 -> V_16 ) ;
}
static int F_85 ( struct V_157 * V_158 ,
const struct V_198 * V_199 )
{
return F_86 ( V_158 , & V_200 , 0 ) ;
}
