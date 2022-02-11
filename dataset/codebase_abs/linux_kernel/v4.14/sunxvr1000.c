static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_2 -> V_4 , L_1 , 0 ) ;
V_2 -> V_5 = F_2 ( V_2 -> V_4 , L_2 , 0 ) ;
V_2 -> V_6 = F_2 ( V_2 -> V_4 , L_3 , 32 ) ;
if ( ! V_2 -> V_3 || ! V_2 -> V_5 ) {
F_3 ( V_7 L_4 ,
V_2 -> V_4 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_4 ( unsigned V_9 ,
unsigned V_10 , unsigned V_11 , unsigned V_12 ,
unsigned V_13 , struct V_14 * V_15 )
{
T_1 V_16 ;
if ( V_9 < 16 ) {
V_10 >>= 8 ;
V_11 >>= 8 ;
V_12 >>= 8 ;
V_16 = ( V_12 << 16 ) | ( V_11 << 8 ) | V_10 ;
( ( T_1 * ) V_15 -> V_17 ) [ V_9 ] = V_16 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_18 * V_19 = & V_15 -> V_19 ;
V_15 -> V_20 = V_21 ;
V_15 -> V_22 = & V_23 ;
V_15 -> V_24 = V_2 -> V_25 ;
V_15 -> V_26 = V_2 -> V_27 ;
V_15 -> V_17 = V_2 -> V_17 ;
F_6 ( V_15 -> V_28 . V_29 , L_5 , sizeof( V_15 -> V_28 . V_29 ) ) ;
V_15 -> V_28 . V_30 = V_2 -> V_31 ;
V_15 -> V_28 . V_32 = V_2 -> V_27 ;
V_15 -> V_28 . type = V_33 ;
if ( V_2 -> V_6 == 32 || V_2 -> V_6 == 24 )
V_15 -> V_28 . V_34 = V_35 ;
else
V_15 -> V_28 . V_34 = V_36 ;
V_19 -> V_37 = V_2 -> V_3 ;
V_19 -> V_38 = V_2 -> V_5 ;
V_19 -> V_39 = V_19 -> V_37 ;
V_19 -> V_40 = V_19 -> V_38 ;
V_19 -> V_41 = V_2 -> V_6 ;
V_19 -> V_10 . V_42 = 0 ;
V_19 -> V_10 . V_43 = 8 ;
V_19 -> V_11 . V_42 = 8 ;
V_19 -> V_11 . V_43 = 8 ;
V_19 -> V_12 . V_42 = 16 ;
V_19 -> V_12 . V_43 = 8 ;
V_19 -> V_13 . V_42 = 0 ;
V_19 -> V_13 . V_43 = 0 ;
if ( F_7 ( & V_15 -> V_44 , 256 , 0 ) ) {
F_3 ( V_7 L_6 ) ;
return - V_45 ;
}
return 0 ;
}
static int F_8 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_50 . V_4 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_51 ;
V_15 = F_9 ( sizeof( struct V_1 ) , & V_47 -> V_50 ) ;
if ( ! V_15 ) {
F_3 ( V_7 L_7 ) ;
V_51 = - V_45 ;
goto V_52;
}
V_2 = V_15 -> V_53 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_4 = V_49 ;
V_2 -> V_31 = V_47 -> V_54 [ 6 ] . V_55 ;
V_51 = F_1 ( V_2 ) ;
if ( V_51 )
goto V_56;
V_15 -> V_28 . V_57 = 16384 ;
V_2 -> V_27 = V_15 -> V_28 . V_57 * V_2 -> V_5 ;
V_2 -> V_25 = F_10 ( & V_47 -> V_54 [ 6 ] , 0 ,
V_2 -> V_27 , L_8 ) ;
if ( ! V_2 -> V_25 ) {
V_51 = - V_45 ;
goto V_56;
}
V_51 = F_5 ( V_2 ) ;
if ( V_51 )
goto V_58;
F_3 ( L_9 , V_49 ) ;
V_51 = F_11 ( V_15 ) ;
if ( V_51 < 0 ) {
F_3 ( V_7 L_10 ,
V_49 ) ;
goto V_58;
}
F_12 ( & V_47 -> V_50 , V_15 ) ;
return 0 ;
V_58:
F_13 ( & V_47 -> V_54 [ 6 ] , V_2 -> V_25 , V_2 -> V_27 ) ;
V_56:
F_14 ( V_15 ) ;
V_52:
return V_51 ;
}
static int T_2 F_15 ( void )
{
if ( F_16 ( L_5 , NULL ) )
return - V_59 ;
return F_17 ( & V_60 ) ;
}
