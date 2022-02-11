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
int V_43 , V_6 ;
if ( ! V_62 )
return;
for ( V_6 = 0 ; V_6 < F_20 ( V_63 ) ; V_6 ++ ) {
if ( V_62 >= V_63 [ V_6 ] )
continue;
V_43 = F_21 ( V_20 -> V_24 , 0 ,
V_63 [ V_6 ] , V_62 ) ;
if ( V_43 != 0 )
F_22 ( V_2 -> V_39 ,
L_11 ,
V_62 , V_63 [ V_6 ] , V_43 ) ;
}
}
static void F_23 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_64 ;
int V_6 ;
unsigned int V_62 = 0 , V_65 ;
if ( V_20 -> V_3 == V_8 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_64 = V_2 -> V_11 [ V_6 ] ;
if ( V_64 -> V_45 -> V_66 . V_67 == 0 ) {
V_62 = 0 ;
break;
}
V_62 = F_24 ( V_64 -> V_45 -> V_66 . V_67 , V_62 ) ;
}
V_65 = V_5 -> V_45 -> V_66 . V_67 ;
} else {
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_64 = V_2 -> V_11 [ V_6 ] ;
if ( V_64 -> V_45 -> V_68 . V_67 == 0 ) {
V_62 = 0 ;
break;
}
V_62 = F_24 ( V_64 -> V_45 -> V_68 . V_67 , V_62 ) ;
}
V_65 = V_5 -> V_45 -> V_68 . V_67 ;
}
F_19 ( V_20 , V_62 ) ;
F_19 ( V_20 , V_65 ) ;
}
static void F_25 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = V_20 -> V_24 ;
struct V_21 * V_22 = & V_24 -> V_22 ;
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_58 * V_69 = V_2 -> V_5 -> V_45 ;
struct V_58 * V_70 ;
struct V_71 * V_72 ;
struct V_71 * V_73 ;
unsigned int V_74 = 0 , V_75 = V_76 ;
unsigned int V_77 = 0 , V_78 = V_76 ;
unsigned int V_79 = V_76 ;
T_1 V_26 = V_80 ;
int V_6 ;
if ( V_20 -> V_3 == V_8 )
V_73 = & V_69 -> V_66 ;
else
V_73 = & V_69 -> V_68 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_70 = V_2 -> V_11 [ V_6 ] -> V_45 ;
if ( V_20 -> V_3 == V_8 )
V_72 = & V_70 -> V_66 ;
else
V_72 = & V_70 -> V_68 ;
V_74 = F_24 ( V_74 , V_72 -> V_81 ) ;
V_75 = F_26 ( V_75 , V_72 -> V_82 ) ;
V_77 = F_24 ( V_77 , V_72 -> V_77 ) ;
V_78 = F_27 ( V_78 , V_72 -> V_78 ) ;
V_26 &= V_72 -> V_26 ;
V_79 = F_28 ( V_72 -> V_79 , V_79 ) ;
}
if ( V_2 -> V_10 > 1 ) {
V_74 = V_73 -> V_81 ;
V_75 = V_73 -> V_82 ;
}
V_22 -> V_81 = F_24 ( V_74 , V_73 -> V_81 ) ;
V_22 -> V_82 = F_26 ( V_75 , V_73 -> V_82 ) ;
if ( V_22 -> V_26 )
V_22 -> V_26 &= V_26 & V_73 -> V_26 ;
else
V_22 -> V_26 = V_26 & V_73 -> V_26 ;
V_22 -> V_79 = F_28 ( V_79 , V_73 -> V_79 ) ;
F_29 ( V_24 ) ;
V_22 -> V_77 = F_24 ( V_22 -> V_77 , V_73 -> V_77 ) ;
V_22 -> V_77 = F_24 ( V_22 -> V_77 , V_77 ) ;
V_22 -> V_78 = F_27 ( V_22 -> V_78 , V_73 -> V_78 ) ;
V_22 -> V_78 = F_27 ( V_22 -> V_78 , V_78 ) ;
}
static int F_30 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_23 * V_24 = V_20 -> V_24 ;
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_64 ;
const char * V_85 = L_12 ;
int V_6 , V_43 = 0 ;
F_31 ( V_5 -> V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
F_31 ( V_2 -> V_11 [ V_6 ] -> V_39 ) ;
F_32 ( V_5 -> V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
F_32 ( V_2 -> V_11 [ V_6 ] -> V_39 ) ;
F_32 ( V_84 -> V_39 ) ;
F_33 ( & V_2 -> V_7 , V_2 -> V_86 ) ;
if ( V_5 -> V_45 -> V_87 && V_5 -> V_45 -> V_87 -> V_88 ) {
V_43 = V_5 -> V_45 -> V_87 -> V_88 ( V_20 , V_5 ) ;
if ( V_43 < 0 ) {
F_12 ( V_5 -> V_39 , L_13
L_14 , V_5 -> V_40 , V_43 ) ;
goto V_89;
}
}
if ( V_84 -> V_45 -> V_87 && V_84 -> V_45 -> V_87 -> V_90 ) {
V_43 = V_84 -> V_45 -> V_87 -> V_90 ( V_20 ) ;
if ( V_43 < 0 ) {
F_12 ( V_84 -> V_39 , L_15
L_14 , V_84 -> V_14 . V_40 , V_43 ) ;
goto V_91;
}
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_64 = V_2 -> V_11 [ V_6 ] ;
if ( V_64 -> V_45 -> V_87 && V_64 -> V_45 -> V_87 -> V_88 ) {
V_43 = V_64 -> V_45 -> V_87 -> V_88 ( V_20 ,
V_64 ) ;
if ( V_43 < 0 ) {
F_12 ( V_64 -> V_39 ,
L_16 ,
V_64 -> V_40 , V_43 ) ;
goto V_92;
}
}
if ( V_20 -> V_3 == V_8 )
V_64 -> V_93 = 0 ;
else
V_64 -> V_94 = 0 ;
}
if ( V_2 -> V_17 -> V_87 && V_2 -> V_17 -> V_87 -> V_88 ) {
V_43 = V_2 -> V_17 -> V_87 -> V_88 ( V_20 ) ;
if ( V_43 < 0 ) {
F_34 ( L_17 ,
V_2 -> V_17 -> V_40 , V_43 ) ;
goto V_95;
}
}
if ( V_2 -> V_17 -> V_96 || V_2 -> V_17 -> V_97 )
goto V_96;
F_25 ( V_20 ) ;
if ( V_2 -> V_10 == 1 )
V_85 = V_2 -> V_64 -> V_40 ;
if ( F_18 ( V_20 ) )
V_24 -> V_22 . V_25 |= V_98 ;
V_43 = - V_57 ;
if ( ! V_24 -> V_22 . V_79 ) {
F_35 ( V_99 L_18 ,
V_85 , V_5 -> V_40 ) ;
goto V_100;
}
if ( ! V_24 -> V_22 . V_26 ) {
F_35 ( V_99 L_19 ,
V_85 , V_5 -> V_40 ) ;
goto V_100;
}
if ( ! V_24 -> V_22 . V_81 || ! V_24 -> V_22 . V_82 ||
V_24 -> V_22 . V_81 > V_24 -> V_22 . V_82 ) {
F_35 ( V_99 L_20 ,
V_85 , V_5 -> V_40 ) ;
goto V_100;
}
F_23 ( V_20 ) ;
if ( V_5 -> V_13 ) {
V_43 = F_10 ( V_20 , V_5 ) ;
if ( V_43 != 0 )
goto V_100;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
if ( V_2 -> V_11 [ V_6 ] -> V_13 ) {
V_43 = F_10 ( V_20 ,
V_2 -> V_11 [ V_6 ] ) ;
if ( V_43 != 0 )
goto V_100;
}
}
F_36 ( L_21 ,
V_85 , V_5 -> V_40 ) ;
F_36 ( L_22 , V_24 -> V_22 . V_79 ) ;
F_36 ( L_23 , V_24 -> V_22 . V_81 ,
V_24 -> V_22 . V_82 ) ;
F_36 ( L_24 , V_24 -> V_22 . V_77 ,
V_24 -> V_22 . V_78 ) ;
V_96:
F_1 ( V_2 , V_20 -> V_3 ) ;
F_37 ( & V_2 -> V_7 ) ;
return 0 ;
V_100:
if ( V_2 -> V_17 -> V_87 && V_2 -> V_17 -> V_87 -> V_101 )
V_2 -> V_17 -> V_87 -> V_101 ( V_20 ) ;
V_95:
V_6 = V_2 -> V_10 ;
V_92:
while ( -- V_6 >= 0 ) {
V_64 = V_2 -> V_11 [ V_6 ] ;
if ( V_64 -> V_45 -> V_87 -> V_101 )
V_64 -> V_45 -> V_87 -> V_101 ( V_20 , V_64 ) ;
}
if ( V_84 -> V_45 -> V_87 && V_84 -> V_45 -> V_87 -> V_102 )
V_84 -> V_45 -> V_87 -> V_102 ( V_20 ) ;
V_91:
if ( V_5 -> V_45 -> V_87 -> V_101 )
V_5 -> V_45 -> V_87 -> V_101 ( V_20 , V_5 ) ;
V_89:
F_37 ( & V_2 -> V_7 ) ;
F_38 ( V_84 -> V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
F_38 ( V_2 -> V_11 [ V_6 ] -> V_39 ) ;
F_38 ( V_5 -> V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
if ( ! V_2 -> V_11 [ V_6 ] -> V_13 )
F_39 ( V_2 -> V_11 [ V_6 ] -> V_39 ) ;
}
if ( ! V_5 -> V_13 )
F_39 ( V_5 -> V_39 ) ;
return V_43 ;
}
static void F_40 ( struct V_103 * V_104 )
{
struct V_1 * V_2 =
F_41 ( V_104 , struct V_1 , V_105 . V_104 ) ;
struct V_4 * V_64 = V_2 -> V_11 [ 0 ] ;
F_33 ( & V_2 -> V_7 , V_2 -> V_86 ) ;
F_8 ( V_2 -> V_39 , L_25 ,
V_64 -> V_45 -> V_66 . V_106 ,
V_64 -> V_9 ? L_26 : L_27 ,
V_2 -> V_107 ? L_28 : L_29 ) ;
if ( V_2 -> V_107 == 1 ) {
V_2 -> V_107 = 0 ;
F_9 ( V_2 , V_8 ,
V_108 ) ;
}
F_37 ( & V_2 -> V_7 ) ;
}
static int F_42 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_64 ;
int V_6 ;
F_33 ( & V_2 -> V_7 , V_2 -> V_86 ) ;
F_3 ( V_2 , V_20 -> V_3 ) ;
if ( ! V_5 -> V_13 )
V_5 -> V_44 = 0 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_64 = V_2 -> V_11 [ V_6 ] ;
if ( ! V_64 -> V_13 )
V_64 -> V_44 = 0 ;
}
F_43 ( V_5 , 1 , V_20 -> V_3 ) ;
if ( V_5 -> V_45 -> V_87 -> V_101 )
V_5 -> V_45 -> V_87 -> V_101 ( V_20 , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_64 = V_2 -> V_11 [ V_6 ] ;
if ( V_64 -> V_45 -> V_87 -> V_101 )
V_64 -> V_45 -> V_87 -> V_101 ( V_20 , V_64 ) ;
}
if ( V_2 -> V_17 -> V_87 && V_2 -> V_17 -> V_87 -> V_101 )
V_2 -> V_17 -> V_87 -> V_101 ( V_20 ) ;
if ( V_84 -> V_45 -> V_87 && V_84 -> V_45 -> V_87 -> V_102 )
V_84 -> V_45 -> V_87 -> V_102 ( V_20 ) ;
if ( V_20 -> V_3 == V_8 ) {
if ( F_4 ( V_2 ) ) {
F_9 ( V_2 ,
V_8 ,
V_108 ) ;
} else {
V_2 -> V_107 = 1 ;
F_44 ( V_109 ,
& V_2 -> V_105 ,
F_45 ( V_2 -> V_16 ) ) ;
}
} else {
F_9 ( V_2 , V_110 ,
V_108 ) ;
}
F_37 ( & V_2 -> V_7 ) ;
F_38 ( V_84 -> V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
F_38 ( V_2 -> V_11 [ V_6 ] -> V_39 ) ;
F_38 ( V_5 -> V_39 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
if ( ! V_2 -> V_11 [ V_6 ] -> V_13 )
F_39 ( V_2 -> V_11 [ V_6 ] -> V_39 ) ;
}
if ( ! V_5 -> V_13 )
F_39 ( V_5 -> V_39 ) ;
return 0 ;
}
static int F_46 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_64 ;
int V_6 , V_43 = 0 ;
F_33 ( & V_2 -> V_7 , V_2 -> V_86 ) ;
if ( V_2 -> V_17 -> V_87 && V_2 -> V_17 -> V_87 -> V_111 ) {
V_43 = V_2 -> V_17 -> V_87 -> V_111 ( V_20 ) ;
if ( V_43 < 0 ) {
F_12 ( V_2 -> V_112 -> V_39 , L_30
L_31 , V_43 ) ;
goto V_89;
}
}
if ( V_84 -> V_45 -> V_87 && V_84 -> V_45 -> V_87 -> V_111 ) {
V_43 = V_84 -> V_45 -> V_87 -> V_111 ( V_20 ) ;
if ( V_43 < 0 ) {
F_12 ( V_84 -> V_39 , L_32
L_31 , V_43 ) ;
goto V_89;
}
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_64 = V_2 -> V_11 [ V_6 ] ;
if ( V_64 -> V_45 -> V_87 && V_64 -> V_45 -> V_87 -> V_111 ) {
V_43 = V_64 -> V_45 -> V_87 -> V_111 ( V_20 ,
V_64 ) ;
if ( V_43 < 0 ) {
F_12 ( V_64 -> V_39 ,
L_33 , V_43 ) ;
goto V_89;
}
}
}
if ( V_5 -> V_45 -> V_87 && V_5 -> V_45 -> V_87 -> V_111 ) {
V_43 = V_5 -> V_45 -> V_87 -> V_111 ( V_20 , V_5 ) ;
if ( V_43 < 0 ) {
F_12 ( V_5 -> V_39 , L_33 ,
V_43 ) ;
goto V_89;
}
}
if ( V_20 -> V_3 == V_8 &&
V_2 -> V_107 ) {
V_2 -> V_107 = 0 ;
F_47 ( & V_2 -> V_105 ) ;
}
F_9 ( V_2 , V_20 -> V_3 ,
V_113 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ )
F_43 ( V_2 -> V_11 [ V_6 ] , 0 ,
V_20 -> V_3 ) ;
F_43 ( V_5 , 0 , V_20 -> V_3 ) ;
V_89:
F_37 ( & V_2 -> V_7 ) ;
return V_43 ;
}
static void F_48 ( struct V_54 * V_55 ,
unsigned int V_114 )
{
struct V_115 * V_116 ;
int V_48 = F_49 ( V_114 ) ;
V_116 = F_50 ( V_55 , V_50 ) ;
V_116 -> F_26 = V_48 ;
V_116 -> F_24 = V_48 ;
}
int F_51 ( struct V_19 * V_20 ,
struct V_54 * V_55 ,
struct V_4 * V_117 )
{
int V_43 ;
if ( V_117 -> V_45 -> V_87 && V_117 -> V_45 -> V_87 -> V_118 ) {
V_43 = V_117 -> V_45 -> V_87 -> V_118 ( V_20 , V_55 , V_117 ) ;
if ( V_43 < 0 ) {
F_12 ( V_117 -> V_39 , L_34 ,
V_117 -> V_40 , V_43 ) ;
return V_43 ;
}
}
return 0 ;
}
static int F_52 ( struct V_19 * V_20 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 , V_43 = 0 ;
F_33 ( & V_2 -> V_7 , V_2 -> V_86 ) ;
V_43 = F_13 ( V_20 , V_55 ) ;
if ( V_43 )
goto V_89;
if ( V_2 -> V_17 -> V_87 && V_2 -> V_17 -> V_87 -> V_118 ) {
V_43 = V_2 -> V_17 -> V_87 -> V_118 ( V_20 , V_55 ) ;
if ( V_43 < 0 ) {
F_12 ( V_2 -> V_112 -> V_39 , L_35
L_36 , V_43 ) ;
goto V_89;
}
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
struct V_4 * V_64 = V_2 -> V_11 [ V_6 ] ;
struct V_54 V_119 ;
V_119 = * V_55 ;
if ( V_64 -> V_93 )
F_48 ( & V_119 ,
V_64 -> V_93 ) ;
if ( V_64 -> V_94 )
F_48 ( & V_119 ,
V_64 -> V_94 ) ;
V_43 = F_51 ( V_20 , & V_119 , V_64 ) ;
if( V_43 < 0 )
goto V_120;
V_64 -> V_44 = F_14 ( & V_119 ) ;
V_64 -> V_48 = F_15 ( & V_119 ) ;
V_64 -> V_51 = F_16 (
F_17 ( & V_119 ) ) ;
}
V_43 = F_51 ( V_20 , V_55 , V_5 ) ;
if ( V_43 < 0 )
goto V_121;
if ( V_84 -> V_45 -> V_87 && V_84 -> V_45 -> V_87 -> V_118 ) {
V_43 = V_84 -> V_45 -> V_87 -> V_118 ( V_20 , V_55 ) ;
if ( V_43 < 0 ) {
F_12 ( V_84 -> V_39 , L_37 ,
V_84 -> V_14 . V_40 , V_43 ) ;
goto V_91;
}
}
V_5 -> V_44 = F_14 ( V_55 ) ;
V_5 -> V_48 = F_15 ( V_55 ) ;
V_5 -> V_51 =
F_16 ( F_17 ( V_55 ) ) ;
V_89:
F_37 ( & V_2 -> V_7 ) ;
return V_43 ;
V_91:
if ( V_5 -> V_45 -> V_87 && V_5 -> V_45 -> V_87 -> V_122 )
V_5 -> V_45 -> V_87 -> V_122 ( V_20 , V_5 ) ;
V_121:
V_6 = V_2 -> V_10 ;
V_120:
while ( -- V_6 >= 0 ) {
struct V_4 * V_64 = V_2 -> V_11 [ V_6 ] ;
if ( V_64 -> V_45 -> V_87 && V_64 -> V_45 -> V_87 -> V_122 )
V_64 -> V_45 -> V_87 -> V_122 ( V_20 , V_64 ) ;
V_64 -> V_44 = 0 ;
}
if ( V_2 -> V_17 -> V_87 && V_2 -> V_17 -> V_87 -> V_122 )
V_2 -> V_17 -> V_87 -> V_122 ( V_20 ) ;
F_37 ( & V_2 -> V_7 ) ;
return V_43 ;
}
static int F_53 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_64 ;
bool V_66 = V_20 -> V_3 == V_8 ;
int V_6 ;
F_33 ( & V_2 -> V_7 , V_2 -> V_86 ) ;
if ( V_5 -> V_13 == 1 ) {
V_5 -> V_44 = 0 ;
V_5 -> V_48 = 0 ;
V_5 -> V_51 = 0 ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_64 = V_2 -> V_11 [ V_6 ] ;
if ( V_64 -> V_13 == 1 ) {
V_64 -> V_44 = 0 ;
V_64 -> V_48 = 0 ;
V_64 -> V_51 = 0 ;
}
}
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
if ( ( V_66 && V_2 -> V_11 [ V_6 ] -> V_9 == 1 ) ||
( ! V_66 && V_2 -> V_11 [ V_6 ] -> V_12 == 1 ) )
F_43 ( V_2 -> V_11 [ V_6 ] , 1 ,
V_20 -> V_3 ) ;
}
if ( V_2 -> V_17 -> V_87 && V_2 -> V_17 -> V_87 -> V_122 )
V_2 -> V_17 -> V_87 -> V_122 ( V_20 ) ;
if ( V_84 -> V_45 -> V_87 && V_84 -> V_45 -> V_87 -> V_122 )
V_84 -> V_45 -> V_87 -> V_122 ( V_20 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_64 = V_2 -> V_11 [ V_6 ] ;
if ( V_64 -> V_45 -> V_87 && V_64 -> V_45 -> V_87 -> V_122 )
V_64 -> V_45 -> V_87 -> V_122 ( V_20 , V_64 ) ;
}
if ( V_5 -> V_45 -> V_87 && V_5 -> V_45 -> V_87 -> V_122 )
V_5 -> V_45 -> V_87 -> V_122 ( V_20 , V_5 ) ;
F_37 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_54 ( struct V_19 * V_20 , int V_123 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_64 ;
int V_6 , V_43 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_64 = V_2 -> V_11 [ V_6 ] ;
if ( V_64 -> V_45 -> V_87 && V_64 -> V_45 -> V_87 -> V_124 ) {
V_43 = V_64 -> V_45 -> V_87 -> V_124 ( V_20 ,
V_123 , V_64 ) ;
if ( V_43 < 0 )
return V_43 ;
}
}
if ( V_84 -> V_45 -> V_87 && V_84 -> V_45 -> V_87 -> V_124 ) {
V_43 = V_84 -> V_45 -> V_87 -> V_124 ( V_20 , V_123 ) ;
if ( V_43 < 0 )
return V_43 ;
}
if ( V_5 -> V_45 -> V_87 && V_5 -> V_45 -> V_87 -> V_124 ) {
V_43 = V_5 -> V_45 -> V_87 -> V_124 ( V_20 , V_123 , V_5 ) ;
if ( V_43 < 0 )
return V_43 ;
}
if ( V_2 -> V_17 -> V_87 && V_2 -> V_17 -> V_87 -> V_124 ) {
V_43 = V_2 -> V_17 -> V_87 -> V_124 ( V_20 , V_123 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return 0 ;
}
static int F_55 ( struct V_19 * V_20 ,
int V_123 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_64 ;
int V_6 , V_43 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_64 = V_2 -> V_11 [ V_6 ] ;
if ( V_64 -> V_45 -> V_87 &&
V_64 -> V_45 -> V_87 -> V_125 ) {
V_43 = V_64 -> V_45 -> V_87 -> V_125 ( V_20 ,
V_123 , V_64 ) ;
if ( V_43 < 0 )
return V_43 ;
}
}
if ( V_84 -> V_45 -> V_125 ) {
V_43 = V_84 -> V_45 -> V_125 ( V_20 , V_123 ) ;
if ( V_43 < 0 )
return V_43 ;
}
if ( V_5 -> V_45 -> V_87 && V_5 -> V_45 -> V_87 -> V_125 ) {
V_43 = V_5 -> V_45 -> V_87 -> V_125 ( V_20 , V_123 , V_5 ) ;
if ( V_43 < 0 )
return V_43 ;
}
return 0 ;
}
static T_2 F_56 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_4 * V_64 ;
struct V_23 * V_24 = V_20 -> V_24 ;
T_2 V_126 = 0 ;
T_3 V_127 = 0 ;
T_3 V_128 = 0 ;
int V_6 ;
if ( V_84 -> V_45 -> V_87 && V_84 -> V_45 -> V_87 -> V_129 )
V_126 = V_84 -> V_45 -> V_87 -> V_129 ( V_20 ) ;
if ( V_5 -> V_45 -> V_87 && V_5 -> V_45 -> V_87 -> V_127 )
V_127 += V_5 -> V_45 -> V_87 -> V_127 ( V_20 , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_64 = V_2 -> V_11 [ V_6 ] ;
if ( V_64 -> V_45 -> V_87 && V_64 -> V_45 -> V_87 -> V_127 )
V_128 = F_24 ( V_128 ,
V_64 -> V_45 -> V_87 -> V_127 ( V_20 ,
V_64 ) ) ;
}
V_127 += V_128 ;
if ( V_84 -> V_45 -> V_127 )
V_127 += V_84 -> V_45 -> V_127 ( V_20 , V_2 -> V_11 [ 0 ] ) ;
V_24 -> V_127 = V_127 ;
return V_126 ;
}
static int F_57 ( struct V_1 * V_33 ,
struct V_1 * V_38 , int V_3 )
{
struct V_36 * V_37 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
if ( V_37 -> V_38 == V_38 && V_37 -> V_33 == V_33 )
return 0 ;
}
V_37 = F_58 ( sizeof( struct V_36 ) , V_130 ) ;
if ( ! V_37 )
return - V_131 ;
V_37 -> V_38 = V_38 ;
V_37 -> V_33 = V_33 ;
V_38 -> V_37 [ V_3 ] . V_24 = V_33 -> V_37 [ V_3 ] . V_24 ;
V_37 -> V_132 = V_133 ;
F_59 ( & V_37 -> V_134 , & V_33 -> V_37 [ V_3 ] . V_135 ) ;
F_59 ( & V_37 -> V_136 , & V_38 -> V_37 [ V_3 ] . V_137 ) ;
F_8 ( V_33 -> V_39 , L_38 ,
V_3 ? L_39 : L_40 , V_33 -> V_17 -> V_40 ,
V_3 ? L_41 : L_42 , V_38 -> V_17 -> V_40 ) ;
#ifdef F_60
V_37 -> V_138 = F_61 ( V_38 -> V_17 -> V_40 , 0644 ,
V_33 -> V_139 , & V_37 -> V_132 ) ;
#endif
return 1 ;
}
static void F_62 ( struct V_1 * V_33 ,
struct V_1 * V_38 , int V_3 )
{
struct V_36 * V_37 ;
struct V_19 * V_140 , * V_141 ;
if ( ! V_38 -> V_37 [ V_3 ] . V_142 )
return;
V_141 = F_63 ( V_38 , V_3 ) ;
F_7 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_37 -> V_33 == V_33 )
continue;
F_8 ( V_33 -> V_39 , L_43 ,
V_3 ? L_39 : L_40 ,
V_37 -> V_33 -> V_17 -> V_40 ,
V_3 ? L_41 : L_42 , V_37 -> V_38 -> V_17 -> V_40 ) ;
V_140 = F_63 ( V_37 -> V_33 , V_3 ) ;
V_141 -> V_24 = V_140 -> V_24 ;
break;
}
}
void F_64 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 , * V_143 ;
F_65 (dpcm, d, &fe->dpcm[stream].be_clients, list_be) {
F_8 ( V_33 -> V_39 , L_44 ,
V_3 ? L_39 : L_40 ,
V_37 -> V_38 -> V_17 -> V_40 ) ;
if ( V_37 -> V_132 != V_144 )
continue;
F_8 ( V_33 -> V_39 , L_45 ,
V_3 ? L_39 : L_40 , V_33 -> V_17 -> V_40 ,
V_3 ? L_41 : L_42 , V_37 -> V_38 -> V_17 -> V_40 ) ;
F_62 ( V_33 , V_37 -> V_38 , V_3 ) ;
#ifdef F_60
F_66 ( V_37 -> V_138 ) ;
#endif
F_67 ( & V_37 -> V_134 ) ;
F_67 ( & V_37 -> V_136 ) ;
F_68 ( V_37 ) ;
}
}
static struct V_1 * F_69 ( struct V_145 * V_112 ,
struct V_146 * V_147 , int V_3 )
{
struct V_1 * V_38 ;
int V_6 , V_148 ;
if ( V_3 == V_8 ) {
for ( V_6 = 0 ; V_6 < V_112 -> V_149 ; V_6 ++ ) {
V_38 = & V_112 -> V_2 [ V_6 ] ;
if ( ! V_38 -> V_17 -> V_97 )
continue;
if ( V_38 -> V_5 -> V_150 == V_147 )
return V_38 ;
for ( V_148 = 0 ; V_148 < V_38 -> V_10 ; V_148 ++ ) {
struct V_4 * V_117 = V_38 -> V_11 [ V_148 ] ;
if ( V_117 -> V_150 == V_147 )
return V_38 ;
}
}
} else {
for ( V_6 = 0 ; V_6 < V_112 -> V_149 ; V_6 ++ ) {
V_38 = & V_112 -> V_2 [ V_6 ] ;
if ( ! V_38 -> V_17 -> V_97 )
continue;
if ( V_38 -> V_5 -> V_151 == V_147 )
return V_38 ;
for ( V_148 = 0 ; V_148 < V_38 -> V_10 ; V_148 ++ ) {
struct V_4 * V_117 = V_38 -> V_11 [ V_148 ] ;
if ( V_117 -> V_151 == V_147 )
return V_38 ;
}
}
}
F_12 ( V_112 -> V_39 , L_46 ,
V_3 ? L_39 : L_40 , V_147 -> V_40 ) ;
return NULL ;
}
static inline struct V_146 *
F_70 ( struct V_4 * V_117 , int V_3 )
{
if ( V_3 == V_8 )
return V_117 -> V_150 ;
else
return V_117 -> V_151 ;
}
static int F_71 ( struct V_152 * V_153 ,
struct V_146 * V_147 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_153 -> V_154 ; V_6 ++ ) {
if ( V_147 == V_153 -> V_155 [ V_6 ] )
return 1 ;
}
return 0 ;
}
int F_72 ( struct V_1 * V_33 ,
int V_3 , struct V_152 * * V_156 )
{
struct V_4 * V_5 = V_33 -> V_5 ;
struct V_152 * V_153 ;
int V_157 ;
V_153 = F_58 ( sizeof( struct V_152 ) +
sizeof( struct V_146 * ) , V_130 ) ;
if ( V_153 == NULL )
return - V_131 ;
V_157 = F_73 ( V_5 , V_3 , & V_153 ) ;
F_8 ( V_33 -> V_39 , L_47 , V_157 ,
V_3 ? L_39 : L_40 ) ;
* V_156 = V_153 ;
return V_157 ;
}
static int F_74 ( struct V_1 * V_33 , int V_3 ,
struct V_152 * * V_156 )
{
struct V_36 * V_37 ;
struct V_152 * V_153 = * V_156 ;
struct V_146 * V_147 ;
int V_158 = 0 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
unsigned int V_6 ;
V_147 = F_70 ( V_37 -> V_38 -> V_5 , V_3 ) ;
if ( V_147 && F_71 ( V_153 , V_147 ) )
continue;
for ( V_6 = 0 ; V_6 < V_37 -> V_38 -> V_10 ; V_6 ++ ) {
struct V_4 * V_117 = V_37 -> V_38 -> V_11 [ V_6 ] ;
V_147 = F_70 ( V_117 , V_3 ) ;
if ( V_147 && F_71 ( V_153 , V_147 ) )
continue;
}
F_8 ( V_33 -> V_39 , L_48 ,
V_3 ? L_39 : L_40 ,
V_37 -> V_38 -> V_17 -> V_40 , V_33 -> V_17 -> V_40 ) ;
V_37 -> V_132 = V_144 ;
V_37 -> V_38 -> V_37 [ V_3 ] . V_159 = V_160 ;
V_158 ++ ;
}
F_8 ( V_33 -> V_39 , L_49 , V_158 ) ;
return V_158 ;
}
static int F_75 ( struct V_1 * V_33 , int V_3 ,
struct V_152 * * V_156 )
{
struct V_145 * V_112 = V_33 -> V_112 ;
struct V_152 * V_153 = * V_156 ;
struct V_1 * V_38 ;
int V_6 , V_161 = 0 , V_162 ;
for ( V_6 = 0 ; V_6 < V_153 -> V_154 ; V_6 ++ ) {
switch ( V_153 -> V_155 [ V_6 ] -> V_163 ) {
case V_164 :
case V_165 :
break;
default:
continue;
}
V_38 = F_69 ( V_112 , V_153 -> V_155 [ V_6 ] , V_3 ) ;
if ( ! V_38 ) {
F_12 ( V_33 -> V_39 , L_50 ,
V_153 -> V_155 [ V_6 ] -> V_40 ) ;
continue;
}
if ( ! V_38 -> V_17 -> V_97 )
continue;
if ( ! V_33 -> V_37 [ V_3 ] . V_24 && ! V_33 -> V_166 )
continue;
V_162 = F_57 ( V_33 , V_38 , V_3 ) ;
if ( V_162 < 0 ) {
F_12 ( V_33 -> V_39 , L_51 ,
V_153 -> V_155 [ V_6 ] -> V_40 ) ;
break;
} else if ( V_162 == 0 )
continue;
V_38 -> V_37 [ V_3 ] . V_159 = V_160 ;
V_161 ++ ;
}
F_8 ( V_33 -> V_39 , L_52 , V_161 ) ;
return V_161 ;
}
int F_76 ( struct V_1 * V_33 ,
int V_3 , struct V_152 * * V_153 , int V_161 )
{
if ( V_161 )
return F_75 ( V_33 , V_3 , V_153 ) ;
else
return F_74 ( V_33 , V_3 , V_153 ) ;
}
void F_77 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_37 -> V_38 -> V_37 [ V_3 ] . V_159 =
V_167 ;
}
static void F_78 ( struct V_1 * V_33 ,
int V_3 )
{
struct V_36 * V_37 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_141 =
F_63 ( V_38 , V_3 ) ;
if ( V_38 -> V_37 [ V_3 ] . V_142 == 0 )
F_12 ( V_38 -> V_39 , L_53 ,
V_3 ? L_39 : L_40 ,
V_38 -> V_37 [ V_3 ] . V_132 ) ;
if ( -- V_38 -> V_37 [ V_3 ] . V_142 != 0 )
continue;
if ( V_38 -> V_37 [ V_3 ] . V_132 != V_168 )
continue;
F_42 ( V_141 ) ;
V_141 -> V_24 = NULL ;
V_38 -> V_37 [ V_3 ] . V_132 = V_169 ;
}
}
int F_79 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 ;
int V_162 , V_170 = 0 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_141 =
F_63 ( V_38 , V_3 ) ;
if ( ! V_141 ) {
F_12 ( V_38 -> V_39 , L_54 ,
V_3 ? L_39 : L_40 ) ;
continue;
}
if ( ! F_80 ( V_33 , V_38 , V_3 ) )
continue;
if ( V_38 -> V_37 [ V_3 ] . V_142 == V_171 )
F_12 ( V_38 -> V_39 , L_55 ,
V_3 ? L_39 : L_40 ,
V_38 -> V_37 [ V_3 ] . V_132 ) ;
if ( V_38 -> V_37 [ V_3 ] . V_142 ++ != 0 )
continue;
if ( ( V_38 -> V_37 [ V_3 ] . V_132 != V_172 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 != V_169 ) )
continue;
F_8 ( V_38 -> V_39 , L_56 ,
V_3 ? L_39 : L_40 , V_38 -> V_17 -> V_40 ) ;
V_141 -> V_24 = V_38 -> V_37 [ V_3 ] . V_24 ;
V_162 = F_30 ( V_141 ) ;
if ( V_162 < 0 ) {
F_12 ( V_38 -> V_39 , L_57 , V_162 ) ;
V_38 -> V_37 [ V_3 ] . V_142 -- ;
if ( V_38 -> V_37 [ V_3 ] . V_142 < 0 )
F_12 ( V_38 -> V_39 , L_58 ,
V_3 ? L_39 : L_40 ,
V_38 -> V_37 [ V_3 ] . V_132 ) ;
V_38 -> V_37 [ V_3 ] . V_132 = V_169 ;
goto V_173;
}
V_38 -> V_37 [ V_3 ] . V_132 = V_168 ;
V_170 ++ ;
}
return V_170 ;
V_173:
F_81 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_141 =
F_63 ( V_38 , V_3 ) ;
if ( ! F_80 ( V_33 , V_38 , V_3 ) )
continue;
if ( V_38 -> V_37 [ V_3 ] . V_142 == 0 )
F_12 ( V_38 -> V_39 , L_59 ,
V_3 ? L_39 : L_40 ,
V_38 -> V_37 [ V_3 ] . V_132 ) ;
if ( -- V_38 -> V_37 [ V_3 ] . V_142 != 0 )
continue;
if ( V_38 -> V_37 [ V_3 ] . V_132 != V_168 )
continue;
F_42 ( V_141 ) ;
V_141 -> V_24 = NULL ;
V_38 -> V_37 [ V_3 ] . V_132 = V_169 ;
}
return V_162 ;
}
static void F_82 ( struct V_23 * V_24 ,
struct V_71 * V_3 )
{
V_24 -> V_22 . V_77 = V_3 -> V_77 ;
V_24 -> V_22 . V_78 = V_3 -> V_78 ;
V_24 -> V_22 . V_81 = V_3 -> V_81 ;
V_24 -> V_22 . V_82 = V_3 -> V_82 ;
if ( V_24 -> V_22 . V_26 )
V_24 -> V_22 . V_26 &= V_3 -> V_26 ;
else
V_24 -> V_22 . V_26 = V_3 -> V_26 ;
V_24 -> V_22 . V_79 = V_3 -> V_79 ;
}
static void F_83 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = V_20 -> V_24 ;
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_58 * V_69 = V_5 -> V_45 ;
if ( V_20 -> V_3 == V_8 )
F_82 ( V_24 , & V_69 -> V_66 ) ;
else
F_82 ( V_24 , & V_69 -> V_68 ) ;
}
static void F_84 ( struct V_1 * V_33 ,
int V_3 , enum V_174 V_132 )
{
struct V_19 * V_20 =
F_63 ( V_33 , V_3 ) ;
F_85 ( V_20 ) ;
if ( V_132 == V_167 && V_33 -> V_37 [ V_3 ] . V_175 ) {
F_86 ( V_20 ,
V_33 -> V_37 [ V_3 ] . V_175 - 1 ) ;
V_33 -> V_37 [ V_3 ] . V_175 = 0 ;
}
V_33 -> V_37 [ V_3 ] . V_159 = V_132 ;
F_87 ( V_20 ) ;
}
static int F_88 ( struct V_19 * V_140 )
{
struct V_1 * V_33 = V_140 -> V_42 ;
struct V_23 * V_24 = V_140 -> V_24 ;
int V_3 = V_140 -> V_3 , V_43 = 0 ;
F_84 ( V_33 , V_3 , V_176 ) ;
V_43 = F_79 ( V_33 , V_140 -> V_3 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_60 , V_43 ) ;
goto V_177;
}
F_8 ( V_33 -> V_39 , L_61 , V_33 -> V_17 -> V_40 ) ;
V_43 = F_30 ( V_140 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_62 , V_43 ) ;
goto V_173;
}
V_33 -> V_37 [ V_3 ] . V_132 = V_168 ;
F_83 ( V_140 ) ;
F_29 ( V_24 ) ;
F_84 ( V_33 , V_3 , V_167 ) ;
return 0 ;
V_173:
F_78 ( V_33 , V_140 -> V_3 ) ;
V_177:
F_84 ( V_33 , V_3 , V_167 ) ;
return V_43 ;
}
int F_89 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_141 =
F_63 ( V_38 , V_3 ) ;
if ( ! F_80 ( V_33 , V_38 , V_3 ) )
continue;
if ( V_38 -> V_37 [ V_3 ] . V_142 == 0 )
F_12 ( V_38 -> V_39 , L_53 ,
V_3 ? L_39 : L_40 ,
V_38 -> V_37 [ V_3 ] . V_132 ) ;
if ( -- V_38 -> V_37 [ V_3 ] . V_142 != 0 )
continue;
if ( ( V_38 -> V_37 [ V_3 ] . V_132 != V_178 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 != V_168 ) )
continue;
F_8 ( V_38 -> V_39 , L_63 ,
V_37 -> V_33 -> V_17 -> V_40 ) ;
F_42 ( V_141 ) ;
V_141 -> V_24 = NULL ;
V_38 -> V_37 [ V_3 ] . V_132 = V_169 ;
}
return 0 ;
}
static int F_90 ( struct V_19 * V_20 )
{
struct V_1 * V_33 = V_20 -> V_42 ;
int V_3 = V_20 -> V_3 ;
F_84 ( V_33 , V_3 , V_176 ) ;
F_89 ( V_33 , V_20 -> V_3 ) ;
F_8 ( V_33 -> V_39 , L_64 , V_33 -> V_17 -> V_40 ) ;
F_42 ( V_20 ) ;
F_6 ( V_33 , V_3 , V_108 ) ;
V_33 -> V_37 [ V_3 ] . V_132 = V_169 ;
F_84 ( V_33 , V_3 , V_167 ) ;
return 0 ;
}
int F_91 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_141 =
F_63 ( V_38 , V_3 ) ;
if ( ! F_80 ( V_33 , V_38 , V_3 ) )
continue;
if ( ! F_92 ( V_33 , V_38 , V_3 ) )
continue;
if ( V_38 -> V_37 [ V_3 ] . V_142 > 1 )
continue;
if ( ( V_38 -> V_37 [ V_3 ] . V_132 != V_179 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 != V_180 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 != V_178 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 != V_181 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 != V_182 ) )
continue;
F_8 ( V_38 -> V_39 , L_65 ,
V_37 -> V_33 -> V_17 -> V_40 ) ;
F_53 ( V_141 ) ;
V_38 -> V_37 [ V_3 ] . V_132 = V_178 ;
}
return 0 ;
}
static int F_93 ( struct V_19 * V_20 )
{
struct V_1 * V_33 = V_20 -> V_42 ;
int V_162 , V_3 = V_20 -> V_3 ;
F_33 ( & V_33 -> V_112 -> V_183 , V_184 ) ;
F_84 ( V_33 , V_3 , V_176 ) ;
F_8 ( V_33 -> V_39 , L_66 , V_33 -> V_17 -> V_40 ) ;
V_162 = F_53 ( V_20 ) ;
if ( V_162 < 0 )
F_12 ( V_33 -> V_39 , L_67 ,
V_33 -> V_17 -> V_40 ) ;
V_162 = F_91 ( V_33 , V_3 ) ;
V_33 -> V_37 [ V_3 ] . V_132 = V_178 ;
F_84 ( V_33 , V_3 , V_167 ) ;
F_37 ( & V_33 -> V_112 -> V_183 ) ;
return 0 ;
}
int F_94 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 ;
int V_43 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_141 =
F_63 ( V_38 , V_3 ) ;
if ( ! F_80 ( V_33 , V_38 , V_3 ) )
continue;
if ( ! F_95 ( V_33 , V_38 , V_3 ) )
continue;
if ( ( V_38 -> V_37 [ V_3 ] . V_132 != V_168 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 != V_179 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 != V_178 ) )
continue;
F_8 ( V_38 -> V_39 , L_68 ,
V_37 -> V_33 -> V_17 -> V_40 ) ;
memcpy ( & V_37 -> V_118 , & V_33 -> V_37 [ V_3 ] . V_118 ,
sizeof( struct V_54 ) ) ;
if ( V_38 -> V_17 -> V_185 ) {
V_43 = V_38 -> V_17 -> V_185 ( V_38 ,
& V_37 -> V_118 ) ;
if ( V_43 < 0 ) {
F_12 ( V_38 -> V_39 ,
L_69 ,
V_43 ) ;
goto V_173;
}
}
V_43 = F_52 ( V_141 , & V_37 -> V_118 ) ;
if ( V_43 < 0 ) {
F_12 ( V_37 -> V_38 -> V_39 ,
L_70 , V_43 ) ;
goto V_173;
}
V_38 -> V_37 [ V_3 ] . V_132 = V_179 ;
}
return 0 ;
V_173:
F_81 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_141 =
F_63 ( V_38 , V_3 ) ;
if ( ! F_80 ( V_33 , V_38 , V_3 ) )
continue;
if ( ! F_92 ( V_33 , V_38 , V_3 ) )
continue;
if ( ( V_38 -> V_37 [ V_3 ] . V_132 != V_168 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 != V_179 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 != V_178 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 != V_182 ) )
continue;
F_53 ( V_141 ) ;
}
return V_43 ;
}
static int F_96 ( struct V_19 * V_20 ,
struct V_54 * V_55 )
{
struct V_1 * V_33 = V_20 -> V_42 ;
int V_43 , V_3 = V_20 -> V_3 ;
F_33 ( & V_33 -> V_112 -> V_183 , V_184 ) ;
F_84 ( V_33 , V_3 , V_176 ) ;
memcpy ( & V_33 -> V_37 [ V_20 -> V_3 ] . V_118 , V_55 ,
sizeof( struct V_54 ) ) ;
V_43 = F_94 ( V_33 , V_20 -> V_3 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_70 , V_43 ) ;
goto V_89;
}
F_8 ( V_33 -> V_39 , L_71 ,
V_33 -> V_17 -> V_40 , F_14 ( V_55 ) ,
F_15 ( V_55 ) , F_17 ( V_55 ) ) ;
V_43 = F_52 ( V_20 , V_55 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_72 , V_43 ) ;
F_91 ( V_33 , V_3 ) ;
} else
V_33 -> V_37 [ V_3 ] . V_132 = V_179 ;
V_89:
F_84 ( V_33 , V_3 , V_167 ) ;
F_37 ( & V_33 -> V_112 -> V_183 ) ;
return V_43 ;
}
static int F_97 ( struct V_36 * V_37 ,
struct V_19 * V_20 , int V_123 )
{
int V_43 ;
F_8 ( V_37 -> V_38 -> V_39 , L_73 ,
V_37 -> V_33 -> V_17 -> V_40 , V_123 ) ;
V_43 = F_54 ( V_20 , V_123 ) ;
if ( V_43 < 0 )
F_12 ( V_37 -> V_38 -> V_39 , L_74 , V_43 ) ;
return V_43 ;
}
int F_98 ( struct V_1 * V_33 , int V_3 ,
int V_123 )
{
struct V_36 * V_37 ;
int V_43 = 0 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_141 =
F_63 ( V_38 , V_3 ) ;
if ( ! F_80 ( V_33 , V_38 , V_3 ) )
continue;
switch ( V_123 ) {
case V_186 :
if ( ( V_38 -> V_37 [ V_3 ] . V_132 != V_180 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 != V_182 ) )
continue;
V_43 = F_97 ( V_37 , V_141 , V_123 ) ;
if ( V_43 )
return V_43 ;
V_38 -> V_37 [ V_3 ] . V_132 = V_187 ;
break;
case V_188 :
if ( ( V_38 -> V_37 [ V_3 ] . V_132 != V_189 ) )
continue;
V_43 = F_97 ( V_37 , V_141 , V_123 ) ;
if ( V_43 )
return V_43 ;
V_38 -> V_37 [ V_3 ] . V_132 = V_187 ;
break;
case V_190 :
if ( ( V_38 -> V_37 [ V_3 ] . V_132 != V_181 ) )
continue;
V_43 = F_97 ( V_37 , V_141 , V_123 ) ;
if ( V_43 )
return V_43 ;
V_38 -> V_37 [ V_3 ] . V_132 = V_187 ;
break;
case V_191 :
if ( V_38 -> V_37 [ V_3 ] . V_132 != V_187 )
continue;
if ( ! F_92 ( V_33 , V_38 , V_3 ) )
continue;
V_43 = F_97 ( V_37 , V_141 , V_123 ) ;
if ( V_43 )
return V_43 ;
V_38 -> V_37 [ V_3 ] . V_132 = V_182 ;
break;
case V_192 :
if ( V_38 -> V_37 [ V_3 ] . V_132 != V_187 )
continue;
if ( ! F_92 ( V_33 , V_38 , V_3 ) )
continue;
V_43 = F_97 ( V_37 , V_141 , V_123 ) ;
if ( V_43 )
return V_43 ;
V_38 -> V_37 [ V_3 ] . V_132 = V_189 ;
break;
case V_193 :
if ( V_38 -> V_37 [ V_3 ] . V_132 != V_187 )
continue;
if ( ! F_92 ( V_33 , V_38 , V_3 ) )
continue;
V_43 = F_97 ( V_37 , V_141 , V_123 ) ;
if ( V_43 )
return V_43 ;
V_38 -> V_37 [ V_3 ] . V_132 = V_181 ;
break;
}
}
return V_43 ;
}
static int F_86 ( struct V_19 * V_20 , int V_123 )
{
struct V_1 * V_33 = V_20 -> V_42 ;
int V_3 = V_20 -> V_3 , V_43 ;
enum V_194 V_124 = V_33 -> V_17 -> V_124 [ V_3 ] ;
V_33 -> V_37 [ V_3 ] . V_159 = V_176 ;
switch ( V_124 ) {
case V_195 :
F_8 ( V_33 -> V_39 , L_75 ,
V_33 -> V_17 -> V_40 , V_123 ) ;
V_43 = F_54 ( V_20 , V_123 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_76 , V_43 ) ;
goto V_89;
}
V_43 = F_98 ( V_33 , V_20 -> V_3 , V_123 ) ;
break;
case V_196 :
V_43 = F_98 ( V_33 , V_20 -> V_3 , V_123 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_76 , V_43 ) ;
goto V_89;
}
F_8 ( V_33 -> V_39 , L_77 ,
V_33 -> V_17 -> V_40 , V_123 ) ;
V_43 = F_54 ( V_20 , V_123 ) ;
break;
case V_197 :
F_8 ( V_33 -> V_39 , L_78 ,
V_33 -> V_17 -> V_40 , V_123 ) ;
V_43 = F_55 ( V_20 , V_123 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_76 , V_43 ) ;
goto V_89;
}
break;
default:
F_12 ( V_33 -> V_39 , L_79 , V_123 ,
V_33 -> V_17 -> V_40 ) ;
V_43 = - V_57 ;
goto V_89;
}
switch ( V_123 ) {
case V_186 :
case V_188 :
case V_190 :
V_33 -> V_37 [ V_3 ] . V_132 = V_187 ;
break;
case V_191 :
case V_192 :
case V_193 :
V_33 -> V_37 [ V_3 ] . V_132 = V_182 ;
break;
}
V_89:
V_33 -> V_37 [ V_3 ] . V_159 = V_167 ;
return V_43 ;
}
static int F_99 ( struct V_19 * V_20 , int V_123 )
{
struct V_1 * V_33 = V_20 -> V_42 ;
int V_3 = V_20 -> V_3 ;
if ( V_33 -> V_37 [ V_3 ] . V_159 != V_167 ) {
V_33 -> V_37 [ V_3 ] . V_175 = V_123 + 1 ;
return 0 ;
}
return F_86 ( V_20 , V_123 ) ;
}
int F_100 ( struct V_1 * V_33 , int V_3 )
{
struct V_36 * V_37 ;
int V_43 = 0 ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
struct V_19 * V_141 =
F_63 ( V_38 , V_3 ) ;
if ( ! F_80 ( V_33 , V_38 , V_3 ) )
continue;
if ( ( V_38 -> V_37 [ V_3 ] . V_132 != V_179 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 != V_182 ) )
continue;
F_8 ( V_38 -> V_39 , L_80 ,
V_37 -> V_33 -> V_17 -> V_40 ) ;
V_43 = F_46 ( V_141 ) ;
if ( V_43 < 0 ) {
F_12 ( V_38 -> V_39 , L_81 ,
V_43 ) ;
break;
}
V_38 -> V_37 [ V_3 ] . V_132 = V_180 ;
}
return V_43 ;
}
static int F_101 ( struct V_19 * V_20 )
{
struct V_1 * V_33 = V_20 -> V_42 ;
int V_3 = V_20 -> V_3 , V_43 = 0 ;
F_33 ( & V_33 -> V_112 -> V_183 , V_184 ) ;
F_8 ( V_33 -> V_39 , L_82 , V_33 -> V_17 -> V_40 ) ;
F_84 ( V_33 , V_3 , V_176 ) ;
if ( F_102 ( & V_33 -> V_37 [ V_3 ] . V_135 ) ) {
F_12 ( V_33 -> V_39 , L_83 ,
V_33 -> V_17 -> V_40 ) ;
V_43 = - V_57 ;
goto V_89;
}
V_43 = F_100 ( V_33 , V_20 -> V_3 ) ;
if ( V_43 < 0 )
goto V_89;
V_43 = F_46 ( V_20 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_84 ,
V_33 -> V_17 -> V_40 ) ;
goto V_89;
}
F_6 ( V_33 , V_3 , V_113 ) ;
V_33 -> V_37 [ V_3 ] . V_132 = V_180 ;
V_89:
F_84 ( V_33 , V_3 , V_167 ) ;
F_37 ( & V_33 -> V_112 -> V_183 ) ;
return V_43 ;
}
static int F_103 ( struct V_19 * V_20 ,
unsigned int V_123 , void * V_198 )
{
struct V_1 * V_2 = V_20 -> V_42 ;
struct V_83 * V_84 = V_2 -> V_84 ;
if ( V_84 -> V_45 -> V_87 && V_84 -> V_45 -> V_87 -> V_199 )
return V_84 -> V_45 -> V_87 -> V_199 ( V_20 , V_123 , V_198 ) ;
return F_104 ( V_20 , V_123 , V_198 ) ;
}
static int F_105 ( struct V_1 * V_33 , int V_3 )
{
struct V_19 * V_20 =
F_63 ( V_33 , V_3 ) ;
enum V_194 V_124 = V_33 -> V_17 -> V_124 [ V_3 ] ;
int V_162 ;
F_8 ( V_33 -> V_39 , L_85 ,
V_3 ? L_39 : L_40 , V_33 -> V_17 -> V_40 ) ;
if ( V_124 == V_197 ) {
F_8 ( V_33 -> V_39 , L_86 ,
V_33 -> V_17 -> V_40 ) ;
V_162 = F_55 ( V_20 , V_191 ) ;
if ( V_162 < 0 )
F_12 ( V_33 -> V_39 , L_76 , V_162 ) ;
} else {
F_8 ( V_33 -> V_39 , L_87 ,
V_33 -> V_17 -> V_40 ) ;
V_162 = F_98 ( V_33 , V_3 , V_191 ) ;
if ( V_162 < 0 )
F_12 ( V_33 -> V_39 , L_76 , V_162 ) ;
}
V_162 = F_91 ( V_33 , V_3 ) ;
if ( V_162 < 0 )
F_12 ( V_33 -> V_39 , L_88 , V_162 ) ;
V_162 = F_89 ( V_33 , V_3 ) ;
if ( V_162 < 0 )
F_12 ( V_33 -> V_39 , L_89 , V_162 ) ;
F_6 ( V_33 , V_3 , V_200 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_33 , int V_3 )
{
struct V_19 * V_20 =
F_63 ( V_33 , V_3 ) ;
struct V_36 * V_37 ;
enum V_194 V_124 = V_33 -> V_17 -> V_124 [ V_3 ] ;
int V_43 ;
F_8 ( V_33 -> V_39 , L_90 ,
V_3 ? L_39 : L_40 , V_33 -> V_17 -> V_40 ) ;
if ( V_33 -> V_37 [ V_3 ] . V_132 == V_178 ||
V_33 -> V_37 [ V_3 ] . V_132 == V_169 )
return - V_57 ;
V_43 = F_79 ( V_33 , V_3 ) ;
if ( V_43 < 0 )
goto V_201;
if ( V_33 -> V_37 [ V_3 ] . V_132 == V_168 )
return 0 ;
V_43 = F_94 ( V_33 , V_3 ) ;
if ( V_43 < 0 )
goto V_102;
if ( V_33 -> V_37 [ V_3 ] . V_132 == V_179 )
return 0 ;
V_43 = F_100 ( V_33 , V_3 ) ;
if ( V_43 < 0 )
goto V_122;
F_6 ( V_33 , V_3 , V_200 ) ;
if ( V_33 -> V_37 [ V_3 ] . V_132 == V_180 ||
V_33 -> V_37 [ V_3 ] . V_132 == V_182 )
return 0 ;
if ( V_124 == V_197 ) {
F_8 ( V_33 -> V_39 , L_91 ,
V_33 -> V_17 -> V_40 ) ;
V_43 = F_55 ( V_20 , V_186 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_92 , V_43 ) ;
goto V_122;
}
} else {
F_8 ( V_33 -> V_39 , L_93 ,
V_33 -> V_17 -> V_40 ) ;
V_43 = F_98 ( V_33 , V_3 ,
V_186 ) ;
if ( V_43 < 0 ) {
F_12 ( V_33 -> V_39 , L_76 , V_43 ) ;
goto V_122;
}
}
return 0 ;
V_122:
F_91 ( V_33 , V_3 ) ;
V_102:
F_89 ( V_33 , V_3 ) ;
V_201:
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
if ( V_38 -> V_37 [ V_3 ] . V_132 != V_187 )
V_37 -> V_132 = V_144 ;
}
return V_43 ;
}
static int F_107 ( struct V_1 * V_33 , int V_3 )
{
int V_43 ;
F_84 ( V_33 , V_3 , V_160 ) ;
V_43 = F_106 ( V_33 , V_3 ) ;
if ( V_43 < 0 )
F_12 ( V_33 -> V_39 , L_94 ) ;
F_84 ( V_33 , V_3 , V_167 ) ;
return V_43 ;
}
static int F_108 ( struct V_1 * V_33 , int V_3 )
{
int V_43 ;
F_84 ( V_33 , V_3 , V_160 ) ;
V_43 = F_105 ( V_33 , V_3 ) ;
if ( V_43 < 0 )
F_12 ( V_33 -> V_39 , L_95 ) ;
F_84 ( V_33 , V_3 , V_167 ) ;
return V_43 ;
}
int F_109 ( struct V_145 * V_112 )
{
int V_6 , V_202 , V_161 , V_157 ;
F_33 ( & V_112 -> V_183 , V_184 ) ;
for ( V_6 = 0 ; V_6 < V_112 -> V_203 ; V_6 ++ ) {
struct V_152 * V_153 ;
struct V_1 * V_33 = & V_112 -> V_2 [ V_6 ] ;
if ( ! V_33 -> V_17 -> V_96 )
continue;
if ( ! V_33 -> V_5 -> V_13 )
continue;
F_8 ( V_33 -> V_39 , L_96 ,
V_33 -> V_17 -> V_40 ) ;
if ( ! V_33 -> V_5 -> V_45 -> V_66 . V_81
|| ! V_33 -> V_64 -> V_45 -> V_66 . V_81 )
goto V_68;
if ( ! V_33 -> V_5 -> V_9
|| ! V_33 -> V_64 -> V_9 )
goto V_68;
V_157 = F_72 ( V_33 , V_8 , & V_153 ) ;
if ( V_157 < 0 ) {
F_22 ( V_33 -> V_39 , L_97 ,
V_33 -> V_17 -> V_40 , L_40 ) ;
F_37 ( & V_112 -> V_183 ) ;
return V_157 ;
}
V_161 = F_76 ( V_33 , V_8 , & V_153 , 1 ) ;
if ( V_161 ) {
F_107 ( V_33 , V_8 ) ;
F_77 ( V_33 , V_8 ) ;
F_64 ( V_33 , V_8 ) ;
}
V_202 = F_76 ( V_33 , V_8 , & V_153 , 0 ) ;
if ( V_202 ) {
F_108 ( V_33 , V_8 ) ;
F_77 ( V_33 , V_8 ) ;
F_64 ( V_33 , V_8 ) ;
}
F_110 ( & V_153 ) ;
V_68:
if ( ! V_33 -> V_5 -> V_45 -> V_68 . V_81
|| ! V_33 -> V_64 -> V_45 -> V_68 . V_81 )
continue;
if ( ! V_33 -> V_5 -> V_12
|| ! V_33 -> V_64 -> V_12 )
continue;
V_157 = F_72 ( V_33 , V_110 , & V_153 ) ;
if ( V_157 < 0 ) {
F_22 ( V_33 -> V_39 , L_97 ,
V_33 -> V_17 -> V_40 , L_39 ) ;
F_37 ( & V_112 -> V_183 ) ;
return V_157 ;
}
V_161 = F_76 ( V_33 , V_110 , & V_153 , 1 ) ;
if ( V_161 ) {
F_107 ( V_33 , V_110 ) ;
F_77 ( V_33 , V_110 ) ;
F_64 ( V_33 , V_110 ) ;
}
V_202 = F_76 ( V_33 , V_110 , & V_153 , 0 ) ;
if ( V_202 ) {
F_108 ( V_33 , V_110 ) ;
F_77 ( V_33 , V_110 ) ;
F_64 ( V_33 , V_110 ) ;
}
F_110 ( & V_153 ) ;
}
F_37 ( & V_112 -> V_183 ) ;
return 0 ;
}
int F_111 ( struct V_1 * V_33 , int V_204 )
{
struct V_36 * V_37 ;
struct V_205 * V_206 =
& V_33 -> V_37 [ V_8 ] . V_135 ;
F_7 (dpcm, clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
int V_6 ;
if ( V_38 -> V_17 -> V_207 )
continue;
for ( V_6 = 0 ; V_6 < V_38 -> V_10 ; V_6 ++ ) {
struct V_4 * V_117 = V_38 -> V_11 [ V_6 ] ;
struct V_58 * V_208 = V_117 -> V_45 ;
F_8 ( V_38 -> V_39 , L_98 ,
V_38 -> V_17 -> V_40 ) ;
if ( V_208 -> V_87 && V_208 -> V_87 -> V_209 &&
V_117 -> V_9 )
V_208 -> V_87 -> V_209 ( V_117 , V_204 ) ;
}
}
return 0 ;
}
static int F_112 ( struct V_19 * V_140 )
{
struct V_1 * V_33 = V_140 -> V_42 ;
struct V_36 * V_37 ;
struct V_152 * V_153 ;
int V_43 ;
int V_3 = V_140 -> V_3 ;
F_33 ( & V_33 -> V_112 -> V_183 , V_184 ) ;
V_33 -> V_37 [ V_3 ] . V_24 = V_140 -> V_24 ;
V_43 = F_72 ( V_33 , V_3 , & V_153 ) ;
if ( V_43 < 0 ) {
F_37 ( & V_33 -> V_112 -> V_183 ) ;
return V_43 ;
} else if ( V_43 == 0 ) {
F_8 ( V_33 -> V_39 , L_99 ,
V_33 -> V_17 -> V_40 , V_3 ? L_39 : L_40 ) ;
}
F_76 ( V_33 , V_3 , & V_153 , 1 ) ;
V_43 = F_88 ( V_140 ) ;
if ( V_43 < 0 ) {
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_37 -> V_132 = V_144 ;
F_64 ( V_33 , V_3 ) ;
V_33 -> V_37 [ V_3 ] . V_24 = NULL ;
}
F_77 ( V_33 , V_3 ) ;
F_110 ( & V_153 ) ;
F_37 ( & V_33 -> V_112 -> V_183 ) ;
return V_43 ;
}
static int F_113 ( struct V_19 * V_140 )
{
struct V_1 * V_33 = V_140 -> V_42 ;
struct V_36 * V_37 ;
int V_3 = V_140 -> V_3 , V_43 ;
F_33 ( & V_33 -> V_112 -> V_183 , V_184 ) ;
V_43 = F_90 ( V_140 ) ;
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_37 -> V_132 = V_144 ;
F_64 ( V_33 , V_3 ) ;
V_33 -> V_37 [ V_3 ] . V_24 = NULL ;
F_37 ( & V_33 -> V_112 -> V_183 ) ;
return V_43 ;
}
int F_114 ( struct V_1 * V_2 , int V_210 )
{
struct V_83 * V_84 = V_2 -> V_84 ;
struct V_4 * V_64 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_211 * V_212 ;
char V_213 [ 64 ] ;
int V_43 = 0 , V_66 = 0 , V_68 = 0 ;
int V_6 ;
if ( V_2 -> V_17 -> V_96 || V_2 -> V_17 -> V_97 ) {
V_66 = V_2 -> V_17 -> V_214 ;
V_68 = V_2 -> V_17 -> V_215 ;
} else {
for ( V_6 = 0 ; V_6 < V_2 -> V_10 ; V_6 ++ ) {
V_64 = V_2 -> V_11 [ V_6 ] ;
if ( V_64 -> V_45 -> V_66 . V_81 )
V_66 = 1 ;
if ( V_64 -> V_45 -> V_68 . V_81 )
V_68 = 1 ;
}
V_68 = V_68 && V_5 -> V_45 -> V_68 . V_81 ;
V_66 = V_66 && V_5 -> V_45 -> V_66 . V_81 ;
}
if ( V_2 -> V_17 -> V_216 ) {
V_66 = 1 ;
V_68 = 0 ;
}
if ( V_2 -> V_17 -> V_217 ) {
V_66 = 0 ;
V_68 = 1 ;
}
if ( V_2 -> V_17 -> V_97 ) {
snprintf ( V_213 , sizeof( V_213 ) , L_100 ,
V_2 -> V_17 -> V_106 ) ;
V_43 = F_115 ( V_2 -> V_112 -> V_218 , V_213 , V_210 ,
V_66 , V_68 , & V_212 ) ;
} else {
if ( V_2 -> V_17 -> V_96 )
snprintf ( V_213 , sizeof( V_213 ) , L_101 ,
V_2 -> V_17 -> V_106 ) ;
else
snprintf ( V_213 , sizeof( V_213 ) , L_102 ,
V_2 -> V_17 -> V_106 ,
( V_2 -> V_10 > 1 ) ?
L_12 : V_2 -> V_64 -> V_40 , V_210 ) ;
V_43 = F_116 ( V_2 -> V_112 -> V_218 , V_213 , V_210 , V_66 ,
V_68 , & V_212 ) ;
}
if ( V_43 < 0 ) {
F_12 ( V_2 -> V_112 -> V_39 , L_103 ,
V_2 -> V_17 -> V_40 ) ;
return V_43 ;
}
F_8 ( V_2 -> V_112 -> V_39 , L_104 , V_210 , V_213 ) ;
F_117 ( & V_2 -> V_105 , F_40 ) ;
V_2 -> V_212 = V_212 ;
V_212 -> V_42 = V_2 ;
if ( V_2 -> V_17 -> V_97 ) {
if ( V_66 )
V_212 -> V_219 [ V_8 ] . V_20 -> V_42 = V_2 ;
if ( V_68 )
V_212 -> V_219 [ V_110 ] . V_20 -> V_42 = V_2 ;
goto V_89;
}
if ( V_2 -> V_17 -> V_96 ) {
V_2 -> V_87 . V_90 = F_112 ;
V_2 -> V_87 . V_118 = F_96 ;
V_2 -> V_87 . V_111 = F_101 ;
V_2 -> V_87 . V_124 = F_99 ;
V_2 -> V_87 . V_122 = F_93 ;
V_2 -> V_87 . V_102 = F_113 ;
V_2 -> V_87 . V_129 = F_56 ;
V_2 -> V_87 . V_199 = F_103 ;
} else {
V_2 -> V_87 . V_90 = F_30 ;
V_2 -> V_87 . V_118 = F_52 ;
V_2 -> V_87 . V_111 = F_46 ;
V_2 -> V_87 . V_124 = F_54 ;
V_2 -> V_87 . V_122 = F_53 ;
V_2 -> V_87 . V_102 = F_42 ;
V_2 -> V_87 . V_129 = F_56 ;
V_2 -> V_87 . V_199 = F_103 ;
}
if ( V_84 -> V_45 -> V_87 ) {
V_2 -> V_87 . V_220 = V_84 -> V_45 -> V_87 -> V_220 ;
V_2 -> V_87 . V_221 = V_84 -> V_45 -> V_87 -> V_221 ;
V_2 -> V_87 . V_222 = V_84 -> V_45 -> V_87 -> V_222 ;
V_2 -> V_87 . V_223 = V_84 -> V_45 -> V_87 -> V_223 ;
V_2 -> V_87 . V_224 = V_84 -> V_45 -> V_87 -> V_224 ;
}
if ( V_66 )
F_118 ( V_212 , V_8 , & V_2 -> V_87 ) ;
if ( V_68 )
F_118 ( V_212 , V_110 , & V_2 -> V_87 ) ;
if ( V_84 -> V_45 -> V_225 ) {
V_43 = V_84 -> V_45 -> V_225 ( V_2 ) ;
if ( V_43 < 0 ) {
F_12 ( V_84 -> V_39 ,
L_105 ,
V_43 ) ;
return V_43 ;
}
}
V_212 -> V_226 = V_84 -> V_45 -> V_227 ;
V_89:
F_119 ( V_2 -> V_112 -> V_39 , L_106 ,
( V_2 -> V_10 > 1 ) ? L_12 : V_2 -> V_64 -> V_40 ,
V_5 -> V_40 ) ;
return V_43 ;
}
int F_120 ( struct V_1 * V_33 , int V_3 )
{
if ( V_33 -> V_37 [ V_3 ] . V_159 == V_176 )
return 1 ;
return 0 ;
}
int F_80 ( struct V_1 * V_33 ,
struct V_1 * V_38 , int V_3 )
{
if ( ( V_33 -> V_37 [ V_3 ] . V_159 == V_176 ) ||
( ( V_33 -> V_37 [ V_3 ] . V_159 == V_160 ) &&
V_38 -> V_37 [ V_3 ] . V_159 ) )
return 1 ;
return 0 ;
}
struct V_19 *
F_63 ( struct V_1 * V_38 , int V_3 )
{
return V_38 -> V_212 -> V_219 [ V_3 ] . V_20 ;
}
enum V_228
F_121 ( struct V_1 * V_38 , int V_3 )
{
return V_38 -> V_37 [ V_3 ] . V_132 ;
}
void F_122 ( struct V_1 * V_38 ,
int V_3 , enum V_228 V_132 )
{
V_38 -> V_37 [ V_3 ] . V_132 = V_132 ;
}
int F_92 ( struct V_1 * V_33 ,
struct V_1 * V_38 , int V_3 )
{
struct V_36 * V_37 ;
int V_132 ;
F_7 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_37 -> V_33 == V_33 )
continue;
V_132 = V_37 -> V_33 -> V_37 [ V_3 ] . V_132 ;
if ( V_132 == V_187 ||
V_132 == V_181 ||
V_132 == V_189 )
return 0 ;
}
return 1 ;
}
int F_95 ( struct V_1 * V_33 ,
struct V_1 * V_38 , int V_3 )
{
struct V_36 * V_37 ;
int V_132 ;
F_7 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_37 -> V_33 == V_33 )
continue;
V_132 = V_37 -> V_33 -> V_37 [ V_3 ] . V_132 ;
if ( V_132 == V_187 ||
V_132 == V_181 ||
V_132 == V_189 ||
V_132 == V_180 )
return 0 ;
}
return 1 ;
}
int F_123 ( struct V_19 * V_20 ,
int V_123 , struct V_83 * V_84 )
{
if ( V_84 -> V_45 -> V_87 && V_84 -> V_45 -> V_87 -> V_124 )
return V_84 -> V_45 -> V_87 -> V_124 ( V_20 , V_123 ) ;
return 0 ;
}
static char * F_124 ( enum V_228 V_132 )
{
switch ( V_132 ) {
case V_172 :
return L_107 ;
case V_168 :
return L_108 ;
case V_179 :
return L_109 ;
case V_180 :
return L_110 ;
case V_187 :
return L_111 ;
case V_182 :
return L_112 ;
case V_189 :
return L_113 ;
case V_181 :
return L_114 ;
case V_178 :
return L_115 ;
case V_169 :
return L_116 ;
}
return L_117 ;
}
static T_4 F_125 ( struct V_1 * V_33 ,
int V_3 , char * V_229 , T_5 V_230 )
{
struct V_54 * V_55 = & V_33 -> V_37 [ V_3 ] . V_118 ;
struct V_36 * V_37 ;
T_4 V_126 = 0 ;
V_126 += snprintf ( V_229 + V_126 , V_230 - V_126 ,
L_118 , V_33 -> V_17 -> V_40 ,
V_3 ? L_119 : L_120 ) ;
V_126 += snprintf ( V_229 + V_126 , V_230 - V_126 , L_121 ,
F_124 ( V_33 -> V_37 [ V_3 ] . V_132 ) ) ;
if ( ( V_33 -> V_37 [ V_3 ] . V_132 >= V_179 ) &&
( V_33 -> V_37 [ V_3 ] . V_132 <= V_182 ) )
V_126 += snprintf ( V_229 + V_126 , V_230 - V_126 ,
L_122
L_123 ,
F_126 ( F_17 ( V_55 ) ) ,
F_15 ( V_55 ) ,
F_14 ( V_55 ) ) ;
V_126 += snprintf ( V_229 + V_126 , V_230 - V_126 , L_124 ) ;
if ( F_102 ( & V_33 -> V_37 [ V_3 ] . V_135 ) ) {
V_126 += snprintf ( V_229 + V_126 , V_230 - V_126 ,
L_125 ) ;
goto V_89;
}
F_7 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_38 = V_37 -> V_38 ;
V_55 = & V_37 -> V_118 ;
V_126 += snprintf ( V_229 + V_126 , V_230 - V_126 ,
L_126 , V_38 -> V_17 -> V_40 ) ;
V_126 += snprintf ( V_229 + V_126 , V_230 - V_126 ,
L_127 ,
F_124 ( V_38 -> V_37 [ V_3 ] . V_132 ) ) ;
if ( ( V_38 -> V_37 [ V_3 ] . V_132 >= V_179 ) &&
( V_38 -> V_37 [ V_3 ] . V_132 <= V_182 ) )
V_126 += snprintf ( V_229 + V_126 , V_230 - V_126 ,
L_128
L_123 ,
F_126 ( F_17 ( V_55 ) ) ,
F_15 ( V_55 ) ,
F_14 ( V_55 ) ) ;
}
V_89:
return V_126 ;
}
static T_4 F_127 ( struct V_231 * V_231 , char T_6 * V_232 ,
T_5 V_170 , T_7 * V_233 )
{
struct V_1 * V_33 = V_231 -> V_42 ;
T_4 V_234 = V_235 , V_126 = 0 , V_43 = 0 ;
char * V_229 ;
V_229 = F_128 ( V_234 , V_130 ) ;
if ( ! V_229 )
return - V_131 ;
if ( V_33 -> V_5 -> V_45 -> V_66 . V_81 )
V_126 += F_125 ( V_33 , V_8 ,
V_229 + V_126 , V_234 - V_126 ) ;
if ( V_33 -> V_5 -> V_45 -> V_68 . V_81 )
V_126 += F_125 ( V_33 , V_110 ,
V_229 + V_126 , V_234 - V_126 ) ;
V_43 = F_129 ( V_232 , V_170 , V_233 , V_229 , V_126 ) ;
F_68 ( V_229 ) ;
return V_43 ;
}
int F_130 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_17 )
return 0 ;
V_2 -> V_139 = F_131 ( V_2 -> V_17 -> V_40 ,
V_2 -> V_112 -> V_236 ) ;
if ( ! V_2 -> V_139 ) {
F_8 ( V_2 -> V_39 ,
L_129 ,
V_2 -> V_17 -> V_40 ) ;
return - V_57 ;
}
V_2 -> V_237 = F_132 ( L_130 , 0444 ,
V_2 -> V_139 ,
V_2 , & V_238 ) ;
return 0 ;
}
