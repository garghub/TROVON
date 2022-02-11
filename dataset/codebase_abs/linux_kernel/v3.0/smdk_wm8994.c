static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 ;
int V_12 ;
if ( F_2 ( V_4 ) == 8000 || F_2 ( V_4 ) == 11025 )
V_11 = F_2 ( V_4 ) * 512 ;
else
V_11 = F_2 ( V_4 ) * 256 ;
V_12 = F_3 ( V_10 , V_13
| V_14
| V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_9 , V_13
| V_14
| V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_4 ( V_10 , V_16 , V_17 ,
V_18 , V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_5 ( V_10 , V_19 ,
V_11 , V_20 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_21 * V_22 = V_6 -> V_22 ;
struct V_23 * V_24 = & V_22 -> V_24 ;
F_7 ( V_24 , L_1 ) ;
F_7 ( V_24 , L_2 ) ;
F_7 ( V_24 , L_3 ) ;
F_7 ( V_24 , L_4 ) ;
F_7 ( V_24 , L_5 ) ;
F_7 ( V_24 , L_6 ) ;
F_8 ( V_24 , L_7 ) ;
F_8 ( V_24 , L_8 ) ;
F_8 ( V_24 , L_9 ) ;
F_8 ( V_24 , L_10 ) ;
F_8 ( V_24 , L_11 ) ;
F_8 ( V_24 , L_12 ) ;
F_8 ( V_24 , L_13 ) ;
F_8 ( V_24 , L_14 ) ;
F_8 ( V_24 , L_15 ) ;
F_8 ( V_24 , L_16 ) ;
F_8 ( V_24 , L_17 ) ;
F_8 ( V_24 , L_18 ) ;
F_8 ( V_24 , L_19 ) ;
F_8 ( V_24 , L_20 ) ;
F_9 ( V_24 ) ;
return 0 ;
}
static int T_1 F_10 ( void )
{
int V_12 ;
V_25 = F_11 ( L_21 , - 1 ) ;
if ( ! V_25 )
return - V_26 ;
F_12 ( V_25 , & V_27 ) ;
V_12 = F_13 ( V_25 ) ;
if ( V_12 )
F_14 ( V_25 ) ;
return V_12 ;
}
static void T_2 F_15 ( void )
{
F_16 ( V_25 ) ;
}
