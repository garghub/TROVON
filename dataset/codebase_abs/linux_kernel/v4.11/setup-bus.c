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
if ( V_4 -> V_10 == V_10 )
return V_4 ;
}
return NULL ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 ;
V_4 = F_10 ( V_2 , V_10 ) ;
return V_4 ? V_4 -> V_11 : 0 ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 ;
V_4 = F_10 ( V_2 , V_10 ) ;
return V_4 ? V_4 -> V_12 : 0 ;
}
static void F_14 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
struct V_9 * V_20 ;
struct V_3 * V_4 , * V_5 ;
T_1 V_21 ;
struct V_1 * V_22 ;
V_20 = & V_8 -> V_9 [ V_18 ] ;
if ( V_20 -> V_17 & V_23 )
continue;
if ( ! ( V_20 -> V_17 ) || V_20 -> V_24 )
continue;
V_21 = F_15 ( V_8 , V_20 ) ;
if ( ! V_21 ) {
F_16 ( & V_8 -> V_8 , L_2 ,
V_18 , V_20 ) ;
continue;
}
V_5 = F_6 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 )
F_17 ( L_3 ) ;
V_5 -> V_10 = V_20 ;
V_5 -> V_8 = V_8 ;
V_22 = V_2 ;
F_11 (dev_res, head, list) {
T_1 V_25 ;
V_25 = F_15 ( V_4 -> V_8 ,
V_4 -> V_10 ) ;
if ( V_21 > V_25 ) {
V_22 = & V_4 -> V_6 ;
break;
}
}
F_18 ( & V_5 -> V_6 , V_22 ) ;
}
}
static void F_19 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
T_2 V_26 = V_8 -> V_26 >> 8 ;
if ( V_26 == V_27 || V_26 == V_28 )
return;
if ( V_26 == V_29 ) {
T_2 V_30 ;
F_20 ( V_8 , V_31 , & V_30 ) ;
if ( V_30 & ( V_32 | V_33 ) )
return;
}
F_14 ( V_8 , V_2 ) ;
}
static inline void F_21 ( struct V_9 * V_10 )
{
V_10 -> V_15 = 0 ;
V_10 -> V_16 = 0 ;
V_10 -> V_17 = 0 ;
}
static void F_22 ( struct V_1 * V_34 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_3 * V_35 , * V_5 ;
struct V_3 * V_4 ;
T_1 V_11 , V_25 ;
int V_36 ;
F_2 (add_res, tmp, realloc_head, list) {
bool V_37 = false ;
V_10 = V_35 -> V_10 ;
if ( ! V_10 -> V_17 )
goto V_38;
F_11 (dev_res, head, list) {
if ( V_4 -> V_10 == V_10 ) {
V_37 = true ;
break;
}
}
if ( ! V_37 )
continue;
V_36 = V_10 - & V_35 -> V_8 -> V_9 [ 0 ] ;
V_11 = V_35 -> V_11 ;
V_25 = V_35 -> V_12 ;
if ( ! F_23 ( V_10 ) ) {
V_10 -> V_15 = V_25 ;
V_10 -> V_16 = V_10 -> V_15 + V_11 - 1 ;
if ( F_24 ( V_35 -> V_8 , V_36 ) )
F_21 ( V_10 ) ;
} else {
V_10 -> V_17 |= V_35 -> V_17 &
( V_39 | V_40 ) ;
if ( F_25 ( V_35 -> V_8 , V_36 ,
V_11 , V_25 ) )
F_26 ( V_41 , & V_35 -> V_8 -> V_8 ,
L_4 ,
( unsigned long long ) V_11 ,
V_36 , V_10 ) ;
}
V_38:
F_3 ( & V_35 -> V_6 ) ;
F_4 ( V_35 ) ;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_1 * V_42 )
{
struct V_9 * V_10 ;
struct V_3 * V_4 ;
int V_36 ;
F_11 (dev_res, head, list) {
V_10 = V_4 -> V_10 ;
V_36 = V_10 - & V_4 -> V_8 -> V_9 [ 0 ] ;
if ( F_23 ( V_10 ) &&
F_24 ( V_4 -> V_8 , V_36 ) ) {
if ( V_42 ) {
if ( ! ( ( V_36 == V_43 ) &&
( ! ( V_10 -> V_17 & V_44 ) ) ) )
F_5 ( V_42 ,
V_4 -> V_8 , V_10 ,
0 ,
0 ) ;
}
F_21 ( V_10 ) ;
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
! ( V_10 -> V_24 -> V_17 & V_49 ) )
return true ;
else
return false ;
}
if ( V_10 -> V_17 & V_48 )
return ! ! ( V_46 & V_48 ) ;
return false ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_1 * V_34 ,
struct V_1 * V_42 )
{
F_31 ( V_50 ) ;
F_31 ( V_51 ) ;
struct V_3 * V_52 ;
struct V_3 * V_4 , * V_53 , * V_54 ;
unsigned long V_55 ;
T_1 V_56 , V_25 ;
if ( ! V_34 || F_32 ( V_34 ) )
goto V_57;
F_11 (dev_res, head, list) {
if ( F_5 ( & V_50 , V_4 -> V_8 , V_4 -> V_10 , 0 , 0 ) ) {
F_1 ( & V_50 ) ;
goto V_57;
}
}
F_2 (dev_res, tmp_res, head, list) {
V_4 -> V_10 -> V_16 += F_12 ( V_34 ,
V_4 -> V_10 ) ;
if ( ! ( V_4 -> V_10 -> V_17 & V_39 ) )
continue;
V_56 = F_13 ( V_34 , V_4 -> V_10 ) ;
if ( V_56 > V_4 -> V_10 -> V_15 ) {
T_1 V_58 = F_23 ( V_4 -> V_10 ) ;
V_4 -> V_10 -> V_15 = V_56 ;
V_4 -> V_10 -> V_16 = V_56 + V_58 - 1 ;
F_11 (dev_res2, head, list) {
V_25 = F_15 ( V_54 -> V_8 ,
V_54 -> V_10 ) ;
if ( V_56 > V_25 ) {
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
F_9 ( V_34 , V_4 -> V_10 ) ;
F_1 ( & V_50 ) ;
F_1 ( V_2 ) ;
return;
}
V_55 = F_28 ( & V_51 ) ;
F_2 (dev_res, tmp_res, head, list)
if ( V_4 -> V_10 -> V_24 &&
! F_29 ( V_55 , V_4 -> V_10 ) ) {
F_9 ( V_34 , V_4 -> V_10 ) ;
F_9 ( & V_50 , V_4 -> V_10 ) ;
F_3 ( & V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
}
F_1 ( & V_51 ) ;
F_11 (dev_res, head, list)
if ( V_4 -> V_10 -> V_24 )
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
if ( V_34 )
F_22 ( V_34 , V_2 ) ;
F_1 ( V_2 ) ;
}
static void F_35 ( struct V_7 * V_8 ,
struct V_1 * V_59 ,
struct V_1 * V_42 )
{
F_31 ( V_2 ) ;
F_19 ( V_8 , & V_2 ) ;
F_30 ( & V_2 , V_59 , V_42 ) ;
}
static void F_36 ( const struct V_60 * V_61 ,
struct V_1 * V_34 ,
struct V_1 * V_42 )
{
struct V_7 * V_8 ;
F_31 ( V_2 ) ;
F_11 (dev, &bus->devices, bus_list)
F_19 ( V_8 , & V_2 ) ;
F_30 ( & V_2 , V_34 , V_42 ) ;
}
void F_37 ( struct V_60 * V_61 )
{
struct V_7 * V_62 = V_61 -> V_63 ;
struct V_9 * V_10 ;
struct V_64 V_65 ;
F_38 ( & V_62 -> V_8 , L_5 ,
& V_61 -> V_66 ) ;
V_10 = V_61 -> V_9 [ 0 ] ;
F_39 ( V_62 -> V_61 , & V_65 , V_10 ) ;
if ( V_10 -> V_17 & V_47 ) {
F_38 ( & V_62 -> V_8 , L_6 , V_10 ) ;
F_40 ( V_62 , V_67 ,
V_65 . V_15 ) ;
F_40 ( V_62 , V_68 ,
V_65 . V_16 ) ;
}
V_10 = V_61 -> V_9 [ 1 ] ;
F_39 ( V_62 -> V_61 , & V_65 , V_10 ) ;
if ( V_10 -> V_17 & V_47 ) {
F_38 ( & V_62 -> V_8 , L_6 , V_10 ) ;
F_40 ( V_62 , V_69 ,
V_65 . V_15 ) ;
F_40 ( V_62 , V_70 ,
V_65 . V_16 ) ;
}
V_10 = V_61 -> V_9 [ 2 ] ;
F_39 ( V_62 -> V_61 , & V_65 , V_10 ) ;
if ( V_10 -> V_17 & V_48 ) {
F_38 ( & V_62 -> V_8 , L_6 , V_10 ) ;
F_40 ( V_62 , V_71 ,
V_65 . V_15 ) ;
F_40 ( V_62 , V_72 ,
V_65 . V_16 ) ;
}
V_10 = V_61 -> V_9 [ 3 ] ;
F_39 ( V_62 -> V_61 , & V_65 , V_10 ) ;
if ( V_10 -> V_17 & V_48 ) {
F_38 ( & V_62 -> V_8 , L_6 , V_10 ) ;
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
F_20 ( V_62 , V_84 , & V_78 ) ;
V_76 = ( V_65 . V_15 >> 8 ) & V_75 ;
V_77 = ( V_65 . V_16 >> 8 ) & V_75 ;
V_78 = ( ( T_2 ) V_77 << 8 ) | V_76 ;
V_79 = ( V_65 . V_16 & 0xffff0000 ) | ( V_65 . V_15 >> 16 ) ;
F_38 ( & V_62 -> V_8 , L_6 , V_10 ) ;
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
F_38 ( & V_62 -> V_8 , L_6 , V_10 ) ;
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
F_38 ( & V_62 -> V_8 , L_6 , V_10 ) ;
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
F_38 ( & V_62 -> V_8 , L_7 ,
& V_61 -> V_66 ) ;
if ( type & V_47 )
F_41 ( V_62 ) ;
if ( type & V_48 )
F_43 ( V_62 ) ;
if ( type & V_49 )
F_44 ( V_62 ) ;
F_42 ( V_62 , V_93 , V_61 -> V_94 ) ;
}
void __weak F_47 ( struct V_60 * V_61 , unsigned long type )
{
}
void F_48 ( struct V_60 * V_61 )
{
unsigned long type = V_47 | V_48 |
V_49 ;
F_47 ( V_61 , type ) ;
F_46 ( V_61 , type ) ;
}
int F_49 ( struct V_7 * V_62 , int V_18 )
{
if ( V_18 < V_83 || V_18 > V_95 )
return 0 ;
if ( F_50 ( V_62 , V_18 ) == 0 )
return 0 ;
if ( ( V_62 -> V_26 >> 8 ) != V_96 )
return 0 ;
if ( ! F_51 ( V_62 , V_18 ) )
return - V_97 ;
switch ( V_18 - V_83 ) {
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
if ( F_50 ( V_62 , V_18 ) == 0 )
return 0 ;
return - V_97 ;
}
static void F_52 ( struct V_60 * V_61 )
{
T_2 V_98 ;
T_4 V_99 ;
struct V_7 * V_62 = V_61 -> V_63 ;
struct V_9 * V_100 ;
V_100 = & V_62 -> V_9 [ V_83 ] ;
V_100 [ 1 ] . V_17 |= V_48 ;
F_20 ( V_62 , V_84 , & V_98 ) ;
if ( ! V_98 ) {
F_42 ( V_62 , V_84 , 0xe0f0 ) ;
F_20 ( V_62 , V_84 , & V_98 ) ;
F_42 ( V_62 , V_84 , 0x0 ) ;
}
if ( V_98 )
V_100 [ 0 ] . V_17 |= V_47 ;
if ( V_62 -> V_101 == V_102 && V_62 -> V_103 == 0x0001 )
return;
F_53 ( V_62 , V_91 , & V_99 ) ;
if ( ! V_99 ) {
F_40 ( V_62 , V_91 ,
0xffe0fff0 ) ;
F_53 ( V_62 , V_91 , & V_99 ) ;
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
F_53 ( V_62 , V_92 ,
& V_106 ) ;
F_40 ( V_62 , V_92 ,
0xffffffff ) ;
F_53 ( V_62 , V_92 , & V_5 ) ;
if ( ! V_5 )
V_100 [ 2 ] . V_17 &= ~ V_90 ;
F_40 ( V_62 , V_92 ,
V_106 ) ;
}
}
static struct V_9 * F_54 ( struct V_60 * V_61 ,
unsigned long V_107 , unsigned long type )
{
int V_18 ;
struct V_9 * V_20 ;
F_55 (bus, r, i) {
if ( V_20 == & V_108 || V_20 == & V_109 )
continue;
if ( V_20 && ( V_20 -> V_17 & V_107 ) == type && ! V_20 -> V_24 )
return V_20 ;
}
return NULL ;
}
static T_1 F_56 ( T_1 V_110 ,
T_1 V_111 ,
T_1 V_112 ,
T_1 V_113 ,
T_1 V_25 )
{
if ( V_110 < V_111 )
V_110 = V_111 ;
if ( V_113 == 1 )
V_113 = 0 ;
#if F_57 ( V_114 ) || F_57 ( V_115 )
V_110 = ( V_110 & 0xff ) + ( ( V_110 & ~ 0xffUL ) << 2 ) ;
#endif
V_110 = F_58 ( V_110 + V_112 , V_25 ) ;
if ( V_110 < V_113 )
V_110 = V_113 ;
return V_110 ;
}
static T_1 F_59 ( T_1 V_110 ,
T_1 V_111 ,
T_1 V_112 ,
T_1 V_113 ,
T_1 V_25 )
{
if ( V_110 < V_111 )
V_110 = V_111 ;
if ( V_113 == 1 )
V_113 = 0 ;
if ( V_110 < V_113 )
V_110 = V_113 ;
V_110 = F_58 ( V_110 + V_112 , V_25 ) ;
return V_110 ;
}
T_1 __weak F_60 ( struct V_60 * V_61 ,
unsigned long type )
{
return 1 ;
}
static T_1 F_61 ( struct V_60 * V_61 ,
unsigned long type )
{
T_1 V_25 = 1 , V_116 ;
if ( type & V_48 )
V_25 = V_117 ;
else if ( type & V_47 ) {
if ( V_61 -> V_63 -> V_81 )
V_25 = V_118 ;
else
V_25 = V_119 ;
}
V_116 = F_60 ( V_61 , type ) ;
return F_62 ( V_25 , V_116 ) ;
}
static void F_63 ( struct V_60 * V_61 , T_1 V_111 ,
T_1 V_11 , struct V_1 * V_34 )
{
struct V_7 * V_8 ;
struct V_9 * V_100 = F_54 ( V_61 , V_47 ,
V_47 ) ;
T_1 V_110 = 0 , V_120 = 0 , V_112 = 0 ;
T_1 V_121 = 0 ;
T_1 V_12 , V_25 ;
if ( ! V_100 )
return;
V_12 = F_61 ( V_61 , V_47 ) ;
F_11 (dev, &bus->devices, bus_list) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
struct V_9 * V_20 = & V_8 -> V_9 [ V_18 ] ;
unsigned long V_58 ;
if ( V_20 -> V_24 || ! ( V_20 -> V_17 & V_47 ) )
continue;
V_58 = F_23 ( V_20 ) ;
if ( V_58 < 0x400 )
V_110 += V_58 ;
else
V_112 += V_58 ;
V_25 = F_15 ( V_8 , V_20 ) ;
if ( V_25 > V_12 )
V_12 = V_25 ;
if ( V_34 )
V_121 += F_12 ( V_34 , V_20 ) ;
}
}
V_120 = F_56 ( V_110 , V_111 , V_112 ,
F_23 ( V_100 ) , V_12 ) ;
if ( V_121 > V_11 )
V_11 = V_121 ;
V_112 = ( ! V_34 || ( V_34 && ! V_11 ) ) ? V_120 :
F_56 ( V_110 , V_111 , V_11 + V_112 ,
F_23 ( V_100 ) , V_12 ) ;
if ( ! V_120 && ! V_112 ) {
if ( V_100 -> V_15 || V_100 -> V_16 )
F_38 ( & V_61 -> V_63 -> V_8 , L_8 ,
V_100 , & V_61 -> V_66 ) ;
V_100 -> V_17 = 0 ;
return;
}
V_100 -> V_15 = V_12 ;
V_100 -> V_16 = V_100 -> V_15 + V_120 - 1 ;
V_100 -> V_17 |= V_39 ;
if ( V_112 > V_120 && V_34 ) {
F_5 ( V_34 , V_61 -> V_63 , V_100 , V_112 - V_120 ,
V_12 ) ;
F_26 ( V_41 , & V_61 -> V_63 -> V_8 , L_9 ,
V_100 , & V_61 -> V_66 ,
( unsigned long long ) V_112 - V_120 ) ;
}
}
static inline T_1 F_64 ( T_1 * V_122 ,
int V_123 )
{
T_1 V_25 = 0 ;
T_1 V_12 = 0 ;
int V_124 ;
for ( V_124 = 0 ; V_124 <= V_123 ; V_124 ++ ) {
T_1 V_125 = 1 ;
V_125 <<= ( V_124 + 20 ) ;
if ( ! V_25 )
V_12 = V_125 ;
else if ( F_58 ( V_25 + V_12 , V_12 ) < V_125 )
V_12 = V_125 >> 1 ;
V_25 += V_122 [ V_124 ] ;
}
return V_12 ;
}
static int F_65 ( struct V_60 * V_61 , unsigned long V_46 ,
unsigned long type , unsigned long V_126 ,
unsigned long V_127 ,
T_1 V_111 , T_1 V_11 ,
struct V_1 * V_34 )
{
struct V_7 * V_8 ;
T_1 V_12 , V_25 , V_110 , V_120 , V_112 ;
T_1 V_122 [ 18 ] ;
int V_124 , V_123 ;
struct V_9 * V_100 = F_54 ( V_61 ,
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
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
struct V_9 * V_20 = & V_8 -> V_9 [ V_18 ] ;
T_1 V_58 ;
if ( V_20 -> V_24 || ( V_20 -> V_17 & V_23 ) ||
( ( V_20 -> V_17 & V_46 ) != type &&
( V_20 -> V_17 & V_46 ) != V_126 &&
( V_20 -> V_17 & V_46 ) != V_127 ) )
continue;
V_58 = F_23 ( V_20 ) ;
#ifdef F_66
if ( V_34 && V_18 >= V_130 &&
V_18 <= V_131 ) {
V_56 = F_62 ( F_15 ( V_8 , V_20 ) , V_56 ) ;
V_20 -> V_16 = V_20 -> V_15 - 1 ;
F_5 ( V_34 , V_8 , V_20 , V_58 , 0 ) ;
V_121 += V_58 ;
continue;
}
#endif
V_25 = F_15 ( V_8 , V_20 ) ;
V_124 = F_67 ( V_25 ) - 20 ;
if ( V_124 < 0 )
V_124 = 0 ;
if ( V_124 >= F_68 ( V_122 ) ) {
F_16 ( & V_8 -> V_8 , L_10 ,
V_18 , V_20 , ( unsigned long long ) V_25 ) ;
V_20 -> V_17 = 0 ;
continue;
}
V_110 += V_58 ;
if ( V_58 == V_25 )
V_122 [ V_124 ] += V_25 ;
if ( V_124 > V_123 )
V_123 = V_124 ;
if ( V_34 ) {
V_121 += F_12 ( V_34 , V_20 ) ;
V_128 = F_13 ( V_34 , V_20 ) ;
V_56 = F_62 ( V_56 , V_128 ) ;
}
}
}
V_12 = F_64 ( V_122 , V_123 ) ;
V_12 = F_62 ( V_12 , F_61 ( V_61 , V_100 -> V_17 ) ) ;
V_120 = F_59 ( V_110 , V_111 , 0 , F_23 ( V_100 ) , V_12 ) ;
V_56 = F_62 ( V_12 , V_56 ) ;
if ( V_121 > V_11 )
V_11 = V_121 ;
V_112 = ( ! V_34 || ( V_34 && ! V_11 ) ) ? V_120 :
F_59 ( V_110 , V_111 , V_11 ,
F_23 ( V_100 ) , V_56 ) ;
if ( ! V_120 && ! V_112 ) {
if ( V_100 -> V_15 || V_100 -> V_16 )
F_38 ( & V_61 -> V_63 -> V_8 , L_8 ,
V_100 , & V_61 -> V_66 ) ;
V_100 -> V_17 = 0 ;
return 0 ;
}
V_100 -> V_15 = V_12 ;
V_100 -> V_16 = V_120 + V_12 - 1 ;
V_100 -> V_17 |= V_39 ;
if ( V_112 > V_120 && V_34 ) {
F_5 ( V_34 , V_61 -> V_63 , V_100 , V_112 - V_120 , V_56 ) ;
F_26 ( V_41 , & V_61 -> V_63 -> V_8 , L_11 ,
V_100 , & V_61 -> V_66 ,
( unsigned long long ) ( V_112 - V_120 ) ,
( unsigned long long ) V_56 ) ;
}
return 0 ;
}
unsigned long F_69 ( struct V_9 * V_10 )
{
if ( V_10 -> V_17 & V_47 )
return V_132 ;
if ( V_10 -> V_17 & V_48 )
return V_133 ;
return 0 ;
}
static void F_70 ( struct V_60 * V_61 ,
struct V_1 * V_34 )
{
struct V_7 * V_62 = V_61 -> V_63 ;
struct V_9 * V_100 = & V_62 -> V_9 [ V_83 ] ;
T_1 V_134 = V_133 * 2 ;
T_2 V_135 ;
if ( V_100 [ 0 ] . V_24 )
goto V_136;
V_100 [ 0 ] . V_15 = V_132 ;
V_100 [ 0 ] . V_16 = V_100 [ 0 ] . V_15 + V_132 - 1 ;
V_100 [ 0 ] . V_17 |= V_47 | V_39 ;
if ( V_34 ) {
V_100 [ 0 ] . V_16 -= V_132 ;
F_5 ( V_34 , V_62 , V_100 , V_132 ,
V_132 ) ;
}
V_136:
if ( V_100 [ 1 ] . V_24 )
goto V_137;
V_100 [ 1 ] . V_15 = V_132 ;
V_100 [ 1 ] . V_16 = V_100 [ 1 ] . V_15 + V_132 - 1 ;
V_100 [ 1 ] . V_17 |= V_47 | V_39 ;
if ( V_34 ) {
V_100 [ 1 ] . V_16 -= V_132 ;
F_5 ( V_34 , V_62 , V_100 + 1 , V_132 ,
V_132 ) ;
}
V_137:
F_20 ( V_62 , V_138 , & V_135 ) ;
if ( V_135 & V_139 ) {
V_135 &= ~ V_139 ;
F_42 ( V_62 , V_138 , V_135 ) ;
F_20 ( V_62 , V_138 , & V_135 ) ;
}
F_20 ( V_62 , V_138 , & V_135 ) ;
if ( ! ( V_135 & V_140 ) ) {
V_135 |= V_140 ;
F_42 ( V_62 , V_138 , V_135 ) ;
F_20 ( V_62 , V_138 , & V_135 ) ;
}
if ( V_100 [ 2 ] . V_24 )
goto V_141;
if ( V_135 & V_140 ) {
V_100 [ 2 ] . V_15 = V_133 ;
V_100 [ 2 ] . V_16 = V_100 [ 2 ] . V_15 + V_133 - 1 ;
V_100 [ 2 ] . V_17 |= V_48 | V_49 |
V_39 ;
if ( V_34 ) {
V_100 [ 2 ] . V_16 -= V_133 ;
F_5 ( V_34 , V_62 , V_100 + 2 ,
V_133 , V_133 ) ;
}
V_134 = V_133 ;
}
V_141:
if ( V_100 [ 3 ] . V_24 )
goto V_142;
V_100 [ 3 ] . V_15 = V_133 ;
V_100 [ 3 ] . V_16 = V_100 [ 3 ] . V_15 + V_134 - 1 ;
V_100 [ 3 ] . V_17 |= V_48 | V_39 ;
if ( V_34 ) {
V_100 [ 3 ] . V_16 -= V_134 ;
F_5 ( V_34 , V_62 , V_100 + 3 , V_134 ,
V_133 ) ;
}
V_142:
;
}
void F_71 ( struct V_60 * V_61 , struct V_1 * V_34 )
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
switch ( V_8 -> V_26 >> 8 ) {
case V_149 :
F_70 ( V_147 , V_34 ) ;
break;
case V_96 :
default:
F_71 ( V_147 , V_34 ) ;
break;
}
}
if ( F_72 ( V_61 ) )
return;
switch ( V_61 -> V_63 -> V_26 >> 8 ) {
case V_149 :
break;
case V_96 :
F_52 ( V_61 ) ;
if ( V_61 -> V_63 -> V_150 ) {
V_145 = V_151 ;
V_144 = V_152 ;
}
default:
F_63 ( V_61 , V_34 ? 0 : V_145 ,
V_145 , V_34 ) ;
V_100 = & V_61 -> V_63 -> V_9 [ V_83 ] ;
V_46 = V_48 ;
V_143 = V_48 | V_49 ;
if ( V_100 [ 2 ] . V_17 & V_90 ) {
V_143 |= V_90 ;
V_146 = F_65 ( V_61 , V_143 , V_143 ,
V_143 , V_143 ,
V_34 ? 0 : V_144 ,
V_144 , V_34 ) ;
if ( V_146 == 0 ) {
V_46 = V_143 ;
V_126 = V_143 & ~ V_90 ;
V_127 = V_143 & ~ V_49 ;
}
}
if ( ! V_126 ) {
V_143 &= ~ V_90 ;
V_146 = F_65 ( V_61 , V_143 , V_143 ,
V_143 , V_143 ,
V_34 ? 0 : V_144 ,
V_144 , V_34 ) ;
if ( V_146 == 0 )
V_46 = V_143 ;
else
V_144 += V_144 ;
V_126 = V_127 = V_48 ;
}
F_65 ( V_61 , V_46 , V_48 , V_126 , V_127 ,
V_34 ? 0 : V_144 ,
V_144 , V_34 ) ;
break;
}
}
void F_73 ( struct V_60 * V_61 )
{
F_71 ( V_61 , NULL ) ;
}
static void F_74 ( struct V_60 * V_147 , struct V_9 * V_20 )
{
int V_18 ;
struct V_9 * V_153 ;
unsigned long V_46 = V_47 | V_48 |
V_49 ;
F_55 (b, parent_r, i) {
if ( ! V_153 )
continue;
if ( ( V_20 -> V_17 & V_46 ) == ( V_153 -> V_17 & V_46 ) &&
F_75 ( V_153 , V_20 ) )
F_76 ( V_153 , V_20 ) ;
}
}
static void F_77 ( struct V_7 * V_8 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
struct V_60 * V_147 ;
struct V_9 * V_20 = & V_8 -> V_9 [ V_18 ] ;
if ( V_20 -> V_24 || ! ( V_20 -> V_17 & V_23 ) ||
! ( V_20 -> V_17 & ( V_47 | V_48 ) ) )
continue;
V_147 = V_8 -> V_61 ;
while ( V_147 && ! V_20 -> V_24 ) {
F_74 ( V_147 , V_20 ) ;
V_147 = V_147 -> V_24 ;
}
}
}
void F_78 ( const struct V_60 * V_61 ,
struct V_1 * V_34 ,
struct V_1 * V_42 )
{
struct V_60 * V_147 ;
struct V_7 * V_8 ;
F_36 ( V_61 , V_34 , V_42 ) ;
F_11 (dev, &bus->devices, bus_list) {
F_77 ( V_8 ) ;
V_147 = V_8 -> V_148 ;
if ( ! V_147 )
continue;
F_78 ( V_147 , V_34 , V_42 ) ;
switch ( V_8 -> V_26 >> 8 ) {
case V_96 :
if ( ! F_79 ( V_8 ) )
F_48 ( V_147 ) ;
break;
case V_149 :
F_37 ( V_147 ) ;
break;
default:
F_38 ( & V_8 -> V_8 , L_12 ,
F_80 ( V_147 ) , V_147 -> V_154 ) ;
break;
}
}
}
void F_81 ( const struct V_60 * V_61 )
{
F_78 ( V_61 , NULL , NULL ) ;
}
static void F_82 ( struct V_7 * V_8 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_83 ; V_18 ++ ) {
struct V_9 * V_20 = & V_8 -> V_9 [ V_18 ] ;
if ( ! V_20 -> V_17 || V_20 -> V_24 )
continue;
F_50 ( V_8 , V_18 ) ;
}
}
static void F_83 ( struct V_7 * V_8 )
{
int V_18 ;
for ( V_18 = V_83 ; V_18 < V_19 ; V_18 ++ ) {
struct V_9 * V_20 = & V_8 -> V_9 [ V_18 ] ;
if ( ! V_20 -> V_17 || V_20 -> V_24 )
continue;
F_49 ( V_8 , V_18 ) ;
}
}
static void F_84 ( struct V_60 * V_147 )
{
struct V_7 * V_8 ;
struct V_60 * V_155 ;
F_11 (dev, &b->devices, bus_list) {
F_82 ( V_8 ) ;
V_155 = V_8 -> V_148 ;
if ( V_155 )
F_84 ( V_155 ) ;
}
}
static void F_85 ( struct V_60 * V_147 )
{
struct V_60 * V_155 ;
if ( V_147 -> V_63 ) {
F_86 ( V_147 ) ;
F_83 ( V_147 -> V_63 ) ;
}
F_11 (child, &b->children, node)
F_85 ( V_155 ) ;
}
void F_87 ( struct V_60 * V_147 )
{
F_85 ( V_147 ) ;
F_84 ( V_147 ) ;
}
static void F_88 ( const struct V_7 * V_62 ,
struct V_1 * V_59 ,
struct V_1 * V_42 )
{
struct V_60 * V_147 ;
F_35 ( (struct V_7 * ) V_62 ,
V_59 , V_42 ) ;
V_147 = V_62 -> V_148 ;
if ( ! V_147 )
return;
F_78 ( V_147 , V_59 , V_42 ) ;
switch ( V_62 -> V_26 >> 8 ) {
case V_96 :
F_48 ( V_147 ) ;
break;
case V_149 :
F_37 ( V_147 ) ;
break;
default:
F_38 ( & V_62 -> V_8 , L_12 ,
F_80 ( V_147 ) , V_147 -> V_154 ) ;
break;
}
}
static void F_89 ( struct V_60 * V_61 ,
unsigned long type )
{
struct V_7 * V_8 = V_61 -> V_63 ;
struct V_9 * V_20 ;
unsigned long V_107 = V_47 | V_48 |
V_49 | V_90 ;
unsigned V_156 = 0 ;
struct V_9 * V_100 ;
int V_36 = 1 ;
V_100 = & V_8 -> V_9 [ V_83 ] ;
if ( type & V_47 )
V_36 = 0 ;
else if ( ! ( type & V_49 ) )
V_36 = 1 ;
else if ( ( type & V_90 ) &&
( V_100 [ 2 ] . V_17 & V_90 ) )
V_36 = 2 ;
else if ( ! ( V_100 [ 2 ] . V_17 & V_90 ) &&
( V_100 [ 2 ] . V_17 & V_49 ) )
V_36 = 2 ;
else
V_36 = 1 ;
V_20 = & V_100 [ V_36 ] ;
if ( ! V_20 -> V_24 )
return;
F_90 ( V_20 ) ;
if ( ! F_34 ( V_20 ) ) {
type = V_156 = V_20 -> V_17 & V_107 ;
F_26 ( V_41 , & V_8 -> V_8 , L_13 ,
V_83 + V_36 , V_20 ) ;
V_20 -> V_16 = F_23 ( V_20 ) - 1 ;
V_20 -> V_15 = 0 ;
V_20 -> V_17 = 0 ;
if ( type & V_49 )
type = V_49 ;
F_46 ( V_61 , type ) ;
V_20 -> V_17 = V_156 ;
}
}
static void F_91 ( struct V_60 * V_61 ,
unsigned long type ,
enum V_157 V_158 )
{
struct V_7 * V_8 ;
bool V_159 = true ;
F_11 (dev, &bus->devices, bus_list) {
struct V_60 * V_147 = V_8 -> V_148 ;
if ( ! V_147 )
continue;
V_159 = false ;
if ( ( V_8 -> V_26 >> 8 ) != V_96 )
continue;
if ( V_158 == V_160 )
F_91 ( V_147 , type ,
V_160 ) ;
}
if ( F_72 ( V_61 ) )
return;
if ( ( V_61 -> V_63 -> V_26 >> 8 ) != V_96 )
return;
if ( ( V_158 == V_160 ) || V_159 )
F_89 ( V_61 , type ) ;
}
static void F_92 ( struct V_60 * V_61 )
{
struct V_9 * V_10 ;
int V_18 ;
F_55 (bus, res, i) {
if ( ! V_10 || ! V_10 -> V_16 || ! V_10 -> V_17 )
continue;
F_26 ( V_41 , & V_61 -> V_8 , L_14 , V_18 , V_10 ) ;
}
}
static void F_93 ( struct V_60 * V_61 )
{
struct V_60 * V_147 ;
struct V_7 * V_8 ;
F_92 ( V_61 ) ;
F_11 (dev, &bus->devices, bus_list) {
V_147 = V_8 -> V_148 ;
if ( ! V_147 )
continue;
F_93 ( V_147 ) ;
}
}
static int F_94 ( struct V_60 * V_61 )
{
int V_161 = 0 ;
struct V_60 * V_162 ;
F_11 (child_bus, &bus->children, node) {
int V_146 ;
V_146 = F_94 ( V_162 ) ;
if ( V_146 + 1 > V_161 )
V_161 = V_146 + 1 ;
}
return V_161 ;
}
void T_5 F_95 ( char * V_163 )
{
if ( ! strncmp ( V_163 , L_15 , 3 ) )
V_164 = V_165 ;
else if ( ! strncmp ( V_163 , L_16 , 2 ) )
V_164 = V_166 ;
}
static bool F_96 ( enum V_167 V_168 )
{
return V_168 >= V_166 ;
}
static int F_97 ( struct V_7 * V_8 , void * V_169 )
{
int V_18 ;
bool * V_170 = V_169 ;
for ( V_18 = V_130 ; V_18 <= V_131 ; V_18 ++ ) {
struct V_9 * V_20 = & V_8 -> V_9 [ V_18 ] ;
struct V_64 V_65 ;
if ( ! V_20 -> V_17 )
continue;
F_39 ( V_8 -> V_61 , & V_65 , V_20 ) ;
if ( ! V_65 . V_15 ) {
* V_170 = true ;
return 1 ;
}
}
return 0 ;
}
static enum V_167 F_98 ( struct V_60 * V_61 ,
enum V_167 V_171 )
{
bool V_170 = false ;
if ( V_171 != V_172 )
return V_171 ;
F_99 ( V_61 , F_97 , & V_170 ) ;
if ( V_170 )
return V_173 ;
return V_171 ;
}
static enum V_167 F_98 ( struct V_60 * V_61 ,
enum V_167 V_171 )
{
return V_171 ;
}
void F_100 ( struct V_60 * V_61 )
{
F_31 ( V_34 ) ;
struct V_1 * V_174 = NULL ;
int V_175 = 0 ;
enum V_157 V_158 = V_176 ;
F_31 ( V_42 ) ;
struct V_3 * V_45 ;
unsigned long V_107 = V_47 | V_48 |
V_49 | V_90 ;
int V_177 = 1 ;
enum V_167 V_171 ;
V_171 = F_98 ( V_61 , V_164 ) ;
if ( F_96 ( V_171 ) ) {
int V_178 = F_94 ( V_61 ) ;
V_177 = V_178 + 1 ;
F_26 ( V_41 , & V_61 -> V_8 ,
L_17 ,
V_178 , V_177 ) ;
}
V_179:
if ( V_175 + 1 == V_177 )
V_174 = & V_34 ;
F_71 ( V_61 , V_174 ) ;
F_78 ( V_61 , V_174 , & V_42 ) ;
if ( V_174 )
F_101 ( ! F_32 ( V_174 ) ) ;
V_175 ++ ;
if ( F_32 ( & V_42 ) )
goto V_180;
if ( V_175 >= V_177 ) {
if ( V_171 == V_172 )
F_38 ( & V_61 -> V_8 , L_18 ) ;
else if ( V_171 == V_173 )
F_38 ( & V_61 -> V_8 , L_19 ) ;
F_1 ( & V_42 ) ;
goto V_180;
}
F_26 ( V_41 , & V_61 -> V_8 ,
L_20 , V_175 + 1 ) ;
if ( ( V_175 + 1 ) > 2 )
V_158 = V_160 ;
F_11 (fail_res, &fail_head, list)
F_91 ( V_45 -> V_8 -> V_61 ,
V_45 -> V_17 & V_107 ,
V_158 ) ;
F_11 (fail_res, &fail_head, list) {
struct V_9 * V_10 = V_45 -> V_10 ;
V_10 -> V_15 = V_45 -> V_15 ;
V_10 -> V_16 = V_45 -> V_16 ;
V_10 -> V_17 = V_45 -> V_17 ;
if ( V_45 -> V_8 -> V_148 )
V_10 -> V_17 = 0 ;
}
F_1 ( & V_42 ) ;
goto V_179;
V_180:
F_93 ( V_61 ) ;
}
void T_5 F_102 ( void )
{
struct V_60 * V_181 ;
F_11 (root_bus, &pci_root_buses, node) {
F_100 ( V_181 ) ;
if ( F_103 ( V_181 -> V_62 ) )
F_104 ( F_103 ( V_181 -> V_62 ) ) ;
}
}
void F_105 ( struct V_7 * V_62 )
{
struct V_60 * V_24 = V_62 -> V_148 ;
F_31 ( V_174 ) ;
int V_175 = 0 ;
F_31 ( V_42 ) ;
struct V_3 * V_45 ;
int V_182 ;
unsigned long V_107 = V_47 | V_48 |
V_49 | V_90 ;
V_179:
F_71 ( V_24 , & V_174 ) ;
F_88 ( V_62 , & V_174 , & V_42 ) ;
F_101 ( ! F_32 ( & V_174 ) ) ;
V_175 ++ ;
if ( F_32 ( & V_42 ) )
goto V_183;
if ( V_175 >= 2 ) {
F_1 ( & V_42 ) ;
goto V_183;
}
F_106 ( V_41 L_21 ,
V_175 + 1 ) ;
F_11 (fail_res, &fail_head, list)
F_91 ( V_45 -> V_8 -> V_61 ,
V_45 -> V_17 & V_107 ,
V_160 ) ;
F_11 (fail_res, &fail_head, list) {
struct V_9 * V_10 = V_45 -> V_10 ;
V_10 -> V_15 = V_45 -> V_15 ;
V_10 -> V_16 = V_45 -> V_16 ;
V_10 -> V_17 = V_45 -> V_17 ;
if ( V_45 -> V_8 -> V_148 )
V_10 -> V_17 = 0 ;
}
F_1 ( & V_42 ) ;
goto V_179;
V_183:
V_182 = F_107 ( V_62 ) ;
if ( V_182 )
F_108 ( & V_62 -> V_8 , L_22 , V_182 ) ;
F_109 ( V_62 ) ;
}
void F_110 ( struct V_60 * V_61 )
{
struct V_7 * V_8 ;
F_31 ( V_174 ) ;
F_111 ( & V_184 ) ;
F_11 (dev, &bus->devices, bus_list)
if ( F_112 ( V_8 ) && F_113 ( V_8 ) )
F_71 ( V_8 -> V_148 ,
& V_174 ) ;
F_114 ( & V_184 ) ;
F_78 ( V_61 , & V_174 , NULL ) ;
F_101 ( ! F_32 ( & V_174 ) ) ;
}
