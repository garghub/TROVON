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
if ( V_4 != V_51 )
F_35 ( V_1 ,
L_2 , V_4 ) ;
return V_45 ;
}
V_47 = ( V_46 >> 16 ) & 0xffff ;
V_48 = V_46 & 0xffff ;
F_17 ( & V_19 ) ;
V_2 = F_2 ( V_1 ) ;
if ( ! V_2 ) {
F_23 ( & V_19 ) ;
F_36 ( V_1 , L_3 ) ;
return V_52 ;
}
V_44 = & V_2 -> V_17 ;
V_44 -> V_48 = V_48 ;
V_44 -> V_20 = V_8 ;
F_23 ( & V_19 ) ;
if ( F_37 ( V_1 , L_4 ) )
V_44 -> V_53 = V_54 ;
if ( F_37 ( V_1 , L_5 ) )
V_44 -> V_53 |= V_55 ;
if ( F_37 ( V_1 , L_6 ) )
V_44 -> V_53 |= V_56 ;
F_38 (slot, &bridge->slots, node)
if ( V_14 -> V_47 == V_47 )
goto V_57;
V_14 = F_3 ( sizeof( struct V_13 ) , V_5 ) ;
if ( ! V_14 ) {
V_4 = V_58 ;
goto V_59;
}
V_14 -> V_26 = V_8 -> V_21 ;
V_14 -> V_47 = V_47 ;
F_39 ( & V_14 -> V_60 ) ;
F_40 ( & V_14 -> V_61 ) ;
F_41 ( & V_14 -> V_62 , & V_8 -> V_63 ) ;
if ( F_42 ( V_49 , V_1 ) || F_43 ( V_1 ) ) {
unsigned long long V_64 ;
int V_65 ;
V_8 -> V_66 ++ ;
V_4 = F_34 ( V_1 , L_7 , NULL , & V_64 ) ;
if ( F_5 ( V_4 ) )
V_64 = V_8 -> V_66 ;
F_44 ( L_8 ,
V_64 , F_45 ( V_49 ) , V_49 -> V_67 , V_47 ) ;
V_65 = F_46 ( V_14 , V_64 ) ;
if ( V_65 ) {
V_14 -> V_14 = NULL ;
V_8 -> V_66 -- ;
if ( V_65 == - V_68 )
F_47 ( L_9
L_10 , V_64 ) ;
else
F_47 ( L_11
L_12 , V_65 ) ;
}
}
V_57:
V_44 -> V_14 = V_14 ;
F_41 ( & V_44 -> V_69 , & V_14 -> V_60 ) ;
if ( F_48 ( V_49 , F_49 ( V_47 , V_48 ) ,
& V_50 , 60 * 1000 ) )
V_14 -> V_53 |= V_70 ;
if ( F_43 ( V_1 ) ) {
V_44 -> V_53 &= ~ V_54 ;
if ( F_50 ( V_1 ,
& V_71 , V_2 ,
F_31 , F_32 ) )
F_44 ( L_13 ) ;
}
if ( ! ( V_44 -> V_53 & V_56 ) ) {
V_4 = F_51 ( V_1 , V_72 ,
V_73 ,
V_2 ) ;
if ( F_5 ( V_4 ) )
F_36 ( V_1 ,
L_14 ) ;
}
return V_45 ;
V_59:
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
if ( ! ( V_17 -> V_53 & V_56 ) ) {
V_4 = F_56 ( V_1 ,
V_72 ,
V_73 ) ;
if ( F_5 ( V_4 ) )
F_57 ( L_15 ) ;
}
}
if ( V_14 -> V_14 )
F_58 ( V_14 ) ;
}
F_17 ( & V_74 ) ;
F_59 ( & V_8 -> V_75 ) ;
F_23 ( & V_74 ) ;
}
static unsigned char F_60 ( struct V_21 * V_26 )
{
struct V_76 * V_18 ;
unsigned char V_77 , V_78 ;
V_77 = V_26 -> V_30 . V_31 ;
F_61 (tmp, &bus->children) {
V_78 = F_62 ( F_63 ( V_18 ) ) ;
if ( V_78 > V_77 )
V_77 = V_78 ;
}
return V_77 ;
}
static void F_64 ( T_1 V_1 )
{
struct V_79 * V_80 = NULL ;
F_65 ( V_1 , & V_80 ) ;
if ( V_80 )
F_66 ( V_80 ) ;
}
static void F_67 ( T_1 V_1 )
{
struct V_79 * V_80 = NULL ;
F_68 ( V_1 ) ;
F_65 ( V_1 , & V_80 ) ;
if ( V_80 )
F_69 ( V_80 , V_81 ) ;
}
static void F_70 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
union V_82 V_83 [ 2 ] ;
struct V_84 V_85 ;
F_38 (func, &slot->funcs, sibling) {
V_85 . V_86 = 2 ;
V_85 . V_87 = V_83 ;
V_83 [ 0 ] . type = V_88 ;
V_83 [ 0 ] . integer . V_89 = V_90 ;
V_83 [ 1 ] . type = V_88 ;
V_83 [ 1 ] . integer . V_89 = 1 ;
F_71 ( F_54 ( V_17 ) , L_16 , & V_85 ,
NULL ) ;
}
}
static void F_72 ( struct V_13 * V_14 , struct V_23 * V_22 )
{
struct V_16 * V_17 ;
if ( V_22 -> V_91 )
return;
F_38 (func, &slot->funcs, sibling) {
if ( F_73 ( V_22 -> V_92 ) == V_17 -> V_48 ) {
V_22 -> V_91 = 1 ;
break;
}
}
}
static int F_74 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
F_38 (func, &slot->funcs, sibling)
F_67 ( F_54 ( V_17 ) ) ;
return F_75 ( V_14 -> V_26 , F_49 ( V_14 -> V_47 , 0 ) ) ;
}
static void T_4 F_76 ( struct V_13 * V_14 )
{
struct V_23 * V_22 ;
struct V_21 * V_26 = V_14 -> V_26 ;
struct V_16 * V_17 ;
int V_77 , V_93 ;
F_77 ( V_94 ) ;
F_74 ( V_14 ) ;
V_77 = F_60 ( V_26 ) ;
for ( V_93 = 0 ; V_93 < 2 ; V_93 ++ ) {
F_38 (dev, &bus->devices, bus_list) {
if ( F_78 ( V_22 -> V_92 ) != V_14 -> V_47 )
continue;
if ( V_22 -> V_95 == V_96 ||
V_22 -> V_95 == V_97 ) {
V_77 = F_79 ( V_26 , V_22 , V_77 , V_93 ) ;
if ( V_93 && V_22 -> V_98 ) {
F_72 ( V_14 , V_22 ) ;
F_80 ( V_22 -> V_98 ) ;
F_81 ( V_22 -> V_98 ,
& V_94 ) ;
}
}
}
}
F_82 ( V_26 , & V_94 , NULL ) ;
F_83 ( V_26 ) ;
F_84 ( V_26 ) ;
F_70 ( V_14 ) ;
F_38 (dev, &bus->devices, bus_list) {
if ( ! V_22 -> V_99 )
V_22 -> V_100 = V_101 ;
}
F_85 ( V_26 ) ;
V_14 -> V_53 |= V_70 ;
F_38 (func, &slot->funcs, sibling) {
V_22 = F_86 ( V_26 , F_49 ( V_14 -> V_47 ,
V_17 -> V_48 ) ) ;
if ( ! V_22 ) {
V_14 -> V_53 &= ( ~ V_70 ) ;
continue;
}
}
}
static struct V_23 * F_87 ( struct V_13 * V_14 )
{
struct V_21 * V_26 = V_14 -> V_26 ;
struct V_23 * V_22 ;
struct V_23 * V_102 = NULL ;
F_88 ( & V_103 ) ;
F_38 (dev, &bus->devices, bus_list)
if ( F_78 ( V_22 -> V_92 ) == V_14 -> V_47 ) {
V_102 = F_89 ( V_22 ) ;
break;
}
F_90 ( & V_103 ) ;
return V_102 ;
}
static void F_91 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
struct V_23 * V_34 ;
while ( ( V_34 = F_87 ( V_14 ) ) ) {
F_92 ( V_34 ) ;
F_22 ( V_34 ) ;
}
F_38 (func, &slot->funcs, sibling)
F_64 ( F_54 ( V_17 ) ) ;
V_14 -> V_53 &= ( ~ V_70 ) ;
}
static bool F_93 ( T_1 V_1 )
{
struct V_79 * V_80 = NULL ;
F_65 ( V_1 , & V_80 ) ;
return V_80 && V_80 -> V_53 . V_104 ;
}
static bool F_94 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
F_38 (func, &slot->funcs, sibling)
if ( F_93 ( F_54 ( V_17 ) ) )
return true ;
return false ;
}
static unsigned int F_95 ( struct V_13 * V_14 )
{
unsigned long long V_105 = 0 ;
struct V_16 * V_17 ;
F_38 (func, &slot->funcs, sibling) {
if ( V_17 -> V_53 & V_55 ) {
T_2 V_4 ;
V_4 = F_34 ( F_54 ( V_17 ) ,
L_5 , NULL , & V_105 ) ;
if ( F_9 ( V_4 ) && V_105 )
break;
} else {
T_3 V_106 ;
F_96 ( V_14 -> V_26 ,
F_49 ( V_14 -> V_47 ,
V_17 -> V_48 ) ,
V_107 , & V_106 ) ;
if ( V_106 != 0xffffffff ) {
V_105 = V_108 ;
break;
}
}
}
return ( unsigned int ) V_105 ;
}
static void F_97 ( struct V_23 * V_22 )
{
T_1 V_1 = F_98 ( & V_22 -> V_22 ) ;
struct V_21 * V_26 = V_22 -> V_98 ;
bool V_109 = false ;
if ( V_1 ) {
T_2 V_4 ;
unsigned long long V_105 ;
V_4 = F_34 ( V_1 , L_5 , NULL , & V_105 ) ;
V_109 = ( F_9 ( V_4 ) && V_105 == V_108 )
|| F_93 ( V_1 ) ;
}
if ( ! V_109 ) {
T_3 V_110 ;
V_109 = F_48 ( V_22 -> V_26 , V_22 -> V_92 , & V_110 , 0 ) ;
}
if ( ! V_109 ) {
F_92 ( V_22 ) ;
if ( V_1 )
F_64 ( V_1 ) ;
} else if ( V_26 ) {
struct V_23 * V_111 , * V_18 ;
F_99 ( & V_22 -> V_22 ) ;
F_19 (child, tmp, &bus->devices, bus_list)
F_97 ( V_111 ) ;
F_100 ( & V_22 -> V_22 ) ;
}
}
static void F_101 ( struct V_9 * V_8 )
{
struct V_13 * V_14 ;
F_38 (slot, &bridge->slots, node) {
struct V_21 * V_26 = V_14 -> V_26 ;
struct V_23 * V_22 , * V_18 ;
F_17 ( & V_14 -> V_61 ) ;
if ( F_94 ( V_14 ) ) {
;
} else if ( F_95 ( V_14 ) == V_108 ) {
F_19 (dev, tmp, &bus->devices,
bus_list)
if ( F_78 ( V_22 -> V_92 ) == V_14 -> V_47 )
F_97 ( V_22 ) ;
F_76 ( V_14 ) ;
} else {
F_91 ( V_14 ) ;
}
F_23 ( & V_14 -> V_61 ) ;
}
}
static void F_84 ( struct V_21 * V_26 )
{
struct V_23 * V_22 ;
F_38 (dev, &bus->devices, bus_list)
F_102 ( V_22 ) ;
}
static void F_83 ( struct V_21 * V_26 )
{
struct V_23 * V_22 , * V_18 ;
int V_112 ;
unsigned long V_113 = V_114 | V_115 ;
F_19 (dev, tmp, &bus->devices, bus_list) {
for ( V_112 = 0 ; V_112 < V_116 ; V_112 ++ ) {
struct V_117 * V_118 = & V_22 -> V_117 [ V_112 ] ;
if ( ( V_118 -> V_53 & V_113 ) && ! V_118 -> V_31 &&
V_118 -> V_33 ) {
F_92 ( V_22 ) ;
break;
}
}
}
}
void F_103 ( T_1 V_1 )
{
struct V_9 * V_8 ;
V_8 = F_52 ( V_1 ) ;
if ( V_8 ) {
F_101 ( V_8 ) ;
F_15 ( V_8 ) ;
}
}
static void F_104 ( T_1 V_1 , T_3 type , void * V_7 )
{
struct V_3 * V_2 = V_7 ;
struct V_16 * V_17 = & V_2 -> V_17 ;
struct V_9 * V_8 ;
char V_119 [ 64 ] ;
struct V_120 V_121 = { . V_122 = sizeof( V_119 ) ,
. V_87 = V_119 } ;
F_17 ( & V_19 ) ;
V_8 = V_2 -> V_8 ;
if ( V_8 )
F_13 ( V_8 ) ;
F_23 ( & V_19 ) ;
F_105 ( V_1 , V_123 , & V_121 ) ;
switch ( type ) {
case V_124 :
F_44 ( L_17 , V_125 , V_119 ) ;
F_44 ( L_18 ,
V_125 , V_119 ) ;
if ( V_8 ) {
F_101 ( V_8 ) ;
} else {
struct V_13 * V_14 = V_17 -> V_14 ;
F_17 ( & V_14 -> V_61 ) ;
F_76 ( V_14 ) ;
F_23 ( & V_14 -> V_61 ) ;
}
break;
case V_126 :
F_44 ( L_19 , V_125 , V_119 ) ;
if ( V_8 ) {
F_101 ( V_8 ) ;
} else {
struct V_13 * V_14 = V_17 -> V_14 ;
int V_102 ;
F_17 ( & V_14 -> V_61 ) ;
V_102 = F_74 ( V_14 ) ;
F_23 ( & V_14 -> V_61 ) ;
if ( V_102 )
F_101 ( V_17 -> V_20 ) ;
}
break;
case V_127 :
F_44 ( L_20 , V_125 , V_119 ) ;
F_106 ( V_17 -> V_14 ) ;
break;
}
if ( V_8 )
F_15 ( V_8 ) ;
}
static void F_107 ( void * V_7 , T_3 type )
{
struct V_3 * V_2 = V_7 ;
T_1 V_1 = V_2 -> V_1 ;
F_108 () ;
F_104 ( V_1 , type , V_2 ) ;
F_109 () ;
F_110 ( V_1 , type , V_128 , NULL ) ;
F_15 ( V_2 -> V_17 . V_20 ) ;
}
static void V_73 ( T_1 V_1 , T_3 type , void * V_7 )
{
struct V_3 * V_2 ;
T_3 V_129 = V_128 ;
switch ( type ) {
case V_124 :
case V_126 :
break;
case V_127 :
V_129 = V_130 ;
F_110 ( V_1 , type , V_129 , NULL ) ;
break;
case V_131 :
return;
case V_132 :
F_36 ( V_1 , L_21
L_22 ) ;
goto V_133;
case V_134 :
F_36 ( V_1 , L_21
L_23 ) ;
goto V_133;
case V_135 :
F_36 ( V_1 , L_24 ) ;
goto V_133;
default:
F_35 ( V_1 , L_25 , type ) ;
V_129 = V_136 ;
goto V_133;
}
F_17 ( & V_19 ) ;
V_2 = F_7 ( V_1 ) ;
if ( V_2 && ! F_11 ( V_2 -> V_1 != V_1 ) ) {
F_13 ( V_2 -> V_17 . V_20 ) ;
F_10 ( V_2 ) ;
F_111 ( F_107 , V_2 , type ) ;
F_23 ( & V_19 ) ;
return;
}
F_23 ( & V_19 ) ;
V_129 = V_137 ;
V_133:
F_110 ( V_1 , type , V_129 , NULL ) ;
}
void F_112 ( struct V_21 * V_26 )
{
struct V_9 * V_8 ;
T_1 V_1 ;
T_2 V_4 ;
if ( V_138 )
return;
V_1 = F_98 ( V_26 -> V_8 ) ;
if ( ! V_1 )
return;
V_8 = F_3 ( sizeof( struct V_9 ) , V_5 ) ;
if ( ! V_8 ) {
F_36 ( V_1 , L_26 ) ;
return;
}
F_39 ( & V_8 -> V_63 ) ;
F_113 ( & V_8 -> V_10 ) ;
V_8 -> V_23 = F_89 ( V_26 -> V_28 ) ;
V_8 -> V_21 = V_26 ;
F_114 ( & V_26 -> V_22 ) ;
if ( ! F_115 ( V_8 -> V_21 ) ) {
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
F_17 ( & V_74 ) ;
F_116 ( & V_8 -> V_75 , & V_139 ) ;
F_23 ( & V_74 ) ;
V_4 = F_117 ( V_140 , V_1 , 1 ,
F_33 , NULL , V_8 , NULL ) ;
if ( F_5 ( V_4 ) ) {
F_36 ( V_1 , L_27 ) ;
F_53 ( V_8 ) ;
F_15 ( V_8 ) ;
}
}
void F_118 ( struct V_21 * V_26 )
{
struct V_9 * V_8 ;
if ( V_138 )
return;
F_17 ( & V_74 ) ;
F_38 (bridge, &bridge_list, list)
if ( V_8 -> V_21 == V_26 ) {
F_23 ( & V_74 ) ;
F_53 ( V_8 ) ;
F_15 ( V_8 ) ;
return;
}
F_23 ( & V_74 ) ;
}
int F_119 ( struct V_13 * V_14 )
{
F_17 ( & V_14 -> V_61 ) ;
if ( ! ( V_14 -> V_53 & V_70 ) )
F_76 ( V_14 ) ;
F_23 ( & V_14 -> V_61 ) ;
return 0 ;
}
int F_106 ( struct V_13 * V_14 )
{
struct V_16 * V_17 ;
int V_65 = 0 ;
F_17 ( & V_14 -> V_61 ) ;
F_91 ( V_14 ) ;
F_38 (func, &slot->funcs, sibling)
if ( V_17 -> V_53 & V_54 ) {
T_1 V_1 = F_54 ( V_17 ) ;
if ( F_5 ( F_120 ( V_1 ) ) )
F_36 ( V_1 , L_28 ) ;
break;
}
F_23 ( & V_14 -> V_61 ) ;
return V_65 ;
}
T_5 F_121 ( struct V_13 * V_14 )
{
return ( V_14 -> V_53 & V_70 ) ;
}
T_5 F_122 ( struct V_13 * V_14 )
{
return ! ( F_95 ( V_14 ) & V_141 ) ;
}
T_5 F_123 ( struct V_13 * V_14 )
{
return ! ! F_95 ( V_14 ) ;
}
