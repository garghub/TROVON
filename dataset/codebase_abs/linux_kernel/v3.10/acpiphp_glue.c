static T_1
F_1 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
int * V_5 = ( int * ) V_3 ;
if ( F_2 ( V_1 ) ) {
( * V_5 ) ++ ;
return V_6 ;
} else {
return V_7 ;
}
}
static inline void F_3 ( struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_10 ) ;
}
static inline void F_5 ( struct V_8 * V_9 )
{
F_6 ( & V_9 -> V_10 , V_11 ) ;
}
static void V_11 ( struct V_12 * V_12 )
{
struct V_8 * V_9 ;
struct V_13 * V_14 , * V_15 ;
struct V_16 * V_17 , * V_18 ;
V_9 = F_7 ( V_12 , struct V_8 , V_10 ) ;
F_8 (slot, next, &bridge->slots, node) {
F_8 (func, tmp, &slot->funcs, sibling) {
F_9 ( V_17 ) ;
}
F_9 ( V_14 ) ;
}
if ( ( V_9 -> V_19 & V_20 ) && V_9 -> V_17 )
F_5 ( V_9 -> V_17 -> V_14 -> V_9 ) ;
F_10 ( & V_9 -> V_21 -> V_22 ) ;
F_11 ( V_9 -> V_23 ) ;
F_9 ( V_9 ) ;
}
static int F_12 ( struct V_24 * V_25 , unsigned long V_26 ,
void * V_27 )
{
struct V_16 * V_17 = F_7 ( V_25 , struct V_16 , V_25 ) ;
struct V_21 * V_28 = V_17 -> V_14 -> V_9 -> V_21 ;
T_3 V_29 ;
if ( ! V_28 -> V_30 )
return V_31 ;
F_13 ( V_28 -> V_30 ,
V_32 ,
& V_29 ) ;
if ( ( ( V_29 >> 8 ) & 0xff ) != V_28 -> V_33 . V_34 ) {
V_29 = ( V_29 & 0xff000000 )
| ( ( unsigned int ) ( V_28 -> V_35 ) << 0 )
| ( ( unsigned int ) ( V_28 -> V_33 . V_34 ) << 8 )
| ( ( unsigned int ) ( V_28 -> V_33 . V_36 ) << 16 ) ;
F_14 ( V_28 -> V_30 , V_32 , V_29 ) ;
}
return V_31 ;
}
static bool F_15 ( struct V_23 * V_37 )
{
T_3 V_38 ;
T_2 V_18 ;
struct V_39 * V_40 ;
if ( F_16 ( V_37 , V_41 , & V_38 ) )
return false ;
if ( ! ( V_38 & V_42 ) )
return false ;
V_18 = F_17 ( V_37 ) ;
if ( ! V_18 )
return false ;
V_40 = F_18 ( V_18 ) ;
if ( ! V_40 )
return false ;
if ( ! ( V_40 -> V_43 & V_44 ) )
return false ;
return true ;
}
static void F_19 ( void * V_45 )
{
struct V_16 * V_17 = V_45 ;
F_3 ( V_17 -> V_14 -> V_9 ) ;
}
static void F_20 ( void * V_45 )
{
struct V_16 * V_17 = V_45 ;
F_5 ( V_17 -> V_14 -> V_9 ) ;
}
static T_1
F_21 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_8 * V_9 = (struct V_8 * ) V_3 ;
struct V_13 * V_14 ;
struct V_16 * V_46 ;
T_2 V_18 ;
T_1 V_47 = V_7 ;
unsigned long long V_48 , V_49 ;
int V_50 , V_51 , V_52 , V_53 = 0 ;
struct V_21 * V_54 = V_9 -> V_21 ;
struct V_23 * V_37 ;
T_3 V_26 ;
if ( ! F_22 ( V_54 , V_1 ) && ! F_2 ( V_1 ) )
return V_7 ;
V_47 = F_23 ( V_1 , L_1 , NULL , & V_48 ) ;
if ( F_24 ( V_47 ) ) {
F_25 ( L_2 , V_47 ) ;
return V_7 ;
}
V_50 = ( V_48 >> 16 ) & 0xffff ;
V_51 = V_48 & 0xffff ;
V_37 = V_9 -> V_23 ;
if ( V_37 && F_15 ( V_37 ) )
return V_7 ;
V_46 = F_26 ( sizeof( struct V_16 ) , V_55 ) ;
if ( ! V_46 )
return V_56 ;
V_46 -> V_1 = V_1 ;
V_46 -> V_51 = V_51 ;
if ( F_27 ( F_28 ( V_1 , L_3 , & V_18 ) ) )
V_46 -> V_19 = V_57 ;
if ( F_27 ( F_28 ( V_1 , L_4 , & V_18 ) ) )
V_46 -> V_19 |= V_58 ;
if ( F_27 ( F_28 ( V_1 , L_5 , & V_18 ) ) )
V_46 -> V_19 |= V_59 ;
if ( F_27 ( F_28 ( V_1 , L_6 , & V_18 ) ) )
V_46 -> V_19 |= V_60 ;
if ( F_27 ( F_28 ( V_1 , L_7 , & V_18 ) ) )
V_46 -> V_19 |= V_61 ;
V_47 = F_23 ( V_1 , L_8 , NULL , & V_49 ) ;
if ( F_24 ( V_47 ) ) {
V_49 = V_9 -> V_62 + 1 ;
}
F_29 (slot, &bridge->slots, node)
if ( V_14 -> V_50 == V_50 ) {
if ( V_14 -> V_49 != V_49 )
F_25 ( L_9 ) ;
V_53 = 1 ;
break;
}
if ( ! V_53 ) {
V_14 = F_26 ( sizeof( struct V_13 ) , V_55 ) ;
if ( ! V_14 ) {
F_9 ( V_46 ) ;
return V_56 ;
}
V_14 -> V_9 = V_9 ;
V_14 -> V_50 = V_50 ;
V_14 -> V_49 = V_49 ;
F_30 ( & V_14 -> V_63 ) ;
F_31 ( & V_14 -> V_64 ) ;
F_32 ( & V_65 ) ;
F_33 ( & V_14 -> V_66 , & V_9 -> V_67 ) ;
F_34 ( & V_65 ) ;
V_9 -> V_62 ++ ;
F_35 ( L_10 ,
V_14 -> V_49 , F_36 ( V_54 ) , V_54 -> V_68 , V_50 ) ;
V_52 = F_37 ( V_14 ) ;
if ( V_52 ) {
if ( V_52 == - V_69 )
F_25 ( L_11
L_12 , V_14 -> V_49 ) ;
else
F_25 ( L_13
L_14 , V_52 ) ;
goto V_70;
}
}
V_46 -> V_14 = V_14 ;
F_32 ( & V_65 ) ;
F_33 ( & V_46 -> V_71 , & V_14 -> V_63 ) ;
F_34 ( & V_65 ) ;
if ( F_38 ( V_54 , F_39 ( V_50 , V_51 ) ,
& V_26 , 60 * 1000 ) )
V_14 -> V_19 |= ( V_72 | V_73 ) ;
if ( F_2 ( V_1 ) ) {
V_46 -> V_19 &= ~ V_57 ;
if ( F_40 ( V_1 ,
& V_74 , V_46 ,
F_19 , F_20 ) )
F_35 ( L_15 ) ;
V_46 -> V_25 . V_75 = F_12 ;
if ( F_41 ( & V_46 -> V_25 ) )
F_35 ( L_16 ) ;
}
if ( ! ( V_46 -> V_19 & V_61 ) ) {
V_47 = F_42 ( V_1 ,
V_76 ,
V_77 ,
V_46 ) ;
if ( F_24 ( V_47 ) )
F_43 ( L_17 ) ;
} else
V_47 = V_7 ;
return V_47 ;
V_70:
V_9 -> V_62 -- ;
F_32 ( & V_65 ) ;
F_44 ( & V_14 -> V_66 ) ;
F_34 ( & V_65 ) ;
F_9 ( V_14 ) ;
F_9 ( V_46 ) ;
return V_7 ;
}
static int F_45 ( T_2 V_1 )
{
int V_53 = F_46 ( V_1 ) ;
if ( ! V_53 ) {
F_47 ( V_78 , V_1 , ( T_3 ) 1 ,
F_1 , NULL , ( void * ) & V_53 , NULL ) ;
}
return V_53 ;
}
static void F_48 ( struct V_8 * V_9 )
{
T_1 V_47 ;
F_32 ( & V_65 ) ;
F_49 ( & V_9 -> V_79 , & V_80 ) ;
F_34 ( & V_65 ) ;
V_47 = F_47 ( V_78 , V_9 -> V_1 , ( T_3 ) 1 ,
F_21 , NULL , V_9 , NULL ) ;
if ( F_24 ( V_47 ) ) {
F_32 ( & V_65 ) ;
F_44 ( & V_9 -> V_79 ) ;
F_34 ( & V_65 ) ;
return;
}
if ( ! F_50 ( V_9 -> V_21 ) ) {
if ( ( V_9 -> V_19 & V_20 ) && V_9 -> V_17 ) {
V_47 = F_51 ( V_9 -> V_17 -> V_1 ,
V_76 ,
V_77 ) ;
if ( F_24 ( V_47 ) )
F_43 ( L_18 ) ;
}
V_47 = F_42 ( V_9 -> V_1 ,
V_76 ,
V_81 ,
V_9 ) ;
if ( F_24 ( V_47 ) ) {
F_43 ( L_17 ) ;
}
}
}
static struct V_16 * F_52 ( T_2 V_1 )
{
struct V_8 * V_9 ;
struct V_13 * V_14 ;
struct V_16 * V_17 = NULL ;
F_32 ( & V_65 ) ;
F_29 (bridge, &bridge_list, list) {
F_29 (slot, &bridge->slots, node) {
F_29 (func, &slot->funcs, sibling) {
if ( V_17 -> V_1 == V_1 ) {
F_3 ( V_17 -> V_14 -> V_9 ) ;
F_34 ( & V_65 ) ;
return V_17 ;
}
}
}
}
F_34 ( & V_65 ) ;
return NULL ;
}
static struct V_8 * F_53 ( T_2 V_1 )
{
struct V_8 * V_9 ;
F_32 ( & V_65 ) ;
F_29 (bridge, &bridge_list, list)
if ( V_9 -> V_1 == V_1 ) {
F_3 ( V_9 ) ;
F_34 ( & V_65 ) ;
return V_9 ;
}
F_34 ( & V_65 ) ;
return NULL ;
}
static void F_54 ( struct V_8 * V_9 )
{
struct V_13 * V_14 ;
struct V_16 * V_17 ;
T_1 V_47 ;
T_2 V_1 = V_9 -> V_1 ;
if ( ! F_50 ( V_9 -> V_21 ) ) {
V_47 = F_51 ( V_1 ,
V_76 ,
V_81 ) ;
if ( F_24 ( V_47 ) )
F_43 ( L_18 ) ;
}
if ( ( V_9 -> V_19 & V_20 ) && V_9 -> V_17 ) {
V_47 = F_42 ( V_9 -> V_17 -> V_1 ,
V_76 ,
V_77 ,
V_9 -> V_17 ) ;
if ( F_24 ( V_47 ) )
F_43 ( L_19 ) ;
}
F_29 (slot, &bridge->slots, node) {
F_29 (func, &slot->funcs, sibling) {
if ( F_2 ( V_17 -> V_1 ) ) {
F_55 ( V_17 -> V_1 ) ;
F_56 ( & V_17 -> V_25 ) ;
}
if ( ! ( V_17 -> V_19 & V_61 ) ) {
V_47 = F_51 ( V_17 -> V_1 ,
V_76 ,
V_77 ) ;
if ( F_24 ( V_47 ) )
F_43 ( L_18 ) ;
}
}
F_57 ( V_14 ) ;
}
F_32 ( & V_65 ) ;
F_44 ( & V_9 -> V_79 ) ;
F_34 ( & V_65 ) ;
}
static int F_58 ( struct V_13 * V_14 )
{
T_1 V_47 ;
struct V_16 * V_17 ;
int V_52 = 0 ;
if ( V_14 -> V_19 & V_73 )
goto V_70;
F_29 (func, &slot->funcs, sibling) {
if ( V_17 -> V_19 & V_59 ) {
F_35 ( L_20 , V_82 ) ;
V_47 = F_59 ( V_17 -> V_1 , L_5 , NULL , NULL ) ;
if ( F_24 ( V_47 ) ) {
F_25 ( L_21 , V_82 ) ;
V_52 = - 1 ;
goto V_70;
} else
break;
}
}
V_14 -> V_19 |= V_73 ;
V_70:
return V_52 ;
}
static int F_60 ( struct V_13 * V_14 )
{
T_1 V_47 ;
struct V_16 * V_17 ;
int V_52 = 0 ;
if ( ( V_14 -> V_19 & V_73 ) == 0 )
goto V_70;
F_29 (func, &slot->funcs, sibling) {
if ( V_17 -> V_19 & V_60 ) {
V_47 = F_59 ( V_17 -> V_1 , L_6 , NULL , NULL ) ;
if ( F_24 ( V_47 ) ) {
F_25 ( L_22 , V_82 ) ;
V_52 = - 1 ;
goto V_70;
} else
break;
}
}
V_14 -> V_19 &= ( ~ V_73 ) ;
V_70:
return V_52 ;
}
static unsigned char F_61 ( struct V_21 * V_28 )
{
struct V_83 * V_18 ;
unsigned char V_84 , V_85 ;
V_84 = V_28 -> V_33 . V_34 ;
F_62 (tmp, &bus->children) {
V_85 = F_63 ( F_64 ( V_18 ) ) ;
if ( V_85 > V_84 )
V_84 = V_85 ;
}
return V_84 ;
}
static int F_65 ( struct V_16 * V_17 )
{
struct V_86 * V_50 ;
int V_87 ;
if ( ! F_66 ( V_17 -> V_1 , & V_50 ) ) {
F_35 ( L_23 ) ;
F_67 ( V_50 ) ;
}
V_87 = F_68 ( V_17 -> V_1 ) ;
if ( ! V_87 )
V_87 = F_66 ( V_17 -> V_1 , & V_50 ) ;
if ( V_87 )
F_35 ( L_24 , - V_87 ) ;
return V_87 ;
}
static int F_69 ( T_2 V_1 )
{
struct V_86 * V_50 ;
int V_52 ;
V_52 = F_66 ( V_1 , & V_50 ) ;
if ( V_52 ) {
F_35 ( L_25 ) ;
return V_52 ;
}
F_67 ( V_50 ) ;
return 0 ;
}
static void F_70 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
union V_88 V_89 [ 2 ] ;
struct V_90 V_91 ;
F_29 (func, &slot->funcs, sibling) {
V_91 . V_5 = 2 ;
V_91 . V_92 = V_89 ;
V_89 [ 0 ] . type = V_93 ;
V_89 [ 0 ] . integer . V_94 = V_95 ;
V_89 [ 1 ] . type = V_93 ;
V_89 [ 1 ] . integer . V_94 = 1 ;
F_59 ( V_17 -> V_1 , L_26 , & V_91 , NULL ) ;
}
}
static void F_71 ( struct V_13 * V_14 , struct V_23 * V_22 )
{
struct V_16 * V_17 ;
if ( ! V_22 -> V_96 )
return;
if ( V_22 -> V_97 )
return;
if ( F_72 ( V_22 -> V_98 ) != V_14 -> V_50 )
return;
F_29 (func, &slot->funcs, sibling) {
if ( F_73 ( V_22 -> V_98 ) == V_17 -> V_51 ) {
if ( ( F_45 ( V_17 -> V_1 ) > 0 ) )
V_22 -> V_97 = 1 ;
break;
}
}
}
static int T_4 F_74 ( struct V_13 * V_14 )
{
struct V_23 * V_22 ;
struct V_21 * V_28 = V_14 -> V_9 -> V_21 ;
struct V_16 * V_17 ;
int V_99 , V_84 , V_100 ;
F_75 ( V_101 ) ;
if ( V_14 -> V_19 & V_72 )
goto V_70;
F_29 (func, &slot->funcs, sibling)
F_65 ( V_17 ) ;
V_99 = F_76 ( V_28 , F_39 ( V_14 -> V_50 , 0 ) ) ;
if ( V_99 == 0 ) {
F_35 ( L_27 ) ;
goto V_70;
}
V_84 = F_61 ( V_28 ) ;
for ( V_100 = 0 ; V_100 < 2 ; V_100 ++ ) {
F_29 (dev, &bus->devices, bus_list) {
if ( F_72 ( V_22 -> V_98 ) != V_14 -> V_50 )
continue;
if ( V_22 -> V_102 == V_103 ||
V_22 -> V_102 == V_104 ) {
V_84 = F_77 ( V_28 , V_22 , V_84 , V_100 ) ;
if ( V_100 && V_22 -> V_96 ) {
F_71 ( V_14 , V_22 ) ;
F_78 ( V_22 -> V_96 ) ;
F_79 ( V_22 -> V_96 ,
& V_101 ) ;
}
}
}
}
F_80 ( V_28 , & V_101 , NULL ) ;
F_81 ( V_28 ) ;
F_82 ( V_28 ) ;
F_70 ( V_14 ) ;
F_83 ( V_28 ) ;
F_29 (dev, &bus->devices, bus_list) {
if ( ! V_22 -> V_105 )
V_22 -> V_106 = V_107 ;
}
F_84 ( V_28 ) ;
V_14 -> V_19 |= V_72 ;
F_29 (func, &slot->funcs, sibling) {
V_22 = F_85 ( V_28 , F_39 ( V_14 -> V_50 ,
V_17 -> V_51 ) ) ;
if ( ! V_22 ) {
V_14 -> V_19 &= ( ~ V_72 ) ;
continue;
}
}
V_70:
return 0 ;
}
static struct V_23 * F_86 ( struct V_13 * V_14 )
{
struct V_21 * V_28 = V_14 -> V_9 -> V_21 ;
struct V_23 * V_22 ;
struct V_23 * V_108 = NULL ;
F_87 ( & V_109 ) ;
F_29 (dev, &bus->devices, bus_list)
if ( F_72 ( V_22 -> V_98 ) == V_14 -> V_50 ) {
V_108 = F_88 ( V_22 ) ;
break;
}
F_89 ( & V_109 ) ;
return V_108 ;
}
static int F_90 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
struct V_23 * V_37 ;
while ( ( V_37 = F_86 ( V_14 ) ) ) {
F_91 ( V_37 ) ;
F_11 ( V_37 ) ;
}
F_29 (func, &slot->funcs, sibling) {
F_69 ( V_17 -> V_1 ) ;
}
V_14 -> V_19 &= ( ~ V_72 ) ;
return 0 ;
}
static unsigned int F_92 ( struct V_13 * V_14 )
{
T_1 V_47 ;
unsigned long long V_110 = 0 ;
T_3 V_111 ;
struct V_16 * V_17 ;
F_29 (func, &slot->funcs, sibling) {
if ( V_17 -> V_19 & V_58 ) {
V_47 = F_23 ( V_17 -> V_1 , L_4 , NULL , & V_110 ) ;
if ( F_27 ( V_47 ) && V_110 )
break;
} else {
F_93 ( V_14 -> V_9 -> V_21 ,
F_39 ( V_14 -> V_50 ,
V_17 -> V_51 ) ,
V_112 , & V_111 ) ;
if ( V_111 != 0xffffffff ) {
V_110 = V_113 ;
break;
}
}
}
return ( unsigned int ) V_110 ;
}
int F_94 ( struct V_13 * V_14 )
{
T_1 V_47 ;
struct V_16 * V_17 ;
struct V_90 V_91 ;
union V_88 V_114 ;
F_29 (func, &slot->funcs, sibling) {
if ( ( V_17 -> V_19 & V_57 ) ) {
V_91 . V_5 = 1 ;
V_91 . V_92 = & V_114 ;
V_114 . type = V_93 ;
V_114 . integer . V_94 = 1 ;
V_47 = F_59 ( V_17 -> V_1 , L_3 , & V_91 , NULL ) ;
if ( F_24 ( V_47 ) ) {
F_25 ( L_28 , V_82 ) ;
return - 1 ;
} else
break;
}
}
return 0 ;
}
static int F_95 ( struct V_8 * V_9 )
{
struct V_13 * V_14 ;
int V_52 = 0 ;
int V_115 , V_116 ;
V_115 = V_116 = 0 ;
F_29 (slot, &bridge->slots, node) {
unsigned int V_47 = F_92 ( V_14 ) ;
if ( V_14 -> V_19 & V_72 ) {
if ( V_47 == V_113 )
continue;
V_52 = F_96 ( V_14 ) ;
if ( V_52 ) {
F_43 ( L_29 ) ;
goto V_70;
} else {
F_94 ( V_14 ) ;
}
V_116 ++ ;
} else {
if ( V_47 != V_113 )
continue;
V_52 = F_97 ( V_14 ) ;
if ( V_52 ) {
F_43 ( L_30 ) ;
goto V_70;
}
V_115 ++ ;
}
}
F_35 ( L_31 , V_82 , V_115 , V_116 ) ;
V_70:
return V_52 ;
}
static void F_82 ( struct V_21 * V_28 )
{
struct V_23 * V_22 ;
F_29 (dev, &bus->devices, bus_list)
F_98 ( V_22 ) ;
}
static void F_81 ( struct V_21 * V_28 )
{
struct V_23 * V_22 , * V_18 ;
int V_117 ;
unsigned long V_118 = V_119 | V_120 ;
F_8 (dev, tmp, &bus->devices, bus_list) {
for ( V_117 = 0 ; V_117 < V_121 ; V_117 ++ ) {
struct V_122 * V_123 = & V_22 -> V_122 [ V_117 ] ;
if ( ( V_123 -> V_19 & V_118 ) && ! V_123 -> V_34 &&
V_123 -> V_36 ) {
F_91 ( V_22 ) ;
break;
}
}
}
}
static T_1
F_99 ( T_2 V_1 , T_3 V_2 , void * V_3 , void * * V_4 )
{
struct V_8 * V_9 ;
char V_124 [ 64 ] ;
struct V_125 V_126 = { . V_127 = sizeof( V_124 ) ,
. V_92 = V_124 } ;
V_9 = F_53 ( V_1 ) ;
if ( V_9 ) {
F_100 ( V_1 , V_128 , & V_126 ) ;
F_35 ( L_32 ,
V_82 , V_124 ) ;
F_95 ( V_9 ) ;
F_5 ( V_9 ) ;
}
return V_7 ;
}
void F_101 ( T_2 V_1 )
{
struct V_8 * V_9 ;
V_9 = F_53 ( V_1 ) ;
if ( V_9 ) {
F_95 ( V_9 ) ;
F_5 ( V_9 ) ;
}
F_47 ( V_78 , V_1 ,
V_129 , F_99 , NULL , NULL , NULL ) ;
}
static void F_102 ( struct V_130 * V_131 )
{
struct V_8 * V_9 ;
char V_124 [ 64 ] ;
struct V_125 V_126 = { . V_127 = sizeof( V_124 ) ,
. V_92 = V_124 } ;
struct V_132 * V_133 ;
T_2 V_1 ;
T_3 type ;
V_133 = F_7 ( V_131 , struct V_132 , V_131 ) ;
V_1 = V_133 -> V_1 ;
type = V_133 -> type ;
V_9 = (struct V_8 * ) V_133 -> V_3 ;
F_103 () ;
F_100 ( V_1 , V_128 , & V_126 ) ;
switch ( type ) {
case V_134 :
F_35 ( L_33 , V_82 , V_124 ) ;
F_35 ( L_32 , V_82 , V_124 ) ;
F_95 ( V_9 ) ;
F_47 ( V_78 , V_1 ,
V_129 , F_99 , NULL , NULL , NULL ) ;
break;
case V_135 :
F_35 ( L_34 , V_82 , V_124 ) ;
F_95 ( V_9 ) ;
break;
case V_136 :
F_35 ( L_35 , V_82 , V_124 ) ;
break;
case V_137 :
F_35 ( L_36 , V_82 , V_124 ) ;
if ( ( V_9 -> V_19 & V_20 ) && V_9 -> V_17 ) {
struct V_13 * V_14 ;
V_14 = V_9 -> V_17 -> V_14 ;
if ( ! F_96 ( V_14 ) )
F_94 ( V_14 ) ;
}
break;
case V_138 :
F_104 ( V_139 L_37
L_38 , V_124 ) ;
break;
case V_140 :
F_104 ( V_139 L_37
L_39 , V_124 ) ;
break;
case V_141 :
F_104 ( V_139 L_40 ,
V_124 ) ;
break;
default:
F_25 ( L_41 , type , V_124 ) ;
break;
}
F_105 () ;
F_9 ( V_133 ) ;
F_5 ( V_9 ) ;
}
static void V_81 ( T_2 V_1 , T_3 type ,
void * V_3 )
{
struct V_8 * V_9 = V_3 ;
F_3 ( V_9 ) ;
F_106 ( V_1 , type , V_3 , F_102 ) ;
}
static void F_107 ( T_2 V_1 , T_3 type , void * V_3 )
{
struct V_16 * V_17 = V_3 ;
char V_124 [ 64 ] ;
struct V_125 V_126 = { . V_127 = sizeof( V_124 ) ,
. V_92 = V_124 } ;
F_100 ( V_1 , V_128 , & V_126 ) ;
switch ( type ) {
case V_134 :
F_35 ( L_33 , V_82 , V_124 ) ;
F_97 ( V_17 -> V_14 ) ;
break;
case V_135 :
F_35 ( L_34 , V_82 , V_124 ) ;
F_95 ( V_17 -> V_14 -> V_9 ) ;
break;
case V_136 :
F_35 ( L_35 , V_82 , V_124 ) ;
break;
case V_137 :
F_35 ( L_36 , V_82 , V_124 ) ;
if ( ! ( F_96 ( V_17 -> V_14 ) ) )
F_94 ( V_17 -> V_14 ) ;
break;
default:
F_25 ( L_41 , type , V_124 ) ;
break;
}
}
static void F_108 ( struct V_130 * V_131 )
{
struct V_132 * V_133 ;
struct V_16 * V_17 ;
V_133 = F_7 ( V_131 , struct V_132 , V_131 ) ;
V_17 = V_133 -> V_3 ;
F_103 () ;
F_107 ( V_133 -> V_1 , V_133 -> type , V_17 ) ;
F_105 () ;
F_9 ( V_133 ) ;
F_5 ( V_17 -> V_14 -> V_9 ) ;
}
static void V_77 ( T_2 V_1 , T_3 type ,
void * V_3 )
{
struct V_16 * V_17 = V_3 ;
F_3 ( V_17 -> V_14 -> V_9 ) ;
F_106 ( V_1 , type , V_3 , F_108 ) ;
}
void F_109 ( struct V_21 * V_28 , T_2 V_1 )
{
T_2 V_142 ;
struct V_8 * V_9 ;
if ( V_143 )
return;
if ( F_45 ( V_1 ) <= 0 )
return;
V_9 = F_26 ( sizeof( struct V_8 ) , V_55 ) ;
if ( V_9 == NULL ) {
F_43 ( L_42 ) ;
return;
}
F_30 ( & V_9 -> V_67 ) ;
F_110 ( & V_9 -> V_10 ) ;
V_9 -> V_1 = V_1 ;
V_9 -> V_23 = F_88 ( V_28 -> V_30 ) ;
V_9 -> V_21 = V_28 ;
F_111 ( & V_28 -> V_22 ) ;
if ( ! F_50 ( V_9 -> V_21 ) &&
F_27 ( F_28 ( V_9 -> V_1 ,
L_3 , & V_142 ) ) ) {
F_35 ( L_43 ) ;
V_9 -> V_19 |= V_20 ;
V_9 -> V_17 = F_52 ( V_1 ) ;
}
F_48 ( V_9 ) ;
}
void F_112 ( struct V_21 * V_28 )
{
struct V_8 * V_9 , * V_18 ;
if ( V_143 )
return;
F_8 (bridge, tmp, &bridge_list, list)
if ( V_9 -> V_21 == V_28 ) {
F_54 ( V_9 ) ;
F_5 ( V_9 ) ;
break;
}
}
int F_97 ( struct V_13 * V_14 )
{
int V_52 ;
F_32 ( & V_14 -> V_64 ) ;
V_52 = F_58 ( V_14 ) ;
if ( V_52 )
goto V_70;
if ( F_92 ( V_14 ) == V_113 ) {
V_52 = F_74 ( V_14 ) ;
if ( V_52 )
F_60 ( V_14 ) ;
} else {
F_35 ( L_44 , V_82 ) ;
F_60 ( V_14 ) ;
}
V_70:
F_34 ( & V_14 -> V_64 ) ;
return V_52 ;
}
int F_96 ( struct V_13 * V_14 )
{
int V_52 = 0 ;
F_32 ( & V_14 -> V_64 ) ;
V_52 = F_90 ( V_14 ) ;
if ( V_52 )
goto V_70;
V_52 = F_60 ( V_14 ) ;
if ( V_52 )
goto V_70;
V_70:
F_34 ( & V_14 -> V_64 ) ;
return V_52 ;
}
T_5 F_113 ( struct V_13 * V_14 )
{
return ( V_14 -> V_19 & V_73 ) ;
}
T_5 F_114 ( struct V_13 * V_14 )
{
unsigned int V_110 ;
V_110 = F_92 ( V_14 ) ;
return ( V_110 & V_144 ) ? 0 : 1 ;
}
T_5 F_115 ( struct V_13 * V_14 )
{
unsigned int V_110 ;
V_110 = F_92 ( V_14 ) ;
return ( V_110 == 0 ) ? 0 : 1 ;
}
