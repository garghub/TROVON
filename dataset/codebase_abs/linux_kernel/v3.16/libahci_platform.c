int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < V_5 && V_2 -> V_6 [ V_3 ] ; V_3 ++ ) {
V_4 = F_2 ( V_2 -> V_6 [ V_3 ] ) ;
if ( V_4 )
goto V_7;
}
return 0 ;
V_7:
while ( -- V_3 >= 0 )
F_3 ( V_2 -> V_6 [ V_3 ] ) ;
return V_4 ;
}
void F_4 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = V_5 - 1 ; V_3 >= 0 ; V_3 -- )
if ( V_2 -> V_6 [ V_3 ] )
F_3 ( V_2 -> V_6 [ V_3 ] ) ;
}
int F_5 ( struct V_1 * V_2 )
{
int V_4 ;
if ( V_2 -> V_8 ) {
V_4 = F_6 ( V_2 -> V_8 ) ;
if ( V_4 )
return V_4 ;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
goto V_9;
if ( V_2 -> V_10 ) {
V_4 = F_7 ( V_2 -> V_10 ) ;
if ( V_4 )
goto V_11;
V_4 = F_8 ( V_2 -> V_10 ) ;
if ( V_4 ) {
F_9 ( V_2 -> V_10 ) ;
goto V_11;
}
}
return 0 ;
V_11:
F_4 ( V_2 ) ;
V_9:
if ( V_2 -> V_8 )
F_10 ( V_2 -> V_8 ) ;
return V_4 ;
}
void F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 ) {
F_12 ( V_2 -> V_10 ) ;
F_9 ( V_2 -> V_10 ) ;
}
F_4 ( V_2 ) ;
if ( V_2 -> V_8 )
F_10 ( V_2 -> V_8 ) ;
}
static void F_13 ( struct V_12 * V_13 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
int V_3 ;
if ( V_2 -> V_15 ) {
F_14 ( V_13 ) ;
F_15 ( V_13 ) ;
}
for ( V_3 = 0 ; V_3 < V_5 && V_2 -> V_6 [ V_3 ] ; V_3 ++ )
F_16 ( V_2 -> V_6 [ V_3 ] ) ;
}
struct V_1 * F_17 ( struct V_16 * V_17 )
{
struct V_12 * V_13 = & V_17 -> V_13 ;
struct V_1 * V_2 ;
struct V_18 * V_18 ;
int V_19 , V_4 = - V_20 ;
if ( ! F_18 ( V_13 , NULL , V_21 ) )
return F_19 ( - V_20 ) ;
V_2 = F_20 ( F_13 , sizeof( * V_2 ) ,
V_21 ) ;
if ( ! V_2 )
goto V_22;
F_21 ( V_13 , V_2 ) ;
V_2 -> V_23 = F_22 ( V_13 ,
F_23 ( V_17 , V_24 , 0 ) ) ;
if ( F_24 ( V_2 -> V_23 ) ) {
F_25 ( V_13 , L_1 ) ;
V_4 = F_26 ( V_2 -> V_23 ) ;
goto V_22;
}
V_2 -> V_8 = F_27 ( V_13 , L_2 ) ;
if ( F_24 ( V_2 -> V_8 ) ) {
V_4 = F_26 ( V_2 -> V_8 ) ;
if ( V_4 == - V_25 )
goto V_22;
V_2 -> V_8 = NULL ;
}
for ( V_19 = 0 ; V_19 < V_5 ; V_19 ++ ) {
if ( V_19 == 0 )
V_18 = F_28 ( V_13 , NULL ) ;
else
V_18 = F_29 ( V_13 -> V_26 , V_19 ) ;
if ( F_24 ( V_18 ) ) {
V_4 = F_26 ( V_18 ) ;
if ( V_4 == - V_25 )
goto V_22;
break;
}
V_2 -> V_6 [ V_19 ] = V_18 ;
}
V_2 -> V_10 = F_30 ( V_13 , L_3 ) ;
if ( F_24 ( V_2 -> V_10 ) ) {
V_4 = F_26 ( V_2 -> V_10 ) ;
switch ( V_4 ) {
case - V_27 :
if ( F_31 ( V_13 -> V_26 , L_4 , NULL ) ) {
F_25 ( V_13 , L_5 ) ;
goto V_22;
}
case - V_28 :
V_2 -> V_10 = NULL ;
break;
case - V_25 :
goto V_22;
default:
F_25 ( V_13 , L_6 ) ;
goto V_22;
}
}
F_32 ( V_13 ) ;
F_33 ( V_13 ) ;
V_2 -> V_15 = true ;
F_34 ( V_13 , NULL ) ;
return V_2 ;
V_22:
F_35 ( V_13 , NULL ) ;
return F_19 ( V_4 ) ;
}
int F_36 ( struct V_16 * V_17 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 ,
unsigned long V_31 ,
unsigned int V_32 ,
unsigned int V_33 )
{
struct V_12 * V_13 = & V_17 -> V_13 ;
struct V_29 V_34 = * V_30 ;
const struct V_29 * V_35 [] = { & V_34 , NULL } ;
struct V_36 * V_37 ;
int V_19 , V_38 , V_39 , V_4 ;
V_38 = F_37 ( V_17 , 0 ) ;
if ( V_38 <= 0 ) {
F_25 ( V_13 , L_7 ) ;
return - V_40 ;
}
V_34 . V_41 = ( void * ) V_31 ;
V_2 -> V_42 |= V_31 ;
F_38 ( V_13 , V_2 , V_32 , V_33 ) ;
if ( V_2 -> V_43 & V_44 )
V_34 . V_42 |= V_45 ;
if ( V_2 -> V_43 & V_46 )
V_34 . V_42 |= V_47 ;
F_39 ( V_2 , & V_34 ) ;
V_39 = F_40 ( F_41 ( V_2 -> V_43 ) , F_42 ( V_2 -> V_48 ) ) ;
V_37 = F_43 ( V_13 , V_35 , V_39 ) ;
if ( ! V_37 )
return - V_20 ;
V_37 -> V_41 = V_2 ;
if ( ! ( V_2 -> V_43 & V_49 ) || V_50 )
V_37 -> V_42 |= V_51 ;
else
F_44 ( V_13 , L_8 ) ;
if ( V_34 . V_42 & V_52 )
F_45 ( V_37 ) ;
for ( V_19 = 0 ; V_19 < V_37 -> V_39 ; V_19 ++ ) {
struct V_53 * V_54 = V_37 -> V_55 [ V_19 ] ;
F_46 ( V_54 , L_9 ,
F_23 ( V_17 , V_24 , 0 ) ) ;
F_46 ( V_54 , L_10 , 0x100 + V_54 -> V_56 * 0x80 ) ;
if ( V_54 -> V_42 & V_52 )
V_54 -> V_57 = V_2 -> V_58 ;
if ( ! ( V_2 -> V_48 & ( 1 << V_19 ) ) )
V_54 -> V_59 = & V_60 ;
}
V_4 = F_47 ( V_37 ) ;
if ( V_4 )
return V_4 ;
F_48 ( V_37 ) ;
F_49 ( V_37 , L_11 ) ;
return F_50 ( V_37 , V_38 , V_61 , V_62 ,
& V_63 ) ;
}
static void F_51 ( struct V_36 * V_37 )
{
struct V_12 * V_13 = V_37 -> V_13 ;
struct V_64 * V_65 = F_52 ( V_13 ) ;
struct V_1 * V_2 = V_37 -> V_41 ;
if ( V_65 && V_65 -> exit )
V_65 -> exit ( V_13 ) ;
F_11 ( V_2 ) ;
}
int F_53 ( struct V_12 * V_13 )
{
struct V_36 * V_37 = F_54 ( V_13 ) ;
struct V_1 * V_2 = V_37 -> V_41 ;
void T_1 * V_23 = V_2 -> V_23 ;
T_2 V_66 ;
if ( V_2 -> V_42 & V_67 ) {
F_25 ( V_13 , L_12 ) ;
return - V_68 ;
}
V_66 = F_55 ( V_23 + V_69 ) ;
V_66 &= ~ V_70 ;
F_56 ( V_66 , V_23 + V_69 ) ;
F_55 ( V_23 + V_69 ) ;
return F_57 ( V_37 , V_71 ) ;
}
int F_58 ( struct V_12 * V_13 )
{
struct V_36 * V_37 = F_54 ( V_13 ) ;
int V_4 ;
if ( V_13 -> V_72 . V_73 . V_74 == V_75 ) {
V_4 = F_47 ( V_37 ) ;
if ( V_4 )
return V_4 ;
F_48 ( V_37 ) ;
}
F_59 ( V_37 ) ;
return 0 ;
}
int F_60 ( struct V_12 * V_13 )
{
struct V_64 * V_65 = F_52 ( V_13 ) ;
struct V_36 * V_37 = F_54 ( V_13 ) ;
struct V_1 * V_2 = V_37 -> V_41 ;
int V_4 ;
V_4 = F_53 ( V_13 ) ;
if ( V_4 )
return V_4 ;
if ( V_65 && V_65 -> V_76 ) {
V_4 = V_65 -> V_76 ( V_13 ) ;
if ( V_4 )
goto V_77;
}
F_11 ( V_2 ) ;
return 0 ;
V_77:
F_58 ( V_13 ) ;
return V_4 ;
}
int F_61 ( struct V_12 * V_13 )
{
struct V_64 * V_65 = F_52 ( V_13 ) ;
struct V_36 * V_37 = F_54 ( V_13 ) ;
struct V_1 * V_2 = V_37 -> V_41 ;
int V_4 ;
V_4 = F_5 ( V_2 ) ;
if ( V_4 )
return V_4 ;
if ( V_65 && V_65 -> V_78 ) {
V_4 = V_65 -> V_78 ( V_13 ) ;
if ( V_4 )
goto V_79;
}
V_4 = F_58 ( V_13 ) ;
if ( V_4 )
goto V_79;
F_15 ( V_13 ) ;
F_62 ( V_13 ) ;
F_32 ( V_13 ) ;
return 0 ;
V_79:
F_11 ( V_2 ) ;
return V_4 ;
}
