static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_3 -> V_10 ;
struct V_11 V_12 = { 0 } ;
struct V_13 * V_14 = NULL ;
struct V_1 * V_15 ;
bool V_16 = false ;
if ( V_6 & V_17 ) {
V_12 . type = V_18 ;
V_12 . V_19 = V_3 -> V_20 . V_21 . V_19 . V_22 ;
} else if ( V_6 & V_23 ) {
V_14 = F_2 ( V_9 , true ) ;
if ( F_3 ( V_14 ) )
return F_4 ( V_14 ) ;
V_12 . type = V_24 ;
V_12 . V_14 = V_14 ;
}
if ( F_5 ( V_3 -> V_20 . V_25 . V_22 ) ) {
V_3 -> V_20 . V_25 . V_22 =
F_6 ( V_3 -> V_20 . V_26 ,
V_27 ,
V_28 ,
V_29 ,
0 ) ;
if ( F_3 ( V_3 -> V_20 . V_25 . V_22 ) ) {
F_7 ( V_3 -> V_30 ,
L_1 ) ;
V_15 = F_4 ( V_3 -> V_20 . V_25 . V_22 ) ;
goto V_31;
}
V_16 = true ;
}
V_5 -> V_32 = V_33 ;
V_15 = F_8 ( V_3 -> V_20 . V_25 . V_22 , V_5 ,
V_6 , V_7 ,
& V_12 ) ;
if ( F_3 ( V_15 ) )
goto V_34;
return V_15 ;
V_34:
if ( V_16 ) {
F_9 ( V_3 -> V_20 . V_25 . V_22 ) ;
V_3 -> V_20 . V_25 . V_22 = NULL ;
}
V_31:
F_10 ( V_9 , V_14 ) ;
return V_15 ;
}
static struct V_1 * F_11 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 , T_1 V_35 )
{
struct V_36 * V_37 = V_3 -> V_10 -> V_3 . V_38 ;
struct V_39 * V_40 = V_3 -> V_41 ;
T_1 V_42 ;
if ( V_40 -> V_43 )
V_42 = V_40 -> V_43 ;
else
V_42 = V_44 ;
return F_12 ( V_37 , V_5 , V_6 , V_42 , V_35 ) ;
}
static void F_13 ( struct V_2 * V_3 ,
struct V_1 * V_15 )
{
struct V_13 * V_14 = NULL ;
V_14 = F_14 ( V_15 ) ;
F_15 ( V_15 ) ;
F_10 ( V_3 -> V_10 , V_14 ) ;
if ( ! F_16 ( V_3 ) && ( V_3 -> V_20 . V_25 . V_22 ) ) {
F_9 ( V_3 -> V_20 . V_25 . V_22 ) ;
V_3 -> V_20 . V_25 . V_22 = NULL ;
}
}
static int F_17 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_45 * V_46 )
{
void * V_47 = F_18 ( V_48 , V_5 -> V_49 ,
V_50 ) ;
void * V_51 = F_18 ( V_48 , V_5 -> V_52 ,
V_50 ) ;
T_2 V_53 = 0 ;
T_3 V_54 = 0 ;
if ( V_46 -> V_55 -> V_56 &
~ ( F_19 ( V_57 ) |
F_19 ( V_58 ) |
F_19 ( V_59 ) |
F_19 ( V_60 ) |
F_19 ( V_61 ) |
F_19 ( V_62 ) ) ) {
F_20 ( V_3 -> V_30 , L_2 ,
V_46 -> V_55 -> V_56 ) ;
return - V_63 ;
}
if ( F_21 ( V_46 -> V_55 , V_57 ) ) {
struct V_64 * V_65 =
F_22 ( V_46 -> V_55 ,
V_57 ,
V_46 -> V_65 ) ;
V_53 = V_65 -> V_53 ;
}
if ( F_21 ( V_46 -> V_55 , V_58 ) ) {
struct V_66 * V_65 =
F_22 ( V_46 -> V_55 ,
V_58 ,
V_46 -> V_65 ) ;
struct V_66 * V_67 =
F_22 ( V_46 -> V_55 ,
V_58 ,
V_46 -> V_67 ) ;
V_54 = V_65 -> V_54 ;
F_23 ( V_68 , V_47 , V_69 ,
F_24 ( V_67 -> V_70 ) ) ;
F_23 ( V_68 , V_51 , V_69 ,
F_24 ( V_65 -> V_70 ) ) ;
F_23 ( V_68 , V_47 , V_71 ,
V_67 -> V_54 ) ;
F_23 ( V_68 , V_51 , V_71 ,
V_65 -> V_54 ) ;
}
if ( F_21 ( V_46 -> V_55 , V_59 ) ) {
struct V_72 * V_65 =
F_22 ( V_46 -> V_55 ,
V_59 ,
V_46 -> V_65 ) ;
struct V_72 * V_67 =
F_22 ( V_46 -> V_55 ,
V_59 ,
V_46 -> V_67 ) ;
F_25 ( F_18 ( V_68 , V_47 ,
V_73 ) ,
V_67 -> V_74 ) ;
F_25 ( F_18 ( V_68 , V_51 ,
V_73 ) ,
V_65 -> V_74 ) ;
F_25 ( F_18 ( V_68 , V_47 ,
V_75 ) ,
V_67 -> V_76 ) ;
F_25 ( F_18 ( V_68 , V_51 ,
V_75 ) ,
V_65 -> V_76 ) ;
}
if ( V_53 == V_60 ) {
struct V_77 * V_65 =
F_22 ( V_46 -> V_55 ,
V_60 ,
V_46 -> V_65 ) ;
struct V_77 * V_67 =
F_22 ( V_46 -> V_55 ,
V_60 ,
V_46 -> V_67 ) ;
memcpy ( F_18 ( V_68 , V_47 ,
V_78 . V_79 . V_80 ) ,
& V_67 -> V_76 , sizeof( V_67 -> V_76 ) ) ;
memcpy ( F_18 ( V_68 , V_51 ,
V_78 . V_79 . V_80 ) ,
& V_65 -> V_76 , sizeof( V_65 -> V_76 ) ) ;
memcpy ( F_18 ( V_68 , V_47 ,
V_81 . V_79 . V_80 ) ,
& V_67 -> V_74 , sizeof( V_67 -> V_74 ) ) ;
memcpy ( F_18 ( V_68 , V_51 ,
V_81 . V_79 . V_80 ) ,
& V_65 -> V_74 , sizeof( V_65 -> V_74 ) ) ;
}
if ( V_53 == V_61 ) {
struct V_82 * V_65 =
F_22 ( V_46 -> V_55 ,
V_61 ,
V_46 -> V_65 ) ;
struct V_82 * V_67 =
F_22 ( V_46 -> V_55 ,
V_61 ,
V_46 -> V_67 ) ;
memcpy ( F_18 ( V_68 , V_47 ,
V_78 . V_83 . V_84 ) ,
& V_67 -> V_76 , sizeof( V_67 -> V_76 ) ) ;
memcpy ( F_18 ( V_68 , V_51 ,
V_78 . V_83 . V_84 ) ,
& V_65 -> V_76 , sizeof( V_65 -> V_76 ) ) ;
memcpy ( F_18 ( V_68 , V_47 ,
V_81 . V_83 . V_84 ) ,
& V_67 -> V_74 , sizeof( V_67 -> V_74 ) ) ;
memcpy ( F_18 ( V_68 , V_51 ,
V_81 . V_83 . V_84 ) ,
& V_65 -> V_74 , sizeof( V_65 -> V_74 ) ) ;
}
if ( F_21 ( V_46 -> V_55 , V_62 ) ) {
struct V_85 * V_65 =
F_22 ( V_46 -> V_55 ,
V_62 ,
V_46 -> V_65 ) ;
struct V_85 * V_67 =
F_22 ( V_46 -> V_55 ,
V_62 ,
V_46 -> V_67 ) ;
switch ( V_54 ) {
case V_86 :
F_23 ( V_68 , V_47 ,
V_87 , F_24 ( V_67 -> V_76 ) ) ;
F_23 ( V_68 , V_51 ,
V_87 , F_24 ( V_65 -> V_76 ) ) ;
F_23 ( V_68 , V_47 ,
V_88 , F_24 ( V_67 -> V_74 ) ) ;
F_23 ( V_68 , V_51 ,
V_88 , F_24 ( V_65 -> V_74 ) ) ;
break;
case V_89 :
F_23 ( V_68 , V_47 ,
V_90 , F_24 ( V_67 -> V_76 ) ) ;
F_23 ( V_68 , V_51 ,
V_90 , F_24 ( V_65 -> V_76 ) ) ;
F_23 ( V_68 , V_47 ,
V_91 , F_24 ( V_67 -> V_74 ) ) ;
F_23 ( V_68 , V_51 ,
V_91 , F_24 ( V_65 -> V_74 ) ) ;
break;
default:
F_7 ( V_3 -> V_30 ,
L_3 ) ;
return - V_92 ;
}
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_93 * V_94 ,
T_1 * V_6 , T_1 * V_7 )
{
const struct V_95 * V_96 ;
F_27 ( V_97 ) ;
if ( F_28 ( V_94 ) )
return - V_92 ;
* V_7 = V_98 ;
* V_6 = 0 ;
F_29 ( V_94 , & V_97 ) ;
F_30 (a, &actions, list) {
if ( * V_6 )
return - V_92 ;
if ( F_31 ( V_96 ) ) {
* V_6 |= V_99 ;
if ( F_32 ( V_3 -> V_10 ,
V_100 . V_101 ) )
* V_6 |= V_23 ;
continue;
}
if ( F_33 ( V_96 ) ) {
T_1 V_102 = F_34 ( V_96 ) ;
if ( V_102 & ~ V_103 ) {
F_20 ( V_3 -> V_30 , L_4 ,
V_102 ) ;
return - V_92 ;
}
* V_7 = V_102 ;
* V_6 |= V_17 ;
continue;
}
return - V_92 ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_93 * V_94 ,
T_1 * V_6 , T_1 * V_104 )
{
const struct V_95 * V_96 ;
F_27 ( V_97 ) ;
if ( F_28 ( V_94 ) )
return - V_92 ;
* V_6 = 0 ;
F_29 ( V_94 , & V_97 ) ;
F_30 (a, &actions, list) {
if ( * V_6 )
return - V_92 ;
if ( F_31 ( V_96 ) ) {
* V_6 = V_99 |
V_23 ;
continue;
}
if ( F_36 ( V_96 ) ) {
int V_105 = F_37 ( V_96 ) ;
struct V_106 * V_107 ;
struct V_2 * V_108 ;
struct V_39 * V_109 ;
V_107 = F_38 ( F_39 ( V_3 -> V_30 ) , V_105 ) ;
if ( ! F_40 ( V_3 -> V_30 , V_107 ) ) {
F_41 ( L_5 ,
V_3 -> V_30 -> V_110 , V_107 -> V_110 ) ;
return - V_92 ;
}
V_108 = F_42 ( V_107 ) ;
V_109 = V_108 -> V_41 ;
if ( V_109 -> V_43 == 0 )
* V_104 = V_44 ;
else
* V_104 = V_109 -> V_43 ;
* V_6 = V_17 ;
continue;
}
return - V_92 ;
}
return 0 ;
}
int F_43 ( struct V_2 * V_3 , T_4 V_111 ,
struct V_45 * V_46 )
{
struct V_112 * V_25 = & V_3 -> V_20 . V_25 ;
int V_113 = 0 ;
T_1 V_7 , V_6 , V_104 = 0 ;
struct V_114 * V_115 ;
struct V_4 * V_5 ;
struct V_1 * V_116 = NULL ;
struct V_36 * V_37 = V_3 -> V_10 -> V_3 . V_38 ;
V_115 = F_44 ( & V_25 -> V_117 , & V_46 -> V_118 ,
V_25 -> V_119 ) ;
if ( V_115 )
V_116 = V_115 -> V_15 ;
else
V_115 = F_45 ( sizeof( * V_115 ) , V_120 ) ;
V_5 = F_46 ( sizeof( * V_5 ) ) ;
if ( ! V_5 || ! V_115 ) {
V_113 = - V_121 ;
goto V_122;
}
V_115 -> V_118 = V_46 -> V_118 ;
V_113 = F_17 ( V_3 , V_5 , V_46 ) ;
if ( V_113 < 0 )
goto V_122;
if ( V_37 && V_37 -> V_123 == V_124 ) {
V_113 = F_35 ( V_3 , V_46 -> V_94 , & V_6 , & V_104 ) ;
if ( V_113 < 0 )
goto V_122;
V_115 -> V_15 = F_11 ( V_3 , V_5 , V_6 , V_104 ) ;
} else {
V_113 = F_26 ( V_3 , V_46 -> V_94 , & V_6 , & V_7 ) ;
if ( V_113 < 0 )
goto V_122;
V_115 -> V_15 = F_1 ( V_3 , V_5 , V_6 , V_7 ) ;
}
if ( F_3 ( V_115 -> V_15 ) ) {
V_113 = F_47 ( V_115 -> V_15 ) ;
goto V_122;
}
V_113 = F_48 ( & V_25 -> V_117 , & V_115 -> V_125 ,
V_25 -> V_119 ) ;
if ( V_113 )
goto V_126;
if ( V_116 )
F_13 ( V_3 , V_116 ) ;
goto V_127;
V_126:
F_15 ( V_115 -> V_15 ) ;
V_122:
if ( ! V_116 )
F_49 ( V_115 ) ;
V_127:
F_50 ( V_5 ) ;
return V_113 ;
}
int F_51 ( struct V_2 * V_3 ,
struct V_45 * V_46 )
{
struct V_114 * V_115 ;
struct V_112 * V_25 = & V_3 -> V_20 . V_25 ;
V_115 = F_44 ( & V_25 -> V_117 , & V_46 -> V_118 ,
V_25 -> V_119 ) ;
if ( ! V_115 )
return - V_92 ;
F_52 ( & V_25 -> V_117 , & V_115 -> V_125 , V_25 -> V_119 ) ;
F_13 ( V_3 , V_115 -> V_15 ) ;
F_49 ( V_115 ) ;
return 0 ;
}
int F_53 ( struct V_2 * V_3 ,
struct V_45 * V_46 )
{
struct V_112 * V_25 = & V_3 -> V_20 . V_25 ;
struct V_114 * V_115 ;
struct V_95 * V_96 ;
struct V_13 * V_14 ;
F_27 ( V_97 ) ;
T_5 V_128 ;
T_5 V_129 ;
T_5 V_130 ;
V_115 = F_44 ( & V_25 -> V_117 , & V_46 -> V_118 ,
V_25 -> V_119 ) ;
if ( ! V_115 )
return - V_92 ;
V_14 = F_14 ( V_115 -> V_15 ) ;
if ( ! V_14 )
return 0 ;
F_54 ( V_14 , & V_128 , & V_129 , & V_130 ) ;
F_29 ( V_46 -> V_94 , & V_97 ) ;
F_30 (a, &actions, list)
F_55 ( V_96 , V_128 , V_129 , V_130 ) ;
return 0 ;
}
int F_56 ( struct V_2 * V_3 )
{
struct V_112 * V_25 = & V_3 -> V_20 . V_25 ;
V_25 -> V_119 = V_131 ;
return F_57 ( & V_25 -> V_117 , & V_25 -> V_119 ) ;
}
static void F_58 ( void * V_132 , void * V_133 )
{
struct V_114 * V_115 = V_132 ;
struct V_2 * V_3 = V_133 ;
F_13 ( V_3 , V_115 -> V_15 ) ;
F_49 ( V_115 ) ;
}
void F_59 ( struct V_2 * V_3 )
{
struct V_112 * V_25 = & V_3 -> V_20 . V_25 ;
F_60 ( & V_25 -> V_117 , F_58 , V_3 ) ;
if ( ! F_5 ( V_25 -> V_22 ) ) {
F_9 ( V_25 -> V_22 ) ;
V_25 -> V_22 = NULL ;
}
}
