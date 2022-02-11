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
V_12 -> V_23 = V_24 ;
V_12 -> V_25 = 0 ;
V_12 -> V_26 = V_16 + V_14 ;
V_12 -> V_27 = V_10 -> V_21 [ V_13 ] + V_14 ;
V_12 -> V_15 = V_15 ;
} else {
V_12 -> V_23 = V_28 ;
V_12 -> V_25 = V_16 + V_14 ;
V_12 -> V_26 = 0 ;
V_12 -> V_27 = NULL ;
V_12 -> V_15 = 0 ;
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
static int
F_50 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
unsigned int V_13 , V_14 = V_30 -> V_32 , V_116 ;
V_13 = F_10 ( V_30 -> V_33 ) ;
if ( V_30 -> V_33 & V_117 )
V_13 += V_31 ;
else
V_14 += V_31 * V_30 -> V_34 ;
V_116 = ( F_7 ( V_10 -> V_3 , V_13 ) - V_30 -> V_32 ) >>
( V_30 -> V_35 + 3 ) ;
if ( V_30 -> V_33 & V_118 && V_31 >= V_116 )
return 1 ;
return F_4 ( V_10 , V_12 , V_13 , V_14 , V_30 -> V_35 ) ;
}
static int
F_64 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
int V_96 ;
V_96 = F_4 ( V_10 , V_12 , 0 , 0 , V_30 -> V_35 ) ;
V_12 -> V_23 = V_119 ;
V_12 -> type = V_120 ;
V_12 -> V_33 = ( V_12 -> V_33 | V_121 | V_122 ) ;
V_12 -> V_15 = 2 ;
return V_96 ;
}
static int
F_65 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
return F_4 ( V_10 , V_12 , 2 , V_31 * 8 , 0 ) ;
}
static int F_66 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
V_12 -> V_33 |= V_123 ;
F_2 ( V_47 L_18
L_19 ,
V_10 -> V_3 -> V_5 ,
V_10 -> V_3 -> V_6 ,
V_10 -> V_3 -> V_7 ,
V_10 -> V_3 -> V_8 ) ;
return F_50 ( V_10 , V_30 , V_12 , V_31 ) ;
}
static void F_67 ( struct V_11 * V_49 )
{
struct V_124 * V_125 =
F_68 ( V_49 , struct V_124 , V_12 ) ;
F_69 ( V_125 ) ;
}
static unsigned int F_70 ( struct V_11 * V_49 , int V_14 )
{
struct V_124 * V_125 =
F_68 ( V_49 , struct V_124 , V_12 ) ;
unsigned int V_126 ;
V_126 = F_56 ( V_49 -> V_25 + V_14 ) ;
if ( V_14 == V_127 ) {
if ( V_126 == 0 )
V_126 = V_125 -> V_128 ;
}
return V_126 ;
}
static int F_71 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
V_12 -> V_33 |= V_129 ;
V_12 -> V_130 = F_70 ;
V_12 -> V_131 = F_67 ;
return F_66 ( V_10 , V_30 , V_12 , V_31 ) ;
}
static int F_72 ( struct V_2 * V_3 )
{
#if F_73 ( V_132 ) || F_73 ( V_133 )
return - V_46 ;
#else
return 0 ;
#endif
}
static int
F_74 ( struct V_9 * V_10 ,
const struct V_29 * V_30 ,
struct V_11 * V_12 , int V_31 )
{
V_12 -> V_33 |= V_134 ;
return F_50 ( V_10 , V_30 , V_12 , V_31 ) ;
}
static inline int F_75 ( T_5 V_135 , T_5 V_136 )
{
return V_135 == V_137 || V_135 == V_136 ;
}
static struct V_138 * F_76 ( struct V_2 * V_3 )
{
struct V_138 * V_139 ;
for ( V_139 = V_140 ; ; V_139 ++ )
if ( F_75 ( V_139 -> V_5 , V_3 -> V_5 ) &&
F_75 ( V_139 -> V_6 , V_3 -> V_6 ) &&
F_75 ( V_139 -> V_141 , V_3 -> V_7 ) &&
F_75 ( V_139 -> V_142 , V_3 -> V_8 ) )
break;
return V_139 ;
}
static inline int F_77 ( struct V_2 * V_3 ,
const struct V_29 * V_30 )
{
if ( V_30 -> V_33 & V_143 )
return 0 ;
else
return V_3 -> V_144 ;
}
static int T_6
F_78 ( struct V_2 * V_3 , struct V_29 * V_30 )
{
const struct V_145 * V_146 ;
int V_147 , V_148 , V_149 = - 1 , V_65 ;
if ( ( ( ( V_3 -> V_83 >> 8 ) != V_150 ) &&
( ( V_3 -> V_83 >> 8 ) != V_151 ) ) ||
( V_3 -> V_83 & 0xff ) > 6 )
return - V_46 ;
for ( V_146 = V_152 ;
V_146 < V_152 + F_40 ( V_152 ) ;
V_146 ++ ) {
if ( V_3 -> V_5 == V_146 -> V_5 &&
V_3 -> V_6 == V_146 -> V_6 )
return - V_46 ;
}
V_147 = V_148 = 0 ;
for ( V_65 = 0 ; V_65 < V_18 ; V_65 ++ ) {
if ( F_6 ( V_3 , V_65 ) & V_153 ) {
V_148 ++ ;
if ( V_149 == - 1 )
V_149 = V_65 ;
}
if ( F_6 ( V_3 , V_65 ) & V_20 )
V_147 ++ ;
}
if ( V_147 <= 1 && V_148 == 1 ) {
V_30 -> V_33 = V_149 ;
V_30 -> V_79 = F_7 ( V_3 , V_149 ) / 8 ;
return 0 ;
}
V_149 = - 1 ;
V_148 = 0 ;
for ( V_65 = 0 ; V_65 < V_18 ; V_65 ++ ) {
if ( F_6 ( V_3 , V_65 ) & V_153 &&
F_7 ( V_3 , V_65 ) == 8 &&
( V_149 == - 1 || ( V_149 + V_148 ) == V_65 ) ) {
V_148 ++ ;
if ( V_149 == - 1 )
V_149 = V_65 ;
}
}
if ( V_148 > 1 ) {
V_30 -> V_33 = V_149 | V_117 ;
V_30 -> V_79 = V_148 ;
return 0 ;
}
return - V_46 ;
}
static inline int
F_79 ( const struct V_29 * V_30 ,
const struct V_29 * V_154 )
{
return
V_30 -> V_79 == V_154 -> V_79 &&
V_30 -> V_155 == V_154 -> V_155 &&
V_30 -> V_34 == V_154 -> V_34 &&
V_30 -> V_35 == V_154 -> V_35 &&
V_30 -> V_32 == V_154 -> V_32 ;
}
struct V_9 *
F_80 ( struct V_2 * V_3 , const struct V_29 * V_30 )
{
struct V_11 V_156 ;
struct V_9 * V_10 ;
struct V_138 * V_139 ;
int V_36 , V_157 , V_65 ;
V_157 = V_30 -> V_79 ;
V_139 = F_76 ( V_3 ) ;
if ( V_139 -> V_158 ) {
V_36 = V_139 -> V_158 ( V_3 ) ;
if ( V_36 < 0 ) {
V_10 = F_81 ( V_36 ) ;
goto V_159;
}
if ( V_36 )
V_157 = V_36 ;
}
V_10 = F_82 ( sizeof( struct V_9 ) +
sizeof( unsigned int ) * V_157 ,
V_160 ) ;
if ( ! V_10 ) {
V_10 = F_81 ( - V_22 ) ;
goto V_161;
}
V_10 -> V_3 = V_3 ;
V_10 -> V_139 = V_139 ;
memset ( & V_156 , 0 , sizeof( struct V_11 ) ) ;
V_156 . V_33 = V_162 | V_163 | V_164 ;
V_156 . V_165 = V_30 -> V_155 * 16 ;
V_156 . V_144 = F_77 ( V_3 , V_30 ) ;
V_156 . V_3 = & V_3 -> V_3 ;
for ( V_65 = 0 ; V_65 < V_157 ; V_65 ++ ) {
if ( V_139 -> V_166 ( V_10 , V_30 , & V_156 , V_65 ) )
break;
#ifdef F_83
F_2 ( V_47 L_20 ,
V_156 . V_25 , V_156 . V_144 , V_156 . V_23 ) ;
#endif
V_10 -> line [ V_65 ] = F_84 ( & V_156 ) ;
if ( V_10 -> line [ V_65 ] < 0 ) {
F_2 ( V_4 L_21 , F_3 ( V_3 ) , V_10 -> line [ V_65 ] ) ;
break;
}
}
V_10 -> V_167 = V_65 ;
return V_10 ;
V_161:
if ( V_139 -> exit )
V_139 -> exit ( V_3 ) ;
V_159:
return V_10 ;
}
void F_85 ( struct V_9 * V_10 )
{
struct V_138 * V_139 ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_10 -> V_167 ; V_65 ++ )
F_86 ( V_10 -> line [ V_65 ] ) ;
for ( V_65 = 0 ; V_65 < V_18 ; V_65 ++ ) {
if ( V_10 -> V_21 [ V_65 ] )
F_19 ( V_10 -> V_21 [ V_65 ] ) ;
V_10 -> V_21 [ V_65 ] = NULL ;
}
V_139 = F_76 ( V_10 -> V_3 ) ;
if ( V_139 -> exit )
V_139 -> exit ( V_10 -> V_3 ) ;
F_87 ( V_10 ) ;
}
void F_88 ( struct V_9 * V_10 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_10 -> V_167 ; V_65 ++ )
if ( V_10 -> line [ V_65 ] >= 0 )
F_89 ( V_10 -> line [ V_65 ] ) ;
if ( V_10 -> V_139 -> exit )
V_10 -> V_139 -> exit ( V_10 -> V_3 ) ;
}
void F_90 ( struct V_9 * V_10 )
{
int V_65 ;
if ( V_10 -> V_139 -> V_158 )
V_10 -> V_139 -> V_158 ( V_10 -> V_3 ) ;
for ( V_65 = 0 ; V_65 < V_10 -> V_167 ; V_65 ++ )
if ( V_10 -> line [ V_65 ] >= 0 )
F_91 ( V_10 -> line [ V_65 ] ) ;
}
static int T_6
F_92 ( struct V_2 * V_3 , const struct V_145 * V_168 )
{
struct V_138 * V_139 ;
struct V_9 * V_10 ;
const struct V_29 * V_30 ;
struct V_29 V_169 ;
int V_36 ;
V_139 = F_76 ( V_3 ) ;
if ( V_139 -> V_170 ) {
V_36 = V_139 -> V_170 ( V_3 ) ;
if ( V_36 )
return V_36 ;
}
if ( V_168 -> V_171 >= F_40 ( V_172 ) ) {
F_2 ( V_108 L_22 ,
V_168 -> V_171 ) ;
return - V_19 ;
}
V_30 = & V_172 [ V_168 -> V_171 ] ;
V_36 = F_93 ( V_3 ) ;
F_94 ( V_3 ) ;
if ( V_36 )
return V_36 ;
if ( V_168 -> V_171 == V_173 ) {
memcpy ( & V_169 , V_30 , sizeof( struct V_29 ) ) ;
V_30 = & V_169 ;
V_36 = F_78 ( V_3 , & V_169 ) ;
if ( V_36 )
goto V_174;
} else {
memcpy ( & V_169 , & V_172 [ V_173 ] ,
sizeof( struct V_29 ) ) ;
V_36 = F_78 ( V_3 , & V_169 ) ;
if ( V_36 == 0 && F_79 ( V_30 , & V_169 ) )
F_1 ( L_23 ,
V_3 ) ;
}
V_10 = F_80 ( V_3 , V_30 ) ;
if ( ! F_95 ( V_10 ) ) {
F_96 ( V_3 , V_10 ) ;
return 0 ;
}
V_36 = F_97 ( V_10 ) ;
V_174:
F_98 ( V_3 ) ;
return V_36 ;
}
static void T_3 F_99 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = F_100 ( V_3 ) ;
F_96 ( V_3 , NULL ) ;
F_85 ( V_10 ) ;
F_98 ( V_3 ) ;
}
static int F_101 ( struct V_2 * V_3 , T_7 V_175 )
{
struct V_9 * V_10 = F_100 ( V_3 ) ;
if ( V_10 )
F_88 ( V_10 ) ;
F_94 ( V_3 ) ;
F_102 ( V_3 , F_103 ( V_3 , V_175 ) ) ;
return 0 ;
}
static int F_104 ( struct V_2 * V_3 )
{
int V_176 ;
struct V_9 * V_10 = F_100 ( V_3 ) ;
F_102 ( V_3 , V_177 ) ;
F_105 ( V_3 ) ;
if ( V_10 ) {
V_176 = F_93 ( V_3 ) ;
if ( V_176 )
F_2 ( V_108 L_24 ) ;
F_90 ( V_10 ) ;
}
return 0 ;
}
static T_8 F_106 ( struct V_2 * V_3 ,
T_9 V_175 )
{
struct V_9 * V_10 = F_100 ( V_3 ) ;
if ( V_175 == V_178 )
return V_179 ;
if ( V_10 )
F_88 ( V_10 ) ;
F_98 ( V_3 ) ;
return V_180 ;
}
static T_8 F_107 ( struct V_2 * V_3 )
{
int V_36 ;
V_36 = F_93 ( V_3 ) ;
if ( V_36 )
return V_179 ;
F_105 ( V_3 ) ;
F_94 ( V_3 ) ;
return V_181 ;
}
static void F_108 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = F_100 ( V_3 ) ;
if ( V_10 )
F_90 ( V_10 ) ;
}
static int T_10 F_109 ( void )
{
return F_110 ( & V_182 ) ;
}
static void T_11 F_111 ( void )
{
F_112 ( & V_182 ) ;
}
