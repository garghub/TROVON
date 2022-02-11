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
static int F_16 ( struct V_18 * V_19 , struct V_22 * V_23 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_24 V_25 = V_23 -> V_26 ;
int V_13 ;
const T_3 V_27 = 9 , V_28 = 25 ;
if ( V_7 -> V_29 == V_30 )
V_25 . V_31 = F_17 ( V_25 . V_31 , 2 ) ;
V_25 . V_32 = F_17 ( V_25 . V_32 , 2 ) ;
V_25 . V_33 = F_17 ( V_25 . V_33 , 2 ) ;
F_18 ( & V_25 . V_33 , & V_25 . V_32 ,
V_34 , V_35 , V_36 ) ;
F_18 ( & V_25 . V_37 , & V_25 . V_31 ,
V_38 , V_39 , V_40 ) ;
V_7 -> V_41 = V_25 . V_31 + V_7 -> V_42 + V_28 ;
V_13 = F_8 ( V_9 , V_43 , V_27 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_44 , V_28 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_45 , V_25 . V_33 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_46 , V_25 . V_37 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_47 , V_25 . V_32 - 1 ) ;
if ( ! V_13 )
V_13 = F_8 ( V_9 , V_48 ,
V_25 . V_31 + V_7 -> V_42 - 1 ) ;
if ( ! V_13 && F_19 ( V_7 -> V_49 ) == V_50 )
V_13 = F_8 ( V_9 , V_51 , V_7 -> V_41 ) ;
if ( ! V_13 )
V_7 -> V_25 = V_25 ;
return V_13 ;
}
static int F_20 ( struct V_18 * V_19 , struct V_22 * V_23 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_23 -> V_26 = V_7 -> V_25 ;
V_23 -> type = V_52 ;
return 0 ;
}
static int F_21 ( struct V_18 * V_19 , struct V_53 * V_23 )
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
static int F_22 ( struct V_18 * V_19 ,
struct V_59 * V_60 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
V_60 -> V_32 = V_7 -> V_25 . V_32 ;
V_60 -> V_31 = V_7 -> V_25 . V_31 ;
V_60 -> V_3 = V_7 -> V_4 -> V_3 ;
V_60 -> V_61 = V_7 -> V_4 -> V_61 ;
V_60 -> V_62 = V_63 ;
return 0 ;
}
static int F_23 ( struct V_18 * V_19 ,
struct V_59 * V_60 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
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
V_13 = F_16 ( V_19 , & V_23 ) ;
if ( ! V_13 ) {
V_60 -> V_32 = V_7 -> V_25 . V_32 ;
V_60 -> V_31 = V_7 -> V_25 . V_31 ;
V_7 -> V_4 = F_1 ( V_60 -> V_3 ,
V_7 -> V_29 , V_7 -> V_64 ) ;
V_60 -> V_61 = V_7 -> V_4 -> V_61 ;
}
return V_13 ;
}
static int F_24 ( struct V_18 * V_19 ,
struct V_59 * V_60 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
const struct V_1 * V_4 ;
F_25 ( & V_60 -> V_32 , V_35 ,
V_36 , 1 ,
& V_60 -> V_31 , V_39 + V_7 -> V_42 ,
V_40 + V_7 -> V_42 , 0 , 0 ) ;
if ( V_7 -> V_29 == V_30 )
V_60 -> V_31 = F_17 ( V_60 -> V_31 - 1 , 2 ) ;
V_4 = F_1 ( V_60 -> V_3 , V_7 -> V_29 ,
V_7 -> V_64 ) ;
if ( ! V_4 ) {
V_4 = V_7 -> V_4 ;
V_60 -> V_3 = V_4 -> V_3 ;
}
V_60 -> V_61 = V_4 -> V_61 ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 ,
struct V_65 * V_66 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_66 -> V_67 . type != V_68 )
return - V_69 ;
if ( V_66 -> V_67 . V_70 != V_9 -> V_70 )
return - V_71 ;
V_66 -> V_72 = V_7 -> V_73 ;
V_66 -> V_74 = 0 ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 ,
struct V_75 * V_11 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
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
static int F_28 ( struct V_18 * V_19 ,
struct V_75 * V_11 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
if ( V_11 -> V_67 . type != V_68 || V_11 -> V_11 > 0xff )
return - V_69 ;
if ( V_11 -> V_67 . V_70 != V_9 -> V_70 )
return - V_71 ;
if ( F_8 ( V_9 , V_11 -> V_11 , V_11 -> V_77 ) < 0 )
return - V_21 ;
return 0 ;
}
static int F_29 ( struct V_78 * V_79 )
{
struct V_7 * V_7 = F_3 ( V_79 -> V_80 ,
struct V_7 , V_81 ) ;
T_2 V_82 , V_83 ;
switch ( V_79 -> V_66 ) {
case V_84 :
V_82 = V_7 -> V_85 -> V_86 ;
V_83 = V_7 -> V_85 -> V_87 ;
V_7 -> V_85 -> V_77 =
( 524 + ( V_7 -> V_41 - 1 ) * ( V_83 - V_82 ) ) / 1048 + V_82 ;
break;
}
return 0 ;
}
static int F_30 ( struct V_78 * V_79 )
{
struct V_7 * V_7 = F_3 ( V_79 -> V_80 ,
struct V_7 , V_81 ) ;
struct V_18 * V_19 = & V_7 -> V_10 ;
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_78 * exp = V_7 -> V_85 ;
int V_12 ;
switch ( V_79 -> V_66 ) {
case V_88 :
if ( V_79 -> V_77 )
V_12 = F_10 ( V_9 , V_89 , 0x8000 ) ;
else
V_12 = F_11 ( V_9 , V_89 , 0x8000 ) ;
if ( V_12 < 0 )
return - V_21 ;
return 0 ;
case V_90 :
if ( V_79 -> V_77 <= V_79 -> V_91 ) {
unsigned long V_92 = V_79 -> V_91 - V_79 -> V_86 ;
V_12 = ( ( V_79 -> V_77 - V_79 -> V_86 ) * 8 + V_92 / 2 ) / V_92 ;
F_13 ( & V_9 -> V_14 , L_2 , V_12 ) ;
V_12 = F_8 ( V_9 , V_93 , V_12 ) ;
if ( V_12 < 0 )
return - V_21 ;
} else {
unsigned long V_92 = V_79 -> V_87 - V_79 -> V_91 - 1 ;
unsigned long V_94 = ( ( V_79 -> V_77 - V_79 -> V_91 - 1 ) *
111 + V_92 / 2 ) / V_92 + 9 ;
if ( V_94 <= 32 )
V_12 = V_94 ;
else if ( V_94 <= 64 )
V_12 = ( ( V_94 - 32 ) * 16 + 16 ) / 32 + 80 ;
else
V_12 = ( ( V_94 - 64 ) * 7 + 28 ) / 56 + 96 ;
F_13 ( & V_9 -> V_14 , L_3 ,
F_5 ( V_9 , V_93 ) , V_12 ) ;
V_12 = F_8 ( V_9 , V_93 , V_12 ) ;
if ( V_12 < 0 )
return - V_21 ;
}
return 0 ;
case V_84 :
if ( V_79 -> V_77 == V_95 ) {
unsigned long V_92 = exp -> V_87 - exp -> V_86 ;
unsigned long V_96 = ( ( exp -> V_77 - exp -> V_86 ) * 1048 +
V_92 / 2 ) / V_92 + 1 ;
F_13 ( & V_9 -> V_14 ,
L_4 ,
F_5 ( V_9 , V_51 ) , V_96 ) ;
if ( F_8 ( V_9 , V_51 , V_96 ) < 0 )
return - V_21 ;
} else {
const T_3 V_28 = 25 ;
V_7 -> V_41 = V_7 -> V_25 . V_31 +
V_7 -> V_42 + V_28 ;
if ( F_8 ( V_9 , V_51 , V_7 -> V_41 ) < 0 )
return - V_21 ;
}
return 0 ;
}
return - V_69 ;
}
static int F_31 ( struct V_97 * V_98 ,
struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
T_2 V_12 ;
unsigned long V_99 ;
int V_13 ;
V_12 = F_8 ( V_9 , V_100 , 1 ) ;
F_13 ( & V_9 -> V_14 , L_5 , V_12 ) ;
V_12 = F_5 ( V_9 , V_101 ) ;
switch ( V_12 ) {
case 0x8411 :
case 0x8421 :
V_7 -> V_73 = V_102 ;
V_7 -> V_29 = V_30 ;
break;
case 0x8431 :
V_7 -> V_73 = V_103 ;
V_7 -> V_29 = V_104 ;
break;
default:
F_32 ( & V_9 -> V_14 ,
L_6 , V_12 ) ;
return - V_71 ;
}
V_7 -> V_64 = 0 ;
if ( V_98 -> V_105 )
V_99 = V_98 -> V_105 ( V_98 ) ;
else
V_99 = V_106 ;
if ( V_99 & V_106 )
V_7 -> V_64 ++ ;
else
V_7 -> V_29 ++ ;
if ( V_99 & V_107 )
V_7 -> V_64 ++ ;
V_7 -> V_4 = & V_7 -> V_29 [ 0 ] ;
F_33 ( & V_9 -> V_14 , L_7 , V_12 ,
V_12 == 0x8431 ? L_8 : L_9 ) ;
V_13 = F_12 ( V_9 ) ;
if ( V_13 < 0 )
F_32 ( & V_9 -> V_14 , L_10 ) ;
return F_34 ( & V_7 -> V_81 ) ;
}
static void F_35 ( struct V_97 * V_98 )
{
if ( V_98 -> V_108 )
V_98 -> V_108 ( V_98 ) ;
}
static int F_36 ( struct V_18 * V_19 , T_4 * V_109 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
* V_109 = V_7 -> V_42 ;
return 0 ;
}
static int F_37 ( struct V_18 * V_19 , unsigned int V_110 ,
enum V_2 * V_3 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_110 >= V_7 -> V_64 )
return - V_69 ;
* V_3 = V_7 -> V_29 [ V_110 ] . V_3 ;
return 0 ;
}
static int F_38 ( struct V_18 * V_19 ,
struct V_111 * V_112 )
{
struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_97 * V_98 = F_39 ( V_9 ) ;
V_112 -> V_99 = V_113 |
V_114 | V_115 |
V_116 | V_117 ;
V_112 -> type = V_118 ;
V_112 -> V_99 = F_40 ( V_98 , V_112 ) ;
return 0 ;
}
static int F_41 ( struct V_18 * V_19 ,
const struct V_111 * V_112 )
{
const struct V_8 * V_9 = F_15 ( V_19 ) ;
struct V_97 * V_98 = F_39 ( V_9 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
unsigned int V_119 = F_42 ( V_7 -> V_4 -> V_3 ) -> V_120 ;
if ( V_98 -> V_121 )
return V_98 -> V_121 ( V_98 , 1 << ( V_119 - 1 ) ) ;
return V_119 == 10 ? 0 : - V_69 ;
}
static int F_43 ( struct V_8 * V_9 ,
const struct V_122 * V_123 )
{
struct V_7 * V_7 ;
struct V_124 * V_125 = F_44 ( V_9 -> V_14 . V_126 ) ;
struct V_97 * V_98 = F_39 ( V_9 ) ;
int V_13 ;
if ( ! V_98 ) {
F_32 ( & V_9 -> V_14 , L_11 ) ;
return - V_69 ;
}
if ( ! F_45 ( V_125 , V_127 ) ) {
F_46 ( & V_125 -> V_14 ,
L_12 ) ;
return - V_21 ;
}
V_7 = F_47 ( sizeof( struct V_7 ) , V_128 ) ;
if ( ! V_7 )
return - V_129 ;
F_48 ( & V_7 -> V_10 , V_9 , & V_130 ) ;
F_49 ( & V_7 -> V_81 , 4 ) ;
F_50 ( & V_7 -> V_81 , & V_131 ,
V_88 , 0 , 1 , 1 , 0 ) ;
F_50 ( & V_7 -> V_81 , & V_131 ,
V_90 , 0 , 127 , 1 , 64 ) ;
V_7 -> V_85 = F_50 ( & V_7 -> V_81 , & V_131 ,
V_132 , 1 , 255 , 1 , 255 ) ;
V_7 -> V_49 = F_51 ( & V_7 -> V_81 ,
& V_131 , V_84 , 1 , 0 ,
V_50 ) ;
V_7 -> V_10 . V_133 = & V_7 -> V_81 ;
if ( V_7 -> V_81 . error ) {
int V_134 = V_7 -> V_81 . error ;
F_52 ( V_7 ) ;
return V_134 ;
}
F_53 ( 2 , & V_7 -> V_49 ,
V_95 , true ) ;
V_7 -> V_42 = 0 ;
V_7 -> V_25 . V_33 = V_34 ;
V_7 -> V_25 . V_37 = V_38 ;
V_7 -> V_25 . V_32 = V_36 ;
V_7 -> V_25 . V_31 = V_40 ;
V_13 = F_31 ( V_98 , V_9 ) ;
if ( V_13 ) {
F_54 ( & V_7 -> V_81 ) ;
F_52 ( V_7 ) ;
}
return V_13 ;
}
static int F_55 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_97 * V_98 = F_39 ( V_9 ) ;
F_56 ( & V_7 -> V_10 ) ;
F_54 ( & V_7 -> V_81 ) ;
F_35 ( V_98 ) ;
F_52 ( V_7 ) ;
return 0 ;
}
static int T_5 F_57 ( void )
{
return F_58 ( & V_135 ) ;
}
static void T_6 F_59 ( void )
{
F_60 ( & V_135 ) ;
}
