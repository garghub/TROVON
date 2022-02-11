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
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 ;
F_11 (dev_res, head, list) {
if ( V_4 -> V_10 == V_10 ) {
int V_18 = V_10 - & V_4 -> V_8 -> V_9 [ 0 ] ;
F_12 ( V_19 , & V_4 -> V_8 -> V_8 ,
L_2 ,
V_18 , V_4 -> V_10 ,
( unsigned long long ) V_4 -> V_11 ) ;
return V_4 -> V_11 ;
}
}
return 0 ;
}
static void F_13 ( struct V_7 * V_8 , struct V_1 * V_2 )
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
V_23 = F_14 ( V_8 , V_22 ) ;
if ( ! V_23 ) {
F_15 ( & V_8 -> V_8 , L_3 ,
V_20 , V_22 ) ;
continue;
}
V_5 = F_6 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 )
F_16 ( L_4
L_5 ) ;
V_5 -> V_10 = V_22 ;
V_5 -> V_8 = V_8 ;
V_24 = V_2 ;
F_11 (dev_res, head, list) {
T_1 V_27 ;
V_27 = F_14 ( V_4 -> V_8 ,
V_4 -> V_10 ) ;
if ( V_23 > V_27 ) {
V_24 = & V_4 -> V_6 ;
break;
}
}
F_17 ( & V_5 -> V_6 , V_24 ) ;
}
}
static void F_18 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
T_2 V_28 = V_8 -> V_28 >> 8 ;
if ( V_28 == V_29 || V_28 == V_30 )
return;
if ( V_28 == V_31 ) {
T_2 V_32 ;
F_19 ( V_8 , V_33 , & V_32 ) ;
if ( V_32 & ( V_34 | V_35 ) )
return;
}
F_13 ( V_8 , V_2 ) ;
}
static inline void F_20 ( struct V_9 * V_10 )
{
V_10 -> V_15 = 0 ;
V_10 -> V_16 = 0 ;
V_10 -> V_17 = 0 ;
}
static void F_21 ( struct V_1 * V_36 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_3 * V_37 , * V_5 ;
struct V_3 * V_4 ;
T_1 V_11 ;
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
if ( ! F_22 ( V_10 ) ) {
V_10 -> V_15 = V_37 -> V_15 ;
V_10 -> V_16 = V_10 -> V_15 + V_11 - 1 ;
if ( F_23 ( V_37 -> V_8 , V_18 ) )
F_20 ( V_10 ) ;
} else {
T_1 V_27 = V_37 -> V_12 ;
V_10 -> V_17 |= V_37 -> V_17 &
( V_40 | V_41 ) ;
if ( F_24 ( V_37 -> V_8 , V_18 ,
V_11 , V_27 ) )
F_12 ( V_19 , & V_37 -> V_8 -> V_8 ,
L_6 ,
( unsigned long long ) V_11 ,
V_18 , V_10 ) ;
}
V_39:
F_3 ( & V_37 -> V_6 ) ;
F_4 ( V_37 ) ;
}
}
static void F_25 ( struct V_1 * V_2 ,
struct V_1 * V_42 )
{
struct V_9 * V_10 ;
struct V_3 * V_4 ;
int V_18 ;
F_11 (dev_res, head, list) {
V_10 = V_4 -> V_10 ;
V_18 = V_10 - & V_4 -> V_8 -> V_9 [ 0 ] ;
if ( F_22 ( V_10 ) &&
F_23 ( V_4 -> V_8 , V_18 ) ) {
if ( V_42 ) {
if ( ! ( ( V_18 == V_43 ) &&
( ! ( V_10 -> V_17 & V_44 ) ) ) )
F_5 ( V_42 ,
V_4 -> V_8 , V_10 ,
0 ,
0 ) ;
}
F_20 ( V_10 ) ;
}
}
}
static unsigned long F_26 ( struct V_1 * V_42 )
{
struct V_3 * V_45 ;
unsigned long V_46 = 0 ;
F_11 (fail_res, fail_head, list)
V_46 |= V_45 -> V_17 ;
return V_46 & ( V_47 | V_48 | V_49 ) ;
}
static bool F_27 ( unsigned long V_46 , struct V_9 * V_10 )
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
static void F_28 ( struct V_1 * V_2 ,
struct V_1 * V_36 ,
struct V_1 * V_42 )
{
F_29 ( V_50 ) ;
F_29 ( V_51 ) ;
struct V_3 * V_52 ;
struct V_3 * V_4 , * V_53 ;
unsigned long V_54 ;
if ( ! V_36 || F_30 ( V_36 ) )
goto V_55;
F_11 (dev_res, head, list) {
if ( F_5 ( & V_50 , V_4 -> V_8 , V_4 -> V_10 , 0 , 0 ) ) {
F_1 ( & V_50 ) ;
goto V_55;
}
}
F_11 (dev_res, head, list)
V_4 -> V_10 -> V_16 += F_10 ( V_36 ,
V_4 -> V_10 ) ;
F_25 ( V_2 , & V_51 ) ;
if ( F_30 ( & V_51 ) ) {
F_11 (dev_res, head, list)
F_9 ( V_36 , V_4 -> V_10 ) ;
F_1 ( & V_50 ) ;
F_1 ( V_2 ) ;
return;
}
V_54 = F_26 ( & V_51 ) ;
F_2 (dev_res, tmp_res, head, list)
if ( V_4 -> V_10 -> V_26 &&
! F_27 ( V_54 , V_4 -> V_10 ) ) {
F_9 ( V_36 , V_4 -> V_10 ) ;
F_9 ( & V_50 , V_4 -> V_10 ) ;
F_3 ( & V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
}
F_1 ( & V_51 ) ;
F_11 (dev_res, head, list)
if ( V_4 -> V_10 -> V_26 )
F_31 ( V_4 -> V_10 ) ;
F_11 (save_res, &save_head, list) {
struct V_9 * V_10 = V_52 -> V_10 ;
V_10 -> V_15 = V_52 -> V_15 ;
V_10 -> V_16 = V_52 -> V_16 ;
V_10 -> V_17 = V_52 -> V_17 ;
}
F_1 ( & V_50 ) ;
V_55:
F_25 ( V_2 , V_42 ) ;
if ( V_36 )
F_21 ( V_36 , V_2 ) ;
F_1 ( V_2 ) ;
}
static void F_32 ( struct V_7 * V_8 ,
struct V_1 * V_56 ,
struct V_1 * V_42 )
{
F_29 ( V_2 ) ;
F_18 ( V_8 , & V_2 ) ;
F_28 ( & V_2 , V_56 , V_42 ) ;
}
static void F_33 ( const struct V_57 * V_58 ,
struct V_1 * V_36 ,
struct V_1 * V_42 )
{
struct V_7 * V_8 ;
F_29 ( V_2 ) ;
F_11 (dev, &bus->devices, bus_list)
F_18 ( V_8 , & V_2 ) ;
F_28 ( & V_2 , V_36 , V_42 ) ;
}
void F_34 ( struct V_57 * V_58 )
{
struct V_7 * V_59 = V_58 -> V_60 ;
struct V_9 * V_10 ;
struct V_61 V_62 ;
F_35 ( & V_59 -> V_8 , L_7 ,
& V_58 -> V_63 ) ;
V_10 = V_58 -> V_9 [ 0 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_47 ) {
F_35 ( & V_59 -> V_8 , L_8 , V_10 ) ;
F_37 ( V_59 , V_64 ,
V_62 . V_15 ) ;
F_37 ( V_59 , V_65 ,
V_62 . V_16 ) ;
}
V_10 = V_58 -> V_9 [ 1 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_47 ) {
F_35 ( & V_59 -> V_8 , L_8 , V_10 ) ;
F_37 ( V_59 , V_66 ,
V_62 . V_15 ) ;
F_37 ( V_59 , V_67 ,
V_62 . V_16 ) ;
}
V_10 = V_58 -> V_9 [ 2 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_48 ) {
F_35 ( & V_59 -> V_8 , L_8 , V_10 ) ;
F_37 ( V_59 , V_68 ,
V_62 . V_15 ) ;
F_37 ( V_59 , V_69 ,
V_62 . V_16 ) ;
}
V_10 = V_58 -> V_9 [ 3 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_48 ) {
F_35 ( & V_59 -> V_8 , L_8 , V_10 ) ;
F_37 ( V_59 , V_70 ,
V_62 . V_15 ) ;
F_37 ( V_59 , V_71 ,
V_62 . V_16 ) ;
}
}
static void F_38 ( struct V_57 * V_58 )
{
struct V_7 * V_59 = V_58 -> V_60 ;
struct V_9 * V_10 ;
struct V_61 V_62 ;
unsigned long V_72 ;
T_3 V_73 , V_74 ;
T_2 V_75 ;
T_4 V_76 ;
V_72 = V_77 ;
if ( V_59 -> V_78 )
V_72 = V_79 ;
V_10 = V_58 -> V_9 [ 0 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_47 ) {
F_19 ( V_59 , V_80 , & V_75 ) ;
V_73 = ( V_62 . V_15 >> 8 ) & V_72 ;
V_74 = ( V_62 . V_16 >> 8 ) & V_72 ;
V_75 = ( ( T_2 ) V_74 << 8 ) | V_73 ;
V_76 = ( V_62 . V_16 & 0xffff0000 ) | ( V_62 . V_15 >> 16 ) ;
F_35 ( & V_59 -> V_8 , L_8 , V_10 ) ;
} else {
V_76 = 0 ;
V_75 = 0x00f0 ;
}
F_37 ( V_59 , V_81 , 0x0000ffff ) ;
F_39 ( V_59 , V_80 , V_75 ) ;
F_37 ( V_59 , V_81 , V_76 ) ;
}
static void F_40 ( struct V_57 * V_58 )
{
struct V_7 * V_59 = V_58 -> V_60 ;
struct V_9 * V_10 ;
struct V_61 V_62 ;
T_4 V_75 ;
V_10 = V_58 -> V_9 [ 1 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_48 ) {
V_75 = ( V_62 . V_15 >> 16 ) & 0xfff0 ;
V_75 |= V_62 . V_16 & 0xfff00000 ;
F_35 ( & V_59 -> V_8 , L_8 , V_10 ) ;
} else {
V_75 = 0x0000fff0 ;
}
F_37 ( V_59 , V_82 , V_75 ) ;
}
static void F_41 ( struct V_57 * V_58 )
{
struct V_7 * V_59 = V_58 -> V_60 ;
struct V_9 * V_10 ;
struct V_61 V_62 ;
T_4 V_75 , V_83 , V_84 ;
F_37 ( V_59 , V_85 , 0 ) ;
V_83 = V_84 = 0 ;
V_10 = V_58 -> V_9 [ 2 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_49 ) {
V_75 = ( V_62 . V_15 >> 16 ) & 0xfff0 ;
V_75 |= V_62 . V_16 & 0xfff00000 ;
if ( V_10 -> V_17 & V_86 ) {
V_83 = F_42 ( V_62 . V_15 ) ;
V_84 = F_42 ( V_62 . V_16 ) ;
}
F_35 ( & V_59 -> V_8 , L_8 , V_10 ) ;
} else {
V_75 = 0x0000fff0 ;
}
F_37 ( V_59 , V_87 , V_75 ) ;
F_37 ( V_59 , V_88 , V_83 ) ;
F_37 ( V_59 , V_85 , V_84 ) ;
}
static void F_43 ( struct V_57 * V_58 , unsigned long type )
{
struct V_7 * V_59 = V_58 -> V_60 ;
F_35 ( & V_59 -> V_8 , L_9 ,
& V_58 -> V_63 ) ;
if ( type & V_47 )
F_38 ( V_58 ) ;
if ( type & V_48 )
F_40 ( V_58 ) ;
if ( type & V_49 )
F_41 ( V_58 ) ;
F_39 ( V_59 , V_89 , V_58 -> V_90 ) ;
}
void F_44 ( struct V_57 * V_58 )
{
unsigned long type = V_47 | V_48 |
V_49 ;
F_43 ( V_58 , type ) ;
}
static void F_45 ( struct V_57 * V_58 )
{
T_2 V_91 ;
T_4 V_92 ;
struct V_7 * V_59 = V_58 -> V_60 ;
struct V_9 * V_93 ;
V_93 = & V_59 -> V_9 [ V_94 ] ;
V_93 [ 1 ] . V_17 |= V_48 ;
F_19 ( V_59 , V_80 , & V_91 ) ;
if ( ! V_91 ) {
F_39 ( V_59 , V_80 , 0xe0f0 ) ;
F_19 ( V_59 , V_80 , & V_91 ) ;
F_39 ( V_59 , V_80 , 0x0 ) ;
}
if ( V_91 )
V_93 [ 0 ] . V_17 |= V_47 ;
if ( V_59 -> V_95 == V_96 && V_59 -> V_97 == 0x0001 )
return;
F_46 ( V_59 , V_87 , & V_92 ) ;
if ( ! V_92 ) {
F_37 ( V_59 , V_87 ,
0xffe0fff0 ) ;
F_46 ( V_59 , V_87 , & V_92 ) ;
F_37 ( V_59 , V_87 , 0x0 ) ;
}
if ( V_92 ) {
V_93 [ 2 ] . V_17 |= V_48 | V_49 ;
if ( ( V_92 & V_98 ) ==
V_99 ) {
V_93 [ 2 ] . V_17 |= V_86 ;
V_93 [ 2 ] . V_17 |= V_99 ;
}
}
if ( V_93 [ 2 ] . V_17 & V_86 ) {
T_4 V_100 , V_5 ;
F_46 ( V_59 , V_88 ,
& V_100 ) ;
F_37 ( V_59 , V_88 ,
0xffffffff ) ;
F_46 ( V_59 , V_88 , & V_5 ) ;
if ( ! V_5 )
V_93 [ 2 ] . V_17 &= ~ V_86 ;
F_37 ( V_59 , V_88 ,
V_100 ) ;
}
}
static struct V_9 * F_47 ( struct V_57 * V_58 , unsigned long type )
{
int V_20 ;
struct V_9 * V_22 ;
unsigned long V_101 = V_47 | V_48 |
V_49 ;
F_48 (bus, r, i) {
if ( V_22 == & V_102 || V_22 == & V_103 )
continue;
if ( V_22 && ( V_22 -> V_17 & V_101 ) == type && ! V_22 -> V_26 )
return V_22 ;
}
return NULL ;
}
static T_1 F_49 ( T_1 V_104 ,
T_1 V_105 ,
T_1 V_106 ,
T_1 V_107 ,
T_1 V_27 )
{
if ( V_104 < V_105 )
V_104 = V_105 ;
if ( V_107 == 1 )
V_107 = 0 ;
#if F_50 ( V_108 ) || F_50 ( V_109 )
V_104 = ( V_104 & 0xff ) + ( ( V_104 & ~ 0xffUL ) << 2 ) ;
#endif
V_104 = F_51 ( V_104 + V_106 , V_27 ) ;
if ( V_104 < V_107 )
V_104 = V_107 ;
return V_104 ;
}
static T_1 F_52 ( T_1 V_104 ,
T_1 V_105 ,
T_1 V_106 ,
T_1 V_107 ,
T_1 V_27 )
{
if ( V_104 < V_105 )
V_104 = V_105 ;
if ( V_107 == 1 )
V_107 = 0 ;
if ( V_104 < V_107 )
V_104 = V_107 ;
V_104 = F_51 ( V_104 + V_106 , V_27 ) ;
return V_104 ;
}
T_1 __weak F_53 ( struct V_57 * V_58 ,
unsigned long type )
{
return 1 ;
}
static T_1 F_54 ( struct V_57 * V_58 ,
unsigned long type )
{
T_1 V_27 = 1 , V_110 ;
if ( type & V_48 )
V_27 = V_111 ;
else if ( type & V_47 ) {
if ( V_58 -> V_60 -> V_78 )
V_27 = V_112 ;
else
V_27 = V_113 ;
}
V_110 = F_53 ( V_58 , type ) ;
return F_55 ( V_27 , V_110 ) ;
}
static void F_56 ( struct V_57 * V_58 , T_1 V_105 ,
T_1 V_11 , struct V_1 * V_36 )
{
struct V_7 * V_8 ;
struct V_9 * V_93 = F_47 ( V_58 , V_47 ) ;
T_1 V_104 = 0 , V_114 = 0 , V_106 = 0 ;
T_1 V_115 = 0 ;
T_1 V_12 , V_27 ;
if ( ! V_93 )
return;
V_12 = F_54 ( V_58 , V_47 ) ;
F_11 (dev, &bus->devices, bus_list) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
unsigned long V_116 ;
if ( V_22 -> V_26 || ! ( V_22 -> V_17 & V_47 ) )
continue;
V_116 = F_22 ( V_22 ) ;
if ( V_116 < 0x400 )
V_104 += V_116 ;
else
V_106 += V_116 ;
V_27 = F_14 ( V_8 , V_22 ) ;
if ( V_27 > V_12 )
V_12 = V_27 ;
if ( V_36 )
V_115 += F_10 ( V_36 , V_22 ) ;
}
}
V_114 = F_49 ( V_104 , V_105 , V_106 ,
F_22 ( V_93 ) , V_12 ) ;
if ( V_115 > V_11 )
V_11 = V_115 ;
V_106 = ( ! V_36 || ( V_36 && ! V_11 ) ) ? V_114 :
F_49 ( V_104 , V_105 , V_11 + V_106 ,
F_22 ( V_93 ) , V_12 ) ;
if ( ! V_114 && ! V_106 ) {
if ( V_93 -> V_15 || V_93 -> V_16 )
F_35 ( & V_58 -> V_60 -> V_8 , L_10
L_11 , V_93 ,
& V_58 -> V_63 ) ;
V_93 -> V_17 = 0 ;
return;
}
V_93 -> V_15 = V_12 ;
V_93 -> V_16 = V_93 -> V_15 + V_114 - 1 ;
V_93 -> V_17 |= V_40 ;
if ( V_106 > V_114 && V_36 ) {
F_5 ( V_36 , V_58 -> V_60 , V_93 , V_106 - V_114 ,
V_12 ) ;
F_12 ( V_19 , & V_58 -> V_60 -> V_8 , L_12
L_13 , V_93 ,
& V_58 -> V_63 ,
( unsigned long long ) V_106 - V_114 ) ;
}
}
static inline T_1 F_57 ( T_1 * V_117 ,
int V_118 )
{
T_1 V_27 = 0 ;
T_1 V_12 = 0 ;
int V_119 ;
for ( V_119 = 0 ; V_119 <= V_118 ; V_119 ++ ) {
T_1 V_120 = 1 ;
V_120 <<= ( V_119 + 20 ) ;
if ( ! V_27 )
V_12 = V_120 ;
else if ( F_51 ( V_27 + V_12 , V_12 ) < V_120 )
V_12 = V_120 >> 1 ;
V_27 += V_117 [ V_119 ] ;
}
return V_12 ;
}
static int F_58 ( struct V_57 * V_58 , unsigned long V_46 ,
unsigned long type , T_1 V_105 ,
T_1 V_11 ,
struct V_1 * V_36 )
{
struct V_7 * V_8 ;
T_1 V_12 , V_27 , V_104 , V_114 , V_106 ;
T_1 V_117 [ 12 ] ;
int V_119 , V_118 ;
struct V_9 * V_93 = F_47 ( V_58 , type ) ;
unsigned int V_121 = 0 ;
T_1 V_115 = 0 ;
if ( ! V_93 )
return 0 ;
memset ( V_117 , 0 , sizeof( V_117 ) ) ;
V_118 = 0 ;
V_104 = 0 ;
V_121 = V_93 -> V_17 & V_86 ;
V_93 -> V_17 &= ~ V_86 ;
F_11 (dev, &bus->devices, bus_list) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
T_1 V_116 ;
if ( V_22 -> V_26 || ( V_22 -> V_17 & V_46 ) != type )
continue;
V_116 = F_22 ( V_22 ) ;
#ifdef F_59
if ( V_36 && V_20 >= V_122 &&
V_20 <= V_123 ) {
V_22 -> V_16 = V_22 -> V_15 - 1 ;
F_5 ( V_36 , V_8 , V_22 , V_116 , 0 ) ;
V_115 += V_116 ;
continue;
}
#endif
V_27 = F_14 ( V_8 , V_22 ) ;
V_119 = F_60 ( V_27 ) - 20 ;
if ( V_119 > 11 ) {
F_15 ( & V_8 -> V_8 , L_14
L_15 , V_20 , V_22 ,
( unsigned long long ) V_27 ) ;
V_22 -> V_17 = 0 ;
continue;
}
V_104 += V_116 ;
if ( V_119 < 0 )
V_119 = 0 ;
if ( V_116 == V_27 )
V_117 [ V_119 ] += V_27 ;
if ( V_119 > V_118 )
V_118 = V_119 ;
V_121 &= V_22 -> V_17 & V_86 ;
if ( V_36 )
V_115 += F_10 ( V_36 , V_22 ) ;
}
}
V_12 = F_57 ( V_117 , V_118 ) ;
V_12 = F_55 ( V_12 , F_54 ( V_58 , V_93 -> V_17 ) ) ;
V_114 = F_52 ( V_104 , V_105 , 0 , F_22 ( V_93 ) , V_12 ) ;
if ( V_115 > V_11 )
V_11 = V_115 ;
V_106 = ( ! V_36 || ( V_36 && ! V_11 ) ) ? V_114 :
F_52 ( V_104 , V_105 , V_11 ,
F_22 ( V_93 ) , V_12 ) ;
if ( ! V_114 && ! V_106 ) {
if ( V_93 -> V_15 || V_93 -> V_16 )
F_35 ( & V_58 -> V_60 -> V_8 , L_10
L_11 , V_93 ,
& V_58 -> V_63 ) ;
V_93 -> V_17 = 0 ;
return 1 ;
}
V_93 -> V_15 = V_12 ;
V_93 -> V_16 = V_114 + V_12 - 1 ;
V_93 -> V_17 |= V_40 | V_121 ;
if ( V_106 > V_114 && V_36 ) {
F_5 ( V_36 , V_58 -> V_60 , V_93 , V_106 - V_114 , V_12 ) ;
F_12 ( V_19 , & V_58 -> V_60 -> V_8 , L_12
L_13 , V_93 ,
& V_58 -> V_63 , ( unsigned long long ) V_106 - V_114 ) ;
}
return 1 ;
}
unsigned long F_61 ( struct V_9 * V_10 )
{
if ( V_10 -> V_17 & V_47 )
return V_124 ;
if ( V_10 -> V_17 & V_48 )
return V_125 ;
return 0 ;
}
static void F_62 ( struct V_57 * V_58 ,
struct V_1 * V_36 )
{
struct V_7 * V_59 = V_58 -> V_60 ;
struct V_9 * V_93 = & V_59 -> V_9 [ V_94 ] ;
T_1 V_126 = V_125 * 2 ;
T_2 V_127 ;
if ( V_93 [ 0 ] . V_26 )
goto V_128;
V_93 [ 0 ] . V_15 = V_124 ;
V_93 [ 0 ] . V_16 = V_93 [ 0 ] . V_15 + V_124 - 1 ;
V_93 [ 0 ] . V_17 |= V_47 | V_40 ;
if ( V_36 ) {
V_93 [ 0 ] . V_16 -= V_124 ;
F_5 ( V_36 , V_59 , V_93 , V_124 ,
V_124 ) ;
}
V_128:
if ( V_93 [ 1 ] . V_26 )
goto V_129;
V_93 [ 1 ] . V_15 = V_124 ;
V_93 [ 1 ] . V_16 = V_93 [ 1 ] . V_15 + V_124 - 1 ;
V_93 [ 1 ] . V_17 |= V_47 | V_40 ;
if ( V_36 ) {
V_93 [ 1 ] . V_16 -= V_124 ;
F_5 ( V_36 , V_59 , V_93 + 1 , V_124 ,
V_124 ) ;
}
V_129:
F_19 ( V_59 , V_130 , & V_127 ) ;
if ( V_127 & V_131 ) {
V_127 &= ~ V_131 ;
F_39 ( V_59 , V_130 , V_127 ) ;
F_19 ( V_59 , V_130 , & V_127 ) ;
}
F_19 ( V_59 , V_130 , & V_127 ) ;
if ( ! ( V_127 & V_132 ) ) {
V_127 |= V_132 ;
F_39 ( V_59 , V_130 , V_127 ) ;
F_19 ( V_59 , V_130 , & V_127 ) ;
}
if ( V_93 [ 2 ] . V_26 )
goto V_133;
if ( V_127 & V_132 ) {
V_93 [ 2 ] . V_15 = V_125 ;
V_93 [ 2 ] . V_16 = V_93 [ 2 ] . V_15 + V_125 - 1 ;
V_93 [ 2 ] . V_17 |= V_48 | V_49 |
V_40 ;
if ( V_36 ) {
V_93 [ 2 ] . V_16 -= V_125 ;
F_5 ( V_36 , V_59 , V_93 + 2 ,
V_125 , V_125 ) ;
}
V_126 = V_125 ;
}
V_133:
if ( V_93 [ 3 ] . V_26 )
goto V_134;
V_93 [ 3 ] . V_15 = V_125 ;
V_93 [ 3 ] . V_16 = V_93 [ 3 ] . V_15 + V_126 - 1 ;
V_93 [ 3 ] . V_17 |= V_48 | V_40 ;
if ( V_36 ) {
V_93 [ 3 ] . V_16 -= V_126 ;
F_5 ( V_36 , V_59 , V_93 + 3 , V_126 ,
V_125 ) ;
}
V_134:
;
}
void T_5 F_63 ( struct V_57 * V_58 ,
struct V_1 * V_36 )
{
struct V_7 * V_8 ;
unsigned long V_46 , V_135 ;
T_1 V_136 = 0 , V_137 = 0 ;
F_11 (dev, &bus->devices, bus_list) {
struct V_57 * V_138 = V_8 -> V_139 ;
if ( ! V_138 )
continue;
switch ( V_8 -> V_28 >> 8 ) {
case V_140 :
F_62 ( V_138 , V_36 ) ;
break;
case V_141 :
default:
F_63 ( V_138 , V_36 ) ;
break;
}
}
if ( F_64 ( V_58 ) )
return;
switch ( V_58 -> V_60 -> V_28 >> 8 ) {
case V_140 :
break;
case V_141 :
F_45 ( V_58 ) ;
if ( V_58 -> V_60 -> V_142 ) {
V_137 = V_143 ;
V_136 = V_144 ;
}
default:
F_56 ( V_58 , V_36 ? 0 : V_137 ,
V_137 , V_36 ) ;
V_46 = V_48 ;
V_135 = V_48 | V_49 ;
if ( F_58 ( V_58 , V_135 , V_135 ,
V_36 ? 0 : V_136 ,
V_136 , V_36 ) )
V_46 = V_135 ;
else
V_136 += V_136 ;
F_58 ( V_58 , V_46 , V_48 ,
V_36 ? 0 : V_136 ,
V_136 , V_36 ) ;
break;
}
}
void T_5 F_65 ( struct V_57 * V_58 )
{
F_63 ( V_58 , NULL ) ;
}
void T_5 F_66 ( const struct V_57 * V_58 ,
struct V_1 * V_36 ,
struct V_1 * V_42 )
{
struct V_57 * V_138 ;
struct V_7 * V_8 ;
F_33 ( V_58 , V_36 , V_42 ) ;
F_11 (dev, &bus->devices, bus_list) {
V_138 = V_8 -> V_139 ;
if ( ! V_138 )
continue;
F_66 ( V_138 , V_36 , V_42 ) ;
switch ( V_8 -> V_28 >> 8 ) {
case V_141 :
if ( ! F_67 ( V_8 ) )
F_44 ( V_138 ) ;
break;
case V_140 :
F_34 ( V_138 ) ;
break;
default:
F_35 ( & V_8 -> V_8 , L_16
L_17 , F_68 ( V_138 ) , V_138 -> V_145 ) ;
break;
}
}
}
void T_5 F_69 ( const struct V_57 * V_58 )
{
F_66 ( V_58 , NULL , NULL ) ;
}
static void T_5 F_70 ( const struct V_7 * V_59 ,
struct V_1 * V_56 ,
struct V_1 * V_42 )
{
struct V_57 * V_138 ;
F_32 ( (struct V_7 * ) V_59 ,
V_56 , V_42 ) ;
V_138 = V_59 -> V_139 ;
if ( ! V_138 )
return;
F_66 ( V_138 , V_56 , V_42 ) ;
switch ( V_59 -> V_28 >> 8 ) {
case V_141 :
F_44 ( V_138 ) ;
break;
case V_140 :
F_34 ( V_138 ) ;
break;
default:
F_35 ( & V_59 -> V_8 , L_16
L_17 , F_68 ( V_138 ) , V_138 -> V_145 ) ;
break;
}
}
static void F_71 ( struct V_57 * V_58 ,
unsigned long type )
{
int V_18 ;
bool V_146 = false ;
struct V_7 * V_8 ;
struct V_9 * V_22 ;
unsigned long V_101 = V_47 | V_48 |
V_49 ;
V_8 = V_58 -> V_60 ;
for ( V_18 = V_94 ; V_18 <= V_147 ;
V_18 ++ ) {
V_22 = & V_8 -> V_9 [ V_18 ] ;
if ( ( V_22 -> V_17 & V_101 ) != type )
continue;
if ( ! V_22 -> V_26 )
continue;
F_72 ( V_22 ) ;
if ( ! F_31 ( V_22 ) ) {
F_12 ( V_19 , & V_8 -> V_8 ,
L_18 , V_18 , V_22 ) ;
V_22 -> V_16 = F_22 ( V_22 ) - 1 ;
V_22 -> V_15 = 0 ;
V_22 -> V_17 = 0 ;
V_146 = true ;
}
}
if ( V_146 ) {
if ( type & V_49 )
type = V_49 ;
F_43 ( V_58 , type ) ;
}
}
static void T_5 F_73 ( struct V_57 * V_58 ,
unsigned long type ,
enum V_148 V_149 )
{
struct V_7 * V_8 ;
bool V_150 = true ;
F_11 (dev, &bus->devices, bus_list) {
struct V_57 * V_138 = V_8 -> V_139 ;
if ( ! V_138 )
continue;
V_150 = false ;
if ( ( V_8 -> V_28 >> 8 ) != V_141 )
continue;
if ( V_149 == V_151 )
F_73 ( V_138 , type ,
V_151 ) ;
}
if ( F_64 ( V_58 ) )
return;
if ( ( V_58 -> V_60 -> V_28 >> 8 ) != V_141 )
return;
if ( ( V_149 == V_151 ) || V_150 )
F_71 ( V_58 , type ) ;
}
static void F_74 ( struct V_57 * V_58 )
{
struct V_9 * V_10 ;
int V_20 ;
F_48 (bus, res, i) {
if ( ! V_10 || ! V_10 -> V_16 || ! V_10 -> V_17 )
continue;
F_12 ( V_19 , & V_58 -> V_8 , L_19 , V_20 , V_10 ) ;
}
}
static void F_75 ( struct V_57 * V_58 )
{
struct V_57 * V_138 ;
struct V_7 * V_8 ;
F_74 ( V_58 ) ;
F_11 (dev, &bus->devices, bus_list) {
V_138 = V_8 -> V_139 ;
if ( ! V_138 )
continue;
F_75 ( V_138 ) ;
}
}
static int F_76 ( struct V_57 * V_58 )
{
int V_152 = 0 ;
struct V_57 * V_153 ;
F_11 (child_bus, &bus->children, node) {
int V_154 ;
V_154 = F_76 ( V_153 ) ;
if ( V_154 + 1 > V_152 )
V_152 = V_154 + 1 ;
}
return V_152 ;
}
void T_6 F_77 ( char * V_155 )
{
if ( ! strncmp ( V_155 , L_20 , 3 ) )
V_156 = V_157 ;
else if ( ! strncmp ( V_155 , L_21 , 2 ) )
V_156 = V_158 ;
}
static bool F_78 ( enum V_159 V_160 )
{
return V_160 >= V_158 ;
}
static int F_79 ( struct V_7 * V_8 , void * V_161 )
{
int V_20 ;
bool * V_162 = V_161 ;
for ( V_20 = V_122 ; V_20 <= V_123 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
struct V_61 V_62 ;
if ( ! V_22 -> V_17 )
continue;
F_36 ( V_8 -> V_58 , & V_62 , V_22 ) ;
if ( ! V_62 . V_15 ) {
* V_162 = true ;
return 1 ;
}
}
return 0 ;
}
static enum V_159 F_80 ( struct V_57 * V_58 ,
enum V_159 V_163 )
{
bool V_162 = false ;
if ( V_163 != V_164 )
return V_163 ;
F_81 ( V_58 , F_79 , & V_162 ) ;
if ( V_162 )
return V_165 ;
return V_163 ;
}
static enum V_159 F_80 ( struct V_57 * V_58 ,
enum V_159 V_163 )
{
return V_163 ;
}
void F_82 ( struct V_57 * V_58 )
{
F_29 ( V_36 ) ;
struct V_1 * V_166 = NULL ;
int V_167 = 0 ;
enum V_148 V_149 = V_168 ;
F_29 ( V_42 ) ;
struct V_3 * V_45 ;
unsigned long V_101 = V_47 | V_48 |
V_49 ;
int V_169 = 1 ;
enum V_159 V_163 ;
V_163 = F_80 ( V_58 , V_156 ) ;
if ( F_78 ( V_163 ) ) {
int V_170 = F_76 ( V_58 ) ;
V_169 = V_170 + 1 ;
F_12 ( V_19 , & V_58 -> V_8 ,
L_22 ,
V_170 , V_169 ) ;
}
V_171:
if ( V_167 + 1 == V_169 )
V_166 = & V_36 ;
F_63 ( V_58 , V_166 ) ;
F_66 ( V_58 , V_166 , & V_42 ) ;
if ( V_166 )
F_83 ( ! F_30 ( V_166 ) ) ;
V_167 ++ ;
if ( F_30 ( & V_42 ) )
goto V_172;
if ( V_167 >= V_169 ) {
if ( V_163 == V_164 )
F_35 ( & V_58 -> V_8 , L_23 ) ;
else if ( V_163 == V_165 )
F_35 ( & V_58 -> V_8 , L_24 ) ;
F_1 ( & V_42 ) ;
goto V_172;
}
F_12 ( V_19 , & V_58 -> V_8 ,
L_25 , V_167 + 1 ) ;
if ( ( V_167 + 1 ) > 2 )
V_149 = V_151 ;
F_11 (fail_res, &fail_head, list)
F_73 ( V_45 -> V_8 -> V_58 ,
V_45 -> V_17 & V_101 ,
V_149 ) ;
F_11 (fail_res, &fail_head, list) {
struct V_9 * V_10 = V_45 -> V_10 ;
V_10 -> V_15 = V_45 -> V_15 ;
V_10 -> V_16 = V_45 -> V_16 ;
V_10 -> V_17 = V_45 -> V_17 ;
if ( V_45 -> V_8 -> V_139 )
V_10 -> V_17 = 0 ;
}
F_1 ( & V_42 ) ;
goto V_171;
V_172:
F_75 ( V_58 ) ;
}
void T_6 F_84 ( void )
{
struct V_57 * V_173 ;
F_11 (root_bus, &pci_root_buses, node)
F_82 ( V_173 ) ;
}
void F_85 ( struct V_7 * V_59 )
{
struct V_57 * V_26 = V_59 -> V_139 ;
F_29 ( V_166 ) ;
int V_167 = 0 ;
F_29 ( V_42 ) ;
struct V_3 * V_45 ;
int V_174 ;
unsigned long V_101 = V_47 | V_48 |
V_49 ;
V_171:
F_63 ( V_26 , & V_166 ) ;
F_70 ( V_59 , & V_166 , & V_42 ) ;
F_83 ( ! F_30 ( & V_166 ) ) ;
V_167 ++ ;
if ( F_30 ( & V_42 ) )
goto V_175;
if ( V_167 >= 2 ) {
F_1 ( & V_42 ) ;
goto V_175;
}
F_86 ( V_19 L_26 ,
V_167 + 1 ) ;
F_11 (fail_res, &fail_head, list)
F_73 ( V_45 -> V_8 -> V_58 ,
V_45 -> V_17 & V_101 ,
V_151 ) ;
F_11 (fail_res, &fail_head, list) {
struct V_9 * V_10 = V_45 -> V_10 ;
V_10 -> V_15 = V_45 -> V_15 ;
V_10 -> V_16 = V_45 -> V_16 ;
V_10 -> V_17 = V_45 -> V_17 ;
if ( V_45 -> V_8 -> V_139 )
V_10 -> V_17 = 0 ;
}
F_1 ( & V_42 ) ;
goto V_171;
V_175:
V_174 = F_87 ( V_59 ) ;
if ( V_174 )
F_88 ( & V_59 -> V_8 , L_27 , V_174 ) ;
F_89 ( V_59 ) ;
}
void F_90 ( struct V_57 * V_58 )
{
struct V_7 * V_8 ;
F_29 ( V_166 ) ;
F_91 ( & V_176 ) ;
F_11 (dev, &bus->devices, bus_list)
if ( V_8 -> V_177 == V_178 ||
V_8 -> V_177 == V_179 )
if ( V_8 -> V_139 )
F_63 ( V_8 -> V_139 ,
& V_166 ) ;
F_92 ( & V_176 ) ;
F_66 ( V_58 , & V_166 , NULL ) ;
F_83 ( ! F_30 ( & V_166 ) ) ;
}
