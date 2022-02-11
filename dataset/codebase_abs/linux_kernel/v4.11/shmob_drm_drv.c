static int F_1 ( struct V_1 * V_2 )
{
static const T_1 V_3 [] = {
[ V_4 ] = V_5 ,
[ V_6 ] = V_7 ,
[ V_8 ] = V_9 ,
[ V_10 ] = V_11 ,
[ V_12 ] = V_13 ,
[ V_14 ] = V_15 ,
[ V_16 ] = V_17 ,
[ V_18 ] = V_19 ,
[ V_20 ] = V_21 | V_22 ,
[ V_23 ] = V_21 | V_24 ,
[ V_25 ] = V_21 | V_26 ,
[ V_27 ] = V_21 | V_28 ,
[ V_29 ] = V_21 | V_30 ,
[ V_31 ] = V_21 | V_32 ,
[ V_33 ] = V_21 | V_34 ,
[ V_35 ] = V_21 | V_36 ,
[ V_37 ] = V_21 | V_38 ,
[ V_39 ] = V_21 | V_40 ,
[ V_41 ] = V_21 | V_42 ,
} ;
if ( V_2 -> V_43 -> V_44 . V_45 >= F_2 ( V_3 ) ) {
F_3 ( V_2 -> V_46 , L_1 ,
V_2 -> V_43 -> V_44 . V_45 ) ;
return - V_47 ;
}
V_2 -> V_3 = V_3 [ V_2 -> V_43 -> V_44 . V_45 ] ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
enum V_48 V_49 )
{
struct V_50 * V_50 ;
char * V_51 ;
switch ( V_49 ) {
case V_52 :
V_51 = L_2 ;
V_2 -> V_53 = V_54 ;
break;
case V_55 :
V_51 = L_3 ;
V_2 -> V_53 = V_56 ;
break;
case V_57 :
V_51 = NULL ;
V_2 -> V_53 = V_58 ;
break;
default:
return - V_47 ;
}
V_50 = F_5 ( V_2 -> V_46 , V_51 ) ;
if ( F_6 ( V_50 ) ) {
F_3 ( V_2 -> V_46 , L_4 , V_51 ) ;
return F_7 ( V_50 ) ;
}
V_2 -> clock = V_50 ;
return 0 ;
}
static void F_8 ( struct V_59 * V_46 )
{
F_9 ( V_46 ) ;
F_10 ( V_46 ) ;
F_11 ( V_46 ) ;
F_12 ( V_46 ) ;
V_46 -> V_60 = NULL ;
}
static int F_13 ( struct V_59 * V_46 , unsigned long V_61 )
{
struct V_62 * V_43 = V_46 -> V_46 -> V_63 ;
struct V_64 * V_65 = V_46 -> V_66 ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
unsigned int V_69 ;
int V_70 ;
if ( V_43 == NULL ) {
F_3 ( V_46 -> V_46 , L_5 ) ;
return - V_47 ;
}
V_2 = F_14 ( & V_65 -> V_46 , sizeof( * V_2 ) , V_71 ) ;
if ( V_2 == NULL ) {
F_3 ( V_46 -> V_46 , L_6 ) ;
return - V_72 ;
}
V_2 -> V_46 = & V_65 -> V_46 ;
V_2 -> V_43 = V_43 ;
F_15 ( & V_2 -> V_73 ) ;
V_2 -> V_74 = V_46 ;
V_46 -> V_60 = V_2 ;
V_68 = F_16 ( V_65 , V_75 , 0 ) ;
if ( V_68 == NULL ) {
F_3 ( & V_65 -> V_46 , L_7 ) ;
return - V_47 ;
}
V_2 -> V_76 = F_17 ( & V_65 -> V_46 , V_68 -> V_77 ,
F_18 ( V_68 ) ) ;
if ( V_2 -> V_76 == NULL ) {
F_3 ( & V_65 -> V_46 , L_8 ) ;
return - V_72 ;
}
V_70 = F_4 ( V_2 , V_43 -> V_78 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_1 ( V_2 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_19 ( V_2 ) ;
if ( V_70 < 0 ) {
F_3 ( & V_65 -> V_46 , L_9 ) ;
return V_70 ;
}
for ( V_69 = 0 ; V_69 < 4 ; ++ V_69 ) {
V_70 = F_20 ( V_2 , V_69 ) ;
if ( V_70 < 0 ) {
F_3 ( & V_65 -> V_46 , L_10 , V_69 ) ;
goto V_79;
}
}
V_70 = F_21 ( V_46 , 1 ) ;
if ( V_70 < 0 ) {
F_3 ( & V_65 -> V_46 , L_11 ) ;
goto V_79;
}
V_70 = F_22 ( V_46 , F_23 ( V_46 -> V_66 , 0 ) ) ;
if ( V_70 < 0 ) {
F_3 ( & V_65 -> V_46 , L_12 ) ;
goto V_79;
}
F_24 ( V_65 , V_2 ) ;
V_79:
if ( V_70 )
F_8 ( V_46 ) ;
return V_70 ;
}
static T_2 F_25 ( int V_80 , void * V_81 )
{
struct V_59 * V_46 = V_81 ;
struct V_1 * V_2 = V_46 -> V_60 ;
unsigned long V_61 ;
T_1 V_82 ;
F_26 ( & V_2 -> V_73 , V_61 ) ;
V_82 = F_27 ( V_2 , V_83 ) ;
F_28 ( V_2 , V_83 , V_82 ^ V_84 ) ;
F_29 ( & V_2 -> V_73 , V_61 ) ;
if ( V_82 & V_85 ) {
F_30 ( V_46 , 0 ) ;
F_31 ( & V_2 -> V_86 ) ;
}
return V_87 ;
}
static int F_32 ( struct V_59 * V_46 , unsigned int V_88 )
{
struct V_1 * V_2 = V_46 -> V_60 ;
F_33 ( V_2 , true ) ;
return 0 ;
}
static void F_34 ( struct V_59 * V_46 , unsigned int V_88 )
{
struct V_1 * V_2 = V_46 -> V_60 ;
F_33 ( V_2 , false ) ;
}
static int F_35 ( struct V_89 * V_46 )
{
struct V_1 * V_2 = F_36 ( V_46 ) ;
F_37 ( V_2 -> V_74 ) ;
F_38 ( & V_2 -> V_86 ) ;
return 0 ;
}
static int F_39 ( struct V_89 * V_46 )
{
struct V_1 * V_2 = F_36 ( V_46 ) ;
F_40 ( V_2 -> V_74 ) ;
F_41 ( & V_2 -> V_86 ) ;
F_42 ( V_2 -> V_74 ) ;
F_43 ( V_2 -> V_74 ) ;
return 0 ;
}
static int F_44 ( struct V_64 * V_65 )
{
return F_45 ( & V_90 , V_65 ) ;
}
static int F_46 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_47 ( V_65 ) ;
F_48 ( V_2 -> V_74 ) ;
return 0 ;
}
