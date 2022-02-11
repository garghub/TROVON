static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_9 && V_6 -> V_10 [ V_7 ] ; V_7 ++ ) {
V_8 = F_4 ( V_6 -> V_10 [ V_7 ] ) ;
if ( V_8 )
goto V_11;
}
if ( V_6 -> V_12 ) {
V_8 = F_5 ( V_6 -> V_12 ) ;
if ( V_8 )
goto V_11;
V_8 = F_6 ( V_6 -> V_12 ) ;
if ( V_8 )
goto V_13;
}
return 0 ;
V_13:
F_7 ( V_6 -> V_12 ) ;
V_11:
while ( -- V_7 >= 0 )
F_8 ( V_6 -> V_10 [ V_7 ] ) ;
return V_8 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
if ( V_6 -> V_12 ) {
F_10 ( V_6 -> V_12 ) ;
F_7 ( V_6 -> V_12 ) ;
}
for ( V_7 = V_9 - 1 ; V_7 >= 0 ; V_7 -- )
if ( V_6 -> V_10 [ V_7 ] )
F_8 ( V_6 -> V_10 [ V_7 ] ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_14 * V_15 ;
struct V_16 * V_17 = F_12 ( & V_2 -> V_2 ) ;
struct V_5 * V_6 ;
struct V_18 * V_19 ;
int V_20 , V_21 , V_7 = 0 ;
if ( F_13 () )
return - V_22 ;
if ( ! V_17 )
V_17 = & V_23 ;
V_20 = F_14 ( & V_2 -> V_2 , F_15 ( 32 ) ) ;
if ( V_20 )
return V_20 ;
V_21 = F_16 ( V_2 , 0 ) ;
if ( V_21 < 0 ) {
F_17 ( & V_2 -> V_2 , L_1 ) ;
return V_21 ;
}
V_4 = F_18 ( & V_24 , & V_2 -> V_2 ,
F_19 ( & V_2 -> V_2 ) ) ;
if ( ! V_4 )
return - V_25 ;
F_20 ( V_2 , V_4 ) ;
V_2 -> V_2 . V_26 = V_17 ;
V_6 = F_3 ( V_4 ) ;
V_19 = F_21 ( V_4 ) ;
if ( V_17 == & V_23 && V_2 -> V_2 . V_27 ) {
if ( F_22 ( V_2 -> V_2 . V_27 , L_2 ) )
V_19 -> V_28 |= V_29 ;
if ( F_22 ( V_2 -> V_2 . V_27 , L_3 ) )
V_19 -> V_28 |= V_30 ;
if ( F_22 ( V_2 -> V_2 . V_27 , L_4 ) )
V_19 -> V_28 |= V_29 | V_30 ;
if ( F_22 ( V_2 -> V_2 . V_27 , L_5 ) )
V_19 -> V_28 |= V_31 ;
F_23 ( V_2 -> V_2 . V_27 , L_6 ,
& V_19 -> V_32 ) ;
V_6 -> V_12 = F_24 ( & V_2 -> V_2 , L_7 ) ;
if ( F_25 ( V_6 -> V_12 ) ) {
V_20 = F_26 ( V_6 -> V_12 ) ;
if ( V_20 == - V_33 )
goto V_34;
V_6 -> V_12 = NULL ;
}
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
V_6 -> V_10 [ V_7 ] = F_27 ( V_2 -> V_2 . V_27 , V_7 ) ;
if ( F_25 ( V_6 -> V_10 [ V_7 ] ) ) {
V_20 = F_26 ( V_6 -> V_10 [ V_7 ] ) ;
if ( V_20 == - V_33 )
goto V_35;
V_6 -> V_10 [ V_7 ] = NULL ;
break;
}
}
}
V_6 -> V_36 = F_28 ( & V_2 -> V_2 , NULL ) ;
if ( F_25 ( V_6 -> V_36 ) ) {
V_20 = F_26 ( V_6 -> V_36 ) ;
if ( V_20 == - V_33 )
goto V_35;
V_6 -> V_36 = NULL ;
} else {
V_20 = F_29 ( V_6 -> V_36 ) ;
if ( V_20 )
goto V_35;
}
if ( V_17 -> V_37 )
V_19 -> V_28 |= V_30 ;
if ( V_17 -> V_38 )
V_19 -> V_28 |= V_29 ;
if ( V_17 -> V_39 )
V_19 -> V_28 |= V_31 ;
if ( V_17 -> V_32 )
V_19 -> V_32 = V_17 -> V_32 ;
#ifndef F_30
if ( V_19 -> V_28 & V_29 ) {
F_17 ( & V_2 -> V_2 ,
L_8 ) ;
V_20 = - V_40 ;
goto V_41;
}
#endif
#ifndef F_31
if ( V_19 -> V_28 & V_30 ) {
F_17 ( & V_2 -> V_2 ,
L_9 ) ;
V_20 = - V_40 ;
goto V_41;
}
#endif
if ( V_17 -> V_42 ) {
V_20 = V_17 -> V_42 ( V_2 ) ;
if ( V_20 < 0 )
goto V_41;
}
V_15 = F_32 ( V_2 , V_43 , 0 ) ;
V_4 -> V_44 = F_33 ( & V_2 -> V_2 , V_15 ) ;
if ( F_25 ( V_4 -> V_44 ) ) {
V_20 = F_26 ( V_4 -> V_44 ) ;
goto V_45;
}
V_4 -> V_46 = V_15 -> V_47 ;
V_4 -> V_48 = F_34 ( V_15 ) ;
V_20 = F_35 ( V_4 , V_21 , V_49 ) ;
if ( V_20 )
goto V_45;
F_36 ( V_4 -> V_50 . V_51 ) ;
F_20 ( V_2 , V_4 ) ;
return V_20 ;
V_45:
if ( V_17 -> V_52 )
V_17 -> V_52 ( V_2 ) ;
V_41:
if ( V_6 -> V_36 )
F_37 ( V_6 -> V_36 ) ;
V_35:
while ( -- V_7 >= 0 )
F_38 ( V_6 -> V_10 [ V_7 ] ) ;
V_34:
if ( V_17 == & V_23 )
V_2 -> V_2 . V_26 = NULL ;
F_39 ( V_4 ) ;
return V_20 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = F_12 ( & V_2 -> V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
F_41 ( V_4 ) ;
if ( V_17 -> V_52 )
V_17 -> V_52 ( V_2 ) ;
if ( V_6 -> V_36 )
F_37 ( V_6 -> V_36 ) ;
for ( V_7 = 0 ; V_7 < V_9 && V_6 -> V_10 [ V_7 ] ; V_7 ++ )
F_38 ( V_6 -> V_10 [ V_7 ] ) ;
F_39 ( V_4 ) ;
if ( V_17 == & V_23 )
V_2 -> V_2 . V_26 = NULL ;
return 0 ;
}
static int F_42 ( struct V_53 * V_2 )
{
struct V_3 * V_4 = F_43 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_26 ;
struct V_1 * V_54 =
F_44 ( V_2 , struct V_1 , V_2 ) ;
bool V_55 = F_45 ( V_2 ) ;
int V_8 ;
V_8 = F_46 ( V_4 , V_55 ) ;
if ( V_8 )
return V_8 ;
if ( V_17 -> V_56 )
V_17 -> V_56 ( V_54 ) ;
return V_8 ;
}
static int F_47 ( struct V_53 * V_2 )
{
struct V_3 * V_4 = F_43 ( V_2 ) ;
struct V_16 * V_17 = F_12 ( V_2 ) ;
struct V_1 * V_54 =
F_44 ( V_2 , struct V_1 , V_2 ) ;
if ( V_17 -> V_42 ) {
int V_20 = V_17 -> V_42 ( V_54 ) ;
if ( V_20 < 0 )
return V_20 ;
}
F_48 ( V_4 , false ) ;
return 0 ;
}
static int T_1 F_49 ( void )
{
if ( F_13 () )
return - V_22 ;
F_50 ( L_10 V_57 L_11 , V_58 ) ;
F_51 ( & V_24 , & V_59 ) ;
return F_52 ( & V_60 ) ;
}
static void T_2 F_53 ( void )
{
F_54 ( & V_60 ) ;
}
