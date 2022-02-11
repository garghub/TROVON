T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 , void * V_4 , T_3 V_5 )
{
struct V_6 V_7 [] = {
{
. V_8 = V_9 ,
. V_10 = 0 ,
. V_11 = 1 ,
. V_12 = & V_3 ,
} ,
{
. V_8 = V_9 ,
. V_10 = V_13 ,
. V_11 = V_5 ,
. V_12 = V_4 ,
} ,
} ;
int V_14 ;
V_14 = F_2 ( V_2 , V_7 , F_3 ( V_7 ) ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 != F_3 ( V_7 ) )
return - V_15 ;
return 0 ;
}
T_1 F_4 ( struct V_1 * V_2 ,
T_2 V_3 , const void * V_4 , T_3 V_5 )
{
struct V_6 V_16 = {
. V_8 = V_9 ,
. V_10 = 0 ,
. V_11 = 1 + V_5 ,
. V_12 = NULL ,
} ;
void * V_17 ;
int V_14 ;
V_17 = F_5 ( V_16 . V_11 , V_18 ) ;
if ( ! V_17 )
return - V_19 ;
V_16 . V_12 = V_17 ;
memcpy ( V_17 , & V_3 , 1 ) ;
memcpy ( V_17 + 1 , V_4 , V_5 ) ;
V_14 = F_2 ( V_2 , & V_16 , 1 ) ;
F_6 ( V_17 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 != 1 )
return - V_15 ;
return 0 ;
}
static bool F_7 ( const char V_20 [ V_21 ] )
{
static const char V_22 [ V_21 ] =
L_1 ;
return memcmp ( V_20 , V_22 ,
sizeof( V_22 ) ) == 0 ;
}
static bool F_8 ( T_4 V_23 )
{
return V_23 == ( V_24 |
V_25 ) ;
}
enum V_26 F_9 ( struct V_1 * V_2 )
{
char V_20 [ V_21 ] = {} ;
T_4 V_23 = 0x00 ;
T_1 V_14 ;
V_14 = F_1 ( V_2 , V_27 ,
V_20 , sizeof( V_20 ) ) ;
if ( V_14 )
return V_28 ;
V_14 = F_1 ( V_2 , V_29 ,
& V_23 , sizeof( V_23 ) ) ;
if ( V_14 == 0 ) {
if ( F_8 ( V_23 ) ) {
if ( F_7 ( V_20 ) )
return V_30 ;
else
return V_31 ;
}
}
if ( F_7 ( V_20 ) )
return V_32 ;
else
return V_33 ;
}
int F_10 ( enum V_26 type ,
struct V_1 * V_2 )
{
T_4 V_34 ;
T_1 V_14 ;
if ( type == V_35 )
return 0 ;
if ( type < V_31 )
return 165000 ;
V_14 = F_1 ( V_2 , V_36 ,
& V_34 , sizeof( V_34 ) ) ;
if ( V_14 || V_34 == 0x00 || V_34 == 0xff ) {
F_11 ( L_2 ) ;
return 165000 ;
}
return V_34 * 5000 / 2 ;
}
int F_12 ( enum V_26 type ,
struct V_1 * V_2 ,
bool * V_37 )
{
T_4 V_38 ;
T_1 V_14 ;
if ( type < V_31 ) {
* V_37 = true ;
return 0 ;
}
V_14 = F_1 ( V_2 , V_39 ,
& V_38 , sizeof( V_38 ) ) ;
if ( V_14 ) {
F_11 ( L_3 ) ;
return V_14 ;
}
* V_37 = ! ( V_38 & V_40 ) ;
return 0 ;
}
int F_13 ( enum V_26 type ,
struct V_1 * V_2 , bool V_41 )
{
T_4 V_38 = V_41 ? 0 : V_40 ;
T_1 V_14 ;
if ( type < V_31 )
return 0 ;
V_14 = F_4 ( V_2 , V_39 ,
& V_38 , sizeof( V_38 ) ) ;
if ( V_14 ) {
F_11 ( L_4 ,
V_41 ? L_5 : L_6 ) ;
return V_14 ;
}
return 0 ;
}
const char * F_14 ( enum V_26 type )
{
switch ( type ) {
case V_35 :
return L_7 ;
case V_33 :
return L_8 ;
case V_32 :
return L_9 ;
case V_31 :
return L_10 ;
case V_30 :
return L_11 ;
default:
F_15 ( type != V_28 ) ;
return L_12 ;
}
}
