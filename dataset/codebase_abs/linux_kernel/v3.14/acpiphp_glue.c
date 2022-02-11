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
static void F_27 ( T_1 V_1 , T_3 type , void * V_7 )
{
struct V_3 * V_2 ;
F_17 ( & V_19 ) ;
V_2 = F_7 ( V_1 ) ;
if ( ! V_2 || F_11 ( V_2 -> V_1 != V_1 )
|| V_2 -> V_17 . V_20 -> V_34 ) {
F_23 ( & V_19 ) ;
return;
}
F_13 ( V_2 -> V_17 . V_20 ) ;
F_10 ( V_2 ) ;
F_23 ( & V_19 ) ;
F_28 ( V_1 , type , V_7 ) ;
F_15 ( V_2 -> V_17 . V_20 ) ;
}
static bool F_29 ( struct V_23 * V_35 )
{
T_3 V_36 ;
T_1 V_18 ;
struct V_37 * V_38 ;
if ( F_30 ( V_35 , V_39 , & V_36 ) )
return false ;
if ( ! ( V_36 & V_40 ) )
return false ;
V_18 = F_31 ( V_35 ) ;
if ( ! V_18 )
return false ;
V_38 = F_32 ( V_18 ) ;
if ( ! V_38 )
return false ;
if ( ! ( V_38 -> V_41 & V_42 ) )
return false ;
return true ;
}
static void F_33 ( void * V_7 )
{
struct V_3 * V_2 = V_7 ;
F_13 ( V_2 -> V_17 . V_20 ) ;
}
static void F_34 ( void * V_7 )
{
struct V_3 * V_2 = V_7 ;
F_15 ( V_2 -> V_17 . V_20 ) ;
}
static T_2 F_35 ( T_1 V_1 , T_3 V_43 , void * V_7 ,
void * * V_44 )
{
struct V_9 * V_8 = V_7 ;
struct V_3 * V_2 ;
struct V_13 * V_14 ;
struct V_16 * V_45 ;
T_2 V_4 = V_46 ;
unsigned long long V_47 ;
int V_48 , V_49 ;
struct V_21 * V_50 = V_8 -> V_21 ;
struct V_23 * V_35 = V_8 -> V_23 ;
T_3 V_51 ;
if ( V_35 && F_29 ( V_35 ) )
return V_46 ;
V_4 = F_36 ( V_1 , L_1 , NULL , & V_47 ) ;
if ( F_5 ( V_4 ) ) {
if ( V_4 != V_52 )
F_37 ( V_1 ,
L_2 , V_4 ) ;
return V_46 ;
}
V_48 = ( V_47 >> 16 ) & 0xffff ;
V_49 = V_47 & 0xffff ;
F_17 ( & V_19 ) ;
V_2 = F_2 ( V_1 ) ;
if ( ! V_2 ) {
F_23 ( & V_19 ) ;
F_38 ( V_1 , L_3 ) ;
return V_53 ;
}
V_45 = & V_2 -> V_17 ;
V_45 -> V_49 = V_49 ;
V_45 -> V_20 = V_8 ;
F_23 ( & V_19 ) ;
if ( F_39 ( V_1 , L_4 ) )
V_45 -> V_54 = V_55 ;
if ( F_39 ( V_1 , L_5 ) )
V_45 -> V_54 |= V_56 ;
if ( F_39 ( V_1 , L_6 ) )
V_45 -> V_54 |= V_57 ;
F_40 (slot, &bridge->slots, node)
if ( V_14 -> V_48 == V_48 )
goto V_58;
V_14 = F_3 ( sizeof( struct V_13 ) , V_5 ) ;
if ( ! V_14 ) {
V_4 = V_59 ;
goto V_60;
}
V_14 -> V_26 = V_8 -> V_21 ;
V_14 -> V_48 = V_48 ;
F_41 ( & V_14 -> V_61 ) ;
F_42 ( & V_14 -> V_62 ) ;
F_43 ( & V_14 -> V_63 , & V_8 -> V_64 ) ;
if ( F_44 ( V_50 , V_1 ) || F_45 ( V_1 ) ) {
unsigned long long V_65 ;
int V_66 ;
V_8 -> V_67 ++ ;
V_4 = F_36 ( V_1 , L_7 , NULL , & V_65 ) ;
if ( F_5 ( V_4 ) )
V_65 = V_8 -> V_67 ;
F_46 ( L_8 ,
V_65 , F_47 ( V_50 ) , V_50 -> V_68 , V_48 ) ;
V_66 = F_48 ( V_14 , V_65 ) ;
if ( V_66 ) {
V_14 -> V_14 = NULL ;
V_8 -> V_67 -- ;
if ( V_66 == - V_69 )
F_49 ( L_9
L_10 , V_65 ) ;
else
F_49 ( L_11
L_12 , V_66 ) ;
}
}
V_58:
V_45 -> V_14 = V_14 ;
F_43 ( & V_45 -> V_70 , & V_14 -> V_61 ) ;
if ( F_50 ( V_50 , F_51 ( V_48 , V_49 ) ,
& V_51 , 60 * 1000 ) )
V_14 -> V_54 |= V_71 ;
if ( F_45 ( V_1 ) ) {
V_45 -> V_54 &= ~ V_55 ;
if ( F_52 ( V_1 ,
& V_72 , V_2 ,
F_33 , F_34 ) )
F_46 ( L_13 ) ;
}
if ( ! ( V_45 -> V_54 & V_57 ) ) {
V_4 = F_53 ( V_1 , V_73 ,
V_74 ,
V_2 ) ;
if ( F_5 ( V_4 ) )
F_38 ( V_1 ,
L_14 ) ;
}
return V_46 ;
V_60:
F_17 ( & V_19 ) ;
F_10 ( V_2 ) ;
F_23 ( & V_19 ) ;
return V_4 ;
}
static struct V_9 * F_54 ( T_1 V_1 )
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
static void F_55 ( struct V_9 * V_8 )
{
struct V_13 * V_14 ;
struct V_16 * V_17 ;
T_2 V_4 ;
F_40 (slot, &bridge->slots, node) {
F_40 (func, &slot->funcs, sibling) {
T_1 V_1 = F_56 ( V_17 ) ;
if ( F_45 ( V_1 ) )
F_57 ( V_1 ) ;
if ( ! ( V_17 -> V_54 & V_57 ) ) {
V_4 = F_58 ( V_1 ,
V_73 ,
V_74 ) ;
if ( F_5 ( V_4 ) )
F_59 ( L_15 ) ;
}
}
V_14 -> V_54 |= V_75 ;
if ( V_14 -> V_14 )
F_60 ( V_14 ) ;
}
F_17 ( & V_76 ) ;
F_61 ( & V_8 -> V_77 ) ;
F_23 ( & V_76 ) ;
F_17 ( & V_19 ) ;
V_8 -> V_34 = true ;
F_23 ( & V_19 ) ;
}
static unsigned char F_62 ( struct V_21 * V_26 )
{
struct V_78 * V_18 ;
unsigned char V_79 , V_80 ;
V_79 = V_26 -> V_30 . V_31 ;
F_63 (tmp, &bus->children) {
V_80 = F_64 ( F_65 ( V_18 ) ) ;
if ( V_80 > V_79 )
V_79 = V_80 ;
}
return V_79 ;
}
static void F_66 ( T_1 V_1 )
{
struct V_81 * V_82 = NULL ;
F_67 ( V_1 , & V_82 ) ;
if ( V_82 )
F_68 ( V_82 ) ;
}
static void F_69 ( T_1 V_1 )
{
struct V_81 * V_82 = NULL ;
F_70 ( V_1 ) ;
F_67 ( V_1 , & V_82 ) ;
if ( F_71 ( V_82 ) )
F_72 ( V_82 , V_83 ) ;
}
static void F_73 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
union V_84 V_85 [ 2 ] ;
struct V_86 V_87 ;
F_40 (func, &slot->funcs, sibling) {
V_87 . V_88 = 2 ;
V_87 . V_89 = V_85 ;
V_85 [ 0 ] . type = V_90 ;
V_85 [ 0 ] . integer . V_91 = V_92 ;
V_85 [ 1 ] . type = V_90 ;
V_85 [ 1 ] . integer . V_91 = 1 ;
F_74 ( F_56 ( V_17 ) , L_16 , & V_87 ,
NULL ) ;
}
}
static void F_75 ( struct V_13 * V_14 , struct V_23 * V_22 )
{
struct V_16 * V_17 ;
if ( V_22 -> V_93 )
return;
F_40 (func, &slot->funcs, sibling) {
if ( F_76 ( V_22 -> V_94 ) == V_17 -> V_49 ) {
V_22 -> V_93 = 1 ;
break;
}
}
}
static int F_77 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
F_40 (func, &slot->funcs, sibling)
F_69 ( F_56 ( V_17 ) ) ;
return F_78 ( V_14 -> V_26 , F_51 ( V_14 -> V_48 , 0 ) ) ;
}
static void T_4 F_79 ( struct V_13 * V_14 )
{
struct V_23 * V_22 ;
struct V_21 * V_26 = V_14 -> V_26 ;
struct V_16 * V_17 ;
int V_79 , V_95 ;
F_80 ( V_96 ) ;
F_77 ( V_14 ) ;
V_79 = F_62 ( V_26 ) ;
for ( V_95 = 0 ; V_95 < 2 ; V_95 ++ ) {
F_40 (dev, &bus->devices, bus_list) {
if ( F_81 ( V_22 -> V_94 ) != V_14 -> V_48 )
continue;
if ( V_22 -> V_97 == V_98 ||
V_22 -> V_97 == V_99 ) {
V_79 = F_82 ( V_26 , V_22 , V_79 , V_95 ) ;
if ( V_95 && V_22 -> V_100 ) {
F_75 ( V_14 , V_22 ) ;
F_83 ( V_22 -> V_100 ) ;
F_84 ( V_22 -> V_100 ,
& V_96 ) ;
}
}
}
}
F_85 ( V_26 , & V_96 , NULL ) ;
F_86 ( V_26 ) ;
F_87 ( V_26 ) ;
F_73 ( V_14 ) ;
F_40 (dev, &bus->devices, bus_list) {
if ( ! V_22 -> V_101 )
V_22 -> V_102 = V_103 ;
}
F_88 ( V_26 ) ;
V_14 -> V_54 |= V_71 ;
F_40 (func, &slot->funcs, sibling) {
V_22 = F_89 ( V_26 , F_51 ( V_14 -> V_48 ,
V_17 -> V_49 ) ) ;
if ( ! V_22 ) {
V_14 -> V_54 &= ( ~ V_71 ) ;
continue;
}
}
}
static struct V_23 * F_90 ( struct V_13 * V_14 )
{
struct V_21 * V_26 = V_14 -> V_26 ;
struct V_23 * V_22 ;
struct V_23 * V_104 = NULL ;
F_91 ( & V_105 ) ;
F_40 (dev, &bus->devices, bus_list)
if ( F_81 ( V_22 -> V_94 ) == V_14 -> V_48 ) {
V_104 = F_92 ( V_22 ) ;
break;
}
F_93 ( & V_105 ) ;
return V_104 ;
}
static void F_94 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
struct V_23 * V_35 ;
while ( ( V_35 = F_90 ( V_14 ) ) ) {
F_95 ( V_35 ) ;
F_22 ( V_35 ) ;
}
F_40 (func, &slot->funcs, sibling)
F_66 ( F_56 ( V_17 ) ) ;
V_14 -> V_54 &= ( ~ V_71 ) ;
}
static bool F_96 ( T_1 V_1 )
{
struct V_81 * V_82 = NULL ;
F_67 ( V_1 , & V_82 ) ;
return V_82 && V_82 -> V_54 . V_106 ;
}
static bool F_97 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
F_40 (func, &slot->funcs, sibling)
if ( F_96 ( F_56 ( V_17 ) ) )
return true ;
return false ;
}
static unsigned int F_98 ( struct V_13 * V_14 )
{
unsigned long long V_107 = 0 ;
struct V_16 * V_17 ;
F_40 (func, &slot->funcs, sibling) {
if ( V_17 -> V_54 & V_56 ) {
T_2 V_4 ;
V_4 = F_36 ( F_56 ( V_17 ) ,
L_5 , NULL , & V_107 ) ;
if ( F_9 ( V_4 ) && V_107 )
break;
} else {
T_3 V_108 ;
F_99 ( V_14 -> V_26 ,
F_51 ( V_14 -> V_48 ,
V_17 -> V_49 ) ,
V_109 , & V_108 ) ;
if ( V_108 != 0xffffffff ) {
V_107 = V_110 ;
break;
}
}
}
return ( unsigned int ) V_107 ;
}
static inline bool F_100 ( unsigned int V_107 )
{
unsigned int V_111 = V_112 | V_113 ;
return ( V_107 & V_111 ) == V_111 ;
}
static void F_101 ( struct V_23 * V_22 )
{
T_1 V_1 = F_102 ( & V_22 -> V_22 ) ;
struct V_21 * V_26 = V_22 -> V_100 ;
bool V_114 = false ;
if ( V_1 ) {
T_2 V_4 ;
unsigned long long V_107 ;
V_4 = F_36 ( V_1 , L_5 , NULL , & V_107 ) ;
V_114 = ( F_9 ( V_4 ) && F_100 ( V_107 ) )
|| F_96 ( V_1 ) ;
}
if ( ! V_114 ) {
T_3 V_115 ;
V_114 = F_50 ( V_22 -> V_26 , V_22 -> V_94 , & V_115 , 0 ) ;
}
if ( ! V_114 ) {
F_95 ( V_22 ) ;
if ( V_1 )
F_66 ( V_1 ) ;
} else if ( V_26 ) {
struct V_23 * V_116 , * V_18 ;
F_103 ( & V_22 -> V_22 ) ;
F_104 (child, tmp, &bus->devices, bus_list)
F_101 ( V_116 ) ;
F_105 ( & V_22 -> V_22 ) ;
}
}
static void F_106 ( struct V_9 * V_8 )
{
struct V_13 * V_14 ;
if ( V_8 -> V_34 )
return;
F_40 (slot, &bridge->slots, node) {
struct V_21 * V_26 = V_14 -> V_26 ;
struct V_23 * V_22 , * V_18 ;
F_17 ( & V_14 -> V_62 ) ;
if ( F_97 ( V_14 ) ) {
;
} else if ( F_100 ( F_98 ( V_14 ) ) ) {
F_104 (dev, tmp,
&bus->devices, bus_list)
if ( F_81 ( V_22 -> V_94 ) == V_14 -> V_48 )
F_101 ( V_22 ) ;
F_79 ( V_14 ) ;
} else {
F_94 ( V_14 ) ;
}
F_23 ( & V_14 -> V_62 ) ;
}
}
static void F_87 ( struct V_21 * V_26 )
{
struct V_23 * V_22 ;
F_40 (dev, &bus->devices, bus_list)
F_107 ( V_22 ) ;
}
static void F_86 ( struct V_21 * V_26 )
{
struct V_23 * V_22 , * V_18 ;
int V_117 ;
unsigned long V_118 = V_119 | V_120 ;
F_104 (dev, tmp, &bus->devices, bus_list) {
for ( V_117 = 0 ; V_117 < V_121 ; V_117 ++ ) {
struct V_122 * V_123 = & V_22 -> V_122 [ V_117 ] ;
if ( ( V_123 -> V_54 & V_118 ) && ! V_123 -> V_31 &&
V_123 -> V_33 ) {
F_95 ( V_22 ) ;
break;
}
}
}
}
void F_108 ( T_1 V_1 )
{
struct V_9 * V_8 ;
V_8 = F_54 ( V_1 ) ;
if ( V_8 ) {
F_109 () ;
F_106 ( V_8 ) ;
F_110 () ;
F_15 ( V_8 ) ;
}
}
static void F_28 ( T_1 V_1 , T_3 type , void * V_7 )
{
struct V_3 * V_2 = V_7 ;
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_9 * V_8 ;
char V_124 [ 64 ] ;
struct V_125 V_126 = { . V_127 = sizeof( V_124 ) ,
. V_89 = V_124 } ;
F_17 ( & V_19 ) ;
V_8 = V_2 -> V_8 ;
if ( V_8 )
F_13 ( V_8 ) ;
F_23 ( & V_19 ) ;
F_109 () ;
F_111 ( V_1 , V_128 , & V_126 ) ;
switch ( type ) {
case V_129 :
F_46 ( L_17 , V_130 , V_124 ) ;
F_46 ( L_18 ,
V_130 , V_124 ) ;
if ( V_8 ) {
F_106 ( V_8 ) ;
} else {
struct V_13 * V_14 = V_17 -> V_14 ;
if ( V_14 -> V_54 & V_75 )
break;
F_17 ( & V_14 -> V_62 ) ;
F_79 ( V_14 ) ;
F_23 ( & V_14 -> V_62 ) ;
}
break;
case V_131 :
F_46 ( L_19 , V_130 , V_124 ) ;
if ( V_8 ) {
F_106 ( V_8 ) ;
} else {
struct V_13 * V_14 = V_17 -> V_14 ;
int V_104 ;
if ( V_14 -> V_54 & V_75 )
break;
F_17 ( & V_14 -> V_62 ) ;
V_104 = F_77 ( V_14 ) ;
F_23 ( & V_14 -> V_62 ) ;
if ( V_104 )
F_106 ( V_17 -> V_20 ) ;
}
break;
case V_132 :
F_46 ( L_20 , V_130 , V_124 ) ;
F_112 ( V_17 -> V_14 ) ;
break;
}
F_110 () ;
if ( V_8 )
F_15 ( V_8 ) ;
}
static void F_113 ( void * V_7 , T_3 type )
{
struct V_3 * V_2 = V_7 ;
T_1 V_1 = V_2 -> V_1 ;
F_114 () ;
F_28 ( V_1 , type , V_2 ) ;
F_115 () ;
F_116 ( V_1 , type , V_133 , NULL ) ;
F_15 ( V_2 -> V_17 . V_20 ) ;
}
static void V_74 ( T_1 V_1 , T_3 type , void * V_7 )
{
struct V_3 * V_2 ;
T_3 V_134 = V_133 ;
T_2 V_4 ;
switch ( type ) {
case V_129 :
case V_131 :
break;
case V_132 :
V_134 = V_135 ;
F_116 ( V_1 , type , V_134 , NULL ) ;
break;
case V_136 :
return;
case V_137 :
F_38 ( V_1 , L_21
L_22 ) ;
goto V_138;
case V_139 :
F_38 ( V_1 , L_21
L_23 ) ;
goto V_138;
case V_140 :
F_38 ( V_1 , L_24 ) ;
goto V_138;
default:
F_37 ( V_1 , L_25 , type ) ;
V_134 = V_141 ;
goto V_138;
}
F_17 ( & V_19 ) ;
V_2 = F_7 ( V_1 ) ;
if ( ! V_2 || F_11 ( V_2 -> V_1 != V_1 )
|| V_2 -> V_17 . V_20 -> V_34 )
goto V_142;
F_13 ( V_2 -> V_17 . V_20 ) ;
F_10 ( V_2 ) ;
V_4 = F_117 ( F_113 , V_2 , type ) ;
if ( F_9 ( V_4 ) ) {
F_23 ( & V_19 ) ;
return;
}
F_15 ( V_2 -> V_17 . V_20 ) ;
V_142:
F_23 ( & V_19 ) ;
V_134 = V_143 ;
V_138:
F_116 ( V_1 , type , V_134 , NULL ) ;
}
void F_118 ( struct V_21 * V_26 )
{
struct V_9 * V_8 ;
T_1 V_1 ;
T_2 V_4 ;
if ( V_144 )
return;
V_1 = F_102 ( V_26 -> V_8 ) ;
if ( ! V_1 )
return;
V_8 = F_3 ( sizeof( struct V_9 ) , V_5 ) ;
if ( ! V_8 ) {
F_38 ( V_1 , L_26 ) ;
return;
}
F_41 ( & V_8 -> V_64 ) ;
F_119 ( & V_8 -> V_10 ) ;
V_8 -> V_23 = F_92 ( V_26 -> V_28 ) ;
V_8 -> V_21 = V_26 ;
F_120 ( & V_26 -> V_22 ) ;
if ( ! F_121 ( V_8 -> V_21 ) ) {
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
F_17 ( & V_76 ) ;
F_122 ( & V_8 -> V_77 , & V_145 ) ;
F_23 ( & V_76 ) ;
V_4 = F_123 ( V_146 , V_1 , 1 ,
F_35 , NULL , V_8 , NULL ) ;
if ( F_5 ( V_4 ) ) {
F_38 ( V_1 , L_27 ) ;
F_55 ( V_8 ) ;
F_15 ( V_8 ) ;
}
}
void F_124 ( struct V_21 * V_26 )
{
struct V_9 * V_8 ;
if ( V_144 )
return;
F_17 ( & V_76 ) ;
F_40 (bridge, &bridge_list, list)
if ( V_8 -> V_21 == V_26 ) {
F_23 ( & V_76 ) ;
F_55 ( V_8 ) ;
F_15 ( V_8 ) ;
return;
}
F_23 ( & V_76 ) ;
}
int F_125 ( struct V_13 * V_14 )
{
F_109 () ;
if ( V_14 -> V_54 & V_75 )
return - V_147 ;
F_17 ( & V_14 -> V_62 ) ;
if ( ! ( V_14 -> V_54 & V_71 ) )
F_79 ( V_14 ) ;
F_23 ( & V_14 -> V_62 ) ;
F_110 () ;
return 0 ;
}
static int F_112 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
if ( V_14 -> V_54 & V_75 )
return - V_147 ;
F_17 ( & V_14 -> V_62 ) ;
F_94 ( V_14 ) ;
F_40 (func, &slot->funcs, sibling)
if ( V_17 -> V_54 & V_55 ) {
T_1 V_1 = F_56 ( V_17 ) ;
if ( F_5 ( F_126 ( V_1 ) ) )
F_38 ( V_1 , L_28 ) ;
break;
}
F_23 ( & V_14 -> V_62 ) ;
return 0 ;
}
int F_127 ( struct V_13 * V_14 )
{
int V_104 ;
F_109 () ;
V_104 = F_112 ( V_14 ) ;
F_110 () ;
return V_104 ;
}
T_5 F_128 ( struct V_13 * V_14 )
{
return ( V_14 -> V_54 & V_71 ) ;
}
T_5 F_129 ( struct V_13 * V_14 )
{
return ! ( F_98 ( V_14 ) & V_148 ) ;
}
T_5 F_130 ( struct V_13 * V_14 )
{
return ! ! F_98 ( V_14 ) ;
}
