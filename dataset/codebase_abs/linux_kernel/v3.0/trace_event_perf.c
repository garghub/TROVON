static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! ( V_4 -> V_5 . V_6 & V_7 ) )
return 0 ;
if ( V_4 -> V_8 == V_9 ) {
if ( V_2 -> V_10 & V_11 )
return 0 ;
}
if ( F_2 () && ! F_3 ( V_12 ) )
return - V_13 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_14 T_1 * V_15 ;
int V_16 ;
int V_17 ;
V_16 = F_1 ( V_2 , V_4 ) ;
if ( V_16 )
return V_16 ;
V_4 -> V_2 = V_2 ;
if ( V_2 -> V_18 ++ > 0 )
return 0 ;
V_16 = - V_19 ;
V_15 = F_5 ( struct V_14 ) ;
if ( ! V_15 )
goto V_20;
F_6 (cpu)
F_7 ( F_8 ( V_15 , V_17 ) ) ;
V_2 -> V_21 = V_15 ;
if ( ! V_22 ) {
char T_1 * V_23 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_23 = ( char T_1 * ) F_5 ( V_26 ) ;
if ( ! V_23 )
goto V_20;
V_27 [ V_24 ] = V_23 ;
}
}
V_16 = V_2 -> V_28 -> V_29 ( V_2 , V_30 ) ;
if ( V_16 )
goto V_20;
V_22 ++ ;
return 0 ;
V_20:
if ( ! V_22 ) {
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
F_9 ( V_27 [ V_24 ] ) ;
V_27 [ V_24 ] = NULL ;
}
}
if ( ! -- V_2 -> V_18 ) {
F_9 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
}
return V_16 ;
}
int F_10 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_31 = V_4 -> V_5 . V_32 ;
int V_16 = - V_33 ;
F_11 ( & V_34 ) ;
F_12 (tp_event, &ftrace_events, list) {
if ( V_2 -> V_35 . type == V_31 &&
V_2 -> V_28 && V_2 -> V_28 -> V_29 &&
F_13 ( V_2 -> V_36 ) ) {
V_16 = F_4 ( V_2 , V_4 ) ;
if ( V_16 )
F_14 ( V_2 -> V_36 ) ;
break;
}
}
F_15 ( & V_34 ) ;
return V_16 ;
}
int F_16 ( struct V_3 * V_4 , int V_10 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_14 T_1 * V_37 ;
struct V_14 * V_15 ;
V_37 = V_2 -> V_21 ;
if ( F_17 ( ! V_37 ) )
return - V_33 ;
if ( ! ( V_10 & V_38 ) )
V_4 -> V_39 . V_40 = V_41 ;
V_15 = F_18 ( V_37 ) ;
F_19 ( & V_4 -> V_42 , V_15 ) ;
return 0 ;
}
void F_20 ( struct V_3 * V_4 , int V_10 )
{
F_21 ( & V_4 -> V_42 ) ;
}
void F_22 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
int V_24 ;
F_11 ( & V_34 ) ;
if ( -- V_2 -> V_18 > 0 )
goto V_43;
V_2 -> V_28 -> V_29 ( V_2 , V_44 ) ;
F_23 () ;
F_9 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
if ( ! -- V_22 ) {
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
F_9 ( V_27 [ V_24 ] ) ;
V_27 [ V_24 ] = NULL ;
}
}
V_43:
F_14 ( V_2 -> V_36 ) ;
F_15 ( & V_34 ) ;
}
T_2 void * F_24 ( int V_45 , unsigned short type ,
struct V_46 * V_47 , int * V_48 )
{
struct V_49 * V_50 ;
unsigned long V_10 ;
char * V_51 ;
int V_52 ;
F_25 ( V_53 % sizeof( unsigned long ) ) ;
V_52 = F_26 () ;
* V_48 = F_27 () ;
if ( * V_48 < 0 )
return NULL ;
V_51 = F_18 ( V_27 [ * V_48 ] ) ;
memset ( & V_51 [ V_45 - sizeof( V_54 ) ] , 0 , sizeof( V_54 ) ) ;
V_50 = (struct V_49 * ) V_51 ;
F_28 ( V_10 ) ;
F_29 ( V_50 , V_10 , V_52 ) ;
V_50 -> type = type ;
return V_51 ;
}
