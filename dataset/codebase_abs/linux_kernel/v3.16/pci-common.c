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
int F_14 ( struct V_23 * V_24 )
{
struct V_1 * V_14 = F_15 ( V_24 ) ;
return V_14 -> V_7 ;
}
struct V_1 * F_16 ( struct V_2 * V_25 )
{
while ( V_25 ) {
struct V_1 * V_14 , * V_26 ;
F_17 (hose, tmp, &hose_list, list_node)
if ( V_14 -> V_11 == V_25 )
return V_14 ;
V_25 = V_25 -> V_27 ;
}
return NULL ;
}
void F_18 ( struct V_28 * V_3 )
{
}
static struct V_29 * F_19 ( struct V_28 * V_3 ,
T_1 * V_30 ,
enum V_31 V_32 )
{
struct V_1 * V_14 = F_15 ( V_3 -> V_24 ) ;
unsigned long V_33 = 0 ;
int V_34 , V_35 ;
if ( ! V_14 )
return NULL ;
if ( V_32 == V_36 ) {
#if 0
*offset += hose->pci_mem_offset;
#endif
V_35 = V_37 ;
} else {
V_33 = ( unsigned long ) V_14 -> V_19 - V_22 ;
* V_30 += V_33 ;
V_35 = V_38 ;
}
for ( V_34 = 0 ; V_34 <= V_39 ; V_34 ++ ) {
struct V_29 * V_40 = & V_3 -> V_29 [ V_34 ] ;
int V_41 = V_40 -> V_41 ;
if ( V_34 == V_39 )
V_41 |= V_37 ;
if ( ( V_41 & V_35 ) == 0 )
continue;
if ( * V_30 < ( V_40 -> V_42 & V_43 ) || * V_30 > V_40 -> V_44 )
continue;
if ( V_32 == V_45 )
* V_30 += V_14 -> V_20 - V_33 ;
return V_40 ;
}
return NULL ;
}
static T_4 F_20 ( struct V_28 * V_3 , struct V_29 * V_40 ,
T_4 V_46 ,
enum V_31 V_32 ,
int V_47 )
{
T_4 V_48 = V_46 ;
if ( V_32 != V_36 )
V_47 = 0 ;
else if ( V_47 == 0 ) {
if ( V_40 -> V_41 & V_49 )
V_47 = 1 ;
}
return F_21 ( V_48 ) ;
}
T_4 F_22 ( struct V_50 * V_50 ,
unsigned long V_51 ,
unsigned long V_18 ,
T_4 V_48 )
{
struct V_28 * V_52 = NULL ;
struct V_29 * V_53 = NULL ;
T_1 V_30 = ( ( T_1 ) V_51 ) << V_54 ;
int V_34 ;
if ( F_23 ( V_51 ) )
return V_48 ;
V_48 = F_21 ( V_48 ) ;
F_24 (pdev) {
for ( V_34 = 0 ; V_34 <= V_39 ; V_34 ++ ) {
struct V_29 * V_40 = & V_52 -> V_29 [ V_34 ] ;
int V_41 = V_40 -> V_41 ;
if ( ( V_41 & V_37 ) == 0 )
continue;
if ( V_30 < ( V_40 -> V_42 & V_43 ) ||
V_30 > V_40 -> V_44 )
continue;
V_53 = V_40 ;
break;
}
if ( V_53 )
break;
}
if ( V_53 ) {
if ( V_53 -> V_41 & V_49 )
V_48 = F_25 ( V_48 ) ;
F_26 ( V_52 ) ;
}
F_27 ( L_1 ,
( unsigned long long ) V_30 , F_28 ( V_48 ) ) ;
return V_48 ;
}
int F_29 ( struct V_28 * V_3 , struct V_55 * V_56 ,
enum V_31 V_32 , int V_47 )
{
T_1 V_30 =
( ( T_1 ) V_56 -> V_57 ) << V_54 ;
struct V_29 * V_40 ;
int V_17 ;
V_40 = F_19 ( V_3 , & V_30 , V_32 ) ;
if ( V_40 == NULL )
return - V_58 ;
V_56 -> V_57 = V_30 >> V_54 ;
V_56 -> V_59 = F_20 ( V_3 , V_40 ,
V_56 -> V_59 ,
V_32 , V_47 ) ;
V_17 = F_30 ( V_56 , V_56 -> V_60 , V_56 -> V_57 ,
V_56 -> V_61 - V_56 -> V_60 , V_56 -> V_59 ) ;
return V_17 ;
}
int F_31 ( struct V_23 * V_24 , T_5 V_62 , T_6 * V_63 , T_7 V_18 )
{
unsigned long V_30 ;
struct V_1 * V_14 = F_15 ( V_24 ) ;
struct V_29 * V_40 = & V_14 -> V_15 ;
void T_2 * V_64 ;
V_30 = ( unsigned long ) V_14 -> V_19 - V_22 ;
V_30 += V_62 ;
if ( ! ( V_40 -> V_41 & V_38 ) )
return - V_65 ;
if ( V_30 < V_40 -> V_42 || ( V_30 + V_18 ) > V_40 -> V_44 )
return - V_65 ;
V_64 = V_14 -> V_19 + V_62 ;
switch ( V_18 ) {
case 1 :
* ( ( V_66 * ) V_63 ) = F_32 ( V_64 ) ;
return 1 ;
case 2 :
if ( V_62 & 1 )
return - V_58 ;
* ( ( V_67 * ) V_63 ) = F_33 ( V_64 ) ;
return 2 ;
case 4 :
if ( V_62 & 3 )
return - V_58 ;
* ( ( T_6 * ) V_63 ) = F_34 ( V_64 ) ;
return 4 ;
}
return - V_58 ;
}
int F_35 ( struct V_23 * V_24 , T_5 V_62 , T_6 V_63 , T_7 V_18 )
{
unsigned long V_30 ;
struct V_1 * V_14 = F_15 ( V_24 ) ;
struct V_29 * V_40 = & V_14 -> V_15 ;
void T_2 * V_64 ;
V_30 = ( unsigned long ) V_14 -> V_19 - V_22 ;
V_30 += V_62 ;
if ( ! ( V_40 -> V_41 & V_38 ) )
return - V_65 ;
if ( V_30 < V_40 -> V_42 || ( V_30 + V_18 ) > V_40 -> V_44 )
return - V_65 ;
V_64 = V_14 -> V_19 + V_62 ;
switch ( V_18 ) {
case 1 :
F_36 ( V_64 , V_63 >> 24 ) ;
return 1 ;
case 2 :
if ( V_62 & 1 )
return - V_58 ;
F_37 ( V_64 , V_63 >> 16 ) ;
return 2 ;
case 4 :
if ( V_62 & 3 )
return - V_58 ;
F_38 ( V_64 , V_63 ) ;
return 4 ;
}
return - V_58 ;
}
int F_39 ( struct V_23 * V_24 ,
struct V_55 * V_56 ,
enum V_31 V_32 )
{
struct V_1 * V_14 = F_15 ( V_24 ) ;
T_1 V_30 =
( ( T_1 ) V_56 -> V_57 ) << V_54 ;
T_1 V_18 = V_56 -> V_61 - V_56 -> V_60 ;
struct V_29 * V_40 ;
F_27 ( L_2 ,
F_14 ( V_24 ) , V_24 -> V_68 ,
V_32 == V_36 ? L_3 : L_4 ,
( unsigned long long ) V_30 ,
( unsigned long long ) ( V_30 + V_18 - 1 ) ) ;
if ( V_32 == V_36 ) {
if ( ( V_30 + V_18 ) > V_14 -> V_69 ) {
#ifdef F_40
F_27 ( L_5 ,
V_70 -> V_71 , V_70 -> V_72 ) ;
F_27 ( L_6 ,
F_14 ( V_24 ) , V_24 -> V_68 ) ;
#endif
if ( V_56 -> V_73 & V_74 )
return F_41 ( V_56 ) ;
return 0 ;
}
V_30 += V_14 -> V_75 ;
} else {
unsigned long V_33 = ( unsigned long ) V_14 -> V_19 -
V_22 ;
unsigned long V_76 = V_30 + V_33 ;
V_40 = & V_14 -> V_15 ;
if ( ! ( V_40 -> V_41 & V_38 ) )
return - V_65 ;
if ( V_76 < V_40 -> V_42 || ( V_76 + V_18 ) > V_40 -> V_44 )
return - V_65 ;
V_30 += V_14 -> V_20 ;
}
F_27 ( L_7 , ( unsigned long long ) V_30 ) ;
V_56 -> V_57 = V_30 >> V_54 ;
V_56 -> V_59 = F_21 ( V_56 -> V_59 ) ;
return F_30 ( V_56 , V_56 -> V_60 , V_56 -> V_57 ,
V_56 -> V_61 - V_56 -> V_60 ,
V_56 -> V_59 ) ;
}
void F_42 ( const struct V_28 * V_3 , int V_77 ,
const struct V_29 * V_78 ,
T_1 * V_42 , T_1 * V_44 )
{
struct V_1 * V_14 = F_15 ( V_3 -> V_24 ) ;
T_1 V_30 = 0 ;
if ( V_14 == NULL )
return;
if ( V_78 -> V_41 & V_38 )
V_30 = ( unsigned long ) V_14 -> V_19 - V_22 ;
#if 0
else if (rsrc->flags & IORESOURCE_MEM)
offset = hose->pci_mem_offset;
#endif
* V_42 = V_78 -> V_42 - V_30 ;
* V_44 = V_78 -> V_44 - V_30 ;
}
void F_43 ( struct V_1 * V_14 ,
struct V_2 * V_3 , int V_79 )
{
int V_80 = 0 , V_81 = - 1 ;
unsigned long long V_82 = 0 ;
struct V_29 * V_83 ;
struct V_84 V_85 ;
struct V_86 V_87 ;
F_44 ( L_8 ,
V_3 -> V_88 , V_79 ? L_9 : L_10 ) ;
if ( F_45 ( & V_87 , V_3 ) )
return;
F_27 ( L_11 ) ;
F_46 (&parser, &range) {
F_27 ( L_12 ,
V_85 . V_89 , V_85 . V_90 ) ;
F_27 ( L_13 ,
V_85 . V_91 , V_85 . V_18 ) ;
if ( V_85 . V_91 == V_92 || V_85 . V_18 == 0 )
continue;
V_83 = NULL ;
switch ( V_85 . V_41 & V_93 ) {
case V_38 :
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
case V_37 :
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
if ( V_83 != NULL )
F_48 ( & V_85 , V_3 , V_83 ) ;
}
if ( V_81 >= 0 && V_14 -> V_97 != V_82 ) {
unsigned int V_99 = V_81 + 1 ;
F_44 ( L_19 , V_82 ) ;
if ( V_99 < V_80 )
memmove ( & V_14 -> V_98 [ V_81 ] ,
& V_14 -> V_98 [ V_99 ] ,
sizeof( struct V_29 ) * ( V_80 - V_99 ) ) ;
V_14 -> V_98 [ -- V_80 ] . V_41 = 0 ;
}
}
int F_49 ( struct V_23 * V_24 )
{
return 0 ;
}
static void F_50 ( struct V_28 * V_3 )
{
struct V_1 * V_14 = F_15 ( V_3 -> V_24 ) ;
int V_34 ;
if ( ! V_14 ) {
F_51 ( L_20 ,
F_52 ( V_3 ) ) ;
return;
}
for ( V_34 = 0 ; V_34 < V_100 ; V_34 ++ ) {
struct V_29 * V_83 = V_3 -> V_29 + V_34 ;
if ( ! V_83 -> V_41 )
continue;
if ( V_83 -> V_42 == 0 ) {
F_27 ( L_21 ,
F_52 ( V_3 ) , V_34 ,
( unsigned long long ) V_83 -> V_42 ,
( unsigned long long ) V_83 -> V_44 ,
( unsigned int ) V_83 -> V_41 ) ;
F_27 ( L_22 ) ;
V_83 -> V_44 -= V_83 -> V_42 ;
V_83 -> V_42 = 0 ;
V_83 -> V_41 |= V_101 ;
continue;
}
F_27 ( L_23 ,
F_52 ( V_3 ) , V_34 ,
( unsigned long long ) V_83 -> V_42 ,
( unsigned long long ) V_83 -> V_44 ,
( unsigned int ) V_83 -> V_41 ) ;
}
}
static int F_53 ( struct V_23 * V_24 ,
struct V_29 * V_83 )
{
struct V_1 * V_14 = F_15 ( V_24 ) ;
struct V_28 * V_3 = V_24 -> V_102 ;
T_1 V_30 ;
V_67 V_103 ;
int V_34 ;
if ( V_83 -> V_41 & V_37 ) {
if ( V_83 -> V_42 != V_14 -> V_97 )
return 0 ;
F_54 ( V_3 , V_104 , & V_103 ) ;
if ( ( V_103 & V_105 ) == 0 )
return 1 ;
for ( V_34 = 0 ; V_34 < 3 ; V_34 ++ ) {
if ( ( V_14 -> V_98 [ V_34 ] . V_41 & V_37 ) &&
V_14 -> V_98 [ V_34 ] . V_42 == V_14 -> V_97 )
return 0 ;
}
return 1 ;
} else {
V_30 = ( unsigned long ) V_14 -> V_19 - V_22 ;
if ( ( ( V_83 -> V_42 - V_30 ) & 0xfffffffful ) != 0 )
return 0 ;
F_54 ( V_3 , V_104 , & V_103 ) ;
if ( V_103 & V_106 )
return 0 ;
return 1 ;
}
}
static void F_55 ( struct V_23 * V_24 )
{
struct V_29 * V_83 ;
int V_34 ;
struct V_28 * V_3 = V_24 -> V_102 ;
F_56 (bus, res, i) {
if ( ! V_83 )
continue;
if ( ! V_83 -> V_41 )
continue;
if ( V_34 >= 3 && V_24 -> V_102 -> V_107 )
continue;
F_27 ( L_24 ,
F_52 ( V_3 ) , V_34 ,
( unsigned long long ) V_83 -> V_42 ,
( unsigned long long ) V_83 -> V_44 ,
( unsigned int ) V_83 -> V_41 ) ;
if ( F_53 ( V_24 , V_83 ) ) {
V_83 -> V_41 = 0 ;
F_27 ( L_25 ,
F_52 ( V_3 ) ) ;
} else {
F_27 ( L_26 ,
F_52 ( V_3 ) ,
( unsigned long long ) V_83 -> V_42 ,
( unsigned long long ) V_83 -> V_44 ) ;
}
}
}
void F_57 ( struct V_23 * V_24 )
{
if ( V_24 -> V_102 != NULL )
F_55 ( V_24 ) ;
}
void F_58 ( struct V_23 * V_24 )
{
struct V_28 * V_3 ;
F_27 ( L_27 ,
V_24 -> V_68 , V_24 -> V_102 ? F_52 ( V_24 -> V_102 ) : L_28 ) ;
F_12 (dev, &bus->devices, bus_list) {
V_3 -> V_3 . V_108 = F_59 ( V_3 ) ;
F_60 ( & V_3 -> V_3 , F_61 ( V_3 -> V_24 ) ) ;
V_3 -> V_109 = F_62 ( V_3 , 0 , 0 ) ;
}
}
void F_63 ( struct V_23 * V_24 )
{
if ( V_24 -> V_102 != NULL )
F_64 ( V_24 ) ;
F_57 ( V_24 ) ;
F_58 ( V_24 ) ;
}
static int F_65 ( struct V_28 * V_3 )
{
return 0 ;
}
T_1 F_66 ( void * V_110 , const struct V_29 * V_83 ,
T_1 V_18 , T_1 V_111 )
{
struct V_28 * V_3 = V_110 ;
T_1 V_42 = V_83 -> V_42 ;
if ( V_83 -> V_41 & V_38 ) {
if ( F_65 ( V_3 ) )
return V_42 ;
if ( V_42 & 0x300 )
V_42 = ( V_42 + 0x3ff ) & ~ 0x3ff ;
}
return V_42 ;
}
static int T_8 F_67 ( struct V_29 * V_27 ,
struct V_29 * V_83 )
{
struct V_29 * V_112 , * * V_113 ;
struct V_29 * * V_114 = NULL ;
for ( V_113 = & V_27 -> V_115 ; ( V_112 = * V_113 ) != NULL ; V_113 = & V_112 -> V_116 ) {
if ( V_112 -> V_44 < V_83 -> V_42 )
continue;
if ( V_83 -> V_44 < V_112 -> V_42 )
break;
if ( V_112 -> V_42 < V_83 -> V_42 || V_112 -> V_44 > V_83 -> V_44 )
return - 1 ;
if ( V_114 == NULL )
V_114 = V_113 ;
}
if ( V_114 == NULL )
return - 1 ;
V_83 -> V_27 = V_27 ;
V_83 -> V_115 = * V_114 ;
V_83 -> V_116 = * V_113 ;
* V_114 = V_83 ;
* V_113 = NULL ;
for ( V_112 = V_83 -> V_115 ; V_112 != NULL ; V_112 = V_112 -> V_116 ) {
V_112 -> V_27 = V_83 ;
F_27 ( L_29 ,
V_112 -> V_117 ,
( unsigned long long ) V_112 -> V_42 ,
( unsigned long long ) V_112 -> V_44 , V_83 -> V_117 ) ;
}
return 0 ;
}
static void F_68 ( struct V_23 * V_24 )
{
struct V_23 * V_118 ;
int V_34 ;
struct V_29 * V_83 , * V_119 ;
F_27 ( L_30 ,
F_14 ( V_24 ) , V_24 -> V_68 ) ;
F_56 (bus, res, i) {
if ( ! V_83 || ! V_83 -> V_41
|| V_83 -> V_42 > V_83 -> V_44 || V_83 -> V_27 )
continue;
if ( V_24 -> V_27 == NULL )
V_119 = ( V_83 -> V_41 & V_38 ) ?
& V_120 : & V_121 ;
else {
V_119 = F_69 ( V_24 -> V_102 , V_83 ) ;
if ( V_119 == V_83 ) {
continue;
}
}
F_27 ( L_31 ,
V_24 -> V_102 ? F_52 ( V_24 -> V_102 ) : L_28 ,
V_24 -> V_68 , V_34 ,
( unsigned long long ) V_83 -> V_42 ,
( unsigned long long ) V_83 -> V_44 ) ;
F_27 ( L_32 ,
( unsigned int ) V_83 -> V_41 ,
V_119 , ( V_119 && V_119 -> V_117 ) ? V_119 -> V_117 : L_33 ) ;
if ( V_119 && ! ( V_119 -> V_41 & V_101 ) ) {
if ( F_70 ( V_119 , V_83 ) == 0 )
continue;
if ( F_67 ( V_119 , V_83 ) == 0 )
continue;
}
F_71 ( L_34 ) ;
F_72 ( L_35 , V_34 , V_24 -> V_68 ) ;
V_83 -> V_42 = V_83 -> V_44 = 0 ;
V_83 -> V_41 = 0 ;
}
F_12 (b, &bus->children, node)
F_68 ( V_118 ) ;
}
static inline void F_73 ( struct V_28 * V_3 , int V_122 )
{
struct V_29 * V_119 , * V_123 = & V_3 -> V_29 [ V_122 ] ;
F_27 ( L_36 ,
F_52 ( V_3 ) , V_122 ,
( unsigned long long ) V_123 -> V_42 ,
( unsigned long long ) V_123 -> V_44 ,
( unsigned int ) V_123 -> V_41 ) ;
V_119 = F_69 ( V_3 , V_123 ) ;
if ( ! V_119 || ( V_119 -> V_41 & V_101 ) ||
F_70 ( V_119 , V_123 ) < 0 ) {
F_71 ( L_37 , V_122 ) ;
F_72 ( L_38 , F_52 ( V_3 ) ) ;
if ( V_119 )
F_27 ( L_39 ,
V_119 ,
( unsigned long long ) V_119 -> V_42 ,
( unsigned long long ) V_119 -> V_44 ,
( unsigned int ) V_119 -> V_41 ) ;
V_123 -> V_41 |= V_101 ;
V_123 -> V_44 -= V_123 -> V_42 ;
V_123 -> V_42 = 0 ;
}
}
static void T_8 F_74 ( int V_124 )
{
struct V_28 * V_3 = NULL ;
int V_122 , V_125 ;
V_67 V_103 ;
struct V_29 * V_123 ;
F_24 (dev) {
F_54 ( V_3 , V_104 , & V_103 ) ;
for ( V_122 = 0 ; V_122 <= V_39 ; V_122 ++ ) {
V_123 = & V_3 -> V_29 [ V_122 ] ;
if ( V_123 -> V_27 )
continue;
if ( ! V_123 -> V_41 || ( V_123 -> V_41 & V_101 ) )
continue;
if ( V_122 == V_39 )
V_125 = 1 ;
if ( V_123 -> V_41 & V_38 )
V_125 = ! ( V_103 & V_106 ) ;
else
V_125 = ! ( V_103 & V_105 ) ;
if ( V_124 == V_125 )
F_73 ( V_3 , V_122 ) ;
}
if ( V_124 )
continue;
V_123 = & V_3 -> V_29 [ V_39 ] ;
if ( V_123 -> V_41 ) {
T_6 V_126 ;
F_75 ( V_3 , V_3 -> V_127 , & V_126 ) ;
if ( V_126 & V_128 ) {
F_27 ( L_40 ,
F_52 ( V_3 ) ) ;
V_123 -> V_41 &= ~ V_129 ;
F_76 ( V_3 , V_3 -> V_127 ,
V_126 & ~ V_128 ) ;
}
}
}
}
static void T_8 F_77 ( struct V_23 * V_24 )
{
struct V_1 * V_14 = F_15 ( V_24 ) ;
T_1 V_30 ;
struct V_29 * V_83 , * V_130 ;
int V_34 ;
F_27 ( L_41 ,
F_14 ( V_24 ) ) ;
if ( ! ( V_14 -> V_15 . V_41 & V_38 ) )
goto V_131;
V_30 = ( unsigned long ) V_14 -> V_19 - V_22 ;
V_83 = F_78 ( sizeof( struct V_29 ) , V_5 ) ;
F_79 ( V_83 == NULL ) ;
V_83 -> V_117 = L_42 ;
V_83 -> V_41 = V_38 ;
V_83 -> V_42 = V_30 ;
V_83 -> V_44 = ( V_30 + 0xfff ) & 0xfffffffful ;
F_27 ( L_43 , V_83 ) ;
if ( F_70 ( & V_14 -> V_15 , V_83 ) ) {
F_27 ( L_44 ,
F_14 ( V_24 ) , V_24 -> V_68 , V_83 ) ;
F_8 ( V_83 ) ;
}
V_131:
V_30 = V_14 -> V_97 ;
F_27 ( L_45 , ( unsigned long long ) V_30 ) ;
for ( V_34 = 0 ; V_34 < 3 ; V_34 ++ ) {
V_130 = & V_14 -> V_98 [ V_34 ] ;
if ( ! ( V_130 -> V_41 & V_37 ) )
continue;
F_27 ( L_46 , V_130 ) ;
if ( ( V_130 -> V_42 - V_30 ) <= 0xa0000 &&
( V_130 -> V_44 - V_30 ) >= 0xbffff )
break;
}
if ( V_34 >= 3 )
return;
V_83 = F_78 ( sizeof( struct V_29 ) , V_5 ) ;
F_79 ( V_83 == NULL ) ;
V_83 -> V_117 = L_47 ;
V_83 -> V_41 = V_37 ;
V_83 -> V_42 = 0xa0000 + V_30 ;
V_83 -> V_44 = 0xbffff + V_30 ;
F_27 ( L_48 , V_83 ) ;
if ( F_70 ( V_130 , V_83 ) ) {
F_27 ( L_49 ,
F_14 ( V_24 ) , V_24 -> V_68 , V_83 ) ;
F_8 ( V_83 ) ;
}
}
void T_8 F_80 ( void )
{
struct V_23 * V_118 ;
F_12 (b, &pci_root_buses, node)
F_68 ( V_118 ) ;
F_74 ( 0 ) ;
F_74 ( 1 ) ;
F_12 (b, &pci_root_buses, node)
F_77 ( V_118 ) ;
F_27 ( L_50 ) ;
F_81 () ;
}
void F_82 ( struct V_23 * V_24 )
{
struct V_28 * V_3 ;
struct V_23 * V_132 ;
F_12 (dev, &bus->devices, bus_list) {
int V_34 ;
for ( V_34 = 0 ; V_34 < V_133 ; V_34 ++ ) {
struct V_29 * V_123 = & V_3 -> V_29 [ V_34 ] ;
if ( V_123 -> V_27 || ! V_123 -> V_42 || ! V_123 -> V_41 )
continue;
F_27 ( L_51 , F_52 ( V_3 ) ) ;
F_27 ( L_52 ,
V_34 , ( unsigned long long ) V_123 -> V_42 ,
( unsigned long long ) V_123 -> V_44 ,
( unsigned int ) V_123 -> V_41 ) ;
F_83 ( V_3 , V_34 ) ;
}
}
F_12 (child_bus, &bus->children, node)
F_82 ( V_132 ) ;
}
void F_84 ( struct V_23 * V_24 )
{
F_27 ( L_53 ,
F_14 ( V_24 ) , V_24 -> V_68 ) ;
F_68 ( V_24 ) ;
F_82 ( V_24 ) ;
F_85 ( V_24 ) ;
}
static void F_86 ( struct V_1 * V_14 ,
struct V_134 * V_135 )
{
unsigned long V_33 ;
struct V_29 * V_83 ;
int V_34 ;
V_83 = & V_14 -> V_15 ;
V_33 = ( unsigned long ) V_14 -> V_19 - V_95 ;
V_83 -> V_42 = ( V_83 -> V_42 + V_33 ) & 0xffffffffu ;
V_83 -> V_44 = ( V_83 -> V_44 + V_33 ) & 0xffffffffu ;
if ( ! V_83 -> V_41 ) {
F_71 ( L_54 ) ;
F_72 ( L_55 ,
V_14 -> V_11 -> V_88 , V_14 -> V_7 ) ;
V_83 -> V_42 = ( unsigned long ) V_14 -> V_19 - V_95 ;
V_83 -> V_44 = V_83 -> V_42 + V_136 ;
V_83 -> V_41 = V_38 ;
}
F_87 ( V_135 , V_83 ,
( V_137 T_1 ) ( V_14 -> V_19 - V_22 ) ) ;
F_27 ( L_56 ,
( unsigned long long ) V_83 -> V_42 ,
( unsigned long long ) V_83 -> V_44 ,
( unsigned long ) V_83 -> V_41 ) ;
for ( V_34 = 0 ; V_34 < 3 ; ++ V_34 ) {
V_83 = & V_14 -> V_98 [ V_34 ] ;
if ( ! V_83 -> V_41 ) {
if ( V_34 > 0 )
continue;
F_51 ( L_57 ) ;
F_72 ( L_58 ,
V_14 -> V_11 -> V_88 , V_14 -> V_7 ) ;
V_83 -> V_42 = V_14 -> V_97 ;
V_83 -> V_44 = ( T_1 ) - 1LL ;
V_83 -> V_41 = V_37 ;
}
F_87 ( V_135 , V_83 , V_14 -> V_97 ) ;
F_27 ( L_59 ,
V_34 , ( unsigned long long ) V_83 -> V_42 ,
( unsigned long long ) V_83 -> V_44 ,
( unsigned long ) V_83 -> V_41 ) ;
}
F_27 ( L_60 ,
( unsigned long long ) V_14 -> V_97 ) ;
F_27 ( L_61 ,
( unsigned long ) V_14 -> V_19 - V_22 ) ;
}
struct V_2 * F_88 ( struct V_23 * V_24 )
{
struct V_1 * V_14 = V_24 -> V_138 ;
return F_89 ( V_14 -> V_11 ) ;
}
static void F_90 ( struct V_1 * V_14 )
{
F_91 ( V_135 ) ;
struct V_23 * V_24 ;
struct V_2 * V_25 = V_14 -> V_11 ;
F_27 ( L_62 , F_92 ( V_25 ) ) ;
F_86 ( V_14 , & V_135 ) ;
V_24 = F_93 ( V_14 -> V_27 , V_14 -> V_139 ,
V_14 -> V_140 , V_14 , & V_135 ) ;
if ( V_24 == NULL ) {
F_51 ( L_63 ,
V_14 -> V_7 ) ;
F_94 ( & V_135 ) ;
return;
}
V_24 -> V_141 . V_42 = V_14 -> V_139 ;
V_14 -> V_24 = V_24 ;
V_14 -> V_142 = V_24 -> V_141 . V_44 ;
}
static int T_8 F_95 ( void )
{
struct V_1 * V_14 , * V_26 ;
int V_143 = 0 ;
F_44 ( L_64 ) ;
F_17 (hose, tmp, &hose_list, list_node) {
V_14 -> V_142 = 0xff ;
F_90 ( V_14 ) ;
if ( V_143 <= V_14 -> V_142 )
V_143 = V_14 -> V_142 + 1 ;
}
V_144 = V_143 ;
F_80 () ;
return 0 ;
}
static struct V_1 * F_96 ( int V_24 )
{
struct V_1 * V_14 , * V_26 ;
F_17 (hose, tmp, &hose_list, list_node)
if ( V_24 >= V_14 -> V_139 && V_24 <= V_14 -> V_142 )
return V_14 ;
return NULL ;
}
long F_97 ( long V_145 , unsigned long V_24 , unsigned long V_146 )
{
struct V_1 * V_14 ;
long V_147 = - V_148 ;
V_14 = F_96 ( V_24 ) ;
if ( ! V_14 )
return - V_149 ;
switch ( V_145 ) {
case V_150 :
return ( long ) V_14 -> V_139 ;
case V_151 :
return ( long ) V_14 -> V_97 ;
case V_152 :
return ( long ) V_14 -> V_20 ;
case V_153 :
return ( long ) V_95 ;
case V_154 :
return ( long ) V_96 ;
}
return V_147 ;
}
static int
F_98 ( struct V_23 * V_24 , unsigned int V_146 , int V_30 ,
int V_155 , T_6 * V_63 )
{
return V_156 ;
}
static int
F_99 ( struct V_23 * V_24 , unsigned int V_146 , int V_30 ,
int V_155 , T_6 V_63 )
{
return V_156 ;
}
static struct V_23 *
F_100 ( struct V_1 * V_14 , int V_157 )
{
static struct V_23 V_24 ;
if ( ! V_14 )
F_51 ( L_65 , V_157 ) ;
V_24 . V_68 = V_157 ;
V_24 . V_138 = V_14 ;
V_24 . V_140 = V_14 ? V_14 -> V_140 : & V_158 ;
return & V_24 ;
}
int F_101 ( struct V_1 * V_14 , int V_24 , int V_146 ,
int V_159 )
{
return F_102 ( F_100 ( V_14 , V_24 ) , V_146 , V_159 ) ;
}
