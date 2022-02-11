static int F_1 ( struct V_1 * V_2 , unsigned short * V_3 ,
unsigned short * V_4 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
unsigned long V_7 ;
V_7 = F_2 ( V_5 -> V_8 + V_9 ) ;
if ( V_3 )
* V_3 = ( V_7 & V_10 )
>> V_11 ;
if ( V_4 )
* V_4 = ( V_7 & V_12 )
>> V_13 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
unsigned long time ;
time = F_2 ( V_5 -> V_8 + V_16 ) ;
F_4 ( time , V_15 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned long V_17 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
F_6 ( V_17 + 1 , V_5 -> V_8 + V_18 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
unsigned short V_3 , V_4 ;
F_1 ( V_2 , & V_3 , & V_4 ) ;
F_8 ( V_20 , L_1 , V_3 ) ;
F_8 ( V_20 , L_2 , V_4 ) ;
return 0 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_21 * V_22 , char * V_23 )
{
unsigned short V_3 ;
F_1 ( V_2 , & V_3 , NULL ) ;
return sprintf ( V_23 , L_3 , V_3 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_21 * V_22 , char * V_23 )
{
unsigned short V_4 ;
F_1 ( V_2 , NULL , & V_4 ) ;
return sprintf ( V_23 , L_3 , V_4 ) ;
}
static int T_2 F_11 ( struct V_24 * V_25 )
{
struct V_5 * V_5 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
int V_30 ;
V_5 = F_12 ( & V_25 -> V_2 , sizeof( * V_5 ) , V_31 ) ;
if ( ! V_5 )
return - V_32 ;
V_27 = F_13 ( V_25 , V_33 , 0 ) ;
if ( ! V_27 )
return - V_34 ;
if ( ! F_14 ( & V_25 -> V_2 , V_27 -> V_35 ,
F_15 ( V_27 ) , V_25 -> V_36 ) )
return - V_37 ;
V_5 -> V_8 = F_16 ( & V_25 -> V_2 , V_27 -> V_35 ,
F_15 ( V_27 ) ) ;
if ( ! V_5 -> V_8 )
return - V_34 ;
V_25 -> V_2 . V_6 = V_5 ;
F_17 ( V_25 , V_29 ) ;
V_29 = F_18 ( V_25 -> V_36 ,
& V_25 -> V_2 , & V_38 , V_39 ) ;
if ( F_19 ( V_29 ) ) {
V_30 = F_20 ( V_29 ) ;
goto exit;
}
V_30 = F_21 ( & V_25 -> V_2 . V_40 , & V_41 ) ;
if ( V_30 )
goto V_42;
return 0 ;
V_42:
F_22 ( V_29 ) ;
exit:
F_17 ( V_25 , NULL ) ;
V_25 -> V_2 . V_6 = NULL ;
return V_30 ;
}
static int T_3 F_23 ( struct V_24 * V_25 )
{
struct V_28 * V_29 = F_24 ( V_25 ) ;
F_25 ( & V_25 -> V_2 . V_40 , & V_41 ) ;
F_17 ( V_25 , NULL ) ;
F_22 ( V_29 ) ;
V_25 -> V_2 . V_6 = NULL ;
return 0 ;
}
static int T_2 F_26 ( void )
{
return F_27 ( & V_43 , F_11 ) ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_43 ) ;
}
