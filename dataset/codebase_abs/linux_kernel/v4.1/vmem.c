static void T_1 * F_1 ( unsigned int V_1 )
{
if ( F_2 () )
return ( void * ) F_3 ( V_2 , V_1 ) ;
return F_4 ( ( 1 << V_1 ) * V_3 ) ;
}
static inline T_2 * F_5 ( void )
{
T_2 * V_4 = NULL ;
V_4 = F_1 ( 2 ) ;
if ( ! V_4 )
return NULL ;
F_6 ( ( unsigned long * ) V_4 , V_5 , V_3 * 4 ) ;
return V_4 ;
}
static inline T_3 * F_7 ( void )
{
T_3 * V_6 = NULL ;
V_6 = F_1 ( 2 ) ;
if ( ! V_6 )
return NULL ;
F_6 ( ( unsigned long * ) V_6 , V_7 , V_3 * 4 ) ;
return V_6 ;
}
static T_4 T_1 * F_8 ( unsigned long V_8 )
{
T_4 * V_9 ;
if ( F_2 () )
V_9 = ( T_4 * ) F_9 ( & V_10 ) ;
else
V_9 = F_10 ( V_11 * sizeof( T_4 ) ,
V_11 * sizeof( T_4 ) ) ;
if ( ! V_9 )
return NULL ;
F_6 ( ( unsigned long * ) V_9 , V_12 ,
V_11 * sizeof( T_4 ) ) ;
return V_9 ;
}
static int F_11 ( unsigned long V_13 , unsigned long V_14 , int V_15 )
{
unsigned long V_16 = V_13 + V_14 ;
unsigned long V_8 = V_13 ;
T_5 * V_17 ;
T_2 * V_18 ;
T_3 * V_19 ;
T_4 * V_20 ;
int V_21 = - V_22 ;
while ( V_8 < V_16 ) {
V_17 = F_12 ( V_8 ) ;
if ( F_13 ( * V_17 ) ) {
V_18 = F_5 () ;
if ( ! V_18 )
goto V_23;
F_14 ( & V_10 , V_17 , V_18 ) ;
}
V_18 = F_15 ( V_17 , V_8 ) ;
#ifndef F_16
if ( V_24 && F_17 ( * V_18 ) && V_8 &&
! ( V_8 & ~ V_25 ) && ( V_8 + V_26 <= V_16 ) ) {
F_18 ( * V_18 ) = F_19 ( V_8 ) |
V_27 | V_28 |
( V_15 ? V_29 : 0 ) ;
V_8 += V_26 ;
continue;
}
#endif
if ( F_17 ( * V_18 ) ) {
V_19 = F_7 () ;
if ( ! V_19 )
goto V_23;
F_20 ( & V_10 , V_18 , V_19 ) ;
}
V_19 = F_21 ( V_18 , V_8 ) ;
#ifndef F_16
if ( V_30 && F_22 ( * V_19 ) && V_8 &&
! ( V_8 & ~ V_31 ) && ( V_8 + V_32 <= V_16 ) ) {
F_23 ( * V_19 ) = F_19 ( V_8 ) |
V_33 | V_34 |
V_35 |
( V_15 ? V_36 : 0 ) ;
V_8 += V_32 ;
continue;
}
#endif
if ( F_22 ( * V_19 ) ) {
V_20 = F_8 ( V_8 ) ;
if ( ! V_20 )
goto V_23;
F_24 ( & V_10 , V_19 , V_20 ) ;
}
V_20 = F_25 ( V_19 , V_8 ) ;
F_26 ( * V_20 ) = F_19 ( V_8 ) |
F_27 ( V_15 ? V_37 : V_38 ) ;
V_8 += V_3 ;
}
V_21 = 0 ;
V_23:
return V_21 ;
}
static void F_28 ( unsigned long V_13 , unsigned long V_14 )
{
unsigned long V_16 = V_13 + V_14 ;
unsigned long V_8 = V_13 ;
T_5 * V_17 ;
T_2 * V_18 ;
T_3 * V_19 ;
T_4 * V_20 ;
T_4 V_9 ;
F_26 ( V_9 ) = V_12 ;
while ( V_8 < V_16 ) {
V_17 = F_12 ( V_8 ) ;
if ( F_13 ( * V_17 ) ) {
V_8 += V_39 ;
continue;
}
V_18 = F_15 ( V_17 , V_8 ) ;
if ( F_17 ( * V_18 ) ) {
V_8 += V_26 ;
continue;
}
if ( F_29 ( * V_18 ) ) {
F_30 ( V_18 ) ;
V_8 += V_26 ;
continue;
}
V_19 = F_21 ( V_18 , V_8 ) ;
if ( F_22 ( * V_19 ) ) {
V_8 += V_32 ;
continue;
}
if ( F_31 ( * V_19 ) ) {
F_32 ( V_19 ) ;
V_8 += V_32 ;
continue;
}
V_20 = F_25 ( V_19 , V_8 ) ;
* V_20 = V_9 ;
V_8 += V_3 ;
}
F_33 ( V_13 , V_16 ) ;
}
int T_6 F_34 ( unsigned long V_13 , unsigned long V_16 , int V_40 )
{
unsigned long V_8 = V_13 ;
T_5 * V_17 ;
T_2 * V_18 ;
T_3 * V_19 ;
T_4 * V_20 ;
int V_21 = - V_22 ;
for ( V_8 = V_13 ; V_8 < V_16 ; ) {
V_17 = F_12 ( V_8 ) ;
if ( F_13 ( * V_17 ) ) {
V_18 = F_5 () ;
if ( ! V_18 )
goto V_23;
F_14 ( & V_10 , V_17 , V_18 ) ;
}
V_18 = F_15 ( V_17 , V_8 ) ;
if ( F_17 ( * V_18 ) ) {
V_19 = F_7 () ;
if ( ! V_19 )
goto V_23;
F_20 ( & V_10 , V_18 , V_19 ) ;
}
V_19 = F_21 ( V_18 , V_8 ) ;
if ( F_22 ( * V_19 ) ) {
if ( V_30 ) {
void * V_41 ;
V_41 = F_35 ( V_32 , V_40 ) ;
if ( ! V_41 )
goto V_23;
F_23 ( * V_19 ) = F_19 ( V_41 ) |
V_33 | V_34 ;
V_8 = ( V_8 + V_32 ) & V_31 ;
continue;
}
V_20 = F_8 ( V_8 ) ;
if ( ! V_20 )
goto V_23;
F_24 ( & V_10 , V_19 , V_20 ) ;
} else if ( F_31 ( * V_19 ) ) {
V_8 = ( V_8 + V_32 ) & V_31 ;
continue;
}
V_20 = F_25 ( V_19 , V_8 ) ;
if ( F_36 ( * V_20 ) ) {
void * V_41 ;
V_41 = F_35 ( V_3 , V_40 ) ;
if ( ! V_41 )
goto V_23;
F_26 ( * V_20 ) =
F_19 ( V_41 ) | F_27 ( V_38 ) ;
}
V_8 += V_3 ;
}
V_21 = 0 ;
V_23:
return V_21 ;
}
void F_37 ( unsigned long V_13 , unsigned long V_16 )
{
}
static int F_38 ( struct V_42 * V_43 )
{
struct V_42 * V_44 ;
if ( V_43 -> V_13 + V_43 -> V_14 > V_45 ||
V_43 -> V_13 + V_43 -> V_14 < V_43 -> V_13 )
return - V_46 ;
F_39 (tmp, &mem_segs, list) {
if ( V_43 -> V_13 >= V_44 -> V_13 + V_44 -> V_14 )
continue;
if ( V_43 -> V_13 + V_43 -> V_14 <= V_44 -> V_13 )
continue;
return - V_47 ;
}
F_40 ( & V_43 -> V_48 , & V_49 ) ;
return 0 ;
}
static void F_41 ( struct V_42 * V_43 )
{
F_42 ( & V_43 -> V_48 ) ;
}
static void F_43 ( struct V_42 * V_43 )
{
F_41 ( V_43 ) ;
F_28 ( V_43 -> V_13 , V_43 -> V_14 ) ;
}
int F_44 ( unsigned long V_13 , unsigned long V_14 )
{
struct V_42 * V_43 ;
int V_21 ;
F_45 ( & V_50 ) ;
V_21 = - V_51 ;
F_39 (seg, &mem_segs, list) {
if ( V_43 -> V_13 == V_13 && V_43 -> V_14 == V_14 )
break;
}
if ( V_43 -> V_13 != V_13 || V_43 -> V_14 != V_14 )
goto V_23;
V_21 = 0 ;
F_43 ( V_43 ) ;
F_46 ( V_43 ) ;
V_23:
F_47 ( & V_50 ) ;
return V_21 ;
}
int F_48 ( unsigned long V_13 , unsigned long V_14 )
{
struct V_42 * V_43 ;
int V_21 ;
F_45 ( & V_50 ) ;
V_21 = - V_22 ;
V_43 = F_49 ( sizeof( * V_43 ) , V_2 ) ;
if ( ! V_43 )
goto V_23;
V_43 -> V_13 = V_13 ;
V_43 -> V_14 = V_14 ;
V_21 = F_38 ( V_43 ) ;
if ( V_21 )
goto V_52;
V_21 = F_11 ( V_13 , V_14 , 0 ) ;
if ( V_21 )
goto V_53;
goto V_23;
V_53:
F_43 ( V_43 ) ;
V_52:
F_46 ( V_43 ) ;
V_23:
F_47 ( & V_50 ) ;
return V_21 ;
}
void T_7 F_50 ( void )
{
unsigned long V_54 , V_55 ;
struct V_56 * V_57 ;
T_8 V_13 , V_16 ;
V_54 = F_51 ( ( unsigned long ) & V_58 ) ;
V_55 = ( unsigned long ) & V_59 & V_60 ;
F_52 (memory, reg) {
V_13 = V_57 -> V_61 ;
V_16 = V_57 -> V_61 + V_57 -> V_14 - 1 ;
if ( V_13 >= V_55 || V_16 <= V_54 )
F_11 ( V_13 , V_16 - V_13 , 0 ) ;
else if ( V_13 >= V_54 && V_16 <= V_55 )
F_11 ( V_13 , V_16 - V_13 , 1 ) ;
else if ( V_13 >= V_54 ) {
F_11 ( V_13 , V_55 - V_13 , 1 ) ;
F_11 ( V_55 , V_16 - V_55 , 0 ) ;
} else if ( V_16 < V_55 ) {
F_11 ( V_13 , V_54 - V_13 , 0 ) ;
F_11 ( V_54 , V_16 - V_54 , 1 ) ;
} else {
F_11 ( V_13 , V_54 - V_13 , 0 ) ;
F_11 ( V_54 , V_55 - V_54 , 1 ) ;
F_11 ( V_55 , V_16 - V_55 , 0 ) ;
}
}
}
static int T_7 F_53 ( void )
{
struct V_56 * V_57 ;
struct V_42 * V_43 ;
F_45 ( & V_50 ) ;
F_52 (memory, reg) {
V_43 = F_49 ( sizeof( * V_43 ) , V_2 ) ;
if ( ! V_43 )
F_54 ( L_1 ) ;
V_43 -> V_13 = V_57 -> V_61 ;
V_43 -> V_14 = V_57 -> V_14 ;
F_38 ( V_43 ) ;
}
F_47 ( & V_50 ) ;
return 0 ;
}
