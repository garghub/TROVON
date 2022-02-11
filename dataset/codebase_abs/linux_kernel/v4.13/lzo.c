static void * F_1 ( struct V_1 * V_2 )
{
void * V_3 ;
V_3 = F_2 ( V_4 , V_5 ) ;
if ( ! V_3 )
return F_3 ( - V_6 ) ;
return V_3 ;
}
static int F_4 ( struct V_7 * V_2 )
{
struct V_8 * V_3 = F_5 ( V_2 ) ;
V_3 -> V_9 = F_1 ( NULL ) ;
if ( F_6 ( V_3 -> V_9 ) )
return - V_6 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , void * V_3 )
{
F_8 ( V_3 ) ;
}
static void F_9 ( struct V_7 * V_2 )
{
struct V_8 * V_3 = F_5 ( V_2 ) ;
F_7 ( NULL , V_3 -> V_9 ) ;
}
static int F_10 ( const T_1 * V_10 , unsigned int V_11 ,
T_1 * V_12 , unsigned int * V_13 , void * V_3 )
{
T_2 V_14 = * V_13 ;
int V_15 ;
V_15 = F_11 ( V_10 , V_11 , V_12 , & V_14 , V_3 ) ;
if ( V_15 != V_16 )
return - V_17 ;
* V_13 = V_14 ;
return 0 ;
}
static int F_12 ( struct V_7 * V_2 , const T_1 * V_10 ,
unsigned int V_11 , T_1 * V_12 , unsigned int * V_13 )
{
struct V_8 * V_3 = F_5 ( V_2 ) ;
return F_10 ( V_10 , V_11 , V_12 , V_13 , V_3 -> V_9 ) ;
}
static int F_13 ( struct V_1 * V_2 , const T_1 * V_10 ,
unsigned int V_11 , T_1 * V_12 , unsigned int * V_13 ,
void * V_3 )
{
return F_10 ( V_10 , V_11 , V_12 , V_13 , V_3 ) ;
}
static int F_14 ( const T_1 * V_10 , unsigned int V_11 ,
T_1 * V_12 , unsigned int * V_13 )
{
int V_15 ;
T_2 V_14 = * V_13 ;
V_15 = F_15 ( V_10 , V_11 , V_12 , & V_14 ) ;
if ( V_15 != V_16 )
return - V_17 ;
* V_13 = V_14 ;
return 0 ;
}
static int F_16 ( struct V_7 * V_2 , const T_1 * V_10 ,
unsigned int V_11 , T_1 * V_12 , unsigned int * V_13 )
{
return F_14 ( V_10 , V_11 , V_12 , V_13 ) ;
}
static int F_17 ( struct V_1 * V_2 , const T_1 * V_10 ,
unsigned int V_11 , T_1 * V_12 , unsigned int * V_13 ,
void * V_3 )
{
return F_14 ( V_10 , V_11 , V_12 , V_13 ) ;
}
static int T_3 F_18 ( void )
{
int V_18 ;
V_18 = F_19 ( & V_19 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_20 ( & V_20 ) ;
if ( V_18 ) {
F_21 ( & V_19 ) ;
return V_18 ;
}
return V_18 ;
}
static void T_4 F_22 ( void )
{
F_21 ( & V_19 ) ;
F_23 ( & V_20 ) ;
}
