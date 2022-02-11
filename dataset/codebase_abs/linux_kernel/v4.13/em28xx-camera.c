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
struct V_5 * V_10 = & V_2 -> V_5 [ V_2 -> V_6 ] ;
V_2 -> V_11 = V_12 ;
for ( V_3 = 0 ; V_13 [ V_3 ] != V_14 ; V_3 ++ ) {
V_10 -> V_15 = V_13 [ V_3 ] ;
V_7 = F_6 ( V_10 , 0x00 ) ;
if ( V_7 < 0 ) {
if ( V_7 != - V_16 )
F_7 ( & V_2 -> V_17 -> V_2 ,
L_1 ,
V_10 -> V_15 << 1 , V_7 ) ;
continue;
}
V_9 = F_8 ( V_7 ) ;
V_7 = F_6 ( V_10 , 0xff ) ;
if ( V_7 < 0 ) {
F_7 ( & V_2 -> V_17 -> V_2 ,
L_1 ,
V_10 -> V_15 << 1 , V_7 ) ;
continue;
}
if ( V_9 != F_8 ( V_7 ) )
continue;
switch ( V_9 ) {
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
V_2 -> V_11 = V_18 ;
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
V_2 -> V_11 = V_19 ;
break;
case 0x8431 :
V_8 = L_9 ;
V_2 -> V_11 = V_20 ;
break;
default:
F_9 ( & V_2 -> V_17 -> V_2 ,
L_10 , V_9 ) ;
return 0 ;
}
if ( V_2 -> V_11 == V_12 )
F_9 ( & V_2 -> V_17 -> V_2 ,
L_11 , V_8 ) ;
else
F_9 ( & V_2 -> V_17 -> V_2 ,
L_12 , V_8 ) ;
return 0 ;
}
return - V_21 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_7 , V_3 ;
char * V_8 ;
T_2 V_22 ;
T_1 V_9 ;
struct V_5 * V_10 = & V_2 -> V_5 [ V_2 -> V_6 ] ;
V_2 -> V_11 = V_12 ;
for ( V_3 = 0 ; V_23 [ V_3 ] != V_14 ; V_3 ++ ) {
V_10 -> V_15 = V_23 [ V_3 ] ;
V_22 = 0x1c ;
V_7 = F_11 ( V_10 , V_22 ) ;
if ( V_7 < 0 ) {
if ( V_7 != - V_16 )
F_7 ( & V_2 -> V_17 -> V_2 ,
L_1 ,
V_10 -> V_15 << 1 , V_7 ) ;
continue;
}
V_9 = V_7 << 8 ;
V_22 = 0x1d ;
V_7 = F_11 ( V_10 , V_22 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_2 -> V_17 -> V_2 ,
L_1 ,
V_10 -> V_15 << 1 , V_7 ) ;
continue;
}
V_9 += V_7 ;
if ( V_9 != 0x7fa2 )
continue;
V_22 = 0x0a ;
V_7 = F_11 ( V_10 , V_22 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_2 -> V_17 -> V_2 ,
L_1 ,
V_10 -> V_15 << 1 , V_7 ) ;
continue;
}
V_9 = V_7 << 8 ;
V_22 = 0x0b ;
V_7 = F_11 ( V_10 , V_22 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_2 -> V_17 -> V_2 ,
L_1 ,
V_10 -> V_15 << 1 , V_7 ) ;
continue;
}
V_9 += V_7 ;
switch ( V_9 ) {
case 0x2642 :
V_8 = L_13 ;
V_2 -> V_11 = V_24 ;
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
F_9 ( & V_2 -> V_17 -> V_2 ,
L_22 ,
V_9 ) ;
return 0 ;
}
if ( V_2 -> V_11 == V_12 )
F_9 ( & V_2 -> V_17 -> V_2 ,
L_11 , V_8 ) ;
else
F_9 ( & V_2 -> V_17 -> V_2 ,
L_12 , V_8 ) ;
return 0 ;
}
return - V_21 ;
}
int F_12 ( struct V_1 * V_2 )
{
int V_7 ;
V_7 = F_5 ( V_2 ) ;
if ( V_2 -> V_11 == V_12 && V_7 < 0 )
V_7 = F_10 ( V_2 ) ;
if ( V_2 -> V_11 == V_12 && V_7 < 0 ) {
F_9 ( & V_2 -> V_17 -> V_2 ,
L_23 ) ;
return - V_21 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_10 = & V_2 -> V_5 [ V_2 -> V_6 ] ;
struct V_25 * V_26 = & V_2 -> V_27 [ V_2 -> V_6 ] ;
struct V_28 * V_29 = V_2 -> V_29 ;
switch ( V_2 -> V_11 ) {
case V_19 :
{
struct V_30 V_31 ;
struct V_32 V_33 = {
. type = L_24 ,
. V_15 = V_10 -> V_15 ,
. V_34 = & V_31 ,
} ;
V_29 -> V_35 = 640 ;
V_29 -> V_36 = 480 ;
V_2 -> V_37 . V_38 = V_39 ;
F_14 ( V_2 , V_40 , V_2 -> V_37 . V_38 ) ;
V_29 -> V_41 = 4300000 ;
V_31 . V_42 = V_29 -> V_41 ;
if ( NULL ==
F_15 ( & V_29 -> V_43 , V_26 ,
& V_33 , NULL ) )
return - V_21 ;
V_29 -> V_44 = V_45 ;
V_29 -> V_46 = 0x00 ;
break;
}
case V_20 :
V_29 -> V_35 = 1280 ;
V_29 -> V_36 = 1024 ;
F_4 ( V_2 ) ;
V_29 -> V_44 = V_47 ;
V_29 -> V_46 = 0x00 ;
break;
case V_18 :
V_29 -> V_35 = 640 ;
V_29 -> V_36 = 512 ;
V_2 -> V_37 . V_38 = V_48 ;
F_14 ( V_2 , V_40 , V_2 -> V_37 . V_38 ) ;
F_1 ( V_2 ) ;
V_29 -> V_44 = V_49 ;
V_29 -> V_46 = 0x00 ;
break;
case V_24 :
{
struct V_50 * V_51 ;
struct V_32 V_52 = {
. type = L_25 ,
. V_53 = V_54 ,
. V_15 = V_10 -> V_15 ,
} ;
struct V_55 V_56 = {
. V_57 = V_58 ,
} ;
V_29 -> V_35 = 640 ;
V_29 -> V_36 = 480 ;
V_51 =
F_15 ( & V_29 -> V_43 , V_26 ,
& V_52 , NULL ) ;
if ( V_51 == NULL )
return - V_21 ;
V_56 . V_56 . V_59 = V_60 ;
V_56 . V_56 . V_61 = 640 ;
V_56 . V_56 . V_62 = 480 ;
F_16 ( V_51 , V_63 , V_64 , NULL , & V_56 ) ;
V_2 -> V_37 . V_38 = V_65 ;
F_14 ( V_2 , V_40 , V_2 -> V_37 . V_38 ) ;
V_29 -> V_44 = V_66 ;
V_29 -> V_46 = 0x00 ;
break;
}
case V_12 :
default:
return - V_67 ;
}
return 0 ;
}
