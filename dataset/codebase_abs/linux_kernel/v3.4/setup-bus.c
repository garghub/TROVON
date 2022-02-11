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
V_43 -> V_56 , V_43 -> V_57 ) ;
V_10 = V_43 -> V_9 [ 0 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_58 ) {
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
F_36 ( V_52 , V_59 ,
V_55 . V_15 ) ;
F_36 ( V_52 , V_60 ,
V_55 . V_16 ) ;
}
V_10 = V_43 -> V_9 [ 1 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_58 ) {
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
F_36 ( V_52 , V_61 ,
V_55 . V_15 ) ;
F_36 ( V_52 , V_62 ,
V_55 . V_16 ) ;
}
V_10 = V_43 -> V_9 [ 2 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_63 ) {
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
F_36 ( V_52 , V_64 ,
V_55 . V_15 ) ;
F_36 ( V_52 , V_65 ,
V_55 . V_16 ) ;
}
V_10 = V_43 -> V_9 [ 3 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_63 ) {
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
F_36 ( V_52 , V_66 ,
V_55 . V_15 ) ;
F_36 ( V_52 , V_67 ,
V_55 . V_16 ) ;
}
}
static void F_37 ( struct V_51 * V_43 )
{
struct V_7 * V_52 = V_43 -> V_53 ;
struct V_9 * V_10 ;
struct V_54 V_55 ;
T_3 V_68 , V_69 ;
V_10 = V_43 -> V_9 [ 0 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_58 ) {
F_38 ( V_52 , V_70 , & V_68 ) ;
V_68 &= 0xffff0000 ;
V_68 |= ( V_55 . V_15 >> 8 ) & 0x00f0 ;
V_68 |= V_55 . V_16 & 0xf000 ;
V_69 = ( V_55 . V_16 & 0xffff0000 ) | ( V_55 . V_15 >> 16 ) ;
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
} else {
V_69 = 0 ;
V_68 = 0x00f0 ;
}
F_36 ( V_52 , V_71 , 0x0000ffff ) ;
F_36 ( V_52 , V_70 , V_68 ) ;
F_36 ( V_52 , V_71 , V_69 ) ;
}
static void F_39 ( struct V_51 * V_43 )
{
struct V_7 * V_52 = V_43 -> V_53 ;
struct V_9 * V_10 ;
struct V_54 V_55 ;
T_3 V_68 ;
V_10 = V_43 -> V_9 [ 1 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_63 ) {
V_68 = ( V_55 . V_15 >> 16 ) & 0xfff0 ;
V_68 |= V_55 . V_16 & 0xfff00000 ;
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
} else {
V_68 = 0x0000fff0 ;
}
F_36 ( V_52 , V_72 , V_68 ) ;
}
static void F_40 ( struct V_51 * V_43 )
{
struct V_7 * V_52 = V_43 -> V_53 ;
struct V_9 * V_10 ;
struct V_54 V_55 ;
T_3 V_68 , V_73 , V_74 ;
F_36 ( V_52 , V_75 , 0 ) ;
V_73 = V_74 = 0 ;
V_10 = V_43 -> V_9 [ 2 ] ;
F_35 ( V_52 , & V_55 , V_10 ) ;
if ( V_10 -> V_17 & V_76 ) {
V_68 = ( V_55 . V_15 >> 16 ) & 0xfff0 ;
V_68 |= V_55 . V_16 & 0xfff00000 ;
if ( V_10 -> V_17 & V_77 ) {
V_73 = F_41 ( V_55 . V_15 ) ;
V_74 = F_41 ( V_55 . V_16 ) ;
}
F_34 ( & V_52 -> V_8 , L_8 , V_10 ) ;
} else {
V_68 = 0x0000fff0 ;
}
F_36 ( V_52 , V_78 , V_68 ) ;
F_36 ( V_52 , V_79 , V_73 ) ;
F_36 ( V_52 , V_75 , V_74 ) ;
}
static void F_42 ( struct V_51 * V_43 , unsigned long type )
{
struct V_7 * V_52 = V_43 -> V_53 ;
F_34 ( & V_52 -> V_8 , L_9 ,
V_43 -> V_56 , V_43 -> V_57 ) ;
if ( type & V_58 )
F_37 ( V_43 ) ;
if ( type & V_63 )
F_39 ( V_43 ) ;
if ( type & V_76 )
F_40 ( V_43 ) ;
F_43 ( V_52 , V_80 , V_43 -> V_81 ) ;
}
void F_44 ( struct V_51 * V_43 )
{
unsigned long type = V_58 | V_63 |
V_76 ;
F_42 ( V_43 , type ) ;
}
static void F_45 ( struct V_51 * V_43 )
{
T_2 V_82 ;
T_3 V_83 ;
struct V_7 * V_52 = V_43 -> V_53 ;
struct V_9 * V_84 ;
V_84 = & V_52 -> V_9 [ V_85 ] ;
V_84 [ 1 ] . V_17 |= V_63 ;
F_19 ( V_52 , V_70 , & V_82 ) ;
if ( ! V_82 ) {
F_43 ( V_52 , V_70 , 0xf0f0 ) ;
F_19 ( V_52 , V_70 , & V_82 ) ;
F_43 ( V_52 , V_70 , 0x0 ) ;
}
if ( V_82 )
V_84 [ 0 ] . V_17 |= V_58 ;
if ( V_52 -> V_86 == V_87 && V_52 -> V_88 == 0x0001 )
return;
F_38 ( V_52 , V_78 , & V_83 ) ;
if ( ! V_83 ) {
F_36 ( V_52 , V_78 ,
0xfff0fff0 ) ;
F_38 ( V_52 , V_78 , & V_83 ) ;
F_36 ( V_52 , V_78 , 0x0 ) ;
}
if ( V_83 ) {
V_84 [ 2 ] . V_17 |= V_63 | V_76 ;
if ( ( V_83 & V_89 ) ==
V_90 ) {
V_84 [ 2 ] . V_17 |= V_77 ;
V_84 [ 2 ] . V_17 |= V_90 ;
}
}
if ( V_84 [ 2 ] . V_17 & V_77 ) {
T_3 V_91 , V_5 ;
F_38 ( V_52 , V_79 ,
& V_91 ) ;
F_36 ( V_52 , V_79 ,
0xffffffff ) ;
F_38 ( V_52 , V_79 , & V_5 ) ;
if ( ! V_5 )
V_84 [ 2 ] . V_17 &= ~ V_77 ;
F_36 ( V_52 , V_79 ,
V_91 ) ;
}
}
static struct V_9 * F_46 ( struct V_51 * V_43 , unsigned long type )
{
int V_20 ;
struct V_9 * V_22 ;
unsigned long V_92 = V_58 | V_63 |
V_76 ;
F_47 (bus, r, i) {
if ( V_22 == & V_93 || V_22 == & V_94 )
continue;
if ( V_22 && ( V_22 -> V_17 & V_92 ) == type && ! V_22 -> V_26 )
return V_22 ;
}
return NULL ;
}
static T_1 F_48 ( T_1 V_95 ,
T_1 V_96 ,
T_1 V_97 ,
T_1 V_98 ,
T_1 V_27 )
{
if ( V_95 < V_96 )
V_95 = V_96 ;
if ( V_98 == 1 )
V_98 = 0 ;
#if F_49 ( V_99 ) || F_49 ( V_100 )
V_95 = ( V_95 & 0xff ) + ( ( V_95 & ~ 0xffUL ) << 2 ) ;
#endif
V_95 = F_50 ( V_95 + V_97 , V_27 ) ;
if ( V_95 < V_98 )
V_95 = V_98 ;
return V_95 ;
}
static T_1 F_51 ( T_1 V_95 ,
T_1 V_96 ,
T_1 V_97 ,
T_1 V_98 ,
T_1 V_27 )
{
if ( V_95 < V_96 )
V_95 = V_96 ;
if ( V_98 == 1 )
V_98 = 0 ;
if ( V_95 < V_98 )
V_95 = V_98 ;
V_95 = F_50 ( V_95 + V_97 , V_27 ) ;
return V_95 ;
}
static void F_52 ( struct V_51 * V_43 , T_1 V_96 ,
T_1 V_11 , struct V_1 * V_36 )
{
struct V_7 * V_8 ;
struct V_9 * V_84 = F_46 ( V_43 , V_58 ) ;
unsigned long V_95 = 0 , V_101 = 0 , V_97 = 0 ;
T_1 V_102 = 0 ;
if ( ! V_84 )
return;
F_11 (dev, &bus->devices, bus_list) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
unsigned long V_103 ;
if ( V_22 -> V_26 || ! ( V_22 -> V_17 & V_58 ) )
continue;
V_103 = F_22 ( V_22 ) ;
if ( V_103 < 0x400 )
V_95 += V_103 ;
else
V_97 += V_103 ;
if ( V_36 )
V_102 += F_10 ( V_36 , V_22 ) ;
}
}
V_101 = F_48 ( V_95 , V_96 , V_97 ,
F_22 ( V_84 ) , 4096 ) ;
if ( V_102 > V_11 )
V_11 = V_102 ;
V_97 = ( ! V_36 || ( V_36 && ! V_11 ) ) ? V_101 :
F_48 ( V_95 , V_96 , V_11 + V_97 ,
F_22 ( V_84 ) , 4096 ) ;
if ( ! V_101 && ! V_97 ) {
if ( V_84 -> V_15 || V_84 -> V_16 )
F_34 ( & V_43 -> V_53 -> V_8 , L_10
L_11 , V_84 ,
V_43 -> V_56 , V_43 -> V_57 ) ;
V_84 -> V_17 = 0 ;
return;
}
V_84 -> V_15 = 4096 ;
V_84 -> V_16 = V_84 -> V_15 + V_101 - 1 ;
V_84 -> V_17 |= V_40 ;
if ( V_97 > V_101 && V_36 ) {
F_5 ( V_36 , V_43 -> V_53 , V_84 , V_97 - V_101 , 4096 ) ;
F_12 ( V_19 , & V_43 -> V_53 -> V_8 , L_12
L_13 , V_84 ,
V_43 -> V_56 , V_43 -> V_57 , V_97 - V_101 ) ;
}
}
static int F_53 ( struct V_51 * V_43 , unsigned long V_104 ,
unsigned long type , T_1 V_96 ,
T_1 V_11 ,
struct V_1 * V_36 )
{
struct V_7 * V_8 ;
T_1 V_12 , V_27 , V_95 , V_101 , V_97 ;
T_1 V_105 [ 12 ] ;
int V_106 , V_107 ;
struct V_9 * V_84 = F_46 ( V_43 , type ) ;
unsigned int V_108 = 0 ;
T_1 V_102 = 0 ;
if ( ! V_84 )
return 0 ;
memset ( V_105 , 0 , sizeof( V_105 ) ) ;
V_107 = 0 ;
V_95 = 0 ;
V_108 = V_84 -> V_17 & V_77 ;
V_84 -> V_17 &= ~ V_77 ;
F_11 (dev, &bus->devices, bus_list) {
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
T_1 V_103 ;
if ( V_22 -> V_26 || ( V_22 -> V_17 & V_104 ) != type )
continue;
V_103 = F_22 ( V_22 ) ;
#ifdef F_54
if ( V_36 && V_20 >= V_109 &&
V_20 <= V_110 ) {
V_22 -> V_16 = V_22 -> V_15 - 1 ;
F_5 ( V_36 , V_8 , V_22 , V_103 , 0 ) ;
V_102 += V_103 ;
continue;
}
#endif
V_27 = F_14 ( V_8 , V_22 ) ;
V_106 = F_55 ( V_27 ) - 20 ;
if ( V_106 > 11 ) {
F_15 ( & V_8 -> V_8 , L_14
L_15 , V_20 , V_22 ,
( unsigned long long ) V_27 ) ;
V_22 -> V_17 = 0 ;
continue;
}
V_95 += V_103 ;
if ( V_106 < 0 )
V_106 = 0 ;
if ( V_103 == V_27 )
V_105 [ V_106 ] += V_27 ;
if ( V_106 > V_107 )
V_107 = V_106 ;
V_108 &= V_22 -> V_17 & V_77 ;
if ( V_36 )
V_102 += F_10 ( V_36 , V_22 ) ;
}
}
V_27 = 0 ;
V_12 = 0 ;
for ( V_106 = 0 ; V_106 <= V_107 ; V_106 ++ ) {
T_1 V_111 = 1 ;
V_111 <<= ( V_106 + 20 ) ;
if ( ! V_27 )
V_12 = V_111 ;
else if ( F_50 ( V_27 + V_12 , V_12 ) < V_111 )
V_12 = V_111 >> 1 ;
V_27 += V_105 [ V_106 ] ;
}
V_101 = F_51 ( V_95 , V_96 , 0 , F_22 ( V_84 ) , V_12 ) ;
if ( V_102 > V_11 )
V_11 = V_102 ;
V_97 = ( ! V_36 || ( V_36 && ! V_11 ) ) ? V_101 :
F_51 ( V_95 , V_96 , V_11 ,
F_22 ( V_84 ) , V_12 ) ;
if ( ! V_101 && ! V_97 ) {
if ( V_84 -> V_15 || V_84 -> V_16 )
F_34 ( & V_43 -> V_53 -> V_8 , L_10
L_11 , V_84 ,
V_43 -> V_56 , V_43 -> V_57 ) ;
V_84 -> V_17 = 0 ;
return 1 ;
}
V_84 -> V_15 = V_12 ;
V_84 -> V_16 = V_101 + V_12 - 1 ;
V_84 -> V_17 |= V_40 | V_108 ;
if ( V_97 > V_101 && V_36 ) {
F_5 ( V_36 , V_43 -> V_53 , V_84 , V_97 - V_101 , V_12 ) ;
F_12 ( V_19 , & V_43 -> V_53 -> V_8 , L_12
L_16 , V_84 ,
V_43 -> V_56 , V_43 -> V_57 , ( unsigned long long ) V_97 - V_101 ) ;
}
return 1 ;
}
unsigned long F_56 ( struct V_9 * V_10 )
{
if ( V_10 -> V_17 & V_58 )
return V_112 ;
if ( V_10 -> V_17 & V_63 )
return V_113 ;
return 0 ;
}
static void F_57 ( struct V_51 * V_43 ,
struct V_1 * V_36 )
{
struct V_7 * V_52 = V_43 -> V_53 ;
struct V_9 * V_84 = & V_52 -> V_9 [ V_85 ] ;
T_1 V_114 = V_113 * 2 ;
T_2 V_115 ;
if ( V_84 [ 0 ] . V_26 )
goto V_116;
V_84 [ 0 ] . V_15 = V_112 ;
V_84 [ 0 ] . V_16 = V_84 [ 0 ] . V_15 + V_112 - 1 ;
V_84 [ 0 ] . V_17 |= V_58 | V_40 ;
if ( V_36 ) {
V_84 [ 0 ] . V_16 -= V_112 ;
F_5 ( V_36 , V_52 , V_84 , V_112 ,
V_112 ) ;
}
V_116:
if ( V_84 [ 1 ] . V_26 )
goto V_117;
V_84 [ 1 ] . V_15 = V_112 ;
V_84 [ 1 ] . V_16 = V_84 [ 1 ] . V_15 + V_112 - 1 ;
V_84 [ 1 ] . V_17 |= V_58 | V_40 ;
if ( V_36 ) {
V_84 [ 1 ] . V_16 -= V_112 ;
F_5 ( V_36 , V_52 , V_84 + 1 , V_112 ,
V_112 ) ;
}
V_117:
F_19 ( V_52 , V_118 , & V_115 ) ;
if ( V_115 & V_119 ) {
V_115 &= ~ V_119 ;
F_43 ( V_52 , V_118 , V_115 ) ;
F_19 ( V_52 , V_118 , & V_115 ) ;
}
F_19 ( V_52 , V_118 , & V_115 ) ;
if ( ! ( V_115 & V_120 ) ) {
V_115 |= V_120 ;
F_43 ( V_52 , V_118 , V_115 ) ;
F_19 ( V_52 , V_118 , & V_115 ) ;
}
if ( V_84 [ 2 ] . V_26 )
goto V_121;
if ( V_115 & V_120 ) {
V_84 [ 2 ] . V_15 = V_113 ;
V_84 [ 2 ] . V_16 = V_84 [ 2 ] . V_15 + V_113 - 1 ;
V_84 [ 2 ] . V_17 |= V_63 | V_76 |
V_40 ;
if ( V_36 ) {
V_84 [ 2 ] . V_16 -= V_113 ;
F_5 ( V_36 , V_52 , V_84 + 2 ,
V_113 , V_113 ) ;
}
V_114 = V_113 ;
}
V_121:
if ( V_84 [ 3 ] . V_26 )
goto V_122;
V_84 [ 3 ] . V_15 = V_113 ;
V_84 [ 3 ] . V_16 = V_84 [ 3 ] . V_15 + V_114 - 1 ;
V_84 [ 3 ] . V_17 |= V_63 | V_40 ;
if ( V_36 ) {
V_84 [ 3 ] . V_16 -= V_114 ;
F_5 ( V_36 , V_52 , V_84 + 3 , V_114 ,
V_113 ) ;
}
V_122:
;
}
void T_4 F_58 ( struct V_51 * V_43 ,
struct V_1 * V_36 )
{
struct V_7 * V_8 ;
unsigned long V_104 , V_123 ;
T_1 V_124 = 0 , V_125 = 0 ;
F_11 (dev, &bus->devices, bus_list) {
struct V_51 * V_126 = V_8 -> V_57 ;
if ( ! V_126 )
continue;
switch ( V_8 -> V_28 >> 8 ) {
case V_127 :
F_57 ( V_126 , V_36 ) ;
break;
case V_128 :
default:
F_58 ( V_126 , V_36 ) ;
break;
}
}
if ( ! V_43 -> V_53 )
return;
switch ( V_43 -> V_53 -> V_28 >> 8 ) {
case V_127 :
break;
case V_128 :
F_45 ( V_43 ) ;
if ( V_43 -> V_53 -> V_129 ) {
V_125 = V_130 ;
V_124 = V_131 ;
}
default:
F_52 ( V_43 , V_36 ? 0 : V_125 ,
V_125 , V_36 ) ;
V_104 = V_63 ;
V_123 = V_63 | V_76 ;
if ( F_53 ( V_43 , V_123 , V_123 ,
V_36 ? 0 : V_124 ,
V_124 , V_36 ) )
V_104 = V_123 ;
else
V_124 += V_124 ;
F_53 ( V_43 , V_104 , V_63 ,
V_36 ? 0 : V_124 ,
V_124 , V_36 ) ;
break;
}
}
void T_4 F_59 ( struct V_51 * V_43 )
{
F_58 ( V_43 , NULL ) ;
}
static void T_4 F_60 ( const struct V_51 * V_43 ,
struct V_1 * V_36 ,
struct V_1 * V_42 )
{
struct V_51 * V_126 ;
struct V_7 * V_8 ;
F_32 ( V_43 , V_36 , V_42 ) ;
F_11 (dev, &bus->devices, bus_list) {
V_126 = V_8 -> V_57 ;
if ( ! V_126 )
continue;
F_60 ( V_126 , V_36 , V_42 ) ;
switch ( V_8 -> V_28 >> 8 ) {
case V_128 :
if ( ! F_61 ( V_8 ) )
F_44 ( V_126 ) ;
break;
case V_127 :
F_33 ( V_126 ) ;
break;
default:
F_34 ( & V_8 -> V_8 , L_17
L_18 , F_62 ( V_126 ) , V_126 -> V_132 ) ;
break;
}
}
}
void T_4 F_63 ( const struct V_51 * V_43 )
{
F_60 ( V_43 , NULL , NULL ) ;
}
static void T_4 F_64 ( const struct V_7 * V_52 ,
struct V_1 * V_50 ,
struct V_1 * V_42 )
{
struct V_51 * V_126 ;
F_31 ( (struct V_7 * ) V_52 ,
V_50 , V_42 ) ;
V_126 = V_52 -> V_57 ;
if ( ! V_126 )
return;
F_60 ( V_126 , V_50 , V_42 ) ;
switch ( V_52 -> V_28 >> 8 ) {
case V_128 :
F_44 ( V_126 ) ;
break;
case V_127 :
F_33 ( V_126 ) ;
break;
default:
F_34 ( & V_52 -> V_8 , L_17
L_18 , F_62 ( V_126 ) , V_126 -> V_132 ) ;
break;
}
}
static void F_65 ( struct V_51 * V_43 ,
unsigned long type )
{
int V_18 ;
bool V_133 = false ;
struct V_7 * V_8 ;
struct V_9 * V_22 ;
unsigned long V_92 = V_58 | V_63 |
V_76 ;
V_8 = V_43 -> V_53 ;
for ( V_18 = V_85 ; V_18 <= V_134 ;
V_18 ++ ) {
V_22 = & V_8 -> V_9 [ V_18 ] ;
if ( ( V_22 -> V_17 & V_92 ) != type )
continue;
if ( ! V_22 -> V_26 )
continue;
F_66 ( V_22 ) ;
if ( ! F_30 ( V_22 ) ) {
F_12 ( V_19 , & V_8 -> V_8 ,
L_19 , V_18 , V_22 ) ;
V_22 -> V_16 = F_22 ( V_22 ) - 1 ;
V_22 -> V_15 = 0 ;
V_22 -> V_17 = 0 ;
V_133 = true ;
}
}
if ( V_133 ) {
if ( type & V_76 )
type = V_76 ;
F_42 ( V_43 , type ) ;
}
}
static void T_4 F_67 ( struct V_51 * V_43 ,
unsigned long type ,
enum V_135 V_136 )
{
struct V_7 * V_8 ;
bool V_137 = true ;
F_11 (dev, &bus->devices, bus_list) {
struct V_51 * V_126 = V_8 -> V_57 ;
if ( ! V_126 )
continue;
V_137 = false ;
if ( ( V_8 -> V_28 >> 8 ) != V_128 )
continue;
if ( V_136 == V_138 )
F_67 ( V_126 , type ,
V_138 ) ;
}
if ( F_26 ( V_43 ) )
return;
if ( ( V_43 -> V_53 -> V_28 >> 8 ) != V_128 )
return;
if ( ( V_136 == V_138 ) || V_137 )
F_65 ( V_43 , type ) ;
}
static void F_68 ( struct V_51 * V_43 )
{
struct V_9 * V_10 ;
int V_20 ;
F_47 (bus, res, i) {
if ( ! V_10 || ! V_10 -> V_16 || ! V_10 -> V_17 )
continue;
F_12 ( V_19 , & V_43 -> V_8 , L_20 , V_20 , V_10 ) ;
}
}
static void F_69 ( struct V_51 * V_43 )
{
struct V_51 * V_126 ;
struct V_7 * V_8 ;
F_68 ( V_43 ) ;
F_11 (dev, &bus->devices, bus_list) {
V_126 = V_8 -> V_57 ;
if ( ! V_126 )
continue;
F_69 ( V_126 ) ;
}
}
static int T_5 F_70 ( struct V_51 * V_43 )
{
int V_139 = 0 ;
struct V_7 * V_8 ;
F_11 (dev, &bus->devices, bus_list) {
int V_140 ;
struct V_51 * V_126 = V_8 -> V_57 ;
if ( ! V_126 )
continue;
V_140 = F_70 ( V_126 ) ;
if ( V_140 + 1 > V_139 )
V_139 = V_140 + 1 ;
}
return V_139 ;
}
static int T_5 F_71 ( void )
{
int V_139 = 0 ;
struct V_51 * V_43 ;
F_11 (bus, &pci_root_buses, node) {
int V_140 ;
V_140 = F_70 ( V_43 ) ;
if ( V_140 > V_139 )
V_139 = V_140 ;
}
return V_139 ;
}
void T_5 F_72 ( char * V_141 )
{
if ( ! strncmp ( V_141 , L_21 , 3 ) )
V_142 = V_143 ;
else if ( ! strncmp ( V_141 , L_22 , 2 ) )
V_142 = V_144 ;
}
static bool T_5 F_73 ( void )
{
return V_142 >= V_144 ;
}
static void T_5 F_74 ( void )
{
#if F_49 ( F_54 ) && F_49 ( V_145 )
struct V_7 * V_8 = NULL ;
if ( V_142 != V_146 )
return;
F_75 (dev) {
int V_20 ;
for ( V_20 = V_109 ; V_20 <= V_110 ; V_20 ++ ) {
struct V_9 * V_22 = & V_8 -> V_9 [ V_20 ] ;
if ( V_22 -> V_17 && ! V_22 -> V_15 ) {
V_142 = V_147 ;
return;
}
}
}
#endif
}
void T_5
F_76 ( void )
{
struct V_51 * V_43 ;
F_28 ( V_36 ) ;
struct V_1 * V_148 = NULL ;
int V_149 = 0 ;
enum V_135 V_136 = V_150 ;
F_28 ( V_42 ) ;
struct V_3 * V_151 ;
unsigned long V_92 = V_58 | V_63 |
V_76 ;
int V_152 = 1 ;
F_74 () ;
if ( F_73 () ) {
int V_153 = F_71 () ;
V_152 = V_153 + 1 ;
F_77 ( V_19 L_23 ,
V_153 , V_152 ) ;
}
V_154:
if ( V_149 + 1 == V_152 )
V_148 = & V_36 ;
F_11 (bus, &pci_root_buses, node)
F_58 ( V_43 , V_148 ) ;
F_11 (bus, &pci_root_buses, node)
F_60 ( V_43 , V_148 , & V_42 ) ;
if ( V_148 )
F_78 ( ! F_29 ( V_148 ) ) ;
V_149 ++ ;
if ( F_29 ( & V_42 ) )
goto V_155;
if ( V_149 >= V_152 ) {
if ( V_142 == V_146 )
F_77 ( V_156 L_24 ) ;
else if ( V_142 == V_147 )
F_77 ( V_156 L_25 ) ;
F_1 ( & V_42 ) ;
goto V_155;
}
F_77 ( V_19 L_26 ,
V_149 + 1 ) ;
if ( ( V_149 + 1 ) > 2 )
V_136 = V_138 ;
F_11 (fail_res, &fail_head, list) {
V_43 = V_151 -> V_8 -> V_43 ;
F_67 ( V_43 ,
V_151 -> V_17 & V_92 ,
V_136 ) ;
}
F_11 (fail_res, &fail_head, list) {
struct V_9 * V_10 = V_151 -> V_10 ;
V_10 -> V_15 = V_151 -> V_15 ;
V_10 -> V_16 = V_151 -> V_16 ;
V_10 -> V_17 = V_151 -> V_17 ;
if ( V_151 -> V_8 -> V_57 )
V_10 -> V_17 = 0 ;
}
F_1 ( & V_42 ) ;
goto V_154;
V_155:
F_11 (bus, &pci_root_buses, node)
F_79 ( V_43 ) ;
F_11 (bus, &pci_root_buses, node)
F_69 ( V_43 ) ;
}
void F_80 ( struct V_7 * V_52 )
{
struct V_51 * V_26 = V_52 -> V_57 ;
F_28 ( V_148 ) ;
int V_149 = 0 ;
F_28 ( V_42 ) ;
struct V_3 * V_151 ;
int V_157 ;
unsigned long V_92 = V_58 | V_63 |
V_76 ;
V_154:
F_58 ( V_26 , & V_148 ) ;
F_64 ( V_52 , & V_148 , & V_42 ) ;
F_78 ( ! F_29 ( & V_148 ) ) ;
V_149 ++ ;
if ( F_29 ( & V_42 ) )
goto V_158;
if ( V_149 >= 2 ) {
F_1 ( & V_42 ) ;
goto V_158;
}
F_77 ( V_19 L_26 ,
V_149 + 1 ) ;
F_11 (fail_res, &fail_head, list) {
struct V_51 * V_43 = V_151 -> V_8 -> V_43 ;
unsigned long V_17 = V_151 -> V_17 ;
F_67 ( V_43 , V_17 & V_92 ,
V_138 ) ;
}
F_11 (fail_res, &fail_head, list) {
struct V_9 * V_10 = V_151 -> V_10 ;
V_10 -> V_15 = V_151 -> V_15 ;
V_10 -> V_16 = V_151 -> V_16 ;
V_10 -> V_17 = V_151 -> V_17 ;
if ( V_151 -> V_8 -> V_57 )
V_10 -> V_17 = 0 ;
}
F_1 ( & V_42 ) ;
goto V_154;
V_158:
V_157 = F_81 ( V_52 ) ;
F_82 ( V_52 ) ;
F_79 ( V_26 ) ;
}
unsigned int T_4 F_83 ( struct V_51 * V_43 )
{
unsigned int V_159 ;
struct V_7 * V_8 ;
F_28 ( V_148 ) ;
V_159 = F_84 ( V_43 ) ;
F_85 ( & V_160 ) ;
F_11 (dev, &bus->devices, bus_list)
if ( V_8 -> V_161 == V_162 ||
V_8 -> V_161 == V_163 )
if ( V_8 -> V_57 )
F_58 ( V_8 -> V_57 ,
& V_148 ) ;
F_86 ( & V_160 ) ;
F_60 ( V_43 , & V_148 , NULL ) ;
F_78 ( ! F_29 ( & V_148 ) ) ;
F_79 ( V_43 ) ;
F_87 ( V_43 ) ;
return V_159 ;
}
