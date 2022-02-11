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
if ( ( V_42 == V_48 ) &&
( V_45 -> V_44 [ V_41 ] . V_49 >= 1 ) )
continue;
F_10 ( V_45 , V_41 , V_42 ) ;
}
F_10 ( V_40 , V_41 , V_42 ) ;
return 0 ;
}
static int F_11 ( struct V_26 * V_27 ,
struct V_1 * V_50 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
int V_52 ;
if ( V_50 -> V_53 && ( V_50 -> V_7 -> V_54 ||
V_12 -> V_24 -> V_54 ) ) {
F_9 ( V_50 -> V_46 , L_2 ,
V_50 -> V_53 ) ;
V_52 = F_12 ( V_27 -> V_31 ,
V_55 ,
V_50 -> V_53 ) ;
if ( V_52 < 0 ) {
F_13 ( V_50 -> V_46 ,
L_3 ,
V_52 ) ;
return V_52 ;
}
}
if ( V_50 -> V_56 && ( V_50 -> V_7 -> V_57 ||
V_12 -> V_24 -> V_57 ) ) {
F_9 ( V_50 -> V_46 , L_4 ,
V_50 -> V_56 ) ;
V_52 = F_12 ( V_27 -> V_31 ,
V_58 ,
V_50 -> V_56 ) ;
if ( V_52 < 0 ) {
F_13 ( V_50 -> V_46 ,
L_5 ,
V_52 ) ;
return V_52 ;
}
}
if ( V_50 -> V_59 && ( V_50 -> V_7 -> V_60 ||
V_12 -> V_24 -> V_60 ) ) {
F_9 ( V_50 -> V_46 , L_6 ,
V_50 -> V_59 ) ;
V_52 = F_12 ( V_27 -> V_31 ,
V_61 ,
V_50 -> V_59 ) ;
if ( V_52 < 0 ) {
F_13 ( V_50 -> V_46 ,
L_7 ,
V_52 ) ;
return V_52 ;
}
}
return 0 ;
}
static int F_14 ( struct V_26 * V_27 ,
struct V_62 * V_63 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_1 * V_13 = V_12 -> V_13 ;
unsigned int V_53 , V_56 , V_59 , V_64 , V_14 ;
V_53 = F_15 ( V_63 ) ;
V_56 = F_16 ( V_63 ) ;
V_59 = F_17 ( F_18 ( V_63 ) ) ;
V_64 = V_13 -> V_7 -> V_54 ||
V_12 -> V_24 -> V_54 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
V_64 |= V_12 -> V_18 [ V_14 ] -> V_7 -> V_54 ;
if ( V_64 && V_13 -> V_53 && V_13 -> V_53 != V_53 ) {
F_13 ( V_12 -> V_46 , L_8 ,
V_13 -> V_53 , V_53 ) ;
return - V_65 ;
}
V_64 = V_13 -> V_7 -> V_57 ||
V_12 -> V_24 -> V_57 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
V_64 |= V_12 -> V_18 [ V_14 ] -> V_7 -> V_57 ;
if ( V_64 && V_13 -> V_56 && V_13 -> V_56 != V_56 ) {
F_13 ( V_12 -> V_46 , L_9 ,
V_13 -> V_56 , V_56 ) ;
return - V_65 ;
}
V_64 = V_13 -> V_7 -> V_60 ||
V_12 -> V_24 -> V_60 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
V_64 |= V_12 -> V_18 [ V_14 ] -> V_7 -> V_60 ;
if ( V_64 && V_13 -> V_59 && V_13 -> V_59 != V_59 ) {
F_13 ( V_12 -> V_46 , L_10 ,
V_13 -> V_59 , V_59 ) ;
return - V_65 ;
}
return 0 ;
}
static bool F_19 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_66 * V_67 = V_12 -> V_13 -> V_7 ;
struct V_68 * V_69 = V_12 -> V_24 ;
unsigned int V_64 , V_14 ;
V_64 = V_67 -> V_54 || V_69 -> V_54 ||
V_67 -> V_57 || V_69 -> V_57 ||
V_67 -> V_60 || V_69 -> V_60 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
V_64 = V_64 ||
V_12 -> V_18 [ V_14 ] -> V_7 -> V_54 ||
V_12 -> V_18 [ V_14 ] -> V_7 -> V_57 ||
V_12 -> V_18 [ V_14 ] -> V_7 -> V_60 ;
return V_64 ;
}
static void F_20 ( struct V_26 * V_27 , int V_70 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
int V_52 ;
if ( ! V_70 )
return;
V_52 = F_21 ( V_27 -> V_31 , 0 , 0 , V_70 ) ;
if ( V_52 != 0 )
F_22 ( V_12 -> V_46 , L_11 ,
V_70 , V_52 ) ;
}
static void F_23 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_71 ;
int V_14 ;
unsigned int V_70 = 0 , V_72 ;
if ( V_27 -> V_3 == V_6 ) {
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_71 = V_12 -> V_18 [ V_14 ] ;
if ( V_71 -> V_7 -> V_8 . V_73 == 0 ) {
V_70 = 0 ;
break;
}
V_70 = F_24 ( V_71 -> V_7 -> V_8 . V_73 , V_70 ) ;
}
V_72 = V_13 -> V_7 -> V_8 . V_73 ;
} else {
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_71 = V_12 -> V_18 [ V_14 ] ;
if ( V_71 -> V_7 -> V_9 . V_73 == 0 ) {
V_70 = 0 ;
break;
}
V_70 = F_24 ( V_71 -> V_7 -> V_9 . V_73 , V_70 ) ;
}
V_72 = V_13 -> V_7 -> V_9 . V_73 ;
}
F_20 ( V_27 , V_70 ) ;
F_20 ( V_27 , V_72 ) ;
}
static void F_25 ( struct V_26 * V_27 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_28 * V_29 = & V_31 -> V_29 ;
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_66 * V_74 = V_12 -> V_13 -> V_7 ;
struct V_66 * V_75 ;
struct V_4 * V_5 ;
struct V_4 * V_76 ;
unsigned int V_77 = 0 , V_78 = V_79 ;
unsigned int V_80 = 0 , V_81 = V_79 ;
unsigned int V_10 = V_79 ;
T_1 V_33 = V_82 ;
int V_14 ;
if ( V_27 -> V_3 == V_6 )
V_76 = & V_74 -> V_8 ;
else
V_76 = & V_74 -> V_9 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
if ( ! F_1 ( V_12 -> V_18 [ V_14 ] ,
V_27 -> V_3 ) )
continue;
V_75 = V_12 -> V_18 [ V_14 ] -> V_7 ;
if ( V_27 -> V_3 == V_6 )
V_5 = & V_75 -> V_8 ;
else
V_5 = & V_75 -> V_9 ;
V_77 = F_24 ( V_77 , V_5 -> V_83 ) ;
V_78 = F_26 ( V_78 , V_5 -> V_84 ) ;
V_80 = F_24 ( V_80 , V_5 -> V_80 ) ;
V_81 = F_27 ( V_81 , V_5 -> V_81 ) ;
V_33 &= V_5 -> V_33 ;
V_10 = F_28 ( V_5 -> V_10 , V_10 ) ;
}
if ( V_12 -> V_17 > 1 ) {
V_77 = V_76 -> V_83 ;
V_78 = V_76 -> V_84 ;
}
V_29 -> V_83 = F_24 ( V_77 , V_76 -> V_83 ) ;
V_29 -> V_84 = F_26 ( V_78 , V_76 -> V_84 ) ;
if ( V_29 -> V_33 )
V_29 -> V_33 &= V_33 & V_76 -> V_33 ;
else
V_29 -> V_33 = V_33 & V_76 -> V_33 ;
V_29 -> V_10 = F_28 ( V_10 , V_76 -> V_10 ) ;
F_29 ( V_31 ) ;
V_29 -> V_80 = F_24 ( V_29 -> V_80 , V_76 -> V_80 ) ;
V_29 -> V_80 = F_24 ( V_29 -> V_80 , V_80 ) ;
V_29 -> V_81 = F_27 ( V_29 -> V_81 , V_76 -> V_81 ) ;
V_29 -> V_81 = F_27 ( V_29 -> V_81 , V_81 ) ;
}
static int F_30 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_85 * V_86 = V_12 -> V_86 ;
struct V_87 * V_21 ;
struct V_88 * V_89 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_71 ;
const char * V_90 = L_12 ;
int V_14 , V_52 = 0 ;
F_31 ( V_13 -> V_46 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
F_31 ( V_12 -> V_18 [ V_14 ] -> V_46 ) ;
F_32 (rtd, rtdcom) {
V_21 = V_89 -> V_21 ;
F_33 ( V_21 -> V_46 ) ;
}
F_34 ( & V_12 -> V_15 , V_12 -> V_91 ) ;
if ( V_13 -> V_7 -> V_92 && V_13 -> V_7 -> V_92 -> V_93 ) {
V_52 = V_13 -> V_7 -> V_92 -> V_93 ( V_27 , V_13 ) ;
if ( V_52 < 0 ) {
F_13 ( V_13 -> V_46 , L_13
L_14 , V_13 -> V_47 , V_52 ) ;
goto V_94;
}
}
if ( V_86 -> V_7 -> V_92 && V_86 -> V_7 -> V_92 -> V_95 ) {
V_52 = V_86 -> V_7 -> V_92 -> V_95 ( V_27 ) ;
if ( V_52 < 0 ) {
F_13 ( V_86 -> V_46 , L_15
L_14 , V_86 -> V_21 . V_47 , V_52 ) ;
goto V_96;
}
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_71 = V_12 -> V_18 [ V_14 ] ;
if ( V_71 -> V_7 -> V_92 && V_71 -> V_7 -> V_92 -> V_93 ) {
V_52 = V_71 -> V_7 -> V_92 -> V_93 ( V_27 ,
V_71 ) ;
if ( V_52 < 0 ) {
F_13 ( V_71 -> V_46 ,
L_16 ,
V_71 -> V_47 , V_52 ) ;
goto V_97;
}
}
if ( V_27 -> V_3 == V_6 )
V_71 -> V_98 = 0 ;
else
V_71 -> V_99 = 0 ;
}
if ( V_12 -> V_24 -> V_92 && V_12 -> V_24 -> V_92 -> V_93 ) {
V_52 = V_12 -> V_24 -> V_92 -> V_93 ( V_27 ) ;
if ( V_52 < 0 ) {
F_35 ( L_17 ,
V_12 -> V_24 -> V_47 , V_52 ) ;
goto V_100;
}
}
if ( V_12 -> V_24 -> V_101 || V_12 -> V_24 -> V_102 )
goto V_101;
F_25 ( V_27 ) ;
if ( V_12 -> V_17 == 1 )
V_90 = V_12 -> V_71 -> V_47 ;
if ( F_19 ( V_27 ) )
V_31 -> V_29 . V_32 |= V_103 ;
V_52 = - V_65 ;
if ( ! V_31 -> V_29 . V_10 ) {
F_36 ( V_104 L_18 ,
V_90 , V_13 -> V_47 ) ;
goto V_105;
}
if ( ! V_31 -> V_29 . V_33 ) {
F_36 ( V_104 L_19 ,
V_90 , V_13 -> V_47 ) ;
goto V_105;
}
if ( ! V_31 -> V_29 . V_83 || ! V_31 -> V_29 . V_84 ||
V_31 -> V_29 . V_83 > V_31 -> V_29 . V_84 ) {
F_36 ( V_104 L_20 ,
V_90 , V_13 -> V_47 ) ;
goto V_105;
}
F_23 ( V_27 ) ;
if ( V_13 -> V_20 ) {
V_52 = F_11 ( V_27 , V_13 ) ;
if ( V_52 != 0 )
goto V_105;
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
if ( V_12 -> V_18 [ V_14 ] -> V_20 ) {
V_52 = F_11 ( V_27 ,
V_12 -> V_18 [ V_14 ] ) ;
if ( V_52 != 0 )
goto V_105;
}
}
F_37 ( L_21 ,
V_90 , V_13 -> V_47 ) ;
F_37 ( L_22 , V_31 -> V_29 . V_10 ) ;
F_37 ( L_23 , V_31 -> V_29 . V_83 ,
V_31 -> V_29 . V_84 ) ;
F_37 ( L_24 , V_31 -> V_29 . V_80 ,
V_31 -> V_29 . V_81 ) ;
V_101:
F_2 ( V_12 , V_27 -> V_3 ) ;
F_38 ( & V_12 -> V_15 ) ;
return 0 ;
V_105:
if ( V_12 -> V_24 -> V_92 && V_12 -> V_24 -> V_92 -> V_106 )
V_12 -> V_24 -> V_92 -> V_106 ( V_27 ) ;
V_100:
V_14 = V_12 -> V_17 ;
V_97:
while ( -- V_14 >= 0 ) {
V_71 = V_12 -> V_18 [ V_14 ] ;
if ( V_71 -> V_7 -> V_92 -> V_106 )
V_71 -> V_7 -> V_92 -> V_106 ( V_27 , V_71 ) ;
}
if ( V_86 -> V_7 -> V_92 && V_86 -> V_7 -> V_92 -> V_107 )
V_86 -> V_7 -> V_92 -> V_107 ( V_27 ) ;
V_96:
if ( V_13 -> V_7 -> V_92 -> V_106 )
V_13 -> V_7 -> V_92 -> V_106 ( V_27 , V_13 ) ;
V_94:
F_38 ( & V_12 -> V_15 ) ;
F_32 (rtd, rtdcom) {
V_21 = V_89 -> V_21 ;
F_39 ( V_21 -> V_46 ) ;
F_40 ( V_21 -> V_46 ) ;
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
if ( ! V_12 -> V_18 [ V_14 ] -> V_20 )
F_41 ( V_12 -> V_18 [ V_14 ] -> V_46 ) ;
}
if ( ! V_13 -> V_20 )
F_41 ( V_13 -> V_46 ) ;
return V_52 ;
}
static void F_42 ( struct V_108 * V_109 )
{
struct V_11 * V_12 =
F_43 ( V_109 , struct V_11 , V_110 . V_109 ) ;
struct V_1 * V_71 = V_12 -> V_18 [ 0 ] ;
F_34 ( & V_12 -> V_15 , V_12 -> V_91 ) ;
F_9 ( V_12 -> V_46 , L_25 ,
V_71 -> V_7 -> V_8 . V_111 ,
V_71 -> V_16 ? L_26 : L_27 ,
V_12 -> V_112 ? L_28 : L_29 ) ;
if ( V_12 -> V_112 == 1 ) {
V_12 -> V_112 = 0 ;
F_10 ( V_12 , V_6 ,
V_48 ) ;
}
F_38 ( & V_12 -> V_15 ) ;
}
static int F_44 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_85 * V_86 = V_12 -> V_86 ;
struct V_87 * V_21 ;
struct V_88 * V_89 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_71 ;
int V_14 ;
F_34 ( & V_12 -> V_15 , V_12 -> V_91 ) ;
F_4 ( V_12 , V_27 -> V_3 ) ;
if ( ! V_13 -> V_20 )
V_13 -> V_53 = 0 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_71 = V_12 -> V_18 [ V_14 ] ;
if ( ! V_71 -> V_20 )
V_71 -> V_53 = 0 ;
}
F_45 ( V_13 , 1 , V_27 -> V_3 ) ;
if ( V_13 -> V_7 -> V_92 -> V_106 )
V_13 -> V_7 -> V_92 -> V_106 ( V_27 , V_13 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_71 = V_12 -> V_18 [ V_14 ] ;
if ( V_71 -> V_7 -> V_92 -> V_106 )
V_71 -> V_7 -> V_92 -> V_106 ( V_27 , V_71 ) ;
}
if ( V_12 -> V_24 -> V_92 && V_12 -> V_24 -> V_92 -> V_106 )
V_12 -> V_24 -> V_92 -> V_106 ( V_27 ) ;
if ( V_86 -> V_7 -> V_92 && V_86 -> V_7 -> V_92 -> V_107 )
V_86 -> V_7 -> V_92 -> V_107 ( V_27 ) ;
if ( V_27 -> V_3 == V_6 ) {
if ( F_5 ( V_12 ) ) {
F_10 ( V_12 ,
V_6 ,
V_48 ) ;
} else {
V_12 -> V_112 = 1 ;
F_46 ( V_113 ,
& V_12 -> V_110 ,
F_47 ( V_12 -> V_23 ) ) ;
}
} else {
F_10 ( V_12 , V_114 ,
V_48 ) ;
}
F_38 ( & V_12 -> V_15 ) ;
F_32 (rtd, rtdcom) {
V_21 = V_89 -> V_21 ;
F_39 ( V_21 -> V_46 ) ;
F_40 ( V_21 -> V_46 ) ;
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
if ( ! V_12 -> V_18 [ V_14 ] -> V_20 )
F_41 ( V_12 -> V_18 [ V_14 ] -> V_46 ) ;
}
if ( ! V_13 -> V_20 )
F_41 ( V_13 -> V_46 ) ;
return 0 ;
}
static int F_48 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_85 * V_86 = V_12 -> V_86 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_71 ;
int V_14 , V_52 = 0 ;
F_34 ( & V_12 -> V_15 , V_12 -> V_91 ) ;
if ( V_12 -> V_24 -> V_92 && V_12 -> V_24 -> V_92 -> V_115 ) {
V_52 = V_12 -> V_24 -> V_92 -> V_115 ( V_27 ) ;
if ( V_52 < 0 ) {
F_13 ( V_12 -> V_116 -> V_46 , L_30
L_31 , V_52 ) ;
goto V_94;
}
}
if ( V_86 -> V_7 -> V_92 && V_86 -> V_7 -> V_92 -> V_115 ) {
V_52 = V_86 -> V_7 -> V_92 -> V_115 ( V_27 ) ;
if ( V_52 < 0 ) {
F_13 ( V_86 -> V_46 , L_32
L_31 , V_52 ) ;
goto V_94;
}
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_71 = V_12 -> V_18 [ V_14 ] ;
if ( V_71 -> V_7 -> V_92 && V_71 -> V_7 -> V_92 -> V_115 ) {
V_52 = V_71 -> V_7 -> V_92 -> V_115 ( V_27 ,
V_71 ) ;
if ( V_52 < 0 ) {
F_13 ( V_71 -> V_46 ,
L_33 ,
V_52 ) ;
goto V_94;
}
}
}
if ( V_13 -> V_7 -> V_92 && V_13 -> V_7 -> V_92 -> V_115 ) {
V_52 = V_13 -> V_7 -> V_92 -> V_115 ( V_27 , V_13 ) ;
if ( V_52 < 0 ) {
F_13 ( V_13 -> V_46 ,
L_34 , V_52 ) ;
goto V_94;
}
}
if ( V_27 -> V_3 == V_6 &&
V_12 -> V_112 ) {
V_12 -> V_112 = 0 ;
F_49 ( & V_12 -> V_110 ) ;
}
F_10 ( V_12 , V_27 -> V_3 ,
V_117 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ )
F_45 ( V_12 -> V_18 [ V_14 ] , 0 ,
V_27 -> V_3 ) ;
F_45 ( V_13 , 0 , V_27 -> V_3 ) ;
V_94:
F_38 ( & V_12 -> V_15 ) ;
return V_52 ;
}
static void F_50 ( struct V_62 * V_63 ,
unsigned int V_118 )
{
struct V_119 * V_120 ;
int V_56 = F_51 ( V_118 ) ;
V_120 = F_52 ( V_63 , V_58 ) ;
V_120 -> F_26 = V_56 ;
V_120 -> F_24 = V_56 ;
}
int F_53 ( struct V_26 * V_27 ,
struct V_62 * V_63 ,
struct V_1 * V_2 )
{
int V_52 ;
if ( V_2 -> V_7 -> V_92 && V_2 -> V_7 -> V_92 -> V_121 ) {
V_52 = V_2 -> V_7 -> V_92 -> V_121 ( V_27 , V_63 , V_2 ) ;
if ( V_52 < 0 ) {
F_13 ( V_2 -> V_46 , L_35 ,
V_2 -> V_47 , V_52 ) ;
return V_52 ;
}
}
return 0 ;
}
static int F_54 ( struct V_26 * V_27 ,
struct V_62 * V_63 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_85 * V_86 = V_12 -> V_86 ;
struct V_1 * V_13 = V_12 -> V_13 ;
int V_14 , V_52 = 0 ;
F_34 ( & V_12 -> V_15 , V_12 -> V_91 ) ;
V_52 = F_14 ( V_27 , V_63 ) ;
if ( V_52 )
goto V_94;
if ( V_12 -> V_24 -> V_92 && V_12 -> V_24 -> V_92 -> V_121 ) {
V_52 = V_12 -> V_24 -> V_92 -> V_121 ( V_27 , V_63 ) ;
if ( V_52 < 0 ) {
F_13 ( V_12 -> V_116 -> V_46 , L_36
L_37 , V_52 ) ;
goto V_94;
}
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
struct V_1 * V_71 = V_12 -> V_18 [ V_14 ] ;
struct V_62 V_122 ;
if ( ! F_1 ( V_71 , V_27 -> V_3 ) )
continue;
V_122 = * V_63 ;
if ( V_71 -> V_98 )
F_50 ( & V_122 ,
V_71 -> V_98 ) ;
if ( V_71 -> V_99 )
F_50 ( & V_122 ,
V_71 -> V_99 ) ;
V_52 = F_53 ( V_27 , & V_122 , V_71 ) ;
if( V_52 < 0 )
goto V_123;
V_71 -> V_53 = F_15 ( & V_122 ) ;
V_71 -> V_56 = F_16 ( & V_122 ) ;
V_71 -> V_59 = F_17 (
F_18 ( & V_122 ) ) ;
}
V_52 = F_53 ( V_27 , V_63 , V_13 ) ;
if ( V_52 < 0 )
goto V_124;
if ( V_86 -> V_7 -> V_92 && V_86 -> V_7 -> V_92 -> V_121 ) {
V_52 = V_86 -> V_7 -> V_92 -> V_121 ( V_27 , V_63 ) ;
if ( V_52 < 0 ) {
F_13 ( V_86 -> V_46 , L_38 ,
V_86 -> V_21 . V_47 , V_52 ) ;
goto V_96;
}
}
V_13 -> V_53 = F_15 ( V_63 ) ;
V_13 -> V_56 = F_16 ( V_63 ) ;
V_13 -> V_59 =
F_17 ( F_18 ( V_63 ) ) ;
V_94:
F_38 ( & V_12 -> V_15 ) ;
return V_52 ;
V_96:
if ( V_13 -> V_7 -> V_92 && V_13 -> V_7 -> V_92 -> V_125 )
V_13 -> V_7 -> V_92 -> V_125 ( V_27 , V_13 ) ;
V_124:
V_14 = V_12 -> V_17 ;
V_123:
while ( -- V_14 >= 0 ) {
struct V_1 * V_71 = V_12 -> V_18 [ V_14 ] ;
if ( V_71 -> V_7 -> V_92 && V_71 -> V_7 -> V_92 -> V_125 )
V_71 -> V_7 -> V_92 -> V_125 ( V_27 , V_71 ) ;
V_71 -> V_53 = 0 ;
}
if ( V_12 -> V_24 -> V_92 && V_12 -> V_24 -> V_92 -> V_125 )
V_12 -> V_24 -> V_92 -> V_125 ( V_27 ) ;
F_38 ( & V_12 -> V_15 ) ;
return V_52 ;
}
static int F_55 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_85 * V_86 = V_12 -> V_86 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_71 ;
bool V_8 = V_27 -> V_3 == V_6 ;
int V_14 ;
F_34 ( & V_12 -> V_15 , V_12 -> V_91 ) ;
if ( V_13 -> V_20 == 1 ) {
V_13 -> V_53 = 0 ;
V_13 -> V_56 = 0 ;
V_13 -> V_59 = 0 ;
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_71 = V_12 -> V_18 [ V_14 ] ;
if ( V_71 -> V_20 == 1 ) {
V_71 -> V_53 = 0 ;
V_71 -> V_56 = 0 ;
V_71 -> V_59 = 0 ;
}
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
if ( ( V_8 && V_12 -> V_18 [ V_14 ] -> V_16 == 1 ) ||
( ! V_8 && V_12 -> V_18 [ V_14 ] -> V_19 == 1 ) )
F_45 ( V_12 -> V_18 [ V_14 ] , 1 ,
V_27 -> V_3 ) ;
}
if ( V_12 -> V_24 -> V_92 && V_12 -> V_24 -> V_92 -> V_125 )
V_12 -> V_24 -> V_92 -> V_125 ( V_27 ) ;
if ( V_86 -> V_7 -> V_92 && V_86 -> V_7 -> V_92 -> V_125 )
V_86 -> V_7 -> V_92 -> V_125 ( V_27 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_71 = V_12 -> V_18 [ V_14 ] ;
if ( V_71 -> V_7 -> V_92 && V_71 -> V_7 -> V_92 -> V_125 )
V_71 -> V_7 -> V_92 -> V_125 ( V_27 , V_71 ) ;
}
if ( V_13 -> V_7 -> V_92 && V_13 -> V_7 -> V_92 -> V_125 )
V_13 -> V_7 -> V_92 -> V_125 ( V_27 , V_13 ) ;
F_38 ( & V_12 -> V_15 ) ;
return 0 ;
}
static int F_56 ( struct V_26 * V_27 , int V_126 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_85 * V_86 = V_12 -> V_86 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_71 ;
int V_14 , V_52 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_71 = V_12 -> V_18 [ V_14 ] ;
if ( V_71 -> V_7 -> V_92 && V_71 -> V_7 -> V_92 -> V_127 ) {
V_52 = V_71 -> V_7 -> V_92 -> V_127 ( V_27 ,
V_126 , V_71 ) ;
if ( V_52 < 0 )
return V_52 ;
}
}
if ( V_86 -> V_7 -> V_92 && V_86 -> V_7 -> V_92 -> V_127 ) {
V_52 = V_86 -> V_7 -> V_92 -> V_127 ( V_27 , V_126 ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( V_13 -> V_7 -> V_92 && V_13 -> V_7 -> V_92 -> V_127 ) {
V_52 = V_13 -> V_7 -> V_92 -> V_127 ( V_27 , V_126 , V_13 ) ;
if ( V_52 < 0 )
return V_52 ;
}
if ( V_12 -> V_24 -> V_92 && V_12 -> V_24 -> V_92 -> V_127 ) {
V_52 = V_12 -> V_24 -> V_92 -> V_127 ( V_27 , V_126 ) ;
if ( V_52 < 0 )
return V_52 ;
}
return 0 ;
}
static int F_57 ( struct V_26 * V_27 ,
int V_126 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_71 ;
int V_14 , V_52 ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_71 = V_12 -> V_18 [ V_14 ] ;
if ( V_71 -> V_7 -> V_92 &&
V_71 -> V_7 -> V_92 -> V_128 ) {
V_52 = V_71 -> V_7 -> V_92 -> V_128 ( V_27 ,
V_126 , V_71 ) ;
if ( V_52 < 0 )
return V_52 ;
}
}
if ( V_13 -> V_7 -> V_92 && V_13 -> V_7 -> V_92 -> V_128 ) {
V_52 = V_13 -> V_7 -> V_92 -> V_128 ( V_27 , V_126 , V_13 ) ;
if ( V_52 < 0 )
return V_52 ;
}
return 0 ;
}
static T_2 F_58 ( struct V_26 * V_27 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_85 * V_86 = V_12 -> V_86 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_1 * V_71 ;
struct V_30 * V_31 = V_27 -> V_31 ;
T_2 V_129 = 0 ;
T_3 V_130 = 0 ;
T_3 V_131 = 0 ;
int V_14 ;
if ( V_86 -> V_7 -> V_92 && V_86 -> V_7 -> V_92 -> V_132 )
V_129 = V_86 -> V_7 -> V_92 -> V_132 ( V_27 ) ;
if ( V_13 -> V_7 -> V_92 && V_13 -> V_7 -> V_92 -> V_130 )
V_130 += V_13 -> V_7 -> V_92 -> V_130 ( V_27 , V_13 ) ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_71 = V_12 -> V_18 [ V_14 ] ;
if ( V_71 -> V_7 -> V_92 && V_71 -> V_7 -> V_92 -> V_130 )
V_131 = F_24 ( V_131 ,
V_71 -> V_7 -> V_92 -> V_130 ( V_27 ,
V_71 ) ) ;
}
V_130 += V_131 ;
V_31 -> V_130 = V_130 ;
return V_129 ;
}
static int F_59 ( struct V_11 * V_40 ,
struct V_11 * V_45 , int V_3 )
{
struct V_43 * V_44 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
if ( V_44 -> V_45 == V_45 && V_44 -> V_40 == V_40 )
return 0 ;
}
V_44 = F_60 ( sizeof( struct V_43 ) , V_133 ) ;
if ( ! V_44 )
return - V_134 ;
V_44 -> V_45 = V_45 ;
V_44 -> V_40 = V_40 ;
V_45 -> V_44 [ V_3 ] . V_31 = V_40 -> V_44 [ V_3 ] . V_31 ;
V_44 -> V_135 = V_136 ;
F_61 ( & V_44 -> V_137 , & V_40 -> V_44 [ V_3 ] . V_138 ) ;
F_61 ( & V_44 -> V_139 , & V_45 -> V_44 [ V_3 ] . V_140 ) ;
F_9 ( V_40 -> V_46 , L_39 ,
V_3 ? L_40 : L_41 , V_40 -> V_24 -> V_47 ,
V_3 ? L_42 : L_43 , V_45 -> V_24 -> V_47 ) ;
#ifdef F_62
if ( V_40 -> V_141 )
V_44 -> V_142 = F_63 ( V_45 -> V_24 -> V_47 , 0644 ,
V_40 -> V_141 , & V_44 -> V_135 ) ;
#endif
return 1 ;
}
static void F_64 ( struct V_11 * V_40 ,
struct V_11 * V_45 , int V_3 )
{
struct V_43 * V_44 ;
struct V_26 * V_143 , * V_144 ;
if ( ! V_45 -> V_44 [ V_3 ] . V_49 )
return;
V_144 = F_65 ( V_45 , V_3 ) ;
F_8 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_44 -> V_40 == V_40 )
continue;
F_9 ( V_40 -> V_46 , L_44 ,
V_3 ? L_40 : L_41 ,
V_44 -> V_40 -> V_24 -> V_47 ,
V_3 ? L_42 : L_43 , V_44 -> V_45 -> V_24 -> V_47 ) ;
V_143 = F_65 ( V_44 -> V_40 , V_3 ) ;
V_144 -> V_31 = V_143 -> V_31 ;
break;
}
}
void F_66 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 , * V_145 ;
F_67 (dpcm, d, &fe->dpcm[stream].be_clients, list_be) {
F_9 ( V_40 -> V_46 , L_45 ,
V_3 ? L_40 : L_41 ,
V_44 -> V_45 -> V_24 -> V_47 ) ;
if ( V_44 -> V_135 != V_146 )
continue;
F_9 ( V_40 -> V_46 , L_46 ,
V_3 ? L_40 : L_41 , V_40 -> V_24 -> V_47 ,
V_3 ? L_42 : L_43 , V_44 -> V_45 -> V_24 -> V_47 ) ;
F_64 ( V_40 , V_44 -> V_45 , V_3 ) ;
#ifdef F_62
F_68 ( V_44 -> V_142 ) ;
#endif
F_69 ( & V_44 -> V_137 ) ;
F_69 ( & V_44 -> V_139 ) ;
F_70 ( V_44 ) ;
}
}
static struct V_11 * F_71 ( struct V_147 * V_116 ,
struct V_148 * V_149 , int V_3 )
{
struct V_11 * V_45 ;
int V_14 ;
if ( V_3 == V_6 ) {
F_8 (be, &card->rtd_list, list) {
if ( ! V_45 -> V_24 -> V_102 )
continue;
if ( V_45 -> V_13 -> V_150 == V_149 )
return V_45 ;
for ( V_14 = 0 ; V_14 < V_45 -> V_17 ; V_14 ++ ) {
struct V_1 * V_2 = V_45 -> V_18 [ V_14 ] ;
if ( V_2 -> V_150 == V_149 )
return V_45 ;
}
}
} else {
F_8 (be, &card->rtd_list, list) {
if ( ! V_45 -> V_24 -> V_102 )
continue;
if ( V_45 -> V_13 -> V_151 == V_149 )
return V_45 ;
for ( V_14 = 0 ; V_14 < V_45 -> V_17 ; V_14 ++ ) {
struct V_1 * V_2 = V_45 -> V_18 [ V_14 ] ;
if ( V_2 -> V_151 == V_149 )
return V_45 ;
}
}
}
F_13 ( V_116 -> V_46 , L_47 ,
V_3 ? L_40 : L_41 , V_149 -> V_47 ) ;
return NULL ;
}
static inline struct V_148 *
F_72 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == V_6 )
return V_2 -> V_150 ;
else
return V_2 -> V_151 ;
}
static int F_73 ( struct V_152 * V_153 ,
struct V_148 * V_149 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_153 -> V_154 ; V_14 ++ ) {
if ( V_149 == V_153 -> V_155 [ V_14 ] )
return 1 ;
}
return 0 ;
}
static bool F_74 ( struct V_148 * V_149 ,
enum V_156 V_41 )
{
struct V_147 * V_116 = V_149 -> V_157 -> V_116 ;
struct V_11 * V_12 ;
int V_14 ;
if ( V_41 == V_158 ) {
F_8 (rtd, &card->rtd_list, list) {
if ( ! V_12 -> V_24 -> V_102 )
continue;
if ( V_12 -> V_13 -> V_150 == V_149 )
return true ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; ++ V_14 ) {
struct V_1 * V_2 = V_12 -> V_18 [ V_14 ] ;
if ( V_2 -> V_150 == V_149 )
return true ;
}
}
} else {
F_8 (rtd, &card->rtd_list, list) {
if ( ! V_12 -> V_24 -> V_102 )
continue;
if ( V_12 -> V_13 -> V_151 == V_149 )
return true ;
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; ++ V_14 ) {
struct V_1 * V_2 = V_12 -> V_18 [ V_14 ] ;
if ( V_2 -> V_151 == V_149 )
return true ;
}
}
}
return false ;
}
int F_75 ( struct V_11 * V_40 ,
int V_3 , struct V_152 * * V_153 )
{
struct V_1 * V_13 = V_40 -> V_13 ;
int V_159 ;
V_159 = F_76 ( V_13 , V_3 , V_153 ,
F_74 ) ;
F_9 ( V_40 -> V_46 , L_48 , V_159 ,
V_3 ? L_40 : L_41 ) ;
return V_159 ;
}
static int F_77 ( struct V_11 * V_40 , int V_3 ,
struct V_152 * * V_160 )
{
struct V_43 * V_44 ;
struct V_152 * V_153 = * V_160 ;
struct V_148 * V_149 ;
int V_161 = 0 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
unsigned int V_14 ;
V_149 = F_72 ( V_44 -> V_45 -> V_13 , V_3 ) ;
if ( V_149 && F_73 ( V_153 , V_149 ) )
continue;
for ( V_14 = 0 ; V_14 < V_44 -> V_45 -> V_17 ; V_14 ++ ) {
struct V_1 * V_2 = V_44 -> V_45 -> V_18 [ V_14 ] ;
V_149 = F_72 ( V_2 , V_3 ) ;
if ( V_149 && F_73 ( V_153 , V_149 ) )
continue;
}
F_9 ( V_40 -> V_46 , L_49 ,
V_3 ? L_40 : L_41 ,
V_44 -> V_45 -> V_24 -> V_47 , V_40 -> V_24 -> V_47 ) ;
V_44 -> V_135 = V_146 ;
V_44 -> V_45 -> V_44 [ V_3 ] . V_162 = V_163 ;
V_161 ++ ;
}
F_9 ( V_40 -> V_46 , L_50 , V_161 ) ;
return V_161 ;
}
static int F_78 ( struct V_11 * V_40 , int V_3 ,
struct V_152 * * V_160 )
{
struct V_147 * V_116 = V_40 -> V_116 ;
struct V_152 * V_153 = * V_160 ;
struct V_11 * V_45 ;
int V_14 , V_164 = 0 , V_165 ;
for ( V_14 = 0 ; V_14 < V_153 -> V_154 ; V_14 ++ ) {
switch ( V_153 -> V_155 [ V_14 ] -> V_166 ) {
case V_167 :
if ( V_3 != V_6 )
continue;
break;
case V_168 :
if ( V_3 != V_114 )
continue;
break;
default:
continue;
}
V_45 = F_71 ( V_116 , V_153 -> V_155 [ V_14 ] , V_3 ) ;
if ( ! V_45 ) {
F_13 ( V_40 -> V_46 , L_51 ,
V_153 -> V_155 [ V_14 ] -> V_47 ) ;
continue;
}
if ( ! V_45 -> V_24 -> V_102 )
continue;
if ( ! V_40 -> V_44 [ V_3 ] . V_31 && ! V_40 -> V_169 )
continue;
V_165 = F_59 ( V_40 , V_45 , V_3 ) ;
if ( V_165 < 0 ) {
F_13 ( V_40 -> V_46 , L_52 ,
V_153 -> V_155 [ V_14 ] -> V_47 ) ;
break;
} else if ( V_165 == 0 )
continue;
V_45 -> V_44 [ V_3 ] . V_162 = V_163 ;
V_164 ++ ;
}
F_9 ( V_40 -> V_46 , L_53 , V_164 ) ;
return V_164 ;
}
int F_79 ( struct V_11 * V_40 ,
int V_3 , struct V_152 * * V_153 , int V_164 )
{
if ( V_164 )
return F_78 ( V_40 , V_3 , V_153 ) ;
else
return F_77 ( V_40 , V_3 , V_153 ) ;
}
void F_80 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_44 -> V_45 -> V_44 [ V_3 ] . V_162 =
V_170 ;
}
static void F_81 ( struct V_11 * V_40 ,
int V_3 )
{
struct V_43 * V_44 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_144 =
F_65 ( V_45 , V_3 ) ;
if ( V_45 -> V_44 [ V_3 ] . V_49 == 0 )
F_13 ( V_45 -> V_46 , L_54 ,
V_3 ? L_40 : L_41 ,
V_45 -> V_44 [ V_3 ] . V_135 ) ;
if ( -- V_45 -> V_44 [ V_3 ] . V_49 != 0 )
continue;
if ( V_45 -> V_44 [ V_3 ] . V_135 != V_171 )
continue;
F_44 ( V_144 ) ;
V_144 -> V_31 = NULL ;
V_45 -> V_44 [ V_3 ] . V_135 = V_172 ;
}
}
int F_82 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 ;
int V_165 , V_173 = 0 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_144 =
F_65 ( V_45 , V_3 ) ;
if ( ! V_144 ) {
F_13 ( V_45 -> V_46 , L_55 ,
V_3 ? L_40 : L_41 ) ;
continue;
}
if ( ! F_83 ( V_40 , V_45 , V_3 ) )
continue;
if ( V_45 -> V_44 [ V_3 ] . V_49 == V_174 )
F_13 ( V_45 -> V_46 , L_56 ,
V_3 ? L_40 : L_41 ,
V_45 -> V_44 [ V_3 ] . V_135 ) ;
if ( V_45 -> V_44 [ V_3 ] . V_49 ++ != 0 )
continue;
if ( ( V_45 -> V_44 [ V_3 ] . V_135 != V_175 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_172 ) )
continue;
F_9 ( V_45 -> V_46 , L_57 ,
V_3 ? L_40 : L_41 , V_45 -> V_24 -> V_47 ) ;
V_144 -> V_31 = V_45 -> V_44 [ V_3 ] . V_31 ;
V_165 = F_30 ( V_144 ) ;
if ( V_165 < 0 ) {
F_13 ( V_45 -> V_46 , L_58 , V_165 ) ;
V_45 -> V_44 [ V_3 ] . V_49 -- ;
if ( V_45 -> V_44 [ V_3 ] . V_49 < 0 )
F_13 ( V_45 -> V_46 , L_59 ,
V_3 ? L_40 : L_41 ,
V_45 -> V_44 [ V_3 ] . V_135 ) ;
V_45 -> V_44 [ V_3 ] . V_135 = V_172 ;
goto V_176;
}
V_45 -> V_44 [ V_3 ] . V_135 = V_171 ;
V_173 ++ ;
}
return V_173 ;
V_176:
F_84 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_144 =
F_65 ( V_45 , V_3 ) ;
if ( ! F_83 ( V_40 , V_45 , V_3 ) )
continue;
if ( V_45 -> V_44 [ V_3 ] . V_49 == 0 )
F_13 ( V_45 -> V_46 , L_60 ,
V_3 ? L_40 : L_41 ,
V_45 -> V_44 [ V_3 ] . V_135 ) ;
if ( -- V_45 -> V_44 [ V_3 ] . V_49 != 0 )
continue;
if ( V_45 -> V_44 [ V_3 ] . V_135 != V_171 )
continue;
F_44 ( V_144 ) ;
V_144 -> V_31 = NULL ;
V_45 -> V_44 [ V_3 ] . V_135 = V_172 ;
}
return V_165 ;
}
static void F_85 ( struct V_30 * V_31 ,
struct V_4 * V_3 ,
T_1 V_33 )
{
V_31 -> V_29 . V_80 = V_3 -> V_80 ;
V_31 -> V_29 . V_81 = V_3 -> V_81 ;
V_31 -> V_29 . V_83 = V_3 -> V_83 ;
V_31 -> V_29 . V_84 = V_3 -> V_84 ;
if ( V_31 -> V_29 . V_33 )
V_31 -> V_29 . V_33 &= V_33 & V_3 -> V_33 ;
else
V_31 -> V_29 . V_33 = V_33 & V_3 -> V_33 ;
V_31 -> V_29 . V_10 = V_3 -> V_10 ;
}
static T_1 F_86 ( struct V_26 * V_27 )
{
struct V_11 * V_40 = V_27 -> V_51 ;
struct V_43 * V_44 ;
T_1 V_33 = V_82 ;
int V_3 = V_27 -> V_3 ;
if ( ! V_40 -> V_24 -> V_177 )
return V_33 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_66 * V_75 ;
struct V_4 * V_5 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_45 -> V_17 ; V_14 ++ ) {
V_75 = V_45 -> V_18 [ V_14 ] -> V_7 ;
if ( V_3 == V_6 )
V_5 = & V_75 -> V_8 ;
else
V_5 = & V_75 -> V_9 ;
V_33 &= V_5 -> V_33 ;
}
}
return V_33 ;
}
static void F_87 ( struct V_26 * V_27 )
{
struct V_30 * V_31 = V_27 -> V_31 ;
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_66 * V_74 = V_13 -> V_7 ;
T_1 V_178 = F_86 ( V_27 ) ;
if ( V_27 -> V_3 == V_6 )
F_85 ( V_31 , & V_74 -> V_8 , V_178 ) ;
else
F_85 ( V_31 , & V_74 -> V_9 , V_178 ) ;
}
static void F_88 ( struct V_11 * V_40 ,
int V_3 , enum V_179 V_135 )
{
struct V_26 * V_27 =
F_65 ( V_40 , V_3 ) ;
F_89 ( V_27 ) ;
if ( V_135 == V_170 && V_40 -> V_44 [ V_3 ] . V_180 ) {
F_90 ( V_27 ,
V_40 -> V_44 [ V_3 ] . V_180 - 1 ) ;
V_40 -> V_44 [ V_3 ] . V_180 = 0 ;
}
V_40 -> V_44 [ V_3 ] . V_162 = V_135 ;
F_91 ( V_27 ) ;
}
static int F_92 ( struct V_26 * V_143 ,
int V_3 )
{
struct V_43 * V_44 ;
struct V_11 * V_40 = V_143 -> V_51 ;
struct V_1 * V_181 = V_40 -> V_13 ;
int V_165 ;
if ( F_19 ( V_143 ) )
V_143 -> V_31 -> V_29 . V_32 |= V_103 ;
if ( V_181 -> V_20 ) {
V_165 = F_11 ( V_143 , V_181 ) ;
if ( V_165 < 0 )
return V_165 ;
}
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_144 =
F_65 ( V_45 , V_3 ) ;
struct V_11 * V_12 = V_144 -> V_51 ;
int V_14 ;
if ( V_12 -> V_24 -> V_182 )
continue;
if ( F_19 ( V_144 ) )
V_144 -> V_31 -> V_29 . V_32 |= V_103 ;
if ( V_12 -> V_13 -> V_20 ) {
V_165 = F_11 ( V_144 , V_12 -> V_13 ) ;
if ( V_165 < 0 )
return V_165 ;
}
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
if ( V_12 -> V_18 [ V_14 ] -> V_20 ) {
V_165 = F_11 ( V_144 ,
V_12 -> V_18 [ V_14 ] ) ;
if ( V_165 < 0 )
return V_165 ;
}
}
}
return 0 ;
}
static int F_93 ( struct V_26 * V_143 )
{
struct V_11 * V_40 = V_143 -> V_51 ;
struct V_30 * V_31 = V_143 -> V_31 ;
int V_3 = V_143 -> V_3 , V_52 = 0 ;
F_88 ( V_40 , V_3 , V_183 ) ;
V_52 = F_82 ( V_40 , V_143 -> V_3 ) ;
if ( V_52 < 0 ) {
F_13 ( V_40 -> V_46 , L_61 , V_52 ) ;
goto V_184;
}
F_9 ( V_40 -> V_46 , L_62 , V_40 -> V_24 -> V_47 ) ;
V_52 = F_30 ( V_143 ) ;
if ( V_52 < 0 ) {
F_13 ( V_40 -> V_46 , L_63 , V_52 ) ;
goto V_176;
}
V_40 -> V_44 [ V_3 ] . V_135 = V_171 ;
F_87 ( V_143 ) ;
F_29 ( V_31 ) ;
V_52 = F_92 ( V_143 , V_3 ) ;
if ( V_52 < 0 ) {
F_13 ( V_40 -> V_46 , L_64 ,
V_52 ) ;
goto V_176;
}
F_88 ( V_40 , V_3 , V_170 ) ;
return 0 ;
V_176:
F_81 ( V_40 , V_143 -> V_3 ) ;
V_184:
F_88 ( V_40 , V_3 , V_170 ) ;
return V_52 ;
}
int F_94 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_144 =
F_65 ( V_45 , V_3 ) ;
if ( ! F_83 ( V_40 , V_45 , V_3 ) )
continue;
if ( V_45 -> V_44 [ V_3 ] . V_49 == 0 )
F_13 ( V_45 -> V_46 , L_54 ,
V_3 ? L_40 : L_41 ,
V_45 -> V_44 [ V_3 ] . V_135 ) ;
if ( -- V_45 -> V_44 [ V_3 ] . V_49 != 0 )
continue;
if ( ( V_45 -> V_44 [ V_3 ] . V_135 != V_185 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_171 ) )
continue;
F_9 ( V_45 -> V_46 , L_65 ,
V_45 -> V_24 -> V_47 ) ;
F_44 ( V_144 ) ;
V_144 -> V_31 = NULL ;
V_45 -> V_44 [ V_3 ] . V_135 = V_172 ;
}
return 0 ;
}
static int F_95 ( struct V_26 * V_27 )
{
struct V_11 * V_40 = V_27 -> V_51 ;
int V_3 = V_27 -> V_3 ;
F_88 ( V_40 , V_3 , V_183 ) ;
F_94 ( V_40 , V_27 -> V_3 ) ;
F_9 ( V_40 -> V_46 , L_66 , V_40 -> V_24 -> V_47 ) ;
F_44 ( V_27 ) ;
F_7 ( V_40 , V_3 , V_48 ) ;
V_40 -> V_44 [ V_3 ] . V_135 = V_172 ;
F_88 ( V_40 , V_3 , V_170 ) ;
return 0 ;
}
int F_96 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_144 =
F_65 ( V_45 , V_3 ) ;
if ( ! F_83 ( V_40 , V_45 , V_3 ) )
continue;
if ( ! F_97 ( V_40 , V_45 , V_3 ) )
continue;
if ( V_45 -> V_44 [ V_3 ] . V_49 > 1 )
continue;
if ( ( V_45 -> V_44 [ V_3 ] . V_135 != V_186 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_187 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_185 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_188 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_189 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_190 ) )
continue;
F_9 ( V_45 -> V_46 , L_67 ,
V_45 -> V_24 -> V_47 ) ;
F_55 ( V_144 ) ;
V_45 -> V_44 [ V_3 ] . V_135 = V_185 ;
}
return 0 ;
}
static int F_98 ( struct V_26 * V_27 )
{
struct V_11 * V_40 = V_27 -> V_51 ;
int V_165 , V_3 = V_27 -> V_3 ;
F_34 ( & V_40 -> V_116 -> V_191 , V_192 ) ;
F_88 ( V_40 , V_3 , V_183 ) ;
F_9 ( V_40 -> V_46 , L_68 , V_40 -> V_24 -> V_47 ) ;
V_165 = F_55 ( V_27 ) ;
if ( V_165 < 0 )
F_13 ( V_40 -> V_46 , L_69 ,
V_40 -> V_24 -> V_47 ) ;
V_165 = F_96 ( V_40 , V_3 ) ;
V_40 -> V_44 [ V_3 ] . V_135 = V_185 ;
F_88 ( V_40 , V_3 , V_170 ) ;
F_38 ( & V_40 -> V_116 -> V_191 ) ;
return 0 ;
}
int F_99 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 ;
int V_52 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_144 =
F_65 ( V_45 , V_3 ) ;
if ( ! F_83 ( V_40 , V_45 , V_3 ) )
continue;
memcpy ( & V_44 -> V_121 , & V_40 -> V_44 [ V_3 ] . V_121 ,
sizeof( struct V_62 ) ) ;
if ( V_45 -> V_24 -> V_182 ) {
V_52 = V_45 -> V_24 -> V_182 ( V_45 ,
& V_44 -> V_121 ) ;
if ( V_52 < 0 ) {
F_13 ( V_45 -> V_46 ,
L_70 ,
V_52 ) ;
goto V_176;
}
}
if ( ! F_100 ( V_40 , V_45 , V_3 ) )
continue;
if ( ( V_45 -> V_44 [ V_3 ] . V_135 != V_171 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_186 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_185 ) )
continue;
F_9 ( V_45 -> V_46 , L_71 ,
V_45 -> V_24 -> V_47 ) ;
V_52 = F_54 ( V_144 , & V_44 -> V_121 ) ;
if ( V_52 < 0 ) {
F_13 ( V_44 -> V_45 -> V_46 ,
L_72 , V_52 ) ;
goto V_176;
}
V_45 -> V_44 [ V_3 ] . V_135 = V_186 ;
}
return 0 ;
V_176:
F_84 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_144 =
F_65 ( V_45 , V_3 ) ;
if ( ! F_83 ( V_40 , V_45 , V_3 ) )
continue;
if ( ! F_97 ( V_40 , V_45 , V_3 ) )
continue;
if ( ( V_45 -> V_44 [ V_3 ] . V_135 != V_171 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_186 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_185 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_189 ) )
continue;
F_55 ( V_144 ) ;
}
return V_52 ;
}
static int F_101 ( struct V_26 * V_27 ,
struct V_62 * V_63 )
{
struct V_11 * V_40 = V_27 -> V_51 ;
int V_52 , V_3 = V_27 -> V_3 ;
F_34 ( & V_40 -> V_116 -> V_191 , V_192 ) ;
F_88 ( V_40 , V_3 , V_183 ) ;
memcpy ( & V_40 -> V_44 [ V_27 -> V_3 ] . V_121 , V_63 ,
sizeof( struct V_62 ) ) ;
V_52 = F_99 ( V_40 , V_27 -> V_3 ) ;
if ( V_52 < 0 ) {
F_13 ( V_40 -> V_46 , L_72 , V_52 ) ;
goto V_94;
}
F_9 ( V_40 -> V_46 , L_73 ,
V_40 -> V_24 -> V_47 , F_15 ( V_63 ) ,
F_16 ( V_63 ) , F_18 ( V_63 ) ) ;
V_52 = F_54 ( V_27 , V_63 ) ;
if ( V_52 < 0 ) {
F_13 ( V_40 -> V_46 , L_74 , V_52 ) ;
F_96 ( V_40 , V_3 ) ;
} else
V_40 -> V_44 [ V_3 ] . V_135 = V_186 ;
V_94:
F_88 ( V_40 , V_3 , V_170 ) ;
F_38 ( & V_40 -> V_116 -> V_191 ) ;
return V_52 ;
}
static int F_102 ( struct V_43 * V_44 ,
struct V_26 * V_27 , int V_126 )
{
int V_52 ;
F_9 ( V_44 -> V_45 -> V_46 , L_75 ,
V_44 -> V_45 -> V_24 -> V_47 , V_126 ) ;
V_52 = F_56 ( V_27 , V_126 ) ;
if ( V_52 < 0 )
F_13 ( V_44 -> V_45 -> V_46 , L_76 , V_52 ) ;
return V_52 ;
}
int F_103 ( struct V_11 * V_40 , int V_3 ,
int V_126 )
{
struct V_43 * V_44 ;
int V_52 = 0 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_144 =
F_65 ( V_45 , V_3 ) ;
if ( ! F_83 ( V_40 , V_45 , V_3 ) )
continue;
switch ( V_126 ) {
case V_193 :
if ( ( V_45 -> V_44 [ V_3 ] . V_135 != V_187 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_189 ) )
continue;
V_52 = F_102 ( V_44 , V_144 , V_126 ) ;
if ( V_52 )
return V_52 ;
V_45 -> V_44 [ V_3 ] . V_135 = V_194 ;
break;
case V_195 :
if ( ( V_45 -> V_44 [ V_3 ] . V_135 != V_190 ) )
continue;
V_52 = F_102 ( V_44 , V_144 , V_126 ) ;
if ( V_52 )
return V_52 ;
V_45 -> V_44 [ V_3 ] . V_135 = V_194 ;
break;
case V_196 :
if ( ( V_45 -> V_44 [ V_3 ] . V_135 != V_188 ) )
continue;
V_52 = F_102 ( V_44 , V_144 , V_126 ) ;
if ( V_52 )
return V_52 ;
V_45 -> V_44 [ V_3 ] . V_135 = V_194 ;
break;
case V_197 :
if ( V_45 -> V_44 [ V_3 ] . V_135 != V_194 )
continue;
if ( ! F_97 ( V_40 , V_45 , V_3 ) )
continue;
V_52 = F_102 ( V_44 , V_144 , V_126 ) ;
if ( V_52 )
return V_52 ;
V_45 -> V_44 [ V_3 ] . V_135 = V_189 ;
break;
case V_198 :
if ( V_45 -> V_44 [ V_3 ] . V_135 != V_194 )
continue;
if ( ! F_97 ( V_40 , V_45 , V_3 ) )
continue;
V_52 = F_102 ( V_44 , V_144 , V_126 ) ;
if ( V_52 )
return V_52 ;
V_45 -> V_44 [ V_3 ] . V_135 = V_190 ;
break;
case V_199 :
if ( V_45 -> V_44 [ V_3 ] . V_135 != V_194 )
continue;
if ( ! F_97 ( V_40 , V_45 , V_3 ) )
continue;
V_52 = F_102 ( V_44 , V_144 , V_126 ) ;
if ( V_52 )
return V_52 ;
V_45 -> V_44 [ V_3 ] . V_135 = V_188 ;
break;
}
}
return V_52 ;
}
static int F_90 ( struct V_26 * V_27 , int V_126 )
{
struct V_11 * V_40 = V_27 -> V_51 ;
int V_3 = V_27 -> V_3 , V_52 ;
enum V_200 V_127 = V_40 -> V_24 -> V_127 [ V_3 ] ;
V_40 -> V_44 [ V_3 ] . V_162 = V_183 ;
switch ( V_127 ) {
case V_201 :
F_9 ( V_40 -> V_46 , L_77 ,
V_40 -> V_24 -> V_47 , V_126 ) ;
V_52 = F_56 ( V_27 , V_126 ) ;
if ( V_52 < 0 ) {
F_13 ( V_40 -> V_46 , L_78 , V_52 ) ;
goto V_94;
}
V_52 = F_103 ( V_40 , V_27 -> V_3 , V_126 ) ;
break;
case V_202 :
V_52 = F_103 ( V_40 , V_27 -> V_3 , V_126 ) ;
if ( V_52 < 0 ) {
F_13 ( V_40 -> V_46 , L_78 , V_52 ) ;
goto V_94;
}
F_9 ( V_40 -> V_46 , L_79 ,
V_40 -> V_24 -> V_47 , V_126 ) ;
V_52 = F_56 ( V_27 , V_126 ) ;
break;
case V_203 :
F_9 ( V_40 -> V_46 , L_80 ,
V_40 -> V_24 -> V_47 , V_126 ) ;
V_52 = F_57 ( V_27 , V_126 ) ;
if ( V_52 < 0 ) {
F_13 ( V_40 -> V_46 , L_78 , V_52 ) ;
goto V_94;
}
break;
default:
F_13 ( V_40 -> V_46 , L_81 , V_126 ,
V_40 -> V_24 -> V_47 ) ;
V_52 = - V_65 ;
goto V_94;
}
switch ( V_126 ) {
case V_193 :
case V_195 :
case V_196 :
V_40 -> V_44 [ V_3 ] . V_135 = V_194 ;
break;
case V_197 :
case V_198 :
V_40 -> V_44 [ V_3 ] . V_135 = V_189 ;
break;
case V_199 :
V_40 -> V_44 [ V_3 ] . V_135 = V_188 ;
break;
}
V_94:
V_40 -> V_44 [ V_3 ] . V_162 = V_170 ;
return V_52 ;
}
static int F_104 ( struct V_26 * V_27 , int V_126 )
{
struct V_11 * V_40 = V_27 -> V_51 ;
int V_3 = V_27 -> V_3 ;
if ( V_40 -> V_44 [ V_3 ] . V_162 != V_170 ) {
V_40 -> V_44 [ V_3 ] . V_180 = V_126 + 1 ;
return 0 ;
}
return F_90 ( V_27 , V_126 ) ;
}
int F_105 ( struct V_11 * V_40 , int V_3 )
{
struct V_43 * V_44 ;
int V_52 = 0 ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
struct V_26 * V_144 =
F_65 ( V_45 , V_3 ) ;
if ( ! F_83 ( V_40 , V_45 , V_3 ) )
continue;
if ( ( V_45 -> V_44 [ V_3 ] . V_135 != V_186 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_189 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 != V_190 ) )
continue;
F_9 ( V_45 -> V_46 , L_82 ,
V_45 -> V_24 -> V_47 ) ;
V_52 = F_48 ( V_144 ) ;
if ( V_52 < 0 ) {
F_13 ( V_45 -> V_46 , L_83 ,
V_52 ) ;
break;
}
V_45 -> V_44 [ V_3 ] . V_135 = V_187 ;
}
return V_52 ;
}
static int F_106 ( struct V_26 * V_27 )
{
struct V_11 * V_40 = V_27 -> V_51 ;
int V_3 = V_27 -> V_3 , V_52 = 0 ;
F_34 ( & V_40 -> V_116 -> V_191 , V_192 ) ;
F_9 ( V_40 -> V_46 , L_84 , V_40 -> V_24 -> V_47 ) ;
F_88 ( V_40 , V_3 , V_183 ) ;
if ( F_107 ( & V_40 -> V_44 [ V_3 ] . V_138 ) ) {
F_13 ( V_40 -> V_46 , L_85 ,
V_40 -> V_24 -> V_47 ) ;
V_52 = - V_65 ;
goto V_94;
}
V_52 = F_105 ( V_40 , V_27 -> V_3 ) ;
if ( V_52 < 0 )
goto V_94;
V_52 = F_48 ( V_27 ) ;
if ( V_52 < 0 ) {
F_13 ( V_40 -> V_46 , L_86 ,
V_40 -> V_24 -> V_47 ) ;
goto V_94;
}
F_7 ( V_40 , V_3 , V_117 ) ;
V_40 -> V_44 [ V_3 ] . V_135 = V_187 ;
V_94:
F_88 ( V_40 , V_3 , V_170 ) ;
F_38 ( & V_40 -> V_116 -> V_191 ) ;
return V_52 ;
}
static int F_108 ( struct V_26 * V_27 ,
unsigned int V_126 , void * V_204 )
{
struct V_11 * V_12 = V_27 -> V_51 ;
struct V_85 * V_86 = V_12 -> V_86 ;
if ( V_86 -> V_7 -> V_92 && V_86 -> V_7 -> V_92 -> V_205 )
return V_86 -> V_7 -> V_92 -> V_205 ( V_27 , V_126 , V_204 ) ;
return F_109 ( V_27 , V_126 , V_204 ) ;
}
static int F_110 ( struct V_11 * V_40 , int V_3 )
{
struct V_26 * V_27 =
F_65 ( V_40 , V_3 ) ;
enum V_200 V_127 = V_40 -> V_24 -> V_127 [ V_3 ] ;
int V_165 ;
F_9 ( V_40 -> V_46 , L_87 ,
V_3 ? L_40 : L_41 , V_40 -> V_24 -> V_47 ) ;
if ( V_127 == V_203 ) {
F_9 ( V_40 -> V_46 , L_88 ,
V_40 -> V_24 -> V_47 ) ;
V_165 = F_57 ( V_27 , V_197 ) ;
if ( V_165 < 0 )
F_13 ( V_40 -> V_46 , L_78 , V_165 ) ;
} else {
F_9 ( V_40 -> V_46 , L_89 ,
V_40 -> V_24 -> V_47 ) ;
V_165 = F_103 ( V_40 , V_3 , V_197 ) ;
if ( V_165 < 0 )
F_13 ( V_40 -> V_46 , L_78 , V_165 ) ;
}
V_165 = F_96 ( V_40 , V_3 ) ;
if ( V_165 < 0 )
F_13 ( V_40 -> V_46 , L_90 , V_165 ) ;
V_165 = F_94 ( V_40 , V_3 ) ;
if ( V_165 < 0 )
F_13 ( V_40 -> V_46 , L_91 , V_165 ) ;
F_7 ( V_40 , V_3 , V_206 ) ;
return 0 ;
}
static int F_111 ( struct V_11 * V_40 , int V_3 )
{
struct V_26 * V_27 =
F_65 ( V_40 , V_3 ) ;
struct V_43 * V_44 ;
enum V_200 V_127 = V_40 -> V_24 -> V_127 [ V_3 ] ;
int V_52 ;
F_9 ( V_40 -> V_46 , L_92 ,
V_3 ? L_40 : L_41 , V_40 -> V_24 -> V_47 ) ;
if ( V_40 -> V_44 [ V_3 ] . V_135 == V_185 ||
V_40 -> V_44 [ V_3 ] . V_135 == V_172 )
return - V_65 ;
V_52 = F_82 ( V_40 , V_3 ) ;
if ( V_52 < 0 )
goto V_207;
if ( V_40 -> V_44 [ V_3 ] . V_135 == V_171 )
return 0 ;
V_52 = F_99 ( V_40 , V_3 ) ;
if ( V_52 < 0 )
goto V_107;
if ( V_40 -> V_44 [ V_3 ] . V_135 == V_186 )
return 0 ;
V_52 = F_105 ( V_40 , V_3 ) ;
if ( V_52 < 0 )
goto V_125;
F_7 ( V_40 , V_3 , V_206 ) ;
if ( V_40 -> V_44 [ V_3 ] . V_135 == V_187 ||
V_40 -> V_44 [ V_3 ] . V_135 == V_189 )
return 0 ;
if ( V_127 == V_203 ) {
F_9 ( V_40 -> V_46 , L_93 ,
V_40 -> V_24 -> V_47 ) ;
V_52 = F_57 ( V_27 , V_193 ) ;
if ( V_52 < 0 ) {
F_13 ( V_40 -> V_46 , L_94 , V_52 ) ;
goto V_125;
}
} else {
F_9 ( V_40 -> V_46 , L_95 ,
V_40 -> V_24 -> V_47 ) ;
V_52 = F_103 ( V_40 , V_3 ,
V_193 ) ;
if ( V_52 < 0 ) {
F_13 ( V_40 -> V_46 , L_78 , V_52 ) ;
goto V_125;
}
}
return 0 ;
V_125:
F_96 ( V_40 , V_3 ) ;
V_107:
F_94 ( V_40 , V_3 ) ;
V_207:
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
if ( V_45 -> V_44 [ V_3 ] . V_135 != V_194 )
V_44 -> V_135 = V_146 ;
}
return V_52 ;
}
static int F_112 ( struct V_11 * V_40 , int V_3 )
{
int V_52 ;
F_88 ( V_40 , V_3 , V_163 ) ;
V_52 = F_111 ( V_40 , V_3 ) ;
if ( V_52 < 0 )
F_13 ( V_40 -> V_46 , L_96 ) ;
F_88 ( V_40 , V_3 , V_170 ) ;
return V_52 ;
}
static int F_113 ( struct V_11 * V_40 , int V_3 )
{
int V_52 ;
F_88 ( V_40 , V_3 , V_163 ) ;
V_52 = F_110 ( V_40 , V_3 ) ;
if ( V_52 < 0 )
F_13 ( V_40 -> V_46 , L_97 ) ;
F_88 ( V_40 , V_3 , V_170 ) ;
return V_52 ;
}
int F_114 ( struct V_147 * V_116 )
{
struct V_11 * V_40 ;
int V_208 , V_164 , V_159 ;
F_34 ( & V_116 -> V_191 , V_192 ) ;
F_8 (fe, &card->rtd_list, list) {
struct V_152 * V_153 ;
if ( ! V_40 -> V_24 -> V_101 )
continue;
if ( ! V_40 -> V_13 -> V_20 )
continue;
F_9 ( V_40 -> V_46 , L_98 ,
V_40 -> V_24 -> V_47 ) ;
if ( ! V_40 -> V_13 -> V_7 -> V_8 . V_83
|| ! V_40 -> V_71 -> V_7 -> V_8 . V_83 )
goto V_9;
if ( ! V_40 -> V_13 -> V_16
|| ! V_40 -> V_71 -> V_16 )
goto V_9;
V_159 = F_75 ( V_40 , V_6 , & V_153 ) ;
if ( V_159 < 0 ) {
F_22 ( V_40 -> V_46 , L_99 ,
V_40 -> V_24 -> V_47 , L_41 ) ;
F_38 ( & V_116 -> V_191 ) ;
return V_159 ;
}
V_164 = F_79 ( V_40 , V_6 , & V_153 , 1 ) ;
if ( V_164 ) {
F_112 ( V_40 , V_6 ) ;
F_80 ( V_40 , V_6 ) ;
F_66 ( V_40 , V_6 ) ;
}
V_208 = F_79 ( V_40 , V_6 , & V_153 , 0 ) ;
if ( V_208 ) {
F_113 ( V_40 , V_6 ) ;
F_80 ( V_40 , V_6 ) ;
F_66 ( V_40 , V_6 ) ;
}
F_115 ( & V_153 ) ;
V_9:
if ( ! V_40 -> V_13 -> V_7 -> V_9 . V_83
|| ! V_40 -> V_71 -> V_7 -> V_9 . V_83 )
continue;
if ( ! V_40 -> V_13 -> V_19
|| ! V_40 -> V_71 -> V_19 )
continue;
V_159 = F_75 ( V_40 , V_114 , & V_153 ) ;
if ( V_159 < 0 ) {
F_22 ( V_40 -> V_46 , L_99 ,
V_40 -> V_24 -> V_47 , L_40 ) ;
F_38 ( & V_116 -> V_191 ) ;
return V_159 ;
}
V_164 = F_79 ( V_40 , V_114 , & V_153 , 1 ) ;
if ( V_164 ) {
F_112 ( V_40 , V_114 ) ;
F_80 ( V_40 , V_114 ) ;
F_66 ( V_40 , V_114 ) ;
}
V_208 = F_79 ( V_40 , V_114 , & V_153 , 0 ) ;
if ( V_208 ) {
F_113 ( V_40 , V_114 ) ;
F_80 ( V_40 , V_114 ) ;
F_66 ( V_40 , V_114 ) ;
}
F_115 ( & V_153 ) ;
}
F_38 ( & V_116 -> V_191 ) ;
return 0 ;
}
int F_116 ( struct V_11 * V_40 , int V_209 )
{
struct V_43 * V_44 ;
struct V_210 * V_211 =
& V_40 -> V_44 [ V_6 ] . V_138 ;
F_8 (dpcm, clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
int V_14 ;
if ( V_45 -> V_24 -> V_212 )
continue;
for ( V_14 = 0 ; V_14 < V_45 -> V_17 ; V_14 ++ ) {
struct V_1 * V_2 = V_45 -> V_18 [ V_14 ] ;
struct V_66 * V_213 = V_2 -> V_7 ;
F_9 ( V_45 -> V_46 , L_100 ,
V_45 -> V_24 -> V_47 ) ;
if ( V_213 -> V_92 && V_213 -> V_92 -> V_214 &&
V_2 -> V_16 )
V_213 -> V_92 -> V_214 ( V_2 , V_209 ) ;
}
}
return 0 ;
}
static int F_117 ( struct V_26 * V_143 )
{
struct V_11 * V_40 = V_143 -> V_51 ;
struct V_43 * V_44 ;
struct V_152 * V_153 ;
int V_52 ;
int V_3 = V_143 -> V_3 ;
F_34 ( & V_40 -> V_116 -> V_191 , V_192 ) ;
V_40 -> V_44 [ V_3 ] . V_31 = V_143 -> V_31 ;
V_52 = F_75 ( V_40 , V_3 , & V_153 ) ;
if ( V_52 < 0 ) {
F_38 ( & V_40 -> V_116 -> V_191 ) ;
return V_52 ;
} else if ( V_52 == 0 ) {
F_9 ( V_40 -> V_46 , L_101 ,
V_40 -> V_24 -> V_47 , V_3 ? L_40 : L_41 ) ;
}
F_79 ( V_40 , V_3 , & V_153 , 1 ) ;
V_52 = F_93 ( V_143 ) ;
if ( V_52 < 0 ) {
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_44 -> V_135 = V_146 ;
F_66 ( V_40 , V_3 ) ;
V_40 -> V_44 [ V_3 ] . V_31 = NULL ;
}
F_80 ( V_40 , V_3 ) ;
F_115 ( & V_153 ) ;
F_38 ( & V_40 -> V_116 -> V_191 ) ;
return V_52 ;
}
static int F_118 ( struct V_26 * V_143 )
{
struct V_11 * V_40 = V_143 -> V_51 ;
struct V_43 * V_44 ;
int V_3 = V_143 -> V_3 , V_52 ;
F_34 ( & V_40 -> V_116 -> V_191 , V_192 ) ;
V_52 = F_95 ( V_143 ) ;
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_44 -> V_135 = V_146 ;
F_66 ( V_40 , V_3 ) ;
V_40 -> V_44 [ V_3 ] . V_31 = NULL ;
F_38 ( & V_40 -> V_116 -> V_191 ) ;
return V_52 ;
}
int F_119 ( struct V_11 * V_12 , int V_215 )
{
struct V_85 * V_86 = V_12 -> V_86 ;
struct V_1 * V_71 ;
struct V_1 * V_13 = V_12 -> V_13 ;
struct V_216 * V_217 ;
char V_218 [ 64 ] ;
int V_52 = 0 , V_8 = 0 , V_9 = 0 ;
int V_14 ;
if ( V_12 -> V_24 -> V_101 || V_12 -> V_24 -> V_102 ) {
V_8 = V_12 -> V_24 -> V_219 ;
V_9 = V_12 -> V_24 -> V_220 ;
} else {
for ( V_14 = 0 ; V_14 < V_12 -> V_17 ; V_14 ++ ) {
V_71 = V_12 -> V_18 [ V_14 ] ;
if ( V_71 -> V_7 -> V_8 . V_83 )
V_8 = 1 ;
if ( V_71 -> V_7 -> V_9 . V_83 )
V_9 = 1 ;
}
V_9 = V_9 && V_13 -> V_7 -> V_9 . V_83 ;
V_8 = V_8 && V_13 -> V_7 -> V_8 . V_83 ;
}
if ( V_12 -> V_24 -> V_221 ) {
V_8 = 1 ;
V_9 = 0 ;
}
if ( V_12 -> V_24 -> V_222 ) {
V_8 = 0 ;
V_9 = 1 ;
}
if ( V_12 -> V_24 -> V_102 ) {
snprintf ( V_218 , sizeof( V_218 ) , L_102 ,
V_12 -> V_24 -> V_111 ) ;
V_52 = F_120 ( V_12 -> V_116 -> V_223 , V_218 , V_215 ,
V_8 , V_9 , & V_217 ) ;
} else {
if ( V_12 -> V_24 -> V_101 )
snprintf ( V_218 , sizeof( V_218 ) , L_103 ,
V_12 -> V_24 -> V_111 ) ;
else
snprintf ( V_218 , sizeof( V_218 ) , L_104 ,
V_12 -> V_24 -> V_111 ,
( V_12 -> V_17 > 1 ) ?
L_12 : V_12 -> V_71 -> V_47 , V_215 ) ;
V_52 = F_121 ( V_12 -> V_116 -> V_223 , V_218 , V_215 , V_8 ,
V_9 , & V_217 ) ;
}
if ( V_52 < 0 ) {
F_13 ( V_12 -> V_116 -> V_46 , L_105 ,
V_12 -> V_24 -> V_47 ) ;
return V_52 ;
}
F_9 ( V_12 -> V_116 -> V_46 , L_106 , V_215 , V_218 ) ;
F_122 ( & V_12 -> V_110 , F_42 ) ;
V_217 -> V_224 = V_12 -> V_24 -> V_224 ;
V_12 -> V_217 = V_217 ;
V_217 -> V_51 = V_12 ;
if ( V_12 -> V_24 -> V_102 ) {
if ( V_8 )
V_217 -> V_225 [ V_6 ] . V_27 -> V_51 = V_12 ;
if ( V_9 )
V_217 -> V_225 [ V_114 ] . V_27 -> V_51 = V_12 ;
goto V_94;
}
if ( V_12 -> V_24 -> V_101 ) {
V_12 -> V_92 . V_95 = F_117 ;
V_12 -> V_92 . V_121 = F_101 ;
V_12 -> V_92 . V_115 = F_106 ;
V_12 -> V_92 . V_127 = F_104 ;
V_12 -> V_92 . V_125 = F_98 ;
V_12 -> V_92 . V_107 = F_118 ;
V_12 -> V_92 . V_132 = F_58 ;
V_12 -> V_92 . V_205 = F_108 ;
} else {
V_12 -> V_92 . V_95 = F_30 ;
V_12 -> V_92 . V_121 = F_54 ;
V_12 -> V_92 . V_115 = F_48 ;
V_12 -> V_92 . V_127 = F_56 ;
V_12 -> V_92 . V_125 = F_55 ;
V_12 -> V_92 . V_107 = F_44 ;
V_12 -> V_92 . V_132 = F_58 ;
V_12 -> V_92 . V_205 = F_108 ;
}
if ( V_86 -> V_7 -> V_92 ) {
V_12 -> V_92 . V_226 = V_86 -> V_7 -> V_92 -> V_226 ;
V_12 -> V_92 . V_227 = V_86 -> V_7 -> V_92 -> V_227 ;
V_12 -> V_92 . V_228 = V_86 -> V_7 -> V_92 -> V_228 ;
V_12 -> V_92 . V_229 = V_86 -> V_7 -> V_92 -> V_229 ;
V_12 -> V_92 . V_230 = V_86 -> V_7 -> V_92 -> V_230 ;
V_12 -> V_92 . V_231 = V_86 -> V_7 -> V_92 -> V_231 ;
}
if ( V_8 )
F_123 ( V_217 , V_6 , & V_12 -> V_92 ) ;
if ( V_9 )
F_123 ( V_217 , V_114 , & V_12 -> V_92 ) ;
if ( V_86 -> V_7 -> V_232 ) {
V_52 = V_86 -> V_7 -> V_232 ( V_12 ) ;
if ( V_52 < 0 ) {
F_13 ( V_86 -> V_46 ,
L_107 ,
V_52 ) ;
return V_52 ;
}
}
V_217 -> V_233 = V_86 -> V_7 -> V_234 ;
V_94:
F_124 ( V_12 -> V_116 -> V_46 , L_108 ,
( V_12 -> V_17 > 1 ) ? L_12 : V_12 -> V_71 -> V_47 ,
V_13 -> V_47 ) ;
return V_52 ;
}
int F_125 ( struct V_11 * V_40 , int V_3 )
{
if ( V_40 -> V_44 [ V_3 ] . V_162 == V_183 )
return 1 ;
return 0 ;
}
int F_83 ( struct V_11 * V_40 ,
struct V_11 * V_45 , int V_3 )
{
if ( ( V_40 -> V_44 [ V_3 ] . V_162 == V_183 ) ||
( ( V_40 -> V_44 [ V_3 ] . V_162 == V_163 ) &&
V_45 -> V_44 [ V_3 ] . V_162 ) )
return 1 ;
return 0 ;
}
struct V_26 *
F_65 ( struct V_11 * V_45 , int V_3 )
{
return V_45 -> V_217 -> V_225 [ V_3 ] . V_27 ;
}
enum V_235
F_126 ( struct V_11 * V_45 , int V_3 )
{
return V_45 -> V_44 [ V_3 ] . V_135 ;
}
void F_127 ( struct V_11 * V_45 ,
int V_3 , enum V_235 V_135 )
{
V_45 -> V_44 [ V_3 ] . V_135 = V_135 ;
}
int F_97 ( struct V_11 * V_40 ,
struct V_11 * V_45 , int V_3 )
{
struct V_43 * V_44 ;
int V_135 ;
F_8 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_44 -> V_40 == V_40 )
continue;
V_135 = V_44 -> V_40 -> V_44 [ V_3 ] . V_135 ;
if ( V_135 == V_194 ||
V_135 == V_188 ||
V_135 == V_190 )
return 0 ;
}
return 1 ;
}
int F_100 ( struct V_11 * V_40 ,
struct V_11 * V_45 , int V_3 )
{
struct V_43 * V_44 ;
int V_135 ;
F_8 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_44 -> V_40 == V_40 )
continue;
V_135 = V_44 -> V_40 -> V_44 [ V_3 ] . V_135 ;
if ( V_135 == V_194 ||
V_135 == V_188 ||
V_135 == V_190 ||
V_135 == V_187 )
return 0 ;
}
return 1 ;
}
static const char * F_128 ( enum V_235 V_135 )
{
switch ( V_135 ) {
case V_175 :
return L_109 ;
case V_171 :
return L_110 ;
case V_186 :
return L_111 ;
case V_187 :
return L_112 ;
case V_194 :
return L_113 ;
case V_189 :
return L_114 ;
case V_190 :
return L_115 ;
case V_188 :
return L_116 ;
case V_185 :
return L_117 ;
case V_172 :
return L_118 ;
}
return L_119 ;
}
static T_4 F_129 ( struct V_11 * V_40 ,
int V_3 , char * V_236 , T_5 V_237 )
{
struct V_62 * V_63 = & V_40 -> V_44 [ V_3 ] . V_121 ;
struct V_43 * V_44 ;
T_4 V_129 = 0 ;
V_129 += snprintf ( V_236 + V_129 , V_237 - V_129 ,
L_120 , V_40 -> V_24 -> V_47 ,
V_3 ? L_121 : L_122 ) ;
V_129 += snprintf ( V_236 + V_129 , V_237 - V_129 , L_123 ,
F_128 ( V_40 -> V_44 [ V_3 ] . V_135 ) ) ;
if ( ( V_40 -> V_44 [ V_3 ] . V_135 >= V_186 ) &&
( V_40 -> V_44 [ V_3 ] . V_135 <= V_189 ) )
V_129 += snprintf ( V_236 + V_129 , V_237 - V_129 ,
L_124
L_125 ,
F_130 ( F_18 ( V_63 ) ) ,
F_16 ( V_63 ) ,
F_15 ( V_63 ) ) ;
V_129 += snprintf ( V_236 + V_129 , V_237 - V_129 , L_126 ) ;
if ( F_107 ( & V_40 -> V_44 [ V_3 ] . V_138 ) ) {
V_129 += snprintf ( V_236 + V_129 , V_237 - V_129 ,
L_127 ) ;
goto V_94;
}
F_8 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_11 * V_45 = V_44 -> V_45 ;
V_63 = & V_44 -> V_121 ;
V_129 += snprintf ( V_236 + V_129 , V_237 - V_129 ,
L_128 , V_45 -> V_24 -> V_47 ) ;
V_129 += snprintf ( V_236 + V_129 , V_237 - V_129 ,
L_129 ,
F_128 ( V_45 -> V_44 [ V_3 ] . V_135 ) ) ;
if ( ( V_45 -> V_44 [ V_3 ] . V_135 >= V_186 ) &&
( V_45 -> V_44 [ V_3 ] . V_135 <= V_189 ) )
V_129 += snprintf ( V_236 + V_129 , V_237 - V_129 ,
L_130
L_125 ,
F_130 ( F_18 ( V_63 ) ) ,
F_16 ( V_63 ) ,
F_15 ( V_63 ) ) ;
}
V_94:
return V_129 ;
}
static T_4 F_131 ( struct V_238 * V_238 , char T_6 * V_239 ,
T_5 V_173 , T_7 * V_240 )
{
struct V_11 * V_40 = V_238 -> V_51 ;
T_4 V_241 = V_242 , V_129 = 0 , V_52 = 0 ;
char * V_236 ;
V_236 = F_132 ( V_241 , V_133 ) ;
if ( ! V_236 )
return - V_134 ;
if ( V_40 -> V_13 -> V_7 -> V_8 . V_83 )
V_129 += F_129 ( V_40 , V_6 ,
V_236 + V_129 , V_241 - V_129 ) ;
if ( V_40 -> V_13 -> V_7 -> V_9 . V_83 )
V_129 += F_129 ( V_40 , V_114 ,
V_236 + V_129 , V_241 - V_129 ) ;
V_52 = F_133 ( V_239 , V_173 , V_240 , V_236 , V_129 ) ;
F_70 ( V_236 ) ;
return V_52 ;
}
void F_134 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_24 )
return;
if ( ! V_12 -> V_116 -> V_243 )
return;
V_12 -> V_141 = F_135 ( V_12 -> V_24 -> V_47 ,
V_12 -> V_116 -> V_243 ) ;
if ( ! V_12 -> V_141 ) {
F_9 ( V_12 -> V_46 ,
L_131 ,
V_12 -> V_24 -> V_47 ) ;
return;
}
F_136 ( L_132 , 0444 , V_12 -> V_141 ,
V_12 , & V_244 ) ;
}
