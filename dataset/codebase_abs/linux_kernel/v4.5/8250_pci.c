static void F_1 ( const char * V_1 , struct V_2 * V_3 )
{
F_2 ( & V_3 -> V_3 ,
L_1
L_2
L_3
L_4
L_5 ,
F_3 ( V_3 ) , V_1 , V_3 -> V_4 , V_3 -> V_5 ,
V_3 -> V_6 , V_3 -> V_7 ) ;
}
static int
F_4 ( struct V_8 * V_9 , struct V_10 * V_11 ,
int V_12 , int V_13 , int V_14 )
{
struct V_2 * V_3 = V_9 -> V_3 ;
if ( V_12 >= V_15 )
return - V_16 ;
if ( F_5 ( V_3 , V_12 ) & V_17 ) {
if ( ! V_9 -> V_18 [ V_12 ] )
V_9 -> V_18 [ V_12 ] = F_6 ( V_3 , V_12 ) ;
if ( ! V_9 -> V_18 [ V_12 ] )
return - V_19 ;
V_11 -> V_11 . V_20 = V_21 ;
V_11 -> V_11 . V_22 = 0 ;
V_11 -> V_11 . V_23 = F_7 ( V_3 , V_12 ) + V_13 ;
V_11 -> V_11 . V_24 = V_9 -> V_18 [ V_12 ] + V_13 ;
V_11 -> V_11 . V_14 = V_14 ;
} else {
V_11 -> V_11 . V_20 = V_25 ;
V_11 -> V_11 . V_22 = F_7 ( V_3 , V_12 ) + V_13 ;
V_11 -> V_11 . V_23 = 0 ;
V_11 -> V_11 . V_24 = NULL ;
V_11 -> V_11 . V_14 = 0 ;
}
return 0 ;
}
static int F_8 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
unsigned int V_12 = 0 , V_13 = V_27 -> V_29 ;
V_12 = F_9 ( V_27 -> V_30 ) ;
if ( V_28 < 2 ) {
V_13 += V_28 * V_27 -> V_31 ;
} else if ( ( V_28 >= 2 ) && ( V_28 < 4 ) ) {
V_12 += 1 ;
V_13 += ( ( V_28 - 2 ) * V_27 -> V_31 ) ;
} else if ( ( V_28 >= 4 ) && ( V_28 < 6 ) ) {
V_12 += 2 ;
V_13 += ( ( V_28 - 4 ) * V_27 -> V_31 ) ;
} else if ( V_28 >= 6 ) {
V_12 += 3 ;
V_13 += ( ( V_28 - 6 ) * V_27 -> V_31 ) ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_27 -> V_32 ) ;
}
static int
F_10 ( struct V_8 * V_9 , const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
unsigned int V_12 , V_13 = V_27 -> V_29 ;
V_12 = F_9 ( V_27 -> V_30 ) ;
if ( V_28 < 4 )
V_12 += V_28 ;
else {
V_12 = 4 ;
V_13 += ( V_28 - 4 ) * V_27 -> V_31 ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_27 -> V_32 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
int V_33 = 0 ;
switch ( V_3 -> V_7 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_33 = 3 ;
break;
case V_38 :
V_33 = 2 ;
break;
case V_39 :
V_33 = 4 ;
break;
case V_40 :
case V_41 :
V_33 = 1 ;
break;
}
return V_33 ;
}
static int
F_12 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
unsigned int V_13 = V_27 -> V_29 ;
unsigned int V_12 = F_9 ( V_27 -> V_30 ) ;
switch ( V_9 -> V_3 -> V_7 ) {
case V_39 :
if ( V_28 == 3 )
V_28 ++ ;
break;
case V_37 :
if ( V_28 > 0 )
V_28 ++ ;
if ( V_28 > 2 )
V_28 ++ ;
break;
}
if ( V_28 > 2 )
V_13 = 0x18 ;
V_13 += V_28 * V_27 -> V_31 ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_27 -> V_32 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
T_1 V_42 ;
if ( ! ( V_3 -> V_7 & 0x1000 ) )
return - V_43 ;
F_14 ( V_3 , 0x44 , & V_42 ) ;
if ( V_42 == 0x00001000L ) {
F_15 ( & V_3 -> V_3 , L_6 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
T_2 V_44 ;
void T_3 * V_45 ;
if ( ( F_5 ( V_3 , 0 ) & V_17 ) == 0 ) {
F_1 ( L_7 , V_3 ) ;
return 0 ;
}
V_44 = 0x41 ;
if ( V_3 -> V_4 == V_46 ||
V_3 -> V_6 == V_47 )
V_44 = 0x43 ;
if ( ( V_3 -> V_4 == V_48 ) &&
( V_3 -> V_5 == V_49 ) )
V_44 = 0x5b ;
V_45 = F_17 ( F_7 ( V_3 , 0 ) , 0x80 ) ;
if ( V_45 == NULL )
return - V_19 ;
F_18 ( V_44 , V_45 + 0x4c ) ;
F_19 ( V_45 + 0x4c ) ;
F_20 ( V_45 ) ;
return 0 ;
}
static void F_21 ( struct V_2 * V_3 )
{
T_2 T_3 * V_45 ;
if ( ( F_5 ( V_3 , 0 ) & V_17 ) == 0 )
return;
V_45 = F_17 ( F_7 ( V_3 , 0 ) , 0x80 ) ;
if ( V_45 != NULL ) {
F_18 ( 0 , V_45 + 0x4c ) ;
F_19 ( V_45 + 0x4c ) ;
F_20 ( V_45 ) ;
}
}
static void F_22 ( struct V_2 * V_3 )
{
void T_3 * V_45 ;
unsigned int V_12 = 0 ;
if ( ( F_5 ( V_3 , V_12 ) & V_17 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return;
}
V_45 = F_6 ( V_3 , V_12 ) ;
if ( V_45 == NULL )
return;
F_18 ( F_19 ( V_45 + V_50 ) & ~ ( V_51 ) ,
V_45 + V_50 ) ;
F_20 ( V_45 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
void T_3 * V_45 ;
unsigned int V_12 = 0 ;
if ( ( F_5 ( V_3 , V_12 ) & V_17 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return;
}
V_45 = F_6 ( V_3 , V_12 ) ;
if ( V_45 == NULL )
return;
F_18 ( V_52 , V_45 + V_53 ) ;
F_20 ( V_45 ) ;
}
static int
F_24 ( struct V_8 * V_9 , const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
unsigned int V_12 , V_13 = V_27 -> V_29 ;
V_12 = 0 ;
if ( V_28 < 4 ) {
V_13 += V_28 * V_27 -> V_31 ;
} else if ( V_28 < 8 ) {
V_13 += V_28 * V_27 -> V_31 + 0xC00 ;
} else
return 1 ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_27 -> V_32 ) ;
}
static int F_25 ( struct V_2 * V_3 )
{
T_2 T_3 * V_45 ;
V_45 = F_6 ( V_3 , 0 ) ;
if ( V_45 == NULL )
return - V_19 ;
F_26 ( 0x10 , V_45 + V_54 ) ;
F_27 ( 50 ) ;
F_26 ( 0x0 , V_45 + V_54 ) ;
F_26 ( 0x4 , V_45 + V_54 ) ;
F_20 ( V_45 ) ;
return 0 ;
}
static void F_28 ( struct V_2 * V_3 )
{
T_2 T_3 * V_45 ;
V_45 = F_6 ( V_3 , 0 ) ;
if ( V_45 != NULL )
F_26 ( 0 , V_45 + V_54 ) ;
F_20 ( V_45 ) ;
}
static int F_29 ( struct V_2 * V_3 )
{
T_4 V_55 ;
void T_3 * V_45 ;
switch ( V_3 -> V_5 & 0xfff8 ) {
case V_56 :
V_55 = 0xffdf ;
break;
case V_57 :
V_55 = 0xf7ff ;
break;
default:
V_55 = 0xfffb ;
break;
}
V_45 = F_17 ( F_7 ( V_3 , 0 ) , 0x80 ) ;
if ( V_45 == NULL )
return - V_19 ;
F_30 ( F_31 ( V_45 + 0x28 ) & V_55 , V_45 + 0x28 ) ;
F_31 ( V_45 + 0x28 ) ;
F_20 ( V_45 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 )
{
T_2 V_55 ;
F_33 ( V_3 , 0x6f , & V_55 ) ;
F_34 ( V_3 , 0x6f , V_55 & 0xef ) ;
if ( ( ( V_3 -> V_5 & 0xfffc ) == V_58 ) ||
( ( V_3 -> V_5 & 0xfffc ) == V_59 ) ) {
F_33 ( V_3 , 0x73 , & V_55 ) ;
F_34 ( V_3 , 0x73 , V_55 & 0xef ) ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 )
{
unsigned int type = V_3 -> V_5 & 0xff00 ;
if ( type == 0x1000 )
return F_29 ( V_3 ) ;
else if ( type == 0x2000 )
return F_32 ( V_3 ) ;
F_1 ( L_9 , V_3 ) ;
return - V_43 ;
}
static int F_36 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
unsigned int V_12 = F_9 ( V_27 -> V_30 ) + V_28 , V_13 = 0 ;
if ( V_28 > 3 ) {
V_12 = 4 ;
V_13 = ( V_28 - 4 ) * 8 ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , 0 ) ;
}
static int F_37 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_7 & 0x00f0 ) >= 0x70 ) {
F_38 ( & V_3 -> V_3 ,
L_10 ,
V_3 -> V_7 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_39 ( struct V_2 * V_3 )
{
const unsigned short * V_60 ;
int V_61 , V_62 ;
for ( V_61 = 0 ; V_61 < F_40 ( V_63 ) ; V_61 ++ ) {
V_60 = V_63 [ V_61 ] . V_60 ;
for ( V_62 = 0 ; V_60 [ V_62 ] ; V_62 ++ )
if ( V_3 -> V_7 == V_60 [ V_62 ] )
return V_63 [ V_61 ] . V_64 ;
}
return 0 ;
}
static int
F_41 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
unsigned int V_12 = 0 , V_13 = V_27 -> V_29 ;
switch ( V_28 ) {
case 0 :
V_12 = 0 ;
break;
case 1 :
V_13 = V_27 -> V_31 ;
V_12 = 0 ;
break;
case 2 :
V_12 = 1 ;
break;
case 3 :
V_13 = V_27 -> V_31 ;
case 4 :
case 5 :
case 6 :
case 7 :
V_12 = V_28 - 2 ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_27 -> V_32 ) ;
}
static int
F_42 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
unsigned int V_12 , V_13 = V_27 -> V_29 ;
switch ( V_28 ) {
case 0 :
V_12 = 1 ;
break;
case 1 :
V_12 = 2 ;
break;
default:
V_12 = 4 ;
V_13 = ( V_28 - 2 ) * V_27 -> V_31 ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_27 -> V_32 ) ;
}
static int F_43 ( struct V_2 * V_3 )
{
F_44 ( 100 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 )
{
void T_3 * V_45 ;
unsigned int V_12 = 0 ;
if ( ( F_5 ( V_3 , V_12 ) & V_17 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return 0 ;
}
V_45 = F_6 ( V_3 , V_12 ) ;
if ( V_45 == NULL )
return - V_19 ;
F_18 ( F_19 ( V_45 + V_50 ) | V_51 ,
V_45 + V_50 ) ;
F_20 ( V_45 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
void T_3 * V_45 ;
struct V_65 V_66 ;
T_1 V_67 ;
unsigned int V_12 = 0 ;
if ( ( F_5 ( V_3 , V_12 ) & V_17 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return 0 ;
}
V_45 = F_6 ( V_3 , V_12 ) ;
if ( V_45 == NULL )
return - V_19 ;
F_47 ( V_3 -> V_68 , & V_66 , & V_3 -> V_69 [ V_12 ] ) ;
V_67 = ( ( V_66 . V_70 + V_71 ) & 0xffffff00 )
| V_72 | V_73 ;
F_18 ( V_67 , V_45 + V_74 ) ;
F_18 ( ( F_19 ( V_45 + V_75 ) & V_76 ) ,
V_45 + V_75 ) ;
F_18 ( V_77 , V_45 + V_78 ) ;
F_18 ( V_79 , V_45 + V_53 ) ;
F_20 ( V_45 ) ;
return 0 ;
}
static int
F_48 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
struct V_2 * V_3 = V_9 -> V_3 ;
void T_3 * V_45 ;
unsigned int V_12 , V_13 = V_27 -> V_29 ;
if ( V_28 >= V_27 -> V_80 )
return 1 ;
V_12 = F_9 ( V_27 -> V_30 ) ;
V_13 += V_28 * V_27 -> V_31 ;
V_45 = F_6 ( V_3 , V_12 ) ;
if ( ! V_45 )
return - V_19 ;
F_26 ( F_49 ( V_45 + V_13 + V_81 ) | V_82 ,
V_45 + V_13 + V_81 ) ;
F_20 ( V_45 ) ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_27 -> V_32 ) ;
}
static int F_50 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
unsigned int V_12 ;
if ( ( V_9 -> V_3 -> V_5 != V_83 ) &&
( V_9 -> V_3 -> V_7 & 0xff00 ) == 0x3000 ) {
V_12 = 3 * V_28 ;
return F_4 ( V_9 , V_11 , V_12 , 0 , V_27 -> V_32 ) ;
} else {
return F_51 ( V_9 , V_27 , V_11 , V_28 ) ;
}
}
static int F_52 ( struct V_2 * V_3 )
{
unsigned int V_84 = V_3 -> V_85 ;
unsigned int V_86 ;
unsigned short V_87 ;
V_86 = ( V_84 & 0xff ) ;
if ( V_86 == 2 ) {
return 1 ;
} else if ( ( V_86 == 0 ) &&
( V_3 -> V_5 == V_88 ) ) {
V_87 = V_3 -> V_7 & 0xf ;
if ( V_87 > 0 ) {
return V_87 ;
} else {
F_2 ( & V_3 -> V_3 , L_11 ) ;
return 0 ;
}
}
F_1 ( L_12 , V_3 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 )
{
unsigned int V_89 = V_3 -> V_7 & 0xf ;
if ( ( V_3 -> V_5 == V_90 ) ||
( V_3 -> V_5 == V_83 ) )
return 0 ;
if ( V_3 -> V_6 == V_91 &&
V_3 -> V_7 == 0x0299 )
return 0 ;
switch ( V_3 -> V_5 ) {
case V_92 :
case V_93 :
case V_94 :
case V_88 :
V_89 = F_52 ( V_3 ) ;
break;
default:
if ( V_89 == 0 ) {
F_1 ( L_13 , V_3 ) ;
}
}
if ( V_89 == 0 )
return - V_43 ;
return V_89 ;
}
static int F_54 ( struct V_2 * V_3 )
{
static const short V_95 [] = { 0x2a0 , 0x2c0 , 0x220 , 0x240 , 0x1e0 ,
0x200 , 0x280 , 0 } ;
int V_96 , V_61 , type ;
struct V_69 * V_22 = NULL ;
T_1 V_97 , V_98 , V_99 ;
V_61 = 0 ;
while ( V_95 [ V_61 ] && V_22 == NULL ) {
V_22 = F_55 ( V_95 [ V_61 ] , V_100 ,
L_14 ) ;
if ( V_22 != NULL ) {
F_56 ( V_3 , V_101 ,
V_102 | V_103 |
V_104 | V_95 [ V_61 ] ) ;
F_56 ( V_3 , V_105 ,
V_95 [ V_61 ] ) ;
V_96 = F_57 ( V_95 [ V_61 ] ) ;
if ( V_96 != 0xff ) {
break;
}
F_58 ( V_22 -> V_70 , V_100 ) ;
V_22 = NULL ;
}
V_61 ++ ;
}
if ( ! V_95 [ V_61 ] ) {
F_2 ( & V_3 -> V_3 , L_15 ) ;
return - V_43 ;
}
type = F_57 ( V_22 -> V_70 + 0x18 ) & 0x0f ;
switch ( type ) {
case 0x2 :
case 0xa :
V_96 = 0 ;
break;
case 0xe :
V_96 = 2 ;
break;
case 0x6 :
V_96 = 1 ;
break;
case 0x8 :
V_96 = 2 ;
break;
default:
F_1 ( L_16 , V_3 ) ;
V_96 = - V_43 ;
}
for ( V_61 = 0 ; V_61 < V_96 ; V_61 ++ ) {
F_14 ( V_3 , V_106 + ( 0x4 * ( V_61 + 1 ) ) ,
& V_99 ) ;
V_99 &= 0x0000FF00 ;
F_56 ( V_3 , V_101 + ( 0x4 * ( V_61 + 1 ) ) ,
V_102 | V_103 |
V_107 | V_99 ) ;
F_14 ( V_3 , V_108 , & V_98 ) ;
V_98 &= ~ ( 0xffff << ( 16 * V_61 ) ) ;
V_98 |= ( V_99 << ( 16 * V_61 ) ) ;
F_56 ( V_3 , V_108 , V_98 ) ;
F_14 ( V_3 , V_109 , & V_97 ) ;
V_97 &= ~ ( 0xf << ( 12 - 4 * V_61 ) ) ;
V_97 |= 1 << ( 23 - V_61 ) ;
F_56 ( V_3 , V_109 , V_97 ) ;
}
if ( V_96 <= 0 ) {
F_58 ( V_22 -> V_70 , V_100 ) ;
}
return V_96 ;
}
static void F_59 ( struct V_2 * V_3 )
{
T_1 V_99 ;
F_14 ( V_3 , V_101 , & V_99 ) ;
V_99 &= 0xffff ;
F_58 ( V_99 , V_100 ) ;
}
static int F_60 ( struct V_2 * V_3 )
{
T_2 T_3 * V_45 ;
unsigned long V_110 ;
unsigned int V_111 = 0 ;
if ( V_3 -> V_4 == V_112 &&
( V_3 -> V_5 & 0xf000 ) != 0xe000 )
return 0 ;
V_45 = F_61 ( V_3 , 0 , 5 ) ;
if ( V_45 == NULL )
return - V_19 ;
V_110 = F_62 ( V_45 ) ;
if ( V_110 == 0x07000200 ) {
V_111 = F_63 ( V_45 + 4 ) ;
F_15 ( & V_3 -> V_3 ,
L_17 ,
V_111 ) ;
}
F_64 ( V_3 , V_45 ) ;
return V_111 ;
}
static int F_65 ( struct V_2 * V_3 )
{
T_2 T_3 * V_45 ;
unsigned long V_110 ;
unsigned int V_111 = 0 ;
if ( V_3 -> V_4 == V_113 &&
( V_3 -> V_5 & 0xF000 ) != 0xC000 )
return 0 ;
V_45 = F_61 ( V_3 , 0 , 5 ) ;
if ( V_45 == NULL )
return - V_19 ;
V_110 = F_62 ( V_45 ) ;
if ( V_110 == 0x07000200 ) {
V_111 = F_63 ( V_45 + 4 ) ;
F_15 ( & V_3 -> V_3 ,
L_18 ,
V_111 ) ;
}
F_64 ( V_3 , V_45 ) ;
return V_111 ;
}
static int F_66 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
V_11 -> V_114 |= V_115 ;
return F_51 ( V_9 , V_27 , V_11 , V_28 ) ;
}
static int F_67 ( T_4 V_116 )
{
struct V_117 * V_118 = & V_119 [ 0 ] ;
while ( V_118 -> V_116 ) {
if ( V_118 -> V_116 == V_116 )
return V_118 -> V_120 ;
V_118 ++ ;
}
F_68 ( L_19 , V_116 ) ;
return 0 ;
}
static int F_69 ( struct V_10 * V_11 )
{
unsigned long V_121 = V_11 -> V_11 . V_22 ;
T_2 V_122 , V_123 ;
V_122 = F_57 ( V_121 + V_124 ) ;
F_70 ( 0xBF , V_121 + V_124 ) ;
V_123 = F_57 ( V_121 + V_125 ) ;
F_70 ( V_122 , V_121 + V_124 ) ;
return V_123 ;
}
static void F_71 ( struct V_10 * V_11 , T_2 V_126 )
{
unsigned long V_121 = V_11 -> V_11 . V_22 ;
T_2 V_122 , V_123 ;
V_122 = F_57 ( V_121 + V_124 ) ;
F_70 ( 0xBF , V_121 + V_124 ) ;
V_123 = F_57 ( V_121 + V_125 ) ;
F_70 ( V_126 , V_121 + V_125 ) ;
F_70 ( V_122 , V_121 + V_124 ) ;
}
static int F_72 ( struct V_10 * V_11 )
{
unsigned long V_121 = V_11 -> V_11 . V_22 ;
T_2 V_122 , V_123 , V_127 ;
V_122 = F_57 ( V_121 + V_124 ) ;
F_70 ( 0xBF , V_121 + V_124 ) ;
V_123 = F_57 ( V_121 + V_125 ) ;
F_70 ( V_123 | 0x10 , V_121 + V_125 ) ;
V_127 = F_57 ( V_121 + V_128 ) ;
F_70 ( V_123 , V_121 + V_125 ) ;
F_70 ( V_122 , V_121 + V_124 ) ;
return V_127 ;
}
static void F_73 ( struct V_10 * V_11 , T_2 V_127 )
{
unsigned long V_121 = V_11 -> V_11 . V_22 ;
T_2 V_122 , V_123 ;
V_122 = F_57 ( V_121 + V_124 ) ;
F_70 ( 0xBF , V_121 + V_124 ) ;
V_123 = F_57 ( V_121 + V_125 ) ;
F_70 ( V_123 | 0x10 , V_121 + V_125 ) ;
F_70 ( V_127 , V_121 + V_128 ) ;
F_70 ( V_123 , V_121 + V_125 ) ;
F_70 ( V_122 , V_121 + V_124 ) ;
}
static int F_74 ( struct V_10 * V_11 )
{
unsigned long V_121 = V_11 -> V_11 . V_22 ;
T_2 V_122 , V_123 ;
V_122 = F_57 ( V_121 + V_124 ) ;
F_70 ( 0xBF , V_121 + V_124 ) ;
V_123 = F_57 ( V_121 + V_125 ) ;
if ( V_123 & 0x20 ) {
F_70 ( 0x80 , V_124 ) ;
if ( ! ( F_57 ( V_125 ) & 0x20 ) ) {
F_70 ( V_122 , V_121 + V_124 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_75 ( struct V_10 * V_11 )
{
T_2 V_129 ;
T_2 V_126 = F_69 ( V_11 ) ;
F_71 ( V_11 , V_126 & V_130 ) ;
V_129 = F_69 ( V_11 ) & 0xC0 ;
if ( V_129 != V_131 )
return - V_16 ;
F_71 ( V_11 , ( V_126 & V_130 ) | V_132 ) ;
V_129 = F_69 ( V_11 ) & 0xC0 ;
if ( V_129 != V_133 )
return - V_16 ;
F_71 ( V_11 , ( V_126 & V_130 ) | V_134 ) ;
V_129 = F_69 ( V_11 ) & 0xC0 ;
if ( V_129 != V_135 )
return - V_16 ;
F_71 ( V_11 , ( V_126 & V_130 ) | V_136 ) ;
V_129 = F_69 ( V_11 ) & 0xC0 ;
if ( V_129 != V_137 )
return - V_16 ;
F_71 ( V_11 , V_126 ) ;
return 0 ;
}
static int F_76 ( struct V_10 * V_11 )
{
T_2 V_126 , V_129 , V_138 ;
unsigned long clock ;
if ( F_75 ( V_11 ) < 0 )
return 1843200 ;
V_126 = F_69 ( V_11 ) ;
F_71 ( V_11 , V_126 & ~ V_139 ) ;
V_129 = F_69 ( V_11 ) ;
if ( V_129 & V_139 ) {
clock = 1843200 ;
goto V_140;
}
F_71 ( V_11 , V_126 | V_139 ) ;
V_129 = F_69 ( V_11 ) ;
if ( ! ( V_129 & V_139 ) ) {
clock = 1843200 ;
goto V_140;
}
V_129 &= V_139 ;
if ( V_129 == V_141 ) {
clock = 3685400 ;
V_138 = V_141 ;
} else if ( V_129 == V_142 ) {
clock = 7372800 ;
V_138 = V_142 ;
} else if ( V_129 == V_139 ) {
clock = 14745600 ;
V_138 = V_139 ;
} else {
clock = 1843200 ;
V_138 = V_143 ;
}
V_126 &= ~ V_144 ;
V_126 |= V_138 ;
V_140:
F_71 ( V_11 , V_126 ) ;
return clock ;
}
static int F_77 ( struct V_10 * V_11 )
{
T_2 V_127 ;
int V_145 = 0 ;
if ( ! F_74 ( V_11 ) )
return 0 ;
V_127 = F_72 ( V_11 ) ;
F_73 ( V_11 , 0xFF ) ;
if ( F_72 ( V_11 ) )
V_145 = 1 ;
F_73 ( V_11 , V_127 ) ;
return V_145 ;
}
static int F_78 ( struct V_2 * V_3 )
{
if ( F_67 ( V_3 -> V_5 ) ) {
unsigned long V_121 = F_7 ( V_3 , 0 ) ;
if ( V_121 ) {
T_1 V_146 ;
F_79 ( F_80 ( V_121 + 0x38 ) | 0x00002000 , V_121 + 0x38 ) ;
V_146 = F_80 ( V_121 + 0x3c ) ;
F_79 ( V_146 | 0x01000000 , V_121 + 0x3c ) ;
F_79 ( V_146 &= ~ 0x01000000 , V_121 + 0x3c ) ;
}
}
return 0 ;
}
static int F_81 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
V_11 -> V_11 . V_22 = F_7 ( V_9 -> V_3 , F_9 ( V_27 -> V_30 ) ) ;
V_11 -> V_11 . V_147 = F_76 ( V_11 ) ;
if ( F_77 ( V_11 ) )
F_82 ( L_20 ) ;
return F_51 ( V_9 , V_27 , V_11 , V_28 ) ;
}
static void F_83 ( struct V_2 * V_3 )
{
}
static int F_51 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
unsigned int V_12 , V_13 = V_27 -> V_29 , V_148 ;
V_12 = F_9 ( V_27 -> V_30 ) ;
if ( V_27 -> V_30 & V_149 )
V_12 += V_28 ;
else
V_13 += V_28 * V_27 -> V_31 ;
V_148 = ( F_84 ( V_9 -> V_3 , V_12 ) - V_27 -> V_29 ) >>
( V_27 -> V_32 + 3 ) ;
if ( V_27 -> V_30 & V_150 && V_28 >= V_148 )
return 1 ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_27 -> V_32 ) ;
}
static int F_85 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
unsigned int V_12 , V_13 = V_27 -> V_29 , V_148 ;
V_12 = F_9 ( V_27 -> V_30 ) ;
if ( V_27 -> V_30 & V_149 )
V_12 += V_28 ;
else
V_13 += V_28 * V_27 -> V_31 ;
V_148 = ( F_84 ( V_9 -> V_3 , V_12 ) - V_27 -> V_29 ) >>
( V_27 -> V_32 + 3 ) ;
if ( V_27 -> V_30 & V_150 && V_28 >= V_148 )
return 1 ;
V_11 -> V_11 . V_147 = 14745600 ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_27 -> V_32 ) ;
}
static int
F_86 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
int V_96 ;
V_96 = F_4 ( V_9 , V_11 , V_28 , 0 , V_27 -> V_32 ) ;
V_11 -> V_11 . V_20 = V_151 ;
V_11 -> V_11 . type = V_152 ;
V_11 -> V_11 . V_30 = ( V_11 -> V_11 . V_30 | V_153 | V_154 ) ;
V_11 -> V_11 . V_14 = 2 ;
return V_96 ;
}
static void
F_87 ( struct V_155 * V_45 , struct V_156 * V_157 ,
struct V_156 * V_158 )
{
unsigned int V_159 = F_88 ( V_157 ) ;
unsigned long V_160 = 100000000 , V_161 = V_159 * 16 ;
unsigned long V_162 = F_89 ( 15 ) - 1 ;
unsigned long V_163 , V_164 ;
T_1 V_129 ;
V_161 *= F_90 ( V_160 / V_161 ) ;
F_91 ( V_161 , V_160 , V_162 , V_162 , & V_163 , & V_164 ) ;
V_45 -> V_147 = V_161 ;
V_129 = ( V_163 << V_165 ) | ( V_164 << V_166 ) ;
F_18 ( V_129 , V_45 -> V_24 + V_167 ) ;
V_129 |= V_168 | V_169 ;
F_18 ( V_129 , V_45 -> V_24 + V_167 ) ;
V_45 -> V_170 &= ~ V_171 ;
if ( V_157 -> V_172 & V_173 )
V_45 -> V_170 |= V_171 ;
F_92 ( V_45 , V_157 , V_158 ) ;
}
static bool F_93 ( struct V_174 * V_175 , void * V_176 )
{
struct V_177 * V_178 = V_176 ;
if ( V_178 -> V_179 != V_175 -> V_5 -> V_3 )
return false ;
V_175 -> V_180 = V_178 ;
return true ;
}
static int
F_94 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
struct V_2 * V_181 = V_9 -> V_3 ;
struct V_5 * V_3 = V_11 -> V_11 . V_3 ;
struct V_182 * V_183 ;
struct V_177 * V_184 , * V_185 ;
struct V_2 * V_179 ;
int V_96 ;
V_183 = F_95 ( V_3 , sizeof( * V_183 ) , V_186 ) ;
if ( ! V_183 )
return - V_19 ;
V_184 = F_95 ( V_3 , sizeof( * V_184 ) , V_186 ) ;
if ( ! V_184 )
return - V_19 ;
V_185 = F_95 ( V_3 , sizeof( * V_185 ) , V_186 ) ;
if ( ! V_185 )
return - V_19 ;
switch ( V_181 -> V_5 ) {
case V_187 :
case V_188 :
case V_189 :
V_185 -> V_190 = 3 ;
V_184 -> V_191 = 2 ;
break;
case V_192 :
case V_193 :
case V_194 :
V_185 -> V_190 = 5 ;
V_184 -> V_191 = 4 ;
break;
default:
return - V_16 ;
}
V_185 -> V_195 = 1 ;
V_185 -> V_196 = 0 ;
V_183 -> V_197 . V_198 = 16 ;
V_184 -> V_195 = 1 ;
V_184 -> V_196 = 0 ;
V_183 -> V_199 . V_200 = 16 ;
V_179 = F_96 ( V_181 -> V_68 , F_97 ( F_98 ( V_181 -> V_201 ) , 0 ) ) ;
V_185 -> V_179 = & V_179 -> V_3 ;
V_184 -> V_179 = & V_179 -> V_3 ;
V_183 -> V_202 = F_93 ;
V_183 -> V_185 = V_185 ;
V_183 -> V_184 = V_184 ;
V_96 = F_51 ( V_9 , V_27 , V_11 , V_28 ) ;
V_11 -> V_11 . V_20 = V_21 ;
V_11 -> V_11 . type = V_203 ;
V_11 -> V_11 . V_30 = ( V_11 -> V_11 . V_30 | V_153 | V_154 ) ;
V_11 -> V_11 . V_204 = F_87 ;
V_11 -> V_11 . V_205 = 64 ;
V_11 -> V_206 = 64 ;
V_11 -> V_183 = V_183 ;
V_11 -> V_207 = V_208 | V_209 ;
F_18 ( V_210 , V_11 -> V_11 . V_24 + V_211 ) ;
return V_96 ;
}
static int
F_99 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
return F_4 ( V_9 , V_11 , 2 , V_28 * 8 , 0 ) ;
}
static int
F_100 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
int V_96 = F_51 ( V_9 , V_27 , V_11 , V_28 ) ;
V_11 -> V_11 . type = V_212 ;
V_11 -> V_11 . V_30 = ( V_11 -> V_11 . V_30 | V_153 | V_154 ) ;
return V_96 ;
}
static int F_101 ( struct V_155 * V_11 ,
struct V_213 * V_214 )
{
T_2 V_215 ;
T_2 * V_216 = ( T_2 * ) V_11 -> V_217 ;
struct V_2 * V_2 = F_102 ( V_11 -> V_3 , struct V_2 ,
V_3 ) ;
F_33 ( V_2 , 0x40 + 8 * * V_216 + 7 , & V_215 ) ;
if ( ! V_214 )
V_214 = & V_11 -> V_214 ;
else if ( V_214 -> V_30 & V_218 )
memset ( V_214 -> V_219 , 0 , sizeof( V_214 -> V_219 ) ) ;
else
memset ( V_214 , 0 , sizeof( * V_214 ) ) ;
V_214 -> V_30 &= V_218 | V_220 ;
if ( V_214 -> V_30 & V_218 ) {
V_215 |= V_221 ;
if ( V_214 -> V_30 & V_220 ) {
V_215 &= ~ V_222 ;
} else {
V_215 |= V_222 ;
}
V_214 -> V_223 = 0 ;
V_214 -> V_224 = 0 ;
} else {
V_215 &= ~ ( V_221 | V_222 ) ;
}
F_34 ( V_2 , 0x40 + 8 * * V_216 + 7 , V_215 ) ;
if ( V_214 != & V_11 -> V_214 )
V_11 -> V_214 = * V_214 ;
return 0 ;
}
static int F_103 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
struct V_2 * V_181 = V_9 -> V_3 ;
T_2 * V_55 ;
T_2 V_225 ;
T_4 V_22 ;
V_225 = 0x40 + 0x08 * V_28 ;
F_104 ( V_181 , V_225 + 4 , & V_22 ) ;
F_15 ( & V_181 -> V_3 , L_21 , V_226 , V_28 , V_22 ) ;
V_11 -> V_11 . V_20 = V_25 ;
V_11 -> V_11 . V_22 = V_22 ;
V_11 -> V_11 . V_227 = F_101 ;
V_55 = F_95 ( & V_181 -> V_3 , sizeof( T_2 ) , V_186 ) ;
if ( ! V_55 )
return - V_19 ;
* V_55 = V_28 ;
V_11 -> V_11 . V_217 = V_55 ;
return 0 ;
}
static int F_105 ( struct V_2 * V_3 )
{
unsigned long V_22 ;
T_1 V_228 , V_61 ;
T_1 V_229 [ 3 ] ;
T_2 V_225 ;
struct V_8 * V_9 = F_106 ( V_3 ) ;
struct V_10 * V_11 ;
switch ( V_3 -> V_5 ) {
case 0x1104 :
case 0x1108 :
V_228 = V_3 -> V_5 & 0xff ;
break;
case 0x1112 :
V_228 = 12 ;
break;
default:
return - V_16 ;
}
F_14 ( V_3 , 0x24 , & V_229 [ 0 ] ) ;
F_14 ( V_3 , 0x20 , & V_229 [ 1 ] ) ;
F_14 ( V_3 , 0x1c , & V_229 [ 2 ] ) ;
for ( V_61 = 0 ; V_61 < V_228 ; ++ V_61 ) {
V_225 = 0x40 + 0x08 * V_61 ;
V_22 = ( V_229 [ V_61 / 4 ] & 0xffffffe0 ) + ( V_61 % 4 ) * 8 ;
F_34 ( V_3 , V_225 + 0x00 , 0x01 ) ;
F_34 ( V_3 , V_225 + 0x01 , 0x33 ) ;
F_34 ( V_3 , V_225 + 0x04 ,
( T_2 ) ( V_22 & 0xff ) ) ;
F_34 ( V_3 , V_225 + 0x05 ,
( T_2 ) ( ( V_22 & 0xff00 ) >> 8 ) ) ;
F_34 ( V_3 , V_225 + 0x06 , V_3 -> V_230 ) ;
if ( V_9 ) {
V_11 = F_107 ( V_9 -> line [ V_61 ] ) ;
F_101 ( & V_11 -> V_11 , NULL ) ;
} else {
F_34 ( V_3 , V_225 + 0x07 , 0x01 ) ;
}
}
return V_228 ;
}
static int F_108 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
V_11 -> V_11 . V_30 |= V_231 ;
F_15 ( & V_9 -> V_3 -> V_3 ,
L_22 ,
V_9 -> V_3 -> V_4 , V_9 -> V_3 -> V_5 ,
V_9 -> V_3 -> V_6 , V_9 -> V_3 -> V_7 ) ;
return F_51 ( V_9 , V_27 , V_11 , V_28 ) ;
}
static void F_109 ( struct V_155 * V_45 )
{
struct V_10 * V_232 = F_110 ( V_45 ) ;
F_111 ( V_232 ) ;
}
static unsigned int F_112 ( struct V_155 * V_45 , int V_13 )
{
struct V_10 * V_232 = F_110 ( V_45 ) ;
unsigned int V_123 ;
V_123 = F_57 ( V_45 -> V_22 + V_13 ) ;
if ( V_13 == V_233 ) {
if ( V_123 == 0 )
V_123 = V_232 -> V_234 ;
}
return V_123 ;
}
static int F_113 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
V_11 -> V_11 . V_30 |= V_235 ;
V_11 -> V_11 . V_236 = F_112 ;
V_11 -> V_11 . V_237 = F_109 ;
return F_108 ( V_9 , V_27 , V_11 , V_28 ) ;
}
static int F_114 ( struct V_2 * V_3 )
{
#if F_115 ( V_238 ) || F_115 ( V_239 )
return - V_43 ;
#else
return 0 ;
#endif
}
static int
F_116 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
V_11 -> V_11 . V_30 |= V_240 ;
return F_51 ( V_9 , V_27 , V_11 , V_28 ) ;
}
static inline int
F_117 ( struct V_8 * V_9 )
{
const int V_241 = V_9 -> V_3 -> V_5 ;
return ( ( V_241 == V_242 ) ||
( V_241 == V_243 ) ) ;
}
static int
F_118 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
T_2 T_3 * V_45 ;
V_45 = F_6 ( V_9 -> V_3 , 0 ) ;
if ( V_45 == NULL )
return - V_19 ;
V_11 -> V_11 . V_30 |= V_240 ;
if ( F_117 ( V_9 ) && V_28 >= 8 )
V_11 -> V_11 . V_147 = ( 7812500 * 16 / 2 ) ;
if ( V_28 == 0 ) {
F_26 ( 0x00 , V_45 + 0x8f ) ;
F_26 ( 0x00 , V_45 + 0x90 ) ;
F_26 ( 0x00 , V_45 + 0x91 ) ;
F_26 ( 0x00 , V_45 + 0x92 ) ;
F_26 ( 0x00 , V_45 + 0x93 ) ;
F_26 ( 0x00 , V_45 + 0x94 ) ;
F_26 ( 0x00 , V_45 + 0x95 ) ;
F_26 ( 0x00 , V_45 + 0x96 ) ;
F_26 ( 0x00 , V_45 + 0x97 ) ;
F_26 ( 0x00 , V_45 + 0x98 ) ;
F_26 ( 0x00 , V_45 + 0x99 ) ;
F_26 ( 0x00 , V_45 + 0x9a ) ;
}
F_26 ( 0x00 , V_45 + V_244 ) ;
F_26 ( V_245 , V_45 + V_246 ) ;
F_26 ( 128 , V_45 + V_247 ) ;
F_26 ( 128 , V_45 + V_248 ) ;
F_20 ( V_45 ) ;
return F_51 ( V_9 , V_27 , V_11 , V_28 ) ;
}
static int
F_119 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
T_2 T_3 * V_45 ;
V_45 = F_6 ( V_9 -> V_3 , 0 ) ;
if ( V_45 == NULL )
return - V_19 ;
V_11 -> V_11 . V_30 |= V_240 ;
if ( V_28 == 0 ) {
switch ( V_9 -> V_3 -> V_5 ) {
case V_249 :
case V_250 :
F_26 ( 0x78 , V_45 + 0x90 ) ;
F_26 ( 0x00 , V_45 + 0x92 ) ;
F_26 ( 0x00 , V_45 + 0x93 ) ;
break;
case V_251 :
case V_252 :
F_26 ( 0x00 , V_45 + 0x90 ) ;
F_26 ( 0xc0 , V_45 + 0x92 ) ;
F_26 ( 0xc0 , V_45 + 0x93 ) ;
break;
}
F_26 ( 0x00 , V_45 + 0x8f ) ;
F_26 ( 0x00 , V_45 + 0x91 ) ;
F_26 ( 0x00 , V_45 + 0x94 ) ;
}
F_26 ( 0x00 , V_45 + V_244 ) ;
F_26 ( V_245 , V_45 + V_246 ) ;
F_26 ( 32 , V_45 + V_247 ) ;
F_26 ( 32 , V_45 + V_248 ) ;
F_20 ( V_45 ) ;
return F_51 ( V_9 , V_27 , V_11 , V_28 ) ;
}
static int
F_120 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
V_11 -> V_11 . V_30 |= V_154 ;
V_11 -> V_11 . type = V_203 ;
return F_51 ( V_9 , V_27 , V_11 , V_28 ) ;
}
static int
F_121 ( struct V_8 * V_9 ,
const struct V_26 * V_27 ,
struct V_10 * V_11 , int V_28 )
{
V_11 -> V_11 . V_30 |= V_154 ;
V_11 -> V_11 . type = V_253 ;
return F_51 ( V_9 , V_27 , V_11 , V_28 ) ;
}
static inline int F_122 ( T_1 V_254 , T_1 V_241 )
{
return V_254 == V_255 || V_254 == V_241 ;
}
static struct V_256 * F_123 ( struct V_2 * V_3 )
{
struct V_256 * V_257 ;
for ( V_257 = V_258 ; ; V_257 ++ )
if ( F_122 ( V_257 -> V_4 , V_3 -> V_4 ) &&
F_122 ( V_257 -> V_5 , V_3 -> V_5 ) &&
F_122 ( V_257 -> V_259 , V_3 -> V_6 ) &&
F_122 ( V_257 -> V_260 , V_3 -> V_7 ) )
break;
return V_257 ;
}
static inline int F_124 ( struct V_2 * V_3 ,
const struct V_26 * V_27 )
{
if ( V_27 -> V_30 & V_261 )
return 0 ;
else
return V_3 -> V_230 ;
}
static int
F_125 ( struct V_2 * V_3 , struct V_26 * V_27 )
{
const struct V_262 * V_263 ;
int V_264 , V_265 , V_266 = - 1 , V_61 ;
if ( ( ( ( V_3 -> V_85 >> 8 ) != V_267 ) &&
( ( V_3 -> V_85 >> 8 ) != V_268 ) ) ||
( V_3 -> V_85 & 0xff ) > 6 )
return - V_43 ;
for ( V_263 = V_269 ;
V_263 < V_269 + F_40 ( V_269 ) ;
V_263 ++ ) {
if ( V_3 -> V_4 == V_263 -> V_4 &&
V_3 -> V_5 == V_263 -> V_5 )
return - V_43 ;
}
V_264 = V_265 = 0 ;
for ( V_61 = 0 ; V_61 < V_15 ; V_61 ++ ) {
if ( F_5 ( V_3 , V_61 ) & V_270 ) {
V_265 ++ ;
if ( V_266 == - 1 )
V_266 = V_61 ;
}
if ( F_5 ( V_3 , V_61 ) & V_17 )
V_264 ++ ;
}
if ( V_264 <= 1 && V_265 == 1 ) {
V_27 -> V_30 = V_266 ;
V_27 -> V_80 = F_84 ( V_3 , V_266 ) / 8 ;
return 0 ;
}
V_266 = - 1 ;
V_265 = 0 ;
for ( V_61 = 0 ; V_61 < V_15 ; V_61 ++ ) {
if ( F_5 ( V_3 , V_61 ) & V_270 &&
F_84 ( V_3 , V_61 ) == 8 &&
( V_266 == - 1 || ( V_266 + V_265 ) == V_61 ) ) {
V_265 ++ ;
if ( V_266 == - 1 )
V_266 = V_61 ;
}
}
if ( V_265 > 1 ) {
V_27 -> V_30 = V_266 | V_149 ;
V_27 -> V_80 = V_265 ;
return 0 ;
}
return - V_43 ;
}
static inline int
F_126 ( const struct V_26 * V_27 ,
const struct V_26 * V_271 )
{
return
V_27 -> V_80 == V_271 -> V_80 &&
V_27 -> V_272 == V_271 -> V_272 &&
V_27 -> V_31 == V_271 -> V_31 &&
V_27 -> V_32 == V_271 -> V_32 &&
V_27 -> V_29 == V_271 -> V_29 ;
}
struct V_8 *
F_127 ( struct V_2 * V_3 , const struct V_26 * V_27 )
{
struct V_10 V_273 ;
struct V_8 * V_9 ;
struct V_256 * V_257 ;
int V_33 , V_274 , V_61 ;
V_274 = V_27 -> V_80 ;
V_257 = F_123 ( V_3 ) ;
if ( V_257 -> V_275 ) {
V_33 = V_257 -> V_275 ( V_3 ) ;
if ( V_33 < 0 ) {
V_9 = F_128 ( V_33 ) ;
goto V_276;
}
if ( V_33 )
V_274 = V_33 ;
}
V_9 = F_129 ( sizeof( struct V_8 ) +
sizeof( unsigned int ) * V_274 ,
V_186 ) ;
if ( ! V_9 ) {
V_9 = F_128 ( - V_19 ) ;
goto V_277;
}
V_9 -> V_3 = V_3 ;
V_9 -> V_257 = V_257 ;
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
V_273 . V_11 . V_30 = V_278 | V_279 | V_280 ;
V_273 . V_11 . V_147 = V_27 -> V_272 * 16 ;
V_273 . V_11 . V_230 = F_124 ( V_3 , V_27 ) ;
V_273 . V_11 . V_3 = & V_3 -> V_3 ;
for ( V_61 = 0 ; V_61 < V_274 ; V_61 ++ ) {
if ( V_257 -> V_281 ( V_9 , V_27 , & V_273 , V_61 ) )
break;
F_15 ( & V_3 -> V_3 , L_23 ,
V_273 . V_11 . V_22 , V_273 . V_11 . V_230 , V_273 . V_11 . V_20 ) ;
V_9 -> line [ V_61 ] = F_130 ( & V_273 ) ;
if ( V_9 -> line [ V_61 ] < 0 ) {
F_2 ( & V_3 -> V_3 ,
L_24 ,
V_273 . V_11 . V_22 , V_273 . V_11 . V_230 ,
V_273 . V_11 . V_20 , V_9 -> line [ V_61 ] ) ;
break;
}
}
V_9 -> V_282 = V_61 ;
return V_9 ;
V_277:
if ( V_257 -> exit )
V_257 -> exit ( V_3 ) ;
V_276:
return V_9 ;
}
void F_131 ( struct V_8 * V_9 )
{
struct V_256 * V_257 ;
int V_61 ;
for ( V_61 = 0 ; V_61 < V_9 -> V_282 ; V_61 ++ )
F_132 ( V_9 -> line [ V_61 ] ) ;
for ( V_61 = 0 ; V_61 < V_15 ; V_61 ++ ) {
if ( V_9 -> V_18 [ V_61 ] )
F_20 ( V_9 -> V_18 [ V_61 ] ) ;
V_9 -> V_18 [ V_61 ] = NULL ;
}
V_257 = F_123 ( V_9 -> V_3 ) ;
if ( V_257 -> exit )
V_257 -> exit ( V_9 -> V_3 ) ;
F_133 ( V_9 ) ;
}
void F_134 ( struct V_8 * V_9 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_9 -> V_282 ; V_61 ++ )
if ( V_9 -> line [ V_61 ] >= 0 )
F_135 ( V_9 -> line [ V_61 ] ) ;
if ( V_9 -> V_257 -> exit )
V_9 -> V_257 -> exit ( V_9 -> V_3 ) ;
}
void F_136 ( struct V_8 * V_9 )
{
int V_61 ;
if ( V_9 -> V_257 -> V_275 )
V_9 -> V_257 -> V_275 ( V_9 -> V_3 ) ;
for ( V_61 = 0 ; V_61 < V_9 -> V_282 ; V_61 ++ )
if ( V_9 -> line [ V_61 ] >= 0 )
F_137 ( V_9 -> line [ V_61 ] ) ;
}
static int
F_138 ( struct V_2 * V_3 , const struct V_262 * V_283 )
{
struct V_256 * V_257 ;
struct V_8 * V_9 ;
const struct V_26 * V_27 ;
struct V_26 V_146 ;
int V_33 ;
V_257 = F_123 ( V_3 ) ;
if ( V_257 -> V_284 ) {
V_33 = V_257 -> V_284 ( V_3 ) ;
if ( V_33 )
return V_33 ;
}
if ( V_283 -> V_285 >= F_40 ( V_286 ) ) {
F_2 ( & V_3 -> V_3 , L_25 ,
V_283 -> V_285 ) ;
return - V_16 ;
}
V_27 = & V_286 [ V_283 -> V_285 ] ;
V_33 = F_139 ( V_3 ) ;
F_140 ( V_3 ) ;
if ( V_33 )
return V_33 ;
if ( V_283 -> V_285 == V_287 ) {
memcpy ( & V_146 , V_27 , sizeof( struct V_26 ) ) ;
V_27 = & V_146 ;
V_33 = F_125 ( V_3 , & V_146 ) ;
if ( V_33 )
goto V_288;
} else {
memcpy ( & V_146 , & V_286 [ V_287 ] ,
sizeof( struct V_26 ) ) ;
V_33 = F_125 ( V_3 , & V_146 ) ;
if ( V_33 == 0 && F_126 ( V_27 , & V_146 ) )
F_1 ( L_26 ,
V_3 ) ;
}
V_9 = F_127 ( V_3 , V_27 ) ;
if ( ! F_141 ( V_9 ) ) {
F_142 ( V_3 , V_9 ) ;
return 0 ;
}
V_33 = F_143 ( V_9 ) ;
V_288:
F_144 ( V_3 ) ;
return V_33 ;
}
static void F_145 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_106 ( V_3 ) ;
F_131 ( V_9 ) ;
F_144 ( V_3 ) ;
}
static int F_146 ( struct V_5 * V_3 )
{
struct V_2 * V_181 = F_147 ( V_3 ) ;
struct V_8 * V_9 = F_106 ( V_181 ) ;
if ( V_9 )
F_134 ( V_9 ) ;
return 0 ;
}
static int F_148 ( struct V_5 * V_3 )
{
struct V_2 * V_181 = F_147 ( V_3 ) ;
struct V_8 * V_9 = F_106 ( V_181 ) ;
int V_289 ;
if ( V_9 ) {
V_289 = F_139 ( V_181 ) ;
if ( V_289 )
F_2 ( V_3 , L_27 ) ;
F_136 ( V_9 ) ;
}
return 0 ;
}
static T_5 F_149 ( struct V_2 * V_3 ,
T_6 V_290 )
{
struct V_8 * V_9 = F_106 ( V_3 ) ;
if ( V_290 == V_291 )
return V_292 ;
if ( V_9 )
F_134 ( V_9 ) ;
F_144 ( V_3 ) ;
return V_293 ;
}
static T_5 F_150 ( struct V_2 * V_3 )
{
int V_33 ;
V_33 = F_139 ( V_3 ) ;
if ( V_33 )
return V_292 ;
F_151 ( V_3 ) ;
F_140 ( V_3 ) ;
return V_294 ;
}
static void F_152 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_106 ( V_3 ) ;
if ( V_9 )
F_136 ( V_9 ) ;
}
