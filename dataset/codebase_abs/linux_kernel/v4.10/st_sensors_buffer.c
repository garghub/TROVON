static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = V_6 -> V_7 ;
F_3 (i, indio_dev->active_scan_mask, num_data_channels) {
const struct V_8 * V_9 = & V_2 -> V_10 [ V_4 ] ;
unsigned int V_11 =
F_4 ( V_9 -> V_12 . V_13 +
V_9 -> V_12 . V_14 , 8 ) ;
unsigned int V_15 =
V_9 -> V_12 . V_16 >> 3 ;
V_3 = F_5 ( V_3 , V_15 ) ;
if ( V_6 -> V_17 -> V_18 ( & V_6 -> V_19 , V_6 -> V_20 ,
V_9 -> V_21 ,
V_11 , V_3 ,
V_6 -> V_22 ) <
V_11 )
return - V_23 ;
V_3 += V_15 ;
}
return 0 ;
}
T_2 F_6 ( int V_24 , void * V_25 )
{
int V_26 ;
struct V_27 * V_28 = V_25 ;
struct V_1 * V_2 = V_28 -> V_2 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_3 V_29 ;
if ( F_7 ( V_2 ) )
V_29 = V_6 -> V_30 ;
else
V_29 = F_8 ( V_2 ) ;
V_26 = F_1 ( V_2 , V_6 -> V_31 ) ;
if ( V_26 < 0 )
goto V_32;
F_9 ( V_2 , V_6 -> V_31 ,
V_29 ) ;
V_32:
F_10 ( V_2 -> V_33 ) ;
return V_34 ;
}
