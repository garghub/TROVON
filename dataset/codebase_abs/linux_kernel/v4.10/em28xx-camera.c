static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned char V_4 [] [ 3 ] = {
{ 0x0d , 0x00 , 0x01 , } ,
{ 0x0d , 0x00 , 0x00 , } ,
{ 0x0a , 0x00 , 0x21 , } ,
{ 0x21 , 0x04 , 0x00 , } ,
} ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
F_3 ( & V_2 -> V_5 [ V_2 -> V_6 ] ,
& V_4 [ V_3 ] [ 0 ] , 3 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned char V_4 [] [ 3 ] = {
{ 0x0d , 0x00 , 0x01 , } ,
{ 0x0d , 0x00 , 0x00 , } ,
{ 0x04 , 0x05 , 0x00 , } ,
{ 0x03 , 0x04 , 0x00 , } ,
{ 0x20 , 0x11 , 0x00 , } ,
{ 0x06 , 0x00 , 0x10 , } ,
{ 0x2b , 0x00 , 0x24 , } ,
{ 0x2e , 0x00 , 0x24 , } ,
{ 0x35 , 0x00 , 0x24 , } ,
{ 0x2d , 0x00 , 0x20 , } ,
{ 0x2c , 0x00 , 0x20 , } ,
{ 0x09 , 0x0a , 0xd4 , } ,
{ 0x35 , 0x00 , 0x57 , } ,
} ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
F_3 ( & V_2 -> V_5 [ V_2 -> V_6 ] ,
& V_4 [ V_3 ] [ 0 ] , 3 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_7 , V_3 ;
char * V_8 ;
T_1 V_9 ;
T_2 V_10 ;
T_3 V_11 ;
struct V_5 V_12 = V_2 -> V_5 [ V_2 -> V_6 ] ;
V_2 -> V_13 = V_14 ;
for ( V_3 = 0 ; V_15 [ V_3 ] != V_16 ; V_3 ++ ) {
V_12 . V_17 = V_15 [ V_3 ] ;
V_9 = 0x00 ;
V_7 = F_3 ( & V_12 , & V_9 , 1 ) ;
if ( V_7 < 0 ) {
if ( V_7 != - V_18 )
F_6 ( & V_2 -> V_19 -> V_2 ,
L_1 ,
V_12 . V_17 << 1 , V_7 ) ;
continue;
}
V_7 = F_7 ( & V_12 , ( T_1 * ) & V_10 , 2 ) ;
if ( V_7 < 0 ) {
F_6 ( & V_2 -> V_19 -> V_2 ,
L_1 ,
V_12 . V_17 << 1 , V_7 ) ;
continue;
}
V_11 = F_8 ( V_10 ) ;
V_9 = 0xff ;
V_7 = F_3 ( & V_12 , & V_9 , 1 ) ;
if ( V_7 < 0 ) {
F_6 ( & V_2 -> V_19 -> V_2 ,
L_1 ,
V_12 . V_17 << 1 , V_7 ) ;
continue;
}
V_7 = F_7 ( & V_12 , ( T_1 * ) & V_10 , 2 ) ;
if ( V_7 < 0 ) {
F_6 ( & V_2 -> V_19 -> V_2 ,
L_1 ,
V_12 . V_17 << 1 , V_7 ) ;
continue;
}
if ( V_11 != F_8 ( V_10 ) )
continue;
V_11 = F_8 ( V_10 ) ;
switch ( V_11 ) {
case 0x1222 :
V_8 = L_2 ;
break;
case 0x1229 :
V_8 = L_3 ;
break;
case 0x1433 :
V_8 = L_4 ;
break;
case 0x143a :
V_8 = L_5 ;
V_2 -> V_13 = V_20 ;
break;
case 0x148c :
V_8 = L_6 ;
break;
case 0x1511 :
V_8 = L_7 ;
break;
case 0x8232 :
case 0x8243 :
V_8 = L_8 ;
V_2 -> V_13 = V_21 ;
break;
case 0x8431 :
V_8 = L_9 ;
V_2 -> V_13 = V_22 ;
break;
default:
F_9 ( & V_2 -> V_19 -> V_2 ,
L_10 , V_11 ) ;
return 0 ;
}
if ( V_2 -> V_13 == V_14 )
F_9 ( & V_2 -> V_19 -> V_2 ,
L_11 , V_8 ) ;
else
F_9 ( & V_2 -> V_19 -> V_2 ,
L_12 , V_8 ) ;
V_2 -> V_5 [ V_2 -> V_6 ] . V_17 = V_12 . V_17 ;
return 0 ;
}
return - V_23 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_7 , V_3 ;
char * V_8 ;
T_1 V_9 ;
T_3 V_11 ;
struct V_5 V_12 = V_2 -> V_5 [ V_2 -> V_6 ] ;
V_2 -> V_13 = V_14 ;
for ( V_3 = 0 ; V_24 [ V_3 ] != V_16 ; V_3 ++ ) {
V_12 . V_17 = V_24 [ V_3 ] ;
V_9 = 0x1c ;
V_7 = F_11 ( & V_12 , V_9 ) ;
if ( V_7 < 0 ) {
if ( V_7 != - V_18 )
F_6 ( & V_2 -> V_19 -> V_2 ,
L_1 ,
V_12 . V_17 << 1 , V_7 ) ;
continue;
}
V_11 = V_7 << 8 ;
V_9 = 0x1d ;
V_7 = F_11 ( & V_12 , V_9 ) ;
if ( V_7 < 0 ) {
F_6 ( & V_2 -> V_19 -> V_2 ,
L_1 ,
V_12 . V_17 << 1 , V_7 ) ;
continue;
}
V_11 += V_7 ;
if ( V_11 != 0x7fa2 )
continue;
V_9 = 0x0a ;
V_7 = F_11 ( & V_12 , V_9 ) ;
if ( V_7 < 0 ) {
F_6 ( & V_2 -> V_19 -> V_2 ,
L_1 ,
V_12 . V_17 << 1 , V_7 ) ;
continue;
}
V_11 = V_7 << 8 ;
V_9 = 0x0b ;
V_7 = F_11 ( & V_12 , V_9 ) ;
if ( V_7 < 0 ) {
F_6 ( & V_2 -> V_19 -> V_2 ,
L_1 ,
V_12 . V_17 << 1 , V_7 ) ;
continue;
}
V_11 += V_7 ;
switch ( V_11 ) {
case 0x2642 :
V_8 = L_13 ;
V_2 -> V_13 = V_25 ;
break;
case 0x7648 :
V_8 = L_14 ;
break;
case 0x7660 :
V_8 = L_15 ;
break;
case 0x7673 :
V_8 = L_16 ;
break;
case 0x7720 :
V_8 = L_17 ;
break;
case 0x7721 :
V_8 = L_18 ;
break;
case 0x9648 :
case 0x9649 :
V_8 = L_19 ;
break;
case 0x9650 :
case 0x9652 :
V_8 = L_20 ;
break;
case 0x9656 :
case 0x9657 :
V_8 = L_21 ;
break;
default:
F_9 ( & V_2 -> V_19 -> V_2 ,
L_22 ,
V_11 ) ;
return 0 ;
}
if ( V_2 -> V_13 == V_14 )
F_9 ( & V_2 -> V_19 -> V_2 ,
L_11 , V_8 ) ;
else
F_9 ( & V_2 -> V_19 -> V_2 ,
L_12 , V_8 ) ;
V_2 -> V_5 [ V_2 -> V_6 ] . V_17 = V_12 . V_17 ;
return 0 ;
}
return - V_23 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_5 ( V_2 ) ;
if ( V_2 -> V_13 == V_14 && V_7 < 0 )
V_7 = F_10 ( V_2 ) ;
if ( V_2 -> V_13 == V_14 && V_7 < 0 ) {
F_9 ( & V_2 -> V_19 -> V_2 ,
L_23 ) ;
return - V_23 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
char V_26 [ V_27 ] ;
struct V_5 * V_12 = & V_2 -> V_5 [ V_2 -> V_6 ] ;
struct V_28 * V_29 = & V_2 -> V_30 [ V_2 -> V_6 ] ;
struct V_31 * V_32 = V_2 -> V_32 ;
int V_7 = 0 ;
F_14 ( V_26 , sizeof( V_26 ) ,
F_15 ( V_29 ) , V_12 -> V_17 ) ;
V_32 -> V_33 = F_16 ( V_26 , - V_34 ) ;
if ( F_17 ( V_32 -> V_33 ) )
return F_18 ( V_32 -> V_33 ) ;
switch ( V_2 -> V_13 ) {
case V_21 :
{
struct V_35 V_36 ;
struct V_37 V_38 = {
. type = L_24 ,
. V_17 = V_12 -> V_17 ,
. V_39 = & V_36 ,
} ;
V_32 -> V_40 = 640 ;
V_32 -> V_41 = 480 ;
V_2 -> V_42 . V_43 = V_44 ;
F_19 ( V_2 , V_45 , V_2 -> V_42 . V_43 ) ;
V_32 -> V_46 = 4300000 ;
V_36 . V_47 = V_32 -> V_46 ;
if ( NULL ==
F_20 ( & V_32 -> V_48 , V_29 ,
& V_38 , NULL ) ) {
V_7 = - V_23 ;
break;
}
V_32 -> V_49 = 0x0d ;
V_32 -> V_50 = 0x00 ;
break;
}
case V_22 :
V_32 -> V_40 = 1280 ;
V_32 -> V_41 = 1024 ;
F_4 ( V_2 ) ;
V_32 -> V_49 = 0x0c ;
V_32 -> V_50 = 0x00 ;
break;
case V_20 :
V_32 -> V_40 = 640 ;
V_32 -> V_41 = 512 ;
V_2 -> V_42 . V_43 = V_51 ;
F_19 ( V_2 , V_45 , V_2 -> V_42 . V_43 ) ;
F_1 ( V_2 ) ;
V_32 -> V_49 = 0x0a ;
V_32 -> V_50 = 0x00 ;
break;
case V_25 :
{
struct V_52 * V_53 ;
struct V_37 V_54 = {
. type = L_25 ,
. V_55 = V_56 ,
. V_17 = V_12 -> V_17 ,
. V_39 = & V_57 ,
} ;
struct V_58 V_59 = {
. V_60 = V_61 ,
} ;
V_32 -> V_40 = 640 ;
V_32 -> V_41 = 480 ;
V_53 =
F_20 ( & V_32 -> V_48 , V_29 ,
& V_54 , NULL ) ;
if ( NULL == V_53 ) {
V_7 = - V_23 ;
break;
}
V_59 . V_59 . V_62 = V_63 ;
V_59 . V_59 . V_64 = 640 ;
V_59 . V_59 . V_65 = 480 ;
F_21 ( V_53 , V_66 , V_67 , NULL , & V_59 ) ;
V_2 -> V_42 . V_43 = V_68 ;
F_19 ( V_2 , V_45 , V_2 -> V_42 . V_43 ) ;
V_32 -> V_49 = 0x08 ;
V_32 -> V_50 = 0x00 ;
break;
}
case V_14 :
default:
V_7 = - V_34 ;
}
if ( V_7 < 0 ) {
F_22 ( V_32 -> V_33 ) ;
V_32 -> V_33 = NULL ;
}
return V_7 ;
}
