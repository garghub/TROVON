static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 , * V_6 ;
T_2 V_7 , V_8 ;
V_5 = F_2 ( V_2 -> V_9 ) ;
if ( V_5 && V_5 -> V_10 > V_3 )
return 0 ;
V_7 = V_11 ;
while ( true ) {
V_8 = ( V_7 - F_3 ( struct V_4 , V_9 ) ) /
sizeof( V_6 -> V_9 [ 0 ] ) ;
if ( V_8 > V_3 )
break;
V_7 *= 2 ;
if ( F_4 ( V_7 < V_11 ) )
return - V_12 ;
}
V_6 = F_5 ( V_7 , V_13 ) ;
if ( ! V_6 )
return - V_14 ;
if ( V_5 )
memcpy ( V_6 -> V_9 , V_5 -> V_9 ,
V_5 -> V_10 * sizeof( V_5 -> V_9 [ 0 ] ) ) ;
V_6 -> V_10 = V_8 ;
F_6 ( V_2 -> V_9 , V_6 ) ;
if ( V_5 )
F_7 ( V_5 , V_15 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
struct V_4 * V_18 = F_9 ( V_2 -> V_9 ) ;
int V_19 = V_17 -> V_20 -> V_19 ;
if ( V_18 && V_19 < V_18 -> V_10 )
return V_18 -> V_9 [ V_19 ] ;
return 0 ;
}
static int F_10 ( struct V_16 * V_17 ,
struct V_1 * V_2 , T_1 V_21 )
{
struct V_4 * V_18 ;
int V_19 = V_17 -> V_20 -> V_19 ;
int V_22 ;
V_18 = F_2 ( V_2 -> V_9 ) ;
if ( ! V_21 && ( ! V_18 || V_18 -> V_10 <= V_19 ) )
return 0 ;
V_22 = F_1 ( V_2 , V_19 ) ;
if ( V_22 )
return V_22 ;
V_18 = F_2 ( V_2 -> V_9 ) ;
V_18 -> V_9 [ V_19 ] = V_21 ;
return 0 ;
}
static struct V_16 *
F_11 ( struct V_16 * V_23 )
{
struct V_16 * V_17 ;
V_17 = F_5 ( sizeof( * V_17 ) , V_13 ) ;
if ( ! V_17 )
return F_12 ( - V_14 ) ;
return V_17 ;
}
static int F_13 ( struct V_16 * V_17 )
{
struct V_16 * V_23 = V_17 -> V_24 ;
struct V_1 * V_2 ;
int V_22 = 0 ;
if ( ! V_23 )
return 0 ;
F_14 () ;
F_15 (&init_net, dev) {
T_1 V_21 = F_8 ( V_23 , V_2 ) ;
V_22 = F_10 ( V_17 , V_2 , V_21 ) ;
if ( V_22 )
break;
}
F_16 () ;
return V_22 ;
}
static void F_17 ( struct V_16 * V_17 )
{
F_18 ( V_17 ) ;
}
static T_3 F_19 ( struct V_16 * V_17 , struct V_25 * V_26 )
{
return V_17 -> V_20 -> V_19 ;
}
static int F_20 ( struct V_27 * V_28 , void * V_29 )
{
struct V_1 * V_2 ;
F_21 () ;
F_22 (&init_net, dev)
F_23 ( V_28 , L_1 , V_2 -> V_30 ,
F_8 ( F_24 ( V_28 ) , V_2 ) ) ;
F_25 () ;
return 0 ;
}
static T_4 F_26 ( struct V_31 * V_32 ,
char * V_33 , T_2 V_34 , T_5 V_35 )
{
char V_36 [ V_37 + 1 ] ;
struct V_1 * V_2 ;
T_1 V_21 ;
int V_22 ;
if ( sscanf ( V_33 , L_2 F_27 ( V_37 ) L_3 , V_36 , & V_21 ) != 2 )
return - V_38 ;
V_2 = F_28 ( & V_39 , V_36 ) ;
if ( ! V_2 )
return - V_40 ;
F_14 () ;
V_22 = F_10 ( F_29 ( V_32 ) , V_2 , V_21 ) ;
F_16 () ;
F_30 ( V_2 ) ;
return V_22 ? : V_34 ;
}
static int F_31 ( const void * V_29 , struct V_41 * V_41 , unsigned V_42 )
{
int V_43 ;
struct V_44 * V_45 = F_32 ( V_41 , & V_43 ) ;
if ( V_45 )
V_45 -> V_46 -> V_47 = ( T_1 ) ( unsigned long ) V_29 ;
return 0 ;
}
static void F_33 ( struct V_16 * V_17 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 ;
void * V_29 = ( void * ) ( unsigned long ) V_17 -> V_20 -> V_19 ;
F_34 (p, tset) {
F_35 ( V_51 ) ;
F_36 ( V_51 -> V_52 , 0 , F_31 , V_29 ) ;
F_37 ( V_51 ) ;
}
}
static int F_38 ( struct V_53 * V_54 ,
unsigned long V_55 , void * V_56 )
{
struct V_1 * V_2 = F_39 ( V_56 ) ;
struct V_4 * V_5 ;
switch ( V_55 ) {
case V_57 :
V_5 = F_2 ( V_2 -> V_9 ) ;
F_40 ( V_2 -> V_9 , NULL ) ;
if ( V_5 )
F_7 ( V_5 , V_15 ) ;
break;
}
return V_58 ;
}
static int T_6 F_41 ( void )
{
F_42 ( & V_59 ) ;
return 0 ;
}
