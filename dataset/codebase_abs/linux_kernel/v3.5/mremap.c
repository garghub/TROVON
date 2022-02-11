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
static void F_13 ( struct V_7 * V_8 , T_1 * V_9 ,
unsigned long V_10 , unsigned long V_11 ,
struct V_7 * V_12 , T_1 * V_13 ,
unsigned long V_14 )
{
struct V_15 * V_16 = NULL ;
struct V_1 * V_2 = V_8 -> V_17 ;
T_4 * V_18 , * V_19 , V_20 ;
T_5 * V_21 , * V_22 ;
if ( V_8 -> V_23 ) {
V_16 = V_8 -> V_23 -> V_24 ;
F_14 ( & V_16 -> V_25 ) ;
}
V_18 = F_15 ( V_2 , V_9 , V_10 , & V_21 ) ;
V_19 = F_16 ( V_13 , V_14 ) ;
V_22 = F_17 ( V_2 , V_13 ) ;
if ( V_22 != V_21 )
F_18 ( V_22 , V_26 ) ;
F_19 () ;
for (; V_10 < V_11 ; V_18 ++ , V_10 += V_27 ,
V_19 ++ , V_14 += V_27 ) {
if ( F_20 ( * V_18 ) )
continue;
V_20 = F_21 ( V_2 , V_10 , V_18 ) ;
V_20 = F_22 ( V_20 , V_12 -> V_28 , V_10 , V_14 ) ;
F_23 ( V_2 , V_14 , V_19 , V_20 ) ;
}
F_24 () ;
if ( V_22 != V_21 )
F_25 ( V_22 ) ;
F_26 ( V_19 - 1 ) ;
F_27 ( V_18 - 1 , V_21 ) ;
if ( V_16 )
F_28 ( & V_16 -> V_25 ) ;
}
unsigned long F_29 ( struct V_7 * V_8 ,
unsigned long V_10 , struct V_7 * V_12 ,
unsigned long V_14 , unsigned long V_29 )
{
unsigned long V_30 , V_31 , V_11 ;
T_1 * V_9 , * V_13 ;
bool V_32 = false ;
V_11 = V_10 + V_29 ;
F_30 ( V_8 , V_10 , V_11 ) ;
F_31 ( V_8 -> V_17 , V_10 , V_11 ) ;
for (; V_10 < V_11 ; V_10 += V_30 , V_14 += V_30 ) {
F_32 () ;
V_31 = ( V_10 + V_33 ) & V_34 ;
V_30 = V_31 - V_10 ;
if ( V_30 > V_11 - V_10 )
V_30 = V_11 - V_10 ;
V_9 = F_1 ( V_8 -> V_17 , V_10 ) ;
if ( ! V_9 )
continue;
V_13 = F_8 ( V_8 -> V_17 , V_8 , V_14 ) ;
if ( ! V_13 )
break;
if ( F_12 ( * V_9 ) ) {
int V_35 = 0 ;
if ( V_30 == V_36 )
V_35 = F_33 ( V_8 , V_12 , V_10 ,
V_14 , V_11 ,
V_9 , V_13 ) ;
if ( V_35 > 0 ) {
V_32 = true ;
continue;
} else if ( ! V_35 ) {
F_34 ( V_8 -> V_17 , V_9 ) ;
}
F_11 ( F_12 ( * V_9 ) ) ;
}
if ( F_7 ( * V_13 ) && F_35 ( V_12 -> V_17 , V_12 ,
V_13 , V_14 ) )
break;
V_31 = ( V_14 + V_33 ) & V_34 ;
if ( V_30 > V_31 - V_14 )
V_30 = V_31 - V_14 ;
if ( V_30 > V_37 )
V_30 = V_37 ;
F_13 ( V_8 , V_9 , V_10 , V_10 + V_30 ,
V_12 , V_13 , V_14 ) ;
V_32 = true ;
}
if ( F_36 ( V_32 ) )
F_37 ( V_8 , V_11 - V_29 , V_10 ) ;
F_38 ( V_8 -> V_17 , V_11 - V_29 , V_11 ) ;
return V_29 + V_10 - V_11 ;
}
static unsigned long F_39 ( struct V_7 * V_8 ,
unsigned long V_10 , unsigned long V_38 ,
unsigned long V_39 , unsigned long V_14 )
{
struct V_1 * V_2 = V_8 -> V_17 ;
struct V_7 * V_12 ;
unsigned long V_40 = V_8 -> V_40 ;
unsigned long V_41 ;
unsigned long V_42 ;
unsigned long V_43 = 0 ;
unsigned long V_44 ;
int V_45 = 0 ;
int V_35 ;
if ( V_2 -> V_46 >= V_47 - 3 )
return - V_48 ;
V_35 = F_40 ( V_8 , V_10 , V_10 + V_38 ,
V_49 , & V_40 ) ;
if ( V_35 )
return V_35 ;
V_41 = V_8 -> V_50 + ( ( V_10 - V_8 -> V_51 ) >> V_52 ) ;
V_12 = F_41 ( & V_8 , V_14 , V_39 , V_41 ) ;
if ( ! V_12 )
return - V_48 ;
V_42 = F_29 ( V_8 , V_10 , V_12 , V_14 , V_38 ) ;
if ( V_42 < V_38 ) {
F_42 ( V_8 ) ;
F_29 ( V_12 , V_14 , V_8 , V_10 , V_42 ) ;
V_8 = V_12 ;
V_38 = V_39 ;
V_10 = V_14 ;
V_14 = - V_48 ;
}
if ( V_40 & V_53 ) {
V_8 -> V_40 &= ~ V_53 ;
V_43 = V_8 -> V_54 - V_8 -> V_51 - V_38 ;
if ( V_10 > V_8 -> V_51 &&
V_10 + V_38 < V_8 -> V_54 )
V_45 = 1 ;
}
V_44 = V_2 -> V_44 ;
V_2 -> V_55 += V_39 >> V_52 ;
F_43 ( V_2 , V_8 -> V_40 , V_8 -> V_23 , V_39 >> V_52 ) ;
if ( F_44 ( V_2 , V_10 , V_38 ) < 0 ) {
F_45 ( V_43 >> V_52 ) ;
V_43 = 0 ;
}
V_2 -> V_44 = V_44 ;
if ( V_43 ) {
V_8 -> V_40 |= V_53 ;
if ( V_45 )
V_8 -> V_56 -> V_40 |= V_53 ;
}
if ( V_40 & V_57 ) {
V_2 -> V_58 += V_39 >> V_52 ;
if ( V_39 > V_38 )
F_46 ( V_12 , V_14 + V_38 ,
V_14 + V_39 ) ;
}
return V_14 ;
}
static struct V_7 * F_47 ( unsigned long V_3 ,
unsigned long V_38 , unsigned long V_39 , unsigned long * V_59 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_7 * V_8 = F_48 ( V_2 , V_3 ) ;
if ( ! V_8 || V_8 -> V_51 > V_3 )
goto V_61;
if ( F_49 ( V_8 ) )
goto V_62;
if ( V_38 > V_8 -> V_54 - V_3 )
goto V_61;
if ( V_39 > V_38 ) {
unsigned long V_63 ;
if ( V_8 -> V_40 & ( V_64 | V_65 ) )
goto V_61;
V_63 = ( V_3 - V_8 -> V_51 ) >> V_52 ;
V_63 += V_8 -> V_50 ;
if ( V_63 + ( V_39 >> V_52 ) < V_63 )
goto V_62;
}
if ( V_8 -> V_40 & V_57 ) {
unsigned long V_66 , V_67 ;
V_66 = V_2 -> V_58 << V_52 ;
V_67 = F_50 ( V_68 ) ;
V_66 += V_39 - V_38 ;
if ( V_66 > V_67 && ! F_51 ( V_69 ) )
goto V_70;
}
if ( ! F_52 ( V_2 , ( V_39 - V_38 ) >> V_52 ) )
goto V_71;
if ( V_8 -> V_40 & V_53 ) {
unsigned long V_72 = ( V_39 - V_38 ) >> V_52 ;
if ( F_53 ( V_2 , V_72 ) )
goto V_61;
* V_59 = V_72 ;
}
return V_8 ;
V_61:
return F_54 ( - V_73 ) ;
V_62:
return F_54 ( - V_74 ) ;
V_71:
return F_54 ( - V_48 ) ;
V_70:
return F_54 ( - V_75 ) ;
}
static unsigned long F_55 ( unsigned long V_3 ,
unsigned long V_38 , unsigned long V_14 ,
unsigned long V_39 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_7 * V_8 ;
unsigned long V_76 = - V_74 ;
unsigned long V_72 = 0 ;
unsigned long V_77 ;
if ( V_14 & ~ V_78 )
goto V_79;
if ( V_39 > V_80 || V_14 > V_80 - V_39 )
goto V_79;
if ( ( V_14 <= V_3 ) && ( V_14 + V_39 ) > V_3 )
goto V_79;
if ( ( V_3 <= V_14 ) && ( V_3 + V_38 ) > V_14 )
goto V_79;
V_76 = F_44 ( V_2 , V_14 , V_39 ) ;
if ( V_76 )
goto V_79;
if ( V_38 >= V_39 ) {
V_76 = F_44 ( V_2 , V_3 + V_39 , V_38 - V_39 ) ;
if ( V_76 && V_38 != V_39 )
goto V_79;
V_38 = V_39 ;
}
V_8 = F_47 ( V_3 , V_38 , V_39 , & V_72 ) ;
if ( F_56 ( V_8 ) ) {
V_76 = F_57 ( V_8 ) ;
goto V_79;
}
V_77 = V_81 ;
if ( V_8 -> V_40 & V_82 )
V_77 |= V_83 ;
V_76 = F_58 ( V_8 -> V_23 , V_14 , V_39 , V_8 -> V_50 +
( ( V_3 - V_8 -> V_51 ) >> V_52 ) ,
V_77 ) ;
if ( V_76 & ~ V_78 )
goto V_84;
V_76 = F_39 ( V_8 , V_3 , V_38 , V_39 , V_14 ) ;
if ( ! ( V_76 & ~ V_78 ) )
goto V_79;
V_84:
F_45 ( V_72 ) ;
V_79:
return V_76 ;
}
static int F_59 ( struct V_7 * V_8 , unsigned long V_85 )
{
unsigned long V_86 = V_8 -> V_54 + V_85 ;
if ( V_86 < V_8 -> V_54 )
return 0 ;
if ( V_8 -> V_56 && V_8 -> V_56 -> V_51 < V_86 )
return 0 ;
if ( F_58 ( NULL , V_8 -> V_51 , V_86 - V_8 -> V_51 ,
0 , V_81 ) & ~ V_78 )
return 0 ;
return 1 ;
}
