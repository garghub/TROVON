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
if ( V_29 > V_17 )
V_17 = V_29 ;
}
V_2 -> V_3 -> V_39 ( V_6 , V_17 ) ;
}
static inline void F_10 ( int V_6 , struct V_2 * V_2 ,
unsigned int V_40 )
{
struct V_7 * V_8 = V_2 -> V_3 -> V_9 ( V_6 ) ;
F_11 ( V_6 , V_41 , & V_8 -> V_42 , V_40 ) ;
}
void F_12 ( struct V_2 * V_2 , struct V_15 * V_16 ,
unsigned int V_40 , bool V_43 )
{
int V_44 ;
if ( ! V_16 -> V_45 )
return;
if ( ! V_43 ) {
F_10 ( F_13 () , V_2 , V_40 ) ;
} else {
F_4 (i, policy->cpus)
F_10 ( V_44 , V_2 , V_40 ) ;
}
}
static inline void F_14 ( struct V_2 * V_2 ,
struct V_15 * V_16 )
{
struct V_7 * V_8 ;
int V_44 ;
F_4 (i, policy->cpus) {
V_8 = V_2 -> V_3 -> V_9 ( V_44 ) ;
F_15 ( & V_8 -> V_42 ) ;
}
}
bool F_16 ( struct V_7 * V_8 ,
unsigned int V_46 )
{
if ( F_17 ( V_8 -> V_23 ) ) {
T_2 V_47 = F_18 () ;
T_3 V_48 = F_19 ( V_47 , V_8 -> V_49 ) ;
if ( V_48 < ( T_3 ) ( V_46 / 2 ) )
return false ;
else
V_8 -> V_49 = V_47 ;
}
return true ;
}
static void F_20 ( struct V_2 * V_2 ,
unsigned int V_46 )
{
if ( V_2 -> V_3 -> V_20 == V_50 ) {
struct V_13 * V_14 = V_2 -> V_12 ;
V_14 -> V_46 = V_46 ;
} else {
struct V_10 * V_11 = V_2 -> V_12 ;
V_11 -> V_46 = V_46 ;
}
}
int F_21 ( struct V_15 * V_16 ,
struct V_51 * V_3 , unsigned int V_52 )
{
struct V_2 * V_2 ;
struct V_53 * V_54 = NULL ;
struct V_55 * V_56 = NULL ;
struct V_57 * V_57 = NULL ;
struct V_10 * V_11 = NULL ;
struct V_13 * V_14 = NULL ;
struct V_7 * V_58 ;
unsigned int V_46 , V_59 , V_18 , V_19 , V_6 = V_16 -> V_6 ;
int V_30 = 0 ;
int V_60 ;
if ( F_2 () )
V_2 = V_16 -> V_61 ;
else
V_2 = V_3 -> V_62 ;
F_22 ( ! V_2 && ( V_52 != V_63 ) ) ;
switch ( V_52 ) {
case V_63 :
if ( F_2 () ) {
F_22 ( V_2 ) ;
} else if ( V_2 ) {
V_2 -> V_64 ++ ;
V_16 -> V_61 = V_2 ;
return 0 ;
}
V_2 = F_23 ( sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 ) {
F_24 ( L_1 , V_66 ) ;
return - V_67 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_64 = 1 ;
V_60 = V_3 -> V_68 ( V_2 ) ;
if ( V_60 ) {
F_24 ( L_2 , V_66 ) ;
F_25 ( V_2 ) ;
return V_60 ;
}
if ( ! F_2 () )
F_22 ( F_26 () ) ;
V_60 = F_27 ( F_28 ( V_16 ) ,
F_1 ( V_2 ) ) ;
if ( V_60 ) {
V_3 -> exit ( V_2 ) ;
F_25 ( V_2 ) ;
return V_60 ;
}
V_16 -> V_61 = V_2 ;
V_59 = V_16 -> V_69 . V_70 / 1000 ;
if ( V_59 == 0 )
V_59 = 1 ;
V_2 -> V_71 = F_29 ( V_2 -> V_71 ,
V_72 * V_59 ) ;
F_20 ( V_2 , F_29 ( V_2 -> V_71 ,
V_59 * V_73 ) ) ;
if ( ( V_3 -> V_20 == V_50 ) &&
( ! V_16 -> V_20 -> V_74 ) ) {
struct V_75 * V_75 = V_2 -> V_3 -> V_76 ;
F_30 ( V_75 -> V_77 ,
V_78 ) ;
}
if ( ! F_2 () )
V_3 -> V_62 = V_2 ;
return 0 ;
case V_79 :
if ( ! -- V_2 -> V_64 ) {
F_31 ( F_28 ( V_16 ) ,
F_1 ( V_2 ) ) ;
if ( ! F_2 () )
F_32 () ;
if ( ( V_2 -> V_3 -> V_20 == V_50 ) &&
( V_16 -> V_20 -> V_74 == 1 ) ) {
struct V_75 * V_75 = V_2 -> V_3 -> V_76 ;
F_33 ( V_75 -> V_77 ,
V_78 ) ;
}
V_3 -> exit ( V_2 ) ;
F_25 ( V_2 ) ;
V_3 -> V_62 = NULL ;
}
V_16 -> V_61 = NULL ;
return 0 ;
}
V_58 = V_2 -> V_3 -> V_9 ( V_6 ) ;
if ( V_2 -> V_3 -> V_20 == V_50 ) {
V_14 = V_2 -> V_12 ;
V_56 = V_2 -> V_3 -> V_80 ( V_6 ) ;
V_46 = V_14 -> V_46 ;
V_18 = V_14 -> V_22 ;
} else {
V_11 = V_2 -> V_12 ;
V_54 = V_2 -> V_3 -> V_80 ( V_6 ) ;
V_46 = V_11 -> V_46 ;
V_18 = V_11 -> V_22 ;
V_57 = V_2 -> V_3 -> V_76 ;
V_30 = V_11 -> V_31 ;
}
switch ( V_52 ) {
case V_81 :
if ( ! V_16 -> V_82 )
return - V_83 ;
F_34 ( & V_2 -> V_84 ) ;
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
F_35 ( & V_24 -> V_85 ) ;
F_36 ( & V_24 -> V_42 ,
V_2 -> V_3 -> V_86 ) ;
}
if ( V_2 -> V_3 -> V_20 == V_50 ) {
V_56 -> V_87 = 0 ;
V_56 -> V_88 = 1 ;
V_56 -> V_89 = V_16 -> V_82 ;
} else {
V_54 -> V_90 = 1 ;
V_54 -> V_91 = V_92 ;
V_57 -> V_93 ( V_6 ) ;
}
F_37 ( & V_2 -> V_84 ) ;
V_58 -> V_49 = F_18 () ;
F_12 ( V_2 , V_16 ,
F_38 ( V_46 ) , true ) ;
break;
case V_94 :
if ( V_2 -> V_3 -> V_20 == V_50 )
V_56 -> V_88 = 0 ;
F_14 ( V_2 , V_16 ) ;
F_34 ( & V_2 -> V_84 ) ;
F_39 ( & V_58 -> V_85 ) ;
V_58 -> V_23 = NULL ;
F_37 ( & V_2 -> V_84 ) ;
break;
case V_95 :
F_34 ( & V_58 -> V_85 ) ;
if ( V_16 -> F_29 < V_58 -> V_23 -> V_82 )
F_40 ( V_58 -> V_23 ,
V_16 -> F_29 , V_96 ) ;
else if ( V_16 -> V_97 > V_58 -> V_23 -> V_82 )
F_40 ( V_58 -> V_23 ,
V_16 -> V_97 , V_98 ) ;
F_3 ( V_2 , V_6 ) ;
F_37 ( & V_58 -> V_85 ) ;
break;
}
return 0 ;
}
