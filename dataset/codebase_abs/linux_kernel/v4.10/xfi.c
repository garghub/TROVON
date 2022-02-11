static int
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
V_10 = F_2 ( & V_2 -> V_5 , V_15 [ V_5 ] , V_16 [ V_5 ] , V_17 ,
0 , & V_7 ) ;
if ( V_10 )
return V_10 ;
if ( ( V_18 != 48000 ) && ( V_18 != 44100 ) ) {
F_3 ( V_7 -> V_5 ,
L_1 ,
V_18 ) ;
F_3 ( V_7 -> V_5 ,
L_2 ) ;
V_18 = 48000 ;
}
if ( ( V_19 != 1 ) && ( V_19 != 2 ) && ( V_19 != 4 ) ) {
F_3 ( V_7 -> V_5 , L_3 ,
V_19 ) ;
F_3 ( V_7 -> V_5 ,
L_4 ) ;
V_19 = 2 ;
}
V_10 = F_4 ( V_7 , V_2 , V_18 , V_19 ,
V_4 -> V_20 , V_21 [ V_5 ] , & V_9 ) ;
if ( V_10 < 0 )
goto error;
V_7 -> V_22 = V_9 ;
V_10 = F_5 ( V_9 ) ;
if ( V_10 < 0 )
goto error;
strcpy ( V_7 -> V_23 , L_5 ) ;
strcpy ( V_7 -> V_24 , L_6 ) ;
snprintf ( V_7 -> V_25 , sizeof( V_7 -> V_25 ) , L_7 ,
V_7 -> V_24 , V_9 -> V_26 , V_9 -> V_27 ) ;
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
static void F_9 ( struct V_1 * V_2 )
{
F_8 ( F_10 ( V_2 ) ) ;
}
static int F_11 ( struct V_28 * V_5 )
{
struct V_6 * V_7 = F_12 ( V_5 ) ;
struct V_8 * V_9 = V_7 -> V_22 ;
return V_9 -> V_29 ( V_9 ) ;
}
static int F_13 ( struct V_28 * V_5 )
{
struct V_6 * V_7 = F_12 ( V_5 ) ;
struct V_8 * V_9 = V_7 -> V_22 ;
return V_9 -> V_30 ( V_9 ) ;
}
