static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 =
F_3 ( V_7 , V_4 - V_4 -> V_8 -> V_4 ) ;
return F_4 ( V_10 -> V_11 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 =
F_3 ( V_7 , V_4 - V_4 -> V_8 -> V_4 ) ;
F_6 ( V_10 -> V_11 ) ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
struct V_9 * V_10 ;
int V_16 = V_4 - V_4 -> V_8 -> V_4 ;
int V_17 ;
V_15 = F_8 ( V_7 , V_16 ) ;
V_10 = F_3 ( V_7 , V_16 ) ;
V_13 = V_15 -> V_18 ?
V_4 -> V_19 :
V_4 -> V_20 ;
if ( V_10 -> V_21 ) {
V_17 = F_9 ( V_13 , V_10 -> V_21 ) ;
if ( V_17 && V_17 != - V_22 ) {
F_10 ( V_13 -> V_23 , L_1 ) ;
goto V_24;
}
}
if ( V_10 -> V_25 ) {
V_17 = F_11 ( V_13 , 0 , V_10 -> V_25 , 0 ) ;
if ( V_17 && V_17 != - V_22 ) {
F_10 ( V_13 -> V_23 , L_2 ) ;
goto V_24;
}
}
V_17 = 0 ;
V_24:
return V_17 ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_28 * V_29 = F_13 ( V_27 ,
V_30 ) ;
if ( ! V_7 -> V_31 )
return 0 ;
V_29 -> V_32 = V_29 -> V_33 = V_7 -> V_31 ;
return 0 ;
}
static int F_14 ( struct V_34 * V_35 ,
struct V_34 * V_36 ,
struct V_6 * V_7 ,
int V_37 , bool V_38 )
{
struct V_9 * V_10 = F_3 ( V_7 , V_37 ) ;
struct V_34 * V_39 = NULL ;
struct V_34 * V_40 = NULL ;
struct V_34 * V_41 = V_38 ? NULL : V_36 ;
unsigned int V_42 ;
V_42 = F_15 ( V_35 , NULL ,
& V_39 , & V_40 ) ;
V_42 &= ~ V_43 ;
if ( ! V_39 && ! V_40 )
return - V_44 ;
if ( V_41 == V_39 )
V_42 |= ( V_41 == V_40 ) ?
V_45 : V_46 ;
else
V_42 |= ( V_41 == V_40 ) ?
V_47 : V_48 ;
V_10 -> V_21 = V_42 ;
F_16 ( V_39 ) ;
F_16 ( V_40 ) ;
return 0 ;
}
static int F_17 ( struct V_34 * V_36 ,
struct V_6 * V_7 ,
int V_37 , bool V_38 )
{
struct V_14 * V_15 = F_8 ( V_7 , V_37 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_37 ) ;
struct V_49 args ;
int V_17 ;
V_17 = F_18 ( V_36 , L_3 ,
L_4 , 0 , & args ) ;
if ( V_17 )
return V_17 ;
if ( V_38 ) {
V_15 -> V_50 = NULL ;
V_15 -> V_51 = L_5 ;
V_15 -> V_52 = L_6 ;
V_15 -> V_18 = 1 ;
V_15 -> V_53 = 1 ;
V_15 -> V_54 = args . V_36 ;
F_19 ( V_36 , & V_15 -> V_55 ) ;
snprintf ( V_10 -> V_56 , V_57 , L_7 ,
V_15 -> V_55 ) ;
if ( ! args . V_58 )
V_15 -> V_55 = NULL ;
} else {
struct V_59 * V_23 = F_20 ( V_7 ) ;
const struct V_60 * V_61 ;
V_61 = F_21 ( V_23 ) ;
V_15 -> V_54 = NULL ;
V_15 -> V_55 = L_5 ;
V_15 -> V_62 = L_6 ;
V_15 -> V_63 = 1 ;
V_15 -> V_64 = F_12 ;
V_15 -> V_50 = args . V_36 ;
F_19 ( V_36 , & V_15 -> V_51 ) ;
if ( V_61 ) {
V_7 -> V_65 . V_66 = V_15 -> V_50 ;
V_7 -> V_65 . V_67 = V_61 -> V_68 ;
} else {
F_22 ( & V_7 -> V_69 ,
& V_7 -> V_65 ,
V_15 -> V_50 ,
L_8 ) ;
}
snprintf ( V_10 -> V_56 , V_57 , L_9 ,
V_15 -> V_51 ) ;
}
V_15 -> V_70 = V_15 -> V_54 ;
V_15 -> V_71 = 1 ;
V_15 -> V_72 = 1 ;
V_15 -> V_73 = V_10 -> V_56 ;
V_15 -> V_74 = V_10 -> V_56 ;
V_15 -> V_75 = & V_76 ;
V_15 -> V_77 = F_7 ;
return 0 ;
}
static int F_23 ( struct V_34 * V_36 ,
struct V_6 * V_7 ,
int V_37 , bool V_38 )
{
struct V_14 * V_15 = F_8 ( V_7 , V_37 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_37 ) ;
struct V_11 * V_11 ;
struct V_34 * V_78 = V_38 ? V_15 -> V_54 :
V_15 -> V_50 ;
T_1 V_79 ;
if ( F_24 ( V_36 , L_10 ) ) {
V_11 = F_25 ( V_36 , 0 ) ;
if ( F_26 ( V_11 ) )
return F_27 ( V_11 ) ;
V_10 -> V_25 = F_28 ( V_11 ) ;
V_10 -> V_11 = V_11 ;
} else if ( ! F_29 ( V_36 , L_11 , & V_79 ) ) {
V_10 -> V_25 = V_79 ;
} else {
V_11 = F_25 ( V_78 , 0 ) ;
if ( ! F_26 ( V_11 ) )
V_10 -> V_25 = F_28 ( V_11 ) ;
}
return 0 ;
}
static int F_30 ( struct V_34 * V_35 ,
struct V_34 * V_36 ,
struct V_6 * V_7 ,
int V_37 )
{
struct V_59 * V_23 = F_20 ( V_7 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_37 ) ;
bool V_38 = false ;
int V_17 ;
if ( 0 == strcmp ( V_36 -> V_73 , L_12 ) )
V_38 = true ;
V_17 = F_14 ( V_35 , V_36 , V_7 , V_37 , V_38 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_17 ( V_36 , V_7 , V_37 , V_38 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_23 ( V_36 , V_7 , V_37 , V_38 ) ;
if ( V_17 < 0 )
return V_17 ;
F_31 ( V_23 , L_13 ,
V_10 -> V_56 ,
V_10 -> V_21 ,
V_10 -> V_25 ) ;
return V_17 ;
}
static int F_32 ( struct V_34 * V_35 ,
struct V_6 * V_7 ,
struct V_59 * V_23 )
{
const struct V_60 * V_61 = F_21 ( V_23 ) ;
struct V_9 * V_80 ;
struct V_14 * V_81 ;
struct V_34 * V_36 ;
int V_17 ;
int V_82 , V_16 ;
if ( ! V_35 )
return - V_44 ;
V_16 = F_33 ( V_35 ) ;
V_80 = F_34 ( V_23 , sizeof( * V_80 ) * V_16 , V_83 ) ;
V_81 = F_34 ( V_23 , sizeof( * V_81 ) * V_16 , V_83 ) ;
if ( ! V_80 || ! V_81 )
return - V_84 ;
V_7 -> V_10 = V_80 ;
V_7 -> V_15 = V_81 ;
V_7 -> V_85 = V_16 ;
V_7 -> V_69 . V_86 = V_87 ;
V_7 -> V_69 . V_23 = V_23 ;
V_7 -> V_69 . V_15 = V_7 -> V_15 ;
V_7 -> V_69 . V_88 = V_16 ;
V_7 -> V_69 . V_65 = & V_7 -> V_65 ;
V_7 -> V_69 . V_89 = 1 ;
if ( V_61 ) {
V_7 -> V_69 . V_90 = V_61 -> V_91 ;
V_7 -> V_69 . V_92 = V_61 -> V_93 ;
} else {
F_35 ( & V_7 -> V_69 ,
L_14 ) ;
}
F_36 ( & V_7 -> V_69 , L_15 ) ;
F_29 ( V_35 , L_16 , & V_7 -> V_31 ) ;
F_31 ( V_23 , L_17 ,
V_7 -> V_69 . V_73 ? V_7 -> V_69 . V_73 : L_18 ,
V_7 -> V_31 ) ;
V_82 = 0 ;
F_37 (node, np) {
V_17 = F_30 ( V_35 , V_36 , V_7 , V_82 ) ;
if ( V_17 < 0 )
return V_17 ;
V_82 ++ ;
}
if ( ! V_7 -> V_69 . V_73 )
V_7 -> V_69 . V_73 = V_7 -> V_69 . V_15 -> V_73 ;
return 0 ;
}
static int F_38 ( struct V_94 * V_8 )
{
struct V_14 * V_15 ;
int V_88 ;
for ( V_88 = 0 , V_15 = V_8 -> V_15 ;
V_88 < V_8 -> V_88 ;
V_88 ++ , V_15 ++ ) {
F_16 ( V_15 -> V_54 ) ;
F_16 ( V_15 -> V_50 ) ;
}
return 0 ;
}
static int F_39 ( struct V_95 * V_96 )
{
struct V_6 * V_7 ;
struct V_34 * V_36 = V_96 -> V_23 . V_66 ;
struct V_59 * V_23 = & V_96 -> V_23 ;
int V_17 ;
V_7 = F_34 ( V_23 , sizeof( * V_7 ) , V_83 ) ;
if ( ! V_7 )
return - V_84 ;
V_17 = F_32 ( V_36 , V_7 , V_23 ) ;
if ( V_17 < 0 ) {
if ( V_17 != - V_97 )
F_10 ( V_23 , L_19 , V_17 ) ;
goto V_24;
}
F_40 ( & V_7 -> V_69 , V_7 ) ;
V_17 = F_41 ( & V_96 -> V_23 , & V_7 -> V_69 ) ;
if ( V_17 >= 0 )
return V_17 ;
V_24:
F_38 ( & V_7 -> V_69 ) ;
return V_17 ;
}
static int F_42 ( struct V_95 * V_96 )
{
struct V_94 * V_8 = F_43 ( V_96 ) ;
return F_38 ( V_8 ) ;
}
