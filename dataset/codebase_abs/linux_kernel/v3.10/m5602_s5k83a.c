int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 = 0 , V_3 = 0 ;
int V_4 , V_5 = 0 ;
struct V_6 * V_6 = (struct V_6 * ) V_1 ;
if ( V_7 ) {
if ( V_7 == V_8 ) {
F_2 ( L_1 , V_9 . V_10 ) ;
goto V_11;
}
return - V_12 ;
}
F_3 ( V_13 , L_2 ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_14 ) && ! V_5 ; V_4 ++ ) {
T_1 V_15 [ 2 ] = { V_14 [ V_4 ] [ 2 ] , V_14 [ V_4 ] [ 3 ] } ;
if ( V_14 [ V_4 ] [ 0 ] == V_16 )
V_5 = F_5 ( V_1 , V_14 [ V_4 ] [ 1 ] ,
V_15 , 2 ) ;
else
V_5 = F_6 ( V_1 , V_14 [ V_4 ] [ 1 ] ,
V_15 [ 0 ] ) ;
}
if ( F_7 ( V_1 , 0x00 , & V_2 , 1 ) )
return - V_12 ;
if ( F_7 ( V_1 , 0x01 , & V_3 , 1 ) )
return - V_12 ;
if ( ( V_2 == 0xff ) || ( V_3 == 0xff ) )
return - V_12 ;
else
F_2 ( L_3 ) ;
V_11:
V_1 -> V_6 . V_17 . V_18 = V_19 ;
V_1 -> V_6 . V_17 . V_20 = F_4 ( V_19 ) ;
V_1 -> V_21 = NULL ;
return 0 ;
}
int F_8 ( struct V_1 * V_1 )
{
int V_4 , V_5 = 0 ;
for ( V_4 = 0 ; V_4 < F_4 ( V_22 ) && ! V_5 ; V_4 ++ ) {
T_1 V_15 [ 2 ] = { 0x00 , 0x00 } ;
switch ( V_22 [ V_4 ] [ 0 ] ) {
case V_23 :
V_5 = F_6 ( V_1 ,
V_22 [ V_4 ] [ 1 ] ,
V_22 [ V_4 ] [ 2 ] ) ;
break;
case V_16 :
V_15 [ 0 ] = V_22 [ V_4 ] [ 2 ] ;
V_5 = F_5 ( V_1 ,
V_22 [ V_4 ] [ 1 ] , V_15 , 1 ) ;
break;
case V_24 :
V_15 [ 0 ] = V_22 [ V_4 ] [ 2 ] ;
V_15 [ 1 ] = V_22 [ V_4 ] [ 3 ] ;
V_5 = F_5 ( V_1 ,
V_22 [ V_4 ] [ 1 ] , V_15 , 2 ) ;
break;
default:
F_2 ( L_4 ) ;
return - V_25 ;
}
}
if ( V_26 )
F_9 ( V_1 ) ;
return V_5 ;
}
int F_10 ( struct V_1 * V_1 )
{
struct V_27 * V_28 = & V_1 -> V_6 . V_29 ;
V_1 -> V_6 . V_30 . V_29 = V_28 ;
F_11 ( V_28 , 6 ) ;
F_12 ( V_28 , & V_31 , V_32 ,
0 , 255 , 1 , V_33 ) ;
F_12 ( V_28 , & V_31 , V_34 ,
0 , V_35 , 1 ,
V_36 ) ;
F_12 ( V_28 , & V_31 , V_37 ,
0 , 255 , 1 , V_38 ) ;
V_1 -> V_39 = F_12 ( V_28 , & V_31 , V_40 ,
0 , 1 , 1 , 0 ) ;
V_1 -> V_41 = F_12 ( V_28 , & V_31 , V_42 ,
0 , 1 , 1 , 0 ) ;
if ( V_28 -> error ) {
F_13 ( L_5 ) ;
return V_28 -> error ;
}
F_14 ( 2 , & V_1 -> V_39 ) ;
return 0 ;
}
static int F_15 ( void * V_15 )
{
struct V_1 * V_1 = (struct V_1 * ) V_15 ;
T_1 V_43 , V_44 = 0 ;
T_2 V_41 , V_39 ;
F_16 ( V_45 ) ;
while ( ! F_17 ( 100 ) ) {
if ( F_18 ( & V_1 -> V_6 . V_46 ) )
break;
F_19 ( V_1 , & V_43 ) ;
if ( V_44 != V_43 ) {
V_44 = V_43 ;
F_2 ( L_6 ) ;
V_39 = V_1 -> V_39 -> V_47 ;
V_41 = V_1 -> V_41 -> V_47 ;
if ( V_43 ) {
V_41 = ! V_41 ;
V_39 = ! V_39 ;
}
F_20 ( (struct V_6 * ) V_1 ,
V_41 , V_39 ) ;
}
F_21 ( & V_1 -> V_6 . V_46 ) ;
F_16 ( V_45 ) ;
}
if ( V_44 ) {
V_39 = V_1 -> V_39 -> V_47 ;
V_41 = V_1 -> V_41 -> V_47 ;
F_20 ( (struct V_6 * ) V_1 , V_41 , V_39 ) ;
}
V_1 -> V_21 = NULL ;
return 0 ;
}
int F_22 ( struct V_1 * V_1 )
{
int V_4 , V_5 = 0 ;
V_1 -> V_21 = F_23 ( F_15 ,
V_1 , L_7 ) ;
F_24 ( V_1 -> V_21 ) ;
for ( V_4 = 0 ; V_4 < F_4 ( V_48 ) && ! V_5 ; V_4 ++ ) {
T_1 V_15 [ 2 ] = { V_48 [ V_4 ] [ 2 ] , V_48 [ V_4 ] [ 3 ] } ;
if ( V_48 [ V_4 ] [ 0 ] == V_16 )
V_5 = F_5 ( V_1 , V_48 [ V_4 ] [ 1 ] ,
V_15 , 2 ) ;
else
V_5 = F_6 ( V_1 , V_48 [ V_4 ] [ 1 ] ,
V_15 [ 0 ] ) ;
}
if ( V_5 < 0 )
return V_5 ;
return F_25 ( V_1 , 1 ) ;
}
int F_26 ( struct V_1 * V_1 )
{
if ( V_1 -> V_21 )
F_27 ( V_1 -> V_21 ) ;
return F_25 ( V_1 , 0 ) ;
}
void F_28 ( struct V_1 * V_1 )
{
F_26 ( V_1 ) ;
V_1 -> V_49 = NULL ;
}
static int F_29 ( struct V_6 * V_6 , T_2 V_47 )
{
int V_5 ;
T_1 V_15 [ 2 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
V_15 [ 0 ] = 0x00 ;
V_15 [ 1 ] = 0x20 ;
V_5 = F_5 ( V_1 , 0x14 , V_15 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_15 [ 0 ] = 0x01 ;
V_15 [ 1 ] = 0x00 ;
V_5 = F_5 ( V_1 , 0x0d , V_15 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_15 [ 0 ] = V_47 >> 3 ;
V_15 [ 1 ] = V_47 >> 1 ;
V_5 = F_5 ( V_1 , V_50 , V_15 , 2 ) ;
return V_5 ;
}
static int F_30 ( struct V_6 * V_6 , T_2 V_47 )
{
int V_5 ;
T_1 V_15 [ 1 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
V_15 [ 0 ] = V_47 ;
V_5 = F_5 ( V_1 , V_51 , V_15 , 1 ) ;
return V_5 ;
}
static int F_31 ( struct V_6 * V_6 , T_2 V_47 )
{
int V_5 ;
T_1 V_15 [ 2 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
V_15 [ 0 ] = 0 ;
V_15 [ 1 ] = V_47 ;
V_5 = F_5 ( V_1 , V_52 , V_15 , 2 ) ;
return V_5 ;
}
static int F_20 ( struct V_6 * V_6 ,
T_2 V_41 , T_2 V_39 )
{
int V_5 ;
T_1 V_15 [ 1 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
V_15 [ 0 ] = 0x05 ;
V_5 = F_5 ( V_1 , V_53 , V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_15 [ 0 ] = V_54 ;
V_15 [ 0 ] = ( V_41 ) ? V_15 [ 0 ] | 0x40 : V_15 [ 0 ] ;
V_15 [ 0 ] = ( V_39 ) ? V_15 [ 0 ] | 0x80 : V_15 [ 0 ] ;
V_5 = F_5 ( V_1 , V_55 , V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_15 [ 0 ] = ( V_41 ) ? 0x0b : 0x0a ;
V_5 = F_5 ( V_1 , V_56 , V_15 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_15 [ 0 ] = ( V_39 ) ? 0x0a : 0x0b ;
V_5 = F_5 ( V_1 , V_57 , V_15 , 1 ) ;
return V_5 ;
}
static int F_32 ( struct V_6 * V_6 )
{
int V_5 ;
T_1 V_43 ;
struct V_1 * V_1 = (struct V_1 * ) V_6 ;
int V_39 = V_1 -> V_39 -> V_47 ;
int V_41 = V_1 -> V_41 -> V_47 ;
V_5 = F_19 ( V_1 , & V_43 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_43 ) {
V_39 = ! V_39 ;
V_41 = ! V_41 ;
}
V_5 = F_20 ( V_6 , V_41 , V_39 ) ;
return V_5 ;
}
static int F_33 ( struct V_58 * V_59 )
{
struct V_6 * V_6 =
F_34 ( V_59 -> V_60 , struct V_6 , V_29 ) ;
int V_5 ;
if ( ! V_6 -> V_61 )
return 0 ;
switch ( V_59 -> V_62 ) {
case V_32 :
V_5 = F_30 ( V_6 , V_59 -> V_47 ) ;
break;
case V_34 :
V_5 = F_31 ( V_6 , V_59 -> V_47 ) ;
break;
case V_37 :
V_5 = F_29 ( V_6 , V_59 -> V_47 ) ;
break;
case V_40 :
V_5 = F_32 ( V_6 ) ;
break;
default:
return - V_25 ;
}
return V_5 ;
}
static int F_25 ( struct V_1 * V_1 , T_1 V_47 )
{
int V_5 = 0 ;
T_1 V_15 [ 1 ] ;
V_5 = F_35 ( V_1 , V_63 , V_15 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_47 )
V_15 [ 0 ] = V_15 [ 0 ] | V_64 ;
else
V_15 [ 0 ] = V_15 [ 0 ] & ~ V_64 ;
V_5 = F_6 ( V_1 , V_63 , V_15 [ 0 ] ) ;
return V_5 ;
}
static int F_19 ( struct V_1 * V_1 , T_1 * V_65 )
{
int V_5 = F_35 ( V_1 , V_63 , V_65 ) ;
* V_65 = ( * V_65 & V_66 ) ? 0 : 1 ;
return V_5 ;
}
static void F_9 ( struct V_1 * V_1 )
{
int V_67 ;
T_1 V_68 , V_69 ;
F_7 ( V_1 , V_53 , & V_69 , 1 ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ ) {
F_5 ( V_1 , V_53 , & V_68 , 1 ) ;
F_2 ( L_8 ,
V_68 ) ;
for ( V_67 = 0 ; V_67 <= 0xff ; V_67 ++ ) {
T_1 V_47 = 0 ;
F_7 ( V_1 , V_67 , & V_47 , 1 ) ;
F_2 ( L_9 , V_67 , V_47 ) ;
}
}
F_2 ( L_10 ) ;
for ( V_68 = 0 ; V_68 < 16 ; V_68 ++ ) {
F_5 ( V_1 , V_53 , & V_68 , 1 ) ;
F_2 ( L_11 ,
V_68 ) ;
for ( V_67 = 0 ; V_67 <= 0xff ; V_67 ++ ) {
T_1 V_70 , V_71 , V_72 = 0xff ;
F_7 ( V_1 , V_67 , & V_70 , 1 ) ;
F_5 ( V_1 , V_67 , & V_72 , 1 ) ;
F_7 ( V_1 , V_67 , & V_71 , 1 ) ;
if ( V_71 == V_72 )
F_2 ( L_12 ,
V_67 ) ;
else
F_2 ( L_13 ,
V_67 ) ;
F_5 ( V_1 , V_67 , & V_70 , 1 ) ;
}
}
F_2 ( L_14 ) ;
F_5 ( V_1 , V_53 , & V_69 , 1 ) ;
}
