void
F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( & V_2 -> V_4 , 1 ) ;
V_2 -> V_5 = V_3 ;
}
struct V_1 *
F_3 ( int V_3 , T_1 V_6 )
{
const T_2 V_7 = sizeof( struct V_1 ) +
V_3 * sizeof( struct V_8 ) ;
struct V_1 * V_2 = F_4 ( V_7 , V_6 ) ;
if ( V_2 )
F_1 ( V_2 , V_3 ) ;
return V_2 ;
}
static struct V_1 *
F_5 ( const struct V_1 * V_2 , T_1 V_6 )
{
struct V_1 * V_9 = NULL ;
if ( V_2 ) {
int V_7 = sizeof( struct V_1 ) + V_2 -> V_5 *
sizeof( struct V_8 ) ;
V_9 = F_6 ( V_2 , V_7 , V_6 ) ;
if ( V_9 )
F_2 ( & V_9 -> V_4 , 1 ) ;
}
return V_9 ;
}
int
F_7 ( const struct V_1 * V_2 )
{
const struct V_8 * V_10 , * V_11 ;
int V_12 = V_13 ;
unsigned int V_14 = 0 ;
int V_15 = 0 ;
F_8 (pa, acl, pe) {
if ( V_10 -> V_16 & ~ ( V_17 | V_18 | V_19 ) )
return - V_20 ;
switch ( V_10 -> V_21 ) {
case V_13 :
if ( V_12 == V_13 ) {
V_14 = 0 ;
V_12 = V_22 ;
break;
}
return - V_20 ;
case V_22 :
if ( V_12 != V_22 )
return - V_20 ;
if ( V_10 -> V_23 == V_24 ||
V_10 -> V_23 < V_14 )
return - V_20 ;
V_14 = V_10 -> V_23 + 1 ;
V_15 = 1 ;
break;
case V_25 :
if ( V_12 == V_22 ) {
V_14 = 0 ;
V_12 = V_26 ;
break;
}
return - V_20 ;
case V_26 :
if ( V_12 != V_26 )
return - V_20 ;
if ( V_10 -> V_23 == V_24 ||
V_10 -> V_23 < V_14 )
return - V_20 ;
V_14 = V_10 -> V_23 + 1 ;
V_15 = 1 ;
break;
case V_27 :
if ( V_12 != V_26 )
return - V_20 ;
V_12 = V_28 ;
break;
case V_28 :
if ( V_12 == V_28 ||
( V_12 == V_26 && ! V_15 ) ) {
V_12 = 0 ;
break;
}
return - V_20 ;
default:
return - V_20 ;
}
}
if ( V_12 == 0 )
return 0 ;
return - V_20 ;
}
int
F_9 ( const struct V_1 * V_2 , T_3 * V_29 )
{
const struct V_8 * V_10 , * V_11 ;
T_3 V_30 = 0 ;
int V_31 = 0 ;
F_8 (pa, acl, pe) {
switch ( V_10 -> V_21 ) {
case V_13 :
V_30 |= ( V_10 -> V_16 & V_32 ) << 6 ;
break;
case V_25 :
V_30 |= ( V_10 -> V_16 & V_32 ) << 3 ;
break;
case V_28 :
V_30 |= V_10 -> V_16 & V_32 ;
break;
case V_27 :
V_30 = ( V_30 & ~ V_33 ) |
( ( V_10 -> V_16 & V_32 ) << 3 ) ;
V_31 = 1 ;
break;
case V_22 :
case V_26 :
V_31 = 1 ;
break;
default:
return - V_20 ;
}
}
if ( V_29 )
* V_29 = ( * V_29 & ~ V_34 ) | V_30 ;
return V_31 ;
}
struct V_1 *
F_10 ( T_3 V_30 , T_1 V_6 )
{
struct V_1 * V_2 = F_3 ( 3 , V_6 ) ;
if ( ! V_2 )
return F_11 ( - V_35 ) ;
V_2 -> V_36 [ 0 ] . V_21 = V_13 ;
V_2 -> V_36 [ 0 ] . V_23 = V_24 ;
V_2 -> V_36 [ 0 ] . V_16 = ( V_30 & V_37 ) >> 6 ;
V_2 -> V_36 [ 1 ] . V_21 = V_25 ;
V_2 -> V_36 [ 1 ] . V_23 = V_24 ;
V_2 -> V_36 [ 1 ] . V_16 = ( V_30 & V_33 ) >> 3 ;
V_2 -> V_36 [ 2 ] . V_21 = V_28 ;
V_2 -> V_36 [ 2 ] . V_23 = V_24 ;
V_2 -> V_36 [ 2 ] . V_16 = ( V_30 & V_32 ) ;
return V_2 ;
}
int
F_12 ( struct V_38 * V_38 , const struct V_1 * V_2 , int V_39 )
{
const struct V_8 * V_10 , * V_11 , * V_40 ;
int V_41 = 0 ;
F_8 (pa, acl, pe) {
switch( V_10 -> V_21 ) {
case V_13 :
if ( V_38 -> V_42 == F_13 () )
goto V_43;
break;
case V_22 :
if ( V_10 -> V_23 == F_13 () )
goto V_44;
break;
case V_25 :
if ( F_14 ( V_38 -> V_45 ) ) {
V_41 = 1 ;
if ( ( V_10 -> V_16 & V_39 ) == V_39 )
goto V_44;
}
break;
case V_26 :
if ( F_14 ( V_10 -> V_23 ) ) {
V_41 = 1 ;
if ( ( V_10 -> V_16 & V_39 ) == V_39 )
goto V_44;
}
break;
case V_27 :
break;
case V_28 :
if ( V_41 )
return - V_46 ;
else
goto V_43;
default:
return - V_47 ;
}
}
return - V_47 ;
V_44:
for ( V_40 = V_10 + 1 ; V_40 != V_11 ; V_40 ++ ) {
if ( V_40 -> V_21 == V_27 ) {
if ( ( V_10 -> V_16 & V_40 -> V_16 & V_39 ) == V_39 )
return 0 ;
return - V_46 ;
}
}
V_43:
if ( ( V_10 -> V_16 & V_39 ) == V_39 )
return 0 ;
return - V_46 ;
}
static int F_15 ( struct V_1 * V_2 , T_3 * V_29 )
{
struct V_8 * V_10 , * V_11 ;
struct V_8 * V_48 = NULL , * V_40 = NULL ;
T_3 V_30 = * V_29 ;
int V_31 = 0 ;
F_8 (pa, acl, pe) {
switch( V_10 -> V_21 ) {
case V_13 :
V_10 -> V_16 &= ( V_30 >> 6 ) | ~ V_32 ;
V_30 &= ( V_10 -> V_16 << 6 ) | ~ V_37 ;
break;
case V_22 :
case V_26 :
V_31 = 1 ;
break;
case V_25 :
V_48 = V_10 ;
break;
case V_28 :
V_10 -> V_16 &= V_30 | ~ V_32 ;
V_30 &= V_10 -> V_16 | ~ V_32 ;
break;
case V_27 :
V_40 = V_10 ;
V_31 = 1 ;
break;
default:
return - V_47 ;
}
}
if ( V_40 ) {
V_40 -> V_16 &= ( V_30 >> 3 ) | ~ V_32 ;
V_30 &= ( V_40 -> V_16 << 3 ) | ~ V_33 ;
} else {
if ( ! V_48 )
return - V_47 ;
V_48 -> V_16 &= ( V_30 >> 3 ) | ~ V_32 ;
V_30 &= ( V_48 -> V_16 << 3 ) | ~ V_33 ;
}
* V_29 = ( * V_29 & ~ V_34 ) | V_30 ;
return V_31 ;
}
static int F_16 ( struct V_1 * V_2 , T_3 V_30 )
{
struct V_8 * V_48 = NULL , * V_40 = NULL ;
struct V_8 * V_10 , * V_11 ;
F_8 (pa, acl, pe) {
switch( V_10 -> V_21 ) {
case V_13 :
V_10 -> V_16 = ( V_30 & V_37 ) >> 6 ;
break;
case V_22 :
case V_26 :
break;
case V_25 :
V_48 = V_10 ;
break;
case V_27 :
V_40 = V_10 ;
break;
case V_28 :
V_10 -> V_16 = ( V_30 & V_32 ) ;
break;
default:
return - V_47 ;
}
}
if ( V_40 ) {
V_40 -> V_16 = ( V_30 & V_33 ) >> 3 ;
} else {
if ( ! V_48 )
return - V_47 ;
V_48 -> V_16 = ( V_30 & V_33 ) >> 3 ;
}
return 0 ;
}
int
F_17 ( struct V_1 * * V_2 , T_1 V_49 , T_3 * V_29 )
{
struct V_1 * V_9 = F_5 ( * V_2 , V_49 ) ;
int V_50 = - V_35 ;
if ( V_9 ) {
V_50 = F_15 ( V_9 , V_29 ) ;
if ( V_50 < 0 ) {
F_18 ( V_9 ) ;
V_9 = NULL ;
}
}
F_18 ( * V_2 ) ;
* V_2 = V_9 ;
return V_50 ;
}
int
F_19 ( struct V_1 * * V_2 , T_1 V_49 , T_3 V_30 )
{
struct V_1 * V_9 = F_5 ( * V_2 , V_49 ) ;
int V_50 = - V_35 ;
if ( V_9 ) {
V_50 = F_16 ( V_9 , V_30 ) ;
if ( V_50 ) {
F_18 ( V_9 ) ;
V_9 = NULL ;
}
}
F_18 ( * V_2 ) ;
* V_2 = V_9 ;
return V_50 ;
}
