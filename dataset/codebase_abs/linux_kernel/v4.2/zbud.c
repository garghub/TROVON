static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
if ( V_2 -> V_4 && V_2 -> V_5 && V_2 -> V_5 -> V_6 )
return V_2 -> V_5 -> V_6 ( V_2 -> V_4 , V_3 ) ;
else
return - V_7 ;
}
static void * F_2 ( char * V_8 , T_1 V_9 ,
struct V_5 * V_5 ,
struct V_4 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_3 ( V_9 , V_5 ? & V_10 : NULL ) ;
if ( V_2 ) {
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
}
return V_2 ;
}
static void F_4 ( void * V_2 )
{
F_5 ( V_2 ) ;
}
static int F_6 ( void * V_2 , T_2 V_11 , T_1 V_9 ,
unsigned long * V_3 )
{
return F_7 ( V_2 , V_11 , V_9 , V_3 ) ;
}
static void F_8 ( void * V_2 , unsigned long V_3 )
{
F_9 ( V_2 , V_3 ) ;
}
static int F_10 ( void * V_2 , unsigned int V_12 ,
unsigned int * V_13 )
{
unsigned int V_14 = 0 ;
int V_15 = - V_16 ;
while ( V_14 < V_12 ) {
V_15 = F_11 ( V_2 , 8 ) ;
if ( V_15 < 0 )
break;
V_14 ++ ;
}
if ( V_13 )
* V_13 = V_14 ;
return V_15 ;
}
static void * F_12 ( void * V_2 , unsigned long V_3 ,
enum V_17 V_18 )
{
return F_13 ( V_2 , V_3 ) ;
}
static void F_14 ( void * V_2 , unsigned long V_3 )
{
F_15 ( V_2 , V_3 ) ;
}
static T_3 F_16 ( void * V_2 )
{
return F_17 ( V_2 ) * V_19 ;
}
static int F_18 ( T_2 V_11 )
{
return ( V_11 + V_20 - 1 ) >> V_21 ;
}
static struct V_22 * F_19 ( struct V_23 * V_23 )
{
struct V_22 * V_24 = F_20 ( V_23 ) ;
V_24 -> V_25 = 0 ;
V_24 -> V_26 = 0 ;
F_21 ( & V_24 -> V_27 ) ;
F_21 ( & V_24 -> V_28 ) ;
V_24 -> V_29 = 0 ;
return V_24 ;
}
static void F_22 ( struct V_22 * V_24 )
{
F_23 ( F_24 ( V_24 ) ) ;
}
static unsigned long F_25 ( struct V_22 * V_24 , enum V_27 V_30 )
{
unsigned long V_3 ;
V_3 = ( unsigned long ) V_24 ;
if ( V_30 == V_31 )
V_3 += V_32 ;
else
V_3 += V_19 - ( V_24 -> V_26 << V_21 ) ;
return V_3 ;
}
static struct V_22 * F_26 ( unsigned long V_3 )
{
return (struct V_22 * ) ( V_3 & V_33 ) ;
}
static int F_27 ( struct V_22 * V_24 )
{
return V_34 - V_24 -> V_25 - V_24 -> V_26 ;
}
struct V_1 * F_3 ( T_1 V_9 , struct V_35 * V_36 )
{
struct V_1 * V_2 ;
int V_37 ;
V_2 = F_28 ( sizeof( struct V_1 ) , V_9 ) ;
if ( ! V_2 )
return NULL ;
F_29 ( & V_2 -> V_38 ) ;
F_30 (i, 0 )
F_21 ( & V_2 -> V_39 [ V_37 ] ) ;
F_21 ( & V_2 -> V_40 ) ;
F_21 ( & V_2 -> V_28 ) ;
V_2 -> V_41 = 0 ;
V_2 -> V_36 = V_36 ;
return V_2 ;
}
void F_5 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
}
int F_7 ( struct V_1 * V_2 , T_2 V_11 , T_1 V_9 ,
unsigned long * V_3 )
{
int V_42 , V_37 , V_43 ;
struct V_22 * V_24 = NULL ;
enum V_27 V_30 ;
struct V_23 * V_23 ;
if ( ! V_11 || ( V_9 & V_44 ) )
return - V_16 ;
if ( V_11 > V_19 - V_32 - V_20 )
return - V_45 ;
V_42 = F_18 ( V_11 ) ;
F_32 ( & V_2 -> V_38 ) ;
V_24 = NULL ;
F_30 (i, chunks) {
if ( ! F_33 ( & V_2 -> V_39 [ V_37 ] ) ) {
V_24 = F_34 ( & V_2 -> V_39 [ V_37 ] ,
struct V_22 , V_27 ) ;
F_35 ( & V_24 -> V_27 ) ;
if ( V_24 -> V_25 == 0 )
V_30 = V_31 ;
else
V_30 = V_46 ;
goto V_47;
}
}
F_36 ( & V_2 -> V_38 ) ;
V_23 = F_37 ( V_9 ) ;
if ( ! V_23 )
return - V_48 ;
F_32 ( & V_2 -> V_38 ) ;
V_2 -> V_41 ++ ;
V_24 = F_19 ( V_23 ) ;
V_30 = V_31 ;
V_47:
if ( V_30 == V_31 )
V_24 -> V_25 = V_42 ;
else
V_24 -> V_26 = V_42 ;
if ( V_24 -> V_25 == 0 || V_24 -> V_26 == 0 ) {
V_43 = F_27 ( V_24 ) ;
F_38 ( & V_24 -> V_27 , & V_2 -> V_39 [ V_43 ] ) ;
} else {
F_38 ( & V_24 -> V_27 , & V_2 -> V_40 ) ;
}
if ( ! F_33 ( & V_24 -> V_28 ) )
F_35 ( & V_24 -> V_28 ) ;
F_38 ( & V_24 -> V_28 , & V_2 -> V_28 ) ;
* V_3 = F_25 ( V_24 , V_30 ) ;
F_36 ( & V_2 -> V_38 ) ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_22 * V_24 ;
int V_43 ;
F_32 ( & V_2 -> V_38 ) ;
V_24 = F_26 ( V_3 ) ;
if ( ( V_3 - V_32 ) & ~ V_33 )
V_24 -> V_26 = 0 ;
else
V_24 -> V_25 = 0 ;
if ( V_24 -> V_29 ) {
F_36 ( & V_2 -> V_38 ) ;
return;
}
F_35 ( & V_24 -> V_27 ) ;
if ( V_24 -> V_25 == 0 && V_24 -> V_26 == 0 ) {
F_35 ( & V_24 -> V_28 ) ;
F_22 ( V_24 ) ;
V_2 -> V_41 -- ;
} else {
V_43 = F_27 ( V_24 ) ;
F_38 ( & V_24 -> V_27 , & V_2 -> V_39 [ V_43 ] ) ;
}
F_36 ( & V_2 -> V_38 ) ;
}
int F_11 ( struct V_1 * V_2 , unsigned int V_49 )
{
int V_37 , V_15 , V_43 ;
struct V_22 * V_24 ;
unsigned long V_50 = 0 , V_51 = 0 ;
F_32 ( & V_2 -> V_38 ) ;
if ( ! V_2 -> V_36 || ! V_2 -> V_36 -> V_6 || F_33 ( & V_2 -> V_28 ) ||
V_49 == 0 ) {
F_36 ( & V_2 -> V_38 ) ;
return - V_16 ;
}
for ( V_37 = 0 ; V_37 < V_49 ; V_37 ++ ) {
V_24 = F_39 ( & V_2 -> V_28 , struct V_22 , V_28 ) ;
F_35 ( & V_24 -> V_28 ) ;
F_35 ( & V_24 -> V_27 ) ;
V_24 -> V_29 = true ;
V_50 = 0 ;
V_51 = 0 ;
if ( V_24 -> V_25 )
V_50 = F_25 ( V_24 , V_31 ) ;
if ( V_24 -> V_26 )
V_51 = F_25 ( V_24 , V_46 ) ;
F_36 ( & V_2 -> V_38 ) ;
if ( V_50 ) {
V_15 = V_2 -> V_36 -> V_6 ( V_2 , V_50 ) ;
if ( V_15 )
goto V_52;
}
if ( V_51 ) {
V_15 = V_2 -> V_36 -> V_6 ( V_2 , V_51 ) ;
if ( V_15 )
goto V_52;
}
V_52:
F_32 ( & V_2 -> V_38 ) ;
V_24 -> V_29 = false ;
if ( V_24 -> V_25 == 0 && V_24 -> V_26 == 0 ) {
F_22 ( V_24 ) ;
V_2 -> V_41 -- ;
F_36 ( & V_2 -> V_38 ) ;
return 0 ;
} else if ( V_24 -> V_25 == 0 ||
V_24 -> V_26 == 0 ) {
V_43 = F_27 ( V_24 ) ;
F_38 ( & V_24 -> V_27 , & V_2 -> V_39 [ V_43 ] ) ;
} else {
F_38 ( & V_24 -> V_27 , & V_2 -> V_40 ) ;
}
F_38 ( & V_24 -> V_28 , & V_2 -> V_28 ) ;
}
F_36 ( & V_2 -> V_38 ) ;
return - V_53 ;
}
void * F_13 ( struct V_1 * V_2 , unsigned long V_3 )
{
return ( void * ) ( V_3 ) ;
}
void F_15 ( struct V_1 * V_2 , unsigned long V_3 )
{
}
T_3 F_17 ( struct V_1 * V_2 )
{
return V_2 -> V_41 ;
}
static int T_4 F_40 ( void )
{
F_41 ( sizeof( struct V_22 ) > V_32 ) ;
F_42 ( L_1 ) ;
#ifdef F_43
F_44 ( & V_54 ) ;
#endif
return 0 ;
}
static void T_5 F_45 ( void )
{
#ifdef F_43
F_46 ( & V_54 ) ;
#endif
F_42 ( L_2 ) ;
}
