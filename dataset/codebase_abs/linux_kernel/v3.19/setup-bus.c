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
F_16 ( L_4 ) ;
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
L_5 ,
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
F_35 ( & V_59 -> V_8 , L_6 ,
& V_58 -> V_63 ) ;
V_10 = V_58 -> V_9 [ 0 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_47 ) {
F_35 ( & V_59 -> V_8 , L_7 , V_10 ) ;
F_37 ( V_59 , V_64 ,
V_62 . V_15 ) ;
F_37 ( V_59 , V_65 ,
V_62 . V_16 ) ;
}
V_10 = V_58 -> V_9 [ 1 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_47 ) {
F_35 ( & V_59 -> V_8 , L_7 , V_10 ) ;
F_37 ( V_59 , V_66 ,
V_62 . V_15 ) ;
F_37 ( V_59 , V_67 ,
V_62 . V_16 ) ;
}
V_10 = V_58 -> V_9 [ 2 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_48 ) {
F_35 ( & V_59 -> V_8 , L_7 , V_10 ) ;
F_37 ( V_59 , V_68 ,
V_62 . V_15 ) ;
F_37 ( V_59 , V_69 ,
V_62 . V_16 ) ;
}
V_10 = V_58 -> V_9 [ 3 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_48 ) {
F_35 ( & V_59 -> V_8 , L_7 , V_10 ) ;
F_37 ( V_59 , V_70 ,
V_62 . V_15 ) ;
F_37 ( V_59 , V_71 ,
V_62 . V_16 ) ;
}
}
static void F_38 ( struct V_7 * V_59 )
{
struct V_9 * V_10 ;
struct V_61 V_62 ;
unsigned long V_72 ;
T_3 V_73 , V_74 ;
T_2 V_75 ;
T_4 V_76 ;
V_72 = V_77 ;
if ( V_59 -> V_78 )
V_72 = V_79 ;
V_10 = & V_59 -> V_9 [ V_80 + 0 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_47 ) {
F_19 ( V_59 , V_81 , & V_75 ) ;
V_73 = ( V_62 . V_15 >> 8 ) & V_72 ;
V_74 = ( V_62 . V_16 >> 8 ) & V_72 ;
V_75 = ( ( T_2 ) V_74 << 8 ) | V_73 ;
V_76 = ( V_62 . V_16 & 0xffff0000 ) | ( V_62 . V_15 >> 16 ) ;
F_35 ( & V_59 -> V_8 , L_7 , V_10 ) ;
} else {
V_76 = 0 ;
V_75 = 0x00f0 ;
}
F_37 ( V_59 , V_82 , 0x0000ffff ) ;
F_39 ( V_59 , V_81 , V_75 ) ;
F_37 ( V_59 , V_82 , V_76 ) ;
}
static void F_40 ( struct V_7 * V_59 )
{
struct V_9 * V_10 ;
struct V_61 V_62 ;
T_4 V_75 ;
V_10 = & V_59 -> V_9 [ V_80 + 1 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_48 ) {
V_75 = ( V_62 . V_15 >> 16 ) & 0xfff0 ;
V_75 |= V_62 . V_16 & 0xfff00000 ;
F_35 ( & V_59 -> V_8 , L_7 , V_10 ) ;
} else {
V_75 = 0x0000fff0 ;
}
F_37 ( V_59 , V_83 , V_75 ) ;
}
static void F_41 ( struct V_7 * V_59 )
{
struct V_9 * V_10 ;
struct V_61 V_62 ;
T_4 V_75 , V_84 , V_85 ;
F_37 ( V_59 , V_86 , 0 ) ;
V_84 = V_85 = 0 ;
V_10 = & V_59 -> V_9 [ V_80 + 2 ] ;
F_36 ( V_59 -> V_58 , & V_62 , V_10 ) ;
if ( V_10 -> V_17 & V_49 ) {
V_75 = ( V_62 . V_15 >> 16 ) & 0xfff0 ;
V_75 |= V_62 . V_16 & 0xfff00000 ;
if ( V_10 -> V_17 & V_87 ) {
V_84 = F_42 ( V_62 . V_15 ) ;
V_85 = F_42 ( V_62 . V_16 ) ;
}
F_35 ( & V_59 -> V_8 , L_7 , V_10 ) ;
} else {
V_75 = 0x0000fff0 ;
}
F_37 ( V_59 , V_88 , V_75 ) ;
F_37 ( V_59 , V_89 , V_84 ) ;
F_37 ( V_59 , V_86 , V_85 ) ;
}
static void F_43 ( struct V_57 * V_58 , unsigned long type )
{
struct V_7 * V_59 = V_58 -> V_60 ;
F_35 ( & V_59 -> V_8 , L_8 ,
& V_58 -> V_63 ) ;
if ( type & V_47 )
F_38 ( V_59 ) ;
if ( type & V_48 )
F_40 ( V_59 ) ;
if ( type & V_49 )
F_41 ( V_59 ) ;
F_39 ( V_59 , V_90 , V_58 -> V_91 ) ;
}
void F_44 ( struct V_57 * V_58 )
{
unsigned long type = V_47 | V_48 |
V_49 ;
F_43 ( V_58 , type ) ;
}
int F_45 ( struct V_7 * V_59 , int V_20 )
{
if ( V_20 < V_80 || V_20 > V_92 )
return 0 ;
if ( F_46 ( V_59 , V_20 ) == 0 )
return 0 ;
if ( ( V_59 -> V_28 >> 8 ) != V_93 )
return 0 ;
if ( ! F_47 ( V_59 , V_20 ) )
return - V_94 ;
switch ( V_20 - V_80 ) {
case 0 :
F_38 ( V_59 ) ;
break;
case 1 :
F_40 ( V_59 ) ;
break;
case 2 :
F_41 ( V_59 ) ;
break;
default:
return - V_94 ;
}
if ( F_46 ( V_59 , V_20 ) == 0 )
return 0 ;
return - V_94 ;
}
static void F_48 ( struct V_57 * V_58 )
{
T_2 V_95 ;
T_4 V_96 ;
struct V_7 * V_59 = V_58 -> V_60 ;
struct V_9 * V_97 ;
V_97 = & V_59 -> V_9 [ V_80 ] ;
V_97 [ 1 ] . V_17 |= V_48 ;
F_19 ( V_59 , V_81 , & V_95 ) ;
if ( ! V_95 ) {
F_39 ( V_59 , V_81 , 0xe0f0 ) ;
F_19 ( V_59 , V_81 , & V_95 ) ;
F_39 ( V_59 , V_81 , 0x0 ) ;
}
if ( V_95 )
V_97 [ 0 ] . V_17 |= V_47 ;
if ( V_59 -> V_98 == V_99 && V_59 -> V_100 == 0x0001 )
return;
F_49 ( V_59 , V_88 , & V_96 ) ;
if ( ! V_96 ) {
F_37 ( V_59 , V_88 ,
0xffe0fff0 ) ;
F_49 ( V_59 , V_88 , & V_96 ) ;
F_37 ( V_59 , V_88 , 0x0 ) ;
}
if ( V_96 ) {
V_97 [ 2 ] . V_17 |= V_48 | V_49 ;
if ( ( V_96 & V_101 ) ==
V_102 ) {
V_97 [ 2 ] . V_17 |= V_87 ;
V_97 [ 2 ] . V_17 |= V_102 ;
}
}
if ( V_97 [ 2 ] . V_17 & V_87 ) {
T_4 V_103 , V_5 ;
F_49 ( V_59 , V_89 ,
& V_103 ) ;
F_37 ( V_59 , V_89 ,
0xffffffff ) ;
F_49 ( V_59 , V_89 , & V_5 ) ;
if ( ! V_5 )
V_97 [ 2 ] . V_17 &= ~ V_87 ;
F_37 ( V_59 , V_89 ,
V_103 ) ;
}
}
static struct V_9 * F_50 ( struct V_57 * V_58 ,
unsigned long V_104 , unsigned long type )
{
int V_20 ;
struct V_9 * V_22 ;
F_51 (bus, r, i) {
if ( V_22 == & V_105 || V_22 == & V_106 )
continue;
if ( V_22 && ( V_22 -> V_17 & V_104 ) == type && ! V_22 -> V_26 )
return V_22 ;
}
return NULL ;
}
static T_1 F_52 ( T_1 V_107 ,
T_1 V_108 ,
T_1 V_109 ,
T_1 V_110 ,
T_1 V_27 )
{
if ( V_107 < V_108 )
V_107 = V_108 ;
if ( V_110 == 1 )
V_110 = 0 ;
#if F_53 ( V_111 ) || F_53 ( V_112 )
V_107 = ( V_107 & 0xff ) + ( ( V_107 & ~ 0xffUL ) << 2 ) ;
#endif
V_107 = F_54 ( V_107 + V_109 , V_27 ) ;
if ( V_107 < V_110 )
V_107 = V_110 ;
return V_107 ;
}
static T_1 F_55 ( T_1 V_107 ,
T_1 V_108 ,
T_1 V_109 ,
T_1 V_110 ,
T_1 V_27 )
{
if ( V_107 < V_108 )
V_107 = V_108 ;
if ( V_110 == 1 )
V_110 = 0 ;
if ( V_107 < V_110 )
V_107 = V_110 ;
V_107 = F_54 ( V_107 + V_109 , V_27 ) ;
return V_107 ;
}
T_1 __weak F_56 ( struct V_57 * V_58 ,
unsigned long type )
{
return 1 ;
}
static T_1 F_57 ( struct V_57 * V_58 ,
unsigned long type )
{
T_1 V_27 = 1 , V_113 ;
if ( type & V_48 )
V_27 = V_114 ;
else if ( type & V_47 ) {
if ( V_58 -> V_60 -> V_78 )
V_27 = V_115 ;
else
V_27 = V_116 ;
}
V_113 = F_56 ( V_58 , type ) ;
return F_58 ( V_27 , V_113 ) ;
}
static void F_59 ( struct V_57 * V_58 , T_1 V_108 ,
T_1 V_11 , struct V_1 * V_36 )
{
struct V_7 * V_8 ;
struct V_9 * V_97 = F_50 ( V_58 , V_47 ,
V_47 ) ;
T_1 V_107 = 0 , V_117 = 0 , V_109 = 0 ;
T_1 V_118 = 0 ;
T_1 V_12 , V_27 ;
if ( ! V_97 )
return;
V_12 = F_57 ( V_58 , V_47 ) ;
F_11 (dev, &bus->devices, bus_list) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
unsigned long V_119 ;
if ( V_22 -> V_26 || ! ( V_22 -> V_17 & V_47 ) )
continue;
V_119 = F_22 ( V_22 ) ;
if ( V_119 < 0x400 )
V_107 += V_119 ;
else
V_109 += V_119 ;
V_27 = F_14 ( V_8 , V_22 ) ;
if ( V_27 > V_12 )
V_12 = V_27 ;
if ( V_36 )
V_118 += F_10 ( V_36 , V_22 ) ;
}
}
V_117 = F_52 ( V_107 , V_108 , V_109 ,
F_22 ( V_97 ) , V_12 ) ;
if ( V_118 > V_11 )
V_11 = V_118 ;
V_109 = ( ! V_36 || ( V_36 && ! V_11 ) ) ? V_117 :
F_52 ( V_107 , V_108 , V_11 + V_109 ,
F_22 ( V_97 ) , V_12 ) ;
if ( ! V_117 && ! V_109 ) {
if ( V_97 -> V_15 || V_97 -> V_16 )
F_35 ( & V_58 -> V_60 -> V_8 , L_9 ,
V_97 , & V_58 -> V_63 ) ;
V_97 -> V_17 = 0 ;
return;
}
V_97 -> V_15 = V_12 ;
V_97 -> V_16 = V_97 -> V_15 + V_117 - 1 ;
V_97 -> V_17 |= V_40 ;
if ( V_109 > V_117 && V_36 ) {
F_5 ( V_36 , V_58 -> V_60 , V_97 , V_109 - V_117 ,
V_12 ) ;
F_12 ( V_19 , & V_58 -> V_60 -> V_8 , L_10 ,
V_97 , & V_58 -> V_63 ,
( unsigned long long ) V_109 - V_117 ) ;
}
}
static inline T_1 F_60 ( T_1 * V_120 ,
int V_121 )
{
T_1 V_27 = 0 ;
T_1 V_12 = 0 ;
int V_122 ;
for ( V_122 = 0 ; V_122 <= V_121 ; V_122 ++ ) {
T_1 V_123 = 1 ;
V_123 <<= ( V_122 + 20 ) ;
if ( ! V_27 )
V_12 = V_123 ;
else if ( F_54 ( V_27 + V_12 , V_12 ) < V_123 )
V_12 = V_123 >> 1 ;
V_27 += V_120 [ V_122 ] ;
}
return V_12 ;
}
static int F_61 ( struct V_57 * V_58 , unsigned long V_46 ,
unsigned long type , unsigned long V_124 ,
unsigned long V_125 ,
T_1 V_108 , T_1 V_11 ,
struct V_1 * V_36 )
{
struct V_7 * V_8 ;
T_1 V_12 , V_27 , V_107 , V_117 , V_109 ;
T_1 V_120 [ 18 ] ;
int V_122 , V_121 ;
struct V_9 * V_97 = F_50 ( V_58 ,
V_46 | V_49 , type ) ;
T_1 V_118 = 0 ;
if ( ! V_97 )
return - V_126 ;
memset ( V_120 , 0 , sizeof( V_120 ) ) ;
V_121 = 0 ;
V_107 = 0 ;
F_11 (dev, &bus->devices, bus_list) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
T_1 V_119 ;
if ( V_22 -> V_26 || ( ( V_22 -> V_17 & V_46 ) != type &&
( V_22 -> V_17 & V_46 ) != V_124 &&
( V_22 -> V_17 & V_46 ) != V_125 ) )
continue;
V_119 = F_22 ( V_22 ) ;
#ifdef F_62
if ( V_36 && V_20 >= V_127 &&
V_20 <= V_128 ) {
V_22 -> V_16 = V_22 -> V_15 - 1 ;
F_5 ( V_36 , V_8 , V_22 , V_119 , 0 ) ;
V_118 += V_119 ;
continue;
}
#endif
V_27 = F_14 ( V_8 , V_22 ) ;
V_122 = F_63 ( V_27 ) - 20 ;
if ( V_122 < 0 )
V_122 = 0 ;
if ( V_122 >= F_64 ( V_120 ) ) {
F_15 ( & V_8 -> V_8 , L_11 ,
V_20 , V_22 , ( unsigned long long ) V_27 ) ;
V_22 -> V_17 = 0 ;
continue;
}
V_107 += V_119 ;
if ( V_119 == V_27 )
V_120 [ V_122 ] += V_27 ;
if ( V_122 > V_121 )
V_121 = V_122 ;
if ( V_36 )
V_118 += F_10 ( V_36 , V_22 ) ;
}
}
V_12 = F_60 ( V_120 , V_121 ) ;
V_12 = F_58 ( V_12 , F_57 ( V_58 , V_97 -> V_17 ) ) ;
V_117 = F_55 ( V_107 , V_108 , 0 , F_22 ( V_97 ) , V_12 ) ;
if ( V_118 > V_11 )
V_11 = V_118 ;
V_109 = ( ! V_36 || ( V_36 && ! V_11 ) ) ? V_117 :
F_55 ( V_107 , V_108 , V_11 ,
F_22 ( V_97 ) , V_12 ) ;
if ( ! V_117 && ! V_109 ) {
if ( V_97 -> V_15 || V_97 -> V_16 )
F_35 ( & V_58 -> V_60 -> V_8 , L_9 ,
V_97 , & V_58 -> V_63 ) ;
V_97 -> V_17 = 0 ;
return 0 ;
}
V_97 -> V_15 = V_12 ;
V_97 -> V_16 = V_117 + V_12 - 1 ;
V_97 -> V_17 |= V_40 ;
if ( V_109 > V_117 && V_36 ) {
F_5 ( V_36 , V_58 -> V_60 , V_97 , V_109 - V_117 , V_12 ) ;
F_12 ( V_19 , & V_58 -> V_60 -> V_8 , L_10 ,
V_97 , & V_58 -> V_63 ,
( unsigned long long ) V_109 - V_117 ) ;
}
return 0 ;
}
unsigned long F_65 ( struct V_9 * V_10 )
{
if ( V_10 -> V_17 & V_47 )
return V_129 ;
if ( V_10 -> V_17 & V_48 )
return V_130 ;
return 0 ;
}
static void F_66 ( struct V_57 * V_58 ,
struct V_1 * V_36 )
{
struct V_7 * V_59 = V_58 -> V_60 ;
struct V_9 * V_97 = & V_59 -> V_9 [ V_80 ] ;
T_1 V_131 = V_130 * 2 ;
T_2 V_132 ;
if ( V_97 [ 0 ] . V_26 )
goto V_133;
V_97 [ 0 ] . V_15 = V_129 ;
V_97 [ 0 ] . V_16 = V_97 [ 0 ] . V_15 + V_129 - 1 ;
V_97 [ 0 ] . V_17 |= V_47 | V_40 ;
if ( V_36 ) {
V_97 [ 0 ] . V_16 -= V_129 ;
F_5 ( V_36 , V_59 , V_97 , V_129 ,
V_129 ) ;
}
V_133:
if ( V_97 [ 1 ] . V_26 )
goto V_134;
V_97 [ 1 ] . V_15 = V_129 ;
V_97 [ 1 ] . V_16 = V_97 [ 1 ] . V_15 + V_129 - 1 ;
V_97 [ 1 ] . V_17 |= V_47 | V_40 ;
if ( V_36 ) {
V_97 [ 1 ] . V_16 -= V_129 ;
F_5 ( V_36 , V_59 , V_97 + 1 , V_129 ,
V_129 ) ;
}
V_134:
F_19 ( V_59 , V_135 , & V_132 ) ;
if ( V_132 & V_136 ) {
V_132 &= ~ V_136 ;
F_39 ( V_59 , V_135 , V_132 ) ;
F_19 ( V_59 , V_135 , & V_132 ) ;
}
F_19 ( V_59 , V_135 , & V_132 ) ;
if ( ! ( V_132 & V_137 ) ) {
V_132 |= V_137 ;
F_39 ( V_59 , V_135 , V_132 ) ;
F_19 ( V_59 , V_135 , & V_132 ) ;
}
if ( V_97 [ 2 ] . V_26 )
goto V_138;
if ( V_132 & V_137 ) {
V_97 [ 2 ] . V_15 = V_130 ;
V_97 [ 2 ] . V_16 = V_97 [ 2 ] . V_15 + V_130 - 1 ;
V_97 [ 2 ] . V_17 |= V_48 | V_49 |
V_40 ;
if ( V_36 ) {
V_97 [ 2 ] . V_16 -= V_130 ;
F_5 ( V_36 , V_59 , V_97 + 2 ,
V_130 , V_130 ) ;
}
V_131 = V_130 ;
}
V_138:
if ( V_97 [ 3 ] . V_26 )
goto V_139;
V_97 [ 3 ] . V_15 = V_130 ;
V_97 [ 3 ] . V_16 = V_97 [ 3 ] . V_15 + V_131 - 1 ;
V_97 [ 3 ] . V_17 |= V_48 | V_40 ;
if ( V_36 ) {
V_97 [ 3 ] . V_16 -= V_131 ;
F_5 ( V_36 , V_59 , V_97 + 3 , V_131 ,
V_130 ) ;
}
V_139:
;
}
void F_67 ( struct V_57 * V_58 , struct V_1 * V_36 )
{
struct V_7 * V_8 ;
unsigned long V_46 , V_140 , V_124 = 0 , V_125 = 0 ;
T_1 V_141 = 0 , V_142 = 0 ;
struct V_9 * V_97 ;
int V_143 ;
F_11 (dev, &bus->devices, bus_list) {
struct V_57 * V_144 = V_8 -> V_145 ;
if ( ! V_144 )
continue;
switch ( V_8 -> V_28 >> 8 ) {
case V_146 :
F_66 ( V_144 , V_36 ) ;
break;
case V_93 :
default:
F_67 ( V_144 , V_36 ) ;
break;
}
}
if ( F_68 ( V_58 ) )
return;
switch ( V_58 -> V_60 -> V_28 >> 8 ) {
case V_146 :
break;
case V_93 :
F_48 ( V_58 ) ;
if ( V_58 -> V_60 -> V_147 ) {
V_142 = V_148 ;
V_141 = V_149 ;
}
default:
F_59 ( V_58 , V_36 ? 0 : V_142 ,
V_142 , V_36 ) ;
V_97 = & V_58 -> V_60 -> V_9 [ V_80 ] ;
V_46 = V_48 ;
V_140 = V_48 | V_49 ;
if ( V_97 [ 2 ] . V_17 & V_87 ) {
V_140 |= V_87 ;
V_143 = F_61 ( V_58 , V_140 , V_140 ,
V_140 , V_140 ,
V_36 ? 0 : V_141 ,
V_141 , V_36 ) ;
if ( V_143 == 0 ) {
V_46 = V_140 ;
V_124 = V_140 & ~ V_87 ;
V_125 = V_140 & ~ V_49 ;
}
}
if ( ! V_124 ) {
V_140 &= ~ V_87 ;
V_143 = F_61 ( V_58 , V_140 , V_140 ,
V_140 , V_140 ,
V_36 ? 0 : V_141 ,
V_141 , V_36 ) ;
if ( V_143 == 0 )
V_46 = V_140 ;
else
V_141 += V_141 ;
V_124 = V_125 = V_48 ;
}
F_61 ( V_58 , V_46 , V_48 , V_124 , V_125 ,
V_36 ? 0 : V_141 ,
V_141 , V_36 ) ;
break;
}
}
void F_69 ( struct V_57 * V_58 )
{
F_67 ( V_58 , NULL ) ;
}
void F_70 ( const struct V_57 * V_58 ,
struct V_1 * V_36 ,
struct V_1 * V_42 )
{
struct V_57 * V_144 ;
struct V_7 * V_8 ;
F_33 ( V_58 , V_36 , V_42 ) ;
F_11 (dev, &bus->devices, bus_list) {
V_144 = V_8 -> V_145 ;
if ( ! V_144 )
continue;
F_70 ( V_144 , V_36 , V_42 ) ;
switch ( V_8 -> V_28 >> 8 ) {
case V_93 :
if ( ! F_71 ( V_8 ) )
F_44 ( V_144 ) ;
break;
case V_146 :
F_34 ( V_144 ) ;
break;
default:
F_35 ( & V_8 -> V_8 , L_12 ,
F_72 ( V_144 ) , V_144 -> V_150 ) ;
break;
}
}
}
void F_73 ( const struct V_57 * V_58 )
{
F_70 ( V_58 , NULL , NULL ) ;
}
static void F_74 ( const struct V_7 * V_59 ,
struct V_1 * V_56 ,
struct V_1 * V_42 )
{
struct V_57 * V_144 ;
F_32 ( (struct V_7 * ) V_59 ,
V_56 , V_42 ) ;
V_144 = V_59 -> V_145 ;
if ( ! V_144 )
return;
F_70 ( V_144 , V_56 , V_42 ) ;
switch ( V_59 -> V_28 >> 8 ) {
case V_93 :
F_44 ( V_144 ) ;
break;
case V_146 :
F_34 ( V_144 ) ;
break;
default:
F_35 ( & V_59 -> V_8 , L_12 ,
F_72 ( V_144 ) , V_144 -> V_150 ) ;
break;
}
}
static void F_75 ( struct V_57 * V_58 ,
unsigned long type )
{
struct V_7 * V_8 = V_58 -> V_60 ;
struct V_9 * V_22 ;
unsigned long V_104 = V_47 | V_48 |
V_49 | V_87 ;
unsigned V_151 = 0 ;
struct V_9 * V_97 ;
int V_18 = 1 ;
V_97 = & V_8 -> V_9 [ V_80 ] ;
if ( type & V_47 )
V_18 = 0 ;
else if ( ! ( type & V_49 ) )
V_18 = 1 ;
else if ( ( type & V_87 ) &&
( V_97 [ 2 ] . V_17 & V_87 ) )
V_18 = 2 ;
else if ( ! ( V_97 [ 2 ] . V_17 & V_87 ) &&
( V_97 [ 2 ] . V_17 & V_49 ) )
V_18 = 2 ;
else
V_18 = 1 ;
V_22 = & V_97 [ V_18 ] ;
if ( ! V_22 -> V_26 )
return;
F_76 ( V_22 ) ;
if ( ! F_31 ( V_22 ) ) {
type = V_151 = V_22 -> V_17 & V_104 ;
F_12 ( V_19 , & V_8 -> V_8 , L_13 ,
V_80 + V_18 , V_22 ) ;
V_22 -> V_16 = F_22 ( V_22 ) - 1 ;
V_22 -> V_15 = 0 ;
V_22 -> V_17 = 0 ;
if ( type & V_49 )
type = V_49 ;
F_43 ( V_58 , type ) ;
V_22 -> V_17 = V_151 ;
}
}
static void F_77 ( struct V_57 * V_58 ,
unsigned long type ,
enum V_152 V_153 )
{
struct V_7 * V_8 ;
bool V_154 = true ;
F_11 (dev, &bus->devices, bus_list) {
struct V_57 * V_144 = V_8 -> V_145 ;
if ( ! V_144 )
continue;
V_154 = false ;
if ( ( V_8 -> V_28 >> 8 ) != V_93 )
continue;
if ( V_153 == V_155 )
F_77 ( V_144 , type ,
V_155 ) ;
}
if ( F_68 ( V_58 ) )
return;
if ( ( V_58 -> V_60 -> V_28 >> 8 ) != V_93 )
return;
if ( ( V_153 == V_155 ) || V_154 )
F_75 ( V_58 , type ) ;
}
static void F_78 ( struct V_57 * V_58 )
{
struct V_9 * V_10 ;
int V_20 ;
F_51 (bus, res, i) {
if ( ! V_10 || ! V_10 -> V_16 || ! V_10 -> V_17 )
continue;
F_12 ( V_19 , & V_58 -> V_8 , L_14 , V_20 , V_10 ) ;
}
}
static void F_79 ( struct V_57 * V_58 )
{
struct V_57 * V_144 ;
struct V_7 * V_8 ;
F_78 ( V_58 ) ;
F_11 (dev, &bus->devices, bus_list) {
V_144 = V_8 -> V_145 ;
if ( ! V_144 )
continue;
F_79 ( V_144 ) ;
}
}
static int F_80 ( struct V_57 * V_58 )
{
int V_156 = 0 ;
struct V_57 * V_157 ;
F_11 (child_bus, &bus->children, node) {
int V_143 ;
V_143 = F_80 ( V_157 ) ;
if ( V_143 + 1 > V_156 )
V_156 = V_143 + 1 ;
}
return V_156 ;
}
void T_5 F_81 ( char * V_158 )
{
if ( ! strncmp ( V_158 , L_15 , 3 ) )
V_159 = V_160 ;
else if ( ! strncmp ( V_158 , L_16 , 2 ) )
V_159 = V_161 ;
}
static bool F_82 ( enum V_162 V_163 )
{
return V_163 >= V_161 ;
}
static int F_83 ( struct V_7 * V_8 , void * V_164 )
{
int V_20 ;
bool * V_165 = V_164 ;
for ( V_20 = V_127 ; V_20 <= V_128 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
struct V_61 V_62 ;
if ( ! V_22 -> V_17 )
continue;
F_36 ( V_8 -> V_58 , & V_62 , V_22 ) ;
if ( ! V_62 . V_15 ) {
* V_165 = true ;
return 1 ;
}
}
return 0 ;
}
static enum V_162 F_84 ( struct V_57 * V_58 ,
enum V_162 V_166 )
{
bool V_165 = false ;
if ( V_166 != V_167 )
return V_166 ;
F_85 ( V_58 , F_83 , & V_165 ) ;
if ( V_165 )
return V_168 ;
return V_166 ;
}
static enum V_162 F_84 ( struct V_57 * V_58 ,
enum V_162 V_166 )
{
return V_166 ;
}
void F_86 ( struct V_57 * V_58 )
{
F_29 ( V_36 ) ;
struct V_1 * V_169 = NULL ;
int V_170 = 0 ;
enum V_152 V_153 = V_171 ;
F_29 ( V_42 ) ;
struct V_3 * V_45 ;
unsigned long V_104 = V_47 | V_48 |
V_49 | V_87 ;
int V_172 = 1 ;
enum V_162 V_166 ;
V_166 = F_84 ( V_58 , V_159 ) ;
if ( F_82 ( V_166 ) ) {
int V_173 = F_80 ( V_58 ) ;
V_172 = V_173 + 1 ;
F_12 ( V_19 , & V_58 -> V_8 ,
L_17 ,
V_173 , V_172 ) ;
}
V_174:
if ( V_170 + 1 == V_172 )
V_169 = & V_36 ;
F_67 ( V_58 , V_169 ) ;
F_70 ( V_58 , V_169 , & V_42 ) ;
if ( V_169 )
F_87 ( ! F_30 ( V_169 ) ) ;
V_170 ++ ;
if ( F_30 ( & V_42 ) )
goto V_175;
if ( V_170 >= V_172 ) {
if ( V_166 == V_167 )
F_35 ( & V_58 -> V_8 , L_18 ) ;
else if ( V_166 == V_168 )
F_35 ( & V_58 -> V_8 , L_19 ) ;
F_1 ( & V_42 ) ;
goto V_175;
}
F_12 ( V_19 , & V_58 -> V_8 ,
L_20 , V_170 + 1 ) ;
if ( ( V_170 + 1 ) > 2 )
V_153 = V_155 ;
F_11 (fail_res, &fail_head, list)
F_77 ( V_45 -> V_8 -> V_58 ,
V_45 -> V_17 & V_104 ,
V_153 ) ;
F_11 (fail_res, &fail_head, list) {
struct V_9 * V_10 = V_45 -> V_10 ;
V_10 -> V_15 = V_45 -> V_15 ;
V_10 -> V_16 = V_45 -> V_16 ;
V_10 -> V_17 = V_45 -> V_17 ;
if ( V_45 -> V_8 -> V_145 )
V_10 -> V_17 = 0 ;
}
F_1 ( & V_42 ) ;
goto V_174;
V_175:
F_79 ( V_58 ) ;
}
void T_5 F_88 ( void )
{
struct V_57 * V_176 ;
F_11 (root_bus, &pci_root_buses, node)
F_86 ( V_176 ) ;
}
void F_89 ( struct V_7 * V_59 )
{
struct V_57 * V_26 = V_59 -> V_145 ;
F_29 ( V_169 ) ;
int V_170 = 0 ;
F_29 ( V_42 ) ;
struct V_3 * V_45 ;
int V_177 ;
unsigned long V_104 = V_47 | V_48 |
V_49 | V_87 ;
V_174:
F_67 ( V_26 , & V_169 ) ;
F_74 ( V_59 , & V_169 , & V_42 ) ;
F_87 ( ! F_30 ( & V_169 ) ) ;
V_170 ++ ;
if ( F_30 ( & V_42 ) )
goto V_178;
if ( V_170 >= 2 ) {
F_1 ( & V_42 ) ;
goto V_178;
}
F_90 ( V_19 L_21 ,
V_170 + 1 ) ;
F_11 (fail_res, &fail_head, list)
F_77 ( V_45 -> V_8 -> V_58 ,
V_45 -> V_17 & V_104 ,
V_155 ) ;
F_11 (fail_res, &fail_head, list) {
struct V_9 * V_10 = V_45 -> V_10 ;
V_10 -> V_15 = V_45 -> V_15 ;
V_10 -> V_16 = V_45 -> V_16 ;
V_10 -> V_17 = V_45 -> V_17 ;
if ( V_45 -> V_8 -> V_145 )
V_10 -> V_17 = 0 ;
}
F_1 ( & V_42 ) ;
goto V_174;
V_178:
V_177 = F_91 ( V_59 ) ;
if ( V_177 )
F_92 ( & V_59 -> V_8 , L_22 , V_177 ) ;
F_93 ( V_59 ) ;
}
void F_94 ( struct V_57 * V_58 )
{
struct V_7 * V_8 ;
F_29 ( V_169 ) ;
F_95 ( & V_179 ) ;
F_11 (dev, &bus->devices, bus_list)
if ( F_96 ( V_8 ) && F_97 ( V_8 ) )
F_67 ( V_8 -> V_145 ,
& V_169 ) ;
F_98 ( & V_179 ) ;
F_70 ( V_58 , & V_169 , NULL ) ;
F_87 ( ! F_30 ( & V_169 ) ) ;
}
