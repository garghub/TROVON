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
T_2 * V_50 , T_3 V_51 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
void * V_13 ;
if ( F_6 ( V_8 , F_25 ( V_9 , V_54 ) ) ) {
F_26 ( & V_8 -> V_17 . V_55 ) ;
return NULL ;
}
V_13 = V_56 . V_57 ( V_49 , V_9 , V_50 , V_51 , V_53 ) ;
if ( F_27 ( V_13 == NULL ) ) {
F_10 ( V_8 , F_25 ( V_9 , V_54 ) ) ;
F_26 ( & V_8 -> V_17 . V_55 ) ;
}
return V_13 ;
}
static void F_28 ( struct V_48 * V_49 , T_1 V_9 ,
void * V_58 , T_2 V_50 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
V_56 . free ( V_49 , V_9 , V_58 , V_50 , V_53 ) ;
F_10 ( V_8 , F_25 ( V_9 , V_54 ) ) ;
}
static T_2 F_29 ( struct V_48 * V_49 , struct V_59 * V_59 ,
unsigned long V_60 , T_1 V_9 ,
enum V_61 V_62 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
T_2 V_13 = V_63 ;
if ( F_6 ( V_8 , F_25 ( V_9 , V_64 ) ) ) {
F_26 ( & V_8 -> V_17 . V_55 ) ;
return V_13 ;
}
V_13 = V_56 . V_65 ( V_49 , V_59 , V_60 , V_9 , V_62 , V_53 ) ;
if ( F_27 ( F_30 ( V_49 , V_13 ) ) ) {
F_10 ( V_8 , F_25 ( V_9 , V_64 ) ) ;
F_26 ( & V_8 -> V_17 . V_55 ) ;
}
return V_13 ;
}
static void F_31 ( struct V_48 * V_49 , T_2 V_50 ,
T_1 V_9 ,
enum V_61 V_62 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
V_56 . V_66 ( V_49 , V_50 , V_9 , V_62 , V_53 ) ;
F_10 ( V_8 , F_25 ( V_9 , V_64 ) ) ;
}
static int F_32 ( struct V_48 * V_49 , struct V_67 * V_68 ,
int V_69 , enum V_61 V_62 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_67 * V_70 ;
int V_13 , V_3 = 0 ;
T_1 V_71 = 0 ;
for ( V_70 = V_68 ; V_3 < V_69 ; V_3 ++ , V_70 ++ )
V_71 += F_25 ( V_70 -> V_72 , V_64 ) ;
if ( F_6 ( V_8 , V_71 ) ) {
F_26 ( & V_8 -> V_17 . V_55 ) ;
return 0 ;
}
V_13 = V_56 . V_73 ( V_49 , V_68 , V_69 , V_62 , V_53 ) ;
if ( F_27 ( ! V_13 ) ) {
F_10 ( V_8 , V_71 ) ;
F_26 ( & V_8 -> V_17 . V_55 ) ;
return V_13 ;
}
for ( V_70 = V_68 , V_3 = 0 ; V_3 < V_13 ; V_3 ++ , V_70 ++ )
V_71 -= F_25 ( V_70 -> V_74 , V_64 ) ;
if ( V_71 )
F_10 ( V_8 , V_71 ) ;
return V_13 ;
}
static void F_33 ( struct V_48 * V_49 ,
struct V_67 * V_68 , int V_69 ,
enum V_61 V_62 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_67 * V_70 ;
T_1 V_71 = 0 ;
int V_3 = 0 ;
for ( V_70 = V_68 ; V_3 < V_69 ; V_3 ++ , V_70 ++ )
V_71 += F_25 ( V_70 -> V_74 , V_64 ) ;
V_56 . V_75 ( V_49 , V_68 , V_69 , V_62 , V_53 ) ;
F_10 ( V_8 , V_71 ) ;
}
static int F_34 ( struct V_48 * V_49 , T_4 V_76 )
{
return V_56 . V_77 ( V_49 , V_76 ) ;
}
static T_4 F_35 ( struct V_48 * V_49 )
{
return V_56 . V_78 ( V_49 ) ;
}
void F_36 ( struct V_7 * V_8 , T_1 V_31 )
{
unsigned long V_10 ;
struct V_35 * V_36 ;
int V_79 = 0 ;
if ( ! F_37 ( V_80 ) )
return;
F_7 ( & V_15 . V_16 , V_10 ) ;
if ( V_31 < V_21 )
V_31 = V_21 ;
F_14 (dev_ent, &vio_cmo.device_list, list)
if ( V_8 == V_36 -> V_8 ) {
V_79 = 1 ;
break;
}
if ( ! V_79 ) {
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
struct V_81 * V_82 = F_39 ( V_49 -> V_83 ) ;
unsigned long V_10 ;
T_1 V_9 ;
if ( F_40 ( V_8 -> V_49 . V_4 ,
L_2 , NULL ) ) {
if ( ! V_82 -> V_84 ) {
F_41 ( V_49 , L_3 ,
V_85 ) ;
return - V_86 ;
}
V_8 -> V_17 . V_31 = F_42 ( V_82 -> V_84 ( V_8 ) ) ;
if ( V_8 -> V_17 . V_31 < V_21 )
V_8 -> V_17 . V_31 = V_21 ;
V_9 = V_21 ;
V_36 = F_43 ( sizeof( struct V_35 ) ,
V_87 ) ;
if ( ! V_36 )
return - V_14 ;
V_36 -> V_8 = V_8 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
F_44 ( & V_36 -> V_88 , & V_15 . V_89 ) ;
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
L_6 , V_85 ,
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
V_85 , V_8 -> V_17 . V_19 ) ;
F_46 () ;
}
F_14 (dev_ent, &vio_cmo.device_list, list)
if ( V_8 == V_36 -> V_8 ) {
F_47 ( & V_36 -> V_88 ) ;
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
F_49 ( & V_8 -> V_17 . V_55 , 0 ) ;
}
F_9 ( & V_15 . V_16 , V_10 ) ;
}
static void F_50 ( struct V_7 * V_8 )
{
F_51 ( & V_8 -> V_49 , & V_90 ) ;
}
static void F_52 ( void )
{
struct V_91 V_92 ;
int V_93 ;
memset ( & V_15 , 0 , sizeof( struct V_15 ) ) ;
F_53 ( & V_15 . V_16 ) ;
F_54 ( & V_15 . V_89 ) ;
F_55 ( & V_15 . V_32 , F_16 ) ;
V_93 = F_56 ( & V_92 ) ;
if ( V_93 != V_94 ) {
F_57 ( V_95 L_9\
L_10 , V_85 , V_93 ) ;
V_15 . V_18 = 0 ;
} else {
V_15 . V_18 = V_92 . V_96 ;
}
V_15 . V_20 = V_21 ;
V_15 . V_30 . V_9 = V_15 . V_20 ;
V_15 . V_30 . V_9 += ( F_1 () *
V_21 ) ;
if ( V_15 . V_30 . V_9 > V_15 . V_18 ) {
F_57 ( V_95 L_11 ,
V_85 ) ;
F_58 ( L_12 , V_85 ) ;
}
V_15 . V_22 . V_9 = V_15 . V_18 - V_15 . V_30 . V_9 ;
V_15 . V_22 . free = V_15 . V_22 . V_9 ;
V_15 . F_8 = V_15 . V_30 . V_9 ;
V_15 . V_31 = V_15 . V_30 . V_9 ;
}
static T_5 F_59 ( struct V_48 * V_49 ,
struct V_97 * V_98 , char * V_99 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
return sprintf ( V_99 , L_13 , F_60 ( & V_8 -> V_17 . V_55 ) ) ;
}
static T_5 F_61 ( struct V_48 * V_49 ,
struct V_97 * V_98 , const char * V_99 , T_1 V_3 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
F_49 ( & V_8 -> V_17 . V_55 , 0 ) ;
return V_3 ;
}
static T_5 F_62 ( struct V_48 * V_49 ,
struct V_97 * V_98 , const char * V_99 , T_1 V_3 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
T_1 V_100 ;
int V_13 ;
V_13 = F_63 ( V_99 , 10 , & V_100 ) ;
if ( V_13 )
return V_13 ;
F_36 ( V_8 , V_100 ) ;
return V_3 ;
}
static T_5 F_64 ( struct V_101 * V_102 , const char * V_99 ,
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
V_103 . V_104 = V_105 ;
V_103 . V_106 = V_107 ;
}
int F_13 ( T_1 V_34 ) { return 0 ; }
void F_36 ( struct V_7 * V_8 , T_1 V_31 ) {}
static int F_38 ( struct V_7 * V_8 ) { return 0 ; }
static void F_45 ( struct V_7 * V_8 ) {}
static void F_50 ( struct V_7 * V_8 ) {}
static void F_52 ( void ) {}
static void F_65 ( void ) { }
static struct V_108 * F_66 ( struct V_7 * V_49 )
{
const unsigned char * V_109 ;
struct V_108 * V_110 ;
unsigned long V_60 , V_9 ;
V_109 = F_40 ( V_49 -> V_49 . V_4 ,
L_2 , NULL ) ;
if ( ! V_109 )
return NULL ;
V_110 = F_67 ( sizeof( * V_110 ) , V_87 ) ;
if ( V_110 == NULL )
return NULL ;
F_68 ( V_49 -> V_49 . V_4 , V_109 ,
& V_110 -> V_111 , & V_60 , & V_9 ) ;
V_110 -> V_112 = V_9 >> V_113 ;
V_110 -> V_114 = V_60 >> V_113 ;
V_110 -> V_115 = 0 ;
V_110 -> V_116 = V_117 ;
V_110 -> V_118 = 16 ;
return F_69 ( V_110 , - 1 ) ;
}
static const struct V_119 * F_70 (
const struct V_119 * V_120 , const struct V_7 * V_49 )
{
while ( V_120 -> type [ 0 ] != '\0' ) {
if ( ( strncmp ( V_49 -> type , V_120 -> type , strlen ( V_120 -> type ) ) == 0 ) &&
F_71 ( V_49 -> V_49 . V_4 ,
V_120 -> V_121 ) )
return V_120 ;
V_120 ++ ;
}
return NULL ;
}
static int F_72 ( struct V_48 * V_49 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_81 * V_82 = F_39 ( V_49 -> V_83 ) ;
const struct V_119 * V_122 ;
int error = - V_123 ;
if ( ! V_82 -> V_124 )
return error ;
V_122 = F_70 ( V_82 -> V_125 , V_8 ) ;
if ( V_122 ) {
memset ( & V_8 -> V_17 , 0 , sizeof( V_8 -> V_17 ) ) ;
if ( F_37 ( V_80 ) ) {
error = F_38 ( V_8 ) ;
if ( error )
return error ;
}
error = V_82 -> V_124 ( V_8 , V_122 ) ;
if ( error && F_37 ( V_80 ) )
F_45 ( V_8 ) ;
}
return error ;
}
static int F_73 ( struct V_48 * V_49 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_81 * V_82 = F_39 ( V_49 -> V_83 ) ;
struct V_48 * V_126 ;
int V_13 = 1 ;
V_126 = F_74 ( V_49 ) ;
if ( V_82 -> remove )
V_13 = V_82 -> remove ( V_8 ) ;
if ( ! V_13 && F_37 ( V_80 ) )
F_45 ( V_8 ) ;
F_75 ( V_126 ) ;
return V_13 ;
}
int F_76 ( struct V_81 * V_82 , struct V_127 * V_128 ,
const char * V_129 )
{
F_77 ( L_14 , V_85 , V_82 -> V_130 ) ;
V_82 -> V_83 . V_130 = V_82 -> V_130 ;
V_82 -> V_83 . V_131 = V_82 -> V_131 ;
V_82 -> V_83 . V_132 = & V_103 ;
V_82 -> V_83 . V_128 = V_128 ;
V_82 -> V_83 . V_129 = V_129 ;
return F_78 ( & V_82 -> V_83 ) ;
}
void F_79 ( struct V_81 * V_82 )
{
F_80 ( & V_82 -> V_83 ) ;
}
static void T_6 F_81 ( struct V_48 * V_49 )
{
struct V_108 * V_110 = F_82 ( V_49 ) ;
if ( V_110 )
F_83 ( V_110 , V_49 -> V_4 ?
V_49 -> V_4 -> V_133 : F_84 ( V_49 ) ) ;
F_5 ( V_49 -> V_4 ) ;
F_48 ( F_24 ( V_49 ) ) ;
}
struct V_7 * F_85 ( struct V_1 * V_4 )
{
struct V_7 * V_8 ;
const unsigned int * V_134 ;
if ( V_4 -> type == NULL ) {
F_57 ( V_135 L_15 ,
V_85 ,
V_4 -> V_130 ? V_4 -> V_130 : L_16 ) ;
return NULL ;
}
V_134 = F_40 ( V_4 , L_17 , NULL ) ;
if ( V_134 == NULL ) {
F_57 ( V_135 L_18 ,
V_85 ,
V_4 -> V_130 ? V_4 -> V_130 : L_16 ) ;
return NULL ;
}
V_8 = F_67 ( sizeof( struct V_7 ) , V_87 ) ;
if ( V_8 == NULL )
return NULL ;
V_8 -> V_136 = F_86 ( V_4 , 0 ) ;
F_87 ( & V_8 -> V_49 , L_19 , * V_134 ) ;
V_8 -> V_130 = V_4 -> V_130 ;
V_8 -> type = V_4 -> type ;
V_8 -> V_134 = * V_134 ;
V_8 -> V_49 . V_4 = F_88 ( V_4 ) ;
if ( F_37 ( V_80 ) )
F_50 ( V_8 ) ;
else
F_51 ( & V_8 -> V_49 , & V_56 ) ;
F_89 ( & V_8 -> V_49 , F_66 ( V_8 ) ) ;
F_90 ( & V_8 -> V_49 , F_91 ( V_4 ) ) ;
V_8 -> V_49 . V_137 = & V_138 . V_49 ;
V_8 -> V_49 . V_132 = & V_103 ;
V_8 -> V_49 . V_139 = F_81 ;
F_92 ( & V_8 -> V_49 , F_93 ( 64 ) ) ;
F_94 ( & V_8 -> V_49 , F_93 ( 64 ) ) ;
if ( F_95 ( & V_8 -> V_49 ) ) {
F_57 ( V_95 L_20 ,
V_85 , F_84 ( & V_8 -> V_49 ) ) ;
F_75 ( & V_8 -> V_49 ) ;
return NULL ;
}
return V_8 ;
}
static int T_7 F_96 ( void )
{
int V_93 ;
struct V_1 * V_2 ;
if ( F_37 ( V_80 ) )
F_65 () ;
V_93 = F_97 ( & V_103 ) ;
if ( V_93 ) {
F_57 ( V_95 L_21 ) ;
return V_93 ;
}
V_93 = F_95 ( & V_138 . V_49 ) ;
if ( V_93 ) {
F_57 ( V_135 L_22 ,
V_85 , V_93 ) ;
return V_93 ;
}
if ( F_37 ( V_80 ) )
F_52 () ;
V_2 = F_2 ( NULL , L_1 ) ;
if ( V_2 ) {
struct V_1 * V_4 ;
for ( V_4 = V_2 -> V_140 ; V_4 != NULL ;
V_4 = V_4 -> V_141 )
F_85 ( V_4 ) ;
F_5 ( V_2 ) ;
}
return 0 ;
}
static T_5 F_98 ( struct V_48 * V_49 ,
struct V_97 * V_98 , char * V_99 )
{
return sprintf ( V_99 , L_23 , F_24 ( V_49 ) -> V_130 ) ;
}
static T_5 F_99 ( struct V_48 * V_49 ,
struct V_97 * V_98 , char * V_99 )
{
struct V_1 * V_4 = V_49 -> V_4 ;
return sprintf ( V_99 , L_23 , V_4 ? V_4 -> V_133 : L_24 ) ;
}
static T_5 F_100 ( struct V_48 * V_49 , struct V_97 * V_98 ,
char * V_99 )
{
const struct V_7 * V_7 = F_24 ( V_49 ) ;
struct V_1 * V_142 ;
const char * V_143 ;
V_142 = V_49 -> V_4 ;
if ( ! V_142 )
return - V_123 ;
V_143 = F_40 ( V_142 , L_25 , NULL ) ;
if ( ! V_143 )
return - V_123 ;
return sprintf ( V_99 , L_26 , V_7 -> type , V_143 ) ;
}
void T_6 F_101 ( struct V_7 * V_8 )
{
F_102 ( & V_8 -> V_49 ) ;
}
static int F_103 ( struct V_48 * V_49 , struct V_144 * V_145 )
{
const struct V_7 * V_7 = F_24 ( V_49 ) ;
struct V_81 * V_146 = F_39 ( V_145 ) ;
const struct V_119 * V_120 = V_146 -> V_125 ;
return ( V_120 != NULL ) && ( F_70 ( V_120 , V_7 ) != NULL ) ;
}
static int F_104 ( struct V_48 * V_49 , struct V_147 * V_148 )
{
const struct V_7 * V_7 = F_24 ( V_49 ) ;
struct V_1 * V_142 ;
const char * V_143 ;
V_142 = V_49 -> V_4 ;
if ( ! V_142 )
return - V_123 ;
V_143 = F_40 ( V_142 , L_25 , NULL ) ;
if ( ! V_143 )
return - V_123 ;
F_105 ( V_148 , L_27 , V_7 -> type , V_143 ) ;
return 0 ;
}
const void * F_106 ( struct V_7 * V_149 , char * V_150 , int * V_72 )
{
return F_40 ( V_149 -> V_49 . V_4 , V_150 , V_72 ) ;
}
static struct V_7 * F_107 ( const char * V_130 )
{
struct V_48 * V_79 ;
V_79 = F_108 ( & V_103 , NULL , V_130 ) ;
if ( ! V_79 )
return NULL ;
return F_24 ( V_79 ) ;
}
struct V_7 * F_109 ( struct V_1 * V_151 )
{
const T_8 * V_134 ;
char V_152 [ 20 ] ;
V_134 = F_40 ( V_151 , L_17 , NULL ) ;
if ( ! V_134 )
return NULL ;
snprintf ( V_152 , sizeof( V_152 ) , L_19 , * V_134 ) ;
return F_107 ( V_152 ) ;
}
int F_110 ( struct V_7 * V_49 )
{
int V_153 = F_111 ( V_49 -> V_134 , V_154 ) ;
if ( V_153 != V_94 )
F_57 ( V_95 L_28 , V_153 ) ;
return V_153 ;
}
int F_112 ( struct V_7 * V_49 )
{
int V_153 = F_111 ( V_49 -> V_134 , V_155 ) ;
if ( V_153 != V_94 )
F_57 ( V_95 L_29 , V_153 ) ;
return V_153 ;
}
