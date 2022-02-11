void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
struct V_4 * V_5 ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
F_2 () ;
V_5 = F_3 ( V_7 [ V_3 ] ) ;
if ( V_5 && V_5 -> V_8 )
V_5 -> V_8 ( V_2 ) ;
F_4 () ;
}
}
void * F_5 ( struct V_1 * V_2 , enum V_9 V_10 , T_1 V_11 )
{
unsigned int V_12 , V_13 , V_14 , V_15 ;
struct V_16 * V_17 , * V_18 ;
struct V_4 * V_5 ;
F_6 ( ! F_7 ( V_2 ) ) ;
V_17 = V_2 -> V_19 ;
if ( V_17 ) {
if ( F_8 ( V_17 , V_10 ) )
return NULL ;
V_14 = V_17 -> V_20 ;
} else {
V_14 = sizeof( * V_18 ) ;
}
F_2 () ;
V_5 = F_3 ( V_7 [ V_10 ] ) ;
if ( ! V_5 ) {
F_4 () ;
return NULL ;
}
V_13 = F_9 ( V_14 , V_5 -> V_21 ) ;
V_12 = V_13 + V_5 -> V_20 ;
F_4 () ;
V_15 = F_10 ( V_12 , V_22 ) ;
V_18 = F_11 ( V_17 , V_15 , V_11 ) ;
if ( ! V_18 )
return NULL ;
if ( ! V_17 ) {
memset ( V_18 -> V_23 , 0 , sizeof( V_18 -> V_23 ) ) ;
V_2 -> V_19 = V_18 ;
} else if ( V_18 != V_17 ) {
F_12 ( V_17 , V_24 ) ;
F_13 ( V_2 -> V_19 , V_18 ) ;
}
V_18 -> V_23 [ V_10 ] = V_13 ;
V_18 -> V_20 = V_12 ;
memset ( ( void * ) V_18 + V_13 , 0 , V_12 - V_13 ) ;
return ( void * ) V_18 + V_13 ;
}
int F_14 ( const struct V_4 * type )
{
int V_25 = 0 ;
F_15 ( & V_26 ) ;
if ( V_7 [ type -> V_10 ] ) {
V_25 = - V_27 ;
goto V_28;
}
F_13 ( V_7 [ type -> V_10 ] , type ) ;
V_28:
F_16 ( & V_26 ) ;
return V_25 ;
}
void F_17 ( const struct V_4 * type )
{
F_15 ( & V_26 ) ;
F_18 ( V_7 [ type -> V_10 ] , NULL ) ;
F_16 ( & V_26 ) ;
F_19 () ;
}
