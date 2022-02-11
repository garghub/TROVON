static int F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 ,
unsigned char V_5 , bool V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
V_9 = sizeof( * V_8 ) ;
if ( V_9 < V_10 )
V_9 = V_10 ;
V_8 = F_2 ( V_9 , V_11 ) ;
if ( ! V_8 )
return - V_12 ;
memcpy ( V_8 -> V_3 , V_3 , V_4 ) ;
V_8 -> type = V_5 ;
V_8 -> V_13 = 1 ;
V_8 -> V_14 = V_6 ;
V_8 -> V_15 = false ;
F_3 ( & V_8 -> V_2 , & V_2 -> V_2 ) ;
V_2 -> V_16 ++ ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 ,
unsigned char V_5 , bool V_6 )
{
struct V_7 * V_8 ;
if ( V_4 > V_17 )
return - V_18 ;
F_5 (ha, &list->list, list) {
if ( ! memcmp ( V_8 -> V_3 , V_3 , V_4 ) &&
V_8 -> type == V_5 ) {
if ( V_6 ) {
if ( V_8 -> V_14 )
return 0 ;
else
V_8 -> V_14 = true ;
}
V_8 -> V_13 ++ ;
return 0 ;
}
}
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned char * V_3 ,
int V_4 , unsigned char V_5 )
{
return F_4 ( V_2 , V_3 , V_4 , V_5 , false ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 ,
unsigned char V_5 , bool V_6 )
{
struct V_7 * V_8 ;
F_5 (ha, &list->list, list) {
if ( ! memcmp ( V_8 -> V_3 , V_3 , V_4 ) &&
( V_8 -> type == V_5 || ! V_5 ) ) {
if ( V_6 ) {
if ( ! V_8 -> V_14 )
break;
else
V_8 -> V_14 = false ;
}
if ( -- V_8 -> V_13 )
return 0 ;
F_8 ( & V_8 -> V_2 ) ;
F_9 ( V_8 , V_19 ) ;
V_2 -> V_16 -- ;
return 0 ;
}
}
return - V_20 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned char * V_3 ,
int V_4 , unsigned char V_5 )
{
return F_7 ( V_2 , V_3 , V_4 , V_5 , false ) ;
}
int F_11 ( struct V_1 * V_21 ,
struct V_1 * V_22 ,
int V_4 , unsigned char V_5 )
{
int V_23 ;
struct V_7 * V_8 , * V_24 ;
unsigned char type ;
F_5 (ha, &from_list->list, list) {
type = V_5 ? V_5 : V_8 -> type ;
V_23 = F_6 ( V_21 , V_8 -> V_3 , V_4 , type ) ;
if ( V_23 )
goto V_25;
}
return 0 ;
V_25:
F_5 (ha2, &from_list->list, list) {
if ( V_24 == V_8 )
break;
type = V_5 ? V_5 : V_24 -> type ;
F_10 ( V_21 , V_24 -> V_3 , V_4 , type ) ;
}
return V_23 ;
}
void F_12 ( struct V_1 * V_21 ,
struct V_1 * V_22 ,
int V_4 , unsigned char V_5 )
{
struct V_7 * V_8 ;
unsigned char type ;
F_5 (ha, &from_list->list, list) {
type = V_5 ? V_5 : V_8 -> type ;
F_10 ( V_21 , V_8 -> V_3 , V_4 , type ) ;
}
}
int F_13 ( struct V_1 * V_21 ,
struct V_1 * V_22 ,
int V_4 )
{
int V_23 = 0 ;
struct V_7 * V_8 , * V_26 ;
F_14 (ha, tmp, &from_list->list, list) {
if ( ! V_8 -> V_15 ) {
V_23 = F_6 ( V_21 , V_8 -> V_3 ,
V_4 , V_8 -> type ) ;
if ( V_23 )
break;
V_8 -> V_15 = true ;
V_8 -> V_13 ++ ;
} else if ( V_8 -> V_13 == 1 ) {
F_10 ( V_21 , V_8 -> V_3 , V_4 , V_8 -> type ) ;
F_10 ( V_22 , V_8 -> V_3 , V_4 , V_8 -> type ) ;
}
}
return V_23 ;
}
void F_15 ( struct V_1 * V_21 ,
struct V_1 * V_22 ,
int V_4 )
{
struct V_7 * V_8 , * V_26 ;
F_14 (ha, tmp, &from_list->list, list) {
if ( V_8 -> V_15 ) {
F_10 ( V_21 , V_8 -> V_3 ,
V_4 , V_8 -> type ) ;
V_8 -> V_15 = false ;
F_10 ( V_22 , V_8 -> V_3 ,
V_4 , V_8 -> type ) ;
}
}
}
void F_16 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_26 ;
F_14 (ha, tmp, &list->list, list) {
F_8 ( & V_8 -> V_2 ) ;
F_9 ( V_8 , V_19 ) ;
}
V_2 -> V_16 = 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_2 ) ;
V_2 -> V_16 = 0 ;
}
void F_19 ( struct V_27 * V_28 )
{
F_16 ( & V_28 -> V_29 ) ;
V_28 -> V_30 = NULL ;
}
int F_20 ( struct V_27 * V_28 )
{
unsigned char V_3 [ V_17 ] ;
struct V_7 * V_8 ;
int V_23 ;
F_17 ( & V_28 -> V_29 ) ;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
V_23 = F_6 ( & V_28 -> V_29 , V_3 , sizeof( V_3 ) ,
V_31 ) ;
if ( ! V_23 ) {
V_8 = F_21 ( & V_28 -> V_29 . V_2 ,
struct V_7 , V_2 ) ;
V_28 -> V_30 = V_8 -> V_3 ;
}
return V_23 ;
}
int F_22 ( struct V_27 * V_28 , unsigned char * V_3 ,
unsigned char V_5 )
{
int V_23 ;
F_23 () ;
V_23 = F_6 ( & V_28 -> V_29 , V_3 , V_28 -> V_4 , V_5 ) ;
if ( ! V_23 )
F_24 ( V_32 , V_28 ) ;
return V_23 ;
}
int F_25 ( struct V_27 * V_28 , unsigned char * V_3 ,
unsigned char V_5 )
{
int V_23 ;
struct V_7 * V_8 ;
F_23 () ;
V_8 = F_21 ( & V_28 -> V_29 . V_2 ,
struct V_7 , V_2 ) ;
if ( V_8 -> V_3 == V_28 -> V_30 && V_8 -> V_13 == 1 )
return - V_20 ;
V_23 = F_10 ( & V_28 -> V_29 , V_3 , V_28 -> V_4 ,
V_5 ) ;
if ( ! V_23 )
F_24 ( V_32 , V_28 ) ;
return V_23 ;
}
int F_26 ( struct V_27 * V_33 ,
struct V_27 * V_34 ,
unsigned char V_5 )
{
int V_23 ;
F_23 () ;
if ( V_34 -> V_4 != V_33 -> V_4 )
return - V_18 ;
V_23 = F_11 ( & V_33 -> V_29 , & V_34 -> V_29 ,
V_33 -> V_4 , V_5 ) ;
if ( ! V_23 )
F_24 ( V_32 , V_33 ) ;
return V_23 ;
}
int F_27 ( struct V_27 * V_33 ,
struct V_27 * V_34 ,
unsigned char V_5 )
{
F_23 () ;
if ( V_34 -> V_4 != V_33 -> V_4 )
return - V_18 ;
F_12 ( & V_33 -> V_29 , & V_34 -> V_29 ,
V_33 -> V_4 , V_5 ) ;
F_24 ( V_32 , V_33 ) ;
return 0 ;
}
int F_28 ( struct V_27 * V_28 , unsigned char * V_3 )
{
struct V_7 * V_8 ;
int V_23 ;
F_29 ( V_28 ) ;
F_5 (ha, &dev->uc.list, list) {
if ( ! memcmp ( V_8 -> V_3 , V_3 , V_28 -> V_4 ) &&
V_8 -> type == V_35 ) {
V_23 = - V_36 ;
goto V_37;
}
}
V_23 = F_1 ( & V_28 -> V_38 , V_3 , V_28 -> V_4 ,
V_35 , true ) ;
if ( ! V_23 )
F_30 ( V_28 ) ;
V_37:
F_31 ( V_28 ) ;
return V_23 ;
}
int F_32 ( struct V_27 * V_28 , unsigned char * V_3 )
{
int V_23 ;
F_29 ( V_28 ) ;
V_23 = F_6 ( & V_28 -> V_38 , V_3 , V_28 -> V_4 ,
V_35 ) ;
if ( ! V_23 )
F_30 ( V_28 ) ;
F_31 ( V_28 ) ;
return V_23 ;
}
int F_33 ( struct V_27 * V_28 , unsigned char * V_3 )
{
int V_23 ;
F_29 ( V_28 ) ;
V_23 = F_10 ( & V_28 -> V_38 , V_3 , V_28 -> V_4 ,
V_35 ) ;
if ( ! V_23 )
F_30 ( V_28 ) ;
F_31 ( V_28 ) ;
return V_23 ;
}
int F_34 ( struct V_27 * V_39 , struct V_27 * V_40 )
{
int V_23 = 0 ;
if ( V_39 -> V_4 != V_40 -> V_4 )
return - V_18 ;
F_35 ( V_39 ) ;
V_23 = F_13 ( & V_39 -> V_38 , & V_40 -> V_38 , V_39 -> V_4 ) ;
if ( ! V_23 )
F_30 ( V_39 ) ;
F_36 ( V_39 ) ;
return V_23 ;
}
void F_37 ( struct V_27 * V_39 , struct V_27 * V_40 )
{
if ( V_39 -> V_4 != V_40 -> V_4 )
return;
F_29 ( V_40 ) ;
F_35 ( V_39 ) ;
F_15 ( & V_39 -> V_38 , & V_40 -> V_38 , V_39 -> V_4 ) ;
F_30 ( V_39 ) ;
F_36 ( V_39 ) ;
F_31 ( V_40 ) ;
}
void F_38 ( struct V_27 * V_28 )
{
F_29 ( V_28 ) ;
F_16 ( & V_28 -> V_38 ) ;
F_31 ( V_28 ) ;
}
void F_39 ( struct V_27 * V_28 )
{
F_17 ( & V_28 -> V_38 ) ;
}
int F_40 ( struct V_27 * V_28 , unsigned char * V_3 )
{
struct V_7 * V_8 ;
int V_23 ;
F_29 ( V_28 ) ;
F_5 (ha, &dev->mc.list, list) {
if ( ! memcmp ( V_8 -> V_3 , V_3 , V_28 -> V_4 ) &&
V_8 -> type == V_41 ) {
V_23 = - V_36 ;
goto V_37;
}
}
V_23 = F_1 ( & V_28 -> V_42 , V_3 , V_28 -> V_4 ,
V_41 , true ) ;
if ( ! V_23 )
F_30 ( V_28 ) ;
V_37:
F_31 ( V_28 ) ;
return V_23 ;
}
static int F_41 ( struct V_27 * V_28 , unsigned char * V_3 ,
bool V_6 )
{
int V_23 ;
F_29 ( V_28 ) ;
V_23 = F_4 ( & V_28 -> V_42 , V_3 , V_28 -> V_4 ,
V_41 , V_6 ) ;
if ( ! V_23 )
F_30 ( V_28 ) ;
F_31 ( V_28 ) ;
return V_23 ;
}
int F_42 ( struct V_27 * V_28 , unsigned char * V_3 )
{
return F_41 ( V_28 , V_3 , false ) ;
}
int F_43 ( struct V_27 * V_28 , unsigned char * V_3 )
{
return F_41 ( V_28 , V_3 , true ) ;
}
static int F_44 ( struct V_27 * V_28 , unsigned char * V_3 ,
bool V_6 )
{
int V_23 ;
F_29 ( V_28 ) ;
V_23 = F_7 ( & V_28 -> V_42 , V_3 , V_28 -> V_4 ,
V_41 , V_6 ) ;
if ( ! V_23 )
F_30 ( V_28 ) ;
F_31 ( V_28 ) ;
return V_23 ;
}
int F_45 ( struct V_27 * V_28 , unsigned char * V_3 )
{
return F_44 ( V_28 , V_3 , false ) ;
}
int F_46 ( struct V_27 * V_28 , unsigned char * V_3 )
{
return F_44 ( V_28 , V_3 , true ) ;
}
int F_47 ( struct V_27 * V_39 , struct V_27 * V_40 )
{
int V_23 = 0 ;
if ( V_39 -> V_4 != V_40 -> V_4 )
return - V_18 ;
F_35 ( V_39 ) ;
V_23 = F_13 ( & V_39 -> V_42 , & V_40 -> V_42 , V_39 -> V_4 ) ;
if ( ! V_23 )
F_30 ( V_39 ) ;
F_36 ( V_39 ) ;
return V_23 ;
}
void F_48 ( struct V_27 * V_39 , struct V_27 * V_40 )
{
if ( V_39 -> V_4 != V_40 -> V_4 )
return;
F_29 ( V_40 ) ;
F_35 ( V_39 ) ;
F_15 ( & V_39 -> V_42 , & V_40 -> V_42 , V_39 -> V_4 ) ;
F_30 ( V_39 ) ;
F_36 ( V_39 ) ;
F_31 ( V_40 ) ;
}
void F_49 ( struct V_27 * V_28 )
{
F_29 ( V_28 ) ;
F_16 ( & V_28 -> V_42 ) ;
F_31 ( V_28 ) ;
}
void F_50 ( struct V_27 * V_28 )
{
F_17 ( & V_28 -> V_42 ) ;
}
static int F_51 ( struct V_43 * V_44 , void * V_45 )
{
struct V_7 * V_8 ;
struct V_27 * V_28 = V_45 ;
if ( V_45 == V_46 )
return 0 ;
F_29 ( V_28 ) ;
F_52 (ha, dev) {
int V_47 ;
F_53 ( V_44 , L_1 , V_28 -> V_48 ,
V_28 -> V_49 , V_8 -> V_13 , V_8 -> V_14 ) ;
for ( V_47 = 0 ; V_47 < V_28 -> V_4 ; V_47 ++ )
F_53 ( V_44 , L_2 , V_8 -> V_3 [ V_47 ] ) ;
F_54 ( V_44 , '\n' ) ;
}
F_31 ( V_28 ) ;
return 0 ;
}
static int F_55 ( struct V_50 * V_50 , struct V_51 * V_51 )
{
return F_56 ( V_50 , V_51 , & V_52 ,
sizeof( struct V_53 ) ) ;
}
static int T_1 F_57 ( struct V_54 * V_54 )
{
if ( ! F_58 ( V_54 , L_3 , 0 , & V_55 ) )
return - V_12 ;
return 0 ;
}
static void T_2 F_59 ( struct V_54 * V_54 )
{
F_60 ( V_54 , L_3 ) ;
}
void T_3 F_61 ( void )
{
F_62 ( & V_56 ) ;
}
