static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
F_2 ( L_1 ) ;
V_6 = F_3 ( sizeof( * V_6 ) , V_8 ) ;
if ( ! V_6 )
return - V_9 ;
V_6 -> V_10 = V_2 ;
V_6 -> V_6 = & V_2 -> V_6 ;
F_4 ( & V_11 ) ;
V_7 = F_5 ( V_6 , NULL , V_4 ) ;
if ( V_7 ) {
F_6 ( V_12 L_2 ) ;
goto V_13;
}
if ( F_7 ( V_6 , V_14 ) ) {
V_7 = F_8 ( V_6 , & V_6 -> V_15 , V_16 ) ;
if ( V_7 )
goto V_13;
}
if ( F_7 ( V_6 , V_17 ) && V_18 ) {
V_7 = F_8 ( V_6 , & V_6 -> V_19 , V_20 ) ;
if ( V_7 )
goto V_21;
}
V_7 = F_8 ( V_6 , & V_6 -> V_22 , V_23 ) ;
if ( V_7 )
goto V_24;
if ( V_6 -> V_4 -> V_25 ) {
V_7 = V_6 -> V_4 -> V_25 ( V_6 , 0 ) ;
if ( V_7 )
goto V_26;
}
if ( F_7 ( V_6 , V_14 ) ) {
V_7 = F_9 ( V_6 ,
& V_6 -> V_22 -> V_27 ) ;
if ( V_7 )
goto V_26;
}
F_10 ( & V_6 -> V_28 , & V_4 -> V_29 ) ;
F_11 ( & V_11 ) ;
F_12 ( L_3 ,
V_4 -> V_30 , V_4 -> V_31 , V_4 -> V_32 , V_4 -> V_33 ,
V_4 -> V_34 , V_6 -> V_22 -> V_35 ) ;
return 0 ;
V_26:
F_13 ( & V_6 -> V_22 ) ;
V_24:
if ( V_6 -> V_19 )
F_13 ( & V_6 -> V_19 ) ;
V_21:
if ( F_7 ( V_6 , V_14 ) )
F_13 ( & V_6 -> V_15 ) ;
V_13:
F_14 ( V_6 ) ;
F_11 ( & V_11 ) ;
return V_7 ;
}
static int F_15 ( struct V_5 * V_6 )
{
return F_16 ( V_6 -> V_10 , 0 ) ;
}
static const char * F_17 ( struct V_5 * V_6 )
{
return V_6 -> V_10 -> V_30 ;
}
static int F_18 ( struct V_5 * V_6 , struct V_36 * V_37 )
{
int V_38 , V_7 , V_39 ;
V_37 -> V_40 = 13 + strlen ( V_6 -> V_10 -> V_30 ) ;
V_37 -> V_41 = V_37 -> V_40 ;
V_37 -> V_42 = F_19 ( V_37 -> V_40 + 1 , V_8 ) ;
if ( V_37 -> V_42 == NULL )
return - V_9 ;
V_39 = V_6 -> V_10 -> V_39 ;
if ( V_39 == - 1 )
V_39 = 0 ;
V_38 = snprintf ( V_37 -> V_42 , V_37 -> V_40 ,
L_4 , V_6 -> V_10 -> V_30 , V_39 ) ;
if ( V_38 > V_37 -> V_40 ) {
F_20 ( L_5 ) ;
V_7 = - V_43 ;
goto V_44;
}
V_6 -> V_45 =
F_19 ( strlen ( V_6 -> V_10 -> V_30 ) +
V_37 -> V_40 + 2 , V_8 ) ;
if ( V_6 -> V_45 == NULL ) {
V_7 = - V_9 ;
goto V_44;
}
sprintf ( V_6 -> V_45 , L_6 , V_6 -> V_10 -> V_30 ,
V_37 -> V_42 ) ;
return 0 ;
V_44:
return V_7 ;
}
int F_21 ( struct V_3 * V_4 , struct V_1 * V_1 )
{
F_2 ( L_1 ) ;
V_4 -> V_46 . V_1 = V_1 ;
V_4 -> V_47 = & V_48 ;
F_22 ( & V_4 -> V_29 ) ;
return F_1 ( V_1 , V_4 ) ;
}
void F_23 ( struct V_3 * V_4 , struct V_1 * V_1 )
{
struct V_5 * V_6 , * V_49 ;
F_2 ( L_1 ) ;
F_24 (dev, tmp, &driver->device_list, driver_item)
F_25 ( V_6 ) ;
F_12 ( L_7 ) ;
}
