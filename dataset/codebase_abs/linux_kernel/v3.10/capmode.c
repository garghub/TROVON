static void F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 ;
struct V_4 * V_11 = V_5 ;
char * V_12 , * V_13 ;
int V_14 ;
F_3 ( V_15 , L_1 , V_6 ) ;
if ( V_6 >= V_16 )
V_14 = 512 - V_6 ;
else
V_14 = 256 - V_6 ;
V_10 = F_4 ( V_6 + V_17 + sizeof( int ) , V_18 ) ;
if ( V_10 == NULL ) {
F_3 ( V_19 , L_2 ) ;
V_2 -> V_20 . V_21 ++ ;
return;
}
F_5 ( V_10 , V_6 + V_17 + sizeof( int ) ) ;
V_10 -> V_2 = V_2 ;
F_6 ( V_10 ) ;
V_11 = (struct V_4 * ) F_7 ( V_10 ) ;
F_8 ( V_10 , V_17 ) ;
V_12 = ( char * ) V_11 ;
V_13 = ( char * ) V_5 ;
memcpy ( V_12 , V_13 , V_17 + sizeof( V_11 -> V_22 . V_23 . V_24 ) ) ;
memcpy ( V_12 + V_17 + sizeof( V_11 -> V_22 . V_23 . V_24 ) + sizeof( int ) ,
V_13 + V_17 + sizeof( V_11 -> V_22 . V_23 . V_24 ) ,
sizeof( struct V_4 ) - V_17 - sizeof( V_11 -> V_22 . V_23 . V_24 ) ) ;
if ( V_6 > sizeof( V_11 -> V_22 ) )
V_8 -> V_25 . V_26 ( V_2 , V_3 , V_14 + sizeof( V_11 -> V_22 ) ,
V_11 -> V_22 . V_27 + sizeof( V_11 -> V_22 )
+ sizeof( int ) ,
V_6 - sizeof( V_11 -> V_22 ) ) ;
F_9 (D_SKB) F_10 ( V_2 , V_10 , L_3 ) ;
V_10 -> V_28 = F_11 ( V_29 ) ;
F_12 ( V_10 ) ;
}
static int F_13 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned short type ,
T_1 V_30 )
{
int V_31 = V_17 ;
struct V_4 * V_11 = (struct V_4 * ) F_14 ( V_10 , V_31 ) ;
F_3 ( V_32 , L_4 ,
* ( ( int * ) & V_11 -> V_22 . V_23 . V_33 [ 0 ] ) ) ;
V_11 -> V_34 . V_35 = * V_2 -> V_36 ;
if ( V_2 -> V_37 & ( V_38 | V_39 ) ) {
V_11 -> V_34 . V_40 = 0 ;
return V_31 ;
}
V_11 -> V_34 . V_40 = V_30 ;
return V_31 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_4 * V_11 , int V_6 ,
int V_3 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_41 * V_34 = & V_11 -> V_34 ;
int V_14 ;
V_6 -= V_17 ;
V_6 -= sizeof( int ) ;
F_3 ( V_15 , L_5 ,
V_8 -> V_42 , V_8 -> V_43 , V_3 ) ;
F_3 ( V_32 , L_6 ,
* ( ( int * ) & V_11 -> V_22 . V_23 . V_33 [ 0 ] ) ) ;
if ( V_6 > V_44 ) {
F_3 ( V_19 , L_7 ,
V_6 , V_44 ) ;
V_6 = V_44 ;
}
if ( V_6 > V_16 ) {
V_34 -> V_45 [ 0 ] = 0 ;
V_34 -> V_45 [ 1 ] = V_14 = 512 - V_6 ;
} else if ( V_6 > V_46 ) {
V_34 -> V_45 [ 0 ] = 0 ;
V_34 -> V_45 [ 1 ] = V_14 = 512 - V_6 - 3 ;
} else
V_34 -> V_45 [ 0 ] = V_14 = 256 - V_6 ;
F_3 ( V_15 , L_8 ,
V_6 , V_14 ) ;
V_8 -> V_25 . V_47 ( V_2 , V_3 , 0 , V_34 , V_17 ) ;
V_8 -> V_25 . V_47 ( V_2 , V_3 , V_14 , & V_11 -> V_22 . V_23 . V_24 ,
sizeof( V_11 -> V_22 . V_23 . V_24 ) ) ;
V_8 -> V_25 . V_47 ( V_2 , V_3 , V_14 + 1 ,
( ( unsigned char * ) & V_11 -> V_22 . V_23 . V_48 ) , V_6 - 1 ) ;
V_8 -> V_49 = V_34 -> V_40 ;
return 1 ;
}
static int F_16 ( struct V_1 * V_2 , int V_50 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_51 ;
struct V_4 * V_52 ;
int V_6 = sizeof( struct V_53 ) ;
F_3 ( V_15 , L_9 ,
V_8 -> V_54 . V_10 -> V_28 , V_50 ) ;
F_9 (D_SKB) F_10 ( V_2 , V_8 -> V_54 . V_10 , L_10 ) ;
V_51 = F_4 ( V_6 + V_17 , V_18 ) ;
if ( V_51 == NULL ) {
F_3 ( V_19 , L_11 ) ;
goto V_55;
}
F_5 ( V_51 , V_6 + V_17 ) ;
V_51 -> V_2 = V_2 ;
F_6 ( V_51 ) ;
V_52 = (struct V_4 * ) F_7 ( V_51 ) ;
F_17 ( V_8 -> V_54 . V_10 , V_52 ,
V_17 + sizeof( struct V_53 ) ) ;
V_52 -> V_22 . V_23 . V_24 = 0 ;
V_52 -> V_22 . V_23 . V_48 . V_56 = V_50 ;
F_3 ( V_32 , L_12 ,
* ( ( int * ) & V_52 -> V_22 . V_23 . V_33 [ 0 ] ) ) ;
V_51 -> V_28 = F_11 ( V_29 ) ;
F_9 (D_SKB) F_10 ( V_2 , V_51 , L_13 ) ;
F_12 ( V_51 ) ;
V_55:
F_18 ( V_8 -> V_54 . V_10 ) ;
V_8 -> V_54 . V_24 = NULL ;
return 0 ;
}
static void F_19 ( void )
{
int V_57 ;
for ( V_57 = 1 ; V_57 <= 8 ; V_57 ++ )
if ( V_58 [ V_57 ] == V_59 )
V_58 [ V_57 ] = & V_60 ;
if ( V_61 == V_59 )
V_61 = & V_60 ;
V_59 = & V_60 ;
V_62 = & V_60 ;
}
static int T_2 F_20 ( void )
{
F_21 ( V_63 ) ;
F_19 () ;
return 0 ;
}
static void T_3 F_22 ( void )
{
F_23 ( & V_60 ) ;
}
