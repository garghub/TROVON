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
V_9 = F_11 ( V_11 * sizeof( T_4 ) ) ;
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
T_4 V_9 ;
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
if ( F_17 ( * V_18 ) ) {
V_19 = F_8 () ;
if ( ! V_19 )
goto V_23;
F_18 ( & V_10 , V_18 , V_19 ) ;
}
V_9 = F_19 ( V_8 , F_20 ( V_15 ? V_24 : 0 ) ) ;
V_19 = F_21 ( V_18 , V_8 ) ;
#if F_22 ( F_6 ) && ! F_22 ( V_25 )
if ( V_26 && F_23 ( * V_19 ) && V_8 &&
! ( V_8 & ~ V_27 ) && ( V_8 + V_28 <= V_16 ) ) {
F_24 ( V_9 ) |= V_29 ;
F_25 ( * V_19 ) = F_24 ( V_9 ) ;
V_8 += V_28 ;
continue;
}
#endif
if ( F_23 ( * V_19 ) ) {
V_20 = F_9 ( V_8 ) ;
if ( ! V_20 )
goto V_23;
F_26 ( & V_10 , V_19 , V_20 ) ;
}
V_20 = F_27 ( V_19 , V_8 ) ;
* V_20 = V_9 ;
V_8 += V_3 ;
}
V_21 = 0 ;
V_23:
F_28 ( V_13 , V_16 ) ;
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
F_24 ( V_9 ) = V_12 ;
while ( V_8 < V_16 ) {
V_17 = F_13 ( V_8 ) ;
if ( F_14 ( * V_17 ) ) {
V_8 += V_30 ;
continue;
}
V_18 = F_16 ( V_17 , V_8 ) ;
if ( F_17 ( * V_18 ) ) {
V_8 += V_31 ;
continue;
}
V_19 = F_21 ( V_18 , V_8 ) ;
if ( F_23 ( * V_19 ) ) {
V_8 += V_28 ;
continue;
}
if ( F_30 ( * V_19 ) ) {
F_31 ( V_19 ) ;
V_8 += V_28 ;
continue;
}
V_20 = F_27 ( V_19 , V_8 ) ;
* V_20 = V_9 ;
V_8 += V_3 ;
}
F_28 ( V_13 , V_16 ) ;
}
int T_6 F_32 ( struct V_32 * V_13 , unsigned long V_33 , int V_34 )
{
unsigned long V_8 , V_35 , V_36 ;
T_5 * V_17 ;
T_2 * V_18 ;
T_3 * V_19 ;
T_4 * V_20 ;
T_4 V_9 ;
int V_21 = - V_22 ;
V_35 = ( unsigned long ) V_13 ;
V_36 = ( unsigned long ) ( V_13 + V_33 ) ;
for ( V_8 = V_35 ; V_8 < V_36 ; V_8 += V_3 ) {
V_17 = F_13 ( V_8 ) ;
if ( F_14 ( * V_17 ) ) {
V_18 = F_5 () ;
if ( ! V_18 )
goto V_23;
F_15 ( & V_10 , V_17 , V_18 ) ;
}
V_18 = F_16 ( V_17 , V_8 ) ;
if ( F_17 ( * V_18 ) ) {
V_19 = F_8 () ;
if ( ! V_19 )
goto V_23;
F_18 ( & V_10 , V_18 , V_19 ) ;
}
V_19 = F_21 ( V_18 , V_8 ) ;
if ( F_23 ( * V_19 ) ) {
V_20 = F_9 ( V_8 ) ;
if ( ! V_20 )
goto V_23;
F_26 ( & V_10 , V_19 , V_20 ) ;
}
V_20 = F_27 ( V_19 , V_8 ) ;
if ( F_33 ( * V_20 ) ) {
unsigned long V_37 ;
V_37 = F_34 ( F_1 ( 0 ) ) ;
if ( ! V_37 )
goto V_23;
V_9 = F_35 ( V_37 >> V_38 , V_39 ) ;
* V_20 = V_9 ;
}
}
memset ( V_13 , 0 , V_33 * sizeof( struct V_32 ) ) ;
V_21 = 0 ;
V_23:
F_28 ( V_35 , V_36 ) ;
return V_21 ;
}
static int F_36 ( struct V_40 * V_41 )
{
struct V_40 * V_42 ;
if ( V_41 -> V_13 + V_41 -> V_14 > V_43 ||
V_41 -> V_13 + V_41 -> V_14 < V_41 -> V_13 )
return - V_44 ;
F_37 (tmp, &mem_segs, list) {
if ( V_41 -> V_13 >= V_42 -> V_13 + V_42 -> V_14 )
continue;
if ( V_41 -> V_13 + V_41 -> V_14 <= V_42 -> V_13 )
continue;
return - V_45 ;
}
F_38 ( & V_41 -> V_46 , & V_47 ) ;
return 0 ;
}
static void F_39 ( struct V_40 * V_41 )
{
F_40 ( & V_41 -> V_46 ) ;
}
static void F_41 ( struct V_40 * V_41 )
{
F_39 ( V_41 ) ;
F_29 ( V_41 -> V_13 , V_41 -> V_14 ) ;
}
int F_42 ( unsigned long V_13 , unsigned long V_14 )
{
struct V_40 * V_41 ;
int V_21 ;
F_43 ( & V_48 ) ;
V_21 = - V_49 ;
F_37 (seg, &mem_segs, list) {
if ( V_41 -> V_13 == V_13 && V_41 -> V_14 == V_14 )
break;
}
if ( V_41 -> V_13 != V_13 || V_41 -> V_14 != V_14 )
goto V_23;
V_21 = 0 ;
F_41 ( V_41 ) ;
F_44 ( V_41 ) ;
V_23:
F_45 ( & V_48 ) ;
return V_21 ;
}
int F_46 ( unsigned long V_13 , unsigned long V_14 )
{
struct V_40 * V_41 ;
int V_21 ;
F_43 ( & V_48 ) ;
V_21 = - V_22 ;
V_41 = F_47 ( sizeof( * V_41 ) , V_2 ) ;
if ( ! V_41 )
goto V_23;
V_41 -> V_13 = V_13 ;
V_41 -> V_14 = V_14 ;
V_21 = F_36 ( V_41 ) ;
if ( V_21 )
goto V_50;
V_21 = F_12 ( V_13 , V_14 , 0 ) ;
if ( V_21 )
goto V_51;
goto V_23;
V_51:
F_41 ( V_41 ) ;
V_50:
F_44 ( V_41 ) ;
V_23:
F_45 ( & V_48 ) ;
return V_21 ;
}
void T_7 F_48 ( void )
{
unsigned long V_52 , V_53 ;
unsigned long V_13 , V_16 ;
int V_54 ;
V_52 = F_49 ( ( unsigned long ) & V_55 ) ;
V_53 = ( unsigned long ) & V_56 & V_57 ;
for ( V_54 = 0 ; V_54 < V_58 && V_59 [ V_54 ] . V_14 > 0 ; V_54 ++ ) {
if ( V_59 [ V_54 ] . type == V_60 ||
V_59 [ V_54 ] . type == V_61 )
continue;
V_13 = V_59 [ V_54 ] . V_62 ;
V_16 = V_59 [ V_54 ] . V_62 + V_59 [ V_54 ] . V_14 ;
if ( V_13 >= V_53 || V_16 <= V_52 )
F_12 ( V_13 , V_16 - V_13 , 0 ) ;
else if ( V_13 >= V_52 && V_16 <= V_53 )
F_12 ( V_13 , V_16 - V_13 , 1 ) ;
else if ( V_13 >= V_52 ) {
F_12 ( V_13 , V_53 - V_13 , 1 ) ;
F_12 ( V_53 , V_16 - V_53 , 0 ) ;
} else if ( V_16 < V_53 ) {
F_12 ( V_13 , V_52 - V_13 , 0 ) ;
F_12 ( V_52 , V_16 - V_52 , 1 ) ;
} else {
F_12 ( V_13 , V_52 - V_13 , 0 ) ;
F_12 ( V_52 , V_53 - V_52 , 1 ) ;
F_12 ( V_53 , V_16 - V_53 , 0 ) ;
}
}
}
static int T_7 F_50 ( void )
{
struct V_40 * V_41 ;
int V_54 ;
F_43 ( & V_48 ) ;
for ( V_54 = 0 ; V_54 < V_58 ; V_54 ++ ) {
if ( ! V_59 [ V_54 ] . V_14 )
continue;
if ( V_59 [ V_54 ] . type == V_60 ||
V_59 [ V_54 ] . type == V_61 )
continue;
V_41 = F_47 ( sizeof( * V_41 ) , V_2 ) ;
if ( ! V_41 )
F_51 ( L_1 ) ;
V_41 -> V_13 = V_59 [ V_54 ] . V_62 ;
V_41 -> V_14 = V_59 [ V_54 ] . V_14 ;
F_36 ( V_41 ) ;
}
F_45 ( & V_48 ) ;
return 0 ;
}
