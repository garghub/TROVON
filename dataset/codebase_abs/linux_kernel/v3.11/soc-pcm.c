int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
V_6 -> V_4 . V_7 = V_4 -> V_7 ;
V_6 -> V_4 . V_8 = V_4 -> V_8 ;
V_6 -> V_4 . V_9 = V_4 -> V_9 ;
V_6 -> V_4 . V_10 = V_4 -> V_10 ;
V_6 -> V_4 . V_11 = V_4 -> V_11 ;
V_6 -> V_4 . V_12 = V_4 -> V_12 ;
V_6 -> V_4 . V_13 = V_4 -> V_13 ;
V_6 -> V_4 . V_14 = V_4 -> V_14 ;
return 0 ;
}
static int F_2 ( struct V_15 * V_16 , int V_17 ,
int V_18 )
{
struct V_19 * V_20 ;
F_3 (dpcm, &fe->dpcm[dir].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
F_4 ( V_21 -> V_22 , L_1 ,
V_21 -> V_23 -> V_24 , V_18 , V_17 ) ;
F_5 ( V_21 , V_17 , V_18 ) ;
}
F_5 ( V_16 , V_17 , V_18 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
int V_29 ;
if ( ! V_26 -> V_30 -> V_31 &&
! V_27 -> V_23 -> V_31 )
return 0 ;
if ( ! V_26 -> V_32 ) {
F_7 ( V_26 -> V_22 ,
L_2 ) ;
return 0 ;
}
F_4 ( V_26 -> V_22 , L_3 , V_26 -> V_32 ) ;
V_29 = F_8 ( V_2 -> V_6 ,
V_33 ,
V_26 -> V_32 , V_26 -> V_32 ) ;
if ( V_29 < 0 ) {
F_9 ( V_26 -> V_22 ,
L_4 ,
V_29 ) ;
return V_29 ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_25 * V_34 )
{
int V_29 , V_35 , V_36 ;
if ( V_2 -> V_37 == V_38 )
V_36 = V_34 -> V_30 -> V_39 . V_40 ;
else
V_36 = V_34 -> V_30 -> V_41 . V_40 ;
if ( ! V_36 )
return;
for ( V_35 = 0 ; V_35 < F_11 ( V_42 ) ; V_35 ++ ) {
if ( V_36 >= V_42 [ V_35 ] )
continue;
V_29 = F_12 ( V_2 -> V_6 , 0 ,
V_42 [ V_35 ] , V_36 ) ;
if ( V_29 != 0 )
F_7 ( V_34 -> V_22 ,
L_5 ,
V_36 , V_42 [ V_35 ] , V_29 ) ;
}
}
static void F_13 ( struct V_3 * V_4 ,
struct V_43 * V_44 ,
struct V_43 * V_45 )
{
V_4 -> V_46 = F_14 ( V_44 -> V_46 , V_45 -> V_46 ) ;
V_4 -> V_47 = F_14 ( V_44 -> V_47 , V_45 -> V_47 ) ;
V_4 -> V_48 = F_14 ( V_44 -> V_48 ,
V_45 -> V_48 ) ;
V_4 -> V_49 = F_15 ( V_44 -> V_49 ,
V_45 -> V_49 ) ;
V_4 -> V_8 = V_44 -> V_8 & V_45 -> V_8 ;
V_4 -> V_50 = V_44 -> V_50 & V_45 -> V_50 ;
if ( V_44 -> V_50
& ( V_51 | V_52 ) )
V_4 -> V_50 |= V_45 -> V_50 ;
if ( V_45 -> V_50
& ( V_51 | V_52 ) )
V_4 -> V_50 |= V_44 -> V_50 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
struct V_57 * V_58 = V_55 -> V_30 ;
struct V_57 * V_59 = V_56 -> V_30 ;
int V_29 = 0 ;
F_17 ( V_55 -> V_22 ) ;
F_17 ( V_56 -> V_22 ) ;
F_17 ( V_54 -> V_22 ) ;
F_18 ( & V_27 -> V_60 , V_27 -> V_61 ) ;
if ( V_55 -> V_30 -> V_62 -> V_63 ) {
V_29 = V_55 -> V_30 -> V_62 -> V_63 ( V_2 , V_55 ) ;
if ( V_29 < 0 ) {
F_9 ( V_55 -> V_22 , L_6
L_7 , V_55 -> V_24 , V_29 ) ;
goto V_64;
}
}
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_65 ) {
V_29 = V_54 -> V_30 -> V_62 -> V_65 ( V_2 ) ;
if ( V_29 < 0 ) {
F_9 ( V_54 -> V_22 , L_8
L_7 , V_54 -> V_24 , V_29 ) ;
goto V_66;
}
}
if ( V_56 -> V_30 -> V_62 -> V_63 ) {
V_29 = V_56 -> V_30 -> V_62 -> V_63 ( V_2 , V_56 ) ;
if ( V_29 < 0 ) {
F_9 ( V_56 -> V_22 , L_9
L_7 , V_56 -> V_24 , V_29 ) ;
goto V_67;
}
}
if ( V_27 -> V_23 -> V_62 && V_27 -> V_23 -> V_62 -> V_63 ) {
V_29 = V_27 -> V_23 -> V_62 -> V_63 ( V_2 ) ;
if ( V_29 < 0 ) {
F_19 ( L_10 ,
V_27 -> V_23 -> V_24 , V_29 ) ;
goto V_68;
}
}
if ( V_27 -> V_23 -> V_69 || V_27 -> V_23 -> V_70 )
goto V_69;
if ( V_2 -> V_37 == V_38 ) {
F_13 ( & V_6 -> V_4 , & V_59 -> V_39 ,
& V_58 -> V_39 ) ;
} else {
F_13 ( & V_6 -> V_4 , & V_59 -> V_41 ,
& V_58 -> V_41 ) ;
}
V_29 = - V_71 ;
F_20 ( V_6 ) ;
if ( ! V_6 -> V_4 . V_50 ) {
F_21 ( V_72 L_11 ,
V_56 -> V_24 , V_55 -> V_24 ) ;
goto V_73;
}
if ( ! V_6 -> V_4 . V_8 ) {
F_21 ( V_72 L_12 ,
V_56 -> V_24 , V_55 -> V_24 ) ;
goto V_73;
}
if ( ! V_6 -> V_4 . V_48 || ! V_6 -> V_4 . V_49 ||
V_6 -> V_4 . V_48 > V_6 -> V_4 . V_49 ) {
F_21 ( V_72 L_13 ,
V_56 -> V_24 , V_55 -> V_24 ) ;
goto V_73;
}
F_10 ( V_2 , V_56 ) ;
F_10 ( V_2 , V_55 ) ;
if ( V_55 -> V_74 ) {
V_29 = F_6 ( V_2 , V_55 ) ;
if ( V_29 != 0 )
goto V_73;
}
if ( V_56 -> V_74 ) {
V_29 = F_6 ( V_2 , V_56 ) ;
if ( V_29 != 0 )
goto V_73;
}
F_22 ( L_14 ,
V_56 -> V_24 , V_55 -> V_24 ) ;
F_22 ( L_15 , V_6 -> V_4 . V_50 ) ;
F_22 ( L_16 , V_6 -> V_4 . V_48 ,
V_6 -> V_4 . V_49 ) ;
F_22 ( L_17 , V_6 -> V_4 . V_46 ,
V_6 -> V_4 . V_47 ) ;
V_69:
if ( V_2 -> V_37 == V_38 ) {
V_55 -> V_75 ++ ;
V_56 -> V_75 ++ ;
} else {
V_55 -> V_76 ++ ;
V_56 -> V_76 ++ ;
}
V_55 -> V_74 ++ ;
V_56 -> V_74 ++ ;
V_27 -> V_77 -> V_74 ++ ;
F_23 ( & V_27 -> V_60 ) ;
return 0 ;
V_73:
if ( V_27 -> V_23 -> V_62 && V_27 -> V_23 -> V_62 -> V_78 )
V_27 -> V_23 -> V_62 -> V_78 ( V_2 ) ;
V_68:
if ( V_56 -> V_30 -> V_62 -> V_78 )
V_56 -> V_30 -> V_62 -> V_78 ( V_2 , V_56 ) ;
V_67:
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_79 )
V_54 -> V_30 -> V_62 -> V_79 ( V_2 ) ;
V_66:
if ( V_55 -> V_30 -> V_62 -> V_78 )
V_55 -> V_30 -> V_62 -> V_78 ( V_2 , V_55 ) ;
V_64:
F_23 ( & V_27 -> V_60 ) ;
F_24 ( V_54 -> V_22 ) ;
F_24 ( V_56 -> V_22 ) ;
F_24 ( V_55 -> V_22 ) ;
return V_29 ;
}
static void F_25 ( struct V_80 * V_81 )
{
struct V_15 * V_27 =
F_26 ( V_81 , struct V_15 , V_82 . V_81 ) ;
struct V_25 * V_56 = V_27 -> V_56 ;
F_18 ( & V_27 -> V_60 , V_27 -> V_61 ) ;
F_4 ( V_27 -> V_22 , L_18 ,
V_56 -> V_30 -> V_39 . V_83 ,
V_56 -> V_75 ? L_19 : L_20 ,
V_27 -> V_84 ? L_21 : L_22 ) ;
if ( V_27 -> V_84 == 1 ) {
V_27 -> V_84 = 0 ;
F_5 ( V_27 , V_38 ,
V_85 ) ;
}
F_23 ( & V_27 -> V_60 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
struct V_86 * V_77 = V_27 -> V_77 ;
F_18 ( & V_27 -> V_60 , V_27 -> V_61 ) ;
if ( V_2 -> V_37 == V_38 ) {
V_55 -> V_75 -- ;
V_56 -> V_75 -- ;
} else {
V_55 -> V_76 -- ;
V_56 -> V_76 -- ;
}
V_55 -> V_74 -- ;
V_56 -> V_74 -- ;
V_77 -> V_74 -- ;
if ( ! V_55 -> V_74 )
V_55 -> V_32 = 0 ;
if ( ! V_56 -> V_74 )
V_56 -> V_32 = 0 ;
F_28 ( V_56 , 1 , V_2 -> V_37 ) ;
if ( V_55 -> V_30 -> V_62 -> V_78 )
V_55 -> V_30 -> V_62 -> V_78 ( V_2 , V_55 ) ;
if ( V_56 -> V_30 -> V_62 -> V_78 )
V_56 -> V_30 -> V_62 -> V_78 ( V_2 , V_56 ) ;
if ( V_27 -> V_23 -> V_62 && V_27 -> V_23 -> V_62 -> V_78 )
V_27 -> V_23 -> V_62 -> V_78 ( V_2 ) ;
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_79 )
V_54 -> V_30 -> V_62 -> V_79 ( V_2 ) ;
V_55 -> V_6 = NULL ;
if ( V_2 -> V_37 == V_38 ) {
if ( ! V_27 -> V_87 || V_77 -> V_88 ||
V_27 -> V_23 -> V_88 ) {
F_5 ( V_27 ,
V_38 ,
V_85 ) ;
} else {
V_27 -> V_84 = 1 ;
F_29 ( & V_27 -> V_82 ,
F_30 ( V_27 -> V_87 ) ) ;
}
} else {
F_5 ( V_27 , V_89 ,
V_85 ) ;
}
F_23 ( & V_27 -> V_60 ) ;
F_24 ( V_54 -> V_22 ) ;
F_24 ( V_56 -> V_22 ) ;
F_24 ( V_55 -> V_22 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
int V_29 = 0 ;
F_18 ( & V_27 -> V_60 , V_27 -> V_61 ) ;
if ( V_27 -> V_23 -> V_62 && V_27 -> V_23 -> V_62 -> V_90 ) {
V_29 = V_27 -> V_23 -> V_62 -> V_90 ( V_2 ) ;
if ( V_29 < 0 ) {
F_9 ( V_27 -> V_91 -> V_22 , L_23
L_24 , V_29 ) ;
goto V_64;
}
}
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_90 ) {
V_29 = V_54 -> V_30 -> V_62 -> V_90 ( V_2 ) ;
if ( V_29 < 0 ) {
F_9 ( V_54 -> V_22 , L_25
L_24 , V_29 ) ;
goto V_64;
}
}
if ( V_56 -> V_30 -> V_62 -> V_90 ) {
V_29 = V_56 -> V_30 -> V_62 -> V_90 ( V_2 , V_56 ) ;
if ( V_29 < 0 ) {
F_9 ( V_56 -> V_22 , L_26 ,
V_29 ) ;
goto V_64;
}
}
if ( V_55 -> V_30 -> V_62 -> V_90 ) {
V_29 = V_55 -> V_30 -> V_62 -> V_90 ( V_2 , V_55 ) ;
if ( V_29 < 0 ) {
F_9 ( V_55 -> V_22 , L_26 ,
V_29 ) ;
goto V_64;
}
}
if ( V_2 -> V_37 == V_38 &&
V_27 -> V_84 ) {
V_27 -> V_84 = 0 ;
F_32 ( & V_27 -> V_82 ) ;
}
F_5 ( V_27 , V_2 -> V_37 ,
V_92 ) ;
F_28 ( V_56 , 0 , V_2 -> V_37 ) ;
V_64:
F_23 ( & V_27 -> V_60 ) ;
return V_29 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
int V_29 = 0 ;
F_18 ( & V_27 -> V_60 , V_27 -> V_61 ) ;
if ( V_27 -> V_23 -> V_62 && V_27 -> V_23 -> V_62 -> V_95 ) {
V_29 = V_27 -> V_23 -> V_62 -> V_95 ( V_2 , V_94 ) ;
if ( V_29 < 0 ) {
F_9 ( V_27 -> V_91 -> V_22 , L_27
L_28 , V_29 ) ;
goto V_64;
}
}
if ( V_56 -> V_30 -> V_62 -> V_95 ) {
V_29 = V_56 -> V_30 -> V_62 -> V_95 ( V_2 , V_94 , V_56 ) ;
if ( V_29 < 0 ) {
F_9 ( V_56 -> V_22 , L_29
L_24 , V_56 -> V_24 , V_29 ) ;
goto V_96;
}
}
if ( V_55 -> V_30 -> V_62 -> V_95 ) {
V_29 = V_55 -> V_30 -> V_62 -> V_95 ( V_2 , V_94 , V_55 ) ;
if ( V_29 < 0 ) {
F_9 ( V_55 -> V_22 , L_30 ,
V_55 -> V_24 , V_29 ) ;
goto V_97;
}
}
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_95 ) {
V_29 = V_54 -> V_30 -> V_62 -> V_95 ( V_2 , V_94 ) ;
if ( V_29 < 0 ) {
F_9 ( V_54 -> V_22 , L_30 ,
V_54 -> V_24 , V_29 ) ;
goto V_66;
}
}
V_55 -> V_32 = F_34 ( V_94 ) ;
V_56 -> V_32 = F_34 ( V_94 ) ;
V_64:
F_23 ( & V_27 -> V_60 ) ;
return V_29 ;
V_66:
if ( V_55 -> V_30 -> V_62 -> V_98 )
V_55 -> V_30 -> V_62 -> V_98 ( V_2 , V_55 ) ;
V_97:
if ( V_56 -> V_30 -> V_62 -> V_98 )
V_56 -> V_30 -> V_62 -> V_98 ( V_2 , V_56 ) ;
V_96:
if ( V_27 -> V_23 -> V_62 && V_27 -> V_23 -> V_62 -> V_98 )
V_27 -> V_23 -> V_62 -> V_98 ( V_2 ) ;
F_23 ( & V_27 -> V_60 ) ;
return V_29 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
struct V_86 * V_77 = V_27 -> V_77 ;
F_18 ( & V_27 -> V_60 , V_27 -> V_61 ) ;
if ( ! V_77 -> V_74 )
F_28 ( V_56 , 1 , V_2 -> V_37 ) ;
if ( V_27 -> V_23 -> V_62 && V_27 -> V_23 -> V_62 -> V_98 )
V_27 -> V_23 -> V_62 -> V_98 ( V_2 ) ;
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_98 )
V_54 -> V_30 -> V_62 -> V_98 ( V_2 ) ;
if ( V_56 -> V_30 -> V_62 -> V_98 )
V_56 -> V_30 -> V_62 -> V_98 ( V_2 , V_56 ) ;
if ( V_55 -> V_30 -> V_62 -> V_98 )
V_55 -> V_30 -> V_62 -> V_98 ( V_2 , V_55 ) ;
F_23 ( & V_27 -> V_60 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , int V_99 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
int V_29 ;
if ( V_56 -> V_30 -> V_62 -> V_100 ) {
V_29 = V_56 -> V_30 -> V_62 -> V_100 ( V_2 , V_99 , V_56 ) ;
if ( V_29 < 0 )
return V_29 ;
}
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_100 ) {
V_29 = V_54 -> V_30 -> V_62 -> V_100 ( V_2 , V_99 ) ;
if ( V_29 < 0 )
return V_29 ;
}
if ( V_55 -> V_30 -> V_62 -> V_100 ) {
V_29 = V_55 -> V_30 -> V_62 -> V_100 ( V_2 , V_99 , V_55 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
int V_99 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
int V_29 ;
if ( V_56 -> V_30 -> V_62 -> V_101 ) {
V_29 = V_56 -> V_30 -> V_62 -> V_101 ( V_2 , V_99 , V_56 ) ;
if ( V_29 < 0 )
return V_29 ;
}
if ( V_54 -> V_30 -> V_101 ) {
V_29 = V_54 -> V_30 -> V_101 ( V_2 , V_99 ) ;
if ( V_29 < 0 )
return V_29 ;
}
if ( V_55 -> V_30 -> V_62 -> V_101 ) {
V_29 = V_55 -> V_30 -> V_62 -> V_101 ( V_2 , V_99 , V_55 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_102 = 0 ;
T_2 V_103 = 0 ;
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_104 )
V_102 = V_54 -> V_30 -> V_62 -> V_104 ( V_2 ) ;
if ( V_55 -> V_30 -> V_62 -> V_103 )
V_103 += V_55 -> V_30 -> V_62 -> V_103 ( V_2 , V_55 ) ;
if ( V_56 -> V_30 -> V_62 -> V_103 )
V_103 += V_56 -> V_30 -> V_62 -> V_103 ( V_2 , V_56 ) ;
if ( V_54 -> V_30 -> V_103 )
V_103 += V_54 -> V_30 -> V_103 ( V_2 , V_56 ) ;
V_6 -> V_103 = V_103 ;
return V_102 ;
}
static int F_39 ( struct V_15 * V_16 ,
struct V_15 * V_21 , int V_37 )
{
struct V_19 * V_20 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
if ( V_20 -> V_21 == V_21 && V_20 -> V_16 == V_16 )
return 0 ;
}
V_20 = F_40 ( sizeof( struct V_19 ) , V_105 ) ;
if ( ! V_20 )
return - V_106 ;
V_20 -> V_21 = V_21 ;
V_20 -> V_16 = V_16 ;
V_21 -> V_20 [ V_37 ] . V_6 = V_16 -> V_20 [ V_37 ] . V_6 ;
V_20 -> V_107 = V_108 ;
F_41 ( & V_20 -> V_109 , & V_16 -> V_20 [ V_37 ] . V_110 ) ;
F_41 ( & V_20 -> V_111 , & V_21 -> V_20 [ V_37 ] . V_112 ) ;
F_4 ( V_16 -> V_22 , L_31 ,
V_37 ? L_32 : L_33 , V_16 -> V_23 -> V_24 ,
V_37 ? L_34 : L_35 , V_21 -> V_23 -> V_24 ) ;
#ifdef F_42
V_20 -> V_113 = F_43 ( V_21 -> V_23 -> V_24 , 0644 ,
V_16 -> V_114 , & V_20 -> V_107 ) ;
#endif
return 1 ;
}
static void F_44 ( struct V_15 * V_16 ,
struct V_15 * V_21 , int V_37 )
{
struct V_19 * V_20 ;
struct V_1 * V_115 , * V_116 ;
if ( ! V_21 -> V_20 [ V_37 ] . V_117 )
return;
V_116 = F_45 ( V_21 , V_37 ) ;
F_3 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_20 -> V_16 == V_16 )
continue;
F_4 ( V_16 -> V_22 , L_36 ,
V_37 ? L_32 : L_33 ,
V_20 -> V_16 -> V_23 -> V_24 ,
V_37 ? L_34 : L_35 , V_20 -> V_21 -> V_23 -> V_24 ) ;
V_115 = F_45 ( V_20 -> V_16 , V_37 ) ;
V_116 -> V_6 = V_115 -> V_6 ;
break;
}
}
static void F_46 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 , * V_118 ;
F_47 (dpcm, d, &fe->dpcm[stream].be_clients, list_be) {
F_4 ( V_16 -> V_22 , L_37 ,
V_37 ? L_32 : L_33 ,
V_20 -> V_21 -> V_23 -> V_24 ) ;
if ( V_20 -> V_107 != V_119 )
continue;
F_4 ( V_16 -> V_22 , L_38 ,
V_37 ? L_32 : L_33 , V_16 -> V_23 -> V_24 ,
V_37 ? L_34 : L_35 , V_20 -> V_21 -> V_23 -> V_24 ) ;
F_44 ( V_16 , V_20 -> V_21 , V_37 ) ;
#ifdef F_42
F_48 ( V_20 -> V_113 ) ;
#endif
F_49 ( & V_20 -> V_109 ) ;
F_49 ( & V_20 -> V_111 ) ;
F_50 ( V_20 ) ;
}
}
static struct V_15 * F_51 ( struct V_120 * V_91 ,
struct V_121 * V_122 , int V_37 )
{
struct V_15 * V_21 ;
int V_35 ;
if ( V_37 == V_38 ) {
for ( V_35 = 0 ; V_35 < V_91 -> V_123 ; V_35 ++ ) {
V_21 = & V_91 -> V_27 [ V_35 ] ;
if ( ! V_21 -> V_23 -> V_70 )
continue;
if ( V_21 -> V_55 -> V_124 == V_122 ||
V_21 -> V_56 -> V_124 == V_122 )
return V_21 ;
}
} else {
for ( V_35 = 0 ; V_35 < V_91 -> V_123 ; V_35 ++ ) {
V_21 = & V_91 -> V_27 [ V_35 ] ;
if ( ! V_21 -> V_23 -> V_70 )
continue;
if ( V_21 -> V_55 -> V_125 == V_122 ||
V_21 -> V_56 -> V_125 == V_122 )
return V_21 ;
}
}
F_9 ( V_91 -> V_22 , L_39 ,
V_37 ? L_32 : L_33 , V_122 -> V_24 ) ;
return NULL ;
}
static inline struct V_121 *
F_52 ( struct V_15 * V_27 , int V_37 )
{
if ( V_37 == V_38 )
return V_27 -> V_55 -> V_124 ;
else
return V_27 -> V_55 -> V_125 ;
}
static inline struct V_121 *
F_53 ( struct V_15 * V_27 , int V_37 )
{
if ( V_37 == V_38 )
return V_27 -> V_56 -> V_124 ;
else
return V_27 -> V_56 -> V_125 ;
}
static int F_54 ( struct V_126 * V_127 ,
struct V_121 * V_122 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_127 -> V_128 ; V_35 ++ ) {
if ( V_122 == V_127 -> V_129 [ V_35 ] )
return 1 ;
}
return 0 ;
}
static int F_55 ( struct V_15 * V_16 ,
int V_37 , struct V_126 * * V_130 )
{
struct V_25 * V_55 = V_16 -> V_55 ;
struct V_126 * V_127 ;
int V_131 ;
V_127 = F_40 ( sizeof( struct V_126 ) +
sizeof( struct V_121 * ) , V_105 ) ;
if ( V_127 == NULL )
return - V_106 ;
V_131 = F_56 ( V_55 , V_37 , & V_127 ) ;
F_4 ( V_16 -> V_22 , L_40 , V_131 ,
V_37 ? L_32 : L_33 ) ;
* V_130 = V_127 ;
return V_131 ;
}
static inline void F_57 ( struct V_126 * * V_127 )
{
F_50 ( * V_127 ) ;
}
static int F_58 ( struct V_15 * V_16 , int V_37 ,
struct V_126 * * V_130 )
{
struct V_19 * V_20 ;
struct V_126 * V_127 = * V_130 ;
struct V_121 * V_122 ;
int V_132 = 0 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
V_122 = F_52 ( V_20 -> V_21 , V_37 ) ;
if ( V_122 && F_54 ( V_127 , V_122 ) )
continue;
V_122 = F_53 ( V_20 -> V_21 , V_37 ) ;
if ( V_122 && F_54 ( V_127 , V_122 ) )
continue;
F_4 ( V_16 -> V_22 , L_41 ,
V_37 ? L_32 : L_33 ,
V_20 -> V_21 -> V_23 -> V_24 , V_16 -> V_23 -> V_24 ) ;
V_20 -> V_107 = V_119 ;
V_20 -> V_21 -> V_20 [ V_37 ] . V_133 = V_134 ;
V_132 ++ ;
}
F_4 ( V_16 -> V_22 , L_42 , V_132 ) ;
return V_132 ;
}
static int F_59 ( struct V_15 * V_16 , int V_37 ,
struct V_126 * * V_130 )
{
struct V_120 * V_91 = V_16 -> V_91 ;
struct V_126 * V_127 = * V_130 ;
struct V_15 * V_21 ;
int V_35 , V_135 = 0 , V_136 ;
for ( V_35 = 0 ; V_35 < V_127 -> V_128 ; V_35 ++ ) {
switch ( V_127 -> V_129 [ V_35 ] -> V_137 ) {
case V_138 :
case V_139 :
break;
default:
continue;
}
V_21 = F_51 ( V_91 , V_127 -> V_129 [ V_35 ] , V_37 ) ;
if ( ! V_21 ) {
F_9 ( V_16 -> V_22 , L_43 ,
V_127 -> V_129 [ V_35 ] -> V_24 ) ;
continue;
}
if ( ! V_21 -> V_23 -> V_70 )
continue;
if ( ! V_16 -> V_20 [ V_37 ] . V_6 )
continue;
V_136 = F_39 ( V_16 , V_21 , V_37 ) ;
if ( V_136 < 0 ) {
F_9 ( V_16 -> V_22 , L_44 ,
V_127 -> V_129 [ V_35 ] -> V_24 ) ;
break;
} else if ( V_136 == 0 )
continue;
V_21 -> V_20 [ V_37 ] . V_133 = V_134 ;
V_135 ++ ;
}
F_4 ( V_16 -> V_22 , L_45 , V_135 ) ;
return V_135 ;
}
static int F_60 ( struct V_15 * V_16 ,
int V_37 , struct V_126 * * V_127 , int V_135 )
{
if ( V_135 )
return F_59 ( V_16 , V_37 , V_127 ) ;
else
return F_58 ( V_16 , V_37 , V_127 ) ;
}
static void F_61 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_20 -> V_21 -> V_20 [ V_37 ] . V_133 =
V_140 ;
}
static void F_62 ( struct V_15 * V_16 ,
int V_37 )
{
struct V_19 * V_20 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_116 =
F_45 ( V_21 , V_37 ) ;
if ( V_21 -> V_20 [ V_37 ] . V_117 == 0 )
F_9 ( V_21 -> V_22 , L_46 ,
V_37 ? L_32 : L_33 ,
V_21 -> V_20 [ V_37 ] . V_107 ) ;
if ( -- V_21 -> V_20 [ V_37 ] . V_117 != 0 )
continue;
if ( V_21 -> V_20 [ V_37 ] . V_107 != V_141 )
continue;
F_27 ( V_116 ) ;
V_116 -> V_6 = NULL ;
V_21 -> V_20 [ V_37 ] . V_107 = V_142 ;
}
}
static int F_63 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 ;
int V_136 , V_143 = 0 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_116 =
F_45 ( V_21 , V_37 ) ;
if ( ! F_64 ( V_16 , V_21 , V_37 ) )
continue;
if ( V_21 -> V_20 [ V_37 ] . V_117 == V_144 )
F_9 ( V_21 -> V_22 , L_47 ,
V_37 ? L_32 : L_33 ,
V_21 -> V_20 [ V_37 ] . V_107 ) ;
if ( V_21 -> V_20 [ V_37 ] . V_117 ++ != 0 )
continue;
if ( ( V_21 -> V_20 [ V_37 ] . V_107 != V_145 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 != V_142 ) )
continue;
F_4 ( V_21 -> V_22 , L_48 , V_21 -> V_23 -> V_24 ) ;
V_116 -> V_6 = V_21 -> V_20 [ V_37 ] . V_6 ;
V_136 = F_16 ( V_116 ) ;
if ( V_136 < 0 ) {
F_9 ( V_21 -> V_22 , L_49 , V_136 ) ;
V_21 -> V_20 [ V_37 ] . V_117 -- ;
if ( V_21 -> V_20 [ V_37 ] . V_117 < 0 )
F_9 ( V_21 -> V_22 , L_50 ,
V_37 ? L_32 : L_33 ,
V_21 -> V_20 [ V_37 ] . V_107 ) ;
V_21 -> V_20 [ V_37 ] . V_107 = V_142 ;
goto V_146;
}
V_21 -> V_20 [ V_37 ] . V_107 = V_141 ;
V_143 ++ ;
}
return V_143 ;
V_146:
F_65 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_116 =
F_45 ( V_21 , V_37 ) ;
if ( ! F_64 ( V_16 , V_21 , V_37 ) )
continue;
if ( V_21 -> V_20 [ V_37 ] . V_117 == 0 )
F_9 ( V_21 -> V_22 , L_51 ,
V_37 ? L_32 : L_33 ,
V_21 -> V_20 [ V_37 ] . V_107 ) ;
if ( -- V_21 -> V_20 [ V_37 ] . V_117 != 0 )
continue;
if ( V_21 -> V_20 [ V_37 ] . V_107 != V_141 )
continue;
F_27 ( V_116 ) ;
V_116 -> V_6 = NULL ;
V_21 -> V_20 [ V_37 ] . V_107 = V_142 ;
}
return V_136 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_57 * V_58 = V_55 -> V_30 ;
if ( V_2 -> V_37 == V_38 ) {
V_6 -> V_4 . V_46 = V_58 -> V_39 . V_46 ;
V_6 -> V_4 . V_47 = V_58 -> V_39 . V_47 ;
V_6 -> V_4 . V_48 = V_58 -> V_39 . V_48 ;
V_6 -> V_4 . V_49 = V_58 -> V_39 . V_49 ;
V_6 -> V_4 . V_8 &= V_58 -> V_39 . V_8 ;
V_6 -> V_4 . V_50 = V_58 -> V_39 . V_50 ;
} else {
V_6 -> V_4 . V_46 = V_58 -> V_41 . V_46 ;
V_6 -> V_4 . V_47 = V_58 -> V_41 . V_47 ;
V_6 -> V_4 . V_48 = V_58 -> V_41 . V_48 ;
V_6 -> V_4 . V_49 = V_58 -> V_41 . V_49 ;
V_6 -> V_4 . V_8 &= V_58 -> V_41 . V_8 ;
V_6 -> V_4 . V_50 = V_58 -> V_41 . V_50 ;
}
}
static int F_67 ( struct V_1 * V_115 )
{
struct V_15 * V_16 = V_115 -> V_28 ;
struct V_5 * V_6 = V_115 -> V_6 ;
int V_37 = V_115 -> V_37 , V_29 = 0 ;
V_16 -> V_20 [ V_37 ] . V_133 = V_147 ;
V_29 = F_63 ( V_16 , V_115 -> V_37 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_52 , V_29 ) ;
goto V_148;
}
F_4 ( V_16 -> V_22 , L_53 , V_16 -> V_23 -> V_24 ) ;
V_29 = F_16 ( V_115 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_54 , V_29 ) ;
goto V_146;
}
V_16 -> V_20 [ V_37 ] . V_107 = V_141 ;
F_66 ( V_115 ) ;
F_20 ( V_6 ) ;
V_16 -> V_20 [ V_37 ] . V_133 = V_140 ;
return 0 ;
V_146:
F_62 ( V_16 , V_115 -> V_37 ) ;
V_148:
V_16 -> V_20 [ V_37 ] . V_133 = V_140 ;
return V_29 ;
}
static int F_68 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_116 =
F_45 ( V_21 , V_37 ) ;
if ( ! F_64 ( V_16 , V_21 , V_37 ) )
continue;
if ( V_21 -> V_20 [ V_37 ] . V_117 == 0 )
F_9 ( V_21 -> V_22 , L_46 ,
V_37 ? L_32 : L_33 ,
V_21 -> V_20 [ V_37 ] . V_107 ) ;
if ( -- V_21 -> V_20 [ V_37 ] . V_117 != 0 )
continue;
if ( ( V_21 -> V_20 [ V_37 ] . V_107 != V_149 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 != V_141 ) )
continue;
F_4 ( V_21 -> V_22 , L_55 ,
V_20 -> V_16 -> V_23 -> V_24 ) ;
F_27 ( V_116 ) ;
V_116 -> V_6 = NULL ;
V_21 -> V_20 [ V_37 ] . V_107 = V_142 ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_37 = V_2 -> V_37 ;
V_16 -> V_20 [ V_37 ] . V_133 = V_147 ;
F_68 ( V_16 , V_2 -> V_37 ) ;
F_4 ( V_16 -> V_22 , L_56 , V_16 -> V_23 -> V_24 ) ;
F_27 ( V_2 ) ;
F_2 ( V_16 , V_37 , V_85 ) ;
V_16 -> V_20 [ V_37 ] . V_107 = V_142 ;
V_16 -> V_20 [ V_37 ] . V_133 = V_140 ;
return 0 ;
}
static int F_70 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_116 =
F_45 ( V_21 , V_37 ) ;
if ( ! F_64 ( V_16 , V_21 , V_37 ) )
continue;
if ( ! F_71 ( V_16 , V_21 , V_37 ) )
continue;
if ( ( V_21 -> V_20 [ V_37 ] . V_107 != V_150 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 != V_151 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 != V_149 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 != V_152 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 != V_153 ) )
continue;
F_4 ( V_21 -> V_22 , L_57 ,
V_20 -> V_16 -> V_23 -> V_24 ) ;
F_35 ( V_116 ) ;
V_21 -> V_20 [ V_37 ] . V_107 = V_149 ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_136 , V_37 = V_2 -> V_37 ;
F_18 ( & V_16 -> V_91 -> V_154 , V_155 ) ;
V_16 -> V_20 [ V_37 ] . V_133 = V_147 ;
F_4 ( V_16 -> V_22 , L_58 , V_16 -> V_23 -> V_24 ) ;
V_136 = F_35 ( V_2 ) ;
if ( V_136 < 0 )
F_9 ( V_16 -> V_22 , L_59 ,
V_16 -> V_23 -> V_24 ) ;
V_136 = F_70 ( V_16 , V_37 ) ;
V_16 -> V_20 [ V_37 ] . V_107 = V_149 ;
V_16 -> V_20 [ V_37 ] . V_133 = V_140 ;
F_23 ( & V_16 -> V_91 -> V_154 ) ;
return 0 ;
}
static int F_73 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 ;
int V_29 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_116 =
F_45 ( V_21 , V_37 ) ;
if ( ! F_64 ( V_16 , V_21 , V_37 ) )
continue;
if ( ! F_74 ( V_16 , V_21 , V_37 ) )
continue;
if ( ( V_21 -> V_20 [ V_37 ] . V_107 != V_141 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 != V_150 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 != V_149 ) )
continue;
F_4 ( V_21 -> V_22 , L_60 ,
V_20 -> V_16 -> V_23 -> V_24 ) ;
memcpy ( & V_20 -> V_95 , & V_16 -> V_20 [ V_37 ] . V_95 ,
sizeof( struct V_93 ) ) ;
if ( V_21 -> V_23 -> V_156 ) {
V_29 = V_21 -> V_23 -> V_156 ( V_21 ,
& V_20 -> V_95 ) ;
if ( V_29 < 0 ) {
F_9 ( V_21 -> V_22 ,
L_61 ,
V_29 ) ;
goto V_146;
}
}
V_29 = F_33 ( V_116 , & V_20 -> V_95 ) ;
if ( V_29 < 0 ) {
F_9 ( V_20 -> V_21 -> V_22 ,
L_62 , V_29 ) ;
goto V_146;
}
V_21 -> V_20 [ V_37 ] . V_107 = V_150 ;
}
return 0 ;
V_146:
F_65 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_116 =
F_45 ( V_21 , V_37 ) ;
if ( ! F_64 ( V_16 , V_21 , V_37 ) )
continue;
if ( ! F_71 ( V_16 , V_21 , V_37 ) )
continue;
if ( ( V_21 -> V_20 [ V_37 ] . V_107 != V_141 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 != V_150 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 != V_149 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 != V_153 ) )
continue;
F_35 ( V_116 ) ;
}
return V_29 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_29 , V_37 = V_2 -> V_37 ;
F_18 ( & V_16 -> V_91 -> V_154 , V_155 ) ;
V_16 -> V_20 [ V_37 ] . V_133 = V_147 ;
memcpy ( & V_16 -> V_20 [ V_2 -> V_37 ] . V_95 , V_94 ,
sizeof( struct V_93 ) ) ;
V_29 = F_73 ( V_16 , V_2 -> V_37 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_62 , V_29 ) ;
goto V_64;
}
F_4 ( V_16 -> V_22 , L_63 ,
V_16 -> V_23 -> V_24 , F_34 ( V_94 ) ,
F_76 ( V_94 ) , F_77 ( V_94 ) ) ;
V_29 = F_33 ( V_2 , V_94 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_64 , V_29 ) ;
F_70 ( V_16 , V_37 ) ;
} else
V_16 -> V_20 [ V_37 ] . V_107 = V_150 ;
V_64:
V_16 -> V_20 [ V_37 ] . V_133 = V_140 ;
F_23 ( & V_16 -> V_91 -> V_154 ) ;
return V_29 ;
}
static int F_78 ( struct V_19 * V_20 ,
struct V_1 * V_2 , int V_99 )
{
int V_29 ;
F_4 ( V_20 -> V_21 -> V_22 , L_65 ,
V_20 -> V_16 -> V_23 -> V_24 , V_99 ) ;
V_29 = F_36 ( V_2 , V_99 ) ;
if ( V_29 < 0 )
F_9 ( V_20 -> V_21 -> V_22 , L_66 , V_29 ) ;
return V_29 ;
}
static int F_79 ( struct V_15 * V_16 , int V_37 ,
int V_99 )
{
struct V_19 * V_20 ;
int V_29 = 0 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_116 =
F_45 ( V_21 , V_37 ) ;
if ( ! F_64 ( V_16 , V_21 , V_37 ) )
continue;
switch ( V_99 ) {
case V_157 :
if ( ( V_21 -> V_20 [ V_37 ] . V_107 != V_151 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 != V_153 ) )
continue;
V_29 = F_78 ( V_20 , V_116 , V_99 ) ;
if ( V_29 )
return V_29 ;
V_21 -> V_20 [ V_37 ] . V_107 = V_158 ;
break;
case V_159 :
if ( ( V_21 -> V_20 [ V_37 ] . V_107 != V_160 ) )
continue;
V_29 = F_78 ( V_20 , V_116 , V_99 ) ;
if ( V_29 )
return V_29 ;
V_21 -> V_20 [ V_37 ] . V_107 = V_158 ;
break;
case V_161 :
if ( ( V_21 -> V_20 [ V_37 ] . V_107 != V_152 ) )
continue;
V_29 = F_78 ( V_20 , V_116 , V_99 ) ;
if ( V_29 )
return V_29 ;
V_21 -> V_20 [ V_37 ] . V_107 = V_158 ;
break;
case V_162 :
if ( V_21 -> V_20 [ V_37 ] . V_107 != V_158 )
continue;
if ( ! F_71 ( V_16 , V_21 , V_37 ) )
continue;
V_29 = F_78 ( V_20 , V_116 , V_99 ) ;
if ( V_29 )
return V_29 ;
V_21 -> V_20 [ V_37 ] . V_107 = V_153 ;
break;
case V_163 :
if ( V_21 -> V_20 [ V_37 ] . V_107 != V_153 )
continue;
if ( ! F_71 ( V_16 , V_21 , V_37 ) )
continue;
V_29 = F_78 ( V_20 , V_116 , V_99 ) ;
if ( V_29 )
return V_29 ;
V_21 -> V_20 [ V_37 ] . V_107 = V_160 ;
break;
case V_164 :
if ( V_21 -> V_20 [ V_37 ] . V_107 != V_158 )
continue;
if ( ! F_71 ( V_16 , V_21 , V_37 ) )
continue;
V_29 = F_78 ( V_20 , V_116 , V_99 ) ;
if ( V_29 )
return V_29 ;
V_21 -> V_20 [ V_37 ] . V_107 = V_152 ;
break;
}
}
return V_29 ;
}
static int F_80 ( struct V_1 * V_2 , int V_99 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_37 = V_2 -> V_37 , V_29 ;
enum V_165 V_100 = V_16 -> V_23 -> V_100 [ V_37 ] ;
V_16 -> V_20 [ V_37 ] . V_133 = V_147 ;
switch ( V_100 ) {
case V_166 :
F_4 ( V_16 -> V_22 , L_67 ,
V_16 -> V_23 -> V_24 , V_99 ) ;
V_29 = F_36 ( V_2 , V_99 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_68 , V_29 ) ;
goto V_64;
}
V_29 = F_79 ( V_16 , V_2 -> V_37 , V_99 ) ;
break;
case V_167 :
V_29 = F_79 ( V_16 , V_2 -> V_37 , V_99 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_68 , V_29 ) ;
goto V_64;
}
F_4 ( V_16 -> V_22 , L_69 ,
V_16 -> V_23 -> V_24 , V_99 ) ;
V_29 = F_36 ( V_2 , V_99 ) ;
break;
case V_168 :
F_4 ( V_16 -> V_22 , L_70 ,
V_16 -> V_23 -> V_24 , V_99 ) ;
V_29 = F_37 ( V_2 , V_99 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_68 , V_29 ) ;
goto V_64;
}
break;
default:
F_9 ( V_16 -> V_22 , L_71 , V_99 ,
V_16 -> V_23 -> V_24 ) ;
V_29 = - V_71 ;
goto V_64;
}
switch ( V_99 ) {
case V_157 :
case V_159 :
case V_161 :
V_16 -> V_20 [ V_37 ] . V_107 = V_158 ;
break;
case V_162 :
case V_163 :
case V_164 :
V_16 -> V_20 [ V_37 ] . V_107 = V_153 ;
break;
}
V_64:
V_16 -> V_20 [ V_37 ] . V_133 = V_140 ;
return V_29 ;
}
static int F_81 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 ;
int V_29 = 0 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_116 =
F_45 ( V_21 , V_37 ) ;
if ( ! F_64 ( V_16 , V_21 , V_37 ) )
continue;
if ( ( V_21 -> V_20 [ V_37 ] . V_107 != V_150 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 != V_153 ) )
continue;
F_4 ( V_21 -> V_22 , L_72 ,
V_20 -> V_16 -> V_23 -> V_24 ) ;
V_29 = F_31 ( V_116 ) ;
if ( V_29 < 0 ) {
F_9 ( V_21 -> V_22 , L_73 ,
V_29 ) ;
break;
}
V_21 -> V_20 [ V_37 ] . V_107 = V_151 ;
}
return V_29 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_37 = V_2 -> V_37 , V_29 = 0 ;
F_18 ( & V_16 -> V_91 -> V_154 , V_155 ) ;
F_4 ( V_16 -> V_22 , L_74 , V_16 -> V_23 -> V_24 ) ;
V_16 -> V_20 [ V_37 ] . V_133 = V_147 ;
if ( F_83 ( & V_16 -> V_20 [ V_37 ] . V_110 ) ) {
F_9 ( V_16 -> V_22 , L_75 ,
V_16 -> V_23 -> V_24 ) ;
V_29 = - V_71 ;
goto V_64;
}
V_29 = F_81 ( V_16 , V_2 -> V_37 ) ;
if ( V_29 < 0 )
goto V_64;
V_29 = F_31 ( V_2 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_76 ,
V_16 -> V_23 -> V_24 ) ;
goto V_64;
}
F_2 ( V_16 , V_37 , V_92 ) ;
V_16 -> V_20 [ V_37 ] . V_107 = V_151 ;
V_64:
V_16 -> V_20 [ V_37 ] . V_133 = V_140 ;
F_23 ( & V_16 -> V_91 -> V_154 ) ;
return V_29 ;
}
static int F_84 ( struct V_1 * V_2 ,
unsigned int V_99 , void * V_169 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
if ( V_54 -> V_30 -> V_62 -> V_170 )
return V_54 -> V_30 -> V_62 -> V_170 ( V_2 , V_99 , V_169 ) ;
return F_85 ( V_2 , V_99 , V_169 ) ;
}
static int F_86 ( struct V_15 * V_16 , int V_37 )
{
struct V_1 * V_2 =
F_45 ( V_16 , V_37 ) ;
enum V_165 V_100 = V_16 -> V_23 -> V_100 [ V_37 ] ;
int V_136 ;
F_4 ( V_16 -> V_22 , L_77 ,
V_37 ? L_32 : L_33 , V_16 -> V_23 -> V_24 ) ;
if ( V_100 == V_168 ) {
F_4 ( V_16 -> V_22 , L_78 ,
V_16 -> V_23 -> V_24 ) ;
V_136 = F_37 ( V_2 , V_162 ) ;
if ( V_136 < 0 )
F_9 ( V_16 -> V_22 , L_68 , V_136 ) ;
} else {
F_4 ( V_16 -> V_22 , L_79 ,
V_16 -> V_23 -> V_24 ) ;
V_136 = F_79 ( V_16 , V_37 , V_162 ) ;
if ( V_136 < 0 )
F_9 ( V_16 -> V_22 , L_68 , V_136 ) ;
}
V_136 = F_70 ( V_16 , V_37 ) ;
if ( V_136 < 0 )
F_9 ( V_16 -> V_22 , L_80 , V_136 ) ;
V_136 = F_68 ( V_16 , V_37 ) ;
if ( V_136 < 0 )
F_9 ( V_16 -> V_22 , L_81 , V_136 ) ;
F_2 ( V_16 , V_37 , V_171 ) ;
return 0 ;
}
static int F_87 ( struct V_15 * V_16 , int V_37 )
{
struct V_1 * V_2 =
F_45 ( V_16 , V_37 ) ;
struct V_19 * V_20 ;
enum V_165 V_100 = V_16 -> V_23 -> V_100 [ V_37 ] ;
int V_29 ;
F_4 ( V_16 -> V_22 , L_82 ,
V_37 ? L_32 : L_33 , V_16 -> V_23 -> V_24 ) ;
if ( V_16 -> V_20 [ V_37 ] . V_107 == V_149 ||
V_16 -> V_20 [ V_37 ] . V_107 == V_142 )
return - V_71 ;
V_29 = F_63 ( V_16 , V_37 ) ;
if ( V_29 < 0 )
goto V_172;
if ( V_16 -> V_20 [ V_37 ] . V_107 == V_141 )
return 0 ;
V_29 = F_73 ( V_16 , V_37 ) ;
if ( V_29 < 0 )
goto V_79;
if ( V_16 -> V_20 [ V_37 ] . V_107 == V_150 )
return 0 ;
V_29 = F_81 ( V_16 , V_37 ) ;
if ( V_29 < 0 )
goto V_98;
F_2 ( V_16 , V_37 , V_171 ) ;
if ( V_16 -> V_20 [ V_37 ] . V_107 == V_151 ||
V_16 -> V_20 [ V_37 ] . V_107 == V_153 )
return 0 ;
if ( V_100 == V_168 ) {
F_4 ( V_16 -> V_22 , L_83 ,
V_16 -> V_23 -> V_24 ) ;
V_29 = F_37 ( V_2 , V_157 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_84 , V_29 ) ;
goto V_98;
}
} else {
F_4 ( V_16 -> V_22 , L_85 ,
V_16 -> V_23 -> V_24 ) ;
V_29 = F_79 ( V_16 , V_37 ,
V_157 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_68 , V_29 ) ;
goto V_98;
}
}
return 0 ;
V_98:
F_70 ( V_16 , V_37 ) ;
V_79:
F_68 ( V_16 , V_37 ) ;
V_172:
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
if ( V_21 -> V_20 [ V_37 ] . V_107 != V_158 )
V_20 -> V_107 = V_119 ;
}
return V_29 ;
}
static int F_88 ( struct V_15 * V_16 , int V_37 )
{
int V_29 ;
V_16 -> V_20 [ V_37 ] . V_133 = V_134 ;
V_29 = F_87 ( V_16 , V_37 ) ;
if ( V_29 < 0 )
F_9 ( V_16 -> V_22 , L_86 ) ;
V_16 -> V_20 [ V_37 ] . V_133 = V_140 ;
return V_29 ;
}
static int F_89 ( struct V_15 * V_16 , int V_37 )
{
int V_29 ;
V_16 -> V_20 [ V_37 ] . V_133 = V_134 ;
V_29 = F_86 ( V_16 , V_37 ) ;
if ( V_29 < 0 )
F_9 ( V_16 -> V_22 , L_87 ) ;
V_16 -> V_20 [ V_37 ] . V_133 = V_140 ;
return V_29 ;
}
int F_90 ( struct V_121 * V_122 )
{
struct V_120 * V_91 ;
int V_35 , V_173 , V_135 , V_131 ;
if ( V_122 -> V_77 )
V_91 = V_122 -> V_77 -> V_91 ;
else if ( V_122 -> V_54 )
V_91 = V_122 -> V_54 -> V_91 ;
else
return - V_71 ;
F_18 ( & V_91 -> V_154 , V_155 ) ;
for ( V_35 = 0 ; V_35 < V_91 -> V_174 ; V_35 ++ ) {
struct V_126 * V_127 ;
struct V_15 * V_16 = & V_91 -> V_27 [ V_35 ] ;
if ( ! V_16 -> V_23 -> V_69 )
continue;
if ( ! V_16 -> V_55 -> V_74 )
continue;
F_4 ( V_16 -> V_22 , L_88 ,
V_16 -> V_23 -> V_24 ) ;
if ( ! V_16 -> V_55 -> V_30 -> V_39 . V_48 )
goto V_41;
V_131 = F_55 ( V_16 , V_38 , & V_127 ) ;
if ( V_131 < 0 ) {
F_7 ( V_16 -> V_22 , L_89 ,
V_16 -> V_23 -> V_24 , L_33 ) ;
F_23 ( & V_91 -> V_154 ) ;
return V_131 ;
}
V_135 = F_60 ( V_16 , V_38 , & V_127 , 1 ) ;
if ( V_135 ) {
F_88 ( V_16 , V_38 ) ;
F_61 ( V_16 , V_38 ) ;
F_46 ( V_16 , V_38 ) ;
}
V_173 = F_60 ( V_16 , V_38 , & V_127 , 0 ) ;
if ( V_173 ) {
F_89 ( V_16 , V_38 ) ;
F_61 ( V_16 , V_38 ) ;
F_46 ( V_16 , V_38 ) ;
}
V_41:
if ( ! V_16 -> V_55 -> V_30 -> V_41 . V_48 )
continue;
V_131 = F_55 ( V_16 , V_89 , & V_127 ) ;
if ( V_131 < 0 ) {
F_7 ( V_16 -> V_22 , L_89 ,
V_16 -> V_23 -> V_24 , L_32 ) ;
F_23 ( & V_91 -> V_154 ) ;
return V_131 ;
}
V_135 = F_60 ( V_16 , V_89 , & V_127 , 1 ) ;
if ( V_135 ) {
F_88 ( V_16 , V_89 ) ;
F_61 ( V_16 , V_89 ) ;
F_46 ( V_16 , V_89 ) ;
}
V_173 = F_60 ( V_16 , V_89 , & V_127 , 0 ) ;
if ( V_173 ) {
F_89 ( V_16 , V_89 ) ;
F_61 ( V_16 , V_89 ) ;
F_46 ( V_16 , V_89 ) ;
}
F_57 ( & V_127 ) ;
}
F_23 ( & V_91 -> V_154 ) ;
return 0 ;
}
int F_91 ( struct V_15 * V_16 , int V_175 )
{
struct V_19 * V_20 ;
struct V_176 * V_177 =
& V_16 -> V_20 [ V_38 ] . V_110 ;
F_3 (dpcm, clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_25 * V_34 = V_21 -> V_56 ;
struct V_57 * V_178 = V_34 -> V_30 ;
if ( V_21 -> V_23 -> V_179 )
continue;
F_4 ( V_21 -> V_22 , L_90 , V_21 -> V_23 -> V_24 ) ;
if ( V_178 -> V_62 -> V_180 && V_34 -> V_75 )
V_178 -> V_62 -> V_180 ( V_34 , V_175 ) ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_115 )
{
struct V_15 * V_16 = V_115 -> V_28 ;
struct V_19 * V_20 ;
struct V_126 * V_127 ;
int V_29 ;
int V_37 = V_115 -> V_37 ;
F_18 ( & V_16 -> V_91 -> V_154 , V_155 ) ;
V_16 -> V_20 [ V_37 ] . V_6 = V_115 -> V_6 ;
if ( F_55 ( V_16 , V_37 , & V_127 ) <= 0 ) {
F_4 ( V_16 -> V_22 , L_91 ,
V_16 -> V_23 -> V_24 , V_37 ? L_32 : L_33 ) ;
}
F_60 ( V_16 , V_37 , & V_127 , 1 ) ;
V_29 = F_67 ( V_115 ) ;
if ( V_29 < 0 ) {
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_20 -> V_107 = V_119 ;
F_46 ( V_16 , V_37 ) ;
V_16 -> V_20 [ V_37 ] . V_6 = NULL ;
}
F_61 ( V_16 , V_37 ) ;
F_57 ( & V_127 ) ;
F_23 ( & V_16 -> V_91 -> V_154 ) ;
return V_29 ;
}
static int F_93 ( struct V_1 * V_115 )
{
struct V_15 * V_16 = V_115 -> V_28 ;
struct V_19 * V_20 ;
int V_37 = V_115 -> V_37 , V_29 ;
F_18 ( & V_16 -> V_91 -> V_154 , V_155 ) ;
V_29 = F_69 ( V_115 ) ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_20 -> V_107 = V_119 ;
F_46 ( V_16 , V_37 ) ;
V_16 -> V_20 [ V_37 ] . V_6 = NULL ;
F_23 ( & V_16 -> V_91 -> V_154 ) ;
return V_29 ;
}
int F_94 ( struct V_15 * V_27 , int V_181 )
{
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_56 = V_27 -> V_56 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_182 * V_183 ;
char V_184 [ 64 ] ;
int V_29 = 0 , V_39 = 0 , V_41 = 0 ;
if ( V_27 -> V_23 -> V_69 || V_27 -> V_23 -> V_70 ) {
if ( V_55 -> V_30 -> V_39 . V_48 )
V_39 = 1 ;
if ( V_55 -> V_30 -> V_41 . V_48 )
V_41 = 1 ;
} else {
if ( V_56 -> V_30 -> V_39 . V_48 &&
V_55 -> V_30 -> V_39 . V_48 )
V_39 = 1 ;
if ( V_56 -> V_30 -> V_41 . V_48 &&
V_55 -> V_30 -> V_41 . V_48 )
V_41 = 1 ;
}
if ( V_27 -> V_23 -> V_70 ) {
snprintf ( V_184 , sizeof( V_184 ) , L_92 ,
V_27 -> V_23 -> V_83 ) ;
V_29 = F_95 ( V_27 -> V_91 -> V_185 , V_184 , V_181 ,
V_39 , V_41 , & V_183 ) ;
} else {
if ( V_27 -> V_23 -> V_69 )
snprintf ( V_184 , sizeof( V_184 ) , L_93 ,
V_27 -> V_23 -> V_83 ) ;
else
snprintf ( V_184 , sizeof( V_184 ) , L_94 ,
V_27 -> V_23 -> V_83 , V_56 -> V_24 , V_181 ) ;
V_29 = F_96 ( V_27 -> V_91 -> V_185 , V_184 , V_181 , V_39 ,
V_41 , & V_183 ) ;
}
if ( V_29 < 0 ) {
F_9 ( V_27 -> V_91 -> V_22 , L_95 ,
V_27 -> V_23 -> V_24 ) ;
return V_29 ;
}
F_4 ( V_27 -> V_91 -> V_22 , L_96 , V_181 , V_184 ) ;
F_97 ( & V_27 -> V_82 , F_25 ) ;
V_27 -> V_183 = V_183 ;
V_183 -> V_28 = V_27 ;
if ( V_27 -> V_23 -> V_70 ) {
if ( V_39 )
V_183 -> V_186 [ V_38 ] . V_2 -> V_28 = V_27 ;
if ( V_41 )
V_183 -> V_186 [ V_89 ] . V_2 -> V_28 = V_27 ;
goto V_64;
}
if ( V_27 -> V_23 -> V_69 ) {
V_27 -> V_62 . V_65 = F_92 ;
V_27 -> V_62 . V_95 = F_75 ;
V_27 -> V_62 . V_90 = F_82 ;
V_27 -> V_62 . V_100 = F_80 ;
V_27 -> V_62 . V_98 = F_72 ;
V_27 -> V_62 . V_79 = F_93 ;
V_27 -> V_62 . V_104 = F_38 ;
V_27 -> V_62 . V_170 = F_84 ;
} else {
V_27 -> V_62 . V_65 = F_16 ;
V_27 -> V_62 . V_95 = F_33 ;
V_27 -> V_62 . V_90 = F_31 ;
V_27 -> V_62 . V_100 = F_36 ;
V_27 -> V_62 . V_98 = F_35 ;
V_27 -> V_62 . V_79 = F_27 ;
V_27 -> V_62 . V_104 = F_38 ;
V_27 -> V_62 . V_170 = F_84 ;
}
if ( V_54 -> V_30 -> V_62 ) {
V_27 -> V_62 . V_187 = V_54 -> V_30 -> V_62 -> V_187 ;
V_27 -> V_62 . V_188 = V_54 -> V_30 -> V_62 -> V_188 ;
V_27 -> V_62 . V_189 = V_54 -> V_30 -> V_62 -> V_189 ;
V_27 -> V_62 . V_190 = V_54 -> V_30 -> V_62 -> V_190 ;
V_27 -> V_62 . V_191 = V_54 -> V_30 -> V_62 -> V_191 ;
}
if ( V_39 )
F_98 ( V_183 , V_38 , & V_27 -> V_62 ) ;
if ( V_41 )
F_98 ( V_183 , V_89 , & V_27 -> V_62 ) ;
if ( V_54 -> V_30 -> V_192 ) {
V_29 = V_54 -> V_30 -> V_192 ( V_27 ) ;
if ( V_29 < 0 ) {
F_9 ( V_54 -> V_22 ,
L_97 ,
V_29 ) ;
return V_29 ;
}
}
V_183 -> V_193 = V_54 -> V_30 -> V_194 ;
V_64:
F_99 ( V_27 -> V_91 -> V_22 , L_98 , V_56 -> V_24 ,
V_55 -> V_24 ) ;
return V_29 ;
}
int F_100 ( struct V_15 * V_16 , int V_37 )
{
if ( V_16 -> V_20 [ V_37 ] . V_133 == V_147 )
return 1 ;
return 0 ;
}
int F_64 ( struct V_15 * V_16 ,
struct V_15 * V_21 , int V_37 )
{
if ( ( V_16 -> V_20 [ V_37 ] . V_133 == V_147 ) ||
( ( V_16 -> V_20 [ V_37 ] . V_133 == V_134 ) &&
V_21 -> V_20 [ V_37 ] . V_133 ) )
return 1 ;
return 0 ;
}
struct V_1 *
F_45 ( struct V_15 * V_21 , int V_37 )
{
return V_21 -> V_183 -> V_186 [ V_37 ] . V_2 ;
}
enum V_195
F_101 ( struct V_15 * V_21 , int V_37 )
{
return V_21 -> V_20 [ V_37 ] . V_107 ;
}
void F_102 ( struct V_15 * V_21 ,
int V_37 , enum V_195 V_107 )
{
V_21 -> V_20 [ V_37 ] . V_107 = V_107 ;
}
int F_71 ( struct V_15 * V_16 ,
struct V_15 * V_21 , int V_37 )
{
struct V_19 * V_20 ;
int V_107 ;
F_3 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_20 -> V_16 == V_16 )
continue;
V_107 = V_20 -> V_16 -> V_20 [ V_37 ] . V_107 ;
if ( V_107 == V_158 ||
V_107 == V_152 ||
V_107 == V_160 )
return 0 ;
}
return 1 ;
}
int F_74 ( struct V_15 * V_16 ,
struct V_15 * V_21 , int V_37 )
{
struct V_19 * V_20 ;
int V_107 ;
F_3 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_20 -> V_16 == V_16 )
continue;
V_107 = V_20 -> V_16 -> V_20 [ V_37 ] . V_107 ;
if ( V_107 == V_158 ||
V_107 == V_152 ||
V_107 == V_160 ||
V_107 == V_151 )
return 0 ;
}
return 1 ;
}
int F_103 ( struct V_1 * V_2 ,
int V_99 , struct V_53 * V_54 )
{
if ( V_54 -> V_30 -> V_62 -> V_100 )
return V_54 -> V_30 -> V_62 -> V_100 ( V_2 , V_99 ) ;
return 0 ;
}
static char * F_104 ( enum V_195 V_107 )
{
switch ( V_107 ) {
case V_145 :
return L_99 ;
case V_141 :
return L_100 ;
case V_150 :
return L_101 ;
case V_151 :
return L_102 ;
case V_158 :
return L_103 ;
case V_153 :
return L_104 ;
case V_160 :
return L_105 ;
case V_152 :
return L_106 ;
case V_149 :
return L_107 ;
case V_142 :
return L_108 ;
}
return L_109 ;
}
static T_3 F_105 ( struct V_15 * V_16 ,
int V_37 , char * V_196 , T_4 V_197 )
{
struct V_93 * V_94 = & V_16 -> V_20 [ V_37 ] . V_95 ;
struct V_19 * V_20 ;
T_3 V_102 = 0 ;
V_102 += snprintf ( V_196 + V_102 , V_197 - V_102 ,
L_110 , V_16 -> V_23 -> V_24 ,
V_37 ? L_111 : L_112 ) ;
V_102 += snprintf ( V_196 + V_102 , V_197 - V_102 , L_113 ,
F_104 ( V_16 -> V_20 [ V_37 ] . V_107 ) ) ;
if ( ( V_16 -> V_20 [ V_37 ] . V_107 >= V_150 ) &&
( V_16 -> V_20 [ V_37 ] . V_107 <= V_153 ) )
V_102 += snprintf ( V_196 + V_102 , V_197 - V_102 ,
L_114
L_115 ,
F_106 ( F_77 ( V_94 ) ) ,
F_76 ( V_94 ) ,
F_34 ( V_94 ) ) ;
V_102 += snprintf ( V_196 + V_102 , V_197 - V_102 , L_116 ) ;
if ( F_83 ( & V_16 -> V_20 [ V_37 ] . V_110 ) ) {
V_102 += snprintf ( V_196 + V_102 , V_197 - V_102 ,
L_117 ) ;
goto V_64;
}
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
V_94 = & V_20 -> V_95 ;
V_102 += snprintf ( V_196 + V_102 , V_197 - V_102 ,
L_118 , V_21 -> V_23 -> V_24 ) ;
V_102 += snprintf ( V_196 + V_102 , V_197 - V_102 ,
L_119 ,
F_104 ( V_21 -> V_20 [ V_37 ] . V_107 ) ) ;
if ( ( V_21 -> V_20 [ V_37 ] . V_107 >= V_150 ) &&
( V_21 -> V_20 [ V_37 ] . V_107 <= V_153 ) )
V_102 += snprintf ( V_196 + V_102 , V_197 - V_102 ,
L_120
L_115 ,
F_106 ( F_77 ( V_94 ) ) ,
F_76 ( V_94 ) ,
F_34 ( V_94 ) ) ;
}
V_64:
return V_102 ;
}
static T_3 F_107 ( struct V_198 * V_198 , char T_5 * V_199 ,
T_4 V_143 , T_6 * V_200 )
{
struct V_15 * V_16 = V_198 -> V_28 ;
T_3 V_201 = V_202 , V_102 = 0 , V_29 = 0 ;
char * V_196 ;
V_196 = F_108 ( V_201 , V_105 ) ;
if ( ! V_196 )
return - V_106 ;
if ( V_16 -> V_55 -> V_30 -> V_39 . V_48 )
V_102 += F_105 ( V_16 , V_38 ,
V_196 + V_102 , V_201 - V_102 ) ;
if ( V_16 -> V_55 -> V_30 -> V_41 . V_48 )
V_102 += F_105 ( V_16 , V_89 ,
V_196 + V_102 , V_201 - V_102 ) ;
V_29 = F_109 ( V_199 , V_143 , V_200 , V_196 , V_102 ) ;
F_50 ( V_196 ) ;
return V_29 ;
}
int F_110 ( struct V_15 * V_27 )
{
if ( ! V_27 -> V_23 )
return 0 ;
V_27 -> V_114 = F_111 ( V_27 -> V_23 -> V_24 ,
V_27 -> V_91 -> V_203 ) ;
if ( ! V_27 -> V_114 ) {
F_4 ( V_27 -> V_22 ,
L_121 ,
V_27 -> V_23 -> V_24 ) ;
return - V_71 ;
}
V_27 -> V_204 = F_112 ( L_122 , 0444 ,
V_27 -> V_114 ,
V_27 , & V_205 ) ;
return 0 ;
}
