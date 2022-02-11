static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 * V_8 = F_3 ( & V_4 -> V_9 ) ;
struct V_10 * V_11 = F_4 ( V_2 ) ;
T_1 V_12 ;
V_12 = 128 | ( 128 << 16 ) ;
F_5 ( V_12 , V_2 -> V_13 + V_14 ) ;
V_11 -> V_15 = V_2 -> V_13 + V_8 -> V_16 ;
return F_6 ( V_2 ) ;
}
static int F_7 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_17 * V_18 = F_9 ( V_2 ) ;
int V_19 , V_20 ;
V_20 = F_10 ( V_18 -> V_21 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_10 ( V_18 -> V_22 ) ;
if ( V_20 )
goto V_23;
if ( V_18 -> V_24 ) {
V_20 = F_11 ( V_18 -> V_24 , 48000000 ) ;
if ( V_20 )
goto V_25;
}
for ( V_19 = 0 ; V_19 < V_26 && V_18 -> V_27 [ V_19 ] ; V_19 ++ ) {
V_20 = F_12 ( V_18 -> V_27 [ V_19 ] ) ;
if ( V_20 )
goto V_28;
}
V_20 = F_13 ( V_18 -> V_29 ) ;
if ( V_20 )
goto V_28;
V_20 = F_14 ( V_18 -> V_29 ) ;
if ( V_20 )
goto V_30;
return 0 ;
V_30:
F_15 ( V_18 -> V_29 ) ;
V_28:
while ( -- V_19 >= 0 )
F_16 ( V_18 -> V_27 [ V_19 ] ) ;
V_25:
F_17 ( V_18 -> V_22 ) ;
V_23:
F_17 ( V_18 -> V_21 ) ;
return V_20 ;
}
static void F_18 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_17 * V_18 = F_9 ( V_2 ) ;
int V_19 ;
F_17 ( V_18 -> V_21 ) ;
F_17 ( V_18 -> V_22 ) ;
F_19 ( V_18 -> V_29 ) ;
F_15 ( V_18 -> V_29 ) ;
for ( V_19 = V_26 - 1 ; V_19 >= 0 ; V_19 -- )
if ( V_18 -> V_27 [ V_19 ] )
F_16 ( V_18 -> V_27 [ V_19 ] ) ;
}
static int F_20 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_31 * V_32 ;
struct V_7 * V_8 = & V_33 ;
struct V_17 * V_18 ;
struct V_10 * V_11 ;
int V_34 , V_35 , V_19 = 0 ;
if ( F_21 () )
return - V_36 ;
V_35 = F_22 ( V_9 , 0 ) ;
if ( V_35 < 0 ) {
F_23 ( & V_9 -> V_9 , L_1 ) ;
return V_35 ;
}
V_32 = F_24 ( V_9 , V_37 , 0 ) ;
if ( ! V_32 ) {
F_23 ( & V_9 -> V_9 , L_2 ) ;
return - V_38 ;
}
V_2 = F_25 ( & V_39 , & V_9 -> V_9 ,
F_26 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 )
return - V_40 ;
F_27 ( V_9 , V_2 ) ;
V_9 -> V_9 . V_41 = V_8 ;
V_18 = F_9 ( V_2 ) ;
V_11 = F_4 ( V_2 ) ;
V_18 -> V_29 = F_28 ( & V_9 -> V_9 , L_3 ) ;
if ( F_29 ( V_18 -> V_29 ) ) {
V_34 = F_30 ( V_18 -> V_29 ) ;
goto V_42;
}
for ( V_19 = 0 ; V_19 < V_26 ; V_19 ++ ) {
V_18 -> V_27 [ V_19 ] = F_31 ( V_9 -> V_9 . V_43 , V_19 ) ;
if ( F_29 ( V_18 -> V_27 [ V_19 ] ) ) {
V_34 = F_30 ( V_18 -> V_27 [ V_19 ] ) ;
if ( V_34 == - V_44 )
goto V_45;
V_18 -> V_27 [ V_19 ] = NULL ;
break;
}
}
V_18 -> V_24 = F_32 ( & V_9 -> V_9 , L_4 ) ;
if ( F_29 ( V_18 -> V_24 ) ) {
F_33 ( & V_9 -> V_9 , L_5 ) ;
V_18 -> V_24 = NULL ;
}
V_18 -> V_21 = F_34 ( & V_9 -> V_9 , L_6 ) ;
if ( F_29 ( V_18 -> V_21 ) ) {
V_34 = F_30 ( V_18 -> V_21 ) ;
if ( V_34 == - V_44 )
goto V_45;
V_18 -> V_21 = NULL ;
}
V_18 -> V_22 = F_34 ( & V_9 -> V_9 , L_7 ) ;
if ( F_29 ( V_18 -> V_22 ) ) {
V_34 = F_30 ( V_18 -> V_22 ) ;
if ( V_34 == - V_44 )
goto V_45;
V_18 -> V_22 = NULL ;
}
if ( V_8 -> V_46 ) {
V_34 = V_8 -> V_46 ( V_9 ) ;
if ( V_34 < 0 )
goto V_45;
}
V_2 -> V_47 = V_32 -> V_48 ;
V_2 -> V_49 = F_35 ( V_32 ) ;
V_2 -> V_13 = F_36 ( & V_9 -> V_9 , V_32 ) ;
if ( F_29 ( V_2 -> V_13 ) ) {
V_34 = F_30 ( V_2 -> V_13 ) ;
goto V_45;
}
V_34 = F_37 ( V_2 , V_35 , V_50 ) ;
if ( V_34 )
goto V_45;
F_38 ( V_2 -> V_5 . V_6 ) ;
F_27 ( V_9 , V_2 ) ;
return V_34 ;
V_45:
while ( -- V_19 >= 0 )
F_39 ( V_18 -> V_27 [ V_19 ] ) ;
V_42:
if ( V_8 == & V_33 )
V_9 -> V_9 . V_41 = NULL ;
F_40 ( V_2 ) ;
return V_34 ;
}
static int F_41 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
struct V_17 * V_18 = F_9 ( V_2 ) ;
int V_19 ;
F_42 ( V_2 ) ;
if ( V_8 -> V_51 )
V_8 -> V_51 ( V_9 ) ;
for ( V_19 = 0 ; V_19 < V_26 && V_18 -> V_27 [ V_19 ] ; V_19 ++ )
F_39 ( V_18 -> V_27 [ V_19 ] ) ;
F_40 ( V_2 ) ;
if ( V_8 == & V_33 )
V_9 -> V_9 . V_41 = NULL ;
return 0 ;
}
static int F_43 ( struct V_52 * V_9 )
{
struct V_1 * V_2 = F_44 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 = F_2 ( V_9 ) ;
bool V_53 = F_45 ( V_9 ) ;
int V_20 ;
V_20 = F_46 ( V_2 , V_53 ) ;
if ( V_20 )
return V_20 ;
if ( V_8 -> V_54 )
V_8 -> V_54 ( V_4 ) ;
F_47 ( V_9 ) ;
return V_20 ;
}
static int F_48 ( struct V_52 * V_9 )
{
struct V_1 * V_2 = F_44 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 = F_2 ( V_9 ) ;
int V_34 ;
F_49 ( V_9 ) ;
if ( V_8 -> V_46 ) {
V_34 = V_8 -> V_46 ( V_4 ) ;
if ( V_34 < 0 )
return V_34 ;
}
F_50 ( V_2 , false ) ;
return 0 ;
}
static int T_2 F_51 ( void )
{
if ( F_21 () )
return - V_36 ;
F_52 ( L_8 V_55 L_9 , V_56 ) ;
F_53 ( & V_39 , & V_57 ) ;
return F_54 ( & V_58 ) ;
}
static void T_3 F_55 ( void )
{
F_56 ( & V_58 ) ;
}
