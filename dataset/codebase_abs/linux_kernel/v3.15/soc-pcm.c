void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_6 = V_2 -> V_6 ;
F_2 ( & V_2 -> V_7 ) ;
if ( V_3 == V_8 ) {
V_5 -> V_9 ++ ;
V_6 -> V_9 ++ ;
} else {
V_5 -> V_10 ++ ;
V_6 -> V_10 ++ ;
}
V_5 -> V_11 ++ ;
V_6 -> V_11 ++ ;
V_5 -> V_12 -> V_11 ++ ;
V_6 -> V_12 -> V_11 ++ ;
}
void F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_6 = V_2 -> V_6 ;
F_2 ( & V_2 -> V_7 ) ;
if ( V_3 == V_8 ) {
V_5 -> V_9 -- ;
V_6 -> V_9 -- ;
} else {
V_5 -> V_10 -- ;
V_6 -> V_10 -- ;
}
V_5 -> V_11 -- ;
V_6 -> V_11 -- ;
V_5 -> V_12 -> V_11 -- ;
V_6 -> V_12 -> V_11 -- ;
}
bool F_4 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_13 || V_2 -> V_14 -> V_15 )
return true ;
return V_2 -> V_5 -> V_12 -> V_15 &&
V_2 -> V_6 -> V_12 -> V_15 ;
}
int F_5 ( struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
struct V_20 * V_21 = V_17 -> V_21 ;
V_21 -> V_19 . V_22 = V_19 -> V_22 ;
V_21 -> V_19 . V_23 = V_19 -> V_23 ;
V_21 -> V_19 . V_24 = V_19 -> V_24 ;
V_21 -> V_19 . V_25 = V_19 -> V_25 ;
V_21 -> V_19 . V_26 = V_19 -> V_26 ;
V_21 -> V_19 . V_27 = V_19 -> V_27 ;
V_21 -> V_19 . V_28 = V_19 -> V_28 ;
V_21 -> V_19 . V_29 = V_19 -> V_29 ;
return 0 ;
}
int F_6 ( struct V_1 * V_30 , int V_31 ,
int V_32 )
{
struct V_33 * V_34 ;
F_7 (dpcm, &fe->dpcm[dir].be_clients, list_be) {
struct V_1 * V_35 = V_34 -> V_35 ;
F_8 ( V_35 -> V_36 , L_1 ,
V_35 -> V_14 -> V_37 , V_32 , V_31 ) ;
F_9 ( V_35 , V_31 , V_32 ) ;
}
F_9 ( V_30 , V_31 , V_32 ) ;
return 0 ;
}
static int F_10 ( struct V_16 * V_17 ,
struct V_4 * V_38 )
{
struct V_1 * V_2 = V_17 -> V_39 ;
int V_40 ;
if ( V_38 -> V_41 && ( V_38 -> V_42 -> V_43 ||
V_2 -> V_14 -> V_43 ) ) {
F_8 ( V_38 -> V_36 , L_2 ,
V_38 -> V_41 ) ;
V_40 = F_11 ( V_17 -> V_21 ,
V_44 ,
V_38 -> V_41 , V_38 -> V_41 ) ;
if ( V_40 < 0 ) {
F_12 ( V_38 -> V_36 ,
L_3 ,
V_40 ) ;
return V_40 ;
}
}
if ( V_38 -> V_45 && ( V_38 -> V_42 -> V_46 ||
V_2 -> V_14 -> V_46 ) ) {
F_8 ( V_38 -> V_36 , L_4 ,
V_38 -> V_45 ) ;
V_40 = F_11 ( V_17 -> V_21 ,
V_47 ,
V_38 -> V_45 ,
V_38 -> V_45 ) ;
if ( V_40 < 0 ) {
F_12 ( V_38 -> V_36 ,
L_5 ,
V_40 ) ;
return V_40 ;
}
}
if ( V_38 -> V_48 && ( V_38 -> V_42 -> V_49 ||
V_2 -> V_14 -> V_49 ) ) {
F_8 ( V_38 -> V_36 , L_6 ,
V_38 -> V_48 ) ;
V_40 = F_11 ( V_17 -> V_21 ,
V_50 ,
V_38 -> V_48 ,
V_38 -> V_48 ) ;
if ( V_40 < 0 ) {
F_12 ( V_38 -> V_36 ,
L_7 ,
V_40 ) ;
return V_40 ;
}
}
return 0 ;
}
static int F_13 ( struct V_16 * V_17 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = V_17 -> V_39 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_6 = V_2 -> V_6 ;
unsigned int V_41 , V_45 , V_48 , V_53 ;
V_41 = F_14 ( V_52 ) ;
V_45 = F_15 ( V_52 ) ;
V_48 = F_16 ( F_17 ( V_52 ) ) ;
V_53 = V_5 -> V_42 -> V_43 ||
V_6 -> V_42 -> V_43 ||
V_2 -> V_14 -> V_43 ;
if ( V_53 && V_5 -> V_41 && V_5 -> V_41 != V_41 ) {
F_12 ( V_2 -> V_36 , L_8 ,
V_5 -> V_41 , V_41 ) ;
return - V_54 ;
}
V_53 = V_5 -> V_42 -> V_46 ||
V_6 -> V_42 -> V_46 ||
V_2 -> V_14 -> V_46 ;
if ( V_53 && V_5 -> V_45 && V_5 -> V_45 != V_45 ) {
F_12 ( V_2 -> V_36 , L_9 ,
V_5 -> V_45 , V_45 ) ;
return - V_54 ;
}
V_53 = V_5 -> V_42 -> V_49 ||
V_6 -> V_42 -> V_49 ||
V_2 -> V_14 -> V_49 ;
if ( V_53 && V_5 -> V_48 && V_5 -> V_48 != V_48 ) {
F_12 ( V_2 -> V_36 , L_10 ,
V_5 -> V_48 , V_48 ) ;
return - V_54 ;
}
return 0 ;
}
static bool F_18 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_39 ;
struct V_55 * V_56 = V_2 -> V_5 -> V_42 ;
struct V_55 * V_57 = V_2 -> V_6 -> V_42 ;
struct V_58 * V_59 = V_2 -> V_14 ;
return V_56 -> V_43 || V_57 -> V_43 ||
V_59 -> V_43 || V_56 -> V_46 ||
V_57 -> V_46 || V_59 -> V_46 ||
V_56 -> V_49 ||
V_57 -> V_49 ||
V_59 -> V_49 ;
}
static void F_19 ( struct V_16 * V_17 ,
struct V_4 * V_60 )
{
int V_40 , V_61 , V_62 ;
if ( V_17 -> V_3 == V_8 )
V_62 = V_60 -> V_42 -> V_63 . V_64 ;
else
V_62 = V_60 -> V_42 -> V_65 . V_64 ;
if ( ! V_62 )
return;
for ( V_61 = 0 ; V_61 < F_20 ( V_66 ) ; V_61 ++ ) {
if ( V_62 >= V_66 [ V_61 ] )
continue;
V_40 = F_21 ( V_17 -> V_21 , 0 ,
V_66 [ V_61 ] , V_62 ) ;
if ( V_40 != 0 )
F_22 ( V_60 -> V_36 ,
L_11 ,
V_62 , V_66 [ V_61 ] , V_40 ) ;
}
}
static void F_23 ( struct V_20 * V_21 ,
struct V_67 * V_68 ,
struct V_67 * V_69 )
{
struct V_18 * V_19 = & V_21 -> V_19 ;
V_19 -> V_70 = F_24 ( V_68 -> V_70 ,
V_69 -> V_70 ) ;
V_19 -> V_71 = F_25 ( V_68 -> V_71 ,
V_69 -> V_71 ) ;
if ( V_19 -> V_23 )
V_19 -> V_23 &= V_68 -> V_23 & V_69 -> V_23 ;
else
V_19 -> V_23 = V_68 -> V_23 & V_69 -> V_23 ;
V_19 -> V_72 = F_26 ( V_68 -> V_72 ,
V_69 -> V_72 ) ;
V_19 -> V_73 = 0 ;
V_19 -> V_74 = V_75 ;
F_27 ( V_21 ) ;
V_19 -> V_73 = F_24 ( V_19 -> V_73 , V_69 -> V_73 ) ;
V_19 -> V_73 = F_24 ( V_19 -> V_73 , V_68 -> V_73 ) ;
V_19 -> V_74 = F_28 ( V_19 -> V_74 , V_69 -> V_74 ) ;
V_19 -> V_74 = F_28 ( V_19 -> V_74 , V_68 -> V_74 ) ;
}
static int F_29 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_39 ;
struct V_20 * V_21 = V_17 -> V_21 ;
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_6 = V_2 -> V_6 ;
struct V_55 * V_78 = V_5 -> V_42 ;
struct V_55 * V_79 = V_6 -> V_42 ;
int V_40 = 0 ;
F_30 ( V_5 -> V_36 ) ;
F_30 ( V_6 -> V_36 ) ;
F_31 ( V_5 -> V_36 ) ;
F_31 ( V_6 -> V_36 ) ;
F_31 ( V_77 -> V_36 ) ;
F_32 ( & V_2 -> V_7 , V_2 -> V_80 ) ;
if ( V_5 -> V_42 -> V_81 && V_5 -> V_42 -> V_81 -> V_82 ) {
V_40 = V_5 -> V_42 -> V_81 -> V_82 ( V_17 , V_5 ) ;
if ( V_40 < 0 ) {
F_12 ( V_5 -> V_36 , L_12
L_13 , V_5 -> V_37 , V_40 ) ;
goto V_83;
}
}
if ( V_77 -> V_42 -> V_81 && V_77 -> V_42 -> V_81 -> V_84 ) {
V_40 = V_77 -> V_42 -> V_81 -> V_84 ( V_17 ) ;
if ( V_40 < 0 ) {
F_12 ( V_77 -> V_36 , L_14
L_13 , V_77 -> V_37 , V_40 ) ;
goto V_85;
}
}
if ( V_6 -> V_42 -> V_81 && V_6 -> V_42 -> V_81 -> V_82 ) {
V_40 = V_6 -> V_42 -> V_81 -> V_82 ( V_17 , V_6 ) ;
if ( V_40 < 0 ) {
F_12 ( V_6 -> V_36 , L_15
L_13 , V_6 -> V_37 , V_40 ) ;
goto V_86;
}
}
if ( V_2 -> V_14 -> V_81 && V_2 -> V_14 -> V_81 -> V_82 ) {
V_40 = V_2 -> V_14 -> V_81 -> V_82 ( V_17 ) ;
if ( V_40 < 0 ) {
F_33 ( L_16 ,
V_2 -> V_14 -> V_37 , V_40 ) ;
goto V_87;
}
}
if ( V_2 -> V_14 -> V_88 || V_2 -> V_14 -> V_89 )
goto V_88;
if ( V_17 -> V_3 == V_8 ) {
F_23 ( V_21 , & V_79 -> V_63 ,
& V_78 -> V_63 ) ;
} else {
F_23 ( V_21 , & V_79 -> V_65 ,
& V_78 -> V_65 ) ;
}
if ( F_18 ( V_17 ) )
V_21 -> V_19 . V_22 |= V_90 ;
V_40 = - V_54 ;
if ( ! V_21 -> V_19 . V_72 ) {
F_34 ( V_91 L_17 ,
V_6 -> V_37 , V_5 -> V_37 ) ;
goto V_92;
}
if ( ! V_21 -> V_19 . V_23 ) {
F_34 ( V_91 L_18 ,
V_6 -> V_37 , V_5 -> V_37 ) ;
goto V_92;
}
if ( ! V_21 -> V_19 . V_70 || ! V_21 -> V_19 . V_71 ||
V_21 -> V_19 . V_70 > V_21 -> V_19 . V_71 ) {
F_34 ( V_91 L_19 ,
V_6 -> V_37 , V_5 -> V_37 ) ;
goto V_92;
}
F_19 ( V_17 , V_6 ) ;
F_19 ( V_17 , V_5 ) ;
if ( V_5 -> V_11 ) {
V_40 = F_10 ( V_17 , V_5 ) ;
if ( V_40 != 0 )
goto V_92;
}
if ( V_6 -> V_11 ) {
V_40 = F_10 ( V_17 , V_6 ) ;
if ( V_40 != 0 )
goto V_92;
}
F_35 ( L_20 ,
V_6 -> V_37 , V_5 -> V_37 ) ;
F_35 ( L_21 , V_21 -> V_19 . V_72 ) ;
F_35 ( L_22 , V_21 -> V_19 . V_70 ,
V_21 -> V_19 . V_71 ) ;
F_35 ( L_23 , V_21 -> V_19 . V_73 ,
V_21 -> V_19 . V_74 ) ;
V_88:
F_1 ( V_2 , V_17 -> V_3 ) ;
F_36 ( & V_2 -> V_7 ) ;
return 0 ;
V_92:
if ( V_2 -> V_14 -> V_81 && V_2 -> V_14 -> V_81 -> V_93 )
V_2 -> V_14 -> V_81 -> V_93 ( V_17 ) ;
V_87:
if ( V_6 -> V_42 -> V_81 -> V_93 )
V_6 -> V_42 -> V_81 -> V_93 ( V_17 , V_6 ) ;
V_86:
if ( V_77 -> V_42 -> V_81 && V_77 -> V_42 -> V_81 -> V_94 )
V_77 -> V_42 -> V_81 -> V_94 ( V_17 ) ;
V_85:
if ( V_5 -> V_42 -> V_81 -> V_93 )
V_5 -> V_42 -> V_81 -> V_93 ( V_17 , V_5 ) ;
V_83:
F_36 ( & V_2 -> V_7 ) ;
F_37 ( V_77 -> V_36 ) ;
F_37 ( V_6 -> V_36 ) ;
F_37 ( V_5 -> V_36 ) ;
if ( ! V_6 -> V_11 )
F_38 ( V_6 -> V_36 ) ;
if ( ! V_5 -> V_11 )
F_38 ( V_5 -> V_36 ) ;
return V_40 ;
}
static void F_39 ( struct V_95 * V_96 )
{
struct V_1 * V_2 =
F_40 ( V_96 , struct V_1 , V_97 . V_96 ) ;
struct V_4 * V_6 = V_2 -> V_6 ;
F_32 ( & V_2 -> V_7 , V_2 -> V_80 ) ;
F_8 ( V_2 -> V_36 , L_24 ,
V_6 -> V_42 -> V_63 . V_98 ,
V_6 -> V_9 ? L_25 : L_26 ,
V_2 -> V_99 ? L_27 : L_28 ) ;
if ( V_2 -> V_99 == 1 ) {
V_2 -> V_99 = 0 ;
F_9 ( V_2 , V_8 ,
V_100 ) ;
}
F_36 ( & V_2 -> V_7 ) ;
}
static int F_41 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_39 ;
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_6 = V_2 -> V_6 ;
F_32 ( & V_2 -> V_7 , V_2 -> V_80 ) ;
F_3 ( V_2 , V_17 -> V_3 ) ;
if ( ! V_5 -> V_11 )
V_5 -> V_41 = 0 ;
if ( ! V_6 -> V_11 )
V_6 -> V_41 = 0 ;
if ( V_5 -> V_42 -> V_81 -> V_93 )
V_5 -> V_42 -> V_81 -> V_93 ( V_17 , V_5 ) ;
if ( V_6 -> V_42 -> V_81 -> V_93 )
V_6 -> V_42 -> V_81 -> V_93 ( V_17 , V_6 ) ;
if ( V_2 -> V_14 -> V_81 && V_2 -> V_14 -> V_81 -> V_93 )
V_2 -> V_14 -> V_81 -> V_93 ( V_17 ) ;
if ( V_77 -> V_42 -> V_81 && V_77 -> V_42 -> V_81 -> V_94 )
V_77 -> V_42 -> V_81 -> V_94 ( V_17 ) ;
V_5 -> V_21 = NULL ;
if ( V_17 -> V_3 == V_8 ) {
if ( F_4 ( V_2 ) ) {
F_9 ( V_2 ,
V_8 ,
V_100 ) ;
} else {
V_2 -> V_99 = 1 ;
F_42 ( V_101 ,
& V_2 -> V_97 ,
F_43 ( V_2 -> V_13 ) ) ;
}
} else {
F_9 ( V_2 , V_102 ,
V_100 ) ;
}
F_36 ( & V_2 -> V_7 ) ;
F_37 ( V_77 -> V_36 ) ;
F_37 ( V_6 -> V_36 ) ;
F_37 ( V_5 -> V_36 ) ;
if ( ! V_6 -> V_11 )
F_38 ( V_6 -> V_36 ) ;
if ( ! V_5 -> V_11 )
F_38 ( V_5 -> V_36 ) ;
return 0 ;
}
static int F_44 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_39 ;
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_6 = V_2 -> V_6 ;
int V_40 = 0 ;
F_32 ( & V_2 -> V_7 , V_2 -> V_80 ) ;
if ( V_2 -> V_14 -> V_81 && V_2 -> V_14 -> V_81 -> V_103 ) {
V_40 = V_2 -> V_14 -> V_81 -> V_103 ( V_17 ) ;
if ( V_40 < 0 ) {
F_12 ( V_2 -> V_104 -> V_36 , L_29
L_30 , V_40 ) ;
goto V_83;
}
}
if ( V_77 -> V_42 -> V_81 && V_77 -> V_42 -> V_81 -> V_103 ) {
V_40 = V_77 -> V_42 -> V_81 -> V_103 ( V_17 ) ;
if ( V_40 < 0 ) {
F_12 ( V_77 -> V_36 , L_31
L_30 , V_40 ) ;
goto V_83;
}
}
if ( V_6 -> V_42 -> V_81 && V_6 -> V_42 -> V_81 -> V_103 ) {
V_40 = V_6 -> V_42 -> V_81 -> V_103 ( V_17 , V_6 ) ;
if ( V_40 < 0 ) {
F_12 ( V_6 -> V_36 , L_32 ,
V_40 ) ;
goto V_83;
}
}
if ( V_5 -> V_42 -> V_81 && V_5 -> V_42 -> V_81 -> V_103 ) {
V_40 = V_5 -> V_42 -> V_81 -> V_103 ( V_17 , V_5 ) ;
if ( V_40 < 0 ) {
F_12 ( V_5 -> V_36 , L_32 ,
V_40 ) ;
goto V_83;
}
}
if ( V_17 -> V_3 == V_8 &&
V_2 -> V_99 ) {
V_2 -> V_99 = 0 ;
F_45 ( & V_2 -> V_97 ) ;
}
F_9 ( V_2 , V_17 -> V_3 ,
V_105 ) ;
F_46 ( V_6 , 0 , V_17 -> V_3 ) ;
V_83:
F_36 ( & V_2 -> V_7 ) ;
return V_40 ;
}
static int F_47 ( struct V_16 * V_17 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = V_17 -> V_39 ;
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_6 = V_2 -> V_6 ;
int V_40 = 0 ;
F_32 ( & V_2 -> V_7 , V_2 -> V_80 ) ;
V_40 = F_13 ( V_17 , V_52 ) ;
if ( V_40 )
goto V_83;
if ( V_2 -> V_14 -> V_81 && V_2 -> V_14 -> V_81 -> V_106 ) {
V_40 = V_2 -> V_14 -> V_81 -> V_106 ( V_17 , V_52 ) ;
if ( V_40 < 0 ) {
F_12 ( V_2 -> V_104 -> V_36 , L_33
L_34 , V_40 ) ;
goto V_83;
}
}
if ( V_6 -> V_42 -> V_81 && V_6 -> V_42 -> V_81 -> V_106 ) {
V_40 = V_6 -> V_42 -> V_81 -> V_106 ( V_17 , V_52 , V_6 ) ;
if ( V_40 < 0 ) {
F_12 ( V_6 -> V_36 , L_35
L_30 , V_6 -> V_37 , V_40 ) ;
goto V_107;
}
}
if ( V_5 -> V_42 -> V_81 && V_5 -> V_42 -> V_81 -> V_106 ) {
V_40 = V_5 -> V_42 -> V_81 -> V_106 ( V_17 , V_52 , V_5 ) ;
if ( V_40 < 0 ) {
F_12 ( V_5 -> V_36 , L_36 ,
V_5 -> V_37 , V_40 ) ;
goto V_108;
}
}
if ( V_77 -> V_42 -> V_81 && V_77 -> V_42 -> V_81 -> V_106 ) {
V_40 = V_77 -> V_42 -> V_81 -> V_106 ( V_17 , V_52 ) ;
if ( V_40 < 0 ) {
F_12 ( V_77 -> V_36 , L_36 ,
V_77 -> V_37 , V_40 ) ;
goto V_85;
}
}
V_5 -> V_41 = F_14 ( V_52 ) ;
V_5 -> V_45 = F_15 ( V_52 ) ;
V_5 -> V_48 =
F_16 ( F_17 ( V_52 ) ) ;
V_6 -> V_41 = F_14 ( V_52 ) ;
V_6 -> V_45 = F_15 ( V_52 ) ;
V_6 -> V_48 =
F_16 ( F_17 ( V_52 ) ) ;
V_83:
F_36 ( & V_2 -> V_7 ) ;
return V_40 ;
V_85:
if ( V_5 -> V_42 -> V_81 && V_5 -> V_42 -> V_81 -> V_109 )
V_5 -> V_42 -> V_81 -> V_109 ( V_17 , V_5 ) ;
V_108:
if ( V_6 -> V_42 -> V_81 && V_6 -> V_42 -> V_81 -> V_109 )
V_6 -> V_42 -> V_81 -> V_109 ( V_17 , V_6 ) ;
V_107:
if ( V_2 -> V_14 -> V_81 && V_2 -> V_14 -> V_81 -> V_109 )
V_2 -> V_14 -> V_81 -> V_109 ( V_17 ) ;
F_36 ( & V_2 -> V_7 ) ;
return V_40 ;
}
static int F_48 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_39 ;
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_6 = V_2 -> V_6 ;
bool V_63 = V_17 -> V_3 == V_8 ;
F_32 ( & V_2 -> V_7 , V_2 -> V_80 ) ;
if ( V_5 -> V_11 == 1 ) {
V_5 -> V_41 = 0 ;
V_5 -> V_45 = 0 ;
V_5 -> V_48 = 0 ;
}
if ( V_6 -> V_11 == 1 ) {
V_6 -> V_41 = 0 ;
V_6 -> V_45 = 0 ;
V_6 -> V_48 = 0 ;
}
if ( ( V_63 && V_6 -> V_9 == 1 ) ||
( ! V_63 && V_6 -> V_10 == 1 ) )
F_46 ( V_6 , 1 , V_17 -> V_3 ) ;
if ( V_2 -> V_14 -> V_81 && V_2 -> V_14 -> V_81 -> V_109 )
V_2 -> V_14 -> V_81 -> V_109 ( V_17 ) ;
if ( V_77 -> V_42 -> V_81 && V_77 -> V_42 -> V_81 -> V_109 )
V_77 -> V_42 -> V_81 -> V_109 ( V_17 ) ;
if ( V_6 -> V_42 -> V_81 && V_6 -> V_42 -> V_81 -> V_109 )
V_6 -> V_42 -> V_81 -> V_109 ( V_17 , V_6 ) ;
if ( V_5 -> V_42 -> V_81 && V_5 -> V_42 -> V_81 -> V_109 )
V_5 -> V_42 -> V_81 -> V_109 ( V_17 , V_5 ) ;
F_36 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_49 ( struct V_16 * V_17 , int V_110 )
{
struct V_1 * V_2 = V_17 -> V_39 ;
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_6 = V_2 -> V_6 ;
int V_40 ;
if ( V_6 -> V_42 -> V_81 && V_6 -> V_42 -> V_81 -> V_111 ) {
V_40 = V_6 -> V_42 -> V_81 -> V_111 ( V_17 , V_110 , V_6 ) ;
if ( V_40 < 0 )
return V_40 ;
}
if ( V_77 -> V_42 -> V_81 && V_77 -> V_42 -> V_81 -> V_111 ) {
V_40 = V_77 -> V_42 -> V_81 -> V_111 ( V_17 , V_110 ) ;
if ( V_40 < 0 )
return V_40 ;
}
if ( V_5 -> V_42 -> V_81 && V_5 -> V_42 -> V_81 -> V_111 ) {
V_40 = V_5 -> V_42 -> V_81 -> V_111 ( V_17 , V_110 , V_5 ) ;
if ( V_40 < 0 )
return V_40 ;
}
return 0 ;
}
static int F_50 ( struct V_16 * V_17 ,
int V_110 )
{
struct V_1 * V_2 = V_17 -> V_39 ;
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_6 = V_2 -> V_6 ;
int V_40 ;
if ( V_6 -> V_42 -> V_81 &&
V_6 -> V_42 -> V_81 -> V_112 ) {
V_40 = V_6 -> V_42 -> V_81 -> V_112 ( V_17 , V_110 , V_6 ) ;
if ( V_40 < 0 )
return V_40 ;
}
if ( V_77 -> V_42 -> V_112 ) {
V_40 = V_77 -> V_42 -> V_112 ( V_17 , V_110 ) ;
if ( V_40 < 0 )
return V_40 ;
}
if ( V_5 -> V_42 -> V_81 && V_5 -> V_42 -> V_81 -> V_112 ) {
V_40 = V_5 -> V_42 -> V_81 -> V_112 ( V_17 , V_110 , V_5 ) ;
if ( V_40 < 0 )
return V_40 ;
}
return 0 ;
}
static T_1 F_51 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_39 ;
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_6 = V_2 -> V_6 ;
struct V_20 * V_21 = V_17 -> V_21 ;
T_1 V_113 = 0 ;
T_2 V_114 = 0 ;
if ( V_77 -> V_42 -> V_81 && V_77 -> V_42 -> V_81 -> V_115 )
V_113 = V_77 -> V_42 -> V_81 -> V_115 ( V_17 ) ;
if ( V_5 -> V_42 -> V_81 && V_5 -> V_42 -> V_81 -> V_114 )
V_114 += V_5 -> V_42 -> V_81 -> V_114 ( V_17 , V_5 ) ;
if ( V_6 -> V_42 -> V_81 && V_6 -> V_42 -> V_81 -> V_114 )
V_114 += V_6 -> V_42 -> V_81 -> V_114 ( V_17 , V_6 ) ;
if ( V_77 -> V_42 -> V_114 )
V_114 += V_77 -> V_42 -> V_114 ( V_17 , V_6 ) ;
V_21 -> V_114 = V_114 ;
return V_113 ;
}
static int F_52 ( struct V_1 * V_30 ,
struct V_1 * V_35 , int V_3 )
{
struct V_33 * V_34 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
if ( V_34 -> V_35 == V_35 && V_34 -> V_30 == V_30 )
return 0 ;
}
V_34 = F_53 ( sizeof( struct V_33 ) , V_116 ) ;
if ( ! V_34 )
return - V_117 ;
V_34 -> V_35 = V_35 ;
V_34 -> V_30 = V_30 ;
V_35 -> V_34 [ V_3 ] . V_21 = V_30 -> V_34 [ V_3 ] . V_21 ;
V_34 -> V_118 = V_119 ;
F_54 ( & V_34 -> V_120 , & V_30 -> V_34 [ V_3 ] . V_121 ) ;
F_54 ( & V_34 -> V_122 , & V_35 -> V_34 [ V_3 ] . V_123 ) ;
F_8 ( V_30 -> V_36 , L_37 ,
V_3 ? L_38 : L_39 , V_30 -> V_14 -> V_37 ,
V_3 ? L_40 : L_41 , V_35 -> V_14 -> V_37 ) ;
#ifdef F_55
V_34 -> V_124 = F_56 ( V_35 -> V_14 -> V_37 , 0644 ,
V_30 -> V_125 , & V_34 -> V_118 ) ;
#endif
return 1 ;
}
static void F_57 ( struct V_1 * V_30 ,
struct V_1 * V_35 , int V_3 )
{
struct V_33 * V_34 ;
struct V_16 * V_126 , * V_127 ;
if ( ! V_35 -> V_34 [ V_3 ] . V_128 )
return;
V_127 = F_58 ( V_35 , V_3 ) ;
F_7 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_34 -> V_30 == V_30 )
continue;
F_8 ( V_30 -> V_36 , L_42 ,
V_3 ? L_38 : L_39 ,
V_34 -> V_30 -> V_14 -> V_37 ,
V_3 ? L_40 : L_41 , V_34 -> V_35 -> V_14 -> V_37 ) ;
V_126 = F_58 ( V_34 -> V_30 , V_3 ) ;
V_127 -> V_21 = V_126 -> V_21 ;
break;
}
}
void F_59 ( struct V_1 * V_30 , int V_3 )
{
struct V_33 * V_34 , * V_129 ;
F_60 (dpcm, d, &fe->dpcm[stream].be_clients, list_be) {
F_8 ( V_30 -> V_36 , L_43 ,
V_3 ? L_38 : L_39 ,
V_34 -> V_35 -> V_14 -> V_37 ) ;
if ( V_34 -> V_118 != V_130 )
continue;
F_8 ( V_30 -> V_36 , L_44 ,
V_3 ? L_38 : L_39 , V_30 -> V_14 -> V_37 ,
V_3 ? L_40 : L_41 , V_34 -> V_35 -> V_14 -> V_37 ) ;
F_57 ( V_30 , V_34 -> V_35 , V_3 ) ;
#ifdef F_55
F_61 ( V_34 -> V_124 ) ;
#endif
F_62 ( & V_34 -> V_120 ) ;
F_62 ( & V_34 -> V_122 ) ;
F_63 ( V_34 ) ;
}
}
static struct V_1 * F_64 ( struct V_131 * V_104 ,
struct V_132 * V_133 , int V_3 )
{
struct V_1 * V_35 ;
int V_61 ;
if ( V_3 == V_8 ) {
for ( V_61 = 0 ; V_61 < V_104 -> V_134 ; V_61 ++ ) {
V_35 = & V_104 -> V_2 [ V_61 ] ;
if ( ! V_35 -> V_14 -> V_89 )
continue;
if ( V_35 -> V_5 -> V_135 == V_133 ||
V_35 -> V_6 -> V_135 == V_133 )
return V_35 ;
}
} else {
for ( V_61 = 0 ; V_61 < V_104 -> V_134 ; V_61 ++ ) {
V_35 = & V_104 -> V_2 [ V_61 ] ;
if ( ! V_35 -> V_14 -> V_89 )
continue;
if ( V_35 -> V_5 -> V_136 == V_133 ||
V_35 -> V_6 -> V_136 == V_133 )
return V_35 ;
}
}
F_12 ( V_104 -> V_36 , L_45 ,
V_3 ? L_38 : L_39 , V_133 -> V_37 ) ;
return NULL ;
}
static inline struct V_132 *
F_65 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == V_8 )
return V_2 -> V_5 -> V_135 ;
else
return V_2 -> V_5 -> V_136 ;
}
static inline struct V_132 *
F_66 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == V_8 )
return V_2 -> V_6 -> V_135 ;
else
return V_2 -> V_6 -> V_136 ;
}
static int F_67 ( struct V_137 * V_138 ,
struct V_132 * V_133 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_138 -> V_139 ; V_61 ++ ) {
if ( V_133 == V_138 -> V_140 [ V_61 ] )
return 1 ;
}
return 0 ;
}
int F_68 ( struct V_1 * V_30 ,
int V_3 , struct V_137 * * V_141 )
{
struct V_4 * V_5 = V_30 -> V_5 ;
struct V_137 * V_138 ;
int V_142 ;
V_138 = F_53 ( sizeof( struct V_137 ) +
sizeof( struct V_132 * ) , V_116 ) ;
if ( V_138 == NULL )
return - V_117 ;
V_142 = F_69 ( V_5 , V_3 , & V_138 ) ;
F_8 ( V_30 -> V_36 , L_46 , V_142 ,
V_3 ? L_38 : L_39 ) ;
* V_141 = V_138 ;
return V_142 ;
}
static int F_70 ( struct V_1 * V_30 , int V_3 ,
struct V_137 * * V_141 )
{
struct V_33 * V_34 ;
struct V_137 * V_138 = * V_141 ;
struct V_132 * V_133 ;
int V_143 = 0 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
V_133 = F_65 ( V_34 -> V_35 , V_3 ) ;
if ( V_133 && F_67 ( V_138 , V_133 ) )
continue;
V_133 = F_66 ( V_34 -> V_35 , V_3 ) ;
if ( V_133 && F_67 ( V_138 , V_133 ) )
continue;
F_8 ( V_30 -> V_36 , L_47 ,
V_3 ? L_38 : L_39 ,
V_34 -> V_35 -> V_14 -> V_37 , V_30 -> V_14 -> V_37 ) ;
V_34 -> V_118 = V_130 ;
V_34 -> V_35 -> V_34 [ V_3 ] . V_144 = V_145 ;
V_143 ++ ;
}
F_8 ( V_30 -> V_36 , L_48 , V_143 ) ;
return V_143 ;
}
static int F_71 ( struct V_1 * V_30 , int V_3 ,
struct V_137 * * V_141 )
{
struct V_131 * V_104 = V_30 -> V_104 ;
struct V_137 * V_138 = * V_141 ;
struct V_1 * V_35 ;
int V_61 , V_146 = 0 , V_147 ;
for ( V_61 = 0 ; V_61 < V_138 -> V_139 ; V_61 ++ ) {
switch ( V_138 -> V_140 [ V_61 ] -> V_148 ) {
case V_149 :
case V_150 :
break;
default:
continue;
}
V_35 = F_64 ( V_104 , V_138 -> V_140 [ V_61 ] , V_3 ) ;
if ( ! V_35 ) {
F_12 ( V_30 -> V_36 , L_49 ,
V_138 -> V_140 [ V_61 ] -> V_37 ) ;
continue;
}
if ( ! V_35 -> V_14 -> V_89 )
continue;
if ( ! V_30 -> V_34 [ V_3 ] . V_21 && ! V_30 -> V_151 )
continue;
V_147 = F_52 ( V_30 , V_35 , V_3 ) ;
if ( V_147 < 0 ) {
F_12 ( V_30 -> V_36 , L_50 ,
V_138 -> V_140 [ V_61 ] -> V_37 ) ;
break;
} else if ( V_147 == 0 )
continue;
V_35 -> V_34 [ V_3 ] . V_144 = V_145 ;
V_146 ++ ;
}
F_8 ( V_30 -> V_36 , L_51 , V_146 ) ;
return V_146 ;
}
int F_72 ( struct V_1 * V_30 ,
int V_3 , struct V_137 * * V_138 , int V_146 )
{
if ( V_146 )
return F_71 ( V_30 , V_3 , V_138 ) ;
else
return F_70 ( V_30 , V_3 , V_138 ) ;
}
void F_73 ( struct V_1 * V_30 , int V_3 )
{
struct V_33 * V_34 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_34 -> V_35 -> V_34 [ V_3 ] . V_144 =
V_152 ;
}
static void F_74 ( struct V_1 * V_30 ,
int V_3 )
{
struct V_33 * V_34 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_35 = V_34 -> V_35 ;
struct V_16 * V_127 =
F_58 ( V_35 , V_3 ) ;
if ( V_35 -> V_34 [ V_3 ] . V_128 == 0 )
F_12 ( V_35 -> V_36 , L_52 ,
V_3 ? L_38 : L_39 ,
V_35 -> V_34 [ V_3 ] . V_118 ) ;
if ( -- V_35 -> V_34 [ V_3 ] . V_128 != 0 )
continue;
if ( V_35 -> V_34 [ V_3 ] . V_118 != V_153 )
continue;
F_41 ( V_127 ) ;
V_127 -> V_21 = NULL ;
V_35 -> V_34 [ V_3 ] . V_118 = V_154 ;
}
}
int F_75 ( struct V_1 * V_30 , int V_3 )
{
struct V_33 * V_34 ;
int V_147 , V_155 = 0 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_35 = V_34 -> V_35 ;
struct V_16 * V_127 =
F_58 ( V_35 , V_3 ) ;
if ( ! V_127 ) {
F_12 ( V_35 -> V_36 , L_53 ,
V_3 ? L_38 : L_39 ) ;
continue;
}
if ( ! F_76 ( V_30 , V_35 , V_3 ) )
continue;
if ( V_35 -> V_34 [ V_3 ] . V_128 == V_156 )
F_12 ( V_35 -> V_36 , L_54 ,
V_3 ? L_38 : L_39 ,
V_35 -> V_34 [ V_3 ] . V_118 ) ;
if ( V_35 -> V_34 [ V_3 ] . V_128 ++ != 0 )
continue;
if ( ( V_35 -> V_34 [ V_3 ] . V_118 != V_157 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 != V_154 ) )
continue;
F_8 ( V_35 -> V_36 , L_55 ,
V_3 ? L_38 : L_39 , V_35 -> V_14 -> V_37 ) ;
V_127 -> V_21 = V_35 -> V_34 [ V_3 ] . V_21 ;
V_147 = F_29 ( V_127 ) ;
if ( V_147 < 0 ) {
F_12 ( V_35 -> V_36 , L_56 , V_147 ) ;
V_35 -> V_34 [ V_3 ] . V_128 -- ;
if ( V_35 -> V_34 [ V_3 ] . V_128 < 0 )
F_12 ( V_35 -> V_36 , L_57 ,
V_3 ? L_38 : L_39 ,
V_35 -> V_34 [ V_3 ] . V_118 ) ;
V_35 -> V_34 [ V_3 ] . V_118 = V_154 ;
goto V_158;
}
V_35 -> V_34 [ V_3 ] . V_118 = V_153 ;
V_155 ++ ;
}
return V_155 ;
V_158:
F_77 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_35 = V_34 -> V_35 ;
struct V_16 * V_127 =
F_58 ( V_35 , V_3 ) ;
if ( ! F_76 ( V_30 , V_35 , V_3 ) )
continue;
if ( V_35 -> V_34 [ V_3 ] . V_128 == 0 )
F_12 ( V_35 -> V_36 , L_58 ,
V_3 ? L_38 : L_39 ,
V_35 -> V_34 [ V_3 ] . V_118 ) ;
if ( -- V_35 -> V_34 [ V_3 ] . V_128 != 0 )
continue;
if ( V_35 -> V_34 [ V_3 ] . V_118 != V_153 )
continue;
F_41 ( V_127 ) ;
V_127 -> V_21 = NULL ;
V_35 -> V_34 [ V_3 ] . V_118 = V_154 ;
}
return V_147 ;
}
static void F_78 ( struct V_20 * V_21 ,
struct V_67 * V_3 )
{
V_21 -> V_19 . V_73 = V_3 -> V_73 ;
V_21 -> V_19 . V_74 = V_3 -> V_74 ;
V_21 -> V_19 . V_70 = V_3 -> V_70 ;
V_21 -> V_19 . V_71 = V_3 -> V_71 ;
if ( V_21 -> V_19 . V_23 )
V_21 -> V_19 . V_23 &= V_3 -> V_23 ;
else
V_21 -> V_19 . V_23 = V_3 -> V_23 ;
V_21 -> V_19 . V_72 = V_3 -> V_72 ;
}
static void F_79 ( struct V_16 * V_17 )
{
struct V_20 * V_21 = V_17 -> V_21 ;
struct V_1 * V_2 = V_17 -> V_39 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_55 * V_78 = V_5 -> V_42 ;
if ( V_17 -> V_3 == V_8 )
F_78 ( V_21 , & V_78 -> V_63 ) ;
else
F_78 ( V_21 , & V_78 -> V_65 ) ;
}
static int F_80 ( struct V_16 * V_126 )
{
struct V_1 * V_30 = V_126 -> V_39 ;
struct V_20 * V_21 = V_126 -> V_21 ;
int V_3 = V_126 -> V_3 , V_40 = 0 ;
V_30 -> V_34 [ V_3 ] . V_144 = V_159 ;
V_40 = F_75 ( V_30 , V_126 -> V_3 ) ;
if ( V_40 < 0 ) {
F_12 ( V_30 -> V_36 , L_59 , V_40 ) ;
goto V_160;
}
F_8 ( V_30 -> V_36 , L_60 , V_30 -> V_14 -> V_37 ) ;
V_40 = F_29 ( V_126 ) ;
if ( V_40 < 0 ) {
F_12 ( V_30 -> V_36 , L_61 , V_40 ) ;
goto V_158;
}
V_30 -> V_34 [ V_3 ] . V_118 = V_153 ;
F_79 ( V_126 ) ;
F_27 ( V_21 ) ;
V_30 -> V_34 [ V_3 ] . V_144 = V_152 ;
return 0 ;
V_158:
F_74 ( V_30 , V_126 -> V_3 ) ;
V_160:
V_30 -> V_34 [ V_3 ] . V_144 = V_152 ;
return V_40 ;
}
int F_81 ( struct V_1 * V_30 , int V_3 )
{
struct V_33 * V_34 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_35 = V_34 -> V_35 ;
struct V_16 * V_127 =
F_58 ( V_35 , V_3 ) ;
if ( ! F_76 ( V_30 , V_35 , V_3 ) )
continue;
if ( V_35 -> V_34 [ V_3 ] . V_128 == 0 )
F_12 ( V_35 -> V_36 , L_52 ,
V_3 ? L_38 : L_39 ,
V_35 -> V_34 [ V_3 ] . V_118 ) ;
if ( -- V_35 -> V_34 [ V_3 ] . V_128 != 0 )
continue;
if ( ( V_35 -> V_34 [ V_3 ] . V_118 != V_161 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 != V_153 ) )
continue;
F_8 ( V_35 -> V_36 , L_62 ,
V_34 -> V_30 -> V_14 -> V_37 ) ;
F_41 ( V_127 ) ;
V_127 -> V_21 = NULL ;
V_35 -> V_34 [ V_3 ] . V_118 = V_154 ;
}
return 0 ;
}
static int F_82 ( struct V_16 * V_17 )
{
struct V_1 * V_30 = V_17 -> V_39 ;
int V_3 = V_17 -> V_3 ;
V_30 -> V_34 [ V_3 ] . V_144 = V_159 ;
F_81 ( V_30 , V_17 -> V_3 ) ;
F_8 ( V_30 -> V_36 , L_63 , V_30 -> V_14 -> V_37 ) ;
F_41 ( V_17 ) ;
F_6 ( V_30 , V_3 , V_100 ) ;
V_30 -> V_34 [ V_3 ] . V_118 = V_154 ;
V_30 -> V_34 [ V_3 ] . V_144 = V_152 ;
return 0 ;
}
int F_83 ( struct V_1 * V_30 , int V_3 )
{
struct V_33 * V_34 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_35 = V_34 -> V_35 ;
struct V_16 * V_127 =
F_58 ( V_35 , V_3 ) ;
if ( ! F_76 ( V_30 , V_35 , V_3 ) )
continue;
if ( ! F_84 ( V_30 , V_35 , V_3 ) )
continue;
if ( ( V_35 -> V_34 [ V_3 ] . V_118 != V_162 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 != V_163 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 != V_161 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 != V_164 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 != V_165 ) )
continue;
F_8 ( V_35 -> V_36 , L_64 ,
V_34 -> V_30 -> V_14 -> V_37 ) ;
F_48 ( V_127 ) ;
V_35 -> V_34 [ V_3 ] . V_118 = V_161 ;
}
return 0 ;
}
static int F_85 ( struct V_16 * V_17 )
{
struct V_1 * V_30 = V_17 -> V_39 ;
int V_147 , V_3 = V_17 -> V_3 ;
F_32 ( & V_30 -> V_104 -> V_166 , V_167 ) ;
V_30 -> V_34 [ V_3 ] . V_144 = V_159 ;
F_8 ( V_30 -> V_36 , L_65 , V_30 -> V_14 -> V_37 ) ;
V_147 = F_48 ( V_17 ) ;
if ( V_147 < 0 )
F_12 ( V_30 -> V_36 , L_66 ,
V_30 -> V_14 -> V_37 ) ;
V_147 = F_83 ( V_30 , V_3 ) ;
V_30 -> V_34 [ V_3 ] . V_118 = V_161 ;
V_30 -> V_34 [ V_3 ] . V_144 = V_152 ;
F_36 ( & V_30 -> V_104 -> V_166 ) ;
return 0 ;
}
int F_86 ( struct V_1 * V_30 , int V_3 )
{
struct V_33 * V_34 ;
int V_40 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_35 = V_34 -> V_35 ;
struct V_16 * V_127 =
F_58 ( V_35 , V_3 ) ;
if ( ! F_76 ( V_30 , V_35 , V_3 ) )
continue;
if ( ! F_87 ( V_30 , V_35 , V_3 ) )
continue;
if ( ( V_35 -> V_34 [ V_3 ] . V_118 != V_153 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 != V_162 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 != V_161 ) )
continue;
F_8 ( V_35 -> V_36 , L_67 ,
V_34 -> V_30 -> V_14 -> V_37 ) ;
memcpy ( & V_34 -> V_106 , & V_30 -> V_34 [ V_3 ] . V_106 ,
sizeof( struct V_51 ) ) ;
if ( V_35 -> V_14 -> V_168 ) {
V_40 = V_35 -> V_14 -> V_168 ( V_35 ,
& V_34 -> V_106 ) ;
if ( V_40 < 0 ) {
F_12 ( V_35 -> V_36 ,
L_68 ,
V_40 ) ;
goto V_158;
}
}
V_40 = F_47 ( V_127 , & V_34 -> V_106 ) ;
if ( V_40 < 0 ) {
F_12 ( V_34 -> V_35 -> V_36 ,
L_69 , V_40 ) ;
goto V_158;
}
V_35 -> V_34 [ V_3 ] . V_118 = V_162 ;
}
return 0 ;
V_158:
F_77 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_35 = V_34 -> V_35 ;
struct V_16 * V_127 =
F_58 ( V_35 , V_3 ) ;
if ( ! F_76 ( V_30 , V_35 , V_3 ) )
continue;
if ( ! F_84 ( V_30 , V_35 , V_3 ) )
continue;
if ( ( V_35 -> V_34 [ V_3 ] . V_118 != V_153 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 != V_162 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 != V_161 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 != V_165 ) )
continue;
F_48 ( V_127 ) ;
}
return V_40 ;
}
static int F_88 ( struct V_16 * V_17 ,
struct V_51 * V_52 )
{
struct V_1 * V_30 = V_17 -> V_39 ;
int V_40 , V_3 = V_17 -> V_3 ;
F_32 ( & V_30 -> V_104 -> V_166 , V_167 ) ;
V_30 -> V_34 [ V_3 ] . V_144 = V_159 ;
memcpy ( & V_30 -> V_34 [ V_17 -> V_3 ] . V_106 , V_52 ,
sizeof( struct V_51 ) ) ;
V_40 = F_86 ( V_30 , V_17 -> V_3 ) ;
if ( V_40 < 0 ) {
F_12 ( V_30 -> V_36 , L_69 , V_40 ) ;
goto V_83;
}
F_8 ( V_30 -> V_36 , L_70 ,
V_30 -> V_14 -> V_37 , F_14 ( V_52 ) ,
F_15 ( V_52 ) , F_17 ( V_52 ) ) ;
V_40 = F_47 ( V_17 , V_52 ) ;
if ( V_40 < 0 ) {
F_12 ( V_30 -> V_36 , L_71 , V_40 ) ;
F_83 ( V_30 , V_3 ) ;
} else
V_30 -> V_34 [ V_3 ] . V_118 = V_162 ;
V_83:
V_30 -> V_34 [ V_3 ] . V_144 = V_152 ;
F_36 ( & V_30 -> V_104 -> V_166 ) ;
return V_40 ;
}
static int F_89 ( struct V_33 * V_34 ,
struct V_16 * V_17 , int V_110 )
{
int V_40 ;
F_8 ( V_34 -> V_35 -> V_36 , L_72 ,
V_34 -> V_30 -> V_14 -> V_37 , V_110 ) ;
V_40 = F_49 ( V_17 , V_110 ) ;
if ( V_40 < 0 )
F_12 ( V_34 -> V_35 -> V_36 , L_73 , V_40 ) ;
return V_40 ;
}
int F_90 ( struct V_1 * V_30 , int V_3 ,
int V_110 )
{
struct V_33 * V_34 ;
int V_40 = 0 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_35 = V_34 -> V_35 ;
struct V_16 * V_127 =
F_58 ( V_35 , V_3 ) ;
if ( ! F_76 ( V_30 , V_35 , V_3 ) )
continue;
switch ( V_110 ) {
case V_169 :
if ( ( V_35 -> V_34 [ V_3 ] . V_118 != V_163 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 != V_165 ) )
continue;
V_40 = F_89 ( V_34 , V_127 , V_110 ) ;
if ( V_40 )
return V_40 ;
V_35 -> V_34 [ V_3 ] . V_118 = V_170 ;
break;
case V_171 :
if ( ( V_35 -> V_34 [ V_3 ] . V_118 != V_172 ) )
continue;
V_40 = F_89 ( V_34 , V_127 , V_110 ) ;
if ( V_40 )
return V_40 ;
V_35 -> V_34 [ V_3 ] . V_118 = V_170 ;
break;
case V_173 :
if ( ( V_35 -> V_34 [ V_3 ] . V_118 != V_164 ) )
continue;
V_40 = F_89 ( V_34 , V_127 , V_110 ) ;
if ( V_40 )
return V_40 ;
V_35 -> V_34 [ V_3 ] . V_118 = V_170 ;
break;
case V_174 :
if ( V_35 -> V_34 [ V_3 ] . V_118 != V_170 )
continue;
if ( ! F_84 ( V_30 , V_35 , V_3 ) )
continue;
V_40 = F_89 ( V_34 , V_127 , V_110 ) ;
if ( V_40 )
return V_40 ;
V_35 -> V_34 [ V_3 ] . V_118 = V_165 ;
break;
case V_175 :
if ( V_35 -> V_34 [ V_3 ] . V_118 != V_170 )
continue;
if ( ! F_84 ( V_30 , V_35 , V_3 ) )
continue;
V_40 = F_89 ( V_34 , V_127 , V_110 ) ;
if ( V_40 )
return V_40 ;
V_35 -> V_34 [ V_3 ] . V_118 = V_172 ;
break;
case V_176 :
if ( V_35 -> V_34 [ V_3 ] . V_118 != V_170 )
continue;
if ( ! F_84 ( V_30 , V_35 , V_3 ) )
continue;
V_40 = F_89 ( V_34 , V_127 , V_110 ) ;
if ( V_40 )
return V_40 ;
V_35 -> V_34 [ V_3 ] . V_118 = V_164 ;
break;
}
}
return V_40 ;
}
static int F_91 ( struct V_16 * V_17 , int V_110 )
{
struct V_1 * V_30 = V_17 -> V_39 ;
int V_3 = V_17 -> V_3 , V_40 ;
enum V_177 V_111 = V_30 -> V_14 -> V_111 [ V_3 ] ;
V_30 -> V_34 [ V_3 ] . V_144 = V_159 ;
switch ( V_111 ) {
case V_178 :
F_8 ( V_30 -> V_36 , L_74 ,
V_30 -> V_14 -> V_37 , V_110 ) ;
V_40 = F_49 ( V_17 , V_110 ) ;
if ( V_40 < 0 ) {
F_12 ( V_30 -> V_36 , L_75 , V_40 ) ;
goto V_83;
}
V_40 = F_90 ( V_30 , V_17 -> V_3 , V_110 ) ;
break;
case V_179 :
V_40 = F_90 ( V_30 , V_17 -> V_3 , V_110 ) ;
if ( V_40 < 0 ) {
F_12 ( V_30 -> V_36 , L_75 , V_40 ) ;
goto V_83;
}
F_8 ( V_30 -> V_36 , L_76 ,
V_30 -> V_14 -> V_37 , V_110 ) ;
V_40 = F_49 ( V_17 , V_110 ) ;
break;
case V_180 :
F_8 ( V_30 -> V_36 , L_77 ,
V_30 -> V_14 -> V_37 , V_110 ) ;
V_40 = F_50 ( V_17 , V_110 ) ;
if ( V_40 < 0 ) {
F_12 ( V_30 -> V_36 , L_75 , V_40 ) ;
goto V_83;
}
break;
default:
F_12 ( V_30 -> V_36 , L_78 , V_110 ,
V_30 -> V_14 -> V_37 ) ;
V_40 = - V_54 ;
goto V_83;
}
switch ( V_110 ) {
case V_169 :
case V_171 :
case V_173 :
V_30 -> V_34 [ V_3 ] . V_118 = V_170 ;
break;
case V_174 :
case V_175 :
case V_176 :
V_30 -> V_34 [ V_3 ] . V_118 = V_165 ;
break;
}
V_83:
V_30 -> V_34 [ V_3 ] . V_144 = V_152 ;
return V_40 ;
}
int F_92 ( struct V_1 * V_30 , int V_3 )
{
struct V_33 * V_34 ;
int V_40 = 0 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_35 = V_34 -> V_35 ;
struct V_16 * V_127 =
F_58 ( V_35 , V_3 ) ;
if ( ! F_76 ( V_30 , V_35 , V_3 ) )
continue;
if ( ( V_35 -> V_34 [ V_3 ] . V_118 != V_162 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 != V_165 ) )
continue;
F_8 ( V_35 -> V_36 , L_79 ,
V_34 -> V_30 -> V_14 -> V_37 ) ;
V_40 = F_44 ( V_127 ) ;
if ( V_40 < 0 ) {
F_12 ( V_35 -> V_36 , L_80 ,
V_40 ) ;
break;
}
V_35 -> V_34 [ V_3 ] . V_118 = V_163 ;
}
return V_40 ;
}
static int F_93 ( struct V_16 * V_17 )
{
struct V_1 * V_30 = V_17 -> V_39 ;
int V_3 = V_17 -> V_3 , V_40 = 0 ;
F_32 ( & V_30 -> V_104 -> V_166 , V_167 ) ;
F_8 ( V_30 -> V_36 , L_81 , V_30 -> V_14 -> V_37 ) ;
V_30 -> V_34 [ V_3 ] . V_144 = V_159 ;
if ( F_94 ( & V_30 -> V_34 [ V_3 ] . V_121 ) ) {
F_12 ( V_30 -> V_36 , L_82 ,
V_30 -> V_14 -> V_37 ) ;
V_40 = - V_54 ;
goto V_83;
}
V_40 = F_92 ( V_30 , V_17 -> V_3 ) ;
if ( V_40 < 0 )
goto V_83;
V_40 = F_44 ( V_17 ) ;
if ( V_40 < 0 ) {
F_12 ( V_30 -> V_36 , L_83 ,
V_30 -> V_14 -> V_37 ) ;
goto V_83;
}
F_6 ( V_30 , V_3 , V_105 ) ;
V_30 -> V_34 [ V_3 ] . V_118 = V_163 ;
V_83:
V_30 -> V_34 [ V_3 ] . V_144 = V_152 ;
F_36 ( & V_30 -> V_104 -> V_166 ) ;
return V_40 ;
}
static int F_95 ( struct V_16 * V_17 ,
unsigned int V_110 , void * V_181 )
{
struct V_1 * V_2 = V_17 -> V_39 ;
struct V_76 * V_77 = V_2 -> V_77 ;
if ( V_77 -> V_42 -> V_81 && V_77 -> V_42 -> V_81 -> V_182 )
return V_77 -> V_42 -> V_81 -> V_182 ( V_17 , V_110 , V_181 ) ;
return F_96 ( V_17 , V_110 , V_181 ) ;
}
static int F_97 ( struct V_1 * V_30 , int V_3 )
{
struct V_16 * V_17 =
F_58 ( V_30 , V_3 ) ;
enum V_177 V_111 = V_30 -> V_14 -> V_111 [ V_3 ] ;
int V_147 ;
F_8 ( V_30 -> V_36 , L_84 ,
V_3 ? L_38 : L_39 , V_30 -> V_14 -> V_37 ) ;
if ( V_111 == V_180 ) {
F_8 ( V_30 -> V_36 , L_85 ,
V_30 -> V_14 -> V_37 ) ;
V_147 = F_50 ( V_17 , V_174 ) ;
if ( V_147 < 0 )
F_12 ( V_30 -> V_36 , L_75 , V_147 ) ;
} else {
F_8 ( V_30 -> V_36 , L_86 ,
V_30 -> V_14 -> V_37 ) ;
V_147 = F_90 ( V_30 , V_3 , V_174 ) ;
if ( V_147 < 0 )
F_12 ( V_30 -> V_36 , L_75 , V_147 ) ;
}
V_147 = F_83 ( V_30 , V_3 ) ;
if ( V_147 < 0 )
F_12 ( V_30 -> V_36 , L_87 , V_147 ) ;
V_147 = F_81 ( V_30 , V_3 ) ;
if ( V_147 < 0 )
F_12 ( V_30 -> V_36 , L_88 , V_147 ) ;
F_6 ( V_30 , V_3 , V_183 ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_30 , int V_3 )
{
struct V_16 * V_17 =
F_58 ( V_30 , V_3 ) ;
struct V_33 * V_34 ;
enum V_177 V_111 = V_30 -> V_14 -> V_111 [ V_3 ] ;
int V_40 ;
F_8 ( V_30 -> V_36 , L_89 ,
V_3 ? L_38 : L_39 , V_30 -> V_14 -> V_37 ) ;
if ( V_30 -> V_34 [ V_3 ] . V_118 == V_161 ||
V_30 -> V_34 [ V_3 ] . V_118 == V_154 )
return - V_54 ;
V_40 = F_75 ( V_30 , V_3 ) ;
if ( V_40 < 0 )
goto V_184;
if ( V_30 -> V_34 [ V_3 ] . V_118 == V_153 )
return 0 ;
V_40 = F_86 ( V_30 , V_3 ) ;
if ( V_40 < 0 )
goto V_94;
if ( V_30 -> V_34 [ V_3 ] . V_118 == V_162 )
return 0 ;
V_40 = F_92 ( V_30 , V_3 ) ;
if ( V_40 < 0 )
goto V_109;
F_6 ( V_30 , V_3 , V_183 ) ;
if ( V_30 -> V_34 [ V_3 ] . V_118 == V_163 ||
V_30 -> V_34 [ V_3 ] . V_118 == V_165 )
return 0 ;
if ( V_111 == V_180 ) {
F_8 ( V_30 -> V_36 , L_90 ,
V_30 -> V_14 -> V_37 ) ;
V_40 = F_50 ( V_17 , V_169 ) ;
if ( V_40 < 0 ) {
F_12 ( V_30 -> V_36 , L_91 , V_40 ) ;
goto V_109;
}
} else {
F_8 ( V_30 -> V_36 , L_92 ,
V_30 -> V_14 -> V_37 ) ;
V_40 = F_90 ( V_30 , V_3 ,
V_169 ) ;
if ( V_40 < 0 ) {
F_12 ( V_30 -> V_36 , L_75 , V_40 ) ;
goto V_109;
}
}
return 0 ;
V_109:
F_83 ( V_30 , V_3 ) ;
V_94:
F_81 ( V_30 , V_3 ) ;
V_184:
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_35 = V_34 -> V_35 ;
if ( V_35 -> V_34 [ V_3 ] . V_118 != V_170 )
V_34 -> V_118 = V_130 ;
}
return V_40 ;
}
static int F_99 ( struct V_1 * V_30 , int V_3 )
{
int V_40 ;
V_30 -> V_34 [ V_3 ] . V_144 = V_145 ;
V_40 = F_98 ( V_30 , V_3 ) ;
if ( V_40 < 0 )
F_12 ( V_30 -> V_36 , L_93 ) ;
V_30 -> V_34 [ V_3 ] . V_144 = V_152 ;
return V_40 ;
}
static int F_100 ( struct V_1 * V_30 , int V_3 )
{
int V_40 ;
V_30 -> V_34 [ V_3 ] . V_144 = V_145 ;
V_40 = F_97 ( V_30 , V_3 ) ;
if ( V_40 < 0 )
F_12 ( V_30 -> V_36 , L_94 ) ;
V_30 -> V_34 [ V_3 ] . V_144 = V_152 ;
return V_40 ;
}
int F_101 ( struct V_131 * V_104 )
{
int V_61 , V_185 , V_146 , V_142 ;
F_32 ( & V_104 -> V_166 , V_167 ) ;
for ( V_61 = 0 ; V_61 < V_104 -> V_186 ; V_61 ++ ) {
struct V_137 * V_138 ;
struct V_1 * V_30 = & V_104 -> V_2 [ V_61 ] ;
if ( ! V_30 -> V_14 -> V_88 )
continue;
if ( ! V_30 -> V_5 -> V_11 )
continue;
F_8 ( V_30 -> V_36 , L_95 ,
V_30 -> V_14 -> V_37 ) ;
if ( ! V_30 -> V_5 -> V_42 -> V_63 . V_70 )
goto V_65;
V_142 = F_68 ( V_30 , V_8 , & V_138 ) ;
if ( V_142 < 0 ) {
F_22 ( V_30 -> V_36 , L_96 ,
V_30 -> V_14 -> V_37 , L_39 ) ;
F_36 ( & V_104 -> V_166 ) ;
return V_142 ;
}
V_146 = F_72 ( V_30 , V_8 , & V_138 , 1 ) ;
if ( V_146 ) {
F_99 ( V_30 , V_8 ) ;
F_73 ( V_30 , V_8 ) ;
F_59 ( V_30 , V_8 ) ;
}
V_185 = F_72 ( V_30 , V_8 , & V_138 , 0 ) ;
if ( V_185 ) {
F_100 ( V_30 , V_8 ) ;
F_73 ( V_30 , V_8 ) ;
F_59 ( V_30 , V_8 ) ;
}
V_65:
if ( ! V_30 -> V_5 -> V_42 -> V_65 . V_70 )
continue;
V_142 = F_68 ( V_30 , V_102 , & V_138 ) ;
if ( V_142 < 0 ) {
F_22 ( V_30 -> V_36 , L_96 ,
V_30 -> V_14 -> V_37 , L_38 ) ;
F_36 ( & V_104 -> V_166 ) ;
return V_142 ;
}
V_146 = F_72 ( V_30 , V_102 , & V_138 , 1 ) ;
if ( V_146 ) {
F_99 ( V_30 , V_102 ) ;
F_73 ( V_30 , V_102 ) ;
F_59 ( V_30 , V_102 ) ;
}
V_185 = F_72 ( V_30 , V_102 , & V_138 , 0 ) ;
if ( V_185 ) {
F_100 ( V_30 , V_102 ) ;
F_73 ( V_30 , V_102 ) ;
F_59 ( V_30 , V_102 ) ;
}
F_102 ( & V_138 ) ;
}
F_36 ( & V_104 -> V_166 ) ;
return 0 ;
}
int F_103 ( struct V_1 * V_30 , int V_187 )
{
struct V_33 * V_34 ;
struct V_188 * V_189 =
& V_30 -> V_34 [ V_8 ] . V_121 ;
F_7 (dpcm, clients, list_be) {
struct V_1 * V_35 = V_34 -> V_35 ;
struct V_4 * V_60 = V_35 -> V_6 ;
struct V_55 * V_190 = V_60 -> V_42 ;
if ( V_35 -> V_14 -> V_191 )
continue;
F_8 ( V_35 -> V_36 , L_97 , V_35 -> V_14 -> V_37 ) ;
if ( V_190 -> V_81 && V_190 -> V_81 -> V_192 && V_60 -> V_9 )
V_190 -> V_81 -> V_192 ( V_60 , V_187 ) ;
}
return 0 ;
}
static int F_104 ( struct V_16 * V_126 )
{
struct V_1 * V_30 = V_126 -> V_39 ;
struct V_33 * V_34 ;
struct V_137 * V_138 ;
int V_40 ;
int V_3 = V_126 -> V_3 ;
F_32 ( & V_30 -> V_104 -> V_166 , V_167 ) ;
V_30 -> V_34 [ V_3 ] . V_21 = V_126 -> V_21 ;
if ( F_68 ( V_30 , V_3 , & V_138 ) <= 0 ) {
F_8 ( V_30 -> V_36 , L_98 ,
V_30 -> V_14 -> V_37 , V_3 ? L_38 : L_39 ) ;
}
F_72 ( V_30 , V_3 , & V_138 , 1 ) ;
V_40 = F_80 ( V_126 ) ;
if ( V_40 < 0 ) {
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_34 -> V_118 = V_130 ;
F_59 ( V_30 , V_3 ) ;
V_30 -> V_34 [ V_3 ] . V_21 = NULL ;
}
F_73 ( V_30 , V_3 ) ;
F_102 ( & V_138 ) ;
F_36 ( & V_30 -> V_104 -> V_166 ) ;
return V_40 ;
}
static int F_105 ( struct V_16 * V_126 )
{
struct V_1 * V_30 = V_126 -> V_39 ;
struct V_33 * V_34 ;
int V_3 = V_126 -> V_3 , V_40 ;
F_32 ( & V_30 -> V_104 -> V_166 , V_167 ) ;
V_40 = F_82 ( V_126 ) ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_34 -> V_118 = V_130 ;
F_59 ( V_30 , V_3 ) ;
V_30 -> V_34 [ V_3 ] . V_21 = NULL ;
F_36 ( & V_30 -> V_104 -> V_166 ) ;
return V_40 ;
}
int F_106 ( struct V_1 * V_2 , int V_193 )
{
struct V_76 * V_77 = V_2 -> V_77 ;
struct V_4 * V_6 = V_2 -> V_6 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_194 * V_195 ;
char V_196 [ 64 ] ;
int V_40 = 0 , V_63 = 0 , V_65 = 0 ;
if ( V_2 -> V_14 -> V_88 || V_2 -> V_14 -> V_89 ) {
V_63 = V_2 -> V_14 -> V_197 ;
V_65 = V_2 -> V_14 -> V_198 ;
} else {
if ( V_6 -> V_42 -> V_63 . V_70 &&
V_5 -> V_42 -> V_63 . V_70 )
V_63 = 1 ;
if ( V_6 -> V_42 -> V_65 . V_70 &&
V_5 -> V_42 -> V_65 . V_70 )
V_65 = 1 ;
}
if ( V_2 -> V_14 -> V_199 ) {
V_63 = 1 ;
V_65 = 0 ;
}
if ( V_2 -> V_14 -> V_200 ) {
V_63 = 0 ;
V_65 = 1 ;
}
if ( V_2 -> V_14 -> V_89 ) {
snprintf ( V_196 , sizeof( V_196 ) , L_99 ,
V_2 -> V_14 -> V_98 ) ;
V_40 = F_107 ( V_2 -> V_104 -> V_201 , V_196 , V_193 ,
V_63 , V_65 , & V_195 ) ;
} else {
if ( V_2 -> V_14 -> V_88 )
snprintf ( V_196 , sizeof( V_196 ) , L_100 ,
V_2 -> V_14 -> V_98 ) ;
else
snprintf ( V_196 , sizeof( V_196 ) , L_101 ,
V_2 -> V_14 -> V_98 , V_6 -> V_37 , V_193 ) ;
V_40 = F_108 ( V_2 -> V_104 -> V_201 , V_196 , V_193 , V_63 ,
V_65 , & V_195 ) ;
}
if ( V_40 < 0 ) {
F_12 ( V_2 -> V_104 -> V_36 , L_102 ,
V_2 -> V_14 -> V_37 ) ;
return V_40 ;
}
F_8 ( V_2 -> V_104 -> V_36 , L_103 , V_193 , V_196 ) ;
F_109 ( & V_2 -> V_97 , F_39 ) ;
V_2 -> V_195 = V_195 ;
V_195 -> V_39 = V_2 ;
if ( V_2 -> V_14 -> V_89 ) {
if ( V_63 )
V_195 -> V_202 [ V_8 ] . V_17 -> V_39 = V_2 ;
if ( V_65 )
V_195 -> V_202 [ V_102 ] . V_17 -> V_39 = V_2 ;
goto V_83;
}
if ( V_2 -> V_14 -> V_88 ) {
V_2 -> V_81 . V_84 = F_104 ;
V_2 -> V_81 . V_106 = F_88 ;
V_2 -> V_81 . V_103 = F_93 ;
V_2 -> V_81 . V_111 = F_91 ;
V_2 -> V_81 . V_109 = F_85 ;
V_2 -> V_81 . V_94 = F_105 ;
V_2 -> V_81 . V_115 = F_51 ;
V_2 -> V_81 . V_182 = F_95 ;
} else {
V_2 -> V_81 . V_84 = F_29 ;
V_2 -> V_81 . V_106 = F_47 ;
V_2 -> V_81 . V_103 = F_44 ;
V_2 -> V_81 . V_111 = F_49 ;
V_2 -> V_81 . V_109 = F_48 ;
V_2 -> V_81 . V_94 = F_41 ;
V_2 -> V_81 . V_115 = F_51 ;
V_2 -> V_81 . V_182 = F_95 ;
}
if ( V_77 -> V_42 -> V_81 ) {
V_2 -> V_81 . V_203 = V_77 -> V_42 -> V_81 -> V_203 ;
V_2 -> V_81 . V_204 = V_77 -> V_42 -> V_81 -> V_204 ;
V_2 -> V_81 . V_205 = V_77 -> V_42 -> V_81 -> V_205 ;
V_2 -> V_81 . V_206 = V_77 -> V_42 -> V_81 -> V_206 ;
V_2 -> V_81 . V_207 = V_77 -> V_42 -> V_81 -> V_207 ;
}
if ( V_63 )
F_110 ( V_195 , V_8 , & V_2 -> V_81 ) ;
if ( V_65 )
F_110 ( V_195 , V_102 , & V_2 -> V_81 ) ;
if ( V_77 -> V_42 -> V_208 ) {
V_40 = V_77 -> V_42 -> V_208 ( V_2 ) ;
if ( V_40 < 0 ) {
F_12 ( V_77 -> V_36 ,
L_104 ,
V_40 ) ;
return V_40 ;
}
}
V_195 -> V_209 = V_77 -> V_42 -> V_210 ;
V_83:
F_111 ( V_2 -> V_104 -> V_36 , L_105 , V_6 -> V_37 ,
V_5 -> V_37 ) ;
return V_40 ;
}
int F_112 ( struct V_1 * V_30 , int V_3 )
{
if ( V_30 -> V_34 [ V_3 ] . V_144 == V_159 )
return 1 ;
return 0 ;
}
int F_76 ( struct V_1 * V_30 ,
struct V_1 * V_35 , int V_3 )
{
if ( ( V_30 -> V_34 [ V_3 ] . V_144 == V_159 ) ||
( ( V_30 -> V_34 [ V_3 ] . V_144 == V_145 ) &&
V_35 -> V_34 [ V_3 ] . V_144 ) )
return 1 ;
return 0 ;
}
struct V_16 *
F_58 ( struct V_1 * V_35 , int V_3 )
{
return V_35 -> V_195 -> V_202 [ V_3 ] . V_17 ;
}
enum V_211
F_113 ( struct V_1 * V_35 , int V_3 )
{
return V_35 -> V_34 [ V_3 ] . V_118 ;
}
void F_114 ( struct V_1 * V_35 ,
int V_3 , enum V_211 V_118 )
{
V_35 -> V_34 [ V_3 ] . V_118 = V_118 ;
}
int F_84 ( struct V_1 * V_30 ,
struct V_1 * V_35 , int V_3 )
{
struct V_33 * V_34 ;
int V_118 ;
F_7 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_34 -> V_30 == V_30 )
continue;
V_118 = V_34 -> V_30 -> V_34 [ V_3 ] . V_118 ;
if ( V_118 == V_170 ||
V_118 == V_164 ||
V_118 == V_172 )
return 0 ;
}
return 1 ;
}
int F_87 ( struct V_1 * V_30 ,
struct V_1 * V_35 , int V_3 )
{
struct V_33 * V_34 ;
int V_118 ;
F_7 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_34 -> V_30 == V_30 )
continue;
V_118 = V_34 -> V_30 -> V_34 [ V_3 ] . V_118 ;
if ( V_118 == V_170 ||
V_118 == V_164 ||
V_118 == V_172 ||
V_118 == V_163 )
return 0 ;
}
return 1 ;
}
int F_115 ( struct V_16 * V_17 ,
int V_110 , struct V_76 * V_77 )
{
if ( V_77 -> V_42 -> V_81 && V_77 -> V_42 -> V_81 -> V_111 )
return V_77 -> V_42 -> V_81 -> V_111 ( V_17 , V_110 ) ;
return 0 ;
}
static char * F_116 ( enum V_211 V_118 )
{
switch ( V_118 ) {
case V_157 :
return L_106 ;
case V_153 :
return L_107 ;
case V_162 :
return L_108 ;
case V_163 :
return L_109 ;
case V_170 :
return L_110 ;
case V_165 :
return L_111 ;
case V_172 :
return L_112 ;
case V_164 :
return L_113 ;
case V_161 :
return L_114 ;
case V_154 :
return L_115 ;
}
return L_116 ;
}
static T_3 F_117 ( struct V_1 * V_30 ,
int V_3 , char * V_212 , T_4 V_213 )
{
struct V_51 * V_52 = & V_30 -> V_34 [ V_3 ] . V_106 ;
struct V_33 * V_34 ;
T_3 V_113 = 0 ;
V_113 += snprintf ( V_212 + V_113 , V_213 - V_113 ,
L_117 , V_30 -> V_14 -> V_37 ,
V_3 ? L_118 : L_119 ) ;
V_113 += snprintf ( V_212 + V_113 , V_213 - V_113 , L_120 ,
F_116 ( V_30 -> V_34 [ V_3 ] . V_118 ) ) ;
if ( ( V_30 -> V_34 [ V_3 ] . V_118 >= V_162 ) &&
( V_30 -> V_34 [ V_3 ] . V_118 <= V_165 ) )
V_113 += snprintf ( V_212 + V_113 , V_213 - V_113 ,
L_121
L_122 ,
F_118 ( F_17 ( V_52 ) ) ,
F_15 ( V_52 ) ,
F_14 ( V_52 ) ) ;
V_113 += snprintf ( V_212 + V_113 , V_213 - V_113 , L_123 ) ;
if ( F_94 ( & V_30 -> V_34 [ V_3 ] . V_121 ) ) {
V_113 += snprintf ( V_212 + V_113 , V_213 - V_113 ,
L_124 ) ;
goto V_83;
}
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_35 = V_34 -> V_35 ;
V_52 = & V_34 -> V_106 ;
V_113 += snprintf ( V_212 + V_113 , V_213 - V_113 ,
L_125 , V_35 -> V_14 -> V_37 ) ;
V_113 += snprintf ( V_212 + V_113 , V_213 - V_113 ,
L_126 ,
F_116 ( V_35 -> V_34 [ V_3 ] . V_118 ) ) ;
if ( ( V_35 -> V_34 [ V_3 ] . V_118 >= V_162 ) &&
( V_35 -> V_34 [ V_3 ] . V_118 <= V_165 ) )
V_113 += snprintf ( V_212 + V_113 , V_213 - V_113 ,
L_127
L_122 ,
F_118 ( F_17 ( V_52 ) ) ,
F_15 ( V_52 ) ,
F_14 ( V_52 ) ) ;
}
V_83:
return V_113 ;
}
static T_3 F_119 ( struct V_214 * V_214 , char T_5 * V_215 ,
T_4 V_155 , T_6 * V_216 )
{
struct V_1 * V_30 = V_214 -> V_39 ;
T_3 V_217 = V_218 , V_113 = 0 , V_40 = 0 ;
char * V_212 ;
V_212 = F_120 ( V_217 , V_116 ) ;
if ( ! V_212 )
return - V_117 ;
if ( V_30 -> V_5 -> V_42 -> V_63 . V_70 )
V_113 += F_117 ( V_30 , V_8 ,
V_212 + V_113 , V_217 - V_113 ) ;
if ( V_30 -> V_5 -> V_42 -> V_65 . V_70 )
V_113 += F_117 ( V_30 , V_102 ,
V_212 + V_113 , V_217 - V_113 ) ;
V_40 = F_121 ( V_215 , V_155 , V_216 , V_212 , V_113 ) ;
F_63 ( V_212 ) ;
return V_40 ;
}
int F_122 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_14 )
return 0 ;
V_2 -> V_125 = F_123 ( V_2 -> V_14 -> V_37 ,
V_2 -> V_104 -> V_219 ) ;
if ( ! V_2 -> V_125 ) {
F_8 ( V_2 -> V_36 ,
L_128 ,
V_2 -> V_14 -> V_37 ) ;
return - V_54 ;
}
V_2 -> V_220 = F_124 ( L_129 , 0444 ,
V_2 -> V_125 ,
V_2 , & V_221 ) ;
return 0 ;
}
