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
V_48 . V_49 = V_45 . V_49 ;
V_50 . V_49 = V_46 . V_49 ;
V_51 . V_49 = V_45 . V_49 ;
V_52 . V_49 = V_46 . V_49 ;
V_39 = F_16 ( V_3 , V_53 , V_54 ,
V_55 ) ;
if ( V_39 )
goto V_26;
F_5 ( V_9 , L_6 ,
F_17 ( V_38 -> V_9 -> V_32 ) ? L_7 :
F_18 ( V_38 -> V_9 -> V_32 ) ? L_8 : L_9 ,
V_23 -> V_4 . V_28 -> V_56 , V_23 -> V_4 . V_31 -> V_56 ) ;
return 0 ;
V_26:
F_19 ( V_3 ) ;
if ( V_23 -> V_4 . V_31 )
V_23 -> V_4 . V_31 -> V_29 = NULL ;
if ( V_23 -> V_4 . V_28 )
V_23 -> V_4 . V_28 -> V_29 = NULL ;
ERROR ( V_9 , L_10 , V_3 -> V_56 , V_39 ) ;
return V_39 ;
}
static void
F_20 ( struct V_37 * V_38 , struct V_2 * V_3 )
{
struct V_1 * V_23 = F_1 ( V_3 ) ;
F_5 ( V_38 -> V_9 , L_11 ) ;
F_19 ( V_3 ) ;
F_21 ( V_23 ) ;
}
static void F_22 ( struct V_40 * V_41 , struct V_57 * V_58 )
{
struct V_59 * V_60 = (struct V_59 * ) V_58 -> V_61 ;
F_23 ( V_60 ) ;
}
static struct V_59 * F_24 ( struct V_62 * V_4 , struct V_59 * V_60 )
{
struct V_59 * V_63 = NULL ;
struct V_40 * V_64 = V_4 -> V_28 ;
int V_65 = 0 ;
T_1 V_66 = V_60 -> V_66 ;
if ( ! F_25 ( V_60 ) ) {
int V_67 = F_26 ( V_60 ) ;
int V_68 = F_27 ( V_60 ) ;
if ( ( ( V_66 + V_69 + V_70 ) % V_64 -> V_71 ) == 0 )
V_65 += 2 ;
if ( ( V_68 >= ( V_70 + V_65 ) ) &&
( V_67 >= V_69 ) )
goto V_72;
}
V_63 = F_28 ( V_60 , V_69 , V_70 + V_65 , V_73 ) ;
F_23 ( V_60 ) ;
V_60 = V_63 ;
if ( ! V_60 )
return V_60 ;
V_72:
F_29 ( 0xdeadbeef , F_30 ( V_60 , 4 ) ) ;
V_66 = V_60 -> V_66 ;
F_31 ( V_66 & 0x3FFF , F_32 ( V_60 , 2 ) ) ;
if ( V_65 )
F_31 ( 0 , F_30 ( V_60 , 2 ) ) ;
return V_60 ;
}
static int F_33 ( struct V_62 * V_4 ,
struct V_59 * V_60 ,
struct V_74 * V_75 )
{
struct V_8 * V_9 = V_4 -> V_5 . V_10 -> V_9 ;
int V_39 = 0 ;
do {
struct V_59 * V_63 ;
T_1 V_76 ;
T_1 V_66 = 0 ;
if ( V_60 -> V_66 < V_69 ) {
V_39 = - V_36 ;
F_5 ( V_9 , L_12 ) ;
goto error;
}
V_76 = F_34 ( V_60 -> V_77 ) ;
F_35 ( V_60 , V_69 ) ;
if ( V_76 & F_36 ( 15 ) ) {
struct V_57 * V_58 = V_9 -> V_58 ;
T_1 V_78 ;
if ( V_76 & F_36 ( 14 ) )
continue;
V_78 = ( V_76 >> 11 ) & 0x7 ;
switch ( V_78 ) {
case 0 :
V_66 = V_76 & 0x7FF ;
if ( V_60 -> V_66 < V_66 ) {
V_39 = - V_79 ;
goto error;
}
V_63 = F_37 ( V_60 , V_73 ) ;
if ( F_38 ( ! V_63 ) ) {
F_5 ( V_9 , L_13 ) ;
goto V_80;
}
F_39 ( V_63 , V_66 ) ;
F_31 ( F_36 ( 15 ) | F_36 ( 11 ) | V_66 ,
F_32 ( V_63 , 2 ) ) ;
F_40 ( V_63 , 0 , V_58 -> V_81 , V_63 -> V_66 ) ;
V_58 -> V_82 = V_63 -> V_66 ;
V_58 -> V_83 = F_22 ;
V_58 -> V_84 = 1 ;
V_58 -> V_61 = V_63 ;
if ( F_41 ( V_4 -> V_28 , V_58 , V_73 ) )
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
T_3 V_85 , V_86 ;
struct V_59 * V_87 ;
if ( V_76 == 0 )
continue;
V_66 = V_76 & 0x3FFF ;
if ( ( V_60 -> V_66 < V_66 )
|| ( V_66 < ( V_88 + V_70 ) ) ) {
V_39 = - V_36 ;
goto error;
}
if ( V_76 & F_36 ( 14 ) ) {
V_85 = F_42 ( V_60 -> V_77 + V_66
- V_70 ) ;
V_86 = ~ F_43 ( ~ 0 ,
V_60 -> V_77 , V_66 - V_70 ) ;
} else {
V_85 = F_44 ( V_60 -> V_77 + V_66
- V_70 ) ;
V_86 = 0xdeadbeef ;
}
if ( V_85 != V_86 ) {
F_5 ( V_9 , L_15 ) ;
goto V_80;
}
V_63 = F_37 ( V_60 , V_73 ) ;
if ( F_38 ( ! V_63 ) ) {
F_5 ( V_9 , L_16 ) ;
continue;
}
F_39 ( V_63 , V_66 - V_70 ) ;
V_87 = F_28 ( V_63 ,
V_89 ,
0 ,
V_73 ) ;
if ( F_38 ( ! V_87 ) ) {
F_5 ( V_9 , L_17 ) ;
F_23 ( V_63 ) ;
continue;
}
F_23 ( V_63 ) ;
F_45 ( V_75 , V_87 ) ;
}
V_80:
F_35 ( V_60 , V_66 ) ;
} while ( V_60 -> V_66 );
error:
F_23 ( V_60 ) ;
return V_39 ;
}
int T_2 F_46 ( struct V_37 * V_38 , struct V_90 * V_91 )
{
struct V_1 * V_23 ;
int V_39 ;
if ( V_92 [ 0 ] . V_93 == 0 ) {
V_39 = F_47 ( V_38 -> V_9 ) ;
if ( V_39 < 0 )
return V_39 ;
V_92 [ 0 ] . V_93 = V_39 ;
V_42 . V_94 = V_39 ;
}
V_23 = F_48 ( sizeof *V_23 , V_95 ) ;
if ( ! V_23 )
return - V_47 ;
V_23 -> V_4 . V_96 = V_91 ;
V_23 -> V_4 . V_34 = V_35 ;
V_23 -> V_4 . V_5 . V_56 = L_18 ;
V_23 -> V_4 . V_5 . V_97 = V_98 ;
V_23 -> V_4 . V_5 . V_99 = F_13 ;
V_23 -> V_4 . V_5 . V_100 = F_20 ;
V_23 -> V_4 . V_5 . V_101 = F_6 ;
V_23 -> V_4 . V_5 . V_102 = F_3 ;
V_23 -> V_4 . V_5 . V_103 = F_12 ;
V_23 -> V_4 . V_104 = F_24 ;
V_23 -> V_4 . V_105 = F_33 ;
V_23 -> V_4 . V_106 = V_69 ;
V_39 = F_49 ( V_38 , & V_23 -> V_4 . V_5 ) ;
if ( V_39 )
F_21 ( V_23 ) ;
return V_39 ;
}
