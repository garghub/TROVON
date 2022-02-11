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
return F_6 ( V_9 , V_11 ) ;
}
static int F_7 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_2 V_12 )
{
return F_8 ( V_9 , V_11 , V_12 ) ;
}
static int F_9 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_2 V_12 )
{
int V_13 ;
V_13 = F_5 ( V_9 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_7 ( V_9 , V_11 , V_13 | V_12 ) ;
}
static int F_10 ( struct V_8 * V_9 , const T_1 V_11 ,
const T_2 V_12 )
{
int V_13 ;
V_13 = F_5 ( V_9 , V_11 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_7 ( V_9 , V_11 , V_13 & ~ V_12 ) ;
}
static int F_11 ( struct V_8 * V_9 )
{
int V_13 ;
F_12 ( & V_9 -> V_14 , L_1 , V_15 ) ;
V_13 = F_7 ( V_9 , V_16 , 1 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_16 , 0 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_17 , 0 ) ;
return V_13 ;
}
static int F_13 ( struct V_18 * V_19 , int V_20 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
if ( F_7 ( V_9 , V_17 , V_20 ? 2 : 0 ) < 0 )
return - V_21 ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 , const struct V_22 * V_23 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_24 V_25 = V_23 -> V_26 ;
int V_13 ;
const T_2 V_27 = 9 , V_28 = 25 ;
if ( V_7 -> V_29 == V_30 )
V_25 . V_31 = F_16 ( V_25 . V_31 , 2 ) ;
V_25 . V_32 = F_16 ( V_25 . V_32 , 2 ) ;
V_25 . V_33 = F_16 ( V_25 . V_33 , 2 ) ;
F_17 ( & V_25 . V_33 , & V_25 . V_32 ,
V_34 , V_35 , V_36 ) ;
F_17 ( & V_25 . V_37 , & V_25 . V_31 ,
V_38 , V_39 , V_40 ) ;
V_7 -> V_41 = V_25 . V_31 + V_7 -> V_42 + V_28 ;
V_13 = F_7 ( V_9 , V_43 , V_27 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_44 , V_28 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_45 , V_25 . V_33 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_46 , V_25 . V_37 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_47 , V_25 . V_32 - 1 ) ;
if ( ! V_13 )
V_13 = F_7 ( V_9 , V_48 ,
V_25 . V_31 + V_7 -> V_42 - 1 ) ;
if ( ! V_13 && F_18 ( V_7 -> V_49 ) == V_50 )
V_13 = F_7 ( V_9 , V_51 , V_7 -> V_41 ) ;
if ( ! V_13 )
V_7 -> V_25 = V_25 ;
return V_13 ;
}
static int F_19 ( struct V_18 * V_19 , struct V_22 * V_23 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_23 -> V_26 = V_7 -> V_25 ;
V_23 -> type = V_52 ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 , struct V_53 * V_23 )
{
V_23 -> V_54 . V_33 = V_34 ;
V_23 -> V_54 . V_37 = V_38 ;
V_23 -> V_54 . V_32 = V_36 ;
V_23 -> V_54 . V_31 = V_40 ;
V_23 -> V_55 = V_23 -> V_54 ;
V_23 -> type = V_52 ;
V_23 -> V_56 . V_57 = 1 ;
V_23 -> V_56 . V_58 = 1 ;
return 0 ;
}
static int F_21 ( struct V_18 * V_19 ,
struct V_59 * V_60 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_60 -> V_32 = V_7 -> V_25 . V_32 ;
V_60 -> V_31 = V_7 -> V_25 . V_31 ;
V_60 -> V_3 = V_7 -> V_4 -> V_3 ;
V_60 -> V_61 = V_7 -> V_4 -> V_61 ;
V_60 -> V_62 = V_63 ;
return 0 ;
}
static int F_22 ( struct V_18 * V_19 ,
struct V_59 * V_60 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_22 V_23 = {
. V_26 = {
. V_33 = V_7 -> V_25 . V_33 ,
. V_37 = V_7 -> V_25 . V_37 ,
. V_32 = V_60 -> V_32 ,
. V_31 = V_60 -> V_31 ,
} ,
} ;
int V_13 ;
V_13 = F_15 ( V_19 , & V_23 ) ;
if ( ! V_13 ) {
V_60 -> V_32 = V_7 -> V_25 . V_32 ;
V_60 -> V_31 = V_7 -> V_25 . V_31 ;
V_7 -> V_4 = F_1 ( V_60 -> V_3 ,
V_7 -> V_29 , V_7 -> V_64 ) ;
V_60 -> V_61 = V_7 -> V_4 -> V_61 ;
}
return V_13 ;
}
static int F_23 ( struct V_18 * V_19 ,
struct V_59 * V_60 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_1 * V_4 ;
F_24 ( & V_60 -> V_32 , V_35 ,
V_36 , 1 ,
& V_60 -> V_31 , V_39 + V_7 -> V_42 ,
V_40 + V_7 -> V_42 , 0 , 0 ) ;
if ( V_7 -> V_29 == V_30 )
V_60 -> V_31 = F_16 ( V_60 -> V_31 - 1 , 2 ) ;
V_4 = F_1 ( V_60 -> V_3 , V_7 -> V_29 ,
V_7 -> V_64 ) ;
if ( ! V_4 ) {
V_4 = V_7 -> V_4 ;
V_60 -> V_3 = V_4 -> V_3 ;
}
V_60 -> V_61 = V_4 -> V_61 ;
return 0 ;
}
static int F_25 ( struct V_18 * V_19 ,
struct V_65 * V_66 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_66 -> V_67 . type != V_68 )
return - V_69 ;
if ( V_66 -> V_67 . V_70 != V_9 -> V_70 )
return - V_71 ;
V_66 -> V_72 = V_7 -> V_73 ;
V_66 -> V_74 = 0 ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 ,
struct V_75 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
if ( V_11 -> V_67 . type != V_68 || V_11 -> V_11 > 0xff )
return - V_69 ;
if ( V_11 -> V_67 . V_70 != V_9 -> V_70 )
return - V_71 ;
V_11 -> V_76 = 2 ;
V_11 -> V_77 = F_5 ( V_9 , V_11 -> V_11 ) ;
if ( V_11 -> V_77 > 0xffff )
return - V_21 ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 ,
struct V_75 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
if ( V_11 -> V_67 . type != V_68 || V_11 -> V_11 > 0xff )
return - V_69 ;
if ( V_11 -> V_67 . V_70 != V_9 -> V_70 )
return - V_71 ;
if ( F_7 ( V_9 , V_11 -> V_11 , V_11 -> V_77 ) < 0 )
return - V_21 ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 , int V_78 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_79 * V_80 = F_29 ( V_9 ) ;
return F_30 ( & V_9 -> V_14 , V_80 , V_78 ) ;
}
static int F_31 ( struct V_81 * V_82 )
{
struct V_7 * V_7 = F_3 ( V_82 -> V_83 ,
struct V_7 , V_84 ) ;
T_3 V_85 , V_86 ;
switch ( V_82 -> V_66 ) {
case V_87 :
V_85 = V_7 -> V_88 -> V_89 ;
V_86 = V_7 -> V_88 -> V_90 ;
V_7 -> V_88 -> V_77 =
( 524 + ( V_7 -> V_41 - 1 ) * ( V_86 - V_85 ) ) / 1048 + V_85 ;
break;
}
return 0 ;
}
static int F_32 ( struct V_81 * V_82 )
{
struct V_7 * V_7 = F_3 ( V_82 -> V_83 ,
struct V_7 , V_84 ) ;
struct V_18 * V_19 = & V_7 -> V_10 ;
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_81 * exp = V_7 -> V_88 ;
int V_12 ;
switch ( V_82 -> V_66 ) {
case V_91 :
if ( V_82 -> V_77 )
V_12 = F_9 ( V_9 , V_92 , 0x8000 ) ;
else
V_12 = F_10 ( V_9 , V_92 , 0x8000 ) ;
if ( V_12 < 0 )
return - V_21 ;
return 0 ;
case V_93 :
if ( V_82 -> V_77 <= V_82 -> V_94 ) {
unsigned long V_95 = V_82 -> V_94 - V_82 -> V_89 ;
V_12 = ( ( V_82 -> V_77 - V_82 -> V_89 ) * 8 + V_95 / 2 ) / V_95 ;
F_12 ( & V_9 -> V_14 , L_2 , V_12 ) ;
V_12 = F_7 ( V_9 , V_96 , V_12 ) ;
if ( V_12 < 0 )
return - V_21 ;
} else {
unsigned long V_95 = V_82 -> V_90 - V_82 -> V_94 - 1 ;
unsigned long V_97 = ( ( V_82 -> V_77 - V_82 -> V_94 - 1 ) *
111 + V_95 / 2 ) / V_95 + 9 ;
if ( V_97 <= 32 )
V_12 = V_97 ;
else if ( V_97 <= 64 )
V_12 = ( ( V_97 - 32 ) * 16 + 16 ) / 32 + 80 ;
else
V_12 = ( ( V_97 - 64 ) * 7 + 28 ) / 56 + 96 ;
F_12 ( & V_9 -> V_14 , L_3 ,
F_5 ( V_9 , V_96 ) , V_12 ) ;
V_12 = F_7 ( V_9 , V_96 , V_12 ) ;
if ( V_12 < 0 )
return - V_21 ;
}
return 0 ;
case V_87 :
if ( V_82 -> V_77 == V_98 ) {
unsigned long V_95 = exp -> V_90 - exp -> V_89 ;
unsigned long V_99 = ( ( exp -> V_77 - exp -> V_89 ) * 1048 +
V_95 / 2 ) / V_95 + 1 ;
F_12 ( & V_9 -> V_14 ,
L_4 ,
F_5 ( V_9 , V_51 ) , V_99 ) ;
if ( F_7 ( V_9 , V_51 , V_99 ) < 0 )
return - V_21 ;
} else {
const T_2 V_28 = 25 ;
V_7 -> V_41 = V_7 -> V_25 . V_31 +
V_7 -> V_42 + V_28 ;
if ( F_7 ( V_9 , V_51 , V_7 -> V_41 ) < 0 )
return - V_21 ;
}
return 0 ;
}
return - V_69 ;
}
static int F_33 ( struct V_79 * V_80 ,
struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
T_3 V_12 ;
unsigned long V_100 ;
int V_13 ;
V_13 = F_28 ( & V_7 -> V_10 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_12 = F_7 ( V_9 , V_101 , 1 ) ;
F_12 ( & V_9 -> V_14 , L_5 , V_12 ) ;
V_12 = F_5 ( V_9 , V_102 ) ;
switch ( V_12 ) {
case 0x8411 :
case 0x8421 :
V_7 -> V_73 = V_103 ;
V_7 -> V_29 = V_30 ;
break;
case 0x8431 :
V_7 -> V_73 = V_104 ;
V_7 -> V_29 = V_105 ;
break;
default:
F_34 ( & V_9 -> V_14 ,
L_6 , V_12 ) ;
V_13 = - V_71 ;
goto V_106;
}
V_7 -> V_64 = 0 ;
if ( V_80 -> V_107 )
V_100 = V_80 -> V_107 ( V_80 ) ;
else
V_100 = V_108 ;
if ( V_100 & V_108 )
V_7 -> V_64 ++ ;
else
V_7 -> V_29 ++ ;
if ( V_100 & V_109 )
V_7 -> V_64 ++ ;
V_7 -> V_4 = & V_7 -> V_29 [ 0 ] ;
F_35 ( & V_9 -> V_14 , L_7 , V_12 ,
V_12 == 0x8431 ? L_8 : L_9 ) ;
V_13 = F_11 ( V_9 ) ;
if ( V_13 < 0 ) {
F_34 ( & V_9 -> V_14 , L_10 ) ;
goto V_106;
}
V_13 = F_36 ( & V_7 -> V_84 ) ;
V_106:
F_28 ( & V_7 -> V_10 , 0 ) ;
return V_13 ;
}
static void F_37 ( struct V_79 * V_80 )
{
if ( V_80 -> V_110 )
V_80 -> V_110 ( V_80 ) ;
}
static int F_38 ( struct V_18 * V_19 , T_4 * V_111 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
* V_111 = V_7 -> V_42 ;
return 0 ;
}
static int F_39 ( struct V_18 * V_19 , unsigned int V_112 ,
enum V_2 * V_3 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_112 >= V_7 -> V_64 )
return - V_69 ;
* V_3 = V_7 -> V_29 [ V_112 ] . V_3 ;
return 0 ;
}
static int F_40 ( struct V_18 * V_19 ,
struct V_113 * V_114 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_79 * V_80 = F_29 ( V_9 ) ;
V_114 -> V_100 = V_115 |
V_116 | V_117 |
V_118 | V_119 ;
V_114 -> type = V_120 ;
V_114 -> V_100 = F_41 ( V_80 , V_114 ) ;
return 0 ;
}
static int F_42 ( struct V_18 * V_19 ,
const struct V_113 * V_114 )
{
const struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_79 * V_80 = F_29 ( V_9 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
unsigned int V_121 = F_43 ( V_7 -> V_4 -> V_3 ) -> V_122 ;
if ( V_80 -> V_123 )
return V_80 -> V_123 ( V_80 , 1 << ( V_121 - 1 ) ) ;
return V_121 == 10 ? 0 : - V_69 ;
}
static int F_44 ( struct V_8 * V_9 ,
const struct V_124 * V_125 )
{
struct V_7 * V_7 ;
struct V_126 * V_127 = F_45 ( V_9 -> V_14 . V_128 ) ;
struct V_79 * V_80 = F_29 ( V_9 ) ;
int V_13 ;
if ( ! V_80 ) {
F_34 ( & V_9 -> V_14 , L_11 ) ;
return - V_69 ;
}
if ( ! F_46 ( V_127 , V_129 ) ) {
F_47 ( & V_127 -> V_14 ,
L_12 ) ;
return - V_21 ;
}
V_7 = F_48 ( sizeof( struct V_7 ) , V_130 ) ;
if ( ! V_7 )
return - V_131 ;
F_49 ( & V_7 -> V_10 , V_9 , & V_132 ) ;
F_50 ( & V_7 -> V_84 , 4 ) ;
F_51 ( & V_7 -> V_84 , & V_133 ,
V_91 , 0 , 1 , 1 , 0 ) ;
F_51 ( & V_7 -> V_84 , & V_133 ,
V_93 , 0 , 127 , 1 , 64 ) ;
V_7 -> V_88 = F_51 ( & V_7 -> V_84 , & V_133 ,
V_134 , 1 , 255 , 1 , 255 ) ;
V_7 -> V_49 = F_52 ( & V_7 -> V_84 ,
& V_133 , V_87 , 1 , 0 ,
V_50 ) ;
V_7 -> V_10 . V_135 = & V_7 -> V_84 ;
if ( V_7 -> V_84 . error ) {
int V_136 = V_7 -> V_84 . error ;
F_53 ( V_7 ) ;
return V_136 ;
}
F_54 ( 2 , & V_7 -> V_49 ,
V_98 , true ) ;
V_7 -> V_42 = 0 ;
V_7 -> V_25 . V_33 = V_34 ;
V_7 -> V_25 . V_37 = V_38 ;
V_7 -> V_25 . V_32 = V_36 ;
V_7 -> V_25 . V_31 = V_40 ;
V_13 = F_33 ( V_80 , V_9 ) ;
if ( V_13 ) {
F_55 ( & V_7 -> V_84 ) ;
F_53 ( V_7 ) ;
}
return V_13 ;
}
static int F_56 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_79 * V_80 = F_29 ( V_9 ) ;
F_57 ( & V_7 -> V_10 ) ;
F_55 ( & V_7 -> V_84 ) ;
F_37 ( V_80 ) ;
F_53 ( V_7 ) ;
return 0 ;
}
