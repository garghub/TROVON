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
bool V_84 = false ;
switch ( V_8 -> V_85 ) {
case V_86 :
if ( F_40 ( V_8 -> V_49 . V_4 ,
L_2 , NULL ) )
V_84 = true ;
break;
case V_87 :
V_84 = false ;
break;
default:
F_41 ( V_49 , L_3 , V_8 -> V_85 ) ;
F_42 () ;
break;
}
if ( V_84 ) {
if ( ! V_82 -> V_88 ) {
F_43 ( V_49 , L_4 ,
V_89 ) ;
return - V_90 ;
}
V_8 -> V_17 . V_31 = F_44 ( V_82 -> V_88 ( V_8 ) ) ;
if ( V_8 -> V_17 . V_31 < V_21 )
V_8 -> V_17 . V_31 = V_21 ;
V_9 = V_21 ;
V_36 = F_45 ( sizeof( struct V_35 ) ,
V_91 ) ;
if ( ! V_36 )
return - V_14 ;
V_36 -> V_8 = V_8 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
F_46 ( & V_36 -> V_92 , & V_15 . V_93 ) ;
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
F_43 ( V_49 , L_5
L_6
L_7 , V_89 ,
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
static void F_47 ( struct V_7 * V_8 )
{
struct V_35 * V_36 ;
unsigned long V_10 ;
T_1 V_28 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
if ( V_8 -> V_17 . V_19 ) {
F_43 ( & V_8 -> V_49 , L_8
L_9 ,
V_89 , V_8 -> V_17 . V_19 ) ;
F_42 () ;
}
F_14 (dev_ent, &vio_cmo.device_list, list)
if ( V_8 == V_36 -> V_8 ) {
F_48 ( & V_36 -> V_92 ) ;
F_49 ( V_36 ) ;
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
F_50 ( & V_8 -> V_17 . V_55 , 0 ) ;
}
F_9 ( & V_15 . V_16 , V_10 ) ;
}
static void F_51 ( struct V_7 * V_8 )
{
F_52 ( & V_8 -> V_49 , & V_94 ) ;
}
static void F_53 ( void )
{
struct V_95 V_96 ;
int V_97 ;
memset ( & V_15 , 0 , sizeof( struct V_15 ) ) ;
F_54 ( & V_15 . V_16 ) ;
F_55 ( & V_15 . V_93 ) ;
F_56 ( & V_15 . V_32 , F_16 ) ;
V_97 = F_57 ( & V_96 ) ;
if ( V_97 != V_98 ) {
F_58 ( V_99 L_10\
L_11 , V_89 , V_97 ) ;
V_15 . V_18 = 0 ;
} else {
V_15 . V_18 = V_96 . V_100 ;
}
V_15 . V_20 = V_21 ;
V_15 . V_30 . V_9 = V_15 . V_20 ;
V_15 . V_30 . V_9 += ( F_1 () *
V_21 ) ;
if ( V_15 . V_30 . V_9 > V_15 . V_18 ) {
F_58 ( V_99 L_12 ,
V_89 ) ;
F_59 ( L_13 , V_89 ) ;
}
V_15 . V_22 . V_9 = V_15 . V_18 - V_15 . V_30 . V_9 ;
V_15 . V_22 . free = V_15 . V_22 . V_9 ;
V_15 . F_8 = V_15 . V_30 . V_9 ;
V_15 . V_31 = V_15 . V_30 . V_9 ;
}
static T_5 F_60 ( struct V_48 * V_49 ,
struct V_101 * V_102 , char * V_103 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
return sprintf ( V_103 , L_14 , F_61 ( & V_8 -> V_17 . V_55 ) ) ;
}
static T_5 F_62 ( struct V_48 * V_49 ,
struct V_101 * V_102 , const char * V_103 , T_1 V_3 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
F_50 ( & V_8 -> V_17 . V_55 , 0 ) ;
return V_3 ;
}
static T_5 F_63 ( struct V_48 * V_49 ,
struct V_101 * V_102 , const char * V_103 , T_1 V_3 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
T_1 V_104 ;
int V_13 ;
V_13 = F_64 ( V_103 , 10 , & V_104 ) ;
if ( V_13 )
return V_13 ;
F_36 ( V_8 , V_104 ) ;
return V_3 ;
}
static T_5 F_65 ( struct V_105 * V_106 , const char * V_103 ,
T_1 V_3 )
{
unsigned long V_10 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
V_15 . V_24 = V_15 . V_23 ;
F_9 ( & V_15 . V_16 , V_10 ) ;
return V_3 ;
}
static void F_66 ( void )
{
V_107 . V_108 = V_109 ;
V_107 . V_110 = V_111 ;
}
int F_13 ( T_1 V_34 ) { return 0 ; }
void F_36 ( struct V_7 * V_8 , T_1 V_31 ) {}
static int F_38 ( struct V_7 * V_8 ) { return 0 ; }
static void F_47 ( struct V_7 * V_8 ) {}
static void F_51 ( struct V_7 * V_8 ) {}
static void F_53 ( void ) {}
static void F_66 ( void ) { }
int F_67 ( struct V_7 * V_112 , struct V_113 * V_114 )
{
struct V_48 * V_49 = & V_112 -> V_49 ;
unsigned long V_115 = 0 ;
long V_116 = 0 ;
int V_13 = 0 ;
if ( V_114 -> V_117 )
V_115 = V_118 + F_68 ( V_114 -> V_117 ) ;
while ( true ) {
V_116 = F_69 ( V_119 , V_114 -> V_10 ,
V_112 -> V_120 ,
V_114 -> V_121 , V_114 -> V_122 , V_114 -> V_39 ,
V_114 -> V_123 , V_114 -> V_124 ) ;
if ( V_116 == V_98 ||
( V_116 != V_125 &&
V_116 != V_126 && V_116 != V_127 ) ||
( V_114 -> V_117 && F_70 ( V_115 , V_118 ) ) )
break;
F_71 ( V_49 , L_15 , V_89 , V_116 ) ;
}
switch ( V_116 ) {
case V_98 :
V_13 = 0 ;
break;
case V_128 :
case V_129 :
V_13 = - V_130 ;
break;
case V_131 :
V_13 = - V_132 ;
break;
case V_133 :
V_13 = - V_134 ;
break;
case V_125 :
case V_127 :
case V_126 :
V_13 = - V_135 ;
break;
default:
V_13 = - V_90 ;
break;
}
if ( V_13 )
F_71 ( V_49 , L_16 ,
V_89 , V_13 , V_116 ) ;
V_114 -> V_136 = V_116 ;
return V_13 ;
}
static struct V_137 * F_72 ( struct V_7 * V_49 )
{
const unsigned char * V_138 ;
struct V_137 * V_139 ;
unsigned long V_60 , V_9 ;
V_138 = F_40 ( V_49 -> V_49 . V_4 ,
L_2 , NULL ) ;
if ( ! V_138 )
return NULL ;
V_139 = F_73 ( sizeof( * V_139 ) , V_91 ) ;
if ( V_139 == NULL )
return NULL ;
F_74 ( V_49 -> V_49 . V_4 , V_138 ,
& V_139 -> V_140 , & V_60 , & V_9 ) ;
V_139 -> V_141 = V_9 >> V_142 ;
V_139 -> V_143 = V_60 >> V_142 ;
V_139 -> V_144 = 0 ;
V_139 -> V_145 = V_146 ;
V_139 -> V_147 = 16 ;
return F_75 ( V_139 , - 1 ) ;
}
static const struct V_148 * F_76 (
const struct V_148 * V_149 , const struct V_7 * V_49 )
{
while ( V_149 -> type [ 0 ] != '\0' ) {
if ( ( strncmp ( V_49 -> type , V_149 -> type , strlen ( V_149 -> type ) ) == 0 ) &&
F_77 ( V_49 -> V_49 . V_4 ,
V_149 -> V_150 ) )
return V_149 ;
V_149 ++ ;
}
return NULL ;
}
static int F_78 ( struct V_48 * V_49 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_81 * V_82 = F_39 ( V_49 -> V_83 ) ;
const struct V_148 * V_151 ;
int error = - V_152 ;
if ( ! V_82 -> V_153 )
return error ;
V_151 = F_76 ( V_82 -> V_154 , V_8 ) ;
if ( V_151 ) {
memset ( & V_8 -> V_17 , 0 , sizeof( V_8 -> V_17 ) ) ;
if ( F_37 ( V_80 ) ) {
error = F_38 ( V_8 ) ;
if ( error )
return error ;
}
error = V_82 -> V_153 ( V_8 , V_151 ) ;
if ( error && F_37 ( V_80 ) )
F_47 ( V_8 ) ;
}
return error ;
}
static int F_79 ( struct V_48 * V_49 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_81 * V_82 = F_39 ( V_49 -> V_83 ) ;
struct V_48 * V_155 ;
int V_13 = 1 ;
V_155 = F_80 ( V_49 ) ;
if ( V_82 -> remove )
V_13 = V_82 -> remove ( V_8 ) ;
if ( ! V_13 && F_37 ( V_80 ) )
F_47 ( V_8 ) ;
F_81 ( V_155 ) ;
return V_13 ;
}
int F_82 ( struct V_81 * V_82 , struct V_156 * V_157 ,
const char * V_158 )
{
F_83 ( L_17 , V_89 , V_82 -> V_159 ) ;
V_82 -> V_83 . V_159 = V_82 -> V_159 ;
V_82 -> V_83 . V_160 = V_82 -> V_160 ;
V_82 -> V_83 . V_161 = & V_107 ;
V_82 -> V_83 . V_157 = V_157 ;
V_82 -> V_83 . V_158 = V_158 ;
return F_84 ( & V_82 -> V_83 ) ;
}
void F_85 ( struct V_81 * V_82 )
{
F_86 ( & V_82 -> V_83 ) ;
}
static void F_87 ( struct V_48 * V_49 )
{
struct V_137 * V_139 = F_88 ( V_49 ) ;
if ( V_139 )
F_89 ( V_139 , F_90 ( V_49 -> V_4 ) ) ;
F_5 ( V_49 -> V_4 ) ;
F_49 ( F_24 ( V_49 ) ) ;
}
struct V_7 * F_91 ( struct V_1 * V_4 )
{
struct V_7 * V_8 ;
struct V_1 * V_162 ;
const unsigned int * V_163 ;
const unsigned int * V_164 = NULL ;
enum V_165 V_85 ;
const char * V_166 = V_4 -> V_159 ? V_4 -> V_159 : L_18 ;
V_162 = F_92 ( V_4 ) ;
if ( V_162 ) {
if ( ! strcmp ( V_162 -> V_167 , L_19 ) )
V_85 = V_87 ;
else if ( ! strcmp ( V_162 -> V_167 , L_20 ) )
V_85 = V_86 ;
else {
F_93 ( L_21 ,
V_89 ,
V_162 -> V_167 ,
V_166 ) ;
F_5 ( V_162 ) ;
return NULL ;
}
F_5 ( V_162 ) ;
} else {
F_93 ( L_22 ,
V_89 , V_166 ) ;
return NULL ;
}
if ( V_85 == V_87 ) {
if ( F_40 ( V_4 , L_23 , NULL ) ) {
F_83 ( L_24 ,
V_89 , V_166 ) ;
return NULL ;
}
}
V_8 = F_73 ( sizeof( struct V_7 ) , V_91 ) ;
if ( V_8 == NULL ) {
F_93 ( L_25 , V_89 ) ;
return NULL ;
}
V_8 -> V_85 = V_85 ;
if ( V_8 -> V_85 == V_86 ) {
if ( V_4 -> type != NULL )
V_8 -> type = V_4 -> type ;
else {
F_93 ( L_26
L_27 , V_89 , V_166 ) ;
goto V_39;
}
V_163 = F_40 ( V_4 , L_28 , NULL ) ;
if ( V_163 == NULL ) {
F_93 ( L_29 ,
V_89 , V_166 ) ;
goto V_39;
}
F_94 ( & V_8 -> V_49 , L_30 , * V_163 ) ;
V_8 -> V_168 = F_95 ( V_4 , 0 ) ;
V_8 -> V_163 = * V_163 ;
} else {
V_164 = F_40 ( V_4 , L_31 , NULL ) ;
if ( V_164 != NULL )
V_8 -> V_120 = * V_164 ;
V_163 = NULL ;
F_94 ( & V_8 -> V_49 , L_32 , V_166 ) ;
V_8 -> type = V_166 ;
V_8 -> V_168 = 0 ;
}
V_8 -> V_159 = V_4 -> V_159 ;
V_8 -> V_49 . V_4 = F_96 ( V_4 ) ;
F_97 ( & V_8 -> V_49 , F_98 ( V_4 ) ) ;
V_8 -> V_49 . V_169 = & V_170 . V_49 ;
V_8 -> V_49 . V_161 = & V_107 ;
V_8 -> V_49 . V_171 = F_87 ;
if ( F_40 ( V_8 -> V_49 . V_4 , L_2 , NULL ) ) {
if ( F_37 ( V_80 ) )
F_51 ( V_8 ) ;
else
F_52 ( & V_8 -> V_49 , & V_56 ) ;
F_99 ( & V_8 -> V_49 ,
F_72 ( V_8 ) ) ;
F_100 ( & V_8 -> V_49 , F_101 ( 64 ) ) ;
F_102 ( & V_8 -> V_49 , F_101 ( 64 ) ) ;
}
if ( F_103 ( & V_8 -> V_49 ) ) {
F_58 ( V_99 L_33 ,
V_89 , F_104 ( & V_8 -> V_49 ) ) ;
F_81 ( & V_8 -> V_49 ) ;
return NULL ;
}
return V_8 ;
V_39:
F_49 ( V_8 ) ;
return NULL ;
}
static void F_105 ( char * V_172 )
{
struct V_1 * V_173 , * V_174 ;
if ( ! V_172 )
return;
V_173 = F_2 ( NULL , V_172 ) ;
if ( V_173 ) {
V_174 = F_106 ( V_173 , NULL ) ;
while ( V_174 ) {
F_91 ( V_174 ) ;
V_174 = F_106 ( V_173 , V_174 ) ;
}
F_5 ( V_173 ) ;
}
}
static int T_6 F_107 ( void )
{
int V_97 ;
if ( F_37 ( V_80 ) )
F_66 () ;
V_97 = F_108 ( & V_107 ) ;
if ( V_97 ) {
F_58 ( V_99 L_34 ) ;
return V_97 ;
}
V_97 = F_103 ( & V_170 . V_49 ) ;
if ( V_97 ) {
F_58 ( V_175 L_35 ,
V_89 , V_97 ) ;
return V_97 ;
}
if ( F_37 ( V_80 ) )
F_53 () ;
return 0 ;
}
static int T_6 F_109 ( void )
{
F_105 ( L_1 ) ;
F_105 ( L_36 ) ;
return 0 ;
}
static T_5 F_110 ( struct V_48 * V_49 ,
struct V_101 * V_102 , char * V_103 )
{
return sprintf ( V_103 , L_37 , F_24 ( V_49 ) -> V_159 ) ;
}
static T_5 F_111 ( struct V_48 * V_49 ,
struct V_101 * V_102 , char * V_103 )
{
struct V_1 * V_4 = V_49 -> V_4 ;
return sprintf ( V_103 , L_37 , F_90 ( V_4 ) ) ;
}
static T_5 F_112 ( struct V_48 * V_49 , struct V_101 * V_102 ,
char * V_103 )
{
const struct V_7 * V_7 = F_24 ( V_49 ) ;
struct V_1 * V_176 ;
const char * V_177 ;
V_176 = V_49 -> V_4 ;
if ( ! V_176 )
return - V_152 ;
V_177 = F_40 ( V_176 , L_38 , NULL ) ;
if ( ! V_177 )
return - V_152 ;
return sprintf ( V_103 , L_39 , V_7 -> type , V_177 ) ;
}
void F_113 ( struct V_7 * V_8 )
{
F_114 ( & V_8 -> V_49 ) ;
}
static int F_115 ( struct V_48 * V_49 , struct V_178 * V_179 )
{
const struct V_7 * V_7 = F_24 ( V_49 ) ;
struct V_81 * V_180 = F_39 ( V_179 ) ;
const struct V_148 * V_149 = V_180 -> V_154 ;
return ( V_149 != NULL ) && ( F_76 ( V_149 , V_7 ) != NULL ) ;
}
static int F_116 ( struct V_48 * V_49 , struct V_181 * V_182 )
{
const struct V_7 * V_7 = F_24 ( V_49 ) ;
struct V_1 * V_176 ;
const char * V_177 ;
V_176 = V_49 -> V_4 ;
if ( ! V_176 )
return - V_152 ;
V_177 = F_40 ( V_176 , L_38 , NULL ) ;
if ( ! V_177 )
return - V_152 ;
F_117 ( V_182 , L_40 , V_7 -> type , V_177 ) ;
return 0 ;
}
const void * F_118 ( struct V_7 * V_112 , char * V_183 , int * V_72 )
{
return F_40 ( V_112 -> V_49 . V_4 , V_183 , V_72 ) ;
}
static struct V_7 * F_119 ( const char * V_159 )
{
struct V_48 * V_79 ;
V_79 = F_120 ( & V_107 , NULL , V_159 ) ;
if ( ! V_79 )
return NULL ;
return F_24 ( V_79 ) ;
}
struct V_7 * F_121 ( struct V_1 * V_184 )
{
const T_7 * V_163 ;
char V_185 [ 20 ] ;
struct V_1 * V_186 ;
const char * V_187 ;
V_186 = F_92 ( V_184 ) ;
if ( ! V_186 )
return NULL ;
V_187 = F_40 ( V_186 , L_41 , NULL ) ;
F_5 ( V_186 ) ;
if ( ! V_187 )
return NULL ;
if ( ! strcmp ( V_187 , L_1 ) ) {
V_163 = F_40 ( V_184 , L_28 , NULL ) ;
if ( ! V_163 )
return NULL ;
snprintf ( V_185 , sizeof( V_185 ) , L_30 , * V_163 ) ;
} else if ( ! strcmp ( V_187 , L_36 ) )
snprintf ( V_185 , sizeof( V_185 ) , L_32 , V_184 -> V_159 ) ;
else
return NULL ;
return F_119 ( V_185 ) ;
}
int F_122 ( struct V_7 * V_49 )
{
int V_188 = F_123 ( V_49 -> V_163 , V_189 ) ;
if ( V_188 != V_98 )
F_58 ( V_99 L_42 , V_188 ) ;
return V_188 ;
}
int F_124 ( struct V_7 * V_49 )
{
int V_188 = F_123 ( V_49 -> V_163 , V_190 ) ;
if ( V_188 != V_98 )
F_58 ( V_99 L_43 , V_188 ) ;
return V_188 ;
}
