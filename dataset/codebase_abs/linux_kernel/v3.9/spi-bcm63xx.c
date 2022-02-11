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
if ( V_17 >= V_24 [ V_20 ] [ 0 ] ) {
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
V_2 = F_13 ( V_7 -> V_15 ) ;
if ( ! V_7 -> V_10 )
V_7 -> V_10 = 8 ;
if ( V_7 -> V_27 & ~ V_28 ) {
F_11 ( & V_7 -> V_11 , L_4 ,
V_12 , V_7 -> V_27 & ~ V_28 ) ;
return - V_13 ;
}
F_14 ( & V_7 -> V_11 , L_5 ,
V_12 , V_7 -> V_27 & V_28 , V_7 -> V_10 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , struct V_8 * V_29 ,
unsigned int V_30 )
{
struct V_1 * V_2 = F_13 ( V_7 -> V_15 ) ;
T_2 V_31 ;
T_2 V_32 ;
T_1 V_33 ;
unsigned int V_20 , V_34 = 0 , V_35 = 0 , V_36 = 0 ;
struct V_8 * V_9 = V_29 ;
bool V_37 = false ;
bool V_38 = false ;
F_6 ( V_2 , 0 , V_39 ) ;
F_14 ( & V_7 -> V_11 , L_6 ,
V_9 -> V_40 , V_9 -> V_41 , V_9 -> V_36 ) ;
if ( V_30 > 1 && V_9 -> V_40 && V_9 -> V_36 <= V_42 )
V_35 = V_9 -> V_36 ;
for ( V_20 = 0 ; V_20 < V_30 ; V_20 ++ ) {
if ( V_9 -> V_40 ) {
V_38 = true ;
F_17 ( V_2 -> V_43 + V_36 , V_9 -> V_40 , V_9 -> V_36 ) ;
if ( V_9 != V_29 )
V_35 = 0 ;
}
if ( V_9 -> V_41 ) {
V_37 = true ;
if ( V_9 == V_29 )
V_35 = 0 ;
}
V_36 += V_9 -> V_36 ;
V_9 = F_18 ( V_9 -> V_44 . V_45 , struct V_8 ,
V_44 ) ;
}
V_36 -= V_35 ;
F_19 ( & V_2 -> V_46 ) ;
V_31 = ( V_36 << V_47 ) ;
if ( V_37 && V_38 && V_35 == 0 )
V_31 |= ( V_48 << V_2 -> V_49 ) ;
else if ( V_37 )
V_31 |= ( V_50 << V_2 -> V_49 ) ;
else if ( V_38 )
V_31 |= ( V_51 << V_2 -> V_49 ) ;
switch ( V_2 -> V_52 ) {
case 8 :
F_6 ( V_2 , V_31 , V_53 ) ;
break;
case 16 :
F_8 ( V_2 , V_31 , V_53 ) ;
break;
}
V_32 = V_54 ;
V_32 |= ( V_35 << V_55 ) ;
V_32 |= ( V_7 -> V_14 << V_56 ) ;
F_8 ( V_2 , V_32 , V_57 ) ;
F_6 ( V_2 , V_58 , V_39 ) ;
V_34 = F_20 ( & V_2 -> V_46 , V_59 ) ;
if ( ! V_34 )
return - V_60 ;
V_33 = F_1 ( V_2 , V_61 ) ;
if ( V_37 && V_33 != V_36 )
return - V_62 ;
if ( ! V_33 )
return 0 ;
V_36 = 0 ;
V_9 = V_29 ;
for ( V_20 = 0 ; V_20 < V_30 ; V_20 ++ ) {
if ( V_9 -> V_41 )
F_21 ( V_9 -> V_41 , V_2 -> V_63 + V_36 , V_9 -> V_36 ) ;
if ( V_9 != V_29 || V_35 == 0 )
V_36 += V_9 -> V_36 ;
V_9 = F_18 ( V_9 -> V_44 . V_45 , struct V_8 ,
V_44 ) ;
}
return 0 ;
}
static int F_22 ( struct V_64 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
F_23 ( & V_2 -> V_65 -> V_11 ) ;
return 0 ;
}
static int F_24 ( struct V_64 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
F_25 ( & V_2 -> V_65 -> V_11 ) ;
return 0 ;
}
static int F_26 ( struct V_64 * V_15 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_8 * V_9 , * V_29 = NULL ;
struct V_6 * V_7 = V_67 -> V_7 ;
int V_68 = 0 ;
unsigned int V_69 = 0 , V_70 = 0 ;
bool V_71 = false ;
F_27 (t, &m->transfers, transfer_list) {
V_68 = F_10 ( V_7 , V_9 ) ;
if ( V_68 < 0 )
goto exit;
if ( ! V_29 )
V_29 = V_9 ;
V_69 ++ ;
V_70 += V_9 -> V_36 ;
if ( V_69 == 2 && ! V_29 -> V_41 && ! V_9 -> V_40 &&
V_29 -> V_36 <= V_42 )
V_71 = true ;
else if ( V_71 && V_9 -> V_40 )
V_71 = false ;
if ( ( V_71 &&
V_70 > ( V_2 -> V_72 + V_42 ) ) ||
( ! V_71 && V_70 > V_2 -> V_72 ) ) {
F_11 ( & V_7 -> V_11 , L_7 ,
V_70 , V_2 -> V_72 ) ;
V_68 = - V_13 ;
goto exit;
}
if ( V_9 -> V_21 != V_29 -> V_21 ) {
F_11 ( & V_7 -> V_11 , L_8 ) ;
V_68 = - V_13 ;
goto exit;
}
if ( V_9 -> V_73 ) {
F_11 ( & V_7 -> V_11 , L_9 ) ;
V_68 = - V_13 ;
goto exit;
}
if ( V_9 -> V_74 ||
F_28 ( & V_9 -> V_44 , & V_67 -> V_75 ) ) {
F_12 ( V_7 , V_29 ) ;
V_68 = F_16 ( V_7 , V_29 , V_69 ) ;
if ( V_68 )
goto exit;
V_67 -> V_76 += V_70 ;
V_29 = NULL ;
V_69 = 0 ;
V_70 = 0 ;
V_71 = false ;
}
}
exit:
V_67 -> V_68 = V_68 ;
F_29 ( V_15 ) ;
return 0 ;
}
static T_4 F_30 ( int V_77 , void * V_78 )
{
struct V_64 * V_15 = (struct V_64 * ) V_78 ;
struct V_1 * V_2 = F_13 ( V_15 ) ;
T_1 V_79 ;
V_79 = F_1 ( V_2 , V_80 ) ;
F_6 ( V_2 , V_81 , V_80 ) ;
F_6 ( V_2 , 0 , V_39 ) ;
if ( V_79 & V_58 )
F_31 ( & V_2 -> V_46 ) ;
return V_82 ;
}
static int F_32 ( struct V_83 * V_65 )
{
struct V_84 * V_85 ;
struct V_86 * V_11 = & V_65 -> V_11 ;
struct V_87 * V_88 = V_65 -> V_11 . V_89 ;
int V_77 ;
struct V_64 * V_15 ;
struct V_90 * V_90 ;
struct V_1 * V_2 ;
int V_91 ;
V_85 = F_33 ( V_65 , V_92 , 0 ) ;
if ( ! V_85 ) {
F_11 ( V_11 , L_10 ) ;
V_91 = - V_93 ;
goto V_94;
}
V_77 = F_34 ( V_65 , 0 ) ;
if ( V_77 < 0 ) {
F_11 ( V_11 , L_11 ) ;
V_91 = - V_93 ;
goto V_94;
}
V_90 = F_35 ( V_11 , L_12 ) ;
if ( F_36 ( V_90 ) ) {
F_11 ( V_11 , L_13 ) ;
V_91 = F_37 ( V_90 ) ;
goto V_94;
}
V_15 = F_38 ( V_11 , sizeof( * V_2 ) ) ;
if ( ! V_15 ) {
F_11 ( V_11 , L_14 ) ;
V_91 = - V_95 ;
goto V_96;
}
V_2 = F_13 ( V_15 ) ;
F_39 ( V_65 , V_15 ) ;
V_2 -> V_65 = V_65 ;
if ( ! F_40 ( & V_65 -> V_11 , V_85 -> V_97 ,
F_41 ( V_85 ) , V_98 ) ) {
F_11 ( V_11 , L_15 ) ;
V_91 = - V_93 ;
goto V_99;
}
V_2 -> V_4 = F_42 ( & V_65 -> V_11 , V_85 -> V_97 ,
F_41 ( V_85 ) ) ;
if ( ! V_2 -> V_4 ) {
F_11 ( V_11 , L_16 ) ;
V_91 = - V_95 ;
goto V_99;
}
V_2 -> V_77 = V_77 ;
V_2 -> V_90 = V_90 ;
V_2 -> V_72 = V_88 -> V_72 ;
V_91 = F_43 ( & V_65 -> V_11 , V_77 , F_30 , 0 ,
V_65 -> V_100 , V_15 ) ;
if ( V_91 ) {
F_11 ( V_11 , L_17 ) ;
goto V_99;
}
V_15 -> V_101 = V_88 -> V_101 ;
V_15 -> V_16 = V_88 -> V_16 ;
V_15 -> V_102 = F_15 ;
V_15 -> V_103 = F_22 ;
V_15 -> V_104 = F_24 ;
V_15 -> V_105 = F_26 ;
V_15 -> V_106 = V_28 ;
V_2 -> V_21 = V_88 -> V_21 ;
V_2 -> V_49 = V_88 -> V_49 ;
V_2 -> V_52 = V_88 -> V_52 ;
V_2 -> V_43 = ( T_1 * ) ( V_2 -> V_4 + F_3 ( V_107 ) ) ;
V_2 -> V_63 = ( const T_1 * ) ( V_2 -> V_4 + F_3 ( V_108 ) ) ;
switch ( V_2 -> V_52 ) {
case 8 :
case 16 :
break;
default:
F_11 ( V_11 , L_18 ,
V_2 -> V_52 ) ;
goto V_99;
}
F_44 ( V_2 -> V_90 ) ;
F_6 ( V_2 , V_81 , V_80 ) ;
V_91 = F_45 ( V_15 ) ;
if ( V_91 ) {
F_11 ( V_11 , L_19 ) ;
goto V_109;
}
F_46 ( V_11 , L_20 ,
V_85 -> V_97 , V_77 , V_2 -> V_72 ) ;
return 0 ;
V_109:
F_47 ( V_90 ) ;
V_99:
F_39 ( V_65 , NULL ) ;
F_48 ( V_15 ) ;
V_96:
F_49 ( V_90 ) ;
V_94:
return V_91 ;
}
static int F_50 ( struct V_83 * V_65 )
{
struct V_64 * V_15 = F_51 ( F_52 ( V_65 ) ) ;
struct V_1 * V_2 = F_13 ( V_15 ) ;
F_53 ( V_15 ) ;
F_6 ( V_2 , 0 , V_39 ) ;
F_47 ( V_2 -> V_90 ) ;
F_49 ( V_2 -> V_90 ) ;
F_39 ( V_65 , 0 ) ;
F_48 ( V_15 ) ;
return 0 ;
}
static int F_54 ( struct V_86 * V_11 )
{
struct V_64 * V_15 =
F_52 ( F_55 ( V_11 ) ) ;
struct V_1 * V_2 = F_13 ( V_15 ) ;
F_56 ( V_15 ) ;
F_47 ( V_2 -> V_90 ) ;
return 0 ;
}
static int F_57 ( struct V_86 * V_11 )
{
struct V_64 * V_15 =
F_52 ( F_55 ( V_11 ) ) ;
struct V_1 * V_2 = F_13 ( V_15 ) ;
F_44 ( V_2 -> V_90 ) ;
F_58 ( V_15 ) ;
return 0 ;
}
