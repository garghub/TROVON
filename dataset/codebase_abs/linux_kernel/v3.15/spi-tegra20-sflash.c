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
static int F_16 ( struct V_69 * V_46 ,
struct V_70 * V_71 )
{
bool V_72 = true ;
int V_73 ;
struct V_1 * V_2 = F_13 ( V_46 ) ;
struct V_11 * V_74 ;
struct V_9 * V_10 = V_71 -> V_10 ;
int V_75 ;
V_71 -> V_22 = 0 ;
V_71 -> V_76 = 0 ;
V_73 = F_17 ( & V_71 -> V_77 ) ;
F_18 (xfer, &msg->transfers, transfer_list) {
F_19 ( & V_2 -> V_78 ) ;
V_75 = F_12 ( V_10 , V_74 ,
V_72 , V_73 ) ;
if ( V_75 < 0 ) {
F_20 ( V_2 -> V_79 ,
L_1 , V_75 ) ;
goto exit;
}
V_72 = false ;
V_75 = F_21 ( & V_2 -> V_78 ,
V_80 ) ;
if ( F_22 ( V_75 == 0 ) ) {
F_20 ( V_2 -> V_79 ,
L_2 , V_75 ) ;
V_75 = - V_81 ;
goto exit;
}
if ( V_2 -> V_82 || V_2 -> V_83 ) {
F_20 ( V_2 -> V_79 , L_3 ) ;
V_75 = - V_81 ;
goto exit;
}
V_71 -> V_76 += V_74 -> V_14 ;
if ( V_74 -> V_84 && V_74 -> V_85 ) {
F_3 ( V_2 , V_2 -> V_54 ,
V_68 ) ;
F_23 ( V_74 -> V_85 ) ;
}
}
V_75 = 0 ;
exit:
F_3 ( V_2 , V_2 -> V_54 , V_68 ) ;
V_71 -> V_22 = V_75 ;
F_24 ( V_46 ) ;
return V_75 ;
}
static T_3 F_25 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_53 ;
unsigned long V_86 ;
F_26 ( & V_2 -> V_87 , V_86 ) ;
if ( V_2 -> V_82 || V_2 -> V_83 || ( V_2 -> V_88 & V_89 ) ) {
F_20 ( V_2 -> V_79 ,
L_4 , V_2 -> V_88 ) ;
F_20 ( V_2 -> V_79 ,
L_5 , V_2 -> V_65 ,
V_2 -> V_42 ) ;
F_27 ( V_2 -> V_90 ) ;
F_23 ( 2 ) ;
F_28 ( V_2 -> V_90 ) ;
F_29 ( & V_2 -> V_78 ) ;
goto exit;
}
if ( V_2 -> V_36 & V_39 )
F_9 ( V_2 , V_12 ) ;
if ( V_2 -> V_36 & V_37 )
V_2 -> V_15 = V_2 -> V_25 ;
else
V_2 -> V_15 = V_2 -> V_32 ;
if ( V_2 -> V_15 == V_12 -> V_14 ) {
F_29 ( & V_2 -> V_78 ) ;
goto exit;
}
F_6 ( V_2 -> V_52 , V_2 , V_12 ) ;
F_10 ( V_2 , V_12 ) ;
exit:
F_30 ( & V_2 -> V_87 , V_86 ) ;
return V_91 ;
}
static T_3 F_31 ( int V_92 , void * V_93 )
{
struct V_1 * V_2 = V_93 ;
V_2 -> V_88 = F_1 ( V_2 , V_8 ) ;
if ( V_2 -> V_36 & V_37 )
V_2 -> V_82 = V_2 -> V_88 & V_94 ;
if ( V_2 -> V_36 & V_39 )
V_2 -> V_83 = V_2 -> V_88 & V_95 ;
F_5 ( V_2 ) ;
return F_25 ( V_2 ) ;
}
static int F_32 ( struct V_96 * V_97 )
{
struct V_69 * V_46 ;
struct V_1 * V_2 ;
struct V_98 * V_99 ;
int V_75 ;
const struct V_100 * V_101 ;
V_101 = F_33 ( V_102 , & V_97 -> V_79 ) ;
if ( ! V_101 ) {
F_20 ( & V_97 -> V_79 , L_6 ) ;
return - V_103 ;
}
V_46 = F_34 ( & V_97 -> V_79 , sizeof( * V_2 ) ) ;
if ( ! V_46 ) {
F_20 ( & V_97 -> V_79 , L_7 ) ;
return - V_104 ;
}
V_46 -> V_105 = V_60 | V_58 ;
V_46 -> V_106 = F_16 ;
V_46 -> V_107 = true ;
V_46 -> V_108 = V_109 ;
F_35 ( V_97 , V_46 ) ;
V_2 = F_13 ( V_46 ) ;
V_2 -> V_46 = V_46 ;
V_2 -> V_79 = & V_97 -> V_79 ;
F_36 ( & V_2 -> V_87 ) ;
if ( F_37 ( V_2 -> V_79 -> V_110 , L_8 ,
& V_46 -> V_111 ) )
V_46 -> V_111 = 25000000 ;
V_99 = F_38 ( V_97 , V_112 , 0 ) ;
V_2 -> V_4 = F_39 ( & V_97 -> V_79 , V_99 ) ;
if ( F_40 ( V_2 -> V_4 ) ) {
V_75 = F_41 ( V_2 -> V_4 ) ;
goto V_113;
}
V_2 -> V_92 = F_42 ( V_97 , 0 ) ;
V_75 = F_43 ( V_2 -> V_92 , F_31 , 0 ,
F_44 ( & V_97 -> V_79 ) , V_2 ) ;
if ( V_75 < 0 ) {
F_20 ( & V_97 -> V_79 , L_9 ,
V_2 -> V_92 ) ;
goto V_113;
}
V_2 -> V_51 = F_45 ( & V_97 -> V_79 , NULL ) ;
if ( F_40 ( V_2 -> V_51 ) ) {
F_20 ( & V_97 -> V_79 , L_10 ) ;
V_75 = F_41 ( V_2 -> V_51 ) ;
goto V_114;
}
V_2 -> V_90 = F_46 ( & V_97 -> V_79 , L_11 ) ;
if ( F_40 ( V_2 -> V_90 ) ) {
F_20 ( & V_97 -> V_79 , L_12 ) ;
V_75 = F_41 ( V_2 -> V_90 ) ;
goto V_114;
}
F_47 ( & V_2 -> V_78 ) ;
F_48 ( & V_97 -> V_79 ) ;
if ( ! F_49 ( & V_97 -> V_79 ) ) {
V_75 = F_50 ( & V_97 -> V_79 ) ;
if ( V_75 )
goto V_115;
}
V_75 = F_51 ( & V_97 -> V_79 ) ;
if ( V_75 < 0 ) {
F_20 ( & V_97 -> V_79 , L_13 , V_75 ) ;
goto V_115;
}
F_27 ( V_2 -> V_90 ) ;
F_23 ( 2 ) ;
F_28 ( V_2 -> V_90 ) ;
V_2 -> V_54 = V_116 | V_117 ;
F_3 ( V_2 , V_2 -> V_54 , V_68 ) ;
F_52 ( & V_97 -> V_79 ) ;
V_46 -> V_79 . V_110 = V_97 -> V_79 . V_110 ;
V_75 = F_53 ( & V_97 -> V_79 , V_46 ) ;
if ( V_75 < 0 ) {
F_20 ( & V_97 -> V_79 , L_14 , V_75 ) ;
goto V_115;
}
return V_75 ;
V_115:
F_54 ( & V_97 -> V_79 ) ;
if ( ! F_55 ( & V_97 -> V_79 ) )
F_56 ( & V_97 -> V_79 ) ;
V_114:
F_57 ( V_2 -> V_92 , V_2 ) ;
V_113:
F_58 ( V_46 ) ;
return V_75 ;
}
static int F_59 ( struct V_96 * V_97 )
{
struct V_69 * V_46 = F_60 ( V_97 ) ;
struct V_1 * V_2 = F_13 ( V_46 ) ;
F_57 ( V_2 -> V_92 , V_2 ) ;
F_54 ( & V_97 -> V_79 ) ;
if ( ! F_55 ( & V_97 -> V_79 ) )
F_56 ( & V_97 -> V_79 ) ;
return 0 ;
}
static int F_61 ( struct V_118 * V_79 )
{
struct V_69 * V_46 = F_62 ( V_79 ) ;
return F_63 ( V_46 ) ;
}
static int F_64 ( struct V_118 * V_79 )
{
struct V_69 * V_46 = F_62 ( V_79 ) ;
struct V_1 * V_2 = F_13 ( V_46 ) ;
int V_75 ;
V_75 = F_51 ( V_79 ) ;
if ( V_75 < 0 ) {
F_20 ( V_79 , L_15 , V_75 ) ;
return V_75 ;
}
F_3 ( V_2 , V_2 -> V_65 , V_68 ) ;
F_52 ( V_79 ) ;
return F_65 ( V_46 ) ;
}
static int F_56 ( struct V_118 * V_79 )
{
struct V_69 * V_46 = F_62 ( V_79 ) ;
struct V_1 * V_2 = F_13 ( V_46 ) ;
F_1 ( V_2 , V_68 ) ;
F_66 ( V_2 -> V_51 ) ;
return 0 ;
}
static int F_50 ( struct V_118 * V_79 )
{
struct V_69 * V_46 = F_62 ( V_79 ) ;
struct V_1 * V_2 = F_13 ( V_46 ) ;
int V_75 ;
V_75 = F_67 ( V_2 -> V_51 ) ;
if ( V_75 < 0 ) {
F_20 ( V_2 -> V_79 , L_16 , V_75 ) ;
return V_75 ;
}
return 0 ;
}
