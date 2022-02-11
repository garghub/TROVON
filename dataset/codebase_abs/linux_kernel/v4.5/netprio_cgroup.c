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
if ( V_17 -> V_19 > V_25 )
return - V_12 ;
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
static T_3 F_19 ( struct V_16 * V_17 , struct V_26 * V_27 )
{
return V_17 -> V_20 -> V_19 ;
}
static int F_20 ( struct V_28 * V_29 , void * V_30 )
{
struct V_1 * V_2 ;
F_21 () ;
F_22 (&init_net, dev)
F_23 ( V_29 , L_1 , V_2 -> V_31 ,
F_8 ( F_24 ( V_29 ) , V_2 ) ) ;
F_25 () ;
return 0 ;
}
static T_4 F_26 ( struct V_32 * V_33 ,
char * V_34 , T_2 V_35 , T_5 V_36 )
{
char V_37 [ V_38 + 1 ] ;
struct V_1 * V_2 ;
T_1 V_21 ;
int V_22 ;
if ( sscanf ( V_34 , L_2 F_27 ( V_38 ) L_3 , V_37 , & V_21 ) != 2 )
return - V_39 ;
V_2 = F_28 ( & V_40 , V_37 ) ;
if ( ! V_2 )
return - V_41 ;
F_29 () ;
F_14 () ;
V_22 = F_10 ( F_30 ( V_33 ) , V_2 , V_21 ) ;
F_16 () ;
F_31 ( V_2 ) ;
return V_22 ? : V_35 ;
}
static int F_32 ( const void * V_30 , struct V_42 * V_42 , unsigned V_43 )
{
int V_44 ;
struct V_45 * V_46 = F_33 ( V_42 , & V_44 ) ;
if ( V_46 ) {
F_34 ( & V_47 ) ;
F_35 ( & V_46 -> V_48 -> V_49 ,
( unsigned long ) V_30 ) ;
F_36 ( & V_47 ) ;
}
return 0 ;
}
static void F_37 ( struct V_50 * V_51 )
{
struct V_52 * V_53 ;
struct V_16 * V_17 ;
F_38 (p, css, tset) {
void * V_30 = ( void * ) ( unsigned long ) V_17 -> V_20 -> V_19 ;
F_39 ( V_53 ) ;
F_40 ( V_53 -> V_54 , 0 , F_32 , V_30 ) ;
F_41 ( V_53 ) ;
}
}
static int F_42 ( struct V_55 * V_56 ,
unsigned long V_57 , void * V_58 )
{
struct V_1 * V_2 = F_43 ( V_58 ) ;
struct V_4 * V_5 ;
switch ( V_57 ) {
case V_59 :
V_5 = F_2 ( V_2 -> V_9 ) ;
F_44 ( V_2 -> V_9 , NULL ) ;
if ( V_5 )
F_7 ( V_5 , V_15 ) ;
break;
}
return V_60 ;
}
static int T_6 F_45 ( void )
{
F_46 ( & V_61 ) ;
return 0 ;
}
