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
static int F_10 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_1 * V_2 ;
F_11 ( V_10 ) ;
V_16 -> V_19 = F_12 ( V_10 ) ;
F_13 (mod, &module_list, list) {
F_14 ( L_1 , V_2 -> V_3 ) ;
V_2 -> V_5 -> F_10 ( V_2 , V_10 ) ;
}
V_10 -> V_20 . V_21 = 0 ;
V_10 -> V_20 . V_22 = 0 ;
V_10 -> V_20 . V_23 = F_15 ( V_16 -> V_19 ) ;
V_10 -> V_20 . V_24 = 2048 ;
V_10 -> V_20 . V_5 = & V_25 ;
return 0 ;
}
static int F_16 ( struct V_26 * V_27 ,
unsigned long V_28 , void * V_29 )
{
struct V_15 * V_16 = F_17 ( V_27 ,
struct V_15 , V_30 ) ;
if ( V_28 == V_31 ) {
if ( V_16 -> V_32 != F_18 ( V_16 -> V_33 ) ) {
V_16 -> V_32 = F_18 ( V_16 -> V_33 ) ;
F_19 ( V_16 -> V_19 ) ;
}
}
return 0 ;
}
static int F_20 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_21 ( V_16 -> V_19 , V_34 ) ;
F_22 ( V_10 ) ;
F_23 ( V_16 -> V_18 ) ;
F_24 ( V_10 ) ;
F_25 ( V_10 ) ;
F_26 ( V_10 ) ;
F_27 ( V_10 -> V_10 ) ;
F_28 ( V_10 ) ;
F_29 ( V_10 -> V_10 ) ;
#ifdef F_30
F_31 ( & V_16 -> V_30 ,
V_35 ) ;
#endif
if ( V_16 -> V_33 )
F_32 ( V_16 -> V_33 ) ;
if ( V_16 -> V_36 )
F_33 ( V_16 -> V_36 ) ;
F_34 ( V_16 -> V_37 ) ;
F_35 ( V_16 -> V_37 ) ;
V_10 -> V_17 = NULL ;
F_36 ( V_10 -> V_10 ) ;
return 0 ;
}
static int F_37 ( struct V_9 * V_10 , unsigned long V_38 )
{
struct V_39 * V_40 = V_10 -> V_41 ;
struct V_42 * V_43 = V_40 -> V_10 . V_44 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
T_1 V_47 = 0 ;
int V_48 ;
V_16 = F_38 ( V_10 -> V_10 , sizeof( * V_16 ) , V_49 ) ;
if ( V_16 )
V_16 -> V_50 =
F_39 ( V_10 -> V_10 , F_40 () ,
sizeof( * V_16 -> V_50 ) , V_49 ) ;
if ( ! V_16 || ! V_16 -> V_50 ) {
F_41 ( V_10 -> V_10 , L_2 ) ;
return - V_51 ;
}
V_10 -> V_17 = V_16 ;
V_16 -> V_52 =
F_42 ( V_10 -> V_10 , NULL ) > 0 ;
V_16 -> V_37 = F_43 ( L_3 , 0 ) ;
if ( ! V_16 -> V_37 ) {
V_48 = - V_51 ;
goto V_53;
}
V_46 = F_44 ( V_40 , V_54 , 0 ) ;
if ( ! V_46 ) {
F_41 ( V_10 -> V_10 , L_4 ) ;
V_48 = - V_55 ;
goto V_56;
}
V_16 -> V_36 = F_45 ( V_46 -> V_57 , F_46 ( V_46 ) ) ;
if ( ! V_16 -> V_36 ) {
F_41 ( V_10 -> V_10 , L_5 ) ;
V_48 = - V_51 ;
goto V_56;
}
V_16 -> V_33 = F_47 ( V_10 -> V_10 , L_6 ) ;
if ( F_48 ( V_16 -> V_33 ) ) {
F_41 ( V_10 -> V_10 , L_7 ) ;
V_48 = - V_58 ;
goto V_59;
}
#ifdef F_30
V_16 -> V_32 = F_18 ( V_16 -> V_33 ) ;
V_16 -> V_30 . V_60 = F_16 ;
V_48 = F_49 ( & V_16 -> V_30 ,
V_35 ) ;
if ( V_48 ) {
F_41 ( V_10 -> V_10 , L_8 ) ;
goto V_61;
}
#endif
if ( F_50 ( V_43 , L_9 , & V_16 -> V_62 ) )
V_16 -> V_62 = V_63 ;
F_14 ( L_10 , V_16 -> V_62 ) ;
if ( F_50 ( V_43 , L_11 , & V_16 -> V_23 ) )
V_16 -> V_23 = V_64 ;
F_14 ( L_12 , V_16 -> V_23 ) ;
if ( F_50 ( V_43 , L_13 ,
& V_16 -> V_65 ) )
V_16 -> V_65 = V_66 ;
F_14 ( L_14 , V_16 -> V_65 ) ;
F_51 ( V_10 -> V_10 ) ;
F_27 ( V_10 -> V_10 ) ;
switch ( F_52 ( V_10 , V_67 ) ) {
case 0x4c100102 :
V_16 -> V_68 = 1 ;
break;
case 0x4f200800 :
case 0x4f201000 :
V_16 -> V_68 = 2 ;
break;
default:
F_53 ( V_10 -> V_10 , L_15
L_16 ,
F_52 ( V_10 , V_67 ) ) ;
V_16 -> V_68 = 1 ;
break;
}
F_29 ( V_10 -> V_10 ) ;
V_48 = F_10 ( V_10 ) ;
if ( V_48 < 0 ) {
F_41 ( V_10 -> V_10 , L_17 ) ;
goto V_69;
}
F_54 ( V_40 , V_10 ) ;
if ( V_16 -> V_52 ) {
V_48 = F_55 ( V_10 -> V_10 , V_10 ) ;
if ( V_48 < 0 )
goto V_70;
V_48 = F_56 ( V_10 , & V_47 ) ;
if ( V_48 < 0 )
goto V_71;
}
if ( ( V_16 -> V_72 == 0 ) || ( V_16 -> V_73 == 0 ) ) {
F_41 ( V_10 -> V_10 , L_18 ) ;
V_48 = - V_74 ;
goto V_75;
}
V_48 = F_57 ( V_10 , 1 ) ;
if ( V_48 < 0 ) {
F_41 ( V_10 -> V_10 , L_19 ) ;
goto V_75;
}
F_27 ( V_10 -> V_10 ) ;
V_48 = F_58 ( V_10 , F_59 ( V_10 -> V_41 , 0 ) ) ;
F_29 ( V_10 -> V_10 ) ;
if ( V_48 < 0 ) {
F_41 ( V_10 -> V_10 , L_20 ) ;
goto V_76;
}
F_13 (mod, &module_list, list) {
F_14 ( L_21 , V_2 -> V_3 , V_2 -> V_77 ) ;
V_47 = V_2 -> V_77 ;
if ( V_47 > 0 )
break;
}
F_60 ( V_10 ) ;
V_16 -> V_18 = F_61 ( V_10 , V_47 ,
V_10 -> V_20 . V_78 ,
V_10 -> V_20 . V_79 ) ;
if ( F_48 ( V_16 -> V_18 ) ) {
V_48 = F_62 ( V_16 -> V_18 ) ;
goto V_80;
}
F_63 ( V_10 ) ;
return 0 ;
V_80:
F_27 ( V_10 -> V_10 ) ;
F_28 ( V_10 ) ;
F_29 ( V_10 -> V_10 ) ;
V_76:
F_26 ( V_10 ) ;
V_70:
F_25 ( V_10 ) ;
V_71:
if ( V_16 -> V_52 )
F_64 ( V_10 -> V_10 , V_10 ) ;
V_75:
F_22 ( V_10 ) ;
V_69:
F_36 ( V_10 -> V_10 ) ;
#ifdef F_30
F_31 ( & V_16 -> V_30 ,
V_35 ) ;
V_61:
#endif
F_32 ( V_16 -> V_33 ) ;
V_59:
F_33 ( V_16 -> V_36 ) ;
V_56:
F_34 ( V_16 -> V_37 ) ;
F_35 ( V_16 -> V_37 ) ;
V_53:
V_10 -> V_17 = NULL ;
return V_48 ;
}
static void F_65 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_66 ( V_16 -> V_18 ) ;
}
static T_2 F_67 ( int V_81 , void * V_82 )
{
struct V_9 * V_10 = V_82 ;
struct V_15 * V_16 = V_10 -> V_17 ;
return F_68 ( V_16 -> V_19 ) ;
}
static void F_69 ( struct V_9 * V_10 )
{
F_70 ( V_10 , 0xffffffff ) ;
}
static int F_71 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
if ( V_16 -> V_68 == 1 ) {
F_72 ( V_10 , V_83 , V_84 ) ;
} else {
F_73 ( V_10 , V_85 ,
V_86 |
V_87 |
V_88 | V_89 ) ;
}
return 0 ;
}
static void F_74 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
if ( V_16 -> V_68 == 1 ) {
F_75 ( V_10 , V_83 ,
V_84 | V_90 ) ;
F_75 ( V_10 , V_91 , V_92 ) ;
} else {
F_73 ( V_10 , V_93 ,
V_86 | V_94 |
V_87 |
V_88 | V_89 ) ;
}
}
static int F_76 ( struct V_9 * V_10 , unsigned int V_95 )
{
return 0 ;
}
static void F_77 ( struct V_9 * V_10 , unsigned int V_95 )
{
return;
}
static T_3 F_40 ( void )
{
return F_78 ( V_96 ) ;
}
static T_3 F_40 ( void )
{
return 0 ;
}
static int F_79 ( struct V_97 * V_98 , void * V_82 )
{
struct V_99 * V_43 = (struct V_99 * ) V_98 -> V_100 ;
struct V_9 * V_10 = V_43 -> V_101 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_17 ;
unsigned V_102 ;
F_27 ( V_10 -> V_10 ) ;
F_80 ( V_98 , L_22 , V_16 -> V_68 ) ;
for ( V_102 = 0 ; V_102 < F_78 ( V_96 ) ; V_102 ++ )
if ( V_16 -> V_68 >= V_96 [ V_102 ] . V_68 )
F_80 ( V_98 , L_23 , V_96 [ V_102 ] . V_3 ,
F_52 ( V_10 , V_96 [ V_102 ] . V_103 ) ) ;
F_29 ( V_10 -> V_10 ) ;
return 0 ;
}
static int F_81 ( struct V_97 * V_98 , void * V_82 )
{
struct V_99 * V_43 = (struct V_99 * ) V_98 -> V_100 ;
struct V_9 * V_10 = V_43 -> V_101 -> V_10 ;
return F_82 ( V_98 , & V_10 -> V_104 -> V_105 ) ;
}
static int F_83 ( struct V_106 * V_101 )
{
struct V_9 * V_10 = V_101 -> V_10 ;
struct V_1 * V_2 ;
int V_48 ;
V_48 = F_84 ( V_107 ,
F_78 ( V_107 ) ,
V_101 -> V_108 , V_101 ) ;
F_13 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_109 )
V_2 -> V_5 -> V_109 ( V_2 , V_101 ) ;
if ( V_48 ) {
F_41 ( V_10 -> V_10 , L_24 ) ;
return V_48 ;
}
return V_48 ;
}
static void F_85 ( struct V_106 * V_101 )
{
struct V_1 * V_2 ;
F_86 ( V_107 ,
F_78 ( V_107 ) , V_101 ) ;
F_13 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_110 )
V_2 -> V_5 -> V_110 ( V_2 , V_101 ) ;
}
static int F_87 ( struct V_111 * V_10 )
{
struct V_9 * V_112 = F_88 ( V_10 ) ;
struct V_15 * V_16 = V_112 -> V_17 ;
unsigned V_102 , V_113 = 0 ;
F_89 ( V_112 ) ;
F_90 ( V_10 ) ;
if ( F_91 ( V_10 ) ) {
V_16 -> V_114 = false ;
return 0 ;
}
F_21 ( V_16 -> V_19 , V_34 ) ;
for ( V_102 = 0 ; V_102 < F_78 ( V_96 ) ; V_102 ++ )
if ( V_96 [ V_102 ] . V_115 && ( V_16 -> V_68 >= V_96 [ V_102 ] . V_68 ) )
V_16 -> V_50 [ V_113 ++ ] = F_52 ( V_112 , V_96 [ V_102 ] . V_103 ) ;
V_16 -> V_114 = true ;
return 0 ;
}
static int F_92 ( struct V_111 * V_10 )
{
struct V_9 * V_112 = F_88 ( V_10 ) ;
struct V_15 * V_16 = V_112 -> V_17 ;
unsigned V_102 , V_113 = 0 ;
F_93 ( V_10 ) ;
if ( V_16 -> V_114 == true ) {
for ( V_102 = 0 ; V_102 < F_78 ( V_96 ) ; V_102 ++ )
if ( V_96 [ V_102 ] . V_115 &&
( V_16 -> V_68 >= V_96 [ V_102 ] . V_68 ) )
F_73 ( V_112 , V_96 [ V_102 ] . V_103 ,
V_16 -> V_50 [ V_113 ++ ] ) ;
}
F_94 ( V_112 ) ;
return 0 ;
}
static int F_95 ( struct V_111 * V_10 )
{
return F_96 ( & V_116 , F_97 ( V_10 ) ) ;
}
static void F_98 ( struct V_111 * V_10 )
{
F_99 ( F_88 ( V_10 ) ) ;
}
static int F_100 ( struct V_39 * V_40 )
{
struct V_117 * V_118 = NULL ;
int V_48 ;
if ( ! V_40 -> V_10 . V_44 ) {
F_41 ( & V_40 -> V_10 , L_25 ) ;
return - V_74 ;
}
V_48 = F_42 ( & V_40 -> V_10 , & V_118 ) ;
if ( V_48 < 0 )
return V_48 ;
else if ( V_48 == 0 )
return F_96 ( & V_116 , V_40 ) ;
else
return F_101 ( & V_40 -> V_10 ,
& V_119 ,
V_118 ) ;
}
static int F_102 ( struct V_39 * V_40 )
{
struct V_9 * V_112 = F_88 ( & V_40 -> V_10 ) ;
struct V_15 * V_16 = V_112 -> V_17 ;
if ( ! V_16 )
return 0 ;
if ( V_16 -> V_52 )
F_103 ( & V_40 -> V_10 , & V_119 ) ;
else
F_99 ( F_104 ( V_40 ) ) ;
return 0 ;
}
static int T_4 F_105 ( void )
{
F_14 ( L_26 ) ;
F_106 () ;
F_107 () ;
return F_108 ( & V_120 ) ;
}
static void T_5 F_109 ( void )
{
F_14 ( L_27 ) ;
F_110 ( & V_120 ) ;
F_111 () ;
F_112 () ;
}
