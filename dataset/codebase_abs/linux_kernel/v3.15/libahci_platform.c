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
case - V_28 :
V_2 -> V_10 = NULL ;
break;
case - V_25 :
goto V_22;
default:
F_25 ( V_13 , L_4 ) ;
goto V_22;
}
}
F_31 ( V_13 ) ;
F_32 ( V_13 ) ;
V_2 -> V_15 = true ;
F_33 ( V_13 , NULL ) ;
return V_2 ;
V_22:
F_34 ( V_13 , NULL ) ;
return F_19 ( V_4 ) ;
}
int F_35 ( struct V_16 * V_17 ,
struct V_1 * V_2 ,
const struct V_29 * V_30 ,
unsigned int V_31 ,
unsigned int V_32 )
{
struct V_12 * V_13 = & V_17 -> V_13 ;
struct V_29 V_33 = * V_30 ;
const struct V_29 * V_34 [] = { & V_33 , NULL } ;
struct V_35 * V_36 ;
int V_19 , V_37 , V_38 , V_4 ;
V_37 = F_36 ( V_17 , 0 ) ;
if ( V_37 <= 0 ) {
F_25 ( V_13 , L_5 ) ;
return - V_39 ;
}
V_2 -> V_40 |= ( unsigned long ) V_33 . V_41 ;
F_37 ( V_13 , V_2 , V_31 , V_32 ) ;
if ( V_2 -> V_42 & V_43 )
V_33 . V_40 |= V_44 ;
if ( V_2 -> V_42 & V_45 )
V_33 . V_40 |= V_46 ;
F_38 ( V_2 , & V_33 ) ;
V_38 = F_39 ( F_40 ( V_2 -> V_42 ) , F_41 ( V_2 -> V_47 ) ) ;
V_36 = F_42 ( V_13 , V_34 , V_38 ) ;
if ( ! V_36 )
return - V_20 ;
V_36 -> V_41 = V_2 ;
if ( ! ( V_2 -> V_42 & V_48 ) || V_49 )
V_36 -> V_40 |= V_50 ;
else
F_43 ( V_13 , L_6 ) ;
if ( V_33 . V_40 & V_51 )
F_44 ( V_36 ) ;
for ( V_19 = 0 ; V_19 < V_36 -> V_38 ; V_19 ++ ) {
struct V_52 * V_53 = V_36 -> V_54 [ V_19 ] ;
F_45 ( V_53 , L_7 ,
F_23 ( V_17 , V_24 , 0 ) ) ;
F_45 ( V_53 , L_8 , 0x100 + V_53 -> V_55 * 0x80 ) ;
if ( V_53 -> V_40 & V_51 )
V_53 -> V_56 = V_2 -> V_57 ;
if ( ! ( V_2 -> V_47 & ( 1 << V_19 ) ) )
V_53 -> V_58 = & V_59 ;
}
V_4 = F_46 ( V_36 ) ;
if ( V_4 )
return V_4 ;
F_47 ( V_36 ) ;
F_48 ( V_36 , L_9 ) ;
return F_49 ( V_36 , V_37 , V_60 , V_61 ,
& V_62 ) ;
}
static void F_50 ( struct V_35 * V_36 )
{
struct V_12 * V_13 = V_36 -> V_13 ;
struct V_63 * V_64 = F_51 ( V_13 ) ;
struct V_1 * V_2 = V_36 -> V_41 ;
if ( V_64 && V_64 -> exit )
V_64 -> exit ( V_13 ) ;
F_11 ( V_2 ) ;
}
int F_52 ( struct V_12 * V_13 )
{
struct V_35 * V_36 = F_53 ( V_13 ) ;
struct V_1 * V_2 = V_36 -> V_41 ;
void T_1 * V_23 = V_2 -> V_23 ;
T_2 V_65 ;
if ( V_2 -> V_40 & V_66 ) {
F_25 ( V_13 , L_10 ) ;
return - V_67 ;
}
V_65 = F_54 ( V_23 + V_68 ) ;
V_65 &= ~ V_69 ;
F_55 ( V_65 , V_23 + V_68 ) ;
F_54 ( V_23 + V_68 ) ;
return F_56 ( V_36 , V_70 ) ;
}
int F_57 ( struct V_12 * V_13 )
{
struct V_35 * V_36 = F_53 ( V_13 ) ;
int V_4 ;
if ( V_13 -> V_71 . V_72 . V_73 == V_74 ) {
V_4 = F_46 ( V_36 ) ;
if ( V_4 )
return V_4 ;
F_47 ( V_36 ) ;
}
F_58 ( V_36 ) ;
return 0 ;
}
int F_59 ( struct V_12 * V_13 )
{
struct V_63 * V_64 = F_51 ( V_13 ) ;
struct V_35 * V_36 = F_53 ( V_13 ) ;
struct V_1 * V_2 = V_36 -> V_41 ;
int V_4 ;
V_4 = F_52 ( V_13 ) ;
if ( V_4 )
return V_4 ;
if ( V_64 && V_64 -> V_75 ) {
V_4 = V_64 -> V_75 ( V_13 ) ;
if ( V_4 )
goto V_76;
}
F_11 ( V_2 ) ;
return 0 ;
V_76:
F_57 ( V_13 ) ;
return V_4 ;
}
int F_60 ( struct V_12 * V_13 )
{
struct V_63 * V_64 = F_51 ( V_13 ) ;
struct V_35 * V_36 = F_53 ( V_13 ) ;
struct V_1 * V_2 = V_36 -> V_41 ;
int V_4 ;
V_4 = F_5 ( V_2 ) ;
if ( V_4 )
return V_4 ;
if ( V_64 && V_64 -> V_77 ) {
V_4 = V_64 -> V_77 ( V_13 ) ;
if ( V_4 )
goto V_78;
}
V_4 = F_57 ( V_13 ) ;
if ( V_4 )
goto V_78;
F_15 ( V_13 ) ;
F_61 ( V_13 ) ;
F_31 ( V_13 ) ;
return 0 ;
V_78:
F_11 ( V_2 ) ;
return V_4 ;
}
