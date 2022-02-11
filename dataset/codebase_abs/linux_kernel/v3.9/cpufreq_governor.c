static inline T_1 F_1 ( unsigned int V_1 , T_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
T_1 V_5 ;
V_4 = F_2 ( F_3 () ) ;
V_5 = F_4 ( V_1 ) . V_6 [ V_7 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_8 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_9 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_10 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_11 ] ;
V_5 += F_4 ( V_1 ) . V_6 [ V_12 ] ;
V_3 = V_4 - V_5 ;
if ( V_2 )
* V_2 = F_5 ( V_4 ) ;
return F_5 ( V_3 ) ;
}
T_1 F_6 ( unsigned int V_1 , T_1 * V_2 )
{
T_1 V_3 = F_7 ( V_1 , NULL ) ;
if ( V_3 == - 1ULL )
return F_1 ( V_1 , V_2 ) ;
else
V_3 += F_8 ( V_1 , V_2 ) ;
return V_3 ;
}
void F_9 ( struct V_13 * V_13 , int V_1 )
{
struct V_14 * V_15 = V_13 -> V_16 ( V_1 ) ;
struct V_17 * V_18 = V_13 -> V_19 ;
struct V_20 * V_21 = V_13 -> V_19 ;
struct V_22 * V_23 ;
unsigned int V_24 = 0 ;
unsigned int V_25 ;
unsigned int V_26 ;
if ( V_13 -> V_27 == V_28 )
V_25 = V_18 -> V_25 ;
else
V_25 = V_21 -> V_25 ;
V_23 = V_15 -> V_29 ;
F_10 (j, policy->cpus) {
struct V_14 * V_30 ;
T_1 V_4 , V_31 , V_32 ;
unsigned int V_3 , V_33 , V_34 ;
unsigned int V_35 ;
V_30 = V_13 -> V_16 ( V_26 ) ;
V_31 = F_6 ( V_26 , & V_4 ) ;
V_33 = ( unsigned int )
( V_4 - V_30 -> V_36 ) ;
V_30 -> V_36 = V_4 ;
V_3 = ( unsigned int )
( V_31 - V_30 -> V_37 ) ;
V_30 -> V_37 = V_31 ;
if ( V_25 ) {
T_1 V_38 ;
unsigned long V_39 ;
V_38 = F_4 ( V_26 ) . V_6 [ V_12 ] -
V_15 -> V_40 ;
V_39 = ( unsigned long )
F_11 ( V_38 ) ;
V_15 -> V_40 =
F_4 ( V_26 ) . V_6 [ V_12 ] ;
V_3 += F_12 ( V_39 ) ;
}
if ( V_13 -> V_27 == V_28 ) {
struct V_41 * V_42 =
V_13 -> V_43 ( V_1 ) ;
V_32 = F_8 ( V_26 ,
& V_4 ) ;
if ( V_32 == - 1ULL )
V_32 = 0 ;
V_34 = ( unsigned int ) ( V_32 -
V_42 -> V_44 ) ;
V_42 -> V_44 = V_32 ;
if ( V_18 -> V_45 && V_3 >= V_34 )
V_3 -= V_34 ;
}
if ( F_13 ( ! V_33 || V_33 < V_3 ) )
continue;
V_35 = 100 * ( V_33 - V_3 ) / V_33 ;
if ( V_13 -> V_27 == V_28 ) {
int V_46 = F_14 ( V_23 , V_26 ) ;
if ( V_46 <= 0 )
V_46 = V_23 -> V_47 ;
V_35 *= V_46 ;
}
if ( V_35 > V_24 )
V_24 = V_35 ;
}
V_13 -> V_48 ( V_1 , V_24 ) ;
}
static inline void F_15 ( struct V_13 * V_13 , int V_1 ,
unsigned int V_49 )
{
int V_50 = F_16 ( V_49 ) ;
struct V_14 * V_15 = V_13 -> V_16 ( V_1 ) ;
F_17 ( V_1 , & V_15 -> V_51 , V_50 ) ;
}
static inline void F_18 ( struct V_13 * V_13 , int V_1 )
{
struct V_14 * V_15 = V_13 -> V_16 ( V_1 ) ;
F_19 ( & V_15 -> V_51 ) ;
}
bool F_20 ( struct V_14 * V_15 ,
unsigned int V_49 )
{
if ( F_21 ( V_15 -> V_29 ) ) {
T_2 V_52 = F_22 () ;
T_3 V_53 = F_23 ( V_52 , V_15 -> V_54 ) ;
if ( V_53 < ( T_3 ) ( V_49 / 2 ) )
return false ;
else
V_15 -> V_54 = V_52 ;
}
return true ;
}
int F_24 ( struct V_13 * V_13 ,
struct V_22 * V_23 , unsigned int V_55 )
{
struct V_41 * V_56 = NULL ;
struct V_57 * V_58 = NULL ;
struct V_59 * V_59 = NULL ;
struct V_60 * V_60 = NULL ;
struct V_17 * V_18 = V_13 -> V_19 ;
struct V_20 * V_21 = V_13 -> V_19 ;
struct V_14 * V_61 ;
unsigned int * V_49 , V_62 , V_25 , V_26 , V_1 = V_23 -> V_1 ;
int V_63 ;
V_61 = V_13 -> V_16 ( V_1 ) ;
if ( V_13 -> V_27 == V_64 ) {
V_58 = V_13 -> V_43 ( V_1 ) ;
V_49 = & V_21 -> V_49 ;
V_25 = V_21 -> V_25 ;
V_59 = V_13 -> V_65 ;
} else {
V_56 = V_13 -> V_43 ( V_1 ) ;
V_49 = & V_18 -> V_49 ;
V_25 = V_18 -> V_25 ;
V_60 = V_13 -> V_65 ;
}
switch ( V_55 ) {
case V_66 :
if ( ! V_23 -> V_47 )
return - V_67 ;
F_25 ( & V_13 -> V_68 ) ;
F_10 (j, policy->cpus) {
struct V_14 * V_30 =
V_13 -> V_16 ( V_26 ) ;
V_30 -> V_1 = V_26 ;
V_30 -> V_29 = V_23 ;
V_30 -> V_37 = F_6 ( V_26 ,
& V_30 -> V_36 ) ;
if ( V_25 )
V_30 -> V_40 =
F_4 ( V_26 ) . V_6 [ V_12 ] ;
F_26 ( & V_30 -> V_69 ) ;
F_27 ( & V_30 -> V_51 ,
V_13 -> V_70 ) ;
}
if ( ! V_23 -> V_27 -> V_71 ) {
V_63 = F_28 ( V_72 ,
V_13 -> V_73 ) ;
if ( V_63 ) {
F_29 ( & V_13 -> V_68 ) ;
return V_63 ;
}
}
if ( V_13 -> V_27 == V_64 ) {
V_58 -> V_74 = 0 ;
V_58 -> V_75 = 1 ;
V_58 -> V_76 = V_23 -> V_47 ;
if ( ! V_23 -> V_27 -> V_71 ) {
F_30 ( V_59 -> V_77 ,
V_78 ) ;
V_13 -> V_79 =
V_80 *
F_12 ( 10 ) ;
}
} else {
V_56 -> V_81 = 1 ;
V_56 -> V_82 = V_83 ;
V_60 -> V_84 ( V_1 ) ;
if ( ! V_23 -> V_27 -> V_71 )
V_18 -> V_45 = V_60 -> V_85 () ;
}
if ( V_23 -> V_27 -> V_71 )
goto V_86;
V_62 = V_23 -> V_87 . V_88 / 1000 ;
if ( V_62 == 0 )
V_62 = 1 ;
V_13 -> V_79 = F_31 ( V_13 -> V_79 ,
V_89 * V_62 ) ;
* V_49 = F_31 ( V_13 -> V_79 , V_62 *
V_90 ) ;
V_86:
F_29 ( & V_13 -> V_68 ) ;
V_61 -> V_54 = F_22 () ;
F_10 (j, policy->cpus)
F_15 ( V_13 , V_26 , * V_49 ) ;
break;
case V_91 :
if ( V_13 -> V_27 == V_64 )
V_58 -> V_75 = 0 ;
F_10 (j, policy->cpus)
F_18 ( V_13 , V_26 ) ;
F_25 ( & V_13 -> V_68 ) ;
F_32 ( & V_61 -> V_69 ) ;
if ( V_23 -> V_27 -> V_71 == 1 ) {
F_33 ( V_72 ,
V_13 -> V_73 ) ;
if ( V_13 -> V_27 == V_64 )
F_34 ( V_59 -> V_77 ,
V_78 ) ;
}
F_29 ( & V_13 -> V_68 ) ;
break;
case V_92 :
F_25 ( & V_61 -> V_69 ) ;
if ( V_23 -> F_31 < V_61 -> V_29 -> V_47 )
F_35 ( V_61 -> V_29 ,
V_23 -> F_31 , V_93 ) ;
else if ( V_23 -> V_94 > V_61 -> V_29 -> V_47 )
F_35 ( V_61 -> V_29 ,
V_23 -> V_94 , V_95 ) ;
F_9 ( V_13 , V_1 ) ;
F_29 ( & V_61 -> V_69 ) ;
break;
}
return 0 ;
}
