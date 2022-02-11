static void F_1 ( struct V_1 * V_2 ,
bool error )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( F_2 ( & V_2 -> V_6 ) ) {
if ( ! error ) {
T_1 V_7 = F_3 ( V_2 , V_8 )
& V_2 -> V_9 ;
error = V_7 & V_10 ;
}
F_4 ( V_2 , V_11 ,
F_3 ( V_2 , V_11 )
& ~ V_2 -> V_12 ) ;
F_5 ( V_2 , V_2 -> V_13 ) ;
if ( ! F_6 ( V_2 ) )
F_4 ( V_2 , V_14 , 0 ) ;
if ( ! error ) {
V_4 -> V_15 += V_2 -> V_16 ;
V_4 -> V_17 = F_7 ( V_2 ) ;
} else {
F_4 ( V_2 , V_18 ,
F_3 ( V_2 , V_18 )
& ~ V_19 ) ;
V_4 -> V_17 = V_20 ;
}
F_8 ( & V_2 -> V_21 ) ;
}
}
static void F_9 ( void * V_22 )
{
F_1 ( V_22 , false ) ;
}
static struct V_23 *
F_10 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
struct V_26 * V_27 = V_2 -> V_28 ;
struct V_29 * V_30 = V_2 -> V_31 ;
enum V_32 V_33 ;
struct V_34 V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
int V_40 ;
switch ( V_2 -> V_41 ) {
case 1 :
V_33 = V_42 ;
break;
case 2 :
V_33 = V_43 ;
break;
default:
V_33 = V_44 ;
break;
}
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_45 = V_25 ;
if ( V_25 == V_46 ) {
V_35 . V_47 = V_2 -> V_48 ;
V_35 . V_49 = V_33 ;
V_35 . V_50 = V_27 -> V_51 ;
V_39 = & V_30 -> V_52 ;
V_37 = V_2 -> V_53 -> V_54 ;
} else {
V_35 . V_55 = V_2 -> V_48 ;
V_35 . V_56 = V_33 ;
V_35 . V_57 = V_27 -> V_51 ;
V_39 = & V_30 -> V_58 ;
V_37 = V_2 -> V_53 -> V_59 ;
}
V_40 = F_11 ( V_37 , & V_35 ) ;
if ( V_40 ) {
F_12 ( & V_2 -> V_60 -> V_61 , L_1 ) ;
return NULL ;
}
return F_13 ( V_37 , V_39 -> V_62 , V_39 -> V_63 , V_25 ,
V_64 | V_65 ) ;
}
T_2 F_14 ( struct V_1 * V_2 )
{
T_1 V_7 ;
V_7 = F_3 ( V_2 , V_8 ) & V_2 -> V_9 ;
if ( V_7 & V_10 ) {
F_15 ( & V_2 -> V_60 -> V_61 , L_2 ) ;
F_16 ( V_2 -> V_53 -> V_59 ) ;
F_16 ( V_2 -> V_53 -> V_54 ) ;
F_1 ( V_2 , true ) ;
return V_66 ;
}
return V_67 ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_68 )
{
struct V_23 * V_69 , * V_70 ;
int V_71 = 0 ;
V_69 = F_10 ( V_2 , V_46 ) ;
if ( ! V_69 ) {
F_15 ( & V_2 -> V_60 -> V_61 ,
L_3 ) ;
V_71 = - V_72 ;
goto V_73;
}
V_70 = F_10 ( V_2 , V_74 ) ;
if ( ! V_70 ) {
F_15 ( & V_2 -> V_60 -> V_61 ,
L_4 ) ;
V_71 = - V_72 ;
goto V_75;
}
V_70 -> V_76 = F_9 ;
V_70 -> V_77 = V_2 ;
F_18 ( V_70 ) ;
F_18 ( V_69 ) ;
return 0 ;
V_75:
F_16 ( V_2 -> V_53 -> V_54 ) ;
V_73:
return V_71 ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_53 -> V_59 ) ;
F_20 ( V_2 -> V_53 -> V_54 ) ;
F_21 ( & V_2 -> V_6 , 1 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = V_2 -> V_80 ;
struct V_81 * V_61 = & V_2 -> V_60 -> V_61 ;
struct V_82 * V_53 = V_2 -> V_53 ;
T_3 V_83 ;
F_23 ( V_83 ) ;
F_24 ( V_84 , V_83 ) ;
V_53 -> V_54 = F_25 ( V_83 ,
V_79 -> V_85 , V_79 -> V_86 , V_61 , L_5 ) ;
if ( ! V_53 -> V_54 )
return - V_87 ;
V_53 -> V_59 = F_25 ( V_83 ,
V_79 -> V_85 , V_79 -> V_88 , V_61 , L_6 ) ;
if ( ! V_53 -> V_59 ) {
F_26 ( V_53 -> V_54 ) ;
V_53 -> V_54 = NULL ;
return - V_87 ;
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_82 * V_53 = V_2 -> V_53 ;
if ( V_53 -> V_59 ) {
F_28 ( V_53 -> V_59 ) ;
F_26 ( V_53 -> V_59 ) ;
V_53 -> V_59 = NULL ;
}
if ( V_53 -> V_54 ) {
F_28 ( V_53 -> V_54 ) ;
F_26 ( V_53 -> V_54 ) ;
V_53 -> V_54 = NULL ;
}
}
int F_29 ( struct V_26 * V_27 ,
struct V_89 * V_90 ,
T_4 V_91 , T_1 * V_92 ,
T_1 * V_93 )
{
struct V_94 * V_95 = V_90 -> V_96 ;
* V_92 = V_95 ? V_95 -> V_51 : 1 ;
* V_93 = F_30 ( V_97 )
| F_31 ( V_98 ) ;
return 0 ;
}
