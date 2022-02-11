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
F_7 ( V_2 , V_6 ) ;
if ( F_8 ( V_6 ) )
return NULL ;
return V_6 ;
}
static T_1 * F_9 ( struct V_1 * V_2 , struct V_7 * V_8 ,
unsigned long V_3 )
{
T_2 * V_4 ;
T_3 * V_5 ;
T_1 * V_6 ;
V_4 = F_2 ( V_2 , V_3 ) ;
V_5 = F_10 ( V_2 , V_4 , V_3 ) ;
if ( ! V_5 )
return NULL ;
V_6 = F_11 ( V_2 , V_5 , V_3 ) ;
if ( ! V_6 )
return NULL ;
F_12 ( F_13 ( * V_6 ) ) ;
if ( F_14 ( * V_6 ) && F_15 ( V_2 , V_8 , V_6 , V_3 ) )
return NULL ;
return V_6 ;
}
static void F_16 ( struct V_7 * V_8 , T_1 * V_9 ,
unsigned long V_10 , unsigned long V_11 ,
struct V_7 * V_12 , T_1 * V_13 ,
unsigned long V_14 )
{
struct V_15 * V_16 = NULL ;
struct V_1 * V_2 = V_8 -> V_17 ;
T_4 * V_18 , * V_19 , V_20 ;
T_5 * V_21 , * V_22 ;
unsigned long V_23 ;
V_23 = V_10 ;
F_17 ( V_8 -> V_17 ,
V_23 , V_11 ) ;
if ( V_8 -> V_24 ) {
V_16 = V_8 -> V_24 -> V_25 ;
F_18 ( & V_16 -> V_26 ) ;
}
V_18 = F_19 ( V_2 , V_9 , V_10 , & V_21 ) ;
V_19 = F_20 ( V_13 , V_14 ) ;
V_22 = F_21 ( V_2 , V_13 ) ;
if ( V_22 != V_21 )
F_22 ( V_22 , V_27 ) ;
F_23 () ;
for (; V_10 < V_11 ; V_18 ++ , V_10 += V_28 ,
V_19 ++ , V_14 += V_28 ) {
if ( F_24 ( * V_18 ) )
continue;
V_20 = F_25 ( V_8 , V_10 , V_18 ) ;
V_20 = F_26 ( V_20 , V_12 -> V_29 , V_10 , V_14 ) ;
F_27 ( V_2 , V_14 , V_19 , V_20 ) ;
}
F_28 () ;
if ( V_22 != V_21 )
F_29 ( V_22 ) ;
F_30 ( V_19 - 1 ) ;
F_31 ( V_18 - 1 , V_21 ) ;
if ( V_16 )
F_32 ( & V_16 -> V_26 ) ;
F_33 ( V_8 -> V_17 , V_23 , V_11 ) ;
}
unsigned long F_34 ( struct V_7 * V_8 ,
unsigned long V_10 , struct V_7 * V_12 ,
unsigned long V_14 , unsigned long V_30 )
{
unsigned long V_31 , V_32 , V_11 ;
T_1 * V_9 , * V_13 ;
V_11 = V_10 + V_30 ;
F_35 ( V_8 , V_10 , V_11 ) ;
for (; V_10 < V_11 ; V_10 += V_31 , V_14 += V_31 ) {
F_36 () ;
V_32 = ( V_10 + V_33 ) & V_34 ;
if ( V_32 - 1 > V_11 )
V_32 = V_11 ;
V_31 = V_32 - V_10 ;
V_9 = F_1 ( V_8 -> V_17 , V_10 ) ;
if ( ! V_9 )
continue;
V_13 = F_9 ( V_8 -> V_17 , V_8 , V_14 ) ;
if ( ! V_13 )
break;
V_32 = ( V_14 + V_33 ) & V_34 ;
if ( V_31 > V_32 - V_14 )
V_31 = V_32 - V_14 ;
if ( V_31 > V_35 )
V_31 = V_35 ;
F_16 ( V_8 , V_9 , V_10 , V_10 + V_31 ,
V_12 , V_13 , V_14 ) ;
}
return V_30 + V_10 - V_11 ;
}
static unsigned long F_37 ( struct V_7 * V_8 ,
unsigned long V_10 , unsigned long V_36 ,
unsigned long V_37 , unsigned long V_14 )
{
struct V_1 * V_2 = V_8 -> V_17 ;
struct V_7 * V_12 ;
unsigned long V_38 = V_8 -> V_38 ;
unsigned long V_39 ;
unsigned long V_40 ;
unsigned long V_41 = 0 ;
unsigned long V_42 ;
int V_43 = 0 ;
int V_44 ;
if ( V_2 -> V_45 >= V_46 - 3 )
return - V_47 ;
V_44 = F_38 ( V_8 , V_10 , V_10 + V_36 ,
V_48 , & V_38 ) ;
if ( V_44 )
return V_44 ;
V_39 = V_8 -> V_49 + ( ( V_10 - V_8 -> V_50 ) >> V_51 ) ;
V_12 = F_39 ( & V_8 , V_14 , V_37 , V_39 ) ;
if ( ! V_12 )
return - V_47 ;
V_40 = F_34 ( V_8 , V_10 , V_12 , V_14 , V_36 ) ;
if ( V_40 < V_36 ) {
F_34 ( V_12 , V_14 , V_8 , V_10 , V_40 ) ;
V_8 = V_12 ;
V_36 = V_37 ;
V_10 = V_14 ;
V_14 = - V_47 ;
}
if ( V_38 & V_52 ) {
V_8 -> V_38 &= ~ V_52 ;
V_41 = V_8 -> V_53 - V_8 -> V_50 - V_36 ;
if ( V_10 > V_8 -> V_50 &&
V_10 + V_36 < V_8 -> V_53 )
V_43 = 1 ;
}
V_42 = V_2 -> V_42 ;
V_2 -> V_54 += V_37 >> V_51 ;
F_40 ( V_2 , V_8 -> V_38 , V_8 -> V_24 , V_37 >> V_51 ) ;
if ( F_41 ( V_2 , V_10 , V_36 ) < 0 ) {
F_42 ( V_41 >> V_51 ) ;
V_41 = 0 ;
}
V_2 -> V_42 = V_42 ;
if ( V_41 ) {
V_8 -> V_38 |= V_52 ;
if ( V_43 )
V_8 -> V_55 -> V_38 |= V_52 ;
}
if ( V_38 & V_56 ) {
V_2 -> V_57 += V_37 >> V_51 ;
if ( V_37 > V_36 )
F_43 ( V_12 , V_14 + V_36 ,
V_14 + V_37 ) ;
}
return V_14 ;
}
static struct V_7 * F_44 ( unsigned long V_3 ,
unsigned long V_36 , unsigned long V_37 , unsigned long * V_58 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_7 * V_8 = F_45 ( V_2 , V_3 ) ;
if ( ! V_8 || V_8 -> V_50 > V_3 )
goto V_60;
if ( F_46 ( V_8 ) )
goto V_61;
if ( V_36 > V_8 -> V_53 - V_3 )
goto V_60;
if ( V_37 > V_36 ) {
unsigned long V_62 ;
if ( V_8 -> V_38 & ( V_63 | V_64 ) )
goto V_60;
V_62 = ( V_3 - V_8 -> V_50 ) >> V_51 ;
V_62 += V_8 -> V_49 ;
if ( V_62 + ( V_37 >> V_51 ) < V_62 )
goto V_61;
}
if ( V_8 -> V_38 & V_56 ) {
unsigned long V_65 , V_66 ;
V_65 = V_2 -> V_57 << V_51 ;
V_66 = F_47 ( V_67 ) ;
V_65 += V_37 - V_36 ;
if ( V_65 > V_66 && ! F_48 ( V_68 ) )
goto V_69;
}
if ( ! F_49 ( V_2 , ( V_37 - V_36 ) >> V_51 ) )
goto V_70;
if ( V_8 -> V_38 & V_52 ) {
unsigned long V_71 = ( V_37 - V_36 ) >> V_51 ;
if ( F_50 ( V_71 ) )
goto V_60;
* V_58 = V_71 ;
}
return V_8 ;
V_60:
return F_51 ( - V_72 ) ;
V_61:
return F_51 ( - V_73 ) ;
V_70:
return F_51 ( - V_47 ) ;
V_69:
return F_51 ( - V_74 ) ;
}
static unsigned long F_52 ( unsigned long V_3 ,
unsigned long V_36 , unsigned long V_14 ,
unsigned long V_37 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_7 * V_8 ;
unsigned long V_75 = - V_73 ;
unsigned long V_71 = 0 ;
unsigned long V_76 ;
if ( V_14 & ~ V_77 )
goto V_78;
if ( V_37 > V_79 || V_14 > V_79 - V_37 )
goto V_78;
if ( ( V_14 <= V_3 ) && ( V_14 + V_37 ) > V_3 )
goto V_78;
if ( ( V_3 <= V_14 ) && ( V_3 + V_36 ) > V_14 )
goto V_78;
V_75 = F_53 ( NULL , 0 , 0 , 0 , V_14 , 1 ) ;
if ( V_75 )
goto V_78;
V_75 = F_41 ( V_2 , V_14 , V_37 ) ;
if ( V_75 )
goto V_78;
if ( V_36 >= V_37 ) {
V_75 = F_41 ( V_2 , V_3 + V_37 , V_36 - V_37 ) ;
if ( V_75 && V_36 != V_37 )
goto V_78;
V_36 = V_37 ;
}
V_8 = F_44 ( V_3 , V_36 , V_37 , & V_71 ) ;
if ( F_54 ( V_8 ) ) {
V_75 = F_55 ( V_8 ) ;
goto V_78;
}
V_76 = V_80 ;
if ( V_8 -> V_38 & V_81 )
V_76 |= V_82 ;
V_75 = F_56 ( V_8 -> V_24 , V_14 , V_37 , V_8 -> V_49 +
( ( V_3 - V_8 -> V_50 ) >> V_51 ) ,
V_76 ) ;
if ( V_75 & ~ V_77 )
goto V_83;
V_75 = F_37 ( V_8 , V_3 , V_36 , V_37 , V_14 ) ;
if ( ! ( V_75 & ~ V_77 ) )
goto V_78;
V_83:
F_42 ( V_71 ) ;
V_78:
return V_75 ;
}
static int F_57 ( struct V_7 * V_8 , unsigned long V_84 )
{
unsigned long V_85 = V_8 -> V_53 + V_84 ;
if ( V_85 < V_8 -> V_53 )
return 0 ;
if ( V_8 -> V_55 && V_8 -> V_55 -> V_50 < V_85 )
return 0 ;
if ( F_56 ( NULL , V_8 -> V_50 , V_85 - V_8 -> V_50 ,
0 , V_80 ) & ~ V_77 )
return 0 ;
return 1 ;
}
unsigned long F_58 ( unsigned long V_3 ,
unsigned long V_36 , unsigned long V_37 ,
unsigned long V_86 , unsigned long V_14 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_7 * V_8 ;
unsigned long V_75 = - V_73 ;
unsigned long V_71 = 0 ;
if ( V_86 & ~ ( V_87 | V_88 ) )
goto V_78;
if ( V_3 & ~ V_77 )
goto V_78;
V_36 = F_59 ( V_36 ) ;
V_37 = F_59 ( V_37 ) ;
if ( ! V_37 )
goto V_78;
if ( V_86 & V_87 ) {
if ( V_86 & V_88 )
V_75 = F_52 ( V_3 , V_36 , V_14 , V_37 ) ;
goto V_78;
}
if ( V_36 >= V_37 ) {
V_75 = F_41 ( V_2 , V_3 + V_37 , V_36 - V_37 ) ;
if ( V_75 && V_36 != V_37 )
goto V_78;
V_75 = V_3 ;
goto V_78;
}
V_8 = F_44 ( V_3 , V_36 , V_37 , & V_71 ) ;
if ( F_54 ( V_8 ) ) {
V_75 = F_55 ( V_8 ) ;
goto V_78;
}
if ( V_36 == V_8 -> V_53 - V_3 ) {
if ( F_57 ( V_8 , V_37 - V_36 ) ) {
int V_89 = ( V_37 - V_36 ) >> V_51 ;
if ( F_60 ( V_8 , V_8 -> V_50 , V_3 + V_37 ,
V_8 -> V_49 , NULL ) ) {
V_75 = - V_47 ;
goto V_78;
}
V_2 -> V_54 += V_89 ;
F_40 ( V_2 , V_8 -> V_38 , V_8 -> V_24 , V_89 ) ;
if ( V_8 -> V_38 & V_56 ) {
V_2 -> V_57 += V_89 ;
F_43 ( V_8 , V_3 + V_36 ,
V_3 + V_37 ) ;
}
V_75 = V_3 ;
goto V_78;
}
}
V_75 = - V_47 ;
if ( V_86 & V_88 ) {
unsigned long V_76 = 0 ;
if ( V_8 -> V_38 & V_81 )
V_76 |= V_82 ;
V_14 = F_56 ( V_8 -> V_24 , 0 , V_37 ,
V_8 -> V_49 +
( ( V_3 - V_8 -> V_50 ) >> V_51 ) ,
V_76 ) ;
if ( V_14 & ~ V_77 ) {
V_75 = V_14 ;
goto V_78;
}
V_75 = F_53 ( NULL , 0 , 0 , 0 , V_14 , 1 ) ;
if ( V_75 )
goto V_78;
V_75 = F_37 ( V_8 , V_3 , V_36 , V_37 , V_14 ) ;
}
V_78:
if ( V_75 & ~ V_77 )
F_42 ( V_71 ) ;
return V_75 ;
}
