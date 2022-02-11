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
unsigned int V_17 = 0 ;
unsigned int V_18 ;
unsigned int V_19 ;
if ( V_2 -> V_3 -> V_20 == V_21 )
V_18 = V_11 -> V_22 ;
else
V_18 = V_14 -> V_22 ;
V_16 = V_8 -> V_23 ;
F_4 (j, policy->cpus) {
struct V_7 * V_24 ;
T_1 V_25 , V_26 ;
unsigned int V_27 , V_28 ;
unsigned int V_29 ;
int V_30 = 0 ;
V_24 = V_2 -> V_3 -> V_9 ( V_19 ) ;
if ( V_2 -> V_3 -> V_20 == V_21 )
V_30 = V_11 -> V_31 ;
V_26 = F_5 ( V_19 , & V_25 , V_30 ) ;
V_28 = ( unsigned int )
( V_25 - V_24 -> V_32 ) ;
V_24 -> V_32 = V_25 ;
V_27 = ( unsigned int )
( V_26 - V_24 -> V_33 ) ;
V_24 -> V_33 = V_26 ;
if ( V_18 ) {
T_1 V_34 ;
unsigned long V_35 ;
V_34 = F_6 ( V_19 ) . V_36 [ V_37 ] -
V_8 -> V_38 ;
V_35 = ( unsigned long )
F_7 ( V_34 ) ;
V_8 -> V_38 =
F_6 ( V_19 ) . V_36 [ V_37 ] ;
V_27 += F_8 ( V_35 ) ;
}
if ( F_9 ( ! V_28 || V_28 < V_27 ) )
continue;
V_29 = 100 * ( V_28 - V_27 ) / V_28 ;
if ( V_2 -> V_3 -> V_20 == V_21 ) {
int V_39 = F_10 ( V_16 , V_19 ) ;
if ( V_39 <= 0 )
V_39 = V_16 -> V_40 ;
V_29 *= V_39 ;
}
if ( V_29 > V_17 )
V_17 = V_29 ;
}
V_2 -> V_3 -> V_41 ( V_6 , V_17 ) ;
}
static inline void F_11 ( int V_6 , struct V_2 * V_2 ,
unsigned int V_42 )
{
struct V_7 * V_8 = V_2 -> V_3 -> V_9 ( V_6 ) ;
F_12 ( V_6 , V_43 , & V_8 -> V_44 , V_42 ) ;
}
void F_13 ( struct V_2 * V_2 , struct V_15 * V_16 ,
unsigned int V_42 , bool V_45 )
{
int V_46 ;
if ( ! V_45 ) {
F_11 ( F_14 () , V_2 , V_42 ) ;
} else {
F_4 (i, policy->cpus)
F_11 ( V_46 , V_2 , V_42 ) ;
}
}
static inline void F_15 ( struct V_2 * V_2 ,
struct V_15 * V_16 )
{
struct V_7 * V_8 ;
int V_46 ;
F_4 (i, policy->cpus) {
V_8 = V_2 -> V_3 -> V_9 ( V_46 ) ;
F_16 ( & V_8 -> V_44 ) ;
}
}
bool F_17 ( struct V_7 * V_8 ,
unsigned int V_47 )
{
if ( F_18 ( V_8 -> V_23 ) ) {
T_2 V_48 = F_19 () ;
T_3 V_49 = F_20 ( V_48 , V_8 -> V_50 ) ;
if ( V_49 < ( T_3 ) ( V_47 / 2 ) )
return false ;
else
V_8 -> V_50 = V_48 ;
}
return true ;
}
static void F_21 ( struct V_2 * V_2 ,
unsigned int V_47 )
{
if ( V_2 -> V_3 -> V_20 == V_51 ) {
struct V_13 * V_14 = V_2 -> V_12 ;
V_14 -> V_47 = V_47 ;
} else {
struct V_10 * V_11 = V_2 -> V_12 ;
V_11 -> V_47 = V_47 ;
}
}
int F_22 ( struct V_15 * V_16 ,
struct V_52 * V_3 , unsigned int V_53 )
{
struct V_2 * V_2 ;
struct V_54 * V_55 = NULL ;
struct V_56 * V_57 = NULL ;
struct V_58 * V_58 = NULL ;
struct V_10 * V_11 = NULL ;
struct V_13 * V_14 = NULL ;
struct V_7 * V_59 ;
unsigned int V_47 , V_60 , V_18 , V_19 , V_6 = V_16 -> V_6 ;
int V_30 = 0 ;
int V_61 ;
if ( F_2 () )
V_2 = V_16 -> V_62 ;
else
V_2 = V_3 -> V_63 ;
F_23 ( ! V_2 && ( V_53 != V_64 ) ) ;
switch ( V_53 ) {
case V_64 :
if ( F_2 () ) {
F_23 ( V_2 ) ;
} else if ( V_2 ) {
V_2 -> V_65 ++ ;
V_16 -> V_62 = V_2 ;
return 0 ;
}
V_2 = F_24 ( sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 ) {
F_25 ( L_1 , V_67 ) ;
return - V_68 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_65 = 1 ;
V_61 = V_3 -> V_69 ( V_2 ) ;
if ( V_61 ) {
F_25 ( L_2 , V_67 ) ;
F_26 ( V_2 ) ;
return V_61 ;
}
if ( ! F_2 () )
F_23 ( F_27 () ) ;
V_61 = F_28 ( F_29 ( V_16 ) ,
F_1 ( V_2 ) ) ;
if ( V_61 ) {
V_3 -> exit ( V_2 ) ;
F_26 ( V_2 ) ;
return V_61 ;
}
V_16 -> V_62 = V_2 ;
V_60 = V_16 -> V_70 . V_71 / 1000 ;
if ( V_60 == 0 )
V_60 = 1 ;
V_2 -> V_72 = F_30 ( V_2 -> V_72 ,
V_73 * V_60 ) ;
F_21 ( V_2 , F_30 ( V_2 -> V_72 ,
V_60 * V_74 ) ) ;
if ( ( V_3 -> V_20 == V_51 ) &&
( ! V_16 -> V_20 -> V_75 ) ) {
struct V_76 * V_76 = V_2 -> V_3 -> V_77 ;
F_31 ( V_76 -> V_78 ,
V_79 ) ;
}
if ( ! F_2 () )
V_3 -> V_63 = V_2 ;
return 0 ;
case V_80 :
if ( ! -- V_2 -> V_65 ) {
F_32 ( F_29 ( V_16 ) ,
F_1 ( V_2 ) ) ;
if ( ! F_2 () )
F_33 () ;
if ( ( V_2 -> V_3 -> V_20 == V_51 ) &&
( V_16 -> V_20 -> V_75 == 1 ) ) {
struct V_76 * V_76 = V_2 -> V_3 -> V_77 ;
F_34 ( V_76 -> V_78 ,
V_79 ) ;
}
V_3 -> exit ( V_2 ) ;
F_26 ( V_2 ) ;
V_3 -> V_63 = NULL ;
}
V_16 -> V_62 = NULL ;
return 0 ;
}
V_59 = V_2 -> V_3 -> V_9 ( V_6 ) ;
if ( V_2 -> V_3 -> V_20 == V_51 ) {
V_14 = V_2 -> V_12 ;
V_57 = V_2 -> V_3 -> V_81 ( V_6 ) ;
V_47 = V_14 -> V_47 ;
V_18 = V_14 -> V_22 ;
} else {
V_11 = V_2 -> V_12 ;
V_55 = V_2 -> V_3 -> V_81 ( V_6 ) ;
V_47 = V_11 -> V_47 ;
V_18 = V_11 -> V_22 ;
V_58 = V_2 -> V_3 -> V_77 ;
V_30 = V_11 -> V_31 ;
}
switch ( V_53 ) {
case V_82 :
if ( ! V_16 -> V_40 )
return - V_83 ;
F_35 ( & V_2 -> V_84 ) ;
F_4 (j, policy->cpus) {
struct V_7 * V_24 =
V_2 -> V_3 -> V_9 ( V_19 ) ;
V_24 -> V_6 = V_19 ;
V_24 -> V_23 = V_16 ;
V_24 -> V_33 = F_5 ( V_19 ,
& V_24 -> V_32 , V_30 ) ;
if ( V_18 )
V_24 -> V_38 =
F_6 ( V_19 ) . V_36 [ V_37 ] ;
F_36 ( & V_24 -> V_85 ) ;
F_37 ( & V_24 -> V_44 ,
V_2 -> V_3 -> V_86 ) ;
}
if ( V_2 -> V_3 -> V_20 == V_51 ) {
V_57 -> V_87 = 0 ;
V_57 -> V_88 = 1 ;
V_57 -> V_89 = V_16 -> V_40 ;
} else {
V_55 -> V_90 = 1 ;
V_55 -> V_91 = V_92 ;
V_58 -> V_93 ( V_6 ) ;
}
F_38 ( & V_2 -> V_84 ) ;
V_59 -> V_50 = F_19 () ;
F_13 ( V_2 , V_16 ,
F_39 ( V_47 ) , true ) ;
break;
case V_94 :
if ( V_2 -> V_3 -> V_20 == V_51 )
V_57 -> V_88 = 0 ;
F_15 ( V_2 , V_16 ) ;
F_35 ( & V_2 -> V_84 ) ;
F_40 ( & V_59 -> V_85 ) ;
V_59 -> V_23 = NULL ;
F_38 ( & V_2 -> V_84 ) ;
break;
case V_95 :
F_35 ( & V_59 -> V_85 ) ;
if ( V_16 -> F_30 < V_59 -> V_23 -> V_40 )
F_41 ( V_59 -> V_23 ,
V_16 -> F_30 , V_96 ) ;
else if ( V_16 -> V_97 > V_59 -> V_23 -> V_40 )
F_41 ( V_59 -> V_23 ,
V_16 -> V_97 , V_98 ) ;
F_3 ( V_2 , V_6 ) ;
F_38 ( & V_59 -> V_85 ) ;
break;
}
return 0 ;
}
