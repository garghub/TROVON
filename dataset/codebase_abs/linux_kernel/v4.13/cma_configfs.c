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
static T_1 F_15 ( struct V_2 * V_3 , char * V_17 )
{
struct V_11 * V_14 ;
struct V_1 * V_5 ;
T_1 V_19 ;
T_3 V_23 ;
V_19 = F_4 ( V_3 , & V_14 , & V_5 ) ;
if ( V_19 )
return V_19 ;
V_23 = F_16 ( V_14 , V_5 -> V_20 ) ;
F_6 ( V_14 ) ;
return sprintf ( V_17 , L_2 , V_23 ) ;
}
static T_1 F_17 ( struct V_2 * V_3 ,
const char * V_17 , T_2 V_21 )
{
struct V_11 * V_14 ;
struct V_1 * V_5 ;
T_1 V_19 ;
T_3 V_23 ;
V_19 = F_18 ( V_17 , 0 , & V_23 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_4 ( V_3 , & V_14 , & V_5 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_19 ( V_14 , V_5 -> V_20 , V_23 ) ;
F_6 ( V_14 ) ;
return V_19 ? V_19 : F_14 ( V_17 , V_21 ) ;
}
static int F_20 ( struct V_16 * V_16 ,
struct V_11 * V_14 )
{
struct V_7 * V_24 ;
unsigned int V_25 ;
unsigned int V_26 ;
struct V_1 * V_27 ;
int V_28 ;
V_24 = F_21 ( V_14 ) ;
if ( ! V_24 )
return - V_15 ;
V_26 = V_24 -> V_29 ;
V_27 = F_22 ( V_26 , sizeof( * V_16 -> V_27 ) ,
V_30 ) ;
if ( ! V_27 ) {
V_28 = - V_31 ;
goto free;
}
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
char V_32 [ 10 ] ;
V_27 [ V_25 ] . V_20 = V_25 + 1 ;
snprintf ( V_32 , sizeof( V_32 ) , L_3 , V_25 + 1 ) ;
V_27 [ V_25 ] . V_16 = V_16 ;
F_23 ( & V_27 [ V_25 ] . V_5 ,
V_32 ,
& V_33 ) ;
F_24 ( & V_27 [ V_25 ] . V_5 ,
& V_16 -> V_34 ) ;
}
V_16 -> V_27 = V_27 ;
return 0 ;
free:
F_25 ( V_27 ) ;
V_16 -> V_27 = NULL ;
return V_28 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 ,
V_6 ) ;
struct V_16 * V_16 = F_2 ( V_5 ,
struct V_16 ,
V_35 ) ;
F_25 ( V_16 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 , struct V_4 ,
V_6 ) ;
struct V_16 * V_16 = F_2 ( V_5 ,
struct V_16 ,
V_34 ) ;
F_25 ( V_16 -> V_27 ) ;
V_16 -> V_27 = NULL ;
}
static struct V_4 * F_28 ( struct V_4 * V_5 ,
const char * V_10 )
{
int V_28 = - V_15 ;
struct V_11 * V_14 = F_5 ( F_3 ,
( void * ) V_10 ) ;
struct V_16 * V_16 = NULL ;
if ( ! V_14 )
goto V_36;
V_16 = F_29 ( sizeof( * V_16 ) , V_30 ) ;
if ( ! V_16 ) {
V_28 = - V_31 ;
goto V_36;
}
strncpy ( V_16 -> V_10 , V_10 , sizeof( V_16 -> V_10 ) ) ;
F_23 ( & V_16 -> V_34 , L_4 ,
& V_37 ) ;
V_28 = F_20 ( V_16 , V_14 ) ;
if ( V_28 )
goto V_36;
F_23 ( & V_16 -> V_35 , V_10 ,
& V_38 ) ;
F_24 ( & V_16 -> V_34 ,
& V_16 -> V_35 ) ;
F_7 ( V_14 ) ;
return & V_16 -> V_35 ;
V_36:
if ( V_14 )
F_7 ( V_14 ) ;
F_25 ( V_16 ) ;
return F_30 ( V_28 ) ;
}
int T_4 F_31 ( void )
{
F_32 ( & V_39 . V_40 ) ;
F_33 ( & V_39 . V_41 ) ;
return F_34 ( & V_39 ) ;
}
void T_5 F_35 ( void )
{
F_36 ( & V_39 ) ;
}
