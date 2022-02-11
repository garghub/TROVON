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
static inline void F_15 ( struct V_13 * V_13 ,
struct V_14 * V_15 , unsigned int V_49 )
{
int V_50 = F_16 ( V_49 ) ;
F_17 ( & V_15 -> V_51 , V_13 -> V_52 ) ;
F_18 ( V_15 -> V_1 , & V_15 -> V_51 , V_50 ) ;
}
static inline void F_19 ( struct V_14 * V_15 )
{
F_20 ( & V_15 -> V_51 ) ;
}
int F_21 ( struct V_13 * V_13 ,
struct V_22 * V_23 , unsigned int V_53 )
{
struct V_41 * V_54 = NULL ;
struct V_55 * V_56 = NULL ;
struct V_17 * V_18 = V_13 -> V_19 ;
struct V_20 * V_21 = V_13 -> V_19 ;
struct V_14 * V_57 ;
unsigned int * V_49 , V_58 , V_25 , V_26 , V_1 = V_23 -> V_1 ;
int V_59 ;
V_57 = V_13 -> V_16 ( V_1 ) ;
if ( V_13 -> V_27 == V_60 ) {
V_56 = V_13 -> V_43 ( V_1 ) ;
V_49 = & V_21 -> V_49 ;
V_25 = V_21 -> V_25 ;
} else {
V_54 = V_13 -> V_43 ( V_1 ) ;
V_49 = & V_18 -> V_49 ;
V_25 = V_18 -> V_25 ;
}
switch ( V_53 ) {
case V_61 :
if ( ( ! F_22 ( V_1 ) ) || ( ! V_23 -> V_47 ) )
return - V_62 ;
F_23 ( & V_13 -> V_63 ) ;
V_13 -> V_64 ++ ;
V_57 -> V_1 = V_1 ;
F_10 (j, policy->cpus) {
struct V_14 * V_30 ;
V_30 = V_13 -> V_16 ( V_26 ) ;
V_30 -> V_29 = V_23 ;
V_30 -> V_37 = F_6 ( V_26 ,
& V_30 -> V_36 ) ;
if ( V_25 )
V_30 -> V_40 =
F_4 ( V_26 ) . V_6 [ V_12 ] ;
}
if ( V_13 -> V_64 != 1 )
goto V_65;
V_59 = F_24 ( V_66 ,
V_13 -> V_67 ) ;
if ( V_59 ) {
F_25 ( & V_13 -> V_63 ) ;
return V_59 ;
}
V_58 = V_23 -> V_68 . V_69 / 1000 ;
if ( V_58 == 0 )
V_58 = 1 ;
if ( V_13 -> V_27 == V_60 ) {
struct V_70 * V_71 = V_13 -> V_72 ;
F_26 ( V_71 -> V_73 ,
V_74 ) ;
V_13 -> V_75 = V_76 *
F_12 ( 10 ) ;
} else {
struct V_77 * V_71 = V_13 -> V_72 ;
V_18 -> V_45 = V_71 -> V_78 () ;
}
V_13 -> V_75 = F_27 ( V_13 -> V_75 ,
V_79 * V_58 ) ;
* V_49 = F_27 ( V_13 -> V_75 , V_58 *
V_80 ) ;
V_65:
if ( V_13 -> V_27 == V_60 ) {
V_56 -> V_81 = 0 ;
V_56 -> V_64 = 1 ;
V_56 -> V_82 = V_23 -> V_47 ;
} else {
struct V_77 * V_71 = V_13 -> V_72 ;
V_54 -> V_83 = 1 ;
V_54 -> V_84 = V_85 ;
V_71 -> V_86 ( V_1 ) ;
}
F_25 ( & V_13 -> V_63 ) ;
F_28 ( & V_57 -> V_87 ) ;
F_15 ( V_13 , V_57 , * V_49 ) ;
break;
case V_88 :
if ( V_13 -> V_27 == V_60 )
V_56 -> V_64 = 0 ;
F_19 ( V_57 ) ;
F_23 ( & V_13 -> V_63 ) ;
F_29 ( & V_57 -> V_87 ) ;
V_13 -> V_64 -- ;
if ( ! V_13 -> V_64 ) {
struct V_70 * V_71 = V_13 -> V_72 ;
F_30 ( V_66 ,
V_13 -> V_67 ) ;
if ( V_13 -> V_27 == V_60 )
F_31 ( V_71 -> V_73 ,
V_74 ) ;
}
F_25 ( & V_13 -> V_63 ) ;
break;
case V_89 :
F_23 ( & V_57 -> V_87 ) ;
if ( V_23 -> F_27 < V_57 -> V_29 -> V_47 )
F_32 ( V_57 -> V_29 ,
V_23 -> F_27 , V_90 ) ;
else if ( V_23 -> V_91 > V_57 -> V_29 -> V_47 )
F_32 ( V_57 -> V_29 ,
V_23 -> V_91 , V_92 ) ;
F_9 ( V_13 , V_1 ) ;
F_25 ( & V_57 -> V_87 ) ;
break;
}
return 0 ;
}
