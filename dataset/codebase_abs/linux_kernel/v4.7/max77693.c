static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_7 ;
int V_8 = 0 ;
V_6 = F_2 ( & V_2 -> V_9 ,
sizeof( struct V_5 ) , V_10 ) ;
if ( V_6 == NULL )
return - V_11 ;
F_3 ( V_2 , V_6 ) ;
V_6 -> V_9 = & V_2 -> V_9 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_12 = V_2 -> V_12 ;
V_6 -> type = V_4 -> V_13 ;
V_6 -> V_14 = F_4 ( V_2 , & V_15 ) ;
if ( F_5 ( V_6 -> V_14 ) ) {
V_8 = F_6 ( V_6 -> V_14 ) ;
F_7 ( V_6 -> V_9 , L_1 ,
V_8 ) ;
return V_8 ;
}
V_8 = F_8 ( V_6 -> V_14 , V_16 ,
& V_7 ) ;
if ( V_8 < 0 ) {
F_7 ( V_6 -> V_9 , L_2 ) ;
return V_8 ;
} else
F_9 ( V_6 -> V_9 , L_3 , V_7 ) ;
V_6 -> V_17 = F_10 ( V_2 -> V_18 , V_19 ) ;
if ( ! V_6 -> V_17 ) {
F_7 ( V_6 -> V_9 , L_4 ) ;
return - V_20 ;
}
F_3 ( V_6 -> V_17 , V_6 ) ;
V_6 -> V_21 = F_10 ( V_2 -> V_18 , V_22 ) ;
if ( ! V_6 -> V_21 ) {
F_7 ( V_6 -> V_9 , L_5 ) ;
V_8 = - V_20 ;
goto V_23;
}
F_3 ( V_6 -> V_21 , V_6 ) ;
V_6 -> V_24 = F_4 ( V_6 -> V_21 ,
& V_25 ) ;
if ( F_5 ( V_6 -> V_24 ) ) {
V_8 = F_6 ( V_6 -> V_24 ) ;
F_7 ( V_6 -> V_9 ,
L_6 , V_8 ) ;
goto V_26;
}
V_6 -> V_27 = F_4 ( V_6 -> V_17 ,
& V_28 ) ;
if ( F_5 ( V_6 -> V_27 ) ) {
V_8 = F_6 ( V_6 -> V_27 ) ;
F_7 ( V_6 -> V_9 ,
L_1 , V_8 ) ;
goto V_26;
}
V_8 = F_11 ( V_6 -> V_14 , V_6 -> V_12 ,
V_29 | V_30 |
V_31 , 0 ,
& V_32 ,
& V_6 -> V_33 ) ;
if ( V_8 ) {
F_7 ( V_6 -> V_9 , L_7 , V_8 ) ;
goto V_26;
}
V_8 = F_11 ( V_6 -> V_14 , V_6 -> V_12 ,
V_29 | V_30 |
V_31 , 0 ,
& V_34 ,
& V_6 -> V_35 ) ;
if ( V_8 ) {
F_7 ( V_6 -> V_9 , L_7 , V_8 ) ;
goto V_36;
}
V_8 = F_11 ( V_6 -> V_14 , V_6 -> V_12 ,
V_29 | V_30 |
V_31 , 0 ,
& V_37 ,
& V_6 -> V_38 ) ;
if ( V_8 ) {
F_7 ( V_6 -> V_9 , L_7 , V_8 ) ;
goto V_39;
}
V_8 = F_11 ( V_6 -> V_27 , V_6 -> V_12 ,
V_29 | V_30 |
V_31 , 0 ,
& V_40 ,
& V_6 -> V_41 ) ;
if ( V_8 ) {
F_7 ( V_6 -> V_9 , L_7 , V_8 ) ;
goto V_42;
}
V_8 = F_12 ( V_6 -> V_14 ,
V_43 ,
V_44 , ( unsigned int ) ~ V_44 ) ;
if ( V_8 < 0 ) {
F_7 ( V_6 -> V_9 ,
L_8 ,
V_8 ) ;
goto V_45;
}
F_13 ( V_6 -> V_9 ) ;
V_8 = F_14 ( V_6 -> V_9 , - 1 , V_46 ,
F_15 ( V_46 ) , NULL , 0 , NULL ) ;
if ( V_8 < 0 )
goto V_47;
return V_8 ;
V_47:
F_16 ( V_6 -> V_9 ) ;
V_45:
F_17 ( V_6 -> V_12 , V_6 -> V_41 ) ;
V_42:
F_17 ( V_6 -> V_12 , V_6 -> V_38 ) ;
V_39:
F_17 ( V_6 -> V_12 , V_6 -> V_35 ) ;
V_36:
F_17 ( V_6 -> V_12 , V_6 -> V_33 ) ;
V_26:
F_18 ( V_6 -> V_21 ) ;
V_23:
F_18 ( V_6 -> V_17 ) ;
return V_8 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_20 ( V_2 ) ;
F_16 ( V_6 -> V_9 ) ;
F_17 ( V_6 -> V_12 , V_6 -> V_41 ) ;
F_17 ( V_6 -> V_12 , V_6 -> V_38 ) ;
F_17 ( V_6 -> V_12 , V_6 -> V_35 ) ;
F_17 ( V_6 -> V_12 , V_6 -> V_33 ) ;
F_18 ( V_6 -> V_17 ) ;
F_18 ( V_6 -> V_21 ) ;
return 0 ;
}
static int F_21 ( struct V_48 * V_9 )
{
struct V_1 * V_2 = F_22 ( V_9 ) ;
struct V_5 * V_6 = F_20 ( V_2 ) ;
if ( F_23 ( V_9 ) ) {
F_24 ( V_6 -> V_12 ) ;
F_25 ( V_6 -> V_12 ) ;
}
return 0 ;
}
static int F_26 ( struct V_48 * V_9 )
{
struct V_1 * V_2 = F_22 ( V_9 ) ;
struct V_5 * V_6 = F_20 ( V_2 ) ;
if ( F_23 ( V_9 ) ) {
F_27 ( V_6 -> V_12 ) ;
F_28 ( V_6 -> V_12 ) ;
}
return 0 ;
}
