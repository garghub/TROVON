void F_1 ( struct V_1 * V_2 , const char * V_3 ,
const struct V_4 * V_5 )
{
V_2 -> V_3 = V_3 ;
V_2 -> V_5 = V_5 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_6 , & V_7 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( & V_2 -> V_6 ) ;
}
static struct V_8 * F_6 ( struct V_9 * V_10 ,
struct V_11 * V_12 , const struct V_13 * V_14 )
{
return F_7 ( V_10 , V_12 , V_14 ) ;
}
static void F_8 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_9 ( V_16 -> V_18 ) ;
}
static int F_10 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
int V_21 ;
V_21 = F_11 ( V_10 , V_20 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_10 , V_20 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_11 ( V_10 , V_20 ) ;
if ( V_21 )
return V_21 ;
return V_21 ;
}
static int F_13 ( struct V_9 * V_10 ,
struct V_19 * V_20 ,
bool V_22 )
{
int V_21 ;
V_21 = F_14 ( V_10 , V_20 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_15 ( V_20 , true ) ;
if ( V_21 ) {
F_16 ( V_10 , V_20 ) ;
return V_21 ;
}
F_17 ( V_10 , V_20 ) ;
F_18 ( V_10 , V_20 , 0 ) ;
F_19 ( V_10 , V_20 ) ;
F_20 ( V_10 , V_20 ) ;
F_16 ( V_10 , V_20 ) ;
return 0 ;
}
static void F_21 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_1 * V_2 ;
F_22 (mod, &module_list, list) {
F_23 ( L_1 , V_2 -> V_3 ) ;
V_2 -> V_5 -> F_21 ( V_2 , V_10 ) ;
}
V_10 -> V_23 . V_24 = 0 ;
V_10 -> V_23 . V_25 = 0 ;
V_10 -> V_23 . V_26 = F_24 ( V_16 -> V_27 ) ;
V_10 -> V_23 . V_28 = 2048 ;
V_10 -> V_23 . V_5 = & V_29 ;
}
static int F_25 ( struct V_30 * V_31 ,
unsigned long V_32 , void * V_33 )
{
struct V_15 * V_16 = F_26 ( V_31 ,
struct V_15 , V_34 ) ;
if ( V_32 == V_35 )
F_27 ( V_16 -> V_27 ) ;
return 0 ;
}
static void F_28 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
if ( V_16 -> V_27 )
F_29 ( V_16 -> V_27 ) ;
if ( V_16 -> V_36 )
F_30 ( V_10 ) ;
F_31 ( V_10 ) ;
if ( V_16 -> V_18 )
F_32 ( V_16 -> V_18 ) ;
F_33 ( V_10 ) ;
F_34 ( V_10 ) ;
F_35 ( V_10 ) ;
#ifdef F_36
if ( V_16 -> V_34 . V_37 )
F_37 ( & V_16 -> V_34 ,
V_38 ) ;
#endif
if ( V_16 -> V_39 )
F_38 ( V_16 -> V_39 ) ;
if ( V_16 -> V_40 )
F_39 ( V_16 -> V_40 ) ;
if ( V_16 -> V_41 ) {
F_40 ( V_16 -> V_41 ) ;
F_41 ( V_16 -> V_41 ) ;
}
V_10 -> V_17 = NULL ;
F_42 ( V_10 -> V_10 ) ;
F_43 ( V_10 ) ;
}
static int F_44 ( struct V_42 * V_43 , struct V_44 * V_10 )
{
struct V_9 * V_45 ;
struct V_46 * V_47 = F_45 ( V_10 ) ;
struct V_48 * V_49 = V_10 -> V_50 ;
struct V_15 * V_16 ;
struct V_51 * V_52 ;
T_1 V_53 = 0 ;
int V_21 ;
V_16 = F_46 ( V_10 , sizeof( * V_16 ) , V_54 ) ;
if ( ! V_16 ) {
F_47 ( V_10 , L_2 ) ;
return - V_55 ;
}
V_45 = F_48 ( V_43 , V_10 ) ;
if ( F_49 ( V_45 ) )
return F_50 ( V_45 ) ;
V_45 -> V_17 = V_16 ;
F_51 ( V_47 , V_45 ) ;
F_52 ( V_45 ) ;
V_16 -> V_56 =
F_53 ( V_10 , NULL ) > 0 ;
V_16 -> V_41 = F_54 ( L_3 , 0 ) ;
if ( ! V_16 -> V_41 ) {
V_21 = - V_55 ;
goto V_57;
}
V_52 = F_55 ( V_47 , V_58 , 0 ) ;
if ( ! V_52 ) {
F_47 ( V_10 , L_4 ) ;
V_21 = - V_59 ;
goto V_57;
}
V_16 -> V_40 = F_56 ( V_52 -> V_60 , F_57 ( V_52 ) ) ;
if ( ! V_16 -> V_40 ) {
F_47 ( V_10 , L_5 ) ;
V_21 = - V_55 ;
goto V_57;
}
V_16 -> V_39 = F_58 ( V_10 , L_6 ) ;
if ( F_49 ( V_16 -> V_39 ) ) {
F_47 ( V_10 , L_7 ) ;
V_21 = - V_61 ;
goto V_57;
}
#ifdef F_36
V_16 -> V_34 . V_37 = F_25 ;
V_21 = F_59 ( & V_16 -> V_34 ,
V_38 ) ;
if ( V_21 ) {
F_47 ( V_10 , L_8 ) ;
V_16 -> V_34 . V_37 = NULL ;
goto V_57;
}
#endif
if ( F_60 ( V_49 , L_9 , & V_16 -> V_62 ) )
V_16 -> V_62 = V_63 ;
F_23 ( L_10 , V_16 -> V_62 ) ;
if ( F_60 ( V_49 , L_11 , & V_16 -> V_26 ) )
V_16 -> V_26 = V_64 ;
F_23 ( L_12 , V_16 -> V_26 ) ;
if ( F_60 ( V_49 , L_13 ,
& V_16 -> V_65 ) )
V_16 -> V_65 = V_66 ;
F_23 ( L_14 , V_16 -> V_65 ) ;
F_61 ( V_10 ) ;
F_62 ( V_10 ) ;
switch ( F_63 ( V_45 , V_67 ) ) {
case 0x4c100102 :
V_16 -> V_68 = 1 ;
break;
case 0x4f200800 :
case 0x4f201000 :
V_16 -> V_68 = 2 ;
break;
default:
F_64 ( V_10 , L_15
L_16 ,
F_63 ( V_45 , V_67 ) ) ;
V_16 -> V_68 = 1 ;
break;
}
F_65 ( V_10 ) ;
if ( V_16 -> V_68 == 1 ) {
F_23 ( L_17 ) ;
V_16 -> V_69 = V_70 ;
V_16 -> V_71 = F_66 ( V_70 ) ;
V_53 = 16 ;
} else {
const char * V_72 = L_18 ;
F_67 ( V_49 , L_19 , & V_72 ) ;
if ( 0 == strcmp ( V_72 , L_20 ) ) {
F_23 ( L_21 ) ;
V_16 -> V_69 = V_73 ;
V_16 -> V_71 =
F_66 ( V_73 ) ;
V_53 = 32 ;
} else if ( 0 == strcmp ( V_72 , L_22 ) ) {
F_23 ( L_23 ) ;
V_16 -> V_69 = V_74 ;
V_16 -> V_71 =
F_66 ( V_74 ) ;
V_53 = 16 ;
} else {
F_23 ( L_24 ,
V_72 ) ;
V_16 -> V_69 = V_75 ;
V_16 -> V_71 =
F_66 ( V_75 ) ;
V_53 = 16 ;
}
}
V_21 = F_68 ( V_45 ) ;
if ( V_21 < 0 ) {
F_47 ( V_10 , L_25 ) ;
goto V_57;
}
F_21 ( V_45 ) ;
if ( V_16 -> V_56 ) {
V_21 = F_69 ( V_10 , V_45 ) ;
if ( V_21 < 0 )
goto V_57;
V_21 = F_70 ( V_45 ) ;
if ( V_21 < 0 )
goto V_57;
} else {
V_21 = F_71 ( V_45 ) ;
if ( V_21 )
goto V_57;
}
if ( ! V_16 -> V_76 &&
( ( V_16 -> V_77 == 0 ) || ( V_16 -> V_78 == 0 ) ) ) {
F_47 ( V_10 , L_26 ) ;
V_21 = - V_79 ;
goto V_57;
}
V_21 = F_72 ( V_45 , 1 ) ;
if ( V_21 < 0 ) {
F_47 ( V_10 , L_27 ) ;
goto V_57;
}
V_21 = F_73 ( V_45 , F_74 ( V_47 , 0 ) ) ;
if ( V_21 < 0 ) {
F_47 ( V_10 , L_28 ) ;
goto V_57;
}
F_75 ( V_45 ) ;
V_16 -> V_18 = F_76 ( V_45 , V_53 ,
V_45 -> V_23 . V_80 ) ;
if ( F_49 ( V_16 -> V_18 ) ) {
V_21 = F_50 ( V_16 -> V_18 ) ;
goto V_57;
}
F_77 ( V_45 ) ;
V_21 = F_78 ( V_45 , 0 ) ;
if ( V_21 )
goto V_57;
V_16 -> V_36 = true ;
return 0 ;
V_57:
F_28 ( V_45 ) ;
return V_21 ;
}
static void F_79 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_80 ( V_16 -> V_18 ) ;
}
static T_2 F_81 ( int V_81 , void * V_82 )
{
struct V_9 * V_10 = V_82 ;
struct V_15 * V_16 = V_10 -> V_17 ;
return F_82 ( V_16 -> V_27 ) ;
}
static int F_83 ( struct V_83 * V_84 , void * V_82 )
{
struct V_85 * V_49 = (struct V_85 * ) V_84 -> V_86 ;
struct V_9 * V_10 = V_49 -> V_87 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_17 ;
unsigned V_88 ;
F_62 ( V_10 -> V_10 ) ;
F_84 ( V_84 , L_29 , V_16 -> V_68 ) ;
for ( V_88 = 0 ; V_88 < F_66 ( V_89 ) ; V_88 ++ )
if ( V_16 -> V_68 >= V_89 [ V_88 ] . V_68 )
F_84 ( V_84 , L_30 , V_89 [ V_88 ] . V_3 ,
F_63 ( V_10 , V_89 [ V_88 ] . V_90 ) ) ;
F_65 ( V_10 -> V_10 ) ;
return 0 ;
}
static int F_85 ( struct V_83 * V_84 , void * V_82 )
{
struct V_85 * V_49 = (struct V_85 * ) V_84 -> V_86 ;
struct V_9 * V_10 = V_49 -> V_87 -> V_10 ;
struct V_91 V_92 = F_86 ( V_84 ) ;
F_87 ( & V_10 -> V_93 -> V_94 , & V_92 ) ;
return 0 ;
}
static int F_88 ( struct V_95 * V_87 )
{
struct V_9 * V_10 = V_87 -> V_10 ;
struct V_1 * V_2 ;
int V_21 ;
V_21 = F_89 ( V_96 ,
F_66 ( V_96 ) ,
V_87 -> V_97 , V_87 ) ;
F_22 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_98 )
V_2 -> V_5 -> V_98 ( V_2 , V_87 ) ;
if ( V_21 ) {
F_47 ( V_10 -> V_10 , L_31 ) ;
return V_21 ;
}
return V_21 ;
}
static int F_90 ( struct V_44 * V_10 )
{
struct V_9 * V_45 = F_91 ( V_10 ) ;
struct V_15 * V_16 = V_45 -> V_17 ;
V_16 -> V_99 = F_92 ( V_45 ) ;
F_93 ( V_10 ) ;
return 0 ;
}
static int F_94 ( struct V_44 * V_10 )
{
struct V_9 * V_45 = F_91 ( V_10 ) ;
struct V_15 * V_16 = V_45 -> V_17 ;
int V_21 = 0 ;
F_95 ( V_10 ) ;
if ( V_16 -> V_99 )
V_21 = F_96 ( V_45 , V_16 -> V_99 ) ;
return V_21 ;
}
static int F_97 ( struct V_44 * V_10 )
{
return F_44 ( & V_100 , V_10 ) ;
}
static void F_98 ( struct V_44 * V_10 )
{
struct V_9 * V_45 = F_91 ( V_10 ) ;
if ( ! V_45 -> V_17 )
return;
F_28 ( F_91 ( V_10 ) ) ;
}
static int F_99 ( struct V_46 * V_47 )
{
struct V_101 * V_102 = NULL ;
int V_21 ;
if ( ! V_47 -> V_10 . V_50 ) {
F_47 ( & V_47 -> V_10 , L_32 ) ;
return - V_79 ;
}
V_21 = F_53 ( & V_47 -> V_10 , & V_102 ) ;
if ( V_21 < 0 )
return V_21 ;
else if ( V_21 == 0 )
return F_44 ( & V_100 , & V_47 -> V_10 ) ;
else
return F_100 ( & V_47 -> V_10 ,
& V_103 ,
V_102 ) ;
}
static int F_101 ( struct V_46 * V_47 )
{
int V_21 ;
V_21 = F_53 ( & V_47 -> V_10 , NULL ) ;
if ( V_21 < 0 )
return V_21 ;
else if ( V_21 == 0 )
F_28 ( F_102 ( V_47 ) ) ;
else
F_103 ( & V_47 -> V_10 , & V_103 ) ;
return 0 ;
}
static int T_3 F_104 ( void )
{
F_23 ( L_33 ) ;
F_105 () ;
F_106 () ;
return F_107 ( & V_104 ) ;
}
static void T_4 F_108 ( void )
{
F_23 ( L_34 ) ;
F_109 ( & V_104 ) ;
F_110 () ;
F_111 () ;
}
