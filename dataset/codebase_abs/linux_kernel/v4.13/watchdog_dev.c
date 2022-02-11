static inline bool F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 ;
unsigned int V_5 = V_2 -> V_6 * 1000 ;
return ( V_3 && F_2 ( V_2 ) && V_5 > V_3 ) ||
( V_5 && ! F_2 ( V_2 ) && F_3 ( V_2 ) ) ;
}
static long F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_9 = V_2 -> V_6 * 1000 ;
unsigned long V_10 ;
unsigned long V_11 ;
unsigned long V_12 ;
unsigned int V_13 ;
V_12 = V_8 -> V_14 + F_5 ( V_9 ) ;
V_13 = F_6 ( V_9 , V_2 -> V_4 ) ;
V_10 = F_5 ( V_13 / 2 ) ;
if ( ! F_2 ( V_2 ) )
return V_10 ;
V_11 = V_12 - F_5 ( V_13 ) ;
return F_7 ( long , V_11 - V_15 , V_10 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
if ( F_1 ( V_2 ) ) {
long V_5 = F_4 ( V_2 ) ;
if ( V_5 > 0 )
F_9 ( V_16 , & V_8 -> V_17 , V_5 ) ;
} else {
F_10 ( & V_8 -> V_17 ) ;
}
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_18 = V_8 -> V_19 +
F_5 ( V_2 -> V_20 ) ;
int V_21 ;
if ( F_12 ( V_18 ) ) {
F_9 ( V_16 , & V_8 -> V_17 ,
V_18 - V_15 ) ;
return 0 ;
}
V_8 -> V_19 = V_15 ;
if ( V_2 -> V_22 -> V_23 )
V_21 = V_2 -> V_22 -> V_23 ( V_2 ) ;
else
V_21 = V_2 -> V_22 -> V_24 ( V_2 ) ;
F_8 ( V_2 ) ;
return V_21 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! F_2 ( V_2 ) && ! F_3 ( V_2 ) )
return 0 ;
F_14 ( V_25 , & V_8 -> V_26 ) ;
V_8 -> V_14 = V_15 ;
return F_11 ( V_2 ) ;
}
static bool F_15 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
return V_2 && ( F_2 ( V_2 ) || F_3 ( V_2 ) ) ;
}
static void F_16 ( struct V_27 * V_17 )
{
struct V_7 * V_8 ;
V_8 = F_17 ( F_18 ( V_17 ) , struct V_7 ,
V_17 ) ;
F_19 ( & V_8 -> V_28 ) ;
if ( F_15 ( V_8 ) )
F_11 ( V_8 -> V_2 ) ;
F_20 ( & V_8 -> V_28 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_29 ;
int V_21 ;
if ( F_2 ( V_2 ) )
return 0 ;
F_14 ( V_25 , & V_8 -> V_26 ) ;
V_29 = V_15 ;
if ( F_3 ( V_2 ) && V_2 -> V_22 -> V_23 )
V_21 = V_2 -> V_22 -> V_23 ( V_2 ) ;
else
V_21 = V_2 -> V_22 -> V_24 ( V_2 ) ;
if ( V_21 == 0 ) {
F_14 ( V_30 , & V_2 -> V_26 ) ;
V_8 -> V_14 = V_29 ;
F_8 ( V_2 ) ;
}
return V_21 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( F_23 ( V_31 , & V_2 -> V_26 ) ) {
F_24 ( L_1 ,
V_2 -> V_32 ) ;
return - V_33 ;
}
if ( V_2 -> V_22 -> V_34 ) {
F_25 ( V_35 , & V_2 -> V_26 ) ;
V_21 = V_2 -> V_22 -> V_34 ( V_2 ) ;
} else {
F_14 ( V_35 , & V_2 -> V_26 ) ;
}
if ( V_21 == 0 ) {
F_25 ( V_30 , & V_2 -> V_26 ) ;
F_8 ( V_2 ) ;
}
return V_21 ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_26 ;
if ( V_2 -> V_22 -> V_26 )
V_26 = V_2 -> V_22 -> V_26 ( V_2 ) ;
else
V_26 = V_2 -> V_36 & ( V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 |
V_43 ) ;
if ( F_23 ( V_44 , & V_8 -> V_26 ) )
V_26 |= V_45 ;
if ( F_27 ( V_25 , & V_8 -> V_26 ) )
V_26 |= V_46 ;
return V_26 ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
int V_21 = 0 ;
if ( ! ( V_2 -> V_47 -> V_48 & V_49 ) )
return - V_50 ;
if ( F_29 ( V_2 , V_6 ) )
return - V_51 ;
if ( V_2 -> V_22 -> V_52 ) {
V_21 = V_2 -> V_22 -> V_52 ( V_2 , V_6 ) ;
} else {
V_2 -> V_6 = V_6 ;
if ( V_2 -> V_53 >= V_2 -> V_6 )
V_2 -> V_53 = 0 ;
}
F_8 ( V_2 ) ;
return V_21 ;
}
static int F_30 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
int V_21 = 0 ;
if ( ! ( V_2 -> V_47 -> V_48 & V_54 ) )
return - V_50 ;
if ( F_31 ( V_2 , V_6 ) )
return - V_51 ;
if ( V_2 -> V_22 -> V_55 )
V_21 = V_2 -> V_22 -> V_55 ( V_2 , V_6 ) ;
else
V_2 -> V_53 = V_6 ;
return V_21 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned int * V_56 )
{
* V_56 = 0 ;
if ( ! V_2 -> V_22 -> V_57 )
return - V_50 ;
* V_56 = V_2 -> V_22 -> V_57 ( V_2 ) ;
return 0 ;
}
static T_1 F_33 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_1 * V_2 = F_34 ( V_59 ) ;
return sprintf ( V_62 , L_2 , ! ! F_23 ( V_31 , & V_2 -> V_26 ) ) ;
}
static T_1 F_35 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_1 * V_2 = F_34 ( V_59 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_26 ;
F_19 ( & V_8 -> V_28 ) ;
V_26 = F_26 ( V_2 ) ;
F_20 ( & V_8 -> V_28 ) ;
return sprintf ( V_62 , L_3 , V_26 ) ;
}
static T_1 F_36 ( struct V_58 * V_59 ,
struct V_60 * V_61 , char * V_62 )
{
struct V_1 * V_2 = F_34 ( V_59 ) ;
return sprintf ( V_62 , L_4 , V_2 -> V_36 ) ;
}
static T_1 F_37 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_1 * V_2 = F_34 ( V_59 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_26 ;
unsigned int V_63 ;
F_19 ( & V_8 -> V_28 ) ;
V_26 = F_32 ( V_2 , & V_63 ) ;
F_20 ( & V_8 -> V_28 ) ;
if ( ! V_26 )
V_26 = sprintf ( V_62 , L_4 , V_63 ) ;
return V_26 ;
}
static T_1 F_38 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_1 * V_2 = F_34 ( V_59 ) ;
return sprintf ( V_62 , L_4 , V_2 -> V_6 ) ;
}
static T_1 F_39 ( struct V_58 * V_59 ,
struct V_60 * V_61 , char * V_62 )
{
struct V_1 * V_2 = F_34 ( V_59 ) ;
return sprintf ( V_62 , L_4 , V_2 -> V_53 ) ;
}
static T_1 F_40 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_1 * V_2 = F_34 ( V_59 ) ;
return sprintf ( V_62 , L_5 , V_2 -> V_47 -> V_64 ) ;
}
static T_1 F_41 ( struct V_58 * V_59 , struct V_60 * V_61 ,
char * V_62 )
{
struct V_1 * V_2 = F_34 ( V_59 ) ;
if ( F_2 ( V_2 ) )
return sprintf ( V_62 , L_6 ) ;
return sprintf ( V_62 , L_7 ) ;
}
static T_1 F_42 ( struct V_58 * V_59 ,
struct V_60 * V_61 , char * V_62 )
{
return F_43 ( V_62 ) ;
}
static T_1 F_44 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
char * V_62 )
{
struct V_1 * V_2 = F_34 ( V_59 ) ;
return F_45 ( V_2 , V_62 ) ;
}
static T_1 F_46 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
const char * V_62 , T_2 V_65 )
{
struct V_1 * V_2 = F_34 ( V_59 ) ;
int V_66 = F_47 ( V_2 , V_62 ) ;
if ( ! V_66 )
V_66 = V_65 ;
return V_66 ;
}
static T_3 F_48 ( struct V_67 * V_68 , struct V_69 * V_61 ,
int V_70 )
{
struct V_58 * V_59 = F_17 ( V_68 , struct V_58 , V_68 ) ;
struct V_1 * V_2 = F_34 ( V_59 ) ;
T_3 V_71 = V_61 -> V_71 ;
if ( V_61 == & V_72 . V_61 && ! V_2 -> V_22 -> V_57 )
V_71 = 0 ;
else if ( V_61 == & V_73 . V_61 &&
! ( V_2 -> V_47 -> V_48 & V_54 ) )
V_71 = 0 ;
else if ( ( V_61 == & V_74 . V_61 ||
V_61 == & V_75 . V_61 ) &&
( ! ( V_2 -> V_47 -> V_48 & V_54 ) ||
! F_49 ( V_76 ) ) )
V_71 = 0 ;
return V_71 ;
}
static int F_50 ( struct V_1 * V_2 , unsigned int V_77 ,
unsigned long V_78 )
{
if ( ! V_2 -> V_22 -> V_79 )
return - V_80 ;
return V_2 -> V_22 -> V_79 ( V_2 , V_77 , V_78 ) ;
}
static T_1 F_51 ( struct V_81 * V_81 , const char T_4 * V_82 ,
T_2 V_83 , T_5 * V_84 )
{
struct V_7 * V_8 = V_81 -> V_85 ;
struct V_1 * V_2 ;
int V_21 ;
T_2 V_86 ;
char V_87 ;
if ( V_83 == 0 )
return 0 ;
F_25 ( V_44 , & V_8 -> V_26 ) ;
for ( V_86 = 0 ; V_86 != V_83 ; V_86 ++ ) {
if ( F_52 ( V_87 , V_82 + V_86 ) )
return - V_88 ;
if ( V_87 == 'V' )
F_14 ( V_44 , & V_8 -> V_26 ) ;
}
V_21 = - V_89 ;
F_19 ( & V_8 -> V_28 ) ;
V_2 = V_8 -> V_2 ;
if ( V_2 )
V_21 = F_13 ( V_2 ) ;
F_20 ( & V_8 -> V_28 ) ;
if ( V_21 < 0 )
return V_21 ;
return V_83 ;
}
static long F_53 ( struct V_81 * V_81 , unsigned int V_77 ,
unsigned long V_78 )
{
struct V_7 * V_8 = V_81 -> V_85 ;
void T_4 * V_90 = ( void T_4 * ) V_78 ;
struct V_1 * V_2 ;
int T_4 * V_91 = V_90 ;
unsigned int V_63 ;
int V_21 ;
F_19 ( & V_8 -> V_28 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_2 ) {
V_21 = - V_89 ;
goto V_92;
}
V_21 = F_50 ( V_2 , V_77 , V_78 ) ;
if ( V_21 != - V_80 )
goto V_92;
switch ( V_77 ) {
case V_93 :
V_21 = F_54 ( V_90 , V_2 -> V_47 ,
sizeof( struct V_94 ) ) ? - V_88 : 0 ;
break;
case V_95 :
V_63 = F_26 ( V_2 ) ;
V_21 = F_55 ( V_63 , V_91 ) ;
break;
case V_96 :
V_21 = F_55 ( V_2 -> V_36 , V_91 ) ;
break;
case V_97 :
if ( F_52 ( V_63 , V_91 ) ) {
V_21 = - V_88 ;
break;
}
if ( V_63 & V_98 ) {
V_21 = F_22 ( V_2 ) ;
if ( V_21 < 0 )
break;
}
if ( V_63 & V_99 )
V_21 = F_21 ( V_2 ) ;
break;
case V_100 :
if ( ! ( V_2 -> V_47 -> V_48 & V_46 ) ) {
V_21 = - V_50 ;
break;
}
V_21 = F_13 ( V_2 ) ;
break;
case V_101 :
if ( F_52 ( V_63 , V_91 ) ) {
V_21 = - V_88 ;
break;
}
V_21 = F_28 ( V_2 , V_63 ) ;
if ( V_21 < 0 )
break;
V_21 = F_13 ( V_2 ) ;
if ( V_21 < 0 )
break;
case V_102 :
if ( V_2 -> V_6 == 0 ) {
V_21 = - V_50 ;
break;
}
V_21 = F_55 ( V_2 -> V_6 , V_91 ) ;
break;
case V_103 :
V_21 = F_32 ( V_2 , & V_63 ) ;
if ( V_21 < 0 )
break;
V_21 = F_55 ( V_63 , V_91 ) ;
break;
case V_104 :
if ( F_52 ( V_63 , V_91 ) ) {
V_21 = - V_88 ;
break;
}
V_21 = F_30 ( V_2 , V_63 ) ;
break;
case V_105 :
V_21 = F_55 ( V_2 -> V_53 , V_91 ) ;
break;
default:
V_21 = - V_106 ;
break;
}
V_92:
F_20 ( & V_8 -> V_28 ) ;
return V_21 ;
}
static int F_56 ( struct V_107 * V_107 , struct V_81 * V_81 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_21 ;
if ( F_57 ( V_107 ) == V_108 )
V_8 = V_109 ;
else
V_8 = F_17 ( V_107 -> V_110 , struct V_7 ,
V_111 ) ;
if ( F_58 ( V_112 , & V_8 -> V_26 ) )
return - V_33 ;
V_2 = V_8 -> V_2 ;
if ( ! F_3 ( V_2 ) && ! F_59 ( V_2 -> V_22 -> V_113 ) ) {
V_21 = - V_33 ;
goto V_114;
}
V_21 = F_21 ( V_2 ) ;
if ( V_21 < 0 )
goto V_115;
V_81 -> V_85 = V_8 ;
if ( ! F_3 ( V_2 ) )
F_60 ( & V_8 -> V_116 ) ;
return F_61 ( V_107 , V_81 ) ;
V_115:
F_62 ( V_8 -> V_2 -> V_22 -> V_113 ) ;
V_114:
F_25 ( V_112 , & V_8 -> V_26 ) ;
return V_21 ;
}
static void F_63 ( struct V_116 * V_116 )
{
struct V_7 * V_8 ;
V_8 = F_17 ( V_116 , struct V_7 , V_116 ) ;
F_64 ( V_8 ) ;
}
static int F_65 ( struct V_107 * V_107 , struct V_81 * V_81 )
{
struct V_7 * V_8 = V_81 -> V_85 ;
struct V_1 * V_2 ;
int V_21 = - V_33 ;
bool V_117 ;
F_19 ( & V_8 -> V_28 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_2 )
goto V_118;
if ( ! F_23 ( V_30 , & V_2 -> V_26 ) )
V_21 = 0 ;
else if ( F_27 ( V_44 , & V_8 -> V_26 ) ||
! ( V_2 -> V_47 -> V_48 & V_45 ) )
V_21 = F_22 ( V_2 ) ;
if ( V_21 < 0 ) {
F_66 ( L_8 , V_2 -> V_32 ) ;
F_13 ( V_2 ) ;
}
F_8 ( V_2 ) ;
F_25 ( V_112 , & V_8 -> V_26 ) ;
V_118:
V_117 = V_2 && F_3 ( V_2 ) ;
F_20 ( & V_8 -> V_28 ) ;
if ( ! V_117 ) {
F_62 ( V_8 -> V_111 . V_113 ) ;
F_67 ( & V_8 -> V_116 , F_63 ) ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , T_6 V_119 )
{
struct V_7 * V_8 ;
int V_21 ;
V_8 = F_69 ( sizeof( struct V_7 ) , V_120 ) ;
if ( ! V_8 )
return - V_121 ;
F_70 ( & V_8 -> V_116 ) ;
F_71 ( & V_8 -> V_28 ) ;
V_8 -> V_2 = V_2 ;
V_2 -> V_8 = V_8 ;
if ( ! V_16 )
return - V_89 ;
F_72 ( & V_8 -> V_17 , F_16 ) ;
if ( V_2 -> V_32 == 0 ) {
V_109 = V_8 ;
V_122 . V_123 = V_2 -> V_123 ;
V_21 = F_73 ( & V_122 ) ;
if ( V_21 != 0 ) {
F_74 ( L_9 ,
V_2 -> V_47 -> V_64 , V_124 , V_21 ) ;
if ( V_21 == - V_33 )
F_74 ( L_10 ,
V_2 -> V_47 -> V_64 ) ;
V_109 = NULL ;
F_64 ( V_8 ) ;
return V_21 ;
}
}
F_75 ( & V_8 -> V_111 , & V_125 ) ;
V_8 -> V_111 . V_113 = V_2 -> V_22 -> V_113 ;
V_21 = F_76 ( & V_8 -> V_111 , V_119 , 1 ) ;
if ( V_21 ) {
F_74 ( L_11 ,
V_2 -> V_32 , F_77 ( V_126 ) , V_2 -> V_32 ) ;
if ( V_2 -> V_32 == 0 ) {
F_78 ( & V_122 ) ;
V_109 = NULL ;
F_67 ( & V_8 -> V_116 , F_63 ) ;
}
return V_21 ;
}
V_8 -> V_19 = V_15 - 1 ;
if ( F_3 ( V_2 ) ) {
if ( V_127 ) {
F_79 ( V_2 -> V_22 -> V_113 ) ;
F_60 ( & V_8 -> V_116 ) ;
F_80 ( V_16 , & V_8 -> V_17 , 0 ) ;
} else {
F_24 ( L_12 ,
V_2 -> V_32 ) ;
}
}
return 0 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
F_82 ( & V_8 -> V_111 ) ;
if ( V_2 -> V_32 == 0 ) {
F_78 ( & V_122 ) ;
V_109 = NULL ;
}
F_19 ( & V_8 -> V_28 ) ;
V_8 -> V_2 = NULL ;
V_2 -> V_8 = NULL ;
F_20 ( & V_8 -> V_28 ) ;
if ( F_2 ( V_2 ) &&
F_23 ( V_128 , & V_2 -> V_26 ) ) {
F_22 ( V_2 ) ;
}
F_83 ( & V_8 -> V_17 ) ;
F_67 ( & V_8 -> V_116 , F_63 ) ;
}
int F_84 ( struct V_1 * V_2 )
{
struct V_58 * V_59 ;
T_6 V_119 ;
int V_66 ;
V_119 = F_85 ( F_77 ( V_126 ) , V_2 -> V_32 ) ;
V_66 = F_68 ( V_2 , V_119 ) ;
if ( V_66 )
return V_66 ;
V_59 = F_86 ( & V_129 , V_2 -> V_123 ,
V_119 , V_2 , V_2 -> V_130 ,
L_13 , V_2 -> V_32 ) ;
if ( F_87 ( V_59 ) ) {
F_81 ( V_2 ) ;
return F_88 ( V_59 ) ;
}
V_66 = F_89 ( V_2 ) ;
if ( V_66 ) {
F_90 ( & V_129 , V_119 ) ;
F_81 ( V_2 ) ;
}
return V_66 ;
}
void F_91 ( struct V_1 * V_2 )
{
F_92 ( V_2 ) ;
F_90 ( & V_129 , V_2 -> V_8 -> V_111 . V_59 ) ;
F_81 ( V_2 ) ;
}
int T_7 F_93 ( void )
{
int V_21 ;
V_16 = F_94 ( L_14 ,
V_131 | V_132 , 0 ) ;
if ( ! V_16 ) {
F_74 ( L_15 ) ;
return - V_121 ;
}
V_21 = F_95 ( & V_129 ) ;
if ( V_21 < 0 ) {
F_74 ( L_16 ) ;
goto V_133;
}
V_21 = F_96 ( & V_126 , 0 , V_134 , L_17 ) ;
if ( V_21 < 0 ) {
F_74 ( L_18 ) ;
goto V_135;
}
return 0 ;
V_135:
F_97 ( & V_129 ) ;
V_133:
F_98 ( V_16 ) ;
return V_21 ;
}
void T_8 F_99 ( void )
{
F_100 ( V_126 , V_134 ) ;
F_97 ( & V_129 ) ;
F_98 ( V_16 ) ;
}
