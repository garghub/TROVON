static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_4 = F_2 ( V_3 -> V_5 + V_6 ) & V_2 -> V_7 -> V_8 ;
T_1 V_9 = F_2 ( V_3 -> V_5 + V_10 ) &
V_2 -> V_7 -> V_8 ;
if ( V_4 && V_9 )
return true ;
if ( ! V_4 && ! V_9 )
return false ;
return - V_11 ;
}
static int F_3 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 , struct V_1 , V_13 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
unsigned long V_14 ;
bool V_15 ;
void T_2 * V_16 = V_3 -> V_5 + V_2 -> V_7 -> V_17 ;
T_1 V_18 = V_2 -> V_7 -> V_19 ;
T_1 V_20 ;
int V_21 ;
int V_22 ;
if ( V_2 -> V_23 ) {
V_21 = F_5 ( V_2 -> V_23 ) ;
if ( V_21 )
return V_21 ;
}
for ( V_22 = 0 ; V_22 < V_24 && V_2 -> V_25 [ V_22 ] ; V_22 ++ ) {
V_21 = F_6 ( V_2 -> V_25 [ V_22 ] ) ;
if ( V_21 ) {
for ( -- V_22 ; V_22 >= 0 ; V_22 -- )
F_7 ( V_2 -> V_25 [ V_22 ] ) ;
goto V_26;
}
}
V_20 = F_2 ( V_16 ) ;
V_20 |= V_27 ;
F_8 ( V_20 , V_16 ) ;
V_20 |= V_28 ;
F_8 ( V_20 , V_16 ) ;
V_14 = V_29 + V_30 ;
V_15 = false ;
while ( 1 ) {
V_21 = F_1 ( V_2 ) ;
if ( V_21 > 0 )
break;
if ( V_15 ) {
V_21 = - V_31 ;
goto V_32;
}
F_9 () ;
if ( F_10 ( V_29 , V_14 ) )
V_15 = true ;
}
V_20 &= ~ V_33 ;
F_8 ( V_20 , V_16 ) ;
V_20 &= ~ V_34 ;
F_8 ( V_20 , V_16 ) ;
V_20 |= V_35 ;
F_8 ( V_20 , V_16 ) ;
V_20 &= ~ V_2 -> V_7 -> V_36 ;
F_8 ( V_20 , V_16 ) ;
V_14 = V_29 + V_30 ;
V_15 = false ;
while ( V_18 && ( F_2 ( V_16 ) & V_18 ) ) {
if ( V_15 ) {
V_21 = - V_31 ;
goto V_32;
}
F_9 () ;
if ( F_10 ( V_29 , V_14 ) )
V_15 = true ;
}
if ( V_2 -> V_7 -> V_37 ) {
V_21 = F_11 ( V_3 -> V_38 ,
V_2 -> V_7 -> V_37 ) ;
if ( V_21 )
goto V_32;
}
return 0 ;
V_32:
for ( V_22 = V_24 - 1 ; V_22 >= 0 ; V_22 -- ) {
if ( V_2 -> V_25 [ V_22 ] )
F_7 ( V_2 -> V_25 [ V_22 ] ) ;
}
V_26:
if ( V_2 -> V_23 )
F_12 ( V_2 -> V_23 ) ;
F_13 ( V_3 -> V_39 , L_1 , V_13 -> V_40 ) ;
return V_21 ;
}
static int F_14 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_4 ( V_13 , struct V_1 , V_13 ) ;
struct V_3 * V_3 = V_2 -> V_3 ;
unsigned long V_14 ;
bool V_15 ;
void T_2 * V_16 = V_3 -> V_5 + V_2 -> V_7 -> V_17 ;
T_1 V_41 = V_2 -> V_7 -> V_19 ;
T_1 V_20 ;
int V_21 ;
int V_22 ;
if ( V_2 -> V_7 -> V_37 ) {
V_21 = F_15 ( V_3 -> V_38 ,
V_2 -> V_7 -> V_37 ) ;
if ( V_21 )
goto V_42;
}
V_20 = F_2 ( V_16 ) ;
V_20 |= V_2 -> V_7 -> V_36 ;
F_8 ( V_20 , V_16 ) ;
V_14 = V_29 + V_30 ;
V_15 = false ;
while ( V_41 && ( F_2 ( V_16 ) & V_41 ) != V_41 ) {
if ( V_15 ) {
V_21 = - V_31 ;
goto V_42;
}
F_9 () ;
if ( F_10 ( V_29 , V_14 ) )
V_15 = true ;
}
V_20 |= V_34 ;
F_8 ( V_20 , V_16 ) ;
V_20 &= ~ V_35 ;
F_8 ( V_20 , V_16 ) ;
V_20 |= V_33 ;
F_8 ( V_20 , V_16 ) ;
V_20 &= ~ V_27 ;
F_8 ( V_20 , V_16 ) ;
V_20 &= ~ V_28 ;
F_8 ( V_20 , V_16 ) ;
V_14 = V_29 + V_30 ;
V_15 = false ;
while ( 1 ) {
V_21 = F_1 ( V_2 ) ;
if ( V_21 == 0 )
break;
if ( V_15 ) {
V_21 = - V_31 ;
goto V_42;
}
F_9 () ;
if ( F_10 ( V_29 , V_14 ) )
V_15 = true ;
}
for ( V_22 = 0 ; V_22 < V_24 && V_2 -> V_25 [ V_22 ] ; V_22 ++ )
F_7 ( V_2 -> V_25 [ V_22 ] ) ;
if ( V_2 -> V_23 )
F_12 ( V_2 -> V_23 ) ;
return 0 ;
V_42:
F_13 ( V_3 -> V_39 , L_2 , V_13 -> V_40 ) ;
return V_21 ;
}
static bool F_16 ( struct V_43 * V_39 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
V_13 = F_17 ( V_39 -> V_44 ) ;
V_2 = F_4 ( V_13 , struct V_1 , V_13 ) ;
return V_2 -> V_7 -> V_45 ;
}
static void F_18 ( struct V_46 * V_47 , struct V_25 * * V_25 )
{
int V_22 ;
for ( V_22 = V_48 + 1 ; V_22 < V_49 ; V_22 ++ )
V_25 [ V_22 ] = F_19 ( & V_47 -> V_39 , V_50 [ V_22 ] ) ;
}
static struct V_3 * F_20 ( struct V_46 * V_47 ,
const struct V_51 * V_51 , int V_52 )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
int V_22 , V_57 ;
struct V_3 * V_3 ;
struct V_25 * V_25 [ V_49 ] ;
V_3 = F_21 ( & V_47 -> V_39 , sizeof( * V_3 ) , V_58 ) ;
if ( ! V_3 )
return F_22 ( - V_59 ) ;
V_3 -> V_39 = & V_47 -> V_39 ;
V_56 = F_23 ( V_47 , V_60 , 0 ) ;
V_3 -> V_5 = F_24 ( & V_47 -> V_39 , V_56 ) ;
if ( F_25 ( V_3 -> V_5 ) )
return F_26 ( V_3 -> V_5 ) ;
V_3 -> V_61 = F_21 ( & V_47 -> V_39 ,
sizeof( * V_3 -> V_61 ) * V_52 , V_58 ) ;
if ( ! V_3 -> V_61 )
return F_22 ( - V_59 ) ;
V_54 = & V_3 -> V_54 ;
V_54 -> V_61 = F_21 ( & V_47 -> V_39 ,
sizeof( * V_54 -> V_61 ) * V_52 , V_58 ) ;
if ( ! V_54 -> V_61 )
return F_22 ( - V_59 ) ;
V_3 -> V_38 = F_27 ( V_47 -> V_39 . V_62 ,
L_3 ) ;
if ( F_25 ( V_3 -> V_38 ) ) {
F_13 ( & V_47 -> V_39 , L_4 ,
F_28 ( V_3 -> V_38 ) ) ;
return F_26 ( V_3 -> V_38 ) ;
}
for ( V_22 = 0 ; V_22 < V_52 ; V_22 ++ ) {
struct V_1 * V_2 = & V_3 -> V_61 [ V_22 ] ;
const struct V_51 * V_7 = & V_51 [ V_22 ] ;
V_2 -> V_23 = F_29 ( & V_47 -> V_39 , V_7 -> V_40 ) ;
if ( F_25 ( V_2 -> V_23 ) ) {
if ( F_28 ( V_2 -> V_23 ) == - V_63 )
V_2 -> V_23 = NULL ;
else
return F_26 ( V_2 -> V_23 ) ;
}
}
V_54 -> V_64 = V_52 ;
F_18 ( V_47 , V_25 ) ;
for ( V_22 = 0 ; V_22 < V_52 ; V_22 ++ ) {
struct V_1 * V_2 = & V_3 -> V_61 [ V_22 ] ;
struct V_12 * V_13 = & V_2 -> V_13 ;
const struct V_51 * V_7 = & V_51 [ V_22 ] ;
V_54 -> V_61 [ V_22 ] = V_13 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_7 = V_7 ;
for ( V_57 = 0 ; V_57 < V_24 && V_7 -> V_65 [ V_57 ] ; V_57 ++ ) {
struct V_25 * V_66 = V_25 [ V_7 -> V_65 [ V_57 ] ] ;
if ( F_25 ( V_66 ) ) {
F_13 ( & V_47 -> V_39 , L_5 ,
V_7 -> V_40 ) ;
return F_26 ( V_66 ) ;
}
V_2 -> V_25 [ V_57 ] = V_66 ;
}
V_13 -> V_40 = V_7 -> V_40 ;
V_13 -> V_67 = F_14 ;
V_13 -> V_68 = F_3 ;
V_13 -> V_69 . V_45 = F_16 ;
}
return V_3 ;
}
static void F_30 ( struct V_46 * V_47 ,
struct V_3 * V_3 , int V_52 )
{
struct V_53 * V_54 ;
int V_22 , V_21 ;
for ( V_22 = 0 ; V_22 < V_52 ; V_22 ++ ) {
struct V_1 * V_2 = & V_3 -> V_61 [ V_22 ] ;
struct V_12 * V_13 = & V_2 -> V_13 ;
V_13 -> V_68 ( V_13 ) ;
F_31 ( V_13 , NULL , false ) ;
}
V_54 = & V_3 -> V_54 ;
V_21 = F_32 ( V_47 -> V_39 . V_62 , V_54 ) ;
if ( V_21 )
F_13 ( & V_47 -> V_39 , L_6 , V_21 ) ;
}
static int T_3 F_33 ( struct V_46 * V_47 )
{
struct V_3 * V_3 ;
V_3 = F_20 ( V_47 , V_70 , V_71 ) ;
if ( F_25 ( V_3 ) )
return F_28 ( V_3 ) ;
F_30 ( V_47 , V_3 , V_71 ) ;
return 0 ;
}
static int T_3 F_34 ( struct V_46 * V_47 )
{
struct V_3 * V_3 ;
struct V_53 * V_54 ;
int V_21 ;
V_3 = F_20 ( V_47 , V_72 , V_73 ) ;
if ( F_25 ( V_3 ) )
return F_28 ( V_3 ) ;
F_30 ( V_47 , V_3 , V_73 ) ;
V_54 = & V_3 -> V_54 ;
V_21 = F_35 ( V_54 -> V_61 [ V_74 ] ,
V_54 -> V_61 [ V_75 ] ) ;
if ( V_21 && F_36 ( V_76 ) )
F_13 ( & V_47 -> V_39 , L_7 , V_21 ) ;
V_21 = F_35 ( V_54 -> V_61 [ V_75 ] ,
V_54 -> V_61 [ V_77 ] ) ;
if ( V_21 && F_36 ( V_76 ) )
F_13 ( & V_47 -> V_39 , L_7 , V_21 ) ;
return 0 ;
}
static int F_37 ( struct V_46 * V_47 )
{
int (* F_38)( struct V_46 * );
const struct V_78 * V_79 ;
V_79 = F_39 ( V_80 , V_47 -> V_39 . V_62 ) ;
if ( ! V_79 || ! V_79 -> V_7 )
return - V_11 ;
F_38 = V_79 -> V_7 ;
return F_38 ( V_47 ) ;
}
