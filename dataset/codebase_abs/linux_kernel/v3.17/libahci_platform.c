int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
if ( ! V_2 -> V_6 [ V_4 ] )
continue;
V_3 = F_2 ( V_2 -> V_6 [ V_4 ] ) ;
if ( V_3 )
goto V_7;
V_3 = F_3 ( V_2 -> V_6 [ V_4 ] ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_6 [ V_4 ] ) ;
goto V_7;
}
}
return 0 ;
V_7:
while ( -- V_4 >= 0 ) {
F_5 ( V_2 -> V_6 [ V_4 ] ) ;
F_4 ( V_2 -> V_6 [ V_4 ] ) ;
}
return V_3 ;
}
void F_6 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
if ( ! V_2 -> V_6 [ V_4 ] )
continue;
F_5 ( V_2 -> V_6 [ V_4 ] ) ;
F_4 ( V_2 -> V_6 [ V_4 ] ) ;
}
}
int F_7 ( struct V_1 * V_2 )
{
int V_8 , V_3 ;
for ( V_8 = 0 ; V_8 < V_9 && V_2 -> V_10 [ V_8 ] ; V_8 ++ ) {
V_3 = F_8 ( V_2 -> V_10 [ V_8 ] ) ;
if ( V_3 )
goto V_11;
}
return 0 ;
V_11:
while ( -- V_8 >= 0 )
F_9 ( V_2 -> V_10 [ V_8 ] ) ;
return V_3 ;
}
void F_10 ( struct V_1 * V_2 )
{
int V_8 ;
for ( V_8 = V_9 - 1 ; V_8 >= 0 ; V_8 -- )
if ( V_2 -> V_10 [ V_8 ] )
F_9 ( V_2 -> V_10 [ V_8 ] ) ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_12 ) {
V_3 = F_12 ( V_2 -> V_12 ) ;
if ( V_3 )
return V_3 ;
}
V_3 = F_7 ( V_2 ) ;
if ( V_3 )
goto V_13;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_14;
return 0 ;
V_14:
F_10 ( V_2 ) ;
V_13:
if ( V_2 -> V_12 )
F_13 ( V_2 -> V_12 ) ;
return V_3 ;
}
void F_14 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_10 ( V_2 ) ;
if ( V_2 -> V_12 )
F_13 ( V_2 -> V_12 ) ;
}
static void F_15 ( struct V_15 * V_16 , void * V_17 )
{
struct V_1 * V_2 = V_17 ;
int V_8 ;
if ( V_2 -> V_18 ) {
F_16 ( V_16 ) ;
F_17 ( V_16 ) ;
}
for ( V_8 = 0 ; V_8 < V_9 && V_2 -> V_10 [ V_8 ] ; V_8 ++ )
F_18 ( V_2 -> V_10 [ V_8 ] ) ;
}
struct V_1 * F_19 ( struct V_19 * V_20 )
{
struct V_15 * V_16 = & V_20 -> V_16 ;
struct V_1 * V_2 ;
struct V_21 * V_21 ;
struct V_22 * V_23 ;
int V_4 , V_24 = 0 , V_3 = - V_25 ;
T_1 V_26 = 0 ;
if ( ! F_20 ( V_16 , NULL , V_27 ) )
return F_21 ( - V_25 ) ;
V_2 = F_22 ( F_15 , sizeof( * V_2 ) ,
V_27 ) ;
if ( ! V_2 )
goto V_28;
F_23 ( V_16 , V_2 ) ;
V_2 -> V_29 = F_24 ( V_16 ,
F_25 ( V_20 , V_30 , 0 ) ) ;
if ( F_26 ( V_2 -> V_29 ) ) {
F_27 ( V_16 , L_1 ) ;
V_3 = F_28 ( V_2 -> V_29 ) ;
goto V_28;
}
V_2 -> V_12 = F_29 ( V_16 , L_2 ) ;
if ( F_26 ( V_2 -> V_12 ) ) {
V_3 = F_28 ( V_2 -> V_12 ) ;
if ( V_3 == - V_31 )
goto V_28;
V_2 -> V_12 = NULL ;
}
for ( V_4 = 0 ; V_4 < V_9 ; V_4 ++ ) {
if ( V_4 == 0 )
V_21 = F_30 ( V_16 , NULL ) ;
else
V_21 = F_31 ( V_16 -> V_32 , V_4 ) ;
if ( F_26 ( V_21 ) ) {
V_3 = F_28 ( V_21 ) ;
if ( V_3 == - V_31 )
goto V_28;
break;
}
V_2 -> V_10 [ V_4 ] = V_21 ;
}
V_2 -> V_5 = F_32 ( V_16 -> V_32 ) ;
if ( V_2 -> V_5 ) {
V_2 -> V_6 = F_33 ( V_16 ,
V_2 -> V_5 * sizeof( * V_2 -> V_6 ) ,
V_27 ) ;
if ( ! V_2 -> V_6 ) {
V_3 = - V_25 ;
goto V_28;
}
F_34 (dev->of_node, child) {
T_1 V_33 ;
if ( ! F_35 ( V_23 ) )
continue;
if ( F_36 ( V_23 , L_3 , & V_33 ) ) {
V_3 = - V_34 ;
goto V_28;
}
if ( V_33 >= V_2 -> V_5 ) {
F_37 ( V_16 , L_4 , V_33 ) ;
continue;
}
V_26 |= F_38 ( V_33 ) ;
V_2 -> V_6 [ V_33 ] = F_39 ( V_16 , V_23 , NULL ) ;
if ( F_26 ( V_2 -> V_6 [ V_33 ] ) ) {
V_3 = F_28 ( V_2 -> V_6 [ V_33 ] ) ;
F_27 ( V_16 ,
L_5 ,
V_23 -> V_35 , V_3 ) ;
goto V_28;
}
V_24 ++ ;
}
if ( ! V_24 ) {
F_37 ( V_16 , L_6 ) ;
V_3 = - V_36 ;
goto V_28;
}
if ( ! V_2 -> V_26 )
V_2 -> V_26 = V_26 ;
} else {
struct V_37 * V_37 = F_40 ( V_16 , L_7 ) ;
if ( ! F_26 ( V_37 ) ) {
V_2 -> V_6 = F_33 ( V_16 , sizeof( * V_2 -> V_6 ) ,
V_27 ) ;
if ( ! V_2 -> V_6 ) {
V_3 = - V_25 ;
goto V_28;
}
V_2 -> V_6 [ 0 ] = V_37 ;
V_2 -> V_5 = 1 ;
} else {
V_3 = F_28 ( V_37 ) ;
switch ( V_3 ) {
case - V_38 :
if ( F_41 ( V_16 -> V_32 , L_8 , NULL ) ) {
F_27 ( V_16 , L_9 ) ;
goto V_28;
}
case - V_36 :
V_2 -> V_6 = NULL ;
break;
default:
goto V_28;
}
}
}
F_42 ( V_16 ) ;
F_43 ( V_16 ) ;
V_2 -> V_18 = true ;
F_44 ( V_16 , NULL ) ;
return V_2 ;
V_28:
F_45 ( V_16 , NULL ) ;
return F_21 ( V_3 ) ;
}
int F_46 ( struct V_19 * V_20 ,
struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
struct V_15 * V_16 = & V_20 -> V_16 ;
struct V_39 V_41 = * V_40 ;
const struct V_39 * V_42 [] = { & V_41 , NULL } ;
struct V_43 * V_44 ;
int V_4 , V_45 , V_46 , V_3 ;
V_45 = F_47 ( V_20 , 0 ) ;
if ( V_45 <= 0 ) {
F_27 ( V_16 , L_10 ) ;
return - V_34 ;
}
V_41 . V_47 = ( void * ) ( unsigned long ) V_2 -> V_48 ;
F_48 ( V_16 , V_2 ) ;
if ( V_2 -> V_49 & V_50 )
V_41 . V_48 |= V_51 ;
if ( V_2 -> V_49 & V_52 )
V_41 . V_48 |= V_53 ;
F_49 ( V_2 , & V_41 ) ;
V_46 = F_50 ( F_51 ( V_2 -> V_49 ) , F_52 ( V_2 -> V_54 ) ) ;
V_44 = F_53 ( V_16 , V_42 , V_46 ) ;
if ( ! V_44 )
return - V_25 ;
V_44 -> V_47 = V_2 ;
if ( ! ( V_2 -> V_49 & V_55 ) || V_56 )
V_44 -> V_48 |= V_57 ;
else
F_54 ( V_16 , L_11 ) ;
if ( V_41 . V_48 & V_58 )
F_55 ( V_44 ) ;
for ( V_4 = 0 ; V_4 < V_44 -> V_46 ; V_4 ++ ) {
struct V_59 * V_60 = V_44 -> V_61 [ V_4 ] ;
F_56 ( V_60 , L_12 ,
F_25 ( V_20 , V_30 , 0 ) ) ;
F_56 ( V_60 , L_13 , 0x100 + V_60 -> V_62 * 0x80 ) ;
if ( V_60 -> V_48 & V_58 )
V_60 -> V_63 = V_2 -> V_64 ;
if ( ! ( V_2 -> V_54 & ( 1 << V_4 ) ) )
V_60 -> V_65 = & V_66 ;
}
if ( V_2 -> V_49 & V_67 ) {
V_3 = F_57 ( V_16 , F_58 ( 64 ) ) ;
if ( V_3 ) {
V_3 = F_57 ( V_16 ,
F_58 ( 32 ) ) ;
if ( V_3 ) {
F_27 ( V_16 , L_14 ) ;
return V_3 ;
}
F_37 ( V_16 , L_15 ) ;
}
}
V_3 = F_59 ( V_44 ) ;
if ( V_3 )
return V_3 ;
F_60 ( V_44 ) ;
F_61 ( V_44 , L_16 ) ;
return F_62 ( V_44 , V_45 , V_68 , V_69 ,
& V_70 ) ;
}
static void F_63 ( struct V_43 * V_44 )
{
struct V_15 * V_16 = V_44 -> V_16 ;
struct V_71 * V_72 = F_64 ( V_16 ) ;
struct V_1 * V_2 = V_44 -> V_47 ;
if ( V_72 && V_72 -> exit )
V_72 -> exit ( V_16 ) ;
F_14 ( V_2 ) ;
}
int F_65 ( struct V_15 * V_16 )
{
struct V_43 * V_44 = F_66 ( V_16 ) ;
struct V_1 * V_2 = V_44 -> V_47 ;
void T_2 * V_29 = V_2 -> V_29 ;
T_1 V_73 ;
if ( V_2 -> V_48 & V_74 ) {
F_27 ( V_16 , L_17 ) ;
return - V_75 ;
}
V_73 = F_67 ( V_29 + V_76 ) ;
V_73 &= ~ V_77 ;
F_68 ( V_73 , V_29 + V_76 ) ;
F_67 ( V_29 + V_76 ) ;
return F_69 ( V_44 , V_78 ) ;
}
int F_70 ( struct V_15 * V_16 )
{
struct V_43 * V_44 = F_66 ( V_16 ) ;
int V_3 ;
if ( V_16 -> V_79 . V_80 . V_81 == V_82 ) {
V_3 = F_59 ( V_44 ) ;
if ( V_3 )
return V_3 ;
F_60 ( V_44 ) ;
}
F_71 ( V_44 ) ;
return 0 ;
}
int F_72 ( struct V_15 * V_16 )
{
struct V_71 * V_72 = F_64 ( V_16 ) ;
struct V_43 * V_44 = F_66 ( V_16 ) ;
struct V_1 * V_2 = V_44 -> V_47 ;
int V_3 ;
V_3 = F_65 ( V_16 ) ;
if ( V_3 )
return V_3 ;
if ( V_72 && V_72 -> V_83 ) {
V_3 = V_72 -> V_83 ( V_16 ) ;
if ( V_3 )
goto V_84;
}
F_14 ( V_2 ) ;
return 0 ;
V_84:
F_70 ( V_16 ) ;
return V_3 ;
}
int F_73 ( struct V_15 * V_16 )
{
struct V_71 * V_72 = F_64 ( V_16 ) ;
struct V_43 * V_44 = F_66 ( V_16 ) ;
struct V_1 * V_2 = V_44 -> V_47 ;
int V_3 ;
V_3 = F_11 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_72 && V_72 -> V_85 ) {
V_3 = V_72 -> V_85 ( V_16 ) ;
if ( V_3 )
goto V_86;
}
V_3 = F_70 ( V_16 ) ;
if ( V_3 )
goto V_86;
F_17 ( V_16 ) ;
F_74 ( V_16 ) ;
F_42 ( V_16 ) ;
return 0 ;
V_86:
F_14 ( V_2 ) ;
return V_3 ;
}
