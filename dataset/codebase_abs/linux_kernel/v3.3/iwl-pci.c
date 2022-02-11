static T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_5 ) ;
F_4 ( V_5 , V_3 + V_6 , & V_4 ) ;
return V_4 ;
}
static bool F_5 ( struct V_1 * V_2 )
{
T_1 V_7 = F_1 ( V_2 ) ;
return ! ( V_7 & V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_7 = F_1 ( V_2 ) ;
if ( ( V_7 & V_9 ) ==
V_9 ) {
F_7 ( V_2 , V_10 ,
V_11 ) ;
F_8 ( V_12 , V_2 -> V_13 , L_1 ) ;
} else {
F_9 ( V_2 , V_10 ,
V_11 ) ;
F_8 ( V_12 , V_2 -> V_13 , L_2 ) ;
}
}
static void F_10 ( struct V_1 * V_2 , char V_14 [] ,
int V_15 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
snprintf ( V_14 , V_15 , L_3 , V_5 -> V_16 ,
V_5 -> V_17 ) ;
}
static T_2 F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
return ( V_5 -> V_16 << 16 ) + V_5 -> V_17 ;
}
static void F_12 ( struct V_1 * V_2 , T_2 V_18 , T_3 V_19 )
{
F_13 ( V_19 , F_14 ( V_2 ) -> V_20 + V_18 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_2 V_18 , T_2 V_19 )
{
F_16 ( V_19 , F_14 ( V_2 ) -> V_20 + V_18 ) ;
}
static T_2 F_17 ( struct V_1 * V_2 , T_2 V_18 )
{
T_2 V_19 = F_18 ( F_14 ( V_2 ) -> V_20 + V_18 ) ;
return V_19 ;
}
static int F_19 ( struct V_5 * V_21 , const struct V_22 * V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) ( V_23 -> V_26 ) ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
T_1 V_29 ;
int V_30 ;
V_2 = F_20 ( sizeof( * V_2 ) + sizeof( * V_28 ) , V_31 ) ;
if ( ! V_2 ) {
F_8 ( V_32 , & V_21 -> V_13 ,
L_4 ) ;
V_30 = - V_33 ;
goto V_34;
}
V_28 = F_14 ( V_2 ) ;
V_28 -> V_5 = V_21 ;
F_21 ( V_21 , V_2 ) ;
F_22 ( V_21 , V_35 | V_36 |
V_37 ) ;
if ( F_23 ( V_21 ) ) {
V_30 = - V_38 ;
goto V_34;
}
F_24 ( V_21 ) ;
V_30 = F_25 ( V_21 , F_26 ( 36 ) ) ;
if ( ! V_30 )
V_30 = F_27 ( V_21 , F_26 ( 36 ) ) ;
if ( V_30 ) {
V_30 = F_25 ( V_21 , F_26 ( 32 ) ) ;
if ( ! V_30 )
V_30 = F_27 ( V_21 ,
F_26 ( 32 ) ) ;
if ( V_30 ) {
F_8 ( V_32 , V_2 -> V_13 ,
L_5 ) ;
goto V_39;
}
}
V_30 = F_28 ( V_21 , V_40 ) ;
if ( V_30 ) {
F_8 ( V_32 , V_2 -> V_13 , L_6 ) ;
goto V_39;
}
V_28 -> V_20 = F_29 ( V_21 , 0 , 0 ) ;
if ( ! V_28 -> V_20 ) {
F_8 ( V_32 , V_2 -> V_13 , L_7 ) ;
V_30 = - V_38 ;
goto V_41;
}
F_8 ( V_12 , & V_21 -> V_13 ,
L_8 ,
( unsigned long long ) F_30 ( V_21 , 0 ) ) ;
F_8 ( V_12 , & V_21 -> V_13 ,
L_9 , V_28 -> V_20 ) ;
F_8 ( V_12 , & V_21 -> V_13 ,
L_10 , V_21 -> V_42 ) ;
F_31 ( V_21 , V_43 , 0x00 ) ;
V_30 = F_32 ( V_21 ) ;
if ( V_30 )
F_8 ( V_32 , & V_21 -> V_13 ,
L_11 , V_30 ) ;
F_4 ( V_21 , V_44 , & V_29 ) ;
if ( V_29 & V_45 ) {
V_29 &= ~ V_45 ;
F_33 ( V_21 , V_44 , V_29 ) ;
}
V_2 -> V_13 = & V_21 -> V_13 ;
V_2 -> V_46 = V_21 -> V_46 ;
V_2 -> V_47 = & V_48 ;
V_30 = F_34 ( V_2 , & V_49 , V_25 ) ;
if ( V_30 )
goto V_50;
return 0 ;
V_50:
F_35 ( V_21 ) ;
F_36 ( V_21 , V_28 -> V_20 ) ;
V_41:
F_21 ( V_21 , NULL ) ;
F_37 ( V_21 ) ;
V_39:
F_38 ( V_21 ) ;
V_34:
F_39 ( V_2 ) ;
return V_30 ;
}
static void T_4 F_40 ( struct V_5 * V_21 )
{
struct V_1 * V_2 = F_41 ( V_21 ) ;
struct V_27 * V_28 = F_14 ( V_2 ) ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
struct V_51 * V_52 = V_2 -> V_52 ;
F_42 ( V_52 -> V_53 ) ;
F_35 ( V_5 ) ;
F_36 ( V_5 , V_28 -> V_20 ) ;
F_37 ( V_5 ) ;
F_38 ( V_5 ) ;
F_21 ( V_5 , NULL ) ;
F_39 ( V_2 ) ;
}
static int F_43 ( struct V_16 * V_16 )
{
struct V_5 * V_21 = F_44 ( V_16 ) ;
struct V_1 * V_2 = F_41 ( V_21 ) ;
struct V_51 * V_52 = V_2 -> V_52 ;
return F_45 ( V_52 -> V_54 ) ;
}
static int F_46 ( struct V_16 * V_16 )
{
struct V_5 * V_21 = F_44 ( V_16 ) ;
struct V_1 * V_2 = F_41 ( V_21 ) ;
struct V_51 * V_52 = V_2 -> V_52 ;
F_31 ( V_21 , V_43 , 0x00 ) ;
return F_47 ( V_52 -> V_54 ) ;
}
int T_5 F_48 ( void )
{
int V_55 ;
V_55 = F_49 ( & V_56 ) ;
if ( V_55 )
F_50 ( L_12 ) ;
return V_55 ;
}
void F_51 ( void )
{
F_52 ( & V_56 ) ;
}
