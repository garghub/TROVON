static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_8 . V_7 ;
struct V_6 * V_9 = V_2 -> V_10 . V_7 ;
if ( ! V_7 ) {
F_2 ( V_2 -> V_11 ,
L_1 ,
V_4 -> V_12 , V_4 -> V_13 ) ;
return - V_14 ;
}
F_3 ( V_2 -> V_11 ,
L_2 ,
V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_4 -> V_13 == V_15 ) {
V_2 -> V_16 = 0 ;
if ( V_9 && V_2 -> V_17 ) {
F_4 ( & V_2 -> V_10 , 0 ,
V_2 -> V_18 ) ;
V_2 -> V_17 = 0 ;
}
F_4 ( & V_2 -> V_8 , 0 ,
V_2 -> V_19 ) ;
return 0 ;
}
V_5 = V_4 -> V_12 & V_2 -> V_19 ;
if ( ! V_5 ) {
F_2 ( V_2 -> V_11 ,
L_1 ,
V_4 -> V_12 , V_4 -> V_13 ) ;
return - V_14 ;
}
if ( V_2 -> V_16 )
F_3 ( V_2 -> V_11 ,
L_3 ,
V_2 -> V_16 , V_5 ) ;
V_2 -> V_16 = V_5 ;
F_4 ( & V_2 -> V_8 , V_5 , V_2 -> V_19 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_20 * V_4 )
{
int V_21 , V_5 ;
struct V_6 * V_9 = V_2 -> V_10 . V_7 ;
if ( ! V_9 ) {
F_2 ( V_2 -> V_11 ,
L_4 ,
V_4 -> V_22 , V_4 -> V_13 ) ;
return - V_14 ;
}
F_3 ( V_2 -> V_11 ,
L_5 ,
V_4 -> V_22 , V_4 -> V_13 ) ;
if ( ! V_2 -> V_16 ) {
F_2 ( V_2 -> V_11 ,
L_6 ) ;
return - V_14 ;
}
V_5 = V_2 -> V_17 & V_2 -> V_18 ;
V_21 = 0 ;
switch ( V_4 -> V_22 ) {
case 1 :
V_21 = V_23 & V_2 -> V_18 ;
break;
case 2 :
V_21 = V_24 & V_2 -> V_18 ;
break;
case 3 :
V_21 = V_25 & V_2 -> V_18 ;
break;
case 4 :
V_21 = V_26 & V_2 -> V_18 ;
break;
}
if ( ! V_21 ) {
F_2 ( V_2 -> V_11 ,
L_7 ) ;
return - V_14 ;
}
if ( V_4 -> V_13 == V_27 )
V_5 = V_5 | V_21 ;
else
V_5 = V_5 & ~ V_21 ;
V_2 -> V_17 = V_5 ;
F_4 ( & V_2 -> V_10 , V_5 , V_2 -> V_18 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_28 * V_4 )
{
F_7 ( V_2 -> V_11 , L_8 ,
V_4 -> V_29 , V_4 -> V_13 ) ;
return 0 ;
}
static int F_8 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_1 * V_2 =
F_9 ( V_33 -> V_34 ) ;
struct V_35 * V_36 = V_31 -> V_37 -> V_36 ;
struct V_28 * V_38 ;
struct V_3 * V_39 ;
struct V_20 * V_40 ;
int V_41 ;
switch ( V_36 -> type ) {
case V_42 :
V_38 = V_31 -> V_37 -> V_43 ;
V_41 = F_6 ( V_2 , V_38 ) ;
break;
case V_44 :
V_39 = V_31 -> V_37 -> V_43 ;
V_41 = F_1 ( V_2 , V_39 ) ;
break;
case V_45 :
V_40 = V_31 -> V_37 -> V_43 ;
V_41 = F_5 ( V_2 , V_40 ) ;
break;
default:
F_2 ( & V_33 -> V_34 -> V_11 ,
L_9 ) ;
return - V_14 ;
}
return V_41 ;
}
static int F_10 ( struct V_1 * V_46 ,
struct V_47 * V_48 ,
struct V_49 * V_34 )
{
struct V_32 * V_33 ;
if ( V_46 -> V_50 ) {
F_11 ( & V_34 -> V_11 ,
L_10 ) ;
return - V_51 ;
}
V_33 = F_12 ( V_34 , F_13 ( V_48 -> V_52 ) ,
F_8 ) ;
if ( F_14 ( V_33 ) )
return F_15 ( V_33 ) ;
F_16 ( V_34 , V_46 ) ;
V_46 -> V_50 = V_33 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_46 ,
struct V_47 * V_48 ,
struct V_49 * V_34 )
{
struct V_32 * V_33 ;
struct V_53 * V_54 ;
V_54 = F_18 ( V_46 -> V_11 , sizeof( * V_54 ) , V_55 ) ;
if ( ! V_54 ) {
F_11 ( V_46 -> V_11 , L_11 ) ;
return - V_56 ;
}
V_33 = F_19 ( V_34 ,
F_13 ( V_48 -> V_52 ) ,
V_57 ) ;
if ( F_14 ( V_33 ) ) {
F_20 ( V_46 -> V_11 , V_54 ) ;
return F_15 ( V_33 ) ;
}
F_16 ( V_34 , V_46 ) ;
V_54 -> V_52 = 0 ;
V_54 -> V_29 = V_33 -> V_58 ;
V_54 -> V_33 = V_33 ;
F_21 ( & V_54 -> V_59 , & V_46 -> V_60 ) ;
return 0 ;
}
static int F_22 ( struct V_49 * V_34 ,
const struct V_61 * V_52 )
{
struct V_62 * V_11 = & V_34 -> V_11 ;
struct V_1 * V_46 ;
struct V_47 * V_48 ;
struct V_63 V_64 ;
struct V_53 * V_54 , * V_65 ;
int V_41 , V_66 ;
struct V_67 * V_68 ;
if ( V_34 -> V_69 < 2 )
return - V_51 ;
V_46 = F_18 ( V_11 , sizeof( * V_46 ) , V_55 ) ;
if ( ! V_46 )
return - V_56 ;
V_46 -> V_70 = V_34 -> V_69 - 1 ;
F_23 ( & V_46 -> V_60 ) ;
F_23 ( & V_46 -> V_71 ) ;
F_23 ( & V_46 -> V_72 ) ;
F_23 ( & V_46 -> V_73 ) ;
V_46 -> V_11 = V_11 ;
snprintf ( V_46 -> V_74 , V_75 , L_12 , V_11 -> V_76 -> V_74 ,
F_24 ( V_11 ) ) ;
F_16 ( V_34 , V_46 ) ;
for ( V_66 = 0 ; V_66 < V_34 -> V_69 ; V_66 ++ ) {
V_48 = & V_34 -> V_48 [ V_66 ] ;
switch ( V_48 -> V_77 ) {
case V_78 :
V_41 = F_10 ( V_46 , V_48 ,
V_34 ) ;
if ( V_41 )
goto V_79;
break;
case V_80 :
V_41 = F_17 ( V_46 , V_48 ,
V_34 ) ;
if ( V_41 )
goto V_79;
break;
default:
F_11 ( V_11 , L_13 ,
V_48 -> V_77 ) ;
V_41 = - V_51 ;
goto V_79;
}
}
if ( ! V_46 -> V_50 ) {
V_41 = - V_14 ;
F_11 ( V_11 , L_14 ) ;
goto V_79;
}
V_41 = F_25 ( V_46 -> V_50 ) ;
if ( V_41 ) {
F_11 ( V_11 , L_15 , V_41 ) ;
goto V_79;
}
V_46 -> V_81 = V_46 -> V_50 -> V_82 -> V_83 ;
V_41 = F_26 ( V_46 -> V_50 , & V_68 ) ;
if ( V_41 ) {
F_11 ( V_11 , L_16 , V_41 ) ;
goto V_84;
}
V_41 = F_27 ( V_46 , V_68 ) ;
if ( V_41 ) {
F_11 ( V_11 , L_17 ,
V_41 ) ;
goto V_85;
}
V_46 -> V_68 = V_68 ;
F_28 (dai, &gbmodule->data_list, list) {
V_41 = F_25 ( V_54 -> V_33 ) ;
if ( V_41 ) {
F_11 ( V_11 ,
L_18 ,
V_41 , V_54 -> V_29 ) ;
goto V_86;
}
}
V_41 = F_29 ( V_46 ) ;
if ( V_41 )
goto V_86;
F_30 ( V_11 , L_19 , 1 ) ;
F_31 ( V_64 . V_74 , V_46 -> V_74 , V_87 ) ;
V_64 . V_88 = 1 ;
V_64 . V_89 = 2 ;
V_64 . V_90 = 3 ;
V_64 . V_91 = V_46 -> V_81 ;
V_64 . V_92 = V_46 -> V_92 ;
V_64 . V_93 = V_46 -> V_93 ;
V_46 -> V_94 = F_32 ( & V_64 ) ;
F_30 ( V_11 , L_20 , V_46 -> V_74 ) ;
F_33 ( V_34 ) ;
return 0 ;
V_86:
F_34 (dai, _dai, &gbmodule->data_list, list)
F_35 ( V_54 -> V_33 ) ;
F_36 ( V_46 ) ;
V_46 -> V_68 = NULL ;
V_85:
F_37 ( V_68 ) ;
V_84:
F_35 ( V_46 -> V_50 ) ;
V_79:
F_34 (dai, _dai, &gbmodule->data_list, list) {
F_38 ( V_54 -> V_33 ) ;
F_39 ( & V_54 -> V_59 ) ;
F_20 ( V_11 , V_54 ) ;
}
if ( V_46 -> V_50 )
F_38 ( V_46 -> V_50 ) ;
F_20 ( V_11 , V_46 ) ;
return V_41 ;
}
static void F_40 ( struct V_49 * V_34 )
{
struct V_1 * V_46 = F_9 ( V_34 ) ;
struct V_53 * V_54 , * V_65 ;
F_41 ( V_34 ) ;
F_42 ( V_46 ) ;
F_43 ( V_46 -> V_94 ) ;
F_36 ( V_46 ) ;
F_37 ( V_46 -> V_68 ) ;
V_46 -> V_68 = NULL ;
F_35 ( V_46 -> V_50 ) ;
F_34 (dai, _dai, &gbmodule->data_list, list) {
F_35 ( V_54 -> V_33 ) ;
F_38 ( V_54 -> V_33 ) ;
F_39 ( & V_54 -> V_59 ) ;
F_20 ( V_46 -> V_11 , V_54 ) ;
}
F_38 ( V_46 -> V_50 ) ;
V_46 -> V_50 = NULL ;
F_20 ( & V_34 -> V_11 , V_46 ) ;
}
static int F_44 ( struct V_62 * V_11 )
{
struct V_49 * V_34 = F_45 ( V_11 ) ;
struct V_1 * V_46 = F_9 ( V_34 ) ;
struct V_53 * V_54 ;
F_28 (dai, &gbmodule->data_list, list)
F_35 ( V_54 -> V_33 ) ;
F_35 ( V_46 -> V_50 ) ;
return 0 ;
}
static int F_46 ( struct V_62 * V_11 )
{
struct V_49 * V_34 = F_45 ( V_11 ) ;
struct V_1 * V_46 = F_9 ( V_34 ) ;
struct V_53 * V_54 ;
int V_41 ;
V_41 = F_25 ( V_46 -> V_50 ) ;
if ( V_41 ) {
F_11 ( V_11 , L_21 , V_41 ) ;
return V_41 ;
}
F_28 (dai, &gbmodule->data_list, list) {
V_41 = F_25 ( V_54 -> V_33 ) ;
if ( V_41 ) {
F_11 ( V_11 ,
L_18 ,
V_41 , V_54 -> V_29 ) ;
return V_41 ;
}
}
return 0 ;
}
