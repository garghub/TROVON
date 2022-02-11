static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 , int V_5 )
{
F_2 ( V_3 -> V_6 ) ;
return F_3 ( ( void * ) F_4 ( V_3 , V_4 , V_5 ) ) ;
}
static struct V_1 * * F_5 ( void )
{
static struct V_1 * * V_7 ;
T_1 V_8 = V_9 * V_10 * sizeof( V_7 [ 0 ] ) ;
F_6 ( & V_11 ) ;
if ( ! V_7 )
V_7 = F_7 ( V_8 ) ;
return V_7 ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_1 * * V_7 , int V_12 , int V_13 )
{
unsigned int V_4 ;
int V_14 ;
F_9 (cpu) {
for ( V_14 = V_12 ; V_14 < V_13 ; V_14 ++ ) {
struct V_1 * V_1 = V_7 [ F_10 ( V_4 , V_14 ) ] ;
if ( V_1 )
F_11 ( V_1 ) ;
}
}
}
static int F_12 ( struct V_2 * V_3 ,
struct V_1 * * V_7 , int V_12 , int V_13 )
{
const T_2 V_15 = V_16 | V_17 | V_18 ;
unsigned int V_4 , V_19 ;
int V_14 ;
F_9 (cpu) {
for ( V_14 = V_12 ; V_14 < V_13 ; V_14 ++ ) {
struct V_1 * * V_20 = & V_7 [ F_10 ( V_4 , V_14 ) ] ;
* V_20 = F_13 ( F_14 ( V_4 ) , V_15 , 0 ) ;
if ( ! * V_20 )
goto V_21;
}
}
return 0 ;
V_21:
while ( -- V_14 >= V_12 )
F_11 ( V_7 [ F_10 ( V_4 , V_14 ) ] ) ;
F_9 (tcpu) {
if ( V_19 == V_4 )
break;
for ( V_14 = V_12 ; V_14 < V_13 ; V_14 ++ )
F_11 ( V_7 [ F_10 ( V_19 , V_14 ) ] ) ;
}
return - V_22 ;
}
static void F_15 ( struct V_2 * V_3 ,
int V_12 , int V_13 )
{
F_16 (
F_4 ( V_3 , V_23 , V_12 ) ,
F_4 ( V_3 , V_24 , V_13 ) ) ;
}
static void F_17 ( unsigned long V_25 , int V_26 )
{
F_18 ( V_25 , V_26 << V_27 ) ;
}
static void F_19 ( struct V_2 * V_3 ,
struct V_1 * * V_7 , int V_12 , int V_13 )
{
unsigned int V_4 ;
int V_14 ;
F_9 (cpu) {
for ( V_14 = V_12 ; V_14 < V_13 ; V_14 ++ ) {
struct V_1 * V_1 ;
V_1 = F_1 ( V_3 , V_4 , V_14 ) ;
F_2 ( ! V_1 ) ;
V_7 [ F_10 ( V_4 , V_14 ) ] = V_1 ;
}
F_17 ( F_4 ( V_3 , V_4 , V_12 ) ,
V_13 - V_12 ) ;
}
}
static void F_20 ( struct V_2 * V_3 ,
int V_12 , int V_13 )
{
F_21 (
F_4 ( V_3 , V_23 , V_12 ) ,
F_4 ( V_3 , V_24 , V_13 ) ) ;
}
static int F_22 ( unsigned long V_25 , struct V_1 * * V_7 ,
int V_26 )
{
return F_23 ( V_25 , V_26 << V_27 ,
V_28 , V_7 ) ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_1 * * V_7 , int V_12 , int V_13 )
{
unsigned int V_4 , V_19 ;
int V_14 , V_21 ;
F_9 (cpu) {
V_21 = F_22 ( F_4 ( V_3 , V_4 , V_12 ) ,
& V_7 [ F_10 ( V_4 , V_12 ) ] ,
V_13 - V_12 ) ;
if ( V_21 < 0 )
goto V_21;
for ( V_14 = V_12 ; V_14 < V_13 ; V_14 ++ )
F_25 ( V_7 [ F_10 ( V_4 , V_14 ) ] ,
V_3 ) ;
}
return 0 ;
V_21:
F_9 (tcpu) {
if ( V_19 == V_4 )
break;
F_17 ( F_4 ( V_3 , V_19 , V_12 ) ,
V_13 - V_12 ) ;
}
F_20 ( V_3 , V_12 , V_13 ) ;
return V_21 ;
}
static void F_26 ( struct V_2 * V_3 ,
int V_12 , int V_13 )
{
F_27 (
F_4 ( V_3 , V_23 , V_12 ) ,
F_4 ( V_3 , V_24 , V_13 ) ) ;
}
static int F_28 ( struct V_2 * V_3 ,
int V_12 , int V_13 )
{
struct V_1 * * V_7 ;
V_7 = F_5 () ;
if ( ! V_7 )
return - V_22 ;
if ( F_12 ( V_3 , V_7 , V_12 , V_13 ) )
return - V_22 ;
if ( F_24 ( V_3 , V_7 , V_12 , V_13 ) ) {
F_8 ( V_3 , V_7 , V_12 , V_13 ) ;
return - V_22 ;
}
F_26 ( V_3 , V_12 , V_13 ) ;
return 0 ;
}
static void F_29 ( struct V_2 * V_3 ,
int V_12 , int V_13 )
{
struct V_1 * * V_7 ;
V_7 = F_5 () ;
F_30 ( ! V_7 ) ;
F_15 ( V_3 , V_12 , V_13 ) ;
F_19 ( V_3 , V_7 , V_12 , V_13 ) ;
F_8 ( V_3 , V_7 , V_12 , V_13 ) ;
}
static struct V_2 * F_31 ( void )
{
struct V_2 * V_3 ;
struct V_29 * * V_30 ;
V_3 = F_32 () ;
if ( ! V_3 )
return NULL ;
V_30 = F_33 ( V_31 , V_32 ,
V_33 , V_34 ) ;
if ( ! V_30 ) {
F_34 ( V_3 ) ;
return NULL ;
}
V_3 -> V_35 = V_30 ;
V_3 -> V_36 = V_30 [ 0 ] -> V_25 - V_31 [ 0 ] ;
F_35 () ;
F_36 ( V_3 -> V_36 ) ;
return V_3 ;
}
static void F_37 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return;
F_38 () ;
F_39 ( V_3 -> V_36 ) ;
if ( V_3 -> V_35 )
F_40 ( V_3 -> V_35 , V_33 ) ;
F_34 ( V_3 ) ;
}
static struct V_1 * F_41 ( void * V_25 )
{
return F_3 ( V_25 ) ;
}
static int T_3 F_42 ( const struct V_37 * V_38 )
{
return 0 ;
}
