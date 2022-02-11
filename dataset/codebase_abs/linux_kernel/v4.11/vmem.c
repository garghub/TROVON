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
unsigned long V_17 , V_18 , V_19 ;
unsigned long V_20 = V_13 + V_2 ;
unsigned long V_21 = V_13 ;
T_5 * V_22 ;
T_2 * V_23 ;
T_3 * V_24 ;
T_4 * V_25 ;
int V_26 = - V_27 ;
V_14 = F_11 ( V_28 ) ;
V_15 = F_11 ( V_29 ) ;
V_16 = F_11 ( V_30 ) ;
if ( ! V_31 ) {
V_14 &= ~ V_32 ;
V_15 &= ~ V_33 ;
V_16 &= ~ V_34 ;
}
V_17 = V_18 = V_19 = 0 ;
while ( V_21 < V_20 ) {
V_22 = F_12 ( V_21 ) ;
if ( F_13 ( * V_22 ) ) {
V_23 = F_5 () ;
if ( ! V_23 )
goto V_35;
F_14 ( & V_11 , V_22 , V_23 ) ;
}
V_23 = F_15 ( V_22 , V_21 ) ;
if ( V_36 && F_16 ( * V_23 ) && V_21 &&
! ( V_21 & ~ V_37 ) && ( V_21 + V_38 <= V_20 ) &&
! F_17 () ) {
F_18 ( * V_23 ) = V_21 | V_16 ;
V_21 += V_38 ;
V_19 ++ ;
continue;
}
if ( F_16 ( * V_23 ) ) {
V_24 = F_7 () ;
if ( ! V_24 )
goto V_35;
F_19 ( & V_11 , V_23 , V_24 ) ;
}
V_24 = F_20 ( V_23 , V_21 ) ;
if ( V_39 && F_21 ( * V_24 ) && V_21 &&
! ( V_21 & ~ V_40 ) && ( V_21 + V_41 <= V_20 ) &&
! F_17 () ) {
F_22 ( * V_24 ) = V_21 | V_15 ;
V_21 += V_41 ;
V_18 ++ ;
continue;
}
if ( F_21 ( * V_24 ) ) {
V_25 = F_8 () ;
if ( ! V_25 )
goto V_35;
F_23 ( & V_11 , V_24 , V_25 ) ;
}
V_25 = F_24 ( V_24 , V_21 ) ;
F_25 ( * V_25 ) = V_21 | V_14 ;
V_21 += V_3 ;
V_17 ++ ;
}
V_26 = 0 ;
V_35:
F_26 ( V_42 , V_17 ) ;
F_26 ( V_43 , V_18 ) ;
F_26 ( V_44 , V_19 ) ;
return V_26 ;
}
static void F_27 ( unsigned long V_13 , unsigned long V_2 )
{
unsigned long V_17 , V_18 , V_19 ;
unsigned long V_20 = V_13 + V_2 ;
unsigned long V_21 = V_13 ;
T_5 * V_22 ;
T_2 * V_23 ;
T_3 * V_24 ;
T_4 * V_25 ;
V_17 = V_18 = V_19 = 0 ;
while ( V_21 < V_20 ) {
V_22 = F_12 ( V_21 ) ;
if ( F_13 ( * V_22 ) ) {
V_21 += V_45 ;
continue;
}
V_23 = F_15 ( V_22 , V_21 ) ;
if ( F_16 ( * V_23 ) ) {
V_21 += V_38 ;
continue;
}
if ( F_28 ( * V_23 ) ) {
F_29 ( V_23 ) ;
V_21 += V_38 ;
V_19 ++ ;
continue;
}
V_24 = F_20 ( V_23 , V_21 ) ;
if ( F_21 ( * V_24 ) ) {
V_21 += V_41 ;
continue;
}
if ( F_30 ( * V_24 ) ) {
F_31 ( V_24 ) ;
V_21 += V_41 ;
V_18 ++ ;
continue;
}
V_25 = F_24 ( V_24 , V_21 ) ;
F_32 ( & V_11 , V_21 , V_25 ) ;
V_21 += V_3 ;
V_17 ++ ;
}
F_33 ( V_13 , V_20 ) ;
F_26 ( V_42 , - V_17 ) ;
F_26 ( V_43 , - V_18 ) ;
F_26 ( V_44 , - V_19 ) ;
}
int T_6 F_34 ( unsigned long V_13 , unsigned long V_20 , int V_46 )
{
unsigned long V_14 , V_15 ;
unsigned long V_21 = V_13 ;
T_5 * V_22 ;
T_2 * V_23 ;
T_3 * V_24 ;
T_4 * V_25 ;
int V_26 = - V_27 ;
V_14 = F_11 ( V_28 ) ;
V_15 = F_11 ( V_29 ) ;
if ( ! V_31 ) {
V_14 &= ~ V_32 ;
V_15 &= ~ V_33 ;
}
for ( V_21 = V_13 ; V_21 < V_20 ; ) {
V_22 = F_12 ( V_21 ) ;
if ( F_13 ( * V_22 ) ) {
V_23 = F_5 () ;
if ( ! V_23 )
goto V_35;
F_14 ( & V_11 , V_22 , V_23 ) ;
}
V_23 = F_15 ( V_22 , V_21 ) ;
if ( F_16 ( * V_23 ) ) {
V_24 = F_7 () ;
if ( ! V_24 )
goto V_35;
F_19 ( & V_11 , V_23 , V_24 ) ;
}
V_24 = F_20 ( V_23 , V_21 ) ;
if ( F_21 ( * V_24 ) ) {
if ( V_39 ) {
void * V_47 ;
V_47 = F_35 ( V_41 , V_46 ) ;
if ( ! V_47 )
goto V_35;
F_22 ( * V_24 ) = F_36 ( V_47 ) | V_15 ;
V_21 = ( V_21 + V_41 ) & V_40 ;
continue;
}
V_25 = F_8 () ;
if ( ! V_25 )
goto V_35;
F_23 ( & V_11 , V_24 , V_25 ) ;
} else if ( F_30 ( * V_24 ) ) {
V_21 = ( V_21 + V_41 ) & V_40 ;
continue;
}
V_25 = F_24 ( V_24 , V_21 ) ;
if ( F_37 ( * V_25 ) ) {
void * V_47 ;
V_47 = F_35 ( V_3 , V_46 ) ;
if ( ! V_47 )
goto V_35;
F_25 ( * V_25 ) = F_36 ( V_47 ) | V_14 ;
}
V_21 += V_3 ;
}
V_26 = 0 ;
V_35:
return V_26 ;
}
void F_38 ( unsigned long V_13 , unsigned long V_20 )
{
}
static int F_39 ( struct V_48 * V_49 )
{
struct V_48 * V_50 ;
if ( V_49 -> V_13 + V_49 -> V_2 > V_51 ||
V_49 -> V_13 + V_49 -> V_2 < V_49 -> V_13 )
return - V_52 ;
F_40 (tmp, &mem_segs, list) {
if ( V_49 -> V_13 >= V_50 -> V_13 + V_50 -> V_2 )
continue;
if ( V_49 -> V_13 + V_49 -> V_2 <= V_50 -> V_13 )
continue;
return - V_53 ;
}
F_41 ( & V_49 -> V_54 , & V_55 ) ;
return 0 ;
}
static void F_42 ( struct V_48 * V_49 )
{
F_43 ( & V_49 -> V_54 ) ;
}
static void F_44 ( struct V_48 * V_49 )
{
F_42 ( V_49 ) ;
F_27 ( V_49 -> V_13 , V_49 -> V_2 ) ;
}
int F_45 ( unsigned long V_13 , unsigned long V_2 )
{
struct V_48 * V_49 ;
int V_26 ;
F_46 ( & V_56 ) ;
V_26 = - V_57 ;
F_40 (seg, &mem_segs, list) {
if ( V_49 -> V_13 == V_13 && V_49 -> V_2 == V_2 )
break;
}
if ( V_49 -> V_13 != V_13 || V_49 -> V_2 != V_2 )
goto V_35;
V_26 = 0 ;
F_44 ( V_49 ) ;
F_47 ( V_49 ) ;
V_35:
F_48 ( & V_56 ) ;
return V_26 ;
}
int F_49 ( unsigned long V_13 , unsigned long V_2 )
{
struct V_48 * V_49 ;
int V_26 ;
F_46 ( & V_56 ) ;
V_26 = - V_27 ;
V_49 = F_50 ( sizeof( * V_49 ) , V_4 ) ;
if ( ! V_49 )
goto V_35;
V_49 -> V_13 = V_13 ;
V_49 -> V_2 = V_2 ;
V_26 = F_39 ( V_49 ) ;
if ( V_26 )
goto V_58;
V_26 = F_10 ( V_13 , V_2 ) ;
if ( V_26 )
goto V_59;
goto V_35;
V_59:
F_44 ( V_49 ) ;
V_58:
F_47 ( V_49 ) ;
V_35:
F_48 ( & V_56 ) ;
return V_26 ;
}
void T_7 F_51 ( void )
{
struct V_60 * V_61 ;
F_52 (memory, reg)
F_10 ( V_61 -> V_62 , V_61 -> V_2 ) ;
F_53 ( ( unsigned long ) V_63 ,
( V_64 - V_63 ) >> V_65 ,
V_66 | V_67 ) ;
F_53 ( ( unsigned long ) V_64 ,
( V_68 - V_64 ) >> V_65 ,
V_66 ) ;
F_53 ( ( unsigned long ) V_69 ,
( V_70 - V_69 ) >> V_65 ,
V_66 | V_67 ) ;
F_54 ( L_1 ,
( V_68 - V_63 ) >> 10 ) ;
}
static int T_7 F_55 ( void )
{
struct V_60 * V_61 ;
struct V_48 * V_49 ;
F_46 ( & V_56 ) ;
F_52 (memory, reg) {
V_49 = F_50 ( sizeof( * V_49 ) , V_4 ) ;
if ( ! V_49 )
F_56 ( L_2 ) ;
V_49 -> V_13 = V_61 -> V_62 ;
V_49 -> V_2 = V_61 -> V_2 ;
F_39 ( V_49 ) ;
}
F_48 ( & V_56 ) ;
return 0 ;
}
