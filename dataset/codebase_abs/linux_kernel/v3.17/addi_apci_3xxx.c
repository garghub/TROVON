static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_8 ;
unsigned int V_9 ;
V_8 = F_2 ( V_4 -> V_10 + 16 ) ;
if ( ( V_8 & 0x2 ) == 0x2 ) {
F_3 ( V_8 , V_4 -> V_10 + 16 ) ;
V_9 = F_2 ( V_4 -> V_10 + 28 ) ;
F_4 ( V_6 , V_9 ) ;
V_6 -> V_11 -> V_12 |= V_13 ;
F_5 ( V_4 , V_6 ) ;
return V_14 ;
}
return V_15 ;
}
static int F_6 ( struct V_3 * V_4 )
{
if ( ( F_2 ( V_4 -> V_10 + 8 ) & 0x80000 ) == 0x80000 )
return 1 ;
return 0 ;
}
static int F_7 ( struct V_3 * V_4 , unsigned int V_16 )
{
unsigned int V_17 = F_8 ( V_16 ) ;
unsigned int V_18 = F_9 ( V_16 ) ;
unsigned int V_19 = F_10 ( V_16 ) ;
unsigned int V_20 ;
unsigned int V_9 ;
if ( F_6 ( V_4 ) )
return - V_21 ;
F_3 ( 0x10000 , V_4 -> V_10 + 12 ) ;
V_20 = F_2 ( V_4 -> V_10 + 4 ) ;
V_20 &= 0xfffffef0 ;
F_3 ( V_20 , V_4 -> V_10 + 4 ) ;
V_9 = ( V_18 & 3 ) | ( ( V_18 >> 2 ) << 6 ) |
( ( V_19 == V_22 ) << 7 ) ;
F_3 ( V_9 , V_4 -> V_10 + 0 ) ;
F_3 ( V_20 | 0x100 , V_4 -> V_10 + 4 ) ;
F_3 ( V_17 , V_4 -> V_10 + 0 ) ;
F_3 ( V_20 , V_4 -> V_10 + 4 ) ;
F_3 ( 1 , V_4 -> V_10 + 48 ) ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_23 * V_24 ,
unsigned long V_25 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_4 -> V_10 + 20 ) ;
if ( V_8 & 0x1 )
return 0 ;
return - V_21 ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_23 * V_24 ,
unsigned int * V_26 )
{
int V_27 ;
int V_28 ;
V_27 = F_7 ( V_4 , V_24 -> V_16 ) ;
if ( V_27 )
return V_27 ;
for ( V_28 = 0 ; V_28 < V_24 -> V_29 ; V_28 ++ ) {
F_3 ( 0x80000 , V_4 -> V_10 + 8 ) ;
V_27 = F_13 ( V_4 , V_6 , V_24 , F_11 , 0 ) ;
if ( V_27 )
return V_27 ;
V_26 [ V_28 ] = F_2 ( V_4 -> V_10 + 28 ) ;
}
return V_24 -> V_29 ;
}
static int F_14 ( struct V_3 * V_4 ,
unsigned int * V_30 , unsigned int V_31 )
{
const struct V_32 * V_33 = F_15 ( V_4 ) ;
struct V_34 * V_35 = V_4 -> V_36 ;
unsigned int V_37 ;
unsigned int V_38 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < 3 ; V_39 ++ ) {
if ( ! ( V_33 -> V_40 & ( 1 << V_39 ) ) )
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
switch ( V_31 & V_41 ) {
case V_42 :
default:
V_38 = ( * V_30 + V_37 / 2 ) / V_37 ;
break;
case V_43 :
V_38 = * V_30 / V_37 ;
break;
case V_44 :
V_38 = ( * V_30 + V_37 - 1 ) / V_37 ;
break;
}
if ( V_38 < 0x10000 ) {
V_35 -> V_45 = V_39 ;
V_35 -> V_46 = V_38 ;
* V_30 = V_38 * V_39 ;
return 0 ;
}
}
return - V_47 ;
}
static int F_16 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_48 * V_49 )
{
const struct V_32 * V_33 = F_15 ( V_4 ) ;
int V_50 = 0 ;
unsigned int V_51 ;
V_50 |= F_17 ( & V_49 -> V_52 , V_53 ) ;
V_50 |= F_17 ( & V_49 -> V_54 , V_55 ) ;
V_50 |= F_17 ( & V_49 -> V_56 , V_57 ) ;
V_50 |= F_17 ( & V_49 -> V_58 , V_59 ) ;
V_50 |= F_17 ( & V_49 -> V_60 , V_59 | V_61 ) ;
if ( V_50 )
return 1 ;
V_50 |= F_18 ( V_49 -> V_60 ) ;
if ( V_50 )
return 2 ;
V_50 |= F_19 ( & V_49 -> V_62 , 0 ) ;
V_50 |= F_19 ( & V_49 -> V_63 , 0 ) ;
V_50 |= F_20 ( & V_49 -> V_64 ,
V_33 -> V_65 ) ;
V_50 |= F_19 ( & V_49 -> V_66 , V_49 -> V_67 ) ;
if ( V_49 -> V_60 == V_59 )
V_50 |= F_20 ( & V_49 -> V_68 , 1 ) ;
else
V_50 |= F_19 ( & V_49 -> V_68 , 0 ) ;
if ( V_50 )
return 3 ;
V_51 = V_49 -> V_64 ;
V_50 |= F_14 ( V_4 , & V_51 , V_49 -> V_31 ) ;
V_50 |= F_19 ( & V_49 -> V_64 , V_51 ) ;
if ( V_50 )
return 4 ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_34 * V_35 = V_4 -> V_36 ;
struct V_48 * V_49 = & V_6 -> V_11 -> V_49 ;
int V_27 ;
V_27 = F_7 ( V_4 , V_49 -> V_69 [ 0 ] ) ;
if ( V_27 )
return V_27 ;
F_3 ( V_35 -> V_45 , V_4 -> V_10 + 36 ) ;
F_3 ( V_35 -> V_46 , V_4 -> V_10 + 32 ) ;
F_3 ( 0x180000 , V_4 -> V_10 + 8 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
return 0 ;
}
static int F_23 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_23 * V_24 ,
unsigned long V_25 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_4 -> V_10 + 96 ) ;
if ( V_8 & 0x100 )
return 0 ;
return - V_21 ;
}
static int F_24 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_23 * V_24 ,
unsigned int * V_26 )
{
unsigned int V_17 = F_8 ( V_24 -> V_16 ) ;
unsigned int V_18 = F_9 ( V_24 -> V_16 ) ;
int V_27 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_24 -> V_29 ; V_28 ++ ) {
F_3 ( V_18 , V_4 -> V_10 + 96 ) ;
F_3 ( ( V_26 [ V_28 ] << 8 ) | V_17 , V_4 -> V_10 + 100 ) ;
V_27 = F_13 ( V_4 , V_6 , V_24 , F_23 , 0 ) ;
if ( V_27 )
return V_27 ;
}
return V_24 -> V_29 ;
}
static int F_25 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_23 * V_24 ,
unsigned int * V_26 )
{
V_26 [ 1 ] = F_26 ( V_4 -> V_70 + 32 ) & 0xf ;
return V_24 -> V_29 ;
}
static int F_27 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_23 * V_24 ,
unsigned int * V_26 )
{
V_6 -> V_71 = F_26 ( V_4 -> V_70 + 48 ) & 0xf ;
if ( F_28 ( V_6 , V_26 ) )
F_29 ( V_6 -> V_71 , V_4 -> V_70 + 48 ) ;
V_26 [ 1 ] = V_6 -> V_71 ;
return V_24 -> V_29 ;
}
static int F_30 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_23 * V_24 ,
unsigned int * V_26 )
{
unsigned int V_17 = F_8 ( V_24 -> V_16 ) ;
unsigned int V_72 = 0 ;
int V_27 ;
if ( V_26 [ 0 ] != V_73 ) {
if ( V_17 < 16 )
return - V_47 ;
V_72 = 0xff0000 ;
}
V_27 = F_31 ( V_4 , V_6 , V_24 , V_26 , V_72 ) ;
if ( V_27 )
return V_27 ;
F_29 ( ( V_6 -> V_74 >> 24 ) & 0xff , V_4 -> V_70 + 224 ) ;
return V_24 -> V_29 ;
}
static int F_32 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_23 * V_24 ,
unsigned int * V_26 )
{
unsigned int V_72 ;
unsigned int V_9 ;
V_72 = F_28 ( V_6 , V_26 ) ;
if ( V_72 ) {
if ( V_72 & 0xff )
F_29 ( V_6 -> V_71 & 0xff , V_4 -> V_70 + 80 ) ;
if ( V_72 & 0xff0000 )
F_29 ( ( V_6 -> V_71 >> 16 ) & 0xff , V_4 -> V_70 + 112 ) ;
}
V_9 = F_26 ( V_4 -> V_70 + 80 ) ;
V_9 |= ( F_26 ( V_4 -> V_70 + 64 ) << 8 ) ;
if ( V_6 -> V_74 & 0xff0000 )
V_9 |= ( F_26 ( V_4 -> V_70 + 112 ) << 16 ) ;
else
V_9 |= ( F_26 ( V_4 -> V_70 + 96 ) << 16 ) ;
V_26 [ 1 ] = V_9 ;
return V_24 -> V_29 ;
}
static int F_33 ( struct V_3 * V_4 )
{
unsigned int V_9 ;
int V_28 ;
F_34 ( V_4 -> V_1 ) ;
F_3 ( 0 , V_4 -> V_10 + 8 ) ;
V_9 = F_2 ( V_4 -> V_10 + 16 ) ;
F_3 ( V_9 , V_4 -> V_10 + 16 ) ;
F_2 ( V_4 -> V_10 + 20 ) ;
for ( V_28 = 0 ; V_28 < 16 ; V_28 ++ )
V_9 = F_2 ( V_4 -> V_10 + 28 ) ;
F_35 ( V_4 -> V_1 ) ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 ,
unsigned long V_25 )
{
struct V_75 * V_76 = F_37 ( V_4 ) ;
const struct V_32 * V_33 = NULL ;
struct V_34 * V_35 ;
struct V_5 * V_6 ;
int V_77 ;
int V_78 ;
int V_27 ;
if ( V_25 < F_38 ( V_79 ) )
V_33 = & V_79 [ V_25 ] ;
if ( ! V_33 )
return - V_80 ;
V_4 -> V_81 = V_33 ;
V_4 -> V_82 = V_33 -> V_83 ;
V_35 = F_39 ( V_4 , sizeof( * V_35 ) ) ;
if ( ! V_35 )
return - V_84 ;
V_27 = F_40 ( V_4 ) ;
if ( V_27 )
return V_27 ;
V_4 -> V_70 = F_41 ( V_76 , 2 ) ;
V_4 -> V_10 = F_42 ( V_76 , 3 ) ;
if ( V_76 -> V_1 > 0 ) {
V_27 = F_43 ( V_76 -> V_1 , F_1 ,
V_85 , V_4 -> V_82 , V_4 ) ;
if ( V_27 == 0 )
V_4 -> V_1 = V_76 -> V_1 ;
}
V_77 = ( V_33 -> V_86 ? 0 : 1 ) + V_33 -> V_87 +
V_33 -> V_88 + V_33 -> V_89 +
V_33 -> V_90 ;
V_27 = F_44 ( V_4 , V_77 ) ;
if ( V_27 )
return V_27 ;
V_78 = 0 ;
if ( V_33 -> V_86 ) {
V_6 = & V_4 -> V_91 [ V_78 ] ;
V_6 -> type = V_92 ;
V_6 -> V_93 = V_94 | V_33 -> V_95 ;
V_6 -> V_96 = V_33 -> V_86 ;
V_6 -> V_97 = V_33 -> V_98 ;
V_6 -> V_99 = & V_100 ;
V_6 -> V_101 = F_12 ;
if ( V_4 -> V_1 ) {
V_4 -> V_7 = V_6 ;
V_6 -> V_93 |= V_102 ;
V_6 -> V_103 = 1 ;
V_6 -> V_104 = F_16 ;
V_6 -> V_105 = F_21 ;
V_6 -> V_106 = F_22 ;
}
V_78 ++ ;
}
if ( V_33 -> V_87 ) {
V_6 = & V_4 -> V_91 [ V_78 ] ;
V_6 -> type = V_107 ;
V_6 -> V_93 = V_108 | V_109 | V_110 ;
V_6 -> V_96 = 4 ;
V_6 -> V_97 = 0x0fff ;
V_6 -> V_99 = & V_111 ;
V_6 -> V_112 = F_24 ;
V_78 ++ ;
}
if ( V_33 -> V_88 ) {
V_6 = & V_4 -> V_91 [ V_78 ] ;
V_6 -> type = V_113 ;
V_6 -> V_93 = V_94 ;
V_6 -> V_96 = 4 ;
V_6 -> V_97 = 1 ;
V_6 -> V_99 = & V_114 ;
V_6 -> V_115 = F_25 ;
V_78 ++ ;
}
if ( V_33 -> V_89 ) {
V_6 = & V_4 -> V_91 [ V_78 ] ;
V_6 -> type = V_116 ;
V_6 -> V_93 = V_108 ;
V_6 -> V_96 = 4 ;
V_6 -> V_97 = 1 ;
V_6 -> V_99 = & V_114 ;
V_6 -> V_115 = F_27 ;
V_78 ++ ;
}
if ( V_33 -> V_90 ) {
V_6 = & V_4 -> V_91 [ V_78 ] ;
V_6 -> type = V_117 ;
V_6 -> V_93 = V_94 | V_108 ;
V_6 -> V_96 = 24 ;
V_6 -> V_97 = 1 ;
V_6 -> V_74 = 0xff ;
V_6 -> V_99 = & V_114 ;
V_6 -> V_118 = F_30 ;
V_6 -> V_115 = F_32 ;
V_78 ++ ;
}
F_33 ( V_4 ) ;
return 0 ;
}
static void F_45 ( struct V_3 * V_4 )
{
struct V_34 * V_35 = V_4 -> V_36 ;
if ( V_35 ) {
if ( V_4 -> V_70 )
F_33 ( V_4 ) ;
if ( V_4 -> V_1 )
F_46 ( V_4 -> V_1 , V_4 ) ;
if ( V_4 -> V_10 )
F_47 ( V_4 -> V_10 ) ;
}
F_48 ( V_4 ) ;
}
static int F_49 ( struct V_75 * V_4 ,
const struct V_119 * V_120 )
{
return F_50 ( V_4 , & V_121 , V_120 -> V_122 ) ;
}
