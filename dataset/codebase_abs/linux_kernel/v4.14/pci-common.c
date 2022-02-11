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
int F_27 ( struct V_26 * V_3 , int V_52 , struct V_53 * V_54 ,
enum V_29 V_30 , int V_55 )
{
T_1 V_28 =
( ( T_1 ) V_54 -> V_56 ) << V_50 ;
struct V_27 * V_39 ;
int V_17 ;
V_39 = F_17 ( V_3 , & V_28 , V_30 ) ;
if ( V_39 == NULL )
return - V_57 ;
V_54 -> V_56 = V_28 >> V_50 ;
V_54 -> V_58 = F_21 ( V_54 -> V_58 ) ;
V_17 = F_28 ( V_54 , V_54 -> V_59 , V_54 -> V_56 ,
V_54 -> V_60 - V_54 -> V_59 , V_54 -> V_58 ) ;
return V_17 ;
}
int F_29 ( struct V_61 * V_31 , T_5 V_62 , T_6 * V_63 , T_7 V_18 )
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
* ( ( V_66 * ) V_63 ) = F_30 ( V_64 ) ;
return 1 ;
case 2 :
if ( V_62 & 1 )
return - V_57 ;
* ( ( V_67 * ) V_63 ) = F_31 ( V_64 ) ;
return 2 ;
case 4 :
if ( V_62 & 3 )
return - V_57 ;
* ( ( T_6 * ) V_63 ) = F_32 ( V_64 ) ;
return 4 ;
}
return - V_57 ;
}
int F_33 ( struct V_61 * V_31 , T_5 V_62 , T_6 V_63 , T_7 V_18 )
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
F_34 ( V_64 , V_63 >> 24 ) ;
return 1 ;
case 2 :
if ( V_62 & 1 )
return - V_57 ;
F_35 ( V_64 , V_63 >> 16 ) ;
return 2 ;
case 4 :
if ( V_62 & 3 )
return - V_57 ;
F_36 ( V_64 , V_63 ) ;
return 4 ;
}
return - V_57 ;
}
int F_37 ( struct V_61 * V_31 ,
struct V_53 * V_54 ,
enum V_29 V_30 )
{
struct V_1 * V_14 = F_18 ( V_31 ) ;
T_1 V_28 =
( ( T_1 ) V_54 -> V_56 ) << V_50 ;
T_1 V_18 = V_54 -> V_60 - V_54 -> V_59 ;
struct V_27 * V_39 ;
F_25 ( L_2 ,
F_38 ( V_31 ) , V_31 -> V_68 ,
V_30 == V_35 ? L_3 : L_4 ,
( unsigned long long ) V_28 ,
( unsigned long long ) ( V_28 + V_18 - 1 ) ) ;
if ( V_30 == V_35 ) {
if ( ( V_28 + V_18 ) > V_14 -> V_69 ) {
#ifdef F_39
F_25 ( L_5 ,
V_70 -> V_71 , V_70 -> V_72 ) ;
F_25 ( L_6 ,
F_38 ( V_31 ) , V_31 -> V_68 ) ;
#endif
if ( V_54 -> V_73 & V_74 )
return F_40 ( V_54 ) ;
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
F_25 ( L_7 , ( unsigned long long ) V_28 ) ;
V_54 -> V_56 = V_28 >> V_50 ;
V_54 -> V_58 = F_21 ( V_54 -> V_58 ) ;
return F_28 ( V_54 , V_54 -> V_59 , V_54 -> V_56 ,
V_54 -> V_60 - V_54 -> V_59 ,
V_54 -> V_58 ) ;
}
void F_41 ( const struct V_26 * V_3 , int V_52 ,
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
V_3 , V_80 ? L_9 : L_10 ) ;
if ( F_45 ( & V_88 , V_3 ) )
return;
F_25 ( L_11 ) ;
F_46 (&parser, &range) {
F_25 ( L_12 ,
V_86 . V_89 , V_86 . V_90 ) ;
F_25 ( L_13 ,
V_86 . V_91 , V_86 . V_18 ) ;
if ( V_86 . V_91 == V_92 || V_86 . V_18 == 0 )
continue;
V_84 = NULL ;
switch ( V_86 . V_40 & V_93 ) {
case V_37 :
F_44 ( L_14 ,
V_86 . V_91 , V_86 . V_91 + V_86 . V_18 - 1 ,
V_86 . V_90 ) ;
if ( V_14 -> V_94 ) {
F_44 ( L_15 ) ;
continue;
}
if ( V_86 . V_18 > 0x01000000 )
V_86 . V_18 = 0x01000000 ;
V_14 -> V_19 = F_47 ( V_86 . V_91 ,
V_86 . V_18 ) ;
if ( V_80 )
V_95 =
( unsigned long ) V_14 -> V_19 ;
V_14 -> V_94 = V_86 . V_90 + V_86 . V_18 ;
V_14 -> V_20 = V_86 . V_91 - V_86 . V_90 ;
V_84 = & V_14 -> V_15 ;
V_86 . V_91 = V_86 . V_90 ;
break;
case V_36 :
F_44 ( L_16 ,
V_86 . V_91 , V_86 . V_91 + V_86 . V_18 - 1 ,
V_86 . V_90 ,
( V_86 . V_89 & 0x40000000 ) ?
L_17 : L_10 ) ;
if ( V_81 >= 3 ) {
F_44 ( L_15 ) ;
continue;
}
if ( V_86 . V_90 == 0 ) {
V_83 = V_86 . V_91 ;
V_82 = V_81 ;
if ( V_80 || V_96 == 0 )
V_96 = V_86 . V_91 ;
V_14 -> V_75 = V_86 . V_91 ;
V_14 -> V_69 = V_86 . V_18 ;
}
if ( V_81 == 0 ||
( V_82 >= 0 && V_86 . V_90 != 0 &&
V_14 -> V_97 == V_83 ) )
V_14 -> V_97 = V_86 . V_91 -
V_86 . V_90 ;
else if ( V_86 . V_90 != 0 &&
V_14 -> V_97 != V_86 . V_91 -
V_86 . V_90 ) {
F_44 ( L_18 ) ;
continue;
}
V_84 = & V_14 -> V_98 [ V_81 ++ ] ;
break;
}
if ( V_84 != NULL ) {
V_84 -> V_99 = V_3 -> V_100 ;
V_84 -> V_40 = V_86 . V_40 ;
V_84 -> V_41 = V_86 . V_91 ;
V_84 -> V_43 = V_86 . V_91 + V_86 . V_18 - 1 ;
V_84 -> V_25 = V_84 -> V_101 = V_84 -> V_102 = NULL ;
}
}
if ( V_82 >= 0 && V_14 -> V_97 != V_83 ) {
unsigned int V_103 = V_82 + 1 ;
F_44 ( L_19 , V_83 ) ;
if ( V_103 < V_81 )
memmove ( & V_14 -> V_98 [ V_82 ] ,
& V_14 -> V_98 [ V_103 ] ,
sizeof( struct V_27 ) * ( V_81 - V_103 ) ) ;
V_14 -> V_98 [ -- V_81 ] . V_40 = 0 ;
}
}
int F_48 ( struct V_61 * V_31 )
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
int F_52 ( struct V_26 * V_3 )
{
V_3 -> V_106 = F_53 ( V_3 , 0 , 0 ) ;
return 0 ;
}
static int T_8 F_54 ( struct V_27 * V_25 ,
struct V_27 * V_84 )
{
struct V_27 * V_107 , * * V_108 ;
struct V_27 * * V_109 = NULL ;
for ( V_108 = & V_25 -> V_101 ; ( V_107 = * V_108 ) != NULL ; V_108 = & V_107 -> V_102 ) {
if ( V_107 -> V_43 < V_84 -> V_41 )
continue;
if ( V_84 -> V_43 < V_107 -> V_41 )
break;
if ( V_107 -> V_41 < V_84 -> V_41 || V_107 -> V_43 > V_84 -> V_43 )
return - 1 ;
if ( V_109 == NULL )
V_109 = V_108 ;
}
if ( V_109 == NULL )
return - 1 ;
V_84 -> V_25 = V_25 ;
V_84 -> V_101 = * V_109 ;
V_84 -> V_102 = * V_108 ;
* V_109 = V_84 ;
* V_108 = NULL ;
for ( V_107 = V_84 -> V_101 ; V_107 != NULL ; V_107 = V_107 -> V_102 ) {
V_107 -> V_25 = V_84 ;
F_25 ( L_24 ,
V_107 -> V_99 ,
( unsigned long long ) V_107 -> V_41 ,
( unsigned long long ) V_107 -> V_43 , V_84 -> V_99 ) ;
}
return 0 ;
}
static void F_55 ( struct V_61 * V_31 )
{
struct V_61 * V_110 ;
int V_33 ;
struct V_27 * V_84 , * V_111 ;
F_25 ( L_25 ,
F_38 ( V_31 ) , V_31 -> V_68 ) ;
F_56 (bus, res, i) {
if ( ! V_84 || ! V_84 -> V_40
|| V_84 -> V_41 > V_84 -> V_43 || V_84 -> V_25 )
continue;
if ( V_31 -> V_25 == NULL )
V_111 = ( V_84 -> V_40 & V_37 ) ?
& V_112 : & V_113 ;
else {
V_111 = F_57 ( V_31 -> V_114 , V_84 ) ;
if ( V_111 == V_84 ) {
continue;
}
}
F_25 ( L_26 ,
V_31 -> V_114 ? F_51 ( V_31 -> V_114 ) : L_27 ,
V_31 -> V_68 , V_33 ,
( unsigned long long ) V_84 -> V_41 ,
( unsigned long long ) V_84 -> V_43 ) ;
F_25 ( L_28 ,
( unsigned int ) V_84 -> V_40 ,
V_111 , ( V_111 && V_111 -> V_99 ) ? V_111 -> V_99 : L_29 ) ;
if ( V_111 && ! ( V_111 -> V_40 & V_105 ) ) {
struct V_26 * V_3 = V_31 -> V_114 ;
if ( F_58 ( V_111 , V_84 ) == 0 )
continue;
if ( F_54 ( V_111 , V_84 ) == 0 )
continue;
if ( V_3 && V_33 < V_115 &&
F_59 ( V_3 ,
V_33 + V_116 ) == 0 )
continue;
}
F_60 ( L_30 ) ;
F_61 ( L_31 , V_33 , V_31 -> V_68 ) ;
V_84 -> V_41 = V_84 -> V_43 = 0 ;
V_84 -> V_40 = 0 ;
}
F_12 (b, &bus->children, node)
F_55 ( V_110 ) ;
}
static inline void F_62 ( struct V_26 * V_3 , int V_117 )
{
struct V_27 * V_111 , * V_118 = & V_3 -> V_27 [ V_117 ] ;
F_25 ( L_32 ,
F_51 ( V_3 ) , V_117 ,
( unsigned long long ) V_118 -> V_41 ,
( unsigned long long ) V_118 -> V_43 ,
( unsigned int ) V_118 -> V_40 ) ;
V_111 = F_57 ( V_3 , V_118 ) ;
if ( ! V_111 || ( V_111 -> V_40 & V_105 ) ||
F_58 ( V_111 , V_118 ) < 0 ) {
F_60 ( L_33 , V_117 ) ;
F_61 ( L_34 , F_51 ( V_3 ) ) ;
if ( V_111 )
F_25 ( L_35 ,
V_111 ,
( unsigned long long ) V_111 -> V_41 ,
( unsigned long long ) V_111 -> V_43 ,
( unsigned int ) V_111 -> V_40 ) ;
V_118 -> V_40 |= V_105 ;
V_118 -> V_43 -= V_118 -> V_41 ;
V_118 -> V_41 = 0 ;
}
}
static void T_8 F_63 ( int V_119 )
{
struct V_26 * V_3 = NULL ;
int V_117 , V_120 ;
V_67 V_121 ;
struct V_27 * V_118 ;
F_22 (dev) {
F_64 ( V_3 , V_122 , & V_121 ) ;
for ( V_117 = 0 ; V_117 <= V_38 ; V_117 ++ ) {
V_118 = & V_3 -> V_27 [ V_117 ] ;
if ( V_118 -> V_25 )
continue;
if ( ! V_118 -> V_40 || ( V_118 -> V_40 & V_105 ) )
continue;
if ( V_117 == V_38 )
V_120 = 1 ;
if ( V_118 -> V_40 & V_37 )
V_120 = ! ( V_121 & V_123 ) ;
else
V_120 = ! ( V_121 & V_124 ) ;
if ( V_119 == V_120 )
F_62 ( V_3 , V_117 ) ;
}
if ( V_119 )
continue;
V_118 = & V_3 -> V_27 [ V_38 ] ;
if ( V_118 -> V_40 ) {
T_6 V_125 ;
F_65 ( V_3 , V_3 -> V_126 , & V_125 ) ;
if ( V_125 & V_127 ) {
F_25 ( L_36 ,
F_51 ( V_3 ) ) ;
V_118 -> V_40 &= ~ V_128 ;
F_66 ( V_3 , V_3 -> V_126 ,
V_125 & ~ V_127 ) ;
}
}
}
}
static void T_8 F_67 ( struct V_61 * V_31 )
{
struct V_1 * V_14 = F_18 ( V_31 ) ;
T_1 V_28 ;
struct V_27 * V_84 , * V_129 ;
int V_33 ;
F_25 ( L_37 ,
F_38 ( V_31 ) ) ;
if ( ! ( V_14 -> V_15 . V_40 & V_37 ) )
goto V_130;
V_28 = ( unsigned long ) V_14 -> V_19 - V_22 ;
V_84 = F_68 ( sizeof( struct V_27 ) , V_5 ) ;
F_69 ( V_84 == NULL ) ;
V_84 -> V_99 = L_38 ;
V_84 -> V_40 = V_37 ;
V_84 -> V_41 = V_28 ;
V_84 -> V_43 = ( V_28 + 0xfff ) & 0xfffffffful ;
F_25 ( L_39 , V_84 ) ;
if ( F_58 ( & V_14 -> V_15 , V_84 ) ) {
F_25 ( L_40 ,
F_38 ( V_31 ) , V_31 -> V_68 , V_84 ) ;
F_8 ( V_84 ) ;
}
V_130:
V_28 = V_14 -> V_97 ;
F_25 ( L_41 , ( unsigned long long ) V_28 ) ;
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
V_129 = & V_14 -> V_98 [ V_33 ] ;
if ( ! ( V_129 -> V_40 & V_36 ) )
continue;
F_25 ( L_42 , V_129 ) ;
if ( ( V_129 -> V_41 - V_28 ) <= 0xa0000 &&
( V_129 -> V_43 - V_28 ) >= 0xbffff )
break;
}
if ( V_33 >= 3 )
return;
V_84 = F_68 ( sizeof( struct V_27 ) , V_5 ) ;
F_69 ( V_84 == NULL ) ;
V_84 -> V_99 = L_43 ;
V_84 -> V_40 = V_36 ;
V_84 -> V_41 = 0xa0000 + V_28 ;
V_84 -> V_43 = 0xbffff + V_28 ;
F_25 ( L_44 , V_84 ) ;
if ( F_58 ( V_129 , V_84 ) ) {
F_25 ( L_45 ,
F_38 ( V_31 ) , V_31 -> V_68 , V_84 ) ;
F_8 ( V_84 ) ;
}
}
void T_8 F_70 ( void )
{
struct V_61 * V_110 ;
F_12 (b, &pci_root_buses, node)
F_55 ( V_110 ) ;
F_63 ( 0 ) ;
F_63 ( 1 ) ;
F_12 (b, &pci_root_buses, node)
F_67 ( V_110 ) ;
F_25 ( L_46 ) ;
F_71 () ;
}
void F_72 ( struct V_61 * V_31 )
{
struct V_26 * V_3 ;
struct V_61 * V_131 ;
F_12 (dev, &bus->devices, bus_list) {
int V_33 ;
for ( V_33 = 0 ; V_33 < V_132 ; V_33 ++ ) {
struct V_27 * V_118 = & V_3 -> V_27 [ V_33 ] ;
if ( V_118 -> V_25 || ! V_118 -> V_41 || ! V_118 -> V_40 )
continue;
F_25 ( L_47 , F_51 ( V_3 ) ) ;
F_25 ( L_48 ,
V_33 , ( unsigned long long ) V_118 -> V_41 ,
( unsigned long long ) V_118 -> V_43 ,
( unsigned int ) V_118 -> V_40 ) ;
if ( F_73 ( V_3 , V_33 ) == 0 )
continue;
F_59 ( V_3 , V_33 ) ;
}
}
F_12 (child_bus, &bus->children, node)
F_72 ( V_131 ) ;
}
void F_74 ( struct V_61 * V_31 )
{
F_25 ( L_49 ,
F_38 ( V_31 ) , V_31 -> V_68 ) ;
F_55 ( V_31 ) ;
F_72 ( V_31 ) ;
F_75 ( V_31 ) ;
}
static void F_76 ( struct V_1 * V_14 ,
struct V_133 * V_134 )
{
unsigned long V_32 ;
struct V_27 * V_84 ;
int V_33 ;
V_84 = & V_14 -> V_15 ;
V_32 = ( unsigned long ) V_14 -> V_19 - V_95 ;
V_84 -> V_41 = ( V_84 -> V_41 + V_32 ) & 0xffffffffu ;
V_84 -> V_43 = ( V_84 -> V_43 + V_32 ) & 0xffffffffu ;
if ( ! V_84 -> V_40 ) {
F_60 ( L_50 ) ;
F_61 ( L_51 ,
V_14 -> V_11 , V_14 -> V_7 ) ;
V_84 -> V_41 = ( unsigned long ) V_14 -> V_19 - V_95 ;
V_84 -> V_43 = V_84 -> V_41 + V_135 ;
V_84 -> V_40 = V_37 ;
}
F_77 ( V_134 , V_84 ,
( V_136 T_1 ) ( V_14 -> V_19 - V_22 ) ) ;
F_25 ( L_52 ,
( unsigned long long ) V_84 -> V_41 ,
( unsigned long long ) V_84 -> V_43 ,
( unsigned long ) V_84 -> V_40 ) ;
for ( V_33 = 0 ; V_33 < 3 ; ++ V_33 ) {
V_84 = & V_14 -> V_98 [ V_33 ] ;
if ( ! V_84 -> V_40 ) {
if ( V_33 > 0 )
continue;
F_50 ( L_53 ) ;
F_61 ( L_54 ,
V_14 -> V_11 , V_14 -> V_7 ) ;
V_84 -> V_41 = V_14 -> V_97 ;
V_84 -> V_43 = ( T_1 ) - 1LL ;
V_84 -> V_40 = V_36 ;
}
F_77 ( V_134 , V_84 , V_14 -> V_97 ) ;
F_25 ( L_55 ,
V_33 , ( unsigned long long ) V_84 -> V_41 ,
( unsigned long long ) V_84 -> V_43 ,
( unsigned long ) V_84 -> V_40 ) ;
}
F_25 ( L_56 ,
( unsigned long long ) V_14 -> V_97 ) ;
F_25 ( L_57 ,
( unsigned long ) V_14 -> V_19 - V_22 ) ;
}
static void F_78 ( struct V_1 * V_14 )
{
F_79 ( V_134 ) ;
struct V_61 * V_31 ;
struct V_2 * V_23 = V_14 -> V_11 ;
F_25 ( L_58 , V_23 ) ;
F_76 ( V_14 , & V_134 ) ;
V_31 = F_80 ( V_14 -> V_25 , V_14 -> V_137 ,
V_14 -> V_138 , V_14 , & V_134 ) ;
if ( V_31 == NULL ) {
F_50 ( L_59 ,
V_14 -> V_7 ) ;
F_81 ( & V_134 ) ;
return;
}
V_31 -> V_139 . V_41 = V_14 -> V_137 ;
V_14 -> V_31 = V_31 ;
V_14 -> V_140 = V_31 -> V_139 . V_43 ;
}
static int T_8 F_82 ( void )
{
struct V_1 * V_14 , * V_24 ;
int V_141 = 0 ;
F_44 ( L_60 ) ;
F_15 (hose, tmp, &hose_list, list_node) {
V_14 -> V_140 = 0xff ;
F_78 ( V_14 ) ;
if ( V_141 <= V_14 -> V_140 )
V_141 = V_14 -> V_140 + 1 ;
}
V_142 = V_141 ;
F_70 () ;
F_15 (hose, tmp, &hose_list, list_node) {
if ( V_14 -> V_31 )
F_75 ( V_14 -> V_31 ) ;
}
return 0 ;
}
static struct V_1 * F_83 ( int V_31 )
{
struct V_1 * V_14 , * V_24 ;
F_15 (hose, tmp, &hose_list, list_node)
if ( V_31 >= V_14 -> V_137 && V_31 <= V_14 -> V_140 )
return V_14 ;
return NULL ;
}
long F_84 ( long V_143 , unsigned long V_31 , unsigned long V_144 )
{
struct V_1 * V_14 ;
long V_145 = - V_146 ;
V_14 = F_83 ( V_31 ) ;
if ( ! V_14 )
return - V_147 ;
switch ( V_143 ) {
case V_148 :
return ( long ) V_14 -> V_137 ;
case V_149 :
return ( long ) V_14 -> V_97 ;
case V_150 :
return ( long ) V_14 -> V_20 ;
case V_151 :
return ( long ) V_95 ;
case V_152 :
return ( long ) V_96 ;
}
return V_145 ;
}
static int
F_85 ( struct V_61 * V_31 , unsigned int V_144 , int V_28 ,
int V_153 , T_6 * V_63 )
{
return V_154 ;
}
static int
F_86 ( struct V_61 * V_31 , unsigned int V_144 , int V_28 ,
int V_153 , T_6 V_63 )
{
return V_154 ;
}
static struct V_61 *
F_87 ( struct V_1 * V_14 , int V_155 )
{
static struct V_61 V_31 ;
if ( ! V_14 )
F_50 ( L_61 , V_155 ) ;
V_31 . V_68 = V_155 ;
V_31 . V_156 = V_14 ;
V_31 . V_138 = V_14 ? V_14 -> V_138 : & V_157 ;
return & V_31 ;
}
int F_88 ( struct V_1 * V_14 , int V_31 , int V_144 ,
int V_158 )
{
return F_89 ( F_87 ( V_14 , V_31 ) , V_144 , V_158 ) ;
}
