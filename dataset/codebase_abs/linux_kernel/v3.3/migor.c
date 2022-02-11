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
V_12 = F_6 ( V_11 , V_17 |
V_18 | V_19 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_6 ( V_8 -> V_20 , V_17 |
V_18 | V_19 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 = V_13 * 512 ;
F_7 ( & V_21 , V_2 ) ;
F_8 ( V_11 -> V_22 , L_1 , V_23 , V_2 ) ;
V_12 = F_4 ( V_8 -> V_20 , V_24 ,
V_2 / 2 , V_15 ) ;
if ( ! V_12 )
V_25 ++ ;
return V_12 ;
}
static int F_9 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = V_8 -> V_11 ;
if ( V_25 ) {
V_25 -- ;
if ( ! V_25 )
F_4 ( V_11 , V_14 , 0 ,
V_15 ) ;
} else {
F_8 ( V_11 -> V_22 , L_2 ) ;
}
return 0 ;
}
static int F_10 ( struct V_7 * V_8 )
{
struct V_26 * V_27 = V_8 -> V_27 ;
struct V_28 * V_29 = & V_27 -> V_29 ;
F_11 ( V_29 , V_30 ,
F_12 ( V_30 ) ) ;
F_13 ( V_29 , V_31 , F_12 ( V_31 ) ) ;
return 0 ;
}
static int T_1 F_14 ( void )
{
int V_12 ;
V_12 = F_15 ( & V_21 ) ;
if ( V_12 < 0 )
return V_12 ;
V_32 = F_16 ( & V_21 , L_3 , NULL ) ;
if ( ! V_32 ) {
V_12 = - V_33 ;
goto V_34;
}
F_17 ( V_32 ) ;
V_35 = F_18 ( L_4 , 1 ) ;
if ( ! V_35 ) {
V_12 = - V_33 ;
goto V_36;
}
F_19 ( V_35 , & V_37 ) ;
V_12 = F_20 ( V_35 ) ;
if ( V_12 )
goto V_38;
return 0 ;
V_38:
F_21 ( V_35 ) ;
V_36:
F_22 ( V_32 ) ;
V_34:
F_23 ( & V_21 ) ;
return V_12 ;
}
static void T_2 F_24 ( void )
{
F_22 ( V_32 ) ;
F_23 ( & V_21 ) ;
F_25 ( V_35 ) ;
}
