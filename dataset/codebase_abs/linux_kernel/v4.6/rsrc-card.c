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
struct V_40 * V_42 ,
struct V_6 * V_7 ,
struct V_15 * V_16 ,
unsigned int * V_43 )
{
struct V_40 * V_44 = NULL ;
struct V_40 * V_45 = NULL ;
unsigned int V_46 ;
V_46 = F_15 ( V_41 , NULL ,
& V_44 , & V_45 ) ;
V_46 &= ~ V_47 ;
if ( ! V_44 && ! V_45 )
return - V_48 ;
if ( V_42 == V_44 )
V_46 |= ( V_42 == V_45 ) ?
V_49 : V_50 ;
else
V_46 |= ( V_42 == V_45 ) ?
V_51 : V_52 ;
F_16 ( V_44 ) ;
F_16 ( V_45 ) ;
* V_43 = V_46 ;
return 0 ;
}
static int F_17 ( struct V_40 * V_53 ,
struct V_6 * V_7 ,
int V_54 , bool V_55 )
{
struct V_15 * V_16 = F_8 ( V_7 , V_54 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_54 ) ;
struct V_56 args ;
int V_17 ;
V_17 = F_18 ( V_53 , L_3 ,
L_4 , 0 , & args ) ;
if ( V_17 )
return V_17 ;
V_17 = F_19 ( V_53 ,
& V_10 -> V_26 ,
& V_10 -> V_27 ,
& V_10 -> V_25 ,
& V_10 -> V_28 ) ;
if ( V_17 )
return V_17 ;
if ( V_55 ) {
V_16 -> V_57 = NULL ;
V_16 -> V_58 = L_5 ;
V_16 -> V_59 = L_6 ;
V_16 -> V_18 = 1 ;
V_16 -> V_60 = 1 ;
V_16 -> V_61 = args . V_53 ;
V_17 = F_20 ( V_53 , & V_16 -> V_62 ) ;
if ( V_17 < 0 )
return V_17 ;
snprintf ( V_10 -> V_63 , V_64 , L_7 ,
V_16 -> V_62 ) ;
if ( ! args . V_65 )
V_16 -> V_62 = NULL ;
} else {
struct V_66 * V_23 = F_21 ( V_7 ) ;
const struct V_67 * V_68 ;
V_68 = F_22 ( V_23 ) ;
V_16 -> V_61 = NULL ;
V_16 -> V_62 = L_5 ;
V_16 -> V_69 = L_6 ;
V_16 -> V_70 = 1 ;
V_16 -> V_71 = F_12 ;
V_16 -> V_57 = args . V_53 ;
V_17 = F_20 ( V_53 , & V_16 -> V_58 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_68 ) {
V_7 -> V_72 . V_73 = V_16 -> V_57 ;
V_7 -> V_72 . V_74 = V_68 -> V_75 ;
} else {
F_23 ( & V_7 -> V_76 ,
& V_7 -> V_72 ,
V_16 -> V_57 ,
L_8 ) ;
}
snprintf ( V_10 -> V_63 , V_64 , L_9 ,
V_16 -> V_58 ) ;
}
V_16 -> V_77 = V_16 -> V_61 ;
V_16 -> V_78 = 1 ;
V_16 -> V_79 = 1 ;
V_16 -> V_80 = V_10 -> V_63 ;
V_16 -> V_81 = V_10 -> V_63 ;
V_16 -> V_82 = & V_83 ;
V_16 -> V_84 = F_7 ;
return 0 ;
}
static int F_24 ( struct V_40 * V_53 ,
struct V_6 * V_7 ,
int V_54 , bool V_55 )
{
struct V_15 * V_16 = F_8 ( V_7 , V_54 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_54 ) ;
struct V_12 * V_12 ;
struct V_40 * V_85 = V_55 ? V_16 -> V_61 :
V_16 -> V_57 ;
T_1 V_86 ;
if ( F_25 ( V_53 , L_10 ) ) {
V_12 = F_26 ( V_53 , 0 ) ;
if ( F_27 ( V_12 ) )
return F_28 ( V_12 ) ;
V_10 -> V_21 = F_29 ( V_12 ) ;
V_10 -> V_12 = V_12 ;
} else if ( ! F_30 ( V_53 , L_11 , & V_86 ) ) {
V_10 -> V_21 = V_86 ;
} else {
V_12 = F_26 ( V_85 , 0 ) ;
if ( ! F_27 ( V_12 ) )
V_10 -> V_21 = F_29 ( V_12 ) ;
}
return 0 ;
}
static int F_31 ( struct V_40 * V_41 ,
struct V_40 * V_53 ,
struct V_6 * V_7 ,
int V_54 , bool V_55 )
{
struct V_66 * V_23 = F_21 ( V_7 ) ;
struct V_15 * V_16 = F_8 ( V_7 , V_54 ) ;
struct V_9 * V_10 = F_3 ( V_7 , V_54 ) ;
int V_17 ;
V_17 = F_17 ( V_53 , V_7 , V_54 , V_55 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_24 ( V_53 , V_7 , V_54 , V_55 ) ;
if ( V_17 < 0 )
return V_17 ;
F_32 ( V_23 , L_12 ,
V_10 -> V_63 ,
V_16 -> V_87 ,
V_10 -> V_21 ) ;
return V_17 ;
}
static int F_33 ( struct V_40 * V_41 ,
struct V_6 * V_7 )
{
struct V_15 * V_16 ;
struct V_40 * V_53 ;
unsigned int V_46 = 0 ;
int V_17 , V_88 ;
bool V_55 ;
V_88 = 0 ;
F_34 (node, np) {
V_16 = F_8 ( V_7 , V_88 ) ;
if ( strcmp ( V_53 -> V_80 , L_13 ) == 0 ) {
V_17 = F_14 ( V_41 , V_53 , V_7 ,
V_16 , & V_46 ) ;
if ( V_17 < 0 )
return V_17 ;
break;
}
V_88 ++ ;
}
V_88 = 0 ;
F_34 (node, np) {
V_16 = F_8 ( V_7 , V_88 ) ;
V_16 -> V_87 = V_46 ;
V_55 = false ;
if ( strcmp ( V_53 -> V_80 , L_14 ) == 0 )
V_55 = true ;
V_17 = F_31 ( V_41 , V_53 , V_7 , V_88 , V_55 ) ;
if ( V_17 < 0 )
return V_17 ;
V_88 ++ ;
}
return 0 ;
}
static int F_35 ( struct V_40 * V_41 ,
struct V_6 * V_7 ,
struct V_66 * V_23 )
{
const struct V_67 * V_68 = F_22 ( V_23 ) ;
struct V_9 * V_89 ;
struct V_15 * V_90 ;
int V_17 ;
int V_11 ;
if ( ! V_41 )
return - V_48 ;
V_11 = F_36 ( V_41 ) ;
V_89 = F_37 ( V_23 , sizeof( * V_89 ) * V_11 , V_91 ) ;
V_90 = F_37 ( V_23 , sizeof( * V_90 ) * V_11 , V_91 ) ;
if ( ! V_89 || ! V_90 )
return - V_92 ;
V_7 -> V_10 = V_89 ;
V_7 -> V_16 = V_90 ;
V_7 -> V_93 = V_11 ;
V_7 -> V_76 . V_94 = V_95 ;
V_7 -> V_76 . V_23 = V_23 ;
V_7 -> V_76 . V_16 = V_7 -> V_16 ;
V_7 -> V_76 . V_96 = V_11 ;
V_7 -> V_76 . V_72 = & V_7 -> V_72 ;
V_7 -> V_76 . V_97 = 1 ;
if ( V_68 ) {
V_7 -> V_76 . V_98 = V_68 -> V_99 ;
V_7 -> V_76 . V_100 = V_68 -> V_101 ;
} else {
F_38 ( & V_7 -> V_76 ,
L_15 ) ;
}
F_39 ( & V_7 -> V_76 , L_16 ) ;
F_30 ( V_41 , L_17 , & V_7 -> V_36 ) ;
F_30 ( V_41 , L_18 , & V_7 -> V_39 ) ;
F_32 ( V_23 , L_19 ,
V_7 -> V_76 . V_80 ? V_7 -> V_76 . V_80 : L_20 ) ;
F_32 ( V_23 , L_21 , V_7 -> V_36 ) ;
F_32 ( V_23 , L_22 , V_7 -> V_39 ) ;
V_17 = F_33 ( V_41 , V_7 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( ! V_7 -> V_76 . V_80 )
V_7 -> V_76 . V_80 = V_7 -> V_76 . V_16 -> V_80 ;
return 0 ;
}
static int F_40 ( struct V_102 * V_8 )
{
struct V_15 * V_16 ;
int V_96 ;
for ( V_96 = 0 , V_16 = V_8 -> V_16 ;
V_96 < V_8 -> V_96 ;
V_96 ++ , V_16 ++ ) {
F_16 ( V_16 -> V_61 ) ;
F_16 ( V_16 -> V_57 ) ;
}
return 0 ;
}
static int F_41 ( struct V_103 * V_104 )
{
struct V_6 * V_7 ;
struct V_40 * V_53 = V_104 -> V_23 . V_73 ;
struct V_66 * V_23 = & V_104 -> V_23 ;
int V_17 ;
V_7 = F_37 ( V_23 , sizeof( * V_7 ) , V_91 ) ;
if ( ! V_7 )
return - V_92 ;
V_17 = F_35 ( V_53 , V_7 , V_23 ) ;
if ( V_17 < 0 ) {
if ( V_17 != - V_105 )
F_10 ( V_23 , L_23 , V_17 ) ;
goto V_24;
}
F_42 ( & V_7 -> V_76 , V_7 ) ;
V_17 = F_43 ( & V_104 -> V_23 , & V_7 -> V_76 ) ;
if ( V_17 >= 0 )
return V_17 ;
V_24:
F_40 ( & V_7 -> V_76 ) ;
return V_17 ;
}
static int F_44 ( struct V_103 * V_104 )
{
struct V_102 * V_8 = F_45 ( V_104 ) ;
return F_40 ( V_8 ) ;
}
