static int
F_1 ( struct V_1 * * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( * V_2 == NULL ) {
* V_2 = F_2 ( V_4 , V_6 ) ;
if ( * V_2 == NULL )
return - V_8 ;
}
if ( V_7 != NULL )
( * V_7 ) ++ ;
return 0 ;
}
static void
F_3 ( struct V_1 * * V_2 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 != NULL && -- * V_7 > 0 )
return;
F_4 ( * V_2 ) ;
* V_2 = NULL ;
}
struct V_9 *
F_5 ( T_1 V_10 , T_2 V_11 )
{
if ( F_6 ( V_10 >= V_12 || V_13 [ V_10 ] == NULL ) )
return & V_14 ;
return F_7 ( V_13 [ V_10 ] [ V_11 ] ) ;
}
struct V_15 *
F_8 ( T_1 V_10 )
{
struct V_15 * V_16 ;
F_9 () ;
V_16 = F_10 ( V_10 ) ;
if ( ! F_11 ( V_16 -> V_17 ) )
V_16 = & V_18 ;
F_12 () ;
return V_16 ;
}
void F_13 ( struct V_15 * V_16 )
{
F_14 ( V_16 -> V_17 ) ;
}
int
F_15 ( unsigned short V_10 )
{
int V_19 ;
struct V_15 * V_16 ;
V_20: V_16 = F_8 ( V_10 ) ;
if ( V_16 == & V_18 ) {
V_19 = F_16 ( L_1 , V_10 ) ;
if ( ! V_19 )
goto V_20;
return - V_21 ;
}
return 0 ;
}
void F_17 ( unsigned short V_10 )
{
struct V_15 * V_16 ;
F_9 () ;
V_16 = F_10 ( V_10 ) ;
F_14 ( V_16 -> V_17 ) ;
F_12 () ;
}
static int F_18 ( struct V_22 * V_23 , void * V_24 )
{
return F_19 ( V_23 ) == ( (struct V_15 * ) V_24 ) -> V_10 ;
}
static int F_20 ( struct V_22 * V_23 , void * V_24 )
{
struct V_9 * V_11 ;
V_11 = (struct V_9 * ) V_24 ;
return F_21 ( V_23 ) == V_11 -> V_11 &&
F_19 ( V_23 ) == V_11 -> V_10 ;
}
static int F_22 ( struct V_15 * V_10 )
{
int V_25 = 0 ;
#ifdef F_23
if ( V_10 -> V_5 != NULL ) {
V_25 = F_1 ( & V_10 -> V_1 ,
V_10 -> V_26 ,
V_10 -> V_5 , NULL ) ;
}
#endif
return V_25 ;
}
static void F_24 ( struct V_15 * V_10 )
{
#ifdef F_23
if ( V_10 -> V_1 != NULL )
F_3 ( & V_10 -> V_1 ,
V_10 -> V_5 , NULL ) ;
#endif
}
int F_25 ( struct V_15 * V_27 )
{
int V_19 = 0 ;
struct V_15 * V_28 ;
if ( V_27 -> V_10 >= V_12 )
return - V_29 ;
if ( V_27 -> V_30 && ! V_27 -> V_31 )
return - V_32 ;
F_26 ( & V_33 ) ;
V_28 = F_27 ( V_34 [ V_27 -> V_10 ] ,
F_28 ( & V_33 ) ) ;
if ( V_28 != & V_18 ) {
V_19 = - V_29 ;
goto V_35;
}
V_19 = F_22 ( V_27 ) ;
if ( V_19 < 0 )
goto V_35;
if ( V_27 -> V_31 )
V_27 -> V_36 = 3 * V_27 -> V_31 () ;
F_29 ( V_34 [ V_27 -> V_10 ] , V_27 ) ;
V_35:
F_30 ( & V_33 ) ;
return V_19 ;
}
void F_31 ( struct V_15 * V_27 )
{
struct V_37 * V_37 ;
F_32 ( V_27 -> V_10 >= V_12 ) ;
F_26 ( & V_33 ) ;
F_32 ( F_27 ( V_34 [ V_27 -> V_10 ] ,
F_28 ( & V_33 )
) != V_27 ) ;
F_29 ( V_34 [ V_27 -> V_10 ] ,
& V_18 ) ;
F_24 ( V_27 ) ;
F_30 ( & V_33 ) ;
F_33 () ;
F_34 () ;
F_35 (net)
F_36 ( V_37 , F_18 , V_27 ) ;
F_37 () ;
}
static int F_38 ( struct V_9 * V_11 )
{
int V_25 = 0 ;
#ifdef F_23
if ( V_11 -> V_5 != NULL ) {
V_25 = F_1 ( V_11 -> V_1 ,
V_38 ,
V_11 -> V_5 ,
V_11 -> V_39 ) ;
if ( V_25 < 0 )
goto V_40;
}
#ifdef F_39
if ( V_11 -> V_41 != NULL ) {
V_25 = F_1 ( & V_11 -> V_42 ,
V_43 ,
V_11 -> V_41 , NULL ) ;
if ( V_25 == 0 )
goto V_40;
F_3 ( V_11 -> V_1 ,
V_11 -> V_5 ,
V_11 -> V_39 ) ;
}
#endif
V_40:
#endif
return V_25 ;
}
static void F_40 ( struct V_9 * V_11 )
{
#ifdef F_23
if ( V_11 -> V_1 != NULL &&
* V_11 -> V_1 != NULL )
F_3 ( V_11 -> V_1 ,
V_11 -> V_5 ,
V_11 -> V_39 ) ;
#ifdef F_39
if ( V_11 -> V_42 != NULL )
F_3 ( & V_11 -> V_42 ,
V_11 -> V_41 , NULL ) ;
#endif
#endif
}
int F_41 ( struct V_9 * V_11 )
{
int V_19 = 0 ;
if ( V_11 -> V_10 >= V_44 )
return - V_29 ;
if ( ( V_11 -> V_45 && ! V_11 -> V_46 )
|| ( V_11 -> V_30 && ! V_11 -> V_31 ) )
return - V_32 ;
F_26 ( & V_33 ) ;
if ( ! V_13 [ V_11 -> V_10 ] ) {
struct V_9 T_3 * * V_47 ;
int V_23 ;
V_47 = F_42 ( V_48 *
sizeof( struct V_9 * ) ,
V_49 ) ;
if ( V_47 == NULL ) {
V_19 = - V_8 ;
goto V_35;
}
for ( V_23 = 0 ; V_23 < V_48 ; V_23 ++ )
F_43 ( V_47 [ V_23 ] , & V_14 ) ;
F_44 () ;
V_13 [ V_11 -> V_10 ] = V_47 ;
} else if ( F_27 (
V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
F_28 ( & V_33 )
) != & V_14 ) {
V_19 = - V_29 ;
goto V_35;
}
V_19 = F_38 ( V_11 ) ;
if ( V_19 < 0 )
goto V_35;
V_11 -> V_36 = 0 ;
if ( V_11 -> V_46 )
V_11 -> V_36 += V_11 -> V_46 () ;
if ( V_11 -> V_31 )
V_11 -> V_36 += 3 * V_11 -> V_31 () ;
F_29 ( V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
V_11 ) ;
V_35:
F_30 ( & V_33 ) ;
return V_19 ;
}
void F_45 ( struct V_9 * V_11 )
{
struct V_37 * V_37 ;
F_32 ( V_11 -> V_10 >= V_44 ) ;
F_26 ( & V_33 ) ;
F_32 ( F_27 (
V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
F_28 ( & V_33 )
) != V_11 ) ;
F_29 ( V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
& V_14 ) ;
F_40 ( V_11 ) ;
F_30 ( & V_33 ) ;
F_33 () ;
F_34 () ;
F_35 (net)
F_36 ( V_37 , F_20 , V_11 ) ;
F_37 () ;
}
int F_46 ( void )
{
unsigned int V_23 ;
int V_25 ;
V_25 = F_38 ( & V_14 ) ;
if ( V_25 < 0 )
return V_25 ;
for ( V_23 = 0 ; V_23 < V_12 ; V_23 ++ )
F_29 ( V_34 [ V_23 ] ,
& V_18 ) ;
return 0 ;
}
void F_47 ( void )
{
unsigned int V_23 ;
F_40 ( & V_14 ) ;
for ( V_23 = 0 ; V_23 < V_44 ; V_23 ++ )
F_48 ( V_13 [ V_23 ] ) ;
}
