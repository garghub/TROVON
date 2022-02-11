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
char T_5 * F_26 ( char * V_40 )
{
return V_40 ;
}
int F_27 ( struct V_35 * V_35 )
{
struct V_41 V_42 ;
unsigned int V_43 ;
F_28 ( L_2 , F_29 ( V_35 ) ) ;
#ifdef F_30
memset ( & V_42 , 0xff , sizeof( V_42 ) ) ;
#endif
if ( F_31 ( V_35 , & V_42 ) ) {
T_6 line , V_44 ;
if ( F_32 ( V_35 , V_45 , & V_44 ) )
return - 1 ;
if ( V_44 == 0 )
return - 1 ;
if ( F_32 ( V_35 , V_46 , & line ) ||
line == 0xff || line == 0 ) {
return - 1 ;
}
F_28 ( L_3 ,
line , V_44 ) ;
V_43 = F_33 ( NULL , line ) ;
if ( V_43 )
F_34 ( V_43 , V_47 ) ;
} else {
F_28 ( L_4 ,
V_42 . V_21 , V_42 . V_48 [ 0 ] , V_42 . V_48 [ 1 ] ,
V_42 . V_49 ? V_42 . V_49 -> V_38 :
L_5 ) ;
V_43 = F_35 ( V_42 . V_49 , V_42 . V_48 ,
V_42 . V_21 ) ;
}
if ( ! V_43 ) {
F_28 ( L_6 ) ;
return - 1 ;
}
F_28 ( L_7 , V_43 ) ;
V_35 -> V_50 = V_43 ;
return 0 ;
}
static struct V_51 * F_36 ( struct V_35 * V_6 ,
T_1 * V_52 ,
enum V_53 V_54 )
{
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
unsigned long V_55 = 0 ;
int V_56 , V_57 ;
if ( V_17 == 0 )
return NULL ;
if ( V_54 == V_58 ) {
#if 0
*offset += hose->pci_mem_offset;
#endif
V_57 = V_59 ;
} else {
V_55 = ( unsigned long ) V_17 -> V_22 - V_25 ;
* V_52 += V_55 ;
V_57 = V_60 ;
}
for ( V_56 = 0 ; V_56 <= V_61 ; V_56 ++ ) {
struct V_51 * V_62 = & V_6 -> V_51 [ V_56 ] ;
int V_63 = V_62 -> V_63 ;
if ( V_56 == V_61 )
V_63 |= V_59 ;
if ( ( V_63 & V_57 ) == 0 )
continue;
if ( * V_52 < ( V_62 -> V_64 & V_65 ) || * V_52 > V_62 -> V_66 )
continue;
if ( V_54 == V_67 )
* V_52 += V_17 -> V_23 - V_55 ;
return V_62 ;
}
return NULL ;
}
static T_7 F_37 ( struct V_35 * V_6 , struct V_51 * V_62 ,
T_7 V_68 ,
enum V_53 V_54 ,
int V_69 )
{
T_7 V_70 = V_68 ;
if ( V_54 != V_58 )
V_69 = 0 ;
else if ( V_69 == 0 ) {
if ( V_62 -> V_63 & V_71 )
V_69 = 1 ;
}
return F_38 ( V_70 ) ;
}
T_7 F_39 ( struct V_72 * V_72 ,
unsigned long V_73 ,
unsigned long V_21 ,
T_7 V_70 )
{
struct V_35 * V_36 = NULL ;
struct V_51 * V_74 = NULL ;
T_1 V_52 = ( ( T_1 ) V_73 ) << V_75 ;
int V_56 ;
if ( F_40 ( V_73 ) )
return V_70 ;
V_70 = F_38 ( V_70 ) ;
F_41 (pdev) {
for ( V_56 = 0 ; V_56 <= V_61 ; V_56 ++ ) {
struct V_51 * V_62 = & V_36 -> V_51 [ V_56 ] ;
int V_63 = V_62 -> V_63 ;
if ( ( V_63 & V_59 ) == 0 )
continue;
if ( V_52 < ( V_62 -> V_64 & V_65 ) ||
V_52 > V_62 -> V_66 )
continue;
V_74 = V_62 ;
break;
}
if ( V_74 )
break;
}
if ( V_74 ) {
if ( V_74 -> V_63 & V_71 )
V_70 = F_42 ( V_70 ) ;
F_43 ( V_36 ) ;
}
F_28 ( L_8 ,
( unsigned long long ) V_52 , F_44 ( V_70 ) ) ;
return V_70 ;
}
int F_45 ( struct V_35 * V_6 , struct V_76 * V_77 ,
enum V_53 V_54 , int V_69 )
{
T_1 V_52 =
( ( T_1 ) V_77 -> V_78 ) << V_75 ;
struct V_51 * V_62 ;
int V_20 ;
V_62 = F_36 ( V_6 , & V_52 , V_54 ) ;
if ( V_62 == NULL )
return - V_79 ;
V_77 -> V_78 = V_52 >> V_75 ;
V_77 -> V_80 = F_37 ( V_6 , V_62 ,
V_77 -> V_80 ,
V_54 , V_69 ) ;
V_20 = F_46 ( V_77 , V_77 -> V_81 , V_77 -> V_78 ,
V_77 -> V_82 - V_77 -> V_81 , V_77 -> V_80 ) ;
return V_20 ;
}
int F_47 ( struct V_26 * V_27 , T_8 V_83 , T_9 * V_84 , T_10 V_21 )
{
unsigned long V_52 ;
struct V_4 * V_17 = F_17 ( V_27 ) ;
struct V_51 * V_62 = & V_17 -> V_18 ;
void T_2 * V_85 ;
V_52 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_52 += V_83 ;
if ( ! ( V_62 -> V_63 & V_60 ) )
return - V_86 ;
if ( V_52 < V_62 -> V_64 || ( V_52 + V_21 ) > V_62 -> V_66 )
return - V_86 ;
V_85 = V_17 -> V_22 + V_83 ;
switch ( V_21 ) {
case 1 :
* ( ( T_6 * ) V_84 ) = F_48 ( V_85 ) ;
return 1 ;
case 2 :
if ( V_83 & 1 )
return - V_79 ;
* ( ( V_87 * ) V_84 ) = F_49 ( V_85 ) ;
return 2 ;
case 4 :
if ( V_83 & 3 )
return - V_79 ;
* ( ( T_9 * ) V_84 ) = F_50 ( V_85 ) ;
return 4 ;
}
return - V_79 ;
}
int F_51 ( struct V_26 * V_27 , T_8 V_83 , T_9 V_84 , T_10 V_21 )
{
unsigned long V_52 ;
struct V_4 * V_17 = F_17 ( V_27 ) ;
struct V_51 * V_62 = & V_17 -> V_18 ;
void T_2 * V_85 ;
V_52 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_52 += V_83 ;
if ( ! ( V_62 -> V_63 & V_60 ) )
return - V_86 ;
if ( V_52 < V_62 -> V_64 || ( V_52 + V_21 ) > V_62 -> V_66 )
return - V_86 ;
V_85 = V_17 -> V_22 + V_83 ;
switch ( V_21 ) {
case 1 :
F_52 ( V_85 , V_84 >> 24 ) ;
return 1 ;
case 2 :
if ( V_83 & 1 )
return - V_79 ;
F_53 ( V_85 , V_84 >> 16 ) ;
return 2 ;
case 4 :
if ( V_83 & 3 )
return - V_79 ;
F_54 ( V_85 , V_84 ) ;
return 4 ;
}
return - V_79 ;
}
int F_55 ( struct V_26 * V_27 ,
struct V_76 * V_77 ,
enum V_53 V_54 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
T_1 V_52 =
( ( T_1 ) V_77 -> V_78 ) << V_75 ;
T_1 V_21 = V_77 -> V_82 - V_77 -> V_81 ;
struct V_51 * V_62 ;
F_28 ( L_9 ,
F_16 ( V_27 ) , V_27 -> V_88 ,
V_54 == V_58 ? L_10 : L_11 ,
( unsigned long long ) V_52 ,
( unsigned long long ) ( V_52 + V_21 - 1 ) ) ;
if ( V_54 == V_58 ) {
if ( ( V_52 + V_21 ) > V_17 -> V_89 ) {
#ifdef F_56
F_57 ( V_90
L_12
L_13 ,
V_91 -> V_92 , V_91 -> V_93 , F_16 ( V_27 ) ,
V_27 -> V_88 ) ;
#endif
if ( V_77 -> V_94 & V_95 )
return F_58 ( V_77 ) ;
return 0 ;
}
V_52 += V_17 -> V_96 ;
} else {
unsigned long V_55 = ( unsigned long ) V_17 -> V_22 - \
V_25 ;
unsigned long V_97 = V_52 + V_55 ;
V_62 = & V_17 -> V_18 ;
if ( ! ( V_62 -> V_63 & V_60 ) )
return - V_86 ;
if ( V_97 < V_62 -> V_64 || ( V_97 + V_21 ) > V_62 -> V_66 )
return - V_86 ;
V_52 += V_17 -> V_23 ;
}
F_28 ( L_14 , ( unsigned long long ) V_52 ) ;
V_77 -> V_78 = V_52 >> V_75 ;
V_77 -> V_80 = F_38 ( V_77 -> V_80 ) ;
return F_46 ( V_77 , V_77 -> V_81 , V_77 -> V_78 ,
V_77 -> V_82 - V_77 -> V_81 ,
V_77 -> V_80 ) ;
}
void F_59 ( const struct V_35 * V_6 , int V_98 ,
const struct V_51 * V_99 ,
T_1 * V_64 , T_1 * V_66 )
{
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
T_1 V_52 = 0 ;
if ( V_17 == NULL )
return;
if ( V_99 -> V_63 & V_60 )
V_52 = ( unsigned long ) V_17 -> V_22 - V_25 ;
#if 0
else if (rsrc->flags & IORESOURCE_MEM)
offset = hose->pci_mem_offset;
#endif
* V_64 = V_99 -> V_64 - V_52 ;
* V_66 = V_99 -> V_66 - V_52 ;
}
void T_5 F_60 ( struct V_4 * V_17 ,
struct V_5 * V_6 ,
int V_100 )
{
const T_9 * V_101 ;
int V_102 ;
int V_103 = F_61 ( V_6 ) ;
int V_37 = V_103 + 5 ;
int V_104 = 0 , V_105 = - 1 ;
T_9 V_106 ;
unsigned long long V_107 , V_108 , V_109 , V_110 , V_21 ;
unsigned long long V_111 = 0 ;
struct V_51 * V_112 ;
F_57 ( V_113 L_15 ,
V_6 -> V_38 , V_100 ? L_16 : L_17 ) ;
V_101 = F_62 ( V_6 , L_18 , & V_102 ) ;
if ( V_101 == NULL )
return;
F_28 ( L_19 ) ;
while ( ( V_102 -= V_37 * 4 ) >= 0 ) {
V_106 = V_101 [ 0 ] ;
V_107 = F_63 ( V_101 + 1 , 2 ) ;
V_108 = F_64 ( V_6 , V_101 + 3 ) ;
V_21 = F_63 ( V_101 + V_103 + 3 , 2 ) ;
F_28 ( L_20
L_21 ,
V_106 , V_107 , V_108 , V_21 ) ;
V_101 += V_37 ;
if ( V_108 == V_114 || V_21 == 0 )
continue;
for (; V_102 >= V_37 * sizeof( T_9 ) ;
V_101 += V_37 , V_102 -= V_37 * 4 ) {
if ( V_101 [ 0 ] != V_106 )
break;
V_109 = F_63 ( V_101 + 1 , 2 ) ;
V_110 = F_64 ( V_6 , V_101 + 3 ) ;
if ( V_109 != V_107 + V_21 ||
V_110 != V_108 + V_21 )
break;
V_21 += F_63 ( V_101 + V_103 + 3 , 2 ) ;
}
V_112 = NULL ;
switch ( ( V_106 >> 24 ) & 0x3 ) {
case 1 :
F_57 ( V_113
L_22 ,
V_108 , V_108 + V_21 - 1 , V_107 ) ;
if ( V_17 -> V_115 ) {
F_57 ( V_113
L_23 ) ;
continue;
}
if ( V_21 > 0x01000000 )
V_21 = 0x01000000 ;
V_17 -> V_22 = F_65 ( V_108 , V_21 ) ;
if ( V_100 )
V_116 =
( unsigned long ) V_17 -> V_22 ;
V_17 -> V_115 = V_107 + V_21 ;
V_17 -> V_23 = V_108 - V_107 ;
V_112 = & V_17 -> V_18 ;
V_112 -> V_63 = V_60 ;
V_112 -> V_64 = V_107 ;
break;
case 2 :
case 3 :
F_57 ( V_113
L_24 ,
V_108 , V_108 + V_21 - 1 , V_107 ,
( V_106 & 0x40000000 ) ? L_25 : L_17 ) ;
if ( V_104 >= 3 ) {
F_57 ( V_113
L_23 ) ;
continue;
}
if ( V_107 == 0 ) {
V_111 = V_108 ;
V_105 = V_104 ;
if ( V_100 || V_117 == 0 )
V_117 = V_108 ;
V_17 -> V_96 = V_108 ;
V_17 -> V_89 = V_21 ;
}
if ( V_104 == 0 ||
( V_105 >= 0 && V_107 != 0 &&
V_17 -> V_118 == V_111 ) )
V_17 -> V_118 = V_108 - V_107 ;
else if ( V_107 != 0 &&
V_17 -> V_118 != V_108 - V_107 ) {
F_57 ( V_113
L_26 ) ;
continue;
}
V_112 = & V_17 -> V_119 [ V_104 ++ ] ;
V_112 -> V_63 = V_59 ;
if ( V_106 & 0x40000000 )
V_112 -> V_63 |= V_71 ;
V_112 -> V_64 = V_108 ;
break;
}
if ( V_112 != NULL ) {
V_112 -> V_120 = V_6 -> V_38 ;
V_112 -> V_66 = V_112 -> V_64 + V_21 - 1 ;
V_112 -> V_30 = NULL ;
V_112 -> V_121 = NULL ;
V_112 -> V_122 = NULL ;
}
}
if ( V_105 >= 0 && V_17 -> V_118 != V_111 ) {
unsigned int V_123 = V_105 + 1 ;
F_57 ( V_113 L_27 , V_111 ) ;
if ( V_123 < V_104 )
memmove ( & V_17 -> V_119 [ V_105 ] ,
& V_17 -> V_119 [ V_123 ] ,
sizeof( struct V_51 ) * ( V_104 - V_123 ) ) ;
V_17 -> V_119 [ -- V_104 ] . V_63 = 0 ;
}
}
int F_66 ( struct V_26 * V_27 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
return 0 ;
}
static void T_5 F_67 ( struct V_35 * V_6 )
{
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
int V_56 ;
if ( ! V_17 ) {
F_57 ( V_124 L_28 ,
F_29 ( V_6 ) ) ;
return;
}
for ( V_56 = 0 ; V_56 < V_125 ; V_56 ++ ) {
struct V_51 * V_112 = V_6 -> V_51 + V_56 ;
if ( ! V_112 -> V_63 )
continue;
if ( V_112 -> V_64 == 0 ) {
F_28 ( L_29 \
L_30 ,
F_29 ( V_6 ) , V_56 ,
( unsigned long long ) V_112 -> V_64 ,
( unsigned long long ) V_112 -> V_66 ,
( unsigned int ) V_112 -> V_63 ) ;
V_112 -> V_66 -= V_112 -> V_64 ;
V_112 -> V_64 = 0 ;
V_112 -> V_63 |= V_126 ;
continue;
}
F_28 ( L_31 ,
F_29 ( V_6 ) , V_56 ,
( unsigned long long ) V_112 -> V_64 ,\
( unsigned long long ) V_112 -> V_66 ,
( unsigned int ) V_112 -> V_63 ) ;
}
}
static int T_5 F_68 ( struct V_26 * V_27 ,
struct V_51 * V_112 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
struct V_35 * V_6 = V_27 -> V_127 ;
T_1 V_52 ;
V_87 V_128 ;
int V_56 ;
if ( V_112 -> V_63 & V_59 ) {
if ( V_112 -> V_64 != V_17 -> V_118 )
return 0 ;
F_69 ( V_6 , V_129 , & V_128 ) ;
if ( ( V_128 & V_130 ) == 0 )
return 1 ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
if ( ( V_17 -> V_119 [ V_56 ] . V_63 & V_59 ) &&
V_17 -> V_119 [ V_56 ] . V_64 == V_17 -> V_118 )
return 0 ;
}
return 1 ;
} else {
V_52 = ( unsigned long ) V_17 -> V_22 - V_25 ;
if ( ( ( V_112 -> V_64 - V_52 ) & 0xfffffffful ) != 0 )
return 0 ;
F_69 ( V_6 , V_129 , & V_128 ) ;
if ( V_128 & V_131 )
return 0 ;
return 1 ;
}
}
static void T_5 F_70 ( struct V_26 * V_27 )
{
struct V_51 * V_112 ;
int V_56 ;
struct V_35 * V_6 = V_27 -> V_127 ;
F_71 (bus, res, i) {
if ( ! V_112 )
continue;
if ( ! V_112 -> V_63 )
continue;
if ( V_56 >= 3 && V_27 -> V_127 -> V_132 )
continue;
F_28 ( L_32 ,
F_29 ( V_6 ) , V_56 ,
( unsigned long long ) V_112 -> V_64 ,\
( unsigned long long ) V_112 -> V_66 ,
( unsigned int ) V_112 -> V_63 ) ;
if ( F_68 ( V_27 , V_112 ) ) {
V_112 -> V_63 = 0 ;
F_28 ( L_33 ,
F_29 ( V_6 ) ) ;
} else {
F_28 ( L_34 ,
F_29 ( V_6 ) ,
( unsigned long long ) V_112 -> V_64 ,
( unsigned long long ) V_112 -> V_66 ) ;
}
}
}
void T_5 F_72 ( struct V_26 * V_27 )
{
if ( V_27 -> V_127 != NULL )
F_70 ( V_27 ) ;
}
void T_5 F_73 ( struct V_26 * V_27 )
{
struct V_35 * V_6 ;
F_28 ( L_35 ,
V_27 -> V_88 , V_27 -> V_127 ? F_29 ( V_27 -> V_127 ) : L_36 ) ;
F_14 (dev, &bus->devices, bus_list) {
V_6 -> V_6 . V_133 = F_22 ( V_6 ) ;
F_74 ( & V_6 -> V_6 , F_75 ( V_6 -> V_27 ) ) ;
F_76 ( & V_6 -> V_6 , V_3 ) ;
V_6 -> V_6 . V_134 . V_135 = ( void * ) V_136 ;
F_27 ( V_6 ) ;
}
}
void T_5 F_77 ( struct V_26 * V_27 )
{
if ( V_27 -> V_127 != NULL )
F_78 ( V_27 ) ;
F_72 ( V_27 ) ;
F_73 ( V_27 ) ;
}
static int F_79 ( struct V_35 * V_6 )
{
return 0 ;
}
T_1 F_80 ( void * V_137 , const struct V_51 * V_112 ,
T_1 V_21 , T_1 V_138 )
{
struct V_35 * V_6 = V_137 ;
T_1 V_64 = V_112 -> V_64 ;
if ( V_112 -> V_63 & V_60 ) {
if ( F_79 ( V_6 ) )
return V_64 ;
if ( V_64 & 0x300 )
V_64 = ( V_64 + 0x3ff ) & ~ 0x3ff ;
}
return V_64 ;
}
static int T_11 F_81 ( struct V_51 * V_30 ,
struct V_51 * V_112 )
{
struct V_51 * V_139 , * * V_140 ;
struct V_51 * * V_141 = NULL ;
for ( V_140 = & V_30 -> V_122 ; ( V_139 = * V_140 ) != NULL ; V_140 = & V_139 -> V_121 ) {
if ( V_139 -> V_66 < V_112 -> V_64 )
continue;
if ( V_112 -> V_66 < V_139 -> V_64 )
break;
if ( V_139 -> V_64 < V_112 -> V_64 || V_139 -> V_66 > V_112 -> V_66 )
return - 1 ;
if ( V_141 == NULL )
V_141 = V_140 ;
}
if ( V_141 == NULL )
return - 1 ;
V_112 -> V_30 = V_30 ;
V_112 -> V_122 = * V_141 ;
V_112 -> V_121 = * V_140 ;
* V_141 = V_112 ;
* V_140 = NULL ;
for ( V_139 = V_112 -> V_122 ; V_139 != NULL ; V_139 = V_139 -> V_121 ) {
V_139 -> V_30 = V_112 ;
F_28 ( L_37 ,
V_139 -> V_120 ,
( unsigned long long ) V_139 -> V_64 ,
( unsigned long long ) V_139 -> V_66 , V_112 -> V_120 ) ;
}
return 0 ;
}
void F_82 ( struct V_26 * V_27 )
{
struct V_26 * V_142 ;
int V_56 ;
struct V_51 * V_112 , * V_143 ;
F_28 ( L_38 ,
F_16 ( V_27 ) , V_27 -> V_88 ) ;
F_71 (bus, res, i) {
if ( ! V_112 || ! V_112 -> V_63
|| V_112 -> V_64 > V_112 -> V_66 || V_112 -> V_30 )
continue;
if ( V_27 -> V_30 == NULL )
V_143 = ( V_112 -> V_63 & V_60 ) ?
& V_144 : & V_145 ;
else {
V_143 = F_83 ( V_27 -> V_127 , V_112 ) ;
if ( V_143 == V_112 ) {
continue;
}
}
F_28 ( L_39
L_40 ,
V_27 -> V_127 ? F_29 ( V_27 -> V_127 ) : L_36 ,
V_27 -> V_88 , V_56 ,
( unsigned long long ) V_112 -> V_64 ,
( unsigned long long ) V_112 -> V_66 ,
( unsigned int ) V_112 -> V_63 ,
V_143 , ( V_143 && V_143 -> V_120 ) ? V_143 -> V_120 : L_41 ) ;
if ( V_143 && ! ( V_143 -> V_63 & V_126 ) ) {
if ( F_84 ( V_143 , V_112 ) == 0 )
continue;
if ( F_81 ( V_143 , V_112 ) == 0 )
continue;
}
F_57 ( V_146 L_42
L_43 , V_56 , V_27 -> V_88 ) ;
V_147:
V_112 -> V_64 = V_112 -> V_66 = 0 ;
V_112 -> V_63 = 0 ;
}
F_14 (b, &bus->children, node)
F_82 ( V_142 ) ;
}
static inline void T_5 F_85 ( struct V_35 * V_6 , int V_148 )
{
struct V_51 * V_143 , * V_149 = & V_6 -> V_51 [ V_148 ] ;
F_28 ( L_44 ,
F_29 ( V_6 ) , V_148 ,
( unsigned long long ) V_149 -> V_64 ,
( unsigned long long ) V_149 -> V_66 ,
( unsigned int ) V_149 -> V_63 ) ;
V_143 = F_83 ( V_6 , V_149 ) ;
if ( ! V_143 || ( V_143 -> V_63 & V_126 ) ||
F_84 ( V_143 , V_149 ) < 0 ) {
F_57 ( V_146 L_45
L_46 , V_148 , F_29 ( V_6 ) ) ;
if ( V_143 )
F_28 ( L_47 ,
V_143 ,
( unsigned long long ) V_143 -> V_64 ,
( unsigned long long ) V_143 -> V_66 ,
( unsigned int ) V_143 -> V_63 ) ;
V_149 -> V_63 |= V_126 ;
V_149 -> V_66 -= V_149 -> V_64 ;
V_149 -> V_64 = 0 ;
}
}
static void T_11 F_86 ( int V_150 )
{
struct V_35 * V_6 = NULL ;
int V_148 , V_151 ;
V_87 V_128 ;
struct V_51 * V_149 ;
F_41 (dev) {
F_69 ( V_6 , V_129 , & V_128 ) ;
for ( V_148 = 0 ; V_148 <= V_61 ; V_148 ++ ) {
V_149 = & V_6 -> V_51 [ V_148 ] ;
if ( V_149 -> V_30 )
continue;
if ( ! V_149 -> V_63 || ( V_149 -> V_63 & V_126 ) )
continue;
if ( V_148 == V_61 )
V_151 = 1 ;
if ( V_149 -> V_63 & V_60 )
V_151 = ! ( V_128 & V_131 ) ;
else
V_151 = ! ( V_128 & V_130 ) ;
if ( V_150 == V_151 )
F_85 ( V_6 , V_148 ) ;
}
if ( V_150 )
continue;
V_149 = & V_6 -> V_51 [ V_61 ] ;
if ( V_149 -> V_63 ) {
T_9 V_152 ;
F_87 ( V_6 , V_6 -> V_153 , & V_152 ) ;
if ( V_152 & V_154 ) {
F_28 ( L_48 ,
F_29 ( V_6 ) ) ;
V_149 -> V_63 &= ~ V_155 ;
F_88 ( V_6 , V_6 -> V_153 ,
V_152 & ~ V_154 ) ;
}
}
}
}
static void T_11 F_89 ( struct V_26 * V_27 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
T_1 V_52 ;
struct V_51 * V_112 , * V_156 ;
int V_56 ;
F_28 ( L_49 ,
F_16 ( V_27 ) ) ;
if ( ! ( V_17 -> V_18 . V_63 & V_60 ) )
goto V_157;
V_52 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_112 = F_90 ( sizeof( struct V_51 ) , V_8 ) ;
F_91 ( V_112 == NULL ) ;
V_112 -> V_120 = L_50 ;
V_112 -> V_63 = V_60 ;
V_112 -> V_64 = V_52 ;
V_112 -> V_66 = ( V_52 + 0xfff ) & 0xfffffffful ;
F_28 ( L_51 , V_112 ) ;
if ( F_84 ( & V_17 -> V_18 , V_112 ) ) {
F_57 ( V_90
L_52 ,
F_16 ( V_27 ) , V_27 -> V_88 , V_112 ) ;
F_10 ( V_112 ) ;
}
V_157:
V_52 = V_17 -> V_118 ;
F_28 ( L_53 , ( unsigned long long ) V_52 ) ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_156 = & V_17 -> V_119 [ V_56 ] ;
if ( ! ( V_156 -> V_63 & V_59 ) )
continue;
F_28 ( L_54 , V_156 ) ;
if ( ( V_156 -> V_64 - V_52 ) <= 0xa0000 &&
( V_156 -> V_66 - V_52 ) >= 0xbffff )
break;
}
if ( V_56 >= 3 )
return;
V_112 = F_90 ( sizeof( struct V_51 ) , V_8 ) ;
F_91 ( V_112 == NULL ) ;
V_112 -> V_120 = L_55 ;
V_112 -> V_63 = V_59 ;
V_112 -> V_64 = 0xa0000 + V_52 ;
V_112 -> V_66 = 0xbffff + V_52 ;
F_28 ( L_56 , V_112 ) ;
if ( F_84 ( V_156 , V_112 ) ) {
F_57 ( V_90
L_57 ,
F_16 ( V_27 ) , V_27 -> V_88 , V_112 ) ;
F_10 ( V_112 ) ;
}
}
void T_11 F_92 ( void )
{
struct V_26 * V_142 ;
F_14 (b, &pci_root_buses, node)
F_82 ( V_142 ) ;
F_86 ( 0 ) ;
F_86 ( 1 ) ;
F_14 (b, &pci_root_buses, node)
F_89 ( V_142 ) ;
F_28 ( L_58 ) ;
F_93 () ;
}
void T_5 F_94 ( struct V_26 * V_27 )
{
struct V_35 * V_6 ;
struct V_26 * V_158 ;
F_14 (dev, &bus->devices, bus_list) {
int V_56 ;
for ( V_56 = 0 ; V_56 < V_159 ; V_56 ++ ) {
struct V_51 * V_149 = & V_6 -> V_51 [ V_56 ] ;
if ( V_149 -> V_30 || ! V_149 -> V_64 || ! V_149 -> V_63 )
continue;
F_28 ( L_59
L_60 ,
F_29 ( V_6 ) , V_56 ,
( unsigned long long ) V_149 -> V_64 ,
( unsigned long long ) V_149 -> V_66 ,
( unsigned int ) V_149 -> V_63 ) ;
F_95 ( V_6 , V_56 ) ;
}
}
F_14 (child_bus, &bus->children, node)
F_94 ( V_158 ) ;
}
void F_96 ( struct V_26 * V_27 )
{
F_28 ( L_61 ,
F_16 ( V_27 ) , V_27 -> V_88 ) ;
F_82 ( V_27 ) ;
F_94 ( V_27 ) ;
F_97 ( V_27 ) ;
}
int F_98 ( struct V_35 * V_6 , int V_160 )
{
return F_99 ( V_6 , V_160 ) ;
}
static void T_5 F_100 ( struct V_4 * V_17 , struct V_161 * V_162 )
{
unsigned long V_55 ;
struct V_51 * V_112 ;
int V_56 ;
V_112 = & V_17 -> V_18 ;
V_55 = ( unsigned long ) V_17 -> V_22 - V_116 ;
V_112 -> V_64 = ( V_112 -> V_64 + V_55 ) & 0xffffffffu ;
V_112 -> V_66 = ( V_112 -> V_66 + V_55 ) & 0xffffffffu ;
if ( ! V_112 -> V_63 ) {
F_57 ( V_146 L_62
L_63 ,
V_17 -> V_14 -> V_38 , V_17 -> V_10 ) ;
V_112 -> V_64 = ( unsigned long ) V_17 -> V_22 - V_116 ;
V_112 -> V_66 = V_112 -> V_64 + V_163 ;
V_112 -> V_63 = V_60 ;
}
F_101 ( V_162 , V_112 , V_17 -> V_22 - V_25 ) ;
F_28 ( L_64 ,
( unsigned long long ) V_112 -> V_64 ,
( unsigned long long ) V_112 -> V_66 ,
( unsigned long ) V_112 -> V_63 ) ;
for ( V_56 = 0 ; V_56 < 3 ; ++ V_56 ) {
V_112 = & V_17 -> V_119 [ V_56 ] ;
if ( ! V_112 -> V_63 ) {
if ( V_56 > 0 )
continue;
F_57 ( V_124 L_65
L_66 ,
V_17 -> V_14 -> V_38 , V_17 -> V_10 ) ;
V_112 -> V_64 = V_17 -> V_118 ;
V_112 -> V_66 = ( T_1 ) - 1LL ;
V_112 -> V_63 = V_59 ;
}
F_101 ( V_162 , V_112 , V_17 -> V_118 ) ;
F_28 ( L_67 ,
V_56 , ( unsigned long long ) V_112 -> V_64 ,
( unsigned long long ) V_112 -> V_66 ,
( unsigned long ) V_112 -> V_63 ) ;
}
F_28 ( L_68 ,
( unsigned long long ) V_17 -> V_118 ) ;
F_28 ( L_69 ,
( unsigned long ) V_17 -> V_22 - V_25 ) ;
}
struct V_5 * F_102 ( struct V_26 * V_27 )
{
struct V_4 * V_17 = V_27 -> V_164 ;
return F_103 ( V_17 -> V_14 ) ;
}
static void T_5 F_104 ( struct V_4 * V_17 )
{
F_105 ( V_162 ) ;
struct V_26 * V_27 ;
struct V_5 * V_28 = V_17 -> V_14 ;
F_28 ( L_70 ,
V_28 ? V_28 -> V_38 : L_71 ) ;
F_100 ( V_17 , & V_162 ) ;
V_27 = F_106 ( V_17 -> V_30 , V_17 -> V_165 ,
V_17 -> V_166 , V_17 , & V_162 ) ;
if ( V_27 == NULL ) {
F_57 ( V_124 L_72 ,
V_17 -> V_10 ) ;
F_107 ( & V_162 ) ;
return;
}
V_27 -> V_167 = V_17 -> V_165 ;
V_17 -> V_27 = V_27 ;
V_17 -> V_168 = V_27 -> V_169 ;
}
static int T_11 F_108 ( void )
{
struct V_4 * V_17 , * V_29 ;
int V_170 = 0 ;
F_57 ( V_113 L_73 ) ;
F_19 (hose, tmp, &hose_list, list_node) {
V_17 -> V_168 = 0xff ;
F_104 ( V_17 ) ;
if ( V_170 <= V_17 -> V_168 )
V_170 = V_17 -> V_168 + 1 ;
}
V_171 = V_170 ;
F_92 () ;
return 0 ;
}
static struct V_4 * F_109 ( int V_27 )
{
struct V_4 * V_17 , * V_29 ;
F_19 (hose, tmp, &hose_list, list_node)
if ( V_27 >= V_17 -> V_165 && V_27 <= V_17 -> V_168 )
return V_17 ;
return NULL ;
}
long F_110 ( long V_172 , unsigned long V_27 , unsigned long V_173 )
{
struct V_4 * V_17 ;
long V_174 = - V_175 ;
V_17 = F_109 ( V_27 ) ;
if ( ! V_17 )
return - V_176 ;
switch ( V_172 ) {
case V_177 :
return ( long ) V_17 -> V_165 ;
case V_178 :
return ( long ) V_17 -> V_118 ;
case V_179 :
return ( long ) V_17 -> V_23 ;
case V_180 :
return ( long ) V_116 ;
case V_181 :
return ( long ) V_117 ;
}
return V_174 ;
}
static int
F_111 ( struct V_26 * V_27 , unsigned int V_173 , int V_52 ,
int V_182 , T_9 * V_84 )
{
return V_183 ;
}
static int
F_112 ( struct V_26 * V_27 , unsigned int V_173 , int V_52 ,
int V_182 , T_9 V_84 )
{
return V_183 ;
}
static struct V_26 *
F_113 ( struct V_4 * V_17 , int V_184 )
{
static struct V_26 V_27 ;
if ( ! V_17 )
F_57 ( V_124 L_74 , V_184 ) ;
V_27 . V_88 = V_184 ;
V_27 . V_164 = V_17 ;
V_27 . V_166 = V_17 ? V_17 -> V_166 : & V_185 ;
return & V_27 ;
}
int F_114 ( struct V_4 * V_17 , int V_27 , int V_173 ,
int V_186 )
{
return F_115 ( F_113 ( V_17 , V_27 ) , V_173 , V_186 ) ;
}
