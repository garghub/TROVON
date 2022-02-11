int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 [ 2 ] = { 0x00 , 0x00 } ;
int V_3 ;
T_2 * V_4 ;
if ( V_5 ) {
if ( V_5 == V_6 ) {
F_2 ( L_1 , V_7 . V_8 ) ;
goto V_9;
}
return - V_10 ;
}
F_3 ( V_11 , L_2 ) ;
for ( V_3 = 0 ; V_3 < F_4 ( V_12 ) ; V_3 ++ ) {
if ( V_12 [ V_3 ] [ 0 ] == V_13 ) {
F_5 ( V_1 ,
V_12 [ V_3 ] [ 1 ] ,
V_12 [ V_3 ] [ 2 ] ) ;
} else {
V_2 [ 0 ] = V_12 [ V_3 ] [ 2 ] ;
V_2 [ 1 ] = V_12 [ V_3 ] [ 3 ] ;
F_6 ( V_1 ,
V_12 [ V_3 ] [ 1 ] , V_2 , 2 ) ;
}
}
if ( F_7 ( V_1 , V_14 , V_2 , 2 ) )
return - V_10 ;
if ( ( V_2 [ 0 ] == 0x14 ) && ( V_2 [ 1 ] == 0x3a ) ) {
F_2 ( L_3 ) ;
goto V_9;
}
return - V_10 ;
V_9:
V_4 = F_8 ( F_4 ( V_15 ) * sizeof( T_2 ) ,
V_16 ) ;
if ( ! V_4 )
return - V_17 ;
V_1 -> V_18 . V_19 . V_20 = V_21 ;
V_1 -> V_18 . V_19 . V_22 = F_4 ( V_21 ) ;
V_1 -> V_23 -> V_24 = V_15 ;
V_1 -> V_23 -> V_25 = F_4 ( V_15 ) ;
for ( V_3 = 0 ; V_3 < F_4 ( V_15 ) ; V_3 ++ )
V_4 [ V_3 ] = V_15 [ V_3 ] . V_26 . V_27 ;
V_1 -> V_28 = V_4 ;
return 0 ;
}
int F_9 ( struct V_1 * V_1 )
{
int V_3 , V_29 = 0 ;
T_2 * V_4 = V_1 -> V_28 ;
for ( V_3 = 0 ; V_3 < F_4 ( V_30 ) && ! V_29 ; V_3 ++ ) {
T_1 V_2 [ 2 ] ;
if ( V_30 [ V_3 ] [ 0 ] == V_13 ) {
V_29 = F_5 ( V_1 ,
V_30 [ V_3 ] [ 1 ] ,
V_30 [ V_3 ] [ 2 ] ) ;
} else {
V_2 [ 0 ] = V_30 [ V_3 ] [ 2 ] ;
V_2 [ 1 ] = V_30 [ V_3 ] [ 3 ] ;
V_29 = F_6 ( V_1 ,
V_30 [ V_3 ] [ 1 ] , V_2 , 2 ) ;
}
}
if ( V_31 )
F_10 ( V_1 ) ;
V_29 = F_11 ( & V_1 -> V_18 , V_4 [ V_32 ] ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_12 ( & V_1 -> V_18 , V_4 [ V_33 ] ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_13 ( & V_1 -> V_18 ,
V_4 [ V_34 ] ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_14 ( & V_1 -> V_18 ,
V_4 [ V_35 ] ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_15 ( & V_1 -> V_18 ,
V_4 [ V_36 ] ) ;
if ( V_29 < 0 )
return V_29 ;
return F_16 ( & V_1 -> V_18 , V_4 [ V_37 ] ) ;
}
int F_17 ( struct V_1 * V_1 )
{
int V_3 , V_29 = 0 ;
T_1 V_2 [ 2 ] ;
struct V_19 * V_19 = & V_1 -> V_18 . V_19 ;
T_2 * V_4 = V_1 -> V_28 ;
int V_38 = V_19 -> V_20 [ V_1 -> V_18 . V_39 ] . V_38 - 1 ;
int V_40 = V_19 -> V_20 [ V_1 -> V_18 . V_39 ] . V_40 ;
for ( V_3 = 0 ; V_3 < F_4 ( V_41 ) && ! V_29 ; V_3 ++ ) {
if ( V_41 [ V_3 ] [ 0 ] == V_13 ) {
V_29 = F_5 ( V_1 ,
V_41 [ V_3 ] [ 1 ] ,
V_41 [ V_3 ] [ 2 ] ) ;
} else {
V_2 [ 0 ] = V_41 [ V_3 ] [ 2 ] ;
V_2 [ 1 ] = V_41 [ V_3 ] [ 3 ] ;
V_29 = F_6 ( V_1 ,
V_41 [ V_3 ] [ 1 ] , V_2 , 2 ) ;
}
}
if ( V_29 < 0 )
return V_29 ;
V_29 = F_5 ( V_1 , V_42 , ( V_40 >> 8 ) & 0xff ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_5 ( V_1 , V_42 , ( V_40 & 0xff ) ) ;
if ( V_29 < 0 )
return V_29 ;
for ( V_3 = 0 ; V_3 < 2 && ! V_29 ; V_3 ++ )
V_29 = F_5 ( V_1 , V_42 , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_5 ( V_1 , V_43 , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_5 ( V_1 , V_43 , 2 ) ;
if ( V_29 < 0 )
return V_29 ;
for ( V_3 = 0 ; V_3 < 2 && ! V_29 ; V_3 ++ )
V_29 = F_5 ( V_1 , V_44 , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_5 ( V_1 , V_44 ,
( V_38 >> 8 ) & 0xff ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_5 ( V_1 , V_44 , V_38 & 0xff ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_5 ( V_1 , V_43 , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
switch ( V_38 ) {
case 640 :
F_3 ( V_45 , L_4 ) ;
V_2 [ 0 ] = V_46 ;
V_2 [ 1 ] = V_47 |
V_48 |
( V_4 [ V_32 ] << 0 ) |
( V_4 [ V_33 ] << 1 ) ;
V_29 = F_6 ( V_1 ,
V_49 , V_2 , 2 ) ;
break;
case 320 :
F_3 ( V_45 , L_5 ) ;
V_2 [ 0 ] = V_46 ;
V_2 [ 1 ] = V_50 |
V_51 |
( V_4 [ V_32 ] << 0 ) |
( V_4 [ V_33 ] << 1 ) ;
V_29 = F_6 ( V_1 ,
V_49 , V_2 , 2 ) ;
break;
}
return V_29 ;
}
void F_18 ( struct V_1 * V_1 )
{
V_1 -> V_52 = NULL ;
F_19 ( V_1 -> V_28 ) ;
}
static int F_20 ( struct V_18 * V_18 , T_3 * V_53 )
{
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
* V_53 = V_4 [ V_32 ] ;
F_3 ( V_45 , L_6 , * V_53 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_18 , T_3 V_53 )
{
int V_29 ;
T_1 V_2 [ 2 ] = { 0x00 , 0x00 } ;
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
F_3 ( V_45 , L_7 , V_53 ) ;
V_4 [ V_32 ] = V_53 ;
V_53 = ! V_53 ;
V_29 = F_6 ( V_1 , V_54 , V_2 , 2 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_7 ( V_1 , V_49 , V_2 , 2 ) ;
if ( V_29 < 0 )
return V_29 ;
V_2 [ 1 ] = ( V_2 [ 1 ] & 0xfe ) | V_53 ;
V_29 = F_6 ( V_1 , V_49 ,
V_2 , 2 ) ;
return V_29 ;
}
static int F_21 ( struct V_18 * V_18 , T_3 * V_53 )
{
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
* V_53 = V_4 [ V_33 ] ;
F_3 ( V_45 , L_8 , * V_53 ) ;
return 0 ;
}
static int F_12 ( struct V_18 * V_18 , T_3 V_53 )
{
int V_29 ;
T_1 V_2 [ 2 ] = { 0x00 , 0x00 } ;
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
F_3 ( V_45 , L_9 , V_53 ) ;
V_4 [ V_33 ] = V_53 ;
V_53 = ! V_53 ;
V_29 = F_6 ( V_1 , V_54 , V_2 , 2 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_7 ( V_1 , V_49 , V_2 , 2 ) ;
if ( V_29 < 0 )
return V_29 ;
V_2 [ 1 ] = ( V_2 [ 1 ] & 0xfd ) | ( ( V_53 << 1 ) & 0x02 ) ;
V_29 = F_6 ( V_1 , V_49 ,
V_2 , 2 ) ;
return V_29 ;
}
static int F_22 ( struct V_18 * V_18 , T_3 * V_53 )
{
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
* V_53 = V_4 [ V_37 ] ;
F_3 ( V_45 , L_10 , * V_53 ) ;
return 0 ;
}
static int F_23 ( struct V_18 * V_18 ,
T_3 V_53 )
{
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
int V_29 ;
T_1 V_2 [ 2 ] ;
V_29 = F_7 ( V_1 , V_55 , V_2 , 2 ) ;
if ( V_29 < 0 )
return V_29 ;
V_4 [ V_56 ] = V_53 & 0x01 ;
V_2 [ 1 ] = ( ( V_2 [ 1 ] & 0xfd ) | ( ( V_53 & 0x01 ) << 1 ) ) ;
V_29 = F_6 ( V_1 , V_55 , V_2 , 2 ) ;
F_3 ( V_45 , L_11 , V_53 ) ;
return V_29 ;
}
static int F_24 ( struct V_18 * V_18 ,
T_3 * V_53 ) {
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
* V_53 = V_4 [ V_56 ] ;
F_3 ( V_45 , L_12 , * V_53 ) ;
return 0 ;
}
static int F_16 ( struct V_18 * V_18 , T_3 V_53 )
{
int V_29 , V_57 ;
T_1 V_2 [ 2 ] = { 0x00 , 0x00 } ;
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
V_4 [ V_37 ] = V_53 ;
V_29 = F_6 ( V_1 , V_54 , V_2 , 2 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_53 >= V_58 * 2 * 2 * 2 )
return - V_59 ;
if ( ( V_53 >= V_58 * 2 * 2 ) &&
( V_53 < ( V_58 - 1 ) * 2 * 2 * 2 ) )
V_57 = ( 1 << 10 ) | ( V_53 << 9 ) |
( V_53 << 8 ) | ( V_53 / 8 ) ;
else if ( ( V_53 >= V_58 * 2 ) &&
( V_53 < V_58 * 2 * 2 ) )
V_57 = ( 1 << 9 ) | ( 1 << 8 ) | ( V_53 / 4 ) ;
else if ( ( V_53 >= V_58 ) &&
( V_53 < V_58 * 2 ) )
V_57 = ( 1 << 8 ) | ( V_53 / 2 ) ;
else
V_57 = V_53 ;
V_2 [ 1 ] = ( V_57 & 0xff ) ;
V_2 [ 0 ] = ( V_57 & 0xff00 ) >> 8 ;
F_3 ( V_45 , L_13 , V_57 ,
V_2 [ 1 ] , V_2 [ 0 ] ) ;
V_29 = F_6 ( V_1 , V_60 ,
V_2 , 2 ) ;
return V_29 ;
}
static int F_13 ( struct V_18 * V_18 , T_3 V_53 )
{
int V_29 ;
T_1 V_2 [ 2 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
V_4 [ V_34 ] = V_53 ;
V_2 [ 1 ] = ( V_53 & 0xff ) ;
V_2 [ 0 ] = ( V_53 & 0xff00 ) >> 8 ;
F_3 ( V_45 , L_14 , V_53 ) ;
V_29 = F_6 ( V_1 , V_61 ,
V_2 , 2 ) ;
if ( V_29 < 0 )
return V_29 ;
return F_6 ( V_1 , V_62 ,
V_2 , 2 ) ;
}
static int F_25 ( struct V_18 * V_18 , T_3 * V_53 )
{
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
* V_53 = V_4 [ V_34 ] ;
F_3 ( V_45 , L_15 , * V_53 ) ;
return 0 ;
}
static int F_14 ( struct V_18 * V_18 , T_3 V_53 )
{
T_1 V_2 [ 2 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
V_4 [ V_35 ] = V_53 ;
V_2 [ 1 ] = ( V_53 & 0xff ) ;
V_2 [ 0 ] = ( V_53 & 0xff00 ) >> 8 ;
F_3 ( V_45 , L_16 , V_53 ) ;
return F_6 ( V_1 , V_63 ,
V_2 , 2 ) ;
}
static int F_26 ( struct V_18 * V_18 , T_3 * V_53 )
{
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
* V_53 = V_4 [ V_35 ] ;
F_3 ( V_45 , L_17 , * V_53 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_18 , T_3 V_53 )
{
T_1 V_2 [ 2 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
V_4 [ V_36 ] = V_53 ;
V_2 [ 1 ] = ( V_53 & 0xff ) ;
V_2 [ 0 ] = ( V_53 & 0xff00 ) >> 8 ;
F_3 ( V_45 , L_18 , V_53 ) ;
return F_6 ( V_1 , V_64 ,
V_2 , 2 ) ;
}
static int F_27 ( struct V_18 * V_18 , T_3 * V_53 )
{
struct V_1 * V_1 = (struct V_1 * ) V_18 ;
T_2 * V_4 = V_1 -> V_28 ;
* V_53 = V_4 [ V_36 ] ;
F_3 ( V_45 , L_19 , * V_53 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_1 )
{
T_1 V_65 , V_66 [ 2 ] = { 0x00 , 0x00 } ;
F_2 ( L_20 ) ;
F_2 ( L_21 ) ;
V_66 [ 1 ] = V_67 ;
F_6 ( V_1 , V_54 , V_66 , 2 ) ;
for ( V_65 = 0 ; V_65 < 0xff ; V_65 ++ ) {
F_7 ( V_1 , V_65 , V_66 , 2 ) ;
F_2 ( L_22 ,
V_65 , V_66 [ 0 ] , V_66 [ 1 ] ) ;
}
F_2 ( L_23 ) ;
V_66 [ 1 ] = V_68 ;
F_6 ( V_1 , V_54 , V_66 , 2 ) ;
for ( V_65 = 0 ; V_65 < 0xff ; V_65 ++ ) {
F_7 ( V_1 , V_65 , V_66 , 2 ) ;
F_2 ( L_22 ,
V_65 , V_66 [ 0 ] , V_66 [ 1 ] ) ;
}
F_2 ( L_24 ) ;
V_66 [ 1 ] = V_69 ;
F_6 ( V_1 , V_54 , V_66 , 2 ) ;
for ( V_65 = 0 ; V_65 < 0xff ; V_65 ++ ) {
F_7 ( V_1 , V_65 , V_66 , 2 ) ;
F_2 ( L_22 ,
V_65 , V_66 [ 0 ] , V_66 [ 1 ] ) ;
}
F_2 ( L_25 ) ;
}
