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
static void F_13 ( struct V_5 * V_6 ,
struct V_43 * V_44 ,
struct V_43 * V_45 )
{
struct V_3 * V_4 = & V_6 -> V_4 ;
V_4 -> V_46 = F_14 ( V_44 -> V_46 ,
V_45 -> V_46 ) ;
V_4 -> V_47 = F_15 ( V_44 -> V_47 ,
V_45 -> V_47 ) ;
V_4 -> V_8 = V_44 -> V_8 & V_45 -> V_8 ;
V_4 -> V_48 = V_44 -> V_48 & V_45 -> V_48 ;
if ( V_44 -> V_48
& ( V_49 | V_50 ) )
V_4 -> V_48 |= V_45 -> V_48 ;
if ( V_45 -> V_48
& ( V_49 | V_50 ) )
V_4 -> V_48 |= V_44 -> V_48 ;
F_16 ( V_6 ) ;
V_4 -> V_51 = F_14 ( V_4 -> V_51 , V_45 -> V_51 ) ;
V_4 -> V_51 = F_14 ( V_4 -> V_51 , V_44 -> V_51 ) ;
V_4 -> V_52 = F_17 ( V_4 -> V_52 , V_45 -> V_52 ) ;
V_4 -> V_52 = F_17 ( V_4 -> V_52 , V_44 -> V_52 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
struct V_57 * V_58 = V_55 -> V_30 ;
struct V_57 * V_59 = V_56 -> V_30 ;
int V_29 = 0 ;
F_19 ( V_55 -> V_22 ) ;
F_19 ( V_56 -> V_22 ) ;
F_20 ( V_55 -> V_22 ) ;
F_20 ( V_56 -> V_22 ) ;
F_20 ( V_54 -> V_22 ) ;
F_21 ( & V_27 -> V_60 , V_27 -> V_61 ) ;
if ( V_55 -> V_30 -> V_62 && V_55 -> V_30 -> V_62 -> V_63 ) {
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
if ( V_56 -> V_30 -> V_62 && V_56 -> V_30 -> V_62 -> V_63 ) {
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
F_22 ( L_10 ,
V_27 -> V_23 -> V_24 , V_29 ) ;
goto V_68;
}
}
if ( V_27 -> V_23 -> V_69 || V_27 -> V_23 -> V_70 )
goto V_69;
if ( V_2 -> V_37 == V_38 ) {
F_13 ( V_6 , & V_59 -> V_39 ,
& V_58 -> V_39 ) ;
} else {
F_13 ( V_6 , & V_59 -> V_41 ,
& V_58 -> V_41 ) ;
}
V_29 = - V_71 ;
if ( ! V_6 -> V_4 . V_48 ) {
F_23 ( V_72 L_11 ,
V_56 -> V_24 , V_55 -> V_24 ) ;
goto V_73;
}
if ( ! V_6 -> V_4 . V_8 ) {
F_23 ( V_72 L_12 ,
V_56 -> V_24 , V_55 -> V_24 ) ;
goto V_73;
}
if ( ! V_6 -> V_4 . V_46 || ! V_6 -> V_4 . V_47 ||
V_6 -> V_4 . V_46 > V_6 -> V_4 . V_47 ) {
F_23 ( V_72 L_13 ,
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
F_24 ( L_14 ,
V_56 -> V_24 , V_55 -> V_24 ) ;
F_24 ( L_15 , V_6 -> V_4 . V_48 ) ;
F_24 ( L_16 , V_6 -> V_4 . V_46 ,
V_6 -> V_4 . V_47 ) ;
F_24 ( L_17 , V_6 -> V_4 . V_51 ,
V_6 -> V_4 . V_52 ) ;
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
F_25 ( & V_27 -> V_60 ) ;
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
F_25 ( & V_27 -> V_60 ) ;
F_26 ( V_54 -> V_22 ) ;
F_26 ( V_56 -> V_22 ) ;
F_26 ( V_55 -> V_22 ) ;
if ( ! V_56 -> V_74 )
F_27 ( V_56 -> V_22 ) ;
if ( ! V_55 -> V_74 )
F_27 ( V_55 -> V_22 ) ;
return V_29 ;
}
static void F_28 ( struct V_80 * V_81 )
{
struct V_15 * V_27 =
F_29 ( V_81 , struct V_15 , V_82 . V_81 ) ;
struct V_25 * V_56 = V_27 -> V_56 ;
F_21 ( & V_27 -> V_60 , V_27 -> V_61 ) ;
F_4 ( V_27 -> V_22 , L_18 ,
V_56 -> V_30 -> V_39 . V_83 ,
V_56 -> V_75 ? L_19 : L_20 ,
V_27 -> V_84 ? L_21 : L_22 ) ;
if ( V_27 -> V_84 == 1 ) {
V_27 -> V_84 = 0 ;
F_5 ( V_27 , V_38 ,
V_85 ) ;
}
F_25 ( & V_27 -> V_60 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
struct V_86 * V_77 = V_27 -> V_77 ;
F_21 ( & V_27 -> V_60 , V_27 -> V_61 ) ;
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
F_31 ( V_56 , 1 , V_2 -> V_37 ) ;
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
F_32 ( V_89 ,
& V_27 -> V_82 ,
F_33 ( V_27 -> V_87 ) ) ;
}
} else {
F_5 ( V_27 , V_90 ,
V_85 ) ;
}
F_25 ( & V_27 -> V_60 ) ;
F_26 ( V_54 -> V_22 ) ;
F_26 ( V_56 -> V_22 ) ;
F_26 ( V_55 -> V_22 ) ;
if ( ! V_56 -> V_74 )
F_27 ( V_56 -> V_22 ) ;
if ( ! V_55 -> V_74 )
F_27 ( V_55 -> V_22 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
int V_29 = 0 ;
F_21 ( & V_27 -> V_60 , V_27 -> V_61 ) ;
if ( V_27 -> V_23 -> V_62 && V_27 -> V_23 -> V_62 -> V_91 ) {
V_29 = V_27 -> V_23 -> V_62 -> V_91 ( V_2 ) ;
if ( V_29 < 0 ) {
F_9 ( V_27 -> V_92 -> V_22 , L_23
L_24 , V_29 ) ;
goto V_64;
}
}
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_91 ) {
V_29 = V_54 -> V_30 -> V_62 -> V_91 ( V_2 ) ;
if ( V_29 < 0 ) {
F_9 ( V_54 -> V_22 , L_25
L_24 , V_29 ) ;
goto V_64;
}
}
if ( V_56 -> V_30 -> V_62 && V_56 -> V_30 -> V_62 -> V_91 ) {
V_29 = V_56 -> V_30 -> V_62 -> V_91 ( V_2 , V_56 ) ;
if ( V_29 < 0 ) {
F_9 ( V_56 -> V_22 , L_26 ,
V_29 ) ;
goto V_64;
}
}
if ( V_55 -> V_30 -> V_62 && V_55 -> V_30 -> V_62 -> V_91 ) {
V_29 = V_55 -> V_30 -> V_62 -> V_91 ( V_2 , V_55 ) ;
if ( V_29 < 0 ) {
F_9 ( V_55 -> V_22 , L_26 ,
V_29 ) ;
goto V_64;
}
}
if ( V_2 -> V_37 == V_38 &&
V_27 -> V_84 ) {
V_27 -> V_84 = 0 ;
F_35 ( & V_27 -> V_82 ) ;
}
F_5 ( V_27 , V_2 -> V_37 ,
V_93 ) ;
F_31 ( V_56 , 0 , V_2 -> V_37 ) ;
V_64:
F_25 ( & V_27 -> V_60 ) ;
return V_29 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
int V_29 = 0 ;
F_21 ( & V_27 -> V_60 , V_27 -> V_61 ) ;
if ( V_27 -> V_23 -> V_62 && V_27 -> V_23 -> V_62 -> V_96 ) {
V_29 = V_27 -> V_23 -> V_62 -> V_96 ( V_2 , V_95 ) ;
if ( V_29 < 0 ) {
F_9 ( V_27 -> V_92 -> V_22 , L_27
L_28 , V_29 ) ;
goto V_64;
}
}
if ( V_56 -> V_30 -> V_62 && V_56 -> V_30 -> V_62 -> V_96 ) {
V_29 = V_56 -> V_30 -> V_62 -> V_96 ( V_2 , V_95 , V_56 ) ;
if ( V_29 < 0 ) {
F_9 ( V_56 -> V_22 , L_29
L_24 , V_56 -> V_24 , V_29 ) ;
goto V_97;
}
}
if ( V_55 -> V_30 -> V_62 && V_55 -> V_30 -> V_62 -> V_96 ) {
V_29 = V_55 -> V_30 -> V_62 -> V_96 ( V_2 , V_95 , V_55 ) ;
if ( V_29 < 0 ) {
F_9 ( V_55 -> V_22 , L_30 ,
V_55 -> V_24 , V_29 ) ;
goto V_98;
}
}
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_96 ) {
V_29 = V_54 -> V_30 -> V_62 -> V_96 ( V_2 , V_95 ) ;
if ( V_29 < 0 ) {
F_9 ( V_54 -> V_22 , L_30 ,
V_54 -> V_24 , V_29 ) ;
goto V_66;
}
}
V_55 -> V_32 = F_37 ( V_95 ) ;
V_56 -> V_32 = F_37 ( V_95 ) ;
V_64:
F_25 ( & V_27 -> V_60 ) ;
return V_29 ;
V_66:
if ( V_55 -> V_30 -> V_62 && V_55 -> V_30 -> V_62 -> V_99 )
V_55 -> V_30 -> V_62 -> V_99 ( V_2 , V_55 ) ;
V_98:
if ( V_56 -> V_30 -> V_62 && V_56 -> V_30 -> V_62 -> V_99 )
V_56 -> V_30 -> V_62 -> V_99 ( V_2 , V_56 ) ;
V_97:
if ( V_27 -> V_23 -> V_62 && V_27 -> V_23 -> V_62 -> V_99 )
V_27 -> V_23 -> V_62 -> V_99 ( V_2 ) ;
F_25 ( & V_27 -> V_60 ) ;
return V_29 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
bool V_39 = V_2 -> V_37 == V_38 ;
F_21 ( & V_27 -> V_60 , V_27 -> V_61 ) ;
if ( ( V_39 && V_56 -> V_75 == 1 ) ||
( ! V_39 && V_56 -> V_76 == 1 ) )
F_31 ( V_56 , 1 , V_2 -> V_37 ) ;
if ( V_27 -> V_23 -> V_62 && V_27 -> V_23 -> V_62 -> V_99 )
V_27 -> V_23 -> V_62 -> V_99 ( V_2 ) ;
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_99 )
V_54 -> V_30 -> V_62 -> V_99 ( V_2 ) ;
if ( V_56 -> V_30 -> V_62 && V_56 -> V_30 -> V_62 -> V_99 )
V_56 -> V_30 -> V_62 -> V_99 ( V_2 , V_56 ) ;
if ( V_55 -> V_30 -> V_62 && V_55 -> V_30 -> V_62 -> V_99 )
V_55 -> V_30 -> V_62 -> V_99 ( V_2 , V_55 ) ;
F_25 ( & V_27 -> V_60 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , int V_100 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
int V_29 ;
if ( V_56 -> V_30 -> V_62 && V_56 -> V_30 -> V_62 -> V_101 ) {
V_29 = V_56 -> V_30 -> V_62 -> V_101 ( V_2 , V_100 , V_56 ) ;
if ( V_29 < 0 )
return V_29 ;
}
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_101 ) {
V_29 = V_54 -> V_30 -> V_62 -> V_101 ( V_2 , V_100 ) ;
if ( V_29 < 0 )
return V_29 ;
}
if ( V_55 -> V_30 -> V_62 && V_55 -> V_30 -> V_62 -> V_101 ) {
V_29 = V_55 -> V_30 -> V_62 -> V_101 ( V_2 , V_100 , V_55 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
int V_100 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
int V_29 ;
if ( V_56 -> V_30 -> V_62 &&
V_56 -> V_30 -> V_62 -> V_102 ) {
V_29 = V_56 -> V_30 -> V_62 -> V_102 ( V_2 , V_100 , V_56 ) ;
if ( V_29 < 0 )
return V_29 ;
}
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_102 ) {
V_29 = V_54 -> V_30 -> V_102 ( V_2 , V_100 ) ;
if ( V_29 < 0 )
return V_29 ;
}
if ( V_55 -> V_30 -> V_62 && V_55 -> V_30 -> V_62 -> V_102 ) {
V_29 = V_55 -> V_30 -> V_62 -> V_102 ( V_2 , V_100 , V_55 ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static T_1 F_41 ( struct V_1 * V_2 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_25 * V_56 = V_27 -> V_56 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_103 = 0 ;
T_2 V_104 = 0 ;
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_105 )
V_103 = V_54 -> V_30 -> V_62 -> V_105 ( V_2 ) ;
if ( V_55 -> V_30 -> V_62 && V_55 -> V_30 -> V_62 -> V_104 )
V_104 += V_55 -> V_30 -> V_62 -> V_104 ( V_2 , V_55 ) ;
if ( V_56 -> V_30 -> V_62 && V_56 -> V_30 -> V_62 -> V_104 )
V_104 += V_56 -> V_30 -> V_62 -> V_104 ( V_2 , V_56 ) ;
if ( V_54 -> V_30 -> V_104 )
V_104 += V_54 -> V_30 -> V_104 ( V_2 , V_56 ) ;
V_6 -> V_104 = V_104 ;
return V_103 ;
}
static int F_42 ( struct V_15 * V_16 ,
struct V_15 * V_21 , int V_37 )
{
struct V_19 * V_20 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
if ( V_20 -> V_21 == V_21 && V_20 -> V_16 == V_16 )
return 0 ;
}
V_20 = F_43 ( sizeof( struct V_19 ) , V_106 ) ;
if ( ! V_20 )
return - V_107 ;
V_20 -> V_21 = V_21 ;
V_20 -> V_16 = V_16 ;
V_21 -> V_20 [ V_37 ] . V_6 = V_16 -> V_20 [ V_37 ] . V_6 ;
V_20 -> V_108 = V_109 ;
F_44 ( & V_20 -> V_110 , & V_16 -> V_20 [ V_37 ] . V_111 ) ;
F_44 ( & V_20 -> V_112 , & V_21 -> V_20 [ V_37 ] . V_113 ) ;
F_4 ( V_16 -> V_22 , L_31 ,
V_37 ? L_32 : L_33 , V_16 -> V_23 -> V_24 ,
V_37 ? L_34 : L_35 , V_21 -> V_23 -> V_24 ) ;
#ifdef F_45
V_20 -> V_114 = F_46 ( V_21 -> V_23 -> V_24 , 0644 ,
V_16 -> V_115 , & V_20 -> V_108 ) ;
#endif
return 1 ;
}
static void F_47 ( struct V_15 * V_16 ,
struct V_15 * V_21 , int V_37 )
{
struct V_19 * V_20 ;
struct V_1 * V_116 , * V_117 ;
if ( ! V_21 -> V_20 [ V_37 ] . V_118 )
return;
V_117 = F_48 ( V_21 , V_37 ) ;
F_3 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_20 -> V_16 == V_16 )
continue;
F_4 ( V_16 -> V_22 , L_36 ,
V_37 ? L_32 : L_33 ,
V_20 -> V_16 -> V_23 -> V_24 ,
V_37 ? L_34 : L_35 , V_20 -> V_21 -> V_23 -> V_24 ) ;
V_116 = F_48 ( V_20 -> V_16 , V_37 ) ;
V_117 -> V_6 = V_116 -> V_6 ;
break;
}
}
static void F_49 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 , * V_119 ;
F_50 (dpcm, d, &fe->dpcm[stream].be_clients, list_be) {
F_4 ( V_16 -> V_22 , L_37 ,
V_37 ? L_32 : L_33 ,
V_20 -> V_21 -> V_23 -> V_24 ) ;
if ( V_20 -> V_108 != V_120 )
continue;
F_4 ( V_16 -> V_22 , L_38 ,
V_37 ? L_32 : L_33 , V_16 -> V_23 -> V_24 ,
V_37 ? L_34 : L_35 , V_20 -> V_21 -> V_23 -> V_24 ) ;
F_47 ( V_16 , V_20 -> V_21 , V_37 ) ;
#ifdef F_45
F_51 ( V_20 -> V_114 ) ;
#endif
F_52 ( & V_20 -> V_110 ) ;
F_52 ( & V_20 -> V_112 ) ;
F_53 ( V_20 ) ;
}
}
static struct V_15 * F_54 ( struct V_121 * V_92 ,
struct V_122 * V_123 , int V_37 )
{
struct V_15 * V_21 ;
int V_35 ;
if ( V_37 == V_38 ) {
for ( V_35 = 0 ; V_35 < V_92 -> V_124 ; V_35 ++ ) {
V_21 = & V_92 -> V_27 [ V_35 ] ;
if ( ! V_21 -> V_23 -> V_70 )
continue;
if ( V_21 -> V_55 -> V_125 == V_123 ||
V_21 -> V_56 -> V_125 == V_123 )
return V_21 ;
}
} else {
for ( V_35 = 0 ; V_35 < V_92 -> V_124 ; V_35 ++ ) {
V_21 = & V_92 -> V_27 [ V_35 ] ;
if ( ! V_21 -> V_23 -> V_70 )
continue;
if ( V_21 -> V_55 -> V_126 == V_123 ||
V_21 -> V_56 -> V_126 == V_123 )
return V_21 ;
}
}
F_9 ( V_92 -> V_22 , L_39 ,
V_37 ? L_32 : L_33 , V_123 -> V_24 ) ;
return NULL ;
}
static inline struct V_122 *
F_55 ( struct V_15 * V_27 , int V_37 )
{
if ( V_37 == V_38 )
return V_27 -> V_55 -> V_125 ;
else
return V_27 -> V_55 -> V_126 ;
}
static inline struct V_122 *
F_56 ( struct V_15 * V_27 , int V_37 )
{
if ( V_37 == V_38 )
return V_27 -> V_56 -> V_125 ;
else
return V_27 -> V_56 -> V_126 ;
}
static int F_57 ( struct V_127 * V_128 ,
struct V_122 * V_123 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_128 -> V_129 ; V_35 ++ ) {
if ( V_123 == V_128 -> V_130 [ V_35 ] )
return 1 ;
}
return 0 ;
}
static int F_58 ( struct V_15 * V_16 ,
int V_37 , struct V_127 * * V_131 )
{
struct V_25 * V_55 = V_16 -> V_55 ;
struct V_127 * V_128 ;
int V_132 ;
V_128 = F_43 ( sizeof( struct V_127 ) +
sizeof( struct V_122 * ) , V_106 ) ;
if ( V_128 == NULL )
return - V_107 ;
V_132 = F_59 ( V_55 , V_37 , & V_128 ) ;
F_4 ( V_16 -> V_22 , L_40 , V_132 ,
V_37 ? L_32 : L_33 ) ;
* V_131 = V_128 ;
return V_132 ;
}
static inline void F_60 ( struct V_127 * * V_128 )
{
F_53 ( * V_128 ) ;
}
static int F_61 ( struct V_15 * V_16 , int V_37 ,
struct V_127 * * V_131 )
{
struct V_19 * V_20 ;
struct V_127 * V_128 = * V_131 ;
struct V_122 * V_123 ;
int V_133 = 0 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
V_123 = F_55 ( V_20 -> V_21 , V_37 ) ;
if ( V_123 && F_57 ( V_128 , V_123 ) )
continue;
V_123 = F_56 ( V_20 -> V_21 , V_37 ) ;
if ( V_123 && F_57 ( V_128 , V_123 ) )
continue;
F_4 ( V_16 -> V_22 , L_41 ,
V_37 ? L_32 : L_33 ,
V_20 -> V_21 -> V_23 -> V_24 , V_16 -> V_23 -> V_24 ) ;
V_20 -> V_108 = V_120 ;
V_20 -> V_21 -> V_20 [ V_37 ] . V_134 = V_135 ;
V_133 ++ ;
}
F_4 ( V_16 -> V_22 , L_42 , V_133 ) ;
return V_133 ;
}
static int F_62 ( struct V_15 * V_16 , int V_37 ,
struct V_127 * * V_131 )
{
struct V_121 * V_92 = V_16 -> V_92 ;
struct V_127 * V_128 = * V_131 ;
struct V_15 * V_21 ;
int V_35 , V_136 = 0 , V_137 ;
for ( V_35 = 0 ; V_35 < V_128 -> V_129 ; V_35 ++ ) {
switch ( V_128 -> V_130 [ V_35 ] -> V_138 ) {
case V_139 :
case V_140 :
break;
default:
continue;
}
V_21 = F_54 ( V_92 , V_128 -> V_130 [ V_35 ] , V_37 ) ;
if ( ! V_21 ) {
F_9 ( V_16 -> V_22 , L_43 ,
V_128 -> V_130 [ V_35 ] -> V_24 ) ;
continue;
}
if ( ! V_21 -> V_23 -> V_70 )
continue;
if ( ! V_16 -> V_20 [ V_37 ] . V_6 )
continue;
V_137 = F_42 ( V_16 , V_21 , V_37 ) ;
if ( V_137 < 0 ) {
F_9 ( V_16 -> V_22 , L_44 ,
V_128 -> V_130 [ V_35 ] -> V_24 ) ;
break;
} else if ( V_137 == 0 )
continue;
V_21 -> V_20 [ V_37 ] . V_134 = V_135 ;
V_136 ++ ;
}
F_4 ( V_16 -> V_22 , L_45 , V_136 ) ;
return V_136 ;
}
static int F_63 ( struct V_15 * V_16 ,
int V_37 , struct V_127 * * V_128 , int V_136 )
{
if ( V_136 )
return F_62 ( V_16 , V_37 , V_128 ) ;
else
return F_61 ( V_16 , V_37 , V_128 ) ;
}
static void F_64 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_20 -> V_21 -> V_20 [ V_37 ] . V_134 =
V_141 ;
}
static void F_65 ( struct V_15 * V_16 ,
int V_37 )
{
struct V_19 * V_20 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_117 =
F_48 ( V_21 , V_37 ) ;
if ( V_21 -> V_20 [ V_37 ] . V_118 == 0 )
F_9 ( V_21 -> V_22 , L_46 ,
V_37 ? L_32 : L_33 ,
V_21 -> V_20 [ V_37 ] . V_108 ) ;
if ( -- V_21 -> V_20 [ V_37 ] . V_118 != 0 )
continue;
if ( V_21 -> V_20 [ V_37 ] . V_108 != V_142 )
continue;
F_30 ( V_117 ) ;
V_117 -> V_6 = NULL ;
V_21 -> V_20 [ V_37 ] . V_108 = V_143 ;
}
}
static int F_66 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 ;
int V_137 , V_144 = 0 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_117 =
F_48 ( V_21 , V_37 ) ;
if ( ! V_117 ) {
F_9 ( V_21 -> V_22 , L_47 ,
V_37 ? L_32 : L_33 ) ;
continue;
}
if ( ! F_67 ( V_16 , V_21 , V_37 ) )
continue;
if ( V_21 -> V_20 [ V_37 ] . V_118 == V_145 )
F_9 ( V_21 -> V_22 , L_48 ,
V_37 ? L_32 : L_33 ,
V_21 -> V_20 [ V_37 ] . V_108 ) ;
if ( V_21 -> V_20 [ V_37 ] . V_118 ++ != 0 )
continue;
if ( ( V_21 -> V_20 [ V_37 ] . V_108 != V_146 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 != V_143 ) )
continue;
F_4 ( V_21 -> V_22 , L_49 ,
V_37 ? L_32 : L_33 , V_21 -> V_23 -> V_24 ) ;
V_117 -> V_6 = V_21 -> V_20 [ V_37 ] . V_6 ;
V_137 = F_18 ( V_117 ) ;
if ( V_137 < 0 ) {
F_9 ( V_21 -> V_22 , L_50 , V_137 ) ;
V_21 -> V_20 [ V_37 ] . V_118 -- ;
if ( V_21 -> V_20 [ V_37 ] . V_118 < 0 )
F_9 ( V_21 -> V_22 , L_51 ,
V_37 ? L_32 : L_33 ,
V_21 -> V_20 [ V_37 ] . V_108 ) ;
V_21 -> V_20 [ V_37 ] . V_108 = V_143 ;
goto V_147;
}
V_21 -> V_20 [ V_37 ] . V_108 = V_142 ;
V_144 ++ ;
}
return V_144 ;
V_147:
F_68 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_117 =
F_48 ( V_21 , V_37 ) ;
if ( ! F_67 ( V_16 , V_21 , V_37 ) )
continue;
if ( V_21 -> V_20 [ V_37 ] . V_118 == 0 )
F_9 ( V_21 -> V_22 , L_52 ,
V_37 ? L_32 : L_33 ,
V_21 -> V_20 [ V_37 ] . V_108 ) ;
if ( -- V_21 -> V_20 [ V_37 ] . V_118 != 0 )
continue;
if ( V_21 -> V_20 [ V_37 ] . V_108 != V_142 )
continue;
F_30 ( V_117 ) ;
V_117 -> V_6 = NULL ;
V_21 -> V_20 [ V_37 ] . V_108 = V_143 ;
}
return V_137 ;
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_57 * V_58 = V_55 -> V_30 ;
if ( V_2 -> V_37 == V_38 ) {
V_6 -> V_4 . V_51 = V_58 -> V_39 . V_51 ;
V_6 -> V_4 . V_52 = V_58 -> V_39 . V_52 ;
V_6 -> V_4 . V_46 = V_58 -> V_39 . V_46 ;
V_6 -> V_4 . V_47 = V_58 -> V_39 . V_47 ;
V_6 -> V_4 . V_8 &= V_58 -> V_39 . V_8 ;
V_6 -> V_4 . V_48 = V_58 -> V_39 . V_48 ;
} else {
V_6 -> V_4 . V_51 = V_58 -> V_41 . V_51 ;
V_6 -> V_4 . V_52 = V_58 -> V_41 . V_52 ;
V_6 -> V_4 . V_46 = V_58 -> V_41 . V_46 ;
V_6 -> V_4 . V_47 = V_58 -> V_41 . V_47 ;
V_6 -> V_4 . V_8 &= V_58 -> V_41 . V_8 ;
V_6 -> V_4 . V_48 = V_58 -> V_41 . V_48 ;
}
}
static int F_70 ( struct V_1 * V_116 )
{
struct V_15 * V_16 = V_116 -> V_28 ;
struct V_5 * V_6 = V_116 -> V_6 ;
int V_37 = V_116 -> V_37 , V_29 = 0 ;
V_16 -> V_20 [ V_37 ] . V_134 = V_148 ;
V_29 = F_66 ( V_16 , V_116 -> V_37 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_53 , V_29 ) ;
goto V_149;
}
F_4 ( V_16 -> V_22 , L_54 , V_16 -> V_23 -> V_24 ) ;
V_29 = F_18 ( V_116 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_55 , V_29 ) ;
goto V_147;
}
V_16 -> V_20 [ V_37 ] . V_108 = V_142 ;
F_69 ( V_116 ) ;
F_16 ( V_6 ) ;
V_16 -> V_20 [ V_37 ] . V_134 = V_141 ;
return 0 ;
V_147:
F_65 ( V_16 , V_116 -> V_37 ) ;
V_149:
V_16 -> V_20 [ V_37 ] . V_134 = V_141 ;
return V_29 ;
}
static int F_71 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_117 =
F_48 ( V_21 , V_37 ) ;
if ( ! F_67 ( V_16 , V_21 , V_37 ) )
continue;
if ( V_21 -> V_20 [ V_37 ] . V_118 == 0 )
F_9 ( V_21 -> V_22 , L_46 ,
V_37 ? L_32 : L_33 ,
V_21 -> V_20 [ V_37 ] . V_108 ) ;
if ( -- V_21 -> V_20 [ V_37 ] . V_118 != 0 )
continue;
if ( ( V_21 -> V_20 [ V_37 ] . V_108 != V_150 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 != V_142 ) )
continue;
F_4 ( V_21 -> V_22 , L_56 ,
V_20 -> V_16 -> V_23 -> V_24 ) ;
F_30 ( V_117 ) ;
V_117 -> V_6 = NULL ;
V_21 -> V_20 [ V_37 ] . V_108 = V_143 ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_37 = V_2 -> V_37 ;
V_16 -> V_20 [ V_37 ] . V_134 = V_148 ;
F_71 ( V_16 , V_2 -> V_37 ) ;
F_4 ( V_16 -> V_22 , L_57 , V_16 -> V_23 -> V_24 ) ;
F_30 ( V_2 ) ;
F_2 ( V_16 , V_37 , V_85 ) ;
V_16 -> V_20 [ V_37 ] . V_108 = V_143 ;
V_16 -> V_20 [ V_37 ] . V_134 = V_141 ;
return 0 ;
}
static int F_73 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_117 =
F_48 ( V_21 , V_37 ) ;
if ( ! F_67 ( V_16 , V_21 , V_37 ) )
continue;
if ( ! F_74 ( V_16 , V_21 , V_37 ) )
continue;
if ( ( V_21 -> V_20 [ V_37 ] . V_108 != V_151 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 != V_152 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 != V_150 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 != V_153 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 != V_154 ) )
continue;
F_4 ( V_21 -> V_22 , L_58 ,
V_20 -> V_16 -> V_23 -> V_24 ) ;
F_38 ( V_117 ) ;
V_21 -> V_20 [ V_37 ] . V_108 = V_150 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_137 , V_37 = V_2 -> V_37 ;
F_21 ( & V_16 -> V_92 -> V_155 , V_156 ) ;
V_16 -> V_20 [ V_37 ] . V_134 = V_148 ;
F_4 ( V_16 -> V_22 , L_59 , V_16 -> V_23 -> V_24 ) ;
V_137 = F_38 ( V_2 ) ;
if ( V_137 < 0 )
F_9 ( V_16 -> V_22 , L_60 ,
V_16 -> V_23 -> V_24 ) ;
V_137 = F_73 ( V_16 , V_37 ) ;
V_16 -> V_20 [ V_37 ] . V_108 = V_150 ;
V_16 -> V_20 [ V_37 ] . V_134 = V_141 ;
F_25 ( & V_16 -> V_92 -> V_155 ) ;
return 0 ;
}
static int F_76 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 ;
int V_29 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_117 =
F_48 ( V_21 , V_37 ) ;
if ( ! F_67 ( V_16 , V_21 , V_37 ) )
continue;
if ( ! F_77 ( V_16 , V_21 , V_37 ) )
continue;
if ( ( V_21 -> V_20 [ V_37 ] . V_108 != V_142 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 != V_151 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 != V_150 ) )
continue;
F_4 ( V_21 -> V_22 , L_61 ,
V_20 -> V_16 -> V_23 -> V_24 ) ;
memcpy ( & V_20 -> V_96 , & V_16 -> V_20 [ V_37 ] . V_96 ,
sizeof( struct V_94 ) ) ;
if ( V_21 -> V_23 -> V_157 ) {
V_29 = V_21 -> V_23 -> V_157 ( V_21 ,
& V_20 -> V_96 ) ;
if ( V_29 < 0 ) {
F_9 ( V_21 -> V_22 ,
L_62 ,
V_29 ) ;
goto V_147;
}
}
V_29 = F_36 ( V_117 , & V_20 -> V_96 ) ;
if ( V_29 < 0 ) {
F_9 ( V_20 -> V_21 -> V_22 ,
L_63 , V_29 ) ;
goto V_147;
}
V_21 -> V_20 [ V_37 ] . V_108 = V_151 ;
}
return 0 ;
V_147:
F_68 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_117 =
F_48 ( V_21 , V_37 ) ;
if ( ! F_67 ( V_16 , V_21 , V_37 ) )
continue;
if ( ! F_74 ( V_16 , V_21 , V_37 ) )
continue;
if ( ( V_21 -> V_20 [ V_37 ] . V_108 != V_142 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 != V_151 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 != V_150 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 != V_154 ) )
continue;
F_38 ( V_117 ) ;
}
return V_29 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_29 , V_37 = V_2 -> V_37 ;
F_21 ( & V_16 -> V_92 -> V_155 , V_156 ) ;
V_16 -> V_20 [ V_37 ] . V_134 = V_148 ;
memcpy ( & V_16 -> V_20 [ V_2 -> V_37 ] . V_96 , V_95 ,
sizeof( struct V_94 ) ) ;
V_29 = F_76 ( V_16 , V_2 -> V_37 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_63 , V_29 ) ;
goto V_64;
}
F_4 ( V_16 -> V_22 , L_64 ,
V_16 -> V_23 -> V_24 , F_37 ( V_95 ) ,
F_79 ( V_95 ) , F_80 ( V_95 ) ) ;
V_29 = F_36 ( V_2 , V_95 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_65 , V_29 ) ;
F_73 ( V_16 , V_37 ) ;
} else
V_16 -> V_20 [ V_37 ] . V_108 = V_151 ;
V_64:
V_16 -> V_20 [ V_37 ] . V_134 = V_141 ;
F_25 ( & V_16 -> V_92 -> V_155 ) ;
return V_29 ;
}
static int F_81 ( struct V_19 * V_20 ,
struct V_1 * V_2 , int V_100 )
{
int V_29 ;
F_4 ( V_20 -> V_21 -> V_22 , L_66 ,
V_20 -> V_16 -> V_23 -> V_24 , V_100 ) ;
V_29 = F_39 ( V_2 , V_100 ) ;
if ( V_29 < 0 )
F_9 ( V_20 -> V_21 -> V_22 , L_67 , V_29 ) ;
return V_29 ;
}
static int F_82 ( struct V_15 * V_16 , int V_37 ,
int V_100 )
{
struct V_19 * V_20 ;
int V_29 = 0 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_117 =
F_48 ( V_21 , V_37 ) ;
if ( ! F_67 ( V_16 , V_21 , V_37 ) )
continue;
switch ( V_100 ) {
case V_158 :
if ( ( V_21 -> V_20 [ V_37 ] . V_108 != V_152 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 != V_154 ) )
continue;
V_29 = F_81 ( V_20 , V_117 , V_100 ) ;
if ( V_29 )
return V_29 ;
V_21 -> V_20 [ V_37 ] . V_108 = V_159 ;
break;
case V_160 :
if ( ( V_21 -> V_20 [ V_37 ] . V_108 != V_161 ) )
continue;
V_29 = F_81 ( V_20 , V_117 , V_100 ) ;
if ( V_29 )
return V_29 ;
V_21 -> V_20 [ V_37 ] . V_108 = V_159 ;
break;
case V_162 :
if ( ( V_21 -> V_20 [ V_37 ] . V_108 != V_153 ) )
continue;
V_29 = F_81 ( V_20 , V_117 , V_100 ) ;
if ( V_29 )
return V_29 ;
V_21 -> V_20 [ V_37 ] . V_108 = V_159 ;
break;
case V_163 :
if ( V_21 -> V_20 [ V_37 ] . V_108 != V_159 )
continue;
if ( ! F_74 ( V_16 , V_21 , V_37 ) )
continue;
V_29 = F_81 ( V_20 , V_117 , V_100 ) ;
if ( V_29 )
return V_29 ;
V_21 -> V_20 [ V_37 ] . V_108 = V_154 ;
break;
case V_164 :
if ( V_21 -> V_20 [ V_37 ] . V_108 != V_154 )
continue;
if ( ! F_74 ( V_16 , V_21 , V_37 ) )
continue;
V_29 = F_81 ( V_20 , V_117 , V_100 ) ;
if ( V_29 )
return V_29 ;
V_21 -> V_20 [ V_37 ] . V_108 = V_161 ;
break;
case V_165 :
if ( V_21 -> V_20 [ V_37 ] . V_108 != V_159 )
continue;
if ( ! F_74 ( V_16 , V_21 , V_37 ) )
continue;
V_29 = F_81 ( V_20 , V_117 , V_100 ) ;
if ( V_29 )
return V_29 ;
V_21 -> V_20 [ V_37 ] . V_108 = V_153 ;
break;
}
}
return V_29 ;
}
static int F_83 ( struct V_1 * V_2 , int V_100 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_37 = V_2 -> V_37 , V_29 ;
enum V_166 V_101 = V_16 -> V_23 -> V_101 [ V_37 ] ;
V_16 -> V_20 [ V_37 ] . V_134 = V_148 ;
switch ( V_101 ) {
case V_167 :
F_4 ( V_16 -> V_22 , L_68 ,
V_16 -> V_23 -> V_24 , V_100 ) ;
V_29 = F_39 ( V_2 , V_100 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_69 , V_29 ) ;
goto V_64;
}
V_29 = F_82 ( V_16 , V_2 -> V_37 , V_100 ) ;
break;
case V_168 :
V_29 = F_82 ( V_16 , V_2 -> V_37 , V_100 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_69 , V_29 ) ;
goto V_64;
}
F_4 ( V_16 -> V_22 , L_70 ,
V_16 -> V_23 -> V_24 , V_100 ) ;
V_29 = F_39 ( V_2 , V_100 ) ;
break;
case V_169 :
F_4 ( V_16 -> V_22 , L_71 ,
V_16 -> V_23 -> V_24 , V_100 ) ;
V_29 = F_40 ( V_2 , V_100 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_69 , V_29 ) ;
goto V_64;
}
break;
default:
F_9 ( V_16 -> V_22 , L_72 , V_100 ,
V_16 -> V_23 -> V_24 ) ;
V_29 = - V_71 ;
goto V_64;
}
switch ( V_100 ) {
case V_158 :
case V_160 :
case V_162 :
V_16 -> V_20 [ V_37 ] . V_108 = V_159 ;
break;
case V_163 :
case V_164 :
case V_165 :
V_16 -> V_20 [ V_37 ] . V_108 = V_154 ;
break;
}
V_64:
V_16 -> V_20 [ V_37 ] . V_134 = V_141 ;
return V_29 ;
}
static int F_84 ( struct V_15 * V_16 , int V_37 )
{
struct V_19 * V_20 ;
int V_29 = 0 ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_1 * V_117 =
F_48 ( V_21 , V_37 ) ;
if ( ! F_67 ( V_16 , V_21 , V_37 ) )
continue;
if ( ( V_21 -> V_20 [ V_37 ] . V_108 != V_151 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 != V_154 ) )
continue;
F_4 ( V_21 -> V_22 , L_73 ,
V_20 -> V_16 -> V_23 -> V_24 ) ;
V_29 = F_34 ( V_117 ) ;
if ( V_29 < 0 ) {
F_9 ( V_21 -> V_22 , L_74 ,
V_29 ) ;
break;
}
V_21 -> V_20 [ V_37 ] . V_108 = V_152 ;
}
return V_29 ;
}
static int F_85 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_28 ;
int V_37 = V_2 -> V_37 , V_29 = 0 ;
F_21 ( & V_16 -> V_92 -> V_155 , V_156 ) ;
F_4 ( V_16 -> V_22 , L_75 , V_16 -> V_23 -> V_24 ) ;
V_16 -> V_20 [ V_37 ] . V_134 = V_148 ;
if ( F_86 ( & V_16 -> V_20 [ V_37 ] . V_111 ) ) {
F_9 ( V_16 -> V_22 , L_76 ,
V_16 -> V_23 -> V_24 ) ;
V_29 = - V_71 ;
goto V_64;
}
V_29 = F_84 ( V_16 , V_2 -> V_37 ) ;
if ( V_29 < 0 )
goto V_64;
V_29 = F_34 ( V_2 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_77 ,
V_16 -> V_23 -> V_24 ) ;
goto V_64;
}
F_2 ( V_16 , V_37 , V_93 ) ;
V_16 -> V_20 [ V_37 ] . V_108 = V_152 ;
V_64:
V_16 -> V_20 [ V_37 ] . V_134 = V_141 ;
F_25 ( & V_16 -> V_92 -> V_155 ) ;
return V_29 ;
}
static int F_87 ( struct V_1 * V_2 ,
unsigned int V_100 , void * V_170 )
{
struct V_15 * V_27 = V_2 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_54 ;
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_171 )
return V_54 -> V_30 -> V_62 -> V_171 ( V_2 , V_100 , V_170 ) ;
return F_88 ( V_2 , V_100 , V_170 ) ;
}
static int F_89 ( struct V_15 * V_16 , int V_37 )
{
struct V_1 * V_2 =
F_48 ( V_16 , V_37 ) ;
enum V_166 V_101 = V_16 -> V_23 -> V_101 [ V_37 ] ;
int V_137 ;
F_4 ( V_16 -> V_22 , L_78 ,
V_37 ? L_32 : L_33 , V_16 -> V_23 -> V_24 ) ;
if ( V_101 == V_169 ) {
F_4 ( V_16 -> V_22 , L_79 ,
V_16 -> V_23 -> V_24 ) ;
V_137 = F_40 ( V_2 , V_163 ) ;
if ( V_137 < 0 )
F_9 ( V_16 -> V_22 , L_69 , V_137 ) ;
} else {
F_4 ( V_16 -> V_22 , L_80 ,
V_16 -> V_23 -> V_24 ) ;
V_137 = F_82 ( V_16 , V_37 , V_163 ) ;
if ( V_137 < 0 )
F_9 ( V_16 -> V_22 , L_69 , V_137 ) ;
}
V_137 = F_73 ( V_16 , V_37 ) ;
if ( V_137 < 0 )
F_9 ( V_16 -> V_22 , L_81 , V_137 ) ;
V_137 = F_71 ( V_16 , V_37 ) ;
if ( V_137 < 0 )
F_9 ( V_16 -> V_22 , L_82 , V_137 ) ;
F_2 ( V_16 , V_37 , V_172 ) ;
return 0 ;
}
static int F_90 ( struct V_15 * V_16 , int V_37 )
{
struct V_1 * V_2 =
F_48 ( V_16 , V_37 ) ;
struct V_19 * V_20 ;
enum V_166 V_101 = V_16 -> V_23 -> V_101 [ V_37 ] ;
int V_29 ;
F_4 ( V_16 -> V_22 , L_83 ,
V_37 ? L_32 : L_33 , V_16 -> V_23 -> V_24 ) ;
if ( V_16 -> V_20 [ V_37 ] . V_108 == V_150 ||
V_16 -> V_20 [ V_37 ] . V_108 == V_143 )
return - V_71 ;
V_29 = F_66 ( V_16 , V_37 ) ;
if ( V_29 < 0 )
goto V_173;
if ( V_16 -> V_20 [ V_37 ] . V_108 == V_142 )
return 0 ;
V_29 = F_76 ( V_16 , V_37 ) ;
if ( V_29 < 0 )
goto V_79;
if ( V_16 -> V_20 [ V_37 ] . V_108 == V_151 )
return 0 ;
V_29 = F_84 ( V_16 , V_37 ) ;
if ( V_29 < 0 )
goto V_99;
F_2 ( V_16 , V_37 , V_172 ) ;
if ( V_16 -> V_20 [ V_37 ] . V_108 == V_152 ||
V_16 -> V_20 [ V_37 ] . V_108 == V_154 )
return 0 ;
if ( V_101 == V_169 ) {
F_4 ( V_16 -> V_22 , L_84 ,
V_16 -> V_23 -> V_24 ) ;
V_29 = F_40 ( V_2 , V_158 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_85 , V_29 ) ;
goto V_99;
}
} else {
F_4 ( V_16 -> V_22 , L_86 ,
V_16 -> V_23 -> V_24 ) ;
V_29 = F_82 ( V_16 , V_37 ,
V_158 ) ;
if ( V_29 < 0 ) {
F_9 ( V_16 -> V_22 , L_69 , V_29 ) ;
goto V_99;
}
}
return 0 ;
V_99:
F_73 ( V_16 , V_37 ) ;
V_79:
F_71 ( V_16 , V_37 ) ;
V_173:
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
if ( V_21 -> V_20 [ V_37 ] . V_108 != V_159 )
V_20 -> V_108 = V_120 ;
}
return V_29 ;
}
static int F_91 ( struct V_15 * V_16 , int V_37 )
{
int V_29 ;
V_16 -> V_20 [ V_37 ] . V_134 = V_135 ;
V_29 = F_90 ( V_16 , V_37 ) ;
if ( V_29 < 0 )
F_9 ( V_16 -> V_22 , L_87 ) ;
V_16 -> V_20 [ V_37 ] . V_134 = V_141 ;
return V_29 ;
}
static int F_92 ( struct V_15 * V_16 , int V_37 )
{
int V_29 ;
V_16 -> V_20 [ V_37 ] . V_134 = V_135 ;
V_29 = F_89 ( V_16 , V_37 ) ;
if ( V_29 < 0 )
F_9 ( V_16 -> V_22 , L_88 ) ;
V_16 -> V_20 [ V_37 ] . V_134 = V_141 ;
return V_29 ;
}
int F_93 ( struct V_121 * V_92 )
{
int V_35 , V_174 , V_136 , V_132 ;
F_21 ( & V_92 -> V_155 , V_156 ) ;
for ( V_35 = 0 ; V_35 < V_92 -> V_175 ; V_35 ++ ) {
struct V_127 * V_128 ;
struct V_15 * V_16 = & V_92 -> V_27 [ V_35 ] ;
if ( ! V_16 -> V_23 -> V_69 )
continue;
if ( ! V_16 -> V_55 -> V_74 )
continue;
F_4 ( V_16 -> V_22 , L_89 ,
V_16 -> V_23 -> V_24 ) ;
if ( ! V_16 -> V_55 -> V_30 -> V_39 . V_46 )
goto V_41;
V_132 = F_58 ( V_16 , V_38 , & V_128 ) ;
if ( V_132 < 0 ) {
F_7 ( V_16 -> V_22 , L_90 ,
V_16 -> V_23 -> V_24 , L_33 ) ;
F_25 ( & V_92 -> V_155 ) ;
return V_132 ;
}
V_136 = F_63 ( V_16 , V_38 , & V_128 , 1 ) ;
if ( V_136 ) {
F_91 ( V_16 , V_38 ) ;
F_64 ( V_16 , V_38 ) ;
F_49 ( V_16 , V_38 ) ;
}
V_174 = F_63 ( V_16 , V_38 , & V_128 , 0 ) ;
if ( V_174 ) {
F_92 ( V_16 , V_38 ) ;
F_64 ( V_16 , V_38 ) ;
F_49 ( V_16 , V_38 ) ;
}
V_41:
if ( ! V_16 -> V_55 -> V_30 -> V_41 . V_46 )
continue;
V_132 = F_58 ( V_16 , V_90 , & V_128 ) ;
if ( V_132 < 0 ) {
F_7 ( V_16 -> V_22 , L_90 ,
V_16 -> V_23 -> V_24 , L_32 ) ;
F_25 ( & V_92 -> V_155 ) ;
return V_132 ;
}
V_136 = F_63 ( V_16 , V_90 , & V_128 , 1 ) ;
if ( V_136 ) {
F_91 ( V_16 , V_90 ) ;
F_64 ( V_16 , V_90 ) ;
F_49 ( V_16 , V_90 ) ;
}
V_174 = F_63 ( V_16 , V_90 , & V_128 , 0 ) ;
if ( V_174 ) {
F_92 ( V_16 , V_90 ) ;
F_64 ( V_16 , V_90 ) ;
F_49 ( V_16 , V_90 ) ;
}
F_60 ( & V_128 ) ;
}
F_25 ( & V_92 -> V_155 ) ;
return 0 ;
}
int F_94 ( struct V_15 * V_16 , int V_176 )
{
struct V_19 * V_20 ;
struct V_177 * V_178 =
& V_16 -> V_20 [ V_38 ] . V_111 ;
F_3 (dpcm, clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
struct V_25 * V_34 = V_21 -> V_56 ;
struct V_57 * V_179 = V_34 -> V_30 ;
if ( V_21 -> V_23 -> V_180 )
continue;
F_4 ( V_21 -> V_22 , L_91 , V_21 -> V_23 -> V_24 ) ;
if ( V_179 -> V_62 && V_179 -> V_62 -> V_181 && V_34 -> V_75 )
V_179 -> V_62 -> V_181 ( V_34 , V_176 ) ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_116 )
{
struct V_15 * V_16 = V_116 -> V_28 ;
struct V_19 * V_20 ;
struct V_127 * V_128 ;
int V_29 ;
int V_37 = V_116 -> V_37 ;
F_21 ( & V_16 -> V_92 -> V_155 , V_156 ) ;
V_16 -> V_20 [ V_37 ] . V_6 = V_116 -> V_6 ;
if ( F_58 ( V_16 , V_37 , & V_128 ) <= 0 ) {
F_4 ( V_16 -> V_22 , L_92 ,
V_16 -> V_23 -> V_24 , V_37 ? L_32 : L_33 ) ;
}
F_63 ( V_16 , V_37 , & V_128 , 1 ) ;
V_29 = F_70 ( V_116 ) ;
if ( V_29 < 0 ) {
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_20 -> V_108 = V_120 ;
F_49 ( V_16 , V_37 ) ;
V_16 -> V_20 [ V_37 ] . V_6 = NULL ;
}
F_64 ( V_16 , V_37 ) ;
F_60 ( & V_128 ) ;
F_25 ( & V_16 -> V_92 -> V_155 ) ;
return V_29 ;
}
static int F_96 ( struct V_1 * V_116 )
{
struct V_15 * V_16 = V_116 -> V_28 ;
struct V_19 * V_20 ;
int V_37 = V_116 -> V_37 , V_29 ;
F_21 ( & V_16 -> V_92 -> V_155 , V_156 ) ;
V_29 = F_72 ( V_116 ) ;
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_20 -> V_108 = V_120 ;
F_49 ( V_16 , V_37 ) ;
V_16 -> V_20 [ V_37 ] . V_6 = NULL ;
F_25 ( & V_16 -> V_92 -> V_155 ) ;
return V_29 ;
}
int F_97 ( struct V_15 * V_27 , int V_182 )
{
struct V_53 * V_54 = V_27 -> V_54 ;
struct V_25 * V_56 = V_27 -> V_56 ;
struct V_25 * V_55 = V_27 -> V_55 ;
struct V_183 * V_184 ;
char V_185 [ 64 ] ;
int V_29 = 0 , V_39 = 0 , V_41 = 0 ;
if ( V_27 -> V_23 -> V_69 || V_27 -> V_23 -> V_70 ) {
if ( V_55 -> V_30 -> V_39 . V_46 )
V_39 = 1 ;
if ( V_55 -> V_30 -> V_41 . V_46 )
V_41 = 1 ;
} else {
if ( V_56 -> V_30 -> V_39 . V_46 &&
V_55 -> V_30 -> V_39 . V_46 )
V_39 = 1 ;
if ( V_56 -> V_30 -> V_41 . V_46 &&
V_55 -> V_30 -> V_41 . V_46 )
V_41 = 1 ;
}
if ( V_27 -> V_23 -> V_186 ) {
V_39 = 1 ;
V_41 = 0 ;
}
if ( V_27 -> V_23 -> V_187 ) {
V_39 = 0 ;
V_41 = 1 ;
}
if ( V_27 -> V_23 -> V_70 ) {
snprintf ( V_185 , sizeof( V_185 ) , L_93 ,
V_27 -> V_23 -> V_83 ) ;
V_29 = F_98 ( V_27 -> V_92 -> V_188 , V_185 , V_182 ,
V_39 , V_41 , & V_184 ) ;
} else {
if ( V_27 -> V_23 -> V_69 )
snprintf ( V_185 , sizeof( V_185 ) , L_94 ,
V_27 -> V_23 -> V_83 ) ;
else
snprintf ( V_185 , sizeof( V_185 ) , L_95 ,
V_27 -> V_23 -> V_83 , V_56 -> V_24 , V_182 ) ;
V_29 = F_99 ( V_27 -> V_92 -> V_188 , V_185 , V_182 , V_39 ,
V_41 , & V_184 ) ;
}
if ( V_29 < 0 ) {
F_9 ( V_27 -> V_92 -> V_22 , L_96 ,
V_27 -> V_23 -> V_24 ) ;
return V_29 ;
}
F_4 ( V_27 -> V_92 -> V_22 , L_97 , V_182 , V_185 ) ;
F_100 ( & V_27 -> V_82 , F_28 ) ;
V_27 -> V_184 = V_184 ;
V_184 -> V_28 = V_27 ;
if ( V_27 -> V_23 -> V_70 ) {
if ( V_39 )
V_184 -> V_189 [ V_38 ] . V_2 -> V_28 = V_27 ;
if ( V_41 )
V_184 -> V_189 [ V_90 ] . V_2 -> V_28 = V_27 ;
goto V_64;
}
if ( V_27 -> V_23 -> V_69 ) {
V_27 -> V_62 . V_65 = F_95 ;
V_27 -> V_62 . V_96 = F_78 ;
V_27 -> V_62 . V_91 = F_85 ;
V_27 -> V_62 . V_101 = F_83 ;
V_27 -> V_62 . V_99 = F_75 ;
V_27 -> V_62 . V_79 = F_96 ;
V_27 -> V_62 . V_105 = F_41 ;
V_27 -> V_62 . V_171 = F_87 ;
} else {
V_27 -> V_62 . V_65 = F_18 ;
V_27 -> V_62 . V_96 = F_36 ;
V_27 -> V_62 . V_91 = F_34 ;
V_27 -> V_62 . V_101 = F_39 ;
V_27 -> V_62 . V_99 = F_38 ;
V_27 -> V_62 . V_79 = F_30 ;
V_27 -> V_62 . V_105 = F_41 ;
V_27 -> V_62 . V_171 = F_87 ;
}
if ( V_54 -> V_30 -> V_62 ) {
V_27 -> V_62 . V_190 = V_54 -> V_30 -> V_62 -> V_190 ;
V_27 -> V_62 . V_191 = V_54 -> V_30 -> V_62 -> V_191 ;
V_27 -> V_62 . V_192 = V_54 -> V_30 -> V_62 -> V_192 ;
V_27 -> V_62 . V_193 = V_54 -> V_30 -> V_62 -> V_193 ;
V_27 -> V_62 . V_194 = V_54 -> V_30 -> V_62 -> V_194 ;
}
if ( V_39 )
F_101 ( V_184 , V_38 , & V_27 -> V_62 ) ;
if ( V_41 )
F_101 ( V_184 , V_90 , & V_27 -> V_62 ) ;
if ( V_54 -> V_30 -> V_195 ) {
V_29 = V_54 -> V_30 -> V_195 ( V_27 ) ;
if ( V_29 < 0 ) {
F_9 ( V_54 -> V_22 ,
L_98 ,
V_29 ) ;
return V_29 ;
}
}
V_184 -> V_196 = V_54 -> V_30 -> V_197 ;
V_64:
F_102 ( V_27 -> V_92 -> V_22 , L_99 , V_56 -> V_24 ,
V_55 -> V_24 ) ;
return V_29 ;
}
int F_103 ( struct V_15 * V_16 , int V_37 )
{
if ( V_16 -> V_20 [ V_37 ] . V_134 == V_148 )
return 1 ;
return 0 ;
}
int F_67 ( struct V_15 * V_16 ,
struct V_15 * V_21 , int V_37 )
{
if ( ( V_16 -> V_20 [ V_37 ] . V_134 == V_148 ) ||
( ( V_16 -> V_20 [ V_37 ] . V_134 == V_135 ) &&
V_21 -> V_20 [ V_37 ] . V_134 ) )
return 1 ;
return 0 ;
}
struct V_1 *
F_48 ( struct V_15 * V_21 , int V_37 )
{
return V_21 -> V_184 -> V_189 [ V_37 ] . V_2 ;
}
enum V_198
F_104 ( struct V_15 * V_21 , int V_37 )
{
return V_21 -> V_20 [ V_37 ] . V_108 ;
}
void F_105 ( struct V_15 * V_21 ,
int V_37 , enum V_198 V_108 )
{
V_21 -> V_20 [ V_37 ] . V_108 = V_108 ;
}
int F_74 ( struct V_15 * V_16 ,
struct V_15 * V_21 , int V_37 )
{
struct V_19 * V_20 ;
int V_108 ;
F_3 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_20 -> V_16 == V_16 )
continue;
V_108 = V_20 -> V_16 -> V_20 [ V_37 ] . V_108 ;
if ( V_108 == V_159 ||
V_108 == V_153 ||
V_108 == V_161 )
return 0 ;
}
return 1 ;
}
int F_77 ( struct V_15 * V_16 ,
struct V_15 * V_21 , int V_37 )
{
struct V_19 * V_20 ;
int V_108 ;
F_3 (dpcm, &be->dpcm[stream].fe_clients, list_fe) {
if ( V_20 -> V_16 == V_16 )
continue;
V_108 = V_20 -> V_16 -> V_20 [ V_37 ] . V_108 ;
if ( V_108 == V_159 ||
V_108 == V_153 ||
V_108 == V_161 ||
V_108 == V_152 )
return 0 ;
}
return 1 ;
}
int F_106 ( struct V_1 * V_2 ,
int V_100 , struct V_53 * V_54 )
{
if ( V_54 -> V_30 -> V_62 && V_54 -> V_30 -> V_62 -> V_101 )
return V_54 -> V_30 -> V_62 -> V_101 ( V_2 , V_100 ) ;
return 0 ;
}
static char * F_107 ( enum V_198 V_108 )
{
switch ( V_108 ) {
case V_146 :
return L_100 ;
case V_142 :
return L_101 ;
case V_151 :
return L_102 ;
case V_152 :
return L_103 ;
case V_159 :
return L_104 ;
case V_154 :
return L_105 ;
case V_161 :
return L_106 ;
case V_153 :
return L_107 ;
case V_150 :
return L_108 ;
case V_143 :
return L_109 ;
}
return L_110 ;
}
static T_3 F_108 ( struct V_15 * V_16 ,
int V_37 , char * V_199 , T_4 V_200 )
{
struct V_94 * V_95 = & V_16 -> V_20 [ V_37 ] . V_96 ;
struct V_19 * V_20 ;
T_3 V_103 = 0 ;
V_103 += snprintf ( V_199 + V_103 , V_200 - V_103 ,
L_111 , V_16 -> V_23 -> V_24 ,
V_37 ? L_112 : L_113 ) ;
V_103 += snprintf ( V_199 + V_103 , V_200 - V_103 , L_114 ,
F_107 ( V_16 -> V_20 [ V_37 ] . V_108 ) ) ;
if ( ( V_16 -> V_20 [ V_37 ] . V_108 >= V_151 ) &&
( V_16 -> V_20 [ V_37 ] . V_108 <= V_154 ) )
V_103 += snprintf ( V_199 + V_103 , V_200 - V_103 ,
L_115
L_116 ,
F_109 ( F_80 ( V_95 ) ) ,
F_79 ( V_95 ) ,
F_37 ( V_95 ) ) ;
V_103 += snprintf ( V_199 + V_103 , V_200 - V_103 , L_117 ) ;
if ( F_86 ( & V_16 -> V_20 [ V_37 ] . V_111 ) ) {
V_103 += snprintf ( V_199 + V_103 , V_200 - V_103 ,
L_118 ) ;
goto V_64;
}
F_3 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
struct V_15 * V_21 = V_20 -> V_21 ;
V_95 = & V_20 -> V_96 ;
V_103 += snprintf ( V_199 + V_103 , V_200 - V_103 ,
L_119 , V_21 -> V_23 -> V_24 ) ;
V_103 += snprintf ( V_199 + V_103 , V_200 - V_103 ,
L_120 ,
F_107 ( V_21 -> V_20 [ V_37 ] . V_108 ) ) ;
if ( ( V_21 -> V_20 [ V_37 ] . V_108 >= V_151 ) &&
( V_21 -> V_20 [ V_37 ] . V_108 <= V_154 ) )
V_103 += snprintf ( V_199 + V_103 , V_200 - V_103 ,
L_121
L_116 ,
F_109 ( F_80 ( V_95 ) ) ,
F_79 ( V_95 ) ,
F_37 ( V_95 ) ) ;
}
V_64:
return V_103 ;
}
static T_3 F_110 ( struct V_201 * V_201 , char T_5 * V_202 ,
T_4 V_144 , T_6 * V_203 )
{
struct V_15 * V_16 = V_201 -> V_28 ;
T_3 V_204 = V_205 , V_103 = 0 , V_29 = 0 ;
char * V_199 ;
V_199 = F_111 ( V_204 , V_106 ) ;
if ( ! V_199 )
return - V_107 ;
if ( V_16 -> V_55 -> V_30 -> V_39 . V_46 )
V_103 += F_108 ( V_16 , V_38 ,
V_199 + V_103 , V_204 - V_103 ) ;
if ( V_16 -> V_55 -> V_30 -> V_41 . V_46 )
V_103 += F_108 ( V_16 , V_90 ,
V_199 + V_103 , V_204 - V_103 ) ;
V_29 = F_112 ( V_202 , V_144 , V_203 , V_199 , V_103 ) ;
F_53 ( V_199 ) ;
return V_29 ;
}
int F_113 ( struct V_15 * V_27 )
{
if ( ! V_27 -> V_23 )
return 0 ;
V_27 -> V_115 = F_114 ( V_27 -> V_23 -> V_24 ,
V_27 -> V_92 -> V_206 ) ;
if ( ! V_27 -> V_115 ) {
F_4 ( V_27 -> V_22 ,
L_122 ,
V_27 -> V_23 -> V_24 ) ;
return - V_71 ;
}
V_27 -> V_207 = F_115 ( L_123 , 0444 ,
V_27 -> V_115 ,
V_27 , & V_208 ) ;
return 0 ;
}
