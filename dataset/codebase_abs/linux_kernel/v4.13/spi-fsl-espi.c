static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_3 F_5 ( struct V_1 * V_2 , int V_3 )
{
return F_6 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , int V_3 ,
T_1 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , int V_3 ,
T_2 V_5 )
{
F_10 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , int V_3 ,
T_3 V_5 )
{
F_12 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_14 ( V_7 -> V_8 -> V_9 ) ;
struct V_10 * V_11 , * V_12 ;
if ( V_7 -> V_13 > V_14 ) {
F_15 ( V_2 -> V_15 , L_1 ,
V_7 -> V_13 ) ;
return - V_16 ;
}
V_12 = F_16 ( & V_7 -> V_17 , struct V_10 ,
V_18 ) ;
F_17 (t, &m->transfers, transfer_list) {
if ( V_12 -> V_19 != V_11 -> V_19 ||
V_12 -> V_20 != V_11 -> V_20 ) {
F_15 ( V_2 -> V_15 , L_2 ) ;
return - V_21 ;
}
}
if ( ! ( V_7 -> V_8 -> V_22 & V_23 ) && V_12 -> V_19 != 8 &&
V_12 -> V_19 != 16 ) {
F_15 ( V_2 -> V_15 ,
L_3 ,
V_12 -> V_19 ) ;
return - V_21 ;
}
return 0 ;
}
static unsigned int F_18 ( struct V_6 * V_7 )
{
struct V_10 * V_11 ;
unsigned int V_24 = 0 , V_25 = 0 ;
F_17 (t, &m->transfers, transfer_list) {
if ( V_24 == 0 ) {
if ( ! V_11 -> V_26 || V_11 -> V_27 ||
V_11 -> V_28 > V_29 )
return 0 ;
V_25 = V_11 -> V_28 ;
} else if ( V_24 == 1 ) {
if ( V_11 -> V_26 || ! V_11 -> V_27 )
return 0 ;
}
V_24 ++ ;
}
return V_24 == 2 ? V_25 : 0 ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_30 )
{
T_1 V_31 ;
unsigned int V_32 ;
const void * V_26 ;
V_31 = V_30 ? F_20 ( V_30 ) : V_29 ;
V_33:
V_32 = V_2 -> V_34 -> V_28 - V_2 -> V_35 ;
V_26 = V_2 -> V_34 -> V_26 ;
while ( V_31 >= F_21 ( 4U , V_32 ) && V_32 ) {
if ( V_32 >= 4 ) {
if ( ! V_26 )
F_7 ( V_2 , V_36 , 0 ) ;
else if ( V_2 -> V_37 )
F_7 ( V_2 , V_36 ,
F_22 ( V_26 + V_2 -> V_35 ) ) ;
else
F_7 ( V_2 , V_36 ,
* ( T_1 * ) ( V_26 + V_2 -> V_35 ) ) ;
V_2 -> V_35 += 4 ;
V_32 -= 4 ;
V_31 -= 4 ;
} else if ( V_32 >= 2 && V_26 && V_2 -> V_37 ) {
F_9 ( V_2 , V_36 ,
F_23 ( V_26 + V_2 -> V_35 ) ) ;
V_2 -> V_35 += 2 ;
V_32 -= 2 ;
V_31 -= 2 ;
} else {
if ( ! V_26 )
F_11 ( V_2 , V_36 , 0 ) ;
else
F_11 ( V_2 , V_36 ,
* ( T_3 * ) ( V_26 + V_2 -> V_35 ) ) ;
V_2 -> V_35 += 1 ;
V_32 -= 1 ;
V_31 -= 1 ;
}
}
if ( ! V_32 ) {
if ( F_24 ( & V_2 -> V_34 -> V_18 ,
V_2 -> V_38 ) || V_2 -> V_25 ) {
V_2 -> V_39 = true ;
return;
}
V_2 -> V_34 = F_25 ( V_2 -> V_34 , V_18 ) ;
V_2 -> V_35 = 0 ;
if ( V_31 )
goto V_33;
}
}
static void F_26 ( struct V_1 * V_2 , T_1 V_30 )
{
T_1 V_40 = F_27 ( V_30 ) ;
unsigned int V_41 ;
void * V_27 ;
V_33:
V_41 = V_2 -> V_42 -> V_28 - V_2 -> V_43 ;
V_27 = V_2 -> V_42 -> V_27 ;
while ( V_40 >= F_21 ( 4U , V_41 ) && V_41 ) {
if ( V_41 >= 4 ) {
T_1 V_5 = F_1 ( V_2 , V_44 ) ;
if ( V_27 && V_2 -> V_37 )
* ( T_1 * ) ( V_27 + V_2 -> V_43 ) = F_28 ( V_5 ) ;
else if ( V_27 )
* ( T_1 * ) ( V_27 + V_2 -> V_43 ) = V_5 ;
V_2 -> V_43 += 4 ;
V_41 -= 4 ;
V_40 -= 4 ;
} else if ( V_41 >= 2 && V_27 && V_2 -> V_37 ) {
T_2 V_5 = F_3 ( V_2 , V_44 ) ;
* ( T_2 * ) ( V_27 + V_2 -> V_43 ) = F_29 ( V_5 ) ;
V_2 -> V_43 += 2 ;
V_41 -= 2 ;
V_40 -= 2 ;
} else {
T_3 V_5 = F_5 ( V_2 , V_44 ) ;
if ( V_27 )
* ( T_3 * ) ( V_27 + V_2 -> V_43 ) = V_5 ;
V_2 -> V_43 += 1 ;
V_41 -= 1 ;
V_40 -= 1 ;
}
}
if ( ! V_41 ) {
if ( F_24 ( & V_2 -> V_42 -> V_18 ,
V_2 -> V_38 ) ) {
V_2 -> V_45 = true ;
return;
}
V_2 -> V_42 = F_25 ( V_2 -> V_42 , V_18 ) ;
V_2 -> V_43 = 0 ;
if ( V_40 )
goto V_33;
}
}
static void F_30 ( struct V_46 * V_8 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = F_14 ( V_8 -> V_9 ) ;
int V_19 = V_11 ? V_11 -> V_19 : V_8 -> V_19 ;
T_1 V_47 , V_48 = V_11 ? V_11 -> V_20 : V_8 -> V_49 ;
struct V_50 * V_51 = F_31 ( V_8 ) ;
T_1 V_52 = V_51 -> V_53 ;
V_51 -> V_53 &= ~ ( F_32 ( 0xF ) | V_54 | F_33 ( 0xF ) ) ;
V_51 -> V_53 |= F_32 ( V_19 - 1 ) ;
V_47 = F_34 ( V_2 -> V_55 , V_48 * 4 ) - 1 ;
if ( V_47 > 15 ) {
V_51 -> V_53 |= V_54 ;
V_47 = F_34 ( V_2 -> V_55 , V_48 * 16 * 4 ) - 1 ;
}
V_51 -> V_53 |= F_33 ( V_47 ) ;
if ( V_51 -> V_53 != V_52 )
F_7 ( V_2 , F_35 ( V_8 -> V_56 ) ,
V_51 -> V_53 ) ;
}
static int F_36 ( struct V_46 * V_8 , struct V_10 * V_11 )
{
struct V_1 * V_2 = F_14 ( V_8 -> V_9 ) ;
unsigned int V_57 = V_11 -> V_28 ;
T_1 V_58 , V_59 ;
int V_60 ;
F_37 ( & V_2 -> V_61 ) ;
V_59 = F_38 ( V_8 -> V_56 ) ;
V_59 |= F_39 ( V_11 -> V_28 - 1 ) ;
if ( V_2 -> V_25 ) {
V_59 |= F_40 ( V_2 -> V_25 ) ;
V_57 = V_11 -> V_28 - V_2 -> V_25 ;
if ( V_11 -> V_62 == V_63 )
V_59 |= V_64 ;
}
F_7 ( V_2 , V_65 , V_59 ) ;
V_58 = V_66 ;
if ( V_57 > V_29 )
V_58 |= V_67 ;
F_7 ( V_2 , V_68 , V_58 ) ;
F_41 ( & V_2 -> V_69 ) ;
F_19 ( V_2 , 0 ) ;
F_42 ( & V_2 -> V_69 ) ;
V_60 = F_43 ( & V_2 -> V_61 , 2 * V_70 ) ;
if ( V_60 == 0 )
F_15 ( V_2 -> V_15 , L_4 ) ;
F_7 ( V_2 , V_68 , 0 ) ;
return V_60 == 0 ? - V_71 : 0 ;
}
static int F_44 ( struct V_6 * V_7 , struct V_10 * V_72 )
{
struct V_1 * V_2 = F_14 ( V_7 -> V_8 -> V_9 ) ;
struct V_46 * V_8 = V_7 -> V_8 ;
int V_60 ;
V_2 -> V_37 = V_8 -> V_22 & V_23 && V_72 -> V_19 > 8 ;
V_2 -> V_38 = & V_7 -> V_17 ;
V_2 -> V_34 = F_16 ( & V_7 -> V_17 , struct V_10 ,
V_18 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_39 = false ;
V_2 -> V_42 = F_16 ( & V_7 -> V_17 , struct V_10 ,
V_18 ) ;
V_2 -> V_43 = 0 ;
V_2 -> V_45 = false ;
V_2 -> V_25 = F_18 ( V_7 ) ;
if ( V_72 -> V_62 == V_63 && ! V_2 -> V_25 ) {
F_15 ( V_2 -> V_15 , L_5 ) ;
return - V_21 ;
}
if ( V_2 -> V_25 )
V_2 -> V_42 = F_25 ( V_2 -> V_42 , V_18 ) ;
F_30 ( V_8 , V_72 ) ;
V_60 = F_36 ( V_8 , V_72 ) ;
if ( V_72 -> V_73 )
F_45 ( V_72 -> V_73 ) ;
return V_60 ;
}
static int F_46 ( struct V_74 * V_9 ,
struct V_6 * V_7 )
{
unsigned int V_73 = 0 , V_62 = 0 ;
struct V_10 * V_11 , V_72 = {} ;
int V_60 ;
V_60 = F_13 ( V_7 ) ;
if ( V_60 )
goto V_75;
F_17 (t, &m->transfers, transfer_list) {
if ( V_11 -> V_73 > V_73 )
V_73 = V_11 -> V_73 ;
if ( V_11 -> V_62 > V_62 )
V_62 = V_11 -> V_62 ;
}
V_11 = F_16 ( & V_7 -> V_17 , struct V_10 ,
V_18 ) ;
V_72 . V_28 = V_7 -> V_13 ;
V_72 . V_20 = V_11 -> V_20 ;
V_72 . V_19 = V_11 -> V_19 ;
V_72 . V_73 = V_73 ;
V_72 . V_62 = V_62 ;
if ( V_72 . V_28 )
V_60 = F_44 ( V_7 , & V_72 ) ;
V_7 -> V_76 = V_60 ? 0 : V_72 . V_28 ;
V_75:
if ( V_7 -> V_77 == - V_78 )
V_7 -> V_77 = V_60 ;
F_47 ( V_9 ) ;
return V_60 ;
}
static int F_48 ( struct V_46 * V_8 )
{
struct V_1 * V_2 ;
T_1 V_79 ;
struct V_50 * V_51 = F_31 ( V_8 ) ;
if ( ! V_51 ) {
V_51 = F_49 ( sizeof( * V_51 ) , V_80 ) ;
if ( ! V_51 )
return - V_81 ;
F_50 ( V_8 , V_51 ) ;
}
V_2 = F_14 ( V_8 -> V_9 ) ;
F_51 ( V_2 -> V_15 ) ;
V_51 -> V_53 = F_1 ( V_2 , F_35 ( V_8 -> V_56 ) ) ;
V_51 -> V_53 &= ~ ( V_82 | V_83
| V_84 ) ;
if ( V_8 -> V_22 & V_85 )
V_51 -> V_53 |= V_82 ;
if ( V_8 -> V_22 & V_86 )
V_51 -> V_53 |= V_83 ;
if ( ! ( V_8 -> V_22 & V_23 ) )
V_51 -> V_53 |= V_84 ;
V_79 = F_1 ( V_2 , V_87 ) ;
V_79 &= ~ V_88 ;
if ( V_8 -> V_22 & V_89 )
V_79 |= V_88 ;
F_7 ( V_2 , V_87 , V_79 ) ;
F_30 ( V_8 , NULL ) ;
F_52 ( V_2 -> V_15 ) ;
F_53 ( V_2 -> V_15 ) ;
return 0 ;
}
static void F_54 ( struct V_46 * V_8 )
{
struct V_50 * V_51 = F_31 ( V_8 ) ;
F_55 ( V_51 ) ;
F_50 ( V_8 , NULL ) ;
}
static void F_56 ( struct V_1 * V_2 , T_1 V_30 )
{
if ( ! V_2 -> V_45 )
F_26 ( V_2 , V_30 ) ;
if ( ! V_2 -> V_39 )
F_19 ( V_2 , V_30 ) ;
if ( ! V_2 -> V_39 || ! V_2 -> V_45 )
return;
V_30 = F_1 ( V_2 , V_90 ) ;
if ( ! ( V_30 & V_91 ) )
F_15 ( V_2 -> V_15 ,
L_6 ) ;
if ( F_27 ( V_30 ) || F_20 ( V_30 ) != V_29 )
F_15 ( V_2 -> V_15 , L_7 ) ;
F_57 ( & V_2 -> V_61 ) ;
}
static T_4 F_58 ( T_5 V_92 , void * V_93 )
{
struct V_1 * V_2 = V_93 ;
T_1 V_30 ;
F_59 ( & V_2 -> V_69 ) ;
V_30 = F_1 ( V_2 , V_90 ) ;
if ( ! V_30 ) {
F_60 ( & V_2 -> V_69 ) ;
return V_94 ;
}
F_61 ( V_2 -> V_15 , L_8 , V_95 , V_30 ) ;
F_56 ( V_2 , V_30 ) ;
F_7 ( V_2 , V_90 , V_30 ) ;
F_60 ( & V_2 -> V_69 ) ;
return V_96 ;
}
static int F_62 ( struct V_97 * V_15 )
{
struct V_74 * V_9 = F_63 ( V_15 ) ;
struct V_1 * V_2 = F_14 ( V_9 ) ;
T_1 V_98 ;
V_98 = F_1 ( V_2 , V_87 ) ;
V_98 &= ~ V_99 ;
F_7 ( V_2 , V_87 , V_98 ) ;
return 0 ;
}
static int F_64 ( struct V_97 * V_15 )
{
struct V_74 * V_9 = F_63 ( V_15 ) ;
struct V_1 * V_2 = F_14 ( V_9 ) ;
T_1 V_98 ;
V_98 = F_1 ( V_2 , V_87 ) ;
V_98 |= V_99 ;
F_7 ( V_2 , V_87 , V_98 ) ;
return 0 ;
}
static T_6 F_65 ( struct V_46 * V_8 )
{
return V_14 ;
}
static void F_66 ( struct V_97 * V_15 , bool V_100 )
{
struct V_74 * V_9 = F_63 ( V_15 ) ;
struct V_1 * V_2 = F_14 ( V_9 ) ;
struct V_101 * V_102 ;
T_1 V_103 , V_51 , V_104 ;
int V_60 ;
F_7 ( V_2 , V_87 , 0 ) ;
F_7 ( V_2 , V_68 , 0 ) ;
F_7 ( V_2 , V_65 , 0 ) ;
F_7 ( V_2 , V_90 , 0xffffffff ) ;
F_67 (master->dev.of_node, nc) {
V_60 = F_68 ( V_102 , L_9 , & V_51 ) ;
if ( V_60 || V_51 >= V_9 -> V_105 )
continue;
V_103 = V_106 ;
V_60 = F_68 ( V_102 , L_10 , & V_104 ) ;
if ( ! V_60 ) {
V_103 &= ~ ( F_69 ( 0xf ) ) ;
V_103 |= F_69 ( V_104 ) ;
}
V_60 = F_68 ( V_102 , L_11 , & V_104 ) ;
if ( ! V_60 ) {
V_103 &= ~ ( F_70 ( 0xf ) ) ;
V_103 |= F_70 ( V_104 ) ;
}
F_7 ( V_2 , F_35 ( V_51 ) , V_103 ) ;
if ( V_100 )
F_71 ( V_15 , L_12 , V_51 , V_103 ) ;
}
F_7 ( V_2 , V_87 , V_107 | V_99 ) ;
}
static int F_72 ( struct V_97 * V_15 , struct V_108 * V_109 ,
unsigned int V_92 , unsigned int V_110 )
{
struct V_74 * V_9 ;
struct V_1 * V_2 ;
int V_60 ;
V_9 = F_73 ( V_15 , sizeof( struct V_1 ) ) ;
if ( ! V_9 )
return - V_81 ;
F_74 ( V_15 , V_9 ) ;
V_9 -> V_111 = V_112 | V_86 | V_85 | V_113 |
V_23 | V_89 ;
V_9 -> V_15 . V_114 = V_15 -> V_114 ;
V_9 -> V_115 = F_75 ( 4 , 16 ) ;
V_9 -> V_116 = F_48 ;
V_9 -> V_117 = F_54 ;
V_9 -> V_118 = F_46 ;
V_9 -> V_119 = true ;
V_9 -> V_120 = F_65 ;
V_9 -> V_105 = V_110 ;
V_2 = F_14 ( V_9 ) ;
F_76 ( & V_2 -> V_69 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_55 = F_77 () ;
if ( V_2 -> V_55 == - 1 ) {
F_15 ( V_15 , L_13 ) ;
V_60 = - V_21 ;
goto V_121;
}
V_9 -> V_122 = F_34 ( V_2 -> V_55 , 4 * 16 * 16 ) ;
V_9 -> V_49 = F_34 ( V_2 -> V_55 , 4 ) ;
F_78 ( & V_2 -> V_61 ) ;
V_2 -> V_4 = F_79 ( V_15 , V_109 ) ;
if ( F_80 ( V_2 -> V_4 ) ) {
V_60 = F_81 ( V_2 -> V_4 ) ;
goto V_121;
}
V_60 = F_82 ( V_15 , V_92 , F_58 , 0 , L_14 , V_2 ) ;
if ( V_60 )
goto V_121;
F_66 ( V_15 , true ) ;
F_83 ( V_15 , V_123 ) ;
F_84 ( V_15 ) ;
F_85 ( V_15 ) ;
F_86 ( V_15 ) ;
F_51 ( V_15 ) ;
V_60 = F_87 ( V_15 , V_9 ) ;
if ( V_60 < 0 )
goto V_124;
F_71 ( V_15 , L_15 , V_2 -> V_4 , V_92 ) ;
F_52 ( V_15 ) ;
F_53 ( V_15 ) ;
return 0 ;
V_124:
F_88 ( V_15 ) ;
F_89 ( V_15 ) ;
F_90 ( V_15 ) ;
V_121:
F_91 ( V_9 ) ;
return V_60 ;
}
static int F_92 ( struct V_97 * V_15 )
{
struct V_101 * V_125 = V_15 -> V_114 ;
T_1 V_110 ;
int V_60 ;
V_60 = F_68 ( V_125 , L_16 , & V_110 ) ;
if ( V_60 ) {
F_15 ( V_15 , L_17 ) ;
return 0 ;
}
return V_110 ;
}
static int F_93 ( struct V_126 * V_127 )
{
struct V_97 * V_15 = & V_127 -> V_15 ;
struct V_101 * V_125 = V_127 -> V_15 . V_114 ;
struct V_108 V_109 ;
unsigned int V_92 , V_110 ;
int V_60 ;
if ( F_94 ( V_125 , L_18 ) ) {
F_15 ( V_15 , L_19 ) ;
return - V_21 ;
}
V_110 = F_92 ( V_15 ) ;
if ( ! V_110 )
return - V_21 ;
V_60 = F_95 ( V_125 , 0 , & V_109 ) ;
if ( V_60 )
return V_60 ;
V_92 = F_96 ( V_125 , 0 ) ;
if ( ! V_92 )
return - V_21 ;
return F_72 ( V_15 , & V_109 , V_92 , V_110 ) ;
}
static int F_97 ( struct V_126 * V_15 )
{
F_89 ( & V_15 -> V_15 ) ;
return 0 ;
}
static int F_98 ( struct V_97 * V_15 )
{
struct V_74 * V_9 = F_63 ( V_15 ) ;
int V_60 ;
V_60 = F_99 ( V_9 ) ;
if ( V_60 ) {
F_100 ( V_15 , L_20 ) ;
return V_60 ;
}
return F_101 ( V_15 ) ;
}
static int F_102 ( struct V_97 * V_15 )
{
struct V_74 * V_9 = F_63 ( V_15 ) ;
int V_60 ;
F_66 ( V_15 , false ) ;
V_60 = F_103 ( V_15 ) ;
if ( V_60 < 0 )
return V_60 ;
return F_104 ( V_9 ) ;
}
