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
unsigned V_1 ,
unsigned int V_9 )
{
unsigned long V_10 ;
F_2 ( L_6 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_11 . V_12 ; V_10 ++ ) {
if ( V_1 == V_8 -> V_11 . V_13 [ V_10 ] . V_14 )
return V_8 -> V_11 . V_13 [ V_10 ] . V_15 ;
}
return V_8 -> V_11 . V_13 [ V_10 - 1 ] . V_15 ;
}
static unsigned int
F_7 (
struct V_7 * V_8 ,
unsigned int V_9 )
{
int V_16 = 0 ;
T_1 V_1 = 0 ;
T_3 V_17 ;
unsigned long V_18 ;
F_2 ( L_7 ) ;
V_17 = V_19 -> V_20 ;
F_8 ( V_19 , F_9 ( V_9 ) ) ;
if ( F_10 () != V_9 )
goto V_21;
V_16 = F_4 ( & V_1 ) ;
if ( V_16 ) {
F_8 ( V_19 , & V_17 ) ;
F_11 ( L_8 , V_16 ) ;
V_16 = 0 ;
goto V_21;
}
V_18 = F_6 ( V_8 , V_1 , V_9 ) ;
V_16 = ( V_18 * 1000 ) ;
V_21:
F_8 ( V_19 , & V_17 ) ;
return V_16 ;
}
static int
F_12 (
struct V_7 * V_8 ,
struct V_22 * V_23 ,
int V_24 )
{
int V_16 = 0 ;
T_1 V_1 = 0 ;
T_3 V_17 ;
int V_2 ;
F_2 ( L_9 ) ;
V_17 = V_19 -> V_20 ;
F_8 ( V_19 , F_9 ( V_23 -> V_9 ) ) ;
if ( F_10 () != V_23 -> V_9 ) {
V_2 = - V_25 ;
goto V_21;
}
if ( V_24 == V_8 -> V_11 . V_24 ) {
if ( F_13 ( V_8 -> V_26 ) ) {
F_2 ( L_10 , V_24 ) ;
V_8 -> V_26 = 0 ;
} else {
F_2 ( L_11 , V_24 ) ;
V_2 = 0 ;
goto V_21;
}
}
F_2 ( L_12 ,
V_8 -> V_11 . V_24 , V_24 ) ;
V_1 = ( T_1 ) V_8 -> V_11 . V_13 [ V_24 ] . V_27 ;
F_2 ( L_13 , V_1 ) ;
V_16 = F_1 ( V_1 ) ;
if ( V_16 ) {
F_11 ( L_14 , V_16 ) ;
V_2 = - V_4 ;
goto V_21;
}
V_8 -> V_11 . V_24 = V_24 ;
V_2 = 0 ;
V_21:
F_8 ( V_19 , & V_17 ) ;
return ( V_2 ) ;
}
static unsigned int
F_14 (
unsigned int V_9 )
{
struct V_7 * V_8 = V_28 [ V_9 ] ;
F_2 ( L_15 ) ;
return F_7 ( V_8 , V_9 ) ;
}
static int
F_15 (
struct V_22 * V_23 ,
unsigned int V_29 )
{
return F_12 ( V_28 [ V_23 -> V_9 ] , V_23 , V_29 ) ;
}
static int
F_16 (
struct V_22 * V_23 )
{
unsigned int V_10 ;
unsigned int V_9 = V_23 -> V_9 ;
struct V_7 * V_8 ;
unsigned int V_30 = 0 ;
struct V_31 * V_32 ;
F_2 ( L_16 ) ;
V_8 = F_17 ( sizeof( * V_8 ) , V_33 ) ;
if ( ! V_8 )
return ( - V_34 ) ;
V_28 [ V_9 ] = V_8 ;
V_30 = F_18 ( & V_8 -> V_11 , V_9 ) ;
if ( V_30 )
goto V_35;
if ( V_8 -> V_11 . V_12 <= 1 ) {
F_2 ( L_17 ) ;
V_30 = - V_4 ;
goto V_36;
}
if ( ( V_8 -> V_11 . V_37 . V_38 !=
V_39 ) ||
( V_8 -> V_11 . V_40 . V_38 !=
V_39 ) ) {
F_2 ( L_18 ,
( T_1 ) ( V_8 -> V_11 . V_37 . V_38 ) ,
( T_1 ) ( V_8 -> V_11 . V_40 . V_38 ) ) ;
V_30 = - V_4 ;
goto V_36;
}
V_32 = F_17 ( sizeof( * V_32 ) *
( V_8 -> V_11 . V_12 + 1 ) ,
V_33 ) ;
if ( ! V_32 ) {
V_30 = - V_34 ;
goto V_36;
}
V_23 -> V_41 . V_42 = 0 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_11 . V_12 ; V_10 ++ ) {
if ( ( V_8 -> V_11 . V_13 [ V_10 ] . V_42 * 1000 ) >
V_23 -> V_41 . V_42 ) {
V_23 -> V_41 . V_42 =
V_8 -> V_11 . V_13 [ V_10 ] . V_42 * 1000 ;
}
}
for ( V_10 = 0 ; V_10 <= V_8 -> V_11 . V_12 ; V_10 ++ )
{
if ( V_10 < V_8 -> V_11 . V_12 ) {
V_32 [ V_10 ] . V_43 =
V_8 -> V_11 . V_13 [ V_10 ] . V_15 * 1000 ;
} else {
V_32 [ V_10 ] . V_43 = V_44 ;
}
}
V_30 = F_19 ( V_23 , V_32 ) ;
if ( V_30 ) {
goto V_45;
}
F_20 ( V_46 ) ;
F_21 ( L_19 , V_9 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_11 . V_12 ; V_10 ++ )
F_2 ( L_20 ,
( V_10 == V_8 -> V_11 . V_24 ? '*' : ' ' ) , V_10 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_15 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_47 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_42 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_48 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_14 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_27 ) ;
V_8 -> V_26 = 1 ;
return ( V_30 ) ;
V_45:
F_22 ( V_32 ) ;
V_36:
F_23 ( V_9 ) ;
V_35:
F_22 ( V_8 ) ;
V_28 [ V_9 ] = NULL ;
return ( V_30 ) ;
}
static int
F_24 (
struct V_22 * V_23 )
{
struct V_7 * V_8 = V_28 [ V_23 -> V_9 ] ;
F_2 ( L_21 ) ;
if ( V_8 ) {
V_28 [ V_23 -> V_9 ] = NULL ;
F_23 ( V_23 -> V_9 ) ;
F_22 ( V_23 -> V_32 ) ;
F_22 ( V_8 ) ;
}
return ( 0 ) ;
}
static int T_4
F_25 ( void )
{
F_2 ( L_22 ) ;
return F_26 ( & V_49 ) ;
}
static void T_5
F_27 ( void )
{
F_2 ( L_23 ) ;
F_28 ( & V_49 ) ;
return;
}
