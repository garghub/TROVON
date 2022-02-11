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
unsigned long V_18 , bool V_19 , bool * V_20 )
{
struct V_1 * V_2 = V_8 -> V_21 ;
T_4 * V_22 , * V_23 , V_12 ;
T_5 * V_24 , * V_25 ;
bool V_26 = false ;
unsigned long V_27 = V_15 - V_14 ;
if ( V_19 )
F_13 ( V_8 ) ;
V_22 = F_26 ( V_2 , V_13 , V_14 , & V_24 ) ;
V_23 = F_27 ( V_17 , V_18 ) ;
V_25 = F_28 ( V_2 , V_17 ) ;
if ( V_25 != V_24 )
F_29 ( V_25 , V_28 ) ;
F_30 () ;
for (; V_14 < V_15 ; V_22 ++ , V_14 += V_29 ,
V_23 ++ , V_18 += V_29 ) {
if ( F_31 ( * V_22 ) )
continue;
V_12 = F_32 ( V_2 , V_14 , V_22 ) ;
if ( F_21 ( V_12 ) && F_33 ( V_12 ) )
V_26 = true ;
V_12 = F_34 ( V_12 , V_16 -> V_30 , V_14 , V_18 ) ;
V_12 = F_19 ( V_12 ) ;
F_35 ( V_2 , V_18 , V_23 , V_12 ) ;
}
F_36 () ;
if ( V_25 != V_24 )
F_37 ( V_25 ) ;
F_38 ( V_23 - 1 ) ;
if ( V_26 )
F_39 ( V_8 , V_15 - V_27 , V_15 ) ;
else
* V_20 = true ;
F_40 ( V_22 - 1 , V_24 ) ;
if ( V_19 )
F_16 ( V_8 ) ;
}
unsigned long F_41 ( struct V_7 * V_8 ,
unsigned long V_14 , struct V_7 * V_16 ,
unsigned long V_18 , unsigned long V_27 ,
bool V_19 )
{
unsigned long V_31 , V_32 , V_15 ;
T_1 * V_13 , * V_17 ;
bool V_20 = false ;
unsigned long V_33 ;
unsigned long V_34 ;
V_15 = V_14 + V_27 ;
F_42 ( V_8 , V_14 , V_15 ) ;
V_33 = V_14 ;
V_34 = V_15 ;
F_43 ( V_8 -> V_21 , V_33 , V_34 ) ;
for (; V_14 < V_15 ; V_14 += V_31 , V_18 += V_31 ) {
F_44 () ;
V_32 = ( V_14 + V_35 ) & V_36 ;
V_31 = V_32 - V_14 ;
if ( V_31 > V_15 - V_14 )
V_31 = V_15 - V_14 ;
V_13 = F_1 ( V_8 -> V_21 , V_14 ) ;
if ( ! V_13 )
continue;
V_17 = F_8 ( V_8 -> V_21 , V_8 , V_18 ) ;
if ( ! V_17 )
break;
if ( F_12 ( * V_13 ) ) {
if ( V_31 == V_37 ) {
bool V_38 ;
if ( V_19 )
F_13 ( V_8 ) ;
V_38 = F_45 ( V_8 , V_14 , V_18 ,
V_15 , V_13 , V_17 ,
& V_20 ) ;
if ( V_19 )
F_16 ( V_8 ) ;
if ( V_38 )
continue;
}
F_46 ( V_8 , V_13 , V_14 ) ;
if ( F_47 ( V_13 ) )
continue;
}
if ( F_48 ( V_16 -> V_21 , V_17 , V_18 ) )
break;
V_32 = ( V_18 + V_35 ) & V_36 ;
if ( V_31 > V_32 - V_18 )
V_31 = V_32 - V_18 ;
if ( V_31 > V_39 )
V_31 = V_39 ;
F_25 ( V_8 , V_13 , V_14 , V_14 + V_31 , V_16 ,
V_17 , V_18 , V_19 , & V_20 ) ;
}
if ( V_20 )
F_39 ( V_8 , V_15 - V_27 , V_14 ) ;
F_49 ( V_8 -> V_21 , V_33 , V_34 ) ;
return V_27 + V_14 - V_15 ;
}
static unsigned long F_50 ( struct V_7 * V_8 ,
unsigned long V_14 , unsigned long V_40 ,
unsigned long V_41 , unsigned long V_18 , bool * V_42 )
{
struct V_1 * V_2 = V_8 -> V_21 ;
struct V_7 * V_16 ;
unsigned long V_43 = V_8 -> V_43 ;
unsigned long V_44 ;
unsigned long V_45 ;
unsigned long V_46 = 0 ;
unsigned long V_47 ;
int V_48 = 0 ;
int V_49 ;
bool V_19 ;
if ( V_2 -> V_50 >= V_51 - 3 )
return - V_52 ;
V_49 = F_51 ( V_8 , V_14 , V_14 + V_40 ,
V_53 , & V_43 ) ;
if ( V_49 )
return V_49 ;
V_44 = V_8 -> V_54 + ( ( V_14 - V_8 -> V_55 ) >> V_56 ) ;
V_16 = F_52 ( & V_8 , V_18 , V_41 , V_44 ,
& V_19 ) ;
if ( ! V_16 )
return - V_52 ;
V_45 = F_41 ( V_8 , V_14 , V_16 , V_18 , V_40 ,
V_19 ) ;
if ( V_45 < V_40 ) {
V_49 = - V_52 ;
} else if ( V_8 -> V_57 && V_8 -> V_57 -> V_58 ) {
V_49 = V_8 -> V_57 -> V_58 ( V_16 ) ;
}
if ( F_53 ( V_49 ) ) {
F_41 ( V_16 , V_18 , V_8 , V_14 , V_45 ,
true ) ;
V_8 = V_16 ;
V_40 = V_41 ;
V_14 = V_18 ;
V_18 = V_49 ;
} else {
F_54 ( V_2 , V_14 , V_14 + V_40 ,
V_18 , V_18 + V_41 ) ;
}
if ( V_43 & V_59 ) {
V_8 -> V_43 &= ~ V_59 ;
V_46 = V_8 -> V_60 - V_8 -> V_55 - V_40 ;
if ( V_14 > V_8 -> V_55 &&
V_14 + V_40 < V_8 -> V_60 )
V_48 = 1 ;
}
V_47 = V_2 -> V_47 ;
F_55 ( V_2 , V_8 -> V_43 , V_41 >> V_56 ) ;
if ( F_53 ( V_8 -> V_43 & V_61 ) )
F_56 ( V_8 ) ;
if ( F_57 ( V_2 , V_14 , V_40 ) < 0 ) {
F_58 ( V_46 >> V_56 ) ;
V_46 = 0 ;
}
V_2 -> V_47 = V_47 ;
if ( V_46 ) {
V_8 -> V_43 |= V_59 ;
if ( V_48 )
V_8 -> V_62 -> V_43 |= V_59 ;
}
if ( V_43 & V_63 ) {
V_2 -> V_64 += V_41 >> V_56 ;
* V_42 = true ;
}
return V_18 ;
}
static struct V_7 * F_59 ( unsigned long V_3 ,
unsigned long V_40 , unsigned long V_41 , unsigned long * V_65 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
struct V_7 * V_8 = F_60 ( V_2 , V_3 ) ;
unsigned long V_67 ;
if ( ! V_8 || V_8 -> V_55 > V_3 )
return F_61 ( - V_68 ) ;
if ( F_62 ( V_8 ) )
return F_61 ( - V_69 ) ;
if ( V_40 > V_8 -> V_60 - V_3 )
return F_61 ( - V_68 ) ;
if ( V_41 == V_40 )
return V_8 ;
V_67 = ( V_3 - V_8 -> V_55 ) >> V_56 ;
V_67 += V_8 -> V_54 ;
if ( V_67 + ( V_41 >> V_56 ) < V_67 )
return F_61 ( - V_69 ) ;
if ( V_8 -> V_43 & ( V_70 | V_61 ) )
return F_61 ( - V_68 ) ;
if ( V_8 -> V_43 & V_63 ) {
unsigned long V_42 , V_71 ;
V_42 = V_2 -> V_64 << V_56 ;
V_71 = F_63 ( V_72 ) ;
V_42 += V_41 - V_40 ;
if ( V_42 > V_71 && ! F_64 ( V_73 ) )
return F_61 ( - V_74 ) ;
}
if ( ! F_65 ( V_2 , V_8 -> V_43 ,
( V_41 - V_40 ) >> V_56 ) )
return F_61 ( - V_52 ) ;
if ( V_8 -> V_43 & V_59 ) {
unsigned long V_75 = ( V_41 - V_40 ) >> V_56 ;
if ( F_66 ( V_2 , V_75 ) )
return F_61 ( - V_52 ) ;
* V_65 = V_75 ;
}
return V_8 ;
}
static unsigned long F_67 ( unsigned long V_3 , unsigned long V_40 ,
unsigned long V_18 , unsigned long V_41 , bool * V_42 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
struct V_7 * V_8 ;
unsigned long V_76 = - V_69 ;
unsigned long V_75 = 0 ;
unsigned long V_77 ;
if ( F_68 ( V_18 ) )
goto V_78;
if ( V_41 > V_79 || V_18 > V_79 - V_41 )
goto V_78;
if ( V_3 + V_40 > V_18 && V_18 + V_41 > V_3 )
goto V_78;
V_76 = F_57 ( V_2 , V_18 , V_41 ) ;
if ( V_76 )
goto V_78;
if ( V_40 >= V_41 ) {
V_76 = F_57 ( V_2 , V_3 + V_41 , V_40 - V_41 ) ;
if ( V_76 && V_40 != V_41 )
goto V_78;
V_40 = V_41 ;
}
V_8 = F_59 ( V_3 , V_40 , V_41 , & V_75 ) ;
if ( F_69 ( V_8 ) ) {
V_76 = F_70 ( V_8 ) ;
goto V_78;
}
V_77 = V_80 ;
if ( V_8 -> V_43 & V_81 )
V_77 |= V_82 ;
V_76 = F_71 ( V_8 -> V_9 , V_18 , V_41 , V_8 -> V_54 +
( ( V_3 - V_8 -> V_55 ) >> V_56 ) ,
V_77 ) ;
if ( F_68 ( V_76 ) )
goto V_83;
V_76 = F_50 ( V_8 , V_3 , V_40 , V_41 , V_18 , V_42 ) ;
if ( ! ( F_68 ( V_76 ) ) )
goto V_78;
V_83:
F_58 ( V_75 ) ;
V_78:
return V_76 ;
}
static int F_72 ( struct V_7 * V_8 , unsigned long V_84 )
{
unsigned long V_85 = V_8 -> V_60 + V_84 ;
if ( V_85 < V_8 -> V_60 )
return 0 ;
if ( V_8 -> V_62 && V_8 -> V_62 -> V_55 < V_85 )
return 0 ;
if ( F_71 ( NULL , V_8 -> V_55 , V_85 - V_8 -> V_55 ,
0 , V_80 ) & ~ V_86 )
return 0 ;
return 1 ;
}
