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
int V_17 = V_18 ;
V_7 = F_1 ( V_2 , V_3 , V_4 , V_5 , & V_6 ) ;
if ( ! V_7 )
return 0 ;
if ( V_5 && ! ( V_2 -> V_19 & V_20 ) &&
F_9 ( & V_2 -> V_9 -> V_21 ) == 1 )
V_17 = F_10 () ;
F_11 () ;
do {
V_15 = * V_7 ;
if ( F_12 ( V_15 ) ) {
T_1 V_22 ;
bool V_23 = V_5 && F_13 ( V_15 ) ;
if ( V_5 ) {
struct V_24 * V_24 ;
V_24 = F_14 ( V_2 , V_4 , V_15 ) ;
if ( ! V_24 || F_15 ( V_24 ) )
continue;
if ( F_16 ( V_15 ) )
continue;
if ( V_17 == F_17 ( V_24 ) )
continue;
}
V_22 = F_18 ( V_14 , V_4 , V_7 ) ;
V_22 = F_19 ( V_22 , V_11 ) ;
if ( V_23 )
V_22 = F_20 ( V_22 ) ;
if ( V_12 && F_21 ( V_22 ) &&
( F_22 ( V_22 ) ||
! ( V_2 -> V_19 & V_25 ) ) ) {
V_22 = F_20 ( V_22 ) ;
}
F_23 ( V_14 , V_4 , V_7 , V_22 ) ;
V_16 ++ ;
} else if ( F_24 ( V_26 ) ) {
T_5 V_27 = F_25 ( V_15 ) ;
if ( F_26 ( V_27 ) ) {
T_1 V_28 ;
F_27 ( & V_27 ) ;
V_28 = F_28 ( V_27 ) ;
if ( F_29 ( V_15 ) )
V_28 = F_30 ( V_28 ) ;
F_31 ( V_14 , V_4 , V_7 , V_28 ) ;
V_16 ++ ;
}
}
} while ( V_7 ++ , V_4 += V_29 , V_4 != V_10 );
F_32 () ;
F_33 ( V_7 - 1 , V_6 ) ;
return V_16 ;
}
static inline unsigned long F_34 ( struct V_1 * V_2 ,
T_6 * V_30 , unsigned long V_4 , unsigned long V_10 ,
T_4 V_11 , int V_12 , int V_5 )
{
T_2 * V_3 ;
struct V_13 * V_14 = V_2 -> V_9 ;
unsigned long V_31 ;
unsigned long V_16 = 0 ;
unsigned long V_32 = 0 ;
unsigned long V_33 = 0 ;
V_3 = F_35 ( V_30 , V_4 ) ;
do {
unsigned long V_34 ;
V_31 = F_36 ( V_4 , V_10 ) ;
if ( ! F_5 ( * V_3 ) && ! F_37 ( * V_3 )
&& F_38 ( V_3 ) )
continue;
if ( ! V_33 ) {
V_33 = V_4 ;
F_39 ( V_14 , V_33 , V_10 ) ;
}
if ( F_5 ( * V_3 ) || F_37 ( * V_3 ) ) {
if ( V_31 - V_4 != V_35 ) {
F_40 ( V_2 , V_3 , V_4 , false , NULL ) ;
if ( F_41 ( V_3 ) )
continue;
} else {
int V_36 = F_42 ( V_2 , V_3 , V_4 ,
V_11 , V_5 ) ;
if ( V_36 ) {
if ( V_36 == V_37 ) {
V_16 += V_37 ;
V_32 ++ ;
}
continue;
}
}
}
V_34 = F_8 ( V_2 , V_3 , V_4 , V_31 , V_11 ,
V_12 , V_5 ) ;
V_16 += V_34 ;
} while ( V_3 ++ , V_4 = V_31 , V_4 != V_10 );
if ( V_33 )
F_43 ( V_14 , V_33 , V_10 ) ;
if ( V_32 )
F_44 ( V_38 , V_32 ) ;
return V_16 ;
}
static inline unsigned long F_45 ( struct V_1 * V_2 ,
T_7 * V_39 , unsigned long V_4 , unsigned long V_10 ,
T_4 V_11 , int V_12 , int V_5 )
{
T_6 * V_30 ;
unsigned long V_31 ;
unsigned long V_16 = 0 ;
V_30 = F_46 ( V_39 , V_4 ) ;
do {
V_31 = F_47 ( V_4 , V_10 ) ;
if ( F_48 ( V_30 ) )
continue;
V_16 += F_34 ( V_2 , V_30 , V_4 , V_31 , V_11 ,
V_12 , V_5 ) ;
} while ( V_30 ++ , V_4 = V_31 , V_4 != V_10 );
return V_16 ;
}
static unsigned long F_49 ( struct V_1 * V_2 ,
unsigned long V_4 , unsigned long V_10 , T_4 V_11 ,
int V_12 , int V_5 )
{
struct V_13 * V_14 = V_2 -> V_9 ;
T_7 * V_39 ;
unsigned long V_31 ;
unsigned long V_40 = V_4 ;
unsigned long V_16 = 0 ;
F_50 ( V_4 >= V_10 ) ;
V_39 = F_51 ( V_14 , V_4 ) ;
F_52 ( V_2 , V_4 , V_10 ) ;
F_53 ( V_14 ) ;
do {
V_31 = F_54 ( V_4 , V_10 ) ;
if ( F_55 ( V_39 ) )
continue;
V_16 += F_45 ( V_2 , V_39 , V_4 , V_31 , V_11 ,
V_12 , V_5 ) ;
} while ( V_39 ++ , V_4 = V_31 , V_4 != V_10 );
if ( V_16 )
F_56 ( V_2 , V_40 , V_10 ) ;
F_57 ( V_14 ) ;
return V_16 ;
}
unsigned long F_58 ( struct V_1 * V_2 , unsigned long V_40 ,
unsigned long V_10 , T_4 V_11 ,
int V_12 , int V_5 )
{
unsigned long V_16 ;
if ( F_59 ( V_2 ) )
V_16 = F_60 ( V_2 , V_40 , V_10 , V_11 ) ;
else
V_16 = F_49 ( V_2 , V_40 , V_10 , V_11 , V_12 , V_5 ) ;
return V_16 ;
}
int
F_61 ( struct V_1 * V_2 , struct V_1 * * V_41 ,
unsigned long V_40 , unsigned long V_10 , unsigned long V_42 )
{
struct V_13 * V_14 = V_2 -> V_9 ;
unsigned long V_43 = V_2 -> V_19 ;
long V_44 = ( V_10 - V_40 ) >> V_45 ;
unsigned long V_46 = 0 ;
T_8 V_47 ;
int error ;
int V_12 = 0 ;
if ( V_42 == V_43 ) {
* V_41 = V_2 ;
return 0 ;
}
if ( V_42 & V_48 ) {
if ( ! F_62 ( V_14 , V_42 , V_44 ) &&
F_62 ( V_14 , V_43 , V_44 ) )
return - V_49 ;
if ( ! ( V_43 & ( V_50 | V_48 | V_51 |
V_20 | V_52 ) ) ) {
V_46 = V_44 ;
if ( F_63 ( V_14 , V_46 ) )
return - V_49 ;
V_42 |= V_50 ;
}
}
V_47 = V_2 -> V_53 + ( ( V_40 - V_2 -> V_54 ) >> V_45 ) ;
* V_41 = F_64 ( V_14 , * V_41 , V_40 , V_10 , V_42 ,
V_2 -> V_55 , V_2 -> V_56 , V_47 , F_65 ( V_2 ) ,
V_2 -> V_57 ) ;
if ( * V_41 ) {
V_2 = * V_41 ;
F_66 ( ( V_2 -> V_19 ^ V_42 ) & ~ V_25 ) ;
goto V_58;
}
* V_41 = V_2 ;
if ( V_40 != V_2 -> V_54 ) {
error = F_67 ( V_14 , V_2 , V_40 , 1 ) ;
if ( error )
goto V_59;
}
if ( V_10 != V_2 -> V_60 ) {
error = F_67 ( V_14 , V_2 , V_10 , 0 ) ;
if ( error )
goto V_59;
}
V_58:
V_2 -> V_19 = V_42 ;
V_12 = F_68 ( V_2 , V_2 -> V_61 ) ;
F_69 ( V_2 ) ;
F_58 ( V_2 , V_40 , V_10 , V_2 -> V_61 ,
V_12 , 0 ) ;
if ( ( V_43 & ( V_48 | V_20 | V_62 ) ) == V_62 &&
( V_42 & V_48 ) ) {
F_70 ( V_2 , V_40 , V_10 , NULL ) ;
}
F_71 ( V_14 , V_43 , - V_44 ) ;
F_71 ( V_14 , V_42 , V_44 ) ;
F_72 ( V_2 ) ;
return 0 ;
V_59:
F_73 ( V_46 ) ;
return error ;
}
static int F_74 ( unsigned long V_40 , T_9 V_63 ,
unsigned long V_64 , int V_65 )
{
unsigned long V_66 , V_10 , V_67 , V_68 ;
struct V_1 * V_2 , * V_69 ;
int error = - V_70 ;
const int V_71 = V_64 & ( V_72 | V_73 ) ;
const bool V_74 = ( V_75 -> V_76 & V_77 ) &&
( V_64 & V_78 ) ;
V_64 &= ~ ( V_72 | V_73 ) ;
if ( V_71 == ( V_72 | V_73 ) )
return - V_70 ;
if ( V_40 & ~ V_79 )
return - V_70 ;
if ( ! V_63 )
return 0 ;
V_63 = F_75 ( V_63 ) ;
V_10 = V_40 + V_63 ;
if ( V_10 <= V_40 )
return - V_49 ;
if ( ! F_76 ( V_64 ) )
return - V_70 ;
V_68 = V_64 ;
if ( F_77 ( & V_75 -> V_14 -> V_80 ) )
return - V_81 ;
error = - V_70 ;
if ( ( V_65 != - 1 ) && ! F_78 ( V_75 -> V_14 , V_65 ) )
goto V_82;
V_2 = F_79 ( V_75 -> V_14 , V_40 ) ;
error = - V_49 ;
if ( ! V_2 )
goto V_82;
V_69 = V_2 -> V_83 ;
if ( F_4 ( V_71 & V_72 ) ) {
if ( V_2 -> V_54 >= V_10 )
goto V_82;
V_40 = V_2 -> V_54 ;
error = - V_70 ;
if ( ! ( V_2 -> V_19 & V_84 ) )
goto V_82;
} else {
if ( V_2 -> V_54 > V_40 )
goto V_82;
if ( F_4 ( V_71 & V_73 ) ) {
V_10 = V_2 -> V_60 ;
error = - V_70 ;
if ( ! ( V_2 -> V_19 & V_85 ) )
goto V_82;
}
}
if ( V_40 > V_2 -> V_54 )
V_69 = V_2 ;
for ( V_66 = V_40 ; ; ) {
unsigned long V_86 ;
unsigned long V_42 ;
int V_87 ;
if ( V_74 && ( V_2 -> V_19 & V_88 ) )
V_64 |= V_89 ;
V_86 = V_90 | V_48 | V_91 |
V_92 ;
V_87 = F_80 ( V_2 , V_64 , V_65 ) ;
V_42 = F_81 ( V_64 , V_87 ) ;
V_42 |= ( V_2 -> V_19 & ~ V_86 ) ;
if ( ( V_42 & ~ ( V_42 >> 4 ) ) & ( V_90 | V_48 | V_91 ) ) {
error = - V_93 ;
goto V_82;
}
error = F_82 ( V_2 , V_68 , V_64 ) ;
if ( error )
goto V_82;
V_67 = V_2 -> V_60 ;
if ( V_67 > V_10 )
V_67 = V_10 ;
error = F_61 ( V_2 , & V_69 , V_66 , V_67 , V_42 ) ;
if ( error )
goto V_82;
V_66 = V_67 ;
if ( V_66 < V_69 -> V_60 )
V_66 = V_69 -> V_60 ;
if ( V_66 >= V_10 )
goto V_82;
V_2 = V_69 -> V_94 ;
if ( ! V_2 || V_2 -> V_54 != V_66 ) {
error = - V_49 ;
goto V_82;
}
V_64 = V_68 ;
}
V_82:
F_83 ( & V_75 -> V_14 -> V_80 ) ;
return error ;
}
