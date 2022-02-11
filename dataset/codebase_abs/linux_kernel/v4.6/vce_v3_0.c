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
( V_4 -> V_34 == V_35 ) )
return V_52 ;
if ( V_4 -> V_53 & V_54 )
V_12 = ( F_17 ( V_55 ) &
V_56 ) >>
V_57 ;
else
V_12 = ( F_17 ( V_58 ) &
V_59 ) >>
V_60 ;
switch ( V_12 ) {
case 1 :
return V_61 ;
case 2 :
return V_52 ;
case 3 :
return V_61 | V_52 ;
default:
return 0 ;
}
}
static int F_18 ( void * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 ;
V_4 -> V_5 . V_30 = F_16 ( V_4 ) ;
if ( ( V_4 -> V_5 . V_30 &
( V_61 | V_52 ) ) ==
( V_61 | V_52 ) )
return - V_63 ;
F_19 ( V_4 ) ;
F_20 ( V_4 ) ;
return 0 ;
}
static int F_21 ( void * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 ;
struct V_1 * V_2 ;
int V_28 ;
V_28 = F_22 ( V_4 , 167 , & V_4 -> V_5 . V_64 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_23 ( V_4 , V_65 +
( V_66 + V_67 ) * 2 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_24 ( V_4 ) ;
if ( V_28 )
return V_28 ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
sprintf ( V_2 -> V_68 , L_3 ) ;
V_28 = F_25 ( V_4 , V_2 , 4096 , V_69 , 0xf ,
& V_4 -> V_5 . V_64 , 0 , V_70 ) ;
if ( V_28 )
return V_28 ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
sprintf ( V_2 -> V_68 , L_4 ) ;
V_28 = F_25 ( V_4 , V_2 , 4096 , V_69 , 0xf ,
& V_4 -> V_5 . V_64 , 0 , V_70 ) ;
if ( V_28 )
return V_28 ;
return V_28 ;
}
static int F_26 ( void * V_62 )
{
int V_28 ;
struct V_3 * V_4 = (struct V_3 * ) V_62 ;
V_28 = F_27 ( V_4 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_28 ( V_4 ) ;
if ( V_28 )
return V_28 ;
return V_28 ;
}
static int F_29 ( void * V_62 )
{
int V_28 , V_26 ;
struct V_3 * V_4 = (struct V_3 * ) V_62 ;
V_28 = F_8 ( V_4 ) ;
if ( V_28 )
return V_28 ;
V_4 -> V_5 . V_2 [ 0 ] . V_71 = false ;
V_4 -> V_5 . V_2 [ 1 ] . V_71 = false ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
V_28 = F_30 ( & V_4 -> V_5 . V_2 [ V_26 ] ) ;
if ( V_28 )
return V_28 ;
else
V_4 -> V_5 . V_2 [ V_26 ] . V_71 = true ;
}
F_31 ( L_5 ) ;
return 0 ;
}
static int F_32 ( void * V_62 )
{
return 0 ;
}
static int F_33 ( void * V_62 )
{
int V_28 ;
struct V_3 * V_4 = (struct V_3 * ) V_62 ;
V_28 = F_32 ( V_4 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_27 ( V_4 ) ;
if ( V_28 )
return V_28 ;
return V_28 ;
}
static int F_34 ( void * V_62 )
{
int V_28 ;
struct V_3 * V_4 = (struct V_3 * ) V_62 ;
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
T_1 V_72 , V_73 ;
F_10 ( V_74 , 0 , ~ ( 1 << 16 ) ) ;
F_10 ( V_18 , 0x1FF000 , ~ 0xFF9FF000 ) ;
F_10 ( V_20 , 0x3F , ~ 0x3F ) ;
F_5 ( V_17 , 0xf7 ) ;
F_5 ( V_75 , 0x00398000 ) ;
F_10 ( V_76 , 0x0 , ~ 0x1 ) ;
F_5 ( V_77 , 0 ) ;
F_5 ( V_78 , 0 ) ;
F_5 ( V_79 , 0 ) ;
if ( V_4 -> V_34 >= V_35 ) {
F_5 ( V_80 , ( V_4 -> V_5 . V_44 >> 8 ) ) ;
F_5 ( V_81 , ( V_4 -> V_5 . V_44 >> 8 ) ) ;
F_5 ( V_82 , ( V_4 -> V_5 . V_44 >> 8 ) ) ;
} else
F_5 ( V_83 , ( V_4 -> V_5 . V_44 >> 8 ) ) ;
V_72 = V_84 ;
V_73 = V_65 ;
F_5 ( V_85 , V_72 & 0x7fffffff ) ;
F_5 ( V_86 , V_73 ) ;
if ( V_25 == 0 ) {
V_72 += V_73 ;
V_73 = V_66 ;
F_5 ( V_87 , V_72 & 0x7fffffff ) ;
F_5 ( V_88 , V_73 ) ;
V_72 += V_73 ;
V_73 = V_67 ;
F_5 ( V_89 , V_72 & 0x7fffffff ) ;
F_5 ( V_90 , V_73 ) ;
} else {
V_72 += V_73 + V_66 + V_67 ;
V_73 = V_66 ;
F_5 ( V_87 , V_72 & 0xfffffff ) ;
F_5 ( V_88 , V_73 ) ;
V_72 += V_73 ;
V_73 = V_67 ;
F_5 ( V_89 , V_72 & 0xfffffff ) ;
F_5 ( V_90 , V_73 ) ;
}
F_10 ( V_91 , 0x0 , ~ 0x100 ) ;
F_10 ( V_92 , V_93 ,
~ V_93 ) ;
}
static bool F_35 ( void * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 ;
T_2 V_94 = 0 ;
V_94 |= ( V_4 -> V_5 . V_30 & V_61 ) ? 0 : V_95 ;
V_94 |= ( V_4 -> V_5 . V_30 & V_52 ) ? 0 : V_96 ;
return ! ( F_2 ( V_97 ) & V_94 ) ;
}
static int F_36 ( void * V_62 )
{
unsigned V_26 ;
struct V_3 * V_4 = (struct V_3 * ) V_62 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_98 ; V_26 ++ )
if ( F_35 ( V_62 ) )
return 0 ;
return - V_99 ;
}
static int F_37 ( void * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 ;
T_2 V_94 = 0 ;
V_94 |= ( V_4 -> V_5 . V_30 & V_61 ) ? 0 : V_100 ;
V_94 |= ( V_4 -> V_5 . V_30 & V_52 ) ? 0 : V_101 ;
F_10 ( V_102 , V_94 ,
~ ( V_100 |
V_101 ) ) ;
F_12 ( 5 ) ;
return F_8 ( V_4 ) ;
}
static void F_38 ( void * V_62 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 ;
F_39 ( V_4 -> V_103 , L_6 ) ;
F_39 ( V_4 -> V_103 , L_7 ,
F_2 ( V_33 ) ) ;
F_39 ( V_4 -> V_103 , L_8 ,
F_2 ( V_36 ) ) ;
F_39 ( V_4 -> V_103 , L_9 ,
F_2 ( V_85 ) ) ;
F_39 ( V_4 -> V_103 , L_10 ,
F_2 ( V_86 ) ) ;
F_39 ( V_4 -> V_103 , L_11 ,
F_2 ( V_87 ) ) ;
F_39 ( V_4 -> V_103 , L_12 ,
F_2 ( V_88 ) ) ;
F_39 ( V_4 -> V_103 , L_13 ,
F_2 ( V_89 ) ) ;
F_39 ( V_4 -> V_103 , L_14 ,
F_2 ( V_90 ) ) ;
F_39 ( V_4 -> V_103 , L_15 ,
F_2 ( V_38 ) ) ;
F_39 ( V_4 -> V_103 , L_16 ,
F_2 ( V_48 ) ) ;
F_39 ( V_4 -> V_103 , L_17 ,
F_2 ( V_49 ) ) ;
F_39 ( V_4 -> V_103 , L_18 ,
F_2 ( V_50 ) ) ;
F_39 ( V_4 -> V_103 , L_19 ,
F_2 ( V_7 ) ) ;
F_39 ( V_4 -> V_103 , L_20 ,
F_2 ( V_9 ) ) ;
F_39 ( V_4 -> V_103 , L_21 ,
F_2 ( V_43 ) ) ;
F_39 ( V_4 -> V_103 , L_22 ,
F_2 ( V_45 ) ) ;
F_39 ( V_4 -> V_103 , L_23 ,
F_2 ( V_46 ) ) ;
F_39 ( V_4 -> V_103 , L_24 ,
F_2 ( V_6 ) ) ;
F_39 ( V_4 -> V_103 , L_25 ,
F_2 ( V_8 ) ) ;
F_39 ( V_4 -> V_103 , L_26 ,
F_2 ( V_74 ) ) ;
F_39 ( V_4 -> V_103 , L_27 ,
F_2 ( V_17 ) ) ;
F_39 ( V_4 -> V_103 , L_28 ,
F_2 ( V_18 ) ) ;
F_39 ( V_4 -> V_103 , L_29 ,
F_2 ( V_20 ) ) ;
F_39 ( V_4 -> V_103 , L_30 ,
F_2 ( V_92 ) ) ;
F_39 ( V_4 -> V_103 , L_31 ,
F_2 ( V_91 ) ) ;
F_39 ( V_4 -> V_103 , L_32 ,
F_2 ( V_75 ) ) ;
F_39 ( V_4 -> V_103 , L_33 ,
F_2 ( V_79 ) ) ;
F_39 ( V_4 -> V_103 , L_34 ,
F_2 ( V_77 ) ) ;
F_39 ( V_4 -> V_103 , L_35 ,
F_2 ( V_78 ) ) ;
F_39 ( V_4 -> V_103 , L_36 ,
F_2 ( V_76 ) ) ;
}
static int F_40 ( struct V_3 * V_4 ,
struct V_104 * V_105 ,
unsigned type ,
enum V_106 V_107 )
{
T_1 V_108 = 0 ;
if ( V_107 == V_109 )
V_108 |= V_93 ;
F_10 ( V_92 , V_108 , ~ V_93 ) ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 ,
struct V_104 * V_105 ,
struct V_110 * V_111 )
{
F_42 ( L_37 ) ;
F_10 ( V_112 ,
V_113 ,
~ V_113 ) ;
switch ( V_111 -> V_114 ) {
case 0 :
case 1 :
F_43 ( & V_4 -> V_5 . V_2 [ V_111 -> V_114 ] ) ;
break;
default:
F_13 ( L_38 ,
V_111 -> V_115 , V_111 -> V_114 ) ;
break;
}
return 0 ;
}
static int F_44 ( void * V_62 ,
enum V_116 V_107 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 ;
bool V_117 = ( V_107 == V_118 ) ? true : false ;
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
if ( V_117 ) {
T_1 V_13 = F_2 ( V_74 ) ;
V_13 &= ~ ( 0xf | 0xff0 ) ;
V_13 |= ( ( 0x0 << 0 ) | ( 0x04 << 4 ) ) ;
F_5 ( V_74 , V_13 ) ;
V_13 = F_2 ( V_18 ) ;
V_13 &= ~ ( 0xf | 0xff0 ) ;
V_13 |= ( ( 0x0 << 0 ) | ( 0x04 << 4 ) ) ;
F_5 ( V_18 , V_13 ) ;
}
F_7 ( V_4 , V_117 ) ;
}
F_10 ( V_31 , 0 , ~ V_32 ) ;
F_14 ( & V_4 -> V_29 ) ;
return 0 ;
}
static int F_45 ( void * V_62 ,
enum V_119 V_107 )
{
struct V_3 * V_4 = (struct V_3 * ) V_62 ;
if ( ! ( V_4 -> V_120 & V_121 ) )
return 0 ;
if ( V_107 == V_122 )
return 0 ;
else
return F_8 ( V_4 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_2 [ 0 ] . V_123 = & V_124 ;
V_4 -> V_5 . V_2 [ 1 ] . V_123 = & V_124 ;
}
static void F_20 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_64 . V_125 = 1 ;
V_4 -> V_5 . V_64 . V_123 = & V_126 ;
}
