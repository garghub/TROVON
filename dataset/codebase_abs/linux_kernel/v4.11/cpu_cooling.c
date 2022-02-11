static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned long V_4 ;
for ( V_4 = 0 ; V_4 <= V_2 -> V_5 ; V_4 ++ ) {
if ( V_3 == V_2 -> V_6 [ V_4 ] )
return V_4 ;
if ( V_3 > V_2 -> V_6 [ V_4 ] )
break;
}
return V_7 ;
}
unsigned long F_2 ( unsigned int V_8 , unsigned int V_3 )
{
struct V_1 * V_2 ;
F_3 ( & V_9 ) ;
F_4 (cpufreq_dev, &cpufreq_dev_list, node) {
if ( F_5 ( V_8 , & V_2 -> V_10 ) ) {
F_6 ( & V_9 ) ;
return F_1 ( V_2 , V_3 ) ;
}
}
F_6 ( & V_9 ) ;
F_7 ( L_1 , V_11 , V_8 ) ;
return V_7 ;
}
static int F_8 ( struct V_12 * V_13 ,
unsigned long V_14 , void * V_15 )
{
struct V_16 * V_17 = V_15 ;
unsigned long V_18 ;
struct V_1 * V_2 ;
if ( V_14 != V_19 )
return V_20 ;
F_3 ( & V_9 ) ;
F_4 (cpufreq_dev, &cpufreq_dev_list, node) {
if ( ! F_5 ( V_17 -> V_8 , & V_2 -> V_10 ) )
continue;
V_18 = V_2 -> V_18 ;
if ( V_17 -> V_21 > V_18 )
F_9 ( V_17 , 0 , V_18 ) ;
break;
}
F_6 ( & V_9 ) ;
return V_22 ;
}
static int F_10 ( struct V_1 * V_23 ,
T_1 V_24 )
{
struct V_25 * V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 = NULL ;
int V_30 = 0 , V_8 , V_31 , V_32 = 0 ;
unsigned long V_3 ;
F_11 (cpu, &cpufreq_device->allowed_cpus) {
V_29 = F_12 ( V_8 ) ;
if ( ! V_29 ) {
F_13 ( & V_23 -> V_33 -> V_28 ,
L_2 , V_8 ) ;
continue;
}
V_30 = F_14 ( V_29 ) ;
if ( V_30 > 0 )
break;
else if ( V_30 < 0 )
return V_30 ;
}
if ( V_30 == 0 )
return - V_34 ;
V_25 = F_15 ( V_30 , sizeof( * V_25 ) , V_35 ) ;
if ( ! V_25 )
return - V_36 ;
for ( V_3 = 0 , V_31 = 0 ;
V_27 = F_16 ( V_29 , & V_3 ) , ! F_17 ( V_27 ) ;
V_3 ++ , V_31 ++ ) {
T_1 V_37 , V_38 ;
T_2 V_39 ;
if ( V_31 >= V_30 ) {
V_32 = - V_40 ;
goto V_41;
}
V_37 = V_3 / 1000000 ;
V_38 = F_18 ( V_27 ) / 1000 ;
F_19 ( V_27 ) ;
V_39 = ( T_2 ) V_24 * V_37 * V_38 * V_38 ;
F_20 ( V_39 , 1000000000 ) ;
V_25 [ V_31 ] . V_42 = V_3 / 1000 ;
V_25 [ V_31 ] . V_39 = V_39 ;
}
if ( V_31 != V_30 ) {
V_32 = F_21 ( V_27 ) ;
goto V_41;
}
V_23 -> V_43 = V_29 ;
V_23 -> V_44 = V_25 ;
V_23 -> V_45 = V_31 ;
return 0 ;
V_41:
F_22 ( V_25 ) ;
return V_32 ;
}
static T_1 F_23 ( struct V_1 * V_23 ,
T_1 V_3 )
{
int V_31 ;
struct V_25 * V_46 = V_23 -> V_44 ;
for ( V_31 = 1 ; V_31 < V_23 -> V_45 ; V_31 ++ )
if ( V_3 < V_46 [ V_31 ] . V_42 )
break;
return V_46 [ V_31 - 1 ] . V_39 ;
}
static T_1 F_24 ( struct V_1 * V_23 ,
T_1 V_39 )
{
int V_31 ;
struct V_25 * V_46 = V_23 -> V_44 ;
for ( V_31 = 1 ; V_31 < V_23 -> V_45 ; V_31 ++ )
if ( V_39 < V_46 [ V_31 ] . V_39 )
break;
return V_46 [ V_31 - 1 ] . V_42 ;
}
static T_1 F_25 ( struct V_1 * V_23 , int V_8 ,
int V_47 )
{
T_1 V_48 ;
T_2 V_49 , V_50 , V_51 , V_52 ;
V_50 = F_26 ( V_8 , & V_49 , 0 ) ;
V_52 = V_50 - V_23 -> V_53 [ V_47 ] ;
V_51 = V_49 - V_23 -> V_54 [ V_47 ] ;
if ( V_51 <= V_52 )
V_48 = 0 ;
else
V_48 = F_27 ( 100 * ( V_51 - V_52 ) , V_51 ) ;
V_23 -> V_53 [ V_47 ] = V_50 ;
V_23 -> V_54 [ V_47 ] = V_49 ;
return V_48 ;
}
static int F_28 ( struct V_1 * V_23 ,
struct V_55 * V_56 , unsigned long V_3 ,
T_1 * V_39 )
{
struct V_26 * V_27 ;
unsigned long V_57 ;
struct V_58 * V_58 = & V_23 -> V_10 ;
unsigned long V_59 = V_3 * 1000 ;
if ( ! V_23 -> V_60 ||
! V_23 -> V_43 ) {
* V_39 = 0 ;
return 0 ;
}
V_27 = F_29 ( V_23 -> V_43 , V_59 ,
true ) ;
if ( F_17 ( V_27 ) ) {
F_30 ( V_23 -> V_43 ,
L_3 ,
V_59 , F_21 ( V_27 ) ) ;
return - V_34 ;
}
V_57 = F_18 ( V_27 ) ;
F_19 ( V_27 ) ;
if ( V_57 == 0 ) {
F_31 ( V_23 -> V_43 ,
L_4 ,
V_59 ) ;
return - V_34 ;
}
return V_23 -> V_60 ( V_58 , V_56 -> V_61 ,
V_57 , V_39 ) ;
}
static T_1 F_32 ( struct V_1 * V_23 ,
unsigned long V_3 )
{
T_1 V_62 ;
V_62 = F_23 ( V_23 , V_3 ) ;
return ( V_62 * V_23 -> V_63 ) / 100 ;
}
static int F_33 ( struct V_64 * V_65 ,
unsigned long * V_66 )
{
struct V_1 * V_23 = V_65 -> V_67 ;
* V_66 = V_23 -> V_5 ;
return 0 ;
}
static int F_34 ( struct V_64 * V_65 ,
unsigned long * V_66 )
{
struct V_1 * V_23 = V_65 -> V_67 ;
* V_66 = V_23 -> V_68 ;
return 0 ;
}
static int F_35 ( struct V_64 * V_65 ,
unsigned long V_66 )
{
struct V_1 * V_23 = V_65 -> V_67 ;
unsigned int V_8 = F_36 ( & V_23 -> V_10 ) ;
unsigned int V_69 ;
if ( F_37 ( V_66 > V_23 -> V_5 ) )
return - V_34 ;
if ( V_23 -> V_68 == V_66 )
return 0 ;
V_69 = V_23 -> V_6 [ V_66 ] ;
V_23 -> V_68 = V_66 ;
V_23 -> V_18 = V_69 ;
F_38 ( V_8 ) ;
return 0 ;
}
static int F_39 ( struct V_64 * V_65 ,
struct V_55 * V_56 ,
T_1 * V_39 )
{
unsigned long V_3 ;
int V_31 = 0 , V_8 , V_32 ;
T_1 V_70 , V_71 , V_72 = 0 ;
struct V_1 * V_23 = V_65 -> V_67 ;
T_1 * V_73 = NULL ;
V_8 = F_40 ( & V_23 -> V_10 , V_74 ) ;
if ( V_8 >= V_75 ) {
* V_39 = 0 ;
return 0 ;
}
V_3 = F_41 ( V_8 ) ;
if ( F_42 () ) {
T_1 V_76 = F_43 ( & V_23 -> V_10 ) ;
V_73 = F_15 ( V_76 , sizeof( * V_73 ) , V_35 ) ;
}
F_11 (cpu, &cpufreq_device->allowed_cpus) {
T_1 V_48 ;
if ( F_44 ( V_8 ) )
V_48 = F_25 ( V_23 , V_8 , V_31 ) ;
else
V_48 = 0 ;
V_72 += V_48 ;
if ( F_45 () && V_73 )
V_73 [ V_31 ] = V_48 ;
V_31 ++ ;
}
V_23 -> V_63 = V_72 ;
V_71 = F_32 ( V_23 , V_3 ) ;
V_32 = F_28 ( V_23 , V_56 , V_3 , & V_70 ) ;
if ( V_32 ) {
F_22 ( V_73 ) ;
return V_32 ;
}
if ( V_73 ) {
F_46 (
& V_23 -> V_10 ,
V_3 , V_73 , V_31 , V_71 , V_70 ) ;
F_22 ( V_73 ) ;
}
* V_39 = V_70 + V_71 ;
return 0 ;
}
static int F_47 ( struct V_64 * V_65 ,
struct V_55 * V_56 ,
unsigned long V_66 , T_1 * V_39 )
{
unsigned int V_3 , V_77 ;
T_3 V_58 ;
T_1 V_70 , V_71 ;
int V_32 ;
struct V_1 * V_23 = V_65 -> V_67 ;
if ( ! F_48 ( & V_58 , V_35 ) )
return - V_36 ;
F_49 ( V_58 , & V_23 -> V_10 , V_74 ) ;
V_77 = F_43 ( V_58 ) ;
if ( V_77 == 0 ) {
* V_39 = 0 ;
V_32 = 0 ;
goto V_78;
}
V_3 = V_23 -> V_6 [ V_66 ] ;
if ( ! V_3 ) {
V_32 = - V_34 ;
goto V_78;
}
V_71 = F_23 ( V_23 , V_3 ) * V_77 ;
V_32 = F_28 ( V_23 , V_56 , V_3 , & V_70 ) ;
if ( V_32 )
goto V_78;
* V_39 = V_70 + V_71 ;
V_78:
F_50 ( V_58 ) ;
return V_32 ;
}
static int F_51 ( struct V_64 * V_65 ,
struct V_55 * V_56 , T_1 V_39 ,
unsigned long * V_66 )
{
unsigned int V_8 , V_79 , V_80 ;
int V_32 ;
T_4 V_81 ;
T_1 V_63 , V_82 , V_70 ;
struct V_1 * V_23 = V_65 -> V_67 ;
V_8 = F_40 ( & V_23 -> V_10 , V_74 ) ;
if ( V_8 >= V_75 )
return - V_83 ;
V_79 = F_41 ( V_8 ) ;
V_32 = F_28 ( V_23 , V_56 , V_79 , & V_70 ) ;
if ( V_32 )
return V_32 ;
V_81 = V_39 - V_70 ;
V_81 = V_81 > 0 ? V_81 : 0 ;
V_63 = V_23 -> V_63 ? : 1 ;
V_82 = ( V_81 * 100 ) / V_63 ;
V_80 = F_24 ( V_23 , V_82 ) ;
* V_66 = F_2 ( V_8 , V_80 ) ;
if ( * V_66 == V_7 ) {
F_31 ( & V_65 -> V_28 ,
L_5 ,
V_80 , V_8 ) ;
return - V_34 ;
}
F_52 ( & V_23 -> V_10 ,
V_80 , * V_66 , V_39 ) ;
return 0 ;
}
static unsigned int F_53 ( struct V_84 * V_85 ,
unsigned int V_86 )
{
struct V_84 * V_87 ;
unsigned int V_21 = 0 ;
F_54 (pos, table) {
if ( V_87 -> V_42 > V_21 && V_87 -> V_42 < V_86 )
V_21 = V_87 -> V_42 ;
}
return V_21 ;
}
static struct V_64 *
F_55 ( struct V_88 * V_89 ,
const struct V_58 * V_90 , T_1 V_24 ,
T_5 V_91 )
{
struct V_16 * V_17 ;
struct V_64 * V_33 ;
struct V_1 * V_2 ;
char V_92 [ V_93 ] ;
struct V_84 * V_87 , * V_85 ;
T_3 V_94 ;
unsigned int V_3 , V_31 , V_77 ;
int V_32 ;
struct V_95 * V_96 ;
bool V_97 ;
if ( ! F_48 ( & V_94 , V_35 ) )
return F_56 ( - V_36 ) ;
F_49 ( V_94 , V_90 , V_74 ) ;
V_17 = F_57 ( F_58 ( V_94 ) ) ;
if ( ! V_17 ) {
F_59 ( L_6 , V_11 ) ;
V_33 = F_56 ( - V_98 ) ;
goto V_99;
}
V_85 = V_17 -> V_6 ;
if ( ! V_85 ) {
F_59 ( L_7 , V_11 ) ;
V_33 = F_56 ( - V_83 ) ;
goto V_100;
}
V_2 = F_60 ( sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 ) {
V_33 = F_56 ( - V_36 ) ;
goto V_100;
}
V_77 = F_43 ( V_90 ) ;
V_2 -> V_53 = F_15 ( V_77 ,
sizeof( * V_2 -> V_53 ) ,
V_35 ) ;
if ( ! V_2 -> V_53 ) {
V_33 = F_56 ( - V_36 ) ;
goto V_101;
}
V_2 -> V_54 =
F_15 ( V_77 , sizeof( * V_2 -> V_54 ) ,
V_35 ) ;
if ( ! V_2 -> V_54 ) {
V_33 = F_56 ( - V_36 ) ;
goto V_102;
}
F_54 (pos, table)
V_2 -> V_5 ++ ;
V_2 -> V_6 = F_61 ( sizeof( * V_2 -> V_6 ) *
V_2 -> V_5 , V_35 ) ;
if ( ! V_2 -> V_6 ) {
V_33 = F_56 ( - V_36 ) ;
goto V_103;
}
V_2 -> V_5 -- ;
F_62 ( & V_2 -> V_10 , V_90 ) ;
if ( V_24 ) {
V_2 -> V_60 = V_91 ;
V_32 = F_10 ( V_2 , V_24 ) ;
if ( V_32 ) {
V_33 = F_56 ( V_32 ) ;
goto V_104;
}
V_96 = & V_105 ;
} else {
V_96 = & V_106 ;
}
V_32 = F_63 ( & V_107 , 0 , 0 , V_35 ) ;
if ( V_32 < 0 ) {
V_33 = F_56 ( V_32 ) ;
goto V_41;
}
V_2 -> V_108 = V_32 ;
for ( V_31 = 0 , V_3 = - 1 ; V_31 <= V_2 -> V_5 ; V_31 ++ ) {
V_3 = F_53 ( V_85 , V_3 ) ;
V_2 -> V_6 [ V_31 ] = V_3 ;
if ( ! V_3 )
F_64 ( L_8 , V_11 ) ;
else
F_59 ( L_9 , V_11 , V_3 ) ;
}
snprintf ( V_92 , sizeof( V_92 ) , L_10 ,
V_2 -> V_108 ) ;
V_33 = F_65 ( V_89 , V_92 , V_2 ,
V_96 ) ;
if ( F_17 ( V_33 ) )
goto V_109;
V_2 -> V_18 = V_2 -> V_6 [ 0 ] ;
V_2 -> V_33 = V_33 ;
F_3 ( & V_9 ) ;
V_97 = F_66 ( & V_110 ) ;
F_67 ( & V_2 -> V_111 , & V_110 ) ;
F_6 ( & V_9 ) ;
if ( V_97 )
F_68 ( & V_112 ,
V_113 ) ;
goto V_100;
V_109:
F_69 ( & V_107 , V_2 -> V_108 ) ;
V_41:
F_22 ( V_2 -> V_44 ) ;
V_104:
F_22 ( V_2 -> V_6 ) ;
V_103:
F_22 ( V_2 -> V_54 ) ;
V_102:
F_22 ( V_2 -> V_53 ) ;
V_101:
F_22 ( V_2 ) ;
V_100:
F_70 ( V_17 ) ;
V_99:
F_50 ( V_94 ) ;
return V_33 ;
}
struct V_64 *
F_71 ( const struct V_58 * V_90 )
{
return F_55 ( NULL , V_90 , 0 , NULL ) ;
}
struct V_64 *
F_72 ( struct V_88 * V_89 ,
const struct V_58 * V_90 )
{
if ( ! V_89 )
return F_56 ( - V_34 ) ;
return F_55 ( V_89 , V_90 , 0 , NULL ) ;
}
struct V_64 *
F_73 ( const struct V_58 * V_90 , T_1 V_24 ,
T_5 V_91 )
{
return F_55 ( NULL , V_90 , V_24 ,
V_91 ) ;
}
struct V_64 *
F_74 ( struct V_88 * V_89 ,
const struct V_58 * V_90 ,
T_1 V_24 ,
T_5 V_91 )
{
if ( ! V_89 )
return F_56 ( - V_34 ) ;
return F_55 ( V_89 , V_90 , V_24 ,
V_91 ) ;
}
void F_75 ( struct V_64 * V_65 )
{
struct V_1 * V_2 ;
bool V_114 ;
if ( ! V_65 )
return;
V_2 = V_65 -> V_67 ;
F_3 ( & V_9 ) ;
F_76 ( & V_2 -> V_111 ) ;
V_114 = F_66 ( & V_110 ) ;
F_6 ( & V_9 ) ;
if ( V_114 )
F_77 ( & V_112 ,
V_113 ) ;
F_78 ( V_2 -> V_33 ) ;
F_69 ( & V_107 , V_2 -> V_108 ) ;
F_22 ( V_2 -> V_44 ) ;
F_22 ( V_2 -> V_54 ) ;
F_22 ( V_2 -> V_53 ) ;
F_22 ( V_2 -> V_6 ) ;
F_22 ( V_2 ) ;
}
