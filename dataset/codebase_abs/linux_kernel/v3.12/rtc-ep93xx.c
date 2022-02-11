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
static int F_11 ( struct V_24 * V_25 )
{
struct V_5 * V_5 ;
struct V_26 * V_27 ;
int V_28 ;
V_5 = F_12 ( & V_25 -> V_2 , sizeof( * V_5 ) , V_29 ) ;
if ( ! V_5 )
return - V_30 ;
V_27 = F_13 ( V_25 , V_31 , 0 ) ;
V_5 -> V_8 = F_14 ( & V_25 -> V_2 , V_27 ) ;
if ( F_15 ( V_5 -> V_8 ) )
return F_16 ( V_5 -> V_8 ) ;
V_25 -> V_2 . V_6 = V_5 ;
F_17 ( V_25 , V_5 ) ;
V_5 -> V_32 = F_18 ( & V_25 -> V_2 ,
V_25 -> V_33 , & V_34 , V_35 ) ;
if ( F_15 ( V_5 -> V_32 ) ) {
V_28 = F_16 ( V_5 -> V_32 ) ;
goto exit;
}
V_28 = F_19 ( & V_25 -> V_2 . V_36 , & V_37 ) ;
if ( V_28 )
goto exit;
return 0 ;
exit:
V_25 -> V_2 . V_6 = NULL ;
return V_28 ;
}
static int F_20 ( struct V_24 * V_25 )
{
F_21 ( & V_25 -> V_2 . V_36 , & V_37 ) ;
V_25 -> V_2 . V_6 = NULL ;
return 0 ;
}
