static struct V_1 * F_1 ( struct V_1 * V_2 , int * V_3 )
{
struct V_1 * V_4 = NULL ;
T_1 V_5 ;
T_2 V_6 ;
struct V_7 * V_8 ;
unsigned char * V_9 ;
struct V_10 * V_11 ;
V_5 = F_2 ( V_2 -> V_12 ) ;
V_5 += F_3 ( sizeof( struct V_10 ) ) ;
V_4 = F_4 ( V_5 , V_13 ) ;
if ( ! V_4 )
goto V_14;
V_6 = V_4 -> V_15 ;
V_8 = F_5 ( V_4 , 0 , 0 , 0 , V_5 - sizeof( * V_8 ) ) ;
V_11 = (struct V_10 * ) F_6 ( V_8 ) ;
V_11 -> V_16 = V_2 -> V_17 -> V_18 ;
V_9 = F_7 ( V_11 ) ;
F_8 ( V_2 , V_9 , V_2 -> V_12 ) ;
V_8 -> V_19 = V_4 -> V_15 - V_6 ;
return V_4 ;
V_14:
if ( V_4 )
F_9 ( V_4 ) ;
* V_3 = - V_20 ;
if ( F_10 () )
F_11 ( V_21 L_1 ) ;
return NULL ;
}
static void F_12 ( struct V_1 * V_4 )
{
struct V_1 * V_22 ;
int V_23 = 0 ;
int V_24 = 0 ;
unsigned char V_25 = * V_4 -> V_26 ;
switch ( V_25 & V_27 ) {
case V_28 :
V_24 = V_29 ;
break;
case V_30 :
V_24 = V_31 ;
break;
default:
return;
}
V_22 = F_1 ( V_4 , & V_23 ) ;
if ( V_22 == NULL )
return;
F_13 ( V_22 ) . V_32 = V_24 ;
F_14 ( V_33 , V_22 , 0 , V_24 , V_13 ) ;
}
static unsigned int F_15 ( unsigned int V_34 ,
struct V_1 * V_4 ,
const struct V_35 * V_36 ,
const struct V_35 * V_37 ,
int (* F_16)( struct V_1 * ) )
{
F_12 ( V_4 ) ;
return V_38 ;
}
static inline void F_17 ( struct V_1 * V_4 )
{
struct V_7 * V_8 = F_18 ( V_4 ) ;
if ( V_8 -> V_19 < sizeof( * V_8 ) || V_4 -> V_12 < V_8 -> V_19 )
return;
if ( F_19 ( V_4 , V_39 ) )
F_20 ( - V_40 ) ;
F_20 ( - V_41 ) ;
}
static int T_3 F_21 ( void )
{
int V_42 = 0 ;
V_33 = F_22 ( & V_43 ,
V_44 , V_45 ,
F_17 ,
NULL , V_46 ) ;
if ( V_33 == NULL ) {
F_11 ( V_21 L_2 ) ;
return - V_20 ;
}
V_42 = F_23 ( & V_47 ) ;
if ( V_42 ) {
F_24 ( V_33 ) ;
}
return V_42 ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_47 ) ;
F_24 ( V_33 ) ;
}
