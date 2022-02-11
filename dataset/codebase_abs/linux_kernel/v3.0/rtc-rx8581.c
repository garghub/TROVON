static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char V_5 [ 7 ] ;
int V_6 , V_7 ;
V_6 = F_2 ( V_2 , V_8 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_9 , L_1 ) ;
return - V_10 ;
}
do {
if ( V_6 & V_11 ) {
V_7 = F_4 ( V_2 ,
V_8 , ( V_6 & ~ V_11 ) ) ;
if ( V_7 != 0 ) {
F_3 ( & V_2 -> V_9 , L_2
L_3 ) ;
return - V_10 ;
}
}
V_7 = F_5 ( V_2 , V_12 ,
7 , V_5 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_2 -> V_9 , L_4 ) ;
return - V_10 ;
}
V_6 = F_2 ( V_2 , V_8 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_9 , L_1 ) ;
return - V_10 ;
}
} while ( V_6 & V_11 );
if ( V_6 & V_13 )
F_6 ( & V_2 -> V_9 ,
L_5 ) ;
F_7 ( & V_2 -> V_9 ,
L_6
L_7 ,
V_14 ,
V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] , V_5 [ 3 ] , V_5 [ 4 ] , V_5 [ 5 ] , V_5 [ 6 ] ) ;
V_4 -> V_15 = F_8 ( V_5 [ V_12 ] & 0x7F ) ;
V_4 -> V_16 = F_8 ( V_5 [ V_17 ] & 0x7F ) ;
V_4 -> V_18 = F_8 ( V_5 [ V_19 ] & 0x3F ) ;
V_4 -> V_20 = F_9 ( V_5 [ V_21 ] & 0x7F ) ;
V_4 -> V_22 = F_8 ( V_5 [ V_23 ] & 0x3F ) ;
V_4 -> V_24 = F_8 ( V_5 [ V_25 ] & 0x1F ) - 1 ;
V_4 -> V_26 = F_8 ( V_5 [ V_27 ] ) ;
if ( V_4 -> V_26 < 70 )
V_4 -> V_26 += 100 ;
F_7 ( & V_2 -> V_9 , L_8
L_9 ,
V_14 ,
V_4 -> V_15 , V_4 -> V_16 , V_4 -> V_18 ,
V_4 -> V_22 , V_4 -> V_24 , V_4 -> V_26 , V_4 -> V_20 ) ;
V_7 = F_10 ( V_4 ) ;
if ( V_7 < 0 )
F_3 ( & V_2 -> V_9 , L_10 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_6 , V_7 ;
unsigned char V_28 [ 7 ] ;
F_7 ( & V_2 -> V_9 , L_11
L_9 ,
V_14 ,
V_4 -> V_15 , V_4 -> V_16 , V_4 -> V_18 ,
V_4 -> V_22 , V_4 -> V_24 , V_4 -> V_26 , V_4 -> V_20 ) ;
V_28 [ V_12 ] = F_12 ( V_4 -> V_15 ) ;
V_28 [ V_17 ] = F_12 ( V_4 -> V_16 ) ;
V_28 [ V_19 ] = F_12 ( V_4 -> V_18 ) ;
V_28 [ V_23 ] = F_12 ( V_4 -> V_22 ) ;
V_28 [ V_25 ] = F_12 ( V_4 -> V_24 + 1 ) ;
V_28 [ V_27 ] = F_12 ( V_4 -> V_26 % 100 ) ;
V_28 [ V_21 ] = ( 0x1 << V_4 -> V_20 ) ;
V_6 = F_2 ( V_2 , V_29 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_9 , L_12 ) ;
return - V_10 ;
}
V_7 = F_4 ( V_2 , V_29 ,
( V_6 | V_30 ) ) ;
if ( V_7 < 0 ) {
F_3 ( & V_2 -> V_9 , L_13 ) ;
return - V_10 ;
}
V_7 = F_13 ( V_2 , V_12 , 7 , V_28 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_2 -> V_9 , L_14 ) ;
return - V_10 ;
}
V_6 = F_2 ( V_2 , V_8 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_9 , L_15 ) ;
return - V_10 ;
}
V_7 = F_4 ( V_2 , V_8 ,
( V_6 & ~ ( V_13 ) ) ) ;
if ( V_7 != 0 ) {
F_3 ( & V_2 -> V_9 , L_16 ) ;
return - V_10 ;
}
V_6 = F_2 ( V_2 , V_29 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_2 -> V_9 , L_12 ) ;
return - V_10 ;
}
V_7 = F_4 ( V_2 , V_29 ,
( V_6 & ~ ( V_30 ) ) ) ;
if ( V_7 != 0 ) {
F_3 ( & V_2 -> V_9 , L_13 ) ;
return - V_10 ;
}
return 0 ;
}
static int F_14 ( struct V_31 * V_9 , struct V_3 * V_4 )
{
return F_1 ( F_15 ( V_9 ) , V_4 ) ;
}
static int F_16 ( struct V_31 * V_9 , struct V_3 * V_4 )
{
return F_11 ( F_15 ( V_9 ) , V_4 ) ;
}
static int T_1 F_17 ( struct V_1 * V_2 ,
const struct V_32 * V_33 )
{
struct V_34 * V_35 ;
F_7 ( & V_2 -> V_9 , L_17 , V_14 ) ;
if ( ! F_18 ( V_2 -> V_36 , V_37 ) )
return - V_38 ;
F_6 ( & V_2 -> V_9 , L_18 V_39 L_19 ) ;
V_35 = F_19 ( V_40 . V_41 . V_42 ,
& V_2 -> V_9 , & V_43 , V_44 ) ;
if ( F_20 ( V_35 ) )
return F_21 ( V_35 ) ;
F_22 ( V_2 , V_35 ) ;
return 0 ;
}
static int T_2 F_23 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_24 ( V_2 ) ;
F_25 ( V_35 ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_40 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_40 ) ;
}
