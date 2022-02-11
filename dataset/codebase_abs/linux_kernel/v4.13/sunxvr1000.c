static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_2 -> V_4 , L_1 , 0 ) ;
V_2 -> V_5 = F_2 ( V_2 -> V_4 , L_2 , 0 ) ;
V_2 -> V_6 = F_2 ( V_2 -> V_4 , L_3 , 32 ) ;
if ( ! V_2 -> V_3 || ! V_2 -> V_5 ) {
F_3 ( V_7 L_4 ,
V_2 -> V_4 -> V_8 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_4 ( unsigned V_10 ,
unsigned V_11 , unsigned V_12 , unsigned V_13 ,
unsigned V_14 , struct V_15 * V_16 )
{
T_1 V_17 ;
if ( V_10 < 16 ) {
V_11 >>= 8 ;
V_12 >>= 8 ;
V_13 >>= 8 ;
V_17 = ( V_13 << 16 ) | ( V_12 << 8 ) | V_11 ;
( ( T_1 * ) V_16 -> V_18 ) [ V_10 ] = V_17 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_19 * V_20 = & V_16 -> V_20 ;
V_16 -> V_21 = V_22 ;
V_16 -> V_23 = & V_24 ;
V_16 -> V_25 = V_2 -> V_26 ;
V_16 -> V_27 = V_2 -> V_28 ;
V_16 -> V_18 = V_2 -> V_18 ;
F_6 ( V_16 -> V_29 . V_30 , L_5 , sizeof( V_16 -> V_29 . V_30 ) ) ;
V_16 -> V_29 . V_31 = V_2 -> V_32 ;
V_16 -> V_29 . V_33 = V_2 -> V_28 ;
V_16 -> V_29 . type = V_34 ;
if ( V_2 -> V_6 == 32 || V_2 -> V_6 == 24 )
V_16 -> V_29 . V_35 = V_36 ;
else
V_16 -> V_29 . V_35 = V_37 ;
V_20 -> V_38 = V_2 -> V_3 ;
V_20 -> V_39 = V_2 -> V_5 ;
V_20 -> V_40 = V_20 -> V_38 ;
V_20 -> V_41 = V_20 -> V_39 ;
V_20 -> V_42 = V_2 -> V_6 ;
V_20 -> V_11 . V_43 = 0 ;
V_20 -> V_11 . V_44 = 8 ;
V_20 -> V_12 . V_43 = 8 ;
V_20 -> V_12 . V_44 = 8 ;
V_20 -> V_13 . V_43 = 16 ;
V_20 -> V_13 . V_44 = 8 ;
V_20 -> V_14 . V_43 = 0 ;
V_20 -> V_14 . V_44 = 0 ;
if ( F_7 ( & V_16 -> V_45 , 256 , 0 ) ) {
F_3 ( V_7 L_6 ) ;
return - V_46 ;
}
return 0 ;
}
static int F_8 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_51 . V_4 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_52 ;
V_16 = F_9 ( sizeof( struct V_1 ) , & V_48 -> V_51 ) ;
if ( ! V_16 ) {
F_3 ( V_7 L_7 ) ;
V_52 = - V_46 ;
goto V_53;
}
V_2 = V_16 -> V_54 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_4 = V_50 ;
V_2 -> V_32 = V_48 -> V_55 [ 6 ] . V_56 ;
V_52 = F_1 ( V_2 ) ;
if ( V_52 )
goto V_57;
V_16 -> V_29 . V_58 = 16384 ;
V_2 -> V_28 = V_16 -> V_29 . V_58 * V_2 -> V_5 ;
V_2 -> V_26 = F_10 ( & V_48 -> V_55 [ 6 ] , 0 ,
V_2 -> V_28 , L_8 ) ;
if ( ! V_2 -> V_26 ) {
V_52 = - V_46 ;
goto V_57;
}
V_52 = F_5 ( V_2 ) ;
if ( V_52 )
goto V_59;
F_3 ( L_9 , V_50 -> V_8 ) ;
V_52 = F_11 ( V_16 ) ;
if ( V_52 < 0 ) {
F_3 ( V_7 L_10 ,
V_50 -> V_8 ) ;
goto V_59;
}
F_12 ( & V_48 -> V_51 , V_16 ) ;
return 0 ;
V_59:
F_13 ( & V_48 -> V_55 [ 6 ] , V_2 -> V_26 , V_2 -> V_28 ) ;
V_57:
F_14 ( V_16 ) ;
V_53:
return V_52 ;
}
static int T_2 F_15 ( void )
{
if ( F_16 ( L_5 , NULL ) )
return - V_60 ;
return F_17 ( & V_61 ) ;
}
