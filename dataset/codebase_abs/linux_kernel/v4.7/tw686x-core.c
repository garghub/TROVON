void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 = F_2 ( V_2 , V_5 ) ;
T_1 V_6 = F_2 ( V_2 , V_7 ) ;
V_4 &= ~ F_3 ( V_3 ) ;
V_6 &= ~ F_3 ( V_3 ) ;
V_2 -> V_8 &= ~ F_3 ( V_3 ) ;
V_2 -> V_9 &= ~ F_3 ( V_3 ) ;
if ( ! V_4 )
V_6 = 0 ;
F_4 ( V_2 , V_5 , V_4 ) ;
F_4 ( V_2 , V_7 , V_6 ) ;
}
void F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 = F_2 ( V_2 , V_5 ) ;
T_1 V_6 = F_2 ( V_2 , V_7 ) ;
V_2 -> V_8 |= V_4 | F_3 ( V_3 ) ;
V_2 -> V_9 |= V_6 | V_10 | F_3 ( V_3 ) ;
}
static void F_6 ( unsigned long V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_11 ;
unsigned long V_12 ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_4 ( V_2 , V_5 , V_2 -> V_8 ) ;
F_4 ( V_2 , V_7 , V_2 -> V_9 ) ;
V_2 -> V_8 = 0 ;
V_2 -> V_9 = 0 ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_14 )
{
T_1 V_4 , V_6 ;
V_4 = F_2 ( V_2 , V_5 ) ;
V_6 = F_2 ( V_2 , V_7 ) ;
V_2 -> V_8 |= V_4 ;
V_2 -> V_9 |= V_6 ;
F_4 ( V_2 , V_5 , V_4 & ~ V_14 ) ;
if ( ( V_4 & ~ V_14 ) == 0 ) {
F_10 ( & V_2 -> V_15 -> V_2 , L_1 ) ;
V_6 &= ~ V_10 ;
}
F_4 ( V_2 , V_7 , V_6 & ~ V_14 ) ;
}
static T_2 F_11 ( int V_16 , void * V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
unsigned int V_18 , V_19 , V_20 ;
T_1 V_21 , V_22 , V_23 , V_24 , V_25 ;
T_1 V_26 , V_4 , V_27 , V_28 ;
unsigned long V_12 ;
V_26 = F_2 ( V_2 , V_29 ) ;
V_21 = F_2 ( V_2 , V_30 ) ;
if ( ! V_26 && ! F_12 ( V_21 ) )
return V_31 ;
if ( V_26 & V_32 ) {
F_10 ( & V_2 -> V_15 -> V_2 ,
L_2 ) ;
V_20 = ~ 0 ;
goto V_33;
}
F_7 ( & V_2 -> V_13 , V_12 ) ;
V_4 = F_2 ( V_2 , V_5 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
V_27 = V_4 & 0xff ;
V_22 = ~ ( V_21 & 0xff ) & V_27 ;
V_23 = V_21 >> 24 ;
V_24 = V_21 >> 16 ;
V_25 = V_22 & ( V_23 | V_24 ) ;
V_20 = 0 ;
V_28 = F_2 ( V_2 , V_34 ) ;
V_18 = ( V_26 & V_27 ) | V_25 ;
V_19 = ( V_26 & V_4 ) >> 8 ;
if ( V_18 )
F_13 ( V_2 , V_18 , V_28 ,
V_21 , & V_20 ) ;
if ( V_19 )
F_14 ( V_2 , V_19 , V_28 ) ;
V_33:
if ( V_20 ) {
F_7 ( & V_2 -> V_13 , V_12 ) ;
F_9 ( V_2 , V_20 ) ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
F_15 ( & V_2 -> V_35 ,
V_36 + F_16 ( 100 ) ) ;
}
return V_37 ;
}
static void F_17 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_18 ( V_39 , struct V_1 ,
V_39 ) ;
unsigned int V_40 ;
for ( V_40 = 0 ; V_40 < F_19 ( V_2 ) ; V_40 ++ )
F_20 ( & V_2 -> V_41 [ V_40 ] . V_42 ) ;
F_21 ( & V_2 -> V_39 ) ;
F_22 ( V_2 -> V_43 ) ;
F_22 ( V_2 -> V_41 ) ;
F_22 ( V_2 ) ;
}
static int F_23 ( struct V_15 * V_15 ,
const struct V_44 * V_45 )
{
struct V_1 * V_2 ;
int V_46 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return - V_48 ;
V_2 -> type = V_45 -> V_49 ;
sprintf ( V_2 -> V_50 , L_3 , V_15 -> V_51 ) ;
V_2 -> V_41 = F_25 ( F_19 ( V_2 ) ,
sizeof( * V_2 -> V_41 ) , V_47 ) ;
if ( ! V_2 -> V_41 ) {
V_46 = - V_48 ;
goto V_52;
}
V_2 -> V_43 = F_25 ( F_19 ( V_2 ) ,
sizeof( * V_2 -> V_43 ) , V_47 ) ;
if ( ! V_2 -> V_43 ) {
V_46 = - V_48 ;
goto V_53;
}
F_26 ( L_4 , V_2 -> V_50 ,
F_27 ( V_15 ) , V_15 -> V_16 ,
( unsigned long ) F_28 ( V_15 , 0 ) ) ;
V_2 -> V_15 = V_15 ;
if ( F_29 ( V_15 ) ) {
V_46 = - V_54 ;
goto V_55;
}
F_30 ( V_15 ) ;
V_46 = F_31 ( V_15 , F_32 ( 32 ) ) ;
if ( V_46 ) {
F_33 ( & V_15 -> V_2 , L_5 ) ;
V_46 = - V_54 ;
goto V_56;
}
V_46 = F_34 ( V_15 , V_2 -> V_50 ) ;
if ( V_46 ) {
F_33 ( & V_15 -> V_2 , L_6 ) ;
goto V_56;
}
V_2 -> V_57 = F_35 ( V_15 , 0 ) ;
if ( ! V_2 -> V_57 ) {
F_33 ( & V_15 -> V_2 , L_7 ) ;
V_46 = - V_48 ;
goto V_58;
}
F_4 ( V_2 , V_59 , 0x0f ) ;
F_36 ( 1 ) ;
F_4 ( V_2 , V_60 [ 0 ] , 0x3f ) ;
if ( F_19 ( V_2 ) > 4 )
F_4 ( V_2 , V_60 [ 1 ] , 0x3f ) ;
F_4 ( V_2 , V_7 , 0 ) ;
F_4 ( V_2 , V_5 , 0 ) ;
F_4 ( V_2 , V_61 , 0xffffff04 ) ;
F_4 ( V_2 , V_62 , 0x140c8584 ) ;
F_4 ( V_2 , V_63 , V_64 ) ;
F_37 ( & V_2 -> V_13 ) ;
V_46 = F_38 ( V_15 -> V_16 , F_11 , V_65 ,
V_2 -> V_50 , V_2 ) ;
if ( V_46 < 0 ) {
F_33 ( & V_15 -> V_2 , L_8 ) ;
goto V_66;
}
F_39 ( & V_2 -> V_35 ,
F_6 , ( unsigned long ) V_2 ) ;
V_2 -> V_39 . V_67 = F_17 ;
V_46 = F_40 ( V_2 ) ;
if ( V_46 ) {
F_33 ( & V_15 -> V_2 , L_9 ) ;
goto V_68;
}
V_46 = F_41 ( V_2 ) ;
if ( V_46 )
F_42 ( & V_15 -> V_2 , L_10 ) ;
F_43 ( V_15 , V_2 ) ;
return 0 ;
V_68:
V_68 ( V_15 -> V_16 , V_2 ) ;
V_66:
F_44 ( V_15 , V_2 -> V_57 ) ;
V_58:
F_45 ( V_15 ) ;
V_56:
F_46 ( V_15 ) ;
V_55:
F_22 ( V_2 -> V_43 ) ;
V_53:
F_22 ( V_2 -> V_41 ) ;
V_52:
F_22 ( V_2 ) ;
return V_46 ;
}
static void F_47 ( struct V_15 * V_15 )
{
struct V_1 * V_2 = F_48 ( V_15 ) ;
unsigned long V_12 ;
V_68 ( V_15 -> V_16 , V_2 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
F_51 ( & V_2 -> V_35 ) ;
F_44 ( V_15 , V_2 -> V_57 ) ;
F_45 ( V_15 ) ;
F_46 ( V_15 ) ;
F_7 ( & V_2 -> V_13 , V_12 ) ;
V_2 -> V_15 = NULL ;
F_8 ( & V_2 -> V_13 , V_12 ) ;
F_52 ( & V_2 -> V_39 ) ;
}
