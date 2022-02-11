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
int F_8 ( T_1 V_10 )
{
int V_11 ;
struct V_12 * V_13 ;
V_11 = F_9 ( V_10 , & V_13 ) ;
if ( V_11 )
return 0 ;
V_11 = F_10 ( V_13 , V_14 ) ;
if ( V_11 )
return 0 ;
else
return 1 ;
}
static T_2
F_11 ( struct V_15 * V_16 , void * V_17 )
{
struct V_16 * V_18 = V_17 ;
struct V_19 V_20 ;
if ( V_16 -> type != V_21 &&
V_16 -> type != V_22 &&
V_16 -> type != V_23 )
return V_24 ;
F_12 ( V_16 , & V_20 ) ;
if ( ( V_20 . V_25 > 0 ) &&
( V_20 . V_26 == V_27 ) ) {
V_18 -> V_28 = V_20 . V_29 ;
V_18 -> V_30 = V_20 . V_29 + V_20 . V_25 - 1 ;
}
return V_24 ;
}
static T_2 F_13 ( T_1 V_10 ,
struct V_16 * V_18 )
{
T_2 V_31 ;
V_18 -> V_28 = - 1 ;
V_31 =
F_14 ( V_10 , V_32 ,
F_11 , V_18 ) ;
if ( F_15 ( V_31 ) )
return V_31 ;
if ( V_18 -> V_28 == - 1 )
return V_33 ;
return V_24 ;
}
static T_2 F_16 ( T_1 V_10 ,
const T_3 * V_34 , T_3 * V_35 )
{
struct V_36 V_37 = {
. V_38 = V_39 ,
. V_40 = 1 ,
. V_41 . V_42 = 12 ,
. V_41 . V_43 = ( void * ) V_34 ,
} ;
T_2 V_31 ;
V_31 = F_17 ( V_10 , & V_37 ) ;
if ( F_18 ( V_31 ) ) {
* V_35 = * ( ( T_3 * ) ( V_37 . V_11 . V_43 + 8 ) ) ;
F_19 ( V_37 . V_11 . V_43 ) ;
}
return V_31 ;
}
static T_2 F_20 ( struct V_4 * V_5 ,
T_3 V_44 ,
T_3 * V_45 )
{
T_2 V_31 ;
T_3 V_46 , V_34 [ 3 ] ;
V_44 &= V_47 ;
V_44 |= V_5 -> V_48 ;
V_34 [ V_49 ] = V_50 ;
V_34 [ V_51 ] = V_44 ;
if ( V_45 ) {
* V_45 &= V_52 ;
V_34 [ V_53 ] = * V_45 | V_5 -> V_54 ;
} else {
V_34 [ V_53 ] = V_52 ;
}
V_31 = F_16 ( V_5 -> V_13 -> V_10 , V_34 , & V_46 ) ;
if ( F_18 ( V_31 ) ) {
V_5 -> V_48 = V_44 ;
if ( V_45 )
* V_45 = V_46 ;
}
return V_31 ;
}
static T_2 F_21 ( struct V_4 * V_5 , T_3 V_55 )
{
T_2 V_31 ;
T_1 V_56 ;
V_31 = F_22 ( V_5 -> V_13 -> V_10 , L_1 , & V_56 ) ;
if ( F_15 ( V_31 ) )
return V_31 ;
F_2 ( & V_57 ) ;
V_31 = F_20 ( V_5 , V_55 , NULL ) ;
F_5 ( & V_57 ) ;
return V_31 ;
}
struct V_4 * F_23 ( T_1 V_10 )
{
struct V_4 * V_5 ;
struct V_12 * V_13 ;
if ( F_9 ( V_10 , & V_13 ) ||
F_10 ( V_13 , V_14 ) )
return NULL ;
V_5 = F_24 ( V_13 ) ;
return V_5 ;
}
struct V_58 * F_25 ( T_1 V_10 )
{
int V_59 , V_60 ;
unsigned long long V_61 ;
T_2 V_31 ;
T_1 V_62 ;
struct V_63 * V_64 ;
struct V_58 * V_65 = NULL ;
struct V_66 * V_7 , * V_56 ;
struct V_4 * V_5 ;
F_26 ( V_67 ) ;
V_62 = V_10 ;
while ( ! F_8 ( V_62 ) ) {
V_7 = F_27 ( sizeof( struct V_66 ) , V_68 ) ;
if ( ! V_7 )
goto V_69;
F_28 ( & V_7 -> V_7 ) ;
V_7 -> V_10 = V_62 ;
F_29 ( & V_7 -> V_7 , & V_67 ) ;
V_31 = F_30 ( V_62 , & V_62 ) ;
if ( F_15 ( V_31 ) )
goto V_69;
}
V_5 = F_23 ( V_62 ) ;
if ( ! V_5 )
goto V_69;
V_64 = V_5 -> V_70 ;
F_4 (node, &device_list, node) {
T_1 V_71 = V_7 -> V_10 ;
V_31 = F_31 ( V_71 , L_2 , NULL , & V_61 ) ;
if ( F_15 ( V_31 ) )
goto V_69;
V_59 = ( V_61 >> 16 ) & 0xffff ;
V_60 = V_61 & 0xffff ;
V_65 = F_32 ( V_64 , F_33 ( V_59 , V_60 ) ) ;
if ( ! V_65 || V_71 == V_10 )
break;
V_64 = V_65 -> V_72 ;
F_34 ( V_65 ) ;
if ( ! V_64 ) {
F_35 ( & V_65 -> V_59 , L_3 ) ;
V_65 = NULL ;
break;
}
}
V_69:
F_36 (node, tmp, &device_list, node)
F_19 ( V_7 ) ;
return V_65 ;
}
T_2 F_37 ( T_1 V_10 , T_3 * V_73 , T_3 V_74 )
{
struct V_4 * V_5 ;
T_2 V_31 ;
T_3 V_75 , V_34 [ 3 ] ;
T_1 V_56 ;
if ( ! V_73 )
return V_76 ;
V_75 = * V_73 & V_52 ;
if ( ( V_75 & V_74 ) != V_74 )
return V_77 ;
V_5 = F_23 ( V_10 ) ;
if ( ! V_5 )
return V_78 ;
V_31 = F_22 ( V_10 , L_1 , & V_56 ) ;
if ( F_15 ( V_31 ) )
return V_31 ;
F_2 ( & V_57 ) ;
* V_73 = V_75 | V_5 -> V_54 ;
if ( ( V_5 -> V_54 & V_75 ) == V_75 )
goto V_69;
while ( * V_73 ) {
V_31 = F_20 ( V_5 , V_5 -> V_48 , V_73 ) ;
if ( F_15 ( V_31 ) )
goto V_69;
if ( V_75 == * V_73 )
break;
V_75 = * V_73 ;
}
if ( ( V_75 & V_74 ) != V_74 ) {
V_31 = V_79 ;
goto V_69;
}
V_34 [ V_49 ] = 0 ;
V_34 [ V_51 ] = V_5 -> V_48 ;
V_34 [ V_53 ] = V_75 ;
V_31 = F_16 ( V_10 , V_34 , V_73 ) ;
if ( F_18 ( V_31 ) )
V_5 -> V_54 = * V_73 ;
V_69:
F_5 ( & V_57 ) ;
return V_31 ;
}
static int F_38 ( struct V_12 * V_13 ,
const struct V_80 * V_81 )
{
unsigned long long V_82 , V_70 ;
T_2 V_31 ;
int V_46 ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
T_3 V_55 , V_83 ;
V_5 = F_27 ( sizeof( struct V_4 ) , V_68 ) ;
if ( ! V_5 )
return - V_84 ;
V_82 = 0 ;
V_31 = F_31 ( V_13 -> V_10 , V_85 , NULL ,
& V_82 ) ;
if ( F_15 ( V_31 ) && V_31 != V_86 ) {
F_39 (KERN_ERR PREFIX L_4 ) ;
V_46 = - V_87 ;
goto V_30;
}
V_5 -> V_88 . V_55 = V_89 ;
V_31 = F_13 ( V_13 -> V_10 , & V_5 -> V_88 ) ;
if ( F_15 ( V_31 ) ) {
V_5 -> V_88 . V_30 = 0xFF ;
F_39 (KERN_WARNING FW_BUG PREFIX
L_5 ) ;
V_31 = F_31 ( V_13 -> V_10 , V_90 ,
NULL , & V_70 ) ;
if ( F_18 ( V_31 ) )
V_5 -> V_88 . V_28 = V_70 ;
else if ( V_31 == V_86 )
V_5 -> V_88 . V_28 = 0 ;
else {
F_39 (KERN_ERR PREFIX L_6 ) ;
V_46 = - V_87 ;
goto V_30;
}
}
F_28 ( & V_5 -> V_7 ) ;
V_5 -> V_13 = V_13 ;
V_5 -> V_82 = V_82 & 0xFFFF ;
strcpy ( F_40 ( V_13 ) , V_91 ) ;
strcpy ( F_41 ( V_13 ) , V_92 ) ;
V_13 -> V_93 = V_5 ;
F_39 (KERN_INFO PREFIX L_7 ,
acpi_device_name(device), acpi_device_bid(device),
root->segment, &root->secondary) ;
V_5 -> V_94 = F_42 ( V_13 -> V_10 ) ;
V_55 = V_83 = V_95 ;
F_21 ( V_5 , V_55 ) ;
F_2 ( & V_6 ) ;
F_3 ( & V_5 -> V_7 , & V_96 ) ;
F_5 ( & V_6 ) ;
V_5 -> V_70 = F_43 ( V_5 ) ;
if ( ! V_5 -> V_70 ) {
F_39 (KERN_ERR PREFIX
L_8 ,
root->segment, (unsigned int)root->secondary.start) ;
V_46 = - V_87 ;
goto V_97;
}
if ( F_44 () )
V_55 |= V_98 ;
if ( F_45 () ) {
V_55 |= V_99 |
V_100 ;
}
if ( F_46 () )
V_55 |= V_101 ;
if ( V_55 != V_83 ) {
V_31 = F_21 ( V_5 , V_55 ) ;
if ( F_15 ( V_31 ) ) {
F_47 ( & V_13 -> V_59 , L_9
L_10 ) ;
F_48 () ;
V_55 = V_83 ;
}
}
if ( ! V_102
&& ( V_55 & V_103 ) == V_103 ) {
V_55 = V_104
| V_105
| V_106 ;
if ( F_49 () ) {
if ( F_50 () )
F_35 ( & V_13 -> V_59 ,
L_11 ) ;
else
V_55 |= V_107 ;
}
F_47 ( & V_13 -> V_59 ,
L_12 , V_55 ) ;
V_31 = F_37 ( V_13 -> V_10 , & V_55 ,
V_104 ) ;
if ( F_18 ( V_31 ) ) {
F_47 ( & V_13 -> V_59 ,
L_13 , V_55 ) ;
if ( V_108 . V_109 & V_110 ) {
F_51 ( V_5 -> V_70 ) ;
}
} else {
F_47 ( & V_13 -> V_59 ,
L_14
L_15 ,
F_52 ( V_31 ) , V_55 ) ;
F_53 ( L_16
L_17 ) ;
F_48 () ;
}
} else {
F_47 ( & V_13 -> V_59 ,
L_18
L_19 , V_55 ) ;
}
F_54 ( V_13 , V_5 -> V_70 ) ;
if ( V_13 -> V_111 . V_55 . V_112 )
F_55 ( V_5 -> V_70 -> V_113 , true ) ;
if ( V_114 != V_115 ) {
F_56 ( V_5 -> V_70 ) ;
F_57 ( V_5 -> V_70 ) ;
}
F_2 ( & V_6 ) ;
F_4 (driver, &acpi_pci_drivers, node)
if ( V_2 -> V_9 )
V_2 -> V_9 ( V_5 ) ;
F_5 ( & V_6 ) ;
if ( V_114 != V_115 )
F_58 ( V_5 -> V_70 ) ;
F_59 ( V_5 -> V_70 ) ;
return 1 ;
V_97:
F_2 ( & V_6 ) ;
F_7 ( & V_5 -> V_7 ) ;
F_5 ( & V_6 ) ;
V_30:
F_19 ( V_5 ) ;
return V_46 ;
}
static void F_60 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_24 ( V_13 ) ;
struct V_1 * V_2 ;
F_61 ( V_5 -> V_70 ) ;
F_2 ( & V_6 ) ;
F_62 (driver, &acpi_pci_drivers, node)
if ( V_2 -> remove )
V_2 -> remove ( V_5 ) ;
F_5 ( & V_6 ) ;
F_55 ( V_5 -> V_70 -> V_113 , false ) ;
F_63 ( V_13 ) ;
F_64 ( V_5 -> V_70 ) ;
F_2 ( & V_6 ) ;
F_7 ( & V_5 -> V_7 ) ;
F_5 ( & V_6 ) ;
F_19 ( V_5 ) ;
}
void T_4 F_65 ( void )
{
F_66 () ;
if ( ! V_116 ) {
F_67 () ;
F_68 ( & V_117 ) ;
}
}
static void F_69 ( T_1 V_10 )
{
struct V_12 * V_13 ;
if ( ! F_9 ( V_10 , & V_13 ) ) {
F_39 ( V_118 L_20 ) ;
return;
}
if ( F_70 ( V_10 ) )
F_39 ( V_119 L_21 ) ;
}
static void F_71 ( struct V_12 * V_13 )
{
T_2 V_31 ;
struct V_120 * V_121 ;
V_121 = F_72 ( sizeof( * V_121 ) , V_68 ) ;
if ( ! V_121 ) {
( void ) F_73 ( V_13 -> V_10 ,
V_122 ,
V_123 ,
NULL ) ;
return;
}
V_121 -> V_13 = V_13 ;
V_121 -> V_124 = V_122 ;
V_31 = F_74 ( V_125 , V_121 ) ;
if ( F_15 ( V_31 ) )
F_19 ( V_121 ) ;
}
static void F_75 ( struct V_126 * V_127 )
{
struct V_4 * V_5 ;
struct V_128 V_129 = { V_130 } ;
struct V_131 * V_132 ;
T_1 V_10 ;
T_3 type ;
V_132 = F_76 ( V_127 , struct V_131 , V_127 ) ;
V_10 = V_132 -> V_10 ;
type = V_132 -> type ;
F_77 () ;
V_5 = F_23 ( V_10 ) ;
F_78 ( V_10 , V_133 , & V_129 ) ;
switch ( type ) {
case V_134 :
F_39 ( V_118 L_22 , V_135 ,
( char * ) V_129 . V_43 ) ;
if ( ! V_5 )
F_69 ( V_10 ) ;
break;
case V_136 :
F_39 ( V_118 L_23 , V_135 ,
( char * ) V_129 . V_43 ) ;
if ( ! V_5 )
F_69 ( V_10 ) ;
break;
case V_122 :
F_39 ( V_118 L_24 , V_135 ,
( char * ) V_129 . V_43 ) ;
if ( V_5 )
F_71 ( V_5 -> V_13 ) ;
break;
default:
F_39 ( V_137 L_25 ,
type , ( char * ) V_129 . V_43 ) ;
break;
}
F_79 () ;
F_19 ( V_132 ) ;
F_19 ( V_129 . V_43 ) ;
}
static void F_80 ( T_1 V_10 , T_3 type ,
void * V_37 )
{
F_81 ( V_10 , type , V_37 ,
F_75 ) ;
}
static T_2 T_4
F_82 ( T_1 V_10 , T_3 V_138 , void * V_37 , void * * V_139 )
{
T_2 V_31 ;
char V_140 [ 64 ] ;
struct V_128 V_129 = { . V_42 = sizeof( V_140 ) ,
. V_43 = V_140 } ;
int * V_141 = ( int * ) V_37 ;
if ( ! F_8 ( V_10 ) )
return V_24 ;
( * V_141 ) ++ ;
F_78 ( V_10 , V_133 , & V_129 ) ;
V_31 = F_83 ( V_10 , V_142 ,
F_80 , NULL ) ;
if ( F_15 ( V_31 ) )
F_39 ( V_118 L_26 ,
V_140 , ( unsigned int ) V_31 ) ;
else
F_39 ( V_118 L_27 ,
V_140 ) ;
return V_24 ;
}
void T_4 F_84 ( void )
{
int V_143 = 0 ;
F_85 ( V_144 , V_145 ,
V_146 , F_82 , NULL , & V_143 , NULL ) ;
F_39 ( V_118 L_28 , V_143 ) ;
}
