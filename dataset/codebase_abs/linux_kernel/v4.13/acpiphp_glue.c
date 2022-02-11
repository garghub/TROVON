static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 = 1 ;
V_4 -> V_7 . V_8 = V_9 ;
V_4 -> V_7 . V_10 = V_11 ;
F_3 ( V_3 , & V_4 -> V_7 ) ;
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
F_7 ( V_4 -> V_12 ) ;
V_4 -> V_7 . V_13 -> V_7 = NULL ;
F_8 ( V_4 ) ;
}
static inline void F_9 ( struct V_14 * V_12 )
{
F_10 ( & V_12 -> V_15 ) ;
}
static inline void F_11 ( struct V_14 * V_12 )
{
F_12 ( & V_12 -> V_15 , V_16 ) ;
}
static struct V_1 * F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_14 () ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 || V_4 -> V_17 . V_18 -> V_19 ) {
F_15 () ;
return NULL ;
}
F_9 ( V_4 -> V_17 . V_18 ) ;
F_6 ( V_4 ) ;
F_15 () ;
return V_4 ;
}
static void F_16 ( struct V_1 * V_4 )
{
F_11 ( V_4 -> V_17 . V_18 ) ;
}
static void V_16 ( struct V_20 * V_20 )
{
struct V_1 * V_4 ;
struct V_14 * V_12 ;
struct V_21 * V_22 , * V_23 ;
struct V_24 * V_17 , * V_25 ;
F_14 () ;
V_12 = F_17 ( V_20 , struct V_14 , V_15 ) ;
F_18 (slot, next, &bridge->slots, node) {
F_18 (func, tmp, &slot->funcs, sibling)
F_6 ( F_19 ( V_17 ) ) ;
F_8 ( V_22 ) ;
}
V_4 = V_12 -> V_4 ;
if ( V_4 ) {
F_11 ( V_4 -> V_17 . V_18 ) ;
V_4 -> V_12 = NULL ;
F_6 ( V_4 ) ;
}
F_20 ( & V_12 -> V_26 -> V_27 ) ;
F_21 ( V_12 -> V_28 ) ;
F_8 ( V_12 ) ;
F_15 () ;
}
static void V_11 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_13 ( V_3 ) ;
struct V_26 * V_29 ;
T_1 V_30 ;
if ( ! V_4 )
return;
V_29 = V_4 -> V_17 . V_22 -> V_29 ;
if ( ! V_29 -> V_13 )
goto V_31;
F_22 ( V_29 -> V_13 , V_32 , & V_30 ) ;
if ( ( ( V_30 >> 8 ) & 0xff ) != V_29 -> V_33 . V_34 ) {
V_30 = ( V_30 & 0xff000000 )
| ( ( unsigned int ) ( V_29 -> V_35 ) << 0 )
| ( ( unsigned int ) ( V_29 -> V_33 . V_34 ) << 8 )
| ( ( unsigned int ) ( V_29 -> V_33 . V_36 ) << 16 ) ;
F_23 ( V_29 -> V_13 , V_32 , V_30 ) ;
}
V_31:
F_16 ( V_4 ) ;
}
static T_2 F_24 ( T_3 V_37 , T_1 V_38 , void * V_39 ,
void * * V_40 )
{
struct V_14 * V_12 = V_39 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_21 * V_22 ;
struct V_24 * V_41 ;
T_2 V_42 = V_43 ;
unsigned long long V_44 ;
int V_45 , V_46 ;
struct V_26 * V_47 = V_12 -> V_26 ;
struct V_28 * V_48 = V_12 -> V_28 ;
T_1 V_49 ;
V_42 = F_25 ( V_37 , L_1 , NULL , & V_44 ) ;
if ( F_26 ( V_42 ) ) {
if ( V_42 != V_50 )
F_27 ( V_37 ,
L_2 , V_42 ) ;
return V_43 ;
}
if ( F_28 ( V_37 , & V_3 ) )
return V_43 ;
V_45 = ( V_44 >> 16 ) & 0xffff ;
V_46 = V_44 & 0xffff ;
F_14 () ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_15 () ;
F_29 ( V_37 , L_3 ) ;
return V_51 ;
}
V_41 = & V_4 -> V_17 ;
V_41 -> V_46 = V_46 ;
V_41 -> V_18 = V_12 ;
F_15 () ;
if ( ! F_30 ( V_3 ) && F_31 ( V_37 , L_4 ) )
V_41 -> V_52 = V_53 ;
if ( F_31 ( V_37 , L_5 ) )
V_41 -> V_52 |= V_54 ;
F_32 (slot, &bridge->slots, node)
if ( V_22 -> V_45 == V_45 )
goto V_55;
V_22 = F_2 ( sizeof( struct V_21 ) , V_5 ) ;
if ( ! V_22 ) {
F_14 () ;
F_6 ( V_4 ) ;
F_15 () ;
return V_56 ;
}
V_22 -> V_29 = V_12 -> V_26 ;
V_22 -> V_45 = V_45 ;
F_33 ( & V_22 -> V_57 ) ;
F_34 ( & V_22 -> V_58 , & V_12 -> V_59 ) ;
if ( ( F_35 ( V_47 , V_37 ) || F_30 ( V_3 ) )
&& ! ( V_48 && V_48 -> V_60 && F_36 ( V_48 ) ) ) {
unsigned long long V_61 ;
int V_62 ;
V_12 -> V_63 ++ ;
V_42 = F_25 ( V_37 , L_6 , NULL , & V_61 ) ;
if ( F_26 ( V_42 ) )
V_61 = V_12 -> V_63 ;
F_37 ( L_7 ,
V_61 , F_38 ( V_47 ) , V_47 -> V_64 , V_45 ) ;
V_62 = F_39 ( V_22 , V_61 ) ;
if ( V_62 ) {
V_22 -> V_22 = NULL ;
V_12 -> V_63 -- ;
if ( V_62 == - V_65 )
F_40 ( L_8 , V_61 ) ;
else
F_40 ( L_9 , V_62 ) ;
}
}
V_55:
V_41 -> V_22 = V_22 ;
F_34 ( & V_41 -> V_66 , & V_22 -> V_57 ) ;
if ( F_41 ( V_47 , F_42 ( V_45 , V_46 ) ,
& V_49 , 60 * 1000 ) )
V_22 -> V_52 |= V_67 ;
return V_43 ;
}
static void F_43 ( struct V_14 * V_12 )
{
struct V_21 * V_22 ;
struct V_24 * V_17 ;
F_32 (slot, &bridge->slots, node) {
F_32 (func, &slot->funcs, sibling) {
struct V_2 * V_3 = F_44 ( V_17 ) ;
F_14 () ;
V_3 -> V_7 -> V_8 = NULL ;
V_3 -> V_7 -> V_10 = NULL ;
F_15 () ;
}
V_22 -> V_52 |= V_68 ;
if ( V_22 -> V_22 )
F_45 ( V_22 ) ;
}
F_46 ( & V_69 ) ;
F_47 ( & V_12 -> V_70 ) ;
F_48 ( & V_69 ) ;
F_14 () ;
V_12 -> V_19 = true ;
F_15 () ;
}
static unsigned char F_49 ( struct V_26 * V_29 )
{
struct V_26 * V_25 ;
unsigned char V_71 , V_72 ;
V_71 = V_29 -> V_33 . V_34 ;
F_32 (tmp, &bus->children, node) {
V_72 = F_50 ( V_25 ) ;
if ( V_72 > V_71 )
V_71 = V_72 ;
}
return V_71 ;
}
static void F_51 ( struct V_21 * V_22 )
{
struct V_24 * V_17 ;
union V_73 V_74 [ 2 ] ;
struct V_75 V_76 ;
F_32 (func, &slot->funcs, sibling) {
V_76 . V_77 = 2 ;
V_76 . V_78 = V_74 ;
V_74 [ 0 ] . type = V_79 ;
V_74 [ 0 ] . integer . V_80 = V_81 ;
V_74 [ 1 ] . type = V_79 ;
V_74 [ 1 ] . integer . V_80 = 1 ;
F_52 ( F_53 ( V_17 ) , L_10 , & V_76 ,
NULL ) ;
}
}
static void F_54 ( struct V_21 * V_22 , struct V_28 * V_27 )
{
struct V_24 * V_17 ;
if ( V_27 -> V_60 )
return;
F_32 (func, &slot->funcs, sibling) {
if ( F_55 ( V_27 -> V_82 ) == V_17 -> V_46 ) {
V_27 -> V_60 = 1 ;
break;
}
}
}
static int F_56 ( struct V_21 * V_22 )
{
struct V_24 * V_17 ;
F_32 (func, &slot->funcs, sibling) {
struct V_2 * V_3 = F_44 ( V_17 ) ;
F_57 ( V_3 -> V_37 ) ;
if ( F_58 ( V_3 ) )
F_59 ( V_3 , V_83 ) ;
}
return F_60 ( V_22 -> V_29 , F_42 ( V_22 -> V_45 , 0 ) ) ;
}
static void F_61 ( struct V_21 * V_22 )
{
struct V_28 * V_27 ;
struct V_26 * V_29 = V_22 -> V_29 ;
struct V_24 * V_17 ;
int V_71 , V_84 ;
F_62 ( V_85 ) ;
F_56 ( V_22 ) ;
V_71 = F_49 ( V_29 ) ;
for ( V_84 = 0 ; V_84 < 2 ; V_84 ++ ) {
F_32 (dev, &bus->devices, bus_list) {
if ( F_63 ( V_27 -> V_82 ) != V_22 -> V_45 )
continue;
if ( F_64 ( V_27 ) ) {
V_71 = F_65 ( V_29 , V_27 , V_71 , V_84 ) ;
if ( V_84 && V_27 -> V_86 ) {
F_54 ( V_22 , V_27 ) ;
F_66 ( V_27 -> V_86 ) ;
F_67 ( V_27 -> V_86 ,
& V_85 ) ;
}
}
}
}
F_68 ( V_29 , & V_85 , NULL ) ;
F_69 ( V_29 ) ;
F_70 ( V_29 ) ;
F_51 ( V_22 ) ;
F_32 (dev, &bus->devices, bus_list) {
if ( ! V_27 -> V_87 )
V_27 -> V_88 = V_89 ;
}
F_71 ( V_29 ) ;
V_22 -> V_52 |= V_67 ;
F_32 (func, &slot->funcs, sibling) {
V_27 = F_72 ( V_29 , F_42 ( V_22 -> V_45 ,
V_17 -> V_46 ) ) ;
if ( ! V_27 ) {
V_22 -> V_52 &= ( ~ V_67 ) ;
continue;
}
}
}
static void F_73 ( struct V_21 * V_22 )
{
struct V_26 * V_29 = V_22 -> V_29 ;
struct V_28 * V_27 , * V_90 ;
struct V_24 * V_17 ;
F_74 (dev, prev, &bus->devices, bus_list)
if ( F_63 ( V_27 -> V_82 ) == V_22 -> V_45 )
F_75 ( V_27 ) ;
F_32 (func, &slot->funcs, sibling)
F_76 ( F_44 ( V_17 ) ) ;
V_22 -> V_52 &= ( ~ V_67 ) ;
}
static bool F_77 ( struct V_21 * V_22 )
{
struct V_26 * V_29 = V_22 -> V_29 ;
struct V_28 * V_27 ;
F_32 (dev, &bus->devices, bus_list) {
if ( F_63 ( V_27 -> V_82 ) == V_22 -> V_45 && V_27 -> V_91 )
return true ;
}
return false ;
}
static unsigned int F_78 ( struct V_21 * V_22 )
{
unsigned long long V_92 = 0 ;
struct V_24 * V_17 ;
F_32 (func, &slot->funcs, sibling) {
if ( V_17 -> V_52 & V_54 ) {
T_2 V_42 ;
V_42 = F_25 ( F_53 ( V_17 ) ,
L_5 , NULL , & V_92 ) ;
if ( F_79 ( V_42 ) && V_92 )
break;
} else {
T_1 V_93 ;
F_80 ( V_22 -> V_29 ,
F_42 ( V_22 -> V_45 ,
V_17 -> V_46 ) ,
V_94 , & V_93 ) ;
if ( V_93 != 0xffffffff ) {
V_92 = V_95 ;
break;
}
}
}
return ( unsigned int ) V_92 ;
}
static inline bool F_81 ( unsigned int V_92 )
{
unsigned int V_96 = V_97 | V_98 ;
return ( V_92 & V_96 ) == V_96 ;
}
static void F_82 ( struct V_28 * V_27 )
{
struct V_2 * V_3 = F_83 ( & V_27 -> V_27 ) ;
struct V_26 * V_29 = V_27 -> V_86 ;
bool V_99 = V_27 -> V_91 ;
if ( V_3 ) {
T_2 V_42 ;
unsigned long long V_92 ;
V_42 = F_25 ( V_3 -> V_37 , L_5 , NULL , & V_92 ) ;
V_99 = V_99 || ( F_79 ( V_42 ) && F_81 ( V_92 ) ) ;
}
if ( ! V_99 )
V_99 = F_84 ( V_27 ) ;
if ( ! V_99 ) {
F_75 ( V_27 ) ;
if ( V_3 )
F_76 ( V_3 ) ;
} else if ( V_29 ) {
struct V_28 * V_100 , * V_25 ;
F_85 ( & V_27 -> V_27 ) ;
F_74 (child, tmp, &bus->devices, bus_list)
F_82 ( V_100 ) ;
F_86 ( & V_27 -> V_27 ) ;
}
}
static void F_87 ( struct V_14 * V_12 )
{
struct V_21 * V_22 ;
if ( V_12 -> V_19 )
return;
if ( V_12 -> V_28 )
F_85 ( & V_12 -> V_28 -> V_27 ) ;
F_32 (slot, &bridge->slots, node) {
struct V_26 * V_29 = V_22 -> V_29 ;
struct V_28 * V_27 , * V_25 ;
if ( F_77 ( V_22 ) ) {
;
} else if ( F_81 ( F_78 ( V_22 ) ) ) {
F_74 (dev, tmp,
&bus->devices, bus_list)
if ( F_63 ( V_27 -> V_82 ) == V_22 -> V_45 )
F_82 ( V_27 ) ;
F_61 ( V_22 ) ;
} else {
F_73 ( V_22 ) ;
}
}
if ( V_12 -> V_28 )
F_86 ( & V_12 -> V_28 -> V_27 ) ;
}
static void F_69 ( struct V_26 * V_29 )
{
struct V_28 * V_27 , * V_25 ;
int V_101 ;
unsigned long V_102 = V_103 | V_104 ;
F_74 (dev, tmp, &bus->devices, bus_list) {
for ( V_101 = 0 ; V_101 < V_105 ; V_101 ++ ) {
struct V_106 * V_107 = & V_27 -> V_106 [ V_101 ] ;
if ( ( V_107 -> V_52 & V_102 ) && ! V_107 -> V_34 &&
V_107 -> V_36 ) {
F_75 ( V_27 ) ;
break;
}
}
}
}
void F_88 ( struct V_2 * V_3 )
{
struct V_14 * V_12 = NULL ;
F_14 () ;
if ( V_3 -> V_7 ) {
V_12 = F_89 ( V_3 -> V_7 ) -> V_108 ;
if ( V_12 )
F_9 ( V_12 ) ;
}
F_15 () ;
if ( V_12 ) {
F_90 () ;
F_87 ( V_12 ) ;
F_91 () ;
F_11 ( V_12 ) ;
}
}
static void F_92 ( T_1 type , struct V_1 * V_4 )
{
T_3 V_37 = V_4 -> V_7 . V_13 -> V_37 ;
struct V_24 * V_17 = & V_4 -> V_17 ;
struct V_21 * V_22 = V_17 -> V_22 ;
struct V_14 * V_12 ;
F_14 () ;
V_12 = V_4 -> V_12 ;
if ( V_12 )
F_9 ( V_12 ) ;
F_15 () ;
F_90 () ;
switch ( type ) {
case V_109 :
F_93 ( V_37 , L_11 , V_110 ) ;
if ( V_12 )
F_87 ( V_12 ) ;
else if ( ! ( V_22 -> V_52 & V_68 ) )
F_61 ( V_22 ) ;
break;
case V_111 :
F_93 ( V_37 , L_12 , V_110 ) ;
if ( V_12 ) {
F_87 ( V_12 ) ;
} else if ( ! ( V_22 -> V_52 & V_68 ) ) {
if ( F_56 ( V_22 ) )
F_87 ( V_17 -> V_18 ) ;
}
break;
case V_112 :
F_93 ( V_37 , L_13 , V_110 ) ;
F_94 ( V_22 ) ;
break;
}
F_91 () ;
if ( V_12 )
F_11 ( V_12 ) ;
}
static int V_9 ( struct V_2 * V_3 , T_1 type )
{
struct V_1 * V_4 ;
V_4 = F_13 ( V_3 ) ;
if ( ! V_4 )
return - V_113 ;
F_92 ( type , V_4 ) ;
F_16 ( V_4 ) ;
return 0 ;
}
void F_95 ( struct V_26 * V_29 )
{
struct V_14 * V_12 ;
struct V_2 * V_3 ;
T_3 V_37 ;
T_2 V_42 ;
if ( V_114 )
return;
V_3 = F_83 ( V_29 -> V_12 ) ;
if ( ! V_3 )
return;
V_37 = V_3 -> V_37 ;
V_12 = F_2 ( sizeof( struct V_14 ) , V_5 ) ;
if ( ! V_12 ) {
F_29 ( V_37 , L_14 ) ;
return;
}
F_33 ( & V_12 -> V_59 ) ;
F_96 ( & V_12 -> V_15 ) ;
V_12 -> V_28 = F_97 ( V_29 -> V_13 ) ;
V_12 -> V_26 = V_29 ;
F_98 ( & V_29 -> V_27 ) ;
F_14 () ;
if ( F_99 ( V_12 -> V_26 ) ) {
struct V_115 * V_116 ;
V_116 = F_2 ( sizeof( * V_116 ) , V_5 ) ;
if ( ! V_116 )
goto V_117;
V_116 -> V_108 = V_12 ;
F_3 ( V_3 , & V_116 -> V_7 ) ;
} else {
struct V_1 * V_4 ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 )
goto V_117;
V_12 -> V_4 = V_4 ;
V_4 -> V_12 = V_12 ;
F_9 ( V_4 -> V_17 . V_18 ) ;
}
F_15 () ;
F_46 ( & V_69 ) ;
F_100 ( & V_12 -> V_70 , & V_118 ) ;
F_48 ( & V_69 ) ;
V_42 = F_101 ( V_119 , V_37 , 1 ,
F_24 , NULL , V_12 , NULL ) ;
if ( F_26 ( V_42 ) ) {
F_29 ( V_37 , L_15 ) ;
F_43 ( V_12 ) ;
F_11 ( V_12 ) ;
}
return;
V_117:
F_15 () ;
F_20 ( & V_29 -> V_27 ) ;
F_21 ( V_12 -> V_28 ) ;
F_8 ( V_12 ) ;
}
static void F_102 ( struct V_14 * V_12 )
{
if ( F_99 ( V_12 -> V_26 ) ) {
struct V_115 * V_116 ;
struct V_2 * V_3 ;
F_14 () ;
V_3 = F_83 ( V_12 -> V_26 -> V_12 ) ;
V_116 = F_89 ( V_3 -> V_7 ) ;
V_3 -> V_7 = NULL ;
F_15 () ;
F_8 ( V_116 ) ;
}
F_43 ( V_12 ) ;
F_11 ( V_12 ) ;
}
void F_103 ( struct V_26 * V_29 )
{
struct V_14 * V_12 ;
if ( V_114 )
return;
F_46 ( & V_69 ) ;
F_32 (bridge, &bridge_list, list)
if ( V_12 -> V_26 == V_29 ) {
F_48 ( & V_69 ) ;
F_102 ( V_12 ) ;
return;
}
F_48 ( & V_69 ) ;
}
int F_104 ( struct V_21 * V_22 )
{
F_90 () ;
if ( V_22 -> V_52 & V_68 ) {
F_91 () ;
return - V_120 ;
}
if ( ! ( V_22 -> V_52 & V_67 ) )
F_61 ( V_22 ) ;
F_91 () ;
return 0 ;
}
static int F_94 ( struct V_21 * V_22 )
{
struct V_24 * V_17 ;
if ( V_22 -> V_52 & V_68 )
return - V_120 ;
F_73 ( V_22 ) ;
F_32 (func, &slot->funcs, sibling)
if ( V_17 -> V_52 & V_53 ) {
T_3 V_37 = F_53 ( V_17 ) ;
if ( F_26 ( F_105 ( V_37 ) ) )
F_29 ( V_37 , L_16 ) ;
break;
}
return 0 ;
}
int F_106 ( struct V_21 * V_22 )
{
int V_121 ;
F_107 () ;
F_90 () ;
V_121 = F_94 ( V_22 ) ;
F_91 () ;
F_108 () ;
return V_121 ;
}
T_4 F_109 ( struct V_21 * V_22 )
{
return ( V_22 -> V_52 & V_67 ) ;
}
T_4 F_110 ( struct V_21 * V_22 )
{
return ! ( F_78 ( V_22 ) & V_122 ) ;
}
T_4 F_111 ( struct V_21 * V_22 )
{
return ! ! F_78 ( V_22 ) ;
}
