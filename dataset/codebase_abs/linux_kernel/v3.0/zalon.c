static int T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 V_3 ;
T_2 V_4 ;
int error = - V_5 ;
void T_3 * V_6 = F_2 ( V_2 -> V_7 . V_8 , 4096 ) ;
void T_3 * V_9 = V_6 + V_10 ;
static int V_11 = 0 ;
struct V_12 * V_13 ;
struct V_14 V_15 ;
F_3 ( V_16 , V_6 + V_17 ) ;
while ( ! ( F_4 ( V_6 + V_18 ) & V_19 ) )
F_5 () ;
F_3 ( V_20 | V_21 | V_22 ,
V_6 + V_23 ) ;
V_4 = ( F_4 ( V_6 + V_23 ) >> 24 ) & 0x07 ;
V_2 -> V_24 = F_6 ( & V_3 ) ;
F_7 ( V_25 L_1 , V_26 ,
V_4 , V_2 -> V_24 ) ;
F_3 ( V_3 . V_27 | V_3 . V_28 , V_6 + V_29 ) ;
if ( V_4 == 0 )
F_7 ( V_30 L_2 , V_26 ) ;
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
F_8 ( 0x20 , V_9 + 0x38 ) ;
F_8 ( 0x04 , V_9 + 0x1b ) ;
F_8 ( 0x80 , V_9 + 0x22 ) ;
V_15 . V_31 = V_32 ;
V_15 . V_33 = 7 ;
V_15 . V_2 = & V_2 -> V_2 ;
V_15 . V_34 . V_35 = V_2 -> V_7 . V_8 + V_10 ;
V_15 . V_34 . V_36 = V_9 ;
V_15 . V_34 . V_24 = V_2 -> V_24 ;
V_15 . V_37 = 2 ;
V_13 = F_9 ( & V_38 , V_11 , & V_15 ) ;
if ( ! V_13 )
return - V_5 ;
if ( F_10 ( V_2 -> V_24 , V_39 , V_40 , L_3 , V_13 ) ) {
F_11 ( V_41 , & V_2 -> V_2 , L_4 ,
V_2 -> V_24 ) ;
goto V_42;
}
V_11 ++ ;
F_12 ( & V_2 -> V_2 , V_13 ) ;
error = F_13 ( V_13 , & V_2 -> V_2 ) ;
if ( error )
goto V_43;
F_14 ( V_13 ) ;
return 0 ;
V_43:
F_15 ( V_2 -> V_24 , V_13 ) ;
V_42:
F_16 ( V_13 ) ;
return error ;
}
static int T_4 F_17 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_18 ( & V_2 -> V_2 ) ;
F_19 ( V_13 ) ;
F_16 ( V_13 ) ;
F_15 ( V_2 -> V_24 , V_13 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
int V_44 = F_21 () ;
if ( ! V_44 )
V_44 = F_22 ( & V_45 ) ;
if ( V_44 )
F_23 () ;
return V_44 ;
}
static void T_4 F_24 ( void )
{
F_25 ( & V_45 ) ;
F_23 () ;
}
