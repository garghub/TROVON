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
struct V_19 * V_20 = & V_15 -> V_21 -> V_20 ;
int V_4 , V_22 ;
switch ( V_1 -> V_23 ) {
case 0 :
memcpy ( V_9 -> V_24 , V_1 -> V_25 , V_26 ) ;
break;
case - V_27 :
F_8 ( V_6 -> V_28 , L_1 ) ;
break;
case - V_29 :
case - V_30 :
case - V_31 :
case - V_32 :
if ( V_9 -> V_13 ) {
V_15 -> V_21 -> V_33 |= V_34 ;
V_15 -> V_21 -> V_33 |= V_35 ;
F_9 ( V_6 , V_15 ) ;
F_3 ( V_6 , 0 ) ;
}
return;
default:
if ( V_9 -> V_13 ) {
F_10 ( V_6 -> V_28 ,
L_2 ,
V_1 -> V_23 ) ;
V_15 -> V_21 -> V_33 |= V_34 ;
V_15 -> V_21 -> V_33 |= V_35 ;
F_9 ( V_6 , V_15 ) ;
F_3 ( V_6 , 0 ) ;
}
return;
}
if ( F_11 ( ! V_9 -> V_13 ) ) {
return;
}
V_1 -> V_6 = F_12 ( V_6 ) ;
V_22 = F_13 ( V_1 , V_36 ) ;
if ( F_11 ( V_22 < 0 ) ) {
F_10 ( V_6 -> V_28 ,
L_3 , V_22 ) ;
if ( V_22 == - V_37 )
F_10 ( V_6 -> V_28 ,
L_4 ) ;
V_15 -> V_21 -> V_33 |= V_34 ;
V_15 -> V_21 -> V_33 |= V_35 ;
F_9 ( V_6 , V_15 ) ;
F_3 ( V_6 , 0 ) ;
return;
}
V_9 -> V_38 -- ;
if ( F_14 ( V_9 -> V_38 > 0 ) )
return;
V_9 -> V_38 = V_9 -> V_39 ;
if ( V_20 -> V_40 == V_41 ) {
V_9 -> V_42 -- ;
if ( V_9 -> V_42 < 0 ) {
F_3 ( V_6 , 0 ) ;
V_15 -> V_21 -> V_33 |= V_34 ;
F_9 ( V_6 , V_15 ) ;
return;
}
}
for ( V_4 = 0 ; V_4 < V_20 -> V_43 ; V_4 ++ ) {
unsigned int V_44 = F_15 ( V_20 -> V_45 [ V_4 ] ) ;
T_1 V_46 = F_16 ( V_9 -> V_24 [ V_4 ] ) ;
if ( F_17 ( V_15 , V_44 ) )
V_46 ^= ( ( V_15 -> V_47 + 1 ) >> 1 ) ;
V_22 = F_18 ( V_15 , V_46 ) ;
if ( F_11 ( V_22 == 0 ) ) {
F_3 ( V_6 , 0 ) ;
return;
}
}
V_15 -> V_21 -> V_33 |= V_48 | V_49 ;
F_9 ( V_6 , V_15 ) ;
}
static void F_19 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 && V_9 -> V_50 )
F_1 ( V_9 -> V_50 , V_9 -> V_51 ) ;
V_9 -> V_52 = 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_16 ) ;
F_19 ( V_6 , V_9 -> V_52 ) ;
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_17 ;
struct V_14 * V_15 = V_6 -> V_53 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_21 -> V_20 ;
T_2 * V_54 ;
int V_55 ;
int V_4 ;
switch ( V_1 -> V_23 ) {
case 0 :
break;
case - V_29 :
case - V_30 :
case - V_31 :
case - V_32 :
if ( V_9 -> V_52 ) {
V_15 -> V_21 -> V_33 |= V_34 ;
F_9 ( V_6 , V_15 ) ;
F_19 ( V_6 , 0 ) ;
}
return;
default:
if ( V_9 -> V_52 ) {
F_10 ( V_6 -> V_28 ,
L_5 ,
V_1 -> V_23 ) ;
V_15 -> V_21 -> V_33 |= V_35 ;
V_15 -> V_21 -> V_33 |= V_34 ;
F_9 ( V_6 , V_15 ) ;
F_19 ( V_6 , 0 ) ;
}
return;
}
if ( ! V_9 -> V_52 )
return;
V_9 -> V_56 -- ;
if ( ( int ) V_9 -> V_56 <= 0 ) {
V_9 -> V_56 = V_9 -> V_57 ;
if ( V_20 -> V_40 == V_41 ) {
V_9 -> V_58 -- ;
if ( V_9 -> V_58 < 0 ) {
F_19 ( V_6 , 0 ) ;
V_15 -> V_21 -> V_33 |= V_34 ;
F_9 ( V_6 , V_15 ) ;
return;
}
}
V_54 = V_1 -> V_25 ;
* V_54 ++ = V_20 -> V_43 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_43 ; V_4 ++ ) {
unsigned int V_59 = F_22 ( V_20 -> V_45 [ V_4 ] ) ;
unsigned short V_46 ;
V_55 = F_23 ( V_15 , & V_46 ) ;
if ( V_55 < 0 ) {
F_10 ( V_6 -> V_28 , L_6 ) ;
V_15 -> V_21 -> V_33 |= ( V_34 |
V_60 ) ;
}
* V_54 ++ = V_46 & 0xff ;
* V_54 ++ = ( V_46 >> 8 ) & 0xff ;
* V_54 ++ = V_59 << 6 ;
V_15 -> V_61 [ V_59 ] = V_46 ;
V_15 -> V_21 -> V_33 |= V_48 ;
F_9 ( V_6 , V_15 ) ;
}
}
V_1 -> V_62 = V_63 ;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_1 -> V_23 = 0 ;
if ( V_9 -> V_52 ) {
if ( V_9 -> V_64 )
V_1 -> V_65 = 8 ;
else
V_1 -> V_65 = 1 ;
V_1 -> V_66 = 1 ;
V_1 -> V_67 [ 0 ] . V_68 = 0 ;
V_1 -> V_67 [ 0 ] . V_69 = V_63 ;
V_1 -> V_67 [ 0 ] . V_23 = 0 ;
V_55 = F_13 ( V_1 , V_36 ) ;
if ( V_55 < 0 ) {
F_10 ( V_6 -> V_28 ,
L_7 ,
V_55 ) ;
if ( V_55 == - V_37 )
F_10 ( V_6 -> V_28 ,
L_8 ) ;
V_15 -> V_21 -> V_33 |= V_34 ;
V_15 -> V_21 -> V_33 |= V_35 ;
F_9 ( V_6 , V_15 ) ;
F_19 ( V_6 , 0 ) ;
}
}
}
static int F_24 ( struct V_5 * V_6 ,
struct V_1 * * V_2 , int V_3 ,
int V_70 )
{
struct V_71 * V_72 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_55 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_1 = V_2 [ V_4 ] ;
if ( V_70 )
V_1 -> V_65 = V_9 -> V_73 ;
V_1 -> V_17 = V_6 ;
V_1 -> V_6 = V_72 ;
V_1 -> V_23 = 0 ;
V_1 -> V_74 = V_75 ;
V_55 = F_13 ( V_1 , V_36 ) ;
if ( V_55 )
return V_55 ;
}
return 0 ;
}
static int F_25 ( struct V_5 * V_6 ,
struct V_14 * V_15 , struct V_19 * V_20 )
{
struct V_8 * V_76 = V_6 -> V_10 ;
int V_22 = 0 , V_4 ;
unsigned int V_77 ;
V_22 |= F_26 ( & V_20 -> V_78 , V_79 | V_80 ) ;
V_22 |= F_26 ( & V_20 -> V_81 , V_82 ) ;
V_22 |= F_26 ( & V_20 -> V_83 , V_79 ) ;
V_22 |= F_26 ( & V_20 -> V_84 , V_41 ) ;
V_22 |= F_26 ( & V_20 -> V_40 , V_41 | V_85 ) ;
if ( V_22 )
return 1 ;
V_22 |= F_27 ( V_20 -> V_78 ) ;
V_22 |= F_27 ( V_20 -> V_40 ) ;
if ( V_22 )
return 2 ;
V_22 |= F_28 ( & V_20 -> V_86 , 0 ) ;
if ( V_20 -> V_81 == V_87 )
V_22 |= F_28 ( & V_20 -> V_88 , 0 ) ;
if ( V_20 -> V_81 == V_82 ) {
if ( V_76 -> V_64 ) {
V_4 = 1 ;
while ( V_4 < ( V_20 -> V_43 ) )
V_4 = V_4 * 2 ;
V_22 |= F_29 ( & V_20 -> V_88 ,
1000000 / 8 * V_4 ) ;
V_77 =
( ( unsigned int ) ( V_20 -> V_88 / 125000 ) ) *
125000 ;
} else {
V_22 |= F_29 ( & V_20 -> V_88 ,
1000000 ) ;
V_77 = ( ( unsigned int ) ( V_20 -> V_88 /
1000000 ) ) * 1000000 ;
}
V_22 |= F_28 ( & V_20 -> V_88 ,
V_77 ) ;
}
V_22 |= F_28 ( & V_20 -> V_89 , V_20 -> V_43 ) ;
if ( V_20 -> V_40 == V_41 )
V_22 |= F_29 ( & V_20 -> V_90 , 1 ) ;
else
V_22 |= F_28 ( & V_20 -> V_90 , 0 ) ;
if ( V_22 )
return 3 ;
return 0 ;
}
static T_2 F_30 ( unsigned int V_59 , unsigned int V_44 )
{
T_2 V_91 = ( V_44 <= 1 ) ;
T_2 V_92 = ( ( V_44 % 2 ) == 0 ) ;
return ( V_59 << 4 ) | ( ( V_91 == 1 ) << 2 ) | ( ( V_92 == 1 ) << 3 ) ;
}
static int F_31 ( struct V_5 * V_6 , unsigned int V_93 )
{
struct V_71 * V_72 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_94 ;
V_9 -> V_95 [ 0 ] = V_93 ;
return F_32 ( V_72 , F_33 ( V_72 , 1 ) ,
V_9 -> V_95 , V_96 ,
& V_94 , V_97 ) ;
}
static int F_34 ( struct V_5 * V_6 , unsigned int V_98 )
{
struct V_71 * V_72 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_55 ;
int V_99 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_100 ; V_4 ++ ) {
V_55 = F_32 ( V_72 , F_35 ( V_72 , 8 ) ,
V_9 -> V_101 , V_102 ,
& V_99 , V_97 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_16 ( V_9 -> V_101 [ 0 ] ) == V_98 )
return V_55 ;
}
return - V_103 ;
}
static int F_36 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_104 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_21 -> V_20 ;
int V_55 ;
if ( V_104 != V_20 -> V_86 )
return - V_105 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_13 ) {
V_9 -> V_13 = 1 ;
V_55 = F_24 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_55 < 0 ) {
V_9 -> V_13 = 0 ;
goto V_106;
}
V_15 -> V_21 -> V_107 = NULL ;
} else {
V_55 = - V_108 ;
}
V_106:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ;
}
static int F_37 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_21 -> V_20 ;
int V_109 = V_20 -> V_43 ;
int V_55 = - V_108 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 )
goto V_110;
V_15 -> V_21 -> V_111 = 0 ;
V_9 -> V_95 [ 1 ] = V_109 ;
for ( V_4 = 0 ; V_4 < V_109 ; ++ V_4 ) {
unsigned int V_59 = F_22 ( V_20 -> V_45 [ V_4 ] ) ;
unsigned int V_44 = F_15 ( V_20 -> V_45 [ V_4 ] ) ;
V_9 -> V_95 [ V_4 + 2 ] = F_30 ( V_59 , V_44 ) ;
}
V_55 = F_31 ( V_6 , V_112 ) ;
if ( V_55 < 0 )
goto V_110;
if ( V_9 -> V_64 ) {
V_9 -> V_73 = 1 ;
while ( V_9 -> V_73 < V_109 )
V_9 -> V_73 *= 2 ;
V_9 -> V_39 = V_20 -> V_88 /
( 125000 * V_9 -> V_73 ) ;
} else {
V_9 -> V_73 = 1 ;
V_9 -> V_39 = V_20 -> V_88 / 1000000 ;
}
if ( V_9 -> V_39 < 1 ) {
V_55 = - V_105 ;
goto V_110;
}
V_9 -> V_38 = V_9 -> V_39 ;
if ( V_20 -> V_40 == V_41 ) {
V_9 -> V_42 = V_20 -> V_90 ;
} else {
V_9 -> V_42 = 0 ;
}
if ( V_20 -> V_78 == V_79 ) {
V_9 -> V_13 = 1 ;
V_55 = F_24 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_55 < 0 ) {
V_9 -> V_13 = 0 ;
goto V_110;
}
V_15 -> V_21 -> V_107 = NULL ;
} else {
V_15 -> V_21 -> V_107 = F_36 ;
}
V_110:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ;
}
static int F_38 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_113 * V_114 ,
unsigned int * V_115 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_59 = F_22 ( V_114 -> V_116 ) ;
unsigned int V_44 = F_15 ( V_114 -> V_116 ) ;
unsigned int V_46 ;
int V_55 = - V_108 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 )
goto V_117;
V_9 -> V_95 [ 1 ] = F_30 ( V_59 , V_44 ) ;
V_55 = F_31 ( V_6 , V_118 ) ;
if ( V_55 < 0 )
goto V_117;
for ( V_4 = 0 ; V_4 < V_114 -> V_119 ; V_4 ++ ) {
V_55 = F_34 ( V_6 , V_118 ) ;
if ( V_55 < 0 )
goto V_117;
V_46 = F_16 ( V_9 -> V_101 [ 1 ] ) ;
if ( F_17 ( V_15 , V_44 ) )
V_46 ^= ( ( V_15 -> V_47 + 1 ) >> 1 ) ;
V_115 [ V_4 ] = V_46 ;
}
V_117:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ? V_55 : V_114 -> V_119 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_113 * V_114 ,
unsigned int * V_115 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_55 ;
F_5 ( & V_9 -> V_16 ) ;
V_55 = F_40 ( V_6 , V_15 , V_114 , V_115 ) ;
F_6 ( & V_9 -> V_16 ) ;
return V_55 ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_113 * V_114 ,
unsigned int * V_115 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_59 = F_22 ( V_114 -> V_116 ) ;
unsigned int V_46 = V_15 -> V_61 [ V_59 ] ;
T_3 * V_91 = ( T_3 * ) & V_9 -> V_95 [ 2 ] ;
int V_55 = - V_108 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_52 )
goto V_120;
V_9 -> V_95 [ 1 ] = 1 ;
V_9 -> V_95 [ 4 ] = V_59 << 6 ;
for ( V_4 = 0 ; V_4 < V_114 -> V_119 ; V_4 ++ ) {
V_46 = V_115 [ V_4 ] ;
* V_91 = F_42 ( V_46 ) ;
V_55 = F_31 ( V_6 , V_121 ) ;
if ( V_55 < 0 )
goto V_120;
V_15 -> V_61 [ V_59 ] = V_46 ;
}
V_120:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ? V_55 : V_114 -> V_119 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_104 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_21 -> V_20 ;
int V_55 ;
if ( V_104 != V_20 -> V_86 )
return - V_105 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_52 ) {
V_9 -> V_52 = 1 ;
V_55 = F_24 ( V_6 , V_9 -> V_50 ,
V_9 -> V_51 , 0 ) ;
if ( V_55 < 0 ) {
V_9 -> V_52 = 0 ;
goto V_122;
}
V_15 -> V_21 -> V_107 = NULL ;
} else {
V_55 = - V_108 ;
}
V_122:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ;
}
static int F_44 ( struct V_5 * V_6 ,
struct V_14 * V_15 , struct V_19 * V_20 )
{
struct V_8 * V_76 = V_6 -> V_10 ;
int V_22 = 0 ;
unsigned int V_123 ;
if ( ! V_76 )
return - V_103 ;
V_22 |= F_26 ( & V_20 -> V_78 , V_79 | V_80 ) ;
if ( 0 ) {
V_123 = V_87 ;
} else {
V_123 = V_82 ;
}
V_22 |= F_26 ( & V_20 -> V_81 , V_123 ) ;
if ( 0 ) {
V_123 = V_82 ;
} else {
V_123 = V_79 ;
}
V_22 |= F_26 ( & V_20 -> V_83 , V_123 ) ;
V_22 |= F_26 ( & V_20 -> V_84 , V_41 ) ;
V_22 |= F_26 ( & V_20 -> V_40 , V_41 | V_85 ) ;
if ( V_22 )
return 1 ;
V_22 |= F_27 ( V_20 -> V_78 ) ;
V_22 |= F_27 ( V_20 -> V_40 ) ;
if ( V_22 )
return 2 ;
V_22 |= F_28 ( & V_20 -> V_86 , 0 ) ;
if ( V_20 -> V_81 == V_87 )
V_22 |= F_28 ( & V_20 -> V_88 , 0 ) ;
if ( V_20 -> V_81 == V_82 )
V_22 |= F_29 ( & V_20 -> V_88 ,
1000000 ) ;
if ( V_20 -> V_83 == V_82 )
V_22 |= F_29 ( & V_20 -> V_124 , 125000 ) ;
V_22 |= F_28 ( & V_20 -> V_89 , V_20 -> V_43 ) ;
if ( V_20 -> V_40 == V_41 )
V_22 |= F_29 ( & V_20 -> V_90 , 1 ) ;
else
V_22 |= F_28 ( & V_20 -> V_90 , 0 ) ;
if ( V_22 )
return 3 ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_21 -> V_20 ;
int V_55 = - V_108 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_52 )
goto V_125;
V_15 -> V_21 -> V_111 = 0 ;
if ( 0 ) {
V_9 -> V_57 = V_20 -> V_124 / 125000 ;
} else {
V_9 -> V_57 = V_20 -> V_88 / 1000000 ;
if ( V_9 -> V_57 < 1 ) {
V_55 = - V_105 ;
goto V_125;
}
}
V_9 -> V_56 = V_9 -> V_57 ;
if ( V_20 -> V_40 == V_41 ) {
if ( 0 ) {
V_9 -> V_58 = V_20 -> V_90 *
V_20 -> V_89 ;
} else {
V_9 -> V_58 = V_20 -> V_90 ;
}
} else {
V_9 -> V_58 = 0 ;
}
if ( V_20 -> V_78 == V_79 ) {
V_9 -> V_52 = 1 ;
V_55 = F_24 ( V_6 , V_9 -> V_50 ,
V_9 -> V_51 , 0 ) ;
if ( V_55 < 0 ) {
V_9 -> V_52 = 0 ;
goto V_125;
}
V_15 -> V_21 -> V_107 = NULL ;
} else {
V_15 -> V_21 -> V_107 = F_43 ;
}
V_125:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ;
}
static int F_46 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_113 * V_114 ,
unsigned int * V_115 )
{
int V_55 ;
V_55 = F_47 ( V_6 , V_15 , V_114 , V_115 , 0 ) ;
if ( V_55 )
return V_55 ;
return V_114 -> V_119 ;
}
static int F_48 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_113 * V_114 ,
unsigned int * V_115 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_55 ;
F_5 ( & V_9 -> V_16 ) ;
F_49 ( V_15 , V_115 ) ;
V_9 -> V_95 [ 1 ] = V_15 -> V_126 ;
V_9 -> V_95 [ 2 ] = V_15 -> V_127 ;
V_55 = F_31 ( V_6 , V_128 ) ;
if ( V_55 < 0 )
goto V_129;
V_55 = F_34 ( V_6 , V_128 ) ;
if ( V_55 < 0 )
goto V_129;
V_115 [ 1 ] = F_16 ( V_9 -> V_101 [ 1 ] ) ;
V_129:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ? V_55 : V_114 -> V_119 ;
}
static int F_50 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_113 * V_114 ,
unsigned int * V_115 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_59 = F_22 ( V_114 -> V_116 ) ;
int V_55 = 0 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
for ( V_4 = 0 ; V_4 < V_114 -> V_119 ; V_4 ++ ) {
V_55 = F_31 ( V_6 , V_130 ) ;
if ( V_55 < 0 )
goto V_131;
V_55 = F_34 ( V_6 , V_130 ) ;
if ( V_55 < 0 )
goto V_131;
V_115 [ V_4 ] = F_16 ( V_9 -> V_101 [ V_59 + 1 ] ) ;
}
V_131:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ? V_55 : V_114 -> V_119 ;
}
static int F_51 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_113 * V_114 ,
unsigned int * V_115 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_59 = F_22 ( V_114 -> V_116 ) ;
T_3 * V_91 = ( T_3 * ) & V_9 -> V_95 [ 2 ] ;
int V_55 = 0 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
V_9 -> V_95 [ 1 ] = V_59 ;
for ( V_4 = 0 ; V_4 < V_114 -> V_119 ; V_4 ++ ) {
* V_91 = F_42 ( V_115 [ V_4 ] ) ;
V_55 = F_31 ( V_6 , V_132 ) ;
if ( V_55 < 0 )
break;
}
F_6 ( & V_9 -> V_16 ) ;
return V_55 ? V_55 : V_114 -> V_119 ;
}
static int F_52 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_113 * V_114 , unsigned int * V_115 )
{
return 2 ;
}
static void F_53 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_2 ( V_9 -> V_133 ) ;
}
static void F_54 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 )
F_53 ( V_6 ) ;
V_9 -> V_134 = 0 ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_55 ;
F_5 ( & V_9 -> V_16 ) ;
F_54 ( V_6 , V_9 -> V_134 ) ;
V_55 = F_31 ( V_6 , V_135 ) ;
F_6 ( & V_9 -> V_16 ) ;
return V_55 ;
}
static void F_56 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_17 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_55 ;
switch ( V_1 -> V_23 ) {
case 0 :
break;
case - V_29 :
case - V_30 :
case - V_31 :
case - V_32 :
if ( V_9 -> V_134 )
F_54 ( V_6 , 0 ) ;
return;
default:
if ( V_9 -> V_134 ) {
F_10 ( V_6 -> V_28 ,
L_9 ,
V_1 -> V_23 ) ;
F_54 ( V_6 , 0 ) ;
}
return;
}
if ( ! V_9 -> V_134 )
return;
V_1 -> V_62 = V_9 -> V_136 ;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_1 -> V_23 = 0 ;
if ( V_9 -> V_134 ) {
V_55 = F_13 ( V_1 , V_36 ) ;
if ( V_55 < 0 ) {
F_10 ( V_6 -> V_28 ,
L_10 ,
V_55 ) ;
if ( V_55 == - V_37 )
F_10 ( V_6 -> V_28 ,
L_8 ) ;
F_54 ( V_6 , 0 ) ;
}
}
}
static int F_57 ( struct V_5 * V_6 )
{
struct V_71 * V_72 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 = V_9 -> V_133 ;
F_58 ( V_1 , V_72 , F_33 ( V_72 , 4 ) ,
V_1 -> V_25 ,
V_9 -> V_136 ,
F_56 ,
V_6 ) ;
return F_13 ( V_1 , V_36 ) ;
}
static int F_59 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_137 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_138 = 255 ;
if ( V_137 < V_139 )
return - V_140 ;
V_138 = ( V_137 / ( 6 * 512 * 1000 / 33 ) ) - 6 ;
if ( V_138 > 255 )
return - V_140 ;
V_9 -> V_141 = V_138 ;
V_9 -> V_142 = V_137 ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_55 = 0 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_134 )
goto V_143;
V_9 -> V_95 [ 1 ] = V_9 -> V_141 ;
V_55 = F_31 ( V_6 , V_144 ) ;
if ( V_55 < 0 )
goto V_143;
memset ( V_9 -> V_133 -> V_25 , 0 , V_9 -> V_136 ) ;
V_9 -> V_134 = 1 ;
V_55 = F_57 ( V_6 ) ;
if ( V_55 < 0 )
V_9 -> V_134 = 0 ;
V_143:
F_6 ( & V_9 -> V_16 ) ;
return V_55 ;
}
static void F_61 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_59 ,
unsigned int V_145 ,
unsigned int V_146 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
char V_147 = ( 1 << V_59 ) ;
char V_148 = ( 16 << V_59 ) ;
char * V_149 = ( char * ) ( V_9 -> V_133 -> V_25 ) ;
int V_150 = V_9 -> V_136 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_150 ; V_4 ++ ) {
char V_151 = * V_149 ;
V_151 &= ~ V_147 ;
if ( V_4 < V_145 )
V_151 |= V_147 ;
if ( ! V_146 )
V_151 &= ~ V_148 ;
else
V_151 |= V_148 ;
* V_149 ++ = V_151 ;
}
}
static int F_62 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_113 * V_114 ,
unsigned int * V_115 )
{
unsigned int V_59 = F_22 ( V_114 -> V_116 ) ;
if ( V_114 -> V_119 != 1 )
return - V_105 ;
F_61 ( V_6 , V_15 , V_59 , V_115 [ 0 ] , 0 ) ;
return V_114 -> V_119 ;
}
static int F_63 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_113 * V_114 ,
unsigned int * V_115 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_59 = F_22 ( V_114 -> V_116 ) ;
switch ( V_115 [ 0 ] ) {
case V_152 :
if ( V_115 [ 1 ] != 0 )
return - V_105 ;
return F_60 ( V_6 , V_15 ) ;
case V_153 :
return F_55 ( V_6 , V_15 ) ;
case V_154 :
V_115 [ 1 ] = V_9 -> V_134 ;
return 0 ;
case V_155 :
return F_59 ( V_6 , V_15 , V_115 [ 1 ] ) ;
case V_156 :
V_115 [ 1 ] = V_9 -> V_142 ;
return 0 ;
case V_157 :
F_61 ( V_6 , V_15 , V_59 , V_115 [ 1 ] , ( V_115 [ 2 ] != 0 ) ) ;
return 0 ;
case V_158 :
return - V_105 ;
}
return - V_105 ;
}
static int F_64 ( struct V_5 * V_6 ,
const T_4 * V_115 , T_5 V_159 ,
unsigned long V_17 )
{
struct V_71 * V_72 = F_12 ( V_6 ) ;
T_2 * V_149 ;
T_2 * V_160 ;
int V_55 ;
if ( ! V_115 )
return 0 ;
if ( V_159 > V_161 ) {
F_10 ( V_6 -> V_28 ,
L_11 ) ;
return - V_162 ;
}
V_149 = F_65 ( V_115 , V_159 , V_163 ) ;
if ( ! V_149 )
return - V_162 ;
V_160 = F_66 ( 1 , V_163 ) ;
if ( ! V_160 ) {
F_67 ( V_149 ) ;
return - V_162 ;
}
* V_160 = 1 ;
V_55 = F_68 ( V_72 , F_69 ( V_72 , 0 ) ,
V_164 ,
V_165 ,
V_166 , 0x0000 ,
V_160 , 1 ,
V_97 ) ;
if ( V_55 < 0 ) {
F_10 ( V_6 -> V_28 , L_12 ) ;
goto V_167;
}
V_55 = F_68 ( V_72 , F_69 ( V_72 , 0 ) ,
V_164 ,
V_165 ,
0 , 0x0000 ,
V_149 , V_159 ,
V_97 ) ;
if ( V_55 < 0 ) {
F_10 ( V_6 -> V_28 , L_13 ) ;
goto V_167;
}
* V_160 = 0 ;
V_55 = F_68 ( V_72 , F_69 ( V_72 , 0 ) ,
V_164 ,
V_165 ,
V_166 , 0x0000 ,
V_160 , 1 ,
V_97 ) ;
if ( V_55 < 0 )
F_10 ( V_6 -> V_28 , L_14 ) ;
V_167:
F_67 ( V_160 ) ;
F_67 ( V_149 ) ;
return V_55 ;
}
static int F_70 ( struct V_5 * V_6 )
{
struct V_71 * V_72 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_9 -> V_95 = F_71 ( V_96 , V_163 ) ;
V_9 -> V_24 = F_71 ( V_26 , V_163 ) ;
V_9 -> V_101 = F_71 ( V_102 , V_163 ) ;
V_9 -> V_11 = F_72 ( V_9 -> V_12 , sizeof( void * ) ,
V_163 ) ;
V_9 -> V_50 = F_72 ( V_9 -> V_51 , sizeof( void * ) ,
V_163 ) ;
if ( ! V_9 -> V_95 || ! V_9 -> V_24 || ! V_9 -> V_101 ||
! V_9 -> V_11 || ! V_9 -> V_50 )
return - V_162 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = F_73 ( 1 , V_163 ) ;
if ( ! V_1 )
return - V_162 ;
V_9 -> V_11 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_72 ;
V_1 -> V_17 = V_6 ;
V_1 -> V_168 = F_74 ( V_72 , 6 ) ;
V_1 -> V_74 = V_75 ;
V_1 -> V_25 = F_71 ( V_26 , V_163 ) ;
if ( ! V_1 -> V_25 )
return - V_162 ;
V_1 -> V_169 = F_7 ;
V_1 -> V_66 = 1 ;
V_1 -> V_62 = V_26 ;
V_1 -> V_67 [ 0 ] . V_68 = 0 ;
V_1 -> V_67 [ 0 ] . V_69 = V_26 ;
}
for ( V_4 = 0 ; V_4 < V_9 -> V_51 ; V_4 ++ ) {
V_1 = F_73 ( 1 , V_163 ) ;
if ( ! V_1 )
return - V_162 ;
V_9 -> V_50 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_72 ;
V_1 -> V_17 = V_6 ;
V_1 -> V_168 = F_75 ( V_72 , 2 ) ;
V_1 -> V_74 = V_75 ;
V_1 -> V_25 = F_71 ( V_63 , V_163 ) ;
if ( ! V_1 -> V_25 )
return - V_162 ;
V_1 -> V_169 = F_21 ;
V_1 -> V_66 = 1 ;
V_1 -> V_62 = V_63 ;
V_1 -> V_67 [ 0 ] . V_68 = 0 ;
V_1 -> V_67 [ 0 ] . V_69 = V_63 ;
if ( V_9 -> V_64 )
V_1 -> V_65 = 8 ;
else
V_1 -> V_65 = 1 ;
}
if ( V_9 -> V_136 ) {
V_1 = F_73 ( 0 , V_163 ) ;
if ( ! V_1 )
return - V_162 ;
V_9 -> V_133 = V_1 ;
V_1 -> V_25 = F_71 ( V_9 -> V_136 ,
V_163 ) ;
if ( ! V_1 -> V_25 )
return - V_162 ;
}
return 0 ;
}
static void F_76 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_1 = V_9 -> V_133 ;
if ( V_1 ) {
F_67 ( V_1 -> V_25 ) ;
F_77 ( V_1 ) ;
}
if ( V_9 -> V_50 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_51 ; V_4 ++ ) {
V_1 = V_9 -> V_50 [ V_4 ] ;
if ( V_1 ) {
F_67 ( V_1 -> V_25 ) ;
F_77 ( V_1 ) ;
}
}
F_67 ( V_9 -> V_50 ) ;
}
if ( V_9 -> V_11 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = V_9 -> V_11 [ V_4 ] ;
if ( V_1 ) {
F_67 ( V_1 -> V_25 ) ;
F_77 ( V_1 ) ;
}
}
F_67 ( V_9 -> V_11 ) ;
}
F_67 ( V_9 -> V_101 ) ;
F_67 ( V_9 -> V_24 ) ;
F_67 ( V_9 -> V_95 ) ;
}
static int F_78 ( struct V_5 * V_6 ,
unsigned long V_170 )
{
struct V_171 * V_172 = F_79 ( V_6 ) ;
struct V_71 * V_72 = F_12 ( V_6 ) ;
struct V_8 * V_9 ;
struct V_14 * V_15 ;
int V_55 ;
V_9 = F_80 ( V_6 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_162 ;
F_81 ( & V_9 -> V_16 , 1 ) ;
F_82 ( V_172 , V_9 ) ;
V_9 -> V_64 = ( V_72 -> V_173 == V_174 ) ;
if ( V_9 -> V_64 ) {
V_9 -> V_12 = V_175 ;
V_9 -> V_51 = V_176 ;
V_9 -> V_136 = 512 ;
} else {
V_9 -> V_12 = V_177 ;
V_9 -> V_51 = V_178 ;
}
V_55 = F_70 ( V_6 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_83 ( V_72 , V_172 -> V_179 -> V_180 . V_181 ,
3 ) ;
if ( V_55 < 0 ) {
F_10 ( V_6 -> V_28 ,
L_15 ) ;
return V_55 ;
}
V_55 = F_84 ( V_6 , & V_72 -> V_6 , V_182 ,
F_64 , 0 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = F_85 ( V_6 , ( V_9 -> V_64 ) ? 5 : 4 ) ;
if ( V_55 )
return V_55 ;
V_15 = & V_6 -> V_183 [ 0 ] ;
V_6 -> V_18 = V_15 ;
V_15 -> type = V_184 ;
V_15 -> V_185 = V_186 | V_187 | V_188 ;
V_15 -> V_189 = 8 ;
V_15 -> V_47 = 0x0fff ;
V_15 -> V_190 = 8 ;
V_15 -> V_191 = & V_192 ;
V_15 -> V_193 = F_38 ;
V_15 -> V_194 = F_25 ;
V_15 -> V_195 = F_37 ;
V_15 -> V_196 = F_4 ;
V_15 = & V_6 -> V_183 [ 1 ] ;
V_6 -> V_53 = V_15 ;
V_15 -> type = V_197 ;
V_15 -> V_185 = V_198 | V_187 | V_199 ;
V_15 -> V_189 = 4 ;
V_15 -> V_47 = 0x0fff ;
V_15 -> V_190 = V_15 -> V_189 ;
V_15 -> V_191 = & V_200 ;
V_15 -> V_194 = F_44 ;
V_15 -> V_195 = F_45 ;
V_15 -> V_196 = F_20 ;
V_15 -> V_193 = F_39 ;
V_15 -> V_201 = F_41 ;
V_55 = F_86 ( V_15 ) ;
if ( V_55 )
return V_55 ;
V_15 = & V_6 -> V_183 [ 2 ] ;
V_15 -> type = V_202 ;
V_15 -> V_185 = V_186 | V_198 ;
V_15 -> V_189 = 8 ;
V_15 -> V_47 = 1 ;
V_15 -> V_191 = & V_203 ;
V_15 -> V_204 = F_48 ;
V_15 -> V_205 = F_46 ;
V_15 = & V_6 -> V_183 [ 3 ] ;
V_15 -> type = V_206 ;
V_15 -> V_185 = V_198 | V_186 ;
V_15 -> V_189 = 4 ;
V_15 -> V_47 = 0xffff ;
V_15 -> V_193 = F_50 ;
V_15 -> V_201 = F_51 ;
V_15 -> V_205 = F_52 ;
if ( V_9 -> V_64 ) {
V_15 = & V_6 -> V_183 [ 4 ] ;
V_15 -> type = V_207 ;
V_15 -> V_185 = V_198 | V_208 ;
V_15 -> V_189 = 8 ;
V_15 -> V_47 = V_9 -> V_136 ;
V_15 -> V_201 = F_62 ;
V_15 -> V_205 = F_63 ;
F_59 ( V_6 , V_15 , V_209 ) ;
}
return 0 ;
}
static void F_87 ( struct V_5 * V_6 )
{
struct V_171 * V_172 = F_79 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_82 ( V_172 , NULL ) ;
if ( ! V_9 )
return;
F_5 ( & V_9 -> V_16 ) ;
F_54 ( V_6 , 1 ) ;
F_19 ( V_6 , 1 ) ;
F_3 ( V_6 , 1 ) ;
F_76 ( V_6 ) ;
F_6 ( & V_9 -> V_16 ) ;
}
static int F_88 ( struct V_171 * V_172 ,
const struct V_210 * V_211 )
{
return F_89 ( V_172 , & V_212 , 0 ) ;
}
