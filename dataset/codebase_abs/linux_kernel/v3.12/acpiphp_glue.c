static void F_1 ( T_1 V_1 , void * V_2 )
{
}
static struct V_3 * F_2 ( T_1 V_1 )
{
struct V_3 * V_2 ;
T_2 V_4 ;
V_2 = F_3 ( sizeof( * V_2 ) , V_5 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_1 = V_1 ;
V_2 -> V_6 = 1 ;
V_4 = F_4 ( V_1 , F_1 , V_2 ) ;
if ( F_5 ( V_4 ) ) {
F_6 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_3 * F_7 ( T_1 V_1 )
{
struct V_3 * V_2 = NULL ;
T_2 V_4 ;
void * V_7 ;
V_4 = F_8 ( V_1 , F_1 , & V_7 ) ;
if ( F_9 ( V_4 ) ) {
V_2 = V_7 ;
V_2 -> V_6 ++ ;
}
return V_2 ;
}
static void F_10 ( struct V_3 * V_2 )
{
if ( -- V_2 -> V_6 )
return;
F_11 ( V_2 -> V_8 ) ;
F_12 ( V_2 -> V_1 , F_1 ) ;
F_6 ( V_2 ) ;
}
static inline void F_13 ( struct V_9 * V_8 )
{
F_14 ( & V_8 -> V_10 ) ;
}
static inline void F_15 ( struct V_9 * V_8 )
{
F_16 ( & V_8 -> V_10 , V_11 ) ;
}
static void V_11 ( struct V_12 * V_12 )
{
struct V_3 * V_2 ;
struct V_9 * V_8 ;
struct V_13 * V_14 , * V_15 ;
struct V_16 * V_17 , * V_18 ;
F_17 ( & V_19 ) ;
V_8 = F_18 ( V_12 , struct V_9 , V_10 ) ;
F_19 (slot, next, &bridge->slots, node) {
F_19 (func, tmp, &slot->funcs, sibling)
F_10 ( F_20 ( V_17 ) ) ;
F_6 ( V_14 ) ;
}
V_2 = V_8 -> V_2 ;
if ( V_2 ) {
F_15 ( V_2 -> V_17 . V_20 ) ;
V_2 -> V_8 = NULL ;
F_10 ( V_2 ) ;
}
F_21 ( & V_8 -> V_21 -> V_22 ) ;
F_22 ( V_8 -> V_23 ) ;
F_6 ( V_8 ) ;
F_23 ( & V_19 ) ;
}
static void F_24 ( T_1 V_24 , T_3 V_25 , void * V_7 )
{
struct V_3 * V_2 = V_7 ;
struct V_21 * V_26 = V_2 -> V_17 . V_14 -> V_26 ;
T_3 V_27 ;
if ( ! V_26 -> V_28 )
return;
F_25 ( V_26 -> V_28 ,
V_29 ,
& V_27 ) ;
if ( ( ( V_27 >> 8 ) & 0xff ) != V_26 -> V_30 . V_31 ) {
V_27 = ( V_27 & 0xff000000 )
| ( ( unsigned int ) ( V_26 -> V_32 ) << 0 )
| ( ( unsigned int ) ( V_26 -> V_30 . V_31 ) << 8 )
| ( ( unsigned int ) ( V_26 -> V_30 . V_33 ) << 16 ) ;
F_26 ( V_26 -> V_28 , V_29 , V_27 ) ;
}
}
static bool F_27 ( struct V_23 * V_34 )
{
T_3 V_35 ;
T_1 V_18 ;
struct V_36 * V_37 ;
if ( F_28 ( V_34 , V_38 , & V_35 ) )
return false ;
if ( ! ( V_35 & V_39 ) )
return false ;
V_18 = F_29 ( V_34 ) ;
if ( ! V_18 )
return false ;
V_37 = F_30 ( V_18 ) ;
if ( ! V_37 )
return false ;
if ( ! ( V_37 -> V_40 & V_41 ) )
return false ;
return true ;
}
static void F_31 ( void * V_7 )
{
struct V_3 * V_2 = V_7 ;
F_13 ( V_2 -> V_17 . V_20 ) ;
}
static void F_32 ( void * V_7 )
{
struct V_3 * V_2 = V_7 ;
F_15 ( V_2 -> V_17 . V_20 ) ;
}
static T_2 F_33 ( T_1 V_1 , T_3 V_42 , void * V_7 ,
void * * V_43 )
{
struct V_9 * V_8 = V_7 ;
struct V_3 * V_2 ;
struct V_13 * V_14 ;
struct V_16 * V_44 ;
T_2 V_4 = V_45 ;
unsigned long long V_46 ;
int V_47 , V_48 ;
struct V_21 * V_49 = V_8 -> V_21 ;
struct V_23 * V_34 = V_8 -> V_23 ;
T_3 V_50 ;
if ( V_34 && F_27 ( V_34 ) )
return V_45 ;
V_4 = F_34 ( V_1 , L_1 , NULL , & V_46 ) ;
if ( F_5 ( V_4 ) ) {
F_35 ( V_1 , L_2 , V_4 ) ;
return V_45 ;
}
V_47 = ( V_46 >> 16 ) & 0xffff ;
V_48 = V_46 & 0xffff ;
F_17 ( & V_19 ) ;
V_2 = F_2 ( V_1 ) ;
if ( ! V_2 ) {
F_23 ( & V_19 ) ;
F_36 ( V_1 , L_3 ) ;
return V_51 ;
}
V_44 = & V_2 -> V_17 ;
V_44 -> V_48 = V_48 ;
V_44 -> V_20 = V_8 ;
F_23 ( & V_19 ) ;
if ( F_37 ( V_1 , L_4 ) )
V_44 -> V_52 = V_53 ;
if ( F_37 ( V_1 , L_5 ) )
V_44 -> V_52 |= V_54 ;
if ( F_37 ( V_1 , L_6 ) )
V_44 -> V_52 |= V_55 ;
F_38 (slot, &bridge->slots, node)
if ( V_14 -> V_47 == V_47 )
goto V_56;
V_14 = F_3 ( sizeof( struct V_13 ) , V_5 ) ;
if ( ! V_14 ) {
V_4 = V_57 ;
goto V_58;
}
V_14 -> V_26 = V_8 -> V_21 ;
V_14 -> V_47 = V_47 ;
F_39 ( & V_14 -> V_59 ) ;
F_40 ( & V_14 -> V_60 ) ;
F_41 ( & V_14 -> V_61 , & V_8 -> V_62 ) ;
if ( F_42 ( V_49 , V_1 ) || F_43 ( V_1 ) ) {
unsigned long long V_63 ;
int V_64 ;
V_8 -> V_65 ++ ;
V_4 = F_34 ( V_1 , L_7 , NULL , & V_63 ) ;
if ( F_5 ( V_4 ) )
V_63 = V_8 -> V_65 ;
F_44 ( L_8 ,
V_63 , F_45 ( V_49 ) , V_49 -> V_66 , V_47 ) ;
V_64 = F_46 ( V_14 , V_63 ) ;
if ( V_64 ) {
V_14 -> V_14 = NULL ;
V_8 -> V_65 -- ;
if ( V_64 == - V_67 )
F_47 ( L_9
L_10 , V_63 ) ;
else
F_47 ( L_11
L_12 , V_64 ) ;
}
}
V_56:
V_44 -> V_14 = V_14 ;
F_41 ( & V_44 -> V_68 , & V_14 -> V_59 ) ;
if ( F_48 ( V_49 , F_49 ( V_47 , V_48 ) ,
& V_50 , 60 * 1000 ) )
V_14 -> V_52 |= V_69 ;
if ( F_43 ( V_1 ) ) {
V_44 -> V_52 &= ~ V_53 ;
if ( F_50 ( V_1 ,
& V_70 , V_2 ,
F_31 , F_32 ) )
F_44 ( L_13 ) ;
}
if ( ! ( V_44 -> V_52 & V_55 ) ) {
V_4 = F_51 ( V_1 , V_71 ,
V_72 ,
V_2 ) ;
if ( F_5 ( V_4 ) )
F_36 ( V_1 ,
L_14 ) ;
}
return V_45 ;
V_58:
F_17 ( & V_19 ) ;
F_10 ( V_2 ) ;
F_23 ( & V_19 ) ;
return V_4 ;
}
static struct V_9 * F_52 ( T_1 V_1 )
{
struct V_3 * V_2 ;
struct V_9 * V_8 = NULL ;
F_17 ( & V_19 ) ;
V_2 = F_7 ( V_1 ) ;
if ( V_2 ) {
V_8 = V_2 -> V_8 ;
if ( V_8 )
F_13 ( V_8 ) ;
F_10 ( V_2 ) ;
}
F_23 ( & V_19 ) ;
return V_8 ;
}
static void F_53 ( struct V_9 * V_8 )
{
struct V_13 * V_14 ;
struct V_16 * V_17 ;
T_2 V_4 ;
F_38 (slot, &bridge->slots, node) {
F_38 (func, &slot->funcs, sibling) {
T_1 V_1 = F_54 ( V_17 ) ;
if ( F_43 ( V_1 ) )
F_55 ( V_1 ) ;
if ( ! ( V_17 -> V_52 & V_55 ) ) {
V_4 = F_56 ( V_1 ,
V_71 ,
V_72 ) ;
if ( F_5 ( V_4 ) )
V_58 ( L_15 ) ;
}
}
if ( V_14 -> V_14 )
F_57 ( V_14 ) ;
}
F_17 ( & V_73 ) ;
F_58 ( & V_8 -> V_74 ) ;
F_23 ( & V_73 ) ;
}
static unsigned char F_59 ( struct V_21 * V_26 )
{
struct V_75 * V_18 ;
unsigned char V_76 , V_77 ;
V_76 = V_26 -> V_30 . V_31 ;
F_60 (tmp, &bus->children) {
V_77 = F_61 ( F_62 ( V_18 ) ) ;
if ( V_77 > V_76 )
V_76 = V_77 ;
}
return V_76 ;
}
static void F_63 ( T_1 V_1 )
{
struct V_78 * V_79 = NULL ;
F_64 ( V_1 , & V_79 ) ;
if ( V_79 )
F_65 ( V_79 ) ;
}
static void F_66 ( T_1 V_1 )
{
struct V_78 * V_79 = NULL ;
F_67 ( V_1 ) ;
F_64 ( V_1 , & V_79 ) ;
if ( V_79 )
F_68 ( V_79 , V_80 ) ;
}
static void F_69 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
union V_81 V_82 [ 2 ] ;
struct V_83 V_84 ;
F_38 (func, &slot->funcs, sibling) {
V_84 . V_85 = 2 ;
V_84 . V_86 = V_82 ;
V_82 [ 0 ] . type = V_87 ;
V_82 [ 0 ] . integer . V_88 = V_89 ;
V_82 [ 1 ] . type = V_87 ;
V_82 [ 1 ] . integer . V_88 = 1 ;
F_70 ( F_54 ( V_17 ) , L_16 , & V_84 ,
NULL ) ;
}
}
static void F_71 ( struct V_13 * V_14 , struct V_23 * V_22 )
{
struct V_16 * V_17 ;
if ( V_22 -> V_90 )
return;
F_38 (func, &slot->funcs, sibling) {
if ( F_72 ( V_22 -> V_91 ) == V_17 -> V_48 ) {
V_22 -> V_90 = 1 ;
break;
}
}
}
static int F_73 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
F_38 (func, &slot->funcs, sibling)
F_66 ( F_54 ( V_17 ) ) ;
return F_74 ( V_14 -> V_26 , F_49 ( V_14 -> V_47 , 0 ) ) ;
}
static void T_4 F_75 ( struct V_13 * V_14 )
{
struct V_23 * V_22 ;
struct V_21 * V_26 = V_14 -> V_26 ;
struct V_16 * V_17 ;
int V_76 , V_92 ;
F_76 ( V_93 ) ;
F_73 ( V_14 ) ;
V_76 = F_59 ( V_26 ) ;
for ( V_92 = 0 ; V_92 < 2 ; V_92 ++ ) {
F_38 (dev, &bus->devices, bus_list) {
if ( F_77 ( V_22 -> V_91 ) != V_14 -> V_47 )
continue;
if ( V_22 -> V_94 == V_95 ||
V_22 -> V_94 == V_96 ) {
V_76 = F_78 ( V_26 , V_22 , V_76 , V_92 ) ;
if ( V_92 && V_22 -> V_97 ) {
F_71 ( V_14 , V_22 ) ;
F_79 ( V_22 -> V_97 ) ;
F_80 ( V_22 -> V_97 ,
& V_93 ) ;
}
}
}
}
F_81 ( V_26 , & V_93 , NULL ) ;
F_82 ( V_26 ) ;
F_83 ( V_26 ) ;
F_69 ( V_14 ) ;
F_38 (dev, &bus->devices, bus_list) {
if ( ! V_22 -> V_98 )
V_22 -> V_99 = V_100 ;
}
F_84 ( V_26 ) ;
V_14 -> V_52 |= V_69 ;
F_38 (func, &slot->funcs, sibling) {
V_22 = F_85 ( V_26 , F_49 ( V_14 -> V_47 ,
V_17 -> V_48 ) ) ;
if ( ! V_22 ) {
V_14 -> V_52 &= ( ~ V_69 ) ;
continue;
}
}
}
static struct V_23 * F_86 ( struct V_13 * V_14 )
{
struct V_21 * V_26 = V_14 -> V_26 ;
struct V_23 * V_22 ;
struct V_23 * V_101 = NULL ;
F_87 ( & V_102 ) ;
F_38 (dev, &bus->devices, bus_list)
if ( F_77 ( V_22 -> V_91 ) == V_14 -> V_47 ) {
V_101 = F_88 ( V_22 ) ;
break;
}
F_89 ( & V_102 ) ;
return V_101 ;
}
static void F_90 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
struct V_23 * V_34 ;
while ( ( V_34 = F_86 ( V_14 ) ) ) {
F_91 ( V_34 ) ;
F_22 ( V_34 ) ;
}
F_38 (func, &slot->funcs, sibling)
F_63 ( F_54 ( V_17 ) ) ;
V_14 -> V_52 &= ( ~ V_69 ) ;
}
static unsigned int F_92 ( struct V_13 * V_14 )
{
unsigned long long V_103 = 0 ;
struct V_16 * V_17 ;
F_38 (func, &slot->funcs, sibling) {
if ( V_17 -> V_52 & V_54 ) {
T_2 V_4 ;
V_4 = F_34 ( F_54 ( V_17 ) ,
L_5 , NULL , & V_103 ) ;
if ( F_9 ( V_4 ) && V_103 )
break;
} else {
T_3 V_104 ;
F_93 ( V_14 -> V_26 ,
F_49 ( V_14 -> V_47 ,
V_17 -> V_48 ) ,
V_105 , & V_104 ) ;
if ( V_104 != 0xffffffff ) {
V_103 = V_106 ;
break;
}
}
}
return ( unsigned int ) V_103 ;
}
static void F_94 ( struct V_23 * V_22 )
{
T_1 V_1 = F_95 ( & V_22 -> V_22 ) ;
struct V_21 * V_26 = V_22 -> V_97 ;
bool V_107 = false ;
if ( V_1 ) {
T_2 V_4 ;
unsigned long long V_103 ;
V_4 = F_34 ( V_1 , L_5 , NULL , & V_103 ) ;
V_107 = F_9 ( V_4 ) && V_103 == V_106 ;
}
if ( ! V_107 ) {
T_3 V_108 ;
V_107 = F_48 ( V_22 -> V_26 , V_22 -> V_91 , & V_108 , 0 ) ;
}
if ( ! V_107 ) {
F_91 ( V_22 ) ;
if ( V_1 )
F_63 ( V_1 ) ;
} else if ( V_26 ) {
struct V_23 * V_109 , * V_18 ;
F_96 ( & V_22 -> V_22 ) ;
F_19 (child, tmp, &bus->devices, bus_list)
F_94 ( V_109 ) ;
F_97 ( & V_22 -> V_22 ) ;
}
}
static void F_98 ( struct V_9 * V_8 )
{
struct V_13 * V_14 ;
F_38 (slot, &bridge->slots, node) {
struct V_21 * V_26 = V_14 -> V_26 ;
struct V_23 * V_22 , * V_18 ;
F_17 ( & V_14 -> V_60 ) ;
if ( F_92 ( V_14 ) == V_106 ) {
F_19 (dev, tmp, &bus->devices,
bus_list)
if ( F_77 ( V_22 -> V_91 ) == V_14 -> V_47 )
F_94 ( V_22 ) ;
F_75 ( V_14 ) ;
} else {
F_90 ( V_14 ) ;
}
F_23 ( & V_14 -> V_60 ) ;
}
}
static void F_83 ( struct V_21 * V_26 )
{
struct V_23 * V_22 ;
F_38 (dev, &bus->devices, bus_list)
F_99 ( V_22 ) ;
}
static void F_82 ( struct V_21 * V_26 )
{
struct V_23 * V_22 , * V_18 ;
int V_110 ;
unsigned long V_111 = V_112 | V_113 ;
F_19 (dev, tmp, &bus->devices, bus_list) {
for ( V_110 = 0 ; V_110 < V_114 ; V_110 ++ ) {
struct V_115 * V_116 = & V_22 -> V_115 [ V_110 ] ;
if ( ( V_116 -> V_52 & V_111 ) && ! V_116 -> V_31 &&
V_116 -> V_33 ) {
F_91 ( V_22 ) ;
break;
}
}
}
}
void F_100 ( T_1 V_1 )
{
struct V_9 * V_8 ;
V_8 = F_52 ( V_1 ) ;
if ( V_8 ) {
F_98 ( V_8 ) ;
F_15 ( V_8 ) ;
}
}
static void F_101 ( T_1 V_1 , T_3 type , void * V_7 )
{
struct V_3 * V_2 = V_7 ;
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_9 * V_8 ;
char V_117 [ 64 ] ;
struct V_118 V_119 = { . V_120 = sizeof( V_117 ) ,
. V_86 = V_117 } ;
F_17 ( & V_19 ) ;
V_8 = V_2 -> V_8 ;
if ( V_8 )
F_13 ( V_8 ) ;
F_23 ( & V_19 ) ;
F_102 ( V_1 , V_121 , & V_119 ) ;
switch ( type ) {
case V_122 :
F_44 ( L_17 , V_123 , V_117 ) ;
F_44 ( L_18 , V_123 , V_117 ) ;
if ( V_8 ) {
F_98 ( V_8 ) ;
} else {
struct V_13 * V_14 = V_17 -> V_14 ;
F_17 ( & V_14 -> V_60 ) ;
F_75 ( V_14 ) ;
F_23 ( & V_14 -> V_60 ) ;
}
break;
case V_124 :
F_44 ( L_19 , V_123 , V_117 ) ;
if ( V_8 ) {
F_98 ( V_8 ) ;
} else {
struct V_13 * V_14 = V_17 -> V_14 ;
int V_101 ;
F_17 ( & V_14 -> V_60 ) ;
V_101 = F_73 ( V_14 ) ;
F_23 ( & V_14 -> V_60 ) ;
if ( V_101 )
F_98 ( V_17 -> V_20 ) ;
}
break;
case V_125 :
F_44 ( L_20 , V_123 , V_117 ) ;
F_103 ( V_17 -> V_14 ) ;
break;
}
if ( V_8 )
F_15 ( V_8 ) ;
}
static void F_104 ( struct V_126 * V_127 )
{
struct V_3 * V_2 ;
struct V_128 * V_129 ;
V_129 = F_18 ( V_127 , struct V_128 , V_127 ) ;
V_2 = V_129 -> V_2 ;
F_105 () ;
F_101 ( V_129 -> V_1 , V_129 -> type , V_2 ) ;
F_106 () ;
F_107 ( V_129 -> V_1 , V_129 -> type ,
V_130 , NULL ) ;
F_6 ( V_129 ) ;
F_15 ( V_2 -> V_17 . V_20 ) ;
}
static void V_72 ( T_1 V_1 , T_3 type , void * V_7 )
{
struct V_3 * V_2 ;
T_3 V_131 = V_130 ;
switch ( type ) {
case V_122 :
case V_124 :
break;
case V_125 :
V_131 = V_132 ;
F_107 ( V_1 , type , V_131 , NULL ) ;
break;
case V_133 :
return;
case V_134 :
F_36 ( V_1 , L_21
L_22 ) ;
goto V_135;
case V_136 :
F_36 ( V_1 , L_21
L_23 ) ;
goto V_135;
case V_137 :
F_36 ( V_1 , L_24 ) ;
goto V_135;
default:
F_35 ( V_1 , L_25 , type ) ;
V_131 = V_138 ;
goto V_135;
}
F_17 ( & V_19 ) ;
V_2 = F_7 ( V_1 ) ;
if ( V_2 ) {
F_13 ( V_2 -> V_17 . V_20 ) ;
F_10 ( V_2 ) ;
F_108 ( V_1 , type , V_2 , F_104 ) ;
F_23 ( & V_19 ) ;
return;
}
F_23 ( & V_19 ) ;
V_131 = V_139 ;
V_135:
F_107 ( V_1 , type , V_131 , NULL ) ;
}
void F_109 ( struct V_21 * V_26 )
{
struct V_9 * V_8 ;
T_1 V_1 ;
T_2 V_4 ;
if ( V_140 )
return;
V_1 = F_95 ( V_26 -> V_8 ) ;
if ( ! V_1 )
return;
V_8 = F_3 ( sizeof( struct V_9 ) , V_5 ) ;
if ( ! V_8 ) {
F_36 ( V_1 , L_26 ) ;
return;
}
F_39 ( & V_8 -> V_62 ) ;
F_110 ( & V_8 -> V_10 ) ;
V_8 -> V_23 = F_88 ( V_26 -> V_28 ) ;
V_8 -> V_21 = V_26 ;
F_111 ( & V_26 -> V_22 ) ;
if ( ! F_112 ( V_8 -> V_21 ) ) {
struct V_3 * V_2 ;
F_17 ( & V_19 ) ;
V_2 = F_7 ( V_1 ) ;
if ( ! V_2 ) {
F_23 ( & V_19 ) ;
F_21 ( & V_26 -> V_22 ) ;
F_22 ( V_8 -> V_23 ) ;
F_6 ( V_8 ) ;
return;
}
V_8 -> V_2 = V_2 ;
V_2 -> V_8 = V_8 ;
F_13 ( V_2 -> V_17 . V_20 ) ;
F_23 ( & V_19 ) ;
}
F_17 ( & V_73 ) ;
F_113 ( & V_8 -> V_74 , & V_141 ) ;
F_23 ( & V_73 ) ;
V_4 = F_114 ( V_142 , V_1 , 1 ,
F_33 , NULL , V_8 , NULL ) ;
if ( F_5 ( V_4 ) ) {
F_36 ( V_1 , L_27 ) ;
F_53 ( V_8 ) ;
F_15 ( V_8 ) ;
}
}
void F_115 ( struct V_21 * V_26 )
{
struct V_9 * V_8 ;
if ( V_140 )
return;
F_17 ( & V_73 ) ;
F_38 (bridge, &bridge_list, list)
if ( V_8 -> V_21 == V_26 ) {
F_23 ( & V_73 ) ;
F_53 ( V_8 ) ;
F_15 ( V_8 ) ;
return;
}
F_23 ( & V_73 ) ;
}
int F_116 ( struct V_13 * V_14 )
{
F_17 ( & V_14 -> V_60 ) ;
if ( ! ( V_14 -> V_52 & V_69 ) )
F_75 ( V_14 ) ;
F_23 ( & V_14 -> V_60 ) ;
return 0 ;
}
int F_103 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
int V_64 = 0 ;
F_17 ( & V_14 -> V_60 ) ;
F_90 ( V_14 ) ;
F_38 (func, &slot->funcs, sibling)
if ( V_17 -> V_52 & V_53 ) {
T_1 V_1 = F_54 ( V_17 ) ;
if ( F_5 ( F_117 ( V_1 ) ) )
F_36 ( V_1 , L_28 ) ;
break;
}
F_23 ( & V_14 -> V_60 ) ;
return V_64 ;
}
T_5 F_118 ( struct V_13 * V_14 )
{
return ( V_14 -> V_52 & V_69 ) ;
}
T_5 F_119 ( struct V_13 * V_14 )
{
return ! ( F_92 ( V_14 ) & V_143 ) ;
}
T_5 F_120 ( struct V_13 * V_14 )
{
return ! ! F_92 ( V_14 ) ;
}
