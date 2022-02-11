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
int V_12 = - V_16 ;
struct V_28 * V_30 = F_18 ( V_6 ) ;
if ( V_6 -> V_18 ) {
F_20 ( V_30 ) ;
V_12 = 0 ;
} else if ( F_22 ( V_30 ) )
V_12 = 0 ;
if ( V_12 == 0 )
V_6 -> V_18 ++ ;
if ( V_6 -> V_18 == 1 && V_12 == 0 ) {
int V_32 = V_6 -> V_2 -> V_33 ( V_6 ) ;
if ( V_32 < 0 ) {
V_12 = V_32 ;
V_6 -> V_18 = 0 ;
F_23 ( V_30 ) ;
} else if ( ! F_24 ( V_34 , V_6 -> V_2 -> V_26 ) )
F_19 ( V_6 ) ;
}
return V_12 ;
}
static void F_25 ( struct V_1 * V_6 )
{
if ( ! V_6 -> V_18 )
return;
V_6 -> V_18 -- ;
F_23 ( F_18 ( V_6 ) ) ;
if ( V_6 -> V_18 == 0 )
V_6 -> V_2 -> V_35 ( V_6 ) ;
}
enum V_36 F_26 ( struct V_1 * V_6 , T_3 V_37 )
{
enum V_36 V_38 ;
unsigned long V_39 = V_40 + F_27 ( 5000 ) ;
F_28 ( V_6 ) ;
do {
V_38 = F_29 ( V_6 , V_37 , NULL , NULL ) ;
if ( F_30 ( V_40 , V_39 ) ) {
F_31 ( L_3 , V_41 ) ;
return V_42 ;
}
if ( V_38 != V_43 )
break;
F_32 () ;
} while ( 1 );
return V_38 ;
}
static int T_4 F_33 ( void )
{
enum V_44 V_45 ;
int V_12 = 0 ;
F_34 ( V_46 . V_25 , V_27 ) ;
F_35 ( V_47 , V_46 . V_25 ) ;
F_35 ( V_34 , V_46 . V_25 ) ;
F_35 ( V_48 , V_46 . V_25 ) ;
F_36 (cap, dma_cap_mask_all) {
V_49 [ V_45 ] = F_37 ( struct V_50 ) ;
if ( ! V_49 [ V_45 ] ) {
V_12 = - V_51 ;
break;
}
}
if ( V_12 ) {
F_31 ( L_4 ) ;
F_36 (cap, dma_cap_mask_all)
F_38 ( V_49 [ V_45 ] ) ;
}
return V_12 ;
}
struct V_1 * F_39 ( enum V_44 V_52 )
{
return F_40 ( V_49 [ V_52 ] -> V_6 ) ;
}
struct V_1 * F_41 ( void )
{
struct V_1 * V_6 = F_39 ( V_53 ) ;
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
if ( F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node)
if ( V_6 -> V_18 )
V_2 -> V_54 ( V_6 ) ;
}
F_47 () ;
}
static bool F_48 ( struct V_1 * V_6 , int V_55 )
{
int V_56 = F_49 ( V_6 -> V_2 -> V_3 ) ;
return V_56 == - 1 || F_50 ( V_55 , F_51 ( V_56 ) ) ;
}
static struct V_1 * F_52 ( enum V_44 V_45 , int V_55 )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
struct V_1 * V_57 = NULL ;
struct V_1 * V_58 = NULL ;
F_46 (device, &dma_device_list, global_node) {
if ( ! F_24 ( V_45 , V_2 -> V_26 ) ||
F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node) {
if ( ! V_6 -> V_18 )
continue;
if ( ! V_57 || V_6 -> V_59 < V_57 -> V_59 )
V_57 = V_6 ;
if ( F_48 ( V_6 , V_55 ) )
if ( ! V_58 ||
V_6 -> V_59 < V_58 -> V_59 )
V_58 = V_6 ;
}
}
V_6 = V_58 ? V_58 : V_57 ;
if ( V_6 )
V_6 -> V_59 ++ ;
return V_6 ;
}
static void F_53 ( void )
{
struct V_1 * V_6 ;
struct V_22 * V_2 ;
int V_55 ;
int V_45 ;
F_36 (cap, dma_cap_mask_all)
F_6 (cpu)
F_7 ( V_49 [ V_45 ] , V_55 ) -> V_6 = NULL ;
F_46 (device, &dma_device_list, global_node) {
if ( F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node)
V_6 -> V_59 = 0 ;
}
if ( ! V_31 )
return;
F_36 (cap, dma_cap_mask_all)
F_54 (cpu) {
V_6 = F_52 ( V_45 , V_55 ) ;
F_7 ( V_49 [ V_45 ] , V_55 ) -> V_6 = V_6 ;
}
}
static struct V_1 * F_55 ( const T_2 * V_60 ,
struct V_22 * V_3 ,
T_5 V_61 , void * V_62 )
{
struct V_1 * V_6 ;
if ( ! F_15 ( V_3 , V_60 ) ) {
F_56 ( L_5 , V_41 ) ;
return NULL ;
}
if ( V_3 -> V_63 > 1 && ! F_24 ( V_34 , V_3 -> V_26 ) )
F_46 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 )
return NULL ;
}
F_46 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 ) {
F_56 ( L_6 ,
V_41 , F_57 ( V_6 ) ) ;
continue;
}
if ( V_61 && ! V_61 ( V_6 , V_62 ) ) {
F_56 ( L_7 ,
V_41 , F_57 ( V_6 ) ) ;
continue;
}
return V_6 ;
}
return NULL ;
}
struct V_1 * F_58 ( struct V_1 * V_6 )
{
int V_12 = - V_64 ;
F_5 ( & V_13 ) ;
if ( V_6 -> V_18 == 0 ) {
V_12 = F_21 ( V_6 ) ;
if ( V_12 )
F_56 ( L_8 ,
V_41 , F_57 ( V_6 ) , V_12 ) ;
} else
V_6 = NULL ;
F_8 ( & V_13 ) ;
return V_6 ;
}
struct V_1 * F_59 ( struct V_22 * V_2 )
{
T_2 V_60 ;
struct V_1 * V_6 ;
int V_12 ;
F_60 ( V_60 ) ;
F_61 ( V_48 , V_60 ) ;
F_5 ( & V_13 ) ;
V_6 = F_55 ( & V_60 , V_2 , NULL , NULL ) ;
if ( V_6 ) {
V_12 = F_21 ( V_6 ) ;
if ( V_12 ) {
F_56 ( L_8 ,
V_41 , F_57 ( V_6 ) , V_12 ) ;
V_6 = NULL ;
}
}
F_8 ( & V_13 ) ;
return V_6 ;
}
struct V_1 * F_62 ( const T_2 * V_60 ,
T_5 V_61 , void * V_62 )
{
struct V_22 * V_2 , * V_65 ;
struct V_1 * V_6 = NULL ;
int V_12 ;
F_5 ( & V_13 ) ;
F_63 (device, _d, &dma_device_list, global_node) {
V_6 = F_55 ( V_60 , V_2 , V_61 , V_62 ) ;
if ( V_6 ) {
F_61 ( V_34 , V_2 -> V_26 ) ;
V_2 -> V_66 ++ ;
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_56 ( L_9 ,
V_41 , F_57 ( V_6 ) ) ;
F_64 ( & V_2 -> V_67 ) ;
} else if ( V_12 )
F_56 ( L_8 ,
V_41 , F_57 ( V_6 ) , V_12 ) ;
else
break;
if ( -- V_2 -> V_66 == 0 )
F_65 ( V_34 , V_2 -> V_26 ) ;
V_6 = NULL ;
}
}
F_8 ( & V_13 ) ;
F_56 ( L_10 ,
V_41 ,
V_6 ? L_11 : L_12 ,
V_6 ? F_57 ( V_6 ) : NULL ) ;
return V_6 ;
}
struct V_1 * F_66 ( struct V_2 * V_3 ,
const char * V_68 )
{
if ( V_3 -> V_69 )
return F_67 ( V_3 -> V_69 , V_68 ) ;
if ( F_68 ( V_3 ) )
return F_69 ( V_3 , V_68 ) ;
return F_70 ( - V_16 ) ;
}
struct V_1 * F_71 ( struct V_2 * V_3 ,
const char * V_68 )
{
struct V_1 * V_70 = F_66 ( V_3 , V_68 ) ;
if ( F_72 ( V_70 ) )
return NULL ;
return V_70 ;
}
void F_73 ( struct V_1 * V_6 )
{
F_5 ( & V_13 ) ;
F_74 ( V_6 -> V_18 != 1 ,
L_13 , V_6 -> V_18 ) ;
F_25 ( V_6 ) ;
if ( -- V_6 -> V_2 -> V_66 == 0 )
F_65 ( V_34 , V_6 -> V_2 -> V_26 ) ;
F_8 ( & V_13 ) ;
}
void F_75 ( void )
{
struct V_22 * V_2 , * V_65 ;
struct V_1 * V_6 ;
int V_12 ;
F_5 ( & V_13 ) ;
V_31 ++ ;
F_63 (device, _d, &dma_device_list, global_node) {
if ( F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node) {
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_64 ( & V_2 -> V_67 ) ;
break;
} else if ( V_12 )
F_56 ( L_8 ,
V_41 , F_57 ( V_6 ) , V_12 ) ;
}
}
if ( V_31 == 1 )
F_53 () ;
F_8 ( & V_13 ) ;
}
void F_76 ( void )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
V_31 -- ;
F_77 ( V_31 < 0 ) ;
F_46 (device, &dma_device_list, global_node) {
if ( F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node)
F_25 ( V_6 ) ;
}
F_8 ( & V_13 ) ;
}
static bool F_78 ( struct V_22 * V_2 )
{
#ifdef F_79
if ( ! F_24 ( V_47 , V_2 -> V_26 ) )
return false ;
#endif
#if F_80 ( V_71 ) || F_80 ( V_72 )
if ( ! F_24 ( V_53 , V_2 -> V_26 ) )
return false ;
#endif
#if F_80 ( V_73 ) || F_80 ( V_74 )
if ( ! F_24 ( V_75 , V_2 -> V_26 ) )
return false ;
#ifndef F_81
if ( ! F_24 ( V_76 , V_2 -> V_26 ) )
return false ;
#endif
#endif
#if F_80 ( V_77 ) || F_80 ( V_78 )
if ( ! F_24 ( V_79 , V_2 -> V_26 ) )
return false ;
#ifndef F_82
if ( ! F_24 ( V_80 , V_2 -> V_26 ) )
return false ;
#endif
#endif
return true ;
}
static int F_83 ( struct V_22 * V_2 )
{
int V_81 ;
F_5 ( & V_13 ) ;
V_81 = F_84 ( & V_20 , NULL , 0 , 0 , V_82 ) ;
if ( V_81 >= 0 )
V_2 -> V_21 = V_81 ;
F_8 ( & V_13 ) ;
return V_81 < 0 ? V_81 : 0 ;
}
int F_85 ( struct V_22 * V_2 )
{
int V_63 = 0 , V_81 ;
struct V_1 * V_6 ;
T_6 * V_19 ;
if ( ! V_2 )
return - V_16 ;
F_77 ( F_24 ( V_53 , V_2 -> V_26 ) &&
! V_2 -> V_83 ) ;
F_77 ( F_24 ( V_75 , V_2 -> V_26 ) &&
! V_2 -> V_84 ) ;
F_77 ( F_24 ( V_76 , V_2 -> V_26 ) &&
! V_2 -> V_85 ) ;
F_77 ( F_24 ( V_79 , V_2 -> V_26 ) &&
! V_2 -> V_86 ) ;
F_77 ( F_24 ( V_80 , V_2 -> V_26 ) &&
! V_2 -> V_87 ) ;
F_77 ( F_24 ( V_47 , V_2 -> V_26 ) &&
! V_2 -> V_88 ) ;
F_77 ( F_24 ( V_89 , V_2 -> V_26 ) &&
! V_2 -> V_90 ) ;
F_77 ( F_24 ( V_91 , V_2 -> V_26 ) &&
! V_2 -> V_92 ) ;
F_77 ( F_24 ( V_48 , V_2 -> V_26 ) &&
! V_2 -> V_93 ) ;
F_77 ( F_24 ( V_94 , V_2 -> V_26 ) &&
! V_2 -> V_95 ) ;
F_77 ( ! V_2 -> V_33 ) ;
F_77 ( ! V_2 -> V_35 ) ;
F_77 ( ! V_2 -> V_96 ) ;
F_77 ( ! V_2 -> V_54 ) ;
F_77 ( ! V_2 -> V_3 ) ;
if ( F_78 ( V_2 ) )
F_61 ( V_97 , V_2 -> V_26 ) ;
V_19 = F_86 ( sizeof( * V_19 ) , V_82 ) ;
if ( ! V_19 )
return - V_51 ;
V_81 = F_83 ( V_2 ) ;
if ( V_81 != 0 ) {
F_14 ( V_19 ) ;
return V_81 ;
}
F_87 ( V_19 , 0 ) ;
F_46 (chan, &device->channels, device_node) {
V_81 = - V_51 ;
V_6 -> V_14 = F_37 ( F_3 ( * V_6 -> V_14 ) ) ;
if ( V_6 -> V_14 == NULL )
goto V_98;
V_6 -> V_3 = F_88 ( sizeof( * V_6 -> V_3 ) , V_82 ) ;
if ( V_6 -> V_3 == NULL ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
goto V_98;
}
V_6 -> V_99 = V_63 ++ ;
V_6 -> V_3 -> V_2 . V_100 = & V_101 ;
V_6 -> V_3 -> V_2 . V_102 = V_2 -> V_3 ;
V_6 -> V_3 -> V_6 = V_6 ;
V_6 -> V_3 -> V_19 = V_19 ;
V_6 -> V_3 -> V_21 = V_2 -> V_21 ;
F_89 ( V_19 ) ;
F_90 ( & V_6 -> V_3 -> V_2 , L_14 ,
V_2 -> V_21 , V_6 -> V_99 ) ;
V_81 = F_91 ( & V_6 -> V_3 -> V_2 ) ;
if ( V_81 ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_14 ( V_6 -> V_3 ) ;
F_92 ( V_19 ) ;
goto V_98;
}
V_6 -> V_18 = 0 ;
}
V_2 -> V_63 = V_63 ;
F_5 ( & V_13 ) ;
if ( V_31 && ! F_24 ( V_34 , V_2 -> V_26 ) )
F_46 (chan, &device->channels, device_node) {
if ( F_21 ( V_6 ) == - V_16 ) {
V_81 = - V_16 ;
F_8 ( & V_13 ) ;
goto V_98;
}
}
F_93 ( & V_2 -> V_67 , & V_103 ) ;
if ( F_24 ( V_34 , V_2 -> V_26 ) )
V_2 -> V_66 ++ ;
F_53 () ;
F_8 ( & V_13 ) ;
return 0 ;
V_98:
if ( F_94 ( V_19 ) == 0 ) {
F_5 ( & V_13 ) ;
F_13 ( & V_20 , V_2 -> V_21 ) ;
F_8 ( & V_13 ) ;
F_14 ( V_19 ) ;
return V_81 ;
}
F_46 (chan, &device->channels, device_node) {
if ( V_6 -> V_14 == NULL )
continue;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_95 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
return V_81 ;
}
void F_96 ( struct V_22 * V_2 )
{
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
F_64 ( & V_2 -> V_67 ) ;
F_53 () ;
F_8 ( & V_13 ) ;
F_46 (chan, &device->channels, device_node) {
F_74 ( V_6 -> V_18 ,
L_15 ,
V_41 , V_6 -> V_18 ) ;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_95 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
}
static struct V_104 * F_97 ( int V_105 )
{
int V_106 = F_98 ( V_105 ) ;
switch ( V_106 ) {
case 0 ... 1 :
return & V_107 [ 0 ] ;
case 2 ... 4 :
return & V_107 [ 1 ] ;
case 5 ... 7 :
return & V_107 [ 2 ] ;
case 8 :
return & V_107 [ 3 ] ;
default:
F_99 () ;
return NULL ;
}
}
static void F_100 ( struct V_108 * V_108 )
{
struct V_109 * V_110 = F_2 ( V_108 , F_3 ( * V_110 ) , V_108 ) ;
struct V_2 * V_3 = V_110 -> V_3 ;
int V_111 , V_11 ;
V_111 = V_110 -> V_112 ;
for ( V_11 = 0 ; V_11 < V_111 ; V_11 ++ )
F_101 ( V_3 , V_110 -> V_113 [ V_11 ] , V_110 -> V_114 ,
V_115 ) ;
V_111 += V_110 -> V_116 ;
for (; V_11 < V_111 ; V_11 ++ )
F_101 ( V_3 , V_110 -> V_113 [ V_11 ] , V_110 -> V_114 ,
V_117 ) ;
V_111 += V_110 -> V_118 ;
for (; V_11 < V_111 ; V_11 ++ ) {
if ( V_110 -> V_113 [ V_11 ] == 0 )
continue;
F_101 ( V_3 , V_110 -> V_113 [ V_11 ] , V_110 -> V_114 ,
V_119 ) ;
}
V_111 = V_110 -> V_120 ;
F_102 ( V_110 , F_97 ( V_111 ) -> V_121 ) ;
}
void F_103 ( struct V_109 * V_110 )
{
if ( V_110 )
F_104 ( & V_110 -> V_108 , F_100 ) ;
}
static void F_105 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_106 ( V_107 ) ; V_11 ++ ) {
struct V_104 * V_122 = & V_107 [ V_11 ] ;
if ( V_122 -> V_121 )
F_107 ( V_122 -> V_121 ) ;
V_122 -> V_121 = NULL ;
if ( V_122 -> V_123 )
F_108 ( V_122 -> V_123 ) ;
V_122 -> V_123 = NULL ;
}
}
static int T_4 F_109 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_106 ( V_107 ) ; V_11 ++ ) {
struct V_104 * V_122 = & V_107 [ V_11 ] ;
T_7 V_124 ;
V_124 = sizeof( struct V_109 ) +
sizeof( V_125 ) * V_122 -> V_124 ;
V_122 -> V_123 = F_110 ( V_122 -> V_68 , V_124 , 0 ,
V_126 , NULL ) ;
if ( ! V_122 -> V_123 )
break;
V_122 -> V_121 = F_111 ( 1 , V_122 -> V_123 ) ;
if ( ! V_122 -> V_121 )
break;
}
if ( V_11 == F_106 ( V_107 ) )
return 0 ;
F_105 () ;
return - V_51 ;
}
struct V_109 *
F_112 ( struct V_2 * V_3 , int V_105 , T_8 V_127 )
{
struct V_109 * V_110 ;
V_110 = F_113 ( F_97 ( V_105 ) -> V_121 , V_127 ) ;
if ( ! V_110 )
return NULL ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
F_114 ( & V_110 -> V_108 ) ;
V_110 -> V_3 = V_3 ;
V_110 -> V_120 = V_105 ;
return V_110 ;
}
void F_115 ( struct V_128 * V_129 ,
struct V_1 * V_6 )
{
V_129 -> V_6 = V_6 ;
#ifdef F_116
F_117 ( & V_129 -> V_130 ) ;
#endif
}
enum V_36
F_118 ( struct V_128 * V_129 )
{
unsigned long V_39 = V_40 + F_27 ( 5000 ) ;
if ( ! V_129 )
return V_131 ;
while ( V_129 -> V_37 == - V_64 ) {
if ( F_30 ( V_40 , V_39 ) ) {
F_31 ( L_16 ,
V_41 ) ;
return V_42 ;
}
F_32 () ;
}
return F_26 ( V_129 -> V_6 , V_129 -> V_37 ) ;
}
void F_119 ( struct V_128 * V_129 )
{
struct V_128 * V_132 = F_120 ( V_129 ) ;
struct V_128 * V_133 ;
struct V_1 * V_6 ;
if ( ! V_132 )
return;
F_121 ( V_129 ) ;
V_6 = V_132 -> V_6 ;
for (; V_132 ; V_132 = V_133 ) {
F_122 ( V_132 ) ;
F_123 ( V_132 ) ;
V_133 = F_120 ( V_132 ) ;
if ( V_133 && V_133 -> V_6 == V_6 )
F_121 ( V_132 ) ;
else
V_133 = NULL ;
F_124 ( V_132 ) ;
V_132 -> V_134 ( V_132 ) ;
}
V_6 -> V_2 -> V_54 ( V_6 ) ;
}
static int T_4 F_125 ( void )
{
int V_12 = F_109 () ;
if ( V_12 )
return V_12 ;
return F_126 ( & V_101 ) ;
}
