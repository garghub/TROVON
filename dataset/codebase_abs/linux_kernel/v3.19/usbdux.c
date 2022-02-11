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
int V_21 ;
int V_4 ;
V_9 -> V_22 -- ;
if ( V_9 -> V_22 == 0 ) {
V_9 -> V_22 = V_9 -> V_23 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_24 ; V_4 ++ ) {
unsigned int V_25 = F_8 ( V_20 -> V_26 [ V_4 ] ) ;
T_1 V_27 = F_9 ( V_9 -> V_28 [ V_4 ] ) ;
if ( F_10 ( V_15 , V_25 ) )
V_27 ^= ( ( V_15 -> V_29 + 1 ) >> 1 ) ;
if ( ! F_11 ( V_15 , & V_27 , 1 ) )
return;
}
if ( V_20 -> V_30 == V_31 &&
V_18 -> V_32 >= V_20 -> V_33 )
V_18 -> V_34 |= V_35 ;
}
if ( ! ( V_18 -> V_34 & V_36 ) ) {
V_1 -> V_6 = F_12 ( V_6 ) ;
V_21 = F_13 ( V_1 , V_37 ) ;
if ( V_21 < 0 ) {
F_14 ( V_6 -> V_38 ,
L_1 ,
V_21 ) ;
if ( V_21 == - V_39 )
F_14 ( V_6 -> V_38 ,
L_2 ) ;
V_18 -> V_34 |= V_40 ;
}
}
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_41 ;
struct V_14 * V_15 = V_6 -> V_42 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_8 * V_9 = V_6 -> V_10 ;
if ( ! V_9 -> V_13 )
return;
switch ( V_1 -> V_43 ) {
case 0 :
memcpy ( V_9 -> V_28 , V_1 -> V_44 , V_45 ) ;
F_7 ( V_6 , V_15 , V_1 ) ;
break;
case - V_46 :
F_16 ( V_6 -> V_38 , L_3 ) ;
F_7 ( V_6 , V_15 , V_1 ) ;
break;
case - V_47 :
case - V_48 :
case - V_49 :
case - V_50 :
V_18 -> V_34 |= V_40 ;
break;
default:
F_14 ( V_6 -> V_38 ,
L_4 ,
V_1 -> V_43 ) ;
V_18 -> V_34 |= V_40 ;
break;
}
if ( V_18 -> V_34 & V_36 )
F_3 ( V_6 , 0 ) ;
F_17 ( V_6 , V_15 ) ;
}
static void F_18 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 && V_9 -> V_51 )
F_1 ( V_9 -> V_51 , V_9 -> V_52 ) ;
V_9 -> V_53 = 0 ;
}
static int F_19 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_16 ) ;
F_18 ( V_6 , V_9 -> V_53 ) ;
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static void F_20 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_1 * V_1 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
T_2 * V_54 ;
int V_21 ;
int V_4 ;
V_9 -> V_55 -- ;
if ( V_9 -> V_55 == 0 ) {
V_9 -> V_55 = V_9 -> V_56 ;
if ( V_20 -> V_30 == V_31 &&
V_18 -> V_32 >= V_20 -> V_33 ) {
V_18 -> V_34 |= V_35 ;
return;
}
V_54 = V_1 -> V_44 ;
* V_54 ++ = V_20 -> V_24 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_24 ; V_4 ++ ) {
unsigned int V_57 = F_21 ( V_20 -> V_26 [ V_4 ] ) ;
unsigned short V_27 ;
if ( ! F_22 ( V_15 , & V_27 , 1 ) ) {
F_14 ( V_6 -> V_38 , L_5 ) ;
V_18 -> V_34 |= V_58 ;
return;
}
* V_54 ++ = V_27 & 0xff ;
* V_54 ++ = ( V_27 >> 8 ) & 0xff ;
* V_54 ++ = V_57 << 6 ;
V_15 -> V_59 [ V_57 ] = V_27 ;
}
}
if ( ! ( V_18 -> V_34 & V_36 ) ) {
V_1 -> V_60 = V_61 ;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_1 -> V_43 = 0 ;
if ( V_9 -> V_62 )
V_1 -> V_63 = 8 ;
else
V_1 -> V_63 = 1 ;
V_1 -> V_64 = 1 ;
V_1 -> V_65 [ 0 ] . V_66 = 0 ;
V_1 -> V_65 [ 0 ] . V_67 = V_61 ;
V_1 -> V_65 [ 0 ] . V_43 = 0 ;
V_21 = F_13 ( V_1 , V_37 ) ;
if ( V_21 < 0 ) {
F_14 ( V_6 -> V_38 ,
L_6 ,
V_21 ) ;
if ( V_21 == - V_39 )
F_14 ( V_6 -> V_38 ,
L_7 ) ;
V_18 -> V_34 |= V_40 ;
}
}
}
static void F_23 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_41 ;
struct V_14 * V_15 = V_6 -> V_68 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_8 * V_9 = V_6 -> V_10 ;
if ( ! V_9 -> V_53 )
return;
switch ( V_1 -> V_43 ) {
case 0 :
F_20 ( V_6 , V_15 , V_1 ) ;
break;
case - V_47 :
case - V_48 :
case - V_49 :
case - V_50 :
V_18 -> V_34 |= V_40 ;
break;
default:
F_14 ( V_6 -> V_38 ,
L_8 ,
V_1 -> V_43 ) ;
V_18 -> V_34 |= V_40 ;
break;
}
if ( V_18 -> V_34 & V_36 )
F_18 ( V_6 , 0 ) ;
F_17 ( V_6 , V_15 ) ;
}
static int F_24 ( struct V_5 * V_6 ,
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
V_1 -> V_63 = V_9 -> V_72 ;
V_1 -> V_41 = V_6 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_43 = 0 ;
V_1 -> V_73 = V_74 ;
V_21 = F_13 ( V_1 , V_37 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_25 ( struct V_5 * V_6 ,
struct V_14 * V_15 , struct V_19 * V_20 )
{
struct V_8 * V_75 = V_6 -> V_10 ;
int V_76 = 0 , V_4 ;
unsigned int V_77 ;
V_76 |= F_26 ( & V_20 -> V_78 , V_79 | V_80 ) ;
V_76 |= F_26 ( & V_20 -> V_81 , V_82 ) ;
V_76 |= F_26 ( & V_20 -> V_83 , V_79 ) ;
V_76 |= F_26 ( & V_20 -> V_84 , V_31 ) ;
V_76 |= F_26 ( & V_20 -> V_30 , V_31 | V_85 ) ;
if ( V_76 )
return 1 ;
V_76 |= F_27 ( V_20 -> V_78 ) ;
V_76 |= F_27 ( V_20 -> V_30 ) ;
if ( V_76 )
return 2 ;
V_76 |= F_28 ( & V_20 -> V_86 , 0 ) ;
if ( V_20 -> V_81 == V_87 )
V_76 |= F_28 ( & V_20 -> V_88 , 0 ) ;
if ( V_20 -> V_81 == V_82 ) {
if ( V_75 -> V_62 ) {
V_4 = 1 ;
while ( V_4 < ( V_20 -> V_24 ) )
V_4 = V_4 * 2 ;
V_76 |= F_29 ( & V_20 -> V_88 ,
1000000 / 8 * V_4 ) ;
V_77 =
( ( unsigned int ) ( V_20 -> V_88 / 125000 ) ) *
125000 ;
} else {
V_76 |= F_29 ( & V_20 -> V_88 ,
1000000 ) ;
V_77 = ( ( unsigned int ) ( V_20 -> V_88 /
1000000 ) ) * 1000000 ;
}
V_76 |= F_28 ( & V_20 -> V_88 ,
V_77 ) ;
}
V_76 |= F_28 ( & V_20 -> V_89 , V_20 -> V_24 ) ;
if ( V_20 -> V_30 == V_31 )
V_76 |= F_29 ( & V_20 -> V_33 , 1 ) ;
else
V_76 |= F_28 ( & V_20 -> V_33 , 0 ) ;
if ( V_76 )
return 3 ;
return 0 ;
}
static T_2 F_30 ( unsigned int V_57 , unsigned int V_25 )
{
T_2 V_90 = ( V_25 <= 1 ) ;
T_2 V_91 = ( ( V_25 % 2 ) == 0 ) ;
return ( V_57 << 4 ) | ( ( V_90 == 1 ) << 2 ) | ( ( V_91 == 1 ) << 3 ) ;
}
static int F_31 ( struct V_5 * V_6 , unsigned int V_92 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_93 ;
V_9 -> V_94 [ 0 ] = V_92 ;
return F_32 ( V_71 , F_33 ( V_71 , 1 ) ,
V_9 -> V_94 , V_95 ,
& V_93 , V_96 ) ;
}
static int F_34 ( struct V_5 * V_6 , unsigned int V_97 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
int V_98 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_99 ; V_4 ++ ) {
V_21 = F_32 ( V_71 , F_35 ( V_71 , 8 ) ,
V_9 -> V_100 , V_101 ,
& V_98 , V_96 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( F_9 ( V_9 -> V_100 [ 0 ] ) == V_97 )
return V_21 ;
}
return - V_102 ;
}
static int F_36 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_103 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_21 ;
if ( V_103 != V_20 -> V_86 )
return - V_104 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_13 ) {
V_9 -> V_13 = 1 ;
V_21 = F_24 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_21 < 0 ) {
V_9 -> V_13 = 0 ;
goto V_105;
}
V_15 -> V_18 -> V_106 = NULL ;
} else {
V_21 = - V_107 ;
}
V_105:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static int F_37 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_108 = V_20 -> V_24 ;
int V_21 = - V_107 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 )
goto V_109;
V_9 -> V_94 [ 1 ] = V_108 ;
for ( V_4 = 0 ; V_4 < V_108 ; ++ V_4 ) {
unsigned int V_57 = F_21 ( V_20 -> V_26 [ V_4 ] ) ;
unsigned int V_25 = F_8 ( V_20 -> V_26 [ V_4 ] ) ;
V_9 -> V_94 [ V_4 + 2 ] = F_30 ( V_57 , V_25 ) ;
}
V_21 = F_31 ( V_6 , V_110 ) ;
if ( V_21 < 0 )
goto V_109;
if ( V_9 -> V_62 ) {
V_9 -> V_72 = 1 ;
while ( V_9 -> V_72 < V_108 )
V_9 -> V_72 *= 2 ;
V_9 -> V_23 = V_20 -> V_88 /
( 125000 * V_9 -> V_72 ) ;
} else {
V_9 -> V_72 = 1 ;
V_9 -> V_23 = V_20 -> V_88 / 1000000 ;
}
if ( V_9 -> V_23 < 1 ) {
V_21 = - V_104 ;
goto V_109;
}
V_9 -> V_22 = V_9 -> V_23 ;
if ( V_20 -> V_78 == V_79 ) {
V_9 -> V_13 = 1 ;
V_21 = F_24 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_21 < 0 ) {
V_9 -> V_13 = 0 ;
goto V_109;
}
V_15 -> V_18 -> V_106 = NULL ;
} else {
V_15 -> V_18 -> V_106 = F_36 ;
}
V_109:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static int F_38 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_57 = F_21 ( V_112 -> V_114 ) ;
unsigned int V_25 = F_8 ( V_112 -> V_114 ) ;
unsigned int V_27 ;
int V_21 = - V_107 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 )
goto V_115;
V_9 -> V_94 [ 1 ] = F_30 ( V_57 , V_25 ) ;
V_21 = F_31 ( V_6 , V_116 ) ;
if ( V_21 < 0 )
goto V_115;
for ( V_4 = 0 ; V_4 < V_112 -> V_117 ; V_4 ++ ) {
V_21 = F_34 ( V_6 , V_116 ) ;
if ( V_21 < 0 )
goto V_115;
V_27 = F_9 ( V_9 -> V_100 [ 1 ] ) ;
if ( F_10 ( V_15 , V_25 ) )
V_27 ^= ( ( V_15 -> V_29 + 1 ) >> 1 ) ;
V_113 [ V_4 ] = V_27 ;
}
V_115:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ? V_21 : V_112 -> V_117 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
F_5 ( & V_9 -> V_16 ) ;
V_21 = F_40 ( V_6 , V_15 , V_112 , V_113 ) ;
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_57 = F_21 ( V_112 -> V_114 ) ;
unsigned int V_27 = V_15 -> V_59 [ V_57 ] ;
T_3 * V_90 = ( T_3 * ) & V_9 -> V_94 [ 2 ] ;
int V_21 = - V_107 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_53 )
goto V_118;
V_9 -> V_94 [ 1 ] = 1 ;
V_9 -> V_94 [ 4 ] = V_57 << 6 ;
for ( V_4 = 0 ; V_4 < V_112 -> V_117 ; V_4 ++ ) {
V_27 = V_113 [ V_4 ] ;
* V_90 = F_42 ( V_27 ) ;
V_21 = F_31 ( V_6 , V_119 ) ;
if ( V_21 < 0 )
goto V_118;
V_15 -> V_59 [ V_57 ] = V_27 ;
}
V_118:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ? V_21 : V_112 -> V_117 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_103 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_21 ;
if ( V_103 != V_20 -> V_86 )
return - V_104 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_53 ) {
V_9 -> V_53 = 1 ;
V_21 = F_24 ( V_6 , V_9 -> V_51 ,
V_9 -> V_52 , 0 ) ;
if ( V_21 < 0 ) {
V_9 -> V_53 = 0 ;
goto V_120;
}
V_15 -> V_18 -> V_106 = NULL ;
} else {
V_21 = - V_107 ;
}
V_120:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static int F_44 ( struct V_5 * V_6 ,
struct V_14 * V_15 , struct V_19 * V_20 )
{
struct V_8 * V_75 = V_6 -> V_10 ;
int V_76 = 0 ;
unsigned int V_121 ;
if ( ! V_75 )
return - V_102 ;
V_76 |= F_26 ( & V_20 -> V_78 , V_79 | V_80 ) ;
if ( 0 ) {
V_121 = V_87 ;
} else {
V_121 = V_82 ;
}
V_76 |= F_26 ( & V_20 -> V_81 , V_121 ) ;
if ( 0 ) {
V_121 = V_82 ;
} else {
V_121 = V_79 ;
}
V_76 |= F_26 ( & V_20 -> V_83 , V_121 ) ;
V_76 |= F_26 ( & V_20 -> V_84 , V_31 ) ;
V_76 |= F_26 ( & V_20 -> V_30 , V_31 | V_85 ) ;
if ( V_76 )
return 1 ;
V_76 |= F_27 ( V_20 -> V_78 ) ;
V_76 |= F_27 ( V_20 -> V_30 ) ;
if ( V_76 )
return 2 ;
V_76 |= F_28 ( & V_20 -> V_86 , 0 ) ;
if ( V_20 -> V_81 == V_87 )
V_76 |= F_28 ( & V_20 -> V_88 , 0 ) ;
if ( V_20 -> V_81 == V_82 )
V_76 |= F_29 ( & V_20 -> V_88 ,
1000000 ) ;
if ( V_20 -> V_83 == V_82 )
V_76 |= F_29 ( & V_20 -> V_122 , 125000 ) ;
V_76 |= F_28 ( & V_20 -> V_89 , V_20 -> V_24 ) ;
if ( V_20 -> V_30 == V_31 )
V_76 |= F_29 ( & V_20 -> V_33 , 1 ) ;
else
V_76 |= F_28 ( & V_20 -> V_33 , 0 ) ;
if ( V_76 )
return 3 ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_21 = - V_107 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_53 )
goto V_123;
if ( 0 ) {
V_9 -> V_56 = V_20 -> V_122 / 125000 ;
} else {
V_9 -> V_56 = V_20 -> V_88 / 1000000 ;
if ( V_9 -> V_56 < 1 ) {
V_21 = - V_104 ;
goto V_123;
}
}
V_9 -> V_55 = V_9 -> V_56 ;
if ( V_20 -> V_78 == V_79 ) {
V_9 -> V_53 = 1 ;
V_21 = F_24 ( V_6 , V_9 -> V_51 ,
V_9 -> V_52 , 0 ) ;
if ( V_21 < 0 ) {
V_9 -> V_53 = 0 ;
goto V_123;
}
V_15 -> V_18 -> V_106 = NULL ;
} else {
V_15 -> V_18 -> V_106 = F_43 ;
}
V_123:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static int F_46 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
int V_21 ;
V_21 = F_47 ( V_6 , V_15 , V_112 , V_113 , 0 ) ;
if ( V_21 )
return V_21 ;
return V_112 -> V_117 ;
}
static int F_48 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
F_5 ( & V_9 -> V_16 ) ;
F_49 ( V_15 , V_113 ) ;
V_9 -> V_94 [ 1 ] = V_15 -> V_124 ;
V_9 -> V_94 [ 2 ] = V_15 -> V_125 ;
V_21 = F_31 ( V_6 , V_126 ) ;
if ( V_21 < 0 )
goto V_127;
V_21 = F_34 ( V_6 , V_126 ) ;
if ( V_21 < 0 )
goto V_127;
V_113 [ 1 ] = F_9 ( V_9 -> V_100 [ 1 ] ) ;
V_127:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ? V_21 : V_112 -> V_117 ;
}
static int F_50 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_57 = F_21 ( V_112 -> V_114 ) ;
int V_21 = 0 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
for ( V_4 = 0 ; V_4 < V_112 -> V_117 ; V_4 ++ ) {
V_21 = F_31 ( V_6 , V_128 ) ;
if ( V_21 < 0 )
goto V_129;
V_21 = F_34 ( V_6 , V_128 ) ;
if ( V_21 < 0 )
goto V_129;
V_113 [ V_4 ] = F_9 ( V_9 -> V_100 [ V_57 + 1 ] ) ;
}
V_129:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ? V_21 : V_112 -> V_117 ;
}
static int F_51 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_57 = F_21 ( V_112 -> V_114 ) ;
T_3 * V_90 = ( T_3 * ) & V_9 -> V_94 [ 2 ] ;
int V_21 = 0 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
V_9 -> V_94 [ 1 ] = V_57 ;
for ( V_4 = 0 ; V_4 < V_112 -> V_117 ; V_4 ++ ) {
* V_90 = F_42 ( V_113 [ V_4 ] ) ;
V_21 = F_31 ( V_6 , V_130 ) ;
if ( V_21 < 0 )
break;
}
F_6 ( & V_9 -> V_16 ) ;
return V_21 ? V_21 : V_112 -> V_117 ;
}
static int F_52 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 , unsigned int * V_113 )
{
return 2 ;
}
static void F_53 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_2 ( V_9 -> V_131 ) ;
}
static void F_54 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 )
F_53 ( V_6 ) ;
V_9 -> V_132 = 0 ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
F_5 ( & V_9 -> V_16 ) ;
F_54 ( V_6 , V_9 -> V_132 ) ;
V_21 = F_31 ( V_6 , V_133 ) ;
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static void F_56 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_41 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
switch ( V_1 -> V_43 ) {
case 0 :
break;
case - V_47 :
case - V_48 :
case - V_49 :
case - V_50 :
if ( V_9 -> V_132 )
F_54 ( V_6 , 0 ) ;
return;
default:
if ( V_9 -> V_132 ) {
F_14 ( V_6 -> V_38 ,
L_9 ,
V_1 -> V_43 ) ;
F_54 ( V_6 , 0 ) ;
}
return;
}
if ( ! V_9 -> V_132 )
return;
V_1 -> V_60 = V_9 -> V_134 ;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_1 -> V_43 = 0 ;
if ( V_9 -> V_132 ) {
V_21 = F_13 ( V_1 , V_37 ) ;
if ( V_21 < 0 ) {
F_14 ( V_6 -> V_38 ,
L_10 ,
V_21 ) ;
if ( V_21 == - V_39 )
F_14 ( V_6 -> V_38 ,
L_7 ) ;
F_54 ( V_6 , 0 ) ;
}
}
}
static int F_57 ( struct V_5 * V_6 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 = V_9 -> V_131 ;
F_58 ( V_1 , V_71 , F_33 ( V_71 , 4 ) ,
V_1 -> V_44 ,
V_9 -> V_134 ,
F_56 ,
V_6 ) ;
return F_13 ( V_1 , V_37 ) ;
}
static int F_59 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_135 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_136 = 255 ;
if ( V_135 < V_137 )
return - V_138 ;
V_136 = ( V_135 / ( 6 * 512 * 1000 / 33 ) ) - 6 ;
if ( V_136 > 255 )
return - V_138 ;
V_9 -> V_139 = V_136 ;
V_9 -> V_140 = V_135 ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 = 0 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_132 )
goto V_141;
V_9 -> V_94 [ 1 ] = V_9 -> V_139 ;
V_21 = F_31 ( V_6 , V_142 ) ;
if ( V_21 < 0 )
goto V_141;
memset ( V_9 -> V_131 -> V_44 , 0 , V_9 -> V_134 ) ;
V_9 -> V_132 = 1 ;
V_21 = F_57 ( V_6 ) ;
if ( V_21 < 0 )
V_9 -> V_132 = 0 ;
V_141:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static void F_61 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_57 ,
unsigned int V_143 ,
unsigned int V_144 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
char V_145 = ( 1 << V_57 ) ;
char V_146 = ( 16 << V_57 ) ;
char * V_147 = ( char * ) ( V_9 -> V_131 -> V_44 ) ;
int V_148 = V_9 -> V_134 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_148 ; V_4 ++ ) {
char V_149 = * V_147 ;
V_149 &= ~ V_145 ;
if ( V_4 < V_143 )
V_149 |= V_145 ;
if ( ! V_144 )
V_149 &= ~ V_146 ;
else
V_149 |= V_146 ;
* V_147 ++ = V_149 ;
}
}
static int F_62 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
unsigned int V_57 = F_21 ( V_112 -> V_114 ) ;
if ( V_112 -> V_117 != 1 )
return - V_104 ;
F_61 ( V_6 , V_15 , V_57 , V_113 [ 0 ] , 0 ) ;
return V_112 -> V_117 ;
}
static int F_63 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_57 = F_21 ( V_112 -> V_114 ) ;
switch ( V_113 [ 0 ] ) {
case V_150 :
if ( V_113 [ 1 ] != 0 )
return - V_104 ;
return F_60 ( V_6 , V_15 ) ;
case V_151 :
return F_55 ( V_6 , V_15 ) ;
case V_152 :
V_113 [ 1 ] = V_9 -> V_132 ;
return 0 ;
case V_153 :
return F_59 ( V_6 , V_15 , V_113 [ 1 ] ) ;
case V_154 :
V_113 [ 1 ] = V_9 -> V_140 ;
return 0 ;
case V_155 :
F_61 ( V_6 , V_15 , V_57 , V_113 [ 1 ] , ( V_113 [ 2 ] != 0 ) ) ;
return 0 ;
case V_156 :
return - V_104 ;
}
return - V_104 ;
}
static int F_64 ( struct V_5 * V_6 ,
const T_4 * V_113 , T_5 V_157 ,
unsigned long V_41 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
T_2 * V_147 ;
T_2 * V_158 ;
int V_21 ;
if ( ! V_113 )
return 0 ;
if ( V_157 > V_159 ) {
F_14 ( V_6 -> V_38 ,
L_11 ) ;
return - V_160 ;
}
V_147 = F_65 ( V_113 , V_157 , V_161 ) ;
if ( ! V_147 )
return - V_160 ;
V_158 = F_66 ( 1 , V_161 ) ;
if ( ! V_158 ) {
F_67 ( V_147 ) ;
return - V_160 ;
}
* V_158 = 1 ;
V_21 = F_68 ( V_71 , F_69 ( V_71 , 0 ) ,
V_162 ,
V_163 ,
V_164 , 0x0000 ,
V_158 , 1 ,
V_96 ) ;
if ( V_21 < 0 ) {
F_14 ( V_6 -> V_38 , L_12 ) ;
goto V_165;
}
V_21 = F_68 ( V_71 , F_69 ( V_71 , 0 ) ,
V_162 ,
V_163 ,
0 , 0x0000 ,
V_147 , V_157 ,
V_96 ) ;
if ( V_21 < 0 ) {
F_14 ( V_6 -> V_38 , L_13 ) ;
goto V_165;
}
* V_158 = 0 ;
V_21 = F_68 ( V_71 , F_69 ( V_71 , 0 ) ,
V_162 ,
V_163 ,
V_164 , 0x0000 ,
V_158 , 1 ,
V_96 ) ;
if ( V_21 < 0 )
F_14 ( V_6 -> V_38 , L_14 ) ;
V_165:
F_67 ( V_158 ) ;
F_67 ( V_147 ) ;
return V_21 ;
}
static int F_70 ( struct V_5 * V_6 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_9 -> V_94 = F_71 ( V_95 , V_161 ) ;
V_9 -> V_28 = F_71 ( V_45 , V_161 ) ;
V_9 -> V_100 = F_71 ( V_101 , V_161 ) ;
V_9 -> V_11 = F_72 ( V_9 -> V_12 , sizeof( void * ) ,
V_161 ) ;
V_9 -> V_51 = F_72 ( V_9 -> V_52 , sizeof( void * ) ,
V_161 ) ;
if ( ! V_9 -> V_94 || ! V_9 -> V_28 || ! V_9 -> V_100 ||
! V_9 -> V_11 || ! V_9 -> V_51 )
return - V_160 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = F_73 ( 1 , V_161 ) ;
if ( ! V_1 )
return - V_160 ;
V_9 -> V_11 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_41 = V_6 ;
V_1 -> V_166 = F_74 ( V_71 , 6 ) ;
V_1 -> V_73 = V_74 ;
V_1 -> V_44 = F_71 ( V_45 , V_161 ) ;
if ( ! V_1 -> V_44 )
return - V_160 ;
V_1 -> V_167 = F_15 ;
V_1 -> V_64 = 1 ;
V_1 -> V_60 = V_45 ;
V_1 -> V_65 [ 0 ] . V_66 = 0 ;
V_1 -> V_65 [ 0 ] . V_67 = V_45 ;
}
for ( V_4 = 0 ; V_4 < V_9 -> V_52 ; V_4 ++ ) {
V_1 = F_73 ( 1 , V_161 ) ;
if ( ! V_1 )
return - V_160 ;
V_9 -> V_51 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_41 = V_6 ;
V_1 -> V_166 = F_75 ( V_71 , 2 ) ;
V_1 -> V_73 = V_74 ;
V_1 -> V_44 = F_71 ( V_61 , V_161 ) ;
if ( ! V_1 -> V_44 )
return - V_160 ;
V_1 -> V_167 = F_23 ;
V_1 -> V_64 = 1 ;
V_1 -> V_60 = V_61 ;
V_1 -> V_65 [ 0 ] . V_66 = 0 ;
V_1 -> V_65 [ 0 ] . V_67 = V_61 ;
if ( V_9 -> V_62 )
V_1 -> V_63 = 8 ;
else
V_1 -> V_63 = 1 ;
}
if ( V_9 -> V_134 ) {
V_1 = F_73 ( 0 , V_161 ) ;
if ( ! V_1 )
return - V_160 ;
V_9 -> V_131 = V_1 ;
V_1 -> V_44 = F_71 ( V_9 -> V_134 ,
V_161 ) ;
if ( ! V_1 -> V_44 )
return - V_160 ;
}
return 0 ;
}
static void F_76 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_1 = V_9 -> V_131 ;
if ( V_1 ) {
F_67 ( V_1 -> V_44 ) ;
F_77 ( V_1 ) ;
}
if ( V_9 -> V_51 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_52 ; V_4 ++ ) {
V_1 = V_9 -> V_51 [ V_4 ] ;
if ( V_1 ) {
F_67 ( V_1 -> V_44 ) ;
F_77 ( V_1 ) ;
}
}
F_67 ( V_9 -> V_51 ) ;
}
if ( V_9 -> V_11 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = V_9 -> V_11 [ V_4 ] ;
if ( V_1 ) {
F_67 ( V_1 -> V_44 ) ;
F_77 ( V_1 ) ;
}
}
F_67 ( V_9 -> V_11 ) ;
}
F_67 ( V_9 -> V_100 ) ;
F_67 ( V_9 -> V_28 ) ;
F_67 ( V_9 -> V_94 ) ;
}
static int F_78 ( struct V_5 * V_6 ,
unsigned long V_168 )
{
struct V_169 * V_170 = F_79 ( V_6 ) ;
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 ;
struct V_14 * V_15 ;
int V_21 ;
V_9 = F_80 ( V_6 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_160 ;
F_81 ( & V_9 -> V_16 , 1 ) ;
F_82 ( V_170 , V_9 ) ;
V_9 -> V_62 = ( V_71 -> V_171 == V_172 ) ;
if ( V_9 -> V_62 ) {
V_9 -> V_12 = V_173 ;
V_9 -> V_52 = V_174 ;
V_9 -> V_134 = 512 ;
} else {
V_9 -> V_12 = V_175 ;
V_9 -> V_52 = V_176 ;
}
V_21 = F_70 ( V_6 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_83 ( V_71 , V_170 -> V_177 -> V_178 . V_179 ,
3 ) ;
if ( V_21 < 0 ) {
F_14 ( V_6 -> V_38 ,
L_15 ) ;
return V_21 ;
}
V_21 = F_84 ( V_6 , & V_71 -> V_6 , V_180 ,
F_64 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_85 ( V_6 , ( V_9 -> V_62 ) ? 5 : 4 ) ;
if ( V_21 )
return V_21 ;
V_15 = & V_6 -> V_181 [ 0 ] ;
V_6 -> V_42 = V_15 ;
V_15 -> type = V_182 ;
V_15 -> V_183 = V_184 | V_185 | V_186 ;
V_15 -> V_187 = 8 ;
V_15 -> V_29 = 0x0fff ;
V_15 -> V_188 = 8 ;
V_15 -> V_189 = & V_190 ;
V_15 -> V_191 = F_38 ;
V_15 -> V_192 = F_25 ;
V_15 -> V_193 = F_37 ;
V_15 -> V_194 = F_4 ;
V_15 = & V_6 -> V_181 [ 1 ] ;
V_6 -> V_68 = V_15 ;
V_15 -> type = V_195 ;
V_15 -> V_183 = V_196 | V_185 | V_197 ;
V_15 -> V_187 = 4 ;
V_15 -> V_29 = 0x0fff ;
V_15 -> V_188 = V_15 -> V_187 ;
V_15 -> V_189 = & V_198 ;
V_15 -> V_192 = F_44 ;
V_15 -> V_193 = F_45 ;
V_15 -> V_194 = F_19 ;
V_15 -> V_191 = F_39 ;
V_15 -> V_199 = F_41 ;
V_21 = F_86 ( V_15 ) ;
if ( V_21 )
return V_21 ;
V_15 = & V_6 -> V_181 [ 2 ] ;
V_15 -> type = V_200 ;
V_15 -> V_183 = V_184 | V_196 ;
V_15 -> V_187 = 8 ;
V_15 -> V_29 = 1 ;
V_15 -> V_189 = & V_201 ;
V_15 -> V_202 = F_48 ;
V_15 -> V_203 = F_46 ;
V_15 = & V_6 -> V_181 [ 3 ] ;
V_15 -> type = V_204 ;
V_15 -> V_183 = V_196 | V_184 ;
V_15 -> V_187 = 4 ;
V_15 -> V_29 = 0xffff ;
V_15 -> V_191 = F_50 ;
V_15 -> V_199 = F_51 ;
V_15 -> V_203 = F_52 ;
if ( V_9 -> V_62 ) {
V_15 = & V_6 -> V_181 [ 4 ] ;
V_15 -> type = V_205 ;
V_15 -> V_183 = V_196 | V_206 ;
V_15 -> V_187 = 8 ;
V_15 -> V_29 = V_9 -> V_134 ;
V_15 -> V_199 = F_62 ;
V_15 -> V_203 = F_63 ;
F_59 ( V_6 , V_15 , V_207 ) ;
}
return 0 ;
}
static void F_87 ( struct V_5 * V_6 )
{
struct V_169 * V_170 = F_79 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_82 ( V_170 , NULL ) ;
if ( ! V_9 )
return;
F_5 ( & V_9 -> V_16 ) ;
F_54 ( V_6 , 1 ) ;
F_18 ( V_6 , 1 ) ;
F_3 ( V_6 , 1 ) ;
F_76 ( V_6 ) ;
F_6 ( & V_9 -> V_16 ) ;
}
static int F_88 ( struct V_169 * V_170 ,
const struct V_208 * V_209 )
{
return F_89 ( V_170 , & V_210 , 0 ) ;
}
