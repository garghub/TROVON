static int F_1 ( int V_1 )
{
return ( V_1 + V_2 - 1 ) >> V_3 ;
}
static struct V_4 * F_2 ( struct V_5 * V_5 )
{
struct V_4 * V_6 = F_3 ( V_5 ) ;
V_6 -> V_7 = 0 ;
V_6 -> V_8 = 0 ;
F_4 ( & V_6 -> V_9 ) ;
F_4 ( & V_6 -> V_10 ) ;
V_6 -> V_11 = 0 ;
return V_6 ;
}
static void F_5 ( struct V_4 * V_6 )
{
F_6 ( F_7 ( V_6 ) ) ;
}
static unsigned long F_8 ( struct V_4 * V_6 , enum V_9 V_12 )
{
unsigned long V_13 ;
V_13 = ( unsigned long ) V_6 ;
if ( V_12 == V_14 )
V_13 += V_15 ;
else
V_13 += V_16 - ( V_6 -> V_8 << V_3 ) ;
return V_13 ;
}
static struct V_4 * F_9 ( unsigned long V_13 )
{
return (struct V_4 * ) ( V_13 & V_17 ) ;
}
static int F_10 ( struct V_4 * V_6 )
{
return V_18 - V_6 -> V_7 - V_6 -> V_8 - 1 ;
}
struct V_19 * F_11 ( T_1 V_20 , struct V_21 * V_22 )
{
struct V_19 * V_23 ;
int V_24 ;
V_23 = F_12 ( sizeof( struct V_19 ) , V_20 ) ;
if ( ! V_23 )
return NULL ;
F_13 ( & V_23 -> V_25 ) ;
F_14 (i, 0 )
F_4 ( & V_23 -> V_26 [ V_24 ] ) ;
F_4 ( & V_23 -> V_27 ) ;
F_4 ( & V_23 -> V_10 ) ;
V_23 -> V_28 = 0 ;
V_23 -> V_22 = V_22 ;
return V_23 ;
}
void F_15 ( struct V_19 * V_23 )
{
F_16 ( V_23 ) ;
}
int F_17 ( struct V_19 * V_23 , int V_1 , T_1 V_20 ,
unsigned long * V_13 )
{
int V_29 , V_24 , V_30 ;
struct V_4 * V_6 = NULL ;
enum V_9 V_12 ;
struct V_5 * V_5 ;
if ( V_1 <= 0 || V_20 & V_31 )
return - V_32 ;
if ( V_1 > V_16 - V_15 - V_2 )
return - V_33 ;
V_29 = F_1 ( V_1 ) ;
F_18 ( & V_23 -> V_25 ) ;
V_6 = NULL ;
F_14 (i, chunks) {
if ( ! F_19 ( & V_23 -> V_26 [ V_24 ] ) ) {
V_6 = F_20 ( & V_23 -> V_26 [ V_24 ] ,
struct V_4 , V_9 ) ;
F_21 ( & V_6 -> V_9 ) ;
if ( V_6 -> V_7 == 0 )
V_12 = V_14 ;
else
V_12 = V_34 ;
goto V_35;
}
}
F_22 ( & V_23 -> V_25 ) ;
V_5 = F_23 ( V_20 ) ;
if ( ! V_5 )
return - V_36 ;
F_18 ( & V_23 -> V_25 ) ;
V_23 -> V_28 ++ ;
V_6 = F_2 ( V_5 ) ;
V_12 = V_14 ;
V_35:
if ( V_12 == V_14 )
V_6 -> V_7 = V_29 ;
else
V_6 -> V_8 = V_29 ;
if ( V_6 -> V_7 == 0 || V_6 -> V_8 == 0 ) {
V_30 = F_10 ( V_6 ) ;
F_24 ( & V_6 -> V_9 , & V_23 -> V_26 [ V_30 ] ) ;
} else {
F_24 ( & V_6 -> V_9 , & V_23 -> V_27 ) ;
}
if ( ! F_19 ( & V_6 -> V_10 ) )
F_21 ( & V_6 -> V_10 ) ;
F_24 ( & V_6 -> V_10 , & V_23 -> V_10 ) ;
* V_13 = F_8 ( V_6 , V_12 ) ;
F_22 ( & V_23 -> V_25 ) ;
return 0 ;
}
void F_25 ( struct V_19 * V_23 , unsigned long V_13 )
{
struct V_4 * V_6 ;
int V_30 ;
F_18 ( & V_23 -> V_25 ) ;
V_6 = F_9 ( V_13 ) ;
if ( ( V_13 - V_15 ) & ~ V_17 )
V_6 -> V_8 = 0 ;
else
V_6 -> V_7 = 0 ;
if ( V_6 -> V_11 ) {
F_22 ( & V_23 -> V_25 ) ;
return;
}
F_21 ( & V_6 -> V_9 ) ;
if ( V_6 -> V_7 == 0 && V_6 -> V_8 == 0 ) {
F_21 ( & V_6 -> V_10 ) ;
F_5 ( V_6 ) ;
V_23 -> V_28 -- ;
} else {
V_30 = F_10 ( V_6 ) ;
F_24 ( & V_6 -> V_9 , & V_23 -> V_26 [ V_30 ] ) ;
}
F_22 ( & V_23 -> V_25 ) ;
}
int F_26 ( struct V_19 * V_23 , unsigned int V_37 )
{
int V_24 , V_38 , V_30 ;
struct V_4 * V_6 ;
unsigned long V_39 = 0 , V_40 = 0 ;
F_18 ( & V_23 -> V_25 ) ;
if ( ! V_23 -> V_22 || ! V_23 -> V_22 -> V_41 || F_19 ( & V_23 -> V_10 ) ||
V_37 == 0 ) {
F_22 ( & V_23 -> V_25 ) ;
return - V_32 ;
}
for ( V_24 = 0 ; V_24 < V_37 ; V_24 ++ ) {
V_6 = F_27 ( & V_23 -> V_10 , struct V_4 , V_10 ) ;
F_21 ( & V_6 -> V_10 ) ;
F_21 ( & V_6 -> V_9 ) ;
V_6 -> V_11 = true ;
V_39 = 0 ;
V_40 = 0 ;
if ( V_6 -> V_7 )
V_39 = F_8 ( V_6 , V_14 ) ;
if ( V_6 -> V_8 )
V_40 = F_8 ( V_6 , V_34 ) ;
F_22 ( & V_23 -> V_25 ) ;
if ( V_39 ) {
V_38 = V_23 -> V_22 -> V_41 ( V_23 , V_39 ) ;
if ( V_38 )
goto V_42;
}
if ( V_40 ) {
V_38 = V_23 -> V_22 -> V_41 ( V_23 , V_40 ) ;
if ( V_38 )
goto V_42;
}
V_42:
F_18 ( & V_23 -> V_25 ) ;
V_6 -> V_11 = false ;
if ( V_6 -> V_7 == 0 && V_6 -> V_8 == 0 ) {
F_5 ( V_6 ) ;
V_23 -> V_28 -- ;
F_22 ( & V_23 -> V_25 ) ;
return 0 ;
} else if ( V_6 -> V_7 == 0 ||
V_6 -> V_8 == 0 ) {
V_30 = F_10 ( V_6 ) ;
F_24 ( & V_6 -> V_9 , & V_23 -> V_26 [ V_30 ] ) ;
} else {
F_24 ( & V_6 -> V_9 , & V_23 -> V_27 ) ;
}
F_24 ( & V_6 -> V_10 , & V_23 -> V_10 ) ;
}
F_22 ( & V_23 -> V_25 ) ;
return - V_43 ;
}
void * F_28 ( struct V_19 * V_23 , unsigned long V_13 )
{
return ( void * ) ( V_13 ) ;
}
void F_29 ( struct V_19 * V_23 , unsigned long V_13 )
{
}
T_2 F_30 ( struct V_19 * V_23 )
{
return V_23 -> V_28 ;
}
static int T_3 F_31 ( void )
{
F_32 ( sizeof( struct V_4 ) > V_15 ) ;
F_33 ( L_1 ) ;
return 0 ;
}
static void T_4 F_34 ( void )
{
F_33 ( L_2 ) ;
}
