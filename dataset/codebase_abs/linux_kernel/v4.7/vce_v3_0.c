static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 == & V_4 -> V_5 . V_2 [ 0 ] )
return F_2 ( V_6 ) ;
else
return F_2 ( V_7 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 == & V_4 -> V_5 . V_2 [ 0 ] )
return F_2 ( V_8 ) ;
else
return F_2 ( V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 == & V_4 -> V_5 . V_2 [ 0 ] )
F_5 ( V_8 , V_2 -> V_10 ) ;
else
F_5 ( V_9 , V_2 -> V_10 ) ;
}
static void F_6 ( struct V_3 * V_4 , bool V_11 )
{
T_2 V_12 , V_13 ;
V_12 = V_13 = F_2 ( V_14 ) ;
if ( V_11 )
V_13 |= V_15 ;
else
V_13 &= ~ V_15 ;
if ( V_12 != V_13 )
F_5 ( V_14 , V_13 ) ;
}
static void F_7 ( struct V_3 * V_4 ,
bool V_16 )
{
T_2 V_12 , V_13 ;
F_6 ( V_4 , true ) ;
if ( ! V_16 ) {
V_12 = V_13 = F_2 ( V_17 ) ;
V_13 |= 0x1ff ;
V_13 &= ~ 0xef0000 ;
if ( V_12 != V_13 )
F_5 ( V_17 , V_13 ) ;
V_12 = V_13 = F_2 ( V_18 ) ;
V_13 |= 0x3ff000 ;
V_13 &= ~ 0xffc00000 ;
if ( V_12 != V_13 )
F_5 ( V_18 , V_13 ) ;
V_12 = V_13 = F_2 ( V_19 ) ;
V_13 |= 0x2 ;
V_13 &= ~ 0x2 ;
if ( V_12 != V_13 )
F_5 ( V_19 , V_13 ) ;
V_12 = V_13 = F_2 ( V_20 ) ;
V_13 |= 0x37f ;
if ( V_12 != V_13 )
F_5 ( V_20 , V_13 ) ;
V_12 = V_13 = F_2 ( V_21 ) ;
V_13 |= V_22 |
V_23 |
V_24 |
0x8 ;
if ( V_12 != V_13 )
F_5 ( V_21 , V_13 ) ;
} else {
V_12 = V_13 = F_2 ( V_17 ) ;
V_13 &= ~ 0x80010 ;
V_13 |= 0xe70008 ;
if ( V_12 != V_13 )
F_5 ( V_17 , V_13 ) ;
V_12 = V_13 = F_2 ( V_18 ) ;
V_13 |= 0xffc00000 ;
if ( V_12 != V_13 )
F_5 ( V_18 , V_13 ) ;
V_12 = V_13 = F_2 ( V_19 ) ;
V_13 |= 0x10000 ;
if ( V_12 != V_13 )
F_5 ( V_19 , V_13 ) ;
V_12 = V_13 = F_2 ( V_20 ) ;
V_13 &= ~ 0xffc00000 ;
if ( V_12 != V_13 )
F_5 ( V_20 , V_13 ) ;
V_12 = V_13 = F_2 ( V_21 ) ;
V_13 &= ~ ( V_22 |
V_23 |
V_24 |
0x8 ) ;
if ( V_12 != V_13 )
F_5 ( V_21 , V_13 ) ;
}
F_6 ( V_4 , false ) ;
}
static int F_8 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_25 , V_26 , V_27 , V_28 ;
F_9 ( & V_4 -> V_29 ) ;
for ( V_25 = 0 ; V_25 < 2 ; ++ V_25 ) {
if ( V_4 -> V_5 . V_30 & ( 1 << V_25 ) )
continue;
if ( V_25 == 0 )
F_10 ( V_31 , 0 ,
~ V_32 ) ;
else
F_10 ( V_31 ,
V_32 ,
~ V_32 ) ;
F_11 ( V_4 , V_25 ) ;
F_10 ( V_33 , 1 , ~ 1 ) ;
if ( V_4 -> V_34 >= V_35 )
F_10 ( V_36 , 1 , ~ 0x200001 ) ;
else
F_10 ( V_36 , V_37 ,
~ V_37 ) ;
F_10 ( V_38 ,
V_39 ,
~ V_39 ) ;
F_12 ( 100 ) ;
F_10 ( V_38 , 0 ,
~ V_39 ) ;
for ( V_26 = 0 ; V_26 < 10 ; ++ V_26 ) {
T_1 V_40 ;
for ( V_27 = 0 ; V_27 < 100 ; ++ V_27 ) {
V_40 = F_2 ( V_33 ) ;
if ( V_40 & 2 )
break;
F_12 ( 10 ) ;
}
V_28 = 0 ;
if ( V_40 & 2 )
break;
F_13 ( L_1 ) ;
F_10 ( V_38 ,
V_39 ,
~ V_39 ) ;
F_12 ( 10 ) ;
F_10 ( V_38 , 0 ,
~ V_39 ) ;
F_12 ( 10 ) ;
V_28 = - 1 ;
}
F_10 ( V_33 , 0 , ~ 1 ) ;
if ( V_4 -> V_41 & V_42 )
F_7 ( V_4 , false ) ;
if ( V_28 ) {
F_13 ( L_2 ) ;
F_14 ( & V_4 -> V_29 ) ;
return V_28 ;
}
}
F_10 ( V_31 , 0 , ~ V_32 ) ;
F_14 ( & V_4 -> V_29 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
F_5 ( V_6 , V_2 -> V_10 ) ;
F_5 ( V_8 , V_2 -> V_10 ) ;
F_5 ( V_43 , V_2 -> V_44 ) ;
F_5 ( V_45 , F_15 ( V_2 -> V_44 ) ) ;
F_5 ( V_46 , V_2 -> V_47 / 4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
F_5 ( V_7 , V_2 -> V_10 ) ;
F_5 ( V_9 , V_2 -> V_10 ) ;
F_5 ( V_48 , V_2 -> V_44 ) ;
F_5 ( V_49 , F_15 ( V_2 -> V_44 ) ) ;
F_5 ( V_50 , V_2 -> V_47 / 4 ) ;
return 0 ;
}
static unsigned F_16 ( struct V_3 * V_4 )
{
T_2 V_12 ;
if ( ( V_4 -> V_34 == V_51 ) ||
( V_4 -> V_34 == V_35 ) ||
( V_4 -> V_34 == V_52 ) ||
( V_4 -> V_34 == V_53 ) )
return V_54 ;
if ( V_4 -> V_55 & V_56 )
V_12 = ( F_17 ( V_57 ) &
V_58 ) >>
V_59 ;
else
V_12 = ( F_17 ( V_60 ) &
V_61 ) >>
V_62 ;
switch ( V_12 ) {
case 1 :
return V_63 ;
case 2 :
return V_54 ;
case 3 :
return V_63 | V_54 ;
default:
return 0 ;
}
}
static int F_18 ( void * V_64 )
{
struct V_3 * V_4 = (struct V_3 * ) V_64 ;
V_4 -> V_5 . V_30 = F_16 ( V_4 ) ;
if ( ( V_4 -> V_5 . V_30 &
( V_63 | V_54 ) ) ==
( V_63 | V_54 ) )
return - V_65 ;
F_19 ( V_4 ) ;
F_20 ( V_4 ) ;
return 0 ;
}
static int F_21 ( void * V_64 )
{
struct V_3 * V_4 = (struct V_3 * ) V_64 ;
struct V_1 * V_2 ;
int V_28 ;
V_28 = F_22 ( V_4 , 167 , & V_4 -> V_5 . V_66 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_23 ( V_4 , V_67 +
( V_68 + V_69 ) * 2 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_24 ( V_4 ) ;
if ( V_28 )
return V_28 ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
sprintf ( V_2 -> V_70 , L_3 ) ;
V_28 = F_25 ( V_4 , V_2 , 512 , V_71 , 0xf ,
& V_4 -> V_5 . V_66 , 0 , V_72 ) ;
if ( V_28 )
return V_28 ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
sprintf ( V_2 -> V_70 , L_4 ) ;
V_28 = F_25 ( V_4 , V_2 , 512 , V_71 , 0xf ,
& V_4 -> V_5 . V_66 , 0 , V_72 ) ;
if ( V_28 )
return V_28 ;
return V_28 ;
}
static int F_26 ( void * V_64 )
{
int V_28 ;
struct V_3 * V_4 = (struct V_3 * ) V_64 ;
V_28 = F_27 ( V_4 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_28 ( V_4 ) ;
if ( V_28 )
return V_28 ;
return V_28 ;
}
static int F_29 ( void * V_64 )
{
int V_28 , V_26 ;
struct V_3 * V_4 = (struct V_3 * ) V_64 ;
V_28 = F_8 ( V_4 ) ;
if ( V_28 )
return V_28 ;
V_4 -> V_5 . V_2 [ 0 ] . V_73 = false ;
V_4 -> V_5 . V_2 [ 1 ] . V_73 = false ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
V_28 = F_30 ( & V_4 -> V_5 . V_2 [ V_26 ] ) ;
if ( V_28 )
return V_28 ;
else
V_4 -> V_5 . V_2 [ V_26 ] . V_73 = true ;
}
F_31 ( L_5 ) ;
return 0 ;
}
static int F_32 ( void * V_64 )
{
return 0 ;
}
static int F_33 ( void * V_64 )
{
int V_28 ;
struct V_3 * V_4 = (struct V_3 * ) V_64 ;
V_28 = F_32 ( V_4 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_27 ( V_4 ) ;
if ( V_28 )
return V_28 ;
return V_28 ;
}
static int F_34 ( void * V_64 )
{
int V_28 ;
struct V_3 * V_4 = (struct V_3 * ) V_64 ;
V_28 = F_24 ( V_4 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_29 ( V_4 ) ;
if ( V_28 )
return V_28 ;
return V_28 ;
}
static void F_11 ( struct V_3 * V_4 , int V_25 )
{
T_1 V_74 , V_75 ;
F_10 ( V_76 , 0 , ~ ( 1 << 16 ) ) ;
F_10 ( V_18 , 0x1FF000 , ~ 0xFF9FF000 ) ;
F_10 ( V_20 , 0x3F , ~ 0x3F ) ;
F_5 ( V_17 , 0xf7 ) ;
F_5 ( V_77 , 0x00398000 ) ;
F_10 ( V_78 , 0x0 , ~ 0x1 ) ;
F_5 ( V_79 , 0 ) ;
F_5 ( V_80 , 0 ) ;
F_5 ( V_81 , 0 ) ;
if ( V_4 -> V_34 >= V_35 ) {
F_5 ( V_82 , ( V_4 -> V_5 . V_44 >> 8 ) ) ;
F_5 ( V_83 , ( V_4 -> V_5 . V_44 >> 8 ) ) ;
F_5 ( V_84 , ( V_4 -> V_5 . V_44 >> 8 ) ) ;
} else
F_5 ( V_85 , ( V_4 -> V_5 . V_44 >> 8 ) ) ;
V_74 = V_86 ;
V_75 = V_67 ;
F_5 ( V_87 , V_74 & 0x7fffffff ) ;
F_5 ( V_88 , V_75 ) ;
if ( V_25 == 0 ) {
V_74 += V_75 ;
V_75 = V_68 ;
F_5 ( V_89 , V_74 & 0x7fffffff ) ;
F_5 ( V_90 , V_75 ) ;
V_74 += V_75 ;
V_75 = V_69 ;
F_5 ( V_91 , V_74 & 0x7fffffff ) ;
F_5 ( V_92 , V_75 ) ;
} else {
V_74 += V_75 + V_68 + V_69 ;
V_75 = V_68 ;
F_5 ( V_89 , V_74 & 0xfffffff ) ;
F_5 ( V_90 , V_75 ) ;
V_74 += V_75 ;
V_75 = V_69 ;
F_5 ( V_91 , V_74 & 0xfffffff ) ;
F_5 ( V_92 , V_75 ) ;
}
F_10 ( V_93 , 0x0 , ~ 0x100 ) ;
F_10 ( V_94 , V_95 ,
~ V_95 ) ;
}
static bool F_35 ( void * V_64 )
{
struct V_3 * V_4 = (struct V_3 * ) V_64 ;
T_2 V_96 = 0 ;
V_96 |= ( V_4 -> V_5 . V_30 & V_63 ) ? 0 : V_97 ;
V_96 |= ( V_4 -> V_5 . V_30 & V_54 ) ? 0 : V_98 ;
return ! ( F_2 ( V_99 ) & V_96 ) ;
}
static int F_36 ( void * V_64 )
{
unsigned V_26 ;
struct V_3 * V_4 = (struct V_3 * ) V_64 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_100 ; V_26 ++ )
if ( F_35 ( V_64 ) )
return 0 ;
return - V_101 ;
}
static int F_37 ( void * V_64 )
{
struct V_3 * V_4 = (struct V_3 * ) V_64 ;
T_2 V_96 = 0 ;
V_96 |= ( V_4 -> V_5 . V_30 & V_63 ) ? 0 : V_102 ;
V_96 |= ( V_4 -> V_5 . V_30 & V_54 ) ? 0 : V_103 ;
F_10 ( V_104 , V_96 ,
~ ( V_102 |
V_103 ) ) ;
F_12 ( 5 ) ;
return F_8 ( V_4 ) ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_105 * V_106 ,
unsigned type ,
enum V_107 V_108 )
{
T_1 V_109 = 0 ;
if ( V_108 == V_110 )
V_109 |= V_95 ;
F_10 ( V_94 , V_109 , ~ V_95 ) ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 ,
struct V_105 * V_106 ,
struct V_111 * V_112 )
{
F_40 ( L_6 ) ;
F_10 ( V_113 ,
V_114 ,
~ V_114 ) ;
switch ( V_112 -> V_115 ) {
case 0 :
case 1 :
F_41 ( & V_4 -> V_5 . V_2 [ V_112 -> V_115 ] ) ;
break;
default:
F_13 ( L_7 ,
V_112 -> V_116 , V_112 -> V_115 ) ;
break;
}
return 0 ;
}
static int F_42 ( void * V_64 ,
enum V_117 V_108 )
{
struct V_3 * V_4 = (struct V_3 * ) V_64 ;
bool V_118 = ( V_108 == V_119 ) ? true : false ;
int V_26 ;
if ( ! ( V_4 -> V_41 & V_42 ) )
return 0 ;
F_9 ( & V_4 -> V_29 ) ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
if ( V_4 -> V_5 . V_30 & ( 1 << V_26 ) )
continue;
if ( V_26 == 0 )
F_10 ( V_31 , 0 ,
~ V_32 ) ;
else
F_10 ( V_31 ,
V_32 ,
~ V_32 ) ;
if ( V_118 ) {
T_1 V_13 = F_2 ( V_76 ) ;
V_13 &= ~ ( 0xf | 0xff0 ) ;
V_13 |= ( ( 0x0 << 0 ) | ( 0x04 << 4 ) ) ;
F_5 ( V_76 , V_13 ) ;
V_13 = F_2 ( V_18 ) ;
V_13 &= ~ ( 0xf | 0xff0 ) ;
V_13 |= ( ( 0x0 << 0 ) | ( 0x04 << 4 ) ) ;
F_5 ( V_18 , V_13 ) ;
}
F_7 ( V_4 , V_118 ) ;
}
F_10 ( V_31 , 0 , ~ V_32 ) ;
F_14 ( & V_4 -> V_29 ) ;
return 0 ;
}
static int F_43 ( void * V_64 ,
enum V_120 V_108 )
{
struct V_3 * V_4 = (struct V_3 * ) V_64 ;
if ( ! ( V_4 -> V_121 & V_122 ) )
return 0 ;
if ( V_108 == V_123 )
return 0 ;
else
return F_8 ( V_4 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_2 [ 0 ] . V_124 = & V_125 ;
V_4 -> V_5 . V_2 [ 1 ] . V_124 = & V_125 ;
}
static void F_20 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_66 . V_126 = 1 ;
V_4 -> V_5 . V_66 . V_124 = & V_127 ;
}
