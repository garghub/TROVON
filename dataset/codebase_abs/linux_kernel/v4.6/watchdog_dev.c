static inline bool F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 ;
unsigned int V_5 = V_2 -> V_6 * 1000 ;
return V_3 && ( ( F_2 ( V_2 ) && V_5 > V_3 ) ||
( V_5 && ! F_2 ( V_2 ) && F_3 ( V_2 ) ) ) ;
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
V_8 -> V_14 = V_15 ;
return F_11 ( V_2 ) ;
}
static void F_14 ( struct V_25 * V_17 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
V_8 = F_15 ( F_16 ( V_17 ) , struct V_7 ,
V_17 ) ;
F_17 ( & V_8 -> V_26 ) ;
V_2 = V_8 -> V_2 ;
if ( V_2 && ( F_2 ( V_2 ) || F_3 ( V_2 ) ) )
F_11 ( V_2 ) ;
F_18 ( & V_8 -> V_26 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_27 ;
int V_21 ;
if ( F_2 ( V_2 ) )
return 0 ;
V_27 = V_15 ;
if ( F_3 ( V_2 ) && V_2 -> V_22 -> V_23 )
V_21 = V_2 -> V_22 -> V_23 ( V_2 ) ;
else
V_21 = V_2 -> V_22 -> V_24 ( V_2 ) ;
if ( V_21 == 0 ) {
F_20 ( V_28 , & V_2 -> V_29 ) ;
V_8 -> V_14 = V_27 ;
F_8 ( V_2 ) ;
}
return V_21 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
if ( F_22 ( V_30 , & V_2 -> V_29 ) ) {
F_23 ( L_1 ,
V_2 -> V_31 ) ;
return - V_32 ;
}
if ( V_2 -> V_22 -> V_33 )
V_21 = V_2 -> V_22 -> V_33 ( V_2 ) ;
else
F_20 ( V_34 , & V_2 -> V_29 ) ;
if ( V_21 == 0 ) {
F_24 ( V_28 , & V_2 -> V_29 ) ;
F_8 ( V_2 ) ;
}
return V_21 ;
}
static unsigned int F_25 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_22 -> V_29 )
return 0 ;
return V_2 -> V_22 -> V_29 ( V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
int V_21 = 0 ;
if ( ! ( V_2 -> V_35 -> V_36 & V_37 ) )
return - V_38 ;
if ( F_27 ( V_2 , V_6 ) )
return - V_39 ;
if ( V_2 -> V_22 -> V_40 )
V_21 = V_2 -> V_22 -> V_40 ( V_2 , V_6 ) ;
else
V_2 -> V_6 = V_6 ;
F_8 ( V_2 ) ;
return V_21 ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned int * V_41 )
{
* V_41 = 0 ;
if ( ! V_2 -> V_22 -> V_42 )
return - V_38 ;
* V_41 = V_2 -> V_22 -> V_42 ( V_2 ) ;
return 0 ;
}
static T_1 F_29 ( struct V_43 * V_44 , struct V_45 * V_46 ,
char * V_47 )
{
struct V_1 * V_2 = F_30 ( V_44 ) ;
return sprintf ( V_47 , L_2 , ! ! F_22 ( V_30 , & V_2 -> V_29 ) ) ;
}
static T_1 F_31 ( struct V_43 * V_44 , struct V_45 * V_46 ,
char * V_47 )
{
struct V_1 * V_2 = F_30 ( V_44 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned int V_29 ;
F_17 ( & V_8 -> V_26 ) ;
V_29 = F_25 ( V_2 ) ;
F_18 ( & V_8 -> V_26 ) ;
return sprintf ( V_47 , L_3 , V_29 ) ;
}
static T_1 F_32 ( struct V_43 * V_44 ,
struct V_45 * V_46 , char * V_47 )
{
struct V_1 * V_2 = F_30 ( V_44 ) ;
return sprintf ( V_47 , L_3 , V_2 -> V_48 ) ;
}
static T_1 F_33 ( struct V_43 * V_44 , struct V_45 * V_46 ,
char * V_47 )
{
struct V_1 * V_2 = F_30 ( V_44 ) ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_1 V_29 ;
unsigned int V_49 ;
F_17 ( & V_8 -> V_26 ) ;
V_29 = F_28 ( V_2 , & V_49 ) ;
F_18 ( & V_8 -> V_26 ) ;
if ( ! V_29 )
V_29 = sprintf ( V_47 , L_3 , V_49 ) ;
return V_29 ;
}
static T_1 F_34 ( struct V_43 * V_44 , struct V_45 * V_46 ,
char * V_47 )
{
struct V_1 * V_2 = F_30 ( V_44 ) ;
return sprintf ( V_47 , L_3 , V_2 -> V_6 ) ;
}
static T_1 F_35 ( struct V_43 * V_44 , struct V_45 * V_46 ,
char * V_47 )
{
struct V_1 * V_2 = F_30 ( V_44 ) ;
return sprintf ( V_47 , L_4 , V_2 -> V_35 -> V_50 ) ;
}
static T_1 F_36 ( struct V_43 * V_44 , struct V_45 * V_46 ,
char * V_47 )
{
struct V_1 * V_2 = F_30 ( V_44 ) ;
if ( F_2 ( V_2 ) )
return sprintf ( V_47 , L_5 ) ;
return sprintf ( V_47 , L_6 ) ;
}
static T_2 F_37 ( struct V_51 * V_52 , struct V_53 * V_46 ,
int V_54 )
{
struct V_43 * V_44 = F_15 ( V_52 , struct V_43 , V_52 ) ;
struct V_1 * V_2 = F_30 ( V_44 ) ;
T_2 V_55 = V_46 -> V_55 ;
if ( V_46 == & V_56 . V_46 && ! V_2 -> V_22 -> V_29 )
V_55 = 0 ;
else if ( V_46 == & V_57 . V_46 && ! V_2 -> V_22 -> V_42 )
V_55 = 0 ;
return V_55 ;
}
static int F_38 ( struct V_1 * V_2 , unsigned int V_58 ,
unsigned long V_59 )
{
if ( ! V_2 -> V_22 -> V_60 )
return - V_61 ;
return V_2 -> V_22 -> V_60 ( V_2 , V_58 , V_59 ) ;
}
static T_1 F_39 ( struct V_62 * V_62 , const char T_3 * V_63 ,
T_4 V_64 , T_5 * V_65 )
{
struct V_7 * V_8 = V_62 -> V_66 ;
struct V_1 * V_2 ;
int V_21 ;
T_4 V_67 ;
char V_68 ;
if ( V_64 == 0 )
return 0 ;
F_24 ( V_69 , & V_8 -> V_29 ) ;
for ( V_67 = 0 ; V_67 != V_64 ; V_67 ++ ) {
if ( F_40 ( V_68 , V_63 + V_67 ) )
return - V_70 ;
if ( V_68 == 'V' )
F_20 ( V_69 , & V_8 -> V_29 ) ;
}
V_21 = - V_71 ;
F_17 ( & V_8 -> V_26 ) ;
V_2 = V_8 -> V_2 ;
if ( V_2 )
V_21 = F_13 ( V_2 ) ;
F_18 ( & V_8 -> V_26 ) ;
if ( V_21 < 0 )
return V_21 ;
return V_64 ;
}
static long F_41 ( struct V_62 * V_62 , unsigned int V_58 ,
unsigned long V_59 )
{
struct V_7 * V_8 = V_62 -> V_66 ;
void T_3 * V_72 = ( void T_3 * ) V_59 ;
struct V_1 * V_2 ;
int T_3 * V_73 = V_72 ;
unsigned int V_49 ;
int V_21 ;
F_17 ( & V_8 -> V_26 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_2 ) {
V_21 = - V_71 ;
goto V_74;
}
V_21 = F_38 ( V_2 , V_58 , V_59 ) ;
if ( V_21 != - V_61 )
goto V_74;
switch ( V_58 ) {
case V_75 :
V_21 = F_42 ( V_72 , V_2 -> V_35 ,
sizeof( struct V_76 ) ) ? - V_70 : 0 ;
break;
case V_77 :
V_49 = F_25 ( V_2 ) ;
V_21 = F_43 ( V_49 , V_73 ) ;
break;
case V_78 :
V_21 = F_43 ( V_2 -> V_48 , V_73 ) ;
break;
case V_79 :
if ( F_40 ( V_49 , V_73 ) ) {
V_21 = - V_70 ;
break;
}
if ( V_49 & V_80 ) {
V_21 = F_21 ( V_2 ) ;
if ( V_21 < 0 )
break;
}
if ( V_49 & V_81 )
V_21 = F_19 ( V_2 ) ;
break;
case V_82 :
if ( ! ( V_2 -> V_35 -> V_36 & V_83 ) ) {
V_21 = - V_38 ;
break;
}
V_21 = F_13 ( V_2 ) ;
break;
case V_84 :
if ( F_40 ( V_49 , V_73 ) ) {
V_21 = - V_70 ;
break;
}
V_21 = F_26 ( V_2 , V_49 ) ;
if ( V_21 < 0 )
break;
V_21 = F_13 ( V_2 ) ;
if ( V_21 < 0 )
break;
case V_85 :
if ( V_2 -> V_6 == 0 ) {
V_21 = - V_38 ;
break;
}
V_21 = F_43 ( V_2 -> V_6 , V_73 ) ;
break;
case V_86 :
V_21 = F_28 ( V_2 , & V_49 ) ;
if ( V_21 < 0 )
break;
V_21 = F_43 ( V_49 , V_73 ) ;
break;
default:
V_21 = - V_87 ;
break;
}
V_74:
F_18 ( & V_8 -> V_26 ) ;
return V_21 ;
}
static int F_44 ( struct V_88 * V_88 , struct V_62 * V_62 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_21 ;
if ( F_45 ( V_88 ) == V_89 )
V_8 = V_90 ;
else
V_8 = F_15 ( V_88 -> V_91 , struct V_7 ,
V_92 ) ;
if ( F_46 ( V_93 , & V_8 -> V_29 ) )
return - V_32 ;
V_2 = V_8 -> V_2 ;
if ( ! F_3 ( V_2 ) && ! F_47 ( V_2 -> V_22 -> V_94 ) ) {
V_21 = - V_32 ;
goto V_95;
}
V_21 = F_19 ( V_2 ) ;
if ( V_21 < 0 )
goto V_96;
V_62 -> V_66 = V_8 ;
if ( ! F_3 ( V_2 ) )
F_48 ( & V_8 -> V_97 ) ;
return F_49 ( V_88 , V_62 ) ;
V_96:
F_50 ( V_8 -> V_2 -> V_22 -> V_94 ) ;
V_95:
F_24 ( V_93 , & V_8 -> V_29 ) ;
return V_21 ;
}
static void F_51 ( struct V_97 * V_97 )
{
struct V_7 * V_8 ;
V_8 = F_15 ( V_97 , struct V_7 , V_97 ) ;
F_52 ( V_8 ) ;
}
static int F_53 ( struct V_88 * V_88 , struct V_62 * V_62 )
{
struct V_7 * V_8 = V_62 -> V_66 ;
struct V_1 * V_2 ;
int V_21 = - V_32 ;
bool V_98 ;
F_17 ( & V_8 -> V_26 ) ;
V_2 = V_8 -> V_2 ;
if ( ! V_2 )
goto V_99;
if ( ! F_22 ( V_28 , & V_2 -> V_29 ) )
V_21 = 0 ;
else if ( F_54 ( V_69 , & V_8 -> V_29 ) ||
! ( V_2 -> V_35 -> V_36 & V_100 ) )
V_21 = F_21 ( V_2 ) ;
if ( V_21 < 0 ) {
F_55 ( L_7 , V_2 -> V_31 ) ;
F_13 ( V_2 ) ;
}
F_56 ( & V_8 -> V_17 ) ;
F_8 ( V_2 ) ;
F_24 ( V_93 , & V_8 -> V_29 ) ;
V_99:
V_98 = V_2 && F_3 ( V_2 ) ;
F_18 ( & V_8 -> V_26 ) ;
if ( ! V_98 ) {
F_50 ( V_8 -> V_92 . V_94 ) ;
F_57 ( & V_8 -> V_97 , F_51 ) ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 , T_6 V_101 )
{
struct V_7 * V_8 ;
int V_21 ;
V_8 = F_59 ( sizeof( struct V_7 ) , V_102 ) ;
if ( ! V_8 )
return - V_103 ;
F_60 ( & V_8 -> V_97 ) ;
F_61 ( & V_8 -> V_26 ) ;
V_8 -> V_2 = V_2 ;
V_2 -> V_8 = V_8 ;
if ( ! V_16 )
return - V_71 ;
F_62 ( & V_8 -> V_17 , F_14 ) ;
if ( V_2 -> V_31 == 0 ) {
V_90 = V_8 ;
V_104 . V_105 = V_2 -> V_105 ;
V_21 = F_63 ( & V_104 ) ;
if ( V_21 != 0 ) {
F_64 ( L_8 ,
V_2 -> V_35 -> V_50 , V_106 , V_21 ) ;
if ( V_21 == - V_32 )
F_64 ( L_9 ,
V_2 -> V_35 -> V_50 ) ;
V_90 = NULL ;
F_52 ( V_8 ) ;
return V_21 ;
}
}
F_65 ( & V_8 -> V_92 , & V_107 ) ;
V_8 -> V_92 . V_94 = V_2 -> V_22 -> V_94 ;
V_21 = F_66 ( & V_8 -> V_92 , V_101 , 1 ) ;
if ( V_21 ) {
F_64 ( L_10 ,
V_2 -> V_31 , F_67 ( V_108 ) , V_2 -> V_31 ) ;
if ( V_2 -> V_31 == 0 ) {
F_68 ( & V_104 ) ;
V_90 = NULL ;
F_57 ( & V_8 -> V_97 , F_51 ) ;
}
return V_21 ;
}
V_8 -> V_19 = V_15 - 1 ;
if ( F_3 ( V_2 ) ) {
F_69 ( V_2 -> V_22 -> V_94 ) ;
F_48 ( & V_8 -> V_97 ) ;
F_70 ( V_16 , & V_8 -> V_17 , 0 ) ;
}
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
F_72 ( & V_8 -> V_92 ) ;
if ( V_2 -> V_31 == 0 ) {
F_68 ( & V_104 ) ;
V_90 = NULL ;
}
F_17 ( & V_8 -> V_26 ) ;
V_8 -> V_2 = NULL ;
V_2 -> V_8 = NULL ;
F_18 ( & V_8 -> V_26 ) ;
F_56 ( & V_8 -> V_17 ) ;
F_57 ( & V_8 -> V_97 , F_51 ) ;
}
int F_73 ( struct V_1 * V_2 )
{
struct V_43 * V_44 ;
T_6 V_101 ;
int V_109 ;
V_101 = F_74 ( F_67 ( V_108 ) , V_2 -> V_31 ) ;
V_109 = F_58 ( V_2 , V_101 ) ;
if ( V_109 )
return V_109 ;
V_44 = F_75 ( & V_110 , V_2 -> V_105 ,
V_101 , V_2 , V_2 -> V_111 ,
L_11 , V_2 -> V_31 ) ;
if ( F_76 ( V_44 ) ) {
F_71 ( V_2 ) ;
return F_77 ( V_44 ) ;
}
return V_109 ;
}
void F_78 ( struct V_1 * V_2 )
{
F_79 ( & V_110 , V_2 -> V_8 -> V_92 . V_44 ) ;
F_71 ( V_2 ) ;
}
int T_7 F_80 ( void )
{
int V_21 ;
V_16 = F_81 ( L_12 ,
V_112 | V_113 , 0 ) ;
if ( ! V_16 ) {
F_64 ( L_13 ) ;
return - V_103 ;
}
V_21 = F_82 ( & V_110 ) ;
if ( V_21 < 0 ) {
F_64 ( L_14 ) ;
return V_21 ;
}
V_21 = F_83 ( & V_108 , 0 , V_114 , L_15 ) ;
if ( V_21 < 0 ) {
F_64 ( L_16 ) ;
F_84 ( & V_110 ) ;
return V_21 ;
}
return 0 ;
}
void T_8 F_85 ( void )
{
F_86 ( V_108 , V_114 ) ;
F_84 ( & V_110 ) ;
F_87 ( V_16 ) ;
}
