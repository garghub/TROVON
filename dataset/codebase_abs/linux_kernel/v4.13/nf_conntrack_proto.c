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
int F_18 ( struct V_1 * V_1 , T_3 V_22 )
{
const struct V_15 * V_10 ;
int V_19 ;
F_19 () ;
V_19 = F_14 ( V_22 ) ;
if ( V_19 < 0 )
return V_19 ;
F_10 () ;
V_10 = F_11 ( V_22 ) ;
F_13 () ;
if ( ! V_10 -> V_23 )
return 0 ;
V_19 = V_10 -> V_23 ( V_1 ) ;
if ( V_19 < 0 )
F_16 ( V_22 ) ;
return V_19 ;
}
void F_20 ( struct V_1 * V_1 , T_3 V_22 )
{
const struct V_15 * V_10 ;
F_19 () ;
F_10 () ;
V_10 = F_11 ( V_22 ) ;
F_13 () ;
if ( F_21 ( ! V_10 ) )
return;
if ( V_10 -> V_24 )
V_10 -> V_24 ( V_1 ) ;
F_16 ( V_22 ) ;
}
struct V_9 *
F_22 ( T_1 V_25 , T_2 V_26 )
{
struct V_9 * V_16 ;
F_10 () ;
V_16 = F_6 ( V_25 , V_26 ) ;
if ( ! F_12 ( V_16 -> V_17 ) )
V_16 = & V_14 ;
F_13 () ;
return V_16 ;
}
void F_23 ( struct V_9 * V_16 )
{
F_17 ( V_16 -> V_17 ) ;
}
static int F_24 ( struct V_27 * V_28 , void * V_29 )
{
return F_25 ( V_28 ) == ( (struct V_15 * ) V_29 ) -> V_10 ;
}
static int F_26 ( struct V_27 * V_28 , void * V_29 )
{
struct V_9 * V_11 ;
V_11 = V_29 ;
return F_27 ( V_28 ) == V_11 -> V_11 &&
F_25 ( V_28 ) == V_11 -> V_10 ;
}
int F_28 ( struct V_15 * V_30 )
{
int V_19 = 0 ;
struct V_15 * V_31 ;
if ( V_30 -> V_10 >= V_12 )
return - V_32 ;
if ( V_30 -> V_33 && ! V_30 -> V_34 )
return - V_35 ;
F_29 ( & V_36 ) ;
V_31 = F_30 ( V_37 [ V_30 -> V_10 ] ,
F_31 ( & V_36 ) ) ;
if ( V_31 != & V_18 ) {
V_19 = - V_32 ;
goto V_38;
}
if ( V_30 -> V_34 )
V_30 -> V_39 = 3 * V_30 -> V_34 () ;
F_32 ( V_37 [ V_30 -> V_10 ] , V_30 ) ;
V_38:
F_33 ( & V_36 ) ;
return V_19 ;
}
int F_34 ( struct V_1 * V_1 ,
struct V_15 * V_30 )
{
if ( V_40 == 0 )
return 0 ;
return V_30 -> V_23 ? V_30 -> V_23 ( V_1 ) : 0 ;
}
void F_35 ( struct V_15 * V_30 )
{
F_36 ( V_30 -> V_10 >= V_12 ) ;
F_29 ( & V_36 ) ;
F_36 ( F_30 ( V_37 [ V_30 -> V_10 ] ,
F_31 ( & V_36 )
) != V_30 ) ;
F_32 ( V_37 [ V_30 -> V_10 ] ,
& V_18 ) ;
F_33 ( & V_36 ) ;
F_37 () ;
F_38 ( F_24 , V_30 ) ;
}
void F_39 ( struct V_1 * V_1 ,
struct V_15 * V_30 )
{
if ( V_30 -> V_24 )
V_30 -> V_24 ( V_1 ) ;
}
static struct V_41 * F_40 ( struct V_1 * V_1 ,
struct V_9 * V_11 )
{
if ( V_11 -> V_42 ) {
return V_11 -> V_42 ( V_1 ) ;
} else if ( V_11 -> V_43 ) {
return F_41 ( V_1 , * V_11 -> V_43 ) ;
}
return NULL ;
}
static
int F_42 ( struct V_1 * V_1 ,
struct V_41 * V_44 ,
struct V_9 * V_11 )
{
int V_45 = 0 ;
#ifdef F_43
if ( V_44 -> V_5 != NULL ) {
V_45 = F_1 ( V_1 ,
& V_44 -> V_2 ,
L_2 ,
V_44 -> V_5 ) ;
if ( V_45 < 0 ) {
if ( ! V_44 -> V_8 ) {
F_5 ( V_44 -> V_5 ) ;
V_44 -> V_5 = NULL ;
}
}
}
#endif
return V_45 ;
}
static
void F_44 ( struct V_1 * V_1 ,
struct V_41 * V_44 ,
struct V_9 * V_11 )
{
#ifdef F_43
if ( V_44 -> V_2 != NULL )
F_3 ( & V_44 -> V_2 ,
& V_44 -> V_5 ,
V_44 -> V_8 ) ;
#endif
}
int F_45 ( struct V_9 * V_11 )
{
int V_19 = 0 ;
if ( V_11 -> V_10 >= F_46 ( V_13 ) )
return - V_32 ;
if ( ( V_11 -> V_46 && ! V_11 -> V_47 ) ||
( V_11 -> V_33 && ! V_11 -> V_34 ) )
return - V_35 ;
F_29 ( & V_36 ) ;
if ( ! V_13 [ V_11 -> V_10 ] ) {
struct V_9 T_4 * * V_48 ;
int V_28 ;
V_48 = F_47 ( V_49 *
sizeof( struct V_9 * ) ,
V_50 ) ;
if ( V_48 == NULL ) {
V_19 = - V_7 ;
goto V_38;
}
for ( V_28 = 0 ; V_28 < V_49 ; V_28 ++ )
F_48 ( V_48 [ V_28 ] ,
& V_14 ) ;
F_49 () ;
V_13 [ V_11 -> V_10 ] = V_48 ;
} else if ( F_30 (
V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
F_31 ( & V_36 )
) != & V_14 ) {
V_19 = - V_32 ;
goto V_38;
}
V_11 -> V_39 = 0 ;
if ( V_11 -> V_47 )
V_11 -> V_39 += V_11 -> V_47 () ;
if ( V_11 -> V_34 )
V_11 -> V_39 += 3 * V_11 -> V_34 () ;
F_32 ( V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
V_11 ) ;
V_38:
F_33 ( & V_36 ) ;
return V_19 ;
}
int F_50 ( struct V_1 * V_1 ,
struct V_9 * V_11 )
{
int V_19 = 0 ;
struct V_41 * V_44 = NULL ;
if ( V_11 -> V_51 ) {
V_19 = V_11 -> V_51 ( V_1 , V_11 -> V_10 ) ;
if ( V_19 < 0 )
goto V_52;
}
V_44 = F_40 ( V_1 , V_11 ) ;
if ( V_44 == NULL )
goto V_52;
V_19 = F_42 ( V_1 , V_44 , V_11 ) ;
if ( V_19 < 0 )
goto V_52;
V_44 -> V_8 ++ ;
V_52:
return V_19 ;
}
static void F_51 ( struct V_9 * V_11 )
{
F_36 ( V_11 -> V_10 >= F_46 ( V_13 ) ) ;
F_36 ( F_30 (
V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
F_31 ( & V_36 )
) != V_11 ) ;
F_32 ( V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
& V_14 ) ;
}
void F_52 ( struct V_9 * V_11 )
{
F_29 ( & V_36 ) ;
F_51 ( V_11 ) ;
F_33 ( & V_36 ) ;
F_37 () ;
}
void F_53 ( struct V_1 * V_1 ,
struct V_9 * V_11 )
{
struct V_41 * V_44 = F_40 ( V_1 , V_11 ) ;
if ( V_44 == NULL )
return;
V_44 -> V_8 -- ;
F_44 ( V_1 , V_44 , V_11 ) ;
}
int F_54 ( struct V_9 * V_11 [] ,
unsigned int V_53 )
{
int V_19 = - V_35 , V_54 ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_53 ; V_28 ++ ) {
V_19 = F_45 ( V_11 [ V_28 ] ) ;
if ( V_19 < 0 )
break;
}
if ( V_28 != V_53 ) {
V_54 = V_11 [ V_28 ] -> V_10 == V_55 ? 6 : 4 ;
F_55 ( L_3 ,
V_54 , V_11 [ V_28 ] -> V_56 , V_54 ) ;
F_56 ( V_11 , V_28 ) ;
}
return V_19 ;
}
int F_57 ( struct V_1 * V_1 ,
struct V_9 * V_11 [] ,
unsigned int V_53 )
{
int V_19 = - V_35 ;
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_53 ; V_28 ++ ) {
V_19 = F_50 ( V_1 , V_11 [ V_28 ] ) ;
if ( V_19 < 0 )
break;
}
if ( V_28 != V_53 ) {
F_55 ( L_4 ,
V_11 [ V_28 ] -> V_56 ,
V_11 [ V_28 ] -> V_10 == V_55 ? 6 : 4 ) ;
F_58 ( V_1 , V_11 , V_28 ) ;
}
return V_19 ;
}
void F_56 ( struct V_9 * V_11 [] ,
unsigned int V_53 )
{
F_29 ( & V_36 ) ;
while ( V_53 -- != 0 )
F_51 ( V_11 [ V_53 ] ) ;
F_33 ( & V_36 ) ;
F_59 () ;
F_38 ( F_26 , V_11 ) ;
}
void F_58 ( struct V_1 * V_1 ,
struct V_9 * V_11 [] ,
unsigned int V_53 )
{
while ( V_53 -- != 0 )
F_53 ( V_1 , V_11 [ V_53 ] ) ;
}
int F_60 ( struct V_1 * V_1 )
{
int V_45 ;
struct V_41 * V_44 = F_40 ( V_1 ,
& V_14 ) ;
V_45 = V_14 . V_51 ( V_1 ,
V_14 . V_10 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_42 ( V_1 ,
V_44 ,
& V_14 ) ;
if ( V_45 < 0 )
return V_45 ;
V_44 -> V_8 ++ ;
return 0 ;
}
void F_61 ( struct V_1 * V_1 )
{
struct V_41 * V_44 = F_40 ( V_1 ,
& V_14 ) ;
V_44 -> V_8 -- ;
F_44 ( V_1 ,
V_44 ,
& V_14 ) ;
}
int F_62 ( void )
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < V_12 ; V_28 ++ )
F_32 ( V_37 [ V_28 ] ,
& V_18 ) ;
return 0 ;
}
void F_63 ( void )
{
unsigned int V_28 ;
for ( V_28 = 0 ; V_28 < F_46 ( V_13 ) ; V_28 ++ )
F_5 ( V_13 [ V_28 ] ) ;
}
