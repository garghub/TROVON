static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 (pi, next, paths, list) {
F_3 ( & V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
}
}
static struct V_7 * F_5 ( void )
{
struct V_7 * V_8 = F_6 ( sizeof( * V_8 ) , V_9 ) ;
if ( V_8 ) {
F_7 ( & V_8 -> V_10 ) ;
F_7 ( & V_8 -> V_11 ) ;
}
return V_8 ;
}
static int F_8 ( struct V_12 * V_13 , unsigned V_14 , char * * V_15 )
{
struct V_7 * V_8 ;
V_8 = F_5 () ;
if ( ! V_8 )
return - V_16 ;
V_13 -> V_17 = V_8 ;
return 0 ;
}
static void F_9 ( struct V_12 * V_13 )
{
struct V_7 * V_8 = (struct V_7 * ) V_13 -> V_17 ;
F_1 ( & V_8 -> V_10 ) ;
F_1 ( & V_8 -> V_11 ) ;
F_4 ( V_8 ) ;
V_13 -> V_17 = NULL ;
}
static int F_10 ( struct V_12 * V_13 , struct V_18 * V_19 ,
T_1 type , char * V_20 , unsigned int V_21 )
{
struct V_3 * V_4 ;
int V_22 = 0 ;
if ( ! V_19 )
F_11 ( L_1 ) ;
else {
switch( type ) {
case V_23 :
break;
case V_24 :
V_4 = V_19 -> V_25 ;
F_11 ( L_2 , V_4 -> V_26 ) ;
break;
}
}
return V_22 ;
}
static int F_12 ( struct V_12 * V_13 , struct V_18 * V_19 ,
int V_14 , char * * V_15 , char * * error )
{
struct V_7 * V_8 = (struct V_7 * ) V_13 -> V_17 ;
struct V_3 * V_4 ;
unsigned V_26 = V_27 ;
char V_28 ;
if ( V_14 > 1 ) {
* error = L_3 ;
return - V_29 ;
}
if ( ( V_14 == 1 ) && ( sscanf ( V_15 [ 0 ] , L_4 , & V_26 , & V_28 ) != 1 ) ) {
* error = L_5 ;
return - V_29 ;
}
V_4 = F_6 ( sizeof( * V_4 ) , V_9 ) ;
if ( ! V_4 ) {
* error = L_6 ;
return - V_16 ;
}
V_4 -> V_19 = V_19 ;
V_4 -> V_26 = V_26 ;
V_19 -> V_25 = V_4 ;
F_13 ( & V_4 -> V_6 , & V_8 -> V_10 ) ;
return 0 ;
}
static void F_14 ( struct V_12 * V_13 , struct V_18 * V_30 )
{
struct V_7 * V_8 = (struct V_7 * ) V_13 -> V_17 ;
struct V_3 * V_4 = V_30 -> V_25 ;
F_15 ( & V_4 -> V_6 , & V_8 -> V_11 ) ;
}
static int F_16 ( struct V_12 * V_13 , struct V_18 * V_30 )
{
struct V_7 * V_8 = (struct V_7 * ) V_13 -> V_17 ;
struct V_3 * V_4 = V_30 -> V_25 ;
F_15 ( & V_4 -> V_6 , & V_8 -> V_10 ) ;
return 0 ;
}
static struct V_18 * F_17 ( struct V_12 * V_13 ,
unsigned * V_26 , T_2 V_31 )
{
struct V_7 * V_8 = (struct V_7 * ) V_13 -> V_17 ;
struct V_3 * V_4 = NULL ;
if ( ! F_18 ( & V_8 -> V_10 ) ) {
V_4 = F_19 ( V_8 -> V_10 . V_5 , struct V_3 , V_6 ) ;
F_20 ( & V_4 -> V_6 , & V_8 -> V_10 ) ;
* V_26 = V_4 -> V_26 ;
}
return V_4 ? V_4 -> V_19 : NULL ;
}
static int T_3 F_21 ( void )
{
int V_32 = F_22 ( & V_33 ) ;
if ( V_32 < 0 )
F_23 ( L_7 , V_32 ) ;
F_24 ( L_8 ) ;
return V_32 ;
}
static void T_4 F_25 ( void )
{
int V_32 = F_26 ( & V_33 ) ;
if ( V_32 < 0 )
F_23 ( L_9 , V_32 ) ;
}
