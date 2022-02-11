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
F_6 ( struct V_6 * * V_7 , enum V_11 V_12 , T_1 V_13 )
{
unsigned int V_14 , V_15 ;
struct V_4 * V_5 ;
T_2 V_16 ;
F_3 () ;
V_5 = F_4 ( V_9 [ V_12 ] ) ;
F_7 ( V_5 == NULL ) ;
V_14 = F_8 ( sizeof( struct V_6 ) , V_5 -> V_17 ) ;
V_15 = V_14 + V_5 -> V_15 ;
V_16 = V_5 -> V_16 ;
F_5 () ;
* V_7 = F_9 ( V_16 , V_13 ) ;
if ( ! * V_7 )
return NULL ;
( * V_7 ) -> V_18 [ V_12 ] = V_14 ;
( * V_7 ) -> V_15 = V_15 ;
return ( void * ) ( * V_7 ) + V_14 ;
}
void * F_10 ( struct V_1 * V_2 , enum V_11 V_12 , T_1 V_13 )
{
struct V_6 * V_19 , * V_20 ;
int V_3 , V_21 , V_22 ;
struct V_4 * V_5 ;
F_11 ( ! F_12 ( V_2 ) ) ;
V_19 = V_2 -> V_7 ;
if ( ! V_19 )
return F_6 ( & V_2 -> V_7 , V_12 , V_13 ) ;
if ( F_2 ( V_19 , V_12 ) )
return NULL ;
F_3 () ;
V_5 = F_4 ( V_9 [ V_12 ] ) ;
F_7 ( V_5 == NULL ) ;
V_22 = F_8 ( V_19 -> V_15 , V_5 -> V_17 ) ;
V_21 = V_22 + V_5 -> V_15 ;
F_5 () ;
V_20 = F_13 ( V_19 , V_21 , V_13 ) ;
if ( ! V_20 )
return NULL ;
if ( V_20 != V_19 ) {
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ ) {
if ( ! F_2 ( V_19 , V_3 ) )
continue;
F_3 () ;
V_5 = F_4 ( V_9 [ V_3 ] ) ;
if ( V_5 && V_5 -> V_23 )
V_5 -> V_23 ( ( void * ) V_20 + V_20 -> V_18 [ V_3 ] ,
( void * ) V_19 + V_19 -> V_18 [ V_3 ] ) ;
F_5 () ;
}
F_14 ( V_19 , V_24 ) ;
V_2 -> V_7 = V_20 ;
}
V_20 -> V_18 [ V_12 ] = V_22 ;
V_20 -> V_15 = V_21 ;
memset ( ( void * ) V_20 + V_22 , 0 , V_21 - V_22 ) ;
return ( void * ) V_20 + V_22 ;
}
static void F_15 ( struct V_4 * type )
{
int V_3 , V_25 ;
struct V_4 * V_26 , * V_27 ;
enum V_11 V_28 = 0 , V_29 = V_8 - 1 ;
if ( ( type -> V_30 & V_31 ) == 0 ) {
V_28 = type -> V_12 ;
V_29 = type -> V_12 ;
}
for ( V_3 = V_28 ; V_3 <= V_29 ; V_3 ++ ) {
V_26 = F_16 ( V_9 [ V_3 ] ,
F_17 ( & V_32 ) ) ;
if ( ! V_26 )
continue;
V_26 -> V_16 = F_8 ( sizeof( struct V_6 ) , V_26 -> V_17 ) +
V_26 -> V_15 ;
for ( V_25 = 0 ; V_25 < V_8 ; V_25 ++ ) {
V_27 = F_16 ( V_9 [ V_25 ] ,
F_17 ( & V_32 ) ) ;
if ( V_27 == NULL || V_27 == V_26 ||
( V_27 -> V_30 & V_31 ) == 0 )
continue;
V_26 -> V_16 = F_8 ( V_26 -> V_16 , V_27 -> V_17 )
+ V_27 -> V_15 ;
}
}
}
int F_18 ( struct V_4 * type )
{
int V_33 = 0 ;
F_19 ( & V_32 ) ;
if ( V_9 [ type -> V_12 ] ) {
V_33 = - V_34 ;
goto V_35;
}
type -> V_16 = F_8 ( sizeof( struct V_6 ) , type -> V_17 )
+ type -> V_15 ;
F_20 ( V_9 [ type -> V_12 ] , type ) ;
F_15 ( type ) ;
V_35:
F_21 ( & V_32 ) ;
return V_33 ;
}
void F_22 ( struct V_4 * type )
{
F_19 ( & V_32 ) ;
F_23 ( V_9 [ type -> V_12 ] , NULL ) ;
F_15 ( type ) ;
F_21 ( & V_32 ) ;
F_24 () ;
}
