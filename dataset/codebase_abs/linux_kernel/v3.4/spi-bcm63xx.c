static inline T_1 F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + F_3 ( V_3 ) ) ;
}
static inline T_2 F_4 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_5 ( V_2 -> V_4 + F_3 ( V_3 ) ) ;
}
static inline void F_6 ( struct V_1 * V_2 ,
T_1 V_5 , unsigned int V_3 )
{
F_7 ( V_5 , V_2 -> V_4 + F_3 ( V_3 ) ) ;
}
static inline void F_8 ( struct V_1 * V_2 ,
T_2 V_5 , unsigned int V_3 )
{
F_9 ( V_5 , V_2 -> V_4 + F_3 ( V_3 ) ) ;
}
static int F_10 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
T_1 V_10 ;
V_10 = ( V_9 ) ? V_9 -> V_10 : V_7 -> V_10 ;
if ( V_10 != 8 ) {
F_11 ( & V_7 -> V_11 , L_1 ,
V_12 , V_10 ) ;
return - V_13 ;
}
if ( V_7 -> V_14 > V_7 -> V_15 -> V_16 ) {
F_11 ( & V_7 -> V_11 , L_2 ,
V_12 , V_7 -> V_14 ) ;
return - V_13 ;
}
return 0 ;
}
static void F_12 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_13 ( V_7 -> V_15 ) ;
T_3 V_17 ;
T_1 V_18 , V_19 ;
int V_20 ;
V_17 = ( V_9 ) ? V_9 -> V_21 : V_7 -> V_22 ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
if ( V_17 <= V_24 [ V_20 ] [ 0 ] ) {
V_18 = V_24 [ V_20 ] [ 1 ] ;
break;
}
}
if ( V_20 == V_23 )
V_18 = V_25 ;
V_19 = F_1 ( V_2 , V_26 ) ;
V_19 &= ~ V_23 ;
V_19 |= V_18 ;
F_6 ( V_2 , V_19 , V_26 ) ;
F_14 ( & V_7 -> V_11 , L_3 ,
V_18 , V_17 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
int V_27 ;
V_2 = F_13 ( V_7 -> V_15 ) ;
if ( ! V_7 -> V_10 )
V_7 -> V_10 = 8 ;
if ( V_7 -> V_28 & ~ V_29 ) {
F_11 ( & V_7 -> V_11 , L_4 ,
V_12 , V_7 -> V_28 & ~ V_29 ) ;
return - V_13 ;
}
V_27 = F_10 ( V_7 , NULL ) ;
if ( V_27 < 0 ) {
F_11 ( & V_7 -> V_11 , L_5 ,
V_7 -> V_28 & ~ V_29 ) ;
return V_27 ;
}
F_14 ( & V_7 -> V_11 , L_6 ,
V_12 , V_7 -> V_28 & V_29 , V_7 -> V_10 , 0 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_30 ;
V_30 = V_2 -> V_31 < V_2 -> V_32 ? V_2 -> V_31 :
V_2 -> V_32 ;
F_17 ( V_2 -> V_33 , V_2 -> V_34 , V_30 ) ;
V_2 -> V_31 -= V_30 ;
}
static unsigned int F_18 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_13 ( V_7 -> V_15 ) ;
T_2 V_35 ;
T_2 V_36 ;
F_6 ( V_2 , 0 , V_37 ) ;
F_14 ( & V_7 -> V_11 , L_7 ,
V_9 -> V_38 , V_9 -> V_39 , V_9 -> V_40 ) ;
V_2 -> V_34 = V_9 -> V_38 ;
V_2 -> V_41 = V_9 -> V_39 ;
if ( V_9 -> V_38 ) {
V_2 -> V_31 = V_9 -> V_40 ;
F_16 ( V_2 ) ;
}
F_19 ( & V_2 -> V_42 ) ;
V_35 = ( V_9 -> V_40 << V_43 ) ;
if ( V_9 -> V_39 && V_9 -> V_38 )
V_35 |= ( V_44 << V_45 ) ;
else if ( V_9 -> V_39 )
V_35 |= ( V_46 << V_45 ) ;
else if ( V_9 -> V_38 )
V_35 |= ( V_47 << V_45 ) ;
F_8 ( V_2 , V_35 , V_48 ) ;
V_36 = V_49 ;
V_36 |= ( 0 << V_50 ) ;
V_36 |= ( V_7 -> V_14 << V_51 ) ;
F_8 ( V_2 , V_36 , V_52 ) ;
F_6 ( V_2 , V_53 , V_37 ) ;
return V_9 -> V_40 - V_2 -> V_31 ;
}
static int F_20 ( struct V_54 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
F_21 ( & V_2 -> V_55 -> V_11 ) ;
return 0 ;
}
static int F_22 ( struct V_54 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
F_23 ( & V_2 -> V_55 -> V_11 ) ;
return 0 ;
}
static int F_24 ( struct V_54 * V_15 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_8 * V_9 ;
struct V_6 * V_7 = V_57 -> V_7 ;
int V_58 = 0 ;
unsigned int V_59 = 0 ;
F_25 (t, &m->transfers, transfer_list) {
unsigned int V_40 = V_9 -> V_40 ;
T_1 V_60 ;
V_58 = F_10 ( V_7 , V_9 ) ;
if ( V_58 < 0 )
goto exit;
F_12 ( V_7 , V_9 ) ;
while ( V_40 ) {
V_40 -= F_18 ( V_7 , V_9 ) ;
V_59 = F_26 ( & V_2 -> V_42 , V_61 ) ;
if ( ! V_59 ) {
V_58 = - V_62 ;
goto exit;
}
V_60 = F_1 ( V_2 , V_63 ) ;
if ( V_60 )
F_27 ( V_2 -> V_41 , V_2 -> V_64 , V_60 ) ;
}
V_57 -> V_65 += V_9 -> V_40 ;
}
exit:
V_57 -> V_58 = V_58 ;
F_28 ( V_15 ) ;
return 0 ;
}
static T_4 F_29 ( int V_66 , void * V_67 )
{
struct V_54 * V_15 = (struct V_54 * ) V_67 ;
struct V_1 * V_2 = F_13 ( V_15 ) ;
T_1 V_68 ;
V_68 = F_1 ( V_2 , V_69 ) ;
F_6 ( V_2 , V_70 , V_69 ) ;
F_6 ( V_2 , 0 , V_37 ) ;
if ( V_68 & V_53 )
F_30 ( & V_2 -> V_42 ) ;
return V_71 ;
}
static int T_5 F_31 ( struct V_72 * V_55 )
{
struct V_73 * V_74 ;
struct V_75 * V_11 = & V_55 -> V_11 ;
struct V_76 * V_77 = V_55 -> V_11 . V_78 ;
int V_66 ;
struct V_54 * V_15 ;
struct V_79 * V_79 ;
struct V_1 * V_2 ;
int V_27 ;
V_74 = F_32 ( V_55 , V_80 , 0 ) ;
if ( ! V_74 ) {
F_11 ( V_11 , L_8 ) ;
V_27 = - V_81 ;
goto V_82;
}
V_66 = F_33 ( V_55 , 0 ) ;
if ( V_66 < 0 ) {
F_11 ( V_11 , L_9 ) ;
V_27 = - V_81 ;
goto V_82;
}
V_79 = F_34 ( V_11 , L_10 ) ;
if ( F_35 ( V_79 ) ) {
F_11 ( V_11 , L_11 ) ;
V_27 = F_36 ( V_79 ) ;
goto V_82;
}
V_15 = F_37 ( V_11 , sizeof( * V_2 ) ) ;
if ( ! V_15 ) {
F_11 ( V_11 , L_12 ) ;
V_27 = - V_83 ;
goto V_84;
}
V_2 = F_13 ( V_15 ) ;
F_38 ( V_55 , V_15 ) ;
V_2 -> V_55 = V_55 ;
if ( ! F_39 ( & V_55 -> V_11 , V_74 -> V_85 ,
F_40 ( V_74 ) , V_86 ) ) {
F_11 ( V_11 , L_13 ) ;
V_27 = - V_81 ;
goto V_87;
}
V_2 -> V_4 = F_41 ( & V_55 -> V_11 , V_74 -> V_85 ,
F_40 ( V_74 ) ) ;
if ( ! V_2 -> V_4 ) {
F_11 ( V_11 , L_14 ) ;
V_27 = - V_83 ;
goto V_87;
}
V_2 -> V_66 = V_66 ;
V_2 -> V_79 = V_79 ;
V_2 -> V_32 = V_77 -> V_32 ;
V_27 = F_42 ( & V_55 -> V_11 , V_66 , F_29 , 0 ,
V_55 -> V_88 , V_15 ) ;
if ( V_27 ) {
F_11 ( V_11 , L_15 ) ;
goto V_87;
}
V_15 -> V_89 = V_77 -> V_89 ;
V_15 -> V_16 = V_77 -> V_16 ;
V_15 -> V_90 = F_15 ;
V_15 -> V_91 = F_20 ;
V_15 -> V_92 = F_22 ;
V_15 -> V_93 = F_24 ;
V_15 -> V_94 = V_29 ;
V_2 -> V_21 = V_77 -> V_21 ;
V_2 -> V_33 = ( T_1 * ) ( V_2 -> V_4 + F_3 ( V_95 ) ) ;
V_2 -> V_64 = ( const T_1 * ) ( V_2 -> V_4 + F_3 ( V_96 ) ) ;
F_43 ( V_2 -> V_79 ) ;
F_6 ( V_2 , V_70 , V_69 ) ;
V_27 = F_44 ( V_15 ) ;
if ( V_27 ) {
F_11 ( V_11 , L_16 ) ;
goto V_97;
}
F_45 ( V_11 , L_17 ,
V_74 -> V_85 , V_66 , V_2 -> V_32 , V_98 ) ;
return 0 ;
V_97:
F_46 ( V_79 ) ;
V_87:
F_38 ( V_55 , NULL ) ;
F_47 ( V_15 ) ;
V_84:
F_48 ( V_79 ) ;
V_82:
return V_27 ;
}
static int T_6 F_49 ( struct V_72 * V_55 )
{
struct V_54 * V_15 = F_50 ( V_55 ) ;
struct V_1 * V_2 = F_13 ( V_15 ) ;
F_51 ( V_15 ) ;
F_6 ( V_2 , 0 , V_37 ) ;
F_46 ( V_2 -> V_79 ) ;
F_48 ( V_2 -> V_79 ) ;
F_38 ( V_55 , 0 ) ;
return 0 ;
}
static int F_52 ( struct V_75 * V_11 )
{
struct V_54 * V_15 =
F_50 ( F_53 ( V_11 ) ) ;
struct V_1 * V_2 = F_13 ( V_15 ) ;
F_46 ( V_2 -> V_79 ) ;
return 0 ;
}
static int F_54 ( struct V_75 * V_11 )
{
struct V_54 * V_15 =
F_50 ( F_53 ( V_11 ) ) ;
struct V_1 * V_2 = F_13 ( V_15 ) ;
F_43 ( V_2 -> V_79 ) ;
return 0 ;
}
