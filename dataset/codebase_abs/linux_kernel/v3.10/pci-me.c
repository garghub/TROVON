static bool F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
T_1 V_5 ;
if ( V_4 -> V_6 == V_7 ) {
F_2 ( V_2 , 0x48 , & V_5 ) ;
if ( ( V_5 & 0x600 ) == 0x200 ) {
F_3 ( & V_2 -> V_8 , L_1 ) ;
return false ;
}
}
return true ;
}
static int F_4 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_9 * V_8 ;
struct V_10 * V_11 ;
int V_12 ;
F_5 ( & V_13 ) ;
if ( ! F_1 ( V_2 , V_4 ) ) {
V_12 = - V_14 ;
goto V_15;
}
if ( V_16 ) {
V_12 = - V_17 ;
goto V_15;
}
V_12 = F_6 ( V_2 ) ;
if ( V_12 ) {
F_7 ( & V_2 -> V_8 , L_2 ) ;
goto V_15;
}
F_8 ( V_2 ) ;
V_12 = F_9 ( V_2 , V_18 ) ;
if ( V_12 ) {
F_7 ( & V_2 -> V_8 , L_3 ) ;
goto V_19;
}
V_8 = F_10 ( V_2 ) ;
if ( ! V_8 ) {
V_12 = - V_20 ;
goto V_21;
}
V_11 = F_11 ( V_8 ) ;
V_11 -> V_22 = F_12 ( V_2 , 0 , 0 ) ;
if ( ! V_11 -> V_22 ) {
F_7 ( & V_2 -> V_8 , L_4 ) ;
V_12 = - V_20 ;
goto V_23;
}
F_13 ( V_2 ) ;
if ( F_14 ( V_2 ) )
V_12 = F_15 ( V_2 -> V_24 ,
NULL ,
V_25 ,
V_26 , V_18 , V_8 ) ;
else
V_12 = F_15 ( V_2 -> V_24 ,
V_27 ,
V_25 ,
V_28 , V_18 , V_8 ) ;
if ( V_12 ) {
F_7 ( & V_2 -> V_8 , L_5 ,
V_2 -> V_24 ) ;
goto V_29;
}
if ( F_16 ( V_8 ) ) {
F_7 ( & V_2 -> V_8 , L_6 ) ;
V_12 = - V_14 ;
goto V_30;
}
V_12 = F_17 ( V_8 ) ;
if ( V_12 )
goto V_30;
V_16 = V_2 ;
F_18 ( V_2 , V_8 ) ;
F_19 ( & V_8 -> V_31 , V_32 ) ;
F_20 ( & V_13 ) ;
F_21 ( L_7 ) ;
return 0 ;
V_30:
F_22 ( V_8 ) ;
F_23 () ;
F_24 ( V_2 -> V_24 , V_8 ) ;
V_29:
F_25 ( V_2 ) ;
F_26 ( V_2 , V_11 -> V_22 ) ;
V_23:
F_27 ( V_8 ) ;
V_21:
F_28 ( V_2 ) ;
V_19:
F_29 ( V_2 ) ;
V_15:
F_20 ( & V_13 ) ;
F_7 ( & V_2 -> V_8 , L_8 ) ;
return V_12 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_9 * V_8 ;
struct V_10 * V_11 ;
if ( V_16 != V_2 )
return;
V_8 = F_31 ( V_2 ) ;
if ( ! V_8 )
return;
V_11 = F_11 ( V_8 ) ;
F_7 ( & V_2 -> V_8 , L_9 ) ;
F_32 ( V_8 ) ;
V_16 = NULL ;
F_22 ( V_8 ) ;
F_24 ( V_2 -> V_24 , V_8 ) ;
F_25 ( V_2 ) ;
F_18 ( V_2 , NULL ) ;
if ( V_11 -> V_22 )
F_26 ( V_2 , V_11 -> V_22 ) ;
F_33 ( V_8 ) ;
F_27 ( V_8 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
}
static int F_34 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 ) ;
struct V_9 * V_8 = F_31 ( V_2 ) ;
if ( ! V_8 )
return - V_14 ;
F_7 ( & V_2 -> V_8 , L_10 ) ;
F_32 ( V_8 ) ;
F_22 ( V_8 ) ;
F_24 ( V_2 -> V_24 , V_8 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = F_35 ( V_6 ) ;
struct V_9 * V_8 ;
int V_12 ;
V_8 = F_31 ( V_2 ) ;
if ( ! V_8 )
return - V_14 ;
F_13 ( V_2 ) ;
if ( F_14 ( V_2 ) )
V_12 = F_15 ( V_2 -> V_24 ,
NULL ,
V_25 ,
V_26 , V_18 , V_8 ) ;
else
V_12 = F_15 ( V_2 -> V_24 ,
V_27 ,
V_25 ,
V_28 , V_18 , V_8 ) ;
if ( V_12 ) {
F_7 ( & V_2 -> V_8 , L_11 ,
V_2 -> V_24 ) ;
return V_12 ;
}
F_5 ( & V_8 -> V_33 ) ;
V_8 -> V_34 = V_35 ;
F_37 ( V_8 ) ;
F_38 ( V_8 , 1 ) ;
F_20 ( & V_8 -> V_33 ) ;
F_19 ( & V_8 -> V_31 , V_32 ) ;
return V_12 ;
}
