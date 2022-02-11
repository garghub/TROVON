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
if ( V_42 && ! F_26 ( V_4 -> V_8 -> V_43 ) ) {
if ( ! ( ( V_18 == V_44 ) &&
( ! ( V_10 -> V_17 & V_45 ) ) ) )
F_5 ( V_42 ,
V_4 -> V_8 , V_10 ,
0 ,
0 ) ;
}
F_20 ( V_10 ) ;
}
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_1 * V_36 ,
struct V_1 * V_42 )
{
F_28 ( V_46 ) ;
F_28 ( V_47 ) ;
struct V_3 * V_48 ;
struct V_3 * V_4 ;
if ( ! V_36 || F_29 ( V_36 ) )
goto V_49;
F_11 (dev_res, head, list) {
if ( F_5 ( & V_46 , V_4 -> V_8 , V_4 -> V_10 , 0 , 0 ) ) {
F_1 ( & V_46 ) ;
goto V_49;
}
}
F_11 (dev_res, head, list)
V_4 -> V_10 -> V_16 += F_10 ( V_36 ,
V_4 -> V_10 ) ;
F_25 ( V_2 , & V_47 ) ;
if ( F_29 ( & V_47 ) ) {
F_11 (dev_res, head, list)
F_9 ( V_36 , V_4 -> V_10 ) ;
F_1 ( & V_46 ) ;
F_1 ( V_2 ) ;
return;
}
F_1 ( & V_47 ) ;
F_11 (dev_res, head, list)
if ( V_4 -> V_10 -> V_26 )
F_30 ( V_4 -> V_10 ) ;
F_11 (save_res, &save_head, list) {
struct V_9 * V_10 = V_48 -> V_10 ;
V_10 -> V_15 = V_48 -> V_15 ;
V_10 -> V_16 = V_48 -> V_16 ;
V_10 -> V_17 = V_48 -> V_17 ;
}
F_1 ( & V_46 ) ;
V_49:
F_25 ( V_2 , V_42 ) ;
if ( V_36 )
F_21 ( V_36 , V_2 ) ;
F_1 ( V_2 ) ;
}
static void F_31 ( struct V_7 * V_8 ,
struct V_1 * V_50 ,
struct V_1 * V_42 )
{
F_28 ( V_2 ) ;
F_18 ( V_8 , & V_2 ) ;
F_27 ( & V_2 , V_50 , V_42 ) ;
}
static void F_32 ( const struct V_51 * V_43 ,
struct V_1 * V_36 ,
struct V_1 * V_42 )
{
struct V_7 * V_8 ;
F_28 ( V_2 ) ;
F_11 (dev, &bus->devices, bus_list)
F_18 ( V_8 , & V_2 ) ;
F_27 ( & V_2 , V_36 , V_42 ) ;
}
void F_33 ( struct V_51 * V_43 )
{
struct V_7 * V_52 = V_43 -> V_53 ;
struct V_9 * V_10 ;
struct V_54 V_55 ;
F_34 ( & V_52 -> V_8 , L_7 ,
& V_43 -> V_56 ) ;
V_10 = V_43 -> V_9 [ 0 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_57 ) {
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
F_36 ( V_52 , V_58 ,
V_55 . V_15 ) ;
F_36 ( V_52 , V_59 ,
V_55 . V_16 ) ;
}
V_10 = V_43 -> V_9 [ 1 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_57 ) {
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
F_36 ( V_52 , V_60 ,
V_55 . V_15 ) ;
F_36 ( V_52 , V_61 ,
V_55 . V_16 ) ;
}
V_10 = V_43 -> V_9 [ 2 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_62 ) {
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
F_36 ( V_52 , V_63 ,
V_55 . V_15 ) ;
F_36 ( V_52 , V_64 ,
V_55 . V_16 ) ;
}
V_10 = V_43 -> V_9 [ 3 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_62 ) {
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
F_36 ( V_52 , V_65 ,
V_55 . V_15 ) ;
F_36 ( V_52 , V_66 ,
V_55 . V_16 ) ;
}
}
static void F_37 ( struct V_51 * V_43 )
{
struct V_7 * V_52 = V_43 -> V_53 ;
struct V_9 * V_10 ;
struct V_54 V_55 ;
unsigned long V_67 ;
T_3 V_68 , V_69 ;
T_4 V_70 , V_71 ;
V_67 = V_72 ;
if ( V_52 -> V_73 )
V_67 = V_74 ;
V_10 = V_43 -> V_9 [ 0 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_57 ) {
F_38 ( V_52 , V_75 , & V_70 ) ;
V_70 &= 0xffff0000 ;
V_68 = ( V_55 . V_15 >> 8 ) & V_67 ;
V_69 = ( V_55 . V_16 >> 8 ) & V_67 ;
V_70 |= ( ( T_4 ) V_69 << 8 ) | V_68 ;
V_71 = ( V_55 . V_16 & 0xffff0000 ) | ( V_55 . V_15 >> 16 ) ;
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
} else {
V_71 = 0 ;
V_70 = 0x00f0 ;
}
F_36 ( V_52 , V_76 , 0x0000ffff ) ;
F_36 ( V_52 , V_75 , V_70 ) ;
F_36 ( V_52 , V_76 , V_71 ) ;
}
static void F_39 ( struct V_51 * V_43 )
{
struct V_7 * V_52 = V_43 -> V_53 ;
struct V_9 * V_10 ;
struct V_54 V_55 ;
T_4 V_70 ;
V_10 = V_43 -> V_9 [ 1 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_62 ) {
V_70 = ( V_55 . V_15 >> 16 ) & 0xfff0 ;
V_70 |= V_55 . V_16 & 0xfff00000 ;
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
} else {
V_70 = 0x0000fff0 ;
}
F_36 ( V_52 , V_77 , V_70 ) ;
}
static void F_40 ( struct V_51 * V_43 )
{
struct V_7 * V_52 = V_43 -> V_53 ;
struct V_9 * V_10 ;
struct V_54 V_55 ;
T_4 V_70 , V_78 , V_79 ;
F_36 ( V_52 , V_80 , 0 ) ;
V_78 = V_79 = 0 ;
V_10 = V_43 -> V_9 [ 2 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_81 ) {
V_70 = ( V_55 . V_15 >> 16 ) & 0xfff0 ;
V_70 |= V_55 . V_16 & 0xfff00000 ;
if ( V_10 -> V_17 & V_82 ) {
V_78 = F_41 ( V_55 . V_15 ) ;
V_79 = F_41 ( V_55 . V_16 ) ;
}
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
} else {
V_70 = 0x0000fff0 ;
}
F_36 ( V_52 , V_83 , V_70 ) ;
F_36 ( V_52 , V_84 , V_78 ) ;
F_36 ( V_52 , V_80 , V_79 ) ;
}
static void F_42 ( struct V_51 * V_43 , unsigned long type )
{
struct V_7 * V_52 = V_43 -> V_53 ;
F_34 ( & V_52 -> V_8 , L_9 ,
& V_43 -> V_56 ) ;
if ( type & V_57 )
F_37 ( V_43 ) ;
if ( type & V_62 )
F_39 ( V_43 ) ;
if ( type & V_81 )
F_40 ( V_43 ) ;
F_43 ( V_52 , V_85 , V_43 -> V_86 ) ;
}
void F_44 ( struct V_51 * V_43 )
{
unsigned long type = V_57 | V_62 |
V_81 ;
F_42 ( V_43 , type ) ;
}
static void F_45 ( struct V_51 * V_43 )
{
T_2 V_87 ;
T_4 V_88 ;
struct V_7 * V_52 = V_43 -> V_53 ;
struct V_9 * V_89 ;
V_89 = & V_52 -> V_9 [ V_90 ] ;
V_89 [ 1 ] . V_17 |= V_62 ;
F_19 ( V_52 , V_75 , & V_87 ) ;
if ( ! V_87 ) {
F_43 ( V_52 , V_75 , 0xf0f0 ) ;
F_19 ( V_52 , V_75 , & V_87 ) ;
F_43 ( V_52 , V_75 , 0x0 ) ;
}
if ( V_87 )
V_89 [ 0 ] . V_17 |= V_57 ;
if ( V_52 -> V_91 == V_92 && V_52 -> V_93 == 0x0001 )
return;
F_38 ( V_52 , V_83 , & V_88 ) ;
if ( ! V_88 ) {
F_36 ( V_52 , V_83 ,
0xfff0fff0 ) ;
F_38 ( V_52 , V_83 , & V_88 ) ;
F_36 ( V_52 , V_83 , 0x0 ) ;
}
if ( V_88 ) {
V_89 [ 2 ] . V_17 |= V_62 | V_81 ;
if ( ( V_88 & V_94 ) ==
V_95 ) {
V_89 [ 2 ] . V_17 |= V_82 ;
V_89 [ 2 ] . V_17 |= V_95 ;
}
}
if ( V_89 [ 2 ] . V_17 & V_82 ) {
T_4 V_96 , V_5 ;
F_38 ( V_52 , V_84 ,
& V_96 ) ;
F_36 ( V_52 , V_84 ,
0xffffffff ) ;
F_38 ( V_52 , V_84 , & V_5 ) ;
if ( ! V_5 )
V_89 [ 2 ] . V_17 &= ~ V_82 ;
F_36 ( V_52 , V_84 ,
V_96 ) ;
}
}
static struct V_9 * F_46 ( struct V_51 * V_43 , unsigned long type )
{
int V_20 ;
struct V_9 * V_22 ;
unsigned long V_97 = V_57 | V_62 |
V_81 ;
F_47 (bus, r, i) {
if ( V_22 == & V_98 || V_22 == & V_99 )
continue;
if ( V_22 && ( V_22 -> V_17 & V_97 ) == type && ! V_22 -> V_26 )
return V_22 ;
}
return NULL ;
}
static T_1 F_48 ( T_1 V_100 ,
T_1 V_101 ,
T_1 V_102 ,
T_1 V_103 ,
T_1 V_27 )
{
if ( V_100 < V_101 )
V_100 = V_101 ;
if ( V_103 == 1 )
V_103 = 0 ;
#if F_49 ( V_104 ) || F_49 ( V_105 )
V_100 = ( V_100 & 0xff ) + ( ( V_100 & ~ 0xffUL ) << 2 ) ;
#endif
V_100 = F_50 ( V_100 + V_102 , V_27 ) ;
if ( V_100 < V_103 )
V_100 = V_103 ;
return V_100 ;
}
static T_1 F_51 ( T_1 V_100 ,
T_1 V_101 ,
T_1 V_102 ,
T_1 V_103 ,
T_1 V_27 )
{
if ( V_100 < V_101 )
V_100 = V_101 ;
if ( V_103 == 1 )
V_103 = 0 ;
if ( V_100 < V_103 )
V_100 = V_103 ;
V_100 = F_50 ( V_100 + V_102 , V_27 ) ;
return V_100 ;
}
T_1 __weak F_52 ( struct V_51 * V_43 ,
unsigned long type )
{
return 1 ;
}
static T_1 F_53 ( struct V_51 * V_43 ,
unsigned long type )
{
T_1 V_27 = 1 , V_106 ;
if ( type & V_62 )
V_27 = V_107 ;
else if ( type & V_57 ) {
if ( V_43 -> V_53 -> V_73 )
V_27 = V_108 ;
else
V_27 = V_109 ;
}
V_106 = F_52 ( V_43 , type ) ;
return F_54 ( V_27 , V_106 ) ;
}
static void F_55 ( struct V_51 * V_43 , T_1 V_101 ,
T_1 V_11 , struct V_1 * V_36 )
{
struct V_7 * V_8 ;
struct V_9 * V_89 = F_46 ( V_43 , V_57 ) ;
unsigned long V_100 = 0 , V_110 = 0 , V_102 = 0 ;
T_1 V_111 = 0 ;
T_1 V_12 , V_112 , V_27 ;
if ( ! V_89 )
return;
V_112 = V_12 = F_53 ( V_43 , V_57 ) ;
F_11 (dev, &bus->devices, bus_list) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
unsigned long V_113 ;
if ( V_22 -> V_26 || ! ( V_22 -> V_17 & V_57 ) )
continue;
V_113 = F_22 ( V_22 ) ;
if ( V_113 < 0x400 )
V_100 += V_113 ;
else
V_102 += V_113 ;
V_27 = F_14 ( V_8 , V_22 ) ;
if ( V_27 > V_12 )
V_12 = V_27 ;
if ( V_36 )
V_111 += F_10 ( V_36 , V_22 ) ;
}
}
if ( V_12 > V_112 )
V_12 = V_112 ;
V_110 = F_48 ( V_100 , V_101 , V_102 ,
F_22 ( V_89 ) , V_12 ) ;
if ( V_111 > V_11 )
V_11 = V_111 ;
V_102 = ( ! V_36 || ( V_36 && ! V_11 ) ) ? V_110 :
F_48 ( V_100 , V_101 , V_11 + V_102 ,
F_22 ( V_89 ) , V_12 ) ;
if ( ! V_110 && ! V_102 ) {
if ( V_89 -> V_15 || V_89 -> V_16 )
F_34 ( & V_43 -> V_53 -> V_8 , L_10
L_11 , V_89 ,
& V_43 -> V_56 ) ;
V_89 -> V_17 = 0 ;
return;
}
V_89 -> V_15 = V_12 ;
V_89 -> V_16 = V_89 -> V_15 + V_110 - 1 ;
V_89 -> V_17 |= V_40 ;
if ( V_102 > V_110 && V_36 ) {
F_5 ( V_36 , V_43 -> V_53 , V_89 , V_102 - V_110 ,
V_12 ) ;
F_12 ( V_19 , & V_43 -> V_53 -> V_8 , L_12
L_13 , V_89 ,
& V_43 -> V_56 , V_102 - V_110 ) ;
}
}
static inline T_1 F_56 ( T_1 * V_114 ,
int V_115 )
{
T_1 V_27 = 0 ;
T_1 V_12 = 0 ;
int V_116 ;
for ( V_116 = 0 ; V_116 <= V_115 ; V_116 ++ ) {
T_1 V_117 = 1 ;
V_117 <<= ( V_116 + 20 ) ;
if ( ! V_27 )
V_12 = V_117 ;
else if ( F_50 ( V_27 + V_12 , V_12 ) < V_117 )
V_12 = V_117 >> 1 ;
V_27 += V_114 [ V_116 ] ;
}
return V_12 ;
}
static int F_57 ( struct V_51 * V_43 , unsigned long V_118 ,
unsigned long type , T_1 V_101 ,
T_1 V_11 ,
struct V_1 * V_36 )
{
struct V_7 * V_8 ;
T_1 V_12 , V_27 , V_100 , V_110 , V_102 ;
T_1 V_114 [ 12 ] ;
int V_116 , V_115 ;
struct V_9 * V_89 = F_46 ( V_43 , type ) ;
unsigned int V_119 = 0 ;
T_1 V_111 = 0 ;
if ( ! V_89 )
return 0 ;
memset ( V_114 , 0 , sizeof( V_114 ) ) ;
V_115 = 0 ;
V_100 = 0 ;
V_119 = V_89 -> V_17 & V_82 ;
V_89 -> V_17 &= ~ V_82 ;
F_11 (dev, &bus->devices, bus_list) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
T_1 V_113 ;
if ( V_22 -> V_26 || ( V_22 -> V_17 & V_118 ) != type )
continue;
V_113 = F_22 ( V_22 ) ;
#ifdef F_58
if ( V_36 && V_20 >= V_120 &&
V_20 <= V_121 ) {
V_22 -> V_16 = V_22 -> V_15 - 1 ;
F_5 ( V_36 , V_8 , V_22 , V_113 , 0 ) ;
V_111 += V_113 ;
continue;
}
#endif
V_27 = F_14 ( V_8 , V_22 ) ;
V_116 = F_59 ( V_27 ) - 20 ;
if ( V_116 > 11 ) {
F_15 ( & V_8 -> V_8 , L_14
L_15 , V_20 , V_22 ,
( unsigned long long ) V_27 ) ;
V_22 -> V_17 = 0 ;
continue;
}
V_100 += V_113 ;
if ( V_116 < 0 )
V_116 = 0 ;
if ( V_113 == V_27 )
V_114 [ V_116 ] += V_27 ;
if ( V_116 > V_115 )
V_115 = V_116 ;
V_119 &= V_22 -> V_17 & V_82 ;
if ( V_36 )
V_111 += F_10 ( V_36 , V_22 ) ;
}
}
V_12 = F_56 ( V_114 , V_115 ) ;
V_12 = F_54 ( V_12 , F_53 ( V_43 , V_89 -> V_17 & V_118 ) ) ;
V_110 = F_51 ( V_100 , V_101 , 0 , F_22 ( V_89 ) , V_12 ) ;
if ( V_111 > V_11 )
V_11 = V_111 ;
V_102 = ( ! V_36 || ( V_36 && ! V_11 ) ) ? V_110 :
F_51 ( V_100 , V_101 , V_11 ,
F_22 ( V_89 ) , V_12 ) ;
if ( ! V_110 && ! V_102 ) {
if ( V_89 -> V_15 || V_89 -> V_16 )
F_34 ( & V_43 -> V_53 -> V_8 , L_10
L_11 , V_89 ,
& V_43 -> V_56 ) ;
V_89 -> V_17 = 0 ;
return 1 ;
}
V_89 -> V_15 = V_12 ;
V_89 -> V_16 = V_110 + V_12 - 1 ;
V_89 -> V_17 |= V_40 | V_119 ;
if ( V_102 > V_110 && V_36 ) {
F_5 ( V_36 , V_43 -> V_53 , V_89 , V_102 - V_110 , V_12 ) ;
F_12 ( V_19 , & V_43 -> V_53 -> V_8 , L_12
L_16 , V_89 ,
& V_43 -> V_56 , ( unsigned long long ) V_102 - V_110 ) ;
}
return 1 ;
}
unsigned long F_60 ( struct V_9 * V_10 )
{
if ( V_10 -> V_17 & V_57 )
return V_122 ;
if ( V_10 -> V_17 & V_62 )
return V_123 ;
return 0 ;
}
static void F_61 ( struct V_51 * V_43 ,
struct V_1 * V_36 )
{
struct V_7 * V_52 = V_43 -> V_53 ;
struct V_9 * V_89 = & V_52 -> V_9 [ V_90 ] ;
T_1 V_124 = V_123 * 2 ;
T_2 V_125 ;
if ( V_89 [ 0 ] . V_26 )
goto V_126;
V_89 [ 0 ] . V_15 = V_122 ;
V_89 [ 0 ] . V_16 = V_89 [ 0 ] . V_15 + V_122 - 1 ;
V_89 [ 0 ] . V_17 |= V_57 | V_40 ;
if ( V_36 ) {
V_89 [ 0 ] . V_16 -= V_122 ;
F_5 ( V_36 , V_52 , V_89 , V_122 ,
V_122 ) ;
}
V_126:
if ( V_89 [ 1 ] . V_26 )
goto V_127;
V_89 [ 1 ] . V_15 = V_122 ;
V_89 [ 1 ] . V_16 = V_89 [ 1 ] . V_15 + V_122 - 1 ;
V_89 [ 1 ] . V_17 |= V_57 | V_40 ;
if ( V_36 ) {
V_89 [ 1 ] . V_16 -= V_122 ;
F_5 ( V_36 , V_52 , V_89 + 1 , V_122 ,
V_122 ) ;
}
V_127:
F_19 ( V_52 , V_128 , & V_125 ) ;
if ( V_125 & V_129 ) {
V_125 &= ~ V_129 ;
F_43 ( V_52 , V_128 , V_125 ) ;
F_19 ( V_52 , V_128 , & V_125 ) ;
}
F_19 ( V_52 , V_128 , & V_125 ) ;
if ( ! ( V_125 & V_130 ) ) {
V_125 |= V_130 ;
F_43 ( V_52 , V_128 , V_125 ) ;
F_19 ( V_52 , V_128 , & V_125 ) ;
}
if ( V_89 [ 2 ] . V_26 )
goto V_131;
if ( V_125 & V_130 ) {
V_89 [ 2 ] . V_15 = V_123 ;
V_89 [ 2 ] . V_16 = V_89 [ 2 ] . V_15 + V_123 - 1 ;
V_89 [ 2 ] . V_17 |= V_62 | V_81 |
V_40 ;
if ( V_36 ) {
V_89 [ 2 ] . V_16 -= V_123 ;
F_5 ( V_36 , V_52 , V_89 + 2 ,
V_123 , V_123 ) ;
}
V_124 = V_123 ;
}
V_131:
if ( V_89 [ 3 ] . V_26 )
goto V_132;
V_89 [ 3 ] . V_15 = V_123 ;
V_89 [ 3 ] . V_16 = V_89 [ 3 ] . V_15 + V_124 - 1 ;
V_89 [ 3 ] . V_17 |= V_62 | V_40 ;
if ( V_36 ) {
V_89 [ 3 ] . V_16 -= V_124 ;
F_5 ( V_36 , V_52 , V_89 + 3 , V_124 ,
V_123 ) ;
}
V_132:
;
}
void T_5 F_62 ( struct V_51 * V_43 ,
struct V_1 * V_36 )
{
struct V_7 * V_8 ;
unsigned long V_118 , V_133 ;
T_1 V_134 = 0 , V_135 = 0 ;
F_11 (dev, &bus->devices, bus_list) {
struct V_51 * V_136 = V_8 -> V_137 ;
if ( ! V_136 )
continue;
switch ( V_8 -> V_28 >> 8 ) {
case V_138 :
F_61 ( V_136 , V_36 ) ;
break;
case V_139 :
default:
F_62 ( V_136 , V_36 ) ;
break;
}
}
if ( ! V_43 -> V_53 )
return;
switch ( V_43 -> V_53 -> V_28 >> 8 ) {
case V_138 :
break;
case V_139 :
F_45 ( V_43 ) ;
if ( V_43 -> V_53 -> V_140 ) {
V_135 = V_141 ;
V_134 = V_142 ;
}
default:
F_55 ( V_43 , V_36 ? 0 : V_135 ,
V_135 , V_36 ) ;
V_118 = V_62 ;
V_133 = V_62 | V_81 ;
if ( F_57 ( V_43 , V_133 , V_133 ,
V_36 ? 0 : V_134 ,
V_134 , V_36 ) )
V_118 = V_133 ;
else
V_134 += V_134 ;
F_57 ( V_43 , V_118 , V_62 ,
V_36 ? 0 : V_134 ,
V_134 , V_36 ) ;
break;
}
}
void T_5 F_63 ( struct V_51 * V_43 )
{
F_62 ( V_43 , NULL ) ;
}
static void T_5 F_64 ( const struct V_51 * V_43 ,
struct V_1 * V_36 ,
struct V_1 * V_42 )
{
struct V_51 * V_136 ;
struct V_7 * V_8 ;
F_32 ( V_43 , V_36 , V_42 ) ;
F_11 (dev, &bus->devices, bus_list) {
V_136 = V_8 -> V_137 ;
if ( ! V_136 )
continue;
F_64 ( V_136 , V_36 , V_42 ) ;
switch ( V_8 -> V_28 >> 8 ) {
case V_139 :
if ( ! F_65 ( V_8 ) )
F_44 ( V_136 ) ;
break;
case V_138 :
F_33 ( V_136 ) ;
break;
default:
F_34 ( & V_8 -> V_8 , L_17
L_18 , F_66 ( V_136 ) , V_136 -> V_143 ) ;
break;
}
}
}
void T_5 F_67 ( const struct V_51 * V_43 )
{
F_64 ( V_43 , NULL , NULL ) ;
}
static void T_5 F_68 ( const struct V_7 * V_52 ,
struct V_1 * V_50 ,
struct V_1 * V_42 )
{
struct V_51 * V_136 ;
F_31 ( (struct V_7 * ) V_52 ,
V_50 , V_42 ) ;
V_136 = V_52 -> V_137 ;
if ( ! V_136 )
return;
F_64 ( V_136 , V_50 , V_42 ) ;
switch ( V_52 -> V_28 >> 8 ) {
case V_139 :
F_44 ( V_136 ) ;
break;
case V_138 :
F_33 ( V_136 ) ;
break;
default:
F_34 ( & V_52 -> V_8 , L_17
L_18 , F_66 ( V_136 ) , V_136 -> V_143 ) ;
break;
}
}
static void F_69 ( struct V_51 * V_43 ,
unsigned long type )
{
int V_18 ;
bool V_144 = false ;
struct V_7 * V_8 ;
struct V_9 * V_22 ;
unsigned long V_97 = V_57 | V_62 |
V_81 ;
V_8 = V_43 -> V_53 ;
for ( V_18 = V_90 ; V_18 <= V_145 ;
V_18 ++ ) {
V_22 = & V_8 -> V_9 [ V_18 ] ;
if ( ( V_22 -> V_17 & V_97 ) != type )
continue;
if ( ! V_22 -> V_26 )
continue;
F_70 ( V_22 ) ;
if ( ! F_30 ( V_22 ) ) {
F_12 ( V_19 , & V_8 -> V_8 ,
L_19 , V_18 , V_22 ) ;
V_22 -> V_16 = F_22 ( V_22 ) - 1 ;
V_22 -> V_15 = 0 ;
V_22 -> V_17 = 0 ;
V_144 = true ;
}
}
if ( V_144 ) {
if ( type & V_81 )
type = V_81 ;
F_42 ( V_43 , type ) ;
}
}
static void T_5 F_71 ( struct V_51 * V_43 ,
unsigned long type ,
enum V_146 V_147 )
{
struct V_7 * V_8 ;
bool V_148 = true ;
F_11 (dev, &bus->devices, bus_list) {
struct V_51 * V_136 = V_8 -> V_137 ;
if ( ! V_136 )
continue;
V_148 = false ;
if ( ( V_8 -> V_28 >> 8 ) != V_139 )
continue;
if ( V_147 == V_149 )
F_71 ( V_136 , type ,
V_149 ) ;
}
if ( F_26 ( V_43 ) )
return;
if ( ( V_43 -> V_53 -> V_28 >> 8 ) != V_139 )
return;
if ( ( V_147 == V_149 ) || V_148 )
F_69 ( V_43 , type ) ;
}
static void F_72 ( struct V_51 * V_43 )
{
struct V_9 * V_10 ;
int V_20 ;
F_47 (bus, res, i) {
if ( ! V_10 || ! V_10 -> V_16 || ! V_10 -> V_17 )
continue;
F_12 ( V_19 , & V_43 -> V_8 , L_20 , V_20 , V_10 ) ;
}
}
static void F_73 ( struct V_51 * V_43 )
{
struct V_51 * V_136 ;
struct V_7 * V_8 ;
F_72 ( V_43 ) ;
F_11 (dev, &bus->devices, bus_list) {
V_136 = V_8 -> V_137 ;
if ( ! V_136 )
continue;
F_73 ( V_136 ) ;
}
}
static int T_6 F_74 ( struct V_51 * V_43 )
{
int V_150 = 0 ;
struct V_7 * V_8 ;
F_11 (dev, &bus->devices, bus_list) {
int V_151 ;
struct V_51 * V_136 = V_8 -> V_137 ;
if ( ! V_136 )
continue;
V_151 = F_74 ( V_136 ) ;
if ( V_151 + 1 > V_150 )
V_150 = V_151 + 1 ;
}
return V_150 ;
}
static int T_6 F_75 ( void )
{
int V_150 = 0 ;
struct V_51 * V_43 ;
F_11 (bus, &pci_root_buses, node) {
int V_151 ;
V_151 = F_74 ( V_43 ) ;
if ( V_151 > V_150 )
V_150 = V_151 ;
}
return V_150 ;
}
void T_6 F_76 ( char * V_152 )
{
if ( ! strncmp ( V_152 , L_21 , 3 ) )
V_153 = V_154 ;
else if ( ! strncmp ( V_152 , L_22 , 2 ) )
V_153 = V_155 ;
}
static bool T_6 F_77 ( void )
{
return V_153 >= V_155 ;
}
static void T_6 F_78 ( void )
{
#if F_49 ( F_58 ) && F_49 ( V_156 )
struct V_7 * V_8 = NULL ;
if ( V_153 != V_157 )
return;
F_79 (dev) {
int V_20 ;
for ( V_20 = V_120 ; V_20 <= V_121 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
if ( V_22 -> V_17 && ! V_22 -> V_15 ) {
V_153 = V_158 ;
return;
}
}
}
#endif
}
void T_6
F_80 ( void )
{
struct V_51 * V_43 ;
F_28 ( V_36 ) ;
struct V_1 * V_159 = NULL ;
int V_160 = 0 ;
enum V_146 V_147 = V_161 ;
F_28 ( V_42 ) ;
struct V_3 * V_162 ;
unsigned long V_97 = V_57 | V_62 |
V_81 ;
int V_163 = 1 ;
F_78 () ;
if ( F_77 () ) {
int V_164 = F_75 () ;
V_163 = V_164 + 1 ;
F_81 ( V_19 L_23 ,
V_164 , V_163 ) ;
}
V_165:
if ( V_160 + 1 == V_163 )
V_159 = & V_36 ;
F_11 (bus, &pci_root_buses, node)
F_62 ( V_43 , V_159 ) ;
F_11 (bus, &pci_root_buses, node)
F_64 ( V_43 , V_159 , & V_42 ) ;
if ( V_159 )
F_82 ( ! F_29 ( V_159 ) ) ;
V_160 ++ ;
if ( F_29 ( & V_42 ) )
goto V_166;
if ( V_160 >= V_163 ) {
if ( V_153 == V_157 )
F_81 ( V_167 L_24 ) ;
else if ( V_153 == V_158 )
F_81 ( V_167 L_25 ) ;
F_1 ( & V_42 ) ;
goto V_166;
}
F_81 ( V_19 L_26 ,
V_160 + 1 ) ;
if ( ( V_160 + 1 ) > 2 )
V_147 = V_149 ;
F_11 (fail_res, &fail_head, list) {
V_43 = V_162 -> V_8 -> V_43 ;
F_71 ( V_43 ,
V_162 -> V_17 & V_97 ,
V_147 ) ;
}
F_11 (fail_res, &fail_head, list) {
struct V_9 * V_10 = V_162 -> V_10 ;
V_10 -> V_15 = V_162 -> V_15 ;
V_10 -> V_16 = V_162 -> V_16 ;
V_10 -> V_17 = V_162 -> V_17 ;
if ( V_162 -> V_8 -> V_137 )
V_10 -> V_17 = 0 ;
}
F_1 ( & V_42 ) ;
goto V_165;
V_166:
F_11 (bus, &pci_root_buses, node)
F_83 ( V_43 ) ;
F_11 (bus, &pci_root_buses, node)
F_73 ( V_43 ) ;
}
void F_84 ( struct V_7 * V_52 )
{
struct V_51 * V_26 = V_52 -> V_137 ;
F_28 ( V_159 ) ;
int V_160 = 0 ;
F_28 ( V_42 ) ;
struct V_3 * V_162 ;
int V_168 ;
unsigned long V_97 = V_57 | V_62 |
V_81 ;
V_165:
F_62 ( V_26 , & V_159 ) ;
F_68 ( V_52 , & V_159 , & V_42 ) ;
F_82 ( ! F_29 ( & V_159 ) ) ;
V_160 ++ ;
if ( F_29 ( & V_42 ) )
goto V_169;
if ( V_160 >= 2 ) {
F_1 ( & V_42 ) ;
goto V_169;
}
F_81 ( V_19 L_26 ,
V_160 + 1 ) ;
F_11 (fail_res, &fail_head, list) {
struct V_51 * V_43 = V_162 -> V_8 -> V_43 ;
unsigned long V_17 = V_162 -> V_17 ;
F_71 ( V_43 , V_17 & V_97 ,
V_149 ) ;
}
F_11 (fail_res, &fail_head, list) {
struct V_9 * V_10 = V_162 -> V_10 ;
V_10 -> V_15 = V_162 -> V_15 ;
V_10 -> V_16 = V_162 -> V_16 ;
V_10 -> V_17 = V_162 -> V_17 ;
if ( V_162 -> V_8 -> V_137 )
V_10 -> V_17 = 0 ;
}
F_1 ( & V_42 ) ;
goto V_165;
V_169:
V_168 = F_85 ( V_52 ) ;
F_86 ( V_52 ) ;
F_83 ( V_26 ) ;
}
unsigned int T_5 F_87 ( struct V_51 * V_43 )
{
unsigned int F_54 ;
struct V_7 * V_8 ;
F_28 ( V_159 ) ;
F_54 = F_88 ( V_43 ) ;
F_89 ( & V_170 ) ;
F_11 (dev, &bus->devices, bus_list)
if ( V_8 -> V_171 == V_172 ||
V_8 -> V_171 == V_173 )
if ( V_8 -> V_137 )
F_62 ( V_8 -> V_137 ,
& V_159 ) ;
F_90 ( & V_170 ) ;
F_64 ( V_43 , & V_159 , NULL ) ;
F_82 ( ! F_29 ( & V_159 ) ) ;
F_83 ( V_43 ) ;
F_91 ( V_43 ) ;
return F_54 ;
}
