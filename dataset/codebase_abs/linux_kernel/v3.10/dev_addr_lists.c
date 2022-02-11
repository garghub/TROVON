static int F_1 ( struct V_1 * V_2 ,
const unsigned char * V_3 , int V_4 ,
unsigned char V_5 , bool V_6 ,
bool V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
V_10 = sizeof( * V_9 ) ;
if ( V_10 < V_11 )
V_10 = V_11 ;
V_9 = F_2 ( V_10 , V_12 ) ;
if ( ! V_9 )
return - V_13 ;
memcpy ( V_9 -> V_3 , V_3 , V_4 ) ;
V_9 -> type = V_5 ;
V_9 -> V_14 = 1 ;
V_9 -> V_15 = V_6 ;
V_9 -> V_16 = V_7 ;
V_9 -> V_17 = 0 ;
F_3 ( & V_9 -> V_2 , & V_2 -> V_2 ) ;
V_2 -> V_18 ++ ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
const unsigned char * V_3 , int V_4 ,
unsigned char V_5 , bool V_6 , bool V_7 )
{
struct V_8 * V_9 ;
if ( V_4 > V_19 )
return - V_20 ;
F_5 (ha, &list->list, list) {
if ( ! memcmp ( V_9 -> V_3 , V_3 , V_4 ) &&
V_9 -> type == V_5 ) {
if ( V_6 ) {
if ( V_9 -> V_15 )
return 0 ;
else
V_9 -> V_15 = true ;
}
if ( V_7 ) {
if ( V_9 -> V_16 )
return - V_21 ;
else
V_9 -> V_16 = true ;
}
V_9 -> V_14 ++ ;
return 0 ;
}
}
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
const unsigned char * V_3 , int V_4 ,
unsigned char V_5 )
{
return F_4 ( V_2 , V_3 , V_4 , V_5 , false , false ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_8 * V_9 , bool V_6 ,
bool V_7 )
{
if ( V_6 && ! V_9 -> V_15 )
return - V_22 ;
if ( V_7 && ! V_9 -> V_16 )
return - V_22 ;
if ( V_6 )
V_9 -> V_15 = false ;
if ( V_7 )
V_9 -> V_16 = false ;
if ( -- V_9 -> V_14 )
return 0 ;
F_8 ( & V_9 -> V_2 ) ;
F_9 ( V_9 , V_23 ) ;
V_2 -> V_18 -- ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
const unsigned char * V_3 , int V_4 ,
unsigned char V_5 , bool V_6 , bool V_7 )
{
struct V_8 * V_9 ;
F_5 (ha, &list->list, list) {
if ( ! memcmp ( V_9 -> V_3 , V_3 , V_4 ) &&
( V_9 -> type == V_5 || ! V_5 ) )
return F_7 ( V_2 , V_9 , V_6 , V_7 ) ;
}
return - V_22 ;
}
static int F_11 ( struct V_1 * V_2 ,
const unsigned char * V_3 , int V_4 ,
unsigned char V_5 )
{
return F_10 ( V_2 , V_3 , V_4 , V_5 , false , false ) ;
}
static int F_12 ( struct V_1 * V_24 ,
struct V_8 * V_9 ,
int V_4 )
{
int V_25 ;
V_25 = F_4 ( V_24 , V_9 -> V_3 , V_4 , V_9 -> type ,
false , true ) ;
if ( V_25 && V_25 != - V_21 )
return V_25 ;
if ( ! V_25 ) {
V_9 -> V_17 ++ ;
V_9 -> V_14 ++ ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_24 ,
struct V_1 * V_26 ,
struct V_8 * V_9 ,
int V_4 )
{
int V_25 ;
V_25 = F_10 ( V_24 , V_9 -> V_3 , V_4 , V_9 -> type ,
false , true ) ;
if ( V_25 )
return;
V_9 -> V_17 -- ;
F_7 ( V_26 , V_9 , false , false ) ;
}
static int F_14 ( struct V_1 * V_24 ,
struct V_1 * V_26 ,
int V_4 )
{
int V_25 = 0 ;
struct V_8 * V_9 , * V_27 ;
F_15 (ha, tmp, &from_list->list, list) {
if ( V_9 -> V_17 == V_9 -> V_14 ) {
F_13 ( V_24 , V_26 , V_9 , V_4 ) ;
} else {
V_25 = F_12 ( V_24 , V_9 , V_4 ) ;
if ( V_25 )
break;
}
}
return V_25 ;
}
int F_16 ( struct V_1 * V_24 ,
struct V_1 * V_26 ,
int V_4 , unsigned char V_5 )
{
int V_25 ;
struct V_8 * V_9 , * V_28 ;
unsigned char type ;
F_5 (ha, &from_list->list, list) {
type = V_5 ? V_5 : V_9 -> type ;
V_25 = F_6 ( V_24 , V_9 -> V_3 , V_4 , type ) ;
if ( V_25 )
goto V_29;
}
return 0 ;
V_29:
F_5 (ha2, &from_list->list, list) {
if ( V_28 == V_9 )
break;
type = V_5 ? V_5 : V_28 -> type ;
F_11 ( V_24 , V_28 -> V_3 , V_4 , type ) ;
}
return V_25 ;
}
void F_17 ( struct V_1 * V_24 ,
struct V_1 * V_26 ,
int V_4 , unsigned char V_5 )
{
struct V_8 * V_9 ;
unsigned char type ;
F_5 (ha, &from_list->list, list) {
type = V_5 ? V_5 : V_9 -> type ;
F_11 ( V_24 , V_9 -> V_3 , V_4 , type ) ;
}
}
int F_18 ( struct V_1 * V_24 ,
struct V_1 * V_26 ,
int V_4 )
{
int V_25 = 0 ;
struct V_8 * V_9 , * V_27 ;
F_15 (ha, tmp, &from_list->list, list) {
if ( ! V_9 -> V_17 ) {
V_25 = F_12 ( V_24 , V_9 , V_4 ) ;
if ( V_25 )
break;
} else if ( V_9 -> V_14 == 1 )
F_13 ( V_24 , V_26 , V_9 , V_4 ) ;
}
return V_25 ;
}
void F_19 ( struct V_1 * V_24 ,
struct V_1 * V_26 ,
int V_4 )
{
struct V_8 * V_9 , * V_27 ;
F_15 (ha, tmp, &from_list->list, list) {
if ( V_9 -> V_17 )
F_13 ( V_24 , V_26 , V_9 , V_4 ) ;
}
}
void F_20 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_27 ;
F_15 (ha, tmp, &list->list, list) {
F_8 ( & V_9 -> V_2 ) ;
F_9 ( V_9 , V_23 ) ;
}
V_2 -> V_18 = 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_2 ) ;
V_2 -> V_18 = 0 ;
}
void F_23 ( struct V_30 * V_31 )
{
F_20 ( & V_31 -> V_32 ) ;
V_31 -> V_33 = NULL ;
}
int F_24 ( struct V_30 * V_31 )
{
unsigned char V_3 [ V_19 ] ;
struct V_8 * V_9 ;
int V_25 ;
F_21 ( & V_31 -> V_32 ) ;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
V_25 = F_6 ( & V_31 -> V_32 , V_3 , sizeof( V_3 ) ,
V_34 ) ;
if ( ! V_25 ) {
V_9 = F_25 ( & V_31 -> V_32 . V_2 ,
struct V_8 , V_2 ) ;
V_31 -> V_33 = V_9 -> V_3 ;
}
return V_25 ;
}
int F_26 ( struct V_30 * V_31 , const unsigned char * V_3 ,
unsigned char V_5 )
{
int V_25 ;
F_27 () ;
V_25 = F_6 ( & V_31 -> V_32 , V_3 , V_31 -> V_4 , V_5 ) ;
if ( ! V_25 )
F_28 ( V_35 , V_31 ) ;
return V_25 ;
}
int F_29 ( struct V_30 * V_31 , const unsigned char * V_3 ,
unsigned char V_5 )
{
int V_25 ;
struct V_8 * V_9 ;
F_27 () ;
V_9 = F_25 ( & V_31 -> V_32 . V_2 ,
struct V_8 , V_2 ) ;
if ( ! memcmp ( V_9 -> V_3 , V_3 , V_31 -> V_4 ) &&
V_9 -> type == V_5 && V_9 -> V_14 == 1 )
return - V_22 ;
V_25 = F_11 ( & V_31 -> V_32 , V_3 , V_31 -> V_4 ,
V_5 ) ;
if ( ! V_25 )
F_28 ( V_35 , V_31 ) ;
return V_25 ;
}
int F_30 ( struct V_30 * V_36 ,
struct V_30 * V_37 ,
unsigned char V_5 )
{
int V_25 ;
F_27 () ;
if ( V_37 -> V_4 != V_36 -> V_4 )
return - V_20 ;
V_25 = F_16 ( & V_36 -> V_32 , & V_37 -> V_32 ,
V_36 -> V_4 , V_5 ) ;
if ( ! V_25 )
F_28 ( V_35 , V_36 ) ;
return V_25 ;
}
int F_31 ( struct V_30 * V_36 ,
struct V_30 * V_37 ,
unsigned char V_5 )
{
F_27 () ;
if ( V_37 -> V_4 != V_36 -> V_4 )
return - V_20 ;
F_17 ( & V_36 -> V_32 , & V_37 -> V_32 ,
V_36 -> V_4 , V_5 ) ;
F_28 ( V_35 , V_36 ) ;
return 0 ;
}
int F_32 ( struct V_30 * V_31 , const unsigned char * V_3 )
{
struct V_8 * V_9 ;
int V_25 ;
F_33 ( V_31 ) ;
F_5 (ha, &dev->uc.list, list) {
if ( ! memcmp ( V_9 -> V_3 , V_3 , V_31 -> V_4 ) &&
V_9 -> type == V_38 ) {
V_25 = - V_21 ;
goto V_39;
}
}
V_25 = F_1 ( & V_31 -> V_40 , V_3 , V_31 -> V_4 ,
V_38 , true , false ) ;
if ( ! V_25 )
F_34 ( V_31 ) ;
V_39:
F_35 ( V_31 ) ;
return V_25 ;
}
int F_36 ( struct V_30 * V_31 , const unsigned char * V_3 )
{
int V_25 ;
F_33 ( V_31 ) ;
V_25 = F_6 ( & V_31 -> V_40 , V_3 , V_31 -> V_4 ,
V_38 ) ;
if ( ! V_25 )
F_34 ( V_31 ) ;
F_35 ( V_31 ) ;
return V_25 ;
}
int F_37 ( struct V_30 * V_31 , const unsigned char * V_3 )
{
int V_25 ;
F_33 ( V_31 ) ;
V_25 = F_11 ( & V_31 -> V_40 , V_3 , V_31 -> V_4 ,
V_38 ) ;
if ( ! V_25 )
F_34 ( V_31 ) ;
F_35 ( V_31 ) ;
return V_25 ;
}
int F_38 ( struct V_30 * V_41 , struct V_30 * V_42 )
{
int V_25 = 0 ;
if ( V_41 -> V_4 != V_42 -> V_4 )
return - V_20 ;
F_39 ( V_41 ) ;
V_25 = F_18 ( & V_41 -> V_40 , & V_42 -> V_40 , V_41 -> V_4 ) ;
if ( ! V_25 )
F_34 ( V_41 ) ;
F_40 ( V_41 ) ;
return V_25 ;
}
int F_41 ( struct V_30 * V_41 , struct V_30 * V_42 )
{
int V_25 = 0 ;
if ( V_41 -> V_4 != V_42 -> V_4 )
return - V_20 ;
F_39 ( V_41 ) ;
V_25 = F_14 ( & V_41 -> V_40 , & V_42 -> V_40 , V_41 -> V_4 ) ;
if ( ! V_25 )
F_34 ( V_41 ) ;
F_40 ( V_41 ) ;
return V_25 ;
}
void F_42 ( struct V_30 * V_41 , struct V_30 * V_42 )
{
if ( V_41 -> V_4 != V_42 -> V_4 )
return;
F_33 ( V_42 ) ;
F_39 ( V_41 ) ;
F_19 ( & V_41 -> V_40 , & V_42 -> V_40 , V_41 -> V_4 ) ;
F_34 ( V_41 ) ;
F_40 ( V_41 ) ;
F_35 ( V_42 ) ;
}
void F_43 ( struct V_30 * V_31 )
{
F_33 ( V_31 ) ;
F_20 ( & V_31 -> V_40 ) ;
F_35 ( V_31 ) ;
}
void F_44 ( struct V_30 * V_31 )
{
F_21 ( & V_31 -> V_40 ) ;
}
int F_45 ( struct V_30 * V_31 , const unsigned char * V_3 )
{
struct V_8 * V_9 ;
int V_25 ;
F_33 ( V_31 ) ;
F_5 (ha, &dev->mc.list, list) {
if ( ! memcmp ( V_9 -> V_3 , V_3 , V_31 -> V_4 ) &&
V_9 -> type == V_43 ) {
V_25 = - V_21 ;
goto V_39;
}
}
V_25 = F_1 ( & V_31 -> V_44 , V_3 , V_31 -> V_4 ,
V_43 , true , false ) ;
if ( ! V_25 )
F_34 ( V_31 ) ;
V_39:
F_35 ( V_31 ) ;
return V_25 ;
}
static int F_46 ( struct V_30 * V_31 , const unsigned char * V_3 ,
bool V_6 )
{
int V_25 ;
F_33 ( V_31 ) ;
V_25 = F_4 ( & V_31 -> V_44 , V_3 , V_31 -> V_4 ,
V_43 , V_6 , false ) ;
if ( ! V_25 )
F_34 ( V_31 ) ;
F_35 ( V_31 ) ;
return V_25 ;
}
int F_47 ( struct V_30 * V_31 , const unsigned char * V_3 )
{
return F_46 ( V_31 , V_3 , false ) ;
}
int F_48 ( struct V_30 * V_31 , const unsigned char * V_3 )
{
return F_46 ( V_31 , V_3 , true ) ;
}
static int F_49 ( struct V_30 * V_31 , const unsigned char * V_3 ,
bool V_6 )
{
int V_25 ;
F_33 ( V_31 ) ;
V_25 = F_10 ( & V_31 -> V_44 , V_3 , V_31 -> V_4 ,
V_43 , V_6 , false ) ;
if ( ! V_25 )
F_34 ( V_31 ) ;
F_35 ( V_31 ) ;
return V_25 ;
}
int F_50 ( struct V_30 * V_31 , const unsigned char * V_3 )
{
return F_49 ( V_31 , V_3 , false ) ;
}
int F_51 ( struct V_30 * V_31 , const unsigned char * V_3 )
{
return F_49 ( V_31 , V_3 , true ) ;
}
int F_52 ( struct V_30 * V_41 , struct V_30 * V_42 )
{
int V_25 = 0 ;
if ( V_41 -> V_4 != V_42 -> V_4 )
return - V_20 ;
F_39 ( V_41 ) ;
V_25 = F_18 ( & V_41 -> V_44 , & V_42 -> V_44 , V_41 -> V_4 ) ;
if ( ! V_25 )
F_34 ( V_41 ) ;
F_40 ( V_41 ) ;
return V_25 ;
}
int F_53 ( struct V_30 * V_41 , struct V_30 * V_42 )
{
int V_25 = 0 ;
if ( V_41 -> V_4 != V_42 -> V_4 )
return - V_20 ;
F_39 ( V_41 ) ;
V_25 = F_14 ( & V_41 -> V_44 , & V_42 -> V_44 , V_41 -> V_4 ) ;
if ( ! V_25 )
F_34 ( V_41 ) ;
F_40 ( V_41 ) ;
return V_25 ;
}
void F_54 ( struct V_30 * V_41 , struct V_30 * V_42 )
{
if ( V_41 -> V_4 != V_42 -> V_4 )
return;
F_33 ( V_42 ) ;
F_39 ( V_41 ) ;
F_19 ( & V_41 -> V_44 , & V_42 -> V_44 , V_41 -> V_4 ) ;
F_34 ( V_41 ) ;
F_40 ( V_41 ) ;
F_35 ( V_42 ) ;
}
void F_55 ( struct V_30 * V_31 )
{
F_33 ( V_31 ) ;
F_20 ( & V_31 -> V_44 ) ;
F_35 ( V_31 ) ;
}
void F_56 ( struct V_30 * V_31 )
{
F_21 ( & V_31 -> V_44 ) ;
}
