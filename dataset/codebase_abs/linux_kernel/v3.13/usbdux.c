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
struct V_14 * V_15 = V_6 -> V_18 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_4 , V_19 , V_20 ;
switch ( V_1 -> V_21 ) {
case 0 :
memcpy ( V_9 -> V_22 , V_1 -> V_23 , V_24 ) ;
break;
case - V_25 :
F_8 ( V_6 -> V_26 , L_1 ) ;
break;
case - V_27 :
case - V_28 :
case - V_29 :
case - V_30 :
if ( V_9 -> V_13 ) {
V_15 -> V_31 -> V_32 |= V_33 ;
V_15 -> V_31 -> V_32 |= V_34 ;
F_9 ( V_6 , V_15 ) ;
F_3 ( V_6 , 0 ) ;
}
return;
default:
if ( V_9 -> V_13 ) {
F_10 ( V_6 -> V_26 ,
L_2 ,
V_1 -> V_21 ) ;
V_15 -> V_31 -> V_32 |= V_33 ;
V_15 -> V_31 -> V_32 |= V_34 ;
F_9 ( V_6 , V_15 ) ;
F_3 ( V_6 , 0 ) ;
}
return;
}
if ( F_11 ( ! V_9 -> V_13 ) ) {
return;
}
V_1 -> V_6 = F_12 ( V_6 ) ;
V_19 = F_13 ( V_1 , V_35 ) ;
if ( F_11 ( V_19 < 0 ) ) {
F_10 ( V_6 -> V_26 ,
L_3 , V_19 ) ;
if ( V_19 == - V_36 )
F_10 ( V_6 -> V_26 ,
L_4 ) ;
V_15 -> V_31 -> V_32 |= V_33 ;
V_15 -> V_31 -> V_32 |= V_34 ;
F_9 ( V_6 , V_15 ) ;
F_3 ( V_6 , 0 ) ;
return;
}
V_9 -> V_37 -- ;
if ( F_14 ( V_9 -> V_37 > 0 ) )
return;
V_9 -> V_37 = V_9 -> V_38 ;
if ( ! V_9 -> V_39 ) {
V_9 -> V_40 -- ;
if ( V_9 -> V_40 < 0 ) {
F_3 ( V_6 , 0 ) ;
V_15 -> V_31 -> V_32 |= V_33 ;
F_9 ( V_6 , V_15 ) ;
return;
}
}
V_20 = V_15 -> V_31 -> V_41 . V_42 ;
for ( V_4 = 0 ; V_4 < V_20 ; V_4 ++ ) {
unsigned int V_43 = F_15 ( V_15 -> V_31 -> V_41 . V_44 [ V_4 ] ) ;
T_1 V_45 = F_16 ( V_9 -> V_22 [ V_4 ] ) ;
if ( F_17 ( V_15 , V_43 ) )
V_45 ^= ( ( V_15 -> V_46 + 1 ) >> 1 ) ;
V_19 = F_18 ( V_15 -> V_31 , V_45 ) ;
if ( F_11 ( V_19 == 0 ) ) {
F_3 ( V_6 , 0 ) ;
return;
}
}
V_15 -> V_31 -> V_32 |= V_47 | V_48 ;
F_9 ( V_6 , V_15 ) ;
}
static void F_19 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 && V_9 -> V_49 )
F_1 ( V_9 -> V_49 , V_9 -> V_50 ) ;
V_9 -> V_51 = 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_16 ) ;
F_19 ( V_6 , V_9 -> V_51 ) ;
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_17 ;
struct V_14 * V_15 = V_6 -> V_52 ;
struct V_8 * V_9 = V_6 -> V_10 ;
T_2 * V_53 ;
int V_54 ;
int V_55 ;
int V_4 ;
switch ( V_1 -> V_21 ) {
case 0 :
break;
case - V_27 :
case - V_28 :
case - V_29 :
case - V_30 :
if ( V_9 -> V_51 ) {
V_15 -> V_31 -> V_32 |= V_33 ;
F_9 ( V_6 , V_15 ) ;
F_19 ( V_6 , 0 ) ;
}
return;
default:
if ( V_9 -> V_51 ) {
F_10 ( V_6 -> V_26 ,
L_5 ,
V_1 -> V_21 ) ;
V_15 -> V_31 -> V_32 |= V_34 ;
V_15 -> V_31 -> V_32 |= V_33 ;
F_9 ( V_6 , V_15 ) ;
F_19 ( V_6 , 0 ) ;
}
return;
}
if ( ! V_9 -> V_51 )
return;
V_9 -> V_56 -- ;
if ( ( int ) V_9 -> V_56 <= 0 ) {
V_9 -> V_56 = V_9 -> V_57 ;
if ( ! V_9 -> V_58 ) {
V_9 -> V_59 -- ;
if ( V_9 -> V_59 < 0 ) {
F_19 ( V_6 , 0 ) ;
V_15 -> V_31 -> V_32 |= V_33 ;
F_9 ( V_6 , V_15 ) ;
return;
}
}
V_53 = V_1 -> V_23 ;
V_54 = V_15 -> V_31 -> V_41 . V_42 ;
* V_53 ++ = V_54 ;
for ( V_4 = 0 ; V_4 < V_15 -> V_31 -> V_41 . V_42 ; V_4 ++ ) {
unsigned int V_60 = V_9 -> V_61 [ V_4 ] ;
unsigned short V_45 ;
V_55 = F_22 ( V_15 -> V_31 , & V_45 ) ;
if ( V_55 < 0 ) {
F_10 ( V_6 -> V_26 , L_6 ) ;
V_15 -> V_31 -> V_32 |= ( V_33 |
V_62 ) ;
}
* V_53 ++ = V_45 & 0xff ;
* V_53 ++ = ( V_45 >> 8 ) & 0xff ;
* V_53 ++ = V_60 ;
V_9 -> V_63 [ V_60 ] = V_45 ;
V_15 -> V_31 -> V_32 |= V_47 ;
F_9 ( V_6 , V_15 ) ;
}
}
V_1 -> V_64 = V_65 ;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_1 -> V_21 = 0 ;
if ( V_9 -> V_51 ) {
if ( V_9 -> V_66 )
V_1 -> V_67 = 8 ;
else
V_1 -> V_67 = 1 ;
V_1 -> V_68 = 1 ;
V_1 -> V_69 [ 0 ] . V_70 = 0 ;
V_1 -> V_69 [ 0 ] . V_71 = V_65 ;
V_1 -> V_69 [ 0 ] . V_21 = 0 ;
V_55 = F_13 ( V_1 , V_35 ) ;
if ( V_55 < 0 ) {
F_10 ( V_6 -> V_26 ,
L_7 ,
V_55 ) ;
if ( V_55 == V_36 )
F_10 ( V_6 -> V_26 ,
L_8 ) ;
V_15 -> V_31 -> V_32 |= V_33 ;
V_15 -> V_31 -> V_32 |= V_34 ;
F_9 ( V_6 , V_15 ) ;
F_19 ( V_6 , 0 ) ;
}
}
}
static int F_23 ( struct V_5 * V_6 ,
struct V_1 * * V_2 , int V_3 ,
int V_72 )
{
struct V_73 * V_74 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_55 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_1 = V_2 [ V_4 ] ;
if ( V_72 )
V_1 -> V_67 = V_9 -> V_75 ;
V_1 -> V_17 = V_6 ;
V_1 -> V_6 = V_74 ;
V_1 -> V_21 = 0 ;
V_1 -> V_76 = V_77 ;
V_55 = F_13 ( V_1 , V_35 ) ;
if ( V_55 )
return V_55 ;
}
return 0 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_14 * V_15 , struct V_78 * V_41 )
{
struct V_8 * V_79 = V_6 -> V_10 ;
int V_19 = 0 , V_4 ;
unsigned int V_80 ;
V_19 |= F_25 ( & V_41 -> V_81 , V_82 | V_83 ) ;
V_19 |= F_25 ( & V_41 -> V_84 , V_85 ) ;
V_19 |= F_25 ( & V_41 -> V_86 , V_82 ) ;
V_19 |= F_25 ( & V_41 -> V_87 , V_88 ) ;
V_19 |= F_25 ( & V_41 -> V_89 , V_88 | V_90 ) ;
if ( V_19 )
return 1 ;
V_19 |= F_26 ( V_41 -> V_81 ) ;
V_19 |= F_26 ( V_41 -> V_89 ) ;
if ( V_19 )
return 2 ;
V_19 |= F_27 ( & V_41 -> V_91 , 0 ) ;
if ( V_41 -> V_84 == V_92 )
V_19 |= F_27 ( & V_41 -> V_93 , 0 ) ;
if ( V_41 -> V_84 == V_85 ) {
if ( V_79 -> V_66 ) {
V_4 = 1 ;
while ( V_4 < ( V_41 -> V_42 ) )
V_4 = V_4 * 2 ;
V_19 |= F_28 ( & V_41 -> V_93 ,
1000000 / 8 * V_4 ) ;
V_80 =
( ( unsigned int ) ( V_41 -> V_93 / 125000 ) ) *
125000 ;
} else {
V_19 |= F_28 ( & V_41 -> V_93 ,
1000000 ) ;
V_80 = ( ( unsigned int ) ( V_41 -> V_93 /
1000000 ) ) * 1000000 ;
}
V_19 |= F_27 ( & V_41 -> V_93 ,
V_80 ) ;
}
V_19 |= F_27 ( & V_41 -> V_94 , V_41 -> V_42 ) ;
if ( V_41 -> V_89 == V_88 ) {
} else {
V_19 |= F_27 ( & V_41 -> V_95 , 0 ) ;
}
if ( V_19 )
return 3 ;
return 0 ;
}
static T_2 F_29 ( unsigned int V_60 , unsigned int V_43 )
{
T_2 V_96 = ( V_43 <= 1 ) ;
T_2 V_97 = ( ( V_43 % 2 ) == 0 ) ;
return ( V_60 << 4 ) | ( ( V_96 == 1 ) << 2 ) | ( ( V_97 == 1 ) << 3 ) ;
}
static int F_30 ( struct V_5 * V_6 , unsigned int V_98 )
{
struct V_73 * V_74 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_99 ;
V_9 -> V_100 [ 0 ] = V_98 ;
return F_31 ( V_74 , F_32 ( V_74 , 1 ) ,
V_9 -> V_100 , V_101 ,
& V_99 , V_102 ) ;
}
static int F_33 ( struct V_5 * V_6 , unsigned int V_103 )
{
struct V_73 * V_74 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_55 ;
int V_104 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_105 ; V_4 ++ ) {
V_55 = F_31 ( V_74 , F_34 ( V_74 , 8 ) ,
V_9 -> V_106 , V_107 ,
& V_104 , V_102 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_16 ( V_9 -> V_106 [ 0 ] ) == V_103 )
return V_55 ;
}
return - V_108 ;
}
static int F_35 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_109 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_55 = - V_110 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_109 != 0 )
goto V_111;
if ( ! V_9 -> V_13 ) {
V_9 -> V_13 = 1 ;
V_55 = F_23 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_55 < 0 ) {
V_9 -> V_13 = 0 ;
goto V_111;
}
V_15 -> V_31 -> V_112 = NULL ;
} else {
V_55 = - V_113 ;
}
V_111:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ;
}
static int F_36 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_78 * V_41 = & V_15 -> V_31 -> V_41 ;
int V_54 = V_41 -> V_42 ;
int V_55 = - V_113 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 )
goto V_114;
V_15 -> V_31 -> V_115 = 0 ;
V_9 -> V_100 [ 1 ] = V_54 ;
for ( V_4 = 0 ; V_4 < V_54 ; ++ V_4 ) {
unsigned int V_60 = F_37 ( V_41 -> V_44 [ V_4 ] ) ;
unsigned int V_43 = F_15 ( V_41 -> V_44 [ V_4 ] ) ;
V_9 -> V_100 [ V_4 + 2 ] = F_29 ( V_60 , V_43 ) ;
}
V_55 = F_30 ( V_6 , V_116 ) ;
if ( V_55 < 0 )
goto V_114;
if ( V_9 -> V_66 ) {
V_9 -> V_75 = 1 ;
while ( V_9 -> V_75 < V_54 )
V_9 -> V_75 *= 2 ;
V_9 -> V_38 = V_41 -> V_93 /
( 125000 * V_9 -> V_75 ) ;
} else {
V_9 -> V_75 = 1 ;
V_9 -> V_38 = V_41 -> V_93 / 1000000 ;
}
if ( V_9 -> V_38 < 1 ) {
V_55 = - V_110 ;
goto V_114;
}
V_9 -> V_37 = V_9 -> V_38 ;
if ( V_41 -> V_89 == V_88 ) {
V_9 -> V_40 = V_41 -> V_95 ;
V_9 -> V_39 = 0 ;
} else {
V_9 -> V_39 = 1 ;
V_9 -> V_40 = 0 ;
}
if ( V_41 -> V_81 == V_82 ) {
V_9 -> V_13 = 1 ;
V_55 = F_23 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_55 < 0 ) {
V_9 -> V_13 = 0 ;
goto V_114;
}
V_15 -> V_31 -> V_112 = NULL ;
} else {
V_15 -> V_31 -> V_112 = F_35 ;
}
V_114:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ;
}
static int F_38 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_60 = F_37 ( V_118 -> V_120 ) ;
unsigned int V_43 = F_15 ( V_118 -> V_120 ) ;
unsigned int V_45 ;
int V_55 = - V_113 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 )
goto V_121;
V_9 -> V_100 [ 1 ] = F_29 ( V_60 , V_43 ) ;
V_55 = F_30 ( V_6 , V_122 ) ;
if ( V_55 < 0 )
goto V_121;
for ( V_4 = 0 ; V_4 < V_118 -> V_20 ; V_4 ++ ) {
V_55 = F_33 ( V_6 , V_122 ) ;
if ( V_55 < 0 )
goto V_121;
V_45 = F_16 ( V_9 -> V_106 [ 1 ] ) ;
if ( F_17 ( V_15 , V_43 ) )
V_45 ^= ( ( V_15 -> V_46 + 1 ) >> 1 ) ;
V_119 [ V_4 ] = V_45 ;
}
V_121:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ? V_55 : V_118 -> V_20 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_60 = F_37 ( V_118 -> V_120 ) ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
for ( V_4 = 0 ; V_4 < V_118 -> V_20 ; V_4 ++ )
V_119 [ V_4 ] = V_9 -> V_63 [ V_60 ] ;
F_6 ( & V_9 -> V_16 ) ;
return V_118 -> V_20 ;
}
static int F_40 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_60 = F_37 ( V_118 -> V_120 ) ;
unsigned int V_45 = V_9 -> V_63 [ V_60 ] ;
T_1 * V_96 = ( T_1 * ) & V_9 -> V_100 [ 2 ] ;
int V_55 = - V_113 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_51 )
goto V_123;
V_9 -> V_100 [ 1 ] = 1 ;
V_9 -> V_100 [ 4 ] = V_60 << 6 ;
for ( V_4 = 0 ; V_4 < V_118 -> V_20 ; V_4 ++ ) {
V_45 = V_119 [ V_4 ] ;
* V_96 = F_41 ( V_45 ) ;
V_55 = F_30 ( V_6 , V_124 ) ;
if ( V_55 < 0 )
goto V_123;
}
V_9 -> V_63 [ V_60 ] = V_45 ;
V_123:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ? V_55 : V_118 -> V_20 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_109 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_55 = - V_110 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_109 != 0 )
goto V_125;
if ( ! V_9 -> V_51 ) {
V_9 -> V_51 = 1 ;
V_55 = F_23 ( V_6 , V_9 -> V_49 ,
V_9 -> V_50 , 0 ) ;
if ( V_55 < 0 ) {
V_9 -> V_51 = 0 ;
goto V_125;
}
V_15 -> V_31 -> V_112 = NULL ;
} else {
V_55 = - V_113 ;
}
V_125:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_14 * V_15 , struct V_78 * V_41 )
{
struct V_8 * V_79 = V_6 -> V_10 ;
int V_19 = 0 ;
unsigned int V_126 ;
if ( ! V_79 )
return - V_108 ;
V_19 |= F_25 ( & V_41 -> V_81 , V_82 | V_83 ) ;
if ( 0 ) {
V_126 = V_92 ;
} else {
V_126 = V_85 ;
}
V_19 |= F_25 ( & V_41 -> V_84 , V_126 ) ;
if ( 0 ) {
V_126 = V_85 ;
} else {
V_126 = V_82 ;
}
V_19 |= F_25 ( & V_41 -> V_86 , V_126 ) ;
V_19 |= F_25 ( & V_41 -> V_87 , V_88 ) ;
V_19 |= F_25 ( & V_41 -> V_89 , V_88 | V_90 ) ;
if ( V_19 )
return 1 ;
V_19 |= F_26 ( V_41 -> V_81 ) ;
V_19 |= F_26 ( V_41 -> V_89 ) ;
if ( V_19 )
return 2 ;
V_19 |= F_27 ( & V_41 -> V_91 , 0 ) ;
if ( V_41 -> V_84 == V_92 )
V_19 |= F_27 ( & V_41 -> V_93 , 0 ) ;
if ( V_41 -> V_84 == V_85 )
V_19 |= F_28 ( & V_41 -> V_93 ,
1000000 ) ;
if ( V_41 -> V_86 == V_85 )
V_19 |= F_28 ( & V_41 -> V_127 , 125000 ) ;
V_19 |= F_27 ( & V_41 -> V_94 , V_41 -> V_42 ) ;
if ( V_41 -> V_89 == V_88 ) {
} else {
V_19 |= F_27 ( & V_41 -> V_95 , 0 ) ;
}
if ( V_19 )
return 3 ;
return 0 ;
}
static int F_44 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_78 * V_41 = & V_15 -> V_31 -> V_41 ;
int V_55 = - V_113 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_51 )
goto V_128;
V_15 -> V_31 -> V_115 = 0 ;
for ( V_4 = 0 ; V_4 < V_41 -> V_42 ; ++ V_4 ) {
unsigned int V_60 = F_37 ( V_41 -> V_44 [ V_4 ] ) ;
V_9 -> V_61 [ V_4 ] = V_60 << 6 ;
}
if ( 0 ) {
V_9 -> V_57 = V_41 -> V_127 / 125000 ;
} else {
V_9 -> V_57 = V_41 -> V_93 / 1000000 ;
if ( V_9 -> V_57 < 1 ) {
V_55 = - V_110 ;
goto V_128;
}
}
V_9 -> V_56 = V_9 -> V_57 ;
if ( V_41 -> V_89 == V_88 ) {
if ( 0 ) {
V_9 -> V_59 = V_41 -> V_95 *
V_41 -> V_94 ;
} else {
V_9 -> V_59 = V_41 -> V_95 ;
}
V_9 -> V_58 = 0 ;
} else {
V_9 -> V_58 = 1 ;
V_9 -> V_59 = 0 ;
}
if ( V_41 -> V_81 == V_82 ) {
V_9 -> V_51 = 1 ;
V_55 = F_23 ( V_6 , V_9 -> V_49 ,
V_9 -> V_50 , 0 ) ;
if ( V_55 < 0 ) {
V_9 -> V_51 = 0 ;
goto V_128;
}
V_15 -> V_31 -> V_112 = NULL ;
} else {
V_15 -> V_31 -> V_112 = F_42 ;
}
V_128:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ;
}
static int F_45 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
int V_55 ;
V_55 = F_46 ( V_6 , V_15 , V_118 , V_119 , 0 ) ;
if ( V_55 )
return V_55 ;
return V_118 -> V_20 ;
}
static int F_47 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_55 ;
F_5 ( & V_9 -> V_16 ) ;
F_48 ( V_15 , V_119 ) ;
V_9 -> V_100 [ 1 ] = V_15 -> V_129 ;
V_9 -> V_100 [ 2 ] = V_15 -> V_130 ;
V_55 = F_30 ( V_6 , V_131 ) ;
if ( V_55 < 0 )
goto V_132;
V_55 = F_33 ( V_6 , V_131 ) ;
if ( V_55 < 0 )
goto V_132;
V_119 [ 1 ] = F_16 ( V_9 -> V_106 [ 1 ] ) ;
V_132:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ? V_55 : V_118 -> V_20 ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_60 = F_37 ( V_118 -> V_120 ) ;
int V_55 = 0 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
for ( V_4 = 0 ; V_4 < V_118 -> V_20 ; V_4 ++ ) {
V_55 = F_30 ( V_6 , V_133 ) ;
if ( V_55 < 0 )
goto V_134;
V_55 = F_33 ( V_6 , V_133 ) ;
if ( V_55 < 0 )
goto V_134;
V_119 [ V_4 ] = F_16 ( V_9 -> V_106 [ V_60 + 1 ] ) ;
}
V_134:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ? V_55 : V_118 -> V_20 ;
}
static int F_50 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_60 = F_37 ( V_118 -> V_120 ) ;
T_1 * V_96 = ( T_1 * ) & V_9 -> V_100 [ 2 ] ;
int V_55 = 0 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
V_9 -> V_100 [ 1 ] = V_60 ;
for ( V_4 = 0 ; V_4 < V_118 -> V_20 ; V_4 ++ ) {
* V_96 = F_41 ( V_119 [ V_4 ] ) ;
V_55 = F_30 ( V_6 , V_135 ) ;
if ( V_55 < 0 )
break;
}
F_6 ( & V_9 -> V_16 ) ;
return V_55 ? V_55 : V_118 -> V_20 ;
}
static int F_51 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_117 * V_118 , unsigned int * V_119 )
{
return 2 ;
}
static void F_52 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_2 ( V_9 -> V_136 ) ;
}
static void F_53 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 )
F_52 ( V_6 ) ;
V_9 -> V_137 = 0 ;
}
static int F_54 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_55 ;
F_5 ( & V_9 -> V_16 ) ;
F_53 ( V_6 , V_9 -> V_137 ) ;
V_55 = F_30 ( V_6 , V_138 ) ;
F_6 ( & V_9 -> V_16 ) ;
return V_55 ;
}
static void F_55 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_17 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_55 ;
switch ( V_1 -> V_21 ) {
case 0 :
break;
case - V_27 :
case - V_28 :
case - V_29 :
case - V_30 :
if ( V_9 -> V_137 )
F_53 ( V_6 , 0 ) ;
return;
default:
if ( V_9 -> V_137 ) {
F_10 ( V_6 -> V_26 ,
L_9 ,
V_1 -> V_21 ) ;
F_53 ( V_6 , 0 ) ;
}
return;
}
if ( ! V_9 -> V_137 )
return;
V_1 -> V_64 = V_9 -> V_139 ;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_1 -> V_21 = 0 ;
if ( V_9 -> V_137 ) {
V_55 = F_13 ( V_1 , V_35 ) ;
if ( V_55 < 0 ) {
F_10 ( V_6 -> V_26 ,
L_10 ,
V_55 ) ;
if ( V_55 == V_36 )
F_10 ( V_6 -> V_26 ,
L_8 ) ;
F_53 ( V_6 , 0 ) ;
}
}
}
static int F_56 ( struct V_5 * V_6 )
{
struct V_73 * V_74 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 = V_9 -> V_136 ;
F_57 ( V_1 , V_74 , F_32 ( V_74 , 4 ) ,
V_1 -> V_23 ,
V_9 -> V_139 ,
F_55 ,
V_6 ) ;
return F_13 ( V_1 , V_35 ) ;
}
static int F_58 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_140 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_141 = 255 ;
if ( V_140 < V_142 ) {
return - V_143 ;
} else {
V_141 = ( V_140 / ( 6 * 512 * 1000 / 33 ) ) - 6 ;
if ( V_141 > 255 )
return - V_143 ;
}
V_9 -> V_144 = V_141 ;
V_9 -> V_145 = V_140 ;
return 0 ;
}
static int F_59 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_55 = 0 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_137 )
goto V_146;
V_9 -> V_100 [ 1 ] = V_9 -> V_144 ;
V_55 = F_30 ( V_6 , V_147 ) ;
if ( V_55 < 0 )
goto V_146;
memset ( V_9 -> V_136 -> V_23 , 0 , V_9 -> V_139 ) ;
V_9 -> V_137 = 1 ;
V_55 = F_56 ( V_6 ) ;
if ( V_55 < 0 )
V_9 -> V_137 = 0 ;
V_146:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ;
}
static void F_60 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_60 ,
unsigned int V_148 ,
unsigned int V_149 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
char V_150 = ( 1 << V_60 ) ;
char V_151 = ( 16 << V_60 ) ;
char * V_152 = ( char * ) ( V_9 -> V_136 -> V_23 ) ;
int V_153 = V_9 -> V_139 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_153 ; V_4 ++ ) {
char V_154 = * V_152 ;
V_154 &= ~ V_150 ;
if ( V_4 < V_148 )
V_154 |= V_150 ;
if ( ! V_149 )
V_154 &= ~ V_151 ;
else
V_154 |= V_151 ;
* V_152 ++ = V_154 ;
}
}
static int F_61 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
unsigned int V_60 = F_37 ( V_118 -> V_120 ) ;
if ( V_118 -> V_20 != 1 )
return - V_110 ;
F_60 ( V_6 , V_15 , V_60 , V_119 [ 0 ] , 0 ) ;
return V_118 -> V_20 ;
}
static int F_62 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_117 * V_118 ,
unsigned int * V_119 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_60 = F_37 ( V_118 -> V_120 ) ;
switch ( V_119 [ 0 ] ) {
case V_155 :
if ( V_119 [ 1 ] != 0 )
return - V_110 ;
return F_59 ( V_6 , V_15 ) ;
case V_156 :
return F_54 ( V_6 , V_15 ) ;
case V_157 :
V_119 [ 1 ] = V_9 -> V_137 ;
return 0 ;
case V_158 :
return F_58 ( V_6 , V_15 , V_119 [ 1 ] ) ;
case V_159 :
V_119 [ 1 ] = V_9 -> V_145 ;
return 0 ;
case V_160 :
F_60 ( V_6 , V_15 , V_60 , V_119 [ 1 ] , ( V_119 [ 2 ] != 0 ) ) ;
return 0 ;
case V_161 :
return - V_110 ;
}
return - V_110 ;
}
static int F_63 ( struct V_5 * V_6 ,
const T_3 * V_119 , T_4 V_162 ,
unsigned long V_17 )
{
struct V_73 * V_74 = F_12 ( V_6 ) ;
T_2 * V_152 ;
T_2 * V_163 ;
int V_55 ;
if ( ! V_119 )
return 0 ;
if ( V_162 > V_164 ) {
F_10 ( V_6 -> V_26 ,
L_11 ) ;
return - V_165 ;
}
V_152 = F_64 ( V_119 , V_162 , V_166 ) ;
if ( ! V_152 )
return - V_165 ;
V_163 = F_65 ( 1 , V_166 ) ;
if ( ! V_163 ) {
F_66 ( V_152 ) ;
return - V_165 ;
}
* V_163 = 1 ;
V_55 = F_67 ( V_74 , F_68 ( V_74 , 0 ) ,
V_167 ,
V_168 ,
V_169 , 0x0000 ,
V_163 , 1 ,
V_102 ) ;
if ( V_55 < 0 ) {
F_10 ( V_6 -> V_26 , L_12 ) ;
goto V_170;
}
V_55 = F_67 ( V_74 , F_68 ( V_74 , 0 ) ,
V_167 ,
V_168 ,
0 , 0x0000 ,
V_152 , V_162 ,
V_102 ) ;
if ( V_55 < 0 ) {
F_10 ( V_6 -> V_26 , L_13 ) ;
goto V_170;
}
* V_163 = 0 ;
V_55 = F_67 ( V_74 , F_68 ( V_74 , 0 ) ,
V_167 ,
V_168 ,
V_169 , 0x0000 ,
V_163 , 1 ,
V_102 ) ;
if ( V_55 < 0 )
F_10 ( V_6 -> V_26 , L_14 ) ;
V_170:
F_66 ( V_163 ) ;
F_66 ( V_152 ) ;
return V_55 ;
}
static int F_69 ( struct V_5 * V_6 )
{
struct V_73 * V_74 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_9 -> V_100 = F_70 ( V_101 , V_166 ) ;
V_9 -> V_22 = F_70 ( V_24 , V_166 ) ;
V_9 -> V_106 = F_70 ( V_107 , V_166 ) ;
V_9 -> V_11 = F_71 ( V_9 -> V_12 , sizeof( void * ) ,
V_166 ) ;
V_9 -> V_49 = F_71 ( V_9 -> V_50 , sizeof( void * ) ,
V_166 ) ;
if ( ! V_9 -> V_100 || ! V_9 -> V_22 || ! V_9 -> V_106 ||
! V_9 -> V_11 || ! V_9 -> V_49 )
return - V_165 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = F_72 ( 1 , V_166 ) ;
if ( ! V_1 )
return - V_165 ;
V_9 -> V_11 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_74 ;
V_1 -> V_17 = V_6 ;
V_1 -> V_171 = F_73 ( V_74 , 6 ) ;
V_1 -> V_76 = V_77 ;
V_1 -> V_23 = F_70 ( V_24 , V_166 ) ;
if ( ! V_1 -> V_23 )
return - V_165 ;
V_1 -> V_172 = F_7 ;
V_1 -> V_68 = 1 ;
V_1 -> V_64 = V_24 ;
V_1 -> V_69 [ 0 ] . V_70 = 0 ;
V_1 -> V_69 [ 0 ] . V_71 = V_24 ;
}
for ( V_4 = 0 ; V_4 < V_9 -> V_50 ; V_4 ++ ) {
V_1 = F_72 ( 1 , V_166 ) ;
if ( ! V_1 )
return - V_165 ;
V_9 -> V_49 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_74 ;
V_1 -> V_17 = V_6 ;
V_1 -> V_171 = F_74 ( V_74 , 2 ) ;
V_1 -> V_76 = V_77 ;
V_1 -> V_23 = F_70 ( V_65 , V_166 ) ;
if ( ! V_1 -> V_23 )
return - V_165 ;
V_1 -> V_172 = F_21 ;
V_1 -> V_68 = 1 ;
V_1 -> V_64 = V_65 ;
V_1 -> V_69 [ 0 ] . V_70 = 0 ;
V_1 -> V_69 [ 0 ] . V_71 = V_65 ;
if ( V_9 -> V_66 )
V_1 -> V_67 = 8 ;
else
V_1 -> V_67 = 1 ;
}
if ( V_9 -> V_139 ) {
V_1 = F_72 ( 0 , V_166 ) ;
if ( ! V_1 )
return - V_165 ;
V_9 -> V_136 = V_1 ;
V_1 -> V_23 = F_70 ( V_9 -> V_139 ,
V_166 ) ;
if ( ! V_1 -> V_23 )
return - V_165 ;
}
return 0 ;
}
static void F_75 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_1 = V_9 -> V_136 ;
if ( V_1 ) {
F_66 ( V_1 -> V_23 ) ;
F_76 ( V_1 ) ;
}
if ( V_9 -> V_49 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_50 ; V_4 ++ ) {
V_1 = V_9 -> V_49 [ V_4 ] ;
if ( V_1 ) {
F_66 ( V_1 -> V_23 ) ;
F_76 ( V_1 ) ;
}
}
F_66 ( V_9 -> V_49 ) ;
}
if ( V_9 -> V_11 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = V_9 -> V_11 [ V_4 ] ;
if ( V_1 ) {
F_66 ( V_1 -> V_23 ) ;
F_76 ( V_1 ) ;
}
}
F_66 ( V_9 -> V_11 ) ;
}
F_66 ( V_9 -> V_106 ) ;
F_66 ( V_9 -> V_22 ) ;
F_66 ( V_9 -> V_100 ) ;
}
static int F_77 ( struct V_5 * V_6 ,
unsigned long V_173 )
{
struct V_174 * V_175 = F_78 ( V_6 ) ;
struct V_73 * V_74 = F_12 ( V_6 ) ;
struct V_8 * V_9 ;
struct V_14 * V_15 ;
int V_55 ;
V_9 = F_79 ( V_6 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_165 ;
F_80 ( & V_9 -> V_16 , 1 ) ;
F_81 ( V_175 , V_9 ) ;
V_9 -> V_66 = ( V_74 -> V_176 == V_177 ) ;
if ( V_9 -> V_66 ) {
V_9 -> V_12 = V_178 ;
V_9 -> V_50 = V_179 ;
V_9 -> V_139 = 512 ;
} else {
V_9 -> V_12 = V_180 ;
V_9 -> V_50 = V_181 ;
}
V_55 = F_69 ( V_6 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_82 ( V_74 , V_175 -> V_182 -> V_183 . V_184 ,
3 ) ;
if ( V_55 < 0 ) {
F_10 ( V_6 -> V_26 ,
L_15 ) ;
return V_55 ;
}
V_55 = F_83 ( V_6 , & V_74 -> V_6 , V_185 ,
F_63 , 0 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = F_84 ( V_6 , ( V_9 -> V_66 ) ? 5 : 4 ) ;
if ( V_55 )
return V_55 ;
V_15 = & V_6 -> V_186 [ 0 ] ;
V_6 -> V_18 = V_15 ;
V_15 -> type = V_187 ;
V_15 -> V_188 = V_189 | V_190 | V_191 ;
V_15 -> V_192 = 8 ;
V_15 -> V_46 = 0x0fff ;
V_15 -> V_193 = 8 ;
V_15 -> V_194 = & V_195 ;
V_15 -> V_196 = F_38 ;
V_15 -> V_197 = F_24 ;
V_15 -> V_198 = F_36 ;
V_15 -> V_199 = F_4 ;
V_15 = & V_6 -> V_186 [ 1 ] ;
V_6 -> V_52 = V_15 ;
V_15 -> type = V_200 ;
V_15 -> V_188 = V_201 | V_190 | V_202 ;
V_15 -> V_192 = V_203 ;
V_15 -> V_46 = 0x0fff ;
V_15 -> V_193 = V_15 -> V_192 ;
V_15 -> V_194 = & V_204 ;
V_15 -> V_197 = F_43 ;
V_15 -> V_198 = F_44 ;
V_15 -> V_199 = F_20 ;
V_15 -> V_196 = F_39 ;
V_15 -> V_205 = F_40 ;
V_15 = & V_6 -> V_186 [ 2 ] ;
V_15 -> type = V_206 ;
V_15 -> V_188 = V_189 | V_201 ;
V_15 -> V_192 = 8 ;
V_15 -> V_46 = 1 ;
V_15 -> V_194 = & V_207 ;
V_15 -> V_208 = F_47 ;
V_15 -> V_209 = F_45 ;
V_15 = & V_6 -> V_186 [ 3 ] ;
V_15 -> type = V_210 ;
V_15 -> V_188 = V_201 | V_189 ;
V_15 -> V_192 = 4 ;
V_15 -> V_46 = 0xffff ;
V_15 -> V_196 = F_49 ;
V_15 -> V_205 = F_50 ;
V_15 -> V_209 = F_51 ;
if ( V_9 -> V_66 ) {
V_15 = & V_6 -> V_186 [ 4 ] ;
V_15 -> type = V_211 ;
V_15 -> V_188 = V_201 | V_212 ;
V_15 -> V_192 = 8 ;
V_15 -> V_46 = V_9 -> V_139 ;
V_15 -> V_205 = F_61 ;
V_15 -> V_209 = F_62 ;
F_58 ( V_6 , V_15 , V_213 ) ;
}
return 0 ;
}
static void F_85 ( struct V_5 * V_6 )
{
struct V_174 * V_175 = F_78 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_81 ( V_175 , NULL ) ;
if ( ! V_9 )
return;
F_5 ( & V_9 -> V_16 ) ;
F_53 ( V_6 , 1 ) ;
F_19 ( V_6 , 1 ) ;
F_3 ( V_6 , 1 ) ;
F_75 ( V_6 ) ;
F_6 ( & V_9 -> V_16 ) ;
}
static int F_86 ( struct V_174 * V_175 ,
const struct V_214 * V_215 )
{
return F_87 ( V_175 , & V_216 , 0 ) ;
}
