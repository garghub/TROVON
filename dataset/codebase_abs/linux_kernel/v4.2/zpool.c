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
static struct V_1 * F_10 ( char * type )
{
struct V_1 * V_2 ;
F_2 ( & V_3 ) ;
F_11 (driver, &drivers_head, list) {
if ( ! strcmp ( V_2 -> type , type ) ) {
bool V_9 = F_12 ( V_2 -> V_10 ) ;
if ( V_9 )
F_13 ( & V_2 -> V_4 ) ;
F_5 ( & V_3 ) ;
return V_9 ? V_2 : NULL ;
}
}
F_5 ( & V_3 ) ;
return NULL ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_4 ) ;
F_16 ( V_2 -> V_10 ) ;
}
struct V_11 * F_17 ( char * type , char * V_12 , T_1 V_13 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 ;
struct V_11 * V_11 ;
F_18 ( L_1 , type ) ;
V_2 = F_10 ( type ) ;
if ( ! V_2 ) {
F_19 ( L_2 , type ) ;
V_2 = F_10 ( type ) ;
}
if ( ! V_2 ) {
F_20 ( L_3 , type ) ;
return NULL ;
}
V_11 = F_21 ( sizeof( * V_11 ) , V_13 ) ;
if ( ! V_11 ) {
F_20 ( L_4 ) ;
F_14 ( V_2 ) ;
return NULL ;
}
V_11 -> type = V_2 -> type ;
V_11 -> V_2 = V_2 ;
V_11 -> V_16 = V_2 -> V_17 ( V_12 , V_13 , V_15 , V_11 ) ;
V_11 -> V_15 = V_15 ;
if ( ! V_11 -> V_16 ) {
F_20 ( L_5 , type ) ;
F_14 ( V_2 ) ;
F_22 ( V_11 ) ;
return NULL ;
}
F_18 ( L_6 , type ) ;
F_2 ( & V_18 ) ;
F_4 ( & V_11 -> V_5 , & V_19 ) ;
F_5 ( & V_18 ) ;
return V_11 ;
}
void F_23 ( struct V_11 * V_11 )
{
F_18 ( L_7 , V_11 -> type ) ;
F_2 ( & V_18 ) ;
F_9 ( & V_11 -> V_5 ) ;
F_5 ( & V_18 ) ;
V_11 -> V_2 -> V_20 ( V_11 -> V_16 ) ;
F_14 ( V_11 -> V_2 ) ;
F_22 ( V_11 ) ;
}
char * F_24 ( struct V_11 * V_11 )
{
return V_11 -> type ;
}
int F_25 ( struct V_11 * V_11 , T_2 V_21 , T_1 V_13 ,
unsigned long * V_22 )
{
return V_11 -> V_2 -> malloc ( V_11 -> V_16 , V_21 , V_13 , V_22 ) ;
}
void F_26 ( struct V_11 * V_11 , unsigned long V_22 )
{
V_11 -> V_2 -> free ( V_11 -> V_16 , V_22 ) ;
}
int F_27 ( struct V_11 * V_11 , unsigned int V_23 ,
unsigned int * V_24 )
{
return V_11 -> V_2 -> V_25 ( V_11 -> V_16 , V_23 , V_24 ) ;
}
void * F_28 ( struct V_11 * V_11 , unsigned long V_22 ,
enum V_26 V_27 )
{
return V_11 -> V_2 -> V_28 ( V_11 -> V_16 , V_22 , V_27 ) ;
}
void F_29 ( struct V_11 * V_11 , unsigned long V_22 )
{
V_11 -> V_2 -> V_29 ( V_11 -> V_16 , V_22 ) ;
}
T_3 F_30 ( struct V_11 * V_11 )
{
return V_11 -> V_2 -> V_30 ( V_11 -> V_16 ) ;
}
static int T_4 F_31 ( void )
{
F_32 ( L_8 ) ;
return 0 ;
}
static void T_5 F_33 ( void )
{
F_32 ( L_9 ) ;
}
