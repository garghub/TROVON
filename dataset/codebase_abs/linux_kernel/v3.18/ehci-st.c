static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 * V_8 = F_3 ( & V_4 -> V_9 ) ;
struct V_10 * V_11 = F_4 ( V_2 ) ;
int V_12 ;
T_1 V_13 ;
V_13 = 128 | ( 128 << 16 ) ;
F_5 ( V_13 , V_2 -> V_14 + V_15 ) ;
V_11 -> V_16 = V_2 -> V_14 + V_8 -> V_17 ;
V_12 = F_6 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static int F_7 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
int V_20 , V_21 ;
V_21 = F_10 ( V_19 -> V_22 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_10 ( V_19 -> V_23 ) ;
if ( V_21 )
goto V_24;
if ( V_19 -> V_25 ) {
V_21 = F_11 ( V_19 -> V_25 , 48000000 ) ;
if ( V_21 )
goto V_26;
}
for ( V_20 = 0 ; V_20 < V_27 && V_19 -> V_28 [ V_20 ] ; V_20 ++ ) {
V_21 = F_12 ( V_19 -> V_28 [ V_20 ] ) ;
if ( V_21 )
goto V_29;
}
V_21 = F_13 ( V_19 -> V_30 ) ;
if ( V_21 )
goto V_29;
V_21 = F_14 ( V_19 -> V_30 ) ;
if ( V_21 )
goto V_31;
return 0 ;
V_31:
F_15 ( V_19 -> V_30 ) ;
V_29:
while ( -- V_20 >= 0 )
F_16 ( V_19 -> V_28 [ V_20 ] ) ;
V_26:
F_17 ( V_19 -> V_23 ) ;
V_24:
F_17 ( V_19 -> V_22 ) ;
return V_21 ;
}
static void F_18 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
int V_20 ;
F_17 ( V_19 -> V_22 ) ;
F_17 ( V_19 -> V_23 ) ;
F_19 ( V_19 -> V_30 ) ;
F_15 ( V_19 -> V_30 ) ;
for ( V_20 = V_27 - 1 ; V_20 >= 0 ; V_20 -- )
if ( V_19 -> V_28 [ V_20 ] )
F_16 ( V_19 -> V_28 [ V_20 ] ) ;
}
static int F_20 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
struct V_7 * V_8 = & V_34 ;
struct V_18 * V_19 ;
struct V_10 * V_11 ;
int V_35 , V_36 , V_20 = 0 ;
if ( F_21 () )
return - V_37 ;
V_36 = F_22 ( V_9 , 0 ) ;
if ( V_36 < 0 ) {
F_23 ( & V_9 -> V_9 , L_1 ) ;
return V_36 ;
}
V_33 = F_24 ( V_9 , V_38 , 0 ) ;
if ( ! V_33 ) {
F_23 ( & V_9 -> V_9 , L_2 ) ;
return - V_39 ;
}
V_2 = F_25 ( & V_40 , & V_9 -> V_9 ,
F_26 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 )
return - V_41 ;
F_27 ( V_9 , V_2 ) ;
V_9 -> V_9 . V_42 = V_8 ;
V_19 = F_9 ( V_2 ) ;
V_11 = F_4 ( V_2 ) ;
V_19 -> V_30 = F_28 ( & V_9 -> V_9 , L_3 ) ;
if ( F_29 ( V_19 -> V_30 ) ) {
V_35 = F_30 ( V_19 -> V_30 ) ;
goto V_43;
}
for ( V_20 = 0 ; V_20 < V_27 ; V_20 ++ ) {
V_19 -> V_28 [ V_20 ] = F_31 ( V_9 -> V_9 . V_44 , V_20 ) ;
if ( F_29 ( V_19 -> V_28 [ V_20 ] ) ) {
V_35 = F_30 ( V_19 -> V_28 [ V_20 ] ) ;
if ( V_35 == - V_45 )
goto V_46;
V_19 -> V_28 [ V_20 ] = NULL ;
break;
}
}
V_19 -> V_25 = F_32 ( & V_9 -> V_9 , L_4 ) ;
if ( F_29 ( V_19 -> V_25 ) ) {
F_33 ( & V_9 -> V_9 , L_5 ) ;
V_19 -> V_25 = NULL ;
}
V_19 -> V_22 = F_34 ( & V_9 -> V_9 , L_6 ) ;
if ( F_29 ( V_19 -> V_22 ) ) {
V_35 = F_30 ( V_19 -> V_22 ) ;
if ( V_35 == - V_45 )
goto V_46;
V_19 -> V_22 = NULL ;
}
V_19 -> V_23 = F_34 ( & V_9 -> V_9 , L_7 ) ;
if ( F_29 ( V_19 -> V_23 ) ) {
V_35 = F_30 ( V_19 -> V_23 ) ;
if ( V_35 == - V_45 )
goto V_46;
V_19 -> V_23 = NULL ;
}
if ( V_8 -> V_47 ) {
V_35 = V_8 -> V_47 ( V_9 ) ;
if ( V_35 < 0 )
goto V_46;
}
V_2 -> V_48 = V_33 -> V_49 ;
V_2 -> V_50 = F_35 ( V_33 ) ;
V_2 -> V_14 = F_36 ( & V_9 -> V_9 , V_33 ) ;
if ( F_29 ( V_2 -> V_14 ) ) {
V_35 = F_30 ( V_2 -> V_14 ) ;
goto V_46;
}
V_35 = F_37 ( V_2 , V_36 , V_51 ) ;
if ( V_35 )
goto V_46;
F_38 ( V_2 -> V_5 . V_6 ) ;
F_27 ( V_9 , V_2 ) ;
return V_35 ;
V_46:
while ( -- V_20 >= 0 )
F_39 ( V_19 -> V_28 [ V_20 ] ) ;
V_43:
if ( V_8 == & V_34 )
V_9 -> V_9 . V_42 = NULL ;
F_40 ( V_2 ) ;
return V_35 ;
}
static int F_41 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
struct V_18 * V_19 = F_9 ( V_2 ) ;
int V_20 ;
F_42 ( V_2 ) ;
if ( V_8 -> V_52 )
V_8 -> V_52 ( V_9 ) ;
for ( V_20 = 0 ; V_20 < V_27 && V_19 -> V_28 [ V_20 ] ; V_20 ++ )
F_39 ( V_19 -> V_28 [ V_20 ] ) ;
F_40 ( V_2 ) ;
if ( V_8 == & V_34 )
V_9 -> V_9 . V_42 = NULL ;
return 0 ;
}
static int F_43 ( struct V_53 * V_9 )
{
struct V_1 * V_2 = F_44 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_45 ( V_9 , struct V_3 , V_9 ) ;
bool V_54 = F_46 ( V_9 ) ;
int V_21 ;
V_21 = F_47 ( V_2 , V_54 ) ;
if ( V_21 )
return V_21 ;
if ( V_8 -> V_55 )
V_8 -> V_55 ( V_4 ) ;
F_48 ( V_9 ) ;
return V_21 ;
}
static int F_49 ( struct V_53 * V_9 )
{
struct V_1 * V_2 = F_44 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_45 ( V_9 , struct V_3 , V_9 ) ;
int V_35 ;
F_50 ( V_9 ) ;
if ( V_8 -> V_47 ) {
V_35 = V_8 -> V_47 ( V_4 ) ;
if ( V_35 < 0 )
return V_35 ;
}
F_51 ( V_2 , false ) ;
return 0 ;
}
static int T_2 F_52 ( void )
{
if ( F_21 () )
return - V_37 ;
F_53 ( L_8 V_56 L_9 , V_57 ) ;
F_54 ( & V_40 , & V_58 ) ;
return F_55 ( & V_59 ) ;
}
static void T_3 F_56 ( void )
{
F_57 ( & V_59 ) ;
}
