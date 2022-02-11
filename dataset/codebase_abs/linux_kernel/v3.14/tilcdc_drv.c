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
void F_6 ( bool V_8 )
{
V_9 = V_8 ;
}
static struct V_10 * F_7 ( struct V_11 * V_12 ,
struct V_13 * V_14 , struct V_15 * V_16 )
{
return F_8 ( V_12 , V_14 , V_16 ) ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
if ( V_18 -> V_20 )
F_10 ( V_18 -> V_20 ) ;
}
static int F_11 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
struct V_1 * V_2 ;
F_12 ( V_12 ) ;
V_18 -> V_21 = F_13 ( V_12 ) ;
F_14 (mod, &module_list, list) {
F_15 ( L_1 , V_2 -> V_3 ) ;
V_2 -> V_5 -> F_11 ( V_2 , V_12 ) ;
}
if ( ( V_18 -> V_22 == 0 ) || ( V_18 -> V_23 == 0 ) ) {
F_16 ( V_12 -> V_12 , L_2 ) ;
return - V_24 ;
}
V_12 -> V_25 . V_26 = 0 ;
V_12 -> V_25 . V_27 = 0 ;
V_12 -> V_25 . V_28 = F_17 ( V_18 -> V_21 ) ;
V_12 -> V_25 . V_29 = 2048 ;
V_12 -> V_25 . V_5 = & V_30 ;
return 0 ;
}
static int F_18 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_34 )
{
struct V_17 * V_18 = F_19 ( V_32 ,
struct V_17 , V_35 ) ;
if ( V_33 == V_36 ) {
if ( V_18 -> V_37 != F_20 ( V_18 -> V_38 ) ) {
V_18 -> V_37 = F_20 ( V_18 -> V_38 ) ;
F_21 ( V_18 -> V_21 ) ;
}
}
return 0 ;
}
static int F_22 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
struct V_1 * V_2 , * V_39 ;
F_23 ( V_12 ) ;
F_24 ( V_12 ) ;
F_25 ( V_12 ) ;
F_26 ( V_12 -> V_12 ) ;
F_27 ( V_12 ) ;
F_28 ( V_12 -> V_12 ) ;
#ifdef F_29
F_30 ( & V_18 -> V_35 ,
V_40 ) ;
#endif
if ( V_18 -> V_38 )
F_31 ( V_18 -> V_38 ) ;
if ( V_18 -> V_41 )
F_32 ( V_18 -> V_41 ) ;
F_33 ( V_18 -> V_42 ) ;
F_34 ( V_18 -> V_42 ) ;
V_12 -> V_19 = NULL ;
F_35 ( V_12 -> V_12 ) ;
F_36 (mod, cur, &module_list, list) {
F_15 ( L_3 , V_2 -> V_3 ) ;
V_2 -> V_5 -> V_43 ( V_2 ) ;
}
F_37 ( V_18 ) ;
return 0 ;
}
static int F_38 ( struct V_11 * V_12 , unsigned long V_44 )
{
struct V_45 * V_46 = V_12 -> V_47 ;
struct V_48 * V_49 = V_46 -> V_12 . V_50 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
T_1 V_53 = 0 ;
int V_54 ;
V_18 = F_39 ( sizeof( * V_18 ) , V_55 ) ;
if ( ! V_18 ) {
F_16 ( V_12 -> V_12 , L_4 ) ;
return - V_56 ;
}
V_12 -> V_19 = V_18 ;
V_18 -> V_42 = F_40 ( L_5 , 0 ) ;
V_52 = F_41 ( V_46 , V_57 , 0 ) ;
if ( ! V_52 ) {
F_16 ( V_12 -> V_12 , L_6 ) ;
V_54 = - V_58 ;
goto V_59;
}
V_18 -> V_41 = F_42 ( V_52 -> V_60 , F_43 ( V_52 ) ) ;
if ( ! V_18 -> V_41 ) {
F_16 ( V_12 -> V_12 , L_7 ) ;
V_54 = - V_56 ;
goto V_59;
}
V_18 -> V_38 = F_44 ( V_12 -> V_12 , L_8 ) ;
if ( F_45 ( V_18 -> V_38 ) ) {
F_16 ( V_12 -> V_12 , L_9 ) ;
V_54 = - V_61 ;
goto V_59;
}
V_18 -> V_62 = F_44 ( V_12 -> V_12 , L_10 ) ;
if ( F_45 ( V_18 -> V_38 ) ) {
F_16 ( V_12 -> V_12 , L_11 ) ;
V_54 = - V_61 ;
goto V_59;
}
#ifdef F_29
V_18 -> V_37 = F_20 ( V_18 -> V_38 ) ;
V_18 -> V_35 . V_63 = F_18 ;
V_54 = F_46 ( & V_18 -> V_35 ,
V_40 ) ;
if ( V_54 ) {
F_16 ( V_12 -> V_12 , L_12 ) ;
goto V_59;
}
#endif
if ( F_47 ( V_49 , L_13 , & V_18 -> V_64 ) )
V_18 -> V_64 = V_65 ;
F_15 ( L_14 , V_18 -> V_64 ) ;
if ( F_47 ( V_49 , L_15 , & V_18 -> V_28 ) )
V_18 -> V_28 = V_66 ;
F_15 ( L_16 , V_18 -> V_28 ) ;
if ( F_47 ( V_49 , L_17 ,
& V_18 -> V_67 ) )
V_18 -> V_67 = V_68 ;
F_15 ( L_18 , V_18 -> V_67 ) ;
F_48 ( V_12 -> V_12 ) ;
F_26 ( V_12 -> V_12 ) ;
switch ( F_49 ( V_12 , V_69 ) ) {
case 0x4c100102 :
V_18 -> V_70 = 1 ;
break;
case 0x4f200800 :
case 0x4f201000 :
V_18 -> V_70 = 2 ;
break;
default:
F_50 ( V_12 -> V_12 , L_19
L_20 ,
F_49 ( V_12 , V_69 ) ) ;
V_18 -> V_70 = 1 ;
break;
}
F_28 ( V_12 -> V_12 ) ;
V_54 = F_11 ( V_12 ) ;
if ( V_54 < 0 ) {
F_16 ( V_12 -> V_12 , L_21 ) ;
goto V_59;
}
V_54 = F_51 ( V_12 , 1 ) ;
if ( V_54 < 0 ) {
F_16 ( V_12 -> V_12 , L_22 ) ;
goto V_59;
}
F_26 ( V_12 -> V_12 ) ;
V_54 = F_52 ( V_12 ) ;
F_28 ( V_12 -> V_12 ) ;
if ( V_54 < 0 ) {
F_16 ( V_12 -> V_12 , L_23 ) ;
goto V_59;
}
F_53 ( V_46 , V_12 ) ;
F_14 (mod, &module_list, list) {
F_15 ( L_24 , V_2 -> V_3 , V_2 -> V_71 ) ;
V_53 = V_2 -> V_71 ;
if ( V_53 > 0 )
break;
}
V_18 -> V_20 = F_54 ( V_12 , V_53 ,
V_12 -> V_25 . V_72 ,
V_12 -> V_25 . V_73 ) ;
F_55 ( V_12 ) ;
return 0 ;
V_59:
F_22 ( V_12 ) ;
return V_54 ;
}
static void F_56 ( struct V_11 * V_12 , struct V_13 * V_74 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
F_57 ( V_18 -> V_21 , V_74 ) ;
}
static void F_58 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
F_59 ( V_18 -> V_20 ) ;
}
static T_2 F_60 ( int V_75 , void * V_76 )
{
struct V_11 * V_12 = V_76 ;
struct V_17 * V_18 = V_12 -> V_19 ;
return F_61 ( V_18 -> V_21 ) ;
}
static void F_62 ( struct V_11 * V_12 )
{
F_63 ( V_12 , 0xffffffff ) ;
}
static int F_64 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
if ( V_18 -> V_70 == 1 )
F_65 ( V_12 , V_77 , V_78 ) ;
else
F_65 ( V_12 , V_79 , V_80 ) ;
return 0 ;
}
static void F_66 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
if ( V_18 -> V_70 == 1 ) {
F_67 ( V_12 , V_77 ,
V_78 | V_81 ) ;
F_67 ( V_12 , V_82 , V_83 ) ;
} else {
F_67 ( V_12 , V_79 ,
V_80 | V_84 |
V_85 | V_86 |
V_87 ) ;
}
}
static void F_68 ( struct V_11 * V_12 , bool V_88 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
T_1 V_89 , V_90 ;
if ( V_18 -> V_70 == 1 ) {
V_89 = V_82 ;
V_90 = V_83 ;
} else {
V_89 = V_79 ;
V_90 = V_85 |
V_86 | V_87 ;
}
if ( V_88 )
F_65 ( V_12 , V_89 , V_90 ) ;
else
F_67 ( V_12 , V_89 , V_90 ) ;
}
static int F_69 ( struct V_11 * V_12 , int V_21 )
{
F_68 ( V_12 , true ) ;
return 0 ;
}
static void F_70 ( struct V_11 * V_12 , int V_21 )
{
F_68 ( V_12 , false ) ;
}
static int F_71 ( struct V_91 * V_92 , void * V_76 )
{
struct V_93 * V_49 = (struct V_93 * ) V_92 -> V_94 ;
struct V_11 * V_12 = V_49 -> V_95 -> V_12 ;
struct V_17 * V_18 = V_12 -> V_19 ;
unsigned V_96 ;
F_26 ( V_12 -> V_12 ) ;
F_72 ( V_92 , L_25 , V_18 -> V_70 ) ;
for ( V_96 = 0 ; V_96 < F_73 ( V_97 ) ; V_96 ++ )
if ( V_18 -> V_70 >= V_97 [ V_96 ] . V_70 )
F_72 ( V_92 , L_26 , V_97 [ V_96 ] . V_3 ,
F_49 ( V_12 , V_97 [ V_96 ] . V_89 ) ) ;
F_28 ( V_12 -> V_12 ) ;
return 0 ;
}
static int F_74 ( struct V_91 * V_92 , void * V_76 )
{
struct V_93 * V_49 = (struct V_93 * ) V_92 -> V_94 ;
struct V_11 * V_12 = V_49 -> V_95 -> V_12 ;
return F_75 ( V_92 , & V_12 -> V_98 -> V_99 ) ;
}
static int F_76 ( struct V_100 * V_95 )
{
struct V_11 * V_12 = V_95 -> V_12 ;
struct V_1 * V_2 ;
int V_54 ;
V_54 = F_77 ( V_101 ,
F_73 ( V_101 ) ,
V_95 -> V_102 , V_95 ) ;
F_14 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_103 )
V_2 -> V_5 -> V_103 ( V_2 , V_95 ) ;
if ( V_54 ) {
F_16 ( V_12 -> V_12 , L_27 ) ;
return V_54 ;
}
return V_54 ;
}
static void F_78 ( struct V_100 * V_95 )
{
struct V_1 * V_2 ;
F_79 ( V_101 ,
F_73 ( V_101 ) , V_95 ) ;
F_14 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_104 )
V_2 -> V_5 -> V_104 ( V_2 , V_95 ) ;
}
static int F_80 ( struct V_105 * V_12 )
{
struct V_11 * V_106 = F_81 ( V_12 ) ;
struct V_17 * V_18 = V_106 -> V_19 ;
unsigned V_96 , V_107 = 0 ;
F_82 ( V_106 ) ;
for ( V_96 = 0 ; V_96 < F_73 ( V_97 ) ; V_96 ++ )
if ( V_97 [ V_96 ] . V_108 && ( V_18 -> V_70 >= V_97 [ V_96 ] . V_70 ) )
V_18 -> V_109 [ V_107 ++ ] = F_49 ( V_106 , V_97 [ V_96 ] . V_89 ) ;
return 0 ;
}
static int F_83 ( struct V_105 * V_12 )
{
struct V_11 * V_106 = F_81 ( V_12 ) ;
struct V_17 * V_18 = V_106 -> V_19 ;
unsigned V_96 , V_107 = 0 ;
for ( V_96 = 0 ; V_96 < F_73 ( V_97 ) ; V_96 ++ )
if ( V_97 [ V_96 ] . V_108 && ( V_18 -> V_70 >= V_97 [ V_96 ] . V_70 ) )
F_84 ( V_106 , V_97 [ V_96 ] . V_89 , V_18 -> V_109 [ V_107 ++ ] ) ;
F_85 ( V_106 ) ;
return 0 ;
}
static int F_86 ( struct V_45 * V_46 )
{
if ( ! V_46 -> V_12 . V_50 ) {
F_16 ( & V_46 -> V_12 , L_28 ) ;
return - V_24 ;
}
if ( V_9 == true )
return - V_110 ;
return F_87 ( & V_111 , V_46 ) ;
}
static int F_88 ( struct V_45 * V_46 )
{
F_89 ( F_90 ( V_46 ) ) ;
return 0 ;
}
static int T_3 F_91 ( void )
{
F_15 ( L_29 ) ;
F_92 () ;
F_93 () ;
F_94 () ;
return F_95 ( & V_112 ) ;
}
static void T_4 F_96 ( void )
{
F_15 ( L_30 ) ;
F_97 () ;
F_98 () ;
F_99 () ;
F_100 ( & V_112 ) ;
}
