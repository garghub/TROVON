static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_5 ) )
return - V_6 ;
V_4 = F_3 ( sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 )
return - V_8 ;
V_4 -> V_9 = V_10 ;
V_4 -> V_11 = NULL ;
V_4 -> V_12 = 0 ;
F_4 ( & V_4 -> V_13 ) ;
V_2 -> V_14 = V_4 ;
return F_5 ( V_1 , V_2 ) ;
}
static int F_6 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
V_4 = V_2 -> V_14 ;
V_2 -> V_14 = NULL ;
F_7 ( ( unsigned long ) V_4 -> V_11 , F_8 ( V_4 -> V_9 ) ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static T_1
F_10 ( struct V_2 * V_2 , char T_2 * V_15 , T_3 V_16 , T_4 * V_17 )
{
T_1 V_18 ;
T_3 V_19 ;
struct V_3 * V_4 ;
V_4 = V_2 -> V_14 ;
if ( F_11 ( & V_4 -> V_13 ) )
return - V_20 ;
if ( ! V_4 -> V_11 ) {
F_12 ( & V_4 -> V_13 ) ;
return 0 ;
}
V_19 = F_13 ( T_3 , V_4 -> V_12 , V_4 -> V_9 ) ;
V_18 = F_14 ( V_15 , V_16 , V_17 ,
V_4 -> V_11 , V_19 ) ;
F_12 ( & V_4 -> V_13 ) ;
return V_18 ;
}
static T_1
F_15 ( struct V_2 * V_2 , const char T_2 * V_15 , T_3 V_16 ,
T_4 * V_17 )
{
char * V_21 ;
struct V_3 * V_4 ;
if ( V_16 > 240 )
return - V_22 ;
V_21 = F_16 ( V_15 , V_16 ) ;
if ( F_17 ( V_21 ) )
return F_18 ( V_21 ) ;
V_4 = V_2 -> V_14 ;
if ( F_11 ( & V_4 -> V_13 ) ) {
F_9 ( V_21 ) ;
return - V_20 ;
}
if ( ! V_4 -> V_11 )
V_4 -> V_11 = ( char * ) F_19 ( V_7
| V_23 | V_24 ,
F_8 ( V_4 -> V_9 ) ) ;
if ( ! V_4 -> V_11 ) {
F_12 ( & V_4 -> V_13 ) ;
F_9 ( V_21 ) ;
return - V_8 ;
}
F_20 ( V_25 , 1 , V_21 ) ;
V_4 -> V_12 = F_21 ( V_21 , V_4 -> V_11 , V_4 -> V_9 ,
& V_4 -> V_26 ) ;
F_12 ( & V_4 -> V_13 ) ;
F_9 ( V_21 ) ;
* V_17 = 0 ;
return V_16 ;
}
static long F_22 ( struct V_2 * V_2 , unsigned int V_21 , unsigned long V_27 )
{
struct V_3 * V_4 ;
int T_2 * V_28 ;
int V_29 ;
V_4 = V_2 -> V_14 ;
if ( F_23 () )
V_28 = F_24 ( V_27 ) ;
else
V_28 = ( int T_2 * ) V_27 ;
if ( F_11 ( & V_4 -> V_13 ) )
return - V_20 ;
switch ( V_21 ) {
case V_30 :
V_29 = V_4 -> V_26 ;
F_12 ( & V_4 -> V_13 ) ;
return F_25 ( V_29 , V_28 ) ;
case V_31 :
F_7 ( ( unsigned long ) V_4 -> V_11 ,
F_8 ( V_4 -> V_9 ) ) ;
V_4 -> V_11 = NULL ;
V_29 = F_26 ( V_4 -> V_9 , V_28 ) ;
if ( F_8 ( V_4 -> V_9 ) > 8 ) {
V_4 -> V_9 = V_10 ;
V_29 = - V_22 ;
}
F_12 ( & V_4 -> V_13 ) ;
return V_29 ;
case V_32 :
V_29 = V_4 -> V_12 ;
F_12 ( & V_4 -> V_13 ) ;
return F_25 ( V_29 , V_28 ) ;
default:
F_12 ( & V_4 -> V_13 ) ;
return - V_33 ;
}
}
static int T_5 F_27 ( void )
{
int V_18 ;
if ( ! V_34 )
return 0 ;
V_25 = F_28 ( L_1 , 1 , 1 , 240 ) ;
if ( ! V_25 )
return - V_8 ;
V_18 = F_29 ( V_25 , & V_35 ) ;
if ( V_18 ) {
F_30 ( V_25 ) ;
return V_18 ;
}
V_18 = F_31 ( & V_36 ) ;
if ( V_18 )
F_30 ( V_25 ) ;
return V_18 ;
}
