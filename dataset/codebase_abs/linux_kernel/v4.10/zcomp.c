static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 -> V_3 ) )
F_3 ( V_2 -> V_3 ) ;
F_4 ( ( unsigned long ) V_2 -> V_4 , 1 ) ;
F_5 ( V_2 ) ;
}
static struct V_1 * F_6 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( sizeof( * V_2 ) , V_7 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_3 = F_8 ( V_6 -> V_8 , 0 , 0 ) ;
V_2 -> V_4 = ( void * ) F_9 ( V_7 | V_9 , 1 ) ;
if ( F_2 ( V_2 -> V_3 ) || ! V_2 -> V_4 ) {
F_1 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
bool F_10 ( const char * V_6 )
{
int V_10 = 0 ;
while ( V_11 [ V_10 ] ) {
if ( F_11 ( V_6 , V_11 [ V_10 ] ) )
return true ;
V_10 ++ ;
}
return F_12 ( V_6 , 0 , 0 ) == 1 ;
}
T_1 F_13 ( const char * V_6 , char * V_12 )
{
bool V_13 = false ;
T_1 V_14 = 0 ;
int V_10 = 0 ;
for (; V_11 [ V_10 ] ; V_10 ++ ) {
if ( ! strcmp ( V_6 , V_11 [ V_10 ] ) ) {
V_13 = true ;
V_14 += F_14 ( V_12 + V_14 , V_15 - V_14 - 2 ,
L_1 , V_11 [ V_10 ] ) ;
} else {
V_14 += F_14 ( V_12 + V_14 , V_15 - V_14 - 2 ,
L_2 , V_11 [ V_10 ] ) ;
}
}
if ( ! V_13 && F_12 ( V_6 , 0 , 0 ) == 1 )
V_14 += F_14 ( V_12 + V_14 , V_15 - V_14 - 2 ,
L_1 , V_6 ) ;
V_14 += F_14 ( V_12 + V_14 , V_15 - V_14 , L_3 ) ;
return V_14 ;
}
struct V_1 * F_15 ( struct V_5 * V_6 )
{
return * F_16 ( V_6 -> V_16 ) ;
}
void F_17 ( struct V_5 * V_6 )
{
F_18 ( V_6 -> V_16 ) ;
}
int F_19 ( struct V_1 * V_2 ,
const void * V_17 , unsigned int * V_18 )
{
* V_18 = V_15 * 2 ;
return F_20 ( V_2 -> V_3 ,
V_17 , V_15 ,
V_2 -> V_4 , V_18 ) ;
}
int F_21 ( struct V_1 * V_2 ,
const void * V_17 , unsigned int V_19 , void * V_20 )
{
unsigned int V_18 = V_15 ;
return F_22 ( V_2 -> V_3 ,
V_17 , V_19 ,
V_20 , & V_18 ) ;
}
int F_23 ( unsigned int V_21 , struct V_22 * V_23 )
{
struct V_5 * V_6 = F_24 ( V_23 , struct V_5 , V_23 ) ;
struct V_1 * V_2 ;
if ( F_25 ( * F_26 ( V_6 -> V_16 , V_21 ) ) )
return 0 ;
V_2 = F_6 ( V_6 ) ;
if ( F_2 ( V_2 ) ) {
F_27 ( L_4 ) ;
return - V_24 ;
}
* F_26 ( V_6 -> V_16 , V_21 ) = V_2 ;
return 0 ;
}
int F_28 ( unsigned int V_21 , struct V_22 * V_23 )
{
struct V_5 * V_6 = F_24 ( V_23 , struct V_5 , V_23 ) ;
struct V_1 * V_2 ;
V_2 = * F_26 ( V_6 -> V_16 , V_21 ) ;
if ( ! F_2 ( V_2 ) )
F_1 ( V_2 ) ;
* F_26 ( V_6 -> V_16 , V_21 ) = NULL ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 )
{
int V_25 ;
V_6 -> V_16 = F_30 ( struct V_1 * ) ;
if ( ! V_6 -> V_16 )
return - V_24 ;
V_25 = F_31 ( V_26 , & V_6 -> V_23 ) ;
if ( V_25 < 0 )
goto V_27;
return 0 ;
V_27:
F_32 ( V_6 -> V_16 ) ;
return V_25 ;
}
void F_33 ( struct V_5 * V_6 )
{
F_34 ( V_26 , & V_6 -> V_23 ) ;
F_32 ( V_6 -> V_16 ) ;
F_5 ( V_6 ) ;
}
struct V_5 * F_35 ( const char * V_28 )
{
struct V_5 * V_6 ;
int error ;
if ( ! F_10 ( V_28 ) )
return F_36 ( - V_29 ) ;
V_6 = F_37 ( sizeof( struct V_5 ) , V_7 ) ;
if ( ! V_6 )
return F_36 ( - V_24 ) ;
V_6 -> V_8 = V_28 ;
error = F_29 ( V_6 ) ;
if ( error ) {
F_5 ( V_6 ) ;
return F_36 ( error ) ;
}
return V_6 ;
}
