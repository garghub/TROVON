void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
F_2 ( & V_2 -> V_7 ) ;
if ( V_3 == V_8 ) {
V_5 -> V_9 ++ ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
V_2 -> V_11 [ V_6 ] -> V_9 ++ ;
} else {
V_5 -> V_12 ++ ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
V_2 -> V_11 [ V_6 ] -> V_12 ++ ;
}
V_5 -> V_13 ++ ;
V_5 -> V_14 -> V_13 ++ ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_2 -> V_11 [ V_6 ] -> V_13 ++ ;
V_2 -> V_11 [ V_6 ] -> V_14 -> V_13 ++ ;
}
}
void F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
F_2 ( & V_2 -> V_7 ) ;
if ( V_3 == V_8 ) {
V_5 -> V_9 -- ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
V_2 -> V_11 [ V_6 ] -> V_9 -- ;
} else {
V_5 -> V_12 -- ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
V_2 -> V_11 [ V_6 ] -> V_12 -- ;
}
V_5 -> V_13 -- ;
V_5 -> V_14 -> V_13 -- ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_2 -> V_11 [ V_6 ] -> V_14 -> V_13 -- ;
V_2 -> V_11 [ V_6 ] -> V_13 -- ;
}
}
bool F_4 ( struct V_1 * V_2 )
{
int V_6 ;
bool V_15 = true ;
if ( ! V_2 -> V_16 || V_2 -> V_17 -> V_18 )
return true ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
V_15 &= V_2 -> V_11 [ V_6 ] -> V_14 -> V_18 ;
return V_2 -> V_5 -> V_14 -> V_18 && V_15 ;
}
int F_5 ( struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_23 * V_24 = V_20 -> V_24 ;
V_24 -> V_22 . V_25 = V_22 -> V_25 ;
V_24 -> V_22 . V_26 = V_22 -> V_26 ;
V_24 -> V_22 . V_27 = V_22 -> V_27 ;
V_24 -> V_22 . V_28 = V_22 -> V_28 ;
V_24 -> V_22 . V_29 = V_22 -> V_29 ;
V_24 -> V_22 . V_30 = V_22 -> V_30 ;
V_24 -> V_22 . V_31 = V_22 -> V_31 ;
V_24 -> V_22 . V_32 = V_22 -> V_32 ;
return 0 ;
}
int F_6 ( struct V_1 * V_33 , int V_34 ,
int V_35 )
{
struct V_36 * V_37 ;
F_7 (dpcm, &fe->dpcm[dir].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
F_8 ( V_38 -> V_39 , L_1 ,
V_38 -> V_17 -> V_40 , V_35 , V_34 ) ;
F_9 ( V_38 , V_34 , V_35 ) ;
}
F_9 ( V_33 , V_34 , V_35 ) ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 ,
struct V_4 * V_41 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
int V_43 ;
if ( V_41 -> V_44 && ( V_41 -> V_45 -> V_46 ||
V_2 -> V_17 -> V_46 ) ) {
F_8 ( V_41 -> V_39 , L_2 ,
V_41 -> V_44 ) ;
V_43 = F_11 ( V_20 -> V_24 ,
V_47 ,
V_41 -> V_44 , V_41 -> V_44 ) ;
if ( V_43 < 0 ) {
F_12 ( V_41 -> V_39 ,
L_3 ,
V_43 ) ;
return V_43 ;
}
}
if ( V_41 -> V_48 && ( V_41 -> V_45 -> V_49 ||
V_2 -> V_17 -> V_49 ) ) {
F_8 ( V_41 -> V_39 , L_4 ,
V_41 -> V_48 ) ;
V_43 = F_11 ( V_20 -> V_24 ,
V_50 ,
V_41 -> V_48 ,
V_41 -> V_48 ) ;
if ( V_43 < 0 ) {
F_12 ( V_41 -> V_39 ,
L_5 ,
V_43 ) ;
return V_43 ;
}
}
if ( V_41 -> V_51 && ( V_41 -> V_45 -> V_52 ||
V_2 -> V_17 -> V_52 ) ) {
F_8 ( V_41 -> V_39 , L_6 ,
V_41 -> V_51 ) ;
V_43 = F_11 ( V_20 -> V_24 ,
V_53 ,
V_41 -> V_51 ,
V_41 -> V_51 ) ;
if ( V_43 < 0 ) {
F_12 ( V_41 -> V_39 ,
L_7 ,
V_43 ) ;
return V_43 ;
}
}
return 0 ;
}
static int F_13 ( struct V_19 * V_20 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_44 , V_48 , V_51 , V_56 , V_6 ;
V_44 = F_14 ( V_55 ) ;
V_48 = F_15 ( V_55 ) ;
V_51 = F_16 ( F_17 ( V_55 ) ) ;
V_56 = V_5 -> V_45 -> V_46 ||
V_2 -> V_17 -> V_46 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
V_56 |= V_2 -> V_11 [ V_6 ] -> V_45 -> V_46 ;
if ( V_56 && V_5 -> V_44 && V_5 -> V_44 != V_44 ) {
F_12 ( V_2 -> V_39 , L_8 ,
V_5 -> V_44 , V_44 ) ;
return - V_57 ;
}
V_56 = V_5 -> V_45 -> V_49 ||
V_2 -> V_17 -> V_49 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
V_56 |= V_2 -> V_11 [ V_6 ] -> V_45 -> V_49 ;
if ( V_56 && V_5 -> V_48 && V_5 -> V_48 != V_48 ) {
F_12 ( V_2 -> V_39 , L_9 ,
V_5 -> V_48 , V_48 ) ;
return - V_57 ;
}
V_56 = V_5 -> V_45 -> V_52 ||
V_2 -> V_17 -> V_52 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
V_56 |= V_2 -> V_11 [ V_6 ] -> V_45 -> V_52 ;
if ( V_56 && V_5 -> V_51 && V_5 -> V_51 != V_51 ) {
F_12 ( V_2 -> V_39 , L_10 ,
V_5 -> V_51 , V_51 ) ;
return - V_57 ;
}
return 0 ;
}
static bool F_18 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_58 * V_59 = V_2 -> V_5 -> V_45 ;
struct V_60 * V_61 = V_2 -> V_17 ;
unsigned int V_56 , V_6 ;
V_56 = V_59 -> V_46 || V_61 -> V_46 ||
V_59 -> V_49 || V_61 -> V_49 ||
V_59 -> V_52 || V_61 -> V_52 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
V_56 = V_56 ||
V_2 -> V_11 [ V_6 ] -> V_45 -> V_46 ||
V_2 -> V_11 [ V_6 ] -> V_45 -> V_49 ||
V_2 -> V_11 [ V_6 ] -> V_45 -> V_52 ;
return V_56 ;
}
static void F_19 ( struct V_19 * V_20 , int V_62 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
int V_43 ;
if ( ! V_62 )
return;
V_43 = F_20 ( V_20 -> V_24 , 0 , 0 , V_62 ) ;
if ( V_43 != 0 )
F_21 ( V_2 -> V_39 , L_11 ,
V_62 , V_43 ) ;
}
static void F_22 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_63 ;
int V_6 ;
unsigned int V_62 = 0 , V_64 ;
if ( V_20 -> V_3 == V_8 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_63 = V_2 -> V_11 [ V_6 ] ;
if ( V_63 -> V_45 -> V_65 . V_66 == 0 ) {
V_62 = 0 ;
break;
}
V_62 = F_23 ( V_63 -> V_45 -> V_65 . V_66 , V_62 ) ;
}
V_64 = V_5 -> V_45 -> V_65 . V_66 ;
} else {
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_63 = V_2 -> V_11 [ V_6 ] ;
if ( V_63 -> V_45 -> V_67 . V_66 == 0 ) {
V_62 = 0 ;
break;
}
V_62 = F_23 ( V_63 -> V_45 -> V_67 . V_66 , V_62 ) ;
}
V_64 = V_5 -> V_45 -> V_67 . V_66 ;
}
F_19 ( V_20 , V_62 ) ;
F_19 ( V_20 , V_64 ) ;
}
static void F_24 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = V_20 -> V_24 ;
struct V_21 * V_22 = & V_24 -> V_22 ;
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_58 * V_68 = V_2 -> V_5 -> V_45 ;
struct V_58 * V_69 ;
struct V_70 * V_71 ;
struct V_70 * V_72 ;
unsigned int V_73 = 0 , V_74 = V_75 ;
unsigned int V_76 = 0 , V_77 = V_75 ;
unsigned int V_78 = V_75 ;
T_1 V_26 = V_79 ;
int V_6 ;
if ( V_20 -> V_3 == V_8 )
V_72 = & V_68 -> V_65 ;
else
V_72 = & V_68 -> V_67 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_69 = V_2 -> V_11 [ V_6 ] -> V_45 ;
if ( V_20 -> V_3 == V_8 )
V_71 = & V_69 -> V_65 ;
else
V_71 = & V_69 -> V_67 ;
V_73 = F_23 ( V_73 , V_71 -> V_80 ) ;
V_74 = F_25 ( V_74 , V_71 -> V_81 ) ;
V_76 = F_23 ( V_76 , V_71 -> V_76 ) ;
V_77 = F_26 ( V_77 , V_71 -> V_77 ) ;
V_26 &= V_71 -> V_26 ;
V_78 = F_27 ( V_71 -> V_78 , V_78 ) ;
}
if ( V_2 -> V_10 > 1 ) {
V_73 = V_72 -> V_80 ;
V_74 = V_72 -> V_81 ;
}
V_22 -> V_80 = F_23 ( V_73 , V_72 -> V_80 ) ;
V_22 -> V_81 = F_25 ( V_74 , V_72 -> V_81 ) ;
if ( V_22 -> V_26 )
V_22 -> V_26 &= V_26 & V_72 -> V_26 ;
else
V_22 -> V_26 = V_26 & V_72 -> V_26 ;
V_22 -> V_78 = F_27 ( V_78 , V_72 -> V_78 ) ;
F_28 ( V_24 ) ;
V_22 -> V_76 = F_23 ( V_22 -> V_76 , V_72 -> V_76 ) ;
V_22 -> V_76 = F_23 ( V_22 -> V_76 , V_76 ) ;
V_22 -> V_77 = F_26 ( V_22 -> V_77 , V_72 -> V_77 ) ;
V_22 -> V_77 = F_26 ( V_22 -> V_77 , V_77 ) ;
}
static int F_29 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_23 * V_24 = V_20 -> V_24 ;
struct V_82 * V_83 = V_2 -> V_83 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_63 ;
const char * V_84 = L_12 ;
int V_6 , V_43 = 0 ;
F_30 ( V_5 -> V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
F_30 ( V_2 -> V_11 [ V_6 ] -> V_39 ) ;
F_31 ( V_5 -> V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
F_31 ( V_2 -> V_11 [ V_6 ] -> V_39 ) ;
F_31 ( V_83 -> V_39 ) ;
F_32 ( & V_2 -> V_7 , V_2 -> V_85 ) ;
if ( V_5 -> V_45 -> V_86 && V_5 -> V_45 -> V_86 -> V_87 ) {
V_43 = V_5 -> V_45 -> V_86 -> V_87 ( V_20 , V_5 ) ;
if ( V_43 < 0 ) {
F_12 ( V_5 -> V_39 , L_13
L_14 , V_5 -> V_40 , V_43 ) ;
goto V_88;
}
}
if ( V_83 -> V_45 -> V_86 && V_83 -> V_45 -> V_86 -> V_89 ) {
V_43 = V_83 -> V_45 -> V_86 -> V_89 ( V_20 ) ;
if ( V_43 < 0 ) {
F_12 ( V_83 -> V_39 , L_15
L_14 , V_83 -> V_14 . V_40 , V_43 ) ;
goto V_90;
}
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_63 = V_2 -> V_11 [ V_6 ] ;
if ( V_63 -> V_45 -> V_86 && V_63 -> V_45 -> V_86 -> V_87 ) {
V_43 = V_63 -> V_45 -> V_86 -> V_87 ( V_20 ,
V_63 ) ;
if ( V_43 < 0 ) {
F_12 ( V_63 -> V_39 ,
L_16 ,
V_63 -> V_40 , V_43 ) ;
goto V_91;
}
}
if ( V_20 -> V_3 == V_8 )
V_63 -> V_92 = 0 ;
else
V_63 -> V_93 = 0 ;
}
if ( V_2 -> V_17 -> V_86 && V_2 -> V_17 -> V_86 -> V_87 ) {
V_43 = V_2 -> V_17 -> V_86 -> V_87 ( V_20 ) ;
if ( V_43 < 0 ) {
F_33 ( L_17 ,
V_2 -> V_17 -> V_40 , V_43 ) ;
goto V_94;
}
}
if ( V_2 -> V_17 -> V_95 || V_2 -> V_17 -> V_96 )
goto V_95;
F_24 ( V_20 ) ;
if ( V_2 -> V_10 == 1 )
V_84 = V_2 -> V_63 -> V_40 ;
if ( F_18 ( V_20 ) )
V_24 -> V_22 . V_25 |= V_97 ;
V_43 = - V_57 ;
if ( ! V_24 -> V_22 . V_78 ) {
F_34 ( V_98 L_18 ,
V_84 , V_5 -> V_40 ) ;
goto V_99;
}
if ( ! V_24 -> V_22 . V_26 ) {
F_34 ( V_98 L_19 ,
V_84 , V_5 -> V_40 ) ;
goto V_99;
}
if ( ! V_24 -> V_22 . V_80 || ! V_24 -> V_22 . V_81 ||
V_24 -> V_22 . V_80 > V_24 -> V_22 . V_81 ) {
F_34 ( V_98 L_20 ,
V_84 , V_5 -> V_40 ) ;
goto V_99;
}
F_22 ( V_20 ) ;
if ( V_5 -> V_13 ) {
V_43 = F_10 ( V_20 , V_5 ) ;
if ( V_43 != 0 )
goto V_99;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
if ( V_2 -> V_11 [ V_6 ] -> V_13 ) {
V_43 = F_10 ( V_20 ,
V_2 -> V_11 [ V_6 ] ) ;
if ( V_43 != 0 )
goto V_99;
}
}
F_35 ( L_21 ,
V_84 , V_5 -> V_40 ) ;
F_35 ( L_22 , V_24 -> V_22 . V_78 ) ;
F_35 ( L_23 , V_24 -> V_22 . V_80 ,
V_24 -> V_22 . V_81 ) ;
F_35 ( L_24 , V_24 -> V_22 . V_76 ,
V_24 -> V_22 . V_77 ) ;
V_95:
F_1 ( V_2 , V_20 -> V_3 ) ;
F_36 ( & V_2 -> V_7 ) ;
return 0 ;
V_99:
if ( V_2 -> V_17 -> V_86 && V_2 -> V_17 -> V_86 -> V_100 )
V_2 -> V_17 -> V_86 -> V_100 ( V_20 ) ;
V_94:
V_6 = V_2 -> V_10 ;
V_91:
while ( -- V_6 >= 0 ) {
V_63 = V_2 -> V_11 [ V_6 ] ;
if ( V_63 -> V_45 -> V_86 -> V_100 )
V_63 -> V_45 -> V_86 -> V_100 ( V_20 , V_63 ) ;
}
if ( V_83 -> V_45 -> V_86 && V_83 -> V_45 -> V_86 -> V_101 )
V_83 -> V_45 -> V_86 -> V_101 ( V_20 ) ;
V_90:
if ( V_5 -> V_45 -> V_86 -> V_100 )
V_5 -> V_45 -> V_86 -> V_100 ( V_20 , V_5 ) ;
V_88:
F_36 ( & V_2 -> V_7 ) ;
F_37 ( V_83 -> V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
F_37 ( V_2 -> V_11 [ V_6 ] -> V_39 ) ;
F_37 ( V_5 -> V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
if ( ! V_2 -> V_11 [ V_6 ] -> V_13 )
F_38 ( V_2 -> V_11 [ V_6 ] -> V_39 ) ;
}
if ( ! V_5 -> V_13 )
F_38 ( V_5 -> V_39 ) ;
return V_43 ;
}
static void F_39 ( struct V_102 * V_103 )
{
struct V_1 * V_2 =
F_40 ( V_103 , struct V_1 , V_104 . V_103 ) ;
struct V_4 * V_63 = V_2 -> V_11 [ 0 ] ;
F_32 ( & V_2 -> V_7 , V_2 -> V_85 ) ;
F_8 ( V_2 -> V_39 , L_25 ,
V_63 -> V_45 -> V_65 . V_105 ,
V_63 -> V_9 ? L_26 : L_27 ,
V_2 -> V_106 ? L_28 : L_29 ) ;
if ( V_2 -> V_106 == 1 ) {
V_2 -> V_106 = 0 ;
F_9 ( V_2 , V_8 ,
V_107 ) ;
}
F_36 ( & V_2 -> V_7 ) ;
}
static int F_41 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_82 * V_83 = V_2 -> V_83 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_63 ;
int V_6 ;
F_32 ( & V_2 -> V_7 , V_2 -> V_85 ) ;
F_3 ( V_2 , V_20 -> V_3 ) ;
if ( ! V_5 -> V_13 )
V_5 -> V_44 = 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_63 = V_2 -> V_11 [ V_6 ] ;
if ( ! V_63 -> V_13 )
V_63 -> V_44 = 0 ;
}
F_42 ( V_5 , 1 , V_20 -> V_3 ) ;
if ( V_5 -> V_45 -> V_86 -> V_100 )
V_5 -> V_45 -> V_86 -> V_100 ( V_20 , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_63 = V_2 -> V_11 [ V_6 ] ;
if ( V_63 -> V_45 -> V_86 -> V_100 )
V_63 -> V_45 -> V_86 -> V_100 ( V_20 , V_63 ) ;
}
if ( V_2 -> V_17 -> V_86 && V_2 -> V_17 -> V_86 -> V_100 )
V_2 -> V_17 -> V_86 -> V_100 ( V_20 ) ;
if ( V_83 -> V_45 -> V_86 && V_83 -> V_45 -> V_86 -> V_101 )
V_83 -> V_45 -> V_86 -> V_101 ( V_20 ) ;
if ( V_20 -> V_3 == V_8 ) {
if ( F_4 ( V_2 ) ) {
F_9 ( V_2 ,
V_8 ,
V_107 ) ;
} else {
V_2 -> V_106 = 1 ;
F_43 ( V_108 ,
& V_2 -> V_104 ,
F_44 ( V_2 -> V_16 ) ) ;
}
} else {
F_9 ( V_2 , V_109 ,
V_107 ) ;
}
F_36 ( & V_2 -> V_7 ) ;
F_37 ( V_83 -> V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
F_37 ( V_2 -> V_11 [ V_6 ] -> V_39 ) ;
F_37 ( V_5 -> V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
if ( ! V_2 -> V_11 [ V_6 ] -> V_13 )
F_38 ( V_2 -> V_11 [ V_6 ] -> V_39 ) ;
}
if ( ! V_5 -> V_13 )
F_38 ( V_5 -> V_39 ) ;
return 0 ;
}
static int F_45 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_82 * V_83 = V_2 -> V_83 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_63 ;
int V_6 , V_43 = 0 ;
F_32 ( & V_2 -> V_7 , V_2 -> V_85 ) ;
if ( V_2 -> V_17 -> V_86 && V_2 -> V_17 -> V_86 -> V_110 ) {
V_43 = V_2 -> V_17 -> V_86 -> V_110 ( V_20 ) ;
if ( V_43 < 0 ) {
F_12 ( V_2 -> V_111 -> V_39 , L_30
L_31 , V_43 ) ;
goto V_88;
}
}
if ( V_83 -> V_45 -> V_86 && V_83 -> V_45 -> V_86 -> V_110 ) {
V_43 = V_83 -> V_45 -> V_86 -> V_110 ( V_20 ) ;
if ( V_43 < 0 ) {
F_12 ( V_83 -> V_39 , L_32
L_31 , V_43 ) ;
goto V_88;
}
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_63 = V_2 -> V_11 [ V_6 ] ;
if ( V_63 -> V_45 -> V_86 && V_63 -> V_45 -> V_86 -> V_110 ) {
V_43 = V_63 -> V_45 -> V_86 -> V_110 ( V_20 ,
V_63 ) ;
if ( V_43 < 0 ) {
F_12 ( V_63 -> V_39 ,
L_33 ,
V_43 ) ;
goto V_88;
}
}
}
if ( V_5 -> V_45 -> V_86 && V_5 -> V_45 -> V_86 -> V_110 ) {
V_43 = V_5 -> V_45 -> V_86 -> V_110 ( V_20 , V_5 ) ;
if ( V_43 < 0 ) {
F_12 ( V_5 -> V_39 ,
L_34 , V_43 ) ;
goto V_88;
}
}
if ( V_20 -> V_3 == V_8 &&
V_2 -> V_106 ) {
V_2 -> V_106 = 0 ;
F_46 ( & V_2 -> V_104 ) ;
}
F_9 ( V_2 , V_20 -> V_3 ,
V_112 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
F_42 ( V_2 -> V_11 [ V_6 ] , 0 ,
V_20 -> V_3 ) ;
F_42 ( V_5 , 0 , V_20 -> V_3 ) ;
V_88:
F_36 ( & V_2 -> V_7 ) ;
return V_43 ;
}
static void F_47 ( struct V_54 * V_55 ,
unsigned int V_113 )
{
struct V_114 * V_115 ;
int V_48 = F_48 ( V_113 ) ;
V_115 = F_49 ( V_55 , V_50 ) ;
V_115 -> F_25 = V_48 ;
V_115 -> F_23 = V_48 ;
}
int F_50 ( struct V_19 * V_20 ,
struct V_54 * V_55 ,
struct V_4 * V_116 )
{
int V_43 ;
if ( V_116 -> V_45 -> V_86 && V_116 -> V_45 -> V_86 -> V_117 ) {
V_43 = V_116 -> V_45 -> V_86 -> V_117 ( V_20 , V_55 , V_116 ) ;
if ( V_43 < 0 ) {
F_12 ( V_116 -> V_39 , L_35 ,
V_116 -> V_40 , V_43 ) ;
return V_43 ;
}
}
return 0 ;
}
static int F_51 ( struct V_19 * V_20 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_82 * V_83 = V_2 -> V_83 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 , V_43 = 0 ;
F_32 ( & V_2 -> V_7 , V_2 -> V_85 ) ;
V_43 = F_13 ( V_20 , V_55 ) ;
if ( V_43 )
goto V_88;
if ( V_2 -> V_17 -> V_86 && V_2 -> V_17 -> V_86 -> V_117 ) {
V_43 = V_2 -> V_17 -> V_86 -> V_117 ( V_20 , V_55 ) ;
if ( V_43 < 0 ) {
F_12 ( V_2 -> V_111 -> V_39 , L_36
L_37 , V_43 ) ;
goto V_88;
}
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
struct V_4 * V_63 = V_2 -> V_11 [ V_6 ] ;
struct V_54 V_118 ;
V_118 = * V_55 ;
if ( V_63 -> V_92 )
F_47 ( & V_118 ,
V_63 -> V_92 ) ;
if ( V_63 -> V_93 )
F_47 ( & V_118 ,
V_63 -> V_93 ) ;
V_43 = F_50 ( V_20 , & V_118 , V_63 ) ;
if( V_43 < 0 )
goto V_119;
V_63 -> V_44 = F_14 ( & V_118 ) ;
V_63 -> V_48 = F_15 ( & V_118 ) ;
V_63 -> V_51 = F_16 (
F_17 ( & V_118 ) ) ;
}
V_43 = F_50 ( V_20 , V_55 , V_5 ) ;
if ( V_43 < 0 )
goto V_120;
if ( V_83 -> V_45 -> V_86 && V_83 -> V_45 -> V_86 -> V_117 ) {
V_43 = V_83 -> V_45 -> V_86 -> V_117 ( V_20 , V_55 ) ;
if ( V_43 < 0 ) {
F_12 ( V_83 -> V_39 , L_38 ,
V_83 -> V_14 . V_40 , V_43 ) ;
goto V_90;
}
}
V_5 -> V_44 = F_14 ( V_55 ) ;
V_5 -> V_48 = F_15 ( V_55 ) ;
V_5 -> V_51 =
F_16 ( F_17 ( V_55 ) ) ;
V_88:
F_36 ( & V_2 -> V_7 ) ;
return V_43 ;
V_90:
if ( V_5 -> V_45 -> V_86 && V_5 -> V_45 -> V_86 -> V_121 )
V_5 -> V_45 -> V_86 -> V_121 ( V_20 , V_5 ) ;
V_120:
V_6 = V_2 -> V_10 ;
V_119:
while ( -- V_6 >= 0 ) {
struct V_4 * V_63 = V_2 -> V_11 [ V_6 ] ;
if ( V_63 -> V_45 -> V_86 && V_63 -> V_45 -> V_86 -> V_121 )
V_63 -> V_45 -> V_86 -> V_121 ( V_20 , V_63 ) ;
V_63 -> V_44 = 0 ;
}
if ( V_2 -> V_17 -> V_86 && V_2 -> V_17 -> V_86 -> V_121 )
V_2 -> V_17 -> V_86 -> V_121 ( V_20 ) ;
F_36 ( & V_2 -> V_7 ) ;
return V_43 ;
}
static int F_52 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_82 * V_83 = V_2 -> V_83 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_63 ;
bool V_65 = V_20 -> V_3 == V_8 ;
int V_6 ;
F_32 ( & V_2 -> V_7 , V_2 -> V_85 ) ;
if ( V_5 -> V_13 == 1 ) {
V_5 -> V_44 = 0 ;
V_5 -> V_48 = 0 ;
V_5 -> V_51 = 0 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_63 = V_2 -> V_11 [ V_6 ] ;
if ( V_63 -> V_13 == 1 ) {
V_63 -> V_44 = 0 ;
V_63 -> V_48 = 0 ;
V_63 -> V_51 = 0 ;
}
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
if ( ( V_65 && V_2 -> V_11 [ V_6 ] -> V_9 == 1 ) ||
( ! V_65 && V_2 -> V_11 [ V_6 ] -> V_12 == 1 ) )
F_42 ( V_2 -> V_11 [ V_6 ] , 1 ,
V_20 -> V_3 ) ;
}
if ( V_2 -> V_17 -> V_86 && V_2 -> V_17 -> V_86 -> V_121 )
V_2 -> V_17 -> V_86 -> V_121 ( V_20 ) ;
if ( V_83 -> V_45 -> V_86 && V_83 -> V_45 -> V_86 -> V_121 )
V_83 -> V_45 -> V_86 -> V_121 ( V_20 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_63 = V_2 -> V_11 [ V_6 ] ;
if ( V_63 -> V_45 -> V_86 && V_63 -> V_45 -> V_86 -> V_121 )
V_63 -> V_45 -> V_86 -> V_121 ( V_20 , V_63 ) ;
}
if ( V_5 -> V_45 -> V_86 && V_5 -> V_45 -> V_86 -> V_121 )
V_5 -> V_45 -> V_86 -> V_121 ( V_20 , V_5 ) ;
F_36 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_53 ( struct V_19 * V_20 , int V_122 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_82 * V_83 = V_2 -> V_83 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_63 ;
int V_6 , V_43 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_63 = V_2 -> V_11 [ V_6 ] ;
if ( V_63 -> V_45 -> V_86 && V_63 -> V_45 -> V_86 -> V_123 ) {
V_43 = V_63 -> V_45 -> V_86 -> V_123 ( V_20 ,
V_122 , V_63 ) ;
if ( V_43 < 0 )
return V_43 ;
}
}
if ( V_83 -> V_45 -> V_86 && V_83 -> V_45 -> V_86 -> V_123 ) {
V_43 = V_83 -> V_45 -> V_86 -> V_123 ( V_20 , V_122 ) ;
if ( V_43 < 0 )
return V_43 ;
}
if ( V_5 -> V_45 -> V_86 && V_5 -> V_45 -> V_86 -> V_123 ) {
V_43 = V_5 -> V_45 -> V_86 -> V_123 ( V_20 , V_122 , V_5 ) ;
if ( V_43 < 0 )
return V_43 ;
}
if ( V_2 -> V_17 -> V_86 && V_2 -> V_17 -> V_86 -> V_123 ) {
V_43 = V_2 -> V_17 -> V_86 -> V_123 ( V_20 , V_122 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return 0 ;
}
static int F_54 ( struct V_19 * V_20 ,
int V_122 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_82 * V_83 = V_2 -> V_83 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_63 ;
int V_6 , V_43 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_63 = V_2 -> V_11 [ V_6 ] ;
if ( V_63 -> V_45 -> V_86 &&
V_63 -> V_45 -> V_86 -> V_124 ) {
V_43 = V_63 -> V_45 -> V_86 -> V_124 ( V_20 ,
V_122 , V_63 ) ;
if ( V_43 < 0 )
return V_43 ;
}
}
if ( V_83 -> V_45 -> V_124 ) {
V_43 = V_83 -> V_45 -> V_124 ( V_20 , V_122 ) ;
if ( V_43 < 0 )
return V_43 ;
}
if ( V_5 -> V_45 -> V_86 && V_5 -> V_45 -> V_86 -> V_124 ) {
V_43 = V_5 -> V_45 -> V_86 -> V_124 ( V_20 , V_122 , V_5 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return 0 ;
}
static T_2 F_55 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_82 * V_83 = V_2 -> V_83 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_63 ;
struct V_23 * V_24 = V_20 -> V_24 ;
T_2 V_125 = 0 ;
T_3 V_126 = 0 ;
T_3 V_127 = 0 ;
int V_6 ;
if ( V_83 -> V_45 -> V_86 && V_83 -> V_45 -> V_86 -> V_128 )
V_125 = V_83 -> V_45 -> V_86 -> V_128 ( V_20 ) ;
if ( V_5 -> V_45 -> V_86 && V_5 -> V_45 -> V_86 -> V_126 )
V_126 += V_5 -> V_45 -> V_86 -> V_126 ( V_20 , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_63 = V_2 -> V_11 [ V_6 ] ;
if ( V_63 -> V_45 -> V_86 && V_63 -> V_45 -> V_86 -> V_126 )
V_127 = F_23 ( V_127 ,
V_63 -> V_45 -> V_86 -> V_126 ( V_20 ,
V_63 ) ) ;
}
V_126 += V_127 ;
if ( V_83 -> V_45 -> V_126 )
V_126 += V_83 -> V_45 -> V_126 ( V_20 , V_2 -> V_11 [ 0 ] ) ;
V_24 -> V_126 = V_126 ;
return V_125 ;
}
static int F_56 ( struct V_1 * V_33 ,
struct V_1 * V_38 , int V_3 )
{
struct V_36 * V_37 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
if ( V_37 -> V_38 == V_38 && V_37 -> V_33 == V_33 )
return 0 ;
}
V_37 = F_57 ( sizeof( struct V_36 ) , V_129 ) ;
if ( ! V_37 )
return - V_130 ;
V_37 -> V_38 = V_38 ;
V_37 -> V_33 = V_33 ;
V_38 -> V_37 [ V_3 ] . V_24 = V_33 -> V_37 [ V_3 ] . V_24 ;
V_37 -> V_131 = V_132 ;
F_58 ( & V_37 -> V_133 , & V_33 -> V_37 [ V_3 ] . V_134 ) ;
F_58 ( & V_37 -> V_135 , & V_38 -> V_37 [ V_3 ] . V_136 ) ;
F_8 ( V_33 -> V_39 , L_39 ,
V_3 ? L_40 : L_41 , V_33 -> V_17 -> V_40 ,
V_3 ? L_42 : L_43 , V_38 -> V_17 -> V_40 ) ;
#ifdef F_59
if ( V_33 -> V_137 )
V_37 -> V_138 = F_60 ( V_38 -> V_17 -> V_40 , 0644 ,
V_33 -> V_137 , & V_37 -> V_131 ) ;
#endif
return 1 ;
}
static void F_61 ( struct V_1 * V_33 ,
struct V_1 * V_38 , int V_3 )
{
struct V_36 * V_37 ;
struct V_19 * V_139 , * V_140 ;
if ( ! V_38 -> V_37 [ V_3 ] . V_141 )
return;
V_140 = F_62 ( V_38 , V_3 ) ;
F_7 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_37 -> V_33 == V_33 )
continue;
F_8 ( V_33 -> V_39 , L_44 ,
V_3 ? L_40 : L_41 ,
V_37 -> V_33 -> V_17 -> V_40 ,
V_3 ? L_42 : L_43 , V_37 -> V_38 -> V_17 -> V_40 ) ;
V_139 = F_62 ( V_37 -> V_33 , V_3 ) ;
V_140 -> V_24 = V_139 -> V_24 ;
break;
}
}
void F_63 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 , * V_142 ;
F_64 (dpcm, d, &fe->dpcm[stream].be_clients, list_be) {
F_8 ( V_33 -> V_39 , L_45 ,
V_3 ? L_40 : L_41 ,
V_37 -> V_38 -> V_17 -> V_40 ) ;
if ( V_37 -> V_131 != V_143 )
continue;
F_8 ( V_33 -> V_39 , L_46 ,
V_3 ? L_40 : L_41 , V_33 -> V_17 -> V_40 ,
V_3 ? L_42 : L_43 , V_37 -> V_38 -> V_17 -> V_40 ) ;
F_61 ( V_33 , V_37 -> V_38 , V_3 ) ;
#ifdef F_59
F_65 ( V_37 -> V_138 ) ;
#endif
F_66 ( & V_37 -> V_133 ) ;
F_66 ( & V_37 -> V_135 ) ;
F_67 ( V_37 ) ;
}
}
static struct V_1 * F_68 ( struct V_144 * V_111 ,
struct V_145 * V_146 , int V_3 )
{
struct V_1 * V_38 ;
int V_6 , V_147 ;
if ( V_3 == V_8 ) {
for ( V_6 = 0 ; V_6 < V_111 -> V_148 ; V_6 ++ ) {
V_38 = & V_111 -> V_2 [ V_6 ] ;
if ( ! V_38 -> V_17 -> V_96 )
continue;
if ( V_38 -> V_5 -> V_149 == V_146 )
return V_38 ;
for ( V_147 = 0 ; V_147 < V_38 -> V_10 ; V_147 ++ ) {
struct V_4 * V_116 = V_38 -> V_11 [ V_147 ] ;
if ( V_116 -> V_149 == V_146 )
return V_38 ;
}
}
} else {
for ( V_6 = 0 ; V_6 < V_111 -> V_148 ; V_6 ++ ) {
V_38 = & V_111 -> V_2 [ V_6 ] ;
if ( ! V_38 -> V_17 -> V_96 )
continue;
if ( V_38 -> V_5 -> V_150 == V_146 )
return V_38 ;
for ( V_147 = 0 ; V_147 < V_38 -> V_10 ; V_147 ++ ) {
struct V_4 * V_116 = V_38 -> V_11 [ V_147 ] ;
if ( V_116 -> V_150 == V_146 )
return V_38 ;
}
}
}
F_12 ( V_111 -> V_39 , L_47 ,
V_3 ? L_40 : L_41 , V_146 -> V_40 ) ;
return NULL ;
}
static inline struct V_145 *
F_69 ( struct V_4 * V_116 , int V_3 )
{
if ( V_3 == V_8 )
return V_116 -> V_149 ;
else
return V_116 -> V_150 ;
}
static int F_70 ( struct V_151 * V_152 ,
struct V_145 * V_146 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_152 -> V_153 ; V_6 ++ ) {
if ( V_146 == V_152 -> V_154 [ V_6 ] )
return 1 ;
}
return 0 ;
}
int F_71 ( struct V_1 * V_33 ,
int V_3 , struct V_151 * * V_152 )
{
struct V_4 * V_5 = V_33 -> V_5 ;
int V_155 ;
V_155 = F_72 ( V_5 , V_3 , V_152 ) ;
F_8 ( V_33 -> V_39 , L_48 , V_155 ,
V_3 ? L_40 : L_41 ) ;
return V_155 ;
}
static int F_73 ( struct V_1 * V_33 , int V_3 ,
struct V_151 * * V_156 )
{
struct V_36 * V_37 ;
struct V_151 * V_152 = * V_156 ;
struct V_145 * V_146 ;
int V_157 = 0 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
unsigned int V_6 ;
V_146 = F_69 ( V_37 -> V_38 -> V_5 , V_3 ) ;
if ( V_146 && F_70 ( V_152 , V_146 ) )
continue;
for ( V_6 = 0 ; V_6 < V_37 -> V_38 -> V_10 ; V_6 ++ ) {
struct V_4 * V_116 = V_37 -> V_38 -> V_11 [ V_6 ] ;
V_146 = F_69 ( V_116 , V_3 ) ;
if ( V_146 && F_70 ( V_152 , V_146 ) )
continue;
}
F_8 ( V_33 -> V_39 , L_49 ,
V_3 ? L_40 : L_41 ,
V_37 -> V_38 -> V_17 -> V_40 , V_33 -> V_17 -> V_40 ) ;
V_37 -> V_131 = V_143 ;
V_37 -> V_38 -> V_37 [ V_3 ] . V_158 = V_159 ;
V_157 ++ ;
}
F_8 ( V_33 -> V_39 , L_50 , V_157 ) ;
return V_157 ;
}
static int F_74 ( struct V_1 * V_33 , int V_3 ,
struct V_151 * * V_156 )
{
struct V_144 * V_111 = V_33 -> V_111 ;
struct V_151 * V_152 = * V_156 ;
struct V_1 * V_38 ;
int V_6 , V_160 = 0 , V_161 ;
for ( V_6 = 0 ; V_6 < V_152 -> V_153 ; V_6 ++ ) {
switch ( V_152 -> V_154 [ V_6 ] -> V_162 ) {
case V_163 :
if ( V_3 != V_8 )
continue;
break;
case V_164 :
if ( V_3 != V_109 )
continue;
break;
default:
continue;
}
V_38 = F_68 ( V_111 , V_152 -> V_154 [ V_6 ] , V_3 ) ;
if ( ! V_38 ) {
F_12 ( V_33 -> V_39 , L_51 ,
V_152 -> V_154 [ V_6 ] -> V_40 ) ;
continue;
}
if ( ! V_38 -> V_17 -> V_96 )
continue;
if ( ! V_33 -> V_37 [ V_3 ] . V_24 && ! V_33 -> V_165 )
continue;
V_161 = F_56 ( V_33 , V_38 , V_3 ) ;
if ( V_161 < 0 ) {
F_12 ( V_33 -> V_39 , L_52 ,
V_152 -> V_154 [ V_6 ] -> V_40 ) ;
break;
} else if ( V_161 == 0 )
continue;
V_38 -> V_37 [ V_3 ] . V_158 = V_159 ;
V_160 ++ ;
}
F_8 ( V_33 -> V_39 , L_53 , V_160 ) ;
return V_160 ;
}
int F_75 ( struct V_1 * V_33 ,
int V_3 , struct V_151 * * V_152 , int V_160 )
{
if ( V_160 )
return F_74 ( V_33 , V_3 , V_152 ) ;
else
return F_73 ( V_33 , V_3 , V_152 ) ;
}
void F_76 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_37 -> V_38 -> V_37 [ V_3 ] . V_158 =
V_166 ;
}
static void F_77 ( struct V_1 * V_33 ,
int V_3 )
{
struct V_36 * V_37 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_140 =
F_62 ( V_38 , V_3 ) ;
if ( V_38 -> V_37 [ V_3 ] . V_141 == 0 )
F_12 ( V_38 -> V_39 , L_54 ,
V_3 ? L_40 : L_41 ,
V_38 -> V_37 [ V_3 ] . V_131 ) ;
if ( -- V_38 -> V_37 [ V_3 ] . V_141 != 0 )
continue;
if ( V_38 -> V_37 [ V_3 ] . V_131 != V_167 )
continue;
F_41 ( V_140 ) ;
V_140 -> V_24 = NULL ;
V_38 -> V_37 [ V_3 ] . V_131 = V_168 ;
}
}
int F_78 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 ;
int V_161 , V_169 = 0 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_140 =
F_62 ( V_38 , V_3 ) ;
if ( ! V_140 ) {
F_12 ( V_38 -> V_39 , L_55 ,
V_3 ? L_40 : L_41 ) ;
continue;
}
if ( ! F_79 ( V_33 , V_38 , V_3 ) )
continue;
if ( V_38 -> V_37 [ V_3 ] . V_141 == V_170 )
F_12 ( V_38 -> V_39 , L_56 ,
V_3 ? L_40 : L_41 ,
V_38 -> V_37 [ V_3 ] . V_131 ) ;
if ( V_38 -> V_37 [ V_3 ] . V_141 ++ != 0 )
continue;
if ( ( V_38 -> V_37 [ V_3 ] . V_131 != V_171 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 != V_168 ) )
continue;
F_8 ( V_38 -> V_39 , L_57 ,
V_3 ? L_40 : L_41 , V_38 -> V_17 -> V_40 ) ;
V_140 -> V_24 = V_38 -> V_37 [ V_3 ] . V_24 ;
V_161 = F_29 ( V_140 ) ;
if ( V_161 < 0 ) {
F_12 ( V_38 -> V_39 , L_58 , V_161 ) ;
V_38 -> V_37 [ V_3 ] . V_141 -- ;
if ( V_38 -> V_37 [ V_3 ] . V_141 < 0 )
F_12 ( V_38 -> V_39 , L_59 ,
V_3 ? L_40 : L_41 ,
V_38 -> V_37 [ V_3 ] . V_131 ) ;
V_38 -> V_37 [ V_3 ] . V_131 = V_168 ;
goto V_172;
}
V_38 -> V_37 [ V_3 ] . V_131 = V_167 ;
V_169 ++ ;
}
return V_169 ;
V_172:
F_80 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_140 =
F_62 ( V_38 , V_3 ) ;
if ( ! F_79 ( V_33 , V_38 , V_3 ) )
continue;
if ( V_38 -> V_37 [ V_3 ] . V_141 == 0 )
F_12 ( V_38 -> V_39 , L_60 ,
V_3 ? L_40 : L_41 ,
V_38 -> V_37 [ V_3 ] . V_131 ) ;
if ( -- V_38 -> V_37 [ V_3 ] . V_141 != 0 )
continue;
if ( V_38 -> V_37 [ V_3 ] . V_131 != V_167 )
continue;
F_41 ( V_140 ) ;
V_140 -> V_24 = NULL ;
V_38 -> V_37 [ V_3 ] . V_131 = V_168 ;
}
return V_161 ;
}
static void F_81 ( struct V_23 * V_24 ,
struct V_70 * V_3 ,
T_1 V_26 )
{
V_24 -> V_22 . V_76 = V_3 -> V_76 ;
V_24 -> V_22 . V_77 = V_3 -> V_77 ;
V_24 -> V_22 . V_80 = V_3 -> V_80 ;
V_24 -> V_22 . V_81 = V_3 -> V_81 ;
if ( V_24 -> V_22 . V_26 )
V_24 -> V_22 . V_26 &= V_26 & V_3 -> V_26 ;
else
V_24 -> V_22 . V_26 = V_26 & V_3 -> V_26 ;
V_24 -> V_22 . V_78 = V_3 -> V_78 ;
}
static T_1 F_82 ( struct V_19 * V_20 )
{
struct V_1 * V_33 = V_20 -> V_42 ;
struct V_36 * V_37 ;
T_1 V_26 = V_79 ;
int V_3 = V_20 -> V_3 ;
if ( ! V_33 -> V_17 -> V_173 )
return V_26 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_58 * V_69 ;
struct V_70 * V_71 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_38 -> V_10 ; V_6 ++ ) {
V_69 = V_38 -> V_11 [ V_6 ] -> V_45 ;
if ( V_3 == V_8 )
V_71 = & V_69 -> V_65 ;
else
V_71 = & V_69 -> V_67 ;
V_26 &= V_71 -> V_26 ;
}
}
return V_26 ;
}
static void F_83 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = V_20 -> V_24 ;
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_58 * V_68 = V_5 -> V_45 ;
T_1 V_174 = F_82 ( V_20 ) ;
if ( V_20 -> V_3 == V_8 )
F_81 ( V_24 , & V_68 -> V_65 , V_174 ) ;
else
F_81 ( V_24 , & V_68 -> V_67 , V_174 ) ;
}
static void F_84 ( struct V_1 * V_33 ,
int V_3 , enum V_175 V_131 )
{
struct V_19 * V_20 =
F_62 ( V_33 , V_3 ) ;
F_85 ( V_20 ) ;
if ( V_131 == V_166 && V_33 -> V_37 [ V_3 ] . V_176 ) {
F_86 ( V_20 ,
V_33 -> V_37 [ V_3 ] . V_176 - 1 ) ;
V_33 -> V_37 [ V_3 ] . V_176 = 0 ;
}
V_33 -> V_37 [ V_3 ] . V_158 = V_131 ;
F_87 ( V_20 ) ;
}
static int F_88 ( struct V_19 * V_139 )
{
struct V_1 * V_33 = V_139 -> V_42 ;
struct V_23 * V_24 = V_139 -> V_24 ;
int V_3 = V_139 -> V_3 , V_43 = 0 ;
F_84 ( V_33 , V_3 , V_177 ) ;
V_43 = F_78 ( V_33 , V_139 -> V_3 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_61 , V_43 ) ;
goto V_178;
}
F_8 ( V_33 -> V_39 , L_62 , V_33 -> V_17 -> V_40 ) ;
V_43 = F_29 ( V_139 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_63 , V_43 ) ;
goto V_172;
}
V_33 -> V_37 [ V_3 ] . V_131 = V_167 ;
F_83 ( V_139 ) ;
F_28 ( V_24 ) ;
F_84 ( V_33 , V_3 , V_166 ) ;
return 0 ;
V_172:
F_77 ( V_33 , V_139 -> V_3 ) ;
V_178:
F_84 ( V_33 , V_3 , V_166 ) ;
return V_43 ;
}
int F_89 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_140 =
F_62 ( V_38 , V_3 ) ;
if ( ! F_79 ( V_33 , V_38 , V_3 ) )
continue;
if ( V_38 -> V_37 [ V_3 ] . V_141 == 0 )
F_12 ( V_38 -> V_39 , L_54 ,
V_3 ? L_40 : L_41 ,
V_38 -> V_37 [ V_3 ] . V_131 ) ;
if ( -- V_38 -> V_37 [ V_3 ] . V_141 != 0 )
continue;
if ( ( V_38 -> V_37 [ V_3 ] . V_131 != V_179 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 != V_167 ) )
continue;
F_8 ( V_38 -> V_39 , L_64 ,
V_37 -> V_33 -> V_17 -> V_40 ) ;
F_41 ( V_140 ) ;
V_140 -> V_24 = NULL ;
V_38 -> V_37 [ V_3 ] . V_131 = V_168 ;
}
return 0 ;
}
static int F_90 ( struct V_19 * V_20 )
{
struct V_1 * V_33 = V_20 -> V_42 ;
int V_3 = V_20 -> V_3 ;
F_84 ( V_33 , V_3 , V_177 ) ;
F_89 ( V_33 , V_20 -> V_3 ) ;
F_8 ( V_33 -> V_39 , L_65 , V_33 -> V_17 -> V_40 ) ;
F_41 ( V_20 ) ;
F_6 ( V_33 , V_3 , V_107 ) ;
V_33 -> V_37 [ V_3 ] . V_131 = V_168 ;
F_84 ( V_33 , V_3 , V_166 ) ;
return 0 ;
}
int F_91 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_140 =
F_62 ( V_38 , V_3 ) ;
if ( ! F_79 ( V_33 , V_38 , V_3 ) )
continue;
if ( ! F_92 ( V_33 , V_38 , V_3 ) )
continue;
if ( V_38 -> V_37 [ V_3 ] . V_141 > 1 )
continue;
if ( ( V_38 -> V_37 [ V_3 ] . V_131 != V_180 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 != V_181 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 != V_179 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 != V_182 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 != V_183 ) )
continue;
F_8 ( V_38 -> V_39 , L_66 ,
V_37 -> V_33 -> V_17 -> V_40 ) ;
F_52 ( V_140 ) ;
V_38 -> V_37 [ V_3 ] . V_131 = V_179 ;
}
return 0 ;
}
static int F_93 ( struct V_19 * V_20 )
{
struct V_1 * V_33 = V_20 -> V_42 ;
int V_161 , V_3 = V_20 -> V_3 ;
F_32 ( & V_33 -> V_111 -> V_184 , V_185 ) ;
F_84 ( V_33 , V_3 , V_177 ) ;
F_8 ( V_33 -> V_39 , L_67 , V_33 -> V_17 -> V_40 ) ;
V_161 = F_52 ( V_20 ) ;
if ( V_161 < 0 )
F_12 ( V_33 -> V_39 , L_68 ,
V_33 -> V_17 -> V_40 ) ;
V_161 = F_91 ( V_33 , V_3 ) ;
V_33 -> V_37 [ V_3 ] . V_131 = V_179 ;
F_84 ( V_33 , V_3 , V_166 ) ;
F_36 ( & V_33 -> V_111 -> V_184 ) ;
return 0 ;
}
int F_94 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 ;
int V_43 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_140 =
F_62 ( V_38 , V_3 ) ;
if ( ! F_79 ( V_33 , V_38 , V_3 ) )
continue;
if ( ! F_95 ( V_33 , V_38 , V_3 ) )
continue;
if ( ( V_38 -> V_37 [ V_3 ] . V_131 != V_167 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 != V_180 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 != V_179 ) )
continue;
F_8 ( V_38 -> V_39 , L_69 ,
V_37 -> V_33 -> V_17 -> V_40 ) ;
memcpy ( & V_37 -> V_117 , & V_33 -> V_37 [ V_3 ] . V_117 ,
sizeof( struct V_54 ) ) ;
if ( V_38 -> V_17 -> V_186 ) {
V_43 = V_38 -> V_17 -> V_186 ( V_38 ,
& V_37 -> V_117 ) ;
if ( V_43 < 0 ) {
F_12 ( V_38 -> V_39 ,
L_70 ,
V_43 ) ;
goto V_172;
}
}
V_43 = F_51 ( V_140 , & V_37 -> V_117 ) ;
if ( V_43 < 0 ) {
F_12 ( V_37 -> V_38 -> V_39 ,
L_71 , V_43 ) ;
goto V_172;
}
V_38 -> V_37 [ V_3 ] . V_131 = V_180 ;
}
return 0 ;
V_172:
F_80 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_140 =
F_62 ( V_38 , V_3 ) ;
if ( ! F_79 ( V_33 , V_38 , V_3 ) )
continue;
if ( ! F_92 ( V_33 , V_38 , V_3 ) )
continue;
if ( ( V_38 -> V_37 [ V_3 ] . V_131 != V_167 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 != V_180 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 != V_179 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 != V_183 ) )
continue;
F_52 ( V_140 ) ;
}
return V_43 ;
}
static int F_96 ( struct V_19 * V_20 ,
struct V_54 * V_55 )
{
struct V_1 * V_33 = V_20 -> V_42 ;
int V_43 , V_3 = V_20 -> V_3 ;
F_32 ( & V_33 -> V_111 -> V_184 , V_185 ) ;
F_84 ( V_33 , V_3 , V_177 ) ;
memcpy ( & V_33 -> V_37 [ V_20 -> V_3 ] . V_117 , V_55 ,
sizeof( struct V_54 ) ) ;
V_43 = F_94 ( V_33 , V_20 -> V_3 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_71 , V_43 ) ;
goto V_88;
}
F_8 ( V_33 -> V_39 , L_72 ,
V_33 -> V_17 -> V_40 , F_14 ( V_55 ) ,
F_15 ( V_55 ) , F_17 ( V_55 ) ) ;
V_43 = F_51 ( V_20 , V_55 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_73 , V_43 ) ;
F_91 ( V_33 , V_3 ) ;
} else
V_33 -> V_37 [ V_3 ] . V_131 = V_180 ;
V_88:
F_84 ( V_33 , V_3 , V_166 ) ;
F_36 ( & V_33 -> V_111 -> V_184 ) ;
return V_43 ;
}
static int F_97 ( struct V_36 * V_37 ,
struct V_19 * V_20 , int V_122 )
{
int V_43 ;
F_8 ( V_37 -> V_38 -> V_39 , L_74 ,
V_37 -> V_33 -> V_17 -> V_40 , V_122 ) ;
V_43 = F_53 ( V_20 , V_122 ) ;
if ( V_43 < 0 )
F_12 ( V_37 -> V_38 -> V_39 , L_75 , V_43 ) ;
return V_43 ;
}
int F_98 ( struct V_1 * V_33 , int V_3 ,
int V_122 )
{
struct V_36 * V_37 ;
int V_43 = 0 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_140 =
F_62 ( V_38 , V_3 ) ;
if ( ! F_79 ( V_33 , V_38 , V_3 ) )
continue;
switch ( V_122 ) {
case V_187 :
if ( ( V_38 -> V_37 [ V_3 ] . V_131 != V_181 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 != V_183 ) )
continue;
V_43 = F_97 ( V_37 , V_140 , V_122 ) ;
if ( V_43 )
return V_43 ;
V_38 -> V_37 [ V_3 ] . V_131 = V_188 ;
break;
case V_189 :
if ( ( V_38 -> V_37 [ V_3 ] . V_131 != V_190 ) )
continue;
V_43 = F_97 ( V_37 , V_140 , V_122 ) ;
if ( V_43 )
return V_43 ;
V_38 -> V_37 [ V_3 ] . V_131 = V_188 ;
break;
case V_191 :
if ( ( V_38 -> V_37 [ V_3 ] . V_131 != V_182 ) )
continue;
V_43 = F_97 ( V_37 , V_140 , V_122 ) ;
if ( V_43 )
return V_43 ;
V_38 -> V_37 [ V_3 ] . V_131 = V_188 ;
break;
case V_192 :
if ( V_38 -> V_37 [ V_3 ] . V_131 != V_188 )
continue;
if ( ! F_92 ( V_33 , V_38 , V_3 ) )
continue;
V_43 = F_97 ( V_37 , V_140 , V_122 ) ;
if ( V_43 )
return V_43 ;
V_38 -> V_37 [ V_3 ] . V_131 = V_183 ;
break;
case V_193 :
if ( V_38 -> V_37 [ V_3 ] . V_131 != V_188 )
continue;
if ( ! F_92 ( V_33 , V_38 , V_3 ) )
continue;
V_43 = F_97 ( V_37 , V_140 , V_122 ) ;
if ( V_43 )
return V_43 ;
V_38 -> V_37 [ V_3 ] . V_131 = V_190 ;
break;
case V_194 :
if ( V_38 -> V_37 [ V_3 ] . V_131 != V_188 )
continue;
if ( ! F_92 ( V_33 , V_38 , V_3 ) )
continue;
V_43 = F_97 ( V_37 , V_140 , V_122 ) ;
if ( V_43 )
return V_43 ;
V_38 -> V_37 [ V_3 ] . V_131 = V_182 ;
break;
}
}
return V_43 ;
}
static int F_86 ( struct V_19 * V_20 , int V_122 )
{
struct V_1 * V_33 = V_20 -> V_42 ;
int V_3 = V_20 -> V_3 , V_43 ;
enum V_195 V_123 = V_33 -> V_17 -> V_123 [ V_3 ] ;
V_33 -> V_37 [ V_3 ] . V_158 = V_177 ;
switch ( V_123 ) {
case V_196 :
F_8 ( V_33 -> V_39 , L_76 ,
V_33 -> V_17 -> V_40 , V_122 ) ;
V_43 = F_53 ( V_20 , V_122 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_77 , V_43 ) ;
goto V_88;
}
V_43 = F_98 ( V_33 , V_20 -> V_3 , V_122 ) ;
break;
case V_197 :
V_43 = F_98 ( V_33 , V_20 -> V_3 , V_122 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_77 , V_43 ) ;
goto V_88;
}
F_8 ( V_33 -> V_39 , L_78 ,
V_33 -> V_17 -> V_40 , V_122 ) ;
V_43 = F_53 ( V_20 , V_122 ) ;
break;
case V_198 :
F_8 ( V_33 -> V_39 , L_79 ,
V_33 -> V_17 -> V_40 , V_122 ) ;
V_43 = F_54 ( V_20 , V_122 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_77 , V_43 ) ;
goto V_88;
}
break;
default:
F_12 ( V_33 -> V_39 , L_80 , V_122 ,
V_33 -> V_17 -> V_40 ) ;
V_43 = - V_57 ;
goto V_88;
}
switch ( V_122 ) {
case V_187 :
case V_189 :
case V_191 :
V_33 -> V_37 [ V_3 ] . V_131 = V_188 ;
break;
case V_192 :
case V_193 :
case V_194 :
V_33 -> V_37 [ V_3 ] . V_131 = V_183 ;
break;
}
V_88:
V_33 -> V_37 [ V_3 ] . V_158 = V_166 ;
return V_43 ;
}
static int F_99 ( struct V_19 * V_20 , int V_122 )
{
struct V_1 * V_33 = V_20 -> V_42 ;
int V_3 = V_20 -> V_3 ;
if ( V_33 -> V_37 [ V_3 ] . V_158 != V_166 ) {
V_33 -> V_37 [ V_3 ] . V_176 = V_122 + 1 ;
return 0 ;
}
return F_86 ( V_20 , V_122 ) ;
}
int F_100 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 ;
int V_43 = 0 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_140 =
F_62 ( V_38 , V_3 ) ;
if ( ! F_79 ( V_33 , V_38 , V_3 ) )
continue;
if ( ( V_38 -> V_37 [ V_3 ] . V_131 != V_180 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 != V_183 ) )
continue;
F_8 ( V_38 -> V_39 , L_81 ,
V_37 -> V_33 -> V_17 -> V_40 ) ;
V_43 = F_45 ( V_140 ) ;
if ( V_43 < 0 ) {
F_12 ( V_38 -> V_39 , L_82 ,
V_43 ) ;
break;
}
V_38 -> V_37 [ V_3 ] . V_131 = V_181 ;
}
return V_43 ;
}
static int F_101 ( struct V_19 * V_20 )
{
struct V_1 * V_33 = V_20 -> V_42 ;
int V_3 = V_20 -> V_3 , V_43 = 0 ;
F_32 ( & V_33 -> V_111 -> V_184 , V_185 ) ;
F_8 ( V_33 -> V_39 , L_83 , V_33 -> V_17 -> V_40 ) ;
F_84 ( V_33 , V_3 , V_177 ) ;
if ( F_102 ( & V_33 -> V_37 [ V_3 ] . V_134 ) ) {
F_12 ( V_33 -> V_39 , L_84 ,
V_33 -> V_17 -> V_40 ) ;
V_43 = - V_57 ;
goto V_88;
}
V_43 = F_100 ( V_33 , V_20 -> V_3 ) ;
if ( V_43 < 0 )
goto V_88;
V_43 = F_45 ( V_20 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_85 ,
V_33 -> V_17 -> V_40 ) ;
goto V_88;
}
F_6 ( V_33 , V_3 , V_112 ) ;
V_33 -> V_37 [ V_3 ] . V_131 = V_181 ;
V_88:
F_84 ( V_33 , V_3 , V_166 ) ;
F_36 ( & V_33 -> V_111 -> V_184 ) ;
return V_43 ;
}
static int F_103 ( struct V_19 * V_20 ,
unsigned int V_122 , void * V_199 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_82 * V_83 = V_2 -> V_83 ;
if ( V_83 -> V_45 -> V_86 && V_83 -> V_45 -> V_86 -> V_200 )
return V_83 -> V_45 -> V_86 -> V_200 ( V_20 , V_122 , V_199 ) ;
return F_104 ( V_20 , V_122 , V_199 ) ;
}
static int F_105 ( struct V_1 * V_33 , int V_3 )
{
struct V_19 * V_20 =
F_62 ( V_33 , V_3 ) ;
enum V_195 V_123 = V_33 -> V_17 -> V_123 [ V_3 ] ;
int V_161 ;
F_8 ( V_33 -> V_39 , L_86 ,
V_3 ? L_40 : L_41 , V_33 -> V_17 -> V_40 ) ;
if ( V_123 == V_198 ) {
F_8 ( V_33 -> V_39 , L_87 ,
V_33 -> V_17 -> V_40 ) ;
V_161 = F_54 ( V_20 , V_192 ) ;
if ( V_161 < 0 )
F_12 ( V_33 -> V_39 , L_77 , V_161 ) ;
} else {
F_8 ( V_33 -> V_39 , L_88 ,
V_33 -> V_17 -> V_40 ) ;
V_161 = F_98 ( V_33 , V_3 , V_192 ) ;
if ( V_161 < 0 )
F_12 ( V_33 -> V_39 , L_77 , V_161 ) ;
}
V_161 = F_91 ( V_33 , V_3 ) ;
if ( V_161 < 0 )
F_12 ( V_33 -> V_39 , L_89 , V_161 ) ;
V_161 = F_89 ( V_33 , V_3 ) ;
if ( V_161 < 0 )
F_12 ( V_33 -> V_39 , L_90 , V_161 ) ;
F_6 ( V_33 , V_3 , V_201 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_33 , int V_3 )
{
struct V_19 * V_20 =
F_62 ( V_33 , V_3 ) ;
struct V_36 * V_37 ;
enum V_195 V_123 = V_33 -> V_17 -> V_123 [ V_3 ] ;
int V_43 ;
F_8 ( V_33 -> V_39 , L_91 ,
V_3 ? L_40 : L_41 , V_33 -> V_17 -> V_40 ) ;
if ( V_33 -> V_37 [ V_3 ] . V_131 == V_179 ||
V_33 -> V_37 [ V_3 ] . V_131 == V_168 )
return - V_57 ;
V_43 = F_78 ( V_33 , V_3 ) ;
if ( V_43 < 0 )
goto V_202;
if ( V_33 -> V_37 [ V_3 ] . V_131 == V_167 )
return 0 ;
V_43 = F_94 ( V_33 , V_3 ) ;
if ( V_43 < 0 )
goto V_101;
if ( V_33 -> V_37 [ V_3 ] . V_131 == V_180 )
return 0 ;
V_43 = F_100 ( V_33 , V_3 ) ;
if ( V_43 < 0 )
goto V_121;
F_6 ( V_33 , V_3 , V_201 ) ;
if ( V_33 -> V_37 [ V_3 ] . V_131 == V_181 ||
V_33 -> V_37 [ V_3 ] . V_131 == V_183 )
return 0 ;
if ( V_123 == V_198 ) {
F_8 ( V_33 -> V_39 , L_92 ,
V_33 -> V_17 -> V_40 ) ;
V_43 = F_54 ( V_20 , V_187 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_93 , V_43 ) ;
goto V_121;
}
} else {
F_8 ( V_33 -> V_39 , L_94 ,
V_33 -> V_17 -> V_40 ) ;
V_43 = F_98 ( V_33 , V_3 ,
V_187 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_77 , V_43 ) ;
goto V_121;
}
}
return 0 ;
V_121:
F_91 ( V_33 , V_3 ) ;
V_101:
F_89 ( V_33 , V_3 ) ;
V_202:
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
if ( V_38 -> V_37 [ V_3 ] . V_131 != V_188 )
V_37 -> V_131 = V_143 ;
}
return V_43 ;
}
static int F_107 ( struct V_1 * V_33 , int V_3 )
{
int V_43 ;
F_84 ( V_33 , V_3 , V_159 ) ;
V_43 = F_106 ( V_33 , V_3 ) ;
if ( V_43 < 0 )
F_12 ( V_33 -> V_39 , L_95 ) ;
F_84 ( V_33 , V_3 , V_166 ) ;
return V_43 ;
}
static int F_108 ( struct V_1 * V_33 , int V_3 )
{
int V_43 ;
F_84 ( V_33 , V_3 , V_159 ) ;
V_43 = F_105 ( V_33 , V_3 ) ;
if ( V_43 < 0 )
F_12 ( V_33 -> V_39 , L_96 ) ;
F_84 ( V_33 , V_3 , V_166 ) ;
return V_43 ;
}
int F_109 ( struct V_144 * V_111 )
{
int V_6 , V_203 , V_160 , V_155 ;
F_32 ( & V_111 -> V_184 , V_185 ) ;
for ( V_6 = 0 ; V_6 < V_111 -> V_204 ; V_6 ++ ) {
struct V_151 * V_152 ;
struct V_1 * V_33 = & V_111 -> V_2 [ V_6 ] ;
if ( ! V_33 -> V_17 -> V_95 )
continue;
if ( ! V_33 -> V_5 -> V_13 )
continue;
F_8 ( V_33 -> V_39 , L_97 ,
V_33 -> V_17 -> V_40 ) ;
if ( ! V_33 -> V_5 -> V_45 -> V_65 . V_80
|| ! V_33 -> V_63 -> V_45 -> V_65 . V_80 )
goto V_67;
if ( ! V_33 -> V_5 -> V_9
|| ! V_33 -> V_63 -> V_9 )
goto V_67;
V_155 = F_71 ( V_33 , V_8 , & V_152 ) ;
if ( V_155 < 0 ) {
F_21 ( V_33 -> V_39 , L_98 ,
V_33 -> V_17 -> V_40 , L_41 ) ;
F_36 ( & V_111 -> V_184 ) ;
return V_155 ;
}
V_160 = F_75 ( V_33 , V_8 , & V_152 , 1 ) ;
if ( V_160 ) {
F_107 ( V_33 , V_8 ) ;
F_76 ( V_33 , V_8 ) ;
F_63 ( V_33 , V_8 ) ;
}
V_203 = F_75 ( V_33 , V_8 , & V_152 , 0 ) ;
if ( V_203 ) {
F_108 ( V_33 , V_8 ) ;
F_76 ( V_33 , V_8 ) ;
F_63 ( V_33 , V_8 ) ;
}
F_110 ( & V_152 ) ;
V_67:
if ( ! V_33 -> V_5 -> V_45 -> V_67 . V_80
|| ! V_33 -> V_63 -> V_45 -> V_67 . V_80 )
continue;
if ( ! V_33 -> V_5 -> V_12
|| ! V_33 -> V_63 -> V_12 )
continue;
V_155 = F_71 ( V_33 , V_109 , & V_152 ) ;
if ( V_155 < 0 ) {
F_21 ( V_33 -> V_39 , L_98 ,
V_33 -> V_17 -> V_40 , L_40 ) ;
F_36 ( & V_111 -> V_184 ) ;
return V_155 ;
}
V_160 = F_75 ( V_33 , V_109 , & V_152 , 1 ) ;
if ( V_160 ) {
F_107 ( V_33 , V_109 ) ;
F_76 ( V_33 , V_109 ) ;
F_63 ( V_33 , V_109 ) ;
}
V_203 = F_75 ( V_33 , V_109 , & V_152 , 0 ) ;
if ( V_203 ) {
F_108 ( V_33 , V_109 ) ;
F_76 ( V_33 , V_109 ) ;
F_63 ( V_33 , V_109 ) ;
}
F_110 ( & V_152 ) ;
}
F_36 ( & V_111 -> V_184 ) ;
return 0 ;
}
int F_111 ( struct V_1 * V_33 , int V_205 )
{
struct V_36 * V_37 ;
struct V_206 * V_207 =
& V_33 -> V_37 [ V_8 ] . V_134 ;
F_7 (dpcm, clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
int V_6 ;
if ( V_38 -> V_17 -> V_208 )
continue;
for ( V_6 = 0 ; V_6 < V_38 -> V_10 ; V_6 ++ ) {
struct V_4 * V_116 = V_38 -> V_11 [ V_6 ] ;
struct V_58 * V_209 = V_116 -> V_45 ;
F_8 ( V_38 -> V_39 , L_99 ,
V_38 -> V_17 -> V_40 ) ;
if ( V_209 -> V_86 && V_209 -> V_86 -> V_210 &&
V_116 -> V_9 )
V_209 -> V_86 -> V_210 ( V_116 , V_205 ) ;
}
}
return 0 ;
}
static int F_112 ( struct V_19 * V_139 )
{
struct V_1 * V_33 = V_139 -> V_42 ;
struct V_36 * V_37 ;
struct V_151 * V_152 ;
int V_43 ;
int V_3 = V_139 -> V_3 ;
F_32 ( & V_33 -> V_111 -> V_184 , V_185 ) ;
V_33 -> V_37 [ V_3 ] . V_24 = V_139 -> V_24 ;
V_43 = F_71 ( V_33 , V_3 , & V_152 ) ;
if ( V_43 < 0 ) {
F_36 ( & V_33 -> V_111 -> V_184 ) ;
return V_43 ;
} else if ( V_43 == 0 ) {
F_8 ( V_33 -> V_39 , L_100 ,
V_33 -> V_17 -> V_40 , V_3 ? L_40 : L_41 ) ;
}
F_75 ( V_33 , V_3 , & V_152 , 1 ) ;
V_43 = F_88 ( V_139 ) ;
if ( V_43 < 0 ) {
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_37 -> V_131 = V_143 ;
F_63 ( V_33 , V_3 ) ;
V_33 -> V_37 [ V_3 ] . V_24 = NULL ;
}
F_76 ( V_33 , V_3 ) ;
F_110 ( & V_152 ) ;
F_36 ( & V_33 -> V_111 -> V_184 ) ;
return V_43 ;
}
static int F_113 ( struct V_19 * V_139 )
{
struct V_1 * V_33 = V_139 -> V_42 ;
struct V_36 * V_37 ;
int V_3 = V_139 -> V_3 , V_43 ;
F_32 ( & V_33 -> V_111 -> V_184 , V_185 ) ;
V_43 = F_90 ( V_139 ) ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_37 -> V_131 = V_143 ;
F_63 ( V_33 , V_3 ) ;
V_33 -> V_37 [ V_3 ] . V_24 = NULL ;
F_36 ( & V_33 -> V_111 -> V_184 ) ;
return V_43 ;
}
int F_114 ( struct V_1 * V_2 , int V_211 )
{
struct V_82 * V_83 = V_2 -> V_83 ;
struct V_4 * V_63 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_212 * V_213 ;
char V_214 [ 64 ] ;
int V_43 = 0 , V_65 = 0 , V_67 = 0 ;
int V_6 ;
if ( V_2 -> V_17 -> V_95 || V_2 -> V_17 -> V_96 ) {
V_65 = V_2 -> V_17 -> V_215 ;
V_67 = V_2 -> V_17 -> V_216 ;
} else {
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_63 = V_2 -> V_11 [ V_6 ] ;
if ( V_63 -> V_45 -> V_65 . V_80 )
V_65 = 1 ;
if ( V_63 -> V_45 -> V_67 . V_80 )
V_67 = 1 ;
}
V_67 = V_67 && V_5 -> V_45 -> V_67 . V_80 ;
V_65 = V_65 && V_5 -> V_45 -> V_65 . V_80 ;
}
if ( V_2 -> V_17 -> V_217 ) {
V_65 = 1 ;
V_67 = 0 ;
}
if ( V_2 -> V_17 -> V_218 ) {
V_65 = 0 ;
V_67 = 1 ;
}
if ( V_2 -> V_17 -> V_96 ) {
snprintf ( V_214 , sizeof( V_214 ) , L_101 ,
V_2 -> V_17 -> V_105 ) ;
V_43 = F_115 ( V_2 -> V_111 -> V_219 , V_214 , V_211 ,
V_65 , V_67 , & V_213 ) ;
} else {
if ( V_2 -> V_17 -> V_95 )
snprintf ( V_214 , sizeof( V_214 ) , L_102 ,
V_2 -> V_17 -> V_105 ) ;
else
snprintf ( V_214 , sizeof( V_214 ) , L_103 ,
V_2 -> V_17 -> V_105 ,
( V_2 -> V_10 > 1 ) ?
L_12 : V_2 -> V_63 -> V_40 , V_211 ) ;
V_43 = F_116 ( V_2 -> V_111 -> V_219 , V_214 , V_211 , V_65 ,
V_67 , & V_213 ) ;
}
if ( V_43 < 0 ) {
F_12 ( V_2 -> V_111 -> V_39 , L_104 ,
V_2 -> V_17 -> V_40 ) ;
return V_43 ;
}
F_8 ( V_2 -> V_111 -> V_39 , L_105 , V_211 , V_214 ) ;
F_117 ( & V_2 -> V_104 , F_39 ) ;
V_213 -> V_220 = V_2 -> V_17 -> V_220 ;
V_2 -> V_213 = V_213 ;
V_213 -> V_42 = V_2 ;
if ( V_2 -> V_17 -> V_96 ) {
if ( V_65 )
V_213 -> V_221 [ V_8 ] . V_20 -> V_42 = V_2 ;
if ( V_67 )
V_213 -> V_221 [ V_109 ] . V_20 -> V_42 = V_2 ;
goto V_88;
}
if ( V_2 -> V_17 -> V_95 ) {
V_2 -> V_86 . V_89 = F_112 ;
V_2 -> V_86 . V_117 = F_96 ;
V_2 -> V_86 . V_110 = F_101 ;
V_2 -> V_86 . V_123 = F_99 ;
V_2 -> V_86 . V_121 = F_93 ;
V_2 -> V_86 . V_101 = F_113 ;
V_2 -> V_86 . V_128 = F_55 ;
V_2 -> V_86 . V_200 = F_103 ;
} else {
V_2 -> V_86 . V_89 = F_29 ;
V_2 -> V_86 . V_117 = F_51 ;
V_2 -> V_86 . V_110 = F_45 ;
V_2 -> V_86 . V_123 = F_53 ;
V_2 -> V_86 . V_121 = F_52 ;
V_2 -> V_86 . V_101 = F_41 ;
V_2 -> V_86 . V_128 = F_55 ;
V_2 -> V_86 . V_200 = F_103 ;
}
if ( V_83 -> V_45 -> V_86 ) {
V_2 -> V_86 . V_222 = V_83 -> V_45 -> V_86 -> V_222 ;
V_2 -> V_86 . V_223 = V_83 -> V_45 -> V_86 -> V_223 ;
V_2 -> V_86 . V_224 = V_83 -> V_45 -> V_86 -> V_224 ;
V_2 -> V_86 . V_225 = V_83 -> V_45 -> V_86 -> V_225 ;
V_2 -> V_86 . V_226 = V_83 -> V_45 -> V_86 -> V_226 ;
}
if ( V_65 )
F_118 ( V_213 , V_8 , & V_2 -> V_86 ) ;
if ( V_67 )
F_118 ( V_213 , V_109 , & V_2 -> V_86 ) ;
if ( V_83 -> V_45 -> V_227 ) {
V_43 = V_83 -> V_45 -> V_227 ( V_2 ) ;
if ( V_43 < 0 ) {
F_12 ( V_83 -> V_39 ,
L_106 ,
V_43 ) ;
return V_43 ;
}
}
V_213 -> V_228 = V_83 -> V_45 -> V_229 ;
V_88:
F_119 ( V_2 -> V_111 -> V_39 , L_107 ,
( V_2 -> V_10 > 1 ) ? L_12 : V_2 -> V_63 -> V_40 ,
V_5 -> V_40 ) ;
return V_43 ;
}
int F_120 ( struct V_1 * V_33 , int V_3 )
{
if ( V_33 -> V_37 [ V_3 ] . V_158 == V_177 )
return 1 ;
return 0 ;
}
int F_79 ( struct V_1 * V_33 ,
struct V_1 * V_38 , int V_3 )
{
if ( ( V_33 -> V_37 [ V_3 ] . V_158 == V_177 ) ||
( ( V_33 -> V_37 [ V_3 ] . V_158 == V_159 ) &&
V_38 -> V_37 [ V_3 ] . V_158 ) )
return 1 ;
return 0 ;
}
struct V_19 *
F_62 ( struct V_1 * V_38 , int V_3 )
{
return V_38 -> V_213 -> V_221 [ V_3 ] . V_20 ;
}
enum V_230
F_121 ( struct V_1 * V_38 , int V_3 )
{
return V_38 -> V_37 [ V_3 ] . V_131 ;
}
void F_122 ( struct V_1 * V_38 ,
int V_3 , enum V_230 V_131 )
{
V_38 -> V_37 [ V_3 ] . V_131 = V_131 ;
}
int F_92 ( struct V_1 * V_33 ,
struct V_1 * V_38 , int V_3 )
{
struct V_36 * V_37 ;
int V_131 ;
F_7 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_37 -> V_33 == V_33 )
continue;
V_131 = V_37 -> V_33 -> V_37 [ V_3 ] . V_131 ;
if ( V_131 == V_188 ||
V_131 == V_182 ||
V_131 == V_190 )
return 0 ;
}
return 1 ;
}
int F_95 ( struct V_1 * V_33 ,
struct V_1 * V_38 , int V_3 )
{
struct V_36 * V_37 ;
int V_131 ;
F_7 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_37 -> V_33 == V_33 )
continue;
V_131 = V_37 -> V_33 -> V_37 [ V_3 ] . V_131 ;
if ( V_131 == V_188 ||
V_131 == V_182 ||
V_131 == V_190 ||
V_131 == V_181 )
return 0 ;
}
return 1 ;
}
int F_123 ( struct V_19 * V_20 ,
int V_122 , struct V_82 * V_83 )
{
if ( V_83 -> V_45 -> V_86 && V_83 -> V_45 -> V_86 -> V_123 )
return V_83 -> V_45 -> V_86 -> V_123 ( V_20 , V_122 ) ;
return 0 ;
}
static char * F_124 ( enum V_230 V_131 )
{
switch ( V_131 ) {
case V_171 :
return L_108 ;
case V_167 :
return L_109 ;
case V_180 :
return L_110 ;
case V_181 :
return L_111 ;
case V_188 :
return L_112 ;
case V_183 :
return L_113 ;
case V_190 :
return L_114 ;
case V_182 :
return L_115 ;
case V_179 :
return L_116 ;
case V_168 :
return L_117 ;
}
return L_118 ;
}
static T_4 F_125 ( struct V_1 * V_33 ,
int V_3 , char * V_231 , T_5 V_232 )
{
struct V_54 * V_55 = & V_33 -> V_37 [ V_3 ] . V_117 ;
struct V_36 * V_37 ;
T_4 V_125 = 0 ;
V_125 += snprintf ( V_231 + V_125 , V_232 - V_125 ,
L_119 , V_33 -> V_17 -> V_40 ,
V_3 ? L_120 : L_121 ) ;
V_125 += snprintf ( V_231 + V_125 , V_232 - V_125 , L_122 ,
F_124 ( V_33 -> V_37 [ V_3 ] . V_131 ) ) ;
if ( ( V_33 -> V_37 [ V_3 ] . V_131 >= V_180 ) &&
( V_33 -> V_37 [ V_3 ] . V_131 <= V_183 ) )
V_125 += snprintf ( V_231 + V_125 , V_232 - V_125 ,
L_123
L_124 ,
F_126 ( F_17 ( V_55 ) ) ,
F_15 ( V_55 ) ,
F_14 ( V_55 ) ) ;
V_125 += snprintf ( V_231 + V_125 , V_232 - V_125 , L_125 ) ;
if ( F_102 ( & V_33 -> V_37 [ V_3 ] . V_134 ) ) {
V_125 += snprintf ( V_231 + V_125 , V_232 - V_125 ,
L_126 ) ;
goto V_88;
}
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
V_55 = & V_37 -> V_117 ;
V_125 += snprintf ( V_231 + V_125 , V_232 - V_125 ,
L_127 , V_38 -> V_17 -> V_40 ) ;
V_125 += snprintf ( V_231 + V_125 , V_232 - V_125 ,
L_128 ,
F_124 ( V_38 -> V_37 [ V_3 ] . V_131 ) ) ;
if ( ( V_38 -> V_37 [ V_3 ] . V_131 >= V_180 ) &&
( V_38 -> V_37 [ V_3 ] . V_131 <= V_183 ) )
V_125 += snprintf ( V_231 + V_125 , V_232 - V_125 ,
L_129
L_124 ,
F_126 ( F_17 ( V_55 ) ) ,
F_15 ( V_55 ) ,
F_14 ( V_55 ) ) ;
}
V_88:
return V_125 ;
}
static T_4 F_127 ( struct V_233 * V_233 , char T_6 * V_234 ,
T_5 V_169 , T_7 * V_235 )
{
struct V_1 * V_33 = V_233 -> V_42 ;
T_4 V_236 = V_237 , V_125 = 0 , V_43 = 0 ;
char * V_231 ;
V_231 = F_128 ( V_236 , V_129 ) ;
if ( ! V_231 )
return - V_130 ;
if ( V_33 -> V_5 -> V_45 -> V_65 . V_80 )
V_125 += F_125 ( V_33 , V_8 ,
V_231 + V_125 , V_236 - V_125 ) ;
if ( V_33 -> V_5 -> V_45 -> V_67 . V_80 )
V_125 += F_125 ( V_33 , V_109 ,
V_231 + V_125 , V_236 - V_125 ) ;
V_43 = F_129 ( V_234 , V_169 , V_235 , V_231 , V_125 ) ;
F_67 ( V_231 ) ;
return V_43 ;
}
void F_130 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_17 )
return;
if ( ! V_2 -> V_111 -> V_238 )
return;
V_2 -> V_137 = F_131 ( V_2 -> V_17 -> V_40 ,
V_2 -> V_111 -> V_238 ) ;
if ( ! V_2 -> V_137 ) {
F_8 ( V_2 -> V_39 ,
L_130 ,
V_2 -> V_17 -> V_40 ) ;
return;
}
V_2 -> V_239 = F_132 ( L_131 , 0444 ,
V_2 -> V_137 ,
V_2 , & V_240 ) ;
}
