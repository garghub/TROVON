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
static int F_15 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
int V_28 , V_29 , V_12 ;
unsigned int V_30 ;
const T_2 * V_31 ;
V_31 = V_27 -> V_32 ;
V_30 = V_2 -> V_30 | V_33 ;
V_29 = V_27 -> V_34 ;
V_28 = V_27 -> V_35 >> 3 ;
while ( V_29 ) {
switch ( V_28 ) {
case 1 :
F_7 ( V_2 -> V_17 , L_8 ,
V_30 , V_2 -> V_36 , * V_31 ) ;
F_16 ( * V_31 , V_2 -> V_4 + V_37 ) ;
break;
case 2 :
F_7 ( V_2 -> V_17 , L_9 ,
V_30 , V_2 -> V_36 , * V_31 ) ;
F_17 ( * ( ( V_38 * ) V_31 ) , V_2 -> V_4 + V_37 ) ;
break;
case 4 :
F_7 ( V_2 -> V_17 , L_10 ,
V_30 , V_2 -> V_36 , * V_31 ) ;
F_4 ( * ( ( T_1 * ) V_31 ) , V_2 -> V_4 + V_37 ) ;
break;
}
F_3 ( V_2 , V_30 , V_39 ) ;
V_12 = F_18 ( & V_2 -> V_40 ,
V_41 ) ;
if ( V_12 == 0 ) {
F_8 ( V_2 -> V_17 , L_11 ) ;
return - V_42 ;
}
V_31 += V_28 ;
V_29 -= V_28 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
int V_28 , V_29 , V_12 ;
unsigned int V_30 ;
T_2 * V_43 ;
V_43 = V_27 -> V_44 ;
V_30 = V_2 -> V_30 ;
switch ( V_27 -> V_45 ) {
case V_46 :
V_30 |= V_47 ;
break;
case V_48 :
V_30 |= V_49 ;
break;
default:
V_30 |= V_50 ;
break;
}
V_29 = V_27 -> V_34 ;
V_28 = V_27 -> V_35 >> 3 ;
while ( V_29 ) {
F_7 ( V_2 -> V_17 , L_12 , V_30 , V_2 -> V_36 ) ;
F_3 ( V_2 , V_30 , V_39 ) ;
V_12 = F_18 ( & V_2 -> V_40 ,
V_41 ) ;
if ( V_12 == 0 ) {
F_8 ( V_2 -> V_17 , L_13 ) ;
return - V_42 ;
}
switch ( V_28 ) {
case 1 :
* V_43 = F_20 ( V_2 -> V_4 + V_37 ) ;
break;
case 2 :
* ( ( V_38 * ) V_43 ) = F_21 ( V_2 -> V_4 + V_37 ) ;
break;
case 4 :
* ( ( T_1 * ) V_43 ) = F_2 ( V_2 -> V_4 + V_37 ) ;
break;
}
V_43 += V_28 ;
V_29 -= V_28 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
int V_12 ;
if ( V_27 -> V_32 ) {
V_12 = F_15 ( V_2 , V_27 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_14 ) ;
return V_12 ;
}
}
if ( V_27 -> V_44 ) {
V_12 = F_19 ( V_2 , V_27 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_15 ) ;
return V_12 ;
}
}
return 0 ;
}
static int F_23 ( struct V_51 * V_8 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
struct V_6 * V_7 = V_53 -> V_7 ;
struct V_26 * V_27 ;
int V_54 = 0 , V_12 ;
int V_55 ;
V_2 -> V_36 = 0 ;
if ( V_7 -> V_56 & V_57 )
V_2 -> V_36 |= F_24 ( V_7 -> V_58 ) ;
if ( V_7 -> V_56 & V_59 )
V_2 -> V_36 |= F_25 ( V_7 -> V_58 ) ;
if ( V_7 -> V_56 & V_60 )
V_2 -> V_36 |= F_26 ( V_7 -> V_58 ) ;
V_55 = ( V_53 -> V_55 << 3 ) / V_7 -> V_35 ;
V_55 = F_27 ( V_55 , 0 , V_61 ) ;
V_2 -> V_30 = 0 ;
V_2 -> V_30 |= F_28 ( V_7 -> V_58 ) ;
V_2 -> V_30 |= F_29 ( V_55 ) ;
V_2 -> V_30 |= V_62 ;
F_3 ( V_2 , V_63 , V_64 ) ;
F_3 ( V_2 , V_2 -> V_36 , V_65 ) ;
F_30 ( & V_2 -> V_66 ) ;
F_31 (t, &m->transfers, transfer_list) {
V_2 -> V_30 |= F_32 ( V_27 -> V_35 ) ;
V_12 = F_22 ( V_2 , V_27 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_16 ) ;
F_33 ( & V_2 -> V_66 ) ;
return - V_20 ;
}
V_53 -> V_67 += V_27 -> V_34 ;
}
F_33 ( & V_2 -> V_66 ) ;
V_53 -> V_54 = V_54 ;
F_34 ( V_8 ) ;
F_3 ( V_2 , V_2 -> V_30 | V_68 , V_39 ) ;
return V_54 ;
}
static T_3 F_35 ( int V_69 , void * V_70 )
{
struct V_1 * V_2 = V_70 ;
V_38 V_71 ;
T_1 V_72 ;
T_3 V_12 = V_73 ;
V_71 = F_1 ( V_2 , V_74 ) ;
V_72 = F_1 ( V_2 , V_75 ) ;
if ( ! V_71 ) {
F_7 ( V_2 -> V_17 , L_17 ) ;
V_12 = V_76 ;
goto V_77;
}
F_3 ( V_2 , V_78 ,
V_74 ) ;
if ( V_72 & V_79 )
F_36 ( & V_2 -> V_40 ) ;
V_77:
return V_12 ;
}
static int F_37 ( struct V_80 * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_38 ( V_17 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_81 * V_82 )
{
struct V_1 * V_2 ;
struct V_51 * V_8 ;
struct V_83 * V_84 , * V_85 , * V_86 ;
struct V_87 * V_88 = V_82 -> V_17 . V_89 ;
T_1 V_90 ;
int V_12 = 0 , V_91 , V_69 ;
V_8 = F_40 ( & V_82 -> V_17 , sizeof( * V_2 ) ) ;
if ( ! V_8 )
return - V_92 ;
V_8 -> V_93 = V_59 | V_57 | V_94 | V_95 ;
V_8 -> V_96 = - 1 ;
V_8 -> V_97 = V_98 ;
V_8 -> V_99 = F_5 ;
V_8 -> V_100 = true ;
V_8 -> V_101 = F_23 ;
V_8 -> V_17 . V_89 = V_82 -> V_17 . V_89 ;
V_8 -> V_102 = F_41 ( 32 - 1 ) | F_41 ( 16 - 1 ) | F_41 ( 8 - 1 ) ;
if ( ! F_42 ( V_88 , L_18 , & V_91 ) )
V_8 -> V_103 = V_91 ;
V_2 = F_6 ( V_8 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_17 = & V_82 -> V_17 ;
F_43 ( V_82 , V_2 ) ;
V_84 = F_44 ( V_82 , V_104 , L_19 ) ;
if ( V_84 == NULL ) {
V_84 = F_45 ( V_82 , V_104 , 0 ) ;
if ( V_84 == NULL ) {
F_8 ( & V_82 -> V_17 , L_20 ) ;
return - V_105 ;
}
}
V_86 = F_44 ( V_82 ,
V_104 , L_21 ) ;
if ( V_86 == NULL ) {
V_86 = F_45 ( V_82 , V_104 , 1 ) ;
if ( V_86 == NULL ) {
F_8 ( & V_82 -> V_17 ,
L_22 ) ;
return - V_105 ;
}
}
V_85 = F_44 ( V_82 ,
V_104 , L_23 ) ;
if ( V_85 == NULL ) {
V_85 = F_45 ( V_82 , V_104 , 2 ) ;
if ( V_85 == NULL ) {
F_7 ( & V_82 -> V_17 ,
L_24 ) ;
}
}
V_69 = F_46 ( V_82 , 0 ) ;
if ( V_69 < 0 ) {
F_8 ( & V_82 -> V_17 , L_25 ) ;
return V_69 ;
}
F_47 ( & V_2 -> V_66 ) ;
V_2 -> V_4 = F_48 ( & V_82 -> V_17 , V_84 ) ;
if ( F_49 ( V_2 -> V_4 ) ) {
V_12 = F_50 ( V_2 -> V_4 ) ;
goto V_106;
}
if ( V_85 ) {
V_2 -> V_107 = true ;
V_2 -> V_108 = F_48 ( & V_82 -> V_17 , V_85 ) ;
if ( F_49 ( V_2 -> V_108 ) ) {
V_12 = F_50 ( V_2 -> V_108 ) ;
goto V_106;
}
}
if ( V_86 ) {
V_2 -> V_109 = F_48 ( & V_82 -> V_17 , V_86 ) ;
if ( F_49 ( V_2 -> V_109 ) ) {
V_12 = F_50 ( V_2 -> V_109 ) ;
goto V_106;
}
}
V_12 = F_51 ( & V_82 -> V_17 , V_69 , F_35 , 0 ,
F_52 ( & V_82 -> V_17 ) , V_2 ) ;
if ( V_12 < 0 ) {
F_8 ( & V_82 -> V_17 , L_26 ,
V_69 ) ;
goto V_106;
}
V_2 -> V_21 = F_53 ( & V_82 -> V_17 , L_27 ) ;
if ( F_49 ( V_2 -> V_21 ) ) {
V_12 = F_50 ( V_2 -> V_21 ) ;
F_8 ( & V_82 -> V_17 , L_28 , V_12 ) ;
}
F_54 ( & V_2 -> V_40 ) ;
F_55 ( & V_82 -> V_17 ) ;
F_56 ( & V_82 -> V_17 , V_110 ) ;
F_57 ( & V_82 -> V_17 ) ;
if ( ! F_42 ( V_88 , L_29 , & V_90 ) )
V_2 -> V_19 = V_90 ;
V_12 = F_58 ( & V_82 -> V_17 , V_8 ) ;
if ( V_12 )
goto V_106;
return 0 ;
V_106:
F_59 ( V_8 ) ;
return V_12 ;
}
static int F_60 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_61 ( V_82 ) ;
int V_12 ;
V_12 = F_11 ( V_2 -> V_17 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_17 , L_6 ) ;
return V_12 ;
}
F_3 ( V_2 , V_78 , V_111 ) ;
F_62 ( V_2 -> V_17 ) ;
F_63 ( & V_82 -> V_17 ) ;
return 0 ;
}
