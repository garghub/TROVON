static int F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( V_3 ) ( V_1 - V_2 ) > 0 ;
}
static struct V_4 * F_2 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_7 ;
return F_3 ( V_8 , struct V_4 , V_7 ) ;
}
static unsigned int F_4 ( struct V_4 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
return V_11 ? V_11 -> V_12 - 1 :
V_13 - 1 ;
}
static bool F_6 ( struct V_14 * V_15 ,
struct V_4 * V_16 )
{
struct V_4 * V_17 = V_15 -> V_17 ;
bool V_18 = false ;
if ( V_16 && V_16 != V_15 -> V_17 ) {
bool V_19 = true ;
if ( V_17 ) {
unsigned int V_20 =
F_4 ( V_16 ) ;
struct V_21 * V_22 =
V_15 -> V_23 + V_20 ;
V_19 =
( V_20 ==
F_4 ( V_17 )
&&
! F_1 ( V_16 -> V_24 , V_22 -> V_25 )
&&
F_1 ( V_17 -> V_26 ,
V_16 -> V_26 ) )
||
V_20 <
F_4 ( V_17 ) ;
}
if ( V_19 )
V_17 = V_16 ;
} else
V_17 = F_7 ( V_15 ) ;
if ( V_17 ) {
V_18 = ! V_15 -> V_17 ||
F_8 ( V_17 ) ;
}
V_15 -> V_17 = V_17 ;
if ( ! V_17 )
return V_18 ;
return V_18 ;
}
struct V_27 * F_9 ( struct V_10 * V_11 )
{
struct V_4 * V_28 = V_11 -> V_9 . V_29 ;
if ( ! V_28 )
V_28 = & V_11 -> V_30 -> V_31 -> V_9 ;
return F_10 ( V_28 , struct V_27 , V_9 ) ;
}
static bool F_8 ( struct V_4 * V_17 )
{
struct V_4 * V_32 ;
struct V_27 * V_33 ;
struct V_14 * V_34 ;
bool V_35 = false ;
V_34 = V_17 -> V_36 ;
V_33 = F_10 ( V_34 , struct V_27 , V_36 ) ;
V_32 = V_33 -> V_37 ;
if ( V_32 ) {
if ( V_32 -> V_38 > V_17 -> V_38 )
V_35 = true ;
V_32 -> V_38 = V_17 -> V_38 ;
}
return V_35 ;
}
static bool F_11 ( struct V_4 * V_9 )
{
struct V_27 * V_33 ;
if ( F_5 ( V_9 ) )
return true ;
V_33 = F_10 ( V_9 , struct V_27 , V_9 ) ;
if ( V_33 -> V_39 == 1 )
return true ;
return false ;
}
struct V_27 * F_9 ( struct V_10 * V_11 )
{
return V_11 -> V_30 -> V_31 ;
}
static bool F_8 ( struct V_4 * V_17 )
{
return false ;
}
static bool F_11 ( struct V_4 * V_9 )
{
return true ;
}
struct V_10 * F_5 ( struct V_4 * V_9 )
{
struct V_10 * V_11 = NULL ;
if ( ! V_9 -> V_40 )
V_11 = F_10 ( V_9 , struct V_10 , V_9 ) ;
return V_11 ;
}
static T_1 F_12 ( unsigned long V_41 , unsigned long V_42 )
{
T_1 V_43 = ( T_1 ) V_41 << V_44 ;
F_13 ( V_43 , V_42 ) ;
return V_43 ;
}
static void F_14 ( struct V_4 * V_9 , unsigned long V_41 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
V_9 -> V_26 = V_9 -> V_24 +
F_12 ( V_41 , V_9 -> V_42 ) ;
if ( V_11 ) {
F_15 ( V_11 -> V_30 , V_11 ,
L_1 ,
V_41 , V_9 -> V_42 ) ;
F_15 ( V_11 -> V_30 , V_11 ,
L_2 ,
V_9 -> V_24 , V_9 -> V_26 ,
F_12 ( V_41 , V_9 -> V_42 ) ) ;
}
}
struct V_4 * F_16 ( struct V_7 * V_8 )
{
struct V_4 * V_9 = NULL ;
if ( V_8 )
V_9 = F_3 ( V_8 , struct V_4 , V_7 ) ;
return V_9 ;
}
static void F_17 ( struct V_5 * V_45 , struct V_4 * V_9 )
{
V_9 -> V_6 = NULL ;
F_18 ( & V_9 -> V_7 , V_45 ) ;
}
static void F_19 ( struct V_21 * V_22 ,
struct V_4 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_46 ;
if ( V_9 == V_22 -> V_47 ) {
V_46 = F_20 ( & V_9 -> V_7 ) ;
V_22 -> V_47 = F_16 ( V_46 ) ;
}
if ( V_9 == V_22 -> V_48 ) {
V_46 = F_21 ( & V_9 -> V_7 ) ;
V_22 -> V_48 = F_16 ( V_46 ) ;
}
F_17 ( & V_22 -> V_49 , V_9 ) ;
if ( V_11 )
F_22 ( & V_11 -> V_50 ) ;
}
static void F_23 ( struct V_5 * V_45 , struct V_4 * V_9 )
{
struct V_4 * V_51 ;
struct V_7 * * V_8 = & V_45 -> V_7 ;
struct V_7 * V_29 = NULL ;
while ( * V_8 ) {
V_29 = * V_8 ;
V_51 = F_3 ( V_29 , struct V_4 , V_7 ) ;
if ( F_1 ( V_51 -> V_26 , V_9 -> V_26 ) )
V_8 = & V_29 -> V_52 ;
else
V_8 = & V_29 -> V_53 ;
}
F_24 ( & V_9 -> V_7 , V_29 , V_8 ) ;
F_25 ( & V_9 -> V_7 , V_45 ) ;
V_9 -> V_6 = V_45 ;
}
static void F_26 ( struct V_4 * V_9 , struct V_7 * V_8 )
{
struct V_4 * V_54 ;
if ( V_8 ) {
V_54 = F_3 ( V_8 , struct V_4 , V_7 ) ;
if ( F_1 ( V_9 -> V_55 , V_54 -> V_55 ) )
V_9 -> V_55 = V_54 -> V_55 ;
}
}
static void F_27 ( struct V_7 * V_8 )
{
struct V_4 * V_9 = F_3 ( V_8 , struct V_4 , V_7 ) ;
V_9 -> V_55 = V_9 -> V_24 ;
F_26 ( V_9 , V_8 -> V_53 ) ;
F_26 ( V_9 , V_8 -> V_52 ) ;
}
static void F_28 ( struct V_7 * V_8 )
{
struct V_7 * V_29 ;
V_56:
F_27 ( V_8 ) ;
V_29 = F_29 ( V_8 ) ;
if ( ! V_29 )
return;
if ( V_8 == V_29 -> V_52 && V_29 -> V_53 )
F_27 ( V_29 -> V_53 ) ;
else if ( V_29 -> V_52 )
F_27 ( V_29 -> V_52 ) ;
V_8 = V_29 ;
goto V_56;
}
static void F_30 ( struct V_21 * V_22 ,
struct V_4 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_8 = & V_9 -> V_7 ;
#ifdef F_31
struct V_14 * V_15 = NULL ;
struct V_27 * V_33 = NULL ;
struct V_57 * V_30 = NULL ;
#endif
F_23 ( & V_22 -> V_58 , V_9 ) ;
if ( V_8 -> V_52 )
V_8 = V_8 -> V_52 ;
else if ( V_8 -> V_53 )
V_8 = V_8 -> V_53 ;
F_28 ( V_8 ) ;
#ifdef F_31
V_15 = V_9 -> V_36 ;
V_33 = F_10 ( V_15 , struct V_27 , V_36 ) ;
V_30 = (struct V_57 * ) V_33 -> V_30 ;
#endif
if ( V_11 )
F_32 ( & V_11 -> V_50 , & V_11 -> V_30 -> V_59 ) ;
#ifdef F_31
else
F_33 ( V_30 , V_9 , & V_30 -> V_60 ) ;
if ( V_33 != V_30 -> V_31 )
V_33 -> V_39 ++ ;
#endif
}
unsigned short F_34 ( int V_61 )
{
return ( V_62 - V_61 ) * V_63 ;
}
static unsigned short F_35 ( int V_42 )
{
return F_36 ( int , 0 ,
V_62 * V_63 - V_42 ) ;
}
static void F_37 ( struct V_4 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
if ( V_11 ) {
V_11 -> V_64 ++ ;
F_15 ( V_11 -> V_30 , V_11 , L_3 ,
V_11 , V_11 -> V_64 ) ;
}
}
static struct V_7 * F_38 ( struct V_7 * V_8 )
{
struct V_7 * V_65 ;
if ( ! V_8 -> V_53 && ! V_8 -> V_52 )
V_65 = F_29 ( V_8 ) ;
else if ( ! V_8 -> V_53 )
V_65 = V_8 -> V_52 ;
else if ( ! V_8 -> V_52 )
V_65 = V_8 -> V_53 ;
else {
V_65 = F_20 ( V_8 ) ;
if ( V_65 -> V_53 )
V_65 = V_65 -> V_53 ;
else if ( F_29 ( V_65 ) != V_8 )
V_65 = F_29 ( V_65 ) ;
}
return V_65 ;
}
static void F_39 ( struct V_21 * V_22 ,
struct V_4 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_8 ;
#ifdef F_31
struct V_14 * V_15 = NULL ;
struct V_27 * V_33 = NULL ;
struct V_57 * V_30 = NULL ;
#endif
V_8 = F_38 ( & V_9 -> V_7 ) ;
F_17 ( & V_22 -> V_58 , V_9 ) ;
if ( V_8 )
F_28 ( V_8 ) ;
#ifdef F_31
V_15 = V_9 -> V_36 ;
V_33 = F_10 ( V_15 , struct V_27 , V_36 ) ;
V_30 = (struct V_57 * ) V_33 -> V_30 ;
#endif
if ( V_11 )
F_22 ( & V_11 -> V_50 ) ;
#ifdef F_31
else
F_40 ( V_30 , V_9 ,
& V_30 -> V_60 ) ;
if ( V_33 != V_30 -> V_31 )
V_33 -> V_39 -- ;
#endif
}
static void F_41 ( struct V_21 * V_22 ,
struct V_4 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_4 * V_47 = V_22 -> V_47 ;
struct V_4 * V_48 = V_22 -> V_48 ;
if ( ! V_47 || F_1 ( V_47 -> V_26 , V_9 -> V_26 ) )
V_22 -> V_47 = V_9 ;
if ( ! V_48 || F_1 ( V_9 -> V_26 , V_48 -> V_26 ) )
V_22 -> V_48 = V_9 ;
F_23 ( & V_22 -> V_49 , V_9 ) ;
if ( V_11 )
F_32 ( & V_11 -> V_50 , & V_11 -> V_30 -> V_66 ) ;
}
static void F_42 ( struct V_21 * V_22 ,
struct V_4 * V_9 ,
bool V_67 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
V_9 -> V_68 = false ;
V_22 -> V_69 -= V_9 -> V_42 ;
if ( V_11 && ! V_67 )
F_43 ( V_11 ) ;
}
void F_44 ( struct V_21 * V_22 , struct V_4 * V_9 )
{
F_19 ( V_22 , V_9 ) ;
F_42 ( V_22 , V_9 ,
V_9 == V_9 -> V_36 -> V_70 ) ;
}
static void F_45 ( struct V_21 * V_22 )
{
struct V_4 * V_47 = V_22 -> V_47 ;
struct V_4 * V_48 = V_22 -> V_48 ;
if ( F_46 ( & V_22 -> V_58 ) && V_48 &&
! F_1 ( V_48 -> V_26 , V_22 -> V_25 ) ) {
V_22 -> V_25 = V_48 -> V_26 ;
}
if ( V_47 && ! F_1 ( V_47 -> V_26 , V_22 -> V_25 ) )
F_44 ( V_22 , V_47 ) ;
}
struct V_21 * F_47 ( struct V_4 * V_9 )
{
struct V_14 * V_36 = V_9 -> V_36 ;
unsigned int V_71 = F_4 ( V_9 ) ;
return V_36 -> V_23 + V_71 ;
}
struct V_21 *
F_48 ( struct V_21 * V_72 ,
struct V_4 * V_9 ,
bool V_73 )
{
struct V_21 * V_74 = V_72 ;
if ( V_9 -> V_75 ) {
struct V_10 * V_11 = F_5 ( V_9 ) ;
unsigned int V_76 , V_77 ;
struct V_57 * V_30 = NULL ;
struct V_5 * V_45 ;
#ifdef F_31
struct V_14 * V_15 ;
struct V_27 * V_33 ;
#endif
if ( V_11 )
V_30 = V_11 -> V_30 ;
#ifdef F_31
else {
V_15 = V_9 -> V_40 ;
V_33 = F_10 ( V_15 , struct V_27 , V_36 ) ;
V_30 = (struct V_57 * ) V_33 -> V_30 ;
}
#endif
V_72 -> V_69 -= V_9 -> V_42 ;
if ( V_9 -> V_77 != V_9 -> V_78 ) {
if ( V_9 -> V_77 < V_79 ||
V_9 -> V_77 > V_80 ) {
F_49 ( L_4 ,
V_9 -> V_77 ) ;
if ( V_9 -> V_77 < V_79 )
V_9 -> V_77 = V_79 ;
else
V_9 -> V_77 = V_80 ;
}
V_9 -> V_78 = V_9 -> V_77 ;
if ( V_11 )
V_11 -> V_61 =
F_35 ( V_9 -> V_78 ) ;
}
if ( V_11 && V_73 )
V_11 -> V_12 = V_11 -> V_81 ;
if ( ! V_11 || V_11 -> V_12 == V_11 -> V_81 )
V_9 -> V_75 = 0 ;
V_74 = F_47 ( V_9 ) ;
V_76 = V_9 -> V_42 ;
V_77 = V_9 -> V_78 *
( V_11 ? V_11 -> V_82 : 1 ) ;
if ( V_76 != V_77 ) {
V_45 = V_11 ? & V_30 -> V_83 :
& V_30 -> V_60 ;
F_40 ( V_30 , V_9 , V_45 ) ;
}
V_9 -> V_42 = V_77 ;
if ( V_76 != V_77 &&
( V_11 ? V_11 -> V_82 == 1 : 1 ) )
F_33 ( V_30 , V_9 , V_45 ) ;
V_74 -> V_69 += V_9 -> V_42 ;
if ( V_74 != V_72 )
V_9 -> V_24 = V_74 -> V_25 ;
}
return V_74 ;
}
void F_50 ( struct V_10 * V_11 , int V_84 )
{
struct V_4 * V_9 = & V_11 -> V_9 ;
struct V_21 * V_22 ;
F_51 (entity) {
V_22 = F_47 ( V_9 ) ;
V_9 -> V_41 += V_84 ;
V_22 -> V_25 += F_12 ( V_84 , V_22 -> V_69 ) ;
F_45 ( V_22 ) ;
}
F_52 ( F_53 ( V_11 ) ) ;
F_15 ( V_11 -> V_30 , V_11 , L_5 , V_84 ) ;
}
void F_54 ( struct V_57 * V_30 , struct V_10 * V_11 ,
unsigned long V_85 )
{
struct V_4 * V_9 = & V_11 -> V_9 ;
int V_86 = V_9 -> V_41 ;
unsigned int V_87 = F_55 ( V_88 ) ;
if ( V_85 > 0 && V_85 < V_87 )
V_86 =
( V_30 -> V_89 * V_85 ) / V_87 ;
if ( V_86 < V_9 -> V_41 )
V_86 = V_9 -> V_41 ;
if ( V_86 > V_9 -> V_38 )
V_9 -> V_38 = V_86 ;
F_50 ( V_11 ,
F_36 ( int , 0 , V_86 - V_9 -> V_41 ) ) ;
}
static void F_56 ( struct V_4 * V_9 ,
struct V_21 * V_22 ,
bool V_90 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
V_22 = F_48 ( V_22 , V_9 , true ) ;
F_14 ( V_9 , V_9 -> V_38 ) ;
if ( V_90 && F_1 ( V_22 -> V_25 , V_9 -> V_26 ) ) {
unsigned long V_91 = V_22 -> V_25 - V_9 -> V_26 ;
if ( V_11 )
V_91 /= V_11 -> V_82 ;
V_9 -> V_24 += V_91 ;
V_9 -> V_26 += V_91 ;
}
F_30 ( V_22 , V_9 ) ;
}
static void F_57 ( struct V_4 * V_9 ,
bool V_92 )
{
struct V_21 * V_22 = F_47 ( V_9 ) ;
bool V_90 = false ;
unsigned long long V_93 ;
if ( V_92 && F_1 ( V_22 -> V_25 , V_9 -> V_26 ) ) {
V_90 = true ;
V_93 = V_9 -> V_26 ;
} else
V_93 = V_22 -> V_25 ;
if ( V_9 -> V_6 == & V_22 -> V_49 ) {
F_19 ( V_22 , V_9 ) ;
V_9 -> V_24 = F_1 ( V_93 , V_9 -> V_26 ) ?
V_93 : V_9 -> V_26 ;
} else {
V_9 -> V_24 = V_93 ;
V_22 -> V_69 += V_9 -> V_42 ;
F_37 ( V_9 ) ;
V_9 -> V_68 = true ;
}
F_56 ( V_9 , V_22 , V_90 ) ;
}
static void F_58 ( struct V_4 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_36 ;
struct V_21 * V_22 = F_47 ( V_9 ) ;
if ( V_9 == V_15 -> V_70 ) {
F_14 ( V_9 , V_9 -> V_41 ) ;
V_9 -> V_24 = V_9 -> V_26 ;
if ( V_9 -> V_6 )
F_39 ( V_22 , V_9 ) ;
} else {
F_39 ( V_22 , V_9 ) ;
}
F_56 ( V_9 , V_22 , false ) ;
}
static void F_59 ( struct V_4 * V_9 ,
struct V_14 * V_15 ,
bool V_92 )
{
struct V_21 * V_22 = F_47 ( V_9 ) ;
if ( V_15 -> V_70 == V_9 || V_9 -> V_6 == & V_22 -> V_58 )
F_58 ( V_9 ) ;
else
F_57 ( V_9 , V_92 ) ;
}
static void F_60 ( struct V_4 * V_9 ,
bool V_92 ,
bool V_94 )
{
struct V_14 * V_15 ;
F_51 (entity) {
V_15 = V_9 -> V_36 ;
F_59 ( V_9 , V_15 , V_92 ) ;
if ( ! F_6 ( V_15 , V_9 ) && ! V_94 )
break;
}
}
bool F_61 ( struct V_4 * V_9 , bool V_95 )
{
struct V_14 * V_15 = V_9 -> V_36 ;
struct V_21 * V_22 ;
bool V_67 ;
if ( ! V_9 -> V_68 )
return false ;
V_22 = F_47 ( V_9 ) ;
V_67 = V_9 == V_15 -> V_70 ;
if ( V_67 ) {
F_14 ( V_9 , V_9 -> V_41 ) ;
V_15 -> V_70 = NULL ;
}
if ( V_9 -> V_6 == & V_22 -> V_58 )
F_39 ( V_22 , V_9 ) ;
else if ( ! V_67 && V_9 -> V_6 == & V_22 -> V_49 )
F_19 ( V_22 , V_9 ) ;
if ( ! V_95 || ! F_1 ( V_9 -> V_26 , V_22 -> V_25 ) )
F_42 ( V_22 , V_9 , V_67 ) ;
else
F_41 ( V_22 , V_9 ) ;
return true ;
}
static void F_62 ( struct V_4 * V_9 ,
bool V_95 ,
bool V_96 )
{
struct V_14 * V_15 ;
struct V_4 * V_29 = NULL ;
F_63 (entity, parent) {
V_15 = V_9 -> V_36 ;
if ( ! F_61 ( V_9 , V_95 ) ) {
return;
}
if ( V_15 -> V_17 == V_9 )
F_6 ( V_15 , NULL ) ;
if ( V_15 -> V_17 || V_15 -> V_70 ) {
break;
}
V_95 = true ;
}
V_9 = V_29 ;
F_51 (entity) {
F_58 ( V_9 ) ;
V_15 = V_9 -> V_36 ;
if ( ! F_6 ( V_15 , V_9 ) &&
! V_96 )
break;
}
}
static T_1 F_64 ( struct V_21 * V_22 )
{
struct V_4 * V_97 = F_2 ( & V_22 -> V_58 ) ;
if ( F_1 ( V_97 -> V_55 , V_22 -> V_25 ) )
return V_97 -> V_55 ;
return V_22 -> V_25 ;
}
static void F_65 ( struct V_21 * V_22 , T_1 V_98 )
{
if ( V_98 > V_22 -> V_25 ) {
V_22 -> V_25 = V_98 ;
F_45 ( V_22 ) ;
}
}
static struct V_4 * F_66 ( struct V_21 * V_22 ,
T_1 V_25 )
{
struct V_4 * V_51 , * V_99 = NULL ;
struct V_7 * V_8 = V_22 -> V_58 . V_7 ;
while ( V_8 ) {
V_51 = F_3 ( V_8 , struct V_4 , V_7 ) ;
V_100:
if ( ! F_1 ( V_51 -> V_24 , V_25 ) )
V_99 = V_51 ;
if ( V_8 -> V_52 ) {
V_51 = F_3 ( V_8 -> V_52 ,
struct V_4 , V_7 ) ;
if ( ! F_1 ( V_51 -> V_55 , V_25 ) ) {
V_8 = V_8 -> V_52 ;
goto V_100;
}
}
if ( V_99 )
break;
V_8 = V_8 -> V_53 ;
}
return V_99 ;
}
static struct V_4 *
F_67 ( struct V_21 * V_22 , bool V_101 )
{
struct V_4 * V_9 ;
T_1 V_102 ;
if ( F_46 ( & V_22 -> V_58 ) )
return NULL ;
V_102 = F_64 ( V_22 ) ;
if ( ! V_101 )
F_65 ( V_22 , V_102 ) ;
V_9 = F_66 ( V_22 , V_102 ) ;
return V_9 ;
}
static struct V_4 * F_7 ( struct V_14 * V_15 )
{
struct V_21 * V_22 = V_15 -> V_23 ;
struct V_21 * V_103 = V_22 + ( V_104 - 1 ) ;
struct V_4 * V_9 = NULL ;
int V_105 = 0 ;
if ( F_68 ( V_15 -> V_106 +
V_107 ) ) {
if ( ! F_46 ( & V_103 -> V_58 ) )
V_105 = V_104 - 1 ;
V_15 -> V_106 = V_108 ;
}
for (; V_105 < V_104 ; V_105 ++ ) {
V_9 = F_67 ( V_22 + V_105 ,
V_15 -> V_70 ) ;
if ( V_9 )
break;
}
if ( ! V_9 )
return NULL ;
return V_9 ;
}
bool F_69 ( struct V_57 * V_30 )
{
struct V_14 * V_15 = & V_30 -> V_31 -> V_36 ;
return V_15 -> V_17 != V_15 -> V_70 ;
}
struct V_10 * F_70 ( struct V_57 * V_30 )
{
struct V_4 * V_9 = NULL ;
struct V_14 * V_15 ;
struct V_10 * V_11 ;
if ( V_30 -> V_109 == 0 )
return NULL ;
V_15 = & V_30 -> V_31 -> V_36 ;
for (; V_15 ; V_15 = V_9 -> V_40 ) {
V_9 = V_15 -> V_17 ;
V_15 -> V_70 = V_9 ;
V_9 -> V_41 = 0 ;
if ( F_11 ( V_9 ) )
F_39 ( F_47 ( V_9 ) ,
V_9 ) ;
}
V_11 = F_5 ( V_9 ) ;
F_51 (entity) {
struct V_14 * V_15 = V_9 -> V_36 ;
if ( ! F_6 ( V_15 , NULL ) )
break;
}
return V_11 ;
}
void F_71 ( struct V_57 * V_30 )
{
struct V_10 * V_110 = V_30 -> V_111 ;
struct V_4 * V_112 = & V_110 -> V_9 ;
struct V_4 * V_9 = V_112 ;
F_72 ( V_110 ) ;
F_73 ( & V_30 -> V_113 ) ;
V_30 -> V_111 = NULL ;
F_51 (entity)
V_9 -> V_36 -> V_70 = NULL ;
if ( ! V_112 -> V_68 )
F_43 ( V_110 ) ;
}
void F_74 ( struct V_57 * V_30 , struct V_10 * V_11 ,
bool V_95 , bool V_96 )
{
struct V_4 * V_9 = & V_11 -> V_9 ;
F_62 ( V_9 , V_95 , V_96 ) ;
}
void F_75 ( struct V_57 * V_30 , struct V_10 * V_11 )
{
struct V_4 * V_9 = & V_11 -> V_9 ;
F_60 ( V_9 , F_76 ( V_11 ) ,
false ) ;
F_77 ( V_11 ) ;
}
void F_78 ( struct V_57 * V_30 , struct V_10 * V_11 )
{
struct V_4 * V_9 = & V_11 -> V_9 ;
F_60 ( V_9 , false ,
V_11 == V_30 -> V_111 ) ;
}
void F_79 ( struct V_57 * V_30 , struct V_10 * V_11 ,
bool V_96 )
{
F_15 ( V_30 , V_11 , L_6 ) ;
F_80 ( V_11 ) ;
V_30 -> V_109 -- ;
if ( ! V_11 -> V_114 )
F_40 ( V_30 , & V_11 -> V_9 ,
& V_30 -> V_83 ) ;
if ( V_11 -> V_82 > 1 )
V_30 -> V_115 -- ;
F_81 ( F_53 ( V_11 ) ) ;
F_74 ( V_30 , V_11 , true , V_96 ) ;
}
void F_82 ( struct V_57 * V_30 , struct V_10 * V_11 )
{
F_15 ( V_30 , V_11 , L_7 ) ;
F_75 ( V_30 , V_11 ) ;
F_83 ( V_11 ) ;
V_30 -> V_109 ++ ;
if ( ! V_11 -> V_114 )
if ( V_11 -> V_82 == 1 )
F_33 ( V_30 , & V_11 -> V_9 ,
& V_30 -> V_83 ) ;
if ( V_11 -> V_82 > 1 )
V_30 -> V_115 ++ ;
}
