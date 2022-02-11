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
F_1 ( V_2 ) ;
V_2 -> V_9 . V_26 |= V_27 | V_28 ;
F_12 ( V_2 -> V_4 -> V_5 , V_2 -> V_9 . V_26 ,
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
F_14 ( L_3
L_4 ,
V_8 -> V_31 , V_18 ) ;
V_8 -> V_31 = V_18 ;
}
F_15 ( V_2 -> V_4 , V_8 ) ;
V_19 = F_16 ( & V_12 ) ;
if ( V_19 )
goto V_33;
V_19 = F_17 ( V_2 -> V_4 -> V_5 , & V_14 ) ;
if ( V_19 )
goto V_34;
F_18 ( V_2 -> V_35 . V_22 . V_36 ) ;
V_19 = F_19 () ;
if ( V_19 )
goto V_37;
F_20 ( 2 ) ;
V_19 = F_21 ( V_2 -> V_4 ) ;
if ( V_19 )
goto V_38;
return 0 ;
V_38:
F_22 () ;
V_37:
V_34:
V_33:
V_32:
F_23 () ;
V_25:
F_24 ( V_22 . V_23 ) ;
V_24:
F_25 ( V_2 ) ;
V_21:
return V_19 ;
}
void F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 -> V_4 ) ;
F_22 () ;
F_23 () ;
F_24 ( V_22 . V_23 ) ;
F_25 ( V_2 ) ;
}
static int T_2 F_28 ( struct V_1 * V_2 )
{
F_29 ( L_5 ) ;
if ( V_22 . V_23 == NULL ) {
struct V_39 * V_40 ;
V_40 = F_30 () ;
if ( F_31 ( V_40 ) ) {
F_8 ( L_6 ) ;
return F_32 ( V_40 ) ;
}
V_22 . V_23 = V_40 ;
}
return 0 ;
}
static void T_2 F_33 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_45 . V_46 ;
int V_47 , V_19 ;
for ( V_47 = 0 ; V_47 < V_44 -> V_48 ; ++ V_47 ) {
struct V_1 * V_2 = V_44 -> V_49 [ V_47 ] ;
if ( V_2 -> type != V_50 )
continue;
V_19 = F_28 ( V_2 ) ;
if ( V_19 ) {
F_8 ( L_7 , V_2 -> V_51 , V_19 ) ;
continue;
}
V_19 = F_34 ( V_2 , & V_42 -> V_45 , V_47 ) ;
if ( V_19 )
F_8 ( L_8 ,
V_2 -> V_51 , V_19 ) ;
}
}
static int T_2 F_35 ( struct V_41 * V_42 )
{
F_33 ( V_42 ) ;
return 0 ;
}
static int T_3 F_36 ( struct V_41 * V_42 )
{
F_37 ( & V_42 -> V_45 ) ;
return 0 ;
}
int T_2 F_38 ( void )
{
return F_39 ( & V_52 , F_35 ) ;
}
void T_3 F_40 ( void )
{
F_41 ( & V_52 ) ;
}
