static void F_1 ( const char * V_1 , struct V_2 * V_3 )
{
F_2 ( V_4
L_1
L_2
L_3
L_4
L_5 ,
F_3 ( V_3 ) , V_1 , V_3 -> V_5 , V_3 -> V_6 ,
V_3 -> V_7 , V_3 -> V_8 ) ;
}
static int
F_4 ( struct V_9 * V_10 , struct V_11 * V_12 ,
int V_13 , int V_14 , int V_15 )
{
struct V_2 * V_3 = V_10 -> V_3 ;
unsigned long V_16 , V_17 ;
if ( V_13 >= V_18 )
return - V_19 ;
V_16 = F_5 ( V_3 , V_13 ) ;
if ( F_6 ( V_3 , V_13 ) & V_20 ) {
V_17 = F_7 ( V_3 , V_13 ) ;
if ( ! V_10 -> V_21 [ V_13 ] )
V_10 -> V_21 [ V_13 ] = F_8 ( V_16 , V_17 ) ;
if ( ! V_10 -> V_21 [ V_13 ] )
return - V_22 ;
V_12 -> V_12 . V_23 = V_24 ;
V_12 -> V_12 . V_25 = 0 ;
V_12 -> V_12 . V_26 = V_16 + V_14 ;
V_12 -> V_12 . V_27 = V_10 -> V_21 [ V_13 ] + V_14 ;
V_12 -> V_12 . V_15 = V_15 ;
} else {
V_12 -> V_12 . V_23 = V_28 ;
V_12 -> V_12 . V_25 = V_16 + V_14 ;
V_12 -> V_12 . V_26 = 0 ;
V_12 -> V_12 . V_27 = NULL ;
V_12 -> V_12 . V_15 = 0 ;
}
return 0 ;
}
static int F_9 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
unsigned int V_13 = 0 , V_14 = V_30 -> V_32 ;
V_13 = F_10 ( V_30 -> V_33 ) ;
if ( V_31 < 2 ) {
V_14 += V_31 * V_30 -> V_34 ;
} else if ( ( V_31 >= 2 ) && ( V_31 < 4 ) ) {
V_13 += 1 ;
V_14 += ( ( V_31 - 2 ) * V_30 -> V_34 ) ;
} else if ( ( V_31 >= 4 ) && ( V_31 < 6 ) ) {
V_13 += 2 ;
V_14 += ( ( V_31 - 4 ) * V_30 -> V_34 ) ;
} else if ( V_31 >= 6 ) {
V_13 += 3 ;
V_14 += ( ( V_31 - 6 ) * V_30 -> V_34 ) ;
}
return F_4 ( V_10 , V_12 , V_13 , V_14 , V_30 -> V_35 ) ;
}
static int
F_11 ( struct V_9 * V_10 , const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
unsigned int V_13 , V_14 = V_30 -> V_32 ;
V_13 = F_10 ( V_30 -> V_33 ) ;
if ( V_31 < 4 )
V_13 += V_31 ;
else {
V_13 = 4 ;
V_14 += ( V_31 - 4 ) * V_30 -> V_34 ;
}
return F_4 ( V_10 , V_12 , V_13 , V_14 , V_30 -> V_35 ) ;
}
static int F_12 ( struct V_2 * V_3 )
{
int V_36 = 0 ;
switch ( V_3 -> V_8 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_36 = 3 ;
break;
case V_41 :
V_36 = 2 ;
break;
case V_42 :
V_36 = 4 ;
break;
case V_43 :
case V_44 :
V_36 = 1 ;
break;
}
return V_36 ;
}
static int
F_13 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
unsigned int V_14 = V_30 -> V_32 ;
unsigned int V_13 = F_10 ( V_30 -> V_33 ) ;
switch ( V_10 -> V_3 -> V_8 ) {
case V_42 :
if ( V_31 == 3 )
V_31 ++ ;
break;
case V_40 :
if ( V_31 > 0 )
V_31 ++ ;
if ( V_31 > 2 )
V_31 ++ ;
break;
}
if ( V_31 > 2 )
V_14 = 0x18 ;
V_14 += V_31 * V_30 -> V_34 ;
return F_4 ( V_10 , V_12 , V_13 , V_14 , V_30 -> V_35 ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
unsigned long V_45 ;
if ( ! ( V_3 -> V_8 & 0x1000 ) )
return - V_46 ;
F_15 ( V_3 , 0x44 , ( void * ) & V_45 ) ;
if ( V_45 == 0x00001000L ) {
F_2 ( V_47 L_6 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
T_1 V_48 ;
void T_2 * V_49 ;
if ( ( F_6 ( V_3 , 0 ) & V_20 ) == 0 ) {
F_1 ( L_7 , V_3 ) ;
return 0 ;
}
V_48 = 0x41 ;
if ( V_3 -> V_5 == V_50 ||
V_3 -> V_7 == V_51 )
V_48 = 0x43 ;
if ( ( V_3 -> V_5 == V_52 ) &&
( V_3 -> V_6 == V_53 ) )
V_48 = 0x5b ;
V_49 = F_8 ( F_5 ( V_3 , 0 ) , 0x80 ) ;
if ( V_49 == NULL )
return - V_22 ;
F_17 ( V_48 , V_49 + 0x4c ) ;
F_18 ( V_49 + 0x4c ) ;
F_19 ( V_49 ) ;
return 0 ;
}
static void T_3 F_20 ( struct V_2 * V_3 )
{
T_1 T_2 * V_49 ;
if ( ( F_6 ( V_3 , 0 ) & V_20 ) == 0 )
return;
V_49 = F_8 ( F_5 ( V_3 , 0 ) , 0x80 ) ;
if ( V_49 != NULL ) {
F_17 ( 0 , V_49 + 0x4c ) ;
F_18 ( V_49 + 0x4c ) ;
F_19 ( V_49 ) ;
}
}
static void T_3 F_21 ( struct V_2 * V_3 )
{
void T_2 * V_49 ;
unsigned long V_16 , V_17 ;
unsigned int V_13 = 0 ;
if ( ( F_6 ( V_3 , V_13 ) & V_20 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return;
}
V_16 = F_5 ( V_3 , V_13 ) ;
V_17 = F_7 ( V_3 , V_13 ) ;
V_49 = F_8 ( V_16 , V_17 ) ;
if ( V_49 == NULL )
return;
F_17 ( F_18 ( V_49 + V_54 ) & ~ ( V_55 ) ,
V_49 + V_54 ) ;
F_19 ( V_49 ) ;
}
static void T_3 F_22 ( struct V_2 * V_3 )
{
void T_2 * V_49 ;
unsigned long V_16 , V_17 ;
unsigned int V_13 = 0 ;
if ( ( F_6 ( V_3 , V_13 ) & V_20 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return;
}
V_16 = F_5 ( V_3 , V_13 ) ;
V_17 = F_7 ( V_3 , V_13 ) ;
V_49 = F_8 ( V_16 , V_17 ) ;
if ( V_49 == NULL )
return;
F_17 ( V_56 , V_49 + V_57 ) ;
F_19 ( V_49 ) ;
}
static int
F_23 ( struct V_9 * V_10 , const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
unsigned int V_13 , V_14 = V_30 -> V_32 ;
V_13 = 0 ;
if ( V_31 < 4 ) {
V_14 += V_31 * V_30 -> V_34 ;
} else if ( V_31 < 8 ) {
V_14 += V_31 * V_30 -> V_34 + 0xC00 ;
} else
return 1 ;
return F_4 ( V_10 , V_12 , V_13 , V_14 , V_30 -> V_35 ) ;
}
static int F_24 ( struct V_2 * V_3 )
{
T_1 T_2 * V_49 ;
V_49 = F_25 ( V_3 , 0 ) ;
if ( V_49 == NULL )
return - V_22 ;
F_26 ( 0x10 , V_49 + V_58 ) ;
F_27 ( 50 ) ;
F_26 ( 0x0 , V_49 + V_58 ) ;
F_26 ( 0x4 , V_49 + V_58 ) ;
F_19 ( V_49 ) ;
return 0 ;
}
static void T_3 F_28 ( struct V_2 * V_3 )
{
T_1 T_2 * V_49 ;
V_49 = F_25 ( V_3 , 0 ) ;
if ( V_49 != NULL )
F_26 ( 0 , V_49 + V_58 ) ;
F_19 ( V_49 ) ;
}
static int F_29 ( struct V_2 * V_3 )
{
T_4 V_59 ;
void T_2 * V_49 ;
switch ( V_3 -> V_6 & 0xfff8 ) {
case V_60 :
V_59 = 0xffdf ;
break;
case V_61 :
V_59 = 0xf7ff ;
break;
default:
V_59 = 0xfffb ;
break;
}
V_49 = F_8 ( F_5 ( V_3 , 0 ) , 0x80 ) ;
if ( V_49 == NULL )
return - V_22 ;
F_30 ( F_31 ( V_49 + 0x28 ) & V_59 , V_49 + 0x28 ) ;
F_31 ( V_49 + 0x28 ) ;
F_19 ( V_49 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 )
{
T_1 V_59 ;
F_33 ( V_3 , 0x6f , & V_59 ) ;
F_34 ( V_3 , 0x6f , V_59 & 0xef ) ;
if ( ( ( V_3 -> V_6 & 0xfffc ) == V_62 ) ||
( ( V_3 -> V_6 & 0xfffc ) == V_63 ) ) {
F_33 ( V_3 , 0x73 , & V_59 ) ;
F_34 ( V_3 , 0x73 , V_59 & 0xef ) ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 )
{
unsigned int type = V_3 -> V_6 & 0xff00 ;
if ( type == 0x1000 )
return F_29 ( V_3 ) ;
else if ( type == 0x2000 )
return F_32 ( V_3 ) ;
F_1 ( L_9 , V_3 ) ;
return - V_46 ;
}
static int F_36 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
unsigned int V_13 = F_10 ( V_30 -> V_33 ) + V_31 , V_14 = 0 ;
if ( V_31 > 3 ) {
V_13 = 4 ;
V_14 = ( V_31 - 4 ) * 8 ;
}
return F_4 ( V_10 , V_12 , V_13 , V_14 , 0 ) ;
}
static int F_37 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_8 & 0x00f0 ) >= 0x70 ) {
F_38 ( & V_3 -> V_3 ,
L_10 ,
V_3 -> V_8 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_39 ( struct V_2 * V_3 )
{
const unsigned short * V_64 ;
int V_65 , V_66 ;
for ( V_65 = 0 ; V_65 < F_40 ( V_67 ) ; V_65 ++ ) {
V_64 = V_67 [ V_65 ] . V_64 ;
for ( V_66 = 0 ; V_64 [ V_66 ] ; V_66 ++ )
if ( V_3 -> V_8 == V_64 [ V_66 ] )
return V_67 [ V_65 ] . V_68 ;
}
return 0 ;
}
static int
F_41 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
unsigned int V_13 = 0 , V_14 = V_30 -> V_32 ;
switch ( V_31 ) {
case 0 :
V_13 = 0 ;
break;
case 1 :
V_14 = V_30 -> V_34 ;
V_13 = 0 ;
break;
case 2 :
V_13 = 1 ;
break;
case 3 :
V_14 = V_30 -> V_34 ;
case 4 :
case 5 :
case 6 :
case 7 :
V_13 = V_31 - 2 ;
}
return F_4 ( V_10 , V_12 , V_13 , V_14 , V_30 -> V_35 ) ;
}
static int
F_42 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
unsigned int V_13 , V_14 = V_30 -> V_32 ;
switch ( V_31 ) {
case 0 :
V_13 = 1 ;
break;
case 1 :
V_13 = 2 ;
break;
default:
V_13 = 4 ;
V_14 = ( V_31 - 2 ) * V_30 -> V_34 ;
}
return F_4 ( V_10 , V_12 , V_13 , V_14 , V_30 -> V_35 ) ;
}
static int F_43 ( struct V_2 * V_3 )
{
F_44 ( 100 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 )
{
void T_2 * V_49 ;
unsigned long V_16 , V_17 ;
unsigned int V_13 = 0 ;
if ( ( F_6 ( V_3 , V_13 ) & V_20 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return 0 ;
}
V_16 = F_5 ( V_3 , V_13 ) ;
V_17 = F_7 ( V_3 , V_13 ) ;
V_49 = F_8 ( V_16 , V_17 ) ;
if ( V_49 == NULL )
return - V_22 ;
F_17 ( F_18 ( V_49 + V_54 ) | V_55 ,
V_49 + V_54 ) ;
F_19 ( V_49 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
void T_2 * V_49 ;
unsigned long V_16 , V_17 ;
T_5 V_69 ;
unsigned int V_13 = 0 ;
if ( ( F_6 ( V_3 , V_13 ) & V_20 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return 0 ;
}
V_16 = F_5 ( V_3 , V_13 ) ;
V_17 = F_7 ( V_3 , V_13 ) ;
V_49 = F_8 ( V_16 , V_17 ) ;
if ( V_49 == NULL )
return - V_22 ;
V_69 = ( ( V_16 + V_70 ) & 0xffffff00 )
| V_71 | V_72 ;
F_17 ( V_69 , V_49 + V_73 ) ;
F_17 ( ( F_18 ( V_49 + V_74 ) & V_75 ) ,
V_49 + V_74 ) ;
F_17 ( V_76 , V_49 + V_77 ) ;
F_17 ( V_78 , V_49 + V_57 ) ;
F_19 ( V_49 ) ;
return 0 ;
}
static int
F_47 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
void T_2 * V_49 ;
unsigned long V_16 , V_17 ;
unsigned int V_13 , V_14 = V_30 -> V_32 ;
if ( V_31 >= V_30 -> V_79 )
return 1 ;
V_13 = F_10 ( V_30 -> V_33 ) ;
V_14 += V_31 * V_30 -> V_34 ;
V_16 = F_5 ( V_10 -> V_3 , V_13 ) ;
V_17 = F_7 ( V_10 -> V_3 , V_13 ) ;
V_49 = F_8 ( V_16 , V_17 ) ;
F_26 ( F_48 ( V_49 + V_14 + V_80 ) | V_81 ,
V_49 + V_14 + V_80 ) ;
F_19 ( V_49 ) ;
return F_4 ( V_10 , V_12 , V_13 , V_14 , V_30 -> V_35 ) ;
}
static int F_49 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
unsigned int V_13 ;
if ( ( V_10 -> V_3 -> V_8 & 0xff00 ) == 0x3000 ) {
V_13 = 3 * V_31 ;
return F_4 ( V_10 , V_12 , V_13 , 0 , V_30 -> V_35 ) ;
} else {
return F_50 ( V_10 , V_30 , V_12 , V_31 ) ;
}
}
static int F_51 ( struct V_2 * V_3 )
{
unsigned int V_82 = V_3 -> V_83 ;
unsigned int V_84 ;
unsigned short V_85 ;
V_84 = ( V_82 & 0xff ) ;
if ( V_84 == 2 ) {
return 1 ;
} else if ( ( V_84 == 0 ) &&
( V_3 -> V_6 == V_86 ) ) {
V_85 = V_3 -> V_8 & 0xf ;
if ( V_85 > 0 ) {
return V_85 ;
} else {
F_2 ( V_87 L_11 ) ;
return 0 ;
}
}
F_1 ( L_12 , V_3 ) ;
return 0 ;
}
static int F_52 ( struct V_2 * V_3 )
{
unsigned int V_88 = V_3 -> V_8 & 0xf ;
if ( ( V_3 -> V_6 == V_89 ) ||
( V_3 -> V_6 == V_90 ) )
return 0 ;
if ( V_3 -> V_7 == V_91 &&
V_3 -> V_8 == 0x0299 )
return 0 ;
switch ( V_3 -> V_6 ) {
case V_92 :
case V_93 :
case V_94 :
case V_86 :
V_88 = F_51 ( V_3 ) ;
break;
default:
if ( V_88 == 0 ) {
F_1 ( L_13 , V_3 ) ;
}
}
if ( V_88 == 0 )
return - V_46 ;
return V_88 ;
}
static int F_53 ( struct V_2 * V_3 )
{
static const short V_95 [] = { 0x2a0 , 0x2c0 , 0x220 , 0x240 , 0x1e0 ,
0x200 , 0x280 , 0 } ;
int V_96 , V_65 , type ;
struct V_97 * V_25 = NULL ;
T_5 V_98 , V_99 , V_100 ;
V_65 = 0 ;
while ( V_95 [ V_65 ] && V_25 == NULL ) {
V_25 = F_54 ( V_95 [ V_65 ] , V_101 ,
L_14 ) ;
if ( V_25 != NULL ) {
F_55 ( V_3 , V_102 ,
V_103 | V_104 |
V_105 | V_95 [ V_65 ] ) ;
F_55 ( V_3 , V_106 ,
V_95 [ V_65 ] ) ;
V_96 = F_56 ( V_95 [ V_65 ] ) ;
if ( V_96 != 0xff ) {
break;
}
F_57 ( V_25 -> V_107 , V_101 ) ;
V_25 = NULL ;
}
V_65 ++ ;
}
if ( ! V_95 [ V_65 ] ) {
F_2 ( V_108 L_15 ) ;
return - V_46 ;
}
type = F_56 ( V_25 -> V_107 + 0x18 ) & 0x0f ;
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
V_96 = - V_46 ;
}
for ( V_65 = 0 ; V_65 < V_96 ; V_65 ++ ) {
F_15 ( V_3 , V_109 + ( 0x4 * ( V_65 + 1 ) ) ,
& V_100 ) ;
V_100 &= 0x0000FF00 ;
F_55 ( V_3 , V_102 + ( 0x4 * ( V_65 + 1 ) ) ,
V_103 | V_104 |
V_110 | V_100 ) ;
F_15 ( V_3 , V_111 , & V_99 ) ;
V_99 &= ~ ( 0xffff << ( 16 * V_65 ) ) ;
V_99 |= ( V_100 << ( 16 * V_65 ) ) ;
F_55 ( V_3 , V_111 , V_99 ) ;
F_15 ( V_3 , V_112 , & V_98 ) ;
V_98 &= ~ ( 0xf << ( 12 - 4 * V_65 ) ) ;
V_98 |= 1 << ( 23 - V_65 ) ;
F_55 ( V_3 , V_112 , V_98 ) ;
}
if ( V_96 <= 0 ) {
F_57 ( V_25 -> V_107 , V_101 ) ;
}
return V_96 ;
}
static void T_3 F_58 ( struct V_2 * V_3 )
{
T_5 V_100 ;
F_15 ( V_3 , V_102 , & V_100 ) ;
V_100 &= 0xffff ;
F_57 ( V_100 , V_101 ) ;
}
static int F_59 ( struct V_2 * V_3 )
{
T_1 T_2 * V_49 ;
unsigned long V_113 ;
unsigned int V_114 = 0 ;
if ( V_3 -> V_5 == V_115 &&
( V_3 -> V_6 & 0xF000 ) != 0xC000 )
return 0 ;
V_49 = F_60 ( V_3 , 0 , 5 ) ;
if ( V_49 == NULL )
return - V_22 ;
V_113 = F_61 ( V_49 ) ;
if ( V_113 == 0x07000200 ) {
V_114 = F_62 ( V_49 + 4 ) ;
F_2 ( V_47
L_17 ,
V_114 ) ;
}
F_63 ( V_3 , V_49 ) ;
return V_114 ;
}
static int F_64 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
V_12 -> V_116 |= V_117 ;
return F_50 ( V_10 , V_30 , V_12 , V_31 ) ;
}
static int F_50 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
unsigned int V_13 , V_14 = V_30 -> V_32 , V_118 ;
V_13 = F_10 ( V_30 -> V_33 ) ;
if ( V_30 -> V_33 & V_119 )
V_13 += V_31 ;
else
V_14 += V_31 * V_30 -> V_34 ;
V_118 = ( F_7 ( V_10 -> V_3 , V_13 ) - V_30 -> V_32 ) >>
( V_30 -> V_35 + 3 ) ;
if ( V_30 -> V_33 & V_120 && V_31 >= V_118 )
return 1 ;
return F_4 ( V_10 , V_12 , V_13 , V_14 , V_30 -> V_35 ) ;
}
static int
F_65 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
int V_96 ;
V_96 = F_4 ( V_10 , V_12 , 0 , 0 , V_30 -> V_35 ) ;
V_12 -> V_12 . V_23 = V_121 ;
V_12 -> V_12 . type = V_122 ;
V_12 -> V_12 . V_33 = ( V_12 -> V_12 . V_33 | V_123 | V_124 ) ;
V_12 -> V_12 . V_15 = 2 ;
return V_96 ;
}
static int
F_66 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
return F_4 ( V_10 , V_12 , 2 , V_31 * 8 , 0 ) ;
}
static int F_67 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
V_12 -> V_12 . V_33 |= V_125 ;
F_2 ( V_47 L_18
L_19 ,
V_10 -> V_3 -> V_5 ,
V_10 -> V_3 -> V_6 ,
V_10 -> V_3 -> V_7 ,
V_10 -> V_3 -> V_8 ) ;
return F_50 ( V_10 , V_30 , V_12 , V_31 ) ;
}
static void F_68 ( struct V_126 * V_49 )
{
struct V_11 * V_127 =
F_69 ( V_49 , struct V_11 , V_12 ) ;
F_70 ( V_127 ) ;
}
static unsigned int F_71 ( struct V_126 * V_49 , int V_14 )
{
struct V_11 * V_127 =
F_69 ( V_49 , struct V_11 , V_12 ) ;
unsigned int V_128 ;
V_128 = F_56 ( V_49 -> V_25 + V_14 ) ;
if ( V_14 == V_129 ) {
if ( V_128 == 0 )
V_128 = V_127 -> V_130 ;
}
return V_128 ;
}
static int F_72 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
V_12 -> V_12 . V_33 |= V_131 ;
V_12 -> V_12 . V_132 = F_71 ;
V_12 -> V_12 . V_133 = F_68 ;
return F_67 ( V_10 , V_30 , V_12 , V_31 ) ;
}
static int F_73 ( struct V_2 * V_3 )
{
#if F_74 ( V_134 ) || F_74 ( V_135 )
return - V_46 ;
#else
return 0 ;
#endif
}
static int
F_75 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
V_12 -> V_12 . V_33 |= V_136 ;
return F_50 ( V_10 , V_30 , V_12 , V_31 ) ;
}
static int
F_76 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
V_12 -> V_12 . V_33 |= V_124 ;
V_12 -> V_12 . type = V_137 ;
return F_50 ( V_10 , V_30 , V_12 , V_31 ) ;
}
static inline int F_77 ( T_5 V_138 , T_5 V_139 )
{
return V_138 == V_140 || V_138 == V_139 ;
}
static struct V_141 * F_78 ( struct V_2 * V_3 )
{
struct V_141 * V_142 ;
for ( V_142 = V_143 ; ; V_142 ++ )
if ( F_77 ( V_142 -> V_5 , V_3 -> V_5 ) &&
F_77 ( V_142 -> V_6 , V_3 -> V_6 ) &&
F_77 ( V_142 -> V_144 , V_3 -> V_7 ) &&
F_77 ( V_142 -> V_145 , V_3 -> V_8 ) )
break;
return V_142 ;
}
static inline int F_79 ( struct V_2 * V_3 ,
const struct V_29 * V_30 )
{
if ( V_30 -> V_33 & V_146 )
return 0 ;
else
return V_3 -> V_147 ;
}
static int T_6
F_80 ( struct V_2 * V_3 , struct V_29 * V_30 )
{
const struct V_148 * V_149 ;
int V_150 , V_151 , V_152 = - 1 , V_65 ;
if ( ( ( ( V_3 -> V_83 >> 8 ) != V_153 ) &&
( ( V_3 -> V_83 >> 8 ) != V_154 ) ) ||
( V_3 -> V_83 & 0xff ) > 6 )
return - V_46 ;
for ( V_149 = V_155 ;
V_149 < V_155 + F_40 ( V_155 ) ;
V_149 ++ ) {
if ( V_3 -> V_5 == V_149 -> V_5 &&
V_3 -> V_6 == V_149 -> V_6 )
return - V_46 ;
}
V_150 = V_151 = 0 ;
for ( V_65 = 0 ; V_65 < V_18 ; V_65 ++ ) {
if ( F_6 ( V_3 , V_65 ) & V_156 ) {
V_151 ++ ;
if ( V_152 == - 1 )
V_152 = V_65 ;
}
if ( F_6 ( V_3 , V_65 ) & V_20 )
V_150 ++ ;
}
if ( V_150 <= 1 && V_151 == 1 ) {
V_30 -> V_33 = V_152 ;
V_30 -> V_79 = F_7 ( V_3 , V_152 ) / 8 ;
return 0 ;
}
V_152 = - 1 ;
V_151 = 0 ;
for ( V_65 = 0 ; V_65 < V_18 ; V_65 ++ ) {
if ( F_6 ( V_3 , V_65 ) & V_156 &&
F_7 ( V_3 , V_65 ) == 8 &&
( V_152 == - 1 || ( V_152 + V_151 ) == V_65 ) ) {
V_151 ++ ;
if ( V_152 == - 1 )
V_152 = V_65 ;
}
}
if ( V_151 > 1 ) {
V_30 -> V_33 = V_152 | V_119 ;
V_30 -> V_79 = V_151 ;
return 0 ;
}
return - V_46 ;
}
static inline int
F_81 ( const struct V_29 * V_30 ,
const struct V_29 * V_157 )
{
return
V_30 -> V_79 == V_157 -> V_79 &&
V_30 -> V_158 == V_157 -> V_158 &&
V_30 -> V_34 == V_157 -> V_34 &&
V_30 -> V_35 == V_157 -> V_35 &&
V_30 -> V_32 == V_157 -> V_32 ;
}
struct V_9 *
F_82 ( struct V_2 * V_3 , const struct V_29 * V_30 )
{
struct V_11 V_159 ;
struct V_9 * V_10 ;
struct V_141 * V_142 ;
int V_36 , V_160 , V_65 ;
V_160 = V_30 -> V_79 ;
V_142 = F_78 ( V_3 ) ;
if ( V_142 -> V_161 ) {
V_36 = V_142 -> V_161 ( V_3 ) ;
if ( V_36 < 0 ) {
V_10 = F_83 ( V_36 ) ;
goto V_162;
}
if ( V_36 )
V_160 = V_36 ;
}
V_10 = F_84 ( sizeof( struct V_9 ) +
sizeof( unsigned int ) * V_160 ,
V_163 ) ;
if ( ! V_10 ) {
V_10 = F_83 ( - V_22 ) ;
goto V_164;
}
V_10 -> V_3 = V_3 ;
V_10 -> V_142 = V_142 ;
memset ( & V_159 , 0 , sizeof( V_159 ) ) ;
V_159 . V_12 . V_33 = V_165 | V_166 | V_167 ;
V_159 . V_12 . V_168 = V_30 -> V_158 * 16 ;
V_159 . V_12 . V_147 = F_79 ( V_3 , V_30 ) ;
V_159 . V_12 . V_3 = & V_3 -> V_3 ;
for ( V_65 = 0 ; V_65 < V_160 ; V_65 ++ ) {
if ( V_142 -> V_169 ( V_10 , V_30 , & V_159 , V_65 ) )
break;
#ifdef F_85
F_2 ( V_47 L_20 ,
V_159 . V_12 . V_25 , V_159 . V_12 . V_147 , V_159 . V_12 . V_23 ) ;
#endif
V_10 -> line [ V_65 ] = F_86 ( & V_159 ) ;
if ( V_10 -> line [ V_65 ] < 0 ) {
F_2 ( V_4 L_21 , F_3 ( V_3 ) , V_10 -> line [ V_65 ] ) ;
break;
}
}
V_10 -> V_170 = V_65 ;
return V_10 ;
V_164:
if ( V_142 -> exit )
V_142 -> exit ( V_3 ) ;
V_162:
return V_10 ;
}
void F_87 ( struct V_9 * V_10 )
{
struct V_141 * V_142 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_10 -> V_170 ; V_65 ++ )
F_88 ( V_10 -> line [ V_65 ] ) ;
for ( V_65 = 0 ; V_65 < V_18 ; V_65 ++ ) {
if ( V_10 -> V_21 [ V_65 ] )
F_19 ( V_10 -> V_21 [ V_65 ] ) ;
V_10 -> V_21 [ V_65 ] = NULL ;
}
V_142 = F_78 ( V_10 -> V_3 ) ;
if ( V_142 -> exit )
V_142 -> exit ( V_10 -> V_3 ) ;
F_89 ( V_10 ) ;
}
void F_90 ( struct V_9 * V_10 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_10 -> V_170 ; V_65 ++ )
if ( V_10 -> line [ V_65 ] >= 0 )
F_91 ( V_10 -> line [ V_65 ] ) ;
if ( V_10 -> V_142 -> exit )
V_10 -> V_142 -> exit ( V_10 -> V_3 ) ;
}
void F_92 ( struct V_9 * V_10 )
{
int V_65 ;
if ( V_10 -> V_142 -> V_161 )
V_10 -> V_142 -> V_161 ( V_10 -> V_3 ) ;
for ( V_65 = 0 ; V_65 < V_10 -> V_170 ; V_65 ++ )
if ( V_10 -> line [ V_65 ] >= 0 )
F_93 ( V_10 -> line [ V_65 ] ) ;
}
static int T_6
F_94 ( struct V_2 * V_3 , const struct V_148 * V_171 )
{
struct V_141 * V_142 ;
struct V_9 * V_10 ;
const struct V_29 * V_30 ;
struct V_29 V_172 ;
int V_36 ;
V_142 = F_78 ( V_3 ) ;
if ( V_142 -> V_173 ) {
V_36 = V_142 -> V_173 ( V_3 ) ;
if ( V_36 )
return V_36 ;
}
if ( V_171 -> V_174 >= F_40 ( V_175 ) ) {
F_2 ( V_108 L_22 ,
V_171 -> V_174 ) ;
return - V_19 ;
}
V_30 = & V_175 [ V_171 -> V_174 ] ;
V_36 = F_95 ( V_3 ) ;
F_96 ( V_3 ) ;
if ( V_36 )
return V_36 ;
if ( V_171 -> V_174 == V_176 ) {
memcpy ( & V_172 , V_30 , sizeof( struct V_29 ) ) ;
V_30 = & V_172 ;
V_36 = F_80 ( V_3 , & V_172 ) ;
if ( V_36 )
goto V_177;
} else {
memcpy ( & V_172 , & V_175 [ V_176 ] ,
sizeof( struct V_29 ) ) ;
V_36 = F_80 ( V_3 , & V_172 ) ;
if ( V_36 == 0 && F_81 ( V_30 , & V_172 ) )
F_1 ( L_23 ,
V_3 ) ;
}
V_10 = F_82 ( V_3 , V_30 ) ;
if ( ! F_97 ( V_10 ) ) {
F_98 ( V_3 , V_10 ) ;
return 0 ;
}
V_36 = F_99 ( V_10 ) ;
V_177:
F_100 ( V_3 ) ;
return V_36 ;
}
static void T_3 F_101 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = F_102 ( V_3 ) ;
F_98 ( V_3 , NULL ) ;
F_87 ( V_10 ) ;
F_100 ( V_3 ) ;
}
static int F_103 ( struct V_2 * V_3 , T_7 V_178 )
{
struct V_9 * V_10 = F_102 ( V_3 ) ;
if ( V_10 )
F_90 ( V_10 ) ;
F_96 ( V_3 ) ;
F_104 ( V_3 , F_105 ( V_3 , V_178 ) ) ;
return 0 ;
}
static int F_106 ( struct V_2 * V_3 )
{
int V_179 ;
struct V_9 * V_10 = F_102 ( V_3 ) ;
F_104 ( V_3 , V_180 ) ;
F_107 ( V_3 ) ;
if ( V_10 ) {
V_179 = F_95 ( V_3 ) ;
if ( V_179 )
F_2 ( V_108 L_24 ) ;
F_92 ( V_10 ) ;
}
return 0 ;
}
static T_8 F_108 ( struct V_2 * V_3 ,
T_9 V_178 )
{
struct V_9 * V_10 = F_102 ( V_3 ) ;
if ( V_178 == V_181 )
return V_182 ;
if ( V_10 )
F_90 ( V_10 ) ;
F_100 ( V_3 ) ;
return V_183 ;
}
static T_8 F_109 ( struct V_2 * V_3 )
{
int V_36 ;
V_36 = F_95 ( V_3 ) ;
if ( V_36 )
return V_182 ;
F_107 ( V_3 ) ;
F_96 ( V_3 ) ;
return V_184 ;
}
static void F_110 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = F_102 ( V_3 ) ;
if ( V_10 )
F_92 ( V_10 ) ;
}
static int T_10 F_111 ( void )
{
return F_112 ( & V_185 ) ;
}
static void T_11 F_113 ( void )
{
F_114 ( & V_185 ) ;
}
