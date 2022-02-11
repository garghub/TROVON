bool F_1 ( void )
{
if ( F_2 ( V_1 ) != 0 )
return true ;
if ( F_3 ( V_2 ) )
return true ;
return false ;
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
F_16 ( F_17 ( V_3 ) , V_3 ) ;
F_16 ( F_18 ( V_3 ) && F_19 ( V_3 ) , V_3 ) ;
if ( ! F_20 ( V_3 ) ) {
F_6 ( F_7 ( V_3 ) , V_4 ,
F_8 ( V_3 ) ) ;
F_9 ( V_7 ) ;
if ( ! F_10 ( V_3 ) )
F_11 ( V_3 ) ;
}
}
static bool F_21 ( struct V_3 * V_3 , bool V_8 )
{
if ( F_22 ( V_3 ) ) {
struct V_9 * V_9 ;
V_9 = F_23 ( V_3 , F_24 ( V_3 ) ) ;
if ( V_8 )
F_25 ( V_3 ) ;
F_26 ( V_3 ) ;
F_27 ( V_3 , V_9 , F_28 ( V_3 ) ) ;
return true ;
}
return false ;
}
static void F_29 ( struct V_3 * V_3 )
{
if ( F_30 ( V_3 ) > 1 )
F_31 ( V_3 ) ;
if ( ! F_32 ( V_3 ) )
F_9 ( V_10 ) ;
F_11 ( V_3 ) ;
}
static void F_33 ( struct V_3 * V_3 )
{
if ( F_12 ( V_3 ) )
F_34 ( V_6 ) ;
else
F_34 ( V_10 ) ;
}
unsigned int F_35 ( struct V_3 * V_3 )
{
int V_11 ;
struct V_12 * V_12 = F_7 ( V_3 ) ;
F_14 ( ! F_15 ( V_3 ) ) ;
F_16 ( F_17 ( V_3 ) , V_3 ) ;
F_36 ( F_37 ( V_12 ) ) ;
if ( ! F_5 ( V_3 ) ) {
V_11 = 1 ;
goto V_13;
}
V_11 = F_8 ( V_3 ) ;
F_38 ( V_12 , V_4 , - V_11 ) ;
if ( F_21 ( V_3 , true ) ) {
F_39 ( F_37 ( V_12 ) ) ;
F_29 ( V_3 ) ;
goto V_14;
}
F_33 ( V_3 ) ;
V_13:
F_39 ( F_37 ( V_12 ) ) ;
V_14:
return V_11 - 1 ;
}
static int F_40 ( long V_15 )
{
if ( V_15 == - V_16 )
V_15 = - V_17 ;
else if ( V_15 == - V_17 )
V_15 = - V_18 ;
return V_15 ;
}
static bool F_41 ( struct V_3 * V_3 , struct V_19 * V_20 ,
int * V_21 )
{
F_16 ( F_22 ( V_3 ) , V_3 ) ;
F_16 ( ! F_15 ( V_3 ) , V_3 ) ;
if ( F_30 ( V_3 ) <= 1 && F_42 ( V_3 ) ) {
F_43 ( V_20 , V_3 ) ;
if ( F_44 ( V_3 ) )
( * V_21 ) ++ ;
F_45 ( V_3 ) ;
return true ;
}
return false ;
}
static void F_46 ( struct V_19 * V_20 , int V_21 )
{
F_47 ( V_10 , F_48 ( V_20 ) ) ;
F_49 ( V_20 ) ;
F_47 ( V_22 , V_21 ) ;
}
static void F_50 ( struct V_19 * V_20 , struct V_12 * V_12 )
{
int V_23 ;
int V_24 = F_48 ( V_20 ) ;
int V_25 = - V_24 ;
struct V_19 V_26 ;
int V_21 = 0 ;
F_51 ( & V_26 , 0 ) ;
F_36 ( F_37 ( V_12 ) ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
struct V_3 * V_3 = V_20 -> V_27 [ V_23 ] ;
if ( F_5 ( V_3 ) ) {
if ( F_21 ( V_3 , false ) )
continue;
else
F_33 ( V_3 ) ;
} else {
V_25 ++ ;
}
F_43 ( & V_26 , V_20 -> V_27 [ V_23 ] ) ;
V_20 -> V_27 [ V_23 ] = NULL ;
}
F_38 ( V_12 , V_4 , V_25 ) ;
F_39 ( F_37 ( V_12 ) ) ;
F_52 ( & V_26 ) ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
struct V_3 * V_3 = V_20 -> V_27 [ V_23 ] ;
if ( V_3 ) {
F_53 ( V_3 ) ;
if ( ! F_41 ( V_3 , & V_26 ,
& V_21 ) ) {
F_25 ( V_3 ) ;
F_29 ( V_3 ) ;
F_45 ( V_3 ) ;
F_54 ( V_3 ) ;
}
}
}
if ( F_48 ( & V_26 ) )
F_46 ( & V_26 , V_21 ) ;
}
static unsigned long F_55 ( struct V_19 * V_20 ,
struct V_28 * V_29 , struct V_12 * V_12 ,
unsigned long V_30 , unsigned long V_31 )
{
T_1 * V_32 ;
T_2 * V_33 ;
V_32 = F_56 ( V_29 -> V_34 , V_30 , & V_33 ) ;
V_31 = F_57 ( V_30 , V_31 ) ;
V_31 = F_58 ( V_30 , V_31 ) ;
V_31 = F_59 ( V_30 , V_31 ) ;
V_31 = F_60 ( V_30 , V_31 ) ;
V_30 += V_35 ;
while ( V_30 < V_31 ) {
struct V_3 * V_3 = NULL ;
V_32 ++ ;
if ( F_61 ( * V_32 ) )
V_3 = F_62 ( V_29 , V_30 , * V_32 ) ;
if ( ! V_3 || F_7 ( V_3 ) != V_12 )
break;
if ( F_63 ( V_3 ) )
break;
F_25 ( V_3 ) ;
V_30 += V_35 ;
if ( F_43 ( V_20 , V_3 ) == 0 )
break;
}
F_64 ( V_32 , V_33 ) ;
return V_30 ;
}
void F_65 ( struct V_28 * V_29 ,
unsigned long V_30 , unsigned long V_31 )
{
V_29 -> V_36 &= V_37 ;
while ( V_30 < V_31 ) {
struct V_3 * V_3 ;
unsigned int V_38 = 0 ;
unsigned long V_39 ;
struct V_19 V_20 ;
struct V_12 * V_12 ;
F_51 ( & V_20 , 0 ) ;
V_3 = F_66 ( V_29 , V_30 , V_40 | V_41 ) ;
if ( V_3 && ! F_67 ( V_3 ) ) {
if ( F_68 ( V_3 ) ) {
F_16 ( F_32 ( V_3 ) , V_3 ) ;
F_54 ( V_3 ) ;
} else if ( F_69 ( V_3 ) ) {
F_53 ( V_3 ) ;
V_38 = F_35 ( V_3 ) ;
F_45 ( V_3 ) ;
F_54 ( V_3 ) ;
} else {
F_43 ( & V_20 , V_3 ) ;
V_12 = F_7 ( V_3 ) ;
V_30 = F_55 ( & V_20 , V_29 ,
V_12 , V_30 , V_31 ) ;
F_50 ( & V_20 , V_12 ) ;
goto V_42;
}
}
V_39 = 1 + V_38 ;
V_30 += V_39 * V_35 ;
V_42:
F_70 () ;
}
}
static int F_71 ( struct V_28 * V_29 , struct V_28 * * V_43 ,
unsigned long V_30 , unsigned long V_31 , T_3 V_44 )
{
struct V_45 * V_46 = V_29 -> V_34 ;
T_4 V_47 ;
int V_11 ;
int V_48 = 0 ;
int V_49 = ! ! ( V_44 & V_50 ) ;
T_3 V_51 = V_29 -> V_36 ;
if ( V_44 == V_29 -> V_36 || ( V_29 -> V_36 & V_52 ) ||
F_72 ( V_29 ) || V_29 == F_73 ( V_53 -> V_46 ) )
goto V_14;
V_47 = V_29 -> V_54 + ( ( V_30 - V_29 -> V_55 ) >> V_56 ) ;
* V_43 = F_74 ( V_46 , * V_43 , V_30 , V_31 , V_44 , V_29 -> V_57 ,
V_29 -> V_58 , V_47 , F_75 ( V_29 ) ,
V_29 -> V_59 ) ;
if ( * V_43 ) {
V_29 = * V_43 ;
goto V_60;
}
if ( V_30 != V_29 -> V_55 ) {
V_48 = F_76 ( V_46 , V_29 , V_30 , 1 ) ;
if ( V_48 )
goto V_14;
}
if ( V_31 != V_29 -> V_61 ) {
V_48 = F_76 ( V_46 , V_29 , V_31 , 0 ) ;
if ( V_48 )
goto V_14;
}
V_60:
V_11 = ( V_31 - V_30 ) >> V_56 ;
if ( ! V_49 )
V_11 = - V_11 ;
else if ( V_51 & V_50 )
V_11 = 0 ;
V_46 -> V_62 += V_11 ;
if ( V_49 )
V_29 -> V_36 = V_44 ;
else
F_65 ( V_29 , V_30 , V_31 ) ;
V_14:
* V_43 = V_29 ;
return V_48 ;
}
static int F_77 ( unsigned long V_30 , T_5 V_63 ,
T_3 V_64 )
{
unsigned long V_65 , V_31 , V_66 ;
struct V_28 * V_29 , * V_43 ;
int error ;
F_78 ( F_79 ( V_30 ) ) ;
F_78 ( V_63 != F_80 ( V_63 ) ) ;
V_31 = V_30 + V_63 ;
if ( V_31 < V_30 )
return - V_67 ;
if ( V_31 == V_30 )
return 0 ;
V_29 = F_81 ( V_53 -> V_46 , V_30 ) ;
if ( ! V_29 || V_29 -> V_55 > V_30 )
return - V_17 ;
V_43 = V_29 -> V_68 ;
if ( V_30 > V_29 -> V_55 )
V_43 = V_29 ;
for ( V_65 = V_30 ; ; ) {
T_3 V_44 = V_29 -> V_36 & V_37 ;
V_44 |= V_64 ;
V_66 = V_29 -> V_61 ;
if ( V_66 > V_31 )
V_66 = V_31 ;
error = F_71 ( V_29 , & V_43 , V_65 , V_66 , V_44 ) ;
if ( error )
break;
V_65 = V_66 ;
if ( V_65 < V_43 -> V_61 )
V_65 = V_43 -> V_61 ;
if ( V_65 >= V_31 )
break;
V_29 = V_43 -> V_69 ;
if ( ! V_29 || V_29 -> V_55 != V_65 ) {
error = - V_17 ;
break;
}
}
return error ;
}
static int F_82 ( struct V_45 * V_46 ,
unsigned long V_30 , T_5 V_63 )
{
struct V_28 * V_29 ;
int V_70 = 0 ;
if ( V_46 == NULL )
V_46 = V_53 -> V_46 ;
V_29 = F_81 ( V_46 , V_30 ) ;
if ( V_29 == NULL )
V_29 = V_46 -> V_71 ;
for (; V_29 ; V_29 = V_29 -> V_69 ) {
if ( V_30 >= V_29 -> V_61 )
continue;
if ( V_30 + V_63 <= V_29 -> V_55 )
break;
if ( V_29 -> V_36 & V_50 ) {
if ( V_30 > V_29 -> V_55 )
V_70 -= ( V_30 - V_29 -> V_55 ) ;
if ( V_30 + V_63 < V_29 -> V_61 ) {
V_70 += V_30 + V_63 - V_29 -> V_55 ;
break;
}
V_70 += V_29 -> V_61 - V_29 -> V_55 ;
}
}
return V_70 >> V_56 ;
}
static T_6 int F_83 ( unsigned long V_30 , T_5 V_63 , T_3 V_64 )
{
unsigned long V_72 ;
unsigned long V_73 ;
int error = - V_17 ;
if ( ! F_1 () )
return - V_74 ;
F_84 () ;
V_63 = F_80 ( V_63 + ( F_79 ( V_30 ) ) ) ;
V_30 &= V_75 ;
V_73 = F_2 ( V_1 ) ;
V_73 >>= V_56 ;
V_72 = V_63 >> V_56 ;
if ( F_85 ( & V_53 -> V_46 -> V_76 ) )
return - V_77 ;
V_72 += V_53 -> V_46 -> V_62 ;
if ( ( V_72 > V_73 ) && ( ! F_3 ( V_2 ) ) ) {
V_72 -= F_82 ( V_53 -> V_46 ,
V_30 , V_63 ) ;
}
if ( ( V_72 <= V_73 ) || F_3 ( V_2 ) )
error = F_77 ( V_30 , V_63 , V_64 ) ;
F_86 ( & V_53 -> V_46 -> V_76 ) ;
if ( error )
return error ;
error = F_87 ( V_30 , V_63 , 0 ) ;
if ( error )
return F_40 ( error ) ;
return 0 ;
}
static int F_88 ( int V_64 )
{
struct V_28 * V_29 , * V_43 = NULL ;
T_3 V_78 = 0 ;
V_53 -> V_46 -> V_79 &= V_37 ;
if ( V_64 & V_80 ) {
V_53 -> V_46 -> V_79 |= V_50 ;
if ( V_64 & V_81 )
V_53 -> V_46 -> V_79 |= V_82 ;
if ( ! ( V_64 & V_83 ) )
goto V_14;
}
if ( V_64 & V_83 ) {
V_78 |= V_50 ;
if ( V_64 & V_81 )
V_78 |= V_82 ;
}
for ( V_29 = V_53 -> V_46 -> V_71 ; V_29 ; V_29 = V_43 -> V_69 ) {
T_3 V_44 ;
V_44 = V_29 -> V_36 & V_37 ;
V_44 |= V_78 ;
F_71 ( V_29 , & V_43 , V_29 -> V_55 , V_29 -> V_61 , V_44 ) ;
F_89 () ;
}
V_14:
return 0 ;
}
int F_90 ( T_5 V_84 , struct V_85 * V_86 )
{
unsigned long V_73 , V_72 ;
int V_87 = 0 ;
V_72 = ( V_84 + V_35 - 1 ) >> V_56 ;
V_73 = F_2 ( V_1 ) ;
if ( V_73 == V_88 )
V_87 = 1 ;
V_73 >>= V_56 ;
F_91 ( & V_89 ) ;
if ( ! V_87 &&
V_72 + V_86 -> V_90 > V_73 && ! F_3 ( V_2 ) )
goto V_14;
F_92 ( V_86 ) ;
V_86 -> V_90 += V_72 ;
V_87 = 1 ;
V_14:
F_93 ( & V_89 ) ;
return V_87 ;
}
void F_94 ( T_5 V_84 , struct V_85 * V_86 )
{
F_91 ( & V_89 ) ;
V_86 -> V_90 -= ( V_84 + V_35 - 1 ) >> V_56 ;
F_93 ( & V_89 ) ;
F_95 ( V_86 ) ;
}
