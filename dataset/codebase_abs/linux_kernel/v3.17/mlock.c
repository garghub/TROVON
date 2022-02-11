int F_1 ( void )
{
if ( F_2 ( V_1 ) )
return 1 ;
if ( F_3 ( V_2 ) != 0 )
return 1 ;
return 0 ;
}
void F_4 ( struct V_3 * V_3 )
{
if ( ! F_5 ( V_3 ) )
return;
F_6 ( F_7 ( V_3 ) , V_4 ,
- F_8 ( V_3 ) ) ;
F_9 ( V_5 ) ;
if ( ! F_10 ( V_3 ) ) {
F_11 ( V_3 ) ;
} else {
if ( F_12 ( V_3 ) )
F_9 ( V_6 ) ;
}
}
void F_13 ( struct V_3 * V_3 )
{
F_14 ( ! F_15 ( V_3 ) ) ;
if ( ! F_16 ( V_3 ) ) {
F_6 ( F_7 ( V_3 ) , V_4 ,
F_8 ( V_3 ) ) ;
F_9 ( V_7 ) ;
if ( ! F_10 ( V_3 ) )
F_11 ( V_3 ) ;
}
}
static bool F_17 ( struct V_3 * V_3 , bool V_8 )
{
if ( F_18 ( V_3 ) ) {
struct V_9 * V_9 ;
V_9 = F_19 ( V_3 , F_7 ( V_3 ) ) ;
if ( V_8 )
F_20 ( V_3 ) ;
F_21 ( V_3 ) ;
F_22 ( V_3 , V_9 , F_23 ( V_3 ) ) ;
return true ;
}
return false ;
}
static void F_24 ( struct V_3 * V_3 )
{
int V_10 = V_11 ;
if ( F_25 ( V_3 ) > 1 )
V_10 = F_26 ( V_3 ) ;
if ( V_10 != V_12 )
F_9 ( V_13 ) ;
F_11 ( V_3 ) ;
}
static void F_27 ( struct V_3 * V_3 )
{
if ( F_12 ( V_3 ) )
F_28 ( V_6 ) ;
else
F_28 ( V_13 ) ;
}
unsigned int F_29 ( struct V_3 * V_3 )
{
unsigned int V_14 ;
struct V_15 * V_15 = F_7 ( V_3 ) ;
F_14 ( ! F_15 ( V_3 ) ) ;
F_30 ( & V_15 -> V_16 ) ;
V_14 = F_8 ( V_3 ) ;
if ( ! F_5 ( V_3 ) )
goto V_17;
F_31 ( V_15 , V_4 , - V_14 ) ;
if ( F_17 ( V_3 , true ) ) {
F_32 ( & V_15 -> V_16 ) ;
F_24 ( V_3 ) ;
goto V_18;
}
F_27 ( V_3 ) ;
V_17:
F_32 ( & V_15 -> V_16 ) ;
V_18:
return V_14 - 1 ;
}
long F_33 ( struct V_19 * V_20 ,
unsigned long V_21 , unsigned long V_22 , int * V_23 )
{
struct V_24 * V_25 = V_20 -> V_26 ;
unsigned long V_14 = ( V_22 - V_21 ) / V_27 ;
int V_28 ;
F_34 ( V_21 & ~ V_29 ) ;
F_34 ( V_22 & ~ V_29 ) ;
F_34 ( V_21 < V_20 -> V_30 ) ;
F_34 ( V_22 > V_20 -> V_31 ) ;
F_34 ( ! F_35 ( & V_25 -> V_32 ) ) ;
V_28 = V_33 | V_34 ;
if ( ( V_20 -> V_35 & ( V_36 | V_37 ) ) == V_36 )
V_28 |= V_38 ;
if ( V_20 -> V_35 & ( V_39 | V_36 | V_40 ) )
V_28 |= V_41 ;
return F_36 ( V_42 , V_25 , V_21 , V_14 , V_28 ,
NULL , NULL , V_23 ) ;
}
static int F_37 ( long V_43 )
{
if ( V_43 == - V_44 )
V_43 = - V_45 ;
else if ( V_43 == - V_45 )
V_43 = - V_46 ;
return V_43 ;
}
static bool F_38 ( struct V_3 * V_3 , struct V_47 * V_48 ,
int * V_49 )
{
F_39 ( F_18 ( V_3 ) , V_3 ) ;
F_39 ( ! F_15 ( V_3 ) , V_3 ) ;
if ( F_25 ( V_3 ) <= 1 && F_40 ( V_3 ) ) {
F_41 ( V_48 , V_3 ) ;
if ( F_42 ( V_3 ) )
( * V_49 ) ++ ;
F_43 ( V_3 ) ;
return true ;
}
return false ;
}
static void F_44 ( struct V_47 * V_48 , int V_49 )
{
F_45 ( V_13 , F_46 ( V_48 ) ) ;
F_47 ( V_48 ) ;
F_45 ( V_50 , V_49 ) ;
}
static void F_48 ( struct V_47 * V_48 , struct V_15 * V_15 )
{
int V_51 ;
int V_52 = F_46 ( V_48 ) ;
int V_53 ;
struct V_47 V_54 ;
int V_49 = 0 ;
F_49 ( & V_54 , 0 ) ;
F_30 ( & V_15 -> V_16 ) ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
struct V_3 * V_3 = V_48 -> V_55 [ V_51 ] ;
if ( F_5 ( V_3 ) ) {
if ( F_17 ( V_3 , false ) )
continue;
else
F_27 ( V_3 ) ;
}
F_41 ( & V_54 , V_48 -> V_55 [ V_51 ] ) ;
V_48 -> V_55 [ V_51 ] = NULL ;
}
V_53 = - V_52 + F_46 ( & V_54 ) ;
F_31 ( V_15 , V_4 , V_53 ) ;
F_32 ( & V_15 -> V_16 ) ;
F_50 ( & V_54 ) ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
struct V_3 * V_3 = V_48 -> V_55 [ V_51 ] ;
if ( V_3 ) {
F_51 ( V_3 ) ;
if ( ! F_38 ( V_3 , & V_54 ,
& V_49 ) ) {
F_20 ( V_3 ) ;
F_24 ( V_3 ) ;
F_43 ( V_3 ) ;
F_52 ( V_3 ) ;
}
}
}
if ( F_46 ( & V_54 ) )
F_44 ( & V_54 , V_49 ) ;
}
static unsigned long F_53 ( struct V_47 * V_48 ,
struct V_19 * V_20 , int V_56 , unsigned long V_21 ,
unsigned long V_22 )
{
T_1 * V_57 ;
T_2 * V_58 ;
V_57 = F_54 ( V_20 -> V_26 , V_21 , & V_58 ) ;
V_22 = F_55 ( V_21 , V_22 ) ;
V_22 = F_56 ( V_21 , V_22 ) ;
V_22 = F_57 ( V_21 , V_22 ) ;
V_21 += V_27 ;
while ( V_21 < V_22 ) {
struct V_3 * V_3 = NULL ;
V_57 ++ ;
if ( F_58 ( * V_57 ) )
V_3 = F_59 ( V_20 , V_21 , * V_57 ) ;
if ( ! V_3 || F_60 ( V_3 ) != V_56 )
break;
F_20 ( V_3 ) ;
V_21 += V_27 ;
if ( F_41 ( V_48 , V_3 ) == 0 )
break;
}
F_61 ( V_57 , V_58 ) ;
return V_21 ;
}
void F_62 ( struct V_19 * V_20 ,
unsigned long V_21 , unsigned long V_22 )
{
V_20 -> V_35 &= ~ V_59 ;
while ( V_21 < V_22 ) {
struct V_3 * V_3 = NULL ;
unsigned int V_60 ;
unsigned long V_61 ;
struct V_47 V_48 ;
struct V_15 * V_15 ;
int V_56 ;
F_49 ( & V_48 , 0 ) ;
V_3 = F_63 ( V_20 , V_21 , V_62 | V_63 ,
& V_60 ) ;
if ( V_3 && ! F_64 ( V_3 ) ) {
if ( F_65 ( V_3 ) ) {
F_51 ( V_3 ) ;
V_60 = F_29 ( V_3 ) ;
F_43 ( V_3 ) ;
F_52 ( V_3 ) ;
} else {
F_41 ( & V_48 , V_3 ) ;
V_15 = F_7 ( V_3 ) ;
V_56 = F_60 ( V_3 ) ;
V_21 = F_53 ( & V_48 , V_20 ,
V_56 , V_21 , V_22 ) ;
F_48 ( & V_48 , V_15 ) ;
goto V_64;
}
}
F_34 ( ( V_21 >> V_65 ) & V_60 ) ;
V_61 = 1 + V_60 ;
V_21 += V_61 * V_27 ;
V_64:
F_66 () ;
}
}
static int F_67 ( struct V_19 * V_20 , struct V_19 * * V_66 ,
unsigned long V_21 , unsigned long V_22 , T_3 V_67 )
{
struct V_24 * V_25 = V_20 -> V_26 ;
T_4 V_68 ;
int V_14 ;
int V_10 = 0 ;
int V_69 = ! ! ( V_67 & V_59 ) ;
if ( V_67 == V_20 -> V_35 || ( V_20 -> V_35 & V_70 ) ||
F_68 ( V_20 ) || V_20 == F_69 ( V_42 -> V_25 ) )
goto V_18;
V_68 = V_20 -> V_71 + ( ( V_21 - V_20 -> V_30 ) >> V_65 ) ;
* V_66 = F_70 ( V_25 , * V_66 , V_21 , V_22 , V_67 , V_20 -> V_72 ,
V_20 -> V_73 , V_68 , F_71 ( V_20 ) ) ;
if ( * V_66 ) {
V_20 = * V_66 ;
goto V_74;
}
if ( V_21 != V_20 -> V_30 ) {
V_10 = F_72 ( V_25 , V_20 , V_21 , 1 ) ;
if ( V_10 )
goto V_18;
}
if ( V_22 != V_20 -> V_31 ) {
V_10 = F_72 ( V_25 , V_20 , V_22 , 0 ) ;
if ( V_10 )
goto V_18;
}
V_74:
V_14 = ( V_22 - V_21 ) >> V_65 ;
if ( ! V_69 )
V_14 = - V_14 ;
V_25 -> V_75 += V_14 ;
if ( V_69 )
V_20 -> V_35 = V_67 ;
else
F_62 ( V_20 , V_21 , V_22 ) ;
V_18:
* V_66 = V_20 ;
return V_10 ;
}
static int F_73 ( unsigned long V_21 , T_5 V_76 , int V_77 )
{
unsigned long V_78 , V_22 , V_79 ;
struct V_19 * V_20 , * V_66 ;
int error ;
F_34 ( V_21 & ~ V_29 ) ;
F_34 ( V_76 != F_74 ( V_76 ) ) ;
V_22 = V_21 + V_76 ;
if ( V_22 < V_21 )
return - V_80 ;
if ( V_22 == V_21 )
return 0 ;
V_20 = F_75 ( V_42 -> V_25 , V_21 ) ;
if ( ! V_20 || V_20 -> V_30 > V_21 )
return - V_45 ;
V_66 = V_20 -> V_81 ;
if ( V_21 > V_20 -> V_30 )
V_66 = V_20 ;
for ( V_78 = V_21 ; ; ) {
T_3 V_67 ;
V_67 = V_20 -> V_35 & ~ V_59 ;
if ( V_77 )
V_67 |= V_59 ;
V_79 = V_20 -> V_31 ;
if ( V_79 > V_22 )
V_79 = V_22 ;
error = F_67 ( V_20 , & V_66 , V_78 , V_79 , V_67 ) ;
if ( error )
break;
V_78 = V_79 ;
if ( V_78 < V_66 -> V_31 )
V_78 = V_66 -> V_31 ;
if ( V_78 >= V_22 )
break;
V_20 = V_66 -> V_82 ;
if ( ! V_20 || V_20 -> V_30 != V_78 ) {
error = - V_45 ;
break;
}
}
return error ;
}
int F_76 ( unsigned long V_21 , unsigned long V_76 , int V_83 )
{
struct V_24 * V_25 = V_42 -> V_25 ;
unsigned long V_22 , V_78 , V_84 ;
struct V_19 * V_20 = NULL ;
int V_85 = 0 ;
long V_10 = 0 ;
F_34 ( V_21 & ~ V_29 ) ;
F_34 ( V_76 != F_74 ( V_76 ) ) ;
V_22 = V_21 + V_76 ;
for ( V_78 = V_21 ; V_78 < V_22 ; V_78 = V_84 ) {
if ( ! V_85 ) {
V_85 = 1 ;
F_77 ( & V_25 -> V_32 ) ;
V_20 = F_75 ( V_25 , V_78 ) ;
} else if ( V_78 >= V_20 -> V_31 )
V_20 = V_20 -> V_82 ;
if ( ! V_20 || V_20 -> V_30 >= V_22 )
break;
V_84 = F_78 ( V_22 , V_20 -> V_31 ) ;
if ( V_20 -> V_35 & ( V_86 | V_87 ) )
continue;
if ( V_78 < V_20 -> V_30 )
V_78 = V_20 -> V_30 ;
V_10 = F_33 ( V_20 , V_78 , V_84 , & V_85 ) ;
if ( V_10 < 0 ) {
if ( V_83 ) {
V_10 = 0 ;
continue;
}
V_10 = F_37 ( V_10 ) ;
break;
}
V_84 = V_78 + V_10 * V_27 ;
V_10 = 0 ;
}
if ( V_85 )
F_79 ( & V_25 -> V_32 ) ;
return V_10 ;
}
static int F_80 ( int V_88 )
{
struct V_19 * V_20 , * V_66 = NULL ;
if ( V_88 & V_89 )
V_42 -> V_25 -> V_90 |= V_59 ;
else
V_42 -> V_25 -> V_90 &= ~ V_59 ;
if ( V_88 == V_89 )
goto V_18;
for ( V_20 = V_42 -> V_25 -> V_91 ; V_20 ; V_20 = V_66 -> V_82 ) {
T_3 V_67 ;
V_67 = V_20 -> V_35 & ~ V_59 ;
if ( V_88 & V_92 )
V_67 |= V_59 ;
F_67 ( V_20 , & V_66 , V_20 -> V_30 , V_20 -> V_31 , V_67 ) ;
F_66 () ;
}
V_18:
return 0 ;
}
int F_81 ( T_5 V_93 , struct V_94 * V_95 )
{
unsigned long V_96 , V_85 ;
int V_97 = 0 ;
V_85 = ( V_93 + V_27 - 1 ) >> V_65 ;
V_96 = F_3 ( V_2 ) ;
if ( V_96 == V_98 )
V_97 = 1 ;
V_96 >>= V_65 ;
F_82 ( & V_99 ) ;
if ( ! V_97 &&
V_85 + V_95 -> V_100 > V_96 && ! F_2 ( V_1 ) )
goto V_18;
F_83 ( V_95 ) ;
V_95 -> V_100 += V_85 ;
V_97 = 1 ;
V_18:
F_84 ( & V_99 ) ;
return V_97 ;
}
void F_85 ( T_5 V_93 , struct V_94 * V_95 )
{
F_82 ( & V_99 ) ;
V_95 -> V_100 -= ( V_93 + V_27 - 1 ) >> V_65 ;
F_84 ( & V_99 ) ;
F_86 ( V_95 ) ;
}
