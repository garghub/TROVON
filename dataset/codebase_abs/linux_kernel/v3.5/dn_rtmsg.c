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
F_10 ( L_1 ) ;
return NULL ;
}
static void F_11 ( struct V_1 * V_4 )
{
struct V_1 * V_21 ;
int V_22 = 0 ;
int V_23 = 0 ;
unsigned char V_24 = * V_4 -> V_25 ;
switch ( V_24 & V_26 ) {
case V_27 :
V_23 = V_28 ;
break;
case V_29 :
V_23 = V_30 ;
break;
default:
return;
}
V_21 = F_1 ( V_4 , & V_22 ) ;
if ( V_21 == NULL )
return;
F_12 ( V_21 ) . V_31 = V_23 ;
F_13 ( V_32 , V_21 , 0 , V_23 , V_13 ) ;
}
static unsigned int F_14 ( unsigned int V_33 ,
struct V_1 * V_4 ,
const struct V_34 * V_35 ,
const struct V_34 * V_36 ,
int (* F_15)( struct V_1 * ) )
{
F_11 ( V_4 ) ;
return V_37 ;
}
static inline void F_16 ( struct V_1 * V_4 )
{
struct V_7 * V_8 = F_17 ( V_4 ) ;
if ( V_8 -> V_19 < sizeof( * V_8 ) || V_4 -> V_12 < V_8 -> V_19 )
return;
if ( ! F_18 ( V_38 ) )
F_19 ( - V_39 ) ;
F_19 ( - V_40 ) ;
}
static int T_3 F_20 ( void )
{
int V_41 = 0 ;
V_32 = F_21 ( & V_42 ,
V_43 , V_44 ,
F_16 ,
NULL , V_45 ) ;
if ( V_32 == NULL ) {
F_22 ( V_46 L_2 ) ;
return - V_20 ;
}
V_41 = F_23 ( & V_47 ) ;
if ( V_41 ) {
F_24 ( V_32 ) ;
}
return V_41 ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_47 ) ;
F_24 ( V_32 ) ;
}
