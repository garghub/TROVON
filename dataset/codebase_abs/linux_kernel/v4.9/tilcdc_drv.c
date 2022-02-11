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
F_16 ( V_10 -> V_10 ) ;
F_17 ( V_10 , V_20 ) ;
F_18 ( V_10 , V_20 , 0 ) ;
F_19 ( V_10 , V_20 ) ;
F_20 ( V_10 -> V_10 ) ;
F_21 ( V_10 , V_20 ) ;
F_22 ( V_10 , V_20 ) ;
F_23 ( V_20 ) ;
return 0 ;
}
static int F_24 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_1 * V_2 ;
F_25 ( V_10 ) ;
V_16 -> V_23 = F_26 ( V_10 ) ;
F_27 (mod, &module_list, list) {
F_28 ( L_1 , V_2 -> V_3 ) ;
V_2 -> V_5 -> F_24 ( V_2 , V_10 ) ;
}
V_10 -> V_24 . V_25 = 0 ;
V_10 -> V_24 . V_26 = 0 ;
V_10 -> V_24 . V_27 = F_29 ( V_16 -> V_23 ) ;
V_10 -> V_24 . V_28 = 2048 ;
V_10 -> V_24 . V_5 = & V_29 ;
return 0 ;
}
static int F_30 ( struct V_30 * V_31 ,
unsigned long V_32 , void * V_33 )
{
struct V_15 * V_16 = F_31 ( V_31 ,
struct V_15 , V_34 ) ;
if ( V_32 == V_35 )
F_32 ( V_16 -> V_23 ) ;
return 0 ;
}
static int F_33 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_34 ( V_10 ) ;
F_35 ( V_16 -> V_18 ) ;
F_36 ( V_10 ) ;
F_37 ( V_10 ) ;
F_38 ( V_10 ) ;
F_39 ( V_10 ) ;
#ifdef F_40
F_41 ( & V_16 -> V_34 ,
V_36 ) ;
#endif
if ( V_16 -> V_37 )
F_42 ( V_16 -> V_37 ) ;
if ( V_16 -> V_38 )
F_43 ( V_16 -> V_38 ) ;
F_44 ( V_16 -> V_39 ) ;
F_45 ( V_16 -> V_39 ) ;
V_10 -> V_17 = NULL ;
F_46 ( V_10 -> V_10 ) ;
return 0 ;
}
static int F_47 ( struct V_9 * V_10 , unsigned long V_40 )
{
struct V_41 * V_42 = V_10 -> V_43 ;
struct V_44 * V_45 = V_42 -> V_10 . V_46 ;
struct V_15 * V_16 ;
struct V_47 * V_48 ;
T_1 V_49 = 0 ;
int V_21 ;
V_16 = F_48 ( V_10 -> V_10 , sizeof( * V_16 ) , V_50 ) ;
if ( ! V_16 ) {
F_49 ( V_10 -> V_10 , L_2 ) ;
return - V_51 ;
}
V_10 -> V_17 = V_16 ;
V_16 -> V_52 =
F_50 ( V_10 -> V_10 , NULL ) > 0 ;
V_16 -> V_39 = F_51 ( L_3 , 0 ) ;
if ( ! V_16 -> V_39 ) {
V_21 = - V_51 ;
goto V_53;
}
V_48 = F_52 ( V_42 , V_54 , 0 ) ;
if ( ! V_48 ) {
F_49 ( V_10 -> V_10 , L_4 ) ;
V_21 = - V_55 ;
goto V_56;
}
V_16 -> V_38 = F_53 ( V_48 -> V_57 , F_54 ( V_48 ) ) ;
if ( ! V_16 -> V_38 ) {
F_49 ( V_10 -> V_10 , L_5 ) ;
V_21 = - V_51 ;
goto V_56;
}
V_16 -> V_37 = F_55 ( V_10 -> V_10 , L_6 ) ;
if ( F_56 ( V_16 -> V_37 ) ) {
F_49 ( V_10 -> V_10 , L_7 ) ;
V_21 = - V_58 ;
goto V_59;
}
#ifdef F_40
V_16 -> V_34 . V_60 = F_30 ;
V_21 = F_57 ( & V_16 -> V_34 ,
V_36 ) ;
if ( V_21 ) {
F_49 ( V_10 -> V_10 , L_8 ) ;
goto V_61;
}
#endif
if ( F_58 ( V_45 , L_9 , & V_16 -> V_62 ) )
V_16 -> V_62 = V_63 ;
F_28 ( L_10 , V_16 -> V_62 ) ;
if ( F_58 ( V_45 , L_11 , & V_16 -> V_27 ) )
V_16 -> V_27 = V_64 ;
F_28 ( L_12 , V_16 -> V_27 ) ;
if ( F_58 ( V_45 , L_13 ,
& V_16 -> V_65 ) )
V_16 -> V_65 = V_66 ;
F_28 ( L_14 , V_16 -> V_65 ) ;
F_59 ( V_10 -> V_10 ) ;
F_16 ( V_10 -> V_10 ) ;
switch ( F_60 ( V_10 , V_67 ) ) {
case 0x4c100102 :
V_16 -> V_68 = 1 ;
break;
case 0x4f200800 :
case 0x4f201000 :
V_16 -> V_68 = 2 ;
break;
default:
F_61 ( V_10 -> V_10 , L_15
L_16 ,
F_60 ( V_10 , V_67 ) ) ;
V_16 -> V_68 = 1 ;
break;
}
F_20 ( V_10 -> V_10 ) ;
if ( V_16 -> V_68 == 1 ) {
F_28 ( L_17 ) ;
V_16 -> V_69 = V_70 ;
V_16 -> V_71 = F_62 ( V_70 ) ;
V_49 = 16 ;
} else {
const char * V_72 = L_18 ;
F_63 ( V_45 , L_19 , & V_72 ) ;
if ( 0 == strcmp ( V_72 , L_20 ) ) {
F_28 ( L_21 ) ;
V_16 -> V_69 = V_73 ;
V_16 -> V_71 =
F_62 ( V_73 ) ;
V_49 = 32 ;
} else if ( 0 == strcmp ( V_72 , L_22 ) ) {
F_28 ( L_23 ) ;
V_16 -> V_69 = V_74 ;
V_16 -> V_71 =
F_62 ( V_74 ) ;
V_49 = 16 ;
} else {
F_28 ( L_24 ,
V_72 ) ;
V_16 -> V_69 = V_75 ;
V_16 -> V_71 =
F_62 ( V_75 ) ;
V_49 = 16 ;
}
}
V_21 = F_24 ( V_10 ) ;
if ( V_21 < 0 ) {
F_49 ( V_10 -> V_10 , L_25 ) ;
goto V_76;
}
F_64 ( V_42 , V_10 ) ;
if ( V_16 -> V_52 ) {
V_21 = F_65 ( V_10 -> V_10 , V_10 ) ;
if ( V_21 < 0 )
goto V_77;
V_21 = F_66 ( V_10 ) ;
if ( V_21 < 0 )
goto V_78;
}
if ( ( V_16 -> V_79 == 0 ) || ( V_16 -> V_80 == 0 ) ) {
F_49 ( V_10 -> V_10 , L_26 ) ;
V_21 = - V_81 ;
goto V_82;
}
V_21 = F_67 ( V_10 , 1 ) ;
if ( V_21 < 0 ) {
F_49 ( V_10 -> V_10 , L_27 ) ;
goto V_82;
}
V_21 = F_68 ( V_10 , F_69 ( V_10 -> V_43 , 0 ) ) ;
if ( V_21 < 0 ) {
F_49 ( V_10 -> V_10 , L_28 ) ;
goto V_83;
}
F_70 ( V_10 ) ;
V_16 -> V_18 = F_71 ( V_10 , V_49 ,
V_10 -> V_24 . V_84 ,
V_10 -> V_24 . V_85 ) ;
if ( F_56 ( V_16 -> V_18 ) ) {
V_21 = F_72 ( V_16 -> V_18 ) ;
goto V_86;
}
F_73 ( V_10 ) ;
return 0 ;
V_86:
F_39 ( V_10 ) ;
V_83:
F_38 ( V_10 ) ;
V_78:
if ( V_16 -> V_52 )
F_74 ( V_10 -> V_10 , V_10 ) ;
V_77:
F_37 ( V_10 ) ;
V_82:
F_34 ( V_10 ) ;
V_76:
F_46 ( V_10 -> V_10 ) ;
#ifdef F_40
F_41 ( & V_16 -> V_34 ,
V_36 ) ;
V_61:
#endif
F_42 ( V_16 -> V_37 ) ;
V_59:
F_43 ( V_16 -> V_38 ) ;
V_56:
F_44 ( V_16 -> V_39 ) ;
F_45 ( V_16 -> V_39 ) ;
V_53:
V_10 -> V_17 = NULL ;
return V_21 ;
}
static void F_75 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_76 ( V_16 -> V_18 ) ;
}
static T_2 F_77 ( int V_87 , void * V_88 )
{
struct V_9 * V_10 = V_88 ;
struct V_15 * V_16 = V_10 -> V_17 ;
return F_78 ( V_16 -> V_23 ) ;
}
static int F_79 ( struct V_9 * V_10 , unsigned int V_89 )
{
return 0 ;
}
static void F_80 ( struct V_9 * V_10 , unsigned int V_89 )
{
return;
}
static int F_81 ( struct V_90 * V_91 , void * V_88 )
{
struct V_92 * V_45 = (struct V_92 * ) V_91 -> V_93 ;
struct V_9 * V_10 = V_45 -> V_94 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_17 ;
unsigned V_95 ;
F_16 ( V_10 -> V_10 ) ;
F_82 ( V_91 , L_29 , V_16 -> V_68 ) ;
for ( V_95 = 0 ; V_95 < F_62 ( V_96 ) ; V_95 ++ )
if ( V_16 -> V_68 >= V_96 [ V_95 ] . V_68 )
F_82 ( V_91 , L_30 , V_96 [ V_95 ] . V_3 ,
F_60 ( V_10 , V_96 [ V_95 ] . V_97 ) ) ;
F_20 ( V_10 -> V_10 ) ;
return 0 ;
}
static int F_83 ( struct V_90 * V_91 , void * V_88 )
{
struct V_92 * V_45 = (struct V_92 * ) V_91 -> V_93 ;
struct V_9 * V_10 = V_45 -> V_94 -> V_10 ;
return F_84 ( V_91 , & V_10 -> V_98 -> V_99 ) ;
}
static int F_85 ( struct V_100 * V_94 )
{
struct V_9 * V_10 = V_94 -> V_10 ;
struct V_1 * V_2 ;
int V_21 ;
V_21 = F_86 ( V_101 ,
F_62 ( V_101 ) ,
V_94 -> V_102 , V_94 ) ;
F_27 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_103 )
V_2 -> V_5 -> V_103 ( V_2 , V_94 ) ;
if ( V_21 ) {
F_49 ( V_10 -> V_10 , L_31 ) ;
return V_21 ;
}
return V_21 ;
}
static void F_87 ( struct V_100 * V_94 )
{
struct V_1 * V_2 ;
F_88 ( V_101 ,
F_62 ( V_101 ) , V_94 ) ;
F_27 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_104 )
V_2 -> V_5 -> V_104 ( V_2 , V_94 ) ;
}
static int F_89 ( struct V_105 * V_10 )
{
struct V_9 * V_106 = F_90 ( V_10 ) ;
struct V_15 * V_16 = V_106 -> V_17 ;
V_16 -> V_107 = F_91 ( V_106 ) ;
F_92 ( V_10 ) ;
return 0 ;
}
static int F_93 ( struct V_105 * V_10 )
{
struct V_9 * V_106 = F_90 ( V_10 ) ;
struct V_15 * V_16 = V_106 -> V_17 ;
int V_21 = 0 ;
F_94 ( V_10 ) ;
if ( V_16 -> V_107 )
V_21 = F_95 ( V_106 , V_16 -> V_107 ) ;
return V_21 ;
}
static int F_96 ( struct V_105 * V_10 )
{
return F_97 ( & V_108 , F_98 ( V_10 ) ) ;
}
static void F_99 ( struct V_105 * V_10 )
{
struct V_9 * V_106 = F_90 ( V_10 ) ;
if ( ! V_106 -> V_17 )
return;
F_100 ( F_90 ( V_10 ) ) ;
}
static int F_101 ( struct V_41 * V_42 )
{
struct V_109 * V_110 = NULL ;
int V_21 ;
if ( ! V_42 -> V_10 . V_46 ) {
F_49 ( & V_42 -> V_10 , L_32 ) ;
return - V_81 ;
}
V_21 = F_50 ( & V_42 -> V_10 , & V_110 ) ;
if ( V_21 < 0 )
return V_21 ;
else if ( V_21 == 0 )
return F_97 ( & V_108 , V_42 ) ;
else
return F_102 ( & V_42 -> V_10 ,
& V_111 ,
V_110 ) ;
}
static int F_103 ( struct V_41 * V_42 )
{
int V_21 ;
V_21 = F_50 ( & V_42 -> V_10 , NULL ) ;
if ( V_21 < 0 )
return V_21 ;
else if ( V_21 == 0 )
F_100 ( F_104 ( V_42 ) ) ;
else
F_105 ( & V_42 -> V_10 , & V_111 ) ;
return 0 ;
}
static int T_3 F_106 ( void )
{
F_28 ( L_33 ) ;
F_107 () ;
F_108 () ;
return F_109 ( & V_112 ) ;
}
static void T_4 F_110 ( void )
{
F_28 ( L_34 ) ;
F_111 ( & V_112 ) ;
F_112 () ;
F_113 () ;
}
