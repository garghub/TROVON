static void F_1 ( struct V_1 * V_2 )
{
V_3 . V_4 . V_5 = V_6 ;
V_3 . V_4 . V_7 = false ;
V_3 . V_4 . V_8 = false ;
V_3 . V_4 . V_9 = 24 ;
V_3 . V_4 . V_10 = 1 ;
F_2 ( V_2 -> V_11 , & V_3 . V_4 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = & V_2 -> V_14 . V_15 ;
struct V_16 V_17 ;
struct V_18 V_19 ;
unsigned long V_20 ;
int V_21 ;
if ( V_2 -> V_11 == NULL ) {
F_4 ( L_1 ) ;
return - V_22 ;
}
V_21 = F_5 ( V_2 ) ;
if ( V_21 ) {
F_4 ( L_2 ) ;
goto V_23;
}
V_21 = F_6 ( V_3 . V_24 ) ;
if ( V_21 )
goto V_25;
V_21 = F_7 () ;
if ( V_21 )
goto V_26;
V_2 -> V_14 . V_15 . V_27 = V_28 ;
V_2 -> V_14 . V_15 . V_29 = V_28 ;
V_21 = F_8 ( V_13 -> V_30 * 1000 , & V_17 , & V_19 ) ;
if ( V_21 )
goto V_31;
V_3 . V_4 . V_32 = V_19 ;
V_20 = V_17 . V_33 / V_19 . V_34 / V_19 . V_35 / 1000 ;
if ( V_20 != V_13 -> V_30 ) {
F_9 ( L_3
L_4 ,
V_13 -> V_30 , V_20 ) ;
V_13 -> V_30 = V_20 ;
}
F_10 ( V_2 -> V_11 , V_13 ) ;
V_21 = F_11 ( & V_17 ) ;
if ( V_21 )
goto V_36;
F_1 ( V_2 ) ;
F_12 ( V_2 -> V_11 -> V_37 ,
& V_3 . V_4 . V_32 ) ;
F_13 ( V_2 -> V_38 . V_3 . V_39 ) ;
V_21 = F_14 () ;
if ( V_21 )
goto V_40;
F_15 ( 2 ) ;
V_21 = F_16 ( V_2 -> V_11 ) ;
if ( V_21 )
goto V_41;
return 0 ;
V_41:
F_17 () ;
V_40:
V_36:
V_31:
F_18 () ;
V_26:
F_19 ( V_3 . V_24 ) ;
V_25:
F_20 ( V_2 ) ;
V_23:
return V_21 ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_11 ) ;
F_17 () ;
F_18 () ;
F_19 ( V_3 . V_24 ) ;
F_20 ( V_2 ) ;
}
static int T_1 F_23 ( struct V_1 * V_2 )
{
F_24 ( L_5 ) ;
if ( V_3 . V_24 == NULL ) {
struct V_42 * V_43 ;
V_43 = F_25 () ;
if ( F_26 ( V_43 ) ) {
F_4 ( L_6 ) ;
return F_27 ( V_43 ) ;
}
V_3 . V_24 = V_43 ;
}
return 0 ;
}
static void T_1 F_28 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = V_45 -> V_48 . V_49 ;
int V_50 , V_21 ;
for ( V_50 = 0 ; V_50 < V_47 -> V_51 ; ++ V_50 ) {
struct V_1 * V_2 = V_47 -> V_52 [ V_50 ] ;
if ( V_2 -> type != V_53 )
continue;
V_21 = F_23 ( V_2 ) ;
if ( V_21 ) {
F_4 ( L_7 , V_2 -> V_54 , V_21 ) ;
continue;
}
V_21 = F_29 ( V_2 , & V_45 -> V_48 , V_50 ) ;
if ( V_21 )
F_4 ( L_8 ,
V_2 -> V_54 , V_21 ) ;
}
}
static int T_1 F_30 ( struct V_44 * V_45 )
{
F_28 ( V_45 ) ;
return 0 ;
}
static int T_2 F_31 ( struct V_44 * V_45 )
{
F_32 ( & V_45 -> V_48 ) ;
return 0 ;
}
int T_1 F_33 ( void )
{
return F_34 ( & V_55 , F_30 ) ;
}
void T_2 F_35 ( void )
{
F_36 ( & V_55 ) ;
}
