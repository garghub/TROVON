static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_5 = F_3 ( V_5 , V_2 -> V_6 . V_7 ) ;
return V_5 ;
}
static int F_4 ( struct V_8 * V_9 )
{
int V_3 ;
struct V_1 * V_2 ;
V_2 = V_9 -> V_2 ;
V_3 = V_9 -> V_10 % F_5 ( V_2 -> V_6 . V_7 ) ;
return F_1 ( V_2 , V_3 ) ;
}
static void F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
F_7 ( V_17 ) ;
F_8 () ;
V_14 = F_9 ( V_12 ,
struct V_13 , V_18 ) ;
V_2 = V_14 -> V_2 ;
V_16 = V_2 -> V_16 ;
F_10 ( & V_14 -> V_19 . V_20 ) ;
F_11 ( & V_14 -> V_19 . V_21 , & V_17 ) ;
F_12 ( & V_14 -> V_19 . V_20 ) ;
while ( ! F_13 ( & V_17 ) ) {
struct V_8 * V_9 ;
V_9 = F_14 ( V_17 . V_22 ,
struct V_8 , V_21 ) ;
F_15 ( & V_9 -> V_21 ) ;
V_9 -> V_19 ( V_9 ) ;
}
F_16 () ;
}
int F_17 ( struct V_15 * V_16 ,
struct V_8 * V_9 , int V_23 )
{
int V_5 , V_24 ;
struct V_13 * V_25 ;
struct V_1 * V_2 ;
F_18 () ;
V_2 = F_19 ( V_16 -> V_2 ) ;
V_24 = - V_26 ;
if ( ! ( V_16 -> V_27 & V_28 ) || V_16 -> V_27 & V_29 )
goto V_30;
if ( ! F_20 ( V_23 , V_2 -> V_6 . V_31 ) )
goto V_30;
V_24 = - V_32 ;
if ( ( V_16 -> V_27 & V_33 ) )
goto V_30;
if ( F_21 ( & V_2 -> V_34 ) >= V_35 )
goto V_30;
V_24 = 0 ;
F_22 ( & V_2 -> V_34 ) ;
V_9 -> V_2 = V_2 ;
V_9 -> V_23 = V_23 ;
if ( F_23 ( F_21 ( & V_2 -> V_10 ) == V_2 -> V_36 ) )
F_24 ( & V_2 -> V_10 , - 1 ) ;
V_9 -> V_10 = F_25 ( & V_2 -> V_10 ) ;
V_5 = F_4 ( V_9 ) ;
V_25 = F_26 ( V_2 -> V_14 , V_5 ) ;
F_10 ( & V_25 -> V_19 . V_20 ) ;
F_27 ( & V_9 -> V_21 , & V_25 -> V_19 . V_21 ) ;
F_12 ( & V_25 -> V_19 . V_20 ) ;
F_28 ( V_5 , V_16 -> V_37 , & V_25 -> V_18 ) ;
V_30:
F_29 () ;
return V_24 ;
}
static struct V_8 * F_30 ( struct V_1 * V_2 )
{
int V_4 , V_38 ;
int V_39 , V_40 ;
struct V_13 * V_25 , * V_41 ;
struct V_8 * V_9 ;
struct V_42 * V_43 ;
V_38 = F_5 ( V_2 -> V_6 . V_7 ) ;
V_39 = V_2 -> V_44 ;
V_40 = V_39 % V_38 ;
V_4 = F_1 ( V_2 , V_40 ) ;
V_41 = F_26 ( V_2 -> V_14 , V_4 ) ;
if ( F_23 ( V_39 > V_2 -> V_36 ) ) {
V_39 = V_39 - V_2 -> V_36 - 1 ;
V_40 = V_39 % V_38 ;
V_4 = F_1 ( V_2 , V_40 ) ;
V_41 = F_26 ( V_2 -> V_14 , V_4 ) ;
V_2 -> V_44 = 0 ;
}
V_9 = NULL ;
V_43 = & V_41 -> V_43 ;
if ( ! F_13 ( & V_43 -> V_21 ) ) {
V_9 = F_14 ( V_43 -> V_21 . V_22 ,
struct V_8 , V_21 ) ;
F_31 ( V_39 != V_9 -> V_10 ) ;
F_10 ( & V_43 -> V_20 ) ;
F_15 ( & V_9 -> V_21 ) ;
F_32 ( & V_2 -> V_45 ) ;
F_12 ( & V_43 -> V_20 ) ;
V_2 -> V_44 ++ ;
goto V_30;
}
V_25 = F_26 ( V_2 -> V_14 , F_33 () ) ;
if ( V_25 -> V_3 == V_41 -> V_3 ) {
V_9 = F_34 ( - V_46 ) ;
goto V_30;
}
V_9 = F_34 ( - V_47 ) ;
V_30:
return V_9 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_48 * V_49 ;
struct V_15 * V_16 = V_2 -> V_16 ;
if ( ! F_36 ( & V_2 -> V_20 ) )
return;
while ( 1 ) {
V_9 = F_30 ( V_2 ) ;
if ( ! V_9 || F_37 ( V_9 ) == - V_47 )
break;
if ( F_37 ( V_9 ) == - V_46 ) {
F_38 ( & V_2 -> V_50 ) ;
F_39 ( & V_2 -> V_20 ) ;
return;
}
V_49 = F_26 ( V_2 -> V_49 , V_9 -> V_23 ) ;
F_10 ( & V_49 -> V_51 . V_20 ) ;
F_27 ( & V_9 -> V_21 , & V_49 -> V_51 . V_21 ) ;
F_12 ( & V_49 -> V_51 . V_20 ) ;
F_28 ( V_9 -> V_23 , V_16 -> V_37 , & V_49 -> V_18 ) ;
}
F_39 ( & V_2 -> V_20 ) ;
if ( F_21 ( & V_2 -> V_45 )
&& ! ( V_16 -> V_27 & V_33 ) )
F_40 ( & V_2 -> V_50 , V_52 + V_53 ) ;
else
F_38 ( & V_2 -> V_50 ) ;
return;
}
static void F_41 ( unsigned long V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
F_35 ( V_2 ) ;
}
static void F_42 ( struct V_11 * V_55 )
{
struct V_48 * V_49 ;
struct V_1 * V_2 ;
F_7 ( V_17 ) ;
F_8 () ;
V_49 = F_9 ( V_55 , struct V_48 , V_18 ) ;
V_2 = V_49 -> V_2 ;
F_10 ( & V_49 -> V_51 . V_20 ) ;
F_11 ( & V_49 -> V_51 . V_21 , & V_17 ) ;
F_12 ( & V_49 -> V_51 . V_20 ) ;
while ( ! F_13 ( & V_17 ) ) {
struct V_8 * V_9 ;
V_9 = F_14 ( V_17 . V_22 ,
struct V_8 , V_21 ) ;
F_15 ( & V_9 -> V_21 ) ;
V_9 -> V_51 ( V_9 ) ;
F_32 ( & V_2 -> V_34 ) ;
}
F_16 () ;
}
void F_43 ( struct V_8 * V_9 )
{
int V_4 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
V_2 = V_9 -> V_2 ;
V_4 = F_44 () ;
V_14 = F_26 ( V_2 -> V_14 , V_4 ) ;
F_10 ( & V_14 -> V_43 . V_20 ) ;
F_22 ( & V_2 -> V_45 ) ;
F_27 ( & V_9 -> V_21 , & V_14 -> V_43 . V_21 ) ;
F_12 ( & V_14 -> V_43 . V_20 ) ;
F_45 () ;
F_35 ( V_2 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
const struct V_6 * V_56 ,
const struct V_6 * V_57 )
{
if ( ! F_47 ( & V_2 -> V_6 . V_7 , V_58 ) )
return - V_59 ;
F_48 ( V_2 -> V_6 . V_7 , V_56 , V_60 ) ;
if ( ! F_47 ( & V_2 -> V_6 . V_31 , V_58 ) ) {
F_49 ( V_2 -> V_6 . V_31 ) ;
return - V_59 ;
}
F_48 ( V_2 -> V_6 . V_31 , V_57 , V_60 ) ;
return 0 ;
}
static void F_50 ( struct V_42 * V_61 )
{
F_51 ( & V_61 -> V_21 ) ;
F_52 ( & V_61 -> V_20 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_48 * V_49 ;
F_54 (cpu, pd->cpumask.cbcpu) {
V_49 = F_26 ( V_2 -> V_49 , V_4 ) ;
V_49 -> V_2 = V_2 ;
F_50 ( & V_49 -> V_51 ) ;
F_55 ( & V_49 -> V_18 , F_42 ) ;
}
}
static void F_56 ( struct V_1 * V_2 )
{
int V_3 , V_38 , V_4 ;
struct V_13 * V_14 ;
V_3 = 0 ;
F_54 (cpu, pd->cpumask.pcpu) {
V_14 = F_26 ( V_2 -> V_14 , V_4 ) ;
V_14 -> V_2 = V_2 ;
V_14 -> V_3 = V_3 ;
V_3 ++ ;
F_50 ( & V_14 -> V_43 ) ;
F_50 ( & V_14 -> V_19 ) ;
F_55 ( & V_14 -> V_18 , F_6 ) ;
F_24 ( & V_14 -> V_62 , 0 ) ;
}
V_38 = F_5 ( V_2 -> V_6 . V_7 ) ;
V_2 -> V_36 = V_38 ? ( V_63 / V_38 ) * V_38 - 1 : 0 ;
}
static struct V_1 * F_57 ( struct V_15 * V_16 ,
const struct V_6 * V_56 ,
const struct V_6 * V_57 )
{
struct V_1 * V_2 ;
V_2 = F_58 ( sizeof( struct V_1 ) , V_58 ) ;
if ( ! V_2 )
goto V_24;
V_2 -> V_14 = F_59 ( struct V_13 ) ;
if ( ! V_2 -> V_14 )
goto V_64;
V_2 -> V_49 = F_59 ( struct V_48 ) ;
if ( ! V_2 -> V_49 )
goto V_65;
if ( F_46 ( V_2 , V_56 , V_57 ) < 0 )
goto V_66;
F_56 ( V_2 ) ;
F_53 ( V_2 ) ;
F_60 ( & V_2 -> V_50 , F_41 , ( unsigned long ) V_2 ) ;
F_24 ( & V_2 -> V_10 , - 1 ) ;
F_24 ( & V_2 -> V_45 , 0 ) ;
F_24 ( & V_2 -> V_34 , 0 ) ;
V_2 -> V_16 = V_16 ;
F_52 ( & V_2 -> V_20 ) ;
return V_2 ;
V_66:
F_61 ( V_2 -> V_49 ) ;
V_65:
F_61 ( V_2 -> V_14 ) ;
V_64:
F_62 ( V_2 ) ;
V_24:
return NULL ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_49 ( V_2 -> V_6 . V_7 ) ;
F_49 ( V_2 -> V_6 . V_31 ) ;
F_61 ( V_2 -> V_14 ) ;
F_61 ( V_2 -> V_49 ) ;
F_62 ( V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_13 * V_14 ;
struct V_48 * V_49 ;
F_54 (cpu, pd->cpumask.pcpu) {
V_14 = F_26 ( V_2 -> V_14 , V_4 ) ;
F_65 ( & V_14 -> V_18 ) ;
}
F_66 ( & V_2 -> V_50 ) ;
if ( F_21 ( & V_2 -> V_45 ) )
F_35 ( V_2 ) ;
F_54 (cpu, pd->cpumask.cbcpu) {
V_49 = F_26 ( V_2 -> V_49 , V_4 ) ;
F_65 ( & V_49 -> V_18 ) ;
}
F_31 ( F_21 ( & V_2 -> V_34 ) != 0 ) ;
}
static void F_67 ( struct V_15 * V_16 )
{
V_16 -> V_27 |= V_28 ;
}
static void F_68 ( struct V_15 * V_16 )
{
if ( ! ( V_16 -> V_27 & V_28 ) )
return;
V_16 -> V_27 &= ~ V_28 ;
F_69 () ;
F_70 () ;
F_64 ( V_16 -> V_2 ) ;
F_71 () ;
}
static void F_72 ( struct V_15 * V_16 ,
struct V_1 * V_67 )
{
struct V_1 * V_68 = V_16 -> V_2 ;
int V_69 = 0 ;
V_16 -> V_27 |= V_33 ;
F_73 ( V_16 -> V_2 , V_67 ) ;
F_69 () ;
if ( ! F_74 ( V_68 -> V_6 . V_7 , V_67 -> V_6 . V_7 ) )
V_69 |= V_70 ;
if ( ! F_74 ( V_68 -> V_6 . V_31 , V_67 -> V_6 . V_31 ) )
V_69 |= V_71 ;
F_64 ( V_68 ) ;
F_63 ( V_68 ) ;
if ( V_69 )
F_75 ( & V_16 -> V_72 ,
V_69 ,
& V_67 -> V_6 ) ;
V_16 -> V_27 &= ~ V_33 ;
}
int F_76 ( struct V_15 * V_16 ,
struct V_73 * V_74 )
{
return F_77 ( & V_16 -> V_72 ,
V_74 ) ;
}
int F_78 ( struct V_15 * V_16 ,
struct V_73 * V_74 )
{
return F_79 (
& V_16 -> V_72 ,
V_74 ) ;
}
static bool F_80 ( struct V_15 * V_16 ,
const struct V_6 * V_6 )
{
if ( ! F_81 ( V_6 , V_60 ) ) {
V_16 -> V_27 |= V_29 ;
return false ;
}
V_16 -> V_27 &= ~ V_29 ;
return true ;
}
static int F_82 ( struct V_15 * V_16 ,
T_1 V_56 ,
T_1 V_57 )
{
int V_75 ;
struct V_1 * V_2 ;
V_75 = F_80 ( V_16 , V_56 ) ;
if ( ! V_75 ) {
F_68 ( V_16 ) ;
goto V_76;
}
V_75 = F_80 ( V_16 , V_57 ) ;
if ( ! V_75 )
F_68 ( V_16 ) ;
V_76:
V_2 = F_57 ( V_16 , V_56 , V_57 ) ;
if ( ! V_2 )
return - V_59 ;
F_83 ( V_16 -> V_6 . V_7 , V_56 ) ;
F_83 ( V_16 -> V_6 . V_31 , V_57 ) ;
F_72 ( V_16 , V_2 ) ;
if ( V_75 )
F_67 ( V_16 ) ;
return 0 ;
}
int F_84 ( struct V_15 * V_16 , T_1 V_56 ,
T_1 V_57 )
{
int V_24 ;
F_85 ( & V_16 -> V_20 ) ;
F_70 () ;
V_24 = F_82 ( V_16 , V_56 , V_57 ) ;
F_71 () ;
F_86 ( & V_16 -> V_20 ) ;
return V_24 ;
}
int F_87 ( struct V_15 * V_16 , int V_77 ,
T_1 V_6 )
{
struct V_6 * V_78 , * V_79 ;
int V_24 = - V_26 ;
F_85 ( & V_16 -> V_20 ) ;
F_70 () ;
switch ( V_77 ) {
case V_70 :
V_78 = V_16 -> V_6 . V_31 ;
V_79 = V_6 ;
break;
case V_71 :
V_79 = V_16 -> V_6 . V_7 ;
V_78 = V_6 ;
break;
default:
goto V_30;
}
V_24 = F_82 ( V_16 , V_79 , V_78 ) ;
V_30:
F_71 () ;
F_86 ( & V_16 -> V_20 ) ;
return V_24 ;
}
static int F_88 ( struct V_15 * V_16 , int V_4 )
{
struct V_1 * V_2 ;
if ( F_20 ( V_4 , V_60 ) ) {
V_2 = F_57 ( V_16 , V_16 -> V_6 . V_7 ,
V_16 -> V_6 . V_31 ) ;
if ( ! V_2 )
return - V_59 ;
F_72 ( V_16 , V_2 ) ;
if ( F_80 ( V_16 , V_16 -> V_6 . V_7 ) &&
F_80 ( V_16 , V_16 -> V_6 . V_31 ) )
F_67 ( V_16 ) ;
}
return 0 ;
}
int F_89 ( struct V_15 * V_16 , int V_4 , int V_80 )
{
int V_24 ;
if ( ! ( V_80 & ( V_71 | V_70 ) ) )
return - V_26 ;
F_85 ( & V_16 -> V_20 ) ;
F_70 () ;
if ( V_80 & V_71 )
F_90 ( V_4 , V_16 -> V_6 . V_31 ) ;
if ( V_80 & V_70 )
F_90 ( V_4 , V_16 -> V_6 . V_7 ) ;
V_24 = F_88 ( V_16 , V_4 ) ;
F_71 () ;
F_86 ( & V_16 -> V_20 ) ;
return V_24 ;
}
static int F_91 ( struct V_15 * V_16 , int V_4 )
{
struct V_1 * V_2 = NULL ;
if ( F_20 ( V_4 , V_81 ) ) {
if ( ! F_80 ( V_16 , V_16 -> V_6 . V_7 ) ||
! F_80 ( V_16 , V_16 -> V_6 . V_31 ) )
F_68 ( V_16 ) ;
V_2 = F_57 ( V_16 , V_16 -> V_6 . V_7 ,
V_16 -> V_6 . V_31 ) ;
if ( ! V_2 )
return - V_59 ;
F_72 ( V_16 , V_2 ) ;
}
return 0 ;
}
int F_92 ( struct V_15 * V_16 , int V_4 , int V_80 )
{
int V_24 ;
if ( ! ( V_80 & ( V_71 | V_70 ) ) )
return - V_26 ;
F_85 ( & V_16 -> V_20 ) ;
F_70 () ;
if ( V_80 & V_71 )
F_93 ( V_4 , V_16 -> V_6 . V_31 ) ;
if ( V_80 & V_70 )
F_93 ( V_4 , V_16 -> V_6 . V_7 ) ;
V_24 = F_91 ( V_16 , V_4 ) ;
F_71 () ;
F_86 ( & V_16 -> V_20 ) ;
return V_24 ;
}
int F_94 ( struct V_15 * V_16 )
{
int V_24 = 0 ;
F_85 ( & V_16 -> V_20 ) ;
if ( V_16 -> V_27 & V_29 )
V_24 = - V_26 ;
F_67 ( V_16 ) ;
F_86 ( & V_16 -> V_20 ) ;
return V_24 ;
}
void F_95 ( struct V_15 * V_16 )
{
F_85 ( & V_16 -> V_20 ) ;
F_68 ( V_16 ) ;
F_86 ( & V_16 -> V_20 ) ;
}
static inline int F_96 ( struct V_15 * V_16 , int V_4 )
{
return F_20 ( V_4 , V_16 -> V_6 . V_7 ) ||
F_20 ( V_4 , V_16 -> V_6 . V_31 ) ;
}
static int F_97 ( struct V_73 * V_82 ,
unsigned long V_83 , void * V_84 )
{
int V_24 ;
struct V_15 * V_16 ;
int V_4 = ( unsigned long ) V_84 ;
V_16 = F_9 ( V_82 , struct V_15 , V_85 ) ;
switch ( V_83 ) {
case V_86 :
case V_87 :
if ( ! F_96 ( V_16 , V_4 ) )
break;
F_85 ( & V_16 -> V_20 ) ;
V_24 = F_88 ( V_16 , V_4 ) ;
F_86 ( & V_16 -> V_20 ) ;
if ( V_24 )
return F_98 ( V_24 ) ;
break;
case V_88 :
case V_89 :
if ( ! F_96 ( V_16 , V_4 ) )
break;
F_85 ( & V_16 -> V_20 ) ;
V_24 = F_91 ( V_16 , V_4 ) ;
F_86 ( & V_16 -> V_20 ) ;
if ( V_24 )
return F_98 ( V_24 ) ;
break;
case V_90 :
case V_91 :
if ( ! F_96 ( V_16 , V_4 ) )
break;
F_85 ( & V_16 -> V_20 ) ;
F_91 ( V_16 , V_4 ) ;
F_86 ( & V_16 -> V_20 ) ;
case V_92 :
case V_93 :
if ( ! F_96 ( V_16 , V_4 ) )
break;
F_85 ( & V_16 -> V_20 ) ;
F_88 ( V_16 , V_4 ) ;
F_86 ( & V_16 -> V_20 ) ;
}
return V_94 ;
}
static void F_99 ( struct V_15 * V_16 )
{
#ifdef F_100
F_101 ( & V_16 -> V_85 ) ;
#endif
F_95 ( V_16 ) ;
F_63 ( V_16 -> V_2 ) ;
F_49 ( V_16 -> V_6 . V_7 ) ;
F_49 ( V_16 -> V_6 . V_31 ) ;
F_62 ( V_16 ) ;
}
static void F_102 ( struct V_95 * V_96 )
{
struct V_15 * V_16 = F_103 ( V_96 ) ;
F_99 ( V_16 ) ;
}
static T_2 F_104 ( struct V_15 * V_16 ,
struct V_97 * V_98 , char * V_99 )
{
struct V_6 * V_6 ;
T_2 V_100 ;
F_85 ( & V_16 -> V_20 ) ;
if ( ! strcmp ( V_98 -> V_101 , L_1 ) )
V_6 = V_16 -> V_6 . V_31 ;
else
V_6 = V_16 -> V_6 . V_7 ;
V_100 = F_105 ( V_99 , V_102 , F_106 ( V_6 ) ,
V_103 ) ;
if ( V_102 - V_100 < 2 )
V_100 = - V_26 ;
else
V_100 += sprintf ( V_99 + V_100 , L_2 ) ;
F_86 ( & V_16 -> V_20 ) ;
return V_100 ;
}
static T_2 F_107 ( struct V_15 * V_16 ,
struct V_97 * V_98 ,
const char * V_99 , T_3 V_104 )
{
T_1 V_105 ;
T_2 V_106 ;
int V_107 ;
if ( ! F_47 ( & V_105 , V_58 ) )
return - V_59 ;
V_106 = F_108 ( V_99 , V_104 , F_106 ( V_105 ) ,
V_108 ) ;
if ( V_106 < 0 )
goto V_30;
V_107 = ! strcmp ( V_98 -> V_101 , L_1 ) ?
V_71 : V_70 ;
V_106 = F_87 ( V_16 , V_107 , V_105 ) ;
if ( ! V_106 )
V_106 = V_104 ;
V_30:
F_49 ( V_105 ) ;
return V_106 ;
}
static T_2 F_109 ( struct V_95 * V_96 ,
struct V_97 * V_98 , char * V_99 )
{
struct V_15 * V_16 ;
struct V_109 * V_110 ;
T_2 V_106 = - V_111 ;
V_16 = F_103 ( V_96 ) ;
V_110 = F_110 ( V_98 ) ;
if ( V_110 -> V_112 )
V_106 = V_110 -> V_112 ( V_16 , V_98 , V_99 ) ;
return V_106 ;
}
static T_2 F_111 ( struct V_95 * V_96 , struct V_97 * V_98 ,
const char * V_99 , T_3 V_104 )
{
struct V_15 * V_16 ;
struct V_109 * V_110 ;
T_2 V_106 = - V_111 ;
V_16 = F_103 ( V_96 ) ;
V_110 = F_110 ( V_98 ) ;
if ( V_110 -> V_112 )
V_106 = V_110 -> V_113 ( V_16 , V_98 , V_99 , V_104 ) ;
return V_106 ;
}
struct V_15 * F_112 ( struct V_114 * V_37 )
{
return F_113 ( V_37 , V_115 , V_115 ) ;
}
struct V_15 * F_113 ( struct V_114 * V_37 ,
const struct V_6 * V_56 ,
const struct V_6 * V_57 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 = NULL ;
V_16 = F_58 ( sizeof( struct V_15 ) , V_58 ) ;
if ( ! V_16 )
goto V_24;
F_70 () ;
if ( ! F_47 ( & V_16 -> V_6 . V_7 , V_58 ) )
goto V_116;
if ( ! F_47 ( & V_16 -> V_6 . V_31 , V_58 ) ) {
F_49 ( V_16 -> V_6 . V_7 ) ;
goto V_116;
}
if ( ! F_80 ( V_16 , V_56 ) ||
! F_80 ( V_16 , V_57 ) )
goto V_117;
V_2 = F_57 ( V_16 , V_56 , V_57 ) ;
if ( ! V_2 )
goto V_117;
F_73 ( V_16 -> V_2 , V_2 ) ;
V_16 -> V_37 = V_37 ;
F_83 ( V_16 -> V_6 . V_7 , V_56 ) ;
F_83 ( V_16 -> V_6 . V_31 , V_57 ) ;
V_16 -> V_27 = 0 ;
#ifdef F_100
V_16 -> V_85 . V_118 = F_97 ;
V_16 -> V_85 . V_119 = 0 ;
F_114 ( & V_16 -> V_85 ) ;
#endif
F_71 () ;
F_115 ( & V_16 -> V_72 ) ;
F_116 ( & V_16 -> V_96 , & V_120 ) ;
F_117 ( & V_16 -> V_20 ) ;
return V_16 ;
V_117:
F_49 ( V_16 -> V_6 . V_7 ) ;
F_49 ( V_16 -> V_6 . V_31 ) ;
V_116:
F_62 ( V_16 ) ;
F_71 () ;
V_24:
return NULL ;
}
void F_118 ( struct V_15 * V_16 )
{
F_119 ( & V_16 -> V_96 ) ;
}
