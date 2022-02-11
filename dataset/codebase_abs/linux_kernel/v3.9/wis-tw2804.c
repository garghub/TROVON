static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , int V_5 )
{
return F_2 ( V_2 , V_3 | ( V_5 << 6 ) , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_6 , int V_5 )
{
int V_7 ;
for ( V_7 = 0 ; V_6 [ V_7 ] != 0xff ; V_7 += 2 )
if ( F_2 ( V_2 ,
V_6 [ V_7 ] | ( V_5 << 6 ) , V_6 [ V_7 + 1 ] ) < 0 )
return - 1 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_8 , void * V_9 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
if ( V_8 == V_12 ) {
int * V_13 = V_9 ;
if ( * V_13 < 0 || * V_13 > 3 ) {
F_6 ( & V_2 -> V_14 ,
L_1 , * V_13 ) ;
return 0 ;
}
V_11 -> V_5 = * V_13 ;
F_7 ( & V_2 -> V_14 , L_2 ,
V_11 -> V_5 ) ;
if ( V_11 -> V_5 == 0 &&
F_3 ( V_2 , V_15 , 0 ) < 0 ) {
F_6 ( & V_2 -> V_14 ,
L_3 ) ;
return 0 ;
}
if ( F_3 ( V_2 , V_16 , V_11 -> V_5 ) < 0 ) {
F_6 ( & V_2 -> V_14 ,
L_4 ,
V_11 -> V_5 ) ;
return 0 ;
}
return 0 ;
}
if ( V_11 -> V_5 < 0 ) {
F_7 ( & V_2 -> V_14 ,
L_5 ,
V_8 ) ;
return 0 ;
}
switch ( V_8 ) {
case V_17 :
{
T_2 * V_13 = V_9 ;
T_1 V_6 [] = {
0x01 , * V_13 & V_18 ? 0xc4 : 0x84 ,
0x09 , * V_13 & V_18 ? 0x07 : 0x04 ,
0x0a , * V_13 & V_18 ? 0xf0 : 0x20 ,
0x0b , * V_13 & V_18 ? 0x07 : 0x04 ,
0x0c , * V_13 & V_18 ? 0xf0 : 0x20 ,
0x0d , * V_13 & V_18 ? 0x40 : 0x4a ,
0x16 , * V_13 & V_18 ? 0x00 : 0x40 ,
0x17 , * V_13 & V_18 ? 0x00 : 0x40 ,
0x20 , * V_13 & V_18 ? 0x07 : 0x0f ,
0x21 , * V_13 & V_18 ? 0x07 : 0x0f ,
0xff , 0xff ,
} ;
F_3 ( V_2 , V_6 , V_11 -> V_5 ) ;
V_11 -> V_19 = * V_13 ;
break;
}
case V_20 :
{
struct V_21 * V_22 = V_9 ;
switch ( V_22 -> V_23 ) {
case V_24 :
V_22 -> type = V_25 ;
strncpy ( V_22 -> V_26 , L_6 , sizeof( V_22 -> V_26 ) ) ;
V_22 -> V_27 = 0 ;
V_22 -> V_28 = 255 ;
V_22 -> V_29 = 1 ;
V_22 -> V_30 = 128 ;
V_22 -> V_31 = 0 ;
break;
case V_32 :
V_22 -> type = V_25 ;
strncpy ( V_22 -> V_26 , L_7 , sizeof( V_22 -> V_26 ) ) ;
V_22 -> V_27 = 0 ;
V_22 -> V_28 = 255 ;
V_22 -> V_29 = 1 ;
V_22 -> V_30 = 128 ;
V_22 -> V_31 = 0 ;
break;
case V_33 :
V_22 -> type = V_25 ;
strncpy ( V_22 -> V_26 , L_8 , sizeof( V_22 -> V_26 ) ) ;
V_22 -> V_27 = 0 ;
V_22 -> V_28 = 255 ;
V_22 -> V_29 = 1 ;
V_22 -> V_30 = 128 ;
V_22 -> V_31 = 0 ;
break;
case V_34 :
V_22 -> type = V_25 ;
strncpy ( V_22 -> V_26 , L_9 , sizeof( V_22 -> V_26 ) ) ;
V_22 -> V_27 = 0 ;
V_22 -> V_28 = 255 ;
V_22 -> V_29 = 1 ;
V_22 -> V_30 = 128 ;
V_22 -> V_31 = 0 ;
break;
}
break;
}
case V_35 :
{
struct V_36 * V_22 = V_9 ;
switch ( V_22 -> V_23 ) {
case V_24 :
if ( V_22 -> V_4 > 255 )
V_11 -> V_37 = 255 ;
else if ( V_22 -> V_4 < 0 )
V_11 -> V_37 = 0 ;
else
V_11 -> V_37 = V_22 -> V_4 ;
F_1 ( V_2 , 0x12 , V_11 -> V_37 , V_11 -> V_5 ) ;
break;
case V_32 :
if ( V_22 -> V_4 > 255 )
V_11 -> V_38 = 255 ;
else if ( V_22 -> V_4 < 0 )
V_11 -> V_38 = 0 ;
else
V_11 -> V_38 = V_22 -> V_4 ;
F_1 ( V_2 , 0x11 , V_11 -> V_38 , V_11 -> V_5 ) ;
break;
case V_33 :
if ( V_22 -> V_4 > 255 )
V_11 -> V_39 = 255 ;
else if ( V_22 -> V_4 < 0 )
V_11 -> V_39 = 0 ;
else
V_11 -> V_39 = V_22 -> V_4 ;
F_1 ( V_2 , 0x10 , V_11 -> V_39 , V_11 -> V_5 ) ;
break;
case V_34 :
if ( V_22 -> V_4 > 255 )
V_11 -> V_40 = 255 ;
else if ( V_22 -> V_4 < 0 )
V_11 -> V_40 = 0 ;
else
V_11 -> V_40 = V_22 -> V_4 ;
F_1 ( V_2 , 0x0f , V_11 -> V_40 , V_11 -> V_5 ) ;
break;
}
break;
}
case V_41 :
{
struct V_36 * V_22 = V_9 ;
switch ( V_22 -> V_23 ) {
case V_24 :
V_22 -> V_4 = V_11 -> V_37 ;
break;
case V_32 :
V_22 -> V_4 = V_11 -> V_38 ;
break;
case V_33 :
V_22 -> V_4 = V_11 -> V_39 ;
break;
case V_34 :
V_22 -> V_4 = V_11 -> V_40 ;
break;
}
break;
}
default:
break;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_42 * V_23 )
{
struct V_43 * V_44 = V_2 -> V_44 ;
struct V_10 * V_11 ;
if ( ! F_9 ( V_44 , V_45 ) )
return - V_46 ;
V_11 = F_10 ( sizeof( struct V_10 ) , V_47 ) ;
if ( V_11 == NULL )
return - V_48 ;
V_11 -> V_5 = - 1 ;
V_11 -> V_19 = V_18 ;
V_11 -> V_37 = 128 ;
V_11 -> V_38 = 128 ;
V_11 -> V_39 = 128 ;
V_11 -> V_40 = 128 ;
F_11 ( V_2 , V_11 ) ;
F_7 ( & V_2 -> V_14 , L_10 ,
V_2 -> V_49 , V_44 -> V_26 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
F_13 ( V_11 ) ;
return 0 ;
}
