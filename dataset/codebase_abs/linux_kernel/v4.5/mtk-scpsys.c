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
if ( V_2 -> V_21 ) {
V_19 = F_5 ( V_2 -> V_21 ) ;
if ( V_19 )
return V_19 ;
}
for ( V_20 = 0 ; V_20 < V_22 && V_2 -> V_23 [ V_20 ] ; V_20 ++ ) {
V_19 = F_6 ( V_2 -> V_23 [ V_20 ] ) ;
if ( V_19 ) {
for ( -- V_20 ; V_20 >= 0 ; V_20 -- )
F_7 ( V_2 -> V_23 [ V_20 ] ) ;
goto V_24;
}
}
V_18 = F_2 ( V_15 ) ;
V_18 |= V_25 ;
F_8 ( V_18 , V_15 ) ;
V_18 |= V_26 ;
F_8 ( V_18 , V_15 ) ;
V_13 = V_27 + V_28 ;
V_14 = false ;
while ( 1 ) {
V_19 = F_1 ( V_2 ) ;
if ( V_19 > 0 )
break;
if ( V_14 ) {
V_19 = - V_29 ;
goto V_30;
}
F_9 () ;
if ( F_10 ( V_27 , V_13 ) )
V_14 = true ;
}
V_18 &= ~ V_31 ;
F_8 ( V_18 , V_15 ) ;
V_18 &= ~ V_32 ;
F_8 ( V_18 , V_15 ) ;
V_18 |= V_33 ;
F_8 ( V_18 , V_15 ) ;
V_18 &= ~ V_2 -> V_34 ;
F_8 ( V_18 , V_15 ) ;
V_13 = V_27 + V_28 ;
V_14 = false ;
while ( V_16 && ( F_2 ( V_15 ) & V_16 ) ) {
if ( V_14 ) {
V_19 = - V_29 ;
goto V_30;
}
F_9 () ;
if ( F_10 ( V_27 , V_13 ) )
V_14 = true ;
}
if ( V_2 -> V_35 ) {
V_19 = F_11 ( V_3 -> V_36 ,
V_2 -> V_35 ) ;
if ( V_19 )
goto V_30;
}
return 0 ;
V_30:
for ( V_20 = V_22 - 1 ; V_20 >= 0 ; V_20 -- ) {
if ( V_2 -> V_23 [ V_20 ] )
F_7 ( V_2 -> V_23 [ V_20 ] ) ;
}
V_24:
if ( V_2 -> V_21 )
F_12 ( V_2 -> V_21 ) ;
F_13 ( V_3 -> V_37 , L_1 , V_12 -> V_38 ) ;
return V_19 ;
}
static int F_14 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 , struct V_1 , V_12 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
unsigned long V_13 ;
bool V_14 ;
void T_2 * V_15 = V_2 -> V_15 ;
T_1 V_39 = V_2 -> V_17 ;
T_1 V_18 ;
int V_19 ;
int V_20 ;
if ( V_2 -> V_35 ) {
V_19 = F_15 ( V_3 -> V_36 ,
V_2 -> V_35 ) ;
if ( V_19 )
goto V_40;
}
V_18 = F_2 ( V_15 ) ;
V_18 |= V_2 -> V_34 ;
F_8 ( V_18 , V_15 ) ;
V_13 = V_27 + V_28 ;
V_14 = false ;
while ( V_39 && ( F_2 ( V_15 ) & V_39 ) != V_39 ) {
if ( V_14 ) {
V_19 = - V_29 ;
goto V_40;
}
F_9 () ;
if ( F_10 ( V_27 , V_13 ) )
V_14 = true ;
}
V_18 |= V_32 ;
F_8 ( V_18 , V_15 ) ;
V_18 &= ~ V_33 ;
F_8 ( V_18 , V_15 ) ;
V_18 |= V_31 ;
F_8 ( V_18 , V_15 ) ;
V_18 &= ~ V_25 ;
F_8 ( V_18 , V_15 ) ;
V_18 &= ~ V_26 ;
F_8 ( V_18 , V_15 ) ;
V_13 = V_27 + V_28 ;
V_14 = false ;
while ( 1 ) {
V_19 = F_1 ( V_2 ) ;
if ( V_19 == 0 )
break;
if ( V_14 ) {
V_19 = - V_29 ;
goto V_40;
}
F_9 () ;
if ( F_10 ( V_27 , V_13 ) )
V_14 = true ;
}
for ( V_20 = 0 ; V_20 < V_22 && V_2 -> V_23 [ V_20 ] ; V_20 ++ )
F_7 ( V_2 -> V_23 [ V_20 ] ) ;
if ( V_2 -> V_21 )
F_12 ( V_2 -> V_21 ) ;
return 0 ;
V_40:
F_13 ( V_3 -> V_37 , L_2 , V_12 -> V_38 ) ;
return V_19 ;
}
static bool F_16 ( struct V_41 * V_37 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
V_12 = F_17 ( V_37 -> V_42 ) ;
V_2 = F_4 ( V_12 , struct V_1 , V_12 ) ;
return V_2 -> V_43 ;
}
static int T_3 F_18 ( struct V_44 * V_45 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
int V_20 , V_50 , V_19 ;
struct V_3 * V_3 ;
struct V_23 * V_23 [ V_51 ] ;
V_3 = F_19 ( & V_45 -> V_37 , sizeof( * V_3 ) , V_52 ) ;
if ( ! V_3 )
return - V_53 ;
V_3 -> V_37 = & V_45 -> V_37 ;
V_49 = F_20 ( V_45 , V_54 , 0 ) ;
V_3 -> V_5 = F_21 ( & V_45 -> V_37 , V_49 ) ;
if ( F_22 ( V_3 -> V_5 ) )
return F_23 ( V_3 -> V_5 ) ;
V_47 = & V_3 -> V_47 ;
V_47 -> V_55 = F_19 ( & V_45 -> V_37 ,
sizeof( * V_47 -> V_55 ) * V_56 , V_52 ) ;
if ( ! V_47 -> V_55 )
return - V_53 ;
V_23 [ V_57 ] = F_24 ( & V_45 -> V_37 , L_3 ) ;
if ( F_22 ( V_23 [ V_57 ] ) )
return F_23 ( V_23 [ V_57 ] ) ;
V_23 [ V_58 ] = F_24 ( & V_45 -> V_37 , L_4 ) ;
if ( F_22 ( V_23 [ V_58 ] ) )
return F_23 ( V_23 [ V_58 ] ) ;
V_23 [ V_59 ] = F_24 ( & V_45 -> V_37 , L_5 ) ;
if ( F_22 ( V_23 [ V_59 ] ) )
return F_23 ( V_23 [ V_59 ] ) ;
V_23 [ V_60 ] = F_24 ( & V_45 -> V_37 , L_6 ) ;
if ( F_22 ( V_23 [ V_60 ] ) )
return F_23 ( V_23 [ V_60 ] ) ;
V_3 -> V_36 = F_25 ( V_45 -> V_37 . V_61 ,
L_7 ) ;
if ( F_22 ( V_3 -> V_36 ) ) {
F_13 ( & V_45 -> V_37 , L_8 ,
F_23 ( V_3 -> V_36 ) ) ;
return F_23 ( V_3 -> V_36 ) ;
}
for ( V_20 = 0 ; V_20 < V_56 ; V_20 ++ ) {
struct V_1 * V_2 = & V_3 -> V_55 [ V_20 ] ;
const struct V_62 * V_63 = & V_62 [ V_20 ] ;
V_2 -> V_21 = F_26 ( & V_45 -> V_37 , V_63 -> V_38 ) ;
if ( F_22 ( V_2 -> V_21 ) ) {
if ( F_23 ( V_2 -> V_21 ) == - V_64 )
V_2 -> V_21 = NULL ;
else
return F_23 ( V_2 -> V_21 ) ;
}
}
V_47 -> V_65 = V_56 ;
for ( V_20 = 0 ; V_20 < V_56 ; V_20 ++ ) {
struct V_1 * V_2 = & V_3 -> V_55 [ V_20 ] ;
struct V_11 * V_12 = & V_2 -> V_12 ;
const struct V_62 * V_63 = & V_62 [ V_20 ] ;
V_47 -> V_55 [ V_20 ] = V_12 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_7 = V_63 -> V_7 ;
V_2 -> V_15 = V_3 -> V_5 + V_63 -> V_66 ;
V_2 -> V_34 = V_63 -> V_34 ;
V_2 -> V_17 = V_63 -> V_17 ;
V_2 -> V_35 = V_63 -> V_35 ;
V_2 -> V_43 = V_63 -> V_43 ;
for ( V_50 = 0 ; V_50 < V_22 && V_63 -> V_67 [ V_50 ] ; V_50 ++ )
V_2 -> V_23 [ V_50 ] = V_23 [ V_63 -> V_67 [ V_50 ] ] ;
V_12 -> V_38 = V_63 -> V_38 ;
V_12 -> V_68 = F_14 ;
V_12 -> V_69 = F_3 ;
V_12 -> V_70 . V_43 = F_16 ;
V_12 -> V_69 ( V_12 ) ;
F_27 ( V_12 , NULL , false ) ;
}
V_19 = F_28 ( V_47 -> V_55 [ V_71 ] ,
V_47 -> V_55 [ V_72 ] ) ;
if ( V_19 && F_29 ( V_73 ) )
F_13 ( & V_45 -> V_37 , L_9 , V_19 ) ;
V_19 = F_28 ( V_47 -> V_55 [ V_72 ] ,
V_47 -> V_55 [ V_74 ] ) ;
if ( V_19 && F_29 ( V_73 ) )
F_13 ( & V_45 -> V_37 , L_9 , V_19 ) ;
V_19 = F_30 ( V_45 -> V_37 . V_61 , V_47 ) ;
if ( V_19 )
F_13 ( & V_45 -> V_37 , L_10 , V_19 ) ;
return 0 ;
}
