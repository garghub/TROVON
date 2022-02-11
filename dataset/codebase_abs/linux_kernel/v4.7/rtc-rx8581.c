static int F_1 ( const struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 * V_5 )
{
T_2 V_6 , V_7 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
V_7 = F_2 ( V_2 , V_3 + V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
V_5 [ V_6 ] = V_7 ;
}
return V_6 ;
}
static int F_3 ( const struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , const T_1 * V_5 )
{
T_2 V_6 , V_8 ;
for ( V_6 = 0 ; V_6 < V_4 ; V_6 ++ ) {
V_8 = F_4 ( V_2 , V_3 + V_6 ,
V_5 [ V_6 ] ) ;
if ( V_8 < 0 )
return V_8 ;
}
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned char V_11 [ 7 ] ;
int V_7 , V_12 ;
struct V_13 * V_13 = F_6 ( V_2 ) ;
V_7 = F_2 ( V_2 , V_14 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_2 -> V_15 , L_1 ) ;
return - V_16 ;
}
do {
if ( V_7 & V_17 ) {
V_12 = F_4 ( V_2 ,
V_14 , ( V_7 & ~ V_17 ) ) ;
if ( V_12 != 0 ) {
F_7 ( & V_2 -> V_15 , L_2 ) ;
return - V_16 ;
}
}
V_12 = V_13 -> V_18 ( V_2 , V_19 ,
7 , V_11 ) ;
if ( V_12 < 0 ) {
F_7 ( & V_2 -> V_15 , L_3 ) ;
return - V_16 ;
}
V_7 = F_2 ( V_2 , V_14 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_2 -> V_15 , L_1 ) ;
return - V_16 ;
}
} while ( V_7 & V_17 );
if ( V_7 & V_20 )
F_8 ( & V_2 -> V_15 ,
L_4 ) ;
F_9 ( & V_2 -> V_15 ,
L_5
L_6 ,
V_21 ,
V_11 [ 0 ] , V_11 [ 1 ] , V_11 [ 2 ] , V_11 [ 3 ] , V_11 [ 4 ] , V_11 [ 5 ] , V_11 [ 6 ] ) ;
V_10 -> V_22 = F_10 ( V_11 [ V_19 ] & 0x7F ) ;
V_10 -> V_23 = F_10 ( V_11 [ V_24 ] & 0x7F ) ;
V_10 -> V_25 = F_10 ( V_11 [ V_26 ] & 0x3F ) ;
V_10 -> V_27 = F_11 ( V_11 [ V_28 ] & 0x7F ) ;
V_10 -> V_29 = F_10 ( V_11 [ V_30 ] & 0x3F ) ;
V_10 -> V_31 = F_10 ( V_11 [ V_32 ] & 0x1F ) - 1 ;
V_10 -> V_33 = F_10 ( V_11 [ V_34 ] ) ;
if ( V_10 -> V_33 < 70 )
V_10 -> V_33 += 100 ;
F_9 ( & V_2 -> V_15 , L_7
L_8 ,
V_21 ,
V_10 -> V_22 , V_10 -> V_23 , V_10 -> V_25 ,
V_10 -> V_29 , V_10 -> V_31 , V_10 -> V_33 , V_10 -> V_27 ) ;
V_12 = F_12 ( V_10 ) ;
if ( V_12 < 0 )
F_7 ( & V_2 -> V_15 , L_9 ) ;
return V_12 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
int V_7 , V_12 ;
unsigned char V_35 [ 7 ] ;
struct V_13 * V_13 = F_6 ( V_2 ) ;
F_9 ( & V_2 -> V_15 , L_10
L_8 ,
V_21 ,
V_10 -> V_22 , V_10 -> V_23 , V_10 -> V_25 ,
V_10 -> V_29 , V_10 -> V_31 , V_10 -> V_33 , V_10 -> V_27 ) ;
V_35 [ V_19 ] = F_14 ( V_10 -> V_22 ) ;
V_35 [ V_24 ] = F_14 ( V_10 -> V_23 ) ;
V_35 [ V_26 ] = F_14 ( V_10 -> V_25 ) ;
V_35 [ V_30 ] = F_14 ( V_10 -> V_29 ) ;
V_35 [ V_32 ] = F_14 ( V_10 -> V_31 + 1 ) ;
V_35 [ V_34 ] = F_14 ( V_10 -> V_33 % 100 ) ;
V_35 [ V_28 ] = ( 0x1 << V_10 -> V_27 ) ;
V_7 = F_2 ( V_2 , V_36 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_2 -> V_15 , L_11 ) ;
return - V_16 ;
}
V_12 = F_4 ( V_2 , V_36 ,
( V_7 | V_37 ) ) ;
if ( V_12 < 0 ) {
F_7 ( & V_2 -> V_15 , L_12 ) ;
return - V_16 ;
}
V_12 = V_13 -> V_38 ( V_2 , V_19 , 7 , V_35 ) ;
if ( V_12 < 0 ) {
F_7 ( & V_2 -> V_15 , L_13 ) ;
return - V_16 ;
}
V_7 = F_2 ( V_2 , V_14 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_2 -> V_15 , L_14 ) ;
return - V_16 ;
}
V_12 = F_4 ( V_2 , V_14 ,
( V_7 & ~ ( V_20 ) ) ) ;
if ( V_12 != 0 ) {
F_7 ( & V_2 -> V_15 , L_15 ) ;
return - V_16 ;
}
V_7 = F_2 ( V_2 , V_36 ) ;
if ( V_7 < 0 ) {
F_7 ( & V_2 -> V_15 , L_11 ) ;
return - V_16 ;
}
V_12 = F_4 ( V_2 , V_36 ,
( V_7 & ~ ( V_37 ) ) ) ;
if ( V_12 != 0 ) {
F_7 ( & V_2 -> V_15 , L_12 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_15 ( struct V_39 * V_15 , struct V_9 * V_10 )
{
return F_5 ( F_16 ( V_15 ) , V_10 ) ;
}
static int F_17 ( struct V_39 * V_15 , struct V_9 * V_10 )
{
return F_13 ( F_16 ( V_15 ) , V_10 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_40 * V_41 )
{
struct V_13 * V_13 ;
F_9 ( & V_2 -> V_15 , L_16 , V_21 ) ;
if ( ! F_19 ( V_2 -> V_42 , V_43 )
&& ! F_19 ( V_2 -> V_42 , V_44 ) )
return - V_16 ;
V_13 = F_20 ( & V_2 -> V_15 , sizeof( struct V_13 ) , V_45 ) ;
if ( ! V_13 )
return - V_46 ;
F_21 ( V_2 , V_13 ) ;
V_13 -> V_2 = V_2 ;
if ( F_19 ( V_2 -> V_42 , V_44 ) ) {
V_13 -> V_18 = V_47 ;
V_13 -> V_38 = V_48 ;
} else {
V_13 -> V_18 = F_1 ;
V_13 -> V_38 = F_3 ;
}
V_13 -> V_49 = F_22 ( & V_2 -> V_15 ,
V_50 . V_51 . V_52 , & V_53 , V_54 ) ;
if ( F_23 ( V_13 -> V_49 ) ) {
F_7 ( & V_2 -> V_15 ,
L_17 ) ;
return F_24 ( V_13 -> V_49 ) ;
}
return 0 ;
}
