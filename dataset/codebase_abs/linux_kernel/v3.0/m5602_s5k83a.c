int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
T_1 V_4 = 0 , V_5 = 0 ;
int V_6 , V_7 = 0 ;
if ( V_8 ) {
if ( V_8 == V_9 ) {
F_2 ( L_1 , V_10 . V_11 ) ;
goto V_12;
}
return - V_13 ;
}
F_3 ( V_14 , L_2 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_15 ) && ! V_7 ; V_6 ++ ) {
T_1 V_16 [ 2 ] = { V_15 [ V_6 ] [ 2 ] , V_15 [ V_6 ] [ 3 ] } ;
if ( V_15 [ V_6 ] [ 0 ] == V_17 )
V_7 = F_5 ( V_1 , V_15 [ V_6 ] [ 1 ] ,
V_16 , 2 ) ;
else
V_7 = F_6 ( V_1 , V_15 [ V_6 ] [ 1 ] ,
V_16 [ 0 ] ) ;
}
if ( F_7 ( V_1 , 0x00 , & V_4 , 1 ) )
return - V_13 ;
if ( F_7 ( V_1 , 0x01 , & V_5 , 1 ) )
return - V_13 ;
if ( ( V_4 == 0xff ) || ( V_5 == 0xff ) )
return - V_13 ;
else
F_2 ( L_3 ) ;
V_12:
V_3 = F_8 (
sizeof( struct V_2 ) , V_18 ) ;
if ( ! V_3 )
return - V_19 ;
V_3 -> V_20 =
F_8 ( sizeof( V_21 ) * F_4 ( V_22 ) , V_18 ) ;
if ( ! V_3 -> V_20 ) {
F_9 ( V_3 ) ;
return - V_19 ;
}
V_1 -> V_23 . V_24 . V_25 = V_26 ;
V_1 -> V_23 . V_24 . V_27 = F_4 ( V_26 ) ;
V_1 -> V_28 -> V_29 = V_22 ;
V_1 -> V_28 -> V_30 = F_4 ( V_22 ) ;
V_3 -> V_31 = NULL ;
for ( V_6 = 0 ; V_6 < F_4 ( V_22 ) ; V_6 ++ )
V_3 -> V_20 [ V_6 ] = V_22 [ V_6 ] . V_32 . V_33 ;
V_1 -> V_34 = V_3 ;
return 0 ;
}
int F_10 ( struct V_1 * V_1 )
{
int V_6 , V_7 = 0 ;
V_21 * V_35 =
( (struct V_2 * ) V_1 -> V_34 ) -> V_20 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_36 ) && ! V_7 ; V_6 ++ ) {
T_1 V_16 [ 2 ] = { 0x00 , 0x00 } ;
switch ( V_36 [ V_6 ] [ 0 ] ) {
case V_37 :
V_7 = F_6 ( V_1 ,
V_36 [ V_6 ] [ 1 ] ,
V_36 [ V_6 ] [ 2 ] ) ;
break;
case V_17 :
V_16 [ 0 ] = V_36 [ V_6 ] [ 2 ] ;
V_7 = F_5 ( V_1 ,
V_36 [ V_6 ] [ 1 ] , V_16 , 1 ) ;
break;
case V_38 :
V_16 [ 0 ] = V_36 [ V_6 ] [ 2 ] ;
V_16 [ 1 ] = V_36 [ V_6 ] [ 3 ] ;
V_7 = F_5 ( V_1 ,
V_36 [ V_6 ] [ 1 ] , V_16 , 2 ) ;
break;
default:
F_2 ( L_4 ) ;
return - V_39 ;
}
}
if ( V_40 )
F_11 ( V_1 ) ;
V_7 = F_12 ( & V_1 -> V_23 , V_35 [ V_41 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( & V_1 -> V_23 ,
V_35 [ V_42 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_14 ( & V_1 -> V_23 ,
V_35 [ V_43 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_15 ( & V_1 -> V_23 , V_35 [ V_44 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_16 ( & V_1 -> V_23 , V_35 [ V_45 ] ) ;
return V_7 ;
}
static int F_17 ( void * V_16 )
{
struct V_1 * V_1 = (struct V_1 * ) V_16 ;
struct V_2 * V_3 = V_1 -> V_34 ;
T_1 V_46 , V_47 = 0 ;
T_2 V_48 , V_49 ;
F_18 ( V_50 ) ;
while ( ! F_19 ( 100 ) ) {
if ( F_20 ( & V_1 -> V_23 . V_51 ) )
break;
F_21 ( V_1 , & V_46 ) ;
if ( V_47 != V_46 ) {
V_47 = V_46 ;
F_2 ( L_5 ) ;
F_22 ( (struct V_23 * ) V_1 , & V_48 ) ;
F_23 ( (struct V_23 * ) V_1 , & V_49 ) ;
if ( V_46 ) {
V_48 = ! V_48 ;
V_49 = ! V_49 ;
}
F_24 ( (struct V_23 * ) V_1 ,
V_48 , V_49 ) ;
}
F_25 ( & V_1 -> V_23 . V_51 ) ;
F_18 ( V_50 ) ;
}
if ( V_47 ) {
F_22 ( (struct V_23 * ) V_1 , & V_48 ) ;
F_23 ( (struct V_23 * ) V_1 , & V_49 ) ;
F_24 ( (struct V_23 * ) V_1 , V_48 , V_49 ) ;
}
V_3 -> V_31 = NULL ;
return 0 ;
}
int F_26 ( struct V_1 * V_1 )
{
int V_6 , V_7 = 0 ;
struct V_2 * V_3 = V_1 -> V_34 ;
V_3 -> V_31 = F_27 ( F_17 ,
V_1 , L_6 ) ;
F_28 ( V_3 -> V_31 ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_52 ) && ! V_7 ; V_6 ++ ) {
T_1 V_16 [ 2 ] = { V_52 [ V_6 ] [ 2 ] , V_52 [ V_6 ] [ 3 ] } ;
if ( V_52 [ V_6 ] [ 0 ] == V_17 )
V_7 = F_5 ( V_1 , V_52 [ V_6 ] [ 1 ] ,
V_16 , 2 ) ;
else
V_7 = F_6 ( V_1 , V_52 [ V_6 ] [ 1 ] ,
V_16 [ 0 ] ) ;
}
if ( V_7 < 0 )
return V_7 ;
return F_29 ( V_1 , 1 ) ;
}
int F_30 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_34 ;
if ( V_3 -> V_31 )
F_31 ( V_3 -> V_31 ) ;
return F_29 ( V_1 , 0 ) ;
}
void F_32 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_34 ;
F_30 ( V_1 ) ;
V_1 -> V_53 = NULL ;
F_9 ( V_3 -> V_20 ) ;
F_9 ( V_3 ) ;
}
static int F_33 ( struct V_23 * V_23 , T_2 * V_54 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
struct V_2 * V_3 = V_1 -> V_34 ;
* V_54 = V_3 -> V_20 [ V_41 ] ;
return 0 ;
}
static int F_12 ( struct V_23 * V_23 , T_2 V_54 )
{
int V_7 ;
T_1 V_16 [ 2 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
struct V_2 * V_3 = V_1 -> V_34 ;
V_3 -> V_20 [ V_41 ] = V_54 ;
V_16 [ 0 ] = 0x00 ;
V_16 [ 1 ] = 0x20 ;
V_7 = F_5 ( V_1 , 0x14 , V_16 , 2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_16 [ 0 ] = 0x01 ;
V_16 [ 1 ] = 0x00 ;
V_7 = F_5 ( V_1 , 0x0d , V_16 , 2 ) ;
if ( V_7 < 0 )
return V_7 ;
V_16 [ 0 ] = V_54 >> 3 ;
V_16 [ 1 ] = V_54 >> 1 ;
V_7 = F_5 ( V_1 , V_55 , V_16 , 2 ) ;
return V_7 ;
}
static int F_34 ( struct V_23 * V_23 , T_2 * V_54 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
struct V_2 * V_3 = V_1 -> V_34 ;
* V_54 = V_3 -> V_20 [ V_42 ] ;
return 0 ;
}
static int F_13 ( struct V_23 * V_23 , T_2 V_54 )
{
int V_7 ;
T_1 V_16 [ 1 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
struct V_2 * V_3 = V_1 -> V_34 ;
V_3 -> V_20 [ V_42 ] = V_54 ;
V_16 [ 0 ] = V_54 ;
V_7 = F_5 ( V_1 , V_56 , V_16 , 1 ) ;
return V_7 ;
}
static int F_35 ( struct V_23 * V_23 , T_2 * V_54 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
struct V_2 * V_3 = V_1 -> V_34 ;
* V_54 = V_3 -> V_20 [ V_43 ] ;
return 0 ;
}
static int F_14 ( struct V_23 * V_23 , T_2 V_54 )
{
int V_7 ;
T_1 V_16 [ 2 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
struct V_2 * V_3 = V_1 -> V_34 ;
V_3 -> V_20 [ V_43 ] = V_54 ;
V_16 [ 0 ] = 0 ;
V_16 [ 1 ] = V_54 ;
V_7 = F_5 ( V_1 , V_57 , V_16 , 2 ) ;
return V_7 ;
}
static int F_22 ( struct V_23 * V_23 , T_2 * V_54 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
struct V_2 * V_3 = V_1 -> V_34 ;
* V_54 = V_3 -> V_20 [ V_45 ] ;
return 0 ;
}
static int F_24 ( struct V_23 * V_23 ,
T_2 V_48 , T_2 V_49 )
{
int V_7 ;
T_1 V_16 [ 1 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
V_16 [ 0 ] = 0x05 ;
V_7 = F_5 ( V_1 , V_58 , V_16 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_16 [ 0 ] = V_59 ;
V_16 [ 0 ] = ( V_48 ) ? V_16 [ 0 ] | 0x40 : V_16 [ 0 ] ;
V_16 [ 0 ] = ( V_49 ) ? V_16 [ 0 ] | 0x80 : V_16 [ 0 ] ;
V_7 = F_5 ( V_1 , V_60 , V_16 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_16 [ 0 ] = ( V_48 ) ? 0x0b : 0x0a ;
V_7 = F_5 ( V_1 , V_61 , V_16 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_16 [ 0 ] = ( V_49 ) ? 0x0a : 0x0b ;
V_7 = F_5 ( V_1 , V_62 , V_16 , 1 ) ;
return V_7 ;
}
static int F_16 ( struct V_23 * V_23 , T_2 V_54 )
{
int V_7 ;
T_1 V_46 ;
T_2 V_49 ;
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
struct V_2 * V_3 = V_1 -> V_34 ;
V_3 -> V_20 [ V_45 ] = V_54 ;
F_23 ( V_23 , & V_49 ) ;
V_7 = F_21 ( V_1 , & V_46 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_46 ) {
V_54 = ! V_54 ;
V_49 = ! V_49 ;
}
V_7 = F_24 ( V_23 , V_54 , V_49 ) ;
return V_7 ;
}
static int F_23 ( struct V_23 * V_23 , T_2 * V_54 )
{
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
struct V_2 * V_3 = V_1 -> V_34 ;
* V_54 = V_3 -> V_20 [ V_44 ] ;
return 0 ;
}
static int F_15 ( struct V_23 * V_23 , T_2 V_54 )
{
int V_7 ;
T_1 V_46 ;
T_2 V_48 ;
struct V_1 * V_1 = (struct V_1 * ) V_23 ;
struct V_2 * V_3 = V_1 -> V_34 ;
V_3 -> V_20 [ V_44 ] = V_54 ;
F_22 ( V_23 , & V_48 ) ;
V_7 = F_21 ( V_1 , & V_46 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_46 ) {
V_54 = ! V_54 ;
V_48 = ! V_48 ;
}
V_7 = F_24 ( V_23 , V_48 , V_54 ) ;
return V_7 ;
}
static int F_29 ( struct V_1 * V_1 , T_1 V_54 )
{
int V_7 = 0 ;
T_1 V_16 [ 1 ] ;
V_7 = F_36 ( V_1 , V_63 , V_16 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_54 )
V_16 [ 0 ] = V_16 [ 0 ] | V_64 ;
else
V_16 [ 0 ] = V_16 [ 0 ] & ~ V_64 ;
V_7 = F_6 ( V_1 , V_63 , V_16 [ 0 ] ) ;
return V_7 ;
}
static int F_21 ( struct V_1 * V_1 , T_1 * V_65 )
{
int V_7 = F_36 ( V_1 , V_63 , V_65 ) ;
* V_65 = ( * V_65 & V_66 ) ? 0 : 1 ;
return V_7 ;
}
static void F_11 ( struct V_1 * V_1 )
{
int V_67 ;
T_1 V_68 , V_69 ;
F_7 ( V_1 , V_58 , & V_69 , 1 ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ ) {
F_5 ( V_1 , V_58 , & V_68 , 1 ) ;
F_2 ( L_7 , V_68 ) ;
for ( V_67 = 0 ; V_67 <= 0xff ; V_67 ++ ) {
T_1 V_54 = 0 ;
F_7 ( V_1 , V_67 , & V_54 , 1 ) ;
F_2 ( L_8 ,
V_67 , V_54 ) ;
}
}
F_2 ( L_9 ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ ) {
F_5 ( V_1 , V_58 , & V_68 , 1 ) ;
F_2 ( L_10
L_11 , V_68 ) ;
for ( V_67 = 0 ; V_67 <= 0xff ; V_67 ++ ) {
T_1 V_70 , V_71 , V_72 = 0xff ;
F_7 ( V_1 , V_67 , & V_70 , 1 ) ;
F_5 ( V_1 , V_67 , & V_72 , 1 ) ;
F_7 ( V_1 , V_67 , & V_71 , 1 ) ;
if ( V_71 == V_72 )
F_2 ( L_12 , V_67 ) ;
else
F_2 ( L_13 , V_67 ) ;
F_5 ( V_1 , V_67 , & V_70 , 1 ) ;
}
}
F_2 ( L_14 ) ;
F_5 ( V_1 , V_58 , & V_69 , 1 ) ;
}
