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
static int F_11 ( struct V_1 * V_2 ,
unsigned V_21 , char * * V_22 )
{
struct V_9 * V_10 ;
V_10 = F_12 ( sizeof( struct V_9 ) , V_23 ) ;
if ( ! V_10 )
return - V_24 ;
V_10 -> V_14 = 0 ;
V_2 -> V_3 = V_10 ;
return 0 ;
}
static unsigned F_13 ( struct V_1 * V_2 ,
T_3 V_25 , char * V_26 ,
unsigned V_27 )
{
unsigned V_28 = 0 ;
switch ( V_25 ) {
case V_29 :
break;
case V_30 :
F_14 ( L_1 , ( unsigned long long ) V_2 -> V_15 ) ;
}
return V_28 ;
}
int F_15 ( void )
{
int V_31 ;
V_31 = F_16 ( & V_32 ) ;
if ( V_31 ) {
F_17 ( L_2 ) ;
return V_31 ;
}
V_31 = F_16 ( & V_33 ) ;
if ( V_31 ) {
F_17 ( L_3
L_4 ) ;
F_18 ( & V_32 ) ;
return V_31 ;
}
return V_31 ;
}
void F_19 ( void )
{
F_18 ( & V_32 ) ;
F_18 ( & V_33 ) ;
}
