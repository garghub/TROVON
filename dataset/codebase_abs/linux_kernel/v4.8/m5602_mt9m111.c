int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 [ 2 ] = { 0x00 , 0x00 } ;
int V_3 ;
struct V_4 * V_4 = (struct V_4 * ) V_1 ;
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
V_1 -> V_4 . V_15 . V_16 = V_17 ;
V_1 -> V_4 . V_15 . V_18 = F_4 ( V_17 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_1 )
{
int V_3 , V_19 = 0 ;
for ( V_3 = 0 ; V_3 < F_4 ( V_20 ) && ! V_19 ; V_3 ++ ) {
T_1 V_2 [ 2 ] ;
if ( V_20 [ V_3 ] [ 0 ] == V_13 ) {
V_19 = F_5 ( V_1 ,
V_20 [ V_3 ] [ 1 ] ,
V_20 [ V_3 ] [ 2 ] ) ;
} else {
V_2 [ 0 ] = V_20 [ V_3 ] [ 2 ] ;
V_2 [ 1 ] = V_20 [ V_3 ] [ 3 ] ;
V_19 = F_6 ( V_1 ,
V_20 [ V_3 ] [ 1 ] , V_2 , 2 ) ;
}
}
if ( V_21 )
F_9 ( V_1 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_1 )
{
struct V_22 * V_23 = & V_1 -> V_4 . V_24 ;
V_1 -> V_4 . V_25 . V_24 = V_23 ;
F_11 ( V_23 , 7 ) ;
V_1 -> V_26 = F_12 ( V_23 , & V_27 ,
V_28 ,
0 , 1 , 1 , 0 ) ;
V_1 -> V_29 = F_13 ( V_23 , & V_30 , NULL ) ;
V_1 -> V_31 = F_12 ( V_23 , & V_27 ,
V_32 , 0 , 0x7ff , 1 ,
V_33 ) ;
V_1 -> V_34 = F_12 ( V_23 , & V_27 ,
V_35 , 0 , 0x7ff , 1 ,
V_36 ) ;
F_12 ( V_23 , & V_27 , V_37 , 0 ,
( V_38 - 1 ) * 2 * 2 * 2 , 1 ,
V_39 ) ;
V_1 -> V_40 = F_12 ( V_23 , & V_27 , V_41 ,
0 , 1 , 1 , 0 ) ;
V_1 -> V_42 = F_12 ( V_23 , & V_27 , V_43 ,
0 , 1 , 1 , 0 ) ;
if ( V_23 -> error ) {
F_14 ( L_4 ) ;
return V_23 -> error ;
}
F_15 ( 4 , & V_1 -> V_26 , 0 , false ) ;
F_16 ( 2 , & V_1 -> V_40 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_1 )
{
int V_3 , V_19 = 0 ;
T_1 V_2 [ 2 ] ;
struct V_15 * V_15 = & V_1 -> V_4 . V_15 ;
struct V_4 * V_4 = (struct V_4 * ) V_1 ;
int V_44 = V_15 -> V_16 [ V_1 -> V_4 . V_45 ] . V_44 - 1 ;
int V_46 = V_15 -> V_16 [ V_1 -> V_4 . V_45 ] . V_46 ;
for ( V_3 = 0 ; V_3 < F_4 ( V_47 ) && ! V_19 ; V_3 ++ ) {
if ( V_47 [ V_3 ] [ 0 ] == V_13 ) {
V_19 = F_5 ( V_1 ,
V_47 [ V_3 ] [ 1 ] ,
V_47 [ V_3 ] [ 2 ] ) ;
} else {
V_2 [ 0 ] = V_47 [ V_3 ] [ 2 ] ;
V_2 [ 1 ] = V_47 [ V_3 ] [ 3 ] ;
V_19 = F_6 ( V_1 ,
V_47 [ V_3 ] [ 1 ] , V_2 , 2 ) ;
}
}
if ( V_19 < 0 )
return V_19 ;
V_19 = F_5 ( V_1 , V_48 , ( V_46 >> 8 ) & 0xff ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_5 ( V_1 , V_48 , ( V_46 & 0xff ) ) ;
if ( V_19 < 0 )
return V_19 ;
for ( V_3 = 0 ; V_3 < 2 && ! V_19 ; V_3 ++ )
V_19 = F_5 ( V_1 , V_48 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_5 ( V_1 , V_49 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_5 ( V_1 , V_49 , 2 ) ;
if ( V_19 < 0 )
return V_19 ;
for ( V_3 = 0 ; V_3 < 2 && ! V_19 ; V_3 ++ )
V_19 = F_5 ( V_1 , V_50 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_5 ( V_1 , V_50 ,
( V_44 >> 8 ) & 0xff ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_5 ( V_1 , V_50 , V_44 & 0xff ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_5 ( V_1 , V_49 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
switch ( V_44 ) {
case 640 :
F_3 ( V_51 , L_5 ) ;
break;
case 320 :
F_3 ( V_51 , L_6 ) ;
break;
}
return V_19 ;
}
void F_18 ( struct V_1 * V_1 )
{
V_1 -> V_52 = NULL ;
}
static int F_19 ( struct V_4 * V_4 )
{
int V_19 ;
T_1 V_2 [ 2 ] = { 0x00 , 0x00 } ;
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
int V_40 ;
int V_42 ;
F_3 ( V_51 , L_7 , V_1 -> V_40 -> V_53 , V_1 -> V_42 -> V_53 ) ;
V_40 = ! V_1 -> V_40 -> V_53 ;
V_42 = ! V_1 -> V_42 -> V_53 ;
V_19 = F_6 ( V_1 , V_54 , V_2 , 2 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 [ 0 ] = V_55 ;
if ( V_4 -> V_56 . V_44 == 640 ) {
V_2 [ 1 ] = V_57 |
V_58 |
( V_40 << 1 ) | V_42 ;
} else {
V_2 [ 1 ] = V_59 |
V_60 |
( V_40 << 1 ) | V_42 ;
}
V_19 = F_6 ( V_1 , V_61 ,
V_2 , 2 ) ;
return V_19 ;
}
static int F_20 ( struct V_4 * V_4 ,
T_2 V_53 )
{
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
int V_19 ;
T_1 V_2 [ 2 ] ;
V_19 = F_7 ( V_1 , V_62 , V_2 , 2 ) ;
if ( V_19 < 0 )
return V_19 ;
V_2 [ 1 ] = ( ( V_2 [ 1 ] & 0xfd ) | ( ( V_53 & 0x01 ) << 1 ) ) ;
V_19 = F_6 ( V_1 , V_62 , V_2 , 2 ) ;
F_3 ( V_51 , L_8 , V_53 ) ;
return V_19 ;
}
static int F_21 ( struct V_4 * V_4 , T_2 V_53 )
{
int V_19 , V_63 ;
T_1 V_2 [ 2 ] = { 0x00 , 0x00 } ;
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
V_19 = F_6 ( V_1 , V_54 , V_2 , 2 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_53 >= V_38 * 2 * 2 * 2 )
return - V_64 ;
if ( ( V_53 >= V_38 * 2 * 2 ) &&
( V_53 < ( V_38 - 1 ) * 2 * 2 * 2 ) )
V_63 = ( 1 << 10 ) | ( V_53 << 9 ) |
( V_53 << 8 ) | ( V_53 / 8 ) ;
else if ( ( V_53 >= V_38 * 2 ) &&
( V_53 < V_38 * 2 * 2 ) )
V_63 = ( 1 << 9 ) | ( 1 << 8 ) | ( V_53 / 4 ) ;
else if ( ( V_53 >= V_38 ) &&
( V_53 < V_38 * 2 ) )
V_63 = ( 1 << 8 ) | ( V_53 / 2 ) ;
else
V_63 = V_53 ;
V_2 [ 1 ] = ( V_63 & 0xff ) ;
V_2 [ 0 ] = ( V_63 & 0xff00 ) >> 8 ;
F_3 ( V_51 , L_9 , V_63 ,
V_2 [ 1 ] , V_2 [ 0 ] ) ;
V_19 = F_6 ( V_1 , V_65 ,
V_2 , 2 ) ;
return V_19 ;
}
static int F_22 ( struct V_4 * V_4 , T_2 V_53 )
{
int V_19 ;
T_1 V_2 [ 2 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
V_2 [ 1 ] = ( V_53 & 0xff ) ;
V_2 [ 0 ] = ( V_53 & 0xff00 ) >> 8 ;
F_3 ( V_51 , L_10 , V_53 ) ;
V_19 = F_6 ( V_1 , V_66 ,
V_2 , 2 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_6 ( V_1 , V_67 ,
V_2 , 2 ) ;
}
static int F_23 ( struct V_4 * V_4 , T_2 V_53 )
{
T_1 V_2 [ 2 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
V_2 [ 1 ] = ( V_53 & 0xff ) ;
V_2 [ 0 ] = ( V_53 & 0xff00 ) >> 8 ;
F_3 ( V_51 , L_11 , V_53 ) ;
return F_6 ( V_1 , V_68 ,
V_2 , 2 ) ;
}
static int F_24 ( struct V_4 * V_4 , T_2 V_53 )
{
T_1 V_2 [ 2 ] ;
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
V_2 [ 1 ] = ( V_53 & 0xff ) ;
V_2 [ 0 ] = ( V_53 & 0xff00 ) >> 8 ;
F_3 ( V_51 , L_12 , V_53 ) ;
return F_6 ( V_1 , V_69 ,
V_2 , 2 ) ;
}
static int F_25 ( struct V_70 * V_71 )
{
struct V_4 * V_4 =
F_26 ( V_71 -> V_72 , struct V_4 , V_24 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_4 ;
int V_19 ;
if ( ! V_4 -> V_73 )
return 0 ;
switch ( V_71 -> V_74 ) {
case V_28 :
V_19 = F_20 ( V_4 , V_71 -> V_53 ) ;
if ( V_19 || V_71 -> V_53 )
return V_19 ;
V_19 = F_22 ( V_4 , V_1 -> V_29 -> V_53 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_24 ( V_4 , V_1 -> V_31 -> V_53 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_23 ( V_4 , V_1 -> V_34 -> V_53 ) ;
break;
case V_37 :
V_19 = F_21 ( V_4 , V_71 -> V_53 ) ;
break;
case V_41 :
V_19 = F_19 ( V_4 ) ;
break;
default:
return - V_64 ;
}
return V_19 ;
}
static void F_9 ( struct V_1 * V_1 )
{
T_1 V_75 , V_76 [ 2 ] = { 0x00 , 0x00 } ;
F_2 ( L_13 ) ;
F_2 ( L_14 ) ;
V_76 [ 1 ] = V_77 ;
F_6 ( V_1 , V_54 , V_76 , 2 ) ;
for ( V_75 = 0 ; V_75 < 0xff ; V_75 ++ ) {
F_7 ( V_1 , V_75 , V_76 , 2 ) ;
F_2 ( L_15 ,
V_75 , V_76 [ 0 ] , V_76 [ 1 ] ) ;
}
F_2 ( L_16 ) ;
V_76 [ 1 ] = V_78 ;
F_6 ( V_1 , V_54 , V_76 , 2 ) ;
for ( V_75 = 0 ; V_75 < 0xff ; V_75 ++ ) {
F_7 ( V_1 , V_75 , V_76 , 2 ) ;
F_2 ( L_15 ,
V_75 , V_76 [ 0 ] , V_76 [ 1 ] ) ;
}
F_2 ( L_17 ) ;
V_76 [ 1 ] = V_79 ;
F_6 ( V_1 , V_54 , V_76 , 2 ) ;
for ( V_75 = 0 ; V_75 < 0xff ; V_75 ++ ) {
F_7 ( V_1 , V_75 , V_76 , 2 ) ;
F_2 ( L_15 ,
V_75 , V_76 [ 0 ] , V_76 [ 1 ] ) ;
}
F_2 ( L_18 ) ;
}
