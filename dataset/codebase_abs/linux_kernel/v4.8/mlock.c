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
int V_10 = V_11 ;
if ( F_30 ( V_3 ) > 1 )
V_10 = F_31 ( V_3 ) ;
if ( V_10 != V_12 )
F_9 ( V_13 ) ;
F_11 ( V_3 ) ;
}
static void F_32 ( struct V_3 * V_3 )
{
if ( F_12 ( V_3 ) )
F_33 ( V_6 ) ;
else
F_33 ( V_13 ) ;
}
unsigned int F_34 ( struct V_3 * V_3 )
{
int V_14 ;
struct V_15 * V_15 = F_7 ( V_3 ) ;
F_14 ( ! F_15 ( V_3 ) ) ;
F_16 ( F_17 ( V_3 ) , V_3 ) ;
F_35 ( F_36 ( V_15 ) ) ;
V_14 = F_8 ( V_3 ) ;
if ( ! F_5 ( V_3 ) )
goto V_16;
F_37 ( V_15 , V_4 , - V_14 ) ;
if ( F_21 ( V_3 , true ) ) {
F_38 ( F_36 ( V_15 ) ) ;
F_29 ( V_3 ) ;
goto V_17;
}
F_32 ( V_3 ) ;
V_16:
F_38 ( F_36 ( V_15 ) ) ;
V_17:
return V_14 - 1 ;
}
static int F_39 ( long V_18 )
{
if ( V_18 == - V_19 )
V_18 = - V_20 ;
else if ( V_18 == - V_20 )
V_18 = - V_21 ;
return V_18 ;
}
static bool F_40 ( struct V_3 * V_3 , struct V_22 * V_23 ,
int * V_24 )
{
F_16 ( F_22 ( V_3 ) , V_3 ) ;
F_16 ( ! F_15 ( V_3 ) , V_3 ) ;
if ( F_30 ( V_3 ) <= 1 && F_41 ( V_3 ) ) {
F_42 ( V_23 , V_3 ) ;
if ( F_43 ( V_3 ) )
( * V_24 ) ++ ;
F_44 ( V_3 ) ;
return true ;
}
return false ;
}
static void F_45 ( struct V_22 * V_23 , int V_24 )
{
F_46 ( V_13 , F_47 ( V_23 ) ) ;
F_48 ( V_23 ) ;
F_46 ( V_25 , V_24 ) ;
}
static void F_49 ( struct V_22 * V_23 , struct V_15 * V_15 )
{
int V_26 ;
int V_27 = F_47 ( V_23 ) ;
int V_28 ;
struct V_22 V_29 ;
int V_24 = 0 ;
F_50 ( & V_29 , 0 ) ;
F_35 ( F_36 ( V_15 ) ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
struct V_3 * V_3 = V_23 -> V_30 [ V_26 ] ;
if ( F_5 ( V_3 ) ) {
if ( F_21 ( V_3 , false ) )
continue;
else
F_32 ( V_3 ) ;
}
F_42 ( & V_29 , V_23 -> V_30 [ V_26 ] ) ;
V_23 -> V_30 [ V_26 ] = NULL ;
}
V_28 = - V_27 + F_47 ( & V_29 ) ;
F_37 ( V_15 , V_4 , V_28 ) ;
F_38 ( F_36 ( V_15 ) ) ;
F_51 ( & V_29 ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
struct V_3 * V_3 = V_23 -> V_30 [ V_26 ] ;
if ( V_3 ) {
F_52 ( V_3 ) ;
if ( ! F_40 ( V_3 , & V_29 ,
& V_24 ) ) {
F_25 ( V_3 ) ;
F_29 ( V_3 ) ;
F_44 ( V_3 ) ;
F_53 ( V_3 ) ;
}
}
}
if ( F_47 ( & V_29 ) )
F_45 ( & V_29 , V_24 ) ;
}
static unsigned long F_54 ( struct V_22 * V_23 ,
struct V_31 * V_32 , int V_33 , unsigned long V_34 ,
unsigned long V_35 )
{
T_1 * V_36 ;
T_2 * V_37 ;
V_36 = F_55 ( V_32 -> V_38 , V_34 , & V_37 ) ;
V_35 = F_56 ( V_34 , V_35 ) ;
V_35 = F_57 ( V_34 , V_35 ) ;
V_35 = F_58 ( V_34 , V_35 ) ;
V_34 += V_39 ;
while ( V_34 < V_35 ) {
struct V_3 * V_3 = NULL ;
V_36 ++ ;
if ( F_59 ( * V_36 ) )
V_3 = F_60 ( V_32 , V_34 , * V_36 ) ;
if ( ! V_3 || F_61 ( V_3 ) != V_33 )
break;
if ( F_62 ( V_3 ) )
break;
F_25 ( V_3 ) ;
V_34 += V_39 ;
if ( F_42 ( V_23 , V_3 ) == 0 )
break;
}
F_63 ( V_36 , V_37 ) ;
return V_34 ;
}
void F_64 ( struct V_31 * V_32 ,
unsigned long V_34 , unsigned long V_35 )
{
V_32 -> V_40 &= V_41 ;
while ( V_34 < V_35 ) {
struct V_3 * V_3 ;
unsigned int V_42 ;
unsigned long V_43 ;
struct V_22 V_23 ;
struct V_15 * V_15 ;
int V_33 ;
F_50 ( & V_23 , 0 ) ;
V_3 = F_65 ( V_32 , V_34 , V_44 | V_45 ,
& V_42 ) ;
if ( V_3 && ! F_66 ( V_3 ) ) {
if ( F_67 ( V_3 ) ) {
F_16 ( F_68 ( V_3 ) , V_3 ) ;
F_53 ( V_3 ) ;
} else if ( F_69 ( V_3 ) ) {
F_52 ( V_3 ) ;
V_42 = F_34 ( V_3 ) ;
F_44 ( V_3 ) ;
F_53 ( V_3 ) ;
} else {
F_42 ( & V_23 , V_3 ) ;
V_15 = F_7 ( V_3 ) ;
V_33 = F_61 ( V_3 ) ;
V_34 = F_54 ( & V_23 , V_32 ,
V_33 , V_34 , V_35 ) ;
F_49 ( & V_23 , V_15 ) ;
goto V_46;
}
}
V_43 = 1 + V_42 ;
V_34 += V_43 * V_39 ;
V_46:
F_70 () ;
}
}
static int F_71 ( struct V_31 * V_32 , struct V_31 * * V_47 ,
unsigned long V_34 , unsigned long V_35 , T_3 V_48 )
{
struct V_49 * V_50 = V_32 -> V_38 ;
T_4 V_51 ;
int V_14 ;
int V_10 = 0 ;
int V_52 = ! ! ( V_48 & V_53 ) ;
if ( V_48 == V_32 -> V_40 || ( V_32 -> V_40 & V_54 ) ||
F_72 ( V_32 ) || V_32 == F_73 ( V_55 -> V_50 ) )
goto V_17;
V_51 = V_32 -> V_56 + ( ( V_34 - V_32 -> V_57 ) >> V_58 ) ;
* V_47 = F_74 ( V_50 , * V_47 , V_34 , V_35 , V_48 , V_32 -> V_59 ,
V_32 -> V_60 , V_51 , F_75 ( V_32 ) ,
V_32 -> V_61 ) ;
if ( * V_47 ) {
V_32 = * V_47 ;
goto V_62;
}
if ( V_34 != V_32 -> V_57 ) {
V_10 = F_76 ( V_50 , V_32 , V_34 , 1 ) ;
if ( V_10 )
goto V_17;
}
if ( V_35 != V_32 -> V_63 ) {
V_10 = F_76 ( V_50 , V_32 , V_35 , 0 ) ;
if ( V_10 )
goto V_17;
}
V_62:
V_14 = ( V_35 - V_34 ) >> V_58 ;
if ( ! V_52 )
V_14 = - V_14 ;
V_50 -> V_64 += V_14 ;
if ( V_52 )
V_32 -> V_40 = V_48 ;
else
F_64 ( V_32 , V_34 , V_35 ) ;
V_17:
* V_47 = V_32 ;
return V_10 ;
}
static int F_77 ( unsigned long V_34 , T_5 V_65 ,
T_3 V_66 )
{
unsigned long V_67 , V_35 , V_68 ;
struct V_31 * V_32 , * V_47 ;
int error ;
F_78 ( F_79 ( V_34 ) ) ;
F_78 ( V_65 != F_80 ( V_65 ) ) ;
V_35 = V_34 + V_65 ;
if ( V_35 < V_34 )
return - V_69 ;
if ( V_35 == V_34 )
return 0 ;
V_32 = F_81 ( V_55 -> V_50 , V_34 ) ;
if ( ! V_32 || V_32 -> V_57 > V_34 )
return - V_20 ;
V_47 = V_32 -> V_70 ;
if ( V_34 > V_32 -> V_57 )
V_47 = V_32 ;
for ( V_67 = V_34 ; ; ) {
T_3 V_48 = V_32 -> V_40 & V_41 ;
V_48 |= V_66 ;
V_68 = V_32 -> V_63 ;
if ( V_68 > V_35 )
V_68 = V_35 ;
error = F_71 ( V_32 , & V_47 , V_67 , V_68 , V_48 ) ;
if ( error )
break;
V_67 = V_68 ;
if ( V_67 < V_47 -> V_63 )
V_67 = V_47 -> V_63 ;
if ( V_67 >= V_35 )
break;
V_32 = V_47 -> V_71 ;
if ( ! V_32 || V_32 -> V_57 != V_67 ) {
error = - V_20 ;
break;
}
}
return error ;
}
static T_6 int F_82 ( unsigned long V_34 , T_5 V_65 , T_3 V_66 )
{
unsigned long V_72 ;
unsigned long V_73 ;
int error = - V_20 ;
if ( ! F_1 () )
return - V_74 ;
F_83 () ;
V_65 = F_80 ( V_65 + ( F_79 ( V_34 ) ) ) ;
V_34 &= V_75 ;
V_73 = F_2 ( V_1 ) ;
V_73 >>= V_58 ;
V_72 = V_65 >> V_58 ;
if ( F_84 ( & V_55 -> V_50 -> V_76 ) )
return - V_77 ;
V_72 += V_55 -> V_50 -> V_64 ;
if ( ( V_72 <= V_73 ) || F_3 ( V_2 ) )
error = F_77 ( V_34 , V_65 , V_66 ) ;
F_85 ( & V_55 -> V_50 -> V_76 ) ;
if ( error )
return error ;
error = F_86 ( V_34 , V_65 , 0 ) ;
if ( error )
return F_39 ( error ) ;
return 0 ;
}
static int F_87 ( int V_66 )
{
struct V_31 * V_32 , * V_47 = NULL ;
T_3 V_78 = 0 ;
V_55 -> V_50 -> V_79 &= V_41 ;
if ( V_66 & V_80 ) {
V_55 -> V_50 -> V_79 |= V_53 ;
if ( V_66 & V_81 )
V_55 -> V_50 -> V_79 |= V_82 ;
if ( ! ( V_66 & V_83 ) )
goto V_17;
}
if ( V_66 & V_83 ) {
V_78 |= V_53 ;
if ( V_66 & V_81 )
V_78 |= V_82 ;
}
for ( V_32 = V_55 -> V_50 -> V_84 ; V_32 ; V_32 = V_47 -> V_71 ) {
T_3 V_48 ;
V_48 = V_32 -> V_40 & V_41 ;
V_48 |= V_78 ;
F_71 ( V_32 , & V_47 , V_32 -> V_57 , V_32 -> V_63 , V_48 ) ;
F_88 () ;
}
V_17:
return 0 ;
}
int F_89 ( T_5 V_85 , struct V_86 * V_87 )
{
unsigned long V_73 , V_72 ;
int V_88 = 0 ;
V_72 = ( V_85 + V_39 - 1 ) >> V_58 ;
V_73 = F_2 ( V_1 ) ;
if ( V_73 == V_89 )
V_88 = 1 ;
V_73 >>= V_58 ;
F_90 ( & V_90 ) ;
if ( ! V_88 &&
V_72 + V_87 -> V_91 > V_73 && ! F_3 ( V_2 ) )
goto V_17;
F_91 ( V_87 ) ;
V_87 -> V_91 += V_72 ;
V_88 = 1 ;
V_17:
F_92 ( & V_90 ) ;
return V_88 ;
}
void F_93 ( T_5 V_85 , struct V_86 * V_87 )
{
F_90 ( & V_90 ) ;
V_87 -> V_91 -= ( V_85 + V_39 - 1 ) >> V_58 ;
F_92 ( & V_90 ) ;
F_94 ( V_87 ) ;
}
