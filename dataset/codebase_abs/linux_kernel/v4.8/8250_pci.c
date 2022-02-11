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
if ( ! F_6 ( V_3 , V_12 , 0 ) && ! F_7 ( V_3 ) )
return - V_18 ;
V_11 -> V_11 . V_19 = V_20 ;
V_11 -> V_11 . V_21 = 0 ;
V_11 -> V_11 . V_22 = F_8 ( V_3 , V_12 ) + V_13 ;
V_11 -> V_11 . V_23 = F_7 ( V_3 ) [ V_12 ] + V_13 ;
V_11 -> V_11 . V_14 = V_14 ;
} else {
V_11 -> V_11 . V_19 = V_24 ;
V_11 -> V_11 . V_21 = F_8 ( V_3 , V_12 ) + V_13 ;
V_11 -> V_11 . V_22 = 0 ;
V_11 -> V_11 . V_23 = NULL ;
V_11 -> V_11 . V_14 = 0 ;
}
return 0 ;
}
static int F_9 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
unsigned int V_12 = 0 , V_13 = V_26 -> V_28 ;
V_12 = F_10 ( V_26 -> V_29 ) ;
if ( V_27 < 2 ) {
V_13 += V_27 * V_26 -> V_30 ;
} else if ( ( V_27 >= 2 ) && ( V_27 < 4 ) ) {
V_12 += 1 ;
V_13 += ( ( V_27 - 2 ) * V_26 -> V_30 ) ;
} else if ( ( V_27 >= 4 ) && ( V_27 < 6 ) ) {
V_12 += 2 ;
V_13 += ( ( V_27 - 4 ) * V_26 -> V_30 ) ;
} else if ( V_27 >= 6 ) {
V_12 += 3 ;
V_13 += ( ( V_27 - 6 ) * V_26 -> V_30 ) ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_26 -> V_31 ) ;
}
static int
F_11 ( struct V_8 * V_9 , const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
unsigned int V_12 , V_13 = V_26 -> V_28 ;
V_12 = F_10 ( V_26 -> V_29 ) ;
if ( V_27 < 4 )
V_12 += V_27 ;
else {
V_12 = 4 ;
V_13 += ( V_27 - 4 ) * V_26 -> V_30 ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_26 -> V_31 ) ;
}
static int F_12 ( struct V_2 * V_3 )
{
int V_32 = 0 ;
switch ( V_3 -> V_7 ) {
case V_33 :
case V_34 :
case V_35 :
case V_36 :
V_32 = 3 ;
break;
case V_37 :
V_32 = 2 ;
break;
case V_38 :
V_32 = 4 ;
break;
case V_39 :
case V_40 :
V_32 = 1 ;
break;
}
return V_32 ;
}
static int
F_13 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
unsigned int V_13 = V_26 -> V_28 ;
unsigned int V_12 = F_10 ( V_26 -> V_29 ) ;
switch ( V_9 -> V_3 -> V_7 ) {
case V_38 :
if ( V_27 == 3 )
V_27 ++ ;
break;
case V_36 :
if ( V_27 > 0 )
V_27 ++ ;
if ( V_27 > 2 )
V_27 ++ ;
break;
}
if ( V_27 > 2 )
V_13 = 0x18 ;
V_13 += V_27 * V_26 -> V_30 ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_26 -> V_31 ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
T_1 V_41 ;
if ( ! ( V_3 -> V_7 & 0x1000 ) )
return - V_42 ;
F_15 ( V_3 , 0x44 , & V_41 ) ;
if ( V_41 == 0x00001000L ) {
F_16 ( & V_3 -> V_3 , L_6 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
T_2 V_43 ;
void T_3 * V_44 ;
if ( ( F_5 ( V_3 , 0 ) & V_17 ) == 0 ) {
F_1 ( L_7 , V_3 ) ;
return 0 ;
}
V_43 = 0x41 ;
if ( V_3 -> V_4 == V_45 ||
V_3 -> V_6 == V_46 )
V_43 = 0x43 ;
if ( ( V_3 -> V_4 == V_47 ) &&
( V_3 -> V_5 == V_48 ) )
V_43 = 0x5b ;
V_44 = F_18 ( F_8 ( V_3 , 0 ) , 0x80 ) ;
if ( V_44 == NULL )
return - V_18 ;
F_19 ( V_43 , V_44 + 0x4c ) ;
F_20 ( V_44 + 0x4c ) ;
F_21 ( V_44 ) ;
return 0 ;
}
static void F_22 ( struct V_2 * V_3 )
{
T_2 T_3 * V_44 ;
if ( ( F_5 ( V_3 , 0 ) & V_17 ) == 0 )
return;
V_44 = F_18 ( F_8 ( V_3 , 0 ) , 0x80 ) ;
if ( V_44 != NULL ) {
F_19 ( 0 , V_44 + 0x4c ) ;
F_20 ( V_44 + 0x4c ) ;
F_21 ( V_44 ) ;
}
}
static void F_23 ( struct V_2 * V_3 )
{
void T_3 * V_44 ;
unsigned int V_12 = 0 ;
if ( ( F_5 ( V_3 , V_12 ) & V_17 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return;
}
V_44 = F_24 ( V_3 , V_12 ) ;
if ( V_44 == NULL )
return;
F_19 ( F_20 ( V_44 + V_49 ) & ~ ( V_50 ) ,
V_44 + V_49 ) ;
F_21 ( V_44 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
void T_3 * V_44 ;
unsigned int V_12 = 0 ;
if ( ( F_5 ( V_3 , V_12 ) & V_17 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return;
}
V_44 = F_24 ( V_3 , V_12 ) ;
if ( V_44 == NULL )
return;
F_19 ( V_51 , V_44 + V_52 ) ;
F_21 ( V_44 ) ;
}
static int
F_26 ( struct V_8 * V_9 , const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
unsigned int V_12 , V_13 = V_26 -> V_28 ;
V_12 = 0 ;
if ( V_27 < 4 ) {
V_13 += V_27 * V_26 -> V_30 ;
} else if ( V_27 < 8 ) {
V_13 += V_27 * V_26 -> V_30 + 0xC00 ;
} else
return 1 ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_26 -> V_31 ) ;
}
static int F_27 ( struct V_2 * V_3 )
{
T_2 T_3 * V_44 ;
V_44 = F_24 ( V_3 , 0 ) ;
if ( V_44 == NULL )
return - V_18 ;
F_28 ( 0x10 , V_44 + V_53 ) ;
F_29 ( 50 ) ;
F_28 ( 0x0 , V_44 + V_53 ) ;
F_28 ( 0x4 , V_44 + V_53 ) ;
F_21 ( V_44 ) ;
return 0 ;
}
static void F_30 ( struct V_2 * V_3 )
{
T_2 T_3 * V_44 ;
V_44 = F_24 ( V_3 , 0 ) ;
if ( V_44 != NULL )
F_28 ( 0 , V_44 + V_53 ) ;
F_21 ( V_44 ) ;
}
static int F_31 ( struct V_2 * V_3 )
{
T_4 V_54 ;
void T_3 * V_44 ;
switch ( V_3 -> V_5 & 0xfff8 ) {
case V_55 :
V_54 = 0xffdf ;
break;
case V_56 :
V_54 = 0xf7ff ;
break;
default:
V_54 = 0xfffb ;
break;
}
V_44 = F_18 ( F_8 ( V_3 , 0 ) , 0x80 ) ;
if ( V_44 == NULL )
return - V_18 ;
F_32 ( F_33 ( V_44 + 0x28 ) & V_54 , V_44 + 0x28 ) ;
F_33 ( V_44 + 0x28 ) ;
F_21 ( V_44 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 )
{
T_2 V_54 ;
F_35 ( V_3 , 0x6f , & V_54 ) ;
F_36 ( V_3 , 0x6f , V_54 & 0xef ) ;
if ( ( ( V_3 -> V_5 & 0xfffc ) == V_57 ) ||
( ( V_3 -> V_5 & 0xfffc ) == V_58 ) ) {
F_35 ( V_3 , 0x73 , & V_54 ) ;
F_36 ( V_3 , 0x73 , V_54 & 0xef ) ;
}
return 0 ;
}
static int F_37 ( struct V_2 * V_3 )
{
unsigned int type = V_3 -> V_5 & 0xff00 ;
if ( type == 0x1000 )
return F_31 ( V_3 ) ;
else if ( type == 0x2000 )
return F_34 ( V_3 ) ;
F_1 ( L_9 , V_3 ) ;
return - V_42 ;
}
static int F_38 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
unsigned int V_12 = F_10 ( V_26 -> V_29 ) + V_27 , V_13 = 0 ;
if ( V_27 > 3 ) {
V_12 = 4 ;
V_13 = ( V_27 - 4 ) * 8 ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , 0 ) ;
}
static int F_39 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_7 & 0x00f0 ) >= 0x70 ) {
F_40 ( & V_3 -> V_3 ,
L_10 ,
V_3 -> V_7 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_41 ( struct V_2 * V_3 )
{
const unsigned short * V_59 ;
int V_60 , V_61 ;
for ( V_60 = 0 ; V_60 < F_42 ( V_62 ) ; V_60 ++ ) {
V_59 = V_62 [ V_60 ] . V_59 ;
for ( V_61 = 0 ; V_59 [ V_61 ] ; V_61 ++ )
if ( V_3 -> V_7 == V_59 [ V_61 ] )
return V_62 [ V_60 ] . V_63 ;
}
return 0 ;
}
static int
F_43 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
unsigned int V_12 = 0 , V_13 = V_26 -> V_28 ;
switch ( V_27 ) {
case 0 :
V_12 = 0 ;
break;
case 1 :
V_13 = V_26 -> V_30 ;
V_12 = 0 ;
break;
case 2 :
V_12 = 1 ;
break;
case 3 :
V_13 = V_26 -> V_30 ;
case 4 :
case 5 :
case 6 :
case 7 :
V_12 = V_27 - 2 ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_26 -> V_31 ) ;
}
static int
F_44 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
unsigned int V_12 , V_13 = V_26 -> V_28 ;
switch ( V_27 ) {
case 0 :
V_12 = 1 ;
break;
case 1 :
V_12 = 2 ;
break;
default:
V_12 = 4 ;
V_13 = ( V_27 - 2 ) * V_26 -> V_30 ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_26 -> V_31 ) ;
}
static int F_45 ( struct V_2 * V_3 )
{
F_46 ( 100 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
void T_3 * V_44 ;
unsigned int V_12 = 0 ;
if ( ( F_5 ( V_3 , V_12 ) & V_17 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return 0 ;
}
V_44 = F_24 ( V_3 , V_12 ) ;
if ( V_44 == NULL )
return - V_18 ;
F_19 ( F_20 ( V_44 + V_49 ) | V_50 ,
V_44 + V_49 ) ;
F_21 ( V_44 ) ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 )
{
void T_3 * V_44 ;
struct V_64 V_65 ;
T_1 V_66 ;
unsigned int V_12 = 0 ;
if ( ( F_5 ( V_3 , V_12 ) & V_17 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return 0 ;
}
V_44 = F_24 ( V_3 , V_12 ) ;
if ( V_44 == NULL )
return - V_18 ;
F_49 ( V_3 -> V_67 , & V_65 , & V_3 -> V_68 [ V_12 ] ) ;
V_66 = ( ( V_65 . V_69 + V_70 ) & 0xffffff00 )
| V_71 | V_72 ;
F_19 ( V_66 , V_44 + V_73 ) ;
F_19 ( ( F_20 ( V_44 + V_74 ) & V_75 ) ,
V_44 + V_74 ) ;
F_19 ( V_76 , V_44 + V_77 ) ;
F_19 ( V_78 , V_44 + V_52 ) ;
F_21 ( V_44 ) ;
return 0 ;
}
static int
F_50 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
struct V_2 * V_3 = V_9 -> V_3 ;
void T_3 * V_44 ;
unsigned int V_12 , V_13 = V_26 -> V_28 ;
if ( V_27 >= V_26 -> V_79 )
return 1 ;
V_12 = F_10 ( V_26 -> V_29 ) ;
V_13 += V_27 * V_26 -> V_30 ;
V_44 = F_24 ( V_3 , V_12 ) ;
if ( ! V_44 )
return - V_18 ;
F_28 ( F_51 ( V_44 + V_13 + V_80 ) | V_81 ,
V_44 + V_13 + V_80 ) ;
F_21 ( V_44 ) ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_26 -> V_31 ) ;
}
static int F_52 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
unsigned int V_12 ;
if ( ( V_9 -> V_3 -> V_5 != V_82 ) &&
( V_9 -> V_3 -> V_7 & 0xff00 ) == 0x3000 ) {
V_12 = 3 * V_27 ;
return F_4 ( V_9 , V_11 , V_12 , 0 , V_26 -> V_31 ) ;
} else {
return F_53 ( V_9 , V_26 , V_11 , V_27 ) ;
}
}
static int F_54 ( struct V_2 * V_3 )
{
unsigned int V_83 = V_3 -> V_84 ;
unsigned int V_85 ;
unsigned short V_86 ;
V_85 = V_83 & 0xff ;
if ( V_85 == 2 )
return 1 ;
if ( ( V_85 == 0 ) && ( V_3 -> V_5 == V_87 ) ) {
V_86 = V_3 -> V_7 & 0xf ;
if ( V_86 > 0 )
return V_86 ;
F_2 ( & V_3 -> V_3 ,
L_11 ) ;
return 0 ;
}
F_1 ( L_12 , V_3 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
unsigned int V_88 = V_3 -> V_7 & 0xf ;
if ( ( V_3 -> V_5 == V_89 ) ||
( V_3 -> V_5 == V_82 ) )
return 0 ;
if ( V_3 -> V_6 == V_90 &&
V_3 -> V_7 == 0x0299 )
return 0 ;
switch ( V_3 -> V_5 ) {
case V_91 :
case V_92 :
case V_93 :
case V_87 :
V_88 = F_54 ( V_3 ) ;
break;
default:
break;
}
if ( V_88 == 0 ) {
F_1 ( L_13 , V_3 ) ;
return - V_42 ;
}
return V_88 ;
}
static int F_56 ( struct V_2 * V_3 )
{
static const short V_94 [] = { 0x2a0 , 0x2c0 , 0x220 , 0x240 , 0x1e0 ,
0x200 , 0x280 , 0 } ;
int V_95 , V_60 , type ;
struct V_68 * V_21 = NULL ;
T_1 V_96 , V_97 , V_98 ;
V_60 = 0 ;
while ( V_94 [ V_60 ] && V_21 == NULL ) {
V_21 = F_57 ( V_94 [ V_60 ] , V_99 ,
L_14 ) ;
if ( V_21 != NULL ) {
F_58 ( V_3 , V_100 ,
V_101 | V_102 |
V_103 | V_94 [ V_60 ] ) ;
F_58 ( V_3 , V_104 ,
V_94 [ V_60 ] ) ;
V_95 = F_59 ( V_94 [ V_60 ] ) ;
if ( V_95 != 0xff ) {
break;
}
F_60 ( V_21 -> V_69 , V_99 ) ;
V_21 = NULL ;
}
V_60 ++ ;
}
if ( ! V_94 [ V_60 ] ) {
F_2 ( & V_3 -> V_3 , L_15 ) ;
return - V_42 ;
}
type = F_59 ( V_21 -> V_69 + 0x18 ) & 0x0f ;
switch ( type ) {
case 0x2 :
case 0xa :
V_95 = 0 ;
break;
case 0xe :
V_95 = 2 ;
break;
case 0x6 :
V_95 = 1 ;
break;
case 0x8 :
V_95 = 2 ;
break;
default:
F_1 ( L_16 , V_3 ) ;
V_95 = - V_42 ;
}
for ( V_60 = 0 ; V_60 < V_95 ; V_60 ++ ) {
F_15 ( V_3 , V_105 + ( 0x4 * ( V_60 + 1 ) ) ,
& V_98 ) ;
V_98 &= 0x0000FF00 ;
F_58 ( V_3 , V_100 + ( 0x4 * ( V_60 + 1 ) ) ,
V_101 | V_102 |
V_106 | V_98 ) ;
F_15 ( V_3 , V_107 , & V_97 ) ;
V_97 &= ~ ( 0xffff << ( 16 * V_60 ) ) ;
V_97 |= ( V_98 << ( 16 * V_60 ) ) ;
F_58 ( V_3 , V_107 , V_97 ) ;
F_15 ( V_3 , V_108 , & V_96 ) ;
V_96 &= ~ ( 0xf << ( 12 - 4 * V_60 ) ) ;
V_96 |= 1 << ( 23 - V_60 ) ;
F_58 ( V_3 , V_108 , V_96 ) ;
}
if ( V_95 <= 0 ) {
F_60 ( V_21 -> V_69 , V_99 ) ;
}
return V_95 ;
}
static void F_61 ( struct V_2 * V_3 )
{
T_1 V_98 ;
F_15 ( V_3 , V_100 , & V_98 ) ;
V_98 &= 0xffff ;
F_60 ( V_98 , V_99 ) ;
}
static int F_62 ( struct V_2 * V_3 )
{
T_2 T_3 * V_44 ;
unsigned long V_109 ;
unsigned int V_110 = 0 ;
if ( V_3 -> V_4 == V_111 &&
( V_3 -> V_5 & 0xf000 ) != 0xe000 )
return 0 ;
V_44 = F_63 ( V_3 , 0 , 5 ) ;
if ( V_44 == NULL )
return - V_18 ;
V_109 = F_64 ( V_44 ) ;
if ( V_109 == 0x07000200 ) {
V_110 = F_65 ( V_44 + 4 ) ;
F_16 ( & V_3 -> V_3 ,
L_17 ,
V_110 ) ;
}
F_66 ( V_3 , V_44 ) ;
return V_110 ;
}
static int F_67 ( struct V_2 * V_3 )
{
T_2 T_3 * V_44 ;
unsigned long V_109 ;
unsigned int V_110 = 0 ;
if ( V_3 -> V_4 == V_112 &&
( V_3 -> V_5 & 0xF000 ) != 0xC000 )
return 0 ;
V_44 = F_63 ( V_3 , 0 , 5 ) ;
if ( V_44 == NULL )
return - V_18 ;
V_109 = F_64 ( V_44 ) ;
if ( V_109 == 0x07000200 ) {
V_110 = F_65 ( V_44 + 4 ) ;
F_16 ( & V_3 -> V_3 ,
L_18 ,
V_110 ) ;
}
F_66 ( V_3 , V_44 ) ;
return V_110 ;
}
static int F_68 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
V_11 -> V_113 |= V_114 ;
return F_53 ( V_9 , V_26 , V_11 , V_27 ) ;
}
static int F_69 ( T_4 V_115 )
{
struct V_116 * V_117 = & V_118 [ 0 ] ;
while ( V_117 -> V_115 ) {
if ( V_117 -> V_115 == V_115 )
return V_117 -> V_119 ;
V_117 ++ ;
}
F_70 ( L_19 , V_115 ) ;
return 0 ;
}
static int F_71 ( struct V_10 * V_11 )
{
unsigned long V_120 = V_11 -> V_11 . V_21 ;
T_2 V_121 , V_122 ;
V_121 = F_59 ( V_120 + V_123 ) ;
F_72 ( 0xBF , V_120 + V_123 ) ;
V_122 = F_59 ( V_120 + V_124 ) ;
F_72 ( V_121 , V_120 + V_123 ) ;
return V_122 ;
}
static void F_73 ( struct V_10 * V_11 , T_2 V_125 )
{
unsigned long V_120 = V_11 -> V_11 . V_21 ;
T_2 V_121 ;
V_121 = F_59 ( V_120 + V_123 ) ;
F_72 ( 0xBF , V_120 + V_123 ) ;
F_59 ( V_120 + V_124 ) ;
F_72 ( V_125 , V_120 + V_124 ) ;
F_72 ( V_121 , V_120 + V_123 ) ;
}
static int F_74 ( struct V_10 * V_11 )
{
unsigned long V_120 = V_11 -> V_11 . V_21 ;
T_2 V_121 , V_122 , V_126 ;
V_121 = F_59 ( V_120 + V_123 ) ;
F_72 ( 0xBF , V_120 + V_123 ) ;
V_122 = F_59 ( V_120 + V_124 ) ;
F_72 ( V_122 | 0x10 , V_120 + V_124 ) ;
V_126 = F_59 ( V_120 + V_127 ) ;
F_72 ( V_122 , V_120 + V_124 ) ;
F_72 ( V_121 , V_120 + V_123 ) ;
return V_126 ;
}
static void F_75 ( struct V_10 * V_11 , T_2 V_126 )
{
unsigned long V_120 = V_11 -> V_11 . V_21 ;
T_2 V_121 , V_122 ;
V_121 = F_59 ( V_120 + V_123 ) ;
F_72 ( 0xBF , V_120 + V_123 ) ;
V_122 = F_59 ( V_120 + V_124 ) ;
F_72 ( V_122 | 0x10 , V_120 + V_124 ) ;
F_72 ( V_126 , V_120 + V_127 ) ;
F_72 ( V_122 , V_120 + V_124 ) ;
F_72 ( V_121 , V_120 + V_123 ) ;
}
static int F_76 ( struct V_10 * V_11 )
{
unsigned long V_120 = V_11 -> V_11 . V_21 ;
T_2 V_121 , V_122 ;
V_121 = F_59 ( V_120 + V_123 ) ;
F_72 ( 0xBF , V_120 + V_123 ) ;
V_122 = F_59 ( V_120 + V_124 ) ;
if ( V_122 & 0x20 ) {
F_72 ( 0x80 , V_123 ) ;
if ( ! ( F_59 ( V_124 ) & 0x20 ) ) {
F_72 ( V_121 , V_120 + V_123 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_77 ( struct V_10 * V_11 )
{
T_2 V_128 , V_125 ;
V_125 = F_71 ( V_11 ) ;
F_73 ( V_11 , V_125 & V_129 ) ;
V_128 = F_71 ( V_11 ) & 0xC0 ;
if ( V_128 != V_130 )
return - V_16 ;
F_73 ( V_11 , ( V_125 & V_129 ) | V_131 ) ;
V_128 = F_71 ( V_11 ) & 0xC0 ;
if ( V_128 != V_132 )
return - V_16 ;
F_73 ( V_11 , ( V_125 & V_129 ) | V_133 ) ;
V_128 = F_71 ( V_11 ) & 0xC0 ;
if ( V_128 != V_134 )
return - V_16 ;
F_73 ( V_11 , ( V_125 & V_129 ) | V_135 ) ;
V_128 = F_71 ( V_11 ) & 0xC0 ;
if ( V_128 != V_136 )
return - V_16 ;
F_73 ( V_11 , V_125 ) ;
return 0 ;
}
static int F_78 ( struct V_10 * V_11 )
{
T_2 V_125 , V_128 , V_137 ;
unsigned long clock ;
if ( F_77 ( V_11 ) < 0 )
return 1843200 ;
V_125 = F_71 ( V_11 ) ;
F_73 ( V_11 , V_125 & ~ V_138 ) ;
V_128 = F_71 ( V_11 ) ;
if ( V_128 & V_138 ) {
clock = 1843200 ;
goto V_139;
}
F_73 ( V_11 , V_125 | V_138 ) ;
V_128 = F_71 ( V_11 ) ;
if ( ! ( V_128 & V_138 ) ) {
clock = 1843200 ;
goto V_139;
}
V_128 &= V_138 ;
if ( V_128 == V_140 ) {
clock = 3685400 ;
V_137 = V_140 ;
} else if ( V_128 == V_141 ) {
clock = 7372800 ;
V_137 = V_141 ;
} else if ( V_128 == V_138 ) {
clock = 14745600 ;
V_137 = V_138 ;
} else {
clock = 1843200 ;
V_137 = V_142 ;
}
V_125 &= ~ V_143 ;
V_125 |= V_137 ;
V_139:
F_73 ( V_11 , V_125 ) ;
return clock ;
}
static int F_79 ( struct V_10 * V_11 )
{
T_2 V_126 ;
int V_144 = 0 ;
if ( ! F_76 ( V_11 ) )
return 0 ;
V_126 = F_74 ( V_11 ) ;
F_75 ( V_11 , 0xFF ) ;
if ( F_74 ( V_11 ) )
V_144 = 1 ;
F_75 ( V_11 , V_126 ) ;
return V_144 ;
}
static int F_80 ( struct V_2 * V_3 )
{
if ( F_69 ( V_3 -> V_5 ) ) {
unsigned long V_120 = F_8 ( V_3 , 0 ) ;
if ( V_120 ) {
T_1 V_145 ;
F_81 ( F_82 ( V_120 + 0x38 ) | 0x00002000 , V_120 + 0x38 ) ;
V_145 = F_82 ( V_120 + 0x3c ) ;
F_81 ( V_145 | 0x01000000 , V_120 + 0x3c ) ;
F_81 ( V_145 &= ~ 0x01000000 , V_120 + 0x3c ) ;
}
}
return 0 ;
}
static int F_83 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
V_11 -> V_11 . V_21 = F_8 ( V_9 -> V_3 , F_10 ( V_26 -> V_29 ) ) ;
V_11 -> V_11 . V_146 = F_78 ( V_11 ) ;
if ( F_79 ( V_11 ) )
F_84 ( L_20 ) ;
return F_53 ( V_9 , V_26 , V_11 , V_27 ) ;
}
static void F_85 ( struct V_2 * V_3 )
{
}
static int F_53 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
unsigned int V_12 , V_13 = V_26 -> V_28 , V_147 ;
V_12 = F_10 ( V_26 -> V_29 ) ;
if ( V_26 -> V_29 & V_148 )
V_12 += V_27 ;
else
V_13 += V_27 * V_26 -> V_30 ;
V_147 = ( F_86 ( V_9 -> V_3 , V_12 ) - V_26 -> V_28 ) >>
( V_26 -> V_31 + 3 ) ;
if ( V_26 -> V_29 & V_149 && V_27 >= V_147 )
return 1 ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_26 -> V_31 ) ;
}
static int
F_87 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
int V_95 ;
V_95 = F_4 ( V_9 , V_11 , V_27 , 0 , V_26 -> V_31 ) ;
V_11 -> V_11 . V_19 = V_150 ;
V_11 -> V_11 . type = V_151 ;
V_11 -> V_11 . V_29 = ( V_11 -> V_11 . V_29 | V_152 | V_153 ) ;
V_11 -> V_11 . V_14 = 2 ;
return V_95 ;
}
static void
F_88 ( struct V_154 * V_44 , struct V_155 * V_156 ,
struct V_155 * V_157 )
{
unsigned int V_158 = F_89 ( V_156 ) ;
unsigned long V_159 = 100000000 , V_160 = V_158 * 16 ;
unsigned long V_161 = F_90 ( 15 ) - 1 ;
unsigned long V_162 , V_163 ;
T_1 V_128 ;
V_160 = V_160 ? V_160 : 9600 * 16 ;
V_160 *= F_91 ( V_159 / V_160 ) ;
F_92 ( V_160 , V_159 , V_161 , V_161 , & V_162 , & V_163 ) ;
V_44 -> V_146 = V_160 ;
V_128 = ( V_162 << V_164 ) | ( V_163 << V_165 ) ;
F_19 ( V_128 , V_44 -> V_23 + V_166 ) ;
V_128 |= V_167 | V_168 ;
F_19 ( V_128 , V_44 -> V_23 + V_166 ) ;
V_44 -> V_169 &= ~ V_170 ;
if ( V_156 -> V_171 & V_172 )
V_44 -> V_169 |= V_170 ;
F_93 ( V_44 , V_156 , V_157 ) ;
}
static bool F_94 ( struct V_173 * V_174 , void * V_175 )
{
struct V_176 * V_177 = V_175 ;
if ( V_177 -> V_178 != V_174 -> V_5 -> V_3 )
return false ;
V_174 -> V_179 = V_177 ;
return true ;
}
static unsigned int
F_95 ( struct V_154 * V_11 )
{
unsigned int V_95 = F_96 ( V_11 ) ;
V_95 |= V_180 | V_181 ;
return V_95 ;
}
static int
F_97 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
struct V_2 * V_182 = V_9 -> V_3 ;
struct V_5 * V_3 = V_11 -> V_11 . V_3 ;
struct V_183 * V_184 ;
struct V_176 * V_185 , * V_186 ;
struct V_2 * V_178 ;
int V_95 ;
V_184 = F_98 ( V_3 , sizeof( * V_184 ) , V_187 ) ;
if ( ! V_184 )
return - V_18 ;
V_185 = F_98 ( V_3 , sizeof( * V_185 ) , V_187 ) ;
if ( ! V_185 )
return - V_18 ;
V_186 = F_98 ( V_3 , sizeof( * V_186 ) , V_187 ) ;
if ( ! V_186 )
return - V_18 ;
switch ( V_182 -> V_5 ) {
case V_188 :
case V_189 :
case V_190 :
V_186 -> V_191 = 3 ;
V_185 -> V_192 = 2 ;
break;
case V_193 :
case V_194 :
case V_195 :
V_186 -> V_191 = 5 ;
V_185 -> V_192 = 4 ;
break;
default:
return - V_16 ;
}
V_186 -> V_196 = 0 ;
V_186 -> V_197 = 1 ;
V_184 -> V_198 . V_199 = 16 ;
V_185 -> V_196 = 0 ;
V_185 -> V_197 = 1 ;
V_184 -> V_200 . V_201 = 16 ;
V_178 = F_99 ( V_182 -> V_67 , F_100 ( F_101 ( V_182 -> V_202 ) , 0 ) ) ;
V_186 -> V_178 = & V_178 -> V_3 ;
V_185 -> V_178 = & V_178 -> V_3 ;
V_184 -> V_203 = F_94 ;
V_184 -> V_186 = V_186 ;
V_184 -> V_185 = V_185 ;
V_95 = F_53 ( V_9 , V_26 , V_11 , V_27 ) ;
V_11 -> V_11 . V_19 = V_20 ;
V_11 -> V_11 . type = V_204 ;
V_11 -> V_11 . V_29 = ( V_11 -> V_11 . V_29 | V_152 | V_153 ) ;
V_11 -> V_11 . V_205 = F_88 ;
V_11 -> V_11 . V_206 = F_95 ;
V_11 -> V_11 . V_207 = 64 ;
V_11 -> V_208 = 64 ;
V_11 -> V_184 = V_184 ;
V_11 -> V_209 = V_210 | V_211 ;
F_19 ( V_212 , V_11 -> V_11 . V_23 + V_213 ) ;
return V_95 ;
}
static int
F_102 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
return F_4 ( V_9 , V_11 , 2 , V_27 * 8 , 0 ) ;
}
static int
F_103 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
int V_95 = F_53 ( V_9 , V_26 , V_11 , V_27 ) ;
V_11 -> V_11 . type = V_214 ;
V_11 -> V_11 . V_29 = ( V_11 -> V_11 . V_29 | V_152 | V_153 ) ;
return V_95 ;
}
static int F_104 ( struct V_154 * V_11 ,
struct V_215 * V_216 )
{
struct V_2 * V_2 = F_105 ( V_11 -> V_3 ) ;
T_2 V_217 ;
T_2 * V_218 = ( T_2 * ) V_11 -> V_219 ;
F_35 ( V_2 , 0x40 + 8 * * V_218 + 7 , & V_217 ) ;
if ( ! V_216 )
V_216 = & V_11 -> V_216 ;
else if ( V_216 -> V_29 & V_220 )
memset ( V_216 -> V_221 , 0 , sizeof( V_216 -> V_221 ) ) ;
else
memset ( V_216 , 0 , sizeof( * V_216 ) ) ;
V_216 -> V_29 &= V_220 | V_222 ;
if ( V_216 -> V_29 & V_220 ) {
V_217 |= V_223 ;
if ( V_216 -> V_29 & V_222 ) {
V_217 &= ~ V_224 ;
} else {
V_217 |= V_224 ;
}
V_216 -> V_225 = 0 ;
V_216 -> V_226 = 0 ;
} else {
V_217 &= ~ ( V_223 | V_224 ) ;
}
F_36 ( V_2 , 0x40 + 8 * * V_218 + 7 , V_217 ) ;
if ( V_216 != & V_11 -> V_216 )
V_11 -> V_216 = * V_216 ;
return 0 ;
}
static int F_106 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
struct V_2 * V_182 = V_9 -> V_3 ;
T_2 * V_54 ;
T_2 V_227 ;
T_4 V_21 ;
V_227 = 0x40 + 0x08 * V_27 ;
F_107 ( V_182 , V_227 + 4 , & V_21 ) ;
F_16 ( & V_182 -> V_3 , L_21 , V_228 , V_27 , V_21 ) ;
V_11 -> V_11 . V_19 = V_24 ;
V_11 -> V_11 . V_21 = V_21 ;
V_11 -> V_11 . V_229 = F_104 ;
V_54 = F_98 ( & V_182 -> V_3 , sizeof( T_2 ) , V_187 ) ;
if ( ! V_54 )
return - V_18 ;
* V_54 = V_27 ;
V_11 -> V_11 . V_219 = V_54 ;
return 0 ;
}
static int F_108 ( struct V_2 * V_3 )
{
unsigned long V_21 ;
T_1 V_230 , V_60 ;
T_1 V_231 [ 3 ] ;
T_2 V_227 ;
struct V_8 * V_9 = F_109 ( V_3 ) ;
struct V_10 * V_11 ;
switch ( V_3 -> V_5 ) {
case 0x1104 :
case 0x1108 :
V_230 = V_3 -> V_5 & 0xff ;
break;
case 0x1112 :
V_230 = 12 ;
break;
default:
return - V_16 ;
}
F_15 ( V_3 , 0x24 , & V_231 [ 0 ] ) ;
F_15 ( V_3 , 0x20 , & V_231 [ 1 ] ) ;
F_15 ( V_3 , 0x1c , & V_231 [ 2 ] ) ;
for ( V_60 = 0 ; V_60 < V_230 ; ++ V_60 ) {
V_227 = 0x40 + 0x08 * V_60 ;
V_21 = ( V_231 [ V_60 / 4 ] & 0xffffffe0 ) + ( V_60 % 4 ) * 8 ;
F_36 ( V_3 , V_227 + 0x00 , 0x01 ) ;
F_36 ( V_3 , V_227 + 0x01 , 0x33 ) ;
F_36 ( V_3 , V_227 + 0x04 ,
( T_2 ) ( V_21 & 0xff ) ) ;
F_36 ( V_3 , V_227 + 0x05 ,
( T_2 ) ( ( V_21 & 0xff00 ) >> 8 ) ) ;
F_36 ( V_3 , V_227 + 0x06 , V_3 -> V_232 ) ;
if ( V_9 ) {
V_11 = F_110 ( V_9 -> line [ V_60 ] ) ;
F_104 ( & V_11 -> V_11 , NULL ) ;
} else {
F_36 ( V_3 , V_227 + 0x07 , 0x01 ) ;
}
}
return V_230 ;
}
static int F_111 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
V_11 -> V_11 . V_29 |= V_233 ;
F_16 ( & V_9 -> V_3 -> V_3 ,
L_22 ,
V_9 -> V_3 -> V_4 , V_9 -> V_3 -> V_5 ,
V_9 -> V_3 -> V_6 , V_9 -> V_3 -> V_7 ) ;
return F_53 ( V_9 , V_26 , V_11 , V_27 ) ;
}
static void F_112 ( struct V_154 * V_44 )
{
struct V_10 * V_234 = F_113 ( V_44 ) ;
F_114 ( V_234 ) ;
}
static unsigned int F_115 ( struct V_154 * V_44 , int V_13 )
{
struct V_10 * V_234 = F_113 ( V_44 ) ;
unsigned int V_122 ;
V_122 = F_59 ( V_44 -> V_21 + V_13 ) ;
if ( V_13 == V_235 ) {
if ( V_122 == 0 )
V_122 = V_234 -> V_236 ;
}
return V_122 ;
}
static int F_116 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
V_11 -> V_11 . V_29 |= V_237 ;
V_11 -> V_11 . V_238 = F_115 ;
V_11 -> V_11 . V_239 = F_112 ;
return F_111 ( V_9 , V_26 , V_11 , V_27 ) ;
}
static int F_117 ( struct V_2 * V_3 )
{
#if F_118 ( V_240 ) || F_118 ( V_241 )
return - V_42 ;
#else
return 0 ;
#endif
}
static int
F_119 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
V_11 -> V_11 . V_29 |= V_242 ;
return F_53 ( V_9 , V_26 , V_11 , V_27 ) ;
}
static inline int
F_120 ( struct V_8 * V_9 )
{
const int V_243 = V_9 -> V_3 -> V_5 ;
return ( ( V_243 == V_244 ) ||
( V_243 == V_245 ) ) ;
}
static int
F_121 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
T_2 T_3 * V_44 ;
V_44 = F_24 ( V_9 -> V_3 , 0 ) ;
if ( V_44 == NULL )
return - V_18 ;
V_11 -> V_11 . V_29 |= V_242 ;
if ( F_120 ( V_9 ) && V_27 >= 8 )
V_11 -> V_11 . V_146 = ( 7812500 * 16 / 2 ) ;
if ( V_27 == 0 ) {
F_28 ( 0x00 , V_44 + 0x8f ) ;
F_28 ( 0x00 , V_44 + 0x90 ) ;
F_28 ( 0x00 , V_44 + 0x91 ) ;
F_28 ( 0x00 , V_44 + 0x92 ) ;
F_28 ( 0x00 , V_44 + 0x93 ) ;
F_28 ( 0x00 , V_44 + 0x94 ) ;
F_28 ( 0x00 , V_44 + 0x95 ) ;
F_28 ( 0x00 , V_44 + 0x96 ) ;
F_28 ( 0x00 , V_44 + 0x97 ) ;
F_28 ( 0x00 , V_44 + 0x98 ) ;
F_28 ( 0x00 , V_44 + 0x99 ) ;
F_28 ( 0x00 , V_44 + 0x9a ) ;
}
F_28 ( 0x00 , V_44 + V_246 ) ;
F_28 ( V_247 , V_44 + V_248 ) ;
F_28 ( 128 , V_44 + V_249 ) ;
F_28 ( 128 , V_44 + V_250 ) ;
F_21 ( V_44 ) ;
return F_53 ( V_9 , V_26 , V_11 , V_27 ) ;
}
static int
F_122 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
T_2 T_3 * V_44 ;
V_44 = F_24 ( V_9 -> V_3 , 0 ) ;
if ( V_44 == NULL )
return - V_18 ;
V_11 -> V_11 . V_29 |= V_242 ;
if ( V_27 == 0 ) {
switch ( V_9 -> V_3 -> V_5 ) {
case V_251 :
case V_252 :
F_28 ( 0x78 , V_44 + 0x90 ) ;
F_28 ( 0x00 , V_44 + 0x92 ) ;
F_28 ( 0x00 , V_44 + 0x93 ) ;
break;
case V_253 :
case V_254 :
F_28 ( 0x00 , V_44 + 0x90 ) ;
F_28 ( 0xc0 , V_44 + 0x92 ) ;
F_28 ( 0xc0 , V_44 + 0x93 ) ;
break;
}
F_28 ( 0x00 , V_44 + 0x8f ) ;
F_28 ( 0x00 , V_44 + 0x91 ) ;
F_28 ( 0x00 , V_44 + 0x94 ) ;
}
F_28 ( 0x00 , V_44 + V_246 ) ;
F_28 ( V_247 , V_44 + V_248 ) ;
F_28 ( 32 , V_44 + V_249 ) ;
F_28 ( 32 , V_44 + V_250 ) ;
F_21 ( V_44 ) ;
return F_53 ( V_9 , V_26 , V_11 , V_27 ) ;
}
static int
F_123 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
V_11 -> V_11 . V_29 |= V_153 ;
V_11 -> V_11 . type = V_204 ;
return F_53 ( V_9 , V_26 , V_11 , V_27 ) ;
}
static int
F_124 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
V_11 -> V_11 . V_29 |= V_153 ;
V_11 -> V_11 . type = V_204 ;
return F_53 ( V_9 , V_26 , V_11 , V_27 ) ;
}
static int
F_125 ( struct V_8 * V_9 ,
const struct V_25 * V_26 ,
struct V_10 * V_11 , int V_27 )
{
V_11 -> V_11 . V_29 |= V_153 ;
V_11 -> V_11 . type = V_255 ;
return F_53 ( V_9 , V_26 , V_11 , V_27 ) ;
}
static inline int F_126 ( T_1 V_256 , T_1 V_243 )
{
return V_256 == V_257 || V_256 == V_243 ;
}
static struct V_258 * F_127 ( struct V_2 * V_3 )
{
struct V_258 * V_259 ;
for ( V_259 = V_260 ; ; V_259 ++ )
if ( F_126 ( V_259 -> V_4 , V_3 -> V_4 ) &&
F_126 ( V_259 -> V_5 , V_3 -> V_5 ) &&
F_126 ( V_259 -> V_261 , V_3 -> V_6 ) &&
F_126 ( V_259 -> V_262 , V_3 -> V_7 ) )
break;
return V_259 ;
}
static inline int F_128 ( struct V_2 * V_3 ,
const struct V_25 * V_26 )
{
if ( V_26 -> V_29 & V_263 )
return 0 ;
else
return V_3 -> V_232 ;
}
static int
F_129 ( struct V_2 * V_3 , struct V_25 * V_26 )
{
const struct V_264 * V_265 ;
int V_266 , V_267 , V_268 = - 1 , V_60 ;
if ( ( ( ( V_3 -> V_84 >> 8 ) != V_269 ) &&
( ( V_3 -> V_84 >> 8 ) != V_270 ) ) ||
( V_3 -> V_84 & 0xff ) > 6 )
return - V_42 ;
for ( V_265 = V_271 ;
V_265 < V_271 + F_42 ( V_271 ) ;
V_265 ++ ) {
if ( V_3 -> V_4 == V_265 -> V_4 &&
V_3 -> V_5 == V_265 -> V_5 )
return - V_42 ;
}
V_266 = V_267 = 0 ;
for ( V_60 = 0 ; V_60 < V_15 ; V_60 ++ ) {
if ( F_5 ( V_3 , V_60 ) & V_272 ) {
V_267 ++ ;
if ( V_268 == - 1 )
V_268 = V_60 ;
}
if ( F_5 ( V_3 , V_60 ) & V_17 )
V_266 ++ ;
}
if ( V_266 <= 1 && V_267 == 1 ) {
V_26 -> V_29 = V_268 ;
V_26 -> V_79 = F_86 ( V_3 , V_268 ) / 8 ;
return 0 ;
}
V_268 = - 1 ;
V_267 = 0 ;
for ( V_60 = 0 ; V_60 < V_15 ; V_60 ++ ) {
if ( F_5 ( V_3 , V_60 ) & V_272 &&
F_86 ( V_3 , V_60 ) == 8 &&
( V_268 == - 1 || ( V_268 + V_267 ) == V_60 ) ) {
V_267 ++ ;
if ( V_268 == - 1 )
V_268 = V_60 ;
}
}
if ( V_267 > 1 ) {
V_26 -> V_29 = V_268 | V_148 ;
V_26 -> V_79 = V_267 ;
return 0 ;
}
return - V_42 ;
}
static inline int
F_130 ( const struct V_25 * V_26 ,
const struct V_25 * V_273 )
{
return
V_26 -> V_79 == V_273 -> V_79 &&
V_26 -> V_274 == V_273 -> V_274 &&
V_26 -> V_30 == V_273 -> V_30 &&
V_26 -> V_31 == V_273 -> V_31 &&
V_26 -> V_28 == V_273 -> V_28 ;
}
struct V_8 *
F_131 ( struct V_2 * V_3 , const struct V_25 * V_26 )
{
struct V_10 V_275 ;
struct V_8 * V_9 ;
struct V_258 * V_259 ;
int V_32 , V_276 , V_60 ;
V_276 = V_26 -> V_79 ;
V_259 = F_127 ( V_3 ) ;
if ( V_259 -> V_277 ) {
V_32 = V_259 -> V_277 ( V_3 ) ;
if ( V_32 < 0 ) {
V_9 = F_132 ( V_32 ) ;
goto V_278;
}
if ( V_32 )
V_276 = V_32 ;
}
V_9 = F_133 ( sizeof( struct V_8 ) +
sizeof( unsigned int ) * V_276 ,
V_187 ) ;
if ( ! V_9 ) {
V_9 = F_132 ( - V_18 ) ;
goto V_279;
}
V_9 -> V_3 = V_3 ;
V_9 -> V_259 = V_259 ;
memset ( & V_275 , 0 , sizeof( V_275 ) ) ;
V_275 . V_11 . V_29 = V_280 | V_281 | V_282 ;
V_275 . V_11 . V_146 = V_26 -> V_274 * 16 ;
V_275 . V_11 . V_232 = F_128 ( V_3 , V_26 ) ;
V_275 . V_11 . V_3 = & V_3 -> V_3 ;
for ( V_60 = 0 ; V_60 < V_276 ; V_60 ++ ) {
if ( V_259 -> V_283 ( V_9 , V_26 , & V_275 , V_60 ) )
break;
F_16 ( & V_3 -> V_3 , L_23 ,
V_275 . V_11 . V_21 , V_275 . V_11 . V_232 , V_275 . V_11 . V_19 ) ;
V_9 -> line [ V_60 ] = F_134 ( & V_275 ) ;
if ( V_9 -> line [ V_60 ] < 0 ) {
F_2 ( & V_3 -> V_3 ,
L_24 ,
V_275 . V_11 . V_21 , V_275 . V_11 . V_232 ,
V_275 . V_11 . V_19 , V_9 -> line [ V_60 ] ) ;
break;
}
}
V_9 -> V_284 = V_60 ;
return V_9 ;
V_279:
if ( V_259 -> exit )
V_259 -> exit ( V_3 ) ;
V_278:
return V_9 ;
}
void F_135 ( struct V_8 * V_9 )
{
struct V_258 * V_259 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_9 -> V_284 ; V_60 ++ )
F_136 ( V_9 -> line [ V_60 ] ) ;
V_259 = F_127 ( V_9 -> V_3 ) ;
if ( V_259 -> exit )
V_259 -> exit ( V_9 -> V_3 ) ;
F_137 ( V_9 ) ;
}
void F_138 ( struct V_8 * V_9 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_9 -> V_284 ; V_60 ++ )
if ( V_9 -> line [ V_60 ] >= 0 )
F_139 ( V_9 -> line [ V_60 ] ) ;
if ( V_9 -> V_259 -> exit )
V_9 -> V_259 -> exit ( V_9 -> V_3 ) ;
}
void F_140 ( struct V_8 * V_9 )
{
int V_60 ;
if ( V_9 -> V_259 -> V_277 )
V_9 -> V_259 -> V_277 ( V_9 -> V_3 ) ;
for ( V_60 = 0 ; V_60 < V_9 -> V_284 ; V_60 ++ )
if ( V_9 -> line [ V_60 ] >= 0 )
F_141 ( V_9 -> line [ V_60 ] ) ;
}
static int
F_142 ( struct V_2 * V_3 , const struct V_264 * V_285 )
{
struct V_258 * V_259 ;
struct V_8 * V_9 ;
const struct V_25 * V_26 ;
struct V_25 V_145 ;
int V_32 ;
V_259 = F_127 ( V_3 ) ;
if ( V_259 -> V_286 ) {
V_32 = V_259 -> V_286 ( V_3 ) ;
if ( V_32 )
return V_32 ;
}
if ( V_285 -> V_287 >= F_42 ( V_288 ) ) {
F_2 ( & V_3 -> V_3 , L_25 ,
V_285 -> V_287 ) ;
return - V_16 ;
}
V_26 = & V_288 [ V_285 -> V_287 ] ;
V_32 = F_143 ( V_3 ) ;
F_144 ( V_3 ) ;
if ( V_32 )
return V_32 ;
if ( V_285 -> V_287 == V_289 ) {
memcpy ( & V_145 , V_26 , sizeof( struct V_25 ) ) ;
V_26 = & V_145 ;
V_32 = F_129 ( V_3 , & V_145 ) ;
if ( V_32 )
return V_32 ;
} else {
memcpy ( & V_145 , & V_288 [ V_289 ] ,
sizeof( struct V_25 ) ) ;
V_32 = F_129 ( V_3 , & V_145 ) ;
if ( V_32 == 0 && F_130 ( V_26 , & V_145 ) )
F_1 ( L_26 ,
V_3 ) ;
}
V_9 = F_131 ( V_3 , V_26 ) ;
if ( F_145 ( V_9 ) )
return F_146 ( V_9 ) ;
F_147 ( V_3 , V_9 ) ;
return 0 ;
}
static void F_148 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_109 ( V_3 ) ;
F_135 ( V_9 ) ;
}
static int F_149 ( struct V_5 * V_3 )
{
struct V_2 * V_182 = F_105 ( V_3 ) ;
struct V_8 * V_9 = F_109 ( V_182 ) ;
if ( V_9 )
F_138 ( V_9 ) ;
return 0 ;
}
static int F_150 ( struct V_5 * V_3 )
{
struct V_2 * V_182 = F_105 ( V_3 ) ;
struct V_8 * V_9 = F_109 ( V_182 ) ;
int V_290 ;
if ( V_9 ) {
V_290 = F_151 ( V_182 ) ;
if ( V_290 )
F_2 ( V_3 , L_27 ) ;
F_140 ( V_9 ) ;
}
return 0 ;
}
static T_5 F_152 ( struct V_2 * V_3 ,
T_6 V_291 )
{
struct V_8 * V_9 = F_109 ( V_3 ) ;
if ( V_291 == V_292 )
return V_293 ;
if ( V_9 )
F_138 ( V_9 ) ;
F_153 ( V_3 ) ;
return V_294 ;
}
static T_5 F_154 ( struct V_2 * V_3 )
{
int V_32 ;
V_32 = F_151 ( V_3 ) ;
if ( V_32 )
return V_293 ;
F_155 ( V_3 ) ;
F_144 ( V_3 ) ;
return V_295 ;
}
static void F_156 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_109 ( V_3 ) ;
if ( V_9 )
F_140 ( V_9 ) ;
}
