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
void F_17 ( struct V_3 * V_3 )
{
F_14 ( ! F_15 ( V_3 ) ) ;
if ( F_5 ( V_3 ) ) {
F_6 ( F_7 ( V_3 ) , V_4 ,
- F_8 ( V_3 ) ) ;
if ( ! F_10 ( V_3 ) ) {
int V_8 = V_9 ;
if ( F_18 ( V_3 ) > 1 )
V_8 = F_19 ( V_3 ) ;
if ( V_8 != V_10 )
F_9 ( V_11 ) ;
F_11 ( V_3 ) ;
} else {
if ( F_12 ( V_3 ) )
F_9 ( V_6 ) ;
else
F_9 ( V_11 ) ;
}
}
}
static long F_20 ( struct V_12 * V_13 ,
unsigned long V_14 , unsigned long V_15 ,
int * V_16 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
unsigned long V_20 = V_14 ;
int V_21 = ( V_15 - V_14 ) / V_22 ;
int V_23 ;
F_21 ( V_14 & ~ V_24 ) ;
F_21 ( V_15 & ~ V_24 ) ;
F_21 ( V_14 < V_13 -> V_25 ) ;
F_21 ( V_15 > V_13 -> V_26 ) ;
F_21 ( ! F_22 ( & V_18 -> V_27 ) ) ;
V_23 = V_28 | V_29 ;
if ( ( V_13 -> V_30 & ( V_31 | V_32 ) ) == V_31 )
V_23 |= V_33 ;
if ( V_13 -> V_30 & ( V_34 | V_31 | V_35 ) )
V_23 |= V_36 ;
return F_23 ( V_37 , V_18 , V_20 , V_21 , V_23 ,
NULL , NULL , V_16 ) ;
}
static int F_24 ( long V_38 )
{
if ( V_38 == - V_39 )
V_38 = - V_40 ;
else if ( V_38 == - V_40 )
V_38 = - V_41 ;
return V_38 ;
}
long F_25 ( struct V_12 * V_13 ,
unsigned long V_14 , unsigned long V_15 )
{
int V_21 = ( V_15 - V_14 ) / V_22 ;
F_14 ( ! ( V_13 -> V_30 & V_42 ) ) ;
if ( V_13 -> V_30 & ( V_43 | V_44 ) )
goto V_45;
if ( ! ( ( V_13 -> V_30 & V_46 ) ||
F_26 ( V_13 ) ||
V_13 == F_27 ( V_37 -> V_18 ) ) ) {
F_20 ( V_13 , V_14 , V_15 , NULL ) ;
return 0 ;
}
F_28 ( V_14 , V_15 ) ;
V_45:
V_13 -> V_30 &= ~ V_42 ;
return V_21 ;
}
void F_29 ( struct V_12 * V_13 ,
unsigned long V_14 , unsigned long V_15 )
{
unsigned long V_20 ;
F_30 () ;
V_13 -> V_30 &= ~ V_42 ;
for ( V_20 = V_14 ; V_20 < V_15 ; V_20 += V_22 ) {
struct V_3 * V_3 ;
V_3 = F_31 ( V_13 , V_20 , V_47 | V_48 ) ;
if ( V_3 && ! F_32 ( V_3 ) ) {
F_33 ( V_3 ) ;
F_17 ( V_3 ) ;
F_34 ( V_3 ) ;
F_35 ( V_3 ) ;
}
F_36 () ;
}
}
static int F_37 ( struct V_12 * V_13 , struct V_12 * * V_49 ,
unsigned long V_14 , unsigned long V_15 , T_1 V_50 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_2 V_51 ;
int V_21 ;
int V_8 = 0 ;
int V_52 = ! ! ( V_50 & V_42 ) ;
if ( V_50 == V_13 -> V_30 || ( V_13 -> V_30 & V_53 ) ||
F_26 ( V_13 ) || V_13 == F_27 ( V_37 -> V_18 ) )
goto V_54;
V_51 = V_13 -> V_55 + ( ( V_14 - V_13 -> V_25 ) >> V_56 ) ;
* V_49 = F_38 ( V_18 , * V_49 , V_14 , V_15 , V_50 , V_13 -> V_57 ,
V_13 -> V_58 , V_51 , F_39 ( V_13 ) ) ;
if ( * V_49 ) {
V_13 = * V_49 ;
goto V_59;
}
if ( V_14 != V_13 -> V_25 ) {
V_8 = F_40 ( V_18 , V_13 , V_14 , 1 ) ;
if ( V_8 )
goto V_54;
}
if ( V_15 != V_13 -> V_26 ) {
V_8 = F_40 ( V_18 , V_13 , V_15 , 0 ) ;
if ( V_8 )
goto V_54;
}
V_59:
V_21 = ( V_15 - V_14 ) >> V_56 ;
if ( ! V_52 )
V_21 = - V_21 ;
V_18 -> V_60 += V_21 ;
if ( V_52 )
V_13 -> V_30 = V_50 ;
else
F_29 ( V_13 , V_14 , V_15 ) ;
V_54:
* V_49 = V_13 ;
return V_8 ;
}
static int F_41 ( unsigned long V_14 , T_3 V_61 , int V_62 )
{
unsigned long V_63 , V_15 , V_64 ;
struct V_12 * V_13 , * V_49 ;
int error ;
F_21 ( V_14 & ~ V_24 ) ;
F_21 ( V_61 != F_42 ( V_61 ) ) ;
V_15 = V_14 + V_61 ;
if ( V_15 < V_14 )
return - V_65 ;
if ( V_15 == V_14 )
return 0 ;
V_13 = F_43 ( V_37 -> V_18 , V_14 ) ;
if ( ! V_13 || V_13 -> V_25 > V_14 )
return - V_40 ;
V_49 = V_13 -> V_66 ;
if ( V_14 > V_13 -> V_25 )
V_49 = V_13 ;
for ( V_63 = V_14 ; ; ) {
T_1 V_50 ;
V_50 = V_13 -> V_30 | V_42 ;
if ( ! V_62 )
V_50 &= ~ V_42 ;
V_64 = V_13 -> V_26 ;
if ( V_64 > V_15 )
V_64 = V_15 ;
error = F_37 ( V_13 , & V_49 , V_63 , V_64 , V_50 ) ;
if ( error )
break;
V_63 = V_64 ;
if ( V_63 < V_49 -> V_26 )
V_63 = V_49 -> V_26 ;
if ( V_63 >= V_15 )
break;
V_13 = V_49 -> V_67 ;
if ( ! V_13 || V_13 -> V_25 != V_63 ) {
error = - V_40 ;
break;
}
}
return error ;
}
static int F_44 ( unsigned long V_14 , T_3 V_61 , int V_68 )
{
struct V_17 * V_18 = V_37 -> V_18 ;
unsigned long V_15 , V_63 , V_69 ;
struct V_12 * V_13 = NULL ;
int V_70 = 0 ;
int V_8 = 0 ;
F_21 ( V_14 & ~ V_24 ) ;
F_21 ( V_61 != F_42 ( V_61 ) ) ;
V_15 = V_14 + V_61 ;
for ( V_63 = V_14 ; V_63 < V_15 ; V_63 = V_69 ) {
if ( ! V_70 ) {
V_70 = 1 ;
F_45 ( & V_18 -> V_27 ) ;
V_13 = F_43 ( V_18 , V_63 ) ;
} else if ( V_63 >= V_13 -> V_26 )
V_13 = V_13 -> V_67 ;
if ( ! V_13 || V_13 -> V_25 >= V_15 )
break;
V_69 = F_46 ( V_15 , V_13 -> V_26 ) ;
if ( V_13 -> V_30 & ( V_43 | V_44 ) )
continue;
if ( V_63 < V_13 -> V_25 )
V_63 = V_13 -> V_25 ;
V_8 = F_20 ( V_13 , V_63 , V_69 , & V_70 ) ;
if ( V_8 < 0 ) {
if ( V_68 ) {
V_8 = 0 ;
continue;
}
V_8 = F_24 ( V_8 ) ;
break;
}
V_69 = V_63 + V_8 * V_22 ;
V_8 = 0 ;
}
if ( V_70 )
F_47 ( & V_18 -> V_27 ) ;
return V_8 ;
}
static int F_48 ( int V_71 )
{
struct V_12 * V_13 , * V_49 = NULL ;
if ( V_71 & V_72 )
V_37 -> V_18 -> V_73 |= V_42 ;
else
V_37 -> V_18 -> V_73 &= ~ V_42 ;
if ( V_71 == V_72 )
goto V_54;
for ( V_13 = V_37 -> V_18 -> V_74 ; V_13 ; V_13 = V_49 -> V_67 ) {
T_1 V_50 ;
V_50 = V_13 -> V_30 | V_42 ;
if ( ! ( V_71 & V_75 ) )
V_50 &= ~ V_42 ;
F_37 ( V_13 , & V_49 , V_13 -> V_25 , V_13 -> V_26 , V_50 ) ;
}
V_54:
return 0 ;
}
int F_49 ( T_3 V_76 , struct V_77 * V_78 )
{
unsigned long V_79 , V_70 ;
int V_80 = 0 ;
V_70 = ( V_76 + V_22 - 1 ) >> V_56 ;
V_79 = F_3 ( V_2 ) ;
if ( V_79 == V_81 )
V_80 = 1 ;
V_79 >>= V_56 ;
F_50 ( & V_82 ) ;
if ( ! V_80 &&
V_70 + V_78 -> V_83 > V_79 && ! F_2 ( V_1 ) )
goto V_54;
F_51 ( V_78 ) ;
V_78 -> V_83 += V_70 ;
V_80 = 1 ;
V_54:
F_52 ( & V_82 ) ;
return V_80 ;
}
void F_53 ( T_3 V_76 , struct V_77 * V_78 )
{
F_50 ( & V_82 ) ;
V_78 -> V_83 -= ( V_76 + V_22 - 1 ) >> V_56 ;
F_52 ( & V_82 ) ;
F_54 ( V_78 ) ;
}
