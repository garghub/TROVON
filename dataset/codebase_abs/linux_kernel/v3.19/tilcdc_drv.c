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
F_17 ( V_12 ) ;
return - V_24 ;
}
V_12 -> V_25 . V_26 = 0 ;
V_12 -> V_25 . V_27 = 0 ;
V_12 -> V_25 . V_28 = F_18 ( V_18 -> V_21 ) ;
V_12 -> V_25 . V_29 = 2048 ;
V_12 -> V_25 . V_5 = & V_30 ;
return 0 ;
}
static int F_19 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_34 )
{
struct V_17 * V_18 = F_20 ( V_32 ,
struct V_17 , V_35 ) ;
if ( V_33 == V_36 ) {
if ( V_18 -> V_37 != F_21 ( V_18 -> V_38 ) ) {
V_18 -> V_37 = F_21 ( V_18 -> V_38 ) ;
F_22 ( V_18 -> V_21 ) ;
}
}
return 0 ;
}
static int F_23 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
F_24 ( V_18 -> V_20 ) ;
F_25 ( V_12 ) ;
F_17 ( V_12 ) ;
F_26 ( V_12 ) ;
F_27 ( V_12 -> V_12 ) ;
F_28 ( V_12 ) ;
F_29 ( V_12 -> V_12 ) ;
#ifdef F_30
F_31 ( & V_18 -> V_35 ,
V_39 ) ;
#endif
if ( V_18 -> V_38 )
F_32 ( V_18 -> V_38 ) ;
if ( V_18 -> V_40 )
F_33 ( V_18 -> V_40 ) ;
F_34 ( V_18 -> V_41 ) ;
F_35 ( V_18 -> V_41 ) ;
V_12 -> V_19 = NULL ;
F_36 ( V_12 -> V_12 ) ;
F_37 ( V_18 ) ;
return 0 ;
}
static int F_38 ( struct V_11 * V_12 , unsigned long V_42 )
{
struct V_43 * V_44 = V_12 -> V_45 ;
struct V_46 * V_47 = V_44 -> V_12 . V_48 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_49 * V_50 ;
T_1 V_51 = 0 ;
int V_52 ;
V_18 = F_39 ( sizeof( * V_18 ) , V_53 ) ;
if ( ! V_18 ) {
F_16 ( V_12 -> V_12 , L_3 ) ;
return - V_54 ;
}
V_12 -> V_19 = V_18 ;
V_18 -> V_41 = F_40 ( L_4 , 0 ) ;
if ( ! V_18 -> V_41 ) {
V_52 = - V_54 ;
goto V_55;
}
V_50 = F_41 ( V_44 , V_56 , 0 ) ;
if ( ! V_50 ) {
F_16 ( V_12 -> V_12 , L_5 ) ;
V_52 = - V_57 ;
goto V_58;
}
V_18 -> V_40 = F_42 ( V_50 -> V_59 , F_43 ( V_50 ) ) ;
if ( ! V_18 -> V_40 ) {
F_16 ( V_12 -> V_12 , L_6 ) ;
V_52 = - V_54 ;
goto V_58;
}
V_18 -> V_38 = F_44 ( V_12 -> V_12 , L_7 ) ;
if ( F_45 ( V_18 -> V_38 ) ) {
F_16 ( V_12 -> V_12 , L_8 ) ;
V_52 = - V_60 ;
goto V_61;
}
V_18 -> V_62 = F_44 ( V_12 -> V_12 , L_9 ) ;
if ( F_45 ( V_18 -> V_38 ) ) {
F_16 ( V_12 -> V_12 , L_10 ) ;
V_52 = - V_60 ;
goto V_63;
}
#ifdef F_30
V_18 -> V_37 = F_21 ( V_18 -> V_38 ) ;
V_18 -> V_35 . V_64 = F_19 ;
V_52 = F_46 ( & V_18 -> V_35 ,
V_39 ) ;
if ( V_52 ) {
F_16 ( V_12 -> V_12 , L_11 ) ;
goto V_65;
}
#endif
if ( F_47 ( V_47 , L_12 , & V_18 -> V_66 ) )
V_18 -> V_66 = V_67 ;
F_15 ( L_13 , V_18 -> V_66 ) ;
if ( F_47 ( V_47 , L_14 , & V_18 -> V_28 ) )
V_18 -> V_28 = V_68 ;
F_15 ( L_15 , V_18 -> V_28 ) ;
if ( F_47 ( V_47 , L_16 ,
& V_18 -> V_69 ) )
V_18 -> V_69 = V_70 ;
F_15 ( L_17 , V_18 -> V_69 ) ;
F_48 ( V_12 -> V_12 ) ;
F_27 ( V_12 -> V_12 ) ;
switch ( F_49 ( V_12 , V_71 ) ) {
case 0x4c100102 :
V_18 -> V_72 = 1 ;
break;
case 0x4f200800 :
case 0x4f201000 :
V_18 -> V_72 = 2 ;
break;
default:
F_50 ( V_12 -> V_12 , L_18
L_19 ,
F_49 ( V_12 , V_71 ) ) ;
V_18 -> V_72 = 1 ;
break;
}
F_29 ( V_12 -> V_12 ) ;
V_52 = F_11 ( V_12 ) ;
if ( V_52 < 0 ) {
F_16 ( V_12 -> V_12 , L_20 ) ;
goto V_73;
}
V_52 = F_51 ( V_12 , 1 ) ;
if ( V_52 < 0 ) {
F_16 ( V_12 -> V_12 , L_21 ) ;
goto V_74;
}
F_27 ( V_12 -> V_12 ) ;
V_52 = F_52 ( V_12 , F_53 ( V_12 -> V_45 , 0 ) ) ;
F_29 ( V_12 -> V_12 ) ;
if ( V_52 < 0 ) {
F_16 ( V_12 -> V_12 , L_22 ) ;
goto V_75;
}
F_54 ( V_44 , V_12 ) ;
F_14 (mod, &module_list, list) {
F_15 ( L_23 , V_2 -> V_3 , V_2 -> V_76 ) ;
V_51 = V_2 -> V_76 ;
if ( V_51 > 0 )
break;
}
V_18 -> V_20 = F_55 ( V_12 , V_51 ,
V_12 -> V_25 . V_77 ,
V_12 -> V_25 . V_78 ) ;
if ( F_45 ( V_18 -> V_20 ) ) {
V_52 = F_56 ( V_18 -> V_20 ) ;
goto V_79;
}
F_57 ( V_12 ) ;
return 0 ;
V_79:
F_27 ( V_12 -> V_12 ) ;
F_28 ( V_12 ) ;
F_29 ( V_12 -> V_12 ) ;
V_75:
F_26 ( V_12 ) ;
V_74:
F_17 ( V_12 ) ;
V_73:
F_36 ( V_12 -> V_12 ) ;
#ifdef F_30
F_31 ( & V_18 -> V_35 ,
V_39 ) ;
V_65:
F_32 ( V_18 -> V_62 ) ;
#endif
V_63:
F_32 ( V_18 -> V_38 ) ;
V_61:
F_33 ( V_18 -> V_40 ) ;
V_58:
F_34 ( V_18 -> V_41 ) ;
F_35 ( V_18 -> V_41 ) ;
V_55:
V_12 -> V_19 = NULL ;
F_37 ( V_18 ) ;
return V_52 ;
}
static void F_58 ( struct V_11 * V_12 , struct V_13 * V_80 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
F_59 ( V_18 -> V_21 , V_80 ) ;
}
static void F_60 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
F_61 ( V_18 -> V_20 ) ;
}
static T_2 F_62 ( int V_81 , void * V_82 )
{
struct V_11 * V_12 = V_82 ;
struct V_17 * V_18 = V_12 -> V_19 ;
return F_63 ( V_18 -> V_21 ) ;
}
static void F_64 ( struct V_11 * V_12 )
{
F_65 ( V_12 , 0xffffffff ) ;
}
static int F_66 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
if ( V_18 -> V_72 == 1 )
F_67 ( V_12 , V_83 , V_84 ) ;
else
F_67 ( V_12 , V_85 , V_86 ) ;
return 0 ;
}
static void F_68 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
if ( V_18 -> V_72 == 1 ) {
F_69 ( V_12 , V_83 ,
V_84 | V_87 ) ;
F_69 ( V_12 , V_88 , V_89 ) ;
} else {
F_69 ( V_12 , V_85 ,
V_86 | V_90 |
V_91 | V_92 |
V_93 ) ;
}
}
static void F_70 ( struct V_11 * V_12 , bool V_94 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
T_1 V_95 , V_96 ;
if ( V_18 -> V_72 == 1 ) {
V_95 = V_88 ;
V_96 = V_89 ;
} else {
V_95 = V_85 ;
V_96 = V_91 |
V_92 | V_93 ;
}
if ( V_94 )
F_67 ( V_12 , V_95 , V_96 ) ;
else
F_69 ( V_12 , V_95 , V_96 ) ;
}
static int F_71 ( struct V_11 * V_12 , int V_21 )
{
F_70 ( V_12 , true ) ;
return 0 ;
}
static void F_72 ( struct V_11 * V_12 , int V_21 )
{
F_70 ( V_12 , false ) ;
}
static int F_73 ( struct V_97 * V_98 , void * V_82 )
{
struct V_99 * V_47 = (struct V_99 * ) V_98 -> V_100 ;
struct V_11 * V_12 = V_47 -> V_101 -> V_12 ;
struct V_17 * V_18 = V_12 -> V_19 ;
unsigned V_102 ;
F_27 ( V_12 -> V_12 ) ;
F_74 ( V_98 , L_24 , V_18 -> V_72 ) ;
for ( V_102 = 0 ; V_102 < F_75 ( V_103 ) ; V_102 ++ )
if ( V_18 -> V_72 >= V_103 [ V_102 ] . V_72 )
F_74 ( V_98 , L_25 , V_103 [ V_102 ] . V_3 ,
F_49 ( V_12 , V_103 [ V_102 ] . V_95 ) ) ;
F_29 ( V_12 -> V_12 ) ;
return 0 ;
}
static int F_76 ( struct V_97 * V_98 , void * V_82 )
{
struct V_99 * V_47 = (struct V_99 * ) V_98 -> V_100 ;
struct V_11 * V_12 = V_47 -> V_101 -> V_12 ;
return F_77 ( V_98 , & V_12 -> V_104 -> V_105 ) ;
}
static int F_78 ( struct V_106 * V_101 )
{
struct V_11 * V_12 = V_101 -> V_12 ;
struct V_1 * V_2 ;
int V_52 ;
V_52 = F_79 ( V_107 ,
F_75 ( V_107 ) ,
V_101 -> V_108 , V_101 ) ;
F_14 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_109 )
V_2 -> V_5 -> V_109 ( V_2 , V_101 ) ;
if ( V_52 ) {
F_16 ( V_12 -> V_12 , L_26 ) ;
return V_52 ;
}
return V_52 ;
}
static void F_80 ( struct V_106 * V_101 )
{
struct V_1 * V_2 ;
F_81 ( V_107 ,
F_75 ( V_107 ) , V_101 ) ;
F_14 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_110 )
V_2 -> V_5 -> V_110 ( V_2 , V_101 ) ;
}
static int F_82 ( struct V_111 * V_12 )
{
struct V_11 * V_112 = F_83 ( V_12 ) ;
struct V_17 * V_18 = V_112 -> V_19 ;
unsigned V_102 , V_113 = 0 ;
F_84 ( V_112 ) ;
for ( V_102 = 0 ; V_102 < F_75 ( V_103 ) ; V_102 ++ )
if ( V_103 [ V_102 ] . V_114 && ( V_18 -> V_72 >= V_103 [ V_102 ] . V_72 ) )
V_18 -> V_115 [ V_113 ++ ] = F_49 ( V_112 , V_103 [ V_102 ] . V_95 ) ;
return 0 ;
}
static int F_85 ( struct V_111 * V_12 )
{
struct V_11 * V_112 = F_83 ( V_12 ) ;
struct V_17 * V_18 = V_112 -> V_19 ;
unsigned V_102 , V_113 = 0 ;
for ( V_102 = 0 ; V_102 < F_75 ( V_103 ) ; V_102 ++ )
if ( V_103 [ V_102 ] . V_114 && ( V_18 -> V_72 >= V_103 [ V_102 ] . V_72 ) )
F_86 ( V_112 , V_103 [ V_102 ] . V_95 , V_18 -> V_115 [ V_113 ++ ] ) ;
F_87 ( V_112 ) ;
return 0 ;
}
static int F_88 ( struct V_43 * V_44 )
{
if ( ! V_44 -> V_12 . V_48 ) {
F_16 ( & V_44 -> V_12 , L_27 ) ;
return - V_24 ;
}
if ( V_9 == true )
return - V_116 ;
return F_89 ( & V_117 , V_44 ) ;
}
static int F_90 ( struct V_43 * V_44 )
{
F_91 ( F_92 ( V_44 ) ) ;
return 0 ;
}
static int T_3 F_93 ( void )
{
F_15 ( L_28 ) ;
F_94 () ;
F_95 () ;
F_96 () ;
return F_97 ( & V_118 ) ;
}
static void T_4 F_98 ( void )
{
F_15 ( L_29 ) ;
F_99 ( & V_118 ) ;
F_100 () ;
F_101 () ;
F_102 () ;
}
