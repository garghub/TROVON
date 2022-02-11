static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = - 1ULL ;
V_2 -> V_4 = V_2 -> V_5 = V_2 -> V_6 = 0 ;
V_2 -> V_7 = V_2 -> V_8 = 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
const T_1 V_8 = F_3 ( V_2 -> V_8 ) ;
const T_1 V_5 = F_3 ( V_2 -> V_5 ) ;
if ( ! V_8 )
return;
if ( ! V_5 )
V_2 -> V_6 = F_4 ( V_2 -> V_7 , V_8 ) ;
else {
V_2 -> V_6 = F_4 ( ( V_2 -> V_6 * V_5 ) +
V_2 -> V_7 ,
V_8 + V_5 ) ;
}
V_2 -> V_5 += V_8 ;
V_2 -> V_8 = V_2 -> V_7 = 0 ;
}
static void F_5 ( struct V_1 * V_9 , struct V_1 * V_10 )
{
F_2 ( V_10 ) ;
if ( ! V_10 -> V_5 )
return;
V_9 -> V_3 = V_3 ( V_9 -> V_3 , V_10 -> V_3 ) ;
V_9 -> V_4 = V_4 ( V_9 -> V_4 , V_10 -> V_4 ) ;
if ( ! V_9 -> V_5 )
V_9 -> V_6 = V_10 -> V_6 ;
else {
V_9 -> V_6 = F_4 ( ( V_10 -> V_6 * V_10 -> V_5 ) +
( V_9 -> V_6 * V_9 -> V_5 ) ,
V_9 -> V_5 + V_10 -> V_5 ) ;
}
V_9 -> V_5 += V_10 -> V_5 ;
}
static void F_6 ( struct V_1 * V_2 , T_2 V_11 )
{
V_2 -> V_3 = V_3 ( V_2 -> V_3 , V_11 ) ;
V_2 -> V_4 = V_4 ( V_2 -> V_4 , V_11 ) ;
if ( V_2 -> V_7 + V_11 < V_2 -> V_7 ||
V_2 -> V_8 + 1 == V_12 )
F_2 ( V_2 ) ;
V_2 -> V_7 += V_11 ;
V_2 -> V_8 ++ ;
}
void F_7 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
int V_19 ;
T_3 V_20 , V_11 ;
V_20 = F_8 ( F_9 ( F_10 () ) ) ;
if ( V_20 < F_11 ( & V_14 -> V_21 ) )
return;
V_11 = V_20 - F_11 ( & V_14 -> V_21 ) ;
F_12 ( V_14 , V_11 ) ;
F_13 () ;
F_14 (cb, &q->stats->callbacks, list) {
if ( ! F_15 ( V_18 ) )
continue;
V_19 = V_18 -> V_22 ( V_14 ) ;
if ( V_19 < 0 )
continue;
V_2 = & F_16 ( V_18 -> V_23 ) [ V_19 ] ;
F_6 ( V_2 , V_11 ) ;
F_17 ( V_18 -> V_23 ) ;
}
F_18 () ;
}
static void F_19 ( unsigned long V_24 )
{
struct V_17 * V_18 = ( void * ) V_24 ;
unsigned int V_19 ;
int V_25 ;
for ( V_19 = 0 ; V_19 < V_18 -> V_26 ; V_19 ++ )
F_1 ( & V_18 -> V_2 [ V_19 ] ) ;
F_20 (cpu) {
struct V_1 * V_23 ;
V_23 = F_21 ( V_18 -> V_23 , V_25 ) ;
for ( V_19 = 0 ; V_19 < V_18 -> V_26 ; V_19 ++ ) {
F_5 ( & V_18 -> V_2 [ V_19 ] , & V_23 [ V_19 ] ) ;
F_1 ( & V_23 [ V_19 ] ) ;
}
}
V_18 -> V_27 ( V_18 ) ;
}
struct V_17 *
F_22 ( void (* V_27)( struct V_17 * ) ,
int (* V_22)( const struct V_13 * ) ,
unsigned int V_26 , void * V_24 )
{
struct V_17 * V_18 ;
V_18 = F_23 ( sizeof( * V_18 ) , V_28 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_2 = F_24 ( V_26 , sizeof( struct V_1 ) ,
V_28 ) ;
if ( ! V_18 -> V_2 ) {
F_25 ( V_18 ) ;
return NULL ;
}
V_18 -> V_23 = F_26 ( V_26 * sizeof( struct V_1 ) ,
F_27 ( struct V_1 ) ) ;
if ( ! V_18 -> V_23 ) {
F_25 ( V_18 -> V_2 ) ;
F_25 ( V_18 ) ;
return NULL ;
}
V_18 -> V_27 = V_27 ;
V_18 -> V_22 = V_22 ;
V_18 -> V_24 = V_24 ;
V_18 -> V_26 = V_26 ;
F_28 ( & V_18 -> V_29 , F_19 , ( unsigned long ) V_18 ) ;
return V_18 ;
}
void F_29 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
unsigned int V_19 ;
int V_25 ;
F_30 (cpu) {
struct V_1 * V_23 ;
V_23 = F_21 ( V_18 -> V_23 , V_25 ) ;
for ( V_19 = 0 ; V_19 < V_18 -> V_26 ; V_19 ++ )
F_1 ( & V_23 [ V_19 ] ) ;
}
F_31 ( & V_16 -> V_30 -> V_31 ) ;
F_32 ( & V_18 -> V_32 , & V_16 -> V_30 -> V_33 ) ;
F_33 ( V_34 , & V_16 -> V_35 ) ;
F_34 ( & V_16 -> V_30 -> V_31 ) ;
}
void F_35 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
F_31 ( & V_16 -> V_30 -> V_31 ) ;
F_36 ( & V_18 -> V_32 ) ;
if ( F_37 ( & V_16 -> V_30 -> V_33 ) && ! V_16 -> V_30 -> V_36 )
F_38 ( V_34 , & V_16 -> V_35 ) ;
F_34 ( & V_16 -> V_30 -> V_31 ) ;
F_39 ( & V_18 -> V_29 ) ;
}
static void F_40 ( struct V_37 * V_38 )
{
struct V_17 * V_18 ;
V_18 = F_41 ( V_38 , struct V_17 , V_39 ) ;
F_42 ( V_18 -> V_23 ) ;
F_25 ( V_18 -> V_2 ) ;
F_25 ( V_18 ) ;
}
void F_43 ( struct V_17 * V_18 )
{
if ( V_18 )
F_44 ( & V_18 -> V_39 , F_40 ) ;
}
void F_45 ( struct V_15 * V_16 )
{
F_31 ( & V_16 -> V_30 -> V_31 ) ;
V_16 -> V_30 -> V_36 = true ;
F_33 ( V_34 , & V_16 -> V_35 ) ;
F_34 ( & V_16 -> V_30 -> V_31 ) ;
}
struct V_40 * F_46 ( void )
{
struct V_40 * V_30 ;
V_30 = F_23 ( sizeof( * V_30 ) , V_28 ) ;
if ( ! V_30 )
return NULL ;
F_47 ( & V_30 -> V_33 ) ;
F_48 ( & V_30 -> V_31 ) ;
V_30 -> V_36 = false ;
return V_30 ;
}
void F_49 ( struct V_40 * V_30 )
{
if ( ! V_30 )
return;
F_50 ( ! F_37 ( & V_30 -> V_33 ) ) ;
F_25 ( V_30 ) ;
}
