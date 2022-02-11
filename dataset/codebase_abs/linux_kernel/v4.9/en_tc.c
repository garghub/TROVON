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
struct V_35 * V_36 )
{
struct V_37 * V_38 = V_3 -> V_10 -> V_3 . V_39 ;
int V_40 ;
V_40 = F_12 ( V_38 , V_36 ) ;
if ( V_40 )
return F_13 ( V_40 ) ;
return F_14 ( V_38 , V_5 , V_36 ) ;
}
static void F_15 ( struct V_2 * V_3 ,
struct V_1 * V_15 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 = V_3 -> V_10 -> V_3 . V_39 ;
struct V_13 * V_14 = NULL ;
V_14 = F_16 ( V_15 ) ;
if ( V_38 && V_38 -> V_41 == V_42 )
F_17 ( V_38 , V_36 ) ;
F_18 ( V_15 ) ;
F_10 ( V_3 -> V_10 , V_14 ) ;
if ( ! F_19 ( V_3 ) && ( V_3 -> V_20 . V_25 . V_22 ) ) {
F_9 ( V_3 -> V_20 . V_25 . V_22 ) ;
V_3 -> V_20 . V_25 . V_22 = NULL ;
}
}
static int F_20 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_43 * V_44 )
{
void * V_45 = F_21 ( V_46 , V_5 -> V_47 ,
V_48 ) ;
void * V_49 = F_21 ( V_46 , V_5 -> V_50 ,
V_48 ) ;
T_2 V_51 = 0 ;
T_3 V_52 = 0 ;
if ( V_44 -> V_53 -> V_54 &
~ ( F_22 ( V_55 ) |
F_22 ( V_56 ) |
F_22 ( V_57 ) |
F_22 ( V_58 ) |
F_22 ( V_59 ) |
F_22 ( V_60 ) |
F_22 ( V_61 ) ) ) {
F_23 ( V_3 -> V_30 , L_2 ,
V_44 -> V_53 -> V_54 ) ;
return - V_62 ;
}
if ( F_24 ( V_44 -> V_53 , V_55 ) ) {
struct V_63 * V_64 =
F_25 ( V_44 -> V_53 ,
V_55 ,
V_44 -> V_64 ) ;
V_51 = V_64 -> V_51 ;
}
if ( F_24 ( V_44 -> V_53 , V_56 ) ) {
struct V_65 * V_64 =
F_25 ( V_44 -> V_53 ,
V_56 ,
V_44 -> V_64 ) ;
struct V_65 * V_66 =
F_25 ( V_44 -> V_53 ,
V_56 ,
V_44 -> V_66 ) ;
V_52 = V_64 -> V_52 ;
F_26 ( V_67 , V_45 , V_68 ,
F_27 ( V_66 -> V_69 ) ) ;
F_26 ( V_67 , V_49 , V_68 ,
F_27 ( V_64 -> V_69 ) ) ;
F_26 ( V_67 , V_45 , V_70 ,
V_66 -> V_52 ) ;
F_26 ( V_67 , V_49 , V_70 ,
V_64 -> V_52 ) ;
}
if ( F_24 ( V_44 -> V_53 , V_57 ) ) {
struct V_71 * V_64 =
F_25 ( V_44 -> V_53 ,
V_57 ,
V_44 -> V_64 ) ;
struct V_71 * V_66 =
F_25 ( V_44 -> V_53 ,
V_57 ,
V_44 -> V_66 ) ;
F_28 ( F_21 ( V_67 , V_45 ,
V_72 ) ,
V_66 -> V_73 ) ;
F_28 ( F_21 ( V_67 , V_49 ,
V_72 ) ,
V_64 -> V_73 ) ;
F_28 ( F_21 ( V_67 , V_45 ,
V_74 ) ,
V_66 -> V_75 ) ;
F_28 ( F_21 ( V_67 , V_49 ,
V_74 ) ,
V_64 -> V_75 ) ;
}
if ( F_24 ( V_44 -> V_53 , V_58 ) ) {
struct V_76 * V_64 =
F_25 ( V_44 -> V_53 ,
V_58 ,
V_44 -> V_64 ) ;
struct V_76 * V_66 =
F_25 ( V_44 -> V_53 ,
V_58 ,
V_44 -> V_66 ) ;
if ( V_66 -> V_77 || V_66 -> V_78 ) {
F_26 ( V_67 , V_45 , V_79 , 1 ) ;
F_26 ( V_67 , V_49 , V_79 , 1 ) ;
F_26 ( V_67 , V_45 , V_80 , V_66 -> V_77 ) ;
F_26 ( V_67 , V_49 , V_80 , V_64 -> V_77 ) ;
F_26 ( V_67 , V_45 , V_81 , V_66 -> V_78 ) ;
F_26 ( V_67 , V_49 , V_81 , V_64 -> V_78 ) ;
}
}
if ( V_51 == V_59 ) {
struct V_82 * V_64 =
F_25 ( V_44 -> V_53 ,
V_59 ,
V_44 -> V_64 ) ;
struct V_82 * V_66 =
F_25 ( V_44 -> V_53 ,
V_59 ,
V_44 -> V_66 ) ;
memcpy ( F_21 ( V_67 , V_45 ,
V_83 . V_84 . V_85 ) ,
& V_66 -> V_75 , sizeof( V_66 -> V_75 ) ) ;
memcpy ( F_21 ( V_67 , V_49 ,
V_83 . V_84 . V_85 ) ,
& V_64 -> V_75 , sizeof( V_64 -> V_75 ) ) ;
memcpy ( F_21 ( V_67 , V_45 ,
V_86 . V_84 . V_85 ) ,
& V_66 -> V_73 , sizeof( V_66 -> V_73 ) ) ;
memcpy ( F_21 ( V_67 , V_49 ,
V_86 . V_84 . V_85 ) ,
& V_64 -> V_73 , sizeof( V_64 -> V_73 ) ) ;
}
if ( V_51 == V_60 ) {
struct V_87 * V_64 =
F_25 ( V_44 -> V_53 ,
V_60 ,
V_44 -> V_64 ) ;
struct V_87 * V_66 =
F_25 ( V_44 -> V_53 ,
V_60 ,
V_44 -> V_66 ) ;
memcpy ( F_21 ( V_67 , V_45 ,
V_83 . V_88 . V_89 ) ,
& V_66 -> V_75 , sizeof( V_66 -> V_75 ) ) ;
memcpy ( F_21 ( V_67 , V_49 ,
V_83 . V_88 . V_89 ) ,
& V_64 -> V_75 , sizeof( V_64 -> V_75 ) ) ;
memcpy ( F_21 ( V_67 , V_45 ,
V_86 . V_88 . V_89 ) ,
& V_66 -> V_73 , sizeof( V_66 -> V_73 ) ) ;
memcpy ( F_21 ( V_67 , V_49 ,
V_86 . V_88 . V_89 ) ,
& V_64 -> V_73 , sizeof( V_64 -> V_73 ) ) ;
}
if ( F_24 ( V_44 -> V_53 , V_61 ) ) {
struct V_90 * V_64 =
F_25 ( V_44 -> V_53 ,
V_61 ,
V_44 -> V_64 ) ;
struct V_90 * V_66 =
F_25 ( V_44 -> V_53 ,
V_61 ,
V_44 -> V_66 ) ;
switch ( V_52 ) {
case V_91 :
F_26 ( V_67 , V_45 ,
V_92 , F_27 ( V_66 -> V_75 ) ) ;
F_26 ( V_67 , V_49 ,
V_92 , F_27 ( V_64 -> V_75 ) ) ;
F_26 ( V_67 , V_45 ,
V_93 , F_27 ( V_66 -> V_73 ) ) ;
F_26 ( V_67 , V_49 ,
V_93 , F_27 ( V_64 -> V_73 ) ) ;
break;
case V_94 :
F_26 ( V_67 , V_45 ,
V_95 , F_27 ( V_66 -> V_75 ) ) ;
F_26 ( V_67 , V_49 ,
V_95 , F_27 ( V_64 -> V_75 ) ) ;
F_26 ( V_67 , V_45 ,
V_96 , F_27 ( V_66 -> V_73 ) ) ;
F_26 ( V_67 , V_49 ,
V_96 , F_27 ( V_64 -> V_73 ) ) ;
break;
default:
F_7 ( V_3 -> V_30 ,
L_3 ) ;
return - V_97 ;
}
}
return 0 ;
}
static int F_29 ( struct V_2 * V_3 , struct V_98 * V_99 ,
T_1 * V_6 , T_1 * V_7 )
{
const struct V_100 * V_101 ;
F_30 ( V_102 ) ;
if ( F_31 ( V_99 ) )
return - V_97 ;
* V_7 = V_103 ;
* V_6 = 0 ;
F_32 ( V_99 , & V_102 ) ;
F_33 (a, &actions, list) {
if ( * V_6 )
return - V_97 ;
if ( F_34 ( V_101 ) ) {
* V_6 |= V_104 ;
if ( F_35 ( V_3 -> V_10 ,
V_105 . V_106 ) )
* V_6 |= V_23 ;
continue;
}
if ( F_36 ( V_101 ) ) {
T_1 V_107 = F_37 ( V_101 ) ;
if ( V_107 & ~ V_108 ) {
F_23 ( V_3 -> V_30 , L_4 ,
V_107 ) ;
return - V_97 ;
}
* V_7 = V_107 ;
* V_6 |= V_17 ;
continue;
}
return - V_97 ;
}
return 0 ;
}
static int F_38 ( struct V_2 * V_3 , struct V_98 * V_99 ,
struct V_35 * V_36 )
{
const struct V_100 * V_101 ;
F_30 ( V_102 ) ;
if ( F_31 ( V_99 ) )
return - V_97 ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_109 = V_3 -> V_110 ;
F_32 ( V_99 , & V_102 ) ;
F_33 (a, &actions, list) {
if ( F_34 ( V_101 ) ) {
V_36 -> V_6 |= V_104 |
V_23 ;
continue;
}
if ( F_39 ( V_101 ) ) {
int V_111 = F_40 ( V_101 ) ;
struct V_112 * V_113 ;
struct V_2 * V_114 ;
V_113 = F_41 ( F_42 ( V_3 -> V_30 ) , V_111 ) ;
if ( ! F_43 ( V_3 -> V_30 , V_113 ) ) {
F_44 ( L_5 ,
V_3 -> V_30 -> V_115 , V_113 -> V_115 ) ;
return - V_97 ;
}
V_36 -> V_6 |= V_17 ;
V_114 = F_45 ( V_113 ) ;
V_36 -> V_116 = V_114 -> V_110 ;
continue;
}
if ( F_46 ( V_101 ) ) {
if ( F_47 ( V_101 ) == V_117 ) {
V_36 -> V_6 |= V_118 ;
} else if ( F_47 ( V_101 ) == V_119 ) {
if ( F_48 ( V_101 ) != F_49 ( V_120 ) )
return - V_62 ;
V_36 -> V_6 |= V_121 ;
V_36 -> V_21 = F_50 ( V_101 ) ;
}
continue;
}
return - V_97 ;
}
return 0 ;
}
int F_51 ( struct V_2 * V_3 , T_4 V_122 ,
struct V_43 * V_44 )
{
struct V_123 * V_25 = & V_3 -> V_20 . V_25 ;
int V_40 = 0 ;
bool V_124 = false ;
T_1 V_7 , V_6 ;
struct V_125 * V_126 ;
struct V_4 * V_5 ;
struct V_1 * V_127 = NULL ;
struct V_35 * V_128 = NULL ;
struct V_37 * V_38 = V_3 -> V_10 -> V_3 . V_39 ;
if ( V_38 && V_38 -> V_41 == V_42 )
V_124 = true ;
V_126 = F_52 ( & V_25 -> V_129 , & V_44 -> V_130 ,
V_25 -> V_131 ) ;
if ( V_126 ) {
V_127 = V_126 -> V_15 ;
V_128 = V_126 -> V_36 ;
} else {
if ( V_124 )
V_126 = F_53 ( sizeof( * V_126 ) + sizeof( struct V_35 ) ,
V_132 ) ;
else
V_126 = F_53 ( sizeof( * V_126 ) , V_132 ) ;
}
V_5 = F_54 ( sizeof( * V_5 ) ) ;
if ( ! V_5 || ! V_126 ) {
V_40 = - V_133 ;
goto V_134;
}
V_126 -> V_130 = V_44 -> V_130 ;
V_40 = F_20 ( V_3 , V_5 , V_44 ) ;
if ( V_40 < 0 )
goto V_134;
if ( V_124 ) {
V_126 -> V_36 = (struct V_35 * ) ( V_126 + 1 ) ;
V_40 = F_38 ( V_3 , V_44 -> V_99 , V_126 -> V_36 ) ;
if ( V_40 < 0 )
goto V_134;
V_126 -> V_15 = F_11 ( V_3 , V_5 , V_126 -> V_36 ) ;
} else {
V_40 = F_29 ( V_3 , V_44 -> V_99 , & V_6 , & V_7 ) ;
if ( V_40 < 0 )
goto V_134;
V_126 -> V_15 = F_1 ( V_3 , V_5 , V_6 , V_7 ) ;
}
if ( F_3 ( V_126 -> V_15 ) ) {
V_40 = F_55 ( V_126 -> V_15 ) ;
goto V_134;
}
V_40 = F_56 ( & V_25 -> V_129 , & V_126 -> V_135 ,
V_25 -> V_131 ) ;
if ( V_40 )
goto V_136;
if ( V_127 )
F_15 ( V_3 , V_127 , V_128 ) ;
goto V_137;
V_136:
F_18 ( V_126 -> V_15 ) ;
V_134:
if ( ! V_127 )
F_57 ( V_126 ) ;
V_137:
F_58 ( V_5 ) ;
return V_40 ;
}
int F_59 ( struct V_2 * V_3 ,
struct V_43 * V_44 )
{
struct V_125 * V_126 ;
struct V_123 * V_25 = & V_3 -> V_20 . V_25 ;
V_126 = F_52 ( & V_25 -> V_129 , & V_44 -> V_130 ,
V_25 -> V_131 ) ;
if ( ! V_126 )
return - V_97 ;
F_60 ( & V_25 -> V_129 , & V_126 -> V_135 , V_25 -> V_131 ) ;
F_15 ( V_3 , V_126 -> V_15 , V_126 -> V_36 ) ;
F_57 ( V_126 ) ;
return 0 ;
}
int F_61 ( struct V_2 * V_3 ,
struct V_43 * V_44 )
{
struct V_123 * V_25 = & V_3 -> V_20 . V_25 ;
struct V_125 * V_126 ;
struct V_100 * V_101 ;
struct V_13 * V_14 ;
F_30 ( V_102 ) ;
T_5 V_138 ;
T_5 V_139 ;
T_5 V_140 ;
V_126 = F_52 ( & V_25 -> V_129 , & V_44 -> V_130 ,
V_25 -> V_131 ) ;
if ( ! V_126 )
return - V_97 ;
V_14 = F_16 ( V_126 -> V_15 ) ;
if ( ! V_14 )
return 0 ;
F_62 ( V_14 , & V_138 , & V_139 , & V_140 ) ;
F_32 ( V_44 -> V_99 , & V_102 ) ;
F_33 (a, &actions, list)
F_63 ( V_101 , V_138 , V_139 , V_140 ) ;
return 0 ;
}
int F_64 ( struct V_2 * V_3 )
{
struct V_123 * V_25 = & V_3 -> V_20 . V_25 ;
V_25 -> V_131 = V_141 ;
return F_65 ( & V_25 -> V_129 , & V_25 -> V_131 ) ;
}
static void F_66 ( void * V_142 , void * V_143 )
{
struct V_125 * V_126 = V_142 ;
struct V_2 * V_3 = V_143 ;
F_15 ( V_3 , V_126 -> V_15 , V_126 -> V_36 ) ;
F_57 ( V_126 ) ;
}
void F_67 ( struct V_2 * V_3 )
{
struct V_123 * V_25 = & V_3 -> V_20 . V_25 ;
F_68 ( & V_25 -> V_129 , F_66 , V_3 ) ;
if ( ! F_5 ( V_25 -> V_22 ) ) {
F_9 ( V_25 -> V_22 ) ;
V_25 -> V_22 = NULL ;
}
}
