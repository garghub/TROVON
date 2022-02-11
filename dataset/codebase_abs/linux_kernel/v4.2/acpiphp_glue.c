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
static bool F_24 ( struct V_28 * V_37 )
{
T_1 V_38 ;
T_2 V_25 ;
struct V_39 * V_40 ;
if ( F_25 ( V_37 , V_41 , & V_38 ) )
return false ;
if ( ! ( V_38 & V_42 ) )
return false ;
V_25 = F_26 ( V_37 ) ;
if ( ! V_25 )
return false ;
V_40 = F_27 ( V_25 ) ;
if ( ! V_40 )
return false ;
if ( ! ( V_40 -> V_43 & V_44 ) )
return false ;
return true ;
}
static T_3 F_28 ( T_2 V_45 , T_1 V_46 , void * V_47 ,
void * * V_48 )
{
struct V_14 * V_12 = V_47 ;
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_21 * V_22 ;
struct V_24 * V_49 ;
T_3 V_50 = V_51 ;
unsigned long long V_52 ;
int V_53 , V_54 ;
struct V_26 * V_55 = V_12 -> V_26 ;
struct V_28 * V_37 = V_12 -> V_28 ;
T_1 V_56 ;
V_50 = F_29 ( V_45 , L_1 , NULL , & V_52 ) ;
if ( F_30 ( V_50 ) ) {
if ( V_50 != V_57 )
F_31 ( V_45 ,
L_2 , V_50 ) ;
return V_51 ;
}
if ( F_32 ( V_45 , & V_3 ) )
return V_51 ;
V_53 = ( V_52 >> 16 ) & 0xffff ;
V_54 = V_52 & 0xffff ;
F_14 () ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_15 () ;
F_33 ( V_45 , L_3 ) ;
return V_58 ;
}
V_49 = & V_4 -> V_17 ;
V_49 -> V_54 = V_54 ;
V_49 -> V_18 = V_12 ;
F_15 () ;
if ( ! F_34 ( V_3 ) && F_35 ( V_45 , L_4 ) )
V_49 -> V_59 = V_60 ;
if ( F_35 ( V_45 , L_5 ) )
V_49 -> V_59 |= V_61 ;
F_36 (slot, &bridge->slots, node)
if ( V_22 -> V_53 == V_53 )
goto V_62;
V_22 = F_2 ( sizeof( struct V_21 ) , V_5 ) ;
if ( ! V_22 ) {
F_14 () ;
F_6 ( V_4 ) ;
F_15 () ;
return V_63 ;
}
V_22 -> V_29 = V_12 -> V_26 ;
V_22 -> V_53 = V_53 ;
F_37 ( & V_22 -> V_64 ) ;
F_38 ( & V_22 -> V_65 , & V_12 -> V_66 ) ;
if ( ( F_39 ( V_55 , V_45 ) || F_34 ( V_3 ) )
&& ! ( V_37 && F_24 ( V_37 ) ) ) {
unsigned long long V_67 ;
int V_68 ;
V_12 -> V_69 ++ ;
V_50 = F_29 ( V_45 , L_6 , NULL , & V_67 ) ;
if ( F_30 ( V_50 ) )
V_67 = V_12 -> V_69 ;
F_40 ( L_7 ,
V_67 , F_41 ( V_55 ) , V_55 -> V_70 , V_53 ) ;
V_68 = F_42 ( V_22 , V_67 ) ;
if ( V_68 ) {
V_22 -> V_22 = NULL ;
V_12 -> V_69 -- ;
if ( V_68 == - V_71 )
F_43 ( L_8 , V_67 ) ;
else
F_43 ( L_9 , V_68 ) ;
}
}
V_62:
V_49 -> V_22 = V_22 ;
F_38 ( & V_49 -> V_72 , & V_22 -> V_64 ) ;
if ( F_44 ( V_55 , F_45 ( V_53 , V_54 ) ,
& V_56 , 60 * 1000 ) )
V_22 -> V_59 |= V_73 ;
return V_51 ;
}
static void F_46 ( struct V_14 * V_12 )
{
struct V_21 * V_22 ;
struct V_24 * V_17 ;
F_36 (slot, &bridge->slots, node) {
F_36 (func, &slot->funcs, sibling) {
struct V_2 * V_3 = F_47 ( V_17 ) ;
F_14 () ;
V_3 -> V_7 -> V_8 = NULL ;
V_3 -> V_7 -> V_10 = NULL ;
F_15 () ;
}
V_22 -> V_59 |= V_74 ;
if ( V_22 -> V_22 )
F_48 ( V_22 ) ;
}
F_49 ( & V_75 ) ;
F_50 ( & V_12 -> V_76 ) ;
F_51 ( & V_75 ) ;
F_14 () ;
V_12 -> V_19 = true ;
F_15 () ;
}
static unsigned char F_52 ( struct V_26 * V_29 )
{
struct V_26 * V_25 ;
unsigned char V_77 , V_78 ;
V_77 = V_29 -> V_33 . V_34 ;
F_36 (tmp, &bus->children, node) {
V_78 = F_53 ( V_25 ) ;
if ( V_78 > V_77 )
V_77 = V_78 ;
}
return V_77 ;
}
static void F_54 ( struct V_21 * V_22 )
{
struct V_24 * V_17 ;
union V_79 V_80 [ 2 ] ;
struct V_81 V_82 ;
F_36 (func, &slot->funcs, sibling) {
V_82 . V_83 = 2 ;
V_82 . V_84 = V_80 ;
V_80 [ 0 ] . type = V_85 ;
V_80 [ 0 ] . integer . V_86 = V_87 ;
V_80 [ 1 ] . type = V_85 ;
V_80 [ 1 ] . integer . V_86 = 1 ;
F_55 ( F_56 ( V_17 ) , L_10 , & V_82 ,
NULL ) ;
}
}
static void F_57 ( struct V_21 * V_22 , struct V_28 * V_27 )
{
struct V_24 * V_17 ;
if ( V_27 -> V_88 )
return;
F_36 (func, &slot->funcs, sibling) {
if ( F_58 ( V_27 -> V_89 ) == V_17 -> V_54 ) {
V_27 -> V_88 = 1 ;
break;
}
}
}
static int F_59 ( struct V_21 * V_22 )
{
struct V_24 * V_17 ;
F_36 (func, &slot->funcs, sibling) {
struct V_2 * V_3 = F_47 ( V_17 ) ;
F_60 ( V_3 -> V_45 ) ;
if ( F_61 ( V_3 ) )
F_62 ( V_3 , V_90 ) ;
}
return F_63 ( V_22 -> V_29 , F_45 ( V_22 -> V_53 , 0 ) ) ;
}
static void F_64 ( struct V_21 * V_22 )
{
struct V_28 * V_27 ;
struct V_26 * V_29 = V_22 -> V_29 ;
struct V_24 * V_17 ;
int V_77 , V_91 ;
F_65 ( V_92 ) ;
F_59 ( V_22 ) ;
V_77 = F_52 ( V_29 ) ;
for ( V_91 = 0 ; V_91 < 2 ; V_91 ++ ) {
F_36 (dev, &bus->devices, bus_list) {
if ( F_66 ( V_27 -> V_89 ) != V_22 -> V_53 )
continue;
if ( F_67 ( V_27 ) ) {
V_77 = F_68 ( V_29 , V_27 , V_77 , V_91 ) ;
if ( V_91 && V_27 -> V_93 ) {
F_57 ( V_22 , V_27 ) ;
F_69 ( V_27 -> V_93 ) ;
F_70 ( V_27 -> V_93 ,
& V_92 ) ;
}
}
}
}
F_71 ( V_29 , & V_92 , NULL ) ;
F_72 ( V_29 ) ;
F_73 ( V_29 ) ;
F_54 ( V_22 ) ;
F_36 (dev, &bus->devices, bus_list) {
if ( ! V_27 -> V_94 )
V_27 -> V_95 = V_96 ;
}
F_74 ( V_29 ) ;
V_22 -> V_59 |= V_73 ;
F_36 (func, &slot->funcs, sibling) {
V_27 = F_75 ( V_29 , F_45 ( V_22 -> V_53 ,
V_17 -> V_54 ) ) ;
if ( ! V_27 ) {
V_22 -> V_59 &= ( ~ V_73 ) ;
continue;
}
}
}
static void F_76 ( struct V_21 * V_22 )
{
struct V_26 * V_29 = V_22 -> V_29 ;
struct V_28 * V_27 , * V_97 ;
struct V_24 * V_17 ;
F_77 (dev, prev, &bus->devices, bus_list)
if ( F_66 ( V_27 -> V_89 ) == V_22 -> V_53 )
F_78 ( V_27 ) ;
F_36 (func, &slot->funcs, sibling)
F_79 ( F_47 ( V_17 ) ) ;
V_22 -> V_59 &= ( ~ V_73 ) ;
}
static bool F_80 ( struct V_21 * V_22 )
{
struct V_26 * V_29 = V_22 -> V_29 ;
struct V_28 * V_27 ;
F_36 (dev, &bus->devices, bus_list) {
if ( F_66 ( V_27 -> V_89 ) == V_22 -> V_53 && V_27 -> V_98 )
return true ;
}
return false ;
}
static unsigned int F_81 ( struct V_21 * V_22 )
{
unsigned long long V_99 = 0 ;
struct V_24 * V_17 ;
F_36 (func, &slot->funcs, sibling) {
if ( V_17 -> V_59 & V_61 ) {
T_3 V_50 ;
V_50 = F_29 ( F_56 ( V_17 ) ,
L_5 , NULL , & V_99 ) ;
if ( F_82 ( V_50 ) && V_99 )
break;
} else {
T_1 V_100 ;
F_83 ( V_22 -> V_29 ,
F_45 ( V_22 -> V_53 ,
V_17 -> V_54 ) ,
V_101 , & V_100 ) ;
if ( V_100 != 0xffffffff ) {
V_99 = V_102 ;
break;
}
}
}
return ( unsigned int ) V_99 ;
}
static inline bool F_84 ( unsigned int V_99 )
{
unsigned int V_103 = V_104 | V_105 ;
return ( V_99 & V_103 ) == V_103 ;
}
static void F_85 ( struct V_28 * V_27 )
{
struct V_2 * V_3 = F_86 ( & V_27 -> V_27 ) ;
struct V_26 * V_29 = V_27 -> V_93 ;
bool V_106 = V_27 -> V_98 ;
if ( V_3 ) {
T_3 V_50 ;
unsigned long long V_99 ;
V_50 = F_29 ( V_3 -> V_45 , L_5 , NULL , & V_99 ) ;
V_106 = V_106 || ( F_82 ( V_50 ) && F_84 ( V_99 ) ) ;
}
if ( ! V_106 )
V_106 = F_87 ( V_27 ) ;
if ( ! V_106 ) {
F_78 ( V_27 ) ;
if ( V_3 )
F_79 ( V_3 ) ;
} else if ( V_29 ) {
struct V_28 * V_107 , * V_25 ;
F_88 ( & V_27 -> V_27 ) ;
F_77 (child, tmp, &bus->devices, bus_list)
F_85 ( V_107 ) ;
F_89 ( & V_27 -> V_27 ) ;
}
}
static void F_90 ( struct V_14 * V_12 )
{
struct V_21 * V_22 ;
if ( V_12 -> V_19 )
return;
F_36 (slot, &bridge->slots, node) {
struct V_26 * V_29 = V_22 -> V_29 ;
struct V_28 * V_27 , * V_25 ;
if ( F_80 ( V_22 ) ) {
;
} else if ( F_84 ( F_81 ( V_22 ) ) ) {
F_77 (dev, tmp,
&bus->devices, bus_list)
if ( F_66 ( V_27 -> V_89 ) == V_22 -> V_53 )
F_85 ( V_27 ) ;
F_64 ( V_22 ) ;
} else {
F_76 ( V_22 ) ;
}
}
}
static void F_72 ( struct V_26 * V_29 )
{
struct V_28 * V_27 , * V_25 ;
int V_108 ;
unsigned long V_109 = V_110 | V_111 ;
F_77 (dev, tmp, &bus->devices, bus_list) {
for ( V_108 = 0 ; V_108 < V_112 ; V_108 ++ ) {
struct V_113 * V_114 = & V_27 -> V_113 [ V_108 ] ;
if ( ( V_114 -> V_59 & V_109 ) && ! V_114 -> V_34 &&
V_114 -> V_36 ) {
F_78 ( V_27 ) ;
break;
}
}
}
}
void F_91 ( struct V_2 * V_3 )
{
struct V_14 * V_12 = NULL ;
F_14 () ;
if ( V_3 -> V_7 ) {
V_12 = F_92 ( V_3 -> V_7 ) -> V_115 ;
if ( V_12 )
F_9 ( V_12 ) ;
}
F_15 () ;
if ( V_12 ) {
F_93 () ;
F_90 ( V_12 ) ;
F_94 () ;
F_11 ( V_12 ) ;
}
}
static void F_95 ( T_1 type , struct V_1 * V_4 )
{
T_2 V_45 = V_4 -> V_7 . V_13 -> V_45 ;
struct V_24 * V_17 = & V_4 -> V_17 ;
struct V_21 * V_22 = V_17 -> V_22 ;
struct V_14 * V_12 ;
F_14 () ;
V_12 = V_4 -> V_12 ;
if ( V_12 )
F_9 ( V_12 ) ;
F_15 () ;
F_93 () ;
switch ( type ) {
case V_116 :
F_96 ( V_45 , L_11 , V_117 ) ;
if ( V_12 )
F_90 ( V_12 ) ;
else if ( ! ( V_22 -> V_59 & V_74 ) )
F_64 ( V_22 ) ;
break;
case V_118 :
F_96 ( V_45 , L_12 , V_117 ) ;
if ( V_12 ) {
F_90 ( V_12 ) ;
} else if ( ! ( V_22 -> V_59 & V_74 ) ) {
if ( F_59 ( V_22 ) )
F_90 ( V_17 -> V_18 ) ;
}
break;
case V_119 :
F_96 ( V_45 , L_13 , V_117 ) ;
F_97 ( V_22 ) ;
break;
}
F_94 () ;
if ( V_12 )
F_11 ( V_12 ) ;
}
static int V_9 ( struct V_2 * V_3 , T_1 type )
{
struct V_1 * V_4 ;
V_4 = F_13 ( V_3 ) ;
if ( ! V_4 )
return - V_120 ;
F_95 ( type , V_4 ) ;
F_16 ( V_4 ) ;
return 0 ;
}
void F_98 ( struct V_26 * V_29 )
{
struct V_14 * V_12 ;
struct V_2 * V_3 ;
T_2 V_45 ;
T_3 V_50 ;
if ( V_121 )
return;
V_3 = F_86 ( V_29 -> V_12 ) ;
if ( ! V_3 )
return;
V_45 = V_3 -> V_45 ;
V_12 = F_2 ( sizeof( struct V_14 ) , V_5 ) ;
if ( ! V_12 ) {
F_33 ( V_45 , L_14 ) ;
return;
}
F_37 ( & V_12 -> V_66 ) ;
F_99 ( & V_12 -> V_15 ) ;
V_12 -> V_28 = F_100 ( V_29 -> V_13 ) ;
V_12 -> V_26 = V_29 ;
F_101 ( & V_29 -> V_27 ) ;
F_14 () ;
if ( F_102 ( V_12 -> V_26 ) ) {
struct V_122 * V_123 ;
V_123 = F_2 ( sizeof( * V_123 ) , V_5 ) ;
if ( ! V_123 )
goto V_124;
V_123 -> V_115 = V_12 ;
F_3 ( V_3 , & V_123 -> V_7 ) ;
} else {
struct V_1 * V_4 ;
V_4 = F_4 ( V_3 ) ;
if ( ! V_4 )
goto V_124;
V_12 -> V_4 = V_4 ;
V_4 -> V_12 = V_12 ;
F_9 ( V_4 -> V_17 . V_18 ) ;
}
F_15 () ;
F_49 ( & V_75 ) ;
F_103 ( & V_12 -> V_76 , & V_125 ) ;
F_51 ( & V_75 ) ;
V_50 = F_104 ( V_126 , V_45 , 1 ,
F_28 , NULL , V_12 , NULL ) ;
if ( F_30 ( V_50 ) ) {
F_33 ( V_45 , L_15 ) ;
F_46 ( V_12 ) ;
F_11 ( V_12 ) ;
}
return;
V_124:
F_15 () ;
F_20 ( & V_29 -> V_27 ) ;
F_21 ( V_12 -> V_28 ) ;
F_8 ( V_12 ) ;
}
static void F_105 ( struct V_14 * V_12 )
{
if ( F_102 ( V_12 -> V_26 ) ) {
struct V_122 * V_123 ;
struct V_2 * V_3 ;
F_14 () ;
V_3 = F_86 ( V_12 -> V_26 -> V_12 ) ;
V_123 = F_92 ( V_3 -> V_7 ) ;
V_3 -> V_7 = NULL ;
F_15 () ;
F_8 ( V_123 ) ;
}
F_46 ( V_12 ) ;
F_11 ( V_12 ) ;
}
void F_106 ( struct V_26 * V_29 )
{
struct V_14 * V_12 ;
if ( V_121 )
return;
F_49 ( & V_75 ) ;
F_36 (bridge, &bridge_list, list)
if ( V_12 -> V_26 == V_29 ) {
F_51 ( & V_75 ) ;
F_105 ( V_12 ) ;
return;
}
F_51 ( & V_75 ) ;
}
int F_107 ( struct V_21 * V_22 )
{
F_93 () ;
if ( V_22 -> V_59 & V_74 )
return - V_127 ;
if ( ! ( V_22 -> V_59 & V_73 ) )
F_64 ( V_22 ) ;
F_94 () ;
return 0 ;
}
static int F_97 ( struct V_21 * V_22 )
{
struct V_24 * V_17 ;
if ( V_22 -> V_59 & V_74 )
return - V_127 ;
F_76 ( V_22 ) ;
F_36 (func, &slot->funcs, sibling)
if ( V_17 -> V_59 & V_60 ) {
T_2 V_45 = F_56 ( V_17 ) ;
if ( F_30 ( F_108 ( V_45 ) ) )
F_33 ( V_45 , L_16 ) ;
break;
}
return 0 ;
}
int F_109 ( struct V_21 * V_22 )
{
int V_128 ;
F_110 () ;
F_93 () ;
V_128 = F_97 ( V_22 ) ;
F_94 () ;
F_111 () ;
return V_128 ;
}
T_4 F_112 ( struct V_21 * V_22 )
{
return ( V_22 -> V_59 & V_73 ) ;
}
T_4 F_113 ( struct V_21 * V_22 )
{
return ! ( F_81 ( V_22 ) & V_129 ) ;
}
T_4 F_114 ( struct V_21 * V_22 )
{
return ! ! F_81 ( V_22 ) ;
}
