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
unsigned int V_35 = V_14 -> V_32 -> V_36 ;
unsigned int V_37 = V_14 -> V_32 -> V_38 . V_39 ;
unsigned int V_3 = 0 ;
unsigned long V_10 ;
int V_40 ;
F_2 ( & V_7 -> V_41 , V_10 ) ;
if ( ! V_7 -> V_31 )
goto V_42;
if ( ! ( V_34 & V_7 -> V_30 ) )
goto V_42;
for ( V_40 = 0 ; V_40 < V_37 ; V_40 ++ ) {
unsigned int V_43 = F_17 ( V_14 -> V_32 -> V_38 . V_44 [ V_40 ] ) ;
if ( V_34 & ( 1 << V_43 ) )
V_3 |= ( 1 << V_40 ) ;
}
if ( F_18 ( V_14 -> V_32 , V_3 ) &&
F_18 ( V_14 -> V_32 , V_3 >> 16 ) ) {
V_14 -> V_32 -> V_36 |= ( V_45 | V_46 ) ;
} else {
F_15 ( V_2 , V_14 ) ;
}
if ( ! V_7 -> V_47 ) {
if ( V_7 -> V_48 > 0 ) {
V_7 -> V_48 -- ;
if ( V_7 -> V_48 == 0 ) {
V_14 -> V_32 -> V_36 |= V_49 ;
F_15 ( V_2 , V_14 ) ;
}
}
}
V_42:
F_7 ( & V_7 -> V_41 , V_10 ) ;
if ( V_35 != V_14 -> V_32 -> V_36 )
F_19 ( V_2 , V_14 ) ;
}
static T_1 F_20 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_13 * V_14 = V_2 -> V_52 ;
unsigned int V_34 ;
unsigned char V_53 ;
V_53 = F_9 ( V_2 -> V_9 + V_54 ) & 0x07 ;
if ( ! V_53 )
return V_55 ;
V_34 = F_8 ( V_2 , V_29 , 0 ) ;
F_1 ( V_2 , 0 , V_29 , 0 ) ;
F_16 ( V_2 , V_14 , V_34 ) ;
return V_56 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_57 * V_38 = & V_14 -> V_32 -> V_38 ;
unsigned int V_58 = 0 ;
unsigned int V_59 = 0 ;
int V_40 ;
if ( ! V_7 -> V_47 && V_7 -> V_48 == 0 ) {
V_14 -> V_32 -> V_36 |= V_49 ;
V_7 -> V_31 = 0 ;
return 1 ;
}
V_7 -> V_30 = 0 ;
V_7 -> V_31 = 1 ;
if ( V_38 -> V_44 ) {
for ( V_40 = 0 ; V_40 < V_38 -> V_39 ; V_40 ++ ) {
unsigned int V_60 = V_38 -> V_44 [ V_40 ] ;
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
F_2 ( & V_7 -> V_41 , V_10 ) ;
if ( V_7 -> V_31 )
F_15 ( V_2 , V_14 ) ;
F_7 ( & V_7 -> V_41 , V_10 ) ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_13 * V_14 ,
unsigned int V_63 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long V_10 ;
int V_64 = 0 ;
if ( V_63 != 0 )
return - V_65 ;
F_2 ( & V_7 -> V_41 , V_10 ) ;
V_14 -> V_32 -> V_33 = NULL ;
if ( V_7 -> V_31 )
V_64 = F_21 ( V_2 , V_14 ) ;
F_7 ( & V_7 -> V_41 , V_10 ) ;
if ( V_64 )
F_19 ( V_2 , V_14 ) ;
return 1 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_57 * V_38 = & V_14 -> V_32 -> V_38 ;
unsigned long V_10 ;
int V_64 = 0 ;
F_2 ( & V_7 -> V_41 , V_10 ) ;
V_7 -> V_31 = 1 ;
switch ( V_38 -> V_66 ) {
case V_67 :
V_7 -> V_47 = 0 ;
V_7 -> V_48 = V_38 -> V_68 ;
break;
default:
V_7 -> V_47 = 1 ;
V_7 -> V_48 = 0 ;
break;
}
switch ( V_38 -> V_69 ) {
case V_70 :
V_14 -> V_32 -> V_33 = F_25 ;
break;
default:
V_64 = F_21 ( V_2 , V_14 ) ;
break;
}
F_7 ( & V_7 -> V_41 , V_10 ) ;
if ( V_64 )
F_19 ( V_2 , V_14 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_57 * V_38 )
{
int V_71 = 0 ;
V_71 |= F_28 ( & V_38 -> V_69 , V_72 | V_70 ) ;
V_71 |= F_28 ( & V_38 -> V_73 , V_74 ) ;
V_71 |= F_28 ( & V_38 -> V_75 , V_72 ) ;
V_71 |= F_28 ( & V_38 -> V_76 , V_67 ) ;
V_71 |= F_28 ( & V_38 -> V_66 , V_67 | V_77 ) ;
if ( V_71 )
return 1 ;
V_71 |= F_29 ( V_38 -> V_69 ) ;
V_71 |= F_29 ( V_38 -> V_66 ) ;
if ( V_71 )
return 2 ;
V_71 |= F_30 ( & V_38 -> V_78 , 0 ) ;
V_71 |= F_30 ( & V_38 -> V_79 , 0 ) ;
V_71 |= F_30 ( & V_38 -> V_80 , 0 ) ;
V_71 |= F_30 ( & V_38 -> V_81 , V_38 -> V_39 ) ;
switch ( V_38 -> V_66 ) {
case V_67 :
break;
case V_77 :
V_71 |= F_30 ( & V_38 -> V_68 , 0 ) ;
break;
default:
break;
}
if ( V_71 )
return 3 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned long V_82 )
{
unsigned char V_83 ;
V_83 = F_9 ( V_2 -> V_9 + V_84 ) ;
if ( V_83 & V_85 )
return 0 ;
return - V_86 ;
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
unsigned char V_38 = 0 ;
unsigned int V_3 ;
int V_25 ;
int V_40 ;
if ( V_43 > 7 ) {
V_43 -= 8 ;
V_9 += V_87 ;
}
if ( V_62 == V_88 )
V_38 |= V_89 ;
if ( V_43 % 2 )
V_38 |= V_90 ;
V_38 |= F_33 ( V_43 / 2 ) ;
V_38 |= F_34 ( V_61 ) ;
F_3 ( V_38 , V_9 + V_91 ) ;
V_25 = F_35 ( V_2 , V_14 , V_16 , F_31 , 0 ) ;
if ( V_25 )
return V_25 ;
V_3 = F_9 ( V_9 + V_92 ) ;
V_3 |= F_9 ( V_9 + V_93 ) << 8 ;
for ( V_40 = 0 ; V_40 < V_16 -> V_24 ; V_40 ++ ) {
F_3 ( V_38 , V_9 + V_91 ) ;
V_25 = F_35 ( V_2 , V_14 , V_16 , F_31 , 0 ) ;
if ( V_25 )
return V_25 ;
V_3 = F_9 ( V_9 + V_92 ) ;
V_3 |= F_9 ( V_9 + V_93 ) << 8 ;
if ( F_36 ( V_14 , V_61 ) )
V_3 = F_37 ( V_14 , V_3 ) ;
V_17 [ V_40 ] = V_3 ;
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
int V_40 ;
for ( V_40 = 0 ; V_40 < V_16 -> V_24 ; V_40 ++ )
V_17 [ V_40 ] = V_7 -> V_94 [ V_43 ] ;
return V_16 -> V_24 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 ,
unsigned long V_82 )
{
unsigned char V_83 ;
V_83 = F_9 ( V_2 -> V_9 + V_95 ) ;
if ( V_83 & V_96 )
return 0 ;
return - V_86 ;
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
unsigned int V_3 = V_7 -> V_94 [ V_43 ] ;
unsigned char V_38 = 0 ;
int V_25 ;
int V_40 ;
if ( V_43 > 3 ) {
V_38 |= F_41 ( V_43 - 4 ) ;
V_9 += V_97 ;
} else {
V_38 |= F_41 ( V_43 ) ;
}
F_3 ( F_42 ( V_61 ) , V_9 + V_98 ) ;
F_3 ( 0 , V_9 + V_99 ) ;
F_3 ( V_38 | V_100 , V_9 + V_101 ) ;
V_25 = F_35 ( V_2 , V_14 , V_16 , F_39 , 0 ) ;
if ( V_25 )
return V_25 ;
for ( V_40 = 0 ; V_40 < V_16 -> V_24 ; V_40 ++ ) {
V_3 = V_17 [ V_40 ] ;
F_3 ( V_3 & 0xff , V_9 + V_98 ) ;
F_3 ( ( V_3 >> 8 ) & 0xff , V_9 + V_99 ) ;
F_3 ( V_38 | V_102 ,
V_9 + V_101 ) ;
V_25 = F_35 ( V_2 , V_14 , V_16 , F_39 , 0 ) ;
if ( V_25 )
return V_25 ;
V_7 -> V_94 [ V_43 ] = V_3 ;
}
return V_16 -> V_24 ;
}
static int F_43 ( struct V_1 * V_2 , struct V_103 * V_104 )
{
struct V_6 * V_7 ;
struct V_13 * V_14 ;
int V_25 ;
V_25 = F_44 ( V_2 , V_104 -> V_105 [ 0 ] , 32 ) ;
if ( V_25 )
return V_25 ;
V_7 = F_45 ( V_2 , sizeof( * V_7 ) ) ;
if ( ! V_7 )
return - V_106 ;
F_46 ( & V_7 -> V_11 ) ;
F_46 ( & V_7 -> V_41 ) ;
F_14 ( V_2 ) ;
if ( V_104 -> V_105 [ 1 ] ) {
V_25 = F_47 ( V_104 -> V_105 [ 1 ] , F_20 , 0 ,
V_2 -> V_107 , V_2 ) ;
if ( V_25 == 0 ) {
V_2 -> V_50 = V_104 -> V_105 [ 1 ] ;
F_3 ( V_108 ,
V_2 -> V_9 + V_109 ) ;
F_3 ( F_48 ( V_2 -> V_50 ) ,
V_2 -> V_9 + V_110 ) ;
}
}
V_25 = F_49 ( V_2 , 4 ) ;
if ( V_25 )
return V_25 ;
V_14 = & V_2 -> V_111 [ 0 ] ;
V_14 -> type = V_112 ;
V_14 -> V_113 = V_114 | V_115 | V_116 ;
V_14 -> V_20 = 16 ;
V_14 -> V_117 = 0xffff ;
V_14 -> V_118 = & V_119 ;
V_14 -> V_120 = F_32 ;
F_3 ( V_121 ,
V_2 -> V_9 + V_109 ) ;
F_3 ( V_121 ,
V_2 -> V_9 + V_109 + V_87 ) ;
V_14 = & V_2 -> V_111 [ 1 ] ;
V_14 -> type = V_122 ;
V_14 -> V_113 = V_114 ;
V_14 -> V_20 = 8 ;
V_14 -> V_117 = 0xffff ;
V_14 -> V_118 = & V_123 ;
V_14 -> V_120 = F_38 ;
V_14 -> V_124 = F_40 ;
F_3 ( 0 , V_2 -> V_9 + V_125 ) ;
F_3 ( 0 , V_2 -> V_9 + V_97 +
V_125 ) ;
V_14 = & V_2 -> V_111 [ 2 ] ;
V_14 -> type = V_126 ;
V_14 -> V_113 = V_114 | V_127 ;
V_14 -> V_20 = 24 ;
V_14 -> V_117 = 1 ;
V_14 -> V_128 = 1 ;
V_14 -> V_118 = & V_129 ;
V_14 -> V_130 = F_10 ;
V_14 -> V_131 = F_12 ;
if ( V_2 -> V_50 ) {
V_2 -> V_52 = V_14 ;
V_14 -> V_113 |= V_132 ;
V_14 -> V_128 = V_14 -> V_20 ;
V_14 -> V_133 = F_24 ;
V_14 -> V_134 = F_26 ;
V_14 -> V_135 = F_27 ;
}
V_14 = & V_2 -> V_111 [ 3 ] ;
V_14 -> type = V_126 ;
V_14 -> V_113 = V_114 | V_127 ;
V_14 -> V_20 = 24 ;
V_14 -> V_117 = 1 ;
V_14 -> V_118 = & V_129 ;
V_14 -> V_130 = F_10 ;
V_14 -> V_131 = F_12 ;
return 0 ;
}
