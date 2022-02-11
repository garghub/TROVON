static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
return true ;
default:
return V_3 < 0xff ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_7 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_65 :
return true ;
default:
return V_3 < 0xff ;
}
}
static int F_3 ( struct V_66 * V_67 ,
enum V_68 V_69 )
{
struct V_70 * V_71 = F_4 ( V_67 -> V_2 ) ;
int V_72 ;
switch ( V_69 ) {
case V_73 :
case V_74 :
break;
case V_75 :
V_72 = F_5 ( V_71 -> V_76 , V_5 ,
V_77 , 0 ) ;
if ( V_72 != 0 ) {
F_6 ( V_67 -> V_2 , L_1 ,
V_72 ) ;
return V_72 ;
}
break;
case V_78 :
V_72 = F_5 ( V_71 -> V_76 , V_5 ,
V_77 , V_77 ) ;
if ( V_72 != 0 ) {
F_6 ( V_67 -> V_2 , L_2 ,
V_72 ) ;
return V_72 ;
}
break;
}
V_67 -> V_79 . V_80 = V_69 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , struct V_76 * V_76 )
{
struct V_70 * V_71 ;
int V_81 , V_72 ;
V_71 = F_8 ( V_2 , sizeof( struct V_70 ) , V_82 ) ;
if ( ! V_71 )
return - V_83 ;
F_9 ( V_2 , V_71 ) ;
V_71 -> V_76 = V_76 ;
for ( V_81 = 0 ; V_81 < F_10 ( V_71 -> V_84 ) ; V_81 ++ )
V_71 -> V_84 [ V_81 ] . V_85 = V_86 [ V_81 ] ;
V_72 = F_11 ( V_2 , F_10 ( V_71 -> V_84 ) ,
V_71 -> V_84 ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 , L_3 , V_72 ) ;
return V_72 ;
}
V_71 -> V_87 [ 0 ] . V_88 = V_89 ;
V_71 -> V_87 [ 1 ] . V_88 = V_90 ;
V_71 -> V_87 [ 2 ] . V_88 = V_91 ;
for ( V_81 = 0 ; V_81 < F_10 ( V_71 -> V_84 ) ; V_81 ++ ) {
V_72 = F_12 ( V_71 -> V_84 [ V_81 ] . V_92 ,
& V_71 -> V_87 [ V_81 ] ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 ,
L_4 ,
V_72 ) ;
}
}
V_72 = F_13 ( F_10 ( V_71 -> V_84 ) ,
V_71 -> V_84 ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 , L_5 , V_72 ) ;
return V_72 ;
}
V_72 = F_14 ( V_76 , V_4 ,
V_93 | V_94 ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 , L_6 , V_72 ) ;
goto V_95;
}
V_72 = F_14 ( V_76 , V_4 , 0 ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 , L_6 , V_72 ) ;
goto V_95;
}
V_71 -> V_96 = F_15 ( V_2 , NULL ) ;
if ( F_16 ( V_71 -> V_96 ) ) {
if ( F_17 ( V_71 -> V_96 ) == - V_97 )
return - V_97 ;
F_18 ( V_2 , L_7 ,
F_17 ( V_71 -> V_96 ) ) ;
F_5 ( V_76 , V_29 ,
V_98 , V_98 ) ;
F_5 ( V_76 , V_14 ,
V_99 , V_99 ) ;
} else {
V_72 = F_19 ( V_71 -> V_96 ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 , L_8 , V_72 ) ;
return V_72 ;
}
}
V_72 = F_5 ( V_71 -> V_76 , V_5 ,
V_77 , V_77 ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 , L_2 ,
V_72 ) ;
goto V_100;
}
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
V_72 = F_23 ( V_2 , & V_101 ,
& V_102 , 1 ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 , L_9 , V_72 ) ;
goto V_103;
}
return 0 ;
V_103:
F_24 ( V_2 ) ;
V_100:
if ( ! F_16 ( V_71 -> V_96 ) )
F_25 ( V_71 -> V_96 ) ;
V_95:
F_26 ( F_10 ( V_71 -> V_84 ) ,
V_71 -> V_84 ) ;
return V_72 ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = F_4 ( V_2 ) ;
F_28 ( V_2 ) ;
F_24 ( V_2 ) ;
if ( ! F_16 ( V_71 -> V_96 ) )
F_25 ( V_71 -> V_96 ) ;
F_26 ( F_10 ( V_71 -> V_84 ) ,
V_71 -> V_84 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = F_4 ( V_2 ) ;
int V_72 ;
V_72 = F_5 ( V_71 -> V_76 , V_5 ,
V_104 , V_104 ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 , L_10 , V_72 ) ;
return V_72 ;
}
V_72 = F_26 ( F_10 ( V_71 -> V_84 ) ,
V_71 -> V_84 ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 , L_11 , V_72 ) ;
return V_72 ;
}
if ( ! F_16 ( V_71 -> V_96 ) )
F_25 ( V_71 -> V_96 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = F_4 ( V_2 ) ;
int V_72 ;
if ( ! F_16 ( V_71 -> V_96 ) ) {
V_72 = F_19 ( V_71 -> V_96 ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 , L_8 , V_72 ) ;
return V_72 ;
}
}
V_72 = F_13 ( F_10 ( V_71 -> V_84 ) ,
V_71 -> V_84 ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 , L_5 , V_72 ) ;
return V_72 ;
}
F_31 ( V_71 -> V_76 , false ) ;
V_72 = F_32 ( V_71 -> V_76 ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 , L_12 , V_72 ) ;
return V_72 ;
}
V_72 = F_5 ( V_71 -> V_76 , V_5 ,
V_104 , 0 ) ;
if ( V_72 != 0 ) {
F_6 ( V_2 , L_13 , V_72 ) ;
return V_72 ;
}
return 0 ;
}
