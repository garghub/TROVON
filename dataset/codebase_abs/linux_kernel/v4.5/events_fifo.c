static inline T_1 * F_1 ( unsigned V_1 )
{
unsigned V_2 = V_1 / V_3 ;
return V_4 [ V_2 ] + V_1 % V_3 ;
}
static unsigned F_2 ( void )
{
return V_5 ;
}
static unsigned F_3 ( void )
{
return V_6 * V_3 ;
}
static int F_4 ( int V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = & F_5 ( V_12 , V_7 ) ;
struct V_13 V_14 ;
unsigned int V_2 ;
F_6 ( V_9 ) ;
for ( V_2 = 0 ; V_2 < V_15 ; V_2 ++ )
V_11 -> V_16 [ V_2 ] = 0 ;
V_14 . V_17 = F_7 ( V_9 ) ;
V_14 . V_18 = 0 ;
V_14 . V_19 = V_7 ;
return F_8 ( V_20 , & V_14 ) ;
}
static void F_9 ( void )
{
unsigned V_2 ;
for ( V_2 = V_6 ; V_2 < V_21 ; V_2 ++ ) {
if ( ! V_4 [ V_2 ] )
break;
F_10 ( ( unsigned long ) V_4 [ V_2 ] ) ;
V_4 [ V_2 ] = NULL ;
}
}
static void F_11 ( T_1 * V_22 )
{
unsigned V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
V_22 [ V_2 ] = 1 << V_23 ;
}
static int F_12 ( struct V_24 * V_25 )
{
unsigned V_1 = V_25 -> V_26 ;
unsigned V_27 ;
int V_28 ;
V_27 = V_1 / V_3 + 1 ;
if ( V_27 > V_21 )
return - V_29 ;
while ( V_6 < V_27 ) {
void * V_22 ;
struct V_30 V_31 ;
V_22 = V_4 [ V_6 ] ;
if ( ! V_22 ) {
V_22 = ( void * ) F_13 ( V_32 ) ;
if ( V_22 == NULL ) {
V_28 = - V_33 ;
goto error;
}
V_4 [ V_6 ] = V_22 ;
}
F_11 ( V_22 ) ;
V_31 . V_34 = F_7 ( V_22 ) ;
V_28 = F_8 ( V_35 , & V_31 ) ;
if ( V_28 < 0 )
goto error;
V_6 ++ ;
}
return 0 ;
error:
if ( V_6 == 0 )
F_14 ( L_1 , V_28 ) ;
else
F_15 ( L_2 , V_28 ) ;
F_9 () ;
return V_28 ;
}
static void F_16 ( struct V_24 * V_25 , unsigned V_7 )
{
}
static void F_17 ( unsigned V_1 )
{
T_1 * V_36 = F_1 ( V_1 ) ;
F_18 ( F_19 ( V_37 , V_36 ) , F_20 ( V_36 ) ) ;
}
static void F_21 ( unsigned V_1 )
{
T_1 * V_36 = F_1 ( V_1 ) ;
F_22 ( F_19 ( V_37 , V_36 ) , F_20 ( V_36 ) ) ;
}
static bool F_23 ( unsigned V_1 )
{
T_1 * V_36 = F_1 ( V_1 ) ;
return F_24 ( F_19 ( V_37 , V_36 ) , F_20 ( V_36 ) ) ;
}
static bool F_25 ( unsigned V_1 )
{
T_1 * V_36 = F_1 ( V_1 ) ;
return F_26 ( F_19 ( V_38 , V_36 ) , F_20 ( V_36 ) ) ;
}
static void F_27 ( unsigned V_1 )
{
T_1 * V_36 = F_1 ( V_1 ) ;
F_22 ( F_19 ( V_38 , V_36 ) , F_20 ( V_36 ) ) ;
}
static bool F_28 ( unsigned V_1 )
{
T_1 * V_36 = F_1 ( V_1 ) ;
return F_24 ( F_19 ( V_38 , V_36 ) , F_20 ( V_36 ) ) ;
}
static void F_29 ( volatile T_1 * V_36 )
{
T_1 V_39 , V_40 , V_41 ;
V_41 = * V_36 ;
do {
V_40 = V_41 & ~ ( 1 << V_42 ) ;
V_39 = V_40 & ~ ( 1 << V_23 ) ;
V_41 = F_30 ( V_36 , V_40 , V_39 ) ;
} while ( V_41 != V_40 );
}
static void F_31 ( unsigned V_1 )
{
T_1 * V_36 = F_1 ( V_1 ) ;
F_32 ( ! F_33 () ) ;
F_29 ( V_36 ) ;
if ( F_23 ( V_1 ) ) {
struct V_43 V_44 = { . V_1 = V_1 } ;
( void ) F_8 ( V_45 , & V_44 ) ;
}
}
static T_2 F_34 ( volatile T_1 * V_36 )
{
T_1 V_39 , V_40 , V_41 ;
V_41 = * V_36 ;
do {
V_40 = V_41 ;
V_39 = ( V_41 & ~ ( ( 1 << V_46 )
| V_47 ) ) ;
} while ( ( V_41 = F_30 ( V_36 , V_40 , V_39 ) ) != V_40 );
return V_41 & V_47 ;
}
static void F_35 ( unsigned V_1 )
{
int V_48 ;
V_48 = F_36 ( V_1 ) ;
if ( V_48 != - 1 )
F_37 ( V_48 ) ;
}
static void F_38 ( unsigned V_7 ,
struct V_8 * V_9 ,
unsigned V_49 , unsigned long * V_50 ,
bool V_51 )
{
struct V_10 * V_11 = & F_5 ( V_12 , V_7 ) ;
T_2 V_16 ;
unsigned V_1 ;
T_1 * V_36 ;
V_16 = V_11 -> V_16 [ V_49 ] ;
if ( V_16 == 0 ) {
F_39 () ;
V_16 = V_9 -> V_16 [ V_49 ] ;
}
V_1 = V_16 ;
V_36 = F_1 ( V_1 ) ;
V_16 = F_34 ( V_36 ) ;
if ( V_16 == 0 )
F_40 ( V_49 , V_50 ) ;
if ( F_23 ( V_1 ) && ! F_28 ( V_1 ) ) {
if ( F_41 ( V_51 ) )
F_42 ( L_3 , V_1 ) ;
else
F_35 ( V_1 ) ;
}
V_11 -> V_16 [ V_49 ] = V_16 ;
}
static void F_43 ( unsigned V_7 , bool V_51 )
{
struct V_8 * V_9 ;
unsigned long V_50 ;
unsigned V_11 ;
V_9 = F_5 ( V_52 , V_7 ) ;
V_50 = F_44 ( & V_9 -> V_50 , 0 ) ;
while ( V_50 ) {
V_11 = F_45 ( & V_50 , V_15 ) ;
F_38 ( V_7 , V_9 , V_11 , & V_50 , V_51 ) ;
V_50 |= F_44 ( & V_9 -> V_50 , 0 ) ;
}
}
static void F_46 ( unsigned V_7 )
{
F_43 ( V_7 , false ) ;
}
static void F_47 ( void )
{
unsigned V_7 ;
F_48 (cpu) {
void * V_9 = F_5 ( V_52 , V_7 ) ;
int V_28 ;
if ( ! V_9 )
continue;
if ( ! F_49 ( V_7 ) ) {
F_10 ( ( unsigned long ) V_9 ) ;
F_5 ( V_52 , V_7 ) = NULL ;
continue;
}
V_28 = F_4 ( V_7 , V_9 ) ;
if ( V_28 < 0 )
F_50 () ;
}
V_6 = 0 ;
}
static int F_51 ( unsigned V_7 )
{
void * V_9 = NULL ;
int V_28 = - V_33 ;
V_9 = ( void * ) F_13 ( V_32 ) ;
if ( V_9 == NULL )
goto error;
V_28 = F_4 ( V_7 , V_9 ) ;
if ( V_28 < 0 )
goto error;
F_5 ( V_52 , V_7 ) = V_9 ;
return 0 ;
error:
F_10 ( ( unsigned long ) V_9 ) ;
return V_28 ;
}
static int F_52 ( struct V_53 * V_54 ,
unsigned long V_55 ,
void * V_56 )
{
int V_7 = ( long ) V_56 ;
int V_28 = 0 ;
switch ( V_55 ) {
case V_57 :
if ( ! F_5 ( V_52 , V_7 ) )
V_28 = F_51 ( V_7 ) ;
break;
case V_58 :
F_43 ( V_7 , true ) ;
break;
default:
break;
}
return V_28 < 0 ? V_59 : V_60 ;
}
int T_3 F_53 ( void )
{
int V_7 = F_54 () ;
int V_28 ;
V_28 = F_51 ( V_7 ) ;
if ( V_28 < 0 )
goto V_61;
F_55 ( L_4 ) ;
V_62 = & V_63 ;
F_56 ( & V_64 ) ;
V_61:
F_57 () ;
return V_28 ;
}
