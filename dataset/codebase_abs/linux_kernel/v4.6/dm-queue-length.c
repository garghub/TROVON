static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( V_2 ) {
F_3 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
}
return V_2 ;
}
static int F_5 ( struct V_7 * V_8 , unsigned V_9 , char * * V_10 )
{
struct V_1 * V_2 = F_1 () ;
if ( ! V_2 )
return - V_11 ;
V_8 -> V_12 = V_2 ;
return 0 ;
}
static void F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 , * V_17 ;
F_7 (pi, next, paths, list) {
F_8 ( & V_16 -> V_18 ) ;
F_9 ( V_16 ) ;
}
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
F_6 ( & V_2 -> V_4 ) ;
F_6 ( & V_2 -> V_5 ) ;
F_9 ( V_2 ) ;
V_8 -> V_12 = NULL ;
}
static int F_11 ( struct V_7 * V_8 , struct V_19 * V_20 ,
T_1 type , char * V_21 , unsigned V_22 )
{
unsigned V_23 = 0 ;
struct V_15 * V_16 ;
if ( ! V_20 )
F_12 ( L_1 ) ;
else {
V_16 = V_20 -> V_24 ;
switch ( type ) {
case V_25 :
F_12 ( L_2 , F_13 ( & V_16 -> V_26 ) ) ;
break;
case V_27 :
F_12 ( L_3 , V_16 -> V_28 ) ;
break;
}
}
return V_23 ;
}
static int F_14 ( struct V_7 * V_8 , struct V_19 * V_20 ,
int V_9 , char * * V_10 , char * * error )
{
struct V_1 * V_2 = V_8 -> V_12 ;
struct V_15 * V_16 ;
unsigned V_28 = V_29 ;
char V_30 ;
unsigned long V_31 ;
if ( V_9 > 1 ) {
* error = L_4 ;
return - V_32 ;
}
if ( ( V_9 == 1 ) && ( sscanf ( V_10 [ 0 ] , L_5 , & V_28 , & V_30 ) != 1 ) ) {
* error = L_6 ;
return - V_32 ;
}
if ( V_28 > 1 ) {
F_15 ( L_7 ) ;
V_28 = 1 ;
}
V_16 = F_2 ( sizeof( * V_16 ) , V_3 ) ;
if ( ! V_16 ) {
* error = L_8 ;
return - V_11 ;
}
V_16 -> V_20 = V_20 ;
V_16 -> V_28 = V_28 ;
F_16 ( & V_16 -> V_26 , 0 ) ;
V_20 -> V_24 = V_16 ;
F_17 ( & V_2 -> V_6 , V_31 ) ;
F_18 ( & V_16 -> V_18 , & V_2 -> V_4 ) ;
F_19 ( & V_2 -> V_6 , V_31 ) ;
return 0 ;
}
static void F_20 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
struct V_15 * V_16 = V_20 -> V_24 ;
unsigned long V_31 ;
F_17 ( & V_2 -> V_6 , V_31 ) ;
F_21 ( & V_16 -> V_18 , & V_2 -> V_5 ) ;
F_19 ( & V_2 -> V_6 , V_31 ) ;
}
static int F_22 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
struct V_15 * V_16 = V_20 -> V_24 ;
unsigned long V_31 ;
F_17 ( & V_2 -> V_6 , V_31 ) ;
F_23 ( & V_16 -> V_18 , & V_2 -> V_4 ) ;
F_19 ( & V_2 -> V_6 , V_31 ) ;
return 0 ;
}
static struct V_19 * F_24 ( struct V_7 * V_8 , T_2 V_33 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
struct V_15 * V_16 = NULL , * V_34 = NULL ;
struct V_19 * V_35 = NULL ;
unsigned long V_31 ;
F_17 ( & V_2 -> V_6 , V_31 ) ;
if ( F_25 ( & V_2 -> V_4 ) )
goto V_36;
F_23 ( V_2 -> V_4 . V_17 , & V_2 -> V_4 ) ;
F_26 (pi, &s->valid_paths, list) {
if ( ! V_34 ||
( F_13 ( & V_16 -> V_26 ) < F_13 ( & V_34 -> V_26 ) ) )
V_34 = V_16 ;
if ( ! F_13 ( & V_34 -> V_26 ) )
break;
}
if ( ! V_34 )
goto V_36;
V_35 = V_34 -> V_20 ;
V_36:
F_19 ( & V_2 -> V_6 , V_31 ) ;
return V_35 ;
}
static int F_27 ( struct V_7 * V_8 , struct V_19 * V_20 ,
T_2 V_33 )
{
struct V_15 * V_16 = V_20 -> V_24 ;
F_28 ( & V_16 -> V_26 ) ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 , struct V_19 * V_20 ,
T_2 V_33 )
{
struct V_15 * V_16 = V_20 -> V_24 ;
F_30 ( & V_16 -> V_26 ) ;
return 0 ;
}
static int T_3 F_31 ( void )
{
int V_37 = F_32 ( & V_38 ) ;
if ( V_37 < 0 )
F_33 ( L_9 , V_37 ) ;
F_34 ( L_10 V_39 L_11 ) ;
return V_37 ;
}
static void T_4 F_35 ( void )
{
int V_37 = F_36 ( & V_38 ) ;
if ( V_37 < 0 )
F_33 ( L_12 , V_37 ) ;
}
