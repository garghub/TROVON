static inline T_1 F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_2 -> V_5 [ V_3 ] ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
#ifdef F_4
return F_5 ( V_2 -> V_4 + V_2 -> V_5 [ V_3 ] ) ;
#else
return F_6 ( V_2 -> V_4 + V_2 -> V_5 [ V_3 ] ) ;
#endif
}
static inline void F_7 ( struct V_1 * V_2 ,
T_1 V_6 , unsigned int V_3 )
{
F_8 ( V_6 , V_2 -> V_4 + V_2 -> V_5 [ V_3 ] ) ;
}
static inline void F_9 ( struct V_1 * V_2 ,
T_2 V_6 , unsigned int V_3 )
{
#ifdef F_4
F_10 ( V_6 , V_2 -> V_4 + V_2 -> V_5 [ V_3 ] ) ;
#else
F_11 ( V_6 , V_2 -> V_4 + V_2 -> V_5 [ V_3 ] ) ;
#endif
}
static void F_12 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_8 -> V_11 ) ;
T_1 V_12 , V_13 ;
int V_14 ;
V_12 = V_15 ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
if ( V_10 -> V_17 >= V_18 [ V_14 ] [ 0 ] ) {
V_12 = V_18 [ V_14 ] [ 1 ] ;
break;
}
}
V_13 = F_1 ( V_2 , V_19 ) ;
V_13 &= ~ V_16 ;
V_13 |= V_12 ;
F_7 ( V_2 , V_13 , V_19 ) ;
F_14 ( & V_8 -> V_20 , L_1 ,
V_12 , V_10 -> V_17 ) ;
}
static int F_15 ( struct V_7 * V_8 , struct V_9 * V_21 ,
unsigned int V_22 )
{
struct V_1 * V_2 = F_13 ( V_8 -> V_11 ) ;
T_2 V_23 ;
T_2 V_24 ;
unsigned int V_14 , V_25 = 0 , V_26 = 0 , V_27 = 0 ;
struct V_9 * V_10 = V_21 ;
bool V_28 = false ;
bool V_29 = false ;
F_7 ( V_2 , 0 , V_30 ) ;
F_14 ( & V_8 -> V_20 , L_2 ,
V_10 -> V_31 , V_10 -> V_32 , V_10 -> V_27 ) ;
if ( V_22 > 1 && V_10 -> V_31 && V_10 -> V_27 <= V_33 )
V_26 = V_10 -> V_27 ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
if ( V_10 -> V_31 ) {
V_29 = true ;
F_16 ( V_2 -> V_34 + V_27 , V_10 -> V_31 , V_10 -> V_27 ) ;
if ( V_10 != V_21 )
V_26 = 0 ;
}
if ( V_10 -> V_32 ) {
V_28 = true ;
if ( V_10 == V_21 )
V_26 = 0 ;
}
V_27 += V_10 -> V_27 ;
V_10 = F_17 ( V_10 -> V_35 . V_36 , struct V_9 ,
V_35 ) ;
}
F_18 ( & V_2 -> V_37 ) ;
V_23 = ( V_27 << V_38 ) ;
if ( V_28 && V_29 && V_26 == 0 )
V_23 |= ( V_39 << V_2 -> V_40 ) ;
else if ( V_28 )
V_23 |= ( V_41 << V_2 -> V_40 ) ;
else if ( V_29 )
V_23 |= ( V_42 << V_2 -> V_40 ) ;
switch ( V_2 -> V_43 ) {
case 8 :
F_7 ( V_2 , V_23 , V_44 ) ;
break;
case 16 :
F_9 ( V_2 , V_23 , V_44 ) ;
break;
}
V_24 = V_45 ;
V_24 |= ( V_26 << V_46 ) ;
V_24 |= ( V_8 -> V_47 << V_48 ) ;
F_9 ( V_2 , V_24 , V_49 ) ;
F_7 ( V_2 , V_50 , V_30 ) ;
V_25 = F_19 ( & V_2 -> V_37 , V_51 ) ;
if ( ! V_25 )
return - V_52 ;
if ( ! V_28 )
return 0 ;
V_27 = 0 ;
V_10 = V_21 ;
for ( V_14 = 0 ; V_14 < V_22 ; V_14 ++ ) {
if ( V_10 -> V_32 )
F_20 ( V_10 -> V_32 , V_2 -> V_53 + V_27 , V_10 -> V_27 ) ;
if ( V_10 != V_21 || V_26 == 0 )
V_27 += V_10 -> V_27 ;
V_10 = F_17 ( V_10 -> V_35 . V_36 , struct V_9 ,
V_35 ) ;
}
return 0 ;
}
static int F_21 ( struct V_54 * V_11 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
struct V_9 * V_10 , * V_21 = NULL ;
struct V_7 * V_8 = V_56 -> V_8 ;
int V_57 = 0 ;
unsigned int V_58 = 0 , V_59 = 0 ;
bool V_60 = false ;
F_22 (t, &m->transfers, transfer_list) {
if ( ! V_21 )
V_21 = V_10 ;
V_58 ++ ;
V_59 += V_10 -> V_27 ;
if ( V_58 == 2 && ! V_21 -> V_32 && ! V_10 -> V_31 &&
V_21 -> V_27 <= V_33 )
V_60 = true ;
else if ( V_60 && V_10 -> V_31 )
V_60 = false ;
if ( ( V_60 &&
V_59 > ( V_2 -> V_61 + V_33 ) ) ||
( ! V_60 && V_59 > V_2 -> V_61 ) ) {
F_23 ( & V_8 -> V_20 , L_3 ,
V_59 , V_2 -> V_61 ) ;
V_57 = - V_62 ;
goto exit;
}
if ( V_10 -> V_17 != V_21 -> V_17 ) {
F_23 ( & V_8 -> V_20 , L_4 ) ;
V_57 = - V_62 ;
goto exit;
}
if ( V_10 -> V_63 ) {
F_23 ( & V_8 -> V_20 , L_5 ) ;
V_57 = - V_62 ;
goto exit;
}
if ( V_10 -> V_64 ||
F_24 ( & V_10 -> V_35 , & V_56 -> V_65 ) ) {
F_12 ( V_8 , V_21 ) ;
V_57 = F_15 ( V_8 , V_21 , V_58 ) ;
if ( V_57 )
goto exit;
V_56 -> V_66 += V_59 ;
V_21 = NULL ;
V_58 = 0 ;
V_59 = 0 ;
V_60 = false ;
}
}
exit:
V_56 -> V_57 = V_57 ;
F_25 ( V_11 ) ;
return 0 ;
}
static T_3 F_26 ( int V_67 , void * V_68 )
{
struct V_54 * V_11 = (struct V_54 * ) V_68 ;
struct V_1 * V_2 = F_13 ( V_11 ) ;
T_1 V_69 ;
V_69 = F_1 ( V_2 , V_70 ) ;
F_7 ( V_2 , V_71 , V_70 ) ;
F_7 ( V_2 , 0 , V_30 ) ;
if ( V_69 & V_50 )
F_27 ( & V_2 -> V_37 ) ;
return V_72 ;
}
static int F_28 ( struct V_73 * V_74 )
{
struct V_75 * V_76 ;
const unsigned long * V_77 ;
struct V_78 * V_20 = & V_74 -> V_20 ;
int V_67 ;
struct V_54 * V_11 ;
struct V_79 * V_79 ;
struct V_1 * V_2 ;
int V_80 ;
if ( ! V_74 -> V_81 -> V_82 )
return - V_62 ;
V_77 = ( const unsigned long * ) V_74 -> V_81 -> V_82 ;
V_67 = F_29 ( V_74 , 0 ) ;
if ( V_67 < 0 ) {
F_23 ( V_20 , L_6 ) ;
return - V_83 ;
}
V_79 = F_30 ( V_20 , L_7 ) ;
if ( F_31 ( V_79 ) ) {
F_23 ( V_20 , L_8 ) ;
return F_32 ( V_79 ) ;
}
V_11 = F_33 ( V_20 , sizeof( * V_2 ) ) ;
if ( ! V_11 ) {
F_23 ( V_20 , L_9 ) ;
return - V_84 ;
}
V_2 = F_13 ( V_11 ) ;
F_34 ( & V_2 -> V_37 ) ;
F_35 ( V_74 , V_11 ) ;
V_2 -> V_74 = V_74 ;
V_76 = F_36 ( V_74 , V_85 , 0 ) ;
V_2 -> V_4 = F_37 ( & V_74 -> V_20 , V_76 ) ;
if ( F_31 ( V_2 -> V_4 ) ) {
V_80 = F_32 ( V_2 -> V_4 ) ;
goto V_86;
}
V_2 -> V_67 = V_67 ;
V_2 -> V_79 = V_79 ;
V_2 -> V_5 = V_77 ;
V_2 -> V_61 = V_2 -> V_5 [ V_87 ] ;
V_80 = F_38 ( & V_74 -> V_20 , V_67 , F_26 , 0 ,
V_74 -> V_88 , V_11 ) ;
if ( V_80 ) {
F_23 ( V_20 , L_10 ) ;
goto V_86;
}
V_11 -> V_89 = V_90 ;
V_11 -> V_91 = V_92 ;
V_11 -> V_93 = F_21 ;
V_11 -> V_94 = V_95 ;
V_11 -> V_96 = F_39 ( 8 ) ;
V_11 -> V_97 = true ;
V_2 -> V_40 = V_2 -> V_5 [ V_98 ] ;
V_2 -> V_43 = V_2 -> V_5 [ V_99 ] ;
V_2 -> V_34 = ( T_1 * ) ( V_2 -> V_4 + V_2 -> V_5 [ V_100 ] ) ;
V_2 -> V_53 = ( const T_1 * ) ( V_2 -> V_4 + V_2 -> V_5 [ V_101 ] ) ;
V_80 = F_40 ( V_2 -> V_79 ) ;
if ( V_80 )
goto V_86;
F_7 ( V_2 , V_71 , V_70 ) ;
V_80 = F_41 ( V_20 , V_11 ) ;
if ( V_80 ) {
F_23 ( V_20 , L_11 ) ;
goto V_102;
}
F_42 ( V_20 , L_12 ,
V_76 , V_67 , V_2 -> V_61 ) ;
return 0 ;
V_102:
F_43 ( V_79 ) ;
V_86:
F_44 ( V_11 ) ;
return V_80 ;
}
static int F_45 ( struct V_73 * V_74 )
{
struct V_54 * V_11 = F_46 ( V_74 ) ;
struct V_1 * V_2 = F_13 ( V_11 ) ;
F_7 ( V_2 , 0 , V_30 ) ;
F_43 ( V_2 -> V_79 ) ;
return 0 ;
}
static int F_47 ( struct V_78 * V_20 )
{
struct V_54 * V_11 = F_48 ( V_20 ) ;
struct V_1 * V_2 = F_13 ( V_11 ) ;
F_49 ( V_11 ) ;
F_43 ( V_2 -> V_79 ) ;
return 0 ;
}
static int F_50 ( struct V_78 * V_20 )
{
struct V_54 * V_11 = F_48 ( V_20 ) ;
struct V_1 * V_2 = F_13 ( V_11 ) ;
int V_80 ;
V_80 = F_40 ( V_2 -> V_79 ) ;
if ( V_80 )
return V_80 ;
F_51 ( V_11 ) ;
return 0 ;
}
