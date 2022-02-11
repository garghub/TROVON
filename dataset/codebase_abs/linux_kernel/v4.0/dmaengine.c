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
}
enum V_38 F_26 ( struct V_1 * V_6 , T_3 V_39 )
{
enum V_38 V_40 ;
unsigned long V_41 = V_42 + F_27 ( 5000 ) ;
F_28 ( V_6 ) ;
do {
V_40 = F_29 ( V_6 , V_39 , NULL , NULL ) ;
if ( F_30 ( V_42 , V_41 ) ) {
F_31 ( L_3 , V_43 ) ;
return V_44 ;
}
if ( V_40 != V_45 )
break;
F_32 () ;
} while ( 1 );
return V_40 ;
}
static int T_4 F_33 ( void )
{
enum V_46 V_47 ;
int V_12 = 0 ;
F_34 ( V_48 . V_25 , V_27 ) ;
F_35 ( V_49 , V_48 . V_25 ) ;
F_35 ( V_36 , V_48 . V_25 ) ;
F_35 ( V_50 , V_48 . V_25 ) ;
F_36 (cap, dma_cap_mask_all) {
V_51 [ V_47 ] = F_37 ( struct V_52 ) ;
if ( ! V_51 [ V_47 ] ) {
V_12 = - V_53 ;
break;
}
}
if ( V_12 ) {
F_31 ( L_4 ) ;
F_36 (cap, dma_cap_mask_all)
F_38 ( V_51 [ V_47 ] ) ;
}
return V_12 ;
}
struct V_1 * F_39 ( enum V_46 V_54 )
{
return F_40 ( V_51 [ V_54 ] -> V_6 ) ;
}
struct V_1 * F_41 ( void )
{
struct V_1 * V_6 = F_39 ( V_55 ) ;
if ( V_6 && ! F_42 ( V_6 -> V_2 , 1 , 1 , 1 ) )
return NULL ;
return V_6 ;
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
V_2 -> V_56 ( V_6 ) ;
}
F_47 () ;
}
static bool F_48 ( struct V_1 * V_6 , int V_57 )
{
int V_58 = F_49 ( V_6 -> V_2 -> V_3 ) ;
return V_58 == - 1 || F_50 ( V_57 , F_51 ( V_58 ) ) ;
}
static struct V_1 * F_52 ( enum V_46 V_47 , int V_57 )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
struct V_1 * V_59 = NULL ;
struct V_1 * V_60 = NULL ;
F_46 (device, &dma_device_list, global_node) {
if ( ! F_23 ( V_47 , V_2 -> V_26 ) ||
F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node) {
if ( ! V_6 -> V_18 )
continue;
if ( ! V_59 || V_6 -> V_61 < V_59 -> V_61 )
V_59 = V_6 ;
if ( F_48 ( V_6 , V_57 ) )
if ( ! V_60 ||
V_6 -> V_61 < V_60 -> V_61 )
V_60 = V_6 ;
}
}
V_6 = V_60 ? V_60 : V_59 ;
if ( V_6 )
V_6 -> V_61 ++ ;
return V_6 ;
}
static void F_53 ( void )
{
struct V_1 * V_6 ;
struct V_22 * V_2 ;
int V_57 ;
int V_47 ;
F_36 (cap, dma_cap_mask_all)
F_6 (cpu)
F_7 ( V_51 [ V_47 ] , V_57 ) -> V_6 = NULL ;
F_46 (device, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node)
V_6 -> V_61 = 0 ;
}
if ( ! V_31 )
return;
F_36 (cap, dma_cap_mask_all)
F_54 (cpu) {
V_6 = F_52 ( V_47 , V_57 ) ;
F_7 ( V_51 [ V_47 ] , V_57 ) -> V_6 = V_6 ;
}
}
int F_55 ( struct V_1 * V_6 , struct V_62 * V_63 )
{
struct V_22 * V_2 ;
if ( ! V_6 || ! V_63 )
return - V_64 ;
V_2 = V_6 -> V_2 ;
if ( ! F_56 ( V_50 , V_2 -> V_26 . V_25 ) )
return - V_65 ;
if ( ! V_2 -> V_66 )
return - V_65 ;
V_63 -> V_67 = V_2 -> V_67 ;
V_63 -> V_68 = V_2 -> V_68 ;
V_63 -> V_66 = V_2 -> V_66 ;
V_63 -> V_69 = V_2 -> V_69 ;
V_63 -> V_70 = ! ! V_2 -> V_71 ;
V_63 -> V_72 = ! ! V_2 -> V_73 ;
return 0 ;
}
static struct V_1 * F_57 ( const T_2 * V_74 ,
struct V_22 * V_3 ,
T_5 V_75 , void * V_76 )
{
struct V_1 * V_6 ;
if ( ! F_15 ( V_3 , V_74 ) ) {
F_58 ( L_5 , V_43 ) ;
return NULL ;
}
if ( V_3 -> V_77 > 1 && ! F_23 ( V_36 , V_3 -> V_26 ) )
F_46 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 )
return NULL ;
}
F_46 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 ) {
F_58 ( L_6 ,
V_43 , F_59 ( V_6 ) ) ;
continue;
}
if ( V_75 && ! V_75 ( V_6 , V_76 ) ) {
F_58 ( L_7 ,
V_43 , F_59 ( V_6 ) ) ;
continue;
}
return V_6 ;
}
return NULL ;
}
struct V_1 * F_60 ( struct V_1 * V_6 )
{
int V_12 = - V_78 ;
F_5 ( & V_13 ) ;
if ( V_6 -> V_18 == 0 ) {
V_12 = F_21 ( V_6 ) ;
if ( V_12 )
F_58 ( L_8 ,
V_43 , F_59 ( V_6 ) , V_12 ) ;
} else
V_6 = NULL ;
F_8 ( & V_13 ) ;
return V_6 ;
}
struct V_1 * F_61 ( struct V_22 * V_2 )
{
T_2 V_74 ;
struct V_1 * V_6 ;
int V_12 ;
F_62 ( V_74 ) ;
F_63 ( V_50 , V_74 ) ;
F_5 ( & V_13 ) ;
V_6 = F_57 ( & V_74 , V_2 , NULL , NULL ) ;
if ( V_6 ) {
V_12 = F_21 ( V_6 ) ;
if ( V_12 ) {
F_58 ( L_8 ,
V_43 , F_59 ( V_6 ) , V_12 ) ;
V_6 = NULL ;
}
}
F_8 ( & V_13 ) ;
return V_6 ;
}
struct V_1 * F_64 ( const T_2 * V_74 ,
T_5 V_75 , void * V_76 )
{
struct V_22 * V_2 , * V_79 ;
struct V_1 * V_6 = NULL ;
int V_12 ;
F_5 ( & V_13 ) ;
F_65 (device, _d, &dma_device_list, global_node) {
V_6 = F_57 ( V_74 , V_2 , V_75 , V_76 ) ;
if ( V_6 ) {
F_63 ( V_36 , V_2 -> V_26 ) ;
V_2 -> V_80 ++ ;
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_58 ( L_9 ,
V_43 , F_59 ( V_6 ) ) ;
F_66 ( & V_2 -> V_81 ) ;
} else if ( V_12 )
F_58 ( L_8 ,
V_43 , F_59 ( V_6 ) , V_12 ) ;
else
break;
if ( -- V_2 -> V_80 == 0 )
F_67 ( V_36 , V_2 -> V_26 ) ;
V_6 = NULL ;
}
}
F_8 ( & V_13 ) ;
F_58 ( L_10 ,
V_43 ,
V_6 ? L_11 : L_12 ,
V_6 ? F_59 ( V_6 ) : NULL ) ;
return V_6 ;
}
struct V_1 * F_68 ( struct V_2 * V_3 ,
const char * V_82 )
{
if ( V_3 -> V_83 )
return F_69 ( V_3 -> V_83 , V_82 ) ;
if ( F_70 ( V_3 ) )
return F_71 ( V_3 , V_82 ) ;
return F_72 ( - V_16 ) ;
}
struct V_1 * F_73 ( struct V_2 * V_3 ,
const char * V_82 )
{
struct V_1 * V_84 = F_68 ( V_3 , V_82 ) ;
if ( F_74 ( V_84 ) )
return NULL ;
return V_84 ;
}
void F_75 ( struct V_1 * V_6 )
{
F_5 ( & V_13 ) ;
F_76 ( V_6 -> V_18 != 1 ,
L_13 , V_6 -> V_18 ) ;
F_25 ( V_6 ) ;
if ( -- V_6 -> V_2 -> V_80 == 0 )
F_67 ( V_36 , V_6 -> V_2 -> V_26 ) ;
F_8 ( & V_13 ) ;
}
void F_77 ( void )
{
struct V_22 * V_2 , * V_79 ;
struct V_1 * V_6 ;
int V_12 ;
F_5 ( & V_13 ) ;
V_31 ++ ;
F_65 (device, _d, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node) {
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_66 ( & V_2 -> V_81 ) ;
break;
} else if ( V_12 )
F_58 ( L_8 ,
V_43 , F_59 ( V_6 ) , V_12 ) ;
}
}
if ( V_31 == 1 )
F_53 () ;
F_8 ( & V_13 ) ;
}
void F_78 ( void )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
V_31 -- ;
F_79 ( V_31 < 0 ) ;
F_46 (device, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node)
F_25 ( V_6 ) ;
}
F_8 ( & V_13 ) ;
}
static bool F_80 ( struct V_22 * V_2 )
{
#ifdef F_81
if ( ! F_23 ( V_49 , V_2 -> V_26 ) )
return false ;
#endif
#if F_82 ( V_85 ) || F_82 ( V_86 )
if ( ! F_23 ( V_55 , V_2 -> V_26 ) )
return false ;
#endif
#if F_82 ( V_87 ) || F_82 ( V_88 )
if ( ! F_23 ( V_89 , V_2 -> V_26 ) )
return false ;
#ifndef F_83
if ( ! F_23 ( V_90 , V_2 -> V_26 ) )
return false ;
#endif
#endif
#if F_82 ( V_91 ) || F_82 ( V_92 )
if ( ! F_23 ( V_93 , V_2 -> V_26 ) )
return false ;
#ifndef F_84
if ( ! F_23 ( V_94 , V_2 -> V_26 ) )
return false ;
#endif
#endif
return true ;
}
static int F_85 ( struct V_22 * V_2 )
{
int V_95 ;
F_5 ( & V_13 ) ;
V_95 = F_86 ( & V_20 , NULL , 0 , 0 , V_96 ) ;
if ( V_95 >= 0 )
V_2 -> V_21 = V_95 ;
F_8 ( & V_13 ) ;
return V_95 < 0 ? V_95 : 0 ;
}
int F_87 ( struct V_22 * V_2 )
{
int V_77 = 0 , V_95 ;
struct V_1 * V_6 ;
T_6 * V_19 ;
if ( ! V_2 )
return - V_16 ;
F_79 ( F_23 ( V_55 , V_2 -> V_26 ) &&
! V_2 -> V_97 ) ;
F_79 ( F_23 ( V_89 , V_2 -> V_26 ) &&
! V_2 -> V_98 ) ;
F_79 ( F_23 ( V_90 , V_2 -> V_26 ) &&
! V_2 -> V_99 ) ;
F_79 ( F_23 ( V_93 , V_2 -> V_26 ) &&
! V_2 -> V_100 ) ;
F_79 ( F_23 ( V_94 , V_2 -> V_26 ) &&
! V_2 -> V_101 ) ;
F_79 ( F_23 ( V_49 , V_2 -> V_26 ) &&
! V_2 -> V_102 ) ;
F_79 ( F_23 ( V_103 , V_2 -> V_26 ) &&
! V_2 -> V_104 ) ;
F_79 ( F_23 ( V_105 , V_2 -> V_26 ) &&
! V_2 -> V_106 ) ;
F_79 ( F_23 ( V_107 , V_2 -> V_26 ) &&
! V_2 -> V_108 ) ;
F_79 ( ! V_2 -> V_109 ) ;
F_79 ( ! V_2 -> V_56 ) ;
F_79 ( ! V_2 -> V_3 ) ;
if ( F_80 ( V_2 ) )
F_63 ( V_110 , V_2 -> V_26 ) ;
V_19 = F_88 ( sizeof( * V_19 ) , V_96 ) ;
if ( ! V_19 )
return - V_53 ;
V_95 = F_85 ( V_2 ) ;
if ( V_95 != 0 ) {
F_14 ( V_19 ) ;
return V_95 ;
}
F_89 ( V_19 , 0 ) ;
F_46 (chan, &device->channels, device_node) {
V_95 = - V_53 ;
V_6 -> V_14 = F_37 ( F_3 ( * V_6 -> V_14 ) ) ;
if ( V_6 -> V_14 == NULL )
goto V_35;
V_6 -> V_3 = F_90 ( sizeof( * V_6 -> V_3 ) , V_96 ) ;
if ( V_6 -> V_3 == NULL ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
goto V_35;
}
V_6 -> V_111 = V_77 ++ ;
V_6 -> V_3 -> V_2 . V_112 = & V_113 ;
V_6 -> V_3 -> V_2 . V_114 = V_2 -> V_3 ;
V_6 -> V_3 -> V_6 = V_6 ;
V_6 -> V_3 -> V_19 = V_19 ;
V_6 -> V_3 -> V_21 = V_2 -> V_21 ;
F_91 ( V_19 ) ;
F_92 ( & V_6 -> V_3 -> V_2 , L_14 ,
V_2 -> V_21 , V_6 -> V_111 ) ;
V_95 = F_93 ( & V_6 -> V_3 -> V_2 ) ;
if ( V_95 ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_14 ( V_6 -> V_3 ) ;
F_94 ( V_19 ) ;
goto V_35;
}
V_6 -> V_18 = 0 ;
}
V_2 -> V_77 = V_77 ;
F_5 ( & V_13 ) ;
if ( V_31 && ! F_23 ( V_36 , V_2 -> V_26 ) )
F_46 (chan, &device->channels, device_node) {
if ( F_21 ( V_6 ) == - V_16 ) {
V_95 = - V_16 ;
F_8 ( & V_13 ) ;
goto V_35;
}
}
F_95 ( & V_2 -> V_81 , & V_115 ) ;
if ( F_23 ( V_36 , V_2 -> V_26 ) )
V_2 -> V_80 ++ ;
F_53 () ;
F_8 ( & V_13 ) ;
return 0 ;
V_35:
if ( F_96 ( V_19 ) == 0 ) {
F_5 ( & V_13 ) ;
F_13 ( & V_20 , V_2 -> V_21 ) ;
F_8 ( & V_13 ) ;
F_14 ( V_19 ) ;
return V_95 ;
}
F_46 (chan, &device->channels, device_node) {
if ( V_6 -> V_14 == NULL )
continue;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_97 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
return V_95 ;
}
void F_98 ( struct V_22 * V_2 )
{
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
F_66 ( & V_2 -> V_81 ) ;
F_53 () ;
F_8 ( & V_13 ) ;
F_46 (chan, &device->channels, device_node) {
F_76 ( V_6 -> V_18 ,
L_15 ,
V_43 , V_6 -> V_18 ) ;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_97 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
}
static struct V_116 * F_99 ( int V_117 )
{
int V_118 = F_100 ( V_117 ) ;
switch ( V_118 ) {
case 0 ... 1 :
return & V_119 [ 0 ] ;
case 2 ... 4 :
return & V_119 [ 1 ] ;
case 5 ... 7 :
return & V_119 [ 2 ] ;
case 8 :
return & V_119 [ 3 ] ;
default:
F_101 () ;
return NULL ;
}
}
static void F_102 ( struct V_120 * V_120 )
{
struct V_121 * V_122 = F_2 ( V_120 , F_3 ( * V_122 ) , V_120 ) ;
struct V_2 * V_3 = V_122 -> V_3 ;
int V_123 , V_11 ;
V_123 = V_122 -> V_124 ;
for ( V_11 = 0 ; V_11 < V_123 ; V_11 ++ )
F_103 ( V_3 , V_122 -> V_125 [ V_11 ] , V_122 -> V_126 ,
V_127 ) ;
V_123 += V_122 -> V_128 ;
for (; V_11 < V_123 ; V_11 ++ )
F_103 ( V_3 , V_122 -> V_125 [ V_11 ] , V_122 -> V_126 ,
V_129 ) ;
V_123 += V_122 -> V_130 ;
for (; V_11 < V_123 ; V_11 ++ ) {
if ( V_122 -> V_125 [ V_11 ] == 0 )
continue;
F_103 ( V_3 , V_122 -> V_125 [ V_11 ] , V_122 -> V_126 ,
V_131 ) ;
}
V_123 = V_122 -> V_132 ;
F_104 ( V_122 , F_99 ( V_123 ) -> V_133 ) ;
}
void F_105 ( struct V_121 * V_122 )
{
if ( V_122 )
F_106 ( & V_122 -> V_120 , F_102 ) ;
}
static void F_107 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_108 ( V_119 ) ; V_11 ++ ) {
struct V_116 * V_134 = & V_119 [ V_11 ] ;
if ( V_134 -> V_133 )
F_109 ( V_134 -> V_133 ) ;
V_134 -> V_133 = NULL ;
if ( V_134 -> V_135 )
F_110 ( V_134 -> V_135 ) ;
V_134 -> V_135 = NULL ;
}
}
static int T_4 F_111 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_108 ( V_119 ) ; V_11 ++ ) {
struct V_116 * V_134 = & V_119 [ V_11 ] ;
T_7 V_136 ;
V_136 = sizeof( struct V_121 ) +
sizeof( V_137 ) * V_134 -> V_136 ;
V_134 -> V_135 = F_112 ( V_134 -> V_82 , V_136 , 0 ,
V_138 , NULL ) ;
if ( ! V_134 -> V_135 )
break;
V_134 -> V_133 = F_113 ( 1 , V_134 -> V_135 ) ;
if ( ! V_134 -> V_133 )
break;
}
if ( V_11 == F_108 ( V_119 ) )
return 0 ;
F_107 () ;
return - V_53 ;
}
struct V_121 *
F_114 ( struct V_2 * V_3 , int V_117 , T_8 V_139 )
{
struct V_121 * V_122 ;
V_122 = F_115 ( F_99 ( V_117 ) -> V_133 , V_139 ) ;
if ( ! V_122 )
return NULL ;
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
F_116 ( & V_122 -> V_120 ) ;
V_122 -> V_3 = V_3 ;
V_122 -> V_132 = V_117 ;
return V_122 ;
}
void F_117 ( struct V_140 * V_141 ,
struct V_1 * V_6 )
{
V_141 -> V_6 = V_6 ;
#ifdef F_118
F_119 ( & V_141 -> V_142 ) ;
#endif
}
enum V_38
F_120 ( struct V_140 * V_141 )
{
unsigned long V_41 = V_42 + F_27 ( 5000 ) ;
if ( ! V_141 )
return V_143 ;
while ( V_141 -> V_39 == - V_78 ) {
if ( F_30 ( V_42 , V_41 ) ) {
F_31 ( L_16 ,
V_43 ) ;
return V_44 ;
}
F_32 () ;
}
return F_26 ( V_141 -> V_6 , V_141 -> V_39 ) ;
}
void F_121 ( struct V_140 * V_141 )
{
struct V_140 * V_144 = F_122 ( V_141 ) ;
struct V_140 * V_145 ;
struct V_1 * V_6 ;
if ( ! V_144 )
return;
F_123 ( V_141 ) ;
V_6 = V_144 -> V_6 ;
for (; V_144 ; V_144 = V_145 ) {
F_124 ( V_144 ) ;
F_125 ( V_144 ) ;
V_145 = F_122 ( V_144 ) ;
if ( V_145 && V_145 -> V_6 == V_6 )
F_123 ( V_144 ) ;
else
V_145 = NULL ;
F_126 ( V_144 ) ;
V_144 -> V_146 ( V_144 ) ;
}
V_6 -> V_2 -> V_56 ( V_6 ) ;
}
static int T_4 F_127 ( void )
{
int V_12 = F_111 () ;
if ( V_12 )
return V_12 ;
return F_128 ( & V_113 ) ;
}
