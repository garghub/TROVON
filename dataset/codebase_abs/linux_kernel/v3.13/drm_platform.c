static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
F_2 ( L_1 ) ;
V_6 = F_3 ( V_4 , & V_2 -> V_6 ) ;
if ( ! V_6 )
return - V_8 ;
V_6 -> V_9 = V_2 ;
V_7 = F_4 ( V_6 , 0 ) ;
if ( V_7 )
goto V_10;
F_5 ( L_2 ,
V_4 -> V_11 , V_4 -> V_12 , V_4 -> V_13 , V_4 -> V_14 ,
V_4 -> V_15 , V_6 -> V_16 -> V_17 ) ;
return 0 ;
V_10:
F_6 ( V_6 ) ;
return V_7 ;
}
static int F_7 ( struct V_5 * V_6 )
{
return F_8 ( V_6 -> V_9 , 0 ) ;
}
static const char * F_9 ( struct V_5 * V_6 )
{
return V_6 -> V_9 -> V_11 ;
}
static int F_10 ( struct V_5 * V_6 , struct V_18 * V_19 )
{
int V_20 , V_7 , V_21 ;
V_19 -> V_22 = 13 + strlen ( V_6 -> V_9 -> V_11 ) ;
V_19 -> V_23 = V_19 -> V_22 ;
V_19 -> V_24 = F_11 ( V_19 -> V_22 + 1 , V_25 ) ;
if ( V_19 -> V_24 == NULL )
return - V_8 ;
V_21 = V_6 -> V_9 -> V_21 ;
if ( V_21 == - 1 )
V_21 = 0 ;
V_20 = snprintf ( V_19 -> V_24 , V_19 -> V_22 ,
L_3 , V_6 -> V_9 -> V_11 , V_21 ) ;
if ( V_20 > V_19 -> V_22 ) {
F_12 ( L_4 ) ;
V_7 = - V_26 ;
goto V_27;
}
V_6 -> V_28 =
F_11 ( strlen ( V_6 -> V_9 -> V_11 ) +
V_19 -> V_22 + 2 , V_25 ) ;
if ( V_6 -> V_28 == NULL ) {
V_7 = - V_8 ;
goto V_27;
}
sprintf ( V_6 -> V_28 , L_5 , V_6 -> V_9 -> V_11 ,
V_19 -> V_24 ) ;
return 0 ;
V_27:
return V_7 ;
}
int F_13 ( struct V_3 * V_4 , struct V_1 * V_1 )
{
F_2 ( L_1 ) ;
V_4 -> V_29 . V_1 = V_1 ;
V_4 -> V_30 = & V_31 ;
F_14 ( & V_4 -> V_32 ) ;
return F_1 ( V_1 , V_4 ) ;
}
void F_15 ( struct V_3 * V_4 , struct V_1 * V_1 )
{
struct V_5 * V_6 , * V_33 ;
F_2 ( L_1 ) ;
F_16 (dev, tmp, &driver->device_list, driver_item)
F_17 ( V_6 ) ;
F_5 ( L_6 ) ;
}
