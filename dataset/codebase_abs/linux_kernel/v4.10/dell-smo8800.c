static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( & V_4 -> V_5 ) ;
F_3 ( & V_4 -> V_6 ) ;
return V_7 ;
}
static T_1 F_4 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_5 ( V_4 -> V_8 , L_1 ) ;
return V_9 ;
}
static T_2 F_6 ( struct V_10 * V_11 ,
void * V_12 )
{
struct V_13 * V_1 ;
if ( V_11 -> type != V_14 )
return V_15 ;
V_1 = & V_11 -> V_2 . V_16 ;
if ( ! V_1 || ! V_1 -> V_17 )
return V_15 ;
* ( ( V_18 * ) V_12 ) = V_1 -> V_19 [ 0 ] ;
return V_20 ;
}
static V_18 F_7 ( struct V_21 * V_22 )
{
V_18 V_1 = 0 ;
T_2 V_23 ;
V_23 = F_8 ( V_22 -> V_24 , V_25 ,
F_6 , & V_1 ) ;
if ( F_9 ( V_23 ) ) {
F_10 ( & V_22 -> V_8 , L_2 ) ;
return 0 ;
}
return V_1 ;
}
static T_3 F_11 ( struct V_26 * V_26 , char T_4 * V_27 ,
T_5 V_28 , T_6 * V_29 )
{
struct V_3 * V_4 = F_12 ( V_26 -> V_30 ,
struct V_3 , V_31 ) ;
V_18 V_2 = 0 ;
unsigned char V_32 = 0 ;
T_3 V_33 = 1 ;
if ( V_28 < 1 )
return - V_34 ;
F_13 ( & V_4 -> V_5 , 0 ) ;
V_33 = F_14 ( V_4 -> V_6 ,
( V_2 = F_15 ( & V_4 -> V_5 , 0 ) ) ) ;
if ( V_33 )
return V_33 ;
V_32 = 1 ;
V_33 = 1 ;
if ( V_2 < 255 )
V_32 = V_2 ;
else
V_32 = 255 ;
if ( F_16 ( V_32 , V_27 ) )
V_33 = - V_35 ;
return V_33 ;
}
static int F_17 ( struct V_36 * V_36 , struct V_26 * V_26 )
{
struct V_3 * V_4 = F_12 ( V_26 -> V_30 ,
struct V_3 , V_31 ) ;
if ( F_18 ( 0 , & V_4 -> V_37 ) )
return - V_38 ;
F_13 ( & V_4 -> V_5 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_36 * V_36 , struct V_26 * V_26 )
{
struct V_3 * V_4 = F_12 ( V_26 -> V_30 ,
struct V_3 , V_31 ) ;
F_20 ( 0 , & V_4 -> V_37 ) ;
return 0 ;
}
static int F_21 ( struct V_21 * V_22 )
{
int V_39 ;
struct V_3 * V_4 ;
V_4 = F_22 ( & V_22 -> V_8 , sizeof( * V_4 ) , V_40 ) ;
if ( ! V_4 ) {
F_10 ( & V_22 -> V_8 , L_3 ) ;
return - V_41 ;
}
V_4 -> V_8 = & V_22 -> V_8 ;
V_4 -> V_31 . V_42 = V_43 ;
V_4 -> V_31 . V_44 = L_4 ;
V_4 -> V_31 . V_45 = & V_46 ;
F_23 ( & V_4 -> V_6 ) ;
V_39 = F_24 ( & V_4 -> V_31 ) ;
if ( V_39 ) {
F_10 ( & V_22 -> V_8 , L_5 , V_39 ) ;
return V_39 ;
}
V_22 -> V_47 = V_4 ;
V_4 -> V_1 = F_7 ( V_22 ) ;
if ( ! V_4 -> V_1 ) {
F_10 ( & V_22 -> V_8 , L_6 ) ;
V_39 = - V_34 ;
goto error;
}
V_39 = F_25 ( V_4 -> V_1 , F_1 ,
F_4 ,
V_48 | V_49 ,
V_50 , V_4 ) ;
if ( V_39 ) {
F_10 ( & V_22 -> V_8 ,
L_7 ,
V_4 -> V_1 , V_39 ) ;
goto error;
}
F_26 ( & V_22 -> V_8 , L_8 ,
V_4 -> V_1 ) ;
return 0 ;
error:
F_27 ( & V_4 -> V_31 ) ;
return V_39 ;
}
static int F_28 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = V_22 -> V_47 ;
F_29 ( V_4 -> V_1 , V_4 ) ;
F_27 ( & V_4 -> V_31 ) ;
F_26 ( & V_22 -> V_8 , L_9 ) ;
return 0 ;
}
