static void F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 ;
struct V_4 * V_11 = V_5 ;
int V_12 ;
F_3 ( V_13 , V_2 , L_1 , V_6 ) ;
if ( V_6 > V_14 )
V_12 = 512 - V_6 ;
else
V_12 = 256 - V_6 ;
V_10 = F_4 ( V_6 + V_15 , V_16 ) ;
if ( ! V_10 ) {
V_2 -> V_17 . V_18 ++ ;
return;
}
F_5 ( V_10 , V_6 + V_15 ) ;
V_10 -> V_2 = V_2 ;
V_11 = (struct V_4 * ) V_10 -> V_19 ;
F_6 ( V_10 ) ;
F_7 ( V_10 , V_15 ) ;
memcpy ( V_11 , V_5 , sizeof( struct V_4 ) ) ;
if ( V_6 > sizeof( V_11 -> V_20 ) )
V_8 -> V_21 . V_22 ( V_2 , V_3 , V_12 + sizeof( V_11 -> V_20 ) ,
V_11 -> V_20 . V_23 + sizeof( V_11 -> V_20 ) ,
V_6 - sizeof( V_11 -> V_20 ) ) ;
if ( F_8 ( V_24 ) )
F_9 ( V_2 , V_10 , L_2 ) ;
V_10 -> V_25 = F_10 ( V_26 ) ;
F_11 ( V_10 ) ;
}
static int F_12 ( struct V_9 * V_10 , struct V_1 * V_2 ,
unsigned short type , T_1 V_27 )
{
int V_28 = V_15 ;
struct V_4 * V_11 = F_13 ( V_10 , V_28 ) ;
V_11 -> V_29 . V_30 = * V_2 -> V_31 ;
if ( V_2 -> V_32 & ( V_33 | V_34 ) ) {
V_11 -> V_29 . V_35 = 0 ;
return V_28 ;
}
V_11 -> V_29 . V_35 = V_27 ;
return V_28 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_4 * V_11 , int V_6 ,
int V_3 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_36 * V_29 = & V_11 -> V_29 ;
int V_12 ;
F_3 ( V_13 , V_2 , L_3 ,
V_8 -> V_37 , V_8 -> V_38 , V_3 ) ;
V_6 -= V_15 ;
if ( V_6 > V_39 ) {
F_3 ( V_40 , V_2 , L_4 ,
V_6 , V_39 ) ;
V_6 = V_39 ;
}
if ( V_6 >= V_41 ) {
V_29 -> V_42 [ 0 ] = 0 ;
V_29 -> V_42 [ 1 ] = V_12 = 512 - V_6 ;
} else if ( V_6 > V_14 ) {
V_29 -> V_42 [ 0 ] = 0 ;
V_29 -> V_42 [ 1 ] = V_12 = 512 - V_6 - 3 ;
} else {
V_29 -> V_42 [ 0 ] = V_12 = 256 - V_6 ;
}
F_3 ( V_13 , V_2 , L_5 ,
V_6 , V_12 ) ;
V_8 -> V_21 . V_43 ( V_2 , V_3 , 0 , V_29 , V_15 ) ;
V_8 -> V_21 . V_43 ( V_2 , V_3 , V_12 , & V_11 -> V_20 , V_6 ) ;
V_8 -> V_44 = V_29 -> V_35 ;
return 1 ;
}
static int T_2 F_15 ( void )
{
int V_45 ;
F_16 ( L_6 ) ;
for ( V_45 = 0 ; V_45 < 256 ; V_45 ++ )
if ( V_46 [ V_45 ] == V_47 )
V_46 [ V_45 ] = & V_48 ;
if ( V_49 == V_47 )
V_49 = & V_48 ;
V_47 = & V_48 ;
return 0 ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_48 ) ;
}
