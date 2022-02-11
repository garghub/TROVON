static int T_1 F_1 ( struct V_1 * V_2 )
{
static const T_2 V_3 [] = {
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
static int T_1 F_4 ( struct V_1 * V_2 ,
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
static int F_8 ( struct V_59 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_60 ;
F_9 ( V_46 ) ;
F_10 ( V_46 ) ;
F_11 ( V_46 ) ;
F_12 ( V_46 ) ;
if ( V_2 -> clock )
F_13 ( V_2 -> clock ) ;
if ( V_2 -> V_61 )
F_14 ( V_2 -> V_61 ) ;
V_46 -> V_60 = NULL ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_59 * V_46 , unsigned long V_62 )
{
struct V_63 * V_43 = V_46 -> V_46 -> V_64 ;
struct V_65 * V_66 = V_46 -> V_67 ;
struct V_1 * V_2 ;
struct V_68 * V_69 ;
unsigned int V_70 ;
int V_71 ;
if ( V_43 == NULL ) {
F_3 ( V_46 -> V_46 , L_5 ) ;
return - V_47 ;
}
V_2 = F_17 ( sizeof( * V_2 ) , V_72 ) ;
if ( V_2 == NULL ) {
F_3 ( V_46 -> V_46 , L_6 ) ;
return - V_73 ;
}
V_2 -> V_46 = & V_66 -> V_46 ;
V_2 -> V_43 = V_43 ;
F_18 ( & V_2 -> V_74 ) ;
V_2 -> V_75 = V_46 ;
V_46 -> V_60 = V_2 ;
V_69 = F_19 ( V_66 , V_76 , 0 ) ;
if ( V_69 == NULL ) {
F_3 ( & V_66 -> V_46 , L_7 ) ;
V_71 = - V_47 ;
goto V_77;
}
V_2 -> V_61 = F_20 ( V_69 -> V_78 , F_21 ( V_69 ) ) ;
if ( V_2 -> V_61 == NULL ) {
F_3 ( & V_66 -> V_46 , L_8 ) ;
V_71 = - V_73 ;
goto V_77;
}
V_71 = F_4 ( V_2 , V_43 -> V_79 ) ;
if ( V_71 < 0 )
goto V_77;
V_71 = F_1 ( V_2 ) ;
if ( V_71 < 0 )
goto V_77;
V_71 = F_22 ( V_2 ) ;
if ( V_71 < 0 ) {
F_3 ( & V_66 -> V_46 , L_9 ) ;
goto V_77;
}
for ( V_70 = 0 ; V_70 < 4 ; ++ V_70 ) {
V_71 = F_23 ( V_2 , V_70 ) ;
if ( V_71 < 0 ) {
F_3 ( & V_66 -> V_46 , L_10 , V_70 ) ;
goto V_77;
}
}
V_71 = F_24 ( V_46 , 1 ) ;
if ( V_71 < 0 ) {
F_3 ( & V_66 -> V_46 , L_11 ) ;
goto V_77;
}
V_71 = F_25 ( V_46 ) ;
if ( V_71 < 0 ) {
F_3 ( & V_66 -> V_46 , L_12 ) ;
goto V_77;
}
F_26 ( V_66 , V_2 ) ;
V_77:
if ( V_71 )
F_8 ( V_46 ) ;
return V_71 ;
}
static void F_27 ( struct V_59 * V_46 , struct V_80 * V_81 )
{
struct V_1 * V_2 = V_46 -> V_60 ;
F_28 ( & V_2 -> V_82 , V_81 ) ;
}
static T_3 F_29 ( int V_83 , void * V_84 )
{
struct V_59 * V_46 = V_84 ;
struct V_1 * V_2 = V_46 -> V_60 ;
unsigned long V_62 ;
T_2 V_85 ;
F_30 ( & V_2 -> V_74 , V_62 ) ;
V_85 = F_31 ( V_2 , V_86 ) ;
F_32 ( V_2 , V_86 , V_85 ^ V_87 ) ;
F_33 ( & V_2 -> V_74 , V_62 ) ;
if ( V_85 & V_88 ) {
F_34 ( V_46 , 0 ) ;
F_35 ( & V_2 -> V_82 ) ;
}
return V_89 ;
}
static int F_36 ( struct V_59 * V_46 , int V_82 )
{
struct V_1 * V_2 = V_46 -> V_60 ;
F_37 ( V_2 , true ) ;
return 0 ;
}
static void F_38 ( struct V_59 * V_46 , int V_82 )
{
struct V_1 * V_2 = V_46 -> V_60 ;
F_37 ( V_2 , false ) ;
}
static int F_39 ( struct V_90 * V_46 )
{
struct V_1 * V_2 = F_40 ( V_46 ) ;
F_41 ( V_2 -> V_75 ) ;
F_42 ( & V_2 -> V_82 ) ;
return 0 ;
}
static int F_43 ( struct V_90 * V_46 )
{
struct V_1 * V_2 = F_40 ( V_46 ) ;
F_44 ( & V_2 -> V_75 -> V_91 . V_92 ) ;
F_45 ( & V_2 -> V_82 ) ;
F_46 ( & V_2 -> V_75 -> V_91 . V_92 ) ;
F_47 ( V_2 -> V_75 ) ;
return 0 ;
}
static int T_1 F_48 ( struct V_65 * V_66 )
{
return F_49 ( & V_93 , V_66 ) ;
}
static int T_4 F_50 ( struct V_65 * V_66 )
{
F_51 ( & V_93 , V_66 ) ;
return 0 ;
}
