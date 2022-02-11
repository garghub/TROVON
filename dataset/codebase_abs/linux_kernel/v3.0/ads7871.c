static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_3 = V_3 | V_5 ;
V_4 = F_2 ( V_2 , V_3 ) ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
V_3 = V_3 | V_5 | V_6 ;
V_4 = F_4 ( V_2 , V_3 ) ;
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_7 )
{
T_1 V_8 [ 2 ] = { V_3 , V_7 } ;
return F_6 ( V_2 , V_8 , sizeof( V_8 ) ) ;
}
static T_2 F_7 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_1 * V_2 = F_8 ( V_10 ) ;
struct V_14 * V_15 = F_9 ( V_12 ) ;
int V_4 , V_7 , V_16 = 0 ;
T_3 V_17 , V_18 ;
V_17 = V_15 -> V_19 ;
F_5 ( V_2 , V_20 ,
( V_21 | V_22 | V_17 ) ) ;
V_4 = F_1 ( V_2 , V_20 ) ;
V_18 = ( ( V_4 & V_21 ) >> V_23 ) ;
while ( ( V_16 < 2 ) && V_18 ) {
V_16 ++ ;
V_4 = F_1 ( V_2 , V_20 ) ;
V_18 = ( ( V_4 & V_21 ) >> V_23 ) ;
F_10 ( 1 ) ;
}
if ( V_18 == 0 ) {
V_7 = F_3 ( V_2 , V_24 ) ;
V_7 = ( ( V_7 >> 2 ) * 25000 ) / 8192 ;
return sprintf ( V_13 , L_1 , V_7 ) ;
} else {
return - 1 ;
}
}
static int T_4 F_11 ( struct V_1 * V_2 )
{
int V_4 , V_25 ;
T_3 V_7 ;
struct V_26 * V_27 ;
F_12 ( & V_2 -> V_10 , L_2 ) ;
V_2 -> V_28 = ( V_29 ) ;
V_2 -> V_30 = 8 ;
F_13 ( V_2 ) ;
F_5 ( V_2 , V_31 , 0 ) ;
F_5 ( V_2 , V_32 , 0 ) ;
V_7 = ( V_33 | V_34 | V_35 | V_36 ) ;
F_5 ( V_2 , V_37 , V_7 ) ;
V_4 = F_1 ( V_2 , V_37 ) ;
F_12 ( & V_2 -> V_10 , L_3 , V_7 , V_4 ) ;
if ( V_7 != V_4 ) {
V_25 = - V_38 ;
goto exit;
}
V_27 = F_14 ( sizeof( struct V_26 ) , V_39 ) ;
if ( ! V_27 ) {
V_25 = - V_40 ;
goto exit;
}
V_25 = F_15 ( & V_2 -> V_10 . V_41 , & V_42 ) ;
if ( V_25 < 0 )
goto V_43;
F_16 ( V_2 , V_27 ) ;
V_27 -> V_44 = F_17 ( & V_2 -> V_10 ) ;
if ( F_18 ( V_27 -> V_44 ) ) {
V_25 = F_19 ( V_27 -> V_44 ) ;
goto V_45;
}
return 0 ;
V_45:
F_20 ( & V_2 -> V_10 . V_41 , & V_42 ) ;
V_43:
F_21 ( V_27 ) ;
exit:
return V_25 ;
}
static int T_5 F_22 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_23 ( V_2 ) ;
F_24 ( V_27 -> V_44 ) ;
F_20 ( & V_2 -> V_10 . V_41 , & V_42 ) ;
F_21 ( V_27 ) ;
return 0 ;
}
static int T_6 F_25 ( void )
{
return F_26 ( & V_46 ) ;
}
static void T_7 F_27 ( void )
{
F_28 ( & V_46 ) ;
}
