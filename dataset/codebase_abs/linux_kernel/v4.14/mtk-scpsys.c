static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_4 = F_2 ( V_3 -> V_5 + V_3 -> V_6 . V_7 ) &
V_2 -> V_8 -> V_9 ;
T_1 V_10 = F_2 ( V_3 -> V_5 + V_3 -> V_6 . V_11 ) &
V_2 -> V_8 -> V_9 ;
if ( V_4 && V_10 )
return true ;
if ( ! V_4 && ! V_10 )
return false ;
return - V_12 ;
}
static int F_3 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_14 , struct V_1 , V_14 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
unsigned long V_15 ;
bool V_16 ;
void T_2 * V_17 = V_3 -> V_5 + V_2 -> V_8 -> V_18 ;
T_1 V_19 = V_2 -> V_8 -> V_20 ;
T_1 V_21 ;
int V_22 ;
int V_23 ;
if ( V_2 -> V_24 ) {
V_22 = F_5 ( V_2 -> V_24 ) ;
if ( V_22 )
return V_22 ;
}
for ( V_23 = 0 ; V_23 < V_25 && V_2 -> V_26 [ V_23 ] ; V_23 ++ ) {
V_22 = F_6 ( V_2 -> V_26 [ V_23 ] ) ;
if ( V_22 ) {
for ( -- V_23 ; V_23 >= 0 ; V_23 -- )
F_7 ( V_2 -> V_26 [ V_23 ] ) ;
goto V_27;
}
}
V_21 = F_2 ( V_17 ) ;
V_21 |= V_28 ;
F_8 ( V_21 , V_17 ) ;
V_21 |= V_29 ;
F_8 ( V_21 , V_17 ) ;
V_15 = V_30 + V_31 ;
V_16 = false ;
while ( 1 ) {
V_22 = F_1 ( V_2 ) ;
if ( V_22 > 0 )
break;
if ( V_16 ) {
V_22 = - V_32 ;
goto V_33;
}
F_9 () ;
if ( F_10 ( V_30 , V_15 ) )
V_16 = true ;
}
V_21 &= ~ V_34 ;
F_8 ( V_21 , V_17 ) ;
V_21 &= ~ V_35 ;
F_8 ( V_21 , V_17 ) ;
V_21 |= V_36 ;
F_8 ( V_21 , V_17 ) ;
V_21 &= ~ V_2 -> V_8 -> V_37 ;
F_8 ( V_21 , V_17 ) ;
V_15 = V_30 + V_31 ;
V_16 = false ;
while ( V_19 && ( F_2 ( V_17 ) & V_19 ) ) {
if ( V_16 ) {
V_22 = - V_32 ;
goto V_33;
}
F_9 () ;
if ( F_10 ( V_30 , V_15 ) )
V_16 = true ;
}
if ( V_2 -> V_8 -> V_38 ) {
V_22 = F_11 ( V_3 -> V_39 ,
V_2 -> V_8 -> V_38 ) ;
if ( V_22 )
goto V_33;
}
return 0 ;
V_33:
for ( V_23 = V_25 - 1 ; V_23 >= 0 ; V_23 -- ) {
if ( V_2 -> V_26 [ V_23 ] )
F_7 ( V_2 -> V_26 [ V_23 ] ) ;
}
V_27:
if ( V_2 -> V_24 )
F_12 ( V_2 -> V_24 ) ;
F_13 ( V_3 -> V_40 , L_1 , V_14 -> V_41 ) ;
return V_22 ;
}
static int F_14 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_14 , struct V_1 , V_14 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
unsigned long V_15 ;
bool V_16 ;
void T_2 * V_17 = V_3 -> V_5 + V_2 -> V_8 -> V_18 ;
T_1 V_42 = V_2 -> V_8 -> V_20 ;
T_1 V_21 ;
int V_22 ;
int V_23 ;
if ( V_2 -> V_8 -> V_38 ) {
V_22 = F_15 ( V_3 -> V_39 ,
V_2 -> V_8 -> V_38 ) ;
if ( V_22 )
goto V_43;
}
V_21 = F_2 ( V_17 ) ;
V_21 |= V_2 -> V_8 -> V_37 ;
F_8 ( V_21 , V_17 ) ;
V_15 = V_30 + V_31 ;
V_16 = false ;
while ( V_42 && ( F_2 ( V_17 ) & V_42 ) != V_42 ) {
if ( V_16 ) {
V_22 = - V_32 ;
goto V_43;
}
F_9 () ;
if ( F_10 ( V_30 , V_15 ) )
V_16 = true ;
}
V_21 |= V_35 ;
F_8 ( V_21 , V_17 ) ;
V_21 &= ~ V_36 ;
F_8 ( V_21 , V_17 ) ;
V_21 |= V_34 ;
F_8 ( V_21 , V_17 ) ;
V_21 &= ~ V_28 ;
F_8 ( V_21 , V_17 ) ;
V_21 &= ~ V_29 ;
F_8 ( V_21 , V_17 ) ;
V_15 = V_30 + V_31 ;
V_16 = false ;
while ( 1 ) {
V_22 = F_1 ( V_2 ) ;
if ( V_22 == 0 )
break;
if ( V_16 ) {
V_22 = - V_32 ;
goto V_43;
}
F_9 () ;
if ( F_10 ( V_30 , V_15 ) )
V_16 = true ;
}
for ( V_23 = 0 ; V_23 < V_25 && V_2 -> V_26 [ V_23 ] ; V_23 ++ )
F_7 ( V_2 -> V_26 [ V_23 ] ) ;
if ( V_2 -> V_24 )
F_12 ( V_2 -> V_24 ) ;
return 0 ;
V_43:
F_13 ( V_3 -> V_40 , L_2 , V_14 -> V_41 ) ;
return V_22 ;
}
static bool F_16 ( struct V_44 * V_40 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
V_14 = F_17 ( V_40 -> V_45 ) ;
V_2 = F_4 ( V_14 , struct V_1 , V_14 ) ;
return V_2 -> V_8 -> V_46 ;
}
static void F_18 ( struct V_47 * V_48 , struct V_26 * * V_26 )
{
int V_23 ;
for ( V_23 = V_49 + 1 ; V_23 < V_50 ; V_23 ++ )
V_26 [ V_23 ] = F_19 ( & V_48 -> V_40 , V_51 [ V_23 ] ) ;
}
static struct V_3 * F_20 ( struct V_47 * V_48 ,
const struct V_52 * V_52 , int V_53 ,
const struct V_54 * V_54 )
{
struct V_55 * V_56 ;
struct V_57 * V_58 ;
int V_23 , V_59 ;
struct V_3 * V_3 ;
struct V_26 * V_26 [ V_50 ] ;
V_3 = F_21 ( & V_48 -> V_40 , sizeof( * V_3 ) , V_60 ) ;
if ( ! V_3 )
return F_22 ( - V_61 ) ;
V_3 -> V_6 . V_7 = V_54 -> V_7 ;
V_3 -> V_6 . V_11 = V_54 -> V_11 ;
V_3 -> V_40 = & V_48 -> V_40 ;
V_58 = F_23 ( V_48 , V_62 , 0 ) ;
V_3 -> V_5 = F_24 ( & V_48 -> V_40 , V_58 ) ;
if ( F_25 ( V_3 -> V_5 ) )
return F_26 ( V_3 -> V_5 ) ;
V_3 -> V_63 = F_21 ( & V_48 -> V_40 ,
sizeof( * V_3 -> V_63 ) * V_53 , V_60 ) ;
if ( ! V_3 -> V_63 )
return F_22 ( - V_61 ) ;
V_56 = & V_3 -> V_56 ;
V_56 -> V_63 = F_21 ( & V_48 -> V_40 ,
sizeof( * V_56 -> V_63 ) * V_53 , V_60 ) ;
if ( ! V_56 -> V_63 )
return F_22 ( - V_61 ) ;
V_3 -> V_39 = F_27 ( V_48 -> V_40 . V_64 ,
L_3 ) ;
if ( F_25 ( V_3 -> V_39 ) ) {
F_13 ( & V_48 -> V_40 , L_4 ,
F_28 ( V_3 -> V_39 ) ) ;
return F_26 ( V_3 -> V_39 ) ;
}
for ( V_23 = 0 ; V_23 < V_53 ; V_23 ++ ) {
struct V_1 * V_2 = & V_3 -> V_63 [ V_23 ] ;
const struct V_52 * V_8 = & V_52 [ V_23 ] ;
V_2 -> V_24 = F_29 ( & V_48 -> V_40 , V_8 -> V_41 ) ;
if ( F_25 ( V_2 -> V_24 ) ) {
if ( F_28 ( V_2 -> V_24 ) == - V_65 )
V_2 -> V_24 = NULL ;
else
return F_26 ( V_2 -> V_24 ) ;
}
}
V_56 -> V_66 = V_53 ;
F_18 ( V_48 , V_26 ) ;
for ( V_23 = 0 ; V_23 < V_53 ; V_23 ++ ) {
struct V_1 * V_2 = & V_3 -> V_63 [ V_23 ] ;
struct V_13 * V_14 = & V_2 -> V_14 ;
const struct V_52 * V_8 = & V_52 [ V_23 ] ;
V_56 -> V_63 [ V_23 ] = V_14 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_8 = V_8 ;
for ( V_59 = 0 ; V_59 < V_25 && V_8 -> V_67 [ V_59 ] ; V_59 ++ ) {
struct V_26 * V_68 = V_26 [ V_8 -> V_67 [ V_59 ] ] ;
if ( F_25 ( V_68 ) ) {
F_13 ( & V_48 -> V_40 , L_5 ,
V_8 -> V_41 ) ;
return F_26 ( V_68 ) ;
}
V_2 -> V_26 [ V_59 ] = V_68 ;
}
V_14 -> V_41 = V_8 -> V_41 ;
V_14 -> V_69 = F_14 ;
V_14 -> V_70 = F_3 ;
V_14 -> V_71 . V_46 = F_16 ;
}
return V_3 ;
}
static void F_30 ( struct V_47 * V_48 ,
struct V_3 * V_3 , int V_53 )
{
struct V_55 * V_56 ;
int V_23 , V_22 ;
for ( V_23 = 0 ; V_23 < V_53 ; V_23 ++ ) {
struct V_1 * V_2 = & V_3 -> V_63 [ V_23 ] ;
struct V_13 * V_14 = & V_2 -> V_14 ;
V_14 -> V_70 ( V_14 ) ;
F_31 ( V_14 , NULL , false ) ;
}
V_56 = & V_3 -> V_56 ;
V_22 = F_32 ( V_48 -> V_40 . V_64 , V_56 ) ;
if ( V_22 )
F_13 ( & V_48 -> V_40 , L_6 , V_22 ) ;
}
static int F_33 ( struct V_47 * V_48 )
{
const struct V_72 * V_73 ;
const struct V_74 * V_75 ;
const struct V_76 * V_77 ;
struct V_3 * V_3 ;
struct V_55 * V_56 ;
int V_23 , V_22 ;
V_73 = F_34 ( V_78 , & V_48 -> V_40 ) ;
V_77 = ( const struct V_76 * ) V_73 -> V_8 ;
V_3 = F_20 ( V_48 , V_77 -> V_63 , V_77 -> V_66 , & V_77 -> V_79 ) ;
if ( F_25 ( V_3 ) )
return F_28 ( V_3 ) ;
F_30 ( V_48 , V_3 , V_77 -> V_66 ) ;
V_56 = & V_3 -> V_56 ;
for ( V_23 = 0 , V_75 = V_77 -> V_80 ; V_23 < V_77 -> V_81 ; V_23 ++ ) {
V_22 = F_35 ( V_56 -> V_63 [ V_75 -> V_82 ] ,
V_56 -> V_63 [ V_75 -> V_83 ] ) ;
if ( V_22 && F_36 ( V_84 ) )
F_13 ( & V_48 -> V_40 , L_7 ,
V_22 ) ;
}
return 0 ;
}
