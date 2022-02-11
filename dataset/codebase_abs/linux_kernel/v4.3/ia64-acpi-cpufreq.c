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
F_11 ( V_22 L_8 ,
V_16 ) ;
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
struct V_23 * V_24 ,
int V_25 )
{
int V_16 = 0 ;
T_1 V_1 = 0 ;
T_3 V_17 ;
int V_2 ;
F_2 ( L_9 ) ;
V_17 = V_19 -> V_20 ;
F_8 ( V_19 , F_9 ( V_24 -> V_9 ) ) ;
if ( F_10 () != V_24 -> V_9 ) {
V_2 = - V_26 ;
goto V_21;
}
if ( V_25 == V_8 -> V_11 . V_25 ) {
if ( F_13 ( V_8 -> V_27 ) ) {
F_2 ( L_10 , V_25 ) ;
V_8 -> V_27 = 0 ;
} else {
F_2 ( L_11 , V_25 ) ;
V_2 = 0 ;
goto V_21;
}
}
F_2 ( L_12 ,
V_8 -> V_11 . V_25 , V_25 ) ;
V_1 = ( T_1 ) V_8 -> V_11 . V_13 [ V_25 ] . V_28 ;
F_2 ( L_13 , V_1 ) ;
V_16 = F_1 ( V_1 ) ;
if ( V_16 ) {
F_11 ( V_22 L_14 , V_16 ) ;
V_2 = - V_4 ;
goto V_21;
}
V_8 -> V_11 . V_25 = V_25 ;
V_2 = 0 ;
V_21:
F_8 ( V_19 , & V_17 ) ;
return ( V_2 ) ;
}
static unsigned int
F_14 (
unsigned int V_9 )
{
struct V_7 * V_8 = V_29 [ V_9 ] ;
F_2 ( L_15 ) ;
return F_7 ( V_8 , V_9 ) ;
}
static int
F_15 (
struct V_23 * V_24 ,
unsigned int V_30 )
{
return F_12 ( V_29 [ V_24 -> V_9 ] , V_24 , V_30 ) ;
}
static int
F_16 (
struct V_23 * V_24 )
{
unsigned int V_10 ;
unsigned int V_9 = V_24 -> V_9 ;
struct V_7 * V_8 ;
unsigned int V_31 = 0 ;
struct V_32 * V_33 ;
F_2 ( L_16 ) ;
V_8 = F_17 ( sizeof( * V_8 ) , V_34 ) ;
if ( ! V_8 )
return ( - V_35 ) ;
V_29 [ V_9 ] = V_8 ;
V_31 = F_18 ( & V_8 -> V_11 , V_9 ) ;
if ( V_31 )
goto V_36;
if ( V_8 -> V_11 . V_12 <= 1 ) {
F_2 ( L_17 ) ;
V_31 = - V_4 ;
goto V_37;
}
if ( ( V_8 -> V_11 . V_38 . V_39 !=
V_40 ) ||
( V_8 -> V_11 . V_41 . V_39 !=
V_40 ) ) {
F_2 ( L_18 ,
( T_1 ) ( V_8 -> V_11 . V_38 . V_39 ) ,
( T_1 ) ( V_8 -> V_11 . V_41 . V_39 ) ) ;
V_31 = - V_4 ;
goto V_37;
}
V_33 = F_17 ( sizeof( * V_33 ) *
( V_8 -> V_11 . V_12 + 1 ) ,
V_34 ) ;
if ( ! V_33 ) {
V_31 = - V_35 ;
goto V_37;
}
V_24 -> V_42 . V_43 = 0 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_11 . V_12 ; V_10 ++ ) {
if ( ( V_8 -> V_11 . V_13 [ V_10 ] . V_43 * 1000 ) >
V_24 -> V_42 . V_43 ) {
V_24 -> V_42 . V_43 =
V_8 -> V_11 . V_13 [ V_10 ] . V_43 * 1000 ;
}
}
for ( V_10 = 0 ; V_10 <= V_8 -> V_11 . V_12 ; V_10 ++ )
{
if ( V_10 < V_8 -> V_11 . V_12 ) {
V_33 [ V_10 ] . V_44 =
V_8 -> V_11 . V_13 [ V_10 ] . V_15 * 1000 ;
} else {
V_33 [ V_10 ] . V_44 = V_45 ;
}
}
V_31 = F_19 ( V_24 , V_33 ) ;
if ( V_31 ) {
goto V_46;
}
F_20 ( V_47 ) ;
F_11 ( V_48 L_19
L_20 , V_9 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_11 . V_12 ; V_10 ++ )
F_2 ( L_21 ,
( V_10 == V_8 -> V_11 . V_25 ? '*' : ' ' ) , V_10 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_15 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_49 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_43 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_50 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_14 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_28 ) ;
V_8 -> V_27 = 1 ;
return ( V_31 ) ;
V_46:
F_21 ( V_33 ) ;
V_37:
F_22 ( V_9 ) ;
V_36:
F_21 ( V_8 ) ;
V_29 [ V_9 ] = NULL ;
return ( V_31 ) ;
}
static int
F_23 (
struct V_23 * V_24 )
{
struct V_7 * V_8 = V_29 [ V_24 -> V_9 ] ;
F_2 ( L_22 ) ;
if ( V_8 ) {
V_29 [ V_24 -> V_9 ] = NULL ;
F_22 ( V_24 -> V_9 ) ;
F_21 ( V_24 -> V_33 ) ;
F_21 ( V_8 ) ;
}
return ( 0 ) ;
}
static int T_4
F_24 ( void )
{
F_2 ( L_23 ) ;
return F_25 ( & V_51 ) ;
}
static void T_5
F_26 ( void )
{
F_2 ( L_24 ) ;
F_27 ( & V_51 ) ;
return;
}
