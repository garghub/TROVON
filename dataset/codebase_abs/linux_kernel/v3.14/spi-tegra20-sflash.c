static inline T_1 F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_5 , unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_6 | V_7 , V_8 ) ;
}
static unsigned F_6 (
struct V_9 * V_10 , struct V_1 * V_2 ,
struct V_11 * V_12 )
{
unsigned V_13 = V_12 -> V_14 - V_2 -> V_15 ;
unsigned V_16 ;
V_2 -> V_17 = F_7 ( V_12 -> V_18 , 8 ) ;
V_16 = V_13 / V_2 -> V_17 ;
if ( V_16 > V_19 )
V_16 = V_19 ;
V_2 -> V_20 = V_16 ;
return V_16 ;
}
static unsigned F_8 (
struct V_1 * V_2 , struct V_11 * V_12 )
{
unsigned V_21 ;
T_1 V_22 ;
unsigned V_23 = V_2 -> V_20 ;
T_2 * V_24 = ( T_2 * ) V_12 -> V_24 + V_2 -> V_25 ;
if ( V_23 > V_19 )
V_23 = V_19 ;
V_21 = V_23 * V_2 -> V_17 ;
V_22 = F_1 ( V_2 , V_8 ) ;
while ( ! ( V_22 & V_26 ) ) {
int V_27 ;
T_1 V_28 = 0 ;
for ( V_27 = 0 ; V_21 && ( V_27 < V_2 -> V_17 ) ;
V_27 ++ , V_21 -- )
V_28 |= ( T_1 ) ( * V_24 ++ ) << ( V_27 * 8 ) ;
F_3 ( V_2 , V_28 , V_29 ) ;
if ( ! V_21 )
break;
V_22 = F_1 ( V_2 , V_8 ) ;
}
V_2 -> V_25 += V_23 * V_2 -> V_17 ;
return V_23 ;
}
static int F_9 (
struct V_1 * V_2 , struct V_11 * V_12 )
{
T_1 V_22 ;
unsigned int V_30 = 0 ;
T_2 * V_31 = ( T_2 * ) V_12 -> V_31 + V_2 -> V_32 ;
V_22 = F_1 ( V_2 , V_8 ) ;
while ( ! ( V_22 & V_33 ) ) {
int V_27 ;
T_1 V_28 = F_1 ( V_2 , V_34 ) ;
for ( V_27 = 0 ; ( V_27 < V_2 -> V_17 ) ; V_27 ++ )
* V_31 ++ = ( V_28 >> ( V_27 * 8 ) ) & 0xFF ;
V_30 ++ ;
V_22 = F_1 ( V_2 , V_8 ) ;
}
V_2 -> V_32 += V_30 * V_2 -> V_17 ;
return 0 ;
}
static int F_10 (
struct V_1 * V_2 , struct V_11 * V_12 )
{
T_1 V_5 = 0 ;
unsigned V_35 ;
if ( V_2 -> V_36 & V_37 )
V_5 |= V_38 ;
if ( V_2 -> V_36 & V_39 )
V_5 |= V_40 ;
F_3 ( V_2 , V_5 , V_41 ) ;
V_2 -> V_42 = V_5 ;
if ( V_2 -> V_36 & V_37 )
V_35 = F_8 ( V_2 , V_12 ) ;
else
V_35 = V_2 -> V_20 ;
V_5 |= F_11 ( V_35 ) ;
F_3 ( V_2 , V_5 , V_41 ) ;
V_2 -> V_42 = V_5 ;
V_5 |= V_43 ;
F_3 ( V_2 , V_5 , V_41 ) ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
struct V_11 * V_12 , bool V_44 ,
bool V_45 )
{
struct V_1 * V_2 = F_13 ( V_10 -> V_46 ) ;
T_1 V_47 ;
T_1 V_48 ;
V_47 = V_12 -> V_49 ;
if ( V_47 != V_2 -> V_50 ) {
F_14 ( V_2 -> V_51 , V_47 ) ;
V_2 -> V_50 = V_47 ;
}
V_2 -> V_52 = V_10 ;
V_2 -> V_15 = 0 ;
V_2 -> V_32 = 0 ;
V_2 -> V_25 = 0 ;
V_2 -> V_53 = V_12 ;
F_6 ( V_10 , V_2 , V_12 ) ;
if ( V_44 ) {
V_48 = V_2 -> V_54 ;
V_48 |= F_15 ( V_12 -> V_18 - 1 ) ;
V_48 |= V_55 ;
V_48 &= ~ V_56 ;
if ( V_10 -> V_57 & V_58 )
V_48 |= V_59 ;
if ( V_10 -> V_57 & V_60 )
V_48 |= V_61 ;
else
V_48 |= V_62 ;
V_48 |= V_63 << V_10 -> V_64 ;
} else {
V_48 = V_2 -> V_65 ;
V_48 &= ~ F_15 ( ~ 0 ) ;
V_48 |= F_15 ( V_12 -> V_18 - 1 ) ;
V_48 &= ~ ( V_66 | V_67 ) ;
}
V_2 -> V_36 = 0 ;
if ( V_12 -> V_31 ) {
V_48 |= V_66 ;
V_2 -> V_36 |= V_39 ;
}
if ( V_12 -> V_24 ) {
V_48 |= V_67 ;
V_2 -> V_36 |= V_37 ;
}
F_3 ( V_2 , V_48 , V_68 ) ;
V_2 -> V_65 = V_48 ;
return F_10 ( V_2 , V_12 ) ;
}
static int F_16 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_10 -> V_46 ) ;
V_10 -> V_69 = V_10 -> V_69 ? : V_2 -> V_70 ;
return 0 ;
}
static int F_17 ( struct V_71 * V_46 ,
struct V_72 * V_73 )
{
bool V_74 = true ;
int V_75 ;
struct V_1 * V_2 = F_13 ( V_46 ) ;
struct V_11 * V_76 ;
struct V_9 * V_10 = V_73 -> V_10 ;
int V_77 ;
V_73 -> V_22 = 0 ;
V_73 -> V_78 = 0 ;
V_75 = F_18 ( & V_73 -> V_79 ) ;
F_19 (xfer, &msg->transfers, transfer_list) {
F_20 ( & V_2 -> V_80 ) ;
V_77 = F_12 ( V_10 , V_76 ,
V_74 , V_75 ) ;
if ( V_77 < 0 ) {
F_21 ( V_2 -> V_81 ,
L_1 , V_77 ) ;
goto exit;
}
V_74 = false ;
V_77 = F_22 ( & V_2 -> V_80 ,
V_82 ) ;
if ( F_23 ( V_77 == 0 ) ) {
F_21 ( V_2 -> V_81 ,
L_2 , V_77 ) ;
V_77 = - V_83 ;
goto exit;
}
if ( V_2 -> V_84 || V_2 -> V_85 ) {
F_21 ( V_2 -> V_81 , L_3 ) ;
V_77 = - V_83 ;
goto exit;
}
V_73 -> V_78 += V_76 -> V_14 ;
if ( V_76 -> V_86 && V_76 -> V_87 ) {
F_3 ( V_2 , V_2 -> V_54 ,
V_68 ) ;
F_24 ( V_76 -> V_87 ) ;
}
}
V_77 = 0 ;
exit:
F_3 ( V_2 , V_2 -> V_54 , V_68 ) ;
V_73 -> V_22 = V_77 ;
F_25 ( V_46 ) ;
return V_77 ;
}
static T_3 F_26 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_53 ;
unsigned long V_88 ;
F_27 ( & V_2 -> V_89 , V_88 ) ;
if ( V_2 -> V_84 || V_2 -> V_85 || ( V_2 -> V_90 & V_91 ) ) {
F_21 ( V_2 -> V_81 ,
L_4 , V_2 -> V_90 ) ;
F_21 ( V_2 -> V_81 ,
L_5 , V_2 -> V_65 ,
V_2 -> V_42 ) ;
F_28 ( V_2 -> V_92 ) ;
F_24 ( 2 ) ;
F_29 ( V_2 -> V_92 ) ;
F_30 ( & V_2 -> V_80 ) ;
goto exit;
}
if ( V_2 -> V_36 & V_39 )
F_9 ( V_2 , V_12 ) ;
if ( V_2 -> V_36 & V_37 )
V_2 -> V_15 = V_2 -> V_25 ;
else
V_2 -> V_15 = V_2 -> V_32 ;
if ( V_2 -> V_15 == V_12 -> V_14 ) {
F_30 ( & V_2 -> V_80 ) ;
goto exit;
}
F_6 ( V_2 -> V_52 , V_2 , V_12 ) ;
F_10 ( V_2 , V_12 ) ;
exit:
F_31 ( & V_2 -> V_89 , V_88 ) ;
return V_93 ;
}
static T_3 F_32 ( int V_94 , void * V_95 )
{
struct V_1 * V_2 = V_95 ;
V_2 -> V_90 = F_1 ( V_2 , V_8 ) ;
if ( V_2 -> V_36 & V_37 )
V_2 -> V_84 = V_2 -> V_90 & V_96 ;
if ( V_2 -> V_36 & V_39 )
V_2 -> V_85 = V_2 -> V_90 & V_97 ;
F_5 ( V_2 ) ;
return F_26 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_98 * V_99 = V_2 -> V_81 -> V_100 ;
if ( F_34 ( V_99 , L_6 ,
& V_2 -> V_70 ) )
V_2 -> V_70 = 25000000 ;
}
static int F_35 ( struct V_101 * V_102 )
{
struct V_71 * V_46 ;
struct V_1 * V_2 ;
struct V_103 * V_104 ;
int V_77 ;
const struct V_105 * V_106 ;
V_106 = F_36 ( V_107 , & V_102 -> V_81 ) ;
if ( ! V_106 ) {
F_21 ( & V_102 -> V_81 , L_7 ) ;
return - V_108 ;
}
V_46 = F_37 ( & V_102 -> V_81 , sizeof( * V_2 ) ) ;
if ( ! V_46 ) {
F_21 ( & V_102 -> V_81 , L_8 ) ;
return - V_109 ;
}
V_46 -> V_110 = V_60 | V_58 ;
V_46 -> V_111 = F_16 ;
V_46 -> V_112 = F_17 ;
V_46 -> V_113 = true ;
V_46 -> V_114 = V_115 ;
V_46 -> V_116 = - 1 ;
F_38 ( V_102 , V_46 ) ;
V_2 = F_13 ( V_46 ) ;
V_2 -> V_46 = V_46 ;
V_2 -> V_81 = & V_102 -> V_81 ;
F_39 ( & V_2 -> V_89 ) ;
F_33 ( V_2 ) ;
V_104 = F_40 ( V_102 , V_117 , 0 ) ;
V_2 -> V_4 = F_41 ( & V_102 -> V_81 , V_104 ) ;
if ( F_42 ( V_2 -> V_4 ) ) {
V_77 = F_43 ( V_2 -> V_4 ) ;
goto V_118;
}
V_2 -> V_94 = F_44 ( V_102 , 0 ) ;
V_77 = F_45 ( V_2 -> V_94 , F_32 , 0 ,
F_46 ( & V_102 -> V_81 ) , V_2 ) ;
if ( V_77 < 0 ) {
F_21 ( & V_102 -> V_81 , L_9 ,
V_2 -> V_94 ) ;
goto V_118;
}
V_2 -> V_51 = F_47 ( & V_102 -> V_81 , NULL ) ;
if ( F_42 ( V_2 -> V_51 ) ) {
F_21 ( & V_102 -> V_81 , L_10 ) ;
V_77 = F_43 ( V_2 -> V_51 ) ;
goto V_119;
}
V_2 -> V_92 = F_48 ( & V_102 -> V_81 , L_11 ) ;
if ( F_42 ( V_2 -> V_92 ) ) {
F_21 ( & V_102 -> V_81 , L_12 ) ;
V_77 = F_43 ( V_2 -> V_92 ) ;
goto V_119;
}
F_49 ( & V_2 -> V_80 ) ;
F_50 ( & V_102 -> V_81 ) ;
if ( ! F_51 ( & V_102 -> V_81 ) ) {
V_77 = F_52 ( & V_102 -> V_81 ) ;
if ( V_77 )
goto V_120;
}
V_77 = F_53 ( & V_102 -> V_81 ) ;
if ( V_77 < 0 ) {
F_21 ( & V_102 -> V_81 , L_13 , V_77 ) ;
goto V_120;
}
F_28 ( V_2 -> V_92 ) ;
F_24 ( 2 ) ;
F_29 ( V_2 -> V_92 ) ;
V_2 -> V_54 = V_121 | V_122 ;
F_3 ( V_2 , V_2 -> V_54 , V_68 ) ;
F_54 ( & V_102 -> V_81 ) ;
V_46 -> V_81 . V_100 = V_102 -> V_81 . V_100 ;
V_77 = F_55 ( & V_102 -> V_81 , V_46 ) ;
if ( V_77 < 0 ) {
F_21 ( & V_102 -> V_81 , L_14 , V_77 ) ;
goto V_120;
}
return V_77 ;
V_120:
F_56 ( & V_102 -> V_81 ) ;
if ( ! F_57 ( & V_102 -> V_81 ) )
F_58 ( & V_102 -> V_81 ) ;
V_119:
F_59 ( V_2 -> V_94 , V_2 ) ;
V_118:
F_60 ( V_46 ) ;
return V_77 ;
}
static int F_61 ( struct V_101 * V_102 )
{
struct V_71 * V_46 = F_62 ( V_102 ) ;
struct V_1 * V_2 = F_13 ( V_46 ) ;
F_59 ( V_2 -> V_94 , V_2 ) ;
F_56 ( & V_102 -> V_81 ) ;
if ( ! F_57 ( & V_102 -> V_81 ) )
F_58 ( & V_102 -> V_81 ) ;
return 0 ;
}
static int F_63 ( struct V_123 * V_81 )
{
struct V_71 * V_46 = F_64 ( V_81 ) ;
return F_65 ( V_46 ) ;
}
static int F_66 ( struct V_123 * V_81 )
{
struct V_71 * V_46 = F_64 ( V_81 ) ;
struct V_1 * V_2 = F_13 ( V_46 ) ;
int V_77 ;
V_77 = F_53 ( V_81 ) ;
if ( V_77 < 0 ) {
F_21 ( V_81 , L_15 , V_77 ) ;
return V_77 ;
}
F_3 ( V_2 , V_2 -> V_65 , V_68 ) ;
F_54 ( V_81 ) ;
return F_67 ( V_46 ) ;
}
static int F_58 ( struct V_123 * V_81 )
{
struct V_71 * V_46 = F_64 ( V_81 ) ;
struct V_1 * V_2 = F_13 ( V_46 ) ;
F_1 ( V_2 , V_68 ) ;
F_68 ( V_2 -> V_51 ) ;
return 0 ;
}
static int F_52 ( struct V_123 * V_81 )
{
struct V_71 * V_46 = F_64 ( V_81 ) ;
struct V_1 * V_2 = F_13 ( V_46 ) ;
int V_77 ;
V_77 = F_69 ( V_2 -> V_51 ) ;
if ( V_77 < 0 ) {
F_21 ( V_2 -> V_81 , L_16 , V_77 ) ;
return V_77 ;
}
return 0 ;
}
