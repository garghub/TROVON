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
char T_5 * F_25 ( char * V_40 )
{
return V_40 ;
}
int F_26 ( struct V_35 * V_35 )
{
struct V_41 V_42 ;
unsigned int V_43 ;
F_27 ( L_2 , F_28 ( V_35 ) ) ;
#ifdef F_29
memset ( & V_42 , 0xff , sizeof( V_42 ) ) ;
#endif
if ( F_30 ( V_35 , & V_42 ) ) {
T_6 line , V_44 ;
if ( F_31 ( V_35 , V_45 , & V_44 ) )
return - 1 ;
if ( V_44 == 0 )
return - 1 ;
if ( F_31 ( V_35 , V_46 , & line ) ||
line == 0xff || line == 0 ) {
return - 1 ;
}
F_27 ( L_3 ,
line , V_44 ) ;
V_43 = F_32 ( NULL , line ) ;
if ( V_43 != V_47 )
F_33 ( V_43 , V_48 ) ;
} else {
F_27 ( L_4 ,
V_42 . V_21 , V_42 . V_49 [ 0 ] , V_42 . V_49 [ 1 ] ,
V_42 . V_50 ? V_42 . V_50 -> V_38 :
L_5 ) ;
V_43 = F_34 ( V_42 . V_50 , V_42 . V_49 ,
V_42 . V_21 ) ;
}
if ( V_43 == V_47 ) {
F_27 ( L_6 ) ;
return - 1 ;
}
F_27 ( L_7 , V_43 ) ;
V_35 -> V_51 = V_43 ;
return 0 ;
}
static struct V_52 * F_35 ( struct V_35 * V_6 ,
T_1 * V_53 ,
enum V_54 V_55 )
{
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
unsigned long V_56 = 0 ;
int V_57 , V_58 ;
if ( V_17 == 0 )
return NULL ;
if ( V_55 == V_59 ) {
#if 0
*offset += hose->pci_mem_offset;
#endif
V_58 = V_60 ;
} else {
V_56 = ( unsigned long ) V_17 -> V_22 - V_25 ;
* V_53 += V_56 ;
V_58 = V_61 ;
}
for ( V_57 = 0 ; V_57 <= V_62 ; V_57 ++ ) {
struct V_52 * V_63 = & V_6 -> V_52 [ V_57 ] ;
int V_64 = V_63 -> V_64 ;
if ( V_57 == V_62 )
V_64 |= V_60 ;
if ( ( V_64 & V_58 ) == 0 )
continue;
if ( * V_53 < ( V_63 -> V_65 & V_66 ) || * V_53 > V_63 -> V_67 )
continue;
if ( V_55 == V_68 )
* V_53 += V_17 -> V_23 - V_56 ;
return V_63 ;
}
return NULL ;
}
static T_7 F_36 ( struct V_35 * V_6 , struct V_52 * V_63 ,
T_7 V_69 ,
enum V_54 V_55 ,
int V_70 )
{
T_7 V_71 = V_69 ;
if ( V_55 != V_59 )
V_70 = 0 ;
else if ( V_70 == 0 ) {
if ( V_63 -> V_64 & V_72 )
V_70 = 1 ;
}
return F_37 ( V_71 ) ;
}
T_7 F_38 ( struct V_73 * V_73 ,
unsigned long V_74 ,
unsigned long V_21 ,
T_7 V_71 )
{
struct V_35 * V_36 = NULL ;
struct V_52 * V_75 = NULL ;
T_1 V_53 = ( ( T_1 ) V_74 ) << V_76 ;
int V_57 ;
if ( F_39 ( V_74 ) )
return V_71 ;
V_71 = F_37 ( V_71 ) ;
F_40 (pdev) {
for ( V_57 = 0 ; V_57 <= V_62 ; V_57 ++ ) {
struct V_52 * V_63 = & V_36 -> V_52 [ V_57 ] ;
int V_64 = V_63 -> V_64 ;
if ( ( V_64 & V_60 ) == 0 )
continue;
if ( V_53 < ( V_63 -> V_65 & V_66 ) ||
V_53 > V_63 -> V_67 )
continue;
V_75 = V_63 ;
break;
}
if ( V_75 )
break;
}
if ( V_75 ) {
if ( V_75 -> V_64 & V_72 )
V_71 = F_41 ( V_71 ) ;
F_42 ( V_36 ) ;
}
F_27 ( L_8 ,
( unsigned long long ) V_53 , F_43 ( V_71 ) ) ;
return V_71 ;
}
int F_44 ( struct V_35 * V_6 , struct V_77 * V_78 ,
enum V_54 V_55 , int V_70 )
{
T_1 V_53 =
( ( T_1 ) V_78 -> V_79 ) << V_76 ;
struct V_52 * V_63 ;
int V_20 ;
V_63 = F_35 ( V_6 , & V_53 , V_55 ) ;
if ( V_63 == NULL )
return - V_80 ;
V_78 -> V_79 = V_53 >> V_76 ;
V_78 -> V_81 = F_36 ( V_6 , V_63 ,
V_78 -> V_81 ,
V_55 , V_70 ) ;
V_20 = F_45 ( V_78 , V_78 -> V_82 , V_78 -> V_79 ,
V_78 -> V_83 - V_78 -> V_82 , V_78 -> V_81 ) ;
return V_20 ;
}
int F_46 ( struct V_26 * V_27 , T_8 V_84 , T_9 * V_85 , T_10 V_21 )
{
unsigned long V_53 ;
struct V_4 * V_17 = F_17 ( V_27 ) ;
struct V_52 * V_63 = & V_17 -> V_18 ;
void T_2 * V_86 ;
V_53 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_53 += V_84 ;
if ( ! ( V_63 -> V_64 & V_61 ) )
return - V_87 ;
if ( V_53 < V_63 -> V_65 || ( V_53 + V_21 ) > V_63 -> V_67 )
return - V_87 ;
V_86 = V_17 -> V_22 + V_84 ;
switch ( V_21 ) {
case 1 :
* ( ( T_6 * ) V_85 ) = F_47 ( V_86 ) ;
return 1 ;
case 2 :
if ( V_84 & 1 )
return - V_80 ;
* ( ( V_88 * ) V_85 ) = F_48 ( V_86 ) ;
return 2 ;
case 4 :
if ( V_84 & 3 )
return - V_80 ;
* ( ( T_9 * ) V_85 ) = F_49 ( V_86 ) ;
return 4 ;
}
return - V_80 ;
}
int F_50 ( struct V_26 * V_27 , T_8 V_84 , T_9 V_85 , T_10 V_21 )
{
unsigned long V_53 ;
struct V_4 * V_17 = F_17 ( V_27 ) ;
struct V_52 * V_63 = & V_17 -> V_18 ;
void T_2 * V_86 ;
V_53 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_53 += V_84 ;
if ( ! ( V_63 -> V_64 & V_61 ) )
return - V_87 ;
if ( V_53 < V_63 -> V_65 || ( V_53 + V_21 ) > V_63 -> V_67 )
return - V_87 ;
V_86 = V_17 -> V_22 + V_84 ;
switch ( V_21 ) {
case 1 :
F_51 ( V_86 , V_85 >> 24 ) ;
return 1 ;
case 2 :
if ( V_84 & 1 )
return - V_80 ;
F_52 ( V_86 , V_85 >> 16 ) ;
return 2 ;
case 4 :
if ( V_84 & 3 )
return - V_80 ;
F_53 ( V_86 , V_85 ) ;
return 4 ;
}
return - V_80 ;
}
int F_54 ( struct V_26 * V_27 ,
struct V_77 * V_78 ,
enum V_54 V_55 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
T_1 V_53 =
( ( T_1 ) V_78 -> V_79 ) << V_76 ;
T_1 V_21 = V_78 -> V_83 - V_78 -> V_82 ;
struct V_52 * V_63 ;
F_27 ( L_9 ,
F_16 ( V_27 ) , V_27 -> V_89 ,
V_55 == V_59 ? L_10 : L_11 ,
( unsigned long long ) V_53 ,
( unsigned long long ) ( V_53 + V_21 - 1 ) ) ;
if ( V_55 == V_59 ) {
if ( ( V_53 + V_21 ) > V_17 -> V_90 ) {
#ifdef F_55
F_56 ( V_91
L_12
L_13 ,
V_92 -> V_93 , V_92 -> V_94 , F_16 ( V_27 ) ,
V_27 -> V_89 ) ;
#endif
if ( V_78 -> V_95 & V_96 )
return F_57 ( V_78 ) ;
return 0 ;
}
V_53 += V_17 -> V_97 ;
} else {
unsigned long V_56 = ( unsigned long ) V_17 -> V_22 - \
V_25 ;
unsigned long V_98 = V_53 + V_56 ;
V_63 = & V_17 -> V_18 ;
if ( ! ( V_63 -> V_64 & V_61 ) )
return - V_87 ;
if ( V_98 < V_63 -> V_65 || ( V_98 + V_21 ) > V_63 -> V_67 )
return - V_87 ;
V_53 += V_17 -> V_23 ;
}
F_27 ( L_14 , ( unsigned long long ) V_53 ) ;
V_78 -> V_79 = V_53 >> V_76 ;
V_78 -> V_81 = F_37 ( V_78 -> V_81 ) ;
return F_45 ( V_78 , V_78 -> V_82 , V_78 -> V_79 ,
V_78 -> V_83 - V_78 -> V_82 ,
V_78 -> V_81 ) ;
}
void F_58 ( const struct V_35 * V_6 , int V_99 ,
const struct V_52 * V_100 ,
T_1 * V_65 , T_1 * V_67 )
{
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
T_1 V_53 = 0 ;
if ( V_17 == NULL )
return;
if ( V_100 -> V_64 & V_61 )
V_53 = ( unsigned long ) V_17 -> V_22 - V_25 ;
#if 0
else if (rsrc->flags & IORESOURCE_MEM)
offset = hose->pci_mem_offset;
#endif
* V_65 = V_100 -> V_65 - V_53 ;
* V_67 = V_100 -> V_67 - V_53 ;
}
void T_5 F_59 ( struct V_4 * V_17 ,
struct V_5 * V_6 ,
int V_101 )
{
const T_9 * V_102 ;
int V_103 ;
int V_104 = F_60 ( V_6 ) ;
int V_37 = V_104 + 5 ;
int V_105 = 0 , V_106 = - 1 ;
T_9 V_107 ;
unsigned long long V_108 , V_109 , V_110 , V_111 , V_21 ;
unsigned long long V_112 = 0 ;
struct V_52 * V_113 ;
F_56 ( V_114 L_15 ,
V_6 -> V_38 , V_101 ? L_16 : L_17 ) ;
V_102 = F_61 ( V_6 , L_18 , & V_103 ) ;
if ( V_102 == NULL )
return;
F_27 ( L_19 ) ;
while ( ( V_103 -= V_37 * 4 ) >= 0 ) {
V_107 = V_102 [ 0 ] ;
V_108 = F_62 ( V_102 + 1 , 2 ) ;
V_109 = F_63 ( V_6 , V_102 + 3 ) ;
V_21 = F_62 ( V_102 + V_104 + 3 , 2 ) ;
F_27 ( L_20
L_21 ,
V_107 , V_108 , V_109 , V_21 ) ;
V_102 += V_37 ;
if ( V_109 == V_115 || V_21 == 0 )
continue;
for (; V_103 >= V_37 * sizeof( T_9 ) ;
V_102 += V_37 , V_103 -= V_37 * 4 ) {
if ( V_102 [ 0 ] != V_107 )
break;
V_110 = F_62 ( V_102 + 1 , 2 ) ;
V_111 = F_63 ( V_6 , V_102 + 3 ) ;
if ( V_110 != V_108 + V_21 ||
V_111 != V_109 + V_21 )
break;
V_21 += F_62 ( V_102 + V_104 + 3 , 2 ) ;
}
V_113 = NULL ;
switch ( ( V_107 >> 24 ) & 0x3 ) {
case 1 :
F_56 ( V_114
L_22 ,
V_109 , V_109 + V_21 - 1 , V_108 ) ;
if ( V_17 -> V_116 ) {
F_56 ( V_114
L_23 ) ;
continue;
}
if ( V_21 > 0x01000000 )
V_21 = 0x01000000 ;
V_17 -> V_22 = F_64 ( V_109 , V_21 ) ;
if ( V_101 )
V_117 =
( unsigned long ) V_17 -> V_22 ;
V_17 -> V_116 = V_108 + V_21 ;
V_17 -> V_23 = V_109 - V_108 ;
V_113 = & V_17 -> V_18 ;
V_113 -> V_64 = V_61 ;
V_113 -> V_65 = V_108 ;
break;
case 2 :
case 3 :
F_56 ( V_114
L_24 ,
V_109 , V_109 + V_21 - 1 , V_108 ,
( V_107 & 0x40000000 ) ? L_25 : L_17 ) ;
if ( V_105 >= 3 ) {
F_56 ( V_114
L_23 ) ;
continue;
}
if ( V_108 == 0 ) {
V_112 = V_109 ;
V_106 = V_105 ;
if ( V_101 || V_118 == 0 )
V_118 = V_109 ;
V_17 -> V_97 = V_109 ;
V_17 -> V_90 = V_21 ;
}
if ( V_105 == 0 ||
( V_106 >= 0 && V_108 != 0 &&
V_17 -> V_119 == V_112 ) )
V_17 -> V_119 = V_109 - V_108 ;
else if ( V_108 != 0 &&
V_17 -> V_119 != V_109 - V_108 ) {
F_56 ( V_114
L_26 ) ;
continue;
}
V_113 = & V_17 -> V_120 [ V_105 ++ ] ;
V_113 -> V_64 = V_60 ;
if ( V_107 & 0x40000000 )
V_113 -> V_64 |= V_72 ;
V_113 -> V_65 = V_109 ;
break;
}
if ( V_113 != NULL ) {
V_113 -> V_121 = V_6 -> V_38 ;
V_113 -> V_67 = V_113 -> V_65 + V_21 - 1 ;
V_113 -> V_30 = NULL ;
V_113 -> V_122 = NULL ;
V_113 -> V_123 = NULL ;
}
}
if ( V_106 >= 0 && V_17 -> V_119 != V_112 ) {
unsigned int V_124 = V_106 + 1 ;
F_56 ( V_114 L_27 , V_112 ) ;
if ( V_124 < V_105 )
memmove ( & V_17 -> V_120 [ V_106 ] ,
& V_17 -> V_120 [ V_124 ] ,
sizeof( struct V_52 ) * ( V_105 - V_124 ) ) ;
V_17 -> V_120 [ -- V_105 ] . V_64 = 0 ;
}
}
int F_65 ( struct V_26 * V_27 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
if ( ! ( V_125 & V_126 ) )
return 0 ;
if ( V_125 & V_127 )
return V_17 -> V_10 != 0 ;
return 1 ;
}
void F_66 ( struct V_35 * V_6 , struct V_128 * V_129 ,
struct V_52 * V_113 )
{
T_1 V_53 = 0 , V_130 = ( T_1 ) - 1 ;
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
if ( ! V_17 )
return;
if ( V_113 -> V_64 & V_61 ) {
V_53 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_130 = 0xffffffffu ;
} else if ( V_113 -> V_64 & V_60 )
V_53 = V_17 -> V_119 ;
V_129 -> V_65 = ( V_113 -> V_65 - V_53 ) & V_130 ;
V_129 -> V_67 = ( V_113 -> V_67 - V_53 ) & V_130 ;
}
void F_67 ( struct V_35 * V_6 , struct V_52 * V_113 ,
struct V_128 * V_129 )
{
T_1 V_53 = 0 , V_130 = ( T_1 ) - 1 ;
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
if ( ! V_17 )
return;
if ( V_113 -> V_64 & V_61 ) {
V_53 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_130 = 0xffffffffu ;
} else if ( V_113 -> V_64 & V_60 )
V_53 = V_17 -> V_119 ;
V_113 -> V_65 = ( V_129 -> V_65 + V_53 ) & V_130 ;
V_113 -> V_67 = ( V_129 -> V_67 + V_53 ) & V_130 ;
}
static void T_5 F_68 ( struct V_52 * V_113 , struct V_35 * V_6 )
{
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
T_1 V_53 = 0 , V_130 = ( T_1 ) - 1 ;
if ( V_113 -> V_64 & V_61 ) {
V_53 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_130 = 0xffffffffu ;
} else if ( V_113 -> V_64 & V_60 )
V_53 = V_17 -> V_119 ;
V_113 -> V_65 = ( V_113 -> V_65 + V_53 ) & V_130 ;
V_113 -> V_67 = ( V_113 -> V_67 + V_53 ) & V_130 ;
}
static void T_5 F_69 ( struct V_35 * V_6 )
{
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
int V_57 ;
if ( ! V_17 ) {
F_56 ( V_131 L_28 ,
F_28 ( V_6 ) ) ;
return;
}
for ( V_57 = 0 ; V_57 < V_132 ; V_57 ++ ) {
struct V_52 * V_113 = V_6 -> V_52 + V_57 ;
if ( ! V_113 -> V_64 )
continue;
if ( V_113 -> V_65 == 0 && ! ( V_125 & V_133 ) ) {
F_27 ( L_29 \
L_30 ,
F_28 ( V_6 ) , V_57 ,
( unsigned long long ) V_113 -> V_65 ,
( unsigned long long ) V_113 -> V_67 ,
( unsigned int ) V_113 -> V_64 ) ;
V_113 -> V_67 -= V_113 -> V_65 ;
V_113 -> V_65 = 0 ;
V_113 -> V_64 |= V_134 ;
continue;
}
F_27 ( L_31 ,
F_28 ( V_6 ) , V_57 ,
( unsigned long long ) V_113 -> V_65 ,\
( unsigned long long ) V_113 -> V_67 ,
( unsigned int ) V_113 -> V_64 ) ;
F_68 ( V_113 , V_6 ) ;
F_27 ( L_32 ,
F_28 ( V_6 ) ,
( unsigned long long ) V_113 -> V_65 ,
( unsigned long long ) V_113 -> V_67 ) ;
}
}
static int T_5 F_70 ( struct V_26 * V_27 ,
struct V_52 * V_113 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
struct V_35 * V_6 = V_27 -> V_135 ;
T_1 V_53 ;
V_88 V_136 ;
int V_57 ;
if ( V_125 & V_133 )
return 0 ;
if ( V_113 -> V_64 & V_60 ) {
if ( V_113 -> V_65 != V_17 -> V_119 )
return 0 ;
F_71 ( V_6 , V_137 , & V_136 ) ;
if ( ( V_136 & V_138 ) == 0 )
return 1 ;
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ ) {
if ( ( V_17 -> V_120 [ V_57 ] . V_64 & V_60 ) &&
V_17 -> V_120 [ V_57 ] . V_65 == V_17 -> V_119 )
return 0 ;
}
return 1 ;
} else {
V_53 = ( unsigned long ) V_17 -> V_22 - V_25 ;
if ( ( ( V_113 -> V_65 - V_53 ) & 0xfffffffful ) != 0 )
return 0 ;
F_71 ( V_6 , V_137 , & V_136 ) ;
if ( V_136 & V_139 )
return 0 ;
return 1 ;
}
}
static void T_5 F_72 ( struct V_26 * V_27 )
{
struct V_52 * V_113 ;
int V_57 ;
struct V_35 * V_6 = V_27 -> V_135 ;
F_73 (bus, res, i) {
V_113 = V_27 -> V_52 [ V_57 ] ;
if ( ! V_113 )
continue;
if ( ! V_113 -> V_64 )
continue;
if ( V_57 >= 3 && V_27 -> V_135 -> V_140 )
continue;
F_27 ( L_33 ,
F_28 ( V_6 ) , V_57 ,
( unsigned long long ) V_113 -> V_65 ,\
( unsigned long long ) V_113 -> V_67 ,
( unsigned int ) V_113 -> V_64 ) ;
F_68 ( V_113 , V_6 ) ;
if ( F_70 ( V_27 , V_113 ) ) {
V_113 -> V_64 = 0 ;
F_27 ( L_34 ,
F_28 ( V_6 ) ) ;
} else {
F_27 ( L_32 ,
F_28 ( V_6 ) ,
( unsigned long long ) V_113 -> V_65 ,
( unsigned long long ) V_113 -> V_67 ) ;
}
}
}
void T_5 F_74 ( struct V_26 * V_27 )
{
if ( V_27 -> V_135 != NULL )
F_72 ( V_27 ) ;
}
void T_5 F_75 ( struct V_26 * V_27 )
{
struct V_35 * V_6 ;
F_27 ( L_35 ,
V_27 -> V_89 , V_27 -> V_135 ? F_28 ( V_27 -> V_135 ) : L_36 ) ;
F_14 (dev, &bus->devices, bus_list) {
V_6 -> V_6 . V_141 = F_22 ( V_6 ) ;
F_76 ( & V_6 -> V_6 , F_77 ( V_6 -> V_27 ) ) ;
F_78 ( & V_6 -> V_6 , V_3 ) ;
V_6 -> V_6 . V_142 . V_143 = ( void * ) V_144 ;
F_26 ( V_6 ) ;
}
}
void T_5 F_79 ( struct V_26 * V_27 )
{
if ( V_27 -> V_135 != NULL )
F_80 ( V_27 ) ;
F_74 ( V_27 ) ;
F_75 ( V_27 ) ;
}
static int F_81 ( struct V_35 * V_6 )
{
if ( ( V_125 & V_145 ) &&
! ( V_6 -> V_27 -> V_146 & V_147 ) )
return 1 ;
return 0 ;
}
T_1 F_82 ( void * V_148 , const struct V_52 * V_113 ,
T_1 V_21 , T_1 V_149 )
{
struct V_35 * V_6 = V_148 ;
T_1 V_65 = V_113 -> V_65 ;
if ( V_113 -> V_64 & V_61 ) {
if ( F_81 ( V_6 ) )
return V_65 ;
if ( V_65 & 0x300 )
V_65 = ( V_65 + 0x3ff ) & ~ 0x3ff ;
}
return V_65 ;
}
static int T_11 F_83 ( struct V_52 * V_30 ,
struct V_52 * V_113 )
{
struct V_52 * V_150 , * * V_151 ;
struct V_52 * * V_152 = NULL ;
for ( V_151 = & V_30 -> V_123 ; ( V_150 = * V_151 ) != NULL ; V_151 = & V_150 -> V_122 ) {
if ( V_150 -> V_67 < V_113 -> V_65 )
continue;
if ( V_113 -> V_67 < V_150 -> V_65 )
break;
if ( V_150 -> V_65 < V_113 -> V_65 || V_150 -> V_67 > V_113 -> V_67 )
return - 1 ;
if ( V_152 == NULL )
V_152 = V_151 ;
}
if ( V_152 == NULL )
return - 1 ;
V_113 -> V_30 = V_30 ;
V_113 -> V_123 = * V_152 ;
V_113 -> V_122 = * V_151 ;
* V_152 = V_113 ;
* V_151 = NULL ;
for ( V_150 = V_113 -> V_123 ; V_150 != NULL ; V_150 = V_150 -> V_122 ) {
V_150 -> V_30 = V_113 ;
F_27 ( L_37 ,
V_150 -> V_121 ,
( unsigned long long ) V_150 -> V_65 ,
( unsigned long long ) V_150 -> V_67 , V_113 -> V_121 ) ;
}
return 0 ;
}
void F_84 ( struct V_26 * V_27 )
{
struct V_26 * V_153 ;
int V_57 ;
struct V_52 * V_113 , * V_154 ;
F_27 ( L_38 ,
F_16 ( V_27 ) , V_27 -> V_89 ) ;
F_73 (bus, res, i) {
V_113 = V_27 -> V_52 [ V_57 ] ;
if ( ! V_113 || ! V_113 -> V_64
|| V_113 -> V_65 > V_113 -> V_67 || V_113 -> V_30 )
continue;
if ( V_27 -> V_30 == NULL )
V_154 = ( V_113 -> V_64 & V_61 ) ?
& V_155 : & V_156 ;
else {
if ( V_125 & V_157 )
goto V_158;
V_154 = F_85 ( V_27 -> V_135 , V_113 ) ;
if ( V_154 == V_113 ) {
continue;
}
}
F_27 ( L_39
L_40 ,
V_27 -> V_135 ? F_28 ( V_27 -> V_135 ) : L_36 ,
V_27 -> V_89 , V_57 ,
( unsigned long long ) V_113 -> V_65 ,
( unsigned long long ) V_113 -> V_67 ,
( unsigned int ) V_113 -> V_64 ,
V_154 , ( V_154 && V_154 -> V_121 ) ? V_154 -> V_121 : L_41 ) ;
if ( V_154 && ! ( V_154 -> V_64 & V_134 ) ) {
if ( F_86 ( V_154 , V_113 ) == 0 )
continue;
if ( F_83 ( V_154 , V_113 ) == 0 )
continue;
}
F_56 ( V_159 L_42
L_43 , V_57 , V_27 -> V_89 ) ;
V_158:
V_113 -> V_65 = V_113 -> V_67 = 0 ;
V_113 -> V_64 = 0 ;
}
F_14 (b, &bus->children, node)
F_84 ( V_153 ) ;
}
static inline void T_5 F_87 ( struct V_35 * V_6 , int V_160 )
{
struct V_52 * V_154 , * V_161 = & V_6 -> V_52 [ V_160 ] ;
F_27 ( L_44 ,
F_28 ( V_6 ) , V_160 ,
( unsigned long long ) V_161 -> V_65 ,
( unsigned long long ) V_161 -> V_67 ,
( unsigned int ) V_161 -> V_64 ) ;
V_154 = F_85 ( V_6 , V_161 ) ;
if ( ! V_154 || ( V_154 -> V_64 & V_134 ) ||
F_86 ( V_154 , V_161 ) < 0 ) {
F_56 ( V_159 L_45
L_46 , V_160 , F_28 ( V_6 ) ) ;
if ( V_154 )
F_27 ( L_47 ,
V_154 ,
( unsigned long long ) V_154 -> V_65 ,
( unsigned long long ) V_154 -> V_67 ,
( unsigned int ) V_154 -> V_64 ) ;
V_161 -> V_64 |= V_134 ;
V_161 -> V_67 -= V_161 -> V_65 ;
V_161 -> V_65 = 0 ;
}
}
static void T_11 F_88 ( int V_162 )
{
struct V_35 * V_6 = NULL ;
int V_160 , V_163 ;
V_88 V_136 ;
struct V_52 * V_161 ;
F_40 (dev) {
F_71 ( V_6 , V_137 , & V_136 ) ;
for ( V_160 = 0 ; V_160 <= V_62 ; V_160 ++ ) {
V_161 = & V_6 -> V_52 [ V_160 ] ;
if ( V_161 -> V_30 )
continue;
if ( ! V_161 -> V_64 || ( V_161 -> V_64 & V_134 ) )
continue;
if ( V_160 == V_62 )
V_163 = 1 ;
if ( V_161 -> V_64 & V_61 )
V_163 = ! ( V_136 & V_139 ) ;
else
V_163 = ! ( V_136 & V_138 ) ;
if ( V_162 == V_163 )
F_87 ( V_6 , V_160 ) ;
}
if ( V_162 )
continue;
V_161 = & V_6 -> V_52 [ V_62 ] ;
if ( V_161 -> V_64 ) {
T_9 V_164 ;
F_89 ( V_6 , V_6 -> V_165 , & V_164 ) ;
if ( V_164 & V_166 ) {
F_27 ( L_48 ,
F_28 ( V_6 ) ) ;
V_161 -> V_64 &= ~ V_167 ;
F_90 ( V_6 , V_6 -> V_165 ,
V_164 & ~ V_166 ) ;
}
}
}
}
static void T_11 F_91 ( struct V_26 * V_27 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
T_1 V_53 ;
struct V_52 * V_113 , * V_168 ;
int V_57 ;
F_27 ( L_49 ,
F_16 ( V_27 ) ) ;
if ( ! ( V_17 -> V_18 . V_64 & V_61 ) )
goto V_169;
V_53 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_113 = F_92 ( sizeof( struct V_52 ) , V_8 ) ;
F_93 ( V_113 == NULL ) ;
V_113 -> V_121 = L_50 ;
V_113 -> V_64 = V_61 ;
V_113 -> V_65 = V_53 ;
V_113 -> V_67 = ( V_53 + 0xfff ) & 0xfffffffful ;
F_27 ( L_51 , V_113 ) ;
if ( F_86 ( & V_17 -> V_18 , V_113 ) ) {
F_56 ( V_91
L_52 ,
F_16 ( V_27 ) , V_27 -> V_89 , V_113 ) ;
F_10 ( V_113 ) ;
}
V_169:
V_53 = V_17 -> V_119 ;
F_27 ( L_53 , ( unsigned long long ) V_53 ) ;
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ ) {
V_168 = & V_17 -> V_120 [ V_57 ] ;
if ( ! ( V_168 -> V_64 & V_60 ) )
continue;
F_27 ( L_54 , V_168 ) ;
if ( ( V_168 -> V_65 - V_53 ) <= 0xa0000 &&
( V_168 -> V_67 - V_53 ) >= 0xbffff )
break;
}
if ( V_57 >= 3 )
return;
V_113 = F_92 ( sizeof( struct V_52 ) , V_8 ) ;
F_93 ( V_113 == NULL ) ;
V_113 -> V_121 = L_55 ;
V_113 -> V_64 = V_60 ;
V_113 -> V_65 = 0xa0000 + V_53 ;
V_113 -> V_67 = 0xbffff + V_53 ;
F_27 ( L_56 , V_113 ) ;
if ( F_86 ( V_168 , V_113 ) ) {
F_56 ( V_91
L_57 ,
F_16 ( V_27 ) , V_27 -> V_89 , V_113 ) ;
F_10 ( V_113 ) ;
}
}
void T_11 F_94 ( void )
{
struct V_26 * V_153 ;
F_14 (b, &pci_root_buses, node)
F_84 ( V_153 ) ;
if ( ! ( V_125 & V_157 ) ) {
F_88 ( 0 ) ;
F_88 ( 1 ) ;
}
if ( ! ( V_125 & V_133 ) ) {
F_14 (b, &pci_root_buses, node)
F_91 ( V_153 ) ;
}
if ( ! ( V_125 & V_133 ) ) {
F_27 ( L_58 ) ;
F_95 () ;
}
}
void T_5 F_96 ( struct V_26 * V_27 )
{
struct V_35 * V_6 ;
struct V_26 * V_170 ;
F_14 (dev, &bus->devices, bus_list) {
int V_57 ;
for ( V_57 = 0 ; V_57 < V_171 ; V_57 ++ ) {
struct V_52 * V_161 = & V_6 -> V_52 [ V_57 ] ;
if ( V_161 -> V_30 || ! V_161 -> V_65 || ! V_161 -> V_64 )
continue;
F_27 ( L_59
L_60 ,
F_28 ( V_6 ) , V_57 ,
( unsigned long long ) V_161 -> V_65 ,
( unsigned long long ) V_161 -> V_67 ,
( unsigned int ) V_161 -> V_64 ) ;
F_97 ( V_6 , V_57 ) ;
}
}
F_14 (child_bus, &bus->children, node)
F_96 ( V_170 ) ;
}
void F_98 ( struct V_26 * V_27 )
{
F_27 ( L_61 ,
F_16 ( V_27 ) , V_27 -> V_89 ) ;
F_84 ( V_27 ) ;
F_96 ( V_27 ) ;
F_99 ( V_27 ) ;
}
int F_100 ( struct V_35 * V_6 , int V_130 )
{
return F_101 ( V_6 , V_130 ) ;
}
void T_5 F_102 ( struct V_4 * V_17 )
{
struct V_26 * V_27 = V_17 -> V_27 ;
struct V_52 * V_113 ;
int V_57 ;
V_27 -> V_52 [ 0 ] = V_113 = & V_17 -> V_18 ;
if ( ! V_113 -> V_64 ) {
F_56 ( V_159 L_62
L_63 ,
V_17 -> V_14 -> V_38 , V_17 -> V_10 ) ;
V_113 -> V_65 = ( unsigned long ) V_17 -> V_22 - V_117 ;
V_113 -> V_67 = V_113 -> V_65 + V_172 ;
V_113 -> V_64 = V_61 ;
}
F_27 ( L_64 ,
( unsigned long long ) V_113 -> V_65 ,
( unsigned long long ) V_113 -> V_67 ,
( unsigned long ) V_113 -> V_64 ) ;
for ( V_57 = 0 ; V_57 < 3 ; ++ V_57 ) {
V_113 = & V_17 -> V_120 [ V_57 ] ;
if ( ! V_113 -> V_64 ) {
if ( V_57 > 0 )
continue;
F_56 ( V_131 L_65
L_66 ,
V_17 -> V_14 -> V_38 , V_17 -> V_10 ) ;
V_113 -> V_65 = V_17 -> V_119 ;
V_113 -> V_67 = ( T_1 ) - 1LL ;
V_113 -> V_64 = V_60 ;
}
V_27 -> V_52 [ V_57 + 1 ] = V_113 ;
F_27 ( L_67 ,
V_57 , ( unsigned long long ) V_113 -> V_65 ,
( unsigned long long ) V_113 -> V_67 ,
( unsigned long ) V_113 -> V_64 ) ;
}
F_27 ( L_68 ,
( unsigned long long ) V_17 -> V_119 ) ;
F_27 ( L_69 ,
( unsigned long ) V_17 -> V_22 - V_25 ) ;
}
struct V_5 * F_103 ( struct V_26 * V_27 )
{
struct V_4 * V_17 = V_27 -> V_173 ;
return F_104 ( V_17 -> V_14 ) ;
}
static void T_5 F_105 ( struct V_4 * V_17 )
{
struct V_26 * V_27 ;
struct V_5 * V_28 = V_17 -> V_14 ;
unsigned long V_56 ;
struct V_52 * V_113 = & V_17 -> V_18 ;
F_27 ( L_70 ,
V_28 ? V_28 -> V_38 : L_71 ) ;
V_27 = F_106 ( V_17 -> V_30 , V_17 -> V_174 , V_17 -> V_175 , V_17 ) ;
if ( V_27 == NULL ) {
F_56 ( V_131 L_72 ,
V_17 -> V_10 ) ;
return;
}
V_27 -> V_176 = V_17 -> V_174 ;
V_17 -> V_27 = V_27 ;
V_56 = ( unsigned long ) V_17 -> V_22 - V_117 ;
V_113 -> V_65 = ( V_113 -> V_65 + V_56 ) & 0xffffffffu ;
V_113 -> V_67 = ( V_113 -> V_67 + V_56 ) & 0xffffffffu ;
F_102 ( V_17 ) ;
V_17 -> V_177 = V_27 -> V_178 = F_107 ( V_27 ) ;
}
static int T_11 F_108 ( void )
{
struct V_4 * V_17 , * V_29 ;
int V_179 = 0 ;
F_56 ( V_114 L_73 ) ;
F_19 (hose, tmp, &hose_list, list_node) {
V_17 -> V_177 = 0xff ;
F_105 ( V_17 ) ;
F_56 ( V_114 L_74 ) ;
F_99 ( V_17 -> V_27 ) ;
if ( V_179 <= V_17 -> V_177 )
V_179 = V_17 -> V_177 + 1 ;
}
V_180 = V_179 ;
F_94 () ;
return 0 ;
}
static struct V_4 * F_109 ( int V_27 )
{
struct V_4 * V_17 , * V_29 ;
F_19 (hose, tmp, &hose_list, list_node)
if ( V_27 >= V_17 -> V_174 && V_27 <= V_17 -> V_177 )
return V_17 ;
return NULL ;
}
long F_110 ( long V_181 , unsigned long V_27 , unsigned long V_182 )
{
struct V_4 * V_17 ;
long V_183 = - V_184 ;
V_17 = F_109 ( V_27 ) ;
if ( ! V_17 )
return - V_185 ;
switch ( V_181 ) {
case V_186 :
return ( long ) V_17 -> V_174 ;
case V_187 :
return ( long ) V_17 -> V_119 ;
case V_188 :
return ( long ) V_17 -> V_23 ;
case V_189 :
return ( long ) V_117 ;
case V_190 :
return ( long ) V_118 ;
}
return V_183 ;
}
static int
F_111 ( struct V_26 * V_27 , unsigned int V_182 , int V_53 ,
int V_191 , T_9 * V_85 )
{
return V_192 ;
}
static int
F_112 ( struct V_26 * V_27 , unsigned int V_182 , int V_53 ,
int V_191 , T_9 V_85 )
{
return V_192 ;
}
static struct V_26 *
F_113 ( struct V_4 * V_17 , int V_193 )
{
static struct V_26 V_27 ;
if ( ! V_17 )
F_56 ( V_131 L_75 , V_193 ) ;
V_27 . V_89 = V_193 ;
V_27 . V_173 = V_17 ;
V_27 . V_175 = V_17 ? V_17 -> V_175 : & V_194 ;
return & V_27 ;
}
int F_114 ( struct V_4 * V_17 , int V_27 , int V_182 ,
int V_195 )
{
return F_115 ( F_113 ( V_17 , V_27 ) , V_182 , V_195 ) ;
}
