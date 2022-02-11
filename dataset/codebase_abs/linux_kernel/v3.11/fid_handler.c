int F_1 ( struct V_1 * V_2 ,
struct V_3 * exp , enum V_4 type )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_6 ;
char * V_8 ;
int V_9 ;
V_10 ;
F_2 ( V_6 -> V_11 ) ;
if ( V_6 -> V_11 == NULL )
RETURN ( - V_12 ) ;
F_3 ( V_8 , V_13 + 5 ) ;
if ( V_8 == NULL )
GOTO ( V_14 , V_9 = - V_12 ) ;
snprintf ( V_8 , V_13 + 5 , L_1 , V_2 -> V_15 ) ;
V_9 = F_4 ( V_6 -> V_11 , exp , type , V_8 , NULL ) ;
F_5 ( V_8 , V_13 + 5 ) ;
if ( V_9 )
GOTO ( V_14 , V_9 ) ;
RETURN ( V_9 ) ;
V_14:
F_6 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
return V_9 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_6 ;
V_10 ;
if ( V_6 -> V_11 != NULL ) {
F_8 ( V_6 -> V_11 ) ;
F_6 ( V_6 -> V_11 ) ;
V_6 -> V_11 = NULL ;
}
RETURN ( 0 ) ;
}
int F_9 ( struct V_16 * V_17 ,
struct V_18 * V_6 ,
const struct V_19 * V_20 )
{
int V_9 = 0 ;
V_10 ;
F_10 ( & V_17 -> V_21 ) ;
if ( V_6 == NULL ) {
F_11 ( V_22 , L_2 ,
V_17 -> V_23 , V_6 -> V_24 ) ;
V_17 -> V_25 = V_6 ;
GOTO ( V_26 , V_9 = 0 ) ;
}
if ( V_17 -> V_25 != NULL ) {
F_11 ( V_27 , L_3
L_4 , V_17 -> V_23 ) ;
GOTO ( V_26 , V_9 = - V_28 ) ;
}
F_11 ( V_22 , L_5 ,
V_17 -> V_23 , V_6 -> V_24 ) ;
V_17 -> V_25 = V_6 ;
V_6 -> V_29 . V_30 = V_17 -> V_31 -> V_32 ;
EXIT ;
V_26:
F_12 ( & V_17 -> V_21 ) ;
return V_9 ;
}
static inline void F_13 ( struct V_33 * V_34 ,
struct V_33 * V_35 ,
T_1 V_36 )
{
V_36 = F_14 ( F_15 ( V_35 ) , V_36 ) ;
V_34 -> V_37 = V_35 -> V_37 ;
V_34 -> V_38 = V_35 -> V_37 + V_36 ;
V_35 -> V_37 += V_36 ;
}
static int F_16 ( struct V_16 * V_17 ,
struct V_33 * V_39 ,
const struct V_19 * V_20 )
{
struct V_33 * V_40 = & V_17 -> V_41 ;
int V_9 ;
V_10 ;
F_17 ( F_18 ( V_40 ) ) ;
if ( F_19 ( V_40 ) ) {
F_20 ( L_6 ,
V_17 -> V_23 ) ;
RETURN ( - V_42 ) ;
} else {
F_13 ( V_39 , V_40 , V_17 -> V_43 ) ;
}
V_9 = F_21 ( V_20 , V_17 , V_39 , 1 ) ;
F_22 ( L_7 V_44 L_8 ,
V_17 -> V_23 , V_9 , F_23 ( V_39 ) ) ;
RETURN ( V_9 ) ;
}
int F_24 ( struct V_16 * V_17 ,
struct V_33 * V_39 ,
const struct V_19 * V_20 )
{
int V_9 ;
V_10 ;
F_10 ( & V_17 -> V_21 ) ;
V_9 = F_16 ( V_17 , V_39 , V_20 ) ;
F_12 ( & V_17 -> V_21 ) ;
RETURN ( V_9 ) ;
}
static int F_25 ( const struct V_19 * V_20 ,
struct V_16 * V_17 )
{
struct V_33 * V_40 = & V_17 -> V_41 ;
int V_9 ;
F_13 ( & V_17 -> V_45 , V_40 , V_17 -> V_46 ) ;
F_13 ( & V_17 -> V_47 , V_40 , V_17 -> V_46 ) ;
V_9 = F_21 ( V_20 , V_17 , NULL , 1 ) ;
return V_9 ;
}
static int F_26 ( const struct V_19 * V_20 ,
struct V_33 * V_39 ,
struct V_16 * V_17 )
{
struct V_33 * V_40 = & V_17 -> V_41 ;
struct V_33 * V_48 = & V_17 -> V_45 ;
struct V_33 * V_49 = & V_17 -> V_47 ;
int V_9 = 0 ;
if ( F_27 ( V_48 ) )
F_25 ( V_20 , V_17 ) ;
if ( F_28 ( V_50 ) )
V_48 -> V_37 = V_48 -> V_38 ;
if ( F_19 ( V_48 ) ) {
struct V_51 * V_52 = V_17 -> V_31 -> V_53 -> V_54 ;
int V_55 = V_52 -> V_56 -> V_57 ;
T_1 V_58 ;
V_58 = F_29 ( V_17 -> V_46 ,
V_55 * V_17 -> V_43 ) ;
V_58 = F_14 ( F_15 ( V_40 ) , V_58 ) ;
* V_48 = * V_49 ;
F_13 ( V_49 , V_40 , V_58 ) ;
V_9 = F_21 ( V_20 , V_17 , NULL , V_17 -> V_59 ) ;
}
F_30 ( ! F_19 ( V_48 ) || F_18 ( V_48 ) ,
V_44 L_8 , F_23 ( V_48 ) ) ;
if ( V_9 == 0 )
F_13 ( V_39 , V_48 , V_17 -> V_43 ) ;
RETURN ( V_9 ) ;
}
static int F_31 ( struct V_16 * V_17 ,
struct V_33 * V_39 ,
const struct V_19 * V_20 )
{
struct V_33 * V_40 = & V_17 -> V_41 ;
int V_9 = 0 ;
V_10 ;
F_17 ( F_18 ( V_40 ) ) ;
if ( F_19 ( V_40 ) ) {
if ( ! V_17 -> V_25 ) {
F_20 ( L_9 ,
V_17 -> V_23 ) ;
RETURN ( - V_60 ) ;
}
V_9 = F_32 ( V_17 -> V_25 , V_20 ) ;
if ( V_9 ) {
F_20 ( L_10 ,
V_17 -> V_23 , V_9 ) ;
RETURN ( V_9 ) ;
}
* V_40 = V_17 -> V_25 -> V_29 ;
F_17 ( F_18 ( V_40 ) ) ;
}
V_9 = F_26 ( V_20 , V_39 , V_17 ) ;
if ( V_9 != 0 ) {
F_20 ( L_11 ,
V_17 -> V_23 , V_9 ) ;
RETURN ( V_9 ) ;
}
F_11 ( V_22 , L_12 V_44 L_8 ,
V_17 -> V_23 , F_23 ( V_39 ) ) ;
RETURN ( V_9 ) ;
}
int F_33 ( struct V_16 * V_17 ,
struct V_33 * V_39 ,
const struct V_19 * V_20 )
{
int V_9 ;
V_10 ;
F_10 ( & V_17 -> V_21 ) ;
V_9 = F_31 ( V_17 , V_39 , V_20 ) ;
F_12 ( & V_17 -> V_21 ) ;
RETURN ( V_9 ) ;
}
static int F_34 ( struct V_61 * V_62 ,
const struct V_19 * V_20 ,
T_2 V_63 , struct V_33 * V_39 )
{
int V_9 ;
struct V_64 * V_65 ;
V_10 ;
V_65 = F_35 ( V_62 ) ;
switch ( V_63 ) {
case V_66 :
if ( ! V_65 -> V_67 ) {
F_20 ( L_13
L_14 ) ;
RETURN ( - V_68 ) ;
}
V_9 = F_33 ( V_65 -> V_67 , V_39 , V_20 ) ;
break;
case V_69 :
if ( ! V_65 -> V_70 ) {
F_20 ( L_15
L_14 ) ;
RETURN ( - V_68 ) ;
}
V_9 = F_24 ( V_65 -> V_70 , V_39 , V_20 ) ;
break;
default:
V_9 = - V_68 ;
break;
}
RETURN ( V_9 ) ;
}
static int F_36 ( struct V_71 * V_72 ,
const struct V_19 * V_20 ,
struct V_73 * V_74 )
{
struct V_33 * V_39 , * V_75 ;
struct V_61 * V_62 ;
int V_9 = - V_76 ;
T_2 * V_63 ;
V_10 ;
F_17 ( ! ( F_37 ( V_72 -> V_77 ) & V_78 ) ) ;
V_62 = V_72 -> V_79 -> V_80 -> V_81 -> V_82 ;
F_17 ( V_62 != NULL ) ;
V_9 = F_38 ( V_74 -> V_83 ) ;
if ( V_9 )
RETURN ( F_39 ( V_9 ) ) ;
V_63 = F_40 ( V_74 -> V_83 , & V_84 ) ;
if ( V_63 != NULL ) {
V_39 = F_41 ( V_74 -> V_83 , & V_85 ) ;
if ( V_39 == NULL )
RETURN ( F_39 ( - V_76 ) ) ;
V_75 = F_40 ( V_74 -> V_83 , & V_85 ) ;
V_39 -> V_30 = V_75 -> V_30 ;
V_39 -> V_86 = V_75 -> V_86 ;
V_9 = F_34 ( V_62 , V_20 , * V_63 , V_39 ) ;
} else
V_9 = F_39 ( - V_76 ) ;
RETURN ( V_9 ) ;
}
static void F_42 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
V_74 -> V_83 = & V_72 -> V_87 ;
F_43 ( V_74 -> V_83 , V_72 , V_88 ) ;
F_44 ( V_74 -> V_83 , & V_89 ) ;
}
static void F_45 ( struct V_73 * V_74 )
{
F_46 ( V_74 -> V_83 ) ;
}
int F_47 ( struct V_71 * V_72 )
{
const struct V_19 * V_20 ;
struct V_73 * V_74 ;
int V_9 ;
V_20 = V_72 -> V_90 -> V_91 ;
F_17 ( V_20 != NULL ) ;
V_74 = F_48 ( & V_20 -> V_92 , & V_93 ) ;
F_17 ( V_74 != NULL ) ;
F_42 ( V_72 , V_74 ) ;
V_9 = F_36 ( V_72 , V_20 , V_74 ) ;
F_49 ( V_72 -> V_94 , 0 ) ;
F_45 ( V_74 ) ;
return V_9 ;
}
int F_50 ( struct V_95 * V_74 )
{
return F_47 ( V_74 -> V_96 -> V_97 ) ;
}
static int F_51 ( struct V_16 * V_17 )
{
int V_9 ;
V_10 ;
V_17 -> V_98 = F_52 ( V_17 -> V_23 ,
V_99 ,
NULL , NULL ) ;
if ( F_53 ( V_17 -> V_98 ) ) {
V_9 = F_54 ( V_17 -> V_98 ) ;
RETURN ( V_9 ) ;
}
V_9 = F_55 ( V_17 -> V_98 ,
V_100 , V_17 ) ;
if ( V_9 ) {
F_20 ( L_16
L_17 , V_17 -> V_23 , V_9 ) ;
GOTO ( V_101 , V_9 ) ;
}
RETURN ( 0 ) ;
V_101:
F_56 ( V_17 ) ;
return V_9 ;
}
static void F_56 ( struct V_16 * V_17 )
{
V_10 ;
if ( V_17 -> V_98 != NULL ) {
if ( ! F_53 ( V_17 -> V_98 ) )
F_57 ( & V_17 -> V_98 ) ;
V_17 -> V_98 = NULL ;
}
EXIT ;
}
static int F_51 ( struct V_16 * V_17 )
{
return 0 ;
}
static void F_56 ( struct V_16 * V_17 )
{
return;
}
int F_58 ( struct V_16 * V_17 ,
struct V_102 * V_52 ,
const char * V_8 ,
enum V_103 type ,
struct V_64 * V_104 ,
const struct V_19 * V_20 )
{
int V_9 , V_105 = ( type == V_106 ) ;
V_10 ;
F_17 ( V_52 != NULL ) ;
F_17 ( V_8 != NULL ) ;
F_17 ( V_104 != NULL ) ;
F_17 ( V_104 -> V_53 != NULL ) ;
V_17 -> V_25 = NULL ;
V_17 -> V_107 = type ;
V_17 -> V_31 = V_104 ;
F_59 ( & V_17 -> V_41 ) ;
F_59 ( & V_17 -> V_45 ) ;
F_59 ( & V_17 -> V_47 ) ;
V_17 -> V_46 = V_108 ;
F_60 ( & V_17 -> V_21 ) ;
V_17 -> V_43 = V_105 ?
V_109 : V_110 ;
snprintf ( V_17 -> V_23 , sizeof( V_17 -> V_23 ) ,
L_18 , ( V_105 ? L_19 : L_20 ) , V_8 ) ;
V_9 = F_61 ( V_17 , V_20 , V_52 ) ;
if ( V_9 )
GOTO ( V_39 , V_9 ) ;
V_9 = F_62 ( V_17 , V_20 ) ;
if ( V_9 == - V_111 ) {
V_17 -> V_41 = V_105 ?
V_112 :
V_113 ;
F_17 ( V_104 != NULL ) ;
V_17 -> V_41 . V_30 = V_104 -> V_32 ;
F_22 ( L_21
L_22 ,
V_17 -> V_23 ) ;
V_9 = F_21 ( V_20 , V_17 , NULL , 0 ) ;
if ( V_9 ) {
F_20 ( L_23
L_24 , V_17 -> V_23 , V_9 ) ;
}
} else if ( V_9 ) {
F_20 ( L_25 ,
V_17 -> V_23 , V_9 ) ;
GOTO ( V_39 , V_9 ) ;
}
if ( V_105 ) {
F_17 ( F_18 ( & V_17 -> V_41 ) ) ;
} else {
F_17 ( ! F_27 ( & V_17 -> V_41 ) &&
F_18 ( & V_17 -> V_41 ) ) ;
}
V_9 = F_51 ( V_17 ) ;
if ( V_9 )
GOTO ( V_39 , V_9 ) ;
EXIT ;
V_39:
if ( V_9 )
F_63 ( V_17 , V_20 ) ;
return V_9 ;
}
void F_63 ( struct V_16 * V_17 ,
const struct V_19 * V_20 )
{
V_10 ;
F_56 ( V_17 ) ;
F_64 ( V_17 , V_20 ) ;
EXIT ;
}
int F_65 ( const struct V_19 * V_20 , struct V_64 * V_104 )
{
if ( V_104 == NULL )
RETURN ( 0 ) ;
if ( V_104 -> V_67 ) {
F_63 ( V_104 -> V_67 , V_20 ) ;
F_6 ( V_104 -> V_67 ) ;
V_104 -> V_67 = NULL ;
}
if ( V_104 -> V_70 ) {
F_63 ( V_104 -> V_70 , V_20 ) ;
F_6 ( V_104 -> V_70 ) ;
V_104 -> V_70 = NULL ;
}
if ( V_104 -> V_114 ) {
F_8 ( V_104 -> V_114 ) ;
F_6 ( V_104 -> V_114 ) ;
V_104 -> V_114 = NULL ;
}
RETURN ( 0 ) ;
}
static int T_3 F_66 ( void )
{
V_99 = F_52 ( V_115 ,
V_116 ,
NULL , NULL ) ;
if ( F_53 ( V_99 ) )
return F_54 ( V_99 ) ;
F_67 ( & V_93 ) ;
F_68 ( & V_93 ) ;
return 0 ;
}
static void T_4 F_69 ( void )
{
F_70 ( & V_93 ) ;
if ( V_99 != NULL && ! F_53 ( V_99 ) ) {
F_57 ( & V_99 ) ;
V_99 = NULL ;
}
}
