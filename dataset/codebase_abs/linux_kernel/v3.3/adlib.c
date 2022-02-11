static int T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( ! V_4 [ V_3 ] )
return 0 ;
if ( V_5 [ V_3 ] == V_6 ) {
F_2 ( V_2 , L_1 ) ;
return 0 ;
}
return 1 ;
}
static void F_3 ( struct V_7 * V_8 )
{
F_4 ( V_8 -> V_9 ) ;
}
static int T_1 F_5 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_7 * V_8 ;
struct V_10 * V_11 ;
int error ;
error = F_6 ( V_12 [ V_3 ] , V_13 [ V_3 ] , V_14 , 0 , & V_8 ) ;
if ( error < 0 ) {
F_2 ( V_2 , L_2 ) ;
return error ;
}
V_8 -> V_9 = F_7 ( V_5 [ V_3 ] , 4 , V_15 ) ;
if ( ! V_8 -> V_9 ) {
F_2 ( V_2 , L_3 ) ;
error = - V_16 ;
goto V_17;
}
V_8 -> V_18 = F_3 ;
strcpy ( V_8 -> V_19 , V_20 ) ;
strcpy ( V_8 -> V_21 , V_15 ) ;
sprintf ( V_8 -> V_22 , V_15 L_4 , V_5 [ V_3 ] ) ;
error = F_8 ( V_8 , V_5 [ V_3 ] , V_5 [ V_3 ] + 2 , V_23 , 1 , & V_11 ) ;
if ( error < 0 ) {
F_2 ( V_2 , L_5 ) ;
goto V_17;
}
error = F_9 ( V_11 , 0 , 0 , NULL ) ;
if ( error < 0 ) {
F_2 ( V_2 , L_6 ) ;
goto V_17;
}
F_10 ( V_8 , V_2 ) ;
error = F_11 ( V_8 ) ;
if ( error < 0 ) {
F_2 ( V_2 , L_7 ) ;
goto V_17;
}
F_12 ( V_2 , V_8 ) ;
return 0 ;
V_17: F_13 ( V_8 ) ;
return error ;
}
static int T_2 F_14 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_13 ( F_15 ( V_2 ) ) ;
F_12 ( V_2 , NULL ) ;
return 0 ;
}
static int T_3 F_16 ( void )
{
return F_17 ( & V_24 , V_25 ) ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_24 ) ;
}
