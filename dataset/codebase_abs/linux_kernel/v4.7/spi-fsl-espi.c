static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_1 T_2 * V_11 = & V_10 -> V_12 [ V_2 -> V_13 ] ;
T_1 T_2 * V_14 = & V_10 -> V_11 ;
T_3 V_15 ;
unsigned long V_16 ;
F_3 ( V_16 ) ;
V_15 = F_4 ( V_14 ) ;
F_5 ( V_14 , V_15 & ~ V_17 ) ;
F_5 ( V_11 , V_7 -> V_18 ) ;
F_5 ( V_14 , V_15 ) ;
F_6 ( V_16 ) ;
}
static T_3 F_7 ( struct V_3 * V_3 )
{
T_3 V_19 ;
T_4 V_20 ;
T_4 V_21 ;
const T_3 * V_22 = V_3 -> V_22 ;
if ( ! V_22 )
return 0 ;
V_19 = * V_22 ++ << V_3 -> V_23 ;
V_21 = V_19 & 0xffff ;
V_20 = ( V_19 >> 16 ) & 0xffff ;
F_8 ( & V_21 ) ;
F_8 ( & V_20 ) ;
V_19 = V_20 | V_21 ;
V_3 -> V_22 = V_22 ;
return V_19 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_5 ) ;
int V_26 = 0 ;
T_5 V_27 ;
T_3 V_28 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_25 ) {
V_26 = V_25 -> V_26 ;
V_28 = V_25 -> V_29 ;
}
if ( ! V_26 )
V_26 = V_2 -> V_26 ;
if ( ! V_28 )
V_28 = V_2 -> V_30 ;
V_7 -> V_31 = 0 ;
V_7 -> V_23 = 0 ;
V_7 -> V_32 = V_33 ;
V_7 -> V_34 = V_35 ;
if ( V_26 <= 8 ) {
V_7 -> V_31 = 8 - V_26 ;
} else {
V_7 -> V_31 = 16 - V_26 ;
if ( V_2 -> V_11 & V_36 )
V_7 -> V_34 = F_7 ;
}
V_3 -> V_31 = V_7 -> V_31 ;
V_3 -> V_23 = V_7 -> V_23 ;
V_3 -> V_32 = V_7 -> V_32 ;
V_3 -> V_34 = V_7 -> V_34 ;
V_26 = V_26 - 1 ;
V_7 -> V_18 &= ~ ( F_10 ( 0xF ) | V_37 | F_11 ( 0xF ) ) ;
V_7 -> V_18 |= F_10 ( V_26 ) ;
if ( ( V_3 -> V_38 / V_28 ) > 64 ) {
V_7 -> V_18 |= V_37 ;
V_27 = F_12 ( V_3 -> V_38 , V_28 * 16 * 4 ) ;
F_13 ( V_27 > 33 , L_1
L_2 , F_14 ( & V_2 -> V_39 ) ,
V_28 , V_3 -> V_38 / ( 4 * 16 * ( 32 + 1 ) ) ) ;
if ( V_27 > 33 )
V_27 = 33 ;
} else {
V_27 = F_12 ( V_3 -> V_38 , V_28 * 4 ) ;
}
if ( V_27 )
V_27 -- ;
if ( V_27 < 2 )
V_27 = 2 ;
V_7 -> V_18 |= F_11 ( V_27 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 , struct V_24 * V_25 ,
unsigned int V_40 )
{
T_3 V_41 ;
struct V_9 * V_10 = V_4 -> V_10 ;
V_4 -> V_42 = V_40 ;
F_5 ( & V_10 -> V_43 , V_44 ) ;
V_41 = V_4 -> V_34 ( V_4 ) ;
F_5 ( & V_10 -> V_45 , V_41 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_5 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
unsigned int V_40 = V_25 -> V_40 ;
int V_46 ;
V_3 -> V_40 = V_25 -> V_40 ;
V_40 = F_17 ( V_40 , 4 ) / 4 ;
V_3 -> V_22 = V_25 -> V_47 ;
V_3 -> V_48 = V_25 -> V_49 ;
F_18 ( & V_3 -> V_50 ) ;
if ( V_25 -> V_40 > V_51 ) {
F_19 ( V_3 -> V_39 , L_3
L_4 , V_25 -> V_40 ) ;
return - V_52 ;
}
F_5 ( & V_10 -> V_53 ,
( F_20 ( V_2 -> V_13 ) | F_21 ( V_25 -> V_40 - 1 ) ) ) ;
V_46 = F_15 ( V_3 , V_25 , V_40 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_22 ( & V_3 -> V_50 , 2 * V_54 ) ;
if ( V_46 == 0 )
F_19 ( V_3 -> V_39 ,
L_5 ,
V_3 -> V_42 ) ;
F_5 ( & V_10 -> V_43 , 0 ) ;
return V_3 -> V_42 ;
}
static inline void F_23 ( unsigned int V_55 , T_5 * V_56 )
{
if ( V_56 ) {
V_56 [ 1 ] = ( T_5 ) ( V_55 >> 16 ) ;
V_56 [ 2 ] = ( T_5 ) ( V_55 >> 8 ) ;
V_56 [ 3 ] = ( T_5 ) ( V_55 >> 0 ) ;
}
}
static inline unsigned int F_24 ( T_5 * V_56 )
{
if ( V_56 )
return V_56 [ 1 ] << 16 | V_56 [ 2 ] << 8 | V_56 [ 3 ] << 0 ;
return 0 ;
}
static void F_25 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_59 * V_61 = V_60 ;
struct V_57 V_62 ;
struct V_24 * V_25 , * V_63 , V_64 ;
int V_65 = 0 ;
F_26 ( & V_62 ) ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
V_63 = F_27 ( & V_58 -> V_66 , struct V_24 ,
V_67 ) ;
F_28 (t, &m->transfers, transfer_list) {
if ( ( V_63 -> V_26 != V_25 -> V_26 ) ||
( V_63 -> V_29 != V_25 -> V_29 ) ) {
V_61 -> V_65 = - V_52 ;
F_19 ( V_4 -> V_39 ,
L_6 ) ;
return;
}
V_64 . V_29 = V_25 -> V_29 ;
V_64 . V_26 = V_25 -> V_26 ;
V_64 . V_68 = F_29 ( V_63 -> V_68 , V_25 -> V_68 ) ;
}
V_64 . V_40 = V_61 -> V_40 ;
V_64 . V_47 = V_61 -> V_47 ;
V_64 . V_49 = V_61 -> V_49 ;
F_30 ( & V_64 , & V_62 ) ;
F_28 (t, &message.transfers, transfer_list) {
if ( V_25 -> V_26 || V_25 -> V_29 ) {
V_65 = - V_52 ;
V_65 = F_9 ( V_2 , V_25 ) ;
if ( V_65 < 0 )
break;
}
if ( V_25 -> V_40 )
V_65 = F_16 ( V_2 , V_25 ) ;
if ( V_65 ) {
V_65 = - V_69 ;
break;
}
if ( V_25 -> V_68 )
F_31 ( V_25 -> V_68 ) ;
}
V_61 -> V_65 = V_65 ;
F_9 ( V_2 , NULL ) ;
}
static void F_32 ( struct V_57 * V_58 ,
struct V_59 * V_64 , T_5 * V_70 )
{
struct V_24 * V_25 ;
T_5 * V_71 ;
int V_72 = 0 ;
struct V_59 * V_61 = V_64 ;
V_71 = F_33 ( V_51 , V_73 ) ;
if ( ! V_71 ) {
V_61 -> V_65 = - V_74 ;
return;
}
F_28 (t, &m->transfers, transfer_list) {
if ( V_25 -> V_47 ) {
memcpy ( V_71 + V_72 , V_25 -> V_47 , V_25 -> V_40 ) ;
V_72 += V_25 -> V_40 ;
}
}
V_61 -> V_47 = V_71 ;
V_61 -> V_49 = V_71 ;
F_25 ( V_58 , V_61 ) ;
V_61 -> V_75 = V_61 -> V_40 ;
F_34 ( V_71 ) ;
}
static void F_35 ( struct V_57 * V_58 ,
struct V_59 * V_64 , T_5 * V_70 )
{
struct V_59 * V_61 = V_64 ;
unsigned int V_76 = V_61 -> V_40 ;
struct V_24 * V_25 ;
T_5 * V_71 ;
T_5 * V_49 = V_70 ;
unsigned int V_77 ;
unsigned int V_55 ;
unsigned int V_78 ;
unsigned int V_79 = 0 ;
unsigned int V_80 ;
int V_72 , V_81 ;
V_71 = F_33 ( V_51 , V_73 ) ;
if ( ! V_71 ) {
V_61 -> V_65 = - V_74 ;
return;
}
for ( V_80 = 0 , V_81 = 0 ; V_80 < V_76 ; V_80 += V_77 , V_81 ++ ) {
V_77 = V_76 - V_80 ;
V_72 = 0 ;
V_78 = 0 ;
F_28 (t, &m->transfers, transfer_list) {
if ( V_25 -> V_47 ) {
memcpy ( V_71 + V_72 , V_25 -> V_47 , V_25 -> V_40 ) ;
V_72 += V_25 -> V_40 ;
if ( ! V_25 -> V_49 )
V_78 += V_25 -> V_40 ;
}
}
if ( V_81 > 0 )
V_77 += V_78 ;
if ( V_77 > V_51 )
V_77 = V_51 ;
if ( V_80 > 0 ) {
V_55 = F_24 ( V_71 ) ;
V_55 += V_79 ;
F_23 ( V_55 , V_71 ) ;
}
V_61 -> V_40 = V_77 ;
V_61 -> V_47 = V_71 ;
V_61 -> V_49 = V_71 ;
F_25 ( V_58 , V_61 ) ;
if ( V_78 < V_51 )
memcpy ( V_49 + V_79 , V_61 -> V_49 + V_78 ,
V_77 - V_78 ) ;
V_79 += V_77 - V_78 ;
if ( V_81 > 0 )
V_61 -> V_75 += V_61 -> V_40 - V_78 ;
else
V_61 -> V_75 += V_61 -> V_40 ;
}
F_34 ( V_71 ) ;
}
static int F_36 ( struct V_82 * V_5 ,
struct V_57 * V_58 )
{
struct V_24 * V_25 ;
T_5 * V_49 = NULL ;
unsigned int V_83 = 0 ;
unsigned int V_84 = 0 ;
unsigned int V_85 = 0 ;
struct V_59 V_61 ;
F_28 (t, &m->transfers, transfer_list) {
if ( V_25 -> V_47 )
V_83 += V_25 -> V_40 ;
if ( V_25 -> V_49 ) {
V_84 += V_25 -> V_40 ;
V_49 = V_25 -> V_49 ;
}
if ( ( V_25 -> V_47 ) || ( V_25 -> V_49 ) )
V_85 += V_25 -> V_40 ;
}
V_61 . V_83 = V_83 ;
V_61 . V_84 = V_84 ;
V_61 . V_40 = V_85 ;
V_61 . V_75 = 0 ;
V_61 . V_65 = 0 ;
if ( ! V_49 )
F_32 ( V_58 , & V_61 , NULL ) ;
else
F_35 ( V_58 , & V_61 , V_49 ) ;
V_58 -> V_75 = V_61 . V_75 ;
V_58 -> V_65 = V_61 . V_65 ;
F_37 ( V_5 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_9 * V_10 ;
int V_86 ;
T_3 V_18 ;
T_3 V_87 ;
struct V_6 * V_7 = F_39 ( V_2 ) ;
if ( ! V_2 -> V_30 )
return - V_52 ;
if ( ! V_7 ) {
V_7 = F_33 ( sizeof( * V_7 ) , V_73 ) ;
if ( ! V_7 )
return - V_74 ;
F_40 ( V_2 , V_7 ) ;
}
V_3 = F_2 ( V_2 -> V_5 ) ;
V_10 = V_3 -> V_10 ;
F_41 ( V_3 -> V_39 ) ;
V_18 = V_7 -> V_18 ;
V_7 -> V_18 = F_4 (
& V_10 -> V_12 [ V_2 -> V_13 ] ) ;
V_7 -> V_18 &= ~ ( V_88 | V_89
| V_90 ) ;
if ( V_2 -> V_11 & V_91 )
V_7 -> V_18 |= V_88 ;
if ( V_2 -> V_11 & V_92 )
V_7 -> V_18 |= V_89 ;
if ( ! ( V_2 -> V_11 & V_36 ) )
V_7 -> V_18 |= V_90 ;
V_87 = F_4 ( & V_10 -> V_11 ) ;
V_87 &= ~ V_93 ;
if ( V_2 -> V_11 & V_94 )
V_87 |= V_93 ;
F_5 ( & V_10 -> V_11 , V_87 ) ;
V_86 = F_9 ( V_2 , NULL ) ;
F_42 ( V_3 -> V_39 ) ;
F_43 ( V_3 -> V_39 ) ;
if ( V_86 < 0 ) {
V_7 -> V_18 = V_18 ;
return V_86 ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_39 ( V_2 ) ;
F_34 ( V_7 ) ;
F_40 ( V_2 , NULL ) ;
}
void F_45 ( struct V_3 * V_4 , T_3 V_95 )
{
struct V_9 * V_10 = V_4 -> V_10 ;
if ( V_95 & V_96 ) {
T_3 V_97 , V_15 ;
T_5 V_98 ;
int V_99 = 4 ;
int V_46 ;
if ( F_46 ( V_95 ) < F_47 ( 4 , V_4 -> V_40 ) ) {
V_46 = F_48 (
! ( F_46 ( V_95 =
F_4 ( & V_10 -> V_100 ) ) <
F_47 ( 4 , V_4 -> V_40 ) ) ,
10000 , 0 ) ;
if ( ! V_46 )
F_19 ( V_4 -> V_39 ,
L_7 ) ;
}
if ( V_4 -> V_40 >= 4 ) {
V_97 = F_4 ( & V_10 -> V_101 ) ;
} else if ( V_4 -> V_40 <= 0 ) {
F_19 ( V_4 -> V_39 ,
L_8
L_9 ,
F_47 ( 4 , V_4 -> V_40 ) , F_46 ( V_95 ) ) ;
V_99 = 0 ;
} else {
V_99 = V_4 -> V_40 ;
V_15 = V_4 -> V_40 ;
V_97 = 0 ;
while ( V_15 -- ) {
V_98 = F_49 ( ( T_5 * ) & V_10 -> V_101 ) ;
V_97 |= ( V_98 << ( V_15 * 8 ) ) ;
}
V_97 <<= ( 4 - V_4 -> V_40 ) * 8 ;
}
V_4 -> V_40 -= V_99 ;
if ( V_4 -> V_48 )
V_4 -> V_32 ( V_97 , V_4 ) ;
}
if ( ! ( V_95 & V_102 ) ) {
int V_46 ;
V_46 = F_48 ( ( ( V_95 = F_4 (
& V_10 -> V_100 ) ) & V_102 ) , 1000 , 0 ) ;
if ( ! V_46 ) {
F_19 ( V_4 -> V_39 , L_10 ) ;
F_5 ( & V_10 -> V_100 , V_95 ) ;
F_50 ( & V_4 -> V_50 ) ;
return;
}
}
F_5 ( & V_10 -> V_100 , V_95 ) ;
V_4 -> V_42 -= 1 ;
if ( V_4 -> V_42 ) {
T_3 V_41 = V_4 -> V_34 ( V_4 ) ;
F_5 ( & V_10 -> V_45 , V_41 ) ;
} else {
F_50 ( & V_4 -> V_50 ) ;
}
}
static T_6 F_51 ( T_7 V_103 , void * V_104 )
{
struct V_3 * V_4 = V_104 ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_6 V_46 = V_105 ;
T_3 V_95 ;
V_95 = F_4 ( & V_10 -> V_100 ) ;
if ( V_95 )
V_46 = V_106 ;
F_52 ( V_4 -> V_39 , L_11 , V_107 , V_95 ) ;
F_45 ( V_4 , V_95 ) ;
return V_46 ;
}
static int F_53 ( struct V_108 * V_39 )
{
struct V_82 * V_5 = F_54 ( V_39 ) ;
struct V_3 * V_3 = F_2 ( V_5 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
T_3 V_109 ;
V_109 = F_4 ( & V_10 -> V_11 ) ;
V_109 &= ~ V_17 ;
F_5 ( & V_10 -> V_11 , V_109 ) ;
return 0 ;
}
static int F_55 ( struct V_108 * V_39 )
{
struct V_82 * V_5 = F_54 ( V_39 ) ;
struct V_3 * V_3 = F_2 ( V_5 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
T_3 V_109 ;
V_109 = F_4 ( & V_10 -> V_11 ) ;
V_109 |= V_17 ;
F_5 ( & V_10 -> V_11 , V_109 ) ;
return 0 ;
}
static T_8 F_56 ( struct V_1 * V_2 )
{
return V_51 ;
}
static struct V_82 * F_57 ( struct V_108 * V_39 ,
struct V_110 * V_111 , unsigned int V_103 )
{
struct V_112 * V_113 = F_58 ( V_39 ) ;
struct V_82 * V_5 ;
struct V_3 * V_3 ;
struct V_9 * V_10 ;
struct V_114 * V_115 ;
const T_1 * V_116 ;
T_3 V_109 , V_12 ;
int V_72 , V_40 , V_46 = 0 ;
V_5 = F_59 ( V_39 , sizeof( struct V_3 ) ) ;
if ( ! V_5 ) {
V_46 = - V_74 ;
goto V_117;
}
F_60 ( V_39 , V_5 ) ;
F_61 ( V_39 , V_111 , V_103 ) ;
V_5 -> V_118 = F_62 ( 4 , 16 ) ;
V_5 -> V_119 = F_38 ;
V_5 -> V_120 = F_44 ;
V_5 -> V_121 = F_36 ;
V_5 -> V_122 = true ;
V_5 -> V_123 = F_56 ;
V_3 = F_2 ( V_5 ) ;
V_3 -> V_10 = F_63 ( V_39 , V_111 ) ;
if ( F_64 ( V_3 -> V_10 ) ) {
V_46 = F_65 ( V_3 -> V_10 ) ;
goto V_124;
}
V_10 = V_3 -> V_10 ;
V_46 = F_66 ( V_39 , V_3 -> V_103 , F_51 ,
0 , L_12 , V_3 ) ;
if ( V_46 )
goto V_124;
if ( V_3 -> V_16 & V_125 ) {
V_3 -> V_31 = 16 ;
V_3 -> V_23 = 24 ;
}
F_5 ( & V_10 -> V_11 , 0 ) ;
F_5 ( & V_10 -> V_43 , 0 ) ;
F_5 ( & V_10 -> V_53 , 0 ) ;
F_5 ( & V_10 -> V_100 , 0xffffffff ) ;
F_67 (master->dev.of_node, nc) {
V_116 = F_68 ( V_115 , L_13 , & V_40 ) ;
if ( ! V_116 || V_40 < sizeof( * V_116 ) )
continue;
V_72 = F_69 ( V_116 ) ;
if ( V_72 < 0 || V_72 >= V_113 -> V_126 )
continue;
V_12 = V_127 ;
V_116 = F_68 ( V_115 , L_14 , & V_40 ) ;
if ( V_116 && V_40 >= sizeof( * V_116 ) ) {
V_12 &= ~ ( F_70 ( 0xf ) ) ;
V_12 |= F_70 ( F_69 ( V_116 ) ) ;
}
V_116 = F_68 ( V_115 , L_15 , & V_40 ) ;
if ( V_116 && V_40 >= sizeof( * V_116 ) ) {
V_12 &= ~ ( F_71 ( 0xf ) ) ;
V_12 |= F_71 ( F_69 ( V_116 ) ) ;
}
F_5 ( & V_10 -> V_12 [ V_72 ] , V_12 ) ;
F_72 ( V_39 , L_16 , V_72 , V_12 ) ;
}
V_109 = V_113 -> V_128 | V_129 | V_17 ;
F_5 ( & V_10 -> V_11 , V_109 ) ;
F_73 ( V_39 , V_130 ) ;
F_74 ( V_39 ) ;
F_75 ( V_39 ) ;
F_76 ( V_39 ) ;
F_41 ( V_39 ) ;
V_46 = F_77 ( V_39 , V_5 ) ;
if ( V_46 < 0 )
goto V_131;
F_72 ( V_39 , L_17 , V_10 , V_3 -> V_103 ) ;
F_42 ( V_39 ) ;
F_43 ( V_39 ) ;
return V_5 ;
V_131:
F_78 ( V_39 ) ;
F_79 ( V_39 ) ;
F_80 ( V_39 ) ;
V_124:
F_81 ( V_5 ) ;
V_117:
return F_82 ( V_46 ) ;
}
static int F_83 ( struct V_108 * V_39 )
{
struct V_114 * V_132 = V_39 -> V_133 ;
struct V_112 * V_113 = F_58 ( V_39 ) ;
const T_3 * V_116 ;
int V_40 ;
V_116 = F_68 ( V_132 , L_18 , & V_40 ) ;
if ( ! V_116 || V_40 < sizeof( * V_116 ) ) {
F_19 ( V_39 , L_19 ) ;
return - V_52 ;
}
V_113 -> V_126 = * V_116 ;
V_113 -> V_134 = NULL ;
return 0 ;
}
static int F_84 ( struct V_135 * V_136 )
{
struct V_108 * V_39 = & V_136 -> V_39 ;
struct V_114 * V_132 = V_136 -> V_39 . V_133 ;
struct V_82 * V_5 ;
struct V_110 V_111 ;
unsigned int V_103 ;
int V_46 = - V_74 ;
V_46 = F_85 ( V_136 ) ;
if ( V_46 )
return V_46 ;
V_46 = F_83 ( V_39 ) ;
if ( V_46 )
goto V_117;
V_46 = F_86 ( V_132 , 0 , & V_111 ) ;
if ( V_46 )
goto V_117;
V_103 = F_87 ( V_132 , 0 ) ;
if ( ! V_103 ) {
V_46 = - V_52 ;
goto V_117;
}
V_5 = F_57 ( V_39 , & V_111 , V_103 ) ;
if ( F_64 ( V_5 ) ) {
V_46 = F_65 ( V_5 ) ;
goto V_117;
}
return 0 ;
V_117:
return V_46 ;
}
static int F_88 ( struct V_135 * V_39 )
{
F_79 ( & V_39 -> V_39 ) ;
return 0 ;
}
static int F_89 ( struct V_108 * V_39 )
{
struct V_82 * V_5 = F_54 ( V_39 ) ;
int V_46 ;
V_46 = F_90 ( V_5 ) ;
if ( V_46 ) {
F_91 ( V_39 , L_20 ) ;
return V_46 ;
}
V_46 = F_92 ( V_39 ) ;
if ( V_46 < 0 )
return V_46 ;
return 0 ;
}
static int F_93 ( struct V_108 * V_39 )
{
struct V_112 * V_113 = F_58 ( V_39 ) ;
struct V_82 * V_5 = F_54 ( V_39 ) ;
struct V_3 * V_3 ;
struct V_9 * V_10 ;
T_3 V_109 ;
int V_72 , V_46 ;
V_3 = F_2 ( V_5 ) ;
V_10 = V_3 -> V_10 ;
F_5 ( & V_10 -> V_11 , 0 ) ;
F_5 ( & V_10 -> V_43 , 0 ) ;
F_5 ( & V_10 -> V_53 , 0 ) ;
F_5 ( & V_10 -> V_100 , 0xffffffff ) ;
for ( V_72 = 0 ; V_72 < V_113 -> V_126 ; V_72 ++ )
F_5 ( & V_10 -> V_12 [ V_72 ] , V_127 ) ;
V_109 = V_113 -> V_128 | V_129 | V_17 ;
F_5 ( & V_10 -> V_11 , V_109 ) ;
V_46 = F_94 ( V_39 ) ;
if ( V_46 < 0 )
return V_46 ;
return F_95 ( V_5 ) ;
}
