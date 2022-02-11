static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static void * F_3 ( T_1 V_4 , struct V_5 * V_5 )
{
return F_4 ( V_4 , & V_6 ) ;
}
static void F_5 ( void * V_2 )
{
F_6 ( V_2 ) ;
}
static int F_7 ( void * V_2 , T_2 V_7 , T_1 V_4 ,
unsigned long * V_3 )
{
return F_8 ( V_2 , V_7 , V_4 , V_3 ) ;
}
static void F_9 ( void * V_2 , unsigned long V_3 )
{
F_10 ( V_2 , V_3 ) ;
}
static int F_11 ( void * V_2 , unsigned int V_8 ,
unsigned int * V_9 )
{
unsigned int V_10 = 0 ;
int V_11 = - V_12 ;
while ( V_10 < V_8 ) {
V_11 = F_12 ( V_2 , 8 ) ;
if ( V_11 < 0 )
break;
V_10 ++ ;
}
if ( V_9 )
* V_9 = V_10 ;
return V_11 ;
}
static void * F_13 ( void * V_2 , unsigned long V_3 ,
enum V_13 V_14 )
{
return F_14 ( V_2 , V_3 ) ;
}
static void F_15 ( void * V_2 , unsigned long V_3 )
{
F_16 ( V_2 , V_3 ) ;
}
static T_3 F_17 ( void * V_2 )
{
return F_18 ( V_2 ) * V_15 ;
}
static int F_19 ( T_2 V_7 )
{
return ( V_7 + V_16 - 1 ) >> V_17 ;
}
static struct V_18 * F_20 ( struct V_19 * V_19 )
{
struct V_18 * V_20 = F_21 ( V_19 ) ;
V_20 -> V_21 = 0 ;
V_20 -> V_22 = 0 ;
F_22 ( & V_20 -> V_23 ) ;
F_22 ( & V_20 -> V_24 ) ;
V_20 -> V_25 = 0 ;
return V_20 ;
}
static void F_23 ( struct V_18 * V_20 )
{
F_24 ( F_25 ( V_20 ) ) ;
}
static unsigned long F_26 ( struct V_18 * V_20 , enum V_23 V_26 )
{
unsigned long V_3 ;
V_3 = ( unsigned long ) V_20 ;
if ( V_26 == V_27 )
V_3 += V_28 ;
else
V_3 += V_15 - ( V_20 -> V_22 << V_17 ) ;
return V_3 ;
}
static struct V_18 * F_27 ( unsigned long V_3 )
{
return (struct V_18 * ) ( V_3 & V_29 ) ;
}
static int F_28 ( struct V_18 * V_20 )
{
return V_30 - V_20 -> V_21 - V_20 -> V_22 - 1 ;
}
struct V_1 * F_4 ( T_1 V_4 , struct V_31 * V_32 )
{
struct V_1 * V_2 ;
int V_33 ;
V_2 = F_29 ( sizeof( struct V_1 ) , V_4 ) ;
if ( ! V_2 )
return NULL ;
F_30 ( & V_2 -> V_34 ) ;
F_31 (i, 0 )
F_22 ( & V_2 -> V_35 [ V_33 ] ) ;
F_22 ( & V_2 -> V_36 ) ;
F_22 ( & V_2 -> V_24 ) ;
V_2 -> V_37 = 0 ;
V_2 -> V_32 = V_32 ;
return V_2 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
}
int F_8 ( struct V_1 * V_2 , T_2 V_7 , T_1 V_4 ,
unsigned long * V_3 )
{
int V_38 , V_33 , V_39 ;
struct V_18 * V_20 = NULL ;
enum V_23 V_26 ;
struct V_19 * V_19 ;
if ( ! V_7 || ( V_4 & V_40 ) )
return - V_12 ;
if ( V_7 > V_15 - V_28 - V_16 )
return - V_41 ;
V_38 = F_19 ( V_7 ) ;
F_33 ( & V_2 -> V_34 ) ;
V_20 = NULL ;
F_31 (i, chunks) {
if ( ! F_34 ( & V_2 -> V_35 [ V_33 ] ) ) {
V_20 = F_35 ( & V_2 -> V_35 [ V_33 ] ,
struct V_18 , V_23 ) ;
F_36 ( & V_20 -> V_23 ) ;
if ( V_20 -> V_21 == 0 )
V_26 = V_27 ;
else
V_26 = V_42 ;
goto V_43;
}
}
F_37 ( & V_2 -> V_34 ) ;
V_19 = F_38 ( V_4 ) ;
if ( ! V_19 )
return - V_44 ;
F_33 ( & V_2 -> V_34 ) ;
V_2 -> V_37 ++ ;
V_20 = F_20 ( V_19 ) ;
V_26 = V_27 ;
V_43:
if ( V_26 == V_27 )
V_20 -> V_21 = V_38 ;
else
V_20 -> V_22 = V_38 ;
if ( V_20 -> V_21 == 0 || V_20 -> V_22 == 0 ) {
V_39 = F_28 ( V_20 ) ;
F_39 ( & V_20 -> V_23 , & V_2 -> V_35 [ V_39 ] ) ;
} else {
F_39 ( & V_20 -> V_23 , & V_2 -> V_36 ) ;
}
if ( ! F_34 ( & V_20 -> V_24 ) )
F_36 ( & V_20 -> V_24 ) ;
F_39 ( & V_20 -> V_24 , & V_2 -> V_24 ) ;
* V_3 = F_26 ( V_20 , V_26 ) ;
F_37 ( & V_2 -> V_34 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_18 * V_20 ;
int V_39 ;
F_33 ( & V_2 -> V_34 ) ;
V_20 = F_27 ( V_3 ) ;
if ( ( V_3 - V_28 ) & ~ V_29 )
V_20 -> V_22 = 0 ;
else
V_20 -> V_21 = 0 ;
if ( V_20 -> V_25 ) {
F_37 ( & V_2 -> V_34 ) ;
return;
}
F_36 ( & V_20 -> V_23 ) ;
if ( V_20 -> V_21 == 0 && V_20 -> V_22 == 0 ) {
F_36 ( & V_20 -> V_24 ) ;
F_23 ( V_20 ) ;
V_2 -> V_37 -- ;
} else {
V_39 = F_28 ( V_20 ) ;
F_39 ( & V_20 -> V_23 , & V_2 -> V_35 [ V_39 ] ) ;
}
F_37 ( & V_2 -> V_34 ) ;
}
int F_12 ( struct V_1 * V_2 , unsigned int V_45 )
{
int V_33 , V_11 , V_39 ;
struct V_18 * V_20 ;
unsigned long V_46 = 0 , V_47 = 0 ;
F_33 ( & V_2 -> V_34 ) ;
if ( ! V_2 -> V_32 || ! V_2 -> V_32 -> V_48 || F_34 ( & V_2 -> V_24 ) ||
V_45 == 0 ) {
F_37 ( & V_2 -> V_34 ) ;
return - V_12 ;
}
for ( V_33 = 0 ; V_33 < V_45 ; V_33 ++ ) {
V_20 = F_40 ( & V_2 -> V_24 , struct V_18 , V_24 ) ;
F_36 ( & V_20 -> V_24 ) ;
F_36 ( & V_20 -> V_23 ) ;
V_20 -> V_25 = true ;
V_46 = 0 ;
V_47 = 0 ;
if ( V_20 -> V_21 )
V_46 = F_26 ( V_20 , V_27 ) ;
if ( V_20 -> V_22 )
V_47 = F_26 ( V_20 , V_42 ) ;
F_37 ( & V_2 -> V_34 ) ;
if ( V_46 ) {
V_11 = V_2 -> V_32 -> V_48 ( V_2 , V_46 ) ;
if ( V_11 )
goto V_49;
}
if ( V_47 ) {
V_11 = V_2 -> V_32 -> V_48 ( V_2 , V_47 ) ;
if ( V_11 )
goto V_49;
}
V_49:
F_33 ( & V_2 -> V_34 ) ;
V_20 -> V_25 = false ;
if ( V_20 -> V_21 == 0 && V_20 -> V_22 == 0 ) {
F_23 ( V_20 ) ;
V_2 -> V_37 -- ;
F_37 ( & V_2 -> V_34 ) ;
return 0 ;
} else if ( V_20 -> V_21 == 0 ||
V_20 -> V_22 == 0 ) {
V_39 = F_28 ( V_20 ) ;
F_39 ( & V_20 -> V_23 , & V_2 -> V_35 [ V_39 ] ) ;
} else {
F_39 ( & V_20 -> V_23 , & V_2 -> V_36 ) ;
}
F_39 ( & V_20 -> V_24 , & V_2 -> V_24 ) ;
}
F_37 ( & V_2 -> V_34 ) ;
return - V_50 ;
}
void * F_14 ( struct V_1 * V_2 , unsigned long V_3 )
{
return ( void * ) ( V_3 ) ;
}
void F_16 ( struct V_1 * V_2 , unsigned long V_3 )
{
}
T_3 F_18 ( struct V_1 * V_2 )
{
return V_2 -> V_37 ;
}
static int T_4 F_41 ( void )
{
F_42 ( sizeof( struct V_18 ) > V_28 ) ;
F_43 ( L_1 ) ;
#ifdef F_44
F_45 ( & V_51 ) ;
#endif
return 0 ;
}
static void T_5 F_46 ( void )
{
#ifdef F_44
F_47 ( & V_51 ) ;
#endif
F_43 ( L_2 ) ;
}
