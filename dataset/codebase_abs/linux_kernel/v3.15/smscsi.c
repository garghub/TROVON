int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
V_2 -> V_6 = V_7 ;
switch ( V_4 -> V_8 [ 0 ] ) {
case V_9 :
V_5 = F_2 ( V_2 , V_4 ) ;
break;
case V_10 :
V_5 = F_3 ( V_2 , V_4 ) ;
break;
case V_11 :
V_5 = F_4 ( V_2 , V_4 ) ;
break;
case V_12 :
V_5 = F_5 ( V_2 , V_4 ) ;
break;
case V_13 :
V_5 = F_6 ( V_2 , V_4 ) ;
break;
case V_14 :
V_5 = F_7 ( V_2 , V_4 ) ;
break;
default:
V_2 -> V_6 = V_15 ;
V_5 = V_16 ;
break;
}
return V_5 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_17 . V_18 && V_2 -> V_17 . V_19 )
return V_20 ;
else {
F_8 ( V_2 ) ;
return V_20 ;
}
return V_20 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_21 [ 36 ] = { 0x00 , 0x80 , 0x02 , 0x00 , 0x1F , 0x00 , 0x00 , 0x00 ,
0x55 , 0x53 , 0x42 , 0x32 , 0x2E , 0x30 , 0x20 ,
0x20 , 0x43 , 0x61 , 0x72 , 0x64 , 0x52 , 0x65 ,
0x61 , 0x64 , 0x65 , 0x72 , 0x20 , 0x20 , 0x20 ,
0x20 , 0x20 , 0x20 , 0x30 , 0x31 , 0x30 , 0x30 } ;
F_9 ( V_2 , V_21 , 36 , V_4 , V_22 ) ;
return V_20 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_23 [ 12 ] = { 0x0b , 0x00 , 0x00 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
T_1 V_24 [ 12 ] = { 0x0b , 0x00 , 0x80 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
if ( V_2 -> V_17 . V_25 )
F_9 ( V_2 , V_24 , 12 , V_4 , V_22 ) ;
else
F_9 ( V_2 , V_23 , 12 , V_4 , V_22 ) ;
return V_20 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_26 = 0 ;
struct V_27 * V_28 = NULL ;
T_2 V_29 ;
T_3 V_30 ;
T_1 V_31 [ 8 ] ;
F_10 ( & V_2 -> V_32 -> V_33 , L_1 ) ;
V_30 = 0x200 ;
V_29 = V_34 . V_35 * V_34 . V_36 * V_34 . V_37 - 1 ;
V_2 -> V_29 = V_29 ;
F_10 ( & V_2 -> V_32 -> V_33 , L_2 , V_30 ) ;
F_10 ( & V_2 -> V_32 -> V_33 , L_3 , V_29 ) ;
V_31 [ 0 ] = ( V_29 >> 24 ) & 0xff ;
V_31 [ 1 ] = ( V_29 >> 16 ) & 0xff ;
V_31 [ 2 ] = ( V_29 >> 8 ) & 0xff ;
V_31 [ 3 ] = ( V_29 >> 0 ) & 0xff ;
V_31 [ 4 ] = ( V_30 >> 24 ) & 0xff ;
V_31 [ 5 ] = ( V_30 >> 16 ) & 0xff ;
V_31 [ 6 ] = ( V_30 >> 8 ) & 0xff ;
V_31 [ 7 ] = ( V_30 >> 0 ) & 0xff ;
F_11 ( V_2 , V_31 , 8 , V_4 , & V_28 , & V_26 , V_22 ) ;
return V_20 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = 0 ;
T_1 * V_38 = V_4 -> V_8 ;
T_2 V_39 = ( ( V_38 [ 2 ] << 24 ) & 0xff000000 ) |
( ( V_38 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_38 [ 4 ] << 8 ) & 0x0000ff00 ) |
( ( V_38 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_40 = ( ( V_38 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_38 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_41 = V_40 * 0x200 ;
void * V_31 ;
if ( V_39 > V_2 -> V_29 )
return V_42 ;
V_31 = F_12 ( V_41 , V_43 ) ;
if ( V_31 == NULL )
return V_42 ;
V_5 = F_13 ( V_2 , V_39 , V_40 , V_31 ) ;
F_9 ( V_2 , V_31 , V_41 , V_4 , V_22 ) ;
F_14 ( V_31 ) ;
if ( ! V_5 )
return V_20 ;
else
return V_42 ;
return V_20 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = 0 ;
T_1 * V_38 = V_4 -> V_8 ;
T_2 V_39 = ( ( V_38 [ 2 ] << 24 ) & 0xff000000 ) |
( ( V_38 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_38 [ 4 ] << 8 ) & 0x0000ff00 ) |
( ( V_38 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_40 = ( ( V_38 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_38 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_41 = V_40 * 0x200 ;
void * V_31 ;
if ( V_39 > V_2 -> V_29 )
return V_42 ;
V_31 = F_12 ( V_41 , V_43 ) ;
if ( V_31 == NULL )
return V_42 ;
F_9 ( V_2 , V_31 , V_41 , V_4 , V_44 ) ;
V_5 = F_15 ( V_2 , V_39 , V_40 , V_31 ) ;
F_14 ( V_31 ) ;
if ( ! V_5 )
return V_20 ;
else
return V_42 ;
return V_20 ;
}
