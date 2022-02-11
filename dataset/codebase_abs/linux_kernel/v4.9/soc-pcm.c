static bool F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
if ( V_3 == V_6 )
V_5 = & V_2 -> V_7 -> V_8 ;
else
V_5 = & V_2 -> V_7 -> V_9 ;
return V_5 -> V_10 ;
}
void F_2 ( struct V_11 * V_12 , int V_3 )
{
struct V_1 * V_13 = V_12 -> V_13 ;
int V_14 ;
F_3 ( & V_12 -> V_15 ) ;
if ( V_3 == V_6 ) {
V_13 -> V_16 ++ ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
V_12 -> V_18 [ V_14 ] -> V_16 ++ ;
} else {
V_13 -> V_19 ++ ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
V_12 -> V_18 [ V_14 ] -> V_19 ++ ;
}
V_13 -> V_20 ++ ;
V_13 -> V_21 -> V_20 ++ ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_12 -> V_18 [ V_14 ] -> V_20 ++ ;
V_12 -> V_18 [ V_14 ] -> V_21 -> V_20 ++ ;
}
}
void F_4 ( struct V_11 * V_12 , int V_3 )
{
struct V_1 * V_13 = V_12 -> V_13 ;
int V_14 ;
F_3 ( & V_12 -> V_15 ) ;
if ( V_3 == V_6 ) {
V_13 -> V_16 -- ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
V_12 -> V_18 [ V_14 ] -> V_16 -- ;
} else {
V_13 -> V_19 -- ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
V_12 -> V_18 [ V_14 ] -> V_19 -- ;
}
V_13 -> V_20 -- ;
V_13 -> V_21 -> V_20 -- ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_12 -> V_18 [ V_14 ] -> V_21 -> V_20 -- ;
V_12 -> V_18 [ V_14 ] -> V_20 -- ;
}
}
bool F_5 ( struct V_11 * V_12 )
{
int V_14 ;
bool V_22 = true ;
if ( ! V_12 -> V_23 || V_12 -> V_24 -> V_25 )
return true ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
V_22 &= V_12 -> V_18 [ V_14 ] -> V_21 -> V_25 ;
return V_12 -> V_13 -> V_21 -> V_25 && V_22 ;
}
int F_6 ( struct V_26 * V_27 ,
const struct V_28 * V_29 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
V_31 -> V_29 . V_32 = V_29 -> V_32 ;
V_31 -> V_29 . V_33 = V_29 -> V_33 ;
V_31 -> V_29 . V_34 = V_29 -> V_34 ;
V_31 -> V_29 . V_35 = V_29 -> V_35 ;
V_31 -> V_29 . V_36 = V_29 -> V_36 ;
V_31 -> V_29 . V_37 = V_29 -> V_37 ;
V_31 -> V_29 . V_38 = V_29 -> V_38 ;
V_31 -> V_29 . V_39 = V_29 -> V_39 ;
return 0 ;
}
int F_7 ( struct V_11 * V_40 , int V_41 ,
int V_42 )
{
struct V_43 * V_44 ;
F_8 (dpcm, &fe->dpcm[dir].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
F_9 ( V_45 -> V_46 , L_1 ,
V_45 -> V_24 -> V_47 , V_42 , V_41 ) ;
F_10 ( V_45 , V_41 , V_42 ) ;
}
F_10 ( V_40 , V_41 , V_42 ) ;
return 0 ;
}
static int F_11 ( struct V_26 * V_27 ,
struct V_1 * V_48 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
int V_50 ;
if ( V_48 -> V_51 && ( V_48 -> V_7 -> V_52 ||
V_12 -> V_24 -> V_52 ) ) {
F_9 ( V_48 -> V_46 , L_2 ,
V_48 -> V_51 ) ;
V_50 = F_12 ( V_27 -> V_31 ,
V_53 ,
V_48 -> V_51 ) ;
if ( V_50 < 0 ) {
F_13 ( V_48 -> V_46 ,
L_3 ,
V_50 ) ;
return V_50 ;
}
}
if ( V_48 -> V_54 && ( V_48 -> V_7 -> V_55 ||
V_12 -> V_24 -> V_55 ) ) {
F_9 ( V_48 -> V_46 , L_4 ,
V_48 -> V_54 ) ;
V_50 = F_12 ( V_27 -> V_31 ,
V_56 ,
V_48 -> V_54 ) ;
if ( V_50 < 0 ) {
F_13 ( V_48 -> V_46 ,
L_5 ,
V_50 ) ;
return V_50 ;
}
}
if ( V_48 -> V_57 && ( V_48 -> V_7 -> V_58 ||
V_12 -> V_24 -> V_58 ) ) {
F_9 ( V_48 -> V_46 , L_6 ,
V_48 -> V_57 ) ;
V_50 = F_12 ( V_27 -> V_31 ,
V_59 ,
V_48 -> V_57 ) ;
if ( V_50 < 0 ) {
F_13 ( V_48 -> V_46 ,
L_7 ,
V_50 ) ;
return V_50 ;
}
}
return 0 ;
}
static int F_14 ( struct V_26 * V_27 ,
struct V_60 * V_61 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_1 * V_13 = V_12 -> V_13 ;
unsigned int V_51 , V_54 , V_57 , V_62 , V_14 ;
V_51 = F_15 ( V_61 ) ;
V_54 = F_16 ( V_61 ) ;
V_57 = F_17 ( F_18 ( V_61 ) ) ;
V_62 = V_13 -> V_7 -> V_52 ||
V_12 -> V_24 -> V_52 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
V_62 |= V_12 -> V_18 [ V_14 ] -> V_7 -> V_52 ;
if ( V_62 && V_13 -> V_51 && V_13 -> V_51 != V_51 ) {
F_13 ( V_12 -> V_46 , L_8 ,
V_13 -> V_51 , V_51 ) ;
return - V_63 ;
}
V_62 = V_13 -> V_7 -> V_55 ||
V_12 -> V_24 -> V_55 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
V_62 |= V_12 -> V_18 [ V_14 ] -> V_7 -> V_55 ;
if ( V_62 && V_13 -> V_54 && V_13 -> V_54 != V_54 ) {
F_13 ( V_12 -> V_46 , L_9 ,
V_13 -> V_54 , V_54 ) ;
return - V_63 ;
}
V_62 = V_13 -> V_7 -> V_58 ||
V_12 -> V_24 -> V_58 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
V_62 |= V_12 -> V_18 [ V_14 ] -> V_7 -> V_58 ;
if ( V_62 && V_13 -> V_57 && V_13 -> V_57 != V_57 ) {
F_13 ( V_12 -> V_46 , L_10 ,
V_13 -> V_57 , V_57 ) ;
return - V_63 ;
}
return 0 ;
}
static bool F_19 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_64 * V_65 = V_12 -> V_13 -> V_7 ;
struct V_66 * V_67 = V_12 -> V_24 ;
unsigned int V_62 , V_14 ;
V_62 = V_65 -> V_52 || V_67 -> V_52 ||
V_65 -> V_55 || V_67 -> V_55 ||
V_65 -> V_58 || V_67 -> V_58 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
V_62 = V_62 ||
V_12 -> V_18 [ V_14 ] -> V_7 -> V_52 ||
V_12 -> V_18 [ V_14 ] -> V_7 -> V_55 ||
V_12 -> V_18 [ V_14 ] -> V_7 -> V_58 ;
return V_62 ;
}
static void F_20 ( struct V_26 * V_27 , int V_68 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
int V_50 ;
if ( ! V_68 )
return;
V_50 = F_21 ( V_27 -> V_31 , 0 , 0 , V_68 ) ;
if ( V_50 != 0 )
F_22 ( V_12 -> V_46 , L_11 ,
V_68 , V_50 ) ;
}
static void F_23 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_69 ;
int V_14 ;
unsigned int V_68 = 0 , V_70 ;
if ( V_27 -> V_3 == V_6 ) {
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_69 = V_12 -> V_18 [ V_14 ] ;
if ( V_69 -> V_7 -> V_8 . V_71 == 0 ) {
V_68 = 0 ;
break;
}
V_68 = F_24 ( V_69 -> V_7 -> V_8 . V_71 , V_68 ) ;
}
V_70 = V_13 -> V_7 -> V_8 . V_71 ;
} else {
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_69 = V_12 -> V_18 [ V_14 ] ;
if ( V_69 -> V_7 -> V_9 . V_71 == 0 ) {
V_68 = 0 ;
break;
}
V_68 = F_24 ( V_69 -> V_7 -> V_9 . V_71 , V_68 ) ;
}
V_70 = V_13 -> V_7 -> V_9 . V_71 ;
}
F_20 ( V_27 , V_68 ) ;
F_20 ( V_27 , V_70 ) ;
}
static void F_25 ( struct V_26 * V_27 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_28 * V_29 = & V_31 -> V_29 ;
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_64 * V_72 = V_12 -> V_13 -> V_7 ;
struct V_64 * V_73 ;
struct V_4 * V_5 ;
struct V_4 * V_74 ;
unsigned int V_75 = 0 , V_76 = V_77 ;
unsigned int V_78 = 0 , V_79 = V_77 ;
unsigned int V_10 = V_77 ;
T_1 V_33 = V_80 ;
int V_14 ;
if ( V_27 -> V_3 == V_6 )
V_74 = & V_72 -> V_8 ;
else
V_74 = & V_72 -> V_9 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
if ( ! F_1 ( V_12 -> V_18 [ V_14 ] ,
V_27 -> V_3 ) )
continue;
V_73 = V_12 -> V_18 [ V_14 ] -> V_7 ;
if ( V_27 -> V_3 == V_6 )
V_5 = & V_73 -> V_8 ;
else
V_5 = & V_73 -> V_9 ;
V_75 = F_24 ( V_75 , V_5 -> V_81 ) ;
V_76 = F_26 ( V_76 , V_5 -> V_82 ) ;
V_78 = F_24 ( V_78 , V_5 -> V_78 ) ;
V_79 = F_27 ( V_79 , V_5 -> V_79 ) ;
V_33 &= V_5 -> V_33 ;
V_10 = F_28 ( V_5 -> V_10 , V_10 ) ;
}
if ( V_12 -> V_17 > 1 ) {
V_75 = V_74 -> V_81 ;
V_76 = V_74 -> V_82 ;
}
V_29 -> V_81 = F_24 ( V_75 , V_74 -> V_81 ) ;
V_29 -> V_82 = F_26 ( V_76 , V_74 -> V_82 ) ;
if ( V_29 -> V_33 )
V_29 -> V_33 &= V_33 & V_74 -> V_33 ;
else
V_29 -> V_33 = V_33 & V_74 -> V_33 ;
V_29 -> V_10 = F_28 ( V_10 , V_74 -> V_10 ) ;
F_29 ( V_31 ) ;
V_29 -> V_78 = F_24 ( V_29 -> V_78 , V_74 -> V_78 ) ;
V_29 -> V_78 = F_24 ( V_29 -> V_78 , V_78 ) ;
V_29 -> V_79 = F_27 ( V_29 -> V_79 , V_74 -> V_79 ) ;
V_29 -> V_79 = F_27 ( V_29 -> V_79 , V_79 ) ;
}
static int F_30 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_83 * V_84 = V_12 -> V_84 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_69 ;
const char * V_85 = L_12 ;
int V_14 , V_50 = 0 ;
F_31 ( V_13 -> V_46 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
F_31 ( V_12 -> V_18 [ V_14 ] -> V_46 ) ;
F_32 ( V_13 -> V_46 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
F_32 ( V_12 -> V_18 [ V_14 ] -> V_46 ) ;
F_32 ( V_84 -> V_46 ) ;
F_33 ( & V_12 -> V_15 , V_12 -> V_86 ) ;
if ( V_13 -> V_7 -> V_87 && V_13 -> V_7 -> V_87 -> V_88 ) {
V_50 = V_13 -> V_7 -> V_87 -> V_88 ( V_27 , V_13 ) ;
if ( V_50 < 0 ) {
F_13 ( V_13 -> V_46 , L_13
L_14 , V_13 -> V_47 , V_50 ) ;
goto V_89;
}
}
if ( V_84 -> V_7 -> V_87 && V_84 -> V_7 -> V_87 -> V_90 ) {
V_50 = V_84 -> V_7 -> V_87 -> V_90 ( V_27 ) ;
if ( V_50 < 0 ) {
F_13 ( V_84 -> V_46 , L_15
L_14 , V_84 -> V_21 . V_47 , V_50 ) ;
goto V_91;
}
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_69 = V_12 -> V_18 [ V_14 ] ;
if ( V_69 -> V_7 -> V_87 && V_69 -> V_7 -> V_87 -> V_88 ) {
V_50 = V_69 -> V_7 -> V_87 -> V_88 ( V_27 ,
V_69 ) ;
if ( V_50 < 0 ) {
F_13 ( V_69 -> V_46 ,
L_16 ,
V_69 -> V_47 , V_50 ) ;
goto V_92;
}
}
if ( V_27 -> V_3 == V_6 )
V_69 -> V_93 = 0 ;
else
V_69 -> V_94 = 0 ;
}
if ( V_12 -> V_24 -> V_87 && V_12 -> V_24 -> V_87 -> V_88 ) {
V_50 = V_12 -> V_24 -> V_87 -> V_88 ( V_27 ) ;
if ( V_50 < 0 ) {
F_34 ( L_17 ,
V_12 -> V_24 -> V_47 , V_50 ) ;
goto V_95;
}
}
if ( V_12 -> V_24 -> V_96 || V_12 -> V_24 -> V_97 )
goto V_96;
F_25 ( V_27 ) ;
if ( V_12 -> V_17 == 1 )
V_85 = V_12 -> V_69 -> V_47 ;
if ( F_19 ( V_27 ) )
V_31 -> V_29 . V_32 |= V_98 ;
V_50 = - V_63 ;
if ( ! V_31 -> V_29 . V_10 ) {
F_35 ( V_99 L_18 ,
V_85 , V_13 -> V_47 ) ;
goto V_100;
}
if ( ! V_31 -> V_29 . V_33 ) {
F_35 ( V_99 L_19 ,
V_85 , V_13 -> V_47 ) ;
goto V_100;
}
if ( ! V_31 -> V_29 . V_81 || ! V_31 -> V_29 . V_82 ||
V_31 -> V_29 . V_81 > V_31 -> V_29 . V_82 ) {
F_35 ( V_99 L_20 ,
V_85 , V_13 -> V_47 ) ;
goto V_100;
}
F_23 ( V_27 ) ;
if ( V_13 -> V_20 ) {
V_50 = F_11 ( V_27 , V_13 ) ;
if ( V_50 != 0 )
goto V_100;
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
if ( V_12 -> V_18 [ V_14 ] -> V_20 ) {
V_50 = F_11 ( V_27 ,
V_12 -> V_18 [ V_14 ] ) ;
if ( V_50 != 0 )
goto V_100;
}
}
F_36 ( L_21 ,
V_85 , V_13 -> V_47 ) ;
F_36 ( L_22 , V_31 -> V_29 . V_10 ) ;
F_36 ( L_23 , V_31 -> V_29 . V_81 ,
V_31 -> V_29 . V_82 ) ;
F_36 ( L_24 , V_31 -> V_29 . V_78 ,
V_31 -> V_29 . V_79 ) ;
V_96:
F_2 ( V_12 , V_27 -> V_3 ) ;
F_37 ( & V_12 -> V_15 ) ;
return 0 ;
V_100:
if ( V_12 -> V_24 -> V_87 && V_12 -> V_24 -> V_87 -> V_101 )
V_12 -> V_24 -> V_87 -> V_101 ( V_27 ) ;
V_95:
V_14 = V_12 -> V_17 ;
V_92:
while ( -- V_14 >= 0 ) {
V_69 = V_12 -> V_18 [ V_14 ] ;
if ( V_69 -> V_7 -> V_87 -> V_101 )
V_69 -> V_7 -> V_87 -> V_101 ( V_27 , V_69 ) ;
}
if ( V_84 -> V_7 -> V_87 && V_84 -> V_7 -> V_87 -> V_102 )
V_84 -> V_7 -> V_87 -> V_102 ( V_27 ) ;
V_91:
if ( V_13 -> V_7 -> V_87 -> V_101 )
V_13 -> V_7 -> V_87 -> V_101 ( V_27 , V_13 ) ;
V_89:
F_37 ( & V_12 -> V_15 ) ;
F_38 ( V_84 -> V_46 ) ;
F_39 ( V_84 -> V_46 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
F_38 ( V_12 -> V_18 [ V_14 ] -> V_46 ) ;
F_39 ( V_12 -> V_18 [ V_14 ] -> V_46 ) ;
}
F_38 ( V_13 -> V_46 ) ;
F_39 ( V_13 -> V_46 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
if ( ! V_12 -> V_18 [ V_14 ] -> V_20 )
F_40 ( V_12 -> V_18 [ V_14 ] -> V_46 ) ;
}
if ( ! V_13 -> V_20 )
F_40 ( V_13 -> V_46 ) ;
return V_50 ;
}
static void F_41 ( struct V_103 * V_104 )
{
struct V_11 * V_12 =
F_42 ( V_104 , struct V_11 , V_105 . V_104 ) ;
struct V_1 * V_69 = V_12 -> V_18 [ 0 ] ;
F_33 ( & V_12 -> V_15 , V_12 -> V_86 ) ;
F_9 ( V_12 -> V_46 , L_25 ,
V_69 -> V_7 -> V_8 . V_106 ,
V_69 -> V_16 ? L_26 : L_27 ,
V_12 -> V_107 ? L_28 : L_29 ) ;
if ( V_12 -> V_107 == 1 ) {
V_12 -> V_107 = 0 ;
F_10 ( V_12 , V_6 ,
V_108 ) ;
}
F_37 ( & V_12 -> V_15 ) ;
}
static int F_43 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_83 * V_84 = V_12 -> V_84 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_69 ;
int V_14 ;
F_33 ( & V_12 -> V_15 , V_12 -> V_86 ) ;
F_4 ( V_12 , V_27 -> V_3 ) ;
if ( ! V_13 -> V_20 )
V_13 -> V_51 = 0 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_69 = V_12 -> V_18 [ V_14 ] ;
if ( ! V_69 -> V_20 )
V_69 -> V_51 = 0 ;
}
F_44 ( V_13 , 1 , V_27 -> V_3 ) ;
if ( V_13 -> V_7 -> V_87 -> V_101 )
V_13 -> V_7 -> V_87 -> V_101 ( V_27 , V_13 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_69 = V_12 -> V_18 [ V_14 ] ;
if ( V_69 -> V_7 -> V_87 -> V_101 )
V_69 -> V_7 -> V_87 -> V_101 ( V_27 , V_69 ) ;
}
if ( V_12 -> V_24 -> V_87 && V_12 -> V_24 -> V_87 -> V_101 )
V_12 -> V_24 -> V_87 -> V_101 ( V_27 ) ;
if ( V_84 -> V_7 -> V_87 && V_84 -> V_7 -> V_87 -> V_102 )
V_84 -> V_7 -> V_87 -> V_102 ( V_27 ) ;
if ( V_27 -> V_3 == V_6 ) {
if ( F_5 ( V_12 ) ) {
F_10 ( V_12 ,
V_6 ,
V_108 ) ;
} else {
V_12 -> V_107 = 1 ;
F_45 ( V_109 ,
& V_12 -> V_105 ,
F_46 ( V_12 -> V_23 ) ) ;
}
} else {
F_10 ( V_12 , V_110 ,
V_108 ) ;
}
F_37 ( & V_12 -> V_15 ) ;
F_38 ( V_84 -> V_46 ) ;
F_39 ( V_84 -> V_46 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
F_38 ( V_12 -> V_18 [ V_14 ] -> V_46 ) ;
F_39 ( V_12 -> V_18 [ V_14 ] -> V_46 ) ;
}
F_38 ( V_13 -> V_46 ) ;
F_39 ( V_13 -> V_46 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
if ( ! V_12 -> V_18 [ V_14 ] -> V_20 )
F_40 ( V_12 -> V_18 [ V_14 ] -> V_46 ) ;
}
if ( ! V_13 -> V_20 )
F_40 ( V_13 -> V_46 ) ;
return 0 ;
}
static int F_47 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_83 * V_84 = V_12 -> V_84 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_69 ;
int V_14 , V_50 = 0 ;
F_33 ( & V_12 -> V_15 , V_12 -> V_86 ) ;
if ( V_12 -> V_24 -> V_87 && V_12 -> V_24 -> V_87 -> V_111 ) {
V_50 = V_12 -> V_24 -> V_87 -> V_111 ( V_27 ) ;
if ( V_50 < 0 ) {
F_13 ( V_12 -> V_112 -> V_46 , L_30
L_31 , V_50 ) ;
goto V_89;
}
}
if ( V_84 -> V_7 -> V_87 && V_84 -> V_7 -> V_87 -> V_111 ) {
V_50 = V_84 -> V_7 -> V_87 -> V_111 ( V_27 ) ;
if ( V_50 < 0 ) {
F_13 ( V_84 -> V_46 , L_32
L_31 , V_50 ) ;
goto V_89;
}
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_69 = V_12 -> V_18 [ V_14 ] ;
if ( V_69 -> V_7 -> V_87 && V_69 -> V_7 -> V_87 -> V_111 ) {
V_50 = V_69 -> V_7 -> V_87 -> V_111 ( V_27 ,
V_69 ) ;
if ( V_50 < 0 ) {
F_13 ( V_69 -> V_46 ,
L_33 ,
V_50 ) ;
goto V_89;
}
}
}
if ( V_13 -> V_7 -> V_87 && V_13 -> V_7 -> V_87 -> V_111 ) {
V_50 = V_13 -> V_7 -> V_87 -> V_111 ( V_27 , V_13 ) ;
if ( V_50 < 0 ) {
F_13 ( V_13 -> V_46 ,
L_34 , V_50 ) ;
goto V_89;
}
}
if ( V_27 -> V_3 == V_6 &&
V_12 -> V_107 ) {
V_12 -> V_107 = 0 ;
F_48 ( & V_12 -> V_105 ) ;
}
F_10 ( V_12 , V_27 -> V_3 ,
V_113 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
F_44 ( V_12 -> V_18 [ V_14 ] , 0 ,
V_27 -> V_3 ) ;
F_44 ( V_13 , 0 , V_27 -> V_3 ) ;
V_89:
F_37 ( & V_12 -> V_15 ) ;
return V_50 ;
}
static void F_49 ( struct V_60 * V_61 ,
unsigned int V_114 )
{
struct V_115 * V_116 ;
int V_54 = F_50 ( V_114 ) ;
V_116 = F_51 ( V_61 , V_56 ) ;
V_116 -> F_26 = V_54 ;
V_116 -> F_24 = V_54 ;
}
int F_52 ( struct V_26 * V_27 ,
struct V_60 * V_61 ,
struct V_1 * V_2 )
{
int V_50 ;
if ( V_2 -> V_7 -> V_87 && V_2 -> V_7 -> V_87 -> V_117 ) {
V_50 = V_2 -> V_7 -> V_87 -> V_117 ( V_27 , V_61 , V_2 ) ;
if ( V_50 < 0 ) {
F_13 ( V_2 -> V_46 , L_35 ,
V_2 -> V_47 , V_50 ) ;
return V_50 ;
}
}
return 0 ;
}
static int F_53 ( struct V_26 * V_27 ,
struct V_60 * V_61 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_83 * V_84 = V_12 -> V_84 ;
struct V_1 * V_13 = V_12 -> V_13 ;
int V_14 , V_50 = 0 ;
F_33 ( & V_12 -> V_15 , V_12 -> V_86 ) ;
V_50 = F_14 ( V_27 , V_61 ) ;
if ( V_50 )
goto V_89;
if ( V_12 -> V_24 -> V_87 && V_12 -> V_24 -> V_87 -> V_117 ) {
V_50 = V_12 -> V_24 -> V_87 -> V_117 ( V_27 , V_61 ) ;
if ( V_50 < 0 ) {
F_13 ( V_12 -> V_112 -> V_46 , L_36
L_37 , V_50 ) ;
goto V_89;
}
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
struct V_1 * V_69 = V_12 -> V_18 [ V_14 ] ;
struct V_60 V_118 ;
if ( ! F_1 ( V_69 , V_27 -> V_3 ) )
continue;
V_118 = * V_61 ;
if ( V_69 -> V_93 )
F_49 ( & V_118 ,
V_69 -> V_93 ) ;
if ( V_69 -> V_94 )
F_49 ( & V_118 ,
V_69 -> V_94 ) ;
V_50 = F_52 ( V_27 , & V_118 , V_69 ) ;
if( V_50 < 0 )
goto V_119;
V_69 -> V_51 = F_15 ( & V_118 ) ;
V_69 -> V_54 = F_16 ( & V_118 ) ;
V_69 -> V_57 = F_17 (
F_18 ( & V_118 ) ) ;
}
V_50 = F_52 ( V_27 , V_61 , V_13 ) ;
if ( V_50 < 0 )
goto V_120;
if ( V_84 -> V_7 -> V_87 && V_84 -> V_7 -> V_87 -> V_117 ) {
V_50 = V_84 -> V_7 -> V_87 -> V_117 ( V_27 , V_61 ) ;
if ( V_50 < 0 ) {
F_13 ( V_84 -> V_46 , L_38 ,
V_84 -> V_21 . V_47 , V_50 ) ;
goto V_91;
}
}
V_13 -> V_51 = F_15 ( V_61 ) ;
V_13 -> V_54 = F_16 ( V_61 ) ;
V_13 -> V_57 =
F_17 ( F_18 ( V_61 ) ) ;
V_89:
F_37 ( & V_12 -> V_15 ) ;
return V_50 ;
V_91:
if ( V_13 -> V_7 -> V_87 && V_13 -> V_7 -> V_87 -> V_121 )
V_13 -> V_7 -> V_87 -> V_121 ( V_27 , V_13 ) ;
V_120:
V_14 = V_12 -> V_17 ;
V_119:
while ( -- V_14 >= 0 ) {
struct V_1 * V_69 = V_12 -> V_18 [ V_14 ] ;
if ( V_69 -> V_7 -> V_87 && V_69 -> V_7 -> V_87 -> V_121 )
V_69 -> V_7 -> V_87 -> V_121 ( V_27 , V_69 ) ;
V_69 -> V_51 = 0 ;
}
if ( V_12 -> V_24 -> V_87 && V_12 -> V_24 -> V_87 -> V_121 )
V_12 -> V_24 -> V_87 -> V_121 ( V_27 ) ;
F_37 ( & V_12 -> V_15 ) ;
return V_50 ;
}
static int F_54 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_83 * V_84 = V_12 -> V_84 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_69 ;
bool V_8 = V_27 -> V_3 == V_6 ;
int V_14 ;
F_33 ( & V_12 -> V_15 , V_12 -> V_86 ) ;
if ( V_13 -> V_20 == 1 ) {
V_13 -> V_51 = 0 ;
V_13 -> V_54 = 0 ;
V_13 -> V_57 = 0 ;
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_69 = V_12 -> V_18 [ V_14 ] ;
if ( V_69 -> V_20 == 1 ) {
V_69 -> V_51 = 0 ;
V_69 -> V_54 = 0 ;
V_69 -> V_57 = 0 ;
}
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
if ( ( V_8 && V_12 -> V_18 [ V_14 ] -> V_16 == 1 ) ||
( ! V_8 && V_12 -> V_18 [ V_14 ] -> V_19 == 1 ) )
F_44 ( V_12 -> V_18 [ V_14 ] , 1 ,
V_27 -> V_3 ) ;
}
if ( V_12 -> V_24 -> V_87 && V_12 -> V_24 -> V_87 -> V_121 )
V_12 -> V_24 -> V_87 -> V_121 ( V_27 ) ;
if ( V_84 -> V_7 -> V_87 && V_84 -> V_7 -> V_87 -> V_121 )
V_84 -> V_7 -> V_87 -> V_121 ( V_27 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_69 = V_12 -> V_18 [ V_14 ] ;
if ( V_69 -> V_7 -> V_87 && V_69 -> V_7 -> V_87 -> V_121 )
V_69 -> V_7 -> V_87 -> V_121 ( V_27 , V_69 ) ;
}
if ( V_13 -> V_7 -> V_87 && V_13 -> V_7 -> V_87 -> V_121 )
V_13 -> V_7 -> V_87 -> V_121 ( V_27 , V_13 ) ;
F_37 ( & V_12 -> V_15 ) ;
return 0 ;
}
static int F_55 ( struct V_26 * V_27 , int V_122 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_83 * V_84 = V_12 -> V_84 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_69 ;
int V_14 , V_50 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_69 = V_12 -> V_18 [ V_14 ] ;
if ( V_69 -> V_7 -> V_87 && V_69 -> V_7 -> V_87 -> V_123 ) {
V_50 = V_69 -> V_7 -> V_87 -> V_123 ( V_27 ,
V_122 , V_69 ) ;
if ( V_50 < 0 )
return V_50 ;
}
}
if ( V_84 -> V_7 -> V_87 && V_84 -> V_7 -> V_87 -> V_123 ) {
V_50 = V_84 -> V_7 -> V_87 -> V_123 ( V_27 , V_122 ) ;
if ( V_50 < 0 )
return V_50 ;
}
if ( V_13 -> V_7 -> V_87 && V_13 -> V_7 -> V_87 -> V_123 ) {
V_50 = V_13 -> V_7 -> V_87 -> V_123 ( V_27 , V_122 , V_13 ) ;
if ( V_50 < 0 )
return V_50 ;
}
if ( V_12 -> V_24 -> V_87 && V_12 -> V_24 -> V_87 -> V_123 ) {
V_50 = V_12 -> V_24 -> V_87 -> V_123 ( V_27 , V_122 ) ;
if ( V_50 < 0 )
return V_50 ;
}
return 0 ;
}
static int F_56 ( struct V_26 * V_27 ,
int V_122 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_83 * V_84 = V_12 -> V_84 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_69 ;
int V_14 , V_50 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_69 = V_12 -> V_18 [ V_14 ] ;
if ( V_69 -> V_7 -> V_87 &&
V_69 -> V_7 -> V_87 -> V_124 ) {
V_50 = V_69 -> V_7 -> V_87 -> V_124 ( V_27 ,
V_122 , V_69 ) ;
if ( V_50 < 0 )
return V_50 ;
}
}
if ( V_84 -> V_7 -> V_124 ) {
V_50 = V_84 -> V_7 -> V_124 ( V_27 , V_122 ) ;
if ( V_50 < 0 )
return V_50 ;
}
if ( V_13 -> V_7 -> V_87 && V_13 -> V_7 -> V_87 -> V_124 ) {
V_50 = V_13 -> V_7 -> V_87 -> V_124 ( V_27 , V_122 , V_13 ) ;
if ( V_50 < 0 )
return V_50 ;
}
return 0 ;
}
static T_2 F_57 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_83 * V_84 = V_12 -> V_84 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_69 ;
struct V_30 * V_31 = V_27 -> V_31 ;
T_2 V_125 = 0 ;
T_3 V_126 = 0 ;
T_3 V_127 = 0 ;
int V_14 ;
if ( V_84 -> V_7 -> V_87 && V_84 -> V_7 -> V_87 -> V_128 )
V_125 = V_84 -> V_7 -> V_87 -> V_128 ( V_27 ) ;
if ( V_13 -> V_7 -> V_87 && V_13 -> V_7 -> V_87 -> V_126 )
V_126 += V_13 -> V_7 -> V_87 -> V_126 ( V_27 , V_13 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_69 = V_12 -> V_18 [ V_14 ] ;
if ( V_69 -> V_7 -> V_87 && V_69 -> V_7 -> V_87 -> V_126 )
V_127 = F_24 ( V_127 ,
V_69 -> V_7 -> V_87 -> V_126 ( V_27 ,
V_69 ) ) ;
}
V_126 += V_127 ;
if ( V_84 -> V_7 -> V_126 )
V_126 += V_84 -> V_7 -> V_126 ( V_27 , V_12 -> V_18 [ 0 ] ) ;
V_31 -> V_126 = V_126 ;
return V_125 ;
}
static int F_58 ( struct V_11 * V_40 ,
struct V_11 * V_45 , int V_3 )
{
struct V_43 * V_44 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
if ( V_44 -> V_45 == V_45 && V_44 -> V_40 == V_40 )
return 0 ;
}
V_44 = F_59 ( sizeof( struct V_43 ) , V_129 ) ;
if ( ! V_44 )
return - V_130 ;
V_44 -> V_45 = V_45 ;
V_44 -> V_40 = V_40 ;
V_45 -> V_44 [ V_3 ] . V_31 = V_40 -> V_44 [ V_3 ] . V_31 ;
V_44 -> V_131 = V_132 ;
F_60 ( & V_44 -> V_133 , & V_40 -> V_44 [ V_3 ] . V_134 ) ;
F_60 ( & V_44 -> V_135 , & V_45 -> V_44 [ V_3 ] . V_136 ) ;
F_9 ( V_40 -> V_46 , L_39 ,
V_3 ? L_40 : L_41 , V_40 -> V_24 -> V_47 ,
V_3 ? L_42 : L_43 , V_45 -> V_24 -> V_47 ) ;
#ifdef F_61
if ( V_40 -> V_137 )
V_44 -> V_138 = F_62 ( V_45 -> V_24 -> V_47 , 0644 ,
V_40 -> V_137 , & V_44 -> V_131 ) ;
#endif
return 1 ;
}
static void F_63 ( struct V_11 * V_40 ,
struct V_11 * V_45 , int V_3 )
{
struct V_43 * V_44 ;
struct V_26 * V_139 , * V_140 ;
if ( ! V_45 -> V_44 [ V_3 ] . V_141 )
return;
V_140 = F_64 ( V_45 , V_3 ) ;
F_8 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_44 -> V_40 == V_40 )
continue;
F_9 ( V_40 -> V_46 , L_44 ,
V_3 ? L_40 : L_41 ,
V_44 -> V_40 -> V_24 -> V_47 ,
V_3 ? L_42 : L_43 , V_44 -> V_45 -> V_24 -> V_47 ) ;
V_139 = F_64 ( V_44 -> V_40 , V_3 ) ;
V_140 -> V_31 = V_139 -> V_31 ;
break;
}
}
void F_65 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 , * V_142 ;
F_66 (dpcm, d, &fe->dpcm[stream].be_clients, list_be) {
F_9 ( V_40 -> V_46 , L_45 ,
V_3 ? L_40 : L_41 ,
V_44 -> V_45 -> V_24 -> V_47 ) ;
if ( V_44 -> V_131 != V_143 )
continue;
F_9 ( V_40 -> V_46 , L_46 ,
V_3 ? L_40 : L_41 , V_40 -> V_24 -> V_47 ,
V_3 ? L_42 : L_43 , V_44 -> V_45 -> V_24 -> V_47 ) ;
F_63 ( V_40 , V_44 -> V_45 , V_3 ) ;
#ifdef F_61
F_67 ( V_44 -> V_138 ) ;
#endif
F_68 ( & V_44 -> V_133 ) ;
F_68 ( & V_44 -> V_135 ) ;
F_69 ( V_44 ) ;
}
}
static struct V_11 * F_70 ( struct V_144 * V_112 ,
struct V_145 * V_146 , int V_3 )
{
struct V_11 * V_45 ;
int V_14 ;
if ( V_3 == V_6 ) {
F_8 (be, &card->rtd_list, list) {
if ( ! V_45 -> V_24 -> V_97 )
continue;
if ( V_45 -> V_13 -> V_147 == V_146 )
return V_45 ;
for ( V_14 = 0 ; V_14 < V_45 -> V_17 ; V_14 ++ ) {
struct V_1 * V_2 = V_45 -> V_18 [ V_14 ] ;
if ( V_2 -> V_147 == V_146 )
return V_45 ;
}
}
} else {
F_8 (be, &card->rtd_list, list) {
if ( ! V_45 -> V_24 -> V_97 )
continue;
if ( V_45 -> V_13 -> V_148 == V_146 )
return V_45 ;
for ( V_14 = 0 ; V_14 < V_45 -> V_17 ; V_14 ++ ) {
struct V_1 * V_2 = V_45 -> V_18 [ V_14 ] ;
if ( V_2 -> V_148 == V_146 )
return V_45 ;
}
}
}
F_13 ( V_112 -> V_46 , L_47 ,
V_3 ? L_40 : L_41 , V_146 -> V_47 ) ;
return NULL ;
}
static inline struct V_145 *
F_71 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == V_6 )
return V_2 -> V_147 ;
else
return V_2 -> V_148 ;
}
static int F_72 ( struct V_149 * V_150 ,
struct V_145 * V_146 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_150 -> V_151 ; V_14 ++ ) {
if ( V_146 == V_150 -> V_152 [ V_14 ] )
return 1 ;
}
return 0 ;
}
static bool F_73 ( struct V_145 * V_146 ,
enum V_153 V_41 )
{
struct V_144 * V_112 = V_146 -> V_154 -> V_112 ;
struct V_11 * V_12 ;
int V_14 ;
if ( V_41 == V_155 ) {
F_8 (rtd, &card->rtd_list, list) {
if ( ! V_12 -> V_24 -> V_97 )
continue;
if ( V_12 -> V_13 -> V_147 == V_146 )
return true ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; ++ V_14 ) {
struct V_1 * V_2 = V_12 -> V_18 [ V_14 ] ;
if ( V_2 -> V_147 == V_146 )
return true ;
}
}
} else {
F_8 (rtd, &card->rtd_list, list) {
if ( ! V_12 -> V_24 -> V_97 )
continue;
if ( V_12 -> V_13 -> V_148 == V_146 )
return true ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; ++ V_14 ) {
struct V_1 * V_2 = V_12 -> V_18 [ V_14 ] ;
if ( V_2 -> V_148 == V_146 )
return true ;
}
}
}
return false ;
}
int F_74 ( struct V_11 * V_40 ,
int V_3 , struct V_149 * * V_150 )
{
struct V_1 * V_13 = V_40 -> V_13 ;
int V_156 ;
V_156 = F_75 ( V_13 , V_3 , V_150 ,
F_73 ) ;
F_9 ( V_40 -> V_46 , L_48 , V_156 ,
V_3 ? L_40 : L_41 ) ;
return V_156 ;
}
static int F_76 ( struct V_11 * V_40 , int V_3 ,
struct V_149 * * V_157 )
{
struct V_43 * V_44 ;
struct V_149 * V_150 = * V_157 ;
struct V_145 * V_146 ;
int V_158 = 0 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
unsigned int V_14 ;
V_146 = F_71 ( V_44 -> V_45 -> V_13 , V_3 ) ;
if ( V_146 && F_72 ( V_150 , V_146 ) )
continue;
for ( V_14 = 0 ; V_14 < V_44 -> V_45 -> V_17 ; V_14 ++ ) {
struct V_1 * V_2 = V_44 -> V_45 -> V_18 [ V_14 ] ;
V_146 = F_71 ( V_2 , V_3 ) ;
if ( V_146 && F_72 ( V_150 , V_146 ) )
continue;
}
F_9 ( V_40 -> V_46 , L_49 ,
V_3 ? L_40 : L_41 ,
V_44 -> V_45 -> V_24 -> V_47 , V_40 -> V_24 -> V_47 ) ;
V_44 -> V_131 = V_143 ;
V_44 -> V_45 -> V_44 [ V_3 ] . V_159 = V_160 ;
V_158 ++ ;
}
F_9 ( V_40 -> V_46 , L_50 , V_158 ) ;
return V_158 ;
}
static int F_77 ( struct V_11 * V_40 , int V_3 ,
struct V_149 * * V_157 )
{
struct V_144 * V_112 = V_40 -> V_112 ;
struct V_149 * V_150 = * V_157 ;
struct V_11 * V_45 ;
int V_14 , V_161 = 0 , V_162 ;
for ( V_14 = 0 ; V_14 < V_150 -> V_151 ; V_14 ++ ) {
switch ( V_150 -> V_152 [ V_14 ] -> V_163 ) {
case V_164 :
if ( V_3 != V_6 )
continue;
break;
case V_165 :
if ( V_3 != V_110 )
continue;
break;
default:
continue;
}
V_45 = F_70 ( V_112 , V_150 -> V_152 [ V_14 ] , V_3 ) ;
if ( ! V_45 ) {
F_13 ( V_40 -> V_46 , L_51 ,
V_150 -> V_152 [ V_14 ] -> V_47 ) ;
continue;
}
if ( ! V_45 -> V_24 -> V_97 )
continue;
if ( ! V_40 -> V_44 [ V_3 ] . V_31 && ! V_40 -> V_166 )
continue;
V_162 = F_58 ( V_40 , V_45 , V_3 ) ;
if ( V_162 < 0 ) {
F_13 ( V_40 -> V_46 , L_52 ,
V_150 -> V_152 [ V_14 ] -> V_47 ) ;
break;
} else if ( V_162 == 0 )
continue;
V_45 -> V_44 [ V_3 ] . V_159 = V_160 ;
V_161 ++ ;
}
F_9 ( V_40 -> V_46 , L_53 , V_161 ) ;
return V_161 ;
}
int F_78 ( struct V_11 * V_40 ,
int V_3 , struct V_149 * * V_150 , int V_161 )
{
if ( V_161 )
return F_77 ( V_40 , V_3 , V_150 ) ;
else
return F_76 ( V_40 , V_3 , V_150 ) ;
}
void F_79 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_44 -> V_45 -> V_44 [ V_3 ] . V_159 =
V_167 ;
}
static void F_80 ( struct V_11 * V_40 ,
int V_3 )
{
struct V_43 * V_44 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_140 =
F_64 ( V_45 , V_3 ) ;
if ( V_45 -> V_44 [ V_3 ] . V_141 == 0 )
F_13 ( V_45 -> V_46 , L_54 ,
V_3 ? L_40 : L_41 ,
V_45 -> V_44 [ V_3 ] . V_131 ) ;
if ( -- V_45 -> V_44 [ V_3 ] . V_141 != 0 )
continue;
if ( V_45 -> V_44 [ V_3 ] . V_131 != V_168 )
continue;
F_43 ( V_140 ) ;
V_140 -> V_31 = NULL ;
V_45 -> V_44 [ V_3 ] . V_131 = V_169 ;
}
}
int F_81 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 ;
int V_162 , V_170 = 0 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_140 =
F_64 ( V_45 , V_3 ) ;
if ( ! V_140 ) {
F_13 ( V_45 -> V_46 , L_55 ,
V_3 ? L_40 : L_41 ) ;
continue;
}
if ( ! F_82 ( V_40 , V_45 , V_3 ) )
continue;
if ( V_45 -> V_44 [ V_3 ] . V_141 == V_171 )
F_13 ( V_45 -> V_46 , L_56 ,
V_3 ? L_40 : L_41 ,
V_45 -> V_44 [ V_3 ] . V_131 ) ;
if ( V_45 -> V_44 [ V_3 ] . V_141 ++ != 0 )
continue;
if ( ( V_45 -> V_44 [ V_3 ] . V_131 != V_172 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_169 ) )
continue;
F_9 ( V_45 -> V_46 , L_57 ,
V_3 ? L_40 : L_41 , V_45 -> V_24 -> V_47 ) ;
V_140 -> V_31 = V_45 -> V_44 [ V_3 ] . V_31 ;
V_162 = F_30 ( V_140 ) ;
if ( V_162 < 0 ) {
F_13 ( V_45 -> V_46 , L_58 , V_162 ) ;
V_45 -> V_44 [ V_3 ] . V_141 -- ;
if ( V_45 -> V_44 [ V_3 ] . V_141 < 0 )
F_13 ( V_45 -> V_46 , L_59 ,
V_3 ? L_40 : L_41 ,
V_45 -> V_44 [ V_3 ] . V_131 ) ;
V_45 -> V_44 [ V_3 ] . V_131 = V_169 ;
goto V_173;
}
V_45 -> V_44 [ V_3 ] . V_131 = V_168 ;
V_170 ++ ;
}
return V_170 ;
V_173:
F_83 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_140 =
F_64 ( V_45 , V_3 ) ;
if ( ! F_82 ( V_40 , V_45 , V_3 ) )
continue;
if ( V_45 -> V_44 [ V_3 ] . V_141 == 0 )
F_13 ( V_45 -> V_46 , L_60 ,
V_3 ? L_40 : L_41 ,
V_45 -> V_44 [ V_3 ] . V_131 ) ;
if ( -- V_45 -> V_44 [ V_3 ] . V_141 != 0 )
continue;
if ( V_45 -> V_44 [ V_3 ] . V_131 != V_168 )
continue;
F_43 ( V_140 ) ;
V_140 -> V_31 = NULL ;
V_45 -> V_44 [ V_3 ] . V_131 = V_169 ;
}
return V_162 ;
}
static void F_84 ( struct V_30 * V_31 ,
struct V_4 * V_3 ,
T_1 V_33 )
{
V_31 -> V_29 . V_78 = V_3 -> V_78 ;
V_31 -> V_29 . V_79 = V_3 -> V_79 ;
V_31 -> V_29 . V_81 = V_3 -> V_81 ;
V_31 -> V_29 . V_82 = V_3 -> V_82 ;
if ( V_31 -> V_29 . V_33 )
V_31 -> V_29 . V_33 &= V_33 & V_3 -> V_33 ;
else
V_31 -> V_29 . V_33 = V_33 & V_3 -> V_33 ;
V_31 -> V_29 . V_10 = V_3 -> V_10 ;
}
static T_1 F_85 ( struct V_26 * V_27 )
{
struct V_11 * V_40 = V_27 -> V_49 ;
struct V_43 * V_44 ;
T_1 V_33 = V_80 ;
int V_3 = V_27 -> V_3 ;
if ( ! V_40 -> V_24 -> V_174 )
return V_33 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_64 * V_73 ;
struct V_4 * V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_45 -> V_17 ; V_14 ++ ) {
V_73 = V_45 -> V_18 [ V_14 ] -> V_7 ;
if ( V_3 == V_6 )
V_5 = & V_73 -> V_8 ;
else
V_5 = & V_73 -> V_9 ;
V_33 &= V_5 -> V_33 ;
}
}
return V_33 ;
}
static void F_86 ( struct V_26 * V_27 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_64 * V_72 = V_13 -> V_7 ;
T_1 V_175 = F_85 ( V_27 ) ;
if ( V_27 -> V_3 == V_6 )
F_84 ( V_31 , & V_72 -> V_8 , V_175 ) ;
else
F_84 ( V_31 , & V_72 -> V_9 , V_175 ) ;
}
static void F_87 ( struct V_11 * V_40 ,
int V_3 , enum V_176 V_131 )
{
struct V_26 * V_27 =
F_64 ( V_40 , V_3 ) ;
F_88 ( V_27 ) ;
if ( V_131 == V_167 && V_40 -> V_44 [ V_3 ] . V_177 ) {
F_89 ( V_27 ,
V_40 -> V_44 [ V_3 ] . V_177 - 1 ) ;
V_40 -> V_44 [ V_3 ] . V_177 = 0 ;
}
V_40 -> V_44 [ V_3 ] . V_159 = V_131 ;
F_90 ( V_27 ) ;
}
static int F_91 ( struct V_26 * V_139 ,
int V_3 )
{
struct V_43 * V_44 ;
struct V_11 * V_40 = V_139 -> V_49 ;
struct V_1 * V_178 = V_40 -> V_13 ;
int V_162 ;
if ( F_19 ( V_139 ) )
V_139 -> V_31 -> V_29 . V_32 |= V_98 ;
if ( V_178 -> V_20 ) {
V_162 = F_11 ( V_139 , V_178 ) ;
if ( V_162 < 0 )
return V_162 ;
}
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_140 =
F_64 ( V_45 , V_3 ) ;
struct V_11 * V_12 = V_140 -> V_49 ;
int V_14 ;
if ( V_12 -> V_24 -> V_179 )
continue;
if ( F_19 ( V_140 ) )
V_140 -> V_31 -> V_29 . V_32 |= V_98 ;
if ( V_12 -> V_13 -> V_20 ) {
V_162 = F_11 ( V_140 , V_12 -> V_13 ) ;
if ( V_162 < 0 )
return V_162 ;
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
if ( V_12 -> V_18 [ V_14 ] -> V_20 ) {
V_162 = F_11 ( V_140 ,
V_12 -> V_18 [ V_14 ] ) ;
if ( V_162 < 0 )
return V_162 ;
}
}
}
return 0 ;
}
static int F_92 ( struct V_26 * V_139 )
{
struct V_11 * V_40 = V_139 -> V_49 ;
struct V_30 * V_31 = V_139 -> V_31 ;
int V_3 = V_139 -> V_3 , V_50 = 0 ;
F_87 ( V_40 , V_3 , V_180 ) ;
V_50 = F_81 ( V_40 , V_139 -> V_3 ) ;
if ( V_50 < 0 ) {
F_13 ( V_40 -> V_46 , L_61 , V_50 ) ;
goto V_181;
}
F_9 ( V_40 -> V_46 , L_62 , V_40 -> V_24 -> V_47 ) ;
V_50 = F_30 ( V_139 ) ;
if ( V_50 < 0 ) {
F_13 ( V_40 -> V_46 , L_63 , V_50 ) ;
goto V_173;
}
V_40 -> V_44 [ V_3 ] . V_131 = V_168 ;
F_86 ( V_139 ) ;
F_29 ( V_31 ) ;
V_50 = F_91 ( V_139 , V_3 ) ;
if ( V_50 < 0 ) {
F_13 ( V_40 -> V_46 , L_64 ,
V_50 ) ;
goto V_173;
}
F_87 ( V_40 , V_3 , V_167 ) ;
return 0 ;
V_173:
F_80 ( V_40 , V_139 -> V_3 ) ;
V_181:
F_87 ( V_40 , V_3 , V_167 ) ;
return V_50 ;
}
int F_93 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_140 =
F_64 ( V_45 , V_3 ) ;
if ( ! F_82 ( V_40 , V_45 , V_3 ) )
continue;
if ( V_45 -> V_44 [ V_3 ] . V_141 == 0 )
F_13 ( V_45 -> V_46 , L_54 ,
V_3 ? L_40 : L_41 ,
V_45 -> V_44 [ V_3 ] . V_131 ) ;
if ( -- V_45 -> V_44 [ V_3 ] . V_141 != 0 )
continue;
if ( ( V_45 -> V_44 [ V_3 ] . V_131 != V_182 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_168 ) )
continue;
F_9 ( V_45 -> V_46 , L_65 ,
V_45 -> V_24 -> V_47 ) ;
F_43 ( V_140 ) ;
V_140 -> V_31 = NULL ;
V_45 -> V_44 [ V_3 ] . V_131 = V_169 ;
}
return 0 ;
}
static int F_94 ( struct V_26 * V_27 )
{
struct V_11 * V_40 = V_27 -> V_49 ;
int V_3 = V_27 -> V_3 ;
F_87 ( V_40 , V_3 , V_180 ) ;
F_93 ( V_40 , V_27 -> V_3 ) ;
F_9 ( V_40 -> V_46 , L_66 , V_40 -> V_24 -> V_47 ) ;
F_43 ( V_27 ) ;
F_7 ( V_40 , V_3 , V_108 ) ;
V_40 -> V_44 [ V_3 ] . V_131 = V_169 ;
F_87 ( V_40 , V_3 , V_167 ) ;
return 0 ;
}
int F_95 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_140 =
F_64 ( V_45 , V_3 ) ;
if ( ! F_82 ( V_40 , V_45 , V_3 ) )
continue;
if ( ! F_96 ( V_40 , V_45 , V_3 ) )
continue;
if ( V_45 -> V_44 [ V_3 ] . V_141 > 1 )
continue;
if ( ( V_45 -> V_44 [ V_3 ] . V_131 != V_183 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_184 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_182 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_185 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_186 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_187 ) )
continue;
F_9 ( V_45 -> V_46 , L_67 ,
V_45 -> V_24 -> V_47 ) ;
F_54 ( V_140 ) ;
V_45 -> V_44 [ V_3 ] . V_131 = V_182 ;
}
return 0 ;
}
static int F_97 ( struct V_26 * V_27 )
{
struct V_11 * V_40 = V_27 -> V_49 ;
int V_162 , V_3 = V_27 -> V_3 ;
F_33 ( & V_40 -> V_112 -> V_188 , V_189 ) ;
F_87 ( V_40 , V_3 , V_180 ) ;
F_9 ( V_40 -> V_46 , L_68 , V_40 -> V_24 -> V_47 ) ;
V_162 = F_54 ( V_27 ) ;
if ( V_162 < 0 )
F_13 ( V_40 -> V_46 , L_69 ,
V_40 -> V_24 -> V_47 ) ;
V_162 = F_95 ( V_40 , V_3 ) ;
V_40 -> V_44 [ V_3 ] . V_131 = V_182 ;
F_87 ( V_40 , V_3 , V_167 ) ;
F_37 ( & V_40 -> V_112 -> V_188 ) ;
return 0 ;
}
int F_98 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 ;
int V_50 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_140 =
F_64 ( V_45 , V_3 ) ;
if ( ! F_82 ( V_40 , V_45 , V_3 ) )
continue;
memcpy ( & V_44 -> V_117 , & V_40 -> V_44 [ V_3 ] . V_117 ,
sizeof( struct V_60 ) ) ;
if ( V_45 -> V_24 -> V_179 ) {
V_50 = V_45 -> V_24 -> V_179 ( V_45 ,
& V_44 -> V_117 ) ;
if ( V_50 < 0 ) {
F_13 ( V_45 -> V_46 ,
L_70 ,
V_50 ) ;
goto V_173;
}
}
if ( ! F_99 ( V_40 , V_45 , V_3 ) )
continue;
if ( ( V_45 -> V_44 [ V_3 ] . V_131 != V_168 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_183 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_182 ) )
continue;
F_9 ( V_45 -> V_46 , L_71 ,
V_45 -> V_24 -> V_47 ) ;
V_50 = F_53 ( V_140 , & V_44 -> V_117 ) ;
if ( V_50 < 0 ) {
F_13 ( V_44 -> V_45 -> V_46 ,
L_72 , V_50 ) ;
goto V_173;
}
V_45 -> V_44 [ V_3 ] . V_131 = V_183 ;
}
return 0 ;
V_173:
F_83 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_140 =
F_64 ( V_45 , V_3 ) ;
if ( ! F_82 ( V_40 , V_45 , V_3 ) )
continue;
if ( ! F_96 ( V_40 , V_45 , V_3 ) )
continue;
if ( ( V_45 -> V_44 [ V_3 ] . V_131 != V_168 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_183 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_182 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_186 ) )
continue;
F_54 ( V_140 ) ;
}
return V_50 ;
}
static int F_100 ( struct V_26 * V_27 ,
struct V_60 * V_61 )
{
struct V_11 * V_40 = V_27 -> V_49 ;
int V_50 , V_3 = V_27 -> V_3 ;
F_33 ( & V_40 -> V_112 -> V_188 , V_189 ) ;
F_87 ( V_40 , V_3 , V_180 ) ;
memcpy ( & V_40 -> V_44 [ V_27 -> V_3 ] . V_117 , V_61 ,
sizeof( struct V_60 ) ) ;
V_50 = F_98 ( V_40 , V_27 -> V_3 ) ;
if ( V_50 < 0 ) {
F_13 ( V_40 -> V_46 , L_72 , V_50 ) ;
goto V_89;
}
F_9 ( V_40 -> V_46 , L_73 ,
V_40 -> V_24 -> V_47 , F_15 ( V_61 ) ,
F_16 ( V_61 ) , F_18 ( V_61 ) ) ;
V_50 = F_53 ( V_27 , V_61 ) ;
if ( V_50 < 0 ) {
F_13 ( V_40 -> V_46 , L_74 , V_50 ) ;
F_95 ( V_40 , V_3 ) ;
} else
V_40 -> V_44 [ V_3 ] . V_131 = V_183 ;
V_89:
F_87 ( V_40 , V_3 , V_167 ) ;
F_37 ( & V_40 -> V_112 -> V_188 ) ;
return V_50 ;
}
static int F_101 ( struct V_43 * V_44 ,
struct V_26 * V_27 , int V_122 )
{
int V_50 ;
F_9 ( V_44 -> V_45 -> V_46 , L_75 ,
V_44 -> V_45 -> V_24 -> V_47 , V_122 ) ;
V_50 = F_55 ( V_27 , V_122 ) ;
if ( V_50 < 0 )
F_13 ( V_44 -> V_45 -> V_46 , L_76 , V_50 ) ;
return V_50 ;
}
int F_102 ( struct V_11 * V_40 , int V_3 ,
int V_122 )
{
struct V_43 * V_44 ;
int V_50 = 0 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_140 =
F_64 ( V_45 , V_3 ) ;
if ( ! F_82 ( V_40 , V_45 , V_3 ) )
continue;
switch ( V_122 ) {
case V_190 :
if ( ( V_45 -> V_44 [ V_3 ] . V_131 != V_184 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_186 ) )
continue;
V_50 = F_101 ( V_44 , V_140 , V_122 ) ;
if ( V_50 )
return V_50 ;
V_45 -> V_44 [ V_3 ] . V_131 = V_191 ;
break;
case V_192 :
if ( ( V_45 -> V_44 [ V_3 ] . V_131 != V_187 ) )
continue;
V_50 = F_101 ( V_44 , V_140 , V_122 ) ;
if ( V_50 )
return V_50 ;
V_45 -> V_44 [ V_3 ] . V_131 = V_191 ;
break;
case V_193 :
if ( ( V_45 -> V_44 [ V_3 ] . V_131 != V_185 ) )
continue;
V_50 = F_101 ( V_44 , V_140 , V_122 ) ;
if ( V_50 )
return V_50 ;
V_45 -> V_44 [ V_3 ] . V_131 = V_191 ;
break;
case V_194 :
if ( V_45 -> V_44 [ V_3 ] . V_131 != V_191 )
continue;
if ( ! F_96 ( V_40 , V_45 , V_3 ) )
continue;
V_50 = F_101 ( V_44 , V_140 , V_122 ) ;
if ( V_50 )
return V_50 ;
V_45 -> V_44 [ V_3 ] . V_131 = V_186 ;
break;
case V_195 :
if ( V_45 -> V_44 [ V_3 ] . V_131 != V_191 )
continue;
if ( ! F_96 ( V_40 , V_45 , V_3 ) )
continue;
V_50 = F_101 ( V_44 , V_140 , V_122 ) ;
if ( V_50 )
return V_50 ;
V_45 -> V_44 [ V_3 ] . V_131 = V_187 ;
break;
case V_196 :
if ( V_45 -> V_44 [ V_3 ] . V_131 != V_191 )
continue;
if ( ! F_96 ( V_40 , V_45 , V_3 ) )
continue;
V_50 = F_101 ( V_44 , V_140 , V_122 ) ;
if ( V_50 )
return V_50 ;
V_45 -> V_44 [ V_3 ] . V_131 = V_185 ;
break;
}
}
return V_50 ;
}
static int F_89 ( struct V_26 * V_27 , int V_122 )
{
struct V_11 * V_40 = V_27 -> V_49 ;
int V_3 = V_27 -> V_3 , V_50 ;
enum V_197 V_123 = V_40 -> V_24 -> V_123 [ V_3 ] ;
V_40 -> V_44 [ V_3 ] . V_159 = V_180 ;
switch ( V_123 ) {
case V_198 :
F_9 ( V_40 -> V_46 , L_77 ,
V_40 -> V_24 -> V_47 , V_122 ) ;
V_50 = F_55 ( V_27 , V_122 ) ;
if ( V_50 < 0 ) {
F_13 ( V_40 -> V_46 , L_78 , V_50 ) ;
goto V_89;
}
V_50 = F_102 ( V_40 , V_27 -> V_3 , V_122 ) ;
break;
case V_199 :
V_50 = F_102 ( V_40 , V_27 -> V_3 , V_122 ) ;
if ( V_50 < 0 ) {
F_13 ( V_40 -> V_46 , L_78 , V_50 ) ;
goto V_89;
}
F_9 ( V_40 -> V_46 , L_79 ,
V_40 -> V_24 -> V_47 , V_122 ) ;
V_50 = F_55 ( V_27 , V_122 ) ;
break;
case V_200 :
F_9 ( V_40 -> V_46 , L_80 ,
V_40 -> V_24 -> V_47 , V_122 ) ;
V_50 = F_56 ( V_27 , V_122 ) ;
if ( V_50 < 0 ) {
F_13 ( V_40 -> V_46 , L_78 , V_50 ) ;
goto V_89;
}
break;
default:
F_13 ( V_40 -> V_46 , L_81 , V_122 ,
V_40 -> V_24 -> V_47 ) ;
V_50 = - V_63 ;
goto V_89;
}
switch ( V_122 ) {
case V_190 :
case V_192 :
case V_193 :
V_40 -> V_44 [ V_3 ] . V_131 = V_191 ;
break;
case V_194 :
case V_195 :
case V_196 :
V_40 -> V_44 [ V_3 ] . V_131 = V_186 ;
break;
}
V_89:
V_40 -> V_44 [ V_3 ] . V_159 = V_167 ;
return V_50 ;
}
static int F_103 ( struct V_26 * V_27 , int V_122 )
{
struct V_11 * V_40 = V_27 -> V_49 ;
int V_3 = V_27 -> V_3 ;
if ( V_40 -> V_44 [ V_3 ] . V_159 != V_167 ) {
V_40 -> V_44 [ V_3 ] . V_177 = V_122 + 1 ;
return 0 ;
}
return F_89 ( V_27 , V_122 ) ;
}
int F_104 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 ;
int V_50 = 0 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_140 =
F_64 ( V_45 , V_3 ) ;
if ( ! F_82 ( V_40 , V_45 , V_3 ) )
continue;
if ( ( V_45 -> V_44 [ V_3 ] . V_131 != V_183 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_186 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 != V_187 ) )
continue;
F_9 ( V_45 -> V_46 , L_82 ,
V_45 -> V_24 -> V_47 ) ;
V_50 = F_47 ( V_140 ) ;
if ( V_50 < 0 ) {
F_13 ( V_45 -> V_46 , L_83 ,
V_50 ) ;
break;
}
V_45 -> V_44 [ V_3 ] . V_131 = V_184 ;
}
return V_50 ;
}
static int F_105 ( struct V_26 * V_27 )
{
struct V_11 * V_40 = V_27 -> V_49 ;
int V_3 = V_27 -> V_3 , V_50 = 0 ;
F_33 ( & V_40 -> V_112 -> V_188 , V_189 ) ;
F_9 ( V_40 -> V_46 , L_84 , V_40 -> V_24 -> V_47 ) ;
F_87 ( V_40 , V_3 , V_180 ) ;
if ( F_106 ( & V_40 -> V_44 [ V_3 ] . V_134 ) ) {
F_13 ( V_40 -> V_46 , L_85 ,
V_40 -> V_24 -> V_47 ) ;
V_50 = - V_63 ;
goto V_89;
}
V_50 = F_104 ( V_40 , V_27 -> V_3 ) ;
if ( V_50 < 0 )
goto V_89;
V_50 = F_47 ( V_27 ) ;
if ( V_50 < 0 ) {
F_13 ( V_40 -> V_46 , L_86 ,
V_40 -> V_24 -> V_47 ) ;
goto V_89;
}
F_7 ( V_40 , V_3 , V_113 ) ;
V_40 -> V_44 [ V_3 ] . V_131 = V_184 ;
V_89:
F_87 ( V_40 , V_3 , V_167 ) ;
F_37 ( & V_40 -> V_112 -> V_188 ) ;
return V_50 ;
}
static int F_107 ( struct V_26 * V_27 ,
unsigned int V_122 , void * V_201 )
{
struct V_11 * V_12 = V_27 -> V_49 ;
struct V_83 * V_84 = V_12 -> V_84 ;
if ( V_84 -> V_7 -> V_87 && V_84 -> V_7 -> V_87 -> V_202 )
return V_84 -> V_7 -> V_87 -> V_202 ( V_27 , V_122 , V_201 ) ;
return F_108 ( V_27 , V_122 , V_201 ) ;
}
static int F_109 ( struct V_11 * V_40 , int V_3 )
{
struct V_26 * V_27 =
F_64 ( V_40 , V_3 ) ;
enum V_197 V_123 = V_40 -> V_24 -> V_123 [ V_3 ] ;
int V_162 ;
F_9 ( V_40 -> V_46 , L_87 ,
V_3 ? L_40 : L_41 , V_40 -> V_24 -> V_47 ) ;
if ( V_123 == V_200 ) {
F_9 ( V_40 -> V_46 , L_88 ,
V_40 -> V_24 -> V_47 ) ;
V_162 = F_56 ( V_27 , V_194 ) ;
if ( V_162 < 0 )
F_13 ( V_40 -> V_46 , L_78 , V_162 ) ;
} else {
F_9 ( V_40 -> V_46 , L_89 ,
V_40 -> V_24 -> V_47 ) ;
V_162 = F_102 ( V_40 , V_3 , V_194 ) ;
if ( V_162 < 0 )
F_13 ( V_40 -> V_46 , L_78 , V_162 ) ;
}
V_162 = F_95 ( V_40 , V_3 ) ;
if ( V_162 < 0 )
F_13 ( V_40 -> V_46 , L_90 , V_162 ) ;
V_162 = F_93 ( V_40 , V_3 ) ;
if ( V_162 < 0 )
F_13 ( V_40 -> V_46 , L_91 , V_162 ) ;
F_7 ( V_40 , V_3 , V_203 ) ;
return 0 ;
}
static int F_110 ( struct V_11 * V_40 , int V_3 )
{
struct V_26 * V_27 =
F_64 ( V_40 , V_3 ) ;
struct V_43 * V_44 ;
enum V_197 V_123 = V_40 -> V_24 -> V_123 [ V_3 ] ;
int V_50 ;
F_9 ( V_40 -> V_46 , L_92 ,
V_3 ? L_40 : L_41 , V_40 -> V_24 -> V_47 ) ;
if ( V_40 -> V_44 [ V_3 ] . V_131 == V_182 ||
V_40 -> V_44 [ V_3 ] . V_131 == V_169 )
return - V_63 ;
V_50 = F_81 ( V_40 , V_3 ) ;
if ( V_50 < 0 )
goto V_204;
if ( V_40 -> V_44 [ V_3 ] . V_131 == V_168 )
return 0 ;
V_50 = F_98 ( V_40 , V_3 ) ;
if ( V_50 < 0 )
goto V_102;
if ( V_40 -> V_44 [ V_3 ] . V_131 == V_183 )
return 0 ;
V_50 = F_104 ( V_40 , V_3 ) ;
if ( V_50 < 0 )
goto V_121;
F_7 ( V_40 , V_3 , V_203 ) ;
if ( V_40 -> V_44 [ V_3 ] . V_131 == V_184 ||
V_40 -> V_44 [ V_3 ] . V_131 == V_186 )
return 0 ;
if ( V_123 == V_200 ) {
F_9 ( V_40 -> V_46 , L_93 ,
V_40 -> V_24 -> V_47 ) ;
V_50 = F_56 ( V_27 , V_190 ) ;
if ( V_50 < 0 ) {
F_13 ( V_40 -> V_46 , L_94 , V_50 ) ;
goto V_121;
}
} else {
F_9 ( V_40 -> V_46 , L_95 ,
V_40 -> V_24 -> V_47 ) ;
V_50 = F_102 ( V_40 , V_3 ,
V_190 ) ;
if ( V_50 < 0 ) {
F_13 ( V_40 -> V_46 , L_78 , V_50 ) ;
goto V_121;
}
}
return 0 ;
V_121:
F_95 ( V_40 , V_3 ) ;
V_102:
F_93 ( V_40 , V_3 ) ;
V_204:
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
if ( V_45 -> V_44 [ V_3 ] . V_131 != V_191 )
V_44 -> V_131 = V_143 ;
}
return V_50 ;
}
static int F_111 ( struct V_11 * V_40 , int V_3 )
{
int V_50 ;
F_87 ( V_40 , V_3 , V_160 ) ;
V_50 = F_110 ( V_40 , V_3 ) ;
if ( V_50 < 0 )
F_13 ( V_40 -> V_46 , L_96 ) ;
F_87 ( V_40 , V_3 , V_167 ) ;
return V_50 ;
}
static int F_112 ( struct V_11 * V_40 , int V_3 )
{
int V_50 ;
F_87 ( V_40 , V_3 , V_160 ) ;
V_50 = F_109 ( V_40 , V_3 ) ;
if ( V_50 < 0 )
F_13 ( V_40 -> V_46 , L_97 ) ;
F_87 ( V_40 , V_3 , V_167 ) ;
return V_50 ;
}
int F_113 ( struct V_144 * V_112 )
{
struct V_11 * V_40 ;
int V_205 , V_161 , V_156 ;
F_33 ( & V_112 -> V_188 , V_189 ) ;
F_8 (fe, &card->rtd_list, list) {
struct V_149 * V_150 ;
if ( ! V_40 -> V_24 -> V_96 )
continue;
if ( ! V_40 -> V_13 -> V_20 )
continue;
F_9 ( V_40 -> V_46 , L_98 ,
V_40 -> V_24 -> V_47 ) ;
if ( ! V_40 -> V_13 -> V_7 -> V_8 . V_81
|| ! V_40 -> V_69 -> V_7 -> V_8 . V_81 )
goto V_9;
if ( ! V_40 -> V_13 -> V_16
|| ! V_40 -> V_69 -> V_16 )
goto V_9;
V_156 = F_74 ( V_40 , V_6 , & V_150 ) ;
if ( V_156 < 0 ) {
F_22 ( V_40 -> V_46 , L_99 ,
V_40 -> V_24 -> V_47 , L_41 ) ;
F_37 ( & V_112 -> V_188 ) ;
return V_156 ;
}
V_161 = F_78 ( V_40 , V_6 , & V_150 , 1 ) ;
if ( V_161 ) {
F_111 ( V_40 , V_6 ) ;
F_79 ( V_40 , V_6 ) ;
F_65 ( V_40 , V_6 ) ;
}
V_205 = F_78 ( V_40 , V_6 , & V_150 , 0 ) ;
if ( V_205 ) {
F_112 ( V_40 , V_6 ) ;
F_79 ( V_40 , V_6 ) ;
F_65 ( V_40 , V_6 ) ;
}
F_114 ( & V_150 ) ;
V_9:
if ( ! V_40 -> V_13 -> V_7 -> V_9 . V_81
|| ! V_40 -> V_69 -> V_7 -> V_9 . V_81 )
continue;
if ( ! V_40 -> V_13 -> V_19
|| ! V_40 -> V_69 -> V_19 )
continue;
V_156 = F_74 ( V_40 , V_110 , & V_150 ) ;
if ( V_156 < 0 ) {
F_22 ( V_40 -> V_46 , L_99 ,
V_40 -> V_24 -> V_47 , L_40 ) ;
F_37 ( & V_112 -> V_188 ) ;
return V_156 ;
}
V_161 = F_78 ( V_40 , V_110 , & V_150 , 1 ) ;
if ( V_161 ) {
F_111 ( V_40 , V_110 ) ;
F_79 ( V_40 , V_110 ) ;
F_65 ( V_40 , V_110 ) ;
}
V_205 = F_78 ( V_40 , V_110 , & V_150 , 0 ) ;
if ( V_205 ) {
F_112 ( V_40 , V_110 ) ;
F_79 ( V_40 , V_110 ) ;
F_65 ( V_40 , V_110 ) ;
}
F_114 ( & V_150 ) ;
}
F_37 ( & V_112 -> V_188 ) ;
return 0 ;
}
int F_115 ( struct V_11 * V_40 , int V_206 )
{
struct V_43 * V_44 ;
struct V_207 * V_208 =
& V_40 -> V_44 [ V_6 ] . V_134 ;
F_8 (dpcm, clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
int V_14 ;
if ( V_45 -> V_24 -> V_209 )
continue;
for ( V_14 = 0 ; V_14 < V_45 -> V_17 ; V_14 ++ ) {
struct V_1 * V_2 = V_45 -> V_18 [ V_14 ] ;
struct V_64 * V_210 = V_2 -> V_7 ;
F_9 ( V_45 -> V_46 , L_100 ,
V_45 -> V_24 -> V_47 ) ;
if ( V_210 -> V_87 && V_210 -> V_87 -> V_211 &&
V_2 -> V_16 )
V_210 -> V_87 -> V_211 ( V_2 , V_206 ) ;
}
}
return 0 ;
}
static int F_116 ( struct V_26 * V_139 )
{
struct V_11 * V_40 = V_139 -> V_49 ;
struct V_43 * V_44 ;
struct V_149 * V_150 ;
int V_50 ;
int V_3 = V_139 -> V_3 ;
F_33 ( & V_40 -> V_112 -> V_188 , V_189 ) ;
V_40 -> V_44 [ V_3 ] . V_31 = V_139 -> V_31 ;
V_50 = F_74 ( V_40 , V_3 , & V_150 ) ;
if ( V_50 < 0 ) {
F_37 ( & V_40 -> V_112 -> V_188 ) ;
return V_50 ;
} else if ( V_50 == 0 ) {
F_9 ( V_40 -> V_46 , L_101 ,
V_40 -> V_24 -> V_47 , V_3 ? L_40 : L_41 ) ;
}
F_78 ( V_40 , V_3 , & V_150 , 1 ) ;
V_50 = F_92 ( V_139 ) ;
if ( V_50 < 0 ) {
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_44 -> V_131 = V_143 ;
F_65 ( V_40 , V_3 ) ;
V_40 -> V_44 [ V_3 ] . V_31 = NULL ;
}
F_79 ( V_40 , V_3 ) ;
F_114 ( & V_150 ) ;
F_37 ( & V_40 -> V_112 -> V_188 ) ;
return V_50 ;
}
static int F_117 ( struct V_26 * V_139 )
{
struct V_11 * V_40 = V_139 -> V_49 ;
struct V_43 * V_44 ;
int V_3 = V_139 -> V_3 , V_50 ;
F_33 ( & V_40 -> V_112 -> V_188 , V_189 ) ;
V_50 = F_94 ( V_139 ) ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_44 -> V_131 = V_143 ;
F_65 ( V_40 , V_3 ) ;
V_40 -> V_44 [ V_3 ] . V_31 = NULL ;
F_37 ( & V_40 -> V_112 -> V_188 ) ;
return V_50 ;
}
int F_118 ( struct V_11 * V_12 , int V_212 )
{
struct V_83 * V_84 = V_12 -> V_84 ;
struct V_1 * V_69 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_213 * V_214 ;
char V_215 [ 64 ] ;
int V_50 = 0 , V_8 = 0 , V_9 = 0 ;
int V_14 ;
if ( V_12 -> V_24 -> V_96 || V_12 -> V_24 -> V_97 ) {
V_8 = V_12 -> V_24 -> V_216 ;
V_9 = V_12 -> V_24 -> V_217 ;
} else {
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_69 = V_12 -> V_18 [ V_14 ] ;
if ( V_69 -> V_7 -> V_8 . V_81 )
V_8 = 1 ;
if ( V_69 -> V_7 -> V_9 . V_81 )
V_9 = 1 ;
}
V_9 = V_9 && V_13 -> V_7 -> V_9 . V_81 ;
V_8 = V_8 && V_13 -> V_7 -> V_8 . V_81 ;
}
if ( V_12 -> V_24 -> V_218 ) {
V_8 = 1 ;
V_9 = 0 ;
}
if ( V_12 -> V_24 -> V_219 ) {
V_8 = 0 ;
V_9 = 1 ;
}
if ( V_12 -> V_24 -> V_97 ) {
snprintf ( V_215 , sizeof( V_215 ) , L_102 ,
V_12 -> V_24 -> V_106 ) ;
V_50 = F_119 ( V_12 -> V_112 -> V_220 , V_215 , V_212 ,
V_8 , V_9 , & V_214 ) ;
} else {
if ( V_12 -> V_24 -> V_96 )
snprintf ( V_215 , sizeof( V_215 ) , L_103 ,
V_12 -> V_24 -> V_106 ) ;
else
snprintf ( V_215 , sizeof( V_215 ) , L_104 ,
V_12 -> V_24 -> V_106 ,
( V_12 -> V_17 > 1 ) ?
L_12 : V_12 -> V_69 -> V_47 , V_212 ) ;
V_50 = F_120 ( V_12 -> V_112 -> V_220 , V_215 , V_212 , V_8 ,
V_9 , & V_214 ) ;
}
if ( V_50 < 0 ) {
F_13 ( V_12 -> V_112 -> V_46 , L_105 ,
V_12 -> V_24 -> V_47 ) ;
return V_50 ;
}
F_9 ( V_12 -> V_112 -> V_46 , L_106 , V_212 , V_215 ) ;
F_121 ( & V_12 -> V_105 , F_41 ) ;
V_214 -> V_221 = V_12 -> V_24 -> V_221 ;
V_12 -> V_214 = V_214 ;
V_214 -> V_49 = V_12 ;
if ( V_12 -> V_24 -> V_97 ) {
if ( V_8 )
V_214 -> V_222 [ V_6 ] . V_27 -> V_49 = V_12 ;
if ( V_9 )
V_214 -> V_222 [ V_110 ] . V_27 -> V_49 = V_12 ;
goto V_89;
}
if ( V_12 -> V_24 -> V_96 ) {
V_12 -> V_87 . V_90 = F_116 ;
V_12 -> V_87 . V_117 = F_100 ;
V_12 -> V_87 . V_111 = F_105 ;
V_12 -> V_87 . V_123 = F_103 ;
V_12 -> V_87 . V_121 = F_97 ;
V_12 -> V_87 . V_102 = F_117 ;
V_12 -> V_87 . V_128 = F_57 ;
V_12 -> V_87 . V_202 = F_107 ;
} else {
V_12 -> V_87 . V_90 = F_30 ;
V_12 -> V_87 . V_117 = F_53 ;
V_12 -> V_87 . V_111 = F_47 ;
V_12 -> V_87 . V_123 = F_55 ;
V_12 -> V_87 . V_121 = F_54 ;
V_12 -> V_87 . V_102 = F_43 ;
V_12 -> V_87 . V_128 = F_57 ;
V_12 -> V_87 . V_202 = F_107 ;
}
if ( V_84 -> V_7 -> V_87 ) {
V_12 -> V_87 . V_223 = V_84 -> V_7 -> V_87 -> V_223 ;
V_12 -> V_87 . V_224 = V_84 -> V_7 -> V_87 -> V_224 ;
V_12 -> V_87 . V_225 = V_84 -> V_7 -> V_87 -> V_225 ;
V_12 -> V_87 . V_226 = V_84 -> V_7 -> V_87 -> V_226 ;
V_12 -> V_87 . V_227 = V_84 -> V_7 -> V_87 -> V_227 ;
}
if ( V_8 )
F_122 ( V_214 , V_6 , & V_12 -> V_87 ) ;
if ( V_9 )
F_122 ( V_214 , V_110 , & V_12 -> V_87 ) ;
if ( V_84 -> V_7 -> V_228 ) {
V_50 = V_84 -> V_7 -> V_228 ( V_12 ) ;
if ( V_50 < 0 ) {
F_13 ( V_84 -> V_46 ,
L_107 ,
V_50 ) ;
return V_50 ;
}
}
V_214 -> V_229 = V_84 -> V_7 -> V_230 ;
V_89:
F_123 ( V_12 -> V_112 -> V_46 , L_108 ,
( V_12 -> V_17 > 1 ) ? L_12 : V_12 -> V_69 -> V_47 ,
V_13 -> V_47 ) ;
return V_50 ;
}
int F_124 ( struct V_11 * V_40 , int V_3 )
{
if ( V_40 -> V_44 [ V_3 ] . V_159 == V_180 )
return 1 ;
return 0 ;
}
int F_82 ( struct V_11 * V_40 ,
struct V_11 * V_45 , int V_3 )
{
if ( ( V_40 -> V_44 [ V_3 ] . V_159 == V_180 ) ||
( ( V_40 -> V_44 [ V_3 ] . V_159 == V_160 ) &&
V_45 -> V_44 [ V_3 ] . V_159 ) )
return 1 ;
return 0 ;
}
struct V_26 *
F_64 ( struct V_11 * V_45 , int V_3 )
{
return V_45 -> V_214 -> V_222 [ V_3 ] . V_27 ;
}
enum V_231
F_125 ( struct V_11 * V_45 , int V_3 )
{
return V_45 -> V_44 [ V_3 ] . V_131 ;
}
void F_126 ( struct V_11 * V_45 ,
int V_3 , enum V_231 V_131 )
{
V_45 -> V_44 [ V_3 ] . V_131 = V_131 ;
}
int F_96 ( struct V_11 * V_40 ,
struct V_11 * V_45 , int V_3 )
{
struct V_43 * V_44 ;
int V_131 ;
F_8 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_44 -> V_40 == V_40 )
continue;
V_131 = V_44 -> V_40 -> V_44 [ V_3 ] . V_131 ;
if ( V_131 == V_191 ||
V_131 == V_185 ||
V_131 == V_187 )
return 0 ;
}
return 1 ;
}
int F_99 ( struct V_11 * V_40 ,
struct V_11 * V_45 , int V_3 )
{
struct V_43 * V_44 ;
int V_131 ;
F_8 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_44 -> V_40 == V_40 )
continue;
V_131 = V_44 -> V_40 -> V_44 [ V_3 ] . V_131 ;
if ( V_131 == V_191 ||
V_131 == V_185 ||
V_131 == V_187 ||
V_131 == V_184 )
return 0 ;
}
return 1 ;
}
int F_127 ( struct V_26 * V_27 ,
int V_122 , struct V_83 * V_84 )
{
if ( V_84 -> V_7 -> V_87 && V_84 -> V_7 -> V_87 -> V_123 )
return V_84 -> V_7 -> V_87 -> V_123 ( V_27 , V_122 ) ;
return 0 ;
}
static char * F_128 ( enum V_231 V_131 )
{
switch ( V_131 ) {
case V_172 :
return L_109 ;
case V_168 :
return L_110 ;
case V_183 :
return L_111 ;
case V_184 :
return L_112 ;
case V_191 :
return L_113 ;
case V_186 :
return L_114 ;
case V_187 :
return L_115 ;
case V_185 :
return L_116 ;
case V_182 :
return L_117 ;
case V_169 :
return L_118 ;
}
return L_119 ;
}
static T_4 F_129 ( struct V_11 * V_40 ,
int V_3 , char * V_232 , T_5 V_233 )
{
struct V_60 * V_61 = & V_40 -> V_44 [ V_3 ] . V_117 ;
struct V_43 * V_44 ;
T_4 V_125 = 0 ;
V_125 += snprintf ( V_232 + V_125 , V_233 - V_125 ,
L_120 , V_40 -> V_24 -> V_47 ,
V_3 ? L_121 : L_122 ) ;
V_125 += snprintf ( V_232 + V_125 , V_233 - V_125 , L_123 ,
F_128 ( V_40 -> V_44 [ V_3 ] . V_131 ) ) ;
if ( ( V_40 -> V_44 [ V_3 ] . V_131 >= V_183 ) &&
( V_40 -> V_44 [ V_3 ] . V_131 <= V_186 ) )
V_125 += snprintf ( V_232 + V_125 , V_233 - V_125 ,
L_124
L_125 ,
F_130 ( F_18 ( V_61 ) ) ,
F_16 ( V_61 ) ,
F_15 ( V_61 ) ) ;
V_125 += snprintf ( V_232 + V_125 , V_233 - V_125 , L_126 ) ;
if ( F_106 ( & V_40 -> V_44 [ V_3 ] . V_134 ) ) {
V_125 += snprintf ( V_232 + V_125 , V_233 - V_125 ,
L_127 ) ;
goto V_89;
}
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
V_61 = & V_44 -> V_117 ;
V_125 += snprintf ( V_232 + V_125 , V_233 - V_125 ,
L_128 , V_45 -> V_24 -> V_47 ) ;
V_125 += snprintf ( V_232 + V_125 , V_233 - V_125 ,
L_129 ,
F_128 ( V_45 -> V_44 [ V_3 ] . V_131 ) ) ;
if ( ( V_45 -> V_44 [ V_3 ] . V_131 >= V_183 ) &&
( V_45 -> V_44 [ V_3 ] . V_131 <= V_186 ) )
V_125 += snprintf ( V_232 + V_125 , V_233 - V_125 ,
L_130
L_125 ,
F_130 ( F_18 ( V_61 ) ) ,
F_16 ( V_61 ) ,
F_15 ( V_61 ) ) ;
}
V_89:
return V_125 ;
}
static T_4 F_131 ( struct V_234 * V_234 , char T_6 * V_235 ,
T_5 V_170 , T_7 * V_236 )
{
struct V_11 * V_40 = V_234 -> V_49 ;
T_4 V_237 = V_238 , V_125 = 0 , V_50 = 0 ;
char * V_232 ;
V_232 = F_132 ( V_237 , V_129 ) ;
if ( ! V_232 )
return - V_130 ;
if ( V_40 -> V_13 -> V_7 -> V_8 . V_81 )
V_125 += F_129 ( V_40 , V_6 ,
V_232 + V_125 , V_237 - V_125 ) ;
if ( V_40 -> V_13 -> V_7 -> V_9 . V_81 )
V_125 += F_129 ( V_40 , V_110 ,
V_232 + V_125 , V_237 - V_125 ) ;
V_50 = F_133 ( V_235 , V_170 , V_236 , V_232 , V_125 ) ;
F_69 ( V_232 ) ;
return V_50 ;
}
void F_134 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_24 )
return;
if ( ! V_12 -> V_112 -> V_239 )
return;
V_12 -> V_137 = F_135 ( V_12 -> V_24 -> V_47 ,
V_12 -> V_112 -> V_239 ) ;
if ( ! V_12 -> V_137 ) {
F_9 ( V_12 -> V_46 ,
L_131 ,
V_12 -> V_24 -> V_47 ) ;
return;
}
V_12 -> V_240 = F_136 ( L_132 , 0444 ,
V_12 -> V_137 ,
V_12 , & V_241 ) ;
}
