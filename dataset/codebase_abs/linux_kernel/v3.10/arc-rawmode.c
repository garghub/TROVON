static int T_1 F_1 ( void )
{
int V_1 ;
F_2 ( V_2 ) ;
for ( V_1 = 0 ; V_1 < 256 ; V_1 ++ )
if ( V_3 [ V_1 ] == V_4 )
V_3 [ V_1 ] = & V_5 ;
if ( V_6 == V_4 )
V_6 = & V_5 ;
V_4 = & V_5 ;
return 0 ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_5 ) ;
}
static void F_5 ( struct V_7 * V_8 , int V_9 ,
struct V_10 * V_11 , int V_12 )
{
struct V_13 * V_14 = F_6 ( V_8 ) ;
struct V_15 * V_16 ;
struct V_10 * V_17 = V_11 ;
int V_18 ;
F_7 ( V_19 , L_1 , V_12 ) ;
if ( V_12 > V_20 )
V_18 = 512 - V_12 ;
else
V_18 = 256 - V_12 ;
V_16 = F_8 ( V_12 + V_21 , V_22 ) ;
if ( V_16 == NULL ) {
F_7 ( V_23 , L_2 ) ;
V_8 -> V_24 . V_25 ++ ;
return;
}
F_9 ( V_16 , V_12 + V_21 ) ;
V_16 -> V_8 = V_8 ;
V_17 = (struct V_10 * ) V_16 -> V_26 ;
F_10 ( V_16 ) ;
F_11 ( V_16 , V_21 ) ;
memcpy ( V_17 , V_11 , sizeof( struct V_10 ) ) ;
if ( V_12 > sizeof( V_17 -> V_27 ) )
V_14 -> V_28 . V_29 ( V_8 , V_9 , V_18 + sizeof( V_17 -> V_27 ) ,
V_17 -> V_27 . V_30 + sizeof( V_17 -> V_27 ) ,
V_12 - sizeof( V_17 -> V_27 ) ) ;
F_12 (D_SKB) F_13 ( V_8 , V_16 , L_3 ) ;
V_16 -> V_31 = F_14 ( V_32 ) ;
F_15 ( V_16 ) ;
}
static int F_16 ( struct V_15 * V_16 , struct V_7 * V_8 ,
unsigned short type , T_3 V_33 )
{
int V_34 = V_21 ;
struct V_10 * V_17 = (struct V_10 * ) F_17 ( V_16 , V_34 ) ;
V_17 -> V_35 . V_36 = * V_8 -> V_37 ;
if ( V_8 -> V_38 & ( V_39 | V_40 ) ) {
V_17 -> V_35 . V_41 = 0 ;
return V_34 ;
}
V_17 -> V_35 . V_41 = V_33 ;
return V_34 ;
}
static int F_18 ( struct V_7 * V_8 , struct V_10 * V_17 , int V_12 ,
int V_9 )
{
struct V_13 * V_14 = F_6 ( V_8 ) ;
struct V_42 * V_35 = & V_17 -> V_35 ;
int V_18 ;
F_7 ( V_19 , L_4 ,
V_14 -> V_43 , V_14 -> V_44 , V_9 ) ;
V_12 -= V_21 ;
if ( V_12 > V_45 ) {
F_7 ( V_23 , L_5 ,
V_12 , V_45 ) ;
V_12 = V_45 ;
}
if ( V_12 >= V_46 ) {
V_35 -> V_47 [ 0 ] = 0 ;
V_35 -> V_47 [ 1 ] = V_18 = 512 - V_12 ;
} else if ( V_12 > V_20 ) {
V_35 -> V_47 [ 0 ] = 0 ;
V_35 -> V_47 [ 1 ] = V_18 = 512 - V_12 - 3 ;
} else
V_35 -> V_47 [ 0 ] = V_18 = 256 - V_12 ;
F_7 ( V_19 , L_6 ,
V_12 , V_18 ) ;
V_14 -> V_28 . V_48 ( V_8 , V_9 , 0 , V_35 , V_21 ) ;
V_14 -> V_28 . V_48 ( V_8 , V_9 , V_18 , & V_17 -> V_27 , V_12 ) ;
V_14 -> V_49 = V_35 -> V_41 ;
return 1 ;
}
