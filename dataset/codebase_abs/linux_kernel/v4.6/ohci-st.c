static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 , V_8 ;
V_8 = F_4 ( V_6 -> V_9 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_4 ( V_6 -> V_10 ) ;
if ( V_8 )
goto V_11;
if ( V_6 -> V_12 ) {
V_8 = F_5 ( V_6 -> V_12 , 48000000 ) ;
if ( V_8 )
goto V_13;
}
for ( V_7 = 0 ; V_7 < V_14 && V_6 -> V_15 [ V_7 ] ; V_7 ++ ) {
V_8 = F_6 ( V_6 -> V_15 [ V_7 ] ) ;
if ( V_8 )
goto V_16;
}
V_8 = F_7 ( V_6 -> V_17 ) ;
if ( V_8 )
goto V_16;
V_8 = F_8 ( V_6 -> V_17 ) ;
if ( V_8 )
goto V_18;
return 0 ;
V_18:
F_9 ( V_6 -> V_17 ) ;
V_16:
while ( -- V_7 >= 0 )
F_10 ( V_6 -> V_15 [ V_7 ] ) ;
V_13:
F_11 ( V_6 -> V_10 ) ;
V_11:
F_11 ( V_6 -> V_9 ) ;
return V_8 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
F_11 ( V_6 -> V_9 ) ;
F_11 ( V_6 -> V_10 ) ;
F_13 ( V_6 -> V_17 ) ;
F_9 ( V_6 -> V_17 ) ;
for ( V_7 = V_14 - 1 ; V_7 >= 0 ; V_7 -- )
if ( V_6 -> V_15 [ V_7 ] )
F_10 ( V_6 -> V_15 [ V_7 ] ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_19 * V_20 ;
struct V_21 * V_22 = & V_23 ;
struct V_5 * V_6 ;
struct V_24 * V_25 ;
int V_26 , V_27 , V_7 = 0 ;
if ( F_15 () )
return - V_28 ;
V_27 = F_16 ( V_2 , 0 ) ;
if ( V_27 < 0 ) {
F_17 ( & V_2 -> V_2 , L_1 ) ;
return V_27 ;
}
V_20 = F_18 ( V_2 , V_29 , 0 ) ;
if ( ! V_20 ) {
F_17 ( & V_2 -> V_2 , L_2 ) ;
return - V_30 ;
}
V_4 = F_19 ( & V_31 , & V_2 -> V_2 ,
F_20 ( & V_2 -> V_2 ) ) ;
if ( ! V_4 )
return - V_32 ;
F_21 ( V_2 , V_4 ) ;
V_2 -> V_2 . V_33 = V_22 ;
V_6 = F_3 ( V_4 ) ;
V_25 = F_22 ( V_4 ) ;
V_6 -> V_17 = F_23 ( & V_2 -> V_2 , L_3 ) ;
if ( F_24 ( V_6 -> V_17 ) ) {
V_26 = F_25 ( V_6 -> V_17 ) ;
goto V_34;
}
for ( V_7 = 0 ; V_7 < V_14 ; V_7 ++ ) {
V_6 -> V_15 [ V_7 ] = F_26 ( V_2 -> V_2 . V_35 , V_7 ) ;
if ( F_24 ( V_6 -> V_15 [ V_7 ] ) ) {
V_26 = F_25 ( V_6 -> V_15 [ V_7 ] ) ;
if ( V_26 == - V_36 )
goto V_37;
V_6 -> V_15 [ V_7 ] = NULL ;
break;
}
}
V_6 -> V_12 = F_27 ( & V_2 -> V_2 , L_4 ) ;
if ( F_24 ( V_6 -> V_12 ) ) {
F_28 ( & V_2 -> V_2 , L_5 ) ;
V_6 -> V_12 = NULL ;
}
V_6 -> V_9 = F_29 ( & V_2 -> V_2 , L_6 ) ;
if ( F_24 ( V_6 -> V_9 ) ) {
V_26 = F_25 ( V_6 -> V_9 ) ;
goto V_37;
}
V_6 -> V_10 = F_29 ( & V_2 -> V_2 , L_7 ) ;
if ( F_24 ( V_6 -> V_10 ) ) {
V_26 = F_25 ( V_6 -> V_10 ) ;
goto V_37;
}
if ( V_22 -> V_38 ) {
V_26 = V_22 -> V_38 ( V_2 ) ;
if ( V_26 < 0 )
goto V_39;
}
V_4 -> V_40 = V_20 -> V_41 ;
V_4 -> V_42 = F_30 ( V_20 ) ;
V_4 -> V_43 = F_31 ( & V_2 -> V_2 , V_20 ) ;
if ( F_24 ( V_4 -> V_43 ) ) {
V_26 = F_25 ( V_4 -> V_43 ) ;
goto V_39;
}
V_26 = F_32 ( V_4 , V_27 , V_44 ) ;
if ( V_26 )
goto V_39;
F_33 ( V_4 -> V_45 . V_46 ) ;
F_21 ( V_2 , V_4 ) ;
return V_26 ;
V_39:
if ( V_22 -> V_47 )
V_22 -> V_47 ( V_2 ) ;
V_37:
while ( -- V_7 >= 0 )
F_34 ( V_6 -> V_15 [ V_7 ] ) ;
V_34:
if ( V_22 == & V_23 )
V_2 -> V_2 . V_33 = NULL ;
F_35 ( V_4 ) ;
return V_26 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_21 * V_22 = F_37 ( & V_2 -> V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
F_38 ( V_4 ) ;
if ( V_22 -> V_47 )
V_22 -> V_47 ( V_2 ) ;
for ( V_7 = 0 ; V_7 < V_14 && V_6 -> V_15 [ V_7 ] ; V_7 ++ )
F_34 ( V_6 -> V_15 [ V_7 ] ) ;
F_35 ( V_4 ) ;
if ( V_22 == & V_23 )
V_2 -> V_2 . V_33 = NULL ;
return 0 ;
}
static int F_39 ( struct V_48 * V_2 )
{
struct V_3 * V_4 = F_40 ( V_2 ) ;
struct V_21 * V_22 = V_2 -> V_33 ;
struct V_1 * V_49 = F_41 ( V_2 ) ;
bool V_50 = F_42 ( V_2 ) ;
int V_8 ;
V_8 = F_43 ( V_4 , V_50 ) ;
if ( V_8 )
return V_8 ;
if ( V_22 -> V_51 )
V_22 -> V_51 ( V_49 ) ;
return V_8 ;
}
static int F_44 ( struct V_48 * V_2 )
{
struct V_3 * V_4 = F_40 ( V_2 ) ;
struct V_21 * V_22 = F_37 ( V_2 ) ;
struct V_1 * V_49 = F_41 ( V_2 ) ;
int V_26 ;
if ( V_22 -> V_38 ) {
V_26 = V_22 -> V_38 ( V_49 ) ;
if ( V_26 < 0 )
return V_26 ;
}
F_45 ( V_4 , false ) ;
return 0 ;
}
static int T_1 F_46 ( void )
{
if ( F_15 () )
return - V_28 ;
F_47 ( L_8 V_52 L_9 , V_53 ) ;
F_48 ( & V_31 , & V_54 ) ;
return F_49 ( & V_55 ) ;
}
static void T_2 F_50 ( void )
{
F_51 ( & V_55 ) ;
}
