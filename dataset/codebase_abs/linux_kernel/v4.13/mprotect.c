static unsigned long F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned long V_4 , unsigned long V_5 , T_2 V_6 ,
int V_7 , int V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_3 * V_12 , V_13 ;
T_4 * V_14 ;
unsigned long V_15 = 0 ;
int V_16 = V_17 ;
if ( F_2 ( V_3 ) )
return 0 ;
V_12 = F_3 ( V_2 -> V_11 , V_3 , V_4 , & V_14 ) ;
if ( V_8 && ! ( V_2 -> V_18 & V_19 ) &&
F_4 ( & V_2 -> V_11 -> V_20 ) == 1 )
V_16 = F_5 () ;
F_6 ( V_2 -> V_11 ) ;
F_7 () ;
do {
V_13 = * V_12 ;
if ( F_8 ( V_13 ) ) {
T_3 V_21 ;
bool V_22 = V_8 && F_9 ( V_13 ) ;
if ( V_8 ) {
struct V_23 * V_23 ;
V_23 = F_10 ( V_2 , V_4 , V_13 ) ;
if ( ! V_23 || F_11 ( V_23 ) )
continue;
if ( F_12 ( V_13 ) )
continue;
if ( V_16 == F_13 ( V_23 ) )
continue;
}
V_21 = F_14 ( V_10 , V_4 , V_12 ) ;
V_21 = F_15 ( V_21 , V_6 ) ;
if ( V_22 )
V_21 = F_16 ( V_21 ) ;
if ( V_7 && F_17 ( V_21 ) &&
( F_18 ( V_21 ) ||
! ( V_2 -> V_18 & V_24 ) ) ) {
V_21 = F_19 ( V_21 ) ;
}
F_20 ( V_10 , V_4 , V_12 , V_21 ) ;
V_15 ++ ;
} else if ( F_21 ( V_25 ) ) {
T_5 V_26 = F_22 ( V_13 ) ;
if ( F_23 ( V_26 ) ) {
T_3 V_27 ;
F_24 ( & V_26 ) ;
V_27 = F_25 ( V_26 ) ;
if ( F_26 ( V_13 ) )
V_27 = F_27 ( V_27 ) ;
F_28 ( V_10 , V_4 , V_12 , V_27 ) ;
V_15 ++ ;
}
}
} while ( V_12 ++ , V_4 += V_28 , V_4 != V_5 );
F_29 () ;
F_30 ( V_12 - 1 , V_14 ) ;
return V_15 ;
}
static inline unsigned long F_31 ( struct V_1 * V_2 ,
T_6 * V_29 , unsigned long V_4 , unsigned long V_5 ,
T_2 V_6 , int V_7 , int V_8 )
{
T_1 * V_3 ;
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_30 ;
unsigned long V_15 = 0 ;
unsigned long V_31 = 0 ;
unsigned long V_32 = 0 ;
V_3 = F_32 ( V_29 , V_4 ) ;
do {
unsigned long V_33 ;
V_30 = F_33 ( V_4 , V_5 ) ;
if ( ! F_34 ( * V_3 ) && ! F_35 ( * V_3 )
&& F_36 ( V_3 ) )
continue;
if ( ! V_32 ) {
V_32 = V_4 ;
F_37 ( V_10 , V_32 , V_5 ) ;
}
if ( F_34 ( * V_3 ) || F_35 ( * V_3 ) ) {
if ( V_30 - V_4 != V_34 ) {
F_38 ( V_2 , V_3 , V_4 , false , NULL ) ;
} else {
int V_35 = F_39 ( V_2 , V_3 , V_4 ,
V_6 , V_8 ) ;
if ( V_35 ) {
if ( V_35 == V_36 ) {
V_15 += V_36 ;
V_31 ++ ;
}
continue;
}
}
}
V_33 = F_1 ( V_2 , V_3 , V_4 , V_30 , V_6 ,
V_7 , V_8 ) ;
V_15 += V_33 ;
} while ( V_3 ++ , V_4 = V_30 , V_4 != V_5 );
if ( V_32 )
F_40 ( V_10 , V_32 , V_5 ) ;
if ( V_31 )
F_41 ( V_37 , V_31 ) ;
return V_15 ;
}
static inline unsigned long F_42 ( struct V_1 * V_2 ,
T_7 * V_38 , unsigned long V_4 , unsigned long V_5 ,
T_2 V_6 , int V_7 , int V_8 )
{
T_6 * V_29 ;
unsigned long V_30 ;
unsigned long V_15 = 0 ;
V_29 = F_43 ( V_38 , V_4 ) ;
do {
V_30 = F_44 ( V_4 , V_5 ) ;
if ( F_45 ( V_29 ) )
continue;
V_15 += F_31 ( V_2 , V_29 , V_4 , V_30 , V_6 ,
V_7 , V_8 ) ;
} while ( V_29 ++ , V_4 = V_30 , V_4 != V_5 );
return V_15 ;
}
static inline unsigned long F_46 ( struct V_1 * V_2 ,
T_8 * V_39 , unsigned long V_4 , unsigned long V_5 ,
T_2 V_6 , int V_7 , int V_8 )
{
T_7 * V_38 ;
unsigned long V_30 ;
unsigned long V_15 = 0 ;
V_38 = F_47 ( V_39 , V_4 ) ;
do {
V_30 = F_48 ( V_4 , V_5 ) ;
if ( F_49 ( V_38 ) )
continue;
V_15 += F_42 ( V_2 , V_38 , V_4 , V_30 , V_6 ,
V_7 , V_8 ) ;
} while ( V_38 ++ , V_4 = V_30 , V_4 != V_5 );
return V_15 ;
}
static unsigned long F_50 ( struct V_1 * V_2 ,
unsigned long V_4 , unsigned long V_5 , T_2 V_6 ,
int V_7 , int V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_8 * V_39 ;
unsigned long V_30 ;
unsigned long V_40 = V_4 ;
unsigned long V_15 = 0 ;
F_51 ( V_4 >= V_5 ) ;
V_39 = F_52 ( V_10 , V_4 ) ;
F_53 ( V_2 , V_4 , V_5 ) ;
F_54 ( V_10 ) ;
do {
V_30 = F_55 ( V_4 , V_5 ) ;
if ( F_56 ( V_39 ) )
continue;
V_15 += F_46 ( V_2 , V_39 , V_4 , V_30 , V_6 ,
V_7 , V_8 ) ;
} while ( V_39 ++ , V_4 = V_30 , V_4 != V_5 );
if ( V_15 )
F_57 ( V_2 , V_40 , V_5 ) ;
F_58 ( V_10 ) ;
return V_15 ;
}
unsigned long F_59 ( struct V_1 * V_2 , unsigned long V_40 ,
unsigned long V_5 , T_2 V_6 ,
int V_7 , int V_8 )
{
unsigned long V_15 ;
if ( F_60 ( V_2 ) )
V_15 = F_61 ( V_2 , V_40 , V_5 , V_6 ) ;
else
V_15 = F_50 ( V_2 , V_40 , V_5 , V_6 , V_7 , V_8 ) ;
return V_15 ;
}
int
F_62 ( struct V_1 * V_2 , struct V_1 * * V_41 ,
unsigned long V_40 , unsigned long V_5 , unsigned long V_42 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_43 = V_2 -> V_18 ;
long V_44 = ( V_5 - V_40 ) >> V_45 ;
unsigned long V_46 = 0 ;
T_9 V_47 ;
int error ;
int V_7 = 0 ;
if ( V_42 == V_43 ) {
* V_41 = V_2 ;
return 0 ;
}
if ( V_42 & V_48 ) {
if ( ! F_63 ( V_10 , V_42 , V_44 ) &&
F_63 ( V_10 , V_43 , V_44 ) )
return - V_49 ;
if ( ! ( V_43 & ( V_50 | V_48 | V_51 |
V_19 | V_52 ) ) ) {
V_46 = V_44 ;
if ( F_64 ( V_10 , V_46 ) )
return - V_49 ;
V_42 |= V_50 ;
}
}
V_47 = V_2 -> V_53 + ( ( V_40 - V_2 -> V_54 ) >> V_45 ) ;
* V_41 = F_65 ( V_10 , * V_41 , V_40 , V_5 , V_42 ,
V_2 -> V_55 , V_2 -> V_56 , V_47 , F_66 ( V_2 ) ,
V_2 -> V_57 ) ;
if ( * V_41 ) {
V_2 = * V_41 ;
F_67 ( ( V_2 -> V_18 ^ V_42 ) & ~ V_24 ) ;
goto V_58;
}
* V_41 = V_2 ;
if ( V_40 != V_2 -> V_54 ) {
error = F_68 ( V_10 , V_2 , V_40 , 1 ) ;
if ( error )
goto V_59;
}
if ( V_5 != V_2 -> V_60 ) {
error = F_68 ( V_10 , V_2 , V_5 , 0 ) ;
if ( error )
goto V_59;
}
V_58:
V_2 -> V_18 = V_42 ;
V_7 = F_69 ( V_2 , V_2 -> V_61 ) ;
F_70 ( V_2 ) ;
F_59 ( V_2 , V_40 , V_5 , V_2 -> V_61 ,
V_7 , 0 ) ;
if ( ( V_43 & ( V_48 | V_19 | V_62 ) ) == V_62 &&
( V_42 & V_48 ) ) {
F_71 ( V_2 , V_40 , V_5 , NULL ) ;
}
F_72 ( V_10 , V_43 , - V_44 ) ;
F_72 ( V_10 , V_42 , V_44 ) ;
F_73 ( V_2 ) ;
return 0 ;
V_59:
F_74 ( V_46 ) ;
return error ;
}
static int F_75 ( unsigned long V_40 , T_10 V_63 ,
unsigned long V_64 , int V_65 )
{
unsigned long V_66 , V_5 , V_67 , V_68 ;
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
V_63 = F_76 ( V_63 ) ;
V_5 = V_40 + V_63 ;
if ( V_5 <= V_40 )
return - V_49 ;
if ( ! F_77 ( V_64 ) )
return - V_70 ;
V_68 = V_64 ;
if ( F_78 ( & V_75 -> V_10 -> V_80 ) )
return - V_81 ;
error = - V_70 ;
if ( ( V_65 != - 1 ) && ! F_79 ( V_75 -> V_10 , V_65 ) )
goto V_82;
V_2 = F_80 ( V_75 -> V_10 , V_40 ) ;
error = - V_49 ;
if ( ! V_2 )
goto V_82;
V_69 = V_2 -> V_83 ;
if ( F_81 ( V_71 & V_72 ) ) {
if ( V_2 -> V_54 >= V_5 )
goto V_82;
V_40 = V_2 -> V_54 ;
error = - V_70 ;
if ( ! ( V_2 -> V_18 & V_84 ) )
goto V_82;
} else {
if ( V_2 -> V_54 > V_40 )
goto V_82;
if ( F_81 ( V_71 & V_73 ) ) {
V_5 = V_2 -> V_60 ;
error = - V_70 ;
if ( ! ( V_2 -> V_18 & V_85 ) )
goto V_82;
}
}
if ( V_40 > V_2 -> V_54 )
V_69 = V_2 ;
for ( V_66 = V_40 ; ; ) {
unsigned long V_86 ;
unsigned long V_42 ;
int V_87 ;
if ( V_74 && ( V_2 -> V_18 & V_88 ) )
V_64 |= V_89 ;
V_86 = V_90 | V_48 | V_91 |
V_92 ;
V_87 = F_82 ( V_2 , V_64 , V_65 ) ;
V_42 = F_83 ( V_64 , V_87 ) ;
V_42 |= ( V_2 -> V_18 & ~ V_86 ) ;
if ( ( V_42 & ~ ( V_42 >> 4 ) ) & ( V_90 | V_48 | V_91 ) ) {
error = - V_93 ;
goto V_82;
}
error = F_84 ( V_2 , V_68 , V_64 ) ;
if ( error )
goto V_82;
V_67 = V_2 -> V_60 ;
if ( V_67 > V_5 )
V_67 = V_5 ;
error = F_62 ( V_2 , & V_69 , V_66 , V_67 , V_42 ) ;
if ( error )
goto V_82;
V_66 = V_67 ;
if ( V_66 < V_69 -> V_60 )
V_66 = V_69 -> V_60 ;
if ( V_66 >= V_5 )
goto V_82;
V_2 = V_69 -> V_94 ;
if ( ! V_2 || V_2 -> V_54 != V_66 ) {
error = - V_49 ;
goto V_82;
}
V_64 = V_68 ;
}
V_82:
F_85 ( & V_75 -> V_10 -> V_80 ) ;
return error ;
}
