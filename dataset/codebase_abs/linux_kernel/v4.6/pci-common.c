struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
F_3 ( & V_6 ) ;
V_4 -> V_7 = V_8 ++ ;
F_4 ( & V_4 -> V_9 , & V_10 ) ;
F_5 ( & V_6 ) ;
V_4 -> V_11 = V_3 ;
V_4 -> V_12 = V_13 ;
return V_4 ;
}
void F_6 ( struct V_1 * V_4 )
{
F_3 ( & V_6 ) ;
F_7 ( & V_4 -> V_9 ) ;
F_5 ( & V_6 ) ;
if ( V_4 -> V_12 )
F_8 ( V_4 ) ;
}
static T_1 F_9 ( const struct V_1 * V_14 )
{
return F_10 ( & V_14 -> V_15 ) ;
}
int F_11 ( void T_2 * V_16 )
{
int V_17 = 0 ;
struct V_1 * V_14 ;
T_1 V_18 ;
F_3 ( & V_6 ) ;
F_12 (hose, &hose_list, list_node) {
V_18 = F_9 ( V_14 ) ;
if ( V_16 >= V_14 -> V_19 &&
V_16 < ( V_14 -> V_19 + V_18 ) ) {
V_17 = 1 ;
break;
}
}
F_5 ( & V_6 ) ;
return V_17 ;
}
unsigned long F_13 ( T_3 V_16 )
{
struct V_1 * V_14 ;
T_1 V_18 ;
unsigned long V_17 = ~ 0 ;
F_3 ( & V_6 ) ;
F_12 (hose, &hose_list, list_node) {
V_18 = F_9 ( V_14 ) ;
if ( V_16 >= V_14 -> V_20 &&
V_16 < ( V_14 -> V_20 + V_18 ) ) {
unsigned long V_21 =
( unsigned long ) V_14 -> V_19 - V_22 ;
V_17 = V_21 + ( V_16 - V_14 -> V_20 ) ;
break;
}
}
F_5 ( & V_6 ) ;
return V_17 ;
}
struct V_1 * F_14 ( struct V_2 * V_23 )
{
while ( V_23 ) {
struct V_1 * V_14 , * V_24 ;
F_15 (hose, tmp, &hose_list, list_node)
if ( V_14 -> V_11 == V_23 )
return V_14 ;
V_23 = V_23 -> V_25 ;
}
return NULL ;
}
void F_16 ( struct V_26 * V_3 )
{
}
static struct V_27 * F_17 ( struct V_26 * V_3 ,
T_1 * V_28 ,
enum V_29 V_30 )
{
struct V_1 * V_14 = F_18 ( V_3 -> V_31 ) ;
unsigned long V_32 = 0 ;
int V_33 , V_34 ;
if ( ! V_14 )
return NULL ;
if ( V_30 == V_35 ) {
#if 0
*offset += hose->pci_mem_offset;
#endif
V_34 = V_36 ;
} else {
V_32 = ( unsigned long ) V_14 -> V_19 - V_22 ;
* V_28 += V_32 ;
V_34 = V_37 ;
}
for ( V_33 = 0 ; V_33 <= V_38 ; V_33 ++ ) {
struct V_27 * V_39 = & V_3 -> V_27 [ V_33 ] ;
int V_40 = V_39 -> V_40 ;
if ( V_33 == V_38 )
V_40 |= V_36 ;
if ( ( V_40 & V_34 ) == 0 )
continue;
if ( * V_28 < ( V_39 -> V_41 & V_42 ) || * V_28 > V_39 -> V_43 )
continue;
if ( V_30 == V_44 )
* V_28 += V_14 -> V_20 - V_32 ;
return V_39 ;
}
return NULL ;
}
static T_4 F_19 ( struct V_26 * V_3 , struct V_27 * V_39 ,
T_4 V_45 ,
enum V_29 V_30 ,
int V_46 )
{
T_4 V_47 = V_45 ;
if ( V_30 != V_35 )
V_46 = 0 ;
else if ( V_46 == 0 ) {
if ( V_39 -> V_40 & V_48 )
V_46 = 1 ;
}
return F_20 ( V_47 ) ;
}
T_4 F_21 ( struct V_49 * V_49 ,
unsigned long V_50 ,
unsigned long V_18 ,
T_4 V_47 )
{
struct V_26 * V_51 = NULL ;
struct V_27 * V_52 = NULL ;
T_1 V_28 = ( ( T_1 ) V_50 ) << V_53 ;
int V_33 ;
if ( F_22 ( V_50 ) )
return V_47 ;
V_47 = F_20 ( V_47 ) ;
F_23 (pdev) {
for ( V_33 = 0 ; V_33 <= V_38 ; V_33 ++ ) {
struct V_27 * V_39 = & V_51 -> V_27 [ V_33 ] ;
int V_40 = V_39 -> V_40 ;
if ( ( V_40 & V_36 ) == 0 )
continue;
if ( V_28 < ( V_39 -> V_41 & V_42 ) ||
V_28 > V_39 -> V_43 )
continue;
V_52 = V_39 ;
break;
}
if ( V_52 )
break;
}
if ( V_52 ) {
if ( V_52 -> V_40 & V_48 )
V_47 = F_24 ( V_47 ) ;
F_25 ( V_51 ) ;
}
F_26 ( L_1 ,
( unsigned long long ) V_28 , F_27 ( V_47 ) ) ;
return V_47 ;
}
int F_28 ( struct V_26 * V_3 , struct V_54 * V_55 ,
enum V_29 V_30 , int V_46 )
{
T_1 V_28 =
( ( T_1 ) V_55 -> V_56 ) << V_53 ;
struct V_27 * V_39 ;
int V_17 ;
V_39 = F_17 ( V_3 , & V_28 , V_30 ) ;
if ( V_39 == NULL )
return - V_57 ;
V_55 -> V_56 = V_28 >> V_53 ;
V_55 -> V_58 = F_19 ( V_3 , V_39 ,
V_55 -> V_58 ,
V_30 , V_46 ) ;
V_17 = F_29 ( V_55 , V_55 -> V_59 , V_55 -> V_56 ,
V_55 -> V_60 - V_55 -> V_59 , V_55 -> V_58 ) ;
return V_17 ;
}
int F_30 ( struct V_61 * V_31 , T_5 V_62 , T_6 * V_63 , T_7 V_18 )
{
unsigned long V_28 ;
struct V_1 * V_14 = F_18 ( V_31 ) ;
struct V_27 * V_39 = & V_14 -> V_15 ;
void T_2 * V_64 ;
V_28 = ( unsigned long ) V_14 -> V_19 - V_22 ;
V_28 += V_62 ;
if ( ! ( V_39 -> V_40 & V_37 ) )
return - V_65 ;
if ( V_28 < V_39 -> V_41 || ( V_28 + V_18 ) > V_39 -> V_43 )
return - V_65 ;
V_64 = V_14 -> V_19 + V_62 ;
switch ( V_18 ) {
case 1 :
* ( ( V_66 * ) V_63 ) = F_31 ( V_64 ) ;
return 1 ;
case 2 :
if ( V_62 & 1 )
return - V_57 ;
* ( ( V_67 * ) V_63 ) = F_32 ( V_64 ) ;
return 2 ;
case 4 :
if ( V_62 & 3 )
return - V_57 ;
* ( ( T_6 * ) V_63 ) = F_33 ( V_64 ) ;
return 4 ;
}
return - V_57 ;
}
int F_34 ( struct V_61 * V_31 , T_5 V_62 , T_6 V_63 , T_7 V_18 )
{
unsigned long V_28 ;
struct V_1 * V_14 = F_18 ( V_31 ) ;
struct V_27 * V_39 = & V_14 -> V_15 ;
void T_2 * V_64 ;
V_28 = ( unsigned long ) V_14 -> V_19 - V_22 ;
V_28 += V_62 ;
if ( ! ( V_39 -> V_40 & V_37 ) )
return - V_65 ;
if ( V_28 < V_39 -> V_41 || ( V_28 + V_18 ) > V_39 -> V_43 )
return - V_65 ;
V_64 = V_14 -> V_19 + V_62 ;
switch ( V_18 ) {
case 1 :
F_35 ( V_64 , V_63 >> 24 ) ;
return 1 ;
case 2 :
if ( V_62 & 1 )
return - V_57 ;
F_36 ( V_64 , V_63 >> 16 ) ;
return 2 ;
case 4 :
if ( V_62 & 3 )
return - V_57 ;
F_37 ( V_64 , V_63 ) ;
return 4 ;
}
return - V_57 ;
}
int F_38 ( struct V_61 * V_31 ,
struct V_54 * V_55 ,
enum V_29 V_30 )
{
struct V_1 * V_14 = F_18 ( V_31 ) ;
T_1 V_28 =
( ( T_1 ) V_55 -> V_56 ) << V_53 ;
T_1 V_18 = V_55 -> V_60 - V_55 -> V_59 ;
struct V_27 * V_39 ;
F_26 ( L_2 ,
F_39 ( V_31 ) , V_31 -> V_68 ,
V_30 == V_35 ? L_3 : L_4 ,
( unsigned long long ) V_28 ,
( unsigned long long ) ( V_28 + V_18 - 1 ) ) ;
if ( V_30 == V_35 ) {
if ( ( V_28 + V_18 ) > V_14 -> V_69 ) {
#ifdef F_40
F_26 ( L_5 ,
V_70 -> V_71 , V_70 -> V_72 ) ;
F_26 ( L_6 ,
F_39 ( V_31 ) , V_31 -> V_68 ) ;
#endif
if ( V_55 -> V_73 & V_74 )
return F_41 ( V_55 ) ;
return 0 ;
}
V_28 += V_14 -> V_75 ;
} else {
unsigned long V_32 = ( unsigned long ) V_14 -> V_19 -
V_22 ;
unsigned long V_76 = V_28 + V_32 ;
V_39 = & V_14 -> V_15 ;
if ( ! ( V_39 -> V_40 & V_37 ) )
return - V_65 ;
if ( V_76 < V_39 -> V_41 || ( V_76 + V_18 ) > V_39 -> V_43 )
return - V_65 ;
V_28 += V_14 -> V_20 ;
}
F_26 ( L_7 , ( unsigned long long ) V_28 ) ;
V_55 -> V_56 = V_28 >> V_53 ;
V_55 -> V_58 = F_20 ( V_55 -> V_58 ) ;
return F_29 ( V_55 , V_55 -> V_59 , V_55 -> V_56 ,
V_55 -> V_60 - V_55 -> V_59 ,
V_55 -> V_58 ) ;
}
void F_42 ( const struct V_26 * V_3 , int V_77 ,
const struct V_27 * V_78 ,
T_1 * V_41 , T_1 * V_43 )
{
struct V_1 * V_14 = F_18 ( V_3 -> V_31 ) ;
T_1 V_28 = 0 ;
if ( V_14 == NULL )
return;
if ( V_78 -> V_40 & V_37 )
V_28 = ( unsigned long ) V_14 -> V_19 - V_22 ;
#if 0
else if (rsrc->flags & IORESOURCE_MEM)
offset = hose->pci_mem_offset;
#endif
* V_41 = V_78 -> V_41 - V_28 ;
* V_43 = V_78 -> V_43 - V_28 ;
}
void F_43 ( struct V_1 * V_14 ,
struct V_2 * V_3 , int V_79 )
{
int V_80 = 0 , V_81 = - 1 ;
unsigned long long V_82 = 0 ;
struct V_27 * V_83 ;
struct V_84 V_85 ;
struct V_86 V_87 ;
F_44 ( L_8 ,
V_3 -> V_88 , V_79 ? L_9 : L_10 ) ;
if ( F_45 ( & V_87 , V_3 ) )
return;
F_26 ( L_11 ) ;
F_46 (&parser, &range) {
F_26 ( L_12 ,
V_85 . V_89 , V_85 . V_90 ) ;
F_26 ( L_13 ,
V_85 . V_91 , V_85 . V_18 ) ;
if ( V_85 . V_91 == V_92 || V_85 . V_18 == 0 )
continue;
V_83 = NULL ;
switch ( V_85 . V_40 & V_93 ) {
case V_37 :
F_44 ( L_14 ,
V_85 . V_91 , V_85 . V_91 + V_85 . V_18 - 1 ,
V_85 . V_90 ) ;
if ( V_14 -> V_94 ) {
F_44 ( L_15 ) ;
continue;
}
if ( V_85 . V_18 > 0x01000000 )
V_85 . V_18 = 0x01000000 ;
V_14 -> V_19 = F_47 ( V_85 . V_91 ,
V_85 . V_18 ) ;
if ( V_79 )
V_95 =
( unsigned long ) V_14 -> V_19 ;
V_14 -> V_94 = V_85 . V_90 + V_85 . V_18 ;
V_14 -> V_20 = V_85 . V_91 - V_85 . V_90 ;
V_83 = & V_14 -> V_15 ;
V_85 . V_91 = V_85 . V_90 ;
break;
case V_36 :
F_44 ( L_16 ,
V_85 . V_91 , V_85 . V_91 + V_85 . V_18 - 1 ,
V_85 . V_90 ,
( V_85 . V_89 & 0x40000000 ) ?
L_17 : L_10 ) ;
if ( V_80 >= 3 ) {
F_44 ( L_15 ) ;
continue;
}
if ( V_85 . V_90 == 0 ) {
V_82 = V_85 . V_91 ;
V_81 = V_80 ;
if ( V_79 || V_96 == 0 )
V_96 = V_85 . V_91 ;
V_14 -> V_75 = V_85 . V_91 ;
V_14 -> V_69 = V_85 . V_18 ;
}
if ( V_80 == 0 ||
( V_81 >= 0 && V_85 . V_90 != 0 &&
V_14 -> V_97 == V_82 ) )
V_14 -> V_97 = V_85 . V_91 -
V_85 . V_90 ;
else if ( V_85 . V_90 != 0 &&
V_14 -> V_97 != V_85 . V_91 -
V_85 . V_90 ) {
F_44 ( L_18 ) ;
continue;
}
V_83 = & V_14 -> V_98 [ V_80 ++ ] ;
break;
}
if ( V_83 != NULL ) {
V_83 -> V_99 = V_3 -> V_88 ;
V_83 -> V_40 = V_85 . V_40 ;
V_83 -> V_41 = V_85 . V_91 ;
V_83 -> V_43 = V_85 . V_91 + V_85 . V_18 - 1 ;
V_83 -> V_25 = V_83 -> V_100 = V_83 -> V_101 = NULL ;
}
}
if ( V_81 >= 0 && V_14 -> V_97 != V_82 ) {
unsigned int V_102 = V_81 + 1 ;
F_44 ( L_19 , V_82 ) ;
if ( V_102 < V_80 )
memmove ( & V_14 -> V_98 [ V_81 ] ,
& V_14 -> V_98 [ V_102 ] ,
sizeof( struct V_27 ) * ( V_80 - V_102 ) ) ;
V_14 -> V_98 [ -- V_80 ] . V_40 = 0 ;
}
}
int F_48 ( struct V_61 * V_31 )
{
return 0 ;
}
static void F_49 ( struct V_26 * V_3 )
{
struct V_1 * V_14 = F_18 ( V_3 -> V_31 ) ;
int V_33 ;
if ( ! V_14 ) {
F_50 ( L_20 ,
F_51 ( V_3 ) ) ;
return;
}
for ( V_33 = 0 ; V_33 < V_103 ; V_33 ++ ) {
struct V_27 * V_83 = V_3 -> V_27 + V_33 ;
if ( ! V_83 -> V_40 )
continue;
if ( V_83 -> V_41 == 0 ) {
F_26 ( L_21 ,
F_51 ( V_3 ) , V_33 ,
( unsigned long long ) V_83 -> V_41 ,
( unsigned long long ) V_83 -> V_43 ,
( unsigned int ) V_83 -> V_40 ) ;
F_26 ( L_22 ) ;
V_83 -> V_43 -= V_83 -> V_41 ;
V_83 -> V_41 = 0 ;
V_83 -> V_40 |= V_104 ;
continue;
}
F_26 ( L_23 ,
F_51 ( V_3 ) , V_33 ,
( unsigned long long ) V_83 -> V_41 ,
( unsigned long long ) V_83 -> V_43 ,
( unsigned int ) V_83 -> V_40 ) ;
}
}
static int F_52 ( struct V_61 * V_31 ,
struct V_27 * V_83 )
{
struct V_1 * V_14 = F_18 ( V_31 ) ;
struct V_26 * V_3 = V_31 -> V_105 ;
T_1 V_28 ;
V_67 V_106 ;
int V_33 ;
if ( V_83 -> V_40 & V_36 ) {
if ( V_83 -> V_41 != V_14 -> V_97 )
return 0 ;
F_53 ( V_3 , V_107 , & V_106 ) ;
if ( ( V_106 & V_108 ) == 0 )
return 1 ;
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
if ( ( V_14 -> V_98 [ V_33 ] . V_40 & V_36 ) &&
V_14 -> V_98 [ V_33 ] . V_41 == V_14 -> V_97 )
return 0 ;
}
return 1 ;
} else {
V_28 = ( unsigned long ) V_14 -> V_19 - V_22 ;
if ( ( ( V_83 -> V_41 - V_28 ) & 0xfffffffful ) != 0 )
return 0 ;
F_53 ( V_3 , V_107 , & V_106 ) ;
if ( V_106 & V_109 )
return 0 ;
return 1 ;
}
}
static void F_54 ( struct V_61 * V_31 )
{
struct V_27 * V_83 ;
int V_33 ;
struct V_26 * V_3 = V_31 -> V_105 ;
F_55 (bus, res, i) {
if ( ! V_83 )
continue;
if ( ! V_83 -> V_40 )
continue;
if ( V_33 >= 3 && V_31 -> V_105 -> V_110 )
continue;
F_26 ( L_24 ,
F_51 ( V_3 ) , V_33 ,
( unsigned long long ) V_83 -> V_41 ,
( unsigned long long ) V_83 -> V_43 ,
( unsigned int ) V_83 -> V_40 ) ;
if ( F_52 ( V_31 , V_83 ) ) {
V_83 -> V_40 = 0 ;
F_26 ( L_25 ,
F_51 ( V_3 ) ) ;
} else {
F_26 ( L_26 ,
F_51 ( V_3 ) ,
( unsigned long long ) V_83 -> V_41 ,
( unsigned long long ) V_83 -> V_43 ) ;
}
}
}
void F_56 ( struct V_61 * V_31 )
{
if ( V_31 -> V_105 != NULL )
F_54 ( V_31 ) ;
}
void F_57 ( struct V_61 * V_31 )
{
struct V_26 * V_3 ;
F_26 ( L_27 ,
V_31 -> V_68 , V_31 -> V_105 ? F_51 ( V_31 -> V_105 ) : L_28 ) ;
F_12 (dev, &bus->devices, bus_list) {
V_3 -> V_3 . V_111 = F_58 ( V_3 ) ;
F_59 ( & V_3 -> V_3 , F_60 ( V_3 -> V_31 ) ) ;
V_3 -> V_112 = F_61 ( V_3 , 0 , 0 ) ;
}
}
void F_62 ( struct V_61 * V_31 )
{
}
T_1 F_63 ( void * V_113 , const struct V_27 * V_83 ,
T_1 V_18 , T_1 V_114 )
{
return V_83 -> V_41 ;
}
int F_64 ( struct V_26 * V_3 )
{
V_3 -> V_112 = F_61 ( V_3 , 0 , 0 ) ;
return 0 ;
}
static int T_8 F_65 ( struct V_27 * V_25 ,
struct V_27 * V_83 )
{
struct V_27 * V_115 , * * V_116 ;
struct V_27 * * V_117 = NULL ;
for ( V_116 = & V_25 -> V_100 ; ( V_115 = * V_116 ) != NULL ; V_116 = & V_115 -> V_101 ) {
if ( V_115 -> V_43 < V_83 -> V_41 )
continue;
if ( V_83 -> V_43 < V_115 -> V_41 )
break;
if ( V_115 -> V_41 < V_83 -> V_41 || V_115 -> V_43 > V_83 -> V_43 )
return - 1 ;
if ( V_117 == NULL )
V_117 = V_116 ;
}
if ( V_117 == NULL )
return - 1 ;
V_83 -> V_25 = V_25 ;
V_83 -> V_100 = * V_117 ;
V_83 -> V_101 = * V_116 ;
* V_117 = V_83 ;
* V_116 = NULL ;
for ( V_115 = V_83 -> V_100 ; V_115 != NULL ; V_115 = V_115 -> V_101 ) {
V_115 -> V_25 = V_83 ;
F_26 ( L_29 ,
V_115 -> V_99 ,
( unsigned long long ) V_115 -> V_41 ,
( unsigned long long ) V_115 -> V_43 , V_83 -> V_99 ) ;
}
return 0 ;
}
static void F_66 ( struct V_61 * V_31 )
{
struct V_61 * V_118 ;
int V_33 ;
struct V_27 * V_83 , * V_119 ;
F_26 ( L_30 ,
F_39 ( V_31 ) , V_31 -> V_68 ) ;
F_55 (bus, res, i) {
if ( ! V_83 || ! V_83 -> V_40
|| V_83 -> V_41 > V_83 -> V_43 || V_83 -> V_25 )
continue;
if ( V_31 -> V_25 == NULL )
V_119 = ( V_83 -> V_40 & V_37 ) ?
& V_120 : & V_121 ;
else {
V_119 = F_67 ( V_31 -> V_105 , V_83 ) ;
if ( V_119 == V_83 ) {
continue;
}
}
F_26 ( L_31 ,
V_31 -> V_105 ? F_51 ( V_31 -> V_105 ) : L_28 ,
V_31 -> V_68 , V_33 ,
( unsigned long long ) V_83 -> V_41 ,
( unsigned long long ) V_83 -> V_43 ) ;
F_26 ( L_32 ,
( unsigned int ) V_83 -> V_40 ,
V_119 , ( V_119 && V_119 -> V_99 ) ? V_119 -> V_99 : L_33 ) ;
if ( V_119 && ! ( V_119 -> V_40 & V_104 ) ) {
struct V_26 * V_3 = V_31 -> V_105 ;
if ( F_68 ( V_119 , V_83 ) == 0 )
continue;
if ( F_65 ( V_119 , V_83 ) == 0 )
continue;
if ( V_3 && V_33 < V_122 &&
F_69 ( V_3 ,
V_33 + V_123 ) == 0 )
continue;
}
F_70 ( L_34 ) ;
F_71 ( L_35 , V_33 , V_31 -> V_68 ) ;
V_83 -> V_41 = V_83 -> V_43 = 0 ;
V_83 -> V_40 = 0 ;
}
F_12 (b, &bus->children, node)
F_66 ( V_118 ) ;
}
static inline void F_72 ( struct V_26 * V_3 , int V_124 )
{
struct V_27 * V_119 , * V_125 = & V_3 -> V_27 [ V_124 ] ;
F_26 ( L_36 ,
F_51 ( V_3 ) , V_124 ,
( unsigned long long ) V_125 -> V_41 ,
( unsigned long long ) V_125 -> V_43 ,
( unsigned int ) V_125 -> V_40 ) ;
V_119 = F_67 ( V_3 , V_125 ) ;
if ( ! V_119 || ( V_119 -> V_40 & V_104 ) ||
F_68 ( V_119 , V_125 ) < 0 ) {
F_70 ( L_37 , V_124 ) ;
F_71 ( L_38 , F_51 ( V_3 ) ) ;
if ( V_119 )
F_26 ( L_39 ,
V_119 ,
( unsigned long long ) V_119 -> V_41 ,
( unsigned long long ) V_119 -> V_43 ,
( unsigned int ) V_119 -> V_40 ) ;
V_125 -> V_40 |= V_104 ;
V_125 -> V_43 -= V_125 -> V_41 ;
V_125 -> V_41 = 0 ;
}
}
static void T_8 F_73 ( int V_126 )
{
struct V_26 * V_3 = NULL ;
int V_124 , V_127 ;
V_67 V_106 ;
struct V_27 * V_125 ;
F_23 (dev) {
F_53 ( V_3 , V_107 , & V_106 ) ;
for ( V_124 = 0 ; V_124 <= V_38 ; V_124 ++ ) {
V_125 = & V_3 -> V_27 [ V_124 ] ;
if ( V_125 -> V_25 )
continue;
if ( ! V_125 -> V_40 || ( V_125 -> V_40 & V_104 ) )
continue;
if ( V_124 == V_38 )
V_127 = 1 ;
if ( V_125 -> V_40 & V_37 )
V_127 = ! ( V_106 & V_109 ) ;
else
V_127 = ! ( V_106 & V_108 ) ;
if ( V_126 == V_127 )
F_72 ( V_3 , V_124 ) ;
}
if ( V_126 )
continue;
V_125 = & V_3 -> V_27 [ V_38 ] ;
if ( V_125 -> V_40 ) {
T_6 V_128 ;
F_74 ( V_3 , V_3 -> V_129 , & V_128 ) ;
if ( V_128 & V_130 ) {
F_26 ( L_40 ,
F_51 ( V_3 ) ) ;
V_125 -> V_40 &= ~ V_131 ;
F_75 ( V_3 , V_3 -> V_129 ,
V_128 & ~ V_130 ) ;
}
}
}
}
static void T_8 F_76 ( struct V_61 * V_31 )
{
struct V_1 * V_14 = F_18 ( V_31 ) ;
T_1 V_28 ;
struct V_27 * V_83 , * V_132 ;
int V_33 ;
F_26 ( L_41 ,
F_39 ( V_31 ) ) ;
if ( ! ( V_14 -> V_15 . V_40 & V_37 ) )
goto V_133;
V_28 = ( unsigned long ) V_14 -> V_19 - V_22 ;
V_83 = F_77 ( sizeof( struct V_27 ) , V_5 ) ;
F_78 ( V_83 == NULL ) ;
V_83 -> V_99 = L_42 ;
V_83 -> V_40 = V_37 ;
V_83 -> V_41 = V_28 ;
V_83 -> V_43 = ( V_28 + 0xfff ) & 0xfffffffful ;
F_26 ( L_43 , V_83 ) ;
if ( F_68 ( & V_14 -> V_15 , V_83 ) ) {
F_26 ( L_44 ,
F_39 ( V_31 ) , V_31 -> V_68 , V_83 ) ;
F_8 ( V_83 ) ;
}
V_133:
V_28 = V_14 -> V_97 ;
F_26 ( L_45 , ( unsigned long long ) V_28 ) ;
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
V_132 = & V_14 -> V_98 [ V_33 ] ;
if ( ! ( V_132 -> V_40 & V_36 ) )
continue;
F_26 ( L_46 , V_132 ) ;
if ( ( V_132 -> V_41 - V_28 ) <= 0xa0000 &&
( V_132 -> V_43 - V_28 ) >= 0xbffff )
break;
}
if ( V_33 >= 3 )
return;
V_83 = F_77 ( sizeof( struct V_27 ) , V_5 ) ;
F_78 ( V_83 == NULL ) ;
V_83 -> V_99 = L_47 ;
V_83 -> V_40 = V_36 ;
V_83 -> V_41 = 0xa0000 + V_28 ;
V_83 -> V_43 = 0xbffff + V_28 ;
F_26 ( L_48 , V_83 ) ;
if ( F_68 ( V_132 , V_83 ) ) {
F_26 ( L_49 ,
F_39 ( V_31 ) , V_31 -> V_68 , V_83 ) ;
F_8 ( V_83 ) ;
}
}
void T_8 F_79 ( void )
{
struct V_61 * V_118 ;
F_12 (b, &pci_root_buses, node)
F_66 ( V_118 ) ;
F_73 ( 0 ) ;
F_73 ( 1 ) ;
F_12 (b, &pci_root_buses, node)
F_76 ( V_118 ) ;
F_26 ( L_50 ) ;
F_80 () ;
}
void F_81 ( struct V_61 * V_31 )
{
struct V_26 * V_3 ;
struct V_61 * V_134 ;
F_12 (dev, &bus->devices, bus_list) {
int V_33 ;
for ( V_33 = 0 ; V_33 < V_135 ; V_33 ++ ) {
struct V_27 * V_125 = & V_3 -> V_27 [ V_33 ] ;
if ( V_125 -> V_25 || ! V_125 -> V_41 || ! V_125 -> V_40 )
continue;
F_26 ( L_51 , F_51 ( V_3 ) ) ;
F_26 ( L_52 ,
V_33 , ( unsigned long long ) V_125 -> V_41 ,
( unsigned long long ) V_125 -> V_43 ,
( unsigned int ) V_125 -> V_40 ) ;
if ( F_82 ( V_3 , V_33 ) == 0 )
continue;
F_69 ( V_3 , V_33 ) ;
}
}
F_12 (child_bus, &bus->children, node)
F_81 ( V_134 ) ;
}
void F_83 ( struct V_61 * V_31 )
{
F_26 ( L_53 ,
F_39 ( V_31 ) , V_31 -> V_68 ) ;
F_66 ( V_31 ) ;
F_81 ( V_31 ) ;
F_84 ( V_31 ) ;
}
static void F_85 ( struct V_1 * V_14 ,
struct V_136 * V_137 )
{
unsigned long V_32 ;
struct V_27 * V_83 ;
int V_33 ;
V_83 = & V_14 -> V_15 ;
V_32 = ( unsigned long ) V_14 -> V_19 - V_95 ;
V_83 -> V_41 = ( V_83 -> V_41 + V_32 ) & 0xffffffffu ;
V_83 -> V_43 = ( V_83 -> V_43 + V_32 ) & 0xffffffffu ;
if ( ! V_83 -> V_40 ) {
F_70 ( L_54 ) ;
F_71 ( L_55 ,
V_14 -> V_11 -> V_88 , V_14 -> V_7 ) ;
V_83 -> V_41 = ( unsigned long ) V_14 -> V_19 - V_95 ;
V_83 -> V_43 = V_83 -> V_41 + V_138 ;
V_83 -> V_40 = V_37 ;
}
F_86 ( V_137 , V_83 ,
( V_139 T_1 ) ( V_14 -> V_19 - V_22 ) ) ;
F_26 ( L_56 ,
( unsigned long long ) V_83 -> V_41 ,
( unsigned long long ) V_83 -> V_43 ,
( unsigned long ) V_83 -> V_40 ) ;
for ( V_33 = 0 ; V_33 < 3 ; ++ V_33 ) {
V_83 = & V_14 -> V_98 [ V_33 ] ;
if ( ! V_83 -> V_40 ) {
if ( V_33 > 0 )
continue;
F_50 ( L_57 ) ;
F_71 ( L_58 ,
V_14 -> V_11 -> V_88 , V_14 -> V_7 ) ;
V_83 -> V_41 = V_14 -> V_97 ;
V_83 -> V_43 = ( T_1 ) - 1LL ;
V_83 -> V_40 = V_36 ;
}
F_86 ( V_137 , V_83 , V_14 -> V_97 ) ;
F_26 ( L_59 ,
V_33 , ( unsigned long long ) V_83 -> V_41 ,
( unsigned long long ) V_83 -> V_43 ,
( unsigned long ) V_83 -> V_40 ) ;
}
F_26 ( L_60 ,
( unsigned long long ) V_14 -> V_97 ) ;
F_26 ( L_61 ,
( unsigned long ) V_14 -> V_19 - V_22 ) ;
}
static void F_87 ( struct V_1 * V_14 )
{
F_88 ( V_137 ) ;
struct V_61 * V_31 ;
struct V_2 * V_23 = V_14 -> V_11 ;
F_26 ( L_62 , F_89 ( V_23 ) ) ;
F_85 ( V_14 , & V_137 ) ;
V_31 = F_90 ( V_14 -> V_25 , V_14 -> V_140 ,
V_14 -> V_141 , V_14 , & V_137 ) ;
if ( V_31 == NULL ) {
F_50 ( L_63 ,
V_14 -> V_7 ) ;
F_91 ( & V_137 ) ;
return;
}
V_31 -> V_142 . V_41 = V_14 -> V_140 ;
V_14 -> V_31 = V_31 ;
V_14 -> V_143 = V_31 -> V_142 . V_43 ;
}
static int T_8 F_92 ( void )
{
struct V_1 * V_14 , * V_24 ;
int V_144 = 0 ;
F_44 ( L_64 ) ;
F_15 (hose, tmp, &hose_list, list_node) {
V_14 -> V_143 = 0xff ;
F_87 ( V_14 ) ;
if ( V_144 <= V_14 -> V_143 )
V_144 = V_14 -> V_143 + 1 ;
}
V_145 = V_144 ;
F_79 () ;
F_15 (hose, tmp, &hose_list, list_node) {
if ( V_14 -> V_31 )
F_84 ( V_14 -> V_31 ) ;
}
return 0 ;
}
static struct V_1 * F_93 ( int V_31 )
{
struct V_1 * V_14 , * V_24 ;
F_15 (hose, tmp, &hose_list, list_node)
if ( V_31 >= V_14 -> V_140 && V_31 <= V_14 -> V_143 )
return V_14 ;
return NULL ;
}
long F_94 ( long V_146 , unsigned long V_31 , unsigned long V_147 )
{
struct V_1 * V_14 ;
long V_148 = - V_149 ;
V_14 = F_93 ( V_31 ) ;
if ( ! V_14 )
return - V_150 ;
switch ( V_146 ) {
case V_151 :
return ( long ) V_14 -> V_140 ;
case V_152 :
return ( long ) V_14 -> V_97 ;
case V_153 :
return ( long ) V_14 -> V_20 ;
case V_154 :
return ( long ) V_95 ;
case V_155 :
return ( long ) V_96 ;
}
return V_148 ;
}
static int
F_95 ( struct V_61 * V_31 , unsigned int V_147 , int V_28 ,
int V_156 , T_6 * V_63 )
{
return V_157 ;
}
static int
F_96 ( struct V_61 * V_31 , unsigned int V_147 , int V_28 ,
int V_156 , T_6 V_63 )
{
return V_157 ;
}
static struct V_61 *
F_97 ( struct V_1 * V_14 , int V_158 )
{
static struct V_61 V_31 ;
if ( ! V_14 )
F_50 ( L_65 , V_158 ) ;
V_31 . V_68 = V_158 ;
V_31 . V_159 = V_14 ;
V_31 . V_141 = V_14 ? V_14 -> V_141 : & V_160 ;
return & V_31 ;
}
int F_98 ( struct V_1 * V_14 , int V_31 , int V_147 ,
int V_161 )
{
return F_99 ( F_97 ( V_14 , V_31 ) , V_147 , V_161 ) ;
}
