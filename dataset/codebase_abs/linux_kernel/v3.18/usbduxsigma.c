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
struct V_19 * V_20 = & V_15 -> V_21 -> V_20 ;
unsigned int V_22 ;
T_1 V_23 ;
int V_24 ;
int V_4 ;
switch ( V_1 -> V_25 ) {
case 0 :
memcpy ( V_9 -> V_26 , V_1 -> V_27 , V_28 ) ;
break;
case - V_29 :
F_8 ( V_6 -> V_30 , L_1 ) ;
break;
case - V_31 :
case - V_32 :
case - V_33 :
case - V_34 :
if ( V_9 -> V_13 ) {
F_3 ( V_6 , 0 ) ;
V_15 -> V_21 -> V_35 |= ( V_36 | V_37 ) ;
F_9 ( V_6 , V_15 ) ;
}
return;
default:
if ( V_9 -> V_13 ) {
F_10 ( V_6 -> V_30 ,
L_2 ,
V_38 , V_1 -> V_25 ) ;
F_3 ( V_6 , 0 ) ;
V_15 -> V_21 -> V_35 |= ( V_36 | V_37 ) ;
F_9 ( V_6 , V_15 ) ;
}
return;
}
if ( F_11 ( ! V_9 -> V_13 ) )
return;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_24 = F_13 ( V_1 , V_39 ) ;
if ( F_11 ( V_24 < 0 ) ) {
F_10 ( V_6 -> V_30 , L_3 ,
V_38 , V_24 ) ;
if ( V_24 == - V_40 )
F_10 ( V_6 -> V_30 ,
L_4 ) ;
F_3 ( V_6 , 0 ) ;
V_15 -> V_21 -> V_35 |= ( V_36 | V_37 ) ;
F_9 ( V_6 , V_15 ) ;
return;
}
V_22 = F_14 ( V_9 -> V_26 [ 0 ] ) ;
V_9 -> V_41 -- ;
if ( F_15 ( V_9 -> V_41 > 0 ) )
return;
V_9 -> V_41 = V_9 -> V_42 ;
if ( V_20 -> V_43 == V_44 ) {
V_9 -> V_45 -- ;
if ( V_9 -> V_45 < 0 ) {
F_3 ( V_6 , 0 ) ;
V_15 -> V_21 -> V_35 |= V_36 ;
F_9 ( V_6 , V_15 ) ;
return;
}
}
for ( V_4 = 0 ; V_4 < V_20 -> V_46 ; V_4 ++ ) {
V_23 = F_14 ( V_9 -> V_26 [ V_4 + 1 ] ) ;
V_23 &= 0x00ffffff ;
V_23 ^= 0x00800000 ;
V_24 = F_16 ( V_15 , & V_23 , sizeof( T_1 ) ) ;
if ( F_11 ( V_24 == 0 ) ) {
F_3 ( V_6 , 0 ) ;
return;
}
}
V_15 -> V_21 -> V_35 |= ( V_47 | V_48 ) ;
F_9 ( V_6 , V_15 ) ;
}
static void F_17 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 && V_9 -> V_49 )
F_1 ( V_9 -> V_49 , V_9 -> V_50 ) ;
V_9 -> V_51 = 0 ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_5 ( & V_9 -> V_16 ) ;
F_17 ( V_6 , V_9 -> V_51 ) ;
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_17 ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_14 * V_15 = V_6 -> V_52 ;
struct V_19 * V_20 = & V_15 -> V_21 -> V_20 ;
T_2 * V_53 ;
int V_24 ;
int V_4 ;
switch ( V_1 -> V_25 ) {
case 0 :
break;
case - V_31 :
case - V_32 :
case - V_33 :
case - V_34 :
if ( V_9 -> V_51 ) {
F_17 ( V_6 , 0 ) ;
V_15 -> V_21 -> V_35 |= V_36 ;
F_9 ( V_6 , V_15 ) ;
}
return;
default:
if ( V_9 -> V_51 ) {
F_10 ( V_6 -> V_30 ,
L_2 ,
V_38 , V_1 -> V_25 ) ;
F_17 ( V_6 , 0 ) ;
V_15 -> V_21 -> V_35 |= ( V_37 | V_36 ) ;
F_9 ( V_6 , V_15 ) ;
}
return;
}
if ( ! V_9 -> V_51 )
return;
V_9 -> V_54 -- ;
if ( ( int ) V_9 -> V_54 <= 0 ) {
V_9 -> V_54 = V_9 -> V_55 ;
if ( V_20 -> V_43 == V_44 ) {
V_9 -> V_56 -- ;
if ( V_9 -> V_56 < 0 ) {
F_17 ( V_6 , 0 ) ;
V_15 -> V_21 -> V_35 |= V_36 ;
F_9 ( V_6 , V_15 ) ;
return;
}
}
V_53 = V_1 -> V_27 ;
* V_53 ++ = V_20 -> V_46 ;
for ( V_4 = 0 ; V_4 < V_20 -> V_46 ; V_4 ++ ) {
unsigned int V_57 = F_20 ( V_20 -> V_58 [ V_4 ] ) ;
unsigned short V_23 ;
V_24 = F_21 ( V_15 , & V_23 ) ;
if ( V_24 < 0 ) {
F_10 ( V_6 -> V_30 , L_5 ) ;
V_15 -> V_21 -> V_35 |= ( V_36 |
V_59 ) ;
}
* V_53 ++ = V_23 ;
* V_53 ++ = V_57 ;
V_15 -> V_60 [ V_57 ] = V_23 ;
V_15 -> V_21 -> V_35 |= V_47 ;
F_9 ( V_6 , V_15 ) ;
}
}
V_1 -> V_61 = V_62 ;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_1 -> V_25 = 0 ;
if ( V_9 -> V_63 )
V_1 -> V_64 = 8 ;
else
V_1 -> V_64 = 1 ;
V_1 -> V_65 = 1 ;
V_1 -> V_66 [ 0 ] . V_67 = 0 ;
V_1 -> V_66 [ 0 ] . V_68 = V_62 ;
V_1 -> V_66 [ 0 ] . V_25 = 0 ;
V_24 = F_13 ( V_1 , V_39 ) ;
if ( V_24 < 0 ) {
F_10 ( V_6 -> V_30 ,
L_3 ,
V_38 , V_24 ) ;
if ( V_24 == - V_40 )
F_10 ( V_6 -> V_30 ,
L_4 ) ;
F_17 ( V_6 , 0 ) ;
V_15 -> V_21 -> V_35 |= ( V_36 | V_37 ) ;
F_9 ( V_6 , V_15 ) ;
}
}
static int F_22 ( struct V_5 * V_6 ,
struct V_1 * * V_2 , int V_3 ,
int V_69 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_24 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_1 = V_2 [ V_4 ] ;
if ( V_69 )
V_1 -> V_64 = V_9 -> V_72 ;
V_1 -> V_17 = V_6 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_25 = 0 ;
V_1 -> V_73 = V_74 ;
V_24 = F_13 ( V_1 , V_39 ) ;
if ( V_24 )
return V_24 ;
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
int V_63 = V_9 -> V_63 ;
int V_64 = F_23 ( V_20 -> V_46 ) ;
int V_76 = 0 ;
V_76 |= F_25 ( & V_20 -> V_77 , V_78 | V_79 ) ;
V_76 |= F_25 ( & V_20 -> V_80 , V_81 ) ;
V_76 |= F_25 ( & V_20 -> V_82 , V_78 ) ;
V_76 |= F_25 ( & V_20 -> V_83 , V_44 ) ;
V_76 |= F_25 ( & V_20 -> V_43 , V_44 | V_84 ) ;
if ( V_76 )
return 1 ;
V_76 |= F_26 ( V_20 -> V_77 ) ;
V_76 |= F_26 ( V_20 -> V_43 ) ;
if ( V_76 )
return 2 ;
V_76 |= F_27 ( & V_20 -> V_85 , 0 ) ;
if ( V_20 -> V_80 == V_86 )
V_76 |= F_27 ( & V_20 -> V_87 , 0 ) ;
if ( V_20 -> V_80 == V_81 ) {
unsigned int V_88 ;
if ( V_63 ) {
V_76 |= F_28 ( & V_20 -> V_87 ,
( 1000000 / 8 * V_64 ) ) ;
V_88 = ( V_20 -> V_87 / 125000 ) * 125000 ;
} else {
V_76 |= F_28 ( & V_20 -> V_87 ,
1000000 ) ;
V_88 = ( V_20 -> V_87 / 1000000 ) * 1000000 ;
}
V_76 |= F_27 ( & V_20 -> V_87 , V_88 ) ;
}
V_76 |= F_27 ( & V_20 -> V_89 , V_20 -> V_46 ) ;
if ( V_20 -> V_43 == V_44 )
V_76 |= F_28 ( & V_20 -> V_90 , 1 ) ;
else
V_76 |= F_27 ( & V_20 -> V_90 , 0 ) ;
if ( V_76 )
return 3 ;
if ( V_63 ) {
V_9 -> V_72 = V_64 ;
V_9 -> V_42 = V_20 -> V_87 / ( 125000 * V_64 ) ;
} else {
V_9 -> V_72 = 1 ;
V_9 -> V_42 = V_20 -> V_87 / 1000000 ;
}
if ( V_9 -> V_42 < 1 )
V_76 |= - V_91 ;
if ( V_20 -> V_43 == V_44 ) {
V_9 -> V_45 = V_20 -> V_90 ;
} else {
V_9 -> V_45 = 0 ;
}
if ( V_76 )
return 4 ;
return 0 ;
}
static void F_29 ( unsigned int V_57 ,
T_2 * V_92 ,
T_2 * V_93 )
{
if ( V_57 < 8 )
( * V_92 ) = ( * V_92 ) | ( 1 << V_57 ) ;
else if ( V_57 < 16 )
( * V_93 ) = ( * V_93 ) | ( 1 << ( V_57 - 8 ) ) ;
}
static int F_30 ( struct V_5 * V_6 , int V_94 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_95 ;
V_9 -> V_96 [ 0 ] = V_94 ;
return F_31 ( V_71 , F_32 ( V_71 , 1 ) ,
V_9 -> V_96 , V_97 ,
& V_95 , V_98 ) ;
}
static int F_33 ( struct V_5 * V_6 , int V_99 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_100 ;
int V_24 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_101 ; V_4 ++ ) {
V_24 = F_31 ( V_71 , F_34 ( V_71 , 8 ) ,
V_9 -> V_102 , V_103 ,
& V_100 , V_98 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_9 -> V_102 [ 0 ] == V_99 )
return 0 ;
}
return - V_104 ;
}
static int F_35 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_105 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_21 -> V_20 ;
int V_24 ;
if ( V_105 != V_20 -> V_85 )
return - V_91 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_13 ) {
V_9 -> V_13 = 1 ;
V_24 = F_22 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_24 < 0 ) {
V_9 -> V_13 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_24 ;
}
V_15 -> V_21 -> V_106 = NULL ;
}
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
static int F_36 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_21 -> V_20 ;
unsigned int V_107 = V_20 -> V_46 ;
T_2 V_92 = 0 ;
T_2 V_93 = 0 ;
T_2 V_108 = 0 ;
int V_24 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
V_15 -> V_21 -> V_109 = 0 ;
for ( V_4 = 0 ; V_4 < V_107 ; V_4 ++ ) {
unsigned int V_57 = F_20 ( V_20 -> V_58 [ V_4 ] ) ;
F_29 ( V_57 , & V_92 , & V_93 ) ;
}
V_9 -> V_96 [ 1 ] = V_107 ;
V_9 -> V_96 [ 2 ] = 0x12 ;
V_9 -> V_96 [ 3 ] = 0x03 ;
V_9 -> V_96 [ 4 ] = 0x00 ;
V_9 -> V_96 [ 5 ] = V_92 ;
V_9 -> V_96 [ 6 ] = V_93 ;
V_9 -> V_96 [ 7 ] = V_108 ;
V_24 = F_30 ( V_6 , V_110 ) ;
if ( V_24 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_24 ;
}
V_9 -> V_41 = V_9 -> V_42 ;
if ( V_20 -> V_77 == V_78 ) {
V_9 -> V_13 = 1 ;
V_24 = F_22 ( V_6 , V_9 -> V_11 ,
V_9 -> V_12 , 1 ) ;
if ( V_24 < 0 ) {
V_9 -> V_13 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_24 ;
}
V_15 -> V_21 -> V_106 = NULL ;
} else {
V_15 -> V_21 -> V_106 = F_35 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_57 = F_20 ( V_112 -> V_114 ) ;
T_2 V_92 = 0 ;
T_2 V_93 = 0 ;
T_2 V_108 = 0 ;
int V_24 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_13 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_115 ;
}
F_29 ( V_57 , & V_92 , & V_93 ) ;
V_9 -> V_96 [ 1 ] = 0x16 ;
V_9 -> V_96 [ 2 ] = 0x80 ;
V_9 -> V_96 [ 3 ] = 0x00 ;
V_9 -> V_96 [ 4 ] = V_92 ;
V_9 -> V_96 [ 5 ] = V_93 ;
V_9 -> V_96 [ 6 ] = V_108 ;
V_24 = F_30 ( V_6 , V_116 ) ;
if ( V_24 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_24 ;
}
for ( V_4 = 0 ; V_4 < V_112 -> V_117 ; V_4 ++ ) {
T_1 V_23 ;
V_24 = F_33 ( V_6 , V_116 ) ;
if ( V_24 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_24 ;
}
V_23 = F_14 ( F_38 ( ( V_118
* ) ( V_9 -> V_102 + 1 ) ) ) ;
V_23 &= 0x00ffffff ;
V_23 ^= 0x00800000 ;
V_113 [ V_4 ] = V_23 ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_112 -> V_117 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_24 ;
F_5 ( & V_9 -> V_16 ) ;
V_24 = F_40 ( V_6 , V_15 , V_112 , V_113 ) ;
F_6 ( & V_9 -> V_16 ) ;
return V_24 ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_57 = F_20 ( V_112 -> V_114 ) ;
int V_24 ;
int V_4 ;
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_51 ) {
F_6 ( & V_9 -> V_16 ) ;
return - V_115 ;
}
for ( V_4 = 0 ; V_4 < V_112 -> V_117 ; V_4 ++ ) {
V_9 -> V_96 [ 1 ] = 1 ;
V_9 -> V_96 [ 2 ] = V_113 [ V_4 ] ;
V_9 -> V_96 [ 3 ] = V_57 ;
V_24 = F_30 ( V_6 , V_119 ) ;
if ( V_24 < 0 ) {
F_6 ( & V_9 -> V_16 ) ;
return V_24 ;
}
V_15 -> V_60 [ V_57 ] = V_113 [ V_4 ] ;
}
F_6 ( & V_9 -> V_16 ) ;
return V_112 -> V_117 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_105 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_21 -> V_20 ;
int V_24 ;
if ( V_105 != V_20 -> V_85 )
return - V_91 ;
F_5 ( & V_9 -> V_16 ) ;
if ( ! V_9 -> V_51 ) {
V_9 -> V_51 = 1 ;
V_24 = F_22 ( V_6 , V_9 -> V_49 ,
V_9 -> V_50 , 0 ) ;
if ( V_24 < 0 ) {
V_9 -> V_51 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_24 ;
}
V_15 -> V_21 -> V_106 = NULL ;
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
int V_63 ;
unsigned int V_120 ;
V_63 = 0 ;
V_76 |= F_25 ( & V_20 -> V_77 , V_78 | V_79 ) ;
if ( V_63 ) {
V_120 = V_86 ;
} else {
V_120 = V_81 ;
}
V_76 |= F_25 ( & V_20 -> V_80 , V_120 ) ;
V_76 |= F_25 ( & V_20 -> V_82 , V_78 ) ;
V_76 |= F_25 ( & V_20 -> V_83 , V_44 ) ;
V_76 |= F_25 ( & V_20 -> V_43 , V_44 | V_84 ) ;
if ( V_76 ) {
F_6 ( & V_9 -> V_16 ) ;
return 1 ;
}
V_76 |= F_26 ( V_20 -> V_77 ) ;
V_76 |= F_26 ( V_20 -> V_43 ) ;
if ( V_76 )
return 2 ;
V_76 |= F_27 ( & V_20 -> V_85 , 0 ) ;
if ( V_20 -> V_80 == V_86 )
V_76 |= F_27 ( & V_20 -> V_87 , 0 ) ;
if ( V_20 -> V_80 == V_81 )
V_76 |= F_28 ( & V_20 -> V_87 ,
1000000 ) ;
if ( V_20 -> V_82 == V_81 )
V_76 |= F_28 ( & V_20 -> V_121 , 125000 ) ;
V_76 |= F_27 ( & V_20 -> V_89 , V_20 -> V_46 ) ;
if ( V_20 -> V_43 == V_44 )
V_76 |= F_28 ( & V_20 -> V_90 , 1 ) ;
else
V_76 |= F_27 ( & V_20 -> V_90 , 0 ) ;
if ( V_76 )
return 3 ;
if ( V_63 ) {
V_9 -> V_55 = V_20 -> V_121 / 125000 ;
} else {
V_9 -> V_55 = V_20 -> V_87 / 1000000 ;
}
if ( V_9 -> V_55 < 1 )
V_76 |= - V_91 ;
if ( V_20 -> V_43 == V_44 ) {
if ( V_63 ) {
V_9 -> V_56 = V_20 -> V_90 *
V_20 -> V_89 ;
} else {
V_9 -> V_56 = V_20 -> V_90 ;
}
} else {
V_9 -> V_56 = 0 ;
}
if ( V_76 )
return 4 ;
return 0 ;
}
static int F_44 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_19 * V_20 = & V_15 -> V_21 -> V_20 ;
int V_24 ;
F_5 ( & V_9 -> V_16 ) ;
V_15 -> V_21 -> V_109 = 0 ;
V_9 -> V_54 = V_9 -> V_55 ;
if ( V_20 -> V_77 == V_78 ) {
V_9 -> V_51 = 1 ;
V_24 = F_22 ( V_6 , V_9 -> V_49 ,
V_9 -> V_50 , 0 ) ;
if ( V_24 < 0 ) {
V_9 -> V_51 = 0 ;
F_6 ( & V_9 -> V_16 ) ;
return V_24 ;
}
V_15 -> V_21 -> V_106 = NULL ;
} else {
V_15 -> V_21 -> V_106 = F_42 ;
}
F_6 ( & V_9 -> V_16 ) ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
int V_24 ;
V_24 = F_46 ( V_6 , V_15 , V_112 , V_113 , 0 ) ;
if ( V_24 )
return V_24 ;
return V_112 -> V_117 ;
}
static int F_47 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_24 ;
F_5 ( & V_9 -> V_16 ) ;
F_48 ( V_15 , V_113 ) ;
V_9 -> V_96 [ 1 ] = V_15 -> V_122 & 0xff ;
V_9 -> V_96 [ 4 ] = V_15 -> V_123 & 0xff ;
V_9 -> V_96 [ 2 ] = ( V_15 -> V_122 >> 8 ) & 0xff ;
V_9 -> V_96 [ 5 ] = ( V_15 -> V_123 >> 8 ) & 0xff ;
V_9 -> V_96 [ 3 ] = ( V_15 -> V_122 >> 16 ) & 0xff ;
V_9 -> V_96 [ 6 ] = ( V_15 -> V_123 >> 16 ) & 0xff ;
V_24 = F_30 ( V_6 , V_124 ) ;
if ( V_24 < 0 )
goto V_125;
V_24 = F_33 ( V_6 , V_124 ) ;
if ( V_24 < 0 )
goto V_125;
V_15 -> V_123 = V_9 -> V_102 [ 1 ] |
( V_9 -> V_102 [ 2 ] << 8 ) |
( V_9 -> V_102 [ 3 ] << 16 ) ;
V_113 [ 1 ] = V_15 -> V_123 ;
V_24 = V_112 -> V_117 ;
V_125:
F_6 ( & V_9 -> V_16 ) ;
return V_24 ;
}
static void F_49 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
if ( V_7 ) {
if ( V_9 -> V_126 )
F_2 ( V_9 -> V_126 ) ;
}
V_9 -> V_127 = 0 ;
}
static int F_50 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_49 ( V_6 , V_9 -> V_127 ) ;
return F_30 ( V_6 , V_128 ) ;
}
static void F_51 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_17 ;
struct V_8 * V_9 = V_6 -> V_10 ;
int V_24 ;
switch ( V_1 -> V_25 ) {
case 0 :
break;
case - V_31 :
case - V_32 :
case - V_33 :
case - V_34 :
if ( V_9 -> V_127 )
F_49 ( V_6 , 0 ) ;
return;
default:
if ( V_9 -> V_127 ) {
F_10 ( V_6 -> V_30 ,
L_2 ,
V_38 , V_1 -> V_25 ) ;
F_49 ( V_6 , 0 ) ;
}
return;
}
if ( ! V_9 -> V_127 )
return;
V_1 -> V_61 = V_9 -> V_129 ;
V_1 -> V_6 = F_12 ( V_6 ) ;
V_1 -> V_25 = 0 ;
V_24 = F_13 ( V_1 , V_39 ) ;
if ( V_24 < 0 ) {
F_10 ( V_6 -> V_30 , L_3 ,
V_38 , V_24 ) ;
if ( V_24 == - V_40 )
F_10 ( V_6 -> V_30 ,
L_4 ) ;
F_49 ( V_6 , 0 ) ;
}
}
static int F_52 ( struct V_5 * V_6 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 = V_9 -> V_126 ;
F_53 ( V_1 , V_71 , F_32 ( V_71 , 4 ) ,
V_1 -> V_27 , V_9 -> V_129 ,
F_51 , V_6 ) ;
return F_13 ( V_1 , V_39 ) ;
}
static int F_54 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_130 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_131 = 255 ;
if ( V_130 < V_132 )
return - V_133 ;
V_131 = ( V_130 / ( 6 * 512 * 1000 / 33 ) ) - 6 ;
if ( V_131 > 255 )
return - V_133 ;
V_9 -> V_134 = V_131 ;
V_9 -> V_135 = V_130 ;
return 0 ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
int V_24 ;
if ( V_9 -> V_127 )
return 0 ;
V_9 -> V_96 [ 1 ] = V_9 -> V_134 ;
V_24 = F_30 ( V_6 , V_136 ) ;
if ( V_24 < 0 )
return V_24 ;
memset ( V_9 -> V_126 -> V_27 , 0 , V_9 -> V_129 ) ;
V_9 -> V_127 = 1 ;
V_24 = F_52 ( V_6 ) ;
if ( V_24 < 0 ) {
V_9 -> V_127 = 0 ;
return V_24 ;
}
return 0 ;
}
static void F_56 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
unsigned int V_57 ,
unsigned int V_137 ,
unsigned int V_138 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
char V_139 = ( 1 << V_57 ) ;
char V_140 = ( 16 << V_57 ) ;
char * V_141 = ( char * ) ( V_9 -> V_126 -> V_27 ) ;
int V_142 = V_9 -> V_129 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_142 ; V_4 ++ ) {
char V_143 = * V_141 ;
V_143 &= ~ V_139 ;
if ( V_4 < V_137 )
V_143 |= V_139 ;
if ( ! V_138 )
V_143 &= ~ V_140 ;
else
V_143 |= V_140 ;
* V_141 ++ = V_143 ;
}
}
static int F_57 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
unsigned int V_57 = F_20 ( V_112 -> V_114 ) ;
if ( V_112 -> V_117 != 1 )
return - V_91 ;
F_56 ( V_6 , V_15 , V_57 , V_113 [ 0 ] , 0 ) ;
return V_112 -> V_117 ;
}
static int F_58 ( struct V_5 * V_6 ,
struct V_14 * V_15 ,
struct V_111 * V_112 ,
unsigned int * V_113 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
unsigned int V_57 = F_20 ( V_112 -> V_114 ) ;
switch ( V_113 [ 0 ] ) {
case V_144 :
if ( V_113 [ 1 ] != 0 )
return - V_91 ;
return F_55 ( V_6 , V_15 ) ;
case V_145 :
return F_50 ( V_6 , V_15 ) ;
case V_146 :
V_113 [ 1 ] = V_9 -> V_127 ;
return 0 ;
case V_147 :
return F_54 ( V_6 , V_15 , V_113 [ 1 ] ) ;
case V_148 :
V_113 [ 1 ] = V_9 -> V_135 ;
return 0 ;
case V_149 :
F_56 ( V_6 , V_15 , V_57 , V_113 [ 1 ] , ( V_113 [ 2 ] != 0 ) ) ;
return 0 ;
case V_150 :
return - V_91 ;
}
return - V_91 ;
}
static int F_59 ( struct V_5 * V_6 , int V_57 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_108 ;
T_1 V_23 ;
int V_24 ;
switch ( V_57 ) {
default:
case 0 :
V_108 = 0 ;
break;
case 1 :
V_108 = 1 ;
break;
case 2 :
V_108 = 4 ;
break;
case 3 :
V_108 = 8 ;
break;
case 4 :
V_108 = 16 ;
break;
case 5 :
V_108 = 32 ;
break;
}
V_9 -> V_96 [ 1 ] = 0x12 ;
V_9 -> V_96 [ 2 ] = 0x80 ;
V_9 -> V_96 [ 3 ] = 0x00 ;
V_9 -> V_96 [ 4 ] = 0 ;
V_9 -> V_96 [ 5 ] = 0 ;
V_9 -> V_96 [ 6 ] = V_108 ;
V_24 = F_30 ( V_6 , V_116 ) ;
if ( V_24 < 0 )
return V_24 ;
V_24 = F_33 ( V_6 , V_116 ) ;
if ( V_24 < 0 )
return V_24 ;
V_23 = F_14 ( F_38 ( ( V_118 * ) ( V_9 -> V_102 + 1 ) ) ) ;
V_23 &= 0x00ffffff ;
V_23 ^= 0x00800000 ;
return ( int ) V_23 ;
}
static int F_60 ( struct V_5 * V_6 ,
const T_3 * V_113 , T_4 V_151 ,
unsigned long V_17 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
T_2 * V_141 ;
T_2 * V_88 ;
int V_24 ;
if ( ! V_113 )
return 0 ;
if ( V_151 > V_152 ) {
F_10 ( V_6 -> V_30 , L_6 ) ;
return - V_153 ;
}
V_141 = F_61 ( V_113 , V_151 , V_154 ) ;
if ( ! V_141 )
return - V_153 ;
V_88 = F_62 ( 1 , V_154 ) ;
if ( ! V_88 ) {
F_63 ( V_141 ) ;
return - V_153 ;
}
* V_88 = 1 ;
V_24 = F_64 ( V_71 , F_65 ( V_71 , 0 ) ,
V_155 ,
V_156 ,
V_157 , 0x0000 ,
V_88 , 1 ,
V_98 ) ;
if ( V_24 < 0 ) {
F_10 ( V_6 -> V_30 , L_7 ) ;
goto V_125;
}
V_24 = F_64 ( V_71 , F_65 ( V_71 , 0 ) ,
V_155 ,
V_156 ,
0 , 0x0000 ,
V_141 , V_151 ,
V_98 ) ;
if ( V_24 < 0 ) {
F_10 ( V_6 -> V_30 , L_8 ) ;
goto V_125;
}
* V_88 = 0 ;
V_24 = F_64 ( V_71 , F_65 ( V_71 , 0 ) ,
V_155 ,
V_156 ,
V_157 , 0x0000 ,
V_88 , 1 ,
V_98 ) ;
if ( V_24 < 0 )
F_10 ( V_6 -> V_30 , L_9 ) ;
V_125:
F_63 ( V_88 ) ;
F_63 ( V_141 ) ;
return V_24 ;
}
static int F_66 ( struct V_5 * V_6 )
{
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_9 -> V_96 = F_67 ( V_97 , V_154 ) ;
V_9 -> V_26 = F_67 ( V_28 , V_154 ) ;
V_9 -> V_102 = F_67 ( V_103 , V_154 ) ;
V_9 -> V_11 = F_68 ( V_9 -> V_12 , sizeof( V_1 ) , V_154 ) ;
V_9 -> V_49 = F_68 ( V_9 -> V_50 , sizeof( V_1 ) , V_154 ) ;
if ( ! V_9 -> V_96 || ! V_9 -> V_26 || ! V_9 -> V_102 ||
! V_9 -> V_11 || ! V_9 -> V_49 )
return - V_153 ;
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = F_69 ( 1 , V_154 ) ;
if ( ! V_1 )
return - V_153 ;
V_9 -> V_11 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_17 = NULL ;
V_1 -> V_158 = F_70 ( V_71 , 6 ) ;
V_1 -> V_73 = V_74 ;
V_1 -> V_27 = F_67 ( V_28 , V_154 ) ;
if ( ! V_1 -> V_27 )
return - V_153 ;
V_1 -> V_159 = F_7 ;
V_1 -> V_65 = 1 ;
V_1 -> V_61 = V_28 ;
V_1 -> V_66 [ 0 ] . V_67 = 0 ;
V_1 -> V_66 [ 0 ] . V_68 = V_28 ;
}
for ( V_4 = 0 ; V_4 < V_9 -> V_50 ; V_4 ++ ) {
V_1 = F_69 ( 1 , V_154 ) ;
if ( ! V_1 )
return - V_153 ;
V_9 -> V_49 [ V_4 ] = V_1 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_17 = NULL ;
V_1 -> V_158 = F_71 ( V_71 , 2 ) ;
V_1 -> V_73 = V_74 ;
V_1 -> V_27 = F_67 ( V_62 , V_154 ) ;
if ( ! V_1 -> V_27 )
return - V_153 ;
V_1 -> V_159 = F_19 ;
V_1 -> V_65 = 1 ;
V_1 -> V_61 = V_62 ;
V_1 -> V_66 [ 0 ] . V_67 = 0 ;
V_1 -> V_66 [ 0 ] . V_68 = V_62 ;
if ( V_9 -> V_63 )
V_1 -> V_64 = 8 ;
else
V_1 -> V_64 = 1 ;
}
if ( V_9 -> V_129 ) {
V_1 = F_69 ( 0 , V_154 ) ;
if ( ! V_1 )
return - V_153 ;
V_9 -> V_126 = V_1 ;
V_1 -> V_27 = F_67 ( V_9 -> V_129 ,
V_154 ) ;
if ( ! V_1 -> V_27 )
return - V_153 ;
}
return 0 ;
}
static void F_72 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
struct V_1 * V_1 ;
int V_4 ;
V_1 = V_9 -> V_126 ;
if ( V_1 ) {
F_63 ( V_1 -> V_27 ) ;
F_73 ( V_1 ) ;
}
if ( V_9 -> V_49 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_50 ; V_4 ++ ) {
V_1 = V_9 -> V_49 [ V_4 ] ;
if ( V_1 ) {
F_63 ( V_1 -> V_27 ) ;
F_73 ( V_1 ) ;
}
}
F_63 ( V_9 -> V_49 ) ;
}
if ( V_9 -> V_11 ) {
for ( V_4 = 0 ; V_4 < V_9 -> V_12 ; V_4 ++ ) {
V_1 = V_9 -> V_11 [ V_4 ] ;
if ( V_1 ) {
F_63 ( V_1 -> V_27 ) ;
F_73 ( V_1 ) ;
}
}
F_63 ( V_9 -> V_11 ) ;
}
F_63 ( V_9 -> V_102 ) ;
F_63 ( V_9 -> V_26 ) ;
F_63 ( V_9 -> V_96 ) ;
}
static int F_74 ( struct V_5 * V_6 ,
unsigned long V_160 )
{
struct V_161 * V_162 = F_75 ( V_6 ) ;
struct V_70 * V_71 = F_12 ( V_6 ) ;
struct V_8 * V_9 ;
struct V_14 * V_15 ;
int V_67 ;
int V_24 ;
V_9 = F_76 ( V_6 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_153 ;
F_77 ( & V_9 -> V_16 , 1 ) ;
F_78 ( V_162 , V_9 ) ;
V_9 -> V_63 = ( V_71 -> V_163 == V_164 ) ;
if ( V_9 -> V_63 ) {
V_9 -> V_12 = V_165 ;
V_9 -> V_50 = V_166 ;
V_9 -> V_129 = 512 ;
} else {
V_9 -> V_12 = V_167 ;
V_9 -> V_50 = V_168 ;
}
V_24 = F_66 ( V_6 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_79 ( V_71 , V_162 -> V_169 -> V_170 . V_171 ,
3 ) ;
if ( V_24 < 0 ) {
F_10 ( V_6 -> V_30 ,
L_10 ) ;
return V_24 ;
}
V_24 = F_80 ( V_6 , & V_71 -> V_6 , V_172 ,
F_60 , 0 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_81 ( V_6 , ( V_9 -> V_63 ) ? 4 : 3 ) ;
if ( V_24 )
return V_24 ;
V_15 = & V_6 -> V_173 [ 0 ] ;
V_6 -> V_18 = V_15 ;
V_15 -> type = V_174 ;
V_15 -> V_175 = V_176 | V_177 | V_178 | V_179 ;
V_15 -> V_180 = V_181 ;
V_15 -> V_182 = V_181 ;
V_15 -> V_183 = 0x00ffffff ;
V_15 -> V_184 = & V_185 ;
V_15 -> V_186 = F_37 ;
V_15 -> V_187 = F_24 ;
V_15 -> V_188 = F_36 ;
V_15 -> V_189 = F_4 ;
V_15 = & V_6 -> V_173 [ 1 ] ;
V_6 -> V_52 = V_15 ;
V_15 -> type = V_190 ;
V_15 -> V_175 = V_191 | V_177 | V_192 ;
V_15 -> V_180 = 4 ;
V_15 -> V_182 = V_15 -> V_180 ;
V_15 -> V_183 = 0x00ff ;
V_15 -> V_184 = & V_193 ;
V_15 -> V_194 = F_41 ;
V_15 -> V_186 = F_39 ;
V_15 -> V_187 = F_43 ;
V_15 -> V_188 = F_44 ;
V_15 -> V_189 = F_18 ;
V_24 = F_82 ( V_15 ) ;
if ( V_24 )
return V_24 ;
V_15 = & V_6 -> V_173 [ 2 ] ;
V_15 -> type = V_195 ;
V_15 -> V_175 = V_176 | V_191 ;
V_15 -> V_180 = 24 ;
V_15 -> V_183 = 1 ;
V_15 -> V_184 = & V_196 ;
V_15 -> V_197 = F_47 ;
V_15 -> V_198 = F_45 ;
if ( V_9 -> V_63 ) {
V_15 = & V_6 -> V_173 [ 3 ] ;
V_15 -> type = V_199 ;
V_15 -> V_175 = V_191 | V_200 ;
V_15 -> V_180 = 8 ;
V_15 -> V_183 = V_9 -> V_129 ;
V_15 -> V_194 = F_57 ;
V_15 -> V_198 = F_58 ;
F_54 ( V_6 , V_15 , V_201 ) ;
}
V_67 = F_59 ( V_6 , 0 ) ;
if ( V_67 < 0 ) {
F_10 ( V_6 -> V_30 ,
L_11 ) ;
return V_67 ;
}
F_83 ( V_6 -> V_30 , L_12 , V_67 ) ;
return 0 ;
}
static void F_84 ( struct V_5 * V_6 )
{
struct V_161 * V_162 = F_75 ( V_6 ) ;
struct V_8 * V_9 = V_6 -> V_10 ;
F_78 ( V_162 , NULL ) ;
if ( ! V_9 )
return;
F_5 ( & V_9 -> V_16 ) ;
F_3 ( V_6 , 1 ) ;
F_17 ( V_6 , 1 ) ;
F_49 ( V_6 , 1 ) ;
F_72 ( V_6 ) ;
F_6 ( & V_9 -> V_16 ) ;
}
static int F_85 ( struct V_161 * V_162 ,
const struct V_202 * V_203 )
{
return F_86 ( V_162 , & V_204 , 0 ) ;
}
