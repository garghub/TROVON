static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
struct V_7 * V_8 = F_3 ( & V_4 -> V_9 ) ;
struct V_10 * V_11 = F_4 ( V_2 ) ;
if ( V_8 -> V_12 )
V_11 -> V_13 |= V_14 ;
if ( V_8 -> V_15 )
V_11 -> V_15 = V_8 -> V_15 ;
return F_5 ( V_2 ) ;
}
static int F_6 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_16 * V_17 = F_8 ( V_2 ) ;
int V_18 , V_19 ;
for ( V_18 = 0 ; V_18 < V_20 && V_17 -> V_21 [ V_18 ] ; V_18 ++ ) {
V_19 = F_9 ( V_17 -> V_21 [ V_18 ] ) ;
if ( V_19 )
goto V_22;
}
if ( V_17 -> V_23 ) {
V_19 = F_10 ( V_17 -> V_23 ) ;
if ( V_19 )
goto V_22;
V_19 = F_11 ( V_17 -> V_23 ) ;
if ( V_19 )
goto V_24;
}
return 0 ;
V_24:
F_12 ( V_17 -> V_23 ) ;
V_22:
while ( -- V_18 >= 0 )
F_13 ( V_17 -> V_21 [ V_18 ] ) ;
return V_19 ;
}
static void F_14 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_16 * V_17 = F_8 ( V_2 ) ;
int V_18 ;
if ( V_17 -> V_23 ) {
F_15 ( V_17 -> V_23 ) ;
F_12 ( V_17 -> V_23 ) ;
}
for ( V_18 = V_20 - 1 ; V_18 >= 0 ; V_18 -- )
if ( V_17 -> V_21 [ V_18 ] )
F_13 ( V_17 -> V_21 [ V_18 ] ) ;
}
static int F_16 ( struct V_3 * V_9 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
struct V_16 * V_17 ;
struct V_10 * V_11 ;
int V_27 , V_28 , V_18 = 0 ;
if ( F_17 () )
return - V_29 ;
if ( ! V_8 )
V_8 = & V_30 ;
V_27 = F_18 ( & V_9 -> V_9 , F_19 ( 32 ) ) ;
if ( V_27 )
return V_27 ;
V_28 = F_20 ( V_9 , 0 ) ;
if ( V_28 < 0 ) {
F_21 ( & V_9 -> V_9 , L_1 ) ;
return V_28 ;
}
V_26 = F_22 ( V_9 , V_31 , 0 ) ;
if ( ! V_26 ) {
F_21 ( & V_9 -> V_9 , L_2 ) ;
return - V_32 ;
}
V_2 = F_23 ( & V_33 , & V_9 -> V_9 ,
F_24 ( & V_9 -> V_9 ) ) ;
if ( ! V_2 )
return - V_34 ;
F_25 ( V_9 , V_2 ) ;
V_9 -> V_9 . V_35 = V_8 ;
V_17 = F_8 ( V_2 ) ;
V_11 = F_4 ( V_2 ) ;
if ( V_8 == & V_30 && V_9 -> V_9 . V_36 ) {
if ( F_26 ( V_9 -> V_9 . V_36 , L_3 ) )
V_11 -> V_13 |= V_37 ;
if ( F_26 ( V_9 -> V_9 . V_36 , L_4 ) )
V_11 -> V_13 |= V_38 ;
if ( F_26 ( V_9 -> V_9 . V_36 , L_5 ) )
V_11 -> V_13 |= V_37 | V_38 ;
V_17 -> V_23 = F_27 ( & V_9 -> V_9 , L_6 ) ;
if ( F_28 ( V_17 -> V_23 ) ) {
V_27 = F_29 ( V_17 -> V_23 ) ;
if ( V_27 == - V_39 )
goto V_40;
V_17 -> V_23 = NULL ;
}
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
V_17 -> V_21 [ V_18 ] = F_30 ( V_9 -> V_9 . V_36 , V_18 ) ;
if ( F_28 ( V_17 -> V_21 [ V_18 ] ) ) {
V_27 = F_29 ( V_17 -> V_21 [ V_18 ] ) ;
if ( V_27 == - V_39 )
goto V_41;
V_17 -> V_21 [ V_18 ] = NULL ;
break;
}
}
}
if ( V_8 -> V_42 )
V_11 -> V_13 |= V_38 ;
if ( V_8 -> V_43 )
V_11 -> V_13 |= V_37 ;
#ifndef F_31
if ( V_11 -> V_13 & V_37 ) {
F_21 ( & V_9 -> V_9 ,
L_7 ) ;
V_27 = - V_44 ;
goto V_41;
}
#endif
#ifndef F_32
if ( V_11 -> V_13 & V_38 ) {
F_21 ( & V_9 -> V_9 ,
L_8 ) ;
V_27 = - V_44 ;
goto V_41;
}
#endif
if ( V_8 -> V_45 ) {
V_27 = V_8 -> V_45 ( V_9 ) ;
if ( V_27 < 0 )
goto V_41;
}
V_2 -> V_46 = V_26 -> V_47 ;
V_2 -> V_48 = F_33 ( V_26 ) ;
V_2 -> V_49 = F_34 ( & V_9 -> V_9 , V_26 ) ;
if ( F_28 ( V_2 -> V_49 ) ) {
V_27 = F_29 ( V_2 -> V_49 ) ;
goto V_50;
}
V_27 = F_35 ( V_2 , V_28 , V_51 ) ;
if ( V_27 )
goto V_50;
F_36 ( V_2 -> V_5 . V_6 ) ;
F_25 ( V_9 , V_2 ) ;
return V_27 ;
V_50:
if ( V_8 -> V_52 )
V_8 -> V_52 ( V_9 ) ;
V_41:
while ( -- V_18 >= 0 )
F_37 ( V_17 -> V_21 [ V_18 ] ) ;
V_40:
if ( V_8 == & V_30 )
V_9 -> V_9 . V_35 = NULL ;
F_38 ( V_2 ) ;
return V_27 ;
}
static int F_39 ( struct V_3 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( & V_9 -> V_9 ) ;
struct V_16 * V_17 = F_8 ( V_2 ) ;
int V_18 ;
F_40 ( V_2 ) ;
if ( V_8 -> V_52 )
V_8 -> V_52 ( V_9 ) ;
for ( V_18 = 0 ; V_18 < V_20 && V_17 -> V_21 [ V_18 ] ; V_18 ++ )
F_37 ( V_17 -> V_21 [ V_18 ] ) ;
F_38 ( V_2 ) ;
if ( V_8 == & V_30 )
V_9 -> V_9 . V_35 = NULL ;
return 0 ;
}
static int F_41 ( struct V_53 * V_9 )
{
struct V_1 * V_2 = F_42 ( V_9 ) ;
struct V_7 * V_8 = V_9 -> V_35 ;
struct V_3 * V_4 =
F_43 ( V_9 , struct V_3 , V_9 ) ;
bool V_54 = F_44 ( V_9 ) ;
int V_19 ;
V_19 = F_45 ( V_2 , V_54 ) ;
if ( V_19 )
return V_19 ;
if ( V_8 -> V_55 )
V_8 -> V_55 ( V_4 ) ;
return V_19 ;
}
static int F_46 ( struct V_53 * V_9 )
{
struct V_1 * V_2 = F_42 ( V_9 ) ;
struct V_7 * V_8 = F_3 ( V_9 ) ;
struct V_3 * V_4 =
F_43 ( V_9 , struct V_3 , V_9 ) ;
if ( V_8 -> V_45 ) {
int V_27 = V_8 -> V_45 ( V_4 ) ;
if ( V_27 < 0 )
return V_27 ;
}
F_47 ( V_2 , false ) ;
return 0 ;
}
static int T_1 F_48 ( void )
{
if ( F_17 () )
return - V_29 ;
F_49 ( L_9 V_56 L_10 , V_57 ) ;
F_50 ( & V_33 , & V_58 ) ;
return F_51 ( & V_59 ) ;
}
static void T_2 F_52 ( void )
{
F_53 ( & V_59 ) ;
}
