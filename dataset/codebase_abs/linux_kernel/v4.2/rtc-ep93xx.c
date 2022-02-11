static int F_1 ( struct V_1 * V_2 , unsigned short * V_3 ,
unsigned short * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
V_6 = F_3 ( V_5 -> V_7 + V_8 ) ;
if ( V_3 )
* V_3 = ( V_6 & V_9 )
>> V_10 ;
if ( V_4 )
* V_4 = ( V_6 & V_11 )
>> V_12 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
unsigned long time ;
time = F_3 ( V_5 -> V_7 + V_15 ) ;
F_5 ( time , V_14 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_16 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
F_7 ( V_16 + 1 , V_5 -> V_7 + V_17 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
unsigned short V_3 , V_4 ;
F_1 ( V_2 , & V_3 , & V_4 ) ;
F_9 ( V_19 , L_1 , V_3 ) ;
F_9 ( V_19 , L_2 , V_4 ) ;
return 0 ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_20 * V_21 , char * V_22 )
{
unsigned short V_3 ;
F_1 ( V_2 , & V_3 , NULL ) ;
return sprintf ( V_22 , L_3 , V_3 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_20 * V_21 , char * V_22 )
{
unsigned short V_4 ;
F_1 ( V_2 , NULL , & V_4 ) ;
return sprintf ( V_22 , L_3 , V_4 ) ;
}
static int F_12 ( struct V_23 * V_24 )
{
struct V_5 * V_5 ;
struct V_25 * V_26 ;
int V_27 ;
V_5 = F_13 ( & V_24 -> V_2 , sizeof( * V_5 ) , V_28 ) ;
if ( ! V_5 )
return - V_29 ;
V_26 = F_14 ( V_24 , V_30 , 0 ) ;
V_5 -> V_7 = F_15 ( & V_24 -> V_2 , V_26 ) ;
if ( F_16 ( V_5 -> V_7 ) )
return F_17 ( V_5 -> V_7 ) ;
V_24 -> V_2 . V_31 = V_5 ;
F_18 ( V_24 , V_5 ) ;
V_5 -> V_32 = F_19 ( & V_24 -> V_2 ,
V_24 -> V_33 , & V_34 , V_35 ) ;
if ( F_16 ( V_5 -> V_32 ) ) {
V_27 = F_17 ( V_5 -> V_32 ) ;
goto exit;
}
V_27 = F_20 ( & V_24 -> V_2 . V_36 , & V_37 ) ;
if ( V_27 )
goto exit;
return 0 ;
exit:
V_24 -> V_2 . V_31 = NULL ;
return V_27 ;
}
static int F_21 ( struct V_23 * V_24 )
{
F_22 ( & V_24 -> V_2 . V_36 , & V_37 ) ;
V_24 -> V_2 . V_31 = NULL ;
return 0 ;
}
