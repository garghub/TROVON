static struct V_1 * F_1 ( char * V_2 )
{
struct V_1 * V_3 = F_2 ( NULL , L_1 ) ;
struct V_1 * V_4 = NULL ;
char * V_5 ;
int V_6 ;
if ( ! V_3 )
return NULL ;
while ( ( V_4 = F_3 ( V_3 , V_4 ) ) ) {
V_6 = F_4 ( V_4 , NULL , & V_5 , NULL , NULL ) ;
if ( ( V_6 == 0 ) && ( ! strcmp ( V_2 , V_5 ) ) )
break;
}
return V_4 ;
}
static struct V_1 * F_5 ( char * V_2 ,
char * V_7 )
{
struct V_1 * V_8 = NULL ;
char * V_5 ;
char * type ;
int V_6 ;
while ( ( V_8 = F_2 ( V_8 , L_2 ) ) ) {
V_6 = F_4 ( V_8 , NULL , & V_5 , & type , NULL ) ;
if ( V_6 == 0 )
if ( ! strcmp ( V_2 , V_5 ) && ! strcmp ( V_7 , type ) )
break;
}
return V_8 ;
}
static struct V_1 * F_6 ( char * V_2 , int * V_9 )
{
struct V_1 * V_4 ;
V_4 = F_5 ( V_2 , L_3 ) ;
if ( V_4 ) {
* V_9 = V_10 ;
return V_4 ;
}
V_4 = F_5 ( V_2 , L_4 ) ;
if ( V_4 ) {
* V_9 = V_11 ;
return V_4 ;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 ) {
* V_9 = V_12 ;
return V_4 ;
}
return NULL ;
}
static struct V_13 * F_7 ( struct V_1 * V_4 )
{
struct V_14 * V_15 , * V_16 ;
struct V_13 * V_13 ;
F_8 (tmp, n, &rpaphp_slot_head) {
V_13 = F_9 ( V_15 , struct V_13 , V_17 ) ;
if ( V_13 -> V_4 == V_4 )
return V_13 ;
}
return NULL ;
}
static struct V_18 * F_10 ( struct V_19 * V_3 ,
struct V_1 * V_20 )
{
struct V_18 * V_15 = NULL ;
struct V_1 * V_21 ;
F_11 (tmp, &parent->devices, bus_list) {
V_21 = F_12 ( V_15 ) ;
if ( V_21 == V_20 )
return V_15 ;
}
return NULL ;
}
static void F_13 ( struct V_1 * V_4 )
{
struct V_22 * V_23 = F_14 ( V_4 ) ;
struct V_24 * V_25 = V_23 -> V_25 ;
struct V_18 * V_26 = NULL ;
F_15 ( V_4 ) ;
V_26 = F_16 ( V_4 , V_25 -> V_27 , V_23 -> V_28 ) ;
if ( ! V_26 ) {
F_17 ( V_29 L_5 ,
V_30 , V_4 -> V_31 ) ;
return;
}
if ( V_26 -> V_32 == V_33 ||
V_26 -> V_32 == V_34 )
F_18 ( V_26 ) ;
F_19 ( V_26 -> V_35 ) ;
F_20 ( V_25 -> V_27 ) ;
}
static int F_21 ( char * V_2 , struct V_1 * V_4 )
{
struct V_18 * V_26 ;
struct V_24 * V_25 ;
if ( F_22 ( V_4 ) )
return - V_36 ;
F_13 ( V_4 ) ;
V_25 = F_14 ( V_4 ) -> V_25 ;
V_26 = F_10 ( V_25 -> V_27 , V_4 ) ;
if ( ! V_26 ) {
F_17 ( V_29 L_6 , V_30 ,
V_2 ) ;
return - V_37 ;
}
if ( V_26 -> V_32 != V_33 ) {
F_17 ( V_29 L_7 ,
V_30 , V_26 -> V_32 , V_2 ) ;
return - V_37 ;
}
if ( F_23 ( V_4 ) ) {
F_17 ( V_29 L_8 ,
V_30 , V_2 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_24 ( char * V_2 , struct V_1 * V_4 )
{
struct V_13 * V_13 ;
struct V_22 * V_23 ;
int V_6 = 0 ;
if ( ! F_22 ( V_4 ) )
return - V_36 ;
V_13 = F_7 ( V_4 ) ;
if ( V_13 && F_25 ( V_13 ) ) {
F_17 ( V_29 L_9 ,
V_30 , V_2 ) ;
return - V_37 ;
}
V_23 = V_4 -> V_38 ;
F_26 ( ! V_23 || ! V_23 -> V_25 ) ;
V_6 = F_27 ( V_23 -> V_25 ) ;
if ( V_6 < 0 )
return V_6 ;
V_23 -> V_25 = NULL ;
return 0 ;
}
static int F_28 ( char * V_2 , struct V_1 * V_4 )
{
struct V_24 * V_25 ;
if ( F_14 ( V_4 ) && F_14 ( V_4 ) -> V_25 ) {
return - V_36 ;
}
V_25 = F_29 ( V_4 ) ;
if ( ! V_25 )
return - V_37 ;
if ( F_23 ( V_4 ) ) {
F_17 ( V_29 L_8 ,
V_30 , V_2 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_30 ( char * V_2 , struct V_1 * V_4 )
{
if ( F_31 ( V_4 ) )
return - V_36 ;
if ( ! F_32 ( V_4 ) ) {
F_17 ( V_29
L_10 ,
V_30 , V_2 ) ;
return - V_37 ;
}
return 0 ;
}
int F_33 ( char * V_2 )
{
struct V_1 * V_4 = NULL ;
int V_9 ;
int V_6 = - V_37 ;
if ( F_34 ( & V_39 ) )
return - V_40 ;
V_4 = F_6 ( V_2 , & V_9 ) ;
if ( ! V_4 ) {
V_6 = - V_41 ;
goto exit;
}
switch ( V_9 ) {
case V_12 :
V_6 = F_30 ( V_2 , V_4 ) ;
break;
case V_10 :
V_6 = F_21 ( V_2 , V_4 ) ;
break;
case V_11 :
V_6 = F_28 ( V_2 , V_4 ) ;
break;
}
F_17 ( V_42 L_11 , V_43 , V_2 ) ;
exit:
F_35 ( & V_39 ) ;
return V_6 ;
}
static int F_36 ( char * V_2 , struct V_1 * V_4 )
{
struct V_44 * V_44 ;
V_44 = F_31 ( V_4 ) ;
if ( ! V_44 )
return - V_36 ;
F_37 ( V_44 ) ;
return 0 ;
}
int F_38 ( char * V_2 , struct V_1 * V_4 )
{
struct V_19 * V_27 ;
struct V_13 * V_13 ;
V_27 = F_22 ( V_4 ) ;
if ( ! V_27 )
return - V_36 ;
F_39 ( L_12 ,
V_27 -> V_45 ? F_40 ( V_27 -> V_45 ) : L_13 ) ;
V_13 = F_7 ( V_4 ) ;
if ( V_13 ) {
F_39 ( L_14 ,
F_41 ( V_27 ) , V_27 -> V_46 ) ;
if ( F_25 ( V_13 ) ) {
F_17 ( V_29
L_9 ,
V_30 , V_2 ) ;
return - V_37 ;
}
}
F_42 ( V_27 ) ;
if ( F_43 ( V_27 ) ) {
F_17 ( V_29 L_15 ,
V_30 ) ;
return - V_47 ;
}
F_26 ( ! V_27 -> V_45 ) ;
F_39 ( L_16 , F_40 ( V_27 -> V_45 ) ) ;
F_44 ( V_27 -> V_45 ) ;
F_45 ( V_27 -> V_45 ) ;
return 0 ;
}
int F_46 ( char * V_2 )
{
struct V_1 * V_4 ;
int V_9 ;
int V_6 = 0 ;
if ( F_34 ( & V_39 ) )
return - V_40 ;
V_4 = F_6 ( V_2 , & V_9 ) ;
if ( ! V_4 ) {
V_6 = - V_41 ;
goto exit;
}
switch ( V_9 ) {
case V_12 :
V_6 = F_36 ( V_2 , V_4 ) ;
break;
case V_11 :
V_6 = F_24 ( V_2 , V_4 ) ;
break;
case V_10 :
V_6 = F_38 ( V_2 , V_4 ) ;
break;
}
F_47 () ;
F_17 ( V_42 L_17 , V_43 , V_2 ) ;
exit:
F_35 ( & V_39 ) ;
return V_6 ;
}
static inline int F_48 ( void )
{
int V_6 = F_49 ( L_18 ) ;
return ( int ) ( V_6 != V_48 ) ;
}
int T_1 F_50 ( void )
{
int V_6 = 0 ;
if ( ! F_48 () ) {
F_17 ( V_49 L_19 ,
V_30 ) ;
return - V_50 ;
}
V_6 = F_51 () ;
return V_6 ;
}
void F_52 ( void )
{
F_53 () ;
return;
}
