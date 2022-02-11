static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
int (* F_4)( void * V_4 ,
T_1 V_5 , T_1 V_6 ) ,
void * V_4 )
{
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_2 -> V_3 ;
T_2 V_11 = F_6 ( F_7 ( V_2 -> V_12 ) -> V_13 ) ;
if ( V_11 < ( V_10 -> V_14 + V_2 -> V_15 ) )
return - 1 ;
V_8 -> V_16 = F_8 ( V_2 , V_10 -> V_14 ) ;
V_10 -> V_14 += V_2 -> V_15 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
void (* F_4) ( void * , int V_17 ) ,
void * V_4 )
{
F_4 ( V_4 , 1 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_2 * V_18 ,
T_2 * V_19 ,
T_2 * V_20 )
{
* V_19 = ( (struct V_9 * ) V_2 -> V_3 ) -> V_14 ;
* V_18 = F_6 ( F_7 ( V_2 -> V_12 ) -> V_13 ) ;
* V_20 = 0 ;
}
static int F_11 ( struct V_1 * V_2 , char * V_21 )
{
struct V_9 * V_10 ;
V_10 = F_12 ( sizeof( struct V_9 ) , V_22 ) ;
if ( ! V_10 )
return - V_23 ;
V_10 -> V_14 = 0 ;
V_2 -> V_3 = V_10 ;
return 0 ;
}
static unsigned F_13 ( struct V_1 * V_2 ,
T_3 V_24 , char * V_25 ,
unsigned V_26 )
{
unsigned V_27 = 0 ;
switch ( V_24 ) {
case V_28 :
break;
case V_29 :
F_14 ( L_1 , ( unsigned long long ) V_2 -> V_15 ) ;
}
return V_27 ;
}
int F_15 ( void )
{
int V_30 ;
V_30 = F_16 ( & V_31 ) ;
if ( V_30 ) {
F_17 ( L_2 ) ;
return V_30 ;
}
V_30 = F_16 ( & V_32 ) ;
if ( V_30 ) {
F_17 ( L_3
L_4 ) ;
F_18 ( & V_31 ) ;
return V_30 ;
}
return V_30 ;
}
void F_19 ( void )
{
F_18 ( & V_31 ) ;
F_18 ( & V_32 ) ;
}
