static int T_1
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
static int V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
if ( V_5 >= V_11 )
return - V_12 ;
if ( ! V_13 [ V_5 ] ) {
V_5 ++ ;
return - V_14 ;
}
V_10 = F_2 ( V_15 [ V_5 ] , V_16 [ V_5 ] , V_17 , 0 , & V_7 ) ;
if ( V_10 )
return V_10 ;
if ( ( V_18 != 48000 ) && ( V_18 != 44100 ) ) {
F_3 ( V_19 L_1 ,
V_18 ) ;
F_3 ( V_19 L_2
L_3 ) ;
V_18 = 48000 ;
}
if ( ( V_20 != 1 ) && ( V_20 != 2 ) && ( V_20 != 4 ) ) {
F_3 ( V_19 L_4 ,
V_20 ) ;
F_3 ( V_19 L_5
L_6 ) ;
V_20 = 2 ;
}
V_10 = F_4 ( V_7 , V_2 , V_18 , V_20 ,
V_4 -> V_21 , V_22 [ V_5 ] , & V_9 ) ;
if ( V_10 < 0 )
goto error;
V_7 -> V_23 = V_9 ;
V_10 = F_5 ( V_9 ) ;
if ( V_10 < 0 )
goto error;
strcpy ( V_7 -> V_24 , L_7 ) ;
strcpy ( V_7 -> V_25 , L_8 ) ;
snprintf ( V_7 -> V_26 , sizeof( V_7 -> V_26 ) , L_9 ,
V_7 -> V_25 , V_9 -> V_27 , V_9 -> V_28 ) ;
V_10 = F_6 ( V_7 ) ;
if ( V_10 < 0 )
goto error;
F_7 ( V_2 , V_7 ) ;
V_5 ++ ;
return 0 ;
error:
F_8 ( V_7 ) ;
return V_10 ;
}
static void T_2 F_9 ( struct V_1 * V_2 )
{
F_8 ( F_10 ( V_2 ) ) ;
F_7 ( V_2 , NULL ) ;
}
static int F_11 ( struct V_1 * V_2 , T_3 V_29 )
{
struct V_6 * V_7 = F_10 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_23 ;
return V_9 -> V_30 ( V_9 , V_29 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_10 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_23 ;
return V_9 -> V_31 ( V_9 ) ;
}
static int T_4 F_13 ( void )
{
return F_14 ( & V_32 ) ;
}
static void T_5 F_15 ( void )
{
F_16 ( & V_32 ) ;
}
