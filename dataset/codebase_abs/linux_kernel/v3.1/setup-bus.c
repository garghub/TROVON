void F_1 ( void )
{
V_1 = 1 ;
}
static void F_2 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
T_1 V_8 , T_1 V_9 )
{
struct V_2 * V_10 = V_3 ;
struct V_2 * V_11 = V_10 -> V_12 ;
struct V_2 * V_13 ;
V_13 = F_3 ( sizeof( * V_13 ) , V_14 ) ;
if ( ! V_13 ) {
F_4 ( L_1 ) ;
return;
}
V_13 -> V_12 = V_11 ;
V_13 -> V_7 = V_7 ;
V_13 -> V_5 = V_5 ;
V_13 -> V_15 = V_7 -> V_15 ;
V_13 -> V_16 = V_7 -> V_16 ;
V_13 -> V_17 = V_7 -> V_17 ;
V_13 -> V_8 = V_8 ;
V_13 -> V_9 = V_9 ;
V_10 -> V_12 = V_13 ;
}
static void F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
F_2 ( V_3 , V_5 , V_7 ,
0 ,
0 ) ;
}
static void F_6 ( struct V_4 * V_5 ,
struct V_18 * V_3 )
{
T_2 V_19 = V_5 -> V_19 >> 8 ;
if ( V_19 == V_20 || V_19 == V_21 )
return;
if ( V_19 == V_22 ) {
T_2 V_23 ;
F_7 ( V_5 , V_24 , & V_23 ) ;
if ( V_23 & ( V_25 | V_26 ) )
return;
}
F_8 ( V_5 , V_3 ) ;
}
static inline void F_9 ( struct V_6 * V_7 )
{
V_7 -> V_15 = 0 ;
V_7 -> V_16 = 0 ;
V_7 -> V_17 = 0 ;
}
static void F_10 ( struct V_2 * V_27 ,
struct V_18 * V_3 )
{
struct V_6 * V_7 ;
struct V_2 * V_10 , * V_13 , * V_28 ;
struct V_18 * V_29 ;
T_1 V_8 ;
int V_30 ;
V_28 = V_27 ;
for ( V_10 = V_27 -> V_12 ; V_10 ; ) {
V_7 = V_10 -> V_7 ;
if ( ! V_7 -> V_17 )
goto V_31;
for ( V_29 = V_3 -> V_12 ; V_29 && V_29 -> V_7 != V_7 ;
V_29 = V_29 -> V_12 ) ;
if ( ! V_29 ) {
V_28 = V_10 ;
V_10 = V_10 -> V_12 ;
continue;
}
V_30 = V_7 - & V_10 -> V_5 -> V_6 [ 0 ] ;
V_8 = V_10 -> V_8 ;
if ( ! F_11 ( V_7 ) ) {
V_7 -> V_15 = V_10 -> V_15 ;
V_7 -> V_16 = V_7 -> V_15 + V_8 - 1 ;
if( F_12 ( V_10 -> V_5 , V_30 ) )
F_9 ( V_7 ) ;
} else {
T_1 V_32 = V_10 -> V_9 ;
V_7 -> V_17 |= V_10 -> V_17 & ( V_33 | V_34 ) ;
if ( F_13 ( V_10 -> V_5 , V_30 , V_8 , V_32 ) )
F_14 ( V_35 , & V_10 -> V_5 -> V_5 , L_2 ,
V_7 ) ;
}
V_31:
V_13 = V_10 ;
V_28 -> V_12 = V_10 = V_10 -> V_12 ;
F_15 ( V_13 ) ;
}
}
static void F_16 ( struct V_18 * V_3 ,
struct V_2 * V_36 )
{
struct V_6 * V_7 ;
struct V_18 * V_10 ;
int V_30 ;
for ( V_10 = V_3 -> V_12 ; V_10 ; V_10 = V_10 -> V_12 ) {
V_7 = V_10 -> V_7 ;
V_30 = V_7 - & V_10 -> V_5 -> V_6 [ 0 ] ;
if ( F_11 ( V_7 ) && F_12 ( V_10 -> V_5 , V_30 ) ) {
if ( V_36 && ! F_17 ( V_10 -> V_5 -> V_37 ) ) {
if ( ! ( ( V_30 == V_38 ) &&
( ! ( V_7 -> V_17 & V_39 ) ) ) )
F_5 ( V_36 , V_10 -> V_5 , V_7 ) ;
}
F_9 ( V_7 ) ;
}
}
}
static void F_18 ( struct V_18 * V_3 ,
struct V_2 * V_27 ,
struct V_2 * V_36 )
{
F_16 ( V_3 , V_36 ) ;
if ( V_27 )
F_10 ( V_27 , V_3 ) ;
F_19 ( V_18 , V_3 ) ;
}
static void F_20 ( struct V_4 * V_5 ,
struct V_2 * V_36 )
{
struct V_18 V_3 ;
V_3 . V_12 = NULL ;
F_6 ( V_5 , & V_3 ) ;
F_18 ( & V_3 , NULL , V_36 ) ;
}
static void F_21 ( const struct V_40 * V_37 ,
struct V_2 * V_27 ,
struct V_2 * V_36 )
{
struct V_4 * V_5 ;
struct V_18 V_3 ;
V_3 . V_12 = NULL ;
F_22 (dev, &bus->devices, bus_list)
F_6 ( V_5 , & V_3 ) ;
F_18 ( & V_3 , V_27 , V_36 ) ;
}
void F_23 ( struct V_40 * V_37 )
{
struct V_4 * V_41 = V_37 -> V_42 ;
struct V_6 * V_7 ;
struct V_43 V_44 ;
F_24 ( & V_41 -> V_5 , L_3 ,
V_37 -> V_45 , V_37 -> V_46 ) ;
V_7 = V_37 -> V_6 [ 0 ] ;
F_25 ( V_41 , & V_44 , V_7 ) ;
if ( V_7 -> V_17 & V_47 ) {
F_24 ( & V_41 -> V_5 , L_4 , V_7 ) ;
F_26 ( V_41 , V_48 ,
V_44 . V_15 ) ;
F_26 ( V_41 , V_49 ,
V_44 . V_16 ) ;
}
V_7 = V_37 -> V_6 [ 1 ] ;
F_25 ( V_41 , & V_44 , V_7 ) ;
if ( V_7 -> V_17 & V_47 ) {
F_24 ( & V_41 -> V_5 , L_4 , V_7 ) ;
F_26 ( V_41 , V_50 ,
V_44 . V_15 ) ;
F_26 ( V_41 , V_51 ,
V_44 . V_16 ) ;
}
V_7 = V_37 -> V_6 [ 2 ] ;
F_25 ( V_41 , & V_44 , V_7 ) ;
if ( V_7 -> V_17 & V_52 ) {
F_24 ( & V_41 -> V_5 , L_4 , V_7 ) ;
F_26 ( V_41 , V_53 ,
V_44 . V_15 ) ;
F_26 ( V_41 , V_54 ,
V_44 . V_16 ) ;
}
V_7 = V_37 -> V_6 [ 3 ] ;
F_25 ( V_41 , & V_44 , V_7 ) ;
if ( V_7 -> V_17 & V_52 ) {
F_24 ( & V_41 -> V_5 , L_4 , V_7 ) ;
F_26 ( V_41 , V_55 ,
V_44 . V_15 ) ;
F_26 ( V_41 , V_56 ,
V_44 . V_16 ) ;
}
}
static void F_27 ( struct V_40 * V_37 )
{
struct V_4 * V_41 = V_37 -> V_42 ;
struct V_6 * V_7 ;
struct V_43 V_44 ;
T_3 V_57 , V_58 ;
V_7 = V_37 -> V_6 [ 0 ] ;
F_25 ( V_41 , & V_44 , V_7 ) ;
if ( V_7 -> V_17 & V_47 ) {
F_28 ( V_41 , V_59 , & V_57 ) ;
V_57 &= 0xffff0000 ;
V_57 |= ( V_44 . V_15 >> 8 ) & 0x00f0 ;
V_57 |= V_44 . V_16 & 0xf000 ;
V_58 = ( V_44 . V_16 & 0xffff0000 ) | ( V_44 . V_15 >> 16 ) ;
F_24 ( & V_41 -> V_5 , L_4 , V_7 ) ;
} else {
V_58 = 0 ;
V_57 = 0x00f0 ;
}
F_26 ( V_41 , V_60 , 0x0000ffff ) ;
F_26 ( V_41 , V_59 , V_57 ) ;
F_26 ( V_41 , V_60 , V_58 ) ;
}
static void F_29 ( struct V_40 * V_37 )
{
struct V_4 * V_41 = V_37 -> V_42 ;
struct V_6 * V_7 ;
struct V_43 V_44 ;
T_3 V_57 ;
V_7 = V_37 -> V_6 [ 1 ] ;
F_25 ( V_41 , & V_44 , V_7 ) ;
if ( V_7 -> V_17 & V_52 ) {
V_57 = ( V_44 . V_15 >> 16 ) & 0xfff0 ;
V_57 |= V_44 . V_16 & 0xfff00000 ;
F_24 ( & V_41 -> V_5 , L_4 , V_7 ) ;
} else {
V_57 = 0x0000fff0 ;
}
F_26 ( V_41 , V_61 , V_57 ) ;
}
static void F_30 ( struct V_40 * V_37 )
{
struct V_4 * V_41 = V_37 -> V_42 ;
struct V_6 * V_7 ;
struct V_43 V_44 ;
T_3 V_57 , V_62 , V_63 ;
F_26 ( V_41 , V_64 , 0 ) ;
V_62 = V_63 = 0 ;
V_7 = V_37 -> V_6 [ 2 ] ;
F_25 ( V_41 , & V_44 , V_7 ) ;
if ( V_7 -> V_17 & V_65 ) {
V_57 = ( V_44 . V_15 >> 16 ) & 0xfff0 ;
V_57 |= V_44 . V_16 & 0xfff00000 ;
if ( V_7 -> V_17 & V_66 ) {
V_62 = F_31 ( V_44 . V_15 ) ;
V_63 = F_31 ( V_44 . V_16 ) ;
}
F_24 ( & V_41 -> V_5 , L_4 , V_7 ) ;
} else {
V_57 = 0x0000fff0 ;
}
F_26 ( V_41 , V_67 , V_57 ) ;
F_26 ( V_41 , V_68 , V_62 ) ;
F_26 ( V_41 , V_64 , V_63 ) ;
}
static void F_32 ( struct V_40 * V_37 , unsigned long type )
{
struct V_4 * V_41 = V_37 -> V_42 ;
F_24 ( & V_41 -> V_5 , L_5 ,
V_37 -> V_45 , V_37 -> V_46 ) ;
if ( type & V_47 )
F_27 ( V_37 ) ;
if ( type & V_52 )
F_29 ( V_37 ) ;
if ( type & V_65 )
F_30 ( V_37 ) ;
F_33 ( V_41 , V_69 , V_37 -> V_70 ) ;
}
static void F_34 ( struct V_40 * V_37 )
{
unsigned long type = V_47 | V_52 |
V_65 ;
F_32 ( V_37 , type ) ;
}
static void F_35 ( struct V_40 * V_37 )
{
T_2 V_71 ;
T_3 V_72 ;
struct V_4 * V_41 = V_37 -> V_42 ;
struct V_6 * V_73 ;
V_73 = & V_41 -> V_6 [ V_74 ] ;
V_73 [ 1 ] . V_17 |= V_52 ;
F_7 ( V_41 , V_59 , & V_71 ) ;
if ( ! V_71 ) {
F_33 ( V_41 , V_59 , 0xf0f0 ) ;
F_7 ( V_41 , V_59 , & V_71 ) ;
F_33 ( V_41 , V_59 , 0x0 ) ;
}
if ( V_71 )
V_73 [ 0 ] . V_17 |= V_47 ;
if ( V_41 -> V_75 == V_76 && V_41 -> V_77 == 0x0001 )
return;
F_28 ( V_41 , V_67 , & V_72 ) ;
if ( ! V_72 ) {
F_26 ( V_41 , V_67 ,
0xfff0fff0 ) ;
F_28 ( V_41 , V_67 , & V_72 ) ;
F_26 ( V_41 , V_67 , 0x0 ) ;
}
if ( V_72 ) {
V_73 [ 2 ] . V_17 |= V_52 | V_65 ;
if ( ( V_72 & V_78 ) ==
V_79 ) {
V_73 [ 2 ] . V_17 |= V_66 ;
V_73 [ 2 ] . V_17 |= V_79 ;
}
}
if ( V_73 [ 2 ] . V_17 & V_66 ) {
T_3 V_80 , V_13 ;
F_28 ( V_41 , V_68 ,
& V_80 ) ;
F_26 ( V_41 , V_68 ,
0xffffffff ) ;
F_28 ( V_41 , V_68 , & V_13 ) ;
if ( ! V_13 )
V_73 [ 2 ] . V_17 &= ~ V_66 ;
F_26 ( V_41 , V_68 ,
V_80 ) ;
}
}
static struct V_6 * F_36 ( struct V_40 * V_37 , unsigned long type )
{
int V_81 ;
struct V_6 * V_82 ;
unsigned long V_83 = V_47 | V_52 |
V_65 ;
F_37 (bus, r, i) {
if ( V_82 == & V_84 || V_82 == & V_85 )
continue;
if ( V_82 && ( V_82 -> V_17 & V_83 ) == type && ! V_82 -> V_86 )
return V_82 ;
}
return NULL ;
}
static T_1 F_38 ( T_1 V_87 ,
T_1 V_88 ,
T_1 V_89 ,
T_1 V_90 ,
T_1 V_32 )
{
if ( V_87 < V_88 )
V_87 = V_88 ;
if ( V_90 == 1 )
V_90 = 0 ;
#if F_39 ( V_91 ) || F_39 ( V_92 )
V_87 = ( V_87 & 0xff ) + ( ( V_87 & ~ 0xffUL ) << 2 ) ;
#endif
V_87 = F_40 ( V_87 + V_89 , V_32 ) ;
if ( V_87 < V_90 )
V_87 = V_90 ;
return V_87 ;
}
static T_1 F_41 ( T_1 V_87 ,
T_1 V_88 ,
T_1 V_89 ,
T_1 V_90 ,
T_1 V_32 )
{
if ( V_87 < V_88 )
V_87 = V_88 ;
if ( V_90 == 1 )
V_90 = 0 ;
if ( V_87 < V_90 )
V_87 = V_90 ;
V_87 = F_40 ( V_87 + V_89 , V_32 ) ;
return V_87 ;
}
static T_1 F_42 ( struct V_2 * V_27 ,
struct V_6 * V_7 )
{
struct V_2 * V_10 ;
for ( V_10 = V_27 -> V_12 ; V_10 && V_10 -> V_7 != V_7 ;
V_10 = V_10 -> V_12 ) ;
if ( V_10 )
return V_10 -> V_8 ;
return 0 ;
}
static void F_43 ( struct V_40 * V_37 , T_1 V_88 ,
T_1 V_8 , struct V_2 * V_27 )
{
struct V_4 * V_5 ;
struct V_6 * V_73 = F_36 ( V_37 , V_47 ) ;
unsigned long V_87 = 0 , V_93 = 0 , V_89 = 0 ;
T_1 V_94 = 0 ;
if ( ! V_73 )
return;
F_22 (dev, &bus->devices, bus_list) {
int V_81 ;
for ( V_81 = 0 ; V_81 < V_95 ; V_81 ++ ) {
struct V_6 * V_82 = & V_5 -> V_6 [ V_81 ] ;
unsigned long V_96 ;
if ( V_82 -> V_86 || ! ( V_82 -> V_17 & V_47 ) )
continue;
V_96 = F_11 ( V_82 ) ;
if ( V_96 < 0x400 )
V_87 += V_96 ;
else
V_89 += V_96 ;
if ( V_27 )
V_94 += F_42 ( V_27 , V_82 ) ;
}
}
V_93 = F_38 ( V_87 , V_88 , V_89 ,
F_11 ( V_73 ) , 4096 ) ;
if ( V_94 > V_8 )
V_8 = V_94 ;
V_89 = ( ! V_27 || ( V_27 && ! V_8 ) ) ? V_93 :
F_38 ( V_87 , V_88 + V_8 , V_89 ,
F_11 ( V_73 ) , 4096 ) ;
if ( ! V_93 && ! V_89 ) {
if ( V_73 -> V_15 || V_73 -> V_16 )
F_24 ( & V_37 -> V_42 -> V_5 , L_6
L_7 , V_73 ,
V_37 -> V_45 , V_37 -> V_46 ) ;
V_73 -> V_17 = 0 ;
return;
}
V_73 -> V_15 = 4096 ;
V_73 -> V_16 = V_73 -> V_15 + V_93 - 1 ;
V_73 -> V_17 |= V_33 ;
if ( V_89 > V_93 && V_27 )
F_2 ( V_27 , V_37 -> V_42 , V_73 , V_89 - V_93 , 4096 ) ;
}
static int F_44 ( struct V_40 * V_37 , unsigned long V_97 ,
unsigned long type , T_1 V_88 ,
T_1 V_8 ,
struct V_2 * V_27 )
{
struct V_4 * V_5 ;
T_1 V_9 , V_32 , V_87 , V_93 , V_89 ;
T_1 V_98 [ 12 ] ;
int V_99 , V_100 ;
struct V_6 * V_73 = F_36 ( V_37 , type ) ;
unsigned int V_101 = 0 ;
T_1 V_94 = 0 ;
if ( ! V_73 )
return 0 ;
memset ( V_98 , 0 , sizeof( V_98 ) ) ;
V_100 = 0 ;
V_87 = 0 ;
V_101 = V_73 -> V_17 & V_66 ;
V_73 -> V_17 &= ~ V_66 ;
F_22 (dev, &bus->devices, bus_list) {
int V_81 ;
for ( V_81 = 0 ; V_81 < V_95 ; V_81 ++ ) {
struct V_6 * V_82 = & V_5 -> V_6 [ V_81 ] ;
T_1 V_96 ;
if ( V_82 -> V_86 || ( V_82 -> V_17 & V_97 ) != type )
continue;
V_96 = F_11 ( V_82 ) ;
#ifdef F_45
if ( V_27 && V_81 >= V_102 &&
V_81 <= V_103 ) {
V_82 -> V_16 = V_82 -> V_15 - 1 ;
F_2 ( V_27 , V_5 , V_82 , V_96 , 0 ) ;
V_94 += V_96 ;
continue;
}
#endif
V_32 = F_46 ( V_5 , V_82 ) ;
V_99 = F_47 ( V_32 ) - 20 ;
if ( V_99 > 11 ) {
F_48 ( & V_5 -> V_5 , L_8
L_9 , V_81 , V_82 ,
( unsigned long long ) V_32 ) ;
V_82 -> V_17 = 0 ;
continue;
}
V_87 += V_96 ;
if ( V_99 < 0 )
V_99 = 0 ;
if ( V_96 == V_32 )
V_98 [ V_99 ] += V_32 ;
if ( V_99 > V_100 )
V_100 = V_99 ;
V_101 &= V_82 -> V_17 & V_66 ;
if ( V_27 )
V_94 += F_42 ( V_27 , V_82 ) ;
}
}
V_32 = 0 ;
V_9 = 0 ;
for ( V_99 = 0 ; V_99 <= V_100 ; V_99 ++ ) {
T_1 V_104 = 1 ;
V_104 <<= ( V_99 + 20 ) ;
if ( ! V_32 )
V_9 = V_104 ;
else if ( F_40 ( V_32 + V_9 , V_9 ) < V_104 )
V_9 = V_104 >> 1 ;
V_32 += V_98 [ V_99 ] ;
}
V_93 = F_41 ( V_87 , V_88 , 0 , F_11 ( V_73 ) , V_9 ) ;
if ( V_94 > V_8 )
V_8 = V_94 ;
V_89 = ( ! V_27 || ( V_27 && ! V_8 ) ) ? V_93 :
F_41 ( V_87 , V_88 + V_8 , 0 ,
F_11 ( V_73 ) , V_9 ) ;
if ( ! V_93 && ! V_89 ) {
if ( V_73 -> V_15 || V_73 -> V_16 )
F_24 ( & V_37 -> V_42 -> V_5 , L_6
L_7 , V_73 ,
V_37 -> V_45 , V_37 -> V_46 ) ;
V_73 -> V_17 = 0 ;
return 1 ;
}
V_73 -> V_15 = V_9 ;
V_73 -> V_16 = V_93 + V_9 - 1 ;
V_73 -> V_17 |= V_33 | V_101 ;
if ( V_89 > V_93 && V_27 )
F_2 ( V_27 , V_37 -> V_42 , V_73 , V_89 - V_93 , V_9 ) ;
return 1 ;
}
unsigned long F_49 ( struct V_6 * V_7 )
{
if ( V_7 -> V_17 & V_47 )
return V_105 ;
if ( V_7 -> V_17 & V_52 )
return V_106 ;
return 0 ;
}
static void F_50 ( struct V_40 * V_37 ,
struct V_2 * V_27 )
{
struct V_4 * V_41 = V_37 -> V_42 ;
struct V_6 * V_73 = & V_41 -> V_6 [ V_74 ] ;
T_2 V_107 ;
V_73 [ 0 ] . V_15 = 0 ;
V_73 [ 0 ] . V_17 |= V_47 | V_34 ;
if ( V_27 )
F_2 ( V_27 , V_41 , V_73 , V_105 , 0 ) ;
V_73 [ 1 ] . V_15 = 0 ;
V_73 [ 1 ] . V_17 |= V_47 | V_34 ;
if ( V_27 )
F_2 ( V_27 , V_41 , V_73 + 1 , V_105 , 0 ) ;
F_7 ( V_41 , V_108 , & V_107 ) ;
if ( ! ( V_107 & V_109 ) ) {
V_107 |= V_109 ;
F_33 ( V_41 , V_108 , V_107 ) ;
F_7 ( V_41 , V_108 , & V_107 ) ;
}
if ( V_107 & V_109 ) {
V_73 [ 2 ] . V_15 = 0 ;
V_73 [ 2 ] . V_17 |= V_52 | V_65 | V_34 ;
if ( V_27 )
F_2 ( V_27 , V_41 , V_73 + 2 , V_106 , 0 ) ;
V_73 [ 3 ] . V_15 = 0 ;
V_73 [ 3 ] . V_17 |= V_52 | V_34 ;
if ( V_27 )
F_2 ( V_27 , V_41 , V_73 + 3 , V_106 , 0 ) ;
} else {
V_73 [ 3 ] . V_15 = 0 ;
V_73 [ 3 ] . V_17 |= V_52 | V_34 ;
if ( V_27 )
F_2 ( V_27 , V_41 , V_73 + 3 , V_106 * 2 , 0 ) ;
}
V_73 [ 0 ] . V_15 = V_73 [ 1 ] . V_15 = V_73 [ 2 ] . V_15 = V_73 [ 3 ] . V_15 = 1 ;
V_73 [ 0 ] . V_16 = V_73 [ 1 ] . V_16 = V_73 [ 2 ] . V_16 = V_73 [ 3 ] . V_16 = 0 ;
}
void T_4 F_51 ( struct V_40 * V_37 ,
struct V_2 * V_27 )
{
struct V_4 * V_5 ;
unsigned long V_97 , V_110 ;
T_1 V_111 = 0 , V_112 = 0 ;
F_22 (dev, &bus->devices, bus_list) {
struct V_40 * V_113 = V_5 -> V_46 ;
if ( ! V_113 )
continue;
switch ( V_5 -> V_19 >> 8 ) {
case V_114 :
F_50 ( V_113 , V_27 ) ;
break;
case V_115 :
default:
F_51 ( V_113 , V_27 ) ;
break;
}
}
if ( ! V_37 -> V_42 )
return;
switch ( V_37 -> V_42 -> V_19 >> 8 ) {
case V_114 :
break;
case V_115 :
F_35 ( V_37 ) ;
if ( V_37 -> V_42 -> V_116 ) {
V_112 = V_117 ;
V_111 = V_118 ;
}
default:
F_43 ( V_37 , 0 , V_112 , V_27 ) ;
V_97 = V_52 ;
V_110 = V_52 | V_65 ;
if ( F_44 ( V_37 , V_110 , V_110 , 0 , V_111 , V_27 ) )
V_97 = V_110 ;
else
V_111 += V_111 ;
F_44 ( V_37 , V_97 , V_52 , 0 , V_111 , V_27 ) ;
break;
}
}
void T_4 F_52 ( struct V_40 * V_37 )
{
F_51 ( V_37 , NULL ) ;
}
static void T_4 F_53 ( const struct V_40 * V_37 ,
struct V_2 * V_27 ,
struct V_2 * V_36 )
{
struct V_40 * V_113 ;
struct V_4 * V_5 ;
F_21 ( V_37 , V_27 , V_36 ) ;
F_22 (dev, &bus->devices, bus_list) {
V_113 = V_5 -> V_46 ;
if ( ! V_113 )
continue;
F_53 ( V_113 , V_27 , V_36 ) ;
switch ( V_5 -> V_19 >> 8 ) {
case V_115 :
if ( ! F_54 ( V_5 ) )
F_34 ( V_113 ) ;
break;
case V_114 :
F_23 ( V_113 ) ;
break;
default:
F_24 ( & V_5 -> V_5 , L_10
L_11 , F_55 ( V_113 ) , V_113 -> V_119 ) ;
break;
}
}
}
void T_4 F_56 ( const struct V_40 * V_37 )
{
F_53 ( V_37 , NULL , NULL ) ;
}
static void T_4 F_57 ( const struct V_4 * V_41 ,
struct V_2 * V_36 )
{
struct V_40 * V_113 ;
F_20 ( (struct V_4 * ) V_41 , V_36 ) ;
V_113 = V_41 -> V_46 ;
if ( ! V_113 )
return;
F_53 ( V_113 , NULL , V_36 ) ;
switch ( V_41 -> V_19 >> 8 ) {
case V_115 :
F_34 ( V_113 ) ;
break;
case V_114 :
F_23 ( V_113 ) ;
break;
default:
F_24 ( & V_41 -> V_5 , L_10
L_11 , F_55 ( V_113 ) , V_113 -> V_119 ) ;
break;
}
}
static void F_58 ( struct V_40 * V_37 ,
unsigned long type )
{
int V_30 ;
bool V_120 = false ;
struct V_4 * V_5 ;
struct V_6 * V_82 ;
unsigned long V_83 = V_47 | V_52 |
V_65 ;
V_5 = V_37 -> V_42 ;
for ( V_30 = V_74 ; V_30 <= V_121 ;
V_30 ++ ) {
V_82 = & V_5 -> V_6 [ V_30 ] ;
if ( ( V_82 -> V_17 & V_83 ) != type )
continue;
if ( ! V_82 -> V_86 )
continue;
F_59 ( V_82 ) ;
if ( ! F_60 ( V_82 ) ) {
F_14 ( V_35 , & V_5 -> V_5 ,
L_12 , V_30 , V_82 ) ;
V_82 -> V_16 = F_11 ( V_82 ) - 1 ;
V_82 -> V_15 = 0 ;
V_82 -> V_17 = 0 ;
V_120 = true ;
}
}
if ( V_120 ) {
if ( type & V_65 )
type = V_65 ;
F_32 ( V_37 , type ) ;
}
}
static void T_4 F_61 ( struct V_40 * V_37 ,
unsigned long type ,
enum V_122 V_123 )
{
struct V_4 * V_5 ;
bool V_124 = true ;
F_22 (dev, &bus->devices, bus_list) {
struct V_40 * V_113 = V_5 -> V_46 ;
if ( ! V_113 )
continue;
V_124 = false ;
if ( ( V_5 -> V_19 >> 8 ) != V_115 )
continue;
if ( V_123 == V_125 )
F_61 ( V_113 , type ,
V_125 ) ;
}
if ( F_17 ( V_37 ) )
return;
if ( ( V_37 -> V_42 -> V_19 >> 8 ) != V_115 )
return;
if ( ( V_123 == V_125 ) || V_124 )
F_58 ( V_37 , type ) ;
}
static void F_62 ( struct V_40 * V_37 )
{
struct V_6 * V_7 ;
int V_81 ;
F_37 (bus, res, i) {
if ( ! V_7 || ! V_7 -> V_16 || ! V_7 -> V_17 )
continue;
F_14 ( V_35 , & V_37 -> V_5 , L_13 , V_81 , V_7 ) ;
}
}
static void F_63 ( struct V_40 * V_37 )
{
struct V_40 * V_113 ;
struct V_4 * V_5 ;
F_62 ( V_37 ) ;
F_22 (dev, &bus->devices, bus_list) {
V_113 = V_5 -> V_46 ;
if ( ! V_113 )
continue;
F_63 ( V_113 ) ;
}
}
static int T_5 F_64 ( struct V_40 * V_37 )
{
int V_126 = 0 ;
struct V_4 * V_5 ;
F_22 (dev, &bus->devices, bus_list) {
int V_127 ;
struct V_40 * V_113 = V_5 -> V_46 ;
if ( ! V_113 )
continue;
V_127 = F_64 ( V_113 ) ;
if ( V_127 + 1 > V_126 )
V_126 = V_127 + 1 ;
}
return V_126 ;
}
static int T_5 F_65 ( void )
{
int V_126 = 0 ;
struct V_40 * V_37 ;
F_22 (bus, &pci_root_buses, node) {
int V_127 ;
V_127 = F_64 ( V_37 ) ;
if ( V_127 > V_126 )
V_126 = V_127 ;
}
return V_126 ;
}
void T_5
F_66 ( void )
{
struct V_40 * V_37 ;
struct V_2 V_128 ;
int V_129 = 0 ;
enum V_122 V_123 = V_130 ;
struct V_2 V_3 , * V_10 ;
unsigned long V_83 = V_47 | V_52 |
V_65 ;
unsigned long V_131 ;
int V_132 = F_65 () ;
int V_133 ;
V_3 . V_12 = NULL ;
V_128 . V_12 = NULL ;
V_133 = V_132 + 1 ;
F_67 ( V_35 L_14 ,
V_132 , V_133 ) ;
V_134:
F_22 (bus, &pci_root_buses, node)
F_51 ( V_37 , & V_128 ) ;
F_22 (bus, &pci_root_buses, node)
F_53 ( V_37 , & V_128 , & V_3 ) ;
F_68 ( V_128 . V_12 ) ;
V_129 ++ ;
if ( ! V_3 . V_12 )
goto V_135;
if ( ! F_69 () ) {
F_19 ( V_2 , & V_3 ) ;
goto V_135;
}
V_131 = 0 ;
for ( V_10 = V_3 . V_12 ; V_10 ; ) {
V_131 |= V_10 -> V_17 ;
V_10 = V_10 -> V_12 ;
}
V_131 &= V_83 ;
if ( ( V_131 == V_47 ) || ( V_129 >= V_133 ) ) {
F_19 ( V_2 , & V_3 ) ;
goto V_135;
}
F_67 ( V_35 L_15 ,
V_129 + 1 ) ;
if ( ( V_129 + 1 ) > 2 )
V_123 = V_125 ;
for ( V_10 = V_3 . V_12 ; V_10 ; ) {
V_37 = V_10 -> V_5 -> V_37 ;
F_61 ( V_37 , V_10 -> V_17 & V_83 ,
V_123 ) ;
V_10 = V_10 -> V_12 ;
}
for ( V_10 = V_3 . V_12 ; V_10 ; ) {
struct V_6 * V_7 = V_10 -> V_7 ;
V_7 -> V_15 = V_10 -> V_15 ;
V_7 -> V_16 = V_10 -> V_16 ;
V_7 -> V_17 = V_10 -> V_17 ;
if ( V_10 -> V_5 -> V_46 )
V_7 -> V_17 = 0 ;
V_10 = V_10 -> V_12 ;
}
F_19 ( V_2 , & V_3 ) ;
goto V_134;
V_135:
F_22 (bus, &pci_root_buses, node)
F_70 ( V_37 ) ;
F_22 (bus, &pci_root_buses, node)
F_63 ( V_37 ) ;
}
void F_71 ( struct V_4 * V_41 )
{
struct V_40 * V_86 = V_41 -> V_46 ;
int V_129 = 0 ;
struct V_2 V_3 , * V_10 ;
int V_136 ;
unsigned long V_83 = V_47 | V_52 |
V_65 ;
V_3 . V_12 = NULL ;
V_134:
F_52 ( V_86 ) ;
F_57 ( V_41 , & V_3 ) ;
V_129 ++ ;
if ( ! V_3 . V_12 )
goto V_137;
if ( V_129 >= 2 ) {
F_19 ( V_2 , & V_3 ) ;
goto V_137;
}
F_67 ( V_35 L_15 ,
V_129 + 1 ) ;
for ( V_10 = V_3 . V_12 ; V_10 ; ) {
struct V_40 * V_37 = V_10 -> V_5 -> V_37 ;
unsigned long V_17 = V_10 -> V_17 ;
F_61 ( V_37 , V_17 & V_83 ,
V_125 ) ;
V_10 = V_10 -> V_12 ;
}
for ( V_10 = V_3 . V_12 ; V_10 ; ) {
struct V_6 * V_7 = V_10 -> V_7 ;
V_7 -> V_15 = V_10 -> V_15 ;
V_7 -> V_16 = V_10 -> V_16 ;
V_7 -> V_17 = V_10 -> V_17 ;
if ( V_10 -> V_5 -> V_46 )
V_7 -> V_17 = 0 ;
V_10 = V_10 -> V_12 ;
}
F_19 ( V_2 , & V_3 ) ;
goto V_134;
V_137:
V_136 = F_72 ( V_41 ) ;
F_73 ( V_41 ) ;
F_70 ( V_86 ) ;
}
