struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
struct V_5 * F_2 ( struct V_6 * V_6 )
{
return V_6 -> V_3 -> V_7 ;
}
static struct V_8 *
F_3 ( struct V_6 * V_6 ,
const struct V_9 * V_10 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_8 * V_11 ;
T_1 V_12 ;
int V_13 ;
V_12 = sizeof( * V_11 ) + V_10 -> V_14 ;
V_11 = F_4 ( V_12 , V_15 ) ;
if ( ! V_11 )
return F_5 ( - V_16 ) ;
V_11 -> V_17 = 1 ;
V_11 -> V_18 . V_10 = V_10 ;
V_13 = F_6 ( & V_11 -> V_19 , & V_20 ) ;
if ( V_13 )
goto V_21;
V_13 = V_10 -> V_22 ( V_6 , V_3 -> V_23 , V_11 -> V_23 ) ;
if ( V_13 )
goto V_24;
return V_11 ;
V_24:
F_7 ( & V_11 -> V_19 ) ;
V_21:
F_8 ( V_11 ) ;
return F_5 ( V_13 ) ;
}
static void F_9 ( struct V_6 * V_6 ,
struct V_8 * V_11 )
{
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
V_10 -> V_25 ( V_6 , V_11 -> V_23 ) ;
F_7 ( & V_11 -> V_19 ) ;
F_8 ( V_11 ) ;
}
static int F_10 ( struct V_6 * V_6 ,
struct V_8 * V_11 ,
struct V_26 * V_27 , bool V_28 ,
T_2 V_29 )
{
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
struct V_2 * V_3 = V_6 -> V_3 ;
int V_13 ;
V_11 -> V_18 . V_27 = V_27 ;
V_11 -> V_18 . V_28 = V_28 ;
V_11 -> V_18 . V_29 = V_29 ;
V_13 = F_11 ( & V_3 -> V_30 , & V_11 -> V_31 ,
V_32 ) ;
if ( V_13 )
return V_13 ;
if ( ! V_11 -> V_18 . V_29 ) {
V_13 = V_10 -> V_33 ( V_6 , V_11 -> V_23 , V_27 , V_28 ) ;
if ( V_13 )
goto V_34;
}
return 0 ;
V_34:
F_12 ( & V_3 -> V_30 , & V_11 -> V_31 ,
V_32 ) ;
return V_13 ;
}
static void F_13 ( struct V_6 * V_6 ,
struct V_8 * V_11 )
{
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
struct V_2 * V_3 = V_6 -> V_3 ;
if ( ! V_11 -> V_18 . V_29 )
V_10 -> V_35 ( V_6 , V_11 -> V_23 ) ;
F_12 ( & V_3 -> V_30 , & V_11 -> V_31 ,
V_32 ) ;
}
static void F_14 ( struct V_8 * V_11 )
{
V_11 -> V_17 ++ ;
}
static void F_15 ( struct V_6 * V_6 ,
struct V_8 * V_11 )
{
if ( -- V_11 -> V_17 )
return;
F_13 ( V_6 , V_11 ) ;
F_9 ( V_6 , V_11 ) ;
}
static struct V_8 *
F_16 ( struct V_2 * V_3 , struct V_26 * V_27 ,
bool V_28 , T_2 V_29 ,
const struct V_9 * V_10 )
{
struct V_36 V_18 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_27 = V_27 ;
V_18 . V_28 = V_28 ;
V_18 . V_29 = V_29 ;
V_18 . V_10 = V_10 ;
return F_17 ( & V_3 -> V_30 , & V_18 ,
V_32 ) ;
}
struct V_8 *
F_18 ( struct V_6 * V_6 , struct V_26 * V_27 ,
bool V_28 , T_2 V_29 ,
enum V_37 V_38 )
{
const struct V_9 * V_10 ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_8 * V_11 ;
V_10 = V_3 -> V_10 -> V_39 ( V_6 , V_38 ) ;
if ( ! V_10 )
return F_5 ( - V_40 ) ;
V_11 = F_16 ( V_3 , V_27 , V_28 ,
V_29 , V_10 ) ;
if ( ! V_11 )
return F_5 ( - V_41 ) ;
return V_11 ;
}
struct V_8 *
F_19 ( struct V_6 * V_6 , struct V_26 * V_27 ,
bool V_28 , T_2 V_29 ,
enum V_37 V_38 )
{
const struct V_9 * V_10 ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_8 * V_11 ;
int V_13 ;
V_10 = V_3 -> V_10 -> V_39 ( V_6 , V_38 ) ;
if ( ! V_10 )
return F_5 ( - V_40 ) ;
V_11 = F_16 ( V_3 , V_27 , V_28 ,
V_29 , V_10 ) ;
if ( V_11 ) {
F_14 ( V_11 ) ;
return V_11 ;
}
V_11 = F_3 ( V_6 , V_10 ) ;
if ( F_20 ( V_11 ) )
return V_11 ;
V_13 = F_10 ( V_6 , V_11 , V_27 ,
V_28 , V_29 ) ;
if ( V_13 )
goto V_42;
return V_11 ;
V_42:
F_9 ( V_6 , V_11 ) ;
return F_5 ( V_13 ) ;
}
void F_21 ( struct V_6 * V_6 ,
struct V_8 * V_11 )
{
F_15 ( V_6 , V_11 ) ;
}
T_3 F_22 ( struct V_8 * V_11 )
{
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
return V_10 -> V_43 ( V_11 -> V_23 ) ;
}
static int
F_23 ( struct V_6 * V_6 ,
struct V_44 * V_45 )
{
int V_13 ;
V_13 = F_24 ( V_6 , & V_45 -> V_46 ) ;
if ( V_13 )
return V_13 ;
V_45 -> V_47 = true ;
return 0 ;
}
static void
F_25 ( struct V_6 * V_6 ,
struct V_44 * V_45 )
{
V_45 -> V_47 = false ;
F_26 ( V_6 , V_45 -> V_46 ) ;
}
struct V_44 *
F_27 ( struct V_2 * V_3 )
{
struct V_44 * V_45 ;
int V_13 ;
V_45 = F_4 ( sizeof( * V_45 ) , V_15 ) ;
if ( ! V_45 )
return NULL ;
V_45 -> V_48 = F_28 ( V_3 -> V_49 ) ;
if ( F_20 ( V_45 -> V_48 ) ) {
V_13 = F_29 ( V_45 -> V_48 ) ;
goto V_50;
}
return V_45 ;
V_50:
F_8 ( V_45 ) ;
return F_5 ( V_13 ) ;
}
void F_30 ( struct V_44 * V_45 )
{
F_31 ( V_45 -> V_48 ) ;
F_8 ( V_45 ) ;
}
int F_32 ( struct V_44 * V_45 )
{
return F_33 ( V_45 -> V_48 ) ;
}
void F_34 ( struct V_44 * V_45 ,
unsigned int V_51 )
{
V_45 -> V_51 = V_51 ;
}
void F_35 ( struct V_44 * V_45 ,
enum V_52 V_53 ,
T_2 V_54 , T_2 V_55 )
{
F_36 ( & V_45 -> V_56 , V_53 ,
V_54 , V_55 ) ;
}
void F_37 ( struct V_44 * V_45 ,
enum V_52 V_53 ,
const char * V_54 ,
const char * V_55 , unsigned int V_57 )
{
F_38 ( & V_45 -> V_56 , V_53 ,
V_54 , V_55 , V_57 ) ;
}
void F_39 ( struct V_44 * V_45 )
{
F_40 ( V_45 -> V_48 ) ;
}
void F_41 ( struct V_44 * V_45 ,
T_3 V_58 )
{
F_42 ( V_45 -> V_48 , V_58 ) ;
}
int F_43 ( struct V_44 * V_45 )
{
return F_44 ( V_45 -> V_48 ) ;
}
int F_45 ( struct V_44 * V_45 )
{
return F_46 ( V_45 -> V_48 ) ;
}
int F_47 ( struct V_6 * V_6 ,
struct V_44 * V_45 ,
struct V_26 * V_59 )
{
struct V_60 * V_60 ;
T_4 V_61 ;
bool V_62 ;
if ( V_59 ) {
if ( ! F_48 ( V_59 ) )
return - V_40 ;
V_60 = F_49 ( V_59 ) ;
if ( V_60 -> V_6 != V_6 )
return - V_40 ;
V_61 = V_60 -> V_61 ;
V_62 = false ;
} else {
V_61 = 0 ;
V_62 = true ;
}
return F_50 ( V_45 -> V_48 ,
V_61 , V_62 ) ;
}
int F_51 ( struct V_6 * V_6 ,
struct V_44 * V_45 ,
T_2 V_63 , T_3 V_64 , T_3 V_65 , T_4 V_66 )
{
T_4 V_67 ;
if ( V_63 == V_68 ) {
switch ( V_65 ) {
case V_69 :
V_67 = 0 ;
break;
case V_70 :
V_67 = 1 ;
break;
default:
F_52 ( V_6 -> V_71 -> V_27 , L_1 ,
V_65 ) ;
return - V_40 ;
}
return F_53 ( V_45 -> V_48 ,
V_64 , V_66 , V_67 ) ;
} else {
F_52 ( V_6 -> V_71 -> V_27 , L_2 ) ;
return - V_40 ;
}
}
int F_54 ( struct V_6 * V_6 ,
struct V_44 * V_45 )
{
return F_55 ( V_45 -> V_48 ,
V_45 -> V_46 ) ;
}
int F_56 ( struct V_6 * V_6 ,
struct V_44 * V_45 ,
T_3 V_72 )
{
return F_57 ( V_45 -> V_48 , V_72 ) ;
}
struct V_73 *
F_58 ( struct V_6 * V_6 ,
struct V_8 * V_11 ,
unsigned long V_74 )
{
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
struct V_73 * V_75 ;
int V_13 ;
F_14 ( V_11 ) ;
V_75 = F_4 ( sizeof( * V_75 ) + V_10 -> V_76 , V_15 ) ;
if ( ! V_75 ) {
V_13 = - V_16 ;
goto V_77;
}
V_75 -> V_74 = V_74 ;
V_75 -> V_11 = V_11 ;
V_75 -> V_45 = F_27 ( V_6 -> V_3 ) ;
if ( F_20 ( V_75 -> V_45 ) ) {
V_13 = F_29 ( V_75 -> V_45 ) ;
goto V_78;
}
V_13 = F_23 ( V_6 , V_75 -> V_45 ) ;
if ( V_13 )
goto V_79;
return V_75 ;
V_79:
F_30 ( V_75 -> V_45 ) ;
V_78:
F_8 ( V_75 ) ;
V_77:
F_15 ( V_6 , V_11 ) ;
return F_5 ( V_13 ) ;
}
void F_59 ( struct V_6 * V_6 ,
struct V_73 * V_75 )
{
struct V_8 * V_11 = V_75 -> V_11 ;
F_25 ( V_6 , V_75 -> V_45 ) ;
F_30 ( V_75 -> V_45 ) ;
F_8 ( V_75 ) ;
F_15 ( V_6 , V_11 ) ;
}
int F_60 ( struct V_6 * V_6 ,
struct V_73 * V_75 )
{
struct V_8 * V_11 = V_75 -> V_11 ;
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
int V_13 ;
V_13 = V_10 -> V_80 ( V_6 , V_11 -> V_23 , V_75 -> V_23 , V_75 -> V_45 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( & V_11 -> V_19 , & V_75 -> V_31 ,
V_20 ) ;
if ( V_13 )
goto V_81;
F_61 ( & V_75 -> V_82 , & V_6 -> V_3 -> V_83 ) ;
return 0 ;
V_81:
V_10 -> V_84 ( V_6 , V_75 -> V_23 ) ;
return V_13 ;
}
void F_62 ( struct V_6 * V_6 ,
struct V_73 * V_75 )
{
struct V_8 * V_11 = V_75 -> V_11 ;
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
F_63 ( & V_75 -> V_82 ) ;
F_12 ( & V_11 -> V_19 , & V_75 -> V_31 ,
V_20 ) ;
V_10 -> V_84 ( V_6 , V_75 -> V_23 ) ;
}
struct V_73 *
F_64 ( struct V_6 * V_6 ,
struct V_8 * V_11 ,
unsigned long V_74 )
{
return F_17 ( & V_11 -> V_19 , & V_74 ,
V_20 ) ;
}
struct V_44 *
F_65 ( struct V_73 * V_75 )
{
return V_75 -> V_45 ;
}
static int F_66 ( struct V_6 * V_6 ,
struct V_73 * V_75 )
{
struct V_8 * V_11 = V_75 -> V_11 ;
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
bool V_85 ;
int V_13 ;
V_13 = V_10 -> V_86 ( V_6 , V_75 -> V_23 , & V_85 ) ;
if ( V_13 )
return V_13 ;
if ( V_85 )
V_75 -> V_87 = V_88 ;
return 0 ;
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_73 * V_75 ;
int V_13 ;
F_68 () ;
F_69 (rule, &acl->rules, list) {
V_13 = F_66 ( V_3 -> V_6 ,
V_75 ) ;
if ( V_13 )
goto V_89;
}
F_70 () ;
return 0 ;
V_89:
F_70 () ;
return V_13 ;
}
static void F_71 ( struct V_2 * V_3 )
{
unsigned long V_90 = V_3 -> V_91 . V_90 ;
F_72 ( & V_3 -> V_91 . V_92 ,
F_73 ( V_90 ) ) ;
}
static void F_74 ( struct V_93 * V_94 )
{
struct V_2 * V_3 = F_75 ( V_94 , struct V_2 ,
V_91 . V_92 . V_94 ) ;
int V_13 ;
V_13 = F_67 ( V_3 ) ;
if ( V_13 )
F_52 ( V_3 -> V_6 -> V_71 -> V_27 , L_3 ) ;
F_71 ( V_3 ) ;
}
int F_76 ( struct V_6 * V_6 ,
struct V_73 * V_75 ,
T_5 * V_95 , T_5 * V_96 , T_5 * V_97 )
{
struct V_44 * V_45 ;
T_5 V_98 ;
T_5 V_99 ;
int V_13 ;
V_45 = F_65 ( V_75 ) ;
V_13 = F_77 ( V_6 , V_45 -> V_46 ,
& V_98 , & V_99 ) ;
if ( V_13 )
return V_13 ;
* V_95 = V_98 - V_75 -> V_100 ;
* V_96 = V_99 - V_75 -> V_101 ;
* V_97 = V_75 -> V_87 ;
V_75 -> V_101 = V_99 ;
V_75 -> V_100 = V_98 ;
return 0 ;
}
static int F_78 ( void * V_23 , T_2 * V_102 ,
char * V_103 , bool V_104 )
{
struct V_6 * V_6 = V_23 ;
char V_105 [ V_106 ] ;
T_2 V_107 ;
int V_13 ;
if ( V_104 )
return 0 ;
V_13 = F_79 ( V_6 , V_108 ,
& V_107 ) ;
if ( V_13 )
return V_13 ;
F_80 ( V_105 , V_107 , V_103 ) ;
V_13 = F_81 ( V_6 -> V_109 , F_82 ( V_110 ) , V_105 ) ;
if ( V_13 )
goto V_111;
* V_102 = V_107 ;
return 0 ;
V_111:
F_83 ( V_6 , V_107 ) ;
return V_13 ;
}
static void F_84 ( void * V_23 , T_2 V_107 ,
bool V_104 )
{
struct V_6 * V_6 = V_23 ;
if ( V_104 )
return;
F_83 ( V_6 , V_107 ) ;
}
static int F_85 ( void * V_23 , T_2 * V_102 ,
T_4 V_61 )
{
struct V_6 * V_6 = V_23 ;
char V_112 [ V_113 ] ;
T_2 V_107 ;
int V_13 ;
V_13 = F_79 ( V_6 , 1 , & V_107 ) ;
if ( V_13 )
return V_13 ;
F_86 ( V_112 , V_107 , V_61 ) ;
V_13 = F_81 ( V_6 -> V_109 , F_82 ( V_114 ) , V_112 ) ;
if ( V_13 )
goto V_115;
* V_102 = V_107 ;
return 0 ;
V_115:
F_83 ( V_6 , V_107 ) ;
return V_13 ;
}
static void F_87 ( void * V_23 , T_2 V_107 )
{
struct V_6 * V_6 = V_23 ;
F_83 ( V_6 , V_107 ) ;
}
int F_88 ( struct V_6 * V_6 )
{
const struct V_116 * V_117 = & V_118 ;
struct V_5 * V_72 ;
struct V_2 * V_3 ;
int V_13 ;
V_3 = F_4 ( sizeof( * V_3 ) + V_117 -> V_119 , V_15 ) ;
if ( ! V_3 )
return - V_16 ;
V_6 -> V_3 = V_3 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_4 = F_89 ( F_90 ( V_6 -> V_109 ,
V_120 ) ,
V_121 ,
V_122 ) ;
if ( ! V_3 -> V_4 ) {
V_13 = - V_16 ;
goto V_123;
}
V_3 -> V_49 = F_91 ( F_90 ( V_6 -> V_109 ,
V_124 ) ,
& V_125 , V_6 ) ;
if ( F_20 ( V_3 -> V_49 ) ) {
V_13 = F_29 ( V_3 -> V_49 ) ;
goto V_126;
}
V_13 = F_6 ( & V_3 -> V_30 ,
& V_32 ) ;
if ( V_13 )
goto V_21;
V_72 = F_92 ( V_6 ) ;
if ( F_20 ( V_72 ) ) {
V_13 = F_29 ( V_72 ) ;
goto V_127;
}
V_3 -> V_7 = V_72 ;
F_93 ( & V_3 -> V_83 ) ;
V_13 = V_117 -> V_128 ( V_6 , V_3 -> V_23 ) ;
if ( V_13 )
goto V_129;
V_3 -> V_10 = V_117 ;
F_94 ( & V_3 -> V_91 . V_92 ,
F_74 ) ;
V_3 -> V_91 . V_90 = V_130 ;
F_72 ( & V_3 -> V_91 . V_92 , 0 ) ;
return 0 ;
V_129:
F_95 ( V_72 ) ;
V_127:
F_7 ( & V_3 -> V_30 ) ;
V_21:
F_96 ( V_3 -> V_49 ) ;
V_126:
F_97 ( V_3 -> V_4 ) ;
V_123:
F_8 ( V_3 ) ;
return V_13 ;
}
void F_98 ( struct V_6 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
const struct V_116 * V_117 = V_3 -> V_10 ;
F_99 ( & V_6 -> V_3 -> V_91 . V_92 ) ;
V_117 -> V_131 ( V_6 , V_3 -> V_23 ) ;
F_100 ( ! F_101 ( & V_3 -> V_83 ) ) ;
F_95 ( V_3 -> V_7 ) ;
F_7 ( & V_3 -> V_30 ) ;
F_96 ( V_3 -> V_49 ) ;
F_97 ( V_3 -> V_4 ) ;
F_8 ( V_3 ) ;
}
