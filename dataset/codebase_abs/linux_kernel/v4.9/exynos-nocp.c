static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_4 -> V_6 , V_7 ,
V_8 , 0 ) ;
if ( V_5 < 0 ) {
F_4 ( V_4 -> V_9 , L_1 ) ;
return V_5 ;
}
V_5 = F_5 ( V_4 -> V_6 , V_10 , 0x0 ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_3 ( V_4 -> V_6 , V_12 ,
V_13 ,
V_14 ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_3 ( V_4 -> V_6 , V_15 ,
V_13 ,
V_16 ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_3 ( V_4 -> V_6 , V_17 ,
V_13 ,
V_18 ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_3 ( V_4 -> V_6 , V_19 ,
V_13 ,
V_16 ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_5 ( V_4 -> V_6 , V_20 , 0x0 ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_5 ( V_4 -> V_6 , V_21 , 0x0 ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_3 ( V_4 -> V_6 , V_22 ,
V_23 ,
V_24 ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_3 ( V_4 -> V_6 , V_25 ,
V_23 ,
V_24 ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_3 ( V_4 -> V_6 , V_26 ,
V_23 ,
V_24 ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_3 ( V_4 -> V_6 , V_27 ,
V_23 ,
V_24 ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_3 ( V_4 -> V_6 , V_7 ,
V_8 | V_28 ,
V_8 | V_28 ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_3 ( V_4 -> V_6 , V_29 ,
V_30 ,
V_30 ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_3 ( V_4 -> V_6 , V_7 ,
V_8 ,
V_8 ) ;
if ( V_5 < 0 )
goto V_11;
return 0 ;
V_11:
if ( F_3 ( V_4 -> V_6 , V_7 ,
V_8 , 0 ) ) {
F_4 ( V_4 -> V_9 , L_2 ) ;
}
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_33 [ 4 ] ;
int V_5 ;
V_5 = F_7 ( V_4 -> V_6 , V_34 , & V_33 [ 0 ] ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_7 ( V_4 -> V_6 , V_35 , & V_33 [ 1 ] ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_7 ( V_4 -> V_6 , V_36 , & V_33 [ 2 ] ) ;
if ( V_5 < 0 )
goto V_11;
V_5 = F_7 ( V_4 -> V_6 , V_37 , & V_33 [ 3 ] ) ;
if ( V_5 < 0 )
goto V_11;
V_32 -> V_38 = ( ( V_33 [ 1 ] << 16 ) | V_33 [ 0 ] ) ;
V_32 -> V_39 = ( ( V_33 [ 3 ] << 16 ) | V_33 [ 2 ] ) ;
F_8 ( & V_2 -> V_9 , L_3 , V_2 -> V_40 -> V_41 ,
V_32 -> V_38 , V_32 -> V_39 ) ;
return 0 ;
V_11:
F_4 ( V_4 -> V_9 , L_4 ) ;
return V_5 ;
}
static int F_9 ( struct V_42 * V_43 ,
struct V_3 * V_4 )
{
struct V_44 * V_9 = V_4 -> V_9 ;
struct V_45 * V_46 = V_9 -> V_47 ;
struct V_48 * V_49 ;
void T_1 * V_50 ;
if ( ! V_46 ) {
F_4 ( V_9 , L_5 ) ;
return - V_51 ;
}
V_4 -> V_52 = F_10 ( V_9 , L_6 ) ;
if ( F_11 ( V_4 -> V_52 ) )
V_4 -> V_52 = NULL ;
V_49 = F_12 ( V_43 , V_53 , 0 ) ;
V_50 = F_13 ( V_9 , V_49 ) ;
if ( F_11 ( V_50 ) )
return F_14 ( V_50 ) ;
V_54 . V_55 = F_15 ( V_49 ) - 4 ;
V_4 -> V_6 = F_16 ( V_9 , V_50 ,
& V_54 ) ;
if ( F_11 ( V_4 -> V_6 ) ) {
F_4 ( V_9 , L_7 ) ;
return F_14 ( V_4 -> V_6 ) ;
}
return 0 ;
}
static int F_17 ( struct V_42 * V_43 )
{
struct V_44 * V_9 = & V_43 -> V_9 ;
struct V_45 * V_46 = V_9 -> V_47 ;
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_18 ( & V_43 -> V_9 , sizeof( * V_4 ) , V_56 ) ;
if ( ! V_4 )
return - V_57 ;
V_4 -> V_9 = & V_43 -> V_9 ;
V_5 = F_9 ( V_43 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_43 -> V_9 ,
L_8 ) ;
return V_5 ;
}
V_4 -> V_40 . V_58 = & V_59 ;
V_4 -> V_40 . V_60 = V_4 ;
V_4 -> V_40 . V_41 = V_46 -> V_61 ;
V_4 -> V_2 = F_19 ( & V_43 -> V_9 , & V_4 -> V_40 ) ;
if ( F_11 ( V_4 -> V_2 ) ) {
F_4 ( & V_43 -> V_9 ,
L_9 ) ;
return F_14 ( V_4 -> V_2 ) ;
}
F_20 ( V_43 , V_4 ) ;
F_21 ( V_4 -> V_52 ) ;
F_22 ( L_10 ,
F_23 ( V_9 ) ) ;
return 0 ;
}
static int F_24 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_25 ( V_43 ) ;
F_26 ( V_4 -> V_52 ) ;
return 0 ;
}
