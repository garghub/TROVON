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
V_21 = F_3 ( V_16 + 1 , V_7 ) ;
if ( ! V_21 )
return - V_8 ;
if ( F_16 ( V_21 , V_15 , V_16 ) ) {
F_9 ( V_21 ) ;
return - V_23 ;
}
V_21 [ V_16 ] = '\0' ;
V_4 = V_2 -> V_14 ;
if ( F_11 ( & V_4 -> V_13 ) ) {
F_9 ( V_21 ) ;
return - V_20 ;
}
if ( ! V_4 -> V_11 )
V_4 -> V_11 = ( char * ) F_17 ( V_7
| V_24 | V_25 ,
F_8 ( V_4 -> V_9 ) ) ;
if ( ! V_4 -> V_11 ) {
F_12 ( & V_4 -> V_13 ) ;
F_9 ( V_21 ) ;
return - V_8 ;
}
F_18 ( V_26 , 1 , V_21 ) ;
V_4 -> V_12 = F_19 ( V_21 , V_4 -> V_11 , V_4 -> V_9 ,
& V_4 -> V_27 ) ;
F_12 ( & V_4 -> V_13 ) ;
F_9 ( V_21 ) ;
* V_17 = 0 ;
return V_16 ;
}
static long F_20 ( struct V_2 * V_2 , unsigned int V_21 , unsigned long V_28 )
{
struct V_3 * V_4 ;
int T_2 * V_29 ;
int V_30 ;
V_4 = V_2 -> V_14 ;
if ( F_21 () )
V_29 = F_22 ( V_28 ) ;
else
V_29 = ( int T_2 * ) V_28 ;
if ( F_11 ( & V_4 -> V_13 ) )
return - V_20 ;
switch ( V_21 ) {
case V_31 :
V_30 = V_4 -> V_27 ;
F_12 ( & V_4 -> V_13 ) ;
return F_23 ( V_30 , V_29 ) ;
case V_32 :
F_7 ( ( unsigned long ) V_4 -> V_11 ,
F_8 ( V_4 -> V_9 ) ) ;
V_4 -> V_11 = NULL ;
V_30 = F_24 ( V_4 -> V_9 , V_29 ) ;
if ( F_8 ( V_4 -> V_9 ) > 8 ) {
V_4 -> V_9 = V_10 ;
V_30 = - V_22 ;
}
F_12 ( & V_4 -> V_13 ) ;
return V_30 ;
case V_33 :
V_30 = V_4 -> V_12 ;
F_12 ( & V_4 -> V_13 ) ;
return F_23 ( V_30 , V_29 ) ;
default:
F_12 ( & V_4 -> V_13 ) ;
return - V_34 ;
}
}
static int T_5 F_25 ( void )
{
int V_18 ;
if ( ! V_35 )
return 0 ;
V_26 = F_26 ( L_1 , 1 , 1 , 240 ) ;
if ( ! V_26 )
return - V_8 ;
V_18 = F_27 ( V_26 , & V_36 ) ;
if ( V_18 ) {
F_28 ( V_26 ) ;
return V_18 ;
}
V_18 = F_29 ( & V_37 ) ;
if ( V_18 )
F_28 ( V_26 ) ;
return V_18 ;
}
