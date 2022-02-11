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
struct V_65 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
if ( V_11 -> V_11 > 0xff )
return - V_66 ;
V_11 -> V_67 = 2 ;
V_11 -> V_68 = F_5 ( V_9 , V_11 -> V_11 ) ;
if ( V_11 -> V_68 > 0xffff )
return - V_21 ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 ,
const struct V_65 * V_11 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
if ( V_11 -> V_11 > 0xff )
return - V_66 ;
if ( F_7 ( V_9 , V_11 -> V_11 , V_11 -> V_68 ) < 0 )
return - V_21 ;
return 0 ;
}
static int F_27 ( struct V_18 * V_19 , int V_69 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_70 * V_71 = F_28 ( V_9 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
return F_29 ( & V_9 -> V_14 , V_71 , V_7 -> V_72 , V_69 ) ;
}
static int F_30 ( struct V_73 * V_74 )
{
struct V_7 * V_7 = F_3 ( V_74 -> V_75 ,
struct V_7 , V_76 ) ;
T_3 V_77 , V_78 ;
switch ( V_74 -> V_79 ) {
case V_80 :
V_77 = V_7 -> V_81 -> V_82 ;
V_78 = V_7 -> V_81 -> V_83 ;
V_7 -> V_81 -> V_68 =
( 524 + ( V_7 -> V_41 - 1 ) * ( V_78 - V_77 ) ) / 1048 + V_77 ;
break;
}
return 0 ;
}
static int F_31 ( struct V_73 * V_74 )
{
struct V_7 * V_7 = F_3 ( V_74 -> V_75 ,
struct V_7 , V_76 ) ;
struct V_18 * V_19 = & V_7 -> V_10 ;
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_73 * exp = V_7 -> V_81 ;
int V_12 ;
switch ( V_74 -> V_79 ) {
case V_84 :
if ( V_74 -> V_68 )
V_12 = F_9 ( V_9 , V_85 , 0x8000 ) ;
else
V_12 = F_10 ( V_9 , V_85 , 0x8000 ) ;
if ( V_12 < 0 )
return - V_21 ;
return 0 ;
case V_86 :
if ( V_74 -> V_68 <= V_74 -> V_87 ) {
unsigned long V_88 = V_74 -> V_87 - V_74 -> V_82 ;
V_12 = ( ( V_74 -> V_68 - ( T_3 ) V_74 -> V_82 ) * 8 + V_88 / 2 ) / V_88 ;
F_12 ( & V_9 -> V_14 , L_2 , V_12 ) ;
V_12 = F_7 ( V_9 , V_89 , V_12 ) ;
if ( V_12 < 0 )
return - V_21 ;
} else {
unsigned long V_88 = V_74 -> V_83 - V_74 -> V_87 - 1 ;
unsigned long V_90 = ( ( V_74 -> V_68 - ( T_3 ) V_74 -> V_87 - 1 ) *
111 + V_88 / 2 ) / V_88 + 9 ;
if ( V_90 <= 32 )
V_12 = V_90 ;
else if ( V_90 <= 64 )
V_12 = ( ( V_90 - 32 ) * 16 + 16 ) / 32 + 80 ;
else
V_12 = ( ( V_90 - 64 ) * 7 + 28 ) / 56 + 96 ;
F_12 ( & V_9 -> V_14 , L_3 ,
F_5 ( V_9 , V_89 ) , V_12 ) ;
V_12 = F_7 ( V_9 , V_89 , V_12 ) ;
if ( V_12 < 0 )
return - V_21 ;
}
return 0 ;
case V_80 :
if ( V_74 -> V_68 == V_91 ) {
unsigned long V_88 = exp -> V_83 - exp -> V_82 ;
unsigned long V_92 = ( ( exp -> V_68 - ( T_3 ) exp -> V_82 ) * 1048 +
V_88 / 2 ) / V_88 + 1 ;
F_12 ( & V_9 -> V_14 ,
L_4 ,
F_5 ( V_9 , V_51 ) , V_92 ) ;
if ( F_7 ( V_9 , V_51 , V_92 ) < 0 )
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
return - V_66 ;
}
static int F_32 ( struct V_70 * V_71 ,
struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
T_3 V_12 ;
unsigned long V_93 ;
int V_13 ;
V_13 = F_27 ( & V_7 -> V_10 , 1 ) ;
if ( V_13 < 0 )
return V_13 ;
V_12 = F_7 ( V_9 , V_94 , 1 ) ;
F_12 ( & V_9 -> V_14 , L_5 , V_12 ) ;
V_12 = F_5 ( V_9 , V_95 ) ;
switch ( V_12 ) {
case 0x8411 :
case 0x8421 :
V_7 -> V_29 = V_30 ;
break;
case 0x8431 :
V_7 -> V_29 = V_96 ;
break;
default:
F_33 ( & V_9 -> V_14 ,
L_6 , V_12 ) ;
V_13 = - V_97 ;
goto V_98;
}
V_7 -> V_64 = 0 ;
if ( V_71 -> V_99 )
V_93 = V_71 -> V_99 ( V_71 ) ;
else
V_93 = V_100 ;
if ( V_93 & V_100 )
V_7 -> V_64 ++ ;
else
V_7 -> V_29 ++ ;
if ( V_93 & V_101 )
V_7 -> V_64 ++ ;
V_7 -> V_4 = & V_7 -> V_29 [ 0 ] ;
F_34 ( & V_9 -> V_14 , L_7 , V_12 ,
V_12 == 0x8431 ? L_8 : L_9 ) ;
V_13 = F_11 ( V_9 ) ;
if ( V_13 < 0 ) {
F_33 ( & V_9 -> V_14 , L_10 ) ;
goto V_98;
}
V_13 = F_35 ( & V_7 -> V_76 ) ;
V_98:
F_27 ( & V_7 -> V_10 , 0 ) ;
return V_13 ;
}
static void F_36 ( struct V_70 * V_71 )
{
if ( V_71 -> V_102 )
V_71 -> V_102 ( V_71 ) ;
}
static int F_37 ( struct V_18 * V_19 , T_4 * V_103 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
* V_103 = V_7 -> V_42 ;
return 0 ;
}
static int F_38 ( struct V_18 * V_19 , unsigned int V_104 ,
enum V_2 * V_3 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
if ( V_104 >= V_7 -> V_64 )
return - V_66 ;
* V_3 = V_7 -> V_29 [ V_104 ] . V_3 ;
return 0 ;
}
static int F_39 ( struct V_18 * V_19 ,
struct V_105 * V_106 )
{
struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_70 * V_71 = F_28 ( V_9 ) ;
V_106 -> V_93 = V_107 |
V_108 | V_109 |
V_110 | V_111 ;
V_106 -> type = V_112 ;
V_106 -> V_93 = F_40 ( V_71 , V_106 ) ;
return 0 ;
}
static int F_41 ( struct V_18 * V_19 ,
const struct V_105 * V_106 )
{
const struct V_8 * V_9 = F_14 ( V_19 ) ;
struct V_70 * V_71 = F_28 ( V_9 ) ;
struct V_7 * V_7 = F_2 ( V_9 ) ;
unsigned int V_113 = F_42 ( V_7 -> V_4 -> V_3 ) -> V_114 ;
if ( V_71 -> V_115 )
return V_71 -> V_115 ( V_71 , 1 << ( V_113 - 1 ) ) ;
return V_113 == 10 ? 0 : - V_66 ;
}
static int F_43 ( struct V_8 * V_9 ,
const struct V_116 * V_117 )
{
struct V_7 * V_7 ;
struct V_118 * V_119 = F_44 ( V_9 -> V_14 . V_120 ) ;
struct V_70 * V_71 = F_28 ( V_9 ) ;
int V_13 ;
if ( ! V_71 ) {
F_33 ( & V_9 -> V_14 , L_11 ) ;
return - V_66 ;
}
if ( ! F_45 ( V_119 , V_121 ) ) {
F_46 ( & V_119 -> V_14 ,
L_12 ) ;
return - V_21 ;
}
V_7 = F_47 ( & V_9 -> V_14 , sizeof( struct V_7 ) , V_122 ) ;
if ( ! V_7 )
return - V_123 ;
F_48 ( & V_7 -> V_10 , V_9 , & V_124 ) ;
F_49 ( & V_7 -> V_76 , 4 ) ;
F_50 ( & V_7 -> V_76 , & V_125 ,
V_84 , 0 , 1 , 1 , 0 ) ;
F_50 ( & V_7 -> V_76 , & V_125 ,
V_86 , 0 , 127 , 1 , 64 ) ;
V_7 -> V_81 = F_50 ( & V_7 -> V_76 , & V_125 ,
V_126 , 1 , 255 , 1 , 255 ) ;
V_7 -> V_49 = F_51 ( & V_7 -> V_76 ,
& V_125 , V_80 , 1 , 0 ,
V_50 ) ;
V_7 -> V_10 . V_127 = & V_7 -> V_76 ;
if ( V_7 -> V_76 . error )
return V_7 -> V_76 . error ;
F_52 ( 2 , & V_7 -> V_49 ,
V_91 , true ) ;
V_7 -> V_42 = 0 ;
V_7 -> V_25 . V_33 = V_34 ;
V_7 -> V_25 . V_37 = V_38 ;
V_7 -> V_25 . V_32 = V_36 ;
V_7 -> V_25 . V_31 = V_40 ;
V_7 -> V_72 = F_53 ( & V_9 -> V_14 , L_13 ) ;
if ( F_54 ( V_7 -> V_72 ) ) {
V_13 = F_55 ( V_7 -> V_72 ) ;
goto V_128;
}
V_13 = F_32 ( V_71 , V_9 ) ;
if ( V_13 ) {
F_56 ( V_7 -> V_72 ) ;
V_128:
F_57 ( & V_7 -> V_76 ) ;
}
return V_13 ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_2 ( V_9 ) ;
struct V_70 * V_71 = F_28 ( V_9 ) ;
F_56 ( V_7 -> V_72 ) ;
F_59 ( & V_7 -> V_10 ) ;
F_57 ( & V_7 -> V_76 ) ;
F_36 ( V_71 ) ;
return 0 ;
}
