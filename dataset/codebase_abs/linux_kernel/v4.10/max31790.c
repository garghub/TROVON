static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_1 * V_7 = V_4 ;
int V_8 ;
int V_9 ;
F_3 ( & V_4 -> V_10 ) ;
if ( F_4 ( V_11 , V_4 -> V_12 + V_13 ) || ! V_4 -> V_14 ) {
V_9 = F_5 ( V_6 ,
V_15 ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_16 = V_9 & 0x3F ;
V_9 = F_5 ( V_6 ,
V_17 ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_16 |= ( V_9 & 0x3F ) << 6 ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ ) {
V_9 = F_6 ( V_6 ,
F_7 ( V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_19 [ V_8 ] = V_9 ;
if ( V_4 -> V_20 [ V_8 ]
& V_21 ) {
V_9 = F_6 ( V_6 ,
F_7 ( V_18
+ V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_19 [ V_18 + V_8 ] = V_9 ;
} else {
V_9 = F_6 ( V_6 ,
F_8 ( V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_22 [ V_8 ] = V_9 ;
V_9 = F_6 ( V_6 ,
F_9 ( V_8 ) ) ;
if ( V_9 < 0 )
goto abort;
V_4 -> V_23 [ V_8 ] = V_9 ;
}
}
V_4 -> V_12 = V_11 ;
V_4 -> V_14 = true ;
}
goto V_24;
abort:
V_4 -> V_14 = false ;
V_7 = F_10 ( V_9 ) ;
V_24:
F_11 ( & V_4 -> V_10 ) ;
return V_7 ;
}
static T_1 F_12 ( T_1 V_25 )
{
return V_26 [ F_13 ( V_25 ) ] ;
}
static T_1 F_14 ( int V_27 )
{
T_1 V_28 ;
if ( V_27 < 500 )
V_28 = 0x0 ;
else if ( V_27 < 1000 )
V_28 = 0x1 ;
else if ( V_27 < 2000 )
V_28 = 0x2 ;
else if ( V_27 < 4000 )
V_28 = 0x3 ;
else if ( V_27 < 8000 )
V_28 = 0x4 ;
else
V_28 = 0x5 ;
return V_28 ;
}
static int F_15 ( struct V_2 * V_3 , T_2 V_29 , int V_30 ,
long * V_31 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_32 , V_27 ;
if ( F_16 ( V_4 ) )
return F_17 ( V_4 ) ;
switch ( V_29 ) {
case V_33 :
V_32 = F_12 ( V_4 -> V_25 [ V_30 ] ) ;
V_27 = F_18 ( V_4 -> V_19 [ V_30 ] , V_32 ) ;
* V_31 = V_27 ;
return 0 ;
case V_34 :
V_32 = F_12 ( V_4 -> V_25 [ V_30 ] ) ;
V_27 = F_18 ( V_4 -> V_23 [ V_30 ] , V_32 ) ;
* V_31 = V_27 ;
return 0 ;
case V_35 :
* V_31 = ! ! ( V_4 -> V_16 & ( 1 << V_30 ) ) ;
return 0 ;
default:
return - V_36 ;
}
}
static int F_19 ( struct V_2 * V_3 , T_2 V_29 , int V_30 ,
long V_31 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_23 ;
int V_37 = 0 ;
T_1 V_28 ;
int V_32 ;
F_3 ( & V_4 -> V_10 ) ;
switch ( V_29 ) {
case V_34 :
V_31 = F_20 ( V_31 , V_38 , V_39 ) ;
V_28 = F_14 ( V_31 ) ;
V_4 -> V_25 [ V_30 ] =
( ( V_4 -> V_25 [ V_30 ] &
~ V_40 ) |
( V_28 << V_41 ) ) ;
V_37 = F_21 ( V_6 ,
F_22 ( V_30 ) ,
V_4 -> V_25 [ V_30 ] ) ;
if ( V_37 < 0 )
break;
V_32 = F_12 ( V_4 -> V_25 [ V_30 ] ) ;
V_23 = F_23 ( V_31 , V_32 ) ;
V_23 = F_20 ( V_23 , 0x1 , 0x7FF ) ;
V_4 -> V_23 [ V_30 ] = V_23 << 5 ;
V_37 = F_24 ( V_6 ,
F_9 ( V_30 ) ,
V_4 -> V_23 [ V_30 ] ) ;
break;
default:
V_37 = - V_36 ;
break;
}
F_11 ( & V_4 -> V_10 ) ;
return V_37 ;
}
static T_3 F_25 ( const void * V_42 , T_2 V_29 , int V_30 )
{
const struct V_1 * V_4 = V_42 ;
T_1 V_20 = V_4 -> V_20 [ V_30 % V_18 ] ;
switch ( V_29 ) {
case V_33 :
case V_35 :
if ( V_30 < V_18 ||
( V_20 & V_21 ) )
return V_43 ;
return 0 ;
case V_34 :
if ( V_30 < V_18 &&
! ( V_20 & V_21 ) )
return V_43 | V_44 ;
return 0 ;
default:
return 0 ;
}
}
static int F_26 ( struct V_2 * V_3 , T_2 V_29 , int V_30 ,
long * V_31 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_20 ;
if ( F_16 ( V_4 ) )
return F_17 ( V_4 ) ;
V_20 = V_4 -> V_20 [ V_30 ] ;
switch ( V_29 ) {
case V_45 :
* V_31 = V_4 -> V_22 [ V_30 ] >> 8 ;
return 0 ;
case V_46 :
if ( V_20 & V_47 )
* V_31 = 2 ;
else if ( V_20 & V_48 )
* V_31 = 1 ;
else
* V_31 = 0 ;
return 0 ;
default:
return - V_36 ;
}
}
static int F_27 ( struct V_2 * V_3 , T_2 V_29 , int V_30 ,
long V_31 )
{
struct V_1 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_20 ;
int V_37 = 0 ;
F_3 ( & V_4 -> V_10 ) ;
switch ( V_29 ) {
case V_45 :
if ( V_31 < 0 || V_31 > 255 ) {
V_37 = - V_49 ;
break;
}
V_4 -> V_22 [ V_30 ] = V_31 << 8 ;
V_37 = F_24 ( V_6 ,
F_8 ( V_30 ) ,
V_31 ) ;
break;
case V_46 :
V_20 = V_4 -> V_20 [ V_30 ] ;
if ( V_31 == 0 ) {
V_20 &= ~ ( V_48 |
V_47 ) ;
} else if ( V_31 == 1 ) {
V_20 = ( V_20 |
V_48 ) &
~ V_47 ;
} else if ( V_31 == 2 ) {
V_20 |= V_48 |
V_47 ;
} else {
V_37 = - V_49 ;
break;
}
V_4 -> V_20 [ V_30 ] = V_20 ;
V_37 = F_21 ( V_6 ,
F_28 ( V_30 ) ,
V_20 ) ;
break;
default:
V_37 = - V_36 ;
break;
}
F_11 ( & V_4 -> V_10 ) ;
return V_37 ;
}
static T_3 F_29 ( const void * V_42 , T_2 V_29 , int V_30 )
{
const struct V_1 * V_4 = V_42 ;
T_1 V_20 = V_4 -> V_20 [ V_30 ] ;
switch ( V_29 ) {
case V_45 :
case V_46 :
if ( ! ( V_20 & V_21 ) )
return V_43 | V_44 ;
return 0 ;
default:
return 0 ;
}
}
static int F_30 ( struct V_2 * V_3 , enum V_50 type ,
T_2 V_29 , int V_30 , long * V_31 )
{
switch ( type ) {
case V_51 :
return F_15 ( V_3 , V_29 , V_30 , V_31 ) ;
case V_52 :
return F_26 ( V_3 , V_29 , V_30 , V_31 ) ;
default:
return - V_36 ;
}
}
static int F_31 ( struct V_2 * V_3 , enum V_50 type ,
T_2 V_29 , int V_30 , long V_31 )
{
switch ( type ) {
case V_51 :
return F_19 ( V_3 , V_29 , V_30 , V_31 ) ;
case V_52 :
return F_27 ( V_3 , V_29 , V_30 , V_31 ) ;
default:
return - V_36 ;
}
}
static T_3 F_32 ( const void * V_4 ,
enum V_50 type ,
T_2 V_29 , int V_30 )
{
switch ( type ) {
case V_51 :
return F_25 ( V_4 , V_29 , V_30 ) ;
case V_52 :
return F_29 ( V_4 , V_29 , V_30 ) ;
default:
return 0 ;
}
}
static int F_33 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
int V_8 , V_9 ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ ) {
V_9 = F_5 ( V_6 ,
F_28 ( V_8 ) ) ;
if ( V_9 < 0 )
return V_9 ;
V_4 -> V_20 [ V_8 ] = V_9 ;
V_9 = F_5 ( V_6 ,
F_22 ( V_8 ) ) ;
if ( V_9 < 0 )
return V_9 ;
V_4 -> V_25 [ V_8 ] = V_9 ;
}
return 0 ;
}
static int F_34 ( struct V_5 * V_6 ,
const struct V_53 * V_54 )
{
struct V_55 * V_56 = V_6 -> V_56 ;
struct V_2 * V_3 = & V_6 -> V_3 ;
struct V_1 * V_4 ;
struct V_2 * V_57 ;
int V_37 ;
if ( ! F_35 ( V_56 ,
V_58 | V_59 ) )
return - V_60 ;
V_4 = F_36 ( V_3 , sizeof( struct V_1 ) , V_61 ) ;
if ( ! V_4 )
return - V_62 ;
V_4 -> V_6 = V_6 ;
F_37 ( & V_4 -> V_10 ) ;
V_37 = F_33 ( V_6 , V_4 ) ;
if ( V_37 )
return V_37 ;
V_57 = F_38 ( V_3 , V_6 -> V_63 ,
V_4 ,
& V_64 ,
NULL ) ;
return F_39 ( V_57 ) ;
}
