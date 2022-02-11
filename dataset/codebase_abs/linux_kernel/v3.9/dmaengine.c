static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_3 , F_3 ( * V_5 ) , V_2 ) ;
return V_5 -> V_6 ;
}
static T_1 F_4 ( struct V_2 * V_3 , struct V_7 * V_8 , char * V_9 )
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
static T_1 F_9 ( struct V_2 * V_3 , struct V_7 * V_8 ,
char * V_9 )
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
static T_1 F_10 ( struct V_2 * V_3 , struct V_7 * V_8 , char * V_9 )
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
F_15 ( struct V_22 * V_2 , T_2 * V_23 )
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
if ( V_49 [ V_45 ] )
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
static struct V_1 * F_48 ( enum V_44 V_45 , int V_55 )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
struct V_1 * V_56 = NULL ;
struct V_1 * V_57 = NULL ;
F_46 (device, &dma_device_list, global_node) {
if ( ! F_24 ( V_45 , V_2 -> V_26 ) ||
F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node) {
if ( ! V_6 -> V_18 )
continue;
if ( ! V_57 )
V_57 = V_6 ;
else if ( V_6 -> V_58 < V_57 -> V_58 )
V_57 = V_6 ;
if ( V_55 -- == 0 ) {
V_56 = V_6 ;
break;
}
}
if ( V_56 )
break;
}
if ( ! V_56 )
V_56 = V_57 ;
if ( V_56 )
V_56 -> V_58 ++ ;
return V_56 ;
}
static void F_49 ( void )
{
struct V_1 * V_6 ;
struct V_22 * V_2 ;
int V_59 ;
int V_45 ;
int V_55 ;
F_36 (cap, dma_cap_mask_all)
F_6 (cpu)
F_7 ( V_49 [ V_45 ] , V_59 ) -> V_6 = NULL ;
F_46 (device, &dma_device_list, global_node) {
if ( F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node)
V_6 -> V_58 = 0 ;
}
if ( ! V_31 )
return;
V_55 = 0 ;
F_36 (cap, dma_cap_mask_all)
F_50 (cpu) {
if ( F_51 () > 1 )
V_6 = F_48 ( V_45 , V_55 ++ ) ;
else
V_6 = F_48 ( V_45 , - 1 ) ;
F_7 ( V_49 [ V_45 ] , V_59 ) -> V_6 = V_6 ;
}
}
static struct V_1 * F_52 ( T_2 * V_60 , struct V_22 * V_3 ,
T_5 V_61 , void * V_62 )
{
struct V_1 * V_6 ;
if ( ! F_15 ( V_3 , V_60 ) ) {
F_53 ( L_5 , V_41 ) ;
return NULL ;
}
if ( V_3 -> V_63 > 1 && ! F_24 ( V_34 , V_3 -> V_26 ) )
F_46 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 )
return NULL ;
}
F_46 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 ) {
F_53 ( L_6 ,
V_41 , F_54 ( V_6 ) ) ;
continue;
}
if ( V_61 && ! V_61 ( V_6 , V_62 ) ) {
F_53 ( L_7 ,
V_41 , F_54 ( V_6 ) ) ;
continue;
}
return V_6 ;
}
return NULL ;
}
struct V_1 * F_55 ( T_2 * V_60 , T_5 V_61 , void * V_62 )
{
struct V_22 * V_2 , * V_64 ;
struct V_1 * V_6 = NULL ;
int V_12 ;
F_5 ( & V_13 ) ;
F_56 (device, _d, &dma_device_list, global_node) {
V_6 = F_52 ( V_60 , V_2 , V_61 , V_62 ) ;
if ( V_6 ) {
F_57 ( V_34 , V_2 -> V_26 ) ;
V_2 -> V_65 ++ ;
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_53 ( L_8 ,
V_41 , F_54 ( V_6 ) ) ;
F_58 ( & V_2 -> V_66 ) ;
} else if ( V_12 )
F_53 ( L_9 ,
V_41 , F_54 ( V_6 ) , V_12 ) ;
else
break;
if ( -- V_2 -> V_65 == 0 )
F_59 ( V_34 , V_2 -> V_26 ) ;
V_6 = NULL ;
}
}
F_8 ( & V_13 ) ;
F_53 ( L_10 ,
V_41 ,
V_6 ? L_11 : L_12 ,
V_6 ? F_54 ( V_6 ) : NULL ) ;
return V_6 ;
}
struct V_1 * F_60 ( struct V_2 * V_3 , char * V_67 )
{
if ( V_3 -> V_68 )
return F_61 ( V_3 -> V_68 , V_67 ) ;
return NULL ;
}
void F_62 ( struct V_1 * V_6 )
{
F_5 ( & V_13 ) ;
F_63 ( V_6 -> V_18 != 1 ,
L_13 , V_6 -> V_18 ) ;
F_25 ( V_6 ) ;
if ( -- V_6 -> V_2 -> V_65 == 0 )
F_59 ( V_34 , V_6 -> V_2 -> V_26 ) ;
F_8 ( & V_13 ) ;
}
void F_64 ( void )
{
struct V_22 * V_2 , * V_64 ;
struct V_1 * V_6 ;
int V_12 ;
F_5 ( & V_13 ) ;
V_31 ++ ;
F_56 (device, _d, &dma_device_list, global_node) {
if ( F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node) {
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_58 ( & V_2 -> V_66 ) ;
break;
} else if ( V_12 )
F_53 ( L_9 ,
V_41 , F_54 ( V_6 ) , V_12 ) ;
}
}
if ( V_31 == 1 )
F_49 () ;
F_8 ( & V_13 ) ;
}
void F_65 ( void )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
V_31 -- ;
F_66 ( V_31 < 0 ) ;
F_46 (device, &dma_device_list, global_node) {
if ( F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node)
F_25 ( V_6 ) ;
}
F_8 ( & V_13 ) ;
}
static bool F_67 ( struct V_22 * V_2 )
{
#ifdef F_68
if ( ! F_24 ( V_47 , V_2 -> V_26 ) )
return false ;
#endif
#if F_69 ( V_69 ) || F_69 ( V_70 )
if ( ! F_24 ( V_53 , V_2 -> V_26 ) )
return false ;
#endif
#if F_69 ( V_71 ) || F_69 ( V_72 )
if ( ! F_24 ( V_73 , V_2 -> V_26 ) )
return false ;
#endif
#if F_69 ( V_74 ) || F_69 ( V_75 )
if ( ! F_24 ( V_76 , V_2 -> V_26 ) )
return false ;
#ifndef F_70
if ( ! F_24 ( V_77 , V_2 -> V_26 ) )
return false ;
#endif
#endif
#if F_69 ( V_78 ) || F_69 ( V_79 )
if ( ! F_24 ( V_80 , V_2 -> V_26 ) )
return false ;
#ifndef F_71
if ( ! F_24 ( V_81 , V_2 -> V_26 ) )
return false ;
#endif
#endif
return true ;
}
static int F_72 ( struct V_22 * V_2 )
{
int V_82 ;
F_5 ( & V_13 ) ;
V_82 = F_73 ( & V_20 , NULL , 0 , 0 , V_83 ) ;
if ( V_82 >= 0 )
V_2 -> V_21 = V_82 ;
F_8 ( & V_13 ) ;
return V_82 < 0 ? V_82 : 0 ;
}
int F_74 ( struct V_22 * V_2 )
{
int V_63 = 0 , V_82 ;
struct V_1 * V_6 ;
T_6 * V_19 ;
if ( ! V_2 )
return - V_16 ;
F_66 ( F_24 ( V_53 , V_2 -> V_26 ) &&
! V_2 -> V_84 ) ;
F_66 ( F_24 ( V_76 , V_2 -> V_26 ) &&
! V_2 -> V_85 ) ;
F_66 ( F_24 ( V_77 , V_2 -> V_26 ) &&
! V_2 -> V_86 ) ;
F_66 ( F_24 ( V_80 , V_2 -> V_26 ) &&
! V_2 -> V_87 ) ;
F_66 ( F_24 ( V_81 , V_2 -> V_26 ) &&
! V_2 -> V_88 ) ;
F_66 ( F_24 ( V_73 , V_2 -> V_26 ) &&
! V_2 -> V_89 ) ;
F_66 ( F_24 ( V_47 , V_2 -> V_26 ) &&
! V_2 -> V_90 ) ;
F_66 ( F_24 ( V_91 , V_2 -> V_26 ) &&
! V_2 -> V_92 ) ;
F_66 ( F_24 ( V_93 , V_2 -> V_26 ) &&
! V_2 -> V_94 ) ;
F_66 ( F_24 ( V_48 , V_2 -> V_26 ) &&
! V_2 -> V_95 ) ;
F_66 ( F_24 ( V_96 , V_2 -> V_26 ) &&
! V_2 -> V_97 ) ;
F_66 ( ! V_2 -> V_33 ) ;
F_66 ( ! V_2 -> V_35 ) ;
F_66 ( ! V_2 -> V_98 ) ;
F_66 ( ! V_2 -> V_54 ) ;
F_66 ( ! V_2 -> V_3 ) ;
if ( F_67 ( V_2 ) )
F_57 ( V_99 , V_2 -> V_26 ) ;
V_19 = F_75 ( sizeof( * V_19 ) , V_83 ) ;
if ( ! V_19 )
return - V_51 ;
V_82 = F_72 ( V_2 ) ;
if ( V_82 != 0 ) {
F_14 ( V_19 ) ;
return V_82 ;
}
F_76 ( V_19 , 0 ) ;
F_46 (chan, &device->channels, device_node) {
V_82 = - V_51 ;
V_6 -> V_14 = F_37 ( F_3 ( * V_6 -> V_14 ) ) ;
if ( V_6 -> V_14 == NULL )
goto V_100;
V_6 -> V_3 = F_77 ( sizeof( * V_6 -> V_3 ) , V_83 ) ;
if ( V_6 -> V_3 == NULL ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
goto V_100;
}
V_6 -> V_101 = V_63 ++ ;
V_6 -> V_3 -> V_2 . V_102 = & V_103 ;
V_6 -> V_3 -> V_2 . V_104 = V_2 -> V_3 ;
V_6 -> V_3 -> V_6 = V_6 ;
V_6 -> V_3 -> V_19 = V_19 ;
V_6 -> V_3 -> V_21 = V_2 -> V_21 ;
F_78 ( V_19 ) ;
F_79 ( & V_6 -> V_3 -> V_2 , L_14 ,
V_2 -> V_21 , V_6 -> V_101 ) ;
V_82 = F_80 ( & V_6 -> V_3 -> V_2 ) ;
if ( V_82 ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_14 ( V_6 -> V_3 ) ;
F_81 ( V_19 ) ;
goto V_100;
}
V_6 -> V_18 = 0 ;
}
V_2 -> V_63 = V_63 ;
F_5 ( & V_13 ) ;
if ( V_31 && ! F_24 ( V_34 , V_2 -> V_26 ) )
F_46 (chan, &device->channels, device_node) {
if ( F_21 ( V_6 ) == - V_16 ) {
V_82 = - V_16 ;
F_8 ( & V_13 ) ;
goto V_100;
}
}
F_82 ( & V_2 -> V_66 , & V_105 ) ;
if ( F_24 ( V_34 , V_2 -> V_26 ) )
V_2 -> V_65 ++ ;
F_49 () ;
F_8 ( & V_13 ) ;
return 0 ;
V_100:
if ( F_83 ( V_19 ) == 0 ) {
F_5 ( & V_13 ) ;
F_13 ( & V_20 , V_2 -> V_21 ) ;
F_8 ( & V_13 ) ;
F_14 ( V_19 ) ;
return V_82 ;
}
F_46 (chan, &device->channels, device_node) {
if ( V_6 -> V_14 == NULL )
continue;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_84 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
return V_82 ;
}
void F_85 ( struct V_22 * V_2 )
{
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
F_58 ( & V_2 -> V_66 ) ;
F_49 () ;
F_8 ( & V_13 ) ;
F_46 (chan, &device->channels, device_node) {
F_63 ( V_6 -> V_18 ,
L_15 ,
V_41 , V_6 -> V_18 ) ;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_84 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
}
T_3
F_86 ( struct V_1 * V_6 , void * V_106 ,
void * V_107 , T_7 V_108 )
{
struct V_22 * V_3 = V_6 -> V_2 ;
struct V_109 * V_110 ;
T_8 V_111 , V_112 ;
T_3 V_37 ;
unsigned long V_113 ;
V_112 = F_87 ( V_3 -> V_3 , V_107 , V_108 , V_114 ) ;
V_111 = F_87 ( V_3 -> V_3 , V_106 , V_108 , V_115 ) ;
V_113 = V_116 |
V_117 |
V_118 ;
V_110 = V_3 -> V_84 ( V_6 , V_111 , V_112 , V_108 , V_113 ) ;
if ( ! V_110 ) {
F_88 ( V_3 -> V_3 , V_112 , V_108 , V_114 ) ;
F_88 ( V_3 -> V_3 , V_111 , V_108 , V_115 ) ;
return - V_51 ;
}
V_110 -> V_119 = NULL ;
V_37 = V_110 -> V_120 ( V_110 ) ;
F_89 () ;
F_90 ( V_6 -> V_14 -> V_17 , V_108 ) ;
F_91 ( V_6 -> V_14 -> V_15 ) ;
F_92 () ;
return V_37 ;
}
T_3
F_93 ( struct V_1 * V_6 , struct V_121 * V_121 ,
unsigned int V_122 , void * V_123 , T_7 V_108 )
{
struct V_22 * V_3 = V_6 -> V_2 ;
struct V_109 * V_110 ;
T_8 V_111 , V_112 ;
T_3 V_37 ;
unsigned long V_113 ;
V_112 = F_87 ( V_3 -> V_3 , V_123 , V_108 , V_114 ) ;
V_111 = F_94 ( V_3 -> V_3 , V_121 , V_122 , V_108 , V_115 ) ;
V_113 = V_116 | V_117 ;
V_110 = V_3 -> V_84 ( V_6 , V_111 , V_112 , V_108 , V_113 ) ;
if ( ! V_110 ) {
F_88 ( V_3 -> V_3 , V_112 , V_108 , V_114 ) ;
F_95 ( V_3 -> V_3 , V_111 , V_108 , V_115 ) ;
return - V_51 ;
}
V_110 -> V_119 = NULL ;
V_37 = V_110 -> V_120 ( V_110 ) ;
F_89 () ;
F_90 ( V_6 -> V_14 -> V_17 , V_108 ) ;
F_91 ( V_6 -> V_14 -> V_15 ) ;
F_92 () ;
return V_37 ;
}
T_3
F_96 ( struct V_1 * V_6 , struct V_121 * V_124 ,
unsigned int V_125 , struct V_121 * V_126 , unsigned int V_127 ,
T_7 V_108 )
{
struct V_22 * V_3 = V_6 -> V_2 ;
struct V_109 * V_110 ;
T_8 V_111 , V_112 ;
T_3 V_37 ;
unsigned long V_113 ;
V_112 = F_94 ( V_3 -> V_3 , V_126 , V_127 , V_108 , V_114 ) ;
V_111 = F_94 ( V_3 -> V_3 , V_124 , V_125 , V_108 ,
V_115 ) ;
V_113 = V_116 ;
V_110 = V_3 -> V_84 ( V_6 , V_111 , V_112 , V_108 , V_113 ) ;
if ( ! V_110 ) {
F_95 ( V_3 -> V_3 , V_112 , V_108 , V_114 ) ;
F_95 ( V_3 -> V_3 , V_111 , V_108 , V_115 ) ;
return - V_51 ;
}
V_110 -> V_119 = NULL ;
V_37 = V_110 -> V_120 ( V_110 ) ;
F_89 () ;
F_90 ( V_6 -> V_14 -> V_17 , V_108 ) ;
F_91 ( V_6 -> V_14 -> V_15 ) ;
F_92 () ;
return V_37 ;
}
void F_97 ( struct V_109 * V_110 ,
struct V_1 * V_6 )
{
V_110 -> V_6 = V_6 ;
#ifdef F_98
F_99 ( & V_110 -> V_128 ) ;
#endif
}
enum V_36
F_100 ( struct V_109 * V_110 )
{
unsigned long V_39 = V_40 + F_27 ( 5000 ) ;
if ( ! V_110 )
return V_129 ;
while ( V_110 -> V_37 == - V_130 ) {
if ( F_30 ( V_40 , V_39 ) ) {
F_31 ( L_16 ,
V_41 ) ;
return V_42 ;
}
F_32 () ;
}
return F_26 ( V_110 -> V_6 , V_110 -> V_37 ) ;
}
void F_101 ( struct V_109 * V_110 )
{
struct V_109 * V_131 = F_102 ( V_110 ) ;
struct V_109 * V_132 ;
struct V_1 * V_6 ;
if ( ! V_131 )
return;
F_103 ( V_110 ) ;
V_6 = V_131 -> V_6 ;
for (; V_131 ; V_131 = V_132 ) {
F_104 ( V_131 ) ;
F_105 ( V_131 ) ;
V_132 = F_102 ( V_131 ) ;
if ( V_132 && V_132 -> V_6 == V_6 )
F_103 ( V_131 ) ;
else
V_132 = NULL ;
F_106 ( V_131 ) ;
V_131 -> V_120 ( V_131 ) ;
}
V_6 -> V_2 -> V_54 ( V_6 ) ;
}
static int T_4 F_107 ( void )
{
return F_108 ( & V_103 ) ;
}
