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
return V_17 -> V_18 . V_19 - V_17 -> V_18 . V_20 + 1 ;
}
int F_12 ( void T_2 * V_21 )
{
int V_22 = 0 ;
struct V_4 * V_17 ;
T_1 V_23 ;
F_5 ( & V_9 ) ;
F_13 (hose, &hose_list, list_node) {
V_23 = F_11 ( V_17 ) ;
if ( V_21 >= V_17 -> V_24 &&
V_21 < ( V_17 -> V_24 + V_23 ) ) {
V_22 = 1 ;
break;
}
}
F_7 ( & V_9 ) ;
return V_22 ;
}
unsigned long F_14 ( T_3 V_21 )
{
struct V_4 * V_17 ;
T_1 V_23 ;
unsigned long V_22 = ~ 0 ;
F_5 ( & V_9 ) ;
F_13 (hose, &hose_list, list_node) {
V_23 = F_11 ( V_17 ) ;
if ( V_21 >= V_17 -> V_25 &&
V_21 < ( V_17 -> V_25 + V_23 ) ) {
unsigned long V_26 =
( unsigned long ) V_17 -> V_24 - V_27 ;
V_22 = V_26 + ( V_21 - V_17 -> V_25 ) ;
break;
}
}
F_7 ( & V_9 ) ;
return V_22 ;
}
int F_15 ( struct V_28 * V_29 )
{
struct V_4 * V_17 = F_16 ( V_29 ) ;
return V_17 -> V_10 ;
}
struct V_4 * F_17 ( struct V_5 * V_30 )
{
while ( V_30 ) {
struct V_4 * V_17 , * V_31 ;
F_18 (hose, tmp, &hose_list, list_node)
if ( V_17 -> V_14 == V_30 )
return V_17 ;
V_30 = V_30 -> V_32 ;
}
return NULL ;
}
static T_4 F_19 ( struct V_33 * V_6 ,
struct V_34 * V_35 , char * V_36 )
{
struct V_37 * V_38 ;
struct V_5 * V_39 ;
V_38 = F_20 ( V_6 ) ;
V_39 = F_21 ( V_38 ) ;
if ( V_39 == NULL || V_39 -> V_40 == NULL )
return 0 ;
return sprintf ( V_36 , L_1 , V_39 -> V_40 ) ;
}
int F_22 ( struct V_37 * V_38 )
{
return F_23 ( & V_38 -> V_6 , & V_41 ) ;
}
char T_5 * F_24 ( char * V_42 )
{
return V_42 ;
}
int F_25 ( struct V_37 * V_37 )
{
struct V_43 V_44 ;
unsigned int V_45 ;
F_26 ( L_2 , F_27 ( V_37 ) ) ;
#ifdef F_28
memset ( & V_44 , 0xff , sizeof( V_44 ) ) ;
#endif
if ( F_29 ( V_37 , & V_44 ) ) {
T_6 line , V_46 ;
if ( F_30 ( V_37 , V_47 , & V_46 ) )
return - 1 ;
if ( V_46 == 0 )
return - 1 ;
if ( F_30 ( V_37 , V_48 , & line ) ||
line == 0xff || line == 0 ) {
return - 1 ;
}
F_26 ( L_3 ,
line , V_46 ) ;
V_45 = F_31 ( NULL , line ) ;
if ( V_45 != V_49 )
F_32 ( V_45 , V_50 ) ;
} else {
F_26 ( L_4 ,
V_44 . V_23 , V_44 . V_51 [ 0 ] , V_44 . V_51 [ 1 ] ,
V_44 . V_52 ? V_44 . V_52 -> V_40 :
L_5 ) ;
V_45 = F_33 ( V_44 . V_52 , V_44 . V_51 ,
V_44 . V_23 ) ;
}
if ( V_45 == V_49 ) {
F_26 ( L_6 ) ;
return - 1 ;
}
F_26 ( L_7 , V_45 ) ;
V_37 -> V_53 = V_45 ;
return 0 ;
}
static struct V_54 * F_34 ( struct V_37 * V_6 ,
T_1 * V_55 ,
enum V_56 V_57 )
{
struct V_4 * V_17 = F_16 ( V_6 -> V_29 ) ;
unsigned long V_58 = 0 ;
int V_59 , V_60 ;
if ( V_17 == 0 )
return NULL ;
if ( V_57 == V_61 ) {
#if 0
*offset += hose->pci_mem_offset;
#endif
V_60 = V_62 ;
} else {
V_58 = ( unsigned long ) V_17 -> V_24 - V_27 ;
* V_55 += V_58 ;
V_60 = V_63 ;
}
for ( V_59 = 0 ; V_59 <= V_64 ; V_59 ++ ) {
struct V_54 * V_65 = & V_6 -> V_54 [ V_59 ] ;
int V_66 = V_65 -> V_66 ;
if ( V_59 == V_64 )
V_66 |= V_62 ;
if ( ( V_66 & V_60 ) == 0 )
continue;
if ( * V_55 < ( V_65 -> V_20 & V_67 ) || * V_55 > V_65 -> V_19 )
continue;
if ( V_57 == V_68 )
* V_55 += V_17 -> V_25 - V_58 ;
return V_65 ;
}
return NULL ;
}
static T_7 F_35 ( struct V_37 * V_6 , struct V_54 * V_65 ,
T_7 V_69 ,
enum V_56 V_57 ,
int V_70 )
{
T_7 V_71 = V_69 ;
if ( V_57 != V_61 )
V_70 = 0 ;
else if ( V_70 == 0 ) {
if ( V_65 -> V_66 & V_72 )
V_70 = 1 ;
}
return F_36 ( V_71 ) ;
}
T_7 F_37 ( struct V_73 * V_73 ,
unsigned long V_74 ,
unsigned long V_23 ,
T_7 V_71 )
{
struct V_37 * V_38 = NULL ;
struct V_54 * V_75 = NULL ;
T_1 V_55 = ( ( T_1 ) V_74 ) << V_76 ;
int V_59 ;
if ( F_38 ( V_74 ) )
return V_71 ;
V_71 = F_36 ( V_71 ) ;
F_39 (pdev) {
for ( V_59 = 0 ; V_59 <= V_64 ; V_59 ++ ) {
struct V_54 * V_65 = & V_38 -> V_54 [ V_59 ] ;
int V_66 = V_65 -> V_66 ;
if ( ( V_66 & V_62 ) == 0 )
continue;
if ( V_55 < ( V_65 -> V_20 & V_67 ) ||
V_55 > V_65 -> V_19 )
continue;
V_75 = V_65 ;
break;
}
if ( V_75 )
break;
}
if ( V_75 ) {
if ( V_75 -> V_66 & V_72 )
V_71 = F_40 ( V_71 ) ;
F_41 ( V_38 ) ;
}
F_26 ( L_8 ,
( unsigned long long ) V_55 , F_42 ( V_71 ) ) ;
return V_71 ;
}
int F_43 ( struct V_37 * V_6 , struct V_77 * V_78 ,
enum V_56 V_57 , int V_70 )
{
T_1 V_55 =
( ( T_1 ) V_78 -> V_79 ) << V_76 ;
struct V_54 * V_65 ;
int V_22 ;
V_65 = F_34 ( V_6 , & V_55 , V_57 ) ;
if ( V_65 == NULL )
return - V_80 ;
V_78 -> V_79 = V_55 >> V_76 ;
V_78 -> V_81 = F_35 ( V_6 , V_65 ,
V_78 -> V_81 ,
V_57 , V_70 ) ;
V_22 = F_44 ( V_78 , V_78 -> V_82 , V_78 -> V_79 ,
V_78 -> V_83 - V_78 -> V_82 , V_78 -> V_81 ) ;
return V_22 ;
}
int F_45 ( struct V_28 * V_29 , T_8 V_84 , T_9 * V_85 , T_10 V_23 )
{
unsigned long V_55 ;
struct V_4 * V_17 = F_16 ( V_29 ) ;
struct V_54 * V_65 = & V_17 -> V_18 ;
void T_2 * V_86 ;
V_55 = ( unsigned long ) V_17 -> V_24 - V_27 ;
V_55 += V_84 ;
if ( ! ( V_65 -> V_66 & V_63 ) )
return - V_87 ;
if ( V_55 < V_65 -> V_20 || ( V_55 + V_23 ) > V_65 -> V_19 )
return - V_87 ;
V_86 = V_17 -> V_24 + V_84 ;
switch ( V_23 ) {
case 1 :
* ( ( T_6 * ) V_85 ) = F_46 ( V_86 ) ;
return 1 ;
case 2 :
if ( V_84 & 1 )
return - V_80 ;
* ( ( V_88 * ) V_85 ) = F_47 ( V_86 ) ;
return 2 ;
case 4 :
if ( V_84 & 3 )
return - V_80 ;
* ( ( T_9 * ) V_85 ) = F_48 ( V_86 ) ;
return 4 ;
}
return - V_80 ;
}
int F_49 ( struct V_28 * V_29 , T_8 V_84 , T_9 V_85 , T_10 V_23 )
{
unsigned long V_55 ;
struct V_4 * V_17 = F_16 ( V_29 ) ;
struct V_54 * V_65 = & V_17 -> V_18 ;
void T_2 * V_86 ;
V_55 = ( unsigned long ) V_17 -> V_24 - V_27 ;
V_55 += V_84 ;
if ( ! ( V_65 -> V_66 & V_63 ) )
return - V_87 ;
if ( V_55 < V_65 -> V_20 || ( V_55 + V_23 ) > V_65 -> V_19 )
return - V_87 ;
V_86 = V_17 -> V_24 + V_84 ;
switch ( V_23 ) {
case 1 :
F_50 ( V_86 , V_85 >> 24 ) ;
return 1 ;
case 2 :
if ( V_84 & 1 )
return - V_80 ;
F_51 ( V_86 , V_85 >> 16 ) ;
return 2 ;
case 4 :
if ( V_84 & 3 )
return - V_80 ;
F_52 ( V_86 , V_85 ) ;
return 4 ;
}
return - V_80 ;
}
int F_53 ( struct V_28 * V_29 ,
struct V_77 * V_78 ,
enum V_56 V_57 )
{
struct V_4 * V_17 = F_16 ( V_29 ) ;
T_1 V_55 =
( ( T_1 ) V_78 -> V_79 ) << V_76 ;
T_1 V_23 = V_78 -> V_83 - V_78 -> V_82 ;
struct V_54 * V_65 ;
F_26 ( L_9 ,
F_15 ( V_29 ) , V_29 -> V_89 ,
V_57 == V_61 ? L_10 : L_11 ,
( unsigned long long ) V_55 ,
( unsigned long long ) ( V_55 + V_23 - 1 ) ) ;
if ( V_57 == V_61 ) {
if ( ( V_55 + V_23 ) > V_17 -> V_90 ) {
#ifdef F_54
F_55 ( V_91
L_12
L_13 ,
V_92 -> V_93 , V_92 -> V_94 , F_15 ( V_29 ) ,
V_29 -> V_89 ) ;
#endif
if ( V_78 -> V_95 & V_96 )
return F_56 ( V_78 ) ;
return 0 ;
}
V_55 += V_17 -> V_97 ;
} else {
unsigned long V_58 = ( unsigned long ) V_17 -> V_24 - \
V_27 ;
unsigned long V_98 = V_55 + V_58 ;
V_65 = & V_17 -> V_18 ;
if ( ! ( V_65 -> V_66 & V_63 ) )
return - V_87 ;
if ( V_98 < V_65 -> V_20 || ( V_98 + V_23 ) > V_65 -> V_19 )
return - V_87 ;
V_55 += V_17 -> V_25 ;
}
F_26 ( L_14 , ( unsigned long long ) V_55 ) ;
V_78 -> V_79 = V_55 >> V_76 ;
V_78 -> V_81 = F_36 ( V_78 -> V_81 ) ;
return F_44 ( V_78 , V_78 -> V_82 , V_78 -> V_79 ,
V_78 -> V_83 - V_78 -> V_82 ,
V_78 -> V_81 ) ;
}
void F_57 ( const struct V_37 * V_6 , int V_99 ,
const struct V_54 * V_100 ,
T_1 * V_20 , T_1 * V_19 )
{
struct V_4 * V_17 = F_16 ( V_6 -> V_29 ) ;
T_1 V_55 = 0 ;
if ( V_17 == NULL )
return;
if ( V_100 -> V_66 & V_63 )
V_55 = ( unsigned long ) V_17 -> V_24 - V_27 ;
#if 0
else if (rsrc->flags & IORESOURCE_MEM)
offset = hose->pci_mem_offset;
#endif
* V_20 = V_100 -> V_20 - V_55 ;
* V_19 = V_100 -> V_19 - V_55 ;
}
void T_5 F_58 ( struct V_4 * V_17 ,
struct V_5 * V_6 ,
int V_101 )
{
const T_9 * V_102 ;
int V_103 ;
int V_104 = F_59 ( V_6 ) ;
int V_39 = V_104 + 5 ;
int V_105 = 0 , V_106 = - 1 ;
T_9 V_107 ;
unsigned long long V_108 , V_109 , V_110 , V_111 , V_23 ;
unsigned long long V_112 = 0 ;
struct V_54 * V_113 ;
F_55 ( V_114 L_15 ,
V_6 -> V_40 , V_101 ? L_16 : L_17 ) ;
V_102 = F_60 ( V_6 , L_18 , & V_103 ) ;
if ( V_102 == NULL )
return;
F_26 ( L_19 ) ;
while ( ( V_103 -= V_39 * 4 ) >= 0 ) {
V_107 = V_102 [ 0 ] ;
V_108 = F_61 ( V_102 + 1 , 2 ) ;
V_109 = F_62 ( V_6 , V_102 + 3 ) ;
V_23 = F_61 ( V_102 + V_104 + 3 , 2 ) ;
F_26 ( L_20
L_21 ,
V_107 , V_108 , V_109 , V_23 ) ;
V_102 += V_39 ;
if ( V_109 == V_115 || V_23 == 0 )
continue;
for (; V_103 >= V_39 * sizeof( T_9 ) ;
V_102 += V_39 , V_103 -= V_39 * 4 ) {
if ( V_102 [ 0 ] != V_107 )
break;
V_110 = F_61 ( V_102 + 1 , 2 ) ;
V_111 = F_62 ( V_6 , V_102 + 3 ) ;
if ( V_110 != V_108 + V_23 ||
V_111 != V_109 + V_23 )
break;
V_23 += F_61 ( V_102 + V_104 + 3 , 2 ) ;
}
V_113 = NULL ;
switch ( ( V_107 >> 24 ) & 0x3 ) {
case 1 :
F_55 ( V_114
L_22 ,
V_109 , V_109 + V_23 - 1 , V_108 ) ;
if ( V_17 -> V_116 ) {
F_55 ( V_114
L_23 ) ;
continue;
}
if ( V_23 > 0x01000000 )
V_23 = 0x01000000 ;
V_17 -> V_24 = F_63 ( V_109 , V_23 ) ;
if ( V_101 )
V_117 =
( unsigned long ) V_17 -> V_24 ;
V_17 -> V_116 = V_108 + V_23 ;
V_17 -> V_25 = V_109 - V_108 ;
V_113 = & V_17 -> V_18 ;
V_113 -> V_66 = V_63 ;
V_113 -> V_20 = V_108 ;
break;
case 2 :
case 3 :
F_55 ( V_114
L_24 ,
V_109 , V_109 + V_23 - 1 , V_108 ,
( V_107 & 0x40000000 ) ? L_25 : L_17 ) ;
if ( V_105 >= 3 ) {
F_55 ( V_114
L_23 ) ;
continue;
}
if ( V_108 == 0 ) {
V_112 = V_109 ;
V_106 = V_105 ;
if ( V_101 || V_118 == 0 )
V_118 = V_109 ;
V_17 -> V_97 = V_109 ;
V_17 -> V_90 = V_23 ;
}
if ( V_105 == 0 ||
( V_106 >= 0 && V_108 != 0 &&
V_17 -> V_119 == V_112 ) )
V_17 -> V_119 = V_109 - V_108 ;
else if ( V_108 != 0 &&
V_17 -> V_119 != V_109 - V_108 ) {
F_55 ( V_114
L_26 ) ;
continue;
}
V_113 = & V_17 -> V_120 [ V_105 ++ ] ;
V_113 -> V_66 = V_62 ;
if ( V_107 & 0x40000000 )
V_113 -> V_66 |= V_72 ;
V_113 -> V_20 = V_109 ;
break;
}
if ( V_113 != NULL ) {
V_113 -> V_121 = V_6 -> V_40 ;
V_113 -> V_19 = V_113 -> V_20 + V_23 - 1 ;
V_113 -> V_32 = NULL ;
V_113 -> V_122 = NULL ;
V_113 -> V_123 = NULL ;
}
}
if ( V_106 >= 0 && V_17 -> V_119 != V_112 ) {
unsigned int V_124 = V_106 + 1 ;
F_55 ( V_114 L_27 , V_112 ) ;
if ( V_124 < V_105 )
memmove ( & V_17 -> V_120 [ V_106 ] ,
& V_17 -> V_120 [ V_124 ] ,
sizeof( struct V_54 ) * ( V_105 - V_124 ) ) ;
V_17 -> V_120 [ -- V_105 ] . V_66 = 0 ;
}
}
int F_64 ( struct V_28 * V_29 )
{
struct V_4 * V_17 = F_16 ( V_29 ) ;
if ( ! ( V_125 & V_126 ) )
return 0 ;
if ( V_125 & V_127 )
return V_17 -> V_10 != 0 ;
return 1 ;
}
void F_65 ( struct V_37 * V_6 , struct V_128 * V_129 ,
struct V_54 * V_113 )
{
T_1 V_55 = 0 , V_130 = ( T_1 ) - 1 ;
struct V_4 * V_17 = F_16 ( V_6 -> V_29 ) ;
if ( ! V_17 )
return;
if ( V_113 -> V_66 & V_63 ) {
V_55 = ( unsigned long ) V_17 -> V_24 - V_27 ;
V_130 = 0xffffffffu ;
} else if ( V_113 -> V_66 & V_62 )
V_55 = V_17 -> V_119 ;
V_129 -> V_20 = ( V_113 -> V_20 - V_55 ) & V_130 ;
V_129 -> V_19 = ( V_113 -> V_19 - V_55 ) & V_130 ;
}
void F_66 ( struct V_37 * V_6 , struct V_54 * V_113 ,
struct V_128 * V_129 )
{
T_1 V_55 = 0 , V_130 = ( T_1 ) - 1 ;
struct V_4 * V_17 = F_16 ( V_6 -> V_29 ) ;
if ( ! V_17 )
return;
if ( V_113 -> V_66 & V_63 ) {
V_55 = ( unsigned long ) V_17 -> V_24 - V_27 ;
V_130 = 0xffffffffu ;
} else if ( V_113 -> V_66 & V_62 )
V_55 = V_17 -> V_119 ;
V_113 -> V_20 = ( V_129 -> V_20 + V_55 ) & V_130 ;
V_113 -> V_19 = ( V_129 -> V_19 + V_55 ) & V_130 ;
}
static void T_5 F_67 ( struct V_54 * V_113 , struct V_37 * V_6 )
{
struct V_4 * V_17 = F_16 ( V_6 -> V_29 ) ;
T_1 V_55 = 0 , V_130 = ( T_1 ) - 1 ;
if ( V_113 -> V_66 & V_63 ) {
V_55 = ( unsigned long ) V_17 -> V_24 - V_27 ;
V_130 = 0xffffffffu ;
} else if ( V_113 -> V_66 & V_62 )
V_55 = V_17 -> V_119 ;
V_113 -> V_20 = ( V_113 -> V_20 + V_55 ) & V_130 ;
V_113 -> V_19 = ( V_113 -> V_19 + V_55 ) & V_130 ;
}
static void T_5 F_68 ( struct V_37 * V_6 )
{
struct V_4 * V_17 = F_16 ( V_6 -> V_29 ) ;
int V_59 ;
if ( ! V_17 ) {
F_55 ( V_131 L_28 ,
F_27 ( V_6 ) ) ;
return;
}
for ( V_59 = 0 ; V_59 < V_132 ; V_59 ++ ) {
struct V_54 * V_113 = V_6 -> V_54 + V_59 ;
if ( ! V_113 -> V_66 )
continue;
if ( V_113 -> V_20 == 0 && ! ( V_125 & V_133 ) ) {
F_26 ( L_29 \
L_30 ,
F_27 ( V_6 ) , V_59 ,
( unsigned long long ) V_113 -> V_20 ,
( unsigned long long ) V_113 -> V_19 ,
( unsigned int ) V_113 -> V_66 ) ;
V_113 -> V_19 -= V_113 -> V_20 ;
V_113 -> V_20 = 0 ;
V_113 -> V_66 |= V_134 ;
continue;
}
F_26 ( L_31 ,
F_27 ( V_6 ) , V_59 ,
( unsigned long long ) V_113 -> V_20 ,\
( unsigned long long ) V_113 -> V_19 ,
( unsigned int ) V_113 -> V_66 ) ;
F_67 ( V_113 , V_6 ) ;
F_26 ( L_32 ,
F_27 ( V_6 ) ,
( unsigned long long ) V_113 -> V_20 ,
( unsigned long long ) V_113 -> V_19 ) ;
}
}
static int T_5 F_69 ( struct V_28 * V_29 ,
struct V_54 * V_113 )
{
struct V_4 * V_17 = F_16 ( V_29 ) ;
struct V_37 * V_6 = V_29 -> V_135 ;
T_1 V_55 ;
V_88 V_136 ;
int V_59 ;
if ( V_125 & V_133 )
return 0 ;
if ( V_113 -> V_66 & V_62 ) {
if ( V_113 -> V_20 != V_17 -> V_119 )
return 0 ;
F_70 ( V_6 , V_137 , & V_136 ) ;
if ( ( V_136 & V_138 ) == 0 )
return 1 ;
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
if ( ( V_17 -> V_120 [ V_59 ] . V_66 & V_62 ) &&
V_17 -> V_120 [ V_59 ] . V_20 == V_17 -> V_119 )
return 0 ;
}
return 1 ;
} else {
V_55 = ( unsigned long ) V_17 -> V_24 - V_27 ;
if ( ( ( V_113 -> V_20 - V_55 ) & 0xfffffffful ) != 0 )
return 0 ;
F_70 ( V_6 , V_137 , & V_136 ) ;
if ( V_136 & V_139 )
return 0 ;
return 1 ;
}
}
static void T_5 F_71 ( struct V_28 * V_29 )
{
struct V_54 * V_113 ;
int V_59 ;
struct V_37 * V_6 = V_29 -> V_135 ;
F_72 (bus, res, i) {
V_113 = V_29 -> V_54 [ V_59 ] ;
if ( ! V_113 )
continue;
if ( ! V_113 -> V_66 )
continue;
if ( V_59 >= 3 && V_29 -> V_135 -> V_140 )
continue;
F_26 ( L_33 ,
F_27 ( V_6 ) , V_59 ,
( unsigned long long ) V_113 -> V_20 ,\
( unsigned long long ) V_113 -> V_19 ,
( unsigned int ) V_113 -> V_66 ) ;
F_67 ( V_113 , V_6 ) ;
if ( F_69 ( V_29 , V_113 ) ) {
V_113 -> V_66 = 0 ;
F_26 ( L_34 ,
F_27 ( V_6 ) ) ;
} else {
F_26 ( L_32 ,
F_27 ( V_6 ) ,
( unsigned long long ) V_113 -> V_20 ,
( unsigned long long ) V_113 -> V_19 ) ;
}
}
}
void T_5 F_73 ( struct V_28 * V_29 )
{
if ( V_29 -> V_135 != NULL )
F_71 ( V_29 ) ;
}
void T_5 F_74 ( struct V_28 * V_29 )
{
struct V_37 * V_6 ;
F_26 ( L_35 ,
V_29 -> V_89 , V_29 -> V_135 ? F_27 ( V_29 -> V_135 ) : L_36 ) ;
F_13 (dev, &bus->devices, bus_list) {
V_6 -> V_6 . V_141 = F_21 ( V_6 ) ;
F_75 ( & V_6 -> V_6 , F_76 ( V_6 -> V_29 ) ) ;
F_77 ( & V_6 -> V_6 , V_3 ) ;
V_6 -> V_6 . V_142 . V_143 = ( void * ) V_144 ;
F_25 ( V_6 ) ;
}
}
void T_5 F_78 ( struct V_28 * V_29 )
{
if ( V_29 -> V_135 != NULL )
F_79 ( V_29 ) ;
F_73 ( V_29 ) ;
F_74 ( V_29 ) ;
}
static int F_80 ( struct V_37 * V_6 )
{
if ( ( V_125 & V_145 ) &&
! ( V_6 -> V_29 -> V_146 & V_147 ) )
return 1 ;
return 0 ;
}
T_1 F_81 ( void * V_148 , const struct V_54 * V_113 ,
T_1 V_23 , T_1 V_149 )
{
struct V_37 * V_6 = V_148 ;
T_1 V_20 = V_113 -> V_20 ;
if ( V_113 -> V_66 & V_63 ) {
if ( F_80 ( V_6 ) )
return V_20 ;
if ( V_20 & 0x300 )
V_20 = ( V_20 + 0x3ff ) & ~ 0x3ff ;
}
return V_20 ;
}
static int T_11 F_82 ( struct V_54 * V_32 ,
struct V_54 * V_113 )
{
struct V_54 * V_150 , * * V_151 ;
struct V_54 * * V_152 = NULL ;
for ( V_151 = & V_32 -> V_123 ; ( V_150 = * V_151 ) != NULL ; V_151 = & V_150 -> V_122 ) {
if ( V_150 -> V_19 < V_113 -> V_20 )
continue;
if ( V_113 -> V_19 < V_150 -> V_20 )
break;
if ( V_150 -> V_20 < V_113 -> V_20 || V_150 -> V_19 > V_113 -> V_19 )
return - 1 ;
if ( V_152 == NULL )
V_152 = V_151 ;
}
if ( V_152 == NULL )
return - 1 ;
V_113 -> V_32 = V_32 ;
V_113 -> V_123 = * V_152 ;
V_113 -> V_122 = * V_151 ;
* V_152 = V_113 ;
* V_151 = NULL ;
for ( V_150 = V_113 -> V_123 ; V_150 != NULL ; V_150 = V_150 -> V_122 ) {
V_150 -> V_32 = V_113 ;
F_26 ( L_37 ,
V_150 -> V_121 ,
( unsigned long long ) V_150 -> V_20 ,
( unsigned long long ) V_150 -> V_19 , V_113 -> V_121 ) ;
}
return 0 ;
}
void F_83 ( struct V_28 * V_29 )
{
struct V_28 * V_153 ;
int V_59 ;
struct V_54 * V_113 , * V_154 ;
F_26 ( L_38 ,
F_15 ( V_29 ) , V_29 -> V_89 ) ;
F_72 (bus, res, i) {
V_113 = V_29 -> V_54 [ V_59 ] ;
if ( ! V_113 || ! V_113 -> V_66
|| V_113 -> V_20 > V_113 -> V_19 || V_113 -> V_32 )
continue;
if ( V_29 -> V_32 == NULL )
V_154 = ( V_113 -> V_66 & V_63 ) ?
& V_155 : & V_156 ;
else {
if ( V_125 & V_157 )
goto V_158;
V_154 = F_84 ( V_29 -> V_135 , V_113 ) ;
if ( V_154 == V_113 ) {
continue;
}
}
F_26 ( L_39
L_40 ,
V_29 -> V_135 ? F_27 ( V_29 -> V_135 ) : L_36 ,
V_29 -> V_89 , V_59 ,
( unsigned long long ) V_113 -> V_20 ,
( unsigned long long ) V_113 -> V_19 ,
( unsigned int ) V_113 -> V_66 ,
V_154 , ( V_154 && V_154 -> V_121 ) ? V_154 -> V_121 : L_41 ) ;
if ( V_154 && ! ( V_154 -> V_66 & V_134 ) ) {
if ( F_85 ( V_154 , V_113 ) == 0 )
continue;
if ( F_82 ( V_154 , V_113 ) == 0 )
continue;
}
F_55 ( V_159 L_42
L_43 , V_59 , V_29 -> V_89 ) ;
V_158:
V_113 -> V_20 = V_113 -> V_19 = 0 ;
V_113 -> V_66 = 0 ;
}
F_13 (b, &bus->children, node)
F_83 ( V_153 ) ;
}
static inline void T_5 F_86 ( struct V_37 * V_6 , int V_160 )
{
struct V_54 * V_154 , * V_161 = & V_6 -> V_54 [ V_160 ] ;
F_26 ( L_44 ,
F_27 ( V_6 ) , V_160 ,
( unsigned long long ) V_161 -> V_20 ,
( unsigned long long ) V_161 -> V_19 ,
( unsigned int ) V_161 -> V_66 ) ;
V_154 = F_84 ( V_6 , V_161 ) ;
if ( ! V_154 || ( V_154 -> V_66 & V_134 ) ||
F_85 ( V_154 , V_161 ) < 0 ) {
F_55 ( V_159 L_45
L_46 , V_160 , F_27 ( V_6 ) ) ;
if ( V_154 )
F_26 ( L_47 ,
V_154 ,
( unsigned long long ) V_154 -> V_20 ,
( unsigned long long ) V_154 -> V_19 ,
( unsigned int ) V_154 -> V_66 ) ;
V_161 -> V_66 |= V_134 ;
V_161 -> V_19 -= V_161 -> V_20 ;
V_161 -> V_20 = 0 ;
}
}
static void T_11 F_87 ( int V_162 )
{
struct V_37 * V_6 = NULL ;
int V_160 , V_163 ;
V_88 V_136 ;
struct V_54 * V_161 ;
F_39 (dev) {
F_70 ( V_6 , V_137 , & V_136 ) ;
for ( V_160 = 0 ; V_160 <= V_64 ; V_160 ++ ) {
V_161 = & V_6 -> V_54 [ V_160 ] ;
if ( V_161 -> V_32 )
continue;
if ( ! V_161 -> V_66 || ( V_161 -> V_66 & V_134 ) )
continue;
if ( V_160 == V_64 )
V_163 = 1 ;
if ( V_161 -> V_66 & V_63 )
V_163 = ! ( V_136 & V_139 ) ;
else
V_163 = ! ( V_136 & V_138 ) ;
if ( V_162 == V_163 )
F_86 ( V_6 , V_160 ) ;
}
if ( V_162 )
continue;
V_161 = & V_6 -> V_54 [ V_64 ] ;
if ( V_161 -> V_66 ) {
T_9 V_164 ;
F_88 ( V_6 , V_6 -> V_165 , & V_164 ) ;
if ( V_164 & V_166 ) {
F_26 ( L_48 ,
F_27 ( V_6 ) ) ;
V_161 -> V_66 &= ~ V_167 ;
F_89 ( V_6 , V_6 -> V_165 ,
V_164 & ~ V_166 ) ;
}
}
}
}
static void T_11 F_90 ( struct V_28 * V_29 )
{
struct V_4 * V_17 = F_16 ( V_29 ) ;
T_1 V_55 ;
struct V_54 * V_113 , * V_168 ;
int V_59 ;
F_26 ( L_49 ,
F_15 ( V_29 ) ) ;
if ( ! ( V_17 -> V_18 . V_66 & V_63 ) )
goto V_169;
V_55 = ( unsigned long ) V_17 -> V_24 - V_27 ;
V_113 = F_91 ( sizeof( struct V_54 ) , V_8 ) ;
F_92 ( V_113 == NULL ) ;
V_113 -> V_121 = L_50 ;
V_113 -> V_66 = V_63 ;
V_113 -> V_20 = V_55 ;
V_113 -> V_19 = ( V_55 + 0xfff ) & 0xfffffffful ;
F_26 ( L_51 , V_113 ) ;
if ( F_85 ( & V_17 -> V_18 , V_113 ) ) {
F_55 ( V_91
L_52 ,
F_15 ( V_29 ) , V_29 -> V_89 , V_113 ) ;
F_10 ( V_113 ) ;
}
V_169:
V_55 = V_17 -> V_119 ;
F_26 ( L_53 , ( unsigned long long ) V_55 ) ;
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
V_168 = & V_17 -> V_120 [ V_59 ] ;
if ( ! ( V_168 -> V_66 & V_62 ) )
continue;
F_26 ( L_54 , V_168 ) ;
if ( ( V_168 -> V_20 - V_55 ) <= 0xa0000 &&
( V_168 -> V_19 - V_55 ) >= 0xbffff )
break;
}
if ( V_59 >= 3 )
return;
V_113 = F_91 ( sizeof( struct V_54 ) , V_8 ) ;
F_92 ( V_113 == NULL ) ;
V_113 -> V_121 = L_55 ;
V_113 -> V_66 = V_62 ;
V_113 -> V_20 = 0xa0000 + V_55 ;
V_113 -> V_19 = 0xbffff + V_55 ;
F_26 ( L_56 , V_113 ) ;
if ( F_85 ( V_168 , V_113 ) ) {
F_55 ( V_91
L_57 ,
F_15 ( V_29 ) , V_29 -> V_89 , V_113 ) ;
F_10 ( V_113 ) ;
}
}
void T_11 F_93 ( void )
{
struct V_28 * V_153 ;
F_13 (b, &pci_root_buses, node)
F_83 ( V_153 ) ;
if ( ! ( V_125 & V_157 ) ) {
F_87 ( 0 ) ;
F_87 ( 1 ) ;
}
if ( ! ( V_125 & V_133 ) ) {
F_13 (b, &pci_root_buses, node)
F_90 ( V_153 ) ;
}
if ( ! ( V_125 & V_133 ) ) {
F_26 ( L_58 ) ;
F_94 () ;
}
}
void T_5 F_95 ( struct V_28 * V_29 )
{
struct V_37 * V_6 ;
struct V_28 * V_170 ;
F_13 (dev, &bus->devices, bus_list) {
int V_59 ;
for ( V_59 = 0 ; V_59 < V_171 ; V_59 ++ ) {
struct V_54 * V_161 = & V_6 -> V_54 [ V_59 ] ;
if ( V_161 -> V_32 || ! V_161 -> V_20 || ! V_161 -> V_66 )
continue;
F_26 ( L_59
L_60 ,
F_27 ( V_6 ) , V_59 ,
( unsigned long long ) V_161 -> V_20 ,
( unsigned long long ) V_161 -> V_19 ,
( unsigned int ) V_161 -> V_66 ) ;
F_96 ( V_6 , V_59 ) ;
}
}
F_13 (child_bus, &bus->children, node)
F_95 ( V_170 ) ;
}
void F_97 ( struct V_28 * V_29 )
{
F_26 ( L_61 ,
F_15 ( V_29 ) , V_29 -> V_89 ) ;
F_83 ( V_29 ) ;
F_95 ( V_29 ) ;
F_98 ( V_29 ) ;
}
int F_99 ( struct V_37 * V_6 , int V_130 )
{
return F_100 ( V_6 , V_130 ) ;
}
void T_5 F_101 ( struct V_4 * V_17 )
{
struct V_28 * V_29 = V_17 -> V_29 ;
struct V_54 * V_113 ;
int V_59 ;
V_29 -> V_54 [ 0 ] = V_113 = & V_17 -> V_18 ;
if ( ! V_113 -> V_66 ) {
F_55 ( V_159 L_62
L_63 ,
V_17 -> V_14 -> V_40 , V_17 -> V_10 ) ;
V_113 -> V_20 = ( unsigned long ) V_17 -> V_24 - V_117 ;
V_113 -> V_19 = V_113 -> V_20 + V_172 ;
V_113 -> V_66 = V_63 ;
}
F_26 ( L_64 ,
( unsigned long long ) V_113 -> V_20 ,
( unsigned long long ) V_113 -> V_19 ,
( unsigned long ) V_113 -> V_66 ) ;
for ( V_59 = 0 ; V_59 < 3 ; ++ V_59 ) {
V_113 = & V_17 -> V_120 [ V_59 ] ;
if ( ! V_113 -> V_66 ) {
if ( V_59 > 0 )
continue;
F_55 ( V_131 L_65
L_66 ,
V_17 -> V_14 -> V_40 , V_17 -> V_10 ) ;
V_113 -> V_20 = V_17 -> V_119 ;
V_113 -> V_19 = ( T_1 ) - 1LL ;
V_113 -> V_66 = V_62 ;
}
V_29 -> V_54 [ V_59 + 1 ] = V_113 ;
F_26 ( L_67 ,
V_59 , ( unsigned long long ) V_113 -> V_20 ,
( unsigned long long ) V_113 -> V_19 ,
( unsigned long ) V_113 -> V_66 ) ;
}
F_26 ( L_68 ,
( unsigned long long ) V_17 -> V_119 ) ;
F_26 ( L_69 ,
( unsigned long ) V_17 -> V_24 - V_27 ) ;
}
static int
F_102 ( struct V_28 * V_29 , unsigned int V_173 , int V_55 ,
int V_174 , T_9 * V_85 )
{
return V_175 ;
}
static int
F_103 ( struct V_28 * V_29 , unsigned int V_173 , int V_55 ,
int V_174 , T_9 V_85 )
{
return V_175 ;
}
static struct V_28 *
F_104 ( struct V_4 * V_17 , int V_176 )
{
static struct V_28 V_29 ;
if ( ! V_17 )
F_55 ( V_131 L_70 , V_176 ) ;
V_29 . V_89 = V_176 ;
V_29 . V_177 = V_17 ;
V_29 . V_178 = V_17 ? V_17 -> V_178 : & V_179 ;
return & V_29 ;
}
int F_105 ( struct V_4 * V_17 , int V_29 , int V_173 ,
int V_180 )
{
return F_106 ( F_104 ( V_17 , V_29 ) , V_173 , V_180 ) ;
}
