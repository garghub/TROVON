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
static int F_15 ( struct V_17 * V_18 ,
struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_25 V_26 = V_24 -> V_27 ;
const T_3 V_28 = 9 , V_29 = 25 ;
int V_12 ;
if ( V_24 -> V_30 != V_31 ||
V_24 -> V_32 != V_33 )
return - V_34 ;
if ( V_6 -> V_35 == V_36 )
V_26 . V_37 = F_16 ( V_26 . V_37 , 2 ) ;
V_26 . V_38 = F_16 ( V_26 . V_38 , 2 ) ;
V_26 . V_39 = F_16 ( V_26 . V_39 , 2 ) ;
F_17 ( & V_26 . V_39 , & V_26 . V_38 ,
V_40 , V_41 , V_42 ) ;
F_17 ( & V_26 . V_43 , & V_26 . V_37 ,
V_44 , V_45 , V_46 ) ;
V_6 -> V_47 = V_26 . V_37 + V_6 -> V_48 + V_29 ;
V_12 = F_7 ( V_8 , V_49 , V_28 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_50 , V_29 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_51 , V_26 . V_39 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_52 , V_26 . V_43 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_53 , V_26 . V_38 - 1 ) ;
if ( ! V_12 )
V_12 = F_7 ( V_8 , V_54 ,
V_26 . V_37 + V_6 -> V_48 - 1 ) ;
if ( ! V_12 && F_18 ( V_6 -> V_55 ) == V_56 )
V_12 = F_7 ( V_8 , V_57 , V_6 -> V_47 ) ;
if ( ! V_12 )
V_6 -> V_26 = V_26 ;
return V_12 ;
}
static int F_19 ( struct V_17 * V_18 ,
struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
if ( V_24 -> V_30 != V_31 )
return - V_34 ;
switch ( V_24 -> V_32 ) {
case V_58 :
case V_59 :
V_24 -> V_27 . V_39 = V_40 ;
V_24 -> V_27 . V_43 = V_44 ;
V_24 -> V_27 . V_38 = V_42 ;
V_24 -> V_27 . V_37 = V_46 ;
return 0 ;
case V_33 :
V_24 -> V_27 = V_6 -> V_26 ;
return 0 ;
default:
return - V_34 ;
}
}
static int F_20 ( struct V_17 * V_18 ,
struct V_21 * V_22 ,
struct V_60 * V_61 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_62 * V_63 = & V_61 -> V_61 ;
if ( V_61 -> V_64 )
return - V_34 ;
V_63 -> V_38 = V_6 -> V_26 . V_38 ;
V_63 -> V_37 = V_6 -> V_26 . V_37 ;
V_63 -> V_2 = V_6 -> V_3 -> V_2 ;
V_63 -> V_65 = V_6 -> V_3 -> V_65 ;
V_63 -> V_66 = V_67 ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 ,
struct V_62 * V_63 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_23 V_24 = {
. V_30 = V_31 ,
. V_32 = V_33 ,
. V_27 . V_39 = V_6 -> V_26 . V_39 ,
. V_27 . V_43 = V_6 -> V_26 . V_43 ,
. V_27 . V_38 = V_63 -> V_38 ,
. V_27 . V_37 = V_63 -> V_37 ,
} ;
int V_12 ;
V_12 = F_15 ( V_18 , NULL , & V_24 ) ;
if ( ! V_12 ) {
V_63 -> V_38 = V_6 -> V_26 . V_38 ;
V_63 -> V_37 = V_6 -> V_26 . V_37 ;
V_6 -> V_3 = F_1 ( V_63 -> V_2 ,
V_6 -> V_35 , V_6 -> V_68 ) ;
V_63 -> V_65 = V_6 -> V_3 -> V_65 ;
}
return V_12 ;
}
static int F_22 ( struct V_17 * V_18 ,
struct V_21 * V_22 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = & V_61 -> V_61 ;
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
const struct V_1 * V_3 ;
if ( V_61 -> V_64 )
return - V_34 ;
F_23 ( & V_63 -> V_38 , V_41 ,
V_42 , 1 ,
& V_63 -> V_37 , V_45 + V_6 -> V_48 ,
V_46 + V_6 -> V_48 , 0 , 0 ) ;
if ( V_6 -> V_35 == V_36 )
V_63 -> V_37 = F_16 ( V_63 -> V_37 - 1 , 2 ) ;
V_3 = F_1 ( V_63 -> V_2 , V_6 -> V_35 ,
V_6 -> V_68 ) ;
if ( ! V_3 ) {
V_3 = V_6 -> V_3 ;
V_63 -> V_2 = V_3 -> V_2 ;
}
V_63 -> V_65 = V_3 -> V_65 ;
if ( V_61 -> V_30 == V_31 )
return F_21 ( V_18 , V_63 ) ;
V_22 -> V_69 = * V_63 ;
return 0 ;
}
static int F_24 ( struct V_17 * V_18 ,
struct V_70 * V_10 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
if ( V_10 -> V_10 > 0xff )
return - V_34 ;
V_10 -> V_71 = 2 ;
V_10 -> V_72 = F_5 ( V_8 , V_10 -> V_10 ) ;
if ( V_10 -> V_72 > 0xffff )
return - V_20 ;
return 0 ;
}
static int F_25 ( struct V_17 * V_18 ,
const struct V_70 * V_10 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
if ( V_10 -> V_10 > 0xff )
return - V_34 ;
if ( F_7 ( V_8 , V_10 -> V_10 , V_10 -> V_72 ) < 0 )
return - V_20 ;
return 0 ;
}
static int F_26 ( struct V_17 * V_18 , int V_73 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_74 * V_75 = F_27 ( V_8 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
return F_28 ( & V_8 -> V_13 , V_75 , V_6 -> V_76 , V_73 ) ;
}
static int F_29 ( struct V_77 * V_78 )
{
struct V_6 * V_6 = F_3 ( V_78 -> V_79 ,
struct V_6 , V_80 ) ;
T_4 V_81 , V_82 ;
switch ( V_78 -> V_83 ) {
case V_84 :
V_81 = V_6 -> V_85 -> V_86 ;
V_82 = V_6 -> V_85 -> V_87 ;
V_6 -> V_85 -> V_72 =
( 524 + ( V_6 -> V_47 - 1 ) * ( V_82 - V_81 ) ) / 1048 + V_81 ;
break;
}
return 0 ;
}
static int F_30 ( struct V_77 * V_78 )
{
struct V_6 * V_6 = F_3 ( V_78 -> V_79 ,
struct V_6 , V_80 ) ;
struct V_17 * V_18 = & V_6 -> V_9 ;
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_77 * exp = V_6 -> V_85 ;
int V_11 ;
switch ( V_78 -> V_83 ) {
case V_88 :
if ( V_78 -> V_72 )
V_11 = F_9 ( V_8 , V_89 , 0x8000 ) ;
else
V_11 = F_10 ( V_8 , V_89 , 0x8000 ) ;
if ( V_11 < 0 )
return - V_20 ;
return 0 ;
case V_90 :
if ( V_78 -> V_72 <= V_78 -> V_91 ) {
unsigned long V_92 = V_78 -> V_91 - V_78 -> V_86 ;
V_11 = ( ( V_78 -> V_72 - ( T_4 ) V_78 -> V_86 ) * 8 + V_92 / 2 ) / V_92 ;
F_12 ( & V_8 -> V_13 , L_2 , V_11 ) ;
V_11 = F_7 ( V_8 , V_93 , V_11 ) ;
if ( V_11 < 0 )
return - V_20 ;
} else {
unsigned long V_92 = V_78 -> V_87 - V_78 -> V_91 - 1 ;
unsigned long V_94 = ( ( V_78 -> V_72 - ( T_4 ) V_78 -> V_91 - 1 ) *
111 + V_92 / 2 ) / V_92 + 9 ;
if ( V_94 <= 32 )
V_11 = V_94 ;
else if ( V_94 <= 64 )
V_11 = ( ( V_94 - 32 ) * 16 + 16 ) / 32 + 80 ;
else
V_11 = ( ( V_94 - 64 ) * 7 + 28 ) / 56 + 96 ;
F_12 ( & V_8 -> V_13 , L_3 ,
F_5 ( V_8 , V_93 ) , V_11 ) ;
V_11 = F_7 ( V_8 , V_93 , V_11 ) ;
if ( V_11 < 0 )
return - V_20 ;
}
return 0 ;
case V_84 :
if ( V_78 -> V_72 == V_95 ) {
unsigned long V_92 = exp -> V_87 - exp -> V_86 ;
unsigned long V_96 = ( ( exp -> V_72 - ( T_4 ) exp -> V_86 ) * 1048 +
V_92 / 2 ) / V_92 + 1 ;
F_12 ( & V_8 -> V_13 ,
L_4 ,
F_5 ( V_8 , V_57 ) , V_96 ) ;
if ( F_7 ( V_8 , V_57 , V_96 ) < 0 )
return - V_20 ;
} else {
const T_3 V_29 = 25 ;
V_6 -> V_47 = V_6 -> V_26 . V_37 +
V_6 -> V_48 + V_29 ;
if ( F_7 ( V_8 , V_57 , V_6 -> V_47 ) < 0 )
return - V_20 ;
}
return 0 ;
}
return - V_34 ;
}
static int F_31 ( struct V_74 * V_75 ,
struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
T_4 V_11 ;
unsigned long V_97 ;
int V_12 ;
V_12 = F_26 ( & V_6 -> V_9 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_11 = F_7 ( V_8 , V_98 , 1 ) ;
F_12 ( & V_8 -> V_13 , L_5 , V_11 ) ;
V_11 = F_5 ( V_8 , V_99 ) ;
switch ( V_11 ) {
case 0x8411 :
case 0x8421 :
V_6 -> V_35 = V_36 ;
break;
case 0x8431 :
V_6 -> V_35 = V_100 ;
break;
default:
F_32 ( & V_8 -> V_13 ,
L_6 , V_11 ) ;
V_12 = - V_101 ;
goto V_102;
}
V_6 -> V_68 = 0 ;
if ( V_75 -> V_103 )
V_97 = V_75 -> V_103 ( V_75 ) ;
else
V_97 = V_104 ;
if ( V_97 & V_104 )
V_6 -> V_68 ++ ;
else
V_6 -> V_35 ++ ;
if ( V_97 & V_105 )
V_6 -> V_68 ++ ;
V_6 -> V_3 = & V_6 -> V_35 [ 0 ] ;
F_33 ( & V_8 -> V_13 , L_7 , V_11 ,
V_11 == 0x8431 ? L_8 : L_9 ) ;
V_12 = F_11 ( V_8 ) ;
if ( V_12 < 0 ) {
F_32 ( & V_8 -> V_13 , L_10 ) ;
goto V_102;
}
V_12 = F_34 ( & V_6 -> V_80 ) ;
V_102:
F_26 ( & V_6 -> V_9 , 0 ) ;
return V_12 ;
}
static void F_35 ( struct V_74 * V_75 )
{
if ( V_75 -> V_106 )
V_75 -> V_106 ( V_75 ) ;
}
static int F_36 ( struct V_17 * V_18 , T_1 * V_107 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
* V_107 = V_6 -> V_48 ;
return 0 ;
}
static int F_37 ( struct V_17 * V_18 ,
struct V_21 * V_22 ,
struct V_108 * V_2 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
if ( V_2 -> V_64 || V_2 -> V_109 >= V_6 -> V_68 )
return - V_34 ;
V_2 -> V_2 = V_6 -> V_35 [ V_2 -> V_109 ] . V_2 ;
return 0 ;
}
static int F_38 ( struct V_17 * V_18 ,
struct V_110 * V_22 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_74 * V_75 = F_27 ( V_8 ) ;
V_22 -> V_97 = V_111 |
V_112 | V_113 |
V_114 | V_115 ;
V_22 -> type = V_116 ;
V_22 -> V_97 = F_39 ( V_75 , V_22 ) ;
return 0 ;
}
static int F_40 ( struct V_17 * V_18 ,
const struct V_110 * V_22 )
{
const struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_74 * V_75 = F_27 ( V_8 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
unsigned int V_117 = F_41 ( V_6 -> V_3 -> V_2 ) -> V_118 ;
if ( V_75 -> V_119 )
return V_75 -> V_119 ( V_75 , 1 << ( V_117 - 1 ) ) ;
return V_117 == 10 ? 0 : - V_34 ;
}
static int F_42 ( struct V_7 * V_8 ,
const struct V_120 * V_121 )
{
struct V_6 * V_6 ;
struct V_122 * V_123 = F_43 ( V_8 -> V_13 . V_124 ) ;
struct V_74 * V_75 = F_27 ( V_8 ) ;
int V_12 ;
if ( ! V_75 ) {
F_32 ( & V_8 -> V_13 , L_11 ) ;
return - V_34 ;
}
if ( ! F_44 ( V_123 , V_125 ) ) {
F_45 ( & V_123 -> V_13 ,
L_12 ) ;
return - V_20 ;
}
V_6 = F_46 ( & V_8 -> V_13 , sizeof( struct V_6 ) , V_126 ) ;
if ( ! V_6 )
return - V_127 ;
F_47 ( & V_6 -> V_9 , V_8 , & V_128 ) ;
F_48 ( & V_6 -> V_80 , 4 ) ;
F_49 ( & V_6 -> V_80 , & V_129 ,
V_88 , 0 , 1 , 1 , 0 ) ;
F_49 ( & V_6 -> V_80 , & V_129 ,
V_90 , 0 , 127 , 1 , 64 ) ;
V_6 -> V_85 = F_49 ( & V_6 -> V_80 , & V_129 ,
V_130 , 1 , 255 , 1 , 255 ) ;
V_6 -> V_55 = F_50 ( & V_6 -> V_80 ,
& V_129 , V_84 , 1 , 0 ,
V_56 ) ;
V_6 -> V_9 . V_131 = & V_6 -> V_80 ;
if ( V_6 -> V_80 . error )
return V_6 -> V_80 . error ;
F_51 ( 2 , & V_6 -> V_55 ,
V_95 , true ) ;
V_6 -> V_48 = 0 ;
V_6 -> V_26 . V_39 = V_40 ;
V_6 -> V_26 . V_43 = V_44 ;
V_6 -> V_26 . V_38 = V_42 ;
V_6 -> V_26 . V_37 = V_46 ;
V_6 -> V_76 = F_52 ( & V_8 -> V_13 , L_13 ) ;
if ( F_53 ( V_6 -> V_76 ) ) {
V_12 = F_54 ( V_6 -> V_76 ) ;
goto V_132;
}
V_12 = F_31 ( V_75 , V_8 ) ;
if ( V_12 ) {
F_55 ( V_6 -> V_76 ) ;
V_132:
F_56 ( & V_6 -> V_80 ) ;
}
return V_12 ;
}
static int F_57 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_74 * V_75 = F_27 ( V_8 ) ;
F_55 ( V_6 -> V_76 ) ;
F_58 ( & V_6 -> V_9 ) ;
F_56 ( & V_6 -> V_80 ) ;
F_35 ( V_75 ) ;
return 0 ;
}
