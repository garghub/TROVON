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
V_2 -> V_55 ( V_6 ) ;
}
F_45 () ;
}
static bool F_46 ( struct V_1 * V_6 , int V_56 )
{
int V_57 = F_47 ( V_6 -> V_2 -> V_3 ) ;
return V_57 == - 1 || F_48 ( V_56 , F_49 ( V_57 ) ) ;
}
static struct V_1 * F_50 ( enum V_46 V_47 , int V_56 )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
struct V_1 * V_58 = NULL ;
struct V_1 * V_59 = NULL ;
F_44 (device, &dma_device_list, global_node) {
if ( ! F_23 ( V_47 , V_2 -> V_26 ) ||
F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_44 (chan, &device->channels, device_node) {
if ( ! V_6 -> V_18 )
continue;
if ( ! V_58 || V_6 -> V_60 < V_58 -> V_60 )
V_58 = V_6 ;
if ( F_46 ( V_6 , V_56 ) )
if ( ! V_59 ||
V_6 -> V_60 < V_59 -> V_60 )
V_59 = V_6 ;
}
}
V_6 = V_59 ? V_59 : V_58 ;
if ( V_6 )
V_6 -> V_60 ++ ;
return V_6 ;
}
static void F_51 ( void )
{
struct V_1 * V_6 ;
struct V_22 * V_2 ;
int V_56 ;
int V_47 ;
F_36 (cap, dma_cap_mask_all)
F_6 (cpu)
F_7 ( V_51 [ V_47 ] , V_56 ) -> V_6 = NULL ;
F_44 (device, &dma_device_list, global_node) {
if ( F_23 ( V_36 , V_2 -> V_26 ) )
continue;
F_44 (chan, &device->channels, device_node)
V_6 -> V_60 = 0 ;
}
if ( ! V_31 )
return;
F_36 (cap, dma_cap_mask_all)
F_52 (cpu) {
V_6 = F_50 ( V_47 , V_56 ) ;
F_7 ( V_51 [ V_47 ] , V_56 ) -> V_6 = V_6 ;
}
}
int F_53 ( struct V_1 * V_6 , struct V_61 * V_62 )
{
struct V_22 * V_2 ;
if ( ! V_6 || ! V_62 )
return - V_63 ;
V_2 = V_6 -> V_2 ;
if ( ! F_54 ( V_50 , V_2 -> V_26 . V_25 ) )
return - V_64 ;
if ( ! V_2 -> V_65 )
return - V_64 ;
V_62 -> V_66 = V_2 -> V_66 ;
V_62 -> V_67 = V_2 -> V_67 ;
V_62 -> V_65 = V_2 -> V_65 ;
V_62 -> V_68 = V_2 -> V_68 ;
V_62 -> V_69 = ! ! ( V_2 -> V_70 && V_2 -> V_71 ) ;
V_62 -> V_72 = ! ! V_2 -> V_73 ;
return 0 ;
}
static struct V_1 * F_55 ( const T_2 * V_74 ,
struct V_22 * V_3 ,
T_5 V_75 , void * V_76 )
{
struct V_1 * V_6 ;
if ( ! F_15 ( V_3 , V_74 ) ) {
F_56 ( L_5 , V_43 ) ;
return NULL ;
}
if ( V_3 -> V_77 > 1 && ! F_23 ( V_36 , V_3 -> V_26 ) )
F_44 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 )
return NULL ;
}
F_44 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 ) {
F_56 ( L_6 ,
V_43 , F_57 ( V_6 ) ) ;
continue;
}
if ( V_75 && ! V_75 ( V_6 , V_76 ) ) {
F_56 ( L_7 ,
V_43 , F_57 ( V_6 ) ) ;
continue;
}
return V_6 ;
}
return NULL ;
}
struct V_1 * F_58 ( struct V_1 * V_6 )
{
int V_12 = - V_78 ;
F_5 ( & V_13 ) ;
if ( V_6 -> V_18 == 0 ) {
V_12 = F_21 ( V_6 ) ;
if ( V_12 )
F_56 ( L_8 ,
V_43 , F_57 ( V_6 ) , V_12 ) ;
} else
V_6 = NULL ;
F_8 ( & V_13 ) ;
return V_6 ;
}
struct V_1 * F_59 ( struct V_22 * V_2 )
{
T_2 V_74 ;
struct V_1 * V_6 ;
int V_12 ;
F_60 ( V_74 ) ;
F_61 ( V_50 , V_74 ) ;
F_5 ( & V_13 ) ;
V_6 = F_55 ( & V_74 , V_2 , NULL , NULL ) ;
if ( V_6 ) {
F_61 ( V_36 , V_2 -> V_26 ) ;
V_2 -> V_79 ++ ;
V_12 = F_21 ( V_6 ) ;
if ( V_12 ) {
F_56 ( L_8 ,
V_43 , F_57 ( V_6 ) , V_12 ) ;
V_6 = NULL ;
if ( -- V_2 -> V_79 == 0 )
F_62 ( V_36 , V_2 -> V_26 ) ;
}
}
F_8 ( & V_13 ) ;
return V_6 ;
}
struct V_1 * F_63 ( const T_2 * V_74 ,
T_5 V_75 , void * V_76 )
{
struct V_22 * V_2 , * V_80 ;
struct V_1 * V_6 = NULL ;
int V_12 ;
F_5 ( & V_13 ) ;
F_64 (device, _d, &dma_device_list, global_node) {
V_6 = F_55 ( V_74 , V_2 , V_75 , V_76 ) ;
if ( V_6 ) {
F_61 ( V_36 , V_2 -> V_26 ) ;
V_2 -> V_79 ++ ;
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_56 ( L_9 ,
V_43 , F_57 ( V_6 ) ) ;
F_65 ( & V_2 -> V_81 ) ;
} else if ( V_12 )
F_56 ( L_8 ,
V_43 , F_57 ( V_6 ) , V_12 ) ;
else
break;
if ( -- V_2 -> V_79 == 0 )
F_62 ( V_36 , V_2 -> V_26 ) ;
V_6 = NULL ;
}
}
F_8 ( & V_13 ) ;
F_56 ( L_10 ,
V_43 ,
V_6 ? L_11 : L_12 ,
V_6 ? F_57 ( V_6 ) : NULL ) ;
return V_6 ;
}
struct V_1 * F_66 ( struct V_2 * V_3 ,
const char * V_82 )
{
if ( V_3 -> V_83 )
return F_67 ( V_3 -> V_83 , V_82 ) ;
if ( F_68 ( V_3 ) )
return F_69 ( V_3 , V_82 ) ;
return F_70 ( - V_16 ) ;
}
struct V_1 * F_71 ( struct V_2 * V_3 ,
const char * V_82 )
{
struct V_1 * V_84 = F_66 ( V_3 , V_82 ) ;
if ( F_72 ( V_84 ) )
return NULL ;
return V_84 ;
}
void F_73 ( struct V_1 * V_6 )
{
F_5 ( & V_13 ) ;
F_74 ( V_6 -> V_18 != 1 ,
L_13 , V_6 -> V_18 ) ;
F_25 ( V_6 ) ;
if ( -- V_6 -> V_2 -> V_79 == 0 )
F_62 ( V_36 , V_6 -> V_2 -> V_26 ) ;
F_8 ( & V_13 ) ;
}
void F_75 ( void )
{
struct V_22 * V_2 , * V_80 ;
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
F_65 ( & V_2 -> V_81 ) ;
break;
} else if ( V_12 )
F_56 ( L_8 ,
V_43 , F_57 ( V_6 ) , V_12 ) ;
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
if ( ! F_23 ( V_49 , V_2 -> V_26 ) )
return false ;
#endif
#if F_80 ( V_85 ) || F_80 ( V_86 )
if ( ! F_23 ( V_87 , V_2 -> V_26 ) )
return false ;
#endif
#if F_80 ( V_88 ) || F_80 ( V_89 )
if ( ! F_23 ( V_90 , V_2 -> V_26 ) )
return false ;
#ifndef F_81
if ( ! F_23 ( V_91 , V_2 -> V_26 ) )
return false ;
#endif
#endif
#if F_80 ( V_92 ) || F_80 ( V_93 )
if ( ! F_23 ( V_94 , V_2 -> V_26 ) )
return false ;
#ifndef F_82
if ( ! F_23 ( V_95 , V_2 -> V_26 ) )
return false ;
#endif
#endif
return true ;
}
static int F_83 ( struct V_22 * V_2 )
{
int V_96 ;
F_5 ( & V_13 ) ;
V_96 = F_84 ( & V_20 , NULL , 0 , 0 , V_97 ) ;
if ( V_96 >= 0 )
V_2 -> V_21 = V_96 ;
F_8 ( & V_13 ) ;
return V_96 < 0 ? V_96 : 0 ;
}
int F_85 ( struct V_22 * V_2 )
{
int V_77 = 0 , V_96 ;
struct V_1 * V_6 ;
T_6 * V_19 ;
if ( ! V_2 )
return - V_16 ;
F_77 ( F_23 ( V_87 , V_2 -> V_26 ) &&
! V_2 -> V_98 ) ;
F_77 ( F_23 ( V_90 , V_2 -> V_26 ) &&
! V_2 -> V_99 ) ;
F_77 ( F_23 ( V_91 , V_2 -> V_26 ) &&
! V_2 -> V_100 ) ;
F_77 ( F_23 ( V_94 , V_2 -> V_26 ) &&
! V_2 -> V_101 ) ;
F_77 ( F_23 ( V_95 , V_2 -> V_26 ) &&
! V_2 -> V_102 ) ;
F_77 ( F_23 ( V_49 , V_2 -> V_26 ) &&
! V_2 -> V_103 ) ;
F_77 ( F_23 ( V_104 , V_2 -> V_26 ) &&
! V_2 -> V_105 ) ;
F_77 ( F_23 ( V_106 , V_2 -> V_26 ) &&
! V_2 -> V_107 ) ;
F_77 ( F_23 ( V_108 , V_2 -> V_26 ) &&
! V_2 -> V_109 ) ;
F_77 ( ! V_2 -> V_110 ) ;
F_77 ( ! V_2 -> V_55 ) ;
F_77 ( ! V_2 -> V_3 ) ;
if ( F_78 ( V_2 ) )
F_61 ( V_111 , V_2 -> V_26 ) ;
V_19 = F_86 ( sizeof( * V_19 ) , V_97 ) ;
if ( ! V_19 )
return - V_53 ;
V_96 = F_83 ( V_2 ) ;
if ( V_96 != 0 ) {
F_14 ( V_19 ) ;
return V_96 ;
}
F_87 ( V_19 , 0 ) ;
F_44 (chan, &device->channels, device_node) {
V_96 = - V_53 ;
V_6 -> V_14 = F_37 ( F_3 ( * V_6 -> V_14 ) ) ;
if ( V_6 -> V_14 == NULL )
goto V_35;
V_6 -> V_3 = F_88 ( sizeof( * V_6 -> V_3 ) , V_97 ) ;
if ( V_6 -> V_3 == NULL ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
goto V_35;
}
V_6 -> V_112 = V_77 ++ ;
V_6 -> V_3 -> V_2 . V_113 = & V_114 ;
V_6 -> V_3 -> V_2 . V_115 = V_2 -> V_3 ;
V_6 -> V_3 -> V_6 = V_6 ;
V_6 -> V_3 -> V_19 = V_19 ;
V_6 -> V_3 -> V_21 = V_2 -> V_21 ;
F_89 ( V_19 ) ;
F_90 ( & V_6 -> V_3 -> V_2 , L_14 ,
V_2 -> V_21 , V_6 -> V_112 ) ;
V_96 = F_91 ( & V_6 -> V_3 -> V_2 ) ;
if ( V_96 ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_14 ( V_6 -> V_3 ) ;
F_92 ( V_19 ) ;
goto V_35;
}
V_6 -> V_18 = 0 ;
}
V_2 -> V_77 = V_77 ;
F_5 ( & V_13 ) ;
if ( V_31 && ! F_23 ( V_36 , V_2 -> V_26 ) )
F_44 (chan, &device->channels, device_node) {
if ( F_21 ( V_6 ) == - V_16 ) {
V_96 = - V_16 ;
F_8 ( & V_13 ) ;
goto V_35;
}
}
F_93 ( & V_2 -> V_81 , & V_116 ) ;
if ( F_23 ( V_36 , V_2 -> V_26 ) )
V_2 -> V_79 ++ ;
F_51 () ;
F_8 ( & V_13 ) ;
return 0 ;
V_35:
if ( F_94 ( V_19 ) == 0 ) {
F_5 ( & V_13 ) ;
F_13 ( & V_20 , V_2 -> V_21 ) ;
F_8 ( & V_13 ) ;
F_14 ( V_19 ) ;
return V_96 ;
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
return V_96 ;
}
void F_96 ( struct V_22 * V_2 )
{
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
F_65 ( & V_2 -> V_81 ) ;
F_51 () ;
F_8 ( & V_13 ) ;
F_44 (chan, &device->channels, device_node) {
F_74 ( V_6 -> V_18 ,
L_15 ,
V_43 , V_6 -> V_18 ) ;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_95 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
}
static struct V_117 * F_97 ( int V_118 )
{
int V_119 = F_98 ( V_118 ) ;
switch ( V_119 ) {
case 0 ... 1 :
return & V_120 [ 0 ] ;
case 2 ... 4 :
return & V_120 [ 1 ] ;
case 5 ... 7 :
return & V_120 [ 2 ] ;
case 8 :
return & V_120 [ 3 ] ;
default:
F_99 () ;
return NULL ;
}
}
static void F_100 ( struct V_121 * V_121 )
{
struct V_122 * V_123 = F_2 ( V_121 , F_3 ( * V_123 ) , V_121 ) ;
struct V_2 * V_3 = V_123 -> V_3 ;
int V_124 , V_11 ;
V_124 = V_123 -> V_125 ;
for ( V_11 = 0 ; V_11 < V_124 ; V_11 ++ )
F_101 ( V_3 , V_123 -> V_126 [ V_11 ] , V_123 -> V_127 ,
V_128 ) ;
V_124 += V_123 -> V_129 ;
for (; V_11 < V_124 ; V_11 ++ )
F_101 ( V_3 , V_123 -> V_126 [ V_11 ] , V_123 -> V_127 ,
V_130 ) ;
V_124 += V_123 -> V_131 ;
for (; V_11 < V_124 ; V_11 ++ ) {
if ( V_123 -> V_126 [ V_11 ] == 0 )
continue;
F_101 ( V_3 , V_123 -> V_126 [ V_11 ] , V_123 -> V_127 ,
V_132 ) ;
}
V_124 = V_123 -> V_133 ;
F_102 ( V_123 , F_97 ( V_124 ) -> V_134 ) ;
}
void F_103 ( struct V_122 * V_123 )
{
if ( V_123 )
F_104 ( & V_123 -> V_121 , F_100 ) ;
}
static void F_105 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_106 ( V_120 ) ; V_11 ++ ) {
struct V_117 * V_135 = & V_120 [ V_11 ] ;
if ( V_135 -> V_134 )
F_107 ( V_135 -> V_134 ) ;
V_135 -> V_134 = NULL ;
if ( V_135 -> V_136 )
F_108 ( V_135 -> V_136 ) ;
V_135 -> V_136 = NULL ;
}
}
static int T_4 F_109 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_106 ( V_120 ) ; V_11 ++ ) {
struct V_117 * V_135 = & V_120 [ V_11 ] ;
T_7 V_137 ;
V_137 = sizeof( struct V_122 ) +
sizeof( V_138 ) * V_135 -> V_137 ;
V_135 -> V_136 = F_110 ( V_135 -> V_82 , V_137 , 0 ,
V_139 , NULL ) ;
if ( ! V_135 -> V_136 )
break;
V_135 -> V_134 = F_111 ( 1 , V_135 -> V_136 ) ;
if ( ! V_135 -> V_134 )
break;
}
if ( V_11 == F_106 ( V_120 ) )
return 0 ;
F_105 () ;
return - V_53 ;
}
struct V_122 *
F_112 ( struct V_2 * V_3 , int V_118 , T_8 V_140 )
{
struct V_122 * V_123 ;
V_123 = F_113 ( F_97 ( V_118 ) -> V_134 , V_140 ) ;
if ( ! V_123 )
return NULL ;
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
F_114 ( & V_123 -> V_121 ) ;
V_123 -> V_3 = V_3 ;
V_123 -> V_133 = V_118 ;
return V_123 ;
}
void F_115 ( struct V_141 * V_142 ,
struct V_1 * V_6 )
{
V_142 -> V_6 = V_6 ;
#ifdef F_116
F_117 ( & V_142 -> V_143 ) ;
#endif
}
enum V_38
F_118 ( struct V_141 * V_142 )
{
unsigned long V_41 = V_42 + F_27 ( 5000 ) ;
if ( ! V_142 )
return V_144 ;
while ( V_142 -> V_39 == - V_78 ) {
if ( F_30 ( V_42 , V_41 ) ) {
F_31 ( L_16 ,
V_43 ) ;
return V_44 ;
}
F_32 () ;
}
return F_26 ( V_142 -> V_6 , V_142 -> V_39 ) ;
}
void F_119 ( struct V_141 * V_142 )
{
struct V_141 * V_145 = F_120 ( V_142 ) ;
struct V_141 * V_146 ;
struct V_1 * V_6 ;
if ( ! V_145 )
return;
F_121 ( V_142 ) ;
V_6 = V_145 -> V_6 ;
for (; V_145 ; V_145 = V_146 ) {
F_122 ( V_145 ) ;
F_123 ( V_145 ) ;
V_146 = F_120 ( V_145 ) ;
if ( V_146 && V_146 -> V_6 == V_6 )
F_121 ( V_145 ) ;
else
V_146 = NULL ;
F_124 ( V_145 ) ;
V_145 -> V_147 ( V_145 ) ;
}
V_6 -> V_2 -> V_55 ( V_6 ) ;
}
static int T_4 F_125 ( void )
{
int V_12 = F_109 () ;
if ( V_12 )
return V_12 ;
return F_126 ( & V_114 ) ;
}
