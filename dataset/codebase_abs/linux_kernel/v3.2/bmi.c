static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
unsigned long V_4 ;
int V_5 ;
V_2 -> V_6 . V_7 = 0 ;
V_3 = V_8 + ( V_9 + V_10 ) * 4 ;
V_4 = V_11 + F_2 ( V_12 ) ;
while ( F_3 ( V_11 , V_4 ) && ! V_2 -> V_6 . V_7 ) {
V_5 = F_4 ( V_2 , V_3 ,
( V_13 * ) & V_2 -> V_6 . V_7 , 4 ,
V_14 ) ;
if ( V_5 ) {
F_5 ( L_1 ,
V_5 ) ;
return V_5 ;
}
V_2 -> V_6 . V_7 &= 0xFF ;
}
if ( ! V_2 -> V_6 . V_7 ) {
F_5 ( L_2 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
T_1 V_16 = 0 ;
int V_5 = 0 ;
V_4 = V_11 + F_2 ( V_12 ) ;
while ( F_3 ( V_11 , V_4 ) && ! V_16 ) {
V_5 = F_4 ( V_2 , V_17 ,
( V_13 * ) & V_16 , sizeof( V_16 ) ,
V_14 ) ;
if ( V_5 ) {
F_5 ( L_3 ) ;
return V_5 ;
}
V_16 &= ( 1 << V_10 ) ;
}
if ( ! V_16 ) {
F_5 ( L_4 ) ;
return - V_18 ;
}
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 , V_13 * V_19 , T_1 V_20 )
{
int V_5 ;
T_1 V_3 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_3 = V_2 -> V_21 . V_22 ;
V_5 = F_4 ( V_2 , V_3 , V_19 , V_20 ,
V_23 ) ;
if ( V_5 )
F_5 ( L_5 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 , V_13 * V_19 , T_1 V_20 )
{
int V_5 ;
T_1 V_3 ;
if ( V_20 >= 4 ) {
V_5 = F_6 ( V_2 ) ;
if ( V_5 )
return V_5 ;
}
V_3 = V_2 -> V_21 . V_22 ;
V_5 = F_4 ( V_2 , V_3 , V_19 , V_20 ,
V_14 ) ;
if ( V_5 ) {
F_5 ( L_6 ,
V_5 ) ;
return V_5 ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_24 = V_25 ;
if ( V_2 -> V_6 . V_26 ) {
F_10 ( V_27 , L_7 ) ;
return 0 ;
}
V_2 -> V_6 . V_26 = true ;
V_5 = F_7 ( V_2 , ( V_13 * ) & V_24 , sizeof( V_24 ) ) ;
if ( V_5 ) {
F_5 ( L_8 , V_5 ) ;
return V_5 ;
}
F_11 ( V_2 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
int V_5 ;
T_1 V_24 = V_30 ;
if ( V_2 -> V_6 . V_26 ) {
F_5 ( L_9 , V_24 ) ;
return - V_31 ;
}
V_5 = F_7 ( V_2 , ( V_13 * ) & V_24 , sizeof( V_24 ) ) ;
if ( V_5 ) {
F_5 ( L_10 , V_5 ) ;
return V_5 ;
}
V_5 = F_8 ( V_2 , ( V_13 * ) & V_29 -> V_32 ,
sizeof( V_29 -> V_32 ) ) ;
if ( V_5 ) {
F_5 ( L_11 , V_5 ) ;
return V_5 ;
}
if ( F_13 ( V_29 -> V_32 ) == V_33 ) {
V_5 = F_8 ( V_2 ,
( V_13 * ) & V_29 -> V_34 ,
sizeof( V_29 -> V_34 ) ) ;
if ( V_5 ) {
F_5 ( L_12 ,
V_5 ) ;
return V_5 ;
}
if ( F_13 ( V_29 -> V_34 ) != sizeof( * V_29 ) ) {
F_14 ( 1 ) ;
return - V_18 ;
}
V_5 = F_8 ( V_2 ,
( ( V_13 * ) V_29 ) +
sizeof( V_29 -> V_34 ) ,
sizeof( * V_29 ) -
sizeof( V_29 -> V_34 ) ) ;
if ( V_5 ) {
F_5 ( L_13 ,
V_29 -> V_34 , V_5 ) ;
return V_5 ;
}
}
F_10 ( V_27 , L_14 ,
V_29 -> V_32 , V_29 -> type ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_3 , V_13 * V_19 , T_1 V_20 )
{
T_1 V_24 = V_35 ;
int V_5 ;
T_1 V_36 ;
T_1 V_37 , V_38 ;
T_2 V_39 ;
if ( V_2 -> V_6 . V_26 ) {
F_5 ( L_9 , V_24 ) ;
return - V_31 ;
}
V_39 = V_40 + sizeof( V_24 ) + sizeof( V_3 ) + sizeof( V_20 ) ;
if ( V_39 > V_41 ) {
F_14 ( 1 ) ;
return - V_18 ;
}
memset ( V_2 -> V_6 . V_42 , 0 , V_39 ) ;
F_10 ( V_27 ,
L_15 ,
V_3 , V_20 ) ;
V_37 = V_20 ;
while ( V_37 ) {
V_38 = ( V_37 < V_40 ) ?
V_37 : V_40 ;
V_36 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_36 += sizeof( V_24 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_3 , sizeof( V_3 ) ) ;
V_36 += sizeof( V_3 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_38 , sizeof( V_38 ) ) ;
V_36 += sizeof( V_20 ) ;
V_5 = F_7 ( V_2 , V_2 -> V_6 . V_42 , V_36 ) ;
if ( V_5 ) {
F_5 ( L_16 ,
V_5 ) ;
return V_5 ;
}
V_5 = F_8 ( V_2 , V_2 -> V_6 . V_42 , V_38 ) ;
if ( V_5 ) {
F_5 ( L_17 ,
V_5 ) ;
return V_5 ;
}
memcpy ( & V_19 [ V_20 - V_37 ] , V_2 -> V_6 . V_42 , V_38 ) ;
V_37 -= V_38 ; V_3 += V_38 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , T_1 V_3 , V_13 * V_19 , T_1 V_20 )
{
T_1 V_24 = V_43 ;
int V_5 ;
T_1 V_36 ;
T_1 V_37 , V_44 ;
const T_1 V_45 = sizeof( V_24 ) + sizeof( V_3 ) + sizeof( V_20 ) ;
V_13 V_46 [ V_40 ] ;
V_13 * V_47 ;
if ( V_2 -> V_6 . V_26 ) {
F_5 ( L_9 , V_24 ) ;
return - V_31 ;
}
if ( ( V_40 + V_45 ) > V_41 ) {
F_14 ( 1 ) ;
return - V_18 ;
}
memset ( V_2 -> V_6 . V_42 , 0 , V_40 + V_45 ) ;
F_10 ( V_27 ,
L_18 , V_3 , V_20 ) ;
V_37 = V_20 ;
while ( V_37 ) {
V_47 = & V_19 [ V_20 - V_37 ] ;
if ( V_37 < ( V_40 - V_45 ) ) {
if ( V_37 & 3 ) {
V_37 = V_37 +
( 4 - ( V_37 & 3 ) ) ;
memcpy ( V_46 , V_47 , V_37 ) ;
V_47 = V_46 ;
}
V_44 = V_37 ;
} else {
V_44 = ( V_40 - V_45 ) ;
}
V_36 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_36 += sizeof( V_24 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_3 , sizeof( V_3 ) ) ;
V_36 += sizeof( V_3 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_44 , sizeof( V_44 ) ) ;
V_36 += sizeof( V_44 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , V_47 , V_44 ) ;
V_36 += V_44 ;
V_5 = F_7 ( V_2 , V_2 -> V_6 . V_42 , V_36 ) ;
if ( V_5 ) {
F_5 ( L_16 ,
V_5 ) ;
return V_5 ;
}
V_37 -= V_44 ; V_3 += V_44 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_48 )
{
T_1 V_24 = V_49 ;
int V_5 ;
T_1 V_36 ;
T_2 V_39 ;
if ( V_2 -> V_6 . V_26 ) {
F_5 ( L_9 , V_24 ) ;
return - V_31 ;
}
V_39 = sizeof( V_24 ) + sizeof( V_3 ) + sizeof( V_48 ) ;
if ( V_39 > V_41 ) {
F_14 ( 1 ) ;
return - V_18 ;
}
memset ( V_2 -> V_6 . V_42 , 0 , V_39 ) ;
F_10 ( V_27 , L_19 ,
V_3 , * V_48 ) ;
V_36 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_36 += sizeof( V_24 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_3 , sizeof( V_3 ) ) ;
V_36 += sizeof( V_3 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , V_48 , sizeof( * V_48 ) ) ;
V_36 += sizeof( * V_48 ) ;
V_5 = F_7 ( V_2 , V_2 -> V_6 . V_42 , V_36 ) ;
if ( V_5 ) {
F_5 ( L_16 , V_5 ) ;
return V_5 ;
}
V_5 = F_8 ( V_2 , V_2 -> V_6 . V_42 , sizeof( * V_48 ) ) ;
if ( V_5 ) {
F_5 ( L_17 , V_5 ) ;
return V_5 ;
}
memcpy ( V_48 , V_2 -> V_6 . V_42 , sizeof( * V_48 ) ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_24 = V_50 ;
int V_5 ;
T_1 V_36 ;
T_2 V_39 ;
if ( V_2 -> V_6 . V_26 ) {
F_5 ( L_9 , V_24 ) ;
return - V_31 ;
}
V_39 = sizeof( V_24 ) + sizeof( V_3 ) ;
if ( V_39 > V_41 ) {
F_14 ( 1 ) ;
return - V_18 ;
}
memset ( V_2 -> V_6 . V_42 , 0 , V_39 ) ;
F_10 ( V_27 , L_20 , V_3 ) ;
V_36 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_36 += sizeof( V_24 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_3 , sizeof( V_3 ) ) ;
V_36 += sizeof( V_3 ) ;
V_5 = F_7 ( V_2 , V_2 -> V_6 . V_42 , V_36 ) ;
if ( V_5 ) {
F_5 ( L_16 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_48 )
{
T_1 V_24 = V_51 ;
int V_5 ;
T_1 V_36 ;
T_2 V_39 ;
if ( V_2 -> V_6 . V_26 ) {
F_5 ( L_9 , V_24 ) ;
return - V_31 ;
}
V_39 = sizeof( V_24 ) + sizeof( V_3 ) ;
if ( V_39 > V_41 ) {
F_14 ( 1 ) ;
return - V_18 ;
}
memset ( V_2 -> V_6 . V_42 , 0 , V_39 ) ;
F_10 ( V_27 , L_21 , V_3 ) ;
V_36 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_36 += sizeof( V_24 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_3 , sizeof( V_3 ) ) ;
V_36 += sizeof( V_3 ) ;
V_5 = F_7 ( V_2 , V_2 -> V_6 . V_42 , V_36 ) ;
if ( V_5 ) {
F_5 ( L_16 , V_5 ) ;
return V_5 ;
}
V_5 = F_8 ( V_2 , V_2 -> V_6 . V_42 , sizeof( * V_48 ) ) ;
if ( V_5 ) {
F_5 ( L_17 , V_5 ) ;
return V_5 ;
}
memcpy ( V_48 , V_2 -> V_6 . V_42 , sizeof( * V_48 ) ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_48 )
{
T_1 V_24 = V_52 ;
int V_5 ;
T_1 V_36 ;
T_2 V_39 ;
if ( V_2 -> V_6 . V_26 ) {
F_5 ( L_9 , V_24 ) ;
return - V_31 ;
}
V_39 = sizeof( V_24 ) + sizeof( V_3 ) + sizeof( V_48 ) ;
if ( V_39 > V_41 ) {
F_14 ( 1 ) ;
return - V_18 ;
}
memset ( V_2 -> V_6 . V_42 , 0 , V_39 ) ;
F_10 ( V_27 ,
L_22 ,
V_3 , V_48 ) ;
V_36 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_36 += sizeof( V_24 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_3 , sizeof( V_3 ) ) ;
V_36 += sizeof( V_3 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_48 , sizeof( V_48 ) ) ;
V_36 += sizeof( V_48 ) ;
V_5 = F_7 ( V_2 , V_2 -> V_6 . V_42 , V_36 ) ;
if ( V_5 ) {
F_5 ( L_16 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 , V_13 * V_19 , T_1 V_20 )
{
T_1 V_24 = V_53 ;
int V_5 ;
T_1 V_36 ;
T_1 V_37 , V_44 ;
const T_1 V_45 = sizeof( V_24 ) + sizeof( V_20 ) ;
T_2 V_39 ;
if ( V_2 -> V_6 . V_26 ) {
F_5 ( L_9 , V_24 ) ;
return - V_31 ;
}
V_39 = V_40 + V_45 ;
if ( V_39 > V_41 ) {
F_14 ( 1 ) ;
return - V_18 ;
}
memset ( V_2 -> V_6 . V_42 , 0 , V_39 ) ;
F_10 ( V_27 , L_23 ,
V_20 ) ;
V_37 = V_20 ;
while ( V_37 ) {
V_44 = ( V_37 < ( V_40 - V_45 ) ) ?
V_37 : ( V_40 - V_45 ) ;
V_36 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_36 += sizeof( V_24 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_44 , sizeof( V_44 ) ) ;
V_36 += sizeof( V_44 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_19 [ V_20 - V_37 ] ,
V_44 ) ;
V_36 += V_44 ;
V_5 = F_7 ( V_2 , V_2 -> V_6 . V_42 , V_36 ) ;
if ( V_5 ) {
F_5 ( L_16 ,
V_5 ) ;
return V_5 ;
}
V_37 -= V_44 ;
}
return 0 ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_24 = V_54 ;
int V_5 ;
T_1 V_36 ;
T_2 V_39 ;
if ( V_2 -> V_6 . V_26 ) {
F_5 ( L_9 , V_24 ) ;
return - V_31 ;
}
V_39 = sizeof( V_24 ) + sizeof( V_3 ) ;
if ( V_39 > V_41 ) {
F_14 ( 1 ) ;
return - V_18 ;
}
memset ( V_2 -> V_6 . V_42 , 0 , V_39 ) ;
F_10 ( V_27 ,
L_24 ,
V_3 ) ;
V_36 = 0 ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_24 , sizeof( V_24 ) ) ;
V_36 += sizeof( V_24 ) ;
memcpy ( & ( V_2 -> V_6 . V_42 [ V_36 ] ) , & V_3 , sizeof( V_3 ) ) ;
V_36 += sizeof( V_3 ) ;
V_5 = F_7 ( V_2 , V_2 -> V_6 . V_42 , V_36 ) ;
if ( V_5 ) {
F_5 ( L_25 ,
V_5 ) ;
return V_5 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 , T_1 V_3 , V_13 * V_19 , T_1 V_20 )
{
int V_5 ;
T_1 V_55 = 0 ;
T_1 V_56 = V_20 & ~ 0x3 ;
T_1 V_57 = V_20 & 0x3 ;
V_5 = F_22 ( V_2 , V_3 ) ;
if ( V_5 )
return V_5 ;
if ( V_57 ) {
memcpy ( & V_55 , & V_19 [ V_56 ] , V_57 ) ;
}
V_5 = F_21 ( V_2 , V_19 , V_56 ) ;
if ( V_5 )
return V_5 ;
if ( V_57 )
V_5 = F_21 ( V_2 , ( V_13 * ) & V_55 , 4 ) ;
if ( ! V_5 ) {
V_5 = F_22 ( V_2 , 0x00 ) ;
}
return V_5 ;
}
int F_24 ( struct V_1 * V_2 )
{
V_2 -> V_6 . V_42 = F_25 ( V_41 , V_58 ) ;
if ( ! V_2 -> V_6 . V_42 )
return - V_59 ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_6 . V_42 ) ;
V_2 -> V_6 . V_42 = NULL ;
}
