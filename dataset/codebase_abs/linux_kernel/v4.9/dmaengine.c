static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 , F_3 ( * V_5 ) , V_2 ) ;
return V_5 -> V_6 ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_1 * V_6 ;
unsigned long V_10 = 0 ;
int V_11 ;
int V_12 ;
F_5 ( & V_13 ) ;
V_6 = F_1 ( V_3 ) ;
if ( V_6 ) {
F_6 (i)
V_10 += F_7 ( V_6 -> V_14 , V_11 ) -> V_15 ;
V_12 = sprintf ( V_9 , L_1 , V_10 ) ;
} else
V_12 = - V_16 ;
F_8 ( & V_13 ) ;
return V_12 ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
struct V_7 * V_8 , char * V_9 )
{
struct V_1 * V_6 ;
unsigned long V_10 = 0 ;
int V_11 ;
int V_12 ;
F_5 ( & V_13 ) ;
V_6 = F_1 ( V_3 ) ;
if ( V_6 ) {
F_6 (i)
V_10 += F_7 ( V_6 -> V_14 , V_11 ) -> V_17 ;
V_12 = sprintf ( V_9 , L_1 , V_10 ) ;
} else
V_12 = - V_16 ;
F_8 ( & V_13 ) ;
return V_12 ;
}
static T_1 F_10 ( struct V_2 * V_3 , struct V_7 * V_8 ,
char * V_9 )
{
struct V_1 * V_6 ;
int V_12 ;
F_5 ( & V_13 ) ;
V_6 = F_1 ( V_3 ) ;
if ( V_6 )
V_12 = sprintf ( V_9 , L_2 , V_6 -> V_18 ) ;
else
V_12 = - V_16 ;
F_8 ( & V_13 ) ;
return V_12 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 , F_3 ( * V_5 ) , V_2 ) ;
if ( F_12 ( V_5 -> V_19 ) ) {
F_5 ( & V_13 ) ;
F_13 ( & V_20 , V_5 -> V_21 ) ;
F_8 ( & V_13 ) ;
F_14 ( V_5 -> V_19 ) ;
}
F_14 ( V_5 ) ;
}
static int
F_15 ( struct V_22 * V_2 ,
const T_2 * V_23 )
{
T_2 V_24 ;
F_16 ( V_24 . V_25 , V_23 -> V_25 , V_2 -> V_26 . V_25 ,
V_27 ) ;
return F_17 ( V_23 -> V_25 , V_24 . V_25 , V_27 ) ;
}
static struct V_28 * F_18 ( struct V_1 * V_6 )
{
return V_6 -> V_2 -> V_3 -> V_29 -> V_30 ;
}
static void F_19 ( struct V_1 * V_6 )
{
struct V_28 * V_30 = F_18 ( V_6 ) ;
while ( V_6 -> V_18 < V_31 ) {
F_20 ( V_30 ) ;
V_6 -> V_18 ++ ;
}
}
static int F_21 ( struct V_1 * V_6 )
{
struct V_28 * V_30 = F_18 ( V_6 ) ;
int V_32 ;
if ( V_6 -> V_18 ) {
F_20 ( V_30 ) ;
goto V_33;
}
if ( ! F_22 ( V_30 ) )
return - V_16 ;
if ( V_6 -> V_2 -> V_34 ) {
V_32 = V_6 -> V_2 -> V_34 ( V_6 ) ;
if ( V_32 < 0 )
goto V_35;
}
if ( ! F_23 ( V_36 , V_6 -> V_2 -> V_26 ) )
F_19 ( V_6 ) ;
V_33:
V_6 -> V_18 ++ ;
return 0 ;
V_35:
F_24 ( V_30 ) ;
return V_32 ;
}
static void F_25 ( struct V_1 * V_6 )
{
if ( ! V_6 -> V_18 )
return;
V_6 -> V_18 -- ;
F_24 ( F_18 ( V_6 ) ) ;
if ( ! V_6 -> V_18 && V_6 -> V_2 -> V_37 ) {
F_26 ( V_6 ) ;
V_6 -> V_2 -> V_37 ( V_6 ) ;
}
if ( V_6 -> V_38 && V_6 -> V_38 -> V_39 ) {
V_6 -> V_38 -> V_39 ( V_6 -> V_38 -> V_3 , V_6 -> V_40 ) ;
V_6 -> V_38 = NULL ;
V_6 -> V_40 = NULL ;
}
}
enum V_41 F_27 ( struct V_1 * V_6 , T_3 V_42 )
{
enum V_41 V_43 ;
unsigned long V_44 = V_45 + F_28 ( 5000 ) ;
F_29 ( V_6 ) ;
do {
V_43 = F_30 ( V_6 , V_42 , NULL , NULL ) ;
if ( F_31 ( V_45 , V_44 ) ) {
F_32 ( V_6 -> V_2 -> V_3 , L_3 , V_46 ) ;
return V_47 ;
}
if ( V_43 != V_48 )
break;
F_33 () ;
} while ( 1 );
return V_43 ;
}
static int T_4 F_34 ( void )
{
enum V_49 V_50 ;
int V_12 = 0 ;
F_35 ( V_51 . V_25 , V_27 ) ;
F_36 ( V_52 , V_51 . V_25 ) ;
F_36 ( V_36 , V_51 . V_25 ) ;
F_36 ( V_53 , V_51 . V_25 ) ;
F_37 (cap, dma_cap_mask_all) {
V_54 [ V_50 ] = F_38 ( struct V_55 ) ;
if ( ! V_54 [ V_50 ] ) {
V_12 = - V_56 ;
break;
}
}
if ( V_12 ) {
F_39 ( L_4 ) ;
F_37 (cap, dma_cap_mask_all)
F_40 ( V_54 [ V_50 ] ) ;
}
return V_12 ;
}
struct V_1 * F_41 ( enum V_49 V_57 )
{
return F_42 ( V_54 [ V_57 ] -> V_6 ) ;
}
void F_43 ( void )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
F_44 () ;
F_45 (device, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node)
if ( V_6 -> V_18 )
V_2 -> V_58 ( V_6 ) ;
}
F_47 () ;
}
static bool F_48 ( struct V_1 * V_6 , int V_59 )
{
int V_60 = F_49 ( V_6 -> V_2 -> V_3 ) ;
return V_60 == - 1 || F_50 ( V_59 , F_51 ( V_60 ) ) ;
}
static struct V_1 * F_52 ( enum V_49 V_50 , int V_59 )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
struct V_1 * V_61 = NULL ;
struct V_1 * V_62 = NULL ;
F_46 (device, &dma_device_list, global_node) {
if ( ! F_23 ( V_50 , V_2 -> V_26 ) ||
F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node) {
if ( ! V_6 -> V_18 )
continue;
if ( ! V_61 || V_6 -> V_63 < V_61 -> V_63 )
V_61 = V_6 ;
if ( F_48 ( V_6 , V_59 ) )
if ( ! V_62 ||
V_6 -> V_63 < V_62 -> V_63 )
V_62 = V_6 ;
}
}
V_6 = V_62 ? V_62 : V_61 ;
if ( V_6 )
V_6 -> V_63 ++ ;
return V_6 ;
}
static void F_53 ( void )
{
struct V_1 * V_6 ;
struct V_22 * V_2 ;
int V_59 ;
int V_50 ;
F_37 (cap, dma_cap_mask_all)
F_6 (cpu)
F_7 ( V_54 [ V_50 ] , V_59 ) -> V_6 = NULL ;
F_46 (device, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node)
V_6 -> V_63 = 0 ;
}
if ( ! V_31 )
return;
F_37 (cap, dma_cap_mask_all)
F_54 (cpu) {
V_6 = F_52 ( V_50 , V_59 ) ;
F_7 ( V_54 [ V_50 ] , V_59 ) -> V_6 = V_6 ;
}
}
int F_55 ( struct V_1 * V_6 , struct V_64 * V_65 )
{
struct V_22 * V_2 ;
if ( ! V_6 || ! V_65 )
return - V_66 ;
V_2 = V_6 -> V_2 ;
if ( ! ( F_56 ( V_53 , V_2 -> V_26 . V_25 ) ||
F_56 ( V_67 , V_2 -> V_26 . V_25 ) ) )
return - V_68 ;
if ( ! V_2 -> V_69 )
return - V_68 ;
V_65 -> V_70 = V_2 -> V_70 ;
V_65 -> V_71 = V_2 -> V_71 ;
V_65 -> V_69 = V_2 -> V_69 ;
V_65 -> V_72 = V_2 -> V_72 ;
V_65 -> V_73 = V_2 -> V_73 ;
V_65 -> V_74 = V_2 -> V_74 ;
V_65 -> V_75 = ! ! ( V_2 -> V_76 && V_2 -> V_77 ) ;
V_65 -> V_78 = ! ! V_2 -> V_79 ;
return 0 ;
}
static struct V_1 * F_57 ( const T_2 * V_80 ,
struct V_22 * V_3 ,
T_5 V_81 , void * V_82 )
{
struct V_1 * V_6 ;
if ( V_80 && ! F_15 ( V_3 , V_80 ) ) {
F_58 ( V_3 -> V_3 , L_5 , V_46 ) ;
return NULL ;
}
if ( V_3 -> V_83 > 1 && ! F_23 ( V_36 , V_3 -> V_26 ) )
F_46 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 )
return NULL ;
}
F_46 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 ) {
F_58 ( V_3 -> V_3 , L_6 ,
V_46 , F_59 ( V_6 ) ) ;
continue;
}
if ( V_81 && ! V_81 ( V_6 , V_82 ) ) {
F_58 ( V_3 -> V_3 , L_7 ,
V_46 , F_59 ( V_6 ) ) ;
continue;
}
return V_6 ;
}
return NULL ;
}
static struct V_1 * F_60 ( struct V_22 * V_2 ,
const T_2 * V_80 ,
T_5 V_81 , void * V_82 )
{
struct V_1 * V_6 = F_57 ( V_80 , V_2 , V_81 , V_82 ) ;
int V_12 ;
if ( V_6 ) {
F_61 ( V_36 , V_2 -> V_26 ) ;
V_2 -> V_84 ++ ;
V_12 = F_21 ( V_6 ) ;
if ( V_12 ) {
if ( V_12 == - V_16 ) {
F_58 ( V_2 -> V_3 , L_8 ,
V_46 , F_59 ( V_6 ) ) ;
F_62 ( & V_2 -> V_85 ) ;
} else
F_58 ( V_2 -> V_3 ,
L_9 ,
V_46 , F_59 ( V_6 ) , V_12 ) ;
if ( -- V_2 -> V_84 == 0 )
F_63 ( V_36 , V_2 -> V_26 ) ;
V_6 = F_64 ( V_12 ) ;
}
}
return V_6 ? V_6 : F_64 ( - V_86 ) ;
}
struct V_1 * F_65 ( struct V_1 * V_6 )
{
int V_12 = - V_87 ;
F_5 ( & V_13 ) ;
if ( V_6 -> V_18 == 0 ) {
struct V_22 * V_2 = V_6 -> V_2 ;
F_61 ( V_36 , V_2 -> V_26 ) ;
V_2 -> V_84 ++ ;
V_12 = F_21 ( V_6 ) ;
if ( V_12 ) {
F_58 ( V_6 -> V_2 -> V_3 ,
L_9 ,
V_46 , F_59 ( V_6 ) , V_12 ) ;
V_6 = NULL ;
if ( -- V_2 -> V_84 == 0 )
F_63 ( V_36 , V_2 -> V_26 ) ;
}
} else
V_6 = NULL ;
F_8 ( & V_13 ) ;
return V_6 ;
}
struct V_1 * F_66 ( struct V_22 * V_2 )
{
T_2 V_80 ;
struct V_1 * V_6 ;
F_67 ( V_80 ) ;
F_61 ( V_53 , V_80 ) ;
F_5 ( & V_13 ) ;
V_6 = F_60 ( V_2 , & V_80 , NULL , NULL ) ;
F_8 ( & V_13 ) ;
return F_68 ( V_6 ) ? NULL : V_6 ;
}
struct V_1 * F_69 ( const T_2 * V_80 ,
T_5 V_81 , void * V_82 )
{
struct V_22 * V_2 , * V_88 ;
struct V_1 * V_6 = NULL ;
F_5 ( & V_13 ) ;
F_70 (device, _d, &dma_device_list, global_node) {
V_6 = F_60 ( V_2 , V_80 , V_81 , V_82 ) ;
if ( ! F_68 ( V_6 ) )
break;
V_6 = NULL ;
}
F_8 ( & V_13 ) ;
F_71 ( L_10 ,
V_46 ,
V_6 ? L_11 : L_12 ,
V_6 ? F_59 ( V_6 ) : NULL ) ;
return V_6 ;
}
static const struct V_89 * F_72 ( struct V_22 * V_2 ,
const char * V_90 ,
struct V_2 * V_3 )
{
int V_11 ;
if ( ! V_2 -> V_91 . V_92 )
return NULL ;
for ( V_11 = 0 ; V_11 < V_2 -> V_91 . V_92 ; V_11 ++ ) {
const struct V_89 * V_93 = & V_2 -> V_91 . V_93 [ V_11 ] ;
if ( ! strcmp ( V_93 -> V_94 , F_73 ( V_3 ) ) &&
! strcmp ( V_93 -> V_95 , V_90 ) )
return V_93 ;
}
return NULL ;
}
struct V_1 * F_74 ( struct V_2 * V_3 , const char * V_90 )
{
struct V_22 * V_96 , * V_88 ;
struct V_1 * V_6 = NULL ;
if ( V_3 -> V_97 )
V_6 = F_75 ( V_3 -> V_97 , V_90 ) ;
if ( F_76 ( V_3 ) && ! V_6 )
V_6 = F_77 ( V_3 , V_90 ) ;
if ( V_6 ) {
if ( ! F_68 ( V_6 ) || F_78 ( V_6 ) == - V_86 )
return V_6 ;
}
F_5 ( & V_13 ) ;
F_70 (d, _d, &dma_device_list, global_node) {
T_2 V_80 ;
const struct V_89 * V_93 = F_72 ( V_96 , V_90 , V_3 ) ;
if ( ! V_93 )
continue;
F_67 ( V_80 ) ;
F_61 ( V_53 , V_80 ) ;
V_6 = F_60 ( V_96 , & V_80 , V_96 -> V_91 . V_81 , V_93 -> V_98 ) ;
if ( ! F_68 ( V_6 ) )
break;
}
F_8 ( & V_13 ) ;
return V_6 ? V_6 : F_64 ( - V_86 ) ;
}
struct V_1 * F_79 ( struct V_2 * V_3 ,
const char * V_90 )
{
struct V_1 * V_99 = F_74 ( V_3 , V_90 ) ;
if ( F_68 ( V_99 ) )
return NULL ;
return V_99 ;
}
struct V_1 * F_80 ( const T_2 * V_80 )
{
struct V_1 * V_6 ;
if ( ! V_80 )
return F_64 ( - V_16 ) ;
V_6 = F_69 ( V_80 , NULL , NULL ) ;
if ( ! V_6 )
V_6 = F_64 ( - V_16 ) ;
return V_6 ;
}
void F_81 ( struct V_1 * V_6 )
{
F_5 ( & V_13 ) ;
F_82 ( V_6 -> V_18 != 1 ,
L_13 , V_6 -> V_18 ) ;
F_25 ( V_6 ) ;
if ( -- V_6 -> V_2 -> V_84 == 0 )
F_63 ( V_36 , V_6 -> V_2 -> V_26 ) ;
F_8 ( & V_13 ) ;
}
void F_83 ( void )
{
struct V_22 * V_2 , * V_88 ;
struct V_1 * V_6 ;
int V_12 ;
F_5 ( & V_13 ) ;
V_31 ++ ;
F_70 (device, _d, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node) {
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_62 ( & V_2 -> V_85 ) ;
break;
} else if ( V_12 )
F_58 ( V_6 -> V_2 -> V_3 ,
L_9 ,
V_46 , F_59 ( V_6 ) , V_12 ) ;
}
}
if ( V_31 == 1 )
F_53 () ;
F_8 ( & V_13 ) ;
}
void F_84 ( void )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
V_31 -- ;
F_85 ( V_31 < 0 ) ;
F_46 (device, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node)
F_25 ( V_6 ) ;
}
F_8 ( & V_13 ) ;
}
static bool F_86 ( struct V_22 * V_2 )
{
#ifdef F_87
if ( ! F_23 ( V_52 , V_2 -> V_26 ) )
return false ;
#endif
#if F_88 ( V_100 )
if ( ! F_23 ( V_101 , V_2 -> V_26 ) )
return false ;
#endif
#if F_88 ( V_102 )
if ( ! F_23 ( V_103 , V_2 -> V_26 ) )
return false ;
#ifndef F_89
if ( ! F_23 ( V_104 , V_2 -> V_26 ) )
return false ;
#endif
#endif
#if F_88 ( V_105 )
if ( ! F_23 ( V_106 , V_2 -> V_26 ) )
return false ;
#ifndef F_90
if ( ! F_23 ( V_107 , V_2 -> V_26 ) )
return false ;
#endif
#endif
return true ;
}
static int F_91 ( struct V_22 * V_2 )
{
int V_108 ;
F_5 ( & V_13 ) ;
V_108 = F_92 ( & V_20 , NULL , 0 , 0 , V_109 ) ;
if ( V_108 >= 0 )
V_2 -> V_21 = V_108 ;
F_8 ( & V_13 ) ;
return V_108 < 0 ? V_108 : 0 ;
}
int F_93 ( struct V_22 * V_2 )
{
int V_83 = 0 , V_108 ;
struct V_1 * V_6 ;
T_6 * V_19 ;
if ( ! V_2 )
return - V_16 ;
F_85 ( F_23 ( V_101 , V_2 -> V_26 ) &&
! V_2 -> V_110 ) ;
F_85 ( F_23 ( V_103 , V_2 -> V_26 ) &&
! V_2 -> V_111 ) ;
F_85 ( F_23 ( V_104 , V_2 -> V_26 ) &&
! V_2 -> V_112 ) ;
F_85 ( F_23 ( V_106 , V_2 -> V_26 ) &&
! V_2 -> V_113 ) ;
F_85 ( F_23 ( V_107 , V_2 -> V_26 ) &&
! V_2 -> V_114 ) ;
F_85 ( F_23 ( V_115 , V_2 -> V_26 ) &&
! V_2 -> V_116 ) ;
F_85 ( F_23 ( V_52 , V_2 -> V_26 ) &&
! V_2 -> V_117 ) ;
F_85 ( F_23 ( V_118 , V_2 -> V_26 ) &&
! V_2 -> V_119 ) ;
F_85 ( F_23 ( V_67 , V_2 -> V_26 ) &&
! V_2 -> V_120 ) ;
F_85 ( F_23 ( V_121 , V_2 -> V_26 ) &&
! V_2 -> V_122 ) ;
F_85 ( ! V_2 -> V_123 ) ;
F_85 ( ! V_2 -> V_58 ) ;
F_85 ( ! V_2 -> V_3 ) ;
if ( F_86 ( V_2 ) )
F_61 ( V_124 , V_2 -> V_26 ) ;
V_19 = F_94 ( sizeof( * V_19 ) , V_109 ) ;
if ( ! V_19 )
return - V_56 ;
V_108 = F_91 ( V_2 ) ;
if ( V_108 != 0 ) {
F_14 ( V_19 ) ;
return V_108 ;
}
F_95 ( V_19 , 0 ) ;
F_46 (chan, &device->channels, device_node) {
V_108 = - V_56 ;
V_6 -> V_14 = F_38 ( F_3 ( * V_6 -> V_14 ) ) ;
if ( V_6 -> V_14 == NULL )
goto V_35;
V_6 -> V_3 = F_96 ( sizeof( * V_6 -> V_3 ) , V_109 ) ;
if ( V_6 -> V_3 == NULL ) {
F_40 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
goto V_35;
}
V_6 -> V_125 = V_83 ++ ;
V_6 -> V_3 -> V_2 . V_126 = & V_127 ;
V_6 -> V_3 -> V_2 . V_128 = V_2 -> V_3 ;
V_6 -> V_3 -> V_6 = V_6 ;
V_6 -> V_3 -> V_19 = V_19 ;
V_6 -> V_3 -> V_21 = V_2 -> V_21 ;
F_97 ( V_19 ) ;
F_98 ( & V_6 -> V_3 -> V_2 , L_14 ,
V_2 -> V_21 , V_6 -> V_125 ) ;
V_108 = F_99 ( & V_6 -> V_3 -> V_2 ) ;
if ( V_108 ) {
F_40 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_14 ( V_6 -> V_3 ) ;
F_100 ( V_19 ) ;
goto V_35;
}
V_6 -> V_18 = 0 ;
}
if ( ! V_83 ) {
F_32 ( V_2 -> V_3 , L_15 , V_46 ) ;
V_108 = - V_16 ;
goto V_35;
}
V_2 -> V_83 = V_83 ;
F_5 ( & V_13 ) ;
if ( V_31 && ! F_23 ( V_36 , V_2 -> V_26 ) )
F_46 (chan, &device->channels, device_node) {
if ( F_21 ( V_6 ) == - V_16 ) {
V_108 = - V_16 ;
F_8 ( & V_13 ) ;
goto V_35;
}
}
F_101 ( & V_2 -> V_85 , & V_129 ) ;
if ( F_23 ( V_36 , V_2 -> V_26 ) )
V_2 -> V_84 ++ ;
F_53 () ;
F_8 ( & V_13 ) ;
return 0 ;
V_35:
if ( F_102 ( V_19 ) == 0 ) {
F_5 ( & V_13 ) ;
F_13 ( & V_20 , V_2 -> V_21 ) ;
F_8 ( & V_13 ) ;
F_14 ( V_19 ) ;
return V_108 ;
}
F_46 (chan, &device->channels, device_node) {
if ( V_6 -> V_14 == NULL )
continue;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_103 ( & V_6 -> V_3 -> V_2 ) ;
F_40 ( V_6 -> V_14 ) ;
}
return V_108 ;
}
void F_104 ( struct V_22 * V_2 )
{
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
F_62 ( & V_2 -> V_85 ) ;
F_53 () ;
F_8 ( & V_13 ) ;
F_46 (chan, &device->channels, device_node) {
F_82 ( V_6 -> V_18 ,
L_16 ,
V_46 , V_6 -> V_18 ) ;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_103 ( & V_6 -> V_3 -> V_2 ) ;
F_40 ( V_6 -> V_14 ) ;
}
}
static struct V_130 * F_105 ( int V_131 )
{
int V_132 = F_106 ( V_131 ) ;
switch ( V_132 ) {
case 0 ... 1 :
return & V_133 [ 0 ] ;
case 2 ... 4 :
return & V_133 [ 1 ] ;
case 5 ... 7 :
return & V_133 [ 2 ] ;
case 8 :
return & V_133 [ 3 ] ;
default:
F_107 () ;
return NULL ;
}
}
static void F_108 ( struct V_134 * V_134 )
{
struct V_135 * V_136 = F_2 ( V_134 , F_3 ( * V_136 ) , V_134 ) ;
struct V_2 * V_3 = V_136 -> V_3 ;
int V_137 , V_11 ;
V_137 = V_136 -> V_138 ;
for ( V_11 = 0 ; V_11 < V_137 ; V_11 ++ )
F_109 ( V_3 , V_136 -> V_139 [ V_11 ] , V_136 -> V_140 ,
V_141 ) ;
V_137 += V_136 -> V_142 ;
for (; V_11 < V_137 ; V_11 ++ )
F_109 ( V_3 , V_136 -> V_139 [ V_11 ] , V_136 -> V_140 ,
V_143 ) ;
V_137 += V_136 -> V_144 ;
for (; V_11 < V_137 ; V_11 ++ ) {
if ( V_136 -> V_139 [ V_11 ] == 0 )
continue;
F_109 ( V_3 , V_136 -> V_139 [ V_11 ] , V_136 -> V_140 ,
V_145 ) ;
}
V_137 = V_136 -> V_146 ;
F_110 ( V_136 , F_105 ( V_137 ) -> V_147 ) ;
}
void F_111 ( struct V_135 * V_136 )
{
if ( V_136 )
F_112 ( & V_136 -> V_134 , F_108 ) ;
}
static void F_113 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_114 ( V_133 ) ; V_11 ++ ) {
struct V_130 * V_148 = & V_133 [ V_11 ] ;
F_115 ( V_148 -> V_147 ) ;
V_148 -> V_147 = NULL ;
F_116 ( V_148 -> V_149 ) ;
V_148 -> V_149 = NULL ;
}
}
static int T_4 F_117 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_114 ( V_133 ) ; V_11 ++ ) {
struct V_130 * V_148 = & V_133 [ V_11 ] ;
T_7 V_150 ;
V_150 = sizeof( struct V_135 ) +
sizeof( V_151 ) * V_148 -> V_150 ;
V_148 -> V_149 = F_118 ( V_148 -> V_90 , V_150 , 0 ,
V_152 , NULL ) ;
if ( ! V_148 -> V_149 )
break;
V_148 -> V_147 = F_119 ( 1 , V_148 -> V_149 ) ;
if ( ! V_148 -> V_147 )
break;
}
if ( V_11 == F_114 ( V_133 ) )
return 0 ;
F_113 () ;
return - V_56 ;
}
struct V_135 *
F_120 ( struct V_2 * V_3 , int V_131 , T_8 V_153 )
{
struct V_135 * V_136 ;
V_136 = F_121 ( F_105 ( V_131 ) -> V_147 , V_153 ) ;
if ( ! V_136 )
return NULL ;
memset ( V_136 , 0 , sizeof( * V_136 ) ) ;
F_122 ( & V_136 -> V_134 ) ;
V_136 -> V_3 = V_3 ;
V_136 -> V_146 = V_131 ;
return V_136 ;
}
void F_123 ( struct V_154 * V_155 ,
struct V_1 * V_6 )
{
V_155 -> V_6 = V_6 ;
#ifdef F_124
F_125 ( & V_155 -> V_156 ) ;
#endif
}
enum V_41
F_126 ( struct V_154 * V_155 )
{
unsigned long V_44 = V_45 + F_28 ( 5000 ) ;
if ( ! V_155 )
return V_157 ;
while ( V_155 -> V_42 == - V_87 ) {
if ( F_31 ( V_45 , V_44 ) ) {
F_32 ( V_155 -> V_6 -> V_2 -> V_3 ,
L_17 ,
V_46 ) ;
return V_47 ;
}
F_33 () ;
}
return F_27 ( V_155 -> V_6 , V_155 -> V_42 ) ;
}
void F_127 ( struct V_154 * V_155 )
{
struct V_154 * V_158 = F_128 ( V_155 ) ;
struct V_154 * V_159 ;
struct V_1 * V_6 ;
if ( ! V_158 )
return;
F_129 ( V_155 ) ;
V_6 = V_158 -> V_6 ;
for (; V_158 ; V_158 = V_159 ) {
F_130 ( V_158 ) ;
F_131 ( V_158 ) ;
V_159 = F_128 ( V_158 ) ;
if ( V_159 && V_159 -> V_6 == V_6 )
F_129 ( V_158 ) ;
else
V_159 = NULL ;
F_132 ( V_158 ) ;
V_158 -> V_160 ( V_158 ) ;
}
V_6 -> V_2 -> V_58 ( V_6 ) ;
}
static int T_4 F_133 ( void )
{
int V_12 = F_117 () ;
if ( V_12 )
return V_12 ;
return F_134 ( & V_127 ) ;
}
