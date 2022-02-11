static void * F_1 ( struct V_1 * V_2 )
{
void * V_3 ;
V_3 = F_2 ( V_4 , V_5 | V_6 ) ;
if ( ! V_3 )
V_3 = F_3 ( V_4 ) ;
if ( ! V_3 )
return F_4 ( - V_7 ) ;
return V_3 ;
}
static int F_5 ( struct V_8 * V_2 )
{
struct V_9 * V_3 = F_6 ( V_2 ) ;
V_3 -> V_10 = F_1 ( NULL ) ;
if ( F_7 ( V_3 -> V_10 ) )
return - V_7 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , void * V_3 )
{
F_9 ( V_3 ) ;
}
static void F_10 ( struct V_8 * V_2 )
{
struct V_9 * V_3 = F_6 ( V_2 ) ;
F_8 ( NULL , V_3 -> V_10 ) ;
}
static int F_11 ( const T_1 * V_11 , unsigned int V_12 ,
T_1 * V_13 , unsigned int * V_14 , void * V_3 )
{
T_2 V_15 = * V_14 ;
int V_16 ;
V_16 = F_12 ( V_11 , V_12 , V_13 , & V_15 , V_3 ) ;
if ( V_16 != V_17 )
return - V_18 ;
* V_14 = V_15 ;
return 0 ;
}
static int F_13 ( struct V_8 * V_2 , const T_1 * V_11 ,
unsigned int V_12 , T_1 * V_13 , unsigned int * V_14 )
{
struct V_9 * V_3 = F_6 ( V_2 ) ;
return F_11 ( V_11 , V_12 , V_13 , V_14 , V_3 -> V_10 ) ;
}
static int F_14 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_12 , T_1 * V_13 , unsigned int * V_14 ,
void * V_3 )
{
return F_11 ( V_11 , V_12 , V_13 , V_14 , V_3 ) ;
}
static int F_15 ( const T_1 * V_11 , unsigned int V_12 ,
T_1 * V_13 , unsigned int * V_14 )
{
int V_16 ;
T_2 V_15 = * V_14 ;
V_16 = F_16 ( V_11 , V_12 , V_13 , & V_15 ) ;
if ( V_16 != V_17 )
return - V_18 ;
* V_14 = V_15 ;
return 0 ;
}
static int F_17 ( struct V_8 * V_2 , const T_1 * V_11 ,
unsigned int V_12 , T_1 * V_13 , unsigned int * V_14 )
{
return F_15 ( V_11 , V_12 , V_13 , V_14 ) ;
}
static int F_18 ( struct V_1 * V_2 , const T_1 * V_11 ,
unsigned int V_12 , T_1 * V_13 , unsigned int * V_14 ,
void * V_3 )
{
return F_15 ( V_11 , V_12 , V_13 , V_14 ) ;
}
static int T_3 F_19 ( void )
{
int V_19 ;
V_19 = F_20 ( & V_20 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_21 ( & V_21 ) ;
if ( V_19 ) {
F_22 ( & V_20 ) ;
return V_19 ;
}
return V_19 ;
}
static void T_4 F_23 ( void )
{
F_22 ( & V_20 ) ;
F_24 ( & V_21 ) ;
}
