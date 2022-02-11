static struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( F_2 () )
return & V_3 -> V_4 ;
else
return V_5 ;
}
static struct V_6 * F_3 ( struct V_7 * V_7 )
{
if ( F_2 () )
return V_7 -> V_8 -> V_9 ;
else
return V_7 -> V_8 -> V_10 ;
}
static inline T_1 F_4 ( unsigned int V_11 , T_1 * V_12 )
{
T_1 V_13 ;
T_1 V_14 ;
T_1 V_15 ;
V_14 = F_5 ( F_6 () ) ;
V_15 = F_7 ( V_11 ) . V_16 [ V_17 ] ;
V_15 += F_7 ( V_11 ) . V_16 [ V_18 ] ;
V_15 += F_7 ( V_11 ) . V_16 [ V_19 ] ;
V_15 += F_7 ( V_11 ) . V_16 [ V_20 ] ;
V_15 += F_7 ( V_11 ) . V_16 [ V_21 ] ;
V_15 += F_7 ( V_11 ) . V_16 [ V_22 ] ;
V_13 = V_14 - V_15 ;
if ( V_12 )
* V_12 = F_8 ( V_14 ) ;
return F_8 ( V_13 ) ;
}
T_1 F_9 ( unsigned int V_11 , T_1 * V_12 , int V_23 )
{
T_1 V_13 = F_10 ( V_11 , V_23 ? V_12 : NULL ) ;
if ( V_13 == - 1ULL )
return F_4 ( V_11 , V_12 ) ;
else if ( ! V_23 )
V_13 += F_11 ( V_11 , V_12 ) ;
return V_13 ;
}
void F_12 ( struct V_7 * V_7 , int V_11 )
{
struct V_24 * V_25 = V_7 -> V_8 -> V_26 ( V_11 ) ;
struct V_27 * V_28 = V_7 -> V_29 ;
struct V_30 * V_31 = V_7 -> V_29 ;
struct V_2 * V_3 ;
unsigned int V_32 = 0 ;
unsigned int V_33 ;
unsigned int V_34 ;
if ( V_7 -> V_8 -> V_35 == V_36 )
V_33 = V_28 -> V_33 ;
else
V_33 = V_31 -> V_33 ;
V_3 = V_25 -> V_37 ;
F_13 (j, policy->cpus) {
struct V_24 * V_38 ;
T_1 V_14 , V_39 ;
unsigned int V_13 , V_40 ;
unsigned int V_41 ;
int V_23 = 0 ;
V_38 = V_7 -> V_8 -> V_26 ( V_34 ) ;
if ( V_7 -> V_8 -> V_35 == V_36 )
V_23 = V_28 -> V_42 ;
V_39 = F_9 ( V_34 , & V_14 , V_23 ) ;
V_40 = ( unsigned int )
( V_14 - V_38 -> V_43 ) ;
V_38 -> V_43 = V_14 ;
V_13 = ( unsigned int )
( V_39 - V_38 -> V_44 ) ;
V_38 -> V_44 = V_39 ;
if ( V_33 ) {
T_1 V_45 ;
unsigned long V_46 ;
V_45 = F_7 ( V_34 ) . V_16 [ V_22 ] -
V_25 -> V_47 ;
V_46 = ( unsigned long )
F_14 ( V_45 ) ;
V_25 -> V_47 =
F_7 ( V_34 ) . V_16 [ V_22 ] ;
V_13 += F_15 ( V_46 ) ;
}
if ( F_16 ( ! V_40 || V_40 < V_13 ) )
continue;
V_41 = 100 * ( V_40 - V_13 ) / V_40 ;
if ( V_7 -> V_8 -> V_35 == V_36 ) {
int V_48 = F_17 ( V_3 , V_34 ) ;
if ( V_48 <= 0 )
V_48 = V_3 -> V_49 ;
V_41 *= V_48 ;
}
if ( V_41 > V_32 )
V_32 = V_41 ;
}
V_7 -> V_8 -> V_50 ( V_11 , V_32 ) ;
}
static inline void F_18 ( int V_11 , struct V_7 * V_7 ,
unsigned int V_51 )
{
struct V_24 * V_25 = V_7 -> V_8 -> V_26 ( V_11 ) ;
F_19 ( V_11 , V_52 , & V_25 -> V_53 , V_51 ) ;
}
void F_20 ( struct V_7 * V_7 , struct V_2 * V_3 ,
unsigned int V_51 , bool V_54 )
{
int V_55 ;
if ( ! V_54 ) {
F_18 ( F_21 () , V_7 , V_51 ) ;
} else {
F_22 () ;
F_13 (i, policy->cpus)
F_18 ( V_55 , V_7 , V_51 ) ;
F_23 () ;
}
}
static inline void F_24 ( struct V_7 * V_7 ,
struct V_2 * V_3 )
{
struct V_24 * V_25 ;
int V_55 ;
F_13 (i, policy->cpus) {
V_25 = V_7 -> V_8 -> V_26 ( V_55 ) ;
F_25 ( & V_25 -> V_53 ) ;
}
}
bool F_26 ( struct V_24 * V_25 ,
unsigned int V_56 )
{
if ( F_27 ( V_25 -> V_37 ) ) {
T_2 V_57 = F_28 () ;
T_3 V_58 = F_29 ( V_57 , V_25 -> V_59 ) ;
if ( V_58 < ( T_3 ) ( V_56 / 2 ) )
return false ;
else
V_25 -> V_59 = V_57 ;
}
return true ;
}
static void F_30 ( struct V_7 * V_7 ,
unsigned int V_56 )
{
if ( V_7 -> V_8 -> V_35 == V_60 ) {
struct V_30 * V_31 = V_7 -> V_29 ;
V_31 -> V_56 = V_56 ;
} else {
struct V_27 * V_28 = V_7 -> V_29 ;
V_28 -> V_56 = V_56 ;
}
}
int F_31 ( struct V_2 * V_3 ,
struct V_61 * V_8 , unsigned int V_62 )
{
struct V_7 * V_7 ;
struct V_63 * V_64 = NULL ;
struct V_65 * V_66 = NULL ;
struct V_67 * V_67 = NULL ;
struct V_27 * V_28 = NULL ;
struct V_30 * V_31 = NULL ;
struct V_24 * V_68 ;
unsigned int V_56 , V_69 , V_33 , V_34 , V_11 = V_3 -> V_11 ;
int V_23 = 0 ;
int V_70 ;
if ( F_2 () )
V_7 = V_3 -> V_71 ;
else
V_7 = V_8 -> V_72 ;
F_32 ( ! V_7 && ( V_62 != V_73 ) ) ;
switch ( V_62 ) {
case V_73 :
if ( F_2 () ) {
F_32 ( V_7 ) ;
} else if ( V_7 ) {
V_7 -> V_74 ++ ;
V_3 -> V_71 = V_7 ;
return 0 ;
}
V_7 = F_33 ( sizeof( * V_7 ) , V_75 ) ;
if ( ! V_7 ) {
F_34 ( L_1 , V_76 ) ;
return - V_77 ;
}
V_7 -> V_8 = V_8 ;
V_7 -> V_74 = 1 ;
V_70 = V_8 -> V_78 ( V_7 ) ;
if ( V_70 ) {
F_34 ( L_2 , V_76 ) ;
F_35 ( V_7 ) ;
return V_70 ;
}
V_70 = F_36 ( F_1 ( V_3 ) ,
F_3 ( V_7 ) ) ;
if ( V_70 ) {
V_8 -> exit ( V_7 ) ;
F_35 ( V_7 ) ;
return V_70 ;
}
V_3 -> V_71 = V_7 ;
V_69 = V_3 -> V_79 . V_80 / 1000 ;
if ( V_69 == 0 )
V_69 = 1 ;
V_7 -> V_81 = F_37 ( V_7 -> V_81 ,
V_82 * V_69 ) ;
F_30 ( V_7 , F_37 ( V_7 -> V_81 ,
V_69 * V_83 ) ) ;
if ( ( V_8 -> V_35 == V_60 ) &&
( ! V_3 -> V_35 -> V_84 ) ) {
struct V_85 * V_85 = V_7 -> V_8 -> V_86 ;
F_38 ( V_85 -> V_87 ,
V_88 ) ;
}
if ( ! F_2 () )
V_8 -> V_72 = V_7 ;
return 0 ;
case V_89 :
if ( ! -- V_7 -> V_74 ) {
F_39 ( F_1 ( V_3 ) ,
F_3 ( V_7 ) ) ;
if ( ( V_7 -> V_8 -> V_35 == V_60 ) &&
( V_3 -> V_35 -> V_84 == 1 ) ) {
struct V_85 * V_85 = V_7 -> V_8 -> V_86 ;
F_40 ( V_85 -> V_87 ,
V_88 ) ;
}
V_8 -> exit ( V_7 ) ;
F_35 ( V_7 ) ;
V_8 -> V_72 = NULL ;
}
V_3 -> V_71 = NULL ;
return 0 ;
}
V_68 = V_7 -> V_8 -> V_26 ( V_11 ) ;
if ( V_7 -> V_8 -> V_35 == V_60 ) {
V_31 = V_7 -> V_29 ;
V_66 = V_7 -> V_8 -> V_90 ( V_11 ) ;
V_56 = V_31 -> V_56 ;
V_33 = V_31 -> V_33 ;
} else {
V_28 = V_7 -> V_29 ;
V_64 = V_7 -> V_8 -> V_90 ( V_11 ) ;
V_56 = V_28 -> V_56 ;
V_33 = V_28 -> V_33 ;
V_67 = V_7 -> V_8 -> V_86 ;
V_23 = V_28 -> V_42 ;
}
switch ( V_62 ) {
case V_91 :
if ( ! V_3 -> V_49 )
return - V_92 ;
F_41 ( & V_7 -> V_93 ) ;
F_13 (j, policy->cpus) {
struct V_24 * V_38 =
V_7 -> V_8 -> V_26 ( V_34 ) ;
V_38 -> V_11 = V_34 ;
V_38 -> V_37 = V_3 ;
V_38 -> V_44 = F_9 ( V_34 ,
& V_38 -> V_43 , V_23 ) ;
if ( V_33 )
V_38 -> V_47 =
F_7 ( V_34 ) . V_16 [ V_22 ] ;
F_42 ( & V_38 -> V_94 ) ;
F_43 ( & V_38 -> V_53 ,
V_7 -> V_8 -> V_95 ) ;
}
if ( V_7 -> V_8 -> V_35 == V_60 ) {
V_66 -> V_96 = 0 ;
V_66 -> V_97 = 1 ;
V_66 -> V_98 = V_3 -> V_49 ;
} else {
V_64 -> V_99 = 1 ;
V_64 -> V_100 = V_101 ;
V_67 -> V_102 ( V_11 ) ;
}
F_44 ( & V_7 -> V_93 ) ;
V_68 -> V_59 = F_28 () ;
F_20 ( V_7 , V_3 ,
F_45 ( V_56 ) , true ) ;
break;
case V_103 :
if ( V_7 -> V_8 -> V_35 == V_60 )
V_66 -> V_97 = 0 ;
F_24 ( V_7 , V_3 ) ;
F_41 ( & V_7 -> V_93 ) ;
F_46 ( & V_68 -> V_94 ) ;
F_44 ( & V_7 -> V_93 ) ;
break;
case V_104 :
F_41 ( & V_68 -> V_94 ) ;
if ( V_3 -> F_37 < V_68 -> V_37 -> V_49 )
F_47 ( V_68 -> V_37 ,
V_3 -> F_37 , V_105 ) ;
else if ( V_3 -> V_106 > V_68 -> V_37 -> V_49 )
F_47 ( V_68 -> V_37 ,
V_3 -> V_106 , V_107 ) ;
F_12 ( V_7 , V_11 ) ;
F_44 ( & V_68 -> V_94 ) ;
break;
}
return 0 ;
}
