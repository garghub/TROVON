int F_1 ( struct V_1 * V_2 , unsigned int * V_3 )
{
int V_4 = V_5 ;
unsigned int V_6 = 0 ;
int V_7 ;
F_2 ( V_2 , V_8 , V_9 , V_10 , L_1 , F_3 ( * V_3 ) ) ;
if( F_3 ( * V_3 ) == V_11 )
{
F_2 ( V_2 , V_8 , V_9 , V_10 , L_2 ) ;
if( F_3 ( * ( V_3 + 1 ) ) == 0 )
{
F_2 ( V_2 , V_8 , V_9 , V_10 , L_3 ) ;
V_4 = F_4 ( V_2 , V_12 , & V_6 , sizeof( V_6 ) ) ;
if( V_4 )
{
F_2 ( V_2 , V_13 , 0 , 0 , L_4 ) ;
return V_4 ;
}
if( V_2 -> V_14 == V_15 )
{
V_6 = 0x00000000 ;
V_4 = F_4 ( V_2 , V_16 , & V_6 , sizeof( V_6 ) ) ;
if( V_4 )
{
F_2 ( V_2 , V_13 , 0 , 0 , L_5 ) ;
return V_4 ;
}
}
else if( V_2 -> V_14 != V_17 )
{
V_7 = F_5 ( V_2 , V_18 , & V_6 , sizeof( V_6 ) ) ;
if ( V_7 < 0 ) {
V_4 = V_7 ;
F_2 ( V_2 , V_13 , 0 , 0 , L_6 ) ;
return V_4 ;
}
V_7 = F_5 ( V_2 , V_19 , & V_6 , sizeof( V_6 ) ) ;
if ( V_7 < 0 ) {
V_4 = V_7 ;
F_2 ( V_2 , V_13 , 0 , 0 , L_7 ) ;
return V_4 ;
}
}
F_2 ( V_2 , V_8 , V_9 , V_10 , L_8 ) ;
V_2 -> V_20 = FALSE ;
V_2 -> V_21 = FALSE ;
F_6 ( & V_2 -> V_22 ) ;
}
else
{
if( TRUE == V_2 -> V_20 )
{
F_2 ( V_2 , V_8 , V_9 , V_10 , L_9 ) ;
return V_4 ;
}
V_6 = 0 ;
F_2 ( V_2 , V_8 , V_9 , V_10 , L_10 ) ;
if ( V_2 -> V_23 == V_24 ||
V_2 -> V_23 == V_25 ||
V_2 -> V_23 == V_26 ||
V_2 -> V_23 == V_27 )
{
V_7 = F_5 ( V_2 , V_28 , & V_6 , sizeof( V_6 ) ) ;
if ( V_7 < 0 ) {
V_4 = V_7 ;
F_2 ( V_2 , V_8 , V_9 , V_10 , L_11 ) ;
return V_4 ;
}
V_6 |= ( 1 << 17 ) ;
V_4 = F_4 ( V_2 , V_28 , & V_6 , sizeof( V_6 ) ) ;
if( V_4 )
{
F_2 ( V_2 , V_13 , 0 , 0 , L_12 ) ;
return V_4 ;
}
}
F_7 ( V_2 ) ;
}
}
else if( F_3 ( * V_3 ) == V_29 )
{
F_2 ( V_2 , V_8 , V_9 , V_10 , L_13 ) ;
F_8 ( V_2 , V_3 ) ;
}
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_30 )
{
int V_4 = V_5 ;
unsigned int V_31 ;
unsigned int V_23 ;
unsigned long V_32 = 0 , V_33 = 0 ;
int V_34 = 0 ;
unsigned char V_35 [ 8 ] = { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF } ;
T_1 V_36 = V_2 -> V_37 ;
if( ( TRUE == V_36 -> V_38 ) && ( TRUE == V_2 -> V_39 ) )
{
V_4 = F_10 ( V_36 -> V_40 ) ;
F_2 ( V_2 , V_8 , V_9 , V_10 , L_14 , V_4 ) ;
}
if( ( V_2 -> V_14 == V_15 )
||
( V_2 -> V_14 == V_17 ) )
{
F_2 ( V_2 , V_8 , V_9 , V_10 , L_15 , V_30 ) ;
V_4 = F_4 ( V_2 , V_12 , & V_30 , sizeof( V_30 ) ) ;
if( V_4 )
{
F_2 ( V_2 , V_8 , V_9 , V_10 , L_16 ) ;
return V_4 ;
}
}
if( V_2 -> V_14 == V_15 )
{
V_31 = 0x80000000 ;
V_4 = F_4 ( V_2 , V_16 , & V_31 , sizeof( V_31 ) ) ;
if( V_4 )
{
F_2 ( V_2 , V_8 , V_9 , V_10 , L_17 ) ;
return V_4 ;
}
}
else if( V_2 -> V_14 != V_17 )
{
V_4 = F_11 ( V_36 -> V_41 ,
F_12 ( V_36 -> V_41 ,
V_36 -> V_42 . V_43 ) ,
V_35 ,
8 ,
& V_34 ,
5000 ) ;
if( V_4 )
{
F_2 ( V_2 , V_8 , V_9 , V_10 , L_18 , V_4 ) ;
return V_4 ;
}
else
{
F_2 ( V_2 , V_8 , V_9 , V_10 , L_19 , V_34 ) ;
}
V_32 = V_44 + F_13 ( 50 ) ;
while( V_32 > V_44 )
{
V_33 ++ ;
F_5 ( V_2 , V_45 , & V_23 , sizeof( V_46 ) ) ;
if( 0xbece3200 == ( V_23 & ~ ( 0xF0 ) ) )
{
V_23 = V_23 & ~ ( 0xF0 ) ;
}
if( V_23 == V_2 -> V_23 )
break;
}
if( V_32 < V_44 )
{
F_2 ( V_2 , V_8 , V_9 , V_10 , L_20 ) ;
}
else
{
F_2 ( V_2 , V_8 , V_9 , V_10 , L_21 , V_33 ) ;
}
V_4 = F_4 ( V_2 , V_12 , & V_30 , sizeof( V_4 ) ) ;
if( V_4 )
{
F_2 ( V_2 , V_13 , 0 , 0 , L_16 ) ;
return V_4 ;
}
}
return V_4 ;
}
int F_14 ( struct V_1 * V_2 )
{
T_2 V_47 = 0 ;
if( V_2 -> V_21 )
{
F_2 ( V_2 , V_8 , V_9 , V_10 , L_22 ) ;
}
else
{
F_2 ( V_2 , V_8 , V_9 , V_10 , L_23 ) ;
V_2 -> V_21 = TRUE ;
F_9 ( V_2 , V_2 -> V_48 ) ;
}
return V_47 ;
}
void F_15 ( struct V_1 * V_2 )
{
unsigned int V_49 = 0 ;
INT V_47 = 0 ;
int V_7 ;
if( V_2 -> V_14 == V_15 )
{
V_49 = 0 ;
V_47 = F_4 ( V_2 , V_16 , & V_49 , sizeof( V_49 ) ) ;
if( V_47 )
{
F_2 ( V_2 , V_13 , 0 , 0 , L_24 , V_47 ) ;
return;
}
}
else
{
V_7 = F_5 ( V_2 , V_18 , & V_49 , sizeof( V_49 ) ) ;
if ( V_7 < 0 ) {
V_47 = V_7 ;
F_2 ( V_2 , V_13 , 0 , 0 , L_25 , V_47 ) ;
return;
}
V_7 = F_5 ( V_2 , V_19 , & V_49 , sizeof( V_49 ) ) ;
if ( V_7 < 0 ) {
V_47 = V_7 ;
F_2 ( V_2 , V_13 , 0 , 0 , L_26 , V_47 ) ;
return;
}
}
}
