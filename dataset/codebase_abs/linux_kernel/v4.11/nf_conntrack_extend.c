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
if ( ! V_5 ) {
F_5 () ;
return NULL ;
}
V_15 = F_7 ( sizeof( struct V_6 ) , V_5 -> V_18 ) ;
V_16 = V_15 + V_5 -> V_16 + V_13 ;
V_17 = V_5 -> V_17 + V_13 ;
F_5 () ;
* V_7 = F_8 ( V_17 , V_14 ) ;
if ( ! * V_7 )
return NULL ;
( * V_7 ) -> V_19 [ V_12 ] = V_15 ;
( * V_7 ) -> V_16 = V_16 ;
return ( void * ) ( * V_7 ) + V_15 ;
}
void * F_9 ( struct V_1 * V_2 , enum V_11 V_12 ,
T_1 V_13 , T_2 V_14 )
{
struct V_6 * V_20 , * V_21 ;
int V_22 , V_23 ;
struct V_4 * V_5 ;
F_10 ( ! F_11 ( V_2 ) ) ;
V_20 = V_2 -> V_7 ;
if ( ! V_20 )
return F_6 ( & V_2 -> V_7 , V_12 , V_13 , V_14 ) ;
if ( F_2 ( V_20 , V_12 ) )
return NULL ;
F_3 () ;
V_5 = F_4 ( V_9 [ V_12 ] ) ;
if ( ! V_5 ) {
F_5 () ;
return NULL ;
}
V_23 = F_7 ( V_20 -> V_16 , V_5 -> V_18 ) ;
V_22 = V_23 + V_5 -> V_16 + V_13 ;
F_5 () ;
V_21 = F_12 ( V_20 , V_22 , V_14 ) ;
if ( ! V_21 )
return NULL ;
if ( V_21 != V_20 ) {
F_13 ( V_20 , V_24 ) ;
F_14 ( V_2 -> V_7 , V_21 ) ;
}
V_21 -> V_19 [ V_12 ] = V_23 ;
V_21 -> V_16 = V_22 ;
memset ( ( void * ) V_21 + V_23 , 0 , V_22 - V_23 ) ;
return ( void * ) V_21 + V_23 ;
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
V_26 -> V_17 = F_7 ( sizeof( struct V_6 ) , V_26 -> V_18 ) +
V_26 -> V_16 ;
for ( V_25 = 0 ; V_25 < V_8 ; V_25 ++ ) {
V_27 = F_16 ( V_9 [ V_25 ] ,
F_17 ( & V_32 ) ) ;
if ( V_27 == NULL || V_27 == V_26 ||
( V_27 -> V_30 & V_31 ) == 0 )
continue;
V_26 -> V_17 = F_7 ( V_26 -> V_17 , V_27 -> V_18 )
+ V_27 -> V_16 ;
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
type -> V_17 = F_7 ( sizeof( struct V_6 ) , type -> V_18 )
+ type -> V_16 ;
F_14 ( V_9 [ type -> V_12 ] , type ) ;
F_15 ( type ) ;
V_35:
F_20 ( & V_32 ) ;
return V_33 ;
}
void F_21 ( struct V_4 * type )
{
F_19 ( & V_32 ) ;
F_22 ( V_9 [ type -> V_12 ] , NULL ) ;
F_15 ( type ) ;
F_20 ( & V_32 ) ;
F_23 () ;
}
