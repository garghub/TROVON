int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_5 ;
struct V_1 * * V_6 = & V_7 ;
while ( * V_6 )
V_6 = & ( * V_6 ) -> V_8 ;
* V_6 = V_2 ;
if ( ! V_2 -> V_9 )
return 0 ;
F_2 (root, &acpi_pci_roots, node) {
V_2 -> V_9 ( V_5 -> V_10 -> V_11 ) ;
V_3 ++ ;
}
return V_3 ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
struct V_1 * * V_6 = & V_7 ;
while ( * V_6 ) {
if ( * V_6 == V_2 )
break;
V_6 = & ( * V_6 ) -> V_8 ;
}
F_4 ( ! * V_6 ) ;
* V_6 = ( * V_6 ) -> V_8 ;
if ( ! V_2 -> remove )
return;
F_2 (root, &acpi_pci_roots, node)
V_2 -> remove ( V_5 -> V_10 -> V_11 ) ;
}
T_1 F_5 ( unsigned int V_12 , unsigned int V_13 )
{
struct V_4 * V_5 ;
F_2 (root, &acpi_pci_roots, node)
if ( ( V_5 -> V_14 == ( V_15 ) V_12 ) &&
( V_5 -> V_16 . V_17 == ( V_15 ) V_13 ) )
return V_5 -> V_10 -> V_11 ;
return NULL ;
}
int F_6 ( T_1 V_11 )
{
int V_18 ;
struct V_19 * V_10 ;
V_18 = F_7 ( V_11 , & V_10 ) ;
if ( V_18 )
return 0 ;
V_18 = F_8 ( V_10 , V_20 ) ;
if ( V_18 )
return 0 ;
else
return 1 ;
}
static T_2
F_9 ( struct V_21 * V_22 , void * V_23 )
{
struct V_22 * V_24 = V_23 ;
struct V_25 V_26 ;
if ( V_22 -> type != V_27 &&
V_22 -> type != V_28 &&
V_22 -> type != V_29 )
return V_30 ;
F_10 ( V_22 , & V_26 ) ;
if ( ( V_26 . V_31 > 0 ) &&
( V_26 . V_32 == V_33 ) ) {
V_24 -> V_17 = V_26 . V_34 ;
V_24 -> V_35 = V_26 . V_34 + V_26 . V_31 - 1 ;
}
return V_30 ;
}
static T_2 F_11 ( T_1 V_11 ,
struct V_22 * V_24 )
{
T_2 V_36 ;
V_24 -> V_17 = - 1 ;
V_36 =
F_12 ( V_11 , V_37 ,
F_9 , V_24 ) ;
if ( F_13 ( V_36 ) )
return V_36 ;
if ( V_24 -> V_17 == - 1 )
return V_38 ;
return V_30 ;
}
static void F_14 ( struct V_19 * V_10 )
{
int V_36 ;
struct V_19 * V_39 = NULL ;
if ( V_10 -> V_40 . V_41 )
if ( V_10 -> V_42 && V_10 -> V_42 -> V_43 . V_44 ) {
V_36 = V_10 -> V_42 -> V_43 . V_44 ( V_10 ) ;
if ( ! V_36 ) {
F_2 (child, &device->children, node)
F_14 ( V_39 ) ;
}
}
}
static T_2 F_15 ( T_1 V_11 ,
const T_3 * V_45 , T_3 * V_46 )
{
struct V_47 V_48 = {
. V_49 = V_50 ,
. V_51 = 1 ,
. V_52 . V_53 = 12 ,
. V_52 . V_54 = ( void * ) V_45 ,
} ;
T_2 V_36 ;
V_36 = F_16 ( V_11 , & V_48 ) ;
if ( F_17 ( V_36 ) ) {
* V_46 = * ( ( T_3 * ) ( V_48 . V_18 . V_54 + 8 ) ) ;
F_18 ( V_48 . V_18 . V_54 ) ;
}
return V_36 ;
}
static T_2 F_19 ( struct V_4 * V_5 ,
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
V_36 = F_15 ( V_5 -> V_10 -> V_11 , V_45 , & V_57 ) ;
if ( F_17 ( V_36 ) ) {
V_5 -> V_59 = V_55 ;
if ( V_56 )
* V_56 = V_57 ;
}
return V_36 ;
}
static T_2 F_20 ( struct V_4 * V_5 , T_3 V_40 )
{
T_2 V_36 ;
T_1 V_66 ;
V_36 = F_21 ( V_5 -> V_10 -> V_11 , L_1 , & V_66 ) ;
if ( F_13 ( V_36 ) )
return V_36 ;
F_22 ( & V_67 ) ;
V_36 = F_19 ( V_5 , V_40 , NULL ) ;
F_23 ( & V_67 ) ;
return V_36 ;
}
struct V_4 * F_24 ( T_1 V_11 )
{
struct V_4 * V_5 ;
F_2 (root, &acpi_pci_roots, node) {
if ( V_5 -> V_10 -> V_11 == V_11 )
return V_5 ;
}
return NULL ;
}
struct V_68 * F_25 ( T_1 V_11 )
{
int V_69 , V_70 ;
unsigned long long V_71 ;
T_2 V_36 ;
T_1 V_72 ;
struct V_73 * V_74 ;
struct V_68 * V_75 = NULL ;
struct V_76 * V_77 , * V_66 ;
struct V_4 * V_5 ;
F_26 ( V_78 ) ;
V_72 = V_11 ;
while ( ! F_6 ( V_72 ) ) {
V_77 = F_27 ( sizeof( struct V_76 ) , V_79 ) ;
if ( ! V_77 )
goto V_80;
F_28 ( & V_77 -> V_77 ) ;
V_77 -> V_11 = V_72 ;
F_29 ( & V_77 -> V_77 , & V_78 ) ;
V_36 = F_30 ( V_72 , & V_72 ) ;
if ( F_13 ( V_36 ) )
goto V_80;
}
V_5 = F_24 ( V_72 ) ;
if ( ! V_5 )
goto V_80;
V_74 = V_5 -> V_13 ;
F_2 (node, &device_list, node) {
T_1 V_81 = V_77 -> V_11 ;
V_36 = F_31 ( V_81 , L_2 , NULL , & V_71 ) ;
if ( F_13 ( V_36 ) )
goto V_80;
V_69 = ( V_71 >> 16 ) & 0xffff ;
V_70 = V_71 & 0xffff ;
V_75 = F_32 ( V_74 , F_33 ( V_69 , V_70 ) ) ;
if ( ! V_75 || V_81 == V_11 )
break;
V_74 = V_75 -> V_82 ;
F_34 ( V_75 ) ;
if ( ! V_74 ) {
F_35 ( & V_75 -> V_69 , L_3 ) ;
V_75 = NULL ;
break;
}
}
V_80:
F_36 (node, tmp, &device_list, node)
F_18 ( V_77 ) ;
return V_75 ;
}
T_2 F_37 ( T_1 V_11 , T_3 * V_83 , T_3 V_84 )
{
struct V_4 * V_5 ;
T_2 V_36 ;
T_3 V_85 , V_45 [ 3 ] ;
T_1 V_66 ;
if ( ! V_83 )
return V_86 ;
V_85 = * V_83 & V_63 ;
if ( ( V_85 & V_84 ) != V_84 )
return V_87 ;
V_5 = F_24 ( V_11 ) ;
if ( ! V_5 )
return V_88 ;
V_36 = F_21 ( V_11 , L_1 , & V_66 ) ;
if ( F_13 ( V_36 ) )
return V_36 ;
F_22 ( & V_67 ) ;
* V_83 = V_85 | V_5 -> V_65 ;
if ( ( V_5 -> V_65 & V_85 ) == V_85 )
goto V_80;
while ( * V_83 ) {
V_36 = F_19 ( V_5 , V_5 -> V_59 , V_83 ) ;
if ( F_13 ( V_36 ) )
goto V_80;
if ( V_85 == * V_83 )
break;
V_85 = * V_83 ;
}
if ( ( V_85 & V_84 ) != V_84 ) {
V_36 = V_89 ;
goto V_80;
}
V_45 [ V_60 ] = 0 ;
V_45 [ V_62 ] = V_5 -> V_59 ;
V_45 [ V_64 ] = V_85 ;
V_36 = F_15 ( V_11 , V_45 , V_83 ) ;
if ( F_17 ( V_36 ) )
V_5 -> V_65 = * V_83 ;
V_80:
F_23 ( & V_67 ) ;
return V_36 ;
}
static int T_4 F_38 ( struct V_19 * V_10 )
{
unsigned long long V_14 , V_13 ;
T_2 V_36 ;
int V_57 ;
struct V_4 * V_5 ;
T_1 V_11 ;
struct V_19 * V_39 ;
T_3 V_40 , V_90 ;
V_5 = F_27 ( sizeof( struct V_4 ) , V_79 ) ;
if ( ! V_5 )
return - V_91 ;
V_14 = 0 ;
V_36 = F_31 ( V_10 -> V_11 , V_92 , NULL ,
& V_14 ) ;
if ( F_13 ( V_36 ) && V_36 != V_93 ) {
F_39 (KERN_ERR PREFIX L_4 ) ;
V_57 = - V_94 ;
goto V_35;
}
V_5 -> V_16 . V_40 = V_95 ;
V_36 = F_11 ( V_10 -> V_11 , & V_5 -> V_16 ) ;
if ( F_13 ( V_36 ) ) {
V_5 -> V_16 . V_35 = 0xFF ;
F_39 (KERN_WARNING FW_BUG PREFIX
L_5 ) ;
V_36 = F_31 ( V_10 -> V_11 , V_96 , NULL , & V_13 ) ;
if ( F_17 ( V_36 ) )
V_5 -> V_16 . V_17 = V_13 ;
else if ( V_36 == V_93 )
V_5 -> V_16 . V_17 = 0 ;
else {
F_39 (KERN_ERR PREFIX L_6 ) ;
V_57 = - V_94 ;
goto V_35;
}
}
F_28 ( & V_5 -> V_77 ) ;
V_5 -> V_10 = V_10 ;
V_5 -> V_14 = V_14 & 0xFFFF ;
strcpy ( F_40 ( V_10 ) , V_97 ) ;
strcpy ( F_41 ( V_10 ) , V_98 ) ;
V_10 -> V_99 = V_5 ;
V_40 = V_90 = V_100 ;
F_20 ( V_5 , V_40 ) ;
F_42 ( & V_5 -> V_77 , & V_101 ) ;
F_39 (KERN_INFO PREFIX L_7 ,
acpi_device_name(device), acpi_device_bid(device),
root->segment, &root->secondary) ;
V_5 -> V_13 = F_43 ( V_5 ) ;
if ( ! V_5 -> V_13 ) {
F_39 (KERN_ERR PREFIX
L_8 ,
root->segment, (unsigned int)root->secondary.start) ;
V_57 = - V_94 ;
goto V_35;
}
V_57 = F_44 ( V_10 ) ;
if ( V_57 )
goto V_35;
V_36 = F_21 ( V_10 -> V_11 , V_102 , & V_11 ) ;
if ( F_17 ( V_36 ) )
V_57 = F_45 ( V_10 -> V_11 , V_5 -> V_13 ) ;
F_2 (child, &device->children, node)
F_14 ( V_39 ) ;
if ( F_46 ( V_5 -> V_13 -> V_103 ) )
V_40 |= V_104 ;
if ( F_47 () )
V_40 |= V_105 |
V_106 ;
if ( F_48 () )
V_40 |= V_107 ;
if ( V_40 != V_90 )
F_20 ( V_5 , V_40 ) ;
if ( ! V_108
&& ( V_40 & V_109 ) == V_109 ) {
V_40 = V_110
| V_111
| V_112 ;
if ( F_49 () ) {
if ( F_50 () )
F_35 ( V_5 -> V_13 -> V_113 ,
L_9 ) ;
else
V_40 |= V_114 ;
}
F_51 ( V_5 -> V_13 -> V_113 ,
L_10 , V_40 ) ;
V_36 = F_37 ( V_10 -> V_11 , & V_40 ,
V_110 ) ;
if ( F_17 ( V_36 ) ) {
F_51 ( V_5 -> V_13 -> V_113 ,
L_11 , V_40 ) ;
} else {
F_51 ( V_5 -> V_13 -> V_113 ,
L_12
L_13 ,
F_52 ( V_36 ) , V_40 ) ;
F_53 ( L_14
L_15 ) ;
F_54 () ;
}
} else {
F_51 ( V_5 -> V_13 -> V_113 ,
L_16
L_17 , V_40 ) ;
}
F_55 ( V_10 , V_5 -> V_13 ) ;
if ( V_10 -> V_115 . V_40 . V_116 )
F_56 ( V_5 -> V_13 -> V_113 , true ) ;
return 0 ;
V_35:
if ( ! F_57 ( & V_5 -> V_77 ) )
F_58 ( & V_5 -> V_77 ) ;
F_18 ( V_5 ) ;
return V_57 ;
}
static int F_59 ( struct V_19 * V_10 )
{
struct V_4 * V_5 = F_60 ( V_10 ) ;
F_61 ( V_5 -> V_13 ) ;
return 0 ;
}
static int F_62 ( struct V_19 * V_10 , int type )
{
struct V_4 * V_5 = F_60 ( V_10 ) ;
F_56 ( V_5 -> V_13 -> V_113 , false ) ;
F_63 ( V_10 ) ;
F_18 ( V_5 ) ;
return 0 ;
}
static int T_5 F_64 ( void )
{
F_65 () ;
if ( V_117 )
return 0 ;
F_66 () ;
if ( F_67 ( & V_118 ) < 0 )
return - V_94 ;
return 0 ;
}
