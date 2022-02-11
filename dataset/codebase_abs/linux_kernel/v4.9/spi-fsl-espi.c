static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_3 ,
T_1 V_5 )
{
F_6 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , int V_3 ,
T_2 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_9 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 ;
T_2 * V_10 = V_2 -> V_11 ;
F_10 (t, &m->transfers, transfer_list) {
if ( V_9 -> V_12 )
memcpy ( V_10 , V_9 -> V_12 , V_9 -> V_13 ) ;
else
memset ( V_10 , 0 , V_9 -> V_13 ) ;
V_10 += V_9 -> V_13 ;
}
}
static void F_11 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 ;
T_2 * V_10 = V_2 -> V_11 ;
F_10 (t, &m->transfers, transfer_list) {
if ( V_9 -> V_14 )
memcpy ( V_9 -> V_14 , V_10 , V_9 -> V_13 ) ;
V_10 += V_9 -> V_13 ;
}
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_13 ( V_7 -> V_15 -> V_16 ) ;
struct V_8 * V_9 , * V_17 ;
if ( V_7 -> V_18 > V_19 ) {
F_14 ( V_2 -> V_20 , L_1 ,
V_7 -> V_18 ) ;
return - V_21 ;
}
V_17 = F_15 ( & V_7 -> V_22 , struct V_8 ,
V_23 ) ;
F_10 (t, &m->transfers, transfer_list) {
if ( V_17 -> V_24 != V_9 -> V_24 ||
V_17 -> V_25 != V_9 -> V_25 ) {
F_14 ( V_2 -> V_20 , L_2 ) ;
return - V_26 ;
}
}
return 0 ;
}
static void F_16 ( struct V_27 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 -> V_16 ) ;
struct V_28 * V_29 = V_15 -> V_30 ;
T_1 V_31 ;
unsigned long V_32 ;
F_17 ( V_32 ) ;
V_31 = F_1 ( V_2 , V_33 ) ;
F_5 ( V_2 , V_33 , V_31 & ~ V_34 ) ;
F_5 ( V_2 , F_18 ( V_15 -> V_35 ) ,
V_29 -> V_36 ) ;
F_5 ( V_2 , V_33 , V_31 ) ;
F_19 ( V_32 ) ;
}
static T_1 F_20 ( struct V_1 * V_1 )
{
T_1 V_37 ;
T_3 V_38 ;
T_3 V_39 ;
const T_1 * V_40 = V_1 -> V_40 ;
if ( ! V_40 )
return 0 ;
V_37 = * V_40 ++ << V_1 -> V_41 ;
V_39 = V_37 & 0xffff ;
V_38 = ( V_37 >> 16 ) & 0xffff ;
F_21 ( & V_39 ) ;
F_21 ( & V_38 ) ;
V_37 = V_38 | V_39 ;
V_1 -> V_40 = V_40 ;
return V_37 ;
}
static void F_22 ( struct V_27 * V_15 ,
struct V_8 * V_9 )
{
struct V_1 * V_1 = F_13 ( V_15 -> V_16 ) ;
int V_24 = V_9 ? V_9 -> V_24 : V_15 -> V_24 ;
T_1 V_42 = V_9 ? V_9 -> V_25 : V_15 -> V_43 ;
T_2 V_44 ;
struct V_28 * V_29 = V_15 -> V_30 ;
V_29 -> V_45 = 0 ;
V_29 -> V_41 = 0 ;
V_29 -> V_46 = V_47 ;
V_29 -> V_48 = V_49 ;
if ( V_24 <= 8 ) {
V_29 -> V_45 = 8 - V_24 ;
} else {
V_29 -> V_45 = 16 - V_24 ;
if ( V_15 -> V_50 & V_51 )
V_29 -> V_48 = F_20 ;
}
V_1 -> V_45 = V_29 -> V_45 ;
V_1 -> V_41 = V_29 -> V_41 ;
V_1 -> V_46 = V_29 -> V_46 ;
V_1 -> V_48 = V_29 -> V_48 ;
V_29 -> V_36 &= ~ ( F_23 ( 0xF ) | V_52 | F_24 ( 0xF ) ) ;
V_29 -> V_36 |= F_23 ( V_24 - 1 ) ;
if ( ( V_1 -> V_53 / V_42 ) > 64 ) {
V_29 -> V_36 |= V_52 ;
V_44 = F_25 ( V_1 -> V_53 , V_42 * 16 * 4 ) ;
F_26 ( V_44 > 33 , L_3
L_4 , F_27 ( & V_15 -> V_20 ) ,
V_42 , V_1 -> V_53 / ( 4 * 16 * ( 32 + 1 ) ) ) ;
if ( V_44 > 33 )
V_44 = 33 ;
} else {
V_44 = F_25 ( V_1 -> V_53 , V_42 * 4 ) ;
}
if ( V_44 )
V_44 -- ;
if ( V_44 < 2 )
V_44 = 2 ;
V_29 -> V_36 |= F_24 ( V_44 ) ;
F_16 ( V_15 ) ;
}
static int F_28 ( struct V_27 * V_15 , struct V_8 * V_9 )
{
struct V_1 * V_1 = F_13 ( V_15 -> V_16 ) ;
T_1 V_54 ;
int V_55 ;
V_1 -> V_13 = V_9 -> V_13 ;
V_1 -> V_56 = F_29 ( V_9 -> V_13 , 4 ) / 4 ;
V_1 -> V_40 = V_9 -> V_12 ;
V_1 -> V_57 = V_9 -> V_14 ;
F_30 ( & V_1 -> V_58 ) ;
F_5 ( V_1 , V_59 ,
( F_31 ( V_15 -> V_35 ) | F_32 ( V_9 -> V_13 - 1 ) ) ) ;
F_5 ( V_1 , V_60 , V_61 ) ;
V_54 = V_1 -> V_48 ( V_1 ) ;
F_5 ( V_1 , V_62 , V_54 ) ;
V_55 = F_33 ( & V_1 -> V_58 , 2 * V_63 ) ;
if ( V_55 == 0 )
F_14 ( V_1 -> V_20 ,
L_5 ,
V_1 -> V_56 ) ;
F_5 ( V_1 , V_60 , 0 ) ;
return V_1 -> V_56 > 0 ? - V_21 : 0 ;
}
static int F_34 ( struct V_6 * V_7 , struct V_8 * V_64 )
{
struct V_1 * V_2 = F_13 ( V_7 -> V_15 -> V_16 ) ;
struct V_27 * V_15 = V_7 -> V_15 ;
int V_55 ;
F_9 ( V_7 , V_2 ) ;
F_22 ( V_15 , V_64 ) ;
V_55 = F_28 ( V_15 , V_64 ) ;
if ( V_64 -> V_65 )
F_35 ( V_64 -> V_65 ) ;
F_22 ( V_15 , NULL ) ;
if ( ! V_55 )
F_11 ( V_7 , V_2 ) ;
return V_55 ;
}
static int F_36 ( struct V_66 * V_16 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = F_13 ( V_7 -> V_15 -> V_16 ) ;
unsigned int V_65 = 0 ;
struct V_8 * V_9 , V_64 = {} ;
int V_55 ;
V_55 = F_12 ( V_7 ) ;
if ( V_55 )
goto V_67;
F_10 (t, &m->transfers, transfer_list) {
if ( V_9 -> V_65 > V_65 )
V_65 = V_9 -> V_65 ;
}
V_9 = F_15 ( & V_7 -> V_22 , struct V_8 ,
V_23 ) ;
V_64 . V_13 = V_7 -> V_18 ;
V_64 . V_25 = V_9 -> V_25 ;
V_64 . V_24 = V_9 -> V_24 ;
V_64 . V_65 = V_65 ;
V_64 . V_12 = V_2 -> V_11 ;
V_64 . V_14 = V_2 -> V_11 ;
if ( V_64 . V_13 )
V_55 = F_34 ( V_7 , & V_64 ) ;
V_7 -> V_68 = V_55 ? 0 : V_64 . V_13 ;
V_67:
if ( V_7 -> V_69 == - V_70 )
V_7 -> V_69 = V_55 ;
F_37 ( V_16 ) ;
return V_55 ;
}
static int F_38 ( struct V_27 * V_15 )
{
struct V_1 * V_1 ;
T_1 V_71 ;
struct V_28 * V_29 = F_39 ( V_15 ) ;
if ( ! V_15 -> V_43 )
return - V_26 ;
if ( ! V_29 ) {
V_29 = F_40 ( sizeof( * V_29 ) , V_72 ) ;
if ( ! V_29 )
return - V_73 ;
F_41 ( V_15 , V_29 ) ;
}
V_1 = F_13 ( V_15 -> V_16 ) ;
F_42 ( V_1 -> V_20 ) ;
V_29 -> V_36 = F_1 ( V_1 ,
F_18 ( V_15 -> V_35 ) ) ;
V_29 -> V_36 &= ~ ( V_74 | V_75
| V_76 ) ;
if ( V_15 -> V_50 & V_77 )
V_29 -> V_36 |= V_74 ;
if ( V_15 -> V_50 & V_78 )
V_29 -> V_36 |= V_75 ;
if ( ! ( V_15 -> V_50 & V_51 ) )
V_29 -> V_36 |= V_76 ;
V_71 = F_1 ( V_1 , V_33 ) ;
V_71 &= ~ V_79 ;
if ( V_15 -> V_50 & V_80 )
V_71 |= V_79 ;
F_5 ( V_1 , V_33 , V_71 ) ;
F_22 ( V_15 , NULL ) ;
F_43 ( V_1 -> V_20 ) ;
F_44 ( V_1 -> V_20 ) ;
return 0 ;
}
static void F_45 ( struct V_27 * V_15 )
{
struct V_28 * V_29 = F_39 ( V_15 ) ;
F_46 ( V_29 ) ;
F_41 ( V_15 , NULL ) ;
}
static void F_47 ( struct V_1 * V_2 , T_1 V_81 )
{
if ( V_81 & V_82 ) {
T_1 V_83 , V_31 ;
T_2 V_84 ;
int V_85 = 4 ;
int V_55 ;
if ( F_48 ( V_81 ) < F_49 ( 4 , V_2 -> V_13 ) ) {
V_55 = F_50 (
! ( F_48 ( V_81 =
F_1 ( V_2 , V_86 ) ) <
F_49 ( 4 , V_2 -> V_13 ) ) ,
10000 , 0 ) ;
if ( ! V_55 )
F_14 ( V_2 -> V_20 ,
L_6 ) ;
}
if ( V_2 -> V_13 >= 4 ) {
V_83 = F_1 ( V_2 , V_87 ) ;
} else if ( V_2 -> V_13 <= 0 ) {
F_14 ( V_2 -> V_20 ,
L_7
L_8 ,
F_49 ( 4 , V_2 -> V_13 ) , F_48 ( V_81 ) ) ;
V_85 = 0 ;
} else {
V_85 = V_2 -> V_13 ;
V_31 = V_2 -> V_13 ;
V_83 = 0 ;
while ( V_31 -- ) {
V_84 = F_3 ( V_2 ,
V_87 ) ;
V_83 |= ( V_84 << ( V_31 * 8 ) ) ;
}
V_83 <<= ( 4 - V_2 -> V_13 ) * 8 ;
}
V_2 -> V_13 -= V_85 ;
if ( V_85 && V_2 -> V_57 )
V_2 -> V_46 ( V_83 , V_2 ) ;
}
if ( ! ( V_81 & V_88 ) ) {
int V_55 ;
V_55 = F_50 ( ( ( V_81 = F_1 (
V_2 , V_86 ) ) & V_88 ) , 1000 , 0 ) ;
if ( ! V_55 ) {
F_14 ( V_2 -> V_20 , L_9 ) ;
F_51 ( & V_2 -> V_58 ) ;
return;
}
}
V_2 -> V_56 -= 1 ;
if ( V_2 -> V_56 ) {
T_1 V_54 = V_2 -> V_48 ( V_2 ) ;
F_5 ( V_2 , V_62 , V_54 ) ;
} else {
F_51 ( & V_2 -> V_58 ) ;
}
}
static T_4 F_52 ( T_5 V_89 , void * V_90 )
{
struct V_1 * V_2 = V_90 ;
T_1 V_81 ;
V_81 = F_1 ( V_2 , V_86 ) ;
if ( ! V_81 )
return V_91 ;
F_53 ( V_2 -> V_20 , L_10 , V_92 , V_81 ) ;
F_47 ( V_2 , V_81 ) ;
F_5 ( V_2 , V_86 , V_81 ) ;
return V_93 ;
}
static int F_54 ( struct V_94 * V_20 )
{
struct V_66 * V_16 = F_55 ( V_20 ) ;
struct V_1 * V_1 = F_13 ( V_16 ) ;
T_1 V_95 ;
V_95 = F_1 ( V_1 , V_33 ) ;
V_95 &= ~ V_34 ;
F_5 ( V_1 , V_33 , V_95 ) ;
return 0 ;
}
static int F_56 ( struct V_94 * V_20 )
{
struct V_66 * V_16 = F_55 ( V_20 ) ;
struct V_1 * V_1 = F_13 ( V_16 ) ;
T_1 V_95 ;
V_95 = F_1 ( V_1 , V_33 ) ;
V_95 |= V_34 ;
F_5 ( V_1 , V_33 , V_95 ) ;
return 0 ;
}
static T_6 F_57 ( struct V_27 * V_15 )
{
return V_19 ;
}
static int F_58 ( struct V_94 * V_20 , struct V_96 * V_97 ,
unsigned int V_89 )
{
struct V_98 * V_99 = F_59 ( V_20 ) ;
struct V_66 * V_16 ;
struct V_1 * V_1 ;
struct V_100 * V_101 ;
const T_7 * V_102 ;
T_1 V_95 , V_103 ;
int V_104 , V_13 , V_55 ;
V_16 = F_60 ( V_20 , sizeof( struct V_1 ) ) ;
if ( ! V_16 )
return - V_73 ;
F_61 ( V_20 , V_16 ) ;
F_62 ( V_20 , V_97 , V_89 ) ;
V_16 -> V_105 = F_63 ( 4 , 16 ) ;
V_16 -> V_106 = F_38 ;
V_16 -> V_107 = F_45 ;
V_16 -> V_108 = F_36 ;
V_16 -> V_109 = true ;
V_16 -> V_110 = F_57 ;
V_1 = F_13 ( V_16 ) ;
V_1 -> V_11 =
F_64 ( V_20 , V_19 , V_72 ) ;
if ( ! V_1 -> V_11 ) {
V_55 = - V_73 ;
goto V_111;
}
V_1 -> V_4 = F_65 ( V_20 , V_97 ) ;
if ( F_66 ( V_1 -> V_4 ) ) {
V_55 = F_67 ( V_1 -> V_4 ) ;
goto V_111;
}
V_55 = F_68 ( V_20 , V_1 -> V_89 , F_52 ,
0 , L_11 , V_1 ) ;
if ( V_55 )
goto V_111;
if ( V_1 -> V_32 & V_112 ) {
V_1 -> V_45 = 16 ;
V_1 -> V_41 = 24 ;
}
F_5 ( V_1 , V_33 , 0 ) ;
F_5 ( V_1 , V_60 , 0 ) ;
F_5 ( V_1 , V_59 , 0 ) ;
F_5 ( V_1 , V_86 , 0xffffffff ) ;
F_69 (master->dev.of_node, nc) {
V_102 = F_70 ( V_101 , L_12 , & V_13 ) ;
if ( ! V_102 || V_13 < sizeof( * V_102 ) )
continue;
V_104 = F_71 ( V_102 ) ;
if ( V_104 < 0 || V_104 >= V_99 -> V_113 )
continue;
V_103 = V_114 ;
V_102 = F_70 ( V_101 , L_13 , & V_13 ) ;
if ( V_102 && V_13 >= sizeof( * V_102 ) ) {
V_103 &= ~ ( F_72 ( 0xf ) ) ;
V_103 |= F_72 ( F_71 ( V_102 ) ) ;
}
V_102 = F_70 ( V_101 , L_14 , & V_13 ) ;
if ( V_102 && V_13 >= sizeof( * V_102 ) ) {
V_103 &= ~ ( F_73 ( 0xf ) ) ;
V_103 |= F_73 ( F_71 ( V_102 ) ) ;
}
F_5 ( V_1 , F_18 ( V_104 ) , V_103 ) ;
F_74 ( V_20 , L_15 , V_104 , V_103 ) ;
}
V_95 = V_99 -> V_115 | V_116 | V_34 ;
F_5 ( V_1 , V_33 , V_95 ) ;
F_75 ( V_20 , V_117 ) ;
F_76 ( V_20 ) ;
F_77 ( V_20 ) ;
F_78 ( V_20 ) ;
F_42 ( V_20 ) ;
V_55 = F_79 ( V_20 , V_16 ) ;
if ( V_55 < 0 )
goto V_118;
F_74 ( V_20 , L_16 , V_1 -> V_4 ,
V_1 -> V_89 ) ;
F_43 ( V_20 ) ;
F_44 ( V_20 ) ;
return 0 ;
V_118:
F_80 ( V_20 ) ;
F_81 ( V_20 ) ;
F_82 ( V_20 ) ;
V_111:
F_83 ( V_16 ) ;
return V_55 ;
}
static int F_84 ( struct V_94 * V_20 )
{
struct V_100 * V_119 = V_20 -> V_120 ;
struct V_98 * V_99 = F_59 ( V_20 ) ;
const T_1 * V_102 ;
int V_13 ;
V_102 = F_70 ( V_119 , L_17 , & V_13 ) ;
if ( ! V_102 || V_13 < sizeof( * V_102 ) ) {
F_14 ( V_20 , L_18 ) ;
return - V_26 ;
}
V_99 -> V_113 = * V_102 ;
V_99 -> V_121 = NULL ;
return 0 ;
}
static int F_85 ( struct V_122 * V_123 )
{
struct V_94 * V_20 = & V_123 -> V_20 ;
struct V_100 * V_119 = V_123 -> V_20 . V_120 ;
struct V_96 V_97 ;
unsigned int V_89 ;
int V_55 ;
V_55 = F_86 ( V_123 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_84 ( V_20 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_87 ( V_119 , 0 , & V_97 ) ;
if ( V_55 )
return V_55 ;
V_89 = F_88 ( V_119 , 0 ) ;
if ( ! V_89 )
return - V_26 ;
return F_58 ( V_20 , & V_97 , V_89 ) ;
}
static int F_89 ( struct V_122 * V_20 )
{
F_81 ( & V_20 -> V_20 ) ;
return 0 ;
}
static int F_90 ( struct V_94 * V_20 )
{
struct V_66 * V_16 = F_55 ( V_20 ) ;
int V_55 ;
V_55 = F_91 ( V_16 ) ;
if ( V_55 ) {
F_92 ( V_20 , L_19 ) ;
return V_55 ;
}
V_55 = F_93 ( V_20 ) ;
if ( V_55 < 0 )
return V_55 ;
return 0 ;
}
static int F_94 ( struct V_94 * V_20 )
{
struct V_98 * V_99 = F_59 ( V_20 ) ;
struct V_66 * V_16 = F_55 ( V_20 ) ;
struct V_1 * V_1 ;
T_1 V_95 ;
int V_104 , V_55 ;
V_1 = F_13 ( V_16 ) ;
F_5 ( V_1 , V_33 , 0 ) ;
F_5 ( V_1 , V_60 , 0 ) ;
F_5 ( V_1 , V_59 , 0 ) ;
F_5 ( V_1 , V_86 , 0xffffffff ) ;
for ( V_104 = 0 ; V_104 < V_99 -> V_113 ; V_104 ++ )
F_5 ( V_1 , F_18 ( V_104 ) ,
V_114 ) ;
V_95 = V_99 -> V_115 | V_116 | V_34 ;
F_5 ( V_1 , V_33 , V_95 ) ;
V_55 = F_95 ( V_20 ) ;
if ( V_55 < 0 )
return V_55 ;
return F_96 ( V_16 ) ;
}
