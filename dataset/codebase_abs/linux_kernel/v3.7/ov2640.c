static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 ,
V_4 ) ;
}
static int F_4 ( struct V_2 * V_3 ,
const struct V_5 * V_6 )
{
int V_7 ;
while ( ( V_6 -> V_8 != 0xff ) || ( V_6 -> V_9 != 0xff ) ) {
V_7 = F_5 ( V_3 ,
V_6 -> V_8 , V_6 -> V_9 ) ;
F_6 ( & V_3 -> V_10 , L_1 ,
V_6 -> V_8 , V_6 -> V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 ++ ;
}
return 0 ;
}
static int F_7 ( struct V_2 * V_3 ,
T_1 V_11 , T_1 V_12 , T_1 V_13 )
{
T_2 V_14 = F_8 ( V_3 , V_11 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= ~ V_12 ;
V_14 |= V_13 & V_12 ;
F_6 ( & V_3 -> V_10 , L_2 , V_11 , V_14 ) ;
return F_5 ( V_3 , V_11 , V_14 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
int V_7 ;
const struct V_5 V_15 [] = {
{ V_16 , V_17 } ,
{ V_18 , V_19 } ,
V_20 ,
} ;
V_7 = F_4 ( V_3 , V_15 ) ;
if ( V_7 )
goto V_21;
F_10 ( 5 ) ;
V_21:
F_11 ( & V_3 -> V_10 , L_3 , V_22 , V_7 ) ;
return V_7 ;
}
static int F_12 ( struct V_23 * V_24 , int V_25 )
{
return 0 ;
}
static int F_13 ( struct V_26 * V_27 )
{
struct V_23 * V_24 =
& F_2 ( V_27 -> V_28 , struct V_1 , V_29 ) -> V_4 ;
struct V_2 * V_3 = F_14 ( V_24 ) ;
T_1 V_14 ;
int V_7 ;
V_7 = F_5 ( V_3 , V_16 , V_17 ) ;
if ( V_7 < 0 )
return V_7 ;
switch ( V_27 -> V_30 ) {
case V_31 :
V_14 = V_27 -> V_14 ? V_32 : 0x00 ;
return F_7 ( V_3 , V_33 , V_32 , V_14 ) ;
case V_34 :
V_14 = V_27 -> V_14 ? V_35 : 0x00 ;
return F_7 ( V_3 , V_33 , V_35 , V_14 ) ;
}
return - V_36 ;
}
static int F_15 ( struct V_23 * V_24 ,
struct V_37 * V_30 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
struct V_1 * V_38 = F_1 ( V_3 ) ;
V_30 -> V_39 = V_38 -> V_40 ;
V_30 -> V_41 = 0 ;
return 0 ;
}
static int F_16 ( struct V_23 * V_24 ,
struct V_42 * V_11 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
int V_7 ;
V_11 -> V_43 = 1 ;
if ( V_11 -> V_11 > 0xff )
return - V_36 ;
V_7 = F_8 ( V_3 , V_11 -> V_11 ) ;
if ( V_7 < 0 )
return V_7 ;
V_11 -> V_14 = V_7 ;
return 0 ;
}
static int F_17 ( struct V_23 * V_24 ,
struct V_42 * V_11 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
if ( V_11 -> V_11 > 0xff ||
V_11 -> V_14 > 0xff )
return - V_36 ;
return F_5 ( V_3 , V_11 -> V_11 , V_11 -> V_14 ) ;
}
static int F_18 ( struct V_23 * V_24 , int V_44 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
struct V_45 * V_46 = F_19 ( V_3 ) ;
return F_20 ( & V_3 -> V_10 , V_46 , V_44 ) ;
}
static const struct V_47 * F_21 ( T_3 * V_48 , T_3 * V_49 )
{
int V_50 , V_51 = F_22 ( V_52 ) - 1 ;
for ( V_50 = 0 ; V_50 < F_22 ( V_52 ) ; V_50 ++ ) {
if ( V_52 [ V_50 ] . V_48 >= * V_48 &&
V_52 [ V_50 ] . V_49 >= * V_49 ) {
* V_48 = V_52 [ V_50 ] . V_48 ;
* V_49 = V_52 [ V_50 ] . V_49 ;
return & V_52 [ V_50 ] ;
}
}
* V_48 = V_52 [ V_51 ] . V_48 ;
* V_49 = V_52 [ V_51 ] . V_49 ;
return & V_52 [ V_51 ] ;
}
static int F_23 ( struct V_2 * V_3 , T_3 * V_48 , T_3 * V_49 ,
enum V_53 V_54 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
const struct V_5 * V_55 ;
int V_7 ;
V_38 -> V_56 = F_21 ( V_48 , V_49 ) ;
V_38 -> V_57 = 0 ;
switch ( V_54 ) {
case V_58 :
F_11 ( & V_3 -> V_10 , L_4 , V_22 ) ;
V_55 = V_59 ;
break;
default:
case V_60 :
F_11 ( & V_3 -> V_10 , L_5 , V_22 ) ;
V_55 = V_61 ;
}
F_9 ( V_3 ) ;
F_11 ( & V_3 -> V_10 , L_6 , V_22 ) ;
V_7 = F_4 ( V_3 , V_62 ) ;
if ( V_7 < 0 )
goto V_21;
F_11 ( & V_3 -> V_10 , L_7 , V_22 , V_38 -> V_56 -> V_63 ) ;
V_7 = F_4 ( V_3 , V_64 ) ;
if ( V_7 < 0 )
goto V_21;
V_7 = F_4 ( V_3 , V_38 -> V_56 -> V_65 ) ;
if ( V_7 < 0 )
goto V_21;
F_11 ( & V_3 -> V_10 , L_8 , V_22 ) ;
V_7 = F_4 ( V_3 , V_66 ) ;
if ( V_7 < 0 )
goto V_21;
V_7 = F_4 ( V_3 , V_55 ) ;
if ( V_7 < 0 )
goto V_21;
V_38 -> V_57 = V_54 ;
* V_48 = V_38 -> V_56 -> V_48 ;
* V_49 = V_38 -> V_56 -> V_49 ;
return 0 ;
V_21:
F_24 ( & V_3 -> V_10 , L_9 , V_22 , V_7 ) ;
F_9 ( V_3 ) ;
V_38 -> V_56 = NULL ;
return V_7 ;
}
static int F_25 ( struct V_23 * V_24 ,
struct V_67 * V_68 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
struct V_1 * V_38 = F_1 ( V_3 ) ;
if ( ! V_38 -> V_56 ) {
T_3 V_48 = V_69 , V_49 = V_70 ;
V_38 -> V_56 = F_21 ( & V_48 , & V_49 ) ;
V_38 -> V_57 = V_60 ;
}
V_68 -> V_48 = V_38 -> V_56 -> V_48 ;
V_68 -> V_49 = V_38 -> V_56 -> V_49 ;
V_68 -> V_54 = V_38 -> V_57 ;
switch ( V_68 -> V_54 ) {
case V_58 :
V_68 -> V_71 = V_72 ;
break;
default:
case V_60 :
V_68 -> V_71 = V_73 ;
}
V_68 -> V_74 = V_75 ;
return 0 ;
}
static int F_26 ( struct V_23 * V_24 ,
struct V_67 * V_68 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
int V_7 ;
switch ( V_68 -> V_54 ) {
case V_58 :
V_68 -> V_71 = V_72 ;
break;
default:
V_68 -> V_54 = V_60 ;
case V_60 :
V_68 -> V_71 = V_73 ;
}
V_7 = F_23 ( V_3 , & V_68 -> V_48 , & V_68 -> V_49 , V_68 -> V_54 ) ;
return V_7 ;
}
static int F_27 ( struct V_23 * V_24 ,
struct V_67 * V_68 )
{
const struct V_47 * V_56 ;
V_56 = F_21 ( & V_68 -> V_48 , & V_68 -> V_49 ) ;
V_68 -> V_74 = V_75 ;
switch ( V_68 -> V_54 ) {
case V_58 :
V_68 -> V_71 = V_72 ;
break;
default:
V_68 -> V_54 = V_60 ;
case V_60 :
V_68 -> V_71 = V_73 ;
}
return 0 ;
}
static int F_28 ( struct V_23 * V_24 , unsigned int V_76 ,
enum V_53 * V_54 )
{
if ( V_76 >= F_22 ( V_77 ) )
return - V_36 ;
* V_54 = V_77 [ V_76 ] ;
return 0 ;
}
static int F_29 ( struct V_23 * V_24 , struct V_78 * V_79 )
{
V_79 -> V_80 . V_81 = 0 ;
V_79 -> V_80 . V_82 = 0 ;
V_79 -> V_80 . V_48 = V_83 ;
V_79 -> V_80 . V_49 = V_84 ;
V_79 -> type = V_85 ;
return 0 ;
}
static int F_30 ( struct V_23 * V_24 , struct V_86 * V_79 )
{
V_79 -> V_87 . V_81 = 0 ;
V_79 -> V_87 . V_82 = 0 ;
V_79 -> V_87 . V_48 = V_83 ;
V_79 -> V_87 . V_49 = V_84 ;
V_79 -> V_88 = V_79 -> V_87 ;
V_79 -> type = V_85 ;
V_79 -> V_89 . V_90 = 1 ;
V_79 -> V_89 . V_91 = 1 ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
T_1 V_92 , V_93 , V_94 , V_95 ;
const char * V_96 ;
int V_7 ;
V_7 = F_18 ( & V_38 -> V_4 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
F_5 ( V_3 , V_16 , V_17 ) ;
V_92 = F_8 ( V_3 , V_97 ) ;
V_93 = F_8 ( V_3 , V_98 ) ;
V_94 = F_8 ( V_3 , V_99 ) ;
V_95 = F_8 ( V_3 , V_100 ) ;
switch ( F_32 ( V_92 , V_93 ) ) {
case V_101 :
V_96 = L_10 ;
V_38 -> V_40 = V_102 ;
break;
default:
F_24 ( & V_3 -> V_10 ,
L_11 , V_92 , V_93 ) ;
V_7 = - V_103 ;
goto V_104;
}
F_33 ( & V_3 -> V_10 ,
L_12 ,
V_96 , V_92 , V_93 , V_94 , V_95 ) ;
V_7 = F_34 ( & V_38 -> V_29 ) ;
V_104:
F_18 ( & V_38 -> V_4 , 0 ) ;
return V_7 ;
}
static int F_35 ( struct V_23 * V_24 ,
struct V_105 * V_106 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
struct V_45 * V_46 = F_19 ( V_3 ) ;
V_106 -> V_107 = V_108 | V_109 |
V_110 | V_111 |
V_112 ;
V_106 -> type = V_113 ;
V_106 -> V_107 = F_36 ( V_46 , V_106 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 ,
const struct V_114 * V_115 )
{
struct V_1 * V_38 ;
struct V_45 * V_46 = F_19 ( V_3 ) ;
struct V_116 * V_117 = F_38 ( V_3 -> V_10 . V_118 ) ;
int V_7 ;
if ( ! V_46 ) {
F_24 ( & V_117 -> V_10 ,
L_13 ) ;
return - V_36 ;
}
if ( ! F_39 ( V_117 , V_119 ) ) {
F_24 ( & V_117 -> V_10 ,
L_14 ) ;
return - V_120 ;
}
V_38 = F_40 ( sizeof( struct V_1 ) , V_121 ) ;
if ( ! V_38 ) {
F_24 ( & V_117 -> V_10 ,
L_15 ) ;
return - V_122 ;
}
F_41 ( & V_38 -> V_4 , V_3 , & V_123 ) ;
F_42 ( & V_38 -> V_29 , 2 ) ;
F_43 ( & V_38 -> V_29 , & V_124 ,
V_31 , 0 , 1 , 1 , 0 ) ;
F_43 ( & V_38 -> V_29 , & V_124 ,
V_34 , 0 , 1 , 1 , 0 ) ;
V_38 -> V_4 . V_125 = & V_38 -> V_29 ;
if ( V_38 -> V_29 . error ) {
int V_21 = V_38 -> V_29 . error ;
F_44 ( V_38 ) ;
return V_21 ;
}
V_7 = F_31 ( V_3 ) ;
if ( V_7 ) {
F_45 ( & V_38 -> V_29 ) ;
F_44 ( V_38 ) ;
} else {
F_33 ( & V_117 -> V_10 , L_16 ) ;
}
return V_7 ;
}
static int F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
F_47 ( & V_38 -> V_4 ) ;
F_45 ( & V_38 -> V_29 ) ;
F_44 ( V_38 ) ;
return 0 ;
}
