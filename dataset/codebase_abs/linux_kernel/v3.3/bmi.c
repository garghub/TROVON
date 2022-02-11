int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 = V_5 ;
if ( V_2 -> V_6 . V_7 ) {
F_2 ( V_8 , L_1 ) ;
return 0 ;
}
V_2 -> V_6 . V_7 = true ;
V_3 = F_3 ( V_2 , ( V_9 * ) & V_4 , sizeof( V_4 ) ) ;
if ( V_3 ) {
F_4 ( L_2 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_3 ;
T_1 V_4 = V_12 ;
if ( V_2 -> V_6 . V_7 ) {
F_4 ( L_3 , V_4 ) ;
return - V_13 ;
}
V_3 = F_3 ( V_2 , ( V_9 * ) & V_4 , sizeof( V_4 ) ) ;
if ( V_3 ) {
F_4 ( L_4 , V_3 ) ;
return V_3 ;
}
V_3 = F_6 ( V_2 , ( V_9 * ) & V_11 -> V_14 ,
sizeof( V_11 -> V_14 ) ) ;
if ( V_3 ) {
F_4 ( L_5 , V_3 ) ;
return V_3 ;
}
if ( F_7 ( V_11 -> V_14 ) == V_15 ) {
V_3 = F_6 ( V_2 ,
( V_9 * ) & V_11 -> V_16 ,
sizeof( V_11 -> V_16 ) ) ;
if ( V_3 ) {
F_4 ( L_6 ,
V_3 ) ;
return V_3 ;
}
if ( F_7 ( V_11 -> V_16 ) != sizeof( * V_11 ) ) {
F_8 ( 1 ) ;
return - V_17 ;
}
V_3 = F_6 ( V_2 ,
( ( V_9 * ) V_11 ) +
sizeof( V_11 -> V_16 ) ,
sizeof( * V_11 ) -
sizeof( V_11 -> V_16 ) ) ;
if ( V_3 ) {
F_4 ( L_7 ,
V_11 -> V_16 , V_3 ) ;
return V_3 ;
}
}
F_2 ( V_8 , L_8 ,
V_11 -> V_14 , V_11 -> type ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_18 , V_9 * V_19 , T_1 V_20 )
{
T_1 V_4 = V_21 ;
int V_3 ;
T_1 V_22 ;
T_1 V_23 , V_24 ;
T_2 V_25 ;
if ( V_2 -> V_6 . V_7 ) {
F_4 ( L_3 , V_4 ) ;
return - V_13 ;
}
V_25 = V_2 -> V_6 . V_26 + sizeof( V_4 ) + sizeof( V_18 ) + sizeof( V_20 ) ;
if ( V_25 > V_2 -> V_6 . V_27 ) {
F_8 ( 1 ) ;
return - V_17 ;
}
memset ( V_2 -> V_6 . V_28 , 0 , V_25 ) ;
F_2 ( V_8 ,
L_9 ,
V_18 , V_20 ) ;
V_23 = V_20 ;
while ( V_23 ) {
V_24 = ( V_23 < V_2 -> V_6 . V_26 ) ?
V_23 : V_2 -> V_6 . V_26 ;
V_22 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_4 , sizeof( V_4 ) ) ;
V_22 += sizeof( V_4 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_18 , sizeof( V_18 ) ) ;
V_22 += sizeof( V_18 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_22 += sizeof( V_20 ) ;
V_3 = F_3 ( V_2 , V_2 -> V_6 . V_28 , V_22 ) ;
if ( V_3 ) {
F_4 ( L_10 ,
V_3 ) ;
return V_3 ;
}
V_3 = F_6 ( V_2 , V_2 -> V_6 . V_28 , V_24 ) ;
if ( V_3 ) {
F_4 ( L_11 ,
V_3 ) ;
return V_3 ;
}
memcpy ( & V_19 [ V_20 - V_23 ] , V_2 -> V_6 . V_28 , V_24 ) ;
V_23 -= V_24 ; V_18 += V_24 ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_18 , V_9 * V_19 , T_1 V_20 )
{
T_1 V_4 = V_29 ;
int V_3 ;
T_1 V_22 ;
T_1 V_23 , V_30 ;
const T_1 V_31 = sizeof( V_4 ) + sizeof( V_18 ) + sizeof( V_20 ) ;
V_9 V_32 [ 400 ] ;
V_9 * V_33 ;
if ( V_2 -> V_6 . V_7 ) {
F_4 ( L_3 , V_4 ) ;
return - V_13 ;
}
if ( ( V_2 -> V_6 . V_26 + V_31 ) > V_2 -> V_6 . V_27 ) {
F_8 ( 1 ) ;
return - V_17 ;
}
if ( F_8 ( V_2 -> V_6 . V_26 > sizeof( V_32 ) ) )
return - V_34 ;
memset ( V_2 -> V_6 . V_28 , 0 , V_2 -> V_6 . V_26 + V_31 ) ;
F_2 ( V_8 ,
L_12 , V_18 , V_20 ) ;
V_23 = V_20 ;
while ( V_23 ) {
V_33 = & V_19 [ V_20 - V_23 ] ;
if ( V_23 < ( V_2 -> V_6 . V_26 - V_31 ) ) {
if ( V_23 & 3 ) {
V_23 = V_23 +
( 4 - ( V_23 & 3 ) ) ;
memcpy ( V_32 , V_33 , V_23 ) ;
V_33 = V_32 ;
}
V_30 = V_23 ;
} else {
V_30 = ( V_2 -> V_6 . V_26 - V_31 ) ;
}
V_22 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_4 , sizeof( V_4 ) ) ;
V_22 += sizeof( V_4 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_18 , sizeof( V_18 ) ) ;
V_22 += sizeof( V_18 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_30 , sizeof( V_30 ) ) ;
V_22 += sizeof( V_30 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , V_33 , V_30 ) ;
V_22 += V_30 ;
V_3 = F_3 ( V_2 , V_2 -> V_6 . V_28 , V_22 ) ;
if ( V_3 ) {
F_4 ( L_10 ,
V_3 ) ;
return V_3 ;
}
V_23 -= V_30 ; V_18 += V_30 ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 , T_1 V_18 , T_1 * V_35 )
{
T_1 V_4 = V_36 ;
int V_3 ;
T_1 V_22 ;
T_2 V_25 ;
if ( V_2 -> V_6 . V_7 ) {
F_4 ( L_3 , V_4 ) ;
return - V_13 ;
}
V_25 = sizeof( V_4 ) + sizeof( V_18 ) + sizeof( V_35 ) ;
if ( V_25 > V_2 -> V_6 . V_27 ) {
F_8 ( 1 ) ;
return - V_17 ;
}
memset ( V_2 -> V_6 . V_28 , 0 , V_25 ) ;
F_2 ( V_8 , L_13 ,
V_18 , * V_35 ) ;
V_22 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_4 , sizeof( V_4 ) ) ;
V_22 += sizeof( V_4 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_18 , sizeof( V_18 ) ) ;
V_22 += sizeof( V_18 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , V_35 , sizeof( * V_35 ) ) ;
V_22 += sizeof( * V_35 ) ;
V_3 = F_3 ( V_2 , V_2 -> V_6 . V_28 , V_22 ) ;
if ( V_3 ) {
F_4 ( L_10 , V_3 ) ;
return V_3 ;
}
V_3 = F_6 ( V_2 , V_2 -> V_6 . V_28 , sizeof( * V_35 ) ) ;
if ( V_3 ) {
F_4 ( L_11 , V_3 ) ;
return V_3 ;
}
memcpy ( V_35 , V_2 -> V_6 . V_28 , sizeof( * V_35 ) ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_18 )
{
T_1 V_4 = V_37 ;
int V_3 ;
T_1 V_22 ;
T_2 V_25 ;
if ( V_2 -> V_6 . V_7 ) {
F_4 ( L_3 , V_4 ) ;
return - V_13 ;
}
V_25 = sizeof( V_4 ) + sizeof( V_18 ) ;
if ( V_25 > V_2 -> V_6 . V_27 ) {
F_8 ( 1 ) ;
return - V_17 ;
}
memset ( V_2 -> V_6 . V_28 , 0 , V_25 ) ;
F_2 ( V_8 , L_14 , V_18 ) ;
V_22 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_4 , sizeof( V_4 ) ) ;
V_22 += sizeof( V_4 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_18 , sizeof( V_18 ) ) ;
V_22 += sizeof( V_18 ) ;
V_3 = F_3 ( V_2 , V_2 -> V_6 . V_28 , V_22 ) ;
if ( V_3 ) {
F_4 ( L_10 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_18 , T_1 * V_35 )
{
T_1 V_4 = V_38 ;
int V_3 ;
T_1 V_22 ;
T_2 V_25 ;
if ( V_2 -> V_6 . V_7 ) {
F_4 ( L_3 , V_4 ) ;
return - V_13 ;
}
V_25 = sizeof( V_4 ) + sizeof( V_18 ) ;
if ( V_25 > V_2 -> V_6 . V_27 ) {
F_8 ( 1 ) ;
return - V_17 ;
}
memset ( V_2 -> V_6 . V_28 , 0 , V_25 ) ;
F_2 ( V_8 , L_15 , V_18 ) ;
V_22 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_4 , sizeof( V_4 ) ) ;
V_22 += sizeof( V_4 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_18 , sizeof( V_18 ) ) ;
V_22 += sizeof( V_18 ) ;
V_3 = F_3 ( V_2 , V_2 -> V_6 . V_28 , V_22 ) ;
if ( V_3 ) {
F_4 ( L_10 , V_3 ) ;
return V_3 ;
}
V_3 = F_6 ( V_2 , V_2 -> V_6 . V_28 , sizeof( * V_35 ) ) ;
if ( V_3 ) {
F_4 ( L_11 , V_3 ) ;
return V_3 ;
}
memcpy ( V_35 , V_2 -> V_6 . V_28 , sizeof( * V_35 ) ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_18 , T_1 V_35 )
{
T_1 V_4 = V_39 ;
int V_3 ;
T_1 V_22 ;
T_2 V_25 ;
if ( V_2 -> V_6 . V_7 ) {
F_4 ( L_3 , V_4 ) ;
return - V_13 ;
}
V_25 = sizeof( V_4 ) + sizeof( V_18 ) + sizeof( V_35 ) ;
if ( V_25 > V_2 -> V_6 . V_27 ) {
F_8 ( 1 ) ;
return - V_17 ;
}
memset ( V_2 -> V_6 . V_28 , 0 , V_25 ) ;
F_2 ( V_8 ,
L_16 ,
V_18 , V_35 ) ;
V_22 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_4 , sizeof( V_4 ) ) ;
V_22 += sizeof( V_4 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_18 , sizeof( V_18 ) ) ;
V_22 += sizeof( V_18 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_35 , sizeof( V_35 ) ) ;
V_22 += sizeof( V_35 ) ;
V_3 = F_3 ( V_2 , V_2 -> V_6 . V_28 , V_22 ) ;
if ( V_3 ) {
F_4 ( L_10 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 , V_9 * V_19 , T_1 V_20 )
{
T_1 V_4 = V_40 ;
int V_3 ;
T_1 V_22 ;
T_1 V_23 , V_30 ;
const T_1 V_31 = sizeof( V_4 ) + sizeof( V_20 ) ;
T_2 V_25 ;
if ( V_2 -> V_6 . V_7 ) {
F_4 ( L_3 , V_4 ) ;
return - V_13 ;
}
V_25 = V_2 -> V_6 . V_26 + V_31 ;
if ( V_25 > V_2 -> V_6 . V_27 ) {
F_8 ( 1 ) ;
return - V_17 ;
}
memset ( V_2 -> V_6 . V_28 , 0 , V_25 ) ;
F_2 ( V_8 , L_17 ,
V_20 ) ;
V_23 = V_20 ;
while ( V_23 ) {
V_30 = ( V_23 < ( V_2 -> V_6 . V_26 - V_31 ) ) ?
V_23 : ( V_2 -> V_6 . V_26 - V_31 ) ;
V_22 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_4 , sizeof( V_4 ) ) ;
V_22 += sizeof( V_4 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_30 , sizeof( V_30 ) ) ;
V_22 += sizeof( V_30 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_19 [ V_20 - V_23 ] ,
V_30 ) ;
V_22 += V_30 ;
V_3 = F_3 ( V_2 , V_2 -> V_6 . V_28 , V_22 ) ;
if ( V_3 ) {
F_4 ( L_10 ,
V_3 ) ;
return V_3 ;
}
V_23 -= V_30 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_18 )
{
T_1 V_4 = V_41 ;
int V_3 ;
T_1 V_22 ;
T_2 V_25 ;
if ( V_2 -> V_6 . V_7 ) {
F_4 ( L_3 , V_4 ) ;
return - V_13 ;
}
V_25 = sizeof( V_4 ) + sizeof( V_18 ) ;
if ( V_25 > V_2 -> V_6 . V_27 ) {
F_8 ( 1 ) ;
return - V_17 ;
}
memset ( V_2 -> V_6 . V_28 , 0 , V_25 ) ;
F_2 ( V_8 ,
L_18 ,
V_18 ) ;
V_22 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_4 , sizeof( V_4 ) ) ;
V_22 += sizeof( V_4 ) ;
memcpy ( & ( V_2 -> V_6 . V_28 [ V_22 ] ) , & V_18 , sizeof( V_18 ) ) ;
V_22 += sizeof( V_18 ) ;
V_3 = F_3 ( V_2 , V_2 -> V_6 . V_28 , V_22 ) ;
if ( V_3 ) {
F_4 ( L_19 ,
V_3 ) ;
return V_3 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_18 , V_9 * V_19 , T_1 V_20 )
{
int V_3 ;
T_1 V_42 = 0 ;
T_1 V_43 = V_20 & ~ 0x3 ;
T_1 V_44 = V_20 & 0x3 ;
V_3 = F_16 ( V_2 , V_18 ) ;
if ( V_3 )
return V_3 ;
if ( V_44 ) {
memcpy ( & V_42 , & V_19 [ V_43 ] , V_44 ) ;
}
V_3 = F_15 ( V_2 , V_19 , V_43 ) ;
if ( V_3 )
return V_3 ;
if ( V_44 )
V_3 = F_15 ( V_2 , ( V_9 * ) & V_42 , 4 ) ;
if ( ! V_3 ) {
V_3 = F_16 ( V_2 , 0x00 ) ;
}
return V_3 ;
}
void F_18 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_7 = false ;
}
int F_19 ( struct V_1 * V_2 )
{
if ( F_8 ( V_2 -> V_6 . V_26 == 0 ) )
return - V_17 ;
V_2 -> V_6 . V_27 = V_2 -> V_6 . V_26 + ( sizeof( T_1 ) * 3 ) ;
V_2 -> V_6 . V_28 = F_20 ( V_2 -> V_6 . V_27 , V_45 ) ;
if ( ! V_2 -> V_6 . V_28 )
return - V_46 ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_6 . V_28 ) ;
V_2 -> V_6 . V_28 = NULL ;
}
