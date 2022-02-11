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
V_9 = F_13 ( V_8 , F_14 ( V_15 ? V_23 : 0 ) ) ;
V_17 = F_15 ( V_8 ) ;
if ( F_16 ( * V_17 ) ) {
V_18 = F_5 () ;
if ( ! V_18 )
goto V_24;
F_17 ( & V_10 , V_17 , V_18 ) ;
}
V_18 = F_18 ( V_17 , V_8 ) ;
#if F_19 ( F_6 ) && ! F_19 ( V_25 )
if ( V_26 && F_20 ( * V_18 ) && V_8 &&
! ( V_8 & ~ V_27 ) && ( V_8 + V_28 <= V_16 ) ) {
F_21 ( V_9 ) |= V_29 ;
F_21 ( V_9 ) |= V_30 ;
F_22 ( * V_18 ) = F_21 ( V_9 ) ;
V_8 += V_28 ;
continue;
}
#endif
if ( F_20 ( * V_18 ) ) {
V_19 = F_8 () ;
if ( ! V_19 )
goto V_24;
F_23 ( & V_10 , V_18 , V_19 ) ;
}
V_19 = F_24 ( V_18 , V_8 ) ;
#if F_19 ( F_6 ) && ! F_19 ( V_25 )
if ( V_31 && F_25 ( * V_19 ) && V_8 &&
! ( V_8 & ~ V_32 ) && ( V_8 + V_33 <= V_16 ) ) {
F_21 ( V_9 ) |= V_34 ;
F_26 ( * V_19 ) = F_21 ( V_9 ) ;
V_8 += V_33 ;
continue;
}
#endif
if ( F_25 ( * V_19 ) ) {
V_20 = F_9 ( V_8 ) ;
if ( ! V_20 )
goto V_24;
F_27 ( & V_10 , V_19 , V_20 ) ;
}
V_20 = F_28 ( V_19 , V_8 ) ;
* V_20 = V_9 ;
V_8 += V_3 ;
}
V_21 = 0 ;
V_24:
F_29 ( V_13 , V_16 ) ;
return V_21 ;
}
static void F_30 ( unsigned long V_13 , unsigned long V_14 )
{
unsigned long V_16 = V_13 + V_14 ;
unsigned long V_8 = V_13 ;
T_5 * V_17 ;
T_2 * V_18 ;
T_3 * V_19 ;
T_4 * V_20 ;
T_4 V_9 ;
F_21 ( V_9 ) = V_12 ;
while ( V_8 < V_16 ) {
V_17 = F_15 ( V_8 ) ;
if ( F_16 ( * V_17 ) ) {
V_8 += V_35 ;
continue;
}
V_18 = F_18 ( V_17 , V_8 ) ;
if ( F_20 ( * V_18 ) ) {
V_8 += V_28 ;
continue;
}
if ( F_31 ( * V_18 ) ) {
F_32 ( V_18 ) ;
V_8 += V_28 ;
continue;
}
V_19 = F_24 ( V_18 , V_8 ) ;
if ( F_25 ( * V_19 ) ) {
V_8 += V_33 ;
continue;
}
if ( F_33 ( * V_19 ) ) {
F_34 ( V_19 ) ;
V_8 += V_33 ;
continue;
}
V_20 = F_28 ( V_19 , V_8 ) ;
* V_20 = V_9 ;
V_8 += V_3 ;
}
F_29 ( V_13 , V_16 ) ;
}
int T_6 F_35 ( struct V_36 * V_13 , unsigned long V_37 , int V_38 )
{
unsigned long V_8 , V_39 , V_40 ;
T_5 * V_17 ;
T_2 * V_18 ;
T_3 * V_19 ;
T_4 * V_20 ;
T_4 V_9 ;
int V_21 = - V_22 ;
V_39 = ( unsigned long ) V_13 ;
V_40 = ( unsigned long ) ( V_13 + V_37 ) ;
for ( V_8 = V_39 ; V_8 < V_40 ; ) {
V_17 = F_15 ( V_8 ) ;
if ( F_16 ( * V_17 ) ) {
V_18 = F_5 () ;
if ( ! V_18 )
goto V_24;
F_17 ( & V_10 , V_17 , V_18 ) ;
}
V_18 = F_18 ( V_17 , V_8 ) ;
if ( F_20 ( * V_18 ) ) {
V_19 = F_8 () ;
if ( ! V_19 )
goto V_24;
F_23 ( & V_10 , V_18 , V_19 ) ;
}
V_19 = F_24 ( V_18 , V_8 ) ;
if ( F_25 ( * V_19 ) ) {
#ifdef F_6
if ( V_31 ) {
void * V_41 ;
V_41 = F_36 ( V_33 , V_38 ) ;
if ( ! V_41 )
goto V_24;
V_9 = F_13 ( F_37 ( V_41 ) , V_42 ) ;
F_21 ( V_9 ) |= V_34 ;
F_26 ( * V_19 ) = F_21 ( V_9 ) ;
V_8 = ( V_8 + V_33 ) & V_32 ;
continue;
}
#endif
V_20 = F_9 ( V_8 ) ;
if ( ! V_20 )
goto V_24;
F_27 ( & V_10 , V_19 , V_20 ) ;
} else if ( F_33 ( * V_19 ) ) {
V_8 = ( V_8 + V_33 ) & V_32 ;
continue;
}
V_20 = F_28 ( V_19 , V_8 ) ;
if ( F_38 ( * V_20 ) ) {
unsigned long V_41 ;
V_41 = F_37 ( F_1 ( 0 ) ) ;
if ( ! V_41 )
goto V_24;
V_9 = F_39 ( V_41 >> V_43 , V_44 ) ;
* V_20 = V_9 ;
}
V_8 += V_3 ;
}
memset ( V_13 , 0 , V_37 * sizeof( struct V_36 ) ) ;
V_21 = 0 ;
V_24:
F_29 ( V_39 , V_40 ) ;
return V_21 ;
}
static int F_40 ( struct V_45 * V_46 )
{
struct V_45 * V_47 ;
if ( V_46 -> V_13 + V_46 -> V_14 > V_48 ||
V_46 -> V_13 + V_46 -> V_14 < V_46 -> V_13 )
return - V_49 ;
F_41 (tmp, &mem_segs, list) {
if ( V_46 -> V_13 >= V_47 -> V_13 + V_47 -> V_14 )
continue;
if ( V_46 -> V_13 + V_46 -> V_14 <= V_47 -> V_13 )
continue;
return - V_50 ;
}
F_42 ( & V_46 -> V_51 , & V_52 ) ;
return 0 ;
}
static void F_43 ( struct V_45 * V_46 )
{
F_44 ( & V_46 -> V_51 ) ;
}
static void F_45 ( struct V_45 * V_46 )
{
F_43 ( V_46 ) ;
F_30 ( V_46 -> V_13 , V_46 -> V_14 ) ;
}
int F_46 ( unsigned long V_13 , unsigned long V_14 )
{
struct V_45 * V_46 ;
int V_21 ;
F_47 ( & V_53 ) ;
V_21 = - V_54 ;
F_41 (seg, &mem_segs, list) {
if ( V_46 -> V_13 == V_13 && V_46 -> V_14 == V_14 )
break;
}
if ( V_46 -> V_13 != V_13 || V_46 -> V_14 != V_14 )
goto V_24;
V_21 = 0 ;
F_45 ( V_46 ) ;
F_48 ( V_46 ) ;
V_24:
F_49 ( & V_53 ) ;
return V_21 ;
}
int F_50 ( unsigned long V_13 , unsigned long V_14 )
{
struct V_45 * V_46 ;
int V_21 ;
F_47 ( & V_53 ) ;
V_21 = - V_22 ;
V_46 = F_51 ( sizeof( * V_46 ) , V_2 ) ;
if ( ! V_46 )
goto V_24;
V_46 -> V_13 = V_13 ;
V_46 -> V_14 = V_14 ;
V_21 = F_40 ( V_46 ) ;
if ( V_21 )
goto V_55;
V_21 = F_12 ( V_13 , V_14 , 0 ) ;
if ( V_21 )
goto V_56;
goto V_24;
V_56:
F_45 ( V_46 ) ;
V_55:
F_48 ( V_46 ) ;
V_24:
F_49 ( & V_53 ) ;
return V_21 ;
}
void T_7 F_52 ( void )
{
unsigned long V_57 , V_58 ;
unsigned long V_13 , V_16 ;
int V_59 ;
V_57 = F_53 ( ( unsigned long ) & V_60 ) ;
V_58 = ( unsigned long ) & V_61 & V_62 ;
for ( V_59 = 0 ; V_59 < V_63 && V_64 [ V_59 ] . V_14 > 0 ; V_59 ++ ) {
if ( V_64 [ V_59 ] . type == V_65 ||
V_64 [ V_59 ] . type == V_66 )
continue;
V_13 = V_64 [ V_59 ] . V_67 ;
V_16 = V_64 [ V_59 ] . V_67 + V_64 [ V_59 ] . V_14 ;
if ( V_13 >= V_58 || V_16 <= V_57 )
F_12 ( V_13 , V_16 - V_13 , 0 ) ;
else if ( V_13 >= V_57 && V_16 <= V_58 )
F_12 ( V_13 , V_16 - V_13 , 1 ) ;
else if ( V_13 >= V_57 ) {
F_12 ( V_13 , V_58 - V_13 , 1 ) ;
F_12 ( V_58 , V_16 - V_58 , 0 ) ;
} else if ( V_16 < V_58 ) {
F_12 ( V_13 , V_57 - V_13 , 0 ) ;
F_12 ( V_57 , V_16 - V_57 , 1 ) ;
} else {
F_12 ( V_13 , V_57 - V_13 , 0 ) ;
F_12 ( V_57 , V_58 - V_57 , 1 ) ;
F_12 ( V_58 , V_16 - V_58 , 0 ) ;
}
}
}
static int T_7 F_54 ( void )
{
struct V_45 * V_46 ;
int V_59 ;
F_47 ( & V_53 ) ;
for ( V_59 = 0 ; V_59 < V_63 ; V_59 ++ ) {
if ( ! V_64 [ V_59 ] . V_14 )
continue;
if ( V_64 [ V_59 ] . type == V_65 ||
V_64 [ V_59 ] . type == V_66 )
continue;
V_46 = F_51 ( sizeof( * V_46 ) , V_2 ) ;
if ( ! V_46 )
F_55 ( L_1 ) ;
V_46 -> V_13 = V_64 [ V_59 ] . V_67 ;
V_46 -> V_14 = V_64 [ V_59 ] . V_14 ;
F_40 ( V_46 ) ;
}
F_49 ( & V_53 ) ;
return 0 ;
}
