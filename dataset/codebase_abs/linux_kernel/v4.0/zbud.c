static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static void * F_3 ( char * V_4 , T_1 V_5 ,
struct V_6 * V_6 )
{
return F_4 ( V_5 , V_6 ? & V_7 : NULL ) ;
}
static void F_5 ( void * V_2 )
{
F_6 ( V_2 ) ;
}
static int F_7 ( void * V_2 , T_2 V_8 , T_1 V_5 ,
unsigned long * V_3 )
{
return F_8 ( V_2 , V_8 , V_5 , V_3 ) ;
}
static void F_9 ( void * V_2 , unsigned long V_3 )
{
F_10 ( V_2 , V_3 ) ;
}
static int F_11 ( void * V_2 , unsigned int V_9 ,
unsigned int * V_10 )
{
unsigned int V_11 = 0 ;
int V_12 = - V_13 ;
while ( V_11 < V_9 ) {
V_12 = F_12 ( V_2 , 8 ) ;
if ( V_12 < 0 )
break;
V_11 ++ ;
}
if ( V_10 )
* V_10 = V_11 ;
return V_12 ;
}
static void * F_13 ( void * V_2 , unsigned long V_3 ,
enum V_14 V_15 )
{
return F_14 ( V_2 , V_3 ) ;
}
static void F_15 ( void * V_2 , unsigned long V_3 )
{
F_16 ( V_2 , V_3 ) ;
}
static T_3 F_17 ( void * V_2 )
{
return F_18 ( V_2 ) * V_16 ;
}
static int F_19 ( T_2 V_8 )
{
return ( V_8 + V_17 - 1 ) >> V_18 ;
}
static struct V_19 * F_20 ( struct V_20 * V_20 )
{
struct V_19 * V_21 = F_21 ( V_20 ) ;
V_21 -> V_22 = 0 ;
V_21 -> V_23 = 0 ;
F_22 ( & V_21 -> V_24 ) ;
F_22 ( & V_21 -> V_25 ) ;
V_21 -> V_26 = 0 ;
return V_21 ;
}
static void F_23 ( struct V_19 * V_21 )
{
F_24 ( F_25 ( V_21 ) ) ;
}
static unsigned long F_26 ( struct V_19 * V_21 , enum V_24 V_27 )
{
unsigned long V_3 ;
V_3 = ( unsigned long ) V_21 ;
if ( V_27 == V_28 )
V_3 += V_29 ;
else
V_3 += V_16 - ( V_21 -> V_23 << V_18 ) ;
return V_3 ;
}
static struct V_19 * F_27 ( unsigned long V_3 )
{
return (struct V_19 * ) ( V_3 & V_30 ) ;
}
static int F_28 ( struct V_19 * V_21 )
{
return V_31 - V_21 -> V_22 - V_21 -> V_23 ;
}
struct V_1 * F_4 ( T_1 V_5 , struct V_32 * V_33 )
{
struct V_1 * V_2 ;
int V_34 ;
V_2 = F_29 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_2 )
return NULL ;
F_30 ( & V_2 -> V_35 ) ;
F_31 (i, 0 )
F_22 ( & V_2 -> V_36 [ V_34 ] ) ;
F_22 ( & V_2 -> V_37 ) ;
F_22 ( & V_2 -> V_25 ) ;
V_2 -> V_38 = 0 ;
V_2 -> V_33 = V_33 ;
return V_2 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
}
int F_8 ( struct V_1 * V_2 , T_2 V_8 , T_1 V_5 ,
unsigned long * V_3 )
{
int V_39 , V_34 , V_40 ;
struct V_19 * V_21 = NULL ;
enum V_24 V_27 ;
struct V_20 * V_20 ;
if ( ! V_8 || ( V_5 & V_41 ) )
return - V_13 ;
if ( V_8 > V_16 - V_29 - V_17 )
return - V_42 ;
V_39 = F_19 ( V_8 ) ;
F_33 ( & V_2 -> V_35 ) ;
V_21 = NULL ;
F_31 (i, chunks) {
if ( ! F_34 ( & V_2 -> V_36 [ V_34 ] ) ) {
V_21 = F_35 ( & V_2 -> V_36 [ V_34 ] ,
struct V_19 , V_24 ) ;
F_36 ( & V_21 -> V_24 ) ;
if ( V_21 -> V_22 == 0 )
V_27 = V_28 ;
else
V_27 = V_43 ;
goto V_44;
}
}
F_37 ( & V_2 -> V_35 ) ;
V_20 = F_38 ( V_5 ) ;
if ( ! V_20 )
return - V_45 ;
F_33 ( & V_2 -> V_35 ) ;
V_2 -> V_38 ++ ;
V_21 = F_20 ( V_20 ) ;
V_27 = V_28 ;
V_44:
if ( V_27 == V_28 )
V_21 -> V_22 = V_39 ;
else
V_21 -> V_23 = V_39 ;
if ( V_21 -> V_22 == 0 || V_21 -> V_23 == 0 ) {
V_40 = F_28 ( V_21 ) ;
F_39 ( & V_21 -> V_24 , & V_2 -> V_36 [ V_40 ] ) ;
} else {
F_39 ( & V_21 -> V_24 , & V_2 -> V_37 ) ;
}
if ( ! F_34 ( & V_21 -> V_25 ) )
F_36 ( & V_21 -> V_25 ) ;
F_39 ( & V_21 -> V_25 , & V_2 -> V_25 ) ;
* V_3 = F_26 ( V_21 , V_27 ) ;
F_37 ( & V_2 -> V_35 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_19 * V_21 ;
int V_40 ;
F_33 ( & V_2 -> V_35 ) ;
V_21 = F_27 ( V_3 ) ;
if ( ( V_3 - V_29 ) & ~ V_30 )
V_21 -> V_23 = 0 ;
else
V_21 -> V_22 = 0 ;
if ( V_21 -> V_26 ) {
F_37 ( & V_2 -> V_35 ) ;
return;
}
F_36 ( & V_21 -> V_24 ) ;
if ( V_21 -> V_22 == 0 && V_21 -> V_23 == 0 ) {
F_36 ( & V_21 -> V_25 ) ;
F_23 ( V_21 ) ;
V_2 -> V_38 -- ;
} else {
V_40 = F_28 ( V_21 ) ;
F_39 ( & V_21 -> V_24 , & V_2 -> V_36 [ V_40 ] ) ;
}
F_37 ( & V_2 -> V_35 ) ;
}
int F_12 ( struct V_1 * V_2 , unsigned int V_46 )
{
int V_34 , V_12 , V_40 ;
struct V_19 * V_21 ;
unsigned long V_47 = 0 , V_48 = 0 ;
F_33 ( & V_2 -> V_35 ) ;
if ( ! V_2 -> V_33 || ! V_2 -> V_33 -> V_49 || F_34 ( & V_2 -> V_25 ) ||
V_46 == 0 ) {
F_37 ( & V_2 -> V_35 ) ;
return - V_13 ;
}
for ( V_34 = 0 ; V_34 < V_46 ; V_34 ++ ) {
V_21 = F_40 ( & V_2 -> V_25 , struct V_19 , V_25 ) ;
F_36 ( & V_21 -> V_25 ) ;
F_36 ( & V_21 -> V_24 ) ;
V_21 -> V_26 = true ;
V_47 = 0 ;
V_48 = 0 ;
if ( V_21 -> V_22 )
V_47 = F_26 ( V_21 , V_28 ) ;
if ( V_21 -> V_23 )
V_48 = F_26 ( V_21 , V_43 ) ;
F_37 ( & V_2 -> V_35 ) ;
if ( V_47 ) {
V_12 = V_2 -> V_33 -> V_49 ( V_2 , V_47 ) ;
if ( V_12 )
goto V_50;
}
if ( V_48 ) {
V_12 = V_2 -> V_33 -> V_49 ( V_2 , V_48 ) ;
if ( V_12 )
goto V_50;
}
V_50:
F_33 ( & V_2 -> V_35 ) ;
V_21 -> V_26 = false ;
if ( V_21 -> V_22 == 0 && V_21 -> V_23 == 0 ) {
F_23 ( V_21 ) ;
V_2 -> V_38 -- ;
F_37 ( & V_2 -> V_35 ) ;
return 0 ;
} else if ( V_21 -> V_22 == 0 ||
V_21 -> V_23 == 0 ) {
V_40 = F_28 ( V_21 ) ;
F_39 ( & V_21 -> V_24 , & V_2 -> V_36 [ V_40 ] ) ;
} else {
F_39 ( & V_21 -> V_24 , & V_2 -> V_37 ) ;
}
F_39 ( & V_21 -> V_25 , & V_2 -> V_25 ) ;
}
F_37 ( & V_2 -> V_35 ) ;
return - V_51 ;
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
return V_2 -> V_38 ;
}
static int T_4 F_41 ( void )
{
F_42 ( sizeof( struct V_19 ) > V_29 ) ;
F_43 ( L_1 ) ;
#ifdef F_44
F_45 ( & V_52 ) ;
#endif
return 0 ;
}
static void T_5 F_46 ( void )
{
#ifdef F_44
F_47 ( & V_52 ) ;
#endif
F_43 ( L_2 ) ;
}
