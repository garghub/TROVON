static bool F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_1 V_5 ;
if ( V_4 -> V_6 == V_7 ||
V_4 -> V_6 == V_8 ) {
F_2 ( V_2 , V_9 , & V_5 ) ;
if ( ( V_5 & 0x600 ) == 0x200 )
goto V_10;
}
if ( V_4 -> V_6 == V_11 ||
V_4 -> V_6 == V_12 ||
V_4 -> V_6 == V_13 ) {
F_2 ( V_2 , V_14 , & V_5 ) ;
if ( ( V_5 & 0xf0000 ) == 0xf0000 )
goto V_10;
}
return true ;
V_10:
F_3 ( & V_2 -> V_15 , L_1 ) ;
return false ;
}
static int F_4 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_16 * V_15 ;
struct V_17 * V_18 ;
int V_19 ;
if ( ! F_1 ( V_2 , V_4 ) ) {
V_19 = - V_20 ;
goto V_21;
}
V_19 = F_5 ( V_2 ) ;
if ( V_19 ) {
F_6 ( & V_2 -> V_15 , L_2 ) ;
goto V_21;
}
F_7 ( V_2 ) ;
V_19 = F_8 ( V_2 , V_22 ) ;
if ( V_19 ) {
F_6 ( & V_2 -> V_15 , L_3 ) ;
goto V_23;
}
if ( F_9 ( & V_2 -> V_15 , F_10 ( 64 ) ) ||
F_11 ( & V_2 -> V_15 , F_10 ( 64 ) ) ) {
V_19 = F_9 ( & V_2 -> V_15 , F_10 ( 32 ) ) ;
if ( V_19 )
V_19 = F_11 ( & V_2 -> V_15 ,
F_10 ( 32 ) ) ;
}
if ( V_19 ) {
F_6 ( & V_2 -> V_15 , L_4 ) ;
goto V_24;
}
V_15 = F_12 ( V_2 ) ;
if ( ! V_15 ) {
V_19 = - V_25 ;
goto V_24;
}
V_18 = F_13 ( V_15 ) ;
V_18 -> V_26 = F_14 ( V_2 , 0 , 0 ) ;
if ( ! V_18 -> V_26 ) {
F_6 ( & V_2 -> V_15 , L_5 ) ;
V_19 = - V_25 ;
goto V_27;
}
F_15 ( V_2 ) ;
if ( F_16 ( V_2 ) )
V_19 = F_17 ( V_2 -> V_28 ,
NULL ,
V_29 ,
V_30 , V_22 , V_15 ) ;
else
V_19 = F_17 ( V_2 -> V_28 ,
V_31 ,
V_29 ,
V_32 , V_22 , V_15 ) ;
if ( V_19 ) {
F_6 ( & V_2 -> V_15 , L_6 ,
V_2 -> V_28 ) ;
goto V_33;
}
if ( F_18 ( V_15 ) ) {
F_6 ( & V_2 -> V_15 , L_7 ) ;
V_19 = - V_20 ;
goto V_34;
}
V_19 = F_19 ( V_15 ) ;
if ( V_19 )
goto V_34;
F_20 ( V_2 , V_15 ) ;
F_21 ( & V_15 -> V_35 , V_36 ) ;
F_22 ( & V_2 -> V_15 , L_8 ) ;
return 0 ;
V_34:
F_23 ( V_15 ) ;
F_24 ( V_15 ) ;
F_25 ( V_2 -> V_28 , V_15 ) ;
V_33:
F_26 ( V_2 ) ;
F_27 ( V_2 , V_18 -> V_26 ) ;
V_27:
F_28 ( V_15 ) ;
V_24:
F_29 ( V_2 ) ;
V_23:
F_30 ( V_2 ) ;
V_21:
F_6 ( & V_2 -> V_15 , L_9 ) ;
return V_19 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_16 * V_15 ;
struct V_17 * V_18 ;
V_15 = F_32 ( V_2 ) ;
if ( ! V_15 )
return;
V_18 = F_13 ( V_15 ) ;
F_22 ( & V_2 -> V_15 , L_10 ) ;
F_33 ( V_15 ) ;
F_24 ( V_15 ) ;
F_25 ( V_2 -> V_28 , V_15 ) ;
F_26 ( V_2 ) ;
if ( V_18 -> V_26 )
F_27 ( V_2 , V_18 -> V_26 ) ;
F_34 ( V_15 ) ;
F_28 ( V_15 ) ;
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
}
static int F_35 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = F_36 ( V_6 ) ;
struct V_16 * V_15 = F_32 ( V_2 ) ;
if ( ! V_15 )
return - V_20 ;
F_22 ( & V_2 -> V_15 , L_11 ) ;
F_33 ( V_15 ) ;
F_24 ( V_15 ) ;
F_25 ( V_2 -> V_28 , V_15 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = F_36 ( V_6 ) ;
struct V_16 * V_15 ;
int V_19 ;
V_15 = F_32 ( V_2 ) ;
if ( ! V_15 )
return - V_20 ;
F_15 ( V_2 ) ;
if ( F_16 ( V_2 ) )
V_19 = F_17 ( V_2 -> V_28 ,
NULL ,
V_29 ,
V_30 , V_22 , V_15 ) ;
else
V_19 = F_17 ( V_2 -> V_28 ,
V_31 ,
V_29 ,
V_32 , V_22 , V_15 ) ;
if ( V_19 ) {
F_6 ( & V_2 -> V_15 , L_12 ,
V_2 -> V_28 ) ;
return V_19 ;
}
V_19 = F_38 ( V_15 ) ;
if ( V_19 )
return V_19 ;
F_21 ( & V_15 -> V_35 , V_36 ) ;
return 0 ;
}
