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
static int F_19 ( struct V_56 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_20 ( & V_2 -> V_57 -> V_19 ) ;
return 0 ;
}
static int F_21 ( struct V_56 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_22 ( & V_2 -> V_57 -> V_19 ) ;
return 0 ;
}
static int F_23 ( struct V_56 * V_10 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 , * V_20 = NULL ;
struct V_6 * V_7 = V_59 -> V_7 ;
int V_60 = 0 ;
unsigned int V_61 = 0 , V_62 = 0 ;
bool V_63 = false ;
F_24 (t, &m->transfers, transfer_list) {
if ( ! V_20 )
V_20 = V_9 ;
V_61 ++ ;
V_62 += V_9 -> V_27 ;
if ( V_61 == 2 && ! V_20 -> V_32 && ! V_9 -> V_31 &&
V_20 -> V_27 <= V_33 )
V_63 = true ;
else if ( V_63 && V_9 -> V_31 )
V_63 = false ;
if ( ( V_63 &&
V_62 > ( V_2 -> V_64 + V_33 ) ) ||
( ! V_63 && V_62 > V_2 -> V_64 ) ) {
F_25 ( & V_7 -> V_19 , L_3 ,
V_62 , V_2 -> V_64 ) ;
V_60 = - V_65 ;
goto exit;
}
if ( V_9 -> V_15 != V_20 -> V_15 ) {
F_25 ( & V_7 -> V_19 , L_4 ) ;
V_60 = - V_65 ;
goto exit;
}
if ( V_9 -> V_66 ) {
F_25 ( & V_7 -> V_19 , L_5 ) ;
V_60 = - V_65 ;
goto exit;
}
if ( V_9 -> V_67 ||
F_26 ( & V_9 -> V_35 , & V_59 -> V_68 ) ) {
F_10 ( V_7 , V_20 ) ;
V_60 = F_13 ( V_7 , V_20 , V_61 ) ;
if ( V_60 )
goto exit;
V_59 -> V_69 += V_62 ;
V_20 = NULL ;
V_61 = 0 ;
V_62 = 0 ;
V_63 = false ;
}
}
exit:
V_59 -> V_60 = V_60 ;
F_27 ( V_10 ) ;
return 0 ;
}
static T_3 F_28 ( int V_70 , void * V_71 )
{
struct V_56 * V_10 = (struct V_56 * ) V_71 ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
T_1 V_72 ;
V_72 = F_1 ( V_2 , V_73 ) ;
F_6 ( V_2 , V_74 , V_73 ) ;
F_6 ( V_2 , 0 , V_30 ) ;
if ( V_72 & V_50 )
F_29 ( & V_2 -> V_37 ) ;
return V_75 ;
}
static int F_30 ( struct V_76 * V_57 )
{
struct V_77 * V_78 ;
struct V_79 * V_19 = & V_57 -> V_19 ;
struct V_80 * V_81 = V_57 -> V_19 . V_82 ;
int V_70 ;
struct V_56 * V_10 ;
struct V_83 * V_83 ;
struct V_1 * V_2 ;
int V_84 ;
V_78 = F_31 ( V_57 , V_85 , 0 ) ;
if ( ! V_78 ) {
F_25 ( V_19 , L_6 ) ;
V_84 = - V_86 ;
goto V_87;
}
V_70 = F_32 ( V_57 , 0 ) ;
if ( V_70 < 0 ) {
F_25 ( V_19 , L_7 ) ;
V_84 = - V_86 ;
goto V_87;
}
V_83 = F_33 ( V_19 , L_8 ) ;
if ( F_34 ( V_83 ) ) {
F_25 ( V_19 , L_9 ) ;
V_84 = F_35 ( V_83 ) ;
goto V_87;
}
V_10 = F_36 ( V_19 , sizeof( * V_2 ) ) ;
if ( ! V_10 ) {
F_25 ( V_19 , L_10 ) ;
V_84 = - V_88 ;
goto V_89;
}
V_2 = F_11 ( V_10 ) ;
F_37 ( V_57 , V_10 ) ;
V_2 -> V_57 = V_57 ;
V_2 -> V_4 = F_38 ( & V_57 -> V_19 , V_78 ) ;
if ( F_34 ( V_2 -> V_4 ) ) {
V_84 = F_35 ( V_2 -> V_4 ) ;
goto V_90;
}
V_2 -> V_70 = V_70 ;
V_2 -> V_83 = V_83 ;
V_2 -> V_64 = V_81 -> V_64 ;
V_84 = F_39 ( & V_57 -> V_19 , V_70 , F_28 , 0 ,
V_57 -> V_91 , V_10 ) ;
if ( V_84 ) {
F_25 ( V_19 , L_11 ) ;
goto V_90;
}
V_10 -> V_92 = V_81 -> V_92 ;
V_10 -> V_93 = V_81 -> V_93 ;
V_10 -> V_94 = F_19 ;
V_10 -> V_95 = F_21 ;
V_10 -> V_96 = F_23 ;
V_10 -> V_97 = V_98 ;
V_10 -> V_99 = F_40 ( 8 ) ;
V_2 -> V_40 = V_81 -> V_40 ;
V_2 -> V_43 = V_81 -> V_43 ;
V_2 -> V_34 = ( T_1 * ) ( V_2 -> V_4 + F_3 ( V_100 ) ) ;
V_2 -> V_55 = ( const T_1 * ) ( V_2 -> V_4 + F_3 ( V_101 ) ) ;
switch ( V_2 -> V_43 ) {
case 8 :
case 16 :
break;
default:
F_25 ( V_19 , L_12 ,
V_2 -> V_43 ) ;
goto V_90;
}
F_41 ( V_2 -> V_83 ) ;
F_6 ( V_2 , V_74 , V_73 ) ;
V_84 = F_42 ( V_10 ) ;
if ( V_84 ) {
F_25 ( V_19 , L_13 ) ;
goto V_102;
}
F_43 ( V_19 , L_14 ,
V_78 -> V_103 , V_70 , V_2 -> V_64 ) ;
return 0 ;
V_102:
F_44 ( V_83 ) ;
V_90:
F_45 ( V_10 ) ;
V_89:
F_46 ( V_83 ) ;
V_87:
return V_84 ;
}
static int F_47 ( struct V_76 * V_57 )
{
struct V_56 * V_10 = F_48 ( F_49 ( V_57 ) ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_50 ( V_10 ) ;
F_6 ( V_2 , 0 , V_30 ) ;
F_44 ( V_2 -> V_83 ) ;
F_46 ( V_2 -> V_83 ) ;
F_45 ( V_10 ) ;
return 0 ;
}
static int F_51 ( struct V_79 * V_19 )
{
struct V_56 * V_10 =
F_49 ( F_52 ( V_19 ) ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_53 ( V_10 ) ;
F_44 ( V_2 -> V_83 ) ;
return 0 ;
}
static int F_54 ( struct V_79 * V_19 )
{
struct V_56 * V_10 =
F_49 ( F_52 ( V_19 ) ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_41 ( V_2 -> V_83 ) ;
F_55 ( V_10 ) ;
return 0 ;
}
