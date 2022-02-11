static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( 0x0 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_2 -> V_6 + V_8 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_9 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_10 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_11 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_12 ) ;
F_4 ( V_2 -> V_6 + V_13 ) ;
F_2 ( 0x0 , V_4 -> V_14 + V_15 ) ;
F_2 ( 0x0 , V_4 -> V_14 + V_16 ) ;
if ( V_4 -> V_17 ) {
unsigned long V_6 = V_4 -> V_17 + V_15 ;
F_2 ( 0x0 , V_6 + F_5 ( 0 ) ) ;
F_2 ( 0x0 , V_6 + F_5 ( 1 ) ) ;
F_2 ( 0x0 , V_6 + F_5 ( 2 ) ) ;
}
return 0 ;
}
static T_1 F_6 ( int V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = V_2 -> V_22 ;
unsigned int V_23 ;
unsigned int V_24 ;
unsigned int V_25 ;
V_21 -> V_26 &= ~ V_27 ;
V_23 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( V_23 & V_28 ) {
V_21 -> V_26 = F_3 ( V_2 -> V_6 + V_8 ) ;
V_21 -> V_26 &= V_29 ;
V_21 -> V_26 |= V_30 ;
F_2 ( V_23 & ~ V_28 ,
V_2 -> V_6 + V_7 ) ;
F_2 ( V_23 , V_2 -> V_6 + V_7 ) ;
}
V_23 = F_3 ( V_4 -> V_14 + V_31 ) ;
if ( V_23 & V_32 ) {
V_21 -> V_26 |= V_33 ;
V_24 = F_3 ( V_4 -> V_14 + V_15 ) ;
F_2 ( 0x0 , V_4 -> V_14 + V_15 ) ;
F_2 ( V_24 , V_4 -> V_14 + V_15 ) ;
}
if ( V_4 -> V_17 ) {
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ ) {
unsigned long V_6 ;
V_6 = V_4 -> V_17 + F_5 ( V_25 ) ;
V_23 = F_3 ( V_6 + V_31 ) ;
if ( V_23 & V_32 ) {
V_21 -> V_26 |= F_7 ( V_25 ) ;
V_24 = F_3 ( V_6 + V_15 ) ;
F_2 ( 0x0 , V_6 + V_15 ) ;
F_2 ( V_24 , V_6 + V_15 ) ;
}
}
}
if ( V_21 -> V_26 & V_27 ) {
F_8 ( V_21 , & V_21 -> V_26 , 1 ) ;
F_9 ( V_2 , V_21 ) ;
}
return V_34 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_35 * V_36 ,
unsigned int * V_37 )
{
V_37 [ 1 ] = F_3 ( V_2 -> V_6 + V_38 ) ;
return V_36 -> V_39 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_35 * V_36 ,
unsigned int * V_37 )
{
V_21 -> V_26 = F_3 ( V_2 -> V_6 + V_11 ) ;
if ( F_12 ( V_21 , V_37 ) )
F_2 ( V_21 -> V_26 , V_2 -> V_6 + V_11 ) ;
V_37 [ 1 ] = V_21 -> V_26 ;
return V_36 -> V_39 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_35 * V_36 ,
unsigned int * V_37 )
{
V_37 [ 1 ] = F_3 ( V_2 -> V_6 + V_40 ) & 3 ;
return V_36 -> V_39 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_35 * V_36 ,
unsigned int * V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_41 , V_42 ;
switch ( V_37 [ 0 ] ) {
case V_43 :
if ( V_37 [ 1 ] != 0 )
return - V_44 ;
V_41 = V_37 [ 3 ] ;
V_42 = ( 1U << V_41 ) - 1 ;
switch ( V_37 [ 2 ] ) {
case V_45 :
V_4 -> V_24 = 0 ;
V_4 -> V_46 = 0 ;
V_4 -> V_47 = 0 ;
F_2 ( 0x0 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_2 -> V_6 + V_8 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_9 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_10 ) ;
break;
case V_48 :
if ( V_4 -> V_24 != V_28 ) {
V_4 -> V_24 = V_28 ;
V_4 -> V_46 = 0 ;
V_4 -> V_47 = 0 ;
} else {
V_4 -> V_46 &= V_42 ;
V_4 -> V_47 &= V_42 ;
}
V_4 -> V_46 |= V_37 [ 4 ] << V_41 ;
V_4 -> V_47 |= V_37 [ 5 ] << V_41 ;
break;
case V_49 :
if ( V_4 -> V_24 != ( V_28 |
V_50 ) ) {
V_4 -> V_24 = V_28 |
V_50 ;
V_4 -> V_46 = 0 ;
V_4 -> V_47 = 0 ;
} else {
V_4 -> V_46 &= V_42 ;
V_4 -> V_47 &= V_42 ;
}
V_4 -> V_46 |= V_37 [ 4 ] << V_41 ;
V_4 -> V_47 |= V_37 [ 5 ] << V_41 ;
break;
default:
return - V_44 ;
}
V_4 -> V_46 &= V_29 ;
V_4 -> V_47 &= V_29 ;
break;
default:
return - V_44 ;
}
return V_36 -> V_39 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_35 * V_36 ,
unsigned int * V_37 )
{
V_37 [ 1 ] = V_21 -> V_26 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_51 * V_52 )
{
int V_53 = 0 ;
V_53 |= F_17 ( & V_52 -> V_54 , V_55 ) ;
V_53 |= F_17 ( & V_52 -> V_56 , V_57 ) ;
V_53 |= F_17 ( & V_52 -> V_58 , V_59 ) ;
V_53 |= F_17 ( & V_52 -> V_60 , V_61 ) ;
V_53 |= F_17 ( & V_52 -> V_62 , V_63 ) ;
if ( V_53 )
return 1 ;
V_53 |= F_18 ( & V_52 -> V_64 , 0 ) ;
V_53 |= F_18 ( & V_52 -> V_65 , 0 ) ;
V_53 |= F_18 ( & V_52 -> V_66 , 0 ) ;
V_53 |= F_18 ( & V_52 -> V_67 ,
V_52 -> V_68 ) ;
V_53 |= F_18 ( & V_52 -> V_69 , 0 ) ;
if ( V_53 )
return 3 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_24 && ! ( V_4 -> V_46 || V_4 -> V_47 ) ) {
F_20 ( V_2 -> V_70 ,
L_1 ) ;
return - V_44 ;
}
F_2 ( V_4 -> V_46 , V_2 -> V_6 + V_9 ) ;
F_2 ( V_4 -> V_47 , V_2 -> V_6 + V_10 ) ;
F_2 ( V_4 -> V_24 , V_2 -> V_6 + V_7 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
F_2 ( 0x0 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_2 -> V_6 + V_8 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_9 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_10 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_35 * V_36 ,
unsigned int * V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_71 ;
switch ( V_37 [ 0 ] ) {
case V_72 :
if ( V_37 [ 1 ] > V_21 -> V_73 )
return - V_44 ;
F_2 ( V_37 [ 1 ] , V_4 -> V_14 + V_16 ) ;
F_2 ( V_74 | V_75 ,
V_4 -> V_14 + V_15 ) ;
break;
case V_76 :
F_2 ( 0x0 , V_4 -> V_14 + V_15 ) ;
break;
case V_77 :
V_37 [ 1 ] = 0 ;
V_71 = F_3 ( V_4 -> V_14 + V_15 ) ;
if ( V_71 & V_74 )
V_37 [ 1 ] |= V_78 ;
if ( V_71 & V_75 )
V_37 [ 1 ] |= V_79 ;
V_71 = F_3 ( V_4 -> V_14 + V_80 ) ;
if ( V_71 & V_81 )
V_37 [ 1 ] |= V_82 ;
V_37 [ 2 ] = V_78 | V_79 |
V_82 ;
break;
case V_83 :
if ( V_37 [ 2 ] > V_21 -> V_73 )
return - V_44 ;
F_2 ( V_37 [ 1 ] , V_4 -> V_14 + V_84 ) ;
F_2 ( V_37 [ 2 ] , V_4 -> V_14 + V_16 ) ;
break;
case V_85 :
V_37 [ 1 ] = F_3 ( V_4 -> V_14 + V_84 ) ;
V_37 [ 2 ] = F_3 ( V_4 -> V_14 + V_16 ) ;
break;
default:
return - V_44 ;
}
return V_36 -> V_39 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_35 * V_36 ,
unsigned int * V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_36 -> V_39 ) {
unsigned int V_71 = V_37 [ V_36 -> V_39 - 1 ] ;
F_2 ( V_71 , V_4 -> V_14 + V_16 ) ;
}
return V_36 -> V_39 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_35 * V_36 ,
unsigned int * V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_36 -> V_39 ; V_86 ++ )
V_37 [ V_86 ] = F_3 ( V_4 -> V_14 + V_87 ) ;
return V_36 -> V_39 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_35 * V_36 ,
unsigned int * V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_25 = F_26 ( V_36 -> V_88 ) ;
unsigned long V_6 = V_4 -> V_17 + F_5 ( V_25 ) ;
unsigned int V_71 ;
switch ( V_37 [ 0 ] ) {
case V_72 :
V_71 = F_3 ( V_6 + V_15 ) ;
V_71 |= V_74 | V_89 ;
F_2 ( V_37 [ 1 ] , V_6 + V_16 ) ;
F_2 ( V_71 , V_6 + V_15 ) ;
break;
case V_76 :
V_71 = F_3 ( V_6 + V_15 ) ;
V_71 &= ~ ( V_74 | V_89 ) ;
F_2 ( V_71 , V_6 + V_15 ) ;
break;
case V_90 :
F_2 ( V_37 [ 1 ] , V_6 + V_15 ) ;
break;
case V_77 :
V_37 [ 1 ] = 0 ;
V_71 = F_3 ( V_6 + V_15 ) ;
if ( V_71 & V_74 )
V_37 [ 1 ] |= V_78 ;
if ( V_71 & V_89 )
V_37 [ 1 ] |= V_79 ;
V_71 = F_3 ( V_6 + V_80 ) ;
if ( V_71 & V_81 )
V_37 [ 1 ] |= V_82 ;
V_37 [ 2 ] = V_78 | V_79 |
V_82 ;
break;
default:
return - V_44 ;
}
return V_36 -> V_39 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_35 * V_36 ,
unsigned int * V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_25 = F_26 ( V_36 -> V_88 ) ;
unsigned long V_6 = V_4 -> V_17 + F_5 ( V_25 ) ;
if ( V_36 -> V_39 ) {
unsigned int V_71 = V_37 [ V_36 -> V_39 - 1 ] ;
F_2 ( V_71 , V_6 + V_16 ) ;
}
return V_36 -> V_39 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_35 * V_36 ,
unsigned int * V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_25 = F_26 ( V_36 -> V_88 ) ;
unsigned long V_6 = V_4 -> V_17 + F_5 ( V_25 ) ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_36 -> V_39 ; V_86 ++ )
V_37 [ V_86 ] = F_3 ( V_6 + V_87 ) ;
return V_36 -> V_39 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned long V_91 )
{
struct V_92 * V_93 = F_30 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_20 * V_21 ;
unsigned int V_71 ;
int V_94 ;
V_4 = F_31 ( V_2 , sizeof( * V_4 ) ) ;
if ( ! V_4 )
return - V_95 ;
V_94 = F_32 ( V_2 ) ;
if ( V_94 )
return V_94 ;
V_4 -> V_96 = F_33 ( V_93 , 0 ) ;
V_71 = F_3 ( V_4 -> V_96 + V_97 ) ;
if ( F_34 ( V_71 ) == 0 ) {
V_2 -> V_6 = F_33 ( V_93 , 1 ) +
V_98 ;
V_4 -> V_14 = V_4 -> V_96 + V_99 ;
} else {
V_2 -> V_6 = V_4 -> V_96 + V_100 ;
V_4 -> V_14 = V_4 -> V_96 + V_101 ;
V_4 -> V_17 = F_33 ( V_93 , 1 ) ;
}
F_1 ( V_2 ) ;
if ( V_93 -> V_18 > 0 ) {
V_94 = F_35 ( V_93 -> V_18 , F_6 , V_102 ,
V_2 -> V_103 , V_2 ) ;
if ( V_94 == 0 )
V_2 -> V_18 = V_93 -> V_18 ;
}
V_94 = F_36 ( V_2 , 7 ) ;
if ( V_94 )
return V_94 ;
V_21 = & V_2 -> V_104 [ 0 ] ;
V_21 -> type = V_105 ;
V_21 -> V_106 = V_107 ;
V_21 -> V_108 = 32 ;
V_21 -> V_73 = 1 ;
V_21 -> V_109 = & V_110 ;
V_21 -> V_111 = F_10 ;
V_21 = & V_2 -> V_104 [ 1 ] ;
V_21 -> type = V_112 ;
V_21 -> V_106 = V_113 ;
V_21 -> V_108 = 32 ;
V_21 -> V_73 = 1 ;
V_21 -> V_109 = & V_110 ;
V_21 -> V_111 = F_11 ;
V_21 = & V_2 -> V_104 [ 2 ] ;
if ( V_2 -> V_18 ) {
V_2 -> V_22 = V_21 ;
V_21 -> type = V_105 ;
V_21 -> V_106 = V_107 | V_114 | V_115 ;
V_21 -> V_108 = 1 ;
V_21 -> V_73 = 1 ;
V_21 -> V_109 = & V_110 ;
V_21 -> V_116 = 1 ;
V_21 -> V_117 = F_14 ;
V_21 -> V_111 = F_15 ;
V_21 -> V_118 = F_16 ;
V_21 -> V_119 = F_19 ;
V_21 -> V_120 = F_21 ;
} else {
V_21 -> type = V_121 ;
}
V_21 = & V_2 -> V_104 [ 3 ] ;
V_21 -> type = V_122 ;
V_21 -> V_106 = V_113 | V_107 ;
V_21 -> V_108 = 1 ;
V_21 -> V_73 = 0x0fff ;
V_21 -> V_109 = & V_110 ;
V_21 -> V_117 = F_22 ;
V_21 -> V_123 = F_23 ;
V_21 -> V_124 = F_24 ;
V_21 = & V_2 -> V_104 [ 4 ] ;
if ( V_4 -> V_17 ) {
V_21 -> type = V_125 ;
V_21 -> V_106 = V_113 | V_107 | V_115 ;
V_21 -> V_108 = 3 ;
V_21 -> V_73 = 0xffffffff ;
V_21 -> V_109 = & V_110 ;
V_21 -> V_117 = F_25 ;
V_21 -> V_123 = F_27 ;
V_21 -> V_124 = F_28 ;
} else {
V_21 -> type = V_121 ;
}
V_21 = & V_2 -> V_104 [ 5 ] ;
V_94 = F_37 ( V_21 , V_2 -> V_6 + V_13 ) ;
if ( V_94 )
return V_94 ;
V_21 = & V_2 -> V_104 [ 6 ] ;
V_21 -> type = V_105 ;
V_21 -> V_106 = V_107 ;
V_21 -> V_108 = 2 ;
V_21 -> V_73 = 1 ;
V_21 -> V_109 = & V_110 ;
V_21 -> V_111 = F_13 ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 )
F_1 ( V_2 ) ;
F_39 ( V_2 ) ;
}
static int F_40 ( struct V_92 * V_2 ,
const struct V_126 * V_127 )
{
return F_41 ( V_2 , & V_128 , V_127 -> V_129 ) ;
}
