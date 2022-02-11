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
else if ( F_19 ( V_9 ) )
V_9 = F_20 ( V_9 ) ;
#endif
return V_9 ;
}
static void F_21 ( struct V_7 * V_8 , T_1 * V_10 ,
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
F_22 ( & V_18 -> V_27 ) ;
}
if ( V_8 -> V_19 ) {
V_19 = V_8 -> V_19 ;
F_23 ( V_19 ) ;
}
}
V_21 = F_24 ( V_2 , V_10 , V_11 , & V_23 ) ;
V_22 = F_25 ( V_14 , V_15 ) ;
V_24 = F_26 ( V_2 , V_14 ) ;
if ( V_24 != V_23 )
F_27 ( V_24 , V_28 ) ;
F_28 () ;
for (; V_11 < V_12 ; V_21 ++ , V_11 += V_29 ,
V_22 ++ , V_15 += V_29 ) {
if ( F_29 ( * V_21 ) )
continue;
V_9 = F_30 ( V_2 , V_11 , V_21 ) ;
V_9 = F_31 ( V_9 , V_13 -> V_30 , V_11 , V_15 ) ;
V_9 = F_13 ( V_9 ) ;
F_32 ( V_2 , V_15 , V_22 , V_9 ) ;
}
F_33 () ;
if ( V_24 != V_23 )
F_34 ( V_24 ) ;
F_35 ( V_22 - 1 ) ;
F_36 ( V_21 - 1 , V_23 ) ;
if ( V_19 )
F_37 ( V_19 ) ;
if ( V_18 )
F_38 ( & V_18 -> V_27 ) ;
}
unsigned long F_39 ( struct V_7 * V_8 ,
unsigned long V_11 , struct V_7 * V_13 ,
unsigned long V_15 , unsigned long V_31 ,
bool V_16 )
{
unsigned long V_32 , V_33 , V_12 ;
T_1 * V_10 , * V_14 ;
bool V_34 = false ;
unsigned long V_35 ;
unsigned long V_36 ;
V_12 = V_11 + V_31 ;
F_40 ( V_8 , V_11 , V_12 ) ;
V_35 = V_11 ;
V_36 = V_12 ;
F_41 ( V_8 -> V_20 , V_35 , V_36 ) ;
for (; V_11 < V_12 ; V_11 += V_32 , V_15 += V_32 ) {
F_42 () ;
V_33 = ( V_11 + V_37 ) & V_38 ;
V_32 = V_33 - V_11 ;
if ( V_32 > V_12 - V_11 )
V_32 = V_12 - V_11 ;
V_10 = F_1 ( V_8 -> V_20 , V_11 ) ;
if ( ! V_10 )
continue;
V_14 = F_8 ( V_8 -> V_20 , V_8 , V_15 ) ;
if ( ! V_14 )
break;
if ( F_12 ( * V_10 ) ) {
int V_39 = 0 ;
if ( V_32 == V_40 ) {
F_11 ( V_8 -> V_25 || ! V_8 -> V_19 ) ;
if ( V_16 )
F_23 ( V_8 -> V_19 ) ;
V_39 = F_43 ( V_8 , V_13 , V_11 ,
V_15 , V_12 ,
V_10 , V_14 ) ;
if ( V_16 )
F_37 ( V_8 -> V_19 ) ;
}
if ( V_39 > 0 ) {
V_34 = true ;
continue;
} else if ( ! V_39 ) {
F_44 ( V_8 , V_11 , V_10 ) ;
}
F_11 ( F_12 ( * V_10 ) ) ;
}
if ( F_7 ( * V_14 ) && F_45 ( V_13 -> V_20 , V_13 ,
V_14 , V_15 ) )
break;
V_33 = ( V_15 + V_37 ) & V_38 ;
if ( V_32 > V_33 - V_15 )
V_32 = V_33 - V_15 ;
if ( V_32 > V_41 )
V_32 = V_41 ;
F_21 ( V_8 , V_10 , V_11 , V_11 + V_32 ,
V_13 , V_14 , V_15 , V_16 ) ;
V_34 = true ;
}
if ( F_46 ( V_34 ) )
F_47 ( V_8 , V_12 - V_31 , V_11 ) ;
F_48 ( V_8 -> V_20 , V_35 , V_36 ) ;
return V_31 + V_11 - V_12 ;
}
static unsigned long F_49 ( struct V_7 * V_8 ,
unsigned long V_11 , unsigned long V_42 ,
unsigned long V_43 , unsigned long V_15 , bool * V_44 )
{
struct V_1 * V_2 = V_8 -> V_20 ;
struct V_7 * V_13 ;
unsigned long V_45 = V_8 -> V_45 ;
unsigned long V_46 ;
unsigned long V_47 ;
unsigned long V_48 = 0 ;
unsigned long V_49 ;
int V_50 = 0 ;
int V_39 ;
bool V_16 ;
if ( V_2 -> V_51 >= V_52 - 3 )
return - V_53 ;
V_39 = F_50 ( V_8 , V_11 , V_11 + V_42 ,
V_54 , & V_45 ) ;
if ( V_39 )
return V_39 ;
V_46 = V_8 -> V_55 + ( ( V_11 - V_8 -> V_56 ) >> V_57 ) ;
V_13 = F_51 ( & V_8 , V_15 , V_43 , V_46 ,
& V_16 ) ;
if ( ! V_13 )
return - V_53 ;
V_47 = F_39 ( V_8 , V_11 , V_13 , V_15 , V_42 ,
V_16 ) ;
if ( V_47 < V_42 ) {
F_39 ( V_13 , V_15 , V_8 , V_11 , V_47 ,
true ) ;
V_8 = V_13 ;
V_42 = V_43 ;
V_11 = V_15 ;
V_15 = - V_53 ;
}
if ( V_45 & V_58 ) {
V_8 -> V_45 &= ~ V_58 ;
V_48 = V_8 -> V_59 - V_8 -> V_56 - V_42 ;
if ( V_11 > V_8 -> V_56 &&
V_11 + V_42 < V_8 -> V_59 )
V_50 = 1 ;
}
V_49 = V_2 -> V_49 ;
F_52 ( V_2 , V_8 -> V_45 , V_8 -> V_25 , V_43 >> V_57 ) ;
if ( F_53 ( V_2 , V_11 , V_42 ) < 0 ) {
F_54 ( V_48 >> V_57 ) ;
V_48 = 0 ;
}
V_2 -> V_49 = V_49 ;
if ( V_48 ) {
V_8 -> V_45 |= V_58 ;
if ( V_50 )
V_8 -> V_60 -> V_45 |= V_58 ;
}
if ( V_45 & V_61 ) {
V_2 -> V_62 += V_43 >> V_57 ;
* V_44 = true ;
}
return V_15 ;
}
static struct V_7 * F_55 ( unsigned long V_3 ,
unsigned long V_42 , unsigned long V_43 , unsigned long * V_63 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_7 * V_8 = F_56 ( V_2 , V_3 ) ;
if ( ! V_8 || V_8 -> V_56 > V_3 )
goto V_65;
if ( F_57 ( V_8 ) )
goto V_66;
if ( V_42 > V_8 -> V_59 - V_3 )
goto V_65;
if ( V_43 > V_42 ) {
unsigned long V_67 ;
if ( V_8 -> V_45 & ( V_68 | V_69 ) )
goto V_65;
V_67 = ( V_3 - V_8 -> V_56 ) >> V_57 ;
V_67 += V_8 -> V_55 ;
if ( V_67 + ( V_43 >> V_57 ) < V_67 )
goto V_66;
}
if ( V_8 -> V_45 & V_61 ) {
unsigned long V_44 , V_70 ;
V_44 = V_2 -> V_62 << V_57 ;
V_70 = F_58 ( V_71 ) ;
V_44 += V_43 - V_42 ;
if ( V_44 > V_70 && ! F_59 ( V_72 ) )
goto V_73;
}
if ( ! F_60 ( V_2 , ( V_43 - V_42 ) >> V_57 ) )
goto V_74;
if ( V_8 -> V_45 & V_58 ) {
unsigned long V_75 = ( V_43 - V_42 ) >> V_57 ;
if ( F_61 ( V_2 , V_75 ) )
goto V_65;
* V_63 = V_75 ;
}
return V_8 ;
V_65:
return F_62 ( - V_76 ) ;
V_66:
return F_62 ( - V_77 ) ;
V_74:
return F_62 ( - V_53 ) ;
V_73:
return F_62 ( - V_78 ) ;
}
static unsigned long F_63 ( unsigned long V_3 , unsigned long V_42 ,
unsigned long V_15 , unsigned long V_43 , bool * V_44 )
{
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_7 * V_8 ;
unsigned long V_79 = - V_77 ;
unsigned long V_75 = 0 ;
unsigned long V_80 ;
if ( V_15 & ~ V_81 )
goto V_82;
if ( V_43 > V_83 || V_15 > V_83 - V_43 )
goto V_82;
if ( ( V_15 <= V_3 ) && ( V_15 + V_43 ) > V_3 )
goto V_82;
if ( ( V_3 <= V_15 ) && ( V_3 + V_42 ) > V_15 )
goto V_82;
V_79 = F_53 ( V_2 , V_15 , V_43 ) ;
if ( V_79 )
goto V_82;
if ( V_42 >= V_43 ) {
V_79 = F_53 ( V_2 , V_3 + V_43 , V_42 - V_43 ) ;
if ( V_79 && V_42 != V_43 )
goto V_82;
V_42 = V_43 ;
}
V_8 = F_55 ( V_3 , V_42 , V_43 , & V_75 ) ;
if ( F_64 ( V_8 ) ) {
V_79 = F_65 ( V_8 ) ;
goto V_82;
}
V_80 = V_84 ;
if ( V_8 -> V_45 & V_85 )
V_80 |= V_86 ;
V_79 = F_66 ( V_8 -> V_25 , V_15 , V_43 , V_8 -> V_55 +
( ( V_3 - V_8 -> V_56 ) >> V_57 ) ,
V_80 ) ;
if ( V_79 & ~ V_81 )
goto V_87;
V_79 = F_49 ( V_8 , V_3 , V_42 , V_43 , V_15 , V_44 ) ;
if ( ! ( V_79 & ~ V_81 ) )
goto V_82;
V_87:
F_54 ( V_75 ) ;
V_82:
return V_79 ;
}
static int F_67 ( struct V_7 * V_8 , unsigned long V_88 )
{
unsigned long V_89 = V_8 -> V_59 + V_88 ;
if ( V_89 < V_8 -> V_59 )
return 0 ;
if ( V_8 -> V_60 && V_8 -> V_60 -> V_56 < V_89 )
return 0 ;
if ( F_66 ( NULL , V_8 -> V_56 , V_89 - V_8 -> V_56 ,
0 , V_84 ) & ~ V_81 )
return 0 ;
return 1 ;
}
