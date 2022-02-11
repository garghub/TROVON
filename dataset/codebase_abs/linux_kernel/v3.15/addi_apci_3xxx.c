static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned int V_11 ;
unsigned int V_12 ;
V_11 = F_2 ( V_6 -> V_13 + 16 ) ;
if ( ( V_11 & 0x2 ) == 0x2 ) {
F_3 ( V_11 , V_6 -> V_13 + 16 ) ;
V_12 = F_2 ( V_6 -> V_13 + 28 ) ;
F_4 ( V_9 -> V_14 , V_12 ) ;
V_9 -> V_14 -> V_15 |= V_16 ;
F_5 ( V_4 , V_9 ) ;
return V_17 ;
}
return V_18 ;
}
static int F_6 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( ( F_2 ( V_6 -> V_13 + 8 ) & 0x80000 ) == 0x80000 )
return 1 ;
else
return 0 ;
}
static int F_7 ( struct V_3 * V_4 , unsigned int V_19 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_20 = F_8 ( V_19 ) ;
unsigned int V_21 = F_9 ( V_19 ) ;
unsigned int V_22 = F_10 ( V_19 ) ;
unsigned int V_23 ;
unsigned int V_12 ;
if ( F_6 ( V_4 ) )
return - V_24 ;
F_3 ( 0x10000 , V_6 -> V_13 + 12 ) ;
V_23 = F_2 ( V_6 -> V_13 + 4 ) ;
V_23 &= 0xfffffef0 ;
F_3 ( V_23 , V_6 -> V_13 + 4 ) ;
V_12 = ( V_21 & 3 ) | ( ( V_21 >> 2 ) << 6 ) |
( ( V_22 == V_25 ) << 7 ) ;
F_3 ( V_12 , V_6 -> V_13 + 0 ) ;
F_3 ( V_23 | 0x100 , V_6 -> V_13 + 4 ) ;
F_3 ( V_20 , V_6 -> V_13 + 0 ) ;
F_3 ( V_23 , V_6 -> V_13 + 4 ) ;
F_3 ( 1 , V_6 -> V_13 + 48 ) ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_26 * V_27 ,
unsigned long V_28 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_11 ;
V_11 = F_2 ( V_6 -> V_13 + 20 ) ;
if ( V_11 & 0x1 )
return 0 ;
return - V_24 ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_26 * V_27 ,
unsigned int * V_29 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
int V_30 ;
int V_31 ;
V_30 = F_7 ( V_4 , V_27 -> V_19 ) ;
if ( V_30 )
return V_30 ;
for ( V_31 = 0 ; V_31 < V_27 -> V_32 ; V_31 ++ ) {
F_3 ( 0x80000 , V_6 -> V_13 + 8 ) ;
V_30 = F_13 ( V_4 , V_9 , V_27 , F_11 , 0 ) ;
if ( V_30 )
return V_30 ;
V_29 [ V_31 ] = F_2 ( V_6 -> V_13 + 28 ) ;
}
return V_27 -> V_32 ;
}
static int F_14 ( struct V_3 * V_4 ,
unsigned int * V_33 , int V_34 )
{
const struct V_35 * V_36 = F_15 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_37 ;
unsigned int V_38 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 3 ; V_39 ++ ) {
if ( ! ( V_36 -> V_40 & ( 1 << V_39 ) ) )
continue;
switch ( V_39 ) {
case 0 :
V_37 = 1 ;
break;
case 1 :
V_37 = 1000 ;
break;
case 2 :
V_37 = 1000000 ;
break;
}
switch ( V_34 ) {
case V_41 :
default:
V_38 = ( * V_33 + V_37 / 2 ) / V_37 ;
break;
case V_42 :
V_38 = * V_33 / V_37 ;
break;
case V_43 :
V_38 = ( * V_33 + V_37 - 1 ) / V_37 ;
break;
}
if ( V_38 < 0x10000 ) {
V_6 -> V_44 = V_39 ;
V_6 -> V_45 = V_38 ;
* V_33 = V_38 * V_39 ;
return 0 ;
}
}
return - V_46 ;
}
static int F_16 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_47 * V_48 )
{
const struct V_35 * V_36 = F_15 ( V_4 ) ;
int V_49 = 0 ;
unsigned int V_50 ;
V_49 |= F_17 ( & V_48 -> V_51 , V_52 ) ;
V_49 |= F_17 ( & V_48 -> V_53 , V_54 ) ;
V_49 |= F_17 ( & V_48 -> V_55 , V_56 ) ;
V_49 |= F_17 ( & V_48 -> V_57 , V_58 ) ;
V_49 |= F_17 ( & V_48 -> V_59 , V_58 | V_60 ) ;
if ( V_49 )
return 1 ;
V_49 |= F_18 ( V_48 -> V_59 ) ;
if ( V_49 )
return 2 ;
V_49 |= F_19 ( & V_48 -> V_61 , 0 ) ;
V_49 |= F_19 ( & V_48 -> V_62 , 0 ) ;
V_49 |= F_20 ( & V_48 -> V_63 ,
V_36 -> V_64 ) ;
V_49 |= F_19 ( & V_48 -> V_65 , V_48 -> V_66 ) ;
if ( V_48 -> V_59 == V_58 )
V_49 |= F_20 ( & V_48 -> V_67 , 1 ) ;
else
V_49 |= F_19 ( & V_48 -> V_67 , 0 ) ;
if ( V_49 )
return 3 ;
if ( V_48 -> V_66 > 1 ) {
V_48 -> V_66 = 1 ;
V_49 |= - V_46 ;
}
V_50 = V_48 -> V_63 ;
V_49 |= F_14 ( V_4 , & V_48 -> V_63 ,
V_48 -> V_68 & V_69 ) ;
if ( V_50 != V_48 -> V_63 )
V_49 |= - V_46 ;
if ( V_49 )
return 4 ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_47 * V_48 = & V_9 -> V_14 -> V_48 ;
int V_30 ;
V_30 = F_7 ( V_4 , V_48 -> V_70 [ 0 ] ) ;
if ( V_30 )
return V_30 ;
F_3 ( V_6 -> V_44 , V_6 -> V_13 + 36 ) ;
F_3 ( V_6 -> V_45 , V_6 -> V_13 + 32 ) ;
F_3 ( 0x180000 , V_6 -> V_13 + 8 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
return 0 ;
}
static int F_23 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_26 * V_27 ,
unsigned long V_28 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_11 ;
V_11 = F_2 ( V_6 -> V_13 + 96 ) ;
if ( V_11 & 0x100 )
return 0 ;
return - V_24 ;
}
static int F_24 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_26 * V_27 ,
unsigned int * V_29 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_20 = F_8 ( V_27 -> V_19 ) ;
unsigned int V_21 = F_9 ( V_27 -> V_19 ) ;
int V_30 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_27 -> V_32 ; V_31 ++ ) {
F_3 ( V_21 , V_6 -> V_13 + 96 ) ;
F_3 ( ( V_29 [ V_31 ] << 8 ) | V_20 , V_6 -> V_13 + 100 ) ;
V_30 = F_13 ( V_4 , V_9 , V_27 , F_23 , 0 ) ;
if ( V_30 )
return V_30 ;
}
return V_27 -> V_32 ;
}
static int F_25 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_26 * V_27 ,
unsigned int * V_29 )
{
V_29 [ 1 ] = F_26 ( V_4 -> V_71 + 32 ) & 0xf ;
return V_27 -> V_32 ;
}
static int F_27 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_26 * V_27 ,
unsigned int * V_29 )
{
V_9 -> V_72 = F_26 ( V_4 -> V_71 + 48 ) & 0xf ;
if ( F_28 ( V_9 , V_29 ) )
F_29 ( V_9 -> V_72 , V_4 -> V_71 + 48 ) ;
V_29 [ 1 ] = V_9 -> V_72 ;
return V_27 -> V_32 ;
}
static int F_30 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_26 * V_27 ,
unsigned int * V_29 )
{
unsigned int V_20 = F_8 ( V_27 -> V_19 ) ;
unsigned int V_73 = 0 ;
int V_30 ;
if ( V_29 [ 0 ] != V_74 ) {
if ( V_20 < 16 )
return - V_46 ;
else
V_73 = 0xff0000 ;
}
V_30 = F_31 ( V_4 , V_9 , V_27 , V_29 , V_73 ) ;
if ( V_30 )
return V_30 ;
F_29 ( ( V_9 -> V_75 >> 24 ) & 0xff , V_4 -> V_71 + 224 ) ;
return V_27 -> V_32 ;
}
static int F_32 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_26 * V_27 ,
unsigned int * V_29 )
{
unsigned int V_73 ;
unsigned int V_12 ;
V_73 = F_28 ( V_9 , V_29 ) ;
if ( V_73 ) {
if ( V_73 & 0xff )
F_29 ( V_9 -> V_72 & 0xff , V_4 -> V_71 + 80 ) ;
if ( V_73 & 0xff0000 )
F_29 ( ( V_9 -> V_72 >> 16 ) & 0xff , V_4 -> V_71 + 112 ) ;
}
V_12 = F_26 ( V_4 -> V_71 + 80 ) ;
V_12 |= ( F_26 ( V_4 -> V_71 + 64 ) << 8 ) ;
if ( V_9 -> V_75 & 0xff0000 )
V_12 |= ( F_26 ( V_4 -> V_71 + 112 ) << 16 ) ;
else
V_12 |= ( F_26 ( V_4 -> V_71 + 96 ) << 16 ) ;
V_29 [ 1 ] = V_12 ;
return V_27 -> V_32 ;
}
static int F_33 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_12 ;
int V_31 ;
F_34 ( V_4 -> V_1 ) ;
F_3 ( 0 , V_6 -> V_13 + 8 ) ;
V_12 = F_2 ( V_6 -> V_13 + 16 ) ;
F_3 ( V_12 , V_6 -> V_13 + 16 ) ;
F_2 ( V_6 -> V_13 + 20 ) ;
for ( V_31 = 0 ; V_31 < 16 ; V_31 ++ )
V_12 = F_2 ( V_6 -> V_13 + 28 ) ;
F_35 ( V_4 -> V_1 ) ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 ,
unsigned long V_28 )
{
struct V_76 * V_77 = F_37 ( V_4 ) ;
const struct V_35 * V_36 = NULL ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
int V_78 ;
int V_79 ;
int V_30 ;
if ( V_28 < F_38 ( V_80 ) )
V_36 = & V_80 [ V_28 ] ;
if ( ! V_36 )
return - V_81 ;
V_4 -> V_82 = V_36 ;
V_4 -> V_83 = V_36 -> V_84 ;
V_6 = F_39 ( V_4 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_85 ;
V_30 = F_40 ( V_4 ) ;
if ( V_30 )
return V_30 ;
V_4 -> V_71 = F_41 ( V_77 , 2 ) ;
V_6 -> V_13 = F_42 ( V_77 , 3 ) ;
if ( V_77 -> V_1 > 0 ) {
V_30 = F_43 ( V_77 -> V_1 , F_1 ,
V_86 , V_4 -> V_83 , V_4 ) ;
if ( V_30 == 0 )
V_4 -> V_1 = V_77 -> V_1 ;
}
V_78 = ( V_36 -> V_87 ? 0 : 1 ) + V_36 -> V_88 +
V_36 -> V_89 + V_36 -> V_90 +
V_36 -> V_91 ;
V_30 = F_44 ( V_4 , V_78 ) ;
if ( V_30 )
return V_30 ;
V_79 = 0 ;
if ( V_36 -> V_87 ) {
V_9 = & V_4 -> V_92 [ V_79 ] ;
V_9 -> type = V_93 ;
V_9 -> V_94 = V_95 | V_36 -> V_96 ;
V_9 -> V_97 = V_36 -> V_87 ;
V_9 -> V_98 = V_36 -> V_99 ;
V_9 -> V_100 = V_9 -> V_97 ;
V_9 -> V_101 = & V_102 ;
V_9 -> V_103 = F_12 ;
if ( V_4 -> V_1 ) {
V_4 -> V_10 = V_9 ;
V_9 -> V_94 |= V_104 ;
V_9 -> V_105 = F_16 ;
V_9 -> V_106 = F_21 ;
V_9 -> V_107 = F_22 ;
}
V_79 ++ ;
}
if ( V_36 -> V_88 ) {
V_9 = & V_4 -> V_92 [ V_79 ] ;
V_9 -> type = V_108 ;
V_9 -> V_94 = V_109 | V_110 | V_111 ;
V_9 -> V_97 = 4 ;
V_9 -> V_98 = 0x0fff ;
V_9 -> V_101 = & V_112 ;
V_9 -> V_113 = F_24 ;
V_79 ++ ;
}
if ( V_36 -> V_89 ) {
V_9 = & V_4 -> V_92 [ V_79 ] ;
V_9 -> type = V_114 ;
V_9 -> V_94 = V_95 ;
V_9 -> V_97 = 4 ;
V_9 -> V_98 = 1 ;
V_9 -> V_101 = & V_115 ;
V_9 -> V_116 = F_25 ;
V_79 ++ ;
}
if ( V_36 -> V_90 ) {
V_9 = & V_4 -> V_92 [ V_79 ] ;
V_9 -> type = V_117 ;
V_9 -> V_94 = V_109 ;
V_9 -> V_97 = 4 ;
V_9 -> V_98 = 1 ;
V_9 -> V_101 = & V_115 ;
V_9 -> V_116 = F_27 ;
V_79 ++ ;
}
if ( V_36 -> V_91 ) {
V_9 = & V_4 -> V_92 [ V_79 ] ;
V_9 -> type = V_118 ;
V_9 -> V_94 = V_95 | V_109 ;
V_9 -> V_97 = 24 ;
V_9 -> V_98 = 1 ;
V_9 -> V_75 = 0xff ;
V_9 -> V_101 = & V_115 ;
V_9 -> V_119 = F_30 ;
V_9 -> V_116 = F_32 ;
V_79 ++ ;
}
F_33 ( V_4 ) ;
return 0 ;
}
static void F_45 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 ) {
if ( V_4 -> V_71 )
F_33 ( V_4 ) ;
if ( V_4 -> V_1 )
F_46 ( V_4 -> V_1 , V_4 ) ;
if ( V_6 -> V_13 )
F_47 ( V_6 -> V_13 ) ;
}
F_48 ( V_4 ) ;
}
static int F_49 ( struct V_76 * V_4 ,
const struct V_120 * V_121 )
{
return F_50 ( V_4 , & V_122 , V_121 -> V_123 ) ;
}
