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
int V_6 , V_7 ;
unsigned long V_8 = 0 ;
if ( ! V_2 || F_2 ( V_2 ) ) {
F_3 ( L_1 , V_3 ) ;
return - V_9 ;
}
if ( ! V_2 -> V_10 ) {
F_5 ( L_2 ,
V_3 , V_2 -> V_11 ) ;
return - V_12 ;
}
for ( V_7 = 0 ; V_2 -> V_13 [ V_7 ] . V_14 != 0 ; V_7 ++ ) {
if ( V_2 -> V_13 [ V_7 ] . V_14 >= V_5 ) {
V_8 = V_2 -> V_13 [ V_7 ] . V_14 ;
break;
}
}
if ( ! V_8 ) {
F_3 ( L_3 ,
V_3 , V_5 ) ;
return - V_9 ;
}
V_6 = V_2 -> V_10 ( V_2 , V_8 ) ;
if ( ! V_6 )
V_2 -> V_4 = V_8 ;
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
F_5 ( L_4 ,
V_3 , V_2 -> V_11 ) ;
return;
}
F_4 ( V_2 , V_5 ) ;
}
void F_7 ( struct V_1 * V_2 ,
struct V_15 * * V_13 )
{
if ( ! V_2 || F_2 ( V_2 ) ) {
F_3 ( L_1 , V_3 ) ;
return;
}
* V_13 = V_2 -> V_13 ;
}
struct V_15 * F_8 ( struct V_1 * V_2 ,
unsigned long V_8 )
{
int V_7 ;
if ( ! V_2 || F_2 ( V_2 ) ) {
F_3 ( L_1 , V_3 ) ;
return F_9 ( - V_9 ) ;
}
if ( ! V_2 -> V_13 ) {
F_3 ( L_5 ,
V_3 , V_2 -> V_11 ) ;
return F_9 ( - V_12 ) ;
}
for ( V_7 = 0 ; V_2 -> V_13 [ V_7 ] . V_14 != 0 ; V_7 ++ ) {
if ( V_2 -> V_13 [ V_7 ] . V_14 == V_8 )
return & V_2 -> V_13 [ V_7 ] ;
}
F_10 ( L_6 ,
V_3 , V_2 -> V_11 ) ;
return F_9 ( - V_12 ) ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
if ( ! V_2 || F_2 ( V_2 ) ) {
F_3 ( L_1 , V_3 ) ;
return - V_9 ;
}
V_2 -> V_17 = V_17 ;
return 0 ;
}
int T_1 F_12 ( void )
{
struct V_1 * V_2 ;
if ( F_13 ( & V_18 ) ) {
F_5 ( L_7 ,
V_3 ) ;
return - V_9 ;
}
F_14 (voltdm, &voltdm_list, node) {
struct V_19 * V_20 ;
if ( ! V_2 -> V_21 )
continue;
V_20 = F_15 ( NULL , V_2 -> V_22 . V_11 ) ;
if ( F_2 ( V_20 ) ) {
F_3 ( L_8 , V_3 ) ;
return - V_9 ;
}
V_2 -> V_22 . V_23 = F_16 ( V_20 ) ;
F_17 ( ! V_2 -> V_22 . V_23 ) ;
F_18 ( V_20 ) ;
if ( V_2 -> V_24 ) {
V_2 -> V_10 = V_25 ;
F_19 ( V_2 ) ;
}
if ( V_2 -> V_26 ) {
V_2 -> V_10 = V_27 ;
F_20 ( V_2 ) ;
}
}
return 0 ;
}
static struct V_1 * F_21 ( const char * V_11 )
{
struct V_1 * V_2 , * V_28 ;
V_2 = NULL ;
F_14 (temp_voltdm, &voltdm_list, node) {
if ( ! strcmp ( V_11 , V_28 -> V_11 ) ) {
V_2 = V_28 ;
break;
}
}
return V_2 ;
}
static int F_22 ( struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_11 )
return - V_9 ;
F_23 ( & V_2 -> V_29 , & V_18 ) ;
F_24 ( L_9 , V_2 -> V_11 ) ;
return 0 ;
}
struct V_1 * F_25 ( const char * V_11 )
{
struct V_1 * V_2 ;
if ( ! V_11 )
return NULL ;
V_2 = F_21 ( V_11 ) ;
return V_2 ;
}
void F_26 ( struct V_1 * * V_30 )
{
struct V_1 * * V_31 ;
if ( V_30 ) {
for ( V_31 = V_30 ; * V_31 ; V_31 ++ )
F_22 ( * V_31 ) ;
}
}
