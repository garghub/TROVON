T_1 F_1 ( const struct V_1 * V_1 )
{
return F_2 ( V_1 -> V_2 ) ;
}
unsigned long F_3 ( const struct V_1 * V_1 )
{
return V_1 -> V_3 << V_4 ;
}
const char * F_4 ( const struct V_1 * V_1 )
{
return V_1 -> V_5 ? V_1 -> V_5 : L_1 ;
}
static unsigned long F_5 ( const struct V_1 * V_1 ,
unsigned int V_6 )
{
if ( V_6 <= V_1 -> V_7 )
return 0 ;
return ( 1UL << ( V_6 - V_1 -> V_7 ) ) - 1 ;
}
static unsigned long F_6 ( const struct V_1 * V_1 ,
unsigned int V_6 )
{
return ( V_1 -> V_2 & ( ( 1UL << V_6 ) - 1 ) )
>> V_1 -> V_7 ;
}
static unsigned long F_7 ( const struct V_1 * V_1 ,
unsigned long V_8 )
{
return F_8 ( V_8 , 1UL << V_1 -> V_7 ) >> V_1 -> V_7 ;
}
static void F_9 ( struct V_1 * V_1 , unsigned long V_9 ,
unsigned int V_3 )
{
unsigned long V_10 , V_11 ;
V_10 = ( V_9 - V_1 -> V_2 ) >> V_1 -> V_7 ;
V_11 = F_7 ( V_1 , V_3 ) ;
F_10 ( & V_1 -> V_12 ) ;
F_11 ( V_1 -> V_13 , V_10 , V_11 ) ;
F_12 ( & V_1 -> V_12 ) ;
}
static int T_2 F_13 ( struct V_1 * V_1 )
{
int V_14 = F_14 ( F_15 ( V_1 ) ) * sizeof( long ) ;
unsigned long V_2 = V_1 -> V_2 , V_9 = V_2 ;
unsigned V_15 = V_1 -> V_3 >> V_16 ;
struct V_17 * V_17 ;
V_1 -> V_13 = F_16 ( V_14 , V_18 ) ;
if ( ! V_1 -> V_13 )
return - V_19 ;
F_17 ( ! F_18 ( V_9 ) ) ;
V_17 = F_19 ( F_20 ( V_9 ) ) ;
do {
unsigned V_20 ;
V_2 = V_9 ;
for ( V_20 = V_21 ; V_20 ; -- V_20 , V_9 ++ ) {
F_17 ( ! F_18 ( V_9 ) ) ;
if ( F_19 ( F_20 ( V_9 ) ) != V_17 )
goto V_22;
}
F_21 ( F_20 ( V_2 ) ) ;
} while ( -- V_15 );
F_22 ( & V_1 -> V_12 ) ;
#ifdef F_23
F_24 ( & V_1 -> V_23 ) ;
F_25 ( & V_1 -> V_24 ) ;
#endif
return 0 ;
V_22:
F_26 ( L_2 , V_1 -> V_5 ) ;
F_27 ( V_1 -> V_13 ) ;
V_1 -> V_3 = 0 ;
return - V_25 ;
}
static int T_2 F_28 ( void )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ ) {
int V_27 = F_13 ( & V_28 [ V_15 ] ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
int T_2 F_29 ( T_1 V_29 , T_1 V_30 ,
unsigned int V_7 ,
const char * V_5 ,
struct V_1 * * V_31 )
{
struct V_1 * V_1 ;
T_1 V_32 ;
if ( V_26 == F_30 ( V_28 ) ) {
F_26 ( L_3 ) ;
return - V_33 ;
}
if ( ! V_30 || ! F_31 ( V_29 , V_30 ) )
return - V_25 ;
V_32 = V_34 <<
F_32 (unsigned long, MAX_ORDER - 1 , pageblock_order) ;
if ( ! F_33 ( V_32 >> V_4 , 1 << V_7 ) )
return - V_25 ;
if ( F_8 ( V_29 , V_32 ) != V_29 || F_8 ( V_30 , V_32 ) != V_30 )
return - V_25 ;
V_1 = & V_28 [ V_26 ] ;
if ( V_5 ) {
V_1 -> V_5 = V_5 ;
} else {
V_1 -> V_5 = F_34 ( V_18 , L_4 , V_26 ) ;
if ( ! V_1 -> V_5 )
return - V_19 ;
}
V_1 -> V_2 = F_35 ( V_29 ) ;
V_1 -> V_3 = V_30 >> V_4 ;
V_1 -> V_7 = V_7 ;
* V_31 = V_1 ;
V_26 ++ ;
V_35 += ( V_30 / V_34 ) ;
return 0 ;
}
int T_2 F_36 ( T_1 V_29 ,
T_1 V_30 , T_1 V_36 ,
T_1 V_32 , unsigned int V_7 ,
bool V_37 , const char * V_5 , struct V_1 * * V_31 )
{
T_1 V_38 = F_37 () ;
T_1 V_39 ;
int V_27 = 0 ;
V_39 = F_38 ( V_40 - 1 ) + 1 ;
F_39 ( L_5 ,
V_41 , & V_30 , & V_29 , & V_36 , & V_32 ) ;
if ( V_26 == F_30 ( V_28 ) ) {
F_26 ( L_3 ) ;
return - V_33 ;
}
if ( ! V_30 )
return - V_25 ;
if ( V_32 && ! F_40 ( V_32 ) )
return - V_25 ;
V_32 = F_41 ( V_32 , ( T_1 ) V_34 <<
F_32 (unsigned long, MAX_ORDER - 1 , pageblock_order) ) ;
V_29 = F_8 ( V_29 , V_32 ) ;
V_30 = F_8 ( V_30 , V_32 ) ;
V_36 &= ~ ( V_32 - 1 ) ;
if ( ! V_29 )
V_37 = false ;
if ( ! F_33 ( V_30 >> V_4 , 1 << V_7 ) )
return - V_25 ;
if ( V_37 && V_29 < V_39 && V_29 + V_30 > V_39 ) {
V_27 = - V_25 ;
F_26 ( L_6 ,
& V_29 , & V_39 ) ;
goto V_42;
}
if ( V_36 == 0 || V_36 > V_38 )
V_36 = V_38 ;
if ( V_37 ) {
if ( F_31 ( V_29 , V_30 ) ||
F_42 ( V_29 , V_30 ) < 0 ) {
V_27 = - V_43 ;
goto V_42;
}
} else {
T_1 V_44 = 0 ;
if ( V_29 < V_39 && V_36 > V_39 ) {
V_44 = F_43 ( V_30 , V_32 ,
V_39 , V_36 ,
V_45 ) ;
V_36 = V_39 ;
}
if ( ! V_44 ) {
V_44 = F_43 ( V_30 , V_32 , V_29 ,
V_36 ,
V_45 ) ;
if ( ! V_44 ) {
V_27 = - V_19 ;
goto V_42;
}
}
F_44 ( V_44 ) ;
V_29 = V_44 ;
}
V_27 = F_29 ( V_29 , V_30 , V_7 , V_5 , V_31 ) ;
if ( V_27 )
goto V_42;
F_45 ( L_7 , ( unsigned long ) V_30 / V_46 ,
& V_29 ) ;
return 0 ;
V_42:
F_26 ( L_8 , ( unsigned long ) V_30 / V_46 ) ;
return V_27 ;
}
static void F_46 ( struct V_1 * V_1 )
{
unsigned long V_47 , V_48 ;
unsigned long V_49 = 0 ;
unsigned int V_50 , V_51 = 0 ;
F_10 ( & V_1 -> V_12 ) ;
F_45 ( L_9 ) ;
for (; ; ) {
V_47 = F_47 ( V_1 -> V_13 , V_1 -> V_3 , V_49 ) ;
if ( V_47 >= V_1 -> V_3 )
break;
V_48 = F_48 ( V_1 -> V_13 , V_1 -> V_3 , V_47 ) ;
V_50 = V_48 - V_47 ;
F_49 ( L_10 , V_51 ? L_11 : L_12 , V_50 , V_47 ) ;
V_51 += V_50 ;
V_49 = V_47 + V_50 ;
}
F_49 ( L_13 , V_51 , V_1 -> V_3 ) ;
F_12 ( & V_1 -> V_12 ) ;
}
static inline void F_46 ( struct V_1 * V_1 ) { }
struct V_52 * F_50 ( struct V_1 * V_1 , T_3 V_3 , unsigned int V_53 ,
T_4 V_54 )
{
unsigned long V_55 , V_56 ;
unsigned long V_9 = - 1 ;
unsigned long V_49 = 0 ;
unsigned long V_57 , V_10 , V_11 ;
struct V_52 * V_52 = NULL ;
int V_27 = - V_19 ;
if ( ! V_1 || ! V_1 -> V_3 )
return NULL ;
F_39 ( L_14 , V_41 , ( void * ) V_1 ,
V_3 , V_53 ) ;
if ( ! V_3 )
return NULL ;
V_55 = F_5 ( V_1 , V_53 ) ;
V_56 = F_6 ( V_1 , V_53 ) ;
V_57 = F_15 ( V_1 ) ;
V_11 = F_7 ( V_1 , V_3 ) ;
if ( V_11 > V_57 )
return NULL ;
for (; ; ) {
F_10 ( & V_1 -> V_12 ) ;
V_10 = F_51 ( V_1 -> V_13 ,
V_57 , V_49 , V_11 , V_55 ,
V_56 ) ;
if ( V_10 >= V_57 ) {
F_12 ( & V_1 -> V_12 ) ;
break;
}
F_52 ( V_1 -> V_13 , V_10 , V_11 ) ;
F_12 ( & V_1 -> V_12 ) ;
V_9 = V_1 -> V_2 + ( V_10 << V_1 -> V_7 ) ;
F_10 ( & V_58 ) ;
V_27 = F_53 ( V_9 , V_9 + V_3 , V_59 ,
V_54 ) ;
F_12 ( & V_58 ) ;
if ( V_27 == 0 ) {
V_52 = F_20 ( V_9 ) ;
break;
}
F_9 ( V_1 , V_9 , V_3 ) ;
if ( V_27 != - V_43 )
break;
F_39 ( L_15 ,
V_41 , F_20 ( V_9 ) ) ;
V_49 = V_10 + V_55 + 1 ;
}
F_54 ( V_9 , V_52 , V_3 , V_53 ) ;
if ( V_27 ) {
F_45 ( L_16 ,
V_41 , V_3 , V_27 ) ;
F_46 ( V_1 ) ;
}
F_39 ( L_17 , V_41 , V_52 ) ;
return V_52 ;
}
bool F_55 ( struct V_1 * V_1 , const struct V_52 * V_8 , unsigned int V_3 )
{
unsigned long V_9 ;
if ( ! V_1 || ! V_8 )
return false ;
F_39 ( L_18 , V_41 , ( void * ) V_8 ) ;
V_9 = F_56 ( V_8 ) ;
if ( V_9 < V_1 -> V_2 || V_9 >= V_1 -> V_2 + V_1 -> V_3 )
return false ;
F_57 ( V_9 + V_3 > V_1 -> V_2 + V_1 -> V_3 ) ;
F_58 ( V_9 , V_3 ) ;
F_9 ( V_1 , V_9 , V_3 ) ;
F_59 ( V_9 , V_8 , V_3 ) ;
return true ;
}
int F_60 ( int (* F_61)( struct V_1 * V_1 , void * V_60 ) , void * V_60 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_26 ; V_15 ++ ) {
int V_27 = F_61 ( & V_28 [ V_15 ] , V_60 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
