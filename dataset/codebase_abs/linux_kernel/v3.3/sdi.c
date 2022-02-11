static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
F_3 ( V_2 -> V_4 -> V_5 , false ) ;
F_4 ( V_2 -> V_4 -> V_5 ,
V_6 ) ;
F_5 ( V_2 -> V_4 -> V_5 , 24 ) ;
F_6 ( 1 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 . V_10 ;
struct V_11 V_12 ;
struct V_13 V_14 ;
T_1 V_15 , V_16 ;
unsigned long V_17 ;
unsigned long V_18 ;
int V_19 ;
if ( V_2 -> V_4 == NULL ) {
F_8 ( L_1 ) ;
return - V_20 ;
}
V_19 = F_9 ( V_2 ) ;
if ( V_19 ) {
F_8 ( L_2 ) ;
goto V_21;
}
V_19 = F_10 ( V_22 . V_23 ) ;
if ( V_19 )
goto V_24;
V_19 = F_11 () ;
if ( V_19 )
goto V_25;
V_19 = F_12 () ;
if ( V_19 )
goto V_26;
F_1 ( V_2 ) ;
V_2 -> V_9 . V_27 |= V_28 | V_29 ;
F_13 ( V_2 -> V_4 -> V_5 , V_2 -> V_9 . V_27 ,
V_2 -> V_9 . V_30 , V_2 -> V_9 . V_31 ) ;
V_19 = F_14 ( 1 , V_8 -> V_32 * 1000 ,
& V_12 , & V_14 ) ;
if ( V_19 )
goto V_33;
V_17 = V_12 . V_17 ;
V_15 = V_14 . V_15 ;
V_16 = V_14 . V_16 ;
V_18 = V_17 / V_15 / V_16 / 1000 ;
if ( V_18 != V_8 -> V_32 ) {
F_15 ( L_3
L_4 ,
V_8 -> V_32 , V_18 ) ;
V_8 -> V_32 = V_18 ;
}
F_16 ( V_2 -> V_4 -> V_5 , V_8 ) ;
V_19 = F_17 ( & V_12 ) ;
if ( V_19 )
goto V_34;
V_19 = F_18 ( V_2 -> V_4 -> V_5 , & V_14 ) ;
if ( V_19 )
goto V_35;
F_19 ( V_2 -> V_36 . V_22 . V_37 ) ;
V_19 = F_20 () ;
if ( V_19 )
goto V_38;
F_21 ( 2 ) ;
V_19 = F_22 ( V_2 -> V_4 ) ;
if ( V_19 )
goto V_39;
return 0 ;
V_39:
F_23 () ;
V_38:
V_35:
V_34:
V_33:
F_24 () ;
V_26:
F_25 () ;
V_25:
F_26 ( V_22 . V_23 ) ;
V_24:
F_27 ( V_2 ) ;
V_21:
return V_19 ;
}
void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_4 ) ;
F_23 () ;
F_24 () ;
F_25 () ;
F_26 ( V_22 . V_23 ) ;
F_27 ( V_2 ) ;
}
int F_30 ( struct V_1 * V_2 )
{
F_31 ( L_5 ) ;
if ( V_22 . V_23 == NULL ) {
struct V_40 * V_41 ;
V_41 = F_32 () ;
if ( F_33 ( V_41 ) ) {
F_8 ( L_6 ) ;
return F_34 ( V_41 ) ;
}
V_22 . V_23 = V_41 ;
}
return 0 ;
}
int F_35 ( void )
{
return 0 ;
}
void F_36 ( void )
{
}
