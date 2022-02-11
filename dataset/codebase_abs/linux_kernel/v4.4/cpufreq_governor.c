static struct V_1 * F_1 ( struct V_2 * V_2 )
{
if ( F_2 () )
return V_2 -> V_3 -> V_4 ;
else
return V_2 -> V_3 -> V_5 ;
}
void F_3 ( struct V_2 * V_2 , int V_6 )
{
struct V_7 * V_8 = V_2 -> V_3 -> V_9 ( V_6 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = V_2 -> V_12 ;
struct V_15 * V_16 = V_8 -> V_17 -> V_16 ;
unsigned int V_18 ;
unsigned int V_19 = 0 ;
unsigned int V_20 ;
unsigned int V_21 ;
if ( V_2 -> V_3 -> V_22 == V_23 ) {
struct V_24 * V_25 =
V_2 -> V_3 -> V_26 ( V_6 ) ;
V_18 = V_11 -> V_18 ;
V_18 *= V_25 -> V_27 ;
V_20 = V_11 -> V_28 ;
} else {
V_18 = V_14 -> V_18 ;
V_20 = V_14 -> V_28 ;
}
F_4 (j, policy->cpus) {
struct V_7 * V_29 ;
T_1 V_30 , V_31 ;
unsigned int V_32 , V_33 ;
unsigned int V_34 ;
int V_35 = 0 ;
V_29 = V_2 -> V_3 -> V_9 ( V_21 ) ;
if ( V_2 -> V_3 -> V_22 == V_23 )
V_35 = V_11 -> V_36 ;
V_31 = F_5 ( V_21 , & V_30 , V_35 ) ;
V_33 = ( unsigned int )
( V_30 - V_29 -> V_37 ) ;
V_29 -> V_37 = V_30 ;
V_32 = ( unsigned int )
( V_31 - V_29 -> V_38 ) ;
V_29 -> V_38 = V_31 ;
if ( V_20 ) {
T_1 V_39 ;
unsigned long V_40 ;
V_39 = F_6 ( V_21 ) . V_41 [ V_42 ] -
V_8 -> V_43 ;
V_40 = ( unsigned long )
F_7 ( V_39 ) ;
V_8 -> V_43 =
F_6 ( V_21 ) . V_41 [ V_42 ] ;
V_32 += F_8 ( V_40 ) ;
}
if ( F_9 ( ! V_33 || V_33 < V_32 ) )
continue;
if ( F_9 ( V_33 > ( 2 * V_18 ) &&
V_29 -> V_44 ) ) {
V_34 = V_29 -> V_44 ;
V_29 -> V_44 = 0 ;
} else {
V_34 = 100 * ( V_33 - V_32 ) / V_33 ;
V_29 -> V_44 = V_34 ;
}
if ( V_34 > V_19 )
V_19 = V_34 ;
}
V_2 -> V_3 -> V_45 ( V_6 , V_19 ) ;
}
static inline void F_10 ( int V_6 , struct V_2 * V_2 ,
unsigned int V_46 )
{
struct V_7 * V_8 = V_2 -> V_3 -> V_9 ( V_6 ) ;
F_11 ( V_6 , V_47 , & V_8 -> V_48 , V_46 ) ;
}
void F_12 ( struct V_2 * V_2 , struct V_15 * V_16 ,
unsigned int V_46 , bool V_49 )
{
int V_50 ;
if ( ! V_49 ) {
F_10 ( F_13 () , V_2 , V_46 ) ;
} else {
F_4 (i, policy->cpus)
F_10 ( V_50 , V_2 , V_46 ) ;
}
}
static inline void F_14 ( struct V_2 * V_2 ,
struct V_15 * V_16 )
{
struct V_7 * V_8 ;
int V_50 ;
F_4 (i, policy->cpus) {
V_8 = V_2 -> V_3 -> V_9 ( V_50 ) ;
F_15 ( & V_8 -> V_48 ) ;
}
}
static bool F_16 ( struct V_51 * V_17 ,
unsigned int V_18 )
{
if ( F_17 ( V_17 -> V_16 ) ) {
T_2 V_52 = F_18 () ;
T_3 V_53 = F_19 ( V_52 , V_17 -> V_54 ) ;
if ( V_53 < ( T_3 ) ( V_18 / 2 ) )
return false ;
else
V_17 -> V_54 = V_52 ;
}
return true ;
}
static void F_20 ( struct V_55 * V_56 )
{
struct V_7 * V_8 = F_21 ( V_56 , struct V_7 ,
V_48 . V_56 ) ;
struct V_51 * V_17 = V_8 -> V_17 ;
struct V_15 * V_16 ;
struct V_2 * V_2 ;
unsigned int V_18 , V_46 ;
bool V_57 = true ;
F_22 ( & V_17 -> V_58 ) ;
V_16 = V_17 -> V_16 ;
if ( ! V_16 )
goto V_59;
V_2 = V_16 -> V_60 ;
if ( V_2 -> V_3 -> V_22 == V_61 ) {
struct V_13 * V_14 = V_2 -> V_12 ;
V_18 = V_14 -> V_18 ;
} else {
struct V_10 * V_11 = V_2 -> V_12 ;
V_18 = V_11 -> V_18 ;
}
if ( ! F_16 ( V_8 -> V_17 , V_18 ) )
V_57 = false ;
V_46 = V_2 -> V_3 -> V_62 ( V_8 , V_2 , V_57 ) ;
F_12 ( V_2 , V_16 , V_46 , V_57 ) ;
V_59:
F_23 ( & V_17 -> V_58 ) ;
}
static void F_24 ( struct V_2 * V_2 ,
unsigned int V_18 )
{
if ( V_2 -> V_3 -> V_22 == V_61 ) {
struct V_13 * V_14 = V_2 -> V_12 ;
V_14 -> V_18 = V_18 ;
} else {
struct V_10 * V_11 = V_2 -> V_12 ;
V_11 -> V_18 = V_18 ;
}
}
static int F_25 ( struct V_15 * V_16 ,
struct V_63 * V_3 )
{
struct V_51 * V_17 ;
int V_21 ;
V_17 = F_26 ( sizeof( * V_17 ) , V_64 ) ;
if ( ! V_17 )
return - V_65 ;
F_4 (j, policy->related_cpus)
V_3 -> V_9 ( V_21 ) -> V_17 = V_17 ;
return 0 ;
}
static void F_27 ( struct V_15 * V_16 ,
struct V_63 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ( V_16 -> V_6 ) ;
struct V_51 * V_17 = V_8 -> V_17 ;
int V_21 ;
F_4 (j, policy->cpus)
V_3 -> V_9 ( V_21 ) -> V_17 = NULL ;
F_28 ( V_17 ) ;
}
static int F_29 ( struct V_15 * V_16 ,
struct V_2 * V_2 ,
struct V_63 * V_3 )
{
unsigned int V_66 ;
int V_67 ;
if ( V_16 -> V_60 )
return - V_68 ;
if ( V_2 ) {
if ( F_30 ( F_2 () ) )
return - V_69 ;
V_67 = F_25 ( V_16 , V_3 ) ;
if ( V_67 )
return V_67 ;
V_2 -> V_70 ++ ;
V_16 -> V_60 = V_2 ;
return 0 ;
}
V_2 = F_26 ( sizeof( * V_2 ) , V_64 ) ;
if ( ! V_2 )
return - V_65 ;
V_67 = F_25 ( V_16 , V_3 ) ;
if ( V_67 )
goto V_71;
V_2 -> V_3 = V_3 ;
V_2 -> V_70 = 1 ;
V_67 = V_3 -> V_72 ( V_2 , ! V_16 -> V_22 -> V_73 ) ;
if ( V_67 )
goto F_27;
V_66 = V_16 -> V_74 . V_75 / 1000 ;
if ( V_66 == 0 )
V_66 = 1 ;
V_2 -> V_76 = F_31 ( V_2 -> V_76 ,
V_77 * V_66 ) ;
F_24 ( V_2 , F_31 ( V_2 -> V_76 ,
V_66 * V_78 ) ) ;
if ( ! F_2 () )
V_3 -> V_79 = V_2 ;
V_67 = F_32 ( F_33 ( V_16 ) ,
F_1 ( V_2 ) ) ;
if ( V_67 )
goto V_80;
V_16 -> V_60 = V_2 ;
return 0 ;
V_80:
if ( ! F_2 () )
V_3 -> V_79 = NULL ;
V_3 -> exit ( V_2 , ! V_16 -> V_22 -> V_73 ) ;
F_27:
F_27 ( V_16 , V_3 ) ;
V_71:
F_28 ( V_2 ) ;
return V_67 ;
}
static int F_34 ( struct V_15 * V_16 ,
struct V_2 * V_2 )
{
struct V_63 * V_3 = V_2 -> V_3 ;
struct V_7 * V_8 = V_3 -> V_9 ( V_16 -> V_6 ) ;
if ( ! V_8 -> V_17 || V_8 -> V_17 -> V_16 )
return - V_68 ;
V_16 -> V_60 = NULL ;
if ( ! -- V_2 -> V_70 ) {
F_35 ( F_33 ( V_16 ) ,
F_1 ( V_2 ) ) ;
if ( ! F_2 () )
V_3 -> V_79 = NULL ;
V_3 -> exit ( V_2 , V_16 -> V_22 -> V_73 == 1 ) ;
F_28 ( V_2 ) ;
}
F_27 ( V_16 , V_3 ) ;
return 0 ;
}
static int F_36 ( struct V_15 * V_16 ,
struct V_2 * V_2 )
{
struct V_63 * V_3 = V_2 -> V_3 ;
unsigned int V_18 , V_20 , V_21 , V_6 = V_16 -> V_6 ;
struct V_7 * V_8 = V_3 -> V_9 ( V_6 ) ;
struct V_51 * V_17 = V_8 -> V_17 ;
int V_35 = 0 ;
if ( ! V_16 -> V_81 )
return - V_69 ;
if ( ! V_17 || V_17 -> V_16 )
return - V_68 ;
if ( V_3 -> V_22 == V_61 ) {
struct V_13 * V_14 = V_2 -> V_12 ;
V_18 = V_14 -> V_18 ;
V_20 = V_14 -> V_28 ;
} else {
struct V_10 * V_11 = V_2 -> V_12 ;
V_18 = V_11 -> V_18 ;
V_20 = V_11 -> V_28 ;
V_35 = V_11 -> V_36 ;
}
V_17 -> V_16 = V_16 ;
V_17 -> V_54 = F_18 () ;
F_37 ( & V_17 -> V_58 ) ;
F_4 (j, policy->cpus) {
struct V_7 * V_29 = V_3 -> V_9 ( V_21 ) ;
unsigned int V_44 ;
V_29 -> V_38 =
F_5 ( V_21 , & V_29 -> V_37 , V_35 ) ;
V_44 = ( unsigned int ) ( V_29 -> V_37 -
V_29 -> V_38 ) ;
V_29 -> V_44 = 100 * V_44 /
( unsigned int ) V_29 -> V_37 ;
if ( V_20 )
V_29 -> V_43 = F_6 ( V_21 ) . V_41 [ V_42 ] ;
F_38 ( & V_29 -> V_48 , F_20 ) ;
}
if ( V_3 -> V_22 == V_61 ) {
struct V_82 * V_83 =
V_3 -> V_26 ( V_6 ) ;
V_83 -> V_84 = 0 ;
V_83 -> V_85 = V_16 -> V_81 ;
} else {
struct V_86 * V_86 = V_3 -> V_87 ;
struct V_24 * V_25 = V_3 -> V_26 ( V_6 ) ;
V_25 -> V_27 = 1 ;
V_25 -> V_88 = V_89 ;
V_86 -> V_90 ( V_6 ) ;
}
F_12 ( V_2 , V_16 , F_39 ( V_18 ) ,
true ) ;
return 0 ;
}
static int F_40 ( struct V_15 * V_16 ,
struct V_2 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_3 -> V_9 ( V_16 -> V_6 ) ;
struct V_51 * V_17 = V_8 -> V_17 ;
if ( ! V_17 || ! V_17 -> V_16 )
return - V_68 ;
F_22 ( & V_17 -> V_58 ) ;
V_17 -> V_16 = NULL ;
F_23 ( & V_17 -> V_58 ) ;
F_14 ( V_2 , V_16 ) ;
F_41 ( & V_17 -> V_58 ) ;
return 0 ;
}
static int F_42 ( struct V_15 * V_16 ,
struct V_2 * V_2 )
{
struct V_63 * V_3 = V_2 -> V_3 ;
unsigned int V_6 = V_16 -> V_6 ;
struct V_7 * V_8 = V_3 -> V_9 ( V_6 ) ;
if ( ! V_8 -> V_17 || ! V_8 -> V_17 -> V_16 )
return - V_68 ;
F_22 ( & V_8 -> V_17 -> V_58 ) ;
if ( V_16 -> F_31 < V_8 -> V_17 -> V_16 -> V_81 )
F_43 ( V_8 -> V_17 -> V_16 , V_16 -> F_31 ,
V_91 ) ;
else if ( V_16 -> V_92 > V_8 -> V_17 -> V_16 -> V_81 )
F_43 ( V_8 -> V_17 -> V_16 , V_16 -> V_92 ,
V_93 ) ;
F_3 ( V_2 , V_6 ) ;
F_23 ( & V_8 -> V_17 -> V_58 ) ;
return 0 ;
}
int F_44 ( struct V_15 * V_16 ,
struct V_63 * V_3 , unsigned int V_94 )
{
struct V_2 * V_2 ;
int V_67 ;
F_22 ( & V_3 -> V_95 ) ;
if ( F_2 () )
V_2 = V_16 -> V_60 ;
else
V_2 = V_3 -> V_79 ;
if ( ! V_2 && ( V_94 != V_96 ) ) {
V_67 = - V_69 ;
goto V_59;
}
switch ( V_94 ) {
case V_96 :
V_67 = F_29 ( V_16 , V_2 , V_3 ) ;
break;
case V_97 :
V_67 = F_34 ( V_16 , V_2 ) ;
break;
case V_98 :
V_67 = F_36 ( V_16 , V_2 ) ;
break;
case V_99 :
V_67 = F_40 ( V_16 , V_2 ) ;
break;
case V_100 :
V_67 = F_42 ( V_16 , V_2 ) ;
break;
default:
V_67 = - V_69 ;
}
V_59:
F_23 ( & V_3 -> V_95 ) ;
return V_67 ;
}
