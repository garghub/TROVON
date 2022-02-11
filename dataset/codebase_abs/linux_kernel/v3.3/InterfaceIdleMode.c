int F_1 ( T_1 V_1 , unsigned int * V_2 )
{
int V_3 = V_4 ;
unsigned int V_5 = 0 ;
int V_6 ;
F_2 ( V_1 , V_7 , V_8 , V_9 , L_1 , F_3 ( * V_2 ) ) ;
if( F_3 ( * V_2 ) == V_10 )
{
F_2 ( V_1 , V_7 , V_8 , V_9 , L_2 ) ;
if( F_3 ( * ( V_2 + 1 ) ) == 0 )
{
F_2 ( V_1 , V_7 , V_8 , V_9 , L_3 ) ;
V_3 = F_4 ( V_1 , V_11 , & V_5 , sizeof( V_5 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_12 , 0 , 0 , L_4 ) ;
return V_3 ;
}
if( V_1 -> V_13 == V_14 )
{
V_5 = 0x00000000 ;
V_3 = F_4 ( V_1 , V_15 , & V_5 , sizeof( V_5 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_12 , 0 , 0 , L_5 ) ;
return V_3 ;
}
}
else if( V_1 -> V_13 != V_16 )
{
V_6 = F_5 ( V_1 , V_17 , & V_5 , sizeof( V_5 ) ) ;
if ( V_6 < 0 ) {
V_3 = V_6 ;
F_2 ( V_1 , V_12 , 0 , 0 , L_6 ) ;
return V_3 ;
}
V_6 = F_5 ( V_1 , V_18 , & V_5 , sizeof( V_5 ) ) ;
if ( V_6 < 0 ) {
V_3 = V_6 ;
F_2 ( V_1 , V_12 , 0 , 0 , L_7 ) ;
return V_3 ;
}
}
F_2 ( V_1 , V_7 , V_8 , V_9 , L_8 ) ;
V_1 -> V_19 = FALSE ;
V_1 -> V_20 = FALSE ;
F_6 ( & V_1 -> V_21 ) ;
}
else
{
if( TRUE == V_1 -> V_19 )
{
F_2 ( V_1 , V_7 , V_8 , V_9 , L_9 ) ;
return V_3 ;
}
V_5 = 0 ;
F_2 ( V_1 , V_7 , V_8 , V_9 , L_10 ) ;
if ( V_1 -> V_22 == V_23 ||
V_1 -> V_22 == V_24 ||
V_1 -> V_22 == V_25 ||
V_1 -> V_22 == V_26 )
{
V_6 = F_5 ( V_1 , V_27 , & V_5 , sizeof( V_5 ) ) ;
if ( V_6 < 0 ) {
V_3 = V_6 ;
F_2 ( V_1 , V_7 , V_8 , V_9 , L_11 ) ;
return V_3 ;
}
V_5 |= ( 1 << 17 ) ;
V_3 = F_4 ( V_1 , V_27 , & V_5 , sizeof( V_5 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_12 , 0 , 0 , L_12 ) ;
return V_3 ;
}
}
F_7 ( V_1 ) ;
}
}
else if( F_3 ( * V_2 ) == V_28 )
{
F_2 ( V_1 , V_7 , V_8 , V_9 , L_13 ) ;
F_8 ( V_1 , V_2 ) ;
}
return V_3 ;
}
static int F_9 ( T_1 V_1 , unsigned int V_29 )
{
int V_3 = V_4 ;
unsigned int V_30 ;
unsigned int V_22 ;
unsigned long V_31 = 0 , V_32 = 0 ;
int V_33 = 0 ;
unsigned char V_34 [ 8 ] = { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF } ;
T_2 V_35 = V_1 -> V_36 ;
if( ( TRUE == V_35 -> V_37 ) && ( TRUE == V_1 -> V_38 ) )
{
V_3 = F_10 ( V_35 -> V_39 ) ;
F_2 ( V_1 , V_7 , V_8 , V_9 , L_14 , V_3 ) ;
}
if( ( V_1 -> V_13 == V_14 )
||
( V_1 -> V_13 == V_16 ) )
{
F_2 ( V_1 , V_7 , V_8 , V_9 , L_15 , V_29 ) ;
V_3 = F_4 ( V_1 , V_11 , & V_29 , sizeof( V_29 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_7 , V_8 , V_9 , L_16 ) ;
return V_3 ;
}
}
if( V_1 -> V_13 == V_14 )
{
V_30 = 0x80000000 ;
V_3 = F_4 ( V_1 , V_15 , & V_30 , sizeof( V_30 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_7 , V_8 , V_9 , L_17 ) ;
return V_3 ;
}
}
else if( V_1 -> V_13 != V_16 )
{
V_3 = F_11 ( V_35 -> V_40 ,
F_12 ( V_35 -> V_40 ,
V_35 -> V_41 . V_42 ) ,
V_34 ,
8 ,
& V_33 ,
5000 ) ;
if( V_3 )
{
F_2 ( V_1 , V_7 , V_8 , V_9 , L_18 , V_3 ) ;
return V_3 ;
}
else
{
F_2 ( V_1 , V_7 , V_8 , V_9 , L_19 , V_33 ) ;
}
V_31 = V_43 + F_13 ( 50 ) ;
while( V_31 > V_43 )
{
V_32 ++ ;
F_5 ( V_1 , V_44 , & V_22 , sizeof( V_45 ) ) ;
if( 0xbece3200 == ( V_22 & ~ ( 0xF0 ) ) )
{
V_22 = V_22 & ~ ( 0xF0 ) ;
}
if( V_22 == V_1 -> V_22 )
break;
}
if( V_31 < V_43 )
{
F_2 ( V_1 , V_7 , V_8 , V_9 , L_20 ) ;
}
else
{
F_2 ( V_1 , V_7 , V_8 , V_9 , L_21 , V_32 ) ;
}
V_3 = F_4 ( V_1 , V_11 , & V_29 , sizeof( V_3 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_12 , 0 , 0 , L_16 ) ;
return V_3 ;
}
}
return V_3 ;
}
int F_14 ( T_1 V_1 )
{
T_3 V_46 = 0 ;
if( V_1 -> V_20 )
{
F_2 ( V_1 , V_7 , V_8 , V_9 , L_22 ) ;
}
else
{
F_2 ( V_1 , V_7 , V_8 , V_9 , L_23 ) ;
V_1 -> V_20 = TRUE ;
F_9 ( V_1 , V_1 -> V_47 ) ;
}
return V_46 ;
}
void F_15 ( T_1 V_1 )
{
unsigned int V_48 = 0 ;
INT V_46 = 0 ;
int V_6 ;
if( V_1 -> V_13 == V_14 )
{
V_48 = 0 ;
V_46 = F_4 ( V_1 , V_15 , & V_48 , sizeof( V_48 ) ) ;
if( V_46 )
{
F_2 ( V_1 , V_12 , 0 , 0 , L_24 , V_46 ) ;
return;
}
}
else
{
V_6 = F_5 ( V_1 , V_17 , & V_48 , sizeof( V_48 ) ) ;
if ( V_6 < 0 ) {
V_46 = V_6 ;
F_2 ( V_1 , V_12 , 0 , 0 , L_25 , V_46 ) ;
return;
}
V_6 = F_5 ( V_1 , V_18 , & V_48 , sizeof( V_48 ) ) ;
if ( V_6 < 0 ) {
V_46 = V_6 ;
F_2 ( V_1 , V_12 , 0 , 0 , L_26 , V_46 ) ;
return;
}
}
}
