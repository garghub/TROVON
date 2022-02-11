int F_1 ( void )
{
if ( F_2 ( V_1 ) != 0 )
return 1 ;
if ( F_3 ( V_2 ) )
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
static int F_33 ( long V_19 )
{
if ( V_19 == - V_20 )
V_19 = - V_21 ;
else if ( V_19 == - V_21 )
V_19 = - V_22 ;
return V_19 ;
}
static bool F_34 ( struct V_3 * V_3 , struct V_23 * V_24 ,
int * V_25 )
{
F_35 ( F_18 ( V_3 ) , V_3 ) ;
F_35 ( ! F_15 ( V_3 ) , V_3 ) ;
if ( F_25 ( V_3 ) <= 1 && F_36 ( V_3 ) ) {
F_37 ( V_24 , V_3 ) ;
if ( F_38 ( V_3 ) )
( * V_25 ) ++ ;
F_39 ( V_3 ) ;
return true ;
}
return false ;
}
static void F_40 ( struct V_23 * V_24 , int V_25 )
{
F_41 ( V_13 , F_42 ( V_24 ) ) ;
F_43 ( V_24 ) ;
F_41 ( V_26 , V_25 ) ;
}
static void F_44 ( struct V_23 * V_24 , struct V_15 * V_15 )
{
int V_27 ;
int V_28 = F_42 ( V_24 ) ;
int V_29 ;
struct V_23 V_30 ;
int V_25 = 0 ;
F_45 ( & V_30 , 0 ) ;
F_30 ( & V_15 -> V_16 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
struct V_3 * V_3 = V_24 -> V_31 [ V_27 ] ;
if ( F_5 ( V_3 ) ) {
if ( F_17 ( V_3 , false ) )
continue;
else
F_27 ( V_3 ) ;
}
F_37 ( & V_30 , V_24 -> V_31 [ V_27 ] ) ;
V_24 -> V_31 [ V_27 ] = NULL ;
}
V_29 = - V_28 + F_42 ( & V_30 ) ;
F_31 ( V_15 , V_4 , V_29 ) ;
F_32 ( & V_15 -> V_16 ) ;
F_46 ( & V_30 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
struct V_3 * V_3 = V_24 -> V_31 [ V_27 ] ;
if ( V_3 ) {
F_47 ( V_3 ) ;
if ( ! F_34 ( V_3 , & V_30 ,
& V_25 ) ) {
F_20 ( V_3 ) ;
F_24 ( V_3 ) ;
F_39 ( V_3 ) ;
F_48 ( V_3 ) ;
}
}
}
if ( F_42 ( & V_30 ) )
F_40 ( & V_30 , V_25 ) ;
}
static unsigned long F_49 ( struct V_23 * V_24 ,
struct V_32 * V_33 , int V_34 , unsigned long V_35 ,
unsigned long V_36 )
{
T_1 * V_37 ;
T_2 * V_38 ;
V_37 = F_50 ( V_33 -> V_39 , V_35 , & V_38 ) ;
V_36 = F_51 ( V_35 , V_36 ) ;
V_36 = F_52 ( V_35 , V_36 ) ;
V_36 = F_53 ( V_35 , V_36 ) ;
V_35 += V_40 ;
while ( V_35 < V_36 ) {
struct V_3 * V_3 = NULL ;
V_37 ++ ;
if ( F_54 ( * V_37 ) )
V_3 = F_55 ( V_33 , V_35 , * V_37 ) ;
if ( ! V_3 || F_56 ( V_3 ) != V_34 )
break;
F_20 ( V_3 ) ;
V_35 += V_40 ;
if ( F_37 ( V_24 , V_3 ) == 0 )
break;
}
F_57 ( V_37 , V_38 ) ;
return V_35 ;
}
void F_58 ( struct V_32 * V_33 ,
unsigned long V_35 , unsigned long V_36 )
{
V_33 -> V_41 &= ~ V_42 ;
while ( V_35 < V_36 ) {
struct V_3 * V_3 = NULL ;
unsigned int V_43 ;
unsigned long V_44 ;
struct V_23 V_24 ;
struct V_15 * V_15 ;
int V_34 ;
F_45 ( & V_24 , 0 ) ;
V_3 = F_59 ( V_33 , V_35 , V_45 | V_46 ,
& V_43 ) ;
if ( V_3 && ! F_60 ( V_3 ) ) {
if ( F_61 ( V_3 ) ) {
F_47 ( V_3 ) ;
V_43 = F_29 ( V_3 ) ;
F_39 ( V_3 ) ;
F_48 ( V_3 ) ;
} else {
F_37 ( & V_24 , V_3 ) ;
V_15 = F_7 ( V_3 ) ;
V_34 = F_56 ( V_3 ) ;
V_35 = F_49 ( & V_24 , V_33 ,
V_34 , V_35 , V_36 ) ;
F_44 ( & V_24 , V_15 ) ;
goto V_47;
}
}
F_62 ( ( V_35 >> V_48 ) & V_43 ) ;
V_44 = 1 + V_43 ;
V_35 += V_44 * V_40 ;
V_47:
F_63 () ;
}
}
static int F_64 ( struct V_32 * V_33 , struct V_32 * * V_49 ,
unsigned long V_35 , unsigned long V_36 , T_3 V_50 )
{
struct V_51 * V_52 = V_33 -> V_39 ;
T_4 V_53 ;
int V_14 ;
int V_10 = 0 ;
int V_54 = ! ! ( V_50 & V_42 ) ;
if ( V_50 == V_33 -> V_41 || ( V_33 -> V_41 & V_55 ) ||
F_65 ( V_33 ) || V_33 == F_66 ( V_56 -> V_52 ) )
goto V_18;
V_53 = V_33 -> V_57 + ( ( V_35 - V_33 -> V_58 ) >> V_48 ) ;
* V_49 = F_67 ( V_52 , * V_49 , V_35 , V_36 , V_50 , V_33 -> V_59 ,
V_33 -> V_60 , V_53 , F_68 ( V_33 ) ) ;
if ( * V_49 ) {
V_33 = * V_49 ;
goto V_61;
}
if ( V_35 != V_33 -> V_58 ) {
V_10 = F_69 ( V_52 , V_33 , V_35 , 1 ) ;
if ( V_10 )
goto V_18;
}
if ( V_36 != V_33 -> V_62 ) {
V_10 = F_69 ( V_52 , V_33 , V_36 , 0 ) ;
if ( V_10 )
goto V_18;
}
V_61:
V_14 = ( V_36 - V_35 ) >> V_48 ;
if ( ! V_54 )
V_14 = - V_14 ;
V_52 -> V_63 += V_14 ;
if ( V_54 )
V_33 -> V_41 = V_50 ;
else
F_58 ( V_33 , V_35 , V_36 ) ;
V_18:
* V_49 = V_33 ;
return V_10 ;
}
static int F_70 ( unsigned long V_35 , T_5 V_64 , int V_65 )
{
unsigned long V_66 , V_36 , V_67 ;
struct V_32 * V_33 , * V_49 ;
int error ;
F_62 ( V_35 & ~ V_68 ) ;
F_62 ( V_64 != F_71 ( V_64 ) ) ;
V_36 = V_35 + V_64 ;
if ( V_36 < V_35 )
return - V_69 ;
if ( V_36 == V_35 )
return 0 ;
V_33 = F_72 ( V_56 -> V_52 , V_35 ) ;
if ( ! V_33 || V_33 -> V_58 > V_35 )
return - V_21 ;
V_49 = V_33 -> V_70 ;
if ( V_35 > V_33 -> V_58 )
V_49 = V_33 ;
for ( V_66 = V_35 ; ; ) {
T_3 V_50 ;
V_50 = V_33 -> V_41 & ~ V_42 ;
if ( V_65 )
V_50 |= V_42 ;
V_67 = V_33 -> V_62 ;
if ( V_67 > V_36 )
V_67 = V_36 ;
error = F_64 ( V_33 , & V_49 , V_66 , V_67 , V_50 ) ;
if ( error )
break;
V_66 = V_67 ;
if ( V_66 < V_49 -> V_62 )
V_66 = V_49 -> V_62 ;
if ( V_66 >= V_36 )
break;
V_33 = V_49 -> V_71 ;
if ( ! V_33 || V_33 -> V_58 != V_66 ) {
error = - V_21 ;
break;
}
}
return error ;
}
static int F_73 ( int V_72 )
{
struct V_32 * V_33 , * V_49 = NULL ;
if ( V_72 & V_73 )
V_56 -> V_52 -> V_74 |= V_42 ;
else
V_56 -> V_52 -> V_74 &= ~ V_42 ;
if ( V_72 == V_73 )
goto V_18;
for ( V_33 = V_56 -> V_52 -> V_75 ; V_33 ; V_33 = V_49 -> V_71 ) {
T_3 V_50 ;
V_50 = V_33 -> V_41 & ~ V_42 ;
if ( V_72 & V_76 )
V_50 |= V_42 ;
F_64 ( V_33 , & V_49 , V_33 -> V_58 , V_33 -> V_62 , V_50 ) ;
F_74 () ;
}
V_18:
return 0 ;
}
int F_75 ( T_5 V_77 , struct V_78 * V_79 )
{
unsigned long V_80 , V_81 ;
int V_82 = 0 ;
V_81 = ( V_77 + V_40 - 1 ) >> V_48 ;
V_80 = F_2 ( V_1 ) ;
if ( V_80 == V_83 )
V_82 = 1 ;
V_80 >>= V_48 ;
F_76 ( & V_84 ) ;
if ( ! V_82 &&
V_81 + V_79 -> V_85 > V_80 && ! F_3 ( V_2 ) )
goto V_18;
F_77 ( V_79 ) ;
V_79 -> V_85 += V_81 ;
V_82 = 1 ;
V_18:
F_78 ( & V_84 ) ;
return V_82 ;
}
void F_79 ( T_5 V_77 , struct V_78 * V_79 )
{
F_76 ( & V_84 ) ;
V_79 -> V_85 -= ( V_77 + V_40 - 1 ) >> V_48 ;
F_78 ( & V_84 ) ;
F_80 ( V_79 ) ;
}
