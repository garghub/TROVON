static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_7 ;
F_2 ( V_6 , L_1 ) ;
F_2 ( V_6 , L_2 ) ;
F_2 ( V_6 , L_3 ) ;
F_2 ( V_6 , L_4 ) ;
F_2 ( V_6 , L_5 ) ;
F_2 ( V_6 , L_6 ) ;
if ( F_3 () ) {
F_2 ( V_6 , L_7 ) ;
F_2 ( V_6 , L_8 ) ;
}
V_7 = F_4 ( V_4 , L_9 ,
V_8 | V_9 | V_10 ,
& V_11 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_5 ( & V_11 , F_6 ( V_12 ) , V_12 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_7 ( & V_11 , F_6 ( V_13 ) , V_13 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static int F_8 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 -> V_18 ;
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_19 * V_21 = V_2 -> V_21 ;
unsigned int V_22 = 24000000 ;
int V_7 = 0 ;
V_7 = F_9 ( V_21 , V_23 |
V_24 | V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_9 ( V_20 , V_23 |
V_24 | V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_10 ( V_20 , V_26 , 0 , V_22 ,
F_11 ( V_17 ) * 256 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_20 , V_27 ,
F_11 ( V_17 ) * 256 , V_28 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_13 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 -> V_18 ;
struct V_19 * V_20 = V_2 -> V_20 ;
unsigned int V_22 = 24000000 ;
int V_7 = 0 ;
if ( F_11 ( V_17 ) != 8000 )
return - V_29 ;
V_7 = F_9 ( V_20 , V_30 |
V_31 | V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_10 ( V_20 , V_32 , 0 , V_22 ,
F_11 ( V_17 ) * 256 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_20 , V_33 ,
F_11 ( V_17 ) * 256 , V_28 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int T_1 F_14 ( void )
{
int V_7 ;
if ( F_3 () ) {
V_34 . V_35 = V_36 [ V_37 ] ;
V_38 [ 1 ] . V_39 = V_36 [ V_37 ] ;
V_40 . V_35 = V_36 [ V_41 ] ;
} else if ( ! F_15 () )
return - V_42 ;
V_43 = F_16 ( L_10 , - 1 ) ;
if ( ! V_43 )
return - V_44 ;
V_7 = F_17 ( & V_43 -> V_45 , & V_46 ,
& V_34 , 1 ) ;
if ( V_7 ) {
F_18 ( V_43 ) ;
return V_7 ;
}
F_19 ( V_43 , & V_40 ) ;
V_7 = F_20 ( V_43 ) ;
if ( V_7 ) {
F_21 ( & V_43 -> V_45 ) ;
F_18 ( V_43 ) ;
}
return V_7 ;
}
static void T_2 F_22 ( void )
{
F_21 ( & V_43 -> V_45 ) ;
F_23 ( V_43 ) ;
}
