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
struct V_58 * V_59 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
V_59 -> V_31 = V_6 -> V_24 . V_31 ;
V_59 -> V_30 = V_6 -> V_24 . V_30 ;
V_59 -> V_2 = V_6 -> V_3 -> V_2 ;
V_59 -> V_60 = V_6 -> V_3 -> V_60 ;
V_59 -> V_61 = V_62 ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 ,
struct V_58 * V_59 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_21 V_22 = {
. V_25 = {
. V_32 = V_6 -> V_24 . V_32 ,
. V_36 = V_6 -> V_24 . V_36 ,
. V_31 = V_59 -> V_31 ,
. V_30 = V_59 -> V_30 ,
} ,
} ;
int V_12 ;
V_12 = F_15 ( V_18 , & V_22 ) ;
if ( ! V_12 ) {
V_59 -> V_31 = V_6 -> V_24 . V_31 ;
V_59 -> V_30 = V_6 -> V_24 . V_30 ;
V_6 -> V_3 = F_1 ( V_59 -> V_2 ,
V_6 -> V_28 , V_6 -> V_63 ) ;
V_59 -> V_60 = V_6 -> V_3 -> V_60 ;
}
return V_12 ;
}
static int F_23 ( struct V_17 * V_18 ,
struct V_58 * V_59 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
const struct V_1 * V_3 ;
F_24 ( & V_59 -> V_31 , V_34 ,
V_35 , 1 ,
& V_59 -> V_30 , V_38 + V_6 -> V_41 ,
V_39 + V_6 -> V_41 , 0 , 0 ) ;
if ( V_6 -> V_28 == V_29 )
V_59 -> V_30 = F_16 ( V_59 -> V_30 - 1 , 2 ) ;
V_3 = F_1 ( V_59 -> V_2 , V_6 -> V_28 ,
V_6 -> V_63 ) ;
if ( ! V_3 ) {
V_3 = V_6 -> V_3 ;
V_59 -> V_2 = V_3 -> V_2 ;
}
V_59 -> V_60 = V_3 -> V_60 ;
return 0 ;
}
static int F_25 ( struct V_17 * V_18 ,
struct V_64 * V_10 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
if ( V_10 -> V_10 > 0xff )
return - V_65 ;
V_10 -> V_66 = 2 ;
V_10 -> V_67 = F_5 ( V_8 , V_10 -> V_10 ) ;
if ( V_10 -> V_67 > 0xffff )
return - V_20 ;
return 0 ;
}
static int F_26 ( struct V_17 * V_18 ,
const struct V_64 * V_10 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
if ( V_10 -> V_10 > 0xff )
return - V_65 ;
if ( F_7 ( V_8 , V_10 -> V_10 , V_10 -> V_67 ) < 0 )
return - V_20 ;
return 0 ;
}
static int F_27 ( struct V_17 * V_18 , int V_68 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_69 * V_70 = F_28 ( V_8 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
return F_29 ( & V_8 -> V_13 , V_70 , V_6 -> V_71 , V_68 ) ;
}
static int F_30 ( struct V_72 * V_73 )
{
struct V_6 * V_6 = F_3 ( V_73 -> V_74 ,
struct V_6 , V_75 ) ;
T_4 V_76 , V_77 ;
switch ( V_73 -> V_78 ) {
case V_79 :
V_76 = V_6 -> V_80 -> V_81 ;
V_77 = V_6 -> V_80 -> V_82 ;
V_6 -> V_80 -> V_67 =
( 524 + ( V_6 -> V_40 - 1 ) * ( V_77 - V_76 ) ) / 1048 + V_76 ;
break;
}
return 0 ;
}
static int F_31 ( struct V_72 * V_73 )
{
struct V_6 * V_6 = F_3 ( V_73 -> V_74 ,
struct V_6 , V_75 ) ;
struct V_17 * V_18 = & V_6 -> V_9 ;
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_72 * exp = V_6 -> V_80 ;
int V_11 ;
switch ( V_73 -> V_78 ) {
case V_83 :
if ( V_73 -> V_67 )
V_11 = F_9 ( V_8 , V_84 , 0x8000 ) ;
else
V_11 = F_10 ( V_8 , V_84 , 0x8000 ) ;
if ( V_11 < 0 )
return - V_20 ;
return 0 ;
case V_85 :
if ( V_73 -> V_67 <= V_73 -> V_86 ) {
unsigned long V_87 = V_73 -> V_86 - V_73 -> V_81 ;
V_11 = ( ( V_73 -> V_67 - ( T_4 ) V_73 -> V_81 ) * 8 + V_87 / 2 ) / V_87 ;
F_12 ( & V_8 -> V_13 , L_2 , V_11 ) ;
V_11 = F_7 ( V_8 , V_88 , V_11 ) ;
if ( V_11 < 0 )
return - V_20 ;
} else {
unsigned long V_87 = V_73 -> V_82 - V_73 -> V_86 - 1 ;
unsigned long V_89 = ( ( V_73 -> V_67 - ( T_4 ) V_73 -> V_86 - 1 ) *
111 + V_87 / 2 ) / V_87 + 9 ;
if ( V_89 <= 32 )
V_11 = V_89 ;
else if ( V_89 <= 64 )
V_11 = ( ( V_89 - 32 ) * 16 + 16 ) / 32 + 80 ;
else
V_11 = ( ( V_89 - 64 ) * 7 + 28 ) / 56 + 96 ;
F_12 ( & V_8 -> V_13 , L_3 ,
F_5 ( V_8 , V_88 ) , V_11 ) ;
V_11 = F_7 ( V_8 , V_88 , V_11 ) ;
if ( V_11 < 0 )
return - V_20 ;
}
return 0 ;
case V_79 :
if ( V_73 -> V_67 == V_90 ) {
unsigned long V_87 = exp -> V_82 - exp -> V_81 ;
unsigned long V_91 = ( ( exp -> V_67 - ( T_4 ) exp -> V_81 ) * 1048 +
V_87 / 2 ) / V_87 + 1 ;
F_12 ( & V_8 -> V_13 ,
L_4 ,
F_5 ( V_8 , V_50 ) , V_91 ) ;
if ( F_7 ( V_8 , V_50 , V_91 ) < 0 )
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
static int F_32 ( struct V_69 * V_70 ,
struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
T_4 V_11 ;
unsigned long V_92 ;
int V_12 ;
V_12 = F_27 ( & V_6 -> V_9 , 1 ) ;
if ( V_12 < 0 )
return V_12 ;
V_11 = F_7 ( V_8 , V_93 , 1 ) ;
F_12 ( & V_8 -> V_13 , L_5 , V_11 ) ;
V_11 = F_5 ( V_8 , V_94 ) ;
switch ( V_11 ) {
case 0x8411 :
case 0x8421 :
V_6 -> V_28 = V_29 ;
break;
case 0x8431 :
V_6 -> V_28 = V_95 ;
break;
default:
F_33 ( & V_8 -> V_13 ,
L_6 , V_11 ) ;
V_12 = - V_96 ;
goto V_97;
}
V_6 -> V_63 = 0 ;
if ( V_70 -> V_98 )
V_92 = V_70 -> V_98 ( V_70 ) ;
else
V_92 = V_99 ;
if ( V_92 & V_99 )
V_6 -> V_63 ++ ;
else
V_6 -> V_28 ++ ;
if ( V_92 & V_100 )
V_6 -> V_63 ++ ;
V_6 -> V_3 = & V_6 -> V_28 [ 0 ] ;
F_34 ( & V_8 -> V_13 , L_7 , V_11 ,
V_11 == 0x8431 ? L_8 : L_9 ) ;
V_12 = F_11 ( V_8 ) ;
if ( V_12 < 0 ) {
F_33 ( & V_8 -> V_13 , L_10 ) ;
goto V_97;
}
V_12 = F_35 ( & V_6 -> V_75 ) ;
V_97:
F_27 ( & V_6 -> V_9 , 0 ) ;
return V_12 ;
}
static void F_36 ( struct V_69 * V_70 )
{
if ( V_70 -> V_101 )
V_70 -> V_101 ( V_70 ) ;
}
static int F_37 ( struct V_17 * V_18 , T_1 * V_102 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
* V_102 = V_6 -> V_41 ;
return 0 ;
}
static int F_38 ( struct V_17 * V_18 , unsigned int V_103 ,
T_1 * V_2 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
if ( V_103 >= V_6 -> V_63 )
return - V_65 ;
* V_2 = V_6 -> V_28 [ V_103 ] . V_2 ;
return 0 ;
}
static int F_39 ( struct V_17 * V_18 ,
struct V_104 * V_105 )
{
struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_69 * V_70 = F_28 ( V_8 ) ;
V_105 -> V_92 = V_106 |
V_107 | V_108 |
V_109 | V_110 ;
V_105 -> type = V_111 ;
V_105 -> V_92 = F_40 ( V_70 , V_105 ) ;
return 0 ;
}
static int F_41 ( struct V_17 * V_18 ,
const struct V_104 * V_105 )
{
const struct V_7 * V_8 = F_14 ( V_18 ) ;
struct V_69 * V_70 = F_28 ( V_8 ) ;
struct V_6 * V_6 = F_2 ( V_8 ) ;
unsigned int V_112 = F_42 ( V_6 -> V_3 -> V_2 ) -> V_113 ;
if ( V_70 -> V_114 )
return V_70 -> V_114 ( V_70 , 1 << ( V_112 - 1 ) ) ;
return V_112 == 10 ? 0 : - V_65 ;
}
static int F_43 ( struct V_7 * V_8 ,
const struct V_115 * V_116 )
{
struct V_6 * V_6 ;
struct V_117 * V_118 = F_44 ( V_8 -> V_13 . V_119 ) ;
struct V_69 * V_70 = F_28 ( V_8 ) ;
int V_12 ;
if ( ! V_70 ) {
F_33 ( & V_8 -> V_13 , L_11 ) ;
return - V_65 ;
}
if ( ! F_45 ( V_118 , V_120 ) ) {
F_46 ( & V_118 -> V_13 ,
L_12 ) ;
return - V_20 ;
}
V_6 = F_47 ( & V_8 -> V_13 , sizeof( struct V_6 ) , V_121 ) ;
if ( ! V_6 )
return - V_122 ;
F_48 ( & V_6 -> V_9 , V_8 , & V_123 ) ;
F_49 ( & V_6 -> V_75 , 4 ) ;
F_50 ( & V_6 -> V_75 , & V_124 ,
V_83 , 0 , 1 , 1 , 0 ) ;
F_50 ( & V_6 -> V_75 , & V_124 ,
V_85 , 0 , 127 , 1 , 64 ) ;
V_6 -> V_80 = F_50 ( & V_6 -> V_75 , & V_124 ,
V_125 , 1 , 255 , 1 , 255 ) ;
V_6 -> V_48 = F_51 ( & V_6 -> V_75 ,
& V_124 , V_79 , 1 , 0 ,
V_49 ) ;
V_6 -> V_9 . V_126 = & V_6 -> V_75 ;
if ( V_6 -> V_75 . error )
return V_6 -> V_75 . error ;
F_52 ( 2 , & V_6 -> V_48 ,
V_90 , true ) ;
V_6 -> V_41 = 0 ;
V_6 -> V_24 . V_32 = V_33 ;
V_6 -> V_24 . V_36 = V_37 ;
V_6 -> V_24 . V_31 = V_35 ;
V_6 -> V_24 . V_30 = V_39 ;
V_6 -> V_71 = F_53 ( & V_8 -> V_13 , L_13 ) ;
if ( F_54 ( V_6 -> V_71 ) ) {
V_12 = F_55 ( V_6 -> V_71 ) ;
goto V_127;
}
V_12 = F_32 ( V_70 , V_8 ) ;
if ( V_12 ) {
F_56 ( V_6 -> V_71 ) ;
V_127:
F_57 ( & V_6 -> V_75 ) ;
}
return V_12 ;
}
static int F_58 ( struct V_7 * V_8 )
{
struct V_6 * V_6 = F_2 ( V_8 ) ;
struct V_69 * V_70 = F_28 ( V_8 ) ;
F_56 ( V_6 -> V_71 ) ;
F_59 ( & V_6 -> V_9 ) ;
F_57 ( & V_6 -> V_75 ) ;
F_36 ( V_70 ) ;
return 0 ;
}
