static void F_1 ( struct V_1 * V_2 )
{
F_2 ( 0x0 , V_2 -> V_3 + V_4 ) ;
F_3 () ;
}
static bool F_4 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_5 & V_6 ) )
return false ;
if ( V_2 -> V_5 & V_7 )
return false ;
return true ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_8 ;
V_9:
V_8 = F_6 ( V_2 -> V_3 + V_10 ) ;
V_8 |= V_11 ;
F_2 ( V_8 , V_2 -> V_3 + V_10 ) ;
if ( F_7 ( F_6 , V_2 -> V_3 + V_12 ,
V_2 -> V_5 , ( V_2 -> V_5 & V_6 ) ,
V_13 , V_14 ) ) {
F_8 ( V_2 -> V_15 , L_1 ,
V_16 , V_2 -> V_17 ) ;
return;
}
V_8 = F_6 ( V_2 -> V_3 + V_10 ) ;
V_8 |= V_11 | V_18 ;
F_2 ( V_8 , V_2 -> V_3 + V_10 ) ;
V_2 -> V_5 = F_6 ( V_2 -> V_3 + V_12 ) ;
if ( F_9 ( ! ( V_2 -> V_5 & V_6 ) ) )
goto V_9;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_19 ;
F_11 ( V_2 -> V_3 ) ;
F_1 ( V_2 ) ;
V_19 = F_6 ( V_2 -> V_3 + V_10 ) ;
F_5 ( V_2 ) ;
if ( ! F_4 ( V_2 ) )
goto V_20;
V_2 -> V_21 = F_6 ( V_2 -> V_3 + V_22 ) ;
if ( V_2 -> V_21 == V_23 )
goto V_20;
if ( F_12 ( V_24 ) )
V_2 -> V_25 = F_6 ( V_2 -> V_3 + V_26 ) ;
if ( V_2 -> V_27 )
V_2 -> V_28 = F_6 ( V_2 -> V_3 + V_29 ) ;
if ( V_2 -> V_30 )
V_2 -> V_31 = F_6 ( V_2 -> V_3 + V_32 ) ;
V_20:
F_2 ( V_19 , V_2 -> V_3 + V_10 ) ;
F_13 ( V_2 -> V_3 ) ;
}
static unsigned long F_14 ( struct V_1 * V_2 )
{
return ( unsigned long ) V_2 -> V_25 << 32 |
( unsigned long ) V_2 -> V_21 ;
}
static unsigned long F_14 ( struct V_1 * V_2 )
{
unsigned long V_33 = 0 , V_34 = 0 ;
unsigned long V_35 ;
V_35 = ( unsigned long ) V_2 -> V_21 ;
if ( V_2 -> V_36 ) {
V_33 = 8 ;
V_34 = 4 ;
}
if ( V_35 & V_37 ) {
V_35 = ( V_35 & V_38 ) - V_34 ;
return V_35 ;
}
if ( V_35 & F_15 ( 1 ) )
F_16 ( V_2 -> V_15 ,
L_2 ) ;
else
V_35 = ( V_35 & V_39 ) - V_33 ;
return V_35 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_40 * V_15 = V_2 -> V_15 ;
unsigned long V_35 ;
F_16 ( V_15 , L_3 ,
V_2 -> V_5 ,
V_2 -> V_5 & V_6 ? L_4 : L_5 ,
V_2 -> V_5 & V_7 ? L_6 : L_7 ) ;
if ( ! F_4 ( V_2 ) ) {
F_16 ( V_15 , L_8 ) ;
return;
}
if ( V_2 -> V_21 == V_23 ) {
F_16 ( V_15 , L_9 ) ;
return;
}
V_35 = F_14 ( V_2 ) ;
F_16 ( V_15 , L_10 , ( void * ) V_35 , ( void * ) V_35 ) ;
if ( V_2 -> V_27 )
F_16 ( V_15 , L_11 , V_2 -> V_28 ) ;
if ( V_2 -> V_30 )
F_16 ( V_15 , L_12 ,
V_2 -> V_31 ,
V_2 -> V_31 & V_41 ?
L_13 : L_14 ,
V_2 -> V_31 & V_42 ? L_15 :
( V_2 -> V_31 & V_43 ?
L_16 : L_17 ) ,
V_2 -> V_31 & V_44 ? 64 : 32 ,
V_2 -> V_31 & ( T_1 ) V_45 ) ;
}
static void F_18 ( void * V_46 )
{
struct V_1 * V_2 = V_46 ;
T_1 V_47 , V_48 ;
T_1 V_49 , V_50 ;
F_11 ( V_2 -> V_3 ) ;
V_49 = F_6 ( V_2 -> V_3 + V_51 ) ;
V_50 = F_6 ( V_2 -> V_3 + V_52 ) ;
F_13 ( V_2 -> V_3 ) ;
V_47 = V_49 & V_53 ;
V_48 = V_50 & V_54 ;
V_2 -> V_55 = false ;
V_2 -> V_27 = false ;
V_2 -> V_30 = false ;
V_2 -> V_36 = false ;
switch ( V_47 ) {
case V_56 :
V_2 -> V_30 = true ;
case V_57 :
V_2 -> V_27 = true ;
case V_58 :
V_2 -> V_55 =
( ( F_12 ( V_24 ) && V_48 != 0 ) ||
( V_48 != V_59 ) ) ;
V_2 -> V_36 =
( V_48 == V_60 ) ;
break;
default:
break;
}
}
static int F_19 ( struct V_61 * V_62 ,
unsigned long V_63 , void * V_64 )
{
int V_17 ;
struct V_1 * V_2 ;
F_20 ( & V_65 ) ;
if ( ! V_66 )
goto V_67;
F_21 ( L_18 ) ;
F_22 (cpu) {
V_2 = F_23 ( V_1 , V_17 ) ;
if ( ! V_2 )
continue;
F_16 ( V_2 -> V_15 , L_19 , V_2 -> V_17 ) ;
F_10 ( V_2 ) ;
F_17 ( V_2 ) ;
}
V_67:
F_24 ( & V_65 ) ;
return 0 ;
}
static int F_25 ( void )
{
struct V_1 * V_2 ;
int V_17 , V_68 = 0 ;
T_2 V_69 ;
F_26 ( & V_69 ) ;
F_22 (cpu) {
V_2 = F_23 ( V_1 , V_17 ) ;
if ( ! V_2 )
continue;
V_68 = F_27 ( V_2 -> V_15 ) ;
if ( V_68 < 0 )
goto V_70;
else
F_28 ( V_17 , & V_69 ) ;
}
return 0 ;
V_70:
F_29 (cpu, &mask) {
V_2 = F_23 ( V_1 , V_17 ) ;
F_30 ( V_2 -> V_15 ) ;
}
return V_68 ;
}
static int F_31 ( void )
{
struct V_1 * V_2 ;
int V_17 , V_68 , V_70 = 0 ;
F_22 (cpu) {
V_2 = F_23 ( V_1 , V_17 ) ;
if ( ! V_2 )
continue;
V_68 = F_32 ( V_2 -> V_15 ) ;
if ( V_68 < 0 )
V_70 = V_68 ;
}
return V_70 ;
}
static T_3 F_33 ( struct V_71 * V_72 ,
const char T_4 * V_73 , T_5 V_74 , T_6 * V_75 )
{
T_7 V_76 ;
int V_68 ;
V_68 = F_34 ( V_73 , V_74 , 2 , & V_76 ) ;
if ( V_68 )
return V_68 ;
F_20 ( & V_65 ) ;
if ( V_76 == V_66 )
goto V_20;
if ( V_76 )
V_68 = F_25 () ;
else
V_68 = F_31 () ;
if ( V_68 ) {
F_35 ( L_20 ,
V_16 , V_76 ? L_21 : L_22 , V_68 ) ;
goto V_70;
}
V_66 = V_76 ;
V_20:
V_68 = V_74 ;
V_70:
F_24 ( & V_65 ) ;
return V_68 ;
}
static T_3 F_36 ( struct V_71 * V_72 ,
char T_4 * V_77 , T_5 V_74 , T_6 * V_75 )
{
T_3 V_68 ;
char V_73 [ 3 ] ;
F_20 ( & V_65 ) ;
snprintf ( V_73 , sizeof( V_73 ) , L_23 , V_66 ) ;
F_24 ( & V_65 ) ;
V_68 = F_37 ( V_77 , V_74 , V_75 , V_73 , sizeof( V_73 ) ) ;
return V_68 ;
}
static int F_38 ( void )
{
struct V_78 * V_71 ;
int V_68 ;
V_79 = F_39 ( L_24 , NULL ) ;
if ( ! V_79 ) {
F_35 ( L_25 , V_16 ) ;
return - V_80 ;
}
V_71 = F_40 ( L_21 , 0644 , V_79 , NULL ,
& V_81 ) ;
if ( ! V_71 ) {
F_35 ( L_26 , V_16 ) ;
V_68 = - V_80 ;
goto V_70;
}
V_68 = F_41 ( & V_82 ,
& V_83 ) ;
if ( V_68 ) {
F_35 ( L_27 ,
V_16 , V_68 ) ;
goto V_70;
}
return 0 ;
V_70:
F_42 ( V_79 ) ;
return V_68 ;
}
static void F_43 ( void )
{
F_44 ( & V_82 ,
& V_83 ) ;
F_42 ( V_79 ) ;
}
static int F_45 ( struct V_84 * V_85 , const struct V_86 * V_87 )
{
void T_8 * V_3 ;
struct V_40 * V_15 = & V_85 -> V_15 ;
struct V_1 * V_2 ;
struct V_88 * V_89 = & V_85 -> V_89 ;
struct V_90 * V_91 = V_85 -> V_15 . V_92 ;
int V_68 ;
V_2 = F_46 ( V_15 , sizeof( * V_2 ) , V_93 ) ;
if ( ! V_2 )
return - V_80 ;
V_2 -> V_17 = V_91 ? F_47 ( V_91 ) : 0 ;
if ( F_23 ( V_1 , V_2 -> V_17 ) ) {
F_8 ( V_15 , L_28 ,
V_2 -> V_17 ) ;
return - V_94 ;
}
V_2 -> V_15 = & V_85 -> V_15 ;
F_48 ( V_85 , V_2 ) ;
V_3 = F_49 ( V_15 , V_89 ) ;
if ( F_50 ( V_3 ) )
return F_51 ( V_3 ) ;
V_2 -> V_3 = V_3 ;
F_52 () ;
F_23 ( V_1 , V_2 -> V_17 ) = V_2 ;
V_68 = F_53 ( V_2 -> V_17 , F_18 ,
V_2 , 1 ) ;
F_54 () ;
if ( V_68 ) {
F_8 ( V_15 , L_29 , V_2 -> V_17 ) ;
goto V_70;
}
if ( ! V_2 -> V_55 ) {
F_8 ( V_15 , L_30 ,
V_2 -> V_17 ) ;
V_68 = - V_95 ;
goto V_70;
}
if ( ! V_96 ++ ) {
V_68 = F_38 () ;
if ( V_68 )
goto V_97;
}
F_20 ( & V_65 ) ;
if ( ! V_66 )
F_32 ( V_15 ) ;
F_24 ( & V_65 ) ;
F_55 ( V_15 , L_31 , V_2 -> V_17 ) ;
return 0 ;
V_97:
V_96 -- ;
V_70:
F_23 ( V_1 , V_2 -> V_17 ) = NULL ;
return V_68 ;
}
static int F_56 ( struct V_84 * V_85 )
{
struct V_40 * V_15 = & V_85 -> V_15 ;
struct V_1 * V_2 = F_57 ( V_85 ) ;
F_23 ( V_1 , V_2 -> V_17 ) = NULL ;
F_20 ( & V_65 ) ;
if ( V_66 )
F_32 ( V_15 ) ;
F_24 ( & V_65 ) ;
if ( ! -- V_96 )
F_43 () ;
return 0 ;
}
