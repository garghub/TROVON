static void * F_1 ( struct V_1 * V_2 )
{
void * V_3 ;
V_3 = F_2 ( V_4 ) ;
if ( ! V_3 )
return F_3 ( - V_5 ) ;
return V_3 ;
}
static int F_4 ( struct V_6 * V_2 )
{
struct V_7 * V_3 = F_5 ( V_2 ) ;
V_3 -> V_8 = F_1 ( NULL ) ;
if ( F_6 ( V_3 -> V_8 ) )
return - V_5 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , void * V_3 )
{
F_8 ( V_3 ) ;
}
static void F_9 ( struct V_6 * V_2 )
{
struct V_7 * V_3 = F_5 ( V_2 ) ;
F_7 ( NULL , V_3 -> V_8 ) ;
}
static int F_10 ( const T_1 * V_9 , unsigned int V_10 ,
T_1 * V_11 , unsigned int * V_12 , void * V_3 )
{
T_2 V_13 = * V_12 ;
int V_14 ;
V_14 = F_11 ( V_9 , V_10 , V_11 , & V_13 , V_3 ) ;
if ( V_14 < 0 )
return - V_15 ;
* V_12 = V_13 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , const T_1 * V_9 ,
unsigned int V_10 , T_1 * V_11 , unsigned int * V_12 ,
void * V_3 )
{
return F_10 ( V_9 , V_10 , V_11 , V_12 , V_3 ) ;
}
static int F_13 ( struct V_6 * V_2 , const T_1 * V_9 ,
unsigned int V_10 , T_1 * V_11 , unsigned int * V_12 )
{
struct V_7 * V_3 = F_5 ( V_2 ) ;
return F_10 ( V_9 , V_10 , V_11 , V_12 , V_3 -> V_8 ) ;
}
static int F_14 ( const T_1 * V_9 , unsigned int V_10 ,
T_1 * V_11 , unsigned int * V_12 , void * V_3 )
{
int V_14 ;
T_2 V_13 = * V_12 ;
T_2 V_16 = V_10 ;
V_14 = F_15 ( V_9 , V_16 , V_11 , & V_13 ) ;
if ( V_14 < 0 )
return - V_15 ;
* V_12 = V_13 ;
return V_14 ;
}
static int F_16 ( struct V_1 * V_2 , const T_1 * V_9 ,
unsigned int V_10 , T_1 * V_11 , unsigned int * V_12 ,
void * V_3 )
{
return F_14 ( V_9 , V_10 , V_11 , V_12 , NULL ) ;
}
static int F_17 ( struct V_6 * V_2 , const T_1 * V_9 ,
unsigned int V_10 , T_1 * V_11 ,
unsigned int * V_12 )
{
return F_14 ( V_9 , V_10 , V_11 , V_12 , NULL ) ;
}
static int T_3 F_18 ( void )
{
int V_17 ;
V_17 = F_19 ( & V_18 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_20 ( & V_19 ) ;
if ( V_17 ) {
F_21 ( & V_18 ) ;
return V_17 ;
}
return V_17 ;
}
static void T_4 F_22 ( void )
{
F_21 ( & V_18 ) ;
F_23 ( & V_19 ) ;
}
