static int T_1 F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( V_2 -> V_4 , L_1 , 0 ) ;
V_2 -> V_5 = F_2 ( V_2 -> V_4 , L_2 , 0 ) ;
V_2 -> V_6 = F_2 ( V_2 -> V_4 , L_3 , 8 ) ;
if ( ! V_2 -> V_3 || ! V_2 -> V_5 ) {
F_3 ( V_7 L_4 ,
F_4 ( V_2 -> V_8 ) ) ;
return - V_9 ;
}
return 0 ;
}
static int F_5 ( unsigned V_10 ,
unsigned V_11 , unsigned V_12 , unsigned V_13 ,
unsigned V_14 , struct V_15 * V_16 )
{
T_2 V_17 ;
if ( V_10 < 16 ) {
V_11 >>= 8 ;
V_12 >>= 8 ;
V_13 >>= 8 ;
V_17 = ( V_13 << 24 ) | ( V_12 << 16 ) | ( V_11 << 8 ) ;
( ( T_2 * ) V_16 -> V_18 ) [ V_10 ] = V_17 ;
}
return 0 ;
}
static int T_1 F_6 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
struct V_19 * V_20 = & V_16 -> V_20 ;
V_16 -> V_21 = V_22 ;
V_16 -> V_23 = & V_24 ;
V_16 -> V_25 = V_2 -> V_26 ;
V_16 -> V_27 = V_2 -> V_28 ;
V_16 -> V_18 = V_2 -> V_18 ;
F_7 ( V_16 -> V_29 . V_30 , L_5 , sizeof( V_16 -> V_29 . V_30 ) ) ;
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
V_20 -> V_11 . V_43 = 8 ;
V_20 -> V_11 . V_44 = 8 ;
V_20 -> V_12 . V_43 = 16 ;
V_20 -> V_12 . V_44 = 8 ;
V_20 -> V_13 . V_43 = 24 ;
V_20 -> V_13 . V_44 = 8 ;
V_20 -> V_14 . V_43 = 0 ;
V_20 -> V_14 . V_44 = 0 ;
if ( F_8 ( & V_16 -> V_45 , 256 , 0 ) ) {
F_3 ( V_7 L_6 ) ;
return - V_46 ;
}
return 0 ;
}
static int T_1 F_9 ( struct V_47 * V_8 ,
const struct V_48 * V_49 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_50 ;
V_50 = F_10 ( V_8 ) ;
if ( V_50 < 0 ) {
F_3 ( V_7 L_7 ,
F_4 ( V_8 ) ) ;
goto V_51;
}
V_16 = F_11 ( sizeof( struct V_1 ) , & V_8 -> V_52 ) ;
if ( ! V_16 ) {
F_3 ( V_7 L_8 ) ;
V_50 = - V_46 ;
goto V_53;
}
V_2 = V_16 -> V_54 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_4 = F_12 ( V_8 ) ;
if ( ! V_2 -> V_4 ) {
F_3 ( V_7 L_9 ,
F_4 ( V_8 ) ) ;
V_50 = - V_55 ;
goto V_56;
}
V_2 -> V_32 = F_13 ( V_8 , 1 ) ;
V_50 = F_14 ( V_8 , 1 , L_10 ) ;
if ( V_50 < 0 ) {
F_3 ( L_11 ,
F_4 ( V_8 ) ) ;
goto V_56;
}
V_50 = F_1 ( V_2 ) ;
if ( V_50 )
goto V_57;
switch ( V_2 -> V_6 ) {
case 8 :
V_16 -> V_29 . V_58 = V_2 -> V_3 ;
break;
case 16 :
V_16 -> V_29 . V_58 = V_2 -> V_3 * 2 ;
break;
case 24 :
V_16 -> V_29 . V_58 = V_2 -> V_3 * 3 ;
break;
case 32 :
V_16 -> V_29 . V_58 = V_2 -> V_3 * 4 ;
break;
}
V_2 -> V_28 = V_16 -> V_29 . V_58 * V_2 -> V_5 ;
V_2 -> V_26 = F_15 ( V_2 -> V_32 , V_2 -> V_28 ) ;
if ( ! V_2 -> V_26 ) {
V_50 = - V_46 ;
goto V_57;
}
V_50 = F_6 ( V_2 ) ;
if ( V_50 )
goto V_59;
F_16 ( V_8 , V_16 ) ;
F_3 ( L_12 , F_4 ( V_8 ) ) ;
V_50 = F_17 ( V_16 ) ;
if ( V_50 < 0 ) {
F_3 ( V_7 L_13 ,
F_4 ( V_8 ) ) ;
goto V_59;
}
return 0 ;
V_59:
F_18 ( V_2 -> V_26 ) ;
V_57:
F_19 ( V_8 , 1 ) ;
V_56:
F_20 ( V_16 ) ;
V_53:
F_21 ( V_8 ) ;
V_51:
return V_50 ;
}
static void T_3 F_22 ( struct V_47 * V_8 )
{
struct V_15 * V_16 = F_23 ( V_8 ) ;
struct V_1 * V_2 = V_16 -> V_54 ;
F_24 ( V_16 ) ;
F_18 ( V_2 -> V_26 ) ;
F_19 ( V_8 , 1 ) ;
F_20 ( V_16 ) ;
F_21 ( V_8 ) ;
}
static int T_4 F_25 ( void )
{
if ( F_26 ( L_5 , NULL ) )
return - V_55 ;
return F_27 ( & V_60 ) ;
}
static void T_5 F_28 ( void )
{
F_29 ( & V_60 ) ;
}
