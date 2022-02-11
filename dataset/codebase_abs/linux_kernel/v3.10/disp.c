T_1
F_1 ( struct V_1 * V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 , T_2 * V_7 )
{
struct V_8 V_9 ;
if ( ! V_8 ( V_2 , 'U' , & V_9 ) ) {
if ( V_9 . V_10 == 1 ) {
T_1 V_11 = F_2 ( V_2 , V_9 . V_12 ) ;
if ( V_11 ) {
* V_3 = F_3 ( V_2 , V_11 + 0x00 ) ;
switch ( * V_3 ) {
case 0x20 :
case 0x21 :
* V_4 = F_3 ( V_2 , V_11 + 0x01 ) ;
* V_6 = F_3 ( V_2 , V_11 + 0x02 ) ;
* V_5 = F_3 ( V_2 , V_11 + 0x03 ) ;
* V_7 = F_3 ( V_2 , V_11 + 0x04 ) ;
return V_11 ;
default:
break;
}
}
}
}
return 0x0000 ;
}
T_1
F_4 ( struct V_1 * V_2 , T_2 V_13 ,
T_2 * V_3 , T_2 * V_6 , T_2 * V_7 )
{
T_2 V_4 , V_5 ;
T_1 V_11 = F_1 ( V_2 , V_3 , & V_4 , & V_5 , V_6 , V_7 ) ;
if ( V_11 && V_13 < V_5 )
return V_11 + V_4 + ( V_13 * * V_6 ) ;
* V_3 = 0x00 ;
return 0x0000 ;
}
T_1
F_5 ( struct V_1 * V_2 , T_2 V_13 ,
T_2 * V_3 , T_2 * V_6 , T_2 * V_7 ,
struct V_14 * V_15 )
{
T_1 V_11 = F_4 ( V_2 , V_13 , V_3 , V_6 , V_7 ) ;
if ( V_11 && * V_6 >= 2 ) {
V_15 -> V_11 = F_2 ( V_2 , V_11 + 0 ) ;
return V_11 ;
}
return 0x0000 ;
}
T_1
F_6 ( struct V_1 * V_2 , T_2 V_13 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
struct V_14 V_15 ;
T_1 V_11 = F_5 ( V_2 , V_13 , V_3 , V_6 , V_4 , & V_15 ) ;
if ( V_11 ) {
* V_5 = F_3 ( V_2 , V_15 . V_11 + 0x05 ) ;
* V_6 = 0x06 ;
V_11 = V_15 . V_11 ;
}
return V_11 ;
}
T_1
F_7 ( struct V_1 * V_2 , T_2 V_13 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 ,
struct V_16 * V_15 )
{
T_1 V_11 = F_6 ( V_2 , V_13 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_11 && * V_4 >= 0x0a ) {
V_15 -> type = F_2 ( V_2 , V_11 + 0x00 ) ;
V_15 -> V_17 = F_8 ( V_2 , V_11 + 0x02 ) ;
if ( * V_3 <= 0x20 )
V_15 -> V_17 |= 0x00c0 ;
V_15 -> V_18 [ 0 ] = F_2 ( V_2 , V_11 + 0x06 ) ;
V_15 -> V_18 [ 1 ] = F_2 ( V_2 , V_11 + 0x08 ) ;
V_15 -> V_18 [ 2 ] = 0x0000 ;
if ( * V_4 >= 0x0c )
V_15 -> V_18 [ 2 ] = F_2 ( V_2 , V_11 + 0x0a ) ;
return V_11 ;
}
return 0x0000 ;
}
T_1
F_9 ( struct V_1 * V_2 , T_1 type , T_1 V_17 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 ,
struct V_16 * V_15 )
{
T_1 V_11 , V_13 = 0 ;
while ( ( V_11 = F_7 ( V_2 , V_13 ++ , V_3 , V_4 , V_5 , V_6 , V_15 ) ) || * V_3 ) {
if ( V_11 && V_15 -> type == type ) {
if ( ( V_15 -> V_17 & V_17 ) == V_17 )
break;
}
}
return V_11 ;
}
T_1
F_10 ( struct V_1 * V_2 , T_1 V_19 , T_2 V_13 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
if ( V_13 < * V_5 )
return V_19 + * V_4 + ( V_13 * * V_6 ) ;
return 0x0000 ;
}
T_1
F_11 ( struct V_1 * V_2 , T_1 V_19 , T_2 V_13 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 ,
struct V_20 * V_15 )
{
T_1 V_11 = F_10 ( V_2 , V_19 , V_13 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_11 ) {
V_15 -> V_21 = F_2 ( V_2 , V_11 + 0x00 ) ;
V_15 -> V_22 [ 0 ] = F_2 ( V_2 , V_11 + 0x02 ) ;
V_15 -> V_22 [ 1 ] = F_2 ( V_2 , V_11 + 0x04 ) ;
}
return V_11 ;
}
T_1
F_12 ( struct V_1 * V_2 , T_1 V_19 , T_1 type ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 ,
struct V_20 * V_15 )
{
T_1 V_11 , V_13 = 0 ;
while ( ( V_11 = F_11 ( V_2 , V_19 , V_13 ++ , V_3 , V_4 , V_5 , V_6 , V_15 ) ) ) {
if ( V_15 -> V_21 == type )
break;
}
return V_11 ;
}
T_1
F_13 ( struct V_1 * V_2 , T_1 V_23 , T_3 V_24 )
{
while ( V_23 ) {
if ( V_24 / 10 >= F_2 ( V_2 , V_23 + 0x00 ) )
return F_2 ( V_2 , V_23 + 0x02 ) ;
V_23 += 0x04 ;
}
return 0x0000 ;
}
