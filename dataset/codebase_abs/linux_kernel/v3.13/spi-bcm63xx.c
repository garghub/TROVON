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
static void F_10 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_11 ( V_7 -> V_10 ) ;
T_1 V_11 , V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
if ( V_9 -> V_15 >= V_16 [ V_13 ] [ 0 ] ) {
V_11 = V_16 [ V_13 ] [ 1 ] ;
break;
}
}
if ( V_13 == V_14 )
V_11 = V_17 ;
V_12 = F_1 ( V_2 , V_18 ) ;
V_12 &= ~ V_14 ;
V_12 |= V_11 ;
F_6 ( V_2 , V_12 , V_18 ) ;
F_12 ( & V_7 -> V_19 , L_1 ,
V_11 , V_9 -> V_15 ) ;
}
static int F_13 ( struct V_6 * V_7 , struct V_8 * V_20 ,
unsigned int V_21 )
{
struct V_1 * V_2 = F_11 ( V_7 -> V_10 ) ;
T_2 V_22 ;
T_2 V_23 ;
T_1 V_24 ;
unsigned int V_13 , V_25 = 0 , V_26 = 0 , V_27 = 0 ;
struct V_8 * V_9 = V_20 ;
bool V_28 = false ;
bool V_29 = false ;
F_6 ( V_2 , 0 , V_30 ) ;
F_12 ( & V_7 -> V_19 , L_2 ,
V_9 -> V_31 , V_9 -> V_32 , V_9 -> V_27 ) ;
if ( V_21 > 1 && V_9 -> V_31 && V_9 -> V_27 <= V_33 )
V_26 = V_9 -> V_27 ;
for ( V_13 = 0 ; V_13 < V_21 ; V_13 ++ ) {
if ( V_9 -> V_31 ) {
V_29 = true ;
F_14 ( V_2 -> V_34 + V_27 , V_9 -> V_31 , V_9 -> V_27 ) ;
if ( V_9 != V_20 )
V_26 = 0 ;
}
if ( V_9 -> V_32 ) {
V_28 = true ;
if ( V_9 == V_20 )
V_26 = 0 ;
}
V_27 += V_9 -> V_27 ;
V_9 = F_15 ( V_9 -> V_35 . V_36 , struct V_8 ,
V_35 ) ;
}
V_27 -= V_26 ;
F_16 ( & V_2 -> V_37 ) ;
V_22 = ( V_27 << V_38 ) ;
if ( V_28 && V_29 && V_26 == 0 )
V_22 |= ( V_39 << V_2 -> V_40 ) ;
else if ( V_28 )
V_22 |= ( V_41 << V_2 -> V_40 ) ;
else if ( V_29 )
V_22 |= ( V_42 << V_2 -> V_40 ) ;
switch ( V_2 -> V_43 ) {
case 8 :
F_6 ( V_2 , V_22 , V_44 ) ;
break;
case 16 :
F_8 ( V_2 , V_22 , V_44 ) ;
break;
}
V_23 = V_45 ;
V_23 |= ( V_26 << V_46 ) ;
V_23 |= ( V_7 -> V_47 << V_48 ) ;
F_8 ( V_2 , V_23 , V_49 ) ;
F_6 ( V_2 , V_50 , V_30 ) ;
V_25 = F_17 ( & V_2 -> V_37 , V_51 ) ;
if ( ! V_25 )
return - V_52 ;
V_24 = F_1 ( V_2 , V_53 ) ;
if ( V_28 && V_24 != V_27 )
return - V_54 ;
if ( ! V_24 )
return 0 ;
V_27 = 0 ;
V_9 = V_20 ;
for ( V_13 = 0 ; V_13 < V_21 ; V_13 ++ ) {
if ( V_9 -> V_32 )
F_18 ( V_9 -> V_32 , V_2 -> V_55 + V_27 , V_9 -> V_27 ) ;
if ( V_9 != V_20 || V_26 == 0 )
V_27 += V_9 -> V_27 ;
V_9 = F_15 ( V_9 -> V_35 . V_36 , struct V_8 ,
V_35 ) ;
}
return 0 ;
}
static int F_19 ( struct V_56 * V_10 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 , * V_20 = NULL ;
struct V_6 * V_7 = V_58 -> V_7 ;
int V_59 = 0 ;
unsigned int V_60 = 0 , V_61 = 0 ;
bool V_62 = false ;
F_20 (t, &m->transfers, transfer_list) {
if ( ! V_20 )
V_20 = V_9 ;
V_60 ++ ;
V_61 += V_9 -> V_27 ;
if ( V_60 == 2 && ! V_20 -> V_32 && ! V_9 -> V_31 &&
V_20 -> V_27 <= V_33 )
V_62 = true ;
else if ( V_62 && V_9 -> V_31 )
V_62 = false ;
if ( ( V_62 &&
V_61 > ( V_2 -> V_63 + V_33 ) ) ||
( ! V_62 && V_61 > V_2 -> V_63 ) ) {
F_21 ( & V_7 -> V_19 , L_3 ,
V_61 , V_2 -> V_63 ) ;
V_59 = - V_64 ;
goto exit;
}
if ( V_9 -> V_15 != V_20 -> V_15 ) {
F_21 ( & V_7 -> V_19 , L_4 ) ;
V_59 = - V_64 ;
goto exit;
}
if ( V_9 -> V_65 ) {
F_21 ( & V_7 -> V_19 , L_5 ) ;
V_59 = - V_64 ;
goto exit;
}
if ( V_9 -> V_66 ||
F_22 ( & V_9 -> V_35 , & V_58 -> V_67 ) ) {
F_10 ( V_7 , V_20 ) ;
V_59 = F_13 ( V_7 , V_20 , V_60 ) ;
if ( V_59 )
goto exit;
V_58 -> V_68 += V_61 ;
V_20 = NULL ;
V_60 = 0 ;
V_61 = 0 ;
V_62 = false ;
}
}
exit:
V_58 -> V_59 = V_59 ;
F_23 ( V_10 ) ;
return 0 ;
}
static T_3 F_24 ( int V_69 , void * V_70 )
{
struct V_56 * V_10 = (struct V_56 * ) V_70 ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
T_1 V_71 ;
V_71 = F_1 ( V_2 , V_72 ) ;
F_6 ( V_2 , V_73 , V_72 ) ;
F_6 ( V_2 , 0 , V_30 ) ;
if ( V_71 & V_50 )
F_25 ( & V_2 -> V_37 ) ;
return V_74 ;
}
static int F_26 ( struct V_75 * V_76 )
{
struct V_77 * V_78 ;
struct V_79 * V_19 = & V_76 -> V_19 ;
struct V_80 * V_81 = F_27 ( & V_76 -> V_19 ) ;
int V_69 ;
struct V_56 * V_10 ;
struct V_82 * V_82 ;
struct V_1 * V_2 ;
int V_83 ;
V_69 = F_28 ( V_76 , 0 ) ;
if ( V_69 < 0 ) {
F_21 ( V_19 , L_6 ) ;
V_83 = - V_84 ;
goto V_85;
}
V_82 = F_29 ( V_19 , L_7 ) ;
if ( F_30 ( V_82 ) ) {
F_21 ( V_19 , L_8 ) ;
V_83 = F_31 ( V_82 ) ;
goto V_85;
}
V_10 = F_32 ( V_19 , sizeof( * V_2 ) ) ;
if ( ! V_10 ) {
F_21 ( V_19 , L_9 ) ;
V_83 = - V_86 ;
goto V_87;
}
V_2 = F_11 ( V_10 ) ;
F_33 ( V_76 , V_10 ) ;
V_2 -> V_76 = V_76 ;
V_78 = F_34 ( V_76 , V_88 , 0 ) ;
V_2 -> V_4 = F_35 ( & V_76 -> V_19 , V_78 ) ;
if ( F_30 ( V_2 -> V_4 ) ) {
V_83 = F_31 ( V_2 -> V_4 ) ;
goto V_89;
}
V_2 -> V_69 = V_69 ;
V_2 -> V_82 = V_82 ;
V_2 -> V_63 = V_81 -> V_63 ;
V_83 = F_36 ( & V_76 -> V_19 , V_69 , F_24 , 0 ,
V_76 -> V_90 , V_10 ) ;
if ( V_83 ) {
F_21 ( V_19 , L_10 ) ;
goto V_89;
}
V_10 -> V_91 = V_81 -> V_91 ;
V_10 -> V_92 = V_81 -> V_92 ;
V_10 -> V_93 = F_19 ;
V_10 -> V_94 = V_95 ;
V_10 -> V_96 = F_37 ( 8 ) ;
V_10 -> V_97 = true ;
V_2 -> V_40 = V_81 -> V_40 ;
V_2 -> V_43 = V_81 -> V_43 ;
V_2 -> V_34 = ( T_1 * ) ( V_2 -> V_4 + F_3 ( V_98 ) ) ;
V_2 -> V_55 = ( const T_1 * ) ( V_2 -> V_4 + F_3 ( V_99 ) ) ;
switch ( V_2 -> V_43 ) {
case 8 :
case 16 :
break;
default:
F_21 ( V_19 , L_11 ,
V_2 -> V_43 ) ;
goto V_89;
}
F_38 ( V_2 -> V_82 ) ;
F_6 ( V_2 , V_73 , V_72 ) ;
V_83 = F_39 ( V_19 , V_10 ) ;
if ( V_83 ) {
F_21 ( V_19 , L_12 ) ;
goto V_100;
}
F_40 ( V_19 , L_13 ,
V_78 -> V_101 , V_69 , V_2 -> V_63 ) ;
return 0 ;
V_100:
F_41 ( V_82 ) ;
V_89:
F_42 ( V_10 ) ;
V_87:
F_43 ( V_82 ) ;
V_85:
return V_83 ;
}
static int F_44 ( struct V_75 * V_76 )
{
struct V_56 * V_10 = F_45 ( V_76 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_6 ( V_2 , 0 , V_30 ) ;
F_41 ( V_2 -> V_82 ) ;
F_43 ( V_2 -> V_82 ) ;
return 0 ;
}
static int F_46 ( struct V_79 * V_19 )
{
struct V_56 * V_10 = F_47 ( V_19 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_48 ( V_10 ) ;
F_41 ( V_2 -> V_82 ) ;
return 0 ;
}
static int F_49 ( struct V_79 * V_19 )
{
struct V_56 * V_10 = F_47 ( V_19 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_38 ( V_2 -> V_82 ) ;
F_50 ( V_10 ) ;
return 0 ;
}
