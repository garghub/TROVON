struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static struct V_5 *
F_2 ( struct V_6 * V_6 ,
const struct V_7 * V_8 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_5 * V_9 ;
T_1 V_10 ;
int V_11 ;
V_10 = sizeof( * V_9 ) + V_8 -> V_12 ;
V_9 = F_3 ( V_10 , V_13 ) ;
if ( ! V_9 )
return F_4 ( - V_14 ) ;
V_9 -> V_15 = 1 ;
V_9 -> V_16 . V_8 = V_8 ;
V_11 = F_5 ( & V_9 -> V_17 , & V_18 ) ;
if ( V_11 )
goto V_19;
V_11 = V_8 -> V_20 ( V_6 , V_3 -> V_21 , V_9 -> V_21 ) ;
if ( V_11 )
goto V_22;
return V_9 ;
V_22:
F_6 ( & V_9 -> V_17 ) ;
V_19:
F_7 ( V_9 ) ;
return F_4 ( V_11 ) ;
}
static void F_8 ( struct V_6 * V_6 ,
struct V_5 * V_9 )
{
const struct V_7 * V_8 = V_9 -> V_16 . V_8 ;
V_8 -> V_23 ( V_6 , V_9 -> V_21 ) ;
F_6 ( & V_9 -> V_17 ) ;
F_7 ( V_9 ) ;
}
static int F_9 ( struct V_6 * V_6 ,
struct V_5 * V_9 ,
struct V_24 * V_25 , bool V_26 )
{
const struct V_7 * V_8 = V_9 -> V_16 . V_8 ;
struct V_2 * V_3 = V_6 -> V_3 ;
int V_11 ;
V_9 -> V_16 . V_25 = V_25 ;
V_9 -> V_16 . V_26 = V_26 ;
V_11 = F_10 ( & V_3 -> V_27 , & V_9 -> V_28 ,
V_29 ) ;
if ( V_11 )
return V_11 ;
V_11 = V_8 -> V_30 ( V_6 , V_9 -> V_21 , V_25 , V_26 ) ;
if ( V_11 )
goto V_31;
return 0 ;
V_31:
F_11 ( & V_3 -> V_27 , & V_9 -> V_28 ,
V_29 ) ;
return V_11 ;
}
static void F_12 ( struct V_6 * V_6 ,
struct V_5 * V_9 )
{
const struct V_7 * V_8 = V_9 -> V_16 . V_8 ;
struct V_2 * V_3 = V_6 -> V_3 ;
V_8 -> V_32 ( V_6 , V_9 -> V_21 ) ;
F_11 ( & V_3 -> V_27 , & V_9 -> V_28 ,
V_29 ) ;
}
static void F_13 ( struct V_5 * V_9 )
{
V_9 -> V_15 ++ ;
}
static void F_14 ( struct V_6 * V_6 ,
struct V_5 * V_9 )
{
if ( -- V_9 -> V_15 )
return;
F_12 ( V_6 , V_9 ) ;
F_8 ( V_6 , V_9 ) ;
}
struct V_5 *
F_15 ( struct V_6 * V_6 ,
struct V_24 * V_25 , bool V_26 ,
enum V_33 V_34 )
{
const struct V_7 * V_8 ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_35 V_16 ;
struct V_5 * V_9 ;
int V_11 ;
V_8 = V_3 -> V_8 -> V_36 ( V_6 , V_34 ) ;
if ( ! V_8 )
return F_4 ( - V_37 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_25 = V_25 ;
V_16 . V_26 = V_26 ;
V_16 . V_8 = V_8 ;
V_9 = F_16 ( & V_3 -> V_27 , & V_16 ,
V_29 ) ;
if ( V_9 ) {
F_13 ( V_9 ) ;
return V_9 ;
}
V_9 = F_2 ( V_6 , V_8 ) ;
if ( F_17 ( V_9 ) )
return V_9 ;
V_11 = F_9 ( V_6 , V_9 , V_25 , V_26 ) ;
if ( V_11 )
goto V_38;
return V_9 ;
V_38:
F_8 ( V_6 , V_9 ) ;
return F_4 ( V_11 ) ;
}
void F_18 ( struct V_6 * V_6 ,
struct V_5 * V_9 )
{
F_14 ( V_6 , V_9 ) ;
}
static int
F_19 ( struct V_6 * V_6 ,
struct V_39 * V_40 )
{
int V_11 ;
V_11 = F_20 ( V_6 , & V_40 -> V_41 ) ;
if ( V_11 )
return V_11 ;
V_40 -> V_42 = true ;
return 0 ;
}
static void
F_21 ( struct V_6 * V_6 ,
struct V_39 * V_40 )
{
V_40 -> V_42 = false ;
F_22 ( V_6 , V_40 -> V_41 ) ;
}
struct V_39 *
F_23 ( struct V_2 * V_3 )
{
struct V_39 * V_40 ;
int V_11 ;
V_40 = F_3 ( sizeof( * V_40 ) , V_13 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_43 = F_24 ( V_3 -> V_44 ) ;
if ( F_17 ( V_40 -> V_43 ) ) {
V_11 = F_25 ( V_40 -> V_43 ) ;
goto V_45;
}
return V_40 ;
V_45:
F_7 ( V_40 ) ;
return F_4 ( V_11 ) ;
}
void F_26 ( struct V_39 * V_40 )
{
F_27 ( V_40 -> V_43 ) ;
F_7 ( V_40 ) ;
}
int F_28 ( struct V_39 * V_40 )
{
return F_29 ( V_40 -> V_43 ) ;
}
void F_30 ( struct V_39 * V_40 ,
unsigned int V_46 )
{
V_40 -> V_46 = V_46 ;
}
void F_31 ( struct V_39 * V_40 ,
enum V_47 V_48 ,
T_2 V_49 , T_2 V_50 )
{
F_32 ( & V_40 -> V_51 , V_48 ,
V_49 , V_50 ) ;
}
void F_33 ( struct V_39 * V_40 ,
enum V_47 V_48 ,
const char * V_49 ,
const char * V_50 , unsigned int V_52 )
{
F_34 ( & V_40 -> V_51 , V_48 ,
V_49 , V_50 , V_52 ) ;
}
void F_35 ( struct V_39 * V_40 )
{
F_36 ( V_40 -> V_43 ) ;
}
void F_37 ( struct V_39 * V_40 ,
T_3 V_53 )
{
F_38 ( V_40 -> V_43 , V_53 ) ;
}
int F_39 ( struct V_39 * V_40 )
{
return F_40 ( V_40 -> V_43 ) ;
}
int F_41 ( struct V_6 * V_6 ,
struct V_39 * V_40 ,
struct V_24 * V_54 )
{
struct V_55 * V_55 ;
T_4 V_56 ;
bool V_57 ;
if ( V_54 ) {
if ( ! F_42 ( V_54 ) )
return - V_37 ;
V_55 = F_43 ( V_54 ) ;
if ( V_55 -> V_6 != V_6 )
return - V_37 ;
V_56 = V_55 -> V_56 ;
V_57 = false ;
} else {
V_56 = 0 ;
V_57 = true ;
}
return F_44 ( V_40 -> V_43 ,
V_56 , V_57 ) ;
}
int F_45 ( struct V_6 * V_6 ,
struct V_39 * V_40 ,
T_2 V_58 , T_3 V_59 , T_3 V_60 , T_4 V_61 )
{
T_4 V_62 ;
if ( V_58 == V_63 ) {
switch ( V_60 ) {
case V_64 :
V_62 = 0 ;
break;
case V_65 :
V_62 = 1 ;
break;
default:
F_46 ( V_6 -> V_66 -> V_25 , L_1 ,
V_60 ) ;
return - V_37 ;
}
return F_47 ( V_40 -> V_43 ,
V_59 , V_61 , V_62 ) ;
} else {
F_46 ( V_6 -> V_66 -> V_25 , L_2 ) ;
return - V_37 ;
}
}
int F_48 ( struct V_6 * V_6 ,
struct V_39 * V_40 )
{
return F_49 ( V_40 -> V_43 ,
V_40 -> V_41 ) ;
}
int F_50 ( struct V_6 * V_6 ,
struct V_39 * V_40 ,
T_3 V_67 )
{
return F_51 ( V_40 -> V_43 , V_67 ) ;
}
struct V_68 *
F_52 ( struct V_6 * V_6 ,
struct V_5 * V_9 ,
unsigned long V_69 )
{
const struct V_7 * V_8 = V_9 -> V_16 . V_8 ;
struct V_68 * V_70 ;
int V_11 ;
F_13 ( V_9 ) ;
V_70 = F_3 ( sizeof( * V_70 ) + V_8 -> V_71 , V_13 ) ;
if ( ! V_70 ) {
V_11 = - V_14 ;
goto V_72;
}
V_70 -> V_69 = V_69 ;
V_70 -> V_9 = V_9 ;
V_70 -> V_40 = F_23 ( V_6 -> V_3 ) ;
if ( F_17 ( V_70 -> V_40 ) ) {
V_11 = F_25 ( V_70 -> V_40 ) ;
goto V_73;
}
V_11 = F_19 ( V_6 , V_70 -> V_40 ) ;
if ( V_11 )
goto V_74;
return V_70 ;
V_74:
F_26 ( V_70 -> V_40 ) ;
V_73:
F_7 ( V_70 ) ;
V_72:
F_14 ( V_6 , V_9 ) ;
return F_4 ( V_11 ) ;
}
void F_53 ( struct V_6 * V_6 ,
struct V_68 * V_70 )
{
struct V_5 * V_9 = V_70 -> V_9 ;
F_21 ( V_6 , V_70 -> V_40 ) ;
F_26 ( V_70 -> V_40 ) ;
F_7 ( V_70 ) ;
F_14 ( V_6 , V_9 ) ;
}
int F_54 ( struct V_6 * V_6 ,
struct V_68 * V_70 )
{
struct V_5 * V_9 = V_70 -> V_9 ;
const struct V_7 * V_8 = V_9 -> V_16 . V_8 ;
int V_11 ;
V_11 = V_8 -> V_75 ( V_6 , V_9 -> V_21 , V_70 -> V_21 , V_70 -> V_40 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_10 ( & V_9 -> V_17 , & V_70 -> V_28 ,
V_18 ) ;
if ( V_11 )
goto V_76;
F_55 ( & V_70 -> V_77 , & V_6 -> V_3 -> V_78 ) ;
return 0 ;
V_76:
V_8 -> V_79 ( V_6 , V_70 -> V_21 ) ;
return V_11 ;
}
void F_56 ( struct V_6 * V_6 ,
struct V_68 * V_70 )
{
struct V_5 * V_9 = V_70 -> V_9 ;
const struct V_7 * V_8 = V_9 -> V_16 . V_8 ;
F_57 ( & V_70 -> V_77 ) ;
F_11 ( & V_9 -> V_17 , & V_70 -> V_28 ,
V_18 ) ;
V_8 -> V_79 ( V_6 , V_70 -> V_21 ) ;
}
struct V_68 *
F_58 ( struct V_6 * V_6 ,
struct V_5 * V_9 ,
unsigned long V_69 )
{
return F_16 ( & V_9 -> V_17 , & V_69 ,
V_18 ) ;
}
struct V_39 *
F_59 ( struct V_68 * V_70 )
{
return V_70 -> V_40 ;
}
static int F_60 ( struct V_6 * V_6 ,
struct V_68 * V_70 )
{
struct V_5 * V_9 = V_70 -> V_9 ;
const struct V_7 * V_8 = V_9 -> V_16 . V_8 ;
bool V_80 ;
int V_11 ;
V_11 = V_8 -> V_81 ( V_6 , V_70 -> V_21 , & V_80 ) ;
if ( V_11 )
return V_11 ;
if ( V_80 )
V_70 -> V_82 = V_83 ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_68 * V_70 ;
int V_11 ;
F_62 () ;
F_63 (rule, &acl->rules, list) {
V_11 = F_60 ( V_3 -> V_6 ,
V_70 ) ;
if ( V_11 )
goto V_84;
}
F_64 () ;
return 0 ;
V_84:
F_64 () ;
return V_11 ;
}
static void F_65 ( struct V_2 * V_3 )
{
unsigned long V_85 = V_3 -> V_86 . V_85 ;
F_66 ( & V_3 -> V_86 . V_87 ,
F_67 ( V_85 ) ) ;
}
static void F_68 ( struct V_88 * V_89 )
{
struct V_2 * V_3 = F_69 ( V_89 , struct V_2 ,
V_86 . V_87 . V_89 ) ;
int V_11 ;
V_11 = F_61 ( V_3 ) ;
if ( V_11 )
F_46 ( V_3 -> V_6 -> V_66 -> V_25 , L_3 ) ;
F_65 ( V_3 ) ;
}
int F_70 ( struct V_6 * V_6 ,
struct V_68 * V_70 ,
T_5 * V_90 , T_5 * V_91 , T_5 * V_92 )
{
struct V_39 * V_40 ;
T_5 V_93 ;
T_5 V_94 ;
int V_11 ;
V_40 = F_59 ( V_70 ) ;
V_11 = F_71 ( V_6 , V_40 -> V_41 ,
& V_93 , & V_94 ) ;
if ( V_11 )
return V_11 ;
* V_90 = V_93 - V_70 -> V_95 ;
* V_91 = V_94 - V_70 -> V_96 ;
* V_92 = V_70 -> V_82 ;
V_70 -> V_96 = V_94 ;
V_70 -> V_95 = V_93 ;
return 0 ;
}
static int F_72 ( void * V_21 , T_2 * V_97 ,
char * V_98 , bool V_99 )
{
struct V_6 * V_6 = V_21 ;
char V_100 [ V_101 ] ;
T_2 V_102 ;
int V_11 ;
if ( V_99 )
return 0 ;
V_11 = F_73 ( V_6 , V_103 ,
& V_102 ) ;
if ( V_11 )
return V_11 ;
F_74 ( V_100 , V_102 , V_98 ) ;
V_11 = F_75 ( V_6 -> V_104 , F_76 ( V_105 ) , V_100 ) ;
if ( V_11 )
goto V_106;
* V_97 = V_102 ;
return 0 ;
V_106:
F_77 ( V_6 , V_102 ) ;
return V_11 ;
}
static void F_78 ( void * V_21 , T_2 V_102 ,
bool V_99 )
{
struct V_6 * V_6 = V_21 ;
if ( V_99 )
return;
F_77 ( V_6 , V_102 ) ;
}
static int F_79 ( void * V_21 , T_2 * V_97 ,
T_4 V_56 )
{
struct V_6 * V_6 = V_21 ;
char V_107 [ V_108 ] ;
T_2 V_102 ;
int V_11 ;
V_11 = F_73 ( V_6 , 1 , & V_102 ) ;
if ( V_11 )
return V_11 ;
F_80 ( V_107 , V_102 , V_56 ) ;
V_11 = F_75 ( V_6 -> V_104 , F_76 ( V_109 ) , V_107 ) ;
if ( V_11 )
goto V_110;
* V_97 = V_102 ;
return 0 ;
V_110:
F_77 ( V_6 , V_102 ) ;
return V_11 ;
}
static void F_81 ( void * V_21 , T_2 V_102 )
{
struct V_6 * V_6 = V_21 ;
F_77 ( V_6 , V_102 ) ;
}
int F_82 ( struct V_6 * V_6 )
{
const struct V_111 * V_112 = & V_113 ;
struct V_2 * V_3 ;
int V_11 ;
V_3 = F_3 ( sizeof( * V_3 ) + V_112 -> V_114 , V_13 ) ;
if ( ! V_3 )
return - V_14 ;
V_6 -> V_3 = V_3 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_4 = F_83 ( F_84 ( V_6 -> V_104 ,
V_115 ) ,
V_116 ,
V_117 ) ;
if ( ! V_3 -> V_4 ) {
V_11 = - V_14 ;
goto V_118;
}
V_3 -> V_44 = F_85 ( F_84 ( V_6 -> V_104 ,
V_119 ) ,
& V_120 , V_6 ) ;
if ( F_17 ( V_3 -> V_44 ) ) {
V_11 = F_25 ( V_3 -> V_44 ) ;
goto V_121;
}
V_11 = F_5 ( & V_3 -> V_27 ,
& V_29 ) ;
if ( V_11 )
goto V_19;
F_86 ( & V_3 -> V_78 ) ;
V_11 = V_112 -> V_122 ( V_6 , V_3 -> V_21 ) ;
if ( V_11 )
goto V_123;
V_3 -> V_8 = V_112 ;
F_87 ( & V_3 -> V_86 . V_87 ,
F_68 ) ;
V_3 -> V_86 . V_85 = V_124 ;
F_66 ( & V_3 -> V_86 . V_87 , 0 ) ;
return 0 ;
V_123:
F_6 ( & V_3 -> V_27 ) ;
V_19:
F_88 ( V_3 -> V_44 ) ;
V_121:
F_89 ( V_3 -> V_4 ) ;
V_118:
F_7 ( V_3 ) ;
return V_11 ;
}
void F_90 ( struct V_6 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
const struct V_111 * V_112 = V_3 -> V_8 ;
F_91 ( & V_6 -> V_3 -> V_86 . V_87 ) ;
V_112 -> V_125 ( V_6 , V_3 -> V_21 ) ;
F_92 ( ! F_93 ( & V_3 -> V_78 ) ) ;
F_6 ( & V_3 -> V_27 ) ;
F_88 ( V_3 -> V_44 ) ;
F_89 ( V_3 -> V_4 ) ;
F_7 ( V_3 ) ;
}
