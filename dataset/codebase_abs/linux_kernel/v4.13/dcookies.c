static inline int F_1 ( void )
{
return ! ( F_2 ( & V_1 ) ) ;
}
static inline unsigned long F_3 ( struct V_2 * V_3 )
{
return ( unsigned long ) V_3 -> V_4 . V_5 ;
}
static T_1 F_4 ( unsigned long V_6 )
{
return ( V_6 >> V_7 ) & ( V_8 - 1 ) ;
}
static struct V_2 * F_5 ( unsigned long V_6 )
{
struct V_2 * V_9 = NULL ;
struct V_2 * V_3 ;
struct V_10 * V_11 ;
struct V_10 * V_12 ;
V_12 = V_13 + F_4 ( V_6 ) ;
F_6 (pos, list) {
V_3 = F_7 ( V_11 , struct V_2 , V_14 ) ;
if ( F_3 ( V_3 ) == V_6 ) {
V_9 = V_3 ;
break;
}
}
return V_9 ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_10 * V_12 = V_13 + F_4 ( F_3 ( V_3 ) ) ;
F_9 ( & V_3 -> V_14 , V_12 ) ;
}
static struct V_2 * F_10 ( const struct V_4 * V_4 )
{
struct V_2 * V_3 = F_11 ( V_15 ,
V_16 ) ;
struct V_5 * V_17 ;
if ( ! V_3 )
return NULL ;
V_17 = V_4 -> V_5 ;
F_12 ( & V_17 -> V_18 ) ;
V_17 -> V_19 |= V_20 ;
F_13 ( & V_17 -> V_18 ) ;
V_3 -> V_4 = * V_4 ;
F_14 ( V_4 ) ;
F_8 ( V_3 ) ;
return V_3 ;
}
int F_15 ( const struct V_4 * V_4 , unsigned long * V_21 )
{
int V_22 = 0 ;
struct V_2 * V_3 ;
F_16 ( & V_23 ) ;
if ( ! F_1 () ) {
V_22 = - V_24 ;
goto V_25;
}
if ( V_4 -> V_5 -> V_19 & V_20 ) {
V_3 = F_5 ( ( unsigned long ) V_4 -> V_5 ) ;
} else {
V_3 = F_10 ( V_4 ) ;
if ( ! V_3 ) {
V_22 = - V_26 ;
goto V_25;
}
}
* V_21 = F_3 ( V_3 ) ;
V_25:
F_17 ( & V_23 ) ;
return V_22 ;
}
static int F_18 ( void )
{
struct V_10 * V_17 ;
unsigned int V_27 , V_28 ;
int V_22 = - V_26 ;
V_15 = F_19 ( L_1 ,
sizeof( struct V_2 ) ,
0 , 0 , NULL ) ;
if ( ! V_15 )
goto V_25;
V_13 = F_20 ( V_29 , V_16 ) ;
if ( ! V_13 )
goto V_30;
V_22 = 0 ;
V_8 = V_29 / sizeof( struct V_10 ) ;
V_28 = 0 ;
do {
V_28 ++ ;
} while ( ( V_8 >> V_28 ) != 0 );
V_28 -- ;
V_8 = 1UL << V_28 ;
V_17 = V_13 ;
V_27 = V_8 ;
do {
F_21 ( V_17 ) ;
V_17 ++ ;
V_27 -- ;
} while ( V_27 );
V_25:
return V_22 ;
V_30:
F_22 ( V_15 ) ;
goto V_25;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_5 * V_17 = V_3 -> V_4 . V_5 ;
F_12 ( & V_17 -> V_18 ) ;
V_17 -> V_19 &= ~ V_20 ;
F_13 ( & V_17 -> V_18 ) ;
F_24 ( & V_3 -> V_4 ) ;
F_25 ( V_15 , V_3 ) ;
}
static void F_26 ( void )
{
struct V_10 * V_12 ;
struct V_10 * V_11 ;
struct V_10 * V_31 ;
struct V_2 * V_3 ;
T_1 V_27 ;
for ( V_27 = 0 ; V_27 < V_8 ; ++ V_27 ) {
V_12 = V_13 + V_27 ;
F_27 (pos, pos2, list) {
V_3 = F_7 ( V_11 , struct V_2 , V_14 ) ;
F_28 ( & V_3 -> V_14 ) ;
F_23 ( V_3 ) ;
}
}
F_29 ( V_13 ) ;
F_22 ( V_15 ) ;
}
struct V_32 * F_30 ( void )
{
struct V_32 * V_33 ;
F_16 ( & V_23 ) ;
V_33 = F_20 ( sizeof( struct V_32 ) , V_16 ) ;
if ( ! V_33 )
goto V_25;
if ( ! F_1 () && F_18 () )
goto V_34;
F_9 ( & V_33 -> V_35 , & V_1 ) ;
V_25:
F_17 ( & V_23 ) ;
return V_33 ;
V_34:
F_29 ( V_33 ) ;
V_33 = NULL ;
goto V_25;
}
void F_31 ( struct V_32 * V_33 )
{
F_16 ( & V_23 ) ;
F_28 ( & V_33 -> V_35 ) ;
F_29 ( V_33 ) ;
if ( ! F_1 () )
F_26 () ;
F_17 ( & V_23 ) ;
}
