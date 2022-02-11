static T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_2 exp ;
T_3 V_4 ;
if ( V_3 >= 0x80000000 ) {
F_2 ( & V_2 -> V_5 , L_1 ) ;
return 0 ;
}
if ( V_3 == 0x7f800000 )
return ~ 0 ;
if ( ( V_3 & 0x7f800000 ) == 0x7f800000 ) {
F_2 ( & V_2 -> V_5 , L_2 ) ;
return 0 ;
}
if ( V_3 == 0 )
return 0 ;
if ( V_3 > 0x4f800000 )
return ~ 0 ;
exp = ( ( T_2 ) V_3 >> 23 ) - 127 ;
V_4 = ( ( V_3 & 0x7fffff ) | 0x800000 ) * 1000000ULL ;
if ( exp < 0 )
V_4 >>= - exp ;
else
V_4 <<= exp ;
V_4 >>= 23 ;
return V_4 & 0xffffffff ;
}
static int F_3 ( struct V_6 * V_7 , T_4 V_8 ,
T_4 V_9 , T_5 * V_10 )
{
struct V_1 * V_2 = F_4 ( & V_7 -> V_11 -> V_12 ) ;
struct V_13 V_14 ;
unsigned char V_15 [ 4 ] ;
T_4 V_16 = V_8 ;
int V_17 ;
V_14 . V_18 = V_2 -> V_18 ;
V_14 . V_19 = 0 ;
V_14 . V_9 = 2 ;
V_14 . V_20 = V_15 ;
V_15 [ 0 ] = ( V_21 ) ( V_16 >> 8 ) ;
V_15 [ 1 ] = ( V_21 ) V_16 ;
V_17 = F_5 ( V_2 -> V_22 , & V_14 , 1 ) ;
if ( V_17 != 1 ) {
if ( V_17 >= 0 )
V_17 = - V_23 ;
goto V_24;
}
V_14 . V_9 = V_9 ;
V_14 . V_19 = V_25 ;
V_17 = F_5 ( V_2 -> V_22 , & V_14 , 1 ) ;
if ( V_17 != 1 ) {
if ( V_17 >= 0 )
V_17 = - V_23 ;
goto V_24;
}
* V_10 = 0 ;
switch ( V_9 ) {
case V_26 :
* V_10 = ( V_15 [ 0 ] << 24 ) + ( V_15 [ 1 ] << 16 ) + ( V_15 [ 2 ] << 8 ) +
V_15 [ 3 ] ;
break;
case V_27 :
* V_10 = ( V_15 [ 0 ] << 8 ) + V_15 [ 1 ] ;
break;
case V_28 :
* V_10 = V_15 [ 0 ] ;
break;
default:
F_6 () ;
}
return 0 ;
V_24:
F_2 ( & V_2 -> V_5 , L_3 , V_16 , V_17 ) ;
return V_17 ;
}
static int F_7 ( struct V_6 * V_7 , T_4 V_8 ,
T_4 V_9 , T_5 * V_10 )
{
unsigned int V_29 ;
int V_30 ;
* V_10 = 0 ;
for ( V_29 = 0 ; V_29 < V_9 ; V_29 ++ ) {
T_5 V_31 ;
V_30 = F_3 ( V_7 , V_8 + V_29 , 1 , & V_31 ) ;
if ( V_30 < 0 )
return V_30 ;
* V_10 |= V_31 << ( ( V_9 - V_29 - 1 ) << 3 ) ;
}
return 0 ;
}
static int F_8 ( struct V_6 * V_7 , T_5 V_8 , T_5 * V_10 ,
bool V_32 )
{
struct V_1 * V_2 = F_4 ( & V_7 -> V_11 -> V_12 ) ;
V_21 V_9 = F_9 ( V_8 ) ;
int V_30 ;
if ( V_9 != V_28 && V_9 != V_27
&& V_9 != V_26 )
return - V_33 ;
if ( V_9 == V_28 || ! V_32 )
V_30 = F_3 ( V_7 , F_10 ( V_8 ) , V_9 , V_10 ) ;
else
V_30 = F_7 ( V_7 , F_10 ( V_8 ) , V_9 ,
V_10 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_8 & V_34 )
* V_10 = F_1 ( V_2 , * V_10 ) ;
return 0 ;
}
int F_11 ( struct V_6 * V_7 , T_5 V_8 , T_5 * V_10 )
{
return F_8 (
V_7 , V_8 , V_10 ,
F_12 ( V_7 ,
V_35 ) ) ;
}
int F_13 ( struct V_6 * V_7 , T_5 V_8 , T_5 * V_10 )
{
int V_30 ;
* V_10 = 0 ;
V_30 = F_14 ( V_7 , V_36 , false , & V_8 , V_10 ) ;
if ( V_30 == - V_37 )
return 0 ;
if ( V_30 < 0 )
return V_30 ;
return F_11 ( V_7 , V_8 , V_10 ) ;
}
int F_15 ( struct V_6 * V_7 , T_5 V_8 , T_5 * V_10 )
{
int V_30 ;
* V_10 = 0 ;
V_30 = F_14 ( V_7 , V_36 , false , & V_8 , V_10 ) ;
if ( V_30 == - V_37 )
return 0 ;
if ( V_30 < 0 )
return V_30 ;
return F_8 ( V_7 , V_8 , V_10 , true ) ;
}
int F_16 ( struct V_6 * V_7 , T_5 V_8 , T_5 V_10 )
{
struct V_1 * V_2 = F_4 ( & V_7 -> V_11 -> V_12 ) ;
struct V_13 V_14 ;
unsigned char V_15 [ 6 ] ;
unsigned int V_38 ;
V_21 V_19 = F_17 ( V_8 ) ;
V_21 V_9 = F_9 ( V_8 ) ;
T_4 V_16 = F_10 ( V_8 ) ;
int V_17 ;
if ( ( V_9 != V_28 && V_9 != V_27 &&
V_9 != V_26 ) || V_19 )
return - V_33 ;
V_14 . V_18 = V_2 -> V_18 ;
V_14 . V_19 = 0 ;
V_14 . V_9 = 2 + V_9 ;
V_14 . V_20 = V_15 ;
V_15 [ 0 ] = ( V_21 ) ( V_8 >> 8 ) ;
V_15 [ 1 ] = ( V_21 ) ( V_8 & 0xff ) ;
switch ( V_9 ) {
case V_28 :
V_15 [ 2 ] = V_10 ;
break;
case V_27 :
V_15 [ 2 ] = V_10 >> 8 ;
V_15 [ 3 ] = V_10 ;
break;
case V_26 :
V_15 [ 2 ] = V_10 >> 24 ;
V_15 [ 3 ] = V_10 >> 16 ;
V_15 [ 4 ] = V_10 >> 8 ;
V_15 [ 5 ] = V_10 ;
break;
default:
F_6 () ;
}
for ( V_38 = 0 ; V_38 < 5 ; V_38 ++ ) {
V_17 = F_5 ( V_2 -> V_22 , & V_14 , 1 ) ;
if ( V_17 == 1 ) {
if ( V_38 )
F_2 ( & V_2 -> V_5 ,
L_4
L_5 , V_38 ) ;
return 0 ;
}
F_18 ( 2000 , 2000 ) ;
}
F_2 ( & V_2 -> V_5 ,
L_6 , V_10 , V_16 , V_17 ) ;
return V_17 ;
}
int F_19 ( struct V_6 * V_7 , T_5 V_8 , T_5 V_10 )
{
int V_30 ;
V_30 = F_14 ( V_7 , V_36 , true , & V_8 , & V_10 ) ;
if ( V_30 == - V_37 )
return 0 ;
if ( V_30 < 0 )
return V_30 ;
return F_16 ( V_7 , V_8 , V_10 ) ;
}
