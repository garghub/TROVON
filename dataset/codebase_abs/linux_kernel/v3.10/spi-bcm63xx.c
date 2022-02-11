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
static int F_13 ( struct V_6 * V_7 )
{
if ( V_7 -> V_20 != 8 ) {
F_14 ( & V_7 -> V_19 , L_2 ,
V_21 , V_7 -> V_20 ) ;
return - V_22 ;
}
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , struct V_8 * V_23 ,
unsigned int V_24 )
{
struct V_1 * V_2 = F_11 ( V_7 -> V_10 ) ;
T_2 V_25 ;
T_2 V_26 ;
T_1 V_27 ;
unsigned int V_13 , V_28 = 0 , V_29 = 0 , V_30 = 0 ;
struct V_8 * V_9 = V_23 ;
bool V_31 = false ;
bool V_32 = false ;
F_6 ( V_2 , 0 , V_33 ) ;
F_12 ( & V_7 -> V_19 , L_3 ,
V_9 -> V_34 , V_9 -> V_35 , V_9 -> V_30 ) ;
if ( V_24 > 1 && V_9 -> V_34 && V_9 -> V_30 <= V_36 )
V_29 = V_9 -> V_30 ;
for ( V_13 = 0 ; V_13 < V_24 ; V_13 ++ ) {
if ( V_9 -> V_34 ) {
V_32 = true ;
F_16 ( V_2 -> V_37 + V_30 , V_9 -> V_34 , V_9 -> V_30 ) ;
if ( V_9 != V_23 )
V_29 = 0 ;
}
if ( V_9 -> V_35 ) {
V_31 = true ;
if ( V_9 == V_23 )
V_29 = 0 ;
}
V_30 += V_9 -> V_30 ;
V_9 = F_17 ( V_9 -> V_38 . V_39 , struct V_8 ,
V_38 ) ;
}
V_30 -= V_29 ;
F_18 ( & V_2 -> V_40 ) ;
V_25 = ( V_30 << V_41 ) ;
if ( V_31 && V_32 && V_29 == 0 )
V_25 |= ( V_42 << V_2 -> V_43 ) ;
else if ( V_31 )
V_25 |= ( V_44 << V_2 -> V_43 ) ;
else if ( V_32 )
V_25 |= ( V_45 << V_2 -> V_43 ) ;
switch ( V_2 -> V_46 ) {
case 8 :
F_6 ( V_2 , V_25 , V_47 ) ;
break;
case 16 :
F_8 ( V_2 , V_25 , V_47 ) ;
break;
}
V_26 = V_48 ;
V_26 |= ( V_29 << V_49 ) ;
V_26 |= ( V_7 -> V_50 << V_51 ) ;
F_8 ( V_2 , V_26 , V_52 ) ;
F_6 ( V_2 , V_53 , V_33 ) ;
V_28 = F_19 ( & V_2 -> V_40 , V_54 ) ;
if ( ! V_28 )
return - V_55 ;
V_27 = F_1 ( V_2 , V_56 ) ;
if ( V_31 && V_27 != V_30 )
return - V_57 ;
if ( ! V_27 )
return 0 ;
V_30 = 0 ;
V_9 = V_23 ;
for ( V_13 = 0 ; V_13 < V_24 ; V_13 ++ ) {
if ( V_9 -> V_35 )
F_20 ( V_9 -> V_35 , V_2 -> V_58 + V_30 , V_9 -> V_30 ) ;
if ( V_9 != V_23 || V_29 == 0 )
V_30 += V_9 -> V_30 ;
V_9 = F_17 ( V_9 -> V_38 . V_39 , struct V_8 ,
V_38 ) ;
}
return 0 ;
}
static int F_21 ( struct V_59 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_22 ( & V_2 -> V_60 -> V_19 ) ;
return 0 ;
}
static int F_23 ( struct V_59 * V_10 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_24 ( & V_2 -> V_60 -> V_19 ) ;
return 0 ;
}
static int F_25 ( struct V_59 * V_10 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_11 ( V_10 ) ;
struct V_8 * V_9 , * V_23 = NULL ;
struct V_6 * V_7 = V_62 -> V_7 ;
int V_63 = 0 ;
unsigned int V_64 = 0 , V_65 = 0 ;
bool V_66 = false ;
F_26 (t, &m->transfers, transfer_list) {
if ( V_9 -> V_20 != 8 ) {
F_14 ( & V_7 -> V_19 , L_2 ,
V_21 , V_9 -> V_20 ) ;
V_63 = - V_22 ;
goto exit;
}
if ( ! V_23 )
V_23 = V_9 ;
V_64 ++ ;
V_65 += V_9 -> V_30 ;
if ( V_64 == 2 && ! V_23 -> V_35 && ! V_9 -> V_34 &&
V_23 -> V_30 <= V_36 )
V_66 = true ;
else if ( V_66 && V_9 -> V_34 )
V_66 = false ;
if ( ( V_66 &&
V_65 > ( V_2 -> V_67 + V_36 ) ) ||
( ! V_66 && V_65 > V_2 -> V_67 ) ) {
F_14 ( & V_7 -> V_19 , L_4 ,
V_65 , V_2 -> V_67 ) ;
V_63 = - V_22 ;
goto exit;
}
if ( V_9 -> V_15 != V_23 -> V_15 ) {
F_14 ( & V_7 -> V_19 , L_5 ) ;
V_63 = - V_22 ;
goto exit;
}
if ( V_9 -> V_68 ) {
F_14 ( & V_7 -> V_19 , L_6 ) ;
V_63 = - V_22 ;
goto exit;
}
if ( V_9 -> V_69 ||
F_27 ( & V_9 -> V_38 , & V_62 -> V_70 ) ) {
F_10 ( V_7 , V_23 ) ;
V_63 = F_15 ( V_7 , V_23 , V_64 ) ;
if ( V_63 )
goto exit;
V_62 -> V_71 += V_65 ;
V_23 = NULL ;
V_64 = 0 ;
V_65 = 0 ;
V_66 = false ;
}
}
exit:
V_62 -> V_63 = V_63 ;
F_28 ( V_10 ) ;
return 0 ;
}
static T_3 F_29 ( int V_72 , void * V_73 )
{
struct V_59 * V_10 = (struct V_59 * ) V_73 ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
T_1 V_74 ;
V_74 = F_1 ( V_2 , V_75 ) ;
F_6 ( V_2 , V_76 , V_75 ) ;
F_6 ( V_2 , 0 , V_33 ) ;
if ( V_74 & V_53 )
F_30 ( & V_2 -> V_40 ) ;
return V_77 ;
}
static int F_31 ( struct V_78 * V_60 )
{
struct V_79 * V_80 ;
struct V_81 * V_19 = & V_60 -> V_19 ;
struct V_82 * V_83 = V_60 -> V_19 . V_84 ;
int V_72 ;
struct V_59 * V_10 ;
struct V_85 * V_85 ;
struct V_1 * V_2 ;
int V_86 ;
V_80 = F_32 ( V_60 , V_87 , 0 ) ;
if ( ! V_80 ) {
F_14 ( V_19 , L_7 ) ;
V_86 = - V_88 ;
goto V_89;
}
V_72 = F_33 ( V_60 , 0 ) ;
if ( V_72 < 0 ) {
F_14 ( V_19 , L_8 ) ;
V_86 = - V_88 ;
goto V_89;
}
V_85 = F_34 ( V_19 , L_9 ) ;
if ( F_35 ( V_85 ) ) {
F_14 ( V_19 , L_10 ) ;
V_86 = F_36 ( V_85 ) ;
goto V_89;
}
V_10 = F_37 ( V_19 , sizeof( * V_2 ) ) ;
if ( ! V_10 ) {
F_14 ( V_19 , L_11 ) ;
V_86 = - V_90 ;
goto V_91;
}
V_2 = F_11 ( V_10 ) ;
F_38 ( V_60 , V_10 ) ;
V_2 -> V_60 = V_60 ;
V_2 -> V_4 = F_39 ( & V_60 -> V_19 , V_80 ) ;
if ( F_35 ( V_2 -> V_4 ) ) {
V_86 = F_36 ( V_2 -> V_4 ) ;
goto V_92;
}
V_2 -> V_72 = V_72 ;
V_2 -> V_85 = V_85 ;
V_2 -> V_67 = V_83 -> V_67 ;
V_86 = F_40 ( & V_60 -> V_19 , V_72 , F_29 , 0 ,
V_60 -> V_93 , V_10 ) ;
if ( V_86 ) {
F_14 ( V_19 , L_12 ) ;
goto V_92;
}
V_10 -> V_94 = V_83 -> V_94 ;
V_10 -> V_95 = V_83 -> V_95 ;
V_10 -> V_96 = F_13 ;
V_10 -> V_97 = F_21 ;
V_10 -> V_98 = F_23 ;
V_10 -> V_99 = F_25 ;
V_10 -> V_100 = V_101 ;
V_2 -> V_43 = V_83 -> V_43 ;
V_2 -> V_46 = V_83 -> V_46 ;
V_2 -> V_37 = ( T_1 * ) ( V_2 -> V_4 + F_3 ( V_102 ) ) ;
V_2 -> V_58 = ( const T_1 * ) ( V_2 -> V_4 + F_3 ( V_103 ) ) ;
switch ( V_2 -> V_46 ) {
case 8 :
case 16 :
break;
default:
F_14 ( V_19 , L_13 ,
V_2 -> V_46 ) ;
goto V_92;
}
F_41 ( V_2 -> V_85 ) ;
F_6 ( V_2 , V_76 , V_75 ) ;
V_86 = F_42 ( V_10 ) ;
if ( V_86 ) {
F_14 ( V_19 , L_14 ) ;
goto V_104;
}
F_43 ( V_19 , L_15 ,
V_80 -> V_105 , V_72 , V_2 -> V_67 ) ;
return 0 ;
V_104:
F_44 ( V_85 ) ;
V_92:
F_38 ( V_60 , NULL ) ;
F_45 ( V_10 ) ;
V_91:
F_46 ( V_85 ) ;
V_89:
return V_86 ;
}
static int F_47 ( struct V_78 * V_60 )
{
struct V_59 * V_10 = F_48 ( F_49 ( V_60 ) ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_50 ( V_10 ) ;
F_6 ( V_2 , 0 , V_33 ) ;
F_44 ( V_2 -> V_85 ) ;
F_46 ( V_2 -> V_85 ) ;
F_38 ( V_60 , 0 ) ;
F_45 ( V_10 ) ;
return 0 ;
}
static int F_51 ( struct V_81 * V_19 )
{
struct V_59 * V_10 =
F_49 ( F_52 ( V_19 ) ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_53 ( V_10 ) ;
F_44 ( V_2 -> V_85 ) ;
return 0 ;
}
static int F_54 ( struct V_81 * V_19 )
{
struct V_59 * V_10 =
F_49 ( F_52 ( V_19 ) ) ;
struct V_1 * V_2 = F_11 ( V_10 ) ;
F_41 ( V_2 -> V_85 ) ;
F_55 ( V_10 ) ;
return 0 ;
}
