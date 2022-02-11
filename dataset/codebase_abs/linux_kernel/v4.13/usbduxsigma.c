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
if ( ( V_1 -> V_23 > 0 ) && ( V_1 -> V_24 != - V_25 ) ) {
V_9 -> V_26 -- ;
if ( V_9 -> V_26 == 0 ) {
V_9 -> V_26 = V_9 -> V_27 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_28 ; V_4 ++ ) {
V_21 = F_8 ( V_9 -> V_29 [ V_4 + 1 ] ) ;
V_21 &= 0x00ffffff ;
V_21 = F_9 ( V_15 , V_21 ) ;
if ( ! F_10 ( V_15 , & V_21 , 1 ) )
return;
}
if ( V_20 -> V_30 == V_31 &&
V_18 -> V_32 >= V_20 -> V_33 )
V_18 -> V_34 |= V_35 ;
}
}
if ( ! ( V_18 -> V_34 & V_36 ) ) {
V_1 -> V_6 = F_11 ( V_6 ) ;
V_22 = F_12 ( V_1 , V_37 ) ;
if ( V_22 < 0 ) {
F_13 ( V_6 -> V_38 , L_1 ,
V_22 ) ;
if ( V_22 == - V_39 )
F_13 ( V_6 -> V_38 ,
L_2 ) ;
V_18 -> V_34 |= V_40 ;
}
}
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_41 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_14 * V_15 = V_6 -> V_42 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! V_9 -> V_13 )
return;
switch ( V_1 -> V_24 ) {
case 0 :
memcpy ( V_9 -> V_29 , V_1 -> V_43 , V_44 ) ;
F_7 ( V_6 , V_15 , V_1 ) ;
break;
case - V_45 :
F_15 ( V_6 -> V_38 , L_3 ) ;
F_7 ( V_6 , V_15 , V_1 ) ;
break;
case - V_46 :
case - V_47 :
case - V_48 :
case - V_49 :
V_18 -> V_34 |= V_40 ;
break;
default:
F_13 ( V_6 -> V_38 , L_4 ,
V_1 -> V_24 ) ;
V_18 -> V_34 |= V_40 ;
break;
}
if ( V_18 -> V_34 & V_36 )
F_3 ( V_6 , 0 ) ;
F_16 ( V_6 , V_15 ) ;
}
static void F_17 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 && V_9 -> V_50 )
F_1 ( V_9 -> V_50 , V_9 -> V_51 ) ;
V_9 -> V_52 = 0 ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_16 ) ;
F_17 ( V_6 , V_9 -> V_52 ) ;
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static void F_19 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_1 * V_1 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
T_2 * V_53 ;
int V_22 ;
int V_4 ;
V_9 -> V_54 -- ;
if ( V_9 -> V_54 == 0 ) {
V_9 -> V_54 = V_9 -> V_55 ;
if ( V_20 -> V_30 == V_31 &&
V_18 -> V_32 >= V_20 -> V_33 ) {
V_18 -> V_34 |= V_35 ;
return;
}
V_53 = V_1 -> V_43 ;
* V_53 ++ = V_20 -> V_28 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_28 ; V_4 ++ ) {
unsigned int V_56 = F_20 ( V_20 -> V_57 [ V_4 ] ) ;
unsigned short V_21 ;
if ( ! F_21 ( V_15 , & V_21 , 1 ) ) {
F_13 ( V_6 -> V_38 , L_5 ) ;
V_18 -> V_34 |= V_58 ;
return;
}
* V_53 ++ = V_21 ;
* V_53 ++ = V_56 ;
V_15 -> V_59 [ V_56 ] = V_21 ;
}
}
if ( ! ( V_18 -> V_34 & V_36 ) ) {
V_1 -> V_60 = V_61 ;
V_1 -> V_6 = F_11 ( V_6 ) ;
V_1 -> V_24 = 0 ;
V_1 -> V_62 = 1 ;
V_1 -> V_63 = 1 ;
V_1 -> V_64 [ 0 ] . V_65 = 0 ;
V_1 -> V_64 [ 0 ] . V_66 = V_61 ;
V_1 -> V_64 [ 0 ] . V_24 = 0 ;
V_22 = F_12 ( V_1 , V_37 ) ;
if ( V_22 < 0 ) {
F_13 ( V_6 -> V_38 , L_1 ,
V_22 ) ;
if ( V_22 == - V_39 )
F_13 ( V_6 -> V_38 ,
L_2 ) ;
V_18 -> V_34 |= V_40 ;
}
}
}
static void F_22 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_41 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_14 * V_15 = V_6 -> V_67 ;
struct V_17 * V_18 = V_15 -> V_18 ;
if ( ! V_9 -> V_52 )
return;
switch ( V_1 -> V_24 ) {
case 0 :
F_19 ( V_6 , V_15 , V_1 ) ;
break;
case - V_46 :
case - V_47 :
case - V_48 :
case - V_49 :
V_18 -> V_34 |= V_40 ;
break;
default:
F_13 ( V_6 -> V_38 , L_4 ,
V_1 -> V_24 ) ;
V_18 -> V_34 |= V_40 ;
break;
}
if ( V_18 -> V_34 & V_36 )
F_17 ( V_6 , 0 ) ;
F_16 ( V_6 , V_15 ) ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_1 * * V_2 , int V_3 ,
int V_68 )
{
struct V_69 * V_70 = F_11 ( V_6 ) ;
struct V_1 * V_1 ;
int V_22 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_1 = V_2 [ V_4 ] ;
if ( V_68 )
V_1 -> V_62 = 1 ;
V_1 -> V_41 = V_6 ;
V_1 -> V_6 = V_70 ;
V_1 -> V_24 = 0 ;
V_1 -> V_71 = V_72 ;
V_22 = F_12 ( V_1 , V_37 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_24 ( int V_73 )
{
if ( V_73 <= 2 )
return 2 ;
if ( V_73 <= 8 )
return 4 ;
return 8 ;
}
static int F_25 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_19 * V_20 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_74 = V_9 -> V_74 ;
int V_62 = F_24 ( V_20 -> V_28 ) ;
unsigned int V_75 ;
int V_76 = 0 ;
V_76 |= F_26 ( & V_20 -> V_77 , V_78 | V_79 ) ;
V_76 |= F_26 ( & V_20 -> V_80 , V_81 ) ;
V_76 |= F_26 ( & V_20 -> V_82 , V_78 ) ;
V_76 |= F_26 ( & V_20 -> V_83 , V_31 ) ;
V_76 |= F_26 ( & V_20 -> V_30 , V_31 | V_84 ) ;
if ( V_76 )
return 1 ;
V_76 |= F_27 ( V_20 -> V_77 ) ;
V_76 |= F_27 ( V_20 -> V_30 ) ;
if ( V_76 )
return 2 ;
V_76 |= F_28 ( & V_20 -> V_85 , 0 ) ;
if ( V_74 ) {
V_76 |= F_29 ( & V_20 -> V_86 ,
( 125000 * V_62 ) ) ;
} else {
V_76 |= F_29 ( & V_20 -> V_86 ,
1000000 ) ;
}
V_76 |= F_28 ( & V_20 -> V_87 ,
V_20 -> V_28 ) ;
if ( V_20 -> V_30 == V_31 )
V_76 |= F_29 ( & V_20 -> V_33 , 1 ) ;
else
V_76 |= F_28 ( & V_20 -> V_33 , 0 ) ;
if ( V_76 )
return 3 ;
V_75 = F_30 ( V_20 -> V_86 , V_74 ? 125000 : 1000000 ) ;
V_76 |= F_28 ( & V_20 -> V_86 , V_75 ) ;
if ( V_76 )
return 4 ;
return 0 ;
}
static void F_31 ( unsigned int V_56 ,
T_2 * V_88 , T_2 * V_89 )
{
if ( V_56 < 8 )
( * V_88 ) = ( * V_88 ) | ( 1 << V_56 ) ;
else if ( V_56 < 16 )
( * V_89 ) = ( * V_89 ) | ( 1 << ( V_56 - 8 ) ) ;
}
static int F_32 ( struct V_5 * V_6 , int V_90 )
{
struct V_69 * V_70 = F_11 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_91 ;
V_9 -> V_92 [ 0 ] = V_90 ;
return F_33 ( V_70 , F_34 ( V_70 , 1 ) ,
V_9 -> V_92 , V_93 ,
& V_91 , V_94 ) ;
}
static int F_35 ( struct V_5 * V_6 , int V_95 )
{
struct V_69 * V_70 = F_11 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_96 ;
int V_22 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_97 ; V_4 ++ ) {
V_22 = F_33 ( V_70 , F_36 ( V_70 , 8 ) ,
V_9 -> V_98 , V_99 ,
& V_96 , V_94 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_9 -> V_98 [ 0 ] == V_95 )
return 0 ;
}
return - V_100 ;
}
static int F_37 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_101 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_22 ;
if ( V_101 != V_20 -> V_85 )
return - V_102 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_13 ) {
V_9 -> V_13 = 1 ;
V_22 = F_23 ( V_6 , V_9 -> V_11 ,
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
static int F_38 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
unsigned int V_104 = V_20 -> V_28 ;
T_2 V_88 = 0 ;
T_2 V_89 = 0 ;
T_2 V_105 = 0 ;
int V_22 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_74 ) {
unsigned int V_62 = F_24 ( V_104 ) ;
V_9 -> V_106 = V_62 ;
V_9 -> V_27 = V_20 -> V_86 / ( 125000 * V_62 ) ;
} else {
V_9 -> V_106 = 1 ;
V_9 -> V_27 = V_20 -> V_86 / 1000000 ;
}
for ( V_4 = 0 ; V_4 < V_104 ; V_4 ++ ) {
unsigned int V_56 = F_20 ( V_20 -> V_57 [ V_4 ] ) ;
F_31 ( V_56 , & V_88 , & V_89 ) ;
}
V_9 -> V_92 [ 1 ] = V_9 -> V_106 ;
V_9 -> V_92 [ 2 ] = V_104 ;
V_9 -> V_92 [ 3 ] = 0x12 ;
V_9 -> V_92 [ 4 ] = 0x03 ;
V_9 -> V_92 [ 5 ] = 0x00 ;
V_9 -> V_92 [ 6 ] = V_88 ;
V_9 -> V_92 [ 7 ] = V_89 ;
V_9 -> V_92 [ 8 ] = V_105 ;
V_22 = F_32 ( V_6 , V_107 ) ;
if ( V_22 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_9 -> V_26 = V_9 -> V_27 ;
if ( V_20 -> V_77 == V_78 ) {
V_9 -> V_13 = 1 ;
V_22 = F_23 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_22 < 0 ) {
V_9 -> V_13 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_15 -> V_18 -> V_103 = NULL ;
} else {
V_15 -> V_18 -> V_103 = F_37 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_56 = F_20 ( V_109 -> V_111 ) ;
T_2 V_88 = 0 ;
T_2 V_89 = 0 ;
T_2 V_105 = 0 ;
int V_22 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_112 ;
}
F_31 ( V_56 , & V_88 , & V_89 ) ;
V_9 -> V_92 [ 1 ] = 0x16 ;
V_9 -> V_92 [ 2 ] = 0x80 ;
V_9 -> V_92 [ 3 ] = 0x00 ;
V_9 -> V_92 [ 4 ] = V_88 ;
V_9 -> V_92 [ 5 ] = V_89 ;
V_9 -> V_92 [ 6 ] = V_105 ;
V_22 = F_32 ( V_6 , V_113 ) ;
if ( V_22 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
for ( V_4 = 0 ; V_4 < V_109 -> V_114 ; V_4 ++ ) {
T_1 V_21 ;
V_22 = F_35 ( V_6 , V_113 ) ;
if ( V_22 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_21 = F_8 ( F_40 ( ( V_115
* ) ( V_9 -> V_98 + 1 ) ) ) ;
V_21 &= 0x00ffffff ;
V_110 [ V_4 ] = F_9 ( V_15 , V_21 ) ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_109 -> V_114 ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_22 ;
F_5 ( & V_9 -> V_16 ) ;
V_22 = F_42 ( V_6 , V_15 , V_109 , V_110 ) ;
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_56 = F_20 ( V_109 -> V_111 ) ;
int V_22 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_52 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_112 ;
}
for ( V_4 = 0 ; V_4 < V_109 -> V_114 ; V_4 ++ ) {
V_9 -> V_92 [ 1 ] = 1 ;
V_9 -> V_92 [ 2 ] = V_110 [ V_4 ] ;
V_9 -> V_92 [ 3 ] = V_56 ;
V_22 = F_32 ( V_6 , V_116 ) ;
if ( V_22 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_15 -> V_59 [ V_56 ] = V_110 [ V_4 ] ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_109 -> V_114 ;
}
static int F_44 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_101 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_22 ;
if ( V_101 != V_20 -> V_85 )
return - V_102 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_52 ) {
V_9 -> V_52 = 1 ;
V_22 = F_23 ( V_6 , V_9 -> V_50 ,
V_9 -> V_51 , 0 ) ;
if ( V_22 < 0 ) {
V_9 -> V_52 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_15 -> V_18 -> V_103 = NULL ;
}
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
static int F_45 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_19 * V_20 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_75 ;
int V_76 = 0 ;
V_76 |= F_26 ( & V_20 -> V_77 , V_78 | V_79 ) ;
V_76 |= F_26 ( & V_20 -> V_80 , V_81 ) ;
V_76 |= F_26 ( & V_20 -> V_82 , V_78 ) ;
V_76 |= F_26 ( & V_20 -> V_83 , V_31 ) ;
V_76 |= F_26 ( & V_20 -> V_30 , V_31 | V_84 ) ;
if ( V_76 ) {
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
V_76 |= F_27 ( V_20 -> V_77 ) ;
V_76 |= F_27 ( V_20 -> V_30 ) ;
if ( V_76 )
return 2 ;
V_76 |= F_28 ( & V_20 -> V_85 , 0 ) ;
V_76 |= F_29 ( & V_20 -> V_86 , 1000000 ) ;
V_76 |= F_28 ( & V_20 -> V_87 ,
V_20 -> V_28 ) ;
if ( V_20 -> V_30 == V_31 )
V_76 |= F_29 ( & V_20 -> V_33 , 1 ) ;
else
V_76 |= F_28 ( & V_20 -> V_33 , 0 ) ;
if ( V_76 )
return 3 ;
V_75 = F_30 ( V_20 -> V_86 , 1000000 ) ;
V_76 |= F_28 ( & V_20 -> V_86 , V_75 ) ;
if ( V_76 )
return 4 ;
return 0 ;
}
static int F_46 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_22 ;
F_5 ( & V_9 -> V_16 ) ;
V_9 -> V_55 = V_20 -> V_86 / 1000000 ;
V_9 -> V_54 = V_9 -> V_55 ;
if ( V_20 -> V_77 == V_78 ) {
V_9 -> V_52 = 1 ;
V_22 = F_23 ( V_6 , V_9 -> V_50 ,
V_9 -> V_51 , 0 ) ;
if ( V_22 < 0 ) {
V_9 -> V_52 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
V_15 -> V_18 -> V_103 = NULL ;
} else {
V_15 -> V_18 -> V_103 = F_44 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_47 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
int V_22 ;
V_22 = F_48 ( V_6 , V_15 , V_109 , V_110 , 0 ) ;
if ( V_22 )
return V_22 ;
return V_109 -> V_114 ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_22 ;
F_5 ( & V_9 -> V_16 ) ;
F_50 ( V_15 , V_110 ) ;
V_9 -> V_92 [ 1 ] = V_15 -> V_117 & 0xff ;
V_9 -> V_92 [ 4 ] = V_15 -> V_118 & 0xff ;
V_9 -> V_92 [ 2 ] = ( V_15 -> V_117 >> 8 ) & 0xff ;
V_9 -> V_92 [ 5 ] = ( V_15 -> V_118 >> 8 ) & 0xff ;
V_9 -> V_92 [ 3 ] = ( V_15 -> V_117 >> 16 ) & 0xff ;
V_9 -> V_92 [ 6 ] = ( V_15 -> V_118 >> 16 ) & 0xff ;
V_22 = F_32 ( V_6 , V_119 ) ;
if ( V_22 < 0 )
goto V_120;
V_22 = F_35 ( V_6 , V_119 ) ;
if ( V_22 < 0 )
goto V_120;
V_15 -> V_118 = V_9 -> V_98 [ 1 ] |
( V_9 -> V_98 [ 2 ] << 8 ) |
( V_9 -> V_98 [ 3 ] << 16 ) ;
V_110 [ 1 ] = V_15 -> V_118 ;
V_22 = V_109 -> V_114 ;
V_120:
F_6 ( & V_9 -> V_16 ) ;
return V_22 ;
}
static void F_51 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 ) {
if ( V_9 -> V_121 )
F_2 ( V_9 -> V_121 ) ;
}
V_9 -> V_122 = 0 ;
}
static int F_52 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_51 ( V_6 , V_9 -> V_122 ) ;
return F_32 ( V_6 , V_123 ) ;
}
static void F_53 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_41 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_22 ;
switch ( V_1 -> V_24 ) {
case 0 :
break;
case - V_46 :
case - V_47 :
case - V_48 :
case - V_49 :
if ( V_9 -> V_122 )
F_51 ( V_6 , 0 ) ;
return;
default:
if ( V_9 -> V_122 ) {
F_13 ( V_6 -> V_38 , L_4 ,
V_1 -> V_24 ) ;
F_51 ( V_6 , 0 ) ;
}
return;
}
if ( ! V_9 -> V_122 )
return;
V_1 -> V_60 = V_9 -> V_124 ;
V_1 -> V_6 = F_11 ( V_6 ) ;
V_1 -> V_24 = 0 ;
V_22 = F_12 ( V_1 , V_37 ) ;
if ( V_22 < 0 ) {
F_13 ( V_6 -> V_38 , L_1 , V_22 ) ;
if ( V_22 == - V_39 )
F_13 ( V_6 -> V_38 ,
L_2 ) ;
F_51 ( V_6 , 0 ) ;
}
}
static int F_54 ( struct V_5 * V_6 )
{
struct V_69 * V_70 = F_11 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 = V_9 -> V_121 ;
F_55 ( V_1 , V_70 , F_34 ( V_70 , 4 ) ,
V_1 -> V_43 , V_9 -> V_124 ,
F_53 , V_6 ) ;
return F_12 ( V_1 , V_37 ) ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_125 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_126 = 255 ;
if ( V_125 < V_127 )
return - V_128 ;
V_126 = ( V_125 / ( 6 * 512 * 1000 / 33 ) ) - 6 ;
if ( V_126 > 255 )
return - V_128 ;
V_9 -> V_129 = V_126 ;
V_9 -> V_130 = V_125 ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_22 ;
if ( V_9 -> V_122 )
return 0 ;
V_9 -> V_92 [ 1 ] = V_9 -> V_129 ;
V_22 = F_32 ( V_6 , V_131 ) ;
if ( V_22 < 0 )
return V_22 ;
memset ( V_9 -> V_121 -> V_43 , 0 , V_9 -> V_124 ) ;
V_9 -> V_122 = 1 ;
V_22 = F_54 ( V_6 ) ;
if ( V_22 < 0 ) {
V_9 -> V_122 = 0 ;
return V_22 ;
}
return 0 ;
}
static void F_58 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_56 ,
unsigned int V_132 ,
unsigned int V_133 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
char V_134 = ( 1 << V_56 ) ;
char V_135 = ( 16 << V_56 ) ;
char * V_136 = ( char * ) ( V_9 -> V_121 -> V_43 ) ;
int V_137 = V_9 -> V_124 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_137 ; V_4 ++ ) {
char V_138 = * V_136 ;
V_138 &= ~ V_134 ;
if ( V_4 < V_132 )
V_138 |= V_134 ;
if ( ! V_133 )
V_138 &= ~ V_135 ;
else
V_138 |= V_135 ;
* V_136 ++ = V_138 ;
}
}
static int F_59 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
unsigned int V_56 = F_20 ( V_109 -> V_111 ) ;
if ( V_109 -> V_114 != 1 )
return - V_102 ;
F_58 ( V_6 , V_15 , V_56 , V_110 [ 0 ] , 0 ) ;
return V_109 -> V_114 ;
}
static int F_60 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_108 * V_109 ,
unsigned int * V_110 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_56 = F_20 ( V_109 -> V_111 ) ;
switch ( V_110 [ 0 ] ) {
case V_139 :
if ( V_110 [ 1 ] != 0 )
return - V_102 ;
return F_57 ( V_6 , V_15 ) ;
case V_140 :
return F_52 ( V_6 , V_15 ) ;
case V_141 :
V_110 [ 1 ] = V_9 -> V_122 ;
return 0 ;
case V_142 :
return F_56 ( V_6 , V_15 , V_110 [ 1 ] ) ;
case V_143 :
V_110 [ 1 ] = V_9 -> V_130 ;
return 0 ;
case V_144 :
F_58 ( V_6 , V_15 , V_56 , V_110 [ 1 ] , ( V_110 [ 2 ] != 0 ) ) ;
return 0 ;
case V_145 :
return - V_102 ;
}
return - V_102 ;
}
static int F_61 ( struct V_5 * V_6 , int V_56 )
{
struct V_14 * V_15 = V_6 -> V_42 ;
struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_105 ;
T_1 V_21 ;
int V_22 ;
switch ( V_56 ) {
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
V_9 -> V_92 [ 1 ] = 0x12 ;
V_9 -> V_92 [ 2 ] = 0x80 ;
V_9 -> V_92 [ 3 ] = 0x00 ;
V_9 -> V_92 [ 4 ] = 0 ;
V_9 -> V_92 [ 5 ] = 0 ;
V_9 -> V_92 [ 6 ] = V_105 ;
V_22 = F_32 ( V_6 , V_113 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_35 ( V_6 , V_113 ) ;
if ( V_22 < 0 )
return V_22 ;
V_21 = F_8 ( F_40 ( ( V_115 * ) ( V_9 -> V_98 + 1 ) ) ) ;
V_21 &= 0x00ffffff ;
return ( int ) F_9 ( V_15 , V_21 ) ;
}
static int F_62 ( struct V_5 * V_6 ,
const T_2 * V_110 , T_3 V_146 ,
unsigned long V_41 )
{
struct V_69 * V_70 = F_11 ( V_6 ) ;
T_2 * V_136 ;
T_2 * V_75 ;
int V_22 ;
if ( ! V_110 )
return 0 ;
if ( V_146 > V_147 ) {
F_13 ( V_6 -> V_38 , L_6 ) ;
return - V_148 ;
}
V_136 = F_63 ( V_110 , V_146 , V_149 ) ;
if ( ! V_136 )
return - V_148 ;
V_75 = F_64 ( 1 , V_149 ) ;
if ( ! V_75 ) {
F_65 ( V_136 ) ;
return - V_148 ;
}
* V_75 = 1 ;
V_22 = F_66 ( V_70 , F_67 ( V_70 , 0 ) ,
V_150 ,
V_151 ,
V_152 , 0x0000 ,
V_75 , 1 ,
V_94 ) ;
if ( V_22 < 0 ) {
F_13 ( V_6 -> V_38 , L_7 ) ;
goto V_120;
}
V_22 = F_66 ( V_70 , F_67 ( V_70 , 0 ) ,
V_150 ,
V_151 ,
0 , 0x0000 ,
V_136 , V_146 ,
V_94 ) ;
if ( V_22 < 0 ) {
F_13 ( V_6 -> V_38 , L_8 ) ;
goto V_120;
}
* V_75 = 0 ;
V_22 = F_66 ( V_70 , F_67 ( V_70 , 0 ) ,
V_150 ,
V_151 ,
V_152 , 0x0000 ,
V_75 , 1 ,
V_94 ) ;
if ( V_22 < 0 )
F_13 ( V_6 -> V_38 , L_9 ) ;
V_120:
F_65 ( V_75 ) ;
F_65 ( V_136 ) ;
return V_22 ;
}
static int F_68 ( struct V_5 * V_6 )
{
struct V_69 * V_70 = F_11 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_9 -> V_92 = F_69 ( V_93 , V_149 ) ;
V_9 -> V_29 = F_69 ( V_44 , V_149 ) ;
V_9 -> V_98 = F_69 ( V_99 , V_149 ) ;
V_9 -> V_11 = F_70 ( V_9 -> V_12 , sizeof( V_1 ) , V_149 ) ;
V_9 -> V_50 = F_70 ( V_9 -> V_51 , sizeof( V_1 ) , V_149 ) ;
if ( ! V_9 -> V_92 || ! V_9 -> V_29 || ! V_9 -> V_98 ||
! V_9 -> V_11 || ! V_9 -> V_50 )
return - V_148 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = F_71 ( 1 , V_149 ) ;
if ( ! V_1 )
return - V_148 ;
V_9 -> V_11 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_70 ;
V_1 -> V_41 = NULL ;
V_1 -> V_153 = F_72 ( V_70 , 6 ) ;
V_1 -> V_71 = V_72 ;
V_1 -> V_43 = F_69 ( V_44 , V_149 ) ;
if ( ! V_1 -> V_43 )
return - V_148 ;
V_1 -> V_154 = F_14 ;
V_1 -> V_63 = 1 ;
V_1 -> V_60 = V_44 ;
V_1 -> V_64 [ 0 ] . V_65 = 0 ;
V_1 -> V_64 [ 0 ] . V_66 = V_44 ;
}
for ( V_4 = 0 ; V_4 < V_9 -> V_51 ; V_4 ++ ) {
V_1 = F_71 ( 1 , V_149 ) ;
if ( ! V_1 )
return - V_148 ;
V_9 -> V_50 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_70 ;
V_1 -> V_41 = NULL ;
V_1 -> V_153 = F_73 ( V_70 , 2 ) ;
V_1 -> V_71 = V_72 ;
V_1 -> V_43 = F_69 ( V_61 , V_149 ) ;
if ( ! V_1 -> V_43 )
return - V_148 ;
V_1 -> V_154 = F_22 ;
V_1 -> V_63 = 1 ;
V_1 -> V_60 = V_61 ;
V_1 -> V_64 [ 0 ] . V_65 = 0 ;
V_1 -> V_64 [ 0 ] . V_66 = V_61 ;
V_1 -> V_62 = 1 ;
}
if ( V_9 -> V_124 ) {
V_1 = F_71 ( 0 , V_149 ) ;
if ( ! V_1 )
return - V_148 ;
V_9 -> V_121 = V_1 ;
V_1 -> V_43 = F_69 ( V_9 -> V_124 ,
V_149 ) ;
if ( ! V_1 -> V_43 )
return - V_148 ;
}
return 0 ;
}
static void F_74 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_1 = V_9 -> V_121 ;
if ( V_1 ) {
F_65 ( V_1 -> V_43 ) ;
F_75 ( V_1 ) ;
}
if ( V_9 -> V_50 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_51 ; V_4 ++ ) {
V_1 = V_9 -> V_50 [ V_4 ] ;
if ( V_1 ) {
F_65 ( V_1 -> V_43 ) ;
F_75 ( V_1 ) ;
}
}
F_65 ( V_9 -> V_50 ) ;
}
if ( V_9 -> V_11 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = V_9 -> V_11 [ V_4 ] ;
if ( V_1 ) {
F_65 ( V_1 -> V_43 ) ;
F_75 ( V_1 ) ;
}
}
F_65 ( V_9 -> V_11 ) ;
}
F_65 ( V_9 -> V_98 ) ;
F_65 ( V_9 -> V_29 ) ;
F_65 ( V_9 -> V_92 ) ;
}
static int F_76 ( struct V_5 * V_6 ,
unsigned long V_155 )
{
struct V_156 * V_157 = F_77 ( V_6 ) ;
struct V_69 * V_70 = F_11 ( V_6 ) ;
struct V_8 * V_9 ;
struct V_14 * V_15 ;
int V_65 ;
int V_22 ;
V_9 = F_78 ( V_6 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_148 ;
F_79 ( & V_9 -> V_16 ) ;
F_80 ( V_157 , V_9 ) ;
V_9 -> V_74 = ( V_70 -> V_158 == V_159 ) ;
if ( V_9 -> V_74 ) {
V_9 -> V_12 = V_160 ;
V_9 -> V_51 = V_161 ;
V_9 -> V_124 = 512 ;
} else {
V_9 -> V_12 = V_162 ;
V_9 -> V_51 = V_163 ;
}
V_22 = F_68 ( V_6 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_81 ( V_70 , V_157 -> V_164 -> V_165 . V_166 ,
3 ) ;
if ( V_22 < 0 ) {
F_13 ( V_6 -> V_38 ,
L_10 ) ;
return V_22 ;
}
V_22 = F_82 ( V_6 , & V_70 -> V_6 , V_167 ,
F_62 , 0 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_83 ( V_6 , ( V_9 -> V_74 ) ? 4 : 3 ) ;
if ( V_22 )
return V_22 ;
V_15 = & V_6 -> V_168 [ 0 ] ;
V_6 -> V_42 = V_15 ;
V_15 -> type = V_169 ;
V_15 -> V_170 = V_171 | V_172 | V_173 | V_174 ;
V_15 -> V_175 = V_176 ;
V_15 -> V_177 = V_176 ;
V_15 -> V_178 = 0x00ffffff ;
V_15 -> V_179 = & V_180 ;
V_15 -> V_181 = F_39 ;
V_15 -> V_182 = F_25 ;
V_15 -> V_183 = F_38 ;
V_15 -> V_184 = F_4 ;
V_15 = & V_6 -> V_168 [ 1 ] ;
V_6 -> V_67 = V_15 ;
V_15 -> type = V_185 ;
V_15 -> V_170 = V_186 | V_172 | V_187 ;
V_15 -> V_175 = 4 ;
V_15 -> V_177 = V_15 -> V_175 ;
V_15 -> V_178 = 0x00ff ;
V_15 -> V_179 = & V_188 ;
V_15 -> V_189 = F_43 ;
V_15 -> V_181 = F_41 ;
V_15 -> V_182 = F_45 ;
V_15 -> V_183 = F_46 ;
V_15 -> V_184 = F_18 ;
V_22 = F_84 ( V_15 ) ;
if ( V_22 )
return V_22 ;
V_15 = & V_6 -> V_168 [ 2 ] ;
V_15 -> type = V_190 ;
V_15 -> V_170 = V_171 | V_186 ;
V_15 -> V_175 = 24 ;
V_15 -> V_178 = 1 ;
V_15 -> V_179 = & V_191 ;
V_15 -> V_192 = F_49 ;
V_15 -> V_193 = F_47 ;
if ( V_9 -> V_74 ) {
V_15 = & V_6 -> V_168 [ 3 ] ;
V_15 -> type = V_194 ;
V_15 -> V_170 = V_186 | V_195 ;
V_15 -> V_175 = 8 ;
V_15 -> V_178 = V_9 -> V_124 ;
V_15 -> V_189 = F_59 ;
V_15 -> V_193 = F_60 ;
F_56 ( V_6 , V_15 , V_196 ) ;
}
V_65 = F_61 ( V_6 , 0 ) ;
if ( V_65 < 0 ) {
F_13 ( V_6 -> V_38 ,
L_11 ) ;
return V_65 ;
}
F_85 ( V_6 -> V_38 , L_12 , V_65 ) ;
return 0 ;
}
static void F_86 ( struct V_5 * V_6 )
{
struct V_156 * V_157 = F_77 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_80 ( V_157 , NULL ) ;
if ( ! V_9 )
return;
F_5 ( & V_9 -> V_16 ) ;
F_3 ( V_6 , 1 ) ;
F_17 ( V_6 , 1 ) ;
F_51 ( V_6 , 1 ) ;
F_74 ( V_6 ) ;
F_6 ( & V_9 -> V_16 ) ;
}
static int F_87 ( struct V_156 * V_157 ,
const struct V_197 * V_198 )
{
return F_88 ( V_157 , & V_199 , 0 ) ;
}
