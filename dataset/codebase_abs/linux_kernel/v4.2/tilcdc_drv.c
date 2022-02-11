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
struct V_11 * V_12 , struct V_13 * V_14 )
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
F_21 ( V_10 ) ;
F_22 ( V_16 -> V_18 ) ;
F_23 ( V_10 ) ;
F_24 ( V_10 ) ;
F_25 ( V_10 ) ;
F_26 ( V_10 -> V_10 ) ;
F_27 ( V_10 ) ;
F_28 ( V_10 -> V_10 ) ;
#ifdef F_29
F_30 ( & V_16 -> V_30 ,
V_34 ) ;
#endif
if ( V_16 -> V_33 )
F_31 ( V_16 -> V_33 ) ;
if ( V_16 -> V_35 )
F_32 ( V_16 -> V_35 ) ;
F_33 ( V_16 -> V_36 ) ;
F_34 ( V_16 -> V_36 ) ;
V_10 -> V_17 = NULL ;
F_35 ( V_10 -> V_10 ) ;
F_36 ( V_16 ) ;
return 0 ;
}
static int F_37 ( struct V_9 * V_10 , unsigned long V_37 )
{
struct V_38 * V_39 = V_10 -> V_40 ;
struct V_41 * V_42 = V_39 -> V_10 . V_43 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_44 * V_45 ;
T_1 V_46 = 0 ;
int V_47 ;
V_16 = F_38 ( sizeof( * V_16 ) , V_48 ) ;
if ( ! V_16 ) {
F_39 ( V_10 -> V_10 , L_2 ) ;
return - V_49 ;
}
V_10 -> V_17 = V_16 ;
V_16 -> V_50 =
F_40 ( V_10 -> V_10 , NULL ) > 0 ;
V_16 -> V_36 = F_41 ( L_3 , 0 ) ;
if ( ! V_16 -> V_36 ) {
V_47 = - V_49 ;
goto V_51;
}
V_45 = F_42 ( V_39 , V_52 , 0 ) ;
if ( ! V_45 ) {
F_39 ( V_10 -> V_10 , L_4 ) ;
V_47 = - V_53 ;
goto V_54;
}
V_16 -> V_35 = F_43 ( V_45 -> V_55 , F_44 ( V_45 ) ) ;
if ( ! V_16 -> V_35 ) {
F_39 ( V_10 -> V_10 , L_5 ) ;
V_47 = - V_49 ;
goto V_54;
}
V_16 -> V_33 = F_45 ( V_10 -> V_10 , L_6 ) ;
if ( F_46 ( V_16 -> V_33 ) ) {
F_39 ( V_10 -> V_10 , L_7 ) ;
V_47 = - V_56 ;
goto V_57;
}
V_16 -> V_58 = F_45 ( V_10 -> V_10 , L_8 ) ;
if ( F_46 ( V_16 -> V_33 ) ) {
F_39 ( V_10 -> V_10 , L_9 ) ;
V_47 = - V_56 ;
goto V_59;
}
#ifdef F_29
V_16 -> V_32 = F_18 ( V_16 -> V_33 ) ;
V_16 -> V_30 . V_60 = F_16 ;
V_47 = F_47 ( & V_16 -> V_30 ,
V_34 ) ;
if ( V_47 ) {
F_39 ( V_10 -> V_10 , L_10 ) ;
goto V_61;
}
#endif
if ( F_48 ( V_42 , L_11 , & V_16 -> V_62 ) )
V_16 -> V_62 = V_63 ;
F_14 ( L_12 , V_16 -> V_62 ) ;
if ( F_48 ( V_42 , L_13 , & V_16 -> V_23 ) )
V_16 -> V_23 = V_64 ;
F_14 ( L_14 , V_16 -> V_23 ) ;
if ( F_48 ( V_42 , L_15 ,
& V_16 -> V_65 ) )
V_16 -> V_65 = V_66 ;
F_14 ( L_16 , V_16 -> V_65 ) ;
F_49 ( V_10 -> V_10 ) ;
F_50 ( V_10 -> V_10 ) ;
F_26 ( V_10 -> V_10 ) ;
switch ( F_51 ( V_10 , V_67 ) ) {
case 0x4c100102 :
V_16 -> V_68 = 1 ;
break;
case 0x4f200800 :
case 0x4f201000 :
V_16 -> V_68 = 2 ;
break;
default:
F_52 ( V_10 -> V_10 , L_17
L_18 ,
F_51 ( V_10 , V_67 ) ) ;
V_16 -> V_68 = 1 ;
break;
}
F_28 ( V_10 -> V_10 ) ;
V_47 = F_10 ( V_10 ) ;
if ( V_47 < 0 ) {
F_39 ( V_10 -> V_10 , L_19 ) ;
goto V_69;
}
F_53 ( V_39 , V_10 ) ;
if ( V_16 -> V_50 ) {
V_47 = F_54 ( V_10 -> V_10 , V_10 ) ;
if ( V_47 < 0 )
goto V_70;
V_47 = F_55 ( V_10 , & V_46 ) ;
if ( V_47 < 0 )
goto V_71;
}
if ( ( V_16 -> V_72 == 0 ) || ( V_16 -> V_73 == 0 ) ) {
F_39 ( V_10 -> V_10 , L_20 ) ;
V_47 = - V_74 ;
goto V_75;
}
V_47 = F_56 ( V_10 , 1 ) ;
if ( V_47 < 0 ) {
F_39 ( V_10 -> V_10 , L_21 ) ;
goto V_75;
}
F_26 ( V_10 -> V_10 ) ;
V_47 = F_57 ( V_10 , F_58 ( V_10 -> V_40 , 0 ) ) ;
F_28 ( V_10 -> V_10 ) ;
if ( V_47 < 0 ) {
F_39 ( V_10 -> V_10 , L_22 ) ;
goto V_76;
}
F_13 (mod, &module_list, list) {
F_14 ( L_23 , V_2 -> V_3 , V_2 -> V_77 ) ;
V_46 = V_2 -> V_77 ;
if ( V_46 > 0 )
break;
}
V_16 -> V_18 = F_59 ( V_10 , V_46 ,
V_10 -> V_20 . V_78 ,
V_10 -> V_20 . V_79 ) ;
if ( F_46 ( V_16 -> V_18 ) ) {
V_47 = F_60 ( V_16 -> V_18 ) ;
goto V_80;
}
F_61 ( V_10 ) ;
return 0 ;
V_80:
F_26 ( V_10 -> V_10 ) ;
F_27 ( V_10 ) ;
F_28 ( V_10 -> V_10 ) ;
V_76:
F_25 ( V_10 ) ;
V_70:
F_24 ( V_10 ) ;
V_71:
if ( V_16 -> V_50 )
F_62 ( V_10 -> V_10 , V_10 ) ;
V_75:
F_21 ( V_10 ) ;
V_69:
F_35 ( V_10 -> V_10 ) ;
#ifdef F_29
F_30 ( & V_16 -> V_30 ,
V_34 ) ;
V_61:
F_31 ( V_16 -> V_58 ) ;
#endif
V_59:
F_31 ( V_16 -> V_33 ) ;
V_57:
F_32 ( V_16 -> V_35 ) ;
V_54:
F_33 ( V_16 -> V_36 ) ;
F_34 ( V_16 -> V_36 ) ;
V_51:
V_10 -> V_17 = NULL ;
F_36 ( V_16 ) ;
return V_47 ;
}
static void F_63 ( struct V_9 * V_10 , struct V_11 * V_81 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_64 ( V_16 -> V_19 , V_81 ) ;
}
static void F_65 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_66 ( V_16 -> V_18 ) ;
}
static T_2 F_67 ( int V_82 , void * V_83 )
{
struct V_9 * V_10 = V_83 ;
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
if ( V_16 -> V_68 == 1 )
F_72 ( V_10 , V_84 , V_85 ) ;
else
F_72 ( V_10 , V_86 , V_87 ) ;
return 0 ;
}
static void F_73 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
if ( V_16 -> V_68 == 1 ) {
F_74 ( V_10 , V_84 ,
V_85 | V_88 ) ;
F_74 ( V_10 , V_89 , V_90 ) ;
} else {
F_74 ( V_10 , V_86 ,
V_87 | V_91 |
V_92 | V_93 |
V_94 ) ;
}
}
static void F_75 ( struct V_9 * V_10 , bool V_95 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
T_1 V_96 , V_97 ;
if ( V_16 -> V_68 == 1 ) {
V_96 = V_89 ;
V_97 = V_90 ;
} else {
V_96 = V_86 ;
V_97 = V_92 |
V_93 | V_94 ;
}
if ( V_95 )
F_72 ( V_10 , V_96 , V_97 ) ;
else
F_74 ( V_10 , V_96 , V_97 ) ;
}
static int F_76 ( struct V_9 * V_10 , int V_19 )
{
F_75 ( V_10 , true ) ;
return 0 ;
}
static void F_77 ( struct V_9 * V_10 , int V_19 )
{
F_75 ( V_10 , false ) ;
}
static int F_78 ( struct V_98 * V_99 , void * V_83 )
{
struct V_100 * V_42 = (struct V_100 * ) V_99 -> V_101 ;
struct V_9 * V_10 = V_42 -> V_102 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_17 ;
unsigned V_103 ;
F_26 ( V_10 -> V_10 ) ;
F_79 ( V_99 , L_24 , V_16 -> V_68 ) ;
for ( V_103 = 0 ; V_103 < F_80 ( V_104 ) ; V_103 ++ )
if ( V_16 -> V_68 >= V_104 [ V_103 ] . V_68 )
F_79 ( V_99 , L_25 , V_104 [ V_103 ] . V_3 ,
F_51 ( V_10 , V_104 [ V_103 ] . V_96 ) ) ;
F_28 ( V_10 -> V_10 ) ;
return 0 ;
}
static int F_81 ( struct V_98 * V_99 , void * V_83 )
{
struct V_100 * V_42 = (struct V_100 * ) V_99 -> V_101 ;
struct V_9 * V_10 = V_42 -> V_102 -> V_10 ;
return F_82 ( V_99 , & V_10 -> V_105 -> V_106 ) ;
}
static int F_83 ( struct V_107 * V_102 )
{
struct V_9 * V_10 = V_102 -> V_10 ;
struct V_1 * V_2 ;
int V_47 ;
V_47 = F_84 ( V_108 ,
F_80 ( V_108 ) ,
V_102 -> V_109 , V_102 ) ;
F_13 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_110 )
V_2 -> V_5 -> V_110 ( V_2 , V_102 ) ;
if ( V_47 ) {
F_39 ( V_10 -> V_10 , L_26 ) ;
return V_47 ;
}
return V_47 ;
}
static void F_85 ( struct V_107 * V_102 )
{
struct V_1 * V_2 ;
F_86 ( V_108 ,
F_80 ( V_108 ) , V_102 ) ;
F_13 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_111 )
V_2 -> V_5 -> V_111 ( V_2 , V_102 ) ;
}
static int F_87 ( struct V_112 * V_10 )
{
struct V_9 * V_113 = F_88 ( V_10 ) ;
struct V_15 * V_16 = V_113 -> V_17 ;
unsigned V_103 , V_114 = 0 ;
F_89 ( V_113 ) ;
for ( V_103 = 0 ; V_103 < F_80 ( V_104 ) ; V_103 ++ )
if ( V_104 [ V_103 ] . V_115 && ( V_16 -> V_68 >= V_104 [ V_103 ] . V_68 ) )
V_16 -> V_116 [ V_114 ++ ] = F_51 ( V_113 , V_104 [ V_103 ] . V_96 ) ;
return 0 ;
}
static int F_90 ( struct V_112 * V_10 )
{
struct V_9 * V_113 = F_88 ( V_10 ) ;
struct V_15 * V_16 = V_113 -> V_17 ;
unsigned V_103 , V_114 = 0 ;
for ( V_103 = 0 ; V_103 < F_80 ( V_104 ) ; V_103 ++ )
if ( V_104 [ V_103 ] . V_115 && ( V_16 -> V_68 >= V_104 [ V_103 ] . V_68 ) )
F_91 ( V_113 , V_104 [ V_103 ] . V_96 , V_16 -> V_116 [ V_114 ++ ] ) ;
F_92 ( V_113 ) ;
return 0 ;
}
static int F_93 ( struct V_112 * V_10 )
{
return F_94 ( & V_117 , F_95 ( V_10 ) ) ;
}
static void F_96 ( struct V_112 * V_10 )
{
F_97 ( F_88 ( V_10 ) ) ;
}
static int F_98 ( struct V_38 * V_39 )
{
struct V_118 * V_119 = NULL ;
int V_47 ;
if ( ! V_39 -> V_10 . V_43 ) {
F_39 ( & V_39 -> V_10 , L_27 ) ;
return - V_74 ;
}
V_47 = F_40 ( & V_39 -> V_10 , & V_119 ) ;
if ( V_47 < 0 )
return V_47 ;
else if ( V_47 == 0 )
return F_94 ( & V_117 , V_39 ) ;
else
return F_99 ( & V_39 -> V_10 ,
& V_120 ,
V_119 ) ;
}
static int F_100 ( struct V_38 * V_39 )
{
struct V_9 * V_113 = F_88 ( & V_39 -> V_10 ) ;
struct V_15 * V_16 = V_113 -> V_17 ;
if ( ! V_16 )
return 0 ;
if ( V_16 -> V_50 )
F_101 ( & V_39 -> V_10 , & V_120 ) ;
else
F_97 ( F_102 ( V_39 ) ) ;
return 0 ;
}
static int T_3 F_103 ( void )
{
F_14 ( L_28 ) ;
F_104 () ;
F_105 () ;
return F_106 ( & V_121 ) ;
}
static void T_4 F_107 ( void )
{
F_14 ( L_29 ) ;
F_108 ( & V_121 ) ;
F_109 () ;
F_110 () ;
}
