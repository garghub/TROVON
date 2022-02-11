void F_1 ( void )
{
V_1 = 1 ;
}
static void F_2 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
T_1 V_8 )
{
struct V_2 * V_9 = V_3 ;
struct V_2 * V_10 = V_9 -> V_11 ;
struct V_2 * V_12 ;
V_12 = F_3 ( sizeof( * V_12 ) , V_13 ) ;
if ( ! V_12 ) {
F_4 ( L_1 ) ;
return;
}
V_12 -> V_11 = V_10 ;
V_12 -> V_7 = V_7 ;
V_12 -> V_5 = V_5 ;
V_12 -> V_14 = V_7 -> V_14 ;
V_12 -> V_15 = V_7 -> V_15 ;
V_12 -> V_16 = V_7 -> V_16 ;
V_12 -> V_8 = V_8 ;
V_9 -> V_11 = V_12 ;
}
static void F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
F_2 ( V_3 , V_5 , V_7 , 0 ) ;
}
static void F_6 ( struct V_4 * V_5 ,
struct V_17 * V_3 )
{
T_2 V_18 = V_5 -> V_18 >> 8 ;
if ( V_18 == V_19 || V_18 == V_20 )
return;
if ( V_18 == V_21 ) {
T_2 V_22 ;
F_7 ( V_5 , V_23 , & V_22 ) ;
if ( V_22 & ( V_24 | V_25 ) )
return;
}
F_8 ( V_5 , V_3 ) ;
}
static inline void F_9 ( struct V_6 * V_7 )
{
V_7 -> V_14 = 0 ;
V_7 -> V_15 = 0 ;
V_7 -> V_16 = 0 ;
}
static void F_10 ( struct V_2 * V_26 ,
struct V_17 * V_3 )
{
struct V_6 * V_7 ;
struct V_2 * V_9 , * V_12 , * V_27 ;
struct V_17 * V_28 ;
T_1 V_8 ;
int V_29 ;
V_27 = V_26 ;
for ( V_9 = V_26 -> V_11 ; V_9 ; ) {
V_7 = V_9 -> V_7 ;
if ( ! V_7 -> V_16 )
goto V_30;
for ( V_28 = V_3 -> V_11 ; V_28 && V_28 -> V_7 != V_7 ;
V_28 = V_28 -> V_11 ) ;
if ( ! V_28 ) {
V_27 = V_9 ;
V_9 = V_9 -> V_11 ;
continue;
}
V_29 = V_7 - & V_9 -> V_5 -> V_6 [ 0 ] ;
V_8 = V_9 -> V_8 ;
if ( ! F_11 ( V_7 ) && V_8 ) {
V_7 -> V_15 = V_7 -> V_14 + V_8 - 1 ;
if( F_12 ( V_9 -> V_5 , V_29 ) )
F_9 ( V_7 ) ;
} else if ( V_8 ) {
F_13 ( V_7 , V_7 -> V_14 ,
F_11 ( V_7 ) + V_8 ) ;
}
V_30:
V_12 = V_9 ;
V_27 -> V_11 = V_9 = V_9 -> V_11 ;
F_14 ( V_12 ) ;
}
}
static void F_15 ( struct V_17 * V_3 ,
struct V_2 * V_31 )
{
struct V_6 * V_7 ;
struct V_17 * V_9 ;
int V_29 ;
for ( V_9 = V_3 -> V_11 ; V_9 ; V_9 = V_9 -> V_11 ) {
V_7 = V_9 -> V_7 ;
V_29 = V_7 - & V_9 -> V_5 -> V_6 [ 0 ] ;
if ( F_11 ( V_7 ) && F_12 ( V_9 -> V_5 , V_29 ) ) {
if ( V_31 && ! F_16 ( V_9 -> V_5 -> V_32 ) ) {
if ( ! ( ( V_29 == V_33 ) &&
( ! ( V_7 -> V_16 & V_34 ) ) ) )
F_5 ( V_31 , V_9 -> V_5 , V_7 ) ;
}
F_9 ( V_7 ) ;
}
}
}
static void F_17 ( struct V_17 * V_3 ,
struct V_2 * V_26 ,
struct V_2 * V_31 )
{
F_15 ( V_3 , V_31 ) ;
if ( V_26 )
F_10 ( V_26 , V_3 ) ;
F_18 ( V_17 , V_3 ) ;
}
static void F_19 ( struct V_4 * V_5 ,
struct V_2 * V_31 )
{
struct V_17 V_3 ;
V_3 . V_11 = NULL ;
F_6 ( V_5 , & V_3 ) ;
F_17 ( & V_3 , NULL , V_31 ) ;
}
static void F_20 ( const struct V_35 * V_32 ,
struct V_2 * V_26 ,
struct V_2 * V_31 )
{
struct V_4 * V_5 ;
struct V_17 V_3 ;
V_3 . V_11 = NULL ;
F_21 (dev, &bus->devices, bus_list)
F_6 ( V_5 , & V_3 ) ;
F_17 ( & V_3 , V_26 , V_31 ) ;
}
void F_22 ( struct V_35 * V_32 )
{
struct V_4 * V_36 = V_32 -> V_37 ;
struct V_6 * V_7 ;
struct V_38 V_39 ;
F_23 ( & V_36 -> V_5 , L_2 ,
V_32 -> V_40 , V_32 -> V_41 ) ;
V_7 = V_32 -> V_6 [ 0 ] ;
F_24 ( V_36 , & V_39 , V_7 ) ;
if ( V_7 -> V_16 & V_42 ) {
F_23 ( & V_36 -> V_5 , L_3 , V_7 ) ;
F_25 ( V_36 , V_43 ,
V_39 . V_14 ) ;
F_25 ( V_36 , V_44 ,
V_39 . V_15 ) ;
}
V_7 = V_32 -> V_6 [ 1 ] ;
F_24 ( V_36 , & V_39 , V_7 ) ;
if ( V_7 -> V_16 & V_42 ) {
F_23 ( & V_36 -> V_5 , L_3 , V_7 ) ;
F_25 ( V_36 , V_45 ,
V_39 . V_14 ) ;
F_25 ( V_36 , V_46 ,
V_39 . V_15 ) ;
}
V_7 = V_32 -> V_6 [ 2 ] ;
F_24 ( V_36 , & V_39 , V_7 ) ;
if ( V_7 -> V_16 & V_47 ) {
F_23 ( & V_36 -> V_5 , L_3 , V_7 ) ;
F_25 ( V_36 , V_48 ,
V_39 . V_14 ) ;
F_25 ( V_36 , V_49 ,
V_39 . V_15 ) ;
}
V_7 = V_32 -> V_6 [ 3 ] ;
F_24 ( V_36 , & V_39 , V_7 ) ;
if ( V_7 -> V_16 & V_47 ) {
F_23 ( & V_36 -> V_5 , L_3 , V_7 ) ;
F_25 ( V_36 , V_50 ,
V_39 . V_14 ) ;
F_25 ( V_36 , V_51 ,
V_39 . V_15 ) ;
}
}
static void F_26 ( struct V_35 * V_32 )
{
struct V_4 * V_36 = V_32 -> V_37 ;
struct V_6 * V_7 ;
struct V_38 V_39 ;
T_3 V_52 , V_53 ;
V_7 = V_32 -> V_6 [ 0 ] ;
F_24 ( V_36 , & V_39 , V_7 ) ;
if ( V_7 -> V_16 & V_42 ) {
F_27 ( V_36 , V_54 , & V_52 ) ;
V_52 &= 0xffff0000 ;
V_52 |= ( V_39 . V_14 >> 8 ) & 0x00f0 ;
V_52 |= V_39 . V_15 & 0xf000 ;
V_53 = ( V_39 . V_15 & 0xffff0000 ) | ( V_39 . V_14 >> 16 ) ;
F_23 ( & V_36 -> V_5 , L_3 , V_7 ) ;
} else {
V_53 = 0 ;
V_52 = 0x00f0 ;
F_23 ( & V_36 -> V_5 , L_4 ) ;
}
F_25 ( V_36 , V_55 , 0x0000ffff ) ;
F_25 ( V_36 , V_54 , V_52 ) ;
F_25 ( V_36 , V_55 , V_53 ) ;
}
static void F_28 ( struct V_35 * V_32 )
{
struct V_4 * V_36 = V_32 -> V_37 ;
struct V_6 * V_7 ;
struct V_38 V_39 ;
T_3 V_52 ;
V_7 = V_32 -> V_6 [ 1 ] ;
F_24 ( V_36 , & V_39 , V_7 ) ;
if ( V_7 -> V_16 & V_47 ) {
V_52 = ( V_39 . V_14 >> 16 ) & 0xfff0 ;
V_52 |= V_39 . V_15 & 0xfff00000 ;
F_23 ( & V_36 -> V_5 , L_3 , V_7 ) ;
} else {
V_52 = 0x0000fff0 ;
F_23 ( & V_36 -> V_5 , L_5 ) ;
}
F_25 ( V_36 , V_56 , V_52 ) ;
}
static void F_29 ( struct V_35 * V_32 )
{
struct V_4 * V_36 = V_32 -> V_37 ;
struct V_6 * V_7 ;
struct V_38 V_39 ;
T_3 V_52 , V_57 , V_58 ;
F_25 ( V_36 , V_59 , 0 ) ;
V_57 = V_58 = 0 ;
V_7 = V_32 -> V_6 [ 2 ] ;
F_24 ( V_36 , & V_39 , V_7 ) ;
if ( V_7 -> V_16 & V_60 ) {
V_52 = ( V_39 . V_14 >> 16 ) & 0xfff0 ;
V_52 |= V_39 . V_15 & 0xfff00000 ;
if ( V_7 -> V_16 & V_61 ) {
V_57 = F_30 ( V_39 . V_14 ) ;
V_58 = F_30 ( V_39 . V_15 ) ;
}
F_23 ( & V_36 -> V_5 , L_3 , V_7 ) ;
} else {
V_52 = 0x0000fff0 ;
F_23 ( & V_36 -> V_5 , L_6 ) ;
}
F_25 ( V_36 , V_62 , V_52 ) ;
F_25 ( V_36 , V_63 , V_57 ) ;
F_25 ( V_36 , V_59 , V_58 ) ;
}
static void F_31 ( struct V_35 * V_32 , unsigned long type )
{
struct V_4 * V_36 = V_32 -> V_37 ;
F_23 ( & V_36 -> V_5 , L_7 ,
V_32 -> V_40 , V_32 -> V_41 ) ;
if ( type & V_42 )
F_26 ( V_32 ) ;
if ( type & V_47 )
F_28 ( V_32 ) ;
if ( type & V_60 )
F_29 ( V_32 ) ;
F_32 ( V_36 , V_64 , V_32 -> V_65 ) ;
}
static void F_33 ( struct V_35 * V_32 )
{
unsigned long type = V_42 | V_47 |
V_60 ;
F_31 ( V_32 , type ) ;
}
static void F_34 ( struct V_35 * V_32 )
{
T_2 V_66 ;
T_3 V_67 ;
struct V_4 * V_36 = V_32 -> V_37 ;
struct V_6 * V_68 ;
V_68 = & V_36 -> V_6 [ V_69 ] ;
V_68 [ 1 ] . V_16 |= V_47 ;
F_7 ( V_36 , V_54 , & V_66 ) ;
if ( ! V_66 ) {
F_32 ( V_36 , V_54 , 0xf0f0 ) ;
F_7 ( V_36 , V_54 , & V_66 ) ;
F_32 ( V_36 , V_54 , 0x0 ) ;
}
if ( V_66 )
V_68 [ 0 ] . V_16 |= V_42 ;
if ( V_36 -> V_70 == V_71 && V_36 -> V_72 == 0x0001 )
return;
F_27 ( V_36 , V_62 , & V_67 ) ;
if ( ! V_67 ) {
F_25 ( V_36 , V_62 ,
0xfff0fff0 ) ;
F_27 ( V_36 , V_62 , & V_67 ) ;
F_25 ( V_36 , V_62 , 0x0 ) ;
}
if ( V_67 ) {
V_68 [ 2 ] . V_16 |= V_47 | V_60 ;
if ( ( V_67 & V_73 ) ==
V_74 ) {
V_68 [ 2 ] . V_16 |= V_61 ;
V_68 [ 2 ] . V_16 |= V_74 ;
}
}
if ( V_68 [ 2 ] . V_16 & V_61 ) {
T_3 V_75 , V_12 ;
F_27 ( V_36 , V_63 ,
& V_75 ) ;
F_25 ( V_36 , V_63 ,
0xffffffff ) ;
F_27 ( V_36 , V_63 , & V_12 ) ;
if ( ! V_12 )
V_68 [ 2 ] . V_16 &= ~ V_61 ;
F_25 ( V_36 , V_63 ,
V_75 ) ;
}
}
static struct V_6 * F_35 ( struct V_35 * V_32 , unsigned long type )
{
int V_76 ;
struct V_6 * V_77 ;
unsigned long V_78 = V_42 | V_47 |
V_60 ;
F_36 (bus, r, i) {
if ( V_77 == & V_79 || V_77 == & V_80 )
continue;
if ( V_77 && ( V_77 -> V_16 & V_78 ) == type && ! V_77 -> V_81 )
return V_77 ;
}
return NULL ;
}
static T_1 F_37 ( T_1 V_82 ,
T_1 V_83 ,
T_1 V_84 ,
T_1 V_85 ,
T_1 V_86 )
{
if ( V_82 < V_83 )
V_82 = V_83 ;
if ( V_85 == 1 )
V_85 = 0 ;
#if F_38 ( V_87 ) || F_38 ( V_88 )
V_82 = ( V_82 & 0xff ) + ( ( V_82 & ~ 0xffUL ) << 2 ) ;
#endif
V_82 = F_39 ( V_82 + V_84 , V_86 ) ;
if ( V_82 < V_85 )
V_82 = V_85 ;
return V_82 ;
}
static T_1 F_40 ( T_1 V_82 ,
T_1 V_83 ,
T_1 V_84 ,
T_1 V_85 ,
T_1 V_86 )
{
if ( V_82 < V_83 )
V_82 = V_83 ;
if ( V_85 == 1 )
V_85 = 0 ;
if ( V_82 < V_85 )
V_82 = V_85 ;
V_82 = F_39 ( V_82 + V_84 , V_86 ) ;
return V_82 ;
}
static void F_41 ( struct V_35 * V_32 , T_1 V_83 ,
T_1 V_8 , struct V_2 * V_26 )
{
struct V_4 * V_5 ;
struct V_6 * V_68 = F_35 ( V_32 , V_42 ) ;
unsigned long V_82 = 0 , V_89 = 0 , V_84 = 0 ;
if ( ! V_68 )
return;
F_21 (dev, &bus->devices, bus_list) {
int V_76 ;
for ( V_76 = 0 ; V_76 < V_90 ; V_76 ++ ) {
struct V_6 * V_77 = & V_5 -> V_6 [ V_76 ] ;
unsigned long V_91 ;
if ( V_77 -> V_81 || ! ( V_77 -> V_16 & V_42 ) )
continue;
V_91 = F_11 ( V_77 ) ;
if ( V_91 < 0x400 )
V_82 += V_91 ;
else
V_84 += V_91 ;
}
}
V_89 = F_37 ( V_82 , V_83 , V_84 ,
F_11 ( V_68 ) , 4096 ) ;
V_84 = ( ! V_26 || ( V_26 && ! V_8 ) ) ? V_89 :
F_37 ( V_82 , V_83 + V_8 , V_84 ,
F_11 ( V_68 ) , 4096 ) ;
if ( ! V_89 && ! V_84 ) {
if ( V_68 -> V_14 || V_68 -> V_15 )
F_23 ( & V_32 -> V_37 -> V_5 , L_8
L_9 , V_68 ,
V_32 -> V_40 , V_32 -> V_41 ) ;
V_68 -> V_16 = 0 ;
return;
}
V_68 -> V_14 = 4096 ;
V_68 -> V_15 = V_68 -> V_14 + V_89 - 1 ;
V_68 -> V_16 |= V_92 ;
if ( V_84 > V_89 && V_26 )
F_2 ( V_26 , V_32 -> V_37 , V_68 , V_84 - V_89 ) ;
}
static int F_42 ( struct V_35 * V_32 , unsigned long V_93 ,
unsigned long type , T_1 V_83 ,
T_1 V_8 ,
struct V_2 * V_26 )
{
struct V_4 * V_5 ;
T_1 V_94 , V_86 , V_82 , V_89 , V_84 ;
T_1 V_95 [ 12 ] ;
int V_96 , V_97 ;
struct V_6 * V_68 = F_35 ( V_32 , type ) ;
unsigned int V_98 = 0 ;
if ( ! V_68 )
return 0 ;
memset ( V_95 , 0 , sizeof( V_95 ) ) ;
V_97 = 0 ;
V_82 = 0 ;
V_98 = V_68 -> V_16 & V_61 ;
V_68 -> V_16 &= ~ V_61 ;
F_21 (dev, &bus->devices, bus_list) {
int V_76 ;
for ( V_76 = 0 ; V_76 < V_90 ; V_76 ++ ) {
struct V_6 * V_77 = & V_5 -> V_6 [ V_76 ] ;
T_1 V_91 ;
if ( V_77 -> V_81 || ( V_77 -> V_16 & V_93 ) != type )
continue;
V_91 = F_11 ( V_77 ) ;
V_86 = F_43 ( V_5 , V_77 ) ;
V_96 = F_44 ( V_86 ) - 20 ;
if ( V_96 > 11 ) {
F_45 ( & V_5 -> V_5 , L_10
L_11 , V_76 , V_77 ,
( unsigned long long ) V_86 ) ;
V_77 -> V_16 = 0 ;
continue;
}
V_82 += V_91 ;
if ( V_96 < 0 )
V_96 = 0 ;
if ( V_91 == V_86 )
V_95 [ V_96 ] += V_86 ;
if ( V_96 > V_97 )
V_97 = V_96 ;
V_98 &= V_77 -> V_16 & V_61 ;
}
}
V_86 = 0 ;
V_94 = 0 ;
for ( V_96 = 0 ; V_96 <= V_97 ; V_96 ++ ) {
T_1 V_99 = 1 ;
V_99 <<= ( V_96 + 20 ) ;
if ( ! V_86 )
V_94 = V_99 ;
else if ( F_39 ( V_86 + V_94 , V_94 ) < V_99 )
V_94 = V_99 >> 1 ;
V_86 += V_95 [ V_96 ] ;
}
V_89 = F_40 ( V_82 , V_83 , 0 , F_11 ( V_68 ) , V_94 ) ;
V_84 = ( ! V_26 || ( V_26 && ! V_8 ) ) ? V_89 :
F_40 ( V_82 , V_83 + V_8 , 0 ,
F_11 ( V_68 ) , V_94 ) ;
if ( ! V_89 && ! V_84 ) {
if ( V_68 -> V_14 || V_68 -> V_15 )
F_23 ( & V_32 -> V_37 -> V_5 , L_8
L_9 , V_68 ,
V_32 -> V_40 , V_32 -> V_41 ) ;
V_68 -> V_16 = 0 ;
return 1 ;
}
V_68 -> V_14 = V_94 ;
V_68 -> V_15 = V_89 + V_94 - 1 ;
V_68 -> V_16 |= V_92 | V_98 ;
if ( V_84 > V_89 && V_26 )
F_2 ( V_26 , V_32 -> V_37 , V_68 , V_84 - V_89 ) ;
return 1 ;
}
static void F_46 ( struct V_35 * V_32 )
{
struct V_4 * V_36 = V_32 -> V_37 ;
struct V_6 * V_68 = & V_36 -> V_6 [ V_69 ] ;
T_2 V_100 ;
V_68 [ 0 ] . V_14 = 0 ;
V_68 [ 0 ] . V_15 = V_101 - 1 ;
V_68 [ 0 ] . V_16 |= V_42 | V_102 ;
V_68 [ 1 ] . V_14 = 0 ;
V_68 [ 1 ] . V_15 = V_101 - 1 ;
V_68 [ 1 ] . V_16 |= V_42 | V_102 ;
F_7 ( V_36 , V_103 , & V_100 ) ;
if ( ! ( V_100 & V_104 ) ) {
V_100 |= V_104 ;
F_32 ( V_36 , V_103 , V_100 ) ;
F_7 ( V_36 , V_103 , & V_100 ) ;
}
if ( V_100 & V_104 ) {
V_68 [ 2 ] . V_14 = 0 ;
V_68 [ 2 ] . V_15 = V_105 - 1 ;
V_68 [ 2 ] . V_16 |= V_47 | V_60 | V_102 ;
V_68 [ 3 ] . V_14 = 0 ;
V_68 [ 3 ] . V_15 = V_105 - 1 ;
V_68 [ 3 ] . V_16 |= V_47 | V_102 ;
} else {
V_68 [ 3 ] . V_14 = 0 ;
V_68 [ 3 ] . V_15 = V_105 * 2 - 1 ;
V_68 [ 3 ] . V_16 |= V_47 | V_102 ;
}
}
void T_4 F_47 ( struct V_35 * V_32 ,
struct V_2 * V_26 )
{
struct V_4 * V_5 ;
unsigned long V_93 , V_106 ;
T_1 V_107 = 0 , V_108 = 0 ;
F_21 (dev, &bus->devices, bus_list) {
struct V_35 * V_109 = V_5 -> V_41 ;
if ( ! V_109 )
continue;
switch ( V_5 -> V_18 >> 8 ) {
case V_110 :
F_46 ( V_109 ) ;
break;
case V_111 :
default:
F_47 ( V_109 , V_26 ) ;
break;
}
}
if ( ! V_32 -> V_37 )
return;
switch ( V_32 -> V_37 -> V_18 >> 8 ) {
case V_110 :
break;
case V_111 :
F_34 ( V_32 ) ;
if ( V_32 -> V_37 -> V_112 ) {
V_108 = V_113 ;
V_107 = V_114 ;
}
default:
F_41 ( V_32 , 0 , V_108 , V_26 ) ;
V_93 = V_47 ;
V_106 = V_47 | V_60 ;
if ( F_42 ( V_32 , V_106 , V_106 , 0 , V_107 , V_26 ) )
V_93 = V_106 ;
else
V_107 += V_107 ;
F_42 ( V_32 , V_93 , V_47 , 0 , V_107 , V_26 ) ;
break;
}
}
void T_4 F_48 ( struct V_35 * V_32 )
{
F_47 ( V_32 , NULL ) ;
}
static void T_4 F_49 ( const struct V_35 * V_32 ,
struct V_2 * V_26 ,
struct V_2 * V_31 )
{
struct V_35 * V_109 ;
struct V_4 * V_5 ;
F_20 ( V_32 , V_26 , V_31 ) ;
F_21 (dev, &bus->devices, bus_list) {
V_109 = V_5 -> V_41 ;
if ( ! V_109 )
continue;
F_49 ( V_109 , V_26 , V_31 ) ;
switch ( V_5 -> V_18 >> 8 ) {
case V_111 :
if ( ! F_50 ( V_5 ) )
F_33 ( V_109 ) ;
break;
case V_110 :
F_22 ( V_109 ) ;
break;
default:
F_23 ( & V_5 -> V_5 , L_12
L_13 , F_51 ( V_109 ) , V_109 -> V_115 ) ;
break;
}
}
}
void T_4 F_52 ( const struct V_35 * V_32 )
{
F_49 ( V_32 , NULL , NULL ) ;
}
static void T_4 F_53 ( const struct V_4 * V_36 ,
struct V_2 * V_31 )
{
struct V_35 * V_109 ;
F_19 ( (struct V_4 * ) V_36 , V_31 ) ;
V_109 = V_36 -> V_41 ;
if ( ! V_109 )
return;
F_49 ( V_109 , NULL , V_31 ) ;
switch ( V_36 -> V_18 >> 8 ) {
case V_111 :
F_33 ( V_109 ) ;
break;
case V_110 :
F_22 ( V_109 ) ;
break;
default:
F_23 ( & V_36 -> V_5 , L_12
L_13 , F_51 ( V_109 ) , V_109 -> V_115 ) ;
break;
}
}
static void F_54 ( struct V_35 * V_32 ,
unsigned long type )
{
int V_29 ;
bool V_116 = false ;
struct V_4 * V_5 ;
struct V_6 * V_77 ;
unsigned long V_78 = V_42 | V_47 |
V_60 ;
V_5 = V_32 -> V_37 ;
for ( V_29 = V_69 ; V_29 <= V_117 ;
V_29 ++ ) {
V_77 = & V_5 -> V_6 [ V_29 ] ;
if ( ( V_77 -> V_16 & V_78 ) != type )
continue;
if ( ! V_77 -> V_81 )
continue;
F_55 ( V_77 ) ;
if ( ! F_56 ( V_77 ) ) {
F_57 ( V_118 , & V_5 -> V_5 ,
L_14 , V_29 , V_77 ) ;
V_77 -> V_15 = F_11 ( V_77 ) - 1 ;
V_77 -> V_14 = 0 ;
V_77 -> V_16 = 0 ;
V_116 = true ;
}
}
if ( V_116 ) {
if ( type & V_60 )
type = V_60 ;
F_31 ( V_32 , type ) ;
}
}
static void T_4 F_58 ( struct V_35 * V_32 ,
unsigned long type ,
enum V_119 V_120 )
{
struct V_4 * V_5 ;
bool V_121 = true ;
F_21 (dev, &bus->devices, bus_list) {
struct V_35 * V_109 = V_5 -> V_41 ;
if ( ! V_109 )
continue;
V_121 = false ;
if ( ( V_5 -> V_18 >> 8 ) != V_111 )
continue;
if ( V_120 == V_122 )
F_58 ( V_109 , type ,
V_122 ) ;
}
if ( F_16 ( V_32 ) )
return;
if ( ( V_32 -> V_37 -> V_18 >> 8 ) != V_111 )
return;
if ( ( V_120 == V_122 ) || V_121 )
F_54 ( V_32 , type ) ;
}
static void F_59 ( struct V_35 * V_32 )
{
struct V_6 * V_7 ;
int V_76 ;
F_36 (bus, res, i) {
if ( ! V_7 || ! V_7 -> V_15 || ! V_7 -> V_16 )
continue;
F_57 ( V_118 , & V_32 -> V_5 , L_15 , V_76 , V_7 ) ;
}
}
static void F_60 ( struct V_35 * V_32 )
{
struct V_35 * V_109 ;
struct V_4 * V_5 ;
F_59 ( V_32 ) ;
F_21 (dev, &bus->devices, bus_list) {
V_109 = V_5 -> V_41 ;
if ( ! V_109 )
continue;
F_60 ( V_109 ) ;
}
}
static int T_5 F_61 ( struct V_35 * V_32 )
{
int V_123 = 0 ;
struct V_4 * V_5 ;
F_21 (dev, &bus->devices, bus_list) {
int V_124 ;
struct V_35 * V_109 = V_5 -> V_41 ;
if ( ! V_109 )
continue;
V_124 = F_61 ( V_109 ) ;
if ( V_124 + 1 > V_123 )
V_123 = V_124 + 1 ;
}
return V_123 ;
}
static int T_5 F_62 ( void )
{
int V_123 = 0 ;
struct V_35 * V_32 ;
F_21 (bus, &pci_root_buses, node) {
int V_124 ;
V_124 = F_61 ( V_32 ) ;
if ( V_124 > V_123 )
V_123 = V_124 ;
}
return V_123 ;
}
void T_5
F_63 ( void )
{
struct V_35 * V_32 ;
struct V_2 V_125 ;
int V_126 = 0 ;
enum V_119 V_120 = V_127 ;
struct V_2 V_3 , * V_9 ;
unsigned long V_78 = V_42 | V_47 |
V_60 ;
unsigned long V_128 ;
int V_129 = F_62 () ;
int V_130 ;
V_3 . V_11 = NULL ;
V_125 . V_11 = NULL ;
V_130 = V_129 + 1 ;
F_64 ( V_118 L_16 ,
V_129 , V_130 ) ;
V_131:
F_21 (bus, &pci_root_buses, node)
F_47 ( V_32 , & V_125 ) ;
F_21 (bus, &pci_root_buses, node)
F_49 ( V_32 , & V_125 , & V_3 ) ;
F_65 ( V_125 . V_11 ) ;
V_126 ++ ;
if ( ! V_3 . V_11 )
goto V_132;
if ( ! F_66 () ) {
F_18 ( V_2 , & V_3 ) ;
goto V_132;
}
V_128 = 0 ;
for ( V_9 = V_3 . V_11 ; V_9 ; ) {
V_128 |= V_9 -> V_16 ;
V_9 = V_9 -> V_11 ;
}
V_128 &= V_78 ;
if ( ( V_128 == V_42 ) || ( V_126 >= V_130 ) ) {
F_18 ( V_2 , & V_3 ) ;
goto V_132;
}
F_64 ( V_118 L_17 ,
V_126 + 1 ) ;
if ( ( V_126 + 1 ) > 2 )
V_120 = V_122 ;
for ( V_9 = V_3 . V_11 ; V_9 ; ) {
V_32 = V_9 -> V_5 -> V_32 ;
F_58 ( V_32 , V_9 -> V_16 & V_78 ,
V_120 ) ;
V_9 = V_9 -> V_11 ;
}
for ( V_9 = V_3 . V_11 ; V_9 ; ) {
struct V_6 * V_7 = V_9 -> V_7 ;
V_7 -> V_14 = V_9 -> V_14 ;
V_7 -> V_15 = V_9 -> V_15 ;
V_7 -> V_16 = V_9 -> V_16 ;
if ( V_9 -> V_5 -> V_41 )
V_7 -> V_16 = 0 ;
V_9 = V_9 -> V_11 ;
}
F_18 ( V_2 , & V_3 ) ;
goto V_131;
V_132:
F_21 (bus, &pci_root_buses, node)
F_67 ( V_32 ) ;
F_21 (bus, &pci_root_buses, node)
F_60 ( V_32 ) ;
}
void F_68 ( struct V_4 * V_36 )
{
struct V_35 * V_81 = V_36 -> V_41 ;
int V_126 = 0 ;
struct V_2 V_3 , * V_9 ;
int V_133 ;
unsigned long V_78 = V_42 | V_47 |
V_60 ;
V_3 . V_11 = NULL ;
V_131:
F_48 ( V_81 ) ;
F_53 ( V_36 , & V_3 ) ;
V_126 ++ ;
if ( ! V_3 . V_11 )
goto V_134;
if ( V_126 >= 2 ) {
F_18 ( V_2 , & V_3 ) ;
goto V_134;
}
F_64 ( V_118 L_17 ,
V_126 + 1 ) ;
for ( V_9 = V_3 . V_11 ; V_9 ; ) {
struct V_35 * V_32 = V_9 -> V_5 -> V_32 ;
unsigned long V_16 = V_9 -> V_16 ;
F_58 ( V_32 , V_16 & V_78 ,
V_122 ) ;
V_9 = V_9 -> V_11 ;
}
for ( V_9 = V_3 . V_11 ; V_9 ; ) {
struct V_6 * V_7 = V_9 -> V_7 ;
V_7 -> V_14 = V_9 -> V_14 ;
V_7 -> V_15 = V_9 -> V_15 ;
V_7 -> V_16 = V_9 -> V_16 ;
if ( V_9 -> V_5 -> V_41 )
V_7 -> V_16 = 0 ;
V_9 = V_9 -> V_11 ;
}
F_18 ( V_2 , & V_3 ) ;
goto V_131;
V_134:
V_133 = F_69 ( V_36 ) ;
F_70 ( V_36 ) ;
F_67 ( V_81 ) ;
}
