static struct V_1 * F_1 ( struct V_2 * V_3 , unsigned V_4 ,
unsigned V_5 )
{
struct V_1 * V_6 ;
V_6 = F_2 ( sizeof( struct V_1 ) + V_4 * sizeof( struct V_7 ) ,
V_8 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_3 = V_3 ;
V_6 -> V_5 = V_5 ;
V_3 -> V_9 = V_6 ;
return V_6 ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_6 = V_3 -> V_9 ;
T_1 V_10 = V_3 -> V_11 ;
T_1 V_12 ;
if ( ! ( V_6 -> V_5 & ( V_6 -> V_5 - 1 ) ) )
V_6 -> V_13 = F_4 ( V_6 -> V_5 ) ;
else
V_6 -> V_13 = - 1 ;
V_6 -> V_14 = 1 ;
while ( V_6 -> V_14 < sizeof( V_15 ) * 8 &&
( V_15 ) 1 << V_6 -> V_14 < V_4 )
V_6 -> V_14 ++ ;
V_6 -> V_16 = ( sizeof( V_15 ) * 8 ) / V_6 -> V_14 ;
if ( ! ( V_6 -> V_16 & ( V_6 -> V_16 - 1 ) ) )
V_6 -> V_17 = F_4 ( V_6 -> V_16 ) ;
else
V_6 -> V_17 = - 1 ;
if ( F_5 ( V_10 , V_6 -> V_5 ) )
V_10 ++ ;
V_6 -> V_10 = V_10 ;
if ( V_6 -> V_10 != V_10 || V_6 -> V_10 >= V_18 ) {
V_3 -> error = L_1 ;
return - V_19 ;
}
V_12 = V_10 ;
if ( F_5 ( V_12 , V_6 -> V_16 ) )
V_12 ++ ;
if ( V_12 > V_18 / sizeof( V_15 ) ) {
V_3 -> error = L_1 ;
return - V_19 ;
}
V_6 -> V_20 = F_6 ( V_12 * sizeof( V_15 ) ) ;
if ( ! V_6 -> V_20 ) {
V_3 -> error = L_2 ;
return - V_21 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_6 , unsigned long V_22 ,
unsigned long * V_23 , unsigned * V_24 )
{
if ( V_6 -> V_17 >= 0 ) {
* V_23 = V_22 >> V_6 -> V_17 ;
* V_24 = V_22 & ( V_6 -> V_16 - 1 ) ;
} else {
* V_23 = V_22 / V_6 -> V_16 ;
* V_24 = V_22 % V_6 -> V_16 ;
}
* V_24 *= V_6 -> V_14 ;
}
static unsigned F_8 ( struct V_1 * V_6 , T_1 V_25 )
{
unsigned long V_23 ;
unsigned V_24 , V_26 ;
T_1 V_27 ;
V_27 = V_25 ;
if ( V_6 -> V_13 >= 0 )
V_27 >>= V_6 -> V_13 ;
else
F_5 ( V_27 , V_6 -> V_5 ) ;
F_7 ( V_6 , V_27 , & V_23 , & V_24 ) ;
V_26 = ( F_9 ( V_6 -> V_20 [ V_23 ] ) >> V_24 ) &
( ( 1 << V_6 -> V_14 ) - 1 ) ;
if ( F_10 ( V_26 >= V_6 -> V_4 ) )
V_26 = 0 ;
return V_26 ;
}
static void F_11 ( struct V_1 * V_6 , unsigned long V_22 ,
unsigned V_28 )
{
unsigned long V_23 ;
unsigned V_24 ;
V_15 V_29 ;
F_7 ( V_6 , V_22 , & V_23 , & V_24 ) ;
V_29 = V_6 -> V_20 [ V_23 ] ;
V_29 &= ~ ( ( ( ( V_15 ) 1 << V_6 -> V_14 ) - 1 ) << V_24 ) ;
V_29 |= ( V_15 ) V_28 << V_24 ;
V_6 -> V_20 [ V_23 ] = V_29 ;
}
static void F_12 ( struct V_1 * V_6 )
{
unsigned V_26 = 0 ;
unsigned long V_22 ;
for ( V_22 = 0 ; V_22 < V_6 -> V_10 ; V_22 ++ ) {
F_11 ( V_6 , V_22 , V_26 ) ;
if ( ++ V_26 >= V_6 -> V_4 )
V_26 = 0 ;
}
}
static int F_13 ( struct V_30 * V_31 , struct V_2 * V_3 )
{
struct V_1 * V_6 = V_3 -> V_9 ;
unsigned long long V_32 ;
int V_33 ;
V_33 = F_14 ( V_3 , F_15 ( V_31 ) , F_16 ( V_3 -> V_34 ) ,
& V_6 -> V_35 [ V_6 -> V_4 ] . V_36 ) ;
if ( V_33 ) {
V_3 -> error = L_3 ;
return V_33 ;
}
if ( F_17 ( F_15 ( V_31 ) , 10 , & V_32 ) || V_32 != ( T_1 ) V_32 ) {
V_3 -> error = L_4 ;
F_18 ( V_3 , V_6 -> V_35 [ V_6 -> V_4 ] . V_36 ) ;
return - V_19 ;
}
V_6 -> V_35 [ V_6 -> V_4 ] . V_32 = V_32 ;
V_6 -> V_4 ++ ;
return 0 ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_3 -> V_9 ;
while ( V_6 -> V_4 -- )
F_18 ( V_3 , V_6 -> V_35 [ V_6 -> V_4 ] . V_36 ) ;
F_20 ( V_6 -> V_20 ) ;
F_21 ( V_6 ) ;
}
static int F_22 ( struct V_2 * V_3 , unsigned V_37 , char * * V_38 )
{
static struct V_39 V_40 [] = {
{ 1 , ( V_41 - sizeof( struct V_1 ) ) / sizeof( struct V_7 ) , L_5 } ,
{ 1 , V_42 , L_6 } ,
{ 0 , 0 , L_7 } ,
} ;
struct V_1 * V_6 ;
struct V_30 V_31 ;
unsigned V_4 , V_5 , V_43 ;
int V_33 ;
V_31 . V_37 = V_37 ;
V_31 . V_38 = V_38 ;
V_33 = F_23 ( V_40 , & V_31 , & V_4 , & V_3 -> error ) ;
if ( V_33 )
return - V_19 ;
V_33 = F_23 ( V_40 + 1 , & V_31 , & V_5 , & V_3 -> error ) ;
if ( V_33 )
return V_33 ;
V_33 = F_24 ( V_40 + 2 , & V_31 , & V_43 , & V_3 -> error ) ;
if ( V_33 )
return V_33 ;
if ( V_31 . V_37 != V_4 * 2 ) {
V_3 -> error = L_8 ;
return - V_19 ;
}
V_6 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( ! V_6 ) {
V_3 -> error = L_9 ;
return - V_21 ;
}
V_33 = F_25 ( V_3 , V_5 ) ;
if ( V_33 )
goto error;
while ( V_31 . V_37 ) {
V_33 = F_13 ( & V_31 , V_3 ) ;
if ( V_33 )
goto error;
}
V_33 = F_3 ( V_3 , V_4 ) ;
if ( V_33 )
goto error;
F_12 ( V_6 ) ;
V_3 -> V_44 = 1 ;
return 0 ;
error:
F_19 ( V_3 ) ;
return V_33 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_45 * V_45 )
{
struct V_1 * V_6 = V_3 -> V_9 ;
T_1 V_25 = F_27 ( V_3 , V_45 -> V_46 ) ;
unsigned V_26 = F_8 ( V_6 , V_25 ) ;
V_45 -> V_47 = V_6 -> V_35 [ V_26 ] . V_36 -> V_48 ;
V_45 -> V_46 = V_6 -> V_35 [ V_26 ] . V_32 + V_25 ;
return V_49 ;
}
static T_2 unsigned long F_28 ( const char * * string )
{
unsigned char V_50 ;
unsigned long V_33 = 0 ;
while ( ( V_50 = V_51 [ ( unsigned char ) * * string ] ) < 16 ) {
V_33 = ( V_33 << 4 ) | V_50 ;
( * string ) ++ ;
}
return V_33 ;
}
static int F_29 ( struct V_1 * V_6 ,
unsigned V_37 , char * * V_38 )
{
unsigned V_52 ;
unsigned long V_23 = 0 ;
for ( V_52 = 1 ; V_52 < V_37 ; V_52 ++ ) {
unsigned long V_26 ;
const char * string = V_38 [ V_52 ] ;
if ( * string == ':' )
V_23 ++ ;
else {
V_23 = F_28 ( & string ) ;
if ( F_10 ( * string != ':' ) ) {
F_30 ( L_10 , V_38 [ V_52 ] ) ;
return - V_19 ;
}
}
string ++ ;
if ( F_10 ( ! * string ) ) {
F_30 ( L_10 , V_38 [ V_52 ] ) ;
return - V_19 ;
}
V_26 = F_28 ( & string ) ;
if ( F_10 ( * string ) ) {
F_30 ( L_10 , V_38 [ V_52 ] ) ;
return - V_19 ;
}
if ( F_10 ( V_23 >= V_6 -> V_10 ) ) {
F_30 ( L_11 , V_23 , V_6 -> V_10 ) ;
return - V_19 ;
}
if ( F_10 ( V_26 >= V_6 -> V_4 ) ) {
F_30 ( L_12 , V_26 , V_6 -> V_4 ) ;
return - V_19 ;
}
F_11 ( V_6 , V_23 , V_26 ) ;
}
return 0 ;
}
static int F_31 ( struct V_2 * V_3 , unsigned V_37 , char * * V_38 )
{
static F_32 ( V_53 ) ;
struct V_1 * V_6 = V_3 -> V_9 ;
int V_33 = - V_19 ;
F_33 ( & V_53 ) ;
if ( ! strcasecmp ( V_38 [ 0 ] , L_13 ) )
V_33 = F_29 ( V_6 , V_37 , V_38 ) ;
else
F_30 ( L_14 ) ;
F_34 ( & V_53 ) ;
return V_33 ;
}
static void F_35 ( struct V_2 * V_3 , T_3 type ,
unsigned V_54 , char * V_55 , unsigned V_56 )
{
struct V_1 * V_6 = V_3 -> V_9 ;
unsigned V_57 = 0 ;
int V_26 ;
switch ( type ) {
case V_58 :
V_55 [ 0 ] = '\0' ;
break;
case V_59 :
F_36 ( L_15 , V_6 -> V_4 , V_6 -> V_5 ) ;
for ( V_26 = 0 ; V_26 < V_6 -> V_4 ; V_26 ++ )
F_36 ( L_16 , V_6 -> V_35 [ V_26 ] . V_36 -> V_60 ,
( unsigned long long ) V_6 -> V_35 [ V_26 ] . V_32 ) ;
break;
}
}
static int F_37 ( struct V_2 * V_3 , unsigned V_61 ,
unsigned long V_62 )
{
struct V_1 * V_6 = V_3 -> V_9 ;
struct V_63 * V_48 ;
T_4 V_64 ;
unsigned V_26 ;
int V_33 = 0 ;
V_26 = F_8 ( V_6 , 0 ) ;
V_48 = V_6 -> V_35 [ V_26 ] . V_36 -> V_48 ;
V_64 = V_6 -> V_35 [ V_26 ] . V_36 -> V_64 ;
if ( V_3 -> V_11 + V_6 -> V_35 [ V_26 ] . V_32 != F_38 ( V_48 -> V_65 ) >> V_66 )
V_33 = F_39 ( NULL , V_61 ) ;
return V_33 ? : F_40 ( V_48 , V_64 , V_61 , V_62 ) ;
}
static int F_41 ( struct V_2 * V_3 ,
T_5 V_67 , void * V_68 )
{
struct V_1 * V_6 = V_3 -> V_9 ;
int V_26 ;
int V_33 ;
for ( V_26 = 0 ; V_26 < V_6 -> V_4 ; V_26 ++ ) {
V_33 = V_67 ( V_3 , V_6 -> V_35 [ V_26 ] . V_36 ,
V_6 -> V_35 [ V_26 ] . V_32 , V_3 -> V_11 , V_68 ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static int T_6 F_42 ( void )
{
int V_33 ;
V_33 = F_43 ( & V_69 ) ;
if ( V_33 < 0 )
F_44 ( L_17 , V_33 ) ;
return V_33 ;
}
static void T_7 F_45 ( void )
{
F_46 ( & V_69 ) ;
}
