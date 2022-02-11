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
if ( ! V_23 -> V_4 . V_28 -> V_30 || ! V_23 -> V_4 . V_31 -> V_30 ) {
F_5 ( V_9 , L_3 ) ;
if ( F_8 ( V_9 -> V_32 , V_3 ,
V_23 -> V_4 . V_28 ) ||
F_8 ( V_9 -> V_32 , V_3 ,
V_23 -> V_4 . V_31 ) ) {
V_23 -> V_4 . V_28 -> V_30 = NULL ;
V_23 -> V_4 . V_31 -> V_30 = NULL ;
goto V_26;
}
}
V_23 -> V_4 . V_33 = 1 ;
V_23 -> V_4 . V_34 = V_35 ;
F_5 ( V_9 , L_4 ) ;
V_25 = F_9 ( & V_23 -> V_4 ) ;
if ( F_10 ( V_25 ) )
return F_11 ( V_25 ) ;
} else
goto V_26;
return 0 ;
V_26:
return - V_36 ;
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
F_13 ( struct V_37 * V_38 , struct V_2 * V_3 )
{
struct V_8 * V_9 = V_38 -> V_9 ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
int V_39 ;
struct V_40 * V_41 ;
V_39 = F_14 ( V_38 , V_3 ) ;
if ( V_39 < 0 )
goto V_26;
V_23 -> V_27 = V_39 ;
V_42 . V_43 = V_39 ;
V_39 = - V_44 ;
V_41 = F_15 ( V_9 -> V_32 , & V_45 ) ;
if ( ! V_41 )
goto V_26;
V_23 -> V_4 . V_28 = V_41 ;
V_41 -> V_29 = V_9 ;
V_41 = F_15 ( V_9 -> V_32 , & V_46 ) ;
if ( ! V_41 )
goto V_26;
V_23 -> V_4 . V_31 = V_41 ;
V_41 -> V_29 = V_9 ;
V_39 = - V_47 ;
V_3 -> V_48 = F_16 ( V_49 ) ;
if ( ! V_3 -> V_48 )
goto V_26;
if ( F_17 ( V_38 -> V_9 -> V_32 ) ) {
V_50 . V_51 =
V_45 . V_51 ;
V_52 . V_51 =
V_46 . V_51 ;
V_3 -> V_53 = F_16 ( V_54 ) ;
if ( ! V_3 -> V_53 )
goto V_26;
}
if ( F_18 ( V_38 -> V_9 -> V_32 ) ) {
V_55 . V_51 =
V_45 . V_51 ;
V_56 . V_51 =
V_46 . V_51 ;
V_3 -> V_57 = F_16 ( V_58 ) ;
if ( ! V_3 -> V_57 )
goto V_26;
}
F_5 ( V_9 , L_6 ,
F_18 ( V_38 -> V_9 -> V_32 ) ? L_7 :
F_17 ( V_38 -> V_9 -> V_32 ) ? L_8 : L_9 ,
V_23 -> V_4 . V_28 -> V_59 , V_23 -> V_4 . V_31 -> V_59 ) ;
return 0 ;
V_26:
if ( V_3 -> V_48 )
F_19 ( V_3 -> V_48 ) ;
if ( V_3 -> V_53 )
F_19 ( V_3 -> V_53 ) ;
if ( V_23 -> V_4 . V_31 -> V_30 )
V_23 -> V_4 . V_31 -> V_29 = NULL ;
if ( V_23 -> V_4 . V_28 -> V_30 )
V_23 -> V_4 . V_28 -> V_29 = NULL ;
ERROR ( V_9 , L_10 , V_3 -> V_59 , V_39 ) ;
return V_39 ;
}
static void
F_20 ( struct V_37 * V_38 , struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_5 ( V_38 -> V_9 , L_11 ) ;
if ( F_18 ( V_38 -> V_9 -> V_32 ) )
F_19 ( V_3 -> V_57 ) ;
if ( F_17 ( V_38 -> V_9 -> V_32 ) )
F_19 ( V_3 -> V_53 ) ;
F_19 ( V_3 -> V_48 ) ;
F_21 ( V_23 ) ;
}
static void F_22 ( struct V_40 * V_41 , struct V_60 * V_61 )
{
struct V_62 * V_63 = (struct V_62 * ) V_61 -> V_64 ;
F_23 ( V_63 ) ;
}
static struct V_62 * F_24 ( struct V_65 * V_4 , struct V_62 * V_63 )
{
struct V_62 * V_66 = NULL ;
struct V_40 * V_67 = V_4 -> V_28 ;
int V_68 = 0 ;
T_1 V_69 = V_63 -> V_69 ;
if ( ! F_25 ( V_63 ) ) {
int V_70 = F_26 ( V_63 ) ;
int V_71 = F_27 ( V_63 ) ;
if ( ( ( V_69 + V_72 + V_73 ) % V_67 -> V_74 ) == 0 )
V_68 += 2 ;
if ( ( V_71 >= ( V_73 + V_68 ) ) &&
( V_70 >= V_72 ) )
goto V_75;
}
V_66 = F_28 ( V_63 , V_72 , V_73 + V_68 , V_76 ) ;
F_23 ( V_63 ) ;
V_63 = V_66 ;
if ( ! V_63 )
return V_63 ;
V_75:
F_29 ( 0xdeadbeef , F_30 ( V_63 , 4 ) ) ;
V_69 = V_63 -> V_69 ;
F_31 ( V_69 & 0x3FFF , F_32 ( V_63 , 2 ) ) ;
if ( V_68 )
F_31 ( 0 , F_30 ( V_63 , 2 ) ) ;
return V_63 ;
}
static int F_33 ( struct V_65 * V_4 ,
struct V_62 * V_63 ,
struct V_77 * V_78 )
{
struct V_8 * V_9 = V_4 -> V_5 . V_10 -> V_9 ;
int V_39 = 0 ;
do {
struct V_62 * V_66 ;
T_1 V_79 ;
T_1 V_69 = 0 ;
if ( V_63 -> V_69 < V_72 ) {
V_39 = - V_36 ;
F_5 ( V_9 , L_12 ) ;
goto error;
}
V_79 = F_34 ( V_63 -> V_80 ) ;
F_35 ( V_63 , V_72 ) ;
if ( V_79 & F_36 ( 15 ) ) {
struct V_60 * V_61 = V_9 -> V_61 ;
T_1 V_81 ;
if ( V_79 & F_36 ( 14 ) )
continue;
V_81 = ( V_79 >> 11 ) & 0x7 ;
switch ( V_81 ) {
case 0 :
V_69 = V_79 & 0x7FF ;
if ( V_63 -> V_69 < V_69 ) {
V_39 = - V_82 ;
goto error;
}
V_66 = F_37 ( V_63 , V_76 ) ;
if ( F_38 ( ! V_66 ) ) {
F_5 ( V_9 , L_13 ) ;
goto V_83;
}
F_39 ( V_66 , V_69 ) ;
F_31 ( F_36 ( 15 ) | F_36 ( 11 ) | V_69 ,
F_32 ( V_66 , 2 ) ) ;
F_40 ( V_66 , 0 , V_61 -> V_84 , V_66 -> V_69 ) ;
V_61 -> V_85 = V_66 -> V_69 ;
V_61 -> V_86 = F_22 ;
V_61 -> V_87 = 1 ;
V_61 -> V_64 = V_66 ;
if ( F_41 ( V_4 -> V_28 , V_61 , V_76 ) )
F_5 ( V_9 , L_14 ) ;
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
T_3 V_88 , V_89 ;
struct V_62 * V_90 ;
if ( V_79 == 0 )
continue;
V_69 = V_79 & 0x3FFF ;
if ( ( V_63 -> V_69 < V_69 )
|| ( V_69 < ( V_91 + V_73 ) ) ) {
V_39 = - V_36 ;
goto error;
}
if ( V_79 & F_36 ( 14 ) ) {
V_88 = F_42 ( V_63 -> V_80 + V_69
- V_73 ) ;
V_89 = ~ F_43 ( ~ 0 ,
V_63 -> V_80 , V_69 - V_73 ) ;
} else {
V_88 = F_44 ( V_63 -> V_80 + V_69
- V_73 ) ;
V_89 = 0xdeadbeef ;
}
if ( V_88 != V_89 ) {
F_5 ( V_9 , L_15 ) ;
goto V_83;
}
V_66 = F_37 ( V_63 , V_76 ) ;
if ( F_38 ( ! V_66 ) ) {
F_5 ( V_9 , L_16 ) ;
continue;
}
F_39 ( V_66 , V_69 - V_73 ) ;
V_90 = F_28 ( V_66 ,
V_92 ,
0 ,
V_76 ) ;
if ( F_38 ( ! V_90 ) ) {
F_5 ( V_9 , L_17 ) ;
F_23 ( V_66 ) ;
continue;
}
F_23 ( V_66 ) ;
F_45 ( V_78 , V_90 ) ;
}
V_83:
F_35 ( V_63 , V_69 ) ;
} while ( V_63 -> V_69 );
error:
F_23 ( V_63 ) ;
return V_39 ;
}
int T_2 F_46 ( struct V_37 * V_38 )
{
struct V_1 * V_23 ;
int V_39 ;
if ( V_93 [ 0 ] . V_94 == 0 ) {
V_39 = F_47 ( V_38 -> V_9 ) ;
if ( V_39 < 0 )
return V_39 ;
V_93 [ 0 ] . V_94 = V_39 ;
V_42 . V_95 = V_39 ;
}
V_23 = F_48 ( sizeof *V_23 , V_96 ) ;
if ( ! V_23 )
return - V_47 ;
V_23 -> V_4 . V_34 = V_35 ;
V_23 -> V_4 . V_5 . V_59 = L_18 ;
V_23 -> V_4 . V_5 . V_97 = V_98 ;
V_23 -> V_4 . V_5 . V_99 = F_13 ;
V_23 -> V_4 . V_5 . V_100 = F_20 ;
V_23 -> V_4 . V_5 . V_101 = F_6 ;
V_23 -> V_4 . V_5 . V_102 = F_3 ;
V_23 -> V_4 . V_5 . V_103 = F_12 ;
V_23 -> V_4 . V_104 = F_24 ;
V_23 -> V_4 . V_105 = F_33 ;
V_23 -> V_4 . V_106 = V_72 ;
V_39 = F_49 ( V_38 , & V_23 -> V_4 . V_5 ) ;
if ( V_39 )
F_21 ( V_23 ) ;
return V_39 ;
}
