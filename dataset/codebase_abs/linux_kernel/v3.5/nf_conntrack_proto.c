static int
F_1 ( struct V_1 * * V_2 , const char * V_3 ,
struct V_4 * V_5 , unsigned int * V_6 )
{
if ( * V_2 == NULL ) {
* V_2 = F_2 ( & V_7 , V_3 , V_5 ) ;
if ( * V_2 == NULL )
return - V_8 ;
}
if ( V_6 != NULL )
( * V_6 ) ++ ;
return 0 ;
}
static void
F_3 ( struct V_1 * * V_2 ,
struct V_4 * V_5 , unsigned int * V_6 )
{
if ( V_6 != NULL && -- * V_6 > 0 )
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
struct V_9 *
F_18 ( T_1 V_22 , T_2 V_23 )
{
struct V_9 * V_16 ;
F_9 () ;
V_16 = F_5 ( V_22 , V_23 ) ;
if ( ! F_11 ( V_16 -> V_17 ) )
V_16 = & V_14 ;
F_12 () ;
return V_16 ;
}
void F_19 ( struct V_9 * V_16 )
{
F_14 ( V_16 -> V_17 ) ;
}
static int F_20 ( struct V_24 * V_25 , void * V_26 )
{
return F_21 ( V_25 ) == ( (struct V_15 * ) V_26 ) -> V_10 ;
}
static int F_22 ( struct V_24 * V_25 , void * V_26 )
{
struct V_9 * V_11 ;
V_11 = (struct V_9 * ) V_26 ;
return F_23 ( V_25 ) == V_11 -> V_11 &&
F_21 ( V_25 ) == V_11 -> V_10 ;
}
static int F_24 ( struct V_15 * V_10 )
{
int V_27 = 0 ;
#ifdef F_25
if ( V_10 -> V_4 != NULL ) {
V_27 = F_1 ( & V_10 -> V_1 ,
V_10 -> V_28 ,
V_10 -> V_4 , NULL ) ;
}
#endif
return V_27 ;
}
static void F_26 ( struct V_15 * V_10 )
{
#ifdef F_25
if ( V_10 -> V_1 != NULL )
F_3 ( & V_10 -> V_1 ,
V_10 -> V_4 , NULL ) ;
#endif
}
int F_27 ( struct V_15 * V_29 )
{
int V_19 = 0 ;
struct V_15 * V_30 ;
if ( V_29 -> V_10 >= V_12 )
return - V_31 ;
if ( V_29 -> V_32 && ! V_29 -> V_33 )
return - V_34 ;
F_28 ( & V_35 ) ;
V_30 = F_29 ( V_36 [ V_29 -> V_10 ] ,
F_30 ( & V_35 ) ) ;
if ( V_30 != & V_18 ) {
V_19 = - V_31 ;
goto V_37;
}
V_19 = F_24 ( V_29 ) ;
if ( V_19 < 0 )
goto V_37;
if ( V_29 -> V_33 )
V_29 -> V_38 = 3 * V_29 -> V_33 () ;
F_31 ( V_36 [ V_29 -> V_10 ] , V_29 ) ;
V_37:
F_32 ( & V_35 ) ;
return V_19 ;
}
void F_33 ( struct V_15 * V_29 )
{
struct V_39 * V_39 ;
F_34 ( V_29 -> V_10 >= V_12 ) ;
F_28 ( & V_35 ) ;
F_34 ( F_29 ( V_36 [ V_29 -> V_10 ] ,
F_30 ( & V_35 )
) != V_29 ) ;
F_31 ( V_36 [ V_29 -> V_10 ] ,
& V_18 ) ;
F_26 ( V_29 ) ;
F_32 ( & V_35 ) ;
F_35 () ;
F_36 () ;
F_37 (net)
F_38 ( V_39 , F_20 , V_29 ) ;
F_39 () ;
}
static int F_40 ( struct V_9 * V_11 )
{
int V_27 = 0 ;
#ifdef F_25
if ( V_11 -> V_4 != NULL ) {
V_27 = F_1 ( V_11 -> V_1 ,
L_2 ,
V_11 -> V_4 ,
V_11 -> V_40 ) ;
if ( V_27 < 0 )
goto V_41;
}
#ifdef F_41
if ( V_11 -> V_42 != NULL ) {
V_27 = F_1 ( & V_11 -> V_43 ,
L_3 ,
V_11 -> V_42 , NULL ) ;
if ( V_27 == 0 )
goto V_41;
F_3 ( V_11 -> V_1 ,
V_11 -> V_4 ,
V_11 -> V_40 ) ;
}
#endif
V_41:
#endif
return V_27 ;
}
static void F_42 ( struct V_9 * V_11 )
{
#ifdef F_25
if ( V_11 -> V_1 != NULL &&
* V_11 -> V_1 != NULL )
F_3 ( V_11 -> V_1 ,
V_11 -> V_4 ,
V_11 -> V_40 ) ;
#ifdef F_41
if ( V_11 -> V_43 != NULL )
F_3 ( & V_11 -> V_43 ,
V_11 -> V_42 , NULL ) ;
#endif
#endif
}
int F_43 ( struct V_9 * V_11 )
{
int V_19 = 0 ;
if ( V_11 -> V_10 >= V_44 )
return - V_31 ;
if ( ( V_11 -> V_45 && ! V_11 -> V_46 )
|| ( V_11 -> V_32 && ! V_11 -> V_33 ) )
return - V_34 ;
F_28 ( & V_35 ) ;
if ( ! V_13 [ V_11 -> V_10 ] ) {
struct V_9 T_3 * * V_47 ;
int V_25 ;
V_47 = F_44 ( V_48 *
sizeof( struct V_9 * ) ,
V_49 ) ;
if ( V_47 == NULL ) {
V_19 = - V_8 ;
goto V_37;
}
for ( V_25 = 0 ; V_25 < V_48 ; V_25 ++ )
F_45 ( V_47 [ V_25 ] , & V_14 ) ;
F_46 () ;
V_13 [ V_11 -> V_10 ] = V_47 ;
} else if ( F_29 (
V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
F_30 ( & V_35 )
) != & V_14 ) {
V_19 = - V_31 ;
goto V_37;
}
V_19 = F_40 ( V_11 ) ;
if ( V_19 < 0 )
goto V_37;
V_11 -> V_38 = 0 ;
if ( V_11 -> V_46 )
V_11 -> V_38 += V_11 -> V_46 () ;
if ( V_11 -> V_33 )
V_11 -> V_38 += 3 * V_11 -> V_33 () ;
F_31 ( V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
V_11 ) ;
V_37:
F_32 ( & V_35 ) ;
return V_19 ;
}
void F_47 ( struct V_9 * V_11 )
{
struct V_39 * V_39 ;
F_34 ( V_11 -> V_10 >= V_44 ) ;
F_28 ( & V_35 ) ;
F_34 ( F_29 (
V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
F_30 ( & V_35 )
) != V_11 ) ;
F_31 ( V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
& V_14 ) ;
F_42 ( V_11 ) ;
F_32 ( & V_35 ) ;
F_35 () ;
F_36 () ;
F_37 (net)
F_38 ( V_39 , F_22 , V_11 ) ;
F_39 () ;
}
int F_48 ( void )
{
unsigned int V_25 ;
int V_27 ;
V_27 = F_40 ( & V_14 ) ;
if ( V_27 < 0 )
return V_27 ;
for ( V_25 = 0 ; V_25 < V_12 ; V_25 ++ )
F_31 ( V_36 [ V_25 ] ,
& V_18 ) ;
return 0 ;
}
void F_49 ( void )
{
unsigned int V_25 ;
F_42 ( & V_14 ) ;
for ( V_25 = 0 ; V_25 < V_44 ; V_25 ++ )
F_50 ( V_13 [ V_25 ] ) ;
}
