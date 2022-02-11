static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_7 ;
F_2 ( V_6 , V_8 ,
F_3 ( V_8 ) ) ;
F_4 ( V_6 , V_9 ,
F_3 ( V_9 ) ) ;
F_5 ( V_6 , L_1 ) ;
F_5 ( V_6 , L_2 ) ;
F_5 ( V_6 , L_3 ) ;
F_5 ( V_6 , L_4 ) ;
F_5 ( V_6 , L_5 ) ;
F_5 ( V_6 , L_6 ) ;
if ( F_6 () ) {
F_5 ( V_6 , L_7 ) ;
F_5 ( V_6 , L_8 ) ;
}
F_7 ( V_6 ) ;
V_7 = F_8 ( V_4 , L_9 ,
V_10 | V_11 | V_12 ,
& V_13 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_9 ( & V_13 , F_3 ( V_14 ) , V_14 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_10 ( & V_13 , F_3 ( V_15 ) , V_15 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static int F_11 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_21 * V_23 = V_2 -> V_23 ;
unsigned int V_24 = 24000000 ;
int V_7 = 0 ;
V_7 = F_12 ( V_23 , V_25 |
V_26 | V_27 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_12 ( V_22 , V_25 |
V_26 | V_27 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_22 , V_28 , 0 , V_24 ,
F_14 ( V_19 ) * 256 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_15 ( V_22 , V_29 ,
F_14 ( V_19 ) * 256 , V_30 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = V_17 -> V_20 ;
struct V_21 * V_22 = V_2 -> V_22 ;
unsigned int V_24 = 24000000 ;
int V_7 = 0 ;
if ( F_14 ( V_19 ) != 8000 )
return - V_31 ;
V_7 = F_12 ( V_22 , V_32 |
V_33 | V_27 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_13 ( V_22 , V_34 , 0 , V_24 ,
F_14 ( V_19 ) * 256 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_15 ( V_22 , V_35 ,
F_14 ( V_19 ) * 256 , V_30 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int T_1 F_17 ( void )
{
int V_7 ;
if ( F_6 () ) {
V_36 . V_37 = V_38 [ V_39 ] ;
V_40 [ 1 ] . V_41 = V_38 [ V_39 ] ;
V_42 . V_37 = V_38 [ V_43 ] ;
} else if ( ! F_18 () )
return - V_44 ;
V_45 = F_19 ( L_10 , - 1 ) ;
if ( ! V_45 )
return - V_46 ;
V_7 = F_20 ( & V_45 -> V_47 , & V_36 ) ;
if ( V_7 ) {
F_21 ( V_45 ) ;
return V_7 ;
}
F_22 ( V_45 , & V_42 ) ;
V_7 = F_23 ( V_45 ) ;
if ( V_7 ) {
F_24 ( & V_45 -> V_47 ) ;
F_21 ( V_45 ) ;
}
return V_7 ;
}
static void T_2 F_25 ( void )
{
F_24 ( & V_45 -> V_47 ) ;
F_26 ( V_45 ) ;
}
