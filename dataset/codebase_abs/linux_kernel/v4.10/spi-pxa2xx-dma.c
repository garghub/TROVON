static void F_1 ( struct V_1 * V_2 ,
bool error )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
if ( F_2 ( & V_2 -> V_7 ) ) {
if ( ! error ) {
T_1 V_8 = F_3 ( V_2 , V_9 )
& V_2 -> V_10 ;
error = V_8 & V_11 ;
}
F_4 ( V_2 , V_12 ,
F_3 ( V_2 , V_12 )
& ~ V_2 -> V_13 ) ;
F_5 ( V_2 , V_2 -> V_14 ) ;
if ( ! F_6 ( V_2 ) )
F_4 ( V_2 , V_15 , 0 ) ;
if ( ! error ) {
V_4 -> V_16 += V_2 -> V_17 ;
V_4 -> V_18 = F_7 ( V_2 ) ;
} else {
F_4 ( V_2 , V_19 ,
F_3 ( V_2 , V_19 )
& ~ V_20 ) ;
V_4 -> V_18 = V_21 ;
}
F_8 ( & V_2 -> V_22 ) ;
}
}
static void F_9 ( void * V_23 )
{
F_1 ( V_23 , false ) ;
}
static struct V_24 *
F_10 ( struct V_1 * V_2 ,
enum V_25 V_26 )
{
struct V_27 * V_28 =
F_11 ( V_2 -> V_5 -> V_6 -> V_29 ) ;
struct V_30 * V_31 = V_2 -> V_32 ;
enum V_33 V_34 ;
struct V_35 V_36 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
int V_41 ;
switch ( V_2 -> V_42 ) {
case 1 :
V_34 = V_43 ;
break;
case 2 :
V_34 = V_44 ;
break;
default:
V_34 = V_45 ;
break;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_46 = V_26 ;
if ( V_26 == V_47 ) {
V_36 . V_48 = V_2 -> V_49 ;
V_36 . V_50 = V_34 ;
V_36 . V_51 = V_28 -> V_52 ;
V_40 = & V_31 -> V_53 ;
V_38 = V_2 -> V_5 -> V_54 ;
} else {
V_36 . V_55 = V_2 -> V_49 ;
V_36 . V_56 = V_34 ;
V_36 . V_57 = V_28 -> V_52 ;
V_40 = & V_31 -> V_58 ;
V_38 = V_2 -> V_5 -> V_59 ;
}
V_41 = F_12 ( V_38 , & V_36 ) ;
if ( V_41 ) {
F_13 ( & V_2 -> V_60 -> V_61 , L_1 ) ;
return NULL ;
}
return F_14 ( V_38 , V_40 -> V_62 , V_40 -> V_63 , V_26 ,
V_64 | V_65 ) ;
}
T_2 F_15 ( struct V_1 * V_2 )
{
T_1 V_8 ;
V_8 = F_3 ( V_2 , V_9 ) & V_2 -> V_10 ;
if ( V_8 & V_11 ) {
F_16 ( & V_2 -> V_60 -> V_61 , L_2 ) ;
F_17 ( V_2 -> V_5 -> V_59 ) ;
F_17 ( V_2 -> V_5 -> V_54 ) ;
F_1 ( V_2 , true ) ;
return V_66 ;
}
return V_67 ;
}
int F_18 ( struct V_1 * V_2 , T_1 V_68 )
{
struct V_24 * V_69 , * V_70 ;
int V_71 ;
V_69 = F_10 ( V_2 , V_47 ) ;
if ( ! V_69 ) {
F_16 ( & V_2 -> V_60 -> V_61 ,
L_3 ) ;
V_71 = - V_72 ;
goto V_73;
}
V_70 = F_10 ( V_2 , V_74 ) ;
if ( ! V_70 ) {
F_16 ( & V_2 -> V_60 -> V_61 ,
L_4 ) ;
V_71 = - V_72 ;
goto V_75;
}
V_70 -> V_76 = F_9 ;
V_70 -> V_77 = V_2 ;
F_19 ( V_70 ) ;
F_19 ( V_69 ) ;
return 0 ;
V_75:
F_17 ( V_2 -> V_5 -> V_54 ) ;
V_73:
return V_71 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_5 -> V_59 ) ;
F_21 ( V_2 -> V_5 -> V_54 ) ;
F_22 ( & V_2 -> V_7 , 1 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = V_2 -> V_80 ;
struct V_81 * V_61 = & V_2 -> V_60 -> V_61 ;
struct V_82 * V_5 = V_2 -> V_5 ;
T_3 V_83 ;
F_24 ( V_83 ) ;
F_25 ( V_84 , V_83 ) ;
V_5 -> V_54 = F_26 ( V_83 ,
V_79 -> V_85 , V_79 -> V_86 , V_61 , L_5 ) ;
if ( ! V_5 -> V_54 )
return - V_87 ;
V_5 -> V_59 = F_26 ( V_83 ,
V_79 -> V_85 , V_79 -> V_88 , V_61 , L_6 ) ;
if ( ! V_5 -> V_59 ) {
F_27 ( V_5 -> V_54 ) ;
V_5 -> V_54 = NULL ;
return - V_87 ;
}
return 0 ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_82 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_59 ) {
F_29 ( V_5 -> V_59 ) ;
F_27 ( V_5 -> V_59 ) ;
V_5 -> V_59 = NULL ;
}
if ( V_5 -> V_54 ) {
F_29 ( V_5 -> V_54 ) ;
F_27 ( V_5 -> V_54 ) ;
V_5 -> V_54 = NULL ;
}
}
int F_30 ( struct V_27 * V_28 ,
struct V_89 * V_29 ,
T_4 V_90 , T_1 * V_91 ,
T_1 * V_92 )
{
struct V_93 * V_94 = V_29 -> V_95 ;
* V_91 = V_94 ? V_94 -> V_52 : 1 ;
* V_92 = F_31 ( V_96 )
| F_32 ( V_97 ) ;
return 0 ;
}
