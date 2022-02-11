static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 , V_8 , V_9 ;
V_7 = F_2 ( V_4 -> V_10 + V_11 ) ;
if ( V_7 == F_2 ( V_4 -> V_10 + V_11 ) ) {
V_8 = ( F_3 ( V_7 ) - F_4 ( V_7 ) ) / 2 ;
V_9 = ( F_5 ( V_7 ) - F_6 ( V_7 ) ) / 2 ;
F_7 ( V_6 , V_12 , V_8 ) ;
F_7 ( V_6 , V_13 , V_9 ) ;
F_8 ( V_6 ) ;
}
F_9 ( V_14 , V_4 -> V_10 + V_15 ) ;
F_9 ( 0 , V_4 -> V_10 + V_15 ) ;
return V_16 ;
}
static int F_10 ( struct V_3 * V_4 , int V_17 )
{
int V_18 = 100 ;
F_9 ( V_17 , V_4 -> V_10 + V_19 ) ;
while ( -- V_18 ) {
if ( F_2 ( V_4 -> V_10 + V_19 ) == V_17 )
break;
F_11 ( 1 ) ;
}
if ( V_18 == 0 ) {
F_12 ( L_1 , V_20 , V_17 ) ;
return - V_21 ;
}
return 0 ;
}
static void F_13 ( struct V_3 * V_4 )
{
T_2 V_22 ;
V_22 = F_2 ( V_4 -> V_10 + V_19 ) ;
F_10 ( V_4 , V_22 | F_14 ( 0xf ) | F_15 ( 0xf ) ) ;
F_10 ( V_4 , F_14 ( V_4 -> V_23 -> V_24 ) |
F_15 ( V_4 -> V_23 -> V_25 ) ) ;
V_22 = F_2 ( V_4 -> V_10 + V_19 ) ;
F_10 ( V_4 , V_22 | V_26 ) ;
F_10 ( V_4 , V_22 & ~ V_26 ) ;
F_9 ( V_14 , V_4 -> V_10 + V_15 ) ;
F_9 ( 0 , V_4 -> V_10 + V_15 ) ;
F_16 ( L_2 , V_20 ,
F_2 ( V_4 -> V_10 + V_19 ) ) ;
}
static int F_17 ( struct V_5 * V_27 )
{
struct V_3 * V_4 = F_18 ( V_27 ) ;
F_13 ( V_4 ) ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 )
{
T_2 V_22 = F_2 ( V_4 -> V_10 + V_19 ) ;
F_10 ( V_4 , V_22 | V_26 ) ;
}
static void F_20 ( struct V_5 * V_27 )
{
struct V_3 * V_4 = F_18 ( V_27 ) ;
F_19 ( V_4 ) ;
}
static int T_3 F_21 ( struct V_28 * V_29 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_30 * V_31 ;
int V_1 , error ;
V_1 = F_22 ( V_29 , 0 ) ;
if ( V_1 < 0 ) {
F_23 ( & V_29 -> V_27 , L_3 ) ;
return - V_32 ;
}
V_31 = F_24 ( V_29 , V_33 , 0 ) ;
if ( ! V_31 ) {
F_23 ( & V_29 -> V_27 , L_4 ) ;
return - V_32 ;
}
V_4 = F_25 ( sizeof( struct V_3 ) , V_34 ) ;
if ( ! V_4 )
return - V_35 ;
V_4 -> V_23 = V_29 -> V_27 . V_36 ;
if ( ! V_4 -> V_23 ) {
F_23 ( & V_29 -> V_27 , L_5 ) ;
error = - V_37 ;
goto V_38;
}
V_4 -> V_10 = F_26 ( V_31 -> V_39 , F_27 ( V_31 ) ) ;
if ( ! V_4 -> V_10 ) {
F_23 ( & V_29 -> V_27 , L_6 ) ;
error = - V_32 ;
goto V_38;
}
F_19 ( V_4 ) ;
error = F_28 ( V_1 , F_1 , 0 ,
V_29 -> V_40 , V_4 ) ;
if ( error ) {
F_23 ( & V_29 -> V_27 , L_7 , error ) ;
goto V_41;
}
F_29 ( V_29 , V_4 ) ;
V_6 = F_30 () ;
if ( ! V_6 ) {
F_23 ( & V_29 -> V_27 , L_8 ) ;
error = - V_35 ;
goto V_42;
}
V_6 -> V_40 = V_29 -> V_40 ;
V_6 -> V_43 . V_44 = V_45 ;
V_6 -> V_46 = F_17 ;
V_6 -> V_47 = F_20 ;
V_6 -> V_27 . V_48 = & V_29 -> V_27 ;
F_31 ( V_6 , V_4 ) ;
V_4 -> V_6 = V_6 ;
F_32 ( V_6 , V_49 , V_12 ) ;
F_32 ( V_6 , V_49 , V_13 ) ;
error = F_33 ( V_6 ) ;
if ( error ) {
F_23 ( & V_29 -> V_27 , L_9 ) ;
goto V_50;
}
return 0 ;
V_50:
F_34 ( V_6 ) ;
V_42:
F_35 ( V_1 , V_4 ) ;
V_41:
F_36 ( V_4 -> V_10 ) ;
V_38:
F_37 ( V_4 ) ;
return error ;
}
static int T_4 F_38 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_39 ( V_29 ) ;
int V_1 = F_22 ( V_29 , 0 ) ;
F_40 ( V_4 -> V_6 ) ;
F_35 ( V_1 , V_4 ) ;
F_36 ( V_4 -> V_10 ) ;
F_37 ( V_4 ) ;
return 0 ;
}
