static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int * V_5 , int * V_6 , long V_7 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
const int V_10 = V_9 -> V_11 + 2 * V_4 -> V_12 ;
unsigned int V_13 ;
unsigned int V_14 ;
unsigned int V_15 ;
int V_16 ;
switch ( V_7 ) {
case V_17 :
if ( V_4 -> type == V_18 ) {
* V_5 = ! ! ( F_3 ( V_9 -> V_11 + 0x16 ) & F_4 ( V_4 -> V_12 ) ) ;
return V_19 ;
}
V_13 = F_3 ( V_10 + 1 ) ;
V_14 = V_13 & F_4 ( 0 ) ;
V_15 = ! ! ( V_13 & F_4 ( 1 ) ) ;
* V_5 = ( V_14 ^ V_15 ) << 24 ;
F_5 ( 0x11 , V_10 + 1 ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
* V_5 |= ( unsigned int ) F_3 ( V_10 ) << ( 8 * V_16 ) ;
return V_19 ;
case V_20 :
* V_5 = V_9 -> V_21 [ V_4 -> V_12 ] ;
return V_19 ;
case V_22 :
* V_5 = 1 ;
* V_6 = V_9 -> V_23 [ V_4 -> V_12 ] ;
return V_24 ;
}
return - V_25 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 const * V_4 , int V_5 , int V_6 , long V_7 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
const int V_10 = V_9 -> V_11 + 2 * V_4 -> V_12 ;
int V_16 ;
unsigned int V_26 ;
switch ( V_7 ) {
case V_17 :
if ( V_4 -> type == V_18 )
return - V_25 ;
if ( ( unsigned int ) V_5 > 0xFFFFFF )
return - V_25 ;
F_5 ( 0x01 , V_10 + 1 ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_5 ( V_5 >> ( 8 * V_16 ) , V_10 ) ;
F_5 ( 0x08 , V_10 + 1 ) ;
F_5 ( 0x01 , V_10 + 1 ) ;
V_5 = V_9 -> V_27 [ V_4 -> V_12 ] ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_5 ( V_5 >> ( 8 * V_16 ) , V_10 ) ;
F_5 ( 0x02 , V_10 + 1 ) ;
F_5 ( 0x06 , V_10 + 1 ) ;
return 0 ;
case V_20 :
if ( V_5 < 0 || V_5 > 1 )
return - V_25 ;
V_9 -> V_21 [ V_4 -> V_12 ] = V_5 ;
V_26 = V_5 | V_9 -> V_28 [ V_4 -> V_12 ] << 1 ;
F_5 ( 0x40 | V_26 , V_10 + 1 ) ;
return 0 ;
case V_22 :
if ( ! V_9 -> V_29 [ V_4 -> V_12 ] && ( V_6 || V_5 != 1 ) )
return - V_25 ;
if ( V_5 == 1 && ! V_6 )
V_9 -> V_23 [ V_4 -> V_12 ] = 0 ;
else if ( ! V_5 )
switch ( V_6 ) {
case 500000 :
V_9 -> V_23 [ V_4 -> V_12 ] = 1 ;
break;
case 250000 :
V_9 -> V_23 [ V_4 -> V_12 ] = 2 ;
break;
default:
return - V_25 ;
}
else
return - V_25 ;
return 0 ;
}
return - V_25 ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_2 V_30 ,
const struct V_3 * V_4 , char * V_31 )
{
const struct V_8 * const V_9 = F_2 ( V_2 ) ;
return snprintf ( V_31 , V_32 , L_1 , V_9 -> V_27 [ V_4 -> V_12 ] ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_2 V_30 ,
const struct V_3 * V_4 , const char * V_31 , T_3 V_33 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
const int V_10 = V_9 -> V_11 + 2 * V_4 -> V_12 ;
unsigned int V_27 ;
int V_34 ;
int V_16 ;
V_34 = F_9 ( V_31 , 0 , & V_27 ) ;
if ( V_34 )
return V_34 ;
if ( V_27 > 0xFFFFFF )
return - V_25 ;
V_9 -> V_27 [ V_4 -> V_12 ] = V_27 ;
F_5 ( 0x01 , V_10 + 1 ) ;
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ )
F_5 ( V_27 >> ( 8 * V_16 ) , V_10 ) ;
return V_33 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
T_2 V_30 , const struct V_3 * V_4 , char * V_31 )
{
const struct V_8 * const V_9 = F_2 ( V_2 ) ;
return snprintf ( V_31 , V_32 , L_1 ,
! V_9 -> V_28 [ V_4 -> V_12 ] ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
T_2 V_30 , const struct V_3 * V_4 , const char * V_31 ,
T_3 V_33 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
const int V_10 = V_9 -> V_11 + 2 * V_4 -> V_12 + 1 ;
bool V_28 ;
int V_34 ;
unsigned int V_26 ;
V_34 = F_12 ( V_31 , & V_28 ) ;
if ( V_34 )
return V_34 ;
V_28 = ! V_28 ;
V_9 -> V_28 [ V_4 -> V_12 ] = V_28 ;
V_26 = V_9 -> V_21 [ V_4 -> V_12 ] |
( unsigned int ) V_28 << 1 ;
F_5 ( 0x40 | V_26 , V_10 ) ;
return V_33 ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
const int V_10 = V_9 -> V_11 + 2 * V_4 -> V_12 + 1 ;
return ! ! ( F_3 ( V_10 ) & F_4 ( 4 ) ) ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
const int V_10 = V_9 -> V_11 + 2 * V_4 -> V_12 + 1 ;
return ! ! ( F_3 ( V_10 ) & F_4 ( 5 ) ) ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , unsigned int V_35 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
unsigned int V_36 = V_35 << 1 ;
const int V_10 = V_9 -> V_11 + 2 * V_4 -> V_12 + 1 ;
V_9 -> V_35 [ V_4 -> V_12 ] = V_35 ;
if ( V_9 -> V_29 [ V_4 -> V_12 ] )
V_36 |= ( V_9 -> V_23 [ V_4 -> V_12 ] + 1 ) << 3 ;
F_5 ( 0x20 | V_36 , V_10 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_8 * const V_9 = F_2 ( V_2 ) ;
return V_9 -> V_35 [ V_4 -> V_12 ] ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , unsigned int V_37 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
const unsigned int V_38 = V_37 |
V_9 -> V_39 [ V_4 -> V_12 ] << 1 ;
const int V_10 = V_9 -> V_11 + 2 * V_4 -> V_12 + 1 ;
if ( V_37 && ! V_9 -> V_29 [ V_4 -> V_12 ] )
return - V_25 ;
V_9 -> V_37 [ V_4 -> V_12 ] = V_37 ;
F_5 ( 0x60 | V_38 , V_10 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_8 * const V_9 = F_2 ( V_2 ) ;
return V_9 -> V_37 [ V_4 -> V_12 ] ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , unsigned int V_29 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
unsigned int V_36 = V_9 -> V_35 [ V_4 -> V_12 ] << 1 ;
const int V_10 = V_9 -> V_11 + 2 * V_4 -> V_12 + 1 ;
if ( V_29 )
V_36 |= ( V_9 -> V_23 [ V_4 -> V_12 ] + 1 ) << 3 ;
else {
V_9 -> V_23 [ V_4 -> V_12 ] = 0 ;
if ( V_9 -> V_37 [ V_4 -> V_12 ] )
F_17 ( V_2 , V_4 , 0 ) ;
}
V_9 -> V_29 [ V_4 -> V_12 ] = V_29 ;
F_5 ( 0x20 | V_36 , V_10 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_8 * const V_9 = F_2 ( V_2 ) ;
return V_9 -> V_29 [ V_4 -> V_12 ] ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , unsigned int V_39 )
{
struct V_8 * const V_9 = F_2 ( V_2 ) ;
const unsigned int V_38 = V_9 -> V_37 [ V_4 -> V_12 ] |
V_39 << 1 ;
const int V_10 = V_9 -> V_11 + 2 * V_4 -> V_12 + 1 ;
V_9 -> V_39 [ V_4 -> V_12 ] = V_39 ;
F_5 ( 0x60 | V_38 , V_10 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_8 * const V_9 = F_2 ( V_2 ) ;
return V_9 -> V_39 [ V_4 -> V_12 ] ;
}
static int F_23 ( struct V_40 * V_41 , unsigned int V_42 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_16 , V_43 ;
unsigned int V_10 ;
V_2 = F_24 ( V_41 , sizeof( * V_9 ) ) ;
if ( ! V_2 )
return - V_44 ;
if ( ! F_25 ( V_41 , V_11 [ V_42 ] , V_45 ,
F_26 ( V_41 ) ) ) {
F_27 ( V_41 , L_2 ,
V_11 [ V_42 ] , V_11 [ V_42 ] + V_45 ) ;
return - V_46 ;
}
V_2 -> V_47 = & V_48 ;
V_2 -> V_49 = V_50 ;
V_2 -> V_51 = F_28 ( V_52 ) ;
V_2 -> V_53 = V_52 ;
V_2 -> V_54 = F_26 ( V_41 ) ;
V_2 -> V_41 . V_55 = V_41 ;
V_9 = F_2 ( V_2 ) ;
V_9 -> V_11 = V_11 [ V_42 ] ;
F_5 ( 0x01 , V_11 [ V_42 ] + 0x11 ) ;
for ( V_16 = 0 ; V_16 < V_56 ; V_16 ++ ) {
V_10 = V_11 [ V_42 ] + 2 * V_16 ;
F_5 ( 0x01 , V_10 + 1 ) ;
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ )
F_5 ( 0x00 , V_10 ) ;
F_5 ( 0x04 , V_10 + 1 ) ;
F_5 ( 0x06 , V_10 + 1 ) ;
F_5 ( 0x20 , V_10 + 1 ) ;
F_5 ( 0x40 , V_10 + 1 ) ;
F_5 ( 0x60 , V_10 + 1 ) ;
}
F_5 ( 0x00 , V_11 [ V_42 ] + 0x11 ) ;
return F_29 ( V_41 , V_2 ) ;
}
