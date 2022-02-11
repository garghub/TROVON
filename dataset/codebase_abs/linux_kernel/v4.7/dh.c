static int F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static T_2 F_3 ( T_3 V_5 , T_4 V_6 , T_1 * V_7 )
{
struct V_8 * V_8 ;
T_5 V_9 ;
long V_10 ;
T_2 V_11 ;
V_9 = F_4 ( V_5 , 0 , V_12 ) ;
if ( F_5 ( V_9 ) ) {
V_11 = - V_13 ;
goto error;
}
V_8 = F_6 ( V_9 ) ;
V_11 = - V_14 ;
if ( V_8 -> type == & V_15 ) {
F_7 ( & V_8 -> V_16 ) ;
V_10 = F_8 ( V_8 ) ;
if ( V_10 == 0 ) {
const struct V_17 * V_18 ;
V_18 = V_17 ( V_8 ) ;
if ( V_6 == 0 ) {
* V_7 = NULL ;
V_11 = V_18 -> V_19 ;
} else if ( V_18 -> V_19 <= V_6 ) {
* V_7 = F_9 ( V_18 -> V_20 ,
V_18 -> V_19 ) ;
if ( * V_7 )
V_11 = V_18 -> V_19 ;
} else {
V_11 = - V_21 ;
}
}
F_10 ( & V_8 -> V_16 ) ;
}
F_11 ( V_8 ) ;
error:
return V_11 ;
}
long F_12 ( struct V_22 T_6 * V_23 ,
char T_6 * V_24 , T_4 V_25 ,
void T_6 * V_26 )
{
long V_11 ;
T_1 V_2 , V_27 , V_28 , V_1 ;
unsigned V_29 ;
struct V_22 V_30 ;
T_7 * V_31 ;
T_2 V_32 ;
T_4 V_33 ;
if ( ! V_23 || ( ! V_24 && V_25 ) ) {
V_11 = - V_21 ;
goto V_34;
}
if ( F_13 ( & V_30 , V_23 , sizeof( V_30 ) ) != 0 ) {
V_11 = - V_35 ;
goto V_34;
}
if ( V_26 ) {
V_11 = - V_21 ;
goto V_34;
}
V_32 = F_3 ( V_30 . V_28 , V_25 , & V_28 ) ;
if ( V_32 < 0 || ! V_28 ) {
V_11 = V_32 ;
goto V_34;
}
V_33 = V_32 ;
V_32 = F_3 ( V_30 . V_2 , V_36 , & V_2 ) ;
if ( V_32 < 0 || ! V_2 ) {
V_11 = V_32 ;
goto V_37;
}
V_32 = F_3 ( V_30 . V_27 , V_36 , & V_27 ) ;
if ( V_32 < 0 || ! V_27 ) {
V_11 = V_32 ;
goto V_38;
}
V_1 = F_14 ( 0 ) ;
if ( ! V_1 ) {
V_11 = - V_39 ;
goto V_40;
}
V_31 = F_15 ( V_33 , V_41 ) ;
if ( ! V_31 ) {
V_11 = - V_39 ;
goto V_42;
}
V_11 = F_1 ( V_1 , V_2 , V_27 , V_28 ) ;
if ( V_11 )
goto V_43;
V_11 = F_16 ( V_1 , V_31 , V_33 , & V_29 , NULL ) ;
if ( V_11 != 0 )
goto V_43;
V_11 = V_29 ;
if ( F_17 ( V_24 , V_31 , V_29 ) != 0 )
V_11 = - V_35 ;
V_43:
F_18 ( V_31 ) ;
V_42:
F_19 ( V_1 ) ;
V_40:
F_19 ( V_27 ) ;
V_38:
F_19 ( V_2 ) ;
V_37:
F_19 ( V_28 ) ;
V_34:
return V_11 ;
}
