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
struct V_28 * V_29 , int V_30 , unsigned long V_31 ,
unsigned long V_32 )
{
T_1 * V_33 ;
T_2 * V_34 ;
V_33 = F_56 ( V_29 -> V_35 , V_31 , & V_34 ) ;
V_32 = F_57 ( V_31 , V_32 ) ;
V_32 = F_58 ( V_31 , V_32 ) ;
V_32 = F_59 ( V_31 , V_32 ) ;
V_32 = F_60 ( V_31 , V_32 ) ;
V_31 += V_36 ;
while ( V_31 < V_32 ) {
struct V_3 * V_3 = NULL ;
V_33 ++ ;
if ( F_61 ( * V_33 ) )
V_3 = F_62 ( V_29 , V_31 , * V_33 ) ;
if ( ! V_3 || F_63 ( V_3 ) != V_30 )
break;
if ( F_64 ( V_3 ) )
break;
F_25 ( V_3 ) ;
V_31 += V_36 ;
if ( F_43 ( V_20 , V_3 ) == 0 )
break;
}
F_65 ( V_33 , V_34 ) ;
return V_31 ;
}
void F_66 ( struct V_28 * V_29 ,
unsigned long V_31 , unsigned long V_32 )
{
V_29 -> V_37 &= V_38 ;
while ( V_31 < V_32 ) {
struct V_3 * V_3 ;
unsigned int V_39 = 0 ;
unsigned long V_40 ;
struct V_19 V_20 ;
struct V_12 * V_12 ;
int V_30 ;
F_51 ( & V_20 , 0 ) ;
V_3 = F_67 ( V_29 , V_31 , V_41 | V_42 ) ;
if ( V_3 && ! F_68 ( V_3 ) ) {
if ( F_69 ( V_3 ) ) {
F_16 ( F_32 ( V_3 ) , V_3 ) ;
F_54 ( V_3 ) ;
} else if ( F_70 ( V_3 ) ) {
F_53 ( V_3 ) ;
V_39 = F_35 ( V_3 ) ;
F_45 ( V_3 ) ;
F_54 ( V_3 ) ;
} else {
F_43 ( & V_20 , V_3 ) ;
V_12 = F_7 ( V_3 ) ;
V_30 = F_63 ( V_3 ) ;
V_31 = F_55 ( & V_20 , V_29 ,
V_30 , V_31 , V_32 ) ;
F_50 ( & V_20 , V_12 ) ;
goto V_43;
}
}
V_40 = 1 + V_39 ;
V_31 += V_40 * V_36 ;
V_43:
F_71 () ;
}
}
static int F_72 ( struct V_28 * V_29 , struct V_28 * * V_44 ,
unsigned long V_31 , unsigned long V_32 , T_3 V_45 )
{
struct V_46 * V_47 = V_29 -> V_35 ;
T_4 V_48 ;
int V_11 ;
int V_49 = 0 ;
int V_50 = ! ! ( V_45 & V_51 ) ;
T_3 V_52 = V_29 -> V_37 ;
if ( V_45 == V_29 -> V_37 || ( V_29 -> V_37 & V_53 ) ||
F_73 ( V_29 ) || V_29 == F_74 ( V_54 -> V_47 ) )
goto V_14;
V_48 = V_29 -> V_55 + ( ( V_31 - V_29 -> V_56 ) >> V_57 ) ;
* V_44 = F_75 ( V_47 , * V_44 , V_31 , V_32 , V_45 , V_29 -> V_58 ,
V_29 -> V_59 , V_48 , F_76 ( V_29 ) ,
V_29 -> V_60 ) ;
if ( * V_44 ) {
V_29 = * V_44 ;
goto V_61;
}
if ( V_31 != V_29 -> V_56 ) {
V_49 = F_77 ( V_47 , V_29 , V_31 , 1 ) ;
if ( V_49 )
goto V_14;
}
if ( V_32 != V_29 -> V_62 ) {
V_49 = F_77 ( V_47 , V_29 , V_32 , 0 ) ;
if ( V_49 )
goto V_14;
}
V_61:
V_11 = ( V_32 - V_31 ) >> V_57 ;
if ( ! V_50 )
V_11 = - V_11 ;
else if ( V_52 & V_51 )
V_11 = 0 ;
V_47 -> V_63 += V_11 ;
if ( V_50 )
V_29 -> V_37 = V_45 ;
else
F_66 ( V_29 , V_31 , V_32 ) ;
V_14:
* V_44 = V_29 ;
return V_49 ;
}
static int F_78 ( unsigned long V_31 , T_5 V_64 ,
T_3 V_65 )
{
unsigned long V_66 , V_32 , V_67 ;
struct V_28 * V_29 , * V_44 ;
int error ;
F_79 ( F_80 ( V_31 ) ) ;
F_79 ( V_64 != F_81 ( V_64 ) ) ;
V_32 = V_31 + V_64 ;
if ( V_32 < V_31 )
return - V_68 ;
if ( V_32 == V_31 )
return 0 ;
V_29 = F_82 ( V_54 -> V_47 , V_31 ) ;
if ( ! V_29 || V_29 -> V_56 > V_31 )
return - V_17 ;
V_44 = V_29 -> V_69 ;
if ( V_31 > V_29 -> V_56 )
V_44 = V_29 ;
for ( V_66 = V_31 ; ; ) {
T_3 V_45 = V_29 -> V_37 & V_38 ;
V_45 |= V_65 ;
V_67 = V_29 -> V_62 ;
if ( V_67 > V_32 )
V_67 = V_32 ;
error = F_72 ( V_29 , & V_44 , V_66 , V_67 , V_45 ) ;
if ( error )
break;
V_66 = V_67 ;
if ( V_66 < V_44 -> V_62 )
V_66 = V_44 -> V_62 ;
if ( V_66 >= V_32 )
break;
V_29 = V_44 -> V_70 ;
if ( ! V_29 || V_29 -> V_56 != V_66 ) {
error = - V_17 ;
break;
}
}
return error ;
}
static int F_83 ( struct V_46 * V_47 ,
unsigned long V_31 , T_5 V_64 )
{
struct V_28 * V_29 ;
int V_71 = 0 ;
if ( V_47 == NULL )
V_47 = V_54 -> V_47 ;
V_29 = F_82 ( V_47 , V_31 ) ;
if ( V_29 == NULL )
V_29 = V_47 -> V_72 ;
for (; V_29 ; V_29 = V_29 -> V_70 ) {
if ( V_31 >= V_29 -> V_62 )
continue;
if ( V_31 + V_64 <= V_29 -> V_56 )
break;
if ( V_29 -> V_37 & V_51 ) {
if ( V_31 > V_29 -> V_56 )
V_71 -= ( V_31 - V_29 -> V_56 ) ;
if ( V_31 + V_64 < V_29 -> V_62 ) {
V_71 += V_31 + V_64 - V_29 -> V_56 ;
break;
}
V_71 += V_29 -> V_62 - V_29 -> V_56 ;
}
}
return V_71 >> V_57 ;
}
static T_6 int F_84 ( unsigned long V_31 , T_5 V_64 , T_3 V_65 )
{
unsigned long V_73 ;
unsigned long V_74 ;
int error = - V_17 ;
if ( ! F_1 () )
return - V_75 ;
F_85 () ;
V_64 = F_81 ( V_64 + ( F_80 ( V_31 ) ) ) ;
V_31 &= V_76 ;
V_74 = F_2 ( V_1 ) ;
V_74 >>= V_57 ;
V_73 = V_64 >> V_57 ;
if ( F_86 ( & V_54 -> V_47 -> V_77 ) )
return - V_78 ;
V_73 += V_54 -> V_47 -> V_63 ;
if ( ( V_73 > V_74 ) && ( ! F_3 ( V_2 ) ) ) {
V_73 -= F_83 ( V_54 -> V_47 ,
V_31 , V_64 ) ;
}
if ( ( V_73 <= V_74 ) || F_3 ( V_2 ) )
error = F_78 ( V_31 , V_64 , V_65 ) ;
F_87 ( & V_54 -> V_47 -> V_77 ) ;
if ( error )
return error ;
error = F_88 ( V_31 , V_64 , 0 ) ;
if ( error )
return F_40 ( error ) ;
return 0 ;
}
static int F_89 ( int V_65 )
{
struct V_28 * V_29 , * V_44 = NULL ;
T_3 V_79 = 0 ;
V_54 -> V_47 -> V_80 &= V_38 ;
if ( V_65 & V_81 ) {
V_54 -> V_47 -> V_80 |= V_51 ;
if ( V_65 & V_82 )
V_54 -> V_47 -> V_80 |= V_83 ;
if ( ! ( V_65 & V_84 ) )
goto V_14;
}
if ( V_65 & V_84 ) {
V_79 |= V_51 ;
if ( V_65 & V_82 )
V_79 |= V_83 ;
}
for ( V_29 = V_54 -> V_47 -> V_72 ; V_29 ; V_29 = V_44 -> V_70 ) {
T_3 V_45 ;
V_45 = V_29 -> V_37 & V_38 ;
V_45 |= V_79 ;
F_72 ( V_29 , & V_44 , V_29 -> V_56 , V_29 -> V_62 , V_45 ) ;
F_90 () ;
}
V_14:
return 0 ;
}
int F_91 ( T_5 V_85 , struct V_86 * V_87 )
{
unsigned long V_74 , V_73 ;
int V_88 = 0 ;
V_73 = ( V_85 + V_36 - 1 ) >> V_57 ;
V_74 = F_2 ( V_1 ) ;
if ( V_74 == V_89 )
V_88 = 1 ;
V_74 >>= V_57 ;
F_92 ( & V_90 ) ;
if ( ! V_88 &&
V_73 + V_87 -> V_91 > V_74 && ! F_3 ( V_2 ) )
goto V_14;
F_93 ( V_87 ) ;
V_87 -> V_91 += V_73 ;
V_88 = 1 ;
V_14:
F_94 ( & V_90 ) ;
return V_88 ;
}
void F_95 ( T_5 V_85 , struct V_86 * V_87 )
{
F_92 ( & V_90 ) ;
V_87 -> V_91 -= ( V_85 + V_36 - 1 ) >> V_57 ;
F_94 ( & V_90 ) ;
F_96 ( V_87 ) ;
}
