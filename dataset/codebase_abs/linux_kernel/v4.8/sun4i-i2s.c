static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
int div = V_3 / V_4 / 2 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
const struct V_7 * V_8 = & V_6 [ V_5 ] ;
if ( V_8 -> div == div )
return V_8 -> V_9 ;
}
return - V_10 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_11 ,
unsigned int V_12 )
{
int div = V_11 / V_12 / V_3 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_13 ) ; V_5 ++ ) {
const struct V_7 * V_14 = & V_13 [ V_5 ] ;
if ( V_14 -> div == div )
return V_14 -> V_9 ;
}
return - V_10 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_15 ,
unsigned int V_4 )
{
unsigned int V_16 ;
int V_17 , V_18 ;
int V_19 , V_5 ;
switch ( V_15 ) {
case 176400 :
case 88200 :
case 44100 :
case 22050 :
case 11025 :
V_16 = 22579200 ;
break;
case 192000 :
case 128000 :
case 96000 :
case 64000 :
case 48000 :
case 32000 :
case 24000 :
case 16000 :
case 12000 :
case 8000 :
V_16 = 24576000 ;
break;
default:
return - V_10 ;
}
V_19 = F_5 ( V_2 -> V_20 , V_16 ) ;
if ( V_19 )
return V_19 ;
for ( V_5 = ( F_2 ( V_21 ) - 1 ) ; V_5 >= 0 ; V_5 -- ) {
unsigned int V_3 = V_21 [ V_5 ] ;
V_17 = F_1 ( V_2 , V_3 ,
V_4 ) ;
V_18 = F_3 ( V_2 , V_3 ,
V_16 ,
V_15 ) ;
if ( ( V_17 >= 0 ) && ( V_18 >= 0 ) )
break;
}
if ( ( V_17 < 0 ) || ( V_18 < 0 ) )
return - V_10 ;
F_6 ( V_2 -> V_22 , V_23 ,
F_7 ( V_17 ) |
F_8 ( V_18 ) |
V_24 ) ;
return 0 ;
}
static int F_9 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_10 ( V_30 ) ;
int V_31 , V_32 ;
T_1 V_33 ;
if ( F_11 ( V_28 ) != 2 )
return - V_10 ;
switch ( F_12 ( V_28 ) ) {
case 16 :
V_33 = V_34 ;
break;
default:
return - V_10 ;
}
V_2 -> V_35 . V_36 = V_33 ;
switch ( F_13 ( V_28 ) ) {
case 16 :
V_31 = 0 ;
V_32 = 0 ;
break;
default:
return - V_10 ;
}
F_14 ( V_2 -> V_22 , V_37 ,
V_38 | V_39 ,
F_15 ( V_32 ) | F_16 ( V_31 ) ) ;
return F_4 ( V_2 , F_17 ( V_28 ) ,
F_13 ( V_28 ) ) ;
}
static int F_18 ( struct V_29 * V_30 , unsigned int V_40 )
{
struct V_1 * V_2 = F_10 ( V_30 ) ;
T_1 V_9 ;
switch ( V_40 & V_41 ) {
case V_42 :
V_9 = V_43 ;
break;
case V_44 :
V_9 = V_45 ;
break;
case V_46 :
V_9 = V_47 ;
break;
default:
return - V_10 ;
}
F_14 ( V_2 -> V_22 , V_37 ,
V_48 ,
V_9 ) ;
switch ( V_40 & V_49 ) {
case V_50 :
V_9 = V_51 |
V_52 ;
break;
case V_53 :
V_9 = V_51 |
V_54 ;
break;
case V_55 :
V_9 = V_52 |
V_56 ;
break;
case V_57 :
V_9 = V_56 |
V_54 ;
break;
default:
return - V_10 ;
}
F_14 ( V_2 -> V_22 , V_37 ,
V_58 |
V_59 ,
V_9 ) ;
switch ( V_40 & V_60 ) {
case V_61 :
V_9 = V_62 ;
break;
case V_63 :
V_9 = V_64 ;
break;
default:
return - V_10 ;
}
F_14 ( V_2 -> V_22 , V_65 ,
V_66 ,
V_9 ) ;
F_14 ( V_2 -> V_22 , V_67 ,
V_68 |
V_69 ,
F_19 ( 1 ) |
F_20 ( 1 ) ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_22 , V_67 ,
V_70 ,
V_70 ) ;
F_6 ( V_2 -> V_22 , V_71 , 0 ) ;
F_14 ( V_2 -> V_22 , V_65 ,
V_72 ,
V_72 ) ;
F_14 ( V_2 -> V_22 , V_73 ,
V_74 ,
V_74 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_22 , V_65 ,
V_72 ,
0 ) ;
F_14 ( V_2 -> V_22 , V_73 ,
V_74 ,
0 ) ;
}
static int F_23 ( struct V_25 * V_26 , int V_75 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_10 ( V_30 ) ;
switch ( V_75 ) {
case V_76 :
case V_77 :
case V_78 :
if ( V_26 -> V_79 == V_80 )
F_21 ( V_2 ) ;
else
return - V_10 ;
break;
case V_81 :
case V_82 :
case V_83 :
if ( V_26 -> V_79 == V_80 )
F_22 ( V_2 ) ;
else
return - V_10 ;
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_24 ( struct V_25 * V_26 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_10 ( V_30 ) ;
F_6 ( V_2 -> V_22 , V_65 ,
V_84 ) ;
F_14 ( V_2 -> V_22 , V_65 ,
V_85 ,
F_25 ( 0 ) ) ;
F_6 ( V_2 -> V_22 , V_86 ,
F_26 ( 2 ) ) ;
F_6 ( V_2 -> V_22 , V_87 ,
F_27 ( 0 , 0 ) | F_27 ( 1 , 1 ) ) ;
return F_28 ( V_2 -> V_20 ) ;
}
static void F_29 ( struct V_25 * V_26 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_10 ( V_30 ) ;
F_30 ( V_2 -> V_20 ) ;
F_14 ( V_2 -> V_22 , V_65 ,
V_85 , 0 ) ;
F_6 ( V_2 -> V_22 , V_65 , 0 ) ;
}
static int F_31 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = F_10 ( V_30 ) ;
F_32 ( V_30 , & V_2 -> V_35 , NULL ) ;
F_33 ( V_30 , V_2 ) ;
return 0 ;
}
static bool F_34 ( struct V_88 * V_89 , unsigned int V_90 )
{
switch ( V_90 ) {
case V_91 :
return false ;
default:
return true ;
}
}
static bool F_35 ( struct V_88 * V_89 , unsigned int V_90 )
{
switch ( V_90 ) {
case V_92 :
case V_93 :
return false ;
default:
return true ;
}
}
static bool F_36 ( struct V_88 * V_89 , unsigned int V_90 )
{
switch ( V_90 ) {
case V_92 :
case V_94 :
case V_95 :
case V_71 :
return true ;
default:
return false ;
}
}
static int F_37 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_38 ( V_89 ) ;
int V_19 ;
V_19 = F_28 ( V_2 -> V_96 ) ;
if ( V_19 ) {
F_39 ( V_89 , L_1 ) ;
return V_19 ;
}
F_40 ( V_2 -> V_22 , false ) ;
F_41 ( V_2 -> V_22 ) ;
V_19 = F_42 ( V_2 -> V_22 ) ;
if ( V_19 ) {
F_39 ( V_89 , L_2 ) ;
goto V_97;
}
return 0 ;
V_97:
F_30 ( V_2 -> V_96 ) ;
return V_19 ;
}
static int F_43 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = F_38 ( V_89 ) ;
F_40 ( V_2 -> V_22 , true ) ;
F_30 ( V_2 -> V_96 ) ;
return 0 ;
}
static int F_44 ( struct V_98 * V_99 )
{
struct V_1 * V_2 ;
struct V_100 * V_101 ;
void T_2 * V_102 ;
int V_103 , V_19 ;
V_2 = F_45 ( & V_99 -> V_89 , sizeof( * V_2 ) , V_104 ) ;
if ( ! V_2 )
return - V_105 ;
F_46 ( V_99 , V_2 ) ;
V_101 = F_47 ( V_99 , V_106 , 0 ) ;
V_102 = F_48 ( & V_99 -> V_89 , V_101 ) ;
if ( F_49 ( V_102 ) )
return F_50 ( V_102 ) ;
V_103 = F_51 ( V_99 , 0 ) ;
if ( V_103 < 0 ) {
F_39 ( & V_99 -> V_89 , L_3 ) ;
return V_103 ;
}
V_2 -> V_96 = F_52 ( & V_99 -> V_89 , L_4 ) ;
if ( F_49 ( V_2 -> V_96 ) ) {
F_39 ( & V_99 -> V_89 , L_5 ) ;
return F_50 ( V_2 -> V_96 ) ;
}
V_2 -> V_22 = F_53 ( & V_99 -> V_89 , V_102 ,
& V_107 ) ;
if ( F_49 ( V_2 -> V_22 ) ) {
F_39 ( & V_99 -> V_89 , L_6 ) ;
return F_50 ( V_2 -> V_22 ) ;
}
V_2 -> V_20 = F_52 ( & V_99 -> V_89 , L_7 ) ;
if ( F_49 ( V_2 -> V_20 ) ) {
F_39 ( & V_99 -> V_89 , L_8 ) ;
return F_50 ( V_2 -> V_20 ) ;
}
V_2 -> V_35 . V_108 = V_101 -> V_109 + V_91 ;
V_2 -> V_35 . V_110 = 4 ;
F_54 ( & V_99 -> V_89 ) ;
if ( ! F_55 ( & V_99 -> V_89 ) ) {
V_19 = F_37 ( & V_99 -> V_89 ) ;
if ( V_19 )
goto V_111;
}
V_19 = F_56 ( & V_99 -> V_89 ,
& V_112 ,
& V_113 , 1 ) ;
if ( V_19 ) {
F_39 ( & V_99 -> V_89 , L_9 ) ;
goto V_114;
}
V_19 = F_57 ( & V_99 -> V_89 , NULL , 0 ) ;
if ( V_19 ) {
F_39 ( & V_99 -> V_89 , L_10 ) ;
goto V_114;
}
return 0 ;
V_114:
if ( ! F_58 ( & V_99 -> V_89 ) )
F_43 ( & V_99 -> V_89 ) ;
V_111:
F_59 ( & V_99 -> V_89 ) ;
return V_19 ;
}
static int F_60 ( struct V_98 * V_99 )
{
F_61 ( & V_99 -> V_89 ) ;
F_59 ( & V_99 -> V_89 ) ;
if ( ! F_58 ( & V_99 -> V_89 ) )
F_43 ( & V_99 -> V_89 ) ;
return 0 ;
}
