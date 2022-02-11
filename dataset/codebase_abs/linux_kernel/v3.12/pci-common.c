void F_1 ( struct V_1 * V_2 )
{
V_3 = V_2 ;
}
struct V_1 * F_2 ( void )
{
return V_3 ;
}
struct V_4 * F_3 ( struct V_5 * V_6 )
{
struct V_4 * V_7 ;
V_7 = F_4 ( sizeof( struct V_4 ) , V_8 ) ;
if ( ! V_7 )
return NULL ;
F_5 ( & V_9 ) ;
V_7 -> V_10 = V_11 ++ ;
F_6 ( & V_7 -> V_12 , & V_13 ) ;
F_7 ( & V_9 ) ;
V_7 -> V_14 = V_6 ;
V_7 -> V_15 = V_16 ;
return V_7 ;
}
void F_8 ( struct V_4 * V_7 )
{
F_5 ( & V_9 ) ;
F_9 ( & V_7 -> V_12 ) ;
F_7 ( & V_9 ) ;
if ( V_7 -> V_15 )
F_10 ( V_7 ) ;
}
static T_1 F_11 ( const struct V_4 * V_17 )
{
return F_12 ( & V_17 -> V_18 ) ;
}
int F_13 ( void T_2 * V_19 )
{
int V_20 = 0 ;
struct V_4 * V_17 ;
T_1 V_21 ;
F_5 ( & V_9 ) ;
F_14 (hose, &hose_list, list_node) {
V_21 = F_11 ( V_17 ) ;
if ( V_19 >= V_17 -> V_22 &&
V_19 < ( V_17 -> V_22 + V_21 ) ) {
V_20 = 1 ;
break;
}
}
F_7 ( & V_9 ) ;
return V_20 ;
}
unsigned long F_15 ( T_3 V_19 )
{
struct V_4 * V_17 ;
T_1 V_21 ;
unsigned long V_20 = ~ 0 ;
F_5 ( & V_9 ) ;
F_14 (hose, &hose_list, list_node) {
V_21 = F_11 ( V_17 ) ;
if ( V_19 >= V_17 -> V_23 &&
V_19 < ( V_17 -> V_23 + V_21 ) ) {
unsigned long V_24 =
( unsigned long ) V_17 -> V_22 - V_25 ;
V_20 = V_24 + ( V_19 - V_17 -> V_23 ) ;
break;
}
}
F_7 ( & V_9 ) ;
return V_20 ;
}
int F_16 ( struct V_26 * V_27 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
return V_17 -> V_10 ;
}
struct V_4 * F_18 ( struct V_5 * V_28 )
{
while ( V_28 ) {
struct V_4 * V_17 , * V_29 ;
F_19 (hose, tmp, &hose_list, list_node)
if ( V_17 -> V_14 == V_28 )
return V_17 ;
V_28 = V_28 -> V_30 ;
}
return NULL ;
}
static T_4 F_20 ( struct V_31 * V_6 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_35 * V_36 ;
struct V_5 * V_37 ;
V_36 = F_21 ( V_6 ) ;
V_37 = F_22 ( V_36 ) ;
if ( V_37 == NULL || V_37 -> V_38 == NULL )
return 0 ;
return sprintf ( V_34 , L_1 , V_37 -> V_38 ) ;
}
int F_23 ( struct V_35 * V_36 )
{
return F_24 ( & V_36 -> V_6 , & V_39 ) ;
}
void F_25 ( struct V_35 * V_6 )
{
}
int F_26 ( struct V_35 * V_35 )
{
struct V_40 V_41 ;
unsigned int V_42 ;
F_27 ( L_2 , F_28 ( V_35 ) ) ;
#ifdef F_29
memset ( & V_41 , 0xff , sizeof( V_41 ) ) ;
#endif
if ( F_30 ( V_35 , & V_41 ) ) {
T_5 line , V_43 ;
if ( F_31 ( V_35 , V_44 , & V_43 ) )
return - 1 ;
if ( V_43 == 0 )
return - 1 ;
if ( F_31 ( V_35 , V_45 , & line ) ||
line == 0xff || line == 0 ) {
return - 1 ;
}
F_27 ( L_3 ,
line , V_43 ) ;
V_42 = F_32 ( NULL , line ) ;
if ( V_42 )
F_33 ( V_42 , V_46 ) ;
} else {
F_27 ( L_4 ,
V_41 . V_21 , V_41 . V_47 [ 0 ] , V_41 . V_47 [ 1 ] ,
F_34 ( V_41 . V_48 ) ) ;
V_42 = F_35 ( V_41 . V_48 , V_41 . V_47 ,
V_41 . V_21 ) ;
}
if ( ! V_42 ) {
F_27 ( L_5 ) ;
return - 1 ;
}
F_27 ( L_6 , V_42 ) ;
V_35 -> V_49 = V_42 ;
return 0 ;
}
static struct V_50 * F_36 ( struct V_35 * V_6 ,
T_1 * V_51 ,
enum V_52 V_53 )
{
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
unsigned long V_54 = 0 ;
int V_55 , V_56 ;
if ( ! V_17 )
return NULL ;
if ( V_53 == V_57 ) {
#if 0
*offset += hose->pci_mem_offset;
#endif
V_56 = V_58 ;
} else {
V_54 = ( unsigned long ) V_17 -> V_22 - V_25 ;
* V_51 += V_54 ;
V_56 = V_59 ;
}
for ( V_55 = 0 ; V_55 <= V_60 ; V_55 ++ ) {
struct V_50 * V_61 = & V_6 -> V_50 [ V_55 ] ;
int V_62 = V_61 -> V_62 ;
if ( V_55 == V_60 )
V_62 |= V_58 ;
if ( ( V_62 & V_56 ) == 0 )
continue;
if ( * V_51 < ( V_61 -> V_63 & V_64 ) || * V_51 > V_61 -> V_65 )
continue;
if ( V_53 == V_66 )
* V_51 += V_17 -> V_23 - V_54 ;
return V_61 ;
}
return NULL ;
}
static T_6 F_37 ( struct V_35 * V_6 , struct V_50 * V_61 ,
T_6 V_67 ,
enum V_52 V_53 ,
int V_68 )
{
T_6 V_69 = V_67 ;
if ( V_53 != V_57 )
V_68 = 0 ;
else if ( V_68 == 0 ) {
if ( V_61 -> V_62 & V_70 )
V_68 = 1 ;
}
return F_38 ( V_69 ) ;
}
T_6 F_39 ( struct V_71 * V_71 ,
unsigned long V_72 ,
unsigned long V_21 ,
T_6 V_69 )
{
struct V_35 * V_36 = NULL ;
struct V_50 * V_73 = NULL ;
T_1 V_51 = ( ( T_1 ) V_72 ) << V_74 ;
int V_55 ;
if ( F_40 ( V_72 ) )
return V_69 ;
V_69 = F_38 ( V_69 ) ;
F_41 (pdev) {
for ( V_55 = 0 ; V_55 <= V_60 ; V_55 ++ ) {
struct V_50 * V_61 = & V_36 -> V_50 [ V_55 ] ;
int V_62 = V_61 -> V_62 ;
if ( ( V_62 & V_58 ) == 0 )
continue;
if ( V_51 < ( V_61 -> V_63 & V_64 ) ||
V_51 > V_61 -> V_65 )
continue;
V_73 = V_61 ;
break;
}
if ( V_73 )
break;
}
if ( V_73 ) {
if ( V_73 -> V_62 & V_70 )
V_69 = F_42 ( V_69 ) ;
F_43 ( V_36 ) ;
}
F_27 ( L_7 ,
( unsigned long long ) V_51 , F_44 ( V_69 ) ) ;
return V_69 ;
}
int F_45 ( struct V_35 * V_6 , struct V_75 * V_76 ,
enum V_52 V_53 , int V_68 )
{
T_1 V_51 =
( ( T_1 ) V_76 -> V_77 ) << V_74 ;
struct V_50 * V_61 ;
int V_20 ;
V_61 = F_36 ( V_6 , & V_51 , V_53 ) ;
if ( V_61 == NULL )
return - V_78 ;
V_76 -> V_77 = V_51 >> V_74 ;
V_76 -> V_79 = F_37 ( V_6 , V_61 ,
V_76 -> V_79 ,
V_53 , V_68 ) ;
V_20 = F_46 ( V_76 , V_76 -> V_80 , V_76 -> V_77 ,
V_76 -> V_81 - V_76 -> V_80 , V_76 -> V_79 ) ;
return V_20 ;
}
int F_47 ( struct V_26 * V_27 , T_7 V_82 , T_8 * V_83 , T_9 V_21 )
{
unsigned long V_51 ;
struct V_4 * V_17 = F_17 ( V_27 ) ;
struct V_50 * V_61 = & V_17 -> V_18 ;
void T_2 * V_84 ;
V_51 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_51 += V_82 ;
if ( ! ( V_61 -> V_62 & V_59 ) )
return - V_85 ;
if ( V_51 < V_61 -> V_63 || ( V_51 + V_21 ) > V_61 -> V_65 )
return - V_85 ;
V_84 = V_17 -> V_22 + V_82 ;
switch ( V_21 ) {
case 1 :
* ( ( T_5 * ) V_83 ) = F_48 ( V_84 ) ;
return 1 ;
case 2 :
if ( V_82 & 1 )
return - V_78 ;
* ( ( V_86 * ) V_83 ) = F_49 ( V_84 ) ;
return 2 ;
case 4 :
if ( V_82 & 3 )
return - V_78 ;
* ( ( T_8 * ) V_83 ) = F_50 ( V_84 ) ;
return 4 ;
}
return - V_78 ;
}
int F_51 ( struct V_26 * V_27 , T_7 V_82 , T_8 V_83 , T_9 V_21 )
{
unsigned long V_51 ;
struct V_4 * V_17 = F_17 ( V_27 ) ;
struct V_50 * V_61 = & V_17 -> V_18 ;
void T_2 * V_84 ;
V_51 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_51 += V_82 ;
if ( ! ( V_61 -> V_62 & V_59 ) )
return - V_85 ;
if ( V_51 < V_61 -> V_63 || ( V_51 + V_21 ) > V_61 -> V_65 )
return - V_85 ;
V_84 = V_17 -> V_22 + V_82 ;
switch ( V_21 ) {
case 1 :
F_52 ( V_84 , V_83 >> 24 ) ;
return 1 ;
case 2 :
if ( V_82 & 1 )
return - V_78 ;
F_53 ( V_84 , V_83 >> 16 ) ;
return 2 ;
case 4 :
if ( V_82 & 3 )
return - V_78 ;
F_54 ( V_84 , V_83 ) ;
return 4 ;
}
return - V_78 ;
}
int F_55 ( struct V_26 * V_27 ,
struct V_75 * V_76 ,
enum V_52 V_53 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
T_1 V_51 =
( ( T_1 ) V_76 -> V_77 ) << V_74 ;
T_1 V_21 = V_76 -> V_81 - V_76 -> V_80 ;
struct V_50 * V_61 ;
F_27 ( L_8 ,
F_16 ( V_27 ) , V_27 -> V_87 ,
V_53 == V_57 ? L_9 : L_10 ,
( unsigned long long ) V_51 ,
( unsigned long long ) ( V_51 + V_21 - 1 ) ) ;
if ( V_53 == V_57 ) {
if ( ( V_51 + V_21 ) > V_17 -> V_88 ) {
#ifdef F_56
F_27 ( L_11 ,
V_89 -> V_90 , V_89 -> V_91 ) ;
F_27 ( L_12 ,
F_16 ( V_27 ) , V_27 -> V_87 ) ;
#endif
if ( V_76 -> V_92 & V_93 )
return F_57 ( V_76 ) ;
return 0 ;
}
V_51 += V_17 -> V_94 ;
} else {
unsigned long V_54 = ( unsigned long ) V_17 -> V_22 -
V_25 ;
unsigned long V_95 = V_51 + V_54 ;
V_61 = & V_17 -> V_18 ;
if ( ! ( V_61 -> V_62 & V_59 ) )
return - V_85 ;
if ( V_95 < V_61 -> V_63 || ( V_95 + V_21 ) > V_61 -> V_65 )
return - V_85 ;
V_51 += V_17 -> V_23 ;
}
F_27 ( L_13 , ( unsigned long long ) V_51 ) ;
V_76 -> V_77 = V_51 >> V_74 ;
V_76 -> V_79 = F_38 ( V_76 -> V_79 ) ;
return F_46 ( V_76 , V_76 -> V_80 , V_76 -> V_77 ,
V_76 -> V_81 - V_76 -> V_80 ,
V_76 -> V_79 ) ;
}
void F_58 ( const struct V_35 * V_6 , int V_96 ,
const struct V_50 * V_97 ,
T_1 * V_63 , T_1 * V_65 )
{
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
T_1 V_51 = 0 ;
if ( V_17 == NULL )
return;
if ( V_97 -> V_62 & V_59 )
V_51 = ( unsigned long ) V_17 -> V_22 - V_25 ;
#if 0
else if (rsrc->flags & IORESOURCE_MEM)
offset = hose->pci_mem_offset;
#endif
* V_63 = V_97 -> V_63 - V_51 ;
* V_65 = V_97 -> V_65 - V_51 ;
}
void F_59 ( struct V_4 * V_17 ,
struct V_5 * V_6 , int V_98 )
{
int V_99 = 0 , V_100 = - 1 ;
unsigned long long V_101 = 0 ;
struct V_50 * V_102 ;
struct V_103 V_104 ;
struct V_105 V_106 ;
F_60 ( L_14 ,
V_6 -> V_38 , V_98 ? L_15 : L_16 ) ;
if ( F_61 ( & V_106 , V_6 ) )
return;
F_27 ( L_17 ) ;
F_62 (&parser, &range) {
F_27 ( L_18 ,
V_104 . V_107 , V_104 . V_108 ) ;
F_27 ( L_19 ,
V_104 . V_109 , V_104 . V_21 ) ;
if ( V_104 . V_109 == V_110 || V_104 . V_21 == 0 )
continue;
V_102 = NULL ;
switch ( V_104 . V_62 & V_111 ) {
case V_59 :
F_60 ( L_20 ,
V_104 . V_109 , V_104 . V_109 + V_104 . V_21 - 1 ,
V_104 . V_108 ) ;
if ( V_17 -> V_112 ) {
F_60 ( L_21 ) ;
continue;
}
if ( V_104 . V_21 > 0x01000000 )
V_104 . V_21 = 0x01000000 ;
V_17 -> V_22 = F_63 ( V_104 . V_109 ,
V_104 . V_21 ) ;
if ( V_98 )
V_113 =
( unsigned long ) V_17 -> V_22 ;
V_17 -> V_112 = V_104 . V_108 + V_104 . V_21 ;
V_17 -> V_23 = V_104 . V_109 - V_104 . V_108 ;
V_102 = & V_17 -> V_18 ;
V_104 . V_109 = V_104 . V_108 ;
break;
case V_58 :
F_60 ( L_22 ,
V_104 . V_109 , V_104 . V_109 + V_104 . V_21 - 1 ,
V_104 . V_108 ,
( V_104 . V_107 & 0x40000000 ) ?
L_23 : L_16 ) ;
if ( V_99 >= 3 ) {
F_60 ( L_21 ) ;
continue;
}
if ( V_104 . V_108 == 0 ) {
V_101 = V_104 . V_109 ;
V_100 = V_99 ;
if ( V_98 || V_114 == 0 )
V_114 = V_104 . V_109 ;
V_17 -> V_94 = V_104 . V_109 ;
V_17 -> V_88 = V_104 . V_21 ;
}
if ( V_99 == 0 ||
( V_100 >= 0 && V_104 . V_108 != 0 &&
V_17 -> V_115 == V_101 ) )
V_17 -> V_115 = V_104 . V_109 -
V_104 . V_108 ;
else if ( V_104 . V_108 != 0 &&
V_17 -> V_115 != V_104 . V_109 -
V_104 . V_108 ) {
F_60 ( L_24 ) ;
continue;
}
V_102 = & V_17 -> V_116 [ V_99 ++ ] ;
break;
}
if ( V_102 != NULL )
F_64 ( & V_104 , V_6 , V_102 ) ;
}
if ( V_100 >= 0 && V_17 -> V_115 != V_101 ) {
unsigned int V_117 = V_100 + 1 ;
F_60 ( L_25 , V_101 ) ;
if ( V_117 < V_99 )
memmove ( & V_17 -> V_116 [ V_100 ] ,
& V_17 -> V_116 [ V_117 ] ,
sizeof( struct V_50 ) * ( V_99 - V_117 ) ) ;
V_17 -> V_116 [ -- V_99 ] . V_62 = 0 ;
}
}
int F_65 ( struct V_26 * V_27 )
{
return 0 ;
}
static void F_66 ( struct V_35 * V_6 )
{
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
int V_55 ;
if ( ! V_17 ) {
F_67 ( L_26 ,
F_28 ( V_6 ) ) ;
return;
}
for ( V_55 = 0 ; V_55 < V_118 ; V_55 ++ ) {
struct V_50 * V_102 = V_6 -> V_50 + V_55 ;
if ( ! V_102 -> V_62 )
continue;
if ( V_102 -> V_63 == 0 ) {
F_27 ( L_27 ,
F_28 ( V_6 ) , V_55 ,
( unsigned long long ) V_102 -> V_63 ,
( unsigned long long ) V_102 -> V_65 ,
( unsigned int ) V_102 -> V_62 ) ;
F_27 ( L_28 ) ;
V_102 -> V_65 -= V_102 -> V_63 ;
V_102 -> V_63 = 0 ;
V_102 -> V_62 |= V_119 ;
continue;
}
F_27 ( L_29 ,
F_28 ( V_6 ) , V_55 ,
( unsigned long long ) V_102 -> V_63 ,
( unsigned long long ) V_102 -> V_65 ,
( unsigned int ) V_102 -> V_62 ) ;
}
}
static int F_68 ( struct V_26 * V_27 ,
struct V_50 * V_102 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
struct V_35 * V_6 = V_27 -> V_120 ;
T_1 V_51 ;
V_86 V_121 ;
int V_55 ;
if ( V_102 -> V_62 & V_58 ) {
if ( V_102 -> V_63 != V_17 -> V_115 )
return 0 ;
F_69 ( V_6 , V_122 , & V_121 ) ;
if ( ( V_121 & V_123 ) == 0 )
return 1 ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( ( V_17 -> V_116 [ V_55 ] . V_62 & V_58 ) &&
V_17 -> V_116 [ V_55 ] . V_63 == V_17 -> V_115 )
return 0 ;
}
return 1 ;
} else {
V_51 = ( unsigned long ) V_17 -> V_22 - V_25 ;
if ( ( ( V_102 -> V_63 - V_51 ) & 0xfffffffful ) != 0 )
return 0 ;
F_69 ( V_6 , V_122 , & V_121 ) ;
if ( V_121 & V_124 )
return 0 ;
return 1 ;
}
}
static void F_70 ( struct V_26 * V_27 )
{
struct V_50 * V_102 ;
int V_55 ;
struct V_35 * V_6 = V_27 -> V_120 ;
F_71 (bus, res, i) {
if ( ! V_102 )
continue;
if ( ! V_102 -> V_62 )
continue;
if ( V_55 >= 3 && V_27 -> V_120 -> V_125 )
continue;
F_27 ( L_30 ,
F_28 ( V_6 ) , V_55 ,
( unsigned long long ) V_102 -> V_63 ,
( unsigned long long ) V_102 -> V_65 ,
( unsigned int ) V_102 -> V_62 ) ;
if ( F_68 ( V_27 , V_102 ) ) {
V_102 -> V_62 = 0 ;
F_27 ( L_31 ,
F_28 ( V_6 ) ) ;
} else {
F_27 ( L_32 ,
F_28 ( V_6 ) ,
( unsigned long long ) V_102 -> V_63 ,
( unsigned long long ) V_102 -> V_65 ) ;
}
}
}
void F_72 ( struct V_26 * V_27 )
{
if ( V_27 -> V_120 != NULL )
F_70 ( V_27 ) ;
}
void F_73 ( struct V_26 * V_27 )
{
struct V_35 * V_6 ;
F_27 ( L_33 ,
V_27 -> V_87 , V_27 -> V_120 ? F_28 ( V_27 -> V_120 ) : L_34 ) ;
F_14 (dev, &bus->devices, bus_list) {
V_6 -> V_6 . V_126 = F_22 ( V_6 ) ;
F_74 ( & V_6 -> V_6 , F_75 ( V_6 -> V_27 ) ) ;
F_76 ( & V_6 -> V_6 , V_3 ) ;
V_6 -> V_6 . V_127 . V_128 = ( void * ) V_129 ;
F_26 ( V_6 ) ;
}
}
void F_77 ( struct V_26 * V_27 )
{
if ( V_27 -> V_120 != NULL )
F_78 ( V_27 ) ;
F_72 ( V_27 ) ;
F_73 ( V_27 ) ;
}
static int F_79 ( struct V_35 * V_6 )
{
return 0 ;
}
T_1 F_80 ( void * V_130 , const struct V_50 * V_102 ,
T_1 V_21 , T_1 V_131 )
{
struct V_35 * V_6 = V_130 ;
T_1 V_63 = V_102 -> V_63 ;
if ( V_102 -> V_62 & V_59 ) {
if ( F_79 ( V_6 ) )
return V_63 ;
if ( V_63 & 0x300 )
V_63 = ( V_63 + 0x3ff ) & ~ 0x3ff ;
}
return V_63 ;
}
static int T_10 F_81 ( struct V_50 * V_30 ,
struct V_50 * V_102 )
{
struct V_50 * V_132 , * * V_133 ;
struct V_50 * * V_134 = NULL ;
for ( V_133 = & V_30 -> V_135 ; ( V_132 = * V_133 ) != NULL ; V_133 = & V_132 -> V_136 ) {
if ( V_132 -> V_65 < V_102 -> V_63 )
continue;
if ( V_102 -> V_65 < V_132 -> V_63 )
break;
if ( V_132 -> V_63 < V_102 -> V_63 || V_132 -> V_65 > V_102 -> V_65 )
return - 1 ;
if ( V_134 == NULL )
V_134 = V_133 ;
}
if ( V_134 == NULL )
return - 1 ;
V_102 -> V_30 = V_30 ;
V_102 -> V_135 = * V_134 ;
V_102 -> V_136 = * V_133 ;
* V_134 = V_102 ;
* V_133 = NULL ;
for ( V_132 = V_102 -> V_135 ; V_132 != NULL ; V_132 = V_132 -> V_136 ) {
V_132 -> V_30 = V_102 ;
F_27 ( L_35 ,
V_132 -> V_137 ,
( unsigned long long ) V_132 -> V_63 ,
( unsigned long long ) V_132 -> V_65 , V_102 -> V_137 ) ;
}
return 0 ;
}
static void F_82 ( struct V_26 * V_27 )
{
struct V_26 * V_138 ;
int V_55 ;
struct V_50 * V_102 , * V_139 ;
F_27 ( L_36 ,
F_16 ( V_27 ) , V_27 -> V_87 ) ;
F_71 (bus, res, i) {
if ( ! V_102 || ! V_102 -> V_62
|| V_102 -> V_63 > V_102 -> V_65 || V_102 -> V_30 )
continue;
if ( V_27 -> V_30 == NULL )
V_139 = ( V_102 -> V_62 & V_59 ) ?
& V_140 : & V_141 ;
else {
V_139 = F_83 ( V_27 -> V_120 , V_102 ) ;
if ( V_139 == V_102 ) {
continue;
}
}
F_27 ( L_37 ,
V_27 -> V_120 ? F_28 ( V_27 -> V_120 ) : L_34 ,
V_27 -> V_87 , V_55 ,
( unsigned long long ) V_102 -> V_63 ,
( unsigned long long ) V_102 -> V_65 ) ;
F_27 ( L_38 ,
( unsigned int ) V_102 -> V_62 ,
V_139 , ( V_139 && V_139 -> V_137 ) ? V_139 -> V_137 : L_39 ) ;
if ( V_139 && ! ( V_139 -> V_62 & V_119 ) ) {
if ( F_84 ( V_139 , V_102 ) == 0 )
continue;
if ( F_81 ( V_139 , V_102 ) == 0 )
continue;
}
F_85 ( L_40 ) ;
F_86 ( L_41 , V_55 , V_27 -> V_87 ) ;
V_102 -> V_63 = V_102 -> V_65 = 0 ;
V_102 -> V_62 = 0 ;
}
F_14 (b, &bus->children, node)
F_82 ( V_138 ) ;
}
static inline void F_87 ( struct V_35 * V_6 , int V_142 )
{
struct V_50 * V_139 , * V_143 = & V_6 -> V_50 [ V_142 ] ;
F_27 ( L_42 ,
F_28 ( V_6 ) , V_142 ,
( unsigned long long ) V_143 -> V_63 ,
( unsigned long long ) V_143 -> V_65 ,
( unsigned int ) V_143 -> V_62 ) ;
V_139 = F_83 ( V_6 , V_143 ) ;
if ( ! V_139 || ( V_139 -> V_62 & V_119 ) ||
F_84 ( V_139 , V_143 ) < 0 ) {
F_85 ( L_43 , V_142 ) ;
F_86 ( L_44 , F_28 ( V_6 ) ) ;
if ( V_139 )
F_27 ( L_45 ,
V_139 ,
( unsigned long long ) V_139 -> V_63 ,
( unsigned long long ) V_139 -> V_65 ,
( unsigned int ) V_139 -> V_62 ) ;
V_143 -> V_62 |= V_119 ;
V_143 -> V_65 -= V_143 -> V_63 ;
V_143 -> V_63 = 0 ;
}
}
static void T_10 F_88 ( int V_144 )
{
struct V_35 * V_6 = NULL ;
int V_142 , V_145 ;
V_86 V_121 ;
struct V_50 * V_143 ;
F_41 (dev) {
F_69 ( V_6 , V_122 , & V_121 ) ;
for ( V_142 = 0 ; V_142 <= V_60 ; V_142 ++ ) {
V_143 = & V_6 -> V_50 [ V_142 ] ;
if ( V_143 -> V_30 )
continue;
if ( ! V_143 -> V_62 || ( V_143 -> V_62 & V_119 ) )
continue;
if ( V_142 == V_60 )
V_145 = 1 ;
if ( V_143 -> V_62 & V_59 )
V_145 = ! ( V_121 & V_124 ) ;
else
V_145 = ! ( V_121 & V_123 ) ;
if ( V_144 == V_145 )
F_87 ( V_6 , V_142 ) ;
}
if ( V_144 )
continue;
V_143 = & V_6 -> V_50 [ V_60 ] ;
if ( V_143 -> V_62 ) {
T_8 V_146 ;
F_89 ( V_6 , V_6 -> V_147 , & V_146 ) ;
if ( V_146 & V_148 ) {
F_27 ( L_46 ,
F_28 ( V_6 ) ) ;
V_143 -> V_62 &= ~ V_149 ;
F_90 ( V_6 , V_6 -> V_147 ,
V_146 & ~ V_148 ) ;
}
}
}
}
static void T_10 F_91 ( struct V_26 * V_27 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
T_1 V_51 ;
struct V_50 * V_102 , * V_150 ;
int V_55 ;
F_27 ( L_47 ,
F_16 ( V_27 ) ) ;
if ( ! ( V_17 -> V_18 . V_62 & V_59 ) )
goto V_151;
V_51 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_102 = F_92 ( sizeof( struct V_50 ) , V_8 ) ;
F_93 ( V_102 == NULL ) ;
V_102 -> V_137 = L_48 ;
V_102 -> V_62 = V_59 ;
V_102 -> V_63 = V_51 ;
V_102 -> V_65 = ( V_51 + 0xfff ) & 0xfffffffful ;
F_27 ( L_49 , V_102 ) ;
if ( F_84 ( & V_17 -> V_18 , V_102 ) ) {
F_27 ( L_50 ,
F_16 ( V_27 ) , V_27 -> V_87 , V_102 ) ;
F_10 ( V_102 ) ;
}
V_151:
V_51 = V_17 -> V_115 ;
F_27 ( L_51 , ( unsigned long long ) V_51 ) ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
V_150 = & V_17 -> V_116 [ V_55 ] ;
if ( ! ( V_150 -> V_62 & V_58 ) )
continue;
F_27 ( L_52 , V_150 ) ;
if ( ( V_150 -> V_63 - V_51 ) <= 0xa0000 &&
( V_150 -> V_65 - V_51 ) >= 0xbffff )
break;
}
if ( V_55 >= 3 )
return;
V_102 = F_92 ( sizeof( struct V_50 ) , V_8 ) ;
F_93 ( V_102 == NULL ) ;
V_102 -> V_137 = L_53 ;
V_102 -> V_62 = V_58 ;
V_102 -> V_63 = 0xa0000 + V_51 ;
V_102 -> V_65 = 0xbffff + V_51 ;
F_27 ( L_54 , V_102 ) ;
if ( F_84 ( V_150 , V_102 ) ) {
F_27 ( L_55 ,
F_16 ( V_27 ) , V_27 -> V_87 , V_102 ) ;
F_10 ( V_102 ) ;
}
}
void T_10 F_94 ( void )
{
struct V_26 * V_138 ;
F_14 (b, &pci_root_buses, node)
F_82 ( V_138 ) ;
F_88 ( 0 ) ;
F_88 ( 1 ) ;
F_14 (b, &pci_root_buses, node)
F_91 ( V_138 ) ;
F_27 ( L_56 ) ;
F_95 () ;
}
void F_96 ( struct V_26 * V_27 )
{
struct V_35 * V_6 ;
struct V_26 * V_152 ;
F_14 (dev, &bus->devices, bus_list) {
int V_55 ;
for ( V_55 = 0 ; V_55 < V_153 ; V_55 ++ ) {
struct V_50 * V_143 = & V_6 -> V_50 [ V_55 ] ;
if ( V_143 -> V_30 || ! V_143 -> V_63 || ! V_143 -> V_62 )
continue;
F_27 ( L_57 , F_28 ( V_6 ) ) ;
F_27 ( L_58 ,
V_55 , ( unsigned long long ) V_143 -> V_63 ,
( unsigned long long ) V_143 -> V_65 ,
( unsigned int ) V_143 -> V_62 ) ;
F_97 ( V_6 , V_55 ) ;
}
}
F_14 (child_bus, &bus->children, node)
F_96 ( V_152 ) ;
}
void F_98 ( struct V_26 * V_27 )
{
F_27 ( L_59 ,
F_16 ( V_27 ) , V_27 -> V_87 ) ;
F_82 ( V_27 ) ;
F_96 ( V_27 ) ;
F_99 ( V_27 ) ;
}
int F_100 ( struct V_35 * V_6 , int V_154 )
{
return F_101 ( V_6 , V_154 ) ;
}
static void F_102 ( struct V_4 * V_17 ,
struct V_155 * V_156 )
{
unsigned long V_54 ;
struct V_50 * V_102 ;
int V_55 ;
V_102 = & V_17 -> V_18 ;
V_54 = ( unsigned long ) V_17 -> V_22 - V_113 ;
V_102 -> V_63 = ( V_102 -> V_63 + V_54 ) & 0xffffffffu ;
V_102 -> V_65 = ( V_102 -> V_65 + V_54 ) & 0xffffffffu ;
if ( ! V_102 -> V_62 ) {
F_85 ( L_60 ) ;
F_86 ( L_61 ,
V_17 -> V_14 -> V_38 , V_17 -> V_10 ) ;
V_102 -> V_63 = ( unsigned long ) V_17 -> V_22 - V_113 ;
V_102 -> V_65 = V_102 -> V_63 + V_157 ;
V_102 -> V_62 = V_59 ;
}
F_103 ( V_156 , V_102 ,
( V_158 T_1 ) ( V_17 -> V_22 - V_25 ) ) ;
F_27 ( L_62 ,
( unsigned long long ) V_102 -> V_63 ,
( unsigned long long ) V_102 -> V_65 ,
( unsigned long ) V_102 -> V_62 ) ;
for ( V_55 = 0 ; V_55 < 3 ; ++ V_55 ) {
V_102 = & V_17 -> V_116 [ V_55 ] ;
if ( ! V_102 -> V_62 ) {
if ( V_55 > 0 )
continue;
F_67 ( L_63 ) ;
F_86 ( L_64 ,
V_17 -> V_14 -> V_38 , V_17 -> V_10 ) ;
V_102 -> V_63 = V_17 -> V_115 ;
V_102 -> V_65 = ( T_1 ) - 1LL ;
V_102 -> V_62 = V_58 ;
}
F_103 ( V_156 , V_102 , V_17 -> V_115 ) ;
F_27 ( L_65 ,
V_55 , ( unsigned long long ) V_102 -> V_63 ,
( unsigned long long ) V_102 -> V_65 ,
( unsigned long ) V_102 -> V_62 ) ;
}
F_27 ( L_66 ,
( unsigned long long ) V_17 -> V_115 ) ;
F_27 ( L_67 ,
( unsigned long ) V_17 -> V_22 - V_25 ) ;
}
struct V_5 * F_104 ( struct V_26 * V_27 )
{
struct V_4 * V_17 = V_27 -> V_159 ;
return F_105 ( V_17 -> V_14 ) ;
}
static void F_106 ( struct V_4 * V_17 )
{
F_107 ( V_156 ) ;
struct V_26 * V_27 ;
struct V_5 * V_28 = V_17 -> V_14 ;
F_27 ( L_68 , F_34 ( V_28 ) ) ;
F_102 ( V_17 , & V_156 ) ;
V_27 = F_108 ( V_17 -> V_30 , V_17 -> V_160 ,
V_17 -> V_161 , V_17 , & V_156 ) ;
if ( V_27 == NULL ) {
F_67 ( L_69 ,
V_17 -> V_10 ) ;
F_109 ( & V_156 ) ;
return;
}
V_27 -> V_162 . V_63 = V_17 -> V_160 ;
V_17 -> V_27 = V_27 ;
V_17 -> V_163 = V_27 -> V_162 . V_65 ;
}
static int T_10 F_110 ( void )
{
struct V_4 * V_17 , * V_29 ;
int V_164 = 0 ;
F_60 ( L_70 ) ;
F_19 (hose, tmp, &hose_list, list_node) {
V_17 -> V_163 = 0xff ;
F_106 ( V_17 ) ;
if ( V_164 <= V_17 -> V_163 )
V_164 = V_17 -> V_163 + 1 ;
}
V_165 = V_164 ;
F_94 () ;
return 0 ;
}
static struct V_4 * F_111 ( int V_27 )
{
struct V_4 * V_17 , * V_29 ;
F_19 (hose, tmp, &hose_list, list_node)
if ( V_27 >= V_17 -> V_160 && V_27 <= V_17 -> V_163 )
return V_17 ;
return NULL ;
}
long F_112 ( long V_166 , unsigned long V_27 , unsigned long V_167 )
{
struct V_4 * V_17 ;
long V_168 = - V_169 ;
V_17 = F_111 ( V_27 ) ;
if ( ! V_17 )
return - V_170 ;
switch ( V_166 ) {
case V_171 :
return ( long ) V_17 -> V_160 ;
case V_172 :
return ( long ) V_17 -> V_115 ;
case V_173 :
return ( long ) V_17 -> V_23 ;
case V_174 :
return ( long ) V_113 ;
case V_175 :
return ( long ) V_114 ;
}
return V_168 ;
}
static int
F_113 ( struct V_26 * V_27 , unsigned int V_167 , int V_51 ,
int V_176 , T_8 * V_83 )
{
return V_177 ;
}
static int
F_114 ( struct V_26 * V_27 , unsigned int V_167 , int V_51 ,
int V_176 , T_8 V_83 )
{
return V_177 ;
}
static struct V_26 *
F_115 ( struct V_4 * V_17 , int V_178 )
{
static struct V_26 V_27 ;
if ( ! V_17 )
F_67 ( L_71 , V_178 ) ;
V_27 . V_87 = V_178 ;
V_27 . V_159 = V_17 ;
V_27 . V_161 = V_17 ? V_17 -> V_161 : & V_179 ;
return & V_27 ;
}
int F_116 ( struct V_4 * V_17 , int V_27 , int V_167 ,
int V_180 )
{
return F_117 ( F_115 ( V_17 , V_27 ) , V_167 , V_180 ) ;
}
