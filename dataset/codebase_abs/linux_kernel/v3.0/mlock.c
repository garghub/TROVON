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
F_5 ( ! F_6 ( V_3 ) ) ;
if ( ! V_3 -> V_4 ) {
return;
}
F_7 ( V_3 , V_5 ) ;
F_8 ( V_6 ) ;
if ( ! F_9 ( V_3 ) ) {
F_10 ( V_3 ) ;
} else {
if ( F_11 ( V_3 ) )
F_8 ( V_7 ) ;
}
}
void F_12 ( struct V_3 * V_3 )
{
F_13 ( ! F_6 ( V_3 ) ) ;
if ( ! F_14 ( V_3 ) ) {
F_15 ( V_3 , V_5 ) ;
F_8 ( V_8 ) ;
if ( ! F_9 ( V_3 ) )
F_10 ( V_3 ) ;
}
}
void F_16 ( struct V_3 * V_3 )
{
F_13 ( ! F_6 ( V_3 ) ) ;
if ( F_17 ( V_3 ) ) {
F_7 ( V_3 , V_5 ) ;
if ( ! F_9 ( V_3 ) ) {
int V_9 = F_18 ( V_3 ) ;
if ( V_9 != V_10 )
F_8 ( V_11 ) ;
F_10 ( V_3 ) ;
} else {
if ( F_11 ( V_3 ) )
F_8 ( V_7 ) ;
else
F_8 ( V_11 ) ;
}
}
}
static long F_19 ( struct V_12 * V_13 ,
unsigned long V_14 , unsigned long V_15 ,
int * V_16 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
unsigned long V_20 = V_14 ;
int V_21 = ( V_15 - V_14 ) / V_22 ;
int V_23 ;
F_5 ( V_14 & ~ V_24 ) ;
F_5 ( V_15 & ~ V_24 ) ;
F_5 ( V_14 < V_13 -> V_25 ) ;
F_5 ( V_15 > V_13 -> V_26 ) ;
F_5 ( ! F_20 ( & V_18 -> V_27 ) ) ;
V_23 = V_28 | V_29 ;
if ( ( V_13 -> V_30 & ( V_31 | V_32 ) ) == V_31 )
V_23 |= V_33 ;
if ( V_13 -> V_30 & ( V_34 | V_31 | V_35 ) )
V_23 |= V_36 ;
return F_21 ( V_37 , V_18 , V_20 , V_21 , V_23 ,
NULL , NULL , V_16 ) ;
}
static int F_22 ( long V_38 )
{
if ( V_38 == - V_39 )
V_38 = - V_40 ;
else if ( V_38 == - V_40 )
V_38 = - V_41 ;
return V_38 ;
}
long F_23 ( struct V_12 * V_13 ,
unsigned long V_14 , unsigned long V_15 )
{
int V_21 = ( V_15 - V_14 ) / V_22 ;
F_13 ( ! ( V_13 -> V_30 & V_42 ) ) ;
if ( V_13 -> V_30 & ( V_43 | V_44 ) )
goto V_45;
if ( ! ( ( V_13 -> V_30 & ( V_46 | V_47 ) ) ||
F_24 ( V_13 ) ||
V_13 == F_25 ( V_37 -> V_18 ) ) ) {
F_19 ( V_13 , V_14 , V_15 , NULL ) ;
return 0 ;
}
F_26 ( V_14 , V_15 ) ;
V_45:
V_13 -> V_30 &= ~ V_42 ;
return V_21 ;
}
void F_27 ( struct V_12 * V_13 ,
unsigned long V_14 , unsigned long V_15 )
{
unsigned long V_20 ;
F_28 () ;
V_13 -> V_30 &= ~ V_42 ;
for ( V_20 = V_14 ; V_20 < V_15 ; V_20 += V_22 ) {
struct V_3 * V_3 ;
V_3 = F_29 ( V_13 , V_20 , V_48 | V_49 ) ;
if ( V_3 && ! F_30 ( V_3 ) ) {
F_31 ( V_3 ) ;
if ( V_3 -> V_4 )
F_16 ( V_3 ) ;
F_32 ( V_3 ) ;
F_33 ( V_3 ) ;
}
F_34 () ;
}
}
static int F_35 ( struct V_12 * V_13 , struct V_12 * * V_50 ,
unsigned long V_14 , unsigned long V_15 , T_1 V_51 )
{
struct V_17 * V_18 = V_13 -> V_19 ;
T_2 V_52 ;
int V_21 ;
int V_9 = 0 ;
int V_53 = ! ! ( V_51 & V_42 ) ;
if ( V_51 == V_13 -> V_30 || ( V_13 -> V_30 & V_54 ) ||
F_24 ( V_13 ) || V_13 == F_25 ( V_37 -> V_18 ) )
goto V_55;
V_52 = V_13 -> V_56 + ( ( V_14 - V_13 -> V_25 ) >> V_57 ) ;
* V_50 = F_36 ( V_18 , * V_50 , V_14 , V_15 , V_51 , V_13 -> V_58 ,
V_13 -> V_59 , V_52 , F_37 ( V_13 ) ) ;
if ( * V_50 ) {
V_13 = * V_50 ;
goto V_60;
}
if ( V_14 != V_13 -> V_25 ) {
V_9 = F_38 ( V_18 , V_13 , V_14 , 1 ) ;
if ( V_9 )
goto V_55;
}
if ( V_15 != V_13 -> V_26 ) {
V_9 = F_38 ( V_18 , V_13 , V_15 , 0 ) ;
if ( V_9 )
goto V_55;
}
V_60:
V_21 = ( V_15 - V_14 ) >> V_57 ;
if ( ! V_53 )
V_21 = - V_21 ;
V_18 -> V_61 += V_21 ;
if ( V_53 )
V_13 -> V_30 = V_51 ;
else
F_27 ( V_13 , V_14 , V_15 ) ;
V_55:
* V_50 = V_13 ;
return V_9 ;
}
static int F_39 ( unsigned long V_14 , T_3 V_62 , int V_63 )
{
unsigned long V_64 , V_15 , V_65 ;
struct V_12 * V_13 , * V_50 ;
int error ;
F_5 ( V_14 & ~ V_24 ) ;
F_5 ( V_62 != F_40 ( V_62 ) ) ;
V_15 = V_14 + V_62 ;
if ( V_15 < V_14 )
return - V_66 ;
if ( V_15 == V_14 )
return 0 ;
V_13 = F_41 ( V_37 -> V_18 , V_14 , & V_50 ) ;
if ( ! V_13 || V_13 -> V_25 > V_14 )
return - V_40 ;
if ( V_14 > V_13 -> V_25 )
V_50 = V_13 ;
for ( V_64 = V_14 ; ; ) {
T_1 V_51 ;
V_51 = V_13 -> V_30 | V_42 ;
if ( ! V_63 )
V_51 &= ~ V_42 ;
V_65 = V_13 -> V_26 ;
if ( V_65 > V_15 )
V_65 = V_15 ;
error = F_35 ( V_13 , & V_50 , V_64 , V_65 , V_51 ) ;
if ( error )
break;
V_64 = V_65 ;
if ( V_64 < V_50 -> V_26 )
V_64 = V_50 -> V_26 ;
if ( V_64 >= V_15 )
break;
V_13 = V_50 -> V_67 ;
if ( ! V_13 || V_13 -> V_25 != V_64 ) {
error = - V_40 ;
break;
}
}
return error ;
}
static int F_42 ( unsigned long V_14 , T_3 V_62 , int V_68 )
{
struct V_17 * V_18 = V_37 -> V_18 ;
unsigned long V_15 , V_64 , V_69 ;
struct V_12 * V_13 = NULL ;
int V_70 = 0 ;
int V_9 = 0 ;
F_5 ( V_14 & ~ V_24 ) ;
F_5 ( V_62 != F_40 ( V_62 ) ) ;
V_15 = V_14 + V_62 ;
for ( V_64 = V_14 ; V_64 < V_15 ; V_64 = V_69 ) {
if ( ! V_70 ) {
V_70 = 1 ;
F_43 ( & V_18 -> V_27 ) ;
V_13 = F_44 ( V_18 , V_64 ) ;
} else if ( V_64 >= V_13 -> V_26 )
V_13 = V_13 -> V_67 ;
if ( ! V_13 || V_13 -> V_25 >= V_15 )
break;
V_69 = F_45 ( V_15 , V_13 -> V_26 ) ;
if ( V_13 -> V_30 & ( V_43 | V_44 ) )
continue;
if ( V_64 < V_13 -> V_25 )
V_64 = V_13 -> V_25 ;
V_9 = F_19 ( V_13 , V_64 , V_69 , & V_70 ) ;
if ( V_9 < 0 ) {
if ( V_68 ) {
V_9 = 0 ;
continue;
}
V_9 = F_22 ( V_9 ) ;
break;
}
V_69 = V_64 + V_9 * V_22 ;
V_9 = 0 ;
}
if ( V_70 )
F_46 ( & V_18 -> V_27 ) ;
return V_9 ;
}
static int F_47 ( int V_71 )
{
struct V_12 * V_13 , * V_50 = NULL ;
unsigned int V_72 = 0 ;
if ( V_71 & V_73 )
V_72 = V_42 ;
V_37 -> V_18 -> V_72 = V_72 ;
if ( V_71 == V_73 )
goto V_55;
for ( V_13 = V_37 -> V_18 -> V_74 ; V_13 ; V_13 = V_50 -> V_67 ) {
T_1 V_51 ;
V_51 = V_13 -> V_30 | V_42 ;
if ( ! ( V_71 & V_75 ) )
V_51 &= ~ V_42 ;
F_35 ( V_13 , & V_50 , V_13 -> V_25 , V_13 -> V_26 , V_51 ) ;
}
V_55:
return 0 ;
}
int F_48 ( T_3 V_76 , struct V_77 * V_78 )
{
unsigned long V_79 , V_70 ;
int V_80 = 0 ;
V_70 = ( V_76 + V_22 - 1 ) >> V_57 ;
V_79 = F_3 ( V_2 ) ;
if ( V_79 == V_81 )
V_80 = 1 ;
V_79 >>= V_57 ;
F_49 ( & V_82 ) ;
if ( ! V_80 &&
V_70 + V_78 -> V_83 > V_79 && ! F_2 ( V_1 ) )
goto V_55;
F_50 ( V_78 ) ;
V_78 -> V_83 += V_70 ;
V_80 = 1 ;
V_55:
F_51 ( & V_82 ) ;
return V_80 ;
}
void F_52 ( T_3 V_76 , struct V_77 * V_78 )
{
F_49 ( & V_82 ) ;
V_78 -> V_83 -= ( V_76 + V_22 - 1 ) >> V_57 ;
F_51 ( & V_82 ) ;
F_53 ( V_78 ) ;
}
