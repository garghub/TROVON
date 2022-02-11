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
struct V_15 * V_16 ;
unsigned int V_17 ;
unsigned int V_18 = 0 ;
unsigned int V_19 ;
unsigned int V_20 ;
if ( V_2 -> V_3 -> V_21 == V_22 ) {
struct V_23 * V_24 =
V_2 -> V_3 -> V_25 ( V_6 ) ;
V_17 = V_11 -> V_17 ;
V_17 *= V_24 -> V_26 ;
V_19 = V_11 -> V_27 ;
} else {
V_17 = V_14 -> V_17 ;
V_19 = V_14 -> V_27 ;
}
V_16 = V_8 -> V_28 ;
F_4 (j, policy->cpus) {
struct V_7 * V_29 ;
T_1 V_30 , V_31 ;
unsigned int V_32 , V_33 ;
unsigned int V_34 ;
int V_35 = 0 ;
V_29 = V_2 -> V_3 -> V_9 ( V_20 ) ;
if ( V_2 -> V_3 -> V_21 == V_22 )
V_35 = V_11 -> V_36 ;
V_31 = F_5 ( V_20 , & V_30 , V_35 ) ;
V_33 = ( unsigned int )
( V_30 - V_29 -> V_37 ) ;
V_29 -> V_37 = V_30 ;
V_32 = ( unsigned int )
( V_31 - V_29 -> V_38 ) ;
V_29 -> V_38 = V_31 ;
if ( V_19 ) {
T_1 V_39 ;
unsigned long V_40 ;
V_39 = F_6 ( V_20 ) . V_41 [ V_42 ] -
V_8 -> V_43 ;
V_40 = ( unsigned long )
F_7 ( V_39 ) ;
V_8 -> V_43 =
F_6 ( V_20 ) . V_41 [ V_42 ] ;
V_32 += F_8 ( V_40 ) ;
}
if ( F_9 ( ! V_33 || V_33 < V_32 ) )
continue;
if ( F_9 ( V_33 > ( 2 * V_17 ) &&
V_29 -> V_44 ) ) {
V_34 = V_29 -> V_44 ;
V_29 -> V_44 = 0 ;
} else {
V_34 = 100 * ( V_33 - V_32 ) / V_33 ;
V_29 -> V_44 = V_34 ;
}
if ( V_34 > V_18 )
V_18 = V_34 ;
}
V_2 -> V_3 -> V_45 ( V_6 , V_18 ) ;
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
F_13 ( & V_51 ) ;
if ( ! V_16 -> V_52 )
goto V_53;
if ( ! V_49 ) {
F_10 ( F_14 () , V_2 , V_46 ) ;
} else {
F_4 (i, policy->cpus)
F_10 ( V_50 , V_2 , V_46 ) ;
}
V_53:
F_15 ( & V_51 ) ;
}
static inline void F_16 ( struct V_2 * V_2 ,
struct V_15 * V_16 )
{
struct V_7 * V_8 ;
int V_50 ;
F_4 (i, policy->cpus) {
V_8 = V_2 -> V_3 -> V_9 ( V_50 ) ;
F_17 ( & V_8 -> V_48 ) ;
}
}
bool F_18 ( struct V_7 * V_8 ,
unsigned int V_17 )
{
if ( F_19 ( V_8 -> V_28 ) ) {
T_2 V_54 = F_20 () ;
T_3 V_55 = F_21 ( V_54 , V_8 -> V_56 ) ;
if ( V_55 < ( T_3 ) ( V_17 / 2 ) )
return false ;
else
V_8 -> V_56 = V_54 ;
}
return true ;
}
static void F_22 ( struct V_2 * V_2 ,
unsigned int V_17 )
{
if ( V_2 -> V_3 -> V_21 == V_57 ) {
struct V_13 * V_14 = V_2 -> V_12 ;
V_14 -> V_17 = V_17 ;
} else {
struct V_10 * V_11 = V_2 -> V_12 ;
V_11 -> V_17 = V_17 ;
}
}
int F_23 ( struct V_15 * V_16 ,
struct V_58 * V_3 , unsigned int V_59 )
{
struct V_2 * V_2 ;
struct V_23 * V_24 = NULL ;
struct V_60 * V_61 = NULL ;
struct V_62 * V_62 = NULL ;
struct V_10 * V_11 = NULL ;
struct V_13 * V_14 = NULL ;
struct V_7 * V_63 ;
unsigned int V_17 , V_64 , V_19 , V_20 , V_6 = V_16 -> V_6 ;
int V_35 = 0 ;
int V_65 ;
if ( F_2 () )
V_2 = V_16 -> V_66 ;
else
V_2 = V_3 -> V_67 ;
F_24 ( ! V_2 && ( V_59 != V_68 ) ) ;
switch ( V_59 ) {
case V_68 :
if ( F_2 () ) {
F_24 ( V_2 ) ;
} else if ( V_2 ) {
V_2 -> V_69 ++ ;
V_16 -> V_66 = V_2 ;
return 0 ;
}
V_2 = F_25 ( sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 ) {
F_26 ( L_1 , V_71 ) ;
return - V_72 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_69 = 1 ;
V_65 = V_3 -> V_73 ( V_2 ) ;
if ( V_65 ) {
F_26 ( L_2 , V_71 ) ;
F_27 ( V_2 ) ;
return V_65 ;
}
if ( ! F_2 () )
F_24 ( F_28 () ) ;
V_65 = F_29 ( F_30 ( V_16 ) ,
F_1 ( V_2 ) ) ;
if ( V_65 ) {
V_3 -> exit ( V_2 ) ;
F_27 ( V_2 ) ;
return V_65 ;
}
V_16 -> V_66 = V_2 ;
V_64 = V_16 -> V_74 . V_75 / 1000 ;
if ( V_64 == 0 )
V_64 = 1 ;
V_2 -> V_76 = F_31 ( V_2 -> V_76 ,
V_77 * V_64 ) ;
F_22 ( V_2 , F_31 ( V_2 -> V_76 ,
V_64 * V_78 ) ) ;
if ( ( V_3 -> V_21 == V_57 ) &&
( ! V_16 -> V_21 -> V_79 ) ) {
struct V_80 * V_80 = V_2 -> V_3 -> V_81 ;
F_32 ( V_80 -> V_82 ,
V_83 ) ;
}
if ( ! F_2 () )
V_3 -> V_67 = V_2 ;
return 0 ;
case V_84 :
if ( ! -- V_2 -> V_69 ) {
F_33 ( F_30 ( V_16 ) ,
F_1 ( V_2 ) ) ;
if ( ! F_2 () )
F_34 () ;
if ( ( V_2 -> V_3 -> V_21 == V_57 ) &&
( V_16 -> V_21 -> V_79 == 1 ) ) {
struct V_80 * V_80 = V_2 -> V_3 -> V_81 ;
F_35 ( V_80 -> V_82 ,
V_83 ) ;
}
V_3 -> exit ( V_2 ) ;
F_27 ( V_2 ) ;
V_3 -> V_67 = NULL ;
}
V_16 -> V_66 = NULL ;
return 0 ;
}
V_63 = V_2 -> V_3 -> V_9 ( V_6 ) ;
if ( V_2 -> V_3 -> V_21 == V_57 ) {
V_14 = V_2 -> V_12 ;
V_61 = V_2 -> V_3 -> V_25 ( V_6 ) ;
V_17 = V_14 -> V_17 ;
V_19 = V_14 -> V_27 ;
} else {
V_11 = V_2 -> V_12 ;
V_24 = V_2 -> V_3 -> V_25 ( V_6 ) ;
V_17 = V_11 -> V_17 ;
V_19 = V_11 -> V_27 ;
V_62 = V_2 -> V_3 -> V_81 ;
V_35 = V_11 -> V_36 ;
}
switch ( V_59 ) {
case V_85 :
if ( ! V_16 -> V_86 )
return - V_87 ;
F_13 ( & V_2 -> V_88 ) ;
F_4 (j, policy->cpus) {
struct V_7 * V_29 =
V_2 -> V_3 -> V_9 ( V_20 ) ;
unsigned int V_44 ;
V_29 -> V_6 = V_20 ;
V_29 -> V_28 = V_16 ;
V_29 -> V_38 = F_5 ( V_20 ,
& V_29 -> V_37 , V_35 ) ;
V_44 = ( unsigned int )
( V_29 -> V_37 - V_29 -> V_38 ) ;
V_29 -> V_44 = 100 * V_44 /
( unsigned int ) V_29 -> V_37 ;
if ( V_19 )
V_29 -> V_43 =
F_6 ( V_20 ) . V_41 [ V_42 ] ;
F_36 ( & V_29 -> V_89 ) ;
F_37 ( & V_29 -> V_48 ,
V_2 -> V_3 -> V_90 ) ;
}
if ( V_2 -> V_3 -> V_21 == V_57 ) {
V_61 -> V_91 = 0 ;
V_61 -> V_92 = 1 ;
V_61 -> V_93 = V_16 -> V_86 ;
} else {
V_24 -> V_26 = 1 ;
V_24 -> V_94 = V_95 ;
V_62 -> V_96 ( V_6 ) ;
}
F_15 ( & V_2 -> V_88 ) ;
V_63 -> V_56 = F_20 () ;
F_12 ( V_2 , V_16 ,
F_38 ( V_17 ) , true ) ;
break;
case V_97 :
if ( V_2 -> V_3 -> V_21 == V_57 )
V_61 -> V_92 = 0 ;
F_16 ( V_2 , V_16 ) ;
F_13 ( & V_2 -> V_88 ) ;
F_39 ( & V_63 -> V_89 ) ;
V_63 -> V_28 = NULL ;
F_15 ( & V_2 -> V_88 ) ;
break;
case V_98 :
F_13 ( & V_2 -> V_88 ) ;
if ( ! V_63 -> V_28 ) {
F_15 ( & V_2 -> V_88 ) ;
break;
}
F_13 ( & V_63 -> V_89 ) ;
if ( V_16 -> F_31 < V_63 -> V_28 -> V_86 )
F_40 ( V_63 -> V_28 ,
V_16 -> F_31 , V_99 ) ;
else if ( V_16 -> V_100 > V_63 -> V_28 -> V_86 )
F_40 ( V_63 -> V_28 ,
V_16 -> V_100 , V_101 ) ;
F_3 ( V_2 , V_6 ) ;
F_15 ( & V_63 -> V_89 ) ;
F_15 ( & V_2 -> V_88 ) ;
break;
}
return 0 ;
}
