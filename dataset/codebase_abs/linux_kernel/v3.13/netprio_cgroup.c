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
struct V_16 * V_23 = F_14 ( V_17 ) ;
struct V_1 * V_2 ;
int V_22 = 0 ;
if ( ! V_23 )
return 0 ;
F_15 () ;
F_16 (&init_net, dev) {
T_1 V_21 = F_8 ( V_23 , V_2 ) ;
V_22 = F_10 ( V_17 , V_2 , V_21 ) ;
if ( V_22 )
break;
}
F_17 () ;
return V_22 ;
}
static void F_18 ( struct V_16 * V_17 )
{
F_19 ( V_17 ) ;
}
static T_3 F_20 ( struct V_16 * V_17 , struct V_24 * V_25 )
{
return V_17 -> V_20 -> V_19 ;
}
static int F_21 ( struct V_16 * V_17 , struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 ;
F_22 () ;
F_23 (&init_net, dev)
V_27 -> V_28 ( V_27 , V_2 -> V_29 , F_8 ( V_17 , V_2 ) ) ;
F_24 () ;
return 0 ;
}
static int F_25 ( struct V_16 * V_17 , struct V_24 * V_25 ,
const char * V_30 )
{
char V_31 [ V_32 + 1 ] ;
struct V_1 * V_2 ;
T_1 V_21 ;
int V_22 ;
if ( sscanf ( V_30 , L_1 F_26 ( V_32 ) L_2 , V_31 , & V_21 ) != 2 )
return - V_33 ;
V_2 = F_27 ( & V_34 , V_31 ) ;
if ( ! V_2 )
return - V_35 ;
F_15 () ;
V_22 = F_10 ( V_17 , V_2 , V_21 ) ;
F_17 () ;
F_28 ( V_2 ) ;
return V_22 ;
}
static int F_29 ( const void * V_36 , struct V_37 * V_37 , unsigned V_38 )
{
int V_39 ;
struct V_40 * V_41 = F_30 ( V_37 , & V_39 ) ;
if ( V_41 )
V_41 -> V_42 -> V_43 = ( T_1 ) ( unsigned long ) V_36 ;
return 0 ;
}
static void F_31 ( struct V_16 * V_17 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 ;
void * V_36 = ( void * ) ( unsigned long ) V_17 -> V_20 -> V_19 ;
F_32 (p, css, tset) {
F_33 ( V_47 ) ;
F_34 ( V_47 -> V_48 , 0 , F_29 , V_36 ) ;
F_35 ( V_47 ) ;
}
}
static int F_36 ( struct V_49 * V_50 ,
unsigned long V_51 , void * V_52 )
{
struct V_1 * V_2 = F_37 ( V_52 ) ;
struct V_4 * V_5 ;
switch ( V_51 ) {
case V_53 :
V_5 = F_2 ( V_2 -> V_9 ) ;
F_38 ( V_2 -> V_9 , NULL ) ;
if ( V_5 )
F_7 ( V_5 , V_15 ) ;
break;
}
return V_54 ;
}
static int T_4 F_39 ( void )
{
int V_22 ;
V_22 = F_40 ( & V_55 ) ;
if ( V_22 )
goto V_56;
F_41 ( & V_57 ) ;
V_56:
return V_22 ;
}
static void T_5 F_42 ( void )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
F_43 ( & V_57 ) ;
F_44 ( & V_55 ) ;
F_15 () ;
F_16 (&init_net, dev) {
V_5 = F_2 ( V_2 -> V_9 ) ;
F_38 ( V_2 -> V_9 , NULL ) ;
if ( V_5 )
F_7 ( V_5 , V_15 ) ;
}
F_17 () ;
}
