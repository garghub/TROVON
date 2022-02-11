static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
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
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int error ;
error = F_4 ( V_2 , V_15 [ V_3 ] , V_16 [ V_3 ] , V_17 , 0 , & V_12 ) ;
if ( error < 0 )
return error ;
error = F_5 ( V_12 , V_5 [ V_3 ] , - 1 , V_7 [ V_3 ] , V_9 [ V_3 ] , V_18 [ V_3 ] ,
V_19 , 0 , & V_14 ) ;
if ( error < 0 )
goto V_20;
V_12 -> V_21 = V_14 ;
error = F_6 ( V_14 , 0 ) ;
if ( error < 0 )
goto V_20;
strcpy ( V_12 -> V_22 , L_4 ) ;
strcpy ( V_12 -> V_23 , V_14 -> V_24 -> V_25 ) ;
sprintf ( V_12 -> V_26 , L_5 ,
V_14 -> V_24 -> V_25 , V_14 -> V_5 , V_7 [ V_3 ] , V_9 [ V_3 ] ) ;
if ( V_18 [ V_3 ] >= 0 )
sprintf ( V_12 -> V_26 + strlen ( V_12 -> V_26 ) , L_6 , V_18 [ V_3 ] ) ;
error = F_7 ( V_14 ) ;
if ( error < 0 )
goto V_20;
error = F_8 ( V_14 , 0 ) ;
if ( error < 0 )
goto V_20;
if ( V_27 [ V_3 ] > 0 && V_27 [ V_3 ] != V_6 ) {
if ( V_28 [ V_3 ] == V_8 )
V_28 [ V_3 ] = - 1 ;
if ( F_9 ( V_12 , 0 , V_29 ,
V_27 [ V_3 ] , 0 , V_28 [ V_3 ] ,
NULL ) < 0 )
F_10 ( V_2 , L_7 ) ;
}
error = F_11 ( V_12 ) ;
if ( error < 0 )
goto V_20;
F_12 ( V_2 , V_12 ) ;
return 0 ;
V_20: F_13 ( V_12 ) ;
return error ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_13 ( F_15 ( V_2 ) ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_30 )
{
struct V_11 * V_12 = F_15 ( V_2 ) ;
struct V_13 * V_14 = V_12 -> V_21 ;
F_17 ( V_12 , V_31 ) ;
V_14 -> V_32 ( V_14 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_11 * V_12 = F_15 ( V_2 ) ;
struct V_13 * V_14 = V_12 -> V_21 ;
V_14 -> V_33 ( V_14 ) ;
F_17 ( V_12 , V_34 ) ;
return 0 ;
}
