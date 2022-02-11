static const struct V_1 * F_1 (
enum V_2 V_3 , const struct V_1 * V_4 ,
int V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
if ( V_4 [ V_6 ] . V_3 == V_3 )
return V_4 + V_6 ;
return NULL ;
}
static struct V_7 * F_2 ( const struct V_8 * V_9 )
{
return F_3 ( F_4 ( V_9 ) , struct V_7 , V_10 ) ;
}
static int F_5 ( struct V_8 * V_9 , const T_1 V_11 )
{
T_2 V_12 = F_6 ( V_9 , V_11 ) ;
return V_12 < 0 ? V_12 : F_7 ( V_12 ) ;
}
static int F_8 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_3 V_12 )
{
return F_9 ( V_9 , V_11 , F_7 ( V_12 ) ) ;
}
static int F_10 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_3 V_12 )
{
int V_13 ;
V_13 = F_5 ( V_9 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_8 ( V_9 , V_11 , V_13 | V_12 ) ;
}
static int F_11 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_3 V_12 )
{
int V_13 ;
V_13 = F_5 ( V_9 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_8 ( V_9 , V_11 , V_13 & ~ V_12 ) ;
}
static int F_12 ( struct V_8 * V_9 )
{
int V_13 ;
F_13 ( & V_9 -> V_14 , L_1 , V_15 ) ;
V_13 = F_8 ( V_9 , V_16 , 1 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_16 , 0 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_17 , 0 ) ;
return V_13 ;
}
static int F_14 ( struct V_18 * V_19 , int V_20 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
if ( F_8 ( V_9 , V_17 , V_20 ? 2 : 0 ) < 0 )
return - V_21 ;
return 0 ;
}
static int F_16 ( struct V_22 * V_23 ,
unsigned long V_24 )
{
struct V_25 * V_26 = F_17 ( V_23 ) ;
unsigned long V_27 = V_24 & V_28 ;
if ( ! F_18 ( V_27 ) )
return - V_29 ;
if ( V_26 -> V_30 )
return V_26 -> V_30 ( V_26 , V_27 ) ;
if ( V_27 == V_31 )
return 0 ;
return - V_29 ;
}
static unsigned long F_19 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_17 ( V_23 ) ;
unsigned long V_24 = V_32 |
V_33 | V_34 |
V_35 | V_36 ;
if ( V_26 -> V_37 )
V_24 |= V_26 -> V_37 ( V_26 ) & V_28 ;
else
V_24 |= V_31 ;
return F_20 ( V_26 , V_24 ) ;
}
static int F_21 ( struct V_18 * V_19 , struct V_38 * V_39 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_40 V_41 = V_39 -> V_42 ;
struct V_22 * V_23 = V_9 -> V_14 . V_43 ;
int V_13 ;
const T_3 V_44 = 9 , V_45 = 25 ;
unsigned int V_46 ;
if ( V_7 -> V_47 == V_48 )
V_41 . V_49 = F_22 ( V_41 . V_49 , 2 ) ;
V_41 . V_50 = F_22 ( V_41 . V_50 , 2 ) ;
V_41 . V_51 = F_22 ( V_41 . V_51 , 2 ) ;
F_23 ( & V_41 . V_51 , & V_41 . V_50 ,
V_52 , V_53 , V_54 ) ;
F_23 ( & V_41 . V_55 , & V_41 . V_49 ,
V_56 , V_57 , V_58 ) ;
V_46 = V_41 . V_49 + V_7 -> V_59 + V_45 ;
V_13 = F_8 ( V_9 , V_60 , V_44 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_61 , V_45 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_62 , V_41 . V_51 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_63 , V_41 . V_55 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_64 , V_41 . V_50 - 1 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_65 ,
V_41 . V_49 + V_7 -> V_59 - 1 ) ;
if ( ! V_13 && V_7 -> V_66 ) {
V_13 = F_8 ( V_9 , V_67 , V_46 ) ;
if ( ! V_13 ) {
const struct V_68 * V_69 =
F_24 ( V_23 -> V_70 ,
V_71 ) ;
V_7 -> V_72 = ( 524 + ( V_46 - 1 ) *
( V_69 -> V_73 - V_69 -> V_74 ) ) /
1048 + V_69 -> V_74 ;
}
}
if ( ! V_13 )
V_7 -> V_41 = V_41 ;
return V_13 ;
}
static int F_25 ( struct V_18 * V_19 , struct V_38 * V_39 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_39 -> V_42 = V_7 -> V_41 ;
V_39 -> type = V_75 ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 , struct V_76 * V_39 )
{
V_39 -> V_77 . V_51 = V_52 ;
V_39 -> V_77 . V_55 = V_56 ;
V_39 -> V_77 . V_50 = V_54 ;
V_39 -> V_77 . V_49 = V_58 ;
V_39 -> V_78 = V_39 -> V_77 ;
V_39 -> type = V_75 ;
V_39 -> V_79 . V_80 = 1 ;
V_39 -> V_79 . V_81 = 1 ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 ,
struct V_82 * V_83 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_83 -> V_50 = V_7 -> V_41 . V_50 ;
V_83 -> V_49 = V_7 -> V_41 . V_49 ;
V_83 -> V_3 = V_7 -> V_4 -> V_3 ;
V_83 -> V_84 = V_7 -> V_4 -> V_84 ;
V_83 -> V_85 = V_86 ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 ,
struct V_82 * V_83 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_38 V_39 = {
. V_42 = {
. V_51 = V_7 -> V_41 . V_51 ,
. V_55 = V_7 -> V_41 . V_55 ,
. V_50 = V_83 -> V_50 ,
. V_49 = V_83 -> V_49 ,
} ,
} ;
int V_13 ;
V_13 = F_21 ( V_19 , & V_39 ) ;
if ( ! V_13 ) {
V_83 -> V_50 = V_7 -> V_41 . V_50 ;
V_83 -> V_49 = V_7 -> V_41 . V_49 ;
V_7 -> V_4 = F_1 ( V_83 -> V_3 ,
V_7 -> V_47 , V_7 -> V_87 ) ;
V_83 -> V_84 = V_7 -> V_4 -> V_84 ;
}
return V_13 ;
}
static int F_29 ( struct V_18 * V_19 ,
struct V_82 * V_83 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_1 * V_4 ;
F_30 ( & V_83 -> V_50 , V_53 ,
V_54 , 1 ,
& V_83 -> V_49 , V_57 + V_7 -> V_59 ,
V_58 + V_7 -> V_59 , 0 , 0 ) ;
if ( V_7 -> V_47 == V_48 )
V_83 -> V_49 = F_22 ( V_83 -> V_49 - 1 , 2 ) ;
V_4 = F_1 ( V_83 -> V_3 , V_7 -> V_47 ,
V_7 -> V_87 ) ;
if ( ! V_4 ) {
V_4 = V_7 -> V_4 ;
V_83 -> V_3 = V_4 -> V_3 ;
}
V_83 -> V_84 = V_4 -> V_84 ;
return 0 ;
}
static int F_31 ( struct V_18 * V_19 ,
struct V_88 * V_89 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_89 -> V_90 . type != V_91 )
return - V_29 ;
if ( V_89 -> V_90 . V_92 != V_9 -> V_92 )
return - V_93 ;
V_89 -> V_94 = V_7 -> V_95 ;
V_89 -> V_96 = 0 ;
return 0 ;
}
static int F_32 ( struct V_18 * V_19 ,
struct V_97 * V_11 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
if ( V_11 -> V_90 . type != V_91 || V_11 -> V_11 > 0xff )
return - V_29 ;
if ( V_11 -> V_90 . V_92 != V_9 -> V_92 )
return - V_93 ;
V_11 -> V_98 = 2 ;
V_11 -> V_99 = F_5 ( V_9 , V_11 -> V_11 ) ;
if ( V_11 -> V_99 > 0xffff )
return - V_21 ;
return 0 ;
}
static int F_33 ( struct V_18 * V_19 ,
struct V_97 * V_11 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
if ( V_11 -> V_90 . type != V_91 || V_11 -> V_11 > 0xff )
return - V_29 ;
if ( V_11 -> V_90 . V_92 != V_9 -> V_92 )
return - V_93 ;
if ( F_8 ( V_9 , V_11 -> V_11 , V_11 -> V_99 ) < 0 )
return - V_21 ;
return 0 ;
}
static int F_34 ( struct V_18 * V_19 , struct V_100 * V_101 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
int V_12 ;
switch ( V_101 -> V_89 ) {
case V_102 :
V_12 = F_5 ( V_9 , V_103 ) ;
if ( V_12 < 0 )
return - V_21 ;
V_101 -> V_104 = ! ! ( V_12 & 0x8000 ) ;
break;
case V_105 :
V_101 -> V_104 = V_7 -> V_66 ;
break;
case V_106 :
V_101 -> V_104 = V_7 -> V_107 ;
break;
case V_71 :
V_101 -> V_104 = V_7 -> V_72 ;
break;
}
return 0 ;
}
static int F_35 ( struct V_18 * V_19 , struct V_100 * V_101 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_22 * V_23 = V_9 -> V_14 . V_43 ;
const struct V_68 * V_69 ;
int V_12 ;
V_69 = F_24 ( & V_108 , V_101 -> V_89 ) ;
if ( ! V_69 )
return - V_29 ;
switch ( V_101 -> V_89 ) {
case V_102 :
if ( V_101 -> V_104 )
V_12 = F_10 ( V_9 , V_103 , 0x8000 ) ;
else
V_12 = F_11 ( V_9 , V_103 , 0x8000 ) ;
if ( V_12 < 0 )
return - V_21 ;
break;
case V_106 :
if ( V_101 -> V_104 > V_69 -> V_73 || V_101 -> V_104 < V_69 -> V_74 )
return - V_29 ;
if ( V_101 -> V_104 <= V_69 -> V_109 ) {
unsigned long V_110 = V_69 -> V_109 - V_69 -> V_74 ;
V_12 = ( ( V_101 -> V_104 - V_69 -> V_74 ) * 8 + V_110 / 2 ) / V_110 ;
F_13 ( & V_9 -> V_14 , L_2 , V_12 ) ;
V_12 = F_8 ( V_9 , V_111 , V_12 ) ;
if ( V_12 < 0 )
return - V_21 ;
} else {
unsigned long V_110 = V_69 -> V_73 - V_69 -> V_109 - 1 ;
unsigned long V_107 = ( ( V_101 -> V_104 - V_69 -> V_109 - 1 ) *
111 + V_110 / 2 ) / V_110 + 9 ;
if ( V_107 <= 32 )
V_12 = V_107 ;
else if ( V_107 <= 64 )
V_12 = ( ( V_107 - 32 ) * 16 + 16 ) / 32 + 80 ;
else
V_12 = ( ( V_107 - 64 ) * 7 + 28 ) / 56 + 96 ;
F_13 ( & V_9 -> V_14 , L_3 ,
F_5 ( V_9 , V_111 ) , V_12 ) ;
V_12 = F_8 ( V_9 , V_111 , V_12 ) ;
if ( V_12 < 0 )
return - V_21 ;
}
V_7 -> V_107 = V_101 -> V_104 ;
break;
case V_71 :
if ( V_101 -> V_104 > V_69 -> V_73 || V_101 -> V_104 < V_69 -> V_74 )
return - V_29 ;
else {
unsigned long V_110 = V_69 -> V_73 - V_69 -> V_74 ;
unsigned long V_112 = ( ( V_101 -> V_104 - V_69 -> V_74 ) * 1048 +
V_110 / 2 ) / V_110 + 1 ;
F_13 ( & V_9 -> V_14 ,
L_4 ,
F_5 ( V_9 , V_67 ) ,
V_112 ) ;
if ( F_8 ( V_9 , V_67 , V_112 ) < 0 )
return - V_21 ;
V_7 -> V_72 = V_101 -> V_104 ;
V_7 -> V_66 = 0 ;
}
break;
case V_105 :
if ( V_101 -> V_104 ) {
const T_3 V_45 = 25 ;
unsigned int V_46 = V_7 -> V_41 . V_49 +
V_7 -> V_59 + V_45 ;
if ( F_8 ( V_9 , V_67 ,
V_46 ) < 0 )
return - V_21 ;
V_69 = F_24 ( V_23 -> V_70 , V_71 ) ;
V_7 -> V_72 = ( 524 + ( V_46 - 1 ) *
( V_69 -> V_73 - V_69 -> V_74 ) ) /
1048 + V_69 -> V_74 ;
V_7 -> V_66 = 1 ;
} else
V_7 -> V_66 = 0 ;
break;
}
return 0 ;
}
static int F_36 ( struct V_22 * V_23 ,
struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_25 * V_26 = F_17 ( V_23 ) ;
T_2 V_12 ;
unsigned long V_24 ;
int V_13 ;
if ( ! V_23 -> V_14 . V_113 ||
F_37 ( V_23 -> V_14 . V_113 ) -> V_114 != V_23 -> V_115 )
return - V_93 ;
V_12 = F_8 ( V_9 , V_116 , 1 ) ;
F_13 ( & V_9 -> V_14 , L_5 , V_12 ) ;
V_12 = F_5 ( V_9 , V_117 ) ;
switch ( V_12 ) {
case 0x8411 :
case 0x8421 :
V_7 -> V_95 = V_118 ;
V_7 -> V_47 = V_48 ;
break;
case 0x8431 :
V_7 -> V_95 = V_119 ;
V_7 -> V_47 = V_120 ;
break;
default:
F_38 ( & V_9 -> V_14 ,
L_6 , V_12 ) ;
return - V_93 ;
}
V_7 -> V_87 = 0 ;
if ( V_26 -> V_37 )
V_24 = V_26 -> V_37 ( V_26 ) ;
else
V_24 = V_31 ;
if ( V_24 & V_31 )
V_7 -> V_87 ++ ;
else
V_7 -> V_47 ++ ;
if ( V_24 & V_121 )
V_7 -> V_87 ++ ;
V_7 -> V_4 = & V_7 -> V_47 [ 0 ] ;
F_39 ( & V_9 -> V_14 , L_7 , V_12 ,
V_12 == 0x8431 ? L_8 : L_9 ) ;
V_13 = F_12 ( V_9 ) ;
if ( V_13 < 0 )
F_38 ( & V_9 -> V_14 , L_10 ) ;
V_7 -> V_107 = 64 ;
V_7 -> V_72 = 255 ;
return V_13 ;
}
static void F_40 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = F_17 ( V_23 ) ;
F_13 ( & V_23 -> V_14 , L_11 ,
V_23 -> V_14 . V_113 , V_23 -> V_122 ) ;
if ( V_26 -> V_123 )
V_26 -> V_123 ( V_26 ) ;
}
static int F_41 ( struct V_18 * V_19 , T_4 * V_124 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
* V_124 = V_7 -> V_59 ;
return 0 ;
}
static int F_42 ( struct V_18 * V_19 , unsigned int V_125 ,
enum V_2 * V_3 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_125 >= V_7 -> V_87 )
return - V_29 ;
* V_3 = V_7 -> V_47 [ V_125 ] . V_3 ;
return 0 ;
}
static int F_43 ( struct V_8 * V_9 ,
const struct V_126 * V_127 )
{
struct V_7 * V_7 ;
struct V_22 * V_23 = V_9 -> V_14 . V_43 ;
struct V_128 * V_129 = F_44 ( V_9 -> V_14 . V_113 ) ;
struct V_25 * V_26 ;
int V_13 ;
if ( ! V_23 ) {
F_38 ( & V_9 -> V_14 , L_12 ) ;
return - V_29 ;
}
V_26 = F_17 ( V_23 ) ;
if ( ! V_26 ) {
F_38 ( & V_9 -> V_14 , L_13 ) ;
return - V_29 ;
}
if ( ! F_45 ( V_129 , V_130 ) ) {
F_46 ( & V_129 -> V_14 ,
L_14 ) ;
return - V_21 ;
}
V_7 = F_47 ( sizeof( struct V_7 ) , V_131 ) ;
if ( ! V_7 )
return - V_132 ;
F_48 ( & V_7 -> V_10 , V_9 , & V_133 ) ;
V_23 -> V_70 = & V_108 ;
V_7 -> V_59 = 0 ;
V_7 -> V_41 . V_51 = V_52 ;
V_7 -> V_41 . V_55 = V_56 ;
V_7 -> V_41 . V_50 = V_54 ;
V_7 -> V_41 . V_49 = V_58 ;
V_7 -> V_66 = 1 ;
V_13 = F_36 ( V_23 , V_9 ) ;
if ( V_13 ) {
V_23 -> V_70 = NULL ;
F_49 ( V_7 ) ;
}
return V_13 ;
}
static int F_50 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_22 * V_23 = V_9 -> V_14 . V_43 ;
V_23 -> V_70 = NULL ;
F_40 ( V_23 ) ;
F_49 ( V_7 ) ;
return 0 ;
}
static int T_5 F_51 ( void )
{
return F_52 ( & V_134 ) ;
}
static void T_6 F_53 ( void )
{
F_54 ( & V_134 ) ;
}
