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
return V_23 == 0 || V_23 == 0xff ;
}
static bool F_9 ( T_4 V_23 )
{
return V_23 == ( V_24 |
V_25 ) ;
}
static bool F_10 ( const char V_20 [ V_21 ] ,
const T_4 V_23 )
{
return F_7 ( V_20 ) &&
( V_23 == ( V_24 |
V_26 ) ) ;
}
enum V_27 F_11 ( struct V_1 * V_2 )
{
char V_20 [ V_21 ] = {} ;
T_4 V_23 = 0x00 ;
T_1 V_14 ;
V_14 = F_1 ( V_2 , V_28 ,
V_20 , sizeof( V_20 ) ) ;
F_12 ( L_2 ,
V_14 ? 0 : ( int ) sizeof( V_20 ) , V_20 , V_14 ) ;
if ( V_14 )
return V_29 ;
V_14 = F_1 ( V_2 , V_30 ,
& V_23 , sizeof( V_23 ) ) ;
F_12 ( L_3 ,
V_23 , V_14 ) ;
if ( V_14 == 0 ) {
if ( F_10 ( V_20 , V_23 ) )
return V_31 ;
if ( F_9 ( V_23 ) ) {
if ( F_7 ( V_20 ) )
return V_32 ;
else
return V_33 ;
}
if ( ! F_8 ( V_23 ) && V_23 != V_20 [ 0 ] )
F_13 ( L_4 ,
V_23 ) ;
}
if ( F_7 ( V_20 ) )
return V_34 ;
else
return V_35 ;
}
int F_14 ( enum V_27 type ,
struct V_1 * V_2 )
{
T_4 V_36 ;
T_1 V_14 ;
if ( type == V_37 )
return 0 ;
if ( type < V_33 )
return 165000 ;
V_14 = F_1 ( V_2 , V_38 ,
& V_36 , sizeof( V_36 ) ) ;
if ( V_14 || V_36 == 0x00 || V_36 == 0xff ) {
F_12 ( L_5 ) ;
return 165000 ;
}
return V_36 * 5000 / 2 ;
}
int F_15 ( enum V_27 type ,
struct V_1 * V_2 ,
bool * V_39 )
{
T_4 V_40 ;
T_1 V_14 ;
if ( type < V_33 ) {
* V_39 = true ;
return 0 ;
}
V_14 = F_1 ( V_2 , V_41 ,
& V_40 , sizeof( V_40 ) ) ;
if ( V_14 ) {
F_12 ( L_6 ) ;
return V_14 ;
}
* V_39 = ! ( V_40 & V_42 ) ;
return 0 ;
}
int F_16 ( enum V_27 type ,
struct V_1 * V_2 , bool V_43 )
{
T_4 V_40 = V_43 ? 0 : V_42 ;
T_1 V_14 ;
if ( type < V_33 )
return 0 ;
V_14 = F_4 ( V_2 , V_41 ,
& V_40 , sizeof( V_40 ) ) ;
if ( V_14 ) {
F_12 ( L_7 ,
V_43 ? L_8 : L_9 ) ;
return V_14 ;
}
return 0 ;
}
const char * F_17 ( enum V_27 type )
{
switch ( type ) {
case V_37 :
return L_10 ;
case V_35 :
return L_11 ;
case V_34 :
return L_12 ;
case V_33 :
return L_13 ;
case V_32 :
return L_14 ;
case V_31 :
return L_15 ;
default:
F_18 ( type != V_29 ) ;
return L_16 ;
}
}
int F_19 ( struct V_1 * V_2 ,
enum V_44 * V_45 )
{
T_2 V_17 ;
int V_14 = 0 ;
if ( ! V_45 ) {
F_13 ( L_17 ) ;
return - V_46 ;
}
V_14 = F_1 ( V_2 , V_47 ,
& V_17 , sizeof( V_17 ) ) ;
if ( V_14 < 0 ) {
F_13 ( L_18 ) ;
return - V_48 ;
}
if ( V_17 & V_49 )
* V_45 = V_50 ;
else
* V_45 = V_51 ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
enum V_44 V_45 )
{
T_2 V_17 = 0 ;
int V_14 ;
int V_52 = 200 ;
enum V_44 V_53 ;
if ( V_45 == V_50 )
V_17 = V_49 ;
V_14 = F_4 ( V_2 , V_54 ,
& V_17 , sizeof( V_17 ) ) ;
if ( V_14 < 0 ) {
F_13 ( L_19 ) ;
return V_14 ;
}
do {
V_14 = F_19 ( V_2 , & V_53 ) ;
if ( V_14 ) {
F_13 ( L_20 ) ;
return V_14 ;
} else {
if ( V_53 != V_45 ) {
F_21 ( 10 ) ;
V_52 -= 10 ;
} else {
F_12 ( L_21 ,
V_45 == V_51 ?
L_22 : L_23 ) ;
return 0 ;
}
}
} while ( V_52 );
F_13 ( L_24 ) ;
return - V_55 ;
}
