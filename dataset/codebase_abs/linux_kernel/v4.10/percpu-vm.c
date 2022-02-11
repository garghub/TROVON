static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 , int V_5 )
{
F_2 ( V_3 -> V_6 ) ;
return F_3 ( ( void * ) F_4 ( V_3 , V_4 , V_5 ) ) ;
}
static struct V_1 * * F_5 ( struct V_2 * V_7 )
{
static struct V_1 * * V_8 ;
T_1 V_9 = V_10 * V_11 * sizeof( V_8 [ 0 ] ) ;
F_6 ( & V_12 ) ;
if ( ! V_8 )
V_8 = F_7 ( V_9 ) ;
return V_8 ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_1 * * V_8 , int V_13 , int V_14 )
{
unsigned int V_4 ;
int V_15 ;
F_9 (cpu) {
for ( V_15 = V_13 ; V_15 < V_14 ; V_15 ++ ) {
struct V_1 * V_1 = V_8 [ F_10 ( V_4 , V_15 ) ] ;
if ( V_1 )
F_11 ( V_1 ) ;
}
}
}
static int F_12 ( struct V_2 * V_3 ,
struct V_1 * * V_8 , int V_13 , int V_14 )
{
const T_2 V_16 = V_17 | V_18 | V_19 ;
unsigned int V_4 , V_20 ;
int V_15 ;
F_9 (cpu) {
for ( V_15 = V_13 ; V_15 < V_14 ; V_15 ++ ) {
struct V_1 * * V_21 = & V_8 [ F_10 ( V_4 , V_15 ) ] ;
* V_21 = F_13 ( F_14 ( V_4 ) , V_16 , 0 ) ;
if ( ! * V_21 )
goto V_22;
}
}
return 0 ;
V_22:
while ( -- V_15 >= V_13 )
F_11 ( V_8 [ F_10 ( V_4 , V_15 ) ] ) ;
F_9 (tcpu) {
if ( V_20 == V_4 )
break;
for ( V_15 = V_13 ; V_15 < V_14 ; V_15 ++ )
F_11 ( V_8 [ F_10 ( V_20 , V_15 ) ] ) ;
}
return - V_23 ;
}
static void F_15 ( struct V_2 * V_3 ,
int V_13 , int V_14 )
{
F_16 (
F_4 ( V_3 , V_24 , V_13 ) ,
F_4 ( V_3 , V_25 , V_14 ) ) ;
}
static void F_17 ( unsigned long V_26 , int V_27 )
{
F_18 ( V_26 , V_27 << V_28 ) ;
}
static void F_19 ( struct V_2 * V_3 ,
struct V_1 * * V_8 , int V_13 , int V_14 )
{
unsigned int V_4 ;
int V_15 ;
F_9 (cpu) {
for ( V_15 = V_13 ; V_15 < V_14 ; V_15 ++ ) {
struct V_1 * V_1 ;
V_1 = F_1 ( V_3 , V_4 , V_15 ) ;
F_2 ( ! V_1 ) ;
V_8 [ F_10 ( V_4 , V_15 ) ] = V_1 ;
}
F_17 ( F_4 ( V_3 , V_4 , V_13 ) ,
V_14 - V_13 ) ;
}
}
static void F_20 ( struct V_2 * V_3 ,
int V_13 , int V_14 )
{
F_21 (
F_4 ( V_3 , V_24 , V_13 ) ,
F_4 ( V_3 , V_25 , V_14 ) ) ;
}
static int F_22 ( unsigned long V_26 , struct V_1 * * V_8 ,
int V_27 )
{
return F_23 ( V_26 , V_27 << V_28 ,
V_29 , V_8 ) ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_1 * * V_8 , int V_13 , int V_14 )
{
unsigned int V_4 , V_20 ;
int V_15 , V_22 ;
F_9 (cpu) {
V_22 = F_22 ( F_4 ( V_3 , V_4 , V_13 ) ,
& V_8 [ F_10 ( V_4 , V_13 ) ] ,
V_14 - V_13 ) ;
if ( V_22 < 0 )
goto V_22;
for ( V_15 = V_13 ; V_15 < V_14 ; V_15 ++ )
F_25 ( V_8 [ F_10 ( V_4 , V_15 ) ] ,
V_3 ) ;
}
return 0 ;
V_22:
F_9 (tcpu) {
if ( V_20 == V_4 )
break;
F_17 ( F_4 ( V_3 , V_20 , V_13 ) ,
V_14 - V_13 ) ;
}
F_20 ( V_3 , V_13 , V_14 ) ;
return V_22 ;
}
static void F_26 ( struct V_2 * V_3 ,
int V_13 , int V_14 )
{
F_27 (
F_4 ( V_3 , V_24 , V_13 ) ,
F_4 ( V_3 , V_25 , V_14 ) ) ;
}
static int F_28 ( struct V_2 * V_3 ,
int V_13 , int V_14 )
{
struct V_1 * * V_8 ;
V_8 = F_5 ( V_3 ) ;
if ( ! V_8 )
return - V_23 ;
if ( F_12 ( V_3 , V_8 , V_13 , V_14 ) )
return - V_23 ;
if ( F_24 ( V_3 , V_8 , V_13 , V_14 ) ) {
F_8 ( V_3 , V_8 , V_13 , V_14 ) ;
return - V_23 ;
}
F_26 ( V_3 , V_13 , V_14 ) ;
return 0 ;
}
static void F_29 ( struct V_2 * V_3 ,
int V_13 , int V_14 )
{
struct V_1 * * V_8 ;
V_8 = F_5 ( V_3 ) ;
F_30 ( ! V_8 ) ;
F_15 ( V_3 , V_13 , V_14 ) ;
F_19 ( V_3 , V_8 , V_13 , V_14 ) ;
F_8 ( V_3 , V_8 , V_13 , V_14 ) ;
}
static struct V_2 * F_31 ( void )
{
struct V_2 * V_3 ;
struct V_30 * * V_31 ;
V_3 = F_32 () ;
if ( ! V_3 )
return NULL ;
V_31 = F_33 ( V_32 , V_33 ,
V_34 , V_35 ) ;
if ( ! V_31 ) {
F_34 ( V_3 ) ;
return NULL ;
}
V_3 -> V_36 = V_31 ;
V_3 -> V_37 = V_31 [ 0 ] -> V_26 - V_32 [ 0 ] ;
return V_3 ;
}
static void F_35 ( struct V_2 * V_3 )
{
if ( V_3 && V_3 -> V_36 )
F_36 ( V_3 -> V_36 , V_34 ) ;
F_34 ( V_3 ) ;
}
static struct V_1 * F_37 ( void * V_26 )
{
return F_3 ( V_26 ) ;
}
static int T_3 F_38 ( const struct V_38 * V_39 )
{
return 0 ;
}
