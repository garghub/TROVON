static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 (pi, next, paths, list) {
F_3 ( & V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
}
}
static void F_5 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
int V_11 ;
F_6 ( V_11 )
* F_7 ( V_8 -> V_12 , V_11 ) = V_10 ;
}
static struct V_7 * F_8 ( void )
{
struct V_7 * V_8 = F_9 ( sizeof( * V_8 ) , V_13 ) ;
if ( ! V_8 )
return NULL ;
F_10 ( & V_8 -> V_14 ) ;
F_10 ( & V_8 -> V_15 ) ;
F_11 ( & V_8 -> V_16 ) ;
V_8 -> V_12 = F_12 ( struct V_9 * ) ;
if ( ! V_8 -> V_12 )
goto V_17;
F_5 ( V_8 , NULL ) ;
if ( F_13 ( & V_8 -> V_18 , 0 , V_13 ) )
goto V_19;
return V_8 ;
V_19:
F_14 ( V_8 -> V_12 ) ;
V_17:
F_4 ( V_8 ) ;
return NULL ; ;
}
static int F_15 ( struct V_20 * V_21 , unsigned V_22 , char * * V_23 )
{
struct V_7 * V_8 ;
V_8 = F_8 () ;
if ( ! V_8 )
return - V_24 ;
V_21 -> V_25 = V_8 ;
return 0 ;
}
static void F_16 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = V_21 -> V_25 ;
F_1 ( & V_8 -> V_14 ) ;
F_1 ( & V_8 -> V_15 ) ;
F_14 ( V_8 -> V_12 ) ;
F_17 ( & V_8 -> V_18 ) ;
F_4 ( V_8 ) ;
V_21 -> V_25 = NULL ;
}
static int F_18 ( struct V_20 * V_21 , struct V_9 * V_10 ,
T_1 type , char * V_26 , unsigned int V_27 )
{
struct V_3 * V_4 ;
int V_28 = 0 ;
if ( ! V_10 )
F_19 ( L_1 ) ;
else {
switch( type ) {
case V_29 :
break;
case V_30 :
V_4 = V_10 -> V_31 ;
F_19 ( L_2 , V_4 -> V_18 ) ;
break;
}
}
return V_28 ;
}
static int F_20 ( struct V_20 * V_21 , struct V_9 * V_10 ,
int V_22 , char * * V_23 , char * * error )
{
struct V_7 * V_8 = V_21 -> V_25 ;
struct V_3 * V_4 ;
unsigned V_18 = V_32 ;
char V_33 ;
unsigned long V_34 ;
if ( V_22 > 1 ) {
* error = L_3 ;
return - V_35 ;
}
if ( ( V_22 == 1 ) && ( sscanf ( V_23 [ 0 ] , L_4 , & V_18 , & V_33 ) != 1 ) ) {
* error = L_5 ;
return - V_35 ;
}
V_4 = F_9 ( sizeof( * V_4 ) , V_13 ) ;
if ( ! V_4 ) {
* error = L_6 ;
return - V_24 ;
}
V_4 -> V_10 = V_10 ;
V_4 -> V_18 = V_18 ;
V_10 -> V_31 = V_4 ;
F_21 ( & V_8 -> V_16 , V_34 ) ;
F_22 ( & V_4 -> V_6 , & V_8 -> V_14 ) ;
F_23 ( & V_8 -> V_16 , V_34 ) ;
return 0 ;
}
static void F_24 ( struct V_20 * V_21 , struct V_9 * V_36 )
{
unsigned long V_34 ;
struct V_7 * V_8 = V_21 -> V_25 ;
struct V_3 * V_4 = V_36 -> V_31 ;
F_21 ( & V_8 -> V_16 , V_34 ) ;
if ( V_36 == * F_25 ( V_8 -> V_12 ) )
F_5 ( V_8 , NULL ) ;
F_26 ( & V_4 -> V_6 , & V_8 -> V_15 ) ;
F_23 ( & V_8 -> V_16 , V_34 ) ;
}
static int F_27 ( struct V_20 * V_21 , struct V_9 * V_36 )
{
unsigned long V_34 ;
struct V_7 * V_8 = V_21 -> V_25 ;
struct V_3 * V_4 = V_36 -> V_31 ;
F_21 ( & V_8 -> V_16 , V_34 ) ;
F_26 ( & V_4 -> V_6 , & V_8 -> V_14 ) ;
F_23 ( & V_8 -> V_16 , V_34 ) ;
return 0 ;
}
static struct V_9 * F_28 ( struct V_20 * V_21 , T_2 V_37 )
{
unsigned long V_34 ;
struct V_7 * V_8 = V_21 -> V_25 ;
struct V_3 * V_4 = NULL ;
struct V_9 * V_12 = NULL ;
F_29 ( V_34 ) ;
V_12 = * F_25 ( V_8 -> V_12 ) ;
if ( V_12 ) {
F_30 ( & V_8 -> V_18 ) ;
if ( F_31 ( & V_8 -> V_18 ) > 0 ) {
F_32 ( V_34 ) ;
return V_12 ;
}
}
F_33 ( & V_8 -> V_16 ) ;
if ( ! F_34 ( & V_8 -> V_14 ) ) {
V_4 = F_35 ( V_8 -> V_14 . V_5 , struct V_3 , V_6 ) ;
F_36 ( & V_4 -> V_6 , & V_8 -> V_14 ) ;
F_37 ( & V_8 -> V_18 , V_4 -> V_18 ) ;
F_5 ( V_8 , V_4 -> V_10 ) ;
V_12 = V_4 -> V_10 ;
}
F_23 ( & V_8 -> V_16 , V_34 ) ;
return V_12 ;
}
static int T_3 F_38 ( void )
{
int V_38 = F_39 ( & V_39 ) ;
if ( V_38 < 0 )
F_40 ( L_7 , V_38 ) ;
F_41 ( L_8 V_40 L_9 ) ;
return V_38 ;
}
static void T_4 F_42 ( void )
{
int V_38 = F_43 ( & V_39 ) ;
if ( V_38 < 0 )
F_40 ( L_10 , V_38 ) ;
}
