static int F_1 ( void )
{
int V_1 ;
F_2 ( L_1 ) ;
V_1 = F_3 ( & V_2 . V_3 -> V_4 ) ;
F_4 ( V_1 < 0 ) ;
if ( V_1 < 0 )
return V_1 ;
return 0 ;
}
static void F_5 ( void )
{
int V_1 ;
F_2 ( L_2 ) ;
V_1 = F_6 ( & V_2 . V_3 -> V_4 ) ;
F_4 ( V_1 < 0 && V_1 != - V_5 ) ;
}
static T_1 F_7 ( int V_6 , void * V_7 )
{
struct V_8 * V_9 = V_7 ;
T_2 V_10 ;
V_10 = F_8 ( V_9 ) ;
F_9 ( V_9 , V_10 ) ;
if ( ( V_10 & V_11 ) &&
V_10 & V_12 ) {
F_10 ( V_9 , V_13 ) ;
F_9 ( V_9 , V_11 |
V_12 ) ;
F_10 ( V_9 , V_14 ) ;
} else if ( V_10 & V_11 ) {
F_10 ( V_9 , V_15 ) ;
} else if ( V_10 & V_12 ) {
F_10 ( V_9 , V_14 ) ;
}
return V_16 ;
}
static int F_11 ( void )
{
int V_1 ;
struct V_17 * V_18 ;
if ( V_2 . V_19 != NULL )
return 0 ;
V_18 = F_12 ( & V_2 . V_3 -> V_4 , L_3 ) ;
if ( F_13 ( V_18 ) ) {
if ( F_14 ( V_18 ) != - V_20 )
F_15 ( L_4 ) ;
return F_14 ( V_18 ) ;
}
if ( F_16 ( V_18 ) ) {
V_1 = F_17 ( V_18 , 1800000 , 1800000 ) ;
if ( V_1 ) {
F_18 ( V_18 ) ;
F_19 ( L_5 ) ;
return V_1 ;
}
}
V_2 . V_19 = V_18 ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 )
{
int V_1 ;
V_1 = F_21 ( V_2 . V_19 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 () ;
if ( V_1 )
goto V_23;
F_22 ( V_24 ) ;
V_2 . V_25 = true ;
return 0 ;
V_23:
F_23 ( V_2 . V_19 ) ;
return V_1 ;
}
static void F_24 ( struct V_21 * V_22 )
{
V_2 . V_25 = false ;
F_5 () ;
F_23 ( V_2 . V_19 ) ;
}
static int F_25 ( struct V_21 * V_22 )
{
int V_1 ;
struct V_26 * V_27 ;
struct V_28 * V_29 = V_2 . V_30 . V_31 ;
struct V_8 * V_9 = & V_2 . V_9 ;
struct V_32 V_33 = { 0 } ;
V_1 = F_20 ( V_22 ) ;
if ( V_1 )
return V_1 ;
F_26 ( V_9 , 0xffffffff ) ;
F_9 ( V_9 , 0xffffffff ) ;
V_27 = & V_2 . V_34 . V_35 ;
F_2 ( L_6 , V_27 -> V_36 , V_27 -> V_37 ) ;
F_27 ( & V_2 . V_38 , V_27 -> V_39 , & V_33 ) ;
V_1 = F_28 ( & V_2 . V_38 . V_38 ) ;
if ( V_1 ) {
F_15 ( L_7 ) ;
goto V_40;
}
V_1 = F_29 ( & V_2 . V_38 . V_38 , & V_33 ) ;
if ( V_1 ) {
F_15 ( L_8 ) ;
goto V_41;
}
V_1 = F_30 ( & V_2 . V_42 , V_33 . V_43 ,
V_33 . V_44 [ 0 ] ) ;
if ( V_1 ) {
F_2 ( L_9 ) ;
goto V_45;
}
V_1 = F_10 ( V_9 , V_14 ) ;
if ( V_1 )
goto V_46;
F_31 ( & V_2 . V_47 , & V_2 . V_9 , & V_2 . V_34 ) ;
F_32 ( 0 ) ;
F_33 ( V_29 , V_27 ) ;
V_1 = F_34 ( & V_2 . V_9 ) ;
if ( V_1 )
goto V_48;
V_1 = F_35 ( V_29 ) ;
if ( V_1 )
goto V_49;
F_36 ( V_9 ,
V_11 | V_12 ) ;
return 0 ;
V_49:
F_37 ( & V_2 . V_9 ) ;
V_48:
F_10 ( & V_2 . V_9 , V_13 ) ;
V_46:
V_45:
V_41:
F_38 ( & V_2 . V_38 . V_38 ) ;
V_40:
F_24 ( V_22 ) ;
return - V_50 ;
}
static void F_39 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = V_2 . V_30 . V_31 ;
F_26 ( & V_2 . V_9 , 0xffffffff ) ;
F_40 ( V_29 ) ;
F_37 ( & V_2 . V_9 ) ;
F_10 ( & V_2 . V_9 , V_13 ) ;
F_38 ( & V_2 . V_38 . V_38 ) ;
F_24 ( V_22 ) ;
}
static int F_41 ( struct V_21 * V_22 ,
struct V_26 * V_35 )
{
struct V_21 * V_51 = & V_2 . V_30 ;
if ( ! F_42 ( V_51 -> V_52 , V_35 ) )
return - V_53 ;
return 0 ;
}
static void F_43 ( struct V_21 * V_22 ,
struct V_26 * V_35 )
{
F_44 ( & V_2 . V_54 ) ;
V_2 . V_34 . V_35 = * V_35 ;
F_45 ( V_35 -> V_39 ) ;
F_46 ( & V_2 . V_54 ) ;
}
static void F_47 ( struct V_21 * V_22 ,
struct V_26 * V_35 )
{
* V_35 = V_2 . V_34 . V_35 ;
}
static void F_48 ( struct V_55 * V_56 )
{
F_44 ( & V_2 . V_54 ) ;
if ( F_1 () ) {
F_46 ( & V_2 . V_54 ) ;
return;
}
F_49 ( & V_2 . V_9 , V_56 ) ;
F_50 ( & V_2 . V_38 , V_56 ) ;
F_51 ( & V_2 . V_42 , V_56 ) ;
F_52 ( & V_2 . V_47 , V_56 ) ;
F_5 () ;
F_46 ( & V_2 . V_54 ) ;
}
static int F_53 ( T_3 * V_57 , int V_58 )
{
int V_1 ;
F_44 ( & V_2 . V_54 ) ;
V_1 = F_1 () ;
F_54 ( V_1 ) ;
V_1 = F_55 ( & V_2 . V_47 , V_57 , V_58 ) ;
F_5 () ;
F_46 ( & V_2 . V_54 ) ;
return V_1 ;
}
static int F_56 ( struct V_21 * V_22 )
{
struct V_21 * V_51 = & V_2 . V_30 ;
int V_1 = 0 ;
F_2 ( L_10 ) ;
F_44 ( & V_2 . V_54 ) ;
if ( V_51 == NULL || V_51 -> V_31 == NULL ) {
F_15 ( L_11 ) ;
V_1 = - V_59 ;
goto V_60;
}
V_1 = F_25 ( V_22 ) ;
if ( V_1 ) {
F_15 ( L_12 ) ;
goto V_60;
}
V_2 . V_61 = true ;
F_46 ( & V_2 . V_54 ) ;
return 0 ;
V_60:
F_46 ( & V_2 . V_54 ) ;
return V_1 ;
}
static void F_57 ( struct V_21 * V_22 )
{
F_2 ( L_13 ) ;
F_44 ( & V_2 . V_54 ) ;
if ( V_2 . V_62 && V_2 . V_63 )
V_2 . V_63 ( & V_2 . V_62 -> V_4 ) ;
F_39 ( V_22 ) ;
V_2 . V_61 = false ;
F_46 ( & V_2 . V_54 ) ;
}
static int F_58 ( struct V_21 * V_22 )
{
int V_1 = 0 ;
F_2 ( L_14 ) ;
F_44 ( & V_2 . V_54 ) ;
V_1 = F_20 ( V_22 ) ;
if ( V_1 ) {
F_15 ( L_12 ) ;
goto V_60;
}
F_46 ( & V_2 . V_54 ) ;
return 0 ;
V_60:
F_46 ( & V_2 . V_54 ) ;
return V_1 ;
}
static void F_59 ( struct V_21 * V_22 )
{
F_2 ( L_15 ) ;
F_44 ( & V_2 . V_54 ) ;
F_24 ( V_22 ) ;
F_46 ( & V_2 . V_54 ) ;
}
static int F_60 ( struct V_21 * V_22 ,
struct V_21 * V_64 )
{
struct V_28 * V_29 ;
int V_1 ;
V_1 = F_11 () ;
if ( V_1 )
return V_1 ;
V_29 = F_61 ( V_22 -> V_52 ) ;
if ( ! V_29 )
return - V_59 ;
V_1 = F_62 ( V_29 , V_22 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_63 ( V_22 , V_64 ) ;
if ( V_1 ) {
F_15 ( L_16 ,
V_64 -> V_65 ) ;
F_64 ( V_29 , V_22 ) ;
return V_1 ;
}
return 0 ;
}
static void F_65 ( struct V_21 * V_22 ,
struct V_21 * V_64 )
{
F_4 ( V_64 != V_22 -> V_64 ) ;
if ( V_64 != V_22 -> V_64 )
return;
F_66 ( V_22 ) ;
if ( V_22 -> V_31 )
F_64 ( V_22 -> V_31 , V_22 ) ;
}
static int F_67 ( struct V_21 * V_22 ,
T_3 * V_66 , int V_58 )
{
bool V_67 ;
int V_1 ;
V_67 = V_2 . V_25 == false ;
if ( V_67 ) {
V_1 = F_58 ( V_22 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_53 ( V_66 , V_58 ) ;
if ( V_67 )
F_59 ( V_22 ) ;
return V_1 ;
}
static int F_68 ( struct V_21 * V_22 ,
const struct V_68 * V_69 )
{
V_2 . V_34 . V_70 = * V_69 ;
return 0 ;
}
static int F_69 ( struct V_21 * V_22 ,
bool V_71 )
{
V_2 . V_34 . V_72 = V_71 ? V_73 : V_74 ;
return 0 ;
}
static void F_70 ( struct V_75 * V_3 )
{
struct V_21 * V_51 = & V_2 . V_30 ;
V_51 -> V_4 = & V_3 -> V_4 ;
V_51 -> V_76 = V_77 ;
V_51 -> V_78 = V_79 ;
V_51 -> V_65 = L_17 ;
V_51 -> V_52 = V_80 ;
V_51 -> V_81 . V_2 = & V_82 ;
V_51 -> V_83 = V_84 ;
F_71 ( V_51 ) ;
}
static void F_72 ( struct V_75 * V_3 )
{
struct V_21 * V_51 = & V_2 . V_30 ;
F_73 ( V_51 ) ;
}
static int F_74 ( struct V_75 * V_3 )
{
struct V_85 * V_86 = V_3 -> V_4 . V_87 ;
struct V_85 * V_88 ;
int V_1 ;
V_88 = F_75 ( V_86 ) ;
if ( ! V_88 )
return 0 ;
V_1 = F_76 ( V_3 , V_88 , & V_2 . V_42 ) ;
if ( V_1 )
goto V_89;
F_77 ( V_88 ) ;
return 0 ;
V_89:
F_77 ( V_88 ) ;
return V_1 ;
}
static int F_78 ( struct V_90 * V_4 ,
void (* F_79)( struct V_90 * V_4 ) )
{
struct V_91 * V_92 = F_80 ( V_4 ) ;
int V_93 = 0 ;
F_44 ( & V_92 -> V_54 ) ;
if ( ! F_81 ( & V_92 -> V_34 ) || ! V_92 -> V_61 ) {
V_93 = - V_94 ;
goto V_51;
}
V_92 -> V_63 = F_79 ;
V_51:
F_46 ( & V_92 -> V_54 ) ;
return V_93 ;
}
static int F_82 ( struct V_90 * V_4 )
{
struct V_91 * V_92 = F_80 ( V_4 ) ;
F_44 ( & V_92 -> V_54 ) ;
V_92 -> V_63 = NULL ;
F_46 ( & V_92 -> V_54 ) ;
return 0 ;
}
static int F_83 ( struct V_90 * V_4 )
{
struct V_91 * V_92 = F_80 ( V_4 ) ;
F_4 ( ! F_81 ( & V_92 -> V_34 ) ) ;
F_4 ( ! V_92 -> V_61 ) ;
F_84 ( & V_92 -> V_9 , true ) ;
F_85 ( & V_92 -> V_47 , & V_92 -> V_9 ) ;
return 0 ;
}
static void F_86 ( struct V_90 * V_4 )
{
struct V_91 * V_92 = F_80 ( V_4 ) ;
F_4 ( ! F_81 ( & V_92 -> V_34 ) ) ;
F_4 ( ! V_92 -> V_61 ) ;
F_87 ( & V_92 -> V_47 , & V_92 -> V_9 ) ;
F_84 ( & V_92 -> V_9 , false ) ;
}
static int F_88 ( struct V_90 * V_4 ,
struct V_95 * V_96 )
{
struct V_91 * V_92 = F_80 ( V_4 ) ;
int V_93 ;
F_44 ( & V_92 -> V_54 ) ;
if ( ! F_81 ( & V_92 -> V_34 ) || ! V_92 -> V_61 ) {
V_93 = - V_94 ;
goto V_51;
}
V_93 = F_89 ( & V_92 -> V_47 , & V_92 -> V_9 , V_96 ,
V_92 -> V_34 . V_35 . V_39 ) ;
V_51:
F_46 ( & V_92 -> V_54 ) ;
return V_93 ;
}
static int F_90 ( struct V_90 * V_4 )
{
struct V_97 V_98 = {
. V_4 = V_4 ,
. V_99 = F_91 () ,
. V_100 = F_92 ( & V_2 . V_9 ) ,
. V_81 = & V_101 ,
} ;
V_2 . V_62 = F_93 (
V_4 , L_18 , V_102 ,
& V_98 , sizeof( V_98 ) ) ;
if ( F_13 ( V_2 . V_62 ) )
return F_14 ( V_2 . V_62 ) ;
return 0 ;
}
static int F_94 ( struct V_90 * V_4 , struct V_90 * V_103 , void * V_7 )
{
struct V_75 * V_3 = F_95 ( V_4 ) ;
int V_1 ;
int V_6 ;
V_2 . V_3 = V_3 ;
F_96 ( & V_3 -> V_4 , & V_2 ) ;
F_97 ( & V_2 . V_54 ) ;
if ( V_3 -> V_4 . V_87 ) {
V_1 = F_74 ( V_3 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_98 ( V_3 , & V_2 . V_9 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_99 ( V_3 , & V_2 . V_38 , & V_2 . V_9 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_100 ( V_3 , & V_2 . V_42 ) ;
if ( V_1 )
goto V_89;
V_1 = F_101 ( V_3 , & V_2 . V_47 ) ;
if ( V_1 )
goto V_89;
V_6 = F_102 ( V_3 , 0 ) ;
if ( V_6 < 0 ) {
F_15 ( L_19 ) ;
V_1 = - V_59 ;
goto V_89;
}
V_1 = F_103 ( & V_3 -> V_4 , V_6 ,
NULL , F_7 ,
V_104 , L_20 , & V_2 . V_9 ) ;
if ( V_1 ) {
F_15 ( L_21 ) ;
goto V_89;
}
F_104 ( & V_3 -> V_4 ) ;
F_70 ( V_3 ) ;
V_1 = F_90 ( & V_3 -> V_4 ) ;
if ( V_1 ) {
F_15 ( L_22 ) ;
F_72 ( V_3 ) ;
F_105 ( & V_3 -> V_4 ) ;
return V_1 ;
}
F_106 ( L_23 , F_48 ) ;
return 0 ;
V_89:
F_107 ( & V_2 . V_38 ) ;
return V_1 ;
}
static void F_108 ( struct V_90 * V_4 , struct V_90 * V_103 , void * V_7 )
{
struct V_75 * V_3 = F_95 ( V_4 ) ;
if ( V_2 . V_62 )
F_109 ( V_2 . V_62 ) ;
F_72 ( V_3 ) ;
F_107 ( & V_2 . V_38 ) ;
F_105 ( & V_3 -> V_4 ) ;
}
static int F_110 ( struct V_75 * V_3 )
{
return F_111 ( & V_3 -> V_4 , & V_105 ) ;
}
static int F_112 ( struct V_75 * V_3 )
{
F_113 ( & V_3 -> V_4 , & V_105 ) ;
return 0 ;
}
static int F_114 ( struct V_90 * V_4 )
{
F_115 () ;
return 0 ;
}
static int F_116 ( struct V_90 * V_4 )
{
int V_1 ;
V_1 = F_117 () ;
if ( V_1 < 0 )
return V_1 ;
return 0 ;
}
int T_4 F_118 ( void )
{
return F_119 ( & V_106 ) ;
}
void F_120 ( void )
{
F_121 ( & V_106 ) ;
}
