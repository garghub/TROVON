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
F_9 ( L_1 , V_7 ) ;
}
void F_10 ( void * V_8 , const void * V_9 , unsigned int V_10 )
{
memcpy ( V_8 , V_9 , V_10 ) ;
}
void F_11 ( T_1 * V_11 )
{
T_1 V_12 = 0 ;
V_12 = F_12 () ;
if ( V_12 == 0 )
V_12 = F_13 () ;
* V_11 = V_12 ;
}
static int F_14 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_15 ( V_14 ) ;
int V_17 = 0 ;
V_16 -> V_18 = F_16 ( 1 , 0 ) ;
if ( ! V_16 -> V_18 )
V_17 = - V_19 ;
F_17 ( & V_16 -> V_20 ) ;
return V_17 ;
}
static void F_18 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = F_15 ( V_14 ) ;
F_19 ( & V_16 -> V_20 ) ;
if ( V_16 -> V_18 )
F_20 ( V_16 -> V_18 ) ;
V_16 -> V_18 = NULL ;
F_21 ( & V_16 -> V_20 ) ;
}
static int F_22 ( struct V_21 * V_14 ,
const T_2 * V_9 , unsigned int V_22 ,
T_2 * V_23 , unsigned int V_24 )
{
struct V_15 * V_16 = F_23 ( V_14 ) ;
int V_17 = 0 ;
F_19 ( & V_16 -> V_20 ) ;
V_17 = F_24 ( V_16 -> V_18 , V_23 , V_24 ) ;
F_21 ( & V_16 -> V_20 ) ;
return V_17 ;
}
static int F_25 ( struct V_21 * V_14 ,
const T_2 * V_25 , unsigned int V_22 )
{
return 0 ;
}
static int T_3 F_26 ( void )
{
int V_17 = 0 ;
V_17 = F_27 () ;
if ( V_17 ) {
F_28 ( L_2 , V_17 ) ;
return - V_26 ;
}
return F_29 ( & V_27 ) ;
}
static void T_4 F_30 ( void )
{
F_31 ( & V_27 ) ;
}
