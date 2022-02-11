static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 -> V_4 ,
V_5 ) ;
F_3 ( V_2 -> V_3 -> V_4 ,
V_6 ) ;
F_4 ( V_2 -> V_3 -> V_4 , 24 ) ;
F_5 ( 1 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 . V_10 ;
struct V_11 V_12 ;
struct V_13 V_14 ;
T_1 V_15 , V_16 ;
unsigned long V_17 ;
unsigned long V_18 ;
int V_19 ;
V_19 = F_7 ( V_2 ) ;
if ( V_19 ) {
F_8 ( L_1 ) ;
goto V_20;
}
V_19 = F_9 ( V_21 . V_22 ) ;
if ( V_19 )
goto V_23;
V_19 = F_10 () ;
if ( V_19 )
goto V_24;
V_19 = F_11 () ;
if ( V_19 )
goto V_25;
F_1 ( V_2 ) ;
V_2 -> V_9 . V_26 |= V_27 | V_28 ;
F_12 ( V_2 -> V_3 -> V_4 , V_2 -> V_9 . V_26 ,
V_2 -> V_9 . V_29 , V_2 -> V_9 . V_30 ) ;
V_19 = F_13 ( 1 , V_8 -> V_31 * 1000 ,
& V_12 , & V_14 ) ;
if ( V_19 )
goto V_32;
V_17 = V_12 . V_17 ;
V_15 = V_14 . V_15 ;
V_16 = V_14 . V_16 ;
V_18 = V_17 / V_15 / V_16 / 1000 ;
if ( V_18 != V_8 -> V_31 ) {
F_14 ( L_2
L_3 ,
V_8 -> V_31 , V_18 ) ;
V_8 -> V_31 = V_18 ;
}
F_15 ( V_2 -> V_3 -> V_4 , V_8 ) ;
V_19 = F_16 ( & V_12 ) ;
if ( V_19 )
goto V_33;
V_19 = F_17 ( V_2 -> V_3 -> V_4 , & V_14 ) ;
if ( V_19 )
goto V_34;
F_18 ( V_2 -> V_35 . V_21 . V_36 ) ;
V_19 = F_19 () ;
if ( V_19 )
goto V_37;
F_20 ( 2 ) ;
V_2 -> V_3 -> V_38 ( V_2 -> V_3 ) ;
return 0 ;
V_37:
V_34:
V_33:
V_32:
F_21 () ;
V_25:
F_22 () ;
V_24:
F_23 ( V_21 . V_22 ) ;
V_23:
F_24 ( V_2 ) ;
V_20:
return V_19 ;
}
void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_39 ( V_2 -> V_3 ) ;
F_26 () ;
F_21 () ;
F_22 () ;
F_23 ( V_21 . V_22 ) ;
F_24 ( V_2 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
F_28 ( L_4 ) ;
if ( V_21 . V_22 == NULL ) {
struct V_40 * V_41 ;
V_41 = F_29 () ;
if ( F_30 ( V_41 ) ) {
F_8 ( L_5 ) ;
return F_31 ( V_41 ) ;
}
V_21 . V_22 = V_41 ;
}
return 0 ;
}
int F_32 ( void )
{
return 0 ;
}
void F_33 ( void )
{
}
