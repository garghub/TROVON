static bool F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ( V_2 -> V_5 & V_6 ) && ( V_2 -> type != V_4 -> type ) )
return false ;
if ( ( V_2 -> V_5 & V_7 ) && ( V_2 -> V_8 != V_4 -> V_8 ) )
return false ;
if ( ( V_2 -> V_5 & V_9 ) &&
( ( V_4 -> type == V_10 ) || ( V_4 -> V_8 == 2 ) ) &&
( V_2 -> V_11 != V_4 -> V_11 ) )
return false ;
if ( ( V_2 -> V_5 & V_12 ) && ( V_4 -> type == V_13 ) &&
( V_2 -> V_14 != V_4 -> V_14 ) )
return false ;
return true ;
}
static bool F_2 ( const struct V_15 * V_16 , struct V_17 * V_18 , T_1 V_19 )
{
const struct V_1 * V_2 = V_18 -> V_20 ;
int V_21 = sizeof( struct V_22 ) ;
int V_23 = V_19 + V_21 ;
union V_24 * V_25 ;
union V_24 V_26 ;
T_1 V_5 ;
struct V_3 V_4 = { 0 , } ;
if ( V_18 -> V_27 != 0 )
return false ;
V_25 = F_3 ( V_16 , V_23 , 2 , & V_26 ) ;
if ( V_25 == NULL )
return false ;
V_5 = F_4 ( V_25 -> V_28 [ 0 ] ) ;
if ( V_5 & V_29 )
V_4 . type = V_10 ;
else
V_4 . type = V_13 ;
V_4 . V_8 = ( V_30 ) V_5 & V_31 ;
if ( V_4 . V_8 == 3 ) {
V_25 = F_3 ( V_16 , V_23 + 4 , 4 , & V_26 ) ;
if ( V_25 == NULL )
return false ;
if ( V_4 . type == V_10 )
V_4 . V_11 = F_5 ( V_25 -> V_32 ) ;
else
V_4 . V_14 = F_5 ( V_25 -> V_32 ) ;
} else if ( V_4 . V_8 == 2 ) {
if ( V_5 & V_33 )
V_23 += 2 ;
V_25 = F_3 ( V_16 , V_23 + 2 , 4 , & V_26 ) ;
if ( V_25 == NULL )
return false ;
V_4 . V_11 = ( V_34 ) F_4 ( V_25 -> V_28 [ 0 ] ) ;
V_4 . V_14 = ( V_34 ) F_4 ( V_25 -> V_28 [ 1 ] ) ;
} else
return false ;
return F_1 ( V_2 , & V_4 ) ;
}
static bool F_6 ( const struct V_15 * V_16 , struct V_17 * V_18 , T_1 V_19 )
{
const struct V_1 * V_2 = V_18 -> V_20 ;
union V_24 * V_25 ;
union V_24 V_26 ;
struct V_3 V_4 = { 0 , } ;
V_25 = F_3 ( V_16 , V_19 , sizeof( V_26 ) , & V_26 ) ;
if ( V_25 == NULL )
return false ;
if ( V_25 -> V_32 == 0 ) {
V_4 . type = V_10 ;
V_25 = F_3 ( V_16 , V_19 + 8 , sizeof( V_26 ) ,
& V_26 ) ;
if ( V_25 == NULL )
return false ;
V_4 . V_11 = F_5 ( V_25 -> V_32 ) ;
} else {
V_4 . V_14 = F_5 ( V_25 -> V_32 ) ;
V_4 . type = V_13 ;
}
V_4 . V_8 = 3 ;
return F_1 ( V_2 , & V_4 ) ;
}
static bool F_7 ( const struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_35 * V_36 = F_8 ( V_16 ) ;
V_30 V_37 = V_36 -> V_38 ;
switch ( V_37 ) {
case V_39 :
return F_2 ( V_16 , V_18 , V_18 -> V_19 ) ;
case V_40 :
return F_6 ( V_16 , V_18 , V_18 -> V_19 ) ;
}
return false ;
}
static bool F_9 ( const struct V_15 * V_16 , struct V_17 * V_18 )
{
unsigned int V_19 = 0 ;
unsigned short V_27 = 0 ;
int V_37 ;
V_37 = F_10 ( V_16 , & V_19 , - 1 , & V_27 , NULL ) ;
if ( V_27 != 0 )
return false ;
switch ( V_37 ) {
case V_39 :
return F_2 ( V_16 , V_18 , V_19 ) ;
case V_40 :
return F_6 ( V_16 , V_18 , V_19 ) ;
}
return false ;
}
static int F_11 ( const struct V_41 * V_18 )
{
const struct V_1 * V_2 = V_18 -> V_20 ;
if ( V_2 -> V_5 & ~ ( V_9 | V_12 | V_7 |
V_6 ) ) {
F_12 ( L_1 , V_2 -> V_5 ) ;
return - V_42 ;
}
if ( ( ! ( V_2 -> V_5 & V_9 ) ) &&
( ! ( V_2 -> V_5 & V_12 ) ) &&
( ( ! ( V_2 -> V_5 & V_6 ) ) ||
( V_2 -> type != V_10 ) ) ) {
F_12 ( L_2 , V_2 -> V_5 ) ;
return - V_42 ;
}
if ( V_2 -> V_5 & V_7 ) {
if ( ( V_2 -> V_8 < 2 ) || ( V_2 -> V_8 > 3 ) ) {
F_12 ( L_3 , V_2 -> V_8 ) ;
return - V_42 ;
}
if ( V_2 -> V_8 == 2 ) {
if ( ( V_2 -> V_5 & V_9 ) &&
( V_2 -> V_11 > 0xffff ) ) {
F_12 ( L_4 , V_2 -> V_11 ) ;
return - V_42 ;
}
if ( ( V_2 -> V_5 & V_12 ) &&
( V_2 -> V_14 > 0xffff ) ) {
F_12 ( L_5 , V_2 -> V_14 ) ;
return - V_42 ;
}
}
}
return 0 ;
}
static int F_13 ( const struct V_41 * V_18 )
{
const struct V_1 * V_2 = V_18 -> V_20 ;
const struct V_43 * V_44 = V_18 -> V_45 ;
const struct V_46 * V_47 = & V_44 -> V_47 ;
int V_48 ;
V_48 = F_11 ( V_18 ) ;
if ( V_48 != 0 )
return V_48 ;
if ( ( V_47 -> V_49 != V_39 ) &&
( V_47 -> V_49 != V_40 ) ) {
F_12 ( L_6 ) ;
return - V_42 ;
}
if ( ( V_47 -> V_49 == V_40 ) &&
( V_2 -> V_8 == 2 ) ) {
F_12 ( L_7 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_14 ( const struct V_41 * V_18 )
{
const struct V_1 * V_2 = V_18 -> V_20 ;
const struct V_50 * V_44 = V_18 -> V_45 ;
const struct V_51 * V_47 = & V_44 -> V_52 ;
int V_48 ;
V_48 = F_11 ( V_18 ) ;
if ( V_48 != 0 )
return V_48 ;
if ( ( V_47 -> V_49 != V_39 ) &&
( V_47 -> V_49 != V_40 ) ) {
F_12 ( L_6 ) ;
return - V_42 ;
}
if ( ( V_47 -> V_49 == V_40 ) &&
( V_2 -> V_8 == 2 ) ) {
F_12 ( L_7 ) ;
return - V_42 ;
}
return 0 ;
}
static int T_2 F_15 ( void )
{
return F_16 ( & V_53 [ 0 ] , F_17 ( V_53 ) ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_53 [ 0 ] , F_17 ( V_53 ) ) ;
}
