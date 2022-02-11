static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_5 = F_3 ( V_5 , V_2 -> V_6 . V_7 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned int V_8 ;
int V_3 ;
V_8 = F_5 ( & V_2 -> V_8 ) ;
V_3 = V_8 % F_6 ( V_2 -> V_6 . V_7 ) ;
return F_1 ( V_2 , V_3 ) ;
}
static void F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
F_8 ( V_15 ) ;
F_9 () ;
V_12 = F_10 ( V_10 ,
struct V_11 , V_16 ) ;
V_2 = V_12 -> V_2 ;
V_14 = V_2 -> V_14 ;
F_11 ( & V_12 -> V_17 . V_18 ) ;
F_12 ( & V_12 -> V_17 . V_19 , & V_15 ) ;
F_13 ( & V_12 -> V_17 . V_18 ) ;
while ( ! F_14 ( & V_15 ) ) {
struct V_20 * V_21 ;
V_21 = F_15 ( V_15 . V_22 ,
struct V_20 , V_19 ) ;
F_16 ( & V_21 -> V_19 ) ;
V_21 -> V_17 ( V_21 ) ;
}
F_17 () ;
}
int F_18 ( struct V_13 * V_14 ,
struct V_20 * V_21 , int V_23 )
{
int V_5 , V_24 ;
struct V_11 * V_25 ;
struct V_1 * V_2 ;
F_19 () ;
V_2 = F_20 ( V_14 -> V_2 ) ;
V_24 = - V_26 ;
if ( ! ( V_14 -> V_27 & V_28 ) || V_14 -> V_27 & V_29 )
goto V_30;
if ( ! F_21 ( V_23 , V_2 -> V_6 . V_31 ) )
goto V_30;
V_24 = - V_32 ;
if ( ( V_14 -> V_27 & V_33 ) )
goto V_30;
if ( F_22 ( & V_2 -> V_34 ) >= V_35 )
goto V_30;
V_24 = 0 ;
F_23 ( & V_2 -> V_34 ) ;
V_21 -> V_2 = V_2 ;
V_21 -> V_23 = V_23 ;
V_5 = F_4 ( V_2 ) ;
V_25 = F_24 ( V_2 -> V_12 , V_5 ) ;
F_11 ( & V_25 -> V_17 . V_18 ) ;
F_25 ( & V_21 -> V_19 , & V_25 -> V_17 . V_19 ) ;
F_13 ( & V_25 -> V_17 . V_18 ) ;
F_26 ( V_5 , V_14 -> V_36 , & V_25 -> V_16 ) ;
V_30:
F_27 () ;
return V_24 ;
}
static struct V_20 * F_28 ( struct V_1 * V_2 )
{
int V_4 , V_37 ;
unsigned int V_38 , V_39 ;
struct V_11 * V_40 ;
struct V_20 * V_21 ;
struct V_41 * V_42 ;
V_37 = F_6 ( V_2 -> V_6 . V_7 ) ;
V_38 = V_2 -> V_43 ;
V_39 = V_38 % V_37 ;
V_4 = F_1 ( V_2 , V_39 ) ;
V_40 = F_24 ( V_2 -> V_12 , V_4 ) ;
V_21 = NULL ;
V_42 = & V_40 -> V_42 ;
if ( ! F_14 ( & V_42 -> V_19 ) ) {
V_21 = F_15 ( V_42 -> V_19 . V_22 ,
struct V_20 , V_19 ) ;
F_11 ( & V_42 -> V_18 ) ;
F_16 ( & V_21 -> V_19 ) ;
F_29 ( & V_2 -> V_44 ) ;
F_13 ( & V_42 -> V_18 ) ;
V_2 -> V_43 ++ ;
goto V_30;
}
if ( F_30 ( V_2 -> V_12 -> V_3 ) == V_40 -> V_3 ) {
V_21 = F_31 ( - V_45 ) ;
goto V_30;
}
V_21 = F_31 ( - V_46 ) ;
V_30:
return V_21 ;
}
static void F_32 ( struct V_1 * V_2 )
{
int V_23 ;
struct V_20 * V_21 ;
struct V_47 * V_48 ;
struct V_13 * V_14 = V_2 -> V_14 ;
if ( ! F_33 ( & V_2 -> V_18 ) )
return;
while ( 1 ) {
V_21 = F_28 ( V_2 ) ;
if ( ! V_21 || F_34 ( V_21 ) == - V_46 )
break;
if ( F_34 ( V_21 ) == - V_45 ) {
F_35 ( & V_2 -> V_49 ) ;
F_36 ( & V_2 -> V_18 ) ;
return;
}
V_23 = V_21 -> V_23 ;
V_48 = F_24 ( V_2 -> V_48 , V_23 ) ;
F_11 ( & V_48 -> V_50 . V_18 ) ;
F_25 ( & V_21 -> V_19 , & V_48 -> V_50 . V_19 ) ;
F_13 ( & V_48 -> V_50 . V_18 ) ;
F_26 ( V_23 , V_14 -> V_36 , & V_48 -> V_16 ) ;
}
F_36 ( & V_2 -> V_18 ) ;
if ( F_22 ( & V_2 -> V_44 )
&& ! ( V_14 -> V_27 & V_33 ) )
F_37 ( & V_2 -> V_49 , V_51 + V_52 ) ;
else
F_35 ( & V_2 -> V_49 ) ;
return;
}
static void F_38 ( unsigned long V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
F_32 ( V_2 ) ;
}
static void F_39 ( struct V_9 * V_54 )
{
struct V_47 * V_48 ;
struct V_1 * V_2 ;
F_8 ( V_15 ) ;
F_9 () ;
V_48 = F_10 ( V_54 , struct V_47 , V_16 ) ;
V_2 = V_48 -> V_2 ;
F_11 ( & V_48 -> V_50 . V_18 ) ;
F_12 ( & V_48 -> V_50 . V_19 , & V_15 ) ;
F_13 ( & V_48 -> V_50 . V_18 ) ;
while ( ! F_14 ( & V_15 ) ) {
struct V_20 * V_21 ;
V_21 = F_15 ( V_15 . V_22 ,
struct V_20 , V_19 ) ;
F_16 ( & V_21 -> V_19 ) ;
V_21 -> V_50 ( V_21 ) ;
F_29 ( & V_2 -> V_34 ) ;
}
F_17 () ;
}
void F_40 ( struct V_20 * V_21 )
{
int V_4 ;
struct V_11 * V_12 ;
struct V_1 * V_2 ;
V_2 = V_21 -> V_2 ;
V_4 = F_41 () ;
V_12 = F_24 ( V_2 -> V_12 , V_4 ) ;
F_11 ( & V_12 -> V_42 . V_18 ) ;
F_23 ( & V_2 -> V_44 ) ;
F_25 ( & V_21 -> V_19 , & V_12 -> V_42 . V_19 ) ;
F_13 ( & V_12 -> V_42 . V_18 ) ;
F_42 () ;
F_32 ( V_2 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
const struct V_6 * V_55 ,
const struct V_6 * V_56 )
{
if ( ! F_44 ( & V_2 -> V_6 . V_7 , V_57 ) )
return - V_58 ;
F_45 ( V_2 -> V_6 . V_7 , V_55 , V_59 ) ;
if ( ! F_44 ( & V_2 -> V_6 . V_31 , V_57 ) ) {
F_46 ( V_2 -> V_6 . V_31 ) ;
return - V_58 ;
}
F_45 ( V_2 -> V_6 . V_31 , V_56 , V_59 ) ;
return 0 ;
}
static void F_47 ( struct V_41 * V_60 )
{
F_48 ( & V_60 -> V_19 ) ;
F_49 ( & V_60 -> V_18 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_47 * V_48 ;
F_51 (cpu, pd->cpumask.cbcpu) {
V_48 = F_24 ( V_2 -> V_48 , V_4 ) ;
V_48 -> V_2 = V_2 ;
F_47 ( & V_48 -> V_50 ) ;
F_52 ( & V_48 -> V_16 , F_39 ) ;
}
}
static void F_53 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
struct V_11 * V_12 ;
V_3 = 0 ;
F_51 (cpu, pd->cpumask.pcpu) {
V_12 = F_24 ( V_2 -> V_12 , V_4 ) ;
V_12 -> V_2 = V_2 ;
V_12 -> V_3 = V_3 ;
V_3 ++ ;
F_47 ( & V_12 -> V_42 ) ;
F_47 ( & V_12 -> V_17 ) ;
F_52 ( & V_12 -> V_16 , F_7 ) ;
F_54 ( & V_12 -> V_61 , 0 ) ;
}
}
static struct V_1 * F_55 ( struct V_13 * V_14 ,
const struct V_6 * V_55 ,
const struct V_6 * V_56 )
{
struct V_1 * V_2 ;
V_2 = F_56 ( sizeof( struct V_1 ) , V_57 ) ;
if ( ! V_2 )
goto V_24;
V_2 -> V_12 = F_57 ( struct V_11 ) ;
if ( ! V_2 -> V_12 )
goto V_62;
V_2 -> V_48 = F_57 ( struct V_47 ) ;
if ( ! V_2 -> V_48 )
goto V_63;
if ( F_43 ( V_2 , V_55 , V_56 ) < 0 )
goto V_64;
F_53 ( V_2 ) ;
F_50 ( V_2 ) ;
F_58 ( & V_2 -> V_49 , F_38 , ( unsigned long ) V_2 ) ;
F_54 ( & V_2 -> V_8 , - 1 ) ;
F_54 ( & V_2 -> V_44 , 0 ) ;
F_54 ( & V_2 -> V_34 , 0 ) ;
V_2 -> V_14 = V_14 ;
F_49 ( & V_2 -> V_18 ) ;
return V_2 ;
V_64:
F_59 ( V_2 -> V_48 ) ;
V_63:
F_59 ( V_2 -> V_12 ) ;
V_62:
F_60 ( V_2 ) ;
V_24:
return NULL ;
}
static void F_61 ( struct V_1 * V_2 )
{
F_46 ( V_2 -> V_6 . V_7 ) ;
F_46 ( V_2 -> V_6 . V_31 ) ;
F_59 ( V_2 -> V_12 ) ;
F_59 ( V_2 -> V_48 ) ;
F_60 ( V_2 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_11 * V_12 ;
struct V_47 * V_48 ;
F_51 (cpu, pd->cpumask.pcpu) {
V_12 = F_24 ( V_2 -> V_12 , V_4 ) ;
F_63 ( & V_12 -> V_16 ) ;
}
F_64 ( & V_2 -> V_49 ) ;
if ( F_22 ( & V_2 -> V_44 ) )
F_32 ( V_2 ) ;
F_51 (cpu, pd->cpumask.cbcpu) {
V_48 = F_24 ( V_2 -> V_48 , V_4 ) ;
F_63 ( & V_48 -> V_16 ) ;
}
F_65 ( F_22 ( & V_2 -> V_34 ) != 0 ) ;
}
static void F_66 ( struct V_13 * V_14 )
{
V_14 -> V_27 |= V_28 ;
}
static void F_67 ( struct V_13 * V_14 )
{
if ( ! ( V_14 -> V_27 & V_28 ) )
return;
V_14 -> V_27 &= ~ V_28 ;
F_68 () ;
F_69 () ;
F_62 ( V_14 -> V_2 ) ;
F_70 () ;
}
static void F_71 ( struct V_13 * V_14 ,
struct V_1 * V_65 )
{
struct V_1 * V_66 = V_14 -> V_2 ;
int V_67 = 0 ;
V_14 -> V_27 |= V_33 ;
F_72 ( V_14 -> V_2 , V_65 ) ;
F_68 () ;
if ( ! F_73 ( V_66 -> V_6 . V_7 , V_65 -> V_6 . V_7 ) )
V_67 |= V_68 ;
if ( ! F_73 ( V_66 -> V_6 . V_31 , V_65 -> V_6 . V_31 ) )
V_67 |= V_69 ;
F_62 ( V_66 ) ;
F_61 ( V_66 ) ;
if ( V_67 )
F_74 ( & V_14 -> V_70 ,
V_67 ,
& V_65 -> V_6 ) ;
V_14 -> V_27 &= ~ V_33 ;
}
int F_75 ( struct V_13 * V_14 ,
struct V_71 * V_72 )
{
return F_76 ( & V_14 -> V_70 ,
V_72 ) ;
}
int F_77 ( struct V_13 * V_14 ,
struct V_71 * V_72 )
{
return F_78 (
& V_14 -> V_70 ,
V_72 ) ;
}
static bool F_79 ( struct V_13 * V_14 ,
const struct V_6 * V_6 )
{
if ( ! F_80 ( V_6 , V_59 ) ) {
V_14 -> V_27 |= V_29 ;
return false ;
}
V_14 -> V_27 &= ~ V_29 ;
return true ;
}
static int F_81 ( struct V_13 * V_14 ,
T_1 V_55 ,
T_1 V_56 )
{
int V_73 ;
struct V_1 * V_2 ;
V_73 = F_79 ( V_14 , V_55 ) ;
if ( ! V_73 ) {
F_67 ( V_14 ) ;
goto V_74;
}
V_73 = F_79 ( V_14 , V_56 ) ;
if ( ! V_73 )
F_67 ( V_14 ) ;
V_74:
V_2 = F_55 ( V_14 , V_55 , V_56 ) ;
if ( ! V_2 )
return - V_58 ;
F_82 ( V_14 -> V_6 . V_7 , V_55 ) ;
F_82 ( V_14 -> V_6 . V_31 , V_56 ) ;
F_71 ( V_14 , V_2 ) ;
if ( V_73 )
F_66 ( V_14 ) ;
return 0 ;
}
int F_83 ( struct V_13 * V_14 , int V_75 ,
T_1 V_6 )
{
struct V_6 * V_76 , * V_77 ;
int V_24 = - V_26 ;
F_84 ( & V_14 -> V_18 ) ;
F_69 () ;
switch ( V_75 ) {
case V_68 :
V_76 = V_14 -> V_6 . V_31 ;
V_77 = V_6 ;
break;
case V_69 :
V_77 = V_14 -> V_6 . V_7 ;
V_76 = V_6 ;
break;
default:
goto V_30;
}
V_24 = F_81 ( V_14 , V_77 , V_76 ) ;
V_30:
F_70 () ;
F_85 ( & V_14 -> V_18 ) ;
return V_24 ;
}
int F_86 ( struct V_13 * V_14 )
{
int V_24 = 0 ;
F_84 ( & V_14 -> V_18 ) ;
if ( V_14 -> V_27 & V_29 )
V_24 = - V_26 ;
F_66 ( V_14 ) ;
F_85 ( & V_14 -> V_18 ) ;
return V_24 ;
}
void F_87 ( struct V_13 * V_14 )
{
F_84 ( & V_14 -> V_18 ) ;
F_67 ( V_14 ) ;
F_85 ( & V_14 -> V_18 ) ;
}
static int F_88 ( struct V_13 * V_14 , int V_4 )
{
struct V_1 * V_2 ;
if ( F_21 ( V_4 , V_59 ) ) {
V_2 = F_55 ( V_14 , V_14 -> V_6 . V_7 ,
V_14 -> V_6 . V_31 ) ;
if ( ! V_2 )
return - V_58 ;
F_71 ( V_14 , V_2 ) ;
if ( F_79 ( V_14 , V_14 -> V_6 . V_7 ) &&
F_79 ( V_14 , V_14 -> V_6 . V_31 ) )
F_66 ( V_14 ) ;
}
return 0 ;
}
static int F_89 ( struct V_13 * V_14 , int V_4 )
{
struct V_1 * V_2 = NULL ;
if ( F_21 ( V_4 , V_59 ) ) {
if ( ! F_79 ( V_14 , V_14 -> V_6 . V_7 ) ||
! F_79 ( V_14 , V_14 -> V_6 . V_31 ) )
F_67 ( V_14 ) ;
V_2 = F_55 ( V_14 , V_14 -> V_6 . V_7 ,
V_14 -> V_6 . V_31 ) ;
if ( ! V_2 )
return - V_58 ;
F_71 ( V_14 , V_2 ) ;
F_90 ( V_4 , V_2 -> V_6 . V_31 ) ;
F_90 ( V_4 , V_2 -> V_6 . V_7 ) ;
}
return 0 ;
}
int F_91 ( struct V_13 * V_14 , int V_4 , int V_78 )
{
int V_24 ;
if ( ! ( V_78 & ( V_69 | V_68 ) ) )
return - V_26 ;
F_84 ( & V_14 -> V_18 ) ;
F_69 () ;
if ( V_78 & V_69 )
F_90 ( V_4 , V_14 -> V_6 . V_31 ) ;
if ( V_78 & V_68 )
F_90 ( V_4 , V_14 -> V_6 . V_7 ) ;
V_24 = F_89 ( V_14 , V_4 ) ;
F_70 () ;
F_85 ( & V_14 -> V_18 ) ;
return V_24 ;
}
static inline int F_92 ( struct V_13 * V_14 , int V_4 )
{
return F_21 ( V_4 , V_14 -> V_6 . V_7 ) ||
F_21 ( V_4 , V_14 -> V_6 . V_31 ) ;
}
static int F_93 ( unsigned int V_4 , struct V_79 * V_80 )
{
struct V_13 * V_14 ;
int V_81 ;
V_14 = F_94 ( V_80 , struct V_13 , V_80 ) ;
if ( ! F_92 ( V_14 , V_4 ) )
return 0 ;
F_84 ( & V_14 -> V_18 ) ;
V_81 = F_88 ( V_14 , V_4 ) ;
F_85 ( & V_14 -> V_18 ) ;
return V_81 ;
}
static int F_95 ( unsigned int V_4 , struct V_79 * V_80 )
{
struct V_13 * V_14 ;
int V_81 ;
V_14 = F_94 ( V_80 , struct V_13 , V_80 ) ;
if ( ! F_92 ( V_14 , V_4 ) )
return 0 ;
F_84 ( & V_14 -> V_18 ) ;
V_81 = F_89 ( V_14 , V_4 ) ;
F_85 ( & V_14 -> V_18 ) ;
return V_81 ;
}
static void F_96 ( struct V_13 * V_14 )
{
#ifdef F_97
F_98 ( V_82 , & V_14 -> V_80 ) ;
#endif
F_87 ( V_14 ) ;
F_61 ( V_14 -> V_2 ) ;
F_46 ( V_14 -> V_6 . V_7 ) ;
F_46 ( V_14 -> V_6 . V_31 ) ;
F_60 ( V_14 ) ;
}
static void F_99 ( struct V_83 * V_84 )
{
struct V_13 * V_14 = F_100 ( V_84 ) ;
F_96 ( V_14 ) ;
}
static T_2 F_101 ( struct V_13 * V_14 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_6 * V_6 ;
T_2 V_88 ;
F_84 ( & V_14 -> V_18 ) ;
if ( ! strcmp ( V_86 -> V_89 , L_1 ) )
V_6 = V_14 -> V_6 . V_31 ;
else
V_6 = V_14 -> V_6 . V_7 ;
V_88 = snprintf ( V_87 , V_90 , L_2 ,
V_91 , F_102 ( V_6 ) ) ;
F_85 ( & V_14 -> V_18 ) ;
return V_88 < V_90 ? V_88 : - V_26 ;
}
static T_2 F_103 ( struct V_13 * V_14 ,
struct V_85 * V_86 ,
const char * V_87 , T_3 V_92 )
{
T_1 V_93 ;
T_2 V_81 ;
int V_94 ;
if ( ! F_44 ( & V_93 , V_57 ) )
return - V_58 ;
V_81 = F_104 ( V_87 , V_92 , F_102 ( V_93 ) ,
V_95 ) ;
if ( V_81 < 0 )
goto V_30;
V_94 = ! strcmp ( V_86 -> V_89 , L_1 ) ?
V_69 : V_68 ;
V_81 = F_83 ( V_14 , V_94 , V_93 ) ;
if ( ! V_81 )
V_81 = V_92 ;
V_30:
F_46 ( V_93 ) ;
return V_81 ;
}
static T_2 F_105 ( struct V_83 * V_84 ,
struct V_85 * V_86 , char * V_87 )
{
struct V_13 * V_14 ;
struct V_96 * V_97 ;
T_2 V_81 = - V_98 ;
V_14 = F_100 ( V_84 ) ;
V_97 = F_106 ( V_86 ) ;
if ( V_97 -> V_99 )
V_81 = V_97 -> V_99 ( V_14 , V_86 , V_87 ) ;
return V_81 ;
}
static T_2 F_107 ( struct V_83 * V_84 , struct V_85 * V_86 ,
const char * V_87 , T_3 V_92 )
{
struct V_13 * V_14 ;
struct V_96 * V_97 ;
T_2 V_81 = - V_98 ;
V_14 = F_100 ( V_84 ) ;
V_97 = F_106 ( V_86 ) ;
if ( V_97 -> V_99 )
V_81 = V_97 -> V_100 ( V_14 , V_86 , V_87 , V_92 ) ;
return V_81 ;
}
struct V_13 * F_108 ( struct V_101 * V_36 )
{
return F_109 ( V_36 , V_102 , V_102 ) ;
}
struct V_13 * F_109 ( struct V_101 * V_36 ,
const struct V_6 * V_55 ,
const struct V_6 * V_56 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 = NULL ;
V_14 = F_56 ( sizeof( struct V_13 ) , V_57 ) ;
if ( ! V_14 )
goto V_24;
F_69 () ;
if ( ! F_44 ( & V_14 -> V_6 . V_7 , V_57 ) )
goto V_103;
if ( ! F_44 ( & V_14 -> V_6 . V_31 , V_57 ) ) {
F_46 ( V_14 -> V_6 . V_7 ) ;
goto V_103;
}
if ( ! F_79 ( V_14 , V_55 ) ||
! F_79 ( V_14 , V_56 ) )
goto V_104;
V_2 = F_55 ( V_14 , V_55 , V_56 ) ;
if ( ! V_2 )
goto V_104;
F_72 ( V_14 -> V_2 , V_2 ) ;
V_14 -> V_36 = V_36 ;
F_82 ( V_14 -> V_6 . V_7 , V_55 ) ;
F_82 ( V_14 -> V_6 . V_31 , V_56 ) ;
V_14 -> V_27 = 0 ;
F_70 () ;
F_110 ( & V_14 -> V_70 ) ;
F_111 ( & V_14 -> V_84 , & V_105 ) ;
F_112 ( & V_14 -> V_18 ) ;
#ifdef F_97
F_113 ( V_82 , & V_14 -> V_80 ) ;
#endif
return V_14 ;
V_104:
F_46 ( V_14 -> V_6 . V_7 ) ;
F_46 ( V_14 -> V_6 . V_31 ) ;
V_103:
F_60 ( V_14 ) ;
F_70 () ;
V_24:
return NULL ;
}
void F_114 ( struct V_13 * V_14 )
{
F_115 ( & V_14 -> V_84 ) ;
}
static T_4 int F_116 ( void )
{
int V_81 ;
V_81 = F_117 ( V_106 , L_3 ,
F_93 ,
F_95 ) ;
if ( V_81 < 0 )
return V_81 ;
V_82 = V_81 ;
return 0 ;
}
static T_5 void F_118 ( void )
{
F_119 ( V_82 ) ;
}
