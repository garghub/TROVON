static int
F_1 ( struct V_1 * V_1 ,
struct V_2 * * V_3 ,
const char * V_4 ,
struct V_5 * V_6 )
{
if ( * V_3 == NULL ) {
* V_3 = F_2 ( V_1 , V_4 , V_6 ) ;
if ( * V_3 == NULL )
return - V_7 ;
}
return 0 ;
}
static void
F_3 ( struct V_2 * * V_3 ,
struct V_5 * * V_6 ,
unsigned int V_8 )
{
if ( V_8 > 0 )
return;
F_4 ( * V_3 ) ;
F_5 ( * V_6 ) ;
* V_3 = NULL ;
* V_6 = NULL ;
}
struct V_9 *
F_6 ( T_1 V_10 , T_2 V_11 )
{
if ( F_7 ( V_10 >= V_12 || V_13 [ V_10 ] == NULL ) )
return & V_14 ;
return F_8 ( V_13 [ V_10 ] [ V_11 ] ) ;
}
struct V_15 *
F_9 ( T_1 V_10 )
{
struct V_15 * V_16 ;
F_10 () ;
V_16 = F_11 ( V_10 ) ;
if ( ! F_12 ( V_16 -> V_17 ) )
V_16 = & V_18 ;
F_13 () ;
return V_16 ;
}
int
F_14 ( unsigned short V_10 )
{
int V_19 ;
struct V_15 * V_16 ;
V_20: V_16 = F_9 ( V_10 ) ;
if ( V_16 == & V_18 ) {
V_19 = F_15 ( L_1 , V_10 ) ;
if ( ! V_19 )
goto V_20;
return - V_21 ;
}
return 0 ;
}
void F_16 ( unsigned short V_10 )
{
struct V_15 * V_16 ;
F_10 () ;
V_16 = F_11 ( V_10 ) ;
F_17 ( V_16 -> V_17 ) ;
F_13 () ;
}
struct V_9 *
F_18 ( T_1 V_22 , T_2 V_23 )
{
struct V_9 * V_16 ;
F_10 () ;
V_16 = F_6 ( V_22 , V_23 ) ;
if ( ! F_12 ( V_16 -> V_17 ) )
V_16 = & V_14 ;
F_13 () ;
return V_16 ;
}
void F_19 ( struct V_9 * V_16 )
{
F_17 ( V_16 -> V_17 ) ;
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
int F_24 ( struct V_15 * V_27 )
{
int V_19 = 0 ;
struct V_15 * V_28 ;
if ( V_27 -> V_10 >= V_12 )
return - V_29 ;
if ( V_27 -> V_30 && ! V_27 -> V_31 )
return - V_32 ;
F_25 ( & V_33 ) ;
V_28 = F_26 ( V_34 [ V_27 -> V_10 ] ,
F_27 ( & V_33 ) ) ;
if ( V_28 != & V_18 ) {
V_19 = - V_29 ;
goto V_35;
}
if ( V_27 -> V_31 )
V_27 -> V_36 = 3 * V_27 -> V_31 () ;
F_28 ( V_34 [ V_27 -> V_10 ] , V_27 ) ;
V_35:
F_29 ( & V_33 ) ;
return V_19 ;
}
int F_30 ( struct V_1 * V_1 ,
struct V_15 * V_27 )
{
int V_19 ;
if ( V_27 -> V_37 ) {
V_19 = V_27 -> V_37 ( V_1 ) ;
if ( V_19 < 0 )
return V_19 ;
}
return 0 ;
}
void F_31 ( struct V_15 * V_27 )
{
F_32 ( V_27 -> V_10 >= V_12 ) ;
F_25 ( & V_33 ) ;
F_32 ( F_26 ( V_34 [ V_27 -> V_10 ] ,
F_27 ( & V_33 )
) != V_27 ) ;
F_28 ( V_34 [ V_27 -> V_10 ] ,
& V_18 ) ;
F_29 ( & V_33 ) ;
F_33 () ;
}
void F_34 ( struct V_1 * V_1 ,
struct V_15 * V_27 )
{
F_35 ( V_1 , F_20 , V_27 , 0 , 0 ) ;
}
static struct V_38 * F_36 ( struct V_1 * V_1 ,
struct V_9 * V_11 )
{
if ( V_11 -> V_39 ) {
return V_11 -> V_39 ( V_1 ) ;
} else if ( V_11 -> V_40 ) {
return F_37 ( V_1 , * V_11 -> V_40 ) ;
}
return NULL ;
}
static
int F_38 ( struct V_1 * V_1 ,
struct V_38 * V_41 ,
struct V_9 * V_11 )
{
int V_42 = 0 ;
#ifdef F_39
if ( V_41 -> V_5 != NULL ) {
V_42 = F_1 ( V_1 ,
& V_41 -> V_2 ,
L_2 ,
V_41 -> V_5 ) ;
if ( V_42 < 0 ) {
if ( ! V_41 -> V_8 ) {
F_5 ( V_41 -> V_5 ) ;
V_41 -> V_5 = NULL ;
}
}
}
#endif
return V_42 ;
}
static
void F_40 ( struct V_1 * V_1 ,
struct V_38 * V_41 ,
struct V_9 * V_11 )
{
#ifdef F_39
if ( V_41 -> V_2 != NULL )
F_3 ( & V_41 -> V_2 ,
& V_41 -> V_5 ,
V_41 -> V_8 ) ;
#endif
}
int F_41 ( struct V_9 * V_11 )
{
int V_19 = 0 ;
if ( V_11 -> V_10 >= V_43 )
return - V_29 ;
if ( ( V_11 -> V_44 && ! V_11 -> V_45 )
|| ( V_11 -> V_30 && ! V_11 -> V_31 ) )
return - V_32 ;
F_25 ( & V_33 ) ;
if ( ! V_13 [ V_11 -> V_10 ] ) {
struct V_9 T_3 * * V_46 ;
int V_25 ;
V_46 = F_42 ( V_47 *
sizeof( struct V_9 * ) ,
V_48 ) ;
if ( V_46 == NULL ) {
V_19 = - V_7 ;
goto V_35;
}
for ( V_25 = 0 ; V_25 < V_47 ; V_25 ++ )
F_43 ( V_46 [ V_25 ] , & V_14 ) ;
F_44 () ;
V_13 [ V_11 -> V_10 ] = V_46 ;
} else if ( F_26 (
V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
F_27 ( & V_33 )
) != & V_14 ) {
V_19 = - V_29 ;
goto V_35;
}
V_11 -> V_36 = 0 ;
if ( V_11 -> V_45 )
V_11 -> V_36 += V_11 -> V_45 () ;
if ( V_11 -> V_31 )
V_11 -> V_36 += 3 * V_11 -> V_31 () ;
F_28 ( V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
V_11 ) ;
V_35:
F_29 ( & V_33 ) ;
return V_19 ;
}
int F_45 ( struct V_1 * V_1 ,
struct V_9 * V_11 )
{
int V_19 = 0 ;
struct V_38 * V_41 = NULL ;
if ( V_11 -> V_37 ) {
V_19 = V_11 -> V_37 ( V_1 , V_11 -> V_10 ) ;
if ( V_19 < 0 )
goto V_49;
}
V_41 = F_36 ( V_1 , V_11 ) ;
if ( V_41 == NULL )
goto V_49;
V_19 = F_38 ( V_1 , V_41 , V_11 ) ;
if ( V_19 < 0 )
goto V_49;
V_41 -> V_8 ++ ;
V_49:
return V_19 ;
}
void F_46 ( struct V_9 * V_11 )
{
F_32 ( V_11 -> V_10 >= V_43 ) ;
F_25 ( & V_33 ) ;
F_32 ( F_26 (
V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
F_27 ( & V_33 )
) != V_11 ) ;
F_28 ( V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
& V_14 ) ;
F_29 ( & V_33 ) ;
F_33 () ;
}
void F_47 ( struct V_1 * V_1 ,
struct V_9 * V_11 )
{
struct V_38 * V_41 = NULL ;
V_41 = F_36 ( V_1 , V_11 ) ;
if ( V_41 == NULL )
return;
V_41 -> V_8 -- ;
F_40 ( V_1 , V_41 , V_11 ) ;
F_35 ( V_1 , F_22 , V_11 , 0 , 0 ) ;
}
int F_48 ( struct V_1 * V_1 )
{
int V_42 ;
struct V_38 * V_41 = F_36 ( V_1 ,
& V_14 ) ;
V_42 = V_14 . V_37 ( V_1 ,
V_14 . V_10 ) ;
if ( V_42 < 0 )
return V_42 ;
V_42 = F_38 ( V_1 ,
V_41 ,
& V_14 ) ;
if ( V_42 < 0 )
return V_42 ;
V_41 -> V_8 ++ ;
return 0 ;
}
void F_49 ( struct V_1 * V_1 )
{
struct V_38 * V_41 = F_36 ( V_1 ,
& V_14 ) ;
V_41 -> V_8 -- ;
F_40 ( V_1 ,
V_41 ,
& V_14 ) ;
}
int F_50 ( void )
{
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_12 ; V_25 ++ )
F_28 ( V_34 [ V_25 ] ,
& V_18 ) ;
return 0 ;
}
void F_51 ( void )
{
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_43 ; V_25 ++ )
F_5 ( V_13 [ V_25 ] ) ;
}
