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
struct V_63 * V_64 ;
T_2 V_13 = V_65 ;
V_64 = F_30 ( V_49 ) ;
if ( F_6 ( V_8 , F_25 ( V_9 , F_31 ( V_64 ) ) ) ) {
F_26 ( & V_8 -> V_17 . V_55 ) ;
return V_13 ;
}
V_13 = V_56 . V_66 ( V_49 , V_59 , V_60 , V_9 , V_62 , V_53 ) ;
if ( F_27 ( F_32 ( V_49 , V_13 ) ) ) {
F_10 ( V_8 , F_25 ( V_9 , F_31 ( V_64 ) ) ) ;
F_26 ( & V_8 -> V_17 . V_55 ) ;
}
return V_13 ;
}
static void F_33 ( struct V_48 * V_49 , T_2 V_50 ,
T_1 V_9 ,
enum V_61 V_62 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_63 * V_64 ;
V_64 = F_30 ( V_49 ) ;
V_56 . V_67 ( V_49 , V_50 , V_9 , V_62 , V_53 ) ;
F_10 ( V_8 , F_25 ( V_9 , F_31 ( V_64 ) ) ) ;
}
static int F_34 ( struct V_48 * V_49 , struct V_68 * V_69 ,
int V_70 , enum V_61 V_62 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_63 * V_64 ;
struct V_68 * V_71 ;
int V_13 , V_3 ;
T_1 V_72 = 0 ;
V_64 = F_30 ( V_49 ) ;
F_35 (sglist, sgl, nelems, count)
V_72 += F_25 ( V_71 -> V_73 , F_31 ( V_64 ) ) ;
if ( F_6 ( V_8 , V_72 ) ) {
F_26 ( & V_8 -> V_17 . V_55 ) ;
return 0 ;
}
V_13 = V_56 . V_74 ( V_49 , V_69 , V_70 , V_62 , V_53 ) ;
if ( F_27 ( ! V_13 ) ) {
F_10 ( V_8 , V_72 ) ;
F_26 ( & V_8 -> V_17 . V_55 ) ;
return V_13 ;
}
F_35 (sglist, sgl, ret, count)
V_72 -= F_25 ( V_71 -> V_75 , F_31 ( V_64 ) ) ;
if ( V_72 )
F_10 ( V_8 , V_72 ) ;
return V_13 ;
}
static void F_36 ( struct V_48 * V_49 ,
struct V_68 * V_69 , int V_70 ,
enum V_61 V_62 ,
struct V_52 * V_53 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_63 * V_64 ;
struct V_68 * V_71 ;
T_1 V_72 = 0 ;
int V_3 ;
V_64 = F_30 ( V_49 ) ;
F_35 (sglist, sgl, nelems, count)
V_72 += F_25 ( V_71 -> V_75 , F_31 ( V_64 ) ) ;
V_56 . V_76 ( V_49 , V_69 , V_70 , V_62 , V_53 ) ;
F_10 ( V_8 , V_72 ) ;
}
static int F_37 ( struct V_48 * V_49 , T_4 V_77 )
{
return V_56 . V_78 ( V_49 , V_77 ) ;
}
static T_4 F_38 ( struct V_48 * V_49 )
{
return V_56 . V_79 ( V_49 ) ;
}
void F_39 ( struct V_7 * V_8 , T_1 V_31 )
{
unsigned long V_10 ;
struct V_35 * V_36 ;
int V_80 = 0 ;
if ( ! F_40 ( V_81 ) )
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
static int F_41 ( struct V_7 * V_8 )
{
struct V_35 * V_36 ;
struct V_48 * V_49 = & V_8 -> V_49 ;
struct V_63 * V_64 ;
struct V_82 * V_83 = F_42 ( V_49 -> V_84 ) ;
unsigned long V_10 ;
T_1 V_9 ;
bool V_85 = false ;
V_64 = F_30 ( V_49 ) ;
switch ( V_8 -> V_86 ) {
case V_87 :
if ( F_43 ( V_8 -> V_49 . V_4 ,
L_2 , NULL ) )
V_85 = true ;
break;
case V_88 :
V_85 = false ;
break;
default:
F_44 ( V_49 , L_3 , V_8 -> V_86 ) ;
F_45 () ;
break;
}
if ( V_85 ) {
if ( ! V_83 -> V_89 ) {
F_46 ( V_49 , L_4 ,
V_90 ) ;
return - V_91 ;
}
V_8 -> V_17 . V_31 =
F_47 ( V_83 -> V_89 ( V_8 ) , V_64 ) ;
if ( V_8 -> V_17 . V_31 < V_21 )
V_8 -> V_17 . V_31 = V_21 ;
V_9 = V_21 ;
V_36 = F_48 ( sizeof( struct V_35 ) ,
V_92 ) ;
if ( ! V_36 )
return - V_14 ;
V_36 -> V_8 = V_8 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
F_49 ( & V_36 -> V_93 , & V_15 . V_94 ) ;
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
F_46 ( V_49 , L_5
L_6
L_7 , V_90 ,
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
static void F_50 ( struct V_7 * V_8 )
{
struct V_35 * V_36 ;
unsigned long V_10 ;
T_1 V_28 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
if ( V_8 -> V_17 . V_19 ) {
F_46 ( & V_8 -> V_49 , L_8
L_9 ,
V_90 , V_8 -> V_17 . V_19 ) ;
F_45 () ;
}
F_14 (dev_ent, &vio_cmo.device_list, list)
if ( V_8 == V_36 -> V_8 ) {
F_51 ( & V_36 -> V_93 ) ;
F_52 ( V_36 ) ;
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
F_53 ( & V_8 -> V_17 . V_55 , 0 ) ;
}
F_9 ( & V_15 . V_16 , V_10 ) ;
}
static void F_54 ( struct V_7 * V_8 )
{
F_55 ( & V_8 -> V_49 , & V_95 ) ;
}
static void F_56 ( void )
{
struct V_96 V_97 ;
int V_98 ;
memset ( & V_15 , 0 , sizeof( struct V_15 ) ) ;
F_57 ( & V_15 . V_16 ) ;
F_58 ( & V_15 . V_94 ) ;
F_59 ( & V_15 . V_32 , F_16 ) ;
V_98 = F_60 ( & V_97 ) ;
if ( V_98 != V_99 ) {
F_61 ( V_100 L_10\
L_11 , V_90 , V_98 ) ;
V_15 . V_18 = 0 ;
} else {
V_15 . V_18 = V_97 . V_101 ;
}
V_15 . V_20 = V_21 ;
V_15 . V_30 . V_9 = V_15 . V_20 ;
V_15 . V_30 . V_9 += ( F_1 () *
V_21 ) ;
if ( V_15 . V_30 . V_9 > V_15 . V_18 ) {
F_61 ( V_100 L_12 ,
V_90 ) ;
F_62 ( L_13 , V_90 ) ;
}
V_15 . V_22 . V_9 = V_15 . V_18 - V_15 . V_30 . V_9 ;
V_15 . V_22 . free = V_15 . V_22 . V_9 ;
V_15 . F_8 = V_15 . V_30 . V_9 ;
V_15 . V_31 = V_15 . V_30 . V_9 ;
}
static T_5 F_63 ( struct V_48 * V_49 ,
struct V_102 * V_103 , char * V_104 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
return sprintf ( V_104 , L_14 , F_64 ( & V_8 -> V_17 . V_55 ) ) ;
}
static T_5 F_65 ( struct V_48 * V_49 ,
struct V_102 * V_103 , const char * V_104 , T_1 V_3 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
F_53 ( & V_8 -> V_17 . V_55 , 0 ) ;
return V_3 ;
}
static T_5 F_66 ( struct V_48 * V_49 ,
struct V_102 * V_103 , const char * V_104 , T_1 V_3 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
T_1 V_105 ;
int V_13 ;
V_13 = F_67 ( V_104 , 10 , & V_105 ) ;
if ( V_13 )
return V_13 ;
F_39 ( V_8 , V_105 ) ;
return V_3 ;
}
static T_5 F_68 ( struct V_106 * V_107 , char * V_104 )
{
return sprintf ( V_104 , L_15 , V_15 . V_24 ) ;
}
static T_5 F_69 ( struct V_106 * V_107 , const char * V_104 ,
T_1 V_3 )
{
unsigned long V_10 ;
F_7 ( & V_15 . V_16 , V_10 ) ;
V_15 . V_24 = V_15 . V_23 ;
F_9 ( & V_15 . V_16 , V_10 ) ;
return V_3 ;
}
static void F_70 ( void )
{
V_108 . V_109 = V_110 ;
V_108 . V_111 = V_112 ;
}
int F_13 ( T_1 V_34 ) { return 0 ; }
void F_39 ( struct V_7 * V_8 , T_1 V_31 ) {}
static int F_41 ( struct V_7 * V_8 ) { return 0 ; }
static void F_50 ( struct V_7 * V_8 ) {}
static void F_54 ( struct V_7 * V_8 ) {}
static void F_56 ( void ) {}
static void F_70 ( void ) { }
int F_71 ( struct V_7 * V_113 , struct V_114 * V_115 )
{
struct V_48 * V_49 = & V_113 -> V_49 ;
unsigned long V_116 = 0 ;
long V_117 = 0 ;
int V_13 = 0 ;
if ( V_115 -> V_118 )
V_116 = V_119 + F_72 ( V_115 -> V_118 ) ;
while ( true ) {
V_117 = F_73 ( V_120 , V_115 -> V_10 ,
V_113 -> V_121 ,
V_115 -> V_122 , V_115 -> V_123 , V_115 -> V_39 ,
V_115 -> V_124 , V_115 -> V_125 ) ;
if ( V_117 == V_99 ||
( V_117 != V_126 &&
V_117 != V_127 && V_117 != V_128 ) ||
( V_115 -> V_118 && F_74 ( V_116 , V_119 ) ) )
break;
F_75 ( V_49 , L_16 , V_90 , V_117 ) ;
}
switch ( V_117 ) {
case V_99 :
V_13 = 0 ;
break;
case V_129 :
case V_130 :
V_13 = - V_131 ;
break;
case V_132 :
V_13 = - V_133 ;
break;
case V_134 :
V_13 = - V_135 ;
break;
case V_126 :
case V_128 :
case V_127 :
V_13 = - V_136 ;
break;
default:
V_13 = - V_91 ;
break;
}
if ( V_13 )
F_75 ( V_49 , L_17 ,
V_90 , V_13 , V_117 ) ;
V_115 -> V_137 = V_117 ;
return V_13 ;
}
static struct V_63 * F_76 ( struct V_7 * V_49 )
{
const T_6 * V_138 ;
struct V_63 * V_64 ;
unsigned long V_60 , V_9 ;
V_138 = F_43 ( V_49 -> V_49 . V_4 ,
L_2 , NULL ) ;
if ( ! V_138 )
return NULL ;
V_64 = F_77 ( sizeof( * V_64 ) , V_92 ) ;
if ( V_64 == NULL )
return NULL ;
F_78 ( V_49 -> V_49 . V_4 , V_138 ,
& V_64 -> V_139 , & V_60 , & V_9 ) ;
V_64 -> V_140 = V_141 ;
V_64 -> V_142 = V_9 >> V_64 -> V_140 ;
V_64 -> V_143 = V_60 >> V_64 -> V_140 ;
V_64 -> V_144 = 0 ;
V_64 -> V_145 = V_146 ;
V_64 -> V_147 = 16 ;
if ( F_40 ( V_148 ) )
V_64 -> V_149 = & V_150 ;
else
V_64 -> V_149 = & V_151 ;
return F_79 ( V_64 , - 1 ) ;
}
static const struct V_152 * F_80 (
const struct V_152 * V_153 , const struct V_7 * V_49 )
{
while ( V_153 -> type [ 0 ] != '\0' ) {
if ( ( strncmp ( V_49 -> type , V_153 -> type , strlen ( V_153 -> type ) ) == 0 ) &&
F_81 ( V_49 -> V_49 . V_4 ,
V_153 -> V_154 ) )
return V_153 ;
V_153 ++ ;
}
return NULL ;
}
static int F_82 ( struct V_48 * V_49 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_82 * V_83 = F_42 ( V_49 -> V_84 ) ;
const struct V_152 * V_155 ;
int error = - V_156 ;
if ( ! V_83 -> V_157 )
return error ;
V_155 = F_80 ( V_83 -> V_158 , V_8 ) ;
if ( V_155 ) {
memset ( & V_8 -> V_17 , 0 , sizeof( V_8 -> V_17 ) ) ;
if ( F_40 ( V_81 ) ) {
error = F_41 ( V_8 ) ;
if ( error )
return error ;
}
error = V_83 -> V_157 ( V_8 , V_155 ) ;
if ( error && F_40 ( V_81 ) )
F_50 ( V_8 ) ;
}
return error ;
}
static int F_83 ( struct V_48 * V_49 )
{
struct V_7 * V_8 = F_24 ( V_49 ) ;
struct V_82 * V_83 = F_42 ( V_49 -> V_84 ) ;
struct V_48 * V_159 ;
int V_13 = 1 ;
V_159 = F_84 ( V_49 ) ;
if ( V_83 -> remove )
V_13 = V_83 -> remove ( V_8 ) ;
if ( ! V_13 && F_40 ( V_81 ) )
F_50 ( V_8 ) ;
F_85 ( V_159 ) ;
return V_13 ;
}
int F_86 ( struct V_82 * V_83 , struct V_160 * V_161 ,
const char * V_162 )
{
F_87 ( L_18 , V_90 , V_83 -> V_163 ) ;
V_83 -> V_84 . V_163 = V_83 -> V_163 ;
V_83 -> V_84 . V_164 = V_83 -> V_164 ;
V_83 -> V_84 . V_165 = & V_108 ;
V_83 -> V_84 . V_161 = V_161 ;
V_83 -> V_84 . V_162 = V_162 ;
return F_88 ( & V_83 -> V_84 ) ;
}
void F_89 ( struct V_82 * V_83 )
{
F_90 ( & V_83 -> V_84 ) ;
}
static void F_91 ( struct V_48 * V_49 )
{
struct V_63 * V_64 = F_30 ( V_49 ) ;
if ( V_64 )
F_92 ( V_64 , F_93 ( V_49 -> V_4 ) ) ;
F_5 ( V_49 -> V_4 ) ;
F_52 ( F_24 ( V_49 ) ) ;
}
struct V_7 * F_94 ( struct V_1 * V_4 )
{
struct V_7 * V_8 ;
struct V_1 * V_166 ;
const T_6 * V_6 ;
enum V_167 V_86 ;
const char * V_168 = V_4 -> V_163 ? V_4 -> V_163 : L_19 ;
V_166 = F_95 ( V_4 ) ;
if ( V_166 ) {
if ( ! strcmp ( V_166 -> V_169 , L_20 ) )
V_86 = V_88 ;
else if ( ! strcmp ( V_166 -> V_169 , L_21 ) )
V_86 = V_87 ;
else {
F_96 ( L_22 ,
V_90 ,
V_166 -> V_169 ,
V_168 ) ;
F_5 ( V_166 ) ;
return NULL ;
}
F_5 ( V_166 ) ;
} else {
F_96 ( L_23 ,
V_90 , V_168 ) ;
return NULL ;
}
if ( V_86 == V_88 ) {
if ( F_43 ( V_4 , L_24 , NULL ) ) {
F_87 ( L_25 ,
V_90 , V_168 ) ;
return NULL ;
}
}
V_8 = F_77 ( sizeof( struct V_7 ) , V_92 ) ;
if ( V_8 == NULL ) {
F_96 ( L_26 , V_90 ) ;
return NULL ;
}
V_8 -> V_86 = V_86 ;
if ( V_8 -> V_86 == V_87 ) {
unsigned int V_170 ;
if ( V_4 -> type != NULL )
V_8 -> type = V_4 -> type ;
else {
F_96 ( L_27
L_28 , V_90 , V_168 ) ;
goto V_39;
}
V_6 = F_43 ( V_4 , L_29 , NULL ) ;
if ( V_6 == NULL ) {
F_96 ( L_30 ,
V_90 , V_168 ) ;
goto V_39;
}
V_170 = F_97 ( V_6 , 1 ) ;
F_98 ( & V_8 -> V_49 , L_31 , V_170 ) ;
V_8 -> V_171 = F_99 ( V_4 , 0 ) ;
V_8 -> V_170 = V_170 ;
} else {
V_6 = F_43 ( V_4 , L_32 , NULL ) ;
if ( V_6 != NULL )
V_8 -> V_121 = F_97 ( V_6 , 1 ) ;
F_98 ( & V_8 -> V_49 , L_33 , V_168 ) ;
V_8 -> type = V_168 ;
V_8 -> V_171 = 0 ;
}
V_8 -> V_163 = V_4 -> V_163 ;
V_8 -> V_49 . V_4 = F_100 ( V_4 ) ;
F_101 ( & V_8 -> V_49 , F_102 ( V_4 ) ) ;
V_8 -> V_49 . V_172 = & V_173 . V_49 ;
V_8 -> V_49 . V_165 = & V_108 ;
V_8 -> V_49 . V_174 = F_91 ;
if ( F_43 ( V_8 -> V_49 . V_4 , L_2 , NULL ) ) {
if ( F_40 ( V_81 ) )
F_54 ( V_8 ) ;
else
F_55 ( & V_8 -> V_49 , & V_56 ) ;
F_103 ( & V_8 -> V_49 ,
F_76 ( V_8 ) ) ;
V_8 -> V_49 . V_175 = F_104 ( 64 ) ;
V_8 -> V_49 . V_176 = & V_8 -> V_49 . V_175 ;
}
if ( F_105 ( & V_8 -> V_49 ) ) {
F_61 ( V_100 L_34 ,
V_90 , F_106 ( & V_8 -> V_49 ) ) ;
F_85 ( & V_8 -> V_49 ) ;
return NULL ;
}
return V_8 ;
V_39:
F_52 ( V_8 ) ;
return NULL ;
}
static void F_107 ( char * V_177 )
{
struct V_1 * V_178 , * V_179 ;
if ( ! V_177 )
return;
V_178 = F_2 ( NULL , V_177 ) ;
if ( V_178 ) {
V_179 = F_108 ( V_178 , NULL ) ;
while ( V_179 ) {
F_94 ( V_179 ) ;
V_179 = F_108 ( V_178 , V_179 ) ;
}
F_5 ( V_178 ) ;
}
}
static int T_7 F_109 ( void )
{
int V_98 ;
if ( F_40 ( V_81 ) )
F_70 () ;
V_98 = F_110 ( & V_108 ) ;
if ( V_98 ) {
F_61 ( V_100 L_35 ) ;
return V_98 ;
}
V_98 = F_105 ( & V_173 . V_49 ) ;
if ( V_98 ) {
F_61 ( V_180 L_36 ,
V_90 , V_98 ) ;
return V_98 ;
}
if ( F_40 ( V_81 ) )
F_56 () ;
return 0 ;
}
static int T_7 F_111 ( void )
{
F_107 ( L_1 ) ;
F_107 ( L_37 ) ;
return 0 ;
}
static T_5 F_112 ( struct V_48 * V_49 ,
struct V_102 * V_103 , char * V_104 )
{
return sprintf ( V_104 , L_38 , F_24 ( V_49 ) -> V_163 ) ;
}
static T_5 F_113 ( struct V_48 * V_49 ,
struct V_102 * V_103 , char * V_104 )
{
struct V_1 * V_4 = V_49 -> V_4 ;
return sprintf ( V_104 , L_38 , F_93 ( V_4 ) ) ;
}
static T_5 F_114 ( struct V_48 * V_49 , struct V_102 * V_103 ,
char * V_104 )
{
const struct V_7 * V_7 = F_24 ( V_49 ) ;
struct V_1 * V_181 ;
const char * V_182 ;
V_181 = V_49 -> V_4 ;
if ( ! V_181 ) {
strcpy ( V_104 , L_39 ) ;
return strlen ( V_104 ) ;
}
V_182 = F_43 ( V_181 , L_40 , NULL ) ;
if ( ! V_182 ) {
strcpy ( V_104 , L_39 ) ;
return strlen ( V_104 ) ;
}
return sprintf ( V_104 , L_41 , V_7 -> type , V_182 ) ;
}
void F_115 ( struct V_7 * V_8 )
{
F_116 ( & V_8 -> V_49 ) ;
}
static int F_117 ( struct V_48 * V_49 , struct V_183 * V_184 )
{
const struct V_7 * V_7 = F_24 ( V_49 ) ;
struct V_82 * V_185 = F_42 ( V_184 ) ;
const struct V_152 * V_153 = V_185 -> V_158 ;
return ( V_153 != NULL ) && ( F_80 ( V_153 , V_7 ) != NULL ) ;
}
static int F_118 ( struct V_48 * V_49 , struct V_186 * V_187 )
{
const struct V_7 * V_7 = F_24 ( V_49 ) ;
struct V_1 * V_181 ;
const char * V_182 ;
V_181 = V_49 -> V_4 ;
if ( ! V_181 )
return - V_156 ;
V_182 = F_43 ( V_181 , L_40 , NULL ) ;
if ( ! V_182 )
return - V_156 ;
F_119 ( V_187 , L_42 , V_7 -> type , V_182 ) ;
return 0 ;
}
const void * F_120 ( struct V_7 * V_113 , char * V_188 , int * V_73 )
{
return F_43 ( V_113 -> V_49 . V_4 , V_188 , V_73 ) ;
}
static struct V_7 * F_121 ( const char * V_163 )
{
struct V_48 * V_80 ;
V_80 = F_122 ( & V_108 , NULL , V_163 ) ;
if ( ! V_80 )
return NULL ;
return F_24 ( V_80 ) ;
}
struct V_7 * F_123 ( struct V_1 * V_189 )
{
char V_190 [ 20 ] ;
struct V_1 * V_191 ;
const char * V_192 ;
V_191 = F_95 ( V_189 ) ;
if ( ! V_191 )
return NULL ;
V_192 = F_43 ( V_191 , L_43 , NULL ) ;
F_5 ( V_191 ) ;
if ( ! V_192 )
return NULL ;
if ( ! strcmp ( V_192 , L_1 ) ) {
const T_6 * V_6 ;
V_6 = F_43 ( V_189 , L_29 , NULL ) ;
if ( ! V_6 )
return NULL ;
snprintf ( V_190 , sizeof( V_190 ) , L_31 ,
( V_193 ) F_97 ( V_6 , 1 ) ) ;
} else if ( ! strcmp ( V_192 , L_37 ) )
snprintf ( V_190 , sizeof( V_190 ) , L_33 , V_189 -> V_163 ) ;
else
return NULL ;
return F_121 ( V_190 ) ;
}
int F_124 ( struct V_7 * V_49 )
{
int V_194 = F_125 ( V_49 -> V_170 , V_195 ) ;
if ( V_194 != V_99 )
F_61 ( V_100 L_44 , V_194 ) ;
return V_194 ;
}
int F_126 ( struct V_7 * V_49 )
{
int V_194 = F_125 ( V_49 -> V_170 , V_196 ) ;
if ( V_194 != V_99 )
F_61 ( V_100 L_45 , V_194 ) ;
return V_194 ;
}
