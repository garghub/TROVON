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
unsigned int F_17 ( struct V_3 * V_3 )
{
unsigned int V_8 = 0 ;
F_14 ( ! F_15 ( V_3 ) ) ;
if ( F_5 ( V_3 ) ) {
unsigned int V_9 = F_8 ( V_3 ) ;
F_6 ( F_7 ( V_3 ) , V_4 , - V_9 ) ;
V_8 = V_9 - 1 ;
if ( ! F_10 ( V_3 ) ) {
int V_10 = V_11 ;
if ( F_18 ( V_3 ) > 1 )
V_10 = F_19 ( V_3 ) ;
if ( V_10 != V_12 )
F_9 ( V_13 ) ;
F_11 ( V_3 ) ;
} else {
if ( F_12 ( V_3 ) )
F_9 ( V_6 ) ;
else
F_9 ( V_13 ) ;
}
}
return V_8 ;
}
long F_20 ( struct V_14 * V_15 ,
unsigned long V_16 , unsigned long V_17 , int * V_18 )
{
struct V_19 * V_20 = V_15 -> V_21 ;
unsigned long V_9 = ( V_17 - V_16 ) / V_22 ;
int V_23 ;
F_21 ( V_16 & ~ V_24 ) ;
F_21 ( V_17 & ~ V_24 ) ;
F_21 ( V_16 < V_15 -> V_25 ) ;
F_21 ( V_17 > V_15 -> V_26 ) ;
F_21 ( ! F_22 ( & V_20 -> V_27 ) ) ;
V_23 = V_28 | V_29 ;
if ( ( V_15 -> V_30 & ( V_31 | V_32 ) ) == V_31 )
V_23 |= V_33 ;
if ( V_15 -> V_30 & ( V_34 | V_31 | V_35 ) )
V_23 |= V_36 ;
return F_23 ( V_37 , V_20 , V_16 , V_9 , V_23 ,
NULL , NULL , V_18 ) ;
}
static int F_24 ( long V_38 )
{
if ( V_38 == - V_39 )
V_38 = - V_40 ;
else if ( V_38 == - V_40 )
V_38 = - V_41 ;
return V_38 ;
}
void F_25 ( struct V_14 * V_15 ,
unsigned long V_16 , unsigned long V_17 )
{
V_15 -> V_30 &= ~ V_42 ;
while ( V_16 < V_17 ) {
struct V_3 * V_3 ;
unsigned int V_8 , V_43 ;
V_3 = F_26 ( V_15 , V_16 , V_44 | V_45 ,
& V_8 ) ;
if ( V_3 && ! F_27 ( V_3 ) ) {
F_28 ( V_3 ) ;
F_29 () ;
V_8 = F_17 ( V_3 ) ;
F_30 ( V_3 ) ;
F_31 ( V_3 ) ;
}
V_43 = 1 + ( ~ ( V_16 >> V_46 ) & V_8 ) ;
V_16 += V_43 * V_22 ;
F_32 () ;
}
}
static int F_33 ( struct V_14 * V_15 , struct V_14 * * V_47 ,
unsigned long V_16 , unsigned long V_17 , T_1 V_48 )
{
struct V_19 * V_20 = V_15 -> V_21 ;
T_2 V_49 ;
int V_9 ;
int V_10 = 0 ;
int V_50 = ! ! ( V_48 & V_42 ) ;
if ( V_48 == V_15 -> V_30 || ( V_15 -> V_30 & V_51 ) ||
F_34 ( V_15 ) || V_15 == F_35 ( V_37 -> V_20 ) )
goto V_52;
V_49 = V_15 -> V_53 + ( ( V_16 - V_15 -> V_25 ) >> V_46 ) ;
* V_47 = F_36 ( V_20 , * V_47 , V_16 , V_17 , V_48 , V_15 -> V_54 ,
V_15 -> V_55 , V_49 , F_37 ( V_15 ) ) ;
if ( * V_47 ) {
V_15 = * V_47 ;
goto V_56;
}
if ( V_16 != V_15 -> V_25 ) {
V_10 = F_38 ( V_20 , V_15 , V_16 , 1 ) ;
if ( V_10 )
goto V_52;
}
if ( V_17 != V_15 -> V_26 ) {
V_10 = F_38 ( V_20 , V_15 , V_17 , 0 ) ;
if ( V_10 )
goto V_52;
}
V_56:
V_9 = ( V_17 - V_16 ) >> V_46 ;
if ( ! V_50 )
V_9 = - V_9 ;
V_20 -> V_57 += V_9 ;
if ( V_50 )
V_15 -> V_30 = V_48 ;
else
F_25 ( V_15 , V_16 , V_17 ) ;
V_52:
* V_47 = V_15 ;
return V_10 ;
}
static int F_39 ( unsigned long V_16 , T_3 V_58 , int V_59 )
{
unsigned long V_60 , V_17 , V_61 ;
struct V_14 * V_15 , * V_47 ;
int error ;
F_21 ( V_16 & ~ V_24 ) ;
F_21 ( V_58 != F_40 ( V_58 ) ) ;
V_17 = V_16 + V_58 ;
if ( V_17 < V_16 )
return - V_62 ;
if ( V_17 == V_16 )
return 0 ;
V_15 = F_41 ( V_37 -> V_20 , V_16 ) ;
if ( ! V_15 || V_15 -> V_25 > V_16 )
return - V_40 ;
V_47 = V_15 -> V_63 ;
if ( V_16 > V_15 -> V_25 )
V_47 = V_15 ;
for ( V_60 = V_16 ; ; ) {
T_1 V_48 ;
V_48 = V_15 -> V_30 & ~ V_42 ;
if ( V_59 )
V_48 |= V_42 ;
V_61 = V_15 -> V_26 ;
if ( V_61 > V_17 )
V_61 = V_17 ;
error = F_33 ( V_15 , & V_47 , V_60 , V_61 , V_48 ) ;
if ( error )
break;
V_60 = V_61 ;
if ( V_60 < V_47 -> V_26 )
V_60 = V_47 -> V_26 ;
if ( V_60 >= V_17 )
break;
V_15 = V_47 -> V_64 ;
if ( ! V_15 || V_15 -> V_25 != V_60 ) {
error = - V_40 ;
break;
}
}
return error ;
}
int F_42 ( unsigned long V_16 , unsigned long V_58 , int V_65 )
{
struct V_19 * V_20 = V_37 -> V_20 ;
unsigned long V_17 , V_60 , V_66 ;
struct V_14 * V_15 = NULL ;
int V_67 = 0 ;
long V_10 = 0 ;
F_21 ( V_16 & ~ V_24 ) ;
F_21 ( V_58 != F_40 ( V_58 ) ) ;
V_17 = V_16 + V_58 ;
for ( V_60 = V_16 ; V_60 < V_17 ; V_60 = V_66 ) {
if ( ! V_67 ) {
V_67 = 1 ;
F_43 ( & V_20 -> V_27 ) ;
V_15 = F_41 ( V_20 , V_60 ) ;
} else if ( V_60 >= V_15 -> V_26 )
V_15 = V_15 -> V_64 ;
if ( ! V_15 || V_15 -> V_25 >= V_17 )
break;
V_66 = F_44 ( V_17 , V_15 -> V_26 ) ;
if ( V_15 -> V_30 & ( V_68 | V_69 ) )
continue;
if ( V_60 < V_15 -> V_25 )
V_60 = V_15 -> V_25 ;
V_10 = F_20 ( V_15 , V_60 , V_66 , & V_67 ) ;
if ( V_10 < 0 ) {
if ( V_65 ) {
V_10 = 0 ;
continue;
}
V_10 = F_24 ( V_10 ) ;
break;
}
V_66 = V_60 + V_10 * V_22 ;
V_10 = 0 ;
}
if ( V_67 )
F_45 ( & V_20 -> V_27 ) ;
return V_10 ;
}
static int F_46 ( int V_70 )
{
struct V_14 * V_15 , * V_47 = NULL ;
if ( V_70 & V_71 )
V_37 -> V_20 -> V_72 |= V_42 ;
else
V_37 -> V_20 -> V_72 &= ~ V_42 ;
if ( V_70 == V_71 )
goto V_52;
for ( V_15 = V_37 -> V_20 -> V_73 ; V_15 ; V_15 = V_47 -> V_64 ) {
T_1 V_48 ;
V_48 = V_15 -> V_30 & ~ V_42 ;
if ( V_70 & V_74 )
V_48 |= V_42 ;
F_33 ( V_15 , & V_47 , V_15 -> V_25 , V_15 -> V_26 , V_48 ) ;
}
V_52:
return 0 ;
}
int F_47 ( T_3 V_75 , struct V_76 * V_77 )
{
unsigned long V_78 , V_67 ;
int V_79 = 0 ;
V_67 = ( V_75 + V_22 - 1 ) >> V_46 ;
V_78 = F_3 ( V_2 ) ;
if ( V_78 == V_80 )
V_79 = 1 ;
V_78 >>= V_46 ;
F_48 ( & V_81 ) ;
if ( ! V_79 &&
V_67 + V_77 -> V_82 > V_78 && ! F_2 ( V_1 ) )
goto V_52;
F_49 ( V_77 ) ;
V_77 -> V_82 += V_67 ;
V_79 = 1 ;
V_52:
F_50 ( & V_81 ) ;
return V_79 ;
}
void F_51 ( T_3 V_75 , struct V_76 * V_77 )
{
F_48 ( & V_81 ) ;
V_77 -> V_82 -= ( V_75 + V_22 - 1 ) >> V_46 ;
F_50 ( & V_81 ) ;
F_52 ( V_77 ) ;
}
