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
static void F_17 ( struct V_3 * V_3 )
{
int V_8 = V_9 ;
if ( F_18 ( V_3 ) > 1 )
V_8 = F_19 ( V_3 ) ;
if ( V_8 != V_10 )
F_9 ( V_11 ) ;
F_11 ( V_3 ) ;
}
static void F_20 ( struct V_3 * V_3 )
{
if ( F_12 ( V_3 ) )
F_9 ( V_6 ) ;
else
F_9 ( V_11 ) ;
}
unsigned int F_21 ( struct V_3 * V_3 )
{
unsigned int V_12 = 0 ;
F_14 ( ! F_15 ( V_3 ) ) ;
if ( F_5 ( V_3 ) ) {
unsigned int V_13 = F_8 ( V_3 ) ;
F_6 ( F_7 ( V_3 ) , V_4 , - V_13 ) ;
V_12 = V_13 - 1 ;
if ( ! F_10 ( V_3 ) )
F_17 ( V_3 ) ;
else
F_20 ( V_3 ) ;
}
return V_12 ;
}
long F_22 ( struct V_14 * V_15 ,
unsigned long V_16 , unsigned long V_17 , int * V_18 )
{
struct V_19 * V_20 = V_15 -> V_21 ;
unsigned long V_13 = ( V_17 - V_16 ) / V_22 ;
int V_23 ;
F_23 ( V_16 & ~ V_24 ) ;
F_23 ( V_17 & ~ V_24 ) ;
F_23 ( V_16 < V_15 -> V_25 ) ;
F_23 ( V_17 > V_15 -> V_26 ) ;
F_23 ( ! F_24 ( & V_20 -> V_27 ) ) ;
V_23 = V_28 | V_29 ;
if ( ( V_15 -> V_30 & ( V_31 | V_32 ) ) == V_31 )
V_23 |= V_33 ;
if ( V_15 -> V_30 & ( V_34 | V_31 | V_35 ) )
V_23 |= V_36 ;
return F_25 ( V_37 , V_20 , V_16 , V_13 , V_23 ,
NULL , NULL , V_18 ) ;
}
static int F_26 ( long V_38 )
{
if ( V_38 == - V_39 )
V_38 = - V_40 ;
else if ( V_38 == - V_40 )
V_38 = - V_41 ;
return V_38 ;
}
static bool F_27 ( struct V_3 * V_3 , struct V_42 * V_43 ,
int * V_44 )
{
F_23 ( F_28 ( V_3 ) ) ;
F_23 ( ! F_15 ( V_3 ) ) ;
if ( F_18 ( V_3 ) <= 1 && F_29 ( V_3 ) ) {
F_30 ( V_43 , V_3 ) ;
if ( F_31 ( V_3 ) )
( * V_44 ) ++ ;
F_32 ( V_3 ) ;
return true ;
}
return false ;
}
static void F_33 ( struct V_42 * V_43 , int V_44 )
{
F_34 ( V_11 , F_35 ( V_43 ) ) ;
F_36 ( V_43 ) ;
F_34 ( V_45 , V_44 ) ;
}
static void F_37 ( struct V_42 * V_43 , struct V_46 * V_46 )
{
int V_47 ;
int V_48 = F_35 ( V_43 ) ;
int V_49 = - V_48 ;
struct V_42 V_50 ;
int V_44 = 0 ;
F_38 ( & V_46 -> V_51 ) ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
struct V_3 * V_3 = V_43 -> V_52 [ V_47 ] ;
if ( F_5 ( V_3 ) ) {
struct V_53 * V_53 ;
int V_54 ;
if ( F_28 ( V_3 ) ) {
V_53 = F_39 ( V_3 , V_46 ) ;
V_54 = F_40 ( V_3 ) ;
F_41 ( V_3 ) ;
F_42 ( V_3 , V_53 , V_54 ) ;
} else {
F_20 ( V_3 ) ;
goto V_55;
}
} else {
V_55:
V_43 -> V_52 [ V_47 ] = NULL ;
F_43 ( V_3 ) ;
V_49 ++ ;
}
}
F_44 ( V_46 , V_4 , V_49 ) ;
F_45 ( & V_46 -> V_51 ) ;
F_46 ( & V_50 , 0 ) ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
struct V_3 * V_3 = V_43 -> V_52 [ V_47 ] ;
if ( V_3 ) {
F_47 ( V_3 ) ;
if ( ! F_27 ( V_3 , & V_50 ,
& V_44 ) ) {
F_48 ( V_3 ) ;
F_17 ( V_3 ) ;
F_32 ( V_3 ) ;
F_43 ( V_3 ) ;
}
}
}
if ( F_35 ( & V_50 ) )
F_33 ( & V_50 , V_44 ) ;
}
static unsigned long F_49 ( struct V_42 * V_43 ,
struct V_14 * V_15 , int V_56 , unsigned long V_16 ,
unsigned long V_17 )
{
T_1 * V_57 ;
T_2 * V_58 ;
V_57 = F_50 ( V_15 -> V_21 , V_16 , & V_58 ) ;
V_17 = F_51 ( V_16 , V_17 ) ;
V_17 = F_52 ( V_16 , V_17 ) ;
V_17 = F_53 ( V_16 , V_17 ) ;
V_16 += V_22 ;
while ( V_16 < V_17 ) {
struct V_3 * V_3 = NULL ;
V_57 ++ ;
if ( F_54 ( * V_57 ) )
V_3 = F_55 ( V_15 , V_16 , * V_57 ) ;
if ( ! V_3 || F_56 ( V_3 ) != V_56 )
break;
F_48 ( V_3 ) ;
V_16 += V_22 ;
if ( F_30 ( V_43 , V_3 ) == 0 )
break;
}
F_57 ( V_57 , V_58 ) ;
return V_16 ;
}
void F_58 ( struct V_14 * V_15 ,
unsigned long V_16 , unsigned long V_17 )
{
V_15 -> V_30 &= ~ V_59 ;
while ( V_16 < V_17 ) {
struct V_3 * V_3 = NULL ;
unsigned int V_12 , V_60 ;
struct V_42 V_43 ;
struct V_46 * V_46 ;
int V_56 ;
F_46 ( & V_43 , 0 ) ;
V_3 = F_59 ( V_15 , V_16 , V_61 | V_62 ,
& V_12 ) ;
if ( V_3 && ! F_60 ( V_3 ) ) {
if ( F_61 ( V_3 ) ) {
F_47 ( V_3 ) ;
V_12 = F_21 ( V_3 ) ;
F_32 ( V_3 ) ;
F_43 ( V_3 ) ;
} else {
F_30 ( & V_43 , V_3 ) ;
V_46 = F_7 ( V_3 ) ;
V_56 = F_56 ( V_3 ) ;
V_16 = F_49 ( & V_43 , V_15 ,
V_56 , V_16 , V_17 ) ;
F_37 ( & V_43 , V_46 ) ;
goto V_63;
}
}
V_60 = 1 + ( ~ ( V_16 >> V_64 ) & V_12 ) ;
V_16 += V_60 * V_22 ;
V_63:
F_62 () ;
}
}
static int F_63 ( struct V_14 * V_15 , struct V_14 * * V_65 ,
unsigned long V_16 , unsigned long V_17 , T_3 V_66 )
{
struct V_19 * V_20 = V_15 -> V_21 ;
T_4 V_67 ;
int V_13 ;
int V_8 = 0 ;
int V_68 = ! ! ( V_66 & V_59 ) ;
if ( V_66 == V_15 -> V_30 || ( V_15 -> V_30 & V_69 ) ||
F_64 ( V_15 ) || V_15 == F_65 ( V_37 -> V_20 ) )
goto V_70;
V_67 = V_15 -> V_71 + ( ( V_16 - V_15 -> V_25 ) >> V_64 ) ;
* V_65 = F_66 ( V_20 , * V_65 , V_16 , V_17 , V_66 , V_15 -> V_72 ,
V_15 -> V_73 , V_67 , F_67 ( V_15 ) ) ;
if ( * V_65 ) {
V_15 = * V_65 ;
goto V_74;
}
if ( V_16 != V_15 -> V_25 ) {
V_8 = F_68 ( V_20 , V_15 , V_16 , 1 ) ;
if ( V_8 )
goto V_70;
}
if ( V_17 != V_15 -> V_26 ) {
V_8 = F_68 ( V_20 , V_15 , V_17 , 0 ) ;
if ( V_8 )
goto V_70;
}
V_74:
V_13 = ( V_17 - V_16 ) >> V_64 ;
if ( ! V_68 )
V_13 = - V_13 ;
V_20 -> V_75 += V_13 ;
if ( V_68 )
V_15 -> V_30 = V_66 ;
else
F_58 ( V_15 , V_16 , V_17 ) ;
V_70:
* V_65 = V_15 ;
return V_8 ;
}
static int F_69 ( unsigned long V_16 , T_5 V_76 , int V_77 )
{
unsigned long V_78 , V_17 , V_79 ;
struct V_14 * V_15 , * V_65 ;
int error ;
F_23 ( V_16 & ~ V_24 ) ;
F_23 ( V_76 != F_70 ( V_76 ) ) ;
V_17 = V_16 + V_76 ;
if ( V_17 < V_16 )
return - V_80 ;
if ( V_17 == V_16 )
return 0 ;
V_15 = F_71 ( V_37 -> V_20 , V_16 ) ;
if ( ! V_15 || V_15 -> V_25 > V_16 )
return - V_40 ;
V_65 = V_15 -> V_81 ;
if ( V_16 > V_15 -> V_25 )
V_65 = V_15 ;
for ( V_78 = V_16 ; ; ) {
T_3 V_66 ;
V_66 = V_15 -> V_30 & ~ V_59 ;
if ( V_77 )
V_66 |= V_59 ;
V_79 = V_15 -> V_26 ;
if ( V_79 > V_17 )
V_79 = V_17 ;
error = F_63 ( V_15 , & V_65 , V_78 , V_79 , V_66 ) ;
if ( error )
break;
V_78 = V_79 ;
if ( V_78 < V_65 -> V_26 )
V_78 = V_65 -> V_26 ;
if ( V_78 >= V_17 )
break;
V_15 = V_65 -> V_82 ;
if ( ! V_15 || V_15 -> V_25 != V_78 ) {
error = - V_40 ;
break;
}
}
return error ;
}
int F_72 ( unsigned long V_16 , unsigned long V_76 , int V_83 )
{
struct V_19 * V_20 = V_37 -> V_20 ;
unsigned long V_17 , V_78 , V_84 ;
struct V_14 * V_15 = NULL ;
int V_85 = 0 ;
long V_8 = 0 ;
F_23 ( V_16 & ~ V_24 ) ;
F_23 ( V_76 != F_70 ( V_76 ) ) ;
V_17 = V_16 + V_76 ;
for ( V_78 = V_16 ; V_78 < V_17 ; V_78 = V_84 ) {
if ( ! V_85 ) {
V_85 = 1 ;
F_73 ( & V_20 -> V_27 ) ;
V_15 = F_71 ( V_20 , V_78 ) ;
} else if ( V_78 >= V_15 -> V_26 )
V_15 = V_15 -> V_82 ;
if ( ! V_15 || V_15 -> V_25 >= V_17 )
break;
V_84 = F_74 ( V_17 , V_15 -> V_26 ) ;
if ( V_15 -> V_30 & ( V_86 | V_87 ) )
continue;
if ( V_78 < V_15 -> V_25 )
V_78 = V_15 -> V_25 ;
V_8 = F_22 ( V_15 , V_78 , V_84 , & V_85 ) ;
if ( V_8 < 0 ) {
if ( V_83 ) {
V_8 = 0 ;
continue;
}
V_8 = F_26 ( V_8 ) ;
break;
}
V_84 = V_78 + V_8 * V_22 ;
V_8 = 0 ;
}
if ( V_85 )
F_75 ( & V_20 -> V_27 ) ;
return V_8 ;
}
static int F_76 ( int V_88 )
{
struct V_14 * V_15 , * V_65 = NULL ;
if ( V_88 & V_89 )
V_37 -> V_20 -> V_90 |= V_59 ;
else
V_37 -> V_20 -> V_90 &= ~ V_59 ;
if ( V_88 == V_89 )
goto V_70;
for ( V_15 = V_37 -> V_20 -> V_91 ; V_15 ; V_15 = V_65 -> V_82 ) {
T_3 V_66 ;
V_66 = V_15 -> V_30 & ~ V_59 ;
if ( V_88 & V_92 )
V_66 |= V_59 ;
F_63 ( V_15 , & V_65 , V_15 -> V_25 , V_15 -> V_26 , V_66 ) ;
F_62 () ;
}
V_70:
return 0 ;
}
int F_77 ( T_5 V_93 , struct V_94 * V_95 )
{
unsigned long V_96 , V_85 ;
int V_97 = 0 ;
V_85 = ( V_93 + V_22 - 1 ) >> V_64 ;
V_96 = F_3 ( V_2 ) ;
if ( V_96 == V_98 )
V_97 = 1 ;
V_96 >>= V_64 ;
F_78 ( & V_99 ) ;
if ( ! V_97 &&
V_85 + V_95 -> V_100 > V_96 && ! F_2 ( V_1 ) )
goto V_70;
F_79 ( V_95 ) ;
V_95 -> V_100 += V_85 ;
V_97 = 1 ;
V_70:
F_80 ( & V_99 ) ;
return V_97 ;
}
void F_81 ( T_5 V_93 , struct V_94 * V_95 )
{
F_78 ( & V_99 ) ;
V_95 -> V_100 -= ( V_93 + V_22 - 1 ) >> V_64 ;
F_80 ( & V_99 ) ;
F_82 ( V_95 ) ;
}
