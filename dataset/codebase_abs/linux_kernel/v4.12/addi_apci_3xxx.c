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
F_4 ( V_6 , & V_9 , 1 ) ;
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
const struct V_32 * V_33 = V_4 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
unsigned int V_38 ;
unsigned int V_39 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
if ( ! ( V_33 -> V_41 & ( 1 << V_40 ) ) )
continue;
switch ( V_40 ) {
case 0 :
V_38 = 1 ;
break;
case 1 :
V_38 = 1000 ;
break;
case 2 :
V_38 = 1000000 ;
break;
}
switch ( V_31 & V_42 ) {
case V_43 :
default:
V_39 = F_15 ( * V_30 , V_38 ) ;
break;
case V_44 :
V_39 = * V_30 / V_38 ;
break;
case V_45 :
V_39 = F_16 ( * V_30 , V_38 ) ;
break;
}
if ( V_39 < 0x10000 ) {
V_36 -> V_46 = V_40 ;
V_36 -> V_47 = V_39 ;
* V_30 = V_39 * V_40 ;
return 0 ;
}
}
return - V_48 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_49 * V_50 )
{
const struct V_32 * V_33 = V_4 -> V_34 ;
int V_51 = 0 ;
unsigned int V_52 ;
V_51 |= F_18 ( & V_50 -> V_53 , V_54 ) ;
V_51 |= F_18 ( & V_50 -> V_55 , V_56 ) ;
V_51 |= F_18 ( & V_50 -> V_57 , V_58 ) ;
V_51 |= F_18 ( & V_50 -> V_59 , V_60 ) ;
V_51 |= F_18 ( & V_50 -> V_61 , V_60 | V_62 ) ;
if ( V_51 )
return 1 ;
V_51 |= F_19 ( V_50 -> V_61 ) ;
if ( V_51 )
return 2 ;
V_51 |= F_20 ( & V_50 -> V_63 , 0 ) ;
V_51 |= F_20 ( & V_50 -> V_64 , 0 ) ;
V_51 |= F_21 ( & V_50 -> V_65 ,
V_33 -> V_66 ) ;
V_51 |= F_20 ( & V_50 -> V_67 ,
V_50 -> V_68 ) ;
if ( V_50 -> V_61 == V_60 )
V_51 |= F_21 ( & V_50 -> V_69 , 1 ) ;
else
V_51 |= F_20 ( & V_50 -> V_69 , 0 ) ;
if ( V_51 )
return 3 ;
V_52 = V_50 -> V_65 ;
V_51 |= F_14 ( V_4 , & V_52 , V_50 -> V_31 ) ;
V_51 |= F_20 ( & V_50 -> V_65 , V_52 ) ;
if ( V_51 )
return 4 ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_49 * V_50 = & V_6 -> V_11 -> V_50 ;
int V_27 ;
V_27 = F_7 ( V_4 , V_50 -> V_70 [ 0 ] ) ;
if ( V_27 )
return V_27 ;
F_3 ( V_36 -> V_46 , V_4 -> V_10 + 36 ) ;
F_3 ( V_36 -> V_47 , V_4 -> V_10 + 32 ) ;
F_3 ( 0x180000 , V_4 -> V_10 + 8 ) ;
return 0 ;
}
static int F_23 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
return 0 ;
}
static int F_24 ( struct V_3 * V_4 ,
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
static int F_25 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_23 * V_24 ,
unsigned int * V_26 )
{
unsigned int V_17 = F_8 ( V_24 -> V_16 ) ;
unsigned int V_18 = F_9 ( V_24 -> V_16 ) ;
int V_27 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_24 -> V_29 ; V_28 ++ ) {
unsigned int V_9 = V_26 [ V_28 ] ;
F_3 ( V_18 , V_4 -> V_10 + 96 ) ;
F_3 ( ( V_9 << 8 ) | V_17 , V_4 -> V_10 + 100 ) ;
V_27 = F_13 ( V_4 , V_6 , V_24 , F_24 , 0 ) ;
if ( V_27 )
return V_27 ;
V_6 -> V_71 [ V_17 ] = V_9 ;
}
return V_24 -> V_29 ;
}
static int F_26 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_23 * V_24 ,
unsigned int * V_26 )
{
V_26 [ 1 ] = F_27 ( V_4 -> V_72 + 32 ) & 0xf ;
return V_24 -> V_29 ;
}
static int F_28 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_23 * V_24 ,
unsigned int * V_26 )
{
V_6 -> V_73 = F_27 ( V_4 -> V_72 + 48 ) & 0xf ;
if ( F_29 ( V_6 , V_26 ) )
F_30 ( V_6 -> V_73 , V_4 -> V_72 + 48 ) ;
V_26 [ 1 ] = V_6 -> V_73 ;
return V_24 -> V_29 ;
}
static int F_31 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_23 * V_24 ,
unsigned int * V_26 )
{
unsigned int V_17 = F_8 ( V_24 -> V_16 ) ;
unsigned int V_74 = 0 ;
int V_27 ;
if ( V_26 [ 0 ] != V_75 ) {
if ( V_17 < 16 )
return - V_48 ;
V_74 = 0xff0000 ;
}
V_27 = F_32 ( V_4 , V_6 , V_24 , V_26 , V_74 ) ;
if ( V_27 )
return V_27 ;
F_30 ( ( V_6 -> V_76 >> 24 ) & 0xff , V_4 -> V_72 + 224 ) ;
return V_24 -> V_29 ;
}
static int F_33 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_23 * V_24 ,
unsigned int * V_26 )
{
unsigned int V_74 ;
unsigned int V_9 ;
V_74 = F_29 ( V_6 , V_26 ) ;
if ( V_74 ) {
if ( V_74 & 0xff )
F_30 ( V_6 -> V_73 & 0xff , V_4 -> V_72 + 80 ) ;
if ( V_74 & 0xff0000 )
F_30 ( ( V_6 -> V_73 >> 16 ) & 0xff , V_4 -> V_72 + 112 ) ;
}
V_9 = F_27 ( V_4 -> V_72 + 80 ) ;
V_9 |= ( F_27 ( V_4 -> V_72 + 64 ) << 8 ) ;
if ( V_6 -> V_76 & 0xff0000 )
V_9 |= ( F_27 ( V_4 -> V_72 + 112 ) << 16 ) ;
else
V_9 |= ( F_27 ( V_4 -> V_72 + 96 ) << 16 ) ;
V_26 [ 1 ] = V_9 ;
return V_24 -> V_29 ;
}
static int F_34 ( struct V_3 * V_4 )
{
unsigned int V_9 ;
int V_28 ;
F_35 ( V_4 -> V_1 ) ;
F_3 ( 0 , V_4 -> V_10 + 8 ) ;
V_9 = F_2 ( V_4 -> V_10 + 16 ) ;
F_3 ( V_9 , V_4 -> V_10 + 16 ) ;
F_2 ( V_4 -> V_10 + 20 ) ;
for ( V_28 = 0 ; V_28 < 16 ; V_28 ++ )
V_9 = F_2 ( V_4 -> V_10 + 28 ) ;
F_36 ( V_4 -> V_1 ) ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
unsigned long V_25 )
{
struct V_77 * V_78 = F_38 ( V_4 ) ;
const struct V_32 * V_33 = NULL ;
struct V_35 * V_36 ;
struct V_5 * V_6 ;
int V_79 ;
int V_80 ;
int V_27 ;
if ( V_25 < F_39 ( V_81 ) )
V_33 = & V_81 [ V_25 ] ;
if ( ! V_33 )
return - V_82 ;
V_4 -> V_34 = V_33 ;
V_4 -> V_83 = V_33 -> V_84 ;
V_36 = F_40 ( V_4 , sizeof( * V_36 ) ) ;
if ( ! V_36 )
return - V_85 ;
V_27 = F_41 ( V_4 ) ;
if ( V_27 )
return V_27 ;
V_4 -> V_72 = F_42 ( V_78 , 2 ) ;
V_4 -> V_10 = F_43 ( V_78 , 3 ) ;
if ( ! V_4 -> V_10 )
return - V_85 ;
if ( V_78 -> V_1 > 0 ) {
V_27 = F_44 ( V_78 -> V_1 , F_1 ,
V_86 , V_4 -> V_83 , V_4 ) ;
if ( V_27 == 0 )
V_4 -> V_1 = V_78 -> V_1 ;
}
V_79 = ( V_33 -> V_87 ? 0 : 1 ) + V_33 -> V_88 +
V_33 -> V_89 + V_33 -> V_90 +
V_33 -> V_91 ;
V_27 = F_45 ( V_4 , V_79 ) ;
if ( V_27 )
return V_27 ;
V_80 = 0 ;
if ( V_33 -> V_87 ) {
V_6 = & V_4 -> V_92 [ V_80 ] ;
V_6 -> type = V_93 ;
V_6 -> V_94 = V_95 | V_33 -> V_96 ;
V_6 -> V_97 = V_33 -> V_87 ;
V_6 -> V_98 = V_33 -> V_99 ;
V_6 -> V_100 = & V_101 ;
V_6 -> V_102 = F_12 ;
if ( V_4 -> V_1 ) {
V_4 -> V_7 = V_6 ;
V_6 -> V_94 |= V_103 ;
V_6 -> V_104 = 1 ;
V_6 -> V_105 = F_17 ;
V_6 -> V_106 = F_22 ;
V_6 -> V_107 = F_23 ;
}
V_80 ++ ;
}
if ( V_33 -> V_88 ) {
V_6 = & V_4 -> V_92 [ V_80 ] ;
V_6 -> type = V_108 ;
V_6 -> V_94 = V_109 | V_110 | V_111 ;
V_6 -> V_97 = 4 ;
V_6 -> V_98 = 0x0fff ;
V_6 -> V_100 = & V_112 ;
V_6 -> V_113 = F_25 ;
V_27 = F_46 ( V_6 ) ;
if ( V_27 )
return V_27 ;
V_80 ++ ;
}
if ( V_33 -> V_89 ) {
V_6 = & V_4 -> V_92 [ V_80 ] ;
V_6 -> type = V_114 ;
V_6 -> V_94 = V_95 ;
V_6 -> V_97 = 4 ;
V_6 -> V_98 = 1 ;
V_6 -> V_100 = & V_115 ;
V_6 -> V_116 = F_26 ;
V_80 ++ ;
}
if ( V_33 -> V_90 ) {
V_6 = & V_4 -> V_92 [ V_80 ] ;
V_6 -> type = V_117 ;
V_6 -> V_94 = V_109 ;
V_6 -> V_97 = 4 ;
V_6 -> V_98 = 1 ;
V_6 -> V_100 = & V_115 ;
V_6 -> V_116 = F_28 ;
V_80 ++ ;
}
if ( V_33 -> V_91 ) {
V_6 = & V_4 -> V_92 [ V_80 ] ;
V_6 -> type = V_118 ;
V_6 -> V_94 = V_95 | V_109 ;
V_6 -> V_97 = 24 ;
V_6 -> V_98 = 1 ;
V_6 -> V_76 = 0xff ;
V_6 -> V_100 = & V_115 ;
V_6 -> V_119 = F_31 ;
V_6 -> V_116 = F_33 ;
V_80 ++ ;
}
F_34 ( V_4 ) ;
return 0 ;
}
static void F_47 ( struct V_3 * V_4 )
{
if ( V_4 -> V_72 )
F_34 ( V_4 ) ;
F_48 ( V_4 ) ;
}
static int F_49 ( struct V_77 * V_4 ,
const struct V_120 * V_121 )
{
return F_50 ( V_4 , & V_122 , V_121 -> V_123 ) ;
}
