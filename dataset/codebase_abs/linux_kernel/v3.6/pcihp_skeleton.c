static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
int V_4 = 0 ;
F_2 ( L_1 , V_5 , V_1 -> V_6 ) ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
int V_4 = 0 ;
F_2 ( L_1 , V_5 , V_1 -> V_6 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_1 , T_1 V_7 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
int V_4 = 0 ;
F_2 ( L_1 , V_5 , V_1 -> V_6 ) ;
switch ( V_7 ) {
case 0 :
break;
case 1 :
default:
break;
}
return V_4 ;
}
static int F_5 ( struct V_1 * V_1 , T_2 V_8 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
int V_4 = 0 ;
F_2 ( L_1 , V_5 , V_1 -> V_6 ) ;
switch ( V_8 ) {
case 0 :
break;
case 1 :
break;
}
return V_4 ;
}
static int F_6 ( struct V_1 * V_1 , T_1 * V_8 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
int V_4 = 0 ;
F_2 ( L_1 , V_5 , V_1 -> V_6 ) ;
return V_4 ;
}
static int F_7 ( struct V_1 * V_1 , T_1 * V_8 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
int V_4 = 0 ;
F_2 ( L_1 , V_5 , V_1 -> V_6 ) ;
return V_4 ;
}
static int F_8 ( struct V_1 * V_1 , T_1 * V_8 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
int V_4 = 0 ;
F_2 ( L_1 , V_5 , V_1 -> V_6 ) ;
return V_4 ;
}
static int F_9 ( struct V_1 * V_1 , T_1 * V_8 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
int V_4 = 0 ;
F_2 ( L_1 , V_5 , V_1 -> V_6 ) ;
return V_4 ;
}
static void F_10 ( struct V_1 * V_1 )
{
struct V_2 * V_2 = V_1 -> V_3 ;
F_2 ( L_1 , V_5 , V_1 -> V_6 ) ;
F_11 ( V_2 -> V_1 -> V_9 ) ;
F_11 ( V_2 -> V_1 ) ;
F_11 ( V_2 ) ;
}
static void F_12 ( struct V_2 * V_2 )
{
snprintf ( V_2 -> V_1 -> V_6 , V_10 , L_2 , V_2 -> V_11 ) ;
}
static int T_3 F_13 ( void )
{
struct V_2 * V_2 ;
struct V_1 * V_1 ;
struct V_12 * V_9 ;
int V_4 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; ++ V_13 ) {
V_2 = F_14 ( sizeof( * V_2 ) , V_15 ) ;
if ( ! V_2 ) {
V_4 = - V_16 ;
goto error;
}
V_1 = F_14 ( sizeof( * V_1 ) , V_15 ) ;
if ( ! V_1 ) {
V_4 = - V_16 ;
goto V_17;
}
V_2 -> V_1 = V_1 ;
V_9 = F_14 ( sizeof( * V_9 ) , V_15 ) ;
if ( ! V_9 ) {
V_4 = - V_16 ;
goto V_18;
}
V_1 -> V_9 = V_9 ;
V_2 -> V_11 = V_13 ;
V_1 -> V_6 = V_2 -> V_6 ;
V_1 -> V_3 = V_2 ;
V_1 -> V_19 = & F_10 ;
F_12 ( V_2 ) ;
V_1 -> V_20 = & V_21 ;
F_6 ( V_1 , & V_9 -> V_22 ) ;
F_7 ( V_1 , & V_9 -> V_23 ) ;
F_8 ( V_1 , & V_9 -> V_24 ) ;
F_9 ( V_1 , & V_9 -> V_25 ) ;
F_2 ( L_3 , V_13 ) ;
V_4 = F_15 ( V_2 -> V_1 ) ;
if ( V_4 ) {
F_16 ( L_4 , V_4 ) ;
goto V_26;
}
F_17 ( & V_2 -> V_27 , & V_27 ) ;
}
return 0 ;
V_26:
F_11 ( V_9 ) ;
V_18:
F_11 ( V_1 ) ;
V_17:
F_11 ( V_2 ) ;
error:
return V_4 ;
}
static void T_4 F_18 ( void )
{
struct V_28 * V_29 ;
struct V_28 * V_30 ;
struct V_2 * V_2 ;
F_19 (tmp, next, &slot_list) {
V_2 = F_20 ( V_29 , struct V_2 , V_27 ) ;
F_21 ( & V_2 -> V_27 ) ;
F_22 ( V_2 -> V_1 ) ;
}
}
static int T_3 F_23 ( void )
{
int V_4 ;
V_9 ( V_31 L_5 V_32 L_6 ) ;
V_14 = 5 ;
return F_13 () ;
}
static void T_4 F_24 ( void )
{
F_18 () ;
}
