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
F_31 ( V_41 L_3 ) ;
return V_42 ;
}
} while ( V_38 == V_43 );
return V_38 ;
}
static int T_4 F_32 ( void )
{
enum V_44 V_45 ;
int V_12 = 0 ;
F_33 ( V_46 . V_25 , V_27 ) ;
F_34 ( V_47 , V_46 . V_25 ) ;
F_34 ( V_34 , V_46 . V_25 ) ;
F_34 ( V_48 , V_46 . V_25 ) ;
F_35 (cap, dma_cap_mask_all) {
V_49 [ V_45 ] = F_36 ( struct V_50 ) ;
if ( ! V_49 [ V_45 ] ) {
V_12 = - V_51 ;
break;
}
}
if ( V_12 ) {
F_37 ( L_4 ) ;
F_35 (cap, dma_cap_mask_all)
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
F_35 (cap, dma_cap_mask_all)
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
F_35 (cap, dma_cap_mask_all)
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
F_53 ( L_5 , V_63 ) ;
return NULL ;
}
if ( V_3 -> V_64 > 1 && ! F_24 ( V_34 , V_3 -> V_26 ) )
F_46 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 )
return NULL ;
}
F_46 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 ) {
F_53 ( L_6 ,
V_63 , F_54 ( V_6 ) ) ;
continue;
}
if ( V_61 && ! V_61 ( V_6 , V_62 ) ) {
F_53 ( L_7 ,
V_63 , F_54 ( V_6 ) ) ;
continue;
}
return V_6 ;
}
return NULL ;
}
struct V_1 * F_55 ( T_2 * V_60 , T_5 V_61 , void * V_62 )
{
struct V_22 * V_2 , * V_65 ;
struct V_1 * V_6 = NULL ;
int V_12 ;
F_5 ( & V_13 ) ;
F_56 (device, _d, &dma_device_list, global_node) {
V_6 = F_52 ( V_60 , V_2 , V_61 , V_62 ) ;
if ( V_6 ) {
F_57 ( V_34 , V_2 -> V_26 ) ;
V_2 -> V_66 ++ ;
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_53 ( L_8 , V_63 ,
F_54 ( V_6 ) ) ;
F_58 ( & V_2 -> V_67 ) ;
} else if ( V_12 )
F_53 ( L_9 ,
V_63 , F_54 ( V_6 ) , V_12 ) ;
else
break;
if ( -- V_2 -> V_66 == 0 )
F_59 ( V_34 , V_2 -> V_26 ) ;
V_6 = NULL ;
}
}
F_8 ( & V_13 ) ;
F_53 ( L_10 , V_63 , V_6 ? L_11 : L_12 ,
V_6 ? F_54 ( V_6 ) : NULL ) ;
return V_6 ;
}
void F_60 ( struct V_1 * V_6 )
{
F_5 ( & V_13 ) ;
F_61 ( V_6 -> V_18 != 1 ,
L_13 , V_6 -> V_18 ) ;
F_25 ( V_6 ) ;
if ( -- V_6 -> V_2 -> V_66 == 0 )
F_59 ( V_34 , V_6 -> V_2 -> V_26 ) ;
F_8 ( & V_13 ) ;
}
void F_62 ( void )
{
struct V_22 * V_2 , * V_65 ;
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
F_58 ( & V_2 -> V_67 ) ;
break;
} else if ( V_12 )
F_37 ( L_9 ,
V_63 , F_54 ( V_6 ) , V_12 ) ;
}
}
if ( V_31 == 1 )
F_49 () ;
F_8 ( & V_13 ) ;
}
void F_63 ( void )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
V_31 -- ;
F_64 ( V_31 < 0 ) ;
F_46 (device, &dma_device_list, global_node) {
if ( F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node)
F_25 ( V_6 ) ;
}
F_8 ( & V_13 ) ;
}
static bool F_65 ( struct V_22 * V_2 )
{
#ifdef F_66
if ( ! F_24 ( V_47 , V_2 -> V_26 ) )
return false ;
#endif
#if F_67 ( V_68 ) || F_67 ( V_69 )
if ( ! F_24 ( V_53 , V_2 -> V_26 ) )
return false ;
#endif
#if F_67 ( V_70 ) || F_67 ( V_71 )
if ( ! F_24 ( V_72 , V_2 -> V_26 ) )
return false ;
#endif
#if F_67 ( V_73 ) || F_67 ( V_74 )
if ( ! F_24 ( V_75 , V_2 -> V_26 ) )
return false ;
#ifndef F_68
if ( ! F_24 ( V_76 , V_2 -> V_26 ) )
return false ;
#endif
#endif
#if F_67 ( V_77 ) || F_67 ( V_78 )
if ( ! F_24 ( V_79 , V_2 -> V_26 ) )
return false ;
#ifndef F_69
if ( ! F_24 ( V_80 , V_2 -> V_26 ) )
return false ;
#endif
#endif
return true ;
}
static int F_70 ( struct V_22 * V_2 )
{
int V_81 ;
V_82:
if ( ! F_71 ( & V_20 , V_83 ) )
return - V_51 ;
F_5 ( & V_13 ) ;
V_81 = F_72 ( & V_20 , NULL , & V_2 -> V_21 ) ;
F_8 ( & V_13 ) ;
if ( V_81 == - V_84 )
goto V_82;
else if ( V_81 != 0 )
return V_81 ;
return 0 ;
}
int F_73 ( struct V_22 * V_2 )
{
int V_64 = 0 , V_81 ;
struct V_1 * V_6 ;
T_6 * V_19 ;
if ( ! V_2 )
return - V_16 ;
F_64 ( F_24 ( V_53 , V_2 -> V_26 ) &&
! V_2 -> V_85 ) ;
F_64 ( F_24 ( V_75 , V_2 -> V_26 ) &&
! V_2 -> V_86 ) ;
F_64 ( F_24 ( V_76 , V_2 -> V_26 ) &&
! V_2 -> V_87 ) ;
F_64 ( F_24 ( V_79 , V_2 -> V_26 ) &&
! V_2 -> V_88 ) ;
F_64 ( F_24 ( V_80 , V_2 -> V_26 ) &&
! V_2 -> V_89 ) ;
F_64 ( F_24 ( V_72 , V_2 -> V_26 ) &&
! V_2 -> V_90 ) ;
F_64 ( F_24 ( V_47 , V_2 -> V_26 ) &&
! V_2 -> V_91 ) ;
F_64 ( F_24 ( V_92 , V_2 -> V_26 ) &&
! V_2 -> V_93 ) ;
F_64 ( F_24 ( V_94 , V_2 -> V_26 ) &&
! V_2 -> V_95 ) ;
F_64 ( F_24 ( V_48 , V_2 -> V_26 ) &&
! V_2 -> V_96 ) ;
F_64 ( F_24 ( V_97 , V_2 -> V_26 ) &&
! V_2 -> V_98 ) ;
F_64 ( ! V_2 -> V_33 ) ;
F_64 ( ! V_2 -> V_35 ) ;
F_64 ( ! V_2 -> V_99 ) ;
F_64 ( ! V_2 -> V_54 ) ;
F_64 ( ! V_2 -> V_3 ) ;
if ( F_65 ( V_2 ) )
F_57 ( V_100 , V_2 -> V_26 ) ;
V_19 = F_74 ( sizeof( * V_19 ) , V_83 ) ;
if ( ! V_19 )
return - V_51 ;
V_81 = F_70 ( V_2 ) ;
if ( V_81 != 0 ) {
F_14 ( V_19 ) ;
return V_81 ;
}
F_75 ( V_19 , 0 ) ;
F_46 (chan, &device->channels, device_node) {
V_81 = - V_51 ;
V_6 -> V_14 = F_36 ( F_3 ( * V_6 -> V_14 ) ) ;
if ( V_6 -> V_14 == NULL )
goto V_101;
V_6 -> V_3 = F_76 ( sizeof( * V_6 -> V_3 ) , V_83 ) ;
if ( V_6 -> V_3 == NULL ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
goto V_101;
}
V_6 -> V_102 = V_64 ++ ;
V_6 -> V_3 -> V_2 . V_103 = & V_104 ;
V_6 -> V_3 -> V_2 . V_105 = V_2 -> V_3 ;
V_6 -> V_3 -> V_6 = V_6 ;
V_6 -> V_3 -> V_19 = V_19 ;
V_6 -> V_3 -> V_21 = V_2 -> V_21 ;
F_77 ( V_19 ) ;
F_78 ( & V_6 -> V_3 -> V_2 , L_14 ,
V_2 -> V_21 , V_6 -> V_102 ) ;
V_81 = F_79 ( & V_6 -> V_3 -> V_2 ) ;
if ( V_81 ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_14 ( V_6 -> V_3 ) ;
F_80 ( V_19 ) ;
goto V_101;
}
V_6 -> V_18 = 0 ;
}
V_2 -> V_64 = V_64 ;
F_5 ( & V_13 ) ;
if ( V_31 && ! F_24 ( V_34 , V_2 -> V_26 ) )
F_46 (chan, &device->channels, device_node) {
if ( F_21 ( V_6 ) == - V_16 ) {
V_81 = - V_16 ;
F_8 ( & V_13 ) ;
goto V_101;
}
}
F_81 ( & V_2 -> V_67 , & V_106 ) ;
if ( F_24 ( V_34 , V_2 -> V_26 ) )
V_2 -> V_66 ++ ;
F_49 () ;
F_8 ( & V_13 ) ;
return 0 ;
V_101:
if ( F_82 ( V_19 ) == 0 ) {
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
F_83 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
return V_81 ;
}
void F_84 ( struct V_22 * V_2 )
{
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
F_58 ( & V_2 -> V_67 ) ;
F_49 () ;
F_8 ( & V_13 ) ;
F_46 (chan, &device->channels, device_node) {
F_61 ( V_6 -> V_18 ,
L_15 ,
V_63 , V_6 -> V_18 ) ;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_83 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
}
T_3
F_85 ( struct V_1 * V_6 , void * V_107 ,
void * V_108 , T_7 V_109 )
{
struct V_22 * V_3 = V_6 -> V_2 ;
struct V_110 * V_111 ;
T_8 V_112 , V_113 ;
T_3 V_37 ;
unsigned long V_114 ;
V_113 = F_86 ( V_3 -> V_3 , V_108 , V_109 , V_115 ) ;
V_112 = F_86 ( V_3 -> V_3 , V_107 , V_109 , V_116 ) ;
V_114 = V_117 |
V_118 |
V_119 ;
V_111 = V_3 -> V_85 ( V_6 , V_112 , V_113 , V_109 , V_114 ) ;
if ( ! V_111 ) {
F_87 ( V_3 -> V_3 , V_113 , V_109 , V_115 ) ;
F_87 ( V_3 -> V_3 , V_112 , V_109 , V_116 ) ;
return - V_51 ;
}
V_111 -> V_120 = NULL ;
V_37 = V_111 -> V_121 ( V_111 ) ;
F_88 () ;
F_89 ( V_6 -> V_14 -> V_17 , V_109 ) ;
F_90 ( V_6 -> V_14 -> V_15 ) ;
F_91 () ;
return V_37 ;
}
T_3
F_92 ( struct V_1 * V_6 , struct V_122 * V_122 ,
unsigned int V_123 , void * V_124 , T_7 V_109 )
{
struct V_22 * V_3 = V_6 -> V_2 ;
struct V_110 * V_111 ;
T_8 V_112 , V_113 ;
T_3 V_37 ;
unsigned long V_114 ;
V_113 = F_86 ( V_3 -> V_3 , V_124 , V_109 , V_115 ) ;
V_112 = F_93 ( V_3 -> V_3 , V_122 , V_123 , V_109 , V_116 ) ;
V_114 = V_117 | V_118 ;
V_111 = V_3 -> V_85 ( V_6 , V_112 , V_113 , V_109 , V_114 ) ;
if ( ! V_111 ) {
F_87 ( V_3 -> V_3 , V_113 , V_109 , V_115 ) ;
F_94 ( V_3 -> V_3 , V_112 , V_109 , V_116 ) ;
return - V_51 ;
}
V_111 -> V_120 = NULL ;
V_37 = V_111 -> V_121 ( V_111 ) ;
F_88 () ;
F_89 ( V_6 -> V_14 -> V_17 , V_109 ) ;
F_90 ( V_6 -> V_14 -> V_15 ) ;
F_91 () ;
return V_37 ;
}
T_3
F_95 ( struct V_1 * V_6 , struct V_122 * V_125 ,
unsigned int V_126 , struct V_122 * V_127 , unsigned int V_128 ,
T_7 V_109 )
{
struct V_22 * V_3 = V_6 -> V_2 ;
struct V_110 * V_111 ;
T_8 V_112 , V_113 ;
T_3 V_37 ;
unsigned long V_114 ;
V_113 = F_93 ( V_3 -> V_3 , V_127 , V_128 , V_109 , V_115 ) ;
V_112 = F_93 ( V_3 -> V_3 , V_125 , V_126 , V_109 ,
V_116 ) ;
V_114 = V_117 ;
V_111 = V_3 -> V_85 ( V_6 , V_112 , V_113 , V_109 , V_114 ) ;
if ( ! V_111 ) {
F_94 ( V_3 -> V_3 , V_113 , V_109 , V_115 ) ;
F_94 ( V_3 -> V_3 , V_112 , V_109 , V_116 ) ;
return - V_51 ;
}
V_111 -> V_120 = NULL ;
V_37 = V_111 -> V_121 ( V_111 ) ;
F_88 () ;
F_89 ( V_6 -> V_14 -> V_17 , V_109 ) ;
F_90 ( V_6 -> V_14 -> V_15 ) ;
F_91 () ;
return V_37 ;
}
void F_96 ( struct V_110 * V_111 ,
struct V_1 * V_6 )
{
V_111 -> V_6 = V_6 ;
#ifdef F_97
F_98 ( & V_111 -> V_129 ) ;
#endif
}
enum V_36
F_99 ( struct V_110 * V_111 )
{
unsigned long V_39 = V_40 + F_27 ( 5000 ) ;
if ( ! V_111 )
return V_130 ;
while ( V_111 -> V_37 == - V_131 ) {
if ( F_30 ( V_40 , V_39 ) ) {
F_37 ( L_16 ,
V_63 ) ;
return V_42 ;
}
F_100 () ;
}
return F_26 ( V_111 -> V_6 , V_111 -> V_37 ) ;
}
void F_101 ( struct V_110 * V_111 )
{
struct V_110 * V_132 = F_102 ( V_111 ) ;
struct V_110 * V_133 ;
struct V_1 * V_6 ;
if ( ! V_132 )
return;
F_103 ( V_111 ) ;
V_6 = V_132 -> V_6 ;
for (; V_132 ; V_132 = V_133 ) {
F_104 ( V_132 ) ;
F_105 ( V_132 ) ;
V_133 = F_102 ( V_132 ) ;
if ( V_133 && V_133 -> V_6 == V_6 )
F_103 ( V_132 ) ;
else
V_133 = NULL ;
F_106 ( V_132 ) ;
V_132 -> V_121 ( V_132 ) ;
}
V_6 -> V_2 -> V_54 ( V_6 ) ;
}
static int T_4 F_107 ( void )
{
return F_108 ( & V_104 ) ;
}
