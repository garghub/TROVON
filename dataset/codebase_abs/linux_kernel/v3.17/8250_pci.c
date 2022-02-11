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
unsigned long V_15 , V_16 ;
if ( V_12 >= V_17 )
return - V_18 ;
V_15 = F_5 ( V_3 , V_12 ) ;
if ( F_6 ( V_3 , V_12 ) & V_19 ) {
V_16 = F_7 ( V_3 , V_12 ) ;
if ( ! V_9 -> V_20 [ V_12 ] )
V_9 -> V_20 [ V_12 ] = F_8 ( V_15 , V_16 ) ;
if ( ! V_9 -> V_20 [ V_12 ] )
return - V_21 ;
V_11 -> V_11 . V_22 = V_23 ;
V_11 -> V_11 . V_24 = 0 ;
V_11 -> V_11 . V_25 = V_15 + V_13 ;
V_11 -> V_11 . V_26 = V_9 -> V_20 [ V_12 ] + V_13 ;
V_11 -> V_11 . V_14 = V_14 ;
} else {
V_11 -> V_11 . V_22 = V_27 ;
V_11 -> V_11 . V_24 = V_15 + V_13 ;
V_11 -> V_11 . V_25 = 0 ;
V_11 -> V_11 . V_26 = NULL ;
V_11 -> V_11 . V_14 = 0 ;
}
return 0 ;
}
static int F_9 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
unsigned int V_12 = 0 , V_13 = V_29 -> V_31 ;
V_12 = F_10 ( V_29 -> V_32 ) ;
if ( V_30 < 2 ) {
V_13 += V_30 * V_29 -> V_33 ;
} else if ( ( V_30 >= 2 ) && ( V_30 < 4 ) ) {
V_12 += 1 ;
V_13 += ( ( V_30 - 2 ) * V_29 -> V_33 ) ;
} else if ( ( V_30 >= 4 ) && ( V_30 < 6 ) ) {
V_12 += 2 ;
V_13 += ( ( V_30 - 4 ) * V_29 -> V_33 ) ;
} else if ( V_30 >= 6 ) {
V_12 += 3 ;
V_13 += ( ( V_30 - 6 ) * V_29 -> V_33 ) ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_29 -> V_34 ) ;
}
static int
F_11 ( struct V_8 * V_9 , const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
unsigned int V_12 , V_13 = V_29 -> V_31 ;
V_12 = F_10 ( V_29 -> V_32 ) ;
if ( V_30 < 4 )
V_12 += V_30 ;
else {
V_12 = 4 ;
V_13 += ( V_30 - 4 ) * V_29 -> V_33 ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_29 -> V_34 ) ;
}
static int F_12 ( struct V_2 * V_3 )
{
int V_35 = 0 ;
switch ( V_3 -> V_7 ) {
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_35 = 3 ;
break;
case V_40 :
V_35 = 2 ;
break;
case V_41 :
V_35 = 4 ;
break;
case V_42 :
case V_43 :
V_35 = 1 ;
break;
}
return V_35 ;
}
static int
F_13 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
unsigned int V_13 = V_29 -> V_31 ;
unsigned int V_12 = F_10 ( V_29 -> V_32 ) ;
switch ( V_9 -> V_3 -> V_7 ) {
case V_41 :
if ( V_30 == 3 )
V_30 ++ ;
break;
case V_39 :
if ( V_30 > 0 )
V_30 ++ ;
if ( V_30 > 2 )
V_30 ++ ;
break;
}
if ( V_30 > 2 )
V_13 = 0x18 ;
V_13 += V_30 * V_29 -> V_33 ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_29 -> V_34 ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
unsigned long V_44 ;
if ( ! ( V_3 -> V_7 & 0x1000 ) )
return - V_45 ;
F_15 ( V_3 , 0x44 , ( void * ) & V_44 ) ;
if ( V_44 == 0x00001000L ) {
F_16 ( & V_3 -> V_3 , L_6 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
T_1 V_46 ;
void T_2 * V_47 ;
if ( ( F_6 ( V_3 , 0 ) & V_19 ) == 0 ) {
F_1 ( L_7 , V_3 ) ;
return 0 ;
}
V_46 = 0x41 ;
if ( V_3 -> V_4 == V_48 ||
V_3 -> V_6 == V_49 )
V_46 = 0x43 ;
if ( ( V_3 -> V_4 == V_50 ) &&
( V_3 -> V_5 == V_51 ) )
V_46 = 0x5b ;
V_47 = F_8 ( F_5 ( V_3 , 0 ) , 0x80 ) ;
if ( V_47 == NULL )
return - V_21 ;
F_18 ( V_46 , V_47 + 0x4c ) ;
F_19 ( V_47 + 0x4c ) ;
F_20 ( V_47 ) ;
return 0 ;
}
static void F_21 ( struct V_2 * V_3 )
{
T_1 T_2 * V_47 ;
if ( ( F_6 ( V_3 , 0 ) & V_19 ) == 0 )
return;
V_47 = F_8 ( F_5 ( V_3 , 0 ) , 0x80 ) ;
if ( V_47 != NULL ) {
F_18 ( 0 , V_47 + 0x4c ) ;
F_19 ( V_47 + 0x4c ) ;
F_20 ( V_47 ) ;
}
}
static void F_22 ( struct V_2 * V_3 )
{
void T_2 * V_47 ;
unsigned long V_15 , V_16 ;
unsigned int V_12 = 0 ;
if ( ( F_6 ( V_3 , V_12 ) & V_19 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return;
}
V_15 = F_5 ( V_3 , V_12 ) ;
V_16 = F_7 ( V_3 , V_12 ) ;
V_47 = F_8 ( V_15 , V_16 ) ;
if ( V_47 == NULL )
return;
F_18 ( F_19 ( V_47 + V_52 ) & ~ ( V_53 ) ,
V_47 + V_52 ) ;
F_20 ( V_47 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
void T_2 * V_47 ;
unsigned long V_15 , V_16 ;
unsigned int V_12 = 0 ;
if ( ( F_6 ( V_3 , V_12 ) & V_19 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return;
}
V_15 = F_5 ( V_3 , V_12 ) ;
V_16 = F_7 ( V_3 , V_12 ) ;
V_47 = F_8 ( V_15 , V_16 ) ;
if ( V_47 == NULL )
return;
F_18 ( V_54 , V_47 + V_55 ) ;
F_20 ( V_47 ) ;
}
static int
F_24 ( struct V_8 * V_9 , const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
unsigned int V_12 , V_13 = V_29 -> V_31 ;
V_12 = 0 ;
if ( V_30 < 4 ) {
V_13 += V_30 * V_29 -> V_33 ;
} else if ( V_30 < 8 ) {
V_13 += V_30 * V_29 -> V_33 + 0xC00 ;
} else
return 1 ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_29 -> V_34 ) ;
}
static int F_25 ( struct V_2 * V_3 )
{
T_1 T_2 * V_47 ;
V_47 = F_26 ( V_3 , 0 ) ;
if ( V_47 == NULL )
return - V_21 ;
F_27 ( 0x10 , V_47 + V_56 ) ;
F_28 ( 50 ) ;
F_27 ( 0x0 , V_47 + V_56 ) ;
F_27 ( 0x4 , V_47 + V_56 ) ;
F_20 ( V_47 ) ;
return 0 ;
}
static void F_29 ( struct V_2 * V_3 )
{
T_1 T_2 * V_47 ;
V_47 = F_26 ( V_3 , 0 ) ;
if ( V_47 != NULL )
F_27 ( 0 , V_47 + V_56 ) ;
F_20 ( V_47 ) ;
}
static int F_30 ( struct V_2 * V_3 )
{
T_3 V_57 ;
void T_2 * V_47 ;
switch ( V_3 -> V_5 & 0xfff8 ) {
case V_58 :
V_57 = 0xffdf ;
break;
case V_59 :
V_57 = 0xf7ff ;
break;
default:
V_57 = 0xfffb ;
break;
}
V_47 = F_8 ( F_5 ( V_3 , 0 ) , 0x80 ) ;
if ( V_47 == NULL )
return - V_21 ;
F_31 ( F_32 ( V_47 + 0x28 ) & V_57 , V_47 + 0x28 ) ;
F_32 ( V_47 + 0x28 ) ;
F_20 ( V_47 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 )
{
T_1 V_57 ;
F_34 ( V_3 , 0x6f , & V_57 ) ;
F_35 ( V_3 , 0x6f , V_57 & 0xef ) ;
if ( ( ( V_3 -> V_5 & 0xfffc ) == V_60 ) ||
( ( V_3 -> V_5 & 0xfffc ) == V_61 ) ) {
F_34 ( V_3 , 0x73 , & V_57 ) ;
F_35 ( V_3 , 0x73 , V_57 & 0xef ) ;
}
return 0 ;
}
static int F_36 ( struct V_2 * V_3 )
{
unsigned int type = V_3 -> V_5 & 0xff00 ;
if ( type == 0x1000 )
return F_30 ( V_3 ) ;
else if ( type == 0x2000 )
return F_33 ( V_3 ) ;
F_1 ( L_9 , V_3 ) ;
return - V_45 ;
}
static int F_37 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
unsigned int V_12 = F_10 ( V_29 -> V_32 ) + V_30 , V_13 = 0 ;
if ( V_30 > 3 ) {
V_12 = 4 ;
V_13 = ( V_30 - 4 ) * 8 ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , 0 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
if ( ( V_3 -> V_7 & 0x00f0 ) >= 0x70 ) {
F_39 ( & V_3 -> V_3 ,
L_10 ,
V_3 -> V_7 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_40 ( struct V_2 * V_3 )
{
const unsigned short * V_62 ;
int V_63 , V_64 ;
for ( V_63 = 0 ; V_63 < F_41 ( V_65 ) ; V_63 ++ ) {
V_62 = V_65 [ V_63 ] . V_62 ;
for ( V_64 = 0 ; V_62 [ V_64 ] ; V_64 ++ )
if ( V_3 -> V_7 == V_62 [ V_64 ] )
return V_65 [ V_63 ] . V_66 ;
}
return 0 ;
}
static int
F_42 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
unsigned int V_12 = 0 , V_13 = V_29 -> V_31 ;
switch ( V_30 ) {
case 0 :
V_12 = 0 ;
break;
case 1 :
V_13 = V_29 -> V_33 ;
V_12 = 0 ;
break;
case 2 :
V_12 = 1 ;
break;
case 3 :
V_13 = V_29 -> V_33 ;
case 4 :
case 5 :
case 6 :
case 7 :
V_12 = V_30 - 2 ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_29 -> V_34 ) ;
}
static int
F_43 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
unsigned int V_12 , V_13 = V_29 -> V_31 ;
switch ( V_30 ) {
case 0 :
V_12 = 1 ;
break;
case 1 :
V_12 = 2 ;
break;
default:
V_12 = 4 ;
V_13 = ( V_30 - 2 ) * V_29 -> V_33 ;
}
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_29 -> V_34 ) ;
}
static int F_44 ( struct V_2 * V_3 )
{
F_45 ( 100 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 )
{
void T_2 * V_47 ;
unsigned long V_15 , V_16 ;
unsigned int V_12 = 0 ;
if ( ( F_6 ( V_3 , V_12 ) & V_19 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return 0 ;
}
V_15 = F_5 ( V_3 , V_12 ) ;
V_16 = F_7 ( V_3 , V_12 ) ;
V_47 = F_8 ( V_15 , V_16 ) ;
if ( V_47 == NULL )
return - V_21 ;
F_18 ( F_19 ( V_47 + V_52 ) | V_53 ,
V_47 + V_52 ) ;
F_20 ( V_47 ) ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 )
{
void T_2 * V_47 ;
unsigned long V_15 , V_16 ;
T_4 V_67 ;
unsigned int V_12 = 0 ;
if ( ( F_6 ( V_3 , V_12 ) & V_19 ) == 0 ) {
F_1 ( L_8 , V_3 ) ;
return 0 ;
}
V_15 = F_5 ( V_3 , V_12 ) ;
V_16 = F_7 ( V_3 , V_12 ) ;
V_47 = F_8 ( V_15 , V_16 ) ;
if ( V_47 == NULL )
return - V_21 ;
V_67 = ( ( V_15 + V_68 ) & 0xffffff00 )
| V_69 | V_70 ;
F_18 ( V_67 , V_47 + V_71 ) ;
F_18 ( ( F_19 ( V_47 + V_72 ) & V_73 ) ,
V_47 + V_72 ) ;
F_18 ( V_74 , V_47 + V_75 ) ;
F_18 ( V_76 , V_47 + V_55 ) ;
F_20 ( V_47 ) ;
return 0 ;
}
static int
F_48 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
void T_2 * V_47 ;
unsigned long V_15 , V_16 ;
unsigned int V_12 , V_13 = V_29 -> V_31 ;
if ( V_30 >= V_29 -> V_77 )
return 1 ;
V_12 = F_10 ( V_29 -> V_32 ) ;
V_13 += V_30 * V_29 -> V_33 ;
V_15 = F_5 ( V_9 -> V_3 , V_12 ) ;
V_16 = F_7 ( V_9 -> V_3 , V_12 ) ;
V_47 = F_8 ( V_15 , V_16 ) ;
F_27 ( F_49 ( V_47 + V_13 + V_78 ) | V_79 ,
V_47 + V_13 + V_78 ) ;
F_20 ( V_47 ) ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_29 -> V_34 ) ;
}
static int F_50 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
unsigned int V_12 ;
if ( ( V_9 -> V_3 -> V_5 != V_80 ) &&
( V_9 -> V_3 -> V_7 & 0xff00 ) == 0x3000 ) {
V_12 = 3 * V_30 ;
return F_4 ( V_9 , V_11 , V_12 , 0 , V_29 -> V_34 ) ;
} else {
return F_51 ( V_9 , V_29 , V_11 , V_30 ) ;
}
}
static int F_52 ( struct V_2 * V_3 )
{
unsigned int V_81 = V_3 -> V_82 ;
unsigned int V_83 ;
unsigned short V_84 ;
V_83 = ( V_81 & 0xff ) ;
if ( V_83 == 2 ) {
return 1 ;
} else if ( ( V_83 == 0 ) &&
( V_3 -> V_5 == V_85 ) ) {
V_84 = V_3 -> V_7 & 0xf ;
if ( V_84 > 0 ) {
return V_84 ;
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
unsigned int V_86 = V_3 -> V_7 & 0xf ;
if ( ( V_3 -> V_5 == V_87 ) ||
( V_3 -> V_5 == V_80 ) )
return 0 ;
if ( V_3 -> V_6 == V_88 &&
V_3 -> V_7 == 0x0299 )
return 0 ;
switch ( V_3 -> V_5 ) {
case V_89 :
case V_90 :
case V_91 :
case V_85 :
V_86 = F_52 ( V_3 ) ;
break;
default:
if ( V_86 == 0 ) {
F_1 ( L_13 , V_3 ) ;
}
}
if ( V_86 == 0 )
return - V_45 ;
return V_86 ;
}
static int F_54 ( struct V_2 * V_3 )
{
static const short V_92 [] = { 0x2a0 , 0x2c0 , 0x220 , 0x240 , 0x1e0 ,
0x200 , 0x280 , 0 } ;
int V_93 , V_63 , type ;
struct V_94 * V_24 = NULL ;
T_4 V_95 , V_96 , V_97 ;
V_63 = 0 ;
while ( V_92 [ V_63 ] && V_24 == NULL ) {
V_24 = F_55 ( V_92 [ V_63 ] , V_98 ,
L_14 ) ;
if ( V_24 != NULL ) {
F_56 ( V_3 , V_99 ,
V_100 | V_101 |
V_102 | V_92 [ V_63 ] ) ;
F_56 ( V_3 , V_103 ,
V_92 [ V_63 ] ) ;
V_93 = F_57 ( V_92 [ V_63 ] ) ;
if ( V_93 != 0xff ) {
break;
}
F_58 ( V_24 -> V_104 , V_98 ) ;
V_24 = NULL ;
}
V_63 ++ ;
}
if ( ! V_92 [ V_63 ] ) {
F_2 ( & V_3 -> V_3 , L_15 ) ;
return - V_45 ;
}
type = F_57 ( V_24 -> V_104 + 0x18 ) & 0x0f ;
switch ( type ) {
case 0x2 :
case 0xa :
V_93 = 0 ;
break;
case 0xe :
V_93 = 2 ;
break;
case 0x6 :
V_93 = 1 ;
break;
case 0x8 :
V_93 = 2 ;
break;
default:
F_1 ( L_16 , V_3 ) ;
V_93 = - V_45 ;
}
for ( V_63 = 0 ; V_63 < V_93 ; V_63 ++ ) {
F_15 ( V_3 , V_105 + ( 0x4 * ( V_63 + 1 ) ) ,
& V_97 ) ;
V_97 &= 0x0000FF00 ;
F_56 ( V_3 , V_99 + ( 0x4 * ( V_63 + 1 ) ) ,
V_100 | V_101 |
V_106 | V_97 ) ;
F_15 ( V_3 , V_107 , & V_96 ) ;
V_96 &= ~ ( 0xffff << ( 16 * V_63 ) ) ;
V_96 |= ( V_97 << ( 16 * V_63 ) ) ;
F_56 ( V_3 , V_107 , V_96 ) ;
F_15 ( V_3 , V_108 , & V_95 ) ;
V_95 &= ~ ( 0xf << ( 12 - 4 * V_63 ) ) ;
V_95 |= 1 << ( 23 - V_63 ) ;
F_56 ( V_3 , V_108 , V_95 ) ;
}
if ( V_93 <= 0 ) {
F_58 ( V_24 -> V_104 , V_98 ) ;
}
return V_93 ;
}
static void F_59 ( struct V_2 * V_3 )
{
T_4 V_97 ;
F_15 ( V_3 , V_99 , & V_97 ) ;
V_97 &= 0xffff ;
F_58 ( V_97 , V_98 ) ;
}
static int F_60 ( struct V_2 * V_3 )
{
T_1 T_2 * V_47 ;
unsigned long V_109 ;
unsigned int V_110 = 0 ;
if ( V_3 -> V_4 == V_111 &&
( V_3 -> V_5 & 0xF000 ) != 0xC000 )
return 0 ;
V_47 = F_61 ( V_3 , 0 , 5 ) ;
if ( V_47 == NULL )
return - V_21 ;
V_109 = F_62 ( V_47 ) ;
if ( V_109 == 0x07000200 ) {
V_110 = F_63 ( V_47 + 4 ) ;
F_16 ( & V_3 -> V_3 ,
L_17 ,
V_110 ) ;
}
F_64 ( V_3 , V_47 ) ;
return V_110 ;
}
static int F_65 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
V_11 -> V_112 |= V_113 ;
return F_51 ( V_9 , V_29 , V_11 , V_30 ) ;
}
static int F_66 ( T_3 V_114 )
{
struct V_115 * V_116 = & V_117 [ 0 ] ;
while ( V_116 -> V_114 ) {
if ( V_116 -> V_114 == V_114 )
return V_116 -> V_118 ;
V_116 ++ ;
}
F_67 ( L_18 , V_114 ) ;
return 0 ;
}
static int F_68 ( struct V_10 * V_11 )
{
unsigned long V_15 = V_11 -> V_11 . V_24 ;
T_1 V_119 , V_120 ;
V_119 = F_57 ( V_15 + V_121 ) ;
F_69 ( 0xBF , V_15 + V_121 ) ;
V_120 = F_57 ( V_15 + V_122 ) ;
F_69 ( V_119 , V_15 + V_121 ) ;
return V_120 ;
}
static void F_70 ( struct V_10 * V_11 , T_1 V_123 )
{
unsigned long V_15 = V_11 -> V_11 . V_24 ;
T_1 V_119 , V_120 ;
V_119 = F_57 ( V_15 + V_121 ) ;
F_69 ( 0xBF , V_15 + V_121 ) ;
V_120 = F_57 ( V_15 + V_122 ) ;
F_69 ( V_123 , V_15 + V_122 ) ;
F_69 ( V_119 , V_15 + V_121 ) ;
}
static int F_71 ( struct V_10 * V_11 )
{
unsigned long V_15 = V_11 -> V_11 . V_24 ;
T_1 V_119 , V_120 , V_124 ;
V_119 = F_57 ( V_15 + V_121 ) ;
F_69 ( 0xBF , V_15 + V_121 ) ;
V_120 = F_57 ( V_15 + V_122 ) ;
F_69 ( V_120 | 0x10 , V_15 + V_122 ) ;
V_124 = F_57 ( V_15 + V_125 ) ;
F_69 ( V_120 , V_15 + V_122 ) ;
F_69 ( V_119 , V_15 + V_121 ) ;
return V_124 ;
}
static void F_72 ( struct V_10 * V_11 , T_1 V_124 )
{
unsigned long V_15 = V_11 -> V_11 . V_24 ;
T_1 V_119 , V_120 ;
V_119 = F_57 ( V_15 + V_121 ) ;
F_69 ( 0xBF , V_15 + V_121 ) ;
V_120 = F_57 ( V_15 + V_122 ) ;
F_69 ( V_120 | 0x10 , V_15 + V_122 ) ;
F_69 ( V_124 , V_15 + V_125 ) ;
F_69 ( V_120 , V_15 + V_122 ) ;
F_69 ( V_119 , V_15 + V_121 ) ;
}
static int F_73 ( struct V_10 * V_11 )
{
unsigned long V_15 = V_11 -> V_11 . V_24 ;
T_1 V_119 , V_120 ;
V_119 = F_57 ( V_15 + V_121 ) ;
F_69 ( 0xBF , V_15 + V_121 ) ;
V_120 = F_57 ( V_15 + V_122 ) ;
if ( V_120 & 0x20 ) {
F_69 ( 0x80 , V_121 ) ;
if ( ! ( F_57 ( V_122 ) & 0x20 ) ) {
F_69 ( V_119 , V_15 + V_121 ) ;
return 1 ;
}
}
return 0 ;
}
static int F_74 ( struct V_10 * V_11 )
{
T_1 V_126 ;
T_1 V_123 = F_68 ( V_11 ) ;
F_70 ( V_11 , V_123 & V_127 ) ;
V_126 = F_68 ( V_11 ) & 0xC0 ;
if ( V_126 != V_128 )
return - V_18 ;
F_70 ( V_11 , ( V_123 & V_127 ) | V_129 ) ;
V_126 = F_68 ( V_11 ) & 0xC0 ;
if ( V_126 != V_130 )
return - V_18 ;
F_70 ( V_11 , ( V_123 & V_127 ) | V_131 ) ;
V_126 = F_68 ( V_11 ) & 0xC0 ;
if ( V_126 != V_132 )
return - V_18 ;
F_70 ( V_11 , ( V_123 & V_127 ) | V_133 ) ;
V_126 = F_68 ( V_11 ) & 0xC0 ;
if ( V_126 != V_134 )
return - V_18 ;
F_70 ( V_11 , V_123 ) ;
return 0 ;
}
static int F_75 ( struct V_10 * V_11 )
{
T_1 V_123 , V_126 , V_135 ;
unsigned long clock ;
if ( F_74 ( V_11 ) < 0 )
return 1843200 ;
V_123 = F_68 ( V_11 ) ;
F_70 ( V_11 , V_123 & ~ V_136 ) ;
V_126 = F_68 ( V_11 ) ;
if ( V_126 & V_136 ) {
clock = 1843200 ;
goto V_137;
}
F_70 ( V_11 , V_123 | V_136 ) ;
V_126 = F_68 ( V_11 ) ;
if ( ! ( V_126 & V_136 ) ) {
clock = 1843200 ;
goto V_137;
}
V_126 &= V_136 ;
if ( V_126 == V_138 ) {
clock = 3685400 ;
V_135 = V_138 ;
} else if ( V_126 == V_139 ) {
clock = 7372800 ;
V_135 = V_139 ;
} else if ( V_126 == V_136 ) {
clock = 14745600 ;
V_135 = V_136 ;
} else {
clock = 1843200 ;
V_135 = V_140 ;
}
V_123 &= ~ V_141 ;
V_123 |= V_135 ;
V_137:
F_70 ( V_11 , V_123 ) ;
return clock ;
}
static int F_76 ( struct V_10 * V_11 )
{
T_1 V_124 ;
int V_142 = 0 ;
if ( ! F_73 ( V_11 ) )
return 0 ;
V_124 = F_71 ( V_11 ) ;
F_72 ( V_11 , 0xFF ) ;
if ( F_71 ( V_11 ) )
V_142 = 1 ;
F_72 ( V_11 , V_124 ) ;
return V_142 ;
}
static int F_77 ( struct V_2 * V_3 )
{
if ( F_66 ( V_3 -> V_5 ) ) {
unsigned long V_15 = F_5 ( V_3 , 0 ) ;
if ( V_15 ) {
T_4 V_143 ;
F_78 ( F_79 ( V_15 + 0x38 ) | 0x00002000 , V_15 + 0x38 ) ;
V_143 = F_79 ( V_15 + 0x3c ) ;
F_78 ( V_143 | 0x01000000 , V_15 + 0x3c ) ;
F_78 ( V_143 &= ~ 0x01000000 , V_15 + 0x3c ) ;
}
}
return 0 ;
}
static int F_80 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
V_11 -> V_11 . V_24 = F_5 ( V_9 -> V_3 , F_10 ( V_29 -> V_32 ) ) ;
V_11 -> V_11 . V_144 = F_75 ( V_11 ) ;
if ( F_76 ( V_11 ) )
F_81 ( L_19 ) ;
return F_51 ( V_9 , V_29 , V_11 , V_30 ) ;
}
static void F_82 ( struct V_2 * V_3 )
{
}
static int F_51 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
unsigned int V_12 , V_13 = V_29 -> V_31 , V_145 ;
V_12 = F_10 ( V_29 -> V_32 ) ;
if ( V_29 -> V_32 & V_146 )
V_12 += V_30 ;
else
V_13 += V_30 * V_29 -> V_33 ;
V_145 = ( F_7 ( V_9 -> V_3 , V_12 ) - V_29 -> V_31 ) >>
( V_29 -> V_34 + 3 ) ;
if ( V_29 -> V_32 & V_147 && V_30 >= V_145 )
return 1 ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_29 -> V_34 ) ;
}
static int F_83 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
unsigned int V_12 , V_13 = V_29 -> V_31 , V_145 ;
V_12 = F_10 ( V_29 -> V_32 ) ;
if ( V_29 -> V_32 & V_146 )
V_12 += V_30 ;
else
V_13 += V_30 * V_29 -> V_33 ;
V_145 = ( F_7 ( V_9 -> V_3 , V_12 ) - V_29 -> V_31 ) >>
( V_29 -> V_34 + 3 ) ;
if ( V_29 -> V_32 & V_147 && V_30 >= V_145 )
return 1 ;
V_11 -> V_11 . V_144 = 14745600 ;
return F_4 ( V_9 , V_11 , V_12 , V_13 , V_29 -> V_34 ) ;
}
static int
F_84 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
int V_93 ;
V_93 = F_4 ( V_9 , V_11 , V_30 , 0 , V_29 -> V_34 ) ;
V_11 -> V_11 . V_22 = V_148 ;
V_11 -> V_11 . type = V_149 ;
V_11 -> V_11 . V_32 = ( V_11 -> V_11 . V_32 | V_150 | V_151 ) ;
V_11 -> V_11 . V_14 = 2 ;
return V_93 ;
}
static void
F_85 ( struct V_152 * V_47 , struct V_153 * V_154 ,
struct V_153 * V_155 )
{
unsigned int V_156 = F_86 ( V_154 ) ;
unsigned int V_157 , V_158 ;
T_4 V_126 ;
switch ( V_156 ) {
case 500000 :
case 1000000 :
case 2000000 :
case 4000000 :
V_157 = 64 ;
V_158 = 100 ;
V_47 -> V_144 = 64000000 ;
break;
case 3500000 :
V_157 = 56 ;
V_158 = 100 ;
V_47 -> V_144 = 56000000 ;
break;
case 1500000 :
case 3000000 :
V_157 = 48 ;
V_158 = 100 ;
V_47 -> V_144 = 48000000 ;
break;
case 2500000 :
V_157 = 40 ;
V_158 = 100 ;
V_47 -> V_144 = 40000000 ;
break;
default:
V_157 = 2304 ;
V_158 = 3125 ;
V_47 -> V_144 = 73728000 ;
}
V_126 = ( V_157 << V_159 ) | ( V_158 << V_160 ) ;
F_18 ( V_126 , V_47 -> V_26 + V_161 ) ;
V_126 |= V_162 | V_163 ;
F_18 ( V_126 , V_47 -> V_26 + V_161 ) ;
V_126 = F_19 ( V_47 -> V_26 + V_164 ) ;
V_126 &= ~ V_165 ;
if ( V_154 -> V_166 & V_167 )
V_126 |= V_165 ;
F_18 ( V_126 , V_47 -> V_26 + V_164 ) ;
F_87 ( V_47 , V_154 , V_155 ) ;
}
static bool F_88 ( struct V_168 * V_169 , void * V_170 )
{
return V_169 -> V_171 == * ( int * ) V_170 ;
}
static int
F_89 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
struct V_172 * V_173 ;
int V_93 ;
V_173 = F_90 ( V_11 -> V_11 . V_3 , sizeof( * V_173 ) , V_174 ) ;
if ( ! V_173 )
return - V_21 ;
switch ( V_9 -> V_3 -> V_5 ) {
case V_175 :
V_173 -> V_176 = 3 ;
V_173 -> V_177 = 2 ;
break;
case V_178 :
V_173 -> V_176 = 5 ;
V_173 -> V_177 = 4 ;
break;
default:
return - V_18 ;
}
V_173 -> V_179 . V_180 = V_173 -> V_176 ;
V_173 -> V_179 . V_181 = 16 ;
V_173 -> V_182 . V_180 = V_173 -> V_177 ;
V_173 -> V_182 . V_183 = 16 ;
V_173 -> V_184 = F_88 ;
V_173 -> V_185 = & V_173 -> V_176 ;
V_173 -> V_186 = & V_173 -> V_177 ;
V_93 = F_51 ( V_9 , V_29 , V_11 , V_30 ) ;
V_11 -> V_11 . V_22 = V_23 ;
V_11 -> V_11 . type = V_187 ;
V_11 -> V_11 . V_32 = ( V_11 -> V_11 . V_32 | V_150 | V_151 ) ;
V_11 -> V_11 . V_188 = F_85 ;
V_11 -> V_11 . V_189 = 64 ;
V_11 -> V_190 = 64 ;
V_11 -> V_173 = V_173 ;
V_11 -> V_191 = V_192 | V_193 ;
F_18 ( V_194 , V_11 -> V_11 . V_26 + V_195 ) ;
return V_93 ;
}
static int
F_91 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
return F_4 ( V_9 , V_11 , 2 , V_30 * 8 , 0 ) ;
}
static int
F_92 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
int V_93 = F_51 ( V_9 , V_29 , V_11 , V_30 ) ;
V_11 -> V_11 . type = V_196 ;
V_11 -> V_11 . V_32 = ( V_11 -> V_11 . V_32 | V_150 | V_151 ) ;
return V_93 ;
}
static int F_93 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
struct V_2 * V_197 = V_9 -> V_3 ;
unsigned long V_15 ;
unsigned long V_24 ;
unsigned long V_198 = 0 ;
T_1 V_199 ;
switch ( V_30 ) {
case 0 : V_24 = 0xe000 ; V_199 = 0x40 ; break;
case 1 : V_24 = 0xe008 ; V_199 = 0x48 ; break;
case 2 : V_24 = 0xe010 ; V_199 = 0x50 ; break;
case 3 : V_24 = 0xe018 ; V_199 = 0x58 ; break;
case 4 : V_24 = 0xe020 ; V_199 = 0x60 ; break;
case 5 : V_24 = 0xe028 ; V_199 = 0x68 ; break;
case 6 : V_24 = 0xe030 ; V_199 = 0x70 ; break;
case 7 : V_24 = 0xe038 ; V_199 = 0x78 ; break;
case 8 : V_24 = 0xe040 ; V_199 = 0x80 ; break;
case 9 : V_24 = 0xe048 ; V_199 = 0x88 ; break;
case 10 : V_24 = 0xe050 ; V_199 = 0x90 ; break;
case 11 : V_24 = 0xe058 ; V_199 = 0x98 ; break;
default:
return - V_18 ;
}
if ( V_30 < 4 ) {
V_15 = F_5 ( V_9 -> V_3 , 3 ) ;
V_198 = ( int ) ( V_15 + ( 0x8 * V_30 ) ) ;
}
F_16 ( & V_197 -> V_3 , L_20 ,
V_200 , V_30 , V_24 , V_198 , V_199 ) ;
F_35 ( V_197 , V_199 + 0x00 , 0x01 ) ;
F_35 ( V_197 , V_199 + 0x01 , 0x33 ) ;
F_35 ( V_197 , V_199 + 0x04 , ( T_1 ) ( V_24 & 0xff ) ) ;
F_35 ( V_197 , V_199 + 0x05 , ( T_1 ) ( ( V_24 & 0xff00 ) >> 8 ) ) ;
F_35 ( V_197 , V_199 + 0x06 , V_197 -> V_201 ) ;
V_11 -> V_11 . V_22 = V_27 ;
V_11 -> V_11 . V_24 = V_24 ;
V_11 -> V_11 . V_25 = 0 ;
V_11 -> V_11 . V_26 = NULL ;
V_11 -> V_11 . V_14 = 0 ;
return 0 ;
}
static int F_94 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
V_11 -> V_11 . V_32 |= V_202 ;
F_16 ( & V_9 -> V_3 -> V_3 ,
L_21 ,
V_9 -> V_3 -> V_4 , V_9 -> V_3 -> V_5 ,
V_9 -> V_3 -> V_6 , V_9 -> V_3 -> V_7 ) ;
return F_51 ( V_9 , V_29 , V_11 , V_30 ) ;
}
static void F_95 ( struct V_152 * V_47 )
{
struct V_10 * V_203 = F_96 ( V_47 ) ;
F_97 ( V_203 ) ;
}
static unsigned int F_98 ( struct V_152 * V_47 , int V_13 )
{
struct V_10 * V_203 = F_96 ( V_47 ) ;
unsigned int V_120 ;
V_120 = F_57 ( V_47 -> V_24 + V_13 ) ;
if ( V_13 == V_204 ) {
if ( V_120 == 0 )
V_120 = V_203 -> V_205 ;
}
return V_120 ;
}
static int F_99 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
V_11 -> V_11 . V_32 |= V_206 ;
V_11 -> V_11 . V_207 = F_98 ;
V_11 -> V_11 . V_208 = F_95 ;
return F_94 ( V_9 , V_29 , V_11 , V_30 ) ;
}
static int F_100 ( struct V_2 * V_3 )
{
#if F_101 ( V_209 ) || F_101 ( V_210 )
return - V_45 ;
#else
return 0 ;
#endif
}
static int
F_102 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
V_11 -> V_11 . V_32 |= V_211 ;
return F_51 ( V_9 , V_29 , V_11 , V_30 ) ;
}
static int
F_103 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
T_1 T_2 * V_47 ;
V_47 = F_26 ( V_9 -> V_3 , 0 ) ;
if ( V_47 == NULL )
return - V_21 ;
V_11 -> V_11 . V_32 |= V_211 ;
if ( V_30 == 0 ) {
F_27 ( 0x00 , V_47 + 0x8f ) ;
F_27 ( 0x00 , V_47 + 0x90 ) ;
F_27 ( 0x00 , V_47 + 0x91 ) ;
F_27 ( 0x00 , V_47 + 0x92 ) ;
F_27 ( 0x00 , V_47 + 0x93 ) ;
F_27 ( 0x00 , V_47 + 0x94 ) ;
F_27 ( 0x00 , V_47 + 0x95 ) ;
F_27 ( 0x00 , V_47 + 0x96 ) ;
F_27 ( 0x00 , V_47 + 0x97 ) ;
F_27 ( 0x00 , V_47 + 0x98 ) ;
F_27 ( 0x00 , V_47 + 0x99 ) ;
F_27 ( 0x00 , V_47 + 0x9a ) ;
}
F_27 ( 0x00 , V_47 + V_212 ) ;
F_27 ( V_213 , V_47 + V_214 ) ;
F_27 ( 128 , V_47 + V_215 ) ;
F_27 ( 128 , V_47 + V_216 ) ;
F_20 ( V_47 ) ;
return F_51 ( V_9 , V_29 , V_11 , V_30 ) ;
}
static int
F_104 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
T_1 T_2 * V_47 ;
V_47 = F_26 ( V_9 -> V_3 , 0 ) ;
if ( V_47 == NULL )
return - V_21 ;
V_11 -> V_11 . V_32 |= V_211 ;
if ( V_30 == 0 ) {
switch ( V_9 -> V_3 -> V_5 ) {
case V_217 :
case V_218 :
F_27 ( 0x78 , V_47 + 0x90 ) ;
F_27 ( 0x00 , V_47 + 0x92 ) ;
F_27 ( 0x00 , V_47 + 0x93 ) ;
break;
case V_219 :
case V_220 :
F_27 ( 0x00 , V_47 + 0x90 ) ;
F_27 ( 0xc0 , V_47 + 0x92 ) ;
F_27 ( 0xc0 , V_47 + 0x93 ) ;
break;
}
F_27 ( 0x00 , V_47 + 0x8f ) ;
F_27 ( 0x00 , V_47 + 0x91 ) ;
F_27 ( 0x00 , V_47 + 0x94 ) ;
}
F_27 ( 0x00 , V_47 + V_212 ) ;
F_27 ( V_213 , V_47 + V_214 ) ;
F_27 ( 32 , V_47 + V_215 ) ;
F_27 ( 32 , V_47 + V_216 ) ;
F_20 ( V_47 ) ;
return F_51 ( V_9 , V_29 , V_11 , V_30 ) ;
}
static int
F_105 ( struct V_8 * V_9 ,
const struct V_28 * V_29 ,
struct V_10 * V_11 , int V_30 )
{
V_11 -> V_11 . V_32 |= V_151 ;
V_11 -> V_11 . type = V_187 ;
return F_51 ( V_9 , V_29 , V_11 , V_30 ) ;
}
static inline int F_106 ( T_4 V_221 , T_4 V_222 )
{
return V_221 == V_223 || V_221 == V_222 ;
}
static struct V_224 * F_107 ( struct V_2 * V_3 )
{
struct V_224 * V_225 ;
for ( V_225 = V_226 ; ; V_225 ++ )
if ( F_106 ( V_225 -> V_4 , V_3 -> V_4 ) &&
F_106 ( V_225 -> V_5 , V_3 -> V_5 ) &&
F_106 ( V_225 -> V_227 , V_3 -> V_6 ) &&
F_106 ( V_225 -> V_228 , V_3 -> V_7 ) )
break;
return V_225 ;
}
static inline int F_108 ( struct V_2 * V_3 ,
const struct V_28 * V_29 )
{
if ( V_29 -> V_32 & V_229 )
return 0 ;
else
return V_3 -> V_201 ;
}
static int
F_109 ( struct V_2 * V_3 , struct V_28 * V_29 )
{
const struct V_230 * V_231 ;
int V_232 , V_233 , V_234 = - 1 , V_63 ;
if ( ( ( ( V_3 -> V_82 >> 8 ) != V_235 ) &&
( ( V_3 -> V_82 >> 8 ) != V_236 ) ) ||
( V_3 -> V_82 & 0xff ) > 6 )
return - V_45 ;
for ( V_231 = V_237 ;
V_231 < V_237 + F_41 ( V_237 ) ;
V_231 ++ ) {
if ( V_3 -> V_4 == V_231 -> V_4 &&
V_3 -> V_5 == V_231 -> V_5 )
return - V_45 ;
}
V_232 = V_233 = 0 ;
for ( V_63 = 0 ; V_63 < V_17 ; V_63 ++ ) {
if ( F_6 ( V_3 , V_63 ) & V_238 ) {
V_233 ++ ;
if ( V_234 == - 1 )
V_234 = V_63 ;
}
if ( F_6 ( V_3 , V_63 ) & V_19 )
V_232 ++ ;
}
if ( V_232 <= 1 && V_233 == 1 ) {
V_29 -> V_32 = V_234 ;
V_29 -> V_77 = F_7 ( V_3 , V_234 ) / 8 ;
return 0 ;
}
V_234 = - 1 ;
V_233 = 0 ;
for ( V_63 = 0 ; V_63 < V_17 ; V_63 ++ ) {
if ( F_6 ( V_3 , V_63 ) & V_238 &&
F_7 ( V_3 , V_63 ) == 8 &&
( V_234 == - 1 || ( V_234 + V_233 ) == V_63 ) ) {
V_233 ++ ;
if ( V_234 == - 1 )
V_234 = V_63 ;
}
}
if ( V_233 > 1 ) {
V_29 -> V_32 = V_234 | V_146 ;
V_29 -> V_77 = V_233 ;
return 0 ;
}
return - V_45 ;
}
static inline int
F_110 ( const struct V_28 * V_29 ,
const struct V_28 * V_239 )
{
return
V_29 -> V_77 == V_239 -> V_77 &&
V_29 -> V_240 == V_239 -> V_240 &&
V_29 -> V_33 == V_239 -> V_33 &&
V_29 -> V_34 == V_239 -> V_34 &&
V_29 -> V_31 == V_239 -> V_31 ;
}
struct V_8 *
F_111 ( struct V_2 * V_3 , const struct V_28 * V_29 )
{
struct V_10 V_241 ;
struct V_8 * V_9 ;
struct V_224 * V_225 ;
int V_35 , V_242 , V_63 ;
V_242 = V_29 -> V_77 ;
V_225 = F_107 ( V_3 ) ;
if ( V_225 -> V_243 ) {
V_35 = V_225 -> V_243 ( V_3 ) ;
if ( V_35 < 0 ) {
V_9 = F_112 ( V_35 ) ;
goto V_244;
}
if ( V_35 )
V_242 = V_35 ;
}
V_9 = F_113 ( sizeof( struct V_8 ) +
sizeof( unsigned int ) * V_242 ,
V_174 ) ;
if ( ! V_9 ) {
V_9 = F_112 ( - V_21 ) ;
goto V_245;
}
V_9 -> V_3 = V_3 ;
V_9 -> V_225 = V_225 ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_11 . V_32 = V_246 | V_247 | V_248 ;
V_241 . V_11 . V_144 = V_29 -> V_240 * 16 ;
V_241 . V_11 . V_201 = F_108 ( V_3 , V_29 ) ;
V_241 . V_11 . V_3 = & V_3 -> V_3 ;
for ( V_63 = 0 ; V_63 < V_242 ; V_63 ++ ) {
if ( V_225 -> V_249 ( V_9 , V_29 , & V_241 , V_63 ) )
break;
F_16 ( & V_3 -> V_3 , L_22 ,
V_241 . V_11 . V_24 , V_241 . V_11 . V_201 , V_241 . V_11 . V_22 ) ;
V_9 -> line [ V_63 ] = F_114 ( & V_241 ) ;
if ( V_9 -> line [ V_63 ] < 0 ) {
F_2 ( & V_3 -> V_3 ,
L_23 ,
V_241 . V_11 . V_24 , V_241 . V_11 . V_201 ,
V_241 . V_11 . V_22 , V_9 -> line [ V_63 ] ) ;
break;
}
}
V_9 -> V_250 = V_63 ;
return V_9 ;
V_245:
if ( V_225 -> exit )
V_225 -> exit ( V_3 ) ;
V_244:
return V_9 ;
}
void F_115 ( struct V_8 * V_9 )
{
struct V_224 * V_225 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_9 -> V_250 ; V_63 ++ )
F_116 ( V_9 -> line [ V_63 ] ) ;
for ( V_63 = 0 ; V_63 < V_17 ; V_63 ++ ) {
if ( V_9 -> V_20 [ V_63 ] )
F_20 ( V_9 -> V_20 [ V_63 ] ) ;
V_9 -> V_20 [ V_63 ] = NULL ;
}
V_225 = F_107 ( V_9 -> V_3 ) ;
if ( V_225 -> exit )
V_225 -> exit ( V_9 -> V_3 ) ;
F_117 ( V_9 ) ;
}
void F_118 ( struct V_8 * V_9 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_9 -> V_250 ; V_63 ++ )
if ( V_9 -> line [ V_63 ] >= 0 )
F_119 ( V_9 -> line [ V_63 ] ) ;
if ( V_9 -> V_225 -> exit )
V_9 -> V_225 -> exit ( V_9 -> V_3 ) ;
}
void F_120 ( struct V_8 * V_9 )
{
int V_63 ;
if ( V_9 -> V_225 -> V_243 )
V_9 -> V_225 -> V_243 ( V_9 -> V_3 ) ;
for ( V_63 = 0 ; V_63 < V_9 -> V_250 ; V_63 ++ )
if ( V_9 -> line [ V_63 ] >= 0 )
F_121 ( V_9 -> line [ V_63 ] ) ;
}
static int
F_122 ( struct V_2 * V_3 , const struct V_230 * V_251 )
{
struct V_224 * V_225 ;
struct V_8 * V_9 ;
const struct V_28 * V_29 ;
struct V_28 V_143 ;
int V_35 ;
V_225 = F_107 ( V_3 ) ;
if ( V_225 -> V_252 ) {
V_35 = V_225 -> V_252 ( V_3 ) ;
if ( V_35 )
return V_35 ;
}
if ( V_251 -> V_253 >= F_41 ( V_254 ) ) {
F_2 ( & V_3 -> V_3 , L_24 ,
V_251 -> V_253 ) ;
return - V_18 ;
}
V_29 = & V_254 [ V_251 -> V_253 ] ;
V_35 = F_123 ( V_3 ) ;
F_124 ( V_3 ) ;
if ( V_35 )
return V_35 ;
if ( V_251 -> V_253 == V_255 ) {
memcpy ( & V_143 , V_29 , sizeof( struct V_28 ) ) ;
V_29 = & V_143 ;
V_35 = F_109 ( V_3 , & V_143 ) ;
if ( V_35 )
goto V_256;
} else {
memcpy ( & V_143 , & V_254 [ V_255 ] ,
sizeof( struct V_28 ) ) ;
V_35 = F_109 ( V_3 , & V_143 ) ;
if ( V_35 == 0 && F_110 ( V_29 , & V_143 ) )
F_1 ( L_25 ,
V_3 ) ;
}
V_9 = F_111 ( V_3 , V_29 ) ;
if ( ! F_125 ( V_9 ) ) {
F_126 ( V_3 , V_9 ) ;
return 0 ;
}
V_35 = F_127 ( V_9 ) ;
V_256:
F_128 ( V_3 ) ;
return V_35 ;
}
static void F_129 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_130 ( V_3 ) ;
F_115 ( V_9 ) ;
F_128 ( V_3 ) ;
}
static int F_131 ( struct V_2 * V_3 , T_5 V_257 )
{
struct V_8 * V_9 = F_130 ( V_3 ) ;
if ( V_9 )
F_118 ( V_9 ) ;
F_124 ( V_3 ) ;
F_132 ( V_3 , F_133 ( V_3 , V_257 ) ) ;
return 0 ;
}
static int F_134 ( struct V_2 * V_3 )
{
int V_258 ;
struct V_8 * V_9 = F_130 ( V_3 ) ;
F_132 ( V_3 , V_259 ) ;
F_135 ( V_3 ) ;
if ( V_9 ) {
V_258 = F_123 ( V_3 ) ;
if ( V_258 )
F_2 ( & V_3 -> V_3 , L_26 ) ;
F_120 ( V_9 ) ;
}
return 0 ;
}
static T_6 F_136 ( struct V_2 * V_3 ,
T_7 V_257 )
{
struct V_8 * V_9 = F_130 ( V_3 ) ;
if ( V_257 == V_260 )
return V_261 ;
if ( V_9 )
F_118 ( V_9 ) ;
F_128 ( V_3 ) ;
return V_262 ;
}
static T_6 F_137 ( struct V_2 * V_3 )
{
int V_35 ;
V_35 = F_123 ( V_3 ) ;
if ( V_35 )
return V_261 ;
F_135 ( V_3 ) ;
F_124 ( V_3 ) ;
return V_263 ;
}
static void F_138 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_130 ( V_3 ) ;
if ( V_9 )
F_120 ( V_9 ) ;
}
