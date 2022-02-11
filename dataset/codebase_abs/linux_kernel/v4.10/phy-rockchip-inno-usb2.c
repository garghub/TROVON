static inline int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , bool V_5 )
{
unsigned int V_6 , V_7 , V_8 ;
V_8 = V_5 ? V_4 -> V_9 : V_4 -> V_10 ;
V_7 = F_2 ( V_4 -> V_11 , V_4 -> V_12 ) ;
V_6 = ( V_8 << V_4 -> V_12 ) | ( V_7 << V_13 ) ;
return F_3 ( V_2 -> V_14 , V_4 -> V_15 , V_6 ) ;
}
static inline bool F_4 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_16 ;
unsigned int V_8 , V_17 ;
unsigned int V_7 = F_2 ( V_4 -> V_11 , V_4 -> V_12 ) ;
V_16 = F_5 ( V_2 -> V_14 , V_4 -> V_15 , & V_17 ) ;
if ( V_16 )
return false ;
V_8 = ( V_17 & V_7 ) >> V_4 -> V_12 ;
return V_8 == V_4 -> V_9 ;
}
static int F_6 ( struct V_18 * V_19 )
{
struct V_1 * V_2 =
F_7 ( V_19 , struct V_1 , V_20 ) ;
int V_16 ;
if ( ! F_4 ( V_2 , & V_2 -> V_21 -> V_22 ) ) {
V_16 = F_1 ( V_2 , & V_2 -> V_21 -> V_22 , true ) ;
if ( V_16 )
return V_16 ;
F_8 ( 1200 , 1300 ) ;
}
return 0 ;
}
static void F_9 ( struct V_18 * V_19 )
{
struct V_1 * V_2 =
F_7 ( V_19 , struct V_1 , V_20 ) ;
F_1 ( V_2 , & V_2 -> V_21 -> V_22 , false ) ;
}
static int F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_2 =
F_7 ( V_19 , struct V_1 , V_20 ) ;
return F_4 ( V_2 , & V_2 -> V_21 -> V_22 ) ;
}
static unsigned long
F_11 ( struct V_18 * V_19 ,
unsigned long V_23 )
{
return 480000000 ;
}
static void F_12 ( void * V_24 )
{
struct V_1 * V_2 = V_24 ;
F_13 ( V_2 -> V_25 -> V_26 ) ;
F_14 ( V_2 -> V_27 ) ;
}
static int
F_15 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = V_2 -> V_25 -> V_26 ;
struct V_30 V_31 ;
const char * V_32 ;
int V_16 ;
V_31 . V_33 = 0 ;
V_31 . V_34 = L_1 ;
V_31 . V_35 = & V_36 ;
F_16 ( V_29 , L_2 , & V_31 . V_34 ) ;
if ( V_2 -> V_37 ) {
V_32 = F_17 ( V_2 -> V_37 ) ;
V_31 . V_38 = & V_32 ;
V_31 . V_39 = 1 ;
} else {
V_31 . V_38 = NULL ;
V_31 . V_39 = 0 ;
}
V_2 -> V_20 . V_31 = & V_31 ;
V_2 -> V_27 = F_18 ( V_2 -> V_25 , & V_2 -> V_20 ) ;
if ( F_19 ( V_2 -> V_27 ) ) {
V_16 = F_20 ( V_2 -> V_27 ) ;
goto V_40;
}
V_16 = F_21 ( V_29 , V_41 , V_2 -> V_27 ) ;
if ( V_16 < 0 )
goto V_42;
V_16 = F_22 ( V_2 -> V_25 , F_12 ,
V_2 ) ;
if ( V_16 < 0 )
goto V_43;
return 0 ;
V_43:
F_13 ( V_29 ) ;
V_42:
F_14 ( V_2 -> V_27 ) ;
V_40:
return V_16 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_16 ;
struct V_28 * V_29 = V_2 -> V_25 -> V_26 ;
struct V_44 * V_45 ;
if ( F_24 ( V_29 , L_3 ) ) {
V_45 = F_25 ( V_2 -> V_25 , 0 ) ;
if ( F_19 ( V_45 ) ) {
if ( F_20 ( V_45 ) != - V_46 )
F_26 ( V_2 -> V_25 , L_4 ) ;
return F_20 ( V_45 ) ;
}
} else {
V_45 = F_27 ( V_2 -> V_25 ,
V_47 ) ;
if ( F_19 ( V_45 ) )
return - V_48 ;
V_16 = F_28 ( V_2 -> V_25 , V_45 ) ;
if ( V_16 ) {
F_26 ( V_2 -> V_25 , L_5 ) ;
return V_16 ;
}
}
V_2 -> V_45 = V_45 ;
return 0 ;
}
static int F_29 ( struct V_49 * V_49 )
{
struct V_50 * V_51 = F_30 ( V_49 ) ;
struct V_1 * V_2 = F_31 ( V_49 -> V_25 . V_52 ) ;
int V_16 = 0 ;
F_32 ( & V_51 -> V_53 ) ;
if ( V_51 -> V_54 == V_55 ) {
if ( V_51 -> V_56 != V_57 ) {
V_16 = F_1 ( V_2 ,
& V_51 -> V_58 -> V_59 ,
true ) ;
if ( V_16 )
goto V_60;
V_16 = F_1 ( V_2 ,
& V_51 -> V_58 -> V_61 ,
true ) ;
if ( V_16 )
goto V_60;
F_33 ( & V_51 -> V_62 ,
V_63 ) ;
} else {
F_34 ( & V_51 -> V_49 -> V_25 , L_6 , V_51 -> V_56 ) ;
}
} else if ( V_51 -> V_54 == V_64 ) {
V_16 = F_1 ( V_2 , & V_51 -> V_58 -> V_65 , true ) ;
if ( V_16 )
goto V_60;
V_16 = F_1 ( V_2 , & V_51 -> V_58 -> V_66 , true ) ;
if ( V_16 )
goto V_60;
F_33 ( & V_51 -> V_67 , V_68 ) ;
}
V_60:
F_35 ( & V_51 -> V_53 ) ;
return V_16 ;
}
static int F_36 ( struct V_49 * V_49 )
{
struct V_50 * V_51 = F_30 ( V_49 ) ;
struct V_1 * V_2 = F_31 ( V_49 -> V_25 . V_52 ) ;
int V_16 ;
F_34 ( & V_51 -> V_49 -> V_25 , L_7 ) ;
if ( ! V_51 -> V_69 )
return 0 ;
V_16 = F_37 ( V_2 -> V_27 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_1 ( V_2 , & V_51 -> V_58 -> V_70 , false ) ;
if ( V_16 )
return V_16 ;
V_51 -> V_69 = false ;
return 0 ;
}
static int F_38 ( struct V_49 * V_49 )
{
struct V_50 * V_51 = F_30 ( V_49 ) ;
struct V_1 * V_2 = F_31 ( V_49 -> V_25 . V_52 ) ;
int V_16 ;
F_34 ( & V_51 -> V_49 -> V_25 , L_8 ) ;
if ( V_51 -> V_69 )
return 0 ;
V_16 = F_1 ( V_2 , & V_51 -> V_58 -> V_70 , true ) ;
if ( V_16 )
return V_16 ;
V_51 -> V_69 = true ;
F_39 ( V_2 -> V_27 ) ;
return 0 ;
}
static int F_40 ( struct V_49 * V_49 )
{
struct V_50 * V_51 = F_30 ( V_49 ) ;
if ( V_51 -> V_54 == V_55 &&
V_51 -> V_56 != V_57 ) {
F_41 ( & V_51 -> V_62 ) ;
F_41 ( & V_51 -> V_71 ) ;
} else if ( V_51 -> V_54 == V_64 )
F_41 ( & V_51 -> V_67 ) ;
return 0 ;
}
static void F_42 ( struct V_72 * V_73 )
{
struct V_50 * V_51 =
F_7 ( V_73 , struct V_50 ,
V_62 . V_73 ) ;
struct V_1 * V_2 = F_31 ( V_51 -> V_49 -> V_25 . V_52 ) ;
static unsigned int V_74 ;
unsigned long V_75 ;
bool V_76 , V_77 , V_78 ;
if ( V_51 -> V_79 )
V_76 =
F_4 ( V_2 , & V_51 -> V_58 -> V_79 ) ;
else
V_76 =
F_4 ( V_2 , & V_51 -> V_58 -> V_80 ) ;
V_77 = false ;
V_78 = false ;
V_75 = V_63 ;
F_34 ( & V_51 -> V_49 -> V_25 , L_9 ,
F_43 ( V_51 -> V_81 ) ) ;
switch ( V_51 -> V_81 ) {
case V_82 :
V_51 -> V_81 = V_83 ;
if ( ! V_76 )
F_38 ( V_51 -> V_49 ) ;
case V_83 :
if ( F_44 ( V_2 -> V_45 , V_84 ) > 0 ) {
F_34 ( & V_51 -> V_49 -> V_25 , L_10 ) ;
V_51 -> V_81 = V_85 ;
F_36 ( V_51 -> V_49 ) ;
return;
} else if ( V_76 ) {
F_34 ( & V_51 -> V_49 -> V_25 , L_11 ) ;
switch ( V_2 -> V_86 ) {
case V_87 :
F_33 ( & V_51 -> V_71 , 0 ) ;
return;
case V_88 :
switch ( V_2 -> V_89 ) {
case V_90 :
F_34 ( & V_51 -> V_49 -> V_25 ,
L_12 ) ;
F_36 ( V_51 -> V_49 ) ;
V_51 -> V_81 = V_91 ;
V_78 = true ;
V_77 = true ;
V_74 = V_92 ;
break;
case V_93 :
F_34 ( & V_51 -> V_49 -> V_25 ,
L_13 ) ;
F_38 ( V_51 -> V_49 ) ;
V_78 = true ;
V_77 = true ;
V_74 = V_94 ;
break;
case V_95 :
F_34 ( & V_51 -> V_49 -> V_25 ,
L_14 ) ;
F_36 ( V_51 -> V_49 ) ;
V_51 -> V_81 = V_91 ;
V_78 = true ;
V_77 = true ;
V_74 = V_96 ;
break;
default:
break;
}
break;
default:
break;
}
} else {
V_78 = true ;
V_2 -> V_86 = V_87 ;
V_2 -> V_89 = V_97 ;
}
if ( V_51 -> V_98 != V_76 ) {
V_51 -> V_98 = V_76 ;
if ( V_78 && V_2 -> V_45 )
F_45 ( V_2 -> V_45 ,
V_74 , V_76 ) ;
}
break;
case V_91 :
if ( ! V_76 ) {
F_34 ( & V_51 -> V_49 -> V_25 , L_15 ) ;
V_2 -> V_86 = V_87 ;
V_2 -> V_89 = V_97 ;
V_51 -> V_81 = V_83 ;
V_75 = 0 ;
F_38 ( V_51 -> V_49 ) ;
}
V_77 = true ;
break;
case V_85 :
if ( F_44 ( V_2 -> V_45 , V_84 ) == 0 ) {
F_34 ( & V_51 -> V_49 -> V_25 , L_16 ) ;
V_51 -> V_81 = V_83 ;
F_38 ( V_51 -> V_49 ) ;
}
break;
default:
break;
}
if ( V_77 )
F_33 ( & V_51 -> V_62 , V_75 ) ;
}
static const char * F_46 ( enum V_99 V_89 )
{
switch ( V_89 ) {
case V_90 :
return L_17 ;
case V_93 :
return L_18 ;
case V_95 :
return L_19 ;
default:
return L_20 ;
}
}
static void F_47 ( struct V_1 * V_2 ,
bool V_5 )
{
F_1 ( V_2 , & V_2 -> V_21 -> V_100 . V_101 , V_5 ) ;
F_1 ( V_2 , & V_2 -> V_21 -> V_100 . V_102 , V_5 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
bool V_5 )
{
F_1 ( V_2 , & V_2 -> V_21 -> V_100 . V_103 , V_5 ) ;
F_1 ( V_2 , & V_2 -> V_21 -> V_100 . V_104 , V_5 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
bool V_5 )
{
F_1 ( V_2 , & V_2 -> V_21 -> V_100 . V_105 , V_5 ) ;
F_1 ( V_2 , & V_2 -> V_21 -> V_100 . V_106 , V_5 ) ;
}
static void F_50 ( struct V_72 * V_73 )
{
struct V_50 * V_51 =
F_7 ( V_73 , struct V_50 , V_71 . V_73 ) ;
struct V_1 * V_2 = F_31 ( V_51 -> V_49 -> V_25 . V_52 ) ;
bool V_107 , V_108 , V_109 ;
unsigned long V_75 ;
F_34 ( & V_51 -> V_49 -> V_25 , L_21 ,
V_2 -> V_86 ) ;
switch ( V_2 -> V_86 ) {
case V_87 :
if ( ! V_51 -> V_69 )
F_38 ( V_51 -> V_49 ) ;
F_1 ( V_2 , & V_2 -> V_21 -> V_100 . V_110 , false ) ;
F_47 ( V_2 , true ) ;
V_2 -> V_86 = V_111 ;
V_2 -> V_112 = 0 ;
V_75 = V_113 ;
break;
case V_111 :
V_107 = F_4 ( V_2 , & V_2 -> V_21 -> V_100 . V_114 ) ;
V_108 = ++ V_2 -> V_112 == V_115 ;
if ( V_107 || V_108 ) {
F_47 ( V_2 , false ) ;
F_48 ( V_2 , true ) ;
V_75 = V_116 ;
V_2 -> V_86 = V_117 ;
} else {
V_75 = V_113 ;
}
break;
case V_117 :
V_109 = F_4 ( V_2 , & V_2 -> V_21 -> V_100 . V_118 ) ;
F_48 ( V_2 , false ) ;
if ( V_109 ) {
F_49 ( V_2 , true ) ;
V_75 = V_119 ;
V_2 -> V_86 = V_120 ;
} else {
if ( V_2 -> V_112 == V_115 ) {
V_2 -> V_89 = V_93 ;
V_2 -> V_86 = V_88 ;
V_75 = 0 ;
} else {
V_2 -> V_89 = V_90 ;
V_2 -> V_86 = V_88 ;
V_75 = 0 ;
}
}
break;
case V_120 :
V_109 = F_4 ( V_2 , & V_2 -> V_21 -> V_100 . V_121 ) ;
F_49 ( V_2 , false ) ;
if ( V_109 )
V_2 -> V_89 = V_93 ;
else
V_2 -> V_89 = V_95 ;
case V_122 :
V_2 -> V_86 = V_88 ;
V_75 = 0 ;
case V_88 :
F_1 ( V_2 , & V_2 -> V_21 -> V_100 . V_110 , true ) ;
F_42 ( & V_51 -> V_62 . V_73 ) ;
F_51 ( & V_51 -> V_49 -> V_25 , L_22 ,
F_46 ( V_2 -> V_89 ) ) ;
return;
default:
return;
}
F_33 ( & V_51 -> V_71 , V_75 ) ;
}
static void F_52 ( struct V_72 * V_73 )
{
struct V_50 * V_51 =
F_7 ( V_73 , struct V_50 , V_67 . V_73 ) ;
struct V_1 * V_2 = F_31 ( V_51 -> V_49 -> V_25 . V_52 ) ;
unsigned int V_123 = V_51 -> V_58 -> V_124 . V_11 -
V_51 -> V_58 -> V_124 . V_12 + 1 ;
unsigned int V_125 , V_126 , V_81 ;
unsigned int V_127 , V_128 ;
int V_16 ;
F_32 ( & V_51 -> V_53 ) ;
V_16 = F_5 ( V_2 -> V_14 , V_51 -> V_58 -> V_129 . V_15 , & V_125 ) ;
if ( V_16 < 0 )
goto V_130;
V_16 = F_5 ( V_2 -> V_14 , V_51 -> V_58 -> V_124 . V_15 ,
& V_126 ) ;
if ( V_16 < 0 )
goto V_130;
V_128 = F_2 ( V_51 -> V_58 -> V_124 . V_11 ,
V_51 -> V_58 -> V_124 . V_12 ) ;
V_127 = F_2 ( V_51 -> V_58 -> V_129 . V_11 ,
V_51 -> V_58 -> V_129 . V_12 ) ;
V_81 = ( ( V_126 & V_128 ) >> V_51 -> V_58 -> V_124 . V_12 ) |
( ( ( V_125 & V_127 ) >> V_51 -> V_58 -> V_129 . V_12 ) << V_123 ) ;
switch ( V_81 ) {
case V_131 :
F_34 ( & V_51 -> V_49 -> V_25 , L_23 ) ;
break;
case V_132 :
if ( ! V_51 -> V_69 ) {
F_34 ( & V_51 -> V_49 -> V_25 , L_24 ) ;
break;
}
case V_133 :
if ( V_51 -> V_69 ) {
F_34 ( & V_51 -> V_49 -> V_25 , L_25 ) ;
F_36 ( V_51 -> V_49 ) ;
V_51 -> V_69 = false ;
} else {
F_34 ( & V_51 -> V_49 -> V_25 , L_24 ) ;
}
break;
case V_134 :
if ( ! V_51 -> V_69 ) {
F_34 ( & V_51 -> V_49 -> V_25 , L_26 ) ;
F_38 ( V_51 -> V_49 ) ;
V_51 -> V_69 = true ;
}
F_1 ( V_2 , & V_51 -> V_58 -> V_65 , true ) ;
F_1 ( V_2 , & V_51 -> V_58 -> V_66 , true ) ;
F_35 ( & V_51 -> V_53 ) ;
return;
default:
F_34 ( & V_51 -> V_49 -> V_25 , L_27 ) ;
break;
}
V_130:
F_35 ( & V_51 -> V_53 ) ;
F_33 ( & V_51 -> V_67 , V_68 ) ;
}
static T_1 F_53 ( int V_135 , void * V_24 )
{
struct V_50 * V_51 = V_24 ;
struct V_1 * V_2 = F_31 ( V_51 -> V_49 -> V_25 . V_52 ) ;
if ( ! F_4 ( V_2 , & V_51 -> V_58 -> V_136 ) )
return V_137 ;
F_32 ( & V_51 -> V_53 ) ;
F_1 ( V_2 , & V_51 -> V_58 -> V_66 , false ) ;
F_1 ( V_2 , & V_51 -> V_58 -> V_65 , true ) ;
F_35 ( & V_51 -> V_53 ) ;
if ( V_51 -> V_69 && V_51 -> V_54 == V_64 )
F_52 ( & V_51 -> V_67 . V_73 ) ;
return V_138 ;
}
static T_1 F_54 ( int V_135 , void * V_24 )
{
struct V_50 * V_51 = V_24 ;
struct V_1 * V_2 = F_31 ( V_51 -> V_49 -> V_25 . V_52 ) ;
if ( ! F_4 ( V_2 , & V_51 -> V_58 -> V_139 ) )
return V_137 ;
F_32 ( & V_51 -> V_53 ) ;
F_1 ( V_2 , & V_51 -> V_58 -> V_59 , true ) ;
F_35 ( & V_51 -> V_53 ) ;
F_42 ( & V_51 -> V_62 . V_73 ) ;
return V_138 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
struct V_28 * V_140 )
{
int V_16 ;
V_51 -> V_54 = V_64 ;
V_51 -> V_58 = & V_2 -> V_21 -> V_141 [ V_64 ] ;
V_51 -> V_69 = true ;
F_56 ( & V_51 -> V_53 ) ;
F_57 ( & V_51 -> V_67 , F_52 ) ;
V_51 -> V_142 = F_58 ( V_140 , L_28 ) ;
if ( V_51 -> V_142 < 0 ) {
F_26 ( V_2 -> V_25 , L_29 ) ;
return V_51 -> V_142 ;
}
V_16 = F_59 ( V_2 -> V_25 , V_51 -> V_142 , NULL ,
F_53 ,
V_143 ,
L_30 , V_51 ) ;
if ( V_16 ) {
F_26 ( V_2 -> V_25 , L_31 ) ;
return V_16 ;
}
return 0 ;
}
static int F_60 ( struct V_144 * V_145 ,
unsigned long V_146 , void * V_147 )
{
struct V_50 * V_51 =
F_7 ( V_145 , struct V_50 , V_148 ) ;
F_33 ( & V_51 -> V_62 , V_63 ) ;
return V_149 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
struct V_28 * V_140 )
{
int V_16 ;
V_51 -> V_54 = V_55 ;
V_51 -> V_58 = & V_2 -> V_21 -> V_141 [ V_55 ] ;
V_51 -> V_81 = V_82 ;
V_51 -> V_69 = true ;
V_51 -> V_98 = false ;
F_56 ( & V_51 -> V_53 ) ;
V_51 -> V_56 = F_62 ( V_140 , - 1 ) ;
if ( V_51 -> V_56 == V_57 ) {
V_16 = 0 ;
goto V_60;
}
F_57 ( & V_51 -> V_71 , F_50 ) ;
F_57 ( & V_51 -> V_62 , F_42 ) ;
V_51 -> V_79 =
F_24 ( V_140 , L_32 ) ;
V_51 -> V_150 = F_58 ( V_140 , L_33 ) ;
if ( V_51 -> V_150 < 0 ) {
F_26 ( V_2 -> V_25 , L_34 ) ;
V_16 = V_51 -> V_150 ;
goto V_60;
}
V_16 = F_59 ( V_2 -> V_25 , V_51 -> V_150 , NULL ,
F_54 ,
V_143 ,
L_35 , V_51 ) ;
if ( V_16 ) {
F_26 ( V_2 -> V_25 , L_36 ) ;
goto V_60;
}
if ( ! F_19 ( V_2 -> V_45 ) ) {
V_51 -> V_148 . V_151 = F_60 ;
V_16 = F_63 ( V_2 -> V_45 , V_84 ,
& V_51 -> V_148 ) ;
if ( V_16 )
F_26 ( V_2 -> V_25 , L_37 ) ;
}
V_60:
return V_16 ;
}
static int F_64 ( struct V_152 * V_153 )
{
struct V_154 * V_25 = & V_153 -> V_25 ;
struct V_28 * V_155 = V_25 -> V_26 ;
struct V_28 * V_140 ;
struct V_156 * V_157 ;
struct V_1 * V_2 ;
const struct V_158 * V_159 ;
const struct V_160 * V_161 ;
unsigned int V_4 ;
int V_162 , V_16 ;
V_2 = F_65 ( V_25 , sizeof( * V_2 ) , V_163 ) ;
if ( ! V_2 )
return - V_48 ;
V_161 = F_66 ( V_25 -> V_164 -> V_165 , V_25 ) ;
if ( ! V_161 || ! V_161 -> V_24 ) {
F_26 ( V_25 , L_38 ) ;
return - V_166 ;
}
if ( ! V_25 -> V_52 || ! V_25 -> V_52 -> V_26 )
return - V_166 ;
V_2 -> V_14 = F_67 ( V_25 -> V_52 -> V_26 ) ;
if ( F_19 ( V_2 -> V_14 ) )
return F_20 ( V_2 -> V_14 ) ;
if ( F_68 ( V_155 , L_39 , & V_4 ) ) {
F_26 ( V_25 , L_40 ,
V_155 -> V_34 ) ;
return - V_166 ;
}
V_2 -> V_25 = V_25 ;
V_159 = V_161 -> V_24 ;
V_2 -> V_86 = V_87 ;
V_2 -> V_89 = V_97 ;
F_69 ( V_153 , V_2 ) ;
V_16 = F_23 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_162 = 0 ;
while ( V_159 [ V_162 ] . V_4 ) {
if ( V_159 [ V_162 ] . V_4 == V_4 ) {
V_2 -> V_21 = & V_159 [ V_162 ] ;
break;
}
++ V_162 ;
}
if ( ! V_2 -> V_21 ) {
F_26 ( V_25 , L_41 ,
V_155 -> V_34 ) ;
return - V_166 ;
}
V_2 -> V_37 = F_70 ( V_155 , L_42 ) ;
if ( ! F_19 ( V_2 -> V_37 ) ) {
F_37 ( V_2 -> V_37 ) ;
} else {
F_51 ( & V_153 -> V_25 , L_43 ) ;
V_2 -> V_37 = NULL ;
}
V_16 = F_15 ( V_2 ) ;
if ( V_16 ) {
F_26 ( V_25 , L_44 ) ;
goto V_167;
}
V_162 = 0 ;
F_71 (np, child_np) {
struct V_50 * V_51 = & V_2 -> V_168 [ V_162 ] ;
struct V_49 * V_49 ;
if ( F_72 ( V_140 -> V_34 , L_45 ) &&
F_72 ( V_140 -> V_34 , L_46 ) )
goto V_169;
V_49 = F_73 ( V_25 , V_140 , & V_170 ) ;
if ( F_19 ( V_49 ) ) {
F_26 ( V_25 , L_47 ) ;
V_16 = F_20 ( V_49 ) ;
goto V_171;
}
V_51 -> V_49 = V_49 ;
F_74 ( V_51 -> V_49 , V_51 ) ;
if ( ! F_72 ( V_140 -> V_34 , L_45 ) ) {
V_16 = F_55 ( V_2 , V_51 ,
V_140 ) ;
if ( V_16 )
goto V_171;
} else {
V_16 = F_61 ( V_2 , V_51 ,
V_140 ) ;
if ( V_16 )
goto V_171;
}
V_169:
if ( ++ V_162 >= V_2 -> V_21 -> V_172 )
break;
}
V_157 = F_75 ( V_25 , V_173 ) ;
return F_76 ( V_157 ) ;
V_171:
F_77 ( V_140 ) ;
V_167:
if ( V_2 -> V_37 ) {
F_39 ( V_2 -> V_37 ) ;
F_78 ( V_2 -> V_37 ) ;
}
return V_16 ;
}
