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
static void F_15 ( struct V_27 * V_17 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
V_8 = F_16 ( F_17 ( V_17 ) , struct V_7 ,
V_17 ) ;
F_18 ( & V_8 -> V_28 ) ;
V_2 = V_8 -> V_2 ;
if ( V_2 && ( F_2 ( V_2 ) || F_3 ( V_2 ) ) )
F_11 ( V_2 ) ;
F_19 ( & V_8 -> V_28 ) ;
}
static int F_20 ( struct V_1 * V_2 )
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
static int F_21 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( F_22 ( V_31 , & V_2 -> V_26 ) ) {
F_23 ( L_1 ,
V_2 -> V_32 ) ;
return - V_33 ;
}
if ( V_2 -> V_22 -> V_34 ) {
F_24 ( V_35 , & V_2 -> V_26 ) ;
V_21 = V_2 -> V_22 -> V_34 ( V_2 ) ;
} else {
F_14 ( V_35 , & V_2 -> V_26 ) ;
}
if ( V_21 == 0 ) {
F_24 ( V_30 , & V_2 -> V_26 ) ;
F_8 ( V_2 ) ;
}
return V_21 ;
}
static unsigned int F_25 ( struct V_1 * V_2 )
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
if ( F_22 ( V_44 , & V_8 -> V_26 ) )
V_26 |= V_45 ;
if ( F_26 ( V_25 , & V_8 -> V_26 ) )
V_26 |= V_46 ;
return V_26 ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
int V_21 = 0 ;
if ( ! ( V_2 -> V_47 -> V_48 & V_49 ) )
return - V_50 ;
if ( F_28 ( V_2 , V_6 ) )
return - V_51 ;
if ( V_2 -> V_22 -> V_52 )
V_21 = V_2 -> V_22 -> V_52 ( V_2 , V_6 ) ;
else
V_2 -> V_6 = V_6 ;
F_8 ( V_2 ) ;
return V_21 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned int * V_53 )
{
* V_53 = 0 ;
if ( ! V_2 -> V_22 -> V_54 )
return - V_50 ;
* V_53 = V_2 -> V_22 -> V_54 ( V_2 ) ;
return 0 ;
}
static T_1 F_30 ( struct V_55 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
struct V_1 * V_2 = F_31 ( V_56 ) ;
return sprintf ( V_59 , L_2 , ! ! F_22 ( V_31 , & V_2 -> V_26 ) ) ;
}
static T_1 F_32 ( struct V_55 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
struct V_1 * V_2 = F_31 ( V_56 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_26 ;
F_18 ( & V_8 -> V_28 ) ;
V_26 = F_25 ( V_2 ) ;
F_19 ( & V_8 -> V_28 ) ;
return sprintf ( V_59 , L_3 , V_26 ) ;
}
static T_1 F_33 ( struct V_55 * V_56 ,
struct V_57 * V_58 , char * V_59 )
{
struct V_1 * V_2 = F_31 ( V_56 ) ;
return sprintf ( V_59 , L_4 , V_2 -> V_36 ) ;
}
static T_1 F_34 ( struct V_55 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
struct V_1 * V_2 = F_31 ( V_56 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_26 ;
unsigned int V_60 ;
F_18 ( & V_8 -> V_28 ) ;
V_26 = F_29 ( V_2 , & V_60 ) ;
F_19 ( & V_8 -> V_28 ) ;
if ( ! V_26 )
V_26 = sprintf ( V_59 , L_4 , V_60 ) ;
return V_26 ;
}
static T_1 F_35 ( struct V_55 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
struct V_1 * V_2 = F_31 ( V_56 ) ;
return sprintf ( V_59 , L_4 , V_2 -> V_6 ) ;
}
static T_1 F_36 ( struct V_55 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
struct V_1 * V_2 = F_31 ( V_56 ) ;
return sprintf ( V_59 , L_5 , V_2 -> V_47 -> V_61 ) ;
}
static T_1 F_37 ( struct V_55 * V_56 , struct V_57 * V_58 ,
char * V_59 )
{
struct V_1 * V_2 = F_31 ( V_56 ) ;
if ( F_2 ( V_2 ) )
return sprintf ( V_59 , L_6 ) ;
return sprintf ( V_59 , L_7 ) ;
}
static T_2 F_38 ( struct V_62 * V_63 , struct V_64 * V_58 ,
int V_65 )
{
struct V_55 * V_56 = F_16 ( V_63 , struct V_55 , V_63 ) ;
struct V_1 * V_2 = F_31 ( V_56 ) ;
T_2 V_66 = V_58 -> V_66 ;
if ( V_58 == & V_67 . V_58 && ! V_2 -> V_22 -> V_54 )
V_66 = 0 ;
return V_66 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned int V_68 ,
unsigned long V_69 )
{
if ( ! V_2 -> V_22 -> V_70 )
return - V_71 ;
return V_2 -> V_22 -> V_70 ( V_2 , V_68 , V_69 ) ;
}
static T_1 F_40 ( struct V_72 * V_72 , const char T_3 * V_73 ,
T_4 V_74 , T_5 * V_75 )
{
struct V_7 * V_8 = V_72 -> V_76 ;
struct V_1 * V_2 ;
int V_21 ;
T_4 V_77 ;
char V_78 ;
if ( V_74 == 0 )
return 0 ;
F_24 ( V_44 , & V_8 -> V_26 ) ;
for ( V_77 = 0 ; V_77 != V_74 ; V_77 ++ ) {
if ( F_41 ( V_78 , V_73 + V_77 ) )
return - V_79 ;
if ( V_78 == 'V' )
F_14 ( V_44 , & V_8 -> V_26 ) ;
}
V_21 = - V_80 ;
F_18 ( & V_8 -> V_28 ) ;
V_2 = V_8 -> V_2 ;
if ( V_2 )
V_21 = F_13 ( V_2 ) ;
F_19 ( & V_8 -> V_28 ) ;
if ( V_21 < 0 )
return V_21 ;
return V_74 ;
}
static long F_42 ( struct V_72 * V_72 , unsigned int V_68 ,
unsigned long V_69 )
{
struct V_7 * V_8 = V_72 -> V_76 ;
void T_3 * V_81 = ( void T_3 * ) V_69 ;
struct V_1 * V_2 ;
int T_3 * V_82 = V_81 ;
unsigned int V_60 ;
int V_21 ;
F_18 ( & V_8 -> V_28 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_2 ) {
V_21 = - V_80 ;
goto V_83;
}
V_21 = F_39 ( V_2 , V_68 , V_69 ) ;
if ( V_21 != - V_71 )
goto V_83;
switch ( V_68 ) {
case V_84 :
V_21 = F_43 ( V_81 , V_2 -> V_47 ,
sizeof( struct V_85 ) ) ? - V_79 : 0 ;
break;
case V_86 :
V_60 = F_25 ( V_2 ) ;
V_21 = F_44 ( V_60 , V_82 ) ;
break;
case V_87 :
V_21 = F_44 ( V_2 -> V_36 , V_82 ) ;
break;
case V_88 :
if ( F_41 ( V_60 , V_82 ) ) {
V_21 = - V_79 ;
break;
}
if ( V_60 & V_89 ) {
V_21 = F_21 ( V_2 ) ;
if ( V_21 < 0 )
break;
}
if ( V_60 & V_90 )
V_21 = F_20 ( V_2 ) ;
break;
case V_91 :
if ( ! ( V_2 -> V_47 -> V_48 & V_46 ) ) {
V_21 = - V_50 ;
break;
}
V_21 = F_13 ( V_2 ) ;
break;
case V_92 :
if ( F_41 ( V_60 , V_82 ) ) {
V_21 = - V_79 ;
break;
}
V_21 = F_27 ( V_2 , V_60 ) ;
if ( V_21 < 0 )
break;
V_21 = F_13 ( V_2 ) ;
if ( V_21 < 0 )
break;
case V_93 :
if ( V_2 -> V_6 == 0 ) {
V_21 = - V_50 ;
break;
}
V_21 = F_44 ( V_2 -> V_6 , V_82 ) ;
break;
case V_94 :
V_21 = F_29 ( V_2 , & V_60 ) ;
if ( V_21 < 0 )
break;
V_21 = F_44 ( V_60 , V_82 ) ;
break;
default:
V_21 = - V_95 ;
break;
}
V_83:
F_19 ( & V_8 -> V_28 ) ;
return V_21 ;
}
static int F_45 ( struct V_96 * V_96 , struct V_72 * V_72 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_21 ;
if ( F_46 ( V_96 ) == V_97 )
V_8 = V_98 ;
else
V_8 = F_16 ( V_96 -> V_99 , struct V_7 ,
V_100 ) ;
if ( F_47 ( V_101 , & V_8 -> V_26 ) )
return - V_33 ;
V_2 = V_8 -> V_2 ;
if ( ! F_3 ( V_2 ) && ! F_48 ( V_2 -> V_22 -> V_102 ) ) {
V_21 = - V_33 ;
goto V_103;
}
V_21 = F_20 ( V_2 ) ;
if ( V_21 < 0 )
goto V_104;
V_72 -> V_76 = V_8 ;
if ( ! F_3 ( V_2 ) )
F_49 ( & V_8 -> V_105 ) ;
return F_50 ( V_96 , V_72 ) ;
V_104:
F_51 ( V_8 -> V_2 -> V_22 -> V_102 ) ;
V_103:
F_24 ( V_101 , & V_8 -> V_26 ) ;
return V_21 ;
}
static void F_52 ( struct V_105 * V_105 )
{
struct V_7 * V_8 ;
V_8 = F_16 ( V_105 , struct V_7 , V_105 ) ;
F_53 ( V_8 ) ;
}
static int F_54 ( struct V_96 * V_96 , struct V_72 * V_72 )
{
struct V_7 * V_8 = V_72 -> V_76 ;
struct V_1 * V_2 ;
int V_21 = - V_33 ;
bool V_106 ;
F_18 ( & V_8 -> V_28 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_2 )
goto V_107;
if ( ! F_22 ( V_30 , & V_2 -> V_26 ) )
V_21 = 0 ;
else if ( F_26 ( V_44 , & V_8 -> V_26 ) ||
! ( V_2 -> V_47 -> V_48 & V_45 ) )
V_21 = F_21 ( V_2 ) ;
if ( V_21 < 0 ) {
F_55 ( L_8 , V_2 -> V_32 ) ;
F_13 ( V_2 ) ;
}
F_8 ( V_2 ) ;
F_24 ( V_101 , & V_8 -> V_26 ) ;
V_107:
V_106 = V_2 && F_3 ( V_2 ) ;
F_19 ( & V_8 -> V_28 ) ;
if ( ! V_106 ) {
F_51 ( V_8 -> V_100 . V_102 ) ;
F_56 ( & V_8 -> V_105 , F_52 ) ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , T_6 V_108 )
{
struct V_7 * V_8 ;
int V_21 ;
V_8 = F_58 ( sizeof( struct V_7 ) , V_109 ) ;
if ( ! V_8 )
return - V_110 ;
F_59 ( & V_8 -> V_105 ) ;
F_60 ( & V_8 -> V_28 ) ;
V_8 -> V_2 = V_2 ;
V_2 -> V_8 = V_8 ;
if ( ! V_16 )
return - V_80 ;
F_61 ( & V_8 -> V_17 , F_15 ) ;
if ( V_2 -> V_32 == 0 ) {
V_98 = V_8 ;
V_111 . V_112 = V_2 -> V_112 ;
V_21 = F_62 ( & V_111 ) ;
if ( V_21 != 0 ) {
F_63 ( L_9 ,
V_2 -> V_47 -> V_61 , V_113 , V_21 ) ;
if ( V_21 == - V_33 )
F_63 ( L_10 ,
V_2 -> V_47 -> V_61 ) ;
V_98 = NULL ;
F_53 ( V_8 ) ;
return V_21 ;
}
}
F_64 ( & V_8 -> V_100 , & V_114 ) ;
V_8 -> V_100 . V_102 = V_2 -> V_22 -> V_102 ;
V_21 = F_65 ( & V_8 -> V_100 , V_108 , 1 ) ;
if ( V_21 ) {
F_63 ( L_11 ,
V_2 -> V_32 , F_66 ( V_115 ) , V_2 -> V_32 ) ;
if ( V_2 -> V_32 == 0 ) {
F_67 ( & V_111 ) ;
V_98 = NULL ;
F_56 ( & V_8 -> V_105 , F_52 ) ;
}
return V_21 ;
}
V_8 -> V_19 = V_15 - 1 ;
if ( F_3 ( V_2 ) ) {
F_68 ( V_2 -> V_22 -> V_102 ) ;
F_49 ( & V_8 -> V_105 ) ;
F_69 ( V_16 , & V_8 -> V_17 , 0 ) ;
}
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
F_71 ( & V_8 -> V_100 ) ;
if ( V_2 -> V_32 == 0 ) {
F_67 ( & V_111 ) ;
V_98 = NULL ;
}
F_18 ( & V_8 -> V_28 ) ;
V_8 -> V_2 = NULL ;
V_2 -> V_8 = NULL ;
F_19 ( & V_8 -> V_28 ) ;
F_72 ( & V_8 -> V_17 ) ;
F_56 ( & V_8 -> V_105 , F_52 ) ;
}
int F_73 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
T_6 V_108 ;
int V_116 ;
V_108 = F_74 ( F_66 ( V_115 ) , V_2 -> V_32 ) ;
V_116 = F_57 ( V_2 , V_108 ) ;
if ( V_116 )
return V_116 ;
V_56 = F_75 ( & V_117 , V_2 -> V_112 ,
V_108 , V_2 , V_2 -> V_118 ,
L_12 , V_2 -> V_32 ) ;
if ( F_76 ( V_56 ) ) {
F_70 ( V_2 ) ;
return F_77 ( V_56 ) ;
}
return V_116 ;
}
void F_78 ( struct V_1 * V_2 )
{
F_79 ( & V_117 , V_2 -> V_8 -> V_100 . V_56 ) ;
F_70 ( V_2 ) ;
}
int T_7 F_80 ( void )
{
int V_21 ;
V_16 = F_81 ( L_13 ,
V_119 | V_120 , 0 ) ;
if ( ! V_16 ) {
F_63 ( L_14 ) ;
return - V_110 ;
}
V_21 = F_82 ( & V_117 ) ;
if ( V_21 < 0 ) {
F_63 ( L_15 ) ;
goto V_121;
}
V_21 = F_83 ( & V_115 , 0 , V_122 , L_16 ) ;
if ( V_21 < 0 ) {
F_63 ( L_17 ) ;
goto V_123;
}
return 0 ;
V_123:
F_84 ( & V_117 ) ;
V_121:
F_85 ( V_16 ) ;
return V_21 ;
}
void T_8 F_86 ( void )
{
F_87 ( V_115 , V_122 ) ;
F_84 ( & V_117 ) ;
F_85 ( V_16 ) ;
}
