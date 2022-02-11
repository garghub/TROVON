static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 , V_9 = 0 ;
T_2 V_10 [ 2 ] ;
T_3 V_11 = 0 ;
struct V_12 * V_13 = F_3 ( V_7 ) ;
if ( F_4 ( & V_13 -> V_14 ) )
return - V_15 ;
V_8 = F_5 ( V_7 , NULL , 0 , & V_10 [ 0 ] , 2 ) ;
if ( V_8 < 0 ) {
F_6 ( L_1 , V_8 ) ;
goto V_16;
}
V_11 = ( V_10 [ 0 ] << 8 ) + V_10 [ 1 ] ;
F_7 ( V_2 , L_2 ,
V_10 [ 0 ] , V_10 [ 1 ] , V_11 ) ;
switch ( V_13 -> V_17 ) {
case V_18 :
V_9 = ( ( int ) V_11 / 32 ) * 250 ;
break;
case V_19 :
case V_20 :
V_9 = ( ( int ) V_11 / 8 ) * 625 / 10 ;
break;
case V_21 :
V_9 = ( ( int ) V_11 / 4 ) * 3125 / 100 ;
break;
}
V_8 = sprintf ( V_5 , L_3 , V_9 ) ;
V_16:
F_8 ( & V_13 -> V_14 ) ;
return V_8 ;
}
static T_1 F_9 ( struct V_1 * V_2 , struct V_3
* V_22 , char * V_5 )
{
return sprintf ( V_5 , L_4 , F_2 ( V_2 ) -> V_23 ) ;
}
static int F_10 ( struct V_6 * V_7 )
{
int V_17 = F_11 ( V_7 ) -> V_24 ;
struct V_12 * V_13 ;
int V_8 ;
if ( V_7 -> V_25 & ( V_26 | V_27 ) )
return - V_28 ;
V_13 = F_12 ( & V_7 -> V_2 , sizeof( * V_13 ) , V_29 ) ;
if ( ! V_13 )
return - V_30 ;
F_13 ( & V_13 -> V_14 ) ;
V_13 -> V_17 = V_17 ;
F_14 ( V_7 , V_13 ) ;
V_8 = F_15 ( & V_7 -> V_2 , & V_31 ) ;
if ( V_8 )
goto V_32;
V_8 = F_15 ( & V_7 -> V_2 , & V_33 ) ;
if ( V_8 )
goto V_34;
V_13 -> V_35 = F_16 ( & V_7 -> V_2 ) ;
if ( F_17 ( V_13 -> V_35 ) ) {
F_7 ( & V_7 -> V_2 , L_5 ) ;
V_8 = F_18 ( V_13 -> V_35 ) ;
goto V_36;
}
return 0 ;
V_36:
F_19 ( & V_7 -> V_2 , & V_33 ) ;
V_34:
F_19 ( & V_7 -> V_2 , & V_31 ) ;
V_32:
F_14 ( V_7 , NULL ) ;
return V_8 ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = F_3 ( V_7 ) ;
F_21 ( V_13 -> V_35 ) ;
F_19 ( & V_7 -> V_2 , & V_31 ) ;
F_19 ( & V_7 -> V_2 , & V_33 ) ;
F_14 ( V_7 , NULL ) ;
return 0 ;
}
