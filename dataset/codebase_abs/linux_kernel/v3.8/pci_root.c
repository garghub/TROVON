int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
F_2 ( & V_6 ) ;
F_3 ( & V_2 -> V_7 , & V_8 ) ;
if ( V_2 -> V_9 )
F_4 (root, &acpi_pci_roots, node) {
V_2 -> V_9 ( V_5 ) ;
V_3 ++ ;
}
F_5 ( & V_6 ) ;
return V_3 ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
F_2 ( & V_6 ) ;
F_7 ( & V_2 -> V_7 ) ;
if ( V_2 -> remove )
F_4 (root, &acpi_pci_roots, node)
V_2 -> remove ( V_5 ) ;
F_5 ( & V_6 ) ;
}
T_1 F_8 ( unsigned int V_10 , unsigned int V_11 )
{
struct V_4 * V_5 ;
T_1 V_12 = NULL ;
F_2 ( & V_6 ) ;
F_4 (root, &acpi_pci_roots, node)
if ( ( V_5 -> V_13 == ( V_14 ) V_10 ) &&
( V_5 -> V_15 . V_16 == ( V_14 ) V_11 ) ) {
V_12 = V_5 -> V_17 -> V_12 ;
break;
}
F_5 ( & V_6 ) ;
return V_12 ;
}
int F_9 ( T_1 V_12 )
{
int V_18 ;
struct V_19 * V_17 ;
V_18 = F_10 ( V_12 , & V_17 ) ;
if ( V_18 )
return 0 ;
V_18 = F_11 ( V_17 , V_20 ) ;
if ( V_18 )
return 0 ;
else
return 1 ;
}
static T_2
F_12 ( struct V_21 * V_22 , void * V_23 )
{
struct V_22 * V_24 = V_23 ;
struct V_25 V_26 ;
if ( V_22 -> type != V_27 &&
V_22 -> type != V_28 &&
V_22 -> type != V_29 )
return V_30 ;
F_13 ( V_22 , & V_26 ) ;
if ( ( V_26 . V_31 > 0 ) &&
( V_26 . V_32 == V_33 ) ) {
V_24 -> V_16 = V_26 . V_34 ;
V_24 -> V_35 = V_26 . V_34 + V_26 . V_31 - 1 ;
}
return V_30 ;
}
static T_2 F_14 ( T_1 V_12 ,
struct V_22 * V_24 )
{
T_2 V_36 ;
V_24 -> V_16 = - 1 ;
V_36 =
F_15 ( V_12 , V_37 ,
F_12 , V_24 ) ;
if ( F_16 ( V_36 ) )
return V_36 ;
if ( V_24 -> V_16 == - 1 )
return V_38 ;
return V_30 ;
}
static void F_17 ( struct V_19 * V_17 )
{
int V_36 ;
struct V_19 * V_39 = NULL ;
if ( V_17 -> V_40 . V_41 )
if ( V_17 -> V_42 && V_17 -> V_42 -> V_43 . V_44 ) {
V_36 = V_17 -> V_42 -> V_43 . V_44 ( V_17 ) ;
if ( ! V_36 ) {
F_4 (child, &device->children, node)
F_17 ( V_39 ) ;
}
}
}
static T_2 F_18 ( T_1 V_12 ,
const T_3 * V_45 , T_3 * V_46 )
{
struct V_47 V_48 = {
. V_49 = V_50 ,
. V_51 = 1 ,
. V_52 . V_53 = 12 ,
. V_52 . V_54 = ( void * ) V_45 ,
} ;
T_2 V_36 ;
V_36 = F_19 ( V_12 , & V_48 ) ;
if ( F_20 ( V_36 ) ) {
* V_46 = * ( ( T_3 * ) ( V_48 . V_18 . V_54 + 8 ) ) ;
F_21 ( V_48 . V_18 . V_54 ) ;
}
return V_36 ;
}
static T_2 F_22 ( struct V_4 * V_5 ,
T_3 V_55 ,
T_3 * V_56 )
{
T_2 V_36 ;
T_3 V_57 , V_45 [ 3 ] ;
V_55 &= V_58 ;
V_55 |= V_5 -> V_59 ;
V_45 [ V_60 ] = V_61 ;
V_45 [ V_62 ] = V_55 ;
if ( V_56 ) {
* V_56 &= V_63 ;
V_45 [ V_64 ] = * V_56 | V_5 -> V_65 ;
} else {
V_45 [ V_64 ] = V_63 ;
}
V_36 = F_18 ( V_5 -> V_17 -> V_12 , V_45 , & V_57 ) ;
if ( F_20 ( V_36 ) ) {
V_5 -> V_59 = V_55 ;
if ( V_56 )
* V_56 = V_57 ;
}
return V_36 ;
}
static T_2 F_23 ( struct V_4 * V_5 , T_3 V_40 )
{
T_2 V_36 ;
T_1 V_66 ;
V_36 = F_24 ( V_5 -> V_17 -> V_12 , L_1 , & V_66 ) ;
if ( F_16 ( V_36 ) )
return V_36 ;
F_2 ( & V_67 ) ;
V_36 = F_22 ( V_5 , V_40 , NULL ) ;
F_5 ( & V_67 ) ;
return V_36 ;
}
struct V_4 * F_25 ( T_1 V_12 )
{
struct V_4 * V_5 ;
struct V_19 * V_17 ;
if ( F_10 ( V_12 , & V_17 ) ||
F_11 ( V_17 , V_20 ) )
return NULL ;
V_5 = F_26 ( V_17 ) ;
return V_5 ;
}
struct V_68 * F_27 ( T_1 V_12 )
{
int V_69 , V_70 ;
unsigned long long V_71 ;
T_2 V_36 ;
T_1 V_72 ;
struct V_73 * V_74 ;
struct V_68 * V_75 = NULL ;
struct V_76 * V_7 , * V_66 ;
struct V_4 * V_5 ;
F_28 ( V_77 ) ;
V_72 = V_12 ;
while ( ! F_9 ( V_72 ) ) {
V_7 = F_29 ( sizeof( struct V_76 ) , V_78 ) ;
if ( ! V_7 )
goto V_79;
F_30 ( & V_7 -> V_7 ) ;
V_7 -> V_12 = V_72 ;
F_31 ( & V_7 -> V_7 , & V_77 ) ;
V_36 = F_32 ( V_72 , & V_72 ) ;
if ( F_16 ( V_36 ) )
goto V_79;
}
V_5 = F_25 ( V_72 ) ;
if ( ! V_5 )
goto V_79;
V_74 = V_5 -> V_11 ;
F_4 (node, &device_list, node) {
T_1 V_80 = V_7 -> V_12 ;
V_36 = F_33 ( V_80 , L_2 , NULL , & V_71 ) ;
if ( F_16 ( V_36 ) )
goto V_79;
V_69 = ( V_71 >> 16 ) & 0xffff ;
V_70 = V_71 & 0xffff ;
V_75 = F_34 ( V_74 , F_35 ( V_69 , V_70 ) ) ;
if ( ! V_75 || V_80 == V_12 )
break;
V_74 = V_75 -> V_81 ;
F_36 ( V_75 ) ;
if ( ! V_74 ) {
F_37 ( & V_75 -> V_69 , L_3 ) ;
V_75 = NULL ;
break;
}
}
V_79:
F_38 (node, tmp, &device_list, node)
F_21 ( V_7 ) ;
return V_75 ;
}
T_2 F_39 ( T_1 V_12 , T_3 * V_82 , T_3 V_83 )
{
struct V_4 * V_5 ;
T_2 V_36 ;
T_3 V_84 , V_45 [ 3 ] ;
T_1 V_66 ;
if ( ! V_82 )
return V_85 ;
V_84 = * V_82 & V_63 ;
if ( ( V_84 & V_83 ) != V_83 )
return V_86 ;
V_5 = F_25 ( V_12 ) ;
if ( ! V_5 )
return V_87 ;
V_36 = F_24 ( V_12 , L_1 , & V_66 ) ;
if ( F_16 ( V_36 ) )
return V_36 ;
F_2 ( & V_67 ) ;
* V_82 = V_84 | V_5 -> V_65 ;
if ( ( V_5 -> V_65 & V_84 ) == V_84 )
goto V_79;
while ( * V_82 ) {
V_36 = F_22 ( V_5 , V_5 -> V_59 , V_82 ) ;
if ( F_16 ( V_36 ) )
goto V_79;
if ( V_84 == * V_82 )
break;
V_84 = * V_82 ;
}
if ( ( V_84 & V_83 ) != V_83 ) {
V_36 = V_88 ;
goto V_79;
}
V_45 [ V_60 ] = 0 ;
V_45 [ V_62 ] = V_5 -> V_59 ;
V_45 [ V_64 ] = V_84 ;
V_36 = F_18 ( V_12 , V_45 , V_82 ) ;
if ( F_20 ( V_36 ) )
V_5 -> V_65 = * V_82 ;
V_79:
F_5 ( & V_67 ) ;
return V_36 ;
}
static int F_40 ( struct V_19 * V_17 )
{
unsigned long long V_13 , V_11 ;
T_2 V_36 ;
int V_57 ;
struct V_4 * V_5 ;
T_1 V_12 ;
struct V_19 * V_39 ;
T_3 V_40 , V_89 ;
bool V_90 = false ;
V_5 = F_29 ( sizeof( struct V_4 ) , V_78 ) ;
if ( ! V_5 )
return - V_91 ;
V_13 = 0 ;
V_36 = F_33 ( V_17 -> V_12 , V_92 , NULL ,
& V_13 ) ;
if ( F_16 ( V_36 ) && V_36 != V_93 ) {
F_41 (KERN_ERR PREFIX L_4 ) ;
V_57 = - V_94 ;
goto V_35;
}
V_5 -> V_15 . V_40 = V_95 ;
V_36 = F_14 ( V_17 -> V_12 , & V_5 -> V_15 ) ;
if ( F_16 ( V_36 ) ) {
V_5 -> V_15 . V_35 = 0xFF ;
F_41 (KERN_WARNING FW_BUG PREFIX
L_5 ) ;
V_36 = F_33 ( V_17 -> V_12 , V_96 ,
NULL , & V_11 ) ;
if ( F_20 ( V_36 ) )
V_5 -> V_15 . V_16 = V_11 ;
else if ( V_36 == V_93 )
V_5 -> V_15 . V_16 = 0 ;
else {
F_41 (KERN_ERR PREFIX L_6 ) ;
V_57 = - V_94 ;
goto V_35;
}
}
F_30 ( & V_5 -> V_7 ) ;
V_5 -> V_17 = V_17 ;
V_5 -> V_13 = V_13 & 0xFFFF ;
strcpy ( F_42 ( V_17 ) , V_97 ) ;
strcpy ( F_43 ( V_17 ) , V_98 ) ;
V_17 -> V_99 = V_5 ;
F_41 (KERN_INFO PREFIX L_7 ,
acpi_device_name(device), acpi_device_bid(device),
root->segment, &root->secondary) ;
V_36 = F_24 ( V_17 -> V_12 , V_100 , & V_12 ) ;
if ( F_20 ( V_36 ) )
V_57 = F_44 ( V_17 -> V_12 , V_5 -> V_13 ,
V_5 -> V_15 . V_16 ) ;
V_5 -> V_101 = F_45 ( V_17 -> V_12 ) ;
V_40 = V_89 = V_102 ;
F_23 ( V_5 , V_40 ) ;
if ( F_46 () )
V_40 |= V_103 ;
if ( F_47 () ) {
V_40 |= V_104 |
V_105 ;
}
if ( F_48 () )
V_40 |= V_106 ;
if ( V_40 != V_89 ) {
V_36 = F_23 ( V_5 , V_40 ) ;
if ( F_16 ( V_36 ) ) {
F_49 ( & V_17 -> V_69 , L_8
L_9 ) ;
F_50 () ;
V_40 = V_89 ;
}
}
if ( ! V_107
&& ( V_40 & V_108 ) == V_108 ) {
V_40 = V_109
| V_110
| V_111 ;
if ( F_51 () ) {
if ( F_52 () )
F_37 ( & V_17 -> V_69 ,
L_10 ) ;
else
V_40 |= V_112 ;
}
F_49 ( & V_17 -> V_69 ,
L_11 , V_40 ) ;
V_36 = F_39 ( V_17 -> V_12 , & V_40 ,
V_109 ) ;
if ( F_20 ( V_36 ) ) {
V_90 = true ;
F_49 ( & V_17 -> V_69 ,
L_12 , V_40 ) ;
} else {
V_90 = false ;
F_49 ( & V_17 -> V_69 ,
L_13
L_14 ,
F_53 ( V_36 ) , V_40 ) ;
}
} else {
F_49 ( & V_17 -> V_69 ,
L_15
L_16 , V_40 ) ;
}
F_2 ( & V_6 ) ;
F_3 ( & V_5 -> V_7 , & V_113 ) ;
F_5 ( & V_6 ) ;
V_5 -> V_11 = F_54 ( V_5 ) ;
if ( ! V_5 -> V_11 ) {
F_41 (KERN_ERR PREFIX
L_17 ,
root->segment, (unsigned int)root->secondary.start) ;
V_57 = - V_94 ;
goto V_114;
}
V_57 = F_55 ( V_17 ) ;
if ( V_57 )
goto V_114;
F_4 (child, &device->children, node)
F_17 ( V_39 ) ;
if ( V_90 ) {
if ( V_115 . V_116 & V_117 )
F_56 ( V_5 -> V_11 ) ;
} else {
F_57 ( L_18
L_19 ) ;
F_50 () ;
}
F_58 ( V_17 , V_5 -> V_11 ) ;
if ( V_17 -> V_118 . V_40 . V_119 )
F_59 ( V_5 -> V_11 -> V_120 , true ) ;
return 0 ;
V_114:
F_2 ( & V_6 ) ;
F_7 ( & V_5 -> V_7 ) ;
F_5 ( & V_6 ) ;
F_60 ( V_5 -> V_13 , V_5 -> V_15 . V_16 ) ;
V_35:
F_21 ( V_5 ) ;
return V_57 ;
}
static int F_61 ( struct V_19 * V_17 )
{
struct V_4 * V_5 = F_26 ( V_17 ) ;
struct V_1 * V_2 ;
if ( V_121 != V_122 )
F_62 ( V_5 -> V_11 ) ;
F_2 ( & V_6 ) ;
F_4 (driver, &acpi_pci_drivers, node)
if ( V_2 -> V_9 )
V_2 -> V_9 ( V_5 ) ;
F_5 ( & V_6 ) ;
if ( V_121 != V_122 )
F_63 ( V_5 -> V_11 ) ;
F_64 ( V_5 -> V_11 ) ;
return 0 ;
}
static int F_65 ( struct V_19 * V_17 , int type )
{
T_2 V_36 ;
T_1 V_12 ;
struct V_4 * V_5 = F_26 ( V_17 ) ;
struct V_1 * V_2 ;
F_66 ( V_5 -> V_11 ) ;
F_2 ( & V_6 ) ;
F_67 (driver, &acpi_pci_drivers, node)
if ( V_2 -> remove )
V_2 -> remove ( V_5 ) ;
F_5 ( & V_6 ) ;
F_59 ( V_5 -> V_11 -> V_120 , false ) ;
F_68 ( V_17 ) ;
V_36 = F_24 ( V_17 -> V_12 , V_100 , & V_12 ) ;
if ( F_20 ( V_36 ) )
F_60 ( V_5 -> V_13 , V_5 -> V_15 . V_16 ) ;
F_69 ( V_5 -> V_11 ) ;
F_2 ( & V_6 ) ;
F_7 ( & V_5 -> V_7 ) ;
F_5 ( & V_6 ) ;
F_21 ( V_5 ) ;
return 0 ;
}
static int T_4 F_70 ( void )
{
F_71 () ;
if ( V_123 )
return 0 ;
F_72 () ;
if ( F_73 ( & V_124 ) < 0 )
return - V_94 ;
return 0 ;
}
