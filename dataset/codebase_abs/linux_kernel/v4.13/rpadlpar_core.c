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
struct V_13 * V_13 , * V_14 ;
F_8 (slot, next, &rpaphp_slot_head,
rpaphp_slot_list) {
if ( V_13 -> V_4 == V_4 )
return V_13 ;
}
return NULL ;
}
static struct V_15 * F_9 ( struct V_16 * V_3 ,
struct V_1 * V_17 )
{
struct V_15 * V_18 = NULL ;
struct V_1 * V_19 ;
F_10 (tmp, &parent->devices, bus_list) {
V_19 = F_11 ( V_18 ) ;
if ( V_19 == V_17 )
return V_18 ;
}
return NULL ;
}
static void F_12 ( struct V_1 * V_4 )
{
struct V_20 * V_21 = F_13 ( V_4 ) ;
struct V_22 * V_23 = V_21 -> V_23 ;
struct V_15 * V_24 = NULL ;
F_14 ( V_21 ) ;
V_24 = F_15 ( V_4 , V_23 -> V_25 , V_21 -> V_26 ) ;
if ( ! V_24 ) {
F_16 ( V_27 L_5 ,
V_28 , V_4 -> V_29 ) ;
return;
}
if ( F_17 ( V_24 ) )
F_18 ( V_24 ) ;
F_19 ( V_24 -> V_30 ) ;
F_20 ( V_23 -> V_25 ) ;
}
static int F_21 ( char * V_2 , struct V_1 * V_4 )
{
struct V_15 * V_24 ;
struct V_22 * V_23 ;
if ( F_22 ( V_4 ) )
return - V_31 ;
F_12 ( V_4 ) ;
V_23 = F_13 ( V_4 ) -> V_23 ;
V_24 = F_9 ( V_23 -> V_25 , V_4 ) ;
if ( ! V_24 ) {
F_16 ( V_27 L_6 , V_28 ,
V_2 ) ;
return - V_32 ;
}
if ( V_24 -> V_33 != V_34 ) {
F_16 ( V_27 L_7 ,
V_28 , V_24 -> V_33 , V_2 ) ;
return - V_32 ;
}
if ( F_23 ( V_4 ) ) {
F_16 ( V_27 L_8 ,
V_28 , V_2 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_24 ( char * V_2 , struct V_1 * V_4 )
{
struct V_13 * V_13 ;
struct V_20 * V_21 ;
int V_6 = 0 ;
if ( ! F_22 ( V_4 ) )
return - V_31 ;
V_13 = F_7 ( V_4 ) ;
if ( V_13 && F_25 ( V_13 ) ) {
F_16 ( V_27 L_9 ,
V_28 , V_2 ) ;
return - V_32 ;
}
V_21 = V_4 -> V_35 ;
F_26 ( ! V_21 || ! V_21 -> V_23 ) ;
V_6 = F_27 ( V_21 -> V_23 ) ;
if ( V_6 < 0 )
return V_6 ;
V_21 -> V_23 = NULL ;
return 0 ;
}
static int F_28 ( char * V_2 , struct V_1 * V_4 )
{
struct V_22 * V_23 ;
if ( F_13 ( V_4 ) && F_13 ( V_4 ) -> V_23 ) {
return - V_31 ;
}
V_23 = F_29 ( V_4 ) ;
if ( ! V_23 )
return - V_32 ;
if ( F_23 ( V_4 ) ) {
F_16 ( V_27 L_8 ,
V_28 , V_2 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_30 ( char * V_2 , struct V_1 * V_4 )
{
struct V_36 * V_36 ;
V_36 = F_31 ( V_4 ) ;
if ( V_36 ) {
F_32 ( & V_36 -> V_24 ) ;
return - V_31 ;
}
if ( ! F_33 ( V_4 ) ) {
F_16 ( V_27
L_10 ,
V_28 , V_2 ) ;
return - V_32 ;
}
return 0 ;
}
int F_34 ( char * V_2 )
{
struct V_1 * V_4 = NULL ;
int V_9 ;
int V_6 = - V_32 ;
if ( F_35 ( & V_37 ) )
return - V_38 ;
V_4 = F_6 ( V_2 , & V_9 ) ;
if ( ! V_4 ) {
V_6 = - V_39 ;
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
F_16 ( V_40 L_11 , V_41 , V_2 ) ;
exit:
F_36 ( & V_37 ) ;
return V_6 ;
}
static int F_37 ( char * V_2 , struct V_1 * V_4 )
{
struct V_36 * V_36 ;
V_36 = F_31 ( V_4 ) ;
if ( ! V_36 )
return - V_31 ;
F_38 ( V_36 ) ;
F_32 ( & V_36 -> V_24 ) ;
return 0 ;
}
int F_39 ( char * V_2 , struct V_1 * V_4 )
{
struct V_16 * V_25 ;
struct V_13 * V_13 ;
int V_42 = 0 ;
F_40 () ;
V_25 = F_22 ( V_4 ) ;
if ( ! V_25 ) {
V_42 = - V_31 ;
goto V_43;
}
F_41 ( L_12 ,
V_25 -> V_44 ? F_42 ( V_25 -> V_44 ) : L_13 ) ;
V_13 = F_7 ( V_4 ) ;
if ( V_13 ) {
F_41 ( L_14 ,
F_43 ( V_25 ) , V_25 -> V_45 ) ;
if ( F_25 ( V_13 ) ) {
F_16 ( V_27
L_9 ,
V_28 , V_2 ) ;
V_42 = - V_32 ;
goto V_43;
}
}
F_44 ( V_25 ) ;
if ( F_45 ( V_25 ) ) {
F_16 ( V_27 L_15 ,
V_28 ) ;
V_42 = - V_46 ;
goto V_43;
}
F_26 ( ! V_25 -> V_44 ) ;
F_41 ( L_16 , F_42 ( V_25 -> V_44 ) ) ;
F_46 ( V_25 -> V_44 ) ;
V_43:
F_47 () ;
return V_42 ;
}
int F_48 ( char * V_2 )
{
struct V_1 * V_4 ;
int V_9 ;
int V_6 = 0 ;
if ( F_35 ( & V_37 ) )
return - V_38 ;
V_4 = F_6 ( V_2 , & V_9 ) ;
if ( ! V_4 ) {
V_6 = - V_39 ;
goto exit;
}
switch ( V_9 ) {
case V_12 :
V_6 = F_37 ( V_2 , V_4 ) ;
break;
case V_11 :
V_6 = F_24 ( V_2 , V_4 ) ;
break;
case V_10 :
V_6 = F_39 ( V_2 , V_4 ) ;
break;
}
F_49 () ;
F_16 ( V_40 L_17 , V_41 , V_2 ) ;
exit:
F_36 ( & V_37 ) ;
return V_6 ;
}
static inline int F_50 ( void )
{
int V_6 = F_51 ( L_18 ) ;
return ( int ) ( V_6 != V_47 ) ;
}
int T_1 F_52 ( void )
{
if ( ! F_50 () ) {
F_16 ( V_48 L_19 ,
V_28 ) ;
return - V_49 ;
}
return F_53 () ;
}
void F_54 ( void )
{
F_55 () ;
return;
}
