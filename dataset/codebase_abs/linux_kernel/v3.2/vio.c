static int F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 = 0 ;
V_2 = F_2 ( NULL , L_1 ) ;
if ( V_2 ) {
struct V_1 * V_4 ;
struct V_5 * V_6 ;
F_3 (node_vroot, of_node) {
V_6 = F_4 ( V_4 , L_2 ,
NULL ) ;
if ( V_6 )
V_3 ++ ;
}
}
F_5 ( V_2 ) ;
return V_3 ;
}
static inline int F_6 ( struct V_7 * V_8 , T_1 V_9 )
{
unsigned long V_10 ;
T_1 V_11 = 0 ;
T_1 V_12 = 0 ;
int V_13 = - V_14 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
if ( V_8 -> V_17 . V_18 > V_8 -> V_17 . V_19 )
V_11 = V_8 -> V_17 . V_18 - V_8 -> V_17 . V_19 ;
if ( V_15 . V_20 >= V_21 )
V_12 = V_15 . V_22 . free ;
if ( ( V_11 + V_12 ) >= V_9 ) {
V_15 . V_23 += V_9 ;
if ( V_15 . V_23 > V_15 . V_24 )
V_15 . V_24 = V_15 . V_23 ;
V_8 -> V_17 . V_19 += V_9 ;
V_9 -= F_8 ( V_11 , V_9 ) ;
V_15 . V_22 . free -= V_9 ;
V_13 = 0 ;
}
F_9 ( & V_15 . V_16 , V_10 ) ;
return V_13 ;
}
static inline void F_10 ( struct V_7 * V_8 , T_1 V_9 )
{
unsigned long V_10 ;
T_1 V_25 = 0 ;
T_1 V_26 = 0 ;
T_1 V_27 = V_9 ;
T_1 V_28 ;
int V_29 = 0 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
V_15 . V_23 -= V_9 ;
if ( V_8 -> V_17 . V_19 > V_8 -> V_17 . V_18 ) {
V_26 = F_8 ( V_27 , ( V_8 -> V_17 . V_19 -
V_8 -> V_17 . V_18 ) ) ;
V_27 -= V_26 ;
}
V_8 -> V_17 . V_19 -= ( V_27 + V_26 ) ;
V_25 = V_21 - V_15 . V_20 ;
if ( V_25 && V_26 ) {
V_28 = F_8 ( V_26 , V_25 ) ;
V_15 . V_22 . V_9 -= V_28 ;
V_15 . V_30 . V_9 += V_28 ;
V_15 . V_20 += V_28 ;
V_26 -= V_28 ;
V_25 -= V_28 ;
V_29 = 1 ;
}
if ( V_25 && V_27 ) {
V_28 = F_11 ( V_25 , V_27 , ( V_8 -> V_17 . V_18 - V_21 ) ) ;
V_15 . V_20 += V_28 ;
V_8 -> V_17 . V_18 -= V_28 ;
V_27 -= V_28 ;
V_25 -= V_28 ;
V_29 = 1 ;
}
if ( V_26 && ( V_15 . V_31 > V_15 . V_30 . V_9 ) ) {
V_28 = F_8 ( V_26 , ( V_15 . V_31 - V_15 . V_30 . V_9 ) ) ;
V_15 . V_22 . V_9 -= V_28 ;
V_15 . V_30 . V_9 += V_28 ;
V_26 -= V_28 ;
V_29 = 1 ;
}
if ( V_26 )
V_15 . V_22 . free += V_26 ;
if ( V_29 )
F_12 ( & V_15 . V_32 , V_33 ) ;
F_9 ( & V_15 . V_16 , V_10 ) ;
}
int F_13 ( T_1 V_34 )
{
struct V_7 * V_8 ;
struct V_35 * V_36 ;
unsigned long V_10 ;
T_1 V_37 , V_38 , V_28 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
if ( V_34 > V_15 . V_18 ) {
V_38 = V_34 - V_15 . V_18 ;
if ( V_15 . V_20 < V_21 ) {
V_28 = F_8 ( V_38 , ( V_21 - V_15 . V_20 ) ) ;
V_15 . V_20 += V_28 ;
V_15 . V_30 . V_9 += V_28 ;
V_38 -= V_28 ;
}
V_15 . V_18 += V_38 ;
V_15 . V_22 . V_9 += V_38 ;
V_15 . V_22 . free += V_38 ;
goto V_39;
}
V_38 = V_15 . V_18 - V_34 ;
V_37 = V_15 . V_22 . free ;
F_14 (dev_ent, &vio_cmo.device_list, list) {
if ( V_37 >= V_38 )
break;
V_8 = V_36 -> V_8 ;
if ( ( V_8 -> V_17 . V_18 > V_8 -> V_17 . V_19 ) &&
( V_8 -> V_17 . V_18 > V_21 ) )
V_37 += V_8 -> V_17 . V_18 -
F_15 ( T_1 , V_8 -> V_17 . V_19 ,
V_21 ) ;
}
if ( V_38 <= V_37 ) {
V_15 . V_18 -= V_38 ;
V_28 = F_8 ( V_15 . V_22 . free , V_38 ) ;
V_15 . V_22 . V_9 -= V_28 ;
V_15 . V_22 . free -= V_28 ;
V_38 -= V_28 ;
F_14 (dev_ent, &vio_cmo.device_list, list) {
if ( ! V_38 )
break;
V_8 = V_36 -> V_8 ;
V_28 = 0 ;
if ( ( V_8 -> V_17 . V_18 > V_8 -> V_17 . V_19 ) &&
( V_8 -> V_17 . V_18 > V_21 ) )
V_28 = V_8 -> V_17 . V_18 -
F_15 ( T_1 , V_8 -> V_17 . V_19 ,
V_21 ) ;
V_8 -> V_17 . V_18 -= F_8 ( V_28 , V_38 ) ;
V_38 -= F_8 ( V_28 , V_38 ) ;
}
} else {
F_9 ( & V_15 . V_16 , V_10 ) ;
return - V_14 ;
}
V_39:
F_12 ( & V_15 . V_32 , 0 ) ;
F_9 ( & V_15 . V_16 , V_10 ) ;
return 0 ;
}
static void F_16 ( struct V_40 * V_41 )
{
struct V_15 * V_17 ;
struct V_7 * V_8 ;
struct V_35 * V_36 ;
unsigned long V_10 ;
T_1 V_37 = 0 , V_42 , V_43 , V_44 ;
int V_45 = 0 , V_46 ;
V_17 = F_17 ( V_41 , struct V_15 , V_32 . V_41 ) ;
F_7 ( & V_15 . V_16 , V_10 ) ;
V_17 -> F_8 = F_1 () * V_21 ;
F_18 ( V_17 -> F_8 > V_17 -> V_18 ) ;
V_17 -> V_20 = F_19 ( T_1 , V_21 , ( V_17 -> V_18 - V_17 -> F_8 ) ) ;
V_17 -> F_8 += V_17 -> V_20 ;
V_17 -> V_31 = V_17 -> F_8 ;
V_37 = V_17 -> V_18 - V_17 -> V_20 ;
F_14 (dev_ent, &vio_cmo.device_list, list) {
V_8 = V_36 -> V_8 ;
V_45 ++ ;
V_8 -> V_17 . V_18 = V_21 ;
V_17 -> V_31 += ( V_8 -> V_17 . V_31 - V_21 ) ;
V_37 -= F_15 ( T_1 , V_8 -> V_17 . V_19 , V_21 ) ;
}
V_42 = V_21 ;
while ( V_37 ) {
V_46 = 0 ;
F_14 (dev_ent, &vio_cmo.device_list, list) {
V_8 = V_36 -> V_8 ;
if ( V_8 -> V_17 . V_31 <= V_42 ) {
V_46 ++ ;
continue;
}
V_43 = F_19 ( T_1 , V_37 , V_47 ) ;
V_43 = F_8 ( V_43 , ( V_8 -> V_17 . V_31 -
V_8 -> V_17 . V_18 ) ) ;
V_8 -> V_17 . V_18 += V_43 ;
V_44 = F_20 ( V_8 -> V_17 . V_19 , V_8 -> V_17 . V_18 ) -
F_20 ( V_8 -> V_17 . V_19 , V_42 ) ;
V_37 -= V_44 ;
}
if ( V_46 == V_45 )
break;
V_42 += V_47 ;
}
V_17 -> V_30 . V_9 = V_17 -> F_8 ;
V_17 -> V_22 . free = 0 ;
V_17 -> V_22 . V_9 = 0 ;
V_44 = 0 ;
F_14 (dev_ent, &vio_cmo.device_list, list) {
V_8 = V_36 -> V_8 ;
if ( V_8 -> V_17 . V_18 )
V_17 -> V_30 . V_9 += ( V_8 -> V_17 . V_18 -
V_21 ) ;
if ( V_8 -> V_17 . V_19 > V_8 -> V_17 . V_18 )
V_44 += V_8 -> V_17 . V_19 - V_8 -> V_17 . V_18 ;
}
V_17 -> V_22 . V_9 = V_17 -> V_18 - V_17 -> V_30 . V_9 ;
V_17 -> V_22 . free = V_17 -> V_22 . V_9 - V_44 ;
F_21 ( F_22 ( V_41 ) ) ;
F_9 ( & V_15 . V_16 , V_10 ) ;
}
static void * F_23 ( struct V_48 * V_49 , T_1 V_9 ,
T_2 * V_50 , T_3 V_51 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
void * V_13 ;
if ( F_6 ( V_8 , F_25 ( V_9 , V_52 ) ) ) {
F_26 ( & V_8 -> V_17 . V_53 ) ;
return NULL ;
}
V_13 = V_54 . V_55 ( V_49 , V_9 , V_50 , V_51 ) ;
if ( F_27 ( V_13 == NULL ) ) {
F_10 ( V_8 , F_25 ( V_9 , V_52 ) ) ;
F_26 ( & V_8 -> V_17 . V_53 ) ;
}
return V_13 ;
}
static void F_28 ( struct V_48 * V_49 , T_1 V_9 ,
void * V_56 , T_2 V_50 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
V_54 . V_57 ( V_49 , V_9 , V_56 , V_50 ) ;
F_10 ( V_8 , F_25 ( V_9 , V_52 ) ) ;
}
static T_2 F_29 ( struct V_48 * V_49 , struct V_58 * V_58 ,
unsigned long V_59 , T_1 V_9 ,
enum V_60 V_61 ,
struct V_62 * V_63 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
T_2 V_13 = V_64 ;
if ( F_6 ( V_8 , F_25 ( V_9 , V_65 ) ) ) {
F_26 ( & V_8 -> V_17 . V_53 ) ;
return V_13 ;
}
V_13 = V_54 . V_66 ( V_49 , V_58 , V_59 , V_9 , V_61 , V_63 ) ;
if ( F_27 ( F_30 ( V_49 , V_13 ) ) ) {
F_10 ( V_8 , F_25 ( V_9 , V_65 ) ) ;
F_26 ( & V_8 -> V_17 . V_53 ) ;
}
return V_13 ;
}
static void F_31 ( struct V_48 * V_49 , T_2 V_50 ,
T_1 V_9 ,
enum V_60 V_61 ,
struct V_62 * V_63 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
V_54 . V_67 ( V_49 , V_50 , V_9 , V_61 , V_63 ) ;
F_10 ( V_8 , F_25 ( V_9 , V_65 ) ) ;
}
static int F_32 ( struct V_48 * V_49 , struct V_68 * V_69 ,
int V_70 , enum V_60 V_61 ,
struct V_62 * V_63 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_68 * V_71 ;
int V_13 , V_3 = 0 ;
T_1 V_72 = 0 ;
for ( V_71 = V_69 ; V_3 < V_70 ; V_3 ++ , V_71 ++ )
V_72 += F_25 ( V_71 -> V_73 , V_65 ) ;
if ( F_6 ( V_8 , V_72 ) ) {
F_26 ( & V_8 -> V_17 . V_53 ) ;
return 0 ;
}
V_13 = V_54 . V_74 ( V_49 , V_69 , V_70 , V_61 , V_63 ) ;
if ( F_27 ( ! V_13 ) ) {
F_10 ( V_8 , V_72 ) ;
F_26 ( & V_8 -> V_17 . V_53 ) ;
return V_13 ;
}
for ( V_71 = V_69 , V_3 = 0 ; V_3 < V_13 ; V_3 ++ , V_71 ++ )
V_72 -= F_25 ( V_71 -> V_75 , V_65 ) ;
if ( V_72 )
F_10 ( V_8 , V_72 ) ;
return V_13 ;
}
static void F_33 ( struct V_48 * V_49 ,
struct V_68 * V_69 , int V_70 ,
enum V_60 V_61 ,
struct V_62 * V_63 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_68 * V_71 ;
T_1 V_72 = 0 ;
int V_3 = 0 ;
for ( V_71 = V_69 ; V_3 < V_70 ; V_3 ++ , V_71 ++ )
V_72 += F_25 ( V_71 -> V_75 , V_65 ) ;
V_54 . V_76 ( V_49 , V_69 , V_70 , V_61 , V_63 ) ;
F_10 ( V_8 , V_72 ) ;
}
static int F_34 ( struct V_48 * V_49 , T_4 V_77 )
{
return V_54 . V_78 ( V_49 , V_77 ) ;
}
static T_4 F_35 ( struct V_48 * V_49 )
{
return V_54 . V_79 ( V_49 ) ;
}
void F_36 ( struct V_7 * V_8 , T_1 V_31 )
{
unsigned long V_10 ;
struct V_35 * V_36 ;
int V_80 = 0 ;
if ( ! F_37 ( V_81 ) )
return;
F_7 ( & V_15 . V_16 , V_10 ) ;
if ( V_31 < V_21 )
V_31 = V_21 ;
F_14 (dev_ent, &vio_cmo.device_list, list)
if ( V_8 == V_36 -> V_8 ) {
V_80 = 1 ;
break;
}
if ( ! V_80 ) {
F_9 ( & V_15 . V_16 , V_10 ) ;
return;
}
if ( V_31 >= V_8 -> V_17 . V_31 ) {
V_15 . V_31 += V_31 - V_8 -> V_17 . V_31 ;
V_8 -> V_17 . V_31 = V_31 ;
} else {
V_15 . V_31 -= V_8 -> V_17 . V_31 - V_31 ;
V_8 -> V_17 . V_31 = V_31 ;
if ( V_8 -> V_17 . V_18 > V_31 ) {
V_15 . V_30 . V_9 -= V_8 -> V_17 . V_18 - V_31 ;
V_15 . V_22 . V_9 += V_8 -> V_17 . V_18 - V_31 ;
if ( V_8 -> V_17 . V_19 < V_8 -> V_17 . V_18 )
V_15 . V_22 . free += V_8 -> V_17 . V_18 -
F_20 ( V_8 -> V_17 . V_19 , V_31 ) ;
V_8 -> V_17 . V_18 = V_31 ;
}
}
F_12 ( & V_15 . V_32 , 0 ) ;
F_9 ( & V_15 . V_16 , V_10 ) ;
}
static int F_38 ( struct V_7 * V_8 )
{
struct V_35 * V_36 ;
struct V_48 * V_49 = & V_8 -> V_49 ;
struct V_82 * V_83 = F_39 ( V_49 -> V_84 ) ;
unsigned long V_10 ;
T_1 V_9 ;
if ( F_40 ( V_8 -> V_49 . V_4 ,
L_2 , NULL ) ) {
if ( ! V_83 -> V_85 ) {
F_41 ( V_49 , L_3 ,
V_86 ) ;
return - V_87 ;
}
V_8 -> V_17 . V_31 = F_42 ( V_83 -> V_85 ( V_8 ) ) ;
if ( V_8 -> V_17 . V_31 < V_21 )
V_8 -> V_17 . V_31 = V_21 ;
V_9 = V_21 ;
V_36 = F_43 ( sizeof( struct V_35 ) ,
V_88 ) ;
if ( ! V_36 )
return - V_14 ;
V_36 -> V_8 = V_8 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
F_44 ( & V_36 -> V_89 , & V_15 . V_90 ) ;
} else {
V_8 -> V_17 . V_31 = 0 ;
V_9 = 0 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
}
if ( V_15 . F_8 == ( ( F_1 () + 1 ) *
V_21 ) ) {
if ( V_9 )
V_15 . V_31 += ( V_8 -> V_17 . V_31 -
V_21 ) ;
} else {
T_1 V_28 ;
V_28 = V_15 . V_20 + V_15 . V_22 . free ;
if ( V_28 < V_9 ) {
F_41 ( V_49 , L_4
L_5
L_6 , V_86 ,
V_9 , ( V_15 . V_20 + V_28 ) ) ;
F_9 ( & V_15 . V_16 , V_10 ) ;
return - V_14 ;
}
V_28 = F_8 ( V_9 , V_15 . V_22 . free ) ;
V_15 . V_22 . free -= V_28 ;
V_15 . V_22 . V_9 -= V_28 ;
V_15 . V_30 . V_9 += V_28 ;
V_15 . V_20 -= V_9 - V_28 ;
V_15 . F_8 += V_9 ;
V_15 . V_31 += V_8 -> V_17 . V_31 ;
}
F_9 ( & V_15 . V_16 , V_10 ) ;
return 0 ;
}
static void F_45 ( struct V_7 * V_8 )
{
struct V_35 * V_36 ;
unsigned long V_10 ;
T_1 V_28 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
if ( V_8 -> V_17 . V_19 ) {
F_41 ( & V_8 -> V_49 , L_7
L_8 ,
V_86 , V_8 -> V_17 . V_19 ) ;
F_46 () ;
}
F_14 (dev_ent, &vio_cmo.device_list, list)
if ( V_8 == V_36 -> V_8 ) {
F_47 ( & V_36 -> V_89 ) ;
F_48 ( V_36 ) ;
break;
}
if ( V_8 -> V_17 . V_18 ) {
V_15 . V_31 -= ( V_8 -> V_17 . V_31 - V_21 ) ;
V_8 -> V_17 . V_18 -= V_21 ;
if ( V_8 -> V_17 . V_18 && ( V_15 . V_20 < V_21 ) ) {
V_28 = F_8 ( V_8 -> V_17 . V_18 , ( V_21 -
V_15 . V_20 ) ) ;
V_15 . V_20 += V_28 ;
V_8 -> V_17 . V_18 -= V_28 ;
}
V_15 . V_22 . V_9 += V_8 -> V_17 . V_18 ;
V_15 . V_22 . free += V_8 -> V_17 . V_18 ;
V_15 . V_30 . V_9 -= V_8 -> V_17 . V_18 ;
V_8 -> V_17 . V_18 = V_21 ;
V_8 -> V_17 . V_31 = V_21 ;
F_49 ( & V_8 -> V_17 . V_53 , 0 ) ;
}
F_9 ( & V_15 . V_16 , V_10 ) ;
}
static void F_50 ( struct V_7 * V_8 )
{
F_51 ( & V_8 -> V_49 , & V_91 ) ;
}
static void F_52 ( void )
{
struct V_92 V_93 ;
int V_94 ;
memset ( & V_15 , 0 , sizeof( struct V_15 ) ) ;
F_53 ( & V_15 . V_16 ) ;
F_54 ( & V_15 . V_90 ) ;
F_55 ( & V_15 . V_32 , F_16 ) ;
V_94 = F_56 ( & V_93 ) ;
if ( V_94 != V_95 ) {
F_57 ( V_96 L_9\
L_10 , V_86 , V_94 ) ;
V_15 . V_18 = 0 ;
} else {
V_15 . V_18 = V_93 . V_97 ;
}
V_15 . V_20 = V_21 ;
V_15 . V_30 . V_9 = V_15 . V_20 ;
V_15 . V_30 . V_9 += ( F_1 () *
V_21 ) ;
if ( V_15 . V_30 . V_9 > V_15 . V_18 ) {
F_57 ( V_96 L_11 ,
V_86 ) ;
F_58 ( L_12 , V_86 ) ;
}
V_15 . V_22 . V_9 = V_15 . V_18 - V_15 . V_30 . V_9 ;
V_15 . V_22 . free = V_15 . V_22 . V_9 ;
V_15 . F_8 = V_15 . V_30 . V_9 ;
V_15 . V_31 = V_15 . V_30 . V_9 ;
}
static T_5 F_59 ( struct V_48 * V_49 ,
struct V_98 * V_99 , char * V_100 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
return sprintf ( V_100 , L_13 , F_60 ( & V_8 -> V_17 . V_53 ) ) ;
}
static T_5 F_61 ( struct V_48 * V_49 ,
struct V_98 * V_99 , const char * V_100 , T_1 V_3 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
F_49 ( & V_8 -> V_17 . V_53 , 0 ) ;
return V_3 ;
}
static T_5 F_62 ( struct V_48 * V_49 ,
struct V_98 * V_99 , const char * V_100 , T_1 V_3 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
T_1 V_101 ;
int V_13 ;
V_13 = F_63 ( V_100 , 10 , & V_101 ) ;
if ( V_13 )
return V_13 ;
F_36 ( V_8 , V_101 ) ;
return V_3 ;
}
static T_5 F_64 ( struct V_102 * V_103 , const char * V_100 ,
T_1 V_3 )
{
unsigned long V_10 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
V_15 . V_24 = V_15 . V_23 ;
F_9 ( & V_15 . V_16 , V_10 ) ;
return V_3 ;
}
static void F_65 ( void )
{
V_104 . V_105 = V_106 ;
V_104 . V_107 = V_108 ;
}
int F_13 ( T_1 V_34 ) { return 0 ; }
void F_36 ( struct V_7 * V_8 , T_1 V_31 ) {}
static int F_38 ( struct V_7 * V_8 ) { return 0 ; }
static void F_45 ( struct V_7 * V_8 ) {}
static void F_50 ( struct V_7 * V_8 ) {}
static void F_52 ( void ) {}
static void F_65 ( void ) { }
static struct V_109 * F_66 ( struct V_7 * V_49 )
{
const unsigned char * V_110 ;
struct V_109 * V_111 ;
unsigned long V_59 , V_9 ;
if ( F_37 ( V_112 ) )
return F_67 ( V_49 ) ;
V_110 = F_40 ( V_49 -> V_49 . V_4 ,
L_2 , NULL ) ;
if ( ! V_110 )
return NULL ;
V_111 = F_68 ( sizeof( * V_111 ) , V_88 ) ;
if ( V_111 == NULL )
return NULL ;
F_69 ( V_49 -> V_49 . V_4 , V_110 ,
& V_111 -> V_113 , & V_59 , & V_9 ) ;
V_111 -> V_114 = V_9 >> V_115 ;
V_111 -> V_116 = V_59 >> V_115 ;
V_111 -> V_117 = 0 ;
V_111 -> V_118 = V_119 ;
V_111 -> V_120 = 16 ;
return F_70 ( V_111 , - 1 ) ;
}
static const struct V_121 * F_71 (
const struct V_121 * V_122 , const struct V_7 * V_49 )
{
while ( V_122 -> type [ 0 ] != '\0' ) {
if ( ( strncmp ( V_49 -> type , V_122 -> type , strlen ( V_122 -> type ) ) == 0 ) &&
F_72 ( V_49 -> V_49 . V_4 ,
V_122 -> V_123 ) )
return V_122 ;
V_122 ++ ;
}
return NULL ;
}
static int F_73 ( struct V_48 * V_49 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_82 * V_83 = F_39 ( V_49 -> V_84 ) ;
const struct V_121 * V_124 ;
int error = - V_125 ;
if ( ! V_83 -> V_126 )
return error ;
V_124 = F_71 ( V_83 -> V_127 , V_8 ) ;
if ( V_124 ) {
memset ( & V_8 -> V_17 , 0 , sizeof( V_8 -> V_17 ) ) ;
if ( F_37 ( V_81 ) ) {
error = F_38 ( V_8 ) ;
if ( error )
return error ;
}
error = V_83 -> V_126 ( V_8 , V_124 ) ;
if ( error && F_37 ( V_81 ) )
F_45 ( V_8 ) ;
}
return error ;
}
static int F_74 ( struct V_48 * V_49 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_82 * V_83 = F_39 ( V_49 -> V_84 ) ;
struct V_48 * V_128 ;
int V_13 = 1 ;
V_128 = F_75 ( V_49 ) ;
if ( V_83 -> remove )
V_13 = V_83 -> remove ( V_8 ) ;
if ( ! V_13 && F_37 ( V_81 ) )
F_45 ( V_8 ) ;
F_76 ( V_128 ) ;
return V_13 ;
}
int F_77 ( struct V_82 * V_83 )
{
F_57 ( V_129 L_14 , V_86 ,
V_83 -> V_84 . V_130 ) ;
V_83 -> V_84 . V_131 = & V_104 ;
return F_78 ( & V_83 -> V_84 ) ;
}
void F_79 ( struct V_82 * V_83 )
{
F_80 ( & V_83 -> V_84 ) ;
}
static void T_6 F_81 ( struct V_48 * V_49 )
{
struct V_109 * V_111 = F_82 ( V_49 ) ;
if ( ! F_37 ( V_112 ) && V_111 )
F_83 ( V_111 , V_49 -> V_4 ?
V_49 -> V_4 -> V_132 : F_84 ( V_49 ) ) ;
F_5 ( V_49 -> V_4 ) ;
F_48 ( F_24 ( V_49 ) ) ;
}
struct V_7 * F_85 ( struct V_1 * V_4 )
{
struct V_7 * V_8 ;
const unsigned int * V_133 ;
if ( V_4 -> type == NULL ) {
F_57 ( V_134 L_15 ,
V_86 ,
V_4 -> V_130 ? V_4 -> V_130 : L_16 ) ;
return NULL ;
}
V_133 = F_40 ( V_4 , L_17 , NULL ) ;
if ( V_133 == NULL ) {
F_57 ( V_134 L_18 ,
V_86 ,
V_4 -> V_130 ? V_4 -> V_130 : L_16 ) ;
return NULL ;
}
V_8 = F_68 ( sizeof( struct V_7 ) , V_88 ) ;
if ( V_8 == NULL )
return NULL ;
V_8 -> V_135 = F_86 ( V_4 , 0 ) ;
F_87 ( & V_8 -> V_49 , L_19 , * V_133 ) ;
V_8 -> V_130 = V_4 -> V_130 ;
V_8 -> type = V_4 -> type ;
V_8 -> V_133 = * V_133 ;
if ( F_37 ( V_112 ) ) {
V_133 = F_40 ( V_4 ,
L_20 , NULL ) ;
if ( V_133 != NULL )
V_8 -> V_133 = * V_133 ;
}
V_8 -> V_49 . V_4 = F_88 ( V_4 ) ;
if ( F_37 ( V_81 ) )
F_50 ( V_8 ) ;
else
F_51 ( & V_8 -> V_49 , & V_54 ) ;
F_89 ( & V_8 -> V_49 , F_66 ( V_8 ) ) ;
F_90 ( & V_8 -> V_49 , F_91 ( V_4 ) ) ;
V_8 -> V_49 . V_136 = & V_137 . V_49 ;
V_8 -> V_49 . V_131 = & V_104 ;
V_8 -> V_49 . V_138 = F_81 ;
F_92 ( & V_8 -> V_49 , F_93 ( 64 ) ) ;
F_94 ( & V_8 -> V_49 , F_93 ( 64 ) ) ;
if ( F_95 ( & V_8 -> V_49 ) ) {
F_57 ( V_96 L_21 ,
V_86 , F_84 ( & V_8 -> V_49 ) ) ;
F_76 ( & V_8 -> V_49 ) ;
return NULL ;
}
return V_8 ;
}
static int T_7 F_96 ( void )
{
int V_94 ;
struct V_1 * V_2 ;
if ( F_37 ( V_81 ) )
F_65 () ;
V_94 = F_97 ( & V_104 ) ;
if ( V_94 ) {
F_57 ( V_96 L_22 ) ;
return V_94 ;
}
V_94 = F_95 ( & V_137 . V_49 ) ;
if ( V_94 ) {
F_57 ( V_134 L_23 ,
V_86 , V_94 ) ;
return V_94 ;
}
if ( F_37 ( V_81 ) )
F_52 () ;
V_2 = F_2 ( NULL , L_1 ) ;
if ( V_2 ) {
struct V_1 * V_4 ;
for ( V_4 = V_2 -> V_139 ; V_4 != NULL ;
V_4 = V_4 -> V_140 )
F_85 ( V_4 ) ;
F_5 ( V_2 ) ;
}
return 0 ;
}
static T_5 F_98 ( struct V_48 * V_49 ,
struct V_98 * V_99 , char * V_100 )
{
return sprintf ( V_100 , L_24 , F_24 ( V_49 ) -> V_130 ) ;
}
static T_5 F_99 ( struct V_48 * V_49 ,
struct V_98 * V_99 , char * V_100 )
{
struct V_1 * V_4 = V_49 -> V_4 ;
return sprintf ( V_100 , L_24 , V_4 ? V_4 -> V_132 : L_25 ) ;
}
static T_5 F_100 ( struct V_48 * V_49 , struct V_98 * V_99 ,
char * V_100 )
{
const struct V_7 * V_7 = F_24 ( V_49 ) ;
struct V_1 * V_141 ;
const char * V_142 ;
V_141 = V_49 -> V_4 ;
if ( ! V_141 )
return - V_125 ;
V_142 = F_40 ( V_141 , L_26 , NULL ) ;
if ( ! V_142 )
return - V_125 ;
return sprintf ( V_100 , L_27 , V_7 -> type , V_142 ) ;
}
void T_6 F_101 ( struct V_7 * V_8 )
{
F_102 ( & V_8 -> V_49 ) ;
}
static int F_103 ( struct V_48 * V_49 , struct V_143 * V_144 )
{
const struct V_7 * V_7 = F_24 ( V_49 ) ;
struct V_82 * V_145 = F_39 ( V_144 ) ;
const struct V_121 * V_122 = V_145 -> V_127 ;
return ( V_122 != NULL ) && ( F_71 ( V_122 , V_7 ) != NULL ) ;
}
static int F_104 ( struct V_48 * V_49 , struct V_146 * V_147 )
{
const struct V_7 * V_7 = F_24 ( V_49 ) ;
struct V_1 * V_141 ;
const char * V_142 ;
V_141 = V_49 -> V_4 ;
if ( ! V_141 )
return - V_125 ;
V_142 = F_40 ( V_141 , L_26 , NULL ) ;
if ( ! V_142 )
return - V_125 ;
F_105 ( V_147 , L_28 , V_7 -> type , V_142 ) ;
return 0 ;
}
const void * F_106 ( struct V_7 * V_148 , char * V_149 , int * V_73 )
{
return F_40 ( V_148 -> V_49 . V_4 , V_149 , V_73 ) ;
}
static struct V_7 * F_107 ( const char * V_130 )
{
struct V_48 * V_80 ;
V_80 = F_108 ( & V_104 , NULL , V_130 ) ;
if ( ! V_80 )
return NULL ;
return F_24 ( V_80 ) ;
}
struct V_7 * F_109 ( struct V_1 * V_150 )
{
const T_8 * V_133 ;
char V_151 [ 20 ] ;
V_133 = F_40 ( V_150 , L_17 , NULL ) ;
if ( ! V_133 )
return NULL ;
snprintf ( V_151 , sizeof( V_151 ) , L_19 , * V_133 ) ;
return F_107 ( V_151 ) ;
}
int F_110 ( struct V_7 * V_49 )
{
int V_152 = F_111 ( V_49 -> V_133 , V_153 ) ;
if ( V_152 != V_95 )
F_57 ( V_96 L_29 , V_152 ) ;
return V_152 ;
}
int F_112 ( struct V_7 * V_49 )
{
int V_152 = F_111 ( V_49 -> V_133 , V_154 ) ;
if ( V_152 != V_95 )
F_57 ( V_96 L_30 , V_152 ) ;
return V_152 ;
}
