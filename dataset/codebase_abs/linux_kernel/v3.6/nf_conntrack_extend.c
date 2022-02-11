void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ ) {
if ( ! F_2 ( V_7 , V_3 ) )
continue;
F_3 () ;
V_5 = F_4 ( V_9 [ V_3 ] ) ;
if ( V_5 && V_5 -> V_10 )
V_5 -> V_10 ( V_2 ) ;
F_5 () ;
}
}
static void *
F_6 ( struct V_6 * * V_7 , enum V_11 V_12 ,
T_1 V_13 , T_2 V_14 )
{
unsigned int V_15 , V_16 ;
struct V_4 * V_5 ;
T_1 V_17 ;
F_3 () ;
V_5 = F_4 ( V_9 [ V_12 ] ) ;
F_7 ( V_5 == NULL ) ;
V_15 = F_8 ( sizeof( struct V_6 ) , V_5 -> V_18 ) ;
V_16 = V_15 + V_5 -> V_16 + V_13 ;
V_17 = V_5 -> V_17 + V_13 ;
F_5 () ;
* V_7 = F_9 ( V_17 , V_14 ) ;
if ( ! * V_7 )
return NULL ;
( * V_7 ) -> V_19 [ V_12 ] = V_15 ;
( * V_7 ) -> V_16 = V_16 ;
return ( void * ) ( * V_7 ) + V_15 ;
}
void * F_10 ( struct V_1 * V_2 , enum V_11 V_12 ,
T_1 V_13 , T_2 V_14 )
{
struct V_6 * V_20 , * V_21 ;
int V_3 , V_22 , V_23 ;
struct V_4 * V_5 ;
F_11 ( ! F_12 ( V_2 ) ) ;
V_20 = V_2 -> V_7 ;
if ( ! V_20 )
return F_6 ( & V_2 -> V_7 , V_12 , V_13 , V_14 ) ;
if ( F_2 ( V_20 , V_12 ) )
return NULL ;
F_3 () ;
V_5 = F_4 ( V_9 [ V_12 ] ) ;
F_7 ( V_5 == NULL ) ;
V_23 = F_8 ( V_20 -> V_16 , V_5 -> V_18 ) ;
V_22 = V_23 + V_5 -> V_16 + V_13 ;
F_5 () ;
V_21 = F_13 ( V_20 , V_22 , V_14 ) ;
if ( ! V_21 )
return NULL ;
if ( V_21 != V_20 ) {
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ ) {
if ( ! F_2 ( V_20 , V_3 ) )
continue;
F_3 () ;
V_5 = F_4 ( V_9 [ V_3 ] ) ;
if ( V_5 && V_5 -> V_24 )
V_5 -> V_24 ( ( void * ) V_21 + V_21 -> V_19 [ V_3 ] ,
( void * ) V_20 + V_20 -> V_19 [ V_3 ] ) ;
F_5 () ;
}
F_14 ( V_20 , V_25 ) ;
V_2 -> V_7 = V_21 ;
}
V_21 -> V_19 [ V_12 ] = V_23 ;
V_21 -> V_16 = V_22 ;
memset ( ( void * ) V_21 + V_23 , 0 , V_22 - V_23 ) ;
return ( void * ) V_21 + V_23 ;
}
static void F_15 ( struct V_4 * type )
{
int V_3 , V_26 ;
struct V_4 * V_27 , * V_28 ;
enum V_11 V_29 = 0 , V_30 = V_8 - 1 ;
if ( ( type -> V_31 & V_32 ) == 0 ) {
V_29 = type -> V_12 ;
V_30 = type -> V_12 ;
}
for ( V_3 = V_29 ; V_3 <= V_30 ; V_3 ++ ) {
V_27 = F_16 ( V_9 [ V_3 ] ,
F_17 ( & V_33 ) ) ;
if ( ! V_27 )
continue;
V_27 -> V_17 = F_8 ( sizeof( struct V_6 ) , V_27 -> V_18 ) +
V_27 -> V_16 ;
for ( V_26 = 0 ; V_26 < V_8 ; V_26 ++ ) {
V_28 = F_16 ( V_9 [ V_26 ] ,
F_17 ( & V_33 ) ) ;
if ( V_28 == NULL || V_28 == V_27 ||
( V_28 -> V_31 & V_32 ) == 0 )
continue;
V_27 -> V_17 = F_8 ( V_27 -> V_17 , V_28 -> V_18 )
+ V_28 -> V_16 ;
}
}
}
int F_18 ( struct V_4 * type )
{
int V_34 = 0 ;
F_19 ( & V_33 ) ;
if ( V_9 [ type -> V_12 ] ) {
V_34 = - V_35 ;
goto V_36;
}
type -> V_17 = F_8 ( sizeof( struct V_6 ) , type -> V_18 )
+ type -> V_16 ;
F_20 ( V_9 [ type -> V_12 ] , type ) ;
F_15 ( type ) ;
V_36:
F_21 ( & V_33 ) ;
return V_34 ;
}
void F_22 ( struct V_4 * type )
{
F_19 ( & V_33 ) ;
F_23 ( V_9 [ type -> V_12 ] , NULL ) ;
F_15 ( type ) ;
F_21 ( & V_33 ) ;
F_24 () ;
}
