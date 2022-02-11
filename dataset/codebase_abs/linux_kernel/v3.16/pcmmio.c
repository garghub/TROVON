static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_9 = V_2 -> V_9 ;
unsigned long V_10 ;
F_2 ( & V_7 -> V_11 , V_10 ) ;
if ( V_4 == 0 ) {
F_3 ( V_3 & 0xff , V_9 + F_4 ( V_5 + 0 ) ) ;
F_3 ( ( V_3 >> 8 ) & 0xff , V_9 + F_4 ( V_5 + 1 ) ) ;
F_3 ( ( V_3 >> 16 ) & 0xff , V_9 + F_4 ( V_5 + 2 ) ) ;
} else {
F_3 ( F_5 ( V_4 ) , V_9 + V_12 ) ;
F_3 ( V_3 & 0xff , V_9 + F_6 ( 0 ) ) ;
F_3 ( ( V_3 >> 8 ) & 0xff , V_9 + F_6 ( 1 ) ) ;
F_3 ( ( V_3 >> 16 ) & 0xff , V_9 + F_6 ( 2 ) ) ;
}
F_7 ( & V_7 -> V_11 , V_10 ) ;
}
static unsigned int F_8 ( struct V_1 * V_2 ,
int V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_9 = V_2 -> V_9 ;
unsigned long V_10 ;
unsigned int V_3 ;
F_2 ( & V_7 -> V_11 , V_10 ) ;
if ( V_4 == 0 ) {
V_3 = F_9 ( V_9 + F_4 ( V_5 + 0 ) ) ;
V_3 |= ( F_9 ( V_9 + F_4 ( V_5 + 1 ) ) << 8 ) ;
V_3 |= ( F_9 ( V_9 + F_4 ( V_5 + 2 ) ) << 16 ) ;
} else {
F_3 ( F_5 ( V_4 ) , V_9 + V_12 ) ;
V_3 = F_9 ( V_9 + F_6 ( 0 ) ) ;
V_3 |= ( F_9 ( V_9 + F_6 ( 1 ) ) << 8 ) ;
V_3 |= ( F_9 ( V_9 + F_6 ( 2 ) ) << 16 ) ;
}
F_7 ( & V_7 -> V_11 , V_10 ) ;
return V_3 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
int V_5 = V_14 -> V_18 == 2 ? 0 : 3 ;
unsigned int V_19 = ( 1 << V_14 -> V_20 ) - 1 ;
unsigned int V_21 ;
unsigned int V_3 ;
V_21 = F_11 ( V_14 , V_17 ) ;
if ( V_21 ) {
V_3 = ~ V_14 -> V_22 & V_19 ;
V_3 &= V_14 -> V_23 ;
F_1 ( V_2 , V_3 , 0 , V_5 ) ;
}
V_3 = F_8 ( V_2 , 0 , V_5 ) ;
V_17 [ 1 ] = ~ V_3 & V_19 ;
return V_16 -> V_24 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
int V_5 = V_14 -> V_18 == 2 ? 0 : 3 ;
int V_25 ;
V_25 = F_13 ( V_2 , V_14 , V_16 , V_17 , 0 ) ;
if ( V_25 )
return V_25 ;
if ( V_17 [ 0 ] == V_26 )
F_1 ( V_2 , V_14 -> V_23 , 0 , V_5 ) ;
return V_16 -> V_24 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 , 0 , 0 ) ;
F_1 ( V_2 , 0 , 0 , 3 ) ;
F_1 ( V_2 , 0 , V_27 , 0 ) ;
F_1 ( V_2 , 0 , V_28 , 0 ) ;
F_1 ( V_2 , 0 , V_29 , 0 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
V_7 -> V_30 = 0 ;
V_7 -> V_31 = 0 ;
V_14 -> V_32 -> V_33 = NULL ;
F_1 ( V_2 , 0 , V_28 , 0 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
unsigned int V_34 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_35 * V_36 = & V_14 -> V_32 -> V_36 ;
unsigned int V_37 = V_14 -> V_32 -> V_38 ;
unsigned int V_3 = 0 ;
unsigned long V_10 ;
int V_39 ;
F_2 ( & V_7 -> V_40 , V_10 ) ;
if ( ! V_7 -> V_31 )
goto V_41;
if ( ! ( V_34 & V_7 -> V_30 ) )
goto V_41;
for ( V_39 = 0 ; V_39 < V_36 -> V_42 ; V_39 ++ ) {
unsigned int V_43 = F_17 ( V_36 -> V_44 [ V_39 ] ) ;
if ( V_34 & ( 1 << V_43 ) )
V_3 |= ( 1 << V_39 ) ;
}
if ( F_18 ( V_14 , V_3 ) &&
F_18 ( V_14 , V_3 >> 16 ) ) {
V_14 -> V_32 -> V_38 |= ( V_45 | V_46 ) ;
} else {
F_15 ( V_2 , V_14 ) ;
}
if ( V_36 -> V_47 == V_48 && V_7 -> V_49 > 0 ) {
V_7 -> V_49 -- ;
if ( V_7 -> V_49 == 0 ) {
V_14 -> V_32 -> V_38 |= V_50 ;
F_15 ( V_2 , V_14 ) ;
}
}
V_41:
F_7 ( & V_7 -> V_40 , V_10 ) ;
if ( V_37 != V_14 -> V_32 -> V_38 )
F_19 ( V_2 , V_14 ) ;
}
static T_1 F_20 ( int V_51 , void * V_52 )
{
struct V_1 * V_2 = V_52 ;
struct V_13 * V_14 = V_2 -> V_53 ;
unsigned int V_34 ;
unsigned char V_54 ;
V_54 = F_9 ( V_2 -> V_9 + V_55 ) & 0x07 ;
if ( ! V_54 )
return V_56 ;
V_34 = F_8 ( V_2 , V_29 , 0 ) ;
F_1 ( V_2 , 0 , V_29 , 0 ) ;
F_16 ( V_2 , V_14 , V_34 ) ;
return V_57 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_35 * V_36 = & V_14 -> V_32 -> V_36 ;
unsigned int V_58 = 0 ;
unsigned int V_59 = 0 ;
int V_39 ;
if ( V_36 -> V_47 == V_48 && V_7 -> V_49 == 0 ) {
V_14 -> V_32 -> V_38 |= V_50 ;
V_7 -> V_31 = 0 ;
return 1 ;
}
V_7 -> V_30 = 0 ;
V_7 -> V_31 = 1 ;
if ( V_36 -> V_44 ) {
for ( V_39 = 0 ; V_39 < V_36 -> V_42 ; V_39 ++ ) {
unsigned int V_60 = V_36 -> V_44 [ V_39 ] ;
unsigned int V_43 = F_17 ( V_60 ) ;
unsigned int V_61 = F_22 ( V_60 ) ;
unsigned int V_62 = F_23 ( V_60 ) ;
V_58 |= ( 1 << V_43 ) ;
V_59 |= ( ( ( V_62 || V_61 ) ? 1 : 0 ) << V_43 ) ;
}
}
V_58 &= ( ( 1 << V_14 -> V_20 ) - 1 ) ;
V_7 -> V_30 = V_58 ;
F_1 ( V_2 , V_59 , V_27 , 0 ) ;
F_1 ( V_2 , V_58 , V_28 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_10 ;
F_2 ( & V_7 -> V_40 , V_10 ) ;
if ( V_7 -> V_31 )
F_15 ( V_2 , V_14 ) ;
F_7 ( & V_7 -> V_40 , V_10 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
unsigned int V_63 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_35 * V_36 = & V_14 -> V_32 -> V_36 ;
unsigned long V_10 ;
int V_64 = 0 ;
if ( V_63 != V_36 -> V_65 )
return - V_66 ;
F_2 ( & V_7 -> V_40 , V_10 ) ;
V_14 -> V_32 -> V_33 = NULL ;
if ( V_7 -> V_31 )
V_64 = F_21 ( V_2 , V_14 ) ;
F_7 ( & V_7 -> V_40 , V_10 ) ;
if ( V_64 )
F_19 ( V_2 , V_14 ) ;
return 1 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_35 * V_36 = & V_14 -> V_32 -> V_36 ;
unsigned long V_10 ;
int V_64 = 0 ;
F_2 ( & V_7 -> V_40 , V_10 ) ;
V_7 -> V_31 = 1 ;
if ( V_36 -> V_47 == V_48 )
V_7 -> V_49 = V_36 -> V_67 ;
else
V_7 -> V_49 = 0 ;
if ( V_36 -> V_68 == V_69 )
V_14 -> V_32 -> V_33 = F_25 ;
else
V_64 = F_21 ( V_2 , V_14 ) ;
F_7 ( & V_7 -> V_40 , V_10 ) ;
if ( V_64 )
F_19 ( V_2 , V_14 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_35 * V_36 )
{
int V_70 = 0 ;
V_70 |= F_28 ( & V_36 -> V_68 , V_71 | V_69 ) ;
V_70 |= F_28 ( & V_36 -> V_72 , V_73 ) ;
V_70 |= F_28 ( & V_36 -> V_74 , V_71 ) ;
V_70 |= F_28 ( & V_36 -> V_75 , V_48 ) ;
V_70 |= F_28 ( & V_36 -> V_47 , V_48 | V_76 ) ;
if ( V_70 )
return 1 ;
V_70 |= F_29 ( V_36 -> V_68 ) ;
V_70 |= F_29 ( V_36 -> V_47 ) ;
if ( V_70 )
return 2 ;
V_70 |= F_30 ( & V_36 -> V_65 , 0 ) ;
V_70 |= F_30 ( & V_36 -> V_77 , 0 ) ;
V_70 |= F_30 ( & V_36 -> V_78 , 0 ) ;
V_70 |= F_30 ( & V_36 -> V_79 , V_36 -> V_42 ) ;
switch ( V_36 -> V_47 ) {
case V_48 :
break;
case V_76 :
V_70 |= F_30 ( & V_36 -> V_67 , 0 ) ;
break;
default:
break;
}
if ( V_70 )
return 3 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned long V_80 )
{
unsigned char V_81 ;
V_81 = F_9 ( V_2 -> V_9 + V_82 ) ;
if ( V_81 & V_83 )
return 0 ;
return - V_84 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
unsigned long V_9 = V_2 -> V_9 ;
unsigned int V_43 = F_17 ( V_16 -> V_60 ) ;
unsigned int V_61 = F_22 ( V_16 -> V_60 ) ;
unsigned int V_62 = F_23 ( V_16 -> V_60 ) ;
unsigned char V_36 = 0 ;
unsigned int V_3 ;
int V_25 ;
int V_39 ;
if ( V_43 > 7 ) {
V_43 -= 8 ;
V_9 += V_85 ;
}
if ( V_62 == V_86 )
V_36 |= V_87 ;
if ( V_43 % 2 )
V_36 |= V_88 ;
V_36 |= F_33 ( V_43 / 2 ) ;
V_36 |= F_34 ( V_61 ) ;
F_3 ( V_36 , V_9 + V_89 ) ;
V_25 = F_35 ( V_2 , V_14 , V_16 , F_31 , 0 ) ;
if ( V_25 )
return V_25 ;
V_3 = F_9 ( V_9 + V_90 ) ;
V_3 |= F_9 ( V_9 + V_91 ) << 8 ;
for ( V_39 = 0 ; V_39 < V_16 -> V_24 ; V_39 ++ ) {
F_3 ( V_36 , V_9 + V_89 ) ;
V_25 = F_35 ( V_2 , V_14 , V_16 , F_31 , 0 ) ;
if ( V_25 )
return V_25 ;
V_3 = F_9 ( V_9 + V_90 ) ;
V_3 |= F_9 ( V_9 + V_91 ) << 8 ;
if ( F_36 ( V_14 , V_61 ) )
V_3 = F_37 ( V_14 , V_3 ) ;
V_17 [ V_39 ] = V_3 ;
}
return V_16 -> V_24 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_43 = F_17 ( V_16 -> V_60 ) ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_16 -> V_24 ; V_39 ++ )
V_17 [ V_39 ] = V_7 -> V_92 [ V_43 ] ;
return V_16 -> V_24 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned long V_80 )
{
unsigned char V_81 ;
V_81 = F_9 ( V_2 -> V_9 + V_93 ) ;
if ( V_81 & V_94 )
return 0 ;
return - V_84 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned int * V_17 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_9 = V_2 -> V_9 ;
unsigned int V_43 = F_17 ( V_16 -> V_60 ) ;
unsigned int V_61 = F_22 ( V_16 -> V_60 ) ;
unsigned int V_3 = V_7 -> V_92 [ V_43 ] ;
unsigned char V_36 = 0 ;
int V_25 ;
int V_39 ;
if ( V_43 > 3 ) {
V_36 |= F_41 ( V_43 - 4 ) ;
V_9 += V_95 ;
} else {
V_36 |= F_41 ( V_43 ) ;
}
F_3 ( F_42 ( V_61 ) , V_9 + V_96 ) ;
F_3 ( 0 , V_9 + V_97 ) ;
F_3 ( V_36 | V_98 , V_9 + V_99 ) ;
V_25 = F_35 ( V_2 , V_14 , V_16 , F_39 , 0 ) ;
if ( V_25 )
return V_25 ;
for ( V_39 = 0 ; V_39 < V_16 -> V_24 ; V_39 ++ ) {
V_3 = V_17 [ V_39 ] ;
F_3 ( V_3 & 0xff , V_9 + V_96 ) ;
F_3 ( ( V_3 >> 8 ) & 0xff , V_9 + V_97 ) ;
F_3 ( V_36 | V_100 ,
V_9 + V_99 ) ;
V_25 = F_35 ( V_2 , V_14 , V_16 , F_39 , 0 ) ;
if ( V_25 )
return V_25 ;
V_7 -> V_92 [ V_43 ] = V_3 ;
}
return V_16 -> V_24 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_101 * V_102 )
{
struct V_6 * V_7 ;
struct V_13 * V_14 ;
int V_25 ;
V_25 = F_44 ( V_2 , V_102 -> V_103 [ 0 ] , 32 ) ;
if ( V_25 )
return V_25 ;
V_7 = F_45 ( V_2 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_104 ;
F_46 ( & V_7 -> V_11 ) ;
F_46 ( & V_7 -> V_40 ) ;
F_14 ( V_2 ) ;
if ( V_102 -> V_103 [ 1 ] ) {
V_25 = F_47 ( V_102 -> V_103 [ 1 ] , F_20 , 0 ,
V_2 -> V_105 , V_2 ) ;
if ( V_25 == 0 ) {
V_2 -> V_51 = V_102 -> V_103 [ 1 ] ;
F_3 ( V_106 ,
V_2 -> V_9 + V_107 ) ;
F_3 ( F_48 ( V_2 -> V_51 ) ,
V_2 -> V_9 + V_108 ) ;
}
}
V_25 = F_49 ( V_2 , 4 ) ;
if ( V_25 )
return V_25 ;
V_14 = & V_2 -> V_109 [ 0 ] ;
V_14 -> type = V_110 ;
V_14 -> V_111 = V_112 | V_113 | V_114 ;
V_14 -> V_20 = 16 ;
V_14 -> V_115 = 0xffff ;
V_14 -> V_116 = & V_117 ;
V_14 -> V_118 = F_32 ;
F_3 ( V_119 ,
V_2 -> V_9 + V_107 ) ;
F_3 ( V_119 ,
V_2 -> V_9 + V_107 + V_85 ) ;
V_14 = & V_2 -> V_109 [ 1 ] ;
V_14 -> type = V_120 ;
V_14 -> V_111 = V_112 ;
V_14 -> V_20 = 8 ;
V_14 -> V_115 = 0xffff ;
V_14 -> V_116 = & V_121 ;
V_14 -> V_118 = F_38 ;
V_14 -> V_122 = F_40 ;
F_3 ( 0 , V_2 -> V_9 + V_123 ) ;
F_3 ( 0 , V_2 -> V_9 + V_95 +
V_123 ) ;
V_14 = & V_2 -> V_109 [ 2 ] ;
V_14 -> type = V_124 ;
V_14 -> V_111 = V_112 | V_125 ;
V_14 -> V_20 = 24 ;
V_14 -> V_115 = 1 ;
V_14 -> V_126 = 1 ;
V_14 -> V_116 = & V_127 ;
V_14 -> V_128 = F_10 ;
V_14 -> V_129 = F_12 ;
if ( V_2 -> V_51 ) {
V_2 -> V_53 = V_14 ;
V_14 -> V_111 |= V_130 ;
V_14 -> V_126 = V_14 -> V_20 ;
V_14 -> V_131 = F_24 ;
V_14 -> V_132 = F_26 ;
V_14 -> V_133 = F_27 ;
}
V_14 = & V_2 -> V_109 [ 3 ] ;
V_14 -> type = V_124 ;
V_14 -> V_111 = V_112 | V_125 ;
V_14 -> V_20 = 24 ;
V_14 -> V_115 = 1 ;
V_14 -> V_116 = & V_127 ;
V_14 -> V_128 = F_10 ;
V_14 -> V_129 = F_12 ;
return 0 ;
}
