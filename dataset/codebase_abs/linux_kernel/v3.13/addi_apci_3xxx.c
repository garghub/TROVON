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
unsigned int * V_28 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_12 ;
int V_29 ;
int V_30 ;
V_29 = F_7 ( V_4 , V_27 -> V_19 ) ;
if ( V_29 )
return V_29 ;
for ( V_30 = 0 ; V_30 < V_27 -> V_31 ; V_30 ++ ) {
F_3 ( 0x80000 , V_6 -> V_13 + 8 ) ;
do {
V_12 = F_2 ( V_6 -> V_13 + 20 ) ;
V_12 &= 0x1 ;
} while ( ! V_12 );
V_28 [ V_30 ] = F_2 ( V_6 -> V_13 + 28 ) ;
}
return V_27 -> V_31 ;
}
static int F_12 ( struct V_3 * V_4 ,
unsigned int * V_32 , int V_33 )
{
const struct V_34 * V_35 = F_13 ( V_4 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_36 ;
unsigned int V_37 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ ) {
if ( ! ( V_35 -> V_39 & ( 1 << V_38 ) ) )
continue;
switch ( V_38 ) {
case 0 :
V_36 = 1 ;
break;
case 1 :
V_36 = 1000 ;
break;
case 2 :
V_36 = 1000000 ;
break;
}
switch ( V_33 ) {
case V_40 :
default:
V_37 = ( * V_32 + V_36 / 2 ) / V_36 ;
break;
case V_41 :
V_37 = * V_32 / V_36 ;
break;
case V_42 :
V_37 = ( * V_32 + V_36 - 1 ) / V_36 ;
break;
}
if ( V_37 < 0x10000 ) {
V_6 -> V_43 = V_38 ;
V_6 -> V_44 = V_37 ;
* V_32 = V_37 * V_38 ;
return 0 ;
}
}
return - V_45 ;
}
static int F_14 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_46 * V_47 )
{
const struct V_34 * V_35 = F_13 ( V_4 ) ;
int V_48 = 0 ;
unsigned int V_49 ;
V_48 |= F_15 ( & V_47 -> V_50 , V_51 ) ;
V_48 |= F_15 ( & V_47 -> V_52 , V_53 ) ;
V_48 |= F_15 ( & V_47 -> V_54 , V_55 ) ;
V_48 |= F_15 ( & V_47 -> V_56 , V_57 ) ;
V_48 |= F_15 ( & V_47 -> V_58 , V_57 | V_59 ) ;
if ( V_48 )
return 1 ;
V_48 |= F_16 ( V_47 -> V_58 ) ;
if ( V_48 )
return 2 ;
V_48 |= F_17 ( & V_47 -> V_60 , 0 ) ;
V_48 |= F_17 ( & V_47 -> V_61 , 0 ) ;
V_48 |= F_18 ( & V_47 -> V_62 ,
V_35 -> V_63 ) ;
V_48 |= F_17 ( & V_47 -> V_64 , V_47 -> V_65 ) ;
if ( V_47 -> V_58 == V_57 )
V_48 |= F_18 ( & V_47 -> V_66 , 1 ) ;
else
V_48 |= F_17 ( & V_47 -> V_66 , 0 ) ;
if ( V_48 )
return 3 ;
if ( V_47 -> V_65 > 1 ) {
V_47 -> V_65 = 1 ;
V_48 |= - V_45 ;
}
V_49 = V_47 -> V_62 ;
V_48 |= F_12 ( V_4 , & V_47 -> V_62 ,
V_47 -> V_67 & V_68 ) ;
if ( V_49 != V_47 -> V_62 )
V_48 |= - V_45 ;
if ( V_48 )
return 4 ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_46 * V_47 = & V_9 -> V_14 -> V_47 ;
int V_29 ;
V_29 = F_7 ( V_4 , V_47 -> V_69 [ 0 ] ) ;
if ( V_29 )
return V_29 ;
F_3 ( V_6 -> V_43 , V_6 -> V_13 + 36 ) ;
F_3 ( V_6 -> V_44 , V_6 -> V_13 + 32 ) ;
F_3 ( 0x180000 , V_6 -> V_13 + 8 ) ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
return 0 ;
}
static int F_21 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_26 * V_27 ,
unsigned int * V_28 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_20 = F_8 ( V_27 -> V_19 ) ;
unsigned int V_21 = F_9 ( V_27 -> V_19 ) ;
unsigned int V_11 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_27 -> V_31 ; V_30 ++ ) {
F_3 ( V_21 , V_6 -> V_13 + 96 ) ;
F_3 ( ( V_28 [ V_30 ] << 8 ) | V_20 , V_6 -> V_13 + 100 ) ;
do {
V_11 = F_2 ( V_6 -> V_13 + 96 ) ;
} while ( ( V_11 & 0x100 ) != 0x100 );
}
return V_27 -> V_31 ;
}
static int F_22 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_26 * V_27 ,
unsigned int * V_28 )
{
V_28 [ 1 ] = F_23 ( V_4 -> V_70 + 32 ) & 0xf ;
return V_27 -> V_31 ;
}
static int F_24 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_26 * V_27 ,
unsigned int * V_28 )
{
V_9 -> V_71 = F_23 ( V_4 -> V_70 + 48 ) & 0xf ;
if ( F_25 ( V_9 , V_28 ) )
F_26 ( V_9 -> V_71 , V_4 -> V_70 + 48 ) ;
V_28 [ 1 ] = V_9 -> V_71 ;
return V_27 -> V_31 ;
}
static int F_27 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_26 * V_27 ,
unsigned int * V_28 )
{
unsigned int V_20 = F_8 ( V_27 -> V_19 ) ;
unsigned int V_72 ;
int V_29 ;
if ( V_20 < 16 ) {
if ( V_28 [ 0 ] != V_73 )
return - V_45 ;
} else {
V_72 = 0xff0000 ;
}
V_29 = F_28 ( V_4 , V_9 , V_27 , V_28 , V_72 ) ;
if ( V_29 )
return V_29 ;
F_26 ( ( V_9 -> V_74 >> 24 ) & 0xff , V_4 -> V_70 + 224 ) ;
return V_27 -> V_31 ;
}
static int F_29 ( struct V_3 * V_4 ,
struct V_8 * V_9 ,
struct V_26 * V_27 ,
unsigned int * V_28 )
{
unsigned int V_72 ;
unsigned int V_12 ;
V_72 = F_25 ( V_9 , V_28 ) ;
if ( V_72 ) {
if ( V_72 & 0xff )
F_26 ( V_9 -> V_71 & 0xff , V_4 -> V_70 + 80 ) ;
if ( V_72 & 0xff0000 )
F_26 ( ( V_9 -> V_71 >> 16 ) & 0xff , V_4 -> V_70 + 112 ) ;
}
V_12 = F_23 ( V_4 -> V_70 + 80 ) ;
V_12 |= ( F_23 ( V_4 -> V_70 + 64 ) << 8 ) ;
if ( V_9 -> V_74 & 0xff0000 )
V_12 |= ( F_23 ( V_4 -> V_70 + 112 ) << 16 ) ;
else
V_12 |= ( F_23 ( V_4 -> V_70 + 96 ) << 16 ) ;
V_28 [ 1 ] = V_12 ;
return V_27 -> V_31 ;
}
static int F_30 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
unsigned int V_12 ;
int V_30 ;
F_31 ( V_4 -> V_1 ) ;
F_3 ( 0 , V_6 -> V_13 + 8 ) ;
V_12 = F_2 ( V_6 -> V_13 + 16 ) ;
F_3 ( V_12 , V_6 -> V_13 + 16 ) ;
F_2 ( V_6 -> V_13 + 20 ) ;
for ( V_30 = 0 ; V_30 < 16 ; V_30 ++ )
V_12 = F_2 ( V_6 -> V_13 + 28 ) ;
F_32 ( V_4 -> V_1 ) ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 ,
unsigned long V_75 )
{
struct V_76 * V_77 = F_34 ( V_4 ) ;
const struct V_34 * V_35 = NULL ;
struct V_5 * V_6 ;
struct V_8 * V_9 ;
int V_78 ;
int V_79 ;
int V_29 ;
if ( V_75 < F_35 ( V_80 ) )
V_35 = & V_80 [ V_75 ] ;
if ( ! V_35 )
return - V_81 ;
V_4 -> V_82 = V_35 ;
V_4 -> V_83 = V_35 -> V_84 ;
V_6 = F_36 ( V_4 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_85 ;
V_29 = F_37 ( V_4 ) ;
if ( V_29 )
return V_29 ;
V_4 -> V_70 = F_38 ( V_77 , 2 ) ;
V_6 -> V_13 = F_39 ( V_77 , 3 ) ;
if ( V_77 -> V_1 > 0 ) {
V_29 = F_40 ( V_77 -> V_1 , F_1 ,
V_86 , V_4 -> V_83 , V_4 ) ;
if ( V_29 == 0 )
V_4 -> V_1 = V_77 -> V_1 ;
}
V_78 = ( V_35 -> V_87 ? 0 : 1 ) + V_35 -> V_88 +
V_35 -> V_89 + V_35 -> V_90 +
V_35 -> V_91 ;
V_29 = F_41 ( V_4 , V_78 ) ;
if ( V_29 )
return V_29 ;
V_79 = 0 ;
if ( V_35 -> V_87 ) {
V_9 = & V_4 -> V_92 [ V_79 ] ;
V_9 -> type = V_93 ;
V_9 -> V_94 = V_95 | V_35 -> V_96 ;
V_9 -> V_97 = V_35 -> V_87 ;
V_9 -> V_98 = V_35 -> V_99 ;
V_9 -> V_100 = V_9 -> V_97 ;
V_9 -> V_101 = & V_102 ;
V_9 -> V_103 = F_11 ;
if ( V_4 -> V_1 ) {
V_4 -> V_10 = V_9 ;
V_9 -> V_94 |= V_104 ;
V_9 -> V_105 = F_14 ;
V_9 -> V_106 = F_19 ;
V_9 -> V_107 = F_20 ;
}
V_79 ++ ;
}
if ( V_35 -> V_88 ) {
V_9 = & V_4 -> V_92 [ V_79 ] ;
V_9 -> type = V_108 ;
V_9 -> V_94 = V_109 | V_110 | V_111 ;
V_9 -> V_97 = 4 ;
V_9 -> V_98 = 0x0fff ;
V_9 -> V_101 = & V_112 ;
V_9 -> V_113 = F_21 ;
V_79 ++ ;
}
if ( V_35 -> V_89 ) {
V_9 = & V_4 -> V_92 [ V_79 ] ;
V_9 -> type = V_114 ;
V_9 -> V_94 = V_95 ;
V_9 -> V_97 = 4 ;
V_9 -> V_98 = 1 ;
V_9 -> V_101 = & V_115 ;
V_9 -> V_116 = F_22 ;
V_79 ++ ;
}
if ( V_35 -> V_90 ) {
V_9 = & V_4 -> V_92 [ V_79 ] ;
V_9 -> type = V_117 ;
V_9 -> V_94 = V_109 ;
V_9 -> V_97 = 4 ;
V_9 -> V_98 = 1 ;
V_9 -> V_101 = & V_115 ;
V_9 -> V_116 = F_24 ;
V_79 ++ ;
}
if ( V_35 -> V_91 ) {
V_9 = & V_4 -> V_92 [ V_79 ] ;
V_9 -> type = V_118 ;
V_9 -> V_94 = V_95 | V_109 ;
V_9 -> V_97 = 24 ;
V_9 -> V_98 = 1 ;
V_9 -> V_74 = 0xff ;
V_9 -> V_101 = & V_115 ;
V_9 -> V_119 = F_27 ;
V_9 -> V_116 = F_29 ;
V_79 ++ ;
}
F_30 ( V_4 ) ;
return 0 ;
}
static void F_42 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
if ( V_6 ) {
if ( V_4 -> V_70 )
F_30 ( V_4 ) ;
if ( V_4 -> V_1 )
F_43 ( V_4 -> V_1 , V_4 ) ;
if ( V_6 -> V_13 )
F_44 ( V_6 -> V_13 ) ;
}
F_45 ( V_4 ) ;
}
static int F_46 ( struct V_76 * V_4 ,
const struct V_120 * V_121 )
{
return F_47 ( V_4 , & V_122 , V_121 -> V_123 ) ;
}
