int F_1 ( T_1 V_1 )
{
int V_2 ;
struct V_3 * V_4 ;
V_2 = F_2 ( V_1 , & V_4 ) ;
if ( V_2 )
return 0 ;
V_2 = F_3 ( V_4 , V_5 ) ;
if ( V_2 )
return 0 ;
else
return 1 ;
}
static T_2
F_4 ( struct V_6 * V_7 , void * V_8 )
{
struct V_7 * V_9 = V_8 ;
struct V_10 V_11 ;
if ( V_7 -> type != V_12 &&
V_7 -> type != V_13 &&
V_7 -> type != V_14 )
return V_15 ;
F_5 ( V_7 , & V_11 ) ;
if ( ( V_11 . V_16 > 0 ) &&
( V_11 . V_17 == V_18 ) ) {
V_9 -> V_19 = V_11 . V_20 ;
V_9 -> V_21 = V_11 . V_20 + V_11 . V_16 - 1 ;
}
return V_15 ;
}
static T_2 F_6 ( T_1 V_1 ,
struct V_7 * V_9 )
{
T_2 V_22 ;
V_9 -> V_19 = - 1 ;
V_22 =
F_7 ( V_1 , V_23 ,
F_4 , V_9 ) ;
if ( F_8 ( V_22 ) )
return V_22 ;
if ( V_9 -> V_19 == - 1 )
return V_24 ;
return V_15 ;
}
static T_2 F_9 ( T_1 V_1 ,
const T_3 * V_25 , T_3 * V_26 )
{
struct V_27 V_28 = {
. V_29 = V_30 ,
. V_31 = 1 ,
. V_32 . V_33 = 12 ,
. V_32 . V_34 = ( void * ) V_25 ,
} ;
T_2 V_22 ;
V_22 = F_10 ( V_1 , & V_28 ) ;
if ( F_11 ( V_22 ) ) {
* V_26 = * ( ( T_3 * ) ( V_28 . V_2 . V_34 + 8 ) ) ;
F_12 ( V_28 . V_2 . V_34 ) ;
}
return V_22 ;
}
static T_2 F_13 ( struct V_35 * V_36 ,
T_3 V_37 ,
T_3 * V_38 )
{
T_2 V_22 ;
T_3 V_39 , V_25 [ 3 ] ;
V_37 &= V_40 ;
V_37 |= V_36 -> V_41 ;
V_25 [ V_42 ] = V_43 ;
V_25 [ V_44 ] = V_37 ;
if ( V_38 ) {
* V_38 &= V_45 ;
V_25 [ V_46 ] = * V_38 | V_36 -> V_47 ;
} else {
V_25 [ V_46 ] = V_36 -> V_47 ;
}
V_22 = F_9 ( V_36 -> V_4 -> V_1 , V_25 , & V_39 ) ;
if ( F_11 ( V_22 ) ) {
V_36 -> V_41 = V_37 ;
if ( V_38 )
* V_38 = V_39 ;
}
return V_22 ;
}
static T_2 F_14 ( struct V_35 * V_36 , T_3 V_48 )
{
T_2 V_22 ;
T_1 V_49 ;
V_22 = F_15 ( V_36 -> V_4 -> V_1 , L_1 , & V_49 ) ;
if ( F_8 ( V_22 ) )
return V_22 ;
F_16 ( & V_50 ) ;
V_22 = F_13 ( V_36 , V_48 , NULL ) ;
F_17 ( & V_50 ) ;
return V_22 ;
}
struct V_35 * F_18 ( T_1 V_1 )
{
struct V_35 * V_36 ;
struct V_3 * V_4 ;
if ( F_2 ( V_1 , & V_4 ) ||
F_3 ( V_4 , V_5 ) )
return NULL ;
V_36 = F_19 ( V_4 ) ;
return V_36 ;
}
struct V_51 * F_20 ( T_1 V_1 )
{
int V_52 , V_53 ;
unsigned long long V_54 ;
T_2 V_22 ;
T_1 V_55 ;
struct V_56 * V_57 ;
struct V_51 * V_58 = NULL ;
struct V_59 * V_60 , * V_49 ;
struct V_35 * V_36 ;
F_21 ( V_61 ) ;
V_55 = V_1 ;
while ( ! F_1 ( V_55 ) ) {
V_60 = F_22 ( sizeof( struct V_59 ) , V_62 ) ;
if ( ! V_60 )
goto V_63;
F_23 ( & V_60 -> V_60 ) ;
V_60 -> V_1 = V_55 ;
F_24 ( & V_60 -> V_60 , & V_61 ) ;
V_22 = F_25 ( V_55 , & V_55 ) ;
if ( F_8 ( V_22 ) )
goto V_63;
}
V_36 = F_18 ( V_55 ) ;
if ( ! V_36 )
goto V_63;
V_57 = V_36 -> V_64 ;
F_26 (node, &device_list, node) {
T_1 V_65 = V_60 -> V_1 ;
V_22 = F_27 ( V_65 , L_2 , NULL , & V_54 ) ;
if ( F_8 ( V_22 ) )
goto V_63;
V_52 = ( V_54 >> 16 ) & 0xffff ;
V_53 = V_54 & 0xffff ;
V_58 = F_28 ( V_57 , F_29 ( V_52 , V_53 ) ) ;
if ( ! V_58 || V_65 == V_1 )
break;
V_57 = V_58 -> V_66 ;
F_30 ( V_58 ) ;
if ( ! V_57 ) {
F_31 ( & V_58 -> V_52 , L_3 ) ;
V_58 = NULL ;
break;
}
}
V_63:
F_32 (node, tmp, &device_list, node)
F_12 ( V_60 ) ;
return V_58 ;
}
T_2 F_33 ( T_1 V_1 , T_3 * V_67 , T_3 V_68 )
{
struct V_35 * V_36 ;
T_2 V_22 ;
T_3 V_69 , V_25 [ 3 ] ;
T_1 V_49 ;
if ( ! V_67 )
return V_70 ;
V_69 = * V_67 & V_45 ;
if ( ( V_69 & V_68 ) != V_68 )
return V_71 ;
V_36 = F_18 ( V_1 ) ;
if ( ! V_36 )
return V_72 ;
V_22 = F_15 ( V_1 , L_1 , & V_49 ) ;
if ( F_8 ( V_22 ) )
return V_22 ;
F_16 ( & V_50 ) ;
* V_67 = V_69 | V_36 -> V_47 ;
if ( ( V_36 -> V_47 & V_69 ) == V_69 )
goto V_63;
while ( * V_67 ) {
V_22 = F_13 ( V_36 , V_36 -> V_41 , V_67 ) ;
if ( F_8 ( V_22 ) )
goto V_63;
if ( V_69 == * V_67 )
break;
V_69 = * V_67 ;
}
if ( ( V_69 & V_68 ) != V_68 ) {
V_22 = V_73 ;
goto V_63;
}
V_25 [ V_42 ] = 0 ;
V_25 [ V_44 ] = V_36 -> V_41 ;
V_25 [ V_46 ] = V_69 ;
V_22 = F_9 ( V_1 , V_25 , V_67 ) ;
if ( F_11 ( V_22 ) )
V_36 -> V_47 = * V_67 ;
V_63:
F_17 ( & V_50 ) ;
return V_22 ;
}
static int F_34 ( struct V_3 * V_4 ,
const struct V_74 * V_75 )
{
unsigned long long V_76 , V_64 ;
T_2 V_22 ;
int V_39 ;
struct V_35 * V_36 ;
T_3 V_48 , V_77 ;
V_36 = F_22 ( sizeof( struct V_35 ) , V_62 ) ;
if ( ! V_36 )
return - V_78 ;
V_76 = 0 ;
V_22 = F_27 ( V_4 -> V_1 , V_79 , NULL ,
& V_76 ) ;
if ( F_8 ( V_22 ) && V_22 != V_80 ) {
F_35 (KERN_ERR PREFIX L_4 ) ;
V_39 = - V_81 ;
goto V_21;
}
V_36 -> V_82 . V_48 = V_83 ;
V_22 = F_6 ( V_4 -> V_1 , & V_36 -> V_82 ) ;
if ( F_8 ( V_22 ) ) {
V_36 -> V_82 . V_21 = 0xFF ;
F_35 (KERN_WARNING FW_BUG PREFIX
L_5 ) ;
V_22 = F_27 ( V_4 -> V_1 , V_84 ,
NULL , & V_64 ) ;
if ( F_11 ( V_22 ) )
V_36 -> V_82 . V_19 = V_64 ;
else if ( V_22 == V_80 )
V_36 -> V_82 . V_19 = 0 ;
else {
F_35 (KERN_ERR PREFIX L_6 ) ;
V_39 = - V_81 ;
goto V_21;
}
}
F_23 ( & V_36 -> V_60 ) ;
V_36 -> V_4 = V_4 ;
V_36 -> V_76 = V_76 & 0xFFFF ;
strcpy ( F_36 ( V_4 ) , V_85 ) ;
strcpy ( F_37 ( V_4 ) , V_86 ) ;
V_4 -> V_87 = V_36 ;
F_35 (KERN_INFO PREFIX L_7 ,
acpi_device_name(device), acpi_device_bid(device),
root->segment, &root->secondary) ;
V_36 -> V_88 = F_38 ( V_4 -> V_1 ) ;
V_48 = V_77 = V_89 ;
F_14 ( V_36 , V_48 ) ;
F_16 ( & V_90 ) ;
F_39 ( & V_36 -> V_60 , & V_91 ) ;
F_17 ( & V_90 ) ;
V_36 -> V_64 = F_40 ( V_36 ) ;
if ( ! V_36 -> V_64 ) {
F_35 (KERN_ERR PREFIX
L_8 ,
root->segment, (unsigned int)root->secondary.start) ;
V_39 = - V_81 ;
goto V_92;
}
if ( F_41 () )
V_48 |= V_93 ;
if ( F_42 () ) {
V_48 |= V_94 |
V_95 ;
}
if ( F_43 () )
V_48 |= V_96 ;
if ( V_48 != V_77 ) {
V_22 = F_14 ( V_36 , V_48 ) ;
if ( F_8 ( V_22 ) ) {
F_44 ( & V_4 -> V_52 , L_9
L_10 ) ;
F_45 () ;
V_48 = V_77 ;
}
}
if ( ! V_97
&& ( V_48 & V_98 ) == V_98 ) {
V_48 = V_99
| V_100
| V_101 ;
if ( F_46 () ) {
if ( F_47 () )
F_31 ( & V_4 -> V_52 ,
L_11 ) ;
else
V_48 |= V_102 ;
}
F_44 ( & V_4 -> V_52 ,
L_12 , V_48 ) ;
V_22 = F_33 ( V_4 -> V_1 , & V_48 ,
V_99 ) ;
if ( F_11 ( V_22 ) ) {
F_44 ( & V_4 -> V_52 ,
L_13 , V_48 ) ;
if ( V_103 . V_104 & V_105 ) {
F_48 ( V_36 -> V_64 ) ;
}
} else {
F_44 ( & V_4 -> V_52 ,
L_14
L_15 ,
F_49 ( V_22 ) , V_48 ) ;
F_50 ( L_16
L_17 ) ;
F_45 () ;
}
} else {
F_44 ( & V_4 -> V_52 ,
L_18
L_19 , V_48 ) ;
}
F_51 ( V_4 , V_36 -> V_64 ) ;
if ( V_4 -> V_106 . V_48 . V_107 )
F_52 ( V_36 -> V_64 -> V_108 , true ) ;
if ( V_109 != V_110 ) {
F_53 ( V_36 -> V_64 ) ;
F_54 ( V_36 -> V_64 ) ;
}
if ( V_109 != V_110 )
F_55 ( V_36 -> V_64 ) ;
F_56 ( V_36 -> V_64 ) ;
return 1 ;
V_92:
F_16 ( & V_90 ) ;
F_57 ( & V_36 -> V_60 ) ;
F_17 ( & V_90 ) ;
V_21:
F_12 ( V_36 ) ;
return V_39 ;
}
static void F_58 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = F_19 ( V_4 ) ;
F_59 ( V_36 -> V_64 ) ;
F_52 ( V_36 -> V_64 -> V_108 , false ) ;
F_60 ( V_4 ) ;
F_61 ( V_36 -> V_64 ) ;
F_16 ( & V_90 ) ;
F_57 ( & V_36 -> V_60 ) ;
F_17 ( & V_90 ) ;
F_12 ( V_36 ) ;
}
void T_4 F_62 ( void )
{
F_63 () ;
if ( ! V_111 ) {
F_64 () ;
F_65 ( & V_112 ) ;
}
}
static void F_66 ( T_1 V_1 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_1 , & V_4 ) ) {
F_35 ( V_113 L_20 ) ;
return;
}
if ( F_67 ( V_1 ) )
F_35 ( V_114 L_21 ) ;
}
static void F_68 ( struct V_3 * V_4 )
{
T_2 V_22 ;
struct V_115 * V_116 ;
V_116 = F_69 ( sizeof( * V_116 ) , V_62 ) ;
if ( ! V_116 ) {
( void ) F_70 ( V_4 -> V_1 ,
V_117 ,
V_118 ,
NULL ) ;
return;
}
V_116 -> V_4 = V_4 ;
V_116 -> V_119 = V_117 ;
V_22 = F_71 ( V_120 , V_116 ) ;
if ( F_8 ( V_22 ) )
F_12 ( V_116 ) ;
}
static void F_72 ( struct V_121 * V_122 )
{
struct V_35 * V_36 ;
struct V_123 V_124 = { V_125 } ;
struct V_126 * V_127 ;
T_1 V_1 ;
T_3 type ;
V_127 = F_73 ( V_122 , struct V_126 , V_122 ) ;
V_1 = V_127 -> V_1 ;
type = V_127 -> type ;
F_74 () ;
V_36 = F_18 ( V_1 ) ;
F_75 ( V_1 , V_128 , & V_124 ) ;
switch ( type ) {
case V_129 :
F_35 ( V_113 L_22 , V_130 ,
( char * ) V_124 . V_34 ) ;
if ( V_36 )
F_76 ( V_1 ) ;
else
F_66 ( V_1 ) ;
break;
case V_131 :
F_35 ( V_113 L_23 , V_130 ,
( char * ) V_124 . V_34 ) ;
if ( ! V_36 )
F_66 ( V_1 ) ;
break;
case V_117 :
F_35 ( V_113 L_24 , V_130 ,
( char * ) V_124 . V_34 ) ;
if ( V_36 )
F_68 ( V_36 -> V_4 ) ;
break;
default:
F_35 ( V_132 L_25 ,
type , ( char * ) V_124 . V_34 ) ;
break;
}
F_77 () ;
F_12 ( V_127 ) ;
F_12 ( V_124 . V_34 ) ;
}
static void F_78 ( T_1 V_1 , T_3 type ,
void * V_28 )
{
F_79 ( V_1 , type , V_28 ,
F_72 ) ;
}
static T_2 T_4
F_80 ( T_1 V_1 , T_3 V_133 , void * V_28 , void * * V_134 )
{
T_2 V_22 ;
char V_135 [ 64 ] ;
struct V_123 V_124 = { . V_33 = sizeof( V_135 ) ,
. V_34 = V_135 } ;
int * V_136 = ( int * ) V_28 ;
if ( ! F_1 ( V_1 ) )
return V_15 ;
( * V_136 ) ++ ;
F_75 ( V_1 , V_128 , & V_124 ) ;
V_22 = F_81 ( V_1 , V_137 ,
F_78 , NULL ) ;
if ( F_8 ( V_22 ) )
F_35 ( V_113 L_26 ,
V_135 , ( unsigned int ) V_22 ) ;
else
F_35 ( V_113 L_27 ,
V_135 ) ;
return V_15 ;
}
void T_4 F_82 ( void )
{
int V_138 = 0 ;
F_83 ( V_139 , V_140 ,
V_141 , F_80 , NULL , & V_138 , NULL ) ;
F_35 ( V_113 L_28 , V_138 ) ;
}
