static int F_1 ( struct V_1 * V_2 , char * V_3 , T_1 * V_4 )
{
unsigned long long V_5 ;
T_2 V_6 ;
V_6 = F_2 ( V_2 -> V_7 -> V_8 , V_3 , NULL ,
& V_5 ) ;
if ( F_3 ( V_6 ) ) {
F_4 ( ( V_9 , V_6 , L_1 , V_3 ) ) ;
return - V_10 ;
}
* V_4 = V_5 ;
return 0 ;
}
static void F_5 ( struct V_11 * V_7 , T_3 V_12 )
{
struct V_13 * V_14 = F_6 ( V_7 ) ;
struct V_1 * V_2 = F_7 ( V_14 ) ;
T_1 * V_15 = V_2 -> V_16 ;
T_4 V_17 = F_8 ( V_14 ) ;
T_1 V_4 ;
int V_18 ;
F_9 ( & V_2 -> V_19 ) ;
memset ( V_15 , 0 , V_20 ) ;
switch ( V_12 ) {
case V_21 :
V_18 = F_1 ( V_2 , V_22 , & V_4 ) ;
if ( V_18 < 0 )
goto V_23;
* V_15 ++ = V_4 ;
break;
default:
F_10 ( & V_7 -> V_24 , L_2 ,
V_12 ) ;
goto V_23;
}
F_11 ( V_14 , V_2 -> V_16 , V_17 ) ;
V_23:
F_12 ( & V_2 -> V_19 ) ;
}
static int F_13 ( struct V_13 * V_14 ,
struct V_25 const * V_26 , int * V_4 ,
int * V_27 , long V_28 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
T_1 V_5 ;
int V_18 ;
if ( ( V_28 != V_29 ) && ( V_28 != V_30 ) )
return - V_31 ;
if ( V_26 -> type != V_32 )
return - V_31 ;
V_18 = F_1 ( V_2 , V_22 , & V_5 ) ;
if ( V_18 < 0 )
return V_18 ;
* V_4 = V_5 ;
return V_33 ;
}
static int F_14 ( struct V_11 * V_7 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_34 * V_15 ;
V_14 = F_15 ( & V_7 -> V_24 , sizeof( * V_2 ) ) ;
if ( ! V_14 )
return - V_35 ;
V_2 = F_7 ( V_14 ) ;
V_7 -> V_36 = V_14 ;
V_2 -> V_7 = V_7 ;
F_16 ( & V_2 -> V_19 ) ;
V_14 -> V_37 = V_38 ;
V_14 -> V_24 . V_39 = & V_7 -> V_24 ;
V_14 -> V_40 = & V_41 ;
V_14 -> V_42 = V_43 ;
V_14 -> V_44 = V_45 ;
V_14 -> V_46 = F_17 ( V_45 ) ;
V_15 = F_18 ( & V_7 -> V_24 ) ;
if ( ! V_15 )
return - V_35 ;
F_19 ( V_14 , V_15 ) ;
return F_20 ( & V_7 -> V_24 , V_14 ) ;
}
