static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_8 = F_2 ( V_6 , sizeof( struct V_9 ) ) ;
if ( ! V_8 )
return - V_12 ;
V_10 = F_3 ( V_8 ) ;
V_11 = F_4 ( V_2 ) ;
if ( V_11 )
goto error;
V_11 = F_5 ( V_2 , V_13 ) ;
if ( V_11 )
goto error;
V_10 -> V_14 = F_6 ( V_2 , 0 , F_7 ( V_2 , 0 ) ) ;
if ( ! V_10 -> V_14 ) {
V_11 = - V_15 ;
goto error;
}
V_10 -> V_16 . V_17 = 0x1000 ;
V_10 -> V_16 . V_18 = 0x1008 ;
V_10 -> V_16 . V_19 = 0x1010 ;
V_10 -> V_16 . V_20 = 0x1080 ;
V_10 -> V_21 = F_8 ( V_6 , NULL ) ;
if ( F_9 ( V_10 -> V_21 ) ) {
V_11 = F_10 ( V_10 -> V_21 ) ;
goto error;
}
V_11 = F_11 ( V_10 -> V_21 ) ;
if ( V_11 )
goto error;
V_10 -> V_22 = F_12 ( V_10 -> V_21 ) ;
if ( ! V_10 -> V_22 )
V_10 -> V_22 = V_23 ;
F_13 ( V_6 , L_1 , V_10 -> V_22 ) ;
V_8 -> V_24 = 4 ;
V_8 -> V_25 = V_26 | V_27 | V_28 |
V_29 | V_30 ;
V_8 -> V_31 = V_32 ;
V_8 -> V_33 = F_14 ( 8 ) ;
V_8 -> V_34 = V_35 ;
V_8 -> V_6 . V_36 = V_2 -> V_6 . V_36 ;
F_15 ( V_2 , V_8 ) ;
V_11 = F_16 ( V_6 , V_8 ) ;
if ( V_11 )
goto error;
return 0 ;
error:
F_17 ( V_10 -> V_21 ) ;
F_18 ( V_8 ) ;
return V_11 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_20 ( V_2 ) ;
struct V_9 * V_10 ;
V_10 = F_3 ( V_8 ) ;
if ( ! V_10 )
return;
F_17 ( V_10 -> V_21 ) ;
F_21 ( 0 , V_10 -> V_14 + F_22 ( V_10 ) ) ;
}
