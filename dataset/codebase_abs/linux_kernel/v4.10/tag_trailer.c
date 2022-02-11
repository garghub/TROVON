static struct V_1 * F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_7 ;
int V_8 ;
T_1 * V_9 ;
V_8 = 0 ;
if ( V_2 -> V_10 < 60 )
V_8 = 60 - V_2 -> V_10 ;
V_7 = F_3 ( V_11 + V_2 -> V_10 + V_8 + 4 , V_12 ) ;
if ( V_7 == NULL ) {
F_4 ( V_2 ) ;
return NULL ;
}
F_5 ( V_7 , V_11 ) ;
F_6 ( V_7 ) ;
F_7 ( V_7 , F_8 ( V_2 ) - V_2 -> V_13 ) ;
F_9 ( V_7 , F_10 ( V_2 ) - V_2 -> V_13 ) ;
F_11 ( V_2 , F_12 ( V_7 , V_2 -> V_10 ) ) ;
F_4 ( V_2 ) ;
if ( V_8 ) {
T_1 * V_14 = F_12 ( V_7 , V_8 ) ;
memset ( V_14 , 0 , V_8 ) ;
}
V_9 = F_12 ( V_7 , 4 ) ;
V_9 [ 0 ] = 0x80 ;
V_9 [ 1 ] = 1 << V_6 -> V_15 ;
V_9 [ 2 ] = 0x10 ;
V_9 [ 3 ] = 0x00 ;
return V_7 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_16 * V_17 , struct V_3 * V_18 )
{
struct V_19 * V_20 = V_4 -> V_21 ;
struct V_22 * V_23 ;
T_1 * V_9 ;
int V_24 ;
if ( F_14 ( V_20 == NULL ) )
goto V_25;
V_23 = V_20 -> V_23 [ 0 ] ;
V_2 = F_15 ( V_2 , V_12 ) ;
if ( V_2 == NULL )
goto V_26;
if ( F_16 ( V_2 ) )
goto V_25;
V_9 = F_17 ( V_2 ) - 4 ;
if ( V_9 [ 0 ] != 0x80 || ( V_9 [ 1 ] & 0xf8 ) != 0x00 ||
( V_9 [ 2 ] & 0xef ) != 0x00 || V_9 [ 3 ] != 0x00 )
goto V_25;
V_24 = V_9 [ 1 ] & 7 ;
if ( V_24 >= V_27 || ! V_23 -> V_28 [ V_24 ] . V_29 )
goto V_25;
F_18 ( V_2 , V_2 -> V_10 - 4 ) ;
V_2 -> V_4 = V_23 -> V_28 [ V_24 ] . V_29 ;
F_19 ( V_2 , V_30 ) ;
V_2 -> V_31 = V_32 ;
V_2 -> V_33 = F_20 ( V_2 , V_2 -> V_4 ) ;
V_2 -> V_4 -> V_34 . V_35 ++ ;
V_2 -> V_4 -> V_34 . V_36 += V_2 -> V_10 ;
F_21 ( V_2 ) ;
return 0 ;
V_25:
F_4 ( V_2 ) ;
V_26:
return 0 ;
}
