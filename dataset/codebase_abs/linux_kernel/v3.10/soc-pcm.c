static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
struct V_5 * V_6 ;
F_2 (dpcm, &fe->dpcm[dir].be_clients, list_be) {
struct V_1 * V_7 = V_6 -> V_7 ;
F_3 ( V_7 -> V_8 , L_1 ,
V_7 -> V_9 -> V_10 , V_4 , V_3 ) ;
F_4 ( V_7 , V_3 , V_4 ) ;
}
F_4 ( V_2 , V_3 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_15 = V_12 -> V_16 ;
int V_17 ;
if ( ! V_14 -> V_18 -> V_19 &&
! V_15 -> V_9 -> V_19 )
return 0 ;
if ( ! V_14 -> V_20 ) {
F_6 ( V_14 -> V_8 ,
L_2 ) ;
return 0 ;
}
F_3 ( V_14 -> V_8 , L_3 , V_14 -> V_20 ) ;
V_17 = F_7 ( V_12 -> V_21 ,
V_22 ,
V_14 -> V_20 , V_14 -> V_20 ) ;
if ( V_17 < 0 ) {
F_8 ( V_14 -> V_8 ,
L_4 ,
V_17 ) ;
return V_17 ;
}
return 0 ;
}
static void F_9 ( struct V_11 * V_12 ,
struct V_13 * V_23 )
{
int V_17 , V_24 , V_25 ;
if ( V_12 -> V_26 == V_27 )
V_25 = V_23 -> V_18 -> V_28 . V_29 ;
else
V_25 = V_23 -> V_18 -> V_30 . V_29 ;
if ( ! V_25 )
return;
for ( V_24 = 0 ; V_24 < F_10 ( V_31 ) ; V_24 ++ ) {
if ( V_25 >= V_31 [ V_24 ] )
continue;
V_17 = F_11 ( V_12 -> V_21 , 0 ,
V_31 [ V_24 ] , V_25 ) ;
if ( V_17 != 0 )
F_6 ( V_23 -> V_8 ,
L_5 ,
V_25 , V_31 [ V_24 ] , V_17 ) ;
}
}
static int F_12 ( struct V_11 * V_12 )
{
struct V_1 * V_15 = V_12 -> V_16 ;
struct V_32 * V_21 = V_12 -> V_21 ;
struct V_33 * V_34 = V_15 -> V_34 ;
struct V_13 * V_35 = V_15 -> V_35 ;
struct V_13 * V_36 = V_15 -> V_36 ;
struct V_37 * V_38 = V_35 -> V_18 ;
struct V_37 * V_39 = V_36 -> V_18 ;
int V_17 = 0 ;
F_13 ( V_35 -> V_8 ) ;
F_13 ( V_36 -> V_8 ) ;
F_13 ( V_34 -> V_8 ) ;
F_14 ( & V_15 -> V_40 , V_15 -> V_41 ) ;
if ( V_35 -> V_18 -> V_42 -> V_43 ) {
V_17 = V_35 -> V_18 -> V_42 -> V_43 ( V_12 , V_35 ) ;
if ( V_17 < 0 ) {
F_8 ( V_35 -> V_8 , L_6
L_7 , V_35 -> V_10 , V_17 ) ;
goto V_44;
}
}
if ( V_34 -> V_18 -> V_42 && V_34 -> V_18 -> V_42 -> V_45 ) {
V_17 = V_34 -> V_18 -> V_42 -> V_45 ( V_12 ) ;
if ( V_17 < 0 ) {
F_8 ( V_34 -> V_8 , L_8
L_7 , V_34 -> V_10 , V_17 ) ;
goto V_46;
}
}
if ( V_36 -> V_18 -> V_42 -> V_43 ) {
V_17 = V_36 -> V_18 -> V_42 -> V_43 ( V_12 , V_36 ) ;
if ( V_17 < 0 ) {
F_8 ( V_36 -> V_8 , L_9
L_7 , V_36 -> V_10 , V_17 ) ;
goto V_47;
}
}
if ( V_15 -> V_9 -> V_42 && V_15 -> V_9 -> V_42 -> V_43 ) {
V_17 = V_15 -> V_9 -> V_42 -> V_43 ( V_12 ) ;
if ( V_17 < 0 ) {
F_15 ( L_10 ,
V_15 -> V_9 -> V_10 , V_17 ) ;
goto V_48;
}
}
if ( V_15 -> V_9 -> V_49 || V_15 -> V_9 -> V_50 )
goto V_49;
if ( V_12 -> V_26 == V_27 ) {
V_21 -> V_51 . V_52 =
F_16 ( V_39 -> V_28 . V_52 ,
V_38 -> V_28 . V_52 ) ;
V_21 -> V_51 . V_53 =
F_17 ( V_39 -> V_28 . V_53 ,
V_38 -> V_28 . V_53 ) ;
V_21 -> V_51 . V_54 =
F_16 ( V_39 -> V_28 . V_54 ,
V_38 -> V_28 . V_54 ) ;
V_21 -> V_51 . V_55 =
F_17 ( V_39 -> V_28 . V_55 ,
V_38 -> V_28 . V_55 ) ;
V_21 -> V_51 . V_56 =
V_39 -> V_28 . V_56 & V_38 -> V_28 . V_56 ;
V_21 -> V_51 . V_57 =
V_39 -> V_28 . V_57 & V_38 -> V_28 . V_57 ;
if ( V_39 -> V_28 . V_57
& ( V_58 | V_59 ) )
V_21 -> V_51 . V_57 |= V_38 -> V_28 . V_57 ;
if ( V_38 -> V_28 . V_57
& ( V_58 | V_59 ) )
V_21 -> V_51 . V_57 |= V_39 -> V_28 . V_57 ;
} else {
V_21 -> V_51 . V_52 =
F_16 ( V_39 -> V_30 . V_52 ,
V_38 -> V_30 . V_52 ) ;
V_21 -> V_51 . V_53 =
F_17 ( V_39 -> V_30 . V_53 ,
V_38 -> V_30 . V_53 ) ;
V_21 -> V_51 . V_54 =
F_16 ( V_39 -> V_30 . V_54 ,
V_38 -> V_30 . V_54 ) ;
V_21 -> V_51 . V_55 =
F_17 ( V_39 -> V_30 . V_55 ,
V_38 -> V_30 . V_55 ) ;
V_21 -> V_51 . V_56 =
V_39 -> V_30 . V_56 & V_38 -> V_30 . V_56 ;
V_21 -> V_51 . V_57 =
V_39 -> V_30 . V_57 & V_38 -> V_30 . V_57 ;
if ( V_39 -> V_30 . V_57
& ( V_58 | V_59 ) )
V_21 -> V_51 . V_57 |= V_38 -> V_30 . V_57 ;
if ( V_38 -> V_30 . V_57
& ( V_58 | V_59 ) )
V_21 -> V_51 . V_57 |= V_39 -> V_30 . V_57 ;
}
V_17 = - V_60 ;
F_18 ( V_21 ) ;
if ( ! V_21 -> V_51 . V_57 ) {
F_19 ( V_61 L_11 ,
V_36 -> V_10 , V_35 -> V_10 ) ;
goto V_62;
}
if ( ! V_21 -> V_51 . V_56 ) {
F_19 ( V_61 L_12 ,
V_36 -> V_10 , V_35 -> V_10 ) ;
goto V_62;
}
if ( ! V_21 -> V_51 . V_54 || ! V_21 -> V_51 . V_55 ||
V_21 -> V_51 . V_54 > V_21 -> V_51 . V_55 ) {
F_19 ( V_61 L_13 ,
V_36 -> V_10 , V_35 -> V_10 ) ;
goto V_62;
}
F_9 ( V_12 , V_36 ) ;
F_9 ( V_12 , V_35 ) ;
if ( V_35 -> V_63 ) {
V_17 = F_5 ( V_12 , V_35 ) ;
if ( V_17 != 0 )
goto V_62;
}
if ( V_36 -> V_63 ) {
V_17 = F_5 ( V_12 , V_36 ) ;
if ( V_17 != 0 )
goto V_62;
}
F_20 ( L_14 ,
V_36 -> V_10 , V_35 -> V_10 ) ;
F_20 ( L_15 , V_21 -> V_51 . V_57 ) ;
F_20 ( L_16 , V_21 -> V_51 . V_54 ,
V_21 -> V_51 . V_55 ) ;
F_20 ( L_17 , V_21 -> V_51 . V_52 ,
V_21 -> V_51 . V_53 ) ;
V_49:
if ( V_12 -> V_26 == V_27 ) {
V_35 -> V_64 ++ ;
V_36 -> V_64 ++ ;
} else {
V_35 -> V_65 ++ ;
V_36 -> V_65 ++ ;
}
V_35 -> V_63 ++ ;
V_36 -> V_63 ++ ;
V_15 -> V_66 -> V_63 ++ ;
F_21 ( & V_15 -> V_40 ) ;
return 0 ;
V_62:
if ( V_15 -> V_9 -> V_42 && V_15 -> V_9 -> V_42 -> V_67 )
V_15 -> V_9 -> V_42 -> V_67 ( V_12 ) ;
V_48:
if ( V_36 -> V_18 -> V_42 -> V_67 )
V_36 -> V_18 -> V_42 -> V_67 ( V_12 , V_36 ) ;
V_47:
if ( V_34 -> V_18 -> V_42 && V_34 -> V_18 -> V_42 -> V_68 )
V_34 -> V_18 -> V_42 -> V_68 ( V_12 ) ;
V_46:
if ( V_35 -> V_18 -> V_42 -> V_67 )
V_35 -> V_18 -> V_42 -> V_67 ( V_12 , V_35 ) ;
V_44:
F_21 ( & V_15 -> V_40 ) ;
F_22 ( V_34 -> V_8 ) ;
F_22 ( V_36 -> V_8 ) ;
F_22 ( V_35 -> V_8 ) ;
return V_17 ;
}
static void F_23 ( struct V_69 * V_70 )
{
struct V_1 * V_15 =
F_24 ( V_70 , struct V_1 , V_71 . V_70 ) ;
struct V_13 * V_36 = V_15 -> V_36 ;
F_14 ( & V_15 -> V_40 , V_15 -> V_41 ) ;
F_3 ( V_15 -> V_8 , L_18 ,
V_36 -> V_18 -> V_28 . V_72 ,
V_36 -> V_64 ? L_19 : L_20 ,
V_15 -> V_73 ? L_21 : L_22 ) ;
if ( V_15 -> V_73 == 1 ) {
V_15 -> V_73 = 0 ;
F_4 ( V_15 , V_27 ,
V_74 ) ;
}
F_21 ( & V_15 -> V_40 ) ;
}
static int F_25 ( struct V_11 * V_12 )
{
struct V_1 * V_15 = V_12 -> V_16 ;
struct V_33 * V_34 = V_15 -> V_34 ;
struct V_13 * V_35 = V_15 -> V_35 ;
struct V_13 * V_36 = V_15 -> V_36 ;
struct V_75 * V_66 = V_15 -> V_66 ;
F_14 ( & V_15 -> V_40 , V_15 -> V_41 ) ;
if ( V_12 -> V_26 == V_27 ) {
V_35 -> V_64 -- ;
V_36 -> V_64 -- ;
} else {
V_35 -> V_65 -- ;
V_36 -> V_65 -- ;
}
V_35 -> V_63 -- ;
V_36 -> V_63 -- ;
V_66 -> V_63 -- ;
if ( ! V_35 -> V_63 )
V_35 -> V_20 = 0 ;
if ( ! V_36 -> V_63 )
V_36 -> V_20 = 0 ;
F_26 ( V_36 , 1 , V_12 -> V_26 ) ;
if ( V_35 -> V_18 -> V_42 -> V_67 )
V_35 -> V_18 -> V_42 -> V_67 ( V_12 , V_35 ) ;
if ( V_36 -> V_18 -> V_42 -> V_67 )
V_36 -> V_18 -> V_42 -> V_67 ( V_12 , V_36 ) ;
if ( V_15 -> V_9 -> V_42 && V_15 -> V_9 -> V_42 -> V_67 )
V_15 -> V_9 -> V_42 -> V_67 ( V_12 ) ;
if ( V_34 -> V_18 -> V_42 && V_34 -> V_18 -> V_42 -> V_68 )
V_34 -> V_18 -> V_42 -> V_68 ( V_12 ) ;
V_35 -> V_21 = NULL ;
if ( V_12 -> V_26 == V_27 ) {
if ( ! V_15 -> V_76 || V_66 -> V_77 ||
V_15 -> V_9 -> V_77 ) {
F_4 ( V_15 ,
V_27 ,
V_74 ) ;
} else {
V_15 -> V_73 = 1 ;
F_27 ( & V_15 -> V_71 ,
F_28 ( V_15 -> V_76 ) ) ;
}
} else {
F_4 ( V_15 , V_78 ,
V_74 ) ;
}
F_21 ( & V_15 -> V_40 ) ;
F_22 ( V_34 -> V_8 ) ;
F_22 ( V_36 -> V_8 ) ;
F_22 ( V_35 -> V_8 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 )
{
struct V_1 * V_15 = V_12 -> V_16 ;
struct V_33 * V_34 = V_15 -> V_34 ;
struct V_13 * V_35 = V_15 -> V_35 ;
struct V_13 * V_36 = V_15 -> V_36 ;
int V_17 = 0 ;
F_14 ( & V_15 -> V_40 , V_15 -> V_41 ) ;
if ( V_15 -> V_9 -> V_42 && V_15 -> V_9 -> V_42 -> V_79 ) {
V_17 = V_15 -> V_9 -> V_42 -> V_79 ( V_12 ) ;
if ( V_17 < 0 ) {
F_8 ( V_15 -> V_80 -> V_8 , L_23
L_24 , V_17 ) ;
goto V_44;
}
}
if ( V_34 -> V_18 -> V_42 && V_34 -> V_18 -> V_42 -> V_79 ) {
V_17 = V_34 -> V_18 -> V_42 -> V_79 ( V_12 ) ;
if ( V_17 < 0 ) {
F_8 ( V_34 -> V_8 , L_25
L_24 , V_17 ) ;
goto V_44;
}
}
if ( V_36 -> V_18 -> V_42 -> V_79 ) {
V_17 = V_36 -> V_18 -> V_42 -> V_79 ( V_12 , V_36 ) ;
if ( V_17 < 0 ) {
F_8 ( V_36 -> V_8 , L_26 ,
V_17 ) ;
goto V_44;
}
}
if ( V_35 -> V_18 -> V_42 -> V_79 ) {
V_17 = V_35 -> V_18 -> V_42 -> V_79 ( V_12 , V_35 ) ;
if ( V_17 < 0 ) {
F_8 ( V_35 -> V_8 , L_26 ,
V_17 ) ;
goto V_44;
}
}
if ( V_12 -> V_26 == V_27 &&
V_15 -> V_73 ) {
V_15 -> V_73 = 0 ;
F_30 ( & V_15 -> V_71 ) ;
}
F_4 ( V_15 , V_12 -> V_26 ,
V_81 ) ;
F_26 ( V_36 , 0 , V_12 -> V_26 ) ;
V_44:
F_21 ( & V_15 -> V_40 ) ;
return V_17 ;
}
static int F_31 ( struct V_11 * V_12 ,
struct V_82 * V_83 )
{
struct V_1 * V_15 = V_12 -> V_16 ;
struct V_33 * V_34 = V_15 -> V_34 ;
struct V_13 * V_35 = V_15 -> V_35 ;
struct V_13 * V_36 = V_15 -> V_36 ;
int V_17 = 0 ;
F_14 ( & V_15 -> V_40 , V_15 -> V_41 ) ;
if ( V_15 -> V_9 -> V_42 && V_15 -> V_9 -> V_42 -> V_84 ) {
V_17 = V_15 -> V_9 -> V_42 -> V_84 ( V_12 , V_83 ) ;
if ( V_17 < 0 ) {
F_8 ( V_15 -> V_80 -> V_8 , L_27
L_28 , V_17 ) ;
goto V_44;
}
}
if ( V_36 -> V_18 -> V_42 -> V_84 ) {
V_17 = V_36 -> V_18 -> V_42 -> V_84 ( V_12 , V_83 , V_36 ) ;
if ( V_17 < 0 ) {
F_8 ( V_36 -> V_8 , L_29
L_24 , V_36 -> V_10 , V_17 ) ;
goto V_85;
}
}
if ( V_35 -> V_18 -> V_42 -> V_84 ) {
V_17 = V_35 -> V_18 -> V_42 -> V_84 ( V_12 , V_83 , V_35 ) ;
if ( V_17 < 0 ) {
F_8 ( V_35 -> V_8 , L_30 ,
V_35 -> V_10 , V_17 ) ;
goto V_86;
}
}
if ( V_34 -> V_18 -> V_42 && V_34 -> V_18 -> V_42 -> V_84 ) {
V_17 = V_34 -> V_18 -> V_42 -> V_84 ( V_12 , V_83 ) ;
if ( V_17 < 0 ) {
F_8 ( V_34 -> V_8 , L_30 ,
V_34 -> V_10 , V_17 ) ;
goto V_46;
}
}
V_35 -> V_20 = F_32 ( V_83 ) ;
V_36 -> V_20 = F_32 ( V_83 ) ;
V_44:
F_21 ( & V_15 -> V_40 ) ;
return V_17 ;
V_46:
if ( V_35 -> V_18 -> V_42 -> V_87 )
V_35 -> V_18 -> V_42 -> V_87 ( V_12 , V_35 ) ;
V_86:
if ( V_36 -> V_18 -> V_42 -> V_87 )
V_36 -> V_18 -> V_42 -> V_87 ( V_12 , V_36 ) ;
V_85:
if ( V_15 -> V_9 -> V_42 && V_15 -> V_9 -> V_42 -> V_87 )
V_15 -> V_9 -> V_42 -> V_87 ( V_12 ) ;
F_21 ( & V_15 -> V_40 ) ;
return V_17 ;
}
static int F_33 ( struct V_11 * V_12 )
{
struct V_1 * V_15 = V_12 -> V_16 ;
struct V_33 * V_34 = V_15 -> V_34 ;
struct V_13 * V_35 = V_15 -> V_35 ;
struct V_13 * V_36 = V_15 -> V_36 ;
struct V_75 * V_66 = V_15 -> V_66 ;
F_14 ( & V_15 -> V_40 , V_15 -> V_41 ) ;
if ( ! V_66 -> V_63 )
F_26 ( V_36 , 1 , V_12 -> V_26 ) ;
if ( V_15 -> V_9 -> V_42 && V_15 -> V_9 -> V_42 -> V_87 )
V_15 -> V_9 -> V_42 -> V_87 ( V_12 ) ;
if ( V_34 -> V_18 -> V_42 && V_34 -> V_18 -> V_42 -> V_87 )
V_34 -> V_18 -> V_42 -> V_87 ( V_12 ) ;
if ( V_36 -> V_18 -> V_42 -> V_87 )
V_36 -> V_18 -> V_42 -> V_87 ( V_12 , V_36 ) ;
if ( V_35 -> V_18 -> V_42 -> V_87 )
V_35 -> V_18 -> V_42 -> V_87 ( V_12 , V_35 ) ;
F_21 ( & V_15 -> V_40 ) ;
return 0 ;
}
static int F_34 ( struct V_11 * V_12 , int V_88 )
{
struct V_1 * V_15 = V_12 -> V_16 ;
struct V_33 * V_34 = V_15 -> V_34 ;
struct V_13 * V_35 = V_15 -> V_35 ;
struct V_13 * V_36 = V_15 -> V_36 ;
int V_17 ;
if ( V_36 -> V_18 -> V_42 -> V_89 ) {
V_17 = V_36 -> V_18 -> V_42 -> V_89 ( V_12 , V_88 , V_36 ) ;
if ( V_17 < 0 )
return V_17 ;
}
if ( V_34 -> V_18 -> V_42 && V_34 -> V_18 -> V_42 -> V_89 ) {
V_17 = V_34 -> V_18 -> V_42 -> V_89 ( V_12 , V_88 ) ;
if ( V_17 < 0 )
return V_17 ;
}
if ( V_35 -> V_18 -> V_42 -> V_89 ) {
V_17 = V_35 -> V_18 -> V_42 -> V_89 ( V_12 , V_88 , V_35 ) ;
if ( V_17 < 0 )
return V_17 ;
}
return 0 ;
}
static int F_35 ( struct V_11 * V_12 ,
int V_88 )
{
struct V_1 * V_15 = V_12 -> V_16 ;
struct V_33 * V_34 = V_15 -> V_34 ;
struct V_13 * V_35 = V_15 -> V_35 ;
struct V_13 * V_36 = V_15 -> V_36 ;
int V_17 ;
if ( V_36 -> V_18 -> V_42 -> V_90 ) {
V_17 = V_36 -> V_18 -> V_42 -> V_90 ( V_12 , V_88 , V_36 ) ;
if ( V_17 < 0 )
return V_17 ;
}
if ( V_34 -> V_18 -> V_90 ) {
V_17 = V_34 -> V_18 -> V_90 ( V_12 , V_88 ) ;
if ( V_17 < 0 )
return V_17 ;
}
if ( V_35 -> V_18 -> V_42 -> V_90 ) {
V_17 = V_35 -> V_18 -> V_42 -> V_90 ( V_12 , V_88 , V_35 ) ;
if ( V_17 < 0 )
return V_17 ;
}
return 0 ;
}
static T_1 F_36 ( struct V_11 * V_12 )
{
struct V_1 * V_15 = V_12 -> V_16 ;
struct V_33 * V_34 = V_15 -> V_34 ;
struct V_13 * V_35 = V_15 -> V_35 ;
struct V_13 * V_36 = V_15 -> V_36 ;
struct V_32 * V_21 = V_12 -> V_21 ;
T_1 V_91 = 0 ;
T_2 V_92 = 0 ;
if ( V_34 -> V_18 -> V_42 && V_34 -> V_18 -> V_42 -> V_93 )
V_91 = V_34 -> V_18 -> V_42 -> V_93 ( V_12 ) ;
if ( V_35 -> V_18 -> V_42 -> V_92 )
V_92 += V_35 -> V_18 -> V_42 -> V_92 ( V_12 , V_35 ) ;
if ( V_36 -> V_18 -> V_42 -> V_92 )
V_92 += V_36 -> V_18 -> V_42 -> V_92 ( V_12 , V_36 ) ;
if ( V_34 -> V_18 -> V_92 )
V_92 += V_34 -> V_18 -> V_92 ( V_12 , V_36 ) ;
V_21 -> V_92 = V_92 ;
return V_91 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_1 * V_7 , int V_26 )
{
struct V_5 * V_6 ;
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
if ( V_6 -> V_7 == V_7 && V_6 -> V_2 == V_2 )
return 0 ;
}
V_6 = F_38 ( sizeof( struct V_5 ) , V_94 ) ;
if ( ! V_6 )
return - V_95 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_2 = V_2 ;
V_7 -> V_6 [ V_26 ] . V_21 = V_2 -> V_6 [ V_26 ] . V_21 ;
V_6 -> V_96 = V_97 ;
F_39 ( & V_6 -> V_98 , & V_2 -> V_6 [ V_26 ] . V_99 ) ;
F_39 ( & V_6 -> V_100 , & V_7 -> V_6 [ V_26 ] . V_101 ) ;
F_3 ( V_2 -> V_8 , L_31 ,
V_26 ? L_32 : L_33 , V_2 -> V_9 -> V_10 ,
V_26 ? L_34 : L_35 , V_7 -> V_9 -> V_10 ) ;
#ifdef F_40
V_6 -> V_102 = F_41 ( V_7 -> V_9 -> V_10 , 0644 ,
V_2 -> V_103 , & V_6 -> V_96 ) ;
#endif
return 1 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_1 * V_7 , int V_26 )
{
struct V_5 * V_6 ;
struct V_11 * V_104 , * V_105 ;
if ( ! V_7 -> V_6 [ V_26 ] . V_106 )
return;
V_105 = F_43 ( V_7 , V_26 ) ;
F_2 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_6 -> V_2 == V_2 )
continue;
F_3 ( V_2 -> V_8 , L_36 ,
V_26 ? L_32 : L_33 ,
V_6 -> V_2 -> V_9 -> V_10 ,
V_26 ? L_34 : L_35 , V_6 -> V_7 -> V_9 -> V_10 ) ;
V_104 = F_43 ( V_6 -> V_2 , V_26 ) ;
V_105 -> V_21 = V_104 -> V_21 ;
break;
}
}
static void F_44 ( struct V_1 * V_2 , int V_26 )
{
struct V_5 * V_6 , * V_107 ;
F_45 (dpcm, d, &fe->dpcm[stream].be_clients, list_be) {
F_3 ( V_2 -> V_8 , L_37 ,
V_26 ? L_32 : L_33 ,
V_6 -> V_7 -> V_9 -> V_10 ) ;
if ( V_6 -> V_96 != V_108 )
continue;
F_3 ( V_2 -> V_8 , L_38 ,
V_26 ? L_32 : L_33 , V_2 -> V_9 -> V_10 ,
V_26 ? L_34 : L_35 , V_6 -> V_7 -> V_9 -> V_10 ) ;
F_42 ( V_2 , V_6 -> V_7 , V_26 ) ;
#ifdef F_40
F_46 ( V_6 -> V_102 ) ;
#endif
F_47 ( & V_6 -> V_98 ) ;
F_47 ( & V_6 -> V_100 ) ;
F_48 ( V_6 ) ;
}
}
static struct V_1 * F_49 ( struct V_109 * V_80 ,
struct V_110 * V_111 , int V_26 )
{
struct V_1 * V_7 ;
int V_24 ;
if ( V_26 == V_27 ) {
for ( V_24 = 0 ; V_24 < V_80 -> V_112 ; V_24 ++ ) {
V_7 = & V_80 -> V_15 [ V_24 ] ;
if ( ! V_7 -> V_9 -> V_50 )
continue;
if ( V_7 -> V_35 -> V_113 == V_111 ||
V_7 -> V_36 -> V_113 == V_111 )
return V_7 ;
}
} else {
for ( V_24 = 0 ; V_24 < V_80 -> V_112 ; V_24 ++ ) {
V_7 = & V_80 -> V_15 [ V_24 ] ;
if ( ! V_7 -> V_9 -> V_50 )
continue;
if ( V_7 -> V_35 -> V_114 == V_111 ||
V_7 -> V_36 -> V_114 == V_111 )
return V_7 ;
}
}
F_8 ( V_80 -> V_8 , L_39 ,
V_26 ? L_32 : L_33 , V_111 -> V_10 ) ;
return NULL ;
}
static inline struct V_110 *
F_50 ( struct V_1 * V_15 , int V_26 )
{
if ( V_26 == V_27 )
return V_15 -> V_35 -> V_113 ;
else
return V_15 -> V_35 -> V_114 ;
}
static inline struct V_110 *
F_51 ( struct V_1 * V_15 , int V_26 )
{
if ( V_26 == V_27 )
return V_15 -> V_36 -> V_113 ;
else
return V_15 -> V_36 -> V_114 ;
}
static int F_52 ( struct V_115 * V_116 ,
struct V_110 * V_111 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_116 -> V_117 ; V_24 ++ ) {
if ( V_111 == V_116 -> V_118 [ V_24 ] )
return 1 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
int V_26 , struct V_115 * * V_119 )
{
struct V_13 * V_35 = V_2 -> V_35 ;
struct V_115 * V_116 ;
int V_120 ;
V_116 = F_38 ( sizeof( struct V_115 ) +
sizeof( struct V_110 * ) , V_94 ) ;
if ( V_116 == NULL )
return - V_95 ;
V_120 = F_54 ( V_35 , V_26 , & V_116 ) ;
F_3 ( V_2 -> V_8 , L_40 , V_120 ,
V_26 ? L_32 : L_33 ) ;
* V_119 = V_116 ;
return V_120 ;
}
static inline void F_55 ( struct V_115 * * V_116 )
{
F_48 ( * V_116 ) ;
}
static int F_56 ( struct V_1 * V_2 , int V_26 ,
struct V_115 * * V_119 )
{
struct V_5 * V_6 ;
struct V_115 * V_116 = * V_119 ;
struct V_110 * V_111 ;
int V_121 = 0 ;
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
V_111 = F_50 ( V_6 -> V_7 , V_26 ) ;
if ( V_111 && F_52 ( V_116 , V_111 ) )
continue;
V_111 = F_51 ( V_6 -> V_7 , V_26 ) ;
if ( V_111 && F_52 ( V_116 , V_111 ) )
continue;
F_3 ( V_2 -> V_8 , L_41 ,
V_26 ? L_32 : L_33 ,
V_6 -> V_7 -> V_9 -> V_10 , V_2 -> V_9 -> V_10 ) ;
V_6 -> V_96 = V_108 ;
V_6 -> V_7 -> V_6 [ V_26 ] . V_122 = V_123 ;
V_121 ++ ;
}
F_3 ( V_2 -> V_8 , L_42 , V_121 ) ;
return V_121 ;
}
static int F_57 ( struct V_1 * V_2 , int V_26 ,
struct V_115 * * V_119 )
{
struct V_109 * V_80 = V_2 -> V_80 ;
struct V_115 * V_116 = * V_119 ;
struct V_1 * V_7 ;
int V_24 , V_124 = 0 , V_125 ;
for ( V_24 = 0 ; V_24 < V_116 -> V_117 ; V_24 ++ ) {
switch ( V_116 -> V_118 [ V_24 ] -> V_126 ) {
case V_127 :
case V_128 :
break;
default:
continue;
}
V_7 = F_49 ( V_80 , V_116 -> V_118 [ V_24 ] , V_26 ) ;
if ( ! V_7 ) {
F_8 ( V_2 -> V_8 , L_43 ,
V_116 -> V_118 [ V_24 ] -> V_10 ) ;
continue;
}
if ( ! V_7 -> V_9 -> V_50 )
continue;
if ( ! V_2 -> V_6 [ V_26 ] . V_21 )
continue;
V_125 = F_37 ( V_2 , V_7 , V_26 ) ;
if ( V_125 < 0 ) {
F_8 ( V_2 -> V_8 , L_44 ,
V_116 -> V_118 [ V_24 ] -> V_10 ) ;
break;
} else if ( V_125 == 0 )
continue;
V_7 -> V_6 [ V_26 ] . V_122 = V_123 ;
V_124 ++ ;
}
F_3 ( V_2 -> V_8 , L_45 , V_124 ) ;
return V_124 ;
}
static int F_58 ( struct V_1 * V_2 ,
int V_26 , struct V_115 * * V_116 , int V_124 )
{
if ( V_124 )
return F_57 ( V_2 , V_26 , V_116 ) ;
else
return F_56 ( V_2 , V_26 , V_116 ) ;
}
static void F_59 ( struct V_1 * V_2 , int V_26 )
{
struct V_5 * V_6 ;
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_6 -> V_7 -> V_6 [ V_26 ] . V_122 =
V_129 ;
}
static void F_60 ( struct V_1 * V_2 ,
int V_26 )
{
struct V_5 * V_6 ;
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_7 = V_6 -> V_7 ;
struct V_11 * V_105 =
F_43 ( V_7 , V_26 ) ;
if ( V_7 -> V_6 [ V_26 ] . V_106 == 0 )
F_8 ( V_7 -> V_8 , L_46 ,
V_26 ? L_32 : L_33 ,
V_7 -> V_6 [ V_26 ] . V_96 ) ;
if ( -- V_7 -> V_6 [ V_26 ] . V_106 != 0 )
continue;
if ( V_7 -> V_6 [ V_26 ] . V_96 != V_130 )
continue;
F_25 ( V_105 ) ;
V_105 -> V_21 = NULL ;
V_7 -> V_6 [ V_26 ] . V_96 = V_131 ;
}
}
static int F_61 ( struct V_1 * V_2 , int V_26 )
{
struct V_5 * V_6 ;
int V_125 , V_132 = 0 ;
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_7 = V_6 -> V_7 ;
struct V_11 * V_105 =
F_43 ( V_7 , V_26 ) ;
if ( ! F_62 ( V_2 , V_7 , V_26 ) )
continue;
if ( V_7 -> V_6 [ V_26 ] . V_106 == V_133 )
F_8 ( V_7 -> V_8 , L_47 ,
V_26 ? L_32 : L_33 ,
V_7 -> V_6 [ V_26 ] . V_96 ) ;
if ( V_7 -> V_6 [ V_26 ] . V_106 ++ != 0 )
continue;
if ( ( V_7 -> V_6 [ V_26 ] . V_96 != V_134 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 != V_131 ) )
continue;
F_3 ( V_7 -> V_8 , L_48 , V_7 -> V_9 -> V_10 ) ;
V_105 -> V_21 = V_7 -> V_6 [ V_26 ] . V_21 ;
V_125 = F_12 ( V_105 ) ;
if ( V_125 < 0 ) {
F_8 ( V_7 -> V_8 , L_49 , V_125 ) ;
V_7 -> V_6 [ V_26 ] . V_106 -- ;
if ( V_7 -> V_6 [ V_26 ] . V_106 < 0 )
F_8 ( V_7 -> V_8 , L_50 ,
V_26 ? L_32 : L_33 ,
V_7 -> V_6 [ V_26 ] . V_96 ) ;
V_7 -> V_6 [ V_26 ] . V_96 = V_131 ;
goto V_135;
}
V_7 -> V_6 [ V_26 ] . V_96 = V_130 ;
V_132 ++ ;
}
return V_132 ;
V_135:
F_63 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_7 = V_6 -> V_7 ;
struct V_11 * V_105 =
F_43 ( V_7 , V_26 ) ;
if ( ! F_62 ( V_2 , V_7 , V_26 ) )
continue;
if ( V_7 -> V_6 [ V_26 ] . V_106 == 0 )
F_8 ( V_7 -> V_8 , L_51 ,
V_26 ? L_32 : L_33 ,
V_7 -> V_6 [ V_26 ] . V_96 ) ;
if ( -- V_7 -> V_6 [ V_26 ] . V_106 != 0 )
continue;
if ( V_7 -> V_6 [ V_26 ] . V_96 != V_130 )
continue;
F_25 ( V_105 ) ;
V_105 -> V_21 = NULL ;
V_7 -> V_6 [ V_26 ] . V_96 = V_131 ;
}
return V_125 ;
}
static void F_64 ( struct V_11 * V_12 )
{
struct V_32 * V_21 = V_12 -> V_21 ;
struct V_1 * V_15 = V_12 -> V_16 ;
struct V_13 * V_35 = V_15 -> V_35 ;
struct V_37 * V_38 = V_35 -> V_18 ;
if ( V_12 -> V_26 == V_27 ) {
V_21 -> V_51 . V_52 = V_38 -> V_28 . V_52 ;
V_21 -> V_51 . V_53 = V_38 -> V_28 . V_53 ;
V_21 -> V_51 . V_54 = V_38 -> V_28 . V_54 ;
V_21 -> V_51 . V_55 = V_38 -> V_28 . V_55 ;
V_21 -> V_51 . V_56 &= V_38 -> V_28 . V_56 ;
V_21 -> V_51 . V_57 = V_38 -> V_28 . V_57 ;
} else {
V_21 -> V_51 . V_52 = V_38 -> V_30 . V_52 ;
V_21 -> V_51 . V_53 = V_38 -> V_30 . V_53 ;
V_21 -> V_51 . V_54 = V_38 -> V_30 . V_54 ;
V_21 -> V_51 . V_55 = V_38 -> V_30 . V_55 ;
V_21 -> V_51 . V_56 &= V_38 -> V_30 . V_56 ;
V_21 -> V_51 . V_57 = V_38 -> V_30 . V_57 ;
}
}
static int F_65 ( struct V_11 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_16 ;
struct V_32 * V_21 = V_104 -> V_21 ;
int V_26 = V_104 -> V_26 , V_17 = 0 ;
V_2 -> V_6 [ V_26 ] . V_122 = V_136 ;
V_17 = F_61 ( V_2 , V_104 -> V_26 ) ;
if ( V_17 < 0 ) {
F_8 ( V_2 -> V_8 , L_52 , V_17 ) ;
goto V_137;
}
F_3 ( V_2 -> V_8 , L_53 , V_2 -> V_9 -> V_10 ) ;
V_17 = F_12 ( V_104 ) ;
if ( V_17 < 0 ) {
F_8 ( V_2 -> V_8 , L_54 , V_17 ) ;
goto V_135;
}
V_2 -> V_6 [ V_26 ] . V_96 = V_130 ;
F_64 ( V_104 ) ;
F_18 ( V_21 ) ;
V_2 -> V_6 [ V_26 ] . V_122 = V_129 ;
return 0 ;
V_135:
F_60 ( V_2 , V_104 -> V_26 ) ;
V_137:
V_2 -> V_6 [ V_26 ] . V_122 = V_129 ;
return V_17 ;
}
static int F_66 ( struct V_1 * V_2 , int V_26 )
{
struct V_5 * V_6 ;
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_7 = V_6 -> V_7 ;
struct V_11 * V_105 =
F_43 ( V_7 , V_26 ) ;
if ( ! F_62 ( V_2 , V_7 , V_26 ) )
continue;
if ( V_7 -> V_6 [ V_26 ] . V_106 == 0 )
F_8 ( V_7 -> V_8 , L_46 ,
V_26 ? L_32 : L_33 ,
V_7 -> V_6 [ V_26 ] . V_96 ) ;
if ( -- V_7 -> V_6 [ V_26 ] . V_106 != 0 )
continue;
if ( ( V_7 -> V_6 [ V_26 ] . V_96 != V_138 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 != V_130 ) )
continue;
F_3 ( V_7 -> V_8 , L_55 ,
V_6 -> V_2 -> V_9 -> V_10 ) ;
F_25 ( V_105 ) ;
V_105 -> V_21 = NULL ;
V_7 -> V_6 [ V_26 ] . V_96 = V_131 ;
}
return 0 ;
}
static int F_67 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_16 ;
int V_26 = V_12 -> V_26 ;
V_2 -> V_6 [ V_26 ] . V_122 = V_136 ;
F_66 ( V_2 , V_12 -> V_26 ) ;
F_3 ( V_2 -> V_8 , L_56 , V_2 -> V_9 -> V_10 ) ;
F_25 ( V_12 ) ;
F_1 ( V_2 , V_26 , V_74 ) ;
V_2 -> V_6 [ V_26 ] . V_96 = V_131 ;
V_2 -> V_6 [ V_26 ] . V_122 = V_129 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , int V_26 )
{
struct V_5 * V_6 ;
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_7 = V_6 -> V_7 ;
struct V_11 * V_105 =
F_43 ( V_7 , V_26 ) ;
if ( ! F_62 ( V_2 , V_7 , V_26 ) )
continue;
if ( ! F_69 ( V_2 , V_7 , V_26 ) )
continue;
if ( ( V_7 -> V_6 [ V_26 ] . V_96 != V_139 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 != V_140 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 != V_138 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 != V_141 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 != V_142 ) )
continue;
F_3 ( V_7 -> V_8 , L_57 ,
V_6 -> V_2 -> V_9 -> V_10 ) ;
F_33 ( V_105 ) ;
V_7 -> V_6 [ V_26 ] . V_96 = V_138 ;
}
return 0 ;
}
static int F_70 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_16 ;
int V_125 , V_26 = V_12 -> V_26 ;
F_14 ( & V_2 -> V_80 -> V_143 , V_144 ) ;
V_2 -> V_6 [ V_26 ] . V_122 = V_136 ;
F_3 ( V_2 -> V_8 , L_58 , V_2 -> V_9 -> V_10 ) ;
V_125 = F_33 ( V_12 ) ;
if ( V_125 < 0 )
F_8 ( V_2 -> V_8 , L_59 ,
V_2 -> V_9 -> V_10 ) ;
V_125 = F_68 ( V_2 , V_26 ) ;
V_2 -> V_6 [ V_26 ] . V_96 = V_138 ;
V_2 -> V_6 [ V_26 ] . V_122 = V_129 ;
F_21 ( & V_2 -> V_80 -> V_143 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , int V_26 )
{
struct V_5 * V_6 ;
int V_17 ;
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_7 = V_6 -> V_7 ;
struct V_11 * V_105 =
F_43 ( V_7 , V_26 ) ;
if ( ! F_62 ( V_2 , V_7 , V_26 ) )
continue;
if ( ! F_72 ( V_2 , V_7 , V_26 ) )
continue;
if ( ( V_7 -> V_6 [ V_26 ] . V_96 != V_130 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 != V_139 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 != V_138 ) )
continue;
F_3 ( V_7 -> V_8 , L_60 ,
V_6 -> V_2 -> V_9 -> V_10 ) ;
memcpy ( & V_6 -> V_84 , & V_2 -> V_6 [ V_26 ] . V_84 ,
sizeof( struct V_82 ) ) ;
if ( V_7 -> V_9 -> V_145 ) {
V_17 = V_7 -> V_9 -> V_145 ( V_7 ,
& V_6 -> V_84 ) ;
if ( V_17 < 0 ) {
F_8 ( V_7 -> V_8 ,
L_61 ,
V_17 ) ;
goto V_135;
}
}
V_17 = F_31 ( V_105 , & V_6 -> V_84 ) ;
if ( V_17 < 0 ) {
F_8 ( V_6 -> V_7 -> V_8 ,
L_62 , V_17 ) ;
goto V_135;
}
V_7 -> V_6 [ V_26 ] . V_96 = V_139 ;
}
return 0 ;
V_135:
F_63 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_7 = V_6 -> V_7 ;
struct V_11 * V_105 =
F_43 ( V_7 , V_26 ) ;
if ( ! F_62 ( V_2 , V_7 , V_26 ) )
continue;
if ( ! F_69 ( V_2 , V_7 , V_26 ) )
continue;
if ( ( V_7 -> V_6 [ V_26 ] . V_96 != V_130 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 != V_139 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 != V_138 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 != V_142 ) )
continue;
F_33 ( V_105 ) ;
}
return V_17 ;
}
static int F_73 ( struct V_11 * V_12 ,
struct V_82 * V_83 )
{
struct V_1 * V_2 = V_12 -> V_16 ;
int V_17 , V_26 = V_12 -> V_26 ;
F_14 ( & V_2 -> V_80 -> V_143 , V_144 ) ;
V_2 -> V_6 [ V_26 ] . V_122 = V_136 ;
memcpy ( & V_2 -> V_6 [ V_12 -> V_26 ] . V_84 , V_83 ,
sizeof( struct V_82 ) ) ;
V_17 = F_71 ( V_2 , V_12 -> V_26 ) ;
if ( V_17 < 0 ) {
F_8 ( V_2 -> V_8 , L_62 , V_17 ) ;
goto V_44;
}
F_3 ( V_2 -> V_8 , L_63 ,
V_2 -> V_9 -> V_10 , F_32 ( V_83 ) ,
F_74 ( V_83 ) , F_75 ( V_83 ) ) ;
V_17 = F_31 ( V_12 , V_83 ) ;
if ( V_17 < 0 ) {
F_8 ( V_2 -> V_8 , L_64 , V_17 ) ;
F_68 ( V_2 , V_26 ) ;
} else
V_2 -> V_6 [ V_26 ] . V_96 = V_139 ;
V_44:
V_2 -> V_6 [ V_26 ] . V_122 = V_129 ;
F_21 ( & V_2 -> V_80 -> V_143 ) ;
return V_17 ;
}
static int F_76 ( struct V_5 * V_6 ,
struct V_11 * V_12 , int V_88 )
{
int V_17 ;
F_3 ( V_6 -> V_7 -> V_8 , L_65 ,
V_6 -> V_2 -> V_9 -> V_10 , V_88 ) ;
V_17 = F_34 ( V_12 , V_88 ) ;
if ( V_17 < 0 )
F_8 ( V_6 -> V_7 -> V_8 , L_66 , V_17 ) ;
return V_17 ;
}
static int F_77 ( struct V_1 * V_2 , int V_26 ,
int V_88 )
{
struct V_5 * V_6 ;
int V_17 = 0 ;
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_7 = V_6 -> V_7 ;
struct V_11 * V_105 =
F_43 ( V_7 , V_26 ) ;
if ( ! F_62 ( V_2 , V_7 , V_26 ) )
continue;
switch ( V_88 ) {
case V_146 :
if ( ( V_7 -> V_6 [ V_26 ] . V_96 != V_140 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 != V_142 ) )
continue;
V_17 = F_76 ( V_6 , V_105 , V_88 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_6 [ V_26 ] . V_96 = V_147 ;
break;
case V_148 :
if ( ( V_7 -> V_6 [ V_26 ] . V_96 != V_149 ) )
continue;
V_17 = F_76 ( V_6 , V_105 , V_88 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_6 [ V_26 ] . V_96 = V_147 ;
break;
case V_150 :
if ( ( V_7 -> V_6 [ V_26 ] . V_96 != V_141 ) )
continue;
V_17 = F_76 ( V_6 , V_105 , V_88 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_6 [ V_26 ] . V_96 = V_147 ;
break;
case V_151 :
if ( V_7 -> V_6 [ V_26 ] . V_96 != V_147 )
continue;
if ( ! F_69 ( V_2 , V_7 , V_26 ) )
continue;
V_17 = F_76 ( V_6 , V_105 , V_88 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_6 [ V_26 ] . V_96 = V_142 ;
break;
case V_152 :
if ( V_7 -> V_6 [ V_26 ] . V_96 != V_142 )
continue;
if ( ! F_69 ( V_2 , V_7 , V_26 ) )
continue;
V_17 = F_76 ( V_6 , V_105 , V_88 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_6 [ V_26 ] . V_96 = V_149 ;
break;
case V_153 :
if ( V_7 -> V_6 [ V_26 ] . V_96 != V_147 )
continue;
if ( ! F_69 ( V_2 , V_7 , V_26 ) )
continue;
V_17 = F_76 ( V_6 , V_105 , V_88 ) ;
if ( V_17 )
return V_17 ;
V_7 -> V_6 [ V_26 ] . V_96 = V_141 ;
break;
}
}
return V_17 ;
}
static int F_78 ( struct V_11 * V_12 , int V_88 )
{
struct V_1 * V_2 = V_12 -> V_16 ;
int V_26 = V_12 -> V_26 , V_17 ;
enum V_154 V_89 = V_2 -> V_9 -> V_89 [ V_26 ] ;
V_2 -> V_6 [ V_26 ] . V_122 = V_136 ;
switch ( V_89 ) {
case V_155 :
F_3 ( V_2 -> V_8 , L_67 ,
V_2 -> V_9 -> V_10 , V_88 ) ;
V_17 = F_34 ( V_12 , V_88 ) ;
if ( V_17 < 0 ) {
F_8 ( V_2 -> V_8 , L_68 , V_17 ) ;
goto V_44;
}
V_17 = F_77 ( V_2 , V_12 -> V_26 , V_88 ) ;
break;
case V_156 :
V_17 = F_77 ( V_2 , V_12 -> V_26 , V_88 ) ;
if ( V_17 < 0 ) {
F_8 ( V_2 -> V_8 , L_68 , V_17 ) ;
goto V_44;
}
F_3 ( V_2 -> V_8 , L_69 ,
V_2 -> V_9 -> V_10 , V_88 ) ;
V_17 = F_34 ( V_12 , V_88 ) ;
break;
case V_157 :
F_3 ( V_2 -> V_8 , L_70 ,
V_2 -> V_9 -> V_10 , V_88 ) ;
V_17 = F_35 ( V_12 , V_88 ) ;
if ( V_17 < 0 ) {
F_8 ( V_2 -> V_8 , L_68 , V_17 ) ;
goto V_44;
}
break;
default:
F_8 ( V_2 -> V_8 , L_71 , V_88 ,
V_2 -> V_9 -> V_10 ) ;
V_17 = - V_60 ;
goto V_44;
}
switch ( V_88 ) {
case V_146 :
case V_148 :
case V_150 :
V_2 -> V_6 [ V_26 ] . V_96 = V_147 ;
break;
case V_151 :
case V_152 :
case V_153 :
V_2 -> V_6 [ V_26 ] . V_96 = V_142 ;
break;
}
V_44:
V_2 -> V_6 [ V_26 ] . V_122 = V_129 ;
return V_17 ;
}
static int F_79 ( struct V_1 * V_2 , int V_26 )
{
struct V_5 * V_6 ;
int V_17 = 0 ;
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_7 = V_6 -> V_7 ;
struct V_11 * V_105 =
F_43 ( V_7 , V_26 ) ;
if ( ! F_62 ( V_2 , V_7 , V_26 ) )
continue;
if ( ( V_7 -> V_6 [ V_26 ] . V_96 != V_139 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 != V_142 ) )
continue;
F_3 ( V_7 -> V_8 , L_72 ,
V_6 -> V_2 -> V_9 -> V_10 ) ;
V_17 = F_29 ( V_105 ) ;
if ( V_17 < 0 ) {
F_8 ( V_7 -> V_8 , L_73 ,
V_17 ) ;
break;
}
V_7 -> V_6 [ V_26 ] . V_96 = V_140 ;
}
return V_17 ;
}
static int F_80 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_16 ;
int V_26 = V_12 -> V_26 , V_17 = 0 ;
F_14 ( & V_2 -> V_80 -> V_143 , V_144 ) ;
F_3 ( V_2 -> V_8 , L_74 , V_2 -> V_9 -> V_10 ) ;
V_2 -> V_6 [ V_26 ] . V_122 = V_136 ;
if ( F_81 ( & V_2 -> V_6 [ V_26 ] . V_99 ) ) {
F_8 ( V_2 -> V_8 , L_75 ,
V_2 -> V_9 -> V_10 ) ;
V_17 = - V_60 ;
goto V_44;
}
V_17 = F_79 ( V_2 , V_12 -> V_26 ) ;
if ( V_17 < 0 )
goto V_44;
V_17 = F_29 ( V_12 ) ;
if ( V_17 < 0 ) {
F_8 ( V_2 -> V_8 , L_76 ,
V_2 -> V_9 -> V_10 ) ;
goto V_44;
}
F_1 ( V_2 , V_26 , V_81 ) ;
V_2 -> V_6 [ V_26 ] . V_96 = V_140 ;
V_44:
V_2 -> V_6 [ V_26 ] . V_122 = V_129 ;
F_21 ( & V_2 -> V_80 -> V_143 ) ;
return V_17 ;
}
static int F_82 ( struct V_11 * V_12 ,
unsigned int V_88 , void * V_158 )
{
struct V_1 * V_15 = V_12 -> V_16 ;
struct V_33 * V_34 = V_15 -> V_34 ;
if ( V_34 -> V_18 -> V_42 -> V_159 )
return V_34 -> V_18 -> V_42 -> V_159 ( V_12 , V_88 , V_158 ) ;
return F_83 ( V_12 , V_88 , V_158 ) ;
}
static int F_84 ( struct V_1 * V_2 , int V_26 )
{
struct V_11 * V_12 =
F_43 ( V_2 , V_26 ) ;
enum V_154 V_89 = V_2 -> V_9 -> V_89 [ V_26 ] ;
int V_125 ;
F_3 ( V_2 -> V_8 , L_77 ,
V_26 ? L_32 : L_33 , V_2 -> V_9 -> V_10 ) ;
if ( V_89 == V_157 ) {
F_3 ( V_2 -> V_8 , L_78 ,
V_2 -> V_9 -> V_10 ) ;
V_125 = F_35 ( V_12 , V_151 ) ;
if ( V_125 < 0 )
F_8 ( V_2 -> V_8 , L_68 , V_125 ) ;
} else {
F_3 ( V_2 -> V_8 , L_79 ,
V_2 -> V_9 -> V_10 ) ;
V_125 = F_77 ( V_2 , V_26 , V_151 ) ;
if ( V_125 < 0 )
F_8 ( V_2 -> V_8 , L_68 , V_125 ) ;
}
V_125 = F_68 ( V_2 , V_26 ) ;
if ( V_125 < 0 )
F_8 ( V_2 -> V_8 , L_80 , V_125 ) ;
V_125 = F_66 ( V_2 , V_26 ) ;
if ( V_125 < 0 )
F_8 ( V_2 -> V_8 , L_81 , V_125 ) ;
F_1 ( V_2 , V_26 , V_160 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 , int V_26 )
{
struct V_11 * V_12 =
F_43 ( V_2 , V_26 ) ;
struct V_5 * V_6 ;
enum V_154 V_89 = V_2 -> V_9 -> V_89 [ V_26 ] ;
int V_17 ;
F_3 ( V_2 -> V_8 , L_82 ,
V_26 ? L_32 : L_33 , V_2 -> V_9 -> V_10 ) ;
if ( V_2 -> V_6 [ V_26 ] . V_96 == V_138 ||
V_2 -> V_6 [ V_26 ] . V_96 == V_131 )
return - V_60 ;
V_17 = F_61 ( V_2 , V_26 ) ;
if ( V_17 < 0 )
goto V_161;
if ( V_2 -> V_6 [ V_26 ] . V_96 == V_130 )
return 0 ;
V_17 = F_71 ( V_2 , V_26 ) ;
if ( V_17 < 0 )
goto V_68;
if ( V_2 -> V_6 [ V_26 ] . V_96 == V_139 )
return 0 ;
V_17 = F_79 ( V_2 , V_26 ) ;
if ( V_17 < 0 )
goto V_87;
F_1 ( V_2 , V_26 , V_160 ) ;
if ( V_2 -> V_6 [ V_26 ] . V_96 == V_140 ||
V_2 -> V_6 [ V_26 ] . V_96 == V_142 )
return 0 ;
if ( V_89 == V_157 ) {
F_3 ( V_2 -> V_8 , L_83 ,
V_2 -> V_9 -> V_10 ) ;
V_17 = F_35 ( V_12 , V_146 ) ;
if ( V_17 < 0 ) {
F_8 ( V_2 -> V_8 , L_84 , V_17 ) ;
goto V_87;
}
} else {
F_3 ( V_2 -> V_8 , L_85 ,
V_2 -> V_9 -> V_10 ) ;
V_17 = F_77 ( V_2 , V_26 ,
V_146 ) ;
if ( V_17 < 0 ) {
F_8 ( V_2 -> V_8 , L_68 , V_17 ) ;
goto V_87;
}
}
return 0 ;
V_87:
F_68 ( V_2 , V_26 ) ;
V_68:
F_66 ( V_2 , V_26 ) ;
V_161:
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_7 = V_6 -> V_7 ;
if ( V_7 -> V_6 [ V_26 ] . V_96 != V_147 )
V_6 -> V_96 = V_108 ;
}
return V_17 ;
}
static int F_86 ( struct V_1 * V_2 , int V_26 )
{
int V_17 ;
V_2 -> V_6 [ V_26 ] . V_122 = V_123 ;
V_17 = F_85 ( V_2 , V_26 ) ;
if ( V_17 < 0 )
F_8 ( V_2 -> V_8 , L_86 ) ;
V_2 -> V_6 [ V_26 ] . V_122 = V_129 ;
return V_17 ;
}
static int F_87 ( struct V_1 * V_2 , int V_26 )
{
int V_17 ;
V_2 -> V_6 [ V_26 ] . V_122 = V_123 ;
V_17 = F_84 ( V_2 , V_26 ) ;
if ( V_17 < 0 )
F_8 ( V_2 -> V_8 , L_87 ) ;
V_2 -> V_6 [ V_26 ] . V_122 = V_129 ;
return V_17 ;
}
int F_88 ( struct V_110 * V_111 )
{
struct V_109 * V_80 ;
int V_24 , V_162 , V_124 , V_120 ;
if ( V_111 -> V_66 )
V_80 = V_111 -> V_66 -> V_80 ;
else if ( V_111 -> V_34 )
V_80 = V_111 -> V_34 -> V_80 ;
else
return - V_60 ;
F_14 ( & V_80 -> V_143 , V_144 ) ;
for ( V_24 = 0 ; V_24 < V_80 -> V_163 ; V_24 ++ ) {
struct V_115 * V_116 ;
struct V_1 * V_2 = & V_80 -> V_15 [ V_24 ] ;
if ( ! V_2 -> V_9 -> V_49 )
continue;
if ( ! V_2 -> V_35 -> V_63 )
continue;
F_3 ( V_2 -> V_8 , L_88 ,
V_2 -> V_9 -> V_10 ) ;
if ( ! V_2 -> V_35 -> V_18 -> V_28 . V_54 )
goto V_30;
V_120 = F_53 ( V_2 , V_27 , & V_116 ) ;
if ( V_120 < 0 ) {
F_6 ( V_2 -> V_8 , L_89 ,
V_2 -> V_9 -> V_10 , L_33 ) ;
F_21 ( & V_80 -> V_143 ) ;
return V_120 ;
}
V_124 = F_58 ( V_2 , V_27 , & V_116 , 1 ) ;
if ( V_124 ) {
F_86 ( V_2 , V_27 ) ;
F_59 ( V_2 , V_27 ) ;
F_44 ( V_2 , V_27 ) ;
}
V_162 = F_58 ( V_2 , V_27 , & V_116 , 0 ) ;
if ( V_162 ) {
F_87 ( V_2 , V_27 ) ;
F_59 ( V_2 , V_27 ) ;
F_44 ( V_2 , V_27 ) ;
}
V_30:
if ( ! V_2 -> V_35 -> V_18 -> V_30 . V_54 )
continue;
V_120 = F_53 ( V_2 , V_78 , & V_116 ) ;
if ( V_120 < 0 ) {
F_6 ( V_2 -> V_8 , L_89 ,
V_2 -> V_9 -> V_10 , L_32 ) ;
F_21 ( & V_80 -> V_143 ) ;
return V_120 ;
}
V_124 = F_58 ( V_2 , V_78 , & V_116 , 1 ) ;
if ( V_124 ) {
F_86 ( V_2 , V_78 ) ;
F_59 ( V_2 , V_78 ) ;
F_44 ( V_2 , V_78 ) ;
}
V_162 = F_58 ( V_2 , V_78 , & V_116 , 0 ) ;
if ( V_162 ) {
F_87 ( V_2 , V_78 ) ;
F_59 ( V_2 , V_78 ) ;
F_44 ( V_2 , V_78 ) ;
}
F_55 ( & V_116 ) ;
}
F_21 ( & V_80 -> V_143 ) ;
return 0 ;
}
int F_89 ( struct V_1 * V_2 , int V_164 )
{
struct V_5 * V_6 ;
struct V_165 * V_166 =
& V_2 -> V_6 [ V_27 ] . V_99 ;
F_2 (dpcm, clients, list_be) {
struct V_1 * V_7 = V_6 -> V_7 ;
struct V_13 * V_23 = V_7 -> V_36 ;
struct V_37 * V_167 = V_23 -> V_18 ;
if ( V_7 -> V_9 -> V_168 )
continue;
F_3 ( V_7 -> V_8 , L_90 , V_7 -> V_9 -> V_10 ) ;
if ( V_167 -> V_42 -> V_169 && V_23 -> V_64 )
V_167 -> V_42 -> V_169 ( V_23 , V_164 ) ;
}
return 0 ;
}
static int F_90 ( struct V_11 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_16 ;
struct V_5 * V_6 ;
struct V_115 * V_116 ;
int V_17 ;
int V_26 = V_104 -> V_26 ;
F_14 ( & V_2 -> V_80 -> V_143 , V_144 ) ;
V_2 -> V_6 [ V_26 ] . V_21 = V_104 -> V_21 ;
if ( F_53 ( V_2 , V_26 , & V_116 ) <= 0 ) {
F_3 ( V_2 -> V_8 , L_91 ,
V_2 -> V_9 -> V_10 , V_26 ? L_32 : L_33 ) ;
}
F_58 ( V_2 , V_26 , & V_116 , 1 ) ;
V_17 = F_65 ( V_104 ) ;
if ( V_17 < 0 ) {
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_6 -> V_96 = V_108 ;
F_44 ( V_2 , V_26 ) ;
V_2 -> V_6 [ V_26 ] . V_21 = NULL ;
}
F_59 ( V_2 , V_26 ) ;
F_55 ( & V_116 ) ;
F_21 ( & V_2 -> V_80 -> V_143 ) ;
return V_17 ;
}
static int F_91 ( struct V_11 * V_104 )
{
struct V_1 * V_2 = V_104 -> V_16 ;
struct V_5 * V_6 ;
int V_26 = V_104 -> V_26 , V_17 ;
F_14 ( & V_2 -> V_80 -> V_143 , V_144 ) ;
V_17 = F_67 ( V_104 ) ;
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_6 -> V_96 = V_108 ;
F_44 ( V_2 , V_26 ) ;
V_2 -> V_6 [ V_26 ] . V_21 = NULL ;
F_21 ( & V_2 -> V_80 -> V_143 ) ;
return V_17 ;
}
int F_92 ( struct V_1 * V_15 , int V_170 )
{
struct V_33 * V_34 = V_15 -> V_34 ;
struct V_13 * V_36 = V_15 -> V_36 ;
struct V_13 * V_35 = V_15 -> V_35 ;
struct V_171 * V_172 ;
char V_173 [ 64 ] ;
int V_17 = 0 , V_28 = 0 , V_30 = 0 ;
if ( V_15 -> V_9 -> V_49 || V_15 -> V_9 -> V_50 ) {
if ( V_35 -> V_18 -> V_28 . V_54 )
V_28 = 1 ;
if ( V_35 -> V_18 -> V_30 . V_54 )
V_30 = 1 ;
} else {
if ( V_36 -> V_18 -> V_28 . V_54 &&
V_35 -> V_18 -> V_28 . V_54 )
V_28 = 1 ;
if ( V_36 -> V_18 -> V_30 . V_54 &&
V_35 -> V_18 -> V_30 . V_54 )
V_30 = 1 ;
}
if ( V_15 -> V_9 -> V_50 ) {
snprintf ( V_173 , sizeof( V_173 ) , L_92 ,
V_15 -> V_9 -> V_72 ) ;
V_17 = F_93 ( V_15 -> V_80 -> V_174 , V_173 , V_170 ,
V_28 , V_30 , & V_172 ) ;
} else {
if ( V_15 -> V_9 -> V_49 )
snprintf ( V_173 , sizeof( V_173 ) , L_93 ,
V_15 -> V_9 -> V_72 ) ;
else
snprintf ( V_173 , sizeof( V_173 ) , L_94 ,
V_15 -> V_9 -> V_72 , V_36 -> V_10 , V_170 ) ;
V_17 = F_94 ( V_15 -> V_80 -> V_174 , V_173 , V_170 , V_28 ,
V_30 , & V_172 ) ;
}
if ( V_17 < 0 ) {
F_8 ( V_15 -> V_80 -> V_8 , L_95 ,
V_15 -> V_9 -> V_10 ) ;
return V_17 ;
}
F_3 ( V_15 -> V_80 -> V_8 , L_96 , V_170 , V_173 ) ;
F_95 ( & V_15 -> V_71 , F_23 ) ;
V_15 -> V_172 = V_172 ;
V_172 -> V_16 = V_15 ;
if ( V_15 -> V_9 -> V_50 ) {
if ( V_28 )
V_172 -> V_175 [ V_27 ] . V_12 -> V_16 = V_15 ;
if ( V_30 )
V_172 -> V_175 [ V_78 ] . V_12 -> V_16 = V_15 ;
goto V_44;
}
if ( V_15 -> V_9 -> V_49 ) {
V_15 -> V_42 . V_45 = F_90 ;
V_15 -> V_42 . V_84 = F_73 ;
V_15 -> V_42 . V_79 = F_80 ;
V_15 -> V_42 . V_89 = F_78 ;
V_15 -> V_42 . V_87 = F_70 ;
V_15 -> V_42 . V_68 = F_91 ;
V_15 -> V_42 . V_93 = F_36 ;
V_15 -> V_42 . V_159 = F_82 ;
} else {
V_15 -> V_42 . V_45 = F_12 ;
V_15 -> V_42 . V_84 = F_31 ;
V_15 -> V_42 . V_79 = F_29 ;
V_15 -> V_42 . V_89 = F_34 ;
V_15 -> V_42 . V_87 = F_33 ;
V_15 -> V_42 . V_68 = F_25 ;
V_15 -> V_42 . V_93 = F_36 ;
V_15 -> V_42 . V_159 = F_82 ;
}
if ( V_34 -> V_18 -> V_42 ) {
V_15 -> V_42 . V_176 = V_34 -> V_18 -> V_42 -> V_176 ;
V_15 -> V_42 . V_177 = V_34 -> V_18 -> V_42 -> V_177 ;
V_15 -> V_42 . V_178 = V_34 -> V_18 -> V_42 -> V_178 ;
V_15 -> V_42 . V_179 = V_34 -> V_18 -> V_42 -> V_179 ;
V_15 -> V_42 . V_180 = V_34 -> V_18 -> V_42 -> V_180 ;
}
if ( V_28 )
F_96 ( V_172 , V_27 , & V_15 -> V_42 ) ;
if ( V_30 )
F_96 ( V_172 , V_78 , & V_15 -> V_42 ) ;
if ( V_34 -> V_18 -> V_181 ) {
V_17 = V_34 -> V_18 -> V_181 ( V_15 ) ;
if ( V_17 < 0 ) {
F_8 ( V_34 -> V_8 ,
L_97 ,
V_17 ) ;
return V_17 ;
}
}
V_172 -> V_182 = V_34 -> V_18 -> V_183 ;
V_44:
F_97 ( V_15 -> V_80 -> V_8 , L_98 , V_36 -> V_10 ,
V_35 -> V_10 ) ;
return V_17 ;
}
int F_98 ( struct V_1 * V_2 , int V_26 )
{
if ( V_2 -> V_6 [ V_26 ] . V_122 == V_136 )
return 1 ;
return 0 ;
}
int F_62 ( struct V_1 * V_2 ,
struct V_1 * V_7 , int V_26 )
{
if ( ( V_2 -> V_6 [ V_26 ] . V_122 == V_136 ) ||
( ( V_2 -> V_6 [ V_26 ] . V_122 == V_123 ) &&
V_7 -> V_6 [ V_26 ] . V_122 ) )
return 1 ;
return 0 ;
}
struct V_11 *
F_43 ( struct V_1 * V_7 , int V_26 )
{
return V_7 -> V_172 -> V_175 [ V_26 ] . V_12 ;
}
enum V_184
F_99 ( struct V_1 * V_7 , int V_26 )
{
return V_7 -> V_6 [ V_26 ] . V_96 ;
}
void F_100 ( struct V_1 * V_7 ,
int V_26 , enum V_184 V_96 )
{
V_7 -> V_6 [ V_26 ] . V_96 = V_96 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_1 * V_7 , int V_26 )
{
struct V_5 * V_6 ;
int V_96 ;
F_2 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_6 -> V_2 == V_2 )
continue;
V_96 = V_6 -> V_2 -> V_6 [ V_26 ] . V_96 ;
if ( V_96 == V_147 ||
V_96 == V_141 ||
V_96 == V_149 )
return 0 ;
}
return 1 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_1 * V_7 , int V_26 )
{
struct V_5 * V_6 ;
int V_96 ;
F_2 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_6 -> V_2 == V_2 )
continue;
V_96 = V_6 -> V_2 -> V_6 [ V_26 ] . V_96 ;
if ( V_96 == V_147 ||
V_96 == V_141 ||
V_96 == V_149 ||
V_96 == V_140 )
return 0 ;
}
return 1 ;
}
int F_101 ( struct V_11 * V_12 ,
int V_88 , struct V_33 * V_34 )
{
if ( V_34 -> V_18 -> V_42 -> V_89 )
return V_34 -> V_18 -> V_42 -> V_89 ( V_12 , V_88 ) ;
return 0 ;
}
static char * F_102 ( enum V_184 V_96 )
{
switch ( V_96 ) {
case V_134 :
return L_99 ;
case V_130 :
return L_100 ;
case V_139 :
return L_101 ;
case V_140 :
return L_102 ;
case V_147 :
return L_103 ;
case V_142 :
return L_104 ;
case V_149 :
return L_105 ;
case V_141 :
return L_106 ;
case V_138 :
return L_107 ;
case V_131 :
return L_108 ;
}
return L_109 ;
}
static T_3 F_103 ( struct V_1 * V_2 ,
int V_26 , char * V_185 , T_4 V_186 )
{
struct V_82 * V_83 = & V_2 -> V_6 [ V_26 ] . V_84 ;
struct V_5 * V_6 ;
T_3 V_91 = 0 ;
V_91 += snprintf ( V_185 + V_91 , V_186 - V_91 ,
L_110 , V_2 -> V_9 -> V_10 ,
V_26 ? L_111 : L_112 ) ;
V_91 += snprintf ( V_185 + V_91 , V_186 - V_91 , L_113 ,
F_102 ( V_2 -> V_6 [ V_26 ] . V_96 ) ) ;
if ( ( V_2 -> V_6 [ V_26 ] . V_96 >= V_139 ) &&
( V_2 -> V_6 [ V_26 ] . V_96 <= V_142 ) )
V_91 += snprintf ( V_185 + V_91 , V_186 - V_91 ,
L_114
L_115 ,
F_104 ( F_75 ( V_83 ) ) ,
F_74 ( V_83 ) ,
F_32 ( V_83 ) ) ;
V_91 += snprintf ( V_185 + V_91 , V_186 - V_91 , L_116 ) ;
if ( F_81 ( & V_2 -> V_6 [ V_26 ] . V_99 ) ) {
V_91 += snprintf ( V_185 + V_91 , V_186 - V_91 ,
L_117 ) ;
goto V_44;
}
F_2 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_1 * V_7 = V_6 -> V_7 ;
V_83 = & V_6 -> V_84 ;
V_91 += snprintf ( V_185 + V_91 , V_186 - V_91 ,
L_118 , V_7 -> V_9 -> V_10 ) ;
V_91 += snprintf ( V_185 + V_91 , V_186 - V_91 ,
L_119 ,
F_102 ( V_7 -> V_6 [ V_26 ] . V_96 ) ) ;
if ( ( V_7 -> V_6 [ V_26 ] . V_96 >= V_139 ) &&
( V_7 -> V_6 [ V_26 ] . V_96 <= V_142 ) )
V_91 += snprintf ( V_185 + V_91 , V_186 - V_91 ,
L_120
L_115 ,
F_104 ( F_75 ( V_83 ) ) ,
F_74 ( V_83 ) ,
F_32 ( V_83 ) ) ;
}
V_44:
return V_91 ;
}
static T_3 F_105 ( struct V_187 * V_187 , char T_5 * V_188 ,
T_4 V_132 , T_6 * V_189 )
{
struct V_1 * V_2 = V_187 -> V_16 ;
T_3 V_190 = V_191 , V_91 = 0 , V_17 = 0 ;
char * V_185 ;
V_185 = F_106 ( V_190 , V_94 ) ;
if ( ! V_185 )
return - V_95 ;
if ( V_2 -> V_35 -> V_18 -> V_28 . V_54 )
V_91 += F_103 ( V_2 , V_27 ,
V_185 + V_91 , V_190 - V_91 ) ;
if ( V_2 -> V_35 -> V_18 -> V_30 . V_54 )
V_91 += F_103 ( V_2 , V_78 ,
V_185 + V_91 , V_190 - V_91 ) ;
V_17 = F_107 ( V_188 , V_132 , V_189 , V_185 , V_91 ) ;
F_48 ( V_185 ) ;
return V_17 ;
}
int F_108 ( struct V_1 * V_15 )
{
if ( ! V_15 -> V_9 )
return 0 ;
V_15 -> V_103 = F_109 ( V_15 -> V_9 -> V_10 ,
V_15 -> V_80 -> V_192 ) ;
if ( ! V_15 -> V_103 ) {
F_3 ( V_15 -> V_8 ,
L_121 ,
V_15 -> V_9 -> V_10 ) ;
return - V_60 ;
}
V_15 -> V_193 = F_110 ( L_122 , 0444 ,
V_15 -> V_103 ,
V_15 , & V_194 ) ;
return 0 ;
}
