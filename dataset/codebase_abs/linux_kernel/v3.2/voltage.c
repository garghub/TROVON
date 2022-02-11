unsigned long F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 || F_2 ( V_2 ) ) {
F_3 ( L_1 , V_3 ) ;
return 0 ;
}
return V_2 -> V_4 ;
}
int F_4 ( struct V_1 * V_2 ,
unsigned long V_5 )
{
int V_6 ;
if ( ! V_2 || F_2 ( V_2 ) ) {
F_3 ( L_1 , V_3 ) ;
return - V_7 ;
}
if ( ! V_2 -> V_8 ) {
F_5 ( L_2 ,
V_3 , V_2 -> V_9 ) ;
return - V_10 ;
}
V_6 = V_2 -> V_8 ( V_2 , V_5 ) ;
if ( ! V_6 )
V_2 -> V_4 = V_5 ;
return V_6 ;
}
void F_6 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
if ( ! V_2 || F_2 ( V_2 ) ) {
F_3 ( L_1 , V_3 ) ;
return;
}
V_5 = F_1 ( V_2 ) ;
if ( ! V_5 ) {
F_5 ( L_3 ,
V_3 , V_2 -> V_9 ) ;
return;
}
F_4 ( V_2 , V_5 ) ;
}
void F_7 ( struct V_1 * V_2 ,
struct V_11 * * V_12 )
{
if ( ! V_2 || F_2 ( V_2 ) ) {
F_3 ( L_1 , V_3 ) ;
return;
}
* V_12 = V_2 -> V_12 ;
}
struct V_11 * F_8 ( struct V_1 * V_2 ,
unsigned long V_13 )
{
int V_14 ;
if ( ! V_2 || F_2 ( V_2 ) ) {
F_3 ( L_1 , V_3 ) ;
return F_9 ( - V_7 ) ;
}
if ( ! V_2 -> V_12 ) {
F_3 ( L_4 ,
V_3 , V_2 -> V_9 ) ;
return F_9 ( - V_10 ) ;
}
for ( V_14 = 0 ; V_2 -> V_12 [ V_14 ] . V_15 != 0 ; V_14 ++ ) {
if ( V_2 -> V_12 [ V_14 ] . V_15 == V_13 )
return & V_2 -> V_12 [ V_14 ] ;
}
F_10 ( L_5
L_6 , V_3 , V_2 -> V_9 ) ;
return F_9 ( - V_10 ) ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
if ( ! V_2 || F_2 ( V_2 ) ) {
F_3 ( L_1 , V_3 ) ;
return - V_7 ;
}
V_2 -> V_17 = V_17 ;
return 0 ;
}
void F_12 ( struct V_1 * V_2 ,
int V_18 )
{
if ( ! V_2 || F_2 ( V_2 ) ) {
F_3 ( L_1 , V_3 ) ;
return;
}
switch ( V_18 ) {
case V_19 :
V_2 -> V_8 = V_20 ;
return;
case V_21 :
V_2 -> V_8 = V_22 ;
return;
default:
F_3 ( L_7
L_8 , V_3 ) ;
}
}
int T_1 F_13 ( void )
{
struct V_1 * V_2 ;
if ( F_14 ( & V_23 ) ) {
F_5 ( L_9 ,
V_3 ) ;
return - V_7 ;
}
F_15 (voltdm, &voltdm_list, node) {
struct V_24 * V_25 ;
if ( ! V_2 -> V_26 )
continue;
V_25 = F_16 ( NULL , V_2 -> V_27 . V_9 ) ;
if ( F_2 ( V_25 ) ) {
F_3 ( L_10 , V_3 ) ;
return - V_7 ;
}
V_2 -> V_27 . V_28 = F_17 ( V_25 ) ;
F_18 ( ! V_2 -> V_27 . V_28 ) ;
F_19 ( V_25 ) ;
if ( V_2 -> V_29 ) {
V_2 -> V_8 = V_22 ;
F_20 ( V_2 ) ;
}
if ( V_2 -> V_30 ) {
V_2 -> V_8 = V_20 ;
F_21 ( V_2 ) ;
}
}
return 0 ;
}
static struct V_1 * F_22 ( const char * V_9 )
{
struct V_1 * V_2 , * V_31 ;
V_2 = NULL ;
F_15 (temp_voltdm, &voltdm_list, node) {
if ( ! strcmp ( V_9 , V_31 -> V_9 ) ) {
V_2 = V_31 ;
break;
}
}
return V_2 ;
}
int F_23 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
if ( ! V_2 || ! V_33 )
return - V_7 ;
F_24 ( L_11
L_12 , V_33 -> V_9 , V_2 -> V_9 ) ;
F_25 ( & V_33 -> V_34 , & V_2 -> V_35 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
int (* F_27)( struct V_1 * V_2 ,
struct V_32 * V_33 ) )
{
struct V_32 * V_33 ;
int V_6 = 0 ;
if ( ! F_27 )
return - V_7 ;
F_15 (pwrdm, &voltdm->pwrdm_list, voltdm_node)
V_6 = (* F_27)( V_2 , V_33 ) ;
return V_6 ;
}
int F_28 ( int (* F_27)( struct V_1 * V_2 , void * V_36 ) ,
void * V_36 )
{
struct V_1 * V_31 ;
int V_6 = 0 ;
if ( ! F_27 )
return - V_7 ;
F_15 (temp_voltdm, &voltdm_list, node) {
V_6 = (* F_27)( V_31 , V_36 ) ;
if ( V_6 )
break;
}
return V_6 ;
}
static int F_29 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_9 )
return - V_7 ;
F_30 ( & V_2 -> V_35 ) ;
F_25 ( & V_2 -> V_37 , & V_23 ) ;
F_24 ( L_13 , V_2 -> V_9 ) ;
return 0 ;
}
struct V_1 * F_31 ( const char * V_9 )
{
struct V_1 * V_2 ;
if ( ! V_9 )
return NULL ;
V_2 = F_22 ( V_9 ) ;
return V_2 ;
}
void F_32 ( struct V_1 * * V_38 )
{
struct V_1 * * V_39 ;
if ( V_38 ) {
for ( V_39 = V_38 ; * V_39 ; V_39 ++ )
F_29 ( * V_39 ) ;
}
}
