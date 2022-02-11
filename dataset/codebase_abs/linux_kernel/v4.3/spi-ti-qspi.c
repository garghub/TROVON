static inline unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
unsigned long V_5 , unsigned long V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 -> V_8 ) ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_11 = 0 , V_12 ;
T_1 V_13 , V_14 , V_15 ;
if ( V_7 -> V_8 -> V_16 ) {
F_7 ( V_2 -> V_17 , L_1 ) ;
return - V_18 ;
}
if ( ! V_2 -> V_19 ) {
F_8 ( V_2 -> V_17 , L_2 ) ;
return - V_20 ;
}
V_14 = F_9 ( V_2 -> V_21 ) ;
V_11 = F_10 ( V_14 , V_2 -> V_19 ) - 1 ;
if ( V_11 < 0 ) {
F_7 ( V_2 -> V_17 , L_3 ) ;
return - V_20 ;
}
if ( V_11 > V_22 ) {
F_7 ( V_2 -> V_17 , L_4 ,
V_22 , V_22 + 1 ) ;
return - V_20 ;
}
F_7 ( V_2 -> V_17 , L_5 ,
V_2 -> V_19 , V_11 ) ;
V_12 = F_11 ( V_2 -> V_17 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_17 , L_6 ) ;
return V_12 ;
}
V_13 = F_1 ( V_2 , V_23 ) ;
V_13 &= ~ V_24 ;
F_3 ( V_2 , V_13 , V_23 ) ;
V_15 = V_24 | V_11 ;
F_3 ( V_2 , V_15 , V_23 ) ;
V_10 -> V_25 = V_15 ;
F_12 ( V_2 -> V_17 ) ;
V_12 = F_13 ( V_2 -> V_17 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_17 , L_7 ) ;
return V_12 ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = & V_2 -> V_10 ;
F_3 ( V_2 , V_10 -> V_25 , V_23 ) ;
}
static inline T_1 F_15 ( struct V_1 * V_2 )
{
T_1 V_26 ;
unsigned long V_27 = V_28 + V_29 ;
V_26 = F_1 ( V_2 , V_30 ) ;
while ( ( V_26 & V_31 ) && F_16 ( V_27 , V_28 ) ) {
F_17 () ;
V_26 = F_1 ( V_2 , V_30 ) ;
}
F_18 ( V_26 & V_31 , L_8 ) ;
return V_26 & V_31 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
int V_34 , V_35 , V_36 ;
unsigned int V_37 ;
const T_2 * V_38 ;
T_1 V_39 ;
V_38 = V_33 -> V_40 ;
V_37 = V_2 -> V_37 | V_41 ;
V_35 = V_33 -> V_42 ;
V_34 = V_33 -> V_43 >> 3 ;
V_36 = V_34 ;
while ( V_35 ) {
if ( F_15 ( V_2 ) )
return - V_18 ;
switch ( V_34 ) {
case 1 :
F_7 ( V_2 -> V_17 , L_9 ,
V_37 , V_2 -> V_44 , * V_38 ) ;
if ( V_35 >= V_45 ) {
T_1 * V_46 = ( T_1 * ) V_38 ;
V_39 = F_20 ( * V_46 ++ ) ;
F_4 ( V_39 , V_2 -> V_4 +
V_47 ) ;
V_39 = F_20 ( * V_46 ++ ) ;
F_4 ( V_39 , V_2 -> V_4 +
V_48 ) ;
V_39 = F_20 ( * V_46 ++ ) ;
F_4 ( V_39 , V_2 -> V_4 +
V_49 ) ;
V_39 = F_20 ( * V_46 ++ ) ;
F_4 ( V_39 , V_2 -> V_4 +
V_50 ) ;
V_36 = V_45 ;
V_37 |= F_21 ( V_51 ) ;
} else {
F_22 ( * V_38 , V_2 -> V_4 + V_50 ) ;
V_37 = V_2 -> V_37 | V_41 ;
V_36 = V_34 ;
V_37 |= F_21 ( V_34 ) ;
}
break;
case 2 :
F_7 ( V_2 -> V_17 , L_10 ,
V_37 , V_2 -> V_44 , * V_38 ) ;
F_23 ( * ( ( V_52 * ) V_38 ) , V_2 -> V_4 + V_50 ) ;
break;
case 4 :
F_7 ( V_2 -> V_17 , L_11 ,
V_37 , V_2 -> V_44 , * V_38 ) ;
F_4 ( * ( ( T_1 * ) V_38 ) , V_2 -> V_4 + V_50 ) ;
break;
}
F_3 ( V_2 , V_37 , V_53 ) ;
if ( ! F_24 ( & V_2 -> V_54 ,
V_29 ) ) {
F_8 ( V_2 -> V_17 , L_12 ) ;
return - V_55 ;
}
V_38 += V_36 ;
V_35 -= V_36 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
int V_34 , V_35 ;
unsigned int V_37 ;
T_2 * V_56 ;
V_56 = V_33 -> V_57 ;
V_37 = V_2 -> V_37 ;
switch ( V_33 -> V_58 ) {
case V_59 :
V_37 |= V_60 ;
break;
case V_61 :
V_37 |= V_62 ;
break;
default:
V_37 |= V_63 ;
break;
}
V_35 = V_33 -> V_42 ;
V_34 = V_33 -> V_43 >> 3 ;
while ( V_35 ) {
F_7 ( V_2 -> V_17 , L_13 , V_37 , V_2 -> V_44 ) ;
if ( F_15 ( V_2 ) )
return - V_18 ;
F_3 ( V_2 , V_37 , V_53 ) ;
if ( ! F_24 ( & V_2 -> V_54 ,
V_29 ) ) {
F_8 ( V_2 -> V_17 , L_14 ) ;
return - V_55 ;
}
switch ( V_34 ) {
case 1 :
* V_56 = F_26 ( V_2 -> V_4 + V_50 ) ;
break;
case 2 :
* ( ( V_52 * ) V_56 ) = F_27 ( V_2 -> V_4 + V_50 ) ;
break;
case 4 :
* ( ( T_1 * ) V_56 ) = F_2 ( V_2 -> V_4 + V_50 ) ;
break;
}
V_56 += V_34 ;
V_35 -= V_34 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
int V_12 ;
if ( V_33 -> V_40 ) {
V_12 = F_19 ( V_2 , V_33 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_15 ) ;
return V_12 ;
}
}
if ( V_33 -> V_57 ) {
V_12 = F_25 ( V_2 , V_33 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_16 ) ;
return V_12 ;
}
}
return 0 ;
}
static int F_29 ( struct V_64 * V_8 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
struct V_6 * V_7 = V_66 -> V_7 ;
struct V_32 * V_33 ;
int V_67 = 0 , V_12 ;
int V_68 ;
V_2 -> V_44 = 0 ;
if ( V_7 -> V_69 & V_70 )
V_2 -> V_44 |= F_30 ( V_7 -> V_71 ) ;
if ( V_7 -> V_69 & V_72 )
V_2 -> V_44 |= F_31 ( V_7 -> V_71 ) ;
if ( V_7 -> V_69 & V_73 )
V_2 -> V_44 |= F_32 ( V_7 -> V_71 ) ;
V_68 = ( V_66 -> V_68 << 3 ) / V_7 -> V_43 ;
V_68 = F_33 ( V_68 , 0 , V_74 ) ;
V_2 -> V_37 = 0 ;
V_2 -> V_37 |= F_34 ( V_7 -> V_71 ) ;
V_2 -> V_37 |= F_35 ( V_68 ) ;
V_2 -> V_37 |= V_75 ;
F_3 ( V_2 , V_76 , V_77 ) ;
F_3 ( V_2 , V_2 -> V_44 , V_78 ) ;
F_36 ( & V_2 -> V_79 ) ;
F_37 (t, &m->transfers, transfer_list) {
V_2 -> V_37 |= F_21 ( V_33 -> V_43 ) ;
V_12 = F_28 ( V_2 , V_33 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_17 ) ;
F_38 ( & V_2 -> V_79 ) ;
return - V_20 ;
}
V_66 -> V_80 += V_33 -> V_42 ;
}
F_38 ( & V_2 -> V_79 ) ;
V_66 -> V_67 = V_67 ;
F_39 ( V_8 ) ;
F_3 ( V_2 , V_2 -> V_37 | V_81 , V_53 ) ;
return V_67 ;
}
static T_3 F_40 ( int V_82 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
V_52 V_84 ;
T_1 V_26 ;
T_3 V_12 = V_85 ;
V_84 = F_1 ( V_2 , V_86 ) ;
V_26 = F_1 ( V_2 , V_30 ) ;
if ( ! V_84 ) {
F_7 ( V_2 -> V_17 , L_18 ) ;
V_12 = V_87 ;
goto V_88;
}
F_3 ( V_2 , V_89 ,
V_86 ) ;
if ( V_26 & V_90 )
F_41 ( & V_2 -> V_54 ) ;
V_88:
return V_12 ;
}
static int F_42 ( struct V_91 * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_43 ( V_17 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_92 * V_93 )
{
struct V_1 * V_2 ;
struct V_64 * V_8 ;
struct V_94 * V_95 , * V_96 , * V_97 ;
struct V_98 * V_99 = V_93 -> V_17 . V_100 ;
T_1 V_101 ;
int V_12 = 0 , V_102 , V_82 ;
V_8 = F_45 ( & V_93 -> V_17 , sizeof( * V_2 ) ) ;
if ( ! V_8 )
return - V_103 ;
V_8 -> V_104 = V_72 | V_70 | V_105 | V_106 ;
V_8 -> V_107 = V_108 ;
V_8 -> V_109 = F_5 ;
V_8 -> V_110 = true ;
V_8 -> V_111 = F_29 ;
V_8 -> V_17 . V_100 = V_93 -> V_17 . V_100 ;
V_8 -> V_112 = F_46 ( 32 ) | F_46 ( 16 ) |
F_46 ( 8 ) ;
if ( ! F_47 ( V_99 , L_19 , & V_102 ) )
V_8 -> V_113 = V_102 ;
V_2 = F_6 ( V_8 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_17 = & V_93 -> V_17 ;
F_48 ( V_93 , V_2 ) ;
V_95 = F_49 ( V_93 , V_114 , L_20 ) ;
if ( V_95 == NULL ) {
V_95 = F_50 ( V_93 , V_114 , 0 ) ;
if ( V_95 == NULL ) {
F_8 ( & V_93 -> V_17 , L_21 ) ;
return - V_115 ;
}
}
V_97 = F_49 ( V_93 ,
V_114 , L_22 ) ;
if ( V_97 == NULL ) {
V_97 = F_50 ( V_93 , V_114 , 1 ) ;
if ( V_97 == NULL ) {
F_8 ( & V_93 -> V_17 ,
L_23 ) ;
}
}
V_96 = F_49 ( V_93 ,
V_114 , L_24 ) ;
if ( V_96 == NULL ) {
V_96 = F_50 ( V_93 , V_114 , 2 ) ;
if ( V_96 == NULL ) {
F_7 ( & V_93 -> V_17 ,
L_25 ) ;
}
}
V_82 = F_51 ( V_93 , 0 ) ;
if ( V_82 < 0 ) {
F_8 ( & V_93 -> V_17 , L_26 ) ;
return V_82 ;
}
F_52 ( & V_2 -> V_79 ) ;
V_2 -> V_4 = F_53 ( & V_93 -> V_17 , V_95 ) ;
if ( F_54 ( V_2 -> V_4 ) ) {
V_12 = F_55 ( V_2 -> V_4 ) ;
goto V_116;
}
if ( V_96 ) {
V_2 -> V_117 = true ;
V_2 -> V_118 = F_53 ( & V_93 -> V_17 , V_96 ) ;
if ( F_54 ( V_2 -> V_118 ) ) {
V_12 = F_55 ( V_2 -> V_118 ) ;
goto V_116;
}
}
if ( V_97 ) {
V_2 -> V_119 = F_53 ( & V_93 -> V_17 , V_97 ) ;
if ( F_54 ( V_2 -> V_119 ) ) {
V_12 = F_55 ( V_2 -> V_119 ) ;
goto V_116;
}
}
V_12 = F_56 ( & V_93 -> V_17 , V_82 , F_40 , 0 ,
F_57 ( & V_93 -> V_17 ) , V_2 ) ;
if ( V_12 < 0 ) {
F_8 ( & V_93 -> V_17 , L_27 ,
V_82 ) ;
goto V_116;
}
V_2 -> V_21 = F_58 ( & V_93 -> V_17 , L_28 ) ;
if ( F_54 ( V_2 -> V_21 ) ) {
V_12 = F_55 ( V_2 -> V_21 ) ;
F_8 ( & V_93 -> V_17 , L_29 , V_12 ) ;
}
F_59 ( & V_2 -> V_54 ) ;
F_60 ( & V_93 -> V_17 ) ;
F_61 ( & V_93 -> V_17 , V_120 ) ;
F_62 ( & V_93 -> V_17 ) ;
if ( ! F_47 ( V_99 , L_30 , & V_101 ) )
V_2 -> V_19 = V_101 ;
V_12 = F_63 ( & V_93 -> V_17 , V_8 ) ;
if ( V_12 )
goto V_116;
return 0 ;
V_116:
F_64 ( V_8 ) ;
return V_12 ;
}
static int F_65 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_66 ( V_93 ) ;
int V_12 ;
V_12 = F_11 ( V_2 -> V_17 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_17 , L_6 ) ;
return V_12 ;
}
F_3 ( V_2 , V_89 , V_121 ) ;
F_67 ( V_2 -> V_17 ) ;
F_68 ( & V_93 -> V_17 ) ;
return 0 ;
}
