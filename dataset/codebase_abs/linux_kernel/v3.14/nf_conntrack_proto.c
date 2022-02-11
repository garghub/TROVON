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
static struct V_27 * F_24 ( struct V_1 * V_1 ,
struct V_15 * V_10 )
{
if ( V_10 -> V_10 == V_28 )
return & V_1 -> V_29 . V_30 ;
else
return NULL ;
}
static int F_25 ( struct V_1 * V_1 ,
struct V_15 * V_10 )
{
int V_31 = 0 ;
struct V_27 * V_32 = F_24 ( V_1 , V_10 ) ;
if ( V_32 == NULL )
return 0 ;
#if F_26 ( V_33 ) && F_26 ( V_34 )
if ( V_32 -> V_5 != NULL ) {
V_31 = F_1 ( V_1 ,
& V_32 -> V_2 ,
V_10 -> V_35 ,
V_32 -> V_5 ) ;
if ( V_31 < 0 ) {
F_5 ( V_32 -> V_5 ) ;
V_32 -> V_5 = NULL ;
}
}
#endif
return V_31 ;
}
static void F_27 ( struct V_1 * V_1 ,
struct V_15 * V_10 )
{
struct V_27 * V_32 = F_24 ( V_1 , V_10 ) ;
if ( V_32 == NULL )
return;
#if F_26 ( V_33 ) && F_26 ( V_34 )
if ( V_32 -> V_2 != NULL )
F_3 ( & V_32 -> V_2 ,
& V_32 -> V_5 ,
0 ) ;
#endif
}
int F_28 ( struct V_15 * V_36 )
{
int V_19 = 0 ;
struct V_15 * V_37 ;
if ( V_36 -> V_10 >= V_12 )
return - V_38 ;
if ( V_36 -> V_39 && ! V_36 -> V_40 )
return - V_41 ;
F_29 ( & V_42 ) ;
V_37 = F_30 ( V_43 [ V_36 -> V_10 ] ,
F_31 ( & V_42 ) ) ;
if ( V_37 != & V_18 ) {
V_19 = - V_38 ;
goto V_44;
}
if ( V_36 -> V_40 )
V_36 -> V_45 = 3 * V_36 -> V_40 () ;
F_32 ( V_43 [ V_36 -> V_10 ] , V_36 ) ;
V_44:
F_33 ( & V_42 ) ;
return V_19 ;
}
int F_34 ( struct V_1 * V_1 ,
struct V_15 * V_36 )
{
int V_19 = 0 ;
if ( V_36 -> V_46 ) {
V_19 = V_36 -> V_46 ( V_1 ) ;
if ( V_19 < 0 )
return V_19 ;
}
return F_25 ( V_1 , V_36 ) ;
}
void F_35 ( struct V_15 * V_36 )
{
F_36 ( V_36 -> V_10 >= V_12 ) ;
F_29 ( & V_42 ) ;
F_36 ( F_30 ( V_43 [ V_36 -> V_10 ] ,
F_31 ( & V_42 )
) != V_36 ) ;
F_32 ( V_43 [ V_36 -> V_10 ] ,
& V_18 ) ;
F_33 ( & V_42 ) ;
F_37 () ;
}
void F_38 ( struct V_1 * V_1 ,
struct V_15 * V_36 )
{
F_27 ( V_1 , V_36 ) ;
F_39 ( V_1 , F_20 , V_36 , 0 , 0 ) ;
}
static struct V_47 * F_40 ( struct V_1 * V_1 ,
struct V_9 * V_11 )
{
if ( V_11 -> V_48 ) {
return V_11 -> V_48 ( V_1 ) ;
} else if ( V_11 -> V_49 ) {
return F_41 ( V_1 , * V_11 -> V_49 ) ;
}
return NULL ;
}
static
int F_42 ( struct V_1 * V_1 ,
struct V_47 * V_50 ,
struct V_9 * V_11 )
{
int V_31 = 0 ;
#ifdef V_33
if ( V_50 -> V_5 != NULL ) {
V_31 = F_1 ( V_1 ,
& V_50 -> V_2 ,
L_2 ,
V_50 -> V_5 ) ;
if ( V_31 < 0 ) {
if ( ! V_50 -> V_8 ) {
F_5 ( V_50 -> V_5 ) ;
V_50 -> V_5 = NULL ;
}
}
}
#ifdef V_34
if ( V_11 -> V_10 != V_51 && V_50 -> V_52 != NULL ) {
if ( V_31 < 0 ) {
F_43 ( V_50 ) ;
goto V_53;
}
V_31 = F_1 ( V_1 ,
& V_50 -> V_54 ,
L_3 ,
V_50 -> V_52 ) ;
if ( V_31 == 0 )
goto V_53;
F_43 ( V_50 ) ;
F_3 ( & V_50 -> V_2 ,
& V_50 -> V_5 ,
V_50 -> V_8 ) ;
}
V_53:
#endif
#endif
return V_31 ;
}
static
void F_44 ( struct V_1 * V_1 ,
struct V_47 * V_50 ,
struct V_9 * V_11 )
{
#ifdef V_33
if ( V_50 -> V_2 != NULL )
F_3 ( & V_50 -> V_2 ,
& V_50 -> V_5 ,
V_50 -> V_8 ) ;
#ifdef V_34
if ( V_11 -> V_10 != V_51 && V_50 -> V_54 != NULL )
F_3 ( & V_50 -> V_54 ,
& V_50 -> V_52 ,
0 ) ;
#endif
#endif
}
int F_45 ( struct V_9 * V_11 )
{
int V_19 = 0 ;
if ( V_11 -> V_10 >= V_55 )
return - V_38 ;
if ( ( V_11 -> V_56 && ! V_11 -> V_57 )
|| ( V_11 -> V_39 && ! V_11 -> V_40 ) )
return - V_41 ;
F_29 ( & V_42 ) ;
if ( ! V_13 [ V_11 -> V_10 ] ) {
struct V_9 T_3 * * V_58 ;
int V_25 ;
V_58 = F_46 ( V_59 *
sizeof( struct V_9 * ) ,
V_60 ) ;
if ( V_58 == NULL ) {
V_19 = - V_7 ;
goto V_44;
}
for ( V_25 = 0 ; V_25 < V_59 ; V_25 ++ )
F_47 ( V_58 [ V_25 ] , & V_14 ) ;
F_48 () ;
V_13 [ V_11 -> V_10 ] = V_58 ;
} else if ( F_30 (
V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
F_31 ( & V_42 )
) != & V_14 ) {
V_19 = - V_38 ;
goto V_44;
}
V_11 -> V_45 = 0 ;
if ( V_11 -> V_57 )
V_11 -> V_45 += V_11 -> V_57 () ;
if ( V_11 -> V_40 )
V_11 -> V_45 += 3 * V_11 -> V_40 () ;
F_32 ( V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
V_11 ) ;
V_44:
F_33 ( & V_42 ) ;
return V_19 ;
}
int F_49 ( struct V_1 * V_1 ,
struct V_9 * V_11 )
{
int V_19 = 0 ;
struct V_47 * V_50 = NULL ;
if ( V_11 -> V_46 ) {
V_19 = V_11 -> V_46 ( V_1 , V_11 -> V_10 ) ;
if ( V_19 < 0 )
goto V_53;
}
V_50 = F_40 ( V_1 , V_11 ) ;
if ( V_50 == NULL )
goto V_53;
V_19 = F_42 ( V_1 , V_50 , V_11 ) ;
if ( V_19 < 0 )
goto V_53;
V_50 -> V_8 ++ ;
V_53:
return V_19 ;
}
void F_50 ( struct V_9 * V_11 )
{
F_36 ( V_11 -> V_10 >= V_55 ) ;
F_29 ( & V_42 ) ;
F_36 ( F_30 (
V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
F_31 ( & V_42 )
) != V_11 ) ;
F_32 ( V_13 [ V_11 -> V_10 ] [ V_11 -> V_11 ] ,
& V_14 ) ;
F_33 ( & V_42 ) ;
F_37 () ;
}
void F_51 ( struct V_1 * V_1 ,
struct V_9 * V_11 )
{
struct V_47 * V_50 = NULL ;
V_50 = F_40 ( V_1 , V_11 ) ;
if ( V_50 == NULL )
return;
V_50 -> V_8 -- ;
F_44 ( V_1 , V_50 , V_11 ) ;
F_39 ( V_1 , F_22 , V_11 , 0 , 0 ) ;
}
int F_52 ( struct V_1 * V_1 )
{
int V_31 ;
struct V_47 * V_50 = F_40 ( V_1 ,
& V_14 ) ;
V_31 = V_14 . V_46 ( V_1 ,
V_14 . V_10 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_42 ( V_1 ,
V_50 ,
& V_14 ) ;
if ( V_31 < 0 )
return V_31 ;
V_50 -> V_8 ++ ;
return 0 ;
}
void F_53 ( struct V_1 * V_1 )
{
struct V_47 * V_50 = F_40 ( V_1 ,
& V_14 ) ;
V_50 -> V_8 -- ;
F_44 ( V_1 ,
V_50 ,
& V_14 ) ;
}
int F_54 ( void )
{
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_12 ; V_25 ++ )
F_32 ( V_43 [ V_25 ] ,
& V_18 ) ;
return 0 ;
}
void F_55 ( void )
{
unsigned int V_25 ;
for ( V_25 = 0 ; V_25 < V_55 ; V_25 ++ )
F_5 ( V_13 [ V_25 ] ) ;
}
