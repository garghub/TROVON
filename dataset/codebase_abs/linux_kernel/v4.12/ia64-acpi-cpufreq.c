static int
F_1 (
T_1 V_1 )
{
T_2 V_2 ;
F_2 ( L_1 ) ;
V_2 = F_3 ( ( V_3 ) V_1 ) ;
if ( V_2 ) {
F_2 ( L_2 ,
V_1 , V_2 ) ;
return - V_4 ;
}
return ( int ) V_2 ;
}
static int
F_4 (
T_1 * V_1 )
{
V_3 V_5 = 0 ;
T_2 V_2 ;
F_2 ( L_3 ) ;
V_2 = F_5 ( & V_5 ,
V_6 ) ;
* V_1 = ( T_1 ) V_5 ;
if ( V_2 )
F_2 ( L_4
L_5 , V_2 , * V_1 ) ;
return ( int ) V_2 ;
}
static unsigned
F_6 (
struct V_7 * V_8 ,
unsigned V_1 )
{
unsigned long V_9 ;
F_2 ( L_6 ) ;
for ( V_9 = 0 ; V_9 < V_8 -> V_10 . V_11 ; V_9 ++ ) {
if ( V_1 == V_8 -> V_10 . V_12 [ V_9 ] . V_13 )
return V_8 -> V_10 . V_12 [ V_9 ] . V_14 ;
}
return V_8 -> V_10 . V_12 [ V_9 - 1 ] . V_14 ;
}
static long
F_7 (
void * V_15 )
{
struct V_16 * V_17 = V_15 ;
unsigned int V_18 = V_17 -> V_18 ;
struct V_7 * V_8 = V_19 [ V_18 ] ;
T_1 V_1 ;
int V_20 ;
F_2 ( L_7 ) ;
if ( F_8 () != V_18 )
return - V_21 ;
V_20 = F_4 ( & V_1 ) ;
if ( V_20 ) {
F_9 ( L_8 , V_20 ) ;
return V_20 ;
}
return 1000 * F_6 ( V_8 , V_1 ) ;
}
static long
F_10 (
void * V_15 )
{
struct V_16 * V_17 = V_15 ;
unsigned int V_18 = V_17 -> V_18 ;
struct V_7 * V_8 = V_19 [ V_18 ] ;
int V_20 , V_22 = V_17 -> V_22 ;
T_1 V_1 ;
F_2 ( L_9 ) ;
if ( F_8 () != V_18 )
return - V_21 ;
if ( V_22 == V_8 -> V_10 . V_22 ) {
if ( F_11 ( V_8 -> V_23 ) ) {
F_2 ( L_10 , V_22 ) ;
V_8 -> V_23 = 0 ;
} else {
F_2 ( L_11 , V_22 ) ;
return 0 ;
}
}
F_2 ( L_12 ,
V_8 -> V_10 . V_22 , V_22 ) ;
V_1 = ( T_1 ) V_8 -> V_10 . V_12 [ V_22 ] . V_24 ;
F_2 ( L_13 , V_1 ) ;
V_20 = F_1 ( V_1 ) ;
if ( V_20 ) {
F_9 ( L_14 , V_20 ) ;
return - V_4 ;
}
V_8 -> V_10 . V_22 = V_22 ;
return 0 ;
}
static unsigned int
F_12 (
unsigned int V_18 )
{
struct V_16 V_17 ;
long V_20 ;
V_17 . V_18 = V_18 ;
V_20 = F_13 ( V_18 , F_7 , & V_17 ) ;
return V_20 > 0 ? ( unsigned int ) V_20 : 0 ;
}
static int
F_14 (
struct V_25 * V_26 ,
unsigned int V_27 )
{
struct V_16 V_17 ;
V_17 . V_18 = V_26 -> V_18 ;
V_17 . V_22 = V_27 ;
return F_13 ( V_17 . V_18 , F_10 , & V_17 ) ;
}
static int
F_15 (
struct V_25 * V_26 )
{
unsigned int V_9 ;
unsigned int V_18 = V_26 -> V_18 ;
struct V_7 * V_8 ;
unsigned int V_28 = 0 ;
struct V_29 * V_30 ;
F_2 ( L_15 ) ;
V_8 = F_16 ( sizeof( * V_8 ) , V_31 ) ;
if ( ! V_8 )
return ( - V_32 ) ;
V_19 [ V_18 ] = V_8 ;
V_28 = F_17 ( & V_8 -> V_10 , V_18 ) ;
if ( V_28 )
goto V_33;
if ( V_8 -> V_10 . V_11 <= 1 ) {
F_2 ( L_16 ) ;
V_28 = - V_4 ;
goto V_34;
}
if ( ( V_8 -> V_10 . V_35 . V_36 !=
V_37 ) ||
( V_8 -> V_10 . V_38 . V_36 !=
V_37 ) ) {
F_2 ( L_17 ,
( T_1 ) ( V_8 -> V_10 . V_35 . V_36 ) ,
( T_1 ) ( V_8 -> V_10 . V_38 . V_36 ) ) ;
V_28 = - V_4 ;
goto V_34;
}
V_30 = F_16 ( sizeof( * V_30 ) *
( V_8 -> V_10 . V_11 + 1 ) ,
V_31 ) ;
if ( ! V_30 ) {
V_28 = - V_32 ;
goto V_34;
}
V_26 -> V_39 . V_40 = 0 ;
for ( V_9 = 0 ; V_9 < V_8 -> V_10 . V_11 ; V_9 ++ ) {
if ( ( V_8 -> V_10 . V_12 [ V_9 ] . V_40 * 1000 ) >
V_26 -> V_39 . V_40 ) {
V_26 -> V_39 . V_40 =
V_8 -> V_10 . V_12 [ V_9 ] . V_40 * 1000 ;
}
}
for ( V_9 = 0 ; V_9 <= V_8 -> V_10 . V_11 ; V_9 ++ )
{
if ( V_9 < V_8 -> V_10 . V_11 ) {
V_30 [ V_9 ] . V_41 =
V_8 -> V_10 . V_12 [ V_9 ] . V_14 * 1000 ;
} else {
V_30 [ V_9 ] . V_41 = V_42 ;
}
}
V_28 = F_18 ( V_26 , V_30 ) ;
if ( V_28 ) {
goto V_43;
}
F_19 ( V_44 ) ;
F_20 ( L_18 , V_18 ) ;
for ( V_9 = 0 ; V_9 < V_8 -> V_10 . V_11 ; V_9 ++ )
F_2 ( L_19 ,
( V_9 == V_8 -> V_10 . V_22 ? '*' : ' ' ) , V_9 ,
( T_1 ) V_8 -> V_10 . V_12 [ V_9 ] . V_14 ,
( T_1 ) V_8 -> V_10 . V_12 [ V_9 ] . V_45 ,
( T_1 ) V_8 -> V_10 . V_12 [ V_9 ] . V_40 ,
( T_1 ) V_8 -> V_10 . V_12 [ V_9 ] . V_46 ,
( T_1 ) V_8 -> V_10 . V_12 [ V_9 ] . V_13 ,
( T_1 ) V_8 -> V_10 . V_12 [ V_9 ] . V_24 ) ;
V_8 -> V_23 = 1 ;
return ( V_28 ) ;
V_43:
F_21 ( V_30 ) ;
V_34:
F_22 ( V_18 ) ;
V_33:
F_21 ( V_8 ) ;
V_19 [ V_18 ] = NULL ;
return ( V_28 ) ;
}
static int
F_23 (
struct V_25 * V_26 )
{
struct V_7 * V_8 = V_19 [ V_26 -> V_18 ] ;
F_2 ( L_20 ) ;
if ( V_8 ) {
V_19 [ V_26 -> V_18 ] = NULL ;
F_22 ( V_26 -> V_18 ) ;
F_21 ( V_26 -> V_30 ) ;
F_21 ( V_8 ) ;
}
return ( 0 ) ;
}
static int T_3
F_24 ( void )
{
F_2 ( L_21 ) ;
return F_25 ( & V_47 ) ;
}
static void T_4
F_26 ( void )
{
F_2 ( L_22 ) ;
F_27 ( & V_47 ) ;
return;
}
