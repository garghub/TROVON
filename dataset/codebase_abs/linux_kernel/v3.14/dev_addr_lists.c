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
V_9 -> V_16 = V_7 ? 1 : 0 ;
V_9 -> V_17 = 0 ;
F_3 ( & V_9 -> V_2 , & V_2 -> V_2 ) ;
V_2 -> V_18 ++ ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
const unsigned char * V_3 , int V_4 ,
unsigned char V_5 , bool V_6 , bool V_7 ,
int V_19 )
{
struct V_8 * V_9 ;
if ( V_4 > V_20 )
return - V_21 ;
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
if ( V_9 -> V_16 && V_19 )
return - V_22 ;
else
V_9 -> V_16 ++ ;
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
return F_4 ( V_2 , V_3 , V_4 , V_5 , false , false ,
0 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_8 * V_9 , bool V_6 ,
bool V_7 )
{
if ( V_6 && ! V_9 -> V_15 )
return - V_23 ;
if ( V_7 && ! V_9 -> V_16 )
return - V_23 ;
if ( V_6 )
V_9 -> V_15 = false ;
if ( V_7 )
V_9 -> V_16 -- ;
if ( -- V_9 -> V_14 )
return 0 ;
F_8 ( & V_9 -> V_2 ) ;
F_9 ( V_9 , V_24 ) ;
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
return - V_23 ;
}
static int F_11 ( struct V_1 * V_2 ,
const unsigned char * V_3 , int V_4 ,
unsigned char V_5 )
{
return F_10 ( V_2 , V_3 , V_4 , V_5 , false , false ) ;
}
static int F_12 ( struct V_1 * V_25 ,
struct V_8 * V_9 ,
int V_4 )
{
int V_26 ;
V_26 = F_4 ( V_25 , V_9 -> V_3 , V_4 , V_9 -> type ,
false , true , V_9 -> V_17 ) ;
if ( V_26 && V_26 != - V_22 )
return V_26 ;
if ( ! V_26 ) {
V_9 -> V_17 ++ ;
V_9 -> V_14 ++ ;
}
return 0 ;
}
static void F_13 ( struct V_1 * V_25 ,
struct V_1 * V_27 ,
struct V_8 * V_9 ,
int V_4 )
{
int V_26 ;
V_26 = F_10 ( V_25 , V_9 -> V_3 , V_4 , V_9 -> type ,
false , true ) ;
if ( V_26 )
return;
V_9 -> V_17 -- ;
F_7 ( V_27 , V_9 , false , false ) ;
}
static int F_14 ( struct V_1 * V_25 ,
struct V_1 * V_27 ,
int V_4 )
{
int V_26 = 0 ;
struct V_8 * V_9 , * V_28 ;
F_15 (ha, tmp, &from_list->list, list) {
if ( V_9 -> V_17 == V_9 -> V_14 ) {
F_13 ( V_25 , V_27 , V_9 , V_4 ) ;
} else {
V_26 = F_12 ( V_25 , V_9 , V_4 ) ;
if ( V_26 )
break;
}
}
return V_26 ;
}
int F_16 ( struct V_1 * V_25 ,
struct V_1 * V_27 ,
int V_4 )
{
int V_26 = 0 ;
struct V_8 * V_9 , * V_28 ;
F_15 (ha, tmp, &from_list->list, list) {
if ( ! V_9 -> V_17 ) {
V_26 = F_12 ( V_25 , V_9 , V_4 ) ;
if ( V_26 )
break;
} else if ( V_9 -> V_14 == 1 )
F_13 ( V_25 , V_27 , V_9 , V_4 ) ;
}
return V_26 ;
}
void F_17 ( struct V_1 * V_25 ,
struct V_1 * V_27 ,
int V_4 )
{
struct V_8 * V_9 , * V_28 ;
F_15 (ha, tmp, &from_list->list, list) {
if ( V_9 -> V_17 )
F_13 ( V_25 , V_27 , V_9 , V_4 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_8 * V_9 , * V_28 ;
F_15 (ha, tmp, &list->list, list) {
F_8 ( & V_9 -> V_2 ) ;
F_9 ( V_9 , V_24 ) ;
}
V_2 -> V_18 = 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_2 ) ;
V_2 -> V_18 = 0 ;
}
void F_21 ( struct V_29 * V_30 )
{
F_18 ( & V_30 -> V_31 ) ;
V_30 -> V_32 = NULL ;
}
int F_22 ( struct V_29 * V_30 )
{
unsigned char V_3 [ V_20 ] ;
struct V_8 * V_9 ;
int V_26 ;
F_19 ( & V_30 -> V_31 ) ;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
V_26 = F_6 ( & V_30 -> V_31 , V_3 , sizeof( V_3 ) ,
V_33 ) ;
if ( ! V_26 ) {
V_9 = F_23 ( & V_30 -> V_31 . V_2 ,
struct V_8 , V_2 ) ;
V_30 -> V_32 = V_9 -> V_3 ;
}
return V_26 ;
}
int F_24 ( struct V_29 * V_30 , const unsigned char * V_3 ,
unsigned char V_5 )
{
int V_26 ;
F_25 () ;
V_26 = F_6 ( & V_30 -> V_31 , V_3 , V_30 -> V_4 , V_5 ) ;
if ( ! V_26 )
F_26 ( V_34 , V_30 ) ;
return V_26 ;
}
int F_27 ( struct V_29 * V_30 , const unsigned char * V_3 ,
unsigned char V_5 )
{
int V_26 ;
struct V_8 * V_9 ;
F_25 () ;
V_9 = F_23 ( & V_30 -> V_31 . V_2 ,
struct V_8 , V_2 ) ;
if ( ! memcmp ( V_9 -> V_3 , V_3 , V_30 -> V_4 ) &&
V_9 -> type == V_5 && V_9 -> V_14 == 1 )
return - V_23 ;
V_26 = F_11 ( & V_30 -> V_31 , V_3 , V_30 -> V_4 ,
V_5 ) ;
if ( ! V_26 )
F_26 ( V_34 , V_30 ) ;
return V_26 ;
}
int F_28 ( struct V_29 * V_30 , const unsigned char * V_3 )
{
struct V_8 * V_9 ;
int V_26 ;
F_29 ( V_30 ) ;
F_5 (ha, &dev->uc.list, list) {
if ( ! memcmp ( V_9 -> V_3 , V_3 , V_30 -> V_4 ) &&
V_9 -> type == V_35 ) {
V_26 = - V_22 ;
goto V_36;
}
}
V_26 = F_1 ( & V_30 -> V_37 , V_3 , V_30 -> V_4 ,
V_35 , true , false ) ;
if ( ! V_26 )
F_30 ( V_30 ) ;
V_36:
F_31 ( V_30 ) ;
return V_26 ;
}
int F_32 ( struct V_29 * V_30 , const unsigned char * V_3 )
{
int V_26 ;
F_29 ( V_30 ) ;
V_26 = F_6 ( & V_30 -> V_37 , V_3 , V_30 -> V_4 ,
V_35 ) ;
if ( ! V_26 )
F_30 ( V_30 ) ;
F_31 ( V_30 ) ;
return V_26 ;
}
int F_33 ( struct V_29 * V_30 , const unsigned char * V_3 )
{
int V_26 ;
F_29 ( V_30 ) ;
V_26 = F_11 ( & V_30 -> V_37 , V_3 , V_30 -> V_4 ,
V_35 ) ;
if ( ! V_26 )
F_30 ( V_30 ) ;
F_31 ( V_30 ) ;
return V_26 ;
}
int F_34 ( struct V_29 * V_38 , struct V_29 * V_39 )
{
int V_26 = 0 ;
if ( V_38 -> V_4 != V_39 -> V_4 )
return - V_21 ;
F_35 ( V_38 ) ;
V_26 = F_16 ( & V_38 -> V_37 , & V_39 -> V_37 , V_38 -> V_4 ) ;
if ( ! V_26 )
F_30 ( V_38 ) ;
F_36 ( V_38 ) ;
return V_26 ;
}
int F_37 ( struct V_29 * V_38 , struct V_29 * V_39 )
{
int V_26 = 0 ;
if ( V_38 -> V_4 != V_39 -> V_4 )
return - V_21 ;
F_35 ( V_38 ) ;
V_26 = F_14 ( & V_38 -> V_37 , & V_39 -> V_37 , V_38 -> V_4 ) ;
if ( ! V_26 )
F_30 ( V_38 ) ;
F_36 ( V_38 ) ;
return V_26 ;
}
void F_38 ( struct V_29 * V_38 , struct V_29 * V_39 )
{
if ( V_38 -> V_4 != V_39 -> V_4 )
return;
F_29 ( V_39 ) ;
F_35 ( V_38 ) ;
F_17 ( & V_38 -> V_37 , & V_39 -> V_37 , V_38 -> V_4 ) ;
F_30 ( V_38 ) ;
F_36 ( V_38 ) ;
F_31 ( V_39 ) ;
}
void F_39 ( struct V_29 * V_30 )
{
F_29 ( V_30 ) ;
F_18 ( & V_30 -> V_37 ) ;
F_31 ( V_30 ) ;
}
void F_40 ( struct V_29 * V_30 )
{
F_19 ( & V_30 -> V_37 ) ;
}
int F_41 ( struct V_29 * V_30 , const unsigned char * V_3 )
{
struct V_8 * V_9 ;
int V_26 ;
F_29 ( V_30 ) ;
F_5 (ha, &dev->mc.list, list) {
if ( ! memcmp ( V_9 -> V_3 , V_3 , V_30 -> V_4 ) &&
V_9 -> type == V_40 ) {
V_26 = - V_22 ;
goto V_36;
}
}
V_26 = F_1 ( & V_30 -> V_41 , V_3 , V_30 -> V_4 ,
V_40 , true , false ) ;
if ( ! V_26 )
F_30 ( V_30 ) ;
V_36:
F_31 ( V_30 ) ;
return V_26 ;
}
static int F_42 ( struct V_29 * V_30 , const unsigned char * V_3 ,
bool V_6 )
{
int V_26 ;
F_29 ( V_30 ) ;
V_26 = F_4 ( & V_30 -> V_41 , V_3 , V_30 -> V_4 ,
V_40 , V_6 , false , 0 ) ;
if ( ! V_26 )
F_30 ( V_30 ) ;
F_31 ( V_30 ) ;
return V_26 ;
}
int F_43 ( struct V_29 * V_30 , const unsigned char * V_3 )
{
return F_42 ( V_30 , V_3 , false ) ;
}
int F_44 ( struct V_29 * V_30 , const unsigned char * V_3 )
{
return F_42 ( V_30 , V_3 , true ) ;
}
static int F_45 ( struct V_29 * V_30 , const unsigned char * V_3 ,
bool V_6 )
{
int V_26 ;
F_29 ( V_30 ) ;
V_26 = F_10 ( & V_30 -> V_41 , V_3 , V_30 -> V_4 ,
V_40 , V_6 , false ) ;
if ( ! V_26 )
F_30 ( V_30 ) ;
F_31 ( V_30 ) ;
return V_26 ;
}
int F_46 ( struct V_29 * V_30 , const unsigned char * V_3 )
{
return F_45 ( V_30 , V_3 , false ) ;
}
int F_47 ( struct V_29 * V_30 , const unsigned char * V_3 )
{
return F_45 ( V_30 , V_3 , true ) ;
}
int F_48 ( struct V_29 * V_38 , struct V_29 * V_39 )
{
int V_26 = 0 ;
if ( V_38 -> V_4 != V_39 -> V_4 )
return - V_21 ;
F_35 ( V_38 ) ;
V_26 = F_16 ( & V_38 -> V_41 , & V_39 -> V_41 , V_38 -> V_4 ) ;
if ( ! V_26 )
F_30 ( V_38 ) ;
F_36 ( V_38 ) ;
return V_26 ;
}
int F_49 ( struct V_29 * V_38 , struct V_29 * V_39 )
{
int V_26 = 0 ;
if ( V_38 -> V_4 != V_39 -> V_4 )
return - V_21 ;
F_35 ( V_38 ) ;
V_26 = F_14 ( & V_38 -> V_41 , & V_39 -> V_41 , V_38 -> V_4 ) ;
if ( ! V_26 )
F_30 ( V_38 ) ;
F_36 ( V_38 ) ;
return V_26 ;
}
void F_50 ( struct V_29 * V_38 , struct V_29 * V_39 )
{
if ( V_38 -> V_4 != V_39 -> V_4 )
return;
F_29 ( V_39 ) ;
F_35 ( V_38 ) ;
F_17 ( & V_38 -> V_41 , & V_39 -> V_41 , V_38 -> V_4 ) ;
F_30 ( V_38 ) ;
F_36 ( V_38 ) ;
F_31 ( V_39 ) ;
}
void F_51 ( struct V_29 * V_30 )
{
F_29 ( V_30 ) ;
F_18 ( & V_30 -> V_41 ) ;
F_31 ( V_30 ) ;
}
void F_52 ( struct V_29 * V_30 )
{
F_19 ( & V_30 -> V_41 ) ;
}
