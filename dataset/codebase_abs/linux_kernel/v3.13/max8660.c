static int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
static const T_1 V_5 [ V_6 ] =
{ 0x10 , 0x12 , 0x20 , 0x23 , 0x24 , 0x29 , 0x2a , 0x32 , 0x33 , 0x39 , 0x80 } ;
int V_7 ;
T_1 V_8 = ( V_1 -> V_9 [ V_2 ] & V_3 ) | V_4 ;
F_2 ( & V_1 -> V_10 -> V_11 , L_1 ,
V_5 [ V_2 ] , V_8 ) ;
V_7 = F_3 ( V_1 -> V_10 ,
V_5 [ V_2 ] , V_8 ) ;
if ( V_7 == 0 )
V_1 -> V_9 [ V_2 ] = V_8 ;
return V_7 ;
}
static int F_4 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_4 = V_1 -> V_9 [ V_14 ] ;
T_1 V_3 = ( F_6 ( V_13 ) == V_15 ) ? 1 : 4 ;
return ! ! ( V_4 & V_3 ) ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_16 = ( F_6 ( V_13 ) == V_15 ) ? 1 : 4 ;
return F_1 ( V_1 , V_14 , 0xff , V_16 ) ;
}
static int F_8 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_3 = ( F_6 ( V_13 ) == V_15 ) ? ~ 1 : ~ 4 ;
return F_1 ( V_1 , V_14 , V_3 , 0 ) ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_2 = ( F_6 ( V_13 ) == V_15 ) ? V_17 : V_18 ;
T_1 V_19 = V_1 -> V_9 [ V_2 ] ;
return V_19 ;
}
static int F_10 ( struct V_12 * V_13 ,
unsigned int V_19 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_2 , V_20 ;
int V_7 ;
V_2 = ( F_6 ( V_13 ) == V_15 ) ? V_17 : V_18 ;
V_7 = F_1 ( V_1 , V_2 , 0 , V_19 ) ;
if ( V_7 )
return V_7 ;
V_20 = ( F_6 ( V_13 ) == V_15 ) ? 0x03 : 0x30 ;
return F_1 ( V_1 , V_21 , 0xff , V_20 ) ;
}
static int F_11 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_19 = V_1 -> V_9 [ V_22 ] ;
return V_19 ;
}
static int F_12 ( struct V_12 * V_13 ,
unsigned int V_19 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
int V_7 ;
V_7 = F_1 ( V_1 , V_22 , 0 , V_19 ) ;
if ( V_7 )
return V_7 ;
return F_1 ( V_1 , V_21 , 0xff , 0xc0 ) ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_4 = V_1 -> V_9 [ V_23 ] ;
T_1 V_3 = ( F_6 ( V_13 ) == V_24 ) ? 2 : 4 ;
return ! ! ( V_4 & V_3 ) ;
}
static int F_14 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_16 = ( F_6 ( V_13 ) == V_24 ) ? 2 : 4 ;
return F_1 ( V_1 , V_23 , 0xff , V_16 ) ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_3 = ( F_6 ( V_13 ) == V_24 ) ? ~ 2 : ~ 4 ;
return F_1 ( V_1 , V_23 , V_3 , 0 ) ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
T_1 V_25 = ( F_6 ( V_13 ) == V_24 ) ? 0 : 4 ;
T_1 V_19 = ( V_1 -> V_9 [ V_26 ] >> V_25 ) & 0xf ;
return V_19 ;
}
static int F_17 ( struct V_12 * V_13 ,
unsigned int V_19 )
{
struct V_1 * V_1 = F_5 ( V_13 ) ;
if ( F_6 ( V_13 ) == V_24 )
return F_1 ( V_1 , V_26 , 0xf0 , V_19 ) ;
else
return F_1 ( V_1 , V_26 , 0x0f ,
V_19 << 4 ) ;
}
static int F_18 ( struct V_27 * V_11 ,
struct V_28 * * V_29 ,
struct V_30 * V_31 )
{
int V_32 , V_33 ;
struct V_28 * V_34 ;
struct V_35 * V_36 ;
struct V_37 V_38 [ F_19 ( V_39 ) ] ;
V_34 = F_20 ( V_11 -> V_29 , L_2 ) ;
if ( ! V_34 ) {
F_21 ( V_11 , L_3 ) ;
return - V_40 ;
}
for ( V_33 = 0 ; V_33 < F_19 ( V_38 ) ; V_33 ++ )
V_38 [ V_33 ] . V_41 = V_39 [ V_33 ] . V_41 ;
V_32 = V_37 ( V_11 , V_34 , V_38 , F_19 ( V_38 ) ) ;
if ( V_32 <= 0 )
return V_32 ;
V_31 -> V_42 = F_22 ( V_11 , sizeof( struct V_35 ) *
V_32 , V_43 ) ;
if ( ! V_31 -> V_42 )
return - V_44 ;
V_31 -> V_45 = V_32 ;
V_36 = V_31 -> V_42 ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ ) {
V_36 -> V_46 = V_33 ;
V_36 -> V_41 = V_38 [ V_33 ] . V_41 ;
V_36 -> V_47 = V_38 [ V_33 ] . V_48 ;
V_29 [ V_33 ] = V_38 [ V_33 ] . V_29 ;
V_36 ++ ;
}
return 0 ;
}
static inline int F_18 ( struct V_27 * V_11 ,
struct V_28 * * V_29 ,
struct V_30 * V_31 )
{
return 0 ;
}
static int F_23 ( struct V_49 * V_10 ,
const struct V_50 * V_51 )
{
struct V_12 * * V_13 ;
struct V_27 * V_11 = & V_10 -> V_11 ;
struct V_30 * V_31 = F_24 ( V_11 ) ;
struct V_52 V_53 = { } ;
struct V_1 * V_1 ;
int V_54 , V_33 , V_46 , V_7 = - V_40 ;
struct V_28 * V_29 [ V_55 ] ;
unsigned long type ;
if ( V_11 -> V_29 && ! V_31 ) {
const struct V_56 * V_46 ;
struct V_30 V_57 ;
V_46 = F_25 ( F_26 ( V_58 ) , V_11 ) ;
if ( ! V_46 )
return - V_59 ;
V_7 = F_18 ( V_11 , V_29 , & V_57 ) ;
if ( V_7 < 0 )
return V_7 ;
V_31 = & V_57 ;
type = ( unsigned long ) V_46 -> V_60 ;
} else {
type = V_51 -> V_61 ;
memset ( V_29 , 0 , sizeof( V_29 ) ) ;
}
if ( V_31 -> V_45 > V_55 ) {
F_21 ( V_11 , L_4 ) ;
return - V_40 ;
}
V_1 = F_22 ( V_11 , sizeof( struct V_1 ) +
sizeof( struct V_12 * ) * V_55 ,
V_43 ) ;
if ( ! V_1 )
return - V_44 ;
V_1 -> V_10 = V_10 ;
V_13 = V_1 -> V_13 ;
if ( V_31 -> V_62 ) {
V_1 -> V_9 [ V_14 ] = 5 ;
} else {
V_63 . V_64 = F_7 ;
V_63 . V_65 = F_8 ;
}
V_1 -> V_9 [ V_66 ] =
V_1 -> V_9 [ V_17 ] =
V_1 -> V_9 [ V_67 ] =
V_1 -> V_9 [ V_18 ] = 0x1b ;
V_1 -> V_9 [ V_68 ] =
V_1 -> V_9 [ V_22 ] = 0x04 ;
for ( V_33 = 0 ; V_33 < V_31 -> V_45 ; V_33 ++ ) {
if ( ! V_31 -> V_42 [ V_33 ] . V_47 )
return V_7 ;
V_54 = V_31 -> V_42 [ V_33 ] . V_47 -> V_69 . V_54 ;
switch ( V_31 -> V_42 [ V_33 ] . V_46 ) {
case V_15 :
if ( V_54 )
V_1 -> V_9 [ V_14 ] |= 1 ;
break;
case V_70 :
if ( V_54 )
V_1 -> V_9 [ V_14 ] |= 4 ;
break;
case V_71 :
break;
case V_24 :
if ( V_54 )
V_1 -> V_9 [ V_23 ] |= 2 ;
break;
case V_72 :
if ( type == V_73 ) {
F_21 ( V_11 , L_5 ) ;
return - V_40 ;
}
if ( V_54 )
V_1 -> V_9 [ V_23 ] |= 4 ;
break;
default:
F_21 ( V_11 , L_6 ,
V_31 -> V_42 [ V_33 ] . V_41 ) ;
return V_7 ;
}
}
for ( V_33 = 0 ; V_33 < V_31 -> V_45 ; V_33 ++ ) {
V_46 = V_31 -> V_42 [ V_33 ] . V_46 ;
V_53 . V_11 = V_11 ;
V_53 . V_48 = V_31 -> V_42 [ V_33 ] . V_47 ;
V_53 . V_29 = V_29 [ V_33 ] ;
V_53 . V_61 = V_1 ;
V_13 [ V_33 ] = F_27 ( & V_10 -> V_11 ,
& V_39 [ V_46 ] , & V_53 ) ;
if ( F_28 ( V_13 [ V_33 ] ) ) {
V_7 = F_29 ( V_13 [ V_33 ] ) ;
F_21 ( & V_10 -> V_11 , L_7 ,
V_39 [ V_46 ] . V_41 ) ;
return F_29 ( V_13 [ V_33 ] ) ;
}
}
F_30 ( V_10 , V_1 ) ;
return 0 ;
}
static int T_2 F_31 ( void )
{
return F_32 ( & V_74 ) ;
}
static void T_3 F_33 ( void )
{
F_34 ( & V_74 ) ;
}
