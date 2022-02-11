static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
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
static void F_6 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
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
int V_3 , V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
if ( ! V_2 -> V_12 [ V_4 ] )
continue;
V_3 = F_12 ( V_2 -> V_12 [ V_4 ] ) ;
if ( V_3 )
goto V_13;
}
return 0 ;
V_13:
while ( -- V_4 >= 0 )
if ( V_2 -> V_12 [ V_4 ] )
F_13 ( V_2 -> V_12 [ V_4 ] ) ;
return V_3 ;
}
void F_14 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
if ( ! V_2 -> V_12 [ V_4 ] )
continue;
F_13 ( V_2 -> V_12 [ V_4 ] ) ;
}
}
int F_15 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_11 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_7 ( V_2 ) ;
if ( V_3 )
goto V_14;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_15;
return 0 ;
V_15:
F_10 ( V_2 ) ;
V_14:
F_14 ( V_2 ) ;
return V_3 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_10 ( V_2 ) ;
F_14 ( V_2 ) ;
}
static void F_17 ( struct V_16 * V_17 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
int V_8 ;
if ( V_2 -> V_19 ) {
F_18 ( V_17 ) ;
F_19 ( V_17 ) ;
}
for ( V_8 = 0 ; V_8 < V_9 && V_2 -> V_10 [ V_8 ] ; V_8 ++ )
F_20 ( V_2 -> V_10 [ V_8 ] ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_5 ; V_8 ++ )
if ( V_2 -> V_12 && V_2 -> V_12 [ V_8 ] )
F_21 ( V_2 -> V_12 [ V_8 ] ) ;
F_22 ( V_2 -> V_12 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_20 ,
struct V_16 * V_17 , struct V_21 * V_22 )
{
int V_3 ;
V_2 -> V_6 [ V_20 ] = F_24 ( V_17 , V_22 , NULL ) ;
if ( ! F_25 ( V_2 -> V_6 [ V_20 ] ) )
return 0 ;
V_3 = F_26 ( V_2 -> V_6 [ V_20 ] ) ;
switch ( V_3 ) {
case - V_23 :
if ( F_27 ( V_22 , L_1 , NULL ) ) {
F_28 ( V_17 ,
L_2 ,
V_22 -> V_24 ) ;
break;
}
case - V_25 :
V_2 -> V_6 [ V_20 ] = NULL ;
V_3 = 0 ;
break;
default:
F_28 ( V_17 ,
L_3 ,
V_22 -> V_24 , V_3 ) ;
break;
}
return V_3 ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_20 ,
struct V_16 * V_17 )
{
struct V_26 * V_27 ;
int V_3 = 0 ;
V_27 = F_30 ( V_17 , L_4 ) ;
if ( ! F_25 ( V_27 ) )
V_2 -> V_12 [ V_20 ] = V_27 ;
else
V_3 = F_26 ( V_27 ) ;
return V_3 ;
}
struct V_1 * F_31 ( struct V_28 * V_29 )
{
struct V_16 * V_17 = & V_29 -> V_17 ;
struct V_1 * V_2 ;
struct V_30 * V_30 ;
struct V_21 * V_31 ;
int V_4 , V_32 , V_33 = 0 , V_3 = - V_34 , V_35 ;
T_1 V_36 = 0 ;
if ( ! F_32 ( V_17 , NULL , V_37 ) )
return F_33 ( - V_34 ) ;
V_2 = F_34 ( F_17 , sizeof( * V_2 ) ,
V_37 ) ;
if ( ! V_2 )
goto V_38;
F_35 ( V_17 , V_2 ) ;
V_2 -> V_39 = F_36 ( V_17 ,
F_37 ( V_29 , V_40 , 0 ) ) ;
if ( F_25 ( V_2 -> V_39 ) ) {
F_28 ( V_17 , L_5 ) ;
V_3 = F_26 ( V_2 -> V_39 ) ;
goto V_38;
}
for ( V_4 = 0 ; V_4 < V_9 ; V_4 ++ ) {
if ( V_4 == 0 )
V_30 = F_38 ( V_17 , NULL ) ;
else
V_30 = F_39 ( V_17 -> V_41 , V_4 ) ;
if ( F_25 ( V_30 ) ) {
V_3 = F_26 ( V_30 ) ;
if ( V_3 == - V_42 )
goto V_38;
break;
}
V_2 -> V_10 [ V_4 ] = V_30 ;
}
V_2 -> V_5 = V_35 = F_40 ( V_17 -> V_41 ) ;
if ( ! V_35 )
V_2 -> V_5 = 1 ;
V_32 = V_2 -> V_5 * sizeof( * V_2 -> V_6 ) ;
V_2 -> V_6 = F_41 ( V_17 , V_32 , V_37 ) ;
if ( ! V_2 -> V_6 ) {
V_3 = - V_34 ;
goto V_38;
}
V_32 = V_2 -> V_5 * sizeof( * V_2 -> V_12 ) ;
V_2 -> V_12 = F_42 ( V_32 , V_37 ) ;
if ( ! V_2 -> V_12 ) {
V_3 = - V_34 ;
goto V_38;
}
if ( V_35 ) {
F_43 (dev->of_node, child) {
T_1 V_20 ;
struct V_28 * T_2 V_43 ;
if ( ! F_44 ( V_31 ) )
continue;
if ( F_45 ( V_31 , L_6 , & V_20 ) ) {
V_3 = - V_44 ;
goto V_38;
}
if ( V_20 >= V_2 -> V_5 ) {
F_46 ( V_17 , L_7 , V_20 ) ;
continue;
}
V_36 |= F_47 ( V_20 ) ;
#ifdef F_48
F_49 ( V_31 , NULL , NULL ) ;
T_2 = F_50 ( V_31 ) ;
if ( T_2 ) {
V_3 = F_29 ( V_2 , V_20 ,
& T_2 -> V_17 ) ;
if ( V_3 == - V_42 )
goto V_38;
}
#endif
V_3 = F_23 ( V_2 , V_20 , V_17 , V_31 ) ;
if ( V_3 )
goto V_38;
V_33 ++ ;
}
if ( ! V_33 ) {
F_46 ( V_17 , L_8 ) ;
V_3 = - V_25 ;
goto V_38;
}
if ( ! V_2 -> V_36 )
V_2 -> V_36 = V_36 ;
} else {
V_3 = F_23 ( V_2 , 0 , V_17 , V_17 -> V_41 ) ;
if ( V_3 )
goto V_38;
V_3 = F_29 ( V_2 , 0 , V_17 ) ;
if ( V_3 == - V_42 )
goto V_38;
}
F_51 ( V_17 ) ;
F_52 ( V_17 ) ;
V_2 -> V_19 = true ;
F_53 ( V_17 , NULL ) ;
return V_2 ;
V_38:
F_54 ( V_17 , NULL ) ;
return F_33 ( V_3 ) ;
}
int F_55 ( struct V_28 * V_29 ,
struct V_1 * V_2 ,
const struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_16 * V_17 = & V_29 -> V_17 ;
struct V_45 V_49 = * V_46 ;
const struct V_45 * V_50 [] = { & V_49 , NULL } ;
struct V_51 * V_52 ;
int V_4 , V_53 , V_54 , V_3 ;
V_53 = F_56 ( V_29 , 0 ) ;
if ( V_53 <= 0 ) {
if ( V_53 != - V_42 )
F_28 ( V_17 , L_9 ) ;
return V_53 ;
}
V_2 -> V_53 = V_53 ;
V_49 . V_55 = ( void * ) ( unsigned long ) V_2 -> V_56 ;
F_57 ( V_17 , V_2 ) ;
if ( V_2 -> V_57 & V_58 )
V_49 . V_56 |= V_59 ;
if ( V_2 -> V_57 & V_60 )
V_49 . V_56 |= V_61 ;
F_58 ( V_2 , & V_49 ) ;
V_54 = F_59 ( F_60 ( V_2 -> V_57 ) , F_61 ( V_2 -> V_62 ) ) ;
V_52 = F_62 ( V_17 , V_50 , V_54 ) ;
if ( ! V_52 )
return - V_34 ;
V_52 -> V_55 = V_2 ;
if ( ! ( V_2 -> V_57 & V_63 ) || V_64 )
V_52 -> V_56 |= V_65 ;
else
F_63 ( V_17 , L_10 ) ;
if ( V_49 . V_56 & V_66 )
F_64 ( V_52 ) ;
for ( V_4 = 0 ; V_4 < V_52 -> V_54 ; V_4 ++ ) {
struct V_67 * V_68 = V_52 -> V_69 [ V_4 ] ;
F_65 ( V_68 , L_11 ,
F_37 ( V_29 , V_40 , 0 ) ) ;
F_65 ( V_68 , L_12 , 0x100 + V_68 -> V_70 * 0x80 ) ;
if ( V_68 -> V_56 & V_66 )
V_68 -> V_71 = V_2 -> V_72 ;
if ( ! ( V_2 -> V_62 & ( 1 << V_4 ) ) )
V_68 -> V_73 = & V_74 ;
}
if ( V_2 -> V_57 & V_75 ) {
V_3 = F_66 ( V_17 , F_67 ( 64 ) ) ;
if ( V_3 ) {
V_3 = F_66 ( V_17 ,
F_67 ( 32 ) ) ;
if ( V_3 ) {
F_28 ( V_17 , L_13 ) ;
return V_3 ;
}
F_46 ( V_17 , L_14 ) ;
}
}
V_3 = F_68 ( V_52 ) ;
if ( V_3 )
return V_3 ;
F_69 ( V_52 ) ;
F_70 ( V_52 , L_15 ) ;
return F_71 ( V_52 , V_48 ) ;
}
static void F_72 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = V_52 -> V_55 ;
F_16 ( V_2 ) ;
}
void F_73 ( struct V_28 * V_29 )
{
struct V_51 * V_52 = F_74 ( V_29 ) ;
struct V_1 * V_2 = V_52 -> V_55 ;
void T_3 * V_39 = V_2 -> V_39 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_52 -> V_54 ; V_4 ++ ) {
struct V_67 * V_68 = V_52 -> V_69 [ V_4 ] ;
if ( V_68 -> V_73 -> V_76 )
V_68 -> V_73 -> V_76 ( V_68 ) ;
if ( V_68 -> V_73 -> V_77 )
V_68 -> V_73 -> V_77 ( V_68 ) ;
}
F_75 ( F_76 ( V_39 + V_78 ) & ~ V_79 , V_39 + V_78 ) ;
F_76 ( V_39 + V_78 ) ;
F_75 ( F_77 ( V_52 -> V_54 , 0 ) , V_39 + V_80 ) ;
}
int F_78 ( struct V_16 * V_17 )
{
struct V_51 * V_52 = F_79 ( V_17 ) ;
struct V_1 * V_2 = V_52 -> V_55 ;
void T_3 * V_39 = V_2 -> V_39 ;
T_1 V_81 ;
if ( V_2 -> V_56 & V_82 ) {
F_28 ( V_17 , L_16 ) ;
return - V_83 ;
}
V_81 = F_76 ( V_39 + V_78 ) ;
V_81 &= ~ V_79 ;
F_75 ( V_81 , V_39 + V_78 ) ;
F_76 ( V_39 + V_78 ) ;
return F_80 ( V_52 , V_84 ) ;
}
int F_81 ( struct V_16 * V_17 )
{
struct V_51 * V_52 = F_79 ( V_17 ) ;
int V_3 ;
if ( V_17 -> V_85 . V_86 . V_87 == V_88 ) {
V_3 = F_68 ( V_52 ) ;
if ( V_3 )
return V_3 ;
F_69 ( V_52 ) ;
}
F_82 ( V_52 ) ;
return 0 ;
}
int F_83 ( struct V_16 * V_17 )
{
struct V_51 * V_52 = F_79 ( V_17 ) ;
struct V_1 * V_2 = V_52 -> V_55 ;
int V_3 ;
V_3 = F_78 ( V_17 ) ;
if ( V_3 )
return V_3 ;
F_16 ( V_2 ) ;
return 0 ;
}
int F_84 ( struct V_16 * V_17 )
{
struct V_51 * V_52 = F_79 ( V_17 ) ;
struct V_1 * V_2 = V_52 -> V_55 ;
int V_3 ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_81 ( V_17 ) ;
if ( V_3 )
goto V_89;
F_19 ( V_17 ) ;
F_85 ( V_17 ) ;
F_51 ( V_17 ) ;
return 0 ;
V_89:
F_16 ( V_2 ) ;
return V_3 ;
}
