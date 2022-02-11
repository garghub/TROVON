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
F_32 ( L_3 , V_46 ) ;
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
F_32 ( L_4 ) ;
F_37 (cap, dma_cap_mask_all)
F_39 ( V_54 [ V_50 ] ) ;
}
return V_12 ;
}
struct V_1 * F_40 ( enum V_49 V_57 )
{
return F_41 ( V_54 [ V_57 ] -> V_6 ) ;
}
void F_42 ( void )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
F_43 () ;
F_44 (device, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_45 (chan, &device->channels, device_node)
if ( V_6 -> V_18 )
V_2 -> V_58 ( V_6 ) ;
}
F_46 () ;
}
static bool F_47 ( struct V_1 * V_6 , int V_59 )
{
int V_60 = F_48 ( V_6 -> V_2 -> V_3 ) ;
return V_60 == - 1 || F_49 ( V_59 , F_50 ( V_60 ) ) ;
}
static struct V_1 * F_51 ( enum V_49 V_50 , int V_59 )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
struct V_1 * V_61 = NULL ;
struct V_1 * V_62 = NULL ;
F_45 (device, &dma_device_list, global_node) {
if ( ! F_23 ( V_50 , V_2 -> V_26 ) ||
F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_45 (chan, &device->channels, device_node) {
if ( ! V_6 -> V_18 )
continue;
if ( ! V_61 || V_6 -> V_63 < V_61 -> V_63 )
V_61 = V_6 ;
if ( F_47 ( V_6 , V_59 ) )
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
static void F_52 ( void )
{
struct V_1 * V_6 ;
struct V_22 * V_2 ;
int V_59 ;
int V_50 ;
F_37 (cap, dma_cap_mask_all)
F_6 (cpu)
F_7 ( V_54 [ V_50 ] , V_59 ) -> V_6 = NULL ;
F_45 (device, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_45 (chan, &device->channels, device_node)
V_6 -> V_63 = 0 ;
}
if ( ! V_31 )
return;
F_37 (cap, dma_cap_mask_all)
F_53 (cpu) {
V_6 = F_51 ( V_50 , V_59 ) ;
F_7 ( V_54 [ V_50 ] , V_59 ) -> V_6 = V_6 ;
}
}
int F_54 ( struct V_1 * V_6 , struct V_64 * V_65 )
{
struct V_22 * V_2 ;
if ( ! V_6 || ! V_65 )
return - V_66 ;
V_2 = V_6 -> V_2 ;
if ( ! F_55 ( V_53 , V_2 -> V_26 . V_25 ) )
return - V_67 ;
if ( ! V_2 -> V_68 )
return - V_67 ;
V_65 -> V_69 = V_2 -> V_69 ;
V_65 -> V_70 = V_2 -> V_70 ;
V_65 -> V_68 = V_2 -> V_68 ;
V_65 -> V_71 = V_2 -> V_71 ;
V_65 -> V_72 = V_2 -> V_72 ;
V_65 -> V_73 = V_2 -> V_73 ;
V_65 -> V_74 = ! ! ( V_2 -> V_75 && V_2 -> V_76 ) ;
V_65 -> V_77 = ! ! V_2 -> V_78 ;
return 0 ;
}
static struct V_1 * F_56 ( const T_2 * V_79 ,
struct V_22 * V_3 ,
T_5 V_80 , void * V_81 )
{
struct V_1 * V_6 ;
if ( V_79 && ! F_15 ( V_3 , V_79 ) ) {
F_57 ( L_5 , V_46 ) ;
return NULL ;
}
if ( V_3 -> V_82 > 1 && ! F_23 ( V_36 , V_3 -> V_26 ) )
F_45 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 )
return NULL ;
}
F_45 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 ) {
F_57 ( L_6 ,
V_46 , F_58 ( V_6 ) ) ;
continue;
}
if ( V_80 && ! V_80 ( V_6 , V_81 ) ) {
F_57 ( L_7 ,
V_46 , F_58 ( V_6 ) ) ;
continue;
}
return V_6 ;
}
return NULL ;
}
static struct V_1 * F_59 ( struct V_22 * V_2 ,
const T_2 * V_79 ,
T_5 V_80 , void * V_81 )
{
struct V_1 * V_6 = F_56 ( V_79 , V_2 , V_80 , V_81 ) ;
int V_12 ;
if ( V_6 ) {
F_60 ( V_36 , V_2 -> V_26 ) ;
V_2 -> V_83 ++ ;
V_12 = F_21 ( V_6 ) ;
if ( V_12 ) {
if ( V_12 == - V_16 ) {
F_57 ( L_8 , V_46 ,
F_58 ( V_6 ) ) ;
F_61 ( & V_2 -> V_84 ) ;
} else
F_57 ( L_9 ,
V_46 , F_58 ( V_6 ) , V_12 ) ;
if ( -- V_2 -> V_83 == 0 )
F_62 ( V_36 , V_2 -> V_26 ) ;
V_6 = F_63 ( V_12 ) ;
}
}
return V_6 ? V_6 : F_63 ( - V_85 ) ;
}
struct V_1 * F_64 ( struct V_1 * V_6 )
{
int V_12 = - V_86 ;
F_5 ( & V_13 ) ;
if ( V_6 -> V_18 == 0 ) {
struct V_22 * V_2 = V_6 -> V_2 ;
F_60 ( V_36 , V_2 -> V_26 ) ;
V_2 -> V_83 ++ ;
V_12 = F_21 ( V_6 ) ;
if ( V_12 ) {
F_57 ( L_9 ,
V_46 , F_58 ( V_6 ) , V_12 ) ;
V_6 = NULL ;
if ( -- V_2 -> V_83 == 0 )
F_62 ( V_36 , V_2 -> V_26 ) ;
}
} else
V_6 = NULL ;
F_8 ( & V_13 ) ;
return V_6 ;
}
struct V_1 * F_65 ( struct V_22 * V_2 )
{
T_2 V_79 ;
struct V_1 * V_6 ;
F_66 ( V_79 ) ;
F_60 ( V_53 , V_79 ) ;
F_5 ( & V_13 ) ;
V_6 = F_59 ( V_2 , & V_79 , NULL , NULL ) ;
F_8 ( & V_13 ) ;
return F_67 ( V_6 ) ? NULL : V_6 ;
}
struct V_1 * F_68 ( const T_2 * V_79 ,
T_5 V_80 , void * V_81 )
{
struct V_22 * V_2 , * V_87 ;
struct V_1 * V_6 = NULL ;
F_5 ( & V_13 ) ;
F_69 (device, _d, &dma_device_list, global_node) {
V_6 = F_59 ( V_2 , V_79 , V_80 , V_81 ) ;
if ( ! F_67 ( V_6 ) )
break;
V_6 = NULL ;
}
F_8 ( & V_13 ) ;
F_57 ( L_10 ,
V_46 ,
V_6 ? L_11 : L_12 ,
V_6 ? F_58 ( V_6 ) : NULL ) ;
return V_6 ;
}
static const struct V_88 * F_70 ( struct V_22 * V_2 ,
const char * V_89 ,
struct V_2 * V_3 )
{
int V_11 ;
if ( ! V_2 -> V_90 . V_91 )
return NULL ;
for ( V_11 = 0 ; V_11 < V_2 -> V_90 . V_91 ; V_11 ++ ) {
const struct V_88 * V_92 = & V_2 -> V_90 . V_92 [ V_11 ] ;
if ( ! strcmp ( V_92 -> V_93 , F_71 ( V_3 ) ) &&
! strcmp ( V_92 -> V_94 , V_89 ) )
return V_92 ;
}
return NULL ;
}
struct V_1 * F_72 ( struct V_2 * V_3 , const char * V_89 )
{
struct V_22 * V_95 , * V_87 ;
struct V_1 * V_6 = NULL ;
if ( V_3 -> V_96 )
V_6 = F_73 ( V_3 -> V_96 , V_89 ) ;
if ( F_74 ( V_3 ) && ! V_6 )
V_6 = F_75 ( V_3 , V_89 ) ;
if ( V_6 ) {
if ( ! F_67 ( V_6 ) || F_76 ( V_6 ) == - V_85 )
return V_6 ;
}
F_5 ( & V_13 ) ;
F_69 (d, _d, &dma_device_list, global_node) {
T_2 V_79 ;
const struct V_88 * V_92 = F_70 ( V_95 , V_89 , V_3 ) ;
if ( ! V_92 )
continue;
F_66 ( V_79 ) ;
F_60 ( V_53 , V_79 ) ;
V_6 = F_59 ( V_95 , & V_79 , V_95 -> V_90 . V_80 , V_92 -> V_97 ) ;
if ( ! F_67 ( V_6 ) )
break;
}
F_8 ( & V_13 ) ;
return V_6 ? V_6 : F_63 ( - V_85 ) ;
}
struct V_1 * F_77 ( struct V_2 * V_3 ,
const char * V_89 )
{
struct V_1 * V_98 = F_72 ( V_3 , V_89 ) ;
if ( F_67 ( V_98 ) )
return NULL ;
return V_98 ;
}
struct V_1 * F_78 ( const T_2 * V_79 )
{
struct V_1 * V_6 ;
if ( ! V_79 )
return F_63 ( - V_16 ) ;
V_6 = F_68 ( V_79 , NULL , NULL ) ;
if ( ! V_6 )
V_6 = F_63 ( - V_16 ) ;
return V_6 ;
}
void F_79 ( struct V_1 * V_6 )
{
F_5 ( & V_13 ) ;
F_80 ( V_6 -> V_18 != 1 ,
L_13 , V_6 -> V_18 ) ;
F_25 ( V_6 ) ;
if ( -- V_6 -> V_2 -> V_83 == 0 )
F_62 ( V_36 , V_6 -> V_2 -> V_26 ) ;
F_8 ( & V_13 ) ;
}
void F_81 ( void )
{
struct V_22 * V_2 , * V_87 ;
struct V_1 * V_6 ;
int V_12 ;
F_5 ( & V_13 ) ;
V_31 ++ ;
F_69 (device, _d, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_45 (chan, &device->channels, device_node) {
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_61 ( & V_2 -> V_84 ) ;
break;
} else if ( V_12 )
F_57 ( L_9 ,
V_46 , F_58 ( V_6 ) , V_12 ) ;
}
}
if ( V_31 == 1 )
F_52 () ;
F_8 ( & V_13 ) ;
}
void F_82 ( void )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
V_31 -- ;
F_83 ( V_31 < 0 ) ;
F_45 (device, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_45 (chan, &device->channels, device_node)
F_25 ( V_6 ) ;
}
F_8 ( & V_13 ) ;
}
static bool F_84 ( struct V_22 * V_2 )
{
#ifdef F_85
if ( ! F_23 ( V_52 , V_2 -> V_26 ) )
return false ;
#endif
#if F_86 ( V_99 ) || F_86 ( V_100 )
if ( ! F_23 ( V_101 , V_2 -> V_26 ) )
return false ;
#endif
#if F_86 ( V_102 ) || F_86 ( V_103 )
if ( ! F_23 ( V_104 , V_2 -> V_26 ) )
return false ;
#ifndef F_87
if ( ! F_23 ( V_105 , V_2 -> V_26 ) )
return false ;
#endif
#endif
#if F_86 ( V_106 ) || F_86 ( V_107 )
if ( ! F_23 ( V_108 , V_2 -> V_26 ) )
return false ;
#ifndef F_88
if ( ! F_23 ( V_109 , V_2 -> V_26 ) )
return false ;
#endif
#endif
return true ;
}
static int F_89 ( struct V_22 * V_2 )
{
int V_110 ;
F_5 ( & V_13 ) ;
V_110 = F_90 ( & V_20 , NULL , 0 , 0 , V_111 ) ;
if ( V_110 >= 0 )
V_2 -> V_21 = V_110 ;
F_8 ( & V_13 ) ;
return V_110 < 0 ? V_110 : 0 ;
}
int F_91 ( struct V_22 * V_2 )
{
int V_82 = 0 , V_110 ;
struct V_1 * V_6 ;
T_6 * V_19 ;
if ( ! V_2 )
return - V_16 ;
F_83 ( F_23 ( V_101 , V_2 -> V_26 ) &&
! V_2 -> V_112 ) ;
F_83 ( F_23 ( V_104 , V_2 -> V_26 ) &&
! V_2 -> V_113 ) ;
F_83 ( F_23 ( V_105 , V_2 -> V_26 ) &&
! V_2 -> V_114 ) ;
F_83 ( F_23 ( V_108 , V_2 -> V_26 ) &&
! V_2 -> V_115 ) ;
F_83 ( F_23 ( V_109 , V_2 -> V_26 ) &&
! V_2 -> V_116 ) ;
F_83 ( F_23 ( V_117 , V_2 -> V_26 ) &&
! V_2 -> V_118 ) ;
F_83 ( F_23 ( V_52 , V_2 -> V_26 ) &&
! V_2 -> V_119 ) ;
F_83 ( F_23 ( V_120 , V_2 -> V_26 ) &&
! V_2 -> V_121 ) ;
F_83 ( F_23 ( V_122 , V_2 -> V_26 ) &&
! V_2 -> V_123 ) ;
F_83 ( F_23 ( V_124 , V_2 -> V_26 ) &&
! V_2 -> V_125 ) ;
F_83 ( ! V_2 -> V_126 ) ;
F_83 ( ! V_2 -> V_58 ) ;
F_83 ( ! V_2 -> V_3 ) ;
if ( F_84 ( V_2 ) )
F_60 ( V_127 , V_2 -> V_26 ) ;
V_19 = F_92 ( sizeof( * V_19 ) , V_111 ) ;
if ( ! V_19 )
return - V_56 ;
V_110 = F_89 ( V_2 ) ;
if ( V_110 != 0 ) {
F_14 ( V_19 ) ;
return V_110 ;
}
F_93 ( V_19 , 0 ) ;
F_45 (chan, &device->channels, device_node) {
V_110 = - V_56 ;
V_6 -> V_14 = F_38 ( F_3 ( * V_6 -> V_14 ) ) ;
if ( V_6 -> V_14 == NULL )
goto V_35;
V_6 -> V_3 = F_94 ( sizeof( * V_6 -> V_3 ) , V_111 ) ;
if ( V_6 -> V_3 == NULL ) {
F_39 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
goto V_35;
}
V_6 -> V_128 = V_82 ++ ;
V_6 -> V_3 -> V_2 . V_129 = & V_130 ;
V_6 -> V_3 -> V_2 . V_131 = V_2 -> V_3 ;
V_6 -> V_3 -> V_6 = V_6 ;
V_6 -> V_3 -> V_19 = V_19 ;
V_6 -> V_3 -> V_21 = V_2 -> V_21 ;
F_95 ( V_19 ) ;
F_96 ( & V_6 -> V_3 -> V_2 , L_14 ,
V_2 -> V_21 , V_6 -> V_128 ) ;
V_110 = F_97 ( & V_6 -> V_3 -> V_2 ) ;
if ( V_110 ) {
F_39 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_14 ( V_6 -> V_3 ) ;
F_98 ( V_19 ) ;
goto V_35;
}
V_6 -> V_18 = 0 ;
}
V_2 -> V_82 = V_82 ;
F_5 ( & V_13 ) ;
if ( V_31 && ! F_23 ( V_36 , V_2 -> V_26 ) )
F_45 (chan, &device->channels, device_node) {
if ( F_21 ( V_6 ) == - V_16 ) {
V_110 = - V_16 ;
F_8 ( & V_13 ) ;
goto V_35;
}
}
F_99 ( & V_2 -> V_84 , & V_132 ) ;
if ( F_23 ( V_36 , V_2 -> V_26 ) )
V_2 -> V_83 ++ ;
F_52 () ;
F_8 ( & V_13 ) ;
return 0 ;
V_35:
if ( F_100 ( V_19 ) == 0 ) {
F_5 ( & V_13 ) ;
F_13 ( & V_20 , V_2 -> V_21 ) ;
F_8 ( & V_13 ) ;
F_14 ( V_19 ) ;
return V_110 ;
}
F_45 (chan, &device->channels, device_node) {
if ( V_6 -> V_14 == NULL )
continue;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_101 ( & V_6 -> V_3 -> V_2 ) ;
F_39 ( V_6 -> V_14 ) ;
}
return V_110 ;
}
void F_102 ( struct V_22 * V_2 )
{
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
F_61 ( & V_2 -> V_84 ) ;
F_52 () ;
F_8 ( & V_13 ) ;
F_45 (chan, &device->channels, device_node) {
F_80 ( V_6 -> V_18 ,
L_15 ,
V_46 , V_6 -> V_18 ) ;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_101 ( & V_6 -> V_3 -> V_2 ) ;
F_39 ( V_6 -> V_14 ) ;
}
}
static struct V_133 * F_103 ( int V_134 )
{
int V_135 = F_104 ( V_134 ) ;
switch ( V_135 ) {
case 0 ... 1 :
return & V_136 [ 0 ] ;
case 2 ... 4 :
return & V_136 [ 1 ] ;
case 5 ... 7 :
return & V_136 [ 2 ] ;
case 8 :
return & V_136 [ 3 ] ;
default:
F_105 () ;
return NULL ;
}
}
static void F_106 ( struct V_137 * V_137 )
{
struct V_138 * V_139 = F_2 ( V_137 , F_3 ( * V_139 ) , V_137 ) ;
struct V_2 * V_3 = V_139 -> V_3 ;
int V_140 , V_11 ;
V_140 = V_139 -> V_141 ;
for ( V_11 = 0 ; V_11 < V_140 ; V_11 ++ )
F_107 ( V_3 , V_139 -> V_142 [ V_11 ] , V_139 -> V_143 ,
V_144 ) ;
V_140 += V_139 -> V_145 ;
for (; V_11 < V_140 ; V_11 ++ )
F_107 ( V_3 , V_139 -> V_142 [ V_11 ] , V_139 -> V_143 ,
V_146 ) ;
V_140 += V_139 -> V_147 ;
for (; V_11 < V_140 ; V_11 ++ ) {
if ( V_139 -> V_142 [ V_11 ] == 0 )
continue;
F_107 ( V_3 , V_139 -> V_142 [ V_11 ] , V_139 -> V_143 ,
V_148 ) ;
}
V_140 = V_139 -> V_149 ;
F_108 ( V_139 , F_103 ( V_140 ) -> V_150 ) ;
}
void F_109 ( struct V_138 * V_139 )
{
if ( V_139 )
F_110 ( & V_139 -> V_137 , F_106 ) ;
}
static void F_111 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_112 ( V_136 ) ; V_11 ++ ) {
struct V_133 * V_151 = & V_136 [ V_11 ] ;
F_113 ( V_151 -> V_150 ) ;
V_151 -> V_150 = NULL ;
F_114 ( V_151 -> V_152 ) ;
V_151 -> V_152 = NULL ;
}
}
static int T_4 F_115 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_112 ( V_136 ) ; V_11 ++ ) {
struct V_133 * V_151 = & V_136 [ V_11 ] ;
T_7 V_153 ;
V_153 = sizeof( struct V_138 ) +
sizeof( V_154 ) * V_151 -> V_153 ;
V_151 -> V_152 = F_116 ( V_151 -> V_89 , V_153 , 0 ,
V_155 , NULL ) ;
if ( ! V_151 -> V_152 )
break;
V_151 -> V_150 = F_117 ( 1 , V_151 -> V_152 ) ;
if ( ! V_151 -> V_150 )
break;
}
if ( V_11 == F_112 ( V_136 ) )
return 0 ;
F_111 () ;
return - V_56 ;
}
struct V_138 *
F_118 ( struct V_2 * V_3 , int V_134 , T_8 V_156 )
{
struct V_138 * V_139 ;
V_139 = F_119 ( F_103 ( V_134 ) -> V_150 , V_156 ) ;
if ( ! V_139 )
return NULL ;
memset ( V_139 , 0 , sizeof( * V_139 ) ) ;
F_120 ( & V_139 -> V_137 ) ;
V_139 -> V_3 = V_3 ;
V_139 -> V_149 = V_134 ;
return V_139 ;
}
void F_121 ( struct V_157 * V_158 ,
struct V_1 * V_6 )
{
V_158 -> V_6 = V_6 ;
#ifdef F_122
F_123 ( & V_158 -> V_159 ) ;
#endif
}
enum V_41
F_124 ( struct V_157 * V_158 )
{
unsigned long V_44 = V_45 + F_28 ( 5000 ) ;
if ( ! V_158 )
return V_160 ;
while ( V_158 -> V_42 == - V_86 ) {
if ( F_31 ( V_45 , V_44 ) ) {
F_32 ( L_16 ,
V_46 ) ;
return V_47 ;
}
F_33 () ;
}
return F_27 ( V_158 -> V_6 , V_158 -> V_42 ) ;
}
void F_125 ( struct V_157 * V_158 )
{
struct V_157 * V_161 = F_126 ( V_158 ) ;
struct V_157 * V_162 ;
struct V_1 * V_6 ;
if ( ! V_161 )
return;
F_127 ( V_158 ) ;
V_6 = V_161 -> V_6 ;
for (; V_161 ; V_161 = V_162 ) {
F_128 ( V_161 ) ;
F_129 ( V_161 ) ;
V_162 = F_126 ( V_161 ) ;
if ( V_162 && V_162 -> V_6 == V_6 )
F_127 ( V_161 ) ;
else
V_162 = NULL ;
F_130 ( V_161 ) ;
V_161 -> V_163 ( V_161 ) ;
}
V_6 -> V_2 -> V_58 ( V_6 ) ;
}
static int T_4 F_131 ( void )
{
int V_12 = F_115 () ;
if ( V_12 )
return V_12 ;
return F_132 ( & V_130 ) ;
}
