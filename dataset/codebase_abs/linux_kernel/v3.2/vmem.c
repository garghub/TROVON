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
unsigned long V_8 ;
T_5 * V_16 ;
T_2 * V_17 ;
T_3 * V_18 ;
T_4 * V_19 ;
T_4 V_9 ;
int V_20 = - V_21 ;
for ( V_8 = V_13 ; V_8 < V_13 + V_14 ; V_8 += V_3 ) {
V_16 = F_13 ( V_8 ) ;
if ( F_14 ( * V_16 ) ) {
V_17 = F_5 () ;
if ( ! V_17 )
goto V_22;
F_15 ( & V_10 , V_16 , V_17 ) ;
}
V_17 = F_16 ( V_16 , V_8 ) ;
if ( F_17 ( * V_17 ) ) {
V_18 = F_8 () ;
if ( ! V_18 )
goto V_22;
F_18 ( & V_10 , V_17 , V_18 ) ;
}
V_9 = F_19 ( V_8 , F_20 ( V_15 ? V_23 : 0 ) ) ;
V_18 = F_21 ( V_17 , V_8 ) ;
#ifdef F_22
if ( V_24 && ! ( V_8 & ~ V_25 ) &&
( V_8 + V_26 <= V_13 + V_14 ) &&
( V_8 >= V_26 ) ) {
F_23 ( V_9 ) |= V_27 ;
F_24 ( * V_18 ) = F_23 ( V_9 ) ;
V_8 += V_26 - V_3 ;
continue;
}
#endif
if ( F_25 ( * V_18 ) ) {
V_19 = F_9 ( V_8 ) ;
if ( ! V_19 )
goto V_22;
F_26 ( & V_10 , V_18 , V_19 ) ;
}
V_19 = F_27 ( V_18 , V_8 ) ;
* V_19 = V_9 ;
}
V_20 = 0 ;
V_22:
F_28 ( V_13 , V_13 + V_14 ) ;
return V_20 ;
}
static void F_29 ( unsigned long V_13 , unsigned long V_14 )
{
unsigned long V_8 ;
T_5 * V_16 ;
T_2 * V_17 ;
T_3 * V_18 ;
T_4 * V_19 ;
T_4 V_9 ;
F_23 ( V_9 ) = V_12 ;
for ( V_8 = V_13 ; V_8 < V_13 + V_14 ; V_8 += V_3 ) {
V_16 = F_13 ( V_8 ) ;
V_17 = F_16 ( V_16 , V_8 ) ;
if ( F_17 ( * V_17 ) )
continue;
V_18 = F_21 ( V_17 , V_8 ) ;
if ( F_25 ( * V_18 ) )
continue;
if ( F_30 ( * V_18 ) ) {
F_31 ( V_18 ) ;
V_8 += V_26 - V_3 ;
continue;
}
V_19 = F_27 ( V_18 , V_8 ) ;
* V_19 = V_9 ;
}
F_28 ( V_13 , V_13 + V_14 ) ;
}
int T_6 F_32 ( struct V_28 * V_13 , unsigned long V_29 , int V_30 )
{
unsigned long V_8 , V_31 , V_32 ;
T_5 * V_16 ;
T_2 * V_17 ;
T_3 * V_18 ;
T_4 * V_19 ;
T_4 V_9 ;
int V_20 = - V_21 ;
V_31 = ( unsigned long ) V_13 ;
V_32 = ( unsigned long ) ( V_13 + V_29 ) ;
for ( V_8 = V_31 ; V_8 < V_32 ; V_8 += V_3 ) {
V_16 = F_13 ( V_8 ) ;
if ( F_14 ( * V_16 ) ) {
V_17 = F_5 () ;
if ( ! V_17 )
goto V_22;
F_15 ( & V_10 , V_16 , V_17 ) ;
}
V_17 = F_16 ( V_16 , V_8 ) ;
if ( F_17 ( * V_17 ) ) {
V_18 = F_8 () ;
if ( ! V_18 )
goto V_22;
F_18 ( & V_10 , V_17 , V_18 ) ;
}
V_18 = F_21 ( V_17 , V_8 ) ;
if ( F_25 ( * V_18 ) ) {
V_19 = F_9 ( V_8 ) ;
if ( ! V_19 )
goto V_22;
F_26 ( & V_10 , V_18 , V_19 ) ;
}
V_19 = F_27 ( V_18 , V_8 ) ;
if ( F_33 ( * V_19 ) ) {
unsigned long V_33 ;
V_33 = F_34 ( F_1 ( 0 ) ) ;
if ( ! V_33 )
goto V_22;
V_9 = F_35 ( V_33 >> V_34 , V_35 ) ;
* V_19 = V_9 ;
}
}
memset ( V_13 , 0 , V_29 * sizeof( struct V_28 ) ) ;
V_20 = 0 ;
V_22:
F_28 ( V_31 , V_32 ) ;
return V_20 ;
}
static int F_36 ( struct V_36 * V_37 )
{
struct V_36 * V_38 ;
if ( V_37 -> V_13 + V_37 -> V_14 > V_39 ||
V_37 -> V_13 + V_37 -> V_14 < V_37 -> V_13 )
return - V_40 ;
F_37 (tmp, &mem_segs, list) {
if ( V_37 -> V_13 >= V_38 -> V_13 + V_38 -> V_14 )
continue;
if ( V_37 -> V_13 + V_37 -> V_14 <= V_38 -> V_13 )
continue;
return - V_41 ;
}
F_38 ( & V_37 -> V_42 , & V_43 ) ;
return 0 ;
}
static void F_39 ( struct V_36 * V_37 )
{
F_40 ( & V_37 -> V_42 ) ;
}
static void F_41 ( struct V_36 * V_37 )
{
F_39 ( V_37 ) ;
F_29 ( V_37 -> V_13 , V_37 -> V_14 ) ;
}
int F_42 ( unsigned long V_13 , unsigned long V_14 )
{
struct V_36 * V_37 ;
int V_20 ;
F_43 ( & V_44 ) ;
V_20 = - V_45 ;
F_37 (seg, &mem_segs, list) {
if ( V_37 -> V_13 == V_13 && V_37 -> V_14 == V_14 )
break;
}
if ( V_37 -> V_13 != V_13 || V_37 -> V_14 != V_14 )
goto V_22;
V_20 = 0 ;
F_41 ( V_37 ) ;
F_44 ( V_37 ) ;
V_22:
F_45 ( & V_44 ) ;
return V_20 ;
}
int F_46 ( unsigned long V_13 , unsigned long V_14 )
{
struct V_36 * V_37 ;
int V_20 ;
F_43 ( & V_44 ) ;
V_20 = - V_21 ;
V_37 = F_47 ( sizeof( * V_37 ) , V_2 ) ;
if ( ! V_37 )
goto V_22;
V_37 -> V_13 = V_13 ;
V_37 -> V_14 = V_14 ;
V_20 = F_36 ( V_37 ) ;
if ( V_20 )
goto V_46;
V_20 = F_12 ( V_13 , V_14 , 0 ) ;
if ( V_20 )
goto V_47;
goto V_22;
V_47:
F_41 ( V_37 ) ;
V_46:
F_44 ( V_37 ) ;
V_22:
F_45 ( & V_44 ) ;
return V_20 ;
}
void T_7 F_48 ( void )
{
unsigned long V_48 , V_49 ;
unsigned long V_13 , V_50 ;
int V_51 ;
V_48 = ( ( unsigned long ) & V_52 ) & V_53 ;
V_49 = F_49 ( ( unsigned long ) & V_54 ) ;
for ( V_51 = 0 ; V_51 < V_55 && V_56 [ V_51 ] . V_14 > 0 ; V_51 ++ ) {
if ( V_56 [ V_51 ] . type == V_57 ||
V_56 [ V_51 ] . type == V_58 )
continue;
V_13 = V_56 [ V_51 ] . V_59 ;
V_50 = V_56 [ V_51 ] . V_59 + V_56 [ V_51 ] . V_14 ;
if ( V_13 >= V_49 || V_50 <= V_48 )
F_12 ( V_13 , V_50 - V_13 , 0 ) ;
else if ( V_13 >= V_48 && V_50 <= V_49 )
F_12 ( V_13 , V_50 - V_13 , 1 ) ;
else if ( V_13 >= V_48 ) {
F_12 ( V_13 , V_49 - V_13 , 1 ) ;
F_12 ( V_49 , V_50 - V_49 , 0 ) ;
} else if ( V_50 < V_49 ) {
F_12 ( V_13 , V_48 - V_13 , 0 ) ;
F_12 ( V_48 , V_50 - V_48 , 1 ) ;
} else {
F_12 ( V_13 , V_48 - V_13 , 0 ) ;
F_12 ( V_48 , V_49 - V_48 , 1 ) ;
F_12 ( V_49 , V_50 - V_49 , 0 ) ;
}
}
}
static int T_7 F_50 ( void )
{
struct V_36 * V_37 ;
int V_51 ;
F_43 ( & V_44 ) ;
for ( V_51 = 0 ; V_51 < V_55 ; V_51 ++ ) {
if ( ! V_56 [ V_51 ] . V_14 )
continue;
if ( V_56 [ V_51 ] . type == V_57 ||
V_56 [ V_51 ] . type == V_58 )
continue;
V_37 = F_47 ( sizeof( * V_37 ) , V_2 ) ;
if ( ! V_37 )
F_51 ( L_1 ) ;
V_37 -> V_13 = V_56 [ V_51 ] . V_59 ;
V_37 -> V_14 = V_56 [ V_51 ] . V_14 ;
F_36 ( V_37 ) ;
}
F_45 ( & V_44 ) ;
return 0 ;
}
