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
int V_9 = V_10 ;
if ( F_18 ( V_3 ) > 1 )
V_9 = F_19 ( V_3 ) ;
if ( V_9 != V_11 )
F_8 ( V_12 ) ;
F_10 ( V_3 ) ;
} else {
if ( F_11 ( V_3 ) )
F_8 ( V_7 ) ;
else
F_8 ( V_12 ) ;
}
}
}
static long F_20 ( struct V_13 * V_14 ,
unsigned long V_15 , unsigned long V_16 ,
int * V_17 )
{
struct V_18 * V_19 = V_14 -> V_20 ;
unsigned long V_21 = V_15 ;
int V_22 = ( V_16 - V_15 ) / V_23 ;
int V_24 ;
F_5 ( V_15 & ~ V_25 ) ;
F_5 ( V_16 & ~ V_25 ) ;
F_5 ( V_15 < V_14 -> V_26 ) ;
F_5 ( V_16 > V_14 -> V_27 ) ;
F_5 ( ! F_21 ( & V_19 -> V_28 ) ) ;
V_24 = V_29 | V_30 ;
if ( ( V_14 -> V_31 & ( V_32 | V_33 ) ) == V_32 )
V_24 |= V_34 ;
if ( V_14 -> V_31 & ( V_35 | V_32 | V_36 ) )
V_24 |= V_37 ;
return F_22 ( V_38 , V_19 , V_21 , V_22 , V_24 ,
NULL , NULL , V_17 ) ;
}
static int F_23 ( long V_39 )
{
if ( V_39 == - V_40 )
V_39 = - V_41 ;
else if ( V_39 == - V_41 )
V_39 = - V_42 ;
return V_39 ;
}
long F_24 ( struct V_13 * V_14 ,
unsigned long V_15 , unsigned long V_16 )
{
int V_22 = ( V_16 - V_15 ) / V_23 ;
F_13 ( ! ( V_14 -> V_31 & V_43 ) ) ;
if ( V_14 -> V_31 & ( V_44 | V_45 ) )
goto V_46;
if ( ! ( ( V_14 -> V_31 & ( V_47 | V_48 ) ) ||
F_25 ( V_14 ) ||
V_14 == F_26 ( V_38 -> V_19 ) ) ) {
F_20 ( V_14 , V_15 , V_16 , NULL ) ;
return 0 ;
}
F_27 ( V_15 , V_16 ) ;
V_46:
V_14 -> V_31 &= ~ V_43 ;
return V_22 ;
}
void F_28 ( struct V_13 * V_14 ,
unsigned long V_15 , unsigned long V_16 )
{
unsigned long V_21 ;
F_29 () ;
V_14 -> V_31 &= ~ V_43 ;
for ( V_21 = V_15 ; V_21 < V_16 ; V_21 += V_23 ) {
struct V_3 * V_3 ;
V_3 = F_30 ( V_14 , V_21 , V_49 | V_50 ) ;
if ( V_3 && ! F_31 ( V_3 ) ) {
F_32 ( V_3 ) ;
if ( V_3 -> V_4 )
F_16 ( V_3 ) ;
F_33 ( V_3 ) ;
F_34 ( V_3 ) ;
}
F_35 () ;
}
}
static int F_36 ( struct V_13 * V_14 , struct V_13 * * V_51 ,
unsigned long V_15 , unsigned long V_16 , T_1 V_52 )
{
struct V_18 * V_19 = V_14 -> V_20 ;
T_2 V_53 ;
int V_22 ;
int V_9 = 0 ;
int V_54 = ! ! ( V_52 & V_43 ) ;
if ( V_52 == V_14 -> V_31 || ( V_14 -> V_31 & V_55 ) ||
F_25 ( V_14 ) || V_14 == F_26 ( V_38 -> V_19 ) )
goto V_56;
V_53 = V_14 -> V_57 + ( ( V_15 - V_14 -> V_26 ) >> V_58 ) ;
* V_51 = F_37 ( V_19 , * V_51 , V_15 , V_16 , V_52 , V_14 -> V_59 ,
V_14 -> V_60 , V_53 , F_38 ( V_14 ) ) ;
if ( * V_51 ) {
V_14 = * V_51 ;
goto V_61;
}
if ( V_15 != V_14 -> V_26 ) {
V_9 = F_39 ( V_19 , V_14 , V_15 , 1 ) ;
if ( V_9 )
goto V_56;
}
if ( V_16 != V_14 -> V_27 ) {
V_9 = F_39 ( V_19 , V_14 , V_16 , 0 ) ;
if ( V_9 )
goto V_56;
}
V_61:
V_22 = ( V_16 - V_15 ) >> V_58 ;
if ( ! V_54 )
V_22 = - V_22 ;
V_19 -> V_62 += V_22 ;
if ( V_54 )
V_14 -> V_31 = V_52 ;
else
F_28 ( V_14 , V_15 , V_16 ) ;
V_56:
* V_51 = V_14 ;
return V_9 ;
}
static int F_40 ( unsigned long V_15 , T_3 V_63 , int V_64 )
{
unsigned long V_65 , V_16 , V_66 ;
struct V_13 * V_14 , * V_51 ;
int error ;
F_5 ( V_15 & ~ V_25 ) ;
F_5 ( V_63 != F_41 ( V_63 ) ) ;
V_16 = V_15 + V_63 ;
if ( V_16 < V_15 )
return - V_67 ;
if ( V_16 == V_15 )
return 0 ;
V_14 = F_42 ( V_38 -> V_19 , V_15 , & V_51 ) ;
if ( ! V_14 || V_14 -> V_26 > V_15 )
return - V_41 ;
if ( V_15 > V_14 -> V_26 )
V_51 = V_14 ;
for ( V_65 = V_15 ; ; ) {
T_1 V_52 ;
V_52 = V_14 -> V_31 | V_43 ;
if ( ! V_64 )
V_52 &= ~ V_43 ;
V_66 = V_14 -> V_27 ;
if ( V_66 > V_16 )
V_66 = V_16 ;
error = F_36 ( V_14 , & V_51 , V_65 , V_66 , V_52 ) ;
if ( error )
break;
V_65 = V_66 ;
if ( V_65 < V_51 -> V_27 )
V_65 = V_51 -> V_27 ;
if ( V_65 >= V_16 )
break;
V_14 = V_51 -> V_68 ;
if ( ! V_14 || V_14 -> V_26 != V_65 ) {
error = - V_41 ;
break;
}
}
return error ;
}
static int F_43 ( unsigned long V_15 , T_3 V_63 , int V_69 )
{
struct V_18 * V_19 = V_38 -> V_19 ;
unsigned long V_16 , V_65 , V_70 ;
struct V_13 * V_14 = NULL ;
int V_71 = 0 ;
int V_9 = 0 ;
F_5 ( V_15 & ~ V_25 ) ;
F_5 ( V_63 != F_41 ( V_63 ) ) ;
V_16 = V_15 + V_63 ;
for ( V_65 = V_15 ; V_65 < V_16 ; V_65 = V_70 ) {
if ( ! V_71 ) {
V_71 = 1 ;
F_44 ( & V_19 -> V_28 ) ;
V_14 = F_45 ( V_19 , V_65 ) ;
} else if ( V_65 >= V_14 -> V_27 )
V_14 = V_14 -> V_68 ;
if ( ! V_14 || V_14 -> V_26 >= V_16 )
break;
V_70 = F_46 ( V_16 , V_14 -> V_27 ) ;
if ( V_14 -> V_31 & ( V_44 | V_45 ) )
continue;
if ( V_65 < V_14 -> V_26 )
V_65 = V_14 -> V_26 ;
V_9 = F_20 ( V_14 , V_65 , V_70 , & V_71 ) ;
if ( V_9 < 0 ) {
if ( V_69 ) {
V_9 = 0 ;
continue;
}
V_9 = F_23 ( V_9 ) ;
break;
}
V_70 = V_65 + V_9 * V_23 ;
V_9 = 0 ;
}
if ( V_71 )
F_47 ( & V_19 -> V_28 ) ;
return V_9 ;
}
static int F_48 ( int V_72 )
{
struct V_13 * V_14 , * V_51 = NULL ;
unsigned int V_73 = 0 ;
if ( V_72 & V_74 )
V_73 = V_43 ;
V_38 -> V_19 -> V_73 = V_73 ;
if ( V_72 == V_74 )
goto V_56;
for ( V_14 = V_38 -> V_19 -> V_75 ; V_14 ; V_14 = V_51 -> V_68 ) {
T_1 V_52 ;
V_52 = V_14 -> V_31 | V_43 ;
if ( ! ( V_72 & V_76 ) )
V_52 &= ~ V_43 ;
F_36 ( V_14 , & V_51 , V_14 -> V_26 , V_14 -> V_27 , V_52 ) ;
}
V_56:
return 0 ;
}
int F_49 ( T_3 V_77 , struct V_78 * V_79 )
{
unsigned long V_80 , V_71 ;
int V_81 = 0 ;
V_71 = ( V_77 + V_23 - 1 ) >> V_58 ;
V_80 = F_3 ( V_2 ) ;
if ( V_80 == V_82 )
V_81 = 1 ;
V_80 >>= V_58 ;
F_50 ( & V_83 ) ;
if ( ! V_81 &&
V_71 + V_79 -> V_84 > V_80 && ! F_2 ( V_1 ) )
goto V_56;
F_51 ( V_79 ) ;
V_79 -> V_84 += V_71 ;
V_81 = 1 ;
V_56:
F_52 ( & V_83 ) ;
return V_81 ;
}
void F_53 ( T_3 V_77 , struct V_78 * V_79 )
{
F_50 ( & V_83 ) ;
V_79 -> V_84 -= ( V_77 + V_23 - 1 ) >> V_58 ;
F_52 ( & V_83 ) ;
F_54 ( V_79 ) ;
}
