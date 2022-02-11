static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_7 , V_8 , V_9 ;
int V_10 ;
if ( ! V_4 -> V_11 ) {
V_4 -> V_12 [ 0 ] = V_4 -> V_13 [ V_14 - 0x10 ] ;
return;
}
if ( F_3 ( V_15 , V_4 -> V_16 + 5 * V_17 ) ) {
for ( V_10 = 0 ; V_10 < F_4 ( V_4 -> V_12 ) ; V_10 ++ )
V_4 -> V_12 [ V_10 ] = - V_18 ;
}
V_7 = ( V_4 -> V_19 [ V_20 ] & 0xc0 ) >> 6 ;
if ( V_7 > 0 )
V_7 -= 1 ;
V_4 -> V_12 [ V_7 ] = V_4 -> V_13 [ V_14 - 0x10 ] ;
V_8 = ( V_7 + 1 ) % F_4 ( V_4 -> V_12 ) ;
V_9 = ( V_4 -> V_19 [ V_20 ] & 0x3f ) | ( ( V_8 + 1 ) << 6 ) ;
F_5 ( V_6 , V_20 , V_9 ) ;
V_4 -> V_19 [ V_20 ] = V_9 ;
}
static struct V_3 * F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_2 V_21 ;
int V_10 ;
F_7 ( & V_4 -> V_22 ) ;
if ( F_3 ( V_15 , V_4 -> V_16 + V_17 ) || ! V_4 -> V_23 ) {
for ( V_10 = 0 ; V_10 < F_4 ( V_4 -> V_19 ) ; V_10 ++ ) {
V_21 = F_8 ( V_6 , V_10 ) ;
if ( F_9 ( V_21 < 0 ) )
V_4 -> V_19 [ V_10 ] = 0 ;
else
V_4 -> V_19 [ V_10 ] = V_21 ;
}
for ( V_10 = 0 ; V_10 < F_4 ( V_4 -> V_13 ) ; V_10 ++ ) {
V_21 = F_8 ( V_6 , V_10 + 0x10 ) ;
if ( F_9 ( V_21 < 0 ) )
V_4 -> V_13 [ V_10 ] = 0 ;
else
V_4 -> V_13 [ V_10 ] = V_21 ;
}
F_1 ( V_2 ) ;
V_4 -> V_16 = V_15 ;
V_4 -> V_23 = true ;
}
F_10 ( & V_4 -> V_22 ) ;
return V_4 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = F_6 ( V_2 ) ;
const T_1 V_25 = V_4 -> V_13 [ V_24 - 0x10 ] ;
T_3 V_26 = 0 ;
switch ( V_24 ) {
case V_27 :
case V_28 :
V_26 = V_25 * 55 ;
break;
case V_29 :
case V_30 :
V_26 = V_25 * 22 ;
break;
case V_31 :
case V_32 :
V_26 = V_25 * 15 ;
break;
case V_33 :
case V_34 :
V_26 = V_25 * - 55 ;
break;
case V_14 :
V_26 = V_25 * 10 ;
break;
default:
F_12 ( 1 ) ;
break;
}
return V_26 ;
}
static unsigned int F_13 ( struct V_1 * V_2 , T_1 V_24 )
{
struct V_3 * V_4 = F_6 ( V_2 ) ;
const T_1 V_25 = V_4 -> V_13 [ V_24 - 0x10 ] ;
unsigned int V_26 ;
unsigned int V_35 ;
switch ( V_24 ) {
case V_36 :
V_26 = V_25 * 250 ;
V_35 = V_26 / 50 ;
break;
case V_37 :
V_26 = V_25 * 125 ;
V_35 = ( V_26 * 10 ) / 35 ;
break;
case V_38 :
V_26 = V_25 * 125 ;
V_35 = ( V_26 * 10 ) / 25 ;
break;
case V_39 :
V_26 = V_25 * 250 ;
V_35 = V_26 / 100 ;
break;
default:
F_12 ( 1 ) ;
V_35 = 0 ;
break;
}
return V_35 ;
}
static int F_14 ( struct V_1 * V_2 , T_3 V_40 , int V_41 ,
long * V_21 )
{
struct V_3 * V_4 = F_6 ( V_2 ) ;
switch ( V_40 ) {
case V_42 :
* V_21 = F_13 ( V_2 , V_43 [ V_41 ] ) ;
return 0 ;
case V_44 :
* V_21 = ! ! ( V_4 -> V_19 [ V_45 ] & F_15 ( V_41 + 4 ) ) ;
return 0 ;
default:
return - V_46 ;
}
}
static int F_16 ( struct V_1 * V_2 , T_3 V_40 , int V_41 , long * V_21 )
{
struct V_3 * V_4 = F_6 ( V_2 ) ;
switch ( V_40 ) {
case V_47 :
if ( V_41 < 8 ) {
* V_21 = F_11 ( V_2 ,
V_48 [ V_41 ] ) ;
} else {
int V_25 = V_4 -> V_12 [ V_41 - 8 ] ;
if ( V_25 < 0 )
return V_25 ;
* V_21 = V_25 * 10 ;
}
return 0 ;
case V_49 :
if ( V_41 < 4 )
* V_21 = ! ! ( V_4 -> V_19 [ V_45 ] & F_15 ( V_41 ) ) ;
else
* V_21 = ! ! ( V_4 -> V_19 [ V_50 ] &
F_15 ( V_41 - 4 ) ) ;
return 0 ;
default:
return - V_46 ;
}
}
static int F_17 ( struct V_1 * V_2 , T_3 V_40 , int V_41 ,
long * V_21 )
{
unsigned long V_35 ;
long V_26 ;
switch ( V_40 ) {
case V_51 :
( void ) F_6 ( V_2 ) ;
V_35 = F_13 ( V_2 , V_43 [ V_41 ] ) ;
V_26 = F_11 ( V_2 , V_48 [ V_41 ] ) ;
* V_21 = abs ( V_35 * V_26 ) ;
return 0 ;
default:
return - V_46 ;
}
}
static int F_18 ( struct V_1 * V_2 , enum V_52 type ,
T_3 V_40 , int V_41 , long * V_21 )
{
switch ( type ) {
case V_53 :
return F_14 ( V_2 , V_40 , V_41 , V_21 ) ;
case V_54 :
return F_17 ( V_2 , V_40 , V_41 , V_21 ) ;
case V_55 :
return F_16 ( V_2 , V_40 , V_41 - 1 , V_21 ) ;
default:
return - V_46 ;
}
}
static T_4 F_19 ( const void * V_56 ,
enum V_52 type ,
T_3 V_40 , int V_41 )
{
const struct V_3 * V_4 = V_56 ;
switch ( type ) {
case V_55 :
if ( V_41 == 0 )
return 0 ;
switch ( V_40 ) {
case V_47 :
if ( V_41 > 9 && ! V_4 -> V_11 )
return 0 ;
return V_57 ;
case V_49 :
if ( V_41 > 8 )
return 0 ;
return V_57 ;
default:
return 0 ;
}
case V_53 :
switch ( V_40 ) {
case V_42 :
case V_44 :
return V_57 ;
default:
return 0 ;
}
case V_54 :
switch ( V_40 ) {
case V_51 :
return V_57 ;
default:
return 0 ;
}
default:
return 0 ;
}
}
static bool F_20 ( struct V_5 * V_6 )
{
struct V_58 * V_59 = F_21 ( & V_6 -> V_2 ) ;
struct V_60 * V_61 = V_6 -> V_2 . V_62 ;
if ( V_59 )
return V_59 -> V_11 ;
if ( F_22 ( V_61 , L_1 , NULL ) )
return true ;
return false ;
}
static int F_23 ( struct V_5 * V_6 ,
const struct V_63 * V_64 )
{
struct V_65 * V_66 = V_6 -> V_66 ;
struct V_3 * V_4 ;
struct V_1 * V_67 ;
if ( ! F_24 ( V_66 , V_68 ) )
return - V_69 ;
V_4 = F_25 ( & V_6 -> V_2 , sizeof( * V_4 ) , V_70 ) ;
if ( ! V_4 )
return - V_71 ;
V_4 -> V_6 = V_6 ;
F_26 ( & V_4 -> V_22 ) ;
V_4 -> V_11 = F_20 ( V_6 ) ;
F_5 ( V_6 , V_45 , 0x00 ) ;
F_5 ( V_6 , V_50 , 0x00 ) ;
V_67 = F_27 ( & V_6 -> V_2 ,
V_6 -> V_72 , V_4 ,
& V_73 ,
NULL ) ;
return F_28 ( V_67 ) ;
}
