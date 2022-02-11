static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 = 1 ;
F_3 ( V_3 , & V_4 -> V_7 , V_8 , NULL ,
V_9 ) ;
return V_4 ;
}
static struct V_1 * F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( ! V_3 -> V_7 )
return NULL ;
V_4 = F_5 ( V_3 -> V_7 ) ;
V_4 -> V_6 ++ ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_4 )
{
if ( -- V_4 -> V_6 )
return;
F_7 ( V_4 -> V_10 ) ;
V_4 -> V_7 . V_11 -> V_7 = NULL ;
F_8 ( V_4 ) ;
}
static inline void F_9 ( struct V_12 * V_10 )
{
F_10 ( & V_10 -> V_13 ) ;
}
static inline void F_11 ( struct V_12 * V_10 )
{
F_12 ( & V_10 -> V_13 , V_14 ) ;
}
static struct V_1 * F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_14 () ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 || V_4 -> V_15 . V_16 -> V_17 ) {
F_15 () ;
return NULL ;
}
F_9 ( V_4 -> V_15 . V_16 ) ;
F_6 ( V_4 ) ;
F_15 () ;
return V_4 ;
}
static void F_16 ( struct V_1 * V_4 )
{
F_11 ( V_4 -> V_15 . V_16 ) ;
}
static void V_14 ( struct V_18 * V_18 )
{
struct V_1 * V_4 ;
struct V_12 * V_10 ;
struct V_19 * V_20 , * V_21 ;
struct V_22 * V_15 , * V_23 ;
F_14 () ;
V_10 = F_17 ( V_18 , struct V_12 , V_13 ) ;
F_18 (slot, next, &bridge->slots, node) {
F_18 (func, tmp, &slot->funcs, sibling)
F_6 ( F_19 ( V_15 ) ) ;
F_8 ( V_20 ) ;
}
V_4 = V_10 -> V_4 ;
if ( V_4 ) {
F_11 ( V_4 -> V_15 . V_16 ) ;
V_4 -> V_10 = NULL ;
F_6 ( V_4 ) ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_21 ( V_10 -> V_26 ) ;
F_8 ( V_10 ) ;
F_15 () ;
}
static void V_9 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_13 ( V_3 ) ;
struct V_24 * V_27 ;
T_1 V_28 ;
if ( ! V_4 )
return;
V_27 = V_4 -> V_15 . V_20 -> V_27 ;
if ( ! V_27 -> V_11 )
goto V_29;
F_22 ( V_27 -> V_11 , V_30 , & V_28 ) ;
if ( ( ( V_28 >> 8 ) & 0xff ) != V_27 -> V_31 . V_32 ) {
V_28 = ( V_28 & 0xff000000 )
| ( ( unsigned int ) ( V_27 -> V_33 ) << 0 )
| ( ( unsigned int ) ( V_27 -> V_31 . V_32 ) << 8 )
| ( ( unsigned int ) ( V_27 -> V_31 . V_34 ) << 16 ) ;
F_23 ( V_27 -> V_11 , V_30 , V_28 ) ;
}
V_29:
F_16 ( V_4 ) ;
}
static bool F_24 ( struct V_26 * V_35 )
{
T_1 V_36 ;
T_2 V_23 ;
struct V_37 * V_38 ;
if ( F_25 ( V_35 , V_39 , & V_36 ) )
return false ;
if ( ! ( V_36 & V_40 ) )
return false ;
V_23 = F_26 ( V_35 ) ;
if ( ! V_23 )
return false ;
V_38 = F_27 ( V_23 ) ;
if ( ! V_38 )
return false ;
if ( ! ( V_38 -> V_41 & V_42 ) )
return false ;
return true ;
}
static T_3 F_28 ( T_2 V_43 , T_1 V_44 , void * V_45 ,
void * * V_46 )
{
struct V_12 * V_10 = V_45 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_19 * V_20 ;
struct V_22 * V_47 ;
T_3 V_48 = V_49 ;
unsigned long long V_50 ;
int V_51 , V_52 ;
struct V_24 * V_53 = V_10 -> V_24 ;
struct V_26 * V_35 = V_10 -> V_26 ;
T_1 V_54 ;
V_48 = F_29 ( V_43 , L_1 , NULL , & V_50 ) ;
if ( F_30 ( V_48 ) ) {
if ( V_48 != V_55 )
F_31 ( V_43 ,
L_2 , V_48 ) ;
return V_49 ;
}
if ( F_32 ( V_43 , & V_3 ) )
return V_49 ;
V_51 = ( V_50 >> 16 ) & 0xffff ;
V_52 = V_50 & 0xffff ;
F_14 () ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_15 () ;
F_33 ( V_43 , L_3 ) ;
return V_56 ;
}
V_47 = & V_4 -> V_15 ;
V_47 -> V_52 = V_52 ;
V_47 -> V_16 = V_10 ;
F_15 () ;
if ( ! F_34 ( V_3 ) && F_35 ( V_43 , L_4 ) )
V_47 -> V_57 = V_58 ;
if ( F_35 ( V_43 , L_5 ) )
V_47 -> V_57 |= V_59 ;
F_36 (slot, &bridge->slots, node)
if ( V_20 -> V_51 == V_51 )
goto V_60;
V_20 = F_2 ( sizeof( struct V_19 ) , V_5 ) ;
if ( ! V_20 ) {
F_14 () ;
F_6 ( V_4 ) ;
F_15 () ;
return V_61 ;
}
V_20 -> V_27 = V_10 -> V_24 ;
V_20 -> V_51 = V_51 ;
F_37 ( & V_20 -> V_62 ) ;
F_38 ( & V_20 -> V_63 , & V_10 -> V_64 ) ;
if ( ( F_39 ( V_53 , V_43 ) || F_34 ( V_3 ) )
&& ! ( V_35 && F_24 ( V_35 ) ) ) {
unsigned long long V_65 ;
int V_66 ;
V_10 -> V_67 ++ ;
V_48 = F_29 ( V_43 , L_6 , NULL , & V_65 ) ;
if ( F_30 ( V_48 ) )
V_65 = V_10 -> V_67 ;
F_40 ( L_7 ,
V_65 , F_41 ( V_53 ) , V_53 -> V_68 , V_51 ) ;
V_66 = F_42 ( V_20 , V_65 ) ;
if ( V_66 ) {
V_20 -> V_20 = NULL ;
V_10 -> V_67 -- ;
if ( V_66 == - V_69 )
F_43 ( L_8 , V_65 ) ;
else
F_43 ( L_9 , V_66 ) ;
}
}
V_60:
V_47 -> V_20 = V_20 ;
F_38 ( & V_47 -> V_70 , & V_20 -> V_62 ) ;
if ( F_44 ( V_53 , F_45 ( V_51 , V_52 ) ,
& V_54 , 60 * 1000 ) )
V_20 -> V_57 |= V_71 ;
return V_49 ;
}
static struct V_12 * F_46 ( struct V_2 * V_3 )
{
struct V_12 * V_10 = NULL ;
F_14 () ;
if ( V_3 -> V_7 ) {
V_10 = F_47 ( V_3 -> V_7 ) -> V_72 ;
if ( V_10 )
F_9 ( V_10 ) ;
}
F_15 () ;
return V_10 ;
}
static void F_48 ( struct V_12 * V_10 )
{
struct V_19 * V_20 ;
struct V_22 * V_15 ;
F_36 (slot, &bridge->slots, node) {
F_36 (func, &slot->funcs, sibling) {
struct V_2 * V_3 = F_49 ( V_15 ) ;
F_14 () ;
V_3 -> V_7 -> V_73 = NULL ;
V_3 -> V_7 -> V_74 = NULL ;
F_15 () ;
}
V_20 -> V_57 |= V_75 ;
if ( V_20 -> V_20 )
F_50 ( V_20 ) ;
}
F_51 ( & V_76 ) ;
F_52 ( & V_10 -> V_77 ) ;
F_53 ( & V_76 ) ;
F_14 () ;
V_10 -> V_17 = true ;
F_15 () ;
}
static unsigned char F_54 ( struct V_24 * V_27 )
{
struct V_24 * V_23 ;
unsigned char V_78 , V_79 ;
V_78 = V_27 -> V_31 . V_32 ;
F_36 (tmp, &bus->children, node) {
V_79 = F_55 ( V_23 ) ;
if ( V_79 > V_78 )
V_78 = V_79 ;
}
return V_78 ;
}
static void F_56 ( struct V_19 * V_20 )
{
struct V_22 * V_15 ;
union V_80 V_81 [ 2 ] ;
struct V_82 V_83 ;
F_36 (func, &slot->funcs, sibling) {
V_83 . V_84 = 2 ;
V_83 . V_85 = V_81 ;
V_81 [ 0 ] . type = V_86 ;
V_81 [ 0 ] . integer . V_87 = V_88 ;
V_81 [ 1 ] . type = V_86 ;
V_81 [ 1 ] . integer . V_87 = 1 ;
F_57 ( F_58 ( V_15 ) , L_10 , & V_83 ,
NULL ) ;
}
}
static void F_59 ( struct V_19 * V_20 , struct V_26 * V_25 )
{
struct V_22 * V_15 ;
if ( V_25 -> V_89 )
return;
F_36 (func, &slot->funcs, sibling) {
if ( F_60 ( V_25 -> V_90 ) == V_15 -> V_52 ) {
V_25 -> V_89 = 1 ;
break;
}
}
}
static int F_61 ( struct V_19 * V_20 )
{
struct V_22 * V_15 ;
F_36 (func, &slot->funcs, sibling) {
struct V_2 * V_3 = F_49 ( V_15 ) ;
F_62 ( V_3 -> V_43 ) ;
if ( F_63 ( V_3 ) )
F_64 ( V_3 , V_91 ) ;
}
return F_65 ( V_20 -> V_27 , F_45 ( V_20 -> V_51 , 0 ) ) ;
}
static void F_66 ( struct V_19 * V_20 )
{
struct V_26 * V_25 ;
struct V_24 * V_27 = V_20 -> V_27 ;
struct V_22 * V_15 ;
int V_78 , V_92 ;
F_67 ( V_93 ) ;
F_61 ( V_20 ) ;
V_78 = F_54 ( V_27 ) ;
for ( V_92 = 0 ; V_92 < 2 ; V_92 ++ ) {
F_36 (dev, &bus->devices, bus_list) {
if ( F_68 ( V_25 -> V_90 ) != V_20 -> V_51 )
continue;
if ( F_69 ( V_25 ) ) {
V_78 = F_70 ( V_27 , V_25 , V_78 , V_92 ) ;
if ( V_92 && V_25 -> V_94 ) {
F_59 ( V_20 , V_25 ) ;
F_71 ( V_25 -> V_94 ) ;
F_72 ( V_25 -> V_94 ,
& V_93 ) ;
}
}
}
}
F_73 ( V_27 , & V_93 , NULL ) ;
F_74 ( V_27 ) ;
F_75 ( V_27 ) ;
F_56 ( V_20 ) ;
F_36 (dev, &bus->devices, bus_list) {
if ( ! V_25 -> V_95 )
V_25 -> V_96 = V_97 ;
}
F_76 ( V_27 ) ;
V_20 -> V_57 |= V_71 ;
F_36 (func, &slot->funcs, sibling) {
V_25 = F_77 ( V_27 , F_45 ( V_20 -> V_51 ,
V_15 -> V_52 ) ) ;
if ( ! V_25 ) {
V_20 -> V_57 &= ( ~ V_71 ) ;
continue;
}
}
}
static void F_78 ( struct V_19 * V_20 )
{
struct V_24 * V_27 = V_20 -> V_27 ;
struct V_26 * V_25 , * V_98 ;
struct V_22 * V_15 ;
F_79 (dev, prev, &bus->devices, bus_list)
if ( F_68 ( V_25 -> V_90 ) == V_20 -> V_51 )
F_80 ( V_25 ) ;
F_36 (func, &slot->funcs, sibling)
F_81 ( F_49 ( V_15 ) ) ;
V_20 -> V_57 &= ( ~ V_71 ) ;
}
static bool F_82 ( struct V_2 * V_3 )
{
return V_3 && V_3 -> V_57 . V_99 ;
}
static bool F_83 ( struct V_19 * V_20 )
{
struct V_22 * V_15 ;
F_36 (func, &slot->funcs, sibling)
if ( F_82 ( F_49 ( V_15 ) ) )
return true ;
return false ;
}
static unsigned int F_84 ( struct V_19 * V_20 )
{
unsigned long long V_100 = 0 ;
struct V_22 * V_15 ;
F_36 (func, &slot->funcs, sibling) {
if ( V_15 -> V_57 & V_59 ) {
T_3 V_48 ;
V_48 = F_29 ( F_58 ( V_15 ) ,
L_5 , NULL , & V_100 ) ;
if ( F_85 ( V_48 ) && V_100 )
break;
} else {
T_1 V_101 ;
F_86 ( V_20 -> V_27 ,
F_45 ( V_20 -> V_51 ,
V_15 -> V_52 ) ,
V_102 , & V_101 ) ;
if ( V_101 != 0xffffffff ) {
V_100 = V_103 ;
break;
}
}
}
return ( unsigned int ) V_100 ;
}
static inline bool F_87 ( unsigned int V_100 )
{
unsigned int V_104 = V_105 | V_106 ;
return ( V_100 & V_104 ) == V_104 ;
}
static void F_88 ( struct V_26 * V_25 )
{
struct V_2 * V_3 = F_89 ( & V_25 -> V_25 ) ;
struct V_24 * V_27 = V_25 -> V_94 ;
bool V_107 = false ;
if ( V_3 ) {
T_3 V_48 ;
unsigned long long V_100 ;
V_48 = F_29 ( V_3 -> V_43 , L_5 , NULL , & V_100 ) ;
V_107 = ( F_85 ( V_48 ) && F_87 ( V_100 ) )
|| F_82 ( V_3 ) ;
}
if ( ! V_107 )
V_107 = F_90 ( V_25 ) ;
if ( ! V_107 ) {
F_80 ( V_25 ) ;
if ( V_3 )
F_81 ( V_3 ) ;
} else if ( V_27 ) {
struct V_26 * V_108 , * V_23 ;
F_91 ( & V_25 -> V_25 ) ;
F_79 (child, tmp, &bus->devices, bus_list)
F_88 ( V_108 ) ;
F_92 ( & V_25 -> V_25 ) ;
}
}
static void F_93 ( struct V_12 * V_10 )
{
struct V_19 * V_20 ;
if ( V_10 -> V_17 )
return;
F_36 (slot, &bridge->slots, node) {
struct V_24 * V_27 = V_20 -> V_27 ;
struct V_26 * V_25 , * V_23 ;
if ( F_83 ( V_20 ) ) {
;
} else if ( F_87 ( F_84 ( V_20 ) ) ) {
F_79 (dev, tmp,
&bus->devices, bus_list)
if ( F_68 ( V_25 -> V_90 ) == V_20 -> V_51 )
F_88 ( V_25 ) ;
F_66 ( V_20 ) ;
} else {
F_78 ( V_20 ) ;
}
}
}
static void F_75 ( struct V_24 * V_27 )
{
struct V_26 * V_25 ;
F_36 (dev, &bus->devices, bus_list)
F_94 ( V_25 ) ;
}
static void F_74 ( struct V_24 * V_27 )
{
struct V_26 * V_25 , * V_23 ;
int V_109 ;
unsigned long V_110 = V_111 | V_112 ;
F_79 (dev, tmp, &bus->devices, bus_list) {
for ( V_109 = 0 ; V_109 < V_113 ; V_109 ++ ) {
struct V_114 * V_115 = & V_25 -> V_114 [ V_109 ] ;
if ( ( V_115 -> V_57 & V_110 ) && ! V_115 -> V_32 &&
V_115 -> V_34 ) {
F_80 ( V_25 ) ;
break;
}
}
}
}
void F_95 ( struct V_2 * V_3 )
{
struct V_12 * V_10 ;
V_10 = F_46 ( V_3 ) ;
if ( V_10 ) {
F_96 () ;
F_93 ( V_10 ) ;
F_97 () ;
F_11 ( V_10 ) ;
}
}
static void F_98 ( T_1 type , struct V_1 * V_4 )
{
T_2 V_43 = V_4 -> V_7 . V_11 -> V_43 ;
struct V_22 * V_15 = & V_4 -> V_15 ;
struct V_19 * V_20 = V_15 -> V_20 ;
struct V_12 * V_10 ;
F_14 () ;
V_10 = V_4 -> V_10 ;
if ( V_10 )
F_9 ( V_10 ) ;
F_15 () ;
F_96 () ;
switch ( type ) {
case V_116 :
F_99 ( V_43 , L_11 , V_117 ) ;
if ( V_10 )
F_93 ( V_10 ) ;
else if ( ! ( V_20 -> V_57 & V_75 ) )
F_66 ( V_20 ) ;
break;
case V_118 :
F_99 ( V_43 , L_12 , V_117 ) ;
if ( V_10 ) {
F_93 ( V_10 ) ;
} else if ( ! ( V_20 -> V_57 & V_75 ) ) {
if ( F_61 ( V_20 ) )
F_93 ( V_15 -> V_16 ) ;
}
break;
case V_119 :
F_99 ( V_43 , L_13 , V_117 ) ;
F_100 ( V_20 ) ;
break;
}
F_97 () ;
if ( V_10 )
F_11 ( V_10 ) ;
}
static int V_8 ( struct V_2 * V_3 , T_1 type )
{
struct V_1 * V_4 ;
V_4 = F_13 ( V_3 ) ;
if ( ! V_4 )
return - V_120 ;
F_98 ( type , V_4 ) ;
F_16 ( V_4 ) ;
return 0 ;
}
void F_101 ( struct V_24 * V_27 )
{
struct V_12 * V_10 ;
struct V_2 * V_3 ;
T_2 V_43 ;
T_3 V_48 ;
if ( V_121 )
return;
V_3 = F_89 ( V_27 -> V_10 ) ;
if ( ! V_3 )
return;
V_43 = V_3 -> V_43 ;
V_10 = F_2 ( sizeof( struct V_12 ) , V_5 ) ;
if ( ! V_10 ) {
F_33 ( V_43 , L_14 ) ;
return;
}
F_37 ( & V_10 -> V_64 ) ;
F_102 ( & V_10 -> V_13 ) ;
V_10 -> V_26 = F_103 ( V_27 -> V_11 ) ;
V_10 -> V_24 = V_27 ;
F_104 ( & V_27 -> V_25 ) ;
F_14 () ;
if ( F_105 ( V_10 -> V_24 ) ) {
struct V_122 * V_123 ;
V_123 = F_2 ( sizeof( * V_123 ) , V_5 ) ;
if ( ! V_123 )
goto V_124;
V_123 -> V_72 = V_10 ;
F_3 ( V_3 , & V_123 -> V_7 , NULL , NULL , NULL ) ;
} else {
struct V_1 * V_4 ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 )
goto V_124;
V_10 -> V_4 = V_4 ;
V_4 -> V_10 = V_10 ;
F_9 ( V_4 -> V_15 . V_16 ) ;
}
F_15 () ;
F_51 ( & V_76 ) ;
F_106 ( & V_10 -> V_77 , & V_125 ) ;
F_53 ( & V_76 ) ;
V_48 = F_107 ( V_126 , V_43 , 1 ,
F_28 , NULL , V_10 , NULL ) ;
if ( F_30 ( V_48 ) ) {
F_33 ( V_43 , L_15 ) ;
F_48 ( V_10 ) ;
F_11 ( V_10 ) ;
}
return;
V_124:
F_15 () ;
F_20 ( & V_27 -> V_25 ) ;
F_21 ( V_10 -> V_26 ) ;
F_8 ( V_10 ) ;
}
void F_108 ( struct V_12 * V_10 )
{
if ( F_105 ( V_10 -> V_24 ) ) {
struct V_122 * V_123 ;
struct V_2 * V_3 ;
F_14 () ;
V_3 = F_89 ( V_10 -> V_24 -> V_10 ) ;
V_123 = F_47 ( V_3 -> V_7 ) ;
V_3 -> V_7 = NULL ;
F_15 () ;
F_8 ( V_123 ) ;
}
F_48 ( V_10 ) ;
F_11 ( V_10 ) ;
}
void F_109 ( struct V_24 * V_27 )
{
struct V_12 * V_10 ;
if ( V_121 )
return;
F_51 ( & V_76 ) ;
F_36 (bridge, &bridge_list, list)
if ( V_10 -> V_24 == V_27 ) {
F_53 ( & V_76 ) ;
F_108 ( V_10 ) ;
return;
}
F_53 ( & V_76 ) ;
}
int F_110 ( struct V_19 * V_20 )
{
F_96 () ;
if ( V_20 -> V_57 & V_75 )
return - V_127 ;
if ( ! ( V_20 -> V_57 & V_71 ) )
F_66 ( V_20 ) ;
F_97 () ;
return 0 ;
}
static int F_100 ( struct V_19 * V_20 )
{
struct V_22 * V_15 ;
if ( V_20 -> V_57 & V_75 )
return - V_127 ;
F_78 ( V_20 ) ;
F_36 (func, &slot->funcs, sibling)
if ( V_15 -> V_57 & V_58 ) {
T_2 V_43 = F_58 ( V_15 ) ;
if ( F_30 ( F_111 ( V_43 ) ) )
F_33 ( V_43 , L_16 ) ;
break;
}
return 0 ;
}
int F_112 ( struct V_19 * V_20 )
{
int V_128 ;
F_113 () ;
F_96 () ;
V_128 = F_100 ( V_20 ) ;
F_97 () ;
F_114 () ;
return V_128 ;
}
T_4 F_115 ( struct V_19 * V_20 )
{
return ( V_20 -> V_57 & V_71 ) ;
}
T_4 F_116 ( struct V_19 * V_20 )
{
return ! ( F_84 ( V_20 ) & V_129 ) ;
}
T_4 F_117 ( struct V_19 * V_20 )
{
return ! ! F_84 ( V_20 ) ;
}
