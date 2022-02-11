static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
F_2 ( & V_5 . V_6 , V_3 ) ;
V_4 = F_3 ( V_5 . V_7 + V_8 ) ;
V_4 |= 1 << ( V_9 + F_4 ( V_2 ) ) ;
F_5 ( V_5 . V_7 + V_8 , V_4 ) ;
F_6 ( & V_5 . V_6 , V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
T_1 V_4 ;
F_2 ( & V_5 . V_6 , V_3 ) ;
V_4 = F_3 ( V_5 . V_7 + V_8 ) ;
V_4 &= ~ ( 1 << ( V_9 + F_4 ( V_2 ) ) ) ;
F_5 ( V_5 . V_7 + V_8 , V_4 ) ;
F_6 ( & V_5 . V_6 , V_3 ) ;
}
static void F_8 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_14 , V_4 ;
T_1 V_15 , V_16 ;
F_10 ( & V_11 -> V_6 ) ;
V_13 -> V_17 ( & V_11 -> V_1 ) ;
F_11 ( & V_11 -> V_6 ) ;
V_15 = F_3 ( V_5 . V_7 + V_8 ) ;
V_16 = F_3 ( V_5 . V_7 + V_18 ) ;
V_4 = F_12 ( ( V_15 & V_16 ) >> V_9 ) ;
if ( V_4 ) {
V_14 = F_13 ( V_5 . V_19 , V_4 - 1 ) ;
F_14 ( V_14 ) ;
}
F_10 ( & V_11 -> V_6 ) ;
V_13 -> V_20 ( & V_11 -> V_1 ) ;
if ( ! F_15 ( & V_11 -> V_1 ) )
V_13 -> V_21 ( & V_11 -> V_1 ) ;
F_11 ( & V_11 -> V_6 ) ;
}
static int F_16 ( struct V_22 * V_23 , unsigned int V_24 ,
T_2 V_25 )
{
F_17 ( L_1 , V_26 , V_23 , V_24 , ( int ) V_25 ) ;
F_18 ( V_24 , & V_5 ) ;
F_19 ( V_24 , & V_27 , V_28 ) ;
F_20 ( V_24 , V_29 ) ;
return 0 ;
}
static int F_21 ( struct V_22 * V_23 , struct V_30 * V_31 ,
const T_1 * V_32 , unsigned int V_33 ,
T_2 * V_34 ,
unsigned int * V_35 )
{
if ( V_33 != 2 )
return - 1 ;
F_17 ( L_2 , V_26 , V_32 [ 0 ] , V_32 [ 1 ] ) ;
* V_34 = V_32 [ 1 ] ;
* V_35 = V_36 ;
return 0 ;
}
static void T_3 F_22 ( void )
{
struct V_30 * V_37 ;
int V_38 ;
F_23 () ;
V_37 = F_24 ( NULL , NULL , L_3 ) ;
if ( ! V_37 )
goto V_39;
F_17 ( L_4 , V_26 , V_37 ) ;
V_5 . V_7 = F_25 ( V_37 , 0 ) ;
if ( ! V_5 . V_7 )
goto V_39;
F_17 ( L_5 , V_26 , V_5 . V_7 ) ;
V_38 = F_26 ( V_37 , 0 ) ;
if ( ! V_38 )
goto V_39;
F_17 ( L_6 , V_26 , V_38 ) ;
F_5 ( V_5 . V_7 + V_8 , 0 ) ;
F_27 ( & V_5 . V_6 ) ;
V_5 . V_19 = F_28 ( V_37 ,
V_40 , & V_41 , & V_5 ) ;
if ( ! V_5 . V_19 )
goto V_39;
F_17 ( L_7 , V_26 ) ;
F_29 ( V_38 , & V_5 ) ;
F_30 ( V_38 , F_8 ) ;
return;
V_39:
F_31 ( L_8 ) ;
}
static void T_3 F_32 ( void )
{
struct V_30 * V_42 ;
struct V_43 T_4 * V_44 ;
T_1 V_45 ;
if ( V_46 . V_47 )
V_46 . V_47 ( L_9 , 0 ) ;
F_33 () ;
F_34 () ;
F_35 () ;
V_42 = F_36 ( NULL , V_48 ) ;
V_44 = F_25 ( V_42 , 0 ) ;
F_37 ( V_42 ) ;
if ( ! V_44 ) {
F_38 ( V_49 L_10 ,
V_26 ) ;
return;
}
V_45 = F_3 ( & V_44 -> V_45 ) ;
V_45 &= ~ 0x03000000 ;
V_45 |= 0x01000000 ;
F_5 ( & V_44 -> V_45 , V_45 ) ;
F_39 ( V_44 ) ;
}
static int T_3 F_40 ( void )
{
return F_41 ( V_50 , V_51 ) ;
}
