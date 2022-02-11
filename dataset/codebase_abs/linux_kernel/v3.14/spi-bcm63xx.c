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
if ( ! V_28 )
return 0 ;
V_27 = 0 ;
V_9 = V_20 ;
for ( V_13 = 0 ; V_13 < V_21 ; V_13 ++ ) {
if ( V_9 -> V_32 )
F_18 ( V_9 -> V_32 , V_2 -> V_53 + V_27 , V_9 -> V_27 ) ;
if ( V_9 != V_20 || V_26 == 0 )
V_27 += V_9 -> V_27 ;
V_9 = F_15 ( V_9 -> V_35 . V_36 , struct V_8 ,
V_35 ) ;
}
return 0 ;
}
static int F_19 ( struct V_54 * V_10 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 , * V_20 = NULL ;
struct V_6 * V_7 = V_56 -> V_7 ;
int V_57 = 0 ;
unsigned int V_58 = 0 , V_59 = 0 ;
bool V_60 = false ;
F_20 (t, &m->transfers, transfer_list) {
if ( ! V_20 )
V_20 = V_9 ;
V_58 ++ ;
V_59 += V_9 -> V_27 ;
if ( V_58 == 2 && ! V_20 -> V_32 && ! V_9 -> V_31 &&
V_20 -> V_27 <= V_33 )
V_60 = true ;
else if ( V_60 && V_9 -> V_31 )
V_60 = false ;
if ( ( V_60 &&
V_59 > ( V_2 -> V_61 + V_33 ) ) ||
( ! V_60 && V_59 > V_2 -> V_61 ) ) {
F_21 ( & V_7 -> V_19 , L_3 ,
V_59 , V_2 -> V_61 ) ;
V_57 = - V_62 ;
goto exit;
}
if ( V_9 -> V_15 != V_20 -> V_15 ) {
F_21 ( & V_7 -> V_19 , L_4 ) ;
V_57 = - V_62 ;
goto exit;
}
if ( V_9 -> V_63 ) {
F_21 ( & V_7 -> V_19 , L_5 ) ;
V_57 = - V_62 ;
goto exit;
}
if ( V_9 -> V_64 ||
F_22 ( & V_9 -> V_35 , & V_56 -> V_65 ) ) {
F_10 ( V_7 , V_20 ) ;
V_57 = F_13 ( V_7 , V_20 , V_58 ) ;
if ( V_57 )
goto exit;
V_56 -> V_66 += V_59 ;
V_20 = NULL ;
V_58 = 0 ;
V_59 = 0 ;
V_60 = false ;
}
}
exit:
V_56 -> V_57 = V_57 ;
F_23 ( V_10 ) ;
return 0 ;
}
static T_3 F_24 ( int V_67 , void * V_68 )
{
struct V_54 * V_10 = (struct V_54 * ) V_68 ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
T_1 V_69 ;
V_69 = F_1 ( V_2 , V_70 ) ;
F_6 ( V_2 , V_71 , V_70 ) ;
F_6 ( V_2 , 0 , V_30 ) ;
if ( V_69 & V_50 )
F_25 ( & V_2 -> V_37 ) ;
return V_72 ;
}
static int F_26 ( struct V_73 * V_74 )
{
struct V_75 * V_76 ;
struct V_77 * V_19 = & V_74 -> V_19 ;
struct V_78 * V_79 = F_27 ( & V_74 -> V_19 ) ;
int V_67 ;
struct V_54 * V_10 ;
struct V_80 * V_80 ;
struct V_1 * V_2 ;
int V_81 ;
V_67 = F_28 ( V_74 , 0 ) ;
if ( V_67 < 0 ) {
F_21 ( V_19 , L_6 ) ;
return - V_82 ;
}
V_80 = F_29 ( V_19 , L_7 ) ;
if ( F_30 ( V_80 ) ) {
F_21 ( V_19 , L_8 ) ;
return F_31 ( V_80 ) ;
}
V_10 = F_32 ( V_19 , sizeof( * V_2 ) ) ;
if ( ! V_10 ) {
F_21 ( V_19 , L_9 ) ;
return - V_83 ;
}
V_2 = F_11 ( V_10 ) ;
F_33 ( V_74 , V_10 ) ;
V_2 -> V_74 = V_74 ;
V_76 = F_34 ( V_74 , V_84 , 0 ) ;
V_2 -> V_4 = F_35 ( & V_74 -> V_19 , V_76 ) ;
if ( F_30 ( V_2 -> V_4 ) ) {
V_81 = F_31 ( V_2 -> V_4 ) ;
goto V_85;
}
V_2 -> V_67 = V_67 ;
V_2 -> V_80 = V_80 ;
V_2 -> V_61 = V_79 -> V_61 ;
V_81 = F_36 ( & V_74 -> V_19 , V_67 , F_24 , 0 ,
V_74 -> V_86 , V_10 ) ;
if ( V_81 ) {
F_21 ( V_19 , L_10 ) ;
goto V_85;
}
V_10 -> V_87 = V_79 -> V_87 ;
V_10 -> V_88 = V_79 -> V_88 ;
V_10 -> V_89 = F_19 ;
V_10 -> V_90 = V_91 ;
V_10 -> V_92 = F_37 ( 8 ) ;
V_10 -> V_93 = true ;
V_2 -> V_40 = V_79 -> V_40 ;
V_2 -> V_43 = V_79 -> V_43 ;
V_2 -> V_34 = ( T_1 * ) ( V_2 -> V_4 + F_3 ( V_94 ) ) ;
V_2 -> V_53 = ( const T_1 * ) ( V_2 -> V_4 + F_3 ( V_95 ) ) ;
switch ( V_2 -> V_43 ) {
case 8 :
case 16 :
break;
default:
F_21 ( V_19 , L_11 ,
V_2 -> V_43 ) ;
goto V_85;
}
V_81 = F_38 ( V_2 -> V_80 ) ;
if ( V_81 )
goto V_85;
F_6 ( V_2 , V_71 , V_70 ) ;
V_81 = F_39 ( V_19 , V_10 ) ;
if ( V_81 ) {
F_21 ( V_19 , L_12 ) ;
goto V_96;
}
F_40 ( V_19 , L_13 ,
V_76 -> V_97 , V_67 , V_2 -> V_61 ) ;
return 0 ;
V_96:
F_41 ( V_80 ) ;
V_85:
F_42 ( V_10 ) ;
return V_81 ;
}
static int F_43 ( struct V_73 * V_74 )
{
struct V_54 * V_10 = F_44 ( V_74 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_6 ( V_2 , 0 , V_30 ) ;
F_41 ( V_2 -> V_80 ) ;
return 0 ;
}
static int F_45 ( struct V_77 * V_19 )
{
struct V_54 * V_10 = F_46 ( V_19 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_47 ( V_10 ) ;
F_41 ( V_2 -> V_80 ) ;
return 0 ;
}
static int F_48 ( struct V_77 * V_19 )
{
struct V_54 * V_10 = F_46 ( V_19 ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
int V_81 ;
V_81 = F_38 ( V_2 -> V_80 ) ;
if ( V_81 )
return V_81 ;
F_49 ( V_10 ) ;
return 0 ;
}
