static const struct V_1 * F_1 (
T_1 V_2 , const struct V_1 * V_3 ,
int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ )
if ( V_3 [ V_5 ] . V_2 == V_2 )
return V_3 + V_5 ;
return NULL ;
}
static struct V_6 * F_2 ( const struct V_7 * V_8 )
{
return F_3 ( F_4 ( V_8 ) , struct V_6 , V_9 ) ;
}
static int F_5 ( struct V_7 * V_8 , const T_2 V_10 )
{
return F_6 ( V_8 , V_10 ) ;
}
static int F_7 ( struct V_7 * V_8 , const T_2 V_10 ,
const T_3 V_11 )
{
return F_8 ( V_8 , V_10 , V_11 ) ;
}
static int F_9 ( struct V_7 * V_8 , const T_2 V_10 ,
const T_3 V_11 )
{
int V_12 ;
V_12 = F_5 ( V_8 , V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_7 ( V_8 , V_10 , V_12 | V_11 ) ;
}
static int F_10 ( struct V_7 * V_8 , const T_2 V_10 ,
const T_3 V_11 )
{
int V_12 ;
V_12 = F_5 ( V_8 , V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_7 ( V_8 , V_10 , V_12 & ~ V_11 ) ;
}
static int F_11 ( struct V_7 * V_8 )
{
int V_12 ;
F_12 ( & V_8 -> V_13 , L_1 , V_14 ) ;
V_12 = F_7 ( V_8 , V_15 , 1 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_15 , 0 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_16 , 0 ) ;
return V_12 ;
}
static int F_13 ( struct V_17 * V_18 , int V_19 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
if ( F_7 ( V_8 , V_16 , V_19 ? 2 : 0 ) < 0 )
return - V_20 ;
return 0 ;
}
static int F_15 ( struct V_17 * V_18 , const struct V_21 * V_22 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_23 V_24 = V_22 -> V_25 ;
int V_12 ;
const T_3 V_26 = 9 , V_27 = 25 ;
if ( V_6 -> V_28 == V_29 )
V_24 . V_30 = F_16 ( V_24 . V_30 , 2 ) ;
V_24 . V_31 = F_16 ( V_24 . V_31 , 2 ) ;
V_24 . V_32 = F_16 ( V_24 . V_32 , 2 ) ;
F_17 ( & V_24 . V_32 , & V_24 . V_31 ,
V_33 , V_34 , V_35 ) ;
F_17 ( & V_24 . V_36 , & V_24 . V_30 ,
V_37 , V_38 , V_39 ) ;
V_6 -> V_40 = V_24 . V_30 + V_6 -> V_41 + V_27 ;
V_12 = F_7 ( V_8 , V_42 , V_26 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_43 , V_27 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_44 , V_24 . V_32 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_45 , V_24 . V_36 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_46 , V_24 . V_31 - 1 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_47 ,
V_24 . V_30 + V_6 -> V_41 - 1 ) ;
if ( ! V_12 && F_18 ( V_6 -> V_48 ) == V_49 )
V_12 = F_7 ( V_8 , V_50 , V_6 -> V_40 ) ;
if ( ! V_12 )
V_6 -> V_24 = V_24 ;
return V_12 ;
}
static int F_19 ( struct V_17 * V_18 , struct V_21 * V_22 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
V_22 -> V_25 = V_6 -> V_24 ;
V_22 -> type = V_51 ;
return 0 ;
}
static int F_20 ( struct V_17 * V_18 , struct V_52 * V_22 )
{
V_22 -> V_53 . V_32 = V_33 ;
V_22 -> V_53 . V_36 = V_37 ;
V_22 -> V_53 . V_31 = V_35 ;
V_22 -> V_53 . V_30 = V_39 ;
V_22 -> V_54 = V_22 -> V_53 ;
V_22 -> type = V_51 ;
V_22 -> V_55 . V_56 = 1 ;
V_22 -> V_55 . V_57 = 1 ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 ,
struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_62 * V_63 = & V_61 -> V_61 ;
if ( V_61 -> V_64 )
return - V_65 ;
V_63 -> V_31 = V_6 -> V_24 . V_31 ;
V_63 -> V_30 = V_6 -> V_24 . V_30 ;
V_63 -> V_2 = V_6 -> V_3 -> V_2 ;
V_63 -> V_66 = V_6 -> V_3 -> V_66 ;
V_63 -> V_67 = V_68 ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 ,
struct V_62 * V_63 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_21 V_22 = {
. V_25 = {
. V_32 = V_6 -> V_24 . V_32 ,
. V_36 = V_6 -> V_24 . V_36 ,
. V_31 = V_63 -> V_31 ,
. V_30 = V_63 -> V_30 ,
} ,
} ;
int V_12 ;
V_12 = F_15 ( V_18 , & V_22 ) ;
if ( ! V_12 ) {
V_63 -> V_31 = V_6 -> V_24 . V_31 ;
V_63 -> V_30 = V_6 -> V_24 . V_30 ;
V_6 -> V_3 = F_1 ( V_63 -> V_2 ,
V_6 -> V_28 , V_6 -> V_69 ) ;
V_63 -> V_66 = V_6 -> V_3 -> V_66 ;
}
return V_12 ;
}
static int F_23 ( struct V_17 * V_18 ,
struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = & V_61 -> V_61 ;
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
const struct V_1 * V_3 ;
if ( V_61 -> V_64 )
return - V_65 ;
F_24 ( & V_63 -> V_31 , V_34 ,
V_35 , 1 ,
& V_63 -> V_30 , V_38 + V_6 -> V_41 ,
V_39 + V_6 -> V_41 , 0 , 0 ) ;
if ( V_6 -> V_28 == V_29 )
V_63 -> V_30 = F_16 ( V_63 -> V_30 - 1 , 2 ) ;
V_3 = F_1 ( V_63 -> V_2 , V_6 -> V_28 ,
V_6 -> V_69 ) ;
if ( ! V_3 ) {
V_3 = V_6 -> V_3 ;
V_63 -> V_2 = V_3 -> V_2 ;
}
V_63 -> V_66 = V_3 -> V_66 ;
if ( V_61 -> V_70 == V_71 )
return F_22 ( V_18 , V_63 ) ;
V_59 -> V_72 = * V_63 ;
return 0 ;
}
static int F_25 ( struct V_17 * V_18 ,
struct V_73 * V_10 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
if ( V_10 -> V_10 > 0xff )
return - V_65 ;
V_10 -> V_74 = 2 ;
V_10 -> V_75 = F_5 ( V_8 , V_10 -> V_10 ) ;
if ( V_10 -> V_75 > 0xffff )
return - V_20 ;
return 0 ;
}
static int F_26 ( struct V_17 * V_18 ,
const struct V_73 * V_10 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
if ( V_10 -> V_10 > 0xff )
return - V_65 ;
if ( F_7 ( V_8 , V_10 -> V_10 , V_10 -> V_75 ) < 0 )
return - V_20 ;
return 0 ;
}
static int F_27 ( struct V_17 * V_18 , int V_76 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_77 * V_78 = F_28 ( V_8 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
return F_29 ( & V_8 -> V_13 , V_78 , V_6 -> V_79 , V_76 ) ;
}
static int F_30 ( struct V_80 * V_81 )
{
struct V_6 * V_6 = F_3 ( V_81 -> V_82 ,
struct V_6 , V_83 ) ;
T_4 V_84 , V_85 ;
switch ( V_81 -> V_86 ) {
case V_87 :
V_84 = V_6 -> V_88 -> V_89 ;
V_85 = V_6 -> V_88 -> V_90 ;
V_6 -> V_88 -> V_75 =
( 524 + ( V_6 -> V_40 - 1 ) * ( V_85 - V_84 ) ) / 1048 + V_84 ;
break;
}
return 0 ;
}
static int F_31 ( struct V_80 * V_81 )
{
struct V_6 * V_6 = F_3 ( V_81 -> V_82 ,
struct V_6 , V_83 ) ;
struct V_17 * V_18 = & V_6 -> V_9 ;
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_80 * exp = V_6 -> V_88 ;
int V_11 ;
switch ( V_81 -> V_86 ) {
case V_91 :
if ( V_81 -> V_75 )
V_11 = F_9 ( V_8 , V_92 , 0x8000 ) ;
else
V_11 = F_10 ( V_8 , V_92 , 0x8000 ) ;
if ( V_11 < 0 )
return - V_20 ;
return 0 ;
case V_93 :
if ( V_81 -> V_75 <= V_81 -> V_94 ) {
unsigned long V_95 = V_81 -> V_94 - V_81 -> V_89 ;
V_11 = ( ( V_81 -> V_75 - ( T_4 ) V_81 -> V_89 ) * 8 + V_95 / 2 ) / V_95 ;
F_12 ( & V_8 -> V_13 , L_2 , V_11 ) ;
V_11 = F_7 ( V_8 , V_96 , V_11 ) ;
if ( V_11 < 0 )
return - V_20 ;
} else {
unsigned long V_95 = V_81 -> V_90 - V_81 -> V_94 - 1 ;
unsigned long V_97 = ( ( V_81 -> V_75 - ( T_4 ) V_81 -> V_94 - 1 ) *
111 + V_95 / 2 ) / V_95 + 9 ;
if ( V_97 <= 32 )
V_11 = V_97 ;
else if ( V_97 <= 64 )
V_11 = ( ( V_97 - 32 ) * 16 + 16 ) / 32 + 80 ;
else
V_11 = ( ( V_97 - 64 ) * 7 + 28 ) / 56 + 96 ;
F_12 ( & V_8 -> V_13 , L_3 ,
F_5 ( V_8 , V_96 ) , V_11 ) ;
V_11 = F_7 ( V_8 , V_96 , V_11 ) ;
if ( V_11 < 0 )
return - V_20 ;
}
return 0 ;
case V_87 :
if ( V_81 -> V_75 == V_98 ) {
unsigned long V_95 = exp -> V_90 - exp -> V_89 ;
unsigned long V_99 = ( ( exp -> V_75 - ( T_4 ) exp -> V_89 ) * 1048 +
V_95 / 2 ) / V_95 + 1 ;
F_12 ( & V_8 -> V_13 ,
L_4 ,
F_5 ( V_8 , V_50 ) , V_99 ) ;
if ( F_7 ( V_8 , V_50 , V_99 ) < 0 )
return - V_20 ;
} else {
const T_3 V_27 = 25 ;
V_6 -> V_40 = V_6 -> V_24 . V_30 +
V_6 -> V_41 + V_27 ;
if ( F_7 ( V_8 , V_50 , V_6 -> V_40 ) < 0 )
return - V_20 ;
}
return 0 ;
}
return - V_65 ;
}
static int F_32 ( struct V_77 * V_78 ,
struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
T_4 V_11 ;
unsigned long V_100 ;
int V_12 ;
V_12 = F_27 ( & V_6 -> V_9 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_11 = F_7 ( V_8 , V_101 , 1 ) ;
F_12 ( & V_8 -> V_13 , L_5 , V_11 ) ;
V_11 = F_5 ( V_8 , V_102 ) ;
switch ( V_11 ) {
case 0x8411 :
case 0x8421 :
V_6 -> V_28 = V_29 ;
break;
case 0x8431 :
V_6 -> V_28 = V_103 ;
break;
default:
F_33 ( & V_8 -> V_13 ,
L_6 , V_11 ) ;
V_12 = - V_104 ;
goto V_105;
}
V_6 -> V_69 = 0 ;
if ( V_78 -> V_106 )
V_100 = V_78 -> V_106 ( V_78 ) ;
else
V_100 = V_107 ;
if ( V_100 & V_107 )
V_6 -> V_69 ++ ;
else
V_6 -> V_28 ++ ;
if ( V_100 & V_108 )
V_6 -> V_69 ++ ;
V_6 -> V_3 = & V_6 -> V_28 [ 0 ] ;
F_34 ( & V_8 -> V_13 , L_7 , V_11 ,
V_11 == 0x8431 ? L_8 : L_9 ) ;
V_12 = F_11 ( V_8 ) ;
if ( V_12 < 0 ) {
F_33 ( & V_8 -> V_13 , L_10 ) ;
goto V_105;
}
V_12 = F_35 ( & V_6 -> V_83 ) ;
V_105:
F_27 ( & V_6 -> V_9 , 0 ) ;
return V_12 ;
}
static void F_36 ( struct V_77 * V_78 )
{
if ( V_78 -> V_109 )
V_78 -> V_109 ( V_78 ) ;
}
static int F_37 ( struct V_17 * V_18 , T_1 * V_110 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
* V_110 = V_6 -> V_41 ;
return 0 ;
}
static int F_38 ( struct V_17 * V_18 ,
struct V_58 * V_59 ,
struct V_111 * V_2 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
if ( V_2 -> V_64 || V_2 -> V_112 >= V_6 -> V_69 )
return - V_65 ;
V_2 -> V_2 = V_6 -> V_28 [ V_2 -> V_112 ] . V_2 ;
return 0 ;
}
static int F_39 ( struct V_17 * V_18 ,
struct V_113 * V_59 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_77 * V_78 = F_28 ( V_8 ) ;
V_59 -> V_100 = V_114 |
V_115 | V_116 |
V_117 | V_118 ;
V_59 -> type = V_119 ;
V_59 -> V_100 = F_40 ( V_78 , V_59 ) ;
return 0 ;
}
static int F_41 ( struct V_17 * V_18 ,
const struct V_113 * V_59 )
{
const struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_77 * V_78 = F_28 ( V_8 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
unsigned int V_120 = F_42 ( V_6 -> V_3 -> V_2 ) -> V_121 ;
if ( V_78 -> V_122 )
return V_78 -> V_122 ( V_78 , 1 << ( V_120 - 1 ) ) ;
return V_120 == 10 ? 0 : - V_65 ;
}
static int F_43 ( struct V_7 * V_8 ,
const struct V_123 * V_124 )
{
struct V_6 * V_6 ;
struct V_125 * V_126 = F_44 ( V_8 -> V_13 . V_127 ) ;
struct V_77 * V_78 = F_28 ( V_8 ) ;
int V_12 ;
if ( ! V_78 ) {
F_33 ( & V_8 -> V_13 , L_11 ) ;
return - V_65 ;
}
if ( ! F_45 ( V_126 , V_128 ) ) {
F_46 ( & V_126 -> V_13 ,
L_12 ) ;
return - V_20 ;
}
V_6 = F_47 ( & V_8 -> V_13 , sizeof( struct V_6 ) , V_129 ) ;
if ( ! V_6 )
return - V_130 ;
F_48 ( & V_6 -> V_9 , V_8 , & V_131 ) ;
F_49 ( & V_6 -> V_83 , 4 ) ;
F_50 ( & V_6 -> V_83 , & V_132 ,
V_91 , 0 , 1 , 1 , 0 ) ;
F_50 ( & V_6 -> V_83 , & V_132 ,
V_93 , 0 , 127 , 1 , 64 ) ;
V_6 -> V_88 = F_50 ( & V_6 -> V_83 , & V_132 ,
V_133 , 1 , 255 , 1 , 255 ) ;
V_6 -> V_48 = F_51 ( & V_6 -> V_83 ,
& V_132 , V_87 , 1 , 0 ,
V_49 ) ;
V_6 -> V_9 . V_134 = & V_6 -> V_83 ;
if ( V_6 -> V_83 . error )
return V_6 -> V_83 . error ;
F_52 ( 2 , & V_6 -> V_48 ,
V_98 , true ) ;
V_6 -> V_41 = 0 ;
V_6 -> V_24 . V_32 = V_33 ;
V_6 -> V_24 . V_36 = V_37 ;
V_6 -> V_24 . V_31 = V_35 ;
V_6 -> V_24 . V_30 = V_39 ;
V_6 -> V_79 = F_53 ( & V_8 -> V_13 , L_13 ) ;
if ( F_54 ( V_6 -> V_79 ) ) {
V_12 = F_55 ( V_6 -> V_79 ) ;
goto V_135;
}
V_12 = F_32 ( V_78 , V_8 ) ;
if ( V_12 ) {
F_56 ( V_6 -> V_79 ) ;
V_135:
F_57 ( & V_6 -> V_83 ) ;
}
return V_12 ;
}
static int F_58 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_77 * V_78 = F_28 ( V_8 ) ;
F_56 ( V_6 -> V_79 ) ;
F_59 ( & V_6 -> V_9 ) ;
F_57 ( & V_6 -> V_83 ) ;
F_36 ( V_78 ) ;
return 0 ;
}
