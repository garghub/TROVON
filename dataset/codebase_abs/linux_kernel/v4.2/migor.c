static unsigned long F_1 ( struct V_1 * V_1 )
{
return V_2 ;
}
static int F_2 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = V_8 -> V_11 ;
int V_12 ;
unsigned int V_13 = F_3 ( V_6 ) ;
V_12 = F_4 ( V_11 , V_14 , 13000000 ,
V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_5 ( V_11 , V_16 , V_13 * 512 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 = V_13 * 512 ;
F_6 ( & V_17 , V_2 ) ;
F_7 ( V_11 -> V_18 , L_1 , V_19 , V_2 ) ;
V_12 = F_4 ( V_8 -> V_20 , V_21 ,
V_2 / 2 , V_15 ) ;
if ( ! V_12 )
V_22 ++ ;
return V_12 ;
}
static int F_8 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = V_8 -> V_11 ;
if ( V_22 ) {
V_22 -- ;
if ( ! V_22 )
F_4 ( V_11 , V_14 , 0 ,
V_15 ) ;
} else {
F_7 ( V_11 -> V_18 , L_2 ) ;
}
return 0 ;
}
static int T_1 F_9 ( void )
{
int V_12 ;
V_12 = F_10 ( & V_17 ) ;
if ( V_12 < 0 )
return V_12 ;
V_23 = F_11 ( & V_17 , L_3 , NULL ) ;
if ( ! V_23 ) {
V_12 = - V_24 ;
goto V_25;
}
V_26 = F_12 ( L_4 , 1 ) ;
if ( ! V_26 ) {
V_12 = - V_24 ;
goto V_27;
}
F_13 ( V_26 , & V_28 ) ;
V_12 = F_14 ( V_26 ) ;
if ( V_12 )
goto V_29;
return 0 ;
V_29:
F_15 ( V_26 ) ;
V_27:
F_16 ( V_23 ) ;
V_25:
F_17 ( & V_17 ) ;
return V_12 ;
}
static void T_2 F_18 ( void )
{
F_16 ( V_23 ) ;
F_17 ( & V_17 ) ;
F_19 ( V_26 ) ;
}
