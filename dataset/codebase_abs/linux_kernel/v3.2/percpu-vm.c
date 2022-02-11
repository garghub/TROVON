static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 , int V_5 )
{
F_2 ( V_3 -> V_6 ) ;
return F_3 ( ( void * ) F_4 ( V_3 , V_4 , V_5 ) ) ;
}
static struct V_1 * * F_5 ( struct V_2 * V_3 ,
unsigned long * * V_7 ,
bool V_8 )
{
static struct V_1 * * V_9 ;
static unsigned long * V_10 ;
T_1 V_11 = V_12 * V_13 * sizeof( V_9 [ 0 ] ) ;
T_1 V_14 = F_6 ( V_13 ) *
sizeof( unsigned long ) ;
if ( ! V_9 || ! V_10 ) {
if ( V_8 && ! V_9 )
V_9 = F_7 ( V_11 ) ;
if ( V_8 && ! V_10 )
V_10 = F_7 ( V_14 ) ;
if ( ! V_9 || ! V_10 )
return NULL ;
}
F_8 ( V_10 , V_3 -> V_15 , V_13 ) ;
* V_7 = V_10 ;
return V_9 ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_1 * * V_9 , unsigned long * V_15 ,
int V_16 , int V_17 )
{
unsigned int V_4 ;
int V_18 ;
F_10 (cpu) {
for ( V_18 = V_16 ; V_18 < V_17 ; V_18 ++ ) {
struct V_1 * V_1 = V_9 [ F_11 ( V_4 , V_18 ) ] ;
if ( V_1 )
F_12 ( V_1 ) ;
}
}
}
static int F_13 ( struct V_2 * V_3 ,
struct V_1 * * V_9 , unsigned long * V_15 ,
int V_16 , int V_17 )
{
const T_2 V_19 = V_20 | V_21 | V_22 ;
unsigned int V_4 ;
int V_18 ;
F_10 (cpu) {
for ( V_18 = V_16 ; V_18 < V_17 ; V_18 ++ ) {
struct V_1 * * V_23 = & V_9 [ F_11 ( V_4 , V_18 ) ] ;
* V_23 = F_14 ( F_15 ( V_4 ) , V_19 , 0 ) ;
if ( ! * V_23 ) {
F_9 ( V_3 , V_9 , V_15 ,
V_16 , V_17 ) ;
return - V_24 ;
}
}
}
return 0 ;
}
static void F_16 ( struct V_2 * V_3 ,
int V_16 , int V_17 )
{
F_17 (
F_4 ( V_3 , V_25 , V_16 ) ,
F_4 ( V_3 , V_26 , V_17 ) ) ;
}
static void F_18 ( unsigned long V_27 , int V_28 )
{
F_19 ( V_27 , V_28 << V_29 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_1 * * V_9 , unsigned long * V_15 ,
int V_16 , int V_17 )
{
unsigned int V_4 ;
int V_18 ;
F_10 (cpu) {
for ( V_18 = V_16 ; V_18 < V_17 ; V_18 ++ ) {
struct V_1 * V_1 ;
V_1 = F_1 ( V_3 , V_4 , V_18 ) ;
F_2 ( ! V_1 ) ;
V_9 [ F_11 ( V_4 , V_18 ) ] = V_1 ;
}
F_18 ( F_4 ( V_3 , V_4 , V_16 ) ,
V_17 - V_16 ) ;
}
for ( V_18 = V_16 ; V_18 < V_17 ; V_18 ++ )
F_21 ( V_18 , V_15 ) ;
}
static void F_22 ( struct V_2 * V_3 ,
int V_16 , int V_17 )
{
F_23 (
F_4 ( V_3 , V_25 , V_16 ) ,
F_4 ( V_3 , V_26 , V_17 ) ) ;
}
static int F_24 ( unsigned long V_27 , struct V_1 * * V_9 ,
int V_28 )
{
return F_25 ( V_27 , V_28 << V_29 ,
V_30 , V_9 ) ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_1 * * V_9 , unsigned long * V_15 ,
int V_16 , int V_17 )
{
unsigned int V_4 , V_31 ;
int V_18 , V_32 ;
F_10 (cpu) {
V_32 = F_24 ( F_4 ( V_3 , V_4 , V_16 ) ,
& V_9 [ F_11 ( V_4 , V_16 ) ] ,
V_17 - V_16 ) ;
if ( V_32 < 0 )
goto V_32;
}
for ( V_18 = V_16 ; V_18 < V_17 ; V_18 ++ ) {
F_10 (cpu)
F_27 ( V_9 [ F_11 ( V_4 , V_18 ) ] ,
V_3 ) ;
F_28 ( V_18 , V_15 ) ;
}
return 0 ;
V_32:
F_10 (tcpu) {
if ( V_31 == V_4 )
break;
F_18 ( F_4 ( V_3 , V_31 , V_16 ) ,
V_17 - V_16 ) ;
}
return V_32 ;
}
static void F_29 ( struct V_2 * V_3 ,
int V_16 , int V_17 )
{
F_30 (
F_4 ( V_3 , V_25 , V_16 ) ,
F_4 ( V_3 , V_26 , V_17 ) ) ;
}
static int F_31 ( struct V_2 * V_3 , int V_33 , int V_34 )
{
int V_16 = F_32 ( V_33 ) ;
int V_17 = F_33 ( V_33 + V_34 ) ;
int V_35 = V_16 , V_36 = V_16 ;
struct V_1 * * V_9 ;
unsigned long * V_15 ;
unsigned int V_4 ;
int V_37 , V_38 , V_39 ;
V_37 = V_16 ;
F_34 ( V_3 , & V_37 , & V_38 , V_17 ) ;
if ( V_37 == V_16 && V_38 == V_17 )
goto V_40;
F_2 ( V_3 -> V_6 ) ;
V_9 = F_5 ( V_3 , & V_15 , true ) ;
if ( ! V_9 )
return - V_24 ;
F_35 (chunk, rs, re, page_start, page_end) {
V_39 = F_13 ( V_3 , V_9 , V_15 , V_37 , V_38 ) ;
if ( V_39 )
goto V_41;
V_35 = V_38 ;
}
F_35 (chunk, rs, re, page_start, page_end) {
V_39 = F_26 ( V_3 , V_9 , V_15 , V_37 , V_38 ) ;
if ( V_39 )
goto V_42;
V_36 = V_38 ;
}
F_29 ( V_3 , V_16 , V_17 ) ;
F_8 ( V_3 -> V_15 , V_15 , V_13 ) ;
V_40:
F_10 (cpu)
memset ( ( void * ) F_4 ( V_3 , V_4 , 0 ) + V_33 , 0 , V_34 ) ;
return 0 ;
V_42:
F_16 ( V_3 , V_16 , V_36 ) ;
F_35 (chunk, rs, re, page_start, unmap_end)
F_20 ( V_3 , V_9 , V_15 , V_37 , V_38 ) ;
F_22 ( V_3 , V_16 , V_36 ) ;
V_41:
F_35 (chunk, rs, re, page_start, free_end)
F_9 ( V_3 , V_9 , V_15 , V_37 , V_38 ) ;
return V_39 ;
}
static void F_36 ( struct V_2 * V_3 , int V_33 , int V_34 )
{
int V_16 = F_32 ( V_33 ) ;
int V_17 = F_33 ( V_33 + V_34 ) ;
struct V_1 * * V_9 ;
unsigned long * V_15 ;
int V_37 , V_38 ;
V_37 = V_16 ;
F_37 ( V_3 , & V_37 , & V_38 , V_17 ) ;
if ( V_37 == V_16 && V_38 == V_17 )
return;
F_2 ( V_3 -> V_6 ) ;
V_9 = F_5 ( V_3 , & V_15 , false ) ;
F_38 ( ! V_9 ) ;
F_16 ( V_3 , V_16 , V_17 ) ;
F_39 (chunk, rs, re, page_start, page_end)
F_20 ( V_3 , V_9 , V_15 , V_37 , V_38 ) ;
F_39 (chunk, rs, re, page_start, page_end)
F_9 ( V_3 , V_9 , V_15 , V_37 , V_38 ) ;
F_8 ( V_3 -> V_15 , V_15 , V_13 ) ;
}
static struct V_2 * F_40 ( void )
{
struct V_2 * V_3 ;
struct V_43 * * V_44 ;
V_3 = F_41 () ;
if ( ! V_3 )
return NULL ;
V_44 = F_42 ( V_45 , V_46 ,
V_47 , V_48 ) ;
if ( ! V_44 ) {
F_43 ( V_3 ) ;
return NULL ;
}
V_3 -> V_49 = V_44 ;
V_3 -> V_50 = V_44 [ 0 ] -> V_27 - V_45 [ 0 ] ;
return V_3 ;
}
static void F_44 ( struct V_2 * V_3 )
{
if ( V_3 && V_3 -> V_49 )
F_45 ( V_3 -> V_49 , V_47 ) ;
F_43 ( V_3 ) ;
}
static struct V_1 * F_46 ( void * V_27 )
{
return F_3 ( V_27 ) ;
}
static int T_3 F_47 ( const struct V_51 * V_52 )
{
return 0 ;
}
