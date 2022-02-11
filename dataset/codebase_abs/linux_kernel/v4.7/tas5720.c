static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_9 = F_2 ( V_4 ) ;
bool V_10 ;
int V_11 ;
switch ( V_9 ) {
case 44100 :
case 48000 :
V_10 = false ;
break;
case 88200 :
case 96000 :
V_10 = true ;
break;
default:
F_3 ( V_8 -> V_12 , L_1 , V_9 ) ;
return - V_13 ;
}
V_11 = F_4 ( V_8 , V_14 ,
V_15 , V_10 ) ;
if ( V_11 < 0 ) {
F_3 ( V_8 -> V_12 , L_2 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static int F_5 ( struct V_5 * V_6 , unsigned int V_16 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_17 ;
int V_11 ;
if ( ( V_16 & V_18 ) != V_19 ) {
F_6 ( V_8 -> V_12 , L_3 ) ;
return - V_13 ;
}
switch ( V_16 & ( V_20 |
V_21 ) ) {
case ( V_22 | V_23 ) :
V_17 = V_24 ;
break;
case ( V_25 | V_23 ) :
V_17 = V_24 ;
break;
case ( V_26 | V_23 ) :
V_17 = V_27 ;
break;
case ( V_28 | V_23 ) :
V_17 = V_27 ;
break;
default:
F_6 ( V_8 -> V_12 , L_4 ) ;
return - V_13 ;
}
V_11 = F_4 ( V_8 , V_14 ,
V_29 ,
V_17 ) ;
if ( V_11 < 0 ) {
F_3 ( V_8 -> V_12 , L_5 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 ,
unsigned int V_30 , unsigned int V_31 ,
int V_32 , int V_33 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_34 ;
int V_11 ;
if ( ! V_30 ) {
F_3 ( V_8 -> V_12 , L_6 ) ;
return - V_13 ;
}
V_34 = F_8 ( V_30 ) ;
if ( V_34 > 7 ) {
F_3 ( V_8 -> V_12 , L_7 ,
V_34 ) ;
return - V_13 ;
}
V_11 = F_4 ( V_8 , V_14 ,
V_35 , V_35 ) ;
if ( V_11 < 0 )
goto V_36;
V_11 = F_4 ( V_8 , V_37 ,
V_38 , V_34 ) ;
if ( V_11 < 0 )
goto V_36;
return 0 ;
V_36:
F_3 ( V_8 -> V_12 , L_8 , V_11 ) ;
return V_11 ;
}
static int F_9 ( struct V_5 * V_6 , int V_39 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_11 ;
V_11 = F_4 ( V_8 , V_37 ,
V_40 , V_39 ? V_40 : 0 ) ;
if ( V_11 < 0 ) {
F_3 ( V_8 -> V_12 , L_9 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static void F_10 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_11 ( V_42 , struct V_43 ,
V_45 . V_42 ) ;
struct V_46 * V_12 = V_44 -> V_8 -> V_12 ;
unsigned int V_47 ;
int V_11 ;
V_11 = F_12 ( V_44 -> V_48 , V_49 , & V_47 ) ;
if ( V_11 < 0 ) {
F_3 ( V_12 , L_10 , V_11 ) ;
goto V_50;
}
V_47 &= V_51 | V_52 | V_53 ;
if ( ( V_47 & V_51 ) && ! ( V_44 -> V_54 & V_51 ) )
F_13 ( V_12 , L_11 ) ;
if ( ( V_47 & V_52 ) && ! ( V_44 -> V_54 & V_52 ) )
F_13 ( V_12 , L_12 ) ;
if ( ( V_47 & V_53 ) && ! ( V_44 -> V_54 & V_53 ) )
F_13 ( V_12 , L_13 ) ;
V_44 -> V_54 = V_47 ;
if ( ! V_47 )
goto V_50;
V_11 = F_14 ( V_44 -> V_48 , V_55 ,
V_56 , 0 ) ;
if ( V_11 < 0 )
F_3 ( V_12 , L_14 , V_11 ) ;
V_11 = F_14 ( V_44 -> V_48 , V_55 ,
V_56 , V_56 ) ;
if ( V_11 < 0 )
F_3 ( V_12 , L_14 , V_11 ) ;
V_50:
F_15 ( & V_44 -> V_45 ,
F_16 ( V_57 ) ) ;
}
static int F_17 ( struct V_7 * V_8 )
{
struct V_43 * V_44 = F_18 ( V_8 ) ;
unsigned int V_58 ;
int V_11 ;
V_44 -> V_8 = V_8 ;
V_11 = F_19 ( F_20 ( V_44 -> V_59 ) ,
V_44 -> V_59 ) ;
if ( V_11 != 0 ) {
F_3 ( V_8 -> V_12 , L_15 , V_11 ) ;
return V_11 ;
}
V_11 = F_12 ( V_44 -> V_48 , V_60 , & V_58 ) ;
if ( V_11 < 0 ) {
F_3 ( V_8 -> V_12 , L_16 ,
V_11 ) ;
goto V_61;
}
if ( V_58 != V_62 ) {
F_3 ( V_8 -> V_12 , L_17 ,
V_62 , V_58 ) ;
V_11 = - V_63 ;
goto V_61;
}
V_11 = F_4 ( V_8 , V_37 ,
V_40 , V_40 ) ;
if ( V_11 < 0 )
goto V_36;
V_11 = F_4 ( V_8 , V_55 ,
V_56 , 0 ) ;
if ( V_11 < 0 )
goto V_36;
F_21 ( & V_44 -> V_45 , F_10 ) ;
return 0 ;
V_36:
F_3 ( V_8 -> V_12 , L_18 , V_11 ) ;
V_61:
F_22 ( F_20 ( V_44 -> V_59 ) ,
V_44 -> V_59 ) ;
return V_11 ;
}
static int F_23 ( struct V_7 * V_8 )
{
struct V_43 * V_44 = F_18 ( V_8 ) ;
int V_11 ;
F_24 ( & V_44 -> V_45 ) ;
V_11 = F_22 ( F_20 ( V_44 -> V_59 ) ,
V_44 -> V_59 ) ;
if ( V_11 < 0 )
F_3 ( V_8 -> V_12 , L_19 , V_11 ) ;
return V_11 ;
}
static int F_25 ( struct V_64 * V_65 ,
struct V_66 * V_67 , int V_68 )
{
struct V_7 * V_8 = F_26 ( V_65 -> V_69 ) ;
struct V_43 * V_44 = F_18 ( V_8 ) ;
int V_11 ;
if ( V_68 & V_70 ) {
V_11 = F_4 ( V_8 , V_55 ,
V_56 , V_56 ) ;
if ( V_11 < 0 ) {
F_3 ( V_8 -> V_12 , L_20 , V_11 ) ;
return V_11 ;
}
F_27 ( 25 ) ;
V_44 -> V_54 = 0 ;
F_15 ( & V_44 -> V_45 ,
F_16 ( V_57 ) ) ;
} else if ( V_68 & V_71 ) {
F_24 ( & V_44 -> V_45 ) ;
V_11 = F_4 ( V_8 , V_55 ,
V_56 , 0 ) ;
if ( V_11 < 0 ) {
F_3 ( V_8 -> V_12 , L_21 ,
V_11 ) ;
return V_11 ;
}
}
return 0 ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_43 * V_44 = F_18 ( V_8 ) ;
int V_11 ;
F_29 ( V_44 -> V_48 , true ) ;
F_30 ( V_44 -> V_48 ) ;
V_11 = F_22 ( F_20 ( V_44 -> V_59 ) ,
V_44 -> V_59 ) ;
if ( V_11 < 0 )
F_3 ( V_8 -> V_12 , L_19 , V_11 ) ;
return V_11 ;
}
static int F_31 ( struct V_7 * V_8 )
{
struct V_43 * V_44 = F_18 ( V_8 ) ;
int V_11 ;
V_11 = F_19 ( F_20 ( V_44 -> V_59 ) ,
V_44 -> V_59 ) ;
if ( V_11 < 0 ) {
F_3 ( V_8 -> V_12 , L_15 , V_11 ) ;
return V_11 ;
}
F_29 ( V_44 -> V_48 , false ) ;
V_11 = F_32 ( V_44 -> V_48 ) ;
if ( V_11 < 0 ) {
F_3 ( V_8 -> V_12 , L_22 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static bool F_33 ( struct V_46 * V_12 , unsigned int V_72 )
{
switch ( V_72 ) {
case V_60 :
case V_49 :
return true ;
default:
return false ;
}
}
static int F_34 ( struct V_73 * V_74 ,
const struct V_75 * V_76 )
{
struct V_46 * V_12 = & V_74 -> V_12 ;
struct V_43 * V_77 ;
int V_11 ;
int V_78 ;
V_77 = F_35 ( V_12 , sizeof( * V_77 ) , V_79 ) ;
if ( ! V_77 )
return - V_80 ;
V_77 -> V_81 = V_74 ;
V_77 -> V_48 = F_36 ( V_74 , & V_82 ) ;
if ( F_37 ( V_77 -> V_48 ) ) {
V_11 = F_38 ( V_77 -> V_48 ) ;
F_3 ( V_12 , L_23 , V_11 ) ;
return V_11 ;
}
for ( V_78 = 0 ; V_78 < F_20 ( V_77 -> V_59 ) ; V_78 ++ )
V_77 -> V_59 [ V_78 ] . V_83 = V_84 [ V_78 ] ;
V_11 = F_39 ( V_12 , F_20 ( V_77 -> V_59 ) ,
V_77 -> V_59 ) ;
if ( V_11 != 0 ) {
F_3 ( V_12 , L_24 , V_11 ) ;
return V_11 ;
}
F_40 ( V_12 , V_77 ) ;
V_11 = F_41 ( & V_74 -> V_12 ,
& V_85 ,
V_86 , F_20 ( V_86 ) ) ;
if ( V_11 < 0 ) {
F_3 ( V_12 , L_25 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static int F_42 ( struct V_73 * V_74 )
{
struct V_46 * V_12 = & V_74 -> V_12 ;
F_43 ( V_12 ) ;
return 0 ;
}
