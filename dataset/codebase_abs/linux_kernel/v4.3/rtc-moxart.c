static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ , V_3 >>= 1 ) {
F_3 ( V_4 -> V_6 , 0 ) ;
F_3 ( V_4 -> V_7 , ( ( V_3 & 1 ) == 1 ) ) ;
F_4 ( V_8 ) ;
F_3 ( V_4 -> V_6 , 1 ) ;
F_4 ( V_8 ) ;
}
}
static T_1 F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
T_1 V_3 = 0 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
F_3 ( V_4 -> V_6 , 0 ) ;
F_4 ( V_8 ) ;
F_3 ( V_4 -> V_6 , 1 ) ;
F_4 ( V_8 ) ;
if ( F_6 ( V_4 -> V_7 ) )
V_3 |= ( 1 << V_5 ) ;
F_4 ( V_8 ) ;
}
return V_3 ;
}
static T_1 F_7 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
T_1 V_3 ;
unsigned long V_10 ;
F_8 ( V_10 ) ;
F_9 ( V_4 -> V_7 , 0 ) ;
F_3 ( V_4 -> V_11 , 1 ) ;
F_4 ( V_8 ) ;
F_1 ( V_2 , V_9 ) ;
F_10 ( V_4 -> V_7 ) ;
F_4 ( V_8 ) ;
V_3 = F_5 ( V_2 ) ;
F_3 ( V_4 -> V_6 , 0 ) ;
F_3 ( V_4 -> V_11 , 0 ) ;
F_4 ( V_8 ) ;
F_11 ( V_10 ) ;
return V_3 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
unsigned long V_10 ;
F_8 ( V_10 ) ;
F_9 ( V_4 -> V_7 , 0 ) ;
F_3 ( V_4 -> V_11 , 1 ) ;
F_4 ( V_8 ) ;
F_1 ( V_2 , V_9 ) ;
F_1 ( V_2 , V_3 ) ;
F_3 ( V_4 -> V_6 , 0 ) ;
F_3 ( V_4 -> V_11 , 0 ) ;
F_4 ( V_8 ) ;
F_11 ( V_10 ) ;
}
static int F_13 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
F_14 ( & V_4 -> V_14 ) ;
F_12 ( V_2 , V_15 , 0 ) ;
F_12 ( V_2 , V_16 ,
( ( ( V_13 -> V_17 - 100 ) / 10 ) << 4 ) |
( ( V_13 -> V_17 - 100 ) % 10 ) ) ;
F_12 ( V_2 , V_18 ,
( ( ( V_13 -> V_19 + 1 ) / 10 ) << 4 ) |
( ( V_13 -> V_19 + 1 ) % 10 ) ) ;
F_12 ( V_2 , V_20 ,
( ( V_13 -> V_21 / 10 ) << 4 ) |
( V_13 -> V_21 % 10 ) ) ;
F_12 ( V_2 , V_22 ,
( ( V_13 -> V_23 / 10 ) << 4 ) |
( V_13 -> V_23 % 10 ) ) ;
F_12 ( V_2 , V_24 ,
( ( V_13 -> V_25 / 10 ) << 4 ) |
( V_13 -> V_25 % 10 ) ) ;
F_12 ( V_2 , V_26 ,
( ( V_13 -> V_27 / 10 ) << 4 ) |
( V_13 -> V_27 % 10 ) ) ;
F_12 ( V_2 , V_15 , 0x80 ) ;
F_15 ( & V_4 -> V_14 ) ;
F_16 ( V_2 , L_1
L_2 ,
V_28 , V_13 -> V_17 , V_13 -> V_19 , V_13 -> V_21 ,
V_13 -> V_23 , V_13 -> V_25 , V_13 -> V_27 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
unsigned char V_29 ;
F_14 ( & V_4 -> V_14 ) ;
V_29 = F_7 ( V_2 , V_30 ) ;
V_13 -> V_27 = ( ( ( V_29 & 0x70 ) >> 4 ) * 10 ) + ( V_29 & 0x0F ) ;
V_29 = F_7 ( V_2 , V_31 ) ;
V_13 -> V_25 = ( ( ( V_29 & 0x70 ) >> 4 ) * 10 ) + ( V_29 & 0x0F ) ;
V_29 = F_7 ( V_2 , V_32 ) ;
if ( V_29 & 0x80 ) {
V_13 -> V_23 = ( ( ( V_29 & 0x10 ) >> 4 ) * 10 ) + ( V_29 & 0x0F ) ;
if ( V_29 & 0x20 ) {
V_13 -> V_23 += 12 ;
if ( V_13 -> V_23 >= 24 )
V_13 -> V_23 = 0 ;
}
} else {
V_13 -> V_23 = ( ( ( V_29 & 0x30 ) >> 4 ) * 10 ) + ( V_29 & 0x0F ) ;
}
V_29 = F_7 ( V_2 , V_33 ) ;
V_13 -> V_21 = ( ( ( V_29 & 0x30 ) >> 4 ) * 10 ) + ( V_29 & 0x0F ) ;
V_29 = F_7 ( V_2 , V_34 ) ;
V_13 -> V_19 = ( ( ( V_29 & 0x10 ) >> 4 ) * 10 ) + ( V_29 & 0x0F ) ;
V_13 -> V_19 -- ;
V_29 = F_7 ( V_2 , V_35 ) ;
V_13 -> V_17 = ( ( ( V_29 & 0xF0 ) >> 4 ) * 10 ) + ( V_29 & 0x0F ) ;
V_13 -> V_17 += 100 ;
if ( V_13 -> V_17 <= 69 )
V_13 -> V_17 += 100 ;
V_29 = F_7 ( V_2 , V_36 ) ;
V_13 -> V_37 = ( V_29 & 0x0f ) - 1 ;
V_13 -> V_38 = V_39 [ V_13 -> V_19 ] ;
V_13 -> V_38 += ( V_13 -> V_21 - 1 ) ;
if ( V_13 -> V_19 >= 2 ) {
if ( ! ( V_13 -> V_17 % 4 ) && ( V_13 -> V_17 % 100 ) )
V_13 -> V_38 ++ ;
}
V_13 -> V_40 = 0 ;
F_15 ( & V_4 -> V_14 ) ;
return 0 ;
}
static int F_18 ( struct V_41 * V_42 )
{
struct V_4 * V_4 ;
int V_43 = 0 ;
V_4 = F_19 ( & V_42 -> V_2 , sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return - V_45 ;
V_4 -> V_7 = F_20 ( V_42 -> V_2 . V_46 ,
L_3 , 0 ) ;
if ( ! F_21 ( V_4 -> V_7 ) ) {
F_22 ( & V_42 -> V_2 , L_4 ,
V_4 -> V_7 ) ;
return V_4 -> V_7 ;
}
V_4 -> V_6 = F_20 ( V_42 -> V_2 . V_46 ,
L_5 , 0 ) ;
if ( ! F_21 ( V_4 -> V_6 ) ) {
F_22 ( & V_42 -> V_2 , L_6 ,
V_4 -> V_6 ) ;
return V_4 -> V_6 ;
}
V_4 -> V_11 = F_20 ( V_42 -> V_2 . V_46 ,
L_7 , 0 ) ;
if ( ! F_21 ( V_4 -> V_11 ) ) {
F_22 ( & V_42 -> V_2 , L_8 ,
V_4 -> V_11 ) ;
return V_4 -> V_11 ;
}
F_23 ( & V_4 -> V_14 ) ;
F_24 ( V_42 , V_4 ) ;
V_43 = F_25 ( & V_42 -> V_2 , V_4 -> V_7 , L_9 ) ;
if ( V_43 ) {
F_22 ( & V_42 -> V_2 , L_10 ) ;
return V_43 ;
}
V_43 = F_26 ( & V_42 -> V_2 , V_4 -> V_6 ,
V_47 , L_11 ) ;
if ( V_43 ) {
F_22 ( & V_42 -> V_2 , L_12 ) ;
return V_43 ;
}
V_43 = F_26 ( & V_42 -> V_2 , V_4 -> V_11 ,
V_47 , L_13 ) ;
if ( V_43 ) {
F_22 ( & V_42 -> V_2 , L_14 ) ;
return V_43 ;
}
V_4 -> V_48 = F_27 ( & V_42 -> V_2 , V_42 -> V_49 ,
& V_50 ,
V_51 ) ;
if ( F_28 ( V_4 -> V_48 ) ) {
F_22 ( & V_42 -> V_2 , L_15 ) ;
return F_29 ( V_4 -> V_48 ) ;
}
return 0 ;
}
