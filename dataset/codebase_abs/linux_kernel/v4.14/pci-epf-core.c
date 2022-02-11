void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 ) {
F_2 ( & V_2 -> V_4 , L_1 ) ;
return;
}
V_2 -> V_3 -> V_5 -> V_6 ( V_2 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 ) {
F_2 ( & V_2 -> V_4 , L_1 ) ;
return;
}
V_2 -> V_3 -> V_5 -> V_7 ( V_2 ) ;
F_4 ( V_2 -> V_3 -> V_8 ) ;
}
int F_5 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 ) {
F_2 ( & V_2 -> V_4 , L_1 ) ;
return - V_9 ;
}
if ( ! F_6 ( V_2 -> V_3 -> V_8 ) )
return - V_10 ;
return V_2 -> V_3 -> V_5 -> V_11 ( V_2 ) ;
}
void F_7 ( struct V_1 * V_2 , void * V_12 , enum V_13 V_14 )
{
struct V_15 * V_4 = & V_2 -> V_4 ;
if ( ! V_12 )
return;
F_8 ( V_4 , V_2 -> V_14 [ V_14 ] . V_16 , V_12 ,
V_2 -> V_14 [ V_14 ] . V_17 ) ;
V_2 -> V_14 [ V_14 ] . V_17 = 0 ;
V_2 -> V_14 [ V_14 ] . V_16 = 0 ;
}
void * F_9 ( struct V_1 * V_2 , T_1 V_16 , enum V_13 V_14 )
{
void * V_18 ;
struct V_15 * V_4 = & V_2 -> V_4 ;
T_2 V_17 ;
if ( V_16 < 128 )
V_16 = 128 ;
V_16 = F_10 ( V_16 ) ;
V_18 = F_11 ( V_4 , V_16 , & V_17 , V_19 ) ;
if ( ! V_18 ) {
F_12 ( V_4 , L_2 ) ;
return NULL ;
}
V_2 -> V_14 [ V_14 ] . V_17 = V_17 ;
V_2 -> V_14 [ V_14 ] . V_16 = V_16 ;
return V_18 ;
}
void F_13 ( struct V_20 * V_3 )
{
F_14 ( V_3 -> V_21 ) ;
F_15 ( & V_3 -> V_3 ) ;
}
int F_16 ( struct V_20 * V_3 ,
struct V_22 * V_8 )
{
int V_23 ;
if ( ! V_3 -> V_5 )
return - V_9 ;
if ( ! V_3 -> V_5 -> V_11 || ! V_3 -> V_5 -> V_7 || ! V_3 -> V_5 -> V_6 )
return - V_9 ;
V_3 -> V_3 . V_24 = & V_25 ;
V_3 -> V_3 . V_8 = V_8 ;
V_23 = F_17 ( & V_3 -> V_3 ) ;
if ( V_23 )
return V_23 ;
V_3 -> V_21 = F_18 ( V_3 -> V_3 . V_26 ) ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_4 ) ;
}
struct V_1 * F_21 ( const char * V_26 )
{
int V_23 ;
struct V_1 * V_2 ;
struct V_15 * V_4 ;
char * V_27 ;
char * V_28 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 ) {
V_23 = - V_29 ;
goto V_30;
}
V_28 = F_23 ( V_26 , V_19 ) ;
if ( ! V_28 ) {
V_23 = - V_29 ;
goto V_31;
}
V_27 = V_28 ;
V_28 = F_24 ( V_28 , '.' ) ;
* V_28 = '\0' ;
V_2 -> V_26 = F_23 ( V_27 , V_19 ) ;
if ( ! V_2 -> V_26 ) {
V_23 = - V_29 ;
goto V_32;
}
V_4 = & V_2 -> V_4 ;
F_25 ( V_4 ) ;
V_4 -> V_24 = & V_25 ;
V_4 -> type = & V_33 ;
V_23 = F_26 ( V_4 , L_3 , V_26 ) ;
if ( V_23 )
goto V_34;
V_23 = F_27 ( V_4 ) ;
if ( V_23 )
goto V_34;
F_28 ( V_27 ) ;
return V_2 ;
V_34:
F_29 ( V_4 ) ;
F_28 ( V_2 -> V_26 ) ;
V_32:
F_28 ( V_27 ) ;
V_31:
F_28 ( V_2 ) ;
V_30:
return F_30 ( V_23 ) ;
}
const struct V_35 *
F_31 ( const struct V_35 * V_36 , struct V_1 * V_2 )
{
if ( ! V_36 || ! V_2 )
return NULL ;
while ( * V_36 -> V_26 ) {
if ( strcmp ( V_2 -> V_26 , V_36 -> V_26 ) == 0 )
return V_36 ;
V_36 ++ ;
}
return NULL ;
}
static void F_32 ( struct V_15 * V_4 )
{
struct V_1 * V_2 = F_33 ( V_4 ) ;
F_28 ( V_2 -> V_26 ) ;
F_28 ( V_2 ) ;
}
static int
F_34 ( const struct V_35 * V_36 , const struct V_1 * V_2 )
{
while ( V_36 -> V_26 [ 0 ] ) {
if ( strcmp ( V_2 -> V_26 , V_36 -> V_26 ) == 0 )
return true ;
V_36 ++ ;
}
return false ;
}
static int F_35 ( struct V_15 * V_4 , struct V_37 * V_38 )
{
struct V_1 * V_2 = F_33 ( V_4 ) ;
struct V_20 * V_3 = F_36 ( V_38 ) ;
if ( V_3 -> V_39 )
return F_34 ( V_3 -> V_39 , V_2 ) ;
return ! strcmp ( V_2 -> V_26 , V_38 -> V_26 ) ;
}
static int F_37 ( struct V_15 * V_4 )
{
struct V_1 * V_2 = F_33 ( V_4 ) ;
struct V_20 * V_3 = F_36 ( V_4 -> V_3 ) ;
if ( ! V_3 -> V_40 )
return - V_41 ;
V_2 -> V_3 = V_3 ;
return V_3 -> V_40 ( V_2 ) ;
}
static int F_38 ( struct V_15 * V_4 )
{
int V_23 = 0 ;
struct V_1 * V_2 = F_33 ( V_4 ) ;
struct V_20 * V_3 = F_36 ( V_4 -> V_3 ) ;
if ( V_3 -> remove )
V_23 = V_3 -> remove ( V_2 ) ;
V_2 -> V_3 = NULL ;
return V_23 ;
}
static int T_3 F_39 ( void )
{
int V_23 ;
V_23 = F_40 ( & V_25 ) ;
if ( V_23 ) {
F_41 ( L_4 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static void T_4 F_42 ( void )
{
F_43 ( & V_25 ) ;
}
