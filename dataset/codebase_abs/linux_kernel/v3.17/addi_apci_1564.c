static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( 0x0 , V_4 -> V_6 + V_7 ) ;
F_3 ( V_4 -> V_6 + V_8 ) ;
F_2 ( 0x0 , V_4 -> V_6 + V_9 ) ;
F_2 ( 0x0 , V_4 -> V_6 + V_10 ) ;
F_2 ( 0x0 , V_4 -> V_6 + V_11 ) ;
F_2 ( 0x0 , V_4 -> V_6 + V_12 ) ;
F_4 ( V_4 -> V_6 + V_13 ) ;
F_2 ( 0x0 , V_4 -> V_6 + V_14 ) ;
F_2 ( 0x0 , V_4 -> V_6 + V_15 ) ;
F_2 ( 0x0 , V_2 -> V_16 + F_5 ( V_17 ) ) ;
F_2 ( 0x0 , V_2 -> V_16 + F_5 ( V_18 ) ) ;
F_2 ( 0x0 , V_2 -> V_16 + F_5 ( V_19 ) ) ;
F_2 ( 0x0 , V_2 -> V_16 + F_5 ( V_20 ) ) ;
return 0 ;
}
static T_1 F_6 ( int V_21 , void * V_22 )
{
struct V_1 * V_2 = V_22 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 = V_2 -> V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
unsigned int V_28 ;
if ( ( F_3 ( V_4 -> V_6 + V_29 ) &
V_30 ) == 0 )
return V_31 ;
V_26 = F_3 ( V_4 -> V_6 + V_7 ) ;
if ( V_26 & V_32 ) {
F_2 ( V_26 & V_33 ,
V_4 -> V_6 + V_7 ) ;
V_24 -> V_34 = F_3 ( V_2 -> V_16 + V_8 )
& 0xffff ;
F_7 ( V_24 , V_24 -> V_34 ) ;
V_24 -> V_35 -> V_36 |= V_37 | V_38 ;
F_8 ( V_2 , V_24 ) ;
F_2 ( V_26 , V_4 -> V_6 + V_7 ) ;
}
V_26 = F_3 ( V_4 -> V_6 + V_39 ) ;
if ( V_26 & 0x01 ) {
V_27 = F_3 ( V_4 -> V_6 + V_14 ) ;
F_2 ( 0x0 , V_4 -> V_6 + V_14 ) ;
F_9 ( V_40 , V_4 -> V_41 , 0 ) ;
F_2 ( V_27 , V_4 -> V_6 + V_14 ) ;
}
for ( V_28 = 0 ; V_28 < 4 ; V_28 ++ ) {
V_26 = F_3 ( V_2 -> V_16 + F_10 ( V_28 ) ) ;
if ( V_26 & 0x01 ) {
V_27 = F_3 ( V_2 -> V_16 + F_5 ( V_28 ) ) ;
F_2 ( 0x0 , V_2 -> V_16 + F_5 ( V_28 ) ) ;
F_9 ( V_40 , V_4 -> V_41 , 0 ) ;
F_2 ( V_27 , V_2 -> V_16 + F_5 ( V_28 ) ) ;
}
}
return V_42 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_45 [ 1 ] = F_3 ( V_4 -> V_6 + V_46 ) ;
return V_44 -> V_47 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_24 -> V_34 = F_3 ( V_4 -> V_6 + V_11 ) ;
if ( F_13 ( V_24 , V_45 ) )
F_2 ( V_24 -> V_34 , V_4 -> V_6 + V_11 ) ;
V_45 [ 1 ] = V_24 -> V_34 ;
return V_44 -> V_47 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_45 [ 1 ] = F_3 ( V_4 -> V_6 + V_48 ) & 3 ;
return V_44 -> V_47 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_49 , V_50 ;
switch ( V_45 [ 0 ] ) {
case V_51 :
if ( V_45 [ 1 ] != 0 )
return - V_52 ;
V_49 = V_45 [ 3 ] ;
V_50 = ( 1U << V_49 ) - 1 ;
switch ( V_45 [ 2 ] ) {
case V_53 :
V_4 -> V_27 = 0 ;
V_4 -> V_54 = 0 ;
V_4 -> V_55 = 0 ;
F_2 ( 0x0 , V_4 -> V_6 + V_7 ) ;
F_3 ( V_4 -> V_6 + V_8 ) ;
F_2 ( 0x0 , V_4 -> V_6 + V_9 ) ;
F_2 ( 0x0 , V_4 -> V_6 + V_10 ) ;
break;
case V_56 :
if ( V_4 -> V_27 != ( V_32 |
V_57 ) ) {
V_4 -> V_27 = V_32 |
V_57 ;
V_4 -> V_54 = 0 ;
V_4 -> V_55 = 0 ;
} else {
V_4 -> V_54 &= V_50 ;
V_4 -> V_55 &= V_50 ;
}
V_4 -> V_54 |= V_45 [ 4 ] << V_49 ;
V_4 -> V_55 |= V_45 [ 5 ] << V_49 ;
break;
case V_58 :
if ( V_4 -> V_27 != ( V_32 |
V_59 ) ) {
V_4 -> V_27 = V_32 |
V_59 ;
V_4 -> V_54 = 0 ;
V_4 -> V_55 = 0 ;
} else {
V_4 -> V_54 &= V_50 ;
V_4 -> V_55 &= V_50 ;
}
V_4 -> V_54 |= V_45 [ 4 ] << V_49 ;
V_4 -> V_55 |= V_45 [ 5 ] << V_49 ;
break;
default:
return - V_52 ;
}
break;
default:
return - V_52 ;
}
return V_44 -> V_47 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_43 * V_44 ,
unsigned int * V_45 )
{
V_45 [ 1 ] = V_24 -> V_34 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_60 * V_61 )
{
int V_62 = 0 ;
V_62 |= F_18 ( & V_61 -> V_63 , V_64 ) ;
V_62 |= F_18 ( & V_61 -> V_65 , V_66 ) ;
V_62 |= F_18 ( & V_61 -> V_67 , V_68 ) ;
V_62 |= F_18 ( & V_61 -> V_69 , V_70 ) ;
V_62 |= F_18 ( & V_61 -> V_71 , V_72 ) ;
if ( V_62 )
return 1 ;
if ( V_62 )
return 2 ;
V_62 |= F_19 ( & V_61 -> V_73 , 0 ) ;
V_62 |= F_19 ( & V_61 -> V_74 , 0 ) ;
V_62 |= F_19 ( & V_61 -> V_75 , 0 ) ;
V_62 |= F_19 ( & V_61 -> V_76 , V_61 -> V_77 ) ;
V_62 |= F_19 ( & V_61 -> V_78 , 0 ) ;
if ( V_62 )
return 3 ;
if ( V_62 )
return 4 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_27 ) {
F_21 ( V_2 -> V_79 ,
L_1 ) ;
return - V_52 ;
}
F_2 ( V_4 -> V_54 , V_4 -> V_6 + V_9 ) ;
F_2 ( V_4 -> V_55 , V_4 -> V_6 + V_10 ) ;
F_2 ( V_4 -> V_27 , V_4 -> V_6 + V_7 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( 0x0 , V_4 -> V_6 + V_7 ) ;
F_3 ( V_4 -> V_6 + V_8 ) ;
F_2 ( 0x0 , V_4 -> V_6 + V_9 ) ;
F_2 ( 0x0 , V_4 -> V_6 + V_10 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned long V_80 )
{
struct V_81 * V_82 = F_24 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_23 * V_24 ;
int V_83 ;
V_4 = F_25 ( V_2 , sizeof( * V_4 ) ) ;
if ( ! V_4 )
return - V_84 ;
V_83 = F_26 ( V_2 ) ;
if ( V_83 )
return V_83 ;
V_2 -> V_16 = F_27 ( V_82 , 1 ) ;
V_4 -> V_6 = F_27 ( V_82 , 0 ) ;
F_1 ( V_2 ) ;
if ( V_82 -> V_21 > 0 ) {
V_83 = F_28 ( V_82 -> V_21 , F_6 , V_85 ,
V_2 -> V_86 , V_2 ) ;
if ( V_83 == 0 )
V_2 -> V_21 = V_82 -> V_21 ;
}
V_83 = F_29 ( V_2 , 6 ) ;
if ( V_83 )
return V_83 ;
V_24 = & V_2 -> V_87 [ 0 ] ;
V_24 -> type = V_88 ;
V_24 -> V_89 = V_90 ;
V_24 -> V_91 = 32 ;
V_24 -> V_92 = 1 ;
V_24 -> V_93 = & V_94 ;
V_24 -> V_95 = F_11 ;
V_24 = & V_2 -> V_87 [ 1 ] ;
V_24 -> type = V_96 ;
V_24 -> V_89 = V_97 ;
V_24 -> V_91 = 32 ;
V_24 -> V_92 = 1 ;
V_24 -> V_93 = & V_94 ;
V_24 -> V_98 = V_99 ;
V_24 -> V_95 = F_12 ;
V_24 = & V_2 -> V_87 [ 2 ] ;
if ( V_2 -> V_21 ) {
V_2 -> V_25 = V_24 ;
V_24 -> type = V_88 ;
V_24 -> V_89 = V_90 | V_100 ;
V_24 -> V_91 = 1 ;
V_24 -> V_92 = 1 ;
V_24 -> V_93 = & V_94 ;
V_24 -> V_101 = 1 ;
V_24 -> V_98 = F_15 ;
V_24 -> V_95 = F_16 ;
V_24 -> V_102 = F_17 ;
V_24 -> V_103 = F_20 ;
V_24 -> V_104 = F_22 ;
} else {
V_24 -> type = V_105 ;
}
V_24 = & V_2 -> V_87 [ 3 ] ;
V_24 -> type = V_106 ;
V_24 -> V_89 = V_97 ;
V_24 -> V_91 = 1 ;
V_24 -> V_92 = 0 ;
V_24 -> V_101 = 1 ;
V_24 -> V_93 = & V_94 ;
V_24 -> V_107 = V_108 ;
V_24 -> V_109 = V_110 ;
V_24 -> V_98 = V_111 ;
V_24 = & V_2 -> V_87 [ 4 ] ;
V_83 = F_30 ( V_24 , V_4 -> V_6 + V_13 ) ;
if ( V_83 )
return V_83 ;
V_24 = & V_2 -> V_87 [ 5 ] ;
V_24 -> type = V_88 ;
V_24 -> V_89 = V_90 ;
V_24 -> V_91 = 2 ;
V_24 -> V_92 = 1 ;
V_24 -> V_93 = & V_94 ;
V_24 -> V_95 = F_14 ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 )
F_1 ( V_2 ) ;
if ( V_2 -> V_21 )
F_32 ( V_2 -> V_21 , V_2 ) ;
F_33 ( V_2 ) ;
}
static int F_34 ( struct V_81 * V_2 ,
const struct V_112 * V_113 )
{
return F_35 ( V_2 , & V_114 , V_113 -> V_115 ) ;
}
