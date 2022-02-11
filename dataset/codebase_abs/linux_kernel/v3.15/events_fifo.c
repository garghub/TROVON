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
static void F_4 ( void )
{
unsigned V_2 ;
for ( V_2 = V_6 ; V_2 < V_7 ; V_2 ++ ) {
if ( ! V_4 [ V_2 ] )
break;
F_5 ( ( unsigned long ) V_4 [ V_2 ] ) ;
V_4 [ V_2 ] = NULL ;
}
}
static void F_6 ( T_1 * V_8 )
{
unsigned V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
V_8 [ V_2 ] = 1 << V_9 ;
}
static int F_7 ( struct V_10 * V_11 )
{
unsigned V_1 = V_11 -> V_12 ;
unsigned V_13 ;
int V_14 ;
V_13 = V_1 / V_3 + 1 ;
if ( V_13 > V_7 )
return - V_15 ;
while ( V_6 < V_13 ) {
void * V_8 ;
struct V_16 V_17 ;
V_8 = V_4 [ V_6 ] ;
if ( ! V_8 ) {
V_8 = ( void * ) F_8 ( V_18 ) ;
if ( V_8 == NULL ) {
V_14 = - V_19 ;
goto error;
}
V_4 [ V_6 ] = V_8 ;
}
F_6 ( V_8 ) ;
V_17 . V_20 = F_9 ( V_8 ) ;
V_14 = F_10 ( V_21 , & V_17 ) ;
if ( V_14 < 0 )
goto error;
V_6 ++ ;
}
return 0 ;
error:
if ( V_6 == 0 )
F_11 ( L_1 , V_14 ) ;
else
F_12 ( L_2 , V_14 ) ;
F_4 () ;
return V_14 ;
}
static void F_13 ( struct V_10 * V_11 , unsigned V_22 )
{
}
static void F_14 ( unsigned V_1 )
{
T_1 * V_23 = F_1 ( V_1 ) ;
F_15 ( F_16 ( V_24 , V_23 ) , F_17 ( V_23 ) ) ;
}
static void F_18 ( unsigned V_1 )
{
T_1 * V_23 = F_1 ( V_1 ) ;
F_19 ( F_16 ( V_24 , V_23 ) , F_17 ( V_23 ) ) ;
}
static bool F_20 ( unsigned V_1 )
{
T_1 * V_23 = F_1 ( V_1 ) ;
return F_21 ( F_16 ( V_24 , V_23 ) , F_17 ( V_23 ) ) ;
}
static bool F_22 ( unsigned V_1 )
{
T_1 * V_23 = F_1 ( V_1 ) ;
return F_23 ( F_16 ( V_25 , V_23 ) , F_17 ( V_23 ) ) ;
}
static void F_24 ( unsigned V_1 )
{
T_1 * V_23 = F_1 ( V_1 ) ;
F_19 ( F_16 ( V_25 , V_23 ) , F_17 ( V_23 ) ) ;
}
static bool F_25 ( unsigned V_1 )
{
T_1 * V_23 = F_1 ( V_1 ) ;
return F_21 ( F_16 ( V_25 , V_23 ) , F_17 ( V_23 ) ) ;
}
static void F_26 ( volatile T_1 * V_23 )
{
T_1 V_26 , V_27 , V_28 ;
V_28 = * V_23 ;
do {
V_27 = V_28 & ~ ( 1 << V_29 ) ;
V_26 = V_27 & ~ ( 1 << V_9 ) ;
V_28 = F_27 ( V_23 , V_27 , V_26 ) ;
} while ( V_28 != V_27 );
}
static void F_28 ( unsigned V_1 )
{
T_1 * V_23 = F_1 ( V_1 ) ;
F_29 ( ! F_30 () ) ;
F_26 ( V_23 ) ;
if ( F_20 ( V_1 ) ) {
struct V_30 V_31 = { . V_1 = V_1 } ;
( void ) F_10 ( V_32 , & V_31 ) ;
}
}
static T_2 F_31 ( volatile T_1 * V_23 )
{
T_1 V_26 , V_27 , V_28 ;
V_28 = * V_23 ;
do {
V_27 = V_28 ;
V_26 = ( V_28 & ~ ( ( 1 << V_33 )
| V_34 ) ) ;
} while ( ( V_28 = F_27 ( V_23 , V_27 , V_26 ) ) != V_27 );
return V_28 & V_34 ;
}
static void F_32 ( unsigned V_1 )
{
int V_35 ;
V_35 = F_33 ( V_1 ) ;
if ( V_35 != - 1 )
F_34 ( V_35 ) ;
}
static void F_35 ( unsigned V_22 ,
struct V_36 * V_37 ,
unsigned V_38 , unsigned long * V_39 )
{
struct V_40 * V_41 = & F_36 ( V_42 , V_22 ) ;
T_2 V_43 ;
unsigned V_1 ;
T_1 * V_23 ;
V_43 = V_41 -> V_43 [ V_38 ] ;
if ( V_43 == 0 ) {
F_37 () ;
V_43 = V_37 -> V_43 [ V_38 ] ;
}
V_1 = V_43 ;
V_23 = F_1 ( V_1 ) ;
V_43 = F_31 ( V_23 ) ;
if ( V_43 == 0 )
F_38 ( V_38 , V_39 ) ;
if ( F_20 ( V_1 ) && ! F_25 ( V_1 ) )
F_32 ( V_1 ) ;
V_41 -> V_43 [ V_38 ] = V_43 ;
}
static void F_39 ( unsigned V_22 )
{
struct V_36 * V_37 ;
unsigned long V_39 ;
unsigned V_41 ;
V_37 = F_36 ( V_44 , V_22 ) ;
V_39 = F_40 ( & V_37 -> V_39 , 0 ) ;
while ( V_39 ) {
V_41 = F_41 ( F_17 ( & V_39 ) , V_45 ) ;
F_35 ( V_22 , V_37 , V_41 , & V_39 ) ;
V_39 |= F_40 ( & V_37 -> V_39 , 0 ) ;
}
}
static void F_42 ( void )
{
unsigned V_22 ;
F_43 (cpu) {
void * V_37 = F_36 ( V_44 , V_22 ) ;
struct V_46 V_47 ;
int V_14 ;
if ( ! V_37 )
continue;
if ( ! F_44 ( V_22 ) ) {
F_5 ( ( unsigned long ) V_37 ) ;
F_36 ( V_44 , V_22 ) = NULL ;
continue;
}
V_47 . V_48 = F_9 ( V_37 ) ;
V_47 . V_49 = 0 ;
V_47 . V_50 = V_22 ;
V_14 = F_10 ( V_51 ,
& V_47 ) ;
if ( V_14 < 0 )
F_45 () ;
}
V_6 = 0 ;
}
static int F_46 ( unsigned V_22 )
{
struct V_52 * V_37 = NULL ;
struct V_46 V_47 ;
int V_14 = - V_19 ;
V_37 = F_47 ( V_18 | V_53 ) ;
if ( V_37 == NULL )
goto error;
V_47 . V_48 = F_9 ( F_48 ( V_37 ) ) ;
V_47 . V_49 = 0 ;
V_47 . V_50 = V_22 ;
V_14 = F_10 ( V_51 , & V_47 ) ;
if ( V_14 < 0 )
goto error;
F_36 ( V_44 , V_22 ) = F_48 ( V_37 ) ;
return 0 ;
error:
F_49 ( V_37 ) ;
return V_14 ;
}
static int F_50 ( struct V_54 * V_55 ,
unsigned long V_56 ,
void * V_57 )
{
int V_22 = ( long ) V_57 ;
int V_14 = 0 ;
switch ( V_56 ) {
case V_58 :
if ( ! F_36 ( V_44 , V_22 ) )
V_14 = F_46 ( V_22 ) ;
break;
default:
break;
}
return V_14 < 0 ? V_59 : V_60 ;
}
int T_3 F_51 ( void )
{
int V_22 = F_52 () ;
int V_14 ;
V_14 = F_46 ( V_22 ) ;
if ( V_14 < 0 )
goto V_61;
F_53 ( L_3 ) ;
V_62 = & V_63 ;
F_54 ( & V_64 ) ;
V_61:
F_55 () ;
return V_14 ;
}
