static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
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
V_7 -> V_4 = V_6 -> V_20 -> V_21 -> V_22 ;
F_13 ( V_7 ) ;
return V_16 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_23 * V_24 , struct V_3 * V_25 )
{
struct V_26 * V_21 = V_4 -> V_27 ;
struct V_28 * V_29 ;
T_2 * V_9 ;
int V_30 ;
if ( F_15 ( V_21 == NULL ) )
goto V_31;
V_29 = V_21 -> V_29 [ 0 ] ;
V_2 = F_16 ( V_2 , V_15 ) ;
if ( V_2 == NULL )
goto V_32;
if ( F_17 ( V_2 ) )
goto V_31;
V_9 = F_18 ( V_2 ) - 4 ;
if ( V_9 [ 0 ] != 0x80 || ( V_9 [ 1 ] & 0xf8 ) != 0x00 ||
( V_9 [ 3 ] & 0xef ) != 0x00 || V_9 [ 3 ] != 0x00 )
goto V_31;
V_30 = V_9 [ 1 ] & 7 ;
if ( V_30 >= V_33 || V_29 -> V_34 [ V_30 ] == NULL )
goto V_31;
F_19 ( V_2 , V_2 -> V_13 - 4 ) ;
V_2 -> V_4 = V_29 -> V_34 [ V_30 ] ;
F_20 ( V_2 , V_35 ) ;
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = F_21 ( V_2 , V_2 -> V_4 ) ;
V_2 -> V_4 -> V_10 . V_39 ++ ;
V_2 -> V_4 -> V_10 . V_40 += V_2 -> V_13 ;
F_22 ( V_2 ) ;
return 0 ;
V_31:
F_4 ( V_2 ) ;
V_32:
return 0 ;
}
