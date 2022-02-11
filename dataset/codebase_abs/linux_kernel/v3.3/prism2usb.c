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
F_4 ( V_10 L_1 , V_11 ) ;
V_9 = - V_12 ;
goto V_13;
}
V_8 = V_7 -> V_14 ;
if ( F_5 ( V_7 , & ( V_2 -> V_6 ) ) != 0 ) {
F_4 ( V_10 L_2 , V_11 ) ;
V_9 = - V_12 ;
goto V_13;
}
F_6 ( V_8 , V_6 ) ;
V_8 -> V_7 = V_7 ;
F_7 ( V_7 -> V_15 , & ( V_2 -> V_6 ) ) ;
if ( V_16 ) {
V_9 = F_8 ( V_8 ,
V_17 ,
V_18 , 0 ) ;
if ( V_9 != 0 ) {
F_9 ( V_7 ) ;
F_10 ( V_8 ) ;
V_9 = - V_12 ;
F_4 ( V_10
L_3 , V_11 ) ;
goto V_13;
}
}
F_11 ( V_6 ) ;
V_7 -> V_19 = V_20 ;
F_12 ( V_6 , V_7 ) ;
F_13 ( V_7 , V_21 ) ;
if ( F_14 ( V_7 ) != 0 ) {
F_4 ( V_10 L_4 , V_11 ) ;
V_9 = - V_12 ;
goto V_13;
}
goto V_22;
V_13:
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
struct V_24 * V_25 ;
struct V_24 * V_26 ;
unsigned long V_27 ;
T_2 * V_8 = V_7 -> V_14 ;
if ( ! V_8 )
goto exit;
F_20 ( & V_8 -> V_28 . V_29 , V_27 ) ;
F_21 ( V_7 ) ;
F_22 ( & V_8 -> V_28 . V_30 , & V_23 ) ;
F_22 ( & V_8 -> V_28 . V_31 , & V_23 ) ;
F_22 ( & V_8 -> V_28 . V_32 , & V_23 ) ;
F_22 ( & V_8 -> V_28 . V_33 , & V_23 ) ;
F_23 ( & V_8 -> V_28 . V_29 , V_27 ) ;
F_13 ( V_7 , V_34 ) ;
F_24 ( & V_8 -> V_35 ) ;
F_24 ( & V_8 -> V_36 ) ;
F_24 ( & V_8 -> V_37 ) ;
F_25 ( & V_8 -> V_38 ) ;
F_25 ( & V_8 -> V_39 ) ;
F_25 ( & V_8 -> V_40 ) ;
F_26 ( & V_8 -> V_41 ) ;
F_26 ( & V_8 -> V_42 ) ;
F_27 () ;
F_28 (entry, &cleanlist) {
T_3 * V_43 ;
V_43 = F_29 ( V_25 , T_3 , V_44 ) ;
F_30 ( & V_43 -> V_22 ) ;
}
F_31 ( 100 ) ;
F_32 (entry, temp, &cleanlist) {
T_3 * V_43 ;
V_43 = F_29 ( V_25 , T_3 , V_44 ) ;
F_15 ( V_43 ) ;
}
F_9 ( V_7 ) ;
F_33 ( V_7 ) ;
F_34 ( V_8 -> V_45 ) ;
F_10 ( V_8 ) ;
F_15 ( V_8 ) ;
F_15 ( V_7 ) ;
}
exit:
F_16 ( V_2 , NULL ) ;
}
static int F_35 ( struct V_1 * V_2 ,
T_4 V_46 )
{
T_2 * V_8 = NULL ;
T_1 * V_7 ;
V_7 = ( T_1 * ) F_18 ( V_2 ) ;
if ( ! V_7 )
return - V_47 ;
V_8 = V_7 -> V_14 ;
if ( ! V_8 )
return - V_47 ;
F_13 ( V_7 , V_34 ) ;
F_25 ( & V_8 -> V_38 ) ;
F_25 ( & V_8 -> V_39 ) ;
F_25 ( & V_8 -> V_40 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
T_2 * V_8 = NULL ;
T_1 * V_7 ;
V_7 = ( T_1 * ) F_18 ( V_2 ) ;
if ( ! V_7 )
return - V_47 ;
V_8 = V_7 -> V_14 ;
if ( ! V_8 )
return - V_47 ;
if ( V_16 ) {
V_9 = F_8 ( V_8 ,
V_17 ,
V_18 , 0 ) ;
if ( V_9 != 0 ) {
F_9 ( V_7 ) ;
F_10 ( V_8 ) ;
F_4 ( V_10
L_3 , V_11 ) ;
F_15 ( V_7 ) ;
F_15 ( V_8 ) ;
V_7 = NULL ;
return - V_47 ;
}
}
F_13 ( V_7 , V_21 ) ;
return 0 ;
}
