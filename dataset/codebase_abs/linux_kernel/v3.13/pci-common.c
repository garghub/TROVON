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
static struct V_40 * F_26 ( struct V_35 * V_6 ,
T_1 * V_41 ,
enum V_42 V_43 )
{
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
unsigned long V_44 = 0 ;
int V_45 , V_46 ;
if ( ! V_17 )
return NULL ;
if ( V_43 == V_47 ) {
#if 0
*offset += hose->pci_mem_offset;
#endif
V_46 = V_48 ;
} else {
V_44 = ( unsigned long ) V_17 -> V_22 - V_25 ;
* V_41 += V_44 ;
V_46 = V_49 ;
}
for ( V_45 = 0 ; V_45 <= V_50 ; V_45 ++ ) {
struct V_40 * V_51 = & V_6 -> V_40 [ V_45 ] ;
int V_52 = V_51 -> V_52 ;
if ( V_45 == V_50 )
V_52 |= V_48 ;
if ( ( V_52 & V_46 ) == 0 )
continue;
if ( * V_41 < ( V_51 -> V_53 & V_54 ) || * V_41 > V_51 -> V_55 )
continue;
if ( V_43 == V_56 )
* V_41 += V_17 -> V_23 - V_44 ;
return V_51 ;
}
return NULL ;
}
static T_5 F_27 ( struct V_35 * V_6 , struct V_40 * V_51 ,
T_5 V_57 ,
enum V_42 V_43 ,
int V_58 )
{
T_5 V_59 = V_57 ;
if ( V_43 != V_47 )
V_58 = 0 ;
else if ( V_58 == 0 ) {
if ( V_51 -> V_52 & V_60 )
V_58 = 1 ;
}
return F_28 ( V_59 ) ;
}
T_5 F_29 ( struct V_61 * V_61 ,
unsigned long V_62 ,
unsigned long V_21 ,
T_5 V_59 )
{
struct V_35 * V_36 = NULL ;
struct V_40 * V_63 = NULL ;
T_1 V_41 = ( ( T_1 ) V_62 ) << V_64 ;
int V_45 ;
if ( F_30 ( V_62 ) )
return V_59 ;
V_59 = F_28 ( V_59 ) ;
F_31 (pdev) {
for ( V_45 = 0 ; V_45 <= V_50 ; V_45 ++ ) {
struct V_40 * V_51 = & V_36 -> V_40 [ V_45 ] ;
int V_52 = V_51 -> V_52 ;
if ( ( V_52 & V_48 ) == 0 )
continue;
if ( V_41 < ( V_51 -> V_53 & V_54 ) ||
V_41 > V_51 -> V_55 )
continue;
V_63 = V_51 ;
break;
}
if ( V_63 )
break;
}
if ( V_63 ) {
if ( V_63 -> V_52 & V_60 )
V_59 = F_32 ( V_59 ) ;
F_33 ( V_36 ) ;
}
F_34 ( L_2 ,
( unsigned long long ) V_41 , F_35 ( V_59 ) ) ;
return V_59 ;
}
int F_36 ( struct V_35 * V_6 , struct V_65 * V_66 ,
enum V_42 V_43 , int V_58 )
{
T_1 V_41 =
( ( T_1 ) V_66 -> V_67 ) << V_64 ;
struct V_40 * V_51 ;
int V_20 ;
V_51 = F_26 ( V_6 , & V_41 , V_43 ) ;
if ( V_51 == NULL )
return - V_68 ;
V_66 -> V_67 = V_41 >> V_64 ;
V_66 -> V_69 = F_27 ( V_6 , V_51 ,
V_66 -> V_69 ,
V_43 , V_58 ) ;
V_20 = F_37 ( V_66 , V_66 -> V_70 , V_66 -> V_67 ,
V_66 -> V_71 - V_66 -> V_70 , V_66 -> V_69 ) ;
return V_20 ;
}
int F_38 ( struct V_26 * V_27 , T_6 V_72 , T_7 * V_73 , T_8 V_21 )
{
unsigned long V_41 ;
struct V_4 * V_17 = F_17 ( V_27 ) ;
struct V_40 * V_51 = & V_17 -> V_18 ;
void T_2 * V_74 ;
V_41 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_41 += V_72 ;
if ( ! ( V_51 -> V_52 & V_49 ) )
return - V_75 ;
if ( V_41 < V_51 -> V_53 || ( V_41 + V_21 ) > V_51 -> V_55 )
return - V_75 ;
V_74 = V_17 -> V_22 + V_72 ;
switch ( V_21 ) {
case 1 :
* ( ( V_76 * ) V_73 ) = F_39 ( V_74 ) ;
return 1 ;
case 2 :
if ( V_72 & 1 )
return - V_68 ;
* ( ( V_77 * ) V_73 ) = F_40 ( V_74 ) ;
return 2 ;
case 4 :
if ( V_72 & 3 )
return - V_68 ;
* ( ( T_7 * ) V_73 ) = F_41 ( V_74 ) ;
return 4 ;
}
return - V_68 ;
}
int F_42 ( struct V_26 * V_27 , T_6 V_72 , T_7 V_73 , T_8 V_21 )
{
unsigned long V_41 ;
struct V_4 * V_17 = F_17 ( V_27 ) ;
struct V_40 * V_51 = & V_17 -> V_18 ;
void T_2 * V_74 ;
V_41 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_41 += V_72 ;
if ( ! ( V_51 -> V_52 & V_49 ) )
return - V_75 ;
if ( V_41 < V_51 -> V_53 || ( V_41 + V_21 ) > V_51 -> V_55 )
return - V_75 ;
V_74 = V_17 -> V_22 + V_72 ;
switch ( V_21 ) {
case 1 :
F_43 ( V_74 , V_73 >> 24 ) ;
return 1 ;
case 2 :
if ( V_72 & 1 )
return - V_68 ;
F_44 ( V_74 , V_73 >> 16 ) ;
return 2 ;
case 4 :
if ( V_72 & 3 )
return - V_68 ;
F_45 ( V_74 , V_73 ) ;
return 4 ;
}
return - V_68 ;
}
int F_46 ( struct V_26 * V_27 ,
struct V_65 * V_66 ,
enum V_42 V_43 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
T_1 V_41 =
( ( T_1 ) V_66 -> V_67 ) << V_64 ;
T_1 V_21 = V_66 -> V_71 - V_66 -> V_70 ;
struct V_40 * V_51 ;
F_34 ( L_3 ,
F_16 ( V_27 ) , V_27 -> V_78 ,
V_43 == V_47 ? L_4 : L_5 ,
( unsigned long long ) V_41 ,
( unsigned long long ) ( V_41 + V_21 - 1 ) ) ;
if ( V_43 == V_47 ) {
if ( ( V_41 + V_21 ) > V_17 -> V_79 ) {
#ifdef F_47
F_34 ( L_6 ,
V_80 -> V_81 , V_80 -> V_82 ) ;
F_34 ( L_7 ,
F_16 ( V_27 ) , V_27 -> V_78 ) ;
#endif
if ( V_66 -> V_83 & V_84 )
return F_48 ( V_66 ) ;
return 0 ;
}
V_41 += V_17 -> V_85 ;
} else {
unsigned long V_44 = ( unsigned long ) V_17 -> V_22 -
V_25 ;
unsigned long V_86 = V_41 + V_44 ;
V_51 = & V_17 -> V_18 ;
if ( ! ( V_51 -> V_52 & V_49 ) )
return - V_75 ;
if ( V_86 < V_51 -> V_53 || ( V_86 + V_21 ) > V_51 -> V_55 )
return - V_75 ;
V_41 += V_17 -> V_23 ;
}
F_34 ( L_8 , ( unsigned long long ) V_41 ) ;
V_66 -> V_67 = V_41 >> V_64 ;
V_66 -> V_69 = F_28 ( V_66 -> V_69 ) ;
return F_37 ( V_66 , V_66 -> V_70 , V_66 -> V_67 ,
V_66 -> V_71 - V_66 -> V_70 ,
V_66 -> V_69 ) ;
}
void F_49 ( const struct V_35 * V_6 , int V_87 ,
const struct V_40 * V_88 ,
T_1 * V_53 , T_1 * V_55 )
{
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
T_1 V_41 = 0 ;
if ( V_17 == NULL )
return;
if ( V_88 -> V_52 & V_49 )
V_41 = ( unsigned long ) V_17 -> V_22 - V_25 ;
#if 0
else if (rsrc->flags & IORESOURCE_MEM)
offset = hose->pci_mem_offset;
#endif
* V_53 = V_88 -> V_53 - V_41 ;
* V_55 = V_88 -> V_55 - V_41 ;
}
void F_50 ( struct V_4 * V_17 ,
struct V_5 * V_6 , int V_89 )
{
int V_90 = 0 , V_91 = - 1 ;
unsigned long long V_92 = 0 ;
struct V_40 * V_93 ;
struct V_94 V_95 ;
struct V_96 V_97 ;
F_51 ( L_9 ,
V_6 -> V_38 , V_89 ? L_10 : L_11 ) ;
if ( F_52 ( & V_97 , V_6 ) )
return;
F_34 ( L_12 ) ;
F_53 (&parser, &range) {
F_34 ( L_13 ,
V_95 . V_98 , V_95 . V_99 ) ;
F_34 ( L_14 ,
V_95 . V_100 , V_95 . V_21 ) ;
if ( V_95 . V_100 == V_101 || V_95 . V_21 == 0 )
continue;
V_93 = NULL ;
switch ( V_95 . V_52 & V_102 ) {
case V_49 :
F_51 ( L_15 ,
V_95 . V_100 , V_95 . V_100 + V_95 . V_21 - 1 ,
V_95 . V_99 ) ;
if ( V_17 -> V_103 ) {
F_51 ( L_16 ) ;
continue;
}
if ( V_95 . V_21 > 0x01000000 )
V_95 . V_21 = 0x01000000 ;
V_17 -> V_22 = F_54 ( V_95 . V_100 ,
V_95 . V_21 ) ;
if ( V_89 )
V_104 =
( unsigned long ) V_17 -> V_22 ;
V_17 -> V_103 = V_95 . V_99 + V_95 . V_21 ;
V_17 -> V_23 = V_95 . V_100 - V_95 . V_99 ;
V_93 = & V_17 -> V_18 ;
V_95 . V_100 = V_95 . V_99 ;
break;
case V_48 :
F_51 ( L_17 ,
V_95 . V_100 , V_95 . V_100 + V_95 . V_21 - 1 ,
V_95 . V_99 ,
( V_95 . V_98 & 0x40000000 ) ?
L_18 : L_11 ) ;
if ( V_90 >= 3 ) {
F_51 ( L_16 ) ;
continue;
}
if ( V_95 . V_99 == 0 ) {
V_92 = V_95 . V_100 ;
V_91 = V_90 ;
if ( V_89 || V_105 == 0 )
V_105 = V_95 . V_100 ;
V_17 -> V_85 = V_95 . V_100 ;
V_17 -> V_79 = V_95 . V_21 ;
}
if ( V_90 == 0 ||
( V_91 >= 0 && V_95 . V_99 != 0 &&
V_17 -> V_106 == V_92 ) )
V_17 -> V_106 = V_95 . V_100 -
V_95 . V_99 ;
else if ( V_95 . V_99 != 0 &&
V_17 -> V_106 != V_95 . V_100 -
V_95 . V_99 ) {
F_51 ( L_19 ) ;
continue;
}
V_93 = & V_17 -> V_107 [ V_90 ++ ] ;
break;
}
if ( V_93 != NULL )
F_55 ( & V_95 , V_6 , V_93 ) ;
}
if ( V_91 >= 0 && V_17 -> V_106 != V_92 ) {
unsigned int V_108 = V_91 + 1 ;
F_51 ( L_20 , V_92 ) ;
if ( V_108 < V_90 )
memmove ( & V_17 -> V_107 [ V_91 ] ,
& V_17 -> V_107 [ V_108 ] ,
sizeof( struct V_40 ) * ( V_90 - V_108 ) ) ;
V_17 -> V_107 [ -- V_90 ] . V_52 = 0 ;
}
}
int F_56 ( struct V_26 * V_27 )
{
return 0 ;
}
static void F_57 ( struct V_35 * V_6 )
{
struct V_4 * V_17 = F_17 ( V_6 -> V_27 ) ;
int V_45 ;
if ( ! V_17 ) {
F_58 ( L_21 ,
F_59 ( V_6 ) ) ;
return;
}
for ( V_45 = 0 ; V_45 < V_109 ; V_45 ++ ) {
struct V_40 * V_93 = V_6 -> V_40 + V_45 ;
if ( ! V_93 -> V_52 )
continue;
if ( V_93 -> V_53 == 0 ) {
F_34 ( L_22 ,
F_59 ( V_6 ) , V_45 ,
( unsigned long long ) V_93 -> V_53 ,
( unsigned long long ) V_93 -> V_55 ,
( unsigned int ) V_93 -> V_52 ) ;
F_34 ( L_23 ) ;
V_93 -> V_55 -= V_93 -> V_53 ;
V_93 -> V_53 = 0 ;
V_93 -> V_52 |= V_110 ;
continue;
}
F_34 ( L_24 ,
F_59 ( V_6 ) , V_45 ,
( unsigned long long ) V_93 -> V_53 ,
( unsigned long long ) V_93 -> V_55 ,
( unsigned int ) V_93 -> V_52 ) ;
}
}
static int F_60 ( struct V_26 * V_27 ,
struct V_40 * V_93 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
struct V_35 * V_6 = V_27 -> V_111 ;
T_1 V_41 ;
V_77 V_112 ;
int V_45 ;
if ( V_93 -> V_52 & V_48 ) {
if ( V_93 -> V_53 != V_17 -> V_106 )
return 0 ;
F_61 ( V_6 , V_113 , & V_112 ) ;
if ( ( V_112 & V_114 ) == 0 )
return 1 ;
for ( V_45 = 0 ; V_45 < 3 ; V_45 ++ ) {
if ( ( V_17 -> V_107 [ V_45 ] . V_52 & V_48 ) &&
V_17 -> V_107 [ V_45 ] . V_53 == V_17 -> V_106 )
return 0 ;
}
return 1 ;
} else {
V_41 = ( unsigned long ) V_17 -> V_22 - V_25 ;
if ( ( ( V_93 -> V_53 - V_41 ) & 0xfffffffful ) != 0 )
return 0 ;
F_61 ( V_6 , V_113 , & V_112 ) ;
if ( V_112 & V_115 )
return 0 ;
return 1 ;
}
}
static void F_62 ( struct V_26 * V_27 )
{
struct V_40 * V_93 ;
int V_45 ;
struct V_35 * V_6 = V_27 -> V_111 ;
F_63 (bus, res, i) {
if ( ! V_93 )
continue;
if ( ! V_93 -> V_52 )
continue;
if ( V_45 >= 3 && V_27 -> V_111 -> V_116 )
continue;
F_34 ( L_25 ,
F_59 ( V_6 ) , V_45 ,
( unsigned long long ) V_93 -> V_53 ,
( unsigned long long ) V_93 -> V_55 ,
( unsigned int ) V_93 -> V_52 ) ;
if ( F_60 ( V_27 , V_93 ) ) {
V_93 -> V_52 = 0 ;
F_34 ( L_26 ,
F_59 ( V_6 ) ) ;
} else {
F_34 ( L_27 ,
F_59 ( V_6 ) ,
( unsigned long long ) V_93 -> V_53 ,
( unsigned long long ) V_93 -> V_55 ) ;
}
}
}
void F_64 ( struct V_26 * V_27 )
{
if ( V_27 -> V_111 != NULL )
F_62 ( V_27 ) ;
}
void F_65 ( struct V_26 * V_27 )
{
struct V_35 * V_6 ;
F_34 ( L_28 ,
V_27 -> V_78 , V_27 -> V_111 ? F_59 ( V_27 -> V_111 ) : L_29 ) ;
F_14 (dev, &bus->devices, bus_list) {
V_6 -> V_6 . V_117 = F_22 ( V_6 ) ;
F_66 ( & V_6 -> V_6 , F_67 ( V_6 -> V_27 ) ) ;
F_68 ( & V_6 -> V_6 , V_3 ) ;
V_6 -> V_6 . V_118 . V_119 = ( void * ) V_120 ;
V_6 -> V_121 = F_69 ( V_6 , 0 , 0 ) ;
}
}
void F_70 ( struct V_26 * V_27 )
{
if ( V_27 -> V_111 != NULL )
F_71 ( V_27 ) ;
F_64 ( V_27 ) ;
F_65 ( V_27 ) ;
}
static int F_72 ( struct V_35 * V_6 )
{
return 0 ;
}
T_1 F_73 ( void * V_122 , const struct V_40 * V_93 ,
T_1 V_21 , T_1 V_123 )
{
struct V_35 * V_6 = V_122 ;
T_1 V_53 = V_93 -> V_53 ;
if ( V_93 -> V_52 & V_49 ) {
if ( F_72 ( V_6 ) )
return V_53 ;
if ( V_53 & 0x300 )
V_53 = ( V_53 + 0x3ff ) & ~ 0x3ff ;
}
return V_53 ;
}
static int T_9 F_74 ( struct V_40 * V_30 ,
struct V_40 * V_93 )
{
struct V_40 * V_124 , * * V_125 ;
struct V_40 * * V_126 = NULL ;
for ( V_125 = & V_30 -> V_127 ; ( V_124 = * V_125 ) != NULL ; V_125 = & V_124 -> V_128 ) {
if ( V_124 -> V_55 < V_93 -> V_53 )
continue;
if ( V_93 -> V_55 < V_124 -> V_53 )
break;
if ( V_124 -> V_53 < V_93 -> V_53 || V_124 -> V_55 > V_93 -> V_55 )
return - 1 ;
if ( V_126 == NULL )
V_126 = V_125 ;
}
if ( V_126 == NULL )
return - 1 ;
V_93 -> V_30 = V_30 ;
V_93 -> V_127 = * V_126 ;
V_93 -> V_128 = * V_125 ;
* V_126 = V_93 ;
* V_125 = NULL ;
for ( V_124 = V_93 -> V_127 ; V_124 != NULL ; V_124 = V_124 -> V_128 ) {
V_124 -> V_30 = V_93 ;
F_34 ( L_30 ,
V_124 -> V_129 ,
( unsigned long long ) V_124 -> V_53 ,
( unsigned long long ) V_124 -> V_55 , V_93 -> V_129 ) ;
}
return 0 ;
}
static void F_75 ( struct V_26 * V_27 )
{
struct V_26 * V_130 ;
int V_45 ;
struct V_40 * V_93 , * V_131 ;
F_34 ( L_31 ,
F_16 ( V_27 ) , V_27 -> V_78 ) ;
F_63 (bus, res, i) {
if ( ! V_93 || ! V_93 -> V_52
|| V_93 -> V_53 > V_93 -> V_55 || V_93 -> V_30 )
continue;
if ( V_27 -> V_30 == NULL )
V_131 = ( V_93 -> V_52 & V_49 ) ?
& V_132 : & V_133 ;
else {
V_131 = F_76 ( V_27 -> V_111 , V_93 ) ;
if ( V_131 == V_93 ) {
continue;
}
}
F_34 ( L_32 ,
V_27 -> V_111 ? F_59 ( V_27 -> V_111 ) : L_29 ,
V_27 -> V_78 , V_45 ,
( unsigned long long ) V_93 -> V_53 ,
( unsigned long long ) V_93 -> V_55 ) ;
F_34 ( L_33 ,
( unsigned int ) V_93 -> V_52 ,
V_131 , ( V_131 && V_131 -> V_129 ) ? V_131 -> V_129 : L_34 ) ;
if ( V_131 && ! ( V_131 -> V_52 & V_110 ) ) {
if ( F_77 ( V_131 , V_93 ) == 0 )
continue;
if ( F_74 ( V_131 , V_93 ) == 0 )
continue;
}
F_78 ( L_35 ) ;
F_79 ( L_36 , V_45 , V_27 -> V_78 ) ;
V_93 -> V_53 = V_93 -> V_55 = 0 ;
V_93 -> V_52 = 0 ;
}
F_14 (b, &bus->children, node)
F_75 ( V_130 ) ;
}
static inline void F_80 ( struct V_35 * V_6 , int V_134 )
{
struct V_40 * V_131 , * V_135 = & V_6 -> V_40 [ V_134 ] ;
F_34 ( L_37 ,
F_59 ( V_6 ) , V_134 ,
( unsigned long long ) V_135 -> V_53 ,
( unsigned long long ) V_135 -> V_55 ,
( unsigned int ) V_135 -> V_52 ) ;
V_131 = F_76 ( V_6 , V_135 ) ;
if ( ! V_131 || ( V_131 -> V_52 & V_110 ) ||
F_77 ( V_131 , V_135 ) < 0 ) {
F_78 ( L_38 , V_134 ) ;
F_79 ( L_39 , F_59 ( V_6 ) ) ;
if ( V_131 )
F_34 ( L_40 ,
V_131 ,
( unsigned long long ) V_131 -> V_53 ,
( unsigned long long ) V_131 -> V_55 ,
( unsigned int ) V_131 -> V_52 ) ;
V_135 -> V_52 |= V_110 ;
V_135 -> V_55 -= V_135 -> V_53 ;
V_135 -> V_53 = 0 ;
}
}
static void T_9 F_81 ( int V_136 )
{
struct V_35 * V_6 = NULL ;
int V_134 , V_137 ;
V_77 V_112 ;
struct V_40 * V_135 ;
F_31 (dev) {
F_61 ( V_6 , V_113 , & V_112 ) ;
for ( V_134 = 0 ; V_134 <= V_50 ; V_134 ++ ) {
V_135 = & V_6 -> V_40 [ V_134 ] ;
if ( V_135 -> V_30 )
continue;
if ( ! V_135 -> V_52 || ( V_135 -> V_52 & V_110 ) )
continue;
if ( V_134 == V_50 )
V_137 = 1 ;
if ( V_135 -> V_52 & V_49 )
V_137 = ! ( V_112 & V_115 ) ;
else
V_137 = ! ( V_112 & V_114 ) ;
if ( V_136 == V_137 )
F_80 ( V_6 , V_134 ) ;
}
if ( V_136 )
continue;
V_135 = & V_6 -> V_40 [ V_50 ] ;
if ( V_135 -> V_52 ) {
T_7 V_138 ;
F_82 ( V_6 , V_6 -> V_139 , & V_138 ) ;
if ( V_138 & V_140 ) {
F_34 ( L_41 ,
F_59 ( V_6 ) ) ;
V_135 -> V_52 &= ~ V_141 ;
F_83 ( V_6 , V_6 -> V_139 ,
V_138 & ~ V_140 ) ;
}
}
}
}
static void T_9 F_84 ( struct V_26 * V_27 )
{
struct V_4 * V_17 = F_17 ( V_27 ) ;
T_1 V_41 ;
struct V_40 * V_93 , * V_142 ;
int V_45 ;
F_34 ( L_42 ,
F_16 ( V_27 ) ) ;
if ( ! ( V_17 -> V_18 . V_52 & V_49 ) )
goto V_143;
V_41 = ( unsigned long ) V_17 -> V_22 - V_25 ;
V_93 = F_85 ( sizeof( struct V_40 ) , V_8 ) ;
F_86 ( V_93 == NULL ) ;
V_93 -> V_129 = L_43 ;
V_93 -> V_52 = V_49 ;
V_93 -> V_53 = V_41 ;
V_93 -> V_55 = ( V_41 + 0xfff ) & 0xfffffffful ;
F_34 ( L_44 , V_93 ) ;
if ( F_77 ( & V_17 -> V_18 , V_93 ) ) {
F_34 ( L_45 ,
F_16 ( V_27 ) , V_27 -> V_78 , V_93 ) ;
F_10 ( V_93 ) ;
}
V_143:
V_41 = V_17 -> V_106 ;
F_34 ( L_46 , ( unsigned long long ) V_41 ) ;
for ( V_45 = 0 ; V_45 < 3 ; V_45 ++ ) {
V_142 = & V_17 -> V_107 [ V_45 ] ;
if ( ! ( V_142 -> V_52 & V_48 ) )
continue;
F_34 ( L_47 , V_142 ) ;
if ( ( V_142 -> V_53 - V_41 ) <= 0xa0000 &&
( V_142 -> V_55 - V_41 ) >= 0xbffff )
break;
}
if ( V_45 >= 3 )
return;
V_93 = F_85 ( sizeof( struct V_40 ) , V_8 ) ;
F_86 ( V_93 == NULL ) ;
V_93 -> V_129 = L_48 ;
V_93 -> V_52 = V_48 ;
V_93 -> V_53 = 0xa0000 + V_41 ;
V_93 -> V_55 = 0xbffff + V_41 ;
F_34 ( L_49 , V_93 ) ;
if ( F_77 ( V_142 , V_93 ) ) {
F_34 ( L_50 ,
F_16 ( V_27 ) , V_27 -> V_78 , V_93 ) ;
F_10 ( V_93 ) ;
}
}
void T_9 F_87 ( void )
{
struct V_26 * V_130 ;
F_14 (b, &pci_root_buses, node)
F_75 ( V_130 ) ;
F_81 ( 0 ) ;
F_81 ( 1 ) ;
F_14 (b, &pci_root_buses, node)
F_84 ( V_130 ) ;
F_34 ( L_51 ) ;
F_88 () ;
}
void F_89 ( struct V_26 * V_27 )
{
struct V_35 * V_6 ;
struct V_26 * V_144 ;
F_14 (dev, &bus->devices, bus_list) {
int V_45 ;
for ( V_45 = 0 ; V_45 < V_145 ; V_45 ++ ) {
struct V_40 * V_135 = & V_6 -> V_40 [ V_45 ] ;
if ( V_135 -> V_30 || ! V_135 -> V_53 || ! V_135 -> V_52 )
continue;
F_34 ( L_52 , F_59 ( V_6 ) ) ;
F_34 ( L_53 ,
V_45 , ( unsigned long long ) V_135 -> V_53 ,
( unsigned long long ) V_135 -> V_55 ,
( unsigned int ) V_135 -> V_52 ) ;
F_90 ( V_6 , V_45 ) ;
}
}
F_14 (child_bus, &bus->children, node)
F_89 ( V_144 ) ;
}
void F_91 ( struct V_26 * V_27 )
{
F_34 ( L_54 ,
F_16 ( V_27 ) , V_27 -> V_78 ) ;
F_75 ( V_27 ) ;
F_89 ( V_27 ) ;
F_92 ( V_27 ) ;
}
int F_93 ( struct V_35 * V_6 , int V_146 )
{
return F_94 ( V_6 , V_146 ) ;
}
static void F_95 ( struct V_4 * V_17 ,
struct V_147 * V_148 )
{
unsigned long V_44 ;
struct V_40 * V_93 ;
int V_45 ;
V_93 = & V_17 -> V_18 ;
V_44 = ( unsigned long ) V_17 -> V_22 - V_104 ;
V_93 -> V_53 = ( V_93 -> V_53 + V_44 ) & 0xffffffffu ;
V_93 -> V_55 = ( V_93 -> V_55 + V_44 ) & 0xffffffffu ;
if ( ! V_93 -> V_52 ) {
F_78 ( L_55 ) ;
F_79 ( L_56 ,
V_17 -> V_14 -> V_38 , V_17 -> V_10 ) ;
V_93 -> V_53 = ( unsigned long ) V_17 -> V_22 - V_104 ;
V_93 -> V_55 = V_93 -> V_53 + V_149 ;
V_93 -> V_52 = V_49 ;
}
F_96 ( V_148 , V_93 ,
( V_150 T_1 ) ( V_17 -> V_22 - V_25 ) ) ;
F_34 ( L_57 ,
( unsigned long long ) V_93 -> V_53 ,
( unsigned long long ) V_93 -> V_55 ,
( unsigned long ) V_93 -> V_52 ) ;
for ( V_45 = 0 ; V_45 < 3 ; ++ V_45 ) {
V_93 = & V_17 -> V_107 [ V_45 ] ;
if ( ! V_93 -> V_52 ) {
if ( V_45 > 0 )
continue;
F_58 ( L_58 ) ;
F_79 ( L_59 ,
V_17 -> V_14 -> V_38 , V_17 -> V_10 ) ;
V_93 -> V_53 = V_17 -> V_106 ;
V_93 -> V_55 = ( T_1 ) - 1LL ;
V_93 -> V_52 = V_48 ;
}
F_96 ( V_148 , V_93 , V_17 -> V_106 ) ;
F_34 ( L_60 ,
V_45 , ( unsigned long long ) V_93 -> V_53 ,
( unsigned long long ) V_93 -> V_55 ,
( unsigned long ) V_93 -> V_52 ) ;
}
F_34 ( L_61 ,
( unsigned long long ) V_17 -> V_106 ) ;
F_34 ( L_62 ,
( unsigned long ) V_17 -> V_22 - V_25 ) ;
}
struct V_5 * F_97 ( struct V_26 * V_27 )
{
struct V_4 * V_17 = V_27 -> V_151 ;
return F_98 ( V_17 -> V_14 ) ;
}
static void F_99 ( struct V_4 * V_17 )
{
F_100 ( V_148 ) ;
struct V_26 * V_27 ;
struct V_5 * V_28 = V_17 -> V_14 ;
F_34 ( L_63 , F_101 ( V_28 ) ) ;
F_95 ( V_17 , & V_148 ) ;
V_27 = F_102 ( V_17 -> V_30 , V_17 -> V_152 ,
V_17 -> V_153 , V_17 , & V_148 ) ;
if ( V_27 == NULL ) {
F_58 ( L_64 ,
V_17 -> V_10 ) ;
F_103 ( & V_148 ) ;
return;
}
V_27 -> V_154 . V_53 = V_17 -> V_152 ;
V_17 -> V_27 = V_27 ;
V_17 -> V_155 = V_27 -> V_154 . V_55 ;
}
static int T_9 F_104 ( void )
{
struct V_4 * V_17 , * V_29 ;
int V_156 = 0 ;
F_51 ( L_65 ) ;
F_19 (hose, tmp, &hose_list, list_node) {
V_17 -> V_155 = 0xff ;
F_99 ( V_17 ) ;
if ( V_156 <= V_17 -> V_155 )
V_156 = V_17 -> V_155 + 1 ;
}
V_157 = V_156 ;
F_87 () ;
return 0 ;
}
static struct V_4 * F_105 ( int V_27 )
{
struct V_4 * V_17 , * V_29 ;
F_19 (hose, tmp, &hose_list, list_node)
if ( V_27 >= V_17 -> V_152 && V_27 <= V_17 -> V_155 )
return V_17 ;
return NULL ;
}
long F_106 ( long V_158 , unsigned long V_27 , unsigned long V_159 )
{
struct V_4 * V_17 ;
long V_160 = - V_161 ;
V_17 = F_105 ( V_27 ) ;
if ( ! V_17 )
return - V_162 ;
switch ( V_158 ) {
case V_163 :
return ( long ) V_17 -> V_152 ;
case V_164 :
return ( long ) V_17 -> V_106 ;
case V_165 :
return ( long ) V_17 -> V_23 ;
case V_166 :
return ( long ) V_104 ;
case V_167 :
return ( long ) V_105 ;
}
return V_160 ;
}
static int
F_107 ( struct V_26 * V_27 , unsigned int V_159 , int V_41 ,
int V_168 , T_7 * V_73 )
{
return V_169 ;
}
static int
F_108 ( struct V_26 * V_27 , unsigned int V_159 , int V_41 ,
int V_168 , T_7 V_73 )
{
return V_169 ;
}
static struct V_26 *
F_109 ( struct V_4 * V_17 , int V_170 )
{
static struct V_26 V_27 ;
if ( ! V_17 )
F_58 ( L_66 , V_170 ) ;
V_27 . V_78 = V_170 ;
V_27 . V_151 = V_17 ;
V_27 . V_153 = V_17 ? V_17 -> V_153 : & V_171 ;
return & V_27 ;
}
int F_110 ( struct V_4 * V_17 , int V_27 , int V_159 ,
int V_172 )
{
return F_111 ( F_109 ( V_17 , V_27 ) , V_159 , V_172 ) ;
}
