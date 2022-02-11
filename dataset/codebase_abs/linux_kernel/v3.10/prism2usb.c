static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 * V_7 = NULL ;
T_2 * V_8 = NULL ;
int V_9 = 0 ;
V_6 = F_2 ( V_2 ) ;
V_7 = F_3 () ;
if ( V_7 == NULL ) {
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
F_9 ( V_7 ) ;
F_10 ( V_8 ) ;
V_9 = - V_10 ;
F_4 ( & V_2 -> V_6 , L_3 ) ;
goto V_11;
}
}
F_11 ( V_6 ) ;
V_7 -> V_17 = V_18 ;
F_12 ( V_6 , V_7 ) ;
F_13 ( V_7 , V_19 ) ;
if ( F_14 ( V_7 ) != 0 ) {
F_4 ( & V_2 -> V_6 , L_4 ) ;
V_9 = - V_10 ;
goto V_11;
}
goto V_20;
V_11:
F_15 ( V_7 ) ;
F_15 ( V_8 ) ;
V_7 = NULL ;
V_20:
F_16 ( V_2 , V_7 ) ;
return V_9 ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 * V_7 ;
V_7 = ( T_1 * ) F_18 ( V_2 ) ;
if ( V_7 != NULL ) {
F_19 ( V_21 ) ;
struct V_22 * V_23 ;
struct V_22 * V_24 ;
unsigned long V_25 ;
T_2 * V_8 = V_7 -> V_12 ;
if ( ! V_8 )
goto exit;
F_20 ( & V_8 -> V_26 . V_27 , V_25 ) ;
F_21 ( V_7 ) ;
F_22 ( & V_8 -> V_26 . V_28 , & V_21 ) ;
F_22 ( & V_8 -> V_26 . V_29 , & V_21 ) ;
F_22 ( & V_8 -> V_26 . V_30 , & V_21 ) ;
F_22 ( & V_8 -> V_26 . V_31 , & V_21 ) ;
F_23 ( & V_8 -> V_26 . V_27 , V_25 ) ;
F_13 ( V_7 , V_32 ) ;
F_24 ( & V_8 -> V_33 ) ;
F_24 ( & V_8 -> V_34 ) ;
F_24 ( & V_8 -> V_35 ) ;
F_25 ( & V_8 -> V_36 ) ;
F_25 ( & V_8 -> V_37 ) ;
F_25 ( & V_8 -> V_38 ) ;
F_26 ( & V_8 -> V_39 ) ;
F_26 ( & V_8 -> V_40 ) ;
F_27 () ;
F_28 (entry, &cleanlist) {
T_3 * V_41 ;
V_41 = F_29 ( V_23 , T_3 , V_42 ) ;
F_30 ( & V_41 -> V_20 ) ;
}
F_31 ( 100 ) ;
F_32 (entry, temp, &cleanlist) {
T_3 * V_41 ;
V_41 = F_29 ( V_23 , T_3 , V_42 ) ;
F_15 ( V_41 ) ;
}
F_9 ( V_7 ) ;
F_33 ( V_7 ) ;
F_34 ( V_8 -> V_43 ) ;
F_10 ( V_8 ) ;
F_15 ( V_8 ) ;
F_15 ( V_7 ) ;
}
exit:
F_16 ( V_2 , NULL ) ;
}
static int F_35 ( struct V_1 * V_2 ,
T_4 V_44 )
{
T_2 * V_8 = NULL ;
T_1 * V_7 ;
V_7 = ( T_1 * ) F_18 ( V_2 ) ;
if ( ! V_7 )
return - V_45 ;
V_8 = V_7 -> V_12 ;
if ( ! V_8 )
return - V_45 ;
F_13 ( V_7 , V_32 ) ;
F_25 ( & V_8 -> V_36 ) ;
F_25 ( & V_8 -> V_37 ) ;
F_25 ( & V_8 -> V_38 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
T_2 * V_8 = NULL ;
T_1 * V_7 ;
V_7 = ( T_1 * ) F_18 ( V_2 ) ;
if ( ! V_7 )
return - V_45 ;
V_8 = V_7 -> V_12 ;
if ( ! V_8 )
return - V_45 ;
if ( V_14 ) {
V_9 = F_8 ( V_8 ,
V_15 ,
V_16 , 0 ) ;
if ( V_9 != 0 ) {
F_9 ( V_7 ) ;
F_10 ( V_8 ) ;
F_4 ( & V_2 -> V_6 , L_3 ) ;
F_15 ( V_7 ) ;
F_15 ( V_8 ) ;
V_7 = NULL ;
return - V_45 ;
}
}
F_13 ( V_7 , V_19 ) ;
return 0 ;
}
