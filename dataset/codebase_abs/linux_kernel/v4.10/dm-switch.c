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
if ( V_10 >= V_18 ) {
V_3 -> error = L_1 ;
return - V_19 ;
}
V_6 -> V_10 = V_10 ;
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
static unsigned F_8 ( struct V_1 * V_6 , unsigned long V_22 )
{
unsigned long V_23 ;
unsigned V_24 ;
F_7 ( V_6 , V_22 , & V_23 , & V_24 ) ;
return ( F_9 ( V_6 -> V_20 [ V_23 ] ) >> V_24 ) &
( ( 1 << V_6 -> V_14 ) - 1 ) ;
}
static unsigned F_10 ( struct V_1 * V_6 , T_1 V_25 )
{
unsigned V_26 ;
T_1 V_27 ;
V_27 = V_25 ;
if ( V_6 -> V_13 >= 0 )
V_27 >>= V_6 -> V_13 ;
else
F_5 ( V_27 , V_6 -> V_5 ) ;
V_26 = F_8 ( V_6 , V_27 ) ;
if ( F_11 ( V_26 >= V_6 -> V_4 ) )
V_26 = 0 ;
return V_26 ;
}
static void F_12 ( struct V_1 * V_6 , unsigned long V_22 ,
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
static void F_13 ( struct V_1 * V_6 )
{
unsigned V_26 = 0 ;
unsigned long V_22 ;
for ( V_22 = 0 ; V_22 < V_6 -> V_10 ; V_22 ++ ) {
F_12 ( V_6 , V_22 , V_26 ) ;
if ( ++ V_26 >= V_6 -> V_4 )
V_26 = 0 ;
}
}
static int F_14 ( struct V_30 * V_31 , struct V_2 * V_3 )
{
struct V_1 * V_6 = V_3 -> V_9 ;
unsigned long long V_32 ;
int V_33 ;
V_33 = F_15 ( V_3 , F_16 ( V_31 ) , F_17 ( V_3 -> V_34 ) ,
& V_6 -> V_35 [ V_6 -> V_4 ] . V_36 ) ;
if ( V_33 ) {
V_3 -> error = L_3 ;
return V_33 ;
}
if ( F_18 ( F_16 ( V_31 ) , 10 , & V_32 ) || V_32 != ( T_1 ) V_32 ) {
V_3 -> error = L_4 ;
F_19 ( V_3 , V_6 -> V_35 [ V_6 -> V_4 ] . V_36 ) ;
return - V_19 ;
}
V_6 -> V_35 [ V_6 -> V_4 ] . V_32 = V_32 ;
V_6 -> V_4 ++ ;
return 0 ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_3 -> V_9 ;
while ( V_6 -> V_4 -- )
F_19 ( V_3 , V_6 -> V_35 [ V_6 -> V_4 ] . V_36 ) ;
F_21 ( V_6 -> V_20 ) ;
F_22 ( V_6 ) ;
}
static int F_23 ( struct V_2 * V_3 , unsigned V_37 , char * * V_38 )
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
V_33 = F_24 ( V_40 , & V_31 , & V_4 , & V_3 -> error ) ;
if ( V_33 )
return - V_19 ;
V_33 = F_24 ( V_40 + 1 , & V_31 , & V_5 , & V_3 -> error ) ;
if ( V_33 )
return V_33 ;
V_33 = F_25 ( V_40 + 2 , & V_31 , & V_43 , & V_3 -> error ) ;
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
V_33 = F_26 ( V_3 , V_5 ) ;
if ( V_33 )
goto error;
while ( V_31 . V_37 ) {
V_33 = F_14 ( & V_31 , V_3 ) ;
if ( V_33 )
goto error;
}
V_33 = F_3 ( V_3 , V_4 ) ;
if ( V_33 )
goto error;
F_13 ( V_6 ) ;
V_3 -> V_44 = 1 ;
return 0 ;
error:
F_20 ( V_3 ) ;
return V_33 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_45 * V_45 )
{
struct V_1 * V_6 = V_3 -> V_9 ;
T_1 V_25 = F_28 ( V_3 , V_45 -> V_46 . V_47 ) ;
unsigned V_26 = F_10 ( V_6 , V_25 ) ;
V_45 -> V_48 = V_6 -> V_35 [ V_26 ] . V_36 -> V_49 ;
V_45 -> V_46 . V_47 = V_6 -> V_35 [ V_26 ] . V_32 + V_25 ;
return V_50 ;
}
static T_2 unsigned long F_29 ( const char * * string )
{
unsigned char V_51 ;
unsigned long V_33 = 0 ;
while ( ( V_51 = V_52 [ ( unsigned char ) * * string ] ) < 16 ) {
V_33 = ( V_33 << 4 ) | V_51 ;
( * string ) ++ ;
}
return V_33 ;
}
static int F_30 ( struct V_1 * V_6 ,
unsigned V_37 , char * * V_38 )
{
unsigned V_53 ;
unsigned long V_23 = 0 ;
for ( V_53 = 1 ; V_53 < V_37 ; V_53 ++ ) {
unsigned long V_26 ;
const char * string = V_38 [ V_53 ] ;
if ( ( * string & 0xdf ) == 'R' ) {
unsigned long V_54 , V_55 ;
string ++ ;
if ( F_11 ( * string == ',' ) ) {
F_31 ( L_10 , V_38 [ V_53 ] ) ;
return - V_19 ;
}
V_54 = F_29 ( & string ) ;
if ( F_11 ( * string != ',' ) ) {
F_31 ( L_10 , V_38 [ V_53 ] ) ;
return - V_19 ;
}
string ++ ;
if ( F_11 ( ! * string ) ) {
F_31 ( L_10 , V_38 [ V_53 ] ) ;
return - V_19 ;
}
V_55 = F_29 ( & string ) ;
if ( F_11 ( * string ) ) {
F_31 ( L_10 , V_38 [ V_53 ] ) ;
return - V_19 ;
}
if ( F_11 ( ! V_54 ) || F_11 ( V_54 - 1 > V_23 ) ) {
F_31 ( L_11 ,
V_54 - 1 , V_23 ) ;
return - V_19 ;
}
if ( F_11 ( V_23 + V_55 < V_23 ) ||
F_11 ( V_23 + V_55 >= V_6 -> V_10 ) ) {
F_31 ( L_12 ,
V_23 , V_55 , V_6 -> V_10 ) ;
return - V_19 ;
}
while ( V_55 -- ) {
V_23 ++ ;
V_26 = F_8 ( V_6 , V_23 - V_54 ) ;
F_12 ( V_6 , V_23 , V_26 ) ;
}
continue;
}
if ( * string == ':' )
V_23 ++ ;
else {
V_23 = F_29 ( & string ) ;
if ( F_11 ( * string != ':' ) ) {
F_31 ( L_10 , V_38 [ V_53 ] ) ;
return - V_19 ;
}
}
string ++ ;
if ( F_11 ( ! * string ) ) {
F_31 ( L_10 , V_38 [ V_53 ] ) ;
return - V_19 ;
}
V_26 = F_29 ( & string ) ;
if ( F_11 ( * string ) ) {
F_31 ( L_10 , V_38 [ V_53 ] ) ;
return - V_19 ;
}
if ( F_11 ( V_23 >= V_6 -> V_10 ) ) {
F_31 ( L_13 , V_23 , V_6 -> V_10 ) ;
return - V_19 ;
}
if ( F_11 ( V_26 >= V_6 -> V_4 ) ) {
F_31 ( L_14 , V_26 , V_6 -> V_4 ) ;
return - V_19 ;
}
F_12 ( V_6 , V_23 , V_26 ) ;
}
return 0 ;
}
static int F_32 ( struct V_2 * V_3 , unsigned V_37 , char * * V_38 )
{
static F_33 ( V_56 ) ;
struct V_1 * V_6 = V_3 -> V_9 ;
int V_33 = - V_19 ;
F_34 ( & V_56 ) ;
if ( ! strcasecmp ( V_38 [ 0 ] , L_15 ) )
V_33 = F_30 ( V_6 , V_37 , V_38 ) ;
else
F_31 ( L_16 ) ;
F_35 ( & V_56 ) ;
return V_33 ;
}
static void F_36 ( struct V_2 * V_3 , T_3 type ,
unsigned V_57 , char * V_58 , unsigned V_59 )
{
struct V_1 * V_6 = V_3 -> V_9 ;
unsigned V_60 = 0 ;
int V_26 ;
switch ( type ) {
case V_61 :
V_58 [ 0 ] = '\0' ;
break;
case V_62 :
F_37 ( L_17 , V_6 -> V_4 , V_6 -> V_5 ) ;
for ( V_26 = 0 ; V_26 < V_6 -> V_4 ; V_26 ++ )
F_37 ( L_18 , V_6 -> V_35 [ V_26 ] . V_36 -> V_63 ,
( unsigned long long ) V_6 -> V_35 [ V_26 ] . V_32 ) ;
break;
}
}
static int F_38 ( struct V_2 * V_3 ,
struct V_64 * * V_49 , T_4 * V_65 )
{
struct V_1 * V_6 = V_3 -> V_9 ;
unsigned V_26 ;
V_26 = F_10 ( V_6 , 0 ) ;
* V_49 = V_6 -> V_35 [ V_26 ] . V_36 -> V_49 ;
* V_65 = V_6 -> V_35 [ V_26 ] . V_36 -> V_65 ;
if ( V_3 -> V_11 + V_6 -> V_35 [ V_26 ] . V_32 !=
F_39 ( ( * V_49 ) -> V_66 ) >> V_67 )
return 1 ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 ,
T_5 V_68 , void * V_69 )
{
struct V_1 * V_6 = V_3 -> V_9 ;
int V_26 ;
int V_33 ;
for ( V_26 = 0 ; V_26 < V_6 -> V_4 ; V_26 ++ ) {
V_33 = V_68 ( V_3 , V_6 -> V_35 [ V_26 ] . V_36 ,
V_6 -> V_35 [ V_26 ] . V_32 , V_3 -> V_11 , V_69 ) ;
if ( V_33 )
return V_33 ;
}
return 0 ;
}
static int T_6 F_41 ( void )
{
int V_33 ;
V_33 = F_42 ( & V_70 ) ;
if ( V_33 < 0 )
F_43 ( L_19 , V_33 ) ;
return V_33 ;
}
static void T_7 F_44 ( void )
{
F_45 ( & V_70 ) ;
}
