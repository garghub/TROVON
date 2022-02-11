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
struct V_26 * V_27 , bool V_28 )
{
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
struct V_2 * V_3 = V_6 -> V_3 ;
int V_13 ;
V_11 -> V_18 . V_27 = V_27 ;
V_11 -> V_18 . V_28 = V_28 ;
V_13 = F_11 ( & V_3 -> V_29 , & V_11 -> V_30 ,
V_31 ) ;
if ( V_13 )
return V_13 ;
V_13 = V_10 -> V_32 ( V_6 , V_11 -> V_23 , V_27 , V_28 ) ;
if ( V_13 )
goto V_33;
return 0 ;
V_33:
F_12 ( & V_3 -> V_29 , & V_11 -> V_30 ,
V_31 ) ;
return V_13 ;
}
static void F_13 ( struct V_6 * V_6 ,
struct V_8 * V_11 )
{
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
struct V_2 * V_3 = V_6 -> V_3 ;
V_10 -> V_34 ( V_6 , V_11 -> V_23 ) ;
F_12 ( & V_3 -> V_29 , & V_11 -> V_30 ,
V_31 ) ;
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
struct V_8 *
F_16 ( struct V_6 * V_6 ,
struct V_26 * V_27 , bool V_28 ,
enum V_35 V_36 )
{
const struct V_9 * V_10 ;
struct V_2 * V_3 = V_6 -> V_3 ;
struct V_37 V_18 ;
struct V_8 * V_11 ;
int V_13 ;
V_10 = V_3 -> V_10 -> V_38 ( V_6 , V_36 ) ;
if ( ! V_10 )
return F_5 ( - V_39 ) ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_27 = V_27 ;
V_18 . V_28 = V_28 ;
V_18 . V_10 = V_10 ;
V_11 = F_17 ( & V_3 -> V_29 , & V_18 ,
V_31 ) ;
if ( V_11 ) {
F_14 ( V_11 ) ;
return V_11 ;
}
V_11 = F_3 ( V_6 , V_10 ) ;
if ( F_18 ( V_11 ) )
return V_11 ;
V_13 = F_10 ( V_6 , V_11 , V_27 , V_28 ) ;
if ( V_13 )
goto V_40;
return V_11 ;
V_40:
F_9 ( V_6 , V_11 ) ;
return F_5 ( V_13 ) ;
}
void F_19 ( struct V_6 * V_6 ,
struct V_8 * V_11 )
{
F_15 ( V_6 , V_11 ) ;
}
static int
F_20 ( struct V_6 * V_6 ,
struct V_41 * V_42 )
{
int V_13 ;
V_13 = F_21 ( V_6 , & V_42 -> V_43 ) ;
if ( V_13 )
return V_13 ;
V_42 -> V_44 = true ;
return 0 ;
}
static void
F_22 ( struct V_6 * V_6 ,
struct V_41 * V_42 )
{
V_42 -> V_44 = false ;
F_23 ( V_6 , V_42 -> V_43 ) ;
}
struct V_41 *
F_24 ( struct V_2 * V_3 )
{
struct V_41 * V_42 ;
int V_13 ;
V_42 = F_4 ( sizeof( * V_42 ) , V_15 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_45 = F_25 ( V_3 -> V_46 ) ;
if ( F_18 ( V_42 -> V_45 ) ) {
V_13 = F_26 ( V_42 -> V_45 ) ;
goto V_47;
}
return V_42 ;
V_47:
F_8 ( V_42 ) ;
return F_5 ( V_13 ) ;
}
void F_27 ( struct V_41 * V_42 )
{
F_28 ( V_42 -> V_45 ) ;
F_8 ( V_42 ) ;
}
int F_29 ( struct V_41 * V_42 )
{
return F_30 ( V_42 -> V_45 ) ;
}
void F_31 ( struct V_41 * V_42 ,
unsigned int V_48 )
{
V_42 -> V_48 = V_48 ;
}
void F_32 ( struct V_41 * V_42 ,
enum V_49 V_50 ,
T_2 V_51 , T_2 V_52 )
{
F_33 ( & V_42 -> V_53 , V_50 ,
V_51 , V_52 ) ;
}
void F_34 ( struct V_41 * V_42 ,
enum V_49 V_50 ,
const char * V_51 ,
const char * V_52 , unsigned int V_54 )
{
F_35 ( & V_42 -> V_53 , V_50 ,
V_51 , V_52 , V_54 ) ;
}
void F_36 ( struct V_41 * V_42 )
{
F_37 ( V_42 -> V_45 ) ;
}
void F_38 ( struct V_41 * V_42 ,
T_3 V_55 )
{
F_39 ( V_42 -> V_45 , V_55 ) ;
}
int F_40 ( struct V_41 * V_42 )
{
return F_41 ( V_42 -> V_45 ) ;
}
int F_42 ( struct V_41 * V_42 )
{
return F_43 ( V_42 -> V_45 ) ;
}
int F_44 ( struct V_6 * V_6 ,
struct V_41 * V_42 ,
struct V_26 * V_56 )
{
struct V_57 * V_57 ;
T_4 V_58 ;
bool V_59 ;
if ( V_56 ) {
if ( ! F_45 ( V_56 ) )
return - V_39 ;
V_57 = F_46 ( V_56 ) ;
if ( V_57 -> V_6 != V_6 )
return - V_39 ;
V_58 = V_57 -> V_58 ;
V_59 = false ;
} else {
V_58 = 0 ;
V_59 = true ;
}
return F_47 ( V_42 -> V_45 ,
V_58 , V_59 ) ;
}
int F_48 ( struct V_6 * V_6 ,
struct V_41 * V_42 ,
T_2 V_60 , T_3 V_61 , T_3 V_62 , T_4 V_63 )
{
T_4 V_64 ;
if ( V_60 == V_65 ) {
switch ( V_62 ) {
case V_66 :
V_64 = 0 ;
break;
case V_67 :
V_64 = 1 ;
break;
default:
F_49 ( V_6 -> V_68 -> V_27 , L_1 ,
V_62 ) ;
return - V_39 ;
}
return F_50 ( V_42 -> V_45 ,
V_61 , V_63 , V_64 ) ;
} else {
F_49 ( V_6 -> V_68 -> V_27 , L_2 ) ;
return - V_39 ;
}
}
int F_51 ( struct V_6 * V_6 ,
struct V_41 * V_42 )
{
return F_52 ( V_42 -> V_45 ,
V_42 -> V_43 ) ;
}
int F_53 ( struct V_6 * V_6 ,
struct V_41 * V_42 ,
T_3 V_69 )
{
return F_54 ( V_42 -> V_45 , V_69 ) ;
}
struct V_70 *
F_55 ( struct V_6 * V_6 ,
struct V_8 * V_11 ,
unsigned long V_71 )
{
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
struct V_70 * V_72 ;
int V_13 ;
F_14 ( V_11 ) ;
V_72 = F_4 ( sizeof( * V_72 ) + V_10 -> V_73 , V_15 ) ;
if ( ! V_72 ) {
V_13 = - V_16 ;
goto V_74;
}
V_72 -> V_71 = V_71 ;
V_72 -> V_11 = V_11 ;
V_72 -> V_42 = F_24 ( V_6 -> V_3 ) ;
if ( F_18 ( V_72 -> V_42 ) ) {
V_13 = F_26 ( V_72 -> V_42 ) ;
goto V_75;
}
V_13 = F_20 ( V_6 , V_72 -> V_42 ) ;
if ( V_13 )
goto V_76;
return V_72 ;
V_76:
F_27 ( V_72 -> V_42 ) ;
V_75:
F_8 ( V_72 ) ;
V_74:
F_15 ( V_6 , V_11 ) ;
return F_5 ( V_13 ) ;
}
void F_56 ( struct V_6 * V_6 ,
struct V_70 * V_72 )
{
struct V_8 * V_11 = V_72 -> V_11 ;
F_22 ( V_6 , V_72 -> V_42 ) ;
F_27 ( V_72 -> V_42 ) ;
F_8 ( V_72 ) ;
F_15 ( V_6 , V_11 ) ;
}
int F_57 ( struct V_6 * V_6 ,
struct V_70 * V_72 )
{
struct V_8 * V_11 = V_72 -> V_11 ;
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
int V_13 ;
V_13 = V_10 -> V_77 ( V_6 , V_11 -> V_23 , V_72 -> V_23 , V_72 -> V_42 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( & V_11 -> V_19 , & V_72 -> V_30 ,
V_20 ) ;
if ( V_13 )
goto V_78;
F_58 ( & V_72 -> V_79 , & V_6 -> V_3 -> V_80 ) ;
return 0 ;
V_78:
V_10 -> V_81 ( V_6 , V_72 -> V_23 ) ;
return V_13 ;
}
void F_59 ( struct V_6 * V_6 ,
struct V_70 * V_72 )
{
struct V_8 * V_11 = V_72 -> V_11 ;
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
F_60 ( & V_72 -> V_79 ) ;
F_12 ( & V_11 -> V_19 , & V_72 -> V_30 ,
V_20 ) ;
V_10 -> V_81 ( V_6 , V_72 -> V_23 ) ;
}
struct V_70 *
F_61 ( struct V_6 * V_6 ,
struct V_8 * V_11 ,
unsigned long V_71 )
{
return F_17 ( & V_11 -> V_19 , & V_71 ,
V_20 ) ;
}
struct V_41 *
F_62 ( struct V_70 * V_72 )
{
return V_72 -> V_42 ;
}
static int F_63 ( struct V_6 * V_6 ,
struct V_70 * V_72 )
{
struct V_8 * V_11 = V_72 -> V_11 ;
const struct V_9 * V_10 = V_11 -> V_18 . V_10 ;
bool V_82 ;
int V_13 ;
V_13 = V_10 -> V_83 ( V_6 , V_72 -> V_23 , & V_82 ) ;
if ( V_13 )
return V_13 ;
if ( V_82 )
V_72 -> V_84 = V_85 ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_70 * V_72 ;
int V_13 ;
F_65 () ;
F_66 (rule, &acl->rules, list) {
V_13 = F_63 ( V_3 -> V_6 ,
V_72 ) ;
if ( V_13 )
goto V_86;
}
F_67 () ;
return 0 ;
V_86:
F_67 () ;
return V_13 ;
}
static void F_68 ( struct V_2 * V_3 )
{
unsigned long V_87 = V_3 -> V_88 . V_87 ;
F_69 ( & V_3 -> V_88 . V_89 ,
F_70 ( V_87 ) ) ;
}
static void F_71 ( struct V_90 * V_91 )
{
struct V_2 * V_3 = F_72 ( V_91 , struct V_2 ,
V_88 . V_89 . V_91 ) ;
int V_13 ;
V_13 = F_64 ( V_3 ) ;
if ( V_13 )
F_49 ( V_3 -> V_6 -> V_68 -> V_27 , L_3 ) ;
F_68 ( V_3 ) ;
}
int F_73 ( struct V_6 * V_6 ,
struct V_70 * V_72 ,
T_5 * V_92 , T_5 * V_93 , T_5 * V_94 )
{
struct V_41 * V_42 ;
T_5 V_95 ;
T_5 V_96 ;
int V_13 ;
V_42 = F_62 ( V_72 ) ;
V_13 = F_74 ( V_6 , V_42 -> V_43 ,
& V_95 , & V_96 ) ;
if ( V_13 )
return V_13 ;
* V_92 = V_95 - V_72 -> V_97 ;
* V_93 = V_96 - V_72 -> V_98 ;
* V_94 = V_72 -> V_84 ;
V_72 -> V_98 = V_96 ;
V_72 -> V_97 = V_95 ;
return 0 ;
}
static int F_75 ( void * V_23 , T_2 * V_99 ,
char * V_100 , bool V_101 )
{
struct V_6 * V_6 = V_23 ;
char V_102 [ V_103 ] ;
T_2 V_104 ;
int V_13 ;
if ( V_101 )
return 0 ;
V_13 = F_76 ( V_6 , V_105 ,
& V_104 ) ;
if ( V_13 )
return V_13 ;
F_77 ( V_102 , V_104 , V_100 ) ;
V_13 = F_78 ( V_6 -> V_106 , F_79 ( V_107 ) , V_102 ) ;
if ( V_13 )
goto V_108;
* V_99 = V_104 ;
return 0 ;
V_108:
F_80 ( V_6 , V_104 ) ;
return V_13 ;
}
static void F_81 ( void * V_23 , T_2 V_104 ,
bool V_101 )
{
struct V_6 * V_6 = V_23 ;
if ( V_101 )
return;
F_80 ( V_6 , V_104 ) ;
}
static int F_82 ( void * V_23 , T_2 * V_99 ,
T_4 V_58 )
{
struct V_6 * V_6 = V_23 ;
char V_109 [ V_110 ] ;
T_2 V_104 ;
int V_13 ;
V_13 = F_76 ( V_6 , 1 , & V_104 ) ;
if ( V_13 )
return V_13 ;
F_83 ( V_109 , V_104 , V_58 ) ;
V_13 = F_78 ( V_6 -> V_106 , F_79 ( V_111 ) , V_109 ) ;
if ( V_13 )
goto V_112;
* V_99 = V_104 ;
return 0 ;
V_112:
F_80 ( V_6 , V_104 ) ;
return V_13 ;
}
static void F_84 ( void * V_23 , T_2 V_104 )
{
struct V_6 * V_6 = V_23 ;
F_80 ( V_6 , V_104 ) ;
}
int F_85 ( struct V_6 * V_6 )
{
const struct V_113 * V_114 = & V_115 ;
struct V_5 * V_69 ;
struct V_2 * V_3 ;
int V_13 ;
V_3 = F_4 ( sizeof( * V_3 ) + V_114 -> V_116 , V_15 ) ;
if ( ! V_3 )
return - V_16 ;
V_6 -> V_3 = V_3 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_4 = F_86 ( F_87 ( V_6 -> V_106 ,
V_117 ) ,
V_118 ,
V_119 ) ;
if ( ! V_3 -> V_4 ) {
V_13 = - V_16 ;
goto V_120;
}
V_3 -> V_46 = F_88 ( F_87 ( V_6 -> V_106 ,
V_121 ) ,
& V_122 , V_6 ) ;
if ( F_18 ( V_3 -> V_46 ) ) {
V_13 = F_26 ( V_3 -> V_46 ) ;
goto V_123;
}
V_13 = F_6 ( & V_3 -> V_29 ,
& V_31 ) ;
if ( V_13 )
goto V_21;
V_69 = F_89 ( V_6 ) ;
if ( F_18 ( V_69 ) ) {
V_13 = F_26 ( V_69 ) ;
goto V_124;
}
V_3 -> V_7 = V_69 ;
F_90 ( & V_3 -> V_80 ) ;
V_13 = V_114 -> V_125 ( V_6 , V_3 -> V_23 ) ;
if ( V_13 )
goto V_126;
V_3 -> V_10 = V_114 ;
F_91 ( & V_3 -> V_88 . V_89 ,
F_71 ) ;
V_3 -> V_88 . V_87 = V_127 ;
F_69 ( & V_3 -> V_88 . V_89 , 0 ) ;
return 0 ;
V_126:
F_92 ( V_69 ) ;
V_124:
F_7 ( & V_3 -> V_29 ) ;
V_21:
F_93 ( V_3 -> V_46 ) ;
V_123:
F_94 ( V_3 -> V_4 ) ;
V_120:
F_8 ( V_3 ) ;
return V_13 ;
}
void F_95 ( struct V_6 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_3 ;
const struct V_113 * V_114 = V_3 -> V_10 ;
F_96 ( & V_6 -> V_3 -> V_88 . V_89 ) ;
V_114 -> V_128 ( V_6 , V_3 -> V_23 ) ;
F_97 ( ! F_98 ( & V_3 -> V_80 ) ) ;
F_92 ( V_3 -> V_7 ) ;
F_7 ( & V_3 -> V_29 ) ;
F_93 ( V_3 -> V_46 ) ;
F_94 ( V_3 -> V_4 ) ;
F_8 ( V_3 ) ;
}
