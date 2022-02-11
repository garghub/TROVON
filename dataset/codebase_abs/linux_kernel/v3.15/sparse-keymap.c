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
V_25 = F_13 ( V_23 , sizeof( struct V_3 ) , V_28 ) ;
if ( ! V_25 )
return - V_29 ;
memcpy ( V_25 , V_22 , V_23 * sizeof( struct V_3 ) ) ;
for ( V_27 = 0 ; V_27 < V_23 ; V_27 ++ ) {
V_26 = & V_25 [ V_27 ] ;
if ( F_12 ) {
error = F_12 ( V_2 , V_26 ) ;
if ( error )
goto V_30;
}
switch ( V_26 -> type ) {
case V_9 :
F_14 ( V_31 , V_2 -> V_32 ) ;
F_14 ( V_26 -> V_7 , V_2 -> V_21 ) ;
break;
case V_33 :
case V_34 :
F_14 ( V_35 , V_2 -> V_32 ) ;
F_14 ( V_26 -> V_36 . V_12 , V_2 -> V_37 ) ;
break;
}
}
if ( F_15 ( V_31 , V_2 -> V_32 ) ) {
F_14 ( V_38 , V_2 -> V_21 ) ;
F_14 ( V_39 , V_2 -> V_32 ) ;
F_14 ( V_40 , V_2 -> V_41 ) ;
}
V_2 -> V_7 = V_25 ;
V_2 -> V_42 = V_23 ;
V_2 -> V_43 = F_7 ;
V_2 -> V_44 = F_8 ;
return 0 ;
V_30:
F_16 ( V_25 ) ;
return error ;
}
void F_17 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
F_18 ( & V_2 -> V_45 , V_16 ) ;
F_16 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
V_2 -> V_42 = 0 ;
F_19 ( & V_2 -> V_45 , V_16 ) ;
}
void F_20 ( struct V_1 * V_2 , const struct V_3 * V_14 ,
unsigned int V_46 , bool V_47 )
{
switch ( V_14 -> type ) {
case V_9 :
F_21 ( V_2 , V_39 , V_40 , V_14 -> V_12 ) ;
F_22 ( V_2 , V_14 -> V_7 , V_46 ) ;
F_23 ( V_2 ) ;
if ( V_46 && V_47 ) {
F_22 ( V_2 , V_14 -> V_7 , 0 ) ;
F_23 ( V_2 ) ;
}
break;
case V_33 :
V_46 = V_14 -> V_36 . V_46 ;
case V_34 :
F_24 ( V_2 , V_14 -> V_36 . V_12 , V_46 ) ;
break;
}
}
bool F_25 ( struct V_1 * V_2 , unsigned int V_12 ,
unsigned int V_46 , bool V_47 )
{
const struct V_3 * V_14 =
F_3 ( V_2 , V_12 ) ;
struct V_3 V_48 ;
if ( V_14 ) {
F_20 ( V_2 , V_14 , V_46 , V_47 ) ;
return true ;
}
V_48 . type = V_9 ;
V_48 . V_12 = V_12 ;
V_48 . V_7 = V_38 ;
F_20 ( V_2 , & V_48 , V_46 , true ) ;
return false ;
}
