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
if ( V_2 -> V_20 ) {
V_19 = F_5 ( V_2 -> V_20 ) ;
if ( V_19 )
goto V_21;
}
V_18 = F_2 ( V_15 ) ;
V_18 |= V_22 ;
F_6 ( V_18 , V_15 ) ;
V_18 |= V_23 ;
F_6 ( V_18 , V_15 ) ;
V_13 = V_24 + V_25 ;
V_14 = false ;
while ( 1 ) {
V_19 = F_1 ( V_2 ) ;
if ( V_19 > 0 )
break;
if ( V_14 ) {
V_19 = - V_26 ;
goto V_27;
}
F_7 () ;
if ( F_8 ( V_24 , V_13 ) )
V_14 = true ;
}
V_18 &= ~ V_28 ;
F_6 ( V_18 , V_15 ) ;
V_18 &= ~ V_29 ;
F_6 ( V_18 , V_15 ) ;
V_18 |= V_30 ;
F_6 ( V_18 , V_15 ) ;
V_18 &= ~ V_2 -> V_31 ;
F_6 ( V_18 , V_15 ) ;
V_13 = V_24 + V_25 ;
V_14 = false ;
while ( V_16 && ( F_2 ( V_15 ) & V_16 ) ) {
if ( V_14 ) {
V_19 = - V_26 ;
goto V_27;
}
F_7 () ;
if ( F_8 ( V_24 , V_13 ) )
V_14 = true ;
}
if ( V_2 -> V_32 ) {
V_19 = F_9 ( V_3 -> V_33 ,
V_2 -> V_32 ) ;
if ( V_19 )
goto V_27;
}
return 0 ;
V_27:
F_10 ( V_2 -> V_20 ) ;
V_21:
F_11 ( V_3 -> V_34 , L_1 , V_12 -> V_35 ) ;
return V_19 ;
}
static int F_12 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 , struct V_1 , V_12 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
unsigned long V_13 ;
bool V_14 ;
void T_2 * V_15 = V_2 -> V_15 ;
T_1 V_36 = V_2 -> V_17 ;
T_1 V_18 ;
int V_19 ;
if ( V_2 -> V_32 ) {
V_19 = F_13 ( V_3 -> V_33 ,
V_2 -> V_32 ) ;
if ( V_19 )
goto V_37;
}
V_18 = F_2 ( V_15 ) ;
V_18 |= V_2 -> V_31 ;
F_6 ( V_18 , V_15 ) ;
V_13 = V_24 + V_25 ;
V_14 = false ;
while ( V_36 && ( F_2 ( V_15 ) & V_36 ) != V_36 ) {
if ( V_14 ) {
V_19 = - V_26 ;
goto V_37;
}
F_7 () ;
if ( F_8 ( V_24 , V_13 ) )
V_14 = true ;
}
V_18 |= V_29 ;
F_6 ( V_18 , V_15 ) ;
V_18 &= ~ V_30 ;
F_6 ( V_18 , V_15 ) ;
V_18 |= V_28 ;
F_6 ( V_18 , V_15 ) ;
V_18 &= ~ V_22 ;
F_6 ( V_18 , V_15 ) ;
V_18 &= ~ V_23 ;
F_6 ( V_18 , V_15 ) ;
V_13 = V_24 + V_25 ;
V_14 = false ;
while ( 1 ) {
V_19 = F_1 ( V_2 ) ;
if ( V_19 == 0 )
break;
if ( V_14 ) {
V_19 = - V_26 ;
goto V_37;
}
F_7 () ;
if ( F_8 ( V_24 , V_13 ) )
V_14 = true ;
}
if ( V_2 -> V_20 )
F_10 ( V_2 -> V_20 ) ;
return 0 ;
V_37:
F_11 ( V_3 -> V_34 , L_2 , V_12 -> V_35 ) ;
return V_19 ;
}
static int T_3 F_14 ( struct V_38 * V_39 )
{
struct V_40 * V_41 ;
struct V_42 * V_43 ;
int V_44 , V_19 ;
struct V_3 * V_3 ;
struct V_20 * V_20 [ V_45 ] ;
V_3 = F_15 ( & V_39 -> V_34 , sizeof( * V_3 ) , V_46 ) ;
if ( ! V_3 )
return - V_47 ;
V_3 -> V_34 = & V_39 -> V_34 ;
V_43 = F_16 ( V_39 , V_48 , 0 ) ;
V_3 -> V_5 = F_17 ( & V_39 -> V_34 , V_43 ) ;
if ( F_18 ( V_3 -> V_5 ) )
return F_19 ( V_3 -> V_5 ) ;
V_41 = & V_3 -> V_41 ;
V_41 -> V_49 = F_15 ( & V_39 -> V_34 ,
sizeof( * V_41 -> V_49 ) * V_50 , V_46 ) ;
if ( ! V_41 -> V_49 )
return - V_47 ;
V_20 [ V_51 ] = F_20 ( & V_39 -> V_34 , L_3 ) ;
if ( F_18 ( V_20 [ V_51 ] ) )
return F_19 ( V_20 [ V_51 ] ) ;
V_20 [ V_52 ] = F_20 ( & V_39 -> V_34 , L_4 ) ;
if ( F_18 ( V_20 [ V_52 ] ) )
return F_19 ( V_20 [ V_52 ] ) ;
V_3 -> V_33 = F_21 ( V_39 -> V_34 . V_53 ,
L_5 ) ;
if ( F_18 ( V_3 -> V_33 ) ) {
F_11 ( & V_39 -> V_34 , L_6 ,
F_19 ( V_3 -> V_33 ) ) ;
return F_19 ( V_3 -> V_33 ) ;
}
V_41 -> V_54 = V_50 ;
for ( V_44 = 0 ; V_44 < V_50 ; V_44 ++ ) {
struct V_1 * V_2 = & V_3 -> V_49 [ V_44 ] ;
struct V_11 * V_12 = & V_2 -> V_12 ;
const struct V_55 * V_56 = & V_55 [ V_44 ] ;
V_41 -> V_49 [ V_44 ] = V_12 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_7 = V_56 -> V_7 ;
V_2 -> V_15 = V_3 -> V_5 + V_56 -> V_57 ;
V_2 -> V_31 = V_56 -> V_31 ;
V_2 -> V_17 = V_56 -> V_17 ;
V_2 -> V_32 = V_56 -> V_32 ;
if ( V_56 -> V_58 != V_59 )
V_2 -> V_20 = V_20 [ V_56 -> V_58 ] ;
V_12 -> V_35 = V_56 -> V_35 ;
V_12 -> V_60 = F_12 ;
V_12 -> V_61 = F_3 ;
V_12 -> V_61 ( V_12 ) ;
F_22 ( V_12 , NULL , false ) ;
}
V_19 = F_23 ( V_41 -> V_49 [ V_62 ] ,
V_41 -> V_49 [ V_63 ] ) ;
if ( V_19 && F_24 ( V_64 ) )
F_11 ( & V_39 -> V_34 , L_7 , V_19 ) ;
V_19 = F_23 ( V_41 -> V_49 [ V_63 ] ,
V_41 -> V_49 [ V_65 ] ) ;
if ( V_19 && F_24 ( V_64 ) )
F_11 ( & V_39 -> V_34 , L_7 , V_19 ) ;
V_19 = F_25 ( V_39 -> V_34 . V_53 , V_41 ) ;
if ( V_19 )
F_11 ( & V_39 -> V_34 , L_8 , V_19 ) ;
return 0 ;
}
