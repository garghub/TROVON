static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 (dev_res, tmp, head, list) {
F_3 ( & V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
}
}
static int F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_9 * V_10 ,
T_1 V_11 , T_1 V_12 )
{
struct V_3 * V_5 ;
V_5 = F_6 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 ) {
F_7 ( L_1 ) ;
return - V_14 ;
}
V_5 -> V_10 = V_10 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_15 = V_10 -> V_15 ;
V_5 -> V_16 = V_10 -> V_16 ;
V_5 -> V_17 = V_10 -> V_17 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_12 = V_12 ;
F_8 ( & V_5 -> V_6 , V_2 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 , * V_5 ;
F_2 (dev_res, tmp, head, list) {
if ( V_4 -> V_10 == V_10 ) {
F_3 ( & V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
break;
}
}
}
static struct V_3 * F_10 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 ;
F_11 (dev_res, head, list) {
if ( V_4 -> V_10 == V_10 ) {
int V_18 = V_10 - & V_4 -> V_8 -> V_9 [ 0 ] ;
F_12 ( V_19 , & V_4 -> V_8 -> V_8 ,
L_2 ,
V_18 , V_4 -> V_10 ,
( unsigned long long ) V_4 -> V_11 ,
( unsigned long long ) V_4 -> V_12 ) ;
return V_4 ;
}
}
return NULL ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 ;
V_4 = F_10 ( V_2 , V_10 ) ;
return V_4 ? V_4 -> V_11 : 0 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 ;
V_4 = F_10 ( V_2 , V_10 ) ;
return V_4 ? V_4 -> V_12 : 0 ;
}
static void F_15 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_9 * V_22 ;
struct V_3 * V_4 , * V_5 ;
T_1 V_23 ;
struct V_1 * V_24 ;
V_22 = & V_8 -> V_9 [ V_20 ] ;
if ( V_22 -> V_17 & V_25 )
continue;
if ( ! ( V_22 -> V_17 ) || V_22 -> V_26 )
continue;
V_23 = F_16 ( V_8 , V_22 ) ;
if ( ! V_23 ) {
F_17 ( & V_8 -> V_8 , L_3 ,
V_20 , V_22 ) ;
continue;
}
V_5 = F_6 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 )
F_18 ( L_4 ) ;
V_5 -> V_10 = V_22 ;
V_5 -> V_8 = V_8 ;
V_24 = V_2 ;
F_11 (dev_res, head, list) {
T_1 V_27 ;
V_27 = F_16 ( V_4 -> V_8 ,
V_4 -> V_10 ) ;
if ( V_23 > V_27 ) {
V_24 = & V_4 -> V_6 ;
break;
}
}
F_19 ( & V_5 -> V_6 , V_24 ) ;
}
}
static void F_20 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
T_2 V_28 = V_8 -> V_28 >> 8 ;
if ( V_28 == V_29 || V_28 == V_30 )
return;
if ( V_28 == V_31 ) {
T_2 V_32 ;
F_21 ( V_8 , V_33 , & V_32 ) ;
if ( V_32 & ( V_34 | V_35 ) )
return;
}
F_15 ( V_8 , V_2 ) ;
}
static inline void F_22 ( struct V_9 * V_10 )
{
V_10 -> V_15 = 0 ;
V_10 -> V_16 = 0 ;
V_10 -> V_17 = 0 ;
}
static void F_23 ( struct V_1 * V_36 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_3 * V_37 , * V_5 ;
struct V_3 * V_4 ;
T_1 V_11 , V_27 ;
int V_18 ;
F_2 (add_res, tmp, realloc_head, list) {
bool V_38 = false ;
V_10 = V_37 -> V_10 ;
if ( ! V_10 -> V_17 )
goto V_39;
F_11 (dev_res, head, list) {
if ( V_4 -> V_10 == V_10 ) {
V_38 = true ;
break;
}
}
if ( ! V_38 )
continue;
V_18 = V_10 - & V_37 -> V_8 -> V_9 [ 0 ] ;
V_11 = V_37 -> V_11 ;
V_27 = V_37 -> V_12 ;
if ( ! F_24 ( V_10 ) ) {
V_10 -> V_15 = V_27 ;
V_10 -> V_16 = V_10 -> V_15 + V_11 - 1 ;
if ( F_25 ( V_37 -> V_8 , V_18 ) )
F_22 ( V_10 ) ;
} else {
V_10 -> V_17 |= V_37 -> V_17 &
( V_40 | V_41 ) ;
if ( F_26 ( V_37 -> V_8 , V_18 ,
V_11 , V_27 ) )
F_12 ( V_19 , & V_37 -> V_8 -> V_8 ,
L_5 ,
( unsigned long long ) V_11 ,
V_18 , V_10 ) ;
}
V_39:
F_3 ( & V_37 -> V_6 ) ;
F_4 ( V_37 ) ;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_1 * V_42 )
{
struct V_9 * V_10 ;
struct V_3 * V_4 ;
int V_18 ;
F_11 (dev_res, head, list) {
V_10 = V_4 -> V_10 ;
V_18 = V_10 - & V_4 -> V_8 -> V_9 [ 0 ] ;
if ( F_24 ( V_10 ) &&
F_25 ( V_4 -> V_8 , V_18 ) ) {
if ( V_42 ) {
if ( ! ( ( V_18 == V_43 ) &&
( ! ( V_10 -> V_17 & V_44 ) ) ) )
F_5 ( V_42 ,
V_4 -> V_8 , V_10 ,
0 ,
0 ) ;
}
F_22 ( V_10 ) ;
}
}
}
static unsigned long F_28 ( struct V_1 * V_42 )
{
struct V_3 * V_45 ;
unsigned long V_46 = 0 ;
F_11 (fail_res, fail_head, list)
V_46 |= V_45 -> V_17 ;
return V_46 & ( V_47 | V_48 | V_49 ) ;
}
static bool F_29 ( unsigned long V_46 , struct V_9 * V_10 )
{
if ( V_10 -> V_17 & V_47 )
return ! ! ( V_46 & V_47 ) ;
if ( V_10 -> V_17 & V_49 ) {
if ( V_46 & V_49 )
return true ;
else if ( ( V_46 & V_48 ) &&
! ( V_10 -> V_26 -> V_17 & V_49 ) )
return true ;
else
return false ;
}
if ( V_10 -> V_17 & V_48 )
return ! ! ( V_46 & V_48 ) ;
return false ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_1 * V_36 ,
struct V_1 * V_42 )
{
F_31 ( V_50 ) ;
F_31 ( V_51 ) ;
struct V_3 * V_52 ;
struct V_3 * V_4 , * V_53 , * V_54 ;
unsigned long V_55 ;
T_1 V_56 , V_27 ;
if ( ! V_36 || F_32 ( V_36 ) )
goto V_57;
F_11 (dev_res, head, list) {
if ( F_5 ( & V_50 , V_4 -> V_8 , V_4 -> V_10 , 0 , 0 ) ) {
F_1 ( & V_50 ) ;
goto V_57;
}
}
F_2 (dev_res, tmp_res, head, list) {
V_4 -> V_10 -> V_16 += F_13 ( V_36 ,
V_4 -> V_10 ) ;
if ( ! ( V_4 -> V_10 -> V_17 & V_40 ) )
continue;
V_56 = F_14 ( V_36 , V_4 -> V_10 ) ;
if ( V_56 > V_4 -> V_10 -> V_15 ) {
T_1 V_58 = F_24 ( V_4 -> V_10 ) ;
V_4 -> V_10 -> V_15 = V_56 ;
V_4 -> V_10 -> V_16 = V_56 + V_58 - 1 ;
F_11 (dev_res2, head, list) {
V_27 = F_16 ( V_54 -> V_8 ,
V_54 -> V_10 ) ;
if ( V_56 > V_27 ) {
F_33 ( & V_4 -> V_6 ,
& V_54 -> V_6 ) ;
break;
}
}
}
}
F_27 ( V_2 , & V_51 ) ;
if ( F_32 ( & V_51 ) ) {
F_11 (dev_res, head, list)
F_9 ( V_36 , V_4 -> V_10 ) ;
F_1 ( & V_50 ) ;
F_1 ( V_2 ) ;
return;
}
V_55 = F_28 ( & V_51 ) ;
F_2 (dev_res, tmp_res, head, list)
if ( V_4 -> V_10 -> V_26 &&
! F_29 ( V_55 , V_4 -> V_10 ) ) {
F_9 ( V_36 , V_4 -> V_10 ) ;
F_9 ( & V_50 , V_4 -> V_10 ) ;
F_3 ( & V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
}
F_1 ( & V_51 ) ;
F_11 (dev_res, head, list)
if ( V_4 -> V_10 -> V_26 )
F_34 ( V_4 -> V_10 ) ;
F_11 (save_res, &save_head, list) {
struct V_9 * V_10 = V_52 -> V_10 ;
V_10 -> V_15 = V_52 -> V_15 ;
V_10 -> V_16 = V_52 -> V_16 ;
V_10 -> V_17 = V_52 -> V_17 ;
}
F_1 ( & V_50 ) ;
V_57:
F_27 ( V_2 , V_42 ) ;
if ( V_36 )
F_23 ( V_36 , V_2 ) ;
F_1 ( V_2 ) ;
}
static void F_35 ( struct V_7 * V_8 ,
struct V_1 * V_59 ,
struct V_1 * V_42 )
{
F_31 ( V_2 ) ;
F_20 ( V_8 , & V_2 ) ;
F_30 ( & V_2 , V_59 , V_42 ) ;
}
static void F_36 ( const struct V_60 * V_61 ,
struct V_1 * V_36 ,
struct V_1 * V_42 )
{
struct V_7 * V_8 ;
F_31 ( V_2 ) ;
F_11 (dev, &bus->devices, bus_list)
F_20 ( V_8 , & V_2 ) ;
F_30 ( & V_2 , V_36 , V_42 ) ;
}
void F_37 ( struct V_60 * V_61 )
{
struct V_7 * V_62 = V_61 -> V_63 ;
struct V_9 * V_10 ;
struct V_64 V_65 ;
F_38 ( & V_62 -> V_8 , L_6 ,
& V_61 -> V_66 ) ;
V_10 = V_61 -> V_9 [ 0 ] ;
F_39 ( V_62 -> V_61 , & V_65 , V_10 ) ;
if ( V_10 -> V_17 & V_47 ) {
F_38 ( & V_62 -> V_8 , L_7 , V_10 ) ;
F_40 ( V_62 , V_67 ,
V_65 . V_15 ) ;
F_40 ( V_62 , V_68 ,
V_65 . V_16 ) ;
}
V_10 = V_61 -> V_9 [ 1 ] ;
F_39 ( V_62 -> V_61 , & V_65 , V_10 ) ;
if ( V_10 -> V_17 & V_47 ) {
F_38 ( & V_62 -> V_8 , L_7 , V_10 ) ;
F_40 ( V_62 , V_69 ,
V_65 . V_15 ) ;
F_40 ( V_62 , V_70 ,
V_65 . V_16 ) ;
}
V_10 = V_61 -> V_9 [ 2 ] ;
F_39 ( V_62 -> V_61 , & V_65 , V_10 ) ;
if ( V_10 -> V_17 & V_48 ) {
F_38 ( & V_62 -> V_8 , L_7 , V_10 ) ;
F_40 ( V_62 , V_71 ,
V_65 . V_15 ) ;
F_40 ( V_62 , V_72 ,
V_65 . V_16 ) ;
}
V_10 = V_61 -> V_9 [ 3 ] ;
F_39 ( V_62 -> V_61 , & V_65 , V_10 ) ;
if ( V_10 -> V_17 & V_48 ) {
F_38 ( & V_62 -> V_8 , L_7 , V_10 ) ;
F_40 ( V_62 , V_73 ,
V_65 . V_15 ) ;
F_40 ( V_62 , V_74 ,
V_65 . V_16 ) ;
}
}
static void F_41 ( struct V_7 * V_62 )
{
struct V_9 * V_10 ;
struct V_64 V_65 ;
unsigned long V_75 ;
T_3 V_76 , V_77 ;
T_2 V_78 ;
T_4 V_79 ;
V_75 = V_80 ;
if ( V_62 -> V_81 )
V_75 = V_82 ;
V_10 = & V_62 -> V_9 [ V_83 + 0 ] ;
F_39 ( V_62 -> V_61 , & V_65 , V_10 ) ;
if ( V_10 -> V_17 & V_47 ) {
F_21 ( V_62 , V_84 , & V_78 ) ;
V_76 = ( V_65 . V_15 >> 8 ) & V_75 ;
V_77 = ( V_65 . V_16 >> 8 ) & V_75 ;
V_78 = ( ( T_2 ) V_77 << 8 ) | V_76 ;
V_79 = ( V_65 . V_16 & 0xffff0000 ) | ( V_65 . V_15 >> 16 ) ;
F_38 ( & V_62 -> V_8 , L_7 , V_10 ) ;
} else {
V_79 = 0 ;
V_78 = 0x00f0 ;
}
F_40 ( V_62 , V_85 , 0x0000ffff ) ;
F_42 ( V_62 , V_84 , V_78 ) ;
F_40 ( V_62 , V_85 , V_79 ) ;
}
static void F_43 ( struct V_7 * V_62 )
{
struct V_9 * V_10 ;
struct V_64 V_65 ;
T_4 V_78 ;
V_10 = & V_62 -> V_9 [ V_83 + 1 ] ;
F_39 ( V_62 -> V_61 , & V_65 , V_10 ) ;
if ( V_10 -> V_17 & V_48 ) {
V_78 = ( V_65 . V_15 >> 16 ) & 0xfff0 ;
V_78 |= V_65 . V_16 & 0xfff00000 ;
F_38 ( & V_62 -> V_8 , L_7 , V_10 ) ;
} else {
V_78 = 0x0000fff0 ;
}
F_40 ( V_62 , V_86 , V_78 ) ;
}
static void F_44 ( struct V_7 * V_62 )
{
struct V_9 * V_10 ;
struct V_64 V_65 ;
T_4 V_78 , V_87 , V_88 ;
F_40 ( V_62 , V_89 , 0 ) ;
V_87 = V_88 = 0 ;
V_10 = & V_62 -> V_9 [ V_83 + 2 ] ;
F_39 ( V_62 -> V_61 , & V_65 , V_10 ) ;
if ( V_10 -> V_17 & V_49 ) {
V_78 = ( V_65 . V_15 >> 16 ) & 0xfff0 ;
V_78 |= V_65 . V_16 & 0xfff00000 ;
if ( V_10 -> V_17 & V_90 ) {
V_87 = F_45 ( V_65 . V_15 ) ;
V_88 = F_45 ( V_65 . V_16 ) ;
}
F_38 ( & V_62 -> V_8 , L_7 , V_10 ) ;
} else {
V_78 = 0x0000fff0 ;
}
F_40 ( V_62 , V_91 , V_78 ) ;
F_40 ( V_62 , V_92 , V_87 ) ;
F_40 ( V_62 , V_89 , V_88 ) ;
}
static void F_46 ( struct V_60 * V_61 , unsigned long type )
{
struct V_7 * V_62 = V_61 -> V_63 ;
F_38 ( & V_62 -> V_8 , L_8 ,
& V_61 -> V_66 ) ;
if ( type & V_47 )
F_41 ( V_62 ) ;
if ( type & V_48 )
F_43 ( V_62 ) ;
if ( type & V_49 )
F_44 ( V_62 ) ;
F_42 ( V_62 , V_93 , V_61 -> V_94 ) ;
}
void F_47 ( struct V_60 * V_61 )
{
unsigned long type = V_47 | V_48 |
V_49 ;
F_46 ( V_61 , type ) ;
}
int F_48 ( struct V_7 * V_62 , int V_20 )
{
if ( V_20 < V_83 || V_20 > V_95 )
return 0 ;
if ( F_49 ( V_62 , V_20 ) == 0 )
return 0 ;
if ( ( V_62 -> V_28 >> 8 ) != V_96 )
return 0 ;
if ( ! F_50 ( V_62 , V_20 ) )
return - V_97 ;
switch ( V_20 - V_83 ) {
case 0 :
F_41 ( V_62 ) ;
break;
case 1 :
F_43 ( V_62 ) ;
break;
case 2 :
F_44 ( V_62 ) ;
break;
default:
return - V_97 ;
}
if ( F_49 ( V_62 , V_20 ) == 0 )
return 0 ;
return - V_97 ;
}
static void F_51 ( struct V_60 * V_61 )
{
T_2 V_98 ;
T_4 V_99 ;
struct V_7 * V_62 = V_61 -> V_63 ;
struct V_9 * V_100 ;
V_100 = & V_62 -> V_9 [ V_83 ] ;
V_100 [ 1 ] . V_17 |= V_48 ;
F_21 ( V_62 , V_84 , & V_98 ) ;
if ( ! V_98 ) {
F_42 ( V_62 , V_84 , 0xe0f0 ) ;
F_21 ( V_62 , V_84 , & V_98 ) ;
F_42 ( V_62 , V_84 , 0x0 ) ;
}
if ( V_98 )
V_100 [ 0 ] . V_17 |= V_47 ;
if ( V_62 -> V_101 == V_102 && V_62 -> V_103 == 0x0001 )
return;
F_52 ( V_62 , V_91 , & V_99 ) ;
if ( ! V_99 ) {
F_40 ( V_62 , V_91 ,
0xffe0fff0 ) ;
F_52 ( V_62 , V_91 , & V_99 ) ;
F_40 ( V_62 , V_91 , 0x0 ) ;
}
if ( V_99 ) {
V_100 [ 2 ] . V_17 |= V_48 | V_49 ;
if ( ( V_99 & V_104 ) ==
V_105 ) {
V_100 [ 2 ] . V_17 |= V_90 ;
V_100 [ 2 ] . V_17 |= V_105 ;
}
}
if ( V_100 [ 2 ] . V_17 & V_90 ) {
T_4 V_106 , V_5 ;
F_52 ( V_62 , V_92 ,
& V_106 ) ;
F_40 ( V_62 , V_92 ,
0xffffffff ) ;
F_52 ( V_62 , V_92 , & V_5 ) ;
if ( ! V_5 )
V_100 [ 2 ] . V_17 &= ~ V_90 ;
F_40 ( V_62 , V_92 ,
V_106 ) ;
}
}
static struct V_9 * F_53 ( struct V_60 * V_61 ,
unsigned long V_107 , unsigned long type )
{
int V_20 ;
struct V_9 * V_22 ;
F_54 (bus, r, i) {
if ( V_22 == & V_108 || V_22 == & V_109 )
continue;
if ( V_22 && ( V_22 -> V_17 & V_107 ) == type && ! V_22 -> V_26 )
return V_22 ;
}
return NULL ;
}
static T_1 F_55 ( T_1 V_110 ,
T_1 V_111 ,
T_1 V_112 ,
T_1 V_113 ,
T_1 V_27 )
{
if ( V_110 < V_111 )
V_110 = V_111 ;
if ( V_113 == 1 )
V_113 = 0 ;
#if F_56 ( V_114 ) || F_56 ( V_115 )
V_110 = ( V_110 & 0xff ) + ( ( V_110 & ~ 0xffUL ) << 2 ) ;
#endif
V_110 = F_57 ( V_110 + V_112 , V_27 ) ;
if ( V_110 < V_113 )
V_110 = V_113 ;
return V_110 ;
}
static T_1 F_58 ( T_1 V_110 ,
T_1 V_111 ,
T_1 V_112 ,
T_1 V_113 ,
T_1 V_27 )
{
if ( V_110 < V_111 )
V_110 = V_111 ;
if ( V_113 == 1 )
V_113 = 0 ;
if ( V_110 < V_113 )
V_110 = V_113 ;
V_110 = F_57 ( V_110 + V_112 , V_27 ) ;
return V_110 ;
}
T_1 __weak F_59 ( struct V_60 * V_61 ,
unsigned long type )
{
return 1 ;
}
static T_1 F_60 ( struct V_60 * V_61 ,
unsigned long type )
{
T_1 V_27 = 1 , V_116 ;
if ( type & V_48 )
V_27 = V_117 ;
else if ( type & V_47 ) {
if ( V_61 -> V_63 -> V_81 )
V_27 = V_118 ;
else
V_27 = V_119 ;
}
V_116 = F_59 ( V_61 , type ) ;
return F_61 ( V_27 , V_116 ) ;
}
static void F_62 ( struct V_60 * V_61 , T_1 V_111 ,
T_1 V_11 , struct V_1 * V_36 )
{
struct V_7 * V_8 ;
struct V_9 * V_100 = F_53 ( V_61 , V_47 ,
V_47 ) ;
T_1 V_110 = 0 , V_120 = 0 , V_112 = 0 ;
T_1 V_121 = 0 ;
T_1 V_12 , V_27 ;
if ( ! V_100 )
return;
V_12 = F_60 ( V_61 , V_47 ) ;
F_11 (dev, &bus->devices, bus_list) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
unsigned long V_58 ;
if ( V_22 -> V_26 || ! ( V_22 -> V_17 & V_47 ) )
continue;
V_58 = F_24 ( V_22 ) ;
if ( V_58 < 0x400 )
V_110 += V_58 ;
else
V_112 += V_58 ;
V_27 = F_16 ( V_8 , V_22 ) ;
if ( V_27 > V_12 )
V_12 = V_27 ;
if ( V_36 )
V_121 += F_13 ( V_36 , V_22 ) ;
}
}
V_120 = F_55 ( V_110 , V_111 , V_112 ,
F_24 ( V_100 ) , V_12 ) ;
if ( V_121 > V_11 )
V_11 = V_121 ;
V_112 = ( ! V_36 || ( V_36 && ! V_11 ) ) ? V_120 :
F_55 ( V_110 , V_111 , V_11 + V_112 ,
F_24 ( V_100 ) , V_12 ) ;
if ( ! V_120 && ! V_112 ) {
if ( V_100 -> V_15 || V_100 -> V_16 )
F_38 ( & V_61 -> V_63 -> V_8 , L_9 ,
V_100 , & V_61 -> V_66 ) ;
V_100 -> V_17 = 0 ;
return;
}
V_100 -> V_15 = V_12 ;
V_100 -> V_16 = V_100 -> V_15 + V_120 - 1 ;
V_100 -> V_17 |= V_40 ;
if ( V_112 > V_120 && V_36 ) {
F_5 ( V_36 , V_61 -> V_63 , V_100 , V_112 - V_120 ,
V_12 ) ;
F_12 ( V_19 , & V_61 -> V_63 -> V_8 , L_10 ,
V_100 , & V_61 -> V_66 ,
( unsigned long long ) V_112 - V_120 ) ;
}
}
static inline T_1 F_63 ( T_1 * V_122 ,
int V_123 )
{
T_1 V_27 = 0 ;
T_1 V_12 = 0 ;
int V_124 ;
for ( V_124 = 0 ; V_124 <= V_123 ; V_124 ++ ) {
T_1 V_125 = 1 ;
V_125 <<= ( V_124 + 20 ) ;
if ( ! V_27 )
V_12 = V_125 ;
else if ( F_57 ( V_27 + V_12 , V_12 ) < V_125 )
V_12 = V_125 >> 1 ;
V_27 += V_122 [ V_124 ] ;
}
return V_12 ;
}
static int F_64 ( struct V_60 * V_61 , unsigned long V_46 ,
unsigned long type , unsigned long V_126 ,
unsigned long V_127 ,
T_1 V_111 , T_1 V_11 ,
struct V_1 * V_36 )
{
struct V_7 * V_8 ;
T_1 V_12 , V_27 , V_110 , V_120 , V_112 ;
T_1 V_122 [ 18 ] ;
int V_124 , V_123 ;
struct V_9 * V_100 = F_53 ( V_61 ,
V_46 | V_49 , type ) ;
T_1 V_121 = 0 ;
T_1 V_128 = 0 ;
T_1 V_56 = 0 ;
if ( ! V_100 )
return - V_129 ;
memset ( V_122 , 0 , sizeof( V_122 ) ) ;
V_123 = 0 ;
V_110 = 0 ;
F_11 (dev, &bus->devices, bus_list) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
T_1 V_58 ;
if ( V_22 -> V_26 || ( V_22 -> V_17 & V_25 ) ||
( ( V_22 -> V_17 & V_46 ) != type &&
( V_22 -> V_17 & V_46 ) != V_126 &&
( V_22 -> V_17 & V_46 ) != V_127 ) )
continue;
V_58 = F_24 ( V_22 ) ;
#ifdef F_65
if ( V_36 && V_20 >= V_130 &&
V_20 <= V_131 ) {
V_56 = F_61 ( F_16 ( V_8 , V_22 ) , V_56 ) ;
V_22 -> V_16 = V_22 -> V_15 - 1 ;
F_5 ( V_36 , V_8 , V_22 , V_58 , 0 ) ;
V_121 += V_58 ;
continue;
}
#endif
V_27 = F_16 ( V_8 , V_22 ) ;
V_124 = F_66 ( V_27 ) - 20 ;
if ( V_124 < 0 )
V_124 = 0 ;
if ( V_124 >= F_67 ( V_122 ) ) {
F_17 ( & V_8 -> V_8 , L_11 ,
V_20 , V_22 , ( unsigned long long ) V_27 ) ;
V_22 -> V_17 = 0 ;
continue;
}
V_110 += V_58 ;
if ( V_58 == V_27 )
V_122 [ V_124 ] += V_27 ;
if ( V_124 > V_123 )
V_123 = V_124 ;
if ( V_36 ) {
V_121 += F_13 ( V_36 , V_22 ) ;
V_128 = F_14 ( V_36 , V_22 ) ;
V_56 = F_61 ( V_56 , V_128 ) ;
}
}
}
V_12 = F_63 ( V_122 , V_123 ) ;
V_12 = F_61 ( V_12 , F_60 ( V_61 , V_100 -> V_17 ) ) ;
V_120 = F_58 ( V_110 , V_111 , 0 , F_24 ( V_100 ) , V_12 ) ;
V_56 = F_61 ( V_12 , V_56 ) ;
if ( V_121 > V_11 )
V_11 = V_121 ;
V_112 = ( ! V_36 || ( V_36 && ! V_11 ) ) ? V_120 :
F_58 ( V_110 , V_111 , V_11 ,
F_24 ( V_100 ) , V_56 ) ;
if ( ! V_120 && ! V_112 ) {
if ( V_100 -> V_15 || V_100 -> V_16 )
F_38 ( & V_61 -> V_63 -> V_8 , L_9 ,
V_100 , & V_61 -> V_66 ) ;
V_100 -> V_17 = 0 ;
return 0 ;
}
V_100 -> V_15 = V_12 ;
V_100 -> V_16 = V_120 + V_12 - 1 ;
V_100 -> V_17 |= V_40 ;
if ( V_112 > V_120 && V_36 ) {
F_5 ( V_36 , V_61 -> V_63 , V_100 , V_112 - V_120 , V_56 ) ;
F_12 ( V_19 , & V_61 -> V_63 -> V_8 , L_12 ,
V_100 , & V_61 -> V_66 ,
( unsigned long long ) ( V_112 - V_120 ) ,
( unsigned long long ) V_56 ) ;
}
return 0 ;
}
unsigned long F_68 ( struct V_9 * V_10 )
{
if ( V_10 -> V_17 & V_47 )
return V_132 ;
if ( V_10 -> V_17 & V_48 )
return V_133 ;
return 0 ;
}
static void F_69 ( struct V_60 * V_61 ,
struct V_1 * V_36 )
{
struct V_7 * V_62 = V_61 -> V_63 ;
struct V_9 * V_100 = & V_62 -> V_9 [ V_83 ] ;
T_1 V_134 = V_133 * 2 ;
T_2 V_135 ;
if ( V_100 [ 0 ] . V_26 )
goto V_136;
V_100 [ 0 ] . V_15 = V_132 ;
V_100 [ 0 ] . V_16 = V_100 [ 0 ] . V_15 + V_132 - 1 ;
V_100 [ 0 ] . V_17 |= V_47 | V_40 ;
if ( V_36 ) {
V_100 [ 0 ] . V_16 -= V_132 ;
F_5 ( V_36 , V_62 , V_100 , V_132 ,
V_132 ) ;
}
V_136:
if ( V_100 [ 1 ] . V_26 )
goto V_137;
V_100 [ 1 ] . V_15 = V_132 ;
V_100 [ 1 ] . V_16 = V_100 [ 1 ] . V_15 + V_132 - 1 ;
V_100 [ 1 ] . V_17 |= V_47 | V_40 ;
if ( V_36 ) {
V_100 [ 1 ] . V_16 -= V_132 ;
F_5 ( V_36 , V_62 , V_100 + 1 , V_132 ,
V_132 ) ;
}
V_137:
F_21 ( V_62 , V_138 , & V_135 ) ;
if ( V_135 & V_139 ) {
V_135 &= ~ V_139 ;
F_42 ( V_62 , V_138 , V_135 ) ;
F_21 ( V_62 , V_138 , & V_135 ) ;
}
F_21 ( V_62 , V_138 , & V_135 ) ;
if ( ! ( V_135 & V_140 ) ) {
V_135 |= V_140 ;
F_42 ( V_62 , V_138 , V_135 ) ;
F_21 ( V_62 , V_138 , & V_135 ) ;
}
if ( V_100 [ 2 ] . V_26 )
goto V_141;
if ( V_135 & V_140 ) {
V_100 [ 2 ] . V_15 = V_133 ;
V_100 [ 2 ] . V_16 = V_100 [ 2 ] . V_15 + V_133 - 1 ;
V_100 [ 2 ] . V_17 |= V_48 | V_49 |
V_40 ;
if ( V_36 ) {
V_100 [ 2 ] . V_16 -= V_133 ;
F_5 ( V_36 , V_62 , V_100 + 2 ,
V_133 , V_133 ) ;
}
V_134 = V_133 ;
}
V_141:
if ( V_100 [ 3 ] . V_26 )
goto V_142;
V_100 [ 3 ] . V_15 = V_133 ;
V_100 [ 3 ] . V_16 = V_100 [ 3 ] . V_15 + V_134 - 1 ;
V_100 [ 3 ] . V_17 |= V_48 | V_40 ;
if ( V_36 ) {
V_100 [ 3 ] . V_16 -= V_134 ;
F_5 ( V_36 , V_62 , V_100 + 3 , V_134 ,
V_133 ) ;
}
V_142:
;
}
void F_70 ( struct V_60 * V_61 , struct V_1 * V_36 )
{
struct V_7 * V_8 ;
unsigned long V_46 , V_143 , V_126 = 0 , V_127 = 0 ;
T_1 V_144 = 0 , V_145 = 0 ;
struct V_9 * V_100 ;
int V_146 ;
F_11 (dev, &bus->devices, bus_list) {
struct V_60 * V_147 = V_8 -> V_148 ;
if ( ! V_147 )
continue;
switch ( V_8 -> V_28 >> 8 ) {
case V_149 :
F_69 ( V_147 , V_36 ) ;
break;
case V_96 :
default:
F_70 ( V_147 , V_36 ) ;
break;
}
}
if ( F_71 ( V_61 ) )
return;
switch ( V_61 -> V_63 -> V_28 >> 8 ) {
case V_149 :
break;
case V_96 :
F_51 ( V_61 ) ;
if ( V_61 -> V_63 -> V_150 ) {
V_145 = V_151 ;
V_144 = V_152 ;
}
default:
F_62 ( V_61 , V_36 ? 0 : V_145 ,
V_145 , V_36 ) ;
V_100 = & V_61 -> V_63 -> V_9 [ V_83 ] ;
V_46 = V_48 ;
V_143 = V_48 | V_49 ;
if ( V_100 [ 2 ] . V_17 & V_90 ) {
V_143 |= V_90 ;
V_146 = F_64 ( V_61 , V_143 , V_143 ,
V_143 , V_143 ,
V_36 ? 0 : V_144 ,
V_144 , V_36 ) ;
if ( V_146 == 0 ) {
V_46 = V_143 ;
V_126 = V_143 & ~ V_90 ;
V_127 = V_143 & ~ V_49 ;
}
}
if ( ! V_126 ) {
V_143 &= ~ V_90 ;
V_146 = F_64 ( V_61 , V_143 , V_143 ,
V_143 , V_143 ,
V_36 ? 0 : V_144 ,
V_144 , V_36 ) ;
if ( V_146 == 0 )
V_46 = V_143 ;
else
V_144 += V_144 ;
V_126 = V_127 = V_48 ;
}
F_64 ( V_61 , V_46 , V_48 , V_126 , V_127 ,
V_36 ? 0 : V_144 ,
V_144 , V_36 ) ;
break;
}
}
void F_72 ( struct V_60 * V_61 )
{
F_70 ( V_61 , NULL ) ;
}
static void F_73 ( struct V_60 * V_147 , struct V_9 * V_22 )
{
int V_20 ;
struct V_9 * V_153 ;
unsigned long V_46 = V_47 | V_48 |
V_49 ;
F_54 (b, parent_r, i) {
if ( ! V_153 )
continue;
if ( ( V_22 -> V_17 & V_46 ) == ( V_153 -> V_17 & V_46 ) &&
F_74 ( V_153 , V_22 ) )
F_75 ( V_153 , V_22 ) ;
}
}
static void F_76 ( struct V_7 * V_8 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_60 * V_147 ;
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
if ( V_22 -> V_26 || ! ( V_22 -> V_17 & V_25 ) ||
! ( V_22 -> V_17 & ( V_47 | V_48 ) ) )
continue;
V_147 = V_8 -> V_61 ;
while ( V_147 && ! V_22 -> V_26 ) {
F_73 ( V_147 , V_22 ) ;
V_147 = V_147 -> V_26 ;
}
}
}
void F_77 ( const struct V_60 * V_61 ,
struct V_1 * V_36 ,
struct V_1 * V_42 )
{
struct V_60 * V_147 ;
struct V_7 * V_8 ;
F_36 ( V_61 , V_36 , V_42 ) ;
F_11 (dev, &bus->devices, bus_list) {
F_76 ( V_8 ) ;
V_147 = V_8 -> V_148 ;
if ( ! V_147 )
continue;
F_77 ( V_147 , V_36 , V_42 ) ;
switch ( V_8 -> V_28 >> 8 ) {
case V_96 :
if ( ! F_78 ( V_8 ) )
F_47 ( V_147 ) ;
break;
case V_149 :
F_37 ( V_147 ) ;
break;
default:
F_38 ( & V_8 -> V_8 , L_13 ,
F_79 ( V_147 ) , V_147 -> V_154 ) ;
break;
}
}
}
void F_80 ( const struct V_60 * V_61 )
{
F_77 ( V_61 , NULL , NULL ) ;
}
static void F_81 ( const struct V_7 * V_62 ,
struct V_1 * V_59 ,
struct V_1 * V_42 )
{
struct V_60 * V_147 ;
F_35 ( (struct V_7 * ) V_62 ,
V_59 , V_42 ) ;
V_147 = V_62 -> V_148 ;
if ( ! V_147 )
return;
F_77 ( V_147 , V_59 , V_42 ) ;
switch ( V_62 -> V_28 >> 8 ) {
case V_96 :
F_47 ( V_147 ) ;
break;
case V_149 :
F_37 ( V_147 ) ;
break;
default:
F_38 ( & V_62 -> V_8 , L_13 ,
F_79 ( V_147 ) , V_147 -> V_154 ) ;
break;
}
}
static void F_82 ( struct V_60 * V_61 ,
unsigned long type )
{
struct V_7 * V_8 = V_61 -> V_63 ;
struct V_9 * V_22 ;
unsigned long V_107 = V_47 | V_48 |
V_49 | V_90 ;
unsigned V_155 = 0 ;
struct V_9 * V_100 ;
int V_18 = 1 ;
V_100 = & V_8 -> V_9 [ V_83 ] ;
if ( type & V_47 )
V_18 = 0 ;
else if ( ! ( type & V_49 ) )
V_18 = 1 ;
else if ( ( type & V_90 ) &&
( V_100 [ 2 ] . V_17 & V_90 ) )
V_18 = 2 ;
else if ( ! ( V_100 [ 2 ] . V_17 & V_90 ) &&
( V_100 [ 2 ] . V_17 & V_49 ) )
V_18 = 2 ;
else
V_18 = 1 ;
V_22 = & V_100 [ V_18 ] ;
if ( ! V_22 -> V_26 )
return;
F_83 ( V_22 ) ;
if ( ! F_34 ( V_22 ) ) {
type = V_155 = V_22 -> V_17 & V_107 ;
F_12 ( V_19 , & V_8 -> V_8 , L_14 ,
V_83 + V_18 , V_22 ) ;
V_22 -> V_16 = F_24 ( V_22 ) - 1 ;
V_22 -> V_15 = 0 ;
V_22 -> V_17 = 0 ;
if ( type & V_49 )
type = V_49 ;
F_46 ( V_61 , type ) ;
V_22 -> V_17 = V_155 ;
}
}
static void F_84 ( struct V_60 * V_61 ,
unsigned long type ,
enum V_156 V_157 )
{
struct V_7 * V_8 ;
bool V_158 = true ;
F_11 (dev, &bus->devices, bus_list) {
struct V_60 * V_147 = V_8 -> V_148 ;
if ( ! V_147 )
continue;
V_158 = false ;
if ( ( V_8 -> V_28 >> 8 ) != V_96 )
continue;
if ( V_157 == V_159 )
F_84 ( V_147 , type ,
V_159 ) ;
}
if ( F_71 ( V_61 ) )
return;
if ( ( V_61 -> V_63 -> V_28 >> 8 ) != V_96 )
return;
if ( ( V_157 == V_159 ) || V_158 )
F_82 ( V_61 , type ) ;
}
static void F_85 ( struct V_60 * V_61 )
{
struct V_9 * V_10 ;
int V_20 ;
F_54 (bus, res, i) {
if ( ! V_10 || ! V_10 -> V_16 || ! V_10 -> V_17 )
continue;
F_12 ( V_19 , & V_61 -> V_8 , L_15 , V_20 , V_10 ) ;
}
}
static void F_86 ( struct V_60 * V_61 )
{
struct V_60 * V_147 ;
struct V_7 * V_8 ;
F_85 ( V_61 ) ;
F_11 (dev, &bus->devices, bus_list) {
V_147 = V_8 -> V_148 ;
if ( ! V_147 )
continue;
F_86 ( V_147 ) ;
}
}
static int F_87 ( struct V_60 * V_61 )
{
int V_160 = 0 ;
struct V_60 * V_161 ;
F_11 (child_bus, &bus->children, node) {
int V_146 ;
V_146 = F_87 ( V_161 ) ;
if ( V_146 + 1 > V_160 )
V_160 = V_146 + 1 ;
}
return V_160 ;
}
void T_5 F_88 ( char * V_162 )
{
if ( ! strncmp ( V_162 , L_16 , 3 ) )
V_163 = V_164 ;
else if ( ! strncmp ( V_162 , L_17 , 2 ) )
V_163 = V_165 ;
}
static bool F_89 ( enum V_166 V_167 )
{
return V_167 >= V_165 ;
}
static int F_90 ( struct V_7 * V_8 , void * V_168 )
{
int V_20 ;
bool * V_169 = V_168 ;
for ( V_20 = V_130 ; V_20 <= V_131 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
struct V_64 V_65 ;
if ( ! V_22 -> V_17 )
continue;
F_39 ( V_8 -> V_61 , & V_65 , V_22 ) ;
if ( ! V_65 . V_15 ) {
* V_169 = true ;
return 1 ;
}
}
return 0 ;
}
static enum V_166 F_91 ( struct V_60 * V_61 ,
enum V_166 V_170 )
{
bool V_169 = false ;
if ( V_170 != V_171 )
return V_170 ;
F_92 ( V_61 , F_90 , & V_169 ) ;
if ( V_169 )
return V_172 ;
return V_170 ;
}
static enum V_166 F_91 ( struct V_60 * V_61 ,
enum V_166 V_170 )
{
return V_170 ;
}
void F_93 ( struct V_60 * V_61 )
{
F_31 ( V_36 ) ;
struct V_1 * V_173 = NULL ;
int V_174 = 0 ;
enum V_156 V_157 = V_175 ;
F_31 ( V_42 ) ;
struct V_3 * V_45 ;
unsigned long V_107 = V_47 | V_48 |
V_49 | V_90 ;
int V_176 = 1 ;
enum V_166 V_170 ;
V_170 = F_91 ( V_61 , V_163 ) ;
if ( F_89 ( V_170 ) ) {
int V_177 = F_87 ( V_61 ) ;
V_176 = V_177 + 1 ;
F_12 ( V_19 , & V_61 -> V_8 ,
L_18 ,
V_177 , V_176 ) ;
}
V_178:
if ( V_174 + 1 == V_176 )
V_173 = & V_36 ;
F_70 ( V_61 , V_173 ) ;
F_77 ( V_61 , V_173 , & V_42 ) ;
if ( V_173 )
F_94 ( ! F_32 ( V_173 ) ) ;
V_174 ++ ;
if ( F_32 ( & V_42 ) )
goto V_179;
if ( V_174 >= V_176 ) {
if ( V_170 == V_171 )
F_38 ( & V_61 -> V_8 , L_19 ) ;
else if ( V_170 == V_172 )
F_38 ( & V_61 -> V_8 , L_20 ) ;
F_1 ( & V_42 ) ;
goto V_179;
}
F_12 ( V_19 , & V_61 -> V_8 ,
L_21 , V_174 + 1 ) ;
if ( ( V_174 + 1 ) > 2 )
V_157 = V_159 ;
F_11 (fail_res, &fail_head, list)
F_84 ( V_45 -> V_8 -> V_61 ,
V_45 -> V_17 & V_107 ,
V_157 ) ;
F_11 (fail_res, &fail_head, list) {
struct V_9 * V_10 = V_45 -> V_10 ;
V_10 -> V_15 = V_45 -> V_15 ;
V_10 -> V_16 = V_45 -> V_16 ;
V_10 -> V_17 = V_45 -> V_17 ;
if ( V_45 -> V_8 -> V_148 )
V_10 -> V_17 = 0 ;
}
F_1 ( & V_42 ) ;
goto V_178;
V_179:
F_86 ( V_61 ) ;
}
void T_5 F_95 ( void )
{
struct V_60 * V_180 ;
F_11 (root_bus, &pci_root_buses, node)
F_93 ( V_180 ) ;
}
void F_96 ( struct V_7 * V_62 )
{
struct V_60 * V_26 = V_62 -> V_148 ;
F_31 ( V_173 ) ;
int V_174 = 0 ;
F_31 ( V_42 ) ;
struct V_3 * V_45 ;
int V_181 ;
unsigned long V_107 = V_47 | V_48 |
V_49 | V_90 ;
V_178:
F_70 ( V_26 , & V_173 ) ;
F_81 ( V_62 , & V_173 , & V_42 ) ;
F_94 ( ! F_32 ( & V_173 ) ) ;
V_174 ++ ;
if ( F_32 ( & V_42 ) )
goto V_182;
if ( V_174 >= 2 ) {
F_1 ( & V_42 ) ;
goto V_182;
}
F_97 ( V_19 L_22 ,
V_174 + 1 ) ;
F_11 (fail_res, &fail_head, list)
F_84 ( V_45 -> V_8 -> V_61 ,
V_45 -> V_17 & V_107 ,
V_159 ) ;
F_11 (fail_res, &fail_head, list) {
struct V_9 * V_10 = V_45 -> V_10 ;
V_10 -> V_15 = V_45 -> V_15 ;
V_10 -> V_16 = V_45 -> V_16 ;
V_10 -> V_17 = V_45 -> V_17 ;
if ( V_45 -> V_8 -> V_148 )
V_10 -> V_17 = 0 ;
}
F_1 ( & V_42 ) ;
goto V_178;
V_182:
V_181 = F_98 ( V_62 ) ;
if ( V_181 )
F_99 ( & V_62 -> V_8 , L_23 , V_181 ) ;
F_100 ( V_62 ) ;
}
void F_101 ( struct V_60 * V_61 )
{
struct V_7 * V_8 ;
F_31 ( V_173 ) ;
F_102 ( & V_183 ) ;
F_11 (dev, &bus->devices, bus_list)
if ( F_103 ( V_8 ) && F_104 ( V_8 ) )
F_70 ( V_8 -> V_148 ,
& V_173 ) ;
F_105 ( & V_183 ) ;
F_77 ( V_61 , & V_173 , NULL ) ;
F_94 ( ! F_32 ( & V_173 ) ) ;
}
