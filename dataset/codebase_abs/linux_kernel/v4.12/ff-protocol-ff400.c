static int F_1 ( struct V_1 * V_2 , unsigned int * V_3 ,
enum V_4 * V_5 )
{
T_1 V_6 ;
T_2 V_7 ;
int V_8 ;
V_8 = F_2 ( V_2 -> V_9 , V_10 ,
V_11 , & V_6 , sizeof( V_6 ) , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_7 = F_3 ( V_6 ) ;
switch ( ( V_7 >> 1 ) & 0x03 ) {
case 0x01 :
* V_3 = 32000 ;
break;
case 0x00 :
* V_3 = 44100 ;
break;
case 0x03 :
* V_3 = 48000 ;
break;
case 0x02 :
default:
return - V_12 ;
}
if ( V_7 & 0x08 )
* V_3 *= 2 ;
else if ( V_7 & 0x10 )
* V_3 *= 4 ;
if ( V_7 & 0x01 ) {
* V_5 = V_13 ;
} else {
switch ( ( V_7 >> 10 ) & 0x07 ) {
case 0x03 :
* V_5 = V_14 ;
break;
case 0x04 :
* V_5 = V_15 ;
break;
case 0x05 :
* V_5 = V_16 ;
break;
case 0x00 :
default:
* V_5 = V_17 ;
break;
}
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_6 ;
int V_18 , V_8 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
if ( V_20 [ V_18 ] == V_3 )
break;
}
if ( V_18 == V_19 )
return - V_21 ;
V_6 = F_5 ( V_3 ) ;
V_8 = F_2 ( V_2 -> V_9 , V_22 ,
V_23 , & V_6 , sizeof( V_6 ) , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
F_6 ( 100 ) ;
V_6 = F_5 ( ( ( V_2 -> V_24 . V_25 << 3 ) << 8 ) |
V_2 -> V_26 . V_27 ) ;
V_8 = F_2 ( V_2 -> V_9 , V_22 ,
V_28 , & V_6 , sizeof( V_6 ) , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 = F_5 ( ( 0x80 << 24 ) |
( V_2 -> V_29 . V_27 << 5 ) |
( V_2 -> V_30 . V_25 ) ) ;
V_8 = F_2 ( V_2 -> V_9 , V_22 ,
V_31 , & V_6 , sizeof( V_6 ) , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 = F_5 ( 0x00000001 ) ;
return F_2 ( V_2 -> V_9 , V_22 ,
V_32 , & V_6 , sizeof( V_6 ) , 0 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_5 ( 0x80000000 ) ;
F_2 ( V_2 -> V_9 , V_22 ,
V_33 , & V_6 , sizeof( V_6 ) , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 , bool V_34 )
{
T_1 * V_6 ;
int V_18 ;
V_6 = F_9 ( sizeof( T_1 ) * 18 , V_35 ) ;
if ( V_6 == NULL )
return - V_36 ;
if ( V_34 ) {
for ( V_18 = 0 ; V_18 < 18 ; ++ V_18 )
V_6 [ V_18 ] = F_5 ( 0x00000001 ) ;
}
return F_2 ( V_2 -> V_9 , V_37 ,
V_38 , V_6 ,
sizeof( T_1 ) * 18 , 0 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
T_1 V_6 ;
T_2 V_7 ;
int V_8 ;
V_8 = F_2 ( V_2 -> V_9 , V_10 ,
V_11 , & V_6 , sizeof( V_6 ) , 0 ) ;
if ( V_8 < 0 )
return;
V_7 = F_3 ( V_6 ) ;
F_11 ( V_40 , L_1 ) ;
F_11 ( V_40 , L_2 ) ;
if ( ( V_7 >> 24 ) & 0x20 ) {
if ( ( V_7 >> 24 ) & 0x40 )
F_11 ( V_40 , L_3 ) ;
else
F_11 ( V_40 , L_4 ) ;
} else {
F_11 ( V_40 , L_5 ) ;
}
F_11 ( V_40 , L_6 ) ;
if ( ( V_7 >> 16 ) & 0x10 ) {
if ( ( V_7 >> 16 ) & 0x04 )
F_11 ( V_40 , L_3 ) ;
else
F_11 ( V_40 , L_4 ) ;
} else {
F_11 ( V_40 , L_5 ) ;
}
F_11 ( V_40 , L_7 ) ;
if ( ( V_7 >> 8 ) & 0x04 ) {
if ( ( V_7 >> 8 ) & 0x10 )
F_11 ( V_40 , L_3 ) ;
else
F_11 ( V_40 , L_4 ) ;
} else {
F_11 ( V_40 , L_5 ) ;
}
F_11 ( V_40 , L_8 ) ;
if ( ( ( V_7 >> 22 ) & 0x07 ) == 0x07 ) {
F_11 ( V_40 , L_9 ) ;
} else {
switch ( ( V_7 >> 22 ) & 0x07 ) {
case 0x00 :
F_11 ( V_40 , L_7 ) ;
break;
case 0x03 :
F_11 ( V_40 , L_6 ) ;
break;
case 0x04 :
F_11 ( V_40 , L_10 ) ;
break;
case 0x07 :
F_11 ( V_40 , L_11 ) ;
break;
case 0x01 :
case 0x02 :
case 0x05 :
case 0x06 :
default:
F_11 ( V_40 , L_12 ) ;
break;
}
if ( ( V_7 >> 25 ) & 0x07 ) {
switch ( ( V_7 >> 25 ) & 0x07 ) {
case 0x01 :
F_11 ( V_40 , L_13 ) ;
break;
case 0x02 :
F_11 ( V_40 , L_14 ) ;
break;
case 0x03 :
F_11 ( V_40 , L_15 ) ;
break;
case 0x04 :
F_11 ( V_40 , L_16 ) ;
break;
case 0x05 :
F_11 ( V_40 , L_17 ) ;
break;
case 0x06 :
F_11 ( V_40 , L_18 ) ;
break;
case 0x07 :
F_11 ( V_40 , L_19 ) ;
break;
case 0x08 :
F_11 ( V_40 , L_20 ) ;
break;
case 0x09 :
F_11 ( V_40 , L_21 ) ;
break;
case 0x00 :
F_11 ( V_40 , L_22 ) ;
break;
}
}
}
F_11 ( V_40 , L_23 ) ;
F_11 ( V_40 , L_24 , ( V_7 & 0x3ff ) * 250 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
T_1 V_6 ;
T_2 V_7 ;
unsigned int V_3 ;
const char * V_5 ;
int V_8 ;
V_8 = F_2 ( V_2 -> V_9 , V_41 ,
V_42 , & V_6 , sizeof( V_6 ) , 0 ) ;
if ( V_8 < 0 )
return;
V_7 = F_3 ( V_6 ) ;
F_11 ( V_40 , L_25 ,
( V_7 & 0x20 ) ? L_26 : L_27 ,
( V_7 & 0x40 ) ? L_28 : L_29 ) ;
F_11 ( V_40 , L_30 ,
( ( V_7 >> 8 ) & 0x01 ) ? L_31 : L_32 ) ;
F_11 ( V_40 , L_33 ,
( ( V_7 >> 8 ) & 0x20 ) ? L_28 : L_29 ) ;
F_11 ( V_40 , L_34 ,
( ( V_7 >> 8 ) & 0x02 ) ? L_35 : L_36 ) ;
switch ( ( V_7 >> 1 ) & 0x03 ) {
case 0x01 :
V_3 = 32000 ;
break;
case 0x00 :
V_3 = 44100 ;
break;
case 0x03 :
V_3 = 48000 ;
break;
case 0x02 :
default:
return;
}
if ( V_7 & 0x08 )
V_3 *= 2 ;
else if ( V_7 & 0x10 )
V_3 *= 4 ;
F_11 ( V_40 , L_37 , V_3 ) ;
if ( V_7 & 0x01 ) {
V_5 = L_38 ;
} else {
switch ( ( V_7 >> 10 ) & 0x07 ) {
case 0x00 :
V_5 = L_32 ;
break;
case 0x03 :
V_5 = L_31 ;
break;
case 0x04 :
V_5 = L_39 ;
break;
case 0x05 :
V_5 = L_40 ;
break;
default:
return;
}
}
F_11 ( V_40 , L_41 , V_5 ) ;
}
