static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 -> V_4 . V_5 ) ;
F_3 ( V_3 -> V_6 ) ;
F_4 ( V_3 -> V_7 ,
V_3 -> V_8 + V_9 ) ;
F_4 ( V_10 | V_11 | V_12 | V_13 |
V_14 , V_3 -> V_8 + V_15 ) ;
F_4 ( F_5 ( 0x5 ) | V_16 | F_6 ( 0x5 ) ,
V_3 -> V_8 + V_17 ) ;
F_4 ( V_18 | V_19 | V_20 |
V_21 | F_7 ( 0xa ) | F_8 ( 0x2 ) |
V_22 , V_3 -> V_8 + V_23 ) ;
F_4 ( V_24 | F_9 ( 0x3 ) , V_3 -> V_8 + V_25 ) ;
F_4 ( V_26 | F_10 ( 0x3 ) | F_11 ( 0x4 ) ,
V_3 -> V_8 + V_27 ) ;
F_4 ( V_26 | F_10 ( 0x3 ) | F_11 ( 0x4 ) |
F_12 ( 0x2 ) , V_3 -> V_8 + V_27 ) ;
F_4 ( V_26 | F_10 ( 0x3 ) | F_11 ( 0x4 ) ,
V_3 -> V_8 + V_27 ) ;
F_4 ( F_13 ( 0xf ) | F_14 ( 0x3 ) | V_28 |
F_15 ( 0xd ) , V_3 -> V_8 + V_29 ) ;
return 0 ;
}
static int F_16 ( struct V_30 * V_31 )
{
const struct V_32 * V_33 =
F_17 ( V_34 , & V_31 -> V_4 ) ;
struct V_2 * V_3 ;
struct V_35 * V_36 ;
struct V_37 * V_37 ;
V_3 = F_18 ( & V_31 -> V_4 , sizeof( * V_3 ) , V_38 ) ;
if ( ! V_3 )
return - V_39 ;
V_36 = F_19 ( V_31 , V_40 , 0 ) ;
V_3 -> V_8 = F_20 ( & V_31 -> V_4 , V_36 ) ;
if ( F_21 ( V_3 -> V_8 ) )
return F_22 ( V_3 -> V_8 ) ;
V_3 -> V_6 = F_23 ( & V_31 -> V_4 , NULL ) ;
if ( F_21 ( V_3 -> V_6 ) )
return F_22 ( V_3 -> V_6 ) ;
V_3 -> V_7 = * ( ( V_41 * ) V_33 -> V_42 ) ;
V_3 -> V_1 = F_24 ( & V_31 -> V_4 , NULL , & V_43 ) ;
if ( F_21 ( V_3 -> V_1 ) ) {
F_25 ( & V_31 -> V_4 , L_1 ) ;
return F_22 ( V_3 -> V_1 ) ;
}
F_26 ( V_31 , V_3 ) ;
V_37 =
F_27 ( & V_31 -> V_4 , V_44 ) ;
if ( F_21 ( V_37 ) )
return F_22 ( V_37 ) ;
return 0 ;
}
