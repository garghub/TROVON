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
T_3 V_14 = V_15 ;
T_4 V_16 = V_17 ;
int V_18 = 0 ;
F_8 (pa, acl, pe) {
if ( V_10 -> V_19 & ~ ( V_20 | V_21 | V_22 ) )
return - V_23 ;
switch ( V_10 -> V_24 ) {
case V_13 :
if ( V_12 == V_13 ) {
V_12 = V_25 ;
break;
}
return - V_23 ;
case V_25 :
if ( V_12 != V_25 )
return - V_23 ;
if ( ! F_9 ( V_10 -> V_26 ) )
return - V_23 ;
if ( F_9 ( V_14 ) &&
F_10 ( V_10 -> V_26 , V_14 ) )
return - V_23 ;
V_14 = V_10 -> V_26 ;
V_18 = 1 ;
break;
case V_27 :
if ( V_12 == V_25 ) {
V_12 = V_28 ;
break;
}
return - V_23 ;
case V_28 :
if ( V_12 != V_28 )
return - V_23 ;
if ( ! F_11 ( V_10 -> V_29 ) )
return - V_23 ;
if ( F_11 ( V_16 ) &&
F_12 ( V_10 -> V_29 , V_16 ) )
return - V_23 ;
V_16 = V_10 -> V_29 ;
V_18 = 1 ;
break;
case V_30 :
if ( V_12 != V_28 )
return - V_23 ;
V_12 = V_31 ;
break;
case V_31 :
if ( V_12 == V_31 ||
( V_12 == V_28 && ! V_18 ) ) {
V_12 = 0 ;
break;
}
return - V_23 ;
default:
return - V_23 ;
}
}
if ( V_12 == 0 )
return 0 ;
return - V_23 ;
}
int
F_13 ( const struct V_1 * V_2 , T_5 * V_32 )
{
const struct V_8 * V_10 , * V_11 ;
T_5 V_33 = 0 ;
int V_34 = 0 ;
F_8 (pa, acl, pe) {
switch ( V_10 -> V_24 ) {
case V_13 :
V_33 |= ( V_10 -> V_19 & V_35 ) << 6 ;
break;
case V_27 :
V_33 |= ( V_10 -> V_19 & V_35 ) << 3 ;
break;
case V_31 :
V_33 |= V_10 -> V_19 & V_35 ;
break;
case V_30 :
V_33 = ( V_33 & ~ V_36 ) |
( ( V_10 -> V_19 & V_35 ) << 3 ) ;
V_34 = 1 ;
break;
case V_25 :
case V_28 :
V_34 = 1 ;
break;
default:
return - V_23 ;
}
}
if ( V_32 )
* V_32 = ( * V_32 & ~ V_37 ) | V_33 ;
return V_34 ;
}
struct V_1 *
F_14 ( T_5 V_33 , T_1 V_6 )
{
struct V_1 * V_2 = F_3 ( 3 , V_6 ) ;
if ( ! V_2 )
return F_15 ( - V_38 ) ;
V_2 -> V_39 [ 0 ] . V_24 = V_13 ;
V_2 -> V_39 [ 0 ] . V_19 = ( V_33 & V_40 ) >> 6 ;
V_2 -> V_39 [ 1 ] . V_24 = V_27 ;
V_2 -> V_39 [ 1 ] . V_19 = ( V_33 & V_36 ) >> 3 ;
V_2 -> V_39 [ 2 ] . V_24 = V_31 ;
V_2 -> V_39 [ 2 ] . V_19 = ( V_33 & V_35 ) ;
return V_2 ;
}
int
F_16 ( struct V_41 * V_41 , const struct V_1 * V_2 , int V_42 )
{
const struct V_8 * V_10 , * V_11 , * V_43 ;
int V_44 = 0 ;
V_42 &= V_45 | V_46 | V_47 | V_48 ;
F_8 (pa, acl, pe) {
switch( V_10 -> V_24 ) {
case V_13 :
if ( F_17 ( V_41 -> V_49 , F_18 () ) )
goto V_50;
break;
case V_25 :
if ( F_17 ( V_10 -> V_26 , F_18 () ) )
goto V_51;
break;
case V_27 :
if ( F_19 ( V_41 -> V_52 ) ) {
V_44 = 1 ;
if ( ( V_10 -> V_19 & V_42 ) == V_42 )
goto V_51;
}
break;
case V_28 :
if ( F_19 ( V_10 -> V_29 ) ) {
V_44 = 1 ;
if ( ( V_10 -> V_19 & V_42 ) == V_42 )
goto V_51;
}
break;
case V_30 :
break;
case V_31 :
if ( V_44 )
return - V_53 ;
else
goto V_50;
default:
return - V_54 ;
}
}
return - V_54 ;
V_51:
for ( V_43 = V_10 + 1 ; V_43 != V_11 ; V_43 ++ ) {
if ( V_43 -> V_24 == V_30 ) {
if ( ( V_10 -> V_19 & V_43 -> V_19 & V_42 ) == V_42 )
return 0 ;
return - V_53 ;
}
}
V_50:
if ( ( V_10 -> V_19 & V_42 ) == V_42 )
return 0 ;
return - V_53 ;
}
static int F_20 ( struct V_1 * V_2 , T_5 * V_32 )
{
struct V_8 * V_10 , * V_11 ;
struct V_8 * V_55 = NULL , * V_43 = NULL ;
T_5 V_33 = * V_32 ;
int V_34 = 0 ;
F_8 (pa, acl, pe) {
switch( V_10 -> V_24 ) {
case V_13 :
V_10 -> V_19 &= ( V_33 >> 6 ) | ~ V_35 ;
V_33 &= ( V_10 -> V_19 << 6 ) | ~ V_40 ;
break;
case V_25 :
case V_28 :
V_34 = 1 ;
break;
case V_27 :
V_55 = V_10 ;
break;
case V_31 :
V_10 -> V_19 &= V_33 | ~ V_35 ;
V_33 &= V_10 -> V_19 | ~ V_35 ;
break;
case V_30 :
V_43 = V_10 ;
V_34 = 1 ;
break;
default:
return - V_54 ;
}
}
if ( V_43 ) {
V_43 -> V_19 &= ( V_33 >> 3 ) | ~ V_35 ;
V_33 &= ( V_43 -> V_19 << 3 ) | ~ V_36 ;
} else {
if ( ! V_55 )
return - V_54 ;
V_55 -> V_19 &= ( V_33 >> 3 ) | ~ V_35 ;
V_33 &= ( V_55 -> V_19 << 3 ) | ~ V_36 ;
}
* V_32 = ( * V_32 & ~ V_37 ) | V_33 ;
return V_34 ;
}
static int F_21 ( struct V_1 * V_2 , T_5 V_33 )
{
struct V_8 * V_55 = NULL , * V_43 = NULL ;
struct V_8 * V_10 , * V_11 ;
F_8 (pa, acl, pe) {
switch( V_10 -> V_24 ) {
case V_13 :
V_10 -> V_19 = ( V_33 & V_40 ) >> 6 ;
break;
case V_25 :
case V_28 :
break;
case V_27 :
V_55 = V_10 ;
break;
case V_30 :
V_43 = V_10 ;
break;
case V_31 :
V_10 -> V_19 = ( V_33 & V_35 ) ;
break;
default:
return - V_54 ;
}
}
if ( V_43 ) {
V_43 -> V_19 = ( V_33 & V_36 ) >> 3 ;
} else {
if ( ! V_55 )
return - V_54 ;
V_55 -> V_19 = ( V_33 & V_36 ) >> 3 ;
}
return 0 ;
}
int
F_22 ( struct V_1 * * V_2 , T_1 V_56 , T_5 * V_32 )
{
struct V_1 * V_9 = F_5 ( * V_2 , V_56 ) ;
int V_57 = - V_38 ;
if ( V_9 ) {
V_57 = F_20 ( V_9 , V_32 ) ;
if ( V_57 < 0 ) {
F_23 ( V_9 ) ;
V_9 = NULL ;
}
}
F_23 ( * V_2 ) ;
* V_2 = V_9 ;
return V_57 ;
}
int
F_24 ( struct V_1 * * V_2 , T_1 V_56 , T_5 V_33 )
{
struct V_1 * V_9 = F_5 ( * V_2 , V_56 ) ;
int V_57 = - V_38 ;
if ( V_9 ) {
V_57 = F_21 ( V_9 , V_33 ) ;
if ( V_57 ) {
F_23 ( V_9 ) ;
V_9 = NULL ;
}
}
F_23 ( * V_2 ) ;
* V_2 = V_9 ;
return V_57 ;
}
