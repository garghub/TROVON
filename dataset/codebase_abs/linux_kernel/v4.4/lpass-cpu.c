static int F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
if ( F_3 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) )
return 0 ;
V_8 = F_4 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] , V_4 ) ;
if ( V_8 )
F_5 ( V_2 -> V_12 , L_1 ,
V_13 , V_4 , V_8 ) ;
return V_8 ;
}
static int F_6 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
if ( ! F_3 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) ) {
V_8 = F_7 (
V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_12 , L_2 ,
V_13 , V_8 ) ;
return V_8 ;
}
}
V_8 = F_7 ( V_7 -> V_16 [ V_2 -> V_10 -> V_11 ] ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_12 , L_3 ,
V_13 , V_8 ) ;
if ( ! F_3 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) )
F_8 (
V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) ;
return V_8 ;
}
return 0 ;
}
static void F_9 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_8 ( V_7 -> V_16 [ V_2 -> V_10 -> V_11 ] ) ;
if ( ! F_3 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) )
F_8 ( V_7 -> V_9 [ V_2 -> V_10 -> V_11 ] ) ;
}
static int F_10 ( struct V_14 * V_15 ,
struct V_17 * V_18 , struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_19 = F_11 ( V_18 ) ;
unsigned int V_20 = F_12 ( V_18 ) ;
unsigned int V_21 = F_13 ( V_18 ) ;
unsigned int V_22 ;
int V_23 , V_8 ;
V_23 = F_14 ( V_19 ) ;
if ( V_23 < 0 ) {
F_5 ( V_2 -> V_12 , L_4 ,
V_13 , V_23 ) ;
return V_23 ;
}
V_22 = V_24 |
V_25 ;
switch ( V_23 ) {
case 16 :
V_22 |= V_26 ;
break;
case 24 :
V_22 |= V_27 ;
break;
case 32 :
V_22 |= V_28 ;
break;
default:
F_5 ( V_2 -> V_12 , L_5 ,
V_13 , V_23 ) ;
return - V_29 ;
}
switch ( V_20 ) {
case 1 :
V_22 |= V_30 ;
V_22 |= V_31 ;
break;
case 2 :
V_22 |= V_30 ;
V_22 |= V_32 ;
break;
case 4 :
V_22 |= V_33 ;
V_22 |= V_32 ;
break;
case 6 :
V_22 |= V_34 ;
V_22 |= V_32 ;
break;
case 8 :
V_22 |= V_35 ;
V_22 |= V_32 ;
break;
default:
F_5 ( V_2 -> V_12 , L_6 ,
V_13 , V_20 ) ;
return - V_29 ;
}
V_8 = F_15 ( V_7 -> V_36 ,
F_16 ( V_7 -> V_37 , V_2 -> V_10 -> V_11 ) ,
V_22 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_12 , L_7 ,
V_13 , V_8 ) ;
return V_8 ;
}
V_8 = F_4 ( V_7 -> V_16 [ V_2 -> V_10 -> V_11 ] ,
V_21 * V_23 * 2 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_12 , L_8 ,
V_13 , V_21 * V_23 * 2 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_17 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_15 ( V_7 -> V_36 ,
F_16 ( V_7 -> V_37 , V_2 -> V_10 -> V_11 ) ,
0 ) ;
if ( V_8 )
F_5 ( V_2 -> V_12 , L_7 ,
V_13 , V_8 ) ;
return V_8 ;
}
static int F_18 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_19 ( V_7 -> V_36 ,
F_16 ( V_7 -> V_37 , V_2 -> V_10 -> V_11 ) ,
V_38 , V_39 ) ;
if ( V_8 )
F_5 ( V_2 -> V_12 , L_7 ,
V_13 , V_8 ) ;
return V_8 ;
}
static int F_20 ( struct V_14 * V_15 ,
int V_40 , struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = - V_29 ;
switch ( V_40 ) {
case V_41 :
case V_42 :
case V_43 :
V_8 = F_19 ( V_7 -> V_36 ,
F_16 ( V_7 -> V_37 ,
V_2 -> V_10 -> V_11 ) ,
V_38 ,
V_39 ) ;
if ( V_8 )
F_5 ( V_2 -> V_12 , L_7 ,
V_13 , V_8 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
V_8 = F_19 ( V_7 -> V_36 ,
F_16 ( V_7 -> V_37 ,
V_2 -> V_10 -> V_11 ) ,
V_38 ,
V_47 ) ;
if ( V_8 )
F_5 ( V_2 -> V_12 , L_7 ,
V_13 , V_8 ) ;
break;
}
return V_8 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_15 ( V_7 -> V_36 ,
F_16 ( V_7 -> V_37 , V_2 -> V_10 -> V_11 ) , 0 ) ;
if ( V_8 )
F_5 ( V_2 -> V_12 , L_7 ,
V_13 , V_8 ) ;
return V_8 ;
}
static bool F_22 ( struct V_48 * V_12 , unsigned int V_49 )
{
struct V_6 * V_7 = F_23 ( V_12 ) ;
struct V_50 * V_51 = V_7 -> V_37 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_51 -> V_53 ; ++ V_52 )
if ( V_49 == F_16 ( V_51 , V_52 ) )
return true ;
for ( V_52 = 0 ; V_52 < V_51 -> V_54 ; ++ V_52 ) {
if ( V_49 == F_24 ( V_51 , V_52 ) )
return true ;
if ( V_49 == F_25 ( V_51 , V_52 ) )
return true ;
}
for ( V_52 = 0 ; V_52 < V_51 -> V_55 ; ++ V_52 ) {
if ( V_49 == F_26 ( V_51 , V_52 ) )
return true ;
if ( V_49 == F_27 ( V_51 , V_52 ) )
return true ;
if ( V_49 == F_28 ( V_51 , V_52 ) )
return true ;
if ( V_49 == F_29 ( V_51 , V_52 ) )
return true ;
}
return false ;
}
static bool F_30 ( struct V_48 * V_12 , unsigned int V_49 )
{
struct V_6 * V_7 = F_23 ( V_12 ) ;
struct V_50 * V_51 = V_7 -> V_37 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_51 -> V_53 ; ++ V_52 )
if ( V_49 == F_16 ( V_51 , V_52 ) )
return true ;
for ( V_52 = 0 ; V_52 < V_51 -> V_54 ; ++ V_52 ) {
if ( V_49 == F_24 ( V_51 , V_52 ) )
return true ;
if ( V_49 == F_31 ( V_51 , V_52 ) )
return true ;
}
for ( V_52 = 0 ; V_52 < V_51 -> V_55 ; ++ V_52 ) {
if ( V_49 == F_26 ( V_51 , V_52 ) )
return true ;
if ( V_49 == F_27 ( V_51 , V_52 ) )
return true ;
if ( V_49 == F_28 ( V_51 , V_52 ) )
return true ;
if ( V_49 == F_32 ( V_51 , V_52 ) )
return true ;
if ( V_49 == F_29 ( V_51 , V_52 ) )
return true ;
}
return false ;
}
static bool F_33 ( struct V_48 * V_12 , unsigned int V_49 )
{
struct V_6 * V_7 = F_23 ( V_12 ) ;
struct V_50 * V_51 = V_7 -> V_37 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_51 -> V_54 ; ++ V_52 )
if ( V_49 == F_31 ( V_51 , V_52 ) )
return true ;
for ( V_52 = 0 ; V_52 < V_51 -> V_55 ; ++ V_52 )
if ( V_49 == F_32 ( V_51 , V_52 ) )
return true ;
return false ;
}
int F_34 ( struct V_56 * V_57 )
{
struct V_6 * V_7 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_50 * V_37 ;
struct V_48 * V_12 = & V_57 -> V_12 ;
const struct V_62 * V_63 ;
char V_64 [ 16 ] ;
int V_8 , V_52 , V_65 ;
V_59 = F_35 ( V_57 -> V_12 . V_66 , L_9 , 0 ) ;
if ( V_59 ) {
F_5 ( & V_57 -> V_12 , L_10 ,
V_13 ) ;
return - V_67 ;
}
V_7 = F_36 ( & V_57 -> V_12 , sizeof( struct V_6 ) ,
V_68 ) ;
if ( ! V_7 )
return - V_69 ;
F_37 ( V_57 , V_7 ) ;
V_63 = F_38 ( V_12 -> V_10 -> V_70 , V_12 ) ;
if ( ! V_63 || ! V_63 -> V_71 )
return - V_29 ;
V_7 -> V_37 = (struct V_50 * ) V_63 -> V_71 ;
V_37 = V_7 -> V_37 ;
V_61 = F_39 ( V_57 , V_72 , L_11 ) ;
V_7 -> V_73 = F_40 ( & V_57 -> V_12 , V_61 ) ;
if ( F_3 ( ( void const V_74 * ) V_7 -> V_73 ) ) {
F_5 ( & V_57 -> V_12 , L_12 ,
V_13 ,
F_41 ( ( void const V_74 * ) V_7 -> V_73 ) ) ;
return F_41 ( ( void const V_74 * ) V_7 -> V_73 ) ;
}
V_75 . V_76 = F_29 ( V_37 ,
V_37 -> V_55 ) ;
V_7 -> V_36 = F_42 ( & V_57 -> V_12 , V_7 -> V_73 ,
& V_75 ) ;
if ( F_3 ( V_7 -> V_36 ) ) {
F_5 ( & V_57 -> V_12 , L_13 ,
V_13 , F_41 ( V_7 -> V_36 ) ) ;
return F_41 ( V_7 -> V_36 ) ;
}
if ( V_37 -> V_77 )
V_37 -> V_77 ( V_57 ) ;
for ( V_52 = 0 ; V_52 < V_37 -> V_78 ; V_52 ++ ) {
V_65 = V_37 -> V_79 [ V_52 ] . V_11 ;
if ( V_37 -> V_78 > 1 )
sprintf ( V_64 , L_14 , V_52 ) ;
else
sprintf ( V_64 , L_15 ) ;
V_7 -> V_9 [ V_65 ] = F_43 ( & V_57 -> V_12 ,
V_64 ) ;
if ( F_3 ( V_7 -> V_9 [ V_65 ] ) ) {
F_44 ( & V_57 -> V_12 ,
L_16 ,
V_13 ,
F_41 ( V_7 -> V_9 [ V_65 ] ) ) ;
}
if ( V_37 -> V_78 > 1 )
sprintf ( V_64 , L_17 , V_52 ) ;
else
sprintf ( V_64 , L_18 ) ;
V_7 -> V_16 [ V_65 ] = F_43 ( & V_57 -> V_12 ,
V_64 ) ;
if ( F_3 ( V_7 -> V_16 [ V_65 ] ) ) {
F_5 ( & V_57 -> V_12 ,
L_19 ,
V_13 ,
F_41 ( V_7 -> V_16 [ V_65 ] ) ) ;
return F_41 ( V_7 -> V_16 [ V_65 ] ) ;
}
}
V_7 -> V_80 = F_43 ( & V_57 -> V_12 , L_20 ) ;
if ( F_3 ( V_7 -> V_80 ) ) {
F_5 ( & V_57 -> V_12 , L_21 ,
V_13 , F_41 ( V_7 -> V_80 ) ) ;
return F_41 ( V_7 -> V_80 ) ;
}
V_8 = F_4 ( V_7 -> V_80 , V_81 ) ;
if ( V_8 ) {
F_5 ( & V_57 -> V_12 , L_22 ,
V_13 , V_8 ) ;
return V_8 ;
}
F_45 ( & V_57 -> V_12 , L_23 , V_13 ,
F_46 ( V_7 -> V_80 ) ) ;
V_8 = F_7 ( V_7 -> V_80 ) ;
if ( V_8 ) {
F_5 ( & V_57 -> V_12 , L_24 ,
V_13 , V_8 ) ;
return V_8 ;
}
V_8 = F_47 ( & V_57 -> V_12 ,
& V_82 ,
V_37 -> V_79 ,
V_37 -> V_78 ) ;
if ( V_8 ) {
F_5 ( & V_57 -> V_12 , L_25 ,
V_13 , V_8 ) ;
goto V_83;
}
V_8 = F_48 ( V_57 ) ;
if ( V_8 ) {
F_5 ( & V_57 -> V_12 , L_26 ,
V_13 , V_8 ) ;
goto V_83;
}
return 0 ;
V_83:
F_8 ( V_7 -> V_80 ) ;
return V_8 ;
}
int F_49 ( struct V_56 * V_57 )
{
struct V_6 * V_7 = F_50 ( V_57 ) ;
if ( V_7 -> V_37 -> exit )
V_7 -> V_37 -> exit ( V_57 ) ;
F_8 ( V_7 -> V_80 ) ;
return 0 ;
}
