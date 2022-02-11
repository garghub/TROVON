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
void F_41 ( void )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
F_42 () ;
F_43 (device, &dma_device_list, global_node) {
if ( F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_44 (chan, &device->channels, device_node)
if ( V_6 -> V_18 )
V_2 -> V_53 ( V_6 ) ;
}
F_45 () ;
}
static struct V_1 * F_46 ( enum V_44 V_45 , int V_54 )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
struct V_1 * V_55 = NULL ;
struct V_1 * V_56 = NULL ;
F_44 (device, &dma_device_list, global_node) {
if ( ! F_24 ( V_45 , V_2 -> V_26 ) ||
F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_44 (chan, &device->channels, device_node) {
if ( ! V_6 -> V_18 )
continue;
if ( ! V_56 )
V_56 = V_6 ;
else if ( V_6 -> V_57 < V_56 -> V_57 )
V_56 = V_6 ;
if ( V_54 -- == 0 ) {
V_55 = V_6 ;
break;
}
}
if ( V_55 )
break;
}
if ( ! V_55 )
V_55 = V_56 ;
if ( V_55 )
V_55 -> V_57 ++ ;
return V_55 ;
}
static void F_47 ( void )
{
struct V_1 * V_6 ;
struct V_22 * V_2 ;
int V_58 ;
int V_45 ;
int V_54 ;
F_35 (cap, dma_cap_mask_all)
F_6 (cpu)
F_7 ( V_49 [ V_45 ] , V_58 ) -> V_6 = NULL ;
F_44 (device, &dma_device_list, global_node) {
if ( F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_44 (chan, &device->channels, device_node)
V_6 -> V_57 = 0 ;
}
if ( ! V_31 )
return;
V_54 = 0 ;
F_35 (cap, dma_cap_mask_all)
F_48 (cpu) {
if ( F_49 () > 1 )
V_6 = F_46 ( V_45 , V_54 ++ ) ;
else
V_6 = F_46 ( V_45 , - 1 ) ;
F_7 ( V_49 [ V_45 ] , V_58 ) -> V_6 = V_6 ;
}
}
static struct V_1 * F_50 ( T_2 * V_59 , struct V_22 * V_3 ,
T_5 V_60 , void * V_61 )
{
struct V_1 * V_6 ;
if ( ! F_15 ( V_3 , V_59 ) ) {
F_51 ( L_5 , V_62 ) ;
return NULL ;
}
if ( V_3 -> V_63 > 1 && ! F_24 ( V_34 , V_3 -> V_26 ) )
F_44 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 )
return NULL ;
}
F_44 (chan, &dev->channels, device_node) {
if ( V_6 -> V_18 ) {
F_51 ( L_6 ,
V_62 , F_52 ( V_6 ) ) ;
continue;
}
if ( V_60 && ! V_60 ( V_6 , V_61 ) ) {
F_51 ( L_7 ,
V_62 , F_52 ( V_6 ) ) ;
continue;
}
return V_6 ;
}
return NULL ;
}
struct V_1 * F_53 ( T_2 * V_59 , T_5 V_60 , void * V_61 )
{
struct V_22 * V_2 , * V_64 ;
struct V_1 * V_6 = NULL ;
int V_12 ;
F_5 ( & V_13 ) ;
F_54 (device, _d, &dma_device_list, global_node) {
V_6 = F_50 ( V_59 , V_2 , V_60 , V_61 ) ;
if ( V_6 ) {
F_55 ( V_34 , V_2 -> V_26 ) ;
V_2 -> V_65 ++ ;
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_51 ( L_8 , V_62 ,
F_52 ( V_6 ) ) ;
F_56 ( & V_2 -> V_66 ) ;
} else if ( V_12 )
F_51 ( L_9 ,
F_52 ( V_6 ) , V_12 ) ;
else
break;
if ( -- V_2 -> V_65 == 0 )
F_57 ( V_34 , V_2 -> V_26 ) ;
V_6 = NULL ;
}
}
F_8 ( & V_13 ) ;
F_51 ( L_10 , V_62 , V_6 ? L_11 : L_12 ,
V_6 ? F_52 ( V_6 ) : NULL ) ;
return V_6 ;
}
void F_58 ( struct V_1 * V_6 )
{
F_5 ( & V_13 ) ;
F_59 ( V_6 -> V_18 != 1 ,
L_13 , V_6 -> V_18 ) ;
F_25 ( V_6 ) ;
if ( -- V_6 -> V_2 -> V_65 == 0 )
F_57 ( V_34 , V_6 -> V_2 -> V_26 ) ;
F_8 ( & V_13 ) ;
}
void F_60 ( void )
{
struct V_22 * V_2 , * V_64 ;
struct V_1 * V_6 ;
int V_12 ;
F_5 ( & V_13 ) ;
V_31 ++ ;
F_54 (device, _d, &dma_device_list, global_node) {
if ( F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_44 (chan, &device->channels, device_node) {
V_12 = F_21 ( V_6 ) ;
if ( V_12 == - V_16 ) {
F_56 ( & V_2 -> V_66 ) ;
break;
} else if ( V_12 )
F_37 ( L_9 ,
F_52 ( V_6 ) , V_12 ) ;
}
}
if ( V_31 == 1 )
F_47 () ;
F_8 ( & V_13 ) ;
}
void F_61 ( void )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
V_31 -- ;
F_62 ( V_31 < 0 ) ;
F_44 (device, &dma_device_list, global_node) {
if ( F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_44 (chan, &device->channels, device_node)
F_25 ( V_6 ) ;
}
F_8 ( & V_13 ) ;
}
static bool F_63 ( struct V_22 * V_2 )
{
#ifdef F_64
if ( ! F_24 ( V_47 , V_2 -> V_26 ) )
return false ;
#endif
#if F_65 ( V_67 ) || F_65 ( V_68 )
if ( ! F_24 ( V_69 , V_2 -> V_26 ) )
return false ;
#endif
#if F_65 ( V_70 ) || F_65 ( V_71 )
if ( ! F_24 ( V_72 , V_2 -> V_26 ) )
return false ;
#endif
#if F_65 ( V_73 ) || F_65 ( V_74 )
if ( ! F_24 ( V_75 , V_2 -> V_26 ) )
return false ;
#ifndef F_66
if ( ! F_24 ( V_76 , V_2 -> V_26 ) )
return false ;
#endif
#endif
#if F_65 ( V_77 ) || F_65 ( V_78 )
if ( ! F_24 ( V_79 , V_2 -> V_26 ) )
return false ;
#ifndef F_67
if ( ! F_24 ( V_80 , V_2 -> V_26 ) )
return false ;
#endif
#endif
return true ;
}
static int F_68 ( struct V_22 * V_2 )
{
int V_81 ;
V_82:
if ( ! F_69 ( & V_20 , V_83 ) )
return - V_51 ;
F_5 ( & V_13 ) ;
V_81 = F_70 ( & V_20 , NULL , & V_2 -> V_21 ) ;
F_8 ( & V_13 ) ;
if ( V_81 == - V_84 )
goto V_82;
else if ( V_81 != 0 )
return V_81 ;
return 0 ;
}
int F_71 ( struct V_22 * V_2 )
{
int V_63 = 0 , V_81 ;
struct V_1 * V_6 ;
T_6 * V_19 ;
if ( ! V_2 )
return - V_16 ;
F_62 ( F_24 ( V_69 , V_2 -> V_26 ) &&
! V_2 -> V_85 ) ;
F_62 ( F_24 ( V_75 , V_2 -> V_26 ) &&
! V_2 -> V_86 ) ;
F_62 ( F_24 ( V_76 , V_2 -> V_26 ) &&
! V_2 -> V_87 ) ;
F_62 ( F_24 ( V_79 , V_2 -> V_26 ) &&
! V_2 -> V_88 ) ;
F_62 ( F_24 ( V_80 , V_2 -> V_26 ) &&
! V_2 -> V_89 ) ;
F_62 ( F_24 ( V_72 , V_2 -> V_26 ) &&
! V_2 -> V_90 ) ;
F_62 ( F_24 ( V_47 , V_2 -> V_26 ) &&
! V_2 -> V_91 ) ;
F_62 ( F_24 ( V_92 , V_2 -> V_26 ) &&
! V_2 -> V_93 ) ;
F_62 ( F_24 ( V_94 , V_2 -> V_26 ) &&
! V_2 -> V_95 ) ;
F_62 ( F_24 ( V_48 , V_2 -> V_26 ) &&
! V_2 -> V_96 ) ;
F_62 ( F_24 ( V_97 , V_2 -> V_26 ) &&
! V_2 -> V_98 ) ;
F_62 ( ! V_2 -> V_33 ) ;
F_62 ( ! V_2 -> V_35 ) ;
F_62 ( ! V_2 -> V_99 ) ;
F_62 ( ! V_2 -> V_53 ) ;
F_62 ( ! V_2 -> V_3 ) ;
if ( F_63 ( V_2 ) )
F_55 ( V_100 , V_2 -> V_26 ) ;
V_19 = F_72 ( sizeof( * V_19 ) , V_83 ) ;
if ( ! V_19 )
return - V_51 ;
V_81 = F_68 ( V_2 ) ;
if ( V_81 != 0 ) {
F_14 ( V_19 ) ;
return V_81 ;
}
F_73 ( V_19 , 0 ) ;
F_44 (chan, &device->channels, device_node) {
V_81 = - V_51 ;
V_6 -> V_14 = F_36 ( F_3 ( * V_6 -> V_14 ) ) ;
if ( V_6 -> V_14 == NULL )
goto V_101;
V_6 -> V_3 = F_74 ( sizeof( * V_6 -> V_3 ) , V_83 ) ;
if ( V_6 -> V_3 == NULL ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
goto V_101;
}
V_6 -> V_102 = V_63 ++ ;
V_6 -> V_3 -> V_2 . V_103 = & V_104 ;
V_6 -> V_3 -> V_2 . V_105 = V_2 -> V_3 ;
V_6 -> V_3 -> V_6 = V_6 ;
V_6 -> V_3 -> V_19 = V_19 ;
V_6 -> V_3 -> V_21 = V_2 -> V_21 ;
F_75 ( V_19 ) ;
F_76 ( & V_6 -> V_3 -> V_2 , L_14 ,
V_2 -> V_21 , V_6 -> V_102 ) ;
V_81 = F_77 ( & V_6 -> V_3 -> V_2 ) ;
if ( V_81 ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_14 ( V_6 -> V_3 ) ;
F_78 ( V_19 ) ;
goto V_101;
}
V_6 -> V_18 = 0 ;
}
V_2 -> V_63 = V_63 ;
F_5 ( & V_13 ) ;
if ( V_31 && ! F_24 ( V_34 , V_2 -> V_26 ) )
F_44 (chan, &device->channels, device_node) {
if ( F_21 ( V_6 ) == - V_16 ) {
V_81 = - V_16 ;
F_8 ( & V_13 ) ;
goto V_101;
}
}
F_79 ( & V_2 -> V_66 , & V_106 ) ;
if ( F_24 ( V_34 , V_2 -> V_26 ) )
V_2 -> V_65 ++ ;
F_47 () ;
F_8 ( & V_13 ) ;
return 0 ;
V_101:
if ( F_80 ( V_19 ) == 0 ) {
F_5 ( & V_13 ) ;
F_13 ( & V_20 , V_2 -> V_21 ) ;
F_8 ( & V_13 ) ;
F_14 ( V_19 ) ;
return V_81 ;
}
F_44 (chan, &device->channels, device_node) {
if ( V_6 -> V_14 == NULL )
continue;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_81 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
return V_81 ;
}
void F_82 ( struct V_22 * V_2 )
{
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
F_56 ( & V_2 -> V_66 ) ;
F_47 () ;
F_8 ( & V_13 ) ;
F_44 (chan, &device->channels, device_node) {
F_59 ( V_6 -> V_18 ,
L_15 ,
V_62 , V_6 -> V_18 ) ;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_81 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
}
T_3
F_83 ( struct V_1 * V_6 , void * V_107 ,
void * V_108 , T_7 V_109 )
{
struct V_22 * V_3 = V_6 -> V_2 ;
struct V_110 * V_111 ;
T_8 V_112 , V_113 ;
T_3 V_37 ;
unsigned long V_114 ;
V_113 = F_84 ( V_3 -> V_3 , V_108 , V_109 , V_115 ) ;
V_112 = F_84 ( V_3 -> V_3 , V_107 , V_109 , V_116 ) ;
V_114 = V_117 |
V_118 |
V_119 ;
V_111 = V_3 -> V_85 ( V_6 , V_112 , V_113 , V_109 , V_114 ) ;
if ( ! V_111 ) {
F_85 ( V_3 -> V_3 , V_113 , V_109 , V_115 ) ;
F_85 ( V_3 -> V_3 , V_112 , V_109 , V_116 ) ;
return - V_51 ;
}
V_111 -> V_120 = NULL ;
V_37 = V_111 -> V_121 ( V_111 ) ;
F_86 () ;
F_87 ( V_6 -> V_14 -> V_17 , V_109 ) ;
F_88 ( V_6 -> V_14 -> V_15 ) ;
F_89 () ;
return V_37 ;
}
T_3
F_90 ( struct V_1 * V_6 , struct V_122 * V_122 ,
unsigned int V_123 , void * V_124 , T_7 V_109 )
{
struct V_22 * V_3 = V_6 -> V_2 ;
struct V_110 * V_111 ;
T_8 V_112 , V_113 ;
T_3 V_37 ;
unsigned long V_114 ;
V_113 = F_84 ( V_3 -> V_3 , V_124 , V_109 , V_115 ) ;
V_112 = F_91 ( V_3 -> V_3 , V_122 , V_123 , V_109 , V_116 ) ;
V_114 = V_117 | V_118 ;
V_111 = V_3 -> V_85 ( V_6 , V_112 , V_113 , V_109 , V_114 ) ;
if ( ! V_111 ) {
F_85 ( V_3 -> V_3 , V_113 , V_109 , V_115 ) ;
F_92 ( V_3 -> V_3 , V_112 , V_109 , V_116 ) ;
return - V_51 ;
}
V_111 -> V_120 = NULL ;
V_37 = V_111 -> V_121 ( V_111 ) ;
F_86 () ;
F_87 ( V_6 -> V_14 -> V_17 , V_109 ) ;
F_88 ( V_6 -> V_14 -> V_15 ) ;
F_89 () ;
return V_37 ;
}
T_3
F_93 ( struct V_1 * V_6 , struct V_122 * V_125 ,
unsigned int V_126 , struct V_122 * V_127 , unsigned int V_128 ,
T_7 V_109 )
{
struct V_22 * V_3 = V_6 -> V_2 ;
struct V_110 * V_111 ;
T_8 V_112 , V_113 ;
T_3 V_37 ;
unsigned long V_114 ;
V_113 = F_91 ( V_3 -> V_3 , V_127 , V_128 , V_109 , V_115 ) ;
V_112 = F_91 ( V_3 -> V_3 , V_125 , V_126 , V_109 ,
V_116 ) ;
V_114 = V_117 ;
V_111 = V_3 -> V_85 ( V_6 , V_112 , V_113 , V_109 , V_114 ) ;
if ( ! V_111 ) {
F_92 ( V_3 -> V_3 , V_113 , V_109 , V_115 ) ;
F_92 ( V_3 -> V_3 , V_112 , V_109 , V_116 ) ;
return - V_51 ;
}
V_111 -> V_120 = NULL ;
V_37 = V_111 -> V_121 ( V_111 ) ;
F_86 () ;
F_87 ( V_6 -> V_14 -> V_17 , V_109 ) ;
F_88 ( V_6 -> V_14 -> V_15 ) ;
F_89 () ;
return V_37 ;
}
void F_94 ( struct V_110 * V_111 ,
struct V_1 * V_6 )
{
V_111 -> V_6 = V_6 ;
#ifdef F_95
F_96 ( & V_111 -> V_129 ) ;
#endif
}
enum V_36
F_97 ( struct V_110 * V_111 )
{
unsigned long V_39 = V_40 + F_27 ( 5000 ) ;
if ( ! V_111 )
return V_130 ;
while ( V_111 -> V_37 == - V_131 ) {
if ( F_30 ( V_40 , V_39 ) ) {
F_37 ( L_16 ,
V_62 ) ;
return V_42 ;
}
F_98 () ;
}
return F_26 ( V_111 -> V_6 , V_111 -> V_37 ) ;
}
void F_99 ( struct V_110 * V_111 )
{
struct V_110 * V_132 = F_100 ( V_111 ) ;
struct V_110 * V_133 ;
struct V_1 * V_6 ;
if ( ! V_132 )
return;
F_101 ( V_111 ) ;
V_6 = V_132 -> V_6 ;
for (; V_132 ; V_132 = V_133 ) {
F_102 ( V_132 ) ;
F_103 ( V_132 ) ;
V_133 = F_100 ( V_132 ) ;
if ( V_133 && V_133 -> V_6 == V_6 )
F_101 ( V_132 ) ;
else
V_133 = NULL ;
F_104 ( V_132 ) ;
V_132 -> V_121 ( V_132 ) ;
}
V_6 -> V_2 -> V_53 ( V_6 ) ;
}
static int T_4 F_105 ( void )
{
return F_106 ( & V_104 ) ;
}
