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
static int F_13 ( struct V_37 * V_38 , struct V_2 * V_3 )
{
struct V_8 * V_9 = V_38 -> V_9 ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
struct V_39 * V_40 ;
int V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
V_45 = F_2 ( V_3 -> V_46 , struct V_44 , V_47 ) ;
if ( ! V_45 -> V_48 ) {
F_14 ( & V_45 -> V_49 ) ;
F_15 ( V_45 -> V_25 , V_9 -> V_32 ) ;
V_41 = F_16 ( V_45 -> V_25 ) ;
F_17 ( & V_45 -> V_49 ) ;
if ( V_41 )
return V_41 ;
V_45 -> V_48 = true ;
}
V_40 = F_18 ( V_9 , V_50 ,
F_19 ( V_51 ) ) ;
if ( F_10 ( V_40 ) )
return F_11 ( V_40 ) ;
V_52 . V_53 = V_40 [ 0 ] . V_54 ;
V_41 = F_20 ( V_38 , V_3 ) ;
if ( V_41 < 0 )
goto V_26;
V_23 -> V_27 = V_41 ;
V_52 . V_55 = V_41 ;
V_41 = - V_56 ;
V_43 = F_21 ( V_9 -> V_32 , & V_57 ) ;
if ( ! V_43 )
goto V_26;
V_23 -> V_4 . V_28 = V_43 ;
V_43 -> V_29 = V_9 ;
V_43 = F_21 ( V_9 -> V_32 , & V_58 ) ;
if ( ! V_43 )
goto V_26;
V_23 -> V_4 . V_31 = V_43 ;
V_43 -> V_29 = V_9 ;
V_41 = - V_59 ;
V_60 . V_61 = V_57 . V_61 ;
V_62 . V_61 = V_58 . V_61 ;
V_63 . V_61 = V_57 . V_61 ;
V_64 . V_61 = V_58 . V_61 ;
V_41 = F_22 ( V_3 , V_65 , V_66 ,
V_67 ) ;
if ( V_41 )
goto V_26;
F_5 ( V_9 , L_6 ,
F_23 ( V_38 -> V_9 -> V_32 ) ? L_7 :
F_24 ( V_38 -> V_9 -> V_32 ) ? L_8 : L_9 ,
V_23 -> V_4 . V_28 -> V_68 , V_23 -> V_4 . V_31 -> V_68 ) ;
return 0 ;
V_26:
F_25 ( V_3 ) ;
if ( V_23 -> V_4 . V_31 )
V_23 -> V_4 . V_31 -> V_29 = NULL ;
if ( V_23 -> V_4 . V_28 )
V_23 -> V_4 . V_28 -> V_29 = NULL ;
ERROR ( V_9 , L_10 , V_3 -> V_68 , V_41 ) ;
return V_41 ;
}
static void F_26 ( struct V_42 * V_43 , struct V_69 * V_70 )
{
struct V_71 * V_72 = (struct V_71 * ) V_70 -> V_73 ;
F_27 ( V_72 ) ;
}
static struct V_71 * F_28 ( struct V_74 * V_4 , struct V_71 * V_72 )
{
struct V_71 * V_75 = NULL ;
struct V_42 * V_76 = V_4 -> V_28 ;
int V_77 = 0 ;
T_1 V_78 = V_72 -> V_78 ;
if ( ! F_29 ( V_72 ) ) {
int V_79 = F_30 ( V_72 ) ;
int V_80 = F_31 ( V_72 ) ;
if ( ( ( V_78 + V_81 + V_82 ) % V_76 -> V_83 ) == 0 )
V_77 += 2 ;
if ( ( V_80 >= ( V_82 + V_77 ) ) &&
( V_79 >= V_81 ) )
goto V_84;
}
V_75 = F_32 ( V_72 , V_81 , V_82 + V_77 , V_85 ) ;
F_27 ( V_72 ) ;
V_72 = V_75 ;
if ( ! V_72 )
return V_72 ;
V_84:
F_33 ( 0xdeadbeef , F_34 ( V_72 , 4 ) ) ;
V_78 = V_72 -> V_78 ;
F_35 ( V_78 & 0x3FFF , F_36 ( V_72 , 2 ) ) ;
if ( V_77 )
F_35 ( 0 , F_34 ( V_72 , 2 ) ) ;
return V_72 ;
}
static int F_37 ( struct V_74 * V_4 ,
struct V_71 * V_72 ,
struct V_86 * V_87 )
{
struct V_8 * V_9 = V_4 -> V_5 . V_10 -> V_9 ;
int V_41 = 0 ;
do {
struct V_71 * V_75 ;
T_1 V_88 ;
T_1 V_78 = 0 ;
if ( V_72 -> V_78 < V_81 ) {
V_41 = - V_36 ;
F_5 ( V_9 , L_11 ) ;
goto error;
}
V_88 = F_38 ( V_72 -> V_89 ) ;
F_39 ( V_72 , V_81 ) ;
if ( V_88 & F_40 ( 15 ) ) {
struct V_69 * V_70 = V_9 -> V_70 ;
T_1 V_90 ;
if ( V_88 & F_40 ( 14 ) )
continue;
V_90 = ( V_88 >> 11 ) & 0x7 ;
switch ( V_90 ) {
case 0 :
V_78 = V_88 & 0x7FF ;
if ( V_72 -> V_78 < V_78 ) {
V_41 = - V_91 ;
goto error;
}
V_75 = F_41 ( V_72 , V_85 ) ;
if ( F_42 ( ! V_75 ) ) {
F_5 ( V_9 , L_12 ) ;
goto V_92;
}
F_43 ( V_75 , V_78 ) ;
F_35 ( F_40 ( 15 ) | F_40 ( 11 ) | V_78 ,
F_36 ( V_75 , 2 ) ) ;
F_44 ( V_75 , 0 , V_70 -> V_93 , V_75 -> V_78 ) ;
V_70 -> V_94 = V_75 -> V_78 ;
V_70 -> V_95 = F_26 ;
V_70 -> V_96 = 1 ;
V_70 -> V_73 = V_75 ;
if ( F_45 ( V_4 -> V_28 , V_70 , V_85 ) )
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
T_2 V_97 , V_98 ;
struct V_71 * V_99 ;
if ( V_88 == 0 )
continue;
V_78 = V_88 & 0x3FFF ;
if ( ( V_72 -> V_78 < V_78 )
|| ( V_78 < ( V_100 + V_82 ) ) ) {
V_41 = - V_36 ;
goto error;
}
if ( V_88 & F_40 ( 14 ) ) {
V_97 = F_46 ( V_72 -> V_89 + V_78
- V_82 ) ;
V_98 = ~ F_47 ( ~ 0 ,
V_72 -> V_89 , V_78 - V_82 ) ;
} else {
V_97 = F_48 ( V_72 -> V_89 + V_78
- V_82 ) ;
V_98 = 0xdeadbeef ;
}
if ( V_97 != V_98 ) {
F_5 ( V_9 , L_14 ) ;
goto V_92;
}
V_75 = F_41 ( V_72 , V_85 ) ;
if ( F_42 ( ! V_75 ) ) {
F_5 ( V_9 , L_15 ) ;
continue;
}
F_43 ( V_75 , V_78 - V_82 ) ;
V_99 = F_32 ( V_75 ,
V_101 ,
0 ,
V_85 ) ;
if ( F_42 ( ! V_99 ) ) {
F_5 ( V_9 , L_16 ) ;
F_27 ( V_75 ) ;
continue;
}
F_27 ( V_75 ) ;
F_49 ( V_87 , V_99 ) ;
}
V_92:
F_39 ( V_72 , V_78 ) ;
} while ( V_72 -> V_78 );
error:
F_27 ( V_72 ) ;
return V_41 ;
}
static inline struct V_44 * F_50 ( struct V_102 * V_103 )
{
return F_2 ( F_51 ( V_103 ) , struct V_44 ,
V_47 . V_104 ) ;
}
static void F_52 ( struct V_105 * V_3 )
{
struct V_44 * V_106 ;
V_106 = F_2 ( V_3 , struct V_44 , V_47 ) ;
if ( V_106 -> V_48 )
F_53 ( F_54 ( V_106 -> V_25 ) ) ;
else
F_55 ( V_106 -> V_25 ) ;
F_56 ( V_106 ) ;
}
static struct V_105 * F_57 ( void )
{
struct V_44 * V_106 ;
V_106 = F_58 ( sizeof( * V_106 ) , V_107 ) ;
if ( ! V_106 )
return F_59 ( - V_59 ) ;
F_60 ( & V_106 -> V_49 ) ;
V_106 -> V_47 . V_108 = F_52 ;
V_106 -> V_25 = F_61 () ;
if ( F_10 ( V_106 -> V_25 ) ) {
struct V_24 * V_25 = V_106 -> V_25 ;
F_56 ( V_106 ) ;
return F_62 ( V_25 ) ;
}
F_63 ( & V_106 -> V_47 . V_104 , L_17 , & V_109 ) ;
return & V_106 -> V_47 ;
}
static void F_64 ( struct V_2 * V_3 )
{
struct V_1 * V_23 ;
struct V_44 * V_106 ;
V_23 = F_1 ( V_3 ) ;
V_106 = F_2 ( V_3 -> V_46 , struct V_44 , V_47 ) ;
F_56 ( V_23 ) ;
F_14 ( & V_106 -> V_49 ) ;
V_106 -> V_110 -- ;
F_17 ( & V_106 -> V_49 ) ;
}
static void F_65 ( struct V_37 * V_38 , struct V_2 * V_3 )
{
F_5 ( V_38 -> V_9 , L_18 ) ;
F_25 ( V_3 ) ;
}
static struct V_2 * F_66 ( struct V_105 * V_46 )
{
struct V_1 * V_23 ;
struct V_44 * V_106 ;
V_23 = F_58 ( sizeof( * V_23 ) , V_107 ) ;
if ( ! V_23 )
return F_59 ( - V_59 ) ;
V_106 = F_2 ( V_46 , struct V_44 , V_47 ) ;
F_14 ( & V_106 -> V_49 ) ;
V_106 -> V_110 ++ ;
V_23 -> V_4 . V_111 = F_54 ( V_106 -> V_25 ) ;
F_17 ( & V_106 -> V_49 ) ;
V_23 -> V_4 . V_34 = V_35 ;
V_23 -> V_4 . V_5 . V_68 = L_19 ;
V_23 -> V_4 . V_5 . V_112 = F_13 ;
V_23 -> V_4 . V_5 . V_113 = F_65 ;
V_23 -> V_4 . V_5 . V_114 = F_6 ;
V_23 -> V_4 . V_5 . V_115 = F_3 ;
V_23 -> V_4 . V_5 . V_116 = F_12 ;
V_23 -> V_4 . V_5 . V_117 = F_64 ;
V_23 -> V_4 . V_118 = F_28 ;
V_23 -> V_4 . V_119 = F_37 ;
V_23 -> V_4 . V_120 = V_81 ;
return & V_23 -> V_4 . V_5 ;
}
