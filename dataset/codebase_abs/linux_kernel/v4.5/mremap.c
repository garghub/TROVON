static T_1 * F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_2 * V_4 ;
T_3 * V_5 ;
T_1 * V_6 ;
V_4 = F_2 ( V_2 , V_3 ) ;
if ( F_3 ( V_4 ) )
return NULL ;
V_5 = F_4 ( V_4 , V_3 ) ;
if ( F_5 ( V_5 ) )
return NULL ;
V_6 = F_6 ( V_5 , V_3 ) ;
if ( F_7 ( * V_6 ) )
return NULL ;
return V_6 ;
}
static T_1 * F_8 ( struct V_1 * V_2 , struct V_7 * V_8 ,
unsigned long V_3 )
{
T_2 * V_4 ;
T_3 * V_5 ;
T_1 * V_6 ;
V_4 = F_2 ( V_2 , V_3 ) ;
V_5 = F_9 ( V_2 , V_4 , V_3 ) ;
if ( ! V_5 )
return NULL ;
V_6 = F_10 ( V_2 , V_5 , V_3 ) ;
if ( ! V_6 )
return NULL ;
F_11 ( F_12 ( * V_6 ) ) ;
return V_6 ;
}
static T_4 F_13 ( T_4 V_9 )
{
#ifdef F_14
if ( F_15 ( V_9 ) )
V_9 = F_16 ( V_9 ) ;
else if ( F_17 ( V_9 ) )
V_9 = F_18 ( V_9 ) ;
#endif
return V_9 ;
}
static void F_19 ( struct V_7 * V_8 , T_1 * V_10 ,
unsigned long V_11 , unsigned long V_12 ,
struct V_7 * V_13 , T_1 * V_14 ,
unsigned long V_15 , bool V_16 )
{
struct V_17 * V_18 = NULL ;
struct V_19 * V_19 = NULL ;
struct V_1 * V_2 = V_8 -> V_20 ;
T_4 * V_21 , * V_22 , V_9 ;
T_5 * V_23 , * V_24 ;
if ( V_16 ) {
if ( V_8 -> V_25 ) {
V_18 = V_8 -> V_25 -> V_26 ;
F_20 ( V_18 ) ;
}
if ( V_8 -> V_19 ) {
V_19 = V_8 -> V_19 ;
F_21 ( V_19 ) ;
}
}
V_21 = F_22 ( V_2 , V_10 , V_11 , & V_23 ) ;
V_22 = F_23 ( V_14 , V_15 ) ;
V_24 = F_24 ( V_2 , V_14 ) ;
if ( V_24 != V_23 )
F_25 ( V_24 , V_27 ) ;
F_26 () ;
for (; V_11 < V_12 ; V_21 ++ , V_11 += V_28 ,
V_22 ++ , V_15 += V_28 ) {
if ( F_27 ( * V_21 ) )
continue;
V_9 = F_28 ( V_2 , V_11 , V_21 ) ;
V_9 = F_29 ( V_9 , V_13 -> V_29 , V_11 , V_15 ) ;
V_9 = F_13 ( V_9 ) ;
F_30 ( V_2 , V_15 , V_22 , V_9 ) ;
}
F_31 () ;
if ( V_24 != V_23 )
F_32 ( V_24 ) ;
F_33 ( V_22 - 1 ) ;
F_34 ( V_21 - 1 , V_23 ) ;
if ( V_19 )
F_35 ( V_19 ) ;
if ( V_18 )
F_36 ( V_18 ) ;
}
unsigned long F_37 ( struct V_7 * V_8 ,
unsigned long V_11 , struct V_7 * V_13 ,
unsigned long V_15 , unsigned long V_30 ,
bool V_16 )
{
unsigned long V_31 , V_32 , V_12 ;
T_1 * V_10 , * V_14 ;
bool V_33 = false ;
unsigned long V_34 ;
unsigned long V_35 ;
V_12 = V_11 + V_30 ;
F_38 ( V_8 , V_11 , V_12 ) ;
V_34 = V_11 ;
V_35 = V_12 ;
F_39 ( V_8 -> V_20 , V_34 , V_35 ) ;
for (; V_11 < V_12 ; V_11 += V_31 , V_15 += V_31 ) {
F_40 () ;
V_32 = ( V_11 + V_36 ) & V_37 ;
V_31 = V_32 - V_11 ;
if ( V_31 > V_12 - V_11 )
V_31 = V_12 - V_11 ;
V_10 = F_1 ( V_8 -> V_20 , V_11 ) ;
if ( ! V_10 )
continue;
V_14 = F_8 ( V_8 -> V_20 , V_8 , V_15 ) ;
if ( ! V_14 )
break;
if ( F_12 ( * V_10 ) ) {
if ( V_31 == V_38 ) {
bool V_39 ;
F_41 ( V_8 -> V_25 || ! V_8 -> V_19 ,
V_8 ) ;
if ( V_16 )
F_21 ( V_8 -> V_19 ) ;
V_39 = F_42 ( V_8 , V_13 , V_11 ,
V_15 , V_12 ,
V_10 , V_14 ) ;
if ( V_16 )
F_35 ( V_8 -> V_19 ) ;
if ( V_39 ) {
V_33 = true ;
continue;
}
}
F_43 ( V_8 , V_10 , V_11 ) ;
if ( F_7 ( * V_10 ) )
continue;
F_11 ( F_12 ( * V_10 ) ) ;
}
if ( F_7 ( * V_14 ) && F_44 ( V_13 -> V_20 , V_13 ,
V_14 , V_15 ) )
break;
V_32 = ( V_15 + V_36 ) & V_37 ;
if ( V_31 > V_32 - V_15 )
V_31 = V_32 - V_15 ;
if ( V_31 > V_40 )
V_31 = V_40 ;
F_19 ( V_8 , V_10 , V_11 , V_11 + V_31 ,
V_13 , V_14 , V_15 , V_16 ) ;
V_33 = true ;
}
if ( F_45 ( V_33 ) )
F_46 ( V_8 , V_12 - V_30 , V_11 ) ;
F_47 ( V_8 -> V_20 , V_34 , V_35 ) ;
return V_30 + V_11 - V_12 ;
}
static unsigned long F_48 ( struct V_7 * V_8 ,
unsigned long V_11 , unsigned long V_41 ,
unsigned long V_42 , unsigned long V_15 , bool * V_43 )
{
struct V_1 * V_2 = V_8 -> V_20 ;
struct V_7 * V_13 ;
unsigned long V_44 = V_8 -> V_44 ;
unsigned long V_45 ;
unsigned long V_46 ;
unsigned long V_47 = 0 ;
unsigned long V_48 ;
int V_49 = 0 ;
int V_50 ;
bool V_16 ;
if ( V_2 -> V_51 >= V_52 - 3 )
return - V_53 ;
V_50 = F_49 ( V_8 , V_11 , V_11 + V_41 ,
V_54 , & V_44 ) ;
if ( V_50 )
return V_50 ;
V_45 = V_8 -> V_55 + ( ( V_11 - V_8 -> V_56 ) >> V_57 ) ;
V_13 = F_50 ( & V_8 , V_15 , V_42 , V_45 ,
& V_16 ) ;
if ( ! V_13 )
return - V_53 ;
V_46 = F_37 ( V_8 , V_11 , V_13 , V_15 , V_41 ,
V_16 ) ;
if ( V_46 < V_41 ) {
V_50 = - V_53 ;
} else if ( V_8 -> V_58 && V_8 -> V_58 -> V_59 ) {
V_50 = V_8 -> V_58 -> V_59 ( V_13 ) ;
}
if ( F_51 ( V_50 ) ) {
F_37 ( V_13 , V_15 , V_8 , V_11 , V_46 ,
true ) ;
V_8 = V_13 ;
V_41 = V_42 ;
V_11 = V_15 ;
V_15 = V_50 ;
} else {
F_52 ( V_2 , V_11 , V_11 + V_41 ,
V_15 , V_15 + V_42 ) ;
}
if ( V_44 & V_60 ) {
V_8 -> V_44 &= ~ V_60 ;
V_47 = V_8 -> V_61 - V_8 -> V_56 - V_41 ;
if ( V_11 > V_8 -> V_56 &&
V_11 + V_41 < V_8 -> V_61 )
V_49 = 1 ;
}
V_48 = V_2 -> V_48 ;
F_53 ( V_2 , V_8 -> V_44 , V_42 >> V_57 ) ;
if ( F_51 ( V_8 -> V_44 & V_62 ) )
F_54 ( V_8 ) ;
if ( F_55 ( V_2 , V_11 , V_41 ) < 0 ) {
F_56 ( V_47 >> V_57 ) ;
V_47 = 0 ;
}
V_2 -> V_48 = V_48 ;
if ( V_47 ) {
V_8 -> V_44 |= V_60 ;
if ( V_49 )
V_8 -> V_63 -> V_44 |= V_60 ;
}
if ( V_44 & V_64 ) {
V_2 -> V_65 += V_42 >> V_57 ;
* V_43 = true ;
}
return V_15 ;
}
static struct V_7 * F_57 ( unsigned long V_3 ,
unsigned long V_41 , unsigned long V_42 , unsigned long * V_66 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
struct V_7 * V_8 = F_58 ( V_2 , V_3 ) ;
unsigned long V_68 ;
if ( ! V_8 || V_8 -> V_56 > V_3 )
return F_59 ( - V_69 ) ;
if ( F_60 ( V_8 ) )
return F_59 ( - V_70 ) ;
if ( V_41 > V_8 -> V_61 - V_3 )
return F_59 ( - V_69 ) ;
if ( V_42 == V_41 )
return V_8 ;
V_68 = ( V_3 - V_8 -> V_56 ) >> V_57 ;
V_68 += V_8 -> V_55 ;
if ( V_68 + ( V_42 >> V_57 ) < V_68 )
return F_59 ( - V_70 ) ;
if ( V_8 -> V_44 & ( V_71 | V_62 ) )
return F_59 ( - V_69 ) ;
if ( V_8 -> V_44 & V_64 ) {
unsigned long V_43 , V_72 ;
V_43 = V_2 -> V_65 << V_57 ;
V_72 = F_61 ( V_73 ) ;
V_43 += V_42 - V_41 ;
if ( V_43 > V_72 && ! F_62 ( V_74 ) )
return F_59 ( - V_75 ) ;
}
if ( ! F_63 ( V_2 , V_8 -> V_44 ,
( V_42 - V_41 ) >> V_57 ) )
return F_59 ( - V_53 ) ;
if ( V_8 -> V_44 & V_60 ) {
unsigned long V_76 = ( V_42 - V_41 ) >> V_57 ;
if ( F_64 ( V_2 , V_76 ) )
return F_59 ( - V_53 ) ;
* V_66 = V_76 ;
}
return V_8 ;
}
static unsigned long F_65 ( unsigned long V_3 , unsigned long V_41 ,
unsigned long V_15 , unsigned long V_42 , bool * V_43 )
{
struct V_1 * V_2 = V_67 -> V_2 ;
struct V_7 * V_8 ;
unsigned long V_77 = - V_70 ;
unsigned long V_76 = 0 ;
unsigned long V_78 ;
if ( F_66 ( V_15 ) )
goto V_79;
if ( V_42 > V_80 || V_15 > V_80 - V_42 )
goto V_79;
if ( V_3 + V_41 > V_15 && V_15 + V_42 > V_3 )
goto V_79;
V_77 = F_55 ( V_2 , V_15 , V_42 ) ;
if ( V_77 )
goto V_79;
if ( V_41 >= V_42 ) {
V_77 = F_55 ( V_2 , V_3 + V_42 , V_41 - V_42 ) ;
if ( V_77 && V_41 != V_42 )
goto V_79;
V_41 = V_42 ;
}
V_8 = F_57 ( V_3 , V_41 , V_42 , & V_76 ) ;
if ( F_67 ( V_8 ) ) {
V_77 = F_68 ( V_8 ) ;
goto V_79;
}
V_78 = V_81 ;
if ( V_8 -> V_44 & V_82 )
V_78 |= V_83 ;
V_77 = F_69 ( V_8 -> V_25 , V_15 , V_42 , V_8 -> V_55 +
( ( V_3 - V_8 -> V_56 ) >> V_57 ) ,
V_78 ) ;
if ( F_66 ( V_77 ) )
goto V_84;
V_77 = F_48 ( V_8 , V_3 , V_41 , V_42 , V_15 , V_43 ) ;
if ( ! ( F_66 ( V_77 ) ) )
goto V_79;
V_84:
F_56 ( V_76 ) ;
V_79:
return V_77 ;
}
static int F_70 ( struct V_7 * V_8 , unsigned long V_85 )
{
unsigned long V_86 = V_8 -> V_61 + V_85 ;
if ( V_86 < V_8 -> V_61 )
return 0 ;
if ( V_8 -> V_63 && V_8 -> V_63 -> V_56 < V_86 )
return 0 ;
if ( F_69 ( NULL , V_8 -> V_56 , V_86 - V_8 -> V_56 ,
0 , V_81 ) & ~ V_87 )
return 0 ;
return 1 ;
}
