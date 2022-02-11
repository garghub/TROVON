static void F_1 ( void )
{
F_2 ( 0x80 , V_1 . V_2 + V_3 ) ;
F_2 ( 0x86 , V_1 . V_2 + V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
F_4 ( & V_1 . V_6 ) ;
F_1 () ;
F_2 ( V_7 , V_1 . V_2 + V_8 ) ;
F_5 ( & V_1 . V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_4 * V_5 , unsigned int V_9 )
{
T_1 V_10 ;
T_2 clock ;
T_3 V_11 ;
clock = 33000000 ;
V_10 = ( V_9 * clock ) >> 15 ;
V_10 -= 1 ;
F_4 ( & V_1 . V_6 ) ;
V_11 = V_12 & 0x38 ;
F_2 ( V_11 , V_1 . V_2 + V_13 ) ;
F_1 () ;
F_7 ( 0 , V_1 . V_2 + V_14 ) ;
F_1 () ;
F_7 ( V_10 , V_1 . V_2 + V_15 ) ;
F_1 () ;
F_2 ( V_7 | V_16 , V_1 . V_2 + V_8 ) ;
F_5 ( & V_1 . V_6 ) ;
V_5 -> V_17 = V_9 ;
return 0 ;
}
static int F_8 ( struct V_4 * V_5 )
{
F_6 ( V_5 , V_5 -> V_17 ) ;
F_4 ( & V_1 . V_6 ) ;
F_2 ( V_18 , V_1 . V_2 + V_19 ) ;
F_5 ( & V_1 . V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
if ( F_10 ( V_1 . V_2 + V_19 ) & V_20 )
return - 1 ;
F_4 ( & V_1 . V_6 ) ;
F_2 ( 0 , V_1 . V_2 + V_19 ) ;
F_5 ( & V_1 . V_6 ) ;
return 0 ;
}
static int F_11 ( struct V_21 * V_22 , void * V_23 )
{
F_12 ( V_22 , L_1 ,
F_13 ( V_1 . V_2 + V_14 ) ) ;
F_12 ( V_22 , L_2 ,
F_13 ( V_1 . V_2 + V_15 ) ) ;
F_12 ( V_22 , L_3 ,
F_14 ( V_1 . V_2 + V_3 ) ) ;
F_12 ( V_22 , L_4 ,
F_14 ( V_1 . V_2 + V_13 ) ) ;
F_12 ( V_22 , L_5 ,
F_13 ( V_1 . V_2 + V_24 ) ) ;
F_12 ( V_22 , L_6 ,
F_14 ( V_1 . V_2 + V_19 ) ) ;
F_12 ( V_22 , L_7 ) ;
return 0 ;
}
static int F_15 ( struct V_25 * V_25 , struct V_26 * V_26 )
{
return F_16 ( V_26 , F_11 , NULL ) ;
}
static void T_4 F_17 ( void )
{
V_1 . V_27 = F_18 ( L_8 ,
V_28 | V_29 , NULL , NULL , & V_30 ) ;
}
static void F_19 ( void )
{
F_20 ( V_1 . V_27 ) ;
}
static void T_4 F_17 ( void )
{
}
static void F_19 ( void )
{
}
static int T_4 F_21 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
T_3 V_35 ;
int V_36 ;
V_34 = F_22 ( V_32 , V_37 , 0 ) ;
if ( ! V_34 )
return - V_38 ;
if ( ! F_23 ( V_34 -> V_39 , F_24 ( V_34 ) , V_32 -> V_40 ) ) {
F_25 ( & V_32 -> V_41 , L_9 ,
( T_2 ) V_34 -> V_39 ) ;
return - V_42 ;
}
V_1 . V_2 = V_34 -> V_39 ;
F_26 ( & V_32 -> V_41 , L_10 , V_1 . V_2 ) ;
V_43 . V_17 = V_17 ;
F_27 ( & V_43 , V_44 ) ;
F_28 ( & V_1 . V_6 ) ;
V_35 = F_10 ( V_1 . V_2 + V_19 ) ;
if ( V_35 & V_20 )
F_29 ( & V_32 -> V_41 ,
L_11 , V_35 ) ;
F_17 () ;
V_36 = F_30 ( & V_43 ) ;
if ( V_36 ) {
F_25 ( & V_32 -> V_41 ,
L_12 ,
V_36 ) ;
goto V_45;
}
return 0 ;
V_45:
F_19 () ;
F_31 ( V_34 -> V_39 , F_24 ( V_34 ) ) ;
V_1 . V_2 = 0 ;
return V_36 ;
}
static int T_5 F_32 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
V_34 = F_22 ( V_32 , V_37 , 0 ) ;
F_9 ( NULL ) ;
F_33 ( & V_43 ) ;
F_19 () ;
F_31 ( V_34 -> V_39 , F_24 ( V_34 ) ) ;
V_1 . V_2 = 0 ;
return 0 ;
}
static int T_6 F_34 ( void )
{
if ( ( V_17 < V_46 ) ||
( V_17 > V_47 ) ) {
F_35 ( L_13
L_14 ,
V_17 , V_46 , V_47 ) ;
return - V_48 ;
}
return F_36 ( & V_49 ) ;
}
static void T_7 F_37 ( void )
{
F_38 ( & V_49 ) ;
}
