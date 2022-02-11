void T_1 * F_1 ( T_2 V_1 , void * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
unsigned long V_5 ;
if ( ( V_4 & V_6 ) == 0 )
V_4 |= F_2 ( V_7 ) ;
if ( V_4 & V_8 )
return NULL ;
F_3 ( V_1 & ~ V_9 ) ;
F_3 ( ( ( unsigned long ) V_2 ) & ~ V_9 ) ;
F_3 ( V_3 & ~ V_9 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 += V_10 )
if ( F_4 ( ( unsigned long ) V_2 + V_5 , V_1 + V_5 , V_4 ) )
return NULL ;
return ( void T_1 * ) V_2 ;
}
void F_5 ( void * V_2 , unsigned long V_3 )
{
F_3 ( ( ( unsigned long ) V_2 ) & ~ V_9 ) ;
F_3 ( V_3 & ~ V_9 ) ;
F_6 ( ( unsigned long ) V_2 , V_3 ) ;
}
void T_1 * F_7 ( T_2 V_11 , unsigned long V_3 ,
unsigned long V_4 , void * V_12 )
{
T_2 V_13 ;
void T_1 * V_14 ;
V_13 = V_11 & V_9 ;
V_3 = F_8 ( V_11 + V_3 ) - V_13 ;
if ( ( V_3 == 0 ) || ( V_13 == 0 ) )
return NULL ;
if ( F_9 () ) {
struct V_15 * V_16 ;
V_16 = F_10 ( V_3 , V_17 ,
V_18 , V_19 ,
V_12 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_20 = V_13 ;
V_14 = F_1 ( V_13 , V_16 -> V_11 , V_3 , V_4 ) ;
if ( ! V_14 )
F_11 ( V_16 -> V_11 ) ;
} else {
V_14 = F_1 ( V_13 , ( void * ) V_18 , V_3 , V_4 ) ;
if ( V_14 )
V_18 += V_3 ;
}
if ( V_14 )
V_14 += V_11 & ~ V_9 ;
return V_14 ;
}
void T_1 * F_12 ( T_2 V_11 , unsigned long V_3 ,
unsigned long V_4 )
{
return F_7 ( V_11 , V_3 , V_4 , F_13 ( 0 ) ) ;
}
void T_1 * F_14 ( T_2 V_11 , unsigned long V_3 )
{
unsigned long V_4 = F_2 ( F_15 ( F_16 ( 0 ) ) ) ;
void * V_12 = F_13 ( 0 ) ;
if ( V_21 . F_14 )
return V_21 . F_14 ( V_11 , V_3 , V_4 , V_12 ) ;
return F_7 ( V_11 , V_3 , V_4 , V_12 ) ;
}
void T_1 * F_17 ( T_2 V_11 , unsigned long V_3 )
{
unsigned long V_4 = F_2 ( F_18 ( F_16 ( 0 ) ) ) ;
void * V_12 = F_13 ( 0 ) ;
if ( V_21 . F_14 )
return V_21 . F_14 ( V_11 , V_3 , V_4 , V_12 ) ;
return F_7 ( V_11 , V_3 , V_4 , V_12 ) ;
}
void T_1 * F_19 ( T_2 V_11 , unsigned long V_3 ,
unsigned long V_4 )
{
void * V_12 = F_13 ( 0 ) ;
if ( V_4 & V_22 )
V_4 |= V_23 ;
V_4 &= ~ V_24 ;
#if F_20 ( V_25 )
V_4 |= V_26 ;
#else
V_4 &= ~ V_27 ;
#endif
#ifdef F_21
V_4 |= F_21 ;
#endif
if ( V_21 . F_14 )
return V_21 . F_14 ( V_11 , V_3 , V_4 , V_12 ) ;
return F_7 ( V_11 , V_3 , V_4 , V_12 ) ;
}
void F_22 ( volatile void T_1 * V_28 )
{
void * V_11 ;
if ( ! F_9 () )
return;
V_11 = ( void * ) ( ( unsigned long V_29 )
F_23 ( V_28 ) & V_9 ) ;
if ( ( unsigned long ) V_11 < V_18 ) {
F_24 ( V_30 L_1
L_2 , V_11 ) ;
return;
}
F_11 ( V_11 ) ;
}
void F_25 ( volatile void T_1 * V_28 )
{
if ( V_21 . F_25 )
V_21 . F_25 ( V_28 ) ;
else
F_22 ( V_28 ) ;
}
struct V_31 * F_26 ( T_3 V_32 )
{
if ( F_27 ( V_32 ) )
return F_28 ( F_29 ( V_32 ) ) ;
return F_30 ( F_31 ( V_32 ) ) ;
}
struct V_31 * F_32 ( T_4 V_33 )
{
if ( F_33 ( V_33 ) )
return F_28 ( F_34 ( V_33 ) ) ;
return F_30 ( F_35 ( V_33 ) ) ;
}
struct V_31 * F_36 ( T_5 V_34 )
{
if ( F_37 ( V_34 ) || F_38 ( V_34 ) )
return F_28 ( F_39 ( V_34 ) ) ;
return F_30 ( F_40 ( V_34 ) ) ;
}
static T_6 * F_41 ( struct V_35 * V_36 )
{
void * V_37 , * V_14 ;
F_42 ( & V_36 -> V_38 ) ;
V_14 = V_36 -> V_39 . V_37 ;
if ( V_14 ) {
V_37 = V_14 + V_40 ;
if ( ( ( unsigned long ) V_37 & ~ V_9 ) == 0 )
V_37 = NULL ;
V_36 -> V_39 . V_37 = V_37 ;
}
F_43 ( & V_36 -> V_38 ) ;
return ( T_6 * ) V_14 ;
}
static T_6 * F_44 ( struct V_35 * V_36 , int V_41 )
{
void * V_14 = NULL ;
struct V_31 * V_31 = F_45 ( V_42 | V_43 | V_44 ) ;
if ( ! V_31 )
return NULL ;
if ( ! V_41 && ! F_46 ( V_31 ) ) {
F_47 ( V_31 ) ;
return NULL ;
}
V_14 = F_48 ( V_31 ) ;
F_42 ( & V_36 -> V_38 ) ;
if ( F_49 ( ! V_36 -> V_39 . V_37 ) ) {
F_50 ( V_31 , V_45 ) ;
V_36 -> V_39 . V_37 = V_14 + V_40 ;
}
F_43 ( & V_36 -> V_38 ) ;
return ( T_6 * ) V_14 ;
}
T_6 * F_51 ( struct V_35 * V_36 , unsigned long V_46 , int V_41 )
{
T_6 * V_47 ;
V_47 = F_41 ( V_36 ) ;
if ( V_47 )
return V_47 ;
return F_44 ( V_36 , V_41 ) ;
}
void F_52 ( unsigned long * V_48 , int V_41 )
{
struct V_31 * V_31 = F_30 ( V_48 ) ;
if ( F_53 ( V_31 ) ) {
if ( ! V_41 )
F_54 ( V_31 ) ;
F_55 ( V_31 , 0 ) ;
}
}
void F_56 ( struct V_49 * V_50 , void * V_48 , int V_51 )
{
unsigned long V_52 = ( unsigned long ) V_48 ;
F_57 ( V_51 > V_53 ) ;
V_52 |= V_51 ;
F_58 ( V_50 , ( void * ) V_52 ) ;
}
void F_59 ( void * V_54 )
{
void * V_48 = ( void * ) ( ( unsigned long ) V_54 & ~ V_53 ) ;
unsigned V_51 = ( unsigned long ) V_54 & V_53 ;
if ( ! V_51 )
F_52 ( V_48 , 0 ) ;
else {
F_57 ( V_51 > V_53 ) ;
F_60 ( F_61 ( V_51 ) , V_48 ) ;
}
}
void F_56 ( struct V_49 * V_50 , void * V_48 , int V_51 )
{
if ( ! V_51 ) {
F_52 ( V_48 , 0 ) ;
} else {
F_57 ( V_51 > V_53 ) ;
F_60 ( F_61 ( V_51 ) , V_48 ) ;
}
}
