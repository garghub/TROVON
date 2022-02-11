static void T_1 * F_1 ( unsigned int V_1 )
{
if ( F_2 () )
return ( void * ) F_3 ( V_2 , V_1 ) ;
return F_4 ( ( 1 << V_1 ) * V_3 ) ;
}
static inline T_2 * F_5 ( void )
{
T_2 * V_4 = NULL ;
#ifdef F_6
V_4 = F_1 ( 2 ) ;
if ( ! V_4 )
return NULL ;
F_7 ( ( unsigned long * ) V_4 , V_5 , V_3 * 4 ) ;
#endif
return V_4 ;
}
static inline T_3 * F_8 ( void )
{
T_3 * V_6 = NULL ;
#ifdef F_6
V_6 = F_1 ( 2 ) ;
if ( ! V_6 )
return NULL ;
F_7 ( ( unsigned long * ) V_6 , V_7 , V_3 * 4 ) ;
#endif
return V_6 ;
}
static T_4 T_1 * F_9 ( unsigned long V_8 )
{
T_4 * V_9 ;
if ( F_2 () )
V_9 = ( T_4 * ) F_10 ( & V_10 , V_8 ) ;
else
V_9 = F_11 ( V_11 * sizeof( T_4 ) ,
V_11 * sizeof( T_4 ) ) ;
if ( ! V_9 )
return NULL ;
F_7 ( ( unsigned long * ) V_9 , V_12 ,
V_11 * sizeof( T_4 ) ) ;
return V_9 ;
}
static int F_12 ( unsigned long V_13 , unsigned long V_14 , int V_15 )
{
unsigned long V_16 = V_13 + V_14 ;
unsigned long V_8 = V_13 ;
T_5 * V_17 ;
T_2 * V_18 ;
T_3 * V_19 ;
T_4 * V_20 ;
int V_21 = - V_22 ;
while ( V_8 < V_16 ) {
V_17 = F_13 ( V_8 ) ;
if ( F_14 ( * V_17 ) ) {
V_18 = F_5 () ;
if ( ! V_18 )
goto V_23;
F_15 ( & V_10 , V_17 , V_18 ) ;
}
V_18 = F_16 ( V_17 , V_8 ) ;
#if F_17 ( F_6 ) && ! F_17 ( V_24 )
if ( V_25 && F_18 ( * V_18 ) && V_8 &&
! ( V_8 & ~ V_26 ) && ( V_8 + V_27 <= V_16 ) ) {
F_19 ( * V_18 ) = F_20 ( V_8 ) |
V_28 | V_29 |
( V_15 ? V_30 : 0 ) ;
V_8 += V_27 ;
continue;
}
#endif
if ( F_18 ( * V_18 ) ) {
V_19 = F_8 () ;
if ( ! V_19 )
goto V_23;
F_21 ( & V_10 , V_18 , V_19 ) ;
}
V_19 = F_22 ( V_18 , V_8 ) ;
#if F_17 ( F_6 ) && ! F_17 ( V_24 )
if ( V_31 && F_23 ( * V_19 ) && V_8 &&
! ( V_8 & ~ V_32 ) && ( V_8 + V_33 <= V_16 ) ) {
F_24 ( * V_19 ) = F_20 ( V_8 ) |
V_34 | V_35 |
V_36 |
( V_15 ? V_37 : 0 ) ;
V_8 += V_33 ;
continue;
}
#endif
if ( F_23 ( * V_19 ) ) {
V_20 = F_9 ( V_8 ) ;
if ( ! V_20 )
goto V_23;
F_25 ( & V_10 , V_19 , V_20 ) ;
}
V_20 = F_26 ( V_19 , V_8 ) ;
F_27 ( * V_20 ) = F_20 ( V_8 ) |
F_28 ( V_15 ? V_38 : V_39 ) ;
V_8 += V_3 ;
}
V_21 = 0 ;
V_23:
return V_21 ;
}
static void F_29 ( unsigned long V_13 , unsigned long V_14 )
{
unsigned long V_16 = V_13 + V_14 ;
unsigned long V_8 = V_13 ;
T_5 * V_17 ;
T_2 * V_18 ;
T_3 * V_19 ;
T_4 * V_20 ;
T_4 V_9 ;
F_27 ( V_9 ) = V_12 ;
while ( V_8 < V_16 ) {
V_17 = F_13 ( V_8 ) ;
if ( F_14 ( * V_17 ) ) {
V_8 += V_40 ;
continue;
}
V_18 = F_16 ( V_17 , V_8 ) ;
if ( F_18 ( * V_18 ) ) {
V_8 += V_27 ;
continue;
}
if ( F_30 ( * V_18 ) ) {
F_31 ( V_18 ) ;
V_8 += V_27 ;
continue;
}
V_19 = F_22 ( V_18 , V_8 ) ;
if ( F_23 ( * V_19 ) ) {
V_8 += V_33 ;
continue;
}
if ( F_32 ( * V_19 ) ) {
F_33 ( V_19 ) ;
V_8 += V_33 ;
continue;
}
V_20 = F_26 ( V_19 , V_8 ) ;
* V_20 = V_9 ;
V_8 += V_3 ;
}
F_34 ( V_13 , V_16 ) ;
}
int T_6 F_35 ( unsigned long V_13 , unsigned long V_16 , int V_41 )
{
unsigned long V_8 = V_13 ;
T_5 * V_17 ;
T_2 * V_18 ;
T_3 * V_19 ;
T_4 * V_20 ;
int V_21 = - V_22 ;
for ( V_8 = V_13 ; V_8 < V_16 ; ) {
V_17 = F_13 ( V_8 ) ;
if ( F_14 ( * V_17 ) ) {
V_18 = F_5 () ;
if ( ! V_18 )
goto V_23;
F_15 ( & V_10 , V_17 , V_18 ) ;
}
V_18 = F_16 ( V_17 , V_8 ) ;
if ( F_18 ( * V_18 ) ) {
V_19 = F_8 () ;
if ( ! V_19 )
goto V_23;
F_21 ( & V_10 , V_18 , V_19 ) ;
}
V_19 = F_22 ( V_18 , V_8 ) ;
if ( F_23 ( * V_19 ) ) {
#ifdef F_6
if ( V_31 ) {
void * V_42 ;
V_42 = F_36 ( V_33 , V_41 ) ;
if ( ! V_42 )
goto V_23;
F_24 ( * V_19 ) = F_20 ( V_42 ) |
V_34 | V_35 |
V_43 ;
V_8 = ( V_8 + V_33 ) & V_32 ;
continue;
}
#endif
V_20 = F_9 ( V_8 ) ;
if ( ! V_20 )
goto V_23;
F_25 ( & V_10 , V_19 , V_20 ) ;
} else if ( F_32 ( * V_19 ) ) {
V_8 = ( V_8 + V_33 ) & V_32 ;
continue;
}
V_20 = F_26 ( V_19 , V_8 ) ;
if ( F_37 ( * V_20 ) ) {
unsigned long V_42 ;
V_42 = F_20 ( F_1 ( 0 ) ) ;
if ( ! V_42 )
goto V_23;
F_27 ( * V_20 ) =
F_20 ( V_42 ) | F_28 ( V_39 ) ;
}
V_8 += V_3 ;
}
memset ( ( void * ) V_13 , 0 , V_16 - V_13 ) ;
V_21 = 0 ;
V_23:
return V_21 ;
}
void F_38 ( unsigned long V_13 , unsigned long V_16 )
{
}
static int F_39 ( struct V_44 * V_45 )
{
struct V_44 * V_46 ;
if ( V_45 -> V_13 + V_45 -> V_14 > V_47 ||
V_45 -> V_13 + V_45 -> V_14 < V_45 -> V_13 )
return - V_48 ;
F_40 (tmp, &mem_segs, list) {
if ( V_45 -> V_13 >= V_46 -> V_13 + V_46 -> V_14 )
continue;
if ( V_45 -> V_13 + V_45 -> V_14 <= V_46 -> V_13 )
continue;
return - V_49 ;
}
F_41 ( & V_45 -> V_50 , & V_51 ) ;
return 0 ;
}
static void F_42 ( struct V_44 * V_45 )
{
F_43 ( & V_45 -> V_50 ) ;
}
static void F_44 ( struct V_44 * V_45 )
{
F_42 ( V_45 ) ;
F_29 ( V_45 -> V_13 , V_45 -> V_14 ) ;
}
int F_45 ( unsigned long V_13 , unsigned long V_14 )
{
struct V_44 * V_45 ;
int V_21 ;
F_46 ( & V_52 ) ;
V_21 = - V_53 ;
F_40 (seg, &mem_segs, list) {
if ( V_45 -> V_13 == V_13 && V_45 -> V_14 == V_14 )
break;
}
if ( V_45 -> V_13 != V_13 || V_45 -> V_14 != V_14 )
goto V_23;
V_21 = 0 ;
F_44 ( V_45 ) ;
F_47 ( V_45 ) ;
V_23:
F_48 ( & V_52 ) ;
return V_21 ;
}
int F_49 ( unsigned long V_13 , unsigned long V_14 )
{
struct V_44 * V_45 ;
int V_21 ;
F_46 ( & V_52 ) ;
V_21 = - V_22 ;
V_45 = F_50 ( sizeof( * V_45 ) , V_2 ) ;
if ( ! V_45 )
goto V_23;
V_45 -> V_13 = V_13 ;
V_45 -> V_14 = V_14 ;
V_21 = F_39 ( V_45 ) ;
if ( V_21 )
goto V_54;
V_21 = F_12 ( V_13 , V_14 , 0 ) ;
if ( V_21 )
goto V_55;
goto V_23;
V_55:
F_44 ( V_45 ) ;
V_54:
F_47 ( V_45 ) ;
V_23:
F_48 ( & V_52 ) ;
return V_21 ;
}
void T_7 F_51 ( void )
{
unsigned long V_56 , V_57 ;
struct V_58 * V_59 ;
T_8 V_13 , V_16 ;
V_56 = F_52 ( ( unsigned long ) & V_60 ) ;
V_57 = ( unsigned long ) & V_61 & V_62 ;
F_53 (memory, reg) {
V_13 = V_59 -> V_63 ;
V_16 = V_59 -> V_63 + V_59 -> V_14 - 1 ;
if ( V_13 >= V_57 || V_16 <= V_56 )
F_12 ( V_13 , V_16 - V_13 , 0 ) ;
else if ( V_13 >= V_56 && V_16 <= V_57 )
F_12 ( V_13 , V_16 - V_13 , 1 ) ;
else if ( V_13 >= V_56 ) {
F_12 ( V_13 , V_57 - V_13 , 1 ) ;
F_12 ( V_57 , V_16 - V_57 , 0 ) ;
} else if ( V_16 < V_57 ) {
F_12 ( V_13 , V_56 - V_13 , 0 ) ;
F_12 ( V_56 , V_16 - V_56 , 1 ) ;
} else {
F_12 ( V_13 , V_56 - V_13 , 0 ) ;
F_12 ( V_56 , V_57 - V_56 , 1 ) ;
F_12 ( V_57 , V_16 - V_57 , 0 ) ;
}
}
}
static int T_7 F_54 ( void )
{
struct V_58 * V_59 ;
struct V_44 * V_45 ;
F_46 ( & V_52 ) ;
F_53 (memory, reg) {
V_45 = F_50 ( sizeof( * V_45 ) , V_2 ) ;
if ( ! V_45 )
F_55 ( L_1 ) ;
V_45 -> V_13 = V_59 -> V_63 ;
V_45 -> V_14 = V_59 -> V_14 ;
F_39 ( V_45 ) ;
}
F_48 ( & V_52 ) ;
return 0 ;
}
