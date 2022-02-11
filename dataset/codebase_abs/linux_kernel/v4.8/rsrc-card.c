static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 =
F_3 ( V_7 , V_4 -> V_11 ) ;
return F_4 ( V_10 -> V_12 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 =
F_3 ( V_7 , V_4 -> V_11 ) ;
F_6 ( V_10 -> V_12 ) ;
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_11 = V_4 -> V_11 ;
int V_17 ;
V_16 = F_8 ( V_7 , V_11 ) ;
V_10 = F_3 ( V_7 , V_11 ) ;
V_14 = V_16 -> V_18 ?
V_4 -> V_19 :
V_4 -> V_20 ;
if ( V_10 -> V_21 ) {
V_17 = F_9 ( V_14 , 0 , V_10 -> V_21 , 0 ) ;
if ( V_17 && V_17 != - V_22 ) {
F_10 ( V_14 -> V_23 , L_1 ) ;
goto V_24;
}
}
if ( V_10 -> V_25 ) {
V_17 = F_11 ( V_14 ,
V_10 -> V_26 ,
V_10 -> V_27 ,
V_10 -> V_25 ,
V_10 -> V_28 ) ;
if ( V_17 && V_17 != - V_22 ) {
F_10 ( V_14 -> V_23 , L_2 ) ;
goto V_24;
}
}
V_17 = 0 ;
V_24:
return V_17 ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_29 * V_30 )
{
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_31 * V_32 = F_13 ( V_30 ,
V_33 ) ;
struct V_31 * V_34 = F_13 ( V_30 ,
V_35 ) ;
if ( V_7 -> V_36 )
V_32 -> V_37 =
V_32 -> V_38 = V_7 -> V_36 ;
if ( V_7 -> V_39 )
V_34 -> V_37 =
V_34 -> V_38 = V_7 -> V_39 ;
return 0 ;
}
static int F_14 ( struct V_40 * V_41 ,
struct V_6 * V_7 ,
int V_42 , bool V_43 )
{
struct V_44 * V_23 = F_15 ( V_7 ) ;
struct V_15 * V_16 = F_8 ( V_7 , V_42 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_42 ) ;
struct V_45 args ;
int V_17 ;
V_17 = F_16 ( V_41 , L_3 ,
L_4 , 0 , & args ) ;
if ( V_17 )
return V_17 ;
V_17 = F_17 ( V_41 ,
& V_10 -> V_26 ,
& V_10 -> V_27 ,
& V_10 -> V_25 ,
& V_10 -> V_28 ) ;
if ( V_17 )
return V_17 ;
if ( V_43 ) {
V_16 -> V_46 = NULL ;
V_16 -> V_47 = L_5 ;
V_16 -> V_48 = L_6 ;
V_16 -> V_18 = 1 ;
V_16 -> V_49 = 1 ;
V_16 -> V_50 = args . V_41 ;
V_17 = F_18 ( V_41 , & V_16 -> V_51 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_19 ( V_23 , V_16 ,
L_7 ,
V_16 -> V_51 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( ! args . V_52 )
V_16 -> V_51 = NULL ;
} else {
const struct V_53 * V_54 ;
V_54 = F_20 ( V_23 ) ;
V_16 -> V_50 = NULL ;
V_16 -> V_51 = L_5 ;
V_16 -> V_55 = L_6 ;
V_16 -> V_56 = 1 ;
V_16 -> V_57 = F_12 ;
V_16 -> V_46 = args . V_41 ;
V_17 = F_18 ( V_41 , & V_16 -> V_47 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_19 ( V_23 , V_16 ,
L_8 ,
V_16 -> V_47 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_54 ) {
V_7 -> V_58 . V_59 = V_16 -> V_46 ;
V_7 -> V_58 . V_60 = V_54 -> V_61 ;
} else {
F_21 ( & V_7 -> V_62 ,
& V_7 -> V_58 ,
V_16 -> V_46 ,
L_9 ) ;
}
}
V_16 -> V_63 = V_16 -> V_50 ;
V_16 -> V_64 = 1 ;
V_16 -> V_65 = 1 ;
V_16 -> V_66 = & V_67 ;
V_16 -> V_68 = F_7 ;
return 0 ;
}
static int F_22 ( struct V_40 * V_41 ,
struct V_6 * V_7 ,
int V_42 , bool V_43 )
{
struct V_15 * V_16 = F_8 ( V_7 , V_42 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_42 ) ;
struct V_12 * V_12 ;
struct V_40 * V_69 = V_43 ? V_16 -> V_50 :
V_16 -> V_46 ;
T_1 V_70 ;
if ( F_23 ( V_41 , L_10 ) ) {
V_12 = F_24 ( V_41 , 0 ) ;
if ( F_25 ( V_12 ) )
return F_26 ( V_12 ) ;
V_10 -> V_21 = F_27 ( V_12 ) ;
V_10 -> V_12 = V_12 ;
} else if ( ! F_28 ( V_41 , L_11 , & V_70 ) ) {
V_10 -> V_21 = V_70 ;
} else {
V_12 = F_24 ( V_69 , 0 ) ;
if ( ! F_25 ( V_12 ) )
V_10 -> V_21 = F_27 ( V_12 ) ;
}
return 0 ;
}
static int F_29 ( struct V_40 * V_71 ,
struct V_40 * V_41 ,
struct V_6 * V_7 ,
int V_42 , bool V_43 )
{
struct V_44 * V_23 = F_15 ( V_7 ) ;
struct V_15 * V_16 = F_8 ( V_7 , V_42 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_42 ) ;
int V_17 ;
V_17 = F_14 ( V_41 , V_7 , V_42 , V_43 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_22 ( V_41 , V_7 , V_42 , V_43 ) ;
if ( V_17 < 0 )
return V_17 ;
F_30 ( V_23 , L_12 ,
V_16 -> V_72 ,
V_16 -> V_73 ,
V_10 -> V_21 ) ;
return V_17 ;
}
static int F_31 ( struct V_40 * V_71 ,
struct V_6 * V_7 )
{
struct V_44 * V_23 = F_15 ( V_7 ) ;
struct V_15 * V_16 ;
struct V_40 * V_41 ;
unsigned int V_74 = 0 ;
int V_17 , V_75 ;
bool V_43 ;
V_75 = 0 ;
F_32 (node, np) {
V_16 = F_8 ( V_7 , V_75 ) ;
if ( strcmp ( V_41 -> V_72 , L_13 ) == 0 ) {
V_17 = F_33 ( V_23 , V_71 , V_41 ,
NULL , & V_74 ) ;
if ( V_17 < 0 )
return V_17 ;
break;
}
V_75 ++ ;
}
V_75 = 0 ;
F_32 (node, np) {
V_16 = F_8 ( V_7 , V_75 ) ;
V_16 -> V_73 = V_74 ;
V_43 = false ;
if ( strcmp ( V_41 -> V_72 , L_14 ) == 0 )
V_43 = true ;
V_17 = F_29 ( V_71 , V_41 , V_7 , V_75 , V_43 ) ;
if ( V_17 < 0 )
return V_17 ;
V_75 ++ ;
}
return 0 ;
}
static int F_34 ( struct V_40 * V_71 ,
struct V_6 * V_7 ,
struct V_44 * V_23 )
{
const struct V_53 * V_54 = F_20 ( V_23 ) ;
struct V_9 * V_76 ;
struct V_15 * V_77 ;
int V_17 ;
int V_11 ;
if ( ! V_71 )
return - V_78 ;
V_11 = F_35 ( V_71 ) ;
V_76 = F_36 ( V_23 , sizeof( * V_76 ) * V_11 , V_79 ) ;
V_77 = F_36 ( V_23 , sizeof( * V_77 ) * V_11 , V_79 ) ;
if ( ! V_76 || ! V_77 )
return - V_80 ;
V_7 -> V_10 = V_76 ;
V_7 -> V_16 = V_77 ;
V_7 -> V_62 . V_81 = V_82 ;
V_7 -> V_62 . V_23 = V_23 ;
V_7 -> V_62 . V_16 = V_7 -> V_16 ;
V_7 -> V_62 . V_83 = V_11 ;
V_7 -> V_62 . V_58 = & V_7 -> V_58 ;
V_7 -> V_62 . V_84 = 1 ;
if ( V_54 ) {
V_7 -> V_62 . V_85 = V_54 -> V_86 ;
V_7 -> V_62 . V_87 = V_54 -> V_88 ;
} else {
F_37 ( & V_7 -> V_62 ,
L_15 ) ;
}
F_28 ( V_71 , L_16 , & V_7 -> V_36 ) ;
F_28 ( V_71 , L_17 , & V_7 -> V_39 ) ;
F_30 ( V_23 , L_18 ,
V_7 -> V_62 . V_72 ? V_7 -> V_62 . V_72 : L_19 ) ;
F_30 ( V_23 , L_20 , V_7 -> V_36 ) ;
F_30 ( V_23 , L_21 , V_7 -> V_39 ) ;
V_17 = F_31 ( V_71 , V_7 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_38 ( & V_7 -> V_62 , L_22 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_39 ( struct V_89 * V_8 )
{
struct V_15 * V_16 ;
int V_83 ;
for ( V_83 = 0 , V_16 = V_8 -> V_16 ;
V_83 < V_8 -> V_83 ;
V_83 ++ , V_16 ++ ) {
F_40 ( V_16 -> V_50 ) ;
F_40 ( V_16 -> V_46 ) ;
}
return 0 ;
}
static int F_41 ( struct V_90 * V_91 )
{
struct V_6 * V_7 ;
struct V_40 * V_41 = V_91 -> V_23 . V_59 ;
struct V_44 * V_23 = & V_91 -> V_23 ;
int V_17 ;
V_7 = F_36 ( V_23 , sizeof( * V_7 ) , V_79 ) ;
if ( ! V_7 )
return - V_80 ;
V_17 = F_34 ( V_41 , V_7 , V_23 ) ;
if ( V_17 < 0 ) {
if ( V_17 != - V_92 )
F_10 ( V_23 , L_23 , V_17 ) ;
goto V_24;
}
F_42 ( & V_7 -> V_62 , V_7 ) ;
V_17 = F_43 ( & V_91 -> V_23 , & V_7 -> V_62 ) ;
if ( V_17 >= 0 )
return V_17 ;
V_24:
F_39 ( & V_7 -> V_62 ) ;
return V_17 ;
}
static int F_44 ( struct V_90 * V_91 )
{
struct V_89 * V_8 = F_45 ( V_91 ) ;
return F_39 ( V_8 ) ;
}
