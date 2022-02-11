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
V_27 = F_11 ( V_15 , V_27 ) ;
if ( ! F_12 ( V_15 , & V_27 , 1 ) )
return;
}
if ( V_20 -> V_29 == V_30 &&
V_18 -> V_31 >= V_20 -> V_32 )
V_18 -> V_33 |= V_34 ;
}
if ( ! ( V_18 -> V_33 & V_35 ) ) {
V_1 -> V_6 = F_13 ( V_6 ) ;
V_21 = F_14 ( V_1 , V_36 ) ;
if ( V_21 < 0 ) {
F_15 ( V_6 -> V_37 ,
L_1 ,
V_21 ) ;
if ( V_21 == - V_38 )
F_15 ( V_6 -> V_37 ,
L_2 ) ;
V_18 -> V_33 |= V_39 ;
}
}
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_40 ;
struct V_14 * V_15 = V_6 -> V_41 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_8 * V_9 = V_6 -> V_10 ;
if ( ! V_9 -> V_13 )
return;
switch ( V_1 -> V_42 ) {
case 0 :
memcpy ( V_9 -> V_28 , V_1 -> V_43 , V_44 ) ;
F_7 ( V_6 , V_15 , V_1 ) ;
break;
case - V_45 :
F_17 ( V_6 -> V_37 , L_3 ) ;
F_7 ( V_6 , V_15 , V_1 ) ;
break;
case - V_46 :
case - V_47 :
case - V_48 :
case - V_49 :
V_18 -> V_33 |= V_39 ;
break;
default:
F_15 ( V_6 -> V_37 ,
L_4 ,
V_1 -> V_42 ) ;
V_18 -> V_33 |= V_39 ;
break;
}
if ( V_18 -> V_33 & V_35 )
F_3 ( V_6 , 0 ) ;
F_18 ( V_6 , V_15 ) ;
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
static void F_21 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_1 * V_1 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
T_2 * V_53 ;
int V_21 ;
int V_4 ;
V_9 -> V_54 -- ;
if ( V_9 -> V_54 == 0 ) {
V_9 -> V_54 = V_9 -> V_55 ;
if ( V_20 -> V_29 == V_30 &&
V_18 -> V_31 >= V_20 -> V_32 ) {
V_18 -> V_33 |= V_34 ;
return;
}
V_53 = V_1 -> V_43 ;
* V_53 ++ = V_20 -> V_24 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_24 ; V_4 ++ ) {
unsigned int V_56 = F_22 ( V_20 -> V_26 [ V_4 ] ) ;
unsigned short V_27 ;
if ( ! F_23 ( V_15 , & V_27 , 1 ) ) {
F_15 ( V_6 -> V_37 , L_5 ) ;
V_18 -> V_33 |= V_57 ;
return;
}
* V_53 ++ = V_27 & 0xff ;
* V_53 ++ = ( V_27 >> 8 ) & 0xff ;
* V_53 ++ = V_56 << 6 ;
V_15 -> V_58 [ V_56 ] = V_27 ;
}
}
if ( ! ( V_18 -> V_33 & V_35 ) ) {
V_1 -> V_59 = V_60 ;
V_1 -> V_6 = F_13 ( V_6 ) ;
V_1 -> V_42 = 0 ;
if ( V_9 -> V_61 )
V_1 -> V_62 = 8 ;
else
V_1 -> V_62 = 1 ;
V_1 -> V_63 = 1 ;
V_1 -> V_64 [ 0 ] . V_65 = 0 ;
V_1 -> V_64 [ 0 ] . V_66 = V_60 ;
V_1 -> V_64 [ 0 ] . V_42 = 0 ;
V_21 = F_14 ( V_1 , V_36 ) ;
if ( V_21 < 0 ) {
F_15 ( V_6 -> V_37 ,
L_6 ,
V_21 ) ;
if ( V_21 == - V_38 )
F_15 ( V_6 -> V_37 ,
L_7 ) ;
V_18 -> V_33 |= V_39 ;
}
}
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_40 ;
struct V_14 * V_15 = V_6 -> V_67 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_8 * V_9 = V_6 -> V_10 ;
if ( ! V_9 -> V_52 )
return;
switch ( V_1 -> V_42 ) {
case 0 :
F_21 ( V_6 , V_15 , V_1 ) ;
break;
case - V_46 :
case - V_47 :
case - V_48 :
case - V_49 :
V_18 -> V_33 |= V_39 ;
break;
default:
F_15 ( V_6 -> V_37 ,
L_8 ,
V_1 -> V_42 ) ;
V_18 -> V_33 |= V_39 ;
break;
}
if ( V_18 -> V_33 & V_35 )
F_19 ( V_6 , 0 ) ;
F_18 ( V_6 , V_15 ) ;
}
static int F_25 ( struct V_5 * V_6 ,
struct V_1 * * V_2 , int V_3 ,
int V_68 )
{
struct V_69 * V_70 = F_13 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_21 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_1 = V_2 [ V_4 ] ;
if ( V_68 )
V_1 -> V_62 = V_9 -> V_71 ;
V_1 -> V_40 = V_6 ;
V_1 -> V_6 = V_70 ;
V_1 -> V_42 = 0 ;
V_1 -> V_72 = V_73 ;
V_21 = F_14 ( V_1 , V_36 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_26 ( struct V_5 * V_6 ,
struct V_14 * V_15 , struct V_19 * V_20 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_74 = 0 ;
V_74 |= F_27 ( & V_20 -> V_75 , V_76 | V_77 ) ;
V_74 |= F_27 ( & V_20 -> V_78 , V_79 ) ;
V_74 |= F_27 ( & V_20 -> V_80 , V_76 ) ;
V_74 |= F_27 ( & V_20 -> V_81 , V_30 ) ;
V_74 |= F_27 ( & V_20 -> V_29 , V_30 | V_82 ) ;
if ( V_74 )
return 1 ;
V_74 |= F_28 ( V_20 -> V_75 ) ;
V_74 |= F_28 ( V_20 -> V_29 ) ;
if ( V_74 )
return 2 ;
V_74 |= F_29 ( & V_20 -> V_83 , 0 ) ;
if ( V_20 -> V_78 == V_84 )
V_74 |= F_29 ( & V_20 -> V_85 , 0 ) ;
if ( V_20 -> V_78 == V_79 ) {
unsigned int V_86 = 1000000 ;
unsigned int V_87 = V_86 ;
if ( V_9 -> V_61 ) {
int V_4 = 1 ;
while ( V_4 < V_20 -> V_24 )
V_4 = V_4 * 2 ;
V_86 /= 8 ;
V_87 = V_86 * V_4 ;
}
V_74 |= F_30 ( & V_20 -> V_85 ,
V_87 ) ;
V_86 = ( V_20 -> V_85 / V_86 ) * V_86 ;
V_74 |= F_29 ( & V_20 -> V_85 , V_86 ) ;
}
V_74 |= F_29 ( & V_20 -> V_88 ,
V_20 -> V_24 ) ;
if ( V_20 -> V_29 == V_30 )
V_74 |= F_30 ( & V_20 -> V_32 , 1 ) ;
else
V_74 |= F_29 ( & V_20 -> V_32 , 0 ) ;
if ( V_74 )
return 3 ;
return 0 ;
}
static T_2 F_31 ( unsigned int V_56 , unsigned int V_25 )
{
T_2 V_89 = ( V_25 <= 1 ) ;
T_2 V_90 = ( ( V_25 % 2 ) == 0 ) ;
return ( V_56 << 4 ) | ( ( V_89 == 1 ) << 2 ) | ( ( V_90 == 1 ) << 3 ) ;
}
static int F_32 ( struct V_5 * V_6 , unsigned int V_91 )
{
struct V_69 * V_70 = F_13 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_92 ;
V_9 -> V_93 [ 0 ] = V_91 ;
return F_33 ( V_70 , F_34 ( V_70 , 1 ) ,
V_9 -> V_93 , V_94 ,
& V_92 , V_95 ) ;
}
static int F_35 ( struct V_5 * V_6 , unsigned int V_96 )
{
struct V_69 * V_70 = F_13 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
int V_97 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_98 ; V_4 ++ ) {
V_21 = F_33 ( V_70 , F_36 ( V_70 , 8 ) ,
V_9 -> V_99 , V_100 ,
& V_97 , V_95 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( F_9 ( V_9 -> V_99 [ 0 ] ) == V_96 )
return V_21 ;
}
return - V_101 ;
}
static int F_37 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_102 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_21 ;
if ( V_102 != V_20 -> V_83 )
return - V_103 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_13 ) {
V_9 -> V_13 = 1 ;
V_21 = F_25 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_21 < 0 ) {
V_9 -> V_13 = 0 ;
goto V_104;
}
V_15 -> V_18 -> V_105 = NULL ;
} else {
V_21 = - V_106 ;
}
V_104:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static int F_38 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_107 = V_20 -> V_24 ;
int V_21 = - V_106 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 )
goto V_108;
V_9 -> V_93 [ 1 ] = V_107 ;
for ( V_4 = 0 ; V_4 < V_107 ; ++ V_4 ) {
unsigned int V_56 = F_22 ( V_20 -> V_26 [ V_4 ] ) ;
unsigned int V_25 = F_8 ( V_20 -> V_26 [ V_4 ] ) ;
V_9 -> V_93 [ V_4 + 2 ] = F_31 ( V_56 , V_25 ) ;
}
V_21 = F_32 ( V_6 , V_109 ) ;
if ( V_21 < 0 )
goto V_108;
if ( V_9 -> V_61 ) {
V_9 -> V_71 = 1 ;
while ( V_9 -> V_71 < V_107 )
V_9 -> V_71 *= 2 ;
V_9 -> V_23 = V_20 -> V_85 /
( 125000 * V_9 -> V_71 ) ;
} else {
V_9 -> V_71 = 1 ;
V_9 -> V_23 = V_20 -> V_85 / 1000000 ;
}
if ( V_9 -> V_23 < 1 ) {
V_21 = - V_103 ;
goto V_108;
}
V_9 -> V_22 = V_9 -> V_23 ;
if ( V_20 -> V_75 == V_76 ) {
V_9 -> V_13 = 1 ;
V_21 = F_25 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_21 < 0 ) {
V_9 -> V_13 = 0 ;
goto V_108;
}
V_15 -> V_18 -> V_105 = NULL ;
} else {
V_15 -> V_18 -> V_105 = F_37 ;
}
V_108:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_110 * V_111 ,
unsigned int * V_112 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_56 = F_22 ( V_111 -> V_113 ) ;
unsigned int V_25 = F_8 ( V_111 -> V_113 ) ;
unsigned int V_27 ;
int V_21 = - V_106 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 )
goto V_114;
V_9 -> V_93 [ 1 ] = F_31 ( V_56 , V_25 ) ;
V_21 = F_32 ( V_6 , V_115 ) ;
if ( V_21 < 0 )
goto V_114;
for ( V_4 = 0 ; V_4 < V_111 -> V_116 ; V_4 ++ ) {
V_21 = F_35 ( V_6 , V_115 ) ;
if ( V_21 < 0 )
goto V_114;
V_27 = F_9 ( V_9 -> V_99 [ 1 ] ) ;
if ( F_10 ( V_15 , V_25 ) )
V_27 = F_11 ( V_15 , V_27 ) ;
V_112 [ V_4 ] = V_27 ;
}
V_114:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ? V_21 : V_111 -> V_116 ;
}
static int F_40 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_110 * V_111 ,
unsigned int * V_112 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
F_5 ( & V_9 -> V_16 ) ;
V_21 = F_41 ( V_6 , V_15 , V_111 , V_112 ) ;
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_110 * V_111 ,
unsigned int * V_112 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_56 = F_22 ( V_111 -> V_113 ) ;
unsigned int V_27 = V_15 -> V_58 [ V_56 ] ;
T_3 * V_89 = ( T_3 * ) & V_9 -> V_93 [ 2 ] ;
int V_21 = - V_106 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_52 )
goto V_117;
V_9 -> V_93 [ 1 ] = 1 ;
V_9 -> V_93 [ 4 ] = V_56 << 6 ;
for ( V_4 = 0 ; V_4 < V_111 -> V_116 ; V_4 ++ ) {
V_27 = V_112 [ V_4 ] ;
* V_89 = F_43 ( V_27 ) ;
V_21 = F_32 ( V_6 , V_118 ) ;
if ( V_21 < 0 )
goto V_117;
V_15 -> V_58 [ V_56 ] = V_27 ;
}
V_117:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ? V_21 : V_111 -> V_116 ;
}
static int F_44 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_102 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_21 ;
if ( V_102 != V_20 -> V_83 )
return - V_103 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_52 ) {
V_9 -> V_52 = 1 ;
V_21 = F_25 ( V_6 , V_9 -> V_50 ,
V_9 -> V_51 , 0 ) ;
if ( V_21 < 0 ) {
V_9 -> V_52 = 0 ;
goto V_119;
}
V_15 -> V_18 -> V_105 = NULL ;
} else {
V_21 = - V_106 ;
}
V_119:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static int F_45 ( struct V_5 * V_6 ,
struct V_14 * V_15 , struct V_19 * V_20 )
{
int V_74 = 0 ;
unsigned int V_120 ;
V_74 |= F_27 ( & V_20 -> V_75 , V_76 | V_77 ) ;
if ( 0 ) {
V_120 = V_84 ;
} else {
V_120 = V_79 ;
}
V_74 |= F_27 ( & V_20 -> V_78 , V_120 ) ;
if ( 0 ) {
V_120 = V_79 ;
} else {
V_120 = V_76 ;
}
V_74 |= F_27 ( & V_20 -> V_80 , V_120 ) ;
V_74 |= F_27 ( & V_20 -> V_81 , V_30 ) ;
V_74 |= F_27 ( & V_20 -> V_29 , V_30 | V_82 ) ;
if ( V_74 )
return 1 ;
V_74 |= F_28 ( V_20 -> V_75 ) ;
V_74 |= F_28 ( V_20 -> V_29 ) ;
if ( V_74 )
return 2 ;
V_74 |= F_29 ( & V_20 -> V_83 , 0 ) ;
if ( V_20 -> V_78 == V_84 )
V_74 |= F_29 ( & V_20 -> V_85 , 0 ) ;
if ( V_20 -> V_78 == V_79 ) {
V_74 |= F_30 ( & V_20 -> V_85 ,
1000000 ) ;
}
if ( V_20 -> V_80 == V_79 )
V_74 |= F_30 ( & V_20 -> V_121 , 125000 ) ;
V_74 |= F_29 ( & V_20 -> V_88 ,
V_20 -> V_24 ) ;
if ( V_20 -> V_29 == V_30 )
V_74 |= F_30 ( & V_20 -> V_32 , 1 ) ;
else
V_74 |= F_29 ( & V_20 -> V_32 , 0 ) ;
if ( V_74 )
return 3 ;
return 0 ;
}
static int F_46 ( struct V_5 * V_6 , struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_18 -> V_20 ;
int V_21 = - V_106 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_52 )
goto V_122;
if ( 0 ) {
V_9 -> V_55 = V_20 -> V_121 / 125000 ;
} else {
V_9 -> V_55 = V_20 -> V_85 / 1000000 ;
if ( V_9 -> V_55 < 1 ) {
V_21 = - V_103 ;
goto V_122;
}
}
V_9 -> V_54 = V_9 -> V_55 ;
if ( V_20 -> V_75 == V_76 ) {
V_9 -> V_52 = 1 ;
V_21 = F_25 ( V_6 , V_9 -> V_50 ,
V_9 -> V_51 , 0 ) ;
if ( V_21 < 0 ) {
V_9 -> V_52 = 0 ;
goto V_122;
}
V_15 -> V_18 -> V_105 = NULL ;
} else {
V_15 -> V_18 -> V_105 = F_44 ;
}
V_122:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static int F_47 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_110 * V_111 ,
unsigned int * V_112 )
{
int V_21 ;
V_21 = F_48 ( V_6 , V_15 , V_111 , V_112 , 0 ) ;
if ( V_21 )
return V_21 ;
return V_111 -> V_116 ;
}
static int F_49 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_110 * V_111 ,
unsigned int * V_112 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
F_5 ( & V_9 -> V_16 ) ;
F_50 ( V_15 , V_112 ) ;
V_9 -> V_93 [ 1 ] = V_15 -> V_123 ;
V_9 -> V_93 [ 2 ] = V_15 -> V_124 ;
V_21 = F_32 ( V_6 , V_125 ) ;
if ( V_21 < 0 )
goto V_126;
V_21 = F_35 ( V_6 , V_125 ) ;
if ( V_21 < 0 )
goto V_126;
V_112 [ 1 ] = F_9 ( V_9 -> V_99 [ 1 ] ) ;
V_126:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ? V_21 : V_111 -> V_116 ;
}
static int F_51 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_110 * V_111 ,
unsigned int * V_112 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_56 = F_22 ( V_111 -> V_113 ) ;
int V_21 = 0 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
for ( V_4 = 0 ; V_4 < V_111 -> V_116 ; V_4 ++ ) {
V_21 = F_32 ( V_6 , V_127 ) ;
if ( V_21 < 0 )
goto V_128;
V_21 = F_35 ( V_6 , V_127 ) ;
if ( V_21 < 0 )
goto V_128;
V_112 [ V_4 ] = F_9 ( V_9 -> V_99 [ V_56 + 1 ] ) ;
}
V_128:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ? V_21 : V_111 -> V_116 ;
}
static int F_52 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_110 * V_111 ,
unsigned int * V_112 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_56 = F_22 ( V_111 -> V_113 ) ;
T_3 * V_89 = ( T_3 * ) & V_9 -> V_93 [ 2 ] ;
int V_21 = 0 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
V_9 -> V_93 [ 1 ] = V_56 ;
for ( V_4 = 0 ; V_4 < V_111 -> V_116 ; V_4 ++ ) {
* V_89 = F_43 ( V_112 [ V_4 ] ) ;
V_21 = F_32 ( V_6 , V_129 ) ;
if ( V_21 < 0 )
break;
}
F_6 ( & V_9 -> V_16 ) ;
return V_21 ? V_21 : V_111 -> V_116 ;
}
static int F_53 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_110 * V_111 , unsigned int * V_112 )
{
return 2 ;
}
static void F_54 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_2 ( V_9 -> V_130 ) ;
}
static void F_55 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 )
F_54 ( V_6 ) ;
V_9 -> V_131 = 0 ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
F_5 ( & V_9 -> V_16 ) ;
F_55 ( V_6 , V_9 -> V_131 ) ;
V_21 = F_32 ( V_6 , V_132 ) ;
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static void F_57 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_40 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 ;
switch ( V_1 -> V_42 ) {
case 0 :
break;
case - V_46 :
case - V_47 :
case - V_48 :
case - V_49 :
if ( V_9 -> V_131 )
F_55 ( V_6 , 0 ) ;
return;
default:
if ( V_9 -> V_131 ) {
F_15 ( V_6 -> V_37 ,
L_9 ,
V_1 -> V_42 ) ;
F_55 ( V_6 , 0 ) ;
}
return;
}
if ( ! V_9 -> V_131 )
return;
V_1 -> V_59 = V_9 -> V_133 ;
V_1 -> V_6 = F_13 ( V_6 ) ;
V_1 -> V_42 = 0 ;
if ( V_9 -> V_131 ) {
V_21 = F_14 ( V_1 , V_36 ) ;
if ( V_21 < 0 ) {
F_15 ( V_6 -> V_37 ,
L_10 ,
V_21 ) ;
if ( V_21 == - V_38 )
F_15 ( V_6 -> V_37 ,
L_7 ) ;
F_55 ( V_6 , 0 ) ;
}
}
}
static int F_58 ( struct V_5 * V_6 )
{
struct V_69 * V_70 = F_13 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 = V_9 -> V_130 ;
F_59 ( V_1 , V_70 , F_34 ( V_70 , 4 ) ,
V_1 -> V_43 ,
V_9 -> V_133 ,
F_57 ,
V_6 ) ;
return F_14 ( V_1 , V_36 ) ;
}
static int F_60 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_134 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_135 = 255 ;
if ( V_134 < V_136 )
return - V_137 ;
V_135 = ( V_134 / ( 6 * 512 * 1000 / 33 ) ) - 6 ;
if ( V_135 > 255 )
return - V_137 ;
V_9 -> V_138 = V_135 ;
V_9 -> V_139 = V_134 ;
return 0 ;
}
static int F_61 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_21 = 0 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_131 )
goto V_140;
V_9 -> V_93 [ 1 ] = V_9 -> V_138 ;
V_21 = F_32 ( V_6 , V_141 ) ;
if ( V_21 < 0 )
goto V_140;
memset ( V_9 -> V_130 -> V_43 , 0 , V_9 -> V_133 ) ;
V_9 -> V_131 = 1 ;
V_21 = F_58 ( V_6 ) ;
if ( V_21 < 0 )
V_9 -> V_131 = 0 ;
V_140:
F_6 ( & V_9 -> V_16 ) ;
return V_21 ;
}
static void F_62 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_56 ,
unsigned int V_142 ,
unsigned int V_143 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
char V_144 = ( 1 << V_56 ) ;
char V_145 = ( 16 << V_56 ) ;
char * V_146 = ( char * ) ( V_9 -> V_130 -> V_43 ) ;
int V_147 = V_9 -> V_133 ;
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
static int F_63 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_110 * V_111 ,
unsigned int * V_112 )
{
unsigned int V_56 = F_22 ( V_111 -> V_113 ) ;
if ( V_111 -> V_116 != 1 )
return - V_103 ;
F_62 ( V_6 , V_15 , V_56 , V_112 [ 0 ] , 0 ) ;
return V_111 -> V_116 ;
}
static int F_64 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_110 * V_111 ,
unsigned int * V_112 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_56 = F_22 ( V_111 -> V_113 ) ;
switch ( V_112 [ 0 ] ) {
case V_149 :
if ( V_112 [ 1 ] != 0 )
return - V_103 ;
return F_61 ( V_6 , V_15 ) ;
case V_150 :
return F_56 ( V_6 , V_15 ) ;
case V_151 :
V_112 [ 1 ] = V_9 -> V_131 ;
return 0 ;
case V_152 :
return F_60 ( V_6 , V_15 , V_112 [ 1 ] ) ;
case V_153 :
V_112 [ 1 ] = V_9 -> V_139 ;
return 0 ;
case V_154 :
F_62 ( V_6 , V_15 , V_56 , V_112 [ 1 ] , ( V_112 [ 2 ] != 0 ) ) ;
return 0 ;
case V_155 :
return - V_103 ;
}
return - V_103 ;
}
static int F_65 ( struct V_5 * V_6 ,
const T_2 * V_112 , T_4 V_156 ,
unsigned long V_40 )
{
struct V_69 * V_70 = F_13 ( V_6 ) ;
T_2 * V_146 ;
T_2 * V_157 ;
int V_21 ;
if ( ! V_112 )
return 0 ;
if ( V_156 > V_158 ) {
F_15 ( V_6 -> V_37 ,
L_11 ) ;
return - V_159 ;
}
V_146 = F_66 ( V_112 , V_156 , V_160 ) ;
if ( ! V_146 )
return - V_159 ;
V_157 = F_67 ( 1 , V_160 ) ;
if ( ! V_157 ) {
F_68 ( V_146 ) ;
return - V_159 ;
}
* V_157 = 1 ;
V_21 = F_69 ( V_70 , F_70 ( V_70 , 0 ) ,
V_161 ,
V_162 ,
V_163 , 0x0000 ,
V_157 , 1 ,
V_95 ) ;
if ( V_21 < 0 ) {
F_15 ( V_6 -> V_37 , L_12 ) ;
goto V_164;
}
V_21 = F_69 ( V_70 , F_70 ( V_70 , 0 ) ,
V_161 ,
V_162 ,
0 , 0x0000 ,
V_146 , V_156 ,
V_95 ) ;
if ( V_21 < 0 ) {
F_15 ( V_6 -> V_37 , L_13 ) ;
goto V_164;
}
* V_157 = 0 ;
V_21 = F_69 ( V_70 , F_70 ( V_70 , 0 ) ,
V_161 ,
V_162 ,
V_163 , 0x0000 ,
V_157 , 1 ,
V_95 ) ;
if ( V_21 < 0 )
F_15 ( V_6 -> V_37 , L_14 ) ;
V_164:
F_68 ( V_157 ) ;
F_68 ( V_146 ) ;
return V_21 ;
}
static int F_71 ( struct V_5 * V_6 )
{
struct V_69 * V_70 = F_13 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_9 -> V_93 = F_72 ( V_94 , V_160 ) ;
V_9 -> V_28 = F_72 ( V_44 , V_160 ) ;
V_9 -> V_99 = F_72 ( V_100 , V_160 ) ;
V_9 -> V_11 = F_73 ( V_9 -> V_12 , sizeof( void * ) ,
V_160 ) ;
V_9 -> V_50 = F_73 ( V_9 -> V_51 , sizeof( void * ) ,
V_160 ) ;
if ( ! V_9 -> V_93 || ! V_9 -> V_28 || ! V_9 -> V_99 ||
! V_9 -> V_11 || ! V_9 -> V_50 )
return - V_159 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = F_74 ( 1 , V_160 ) ;
if ( ! V_1 )
return - V_159 ;
V_9 -> V_11 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_70 ;
V_1 -> V_40 = V_6 ;
V_1 -> V_165 = F_75 ( V_70 , 6 ) ;
V_1 -> V_72 = V_73 ;
V_1 -> V_43 = F_72 ( V_44 , V_160 ) ;
if ( ! V_1 -> V_43 )
return - V_159 ;
V_1 -> V_166 = F_16 ;
V_1 -> V_63 = 1 ;
V_1 -> V_59 = V_44 ;
V_1 -> V_64 [ 0 ] . V_65 = 0 ;
V_1 -> V_64 [ 0 ] . V_66 = V_44 ;
}
for ( V_4 = 0 ; V_4 < V_9 -> V_51 ; V_4 ++ ) {
V_1 = F_74 ( 1 , V_160 ) ;
if ( ! V_1 )
return - V_159 ;
V_9 -> V_50 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_70 ;
V_1 -> V_40 = V_6 ;
V_1 -> V_165 = F_76 ( V_70 , 2 ) ;
V_1 -> V_72 = V_73 ;
V_1 -> V_43 = F_72 ( V_60 , V_160 ) ;
if ( ! V_1 -> V_43 )
return - V_159 ;
V_1 -> V_166 = F_24 ;
V_1 -> V_63 = 1 ;
V_1 -> V_59 = V_60 ;
V_1 -> V_64 [ 0 ] . V_65 = 0 ;
V_1 -> V_64 [ 0 ] . V_66 = V_60 ;
if ( V_9 -> V_61 )
V_1 -> V_62 = 8 ;
else
V_1 -> V_62 = 1 ;
}
if ( V_9 -> V_133 ) {
V_1 = F_74 ( 0 , V_160 ) ;
if ( ! V_1 )
return - V_159 ;
V_9 -> V_130 = V_1 ;
V_1 -> V_43 = F_72 ( V_9 -> V_133 ,
V_160 ) ;
if ( ! V_1 -> V_43 )
return - V_159 ;
}
return 0 ;
}
static void F_77 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_1 = V_9 -> V_130 ;
if ( V_1 ) {
F_68 ( V_1 -> V_43 ) ;
F_78 ( V_1 ) ;
}
if ( V_9 -> V_50 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_51 ; V_4 ++ ) {
V_1 = V_9 -> V_50 [ V_4 ] ;
if ( V_1 ) {
F_68 ( V_1 -> V_43 ) ;
F_78 ( V_1 ) ;
}
}
F_68 ( V_9 -> V_50 ) ;
}
if ( V_9 -> V_11 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = V_9 -> V_11 [ V_4 ] ;
if ( V_1 ) {
F_68 ( V_1 -> V_43 ) ;
F_78 ( V_1 ) ;
}
}
F_68 ( V_9 -> V_11 ) ;
}
F_68 ( V_9 -> V_99 ) ;
F_68 ( V_9 -> V_28 ) ;
F_68 ( V_9 -> V_93 ) ;
}
static int F_79 ( struct V_5 * V_6 ,
unsigned long V_167 )
{
struct V_168 * V_169 = F_80 ( V_6 ) ;
struct V_69 * V_70 = F_13 ( V_6 ) ;
struct V_8 * V_9 ;
struct V_14 * V_15 ;
int V_21 ;
V_9 = F_81 ( V_6 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_159 ;
F_82 ( & V_9 -> V_16 ) ;
F_83 ( V_169 , V_9 ) ;
V_9 -> V_61 = ( V_70 -> V_170 == V_171 ) ;
if ( V_9 -> V_61 ) {
V_9 -> V_12 = V_172 ;
V_9 -> V_51 = V_173 ;
V_9 -> V_133 = 512 ;
} else {
V_9 -> V_12 = V_174 ;
V_9 -> V_51 = V_175 ;
}
V_21 = F_71 ( V_6 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_84 ( V_70 , V_169 -> V_176 -> V_177 . V_178 ,
3 ) ;
if ( V_21 < 0 ) {
F_15 ( V_6 -> V_37 ,
L_15 ) ;
return V_21 ;
}
V_21 = F_85 ( V_6 , & V_70 -> V_6 , V_179 ,
F_65 , 0 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_86 ( V_6 , ( V_9 -> V_61 ) ? 5 : 4 ) ;
if ( V_21 )
return V_21 ;
V_15 = & V_6 -> V_180 [ 0 ] ;
V_6 -> V_41 = V_15 ;
V_15 -> type = V_181 ;
V_15 -> V_182 = V_183 | V_184 | V_185 ;
V_15 -> V_186 = 8 ;
V_15 -> V_187 = 0x0fff ;
V_15 -> V_188 = 8 ;
V_15 -> V_189 = & V_190 ;
V_15 -> V_191 = F_39 ;
V_15 -> V_192 = F_26 ;
V_15 -> V_193 = F_38 ;
V_15 -> V_194 = F_4 ;
V_15 = & V_6 -> V_180 [ 1 ] ;
V_6 -> V_67 = V_15 ;
V_15 -> type = V_195 ;
V_15 -> V_182 = V_196 | V_184 | V_197 ;
V_15 -> V_186 = 4 ;
V_15 -> V_187 = 0x0fff ;
V_15 -> V_188 = V_15 -> V_186 ;
V_15 -> V_189 = & V_198 ;
V_15 -> V_192 = F_45 ;
V_15 -> V_193 = F_46 ;
V_15 -> V_194 = F_20 ;
V_15 -> V_191 = F_40 ;
V_15 -> V_199 = F_42 ;
V_21 = F_87 ( V_15 ) ;
if ( V_21 )
return V_21 ;
V_15 = & V_6 -> V_180 [ 2 ] ;
V_15 -> type = V_200 ;
V_15 -> V_182 = V_183 | V_196 ;
V_15 -> V_186 = 8 ;
V_15 -> V_187 = 1 ;
V_15 -> V_189 = & V_201 ;
V_15 -> V_202 = F_49 ;
V_15 -> V_203 = F_47 ;
V_15 = & V_6 -> V_180 [ 3 ] ;
V_15 -> type = V_204 ;
V_15 -> V_182 = V_196 | V_183 ;
V_15 -> V_186 = 4 ;
V_15 -> V_187 = 0xffff ;
V_15 -> V_191 = F_51 ;
V_15 -> V_199 = F_52 ;
V_15 -> V_203 = F_53 ;
if ( V_9 -> V_61 ) {
V_15 = & V_6 -> V_180 [ 4 ] ;
V_15 -> type = V_205 ;
V_15 -> V_182 = V_196 | V_206 ;
V_15 -> V_186 = 8 ;
V_15 -> V_187 = V_9 -> V_133 ;
V_15 -> V_199 = F_63 ;
V_15 -> V_203 = F_64 ;
F_60 ( V_6 , V_15 , V_207 ) ;
}
return 0 ;
}
static void F_88 ( struct V_5 * V_6 )
{
struct V_168 * V_169 = F_80 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_83 ( V_169 , NULL ) ;
if ( ! V_9 )
return;
F_5 ( & V_9 -> V_16 ) ;
F_55 ( V_6 , 1 ) ;
F_19 ( V_6 , 1 ) ;
F_3 ( V_6 , 1 ) ;
F_77 ( V_6 ) ;
F_6 ( & V_9 -> V_16 ) ;
}
static int F_89 ( struct V_168 * V_169 ,
const struct V_208 * V_209 )
{
return F_90 ( V_169 , & V_210 , 0 ) ;
}
