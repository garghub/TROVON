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
F_15 ( V_24 , F_16 ( V_23 ) ) ;
}
static void F_17 ( unsigned V_1 )
{
T_1 * V_23 = F_1 ( V_1 ) ;
F_18 ( V_24 , F_16 ( V_23 ) ) ;
}
static bool F_19 ( unsigned V_1 )
{
T_1 * V_23 = F_1 ( V_1 ) ;
return F_20 ( V_24 , F_16 ( V_23 ) ) ;
}
static bool F_21 ( unsigned V_1 )
{
T_1 * V_23 = F_1 ( V_1 ) ;
return F_22 ( V_9 , F_16 ( V_23 ) ) ;
}
static void F_23 ( unsigned V_1 )
{
T_1 * V_23 = F_1 ( V_1 ) ;
F_18 ( V_9 , F_16 ( V_23 ) ) ;
}
static void F_24 ( volatile T_1 * V_23 )
{
T_1 V_25 , V_26 , V_27 ;
V_27 = * V_23 ;
do {
V_26 = V_27 & ~ ( 1 << V_28 ) ;
V_25 = V_26 & ~ ( 1 << V_9 ) ;
V_27 = F_25 ( V_23 , V_26 , V_25 ) ;
} while ( V_27 != V_26 );
}
static void F_26 ( unsigned V_1 )
{
T_1 * V_23 = F_1 ( V_1 ) ;
F_27 ( ! F_28 () ) ;
F_24 ( V_23 ) ;
if ( F_20 ( V_24 , F_16 ( V_23 ) ) ) {
struct V_29 V_30 = { . V_1 = V_1 } ;
( void ) F_10 ( V_31 , & V_30 ) ;
}
}
static T_2 F_29 ( volatile T_1 * V_23 )
{
T_1 V_25 , V_26 , V_27 ;
V_27 = * V_23 ;
do {
V_26 = V_27 ;
V_25 = ( V_27 & ~ ( ( 1 << V_32 )
| V_33 ) ) ;
} while ( ( V_27 = F_25 ( V_23 , V_26 , V_25 ) ) != V_26 );
return V_27 & V_33 ;
}
static void F_30 ( unsigned V_1 )
{
int V_34 ;
struct V_35 * V_36 ;
V_34 = F_31 ( V_1 ) ;
if ( V_34 != - 1 ) {
V_36 = F_32 ( V_34 ) ;
if ( V_36 )
F_33 ( V_34 , V_36 ) ;
}
}
static void F_34 ( unsigned V_22 ,
struct V_37 * V_38 ,
unsigned V_39 , T_2 * V_40 )
{
struct V_41 * V_42 = & F_35 ( V_43 , V_22 ) ;
T_2 V_44 ;
unsigned V_1 ;
T_1 * V_23 ;
V_44 = V_42 -> V_44 [ V_39 ] ;
if ( V_44 == 0 ) {
F_36 () ;
V_44 = V_38 -> V_44 [ V_39 ] ;
}
V_1 = V_44 ;
V_23 = F_1 ( V_1 ) ;
V_44 = F_29 ( V_23 ) ;
if ( V_44 == 0 )
F_37 ( V_39 , F_16 ( V_40 ) ) ;
if ( F_20 ( V_24 , F_16 ( V_23 ) )
&& ! F_20 ( V_9 , F_16 ( V_23 ) ) )
F_30 ( V_1 ) ;
V_42 -> V_44 [ V_39 ] = V_44 ;
}
static void F_38 ( unsigned V_22 )
{
struct V_37 * V_38 ;
T_2 V_40 ;
unsigned V_42 ;
V_38 = F_35 ( V_45 , V_22 ) ;
V_40 = F_39 ( & V_38 -> V_40 , 0 ) ;
while ( V_40 ) {
V_42 = F_40 ( F_16 ( & V_40 ) , V_46 ) ;
F_34 ( V_22 , V_38 , V_42 , & V_40 ) ;
V_40 |= F_39 ( & V_38 -> V_40 , 0 ) ;
}
}
static void F_41 ( void )
{
unsigned V_22 ;
F_42 (cpu) {
void * V_38 = F_35 ( V_45 , V_22 ) ;
struct V_47 V_48 ;
int V_14 ;
if ( ! V_38 )
continue;
if ( ! F_43 ( V_22 ) ) {
F_5 ( ( unsigned long ) V_38 ) ;
F_35 ( V_45 , V_22 ) = NULL ;
continue;
}
V_48 . V_49 = F_9 ( V_38 ) ;
V_48 . V_50 = 0 ;
V_48 . V_51 = V_22 ;
V_14 = F_10 ( V_52 ,
& V_48 ) ;
if ( V_14 < 0 )
F_44 () ;
}
V_6 = 0 ;
}
static int F_45 ( unsigned V_22 )
{
struct V_53 * V_38 = NULL ;
struct V_47 V_48 ;
int V_14 = - V_19 ;
V_38 = F_46 ( V_18 | V_54 ) ;
if ( V_38 == NULL )
goto error;
V_48 . V_49 = F_9 ( F_47 ( V_38 ) ) ;
V_48 . V_50 = 0 ;
V_48 . V_51 = V_22 ;
V_14 = F_10 ( V_52 , & V_48 ) ;
if ( V_14 < 0 )
goto error;
F_35 ( V_45 , V_22 ) = F_47 ( V_38 ) ;
return 0 ;
error:
F_48 ( V_38 ) ;
return V_14 ;
}
static int F_49 ( struct V_55 * V_56 ,
unsigned long V_57 ,
void * V_58 )
{
int V_22 = ( long ) V_58 ;
int V_14 = 0 ;
switch ( V_57 ) {
case V_59 :
if ( ! F_35 ( V_45 , V_22 ) )
V_14 = F_45 ( V_22 ) ;
break;
default:
break;
}
return V_14 < 0 ? V_60 : V_61 ;
}
int T_3 F_50 ( void )
{
int V_22 = F_51 () ;
int V_14 ;
V_14 = F_45 ( V_22 ) ;
if ( V_14 < 0 )
goto V_62;
F_52 ( L_3 ) ;
V_63 = & V_64 ;
F_53 ( & V_65 ) ;
V_62:
F_54 () ;
return V_14 ;
}
