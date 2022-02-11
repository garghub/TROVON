T_1 F_1 ( T_1 V_1 , unsigned int V_2 )
{
return F_2 ( V_1 , V_2 ) ;
}
void * F_3 ( unsigned int V_3 )
{
return F_4 ( V_3 , V_4 ) ;
}
void F_5 ( void * V_5 )
{
F_6 ( V_5 ) ;
}
int F_7 ( void )
{
return V_6 ;
}
void F_8 ( char * V_7 )
{
F_9 ( V_7 ) ;
}
void F_10 ( void * V_8 , const void * V_9 , unsigned int V_10 )
{
memcpy ( V_8 , V_9 , V_10 ) ;
}
void F_11 ( T_1 * V_11 )
{
struct V_12 V_13 ;
T_1 V_14 = 0 ;
V_14 = F_12 () ;
if ( ( 0 == V_14 ) &&
( 0 == F_13 ( & V_13 ) ) ) {
V_14 = V_13 . V_15 ;
V_14 = V_14 << 32 ;
V_14 = V_14 | V_13 . V_16 ;
}
* V_11 = V_14 ;
}
static int F_14 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_15 ( V_18 ) ;
int V_21 = 0 ;
V_20 -> V_22 = F_16 ( 1 , 0 ) ;
if ( ! V_20 -> V_22 )
V_21 = - V_23 ;
F_17 ( & V_20 -> V_24 ) ;
return V_21 ;
}
static void F_18 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_15 ( V_18 ) ;
F_19 ( & V_20 -> V_24 ) ;
if ( V_20 -> V_22 )
F_20 ( V_20 -> V_22 ) ;
V_20 -> V_22 = NULL ;
F_21 ( & V_20 -> V_24 ) ;
}
static int F_22 ( struct V_25 * V_18 ,
const T_2 * V_9 , unsigned int V_26 ,
T_2 * V_27 , unsigned int V_28 )
{
struct V_19 * V_20 = F_23 ( V_18 ) ;
int V_21 = 0 ;
F_19 ( & V_20 -> V_24 ) ;
V_21 = F_24 ( V_20 -> V_22 , V_27 , V_28 ) ;
F_21 ( & V_20 -> V_24 ) ;
return V_21 ;
}
static int F_25 ( struct V_25 * V_18 ,
const T_2 * V_29 , unsigned int V_26 )
{
return 0 ;
}
static int T_3 F_26 ( void )
{
int V_21 = 0 ;
V_21 = F_27 () ;
if ( V_21 ) {
F_28 ( L_1 , V_21 ) ;
return - V_30 ;
}
return F_29 ( & V_31 ) ;
}
static void T_4 F_30 ( void )
{
F_31 ( & V_31 ) ;
}
