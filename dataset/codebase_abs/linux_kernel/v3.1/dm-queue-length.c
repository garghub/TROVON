static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( V_2 ) {
F_3 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
}
return V_2 ;
}
static int F_4 ( struct V_6 * V_7 , unsigned V_8 , char * * V_9 )
{
struct V_1 * V_2 = F_1 () ;
if ( ! V_2 )
return - V_10 ;
V_7 -> V_11 = V_2 ;
return 0 ;
}
static void F_5 ( struct V_12 * V_13 )
{
struct V_14 * V_15 , * V_16 ;
F_6 (pi, next, paths, list) {
F_7 ( & V_15 -> V_17 ) ;
F_8 ( V_15 ) ;
}
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_11 ;
F_5 ( & V_2 -> V_4 ) ;
F_5 ( & V_2 -> V_5 ) ;
F_8 ( V_2 ) ;
V_7 -> V_11 = NULL ;
}
static int F_10 ( struct V_6 * V_7 , struct V_18 * V_19 ,
T_1 type , char * V_20 , unsigned V_21 )
{
unsigned V_22 = 0 ;
struct V_14 * V_15 ;
if ( ! V_19 )
F_11 ( L_1 ) ;
else {
V_15 = V_19 -> V_23 ;
switch ( type ) {
case V_24 :
F_11 ( L_2 , F_12 ( & V_15 -> V_25 ) ) ;
break;
case V_26 :
F_11 ( L_3 , V_15 -> V_27 ) ;
break;
}
}
return V_22 ;
}
static int F_13 ( struct V_6 * V_7 , struct V_18 * V_19 ,
int V_8 , char * * V_9 , char * * error )
{
struct V_1 * V_2 = V_7 -> V_11 ;
struct V_14 * V_15 ;
unsigned V_27 = V_28 ;
if ( V_8 > 1 ) {
* error = L_4 ;
return - V_29 ;
}
if ( ( V_8 == 1 ) && ( sscanf ( V_9 [ 0 ] , L_5 , & V_27 ) != 1 ) ) {
* error = L_6 ;
return - V_29 ;
}
V_15 = F_2 ( sizeof( * V_15 ) , V_3 ) ;
if ( ! V_15 ) {
* error = L_7 ;
return - V_10 ;
}
V_15 -> V_19 = V_19 ;
V_15 -> V_27 = V_27 ;
F_14 ( & V_15 -> V_25 , 0 ) ;
V_19 -> V_23 = V_15 ;
F_15 ( & V_15 -> V_17 , & V_2 -> V_4 ) ;
return 0 ;
}
static void F_16 ( struct V_6 * V_7 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_7 -> V_11 ;
struct V_14 * V_15 = V_19 -> V_23 ;
F_17 ( & V_15 -> V_17 , & V_2 -> V_5 ) ;
}
static int F_18 ( struct V_6 * V_7 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_7 -> V_11 ;
struct V_14 * V_15 = V_19 -> V_23 ;
F_19 ( & V_15 -> V_17 , & V_2 -> V_4 ) ;
return 0 ;
}
static struct V_18 * F_20 ( struct V_6 * V_7 ,
unsigned * V_27 , T_2 V_30 )
{
struct V_1 * V_2 = V_7 -> V_11 ;
struct V_14 * V_15 = NULL , * V_31 = NULL ;
if ( F_21 ( & V_2 -> V_4 ) )
return NULL ;
F_19 ( V_2 -> V_4 . V_16 , & V_2 -> V_4 ) ;
F_22 (pi, &s->valid_paths, list) {
if ( ! V_31 ||
( F_12 ( & V_15 -> V_25 ) < F_12 ( & V_31 -> V_25 ) ) )
V_31 = V_15 ;
if ( ! F_12 ( & V_31 -> V_25 ) )
break;
}
if ( ! V_31 )
return NULL ;
* V_27 = V_31 -> V_27 ;
return V_31 -> V_19 ;
}
static int F_23 ( struct V_6 * V_7 , struct V_18 * V_19 ,
T_2 V_30 )
{
struct V_14 * V_15 = V_19 -> V_23 ;
F_24 ( & V_15 -> V_25 ) ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 , struct V_18 * V_19 ,
T_2 V_30 )
{
struct V_14 * V_15 = V_19 -> V_23 ;
F_26 ( & V_15 -> V_25 ) ;
return 0 ;
}
static int T_3 F_27 ( void )
{
int V_32 = F_28 ( & V_33 ) ;
if ( V_32 < 0 )
F_29 ( L_8 , V_32 ) ;
F_30 ( L_9 V_34 L_10 ) ;
return V_32 ;
}
static void T_4 F_31 ( void )
{
int V_32 = F_32 ( & V_33 ) ;
if ( V_32 < 0 )
F_29 ( L_11 , V_32 ) ;
}
