static unsigned int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_3 * V_5 ;
unsigned int V_6 = 0 ;
for ( V_5 = V_2 -> V_7 ; V_5 -> type != V_8 ; V_5 ++ ) {
if ( V_5 -> type == V_9 ) {
if ( V_5 == V_4 )
break;
V_6 ++ ;
}
}
return V_6 ;
}
static struct V_3 * F_2 ( struct V_1 * V_2 ,
unsigned int V_10 )
{
struct V_3 * V_5 ;
unsigned int V_11 = 0 ;
for ( V_5 = V_2 -> V_7 ; V_5 -> type != V_8 ; V_5 ++ )
if ( V_5 -> type == V_9 )
if ( V_11 ++ == V_10 )
return V_5 ;
return NULL ;
}
struct V_3 * F_3 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
struct V_3 * V_5 ;
for ( V_5 = V_2 -> V_7 ; V_5 -> type != V_8 ; V_5 ++ )
if ( V_12 == V_5 -> V_12 )
return V_5 ;
return NULL ;
}
struct V_3 * F_4 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
struct V_3 * V_5 ;
for ( V_5 = V_2 -> V_7 ; V_5 -> type != V_8 ; V_5 ++ )
if ( V_5 -> type == V_9 && V_7 == V_5 -> V_7 )
return V_5 ;
return NULL ;
}
static struct V_3 * F_5 ( struct V_1 * V_2 ,
const struct V_13 * V_14 )
{
struct V_3 * V_5 ;
unsigned int V_15 ;
if ( V_14 -> V_16 & V_17 )
V_5 = F_2 ( V_2 , V_14 -> V_10 ) ;
else if ( F_6 ( V_14 , & V_15 ) == 0 )
V_5 = F_3 ( V_2 , V_15 ) ;
else
V_5 = NULL ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
const struct V_3 * V_5 ;
if ( V_2 -> V_7 ) {
V_5 = F_5 ( V_2 , V_14 ) ;
if ( V_5 && V_5 -> type == V_9 ) {
V_14 -> V_7 = V_5 -> V_7 ;
if ( ! ( V_14 -> V_16 & V_17 ) )
V_14 -> V_10 =
F_1 ( V_2 , V_5 ) ;
V_14 -> V_18 = sizeof( V_5 -> V_12 ) ;
memcpy ( V_14 -> V_15 , & V_5 -> V_12 , sizeof( V_5 -> V_12 ) ) ;
return 0 ;
}
}
return - V_19 ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_13 * V_14 ,
unsigned int * V_20 )
{
struct V_3 * V_5 ;
if ( V_2 -> V_7 ) {
V_5 = F_5 ( V_2 , V_14 ) ;
if ( V_5 && V_5 -> type == V_9 ) {
* V_20 = V_5 -> V_7 ;
V_5 -> V_7 = V_14 -> V_7 ;
F_9 ( V_14 -> V_7 , V_2 -> V_21 ) ;
if ( ! F_4 ( V_2 , * V_20 ) )
F_10 ( * V_20 , V_2 -> V_21 ) ;
return 0 ;
}
}
return - V_19 ;
}
int F_11 ( struct V_1 * V_2 ,
const struct V_3 * V_22 ,
int (* F_12)( struct V_1 * , struct V_3 * ) )
{
T_1 V_23 = 1 ;
const struct V_3 * V_24 ;
struct V_3 * V_25 , * V_26 ;
int V_27 ;
int error ;
for ( V_24 = V_22 ; V_24 -> type != V_8 ; V_24 ++ )
V_23 ++ ;
V_25 = F_13 ( & V_2 -> V_2 , V_22 , V_23 * sizeof( * V_25 ) ,
V_28 ) ;
if ( ! V_25 )
return - V_29 ;
for ( V_27 = 0 ; V_27 < V_23 ; V_27 ++ ) {
V_26 = & V_25 [ V_27 ] ;
if ( F_12 ) {
error = F_12 ( V_2 , V_26 ) ;
if ( error )
return error ;
}
switch ( V_26 -> type ) {
case V_9 :
F_14 ( V_30 , V_2 -> V_31 ) ;
F_14 ( V_26 -> V_7 , V_2 -> V_21 ) ;
break;
case V_32 :
case V_33 :
F_14 ( V_34 , V_2 -> V_31 ) ;
F_14 ( V_26 -> V_35 . V_12 , V_2 -> V_36 ) ;
break;
}
}
if ( F_15 ( V_30 , V_2 -> V_31 ) ) {
F_14 ( V_37 , V_2 -> V_21 ) ;
F_14 ( V_38 , V_2 -> V_31 ) ;
F_14 ( V_39 , V_2 -> V_40 ) ;
}
V_2 -> V_7 = V_25 ;
V_2 -> V_41 = V_23 ;
V_2 -> V_42 = F_7 ;
V_2 -> V_43 = F_8 ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 , const struct V_3 * V_14 ,
unsigned int V_44 , bool V_45 )
{
switch ( V_14 -> type ) {
case V_9 :
F_17 ( V_2 , V_38 , V_39 , V_14 -> V_12 ) ;
F_18 ( V_2 , V_14 -> V_7 , V_44 ) ;
F_19 ( V_2 ) ;
if ( V_44 && V_45 ) {
F_18 ( V_2 , V_14 -> V_7 , 0 ) ;
F_19 ( V_2 ) ;
}
break;
case V_32 :
V_44 = V_14 -> V_35 . V_44 ;
case V_33 :
F_20 ( V_2 , V_14 -> V_35 . V_12 , V_44 ) ;
break;
}
}
bool F_21 ( struct V_1 * V_2 , unsigned int V_12 ,
unsigned int V_44 , bool V_45 )
{
const struct V_3 * V_14 =
F_3 ( V_2 , V_12 ) ;
struct V_3 V_46 ;
if ( V_14 ) {
F_16 ( V_2 , V_14 , V_44 , V_45 ) ;
return true ;
}
V_46 . type = V_9 ;
V_46 . V_12 = V_12 ;
V_46 . V_7 = V_37 ;
F_16 ( V_2 , & V_46 , V_44 , true ) ;
return false ;
}
