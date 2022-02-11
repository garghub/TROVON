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
static const struct V_44 * F_18 ( T_3 * V_45 , T_3 * V_46 )
{
int V_47 , V_48 = F_19 ( V_49 ) - 1 ;
for ( V_47 = 0 ; V_47 < F_19 ( V_49 ) ; V_47 ++ ) {
if ( V_49 [ V_47 ] . V_45 >= * V_45 &&
V_49 [ V_47 ] . V_46 >= * V_46 ) {
* V_45 = V_49 [ V_47 ] . V_45 ;
* V_46 = V_49 [ V_47 ] . V_46 ;
return & V_49 [ V_47 ] ;
}
}
* V_45 = V_49 [ V_48 ] . V_45 ;
* V_46 = V_49 [ V_48 ] . V_46 ;
return & V_49 [ V_48 ] ;
}
static int F_20 ( struct V_2 * V_3 , T_3 * V_45 , T_3 * V_46 ,
enum V_50 V_51 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
const struct V_5 * V_52 ;
int V_7 ;
V_38 -> V_53 = F_18 ( V_45 , V_46 ) ;
V_38 -> V_54 = 0 ;
switch ( V_51 ) {
case V_55 :
F_11 ( & V_3 -> V_10 , L_4 , V_22 ) ;
V_52 = V_56 ;
break;
default:
case V_57 :
F_11 ( & V_3 -> V_10 , L_5 , V_22 ) ;
V_52 = V_58 ;
}
F_9 ( V_3 ) ;
F_11 ( & V_3 -> V_10 , L_6 , V_22 ) ;
V_7 = F_4 ( V_3 , V_59 ) ;
if ( V_7 < 0 )
goto V_21;
F_11 ( & V_3 -> V_10 , L_7 , V_22 , V_38 -> V_53 -> V_60 ) ;
V_7 = F_4 ( V_3 , V_61 ) ;
if ( V_7 < 0 )
goto V_21;
V_7 = F_4 ( V_3 , V_38 -> V_53 -> V_62 ) ;
if ( V_7 < 0 )
goto V_21;
F_11 ( & V_3 -> V_10 , L_8 , V_22 ) ;
V_7 = F_4 ( V_3 , V_63 ) ;
if ( V_7 < 0 )
goto V_21;
V_7 = F_4 ( V_3 , V_52 ) ;
if ( V_7 < 0 )
goto V_21;
V_38 -> V_54 = V_51 ;
* V_45 = V_38 -> V_53 -> V_45 ;
* V_46 = V_38 -> V_53 -> V_46 ;
return 0 ;
V_21:
F_21 ( & V_3 -> V_10 , L_9 , V_22 , V_7 ) ;
F_9 ( V_3 ) ;
V_38 -> V_53 = NULL ;
return V_7 ;
}
static int F_22 ( struct V_23 * V_24 ,
struct V_64 * V_65 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
struct V_1 * V_38 = F_1 ( V_3 ) ;
if ( ! V_38 -> V_53 ) {
T_3 V_45 = V_66 , V_46 = V_67 ;
V_38 -> V_53 = F_18 ( & V_45 , & V_46 ) ;
V_38 -> V_54 = V_57 ;
}
V_65 -> V_45 = V_38 -> V_53 -> V_45 ;
V_65 -> V_46 = V_38 -> V_53 -> V_46 ;
V_65 -> V_51 = V_38 -> V_54 ;
switch ( V_65 -> V_51 ) {
case V_55 :
V_65 -> V_68 = V_69 ;
break;
default:
case V_57 :
V_65 -> V_68 = V_70 ;
}
V_65 -> V_71 = V_72 ;
return 0 ;
}
static int F_23 ( struct V_23 * V_24 ,
struct V_64 * V_65 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
int V_7 ;
switch ( V_65 -> V_51 ) {
case V_55 :
V_65 -> V_68 = V_69 ;
break;
default:
V_65 -> V_51 = V_57 ;
case V_57 :
V_65 -> V_68 = V_70 ;
}
V_7 = F_20 ( V_3 , & V_65 -> V_45 , & V_65 -> V_46 , V_65 -> V_51 ) ;
return V_7 ;
}
static int F_24 ( struct V_23 * V_24 ,
struct V_64 * V_65 )
{
const struct V_44 * V_53 ;
V_53 = F_18 ( & V_65 -> V_45 , & V_65 -> V_46 ) ;
V_65 -> V_71 = V_72 ;
switch ( V_65 -> V_51 ) {
case V_55 :
V_65 -> V_68 = V_69 ;
break;
default:
V_65 -> V_51 = V_57 ;
case V_57 :
V_65 -> V_68 = V_70 ;
}
return 0 ;
}
static int F_25 ( struct V_23 * V_24 , unsigned int V_73 ,
enum V_50 * V_51 )
{
if ( V_73 >= F_19 ( V_74 ) )
return - V_36 ;
* V_51 = V_74 [ V_73 ] ;
return 0 ;
}
static int F_26 ( struct V_23 * V_24 , struct V_75 * V_76 )
{
V_76 -> V_77 . V_78 = 0 ;
V_76 -> V_77 . V_79 = 0 ;
V_76 -> V_77 . V_45 = V_80 ;
V_76 -> V_77 . V_46 = V_81 ;
V_76 -> type = V_82 ;
return 0 ;
}
static int F_27 ( struct V_23 * V_24 , struct V_83 * V_76 )
{
V_76 -> V_84 . V_78 = 0 ;
V_76 -> V_84 . V_79 = 0 ;
V_76 -> V_84 . V_45 = V_80 ;
V_76 -> V_84 . V_46 = V_81 ;
V_76 -> V_85 = V_76 -> V_84 ;
V_76 -> type = V_82 ;
V_76 -> V_86 . V_87 = 1 ;
V_76 -> V_86 . V_88 = 1 ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
T_1 V_89 , V_90 , V_91 , V_92 ;
const char * V_93 ;
int V_7 ;
F_5 ( V_3 , V_16 , V_17 ) ;
V_89 = F_8 ( V_3 , V_94 ) ;
V_90 = F_8 ( V_3 , V_95 ) ;
V_91 = F_8 ( V_3 , V_96 ) ;
V_92 = F_8 ( V_3 , V_97 ) ;
switch ( F_29 ( V_89 , V_90 ) ) {
case V_98 :
V_93 = L_10 ;
V_38 -> V_40 = V_99 ;
break;
default:
F_21 ( & V_3 -> V_10 ,
L_11 , V_89 , V_90 ) ;
V_7 = - V_100 ;
goto V_21;
}
F_30 ( & V_3 -> V_10 ,
L_12 ,
V_93 , V_89 , V_90 , V_91 , V_92 ) ;
return F_31 ( & V_38 -> V_29 ) ;
V_21:
return V_7 ;
}
static int F_32 ( struct V_23 * V_24 ,
struct V_101 * V_102 )
{
struct V_2 * V_3 = F_14 ( V_24 ) ;
struct V_103 * V_104 = F_33 ( V_3 ) ;
V_102 -> V_105 = V_106 | V_107 |
V_108 | V_109 |
V_110 ;
V_102 -> type = V_111 ;
V_102 -> V_105 = F_34 ( V_104 , V_102 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 ,
const struct V_112 * V_113 )
{
struct V_1 * V_38 ;
struct V_103 * V_104 = F_33 ( V_3 ) ;
struct V_114 * V_115 = F_36 ( V_3 -> V_10 . V_116 ) ;
int V_7 ;
if ( ! V_104 ) {
F_21 ( & V_115 -> V_10 ,
L_13 ) ;
return - V_36 ;
}
if ( ! F_37 ( V_115 , V_117 ) ) {
F_21 ( & V_115 -> V_10 ,
L_14 ) ;
return - V_118 ;
}
V_38 = F_38 ( sizeof( struct V_1 ) , V_119 ) ;
if ( ! V_38 ) {
F_21 ( & V_115 -> V_10 ,
L_15 ) ;
return - V_120 ;
}
F_39 ( & V_38 -> V_4 , V_3 , & V_121 ) ;
F_40 ( & V_38 -> V_29 , 2 ) ;
F_41 ( & V_38 -> V_29 , & V_122 ,
V_31 , 0 , 1 , 1 , 0 ) ;
F_41 ( & V_38 -> V_29 , & V_122 ,
V_34 , 0 , 1 , 1 , 0 ) ;
V_38 -> V_4 . V_123 = & V_38 -> V_29 ;
if ( V_38 -> V_29 . error ) {
int V_21 = V_38 -> V_29 . error ;
F_42 ( V_38 ) ;
return V_21 ;
}
V_7 = F_28 ( V_3 ) ;
if ( V_7 ) {
F_43 ( & V_38 -> V_29 ) ;
F_42 ( V_38 ) ;
} else {
F_30 ( & V_115 -> V_10 , L_16 ) ;
}
return V_7 ;
}
static int F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_38 = F_1 ( V_3 ) ;
F_45 ( & V_38 -> V_4 ) ;
F_43 ( & V_38 -> V_29 ) ;
F_42 ( V_38 ) ;
return 0 ;
}
