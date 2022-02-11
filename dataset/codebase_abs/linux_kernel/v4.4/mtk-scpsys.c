static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_4 = F_2 ( V_3 -> V_5 + V_6 ) & V_2 -> V_7 ;
T_1 V_8 = F_2 ( V_3 -> V_5 + V_9 ) & V_2 -> V_7 ;
if ( V_4 && V_8 )
return true ;
if ( ! V_4 && ! V_8 )
return false ;
return - V_10 ;
}
static int F_3 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 , struct V_1 , V_12 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
unsigned long V_13 ;
bool V_14 ;
void T_2 * V_15 = V_2 -> V_15 ;
T_1 V_16 = V_2 -> V_17 ;
T_1 V_18 ;
int V_19 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 && V_2 -> V_22 [ V_20 ] ; V_20 ++ ) {
V_19 = F_5 ( V_2 -> V_22 [ V_20 ] ) ;
if ( V_19 ) {
for ( -- V_20 ; V_20 >= 0 ; V_20 -- )
F_6 ( V_2 -> V_22 [ V_20 ] ) ;
goto V_23;
}
}
V_18 = F_2 ( V_15 ) ;
V_18 |= V_24 ;
F_7 ( V_18 , V_15 ) ;
V_18 |= V_25 ;
F_7 ( V_18 , V_15 ) ;
V_13 = V_26 + V_27 ;
V_14 = false ;
while ( 1 ) {
V_19 = F_1 ( V_2 ) ;
if ( V_19 > 0 )
break;
if ( V_14 ) {
V_19 = - V_28 ;
goto V_29;
}
F_8 () ;
if ( F_9 ( V_26 , V_13 ) )
V_14 = true ;
}
V_18 &= ~ V_30 ;
F_7 ( V_18 , V_15 ) ;
V_18 &= ~ V_31 ;
F_7 ( V_18 , V_15 ) ;
V_18 |= V_32 ;
F_7 ( V_18 , V_15 ) ;
V_18 &= ~ V_2 -> V_33 ;
F_7 ( V_18 , V_15 ) ;
V_13 = V_26 + V_27 ;
V_14 = false ;
while ( V_16 && ( F_2 ( V_15 ) & V_16 ) ) {
if ( V_14 ) {
V_19 = - V_28 ;
goto V_29;
}
F_8 () ;
if ( F_9 ( V_26 , V_13 ) )
V_14 = true ;
}
if ( V_2 -> V_34 ) {
V_19 = F_10 ( V_3 -> V_35 ,
V_2 -> V_34 ) ;
if ( V_19 )
goto V_29;
}
return 0 ;
V_29:
for ( V_20 = V_21 - 1 ; V_20 >= 0 ; V_20 -- ) {
if ( V_2 -> V_22 [ V_20 ] )
F_6 ( V_2 -> V_22 [ V_20 ] ) ;
}
V_23:
F_11 ( V_3 -> V_36 , L_1 , V_12 -> V_37 ) ;
return V_19 ;
}
static int F_12 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 , struct V_1 , V_12 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
unsigned long V_13 ;
bool V_14 ;
void T_2 * V_15 = V_2 -> V_15 ;
T_1 V_38 = V_2 -> V_17 ;
T_1 V_18 ;
int V_19 ;
int V_20 ;
if ( V_2 -> V_34 ) {
V_19 = F_13 ( V_3 -> V_35 ,
V_2 -> V_34 ) ;
if ( V_19 )
goto V_39;
}
V_18 = F_2 ( V_15 ) ;
V_18 |= V_2 -> V_33 ;
F_7 ( V_18 , V_15 ) ;
V_13 = V_26 + V_27 ;
V_14 = false ;
while ( V_38 && ( F_2 ( V_15 ) & V_38 ) != V_38 ) {
if ( V_14 ) {
V_19 = - V_28 ;
goto V_39;
}
F_8 () ;
if ( F_9 ( V_26 , V_13 ) )
V_14 = true ;
}
V_18 |= V_31 ;
F_7 ( V_18 , V_15 ) ;
V_18 &= ~ V_32 ;
F_7 ( V_18 , V_15 ) ;
V_18 |= V_30 ;
F_7 ( V_18 , V_15 ) ;
V_18 &= ~ V_24 ;
F_7 ( V_18 , V_15 ) ;
V_18 &= ~ V_25 ;
F_7 ( V_18 , V_15 ) ;
V_13 = V_26 + V_27 ;
V_14 = false ;
while ( 1 ) {
V_19 = F_1 ( V_2 ) ;
if ( V_19 == 0 )
break;
if ( V_14 ) {
V_19 = - V_28 ;
goto V_39;
}
F_8 () ;
if ( F_9 ( V_26 , V_13 ) )
V_14 = true ;
}
for ( V_20 = 0 ; V_20 < V_21 && V_2 -> V_22 [ V_20 ] ; V_20 ++ )
F_6 ( V_2 -> V_22 [ V_20 ] ) ;
return 0 ;
V_39:
F_11 ( V_3 -> V_36 , L_2 , V_12 -> V_37 ) ;
return V_19 ;
}
static bool F_14 ( struct V_40 * V_36 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
V_12 = F_15 ( V_36 -> V_41 ) ;
V_2 = F_4 ( V_12 , struct V_1 , V_12 ) ;
return V_2 -> V_42 ;
}
static int T_3 F_16 ( struct V_43 * V_44 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
int V_20 , V_49 , V_19 ;
struct V_3 * V_3 ;
struct V_22 * V_22 [ V_50 ] ;
V_3 = F_17 ( & V_44 -> V_36 , sizeof( * V_3 ) , V_51 ) ;
if ( ! V_3 )
return - V_52 ;
V_3 -> V_36 = & V_44 -> V_36 ;
V_48 = F_18 ( V_44 , V_53 , 0 ) ;
V_3 -> V_5 = F_19 ( & V_44 -> V_36 , V_48 ) ;
if ( F_20 ( V_3 -> V_5 ) )
return F_21 ( V_3 -> V_5 ) ;
V_46 = & V_3 -> V_46 ;
V_46 -> V_54 = F_17 ( & V_44 -> V_36 ,
sizeof( * V_46 -> V_54 ) * V_55 , V_51 ) ;
if ( ! V_46 -> V_54 )
return - V_52 ;
V_22 [ V_56 ] = F_22 ( & V_44 -> V_36 , L_3 ) ;
if ( F_20 ( V_22 [ V_56 ] ) )
return F_21 ( V_22 [ V_56 ] ) ;
V_22 [ V_57 ] = F_22 ( & V_44 -> V_36 , L_4 ) ;
if ( F_20 ( V_22 [ V_57 ] ) )
return F_21 ( V_22 [ V_57 ] ) ;
V_22 [ V_58 ] = F_22 ( & V_44 -> V_36 , L_5 ) ;
if ( F_20 ( V_22 [ V_58 ] ) )
return F_21 ( V_22 [ V_58 ] ) ;
V_22 [ V_59 ] = F_22 ( & V_44 -> V_36 , L_6 ) ;
if ( F_20 ( V_22 [ V_59 ] ) )
return F_21 ( V_22 [ V_59 ] ) ;
V_3 -> V_35 = F_23 ( V_44 -> V_36 . V_60 ,
L_7 ) ;
if ( F_20 ( V_3 -> V_35 ) ) {
F_11 ( & V_44 -> V_36 , L_8 ,
F_21 ( V_3 -> V_35 ) ) ;
return F_21 ( V_3 -> V_35 ) ;
}
V_46 -> V_61 = V_55 ;
for ( V_20 = 0 ; V_20 < V_55 ; V_20 ++ ) {
struct V_1 * V_2 = & V_3 -> V_54 [ V_20 ] ;
struct V_11 * V_12 = & V_2 -> V_12 ;
const struct V_62 * V_63 = & V_62 [ V_20 ] ;
V_46 -> V_54 [ V_20 ] = V_12 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_7 = V_63 -> V_7 ;
V_2 -> V_15 = V_3 -> V_5 + V_63 -> V_64 ;
V_2 -> V_33 = V_63 -> V_33 ;
V_2 -> V_17 = V_63 -> V_17 ;
V_2 -> V_34 = V_63 -> V_34 ;
V_2 -> V_42 = V_63 -> V_42 ;
for ( V_49 = 0 ; V_49 < V_21 && V_63 -> V_65 [ V_49 ] ; V_49 ++ )
V_2 -> V_22 [ V_49 ] = V_22 [ V_63 -> V_65 [ V_49 ] ] ;
V_12 -> V_37 = V_63 -> V_37 ;
V_12 -> V_66 = F_12 ;
V_12 -> V_67 = F_3 ;
V_12 -> V_68 . V_42 = F_14 ;
V_12 -> V_67 ( V_12 ) ;
F_24 ( V_12 , NULL , false ) ;
}
V_19 = F_25 ( V_46 -> V_54 [ V_69 ] ,
V_46 -> V_54 [ V_70 ] ) ;
if ( V_19 && F_26 ( V_71 ) )
F_11 ( & V_44 -> V_36 , L_9 , V_19 ) ;
V_19 = F_25 ( V_46 -> V_54 [ V_70 ] ,
V_46 -> V_54 [ V_72 ] ) ;
if ( V_19 && F_26 ( V_71 ) )
F_11 ( & V_44 -> V_36 , L_9 , V_19 ) ;
V_19 = F_27 ( V_44 -> V_36 . V_60 , V_46 ) ;
if ( V_19 )
F_11 ( & V_44 -> V_36 , L_10 , V_19 ) ;
return 0 ;
}
