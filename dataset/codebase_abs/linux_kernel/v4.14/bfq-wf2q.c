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
struct V_4 * V_16 ,
bool V_17 )
{
struct V_4 * V_18 = V_15 -> V_18 ;
bool V_19 = false ;
bool V_20 = false ;
if ( V_16 && V_16 != V_15 -> V_18 ) {
V_20 = true ;
if ( V_18 ) {
unsigned int V_21 =
F_4 ( V_16 ) ;
struct V_22 * V_23 =
V_15 -> V_24 + V_21 ;
V_20 =
( V_21 ==
F_4 ( V_18 )
&&
! F_1 ( V_16 -> V_25 , V_23 -> V_26 )
&&
F_1 ( V_18 -> V_27 ,
V_16 -> V_27 ) ) ;
}
if ( V_20 )
V_18 = V_16 ;
}
if ( ! V_20 )
V_18 = F_7 ( V_15 , V_17 ) ;
if ( V_18 )
V_19 = ! V_15 -> V_18 ||
F_8 ( V_18 ) ;
V_15 -> V_18 = V_18 ;
if ( ! V_18 )
return V_19 ;
return V_19 ;
}
struct V_28 * F_9 ( struct V_10 * V_11 )
{
struct V_4 * V_29 = V_11 -> V_9 . V_30 ;
if ( ! V_29 )
V_29 = & V_11 -> V_31 -> V_32 -> V_9 ;
return F_10 ( V_29 , struct V_28 , V_9 ) ;
}
static bool F_8 ( struct V_4 * V_18 )
{
struct V_4 * V_33 ;
struct V_28 * V_34 ;
struct V_14 * V_35 ;
bool V_36 = false ;
V_35 = V_18 -> V_37 ;
V_34 = F_10 ( V_35 , struct V_28 , V_37 ) ;
V_33 = V_34 -> V_38 ;
if ( V_33 ) {
if ( V_33 -> V_39 > V_18 -> V_39 )
V_36 = true ;
V_33 -> V_39 = V_18 -> V_39 ;
}
return V_36 ;
}
static bool F_11 ( struct V_4 * V_9 )
{
struct V_28 * V_34 ;
if ( F_5 ( V_9 ) )
return true ;
V_34 = F_10 ( V_9 , struct V_28 , V_9 ) ;
if ( V_34 -> V_40 == 1 )
return true ;
return false ;
}
struct V_28 * F_9 ( struct V_10 * V_11 )
{
return V_11 -> V_31 -> V_32 ;
}
static bool F_8 ( struct V_4 * V_18 )
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
if ( ! V_9 -> V_41 )
V_11 = F_10 ( V_9 , struct V_10 , V_9 ) ;
return V_11 ;
}
static T_1 F_12 ( unsigned long V_42 , unsigned long V_43 )
{
T_1 V_44 = ( T_1 ) V_42 << V_45 ;
F_13 ( V_44 , V_43 ) ;
return V_44 ;
}
static void F_14 ( struct V_4 * V_9 , unsigned long V_42 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
V_9 -> V_27 = V_9 -> V_25 +
F_12 ( V_42 , V_9 -> V_43 ) ;
if ( V_11 ) {
F_15 ( V_11 -> V_31 , V_11 ,
L_1 ,
V_42 , V_9 -> V_43 ) ;
F_15 ( V_11 -> V_31 , V_11 ,
L_2 ,
V_9 -> V_25 , V_9 -> V_27 ,
F_12 ( V_42 , V_9 -> V_43 ) ) ;
}
}
struct V_4 * F_16 ( struct V_7 * V_8 )
{
struct V_4 * V_9 = NULL ;
if ( V_8 )
V_9 = F_3 ( V_8 , struct V_4 , V_7 ) ;
return V_9 ;
}
static void F_17 ( struct V_5 * V_46 , struct V_4 * V_9 )
{
V_9 -> V_6 = NULL ;
F_18 ( & V_9 -> V_7 , V_46 ) ;
}
static void F_19 ( struct V_22 * V_23 ,
struct V_4 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_47 ;
if ( V_9 == V_23 -> V_48 ) {
V_47 = F_20 ( & V_9 -> V_7 ) ;
V_23 -> V_48 = F_16 ( V_47 ) ;
}
if ( V_9 == V_23 -> V_49 ) {
V_47 = F_21 ( & V_9 -> V_7 ) ;
V_23 -> V_49 = F_16 ( V_47 ) ;
}
F_17 ( & V_23 -> V_50 , V_9 ) ;
if ( V_11 )
F_22 ( & V_11 -> V_51 ) ;
}
static void F_23 ( struct V_5 * V_46 , struct V_4 * V_9 )
{
struct V_4 * V_52 ;
struct V_7 * * V_8 = & V_46 -> V_7 ;
struct V_7 * V_30 = NULL ;
while ( * V_8 ) {
V_30 = * V_8 ;
V_52 = F_3 ( V_30 , struct V_4 , V_7 ) ;
if ( F_1 ( V_52 -> V_27 , V_9 -> V_27 ) )
V_8 = & V_30 -> V_53 ;
else
V_8 = & V_30 -> V_54 ;
}
F_24 ( & V_9 -> V_7 , V_30 , V_8 ) ;
F_25 ( & V_9 -> V_7 , V_46 ) ;
V_9 -> V_6 = V_46 ;
}
static void F_26 ( struct V_4 * V_9 , struct V_7 * V_8 )
{
struct V_4 * V_55 ;
if ( V_8 ) {
V_55 = F_3 ( V_8 , struct V_4 , V_7 ) ;
if ( F_1 ( V_9 -> V_56 , V_55 -> V_56 ) )
V_9 -> V_56 = V_55 -> V_56 ;
}
}
static void F_27 ( struct V_7 * V_8 )
{
struct V_4 * V_9 = F_3 ( V_8 , struct V_4 , V_7 ) ;
V_9 -> V_56 = V_9 -> V_25 ;
F_26 ( V_9 , V_8 -> V_54 ) ;
F_26 ( V_9 , V_8 -> V_53 ) ;
}
static void F_28 ( struct V_7 * V_8 )
{
struct V_7 * V_30 ;
V_57:
F_27 ( V_8 ) ;
V_30 = F_29 ( V_8 ) ;
if ( ! V_30 )
return;
if ( V_8 == V_30 -> V_53 && V_30 -> V_54 )
F_27 ( V_30 -> V_54 ) ;
else if ( V_30 -> V_53 )
F_27 ( V_30 -> V_53 ) ;
V_8 = V_30 ;
goto V_57;
}
static void F_30 ( struct V_22 * V_23 ,
struct V_4 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_8 = & V_9 -> V_7 ;
#ifdef F_31
struct V_14 * V_15 = NULL ;
struct V_28 * V_34 = NULL ;
struct V_58 * V_31 = NULL ;
#endif
F_23 ( & V_23 -> V_59 , V_9 ) ;
if ( V_8 -> V_53 )
V_8 = V_8 -> V_53 ;
else if ( V_8 -> V_54 )
V_8 = V_8 -> V_54 ;
F_28 ( V_8 ) ;
#ifdef F_31
V_15 = V_9 -> V_37 ;
V_34 = F_10 ( V_15 , struct V_28 , V_37 ) ;
V_31 = (struct V_58 * ) V_34 -> V_31 ;
#endif
if ( V_11 )
F_32 ( & V_11 -> V_51 , & V_11 -> V_31 -> V_60 ) ;
#ifdef F_31
else
F_33 ( V_31 , V_9 , & V_31 -> V_61 ) ;
if ( V_34 != V_31 -> V_32 )
V_34 -> V_40 ++ ;
#endif
}
unsigned short F_34 ( int V_62 )
{
return ( V_63 - V_62 ) * V_64 ;
}
static unsigned short F_35 ( int V_43 )
{
return F_36 ( int , 0 ,
V_63 * V_64 - V_43 ) ;
}
static void F_37 ( struct V_4 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
if ( V_11 ) {
V_11 -> V_65 ++ ;
F_15 ( V_11 -> V_31 , V_11 , L_3 ,
V_11 , V_11 -> V_65 ) ;
}
}
static struct V_7 * F_38 ( struct V_7 * V_8 )
{
struct V_7 * V_66 ;
if ( ! V_8 -> V_54 && ! V_8 -> V_53 )
V_66 = F_29 ( V_8 ) ;
else if ( ! V_8 -> V_54 )
V_66 = V_8 -> V_53 ;
else if ( ! V_8 -> V_53 )
V_66 = V_8 -> V_54 ;
else {
V_66 = F_20 ( V_8 ) ;
if ( V_66 -> V_54 )
V_66 = V_66 -> V_54 ;
else if ( F_29 ( V_66 ) != V_8 )
V_66 = F_29 ( V_66 ) ;
}
return V_66 ;
}
static void F_39 ( struct V_22 * V_23 ,
struct V_4 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_7 * V_8 ;
#ifdef F_31
struct V_14 * V_15 = NULL ;
struct V_28 * V_34 = NULL ;
struct V_58 * V_31 = NULL ;
#endif
V_8 = F_38 ( & V_9 -> V_7 ) ;
F_17 ( & V_23 -> V_59 , V_9 ) ;
if ( V_8 )
F_28 ( V_8 ) ;
#ifdef F_31
V_15 = V_9 -> V_37 ;
V_34 = F_10 ( V_15 , struct V_28 , V_37 ) ;
V_31 = (struct V_58 * ) V_34 -> V_31 ;
#endif
if ( V_11 )
F_22 ( & V_11 -> V_51 ) ;
#ifdef F_31
else
F_40 ( V_31 , V_9 ,
& V_31 -> V_61 ) ;
if ( V_34 != V_31 -> V_32 )
V_34 -> V_40 -- ;
#endif
}
static void F_41 ( struct V_22 * V_23 ,
struct V_4 * V_9 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
struct V_4 * V_48 = V_23 -> V_48 ;
struct V_4 * V_49 = V_23 -> V_49 ;
if ( ! V_48 || F_1 ( V_48 -> V_27 , V_9 -> V_27 ) )
V_23 -> V_48 = V_9 ;
if ( ! V_49 || F_1 ( V_9 -> V_27 , V_49 -> V_27 ) )
V_23 -> V_49 = V_9 ;
F_23 ( & V_23 -> V_50 , V_9 ) ;
if ( V_11 )
F_32 ( & V_11 -> V_51 , & V_11 -> V_31 -> V_67 ) ;
}
static void F_42 ( struct V_22 * V_23 ,
struct V_4 * V_9 ,
bool V_68 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
V_9 -> V_69 = false ;
V_23 -> V_70 -= V_9 -> V_43 ;
if ( V_11 && ! V_68 )
F_43 ( V_11 ) ;
}
void F_44 ( struct V_22 * V_23 , struct V_4 * V_9 )
{
F_19 ( V_23 , V_9 ) ;
F_42 ( V_23 , V_9 ,
V_9 == V_9 -> V_37 -> V_71 ) ;
}
static void F_45 ( struct V_22 * V_23 )
{
struct V_4 * V_48 = V_23 -> V_48 ;
struct V_4 * V_49 = V_23 -> V_49 ;
if ( F_46 ( & V_23 -> V_59 ) && V_49 &&
! F_1 ( V_49 -> V_27 , V_23 -> V_26 ) ) {
V_23 -> V_26 = V_49 -> V_27 ;
}
if ( V_48 && ! F_1 ( V_48 -> V_27 , V_23 -> V_26 ) )
F_44 ( V_23 , V_48 ) ;
}
struct V_22 * F_47 ( struct V_4 * V_9 )
{
struct V_14 * V_37 = V_9 -> V_37 ;
unsigned int V_72 = F_4 ( V_9 ) ;
return V_37 -> V_24 + V_72 ;
}
struct V_22 *
F_48 ( struct V_22 * V_73 ,
struct V_4 * V_9 ,
bool V_74 )
{
struct V_22 * V_75 = V_73 ;
if ( V_9 -> V_76 ) {
struct V_10 * V_11 = F_5 ( V_9 ) ;
unsigned int V_77 , V_78 ;
struct V_58 * V_31 = NULL ;
struct V_5 * V_46 ;
#ifdef F_31
struct V_14 * V_15 ;
struct V_28 * V_34 ;
#endif
if ( V_11 )
V_31 = V_11 -> V_31 ;
#ifdef F_31
else {
V_15 = V_9 -> V_41 ;
V_34 = F_10 ( V_15 , struct V_28 , V_37 ) ;
V_31 = (struct V_58 * ) V_34 -> V_31 ;
}
#endif
V_73 -> V_70 -= V_9 -> V_43 ;
if ( V_9 -> V_78 != V_9 -> V_79 ) {
if ( V_9 -> V_78 < V_80 ||
V_9 -> V_78 > V_81 ) {
F_49 ( L_4 ,
V_9 -> V_78 ) ;
if ( V_9 -> V_78 < V_80 )
V_9 -> V_78 = V_80 ;
else
V_9 -> V_78 = V_81 ;
}
V_9 -> V_79 = V_9 -> V_78 ;
if ( V_11 )
V_11 -> V_62 =
F_35 ( V_9 -> V_79 ) ;
}
if ( V_11 && V_74 )
V_11 -> V_12 = V_11 -> V_82 ;
if ( ! V_11 || V_11 -> V_12 == V_11 -> V_82 )
V_9 -> V_76 = 0 ;
V_75 = F_47 ( V_9 ) ;
V_77 = V_9 -> V_43 ;
V_78 = V_9 -> V_79 *
( V_11 ? V_11 -> V_83 : 1 ) ;
if ( V_77 != V_78 ) {
V_46 = V_11 ? & V_31 -> V_84 :
& V_31 -> V_61 ;
F_40 ( V_31 , V_9 , V_46 ) ;
}
V_9 -> V_43 = V_78 ;
if ( V_77 != V_78 &&
( V_11 ? V_11 -> V_83 == 1 : 1 ) )
F_33 ( V_31 , V_9 , V_46 ) ;
V_75 -> V_70 += V_9 -> V_43 ;
if ( V_75 != V_73 )
V_9 -> V_25 = V_75 -> V_26 ;
}
return V_75 ;
}
void F_50 ( struct V_10 * V_11 , int V_85 )
{
struct V_4 * V_9 = & V_11 -> V_9 ;
struct V_22 * V_23 ;
F_51 (entity) {
V_23 = F_47 ( V_9 ) ;
V_9 -> V_42 += V_85 ;
V_23 -> V_26 += F_12 ( V_85 , V_23 -> V_70 ) ;
F_45 ( V_23 ) ;
}
F_52 ( F_53 ( V_11 ) ) ;
F_15 ( V_11 -> V_31 , V_11 , L_5 , V_85 ) ;
}
void F_54 ( struct V_58 * V_31 , struct V_10 * V_11 ,
unsigned long V_86 )
{
struct V_4 * V_9 = & V_11 -> V_9 ;
int V_87 = V_9 -> V_42 ;
unsigned int V_88 = F_55 ( V_89 ) ;
if ( V_86 > 0 && V_86 < V_88 )
V_87 =
( V_31 -> V_90 * V_86 ) / V_88 ;
if ( V_87 < V_9 -> V_42 )
V_87 = V_9 -> V_42 ;
if ( V_87 > V_9 -> V_39 )
V_9 -> V_39 = V_87 ;
F_50 ( V_11 ,
F_36 ( int , 0 , V_87 - V_9 -> V_42 ) ) ;
}
static void F_56 ( struct V_4 * V_9 ,
struct V_22 * V_23 ,
bool V_91 )
{
struct V_10 * V_11 = F_5 ( V_9 ) ;
V_23 = F_48 ( V_23 , V_9 , true ) ;
F_14 ( V_9 , V_9 -> V_39 ) ;
if ( V_91 && F_1 ( V_23 -> V_26 , V_9 -> V_27 ) ) {
unsigned long V_92 = V_23 -> V_26 - V_9 -> V_27 ;
if ( V_11 )
V_92 /= V_11 -> V_83 ;
V_9 -> V_25 += V_92 ;
V_9 -> V_27 += V_92 ;
}
F_30 ( V_23 , V_9 ) ;
}
static void F_57 ( struct V_4 * V_9 ,
bool V_93 )
{
struct V_22 * V_23 = F_47 ( V_9 ) ;
bool V_91 = false ;
unsigned long long V_94 ;
if ( V_93 && F_1 ( V_23 -> V_26 , V_9 -> V_27 ) ) {
V_91 = true ;
V_94 = V_9 -> V_27 ;
} else
V_94 = V_23 -> V_26 ;
if ( V_9 -> V_6 == & V_23 -> V_50 ) {
F_19 ( V_23 , V_9 ) ;
V_9 -> V_25 = F_1 ( V_94 , V_9 -> V_27 ) ?
V_94 : V_9 -> V_27 ;
} else {
V_9 -> V_25 = V_94 ;
V_23 -> V_70 += V_9 -> V_43 ;
F_37 ( V_9 ) ;
V_9 -> V_69 = true ;
}
F_56 ( V_9 , V_23 , V_91 ) ;
}
static void F_58 ( struct V_4 * V_9 )
{
struct V_14 * V_15 = V_9 -> V_37 ;
struct V_22 * V_23 = F_47 ( V_9 ) ;
if ( V_9 == V_15 -> V_71 ) {
F_14 ( V_9 , V_9 -> V_42 ) ;
V_9 -> V_25 = V_9 -> V_27 ;
if ( V_9 -> V_6 )
F_39 ( V_23 , V_9 ) ;
} else {
F_39 ( V_23 , V_9 ) ;
}
F_56 ( V_9 , V_23 , false ) ;
}
static void F_59 ( struct V_4 * V_9 ,
struct V_14 * V_15 ,
bool V_93 )
{
struct V_22 * V_23 = F_47 ( V_9 ) ;
if ( V_15 -> V_71 == V_9 || V_9 -> V_6 == & V_23 -> V_59 )
F_58 ( V_9 ) ;
else
F_57 ( V_9 , V_93 ) ;
}
static void F_60 ( struct V_4 * V_9 ,
bool V_93 ,
bool V_95 , bool V_17 )
{
struct V_14 * V_15 ;
F_51 (entity) {
V_15 = V_9 -> V_37 ;
F_59 ( V_9 , V_15 , V_93 ) ;
if ( ! F_6 ( V_15 , V_9 , V_17 ) &&
! V_95 )
break;
}
}
bool F_61 ( struct V_4 * V_9 , bool V_96 )
{
struct V_14 * V_15 = V_9 -> V_37 ;
struct V_22 * V_23 ;
bool V_68 ;
if ( ! V_9 -> V_69 )
return false ;
V_23 = F_47 ( V_9 ) ;
V_68 = V_9 == V_15 -> V_71 ;
if ( V_68 ) {
F_14 ( V_9 , V_9 -> V_42 ) ;
V_15 -> V_71 = NULL ;
}
if ( V_9 -> V_6 == & V_23 -> V_59 )
F_39 ( V_23 , V_9 ) ;
else if ( ! V_68 && V_9 -> V_6 == & V_23 -> V_50 )
F_19 ( V_23 , V_9 ) ;
if ( ! V_96 || ! F_1 ( V_9 -> V_27 , V_23 -> V_26 ) )
F_42 ( V_23 , V_9 , V_68 ) ;
else
F_41 ( V_23 , V_9 ) ;
return true ;
}
static void F_62 ( struct V_4 * V_9 ,
bool V_96 ,
bool V_17 )
{
struct V_14 * V_15 ;
struct V_4 * V_30 = NULL ;
F_63 (entity, parent) {
V_15 = V_9 -> V_37 ;
if ( ! F_61 ( V_9 , V_96 ) ) {
return;
}
if ( V_15 -> V_18 == V_9 )
F_6 ( V_15 , NULL , V_17 ) ;
if ( V_15 -> V_18 || V_15 -> V_71 ) {
break;
}
V_96 = true ;
}
V_9 = V_30 ;
F_51 (entity) {
F_58 ( V_9 ) ;
V_15 = V_9 -> V_37 ;
if ( ! F_6 ( V_15 , V_9 , V_17 ) &&
! V_17 )
break;
}
}
static T_1 F_64 ( struct V_22 * V_23 )
{
struct V_4 * V_97 = F_2 ( & V_23 -> V_59 ) ;
if ( F_1 ( V_97 -> V_56 , V_23 -> V_26 ) )
return V_97 -> V_56 ;
return V_23 -> V_26 ;
}
static void F_65 ( struct V_22 * V_23 , T_1 V_98 )
{
if ( V_98 > V_23 -> V_26 ) {
V_23 -> V_26 = V_98 ;
F_45 ( V_23 ) ;
}
}
static struct V_4 * F_66 ( struct V_22 * V_23 ,
T_1 V_26 )
{
struct V_4 * V_52 , * V_99 = NULL ;
struct V_7 * V_8 = V_23 -> V_59 . V_7 ;
while ( V_8 ) {
V_52 = F_3 ( V_8 , struct V_4 , V_7 ) ;
V_100:
if ( ! F_1 ( V_52 -> V_25 , V_26 ) )
V_99 = V_52 ;
if ( V_8 -> V_53 ) {
V_52 = F_3 ( V_8 -> V_53 ,
struct V_4 , V_7 ) ;
if ( ! F_1 ( V_52 -> V_56 , V_26 ) ) {
V_8 = V_8 -> V_53 ;
goto V_100;
}
}
if ( V_99 )
break;
V_8 = V_8 -> V_54 ;
}
return V_99 ;
}
static struct V_4 *
F_67 ( struct V_22 * V_23 , bool V_101 )
{
struct V_4 * V_9 ;
T_1 V_102 ;
if ( F_46 ( & V_23 -> V_59 ) )
return NULL ;
V_102 = F_64 ( V_23 ) ;
if ( ! V_101 )
F_65 ( V_23 , V_102 ) ;
V_9 = F_66 ( V_23 , V_102 ) ;
return V_9 ;
}
static struct V_4 * F_7 ( struct V_14 * V_15 ,
bool V_17 )
{
struct V_22 * V_23 = V_15 -> V_24 ;
struct V_22 * V_103 = V_23 + ( V_104 - 1 ) ;
struct V_4 * V_9 = NULL ;
int V_105 = 0 ;
if ( F_68 ( V_15 -> V_106 +
V_107 ) ) {
if ( ! F_46 ( & V_103 -> V_59 ) )
V_105 = V_104 - 1 ;
V_15 -> V_106 = V_108 ;
}
for (; V_105 < V_104 ; V_105 ++ ) {
V_9 = F_67 ( V_23 + V_105 ,
V_15 -> V_71 &&
! V_17 ) ;
if ( V_9 )
break;
}
if ( ! V_9 )
return NULL ;
return V_9 ;
}
bool F_69 ( struct V_58 * V_31 )
{
struct V_14 * V_15 = & V_31 -> V_32 -> V_37 ;
return V_15 -> V_18 != V_15 -> V_71 ;
}
struct V_10 * F_70 ( struct V_58 * V_31 )
{
struct V_4 * V_9 = NULL ;
struct V_14 * V_15 ;
struct V_10 * V_11 ;
if ( V_31 -> V_109 == 0 )
return NULL ;
V_15 = & V_31 -> V_32 -> V_37 ;
for (; V_15 ; V_15 = V_9 -> V_41 ) {
V_9 = V_15 -> V_18 ;
V_15 -> V_71 = V_9 ;
V_9 -> V_42 = 0 ;
if ( F_11 ( V_9 ) )
F_39 ( F_47 ( V_9 ) ,
V_9 ) ;
}
V_11 = F_5 ( V_9 ) ;
F_51 (entity) {
struct V_14 * V_15 = V_9 -> V_37 ;
if ( ! F_6 ( V_15 , NULL , false ) )
break;
}
return V_11 ;
}
void F_71 ( struct V_58 * V_31 )
{
struct V_10 * V_110 = V_31 -> V_111 ;
struct V_4 * V_112 = & V_110 -> V_9 ;
struct V_4 * V_9 = V_112 ;
F_72 ( V_110 ) ;
F_73 ( & V_31 -> V_113 ) ;
V_31 -> V_111 = NULL ;
F_51 (entity)
V_9 -> V_37 -> V_71 = NULL ;
if ( ! V_112 -> V_69 )
F_43 ( V_110 ) ;
}
void F_74 ( struct V_58 * V_31 , struct V_10 * V_11 ,
bool V_96 , bool V_17 )
{
struct V_4 * V_9 = & V_11 -> V_9 ;
F_62 ( V_9 , V_96 , V_17 ) ;
}
void F_75 ( struct V_58 * V_31 , struct V_10 * V_11 )
{
struct V_4 * V_9 = & V_11 -> V_9 ;
F_60 ( V_9 , F_76 ( V_11 ) ,
false , false ) ;
F_77 ( V_11 ) ;
}
void F_78 ( struct V_58 * V_31 , struct V_10 * V_11 ,
bool V_17 )
{
struct V_4 * V_9 = & V_11 -> V_9 ;
F_60 ( V_9 , false ,
V_11 == V_31 -> V_111 , V_17 ) ;
}
void F_79 ( struct V_58 * V_31 , struct V_10 * V_11 ,
bool V_17 )
{
F_15 ( V_31 , V_11 , L_6 ) ;
F_80 ( V_11 ) ;
V_31 -> V_109 -- ;
if ( ! V_11 -> V_114 )
F_40 ( V_31 , & V_11 -> V_9 ,
& V_31 -> V_84 ) ;
if ( V_11 -> V_83 > 1 )
V_31 -> V_115 -- ;
F_81 ( F_53 ( V_11 ) ) ;
F_74 ( V_31 , V_11 , true , V_17 ) ;
}
void F_82 ( struct V_58 * V_31 , struct V_10 * V_11 )
{
F_15 ( V_31 , V_11 , L_7 ) ;
F_75 ( V_31 , V_11 ) ;
F_83 ( V_11 ) ;
V_31 -> V_109 ++ ;
if ( ! V_11 -> V_114 )
if ( V_11 -> V_83 == 1 )
F_33 ( V_31 , & V_11 -> V_9 ,
& V_31 -> V_84 ) ;
if ( V_11 -> V_83 > 1 )
V_31 -> V_115 ++ ;
}
