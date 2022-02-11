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
F_16 (cpu, &cpufreq_device->allowed_cpus) {
V_34 = F_17 ( V_13 ) ;
if ( ! V_34 ) {
F_18 ( & V_28 -> V_37 -> V_33 ,
L_2 , V_13 ) ;
continue;
}
V_35 = F_19 ( V_34 ) ;
if ( V_35 > 0 )
break;
else if ( V_35 < 0 )
return V_35 ;
}
if ( V_35 == 0 )
return - V_38 ;
V_30 = F_20 ( V_35 , sizeof( * V_30 ) , V_5 ) ;
if ( ! V_30 )
return - V_39 ;
F_21 () ;
for ( V_8 = 0 , V_36 = 0 ;
V_32 = F_22 ( V_34 , & V_8 ) , ! F_23 ( V_32 ) ;
V_8 ++ , V_36 ++ ) {
T_1 V_40 , V_41 ;
T_2 V_42 ;
if ( V_36 >= V_35 ) {
F_24 () ;
V_3 = - V_43 ;
goto V_44;
}
V_40 = V_8 / 1000000 ;
V_41 = F_25 ( V_32 ) / 1000 ;
V_42 = ( T_2 ) V_29 * V_40 * V_41 * V_41 ;
F_26 ( V_42 , 1000000000 ) ;
V_30 [ V_36 ] . V_45 = V_8 / 1000 ;
V_30 [ V_36 ] . V_42 = V_42 ;
}
F_24 () ;
if ( V_36 != V_35 ) {
V_3 = F_27 ( V_32 ) ;
goto V_44;
}
V_28 -> V_46 = V_34 ;
V_28 -> V_47 = V_30 ;
V_28 -> V_48 = V_36 ;
return 0 ;
V_44:
F_28 ( V_30 ) ;
return V_3 ;
}
static T_1 F_29 ( struct V_6 * V_28 ,
T_1 V_8 )
{
int V_36 ;
struct V_30 * V_49 = V_28 -> V_47 ;
for ( V_36 = 1 ; V_36 < V_28 -> V_48 ; V_36 ++ )
if ( V_8 < V_49 [ V_36 ] . V_45 )
break;
return V_49 [ V_36 - 1 ] . V_42 ;
}
static T_1 F_30 ( struct V_6 * V_28 ,
T_1 V_42 )
{
int V_36 ;
struct V_30 * V_49 = V_28 -> V_47 ;
for ( V_36 = 1 ; V_36 < V_28 -> V_48 ; V_36 ++ )
if ( V_42 < V_49 [ V_36 ] . V_42 )
break;
return V_49 [ V_36 - 1 ] . V_45 ;
}
static T_1 F_31 ( struct V_6 * V_28 , int V_13 ,
int V_50 )
{
T_1 V_51 ;
T_2 V_52 , V_53 , V_54 , V_55 ;
V_53 = F_32 ( V_13 , & V_52 , 0 ) ;
V_55 = V_53 - V_28 -> V_56 [ V_50 ] ;
V_54 = V_52 - V_28 -> V_57 [ V_50 ] ;
if ( V_54 <= V_55 )
V_51 = 0 ;
else
V_51 = F_33 ( 100 * ( V_54 - V_55 ) , V_54 ) ;
V_28 -> V_56 [ V_50 ] = V_53 ;
V_28 -> V_57 [ V_50 ] = V_52 ;
return V_51 ;
}
static int F_34 ( struct V_6 * V_28 ,
struct V_58 * V_59 , unsigned long V_8 ,
T_1 * V_42 )
{
struct V_31 * V_32 ;
unsigned long V_60 ;
struct V_61 * V_61 = & V_28 -> V_15 ;
unsigned long V_62 = V_8 * 1000 ;
if ( ! V_28 -> V_63 ||
! V_28 -> V_46 ) {
* V_42 = 0 ;
return 0 ;
}
F_21 () ;
V_32 = F_35 ( V_28 -> V_46 , V_62 ,
true ) ;
V_60 = F_25 ( V_32 ) ;
F_24 () ;
if ( V_60 == 0 ) {
F_36 ( V_28 -> V_46 ,
L_3 ,
V_62 , F_23 ( V_32 ) ? F_27 ( V_32 ) : 0 ) ;
return - V_38 ;
}
return V_28 -> V_63 ( V_61 , V_59 -> V_64 ,
V_60 , V_42 ) ;
}
static T_1 F_37 ( struct V_6 * V_28 ,
unsigned long V_8 )
{
T_1 V_65 ;
V_65 = F_29 ( V_28 , V_8 ) ;
return ( V_65 * V_28 -> V_66 ) / 100 ;
}
static int F_38 ( struct V_67 * V_68 ,
unsigned long * V_69 )
{
struct V_6 * V_28 = V_68 -> V_70 ;
* V_69 = V_28 -> V_10 ;
return 0 ;
}
static int F_39 ( struct V_67 * V_68 ,
unsigned long * V_69 )
{
struct V_6 * V_28 = V_68 -> V_70 ;
* V_69 = V_28 -> V_71 ;
return 0 ;
}
static int F_40 ( struct V_67 * V_68 ,
unsigned long V_69 )
{
struct V_6 * V_28 = V_68 -> V_70 ;
unsigned int V_13 = F_41 ( & V_28 -> V_15 ) ;
unsigned int V_72 ;
if ( F_42 ( V_69 > V_28 -> V_10 ) )
return - V_38 ;
if ( V_28 -> V_71 == V_69 )
return 0 ;
V_72 = V_28 -> V_11 [ V_69 ] ;
V_28 -> V_71 = V_69 ;
V_28 -> V_23 = V_72 ;
F_43 ( V_13 ) ;
return 0 ;
}
static int F_44 ( struct V_67 * V_68 ,
struct V_58 * V_59 ,
T_1 * V_42 )
{
unsigned long V_8 ;
int V_36 = 0 , V_13 , V_3 ;
T_1 V_73 , V_74 , V_75 = 0 ;
struct V_6 * V_28 = V_68 -> V_70 ;
T_1 * V_76 = NULL ;
V_13 = F_45 ( & V_28 -> V_15 , V_77 ) ;
if ( V_13 >= V_78 ) {
* V_42 = 0 ;
return 0 ;
}
V_8 = F_46 ( V_13 ) ;
if ( F_47 () ) {
T_1 V_79 = F_48 ( & V_28 -> V_15 ) ;
V_76 = F_20 ( V_79 , sizeof( * V_76 ) , V_5 ) ;
}
F_16 (cpu, &cpufreq_device->allowed_cpus) {
T_1 V_51 ;
if ( F_49 ( V_13 ) )
V_51 = F_31 ( V_28 , V_13 , V_36 ) ;
else
V_51 = 0 ;
V_75 += V_51 ;
if ( F_50 () && V_76 )
V_76 [ V_36 ] = V_51 ;
V_36 ++ ;
}
V_28 -> V_66 = V_75 ;
V_74 = F_37 ( V_28 , V_8 ) ;
V_3 = F_34 ( V_28 , V_59 , V_8 , & V_73 ) ;
if ( V_3 ) {
F_28 ( V_76 ) ;
return V_3 ;
}
if ( V_76 ) {
F_51 (
& V_28 -> V_15 ,
V_8 , V_76 , V_36 , V_74 , V_73 ) ;
F_28 ( V_76 ) ;
}
* V_42 = V_73 + V_74 ;
return 0 ;
}
static int F_52 ( struct V_67 * V_68 ,
struct V_58 * V_59 ,
unsigned long V_69 , T_1 * V_42 )
{
unsigned int V_8 , V_80 ;
T_3 V_61 ;
T_1 V_73 , V_74 ;
int V_3 ;
struct V_6 * V_28 = V_68 -> V_70 ;
F_53 ( & V_61 , & V_28 -> V_15 , V_77 ) ;
V_80 = F_48 ( & V_61 ) ;
if ( V_80 == 0 ) {
* V_42 = 0 ;
return 0 ;
}
V_8 = V_28 -> V_11 [ V_69 ] ;
if ( ! V_8 )
return - V_38 ;
V_74 = F_29 ( V_28 , V_8 ) * V_80 ;
V_3 = F_34 ( V_28 , V_59 , V_8 , & V_73 ) ;
if ( V_3 )
return V_3 ;
* V_42 = V_73 + V_74 ;
return 0 ;
}
static int F_54 ( struct V_67 * V_68 ,
struct V_58 * V_59 , T_1 V_42 ,
unsigned long * V_69 )
{
unsigned int V_13 , V_81 , V_82 ;
int V_3 ;
T_4 V_83 ;
T_1 V_66 , V_84 , V_73 ;
struct V_6 * V_28 = V_68 -> V_70 ;
V_13 = F_45 ( & V_28 -> V_15 , V_77 ) ;
if ( V_13 >= V_78 )
return - V_85 ;
V_81 = F_46 ( V_13 ) ;
V_3 = F_34 ( V_28 , V_59 , V_81 , & V_73 ) ;
if ( V_3 )
return V_3 ;
V_83 = V_42 - V_73 ;
V_83 = V_83 > 0 ? V_83 : 0 ;
V_66 = V_28 -> V_66 ? : 1 ;
V_84 = ( V_83 * 100 ) / V_66 ;
V_82 = F_30 ( V_28 , V_84 ) ;
* V_69 = F_9 ( V_13 , V_82 ) ;
if ( * V_69 == V_12 ) {
F_36 ( & V_68 -> V_33 ,
L_4 ,
V_82 , V_13 ) ;
return - V_38 ;
}
F_55 ( & V_28 -> V_15 ,
V_82 , * V_69 , V_42 ) ;
return 0 ;
}
static unsigned int F_56 ( struct V_86 * V_87 ,
unsigned int V_88 )
{
struct V_86 * V_89 ;
unsigned int V_26 = 0 ;
F_57 (pos, table) {
if ( V_89 -> V_45 > V_26 && V_89 -> V_45 < V_88 )
V_26 = V_89 -> V_45 ;
}
return V_26 ;
}
static struct V_67 *
F_58 ( struct V_90 * V_91 ,
const struct V_61 * V_92 , T_1 V_29 ,
T_5 V_93 )
{
struct V_67 * V_37 ;
struct V_6 * V_7 ;
char V_94 [ V_95 ] ;
struct V_86 * V_89 , * V_87 ;
unsigned int V_8 , V_36 , V_80 ;
int V_3 ;
V_87 = F_59 ( F_60 ( V_92 ) ) ;
if ( ! V_87 ) {
F_61 ( L_5 , V_16 ) ;
return F_62 ( - V_96 ) ;
}
V_7 = F_63 ( sizeof( * V_7 ) , V_5 ) ;
if ( ! V_7 )
return F_62 ( - V_39 ) ;
V_80 = F_48 ( V_92 ) ;
V_7 -> V_56 = F_20 ( V_80 ,
sizeof( * V_7 -> V_56 ) ,
V_5 ) ;
if ( ! V_7 -> V_56 ) {
V_37 = F_62 ( - V_39 ) ;
goto V_97;
}
V_7 -> V_57 =
F_20 ( V_80 , sizeof( * V_7 -> V_57 ) ,
V_5 ) ;
if ( ! V_7 -> V_57 ) {
V_37 = F_62 ( - V_39 ) ;
goto V_98;
}
F_57 (pos, table)
V_7 -> V_10 ++ ;
V_7 -> V_11 = F_64 ( sizeof( * V_7 -> V_11 ) *
V_7 -> V_10 , V_5 ) ;
if ( ! V_7 -> V_11 ) {
V_37 = F_62 ( - V_39 ) ;
goto V_99;
}
V_7 -> V_10 -- ;
F_65 ( & V_7 -> V_15 , V_92 ) ;
if ( V_29 ) {
V_100 . V_101 =
F_44 ;
V_100 . V_102 = F_52 ;
V_100 . V_103 = F_54 ;
V_7 -> V_63 = V_93 ;
V_3 = F_15 ( V_7 , V_29 ) ;
if ( V_3 ) {
V_37 = F_62 ( V_3 ) ;
goto V_104;
}
}
V_3 = F_1 ( & V_105 , & V_7 -> V_2 ) ;
if ( V_3 ) {
V_37 = F_62 ( V_3 ) ;
goto V_44;
}
snprintf ( V_94 , sizeof( V_94 ) , L_6 ,
V_7 -> V_2 ) ;
V_37 = F_66 ( V_91 , V_94 , V_7 ,
& V_100 ) ;
if ( F_23 ( V_37 ) )
goto V_106;
for ( V_36 = 0 , V_8 = - 1 ; V_36 <= V_7 -> V_10 ; V_36 ++ ) {
V_8 = F_56 ( V_87 , V_8 ) ;
V_7 -> V_11 [ V_36 ] = V_8 ;
if ( ! V_8 )
F_67 ( L_7 , V_16 ) ;
else
F_61 ( L_8 , V_16 , V_8 ) ;
}
V_7 -> V_23 = V_7 -> V_11 [ 0 ] ;
V_7 -> V_37 = V_37 ;
F_2 ( & V_4 ) ;
F_2 ( & V_14 ) ;
F_68 ( & V_7 -> V_107 , & V_108 ) ;
F_4 ( & V_14 ) ;
if ( ! V_109 ++ )
F_69 ( & V_110 ,
V_111 ) ;
F_4 ( & V_4 ) ;
return V_37 ;
V_106:
F_6 ( & V_105 , V_7 -> V_2 ) ;
V_44:
F_28 ( V_7 -> V_47 ) ;
V_104:
F_28 ( V_7 -> V_11 ) ;
V_99:
F_28 ( V_7 -> V_57 ) ;
V_98:
F_28 ( V_7 -> V_56 ) ;
V_97:
F_28 ( V_7 ) ;
return V_37 ;
}
struct V_67 *
F_70 ( const struct V_61 * V_92 )
{
return F_58 ( NULL , V_92 , 0 , NULL ) ;
}
struct V_67 *
F_71 ( struct V_90 * V_91 ,
const struct V_61 * V_92 )
{
if ( ! V_91 )
return F_62 ( - V_38 ) ;
return F_58 ( V_91 , V_92 , 0 , NULL ) ;
}
struct V_67 *
F_72 ( const struct V_61 * V_92 , T_1 V_29 ,
T_5 V_93 )
{
return F_58 ( NULL , V_92 , V_29 ,
V_93 ) ;
}
struct V_67 *
F_73 ( struct V_90 * V_91 ,
const struct V_61 * V_92 ,
T_1 V_29 ,
T_5 V_93 )
{
if ( ! V_91 )
return F_62 ( - V_38 ) ;
return F_58 ( V_91 , V_92 , V_29 ,
V_93 ) ;
}
void F_74 ( struct V_67 * V_68 )
{
struct V_6 * V_7 ;
if ( ! V_68 )
return;
V_7 = V_68 -> V_70 ;
F_2 ( & V_4 ) ;
if ( ! -- V_109 )
F_75 ( & V_110 ,
V_111 ) ;
F_2 ( & V_14 ) ;
F_76 ( & V_7 -> V_107 ) ;
F_4 ( & V_14 ) ;
F_4 ( & V_4 ) ;
F_77 ( V_7 -> V_37 ) ;
F_6 ( & V_105 , V_7 -> V_2 ) ;
F_28 ( V_7 -> V_47 ) ;
F_28 ( V_7 -> V_57 ) ;
F_28 ( V_7 -> V_56 ) ;
F_28 ( V_7 -> V_11 ) ;
F_28 ( V_7 ) ;
}
