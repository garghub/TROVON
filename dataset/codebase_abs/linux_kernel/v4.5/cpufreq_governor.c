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
if ( V_31 < V_29 -> V_38 )
V_31 = V_29 -> V_38 ;
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
void F_10 ( struct V_15 * V_16 , unsigned int V_46 )
{
struct V_2 * V_2 = V_16 -> V_47 ;
struct V_7 * V_8 ;
int V_6 ;
F_4 (cpu, policy->cpus) {
V_8 = V_2 -> V_3 -> V_9 ( V_6 ) ;
V_8 -> V_48 . V_49 = V_50 + V_46 ;
F_11 ( & V_8 -> V_48 , V_6 ) ;
}
}
static inline void F_12 ( struct V_15 * V_16 )
{
struct V_2 * V_2 = V_16 -> V_47 ;
struct V_7 * V_8 ;
int V_51 ;
F_4 (i, policy->cpus) {
V_8 = V_2 -> V_3 -> V_9 ( V_51 ) ;
F_13 ( & V_8 -> V_48 ) ;
}
}
void F_14 ( struct V_52 * V_17 )
{
F_15 ( & V_17 -> V_53 ) ;
F_12 ( V_17 -> V_16 ) ;
F_16 ( & V_17 -> V_54 ) ;
F_12 ( V_17 -> V_16 ) ;
F_17 ( & V_17 -> V_53 , 0 ) ;
}
static bool F_18 ( struct V_52 * V_17 ,
unsigned int V_18 )
{
if ( F_19 ( V_17 -> V_16 ) ) {
T_2 V_55 = F_20 () ;
T_3 V_56 = F_21 ( V_55 , V_17 -> V_57 ) ;
if ( V_56 < ( T_3 ) ( V_18 / 2 ) )
return false ;
else
V_17 -> V_57 = V_55 ;
}
return true ;
}
static void F_22 ( struct V_58 * V_54 )
{
struct V_52 * V_17 = F_23 ( V_54 , struct
V_52 , V_54 ) ;
struct V_15 * V_16 ;
struct V_2 * V_2 ;
unsigned int V_18 , V_46 ;
bool V_59 ;
V_16 = V_17 -> V_16 ;
V_2 = V_16 -> V_47 ;
F_12 ( V_16 ) ;
if ( V_2 -> V_3 -> V_22 == V_60 ) {
struct V_13 * V_14 = V_2 -> V_12 ;
V_18 = V_14 -> V_18 ;
} else {
struct V_10 * V_11 = V_2 -> V_12 ;
V_18 = V_11 -> V_18 ;
}
V_59 = F_18 ( V_17 , V_18 ) ;
F_24 ( & V_17 -> V_61 ) ;
V_46 = V_2 -> V_3 -> V_62 ( V_16 , V_59 ) ;
F_25 ( & V_17 -> V_61 ) ;
F_26 ( & V_17 -> V_53 ) ;
F_10 ( V_16 , V_46 ) ;
}
static void F_27 ( unsigned long V_63 )
{
struct V_7 * V_8 = (struct V_7 * ) V_63 ;
struct V_52 * V_17 = V_8 -> V_17 ;
if ( F_28 ( & V_17 -> V_53 ) > 1 )
F_26 ( & V_17 -> V_53 ) ;
else
F_29 ( V_64 , & V_17 -> V_54 ) ;
}
static void F_30 ( struct V_2 * V_2 ,
unsigned int V_18 )
{
if ( V_2 -> V_3 -> V_22 == V_60 ) {
struct V_13 * V_14 = V_2 -> V_12 ;
V_14 -> V_18 = V_18 ;
} else {
struct V_10 * V_11 = V_2 -> V_12 ;
V_11 -> V_18 = V_18 ;
}
}
static int F_31 ( struct V_15 * V_16 ,
struct V_65 * V_3 )
{
struct V_52 * V_17 ;
int V_21 ;
V_17 = F_32 ( sizeof( * V_17 ) , V_66 ) ;
if ( ! V_17 )
return - V_67 ;
F_4 (j, policy->related_cpus)
V_3 -> V_9 ( V_21 ) -> V_17 = V_17 ;
F_33 ( & V_17 -> V_61 ) ;
F_17 ( & V_17 -> V_53 , 0 ) ;
F_34 ( & V_17 -> V_54 , F_22 ) ;
return 0 ;
}
static void F_35 ( struct V_15 * V_16 ,
struct V_65 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ( V_16 -> V_6 ) ;
struct V_52 * V_17 = V_8 -> V_17 ;
int V_21 ;
F_36 ( & V_17 -> V_61 ) ;
F_4 (j, policy->cpus)
V_3 -> V_9 ( V_21 ) -> V_17 = NULL ;
F_37 ( V_17 ) ;
}
static int F_38 ( struct V_15 * V_16 ,
struct V_2 * V_2 ,
struct V_65 * V_3 )
{
unsigned int V_68 ;
int V_69 ;
if ( V_16 -> V_47 )
return - V_70 ;
if ( V_2 ) {
if ( F_39 ( F_2 () ) )
return - V_71 ;
V_69 = F_31 ( V_16 , V_3 ) ;
if ( V_69 )
return V_69 ;
V_2 -> V_72 ++ ;
V_16 -> V_47 = V_2 ;
return 0 ;
}
V_2 = F_32 ( sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 )
return - V_67 ;
V_69 = F_31 ( V_16 , V_3 ) ;
if ( V_69 )
goto V_73;
V_2 -> V_3 = V_3 ;
V_2 -> V_72 = 1 ;
V_69 = V_3 -> V_74 ( V_2 , ! V_16 -> V_22 -> V_75 ) ;
if ( V_69 )
goto F_35;
V_68 = V_16 -> V_76 . V_77 / 1000 ;
if ( V_68 == 0 )
V_68 = 1 ;
V_2 -> V_78 = F_40 ( V_2 -> V_78 ,
V_79 * V_68 ) ;
F_30 ( V_2 , F_40 ( V_2 -> V_78 ,
V_68 * V_80 ) ) ;
if ( ! F_2 () )
V_3 -> V_81 = V_2 ;
V_16 -> V_47 = V_2 ;
V_69 = F_41 ( F_42 ( V_16 ) ,
F_1 ( V_2 ) ) ;
if ( V_69 )
goto V_82;
return 0 ;
V_82:
V_16 -> V_47 = NULL ;
if ( ! F_2 () )
V_3 -> V_81 = NULL ;
V_3 -> exit ( V_2 , ! V_16 -> V_22 -> V_75 ) ;
F_35:
F_35 ( V_16 , V_3 ) ;
V_73:
F_37 ( V_2 ) ;
return V_69 ;
}
static int F_43 ( struct V_15 * V_16 ,
struct V_2 * V_2 )
{
struct V_65 * V_3 = V_2 -> V_3 ;
struct V_7 * V_8 = V_3 -> V_9 ( V_16 -> V_6 ) ;
if ( ! V_8 -> V_17 || V_8 -> V_17 -> V_16 )
return - V_70 ;
if ( ! -- V_2 -> V_72 ) {
F_44 ( F_42 ( V_16 ) ,
F_1 ( V_2 ) ) ;
V_16 -> V_47 = NULL ;
if ( ! F_2 () )
V_3 -> V_81 = NULL ;
V_3 -> exit ( V_2 , V_16 -> V_22 -> V_75 == 1 ) ;
F_37 ( V_2 ) ;
} else {
V_16 -> V_47 = NULL ;
}
F_35 ( V_16 , V_3 ) ;
return 0 ;
}
static int F_45 ( struct V_15 * V_16 ,
struct V_2 * V_2 )
{
struct V_65 * V_3 = V_2 -> V_3 ;
unsigned int V_18 , V_20 , V_21 , V_6 = V_16 -> V_6 ;
struct V_7 * V_8 = V_3 -> V_9 ( V_6 ) ;
struct V_52 * V_17 = V_8 -> V_17 ;
int V_35 = 0 ;
if ( ! V_16 -> V_83 )
return - V_71 ;
if ( ! V_17 || V_17 -> V_16 )
return - V_70 ;
if ( V_3 -> V_22 == V_60 ) {
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
V_17 -> V_57 = F_20 () ;
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
F_46 ( & V_29 -> V_48 , F_27 ,
( unsigned long ) V_29 ,
V_84 | V_85 ) ;
}
if ( V_3 -> V_22 == V_60 ) {
struct V_86 * V_87 =
V_3 -> V_26 ( V_6 ) ;
V_87 -> V_88 = 0 ;
V_87 -> V_89 = V_16 -> V_83 ;
} else {
struct V_90 * V_90 = V_3 -> V_91 ;
struct V_24 * V_25 = V_3 -> V_26 ( V_6 ) ;
V_25 -> V_27 = 1 ;
V_25 -> V_92 = V_93 ;
V_90 -> V_94 ( V_6 ) ;
}
F_10 ( V_16 , F_47 ( V_18 ) ) ;
return 0 ;
}
static int F_48 ( struct V_15 * V_16 ,
struct V_2 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_3 -> V_9 ( V_16 -> V_6 ) ;
struct V_52 * V_17 = V_8 -> V_17 ;
if ( ! V_17 || ! V_17 -> V_16 )
return - V_70 ;
F_14 ( V_17 ) ;
V_17 -> V_16 = NULL ;
return 0 ;
}
static int F_49 ( struct V_15 * V_16 ,
struct V_2 * V_2 )
{
struct V_65 * V_3 = V_2 -> V_3 ;
unsigned int V_6 = V_16 -> V_6 ;
struct V_7 * V_8 = V_3 -> V_9 ( V_6 ) ;
if ( ! V_8 -> V_17 || ! V_8 -> V_17 -> V_16 )
return - V_70 ;
F_24 ( & V_8 -> V_17 -> V_61 ) ;
if ( V_16 -> F_40 < V_8 -> V_17 -> V_16 -> V_83 )
F_50 ( V_8 -> V_17 -> V_16 , V_16 -> F_40 ,
V_95 ) ;
else if ( V_16 -> V_96 > V_8 -> V_17 -> V_16 -> V_83 )
F_50 ( V_8 -> V_17 -> V_16 , V_16 -> V_96 ,
V_97 ) ;
F_3 ( V_2 , V_6 ) ;
F_25 ( & V_8 -> V_17 -> V_61 ) ;
return 0 ;
}
int F_51 ( struct V_15 * V_16 ,
struct V_65 * V_3 , unsigned int V_98 )
{
struct V_2 * V_2 ;
int V_69 ;
F_24 ( & V_3 -> V_99 ) ;
if ( F_2 () )
V_2 = V_16 -> V_47 ;
else
V_2 = V_3 -> V_81 ;
if ( ! V_2 && ( V_98 != V_100 ) ) {
V_69 = - V_71 ;
goto V_101;
}
switch ( V_98 ) {
case V_100 :
V_69 = F_38 ( V_16 , V_2 , V_3 ) ;
break;
case V_102 :
V_69 = F_43 ( V_16 , V_2 ) ;
break;
case V_103 :
V_69 = F_45 ( V_16 , V_2 ) ;
break;
case V_104 :
V_69 = F_48 ( V_16 , V_2 ) ;
break;
case V_105 :
V_69 = F_49 ( V_16 , V_2 ) ;
break;
default:
V_69 = - V_71 ;
}
V_101:
F_25 ( & V_3 -> V_99 ) ;
return V_69 ;
}
