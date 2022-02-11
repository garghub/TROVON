static T_1 * F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_2 * V_4 ;
T_3 * V_5 ;
T_4 * V_6 ;
T_1 * V_7 ;
V_4 = F_2 ( V_2 , V_3 ) ;
if ( F_3 ( V_4 ) )
return NULL ;
V_5 = F_4 ( V_4 , V_3 ) ;
if ( F_5 ( V_5 ) )
return NULL ;
V_6 = F_6 ( V_5 , V_3 ) ;
if ( F_7 ( V_6 ) )
return NULL ;
V_7 = F_8 ( V_6 , V_3 ) ;
if ( F_9 ( * V_7 ) )
return NULL ;
return V_7 ;
}
static T_1 * F_10 ( struct V_1 * V_2 , struct V_8 * V_9 ,
unsigned long V_3 )
{
T_2 * V_4 ;
T_3 * V_5 ;
T_4 * V_6 ;
T_1 * V_7 ;
V_4 = F_2 ( V_2 , V_3 ) ;
V_5 = F_11 ( V_2 , V_4 , V_3 ) ;
if ( ! V_5 )
return NULL ;
V_6 = F_12 ( V_2 , V_5 , V_3 ) ;
if ( ! V_6 )
return NULL ;
V_7 = F_13 ( V_2 , V_6 , V_3 ) ;
if ( ! V_7 )
return NULL ;
F_14 ( F_15 ( * V_7 ) ) ;
return V_7 ;
}
static void F_16 ( struct V_8 * V_9 )
{
if ( V_9 -> V_10 )
F_17 ( V_9 -> V_10 -> V_11 ) ;
if ( V_9 -> V_12 )
F_18 ( V_9 -> V_12 ) ;
}
static void F_19 ( struct V_8 * V_9 )
{
if ( V_9 -> V_12 )
F_20 ( V_9 -> V_12 ) ;
if ( V_9 -> V_10 )
F_21 ( V_9 -> V_10 -> V_11 ) ;
}
static T_5 F_22 ( T_5 V_13 )
{
#ifdef F_23
if ( F_24 ( V_13 ) )
V_13 = F_25 ( V_13 ) ;
else if ( F_26 ( V_13 ) )
V_13 = F_27 ( V_13 ) ;
#endif
return V_13 ;
}
static void F_28 ( struct V_8 * V_9 , T_1 * V_14 ,
unsigned long V_15 , unsigned long V_16 ,
struct V_8 * V_17 , T_1 * V_18 ,
unsigned long V_19 , bool V_20 , bool * V_21 )
{
struct V_1 * V_2 = V_9 -> V_22 ;
T_5 * V_23 , * V_24 , V_13 ;
T_6 * V_25 , * V_26 ;
bool V_27 = false ;
unsigned long V_28 = V_16 - V_15 ;
if ( V_20 )
F_16 ( V_9 ) ;
V_23 = F_29 ( V_2 , V_14 , V_15 , & V_25 ) ;
V_24 = F_30 ( V_18 , V_19 ) ;
V_26 = F_31 ( V_2 , V_18 ) ;
if ( V_26 != V_25 )
F_32 ( V_26 , V_29 ) ;
F_33 ( V_9 -> V_22 ) ;
F_34 () ;
for (; V_15 < V_16 ; V_23 ++ , V_15 += V_30 ,
V_24 ++ , V_19 += V_30 ) {
if ( F_35 ( * V_23 ) )
continue;
V_13 = F_36 ( V_2 , V_15 , V_23 ) ;
if ( F_24 ( V_13 ) && F_37 ( V_13 ) )
V_27 = true ;
V_13 = F_38 ( V_13 , V_17 -> V_31 , V_15 , V_19 ) ;
V_13 = F_22 ( V_13 ) ;
F_39 ( V_2 , V_19 , V_24 , V_13 ) ;
}
F_40 () ;
if ( V_26 != V_25 )
F_41 ( V_26 ) ;
F_42 ( V_24 - 1 ) ;
if ( V_27 )
F_43 ( V_9 , V_16 - V_28 , V_16 ) ;
else
* V_21 = true ;
F_44 ( V_23 - 1 , V_25 ) ;
if ( V_20 )
F_19 ( V_9 ) ;
}
unsigned long F_45 ( struct V_8 * V_9 ,
unsigned long V_15 , struct V_8 * V_17 ,
unsigned long V_19 , unsigned long V_28 ,
bool V_20 )
{
unsigned long V_32 , V_33 , V_16 ;
T_1 * V_14 , * V_18 ;
bool V_21 = false ;
unsigned long V_34 ;
unsigned long V_35 ;
V_16 = V_15 + V_28 ;
F_46 ( V_9 , V_15 , V_16 ) ;
V_34 = V_15 ;
V_35 = V_16 ;
F_47 ( V_9 -> V_22 , V_34 , V_35 ) ;
for (; V_15 < V_16 ; V_15 += V_32 , V_19 += V_32 ) {
F_48 () ;
V_33 = ( V_15 + V_36 ) & V_37 ;
V_32 = V_33 - V_15 ;
if ( V_32 > V_16 - V_15 )
V_32 = V_16 - V_15 ;
V_14 = F_1 ( V_9 -> V_22 , V_15 ) ;
if ( ! V_14 )
continue;
V_18 = F_10 ( V_9 -> V_22 , V_9 , V_19 ) ;
if ( ! V_18 )
break;
if ( F_49 ( * V_14 ) || F_15 ( * V_14 ) ) {
if ( V_32 == V_38 ) {
bool V_39 ;
if ( V_20 )
F_16 ( V_9 ) ;
V_39 = F_50 ( V_9 , V_15 , V_19 ,
V_16 , V_14 , V_18 ,
& V_21 ) ;
if ( V_20 )
F_19 ( V_9 ) ;
if ( V_39 )
continue;
}
F_51 ( V_9 , V_14 , V_15 ) ;
if ( F_52 ( V_14 ) )
continue;
}
if ( F_53 ( V_17 -> V_22 , V_18 , V_19 ) )
break;
V_33 = ( V_19 + V_36 ) & V_37 ;
if ( V_32 > V_33 - V_19 )
V_32 = V_33 - V_19 ;
if ( V_32 > V_40 )
V_32 = V_40 ;
F_28 ( V_9 , V_14 , V_15 , V_15 + V_32 , V_17 ,
V_18 , V_19 , V_20 , & V_21 ) ;
}
if ( V_21 )
F_43 ( V_9 , V_16 - V_28 , V_15 ) ;
F_54 ( V_9 -> V_22 , V_34 , V_35 ) ;
return V_28 + V_15 - V_16 ;
}
static unsigned long F_55 ( struct V_8 * V_9 ,
unsigned long V_15 , unsigned long V_41 ,
unsigned long V_42 , unsigned long V_19 ,
bool * V_43 , struct V_44 * V_45 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = V_9 -> V_22 ;
struct V_8 * V_17 ;
unsigned long V_48 = V_9 -> V_48 ;
unsigned long V_49 ;
unsigned long V_50 ;
unsigned long V_51 = 0 ;
unsigned long V_52 ;
int V_53 = 0 ;
int V_54 ;
bool V_20 ;
if ( V_2 -> V_55 >= V_56 - 3 )
return - V_57 ;
V_54 = F_56 ( V_9 , V_15 , V_15 + V_41 ,
V_58 , & V_48 ) ;
if ( V_54 )
return V_54 ;
V_49 = V_9 -> V_59 + ( ( V_15 - V_9 -> V_60 ) >> V_61 ) ;
V_17 = F_57 ( & V_9 , V_19 , V_42 , V_49 ,
& V_20 ) ;
if ( ! V_17 )
return - V_57 ;
V_50 = F_45 ( V_9 , V_15 , V_17 , V_19 , V_41 ,
V_20 ) ;
if ( V_50 < V_41 ) {
V_54 = - V_57 ;
} else if ( V_9 -> V_62 && V_9 -> V_62 -> V_63 ) {
V_54 = V_9 -> V_62 -> V_63 ( V_17 ) ;
}
if ( F_58 ( V_54 ) ) {
F_45 ( V_17 , V_19 , V_9 , V_15 , V_50 ,
true ) ;
V_9 = V_17 ;
V_41 = V_42 ;
V_15 = V_19 ;
V_19 = V_54 ;
} else {
F_59 ( V_17 , V_45 ) ;
F_60 ( V_2 , V_15 , V_15 + V_41 ,
V_19 , V_19 + V_42 ) ;
}
if ( V_48 & V_64 ) {
V_9 -> V_48 &= ~ V_64 ;
V_51 = V_9 -> V_65 - V_9 -> V_60 - V_41 ;
if ( V_15 > V_9 -> V_60 &&
V_15 + V_41 < V_9 -> V_65 )
V_53 = 1 ;
}
V_52 = V_2 -> V_52 ;
F_61 ( V_2 , V_9 -> V_48 , V_42 >> V_61 ) ;
if ( F_58 ( V_9 -> V_48 & V_66 ) )
F_62 ( V_9 ) ;
if ( F_63 ( V_2 , V_15 , V_41 , V_47 ) < 0 ) {
F_64 ( V_51 >> V_61 ) ;
V_51 = 0 ;
}
V_2 -> V_52 = V_52 ;
if ( V_51 ) {
V_9 -> V_48 |= V_64 ;
if ( V_53 )
V_9 -> V_67 -> V_48 |= V_64 ;
}
if ( V_48 & V_68 ) {
V_2 -> V_69 += V_42 >> V_61 ;
* V_43 = true ;
}
return V_19 ;
}
static struct V_8 * F_65 ( unsigned long V_3 ,
unsigned long V_41 , unsigned long V_42 , unsigned long * V_70 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_8 * V_9 = F_66 ( V_2 , V_3 ) ;
unsigned long V_72 ;
if ( ! V_9 || V_9 -> V_60 > V_3 )
return F_67 ( - V_73 ) ;
if ( ! V_41 && ! ( V_9 -> V_48 & ( V_74 | V_75 ) ) ) {
F_68 ( L_1 , V_71 -> V_76 , V_71 -> V_77 ) ;
return F_67 ( - V_78 ) ;
}
if ( F_69 ( V_9 ) )
return F_67 ( - V_78 ) ;
if ( V_41 > V_9 -> V_65 - V_3 )
return F_67 ( - V_73 ) ;
if ( V_42 == V_41 )
return V_9 ;
V_72 = ( V_3 - V_9 -> V_60 ) >> V_61 ;
V_72 += V_9 -> V_59 ;
if ( V_72 + ( V_42 >> V_61 ) < V_72 )
return F_67 ( - V_78 ) ;
if ( V_9 -> V_48 & ( V_79 | V_66 ) )
return F_67 ( - V_73 ) ;
if ( V_9 -> V_48 & V_68 ) {
unsigned long V_43 , V_80 ;
V_43 = V_2 -> V_69 << V_61 ;
V_80 = F_70 ( V_81 ) ;
V_43 += V_42 - V_41 ;
if ( V_43 > V_80 && ! F_71 ( V_82 ) )
return F_67 ( - V_83 ) ;
}
if ( ! F_72 ( V_2 , V_9 -> V_48 ,
( V_42 - V_41 ) >> V_61 ) )
return F_67 ( - V_57 ) ;
if ( V_9 -> V_48 & V_64 ) {
unsigned long V_84 = ( V_42 - V_41 ) >> V_61 ;
if ( F_73 ( V_2 , V_84 ) )
return F_67 ( - V_57 ) ;
* V_70 = V_84 ;
}
return V_9 ;
}
static unsigned long F_74 ( unsigned long V_3 , unsigned long V_41 ,
unsigned long V_19 , unsigned long V_42 , bool * V_43 ,
struct V_44 * V_45 ,
struct V_46 * V_85 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_8 * V_9 ;
unsigned long V_86 = - V_78 ;
unsigned long V_84 = 0 ;
unsigned long V_87 ;
if ( F_75 ( V_19 ) )
goto V_88;
if ( V_42 > V_89 || V_19 > V_89 - V_42 )
goto V_88;
if ( V_3 + V_41 > V_19 && V_19 + V_42 > V_3 )
goto V_88;
V_86 = F_63 ( V_2 , V_19 , V_42 , V_85 ) ;
if ( V_86 )
goto V_88;
if ( V_41 >= V_42 ) {
V_86 = F_63 ( V_2 , V_3 + V_42 , V_41 - V_42 , V_47 ) ;
if ( V_86 && V_41 != V_42 )
goto V_88;
V_41 = V_42 ;
}
V_9 = F_65 ( V_3 , V_41 , V_42 , & V_84 ) ;
if ( F_76 ( V_9 ) ) {
V_86 = F_77 ( V_9 ) ;
goto V_88;
}
V_87 = V_90 ;
if ( V_9 -> V_48 & V_75 )
V_87 |= V_91 ;
V_86 = F_78 ( V_9 -> V_10 , V_19 , V_42 , V_9 -> V_59 +
( ( V_3 - V_9 -> V_60 ) >> V_61 ) ,
V_87 ) ;
if ( F_75 ( V_86 ) )
goto V_92;
V_86 = F_55 ( V_9 , V_3 , V_41 , V_42 , V_19 , V_43 , V_45 ,
V_47 ) ;
if ( ! ( F_75 ( V_86 ) ) )
goto V_88;
V_92:
F_64 ( V_84 ) ;
V_88:
return V_86 ;
}
static int F_79 ( struct V_8 * V_9 , unsigned long V_93 )
{
unsigned long V_94 = V_9 -> V_65 + V_93 ;
if ( V_94 < V_9 -> V_65 )
return 0 ;
if ( V_9 -> V_67 && V_9 -> V_67 -> V_60 < V_94 )
return 0 ;
if ( F_78 ( NULL , V_9 -> V_60 , V_94 - V_9 -> V_60 ,
0 , V_90 ) & ~ V_95 )
return 0 ;
return 1 ;
}
