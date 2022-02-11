static struct V_1 * F_1 ( void )
{
if ( V_2 . V_3 )
return NULL ;
V_2 . V_3 = 1 ;
return & V_2 ;
}
static void F_2 ( struct V_1 * V_4 )
{
F_3 ( V_4 -> V_5 ) ;
V_4 -> V_3 = 0 ;
}
static struct V_1 * F_4 ( int V_4 , int * V_6 )
{
if ( V_4 >= 0 && V_4 < V_7 ) {
* V_6 = V_4 ;
return & V_2 ;
}
return NULL ;
}
static struct V_1 * F_5 ( int V_4 , int * V_6 )
{
struct V_1 * V_5 = F_4 ( V_4 , V_6 ) ;
if ( V_5 == NULL || ! V_5 -> V_8 )
return NULL ;
return V_5 ;
}
static struct V_9 * F_6 ( int V_4 )
{
int V_10 ;
struct V_1 * V_11 = F_4 ( V_4 , & V_10 ) ;
if ( V_11 != NULL )
return & V_11 -> V_9 [ V_10 ] ;
return NULL ;
}
static int F_7 ( struct V_12 * V_13 , int V_14 , T_1 * V_15 )
{
int V_16 ;
T_2 V_17 ;
T_2 const V_18 =
( V_19 << 24 )
| ( V_20 << 16 )
| ( V_14 << 8 )
| ( V_21 << 4 ) ;
F_8 ( & V_13 -> V_22 , L_1 , V_14 ) ;
F_9 ( & V_23 ) ;
V_16 = F_10 ( V_13 , V_24 , V_18 ) ;
if ( ! V_16 ) {
V_16 = F_11 ( V_13 , V_25 , & V_17 ) ;
* V_15 = ( T_1 ) V_17 ;
}
F_12 ( & V_23 ) ;
return V_16 ;
}
static int F_13 ( struct V_12 * V_13 ,
int V_14 ,
T_1 V_15 )
{
int V_16 ;
T_2 const V_18 = ( V_26 << 24 )
| ( V_20 << 16 )
| ( V_14 << 8 )
| ( V_21 << 4 ) ;
F_9 ( & V_23 ) ;
V_16 = F_10 ( V_13 , V_25 , V_15 ) ;
if ( ! V_16 )
V_16 = F_10 ( V_13 , V_24 , V_18 ) ;
F_12 ( & V_23 ) ;
return V_16 ;
}
static int F_14 ( struct V_1 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_5 ;
unsigned int V_27 ;
int V_16 = 0 ;
int V_14 = 0x10 ;
for ( V_27 = 0 ; V_27 < V_7 ; ++ V_27 ) {
struct V_28 * V_15 = & V_4 -> V_28 [ V_27 ] ;
V_16 = F_7 ( V_13 , V_14 ++ , & V_15 -> V_29 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_7 ( V_13 , V_14 ++ , & V_15 -> V_30 ) ;
if ( V_16 != 0 )
return V_16 ;
V_15 -> V_29 &= ( T_1 ) 0xfffffc00u ;
if ( ( V_15 -> V_30 & 0xfffffc00u ) == 0 )
V_15 -> V_30 = 0 ;
else
V_15 -> V_30 |= 0x3ffu ;
}
if ( V_16 == 0 ) {
for ( V_27 = 0 ; V_27 != V_7 ; ++ V_27 ) {
F_15 ( & V_13 -> V_22 , L_2
L_3 , V_27 ,
( unsigned long ) V_4 -> V_28 [ V_27 ] . V_29 ,
( unsigned long ) V_4 -> V_28 [ V_27 ] . V_30 ) ;
}
}
return V_16 ;
}
int F_16 ( int V_31 , T_1 * V_32 , T_1 * V_33 )
{
int V_10 ;
struct V_1 * V_4 = F_5 ( V_31 , & V_10 ) ;
if ( V_4 == NULL ) {
F_17 ( 1 ) ;
return - V_34 ;
}
* V_32 = V_4 -> V_28 [ V_10 ] . V_29 ;
* V_33 = V_4 -> V_28 [ V_10 ] . V_30 ;
return 0 ;
}
int F_18 ( int V_31 )
{
struct V_1 * V_4 ;
int V_16 ;
int V_10 ;
T_1 V_29 , V_30 ;
V_4 = F_5 ( V_31 , & V_10 ) ;
if ( V_4 == NULL ) {
F_17 ( 1 ) ;
return - V_35 ;
}
V_29 = V_4 -> V_28 [ V_10 ] . V_29 & 0xfffffc00u ;
V_30 = V_4 -> V_28 [ V_10 ] . V_30 & 0xfffffc00u ;
if ( V_31 == V_36 ) {
V_29 |= 0x00000009 ;
V_30 |= 0x00000015 ;
} else if ( V_31 == V_37 ) {
V_29 |= 0x00000008 ;
V_30 |= 0x00000018 ;
} else
V_30 |= 0x00000018 ;
V_16 = F_13 ( V_4 -> V_5 ,
2 * V_10 , V_29 ) ;
if ( V_16 == 0 )
V_16 = F_13 ( V_4 -> V_5 ,
2 * V_10 + 1 , V_30 ) ;
return V_16 ;
}
int F_19 ( int V_38 , int (* F_20)( unsigned long V_39 ) ,
unsigned long V_39 )
{
struct V_1 * V_4 ;
struct V_9 * V_40 ;
int V_10 ;
int V_41 = 0 ;
F_9 ( & V_42 ) ;
V_40 = F_6 ( V_38 ) ;
if ( V_40 == NULL ) {
V_41 = - V_43 ;
goto V_44;
}
if ( V_40 -> V_45 ) {
V_41 = - V_46 ;
goto V_44;
}
V_40 -> V_45 = 1 ;
V_4 = F_5 ( V_38 , & V_10 ) ;
if ( V_4 ) {
(* F_20)( V_39 ) ;
goto V_44;
}
V_40 -> F_20 = F_20 ;
V_40 -> V_47 = V_39 ;
V_44:
F_12 ( & V_42 ) ;
return V_41 ;
}
void F_21 ( int V_38 )
{
struct V_9 * V_40 ;
F_9 ( & V_42 ) ;
V_40 = F_6 ( V_38 ) ;
if ( V_40 == NULL || ! V_40 -> V_45 )
F_17 ( 1 ) ;
else
V_40 -> V_45 = 0 ;
F_12 ( & V_42 ) ;
}
static void F_22 ( struct V_1 * V_4 )
{
struct V_9 * V_40 = & V_4 -> V_9 [ 0 ] ;
int V_27 ;
F_9 ( & V_42 ) ;
V_4 -> V_8 = 1 ;
for ( V_27 = 0 ; V_27 < V_7 ; V_27 ++ ) {
if ( V_40 -> F_20 && V_40 -> V_45 ) {
V_40 -> F_20 ( V_40 -> V_47 ) ;
V_40 -> F_20 = NULL ;
}
V_40 ++ ;
}
F_12 ( & V_42 ) ;
}
static int F_23 ( struct V_12 * V_22 , const struct V_48 * V_49 )
{
int error ;
struct V_1 * V_4 ;
F_8 ( & V_22 -> V_22 , L_4 ) ;
V_4 = F_1 () ;
if ( V_4 == NULL )
return - V_46 ;
error = F_24 ( V_22 ) ;
if ( error ) {
F_25 ( & V_22 -> V_22 ,
L_5 ) ;
goto V_50;
}
V_4 -> V_5 = F_26 ( V_22 ) ;
F_27 ( V_22 , V_4 ) ;
error = F_14 ( V_4 ) ;
if ( error ) {
F_28 ( V_22 ) ;
F_25 ( & V_22 -> V_22 , L_6 ) ;
goto V_50;
}
F_22 ( V_4 ) ;
return 0 ;
V_50:
F_2 ( V_4 ) ;
return error ;
}
static int T_3 F_29 ( void )
{
return F_30 ( & V_51 ) ;
}
static void T_4 F_31 ( void )
{
F_32 ( & V_51 ) ;
}
