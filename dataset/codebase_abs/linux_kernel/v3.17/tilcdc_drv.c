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
F_23 ( V_18 -> V_20 ) ;
F_24 ( V_12 ) ;
F_25 ( V_12 ) ;
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
V_50 = F_41 ( V_44 , V_55 , 0 ) ;
if ( ! V_50 ) {
F_16 ( V_12 -> V_12 , L_5 ) ;
V_52 = - V_56 ;
goto V_57;
}
V_18 -> V_40 = F_42 ( V_50 -> V_58 , F_43 ( V_50 ) ) ;
if ( ! V_18 -> V_40 ) {
F_16 ( V_12 -> V_12 , L_6 ) ;
V_52 = - V_54 ;
goto V_57;
}
V_18 -> V_38 = F_44 ( V_12 -> V_12 , L_7 ) ;
if ( F_45 ( V_18 -> V_38 ) ) {
F_16 ( V_12 -> V_12 , L_8 ) ;
V_52 = - V_59 ;
goto V_57;
}
V_18 -> V_60 = F_44 ( V_12 -> V_12 , L_9 ) ;
if ( F_45 ( V_18 -> V_38 ) ) {
F_16 ( V_12 -> V_12 , L_10 ) ;
V_52 = - V_59 ;
goto V_57;
}
#ifdef F_30
V_18 -> V_37 = F_20 ( V_18 -> V_38 ) ;
V_18 -> V_35 . V_61 = F_18 ;
V_52 = F_46 ( & V_18 -> V_35 ,
V_39 ) ;
if ( V_52 ) {
F_16 ( V_12 -> V_12 , L_11 ) ;
goto V_57;
}
#endif
if ( F_47 ( V_47 , L_12 , & V_18 -> V_62 ) )
V_18 -> V_62 = V_63 ;
F_15 ( L_13 , V_18 -> V_62 ) ;
if ( F_47 ( V_47 , L_14 , & V_18 -> V_28 ) )
V_18 -> V_28 = V_64 ;
F_15 ( L_15 , V_18 -> V_28 ) ;
if ( F_47 ( V_47 , L_16 ,
& V_18 -> V_65 ) )
V_18 -> V_65 = V_66 ;
F_15 ( L_17 , V_18 -> V_65 ) ;
F_48 ( V_12 -> V_12 ) ;
F_27 ( V_12 -> V_12 ) ;
switch ( F_49 ( V_12 , V_67 ) ) {
case 0x4c100102 :
V_18 -> V_68 = 1 ;
break;
case 0x4f200800 :
case 0x4f201000 :
V_18 -> V_68 = 2 ;
break;
default:
F_50 ( V_12 -> V_12 , L_18
L_19 ,
F_49 ( V_12 , V_67 ) ) ;
V_18 -> V_68 = 1 ;
break;
}
F_29 ( V_12 -> V_12 ) ;
V_52 = F_11 ( V_12 ) ;
if ( V_52 < 0 ) {
F_16 ( V_12 -> V_12 , L_20 ) ;
goto V_57;
}
V_52 = F_51 ( V_12 , 1 ) ;
if ( V_52 < 0 ) {
F_16 ( V_12 -> V_12 , L_21 ) ;
goto V_57;
}
F_27 ( V_12 -> V_12 ) ;
V_52 = F_52 ( V_12 , F_53 ( V_12 -> V_45 , 0 ) ) ;
F_29 ( V_12 -> V_12 ) ;
if ( V_52 < 0 ) {
F_16 ( V_12 -> V_12 , L_22 ) ;
goto V_57;
}
F_54 ( V_44 , V_12 ) ;
F_14 (mod, &module_list, list) {
F_15 ( L_23 , V_2 -> V_3 , V_2 -> V_69 ) ;
V_51 = V_2 -> V_69 ;
if ( V_51 > 0 )
break;
}
V_18 -> V_20 = F_55 ( V_12 , V_51 ,
V_12 -> V_25 . V_70 ,
V_12 -> V_25 . V_71 ) ;
F_56 ( V_12 ) ;
return 0 ;
V_57:
F_22 ( V_12 ) ;
return V_52 ;
}
static void F_57 ( struct V_11 * V_12 , struct V_13 * V_72 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
F_58 ( V_18 -> V_21 , V_72 ) ;
}
static void F_59 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
F_60 ( V_18 -> V_20 ) ;
}
static T_2 F_61 ( int V_73 , void * V_74 )
{
struct V_11 * V_12 = V_74 ;
struct V_17 * V_18 = V_12 -> V_19 ;
return F_62 ( V_18 -> V_21 ) ;
}
static void F_63 ( struct V_11 * V_12 )
{
F_64 ( V_12 , 0xffffffff ) ;
}
static int F_65 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
if ( V_18 -> V_68 == 1 )
F_66 ( V_12 , V_75 , V_76 ) ;
else
F_66 ( V_12 , V_77 , V_78 ) ;
return 0 ;
}
static void F_67 ( struct V_11 * V_12 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
if ( V_18 -> V_68 == 1 ) {
F_68 ( V_12 , V_75 ,
V_76 | V_79 ) ;
F_68 ( V_12 , V_80 , V_81 ) ;
} else {
F_68 ( V_12 , V_77 ,
V_78 | V_82 |
V_83 | V_84 |
V_85 ) ;
}
}
static void F_69 ( struct V_11 * V_12 , bool V_86 )
{
struct V_17 * V_18 = V_12 -> V_19 ;
T_1 V_87 , V_88 ;
if ( V_18 -> V_68 == 1 ) {
V_87 = V_80 ;
V_88 = V_81 ;
} else {
V_87 = V_77 ;
V_88 = V_83 |
V_84 | V_85 ;
}
if ( V_86 )
F_66 ( V_12 , V_87 , V_88 ) ;
else
F_68 ( V_12 , V_87 , V_88 ) ;
}
static int F_70 ( struct V_11 * V_12 , int V_21 )
{
F_69 ( V_12 , true ) ;
return 0 ;
}
static void F_71 ( struct V_11 * V_12 , int V_21 )
{
F_69 ( V_12 , false ) ;
}
static int F_72 ( struct V_89 * V_90 , void * V_74 )
{
struct V_91 * V_47 = (struct V_91 * ) V_90 -> V_92 ;
struct V_11 * V_12 = V_47 -> V_93 -> V_12 ;
struct V_17 * V_18 = V_12 -> V_19 ;
unsigned V_94 ;
F_27 ( V_12 -> V_12 ) ;
F_73 ( V_90 , L_24 , V_18 -> V_68 ) ;
for ( V_94 = 0 ; V_94 < F_74 ( V_95 ) ; V_94 ++ )
if ( V_18 -> V_68 >= V_95 [ V_94 ] . V_68 )
F_73 ( V_90 , L_25 , V_95 [ V_94 ] . V_3 ,
F_49 ( V_12 , V_95 [ V_94 ] . V_87 ) ) ;
F_29 ( V_12 -> V_12 ) ;
return 0 ;
}
static int F_75 ( struct V_89 * V_90 , void * V_74 )
{
struct V_91 * V_47 = (struct V_91 * ) V_90 -> V_92 ;
struct V_11 * V_12 = V_47 -> V_93 -> V_12 ;
return F_76 ( V_90 , & V_12 -> V_96 -> V_97 ) ;
}
static int F_77 ( struct V_98 * V_93 )
{
struct V_11 * V_12 = V_93 -> V_12 ;
struct V_1 * V_2 ;
int V_52 ;
V_52 = F_78 ( V_99 ,
F_74 ( V_99 ) ,
V_93 -> V_100 , V_93 ) ;
F_14 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_101 )
V_2 -> V_5 -> V_101 ( V_2 , V_93 ) ;
if ( V_52 ) {
F_16 ( V_12 -> V_12 , L_26 ) ;
return V_52 ;
}
return V_52 ;
}
static void F_79 ( struct V_98 * V_93 )
{
struct V_1 * V_2 ;
F_80 ( V_99 ,
F_74 ( V_99 ) , V_93 ) ;
F_14 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_102 )
V_2 -> V_5 -> V_102 ( V_2 , V_93 ) ;
}
static int F_81 ( struct V_103 * V_12 )
{
struct V_11 * V_104 = F_82 ( V_12 ) ;
struct V_17 * V_18 = V_104 -> V_19 ;
unsigned V_94 , V_105 = 0 ;
F_83 ( V_104 ) ;
for ( V_94 = 0 ; V_94 < F_74 ( V_95 ) ; V_94 ++ )
if ( V_95 [ V_94 ] . V_106 && ( V_18 -> V_68 >= V_95 [ V_94 ] . V_68 ) )
V_18 -> V_107 [ V_105 ++ ] = F_49 ( V_104 , V_95 [ V_94 ] . V_87 ) ;
return 0 ;
}
static int F_84 ( struct V_103 * V_12 )
{
struct V_11 * V_104 = F_82 ( V_12 ) ;
struct V_17 * V_18 = V_104 -> V_19 ;
unsigned V_94 , V_105 = 0 ;
for ( V_94 = 0 ; V_94 < F_74 ( V_95 ) ; V_94 ++ )
if ( V_95 [ V_94 ] . V_106 && ( V_18 -> V_68 >= V_95 [ V_94 ] . V_68 ) )
F_85 ( V_104 , V_95 [ V_94 ] . V_87 , V_18 -> V_107 [ V_105 ++ ] ) ;
F_86 ( V_104 ) ;
return 0 ;
}
static int F_87 ( struct V_43 * V_44 )
{
if ( ! V_44 -> V_12 . V_48 ) {
F_16 ( & V_44 -> V_12 , L_27 ) ;
return - V_24 ;
}
if ( V_9 == true )
return - V_108 ;
return F_88 ( & V_109 , V_44 ) ;
}
static int F_89 ( struct V_43 * V_44 )
{
F_90 ( F_91 ( V_44 ) ) ;
return 0 ;
}
static int T_3 F_92 ( void )
{
F_15 ( L_28 ) ;
F_93 () ;
F_94 () ;
F_95 () ;
return F_96 ( & V_110 ) ;
}
static void T_4 F_97 ( void )
{
F_15 ( L_29 ) ;
F_98 ( & V_110 ) ;
F_99 () ;
F_100 () ;
F_101 () ;
}
