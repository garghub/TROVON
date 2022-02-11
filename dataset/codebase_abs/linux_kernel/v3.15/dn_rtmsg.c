static struct V_1 * F_1 ( struct V_1 * V_2 , int * V_3 )
{
struct V_1 * V_4 = NULL ;
T_1 V_5 ;
T_2 V_6 ;
struct V_7 * V_8 ;
unsigned char * V_9 ;
struct V_10 * V_11 ;
V_5 = F_2 ( V_2 -> V_12 ) +
F_2 ( sizeof( struct V_10 ) ) ;
V_4 = F_3 ( V_5 , V_13 ) ;
if ( ! V_4 ) {
* V_3 = - V_14 ;
return NULL ;
}
V_6 = V_4 -> V_15 ;
V_8 = F_4 ( V_4 , 0 , 0 , 0 , V_5 , 0 ) ;
if ( ! V_8 ) {
F_5 ( V_4 ) ;
* V_3 = - V_14 ;
return NULL ;
}
V_11 = (struct V_10 * ) F_6 ( V_8 ) ;
V_11 -> V_16 = V_2 -> V_17 -> V_18 ;
V_9 = F_7 ( V_11 ) ;
F_8 ( V_2 , V_9 , V_2 -> V_12 ) ;
V_8 -> V_19 = V_4 -> V_15 - V_6 ;
return V_4 ;
}
static void F_9 ( struct V_1 * V_4 )
{
struct V_1 * V_20 ;
int V_21 = 0 ;
int V_22 = 0 ;
unsigned char V_23 = * V_4 -> V_24 ;
switch ( V_23 & V_25 ) {
case V_26 :
V_22 = V_27 ;
break;
case V_28 :
V_22 = V_29 ;
break;
default:
return;
}
V_20 = F_1 ( V_4 , & V_21 ) ;
if ( V_20 == NULL )
return;
F_10 ( V_20 ) . V_30 = V_22 ;
F_11 ( V_31 , V_20 , 0 , V_22 , V_13 ) ;
}
static unsigned int F_12 ( const struct V_32 * V_33 ,
struct V_1 * V_4 ,
const struct V_34 * V_35 ,
const struct V_34 * V_36 ,
int (* F_13)( struct V_1 * ) )
{
F_9 ( V_4 ) ;
return V_37 ;
}
static inline void F_14 ( struct V_1 * V_4 )
{
struct V_7 * V_8 = F_15 ( V_4 ) ;
if ( V_8 -> V_19 < sizeof( * V_8 ) || V_4 -> V_12 < V_8 -> V_19 )
return;
if ( ! F_16 ( V_4 , V_38 ) )
F_17 ( - V_39 ) ;
F_17 ( - V_40 ) ;
}
static int T_3 F_18 ( void )
{
int V_41 = 0 ;
struct V_42 V_43 = {
. V_44 = V_45 ,
. V_46 = F_14 ,
} ;
V_31 = F_19 ( & V_47 , V_48 , & V_43 ) ;
if ( V_31 == NULL ) {
F_20 ( V_49 L_1 ) ;
return - V_14 ;
}
V_41 = F_21 ( & V_50 ) ;
if ( V_41 ) {
F_22 ( V_31 ) ;
}
return V_41 ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_50 ) ;
F_22 ( V_31 ) ;
}
