static T_1 * F_1 ( struct V_1 * V_2 , T_2 * V_3 ,
unsigned long V_4 , int V_5 , T_3 * * V_6 )
{
T_1 * V_7 ;
T_3 * V_8 ;
if ( ! V_5 )
return F_2 ( V_2 -> V_9 , V_3 , V_4 , V_6 ) ;
V_8 = F_3 ( V_2 -> V_9 , V_3 ) ;
if ( F_4 ( F_5 ( * V_3 ) || F_6 ( * V_3 ) ) ) {
F_7 ( V_8 ) ;
return NULL ;
}
V_7 = F_2 ( V_2 -> V_9 , V_3 , V_4 , V_6 ) ;
F_7 ( V_8 ) ;
return V_7 ;
}
static unsigned long F_8 ( struct V_1 * V_2 , T_2 * V_3 ,
unsigned long V_4 , unsigned long V_10 , T_4 V_11 ,
int V_12 , int V_5 )
{
struct V_13 * V_14 = V_2 -> V_9 ;
T_1 * V_7 , V_15 ;
T_3 * V_6 ;
unsigned long V_16 = 0 ;
V_7 = F_1 ( V_2 , V_3 , V_4 , V_5 , & V_6 ) ;
if ( ! V_7 )
return 0 ;
F_9 () ;
do {
V_15 = * V_7 ;
if ( F_10 ( V_15 ) ) {
T_1 V_17 ;
bool V_18 = V_5 && F_11 ( V_15 ) ;
if ( V_5 ) {
struct V_19 * V_19 ;
V_19 = F_12 ( V_2 , V_4 , V_15 ) ;
if ( ! V_19 || F_13 ( V_19 ) )
continue;
if ( F_14 ( V_15 ) )
continue;
}
V_17 = F_15 ( V_14 , V_4 , V_7 ) ;
V_17 = F_16 ( V_17 , V_11 ) ;
if ( V_18 )
V_17 = F_17 ( V_17 ) ;
if ( V_12 && F_18 ( V_17 ) &&
( F_19 ( V_17 ) ||
! ( V_2 -> V_20 & V_21 ) ) ) {
V_17 = F_17 ( V_17 ) ;
}
F_20 ( V_14 , V_4 , V_7 , V_17 ) ;
V_16 ++ ;
} else if ( F_21 ( V_22 ) ) {
T_5 V_23 = F_22 ( V_15 ) ;
if ( F_23 ( V_23 ) ) {
T_1 V_24 ;
F_24 ( & V_23 ) ;
V_24 = F_25 ( V_23 ) ;
if ( F_26 ( V_15 ) )
V_24 = F_27 ( V_24 ) ;
F_28 ( V_14 , V_4 , V_7 , V_24 ) ;
V_16 ++ ;
}
}
} while ( V_7 ++ , V_4 += V_25 , V_4 != V_10 );
F_29 () ;
F_30 ( V_7 - 1 , V_6 ) ;
return V_16 ;
}
static inline unsigned long F_31 ( struct V_1 * V_2 ,
T_6 * V_26 , unsigned long V_4 , unsigned long V_10 ,
T_4 V_11 , int V_12 , int V_5 )
{
T_2 * V_3 ;
struct V_13 * V_14 = V_2 -> V_9 ;
unsigned long V_27 ;
unsigned long V_16 = 0 ;
unsigned long V_28 = 0 ;
unsigned long V_29 = 0 ;
V_3 = F_32 ( V_26 , V_4 ) ;
do {
unsigned long V_30 ;
V_27 = F_33 ( V_4 , V_10 ) ;
if ( ! F_5 ( * V_3 ) && ! F_34 ( * V_3 )
&& F_35 ( V_3 ) )
continue;
if ( ! V_29 ) {
V_29 = V_4 ;
F_36 ( V_14 , V_29 , V_10 ) ;
}
if ( F_5 ( * V_3 ) || F_34 ( * V_3 ) ) {
if ( V_27 - V_4 != V_31 ) {
F_37 ( V_2 , V_3 , V_4 ) ;
if ( F_38 ( V_3 ) )
continue;
} else {
int V_32 = F_39 ( V_2 , V_3 , V_4 ,
V_11 , V_5 ) ;
if ( V_32 ) {
if ( V_32 == V_33 ) {
V_16 += V_33 ;
V_28 ++ ;
}
continue;
}
}
}
V_30 = F_8 ( V_2 , V_3 , V_4 , V_27 , V_11 ,
V_12 , V_5 ) ;
V_16 += V_30 ;
} while ( V_3 ++ , V_4 = V_27 , V_4 != V_10 );
if ( V_29 )
F_40 ( V_14 , V_29 , V_10 ) ;
if ( V_28 )
F_41 ( V_34 , V_28 ) ;
return V_16 ;
}
static inline unsigned long F_42 ( struct V_1 * V_2 ,
T_7 * V_35 , unsigned long V_4 , unsigned long V_10 ,
T_4 V_11 , int V_12 , int V_5 )
{
T_6 * V_26 ;
unsigned long V_27 ;
unsigned long V_16 = 0 ;
V_26 = F_43 ( V_35 , V_4 ) ;
do {
V_27 = F_44 ( V_4 , V_10 ) ;
if ( F_45 ( V_26 ) )
continue;
V_16 += F_31 ( V_2 , V_26 , V_4 , V_27 , V_11 ,
V_12 , V_5 ) ;
} while ( V_26 ++ , V_4 = V_27 , V_4 != V_10 );
return V_16 ;
}
static unsigned long F_46 ( struct V_1 * V_2 ,
unsigned long V_4 , unsigned long V_10 , T_4 V_11 ,
int V_12 , int V_5 )
{
struct V_13 * V_14 = V_2 -> V_9 ;
T_7 * V_35 ;
unsigned long V_27 ;
unsigned long V_36 = V_4 ;
unsigned long V_16 = 0 ;
F_47 ( V_4 >= V_10 ) ;
V_35 = F_48 ( V_14 , V_4 ) ;
F_49 ( V_2 , V_4 , V_10 ) ;
F_50 ( V_14 ) ;
do {
V_27 = F_51 ( V_4 , V_10 ) ;
if ( F_52 ( V_35 ) )
continue;
V_16 += F_42 ( V_2 , V_35 , V_4 , V_27 , V_11 ,
V_12 , V_5 ) ;
} while ( V_35 ++ , V_4 = V_27 , V_4 != V_10 );
if ( V_16 )
F_53 ( V_2 , V_36 , V_10 ) ;
F_54 ( V_14 ) ;
return V_16 ;
}
unsigned long F_55 ( struct V_1 * V_2 , unsigned long V_36 ,
unsigned long V_10 , T_4 V_11 ,
int V_12 , int V_5 )
{
unsigned long V_16 ;
if ( F_56 ( V_2 ) )
V_16 = F_57 ( V_2 , V_36 , V_10 , V_11 ) ;
else
V_16 = F_46 ( V_2 , V_36 , V_10 , V_11 , V_12 , V_5 ) ;
return V_16 ;
}
int
F_58 ( struct V_1 * V_2 , struct V_1 * * V_37 ,
unsigned long V_36 , unsigned long V_10 , unsigned long V_38 )
{
struct V_13 * V_14 = V_2 -> V_9 ;
unsigned long V_39 = V_2 -> V_20 ;
long V_40 = ( V_10 - V_36 ) >> V_41 ;
unsigned long V_42 = 0 ;
T_8 V_43 ;
int error ;
int V_12 = 0 ;
if ( V_38 == V_39 ) {
* V_37 = V_2 ;
return 0 ;
}
if ( V_38 & V_44 ) {
if ( ! F_59 ( V_14 , V_38 , V_40 ) &&
F_59 ( V_14 , V_39 , V_40 ) )
return - V_45 ;
if ( ! ( V_39 & ( V_46 | V_44 | V_47 |
V_48 | V_49 ) ) ) {
V_42 = V_40 ;
if ( F_60 ( V_14 , V_42 ) )
return - V_45 ;
V_38 |= V_46 ;
}
}
V_43 = V_2 -> V_50 + ( ( V_36 - V_2 -> V_51 ) >> V_41 ) ;
* V_37 = F_61 ( V_14 , * V_37 , V_36 , V_10 , V_38 ,
V_2 -> V_52 , V_2 -> V_53 , V_43 , F_62 ( V_2 ) ,
V_2 -> V_54 ) ;
if ( * V_37 ) {
V_2 = * V_37 ;
F_63 ( ( V_2 -> V_20 ^ V_38 ) & ~ V_21 ) ;
goto V_55;
}
* V_37 = V_2 ;
if ( V_36 != V_2 -> V_51 ) {
error = F_64 ( V_14 , V_2 , V_36 , 1 ) ;
if ( error )
goto V_56;
}
if ( V_10 != V_2 -> V_57 ) {
error = F_64 ( V_14 , V_2 , V_10 , 0 ) ;
if ( error )
goto V_56;
}
V_55:
V_2 -> V_20 = V_38 ;
V_12 = F_65 ( V_2 , V_2 -> V_58 ) ;
F_66 ( V_2 ) ;
F_55 ( V_2 , V_36 , V_10 , V_2 -> V_58 ,
V_12 , 0 ) ;
if ( ( V_39 & ( V_44 | V_48 | V_59 ) ) == V_59 &&
( V_38 & V_44 ) ) {
F_67 ( V_2 , V_36 , V_10 , NULL ) ;
}
F_68 ( V_14 , V_39 , - V_40 ) ;
F_68 ( V_14 , V_38 , V_40 ) ;
F_69 ( V_2 ) ;
return 0 ;
V_56:
F_70 ( V_42 ) ;
return error ;
}
static int F_71 ( unsigned long V_36 , T_9 V_60 ,
unsigned long V_61 , int V_62 )
{
unsigned long V_63 , V_10 , V_64 , V_65 ;
struct V_1 * V_2 , * V_66 ;
int error = - V_67 ;
const int V_68 = V_61 & ( V_69 | V_70 ) ;
const bool V_71 = ( V_72 -> V_73 & V_74 ) &&
( V_61 & V_75 ) ;
V_61 &= ~ ( V_69 | V_70 ) ;
if ( V_68 == ( V_69 | V_70 ) )
return - V_67 ;
if ( V_36 & ~ V_76 )
return - V_67 ;
if ( ! V_60 )
return 0 ;
V_60 = F_72 ( V_60 ) ;
V_10 = V_36 + V_60 ;
if ( V_10 <= V_36 )
return - V_45 ;
if ( ! F_73 ( V_61 ) )
return - V_67 ;
V_65 = V_61 ;
if ( F_74 ( & V_72 -> V_14 -> V_77 ) )
return - V_78 ;
error = - V_67 ;
if ( ( V_62 != - 1 ) && ! F_75 ( V_72 -> V_14 , V_62 ) )
goto V_79;
V_2 = F_76 ( V_72 -> V_14 , V_36 ) ;
error = - V_45 ;
if ( ! V_2 )
goto V_79;
V_66 = V_2 -> V_80 ;
if ( F_4 ( V_68 & V_69 ) ) {
if ( V_2 -> V_51 >= V_10 )
goto V_79;
V_36 = V_2 -> V_51 ;
error = - V_67 ;
if ( ! ( V_2 -> V_20 & V_81 ) )
goto V_79;
} else {
if ( V_2 -> V_51 > V_36 )
goto V_79;
if ( F_4 ( V_68 & V_70 ) ) {
V_10 = V_2 -> V_57 ;
error = - V_67 ;
if ( ! ( V_2 -> V_20 & V_82 ) )
goto V_79;
}
}
if ( V_36 > V_2 -> V_51 )
V_66 = V_2 ;
for ( V_63 = V_36 ; ; ) {
unsigned long V_83 ;
unsigned long V_38 ;
int V_84 ;
if ( V_71 && ( V_2 -> V_20 & V_85 ) )
V_61 |= V_86 ;
V_83 = V_87 | V_44 | V_88 |
V_89 ;
V_84 = F_77 ( V_2 , V_61 , V_62 ) ;
V_38 = F_78 ( V_61 , V_84 ) ;
V_38 |= ( V_2 -> V_20 & ~ V_83 ) ;
if ( ( V_38 & ~ ( V_38 >> 4 ) ) & ( V_87 | V_44 | V_88 ) ) {
error = - V_90 ;
goto V_79;
}
error = F_79 ( V_2 , V_65 , V_61 ) ;
if ( error )
goto V_79;
V_64 = V_2 -> V_57 ;
if ( V_64 > V_10 )
V_64 = V_10 ;
error = F_58 ( V_2 , & V_66 , V_63 , V_64 , V_38 ) ;
if ( error )
goto V_79;
V_63 = V_64 ;
if ( V_63 < V_66 -> V_57 )
V_63 = V_66 -> V_57 ;
if ( V_63 >= V_10 )
goto V_79;
V_2 = V_66 -> V_91 ;
if ( ! V_2 || V_2 -> V_51 != V_63 ) {
error = - V_45 ;
goto V_79;
}
V_61 = V_65 ;
}
V_79:
F_80 ( & V_72 -> V_14 -> V_77 ) ;
return error ;
}
