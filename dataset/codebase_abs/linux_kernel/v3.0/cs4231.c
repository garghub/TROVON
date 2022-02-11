static int T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( ! V_4 [ V_3 ] )
return 0 ;
if ( V_5 [ V_3 ] == V_6 ) {
F_2 ( V_2 , L_1 ) ;
return 0 ;
}
if ( V_7 [ V_3 ] == V_8 ) {
F_2 ( V_2 , L_2 ) ;
return 0 ;
}
if ( V_9 [ V_3 ] == V_10 ) {
F_2 ( V_2 , L_3 ) ;
return 0 ;
}
return 1 ;
}
static int T_1 F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int error ;
error = F_4 ( V_17 [ V_3 ] , V_18 [ V_3 ] , V_19 , 0 , & V_12 ) ;
if ( error < 0 )
return error ;
error = F_5 ( V_12 , V_5 [ V_3 ] , - 1 , V_7 [ V_3 ] , V_9 [ V_3 ] , V_20 [ V_3 ] ,
V_21 , 0 , & V_14 ) ;
if ( error < 0 )
goto V_22;
V_12 -> V_23 = V_14 ;
error = F_6 ( V_14 , 0 , & V_16 ) ;
if ( error < 0 )
goto V_22;
strcpy ( V_12 -> V_24 , L_4 ) ;
strcpy ( V_12 -> V_25 , V_16 -> V_26 ) ;
sprintf ( V_12 -> V_27 , L_5 ,
V_16 -> V_26 , V_14 -> V_5 , V_7 [ V_3 ] , V_9 [ V_3 ] ) ;
if ( V_20 [ V_3 ] >= 0 )
sprintf ( V_12 -> V_27 + strlen ( V_12 -> V_27 ) , L_6 , V_20 [ V_3 ] ) ;
error = F_7 ( V_14 ) ;
if ( error < 0 )
goto V_22;
error = F_8 ( V_14 , 0 , NULL ) ;
if ( error < 0 )
goto V_22;
if ( V_28 [ V_3 ] > 0 && V_28 [ V_3 ] != V_6 ) {
if ( V_29 [ V_3 ] == V_8 )
V_29 [ V_3 ] = - 1 ;
if ( F_9 ( V_12 , 0 , V_30 ,
V_28 [ V_3 ] , 0 , V_29 [ V_3 ] ,
V_29 [ V_3 ] >= 0 ? V_31 : 0 ,
NULL ) < 0 )
F_10 ( V_2 , L_7 ) ;
}
F_11 ( V_12 , V_2 ) ;
error = F_12 ( V_12 ) ;
if ( error < 0 )
goto V_22;
F_13 ( V_2 , V_12 ) ;
return 0 ;
V_22: F_14 ( V_12 ) ;
return error ;
}
static int T_2 F_15 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_14 ( F_16 ( V_2 ) ) ;
F_13 ( V_2 , NULL ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_3 , T_3 V_32 )
{
struct V_11 * V_12 = F_16 ( V_2 ) ;
struct V_13 * V_14 = V_12 -> V_23 ;
F_18 ( V_12 , V_33 ) ;
V_14 -> V_34 ( V_14 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_11 * V_12 = F_16 ( V_2 ) ;
struct V_13 * V_14 = V_12 -> V_23 ;
V_14 -> V_35 ( V_14 ) ;
F_18 ( V_12 , V_36 ) ;
return 0 ;
}
static int T_4 F_20 ( void )
{
return F_21 ( & V_37 , V_38 ) ;
}
static void T_5 F_22 ( void )
{
F_23 ( & V_37 ) ;
}
