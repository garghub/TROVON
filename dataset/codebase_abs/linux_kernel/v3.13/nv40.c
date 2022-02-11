static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = ( void * ) V_2 ;
struct V_9 * V_10 = ( void * ) V_6 ;
T_1 log = V_6 -> V_11 ;
T_1 V_12 = 0x00000000 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < 4 && V_6 -> signal [ V_13 ] ; V_13 ++ )
V_12 |= ( V_6 -> signal [ V_13 ] - V_4 -> signal ) << ( V_13 * 8 ) ;
F_2 ( V_8 , 0x00a7c0 + V_4 -> V_14 , 0x00000001 ) ;
F_2 ( V_8 , 0x00a400 + V_4 -> V_14 + ( V_10 -> V_15 . V_16 * 0x40 ) , V_12 ) ;
F_2 ( V_8 , 0x00a420 + V_4 -> V_14 + ( V_10 -> V_15 . V_16 * 0x40 ) , log ) ;
}
static void
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = ( void * ) V_2 ;
struct V_9 * V_10 = ( void * ) V_6 ;
switch ( V_10 -> V_15 . V_16 ) {
case 0 : V_10 -> V_15 . V_6 = F_4 ( V_8 , 0x00a700 + V_4 -> V_14 ) ; break;
case 1 : V_10 -> V_15 . V_6 = F_4 ( V_8 , 0x00a6c0 + V_4 -> V_14 ) ; break;
case 2 : V_10 -> V_15 . V_6 = F_4 ( V_8 , 0x00a680 + V_4 -> V_14 ) ; break;
case 3 : V_10 -> V_15 . V_6 = F_4 ( V_8 , 0x00a740 + V_4 -> V_14 ) ; break;
}
V_10 -> V_15 . V_17 = F_4 ( V_8 , 0x00a600 + V_4 -> V_14 ) ;
}
static void
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = ( void * ) V_2 ;
if ( V_8 -> V_18 != V_2 -> V_18 ) {
F_2 ( V_8 , 0x400084 , 0x00000020 ) ;
V_8 -> V_18 = V_2 -> V_18 ;
}
}
int
F_6 ( struct V_19 * V_20 , struct V_19 * V_21 ,
struct V_22 * V_23 , void * V_24 , T_1 V_25 ,
struct V_19 * * V_26 )
{
struct V_27 * V_28 = ( void * ) V_23 ;
struct V_7 * V_8 ;
int V_29 ;
V_29 = F_7 ( V_20 , V_21 , V_23 , & V_8 ) ;
* V_26 = F_8 ( V_8 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_9 ( & V_8 -> V_15 , L_1 , 0 , 0 , 0 , 4 , V_28 -> V_30 ) ;
if ( V_29 )
return V_29 ;
F_10 ( V_8 ) -> V_31 = & V_32 ;
F_10 ( V_8 ) -> V_33 = V_34 ;
return 0 ;
}
