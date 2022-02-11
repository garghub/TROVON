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
static T_2 F_8 ( int V_59 , void * V_60 )
{
struct V_61 * V_46 = V_60 ;
struct V_1 * V_2 = V_46 -> V_62 ;
unsigned long V_63 ;
T_1 V_64 ;
F_9 ( & V_2 -> V_65 , V_63 ) ;
V_64 = F_10 ( V_2 , V_66 ) ;
F_11 ( V_2 , V_66 , V_64 ^ V_67 ) ;
F_12 ( & V_2 -> V_65 , V_63 ) ;
if ( V_64 & V_68 ) {
F_13 ( V_46 , 0 ) ;
F_14 ( & V_2 -> V_69 ) ;
}
return V_70 ;
}
static int F_15 ( struct V_71 * V_46 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
F_17 ( V_2 -> V_72 ) ;
F_18 ( & V_2 -> V_69 ) ;
return 0 ;
}
static int F_19 ( struct V_71 * V_46 )
{
struct V_1 * V_2 = F_16 ( V_46 ) ;
F_20 ( V_2 -> V_72 ) ;
F_21 ( & V_2 -> V_69 ) ;
F_22 ( V_2 -> V_72 ) ;
F_23 ( V_2 -> V_72 ) ;
return 0 ;
}
static int F_24 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_25 ( V_74 ) ;
struct V_61 * V_72 = V_2 -> V_72 ;
F_26 ( V_72 ) ;
F_27 ( V_72 ) ;
F_28 ( V_72 ) ;
F_29 ( V_72 ) ;
F_30 ( V_72 ) ;
return 0 ;
}
static int F_31 ( struct V_73 * V_74 )
{
struct V_75 * V_43 = V_74 -> V_46 . V_76 ;
struct V_1 * V_2 ;
struct V_61 * V_72 ;
struct V_77 * V_78 ;
unsigned int V_79 ;
int V_80 ;
if ( V_43 == NULL ) {
F_3 ( & V_74 -> V_46 , L_5 ) ;
return - V_47 ;
}
V_2 = F_32 ( & V_74 -> V_46 , sizeof( * V_2 ) , V_81 ) ;
if ( V_2 == NULL )
return - V_82 ;
V_2 -> V_46 = & V_74 -> V_46 ;
V_2 -> V_43 = V_43 ;
F_33 ( & V_2 -> V_65 ) ;
F_34 ( V_74 , V_2 ) ;
V_78 = F_35 ( V_74 , V_83 , 0 ) ;
V_2 -> V_84 = F_36 ( & V_74 -> V_46 , V_78 ) ;
if ( V_2 -> V_84 == NULL )
return - V_82 ;
V_80 = F_4 ( V_2 , V_43 -> V_85 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 = F_1 ( V_2 ) ;
if ( V_80 < 0 )
return V_80 ;
V_72 = F_37 ( & V_86 , & V_74 -> V_46 ) ;
if ( F_6 ( V_72 ) )
return F_7 ( V_72 ) ;
V_2 -> V_72 = V_72 ;
V_72 -> V_62 = V_2 ;
V_80 = F_38 ( V_2 ) ;
if ( V_80 < 0 ) {
F_3 ( & V_74 -> V_46 , L_6 ) ;
goto V_87;
}
for ( V_79 = 0 ; V_79 < 4 ; ++ V_79 ) {
V_80 = F_39 ( V_2 , V_79 ) ;
if ( V_80 < 0 ) {
F_3 ( & V_74 -> V_46 , L_7 , V_79 ) ;
goto V_88;
}
}
V_80 = F_40 ( V_72 , 1 ) ;
if ( V_80 < 0 ) {
F_3 ( & V_74 -> V_46 , L_8 ) ;
goto V_88;
}
V_80 = F_41 ( V_72 , F_42 ( V_74 , 0 ) ) ;
if ( V_80 < 0 ) {
F_3 ( & V_74 -> V_46 , L_9 ) ;
goto V_89;
}
V_80 = F_43 ( V_72 , 0 ) ;
if ( V_80 < 0 )
goto V_90;
return 0 ;
V_90:
F_29 ( V_72 ) ;
V_89:
F_44 ( V_72 ) ;
V_88:
F_27 ( V_72 ) ;
F_28 ( V_72 ) ;
V_87:
F_30 ( V_72 ) ;
return V_80 ;
}
