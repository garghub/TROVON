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
static struct V_1 * F_52 ( const T_2 * V_60 ,
struct V_22 * V_3 ,
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
struct V_1 * F_55 ( const T_2 * V_60 ,
T_5 V_61 , void * V_62 )
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
struct V_1 * F_60 ( struct V_2 * V_3 , const char * V_67 )
{
if ( V_3 -> V_68 )
return F_61 ( V_3 -> V_68 , V_67 ) ;
if ( F_62 ( V_3 ) )
return F_63 ( V_3 , V_67 ) ;
return NULL ;
}
void F_64 ( struct V_1 * V_6 )
{
F_5 ( & V_13 ) ;
F_65 ( V_6 -> V_18 != 1 ,
L_13 , V_6 -> V_18 ) ;
F_25 ( V_6 ) ;
if ( -- V_6 -> V_2 -> V_65 == 0 )
F_59 ( V_34 , V_6 -> V_2 -> V_26 ) ;
F_8 ( & V_13 ) ;
}
void F_66 ( void )
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
void F_67 ( void )
{
struct V_22 * V_2 ;
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
V_31 -- ;
F_68 ( V_31 < 0 ) ;
F_46 (device, &dma_device_list, global_node) {
if ( F_24 ( V_34 , V_2 -> V_26 ) )
continue;
F_46 (chan, &device->channels, device_node)
F_25 ( V_6 ) ;
}
F_8 ( & V_13 ) ;
}
static bool F_69 ( struct V_22 * V_2 )
{
#ifdef F_70
if ( ! F_24 ( V_47 , V_2 -> V_26 ) )
return false ;
#endif
#if F_71 ( V_69 ) || F_71 ( V_70 )
if ( ! F_24 ( V_53 , V_2 -> V_26 ) )
return false ;
#endif
#if F_71 ( V_71 ) || F_71 ( V_72 )
if ( ! F_24 ( V_73 , V_2 -> V_26 ) )
return false ;
#ifndef F_72
if ( ! F_24 ( V_74 , V_2 -> V_26 ) )
return false ;
#endif
#endif
#if F_71 ( V_75 ) || F_71 ( V_76 )
if ( ! F_24 ( V_77 , V_2 -> V_26 ) )
return false ;
#ifndef F_73
if ( ! F_24 ( V_78 , V_2 -> V_26 ) )
return false ;
#endif
#endif
return true ;
}
static int F_74 ( struct V_22 * V_2 )
{
int V_79 ;
F_5 ( & V_13 ) ;
V_79 = F_75 ( & V_20 , NULL , 0 , 0 , V_80 ) ;
if ( V_79 >= 0 )
V_2 -> V_21 = V_79 ;
F_8 ( & V_13 ) ;
return V_79 < 0 ? V_79 : 0 ;
}
int F_76 ( struct V_22 * V_2 )
{
int V_63 = 0 , V_79 ;
struct V_1 * V_6 ;
T_6 * V_19 ;
if ( ! V_2 )
return - V_16 ;
F_68 ( F_24 ( V_53 , V_2 -> V_26 ) &&
! V_2 -> V_81 ) ;
F_68 ( F_24 ( V_73 , V_2 -> V_26 ) &&
! V_2 -> V_82 ) ;
F_68 ( F_24 ( V_74 , V_2 -> V_26 ) &&
! V_2 -> V_83 ) ;
F_68 ( F_24 ( V_77 , V_2 -> V_26 ) &&
! V_2 -> V_84 ) ;
F_68 ( F_24 ( V_78 , V_2 -> V_26 ) &&
! V_2 -> V_85 ) ;
F_68 ( F_24 ( V_47 , V_2 -> V_26 ) &&
! V_2 -> V_86 ) ;
F_68 ( F_24 ( V_87 , V_2 -> V_26 ) &&
! V_2 -> V_88 ) ;
F_68 ( F_24 ( V_89 , V_2 -> V_26 ) &&
! V_2 -> V_90 ) ;
F_68 ( F_24 ( V_48 , V_2 -> V_26 ) &&
! V_2 -> V_91 ) ;
F_68 ( F_24 ( V_92 , V_2 -> V_26 ) &&
! V_2 -> V_93 ) ;
F_68 ( ! V_2 -> V_33 ) ;
F_68 ( ! V_2 -> V_35 ) ;
F_68 ( ! V_2 -> V_94 ) ;
F_68 ( ! V_2 -> V_54 ) ;
F_68 ( ! V_2 -> V_3 ) ;
if ( F_69 ( V_2 ) )
F_57 ( V_95 , V_2 -> V_26 ) ;
V_19 = F_77 ( sizeof( * V_19 ) , V_80 ) ;
if ( ! V_19 )
return - V_51 ;
V_79 = F_74 ( V_2 ) ;
if ( V_79 != 0 ) {
F_14 ( V_19 ) ;
return V_79 ;
}
F_78 ( V_19 , 0 ) ;
F_46 (chan, &device->channels, device_node) {
V_79 = - V_51 ;
V_6 -> V_14 = F_37 ( F_3 ( * V_6 -> V_14 ) ) ;
if ( V_6 -> V_14 == NULL )
goto V_96;
V_6 -> V_3 = F_79 ( sizeof( * V_6 -> V_3 ) , V_80 ) ;
if ( V_6 -> V_3 == NULL ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
goto V_96;
}
V_6 -> V_97 = V_63 ++ ;
V_6 -> V_3 -> V_2 . V_98 = & V_99 ;
V_6 -> V_3 -> V_2 . V_100 = V_2 -> V_3 ;
V_6 -> V_3 -> V_6 = V_6 ;
V_6 -> V_3 -> V_19 = V_19 ;
V_6 -> V_3 -> V_21 = V_2 -> V_21 ;
F_80 ( V_19 ) ;
F_81 ( & V_6 -> V_3 -> V_2 , L_14 ,
V_2 -> V_21 , V_6 -> V_97 ) ;
V_79 = F_82 ( & V_6 -> V_3 -> V_2 ) ;
if ( V_79 ) {
F_38 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_14 ( V_6 -> V_3 ) ;
F_83 ( V_19 ) ;
goto V_96;
}
V_6 -> V_18 = 0 ;
}
V_2 -> V_63 = V_63 ;
F_5 ( & V_13 ) ;
if ( V_31 && ! F_24 ( V_34 , V_2 -> V_26 ) )
F_46 (chan, &device->channels, device_node) {
if ( F_21 ( V_6 ) == - V_16 ) {
V_79 = - V_16 ;
F_8 ( & V_13 ) ;
goto V_96;
}
}
F_84 ( & V_2 -> V_66 , & V_101 ) ;
if ( F_24 ( V_34 , V_2 -> V_26 ) )
V_2 -> V_65 ++ ;
F_49 () ;
F_8 ( & V_13 ) ;
return 0 ;
V_96:
if ( F_85 ( V_19 ) == 0 ) {
F_5 ( & V_13 ) ;
F_13 ( & V_20 , V_2 -> V_21 ) ;
F_8 ( & V_13 ) ;
F_14 ( V_19 ) ;
return V_79 ;
}
F_46 (chan, &device->channels, device_node) {
if ( V_6 -> V_14 == NULL )
continue;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_86 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
return V_79 ;
}
void F_87 ( struct V_22 * V_2 )
{
struct V_1 * V_6 ;
F_5 ( & V_13 ) ;
F_58 ( & V_2 -> V_66 ) ;
F_49 () ;
F_8 ( & V_13 ) ;
F_46 (chan, &device->channels, device_node) {
F_65 ( V_6 -> V_18 ,
L_15 ,
V_41 , V_6 -> V_18 ) ;
F_5 ( & V_13 ) ;
V_6 -> V_3 -> V_6 = NULL ;
F_8 ( & V_13 ) ;
F_86 ( & V_6 -> V_3 -> V_2 ) ;
F_38 ( V_6 -> V_14 ) ;
}
}
T_3
F_88 ( struct V_1 * V_6 , void * V_102 ,
void * V_103 , T_7 V_104 )
{
struct V_22 * V_3 = V_6 -> V_2 ;
struct V_105 * V_106 ;
T_8 V_107 , V_108 ;
T_3 V_37 ;
unsigned long V_109 ;
V_108 = F_89 ( V_3 -> V_3 , V_103 , V_104 , V_110 ) ;
V_107 = F_89 ( V_3 -> V_3 , V_102 , V_104 , V_111 ) ;
V_109 = V_112 |
V_113 |
V_114 ;
V_106 = V_3 -> V_81 ( V_6 , V_107 , V_108 , V_104 , V_109 ) ;
if ( ! V_106 ) {
F_90 ( V_3 -> V_3 , V_108 , V_104 , V_110 ) ;
F_90 ( V_3 -> V_3 , V_107 , V_104 , V_111 ) ;
return - V_51 ;
}
V_106 -> V_115 = NULL ;
V_37 = V_106 -> V_116 ( V_106 ) ;
F_91 () ;
F_92 ( V_6 -> V_14 -> V_17 , V_104 ) ;
F_93 ( V_6 -> V_14 -> V_15 ) ;
F_94 () ;
return V_37 ;
}
T_3
F_95 ( struct V_1 * V_6 , struct V_117 * V_117 ,
unsigned int V_118 , void * V_119 , T_7 V_104 )
{
struct V_22 * V_3 = V_6 -> V_2 ;
struct V_105 * V_106 ;
T_8 V_107 , V_108 ;
T_3 V_37 ;
unsigned long V_109 ;
V_108 = F_89 ( V_3 -> V_3 , V_119 , V_104 , V_110 ) ;
V_107 = F_96 ( V_3 -> V_3 , V_117 , V_118 , V_104 , V_111 ) ;
V_109 = V_112 | V_113 ;
V_106 = V_3 -> V_81 ( V_6 , V_107 , V_108 , V_104 , V_109 ) ;
if ( ! V_106 ) {
F_90 ( V_3 -> V_3 , V_108 , V_104 , V_110 ) ;
F_97 ( V_3 -> V_3 , V_107 , V_104 , V_111 ) ;
return - V_51 ;
}
V_106 -> V_115 = NULL ;
V_37 = V_106 -> V_116 ( V_106 ) ;
F_91 () ;
F_92 ( V_6 -> V_14 -> V_17 , V_104 ) ;
F_93 ( V_6 -> V_14 -> V_15 ) ;
F_94 () ;
return V_37 ;
}
T_3
F_98 ( struct V_1 * V_6 , struct V_117 * V_120 ,
unsigned int V_121 , struct V_117 * V_122 , unsigned int V_123 ,
T_7 V_104 )
{
struct V_22 * V_3 = V_6 -> V_2 ;
struct V_105 * V_106 ;
T_8 V_107 , V_108 ;
T_3 V_37 ;
unsigned long V_109 ;
V_108 = F_96 ( V_3 -> V_3 , V_122 , V_123 , V_104 , V_110 ) ;
V_107 = F_96 ( V_3 -> V_3 , V_120 , V_121 , V_104 ,
V_111 ) ;
V_109 = V_112 ;
V_106 = V_3 -> V_81 ( V_6 , V_107 , V_108 , V_104 , V_109 ) ;
if ( ! V_106 ) {
F_97 ( V_3 -> V_3 , V_108 , V_104 , V_110 ) ;
F_97 ( V_3 -> V_3 , V_107 , V_104 , V_111 ) ;
return - V_51 ;
}
V_106 -> V_115 = NULL ;
V_37 = V_106 -> V_116 ( V_106 ) ;
F_91 () ;
F_92 ( V_6 -> V_14 -> V_17 , V_104 ) ;
F_93 ( V_6 -> V_14 -> V_15 ) ;
F_94 () ;
return V_37 ;
}
void F_99 ( struct V_105 * V_106 ,
struct V_1 * V_6 )
{
V_106 -> V_6 = V_6 ;
#ifdef F_100
F_101 ( & V_106 -> V_124 ) ;
#endif
}
enum V_36
F_102 ( struct V_105 * V_106 )
{
unsigned long V_39 = V_40 + F_27 ( 5000 ) ;
if ( ! V_106 )
return V_125 ;
while ( V_106 -> V_37 == - V_126 ) {
if ( F_30 ( V_40 , V_39 ) ) {
F_31 ( L_16 ,
V_41 ) ;
return V_42 ;
}
F_32 () ;
}
return F_26 ( V_106 -> V_6 , V_106 -> V_37 ) ;
}
void F_103 ( struct V_105 * V_106 )
{
struct V_105 * V_127 = F_104 ( V_106 ) ;
struct V_105 * V_128 ;
struct V_1 * V_6 ;
if ( ! V_127 )
return;
F_105 ( V_106 ) ;
V_6 = V_127 -> V_6 ;
for (; V_127 ; V_127 = V_128 ) {
F_106 ( V_127 ) ;
F_107 ( V_127 ) ;
V_128 = F_104 ( V_127 ) ;
if ( V_128 && V_128 -> V_6 == V_6 )
F_105 ( V_127 ) ;
else
V_128 = NULL ;
F_108 ( V_127 ) ;
V_127 -> V_116 ( V_127 ) ;
}
V_6 -> V_2 -> V_54 ( V_6 ) ;
}
static int T_4 F_109 ( void )
{
return F_110 ( & V_99 ) ;
}
