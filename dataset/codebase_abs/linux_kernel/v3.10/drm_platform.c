int F_1 ( struct V_1 * V_2 ,
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
V_7 = F_8 ( V_6 , & V_6 -> V_17 , V_18 ) ;
if ( V_7 )
goto V_19;
if ( V_6 -> V_4 -> V_20 ) {
V_7 = V_6 -> V_4 -> V_20 ( V_6 , 0 ) ;
if ( V_7 )
goto V_21;
}
if ( F_7 ( V_6 , V_14 ) ) {
V_7 = F_9 ( V_6 ,
& V_6 -> V_17 -> V_22 ) ;
if ( V_7 )
goto V_21;
}
F_10 ( & V_6 -> V_23 , & V_4 -> V_24 ) ;
F_11 ( & V_11 ) ;
F_12 ( L_3 ,
V_4 -> V_25 , V_4 -> V_26 , V_4 -> V_27 , V_4 -> V_28 ,
V_4 -> V_29 , V_6 -> V_17 -> V_30 ) ;
return 0 ;
V_21:
F_13 ( & V_6 -> V_17 ) ;
V_19:
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
return V_6 -> V_10 -> V_25 ;
}
static int F_18 ( struct V_5 * V_6 , struct V_31 * V_32 )
{
int V_33 , V_7 , V_34 ;
V_32 -> V_35 = 13 + strlen ( V_6 -> V_10 -> V_25 ) ;
V_32 -> V_36 = V_32 -> V_35 ;
V_32 -> V_37 = F_19 ( V_32 -> V_35 + 1 , V_8 ) ;
if ( V_32 -> V_37 == NULL )
return - V_9 ;
V_34 = V_6 -> V_10 -> V_34 ;
if ( V_34 == - 1 )
V_34 = 0 ;
V_33 = snprintf ( V_32 -> V_37 , V_32 -> V_35 ,
L_4 , V_6 -> V_10 -> V_25 , V_34 ) ;
if ( V_33 > V_32 -> V_35 ) {
F_20 ( L_5 ) ;
V_7 = - V_38 ;
goto V_39;
}
V_6 -> V_40 =
F_19 ( strlen ( V_6 -> V_10 -> V_25 ) +
V_32 -> V_35 + 2 , V_8 ) ;
if ( V_6 -> V_40 == NULL ) {
V_7 = - V_9 ;
goto V_39;
}
sprintf ( V_6 -> V_40 , L_6 , V_6 -> V_10 -> V_25 ,
V_32 -> V_37 ) ;
return 0 ;
V_39:
return V_7 ;
}
int F_21 ( struct V_3 * V_4 , struct V_1 * V_1 )
{
F_2 ( L_1 ) ;
V_4 -> V_41 . V_1 = V_1 ;
V_4 -> V_42 = & V_43 ;
F_22 ( & V_4 -> V_24 ) ;
return F_1 ( V_1 , V_4 ) ;
}
void F_23 ( struct V_3 * V_4 , struct V_1 * V_1 )
{
struct V_5 * V_6 , * V_44 ;
F_2 ( L_1 ) ;
F_24 (dev, tmp, &driver->device_list, driver_item)
F_25 ( V_6 ) ;
F_12 ( L_7 ) ;
}
