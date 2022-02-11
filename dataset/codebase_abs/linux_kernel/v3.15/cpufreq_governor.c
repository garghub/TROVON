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
F_13 ( & V_45 ) ;
if ( ! V_16 -> V_46 )
goto V_47;
if ( ! V_43 ) {
F_10 ( F_14 () , V_2 , V_40 ) ;
} else {
F_4 (i, policy->cpus)
F_10 ( V_44 , V_2 , V_40 ) ;
}
V_47:
F_15 ( & V_45 ) ;
}
static inline void F_16 ( struct V_2 * V_2 ,
struct V_15 * V_16 )
{
struct V_7 * V_8 ;
int V_44 ;
F_4 (i, policy->cpus) {
V_8 = V_2 -> V_3 -> V_9 ( V_44 ) ;
F_17 ( & V_8 -> V_42 ) ;
}
}
bool F_18 ( struct V_7 * V_8 ,
unsigned int V_48 )
{
if ( F_19 ( V_8 -> V_23 ) ) {
T_2 V_49 = F_20 () ;
T_3 V_50 = F_21 ( V_49 , V_8 -> V_51 ) ;
if ( V_50 < ( T_3 ) ( V_48 / 2 ) )
return false ;
else
V_8 -> V_51 = V_49 ;
}
return true ;
}
static void F_22 ( struct V_2 * V_2 ,
unsigned int V_48 )
{
if ( V_2 -> V_3 -> V_20 == V_52 ) {
struct V_13 * V_14 = V_2 -> V_12 ;
V_14 -> V_48 = V_48 ;
} else {
struct V_10 * V_11 = V_2 -> V_12 ;
V_11 -> V_48 = V_48 ;
}
}
int F_23 ( struct V_15 * V_16 ,
struct V_53 * V_3 , unsigned int V_54 )
{
struct V_2 * V_2 ;
struct V_55 * V_56 = NULL ;
struct V_57 * V_58 = NULL ;
struct V_59 * V_59 = NULL ;
struct V_10 * V_11 = NULL ;
struct V_13 * V_14 = NULL ;
struct V_7 * V_60 ;
unsigned int V_48 , V_61 , V_18 , V_19 , V_6 = V_16 -> V_6 ;
int V_30 = 0 ;
int V_62 ;
if ( F_2 () )
V_2 = V_16 -> V_63 ;
else
V_2 = V_3 -> V_64 ;
F_24 ( ! V_2 && ( V_54 != V_65 ) ) ;
switch ( V_54 ) {
case V_65 :
if ( F_2 () ) {
F_24 ( V_2 ) ;
} else if ( V_2 ) {
V_2 -> V_66 ++ ;
V_16 -> V_63 = V_2 ;
return 0 ;
}
V_2 = F_25 ( sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 ) {
F_26 ( L_1 , V_68 ) ;
return - V_69 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_66 = 1 ;
V_62 = V_3 -> V_70 ( V_2 ) ;
if ( V_62 ) {
F_26 ( L_2 , V_68 ) ;
F_27 ( V_2 ) ;
return V_62 ;
}
if ( ! F_2 () )
F_24 ( F_28 () ) ;
V_62 = F_29 ( F_30 ( V_16 ) ,
F_1 ( V_2 ) ) ;
if ( V_62 ) {
V_3 -> exit ( V_2 ) ;
F_27 ( V_2 ) ;
return V_62 ;
}
V_16 -> V_63 = V_2 ;
V_61 = V_16 -> V_71 . V_72 / 1000 ;
if ( V_61 == 0 )
V_61 = 1 ;
V_2 -> V_73 = F_31 ( V_2 -> V_73 ,
V_74 * V_61 ) ;
F_22 ( V_2 , F_31 ( V_2 -> V_73 ,
V_61 * V_75 ) ) ;
if ( ( V_3 -> V_20 == V_52 ) &&
( ! V_16 -> V_20 -> V_76 ) ) {
struct V_77 * V_77 = V_2 -> V_3 -> V_78 ;
F_32 ( V_77 -> V_79 ,
V_80 ) ;
}
if ( ! F_2 () )
V_3 -> V_64 = V_2 ;
return 0 ;
case V_81 :
if ( ! -- V_2 -> V_66 ) {
F_33 ( F_30 ( V_16 ) ,
F_1 ( V_2 ) ) ;
if ( ! F_2 () )
F_34 () ;
if ( ( V_2 -> V_3 -> V_20 == V_52 ) &&
( V_16 -> V_20 -> V_76 == 1 ) ) {
struct V_77 * V_77 = V_2 -> V_3 -> V_78 ;
F_35 ( V_77 -> V_79 ,
V_80 ) ;
}
V_3 -> exit ( V_2 ) ;
F_27 ( V_2 ) ;
V_3 -> V_64 = NULL ;
}
V_16 -> V_63 = NULL ;
return 0 ;
}
V_60 = V_2 -> V_3 -> V_9 ( V_6 ) ;
if ( V_2 -> V_3 -> V_20 == V_52 ) {
V_14 = V_2 -> V_12 ;
V_58 = V_2 -> V_3 -> V_82 ( V_6 ) ;
V_48 = V_14 -> V_48 ;
V_18 = V_14 -> V_22 ;
} else {
V_11 = V_2 -> V_12 ;
V_56 = V_2 -> V_3 -> V_82 ( V_6 ) ;
V_48 = V_11 -> V_48 ;
V_18 = V_11 -> V_22 ;
V_59 = V_2 -> V_3 -> V_78 ;
V_30 = V_11 -> V_31 ;
}
switch ( V_54 ) {
case V_83 :
if ( ! V_16 -> V_84 )
return - V_85 ;
F_13 ( & V_2 -> V_86 ) ;
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
F_36 ( & V_24 -> V_87 ) ;
F_37 ( & V_24 -> V_42 ,
V_2 -> V_3 -> V_88 ) ;
}
if ( V_2 -> V_3 -> V_20 == V_52 ) {
V_58 -> V_89 = 0 ;
V_58 -> V_90 = 1 ;
V_58 -> V_91 = V_16 -> V_84 ;
} else {
V_56 -> V_92 = 1 ;
V_56 -> V_93 = V_94 ;
V_59 -> V_95 ( V_6 ) ;
}
F_15 ( & V_2 -> V_86 ) ;
V_60 -> V_51 = F_20 () ;
F_12 ( V_2 , V_16 ,
F_38 ( V_48 ) , true ) ;
break;
case V_96 :
if ( V_2 -> V_3 -> V_20 == V_52 )
V_58 -> V_90 = 0 ;
F_16 ( V_2 , V_16 ) ;
F_13 ( & V_2 -> V_86 ) ;
F_39 ( & V_60 -> V_87 ) ;
V_60 -> V_23 = NULL ;
F_15 ( & V_2 -> V_86 ) ;
break;
case V_97 :
F_13 ( & V_2 -> V_86 ) ;
if ( ! V_60 -> V_23 ) {
F_15 ( & V_2 -> V_86 ) ;
break;
}
F_13 ( & V_60 -> V_87 ) ;
if ( V_16 -> F_31 < V_60 -> V_23 -> V_84 )
F_40 ( V_60 -> V_23 ,
V_16 -> F_31 , V_98 ) ;
else if ( V_16 -> V_99 > V_60 -> V_23 -> V_84 )
F_40 ( V_60 -> V_23 ,
V_16 -> V_99 , V_100 ) ;
F_3 ( V_2 , V_6 ) ;
F_15 ( & V_60 -> V_87 ) ;
F_15 ( & V_2 -> V_86 ) ;
break;
}
return 0 ;
}
