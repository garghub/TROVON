static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
T_1 V_6 = F_2 ( & V_4 -> V_7 [ V_5 ] . V_6 ) ;
int V_8 = V_6 == V_9 || ( V_6 & V_10 ) ;
if ( V_8 && ! F_3 ( V_5 , & V_4 -> V_11 ) ) {
F_4 ( V_12 , & V_4 -> V_7 [ V_5 ] . V_6 ) ;
return 1 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_6 )
{
unsigned long V_13 = V_14 ;
int V_15 , V_5 ;
int V_16 = V_4 -> V_16 ;
int V_17 = 100 ;
if ( ( V_6 & V_18 ) == V_19 )
V_16 = 1 ;
for ( V_15 = 0 ; V_15 < V_17 ; V_15 ++ ) {
for ( V_5 = 1 ; V_5 <= V_16 ; V_5 ++ )
if ( F_1 ( V_2 , V_4 , V_5 ) )
return V_5 ;
if ( ! ( V_6 & V_20 ) ) {
if ( F_6 ( V_14 ,
V_13 + F_7 ( 10 * V_17 ) ) )
break;
F_8 ( 10 , 0 ) ;
}
}
return - V_21 ;
}
static void F_9 ( volatile struct V_22 T_2 * V_7 , int V_23 , int args , T_1 V_24 [] )
{
int V_15 ;
F_4 ( V_23 , & V_7 -> V_23 ) ;
F_4 ( V_25 , & V_7 -> V_26 ) ;
for ( V_15 = 0 ; V_15 < V_27 ; V_15 ++ )
F_4 ( V_24 [ V_15 ] , & V_7 -> V_24 [ V_15 ] ) ;
F_4 ( V_28 | V_12 , & V_7 -> V_6 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 <= V_4 -> V_16 ; V_15 ++ ) {
F_11 ( L_1 ,
V_15 , F_2 ( & V_4 -> V_7 [ V_15 ] . V_23 ) , F_2 ( & V_4 -> V_7 [ V_15 ] . V_6 ) ) ;
F_4 ( 0 , & V_4 -> V_7 [ V_15 ] . V_6 ) ;
F_12 ( V_15 , & V_4 -> V_11 ) ;
}
}
static int F_13 ( struct V_1 * V_2 , int V_23 , int args , T_1 V_24 [] )
{
struct V_3 * V_4 = ( V_23 >= 128 ) ? & V_2 -> V_29 : & V_2 -> V_30 ;
volatile struct V_22 T_2 * V_7 ;
int V_31 = F_7 ( 1000 ) ;
int V_6 , V_5 , V_15 ;
unsigned long V_13 ;
if ( NULL == V_4 ) {
F_14 ( L_2 ) ;
return - V_21 ;
}
if ( args < 0 || args > V_27 ||
V_23 < 0 || V_23 > 255 || V_32 [ V_23 ] . V_33 == NULL ) {
F_14 ( L_3 , V_23 , args ) ;
return - V_34 ;
}
if ( V_32 [ V_23 ] . V_6 & V_35 ) {
F_15 ( L_4 , V_32 [ V_23 ] . V_33 ) ;
}
else {
F_16 ( L_4 , V_32 [ V_23 ] . V_33 ) ;
}
for ( V_15 = args ; V_15 < V_27 ; V_15 ++ )
V_24 [ V_15 ] = 0 ;
if ( V_2 -> V_36 [ V_23 ] . V_37 &&
F_17 ( V_14 ,
V_2 -> V_36 [ V_23 ] . V_37 +
F_7 ( 1800000 ) ) &&
! memcmp ( V_24 , V_2 -> V_36 [ V_23 ] . V_24 , sizeof( V_2 -> V_36 [ V_23 ] . V_24 ) ) ) {
V_2 -> V_36 [ V_23 ] . V_37 = V_14 ;
return 0 ;
}
V_6 = V_32 [ V_23 ] . V_6 ;
if ( V_6 & V_38 ) {
for ( V_15 = 0 ; V_15 < 100 ; V_15 ++ ) {
V_5 = V_15 % ( V_4 -> V_16 + 1 ) ;
if ( F_1 ( V_2 , V_4 , V_5 ) ) {
F_9 ( & V_4 -> V_7 [ V_5 ] , V_23 , args , V_24 ) ;
F_12 ( V_5 , & V_4 -> V_11 ) ;
return 0 ;
}
F_11 ( L_5 ,
V_32 [ V_23 ] . V_33 , V_5 , F_2 ( & V_4 -> V_7 [ V_5 ] . V_6 ) ) ;
}
F_18 ( L_6 , V_32 [ V_23 ] . V_33 ) ;
F_10 ( V_2 , V_4 ) ;
return - V_39 ;
}
if ( ( V_6 & V_18 ) == V_18 )
V_31 = F_7 ( 100 ) ;
V_5 = F_5 ( V_2 , V_4 , V_6 ) ;
if ( V_5 < 0 ) {
F_11 ( L_7 , V_32 [ V_23 ] . V_33 ) ;
F_10 ( V_2 , V_4 ) ;
return - V_39 ;
}
V_7 = & V_4 -> V_7 [ V_5 ] ;
F_9 ( V_7 , V_23 , args , V_24 ) ;
if ( V_6 & V_40 ) {
memcpy ( V_2 -> V_36 [ V_23 ] . V_24 , V_24 , sizeof( V_2 -> V_36 [ V_23 ] . V_24 ) ) ;
V_2 -> V_36 [ V_23 ] . V_37 = V_14 ;
}
if ( ( V_6 & V_19 ) == 0 ) {
F_12 ( V_5 , & V_4 -> V_11 ) ;
return 0 ;
}
V_13 = V_14 ;
if ( ! ( V_6 & V_41 ) ) {
for ( V_15 = 0 ; V_15 < 100 ; V_15 ++ ) {
if ( F_2 ( & V_7 -> V_6 ) & V_10 )
break;
}
}
while ( ! ( F_2 ( & V_7 -> V_6 ) & V_10 ) ) {
if ( F_6 ( V_14 , V_13 + V_31 ) ) {
F_11 ( L_8 , V_32 [ V_23 ] . V_33 ) ;
F_4 ( 0 , & V_7 -> V_6 ) ;
F_12 ( V_5 , & V_4 -> V_11 ) ;
return - V_42 ;
}
if ( V_6 & V_43 )
F_19 ( 1 ) ;
else
F_8 ( 1 , 0 ) ;
}
if ( F_6 ( V_14 , V_13 + F_7 ( 100 ) ) )
F_11 ( L_9 ,
V_32 [ V_23 ] . V_33 ,
F_20 ( V_14 - V_13 ) ) ;
for ( V_15 = 0 ; V_15 < V_27 ; V_15 ++ )
V_24 [ V_15 ] = F_2 ( & V_7 -> V_24 [ V_15 ] ) ;
F_4 ( 0 , & V_7 -> V_6 ) ;
F_12 ( V_5 , & V_4 -> V_11 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , int V_23 , int args , T_1 V_24 [] )
{
int V_44 = F_13 ( V_2 , V_23 , args , V_24 ) ;
return ( V_44 == - V_39 ) ? F_13 ( V_2 , V_23 , args , V_24 ) : V_44 ;
}
int F_22 ( void * V_45 , T_1 V_23 , int V_46 , int V_47 , T_1 V_24 [ V_27 ] )
{
return F_21 ( V_45 , V_23 , V_46 , V_24 ) ;
}
int F_23 ( struct V_1 * V_2 , T_1 V_24 [ V_27 ] , int V_23 , int args , ... )
{
T_3 V_48 ;
int V_15 ;
va_start ( V_48 , args ) ;
for ( V_15 = 0 ; V_15 < args ; V_15 ++ ) {
V_24 [ V_15 ] = va_arg ( V_48 , T_1 ) ;
}
va_end ( V_48 ) ;
return F_21 ( V_2 , V_23 , args , V_24 ) ;
}
int F_24 ( struct V_1 * V_2 , int V_23 , int args , ... )
{
T_1 V_24 [ V_27 ] ;
T_3 V_48 ;
int V_15 ;
va_start ( V_48 , args ) ;
for ( V_15 = 0 ; V_15 < args ; V_15 ++ ) {
V_24 [ V_15 ] = va_arg ( V_48 , T_1 ) ;
}
va_end ( V_48 ) ;
return F_21 ( V_2 , V_23 , args , V_24 ) ;
}
void F_25 ( struct V_3 * V_4 , int V_5 ,
int V_49 , T_1 V_24 [] )
{
volatile T_1 T_2 * V_50 = V_4 -> V_7 [ V_5 ] . V_24 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_49 ; V_15 ++ , V_50 ++ )
V_24 [ V_15 ] = F_2 ( V_50 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < 256 ; V_15 ++ )
V_2 -> V_36 [ V_15 ] . V_37 = 0 ;
}
