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
F_15 ( V_20 , true ) ;
F_16 ( V_10 , V_20 ) ;
F_17 ( V_10 , V_20 , 0 ) ;
F_18 ( V_10 , V_20 ) ;
F_19 ( V_10 , V_20 ) ;
F_20 ( V_10 , V_20 ) ;
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
V_45 -> V_56 = V_47 ;
V_45 -> V_17 = V_16 ;
F_51 ( V_47 , V_45 ) ;
F_52 ( V_45 ) ;
V_16 -> V_57 =
F_53 ( V_10 , NULL ) > 0 ;
V_16 -> V_41 = F_54 ( L_3 , 0 ) ;
if ( ! V_16 -> V_41 ) {
V_21 = - V_55 ;
goto V_58;
}
V_52 = F_55 ( V_47 , V_59 , 0 ) ;
if ( ! V_52 ) {
F_47 ( V_10 , L_4 ) ;
V_21 = - V_60 ;
goto V_58;
}
V_16 -> V_40 = F_56 ( V_52 -> V_61 , F_57 ( V_52 ) ) ;
if ( ! V_16 -> V_40 ) {
F_47 ( V_10 , L_5 ) ;
V_21 = - V_55 ;
goto V_58;
}
V_16 -> V_39 = F_58 ( V_10 , L_6 ) ;
if ( F_49 ( V_16 -> V_39 ) ) {
F_47 ( V_10 , L_7 ) ;
V_21 = - V_62 ;
goto V_58;
}
#ifdef F_36
V_16 -> V_34 . V_37 = F_25 ;
V_21 = F_59 ( & V_16 -> V_34 ,
V_38 ) ;
if ( V_21 ) {
F_47 ( V_10 , L_8 ) ;
V_16 -> V_34 . V_37 = NULL ;
goto V_58;
}
#endif
if ( F_60 ( V_49 , L_9 , & V_16 -> V_63 ) )
V_16 -> V_63 = V_64 ;
F_23 ( L_10 , V_16 -> V_63 ) ;
if ( F_60 ( V_49 , L_11 , & V_16 -> V_26 ) )
V_16 -> V_26 = V_65 ;
F_23 ( L_12 , V_16 -> V_26 ) ;
if ( F_60 ( V_49 , L_13 ,
& V_16 -> V_66 ) )
V_16 -> V_66 = V_67 ;
F_23 ( L_14 , V_16 -> V_66 ) ;
F_61 ( V_10 ) ;
F_62 ( V_10 ) ;
switch ( F_63 ( V_45 , V_68 ) ) {
case 0x4c100102 :
V_16 -> V_69 = 1 ;
break;
case 0x4f200800 :
case 0x4f201000 :
V_16 -> V_69 = 2 ;
break;
default:
F_64 ( V_10 , L_15
L_16 ,
F_63 ( V_45 , V_68 ) ) ;
V_16 -> V_69 = 1 ;
break;
}
F_65 ( V_10 ) ;
if ( V_16 -> V_69 == 1 ) {
F_23 ( L_17 ) ;
V_16 -> V_70 = V_71 ;
V_16 -> V_72 = F_66 ( V_71 ) ;
V_53 = 16 ;
} else {
const char * V_73 = L_18 ;
F_67 ( V_49 , L_19 , & V_73 ) ;
if ( 0 == strcmp ( V_73 , L_20 ) ) {
F_23 ( L_21 ) ;
V_16 -> V_70 = V_74 ;
V_16 -> V_72 =
F_66 ( V_74 ) ;
V_53 = 32 ;
} else if ( 0 == strcmp ( V_73 , L_22 ) ) {
F_23 ( L_23 ) ;
V_16 -> V_70 = V_75 ;
V_16 -> V_72 =
F_66 ( V_75 ) ;
V_53 = 16 ;
} else {
F_23 ( L_24 ,
V_73 ) ;
V_16 -> V_70 = V_76 ;
V_16 -> V_72 =
F_66 ( V_76 ) ;
V_53 = 16 ;
}
}
V_21 = F_68 ( V_45 ) ;
if ( V_21 < 0 ) {
F_47 ( V_10 , L_25 ) ;
goto V_58;
}
F_21 ( V_45 ) ;
if ( V_16 -> V_57 ) {
V_21 = F_69 ( V_10 , V_45 ) ;
if ( V_21 < 0 )
goto V_58;
V_21 = F_70 ( V_45 ) ;
if ( V_21 < 0 )
goto V_58;
} else {
V_21 = F_71 ( V_45 ) ;
if ( V_21 )
goto V_58;
}
if ( ! V_16 -> V_77 &&
( ( V_16 -> V_78 == 0 ) || ( V_16 -> V_79 == 0 ) ) ) {
F_47 ( V_10 , L_26 ) ;
V_21 = - V_80 ;
goto V_58;
}
V_21 = F_72 ( V_45 , 1 ) ;
if ( V_21 < 0 ) {
F_47 ( V_10 , L_27 ) ;
goto V_58;
}
V_21 = F_73 ( V_45 , F_74 ( V_47 , 0 ) ) ;
if ( V_21 < 0 ) {
F_47 ( V_10 , L_28 ) ;
goto V_58;
}
F_75 ( V_45 ) ;
V_16 -> V_18 = F_76 ( V_45 , V_53 ,
V_45 -> V_23 . V_81 ,
V_45 -> V_23 . V_82 ) ;
if ( F_49 ( V_16 -> V_18 ) ) {
V_21 = F_50 ( V_16 -> V_18 ) ;
goto V_58;
}
F_77 ( V_45 ) ;
V_21 = F_78 ( V_45 , 0 ) ;
if ( V_21 )
goto V_58;
V_16 -> V_36 = true ;
return 0 ;
V_58:
F_28 ( V_45 ) ;
return V_21 ;
}
static void F_79 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_80 ( V_16 -> V_18 ) ;
}
static T_2 F_81 ( int V_83 , void * V_84 )
{
struct V_9 * V_10 = V_84 ;
struct V_15 * V_16 = V_10 -> V_17 ;
return F_82 ( V_16 -> V_27 ) ;
}
static int F_83 ( struct V_9 * V_10 , unsigned int V_85 )
{
return 0 ;
}
static void F_84 ( struct V_9 * V_10 , unsigned int V_85 )
{
return;
}
static int F_85 ( struct V_86 * V_87 , void * V_84 )
{
struct V_88 * V_49 = (struct V_88 * ) V_87 -> V_89 ;
struct V_9 * V_10 = V_49 -> V_90 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_17 ;
unsigned V_91 ;
F_62 ( V_10 -> V_10 ) ;
F_86 ( V_87 , L_29 , V_16 -> V_69 ) ;
for ( V_91 = 0 ; V_91 < F_66 ( V_92 ) ; V_91 ++ )
if ( V_16 -> V_69 >= V_92 [ V_91 ] . V_69 )
F_86 ( V_87 , L_30 , V_92 [ V_91 ] . V_3 ,
F_63 ( V_10 , V_92 [ V_91 ] . V_93 ) ) ;
F_65 ( V_10 -> V_10 ) ;
return 0 ;
}
static int F_87 ( struct V_86 * V_87 , void * V_84 )
{
struct V_88 * V_49 = (struct V_88 * ) V_87 -> V_89 ;
struct V_9 * V_10 = V_49 -> V_90 -> V_10 ;
return F_88 ( V_87 , & V_10 -> V_94 -> V_95 ) ;
}
static int F_89 ( struct V_96 * V_90 )
{
struct V_9 * V_10 = V_90 -> V_10 ;
struct V_1 * V_2 ;
int V_21 ;
V_21 = F_90 ( V_97 ,
F_66 ( V_97 ) ,
V_90 -> V_98 , V_90 ) ;
F_22 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_99 )
V_2 -> V_5 -> V_99 ( V_2 , V_90 ) ;
if ( V_21 ) {
F_47 ( V_10 -> V_10 , L_31 ) ;
return V_21 ;
}
return V_21 ;
}
static void F_91 ( struct V_96 * V_90 )
{
struct V_1 * V_2 ;
F_92 ( V_97 ,
F_66 ( V_97 ) , V_90 ) ;
F_22 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_100 )
V_2 -> V_5 -> V_100 ( V_2 , V_90 ) ;
}
static int F_93 ( struct V_44 * V_10 )
{
struct V_9 * V_45 = F_94 ( V_10 ) ;
struct V_15 * V_16 = V_45 -> V_17 ;
V_16 -> V_101 = F_95 ( V_45 ) ;
F_96 ( V_10 ) ;
return 0 ;
}
static int F_97 ( struct V_44 * V_10 )
{
struct V_9 * V_45 = F_94 ( V_10 ) ;
struct V_15 * V_16 = V_45 -> V_17 ;
int V_21 = 0 ;
F_98 ( V_10 ) ;
if ( V_16 -> V_101 )
V_21 = F_99 ( V_45 , V_16 -> V_101 ) ;
return V_21 ;
}
static int F_100 ( struct V_44 * V_10 )
{
return F_44 ( & V_102 , V_10 ) ;
}
static void F_101 ( struct V_44 * V_10 )
{
struct V_9 * V_45 = F_94 ( V_10 ) ;
if ( ! V_45 -> V_17 )
return;
F_28 ( F_94 ( V_10 ) ) ;
}
static int F_102 ( struct V_46 * V_47 )
{
struct V_103 * V_104 = NULL ;
int V_21 ;
if ( ! V_47 -> V_10 . V_50 ) {
F_47 ( & V_47 -> V_10 , L_32 ) ;
return - V_80 ;
}
V_21 = F_53 ( & V_47 -> V_10 , & V_104 ) ;
if ( V_21 < 0 )
return V_21 ;
else if ( V_21 == 0 )
return F_44 ( & V_102 , & V_47 -> V_10 ) ;
else
return F_103 ( & V_47 -> V_10 ,
& V_105 ,
V_104 ) ;
}
static int F_104 ( struct V_46 * V_47 )
{
int V_21 ;
V_21 = F_53 ( & V_47 -> V_10 , NULL ) ;
if ( V_21 < 0 )
return V_21 ;
else if ( V_21 == 0 )
F_28 ( F_105 ( V_47 ) ) ;
else
F_106 ( & V_47 -> V_10 , & V_105 ) ;
return 0 ;
}
static int T_3 F_107 ( void )
{
F_23 ( L_33 ) ;
F_108 () ;
F_109 () ;
return F_110 ( & V_106 ) ;
}
static void T_4 F_111 ( void )
{
F_23 ( L_34 ) ;
F_112 ( & V_106 ) ;
F_113 () ;
F_114 () ;
}
