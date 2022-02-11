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
if ( ! V_7 -> V_34 )
return 0 ;
V_32 -> V_35 = V_32 -> V_36 = V_7 -> V_34 ;
return 0 ;
}
static int F_14 ( struct V_37 * V_38 ,
struct V_37 * V_39 ,
struct V_6 * V_7 ,
struct V_15 * V_16 ,
unsigned int * V_40 )
{
struct V_37 * V_41 = NULL ;
struct V_37 * V_42 = NULL ;
unsigned int V_43 ;
V_43 = F_15 ( V_38 , NULL ,
& V_41 , & V_42 ) ;
V_43 &= ~ V_44 ;
if ( ! V_41 && ! V_42 )
return - V_45 ;
if ( V_39 == V_41 )
V_43 |= ( V_39 == V_42 ) ?
V_46 : V_47 ;
else
V_43 |= ( V_39 == V_42 ) ?
V_48 : V_49 ;
F_16 ( V_41 ) ;
F_16 ( V_42 ) ;
* V_40 = V_43 ;
return 0 ;
}
static int F_17 ( struct V_37 * V_50 ,
struct V_6 * V_7 ,
int V_51 , bool V_52 )
{
struct V_15 * V_16 = F_8 ( V_7 , V_51 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_51 ) ;
struct V_53 args ;
int V_17 ;
V_17 = F_18 ( V_50 , L_3 ,
L_4 , 0 , & args ) ;
if ( V_17 )
return V_17 ;
V_17 = F_19 ( V_50 ,
& V_10 -> V_26 ,
& V_10 -> V_27 ,
& V_10 -> V_25 ,
& V_10 -> V_28 ) ;
if ( V_17 )
return V_17 ;
if ( V_52 ) {
V_16 -> V_54 = NULL ;
V_16 -> V_55 = L_5 ;
V_16 -> V_56 = L_6 ;
V_16 -> V_18 = 1 ;
V_16 -> V_57 = 1 ;
V_16 -> V_58 = args . V_50 ;
V_17 = F_20 ( V_50 , & V_16 -> V_59 ) ;
if ( V_17 < 0 )
return V_17 ;
snprintf ( V_10 -> V_60 , V_61 , L_7 ,
V_16 -> V_59 ) ;
if ( ! args . V_62 )
V_16 -> V_59 = NULL ;
} else {
struct V_63 * V_23 = F_21 ( V_7 ) ;
const struct V_64 * V_65 ;
V_65 = F_22 ( V_23 ) ;
V_16 -> V_58 = NULL ;
V_16 -> V_59 = L_5 ;
V_16 -> V_66 = L_6 ;
V_16 -> V_67 = 1 ;
V_16 -> V_68 = F_12 ;
V_16 -> V_54 = args . V_50 ;
V_17 = F_20 ( V_50 , & V_16 -> V_55 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_65 ) {
V_7 -> V_69 . V_70 = V_16 -> V_54 ;
V_7 -> V_69 . V_71 = V_65 -> V_72 ;
} else {
F_23 ( & V_7 -> V_73 ,
& V_7 -> V_69 ,
V_16 -> V_54 ,
L_8 ) ;
}
snprintf ( V_10 -> V_60 , V_61 , L_9 ,
V_16 -> V_55 ) ;
}
V_16 -> V_74 = V_16 -> V_58 ;
V_16 -> V_75 = 1 ;
V_16 -> V_76 = 1 ;
V_16 -> V_77 = V_10 -> V_60 ;
V_16 -> V_78 = V_10 -> V_60 ;
V_16 -> V_79 = & V_80 ;
V_16 -> V_81 = F_7 ;
return 0 ;
}
static int F_24 ( struct V_37 * V_50 ,
struct V_6 * V_7 ,
int V_51 , bool V_52 )
{
struct V_15 * V_16 = F_8 ( V_7 , V_51 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_51 ) ;
struct V_12 * V_12 ;
struct V_37 * V_82 = V_52 ? V_16 -> V_58 :
V_16 -> V_54 ;
T_1 V_83 ;
if ( F_25 ( V_50 , L_10 ) ) {
V_12 = F_26 ( V_50 , 0 ) ;
if ( F_27 ( V_12 ) )
return F_28 ( V_12 ) ;
V_10 -> V_21 = F_29 ( V_12 ) ;
V_10 -> V_12 = V_12 ;
} else if ( ! F_30 ( V_50 , L_11 , & V_83 ) ) {
V_10 -> V_21 = V_83 ;
} else {
V_12 = F_26 ( V_82 , 0 ) ;
if ( ! F_27 ( V_12 ) )
V_10 -> V_21 = F_29 ( V_12 ) ;
}
return 0 ;
}
static int F_31 ( struct V_37 * V_38 ,
struct V_37 * V_50 ,
struct V_6 * V_7 ,
int V_51 , bool V_52 )
{
struct V_63 * V_23 = F_21 ( V_7 ) ;
struct V_15 * V_16 = F_8 ( V_7 , V_51 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_51 ) ;
int V_17 ;
V_17 = F_17 ( V_50 , V_7 , V_51 , V_52 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_24 ( V_50 , V_7 , V_51 , V_52 ) ;
if ( V_17 < 0 )
return V_17 ;
F_32 ( V_23 , L_12 ,
V_10 -> V_60 ,
V_16 -> V_84 ,
V_10 -> V_21 ) ;
return V_17 ;
}
static int F_33 ( struct V_37 * V_38 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 ;
struct V_37 * V_50 ;
unsigned int V_43 = 0 ;
int V_17 , V_85 ;
bool V_52 ;
V_85 = 0 ;
F_34 (node, np) {
V_16 = F_8 ( V_7 , V_85 ) ;
if ( strcmp ( V_50 -> V_77 , L_13 ) == 0 ) {
V_17 = F_14 ( V_38 , V_50 , V_7 ,
V_16 , & V_43 ) ;
if ( V_17 < 0 )
return V_17 ;
break;
}
V_85 ++ ;
}
V_85 = 0 ;
F_34 (node, np) {
V_16 = F_8 ( V_7 , V_85 ) ;
V_16 -> V_84 = V_43 ;
V_52 = false ;
if ( strcmp ( V_50 -> V_77 , L_14 ) == 0 )
V_52 = true ;
V_17 = F_31 ( V_38 , V_50 , V_7 , V_85 , V_52 ) ;
if ( V_17 < 0 )
return V_17 ;
V_85 ++ ;
}
return 0 ;
}
static int F_35 ( struct V_37 * V_38 ,
struct V_6 * V_7 ,
struct V_63 * V_23 )
{
const struct V_64 * V_65 = F_22 ( V_23 ) ;
struct V_9 * V_86 ;
struct V_15 * V_87 ;
int V_17 ;
int V_11 ;
if ( ! V_38 )
return - V_45 ;
V_11 = F_36 ( V_38 ) ;
V_86 = F_37 ( V_23 , sizeof( * V_86 ) * V_11 , V_88 ) ;
V_87 = F_37 ( V_23 , sizeof( * V_87 ) * V_11 , V_88 ) ;
if ( ! V_86 || ! V_87 )
return - V_89 ;
V_7 -> V_10 = V_86 ;
V_7 -> V_16 = V_87 ;
V_7 -> V_90 = V_11 ;
V_7 -> V_73 . V_91 = V_92 ;
V_7 -> V_73 . V_23 = V_23 ;
V_7 -> V_73 . V_16 = V_7 -> V_16 ;
V_7 -> V_73 . V_93 = V_11 ;
V_7 -> V_73 . V_69 = & V_7 -> V_69 ;
V_7 -> V_73 . V_94 = 1 ;
if ( V_65 ) {
V_7 -> V_73 . V_95 = V_65 -> V_96 ;
V_7 -> V_73 . V_97 = V_65 -> V_98 ;
} else {
F_38 ( & V_7 -> V_73 ,
L_15 ) ;
}
F_39 ( & V_7 -> V_73 , L_16 ) ;
F_30 ( V_38 , L_17 , & V_7 -> V_34 ) ;
F_32 ( V_23 , L_18 ,
V_7 -> V_73 . V_77 ? V_7 -> V_73 . V_77 : L_19 ,
V_7 -> V_34 ) ;
V_17 = F_33 ( V_38 , V_7 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( ! V_7 -> V_73 . V_77 )
V_7 -> V_73 . V_77 = V_7 -> V_73 . V_16 -> V_77 ;
return 0 ;
}
static int F_40 ( struct V_99 * V_8 )
{
struct V_15 * V_16 ;
int V_93 ;
for ( V_93 = 0 , V_16 = V_8 -> V_16 ;
V_93 < V_8 -> V_93 ;
V_93 ++ , V_16 ++ ) {
F_16 ( V_16 -> V_58 ) ;
F_16 ( V_16 -> V_54 ) ;
}
return 0 ;
}
static int F_41 ( struct V_100 * V_101 )
{
struct V_6 * V_7 ;
struct V_37 * V_50 = V_101 -> V_23 . V_70 ;
struct V_63 * V_23 = & V_101 -> V_23 ;
int V_17 ;
V_7 = F_37 ( V_23 , sizeof( * V_7 ) , V_88 ) ;
if ( ! V_7 )
return - V_89 ;
V_17 = F_35 ( V_50 , V_7 , V_23 ) ;
if ( V_17 < 0 ) {
if ( V_17 != - V_102 )
F_10 ( V_23 , L_20 , V_17 ) ;
goto V_24;
}
F_42 ( & V_7 -> V_73 , V_7 ) ;
V_17 = F_43 ( & V_101 -> V_23 , & V_7 -> V_73 ) ;
if ( V_17 >= 0 )
return V_17 ;
V_24:
F_40 ( & V_7 -> V_73 ) ;
return V_17 ;
}
static int F_44 ( struct V_100 * V_101 )
{
struct V_99 * V_8 = F_45 ( V_101 ) ;
return F_40 ( V_8 ) ;
}
