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
F_8 ( & V_8 -> V_12 ) ;
}
return V_8 ;
}
static int F_9 ( struct V_13 * V_14 , unsigned V_15 , char * * V_16 )
{
struct V_7 * V_8 ;
V_8 = F_5 () ;
if ( ! V_8 )
return - V_17 ;
V_14 -> V_18 = V_8 ;
return 0 ;
}
static void F_10 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_18 ;
F_1 ( & V_8 -> V_10 ) ;
F_1 ( & V_8 -> V_11 ) ;
F_4 ( V_8 ) ;
V_14 -> V_18 = NULL ;
}
static int F_11 ( struct V_13 * V_14 , struct V_19 * V_20 ,
T_1 type , char * V_21 , unsigned int V_22 )
{
struct V_3 * V_4 ;
int V_23 = 0 ;
if ( ! V_20 )
F_12 ( L_1 ) ;
else {
switch( type ) {
case V_24 :
break;
case V_25 :
V_4 = V_20 -> V_26 ;
F_12 ( L_2 , V_4 -> V_27 ) ;
break;
}
}
return V_23 ;
}
static int F_13 ( struct V_13 * V_14 , struct V_19 * V_20 ,
int V_15 , char * * V_16 , char * * error )
{
struct V_7 * V_8 = V_14 -> V_18 ;
struct V_3 * V_4 ;
unsigned V_27 = V_28 ;
char V_29 ;
unsigned long V_30 ;
if ( V_15 > 1 ) {
* error = L_3 ;
return - V_31 ;
}
if ( ( V_15 == 1 ) && ( sscanf ( V_16 [ 0 ] , L_4 , & V_27 , & V_29 ) != 1 ) ) {
* error = L_5 ;
return - V_31 ;
}
if ( V_27 > 1 ) {
F_14 ( L_6 ) ;
V_27 = 1 ;
}
V_4 = F_6 ( sizeof( * V_4 ) , V_9 ) ;
if ( ! V_4 ) {
* error = L_7 ;
return - V_17 ;
}
V_4 -> V_20 = V_20 ;
V_4 -> V_27 = V_27 ;
V_20 -> V_26 = V_4 ;
F_15 ( & V_8 -> V_12 , V_30 ) ;
F_16 ( & V_4 -> V_6 , & V_8 -> V_10 ) ;
F_17 ( & V_8 -> V_12 , V_30 ) ;
return 0 ;
}
static void F_18 ( struct V_13 * V_14 , struct V_19 * V_32 )
{
unsigned long V_30 ;
struct V_7 * V_8 = V_14 -> V_18 ;
struct V_3 * V_4 = V_32 -> V_26 ;
F_15 ( & V_8 -> V_12 , V_30 ) ;
F_19 ( & V_4 -> V_6 , & V_8 -> V_11 ) ;
F_17 ( & V_8 -> V_12 , V_30 ) ;
}
static int F_20 ( struct V_13 * V_14 , struct V_19 * V_32 )
{
unsigned long V_30 ;
struct V_7 * V_8 = V_14 -> V_18 ;
struct V_3 * V_4 = V_32 -> V_26 ;
F_15 ( & V_8 -> V_12 , V_30 ) ;
F_19 ( & V_4 -> V_6 , & V_8 -> V_10 ) ;
F_17 ( & V_8 -> V_12 , V_30 ) ;
return 0 ;
}
static struct V_19 * F_21 ( struct V_13 * V_14 , T_2 V_33 )
{
unsigned long V_30 ;
struct V_7 * V_8 = V_14 -> V_18 ;
struct V_3 * V_4 = NULL ;
F_15 ( & V_8 -> V_12 , V_30 ) ;
if ( ! F_22 ( & V_8 -> V_10 ) ) {
V_4 = F_23 ( V_8 -> V_10 . V_5 , struct V_3 , V_6 ) ;
F_24 ( & V_4 -> V_6 , & V_8 -> V_10 ) ;
}
F_17 ( & V_8 -> V_12 , V_30 ) ;
return V_4 ? V_4 -> V_20 : NULL ;
}
static int T_3 F_25 ( void )
{
int V_34 = F_26 ( & V_35 ) ;
if ( V_34 < 0 )
F_27 ( L_8 , V_34 ) ;
F_28 ( L_9 V_36 L_10 ) ;
return V_34 ;
}
static void T_4 F_29 ( void )
{
int V_34 = F_30 ( & V_35 ) ;
if ( V_34 < 0 )
F_27 ( L_11 , V_34 ) ;
}
