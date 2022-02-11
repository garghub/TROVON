static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = V_2 -> V_4 ;
unsigned int V_5 = F_2 ( V_3 ) ;
unsigned int V_6 = F_3 ( V_3 ) ;
unsigned int V_7 = F_4 ( V_5 , V_6 , V_8 ) ;
unsigned int V_9 = V_2 -> V_10 [ V_7 ] ;
F_5 ( V_4 , V_11 , V_12 , V_7 ) ;
F_6 ( V_4 , V_9 , 1 ) ;
F_7 ( V_4 ) ;
F_5 ( V_4 , V_11 , V_12 , V_7 ) ;
F_6 ( V_4 , V_9 , 0 ) ;
F_7 ( V_4 ) ;
}
static T_1 F_8 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
unsigned int V_15 , V_16 ;
V_15 = F_9 ( V_2 -> V_17 + V_18 ) ;
V_16 = V_19 | V_20 ;
if ( V_15 & V_16 )
F_1 ( V_2 , V_15 ) ;
return V_21 ;
}
static int F_10 ( struct V_4 * V_22 )
{
struct V_1 * V_2 = F_11 ( V_22 ) ;
const struct V_23 * V_24 = V_2 -> V_24 ;
unsigned int V_16 , V_25 ;
F_12 ( V_2 -> V_26 ) ;
V_16 = F_9 ( V_2 -> V_17 + V_27 ) ;
V_16 |= ( V_28 | V_29 ) ;
V_16 &= ~ ( V_30 | V_31 ) ;
V_25 = V_24 -> V_32 | ( V_24 -> V_33 << V_34 ) ;
V_16 |= V_25 ;
F_13 ( V_16 , V_2 -> V_17 + V_27 ) ;
return 0 ;
}
static void F_14 ( struct V_4 * V_22 )
{
struct V_1 * V_2 = F_11 ( V_22 ) ;
F_15 ( V_2 -> V_26 ) ;
}
static int F_16 ( struct V_35 * V_36 )
{
const struct V_23 * V_24 =
V_36 -> V_22 . V_37 ;
const struct V_38 * V_39 ;
struct V_1 * V_2 ;
struct V_4 * V_4 ;
struct V_40 * V_41 ;
int V_13 ;
int error ;
if ( ! V_24 ) {
F_17 ( & V_36 -> V_22 , L_1 ) ;
return - V_42 ;
}
V_39 = V_24 -> V_39 ;
V_13 = F_18 ( V_36 , 0 ) ;
if ( V_13 < 0 ) {
F_17 ( & V_36 -> V_22 , L_2 ) ;
return - V_43 ;
}
V_2 = F_19 ( sizeof( struct V_1 ) , V_44 ) ;
V_4 = F_20 () ;
if ( ! V_2 || ! V_4 ) {
F_17 ( & V_36 -> V_22 , L_3 ) ;
error = - V_45 ;
goto V_46;
}
V_2 -> V_24 = V_24 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_13 = V_13 ;
V_41 = F_21 ( V_36 , V_47 , 0 ) ;
if ( V_41 == NULL ) {
F_17 ( & V_36 -> V_22 , L_4 ) ;
error = - V_43 ;
goto V_46;
}
V_41 = F_22 ( V_41 -> V_48 , F_23 ( V_41 ) , V_36 -> V_49 ) ;
if ( V_41 == NULL ) {
F_17 ( & V_36 -> V_22 , L_5 ) ;
error = - V_50 ;
goto V_46;
}
V_2 -> V_17 = F_24 ( V_41 -> V_48 , F_23 ( V_41 ) ) ;
if ( V_2 -> V_17 == NULL ) {
F_17 ( & V_36 -> V_22 , L_6 ) ;
error = - V_43 ;
goto V_51;
}
V_2 -> V_26 = F_25 ( & V_36 -> V_22 , NULL ) ;
if ( F_26 ( V_2 -> V_26 ) ) {
F_17 ( & V_36 -> V_22 , L_7 ) ;
error = F_27 ( V_2 -> V_26 ) ;
goto V_52;
}
F_28 ( & V_36 -> V_22 ) ;
V_4 -> V_49 = V_36 -> V_49 ;
V_4 -> V_53 . V_54 = V_55 ;
V_4 -> V_56 = F_10 ;
V_4 -> V_57 = F_14 ;
V_4 -> V_22 . V_58 = & V_36 -> V_22 ;
error = F_29 ( V_39 , NULL ,
V_59 , V_60 ,
V_2 -> V_10 , V_4 ) ;
if ( error ) {
F_17 ( & V_36 -> V_22 , L_8 ) ;
goto V_61;
}
error = F_30 ( V_2 -> V_13 , F_8 ,
0 , V_36 -> V_49 , V_2 ) ;
if ( error ) {
F_17 ( & V_36 -> V_22 , L_9 ) ;
goto V_61;
}
F_31 ( V_62 , V_4 -> V_63 ) ;
F_32 ( V_4 , V_11 , V_12 ) ;
F_33 ( V_4 , V_2 ) ;
error = F_34 ( V_4 ) ;
if ( error ) {
F_17 ( & V_36 -> V_22 , L_10 ) ;
goto V_64;
}
F_35 ( V_36 , V_2 ) ;
return 0 ;
V_64:
F_36 ( V_13 , V_2 ) ;
V_61:
F_37 ( V_2 -> V_26 ) ;
V_52:
F_38 ( V_2 -> V_17 ) ;
V_51:
F_39 ( V_41 -> V_48 , F_23 ( V_41 ) ) ;
V_46:
F_40 ( V_4 ) ;
F_41 ( V_2 ) ;
return error ;
}
static int F_42 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_43 ( V_36 ) ;
struct V_40 * V_41 ;
F_36 ( V_2 -> V_13 , V_2 ) ;
F_37 ( V_2 -> V_26 ) ;
F_44 ( V_2 -> V_4 ) ;
F_38 ( V_2 -> V_17 ) ;
V_41 = F_21 ( V_36 , V_47 , 0 ) ;
F_39 ( V_41 -> V_48 , F_23 ( V_41 ) ) ;
F_41 ( V_2 ) ;
return 0 ;
}
