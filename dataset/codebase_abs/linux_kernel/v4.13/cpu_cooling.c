static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
unsigned long V_5 ;
for ( V_5 = 1 ; V_5 <= V_2 -> V_6 ; V_5 ++ )
if ( V_3 > V_4 [ V_5 ] . V_7 )
break;
return V_5 - 1 ;
}
static int F_2 ( struct V_8 * V_9 ,
unsigned long V_10 , void * V_11 )
{
struct V_12 * V_13 = V_11 ;
unsigned long V_14 ;
struct V_1 * V_2 ;
if ( V_10 != V_15 )
return V_16 ;
F_3 ( & V_17 ) ;
F_4 (cpufreq_cdev, &cpufreq_cdev_list, node) {
if ( V_13 -> V_18 != V_2 -> V_13 -> V_18 )
continue;
V_14 = V_2 -> V_14 ;
if ( V_13 -> V_19 > V_14 )
F_5 ( V_13 , 0 , V_14 ) ;
break;
}
F_6 ( & V_17 ) ;
return V_20 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_21 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 ;
struct V_24 * V_25 = NULL ;
int V_26 = 0 , V_18 = V_2 -> V_13 -> V_18 , V_27 ;
V_25 = F_8 ( V_18 ) ;
if ( F_9 ( ! V_25 ) ) {
F_10 ( & V_2 -> V_28 -> V_24 ,
L_1 , V_18 ) ;
return - V_29 ;
}
V_26 = F_11 ( V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 != V_2 -> V_6 + 1 ) {
F_10 ( V_25 , L_2 ) ;
return - V_30 ;
}
for ( V_27 = 0 ; V_27 <= V_2 -> V_6 ; V_27 ++ ) {
unsigned long V_3 = V_4 [ V_27 ] . V_7 * 1000 ;
T_1 V_31 = V_4 [ V_27 ] . V_7 / 1000 ;
T_2 V_32 ;
T_1 V_33 ;
V_23 = F_12 ( V_25 , & V_3 ) ;
if ( F_13 ( V_23 ) ) {
F_14 ( V_25 , L_3 ,
V_3 ) ;
return - V_30 ;
}
V_33 = F_15 ( V_23 ) / 1000 ;
F_16 ( V_23 ) ;
V_32 = ( T_2 ) V_21 * V_31 * V_33 * V_33 ;
F_17 ( V_32 , 1000000000 ) ;
V_4 [ V_27 ] . V_32 = V_32 ;
}
return 0 ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
T_1 V_3 )
{
int V_27 ;
struct V_4 * V_4 = V_2 -> V_4 ;
for ( V_27 = 1 ; V_27 <= V_2 -> V_6 ; V_27 ++ )
if ( V_3 > V_4 [ V_27 ] . V_7 )
break;
return V_4 [ V_27 - 1 ] . V_32 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
T_1 V_32 )
{
int V_27 ;
struct V_4 * V_4 = V_2 -> V_4 ;
for ( V_27 = 1 ; V_27 <= V_2 -> V_6 ; V_27 ++ )
if ( V_32 > V_4 [ V_27 ] . V_32 )
break;
return V_4 [ V_27 - 1 ] . V_7 ;
}
static T_1 F_20 ( struct V_1 * V_2 , int V_18 ,
int V_34 )
{
T_1 V_35 ;
T_2 V_36 , V_37 , V_38 , V_39 ;
struct V_40 * V_41 = & V_2 -> V_41 [ V_34 ] ;
V_37 = F_21 ( V_18 , & V_36 , 0 ) ;
V_39 = V_37 - V_41 -> time ;
V_38 = V_36 - V_41 -> V_42 ;
if ( V_38 <= V_39 )
V_35 = 0 ;
else
V_35 = F_22 ( 100 * ( V_38 - V_39 ) , V_38 ) ;
V_41 -> time = V_37 ;
V_41 -> V_42 = V_36 ;
return V_35 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_43 * V_44 , unsigned long V_3 ,
T_1 * V_32 )
{
struct V_22 * V_23 ;
unsigned long V_45 ;
struct V_12 * V_13 = V_2 -> V_13 ;
struct V_46 * V_46 = V_13 -> V_47 ;
unsigned long V_48 = V_3 * 1000 ;
struct V_24 * V_25 ;
if ( ! V_2 -> V_49 ) {
* V_32 = 0 ;
return 0 ;
}
V_25 = F_8 ( V_13 -> V_18 ) ;
F_24 ( ! V_25 ) ;
V_23 = F_25 ( V_25 , V_48 , true ) ;
if ( F_13 ( V_23 ) ) {
F_26 ( V_25 , L_4 ,
V_48 , F_27 ( V_23 ) ) ;
return - V_30 ;
}
V_45 = F_15 ( V_23 ) ;
F_16 ( V_23 ) ;
if ( V_45 == 0 ) {
F_28 ( V_25 , L_5 ,
V_48 ) ;
return - V_30 ;
}
return V_2 -> V_49 ( V_46 , V_44 -> V_50 ,
V_45 , V_32 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_51 ;
V_51 = F_18 ( V_2 , V_3 ) ;
return ( V_51 * V_2 -> V_52 ) / 100 ;
}
static int F_30 ( struct V_53 * V_28 ,
unsigned long * V_54 )
{
struct V_1 * V_2 = V_28 -> V_55 ;
* V_54 = V_2 -> V_6 ;
return 0 ;
}
static int F_31 ( struct V_53 * V_28 ,
unsigned long * V_54 )
{
struct V_1 * V_2 = V_28 -> V_55 ;
* V_54 = V_2 -> V_56 ;
return 0 ;
}
static int F_32 ( struct V_53 * V_28 ,
unsigned long V_54 )
{
struct V_1 * V_2 = V_28 -> V_55 ;
unsigned int V_57 ;
if ( F_24 ( V_54 > V_2 -> V_6 ) )
return - V_30 ;
if ( V_2 -> V_56 == V_54 )
return 0 ;
V_57 = V_2 -> V_4 [ V_54 ] . V_7 ;
V_2 -> V_56 = V_54 ;
V_2 -> V_14 = V_57 ;
F_33 ( V_2 -> V_13 -> V_18 ) ;
return 0 ;
}
static int F_34 ( struct V_53 * V_28 ,
struct V_43 * V_44 ,
T_1 * V_32 )
{
unsigned long V_3 ;
int V_27 = 0 , V_18 , V_58 ;
T_1 V_59 , V_60 , V_61 = 0 ;
struct V_1 * V_2 = V_28 -> V_55 ;
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 * V_62 = NULL ;
V_3 = F_35 ( V_13 -> V_18 ) ;
if ( F_36 () ) {
T_1 V_63 = F_37 ( V_13 -> V_47 ) ;
V_62 = F_38 ( V_63 , sizeof( * V_62 ) , V_64 ) ;
}
F_39 (cpu, policy->related_cpus) {
T_1 V_35 ;
if ( F_40 ( V_18 ) )
V_35 = F_20 ( V_2 , V_18 , V_27 ) ;
else
V_35 = 0 ;
V_61 += V_35 ;
if ( F_41 () && V_62 )
V_62 [ V_27 ] = V_35 ;
V_27 ++ ;
}
V_2 -> V_52 = V_61 ;
V_60 = F_29 ( V_2 , V_3 ) ;
V_58 = F_23 ( V_2 , V_44 , V_3 , & V_59 ) ;
if ( V_58 ) {
F_42 ( V_62 ) ;
return V_58 ;
}
if ( V_62 ) {
F_43 ( V_13 -> V_47 , V_3 ,
V_62 , V_27 , V_60 ,
V_59 ) ;
F_42 ( V_62 ) ;
}
* V_32 = V_59 + V_60 ;
return 0 ;
}
static int F_44 ( struct V_53 * V_28 ,
struct V_43 * V_44 ,
unsigned long V_54 , T_1 * V_32 )
{
unsigned int V_3 , V_65 ;
T_1 V_59 , V_60 ;
int V_58 ;
struct V_1 * V_2 = V_28 -> V_55 ;
if ( F_24 ( V_54 > V_2 -> V_6 ) )
return - V_30 ;
V_65 = F_37 ( V_2 -> V_13 -> V_66 ) ;
V_3 = V_2 -> V_4 [ V_54 ] . V_7 ;
V_60 = F_18 ( V_2 , V_3 ) * V_65 ;
V_58 = F_23 ( V_2 , V_44 , V_3 , & V_59 ) ;
if ( V_58 )
return V_58 ;
* V_32 = V_59 + V_60 ;
return V_58 ;
}
static int F_45 ( struct V_53 * V_28 ,
struct V_43 * V_44 , T_1 V_32 ,
unsigned long * V_54 )
{
unsigned int V_67 , V_68 ;
int V_58 ;
T_3 V_69 ;
T_1 V_52 , V_70 , V_59 ;
struct V_1 * V_2 = V_28 -> V_55 ;
struct V_12 * V_13 = V_2 -> V_13 ;
V_67 = F_35 ( V_13 -> V_18 ) ;
V_58 = F_23 ( V_2 , V_44 , V_67 , & V_59 ) ;
if ( V_58 )
return V_58 ;
V_69 = V_32 - V_59 ;
V_69 = V_69 > 0 ? V_69 : 0 ;
V_52 = V_2 -> V_52 ? : 1 ;
V_70 = ( V_69 * 100 ) / V_52 ;
V_68 = F_19 ( V_2 , V_70 ) ;
* V_54 = F_1 ( V_2 , V_68 ) ;
F_46 ( V_13 -> V_47 , V_68 , * V_54 ,
V_32 ) ;
return 0 ;
}
static unsigned int F_47 ( struct V_71 * V_72 ,
unsigned int V_73 )
{
struct V_71 * V_74 ;
unsigned int V_19 = 0 ;
F_48 (pos, table) {
if ( V_74 -> V_7 > V_19 && V_74 -> V_7 < V_73 )
V_19 = V_74 -> V_7 ;
}
return V_19 ;
}
static struct V_53 *
F_49 ( struct V_75 * V_76 ,
struct V_12 * V_13 , T_1 V_21 ,
T_4 V_77 )
{
struct V_53 * V_28 ;
struct V_1 * V_2 ;
char V_78 [ V_79 ] ;
unsigned int V_3 , V_27 , V_65 ;
int V_58 ;
struct V_80 * V_81 ;
bool V_82 ;
if ( F_50 ( V_13 ) ) {
F_51 ( L_6 , V_83 , V_13 ) ;
return F_52 ( - V_30 ) ;
}
V_27 = F_53 ( V_13 ) ;
if ( ! V_27 ) {
F_54 ( L_7 ,
V_83 ) ;
return F_52 ( - V_29 ) ;
}
V_2 = F_55 ( sizeof( * V_2 ) , V_64 ) ;
if ( ! V_2 )
return F_52 ( - V_84 ) ;
V_2 -> V_13 = V_13 ;
V_65 = F_37 ( V_13 -> V_47 ) ;
V_2 -> V_41 = F_38 ( V_65 ,
sizeof( * V_2 -> V_41 ) ,
V_64 ) ;
if ( ! V_2 -> V_41 ) {
V_28 = F_52 ( - V_84 ) ;
goto V_85;
}
V_2 -> V_6 = V_27 - 1 ;
V_2 -> V_4 = F_56 ( V_27 ,
sizeof( * V_2 -> V_4 ) ,
V_64 ) ;
if ( ! V_2 -> V_4 ) {
V_28 = F_52 ( - V_84 ) ;
goto V_86;
}
V_58 = F_57 ( & V_87 , 0 , 0 , V_64 ) ;
if ( V_58 < 0 ) {
V_28 = F_52 ( V_58 ) ;
goto V_88;
}
V_2 -> V_89 = V_58 ;
snprintf ( V_78 , sizeof( V_78 ) , L_8 ,
V_2 -> V_89 ) ;
for ( V_27 = 0 , V_3 = - 1 ; V_27 <= V_2 -> V_6 ; V_27 ++ ) {
V_3 = F_47 ( V_13 -> V_4 , V_3 ) ;
V_2 -> V_4 [ V_27 ] . V_7 = V_3 ;
if ( ! V_3 )
F_58 ( L_9 , V_83 ) ;
else
F_54 ( L_10 , V_83 , V_3 ) ;
}
if ( V_21 ) {
V_2 -> V_49 = V_77 ;
V_58 = F_7 ( V_2 , V_21 ) ;
if ( V_58 ) {
V_28 = F_52 ( V_58 ) ;
goto V_90;
}
V_81 = & V_91 ;
} else {
V_81 = & V_92 ;
}
V_28 = F_59 ( V_76 , V_78 , V_2 ,
V_81 ) ;
if ( F_13 ( V_28 ) )
goto V_90;
V_2 -> V_14 = V_2 -> V_4 [ 0 ] . V_7 ;
V_2 -> V_28 = V_28 ;
F_3 ( & V_17 ) ;
V_82 = F_60 ( & V_93 ) ;
F_61 ( & V_2 -> V_94 , & V_93 ) ;
F_6 ( & V_17 ) ;
if ( V_82 )
F_62 ( & V_95 ,
V_96 ) ;
return V_28 ;
V_90:
F_63 ( & V_87 , V_2 -> V_89 ) ;
V_88:
F_42 ( V_2 -> V_4 ) ;
V_86:
F_42 ( V_2 -> V_41 ) ;
V_85:
F_42 ( V_2 ) ;
return V_28 ;
}
struct V_53 *
F_64 ( struct V_12 * V_13 )
{
return F_49 ( NULL , V_13 , 0 , NULL ) ;
}
struct V_53 *
F_65 ( struct V_75 * V_76 ,
struct V_12 * V_13 )
{
if ( ! V_76 )
return F_52 ( - V_30 ) ;
return F_49 ( V_76 , V_13 , 0 , NULL ) ;
}
struct V_53 *
F_66 ( struct V_12 * V_13 , T_1 V_21 ,
T_4 V_77 )
{
return F_49 ( NULL , V_13 , V_21 ,
V_77 ) ;
}
struct V_53 *
F_67 ( struct V_75 * V_76 ,
struct V_12 * V_13 ,
T_1 V_21 ,
T_4 V_77 )
{
if ( ! V_76 )
return F_52 ( - V_30 ) ;
return F_49 ( V_76 , V_13 , V_21 ,
V_77 ) ;
}
void F_68 ( struct V_53 * V_28 )
{
struct V_1 * V_2 ;
bool V_97 ;
if ( ! V_28 )
return;
V_2 = V_28 -> V_55 ;
F_3 ( & V_17 ) ;
F_69 ( & V_2 -> V_94 ) ;
V_97 = F_60 ( & V_93 ) ;
F_6 ( & V_17 ) ;
if ( V_97 )
F_70 ( & V_95 ,
V_96 ) ;
F_71 ( V_2 -> V_28 ) ;
F_63 ( & V_87 , V_2 -> V_89 ) ;
F_42 ( V_2 -> V_41 ) ;
F_42 ( V_2 -> V_4 ) ;
F_42 ( V_2 ) ;
}
