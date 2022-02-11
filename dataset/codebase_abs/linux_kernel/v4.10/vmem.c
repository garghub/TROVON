static void T_1 * F_1 ( unsigned int V_1 )
{
unsigned long V_2 = V_3 << V_1 ;
if ( F_2 () )
return ( void * ) F_3 ( V_4 , V_1 ) ;
return ( void * ) F_4 ( V_2 , V_2 ) ;
}
static inline T_2 * F_5 ( void )
{
T_2 * V_5 = NULL ;
V_5 = F_1 ( 2 ) ;
if ( ! V_5 )
return NULL ;
F_6 ( ( unsigned long * ) V_5 , V_6 , V_3 * 4 ) ;
return V_5 ;
}
T_3 * F_7 ( void )
{
T_3 * V_7 = NULL ;
V_7 = F_1 ( 2 ) ;
if ( ! V_7 )
return NULL ;
F_6 ( ( unsigned long * ) V_7 , V_8 , V_3 * 4 ) ;
return V_7 ;
}
T_4 T_1 * F_8 ( void )
{
unsigned long V_2 = V_9 * sizeof( T_4 ) ;
T_4 * V_10 ;
if ( F_2 () )
V_10 = ( T_4 * ) F_9 ( & V_11 ) ;
else
V_10 = ( T_4 * ) F_4 ( V_2 , V_2 ) ;
if ( ! V_10 )
return NULL ;
F_6 ( ( unsigned long * ) V_10 , V_12 , V_2 ) ;
return V_10 ;
}
static int F_10 ( unsigned long V_13 , unsigned long V_2 )
{
unsigned long V_14 , V_15 , V_16 ;
unsigned long V_17 = V_13 + V_2 ;
unsigned long V_18 = V_13 ;
T_5 * V_19 ;
T_2 * V_20 ;
T_3 * V_21 ;
T_4 * V_22 ;
int V_23 = - V_24 ;
V_14 = V_15 = V_16 = 0 ;
while ( V_18 < V_17 ) {
V_19 = F_11 ( V_18 ) ;
if ( F_12 ( * V_19 ) ) {
V_20 = F_5 () ;
if ( ! V_20 )
goto V_25;
F_13 ( & V_11 , V_19 , V_20 ) ;
}
V_20 = F_14 ( V_19 , V_18 ) ;
if ( V_26 && F_15 ( * V_20 ) && V_18 &&
! ( V_18 & ~ V_27 ) && ( V_18 + V_28 <= V_17 ) &&
! F_16 () ) {
F_17 ( * V_20 ) = V_18 | F_18 ( V_29 ) ;
V_18 += V_28 ;
V_16 ++ ;
continue;
}
if ( F_15 ( * V_20 ) ) {
V_21 = F_7 () ;
if ( ! V_21 )
goto V_25;
F_19 ( & V_11 , V_20 , V_21 ) ;
}
V_21 = F_20 ( V_20 , V_18 ) ;
if ( V_30 && F_21 ( * V_21 ) && V_18 &&
! ( V_18 & ~ V_31 ) && ( V_18 + V_32 <= V_17 ) &&
! F_16 () ) {
F_22 ( * V_21 ) = V_18 | F_18 ( V_33 ) ;
V_18 += V_32 ;
V_15 ++ ;
continue;
}
if ( F_21 ( * V_21 ) ) {
V_22 = F_8 () ;
if ( ! V_22 )
goto V_25;
F_23 ( & V_11 , V_21 , V_22 ) ;
}
V_22 = F_24 ( V_21 , V_18 ) ;
F_25 ( * V_22 ) = V_18 | F_18 ( V_34 ) ;
V_18 += V_3 ;
V_14 ++ ;
}
V_23 = 0 ;
V_25:
F_26 ( V_35 , V_14 ) ;
F_26 ( V_36 , V_15 ) ;
F_26 ( V_37 , V_16 ) ;
return V_23 ;
}
static void F_27 ( unsigned long V_13 , unsigned long V_2 )
{
unsigned long V_14 , V_15 , V_16 ;
unsigned long V_17 = V_13 + V_2 ;
unsigned long V_18 = V_13 ;
T_5 * V_19 ;
T_2 * V_20 ;
T_3 * V_21 ;
T_4 * V_22 ;
V_14 = V_15 = V_16 = 0 ;
while ( V_18 < V_17 ) {
V_19 = F_11 ( V_18 ) ;
if ( F_12 ( * V_19 ) ) {
V_18 += V_38 ;
continue;
}
V_20 = F_14 ( V_19 , V_18 ) ;
if ( F_15 ( * V_20 ) ) {
V_18 += V_28 ;
continue;
}
if ( F_28 ( * V_20 ) ) {
F_29 ( V_20 ) ;
V_18 += V_28 ;
V_16 ++ ;
continue;
}
V_21 = F_20 ( V_20 , V_18 ) ;
if ( F_21 ( * V_21 ) ) {
V_18 += V_32 ;
continue;
}
if ( F_30 ( * V_21 ) ) {
F_31 ( V_21 ) ;
V_18 += V_32 ;
V_15 ++ ;
continue;
}
V_22 = F_24 ( V_21 , V_18 ) ;
F_32 ( & V_11 , V_18 , V_22 ) ;
V_18 += V_3 ;
V_14 ++ ;
}
F_33 ( V_13 , V_17 ) ;
F_26 ( V_35 , - V_14 ) ;
F_26 ( V_36 , - V_15 ) ;
F_26 ( V_37 , - V_16 ) ;
}
int T_6 F_34 ( unsigned long V_13 , unsigned long V_17 , int V_39 )
{
unsigned long V_18 = V_13 ;
T_5 * V_19 ;
T_2 * V_20 ;
T_3 * V_21 ;
T_4 * V_22 ;
int V_23 = - V_24 ;
for ( V_18 = V_13 ; V_18 < V_17 ; ) {
V_19 = F_11 ( V_18 ) ;
if ( F_12 ( * V_19 ) ) {
V_20 = F_5 () ;
if ( ! V_20 )
goto V_25;
F_13 ( & V_11 , V_19 , V_20 ) ;
}
V_20 = F_14 ( V_19 , V_18 ) ;
if ( F_15 ( * V_20 ) ) {
V_21 = F_7 () ;
if ( ! V_21 )
goto V_25;
F_19 ( & V_11 , V_20 , V_21 ) ;
}
V_21 = F_20 ( V_20 , V_18 ) ;
if ( F_21 ( * V_21 ) ) {
if ( V_30 ) {
void * V_40 ;
V_40 = F_35 ( V_32 , V_39 ) ;
if ( ! V_40 )
goto V_25;
F_22 ( * V_21 ) = F_36 ( V_40 ) |
V_41 | V_42 ;
V_18 = ( V_18 + V_32 ) & V_31 ;
continue;
}
V_22 = F_8 () ;
if ( ! V_22 )
goto V_25;
F_23 ( & V_11 , V_21 , V_22 ) ;
} else if ( F_30 ( * V_21 ) ) {
V_18 = ( V_18 + V_32 ) & V_31 ;
continue;
}
V_22 = F_24 ( V_21 , V_18 ) ;
if ( F_37 ( * V_22 ) ) {
void * V_40 ;
V_40 = F_35 ( V_3 , V_39 ) ;
if ( ! V_40 )
goto V_25;
F_25 ( * V_22 ) =
F_36 ( V_40 ) | F_18 ( V_34 ) ;
}
V_18 += V_3 ;
}
V_23 = 0 ;
V_25:
return V_23 ;
}
void F_38 ( unsigned long V_13 , unsigned long V_17 )
{
}
static int F_39 ( struct V_43 * V_44 )
{
struct V_43 * V_45 ;
if ( V_44 -> V_13 + V_44 -> V_2 > V_46 ||
V_44 -> V_13 + V_44 -> V_2 < V_44 -> V_13 )
return - V_47 ;
F_40 (tmp, &mem_segs, list) {
if ( V_44 -> V_13 >= V_45 -> V_13 + V_45 -> V_2 )
continue;
if ( V_44 -> V_13 + V_44 -> V_2 <= V_45 -> V_13 )
continue;
return - V_48 ;
}
F_41 ( & V_44 -> V_49 , & V_50 ) ;
return 0 ;
}
static void F_42 ( struct V_43 * V_44 )
{
F_43 ( & V_44 -> V_49 ) ;
}
static void F_44 ( struct V_43 * V_44 )
{
F_42 ( V_44 ) ;
F_27 ( V_44 -> V_13 , V_44 -> V_2 ) ;
}
int F_45 ( unsigned long V_13 , unsigned long V_2 )
{
struct V_43 * V_44 ;
int V_23 ;
F_46 ( & V_51 ) ;
V_23 = - V_52 ;
F_40 (seg, &mem_segs, list) {
if ( V_44 -> V_13 == V_13 && V_44 -> V_2 == V_2 )
break;
}
if ( V_44 -> V_13 != V_13 || V_44 -> V_2 != V_2 )
goto V_25;
V_23 = 0 ;
F_44 ( V_44 ) ;
F_47 ( V_44 ) ;
V_25:
F_48 ( & V_51 ) ;
return V_23 ;
}
int F_49 ( unsigned long V_13 , unsigned long V_2 )
{
struct V_43 * V_44 ;
int V_23 ;
F_46 ( & V_51 ) ;
V_23 = - V_24 ;
V_44 = F_50 ( sizeof( * V_44 ) , V_4 ) ;
if ( ! V_44 )
goto V_25;
V_44 -> V_13 = V_13 ;
V_44 -> V_2 = V_2 ;
V_23 = F_39 ( V_44 ) ;
if ( V_23 )
goto V_53;
V_23 = F_10 ( V_13 , V_2 ) ;
if ( V_23 )
goto V_54;
goto V_25;
V_54:
F_44 ( V_44 ) ;
V_53:
F_47 ( V_44 ) ;
V_25:
F_48 ( & V_51 ) ;
return V_23 ;
}
void T_7 F_51 ( void )
{
unsigned long V_2 = V_55 - V_56 ;
struct V_57 * V_58 ;
F_52 (memory, reg)
F_10 ( V_58 -> V_59 , V_58 -> V_2 ) ;
F_53 ( ( unsigned long ) V_56 , V_2 >> V_60 ) ;
F_54 ( L_1 , V_2 >> 10 ) ;
}
static int T_7 F_55 ( void )
{
struct V_57 * V_58 ;
struct V_43 * V_44 ;
F_46 ( & V_51 ) ;
F_52 (memory, reg) {
V_44 = F_50 ( sizeof( * V_44 ) , V_4 ) ;
if ( ! V_44 )
F_56 ( L_2 ) ;
V_44 -> V_13 = V_58 -> V_59 ;
V_44 -> V_2 = V_58 -> V_2 ;
F_39 ( V_44 ) ;
}
F_48 ( & V_51 ) ;
return 0 ;
}
