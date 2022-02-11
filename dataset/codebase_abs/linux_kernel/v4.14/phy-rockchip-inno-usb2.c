static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 == NULL ? V_3 -> V_5 : V_3 -> V_4 ;
}
static inline int F_2 ( struct V_1 * V_6 ,
const struct V_7 * V_8 , bool V_9 )
{
unsigned int V_10 , V_11 , V_12 ;
V_12 = V_9 ? V_8 -> V_13 : V_8 -> V_14 ;
V_11 = F_3 ( V_8 -> V_15 , V_8 -> V_16 ) ;
V_10 = ( V_12 << V_8 -> V_16 ) | ( V_11 << V_17 ) ;
return F_4 ( V_6 , V_8 -> V_18 , V_10 ) ;
}
static inline bool F_5 ( struct V_1 * V_6 ,
const struct V_7 * V_8 )
{
int V_19 ;
unsigned int V_12 , V_20 ;
unsigned int V_11 = F_3 ( V_8 -> V_15 , V_8 -> V_16 ) ;
V_19 = F_6 ( V_6 , V_8 -> V_18 , & V_20 ) ;
if ( V_19 )
return false ;
V_12 = ( V_20 & V_11 ) >> V_8 -> V_16 ;
return V_12 == V_8 -> V_13 ;
}
static int F_7 ( struct V_21 * V_22 )
{
struct V_2 * V_3 =
F_8 ( V_22 , struct V_2 , V_23 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_19 ;
if ( ! F_5 ( V_6 , & V_3 -> V_24 -> V_25 ) ) {
V_19 = F_2 ( V_6 , & V_3 -> V_24 -> V_25 , true ) ;
if ( V_19 )
return V_19 ;
F_9 ( 1200 , 1300 ) ;
}
return 0 ;
}
static void F_10 ( struct V_21 * V_22 )
{
struct V_2 * V_3 =
F_8 ( V_22 , struct V_2 , V_23 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_2 ( V_6 , & V_3 -> V_24 -> V_25 , false ) ;
}
static int F_11 ( struct V_21 * V_22 )
{
struct V_2 * V_3 =
F_8 ( V_22 , struct V_2 , V_23 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_5 ( V_6 , & V_3 -> V_24 -> V_25 ) ;
}
static unsigned long
F_12 ( struct V_21 * V_22 ,
unsigned long V_26 )
{
return 480000000 ;
}
static void F_13 ( void * V_27 )
{
struct V_2 * V_3 = V_27 ;
F_14 ( V_3 -> V_28 -> V_29 ) ;
F_15 ( V_3 -> V_30 ) ;
}
static int
F_16 ( struct V_2 * V_3 )
{
struct V_31 * V_32 = V_3 -> V_28 -> V_29 ;
struct V_33 V_34 ;
const char * V_35 ;
int V_19 ;
V_34 . V_36 = 0 ;
V_34 . V_37 = L_1 ;
V_34 . V_38 = & V_39 ;
F_17 ( V_32 , L_2 , & V_34 . V_37 ) ;
if ( V_3 -> V_40 ) {
V_35 = F_18 ( V_3 -> V_40 ) ;
V_34 . V_41 = & V_35 ;
V_34 . V_42 = 1 ;
} else {
V_34 . V_41 = NULL ;
V_34 . V_42 = 0 ;
}
V_3 -> V_23 . V_34 = & V_34 ;
V_3 -> V_30 = F_19 ( V_3 -> V_28 , & V_3 -> V_23 ) ;
if ( F_20 ( V_3 -> V_30 ) ) {
V_19 = F_21 ( V_3 -> V_30 ) ;
goto V_43;
}
V_19 = F_22 ( V_32 , V_44 , V_3 -> V_30 ) ;
if ( V_19 < 0 )
goto V_45;
V_19 = F_23 ( V_3 -> V_28 , F_13 ,
V_3 ) ;
if ( V_19 < 0 )
goto V_46;
return 0 ;
V_46:
F_14 ( V_32 ) ;
V_45:
F_15 ( V_3 -> V_30 ) ;
V_43:
return V_19 ;
}
static int F_24 ( struct V_2 * V_3 )
{
int V_19 ;
struct V_31 * V_32 = V_3 -> V_28 -> V_29 ;
struct V_47 * V_48 ;
if ( F_25 ( V_32 , L_3 ) ) {
V_48 = F_26 ( V_3 -> V_28 , 0 ) ;
if ( F_20 ( V_48 ) ) {
if ( F_21 ( V_48 ) != - V_49 )
F_27 ( V_3 -> V_28 , L_4 ) ;
return F_21 ( V_48 ) ;
}
} else {
V_48 = F_28 ( V_3 -> V_28 ,
V_50 ) ;
if ( F_20 ( V_48 ) )
return - V_51 ;
V_19 = F_29 ( V_3 -> V_28 , V_48 ) ;
if ( V_19 ) {
F_27 ( V_3 -> V_28 , L_5 ) ;
return V_19 ;
}
}
V_3 -> V_48 = V_48 ;
return 0 ;
}
static int F_30 ( struct V_52 * V_52 )
{
struct V_53 * V_54 = F_31 ( V_52 ) ;
struct V_2 * V_3 = F_32 ( V_52 -> V_28 . V_55 ) ;
int V_19 = 0 ;
F_33 ( & V_54 -> V_56 ) ;
if ( V_54 -> V_57 == V_58 ) {
if ( V_54 -> V_59 != V_60 &&
V_54 -> V_59 != V_61 ) {
V_19 = F_2 ( V_3 -> V_5 ,
& V_54 -> V_62 -> V_63 ,
true ) ;
if ( V_19 )
goto V_64;
V_19 = F_2 ( V_3 -> V_5 ,
& V_54 -> V_62 -> V_65 ,
true ) ;
if ( V_19 )
goto V_64;
F_34 ( & V_54 -> V_66 ,
V_67 * 3 ) ;
} else {
F_35 ( & V_54 -> V_52 -> V_28 , L_6 , V_54 -> V_59 ) ;
}
} else if ( V_54 -> V_57 == V_68 ) {
V_19 = F_2 ( V_3 -> V_5 ,
& V_54 -> V_62 -> V_69 , true ) ;
if ( V_19 )
goto V_64;
V_19 = F_2 ( V_3 -> V_5 ,
& V_54 -> V_62 -> V_70 , true ) ;
if ( V_19 )
goto V_64;
F_34 ( & V_54 -> V_71 , V_72 ) ;
}
V_64:
F_36 ( & V_54 -> V_56 ) ;
return V_19 ;
}
static int F_37 ( struct V_52 * V_52 )
{
struct V_53 * V_54 = F_31 ( V_52 ) ;
struct V_2 * V_3 = F_32 ( V_52 -> V_28 . V_55 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_19 ;
F_35 ( & V_54 -> V_52 -> V_28 , L_7 ) ;
if ( ! V_54 -> V_73 )
return 0 ;
V_19 = F_38 ( V_3 -> V_30 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_2 ( V_6 , & V_54 -> V_62 -> V_74 , false ) ;
if ( V_19 )
return V_19 ;
F_9 ( 1500 , 2000 ) ;
V_54 -> V_73 = false ;
return 0 ;
}
static int F_39 ( struct V_52 * V_52 )
{
struct V_53 * V_54 = F_31 ( V_52 ) ;
struct V_2 * V_3 = F_32 ( V_52 -> V_28 . V_55 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_19 ;
F_35 ( & V_54 -> V_52 -> V_28 , L_8 ) ;
if ( V_54 -> V_73 )
return 0 ;
V_19 = F_2 ( V_6 , & V_54 -> V_62 -> V_74 , true ) ;
if ( V_19 )
return V_19 ;
V_54 -> V_73 = true ;
F_40 ( V_3 -> V_30 ) ;
return 0 ;
}
static int F_41 ( struct V_52 * V_52 )
{
struct V_53 * V_54 = F_31 ( V_52 ) ;
if ( V_54 -> V_57 == V_58 &&
V_54 -> V_59 != V_60 &&
V_54 -> V_59 != V_61 ) {
F_42 ( & V_54 -> V_66 ) ;
F_42 ( & V_54 -> V_75 ) ;
} else if ( V_54 -> V_57 == V_68 )
F_42 ( & V_54 -> V_71 ) ;
return 0 ;
}
static void F_43 ( struct V_76 * V_77 )
{
struct V_53 * V_54 =
F_8 ( V_77 , struct V_53 ,
V_66 . V_77 ) ;
struct V_2 * V_3 = F_32 ( V_54 -> V_52 -> V_28 . V_55 ) ;
static unsigned int V_78 ;
unsigned long V_79 ;
bool V_80 , V_81 , V_82 ;
if ( V_54 -> V_83 )
V_80 = F_5 ( V_3 -> V_5 ,
& V_54 -> V_62 -> V_83 ) ;
else
V_80 = F_5 ( V_3 -> V_5 ,
& V_54 -> V_62 -> V_84 ) ;
V_81 = false ;
V_82 = false ;
V_79 = V_67 ;
F_35 ( & V_54 -> V_52 -> V_28 , L_9 ,
F_44 ( V_54 -> V_85 ) ) ;
switch ( V_54 -> V_85 ) {
case V_86 :
V_54 -> V_85 = V_87 ;
if ( ! V_80 )
F_39 ( V_54 -> V_52 ) ;
case V_87 :
if ( F_45 ( V_3 -> V_48 , V_88 ) > 0 ) {
F_35 ( & V_54 -> V_52 -> V_28 , L_10 ) ;
V_54 -> V_85 = V_89 ;
F_37 ( V_54 -> V_52 ) ;
return;
} else if ( V_80 ) {
F_35 ( & V_54 -> V_52 -> V_28 , L_11 ) ;
switch ( V_3 -> V_90 ) {
case V_91 :
F_34 ( & V_54 -> V_75 , 0 ) ;
return;
case V_92 :
switch ( V_3 -> V_93 ) {
case V_94 :
F_35 ( & V_54 -> V_52 -> V_28 , L_12 ) ;
F_37 ( V_54 -> V_52 ) ;
V_54 -> V_85 = V_95 ;
V_82 = true ;
V_81 = true ;
V_78 = V_96 ;
break;
case V_97 :
F_35 ( & V_54 -> V_52 -> V_28 , L_13 ) ;
F_39 ( V_54 -> V_52 ) ;
V_82 = true ;
V_81 = true ;
V_78 = V_98 ;
break;
case V_99 :
F_35 ( & V_54 -> V_52 -> V_28 , L_14 ) ;
F_37 ( V_54 -> V_52 ) ;
V_54 -> V_85 = V_95 ;
V_82 = true ;
V_81 = true ;
V_78 = V_100 ;
break;
default:
break;
}
break;
default:
break;
}
} else {
V_82 = true ;
V_3 -> V_90 = V_91 ;
V_3 -> V_93 = V_101 ;
}
if ( V_54 -> V_102 != V_80 ) {
V_54 -> V_102 = V_80 ;
if ( V_82 && V_3 -> V_48 ) {
F_46 ( V_3 -> V_48 ,
V_78 , V_80 ) ;
if ( V_78 == V_96 )
F_46 ( V_3 -> V_48 ,
V_103 ,
V_80 ) ;
}
}
break;
case V_95 :
if ( ! V_80 ) {
F_35 ( & V_54 -> V_52 -> V_28 , L_15 ) ;
V_3 -> V_90 = V_91 ;
V_3 -> V_93 = V_101 ;
V_54 -> V_85 = V_87 ;
V_79 = 0 ;
F_39 ( V_54 -> V_52 ) ;
}
V_81 = true ;
break;
case V_89 :
if ( F_45 ( V_3 -> V_48 , V_88 ) == 0 ) {
F_35 ( & V_54 -> V_52 -> V_28 , L_16 ) ;
V_54 -> V_85 = V_87 ;
F_39 ( V_54 -> V_52 ) ;
}
break;
default:
break;
}
if ( V_81 )
F_34 ( & V_54 -> V_66 , V_79 ) ;
}
static const char * F_47 ( enum V_104 V_93 )
{
switch ( V_93 ) {
case V_94 :
return L_17 ;
case V_97 :
return L_18 ;
case V_99 :
return L_19 ;
default:
return L_20 ;
}
}
static void F_48 ( struct V_2 * V_3 ,
bool V_9 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_2 ( V_6 , & V_3 -> V_24 -> V_105 . V_106 , V_9 ) ;
F_2 ( V_6 , & V_3 -> V_24 -> V_105 . V_107 , V_9 ) ;
}
static void F_49 ( struct V_2 * V_3 ,
bool V_9 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_2 ( V_6 , & V_3 -> V_24 -> V_105 . V_108 , V_9 ) ;
F_2 ( V_6 , & V_3 -> V_24 -> V_105 . V_109 , V_9 ) ;
}
static void F_50 ( struct V_2 * V_3 ,
bool V_9 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_2 ( V_6 , & V_3 -> V_24 -> V_105 . V_110 , V_9 ) ;
F_2 ( V_6 , & V_3 -> V_24 -> V_105 . V_111 , V_9 ) ;
}
static void F_51 ( struct V_76 * V_77 )
{
struct V_53 * V_54 =
F_8 ( V_77 , struct V_53 , V_75 . V_77 ) ;
struct V_2 * V_3 = F_32 ( V_54 -> V_52 -> V_28 . V_55 ) ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
bool V_112 , V_113 , V_114 ;
unsigned long V_79 ;
F_35 ( & V_54 -> V_52 -> V_28 , L_21 ,
V_3 -> V_90 ) ;
switch ( V_3 -> V_90 ) {
case V_91 :
if ( ! V_54 -> V_73 )
F_39 ( V_54 -> V_52 ) ;
F_2 ( V_6 , & V_3 -> V_24 -> V_105 . V_115 , false ) ;
F_48 ( V_3 , true ) ;
V_3 -> V_90 = V_116 ;
V_3 -> V_117 = 0 ;
V_79 = V_118 ;
break;
case V_116 :
V_112 = F_5 ( V_3 -> V_5 ,
& V_3 -> V_24 -> V_105 . V_119 ) ;
V_113 = ++ V_3 -> V_117 == V_120 ;
if ( V_112 || V_113 ) {
F_48 ( V_3 , false ) ;
F_49 ( V_3 , true ) ;
V_79 = V_121 ;
V_3 -> V_90 = V_122 ;
} else {
V_79 = V_118 ;
}
break;
case V_122 :
V_114 = F_5 ( V_3 -> V_5 ,
& V_3 -> V_24 -> V_105 . V_123 ) ;
F_49 ( V_3 , false ) ;
if ( V_114 ) {
F_50 ( V_3 , true ) ;
V_79 = V_124 ;
V_3 -> V_90 = V_125 ;
} else {
if ( V_3 -> V_117 == V_120 ) {
V_3 -> V_93 = V_97 ;
V_3 -> V_90 = V_92 ;
V_79 = 0 ;
} else {
V_3 -> V_93 = V_94 ;
V_3 -> V_90 = V_92 ;
V_79 = 0 ;
}
}
break;
case V_125 :
V_114 = F_5 ( V_3 -> V_5 ,
& V_3 -> V_24 -> V_105 . V_126 ) ;
F_50 ( V_3 , false ) ;
if ( V_114 )
V_3 -> V_93 = V_97 ;
else
V_3 -> V_93 = V_99 ;
case V_127 :
V_3 -> V_90 = V_92 ;
V_79 = 0 ;
case V_92 :
F_2 ( V_6 , & V_3 -> V_24 -> V_105 . V_115 , true ) ;
F_43 ( & V_54 -> V_66 . V_77 ) ;
F_52 ( & V_54 -> V_52 -> V_28 , L_22 ,
F_47 ( V_3 -> V_93 ) ) ;
return;
default:
return;
}
F_34 ( & V_54 -> V_75 , V_79 ) ;
}
static void F_53 ( struct V_76 * V_77 )
{
struct V_53 * V_54 =
F_8 ( V_77 , struct V_53 , V_71 . V_77 ) ;
struct V_2 * V_3 = F_32 ( V_54 -> V_52 -> V_28 . V_55 ) ;
unsigned int V_128 = V_54 -> V_62 -> V_129 . V_15 -
V_54 -> V_62 -> V_129 . V_16 + 1 ;
unsigned int V_130 , V_131 , V_85 ;
unsigned int V_132 , V_133 ;
int V_19 ;
F_33 ( & V_54 -> V_56 ) ;
V_19 = F_6 ( V_3 -> V_5 , V_54 -> V_62 -> V_134 . V_18 , & V_130 ) ;
if ( V_19 < 0 )
goto V_135;
V_19 = F_6 ( V_3 -> V_5 , V_54 -> V_62 -> V_129 . V_18 , & V_131 ) ;
if ( V_19 < 0 )
goto V_135;
V_133 = F_3 ( V_54 -> V_62 -> V_129 . V_15 ,
V_54 -> V_62 -> V_129 . V_16 ) ;
V_132 = F_3 ( V_54 -> V_62 -> V_134 . V_15 ,
V_54 -> V_62 -> V_134 . V_16 ) ;
V_85 = ( ( V_131 & V_133 ) >> V_54 -> V_62 -> V_129 . V_16 ) |
( ( ( V_130 & V_132 ) >> V_54 -> V_62 -> V_134 . V_16 ) << V_128 ) ;
switch ( V_85 ) {
case V_136 :
F_35 ( & V_54 -> V_52 -> V_28 , L_23 ) ;
break;
case V_137 :
if ( ! V_54 -> V_73 ) {
F_35 ( & V_54 -> V_52 -> V_28 , L_24 ) ;
break;
}
case V_138 :
if ( V_54 -> V_73 ) {
F_35 ( & V_54 -> V_52 -> V_28 , L_25 ) ;
F_37 ( V_54 -> V_52 ) ;
V_54 -> V_73 = false ;
} else {
F_35 ( & V_54 -> V_52 -> V_28 , L_24 ) ;
}
break;
case V_139 :
if ( ! V_54 -> V_73 ) {
F_35 ( & V_54 -> V_52 -> V_28 , L_26 ) ;
F_39 ( V_54 -> V_52 ) ;
V_54 -> V_73 = true ;
}
F_2 ( V_3 -> V_5 , & V_54 -> V_62 -> V_69 , true ) ;
F_2 ( V_3 -> V_5 , & V_54 -> V_62 -> V_70 , true ) ;
F_36 ( & V_54 -> V_56 ) ;
return;
default:
F_35 ( & V_54 -> V_52 -> V_28 , L_27 ) ;
break;
}
V_135:
F_36 ( & V_54 -> V_56 ) ;
F_34 ( & V_54 -> V_71 , V_72 ) ;
}
static T_1 F_54 ( int V_140 , void * V_27 )
{
struct V_53 * V_54 = V_27 ;
struct V_2 * V_3 = F_32 ( V_54 -> V_52 -> V_28 . V_55 ) ;
if ( ! F_5 ( V_3 -> V_5 , & V_54 -> V_62 -> V_141 ) )
return V_142 ;
F_33 ( & V_54 -> V_56 ) ;
F_2 ( V_3 -> V_5 , & V_54 -> V_62 -> V_70 , false ) ;
F_2 ( V_3 -> V_5 , & V_54 -> V_62 -> V_69 , true ) ;
F_36 ( & V_54 -> V_56 ) ;
if ( V_54 -> V_73 && V_54 -> V_57 == V_68 )
F_53 ( & V_54 -> V_71 . V_77 ) ;
return V_143 ;
}
static T_1 F_55 ( int V_140 , void * V_27 )
{
struct V_53 * V_54 = V_27 ;
struct V_2 * V_3 = F_32 ( V_54 -> V_52 -> V_28 . V_55 ) ;
if ( ! F_5 ( V_3 -> V_5 , & V_54 -> V_62 -> V_144 ) )
return V_142 ;
F_33 ( & V_54 -> V_56 ) ;
F_2 ( V_3 -> V_5 , & V_54 -> V_62 -> V_63 , true ) ;
F_36 ( & V_54 -> V_56 ) ;
F_43 ( & V_54 -> V_66 . V_77 ) ;
return V_143 ;
}
static T_1 F_56 ( int V_140 , void * V_27 )
{
struct V_53 * V_54 = V_27 ;
struct V_2 * V_3 = F_32 ( V_54 -> V_52 -> V_28 . V_55 ) ;
if ( F_5 ( V_3 -> V_5 , & V_54 -> V_62 -> V_144 ) )
return F_55 ( V_140 , V_27 ) ;
else
return V_142 ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_53 * V_54 ,
struct V_31 * V_145 )
{
int V_19 ;
V_54 -> V_57 = V_68 ;
V_54 -> V_62 = & V_3 -> V_24 -> V_146 [ V_68 ] ;
V_54 -> V_73 = true ;
F_58 ( & V_54 -> V_56 ) ;
F_59 ( & V_54 -> V_71 , F_53 ) ;
V_54 -> V_147 = F_60 ( V_145 , L_28 ) ;
if ( V_54 -> V_147 < 0 ) {
F_27 ( V_3 -> V_28 , L_29 ) ;
return V_54 -> V_147 ;
}
V_19 = F_61 ( V_3 -> V_28 , V_54 -> V_147 , NULL ,
F_54 ,
V_148 ,
L_30 , V_54 ) ;
if ( V_19 ) {
F_27 ( V_3 -> V_28 , L_31 ) ;
return V_19 ;
}
return 0 ;
}
static int F_62 ( struct V_149 * V_150 ,
unsigned long V_151 , void * V_152 )
{
struct V_53 * V_54 =
F_8 ( V_150 , struct V_53 , V_153 ) ;
F_34 ( & V_54 -> V_66 , V_67 ) ;
return V_154 ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_53 * V_54 ,
struct V_31 * V_145 )
{
int V_19 ;
V_54 -> V_57 = V_58 ;
V_54 -> V_62 = & V_3 -> V_24 -> V_146 [ V_58 ] ;
V_54 -> V_85 = V_86 ;
V_54 -> V_73 = true ;
V_54 -> V_102 = false ;
F_58 ( & V_54 -> V_56 ) ;
V_54 -> V_59 = F_64 ( V_145 , - 1 ) ;
if ( V_54 -> V_59 == V_60 ||
V_54 -> V_59 == V_61 ) {
V_19 = 0 ;
goto V_64;
}
F_59 ( & V_54 -> V_75 , F_51 ) ;
F_59 ( & V_54 -> V_66 , F_43 ) ;
V_54 -> V_83 =
F_25 ( V_145 , L_32 ) ;
V_54 -> V_155 = F_60 ( V_145 , L_33 ) ;
if ( V_54 -> V_155 > 0 ) {
V_19 = F_61 ( V_3 -> V_28 , V_54 -> V_155 ,
NULL ,
F_56 ,
V_148 ,
L_34 ,
V_54 ) ;
if ( V_19 ) {
F_27 ( V_3 -> V_28 ,
L_35 ) ;
goto V_64;
}
} else {
V_54 -> V_156 = F_60 ( V_145 , L_36 ) ;
if ( V_54 -> V_156 < 0 ) {
F_27 ( V_3 -> V_28 , L_37 ) ;
V_19 = V_54 -> V_156 ;
goto V_64;
}
V_19 = F_61 ( V_3 -> V_28 , V_54 -> V_156 ,
NULL ,
F_55 ,
V_148 ,
L_38 ,
V_54 ) ;
if ( V_19 ) {
F_27 ( V_3 -> V_28 ,
L_39 ) ;
goto V_64;
}
}
if ( ! F_20 ( V_3 -> V_48 ) ) {
V_54 -> V_153 . V_157 = F_62 ;
V_19 = F_65 ( V_3 -> V_28 , V_3 -> V_48 ,
V_88 , & V_54 -> V_153 ) ;
if ( V_19 )
F_27 ( V_3 -> V_28 , L_40 ) ;
}
V_64:
return V_19 ;
}
static int F_66 ( struct V_158 * V_159 )
{
struct V_160 * V_28 = & V_159 -> V_28 ;
struct V_31 * V_161 = V_28 -> V_29 ;
struct V_31 * V_145 ;
struct V_162 * V_163 ;
struct V_2 * V_3 ;
const struct V_164 * V_165 ;
const struct V_166 * V_167 ;
unsigned int V_8 ;
int V_168 , V_19 ;
V_3 = F_67 ( V_28 , sizeof( * V_3 ) , V_169 ) ;
if ( ! V_3 )
return - V_51 ;
V_167 = F_68 ( V_28 -> V_170 -> V_171 , V_28 ) ;
if ( ! V_167 || ! V_167 -> V_27 ) {
F_27 ( V_28 , L_41 ) ;
return - V_172 ;
}
if ( ! V_28 -> V_55 || ! V_28 -> V_55 -> V_29 )
return - V_172 ;
V_3 -> V_5 = F_69 ( V_28 -> V_55 -> V_29 ) ;
if ( F_20 ( V_3 -> V_5 ) )
return F_21 ( V_3 -> V_5 ) ;
if ( F_70 ( V_161 , L_42 ) ) {
V_3 -> V_4 =
F_71 ( V_28 -> V_29 ,
L_43 ) ;
if ( F_20 ( V_3 -> V_4 ) )
return F_21 ( V_3 -> V_4 ) ;
} else {
V_3 -> V_4 = NULL ;
}
if ( F_72 ( V_161 , L_44 , & V_8 ) ) {
F_27 ( V_28 , L_45 ,
V_161 -> V_37 ) ;
return - V_172 ;
}
V_3 -> V_28 = V_28 ;
V_165 = V_167 -> V_27 ;
V_3 -> V_90 = V_91 ;
V_3 -> V_93 = V_101 ;
F_73 ( V_159 , V_3 ) ;
V_19 = F_24 ( V_3 ) ;
if ( V_19 )
return V_19 ;
V_168 = 0 ;
while ( V_165 [ V_168 ] . V_8 ) {
if ( V_165 [ V_168 ] . V_8 == V_8 ) {
V_3 -> V_24 = & V_165 [ V_168 ] ;
break;
}
++ V_168 ;
}
if ( ! V_3 -> V_24 ) {
F_27 ( V_28 , L_46 ,
V_161 -> V_37 ) ;
return - V_172 ;
}
V_3 -> V_40 = F_74 ( V_161 , L_47 ) ;
if ( ! F_20 ( V_3 -> V_40 ) ) {
F_38 ( V_3 -> V_40 ) ;
} else {
F_52 ( & V_159 -> V_28 , L_48 ) ;
V_3 -> V_40 = NULL ;
}
V_19 = F_16 ( V_3 ) ;
if ( V_19 ) {
F_27 ( V_28 , L_49 ) ;
goto V_173;
}
V_168 = 0 ;
F_75 (np, child_np) {
struct V_53 * V_54 = & V_3 -> V_174 [ V_168 ] ;
struct V_52 * V_52 ;
if ( F_76 ( V_145 -> V_37 , L_50 ) &&
F_76 ( V_145 -> V_37 , L_51 ) )
goto V_175;
V_52 = F_77 ( V_28 , V_145 , & V_176 ) ;
if ( F_20 ( V_52 ) ) {
F_27 ( V_28 , L_52 ) ;
V_19 = F_21 ( V_52 ) ;
goto V_177;
}
V_54 -> V_52 = V_52 ;
F_78 ( V_54 -> V_52 , V_54 ) ;
if ( ! F_76 ( V_145 -> V_37 , L_50 ) ) {
V_19 = F_57 ( V_3 , V_54 ,
V_145 ) ;
if ( V_19 )
goto V_177;
} else {
V_19 = F_63 ( V_3 , V_54 ,
V_145 ) ;
if ( V_19 )
goto V_177;
}
V_175:
if ( ++ V_168 >= V_3 -> V_24 -> V_178 )
break;
}
V_163 = F_79 ( V_28 , V_179 ) ;
return F_80 ( V_163 ) ;
V_177:
F_81 ( V_145 ) ;
V_173:
if ( V_3 -> V_40 ) {
F_40 ( V_3 -> V_40 ) ;
F_82 ( V_3 -> V_40 ) ;
}
return V_19 ;
}
