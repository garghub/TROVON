T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_7 ;
int V_8 ;
T_2 * V_9 ;
V_4 -> V_10 . V_11 ++ ;
V_4 -> V_10 . V_12 += V_2 -> V_13 ;
V_8 = 0 ;
if ( V_2 -> V_13 < 60 )
V_8 = 60 - V_2 -> V_13 ;
V_7 = F_3 ( V_14 + V_2 -> V_13 + V_8 + 4 , V_15 ) ;
if ( V_7 == NULL ) {
F_4 ( V_2 ) ;
return V_16 ;
}
F_5 ( V_7 , V_14 ) ;
F_6 ( V_7 ) ;
F_7 ( V_7 , F_8 ( V_2 ) - V_2 -> V_17 ) ;
F_9 ( V_7 , F_10 ( V_2 ) - V_2 -> V_17 ) ;
F_11 ( V_2 , F_12 ( V_7 , V_2 -> V_13 ) ) ;
F_4 ( V_2 ) ;
if ( V_8 ) {
T_2 * V_18 = F_12 ( V_7 , V_8 ) ;
memset ( V_18 , 0 , V_8 ) ;
}
V_9 = F_12 ( V_7 , 4 ) ;
V_9 [ 0 ] = 0x80 ;
V_9 [ 1 ] = 1 << V_6 -> V_19 ;
V_9 [ 2 ] = 0x10 ;
V_9 [ 3 ] = 0x00 ;
V_7 -> V_20 = F_13 ( V_21 ) ;
V_7 -> V_4 = V_6 -> V_22 -> V_23 -> V_24 ;
F_14 ( V_7 ) ;
return V_16 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_25 * V_26 , struct V_3 * V_27 )
{
struct V_28 * V_23 = V_4 -> V_29 ;
struct V_30 * V_31 ;
T_2 * V_9 ;
int V_32 ;
if ( F_16 ( V_23 == NULL ) )
goto V_33;
V_31 = V_23 -> V_31 [ 0 ] ;
V_2 = F_17 ( V_2 , V_15 ) ;
if ( V_2 == NULL )
goto V_34;
if ( F_18 ( V_2 ) )
goto V_33;
V_9 = F_19 ( V_2 ) - 4 ;
if ( V_9 [ 0 ] != 0x80 || ( V_9 [ 1 ] & 0xf8 ) != 0x00 ||
( V_9 [ 3 ] & 0xef ) != 0x00 || V_9 [ 3 ] != 0x00 )
goto V_33;
V_32 = V_9 [ 1 ] & 7 ;
if ( V_32 >= V_35 || V_31 -> V_36 [ V_32 ] == NULL )
goto V_33;
F_20 ( V_2 , V_2 -> V_13 - 4 ) ;
V_2 -> V_4 = V_31 -> V_36 [ V_32 ] ;
F_21 ( V_2 , V_37 ) ;
V_2 -> V_38 = V_39 ;
V_2 -> V_20 = F_22 ( V_2 , V_2 -> V_4 ) ;
V_2 -> V_4 -> V_10 . V_40 ++ ;
V_2 -> V_4 -> V_10 . V_41 += V_2 -> V_13 ;
F_23 ( V_2 ) ;
return 0 ;
V_33:
F_4 ( V_2 ) ;
V_34:
return 0 ;
}
static int T_3 F_24 ( void )
{
F_25 ( & V_42 ) ;
return 0 ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_42 ) ;
}
