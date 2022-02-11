static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
if ( ! V_3 )
return NULL ;
V_5 = F_2 ( V_3 , struct V_4 , V_6 ) ;
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static bool F_3 ( struct V_7 * V_8 , void * V_9 )
{
return ! strcmp ( V_8 -> V_10 , V_9 ) ;
}
static int F_4 ( struct V_2 * V_3 ,
struct V_11 * * V_12 ,
struct V_1 * * V_13 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_11 * V_14 ;
if ( ! V_5 )
return - V_15 ;
V_14 = F_5 ( F_3 ,
V_5 -> V_16 -> V_10 ) ;
if ( ! V_14 )
return - V_15 ;
* V_12 = V_14 ;
* V_13 = V_5 ;
return 0 ;
}
static void F_6 ( struct V_11 * V_14 )
{
F_7 ( V_14 ) ;
}
static T_1 F_8 ( struct V_2 * V_3 ,
char * V_17 )
{
struct V_11 * V_14 ;
struct V_1 * V_5 ;
int V_18 ;
T_1 V_19 ;
V_19 = F_4 ( V_3 , & V_14 , & V_5 ) ;
if ( V_19 )
return V_19 ;
V_18 = F_9 ( V_14 , V_5 -> V_20 ) ;
F_6 ( V_14 ) ;
if ( V_18 < 0 )
return V_18 ;
return sprintf ( V_17 , L_1 , F_10 ( V_18 ) ) ;
}
static T_1 F_11 ( struct V_2 * V_3 ,
const char * V_17 , T_2 V_21 )
{
struct V_11 * V_14 ;
struct V_1 * V_5 ;
int V_18 = F_12 ( V_17 ) ;
T_1 V_19 ;
if ( V_18 < 0 )
return - V_22 ;
V_19 = F_4 ( V_3 , & V_14 , & V_5 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_13 ( V_14 , V_5 -> V_20 , V_18 ) ;
F_6 ( V_14 ) ;
return ! V_19 ? F_14 ( V_17 , V_21 ) : V_19 ;
}
static int F_15 ( struct V_16 * V_16 ,
struct V_11 * V_14 )
{
struct V_7 * V_23 ;
unsigned int V_24 ;
unsigned int V_25 ;
struct V_1 * V_26 ;
struct V_4 * * V_27 ;
int V_28 ;
V_23 = F_16 ( V_14 ) ;
if ( ! V_23 )
return - V_15 ;
V_25 = V_23 -> V_29 ;
V_26 = F_17 ( V_25 , sizeof( * V_16 -> V_26 ) ,
V_30 ) ;
V_27 = F_17 ( V_25 + 1 , sizeof( * V_27 ) , V_30 ) ;
if ( ! V_26 || ! V_27 ) {
V_28 = - V_31 ;
goto free;
}
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
char V_32 [ 10 ] ;
V_26 [ V_24 ] . V_20 = V_24 + 1 ;
snprintf ( V_32 , sizeof( V_32 ) , L_2 , V_24 + 1 ) ;
V_26 [ V_24 ] . V_16 = V_16 ;
F_18 ( & V_26 [ V_24 ] . V_5 ,
V_32 ,
& V_33 ) ;
V_27 [ V_24 ] = & V_26 [ V_24 ] . V_5 ;
}
V_27 [ V_24 ] = NULL ;
V_16 -> V_34 = V_27 ;
V_16 -> V_26 = V_26 ;
return 0 ;
free:
F_19 ( V_26 ) ;
F_19 ( V_27 ) ;
V_16 -> V_26 = NULL ;
V_16 -> V_34 = NULL ;
return V_28 ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 ,
V_6 ) ;
struct V_16 * V_16 = F_2 ( V_5 ,
struct V_16 ,
V_35 ) ;
F_19 ( V_16 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 ,
V_6 ) ;
struct V_16 * V_16 = F_2 ( V_5 ,
struct V_16 ,
V_27 ) ;
F_19 ( V_16 -> V_26 ) ;
F_19 ( V_16 -> V_34 ) ;
V_16 -> V_26 = NULL ;
V_16 -> V_34 = NULL ;
}
static struct V_4 * F_22 ( struct V_4 * V_5 ,
const char * V_10 )
{
int V_28 = - V_15 ;
struct V_11 * V_14 = F_5 ( F_3 ,
( void * ) V_10 ) ;
struct V_16 * V_16 = NULL ;
if ( ! V_14 )
goto V_36;
V_16 = F_23 ( sizeof( * V_16 ) , V_30 ) ;
if ( ! V_16 ) {
V_28 = - V_31 ;
goto V_36;
}
strncpy ( V_16 -> V_10 , V_10 , sizeof( V_16 -> V_10 ) ) ;
V_28 = F_15 ( V_16 , V_14 ) ;
if ( V_28 )
goto V_36;
V_16 -> V_27 . V_37 =
V_16 -> V_34 ;
F_18 ( & V_16 -> V_27 , L_3 ,
& V_38 ) ;
V_16 -> V_35 . V_37
= V_16 -> V_39 ;
V_16 -> V_39 [ 0 ] = & V_16 -> V_27 ;
V_16 -> V_39 [ 1 ] = NULL ;
F_18 ( & V_16 -> V_35 , V_10 ,
& V_40 ) ;
F_7 ( V_14 ) ;
return & V_16 -> V_35 ;
V_36:
if ( V_14 )
F_7 ( V_14 ) ;
F_19 ( V_16 ) ;
return F_24 ( V_28 ) ;
}
int T_3 F_25 ( void )
{
F_26 ( & V_41 . V_42 ) ;
F_27 ( & V_41 . V_43 ) ;
return F_28 ( & V_41 ) ;
}
void T_4 F_29 ( void )
{
F_30 ( & V_41 ) ;
}
