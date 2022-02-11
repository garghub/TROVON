static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 * V_7 = NULL ;
T_2 * V_8 = NULL ;
int V_9 = 0 ;
V_6 = F_2 ( V_2 ) ;
V_7 = F_3 () ;
if ( ! V_7 ) {
F_4 ( & V_2 -> V_6 , L_1 ) ;
V_9 = - V_10 ;
goto V_11;
}
V_8 = V_7 -> V_12 ;
if ( F_5 ( V_7 , & ( V_2 -> V_6 ) ) != 0 ) {
F_4 ( & V_2 -> V_6 , L_2 ) ;
V_9 = - V_10 ;
goto V_11;
}
F_6 ( V_8 , V_6 ) ;
V_8 -> V_7 = V_7 ;
F_7 ( V_7 -> V_13 , & ( V_2 -> V_6 ) ) ;
if ( V_14 ) {
V_9 = F_8 ( V_8 ,
V_15 ,
V_16 , 0 ) ;
if ( V_9 != 0 ) {
V_9 = - V_10 ;
F_4 ( & V_2 -> V_6 ,
L_3 ) ;
goto V_17;
}
}
F_9 ( V_6 ) ;
V_7 -> V_18 = V_19 ;
F_10 ( V_6 , V_7 ) ;
F_11 ( V_7 , V_20 ) ;
if ( F_12 ( V_7 ) != 0 ) {
F_4 ( & V_2 -> V_6 , L_4 ) ;
V_9 = - V_10 ;
goto V_21;
}
goto V_22;
V_21:
F_13 ( V_6 ) ;
V_17:
F_14 ( V_7 ) ;
V_11:
F_15 ( V_7 ) ;
F_15 ( V_8 ) ;
V_7 = NULL ;
V_22:
F_16 ( V_2 , V_7 ) ;
return V_9 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 * V_7 ;
V_7 = ( T_1 * ) F_18 ( V_2 ) ;
if ( V_7 != NULL ) {
F_19 ( V_23 ) ;
T_3 * V_24 , * V_25 ;
unsigned long V_26 ;
T_2 * V_8 = V_7 -> V_12 ;
if ( ! V_8 )
goto exit;
F_20 ( & V_8 -> V_27 . V_28 , V_26 ) ;
F_21 ( V_7 ) ;
F_22 ( & V_8 -> V_27 . V_29 , & V_23 ) ;
F_22 ( & V_8 -> V_27 . V_30 , & V_23 ) ;
F_22 ( & V_8 -> V_27 . V_31 , & V_23 ) ;
F_22 ( & V_8 -> V_27 . V_32 , & V_23 ) ;
F_23 ( & V_8 -> V_27 . V_28 , V_26 ) ;
F_11 ( V_7 , V_33 ) ;
F_24 ( & V_8 -> V_34 ) ;
F_24 ( & V_8 -> V_35 ) ;
F_24 ( & V_8 -> V_36 ) ;
F_25 ( & V_8 -> V_37 ) ;
F_25 ( & V_8 -> V_38 ) ;
F_25 ( & V_8 -> V_39 ) ;
F_26 ( & V_8 -> V_40 ) ;
F_26 ( & V_8 -> V_41 ) ;
F_27 ( & V_8 -> V_42 ) ;
F_27 ( & V_8 -> V_43 ) ;
F_28 (ctlx, &cleanlist, list)
F_29 ( & V_24 -> V_22 ) ;
F_30 ( 100 ) ;
F_31 (ctlx, temp, &cleanlist, list)
F_15 ( V_24 ) ;
F_32 ( V_7 ) ;
F_14 ( V_7 ) ;
F_13 ( V_8 -> V_44 ) ;
F_33 ( V_8 ) ;
F_15 ( V_8 ) ;
F_15 ( V_7 ) ;
}
exit:
F_16 ( V_2 , NULL ) ;
}
static int F_34 ( struct V_1 * V_2 ,
T_4 V_45 )
{
T_2 * V_8 = NULL ;
T_1 * V_7 ;
V_7 = ( T_1 * ) F_18 ( V_2 ) ;
if ( ! V_7 )
return - V_46 ;
V_8 = V_7 -> V_12 ;
if ( ! V_8 )
return - V_46 ;
F_11 ( V_7 , V_33 ) ;
F_25 ( & V_8 -> V_37 ) ;
F_25 ( & V_8 -> V_38 ) ;
F_25 ( & V_8 -> V_39 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
T_2 * V_8 = NULL ;
T_1 * V_7 ;
V_7 = ( T_1 * ) F_18 ( V_2 ) ;
if ( ! V_7 )
return - V_46 ;
V_8 = V_7 -> V_12 ;
if ( ! V_8 )
return - V_46 ;
if ( V_14 ) {
V_9 = F_8 ( V_8 ,
V_15 ,
V_16 , 0 ) ;
if ( V_9 != 0 ) {
F_32 ( V_7 ) ;
F_33 ( V_8 ) ;
F_4 ( & V_2 -> V_6 , L_3 ) ;
F_15 ( V_7 ) ;
F_15 ( V_8 ) ;
V_7 = NULL ;
return - V_46 ;
}
}
F_11 ( V_7 , V_20 ) ;
return 0 ;
}
