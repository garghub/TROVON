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
if ( ! V_6 -> V_18 && V_6 -> V_2 -> V_37 )
V_6 -> V_2 -> V_37 ( V_6 ) ;
if ( V_6 -> V_38 && V_6 -> V_38 -> V_39 ) {
V_6 -> V_38 -> V_39 ( V_6 -> V_38 -> V_3 , V_6 -> V_40 ) ;
V_6 -> V_38 = NULL ;
V_6 -> V_40 = NULL ;
}
}
enum V_41 F_26 ( struct V_1 * V_6 , T_3 V_42 )
{
enum V_41 V_43 ;
unsigned long V_44 = V_45 + F_27 ( 5000 ) ;
F_28 ( V_6 ) ;
do {
V_43 = F_29 ( V_6 , V_42 , NULL , NULL ) ;
if ( F_30 ( V_45 , V_44 ) ) {
F_31 ( L_3 , V_46 ) ;
return V_47 ;
}
if ( V_43 != V_48 )
break;
F_32 () ;
} while ( 1 );
return V_43 ;
}
static int T_4 F_33 ( void )
{
enum V_49 V_50 ;
int V_12 = 0 ;
F_34 ( V_51 . V_25 , V_27 ) ;
F_35 ( V_52 , V_51 . V_25 ) ;
F_35 ( V_36 , V_51 . V_25 ) ;
F_35 ( V_53 , V_51 . V_25 ) ;
F_36 (cap, dma_cap_mask_all) {
V_54 [ V_50 ] = F_37 ( struct V_55 ) ;
if ( ! V_54 [ V_50 ] ) {
V_12 = - V_56 ;
break;
}
}
if ( V_12 ) {
F_31 ( L_4 ) ;
F_36 (cap, dma_cap_mask_all)
F_38 ( V_54 [ V_50 ] ) ;
}
return V_12 ;
}
struct V_1 * F_39 ( enum V_49 V_57 )
{
return F_40 ( V_54 [ V_57 ] -> V_6 ) ;
}
void F_41 ( void )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
F_42 () ;
F_43 (device, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_44 (chan, &device->channels, device_node)
if ( V_6 -> V_18 )
V_2 -> V_58 ( V_6 ) ;
}
F_45 () ;
}
static bool F_46 ( struct V_1 * V_6 , int V_59 )
{
int V_60 = F_47 ( V_6 -> V_2 -> V_3 ) ;
return V_60 == - 1 || F_48 ( V_59 , F_49 ( V_60 ) ) ;
}
static struct V_1 * F_50 ( enum V_49 V_50 , int V_59 )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
struct V_1 * V_61 = NULL ;
struct V_1 * V_62 = NULL ;
F_44 (device, &dma_device_list, global_node) {
if ( ! F_23 ( V_50 , V_2 -> V_26 ) ||
F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_44 (chan, &device->channels, device_node) {
if ( ! V_6 -> V_18 )
continue;
if ( ! V_61 || V_6 -> V_63 < V_61 -> V_63 )
V_61 = V_6 ;
if ( F_46 ( V_6 , V_59 ) )
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
static void F_51 ( void )
{
struct V_1 * V_6 ;
struct V_22 * V_2 ;
int V_59 ;
int V_50 ;
F_36 (cap, dma_cap_mask_all)
F_6 (cpu)
F_7 ( V_54 [ V_50 ] , V_59 ) -> V_6 = NULL ;
F_44 (device, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_44 (chan, &device->channels, device_node)
V_6 -> V_63 = 0 ;
}
if ( ! V_31 )
return;
F_36 (cap, dma_cap_mask_all)
F_52 (cpu) {
V_6 = F_50 ( V_50 , V_59 ) ;
F_7 ( V_54 [ V_50 ] , V_59 ) -> V_6 = V_6 ;
}
}
int F_53 ( struct V_1 * V_6 , struct V_64 * V_65 )
{
struct V_22 * V_2 ;
if ( ! V_6 || ! V_65 )
return - V_66 ;
V_2 = V_6 -> V_2 ;
if ( ! F_54 ( V_53 , V_2 -> V_26 . V_25 ) )
return - V_67 ;
if ( ! V_2 -> V_68 )
return - V_67 ;
V_65 -> V_69 = V_2 -> V_69 ;
V_65 -> V_70 = V_2 -> V_70 ;
V_65 -> V_68 = V_2 -> V_68 ;
V_65 -> V_71 = V_2 -> V_71 ;
V_65 -> V_72 = ! ! ( V_2 -> V_73 && V_2 -> V_74 ) ;
V_65 -> V_75 = ! ! V_2 -> V_76 ;
return 0 ;
}
static struct V_1 * F_55 ( const T_2 * V_77 ,
struct V_22 * V_3 ,
T_5 V_78 , void * V_79 )
{
struct V_1 * V_6 ;
if ( ! F_15 ( V_3 , V_77 ) ) {
F_56 ( L_5 , V_46 ) ;
return NULL ;
}
if ( V_3 -> V_80 > 1 && ! F_23 ( V_36 , V_3 -> V_26 ) )
F_44 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 )
return NULL ;
}
F_44 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 ) {
F_56 ( L_6 ,
V_46 , F_57 ( V_6 ) ) ;
continue;
}
if ( V_78 && ! V_78 ( V_6 , V_79 ) ) {
F_56 ( L_7 ,
V_46 , F_57 ( V_6 ) ) ;
continue;
}
return V_6 ;
}
return NULL ;
}
struct V_1 * F_58 ( struct V_1 * V_6 )
{
int V_12 = - V_81 ;
F_5 ( & V_13 ) ;
if ( V_6 -> V_18 == 0 ) {
V_12 = F_21 ( V_6 ) ;
if ( V_12 )
F_56 ( L_8 ,
V_46 , F_57 ( V_6 ) , V_12 ) ;
} else
V_6 = NULL ;
F_8 ( & V_13 ) ;
return V_6 ;
}
struct V_1 * F_59 ( struct V_22 * V_2 )
{
T_2 V_77 ;
struct V_1 * V_6 ;
int V_12 ;
F_60 ( V_77 ) ;
F_61 ( V_53 , V_77 ) ;
F_5 ( & V_13 ) ;
V_6 = F_55 ( & V_77 , V_2 , NULL , NULL ) ;
if ( V_6 ) {
F_61 ( V_36 , V_2 -> V_26 ) ;
V_2 -> V_82 ++ ;
V_12 = F_21 ( V_6 ) ;
if ( V_12 ) {
F_56 ( L_8 ,
V_46 , F_57 ( V_6 ) , V_12 ) ;
V_6 = NULL ;
if ( -- V_2 -> V_82 == 0 )
F_62 ( V_36 , V_2 -> V_26 ) ;
}
}
F_8 ( & V_13 ) ;
return V_6 ;
}
struct V_1 * F_63 ( const T_2 * V_77 ,
T_5 V_78 , void * V_79 )
{
struct V_22 * V_2 , * V_83 ;
struct V_1 * V_6 = NULL ;
int V_12 ;
F_5 ( & V_13 ) ;
F_64 (device, _d, &dma_device_list, global_node) {
V_6 = F_55 ( V_77 , V_2 , V_78 , V_79 ) ;
if ( V_6 ) {
F_61 ( V_36 , V_2 -> V_26 ) ;
V_2 -> V_82 ++ ;
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_56 ( L_9 ,
V_46 , F_57 ( V_6 ) ) ;
F_65 ( & V_2 -> V_84 ) ;
} else if ( V_12 )
F_56 ( L_8 ,
V_46 , F_57 ( V_6 ) , V_12 ) ;
else
break;
if ( -- V_2 -> V_82 == 0 )
F_62 ( V_36 , V_2 -> V_26 ) ;
V_6 = NULL ;
}
}
F_8 ( & V_13 ) ;
F_56 ( L_10 ,
V_46 ,
V_6 ? L_11 : L_12 ,
V_6 ? F_57 ( V_6 ) : NULL ) ;
return V_6 ;
}
struct V_1 * F_66 ( struct V_2 * V_3 ,
const char * V_85 )
{
if ( V_3 -> V_86 )
return F_67 ( V_3 -> V_86 , V_85 ) ;
if ( F_68 ( V_3 ) )
return F_69 ( V_3 , V_85 ) ;
return F_70 ( - V_16 ) ;
}
struct V_1 * F_71 ( struct V_2 * V_3 ,
const char * V_85 )
{
struct V_1 * V_87 = F_66 ( V_3 , V_85 ) ;
if ( F_72 ( V_87 ) )
return NULL ;
F_61 ( V_36 , V_87 -> V_2 -> V_26 ) ;
V_87 -> V_2 -> V_82 ++ ;
return V_87 ;
}
void F_73 ( struct V_1 * V_6 )
{
F_5 ( & V_13 ) ;
F_74 ( V_6 -> V_18 != 1 ,
L_13 , V_6 -> V_18 ) ;
F_25 ( V_6 ) ;
if ( -- V_6 -> V_2 -> V_82 == 0 )
F_62 ( V_36 , V_6 -> V_2 -> V_26 ) ;
F_8 ( & V_13 ) ;
}
void F_75 ( void )
{
struct V_22 * V_2 , * V_83 ;
struct V_1 * V_6 ;
int V_12 ;
F_5 ( & V_13 ) ;
V_31 ++ ;
F_64 (device, _d, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_44 (chan, &device->channels, device_node) {
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_65 ( & V_2 -> V_84 ) ;
break;
} else if ( V_12 )
F_56 ( L_8 ,
V_46 , F_57 ( V_6 ) , V_12 ) ;
}
}
if ( V_31 == 1 )
F_51 () ;
F_8 ( & V_13 ) ;
}
void F_76 ( void )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
V_31 -- ;
F_77 ( V_31 < 0 ) ;
F_44 (device, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_44 (chan, &device->channels, device_node)
F_25 ( V_6 ) ;
}
F_8 ( & V_13 ) ;
}
static bool F_78 ( struct V_22 * V_2 )
{
#ifdef F_79
if ( ! F_23 ( V_52 , V_2 -> V_26 ) )
return false ;
#endif
#if F_80 ( V_88 ) || F_80 ( V_89 )
if ( ! F_23 ( V_90 , V_2 -> V_26 ) )
return false ;
#endif
#if F_80 ( V_91 ) || F_80 ( V_92 )
if ( ! F_23 ( V_93 , V_2 -> V_26 ) )
return false ;
#ifndef F_81
if ( ! F_23 ( V_94 , V_2 -> V_26 ) )
return false ;
#endif
#endif
#if F_80 ( V_95 ) || F_80 ( V_96 )
if ( ! F_23 ( V_97 , V_2 -> V_26 ) )
return false ;
#ifndef F_82
if ( ! F_23 ( V_98 , V_2 -> V_26 ) )
return false ;
#endif
#endif
return true ;
}
static int F_83 ( struct V_22 * V_2 )
{
int V_99 ;
F_5 ( & V_13 ) ;
V_99 = F_84 ( & V_20 , NULL , 0 , 0 , V_100 ) ;
if ( V_99 >= 0 )
V_2 -> V_21 = V_99 ;
F_8 ( & V_13 ) ;
return V_99 < 0 ? V_99 : 0 ;
}
int F_85 ( struct V_22 * V_2 )
{
int V_80 = 0 , V_99 ;
struct V_1 * V_6 ;
T_6 * V_19 ;
if ( ! V_2 )
return - V_16 ;
F_77 ( F_23 ( V_90 , V_2 -> V_26 ) &&
! V_2 -> V_101 ) ;
F_77 ( F_23 ( V_93 , V_2 -> V_26 ) &&
! V_2 -> V_102 ) ;
F_77 ( F_23 ( V_94 , V_2 -> V_26 ) &&
! V_2 -> V_103 ) ;
F_77 ( F_23 ( V_97 , V_2 -> V_26 ) &&
! V_2 -> V_104 ) ;
F_77 ( F_23 ( V_98 , V_2 -> V_26 ) &&
! V_2 -> V_105 ) ;
F_77 ( F_23 ( V_106 , V_2 -> V_26 ) &&
! V_2 -> V_107 ) ;
F_77 ( F_23 ( V_52 , V_2 -> V_26 ) &&
! V_2 -> V_108 ) ;
F_77 ( F_23 ( V_109 , V_2 -> V_26 ) &&
! V_2 -> V_110 ) ;
F_77 ( F_23 ( V_111 , V_2 -> V_26 ) &&
! V_2 -> V_112 ) ;
F_77 ( F_23 ( V_113 , V_2 -> V_26 ) &&
! V_2 -> V_114 ) ;
F_77 ( ! V_2 -> V_115 ) ;
F_77 ( ! V_2 -> V_58 ) ;
F_77 ( ! V_2 -> V_3 ) ;
if ( F_78 ( V_2 ) )
F_61 ( V_116 , V_2 -> V_26 ) ;
V_19 = F_86 ( sizeof( * V_19 ) , V_100 ) ;
if ( ! V_19 )
return - V_56 ;
V_99 = F_83 ( V_2 ) ;
if ( V_99 != 0 ) {
F_14 ( V_19 ) ;
return V_99 ;
}
F_87 ( V_19 , 0 ) ;
F_44 (chan, &device->channels, device_node) {
V_99 = - V_56 ;
V_6 -> V_14 = F_37 ( F_3 ( * V_6 -> V_14 ) ) ;
if ( V_6 -> V_14 == NULL )
goto V_35;
V_6 -> V_3 = F_88 ( sizeof( * V_6 -> V_3 ) , V_100 ) ;
if ( V_6 -> V_3 == NULL ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
goto V_35;
}
V_6 -> V_117 = V_80 ++ ;
V_6 -> V_3 -> V_2 . V_118 = & V_119 ;
V_6 -> V_3 -> V_2 . V_120 = V_2 -> V_3 ;
V_6 -> V_3 -> V_6 = V_6 ;
V_6 -> V_3 -> V_19 = V_19 ;
V_6 -> V_3 -> V_21 = V_2 -> V_21 ;
F_89 ( V_19 ) ;
F_90 ( & V_6 -> V_3 -> V_2 , L_14 ,
V_2 -> V_21 , V_6 -> V_117 ) ;
V_99 = F_91 ( & V_6 -> V_3 -> V_2 ) ;
if ( V_99 ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_14 ( V_6 -> V_3 ) ;
F_92 ( V_19 ) ;
goto V_35;
}
V_6 -> V_18 = 0 ;
}
V_2 -> V_80 = V_80 ;
F_5 ( & V_13 ) ;
if ( V_31 && ! F_23 ( V_36 , V_2 -> V_26 ) )
F_44 (chan, &device->channels, device_node) {
if ( F_21 ( V_6 ) == - V_16 ) {
V_99 = - V_16 ;
F_8 ( & V_13 ) ;
goto V_35;
}
}
F_93 ( & V_2 -> V_84 , & V_121 ) ;
if ( F_23 ( V_36 , V_2 -> V_26 ) )
V_2 -> V_82 ++ ;
F_51 () ;
F_8 ( & V_13 ) ;
return 0 ;
V_35:
if ( F_94 ( V_19 ) == 0 ) {
F_5 ( & V_13 ) ;
F_13 ( & V_20 , V_2 -> V_21 ) ;
F_8 ( & V_13 ) ;
F_14 ( V_19 ) ;
return V_99 ;
}
F_44 (chan, &device->channels, device_node) {
if ( V_6 -> V_14 == NULL )
continue;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_95 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
return V_99 ;
}
void F_96 ( struct V_22 * V_2 )
{
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
F_65 ( & V_2 -> V_84 ) ;
F_51 () ;
F_8 ( & V_13 ) ;
F_44 (chan, &device->channels, device_node) {
F_74 ( V_6 -> V_18 ,
L_15 ,
V_46 , V_6 -> V_18 ) ;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_95 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
}
static struct V_122 * F_97 ( int V_123 )
{
int V_124 = F_98 ( V_123 ) ;
switch ( V_124 ) {
case 0 ... 1 :
return & V_125 [ 0 ] ;
case 2 ... 4 :
return & V_125 [ 1 ] ;
case 5 ... 7 :
return & V_125 [ 2 ] ;
case 8 :
return & V_125 [ 3 ] ;
default:
F_99 () ;
return NULL ;
}
}
static void F_100 ( struct V_126 * V_126 )
{
struct V_127 * V_128 = F_2 ( V_126 , F_3 ( * V_128 ) , V_126 ) ;
struct V_2 * V_3 = V_128 -> V_3 ;
int V_129 , V_11 ;
V_129 = V_128 -> V_130 ;
for ( V_11 = 0 ; V_11 < V_129 ; V_11 ++ )
F_101 ( V_3 , V_128 -> V_131 [ V_11 ] , V_128 -> V_132 ,
V_133 ) ;
V_129 += V_128 -> V_134 ;
for (; V_11 < V_129 ; V_11 ++ )
F_101 ( V_3 , V_128 -> V_131 [ V_11 ] , V_128 -> V_132 ,
V_135 ) ;
V_129 += V_128 -> V_136 ;
for (; V_11 < V_129 ; V_11 ++ ) {
if ( V_128 -> V_131 [ V_11 ] == 0 )
continue;
F_101 ( V_3 , V_128 -> V_131 [ V_11 ] , V_128 -> V_132 ,
V_137 ) ;
}
V_129 = V_128 -> V_138 ;
F_102 ( V_128 , F_97 ( V_129 ) -> V_139 ) ;
}
void F_103 ( struct V_127 * V_128 )
{
if ( V_128 )
F_104 ( & V_128 -> V_126 , F_100 ) ;
}
static void F_105 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_106 ( V_125 ) ; V_11 ++ ) {
struct V_122 * V_140 = & V_125 [ V_11 ] ;
if ( V_140 -> V_139 )
F_107 ( V_140 -> V_139 ) ;
V_140 -> V_139 = NULL ;
if ( V_140 -> V_141 )
F_108 ( V_140 -> V_141 ) ;
V_140 -> V_141 = NULL ;
}
}
static int T_4 F_109 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_106 ( V_125 ) ; V_11 ++ ) {
struct V_122 * V_140 = & V_125 [ V_11 ] ;
T_7 V_142 ;
V_142 = sizeof( struct V_127 ) +
sizeof( V_143 ) * V_140 -> V_142 ;
V_140 -> V_141 = F_110 ( V_140 -> V_85 , V_142 , 0 ,
V_144 , NULL ) ;
if ( ! V_140 -> V_141 )
break;
V_140 -> V_139 = F_111 ( 1 , V_140 -> V_141 ) ;
if ( ! V_140 -> V_139 )
break;
}
if ( V_11 == F_106 ( V_125 ) )
return 0 ;
F_105 () ;
return - V_56 ;
}
struct V_127 *
F_112 ( struct V_2 * V_3 , int V_123 , T_8 V_145 )
{
struct V_127 * V_128 ;
V_128 = F_113 ( F_97 ( V_123 ) -> V_139 , V_145 ) ;
if ( ! V_128 )
return NULL ;
memset ( V_128 , 0 , sizeof( * V_128 ) ) ;
F_114 ( & V_128 -> V_126 ) ;
V_128 -> V_3 = V_3 ;
V_128 -> V_138 = V_123 ;
return V_128 ;
}
void F_115 ( struct V_146 * V_147 ,
struct V_1 * V_6 )
{
V_147 -> V_6 = V_6 ;
#ifdef F_116
F_117 ( & V_147 -> V_148 ) ;
#endif
}
enum V_41
F_118 ( struct V_146 * V_147 )
{
unsigned long V_44 = V_45 + F_27 ( 5000 ) ;
if ( ! V_147 )
return V_149 ;
while ( V_147 -> V_42 == - V_81 ) {
if ( F_30 ( V_45 , V_44 ) ) {
F_31 ( L_16 ,
V_46 ) ;
return V_47 ;
}
F_32 () ;
}
return F_26 ( V_147 -> V_6 , V_147 -> V_42 ) ;
}
void F_119 ( struct V_146 * V_147 )
{
struct V_146 * V_150 = F_120 ( V_147 ) ;
struct V_146 * V_151 ;
struct V_1 * V_6 ;
if ( ! V_150 )
return;
F_121 ( V_147 ) ;
V_6 = V_150 -> V_6 ;
for (; V_150 ; V_150 = V_151 ) {
F_122 ( V_150 ) ;
F_123 ( V_150 ) ;
V_151 = F_120 ( V_150 ) ;
if ( V_151 && V_151 -> V_6 == V_6 )
F_121 ( V_150 ) ;
else
V_151 = NULL ;
F_124 ( V_150 ) ;
V_150 -> V_152 ( V_150 ) ;
}
V_6 -> V_2 -> V_58 ( V_6 ) ;
}
static int T_4 F_125 ( void )
{
int V_12 = F_109 () ;
if ( V_12 )
return V_12 ;
return F_126 ( & V_119 ) ;
}
