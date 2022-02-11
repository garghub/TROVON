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
T_4 F_19 ( struct V_45 * V_45 ,
unsigned long V_46 ,
unsigned long V_18 ,
T_4 V_47 )
{
struct V_26 * V_48 = NULL ;
struct V_27 * V_49 = NULL ;
T_1 V_28 = ( ( T_1 ) V_46 ) << V_50 ;
int V_33 ;
if ( F_20 ( V_46 ) )
return V_47 ;
V_47 = F_21 ( V_47 ) ;
F_22 (pdev) {
for ( V_33 = 0 ; V_33 <= V_38 ; V_33 ++ ) {
struct V_27 * V_39 = & V_48 -> V_27 [ V_33 ] ;
int V_40 = V_39 -> V_40 ;
if ( ( V_40 & V_36 ) == 0 )
continue;
if ( V_28 < ( V_39 -> V_41 & V_42 ) ||
V_28 > V_39 -> V_43 )
continue;
V_49 = V_39 ;
break;
}
if ( V_49 )
break;
}
if ( V_49 ) {
if ( V_49 -> V_40 & V_51 )
V_47 = F_23 ( V_47 ) ;
F_24 ( V_48 ) ;
}
F_25 ( L_1 ,
( unsigned long long ) V_28 , F_26 ( V_47 ) ) ;
return V_47 ;
}
int F_27 ( struct V_26 * V_3 , struct V_52 * V_53 ,
enum V_29 V_30 , int V_54 )
{
T_1 V_28 =
( ( T_1 ) V_53 -> V_55 ) << V_50 ;
struct V_27 * V_39 ;
int V_17 ;
V_39 = F_17 ( V_3 , & V_28 , V_30 ) ;
if ( V_39 == NULL )
return - V_56 ;
V_53 -> V_55 = V_28 >> V_50 ;
V_53 -> V_57 = F_21 ( V_53 -> V_57 ) ;
V_17 = F_28 ( V_53 , V_53 -> V_58 , V_53 -> V_55 ,
V_53 -> V_59 - V_53 -> V_58 , V_53 -> V_57 ) ;
return V_17 ;
}
int F_29 ( struct V_60 * V_31 , T_5 V_61 , T_6 * V_62 , T_7 V_18 )
{
unsigned long V_28 ;
struct V_1 * V_14 = F_18 ( V_31 ) ;
struct V_27 * V_39 = & V_14 -> V_15 ;
void T_2 * V_63 ;
V_28 = ( unsigned long ) V_14 -> V_19 - V_22 ;
V_28 += V_61 ;
if ( ! ( V_39 -> V_40 & V_37 ) )
return - V_64 ;
if ( V_28 < V_39 -> V_41 || ( V_28 + V_18 ) > V_39 -> V_43 )
return - V_64 ;
V_63 = V_14 -> V_19 + V_61 ;
switch ( V_18 ) {
case 1 :
* ( ( V_65 * ) V_62 ) = F_30 ( V_63 ) ;
return 1 ;
case 2 :
if ( V_61 & 1 )
return - V_56 ;
* ( ( V_66 * ) V_62 ) = F_31 ( V_63 ) ;
return 2 ;
case 4 :
if ( V_61 & 3 )
return - V_56 ;
* ( ( T_6 * ) V_62 ) = F_32 ( V_63 ) ;
return 4 ;
}
return - V_56 ;
}
int F_33 ( struct V_60 * V_31 , T_5 V_61 , T_6 V_62 , T_7 V_18 )
{
unsigned long V_28 ;
struct V_1 * V_14 = F_18 ( V_31 ) ;
struct V_27 * V_39 = & V_14 -> V_15 ;
void T_2 * V_63 ;
V_28 = ( unsigned long ) V_14 -> V_19 - V_22 ;
V_28 += V_61 ;
if ( ! ( V_39 -> V_40 & V_37 ) )
return - V_64 ;
if ( V_28 < V_39 -> V_41 || ( V_28 + V_18 ) > V_39 -> V_43 )
return - V_64 ;
V_63 = V_14 -> V_19 + V_61 ;
switch ( V_18 ) {
case 1 :
F_34 ( V_63 , V_62 >> 24 ) ;
return 1 ;
case 2 :
if ( V_61 & 1 )
return - V_56 ;
F_35 ( V_63 , V_62 >> 16 ) ;
return 2 ;
case 4 :
if ( V_61 & 3 )
return - V_56 ;
F_36 ( V_63 , V_62 ) ;
return 4 ;
}
return - V_56 ;
}
int F_37 ( struct V_60 * V_31 ,
struct V_52 * V_53 ,
enum V_29 V_30 )
{
struct V_1 * V_14 = F_18 ( V_31 ) ;
T_1 V_28 =
( ( T_1 ) V_53 -> V_55 ) << V_50 ;
T_1 V_18 = V_53 -> V_59 - V_53 -> V_58 ;
struct V_27 * V_39 ;
F_25 ( L_2 ,
F_38 ( V_31 ) , V_31 -> V_67 ,
V_30 == V_35 ? L_3 : L_4 ,
( unsigned long long ) V_28 ,
( unsigned long long ) ( V_28 + V_18 - 1 ) ) ;
if ( V_30 == V_35 ) {
if ( ( V_28 + V_18 ) > V_14 -> V_68 ) {
#ifdef F_39
F_25 ( L_5 ,
V_69 -> V_70 , V_69 -> V_71 ) ;
F_25 ( L_6 ,
F_38 ( V_31 ) , V_31 -> V_67 ) ;
#endif
if ( V_53 -> V_72 & V_73 )
return F_40 ( V_53 ) ;
return 0 ;
}
V_28 += V_14 -> V_74 ;
} else {
unsigned long V_32 = ( unsigned long ) V_14 -> V_19 -
V_22 ;
unsigned long V_75 = V_28 + V_32 ;
V_39 = & V_14 -> V_15 ;
if ( ! ( V_39 -> V_40 & V_37 ) )
return - V_64 ;
if ( V_75 < V_39 -> V_41 || ( V_75 + V_18 ) > V_39 -> V_43 )
return - V_64 ;
V_28 += V_14 -> V_20 ;
}
F_25 ( L_7 , ( unsigned long long ) V_28 ) ;
V_53 -> V_55 = V_28 >> V_50 ;
V_53 -> V_57 = F_21 ( V_53 -> V_57 ) ;
return F_28 ( V_53 , V_53 -> V_58 , V_53 -> V_55 ,
V_53 -> V_59 - V_53 -> V_58 ,
V_53 -> V_57 ) ;
}
void F_41 ( const struct V_26 * V_3 , int V_76 ,
const struct V_27 * V_77 ,
T_1 * V_41 , T_1 * V_43 )
{
struct V_78 V_79 ;
if ( V_77 -> V_40 & V_37 ) {
F_42 ( V_3 -> V_31 , & V_79 ,
(struct V_27 * ) V_77 ) ;
* V_41 = V_79 . V_41 ;
* V_43 = V_79 . V_43 ;
return;
}
* V_41 = V_77 -> V_41 ;
* V_43 = V_77 -> V_43 ;
}
void F_43 ( struct V_1 * V_14 ,
struct V_2 * V_3 , int V_80 )
{
int V_81 = 0 , V_82 = - 1 ;
unsigned long long V_83 = 0 ;
struct V_27 * V_84 ;
struct V_85 V_86 ;
struct V_87 V_88 ;
F_44 ( L_8 ,
V_3 -> V_89 , V_80 ? L_9 : L_10 ) ;
if ( F_45 ( & V_88 , V_3 ) )
return;
F_25 ( L_11 ) ;
F_46 (&parser, &range) {
F_25 ( L_12 ,
V_86 . V_90 , V_86 . V_91 ) ;
F_25 ( L_13 ,
V_86 . V_92 , V_86 . V_18 ) ;
if ( V_86 . V_92 == V_93 || V_86 . V_18 == 0 )
continue;
V_84 = NULL ;
switch ( V_86 . V_40 & V_94 ) {
case V_37 :
F_44 ( L_14 ,
V_86 . V_92 , V_86 . V_92 + V_86 . V_18 - 1 ,
V_86 . V_91 ) ;
if ( V_14 -> V_95 ) {
F_44 ( L_15 ) ;
continue;
}
if ( V_86 . V_18 > 0x01000000 )
V_86 . V_18 = 0x01000000 ;
V_14 -> V_19 = F_47 ( V_86 . V_92 ,
V_86 . V_18 ) ;
if ( V_80 )
V_96 =
( unsigned long ) V_14 -> V_19 ;
V_14 -> V_95 = V_86 . V_91 + V_86 . V_18 ;
V_14 -> V_20 = V_86 . V_92 - V_86 . V_91 ;
V_84 = & V_14 -> V_15 ;
V_86 . V_92 = V_86 . V_91 ;
break;
case V_36 :
F_44 ( L_16 ,
V_86 . V_92 , V_86 . V_92 + V_86 . V_18 - 1 ,
V_86 . V_91 ,
( V_86 . V_90 & 0x40000000 ) ?
L_17 : L_10 ) ;
if ( V_81 >= 3 ) {
F_44 ( L_15 ) ;
continue;
}
if ( V_86 . V_91 == 0 ) {
V_83 = V_86 . V_92 ;
V_82 = V_81 ;
if ( V_80 || V_97 == 0 )
V_97 = V_86 . V_92 ;
V_14 -> V_74 = V_86 . V_92 ;
V_14 -> V_68 = V_86 . V_18 ;
}
if ( V_81 == 0 ||
( V_82 >= 0 && V_86 . V_91 != 0 &&
V_14 -> V_98 == V_83 ) )
V_14 -> V_98 = V_86 . V_92 -
V_86 . V_91 ;
else if ( V_86 . V_91 != 0 &&
V_14 -> V_98 != V_86 . V_92 -
V_86 . V_91 ) {
F_44 ( L_18 ) ;
continue;
}
V_84 = & V_14 -> V_99 [ V_81 ++ ] ;
break;
}
if ( V_84 != NULL ) {
V_84 -> V_100 = V_3 -> V_89 ;
V_84 -> V_40 = V_86 . V_40 ;
V_84 -> V_41 = V_86 . V_92 ;
V_84 -> V_43 = V_86 . V_92 + V_86 . V_18 - 1 ;
V_84 -> V_25 = V_84 -> V_101 = V_84 -> V_102 = NULL ;
}
}
if ( V_82 >= 0 && V_14 -> V_98 != V_83 ) {
unsigned int V_103 = V_82 + 1 ;
F_44 ( L_19 , V_83 ) ;
if ( V_103 < V_81 )
memmove ( & V_14 -> V_99 [ V_82 ] ,
& V_14 -> V_99 [ V_103 ] ,
sizeof( struct V_27 ) * ( V_81 - V_103 ) ) ;
V_14 -> V_99 [ -- V_81 ] . V_40 = 0 ;
}
}
int F_48 ( struct V_60 * V_31 )
{
return F_38 ( V_31 ) ;
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
for ( V_33 = 0 ; V_33 < V_104 ; V_33 ++ ) {
struct V_27 * V_84 = V_3 -> V_27 + V_33 ;
if ( ! V_84 -> V_40 )
continue;
if ( V_84 -> V_41 == 0 ) {
F_25 ( L_21 ,
F_51 ( V_3 ) , V_33 ,
( unsigned long long ) V_84 -> V_41 ,
( unsigned long long ) V_84 -> V_43 ,
( unsigned int ) V_84 -> V_40 ) ;
F_25 ( L_22 ) ;
V_84 -> V_43 -= V_84 -> V_41 ;
V_84 -> V_41 = 0 ;
V_84 -> V_40 |= V_105 ;
continue;
}
F_25 ( L_23 ,
F_51 ( V_3 ) , V_33 ,
( unsigned long long ) V_84 -> V_41 ,
( unsigned long long ) V_84 -> V_43 ,
( unsigned int ) V_84 -> V_40 ) ;
}
}
static int F_52 ( struct V_60 * V_31 ,
struct V_27 * V_84 )
{
struct V_1 * V_14 = F_18 ( V_31 ) ;
struct V_26 * V_3 = V_31 -> V_106 ;
T_1 V_28 ;
V_66 V_107 ;
int V_33 ;
if ( V_84 -> V_40 & V_36 ) {
if ( V_84 -> V_41 != V_14 -> V_98 )
return 0 ;
F_53 ( V_3 , V_108 , & V_107 ) ;
if ( ( V_107 & V_109 ) == 0 )
return 1 ;
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
if ( ( V_14 -> V_99 [ V_33 ] . V_40 & V_36 ) &&
V_14 -> V_99 [ V_33 ] . V_41 == V_14 -> V_98 )
return 0 ;
}
return 1 ;
} else {
V_28 = ( unsigned long ) V_14 -> V_19 - V_22 ;
if ( ( ( V_84 -> V_41 - V_28 ) & 0xfffffffful ) != 0 )
return 0 ;
F_53 ( V_3 , V_108 , & V_107 ) ;
if ( V_107 & V_110 )
return 0 ;
return 1 ;
}
}
static void F_54 ( struct V_60 * V_31 )
{
struct V_27 * V_84 ;
int V_33 ;
struct V_26 * V_3 = V_31 -> V_106 ;
F_55 (bus, res, i) {
if ( ! V_84 )
continue;
if ( ! V_84 -> V_40 )
continue;
if ( V_33 >= 3 && V_31 -> V_106 -> V_111 )
continue;
F_25 ( L_24 ,
F_51 ( V_3 ) , V_33 ,
( unsigned long long ) V_84 -> V_41 ,
( unsigned long long ) V_84 -> V_43 ,
( unsigned int ) V_84 -> V_40 ) ;
if ( F_52 ( V_31 , V_84 ) ) {
V_84 -> V_40 = 0 ;
F_25 ( L_25 ,
F_51 ( V_3 ) ) ;
} else {
F_25 ( L_26 ,
F_51 ( V_3 ) ,
( unsigned long long ) V_84 -> V_41 ,
( unsigned long long ) V_84 -> V_43 ) ;
}
}
}
void F_56 ( struct V_60 * V_31 )
{
if ( V_31 -> V_106 != NULL )
F_54 ( V_31 ) ;
}
void F_57 ( struct V_60 * V_31 )
{
struct V_26 * V_3 ;
F_25 ( L_27 ,
V_31 -> V_67 , V_31 -> V_106 ? F_51 ( V_31 -> V_106 ) : L_28 ) ;
F_12 (dev, &bus->devices, bus_list) {
V_3 -> V_3 . V_112 = F_58 ( V_3 ) ;
F_59 ( & V_3 -> V_3 , F_60 ( V_3 -> V_31 ) ) ;
V_3 -> V_113 = F_61 ( V_3 , 0 , 0 ) ;
}
}
void F_62 ( struct V_60 * V_31 )
{
}
T_1 F_63 ( void * V_114 , const struct V_27 * V_84 ,
T_1 V_18 , T_1 V_115 )
{
return V_84 -> V_41 ;
}
int F_64 ( struct V_26 * V_3 )
{
V_3 -> V_113 = F_61 ( V_3 , 0 , 0 ) ;
return 0 ;
}
static int T_8 F_65 ( struct V_27 * V_25 ,
struct V_27 * V_84 )
{
struct V_27 * V_116 , * * V_117 ;
struct V_27 * * V_118 = NULL ;
for ( V_117 = & V_25 -> V_101 ; ( V_116 = * V_117 ) != NULL ; V_117 = & V_116 -> V_102 ) {
if ( V_116 -> V_43 < V_84 -> V_41 )
continue;
if ( V_84 -> V_43 < V_116 -> V_41 )
break;
if ( V_116 -> V_41 < V_84 -> V_41 || V_116 -> V_43 > V_84 -> V_43 )
return - 1 ;
if ( V_118 == NULL )
V_118 = V_117 ;
}
if ( V_118 == NULL )
return - 1 ;
V_84 -> V_25 = V_25 ;
V_84 -> V_101 = * V_118 ;
V_84 -> V_102 = * V_117 ;
* V_118 = V_84 ;
* V_117 = NULL ;
for ( V_116 = V_84 -> V_101 ; V_116 != NULL ; V_116 = V_116 -> V_102 ) {
V_116 -> V_25 = V_84 ;
F_25 ( L_29 ,
V_116 -> V_100 ,
( unsigned long long ) V_116 -> V_41 ,
( unsigned long long ) V_116 -> V_43 , V_84 -> V_100 ) ;
}
return 0 ;
}
static void F_66 ( struct V_60 * V_31 )
{
struct V_60 * V_119 ;
int V_33 ;
struct V_27 * V_84 , * V_120 ;
F_25 ( L_30 ,
F_38 ( V_31 ) , V_31 -> V_67 ) ;
F_55 (bus, res, i) {
if ( ! V_84 || ! V_84 -> V_40
|| V_84 -> V_41 > V_84 -> V_43 || V_84 -> V_25 )
continue;
if ( V_31 -> V_25 == NULL )
V_120 = ( V_84 -> V_40 & V_37 ) ?
& V_121 : & V_122 ;
else {
V_120 = F_67 ( V_31 -> V_106 , V_84 ) ;
if ( V_120 == V_84 ) {
continue;
}
}
F_25 ( L_31 ,
V_31 -> V_106 ? F_51 ( V_31 -> V_106 ) : L_28 ,
V_31 -> V_67 , V_33 ,
( unsigned long long ) V_84 -> V_41 ,
( unsigned long long ) V_84 -> V_43 ) ;
F_25 ( L_32 ,
( unsigned int ) V_84 -> V_40 ,
V_120 , ( V_120 && V_120 -> V_100 ) ? V_120 -> V_100 : L_33 ) ;
if ( V_120 && ! ( V_120 -> V_40 & V_105 ) ) {
struct V_26 * V_3 = V_31 -> V_106 ;
if ( F_68 ( V_120 , V_84 ) == 0 )
continue;
if ( F_65 ( V_120 , V_84 ) == 0 )
continue;
if ( V_3 && V_33 < V_123 &&
F_69 ( V_3 ,
V_33 + V_124 ) == 0 )
continue;
}
F_70 ( L_34 ) ;
F_71 ( L_35 , V_33 , V_31 -> V_67 ) ;
V_84 -> V_41 = V_84 -> V_43 = 0 ;
V_84 -> V_40 = 0 ;
}
F_12 (b, &bus->children, node)
F_66 ( V_119 ) ;
}
static inline void F_72 ( struct V_26 * V_3 , int V_125 )
{
struct V_27 * V_120 , * V_126 = & V_3 -> V_27 [ V_125 ] ;
F_25 ( L_36 ,
F_51 ( V_3 ) , V_125 ,
( unsigned long long ) V_126 -> V_41 ,
( unsigned long long ) V_126 -> V_43 ,
( unsigned int ) V_126 -> V_40 ) ;
V_120 = F_67 ( V_3 , V_126 ) ;
if ( ! V_120 || ( V_120 -> V_40 & V_105 ) ||
F_68 ( V_120 , V_126 ) < 0 ) {
F_70 ( L_37 , V_125 ) ;
F_71 ( L_38 , F_51 ( V_3 ) ) ;
if ( V_120 )
F_25 ( L_39 ,
V_120 ,
( unsigned long long ) V_120 -> V_41 ,
( unsigned long long ) V_120 -> V_43 ,
( unsigned int ) V_120 -> V_40 ) ;
V_126 -> V_40 |= V_105 ;
V_126 -> V_43 -= V_126 -> V_41 ;
V_126 -> V_41 = 0 ;
}
}
static void T_8 F_73 ( int V_127 )
{
struct V_26 * V_3 = NULL ;
int V_125 , V_128 ;
V_66 V_107 ;
struct V_27 * V_126 ;
F_22 (dev) {
F_53 ( V_3 , V_108 , & V_107 ) ;
for ( V_125 = 0 ; V_125 <= V_38 ; V_125 ++ ) {
V_126 = & V_3 -> V_27 [ V_125 ] ;
if ( V_126 -> V_25 )
continue;
if ( ! V_126 -> V_40 || ( V_126 -> V_40 & V_105 ) )
continue;
if ( V_125 == V_38 )
V_128 = 1 ;
if ( V_126 -> V_40 & V_37 )
V_128 = ! ( V_107 & V_110 ) ;
else
V_128 = ! ( V_107 & V_109 ) ;
if ( V_127 == V_128 )
F_72 ( V_3 , V_125 ) ;
}
if ( V_127 )
continue;
V_126 = & V_3 -> V_27 [ V_38 ] ;
if ( V_126 -> V_40 ) {
T_6 V_129 ;
F_74 ( V_3 , V_3 -> V_130 , & V_129 ) ;
if ( V_129 & V_131 ) {
F_25 ( L_40 ,
F_51 ( V_3 ) ) ;
V_126 -> V_40 &= ~ V_132 ;
F_75 ( V_3 , V_3 -> V_130 ,
V_129 & ~ V_131 ) ;
}
}
}
}
static void T_8 F_76 ( struct V_60 * V_31 )
{
struct V_1 * V_14 = F_18 ( V_31 ) ;
T_1 V_28 ;
struct V_27 * V_84 , * V_133 ;
int V_33 ;
F_25 ( L_41 ,
F_38 ( V_31 ) ) ;
if ( ! ( V_14 -> V_15 . V_40 & V_37 ) )
goto V_134;
V_28 = ( unsigned long ) V_14 -> V_19 - V_22 ;
V_84 = F_77 ( sizeof( struct V_27 ) , V_5 ) ;
F_78 ( V_84 == NULL ) ;
V_84 -> V_100 = L_42 ;
V_84 -> V_40 = V_37 ;
V_84 -> V_41 = V_28 ;
V_84 -> V_43 = ( V_28 + 0xfff ) & 0xfffffffful ;
F_25 ( L_43 , V_84 ) ;
if ( F_68 ( & V_14 -> V_15 , V_84 ) ) {
F_25 ( L_44 ,
F_38 ( V_31 ) , V_31 -> V_67 , V_84 ) ;
F_8 ( V_84 ) ;
}
V_134:
V_28 = V_14 -> V_98 ;
F_25 ( L_45 , ( unsigned long long ) V_28 ) ;
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
V_133 = & V_14 -> V_99 [ V_33 ] ;
if ( ! ( V_133 -> V_40 & V_36 ) )
continue;
F_25 ( L_46 , V_133 ) ;
if ( ( V_133 -> V_41 - V_28 ) <= 0xa0000 &&
( V_133 -> V_43 - V_28 ) >= 0xbffff )
break;
}
if ( V_33 >= 3 )
return;
V_84 = F_77 ( sizeof( struct V_27 ) , V_5 ) ;
F_78 ( V_84 == NULL ) ;
V_84 -> V_100 = L_47 ;
V_84 -> V_40 = V_36 ;
V_84 -> V_41 = 0xa0000 + V_28 ;
V_84 -> V_43 = 0xbffff + V_28 ;
F_25 ( L_48 , V_84 ) ;
if ( F_68 ( V_133 , V_84 ) ) {
F_25 ( L_49 ,
F_38 ( V_31 ) , V_31 -> V_67 , V_84 ) ;
F_8 ( V_84 ) ;
}
}
void T_8 F_79 ( void )
{
struct V_60 * V_119 ;
F_12 (b, &pci_root_buses, node)
F_66 ( V_119 ) ;
F_73 ( 0 ) ;
F_73 ( 1 ) ;
F_12 (b, &pci_root_buses, node)
F_76 ( V_119 ) ;
F_25 ( L_50 ) ;
F_80 () ;
}
void F_81 ( struct V_60 * V_31 )
{
struct V_26 * V_3 ;
struct V_60 * V_135 ;
F_12 (dev, &bus->devices, bus_list) {
int V_33 ;
for ( V_33 = 0 ; V_33 < V_136 ; V_33 ++ ) {
struct V_27 * V_126 = & V_3 -> V_27 [ V_33 ] ;
if ( V_126 -> V_25 || ! V_126 -> V_41 || ! V_126 -> V_40 )
continue;
F_25 ( L_51 , F_51 ( V_3 ) ) ;
F_25 ( L_52 ,
V_33 , ( unsigned long long ) V_126 -> V_41 ,
( unsigned long long ) V_126 -> V_43 ,
( unsigned int ) V_126 -> V_40 ) ;
if ( F_82 ( V_3 , V_33 ) == 0 )
continue;
F_69 ( V_3 , V_33 ) ;
}
}
F_12 (child_bus, &bus->children, node)
F_81 ( V_135 ) ;
}
void F_83 ( struct V_60 * V_31 )
{
F_25 ( L_53 ,
F_38 ( V_31 ) , V_31 -> V_67 ) ;
F_66 ( V_31 ) ;
F_81 ( V_31 ) ;
F_84 ( V_31 ) ;
}
static void F_85 ( struct V_1 * V_14 ,
struct V_137 * V_138 )
{
unsigned long V_32 ;
struct V_27 * V_84 ;
int V_33 ;
V_84 = & V_14 -> V_15 ;
V_32 = ( unsigned long ) V_14 -> V_19 - V_96 ;
V_84 -> V_41 = ( V_84 -> V_41 + V_32 ) & 0xffffffffu ;
V_84 -> V_43 = ( V_84 -> V_43 + V_32 ) & 0xffffffffu ;
if ( ! V_84 -> V_40 ) {
F_70 ( L_54 ) ;
F_71 ( L_55 ,
V_14 -> V_11 -> V_89 , V_14 -> V_7 ) ;
V_84 -> V_41 = ( unsigned long ) V_14 -> V_19 - V_96 ;
V_84 -> V_43 = V_84 -> V_41 + V_139 ;
V_84 -> V_40 = V_37 ;
}
F_86 ( V_138 , V_84 ,
( V_140 T_1 ) ( V_14 -> V_19 - V_22 ) ) ;
F_25 ( L_56 ,
( unsigned long long ) V_84 -> V_41 ,
( unsigned long long ) V_84 -> V_43 ,
( unsigned long ) V_84 -> V_40 ) ;
for ( V_33 = 0 ; V_33 < 3 ; ++ V_33 ) {
V_84 = & V_14 -> V_99 [ V_33 ] ;
if ( ! V_84 -> V_40 ) {
if ( V_33 > 0 )
continue;
F_50 ( L_57 ) ;
F_71 ( L_58 ,
V_14 -> V_11 -> V_89 , V_14 -> V_7 ) ;
V_84 -> V_41 = V_14 -> V_98 ;
V_84 -> V_43 = ( T_1 ) - 1LL ;
V_84 -> V_40 = V_36 ;
}
F_86 ( V_138 , V_84 , V_14 -> V_98 ) ;
F_25 ( L_59 ,
V_33 , ( unsigned long long ) V_84 -> V_41 ,
( unsigned long long ) V_84 -> V_43 ,
( unsigned long ) V_84 -> V_40 ) ;
}
F_25 ( L_60 ,
( unsigned long long ) V_14 -> V_98 ) ;
F_25 ( L_61 ,
( unsigned long ) V_14 -> V_19 - V_22 ) ;
}
static void F_87 ( struct V_1 * V_14 )
{
F_88 ( V_138 ) ;
struct V_60 * V_31 ;
struct V_2 * V_23 = V_14 -> V_11 ;
F_25 ( L_62 , F_89 ( V_23 ) ) ;
F_85 ( V_14 , & V_138 ) ;
V_31 = F_90 ( V_14 -> V_25 , V_14 -> V_141 ,
V_14 -> V_142 , V_14 , & V_138 ) ;
if ( V_31 == NULL ) {
F_50 ( L_63 ,
V_14 -> V_7 ) ;
F_91 ( & V_138 ) ;
return;
}
V_31 -> V_143 . V_41 = V_14 -> V_141 ;
V_14 -> V_31 = V_31 ;
V_14 -> V_144 = V_31 -> V_143 . V_43 ;
}
static int T_8 F_92 ( void )
{
struct V_1 * V_14 , * V_24 ;
int V_145 = 0 ;
F_44 ( L_64 ) ;
F_15 (hose, tmp, &hose_list, list_node) {
V_14 -> V_144 = 0xff ;
F_87 ( V_14 ) ;
if ( V_145 <= V_14 -> V_144 )
V_145 = V_14 -> V_144 + 1 ;
}
V_146 = V_145 ;
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
if ( V_31 >= V_14 -> V_141 && V_31 <= V_14 -> V_144 )
return V_14 ;
return NULL ;
}
long F_94 ( long V_147 , unsigned long V_31 , unsigned long V_148 )
{
struct V_1 * V_14 ;
long V_149 = - V_150 ;
V_14 = F_93 ( V_31 ) ;
if ( ! V_14 )
return - V_151 ;
switch ( V_147 ) {
case V_152 :
return ( long ) V_14 -> V_141 ;
case V_153 :
return ( long ) V_14 -> V_98 ;
case V_154 :
return ( long ) V_14 -> V_20 ;
case V_155 :
return ( long ) V_96 ;
case V_156 :
return ( long ) V_97 ;
}
return V_149 ;
}
static int
F_95 ( struct V_60 * V_31 , unsigned int V_148 , int V_28 ,
int V_157 , T_6 * V_62 )
{
return V_158 ;
}
static int
F_96 ( struct V_60 * V_31 , unsigned int V_148 , int V_28 ,
int V_157 , T_6 V_62 )
{
return V_158 ;
}
static struct V_60 *
F_97 ( struct V_1 * V_14 , int V_159 )
{
static struct V_60 V_31 ;
if ( ! V_14 )
F_50 ( L_65 , V_159 ) ;
V_31 . V_67 = V_159 ;
V_31 . V_160 = V_14 ;
V_31 . V_142 = V_14 ? V_14 -> V_142 : & V_161 ;
return & V_31 ;
}
int F_98 ( struct V_1 * V_14 , int V_31 , int V_148 ,
int V_162 )
{
return F_99 ( F_97 ( V_14 , V_31 ) , V_148 , V_162 ) ;
}
