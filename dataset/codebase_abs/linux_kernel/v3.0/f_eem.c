static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static int F_3 ( struct V_2 * V_3 , const struct V_6 * V_7 )
{
struct V_8 * V_9 = V_3 -> V_10 -> V_9 ;
int V_11 = - V_12 ;
T_1 V_13 = F_4 ( V_7 -> V_14 ) ;
T_1 V_15 = F_4 ( V_7 -> V_16 ) ;
T_1 V_17 = F_4 ( V_7 -> V_18 ) ;
F_5 ( V_9 , L_1 ,
V_7 -> V_19 , V_7 -> V_20 ,
V_15 , V_13 , V_17 ) ;
return V_11 ;
}
static int F_6 ( struct V_2 * V_3 , unsigned V_21 , unsigned V_22 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_3 -> V_10 -> V_9 ;
struct V_24 * V_25 ;
if ( V_22 != 0 )
goto V_26;
if ( V_21 == V_23 -> V_27 ) {
if ( V_23 -> V_4 . V_28 -> V_29 ) {
F_5 ( V_9 , L_2 ) ;
F_7 ( & V_23 -> V_4 ) ;
}
if ( ! V_23 -> V_4 . V_30 ) {
F_5 ( V_9 , L_3 ) ;
V_23 -> V_4 . V_30 = F_8 ( V_9 -> V_31 ,
V_23 -> V_32 . V_30 , V_23 -> V_33 . V_30 ) ;
V_23 -> V_4 . V_34 = F_8 ( V_9 -> V_31 ,
V_23 -> V_32 . V_34 , V_23 -> V_33 . V_34 ) ;
}
V_23 -> V_4 . V_35 = 1 ;
V_23 -> V_4 . V_36 = V_37 ;
F_5 ( V_9 , L_4 ) ;
V_25 = F_9 ( & V_23 -> V_4 ) ;
if ( F_10 ( V_25 ) )
return F_11 ( V_25 ) ;
} else
goto V_26;
return 0 ;
V_26:
return - V_38 ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_3 -> V_10 -> V_9 ;
F_5 ( V_9 , L_5 ) ;
if ( V_23 -> V_4 . V_28 -> V_29 )
F_7 ( & V_23 -> V_4 ) ;
}
static int T_2
F_13 ( struct V_39 * V_40 , struct V_2 * V_3 )
{
struct V_8 * V_9 = V_40 -> V_9 ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
int V_41 ;
struct V_42 * V_43 ;
V_41 = F_14 ( V_40 , V_3 ) ;
if ( V_41 < 0 )
goto V_26;
V_23 -> V_27 = V_41 ;
V_44 . V_45 = V_41 ;
V_41 = - V_46 ;
V_43 = F_15 ( V_9 -> V_31 , & V_47 ) ;
if ( ! V_43 )
goto V_26;
V_23 -> V_4 . V_28 = V_43 ;
V_43 -> V_29 = V_9 ;
V_43 = F_15 ( V_9 -> V_31 , & V_48 ) ;
if ( ! V_43 )
goto V_26;
V_23 -> V_4 . V_49 = V_43 ;
V_43 -> V_29 = V_9 ;
V_41 = - V_50 ;
V_3 -> V_51 = F_16 ( V_52 ) ;
if ( ! V_3 -> V_51 )
goto V_26;
V_23 -> V_33 . V_30 = F_17 ( V_52 ,
V_3 -> V_51 , & V_47 ) ;
V_23 -> V_33 . V_34 = F_17 ( V_52 ,
V_3 -> V_51 , & V_48 ) ;
if ( F_18 ( V_40 -> V_9 -> V_31 ) ) {
V_53 . V_54 =
V_47 . V_54 ;
V_55 . V_54 =
V_48 . V_54 ;
V_3 -> V_56 = F_16 ( V_57 ) ;
if ( ! V_3 -> V_56 )
goto V_26;
V_23 -> V_32 . V_30 = F_17 ( V_57 ,
V_3 -> V_56 , & V_53 ) ;
V_23 -> V_32 . V_34 = F_17 ( V_57 ,
V_3 -> V_56 , & V_55 ) ;
}
F_5 ( V_9 , L_6 ,
F_18 ( V_40 -> V_9 -> V_31 ) ? L_7 : L_8 ,
V_23 -> V_4 . V_28 -> V_58 , V_23 -> V_4 . V_49 -> V_58 ) ;
return 0 ;
V_26:
if ( V_3 -> V_51 )
F_19 ( V_3 -> V_51 ) ;
if ( V_23 -> V_4 . V_34 )
V_23 -> V_4 . V_49 -> V_29 = NULL ;
if ( V_23 -> V_4 . V_30 )
V_23 -> V_4 . V_28 -> V_29 = NULL ;
ERROR ( V_9 , L_9 , V_3 -> V_58 , V_41 ) ;
return V_41 ;
}
static void
F_20 ( struct V_39 * V_40 , struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_5 ( V_40 -> V_9 , L_10 ) ;
if ( F_18 ( V_40 -> V_9 -> V_31 ) )
F_19 ( V_3 -> V_56 ) ;
F_19 ( V_3 -> V_51 ) ;
F_21 ( V_23 ) ;
}
static void F_22 ( struct V_42 * V_43 , struct V_59 * V_60 )
{
struct V_61 * V_62 = (struct V_61 * ) V_60 -> V_63 ;
F_23 ( V_62 ) ;
}
static struct V_61 * F_24 ( struct V_64 * V_4 , struct V_61 * V_62 )
{
struct V_61 * V_65 = NULL ;
struct V_42 * V_30 = V_4 -> V_28 ;
int V_66 = 0 ;
T_1 V_67 = V_62 -> V_67 ;
if ( ! F_25 ( V_62 ) ) {
int V_68 = F_26 ( V_62 ) ;
int V_69 = F_27 ( V_62 ) ;
if ( ( ( V_67 + V_70 + V_71 ) % V_30 -> V_72 ) == 0 )
V_66 += 2 ;
if ( ( V_69 >= ( V_71 + V_66 ) ) &&
( V_68 >= V_70 ) )
goto V_73;
}
V_65 = F_28 ( V_62 , V_70 , V_71 + V_66 , V_74 ) ;
F_23 ( V_62 ) ;
V_62 = V_65 ;
if ( ! V_62 )
return V_62 ;
V_73:
F_29 ( 0xdeadbeef , F_30 ( V_62 , 4 ) ) ;
V_67 = V_62 -> V_67 ;
F_31 ( V_67 & 0x3FFF , F_32 ( V_62 , 2 ) ) ;
if ( V_66 )
F_31 ( 0 , F_30 ( V_62 , 2 ) ) ;
return V_62 ;
}
static int F_33 ( struct V_64 * V_4 ,
struct V_61 * V_62 ,
struct V_75 * V_76 )
{
struct V_8 * V_9 = V_4 -> V_5 . V_10 -> V_9 ;
int V_41 = 0 ;
do {
struct V_61 * V_65 ;
T_1 V_77 ;
T_1 V_67 = 0 ;
if ( V_62 -> V_67 < V_70 ) {
V_41 = - V_38 ;
F_5 ( V_9 , L_11 ) ;
goto error;
}
V_77 = F_34 ( V_62 -> V_78 ) ;
F_35 ( V_62 , V_70 ) ;
if ( V_77 & F_36 ( 15 ) ) {
struct V_59 * V_60 = V_9 -> V_60 ;
T_1 V_79 ;
if ( V_77 & F_36 ( 14 ) )
continue;
V_79 = ( V_77 >> 11 ) & 0x7 ;
switch ( V_79 ) {
case 0 :
V_67 = V_77 & 0x7FF ;
if ( V_62 -> V_67 < V_67 ) {
V_41 = - V_80 ;
goto error;
}
V_65 = F_37 ( V_62 , V_74 ) ;
if ( F_38 ( ! V_65 ) ) {
F_5 ( V_9 , L_12 ) ;
goto V_81;
}
F_39 ( V_65 , V_67 ) ;
F_31 ( F_36 ( 15 ) | F_36 ( 11 ) | V_67 ,
F_32 ( V_65 , 2 ) ) ;
F_40 ( V_65 , 0 , V_60 -> V_82 , V_65 -> V_67 ) ;
V_60 -> V_83 = V_65 -> V_67 ;
V_60 -> V_84 = F_22 ;
V_60 -> V_85 = 1 ;
V_60 -> V_63 = V_65 ;
if ( F_41 ( V_4 -> V_28 , V_60 , V_74 ) )
F_5 ( V_9 , L_13 ) ;
break;
case 1 :
case 2 :
case 3 :
case 4 :
case 5 :
default:
continue;
}
} else {
T_3 V_86 , V_87 ;
struct V_61 * V_88 ;
if ( V_77 == 0 )
continue;
V_67 = V_77 & 0x3FFF ;
if ( ( V_62 -> V_67 < V_67 )
|| ( V_67 < ( V_89 + V_71 ) ) ) {
V_41 = - V_38 ;
goto error;
}
if ( V_77 & F_36 ( 14 ) ) {
V_86 = F_42 ( V_62 -> V_78 + V_67
- V_71 ) ;
V_87 = ~ F_43 ( ~ 0 ,
V_62 -> V_78 , V_67 - V_71 ) ;
} else {
V_86 = F_44 ( V_62 -> V_78 + V_67
- V_71 ) ;
V_87 = 0xdeadbeef ;
}
if ( V_86 != V_87 ) {
F_5 ( V_9 , L_14 ) ;
goto V_81;
}
V_65 = F_37 ( V_62 , V_74 ) ;
if ( F_38 ( ! V_65 ) ) {
F_5 ( V_9 , L_15 ) ;
continue;
}
F_39 ( V_65 , V_67 - V_71 ) ;
V_88 = F_28 ( V_65 ,
V_90 ,
0 ,
V_74 ) ;
if ( F_38 ( ! V_88 ) ) {
F_5 ( V_9 , L_16 ) ;
F_23 ( V_65 ) ;
continue;
}
F_23 ( V_65 ) ;
F_45 ( V_76 , V_88 ) ;
}
V_81:
F_35 ( V_62 , V_67 ) ;
} while ( V_62 -> V_67 );
error:
F_23 ( V_62 ) ;
return V_41 ;
}
int T_2 F_46 ( struct V_39 * V_40 )
{
struct V_1 * V_23 ;
int V_41 ;
if ( V_91 [ 0 ] . V_92 == 0 ) {
V_41 = F_47 ( V_40 -> V_9 ) ;
if ( V_41 < 0 )
return V_41 ;
V_91 [ 0 ] . V_92 = V_41 ;
V_44 . V_93 = V_41 ;
}
V_23 = F_48 ( sizeof *V_23 , V_94 ) ;
if ( ! V_23 )
return - V_50 ;
V_23 -> V_4 . V_36 = V_37 ;
V_23 -> V_4 . V_5 . V_58 = L_17 ;
V_23 -> V_4 . V_5 . V_95 = V_96 ;
V_23 -> V_4 . V_5 . V_97 = F_13 ;
V_23 -> V_4 . V_5 . V_98 = F_20 ;
V_23 -> V_4 . V_5 . V_99 = F_6 ;
V_23 -> V_4 . V_5 . V_100 = F_3 ;
V_23 -> V_4 . V_5 . V_101 = F_12 ;
V_23 -> V_4 . V_102 = F_24 ;
V_23 -> V_4 . V_103 = F_33 ;
V_23 -> V_4 . V_104 = V_70 ;
V_41 = F_49 ( V_40 , & V_23 -> V_4 . V_5 ) ;
if ( V_41 )
F_21 ( V_23 ) ;
return V_41 ;
}
