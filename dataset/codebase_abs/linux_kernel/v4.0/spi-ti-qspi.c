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
int V_34 , V_35 ;
unsigned int V_36 ;
const T_2 * V_37 ;
V_37 = V_33 -> V_38 ;
V_36 = V_2 -> V_36 | V_39 ;
V_35 = V_33 -> V_40 ;
V_34 = V_33 -> V_41 >> 3 ;
while ( V_35 ) {
if ( F_15 ( V_2 ) )
return - V_18 ;
switch ( V_34 ) {
case 1 :
F_7 ( V_2 -> V_17 , L_9 ,
V_36 , V_2 -> V_42 , * V_37 ) ;
F_20 ( * V_37 , V_2 -> V_4 + V_43 ) ;
break;
case 2 :
F_7 ( V_2 -> V_17 , L_10 ,
V_36 , V_2 -> V_42 , * V_37 ) ;
F_21 ( * ( ( V_44 * ) V_37 ) , V_2 -> V_4 + V_43 ) ;
break;
case 4 :
F_7 ( V_2 -> V_17 , L_11 ,
V_36 , V_2 -> V_42 , * V_37 ) ;
F_4 ( * ( ( T_1 * ) V_37 ) , V_2 -> V_4 + V_43 ) ;
break;
}
F_3 ( V_2 , V_36 , V_45 ) ;
if ( ! F_22 ( & V_2 -> V_46 ,
V_29 ) ) {
F_8 ( V_2 -> V_17 , L_12 ) ;
return - V_47 ;
}
V_37 += V_34 ;
V_35 -= V_34 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
int V_34 , V_35 ;
unsigned int V_36 ;
T_2 * V_48 ;
V_48 = V_33 -> V_49 ;
V_36 = V_2 -> V_36 ;
switch ( V_33 -> V_50 ) {
case V_51 :
V_36 |= V_52 ;
break;
case V_53 :
V_36 |= V_54 ;
break;
default:
V_36 |= V_55 ;
break;
}
V_35 = V_33 -> V_40 ;
V_34 = V_33 -> V_41 >> 3 ;
while ( V_35 ) {
F_7 ( V_2 -> V_17 , L_13 , V_36 , V_2 -> V_42 ) ;
if ( F_15 ( V_2 ) )
return - V_18 ;
F_3 ( V_2 , V_36 , V_45 ) ;
if ( ! F_22 ( & V_2 -> V_46 ,
V_29 ) ) {
F_8 ( V_2 -> V_17 , L_14 ) ;
return - V_47 ;
}
switch ( V_34 ) {
case 1 :
* V_48 = F_24 ( V_2 -> V_4 + V_43 ) ;
break;
case 2 :
* ( ( V_44 * ) V_48 ) = F_25 ( V_2 -> V_4 + V_43 ) ;
break;
case 4 :
* ( ( T_1 * ) V_48 ) = F_2 ( V_2 -> V_4 + V_43 ) ;
break;
}
V_48 += V_34 ;
V_35 -= V_34 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
int V_12 ;
if ( V_33 -> V_38 ) {
V_12 = F_19 ( V_2 , V_33 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_15 ) ;
return V_12 ;
}
}
if ( V_33 -> V_49 ) {
V_12 = F_23 ( V_2 , V_33 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_16 ) ;
return V_12 ;
}
}
return 0 ;
}
static int F_27 ( struct V_56 * V_8 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
struct V_6 * V_7 = V_58 -> V_7 ;
struct V_32 * V_33 ;
int V_59 = 0 , V_12 ;
int V_60 ;
V_2 -> V_42 = 0 ;
if ( V_7 -> V_61 & V_62 )
V_2 -> V_42 |= F_28 ( V_7 -> V_63 ) ;
if ( V_7 -> V_61 & V_64 )
V_2 -> V_42 |= F_29 ( V_7 -> V_63 ) ;
if ( V_7 -> V_61 & V_65 )
V_2 -> V_42 |= F_30 ( V_7 -> V_63 ) ;
V_60 = ( V_58 -> V_60 << 3 ) / V_7 -> V_41 ;
V_60 = F_31 ( V_60 , 0 , V_66 ) ;
V_2 -> V_36 = 0 ;
V_2 -> V_36 |= F_32 ( V_7 -> V_63 ) ;
V_2 -> V_36 |= F_33 ( V_60 ) ;
V_2 -> V_36 |= V_67 ;
F_3 ( V_2 , V_68 , V_69 ) ;
F_3 ( V_2 , V_2 -> V_42 , V_70 ) ;
F_34 ( & V_2 -> V_71 ) ;
F_35 (t, &m->transfers, transfer_list) {
V_2 -> V_36 |= F_36 ( V_33 -> V_41 ) ;
V_12 = F_26 ( V_2 , V_33 ) ;
if ( V_12 ) {
F_7 ( V_2 -> V_17 , L_17 ) ;
F_37 ( & V_2 -> V_71 ) ;
return - V_20 ;
}
V_58 -> V_72 += V_33 -> V_40 ;
}
F_37 ( & V_2 -> V_71 ) ;
V_58 -> V_59 = V_59 ;
F_38 ( V_8 ) ;
F_3 ( V_2 , V_2 -> V_36 | V_73 , V_45 ) ;
return V_59 ;
}
static T_3 F_39 ( int V_74 , void * V_75 )
{
struct V_1 * V_2 = V_75 ;
V_44 V_76 ;
T_1 V_26 ;
T_3 V_12 = V_77 ;
V_76 = F_1 ( V_2 , V_78 ) ;
V_26 = F_1 ( V_2 , V_30 ) ;
if ( ! V_76 ) {
F_7 ( V_2 -> V_17 , L_18 ) ;
V_12 = V_79 ;
goto V_80;
}
F_3 ( V_2 , V_81 ,
V_78 ) ;
if ( V_26 & V_82 )
F_40 ( & V_2 -> V_46 ) ;
V_80:
return V_12 ;
}
static int F_41 ( struct V_83 * V_17 )
{
struct V_1 * V_2 ;
V_2 = F_42 ( V_17 ) ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
struct V_56 * V_8 ;
struct V_86 * V_87 , * V_88 , * V_89 ;
struct V_90 * V_91 = V_85 -> V_17 . V_92 ;
T_1 V_93 ;
int V_12 = 0 , V_94 , V_74 ;
V_8 = F_44 ( & V_85 -> V_17 , sizeof( * V_2 ) ) ;
if ( ! V_8 )
return - V_95 ;
V_8 -> V_96 = V_64 | V_62 | V_97 | V_98 ;
V_8 -> V_99 = V_100 ;
V_8 -> V_101 = F_5 ;
V_8 -> V_102 = true ;
V_8 -> V_103 = F_27 ;
V_8 -> V_17 . V_92 = V_85 -> V_17 . V_92 ;
V_8 -> V_104 = F_45 ( 32 ) | F_45 ( 16 ) |
F_45 ( 8 ) ;
if ( ! F_46 ( V_91 , L_19 , & V_94 ) )
V_8 -> V_105 = V_94 ;
V_2 = F_6 ( V_8 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_17 = & V_85 -> V_17 ;
F_47 ( V_85 , V_2 ) ;
V_87 = F_48 ( V_85 , V_106 , L_20 ) ;
if ( V_87 == NULL ) {
V_87 = F_49 ( V_85 , V_106 , 0 ) ;
if ( V_87 == NULL ) {
F_8 ( & V_85 -> V_17 , L_21 ) ;
return - V_107 ;
}
}
V_89 = F_48 ( V_85 ,
V_106 , L_22 ) ;
if ( V_89 == NULL ) {
V_89 = F_49 ( V_85 , V_106 , 1 ) ;
if ( V_89 == NULL ) {
F_8 ( & V_85 -> V_17 ,
L_23 ) ;
}
}
V_88 = F_48 ( V_85 ,
V_106 , L_24 ) ;
if ( V_88 == NULL ) {
V_88 = F_49 ( V_85 , V_106 , 2 ) ;
if ( V_88 == NULL ) {
F_7 ( & V_85 -> V_17 ,
L_25 ) ;
}
}
V_74 = F_50 ( V_85 , 0 ) ;
if ( V_74 < 0 ) {
F_8 ( & V_85 -> V_17 , L_26 ) ;
return V_74 ;
}
F_51 ( & V_2 -> V_71 ) ;
V_2 -> V_4 = F_52 ( & V_85 -> V_17 , V_87 ) ;
if ( F_53 ( V_2 -> V_4 ) ) {
V_12 = F_54 ( V_2 -> V_4 ) ;
goto V_108;
}
if ( V_88 ) {
V_2 -> V_109 = true ;
V_2 -> V_110 = F_52 ( & V_85 -> V_17 , V_88 ) ;
if ( F_53 ( V_2 -> V_110 ) ) {
V_12 = F_54 ( V_2 -> V_110 ) ;
goto V_108;
}
}
if ( V_89 ) {
V_2 -> V_111 = F_52 ( & V_85 -> V_17 , V_89 ) ;
if ( F_53 ( V_2 -> V_111 ) ) {
V_12 = F_54 ( V_2 -> V_111 ) ;
goto V_108;
}
}
V_12 = F_55 ( & V_85 -> V_17 , V_74 , F_39 , 0 ,
F_56 ( & V_85 -> V_17 ) , V_2 ) ;
if ( V_12 < 0 ) {
F_8 ( & V_85 -> V_17 , L_27 ,
V_74 ) ;
goto V_108;
}
V_2 -> V_21 = F_57 ( & V_85 -> V_17 , L_28 ) ;
if ( F_53 ( V_2 -> V_21 ) ) {
V_12 = F_54 ( V_2 -> V_21 ) ;
F_8 ( & V_85 -> V_17 , L_29 , V_12 ) ;
}
F_58 ( & V_2 -> V_46 ) ;
F_59 ( & V_85 -> V_17 ) ;
F_60 ( & V_85 -> V_17 , V_112 ) ;
F_61 ( & V_85 -> V_17 ) ;
if ( ! F_46 ( V_91 , L_30 , & V_93 ) )
V_2 -> V_19 = V_93 ;
V_12 = F_62 ( & V_85 -> V_17 , V_8 ) ;
if ( V_12 )
goto V_108;
return 0 ;
V_108:
F_63 ( V_8 ) ;
return V_12 ;
}
static int F_64 ( struct V_84 * V_85 )
{
struct V_1 * V_2 = F_65 ( V_85 ) ;
int V_12 ;
V_12 = F_11 ( V_2 -> V_17 ) ;
if ( V_12 < 0 ) {
F_8 ( V_2 -> V_17 , L_6 ) ;
return V_12 ;
}
F_3 ( V_2 , V_81 , V_113 ) ;
F_66 ( V_2 -> V_17 ) ;
F_67 ( & V_85 -> V_17 ) ;
return 0 ;
}
