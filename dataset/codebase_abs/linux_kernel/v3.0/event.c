static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_5 , L_1 ,
V_4 -> V_6 ,
V_4 -> V_7 ) ;
if ( V_2 -> V_8 ) {
F_3 ( V_2 -> V_9 , false ) ;
F_2 ( V_10 , L_2 ) ;
V_2 -> V_8 = false ;
}
return 0 ;
}
static void F_4 ( struct V_3 * V_4 )
{
F_2 ( V_5 , L_3 ) ;
F_2 ( V_5 , L_4 , V_4 -> V_11 ) ;
F_2 ( V_5 , L_5 , V_4 -> V_12 ) ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_13 ;
T_1 V_14 ;
F_4 ( V_4 ) ;
V_14 = V_4 -> V_11 & ~ ( V_4 -> V_12 ) ;
F_2 ( V_5 , L_6 , V_14 ) ;
if ( V_14 & V_15 ) {
V_13 = F_1 ( V_2 , V_4 ) ;
if ( V_13 < 0 )
return V_13 ;
}
if ( V_14 & V_16 ) {
F_2 ( V_5 , L_7 ) ;
if ( V_2 -> V_17 &&
V_2 -> V_18 != V_19 ) {
V_13 = F_6 ( V_2 , V_19 ) ;
if ( V_13 < 0 )
return V_13 ;
}
}
if ( V_14 & V_20 &&
V_2 -> V_18 != V_19 ) {
F_2 ( V_5 , L_8 ) ;
F_7 ( V_2 -> V_21 ) ;
}
if ( V_14 & V_22 ) {
if ( V_2 -> V_17 ) {
V_13 = F_6 ( V_2 , V_23 ) ;
if ( V_13 < 0 )
return V_13 ;
}
}
if ( V_2 -> V_21 && V_2 -> V_24 ) {
if ( V_14 & V_25 ) {
F_2 ( V_5 ,
L_9 ) ;
F_8 ( V_2 -> V_21 ,
V_26 ,
V_27 ) ;
}
if ( V_14 & V_28 ) {
F_2 ( V_5 ,
L_10 ) ;
F_8 ( V_2 -> V_21 ,
V_29 ,
V_27 ) ;
}
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_30 , int V_31 )
{
T_1 V_11 , V_32 ;
unsigned long V_33 ;
V_33 = V_34 + F_10 ( V_31 ) ;
do {
if ( F_11 ( V_34 , V_33 ) )
return - V_35 ;
F_12 ( 1 ) ;
F_13 ( V_2 , V_2 -> V_36 [ 0 ] , & V_11 ,
sizeof( V_11 ) ) ;
V_32 = V_11 & V_30 ;
F_13 ( V_2 , V_2 -> V_36 [ 1 ] , & V_11 ,
sizeof( V_11 ) ) ;
V_32 |= V_11 & V_30 ;
} while ( ! V_32 );
return 0 ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_15 ( V_2 , ~ ( V_2 -> V_37 ) ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_36 [ 0 ] = F_17 ( V_2 , V_38 ) ;
V_2 -> V_36 [ 1 ] = V_2 -> V_36 [ 0 ] + sizeof( struct V_3 ) ;
F_2 ( V_5 , L_11 ,
V_2 -> V_36 [ 0 ] , V_2 -> V_36 [ 1 ] ) ;
}
int F_18 ( struct V_1 * V_2 , T_2 V_39 )
{
struct V_3 V_4 ;
int V_13 ;
F_2 ( V_5 , L_12 , V_39 ) ;
if ( V_39 > 1 )
return - V_40 ;
F_13 ( V_2 , V_2 -> V_36 [ V_39 ] , & V_4 ,
sizeof( struct V_3 ) ) ;
V_13 = F_5 ( V_2 , & V_4 ) ;
if ( V_13 < 0 )
return V_13 ;
F_19 ( V_2 , V_41 , V_42 ) ;
return 0 ;
}
