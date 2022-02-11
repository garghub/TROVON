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
V_9 = F_23 ( V_3 , F_7 ( V_3 ) ) ;
if ( V_8 )
F_24 ( V_3 ) ;
F_25 ( V_3 ) ;
F_26 ( V_3 , V_9 , F_27 ( V_3 ) ) ;
return true ;
}
return false ;
}
static void F_28 ( struct V_3 * V_3 )
{
int V_10 = V_11 ;
if ( F_29 ( V_3 ) > 1 )
V_10 = F_30 ( V_3 ) ;
if ( V_10 != V_12 )
F_9 ( V_13 ) ;
F_11 ( V_3 ) ;
}
static void F_31 ( struct V_3 * V_3 )
{
if ( F_12 ( V_3 ) )
F_32 ( V_6 ) ;
else
F_32 ( V_13 ) ;
}
unsigned int F_33 ( struct V_3 * V_3 )
{
int V_14 ;
struct V_15 * V_15 = F_7 ( V_3 ) ;
F_14 ( ! F_15 ( V_3 ) ) ;
F_16 ( F_17 ( V_3 ) , V_3 ) ;
F_34 ( & V_15 -> V_16 ) ;
V_14 = F_8 ( V_3 ) ;
if ( ! F_5 ( V_3 ) )
goto V_17;
F_35 ( V_15 , V_4 , - V_14 ) ;
if ( F_21 ( V_3 , true ) ) {
F_36 ( & V_15 -> V_16 ) ;
F_28 ( V_3 ) ;
goto V_18;
}
F_31 ( V_3 ) ;
V_17:
F_36 ( & V_15 -> V_16 ) ;
V_18:
return V_14 - 1 ;
}
static int F_37 ( long V_19 )
{
if ( V_19 == - V_20 )
V_19 = - V_21 ;
else if ( V_19 == - V_21 )
V_19 = - V_22 ;
return V_19 ;
}
static bool F_38 ( struct V_3 * V_3 , struct V_23 * V_24 ,
int * V_25 )
{
F_16 ( F_22 ( V_3 ) , V_3 ) ;
F_16 ( ! F_15 ( V_3 ) , V_3 ) ;
if ( F_29 ( V_3 ) <= 1 && F_39 ( V_3 ) ) {
F_40 ( V_24 , V_3 ) ;
if ( F_41 ( V_3 ) )
( * V_25 ) ++ ;
F_42 ( V_3 ) ;
return true ;
}
return false ;
}
static void F_43 ( struct V_23 * V_24 , int V_25 )
{
F_44 ( V_13 , F_45 ( V_24 ) ) ;
F_46 ( V_24 ) ;
F_44 ( V_26 , V_25 ) ;
}
static void F_47 ( struct V_23 * V_24 , struct V_15 * V_15 )
{
int V_27 ;
int V_28 = F_45 ( V_24 ) ;
int V_29 ;
struct V_23 V_30 ;
int V_25 = 0 ;
F_48 ( & V_30 , 0 ) ;
F_34 ( & V_15 -> V_16 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
struct V_3 * V_3 = V_24 -> V_31 [ V_27 ] ;
if ( F_5 ( V_3 ) ) {
if ( F_21 ( V_3 , false ) )
continue;
else
F_31 ( V_3 ) ;
}
F_40 ( & V_30 , V_24 -> V_31 [ V_27 ] ) ;
V_24 -> V_31 [ V_27 ] = NULL ;
}
V_29 = - V_28 + F_45 ( & V_30 ) ;
F_35 ( V_15 , V_4 , V_29 ) ;
F_36 ( & V_15 -> V_16 ) ;
F_49 ( & V_30 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
struct V_3 * V_3 = V_24 -> V_31 [ V_27 ] ;
if ( V_3 ) {
F_50 ( V_3 ) ;
if ( ! F_38 ( V_3 , & V_30 ,
& V_25 ) ) {
F_24 ( V_3 ) ;
F_28 ( V_3 ) ;
F_42 ( V_3 ) ;
F_51 ( V_3 ) ;
}
}
}
if ( F_45 ( & V_30 ) )
F_43 ( & V_30 , V_25 ) ;
}
static unsigned long F_52 ( struct V_23 * V_24 ,
struct V_32 * V_33 , int V_34 , unsigned long V_35 ,
unsigned long V_36 )
{
T_1 * V_37 ;
T_2 * V_38 ;
V_37 = F_53 ( V_33 -> V_39 , V_35 , & V_38 ) ;
V_36 = F_54 ( V_35 , V_36 ) ;
V_36 = F_55 ( V_35 , V_36 ) ;
V_36 = F_56 ( V_35 , V_36 ) ;
V_35 += V_40 ;
while ( V_35 < V_36 ) {
struct V_3 * V_3 = NULL ;
V_37 ++ ;
if ( F_57 ( * V_37 ) )
V_3 = F_58 ( V_33 , V_35 , * V_37 ) ;
if ( ! V_3 || F_59 ( V_3 ) != V_34 )
break;
if ( F_60 ( V_3 ) )
break;
F_24 ( V_3 ) ;
V_35 += V_40 ;
if ( F_40 ( V_24 , V_3 ) == 0 )
break;
}
F_61 ( V_37 , V_38 ) ;
return V_35 ;
}
void F_62 ( struct V_32 * V_33 ,
unsigned long V_35 , unsigned long V_36 )
{
V_33 -> V_41 &= V_42 ;
while ( V_35 < V_36 ) {
struct V_3 * V_3 ;
unsigned int V_43 ;
unsigned long V_44 ;
struct V_23 V_24 ;
struct V_15 * V_15 ;
int V_34 ;
F_48 ( & V_24 , 0 ) ;
V_3 = F_63 ( V_33 , V_35 , V_45 | V_46 ,
& V_43 ) ;
if ( V_3 && ! F_64 ( V_3 ) ) {
if ( F_65 ( V_3 ) ) {
F_16 ( F_66 ( V_3 ) , V_3 ) ;
F_51 ( V_3 ) ;
} else if ( F_67 ( V_3 ) ) {
F_50 ( V_3 ) ;
V_43 = F_33 ( V_3 ) ;
F_42 ( V_3 ) ;
F_51 ( V_3 ) ;
} else {
F_40 ( & V_24 , V_3 ) ;
V_15 = F_7 ( V_3 ) ;
V_34 = F_59 ( V_3 ) ;
V_35 = F_52 ( & V_24 , V_33 ,
V_34 , V_35 , V_36 ) ;
F_47 ( & V_24 , V_15 ) ;
goto V_47;
}
}
V_44 = 1 + V_43 ;
V_35 += V_44 * V_40 ;
V_47:
F_68 () ;
}
}
static int F_69 ( struct V_32 * V_33 , struct V_32 * * V_48 ,
unsigned long V_35 , unsigned long V_36 , T_3 V_49 )
{
struct V_50 * V_51 = V_33 -> V_39 ;
T_4 V_52 ;
int V_14 ;
int V_10 = 0 ;
int V_53 = ! ! ( V_49 & V_54 ) ;
if ( V_49 == V_33 -> V_41 || ( V_33 -> V_41 & V_55 ) ||
F_70 ( V_33 ) || V_33 == F_71 ( V_56 -> V_51 ) )
goto V_18;
V_52 = V_33 -> V_57 + ( ( V_35 - V_33 -> V_58 ) >> V_59 ) ;
* V_48 = F_72 ( V_51 , * V_48 , V_35 , V_36 , V_49 , V_33 -> V_60 ,
V_33 -> V_61 , V_52 , F_73 ( V_33 ) ,
V_33 -> V_62 ) ;
if ( * V_48 ) {
V_33 = * V_48 ;
goto V_63;
}
if ( V_35 != V_33 -> V_58 ) {
V_10 = F_74 ( V_51 , V_33 , V_35 , 1 ) ;
if ( V_10 )
goto V_18;
}
if ( V_36 != V_33 -> V_64 ) {
V_10 = F_74 ( V_51 , V_33 , V_36 , 0 ) ;
if ( V_10 )
goto V_18;
}
V_63:
V_14 = ( V_36 - V_35 ) >> V_59 ;
if ( ! V_53 )
V_14 = - V_14 ;
V_51 -> V_65 += V_14 ;
if ( V_53 )
V_33 -> V_41 = V_49 ;
else
F_62 ( V_33 , V_35 , V_36 ) ;
V_18:
* V_48 = V_33 ;
return V_10 ;
}
static int F_75 ( unsigned long V_35 , T_5 V_66 ,
T_3 V_67 )
{
unsigned long V_68 , V_36 , V_69 ;
struct V_32 * V_33 , * V_48 ;
int error ;
F_76 ( F_77 ( V_35 ) ) ;
F_76 ( V_66 != F_78 ( V_66 ) ) ;
V_36 = V_35 + V_66 ;
if ( V_36 < V_35 )
return - V_70 ;
if ( V_36 == V_35 )
return 0 ;
V_33 = F_79 ( V_56 -> V_51 , V_35 ) ;
if ( ! V_33 || V_33 -> V_58 > V_35 )
return - V_21 ;
V_48 = V_33 -> V_71 ;
if ( V_35 > V_33 -> V_58 )
V_48 = V_33 ;
for ( V_68 = V_35 ; ; ) {
T_3 V_49 = V_33 -> V_41 & V_42 ;
V_49 |= V_67 ;
V_69 = V_33 -> V_64 ;
if ( V_69 > V_36 )
V_69 = V_36 ;
error = F_69 ( V_33 , & V_48 , V_68 , V_69 , V_49 ) ;
if ( error )
break;
V_68 = V_69 ;
if ( V_68 < V_48 -> V_64 )
V_68 = V_48 -> V_64 ;
if ( V_68 >= V_36 )
break;
V_33 = V_48 -> V_72 ;
if ( ! V_33 || V_33 -> V_58 != V_68 ) {
error = - V_21 ;
break;
}
}
return error ;
}
static int F_80 ( unsigned long V_35 , T_5 V_66 , T_3 V_67 )
{
unsigned long V_73 ;
unsigned long V_74 ;
int error = - V_21 ;
if ( ! F_1 () )
return - V_75 ;
F_81 () ;
V_66 = F_78 ( V_66 + ( F_77 ( V_35 ) ) ) ;
V_35 &= V_76 ;
V_74 = F_2 ( V_1 ) ;
V_74 >>= V_59 ;
V_73 = V_66 >> V_59 ;
F_82 ( & V_56 -> V_51 -> V_77 ) ;
V_73 += V_56 -> V_51 -> V_65 ;
if ( ( V_73 <= V_74 ) || F_3 ( V_2 ) )
error = F_75 ( V_35 , V_66 , V_67 ) ;
F_83 ( & V_56 -> V_51 -> V_77 ) ;
if ( error )
return error ;
error = F_84 ( V_35 , V_66 , 0 ) ;
if ( error )
return F_37 ( error ) ;
return 0 ;
}
static int F_85 ( int V_67 )
{
struct V_32 * V_33 , * V_48 = NULL ;
T_3 V_78 = 0 ;
V_56 -> V_51 -> V_79 &= V_42 ;
if ( V_67 & V_80 ) {
V_56 -> V_51 -> V_79 |= V_54 ;
if ( V_67 & V_81 )
V_56 -> V_51 -> V_79 |= V_82 ;
if ( ! ( V_67 & V_83 ) )
goto V_18;
}
if ( V_67 & V_83 ) {
V_78 |= V_54 ;
if ( V_67 & V_81 )
V_78 |= V_82 ;
}
for ( V_33 = V_56 -> V_51 -> V_84 ; V_33 ; V_33 = V_48 -> V_72 ) {
T_3 V_49 ;
V_49 = V_33 -> V_41 & V_42 ;
V_49 |= V_78 ;
F_69 ( V_33 , & V_48 , V_33 -> V_58 , V_33 -> V_64 , V_49 ) ;
F_86 () ;
}
V_18:
return 0 ;
}
int F_87 ( T_5 V_85 , struct V_86 * V_87 )
{
unsigned long V_74 , V_73 ;
int V_88 = 0 ;
V_73 = ( V_85 + V_40 - 1 ) >> V_59 ;
V_74 = F_2 ( V_1 ) ;
if ( V_74 == V_89 )
V_88 = 1 ;
V_74 >>= V_59 ;
F_88 ( & V_90 ) ;
if ( ! V_88 &&
V_73 + V_87 -> V_91 > V_74 && ! F_3 ( V_2 ) )
goto V_18;
F_89 ( V_87 ) ;
V_87 -> V_91 += V_73 ;
V_88 = 1 ;
V_18:
F_90 ( & V_90 ) ;
return V_88 ;
}
void F_91 ( T_5 V_85 , struct V_86 * V_87 )
{
F_88 ( & V_90 ) ;
V_87 -> V_91 -= ( V_85 + V_40 - 1 ) >> V_59 ;
F_90 ( & V_90 ) ;
F_92 ( V_87 ) ;
}
