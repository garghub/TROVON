static int F_1 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 ,
unsigned char V_5 , bool V_6 )
{
struct V_7 * V_8 ;
int V_9 ;
if ( V_4 > V_10 )
return - V_11 ;
F_2 (ha, &list->list, list) {
if ( ! memcmp ( V_8 -> V_3 , V_3 , V_4 ) &&
V_8 -> type == V_5 ) {
if ( V_6 ) {
if ( V_8 -> V_12 )
return 0 ;
else
V_8 -> V_12 = true ;
}
V_8 -> V_13 ++ ;
return 0 ;
}
}
V_9 = sizeof( * V_8 ) ;
if ( V_9 < V_14 )
V_9 = V_14 ;
V_8 = F_3 ( V_9 , V_15 ) ;
if ( ! V_8 )
return - V_16 ;
memcpy ( V_8 -> V_3 , V_3 , V_4 ) ;
V_8 -> type = V_5 ;
V_8 -> V_13 = 1 ;
V_8 -> V_12 = V_6 ;
V_8 -> V_17 = false ;
F_4 ( & V_8 -> V_2 , & V_2 -> V_2 ) ;
V_2 -> V_18 ++ ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned char * V_3 ,
int V_4 , unsigned char V_5 )
{
return F_1 ( V_2 , V_3 , V_4 , V_5 , false ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned char * V_3 , int V_4 ,
unsigned char V_5 , bool V_6 )
{
struct V_7 * V_8 ;
F_2 (ha, &list->list, list) {
if ( ! memcmp ( V_8 -> V_3 , V_3 , V_4 ) &&
( V_8 -> type == V_5 || ! V_5 ) ) {
if ( V_6 ) {
if ( ! V_8 -> V_12 )
break;
else
V_8 -> V_12 = false ;
}
if ( -- V_8 -> V_13 )
return 0 ;
F_7 ( & V_8 -> V_2 ) ;
F_8 ( V_8 , V_19 ) ;
V_2 -> V_18 -- ;
return 0 ;
}
}
return - V_20 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned char * V_3 ,
int V_4 , unsigned char V_5 )
{
return F_6 ( V_2 , V_3 , V_4 , V_5 , false ) ;
}
int F_10 ( struct V_1 * V_21 ,
struct V_1 * V_22 ,
int V_4 , unsigned char V_5 )
{
int V_23 ;
struct V_7 * V_8 , * V_24 ;
unsigned char type ;
F_2 (ha, &from_list->list, list) {
type = V_5 ? V_5 : V_8 -> type ;
V_23 = F_5 ( V_21 , V_8 -> V_3 , V_4 , type ) ;
if ( V_23 )
goto V_25;
}
return 0 ;
V_25:
F_2 (ha2, &from_list->list, list) {
if ( V_24 == V_8 )
break;
type = V_5 ? V_5 : V_24 -> type ;
F_9 ( V_21 , V_24 -> V_3 , V_4 , type ) ;
}
return V_23 ;
}
void F_11 ( struct V_1 * V_21 ,
struct V_1 * V_22 ,
int V_4 , unsigned char V_5 )
{
struct V_7 * V_8 ;
unsigned char type ;
F_2 (ha, &from_list->list, list) {
type = V_5 ? V_5 : V_8 -> type ;
F_9 ( V_21 , V_8 -> V_3 , V_4 , type ) ;
}
}
int F_12 ( struct V_1 * V_21 ,
struct V_1 * V_22 ,
int V_4 )
{
int V_23 = 0 ;
struct V_7 * V_8 , * V_26 ;
F_13 (ha, tmp, &from_list->list, list) {
if ( ! V_8 -> V_17 ) {
V_23 = F_5 ( V_21 , V_8 -> V_3 ,
V_4 , V_8 -> type ) ;
if ( V_23 )
break;
V_8 -> V_17 = true ;
V_8 -> V_13 ++ ;
} else if ( V_8 -> V_13 == 1 ) {
F_9 ( V_21 , V_8 -> V_3 , V_4 , V_8 -> type ) ;
F_9 ( V_22 , V_8 -> V_3 , V_4 , V_8 -> type ) ;
}
}
return V_23 ;
}
void F_14 ( struct V_1 * V_21 ,
struct V_1 * V_22 ,
int V_4 )
{
struct V_7 * V_8 , * V_26 ;
F_13 (ha, tmp, &from_list->list, list) {
if ( V_8 -> V_17 ) {
F_9 ( V_21 , V_8 -> V_3 ,
V_4 , V_8 -> type ) ;
V_8 -> V_17 = false ;
F_9 ( V_22 , V_8 -> V_3 ,
V_4 , V_8 -> type ) ;
}
}
}
void F_15 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_26 ;
F_13 (ha, tmp, &list->list, list) {
F_7 ( & V_8 -> V_2 ) ;
F_8 ( V_8 , V_19 ) ;
}
V_2 -> V_18 = 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_2 ) ;
V_2 -> V_18 = 0 ;
}
void F_18 ( struct V_27 * V_28 )
{
F_15 ( & V_28 -> V_29 ) ;
V_28 -> V_30 = NULL ;
}
int F_19 ( struct V_27 * V_28 )
{
unsigned char V_3 [ V_10 ] ;
struct V_7 * V_8 ;
int V_23 ;
F_16 ( & V_28 -> V_29 ) ;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
V_23 = F_5 ( & V_28 -> V_29 , V_3 , sizeof( V_3 ) ,
V_31 ) ;
if ( ! V_23 ) {
V_8 = F_20 ( & V_28 -> V_29 . V_2 ,
struct V_7 , V_2 ) ;
V_28 -> V_30 = V_8 -> V_3 ;
}
return V_23 ;
}
int F_21 ( struct V_27 * V_28 , unsigned char * V_3 ,
unsigned char V_5 )
{
int V_23 ;
F_22 () ;
V_23 = F_5 ( & V_28 -> V_29 , V_3 , V_28 -> V_4 , V_5 ) ;
if ( ! V_23 )
F_23 ( V_32 , V_28 ) ;
return V_23 ;
}
int F_24 ( struct V_27 * V_28 , unsigned char * V_3 ,
unsigned char V_5 )
{
int V_23 ;
struct V_7 * V_8 ;
F_22 () ;
V_8 = F_20 ( & V_28 -> V_29 . V_2 ,
struct V_7 , V_2 ) ;
if ( V_8 -> V_3 == V_28 -> V_30 && V_8 -> V_13 == 1 )
return - V_20 ;
V_23 = F_9 ( & V_28 -> V_29 , V_3 , V_28 -> V_4 ,
V_5 ) ;
if ( ! V_23 )
F_23 ( V_32 , V_28 ) ;
return V_23 ;
}
int F_25 ( struct V_27 * V_33 ,
struct V_27 * V_34 ,
unsigned char V_5 )
{
int V_23 ;
F_22 () ;
if ( V_34 -> V_4 != V_33 -> V_4 )
return - V_11 ;
V_23 = F_10 ( & V_33 -> V_29 , & V_34 -> V_29 ,
V_33 -> V_4 , V_5 ) ;
if ( ! V_23 )
F_23 ( V_32 , V_33 ) ;
return V_23 ;
}
int F_26 ( struct V_27 * V_33 ,
struct V_27 * V_34 ,
unsigned char V_5 )
{
F_22 () ;
if ( V_34 -> V_4 != V_33 -> V_4 )
return - V_11 ;
F_11 ( & V_33 -> V_29 , & V_34 -> V_29 ,
V_33 -> V_4 , V_5 ) ;
F_23 ( V_32 , V_33 ) ;
return 0 ;
}
int F_27 ( struct V_27 * V_28 , unsigned char * V_3 )
{
int V_23 ;
F_28 ( V_28 ) ;
V_23 = F_5 ( & V_28 -> V_35 , V_3 , V_28 -> V_4 ,
V_36 ) ;
if ( ! V_23 )
F_29 ( V_28 ) ;
F_30 ( V_28 ) ;
return V_23 ;
}
int F_31 ( struct V_27 * V_28 , unsigned char * V_3 )
{
int V_23 ;
F_28 ( V_28 ) ;
V_23 = F_9 ( & V_28 -> V_35 , V_3 , V_28 -> V_4 ,
V_36 ) ;
if ( ! V_23 )
F_29 ( V_28 ) ;
F_30 ( V_28 ) ;
return V_23 ;
}
int F_32 ( struct V_27 * V_37 , struct V_27 * V_38 )
{
int V_23 = 0 ;
if ( V_37 -> V_4 != V_38 -> V_4 )
return - V_11 ;
F_28 ( V_37 ) ;
V_23 = F_12 ( & V_37 -> V_35 , & V_38 -> V_35 , V_37 -> V_4 ) ;
if ( ! V_23 )
F_29 ( V_37 ) ;
F_30 ( V_37 ) ;
return V_23 ;
}
void F_33 ( struct V_27 * V_37 , struct V_27 * V_38 )
{
if ( V_37 -> V_4 != V_38 -> V_4 )
return;
F_28 ( V_38 ) ;
F_34 ( V_37 ) ;
F_14 ( & V_37 -> V_35 , & V_38 -> V_35 , V_37 -> V_4 ) ;
F_29 ( V_37 ) ;
F_35 ( V_37 ) ;
F_30 ( V_38 ) ;
}
void F_36 ( struct V_27 * V_28 )
{
F_28 ( V_28 ) ;
F_15 ( & V_28 -> V_35 ) ;
F_30 ( V_28 ) ;
}
void F_37 ( struct V_27 * V_28 )
{
F_16 ( & V_28 -> V_35 ) ;
}
static int F_38 ( struct V_27 * V_28 , unsigned char * V_3 ,
bool V_6 )
{
int V_23 ;
F_28 ( V_28 ) ;
V_23 = F_1 ( & V_28 -> V_39 , V_3 , V_28 -> V_4 ,
V_40 , V_6 ) ;
if ( ! V_23 )
F_29 ( V_28 ) ;
F_30 ( V_28 ) ;
return V_23 ;
}
int F_39 ( struct V_27 * V_28 , unsigned char * V_3 )
{
return F_38 ( V_28 , V_3 , false ) ;
}
int F_40 ( struct V_27 * V_28 , unsigned char * V_3 )
{
return F_38 ( V_28 , V_3 , true ) ;
}
static int F_41 ( struct V_27 * V_28 , unsigned char * V_3 ,
bool V_6 )
{
int V_23 ;
F_28 ( V_28 ) ;
V_23 = F_6 ( & V_28 -> V_39 , V_3 , V_28 -> V_4 ,
V_40 , V_6 ) ;
if ( ! V_23 )
F_29 ( V_28 ) ;
F_30 ( V_28 ) ;
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
int F_44 ( struct V_27 * V_37 , struct V_27 * V_38 )
{
int V_23 = 0 ;
if ( V_37 -> V_4 != V_38 -> V_4 )
return - V_11 ;
F_28 ( V_37 ) ;
V_23 = F_12 ( & V_37 -> V_39 , & V_38 -> V_39 , V_37 -> V_4 ) ;
if ( ! V_23 )
F_29 ( V_37 ) ;
F_30 ( V_37 ) ;
return V_23 ;
}
void F_45 ( struct V_27 * V_37 , struct V_27 * V_38 )
{
if ( V_37 -> V_4 != V_38 -> V_4 )
return;
F_28 ( V_38 ) ;
F_34 ( V_37 ) ;
F_14 ( & V_37 -> V_39 , & V_38 -> V_39 , V_37 -> V_4 ) ;
F_29 ( V_37 ) ;
F_35 ( V_37 ) ;
F_30 ( V_38 ) ;
}
void F_46 ( struct V_27 * V_28 )
{
F_28 ( V_28 ) ;
F_15 ( & V_28 -> V_39 ) ;
F_30 ( V_28 ) ;
}
void F_47 ( struct V_27 * V_28 )
{
F_16 ( & V_28 -> V_39 ) ;
}
static int F_48 ( struct V_41 * V_42 , void * V_43 )
{
struct V_7 * V_8 ;
struct V_27 * V_28 = V_43 ;
if ( V_43 == V_44 )
return 0 ;
F_28 ( V_28 ) ;
F_49 (ha, dev) {
int V_45 ;
F_50 ( V_42 , L_1 , V_28 -> V_46 ,
V_28 -> V_47 , V_8 -> V_13 , V_8 -> V_12 ) ;
for ( V_45 = 0 ; V_45 < V_28 -> V_4 ; V_45 ++ )
F_50 ( V_42 , L_2 , V_8 -> V_3 [ V_45 ] ) ;
F_51 ( V_42 , '\n' ) ;
}
F_30 ( V_28 ) ;
return 0 ;
}
static int F_52 ( struct V_48 * V_48 , struct V_49 * V_49 )
{
return F_53 ( V_48 , V_49 , & V_50 ,
sizeof( struct V_51 ) ) ;
}
static int T_1 F_54 ( struct V_52 * V_52 )
{
if ( ! F_55 ( V_52 , L_3 , 0 , & V_53 ) )
return - V_16 ;
return 0 ;
}
static void T_2 F_56 ( struct V_52 * V_52 )
{
F_57 ( V_52 , L_3 ) ;
}
void T_3 F_58 ( void )
{
F_59 ( & V_54 ) ;
}
