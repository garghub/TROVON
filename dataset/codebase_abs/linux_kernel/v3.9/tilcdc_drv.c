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
if ( V_16 -> V_18 )
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
if ( ( V_16 -> V_20 = 0 ) || ( V_16 -> V_21 == 0 ) ) {
F_15 ( V_10 -> V_10 , L_2 ) ;
return - V_22 ;
}
V_10 -> V_23 . V_24 = 0 ;
V_10 -> V_23 . V_25 = 0 ;
V_10 -> V_23 . V_26 = F_16 ( V_16 -> V_19 ) ;
V_10 -> V_23 . V_27 = 2048 ;
V_10 -> V_23 . V_5 = & V_28 ;
return 0 ;
}
static int F_17 ( struct V_29 * V_30 ,
unsigned long V_31 , void * V_32 )
{
struct V_15 * V_16 = F_18 ( V_30 ,
struct V_15 , V_33 ) ;
if ( V_31 == V_34 ) {
if ( V_16 -> V_35 != F_19 ( V_16 -> V_36 ) ) {
V_16 -> V_35 = F_19 ( V_16 -> V_36 ) ;
F_20 ( V_16 -> V_19 ) ;
}
}
return 0 ;
}
static int F_21 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_1 * V_2 , * V_37 ;
F_22 ( V_10 ) ;
F_23 ( V_10 ) ;
F_24 ( V_10 ) ;
F_25 ( V_10 -> V_10 ) ;
F_26 ( V_10 ) ;
F_27 ( V_10 -> V_10 ) ;
#ifdef F_28
F_29 ( & V_16 -> V_33 ,
V_38 ) ;
#endif
if ( V_16 -> V_36 )
F_30 ( V_16 -> V_36 ) ;
if ( V_16 -> V_39 )
F_31 ( V_16 -> V_39 ) ;
F_32 ( V_16 -> V_40 ) ;
F_33 ( V_16 -> V_40 ) ;
V_10 -> V_17 = NULL ;
F_34 ( V_10 -> V_10 ) ;
F_35 (mod, cur, &module_list, list) {
F_14 ( L_3 , V_2 -> V_3 ) ;
V_2 -> V_5 -> V_41 ( V_2 ) ;
}
F_36 ( V_16 ) ;
return 0 ;
}
static int F_37 ( struct V_9 * V_10 , unsigned long V_42 )
{
struct V_43 * V_44 = V_10 -> V_45 ;
struct V_46 * V_47 = V_44 -> V_10 . V_48 ;
struct V_15 * V_16 ;
struct V_49 * V_50 ;
int V_51 ;
V_16 = F_38 ( sizeof( * V_16 ) , V_52 ) ;
if ( ! V_16 ) {
F_15 ( V_10 -> V_10 , L_4 ) ;
return - V_53 ;
}
V_10 -> V_17 = V_16 ;
V_16 -> V_40 = F_39 ( L_5 , 0 ) ;
V_50 = F_40 ( V_44 , V_54 , 0 ) ;
if ( ! V_50 ) {
F_15 ( V_10 -> V_10 , L_6 ) ;
V_51 = - V_55 ;
goto V_56;
}
V_16 -> V_39 = F_41 ( V_50 -> V_57 , F_42 ( V_50 ) ) ;
if ( ! V_16 -> V_39 ) {
F_15 ( V_10 -> V_10 , L_7 ) ;
V_51 = - V_53 ;
goto V_56;
}
V_16 -> V_36 = F_43 ( V_10 -> V_10 , L_8 ) ;
if ( F_44 ( V_16 -> V_36 ) ) {
F_15 ( V_10 -> V_10 , L_9 ) ;
V_51 = - V_58 ;
goto V_56;
}
V_16 -> V_59 = F_43 ( V_10 -> V_10 , L_10 ) ;
if ( F_44 ( V_16 -> V_36 ) ) {
F_15 ( V_10 -> V_10 , L_11 ) ;
V_51 = - V_58 ;
goto V_56;
}
#ifdef F_28
V_16 -> V_35 = F_19 ( V_16 -> V_36 ) ;
V_16 -> V_33 . V_60 = F_17 ;
V_51 = F_45 ( & V_16 -> V_33 ,
V_38 ) ;
if ( V_51 ) {
F_15 ( V_10 -> V_10 , L_12 ) ;
goto V_56;
}
#endif
if ( F_46 ( V_47 , L_13 , & V_16 -> V_61 ) )
V_16 -> V_61 = 1280 * 1024 * 60 ;
F_47 ( V_10 -> V_10 ) ;
F_25 ( V_10 -> V_10 ) ;
switch ( F_48 ( V_10 , V_62 ) ) {
case 0x4c100102 :
V_16 -> V_63 = 1 ;
break;
case 0x4f200800 :
case 0x4f201000 :
V_16 -> V_63 = 2 ;
break;
default:
F_49 ( V_10 -> V_10 , L_14
L_15 ,
F_48 ( V_10 , V_62 ) ) ;
V_16 -> V_63 = 1 ;
break;
}
F_27 ( V_10 -> V_10 ) ;
V_51 = F_10 ( V_10 ) ;
if ( V_51 < 0 ) {
F_15 ( V_10 -> V_10 , L_16 ) ;
goto V_56;
}
V_51 = F_50 ( V_10 , 1 ) ;
if ( V_51 < 0 ) {
F_15 ( V_10 -> V_10 , L_17 ) ;
goto V_56;
}
F_25 ( V_10 -> V_10 ) ;
V_51 = F_51 ( V_10 ) ;
F_27 ( V_10 -> V_10 ) ;
if ( V_51 < 0 ) {
F_15 ( V_10 -> V_10 , L_18 ) ;
goto V_56;
}
F_52 ( V_44 , V_10 ) ;
V_16 -> V_18 = F_53 ( V_10 , 16 ,
V_10 -> V_23 . V_64 ,
V_10 -> V_23 . V_65 ) ;
F_54 ( V_10 ) ;
return 0 ;
V_56:
F_21 ( V_10 ) ;
return V_51 ;
}
static void F_55 ( struct V_9 * V_10 , struct V_11 * V_66 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_56 ( V_16 -> V_19 , V_66 ) ;
}
static void F_57 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
F_58 ( V_16 -> V_18 ) ;
}
static T_1 F_59 ( T_2 )
{
struct V_9 * V_10 = V_67 ;
struct V_15 * V_16 = V_10 -> V_17 ;
return F_60 ( V_16 -> V_19 ) ;
}
static void F_61 ( struct V_9 * V_10 )
{
F_62 ( V_10 , 0xffffffff ) ;
}
static int F_63 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
if ( V_16 -> V_63 == 1 ) {
F_64 ( V_10 , V_68 , V_69 ) ;
} else {
F_64 ( V_10 , V_70 , V_71 ) ;
}
return 0 ;
}
static void F_65 ( struct V_9 * V_10 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
if ( V_16 -> V_63 == 1 ) {
F_66 ( V_10 , V_68 ,
V_69 | V_72 ) ;
F_66 ( V_10 , V_73 , V_74 ) ;
} else {
F_66 ( V_10 , V_70 ,
V_71 | V_75 |
V_76 | V_77 |
V_78 ) ;
}
}
static void F_67 ( struct V_9 * V_10 , bool V_79 )
{
struct V_15 * V_16 = V_10 -> V_17 ;
T_3 V_80 , V_81 ;
if ( V_16 -> V_63 == 1 ) {
V_80 = V_73 ;
V_81 = V_74 ;
} else {
V_80 = V_70 ;
V_81 = V_76 |
V_77 | V_78 ;
}
if ( V_79 )
F_64 ( V_10 , V_80 , V_81 ) ;
else
F_66 ( V_10 , V_80 , V_81 ) ;
}
static int F_68 ( struct V_9 * V_10 , int V_19 )
{
F_67 ( V_10 , true ) ;
return 0 ;
}
static void F_69 ( struct V_9 * V_10 , int V_19 )
{
F_67 ( V_10 , false ) ;
}
static int F_70 ( struct V_82 * V_83 , void * V_67 )
{
struct V_84 * V_47 = (struct V_84 * ) V_83 -> V_85 ;
struct V_9 * V_10 = V_47 -> V_86 -> V_10 ;
struct V_15 * V_16 = V_10 -> V_17 ;
unsigned V_87 ;
F_25 ( V_10 -> V_10 ) ;
F_71 ( V_83 , L_19 , V_16 -> V_63 ) ;
for ( V_87 = 0 ; V_87 < F_72 ( V_88 ) ; V_87 ++ )
if ( V_16 -> V_63 >= V_88 [ V_87 ] . V_63 )
F_71 ( V_83 , L_20 , V_88 [ V_87 ] . V_3 ,
F_48 ( V_10 , V_88 [ V_87 ] . V_80 ) ) ;
F_27 ( V_10 -> V_10 ) ;
return 0 ;
}
static int F_73 ( struct V_82 * V_83 , void * V_67 )
{
struct V_84 * V_47 = (struct V_84 * ) V_83 -> V_85 ;
struct V_9 * V_10 = V_47 -> V_86 -> V_10 ;
return F_74 ( V_83 , V_10 -> V_89 ) ;
}
static int F_75 ( struct V_90 * V_86 )
{
struct V_9 * V_10 = V_86 -> V_10 ;
struct V_1 * V_2 ;
int V_51 ;
V_51 = F_76 ( V_91 ,
F_72 ( V_91 ) ,
V_86 -> V_92 , V_86 ) ;
F_13 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_93 )
V_2 -> V_5 -> V_93 ( V_2 , V_86 ) ;
if ( V_51 ) {
F_15 ( V_10 -> V_10 , L_21 ) ;
return V_51 ;
}
return V_51 ;
}
static void F_77 ( struct V_90 * V_86 )
{
struct V_1 * V_2 ;
F_78 ( V_91 ,
F_72 ( V_91 ) , V_86 ) ;
F_13 (mod, &module_list, list)
if ( V_2 -> V_5 -> V_94 )
V_2 -> V_5 -> V_94 ( V_2 , V_86 ) ;
}
static int F_79 ( struct V_95 * V_10 )
{
struct V_9 * V_96 = F_80 ( V_10 ) ;
struct V_15 * V_16 = V_96 -> V_17 ;
unsigned V_87 , V_97 = 0 ;
F_81 ( V_96 ) ;
for ( V_87 = 0 ; V_87 < F_72 ( V_88 ) ; V_87 ++ )
if ( V_88 [ V_87 ] . V_98 && ( V_16 -> V_63 >= V_88 [ V_87 ] . V_63 ) )
V_16 -> V_99 [ V_97 ++ ] = F_48 ( V_96 , V_88 [ V_87 ] . V_80 ) ;
return 0 ;
}
static int F_82 ( struct V_95 * V_10 )
{
struct V_9 * V_96 = F_80 ( V_10 ) ;
struct V_15 * V_16 = V_96 -> V_17 ;
unsigned V_87 , V_97 = 0 ;
for ( V_87 = 0 ; V_87 < F_72 ( V_88 ) ; V_87 ++ )
if ( V_88 [ V_87 ] . V_98 && ( V_16 -> V_63 >= V_88 [ V_87 ] . V_63 ) )
F_83 ( V_96 , V_88 [ V_87 ] . V_80 , V_16 -> V_99 [ V_97 ++ ] ) ;
F_84 ( V_96 ) ;
return 0 ;
}
static int F_85 ( struct V_43 * V_44 )
{
if ( ! V_44 -> V_10 . V_48 ) {
F_15 ( & V_44 -> V_10 , L_22 ) ;
return - V_22 ;
}
return F_86 ( & V_100 , V_44 ) ;
}
static int F_87 ( struct V_43 * V_44 )
{
F_88 ( & V_100 , V_44 ) ;
return 0 ;
}
static int T_4 F_89 ( void )
{
F_14 ( L_23 ) ;
F_90 () ;
F_91 () ;
F_92 () ;
return F_93 ( & V_101 ) ;
}
static void T_5 F_94 ( void )
{
F_14 ( L_24 ) ;
F_95 () ;
F_96 () ;
F_97 () ;
F_98 ( & V_101 ) ;
}
