int F_1 ( T_1 V_1 , unsigned int * V_2 )
{
int V_3 = V_4 ;
unsigned int V_5 = 0 ;
F_2 ( V_1 , V_6 , V_7 , V_8 , L_1 , F_3 ( * V_2 ) ) ;
if( F_3 ( * V_2 ) == V_9 )
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_2 ) ;
if( F_3 ( * ( V_2 + 1 ) ) == 0 )
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_3 ) ;
V_3 = F_4 ( V_1 , V_10 , & V_5 , sizeof( V_5 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_11 , 0 , 0 , L_4 ) ;
return V_3 ;
}
if( V_1 -> V_12 == V_13 )
{
V_5 = 0x00000000 ;
V_3 = F_4 ( V_1 , V_14 , & V_5 , sizeof( V_5 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_11 , 0 , 0 , L_5 ) ;
return V_3 ;
}
}
else if( V_1 -> V_12 != V_15 )
{
V_3 = F_5 ( V_1 , V_16 , & V_5 , sizeof( V_5 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_11 , 0 , 0 , L_6 ) ;
return V_3 ;
}
V_3 = F_5 ( V_1 , V_17 , & V_5 , sizeof( V_5 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_11 , 0 , 0 , L_7 ) ;
return V_3 ;
}
}
F_2 ( V_1 , V_6 , V_7 , V_8 , L_8 ) ;
V_1 -> V_18 = FALSE ;
V_1 -> V_19 = FALSE ;
F_6 ( & V_1 -> V_20 ) ;
}
else
{
if( TRUE == V_1 -> V_18 )
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_9 ) ;
return V_3 ;
}
V_5 = 0 ;
F_2 ( V_1 , V_6 , V_7 , V_8 , L_10 ) ;
if ( V_1 -> V_21 == V_22 ||
V_1 -> V_21 == V_23 ||
V_1 -> V_21 == V_24 ||
V_1 -> V_21 == V_25 )
{
V_3 = F_5 ( V_1 , V_26 , & V_5 , sizeof( V_5 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_11 ) ;
return V_3 ;
}
V_5 |= ( 1 << 17 ) ;
V_3 = F_4 ( V_1 , V_26 , & V_5 , sizeof( V_5 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_11 , 0 , 0 , L_12 ) ;
return V_3 ;
}
}
F_7 ( V_1 ) ;
}
}
else if( F_3 ( * V_2 ) == V_27 )
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_13 ) ;
F_8 ( V_1 , V_2 ) ;
}
return V_3 ;
}
static int F_9 ( T_1 V_1 , unsigned int V_28 )
{
int V_3 = V_4 ;
unsigned int V_29 ;
unsigned int V_21 ;
unsigned long V_30 = 0 , V_31 = 0 ;
int V_32 = 0 ;
unsigned char V_33 [ 8 ] = { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF } ;
T_2 V_34 = V_1 -> V_35 ;
if( ( TRUE == V_34 -> V_36 ) && ( TRUE == V_1 -> V_37 ) )
{
V_3 = F_10 ( V_34 -> V_38 ) ;
F_2 ( V_1 , V_6 , V_7 , V_8 , L_14 , V_3 ) ;
}
if( ( V_1 -> V_12 == V_13 )
||
( V_1 -> V_12 == V_15 ) )
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_15 , V_28 ) ;
V_3 = F_4 ( V_1 , V_10 , & V_28 , sizeof( V_28 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_16 ) ;
return V_3 ;
}
}
if( V_1 -> V_12 == V_13 )
{
V_29 = 0x80000000 ;
V_3 = F_4 ( V_1 , V_14 , & V_29 , sizeof( V_29 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_17 ) ;
return V_3 ;
}
}
else if( V_1 -> V_12 != V_15 )
{
V_3 = F_11 ( V_34 -> V_39 ,
F_12 ( V_34 -> V_39 ,
V_34 -> V_40 . V_41 ) ,
V_33 ,
8 ,
& V_32 ,
5000 ) ;
if( V_3 )
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_18 , V_3 ) ;
return V_3 ;
}
else
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_19 , V_32 ) ;
}
V_30 = V_42 + F_13 ( 50 ) ;
while( V_30 > V_42 )
{
V_31 ++ ;
F_5 ( V_1 , V_43 , & V_21 , sizeof( V_44 ) ) ;
if( 0xbece3200 == ( V_21 & ~ ( 0xF0 ) ) )
{
V_21 = V_21 & ~ ( 0xF0 ) ;
}
if( V_21 == V_1 -> V_21 )
break;
}
if( V_30 < V_42 )
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_20 ) ;
}
else
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_21 , V_31 ) ;
}
V_3 = F_4 ( V_1 , V_10 , & V_28 , sizeof( V_3 ) ) ;
if( V_3 )
{
F_2 ( V_1 , V_11 , 0 , 0 , L_16 ) ;
return V_3 ;
}
}
return V_3 ;
}
int F_14 ( T_1 V_1 )
{
T_3 V_45 = 0 ;
if( V_1 -> V_19 )
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_22 ) ;
}
else
{
F_2 ( V_1 , V_6 , V_7 , V_8 , L_23 ) ;
V_1 -> V_19 = TRUE ;
F_9 ( V_1 , V_1 -> V_46 ) ;
}
return V_45 ;
}
void F_15 ( T_1 V_1 )
{
unsigned int V_47 = 0 ;
INT V_45 = 0 ;
if( V_1 -> V_12 == V_13 )
{
V_47 = 0 ;
V_45 = F_4 ( V_1 , V_14 , & V_47 , sizeof( V_47 ) ) ;
if( V_45 )
{
F_2 ( V_1 , V_11 , 0 , 0 , L_24 , V_45 ) ;
return;
}
}
else
{
V_45 = F_5 ( V_1 , V_16 , & V_47 , sizeof( V_47 ) ) ;
if( V_45 )
{
F_2 ( V_1 , V_11 , 0 , 0 , L_25 , V_45 ) ;
return;
}
V_45 = F_5 ( V_1 , V_17 , & V_47 , sizeof( V_47 ) ) ;
if( V_45 )
{
F_2 ( V_1 , V_11 , 0 , 0 , L_26 , V_45 ) ;
return;
}
}
}
