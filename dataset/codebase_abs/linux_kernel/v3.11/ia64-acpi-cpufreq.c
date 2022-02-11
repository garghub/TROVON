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
struct V_26 V_26 ;
T_3 V_17 ;
int V_2 ;
F_2 ( L_9 ) ;
V_17 = V_19 -> V_20 ;
F_8 ( V_19 , F_9 ( V_24 -> V_9 ) ) ;
if ( F_10 () != V_24 -> V_9 ) {
V_2 = - V_27 ;
goto V_21;
}
if ( V_25 == V_8 -> V_11 . V_25 ) {
if ( F_13 ( V_8 -> V_28 ) ) {
F_2 ( L_10 , V_25 ) ;
V_8 -> V_28 = 0 ;
} else {
F_2 ( L_11 , V_25 ) ;
V_2 = 0 ;
goto V_21;
}
}
F_2 ( L_12 ,
V_8 -> V_11 . V_25 , V_25 ) ;
V_26 . V_29 = V_8 -> V_30 [ V_8 -> V_11 . V_25 ] . V_31 ;
V_26 . V_32 = V_8 -> V_30 [ V_25 ] . V_31 ;
F_14 ( V_24 , & V_26 , V_33 ) ;
V_1 = ( T_1 ) V_8 -> V_11 . V_13 [ V_25 ] . V_34 ;
F_2 ( L_13 , V_1 ) ;
V_16 = F_1 ( V_1 ) ;
if ( V_16 ) {
unsigned int V_35 = V_26 . V_32 ;
F_14 ( V_24 , & V_26 ,
V_36 ) ;
V_26 . V_32 = V_26 . V_29 ;
V_26 . V_29 = V_35 ;
F_14 ( V_24 , & V_26 ,
V_33 ) ;
F_14 ( V_24 , & V_26 ,
V_36 ) ;
F_11 ( V_22 L_14 , V_16 ) ;
V_2 = - V_4 ;
goto V_21;
}
F_14 ( V_24 , & V_26 , V_36 ) ;
V_8 -> V_11 . V_25 = V_25 ;
V_2 = 0 ;
V_21:
F_8 ( V_19 , & V_17 ) ;
return ( V_2 ) ;
}
static unsigned int
F_15 (
unsigned int V_9 )
{
struct V_7 * V_8 = V_37 [ V_9 ] ;
F_2 ( L_15 ) ;
return F_7 ( V_8 , V_9 ) ;
}
static int
F_16 (
struct V_23 * V_24 ,
unsigned int V_38 ,
unsigned int V_39 )
{
struct V_7 * V_8 = V_37 [ V_24 -> V_9 ] ;
unsigned int V_40 = 0 ;
unsigned int V_41 = 0 ;
F_2 ( L_16 ) ;
V_41 = F_17 ( V_24 ,
V_8 -> V_30 , V_38 , V_39 , & V_40 ) ;
if ( V_41 )
return ( V_41 ) ;
V_41 = F_12 ( V_8 , V_24 , V_40 ) ;
return ( V_41 ) ;
}
static int
F_18 (
struct V_23 * V_24 )
{
unsigned int V_41 = 0 ;
struct V_7 * V_8 = V_37 [ V_24 -> V_9 ] ;
F_2 ( L_17 ) ;
V_41 = F_19 ( V_24 ,
V_8 -> V_30 ) ;
return ( V_41 ) ;
}
static int
F_20 (
struct V_23 * V_24 )
{
unsigned int V_10 ;
unsigned int V_9 = V_24 -> V_9 ;
struct V_7 * V_8 ;
unsigned int V_41 = 0 ;
F_2 ( L_18 ) ;
V_8 = F_21 ( sizeof( struct V_7 ) , V_42 ) ;
if ( ! V_8 )
return ( - V_43 ) ;
V_37 [ V_9 ] = V_8 ;
V_41 = F_22 ( & V_8 -> V_11 , V_9 ) ;
if ( V_41 )
goto V_44;
if ( V_8 -> V_11 . V_12 <= 1 ) {
F_2 ( L_19 ) ;
V_41 = - V_4 ;
goto V_45;
}
if ( ( V_8 -> V_11 . V_46 . V_47 !=
V_48 ) ||
( V_8 -> V_11 . V_49 . V_47 !=
V_48 ) ) {
F_2 ( L_20 ,
( T_1 ) ( V_8 -> V_11 . V_46 . V_47 ) ,
( T_1 ) ( V_8 -> V_11 . V_49 . V_47 ) ) ;
V_41 = - V_4 ;
goto V_45;
}
V_8 -> V_30 = F_23 ( sizeof( struct V_50 ) *
( V_8 -> V_11 . V_12 + 1 ) ,
V_42 ) ;
if ( ! V_8 -> V_30 ) {
V_41 = - V_43 ;
goto V_45;
}
V_24 -> V_51 . V_52 = 0 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_11 . V_12 ; V_10 ++ ) {
if ( ( V_8 -> V_11 . V_13 [ V_10 ] . V_52 * 1000 ) >
V_24 -> V_51 . V_52 ) {
V_24 -> V_51 . V_52 =
V_8 -> V_11 . V_13 [ V_10 ] . V_52 * 1000 ;
}
}
V_24 -> V_53 = F_7 ( V_8 , V_24 -> V_9 ) ;
for ( V_10 = 0 ; V_10 <= V_8 -> V_11 . V_12 ; V_10 ++ )
{
V_8 -> V_30 [ V_10 ] . V_54 = V_10 ;
if ( V_10 < V_8 -> V_11 . V_12 ) {
V_8 -> V_30 [ V_10 ] . V_31 =
V_8 -> V_11 . V_13 [ V_10 ] . V_15 * 1000 ;
} else {
V_8 -> V_30 [ V_10 ] . V_31 = V_55 ;
}
}
V_41 = F_24 ( V_24 , V_8 -> V_30 ) ;
if ( V_41 ) {
goto V_56;
}
F_25 ( V_57 ) ;
F_11 ( V_58 L_21
L_22 , V_9 ) ;
for ( V_10 = 0 ; V_10 < V_8 -> V_11 . V_12 ; V_10 ++ )
F_2 ( L_23 ,
( V_10 == V_8 -> V_11 . V_25 ? '*' : ' ' ) , V_10 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_15 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_59 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_52 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_60 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_14 ,
( T_1 ) V_8 -> V_11 . V_13 [ V_10 ] . V_34 ) ;
F_26 ( V_8 -> V_30 , V_24 -> V_9 ) ;
V_8 -> V_28 = 1 ;
return ( V_41 ) ;
V_56:
F_27 ( V_8 -> V_30 ) ;
V_45:
F_28 ( & V_8 -> V_11 , V_9 ) ;
V_44:
F_27 ( V_8 ) ;
V_37 [ V_9 ] = NULL ;
return ( V_41 ) ;
}
static int
F_29 (
struct V_23 * V_24 )
{
struct V_7 * V_8 = V_37 [ V_24 -> V_9 ] ;
F_2 ( L_24 ) ;
if ( V_8 ) {
F_30 ( V_24 -> V_9 ) ;
V_37 [ V_24 -> V_9 ] = NULL ;
F_28 ( & V_8 -> V_11 ,
V_24 -> V_9 ) ;
F_27 ( V_8 ) ;
}
return ( 0 ) ;
}
static int T_4
F_31 ( void )
{
F_2 ( L_25 ) ;
return F_32 ( & V_61 ) ;
}
static void T_5
F_33 ( void )
{
F_2 ( L_26 ) ;
F_34 ( & V_61 ) ;
return;
}
