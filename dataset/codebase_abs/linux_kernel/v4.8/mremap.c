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
static void F_13 ( struct V_7 * V_8 )
{
if ( V_8 -> V_9 )
F_14 ( V_8 -> V_9 -> V_10 ) ;
if ( V_8 -> V_11 )
F_15 ( V_8 -> V_11 ) ;
}
static void F_16 ( struct V_7 * V_8 )
{
if ( V_8 -> V_11 )
F_17 ( V_8 -> V_11 ) ;
if ( V_8 -> V_9 )
F_18 ( V_8 -> V_9 -> V_10 ) ;
}
static T_4 F_19 ( T_4 V_12 )
{
#ifdef F_20
if ( F_21 ( V_12 ) )
V_12 = F_22 ( V_12 ) ;
else if ( F_23 ( V_12 ) )
V_12 = F_24 ( V_12 ) ;
#endif
return V_12 ;
}
static void F_25 ( struct V_7 * V_8 , T_1 * V_13 ,
unsigned long V_14 , unsigned long V_15 ,
struct V_7 * V_16 , T_1 * V_17 ,
unsigned long V_18 , bool V_19 )
{
struct V_1 * V_2 = V_8 -> V_20 ;
T_4 * V_21 , * V_22 , V_12 ;
T_5 * V_23 , * V_24 ;
if ( V_19 )
F_13 ( V_8 ) ;
V_21 = F_26 ( V_2 , V_13 , V_14 , & V_23 ) ;
V_22 = F_27 ( V_17 , V_18 ) ;
V_24 = F_28 ( V_2 , V_17 ) ;
if ( V_24 != V_23 )
F_29 ( V_24 , V_25 ) ;
F_30 () ;
for (; V_14 < V_15 ; V_21 ++ , V_14 += V_26 ,
V_22 ++ , V_18 += V_26 ) {
if ( F_31 ( * V_21 ) )
continue;
V_12 = F_32 ( V_2 , V_14 , V_21 ) ;
V_12 = F_33 ( V_12 , V_16 -> V_27 , V_14 , V_18 ) ;
V_12 = F_19 ( V_12 ) ;
F_34 ( V_2 , V_18 , V_22 , V_12 ) ;
}
F_35 () ;
if ( V_24 != V_23 )
F_36 ( V_24 ) ;
F_37 ( V_22 - 1 ) ;
F_38 ( V_21 - 1 , V_23 ) ;
if ( V_19 )
F_16 ( V_8 ) ;
}
unsigned long F_39 ( struct V_7 * V_8 ,
unsigned long V_14 , struct V_7 * V_16 ,
unsigned long V_18 , unsigned long V_28 ,
bool V_19 )
{
unsigned long V_29 , V_30 , V_15 ;
T_1 * V_13 , * V_17 ;
bool V_31 = false ;
unsigned long V_32 ;
unsigned long V_33 ;
V_15 = V_14 + V_28 ;
F_40 ( V_8 , V_14 , V_15 ) ;
V_32 = V_14 ;
V_33 = V_15 ;
F_41 ( V_8 -> V_20 , V_32 , V_33 ) ;
for (; V_14 < V_15 ; V_14 += V_29 , V_18 += V_29 ) {
F_42 () ;
V_30 = ( V_14 + V_34 ) & V_35 ;
V_29 = V_30 - V_14 ;
if ( V_29 > V_15 - V_14 )
V_29 = V_15 - V_14 ;
V_13 = F_1 ( V_8 -> V_20 , V_14 ) ;
if ( ! V_13 )
continue;
V_17 = F_8 ( V_8 -> V_20 , V_8 , V_18 ) ;
if ( ! V_17 )
break;
if ( F_12 ( * V_13 ) ) {
if ( V_29 == V_36 ) {
bool V_37 ;
if ( V_19 )
F_13 ( V_8 ) ;
V_37 = F_43 ( V_8 , V_14 , V_18 ,
V_15 , V_13 , V_17 ) ;
if ( V_19 )
F_16 ( V_8 ) ;
if ( V_37 ) {
V_31 = true ;
continue;
}
}
F_44 ( V_8 , V_13 , V_14 ) ;
if ( F_45 ( V_13 ) )
continue;
}
if ( F_46 ( V_16 -> V_20 , V_17 , V_18 ) )
break;
V_30 = ( V_18 + V_34 ) & V_35 ;
if ( V_29 > V_30 - V_18 )
V_29 = V_30 - V_18 ;
if ( V_29 > V_38 )
V_29 = V_38 ;
F_25 ( V_8 , V_13 , V_14 , V_14 + V_29 ,
V_16 , V_17 , V_18 , V_19 ) ;
V_31 = true ;
}
if ( F_47 ( V_31 ) )
F_48 ( V_8 , V_15 - V_28 , V_14 ) ;
F_49 ( V_8 -> V_20 , V_32 , V_33 ) ;
return V_28 + V_14 - V_15 ;
}
static unsigned long F_50 ( struct V_7 * V_8 ,
unsigned long V_14 , unsigned long V_39 ,
unsigned long V_40 , unsigned long V_18 , bool * V_41 )
{
struct V_1 * V_2 = V_8 -> V_20 ;
struct V_7 * V_16 ;
unsigned long V_42 = V_8 -> V_42 ;
unsigned long V_43 ;
unsigned long V_44 ;
unsigned long V_45 = 0 ;
unsigned long V_46 ;
int V_47 = 0 ;
int V_48 ;
bool V_19 ;
if ( V_2 -> V_49 >= V_50 - 3 )
return - V_51 ;
V_48 = F_51 ( V_8 , V_14 , V_14 + V_39 ,
V_52 , & V_42 ) ;
if ( V_48 )
return V_48 ;
V_43 = V_8 -> V_53 + ( ( V_14 - V_8 -> V_54 ) >> V_55 ) ;
V_16 = F_52 ( & V_8 , V_18 , V_40 , V_43 ,
& V_19 ) ;
if ( ! V_16 )
return - V_51 ;
V_44 = F_39 ( V_8 , V_14 , V_16 , V_18 , V_39 ,
V_19 ) ;
if ( V_44 < V_39 ) {
V_48 = - V_51 ;
} else if ( V_8 -> V_56 && V_8 -> V_56 -> V_57 ) {
V_48 = V_8 -> V_56 -> V_57 ( V_16 ) ;
}
if ( F_53 ( V_48 ) ) {
F_39 ( V_16 , V_18 , V_8 , V_14 , V_44 ,
true ) ;
V_8 = V_16 ;
V_39 = V_40 ;
V_14 = V_18 ;
V_18 = V_48 ;
} else {
F_54 ( V_2 , V_14 , V_14 + V_39 ,
V_18 , V_18 + V_40 ) ;
}
if ( V_42 & V_58 ) {
V_8 -> V_42 &= ~ V_58 ;
V_45 = V_8 -> V_59 - V_8 -> V_54 - V_39 ;
if ( V_14 > V_8 -> V_54 &&
V_14 + V_39 < V_8 -> V_59 )
V_47 = 1 ;
}
V_46 = V_2 -> V_46 ;
F_55 ( V_2 , V_8 -> V_42 , V_40 >> V_55 ) ;
if ( F_53 ( V_8 -> V_42 & V_60 ) )
F_56 ( V_8 ) ;
if ( F_57 ( V_2 , V_14 , V_39 ) < 0 ) {
F_58 ( V_45 >> V_55 ) ;
V_45 = 0 ;
}
V_2 -> V_46 = V_46 ;
if ( V_45 ) {
V_8 -> V_42 |= V_58 ;
if ( V_47 )
V_8 -> V_61 -> V_42 |= V_58 ;
}
if ( V_42 & V_62 ) {
V_2 -> V_63 += V_40 >> V_55 ;
* V_41 = true ;
}
return V_18 ;
}
static struct V_7 * F_59 ( unsigned long V_3 ,
unsigned long V_39 , unsigned long V_40 , unsigned long * V_64 )
{
struct V_1 * V_2 = V_65 -> V_2 ;
struct V_7 * V_8 = F_60 ( V_2 , V_3 ) ;
unsigned long V_66 ;
if ( ! V_8 || V_8 -> V_54 > V_3 )
return F_61 ( - V_67 ) ;
if ( F_62 ( V_8 ) )
return F_61 ( - V_68 ) ;
if ( V_39 > V_8 -> V_59 - V_3 )
return F_61 ( - V_67 ) ;
if ( V_40 == V_39 )
return V_8 ;
V_66 = ( V_3 - V_8 -> V_54 ) >> V_55 ;
V_66 += V_8 -> V_53 ;
if ( V_66 + ( V_40 >> V_55 ) < V_66 )
return F_61 ( - V_68 ) ;
if ( V_8 -> V_42 & ( V_69 | V_60 ) )
return F_61 ( - V_67 ) ;
if ( V_8 -> V_42 & V_62 ) {
unsigned long V_41 , V_70 ;
V_41 = V_2 -> V_63 << V_55 ;
V_70 = F_63 ( V_71 ) ;
V_41 += V_40 - V_39 ;
if ( V_41 > V_70 && ! F_64 ( V_72 ) )
return F_61 ( - V_73 ) ;
}
if ( ! F_65 ( V_2 , V_8 -> V_42 ,
( V_40 - V_39 ) >> V_55 ) )
return F_61 ( - V_51 ) ;
if ( V_8 -> V_42 & V_58 ) {
unsigned long V_74 = ( V_40 - V_39 ) >> V_55 ;
if ( F_66 ( V_2 , V_74 ) )
return F_61 ( - V_51 ) ;
* V_64 = V_74 ;
}
return V_8 ;
}
static unsigned long F_67 ( unsigned long V_3 , unsigned long V_39 ,
unsigned long V_18 , unsigned long V_40 , bool * V_41 )
{
struct V_1 * V_2 = V_65 -> V_2 ;
struct V_7 * V_8 ;
unsigned long V_75 = - V_68 ;
unsigned long V_74 = 0 ;
unsigned long V_76 ;
if ( F_68 ( V_18 ) )
goto V_77;
if ( V_40 > V_78 || V_18 > V_78 - V_40 )
goto V_77;
if ( V_3 + V_39 > V_18 && V_18 + V_40 > V_3 )
goto V_77;
V_75 = F_57 ( V_2 , V_18 , V_40 ) ;
if ( V_75 )
goto V_77;
if ( V_39 >= V_40 ) {
V_75 = F_57 ( V_2 , V_3 + V_40 , V_39 - V_40 ) ;
if ( V_75 && V_39 != V_40 )
goto V_77;
V_39 = V_40 ;
}
V_8 = F_59 ( V_3 , V_39 , V_40 , & V_74 ) ;
if ( F_69 ( V_8 ) ) {
V_75 = F_70 ( V_8 ) ;
goto V_77;
}
V_76 = V_79 ;
if ( V_8 -> V_42 & V_80 )
V_76 |= V_81 ;
V_75 = F_71 ( V_8 -> V_9 , V_18 , V_40 , V_8 -> V_53 +
( ( V_3 - V_8 -> V_54 ) >> V_55 ) ,
V_76 ) ;
if ( F_68 ( V_75 ) )
goto V_82;
V_75 = F_50 ( V_8 , V_3 , V_39 , V_40 , V_18 , V_41 ) ;
if ( ! ( F_68 ( V_75 ) ) )
goto V_77;
V_82:
F_58 ( V_74 ) ;
V_77:
return V_75 ;
}
static int F_72 ( struct V_7 * V_8 , unsigned long V_83 )
{
unsigned long V_84 = V_8 -> V_59 + V_83 ;
if ( V_84 < V_8 -> V_59 )
return 0 ;
if ( V_8 -> V_61 && V_8 -> V_61 -> V_54 < V_84 )
return 0 ;
if ( F_71 ( NULL , V_8 -> V_54 , V_84 - V_8 -> V_54 ,
0 , V_79 ) & ~ V_85 )
return 0 ;
return 1 ;
}
