static int F_1 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
F_2 ( & V_4 ) ;
V_3 = F_3 ( V_1 , NULL , 0 , 0 , V_5 ) ;
F_4 ( & V_4 ) ;
if ( F_5 ( V_3 < 0 ) )
return V_3 ;
* V_2 = V_3 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_1 , int V_2 )
{
F_2 ( & V_4 ) ;
F_7 ( V_1 , V_2 ) ;
F_4 ( & V_4 ) ;
}
static unsigned long F_8 ( struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned long V_9 ;
for ( V_9 = 0 ; V_9 <= V_7 -> V_10 ; V_9 ++ ) {
if ( V_8 == V_7 -> V_11 [ V_9 ] )
return V_9 ;
if ( V_8 > V_7 -> V_11 [ V_9 ] )
break;
}
return V_12 ;
}
unsigned long F_9 ( unsigned int V_13 , unsigned int V_8 )
{
struct V_6 * V_7 ;
F_2 ( & V_14 ) ;
F_10 (cpufreq_dev, &cpufreq_dev_list, node) {
if ( F_11 ( V_13 , & V_7 -> V_15 ) ) {
F_4 ( & V_14 ) ;
return F_8 ( V_7 , V_8 ) ;
}
}
F_4 ( & V_14 ) ;
F_12 ( L_1 , V_16 , V_13 ) ;
return V_12 ;
}
static int F_13 ( struct V_17 * V_18 ,
unsigned long V_19 , void * V_20 )
{
struct V_21 * V_22 = V_20 ;
unsigned long V_23 ;
struct V_6 * V_7 ;
if ( V_19 != V_24 )
return V_25 ;
F_2 ( & V_14 ) ;
F_10 (cpufreq_dev, &cpufreq_dev_list, node) {
if ( ! F_11 ( V_22 -> V_13 , & V_7 -> V_15 ) )
continue;
V_23 = V_7 -> V_23 ;
if ( V_22 -> V_26 > V_23 )
F_14 ( V_22 , 0 , V_23 ) ;
break;
}
F_4 ( & V_14 ) ;
return V_27 ;
}
static int F_15 ( struct V_6 * V_28 ,
T_1 V_29 )
{
struct V_30 * V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 = NULL ;
int V_35 = 0 , V_13 , V_36 , V_3 = 0 ;
unsigned long V_8 ;
F_16 () ;
F_17 (cpu, &cpufreq_device->allowed_cpus) {
V_34 = F_18 ( V_13 ) ;
if ( ! V_34 ) {
F_19 ( & V_28 -> V_37 -> V_33 ,
L_2 , V_13 ) ;
continue;
}
V_35 = F_20 ( V_34 ) ;
if ( V_35 > 0 ) {
break;
} else if ( V_35 < 0 ) {
V_3 = V_35 ;
goto V_38;
}
}
if ( V_35 == 0 ) {
V_3 = - V_39 ;
goto V_38;
}
V_30 = F_21 ( V_35 , sizeof( * V_30 ) , V_5 ) ;
if ( ! V_30 ) {
V_3 = - V_40 ;
goto V_38;
}
for ( V_8 = 0 , V_36 = 0 ;
V_32 = F_22 ( V_34 , & V_8 ) , ! F_23 ( V_32 ) ;
V_8 ++ , V_36 ++ ) {
T_1 V_41 , V_42 ;
T_2 V_43 ;
V_41 = V_8 / 1000000 ;
V_42 = F_24 ( V_32 ) / 1000 ;
V_43 = ( T_2 ) V_29 * V_41 * V_42 * V_42 ;
F_25 ( V_43 , 1000000000 ) ;
V_30 [ V_36 ] . V_44 = V_8 / 1000 ;
V_30 [ V_36 ] . V_43 = V_43 ;
}
if ( V_36 == 0 ) {
V_3 = F_26 ( V_32 ) ;
goto V_38;
}
V_28 -> V_45 = V_34 ;
V_28 -> V_46 = V_30 ;
V_28 -> V_47 = V_36 ;
V_38:
F_27 () ;
return V_3 ;
}
static T_1 F_28 ( struct V_6 * V_28 ,
T_1 V_8 )
{
int V_36 ;
struct V_30 * V_48 = V_28 -> V_46 ;
for ( V_36 = 1 ; V_36 < V_28 -> V_47 ; V_36 ++ )
if ( V_8 < V_48 [ V_36 ] . V_44 )
break;
return V_48 [ V_36 - 1 ] . V_43 ;
}
static T_1 F_29 ( struct V_6 * V_28 ,
T_1 V_43 )
{
int V_36 ;
struct V_30 * V_48 = V_28 -> V_46 ;
for ( V_36 = 1 ; V_36 < V_28 -> V_47 ; V_36 ++ )
if ( V_43 < V_48 [ V_36 ] . V_43 )
break;
return V_48 [ V_36 - 1 ] . V_44 ;
}
static T_1 F_30 ( struct V_6 * V_28 , int V_13 )
{
T_1 V_49 ;
T_2 V_50 , V_51 , V_52 , V_53 ;
V_51 = F_31 ( V_13 , & V_50 , 0 ) ;
V_53 = V_51 - V_28 -> V_54 [ V_13 ] ;
V_52 = V_50 - V_28 -> V_55 [ V_13 ] ;
if ( V_52 <= V_53 )
V_49 = 0 ;
else
V_49 = F_32 ( 100 * ( V_52 - V_53 ) , V_52 ) ;
V_28 -> V_54 [ V_13 ] = V_51 ;
V_28 -> V_55 [ V_13 ] = V_50 ;
return V_49 ;
}
static int F_33 ( struct V_6 * V_28 ,
struct V_56 * V_57 , unsigned long V_8 ,
T_1 * V_43 )
{
struct V_31 * V_32 ;
unsigned long V_58 ;
struct V_59 * V_59 = & V_28 -> V_15 ;
unsigned long V_60 = V_8 * 1000 ;
if ( ! V_28 -> V_61 ||
! V_28 -> V_45 ) {
* V_43 = 0 ;
return 0 ;
}
F_16 () ;
V_32 = F_34 ( V_28 -> V_45 , V_60 ,
true ) ;
V_58 = F_24 ( V_32 ) ;
F_27 () ;
if ( V_58 == 0 ) {
F_35 ( V_28 -> V_45 ,
L_3 ,
V_60 , F_23 ( V_32 ) ? F_26 ( V_32 ) : 0 ) ;
return - V_39 ;
}
return V_28 -> V_61 ( V_59 , V_57 -> V_62 ,
V_58 , V_43 ) ;
}
static T_1 F_36 ( struct V_6 * V_28 ,
unsigned long V_8 )
{
T_1 V_63 ;
V_63 = F_28 ( V_28 , V_8 ) ;
return ( V_63 * V_28 -> V_64 ) / 100 ;
}
static int F_37 ( struct V_65 * V_66 ,
unsigned long * V_67 )
{
struct V_6 * V_28 = V_66 -> V_68 ;
* V_67 = V_28 -> V_10 ;
return 0 ;
}
static int F_38 ( struct V_65 * V_66 ,
unsigned long * V_67 )
{
struct V_6 * V_28 = V_66 -> V_68 ;
* V_67 = V_28 -> V_69 ;
return 0 ;
}
static int F_39 ( struct V_65 * V_66 ,
unsigned long V_67 )
{
struct V_6 * V_28 = V_66 -> V_68 ;
unsigned int V_13 = F_40 ( & V_28 -> V_15 ) ;
unsigned int V_70 ;
if ( F_41 ( V_67 > V_28 -> V_10 ) )
return - V_39 ;
if ( V_28 -> V_69 == V_67 )
return 0 ;
V_70 = V_28 -> V_11 [ V_67 ] ;
V_28 -> V_69 = V_67 ;
V_28 -> V_23 = V_70 ;
F_42 ( V_13 ) ;
return 0 ;
}
static int F_43 ( struct V_65 * V_66 ,
struct V_56 * V_57 ,
T_1 * V_43 )
{
unsigned long V_8 ;
int V_36 = 0 , V_13 , V_3 ;
T_1 V_71 , V_72 , V_73 = 0 ;
struct V_6 * V_28 = V_66 -> V_68 ;
T_1 * V_74 = NULL ;
V_13 = F_44 ( & V_28 -> V_15 , V_75 ) ;
if ( V_13 >= V_76 ) {
* V_43 = 0 ;
return 0 ;
}
V_8 = F_45 ( V_13 ) ;
if ( F_46 () ) {
T_1 V_77 = F_47 ( & V_28 -> V_15 ) ;
V_74 = F_48 ( & V_66 -> V_33 , V_77 , sizeof( * V_74 ) ,
V_5 ) ;
}
F_17 (cpu, &cpufreq_device->allowed_cpus) {
T_1 V_49 ;
if ( F_49 ( V_13 ) )
V_49 = F_30 ( V_28 , V_13 ) ;
else
V_49 = 0 ;
V_73 += V_49 ;
if ( F_50 () && V_74 )
V_74 [ V_36 ] = V_49 ;
V_36 ++ ;
}
V_28 -> V_64 = V_73 ;
V_72 = F_36 ( V_28 , V_8 ) ;
V_3 = F_33 ( V_28 , V_57 , V_8 , & V_71 ) ;
if ( V_3 ) {
if ( V_74 )
F_51 ( & V_66 -> V_33 , V_74 ) ;
return V_3 ;
}
if ( V_74 ) {
F_52 (
& V_28 -> V_15 ,
V_8 , V_74 , V_36 , V_72 , V_71 ) ;
F_51 ( & V_66 -> V_33 , V_74 ) ;
}
* V_43 = V_71 + V_72 ;
return 0 ;
}
static int F_53 ( struct V_65 * V_66 ,
struct V_56 * V_57 ,
unsigned long V_67 , T_1 * V_43 )
{
unsigned int V_8 , V_78 ;
T_3 V_59 ;
T_1 V_71 , V_72 ;
int V_3 ;
struct V_6 * V_28 = V_66 -> V_68 ;
F_54 ( & V_59 , & V_28 -> V_15 , V_75 ) ;
V_78 = F_47 ( & V_59 ) ;
if ( V_78 == 0 ) {
* V_43 = 0 ;
return 0 ;
}
V_8 = V_28 -> V_11 [ V_67 ] ;
if ( ! V_8 )
return - V_39 ;
V_72 = F_28 ( V_28 , V_8 ) * V_78 ;
V_3 = F_33 ( V_28 , V_57 , V_8 , & V_71 ) ;
if ( V_3 )
return V_3 ;
* V_43 = V_71 + V_72 ;
return 0 ;
}
static int F_55 ( struct V_65 * V_66 ,
struct V_56 * V_57 , T_1 V_43 ,
unsigned long * V_67 )
{
unsigned int V_13 , V_79 , V_80 ;
int V_3 ;
T_4 V_81 ;
T_1 V_64 , V_82 , V_71 ;
struct V_6 * V_28 = V_66 -> V_68 ;
V_13 = F_44 ( & V_28 -> V_15 , V_75 ) ;
if ( V_13 >= V_76 )
return - V_83 ;
V_79 = F_45 ( V_13 ) ;
V_3 = F_33 ( V_28 , V_57 , V_79 , & V_71 ) ;
if ( V_3 )
return V_3 ;
V_81 = V_43 - V_71 ;
V_81 = V_81 > 0 ? V_81 : 0 ;
V_64 = V_28 -> V_64 ? : 1 ;
V_82 = ( V_81 * 100 ) / V_64 ;
V_80 = F_29 ( V_28 , V_82 ) ;
* V_67 = F_9 ( V_13 , V_80 ) ;
if ( * V_67 == V_12 ) {
F_35 ( & V_66 -> V_33 ,
L_4 ,
V_80 , V_13 ) ;
return - V_39 ;
}
F_56 ( & V_28 -> V_15 ,
V_80 , * V_67 , V_43 ) ;
return 0 ;
}
static unsigned int F_57 ( struct V_84 * V_85 ,
unsigned int V_86 )
{
struct V_84 * V_87 ;
unsigned int V_26 = 0 ;
F_58 (pos, table) {
if ( V_87 -> V_44 > V_26 && V_87 -> V_44 < V_86 )
V_26 = V_87 -> V_44 ;
}
return V_26 ;
}
static struct V_65 *
F_59 ( struct V_88 * V_89 ,
const struct V_59 * V_90 , T_1 V_29 ,
T_5 V_91 )
{
struct V_65 * V_37 ;
struct V_6 * V_7 ;
char V_92 [ V_93 ] ;
struct V_84 * V_87 , * V_85 ;
unsigned int V_8 , V_36 , V_78 ;
int V_3 ;
V_85 = F_60 ( F_61 ( V_90 ) ) ;
if ( ! V_85 ) {
F_62 ( L_5 , V_16 ) ;
return F_63 ( - V_94 ) ;
}
V_7 = F_64 ( sizeof( * V_7 ) , V_5 ) ;
if ( ! V_7 )
return F_63 ( - V_40 ) ;
V_78 = F_47 ( V_90 ) ;
V_7 -> V_54 = F_21 ( V_78 ,
sizeof( * V_7 -> V_54 ) ,
V_5 ) ;
if ( ! V_7 -> V_54 ) {
V_37 = F_63 ( - V_40 ) ;
goto V_95;
}
V_7 -> V_55 =
F_21 ( V_78 , sizeof( * V_7 -> V_55 ) ,
V_5 ) ;
if ( ! V_7 -> V_55 ) {
V_37 = F_63 ( - V_40 ) ;
goto V_96;
}
F_58 (pos, table)
V_7 -> V_10 ++ ;
V_7 -> V_11 = F_65 ( sizeof( * V_7 -> V_11 ) *
V_7 -> V_10 , V_5 ) ;
if ( ! V_7 -> V_11 ) {
V_37 = F_63 ( - V_40 ) ;
goto V_97;
}
V_7 -> V_10 -- ;
F_66 ( & V_7 -> V_15 , V_90 ) ;
if ( V_29 ) {
V_98 . V_99 =
F_43 ;
V_98 . V_100 = F_53 ;
V_98 . V_101 = F_55 ;
V_7 -> V_61 = V_91 ;
V_3 = F_15 ( V_7 , V_29 ) ;
if ( V_3 ) {
V_37 = F_63 ( V_3 ) ;
goto V_102;
}
}
V_3 = F_1 ( & V_103 , & V_7 -> V_2 ) ;
if ( V_3 ) {
V_37 = F_63 ( V_3 ) ;
goto V_102;
}
snprintf ( V_92 , sizeof( V_92 ) , L_6 ,
V_7 -> V_2 ) ;
V_37 = F_67 ( V_89 , V_92 , V_7 ,
& V_98 ) ;
if ( F_23 ( V_37 ) )
goto V_104;
for ( V_36 = 0 , V_8 = - 1 ; V_36 <= V_7 -> V_10 ; V_36 ++ ) {
V_8 = F_57 ( V_85 , V_8 ) ;
V_7 -> V_11 [ V_36 ] = V_8 ;
if ( ! V_8 )
F_68 ( L_7 , V_16 ) ;
else
F_62 ( L_8 , V_16 , V_8 ) ;
}
V_7 -> V_23 = V_7 -> V_11 [ 0 ] ;
V_7 -> V_37 = V_37 ;
F_2 ( & V_4 ) ;
F_2 ( & V_14 ) ;
F_69 ( & V_7 -> V_105 , & V_106 ) ;
F_4 ( & V_14 ) ;
if ( ! V_107 ++ )
F_70 ( & V_108 ,
V_109 ) ;
F_4 ( & V_4 ) ;
return V_37 ;
V_104:
F_6 ( & V_103 , V_7 -> V_2 ) ;
V_102:
F_71 ( V_7 -> V_11 ) ;
V_97:
F_71 ( V_7 -> V_55 ) ;
V_96:
F_71 ( V_7 -> V_54 ) ;
V_95:
F_71 ( V_7 ) ;
return V_37 ;
}
struct V_65 *
F_72 ( const struct V_59 * V_90 )
{
return F_59 ( NULL , V_90 , 0 , NULL ) ;
}
struct V_65 *
F_73 ( struct V_88 * V_89 ,
const struct V_59 * V_90 )
{
if ( ! V_89 )
return F_63 ( - V_39 ) ;
return F_59 ( V_89 , V_90 , 0 , NULL ) ;
}
struct V_65 *
F_74 ( const struct V_59 * V_90 , T_1 V_29 ,
T_5 V_91 )
{
return F_59 ( NULL , V_90 , V_29 ,
V_91 ) ;
}
struct V_65 *
F_75 ( struct V_88 * V_89 ,
const struct V_59 * V_90 ,
T_1 V_29 ,
T_5 V_91 )
{
if ( ! V_89 )
return F_63 ( - V_39 ) ;
return F_59 ( V_89 , V_90 , V_29 ,
V_91 ) ;
}
void F_76 ( struct V_65 * V_66 )
{
struct V_6 * V_7 ;
if ( ! V_66 )
return;
V_7 = V_66 -> V_68 ;
F_2 ( & V_4 ) ;
if ( ! -- V_107 )
F_77 ( & V_108 ,
V_109 ) ;
F_2 ( & V_14 ) ;
F_78 ( & V_7 -> V_105 ) ;
F_4 ( & V_14 ) ;
F_4 ( & V_4 ) ;
F_79 ( V_7 -> V_37 ) ;
F_6 ( & V_103 , V_7 -> V_2 ) ;
F_71 ( V_7 -> V_55 ) ;
F_71 ( V_7 -> V_54 ) ;
F_71 ( V_7 -> V_11 ) ;
F_71 ( V_7 ) ;
}
