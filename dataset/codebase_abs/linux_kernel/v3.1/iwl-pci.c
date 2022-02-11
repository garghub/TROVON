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
F_7 ( V_2 -> V_10 , V_11 ,
V_12 ) ;
F_8 ( V_13 , V_2 -> V_14 , L_1 ) ;
} else {
F_9 ( V_2 -> V_10 , V_11 ,
V_12 ) ;
F_8 ( V_13 , V_2 -> V_14 , L_2 ) ;
}
}
static void F_10 ( struct V_1 * V_2 , void * V_10 )
{
V_2 -> V_10 = V_10 ;
F_11 ( F_2 ( V_2 ) , V_10 ) ;
}
static void F_12 ( struct V_1 * V_2 , char V_15 [] ,
int V_16 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
snprintf ( V_15 , V_16 , L_3 , V_5 -> V_17 ,
V_5 -> V_18 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_2 V_19 , T_3 V_20 )
{
F_14 ( V_20 , F_15 ( V_2 ) -> V_21 + V_19 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_2 V_19 , T_2 V_20 )
{
F_17 ( V_20 , F_15 ( V_2 ) -> V_21 + V_19 ) ;
}
static T_2 F_18 ( struct V_1 * V_2 , T_2 V_19 )
{
T_2 V_20 = F_19 ( F_15 ( V_2 ) -> V_21 + V_19 ) ;
return V_20 ;
}
static int F_20 ( struct V_5 * V_22 , const struct V_23 * V_24 )
{
struct V_25 * V_26 = (struct V_25 * ) ( V_24 -> V_27 ) ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
T_1 V_30 ;
int V_31 ;
V_2 = F_21 ( sizeof( * V_2 ) + sizeof( * V_29 ) , V_32 ) ;
if ( ! V_2 ) {
F_8 ( V_33 , & V_22 -> V_14 ,
L_4 ) ;
V_31 = - V_34 ;
goto V_35;
}
V_29 = F_15 ( V_2 ) ;
V_29 -> V_5 = V_22 ;
F_22 ( V_22 , V_36 | V_37 |
V_38 ) ;
if ( F_23 ( V_22 ) ) {
V_31 = - V_39 ;
goto V_35;
}
F_24 ( V_22 ) ;
V_31 = F_25 ( V_22 , F_26 ( 36 ) ) ;
if ( ! V_31 )
V_31 = F_27 ( V_22 , F_26 ( 36 ) ) ;
if ( V_31 ) {
V_31 = F_25 ( V_22 , F_26 ( 32 ) ) ;
if ( ! V_31 )
V_31 = F_27 ( V_22 ,
F_26 ( 32 ) ) ;
if ( V_31 ) {
F_8 ( V_33 , V_2 -> V_14 ,
L_5 ) ;
goto V_40;
}
}
V_31 = F_28 ( V_22 , V_41 ) ;
if ( V_31 ) {
F_8 ( V_33 , V_2 -> V_14 , L_6 ) ;
goto V_40;
}
V_29 -> V_21 = F_29 ( V_22 , 0 , 0 ) ;
if ( ! V_29 -> V_21 ) {
F_8 ( V_33 , V_2 -> V_14 , L_7 ) ;
V_31 = - V_39 ;
goto V_42;
}
F_8 ( V_13 , & V_22 -> V_14 ,
L_8 ,
( unsigned long long ) F_30 ( V_22 , 0 ) ) ;
F_8 ( V_13 , & V_22 -> V_14 ,
L_9 , V_29 -> V_21 ) ;
F_8 ( V_13 , & V_22 -> V_14 ,
L_10 , V_22 -> V_43 ) ;
F_31 ( V_22 , V_44 , 0x00 ) ;
V_31 = F_32 ( V_22 ) ;
if ( V_31 ) {
F_8 ( V_33 , & V_22 -> V_14 , L_11 ) ;
goto V_45;
}
F_4 ( V_22 , V_46 , & V_30 ) ;
if ( V_30 & V_47 ) {
V_30 &= ~ V_47 ;
F_33 ( V_22 , V_46 , V_30 ) ;
}
V_2 -> V_14 = & V_22 -> V_14 ;
V_2 -> V_48 = V_22 -> V_48 ;
V_2 -> V_49 = & V_50 ;
V_31 = F_34 ( V_2 , V_26 ) ;
if ( V_31 )
goto V_51;
return 0 ;
V_51:
F_35 ( V_22 ) ;
V_45:
F_36 ( V_22 , V_29 -> V_21 ) ;
V_42:
F_11 ( V_22 , NULL ) ;
F_37 ( V_22 ) ;
V_40:
F_38 ( V_22 ) ;
V_35:
F_39 ( V_2 ) ;
return V_31 ;
}
static void T_4 F_40 ( struct V_5 * V_22 )
{
struct V_52 * V_53 = F_41 ( V_22 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_28 * V_29 = F_15 ( V_2 ) ;
struct V_5 * V_5 = F_2 ( V_2 ) ;
F_42 ( V_53 ) ;
F_35 ( V_5 ) ;
F_36 ( V_5 , V_29 -> V_21 ) ;
F_37 ( V_5 ) ;
F_38 ( V_5 ) ;
F_11 ( V_5 , NULL ) ;
F_39 ( V_2 ) ;
}
static int F_43 ( struct V_17 * V_17 )
{
struct V_5 * V_22 = F_44 ( V_17 ) ;
struct V_52 * V_53 = F_41 ( V_22 ) ;
return F_45 ( V_53 ) ;
}
static int F_46 ( struct V_17 * V_17 )
{
struct V_5 * V_22 = F_44 ( V_17 ) ;
struct V_52 * V_53 = F_41 ( V_22 ) ;
F_31 ( V_22 , V_44 , 0x00 ) ;
return F_47 ( V_53 ) ;
}
int T_5 F_48 ( void )
{
int V_54 ;
V_54 = F_49 ( & V_55 ) ;
if ( V_54 )
F_50 ( L_12 ) ;
return V_54 ;
}
void F_51 ( void )
{
F_52 ( & V_55 ) ;
}
