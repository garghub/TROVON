void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , 0 ) ;
F_4 ( & V_2 -> V_5 , & V_6 ) ;
F_5 ( & V_3 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_7 = 0 , V_4 ;
F_2 ( & V_3 ) ;
V_4 = F_7 ( & V_2 -> V_4 ) ;
F_8 ( V_4 < 0 ) ;
if ( V_4 > 0 )
V_7 = - V_8 ;
else
F_9 ( & V_2 -> V_5 ) ;
F_5 ( & V_3 ) ;
return V_7 ;
}
int F_10 ( void * V_9 , unsigned long V_10 )
{
struct V_11 * V_11 ;
F_2 ( & V_12 ) ;
F_11 (zpool, &pools_head, list) {
if ( V_11 -> V_9 == V_9 ) {
F_5 ( & V_12 ) ;
if ( ! V_11 -> V_13 || ! V_11 -> V_13 -> V_14 )
return - V_15 ;
return V_11 -> V_13 -> V_14 ( V_11 , V_10 ) ;
}
}
F_5 ( & V_12 ) ;
return - V_16 ;
}
static struct V_1 * F_12 ( char * type )
{
struct V_1 * V_2 ;
F_2 ( & V_3 ) ;
F_11 (driver, &drivers_head, list) {
if ( ! strcmp ( V_2 -> type , type ) ) {
bool V_17 = F_13 ( V_2 -> V_18 ) ;
if ( V_17 )
F_14 ( & V_2 -> V_4 ) ;
F_5 ( & V_3 ) ;
return V_17 ? V_2 : NULL ;
}
}
F_5 ( & V_3 ) ;
return NULL ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_4 ) ;
F_17 ( V_2 -> V_18 ) ;
}
struct V_11 * F_18 ( char * type , T_1 V_19 , struct V_20 * V_13 )
{
struct V_1 * V_2 ;
struct V_11 * V_11 ;
F_19 ( L_1 , type ) ;
V_2 = F_12 ( type ) ;
if ( ! V_2 ) {
F_20 ( L_2 , type ) ;
V_2 = F_12 ( type ) ;
}
if ( ! V_2 ) {
F_21 ( L_3 , type ) ;
return NULL ;
}
V_11 = F_22 ( sizeof( * V_11 ) , V_19 ) ;
if ( ! V_11 ) {
F_21 ( L_4 ) ;
F_15 ( V_2 ) ;
return NULL ;
}
V_11 -> type = V_2 -> type ;
V_11 -> V_2 = V_2 ;
V_11 -> V_9 = V_2 -> V_21 ( V_19 , V_13 ) ;
V_11 -> V_13 = V_13 ;
if ( ! V_11 -> V_9 ) {
F_21 ( L_5 , type ) ;
F_15 ( V_2 ) ;
F_23 ( V_11 ) ;
return NULL ;
}
F_19 ( L_6 , type ) ;
F_2 ( & V_12 ) ;
F_4 ( & V_11 -> V_5 , & V_22 ) ;
F_5 ( & V_12 ) ;
return V_11 ;
}
void F_24 ( struct V_11 * V_11 )
{
F_19 ( L_7 , V_11 -> type ) ;
F_2 ( & V_12 ) ;
F_9 ( & V_11 -> V_5 ) ;
F_5 ( & V_12 ) ;
V_11 -> V_2 -> V_23 ( V_11 -> V_9 ) ;
F_15 ( V_11 -> V_2 ) ;
F_23 ( V_11 ) ;
}
char * F_25 ( struct V_11 * V_11 )
{
return V_11 -> type ;
}
int F_26 ( struct V_11 * V_11 , T_2 V_24 , T_1 V_19 ,
unsigned long * V_10 )
{
return V_11 -> V_2 -> malloc ( V_11 -> V_9 , V_24 , V_19 , V_10 ) ;
}
void F_27 ( struct V_11 * V_11 , unsigned long V_10 )
{
V_11 -> V_2 -> free ( V_11 -> V_9 , V_10 ) ;
}
int F_28 ( struct V_11 * V_11 , unsigned int V_25 ,
unsigned int * V_26 )
{
return V_11 -> V_2 -> V_27 ( V_11 -> V_9 , V_25 , V_26 ) ;
}
void * F_29 ( struct V_11 * V_11 , unsigned long V_10 ,
enum V_28 V_29 )
{
return V_11 -> V_2 -> V_30 ( V_11 -> V_9 , V_10 , V_29 ) ;
}
void F_30 ( struct V_11 * V_11 , unsigned long V_10 )
{
V_11 -> V_2 -> V_31 ( V_11 -> V_9 , V_10 ) ;
}
T_3 F_31 ( struct V_11 * V_11 )
{
return V_11 -> V_2 -> V_32 ( V_11 -> V_9 ) ;
}
static int T_4 F_32 ( void )
{
F_19 ( L_8 ) ;
return 0 ;
}
static void T_5 F_33 ( void )
{
F_19 ( L_9 ) ;
}
