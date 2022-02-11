static int F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_3 ( V_7 -> V_9 , V_4 ) ;
if ( V_8 )
F_4 ( V_2 -> V_10 , L_1 ,
V_11 , V_4 , V_8 ) ;
return V_8 ;
}
static int F_5 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_6 ( V_7 -> V_9 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_10 , L_2 ,
V_11 , V_8 ) ;
return V_8 ;
}
V_8 = F_6 ( V_7 -> V_14 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_10 , L_3 ,
V_11 , V_8 ) ;
F_7 ( V_7 -> V_9 ) ;
return V_8 ;
}
return 0 ;
}
static void F_8 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_7 ( V_7 -> V_14 ) ;
F_7 ( V_7 -> V_9 ) ;
}
static int F_9 ( struct V_12 * V_13 ,
struct V_15 * V_16 , struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_17 = F_10 ( V_16 ) ;
unsigned int V_18 = F_11 ( V_16 ) ;
unsigned int V_19 = F_12 ( V_16 ) ;
unsigned int V_20 ;
int V_21 , V_8 ;
V_21 = F_13 ( V_17 ) ;
if ( V_21 < 0 ) {
F_4 ( V_2 -> V_10 , L_4 ,
V_11 , V_21 ) ;
return V_21 ;
}
V_20 = V_22 |
V_23 ;
switch ( V_21 ) {
case 16 :
V_20 |= V_24 ;
break;
case 24 :
V_20 |= V_25 ;
break;
case 32 :
V_20 |= V_26 ;
break;
default:
F_4 ( V_2 -> V_10 , L_5 ,
V_11 , V_21 ) ;
return - V_27 ;
}
switch ( V_18 ) {
case 1 :
V_20 |= V_28 ;
V_20 |= V_29 ;
break;
case 2 :
V_20 |= V_28 ;
V_20 |= V_30 ;
break;
case 4 :
V_20 |= V_31 ;
V_20 |= V_30 ;
break;
case 6 :
V_20 |= V_32 ;
V_20 |= V_30 ;
break;
case 8 :
V_20 |= V_33 ;
V_20 |= V_30 ;
break;
default:
F_4 ( V_2 -> V_10 , L_6 ,
V_11 , V_18 ) ;
return - V_27 ;
}
V_8 = F_14 ( V_7 -> V_34 ,
F_15 ( V_35 ) , V_20 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_10 , L_7 ,
V_11 , V_8 ) ;
return V_8 ;
}
V_8 = F_3 ( V_7 -> V_14 , V_19 * V_21 * 2 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_10 , L_8 ,
V_11 , V_19 * V_21 * 2 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_16 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_14 ( V_7 -> V_34 ,
F_15 ( V_35 ) , 0 ) ;
if ( V_8 )
F_4 ( V_2 -> V_10 , L_7 ,
V_11 , V_8 ) ;
return V_8 ;
}
static int F_17 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_18 ( V_7 -> V_34 ,
F_15 ( V_35 ) ,
V_36 , V_37 ) ;
if ( V_8 )
F_4 ( V_2 -> V_10 , L_7 ,
V_11 , V_8 ) ;
return V_8 ;
}
static int F_19 ( struct V_12 * V_13 ,
int V_38 , struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = - V_27 ;
switch ( V_38 ) {
case V_39 :
case V_40 :
case V_41 :
V_8 = F_18 ( V_7 -> V_34 ,
F_15 ( V_35 ) ,
V_36 ,
V_37 ) ;
if ( V_8 )
F_4 ( V_2 -> V_10 , L_7 ,
V_11 , V_8 ) ;
break;
case V_42 :
case V_43 :
case V_44 :
V_8 = F_18 ( V_7 -> V_34 ,
F_15 ( V_35 ) ,
V_36 ,
V_45 ) ;
if ( V_8 )
F_4 ( V_2 -> V_10 , L_7 ,
V_11 , V_8 ) ;
break;
}
return V_8 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 ;
V_8 = F_14 ( V_7 -> V_34 ,
F_15 ( V_35 ) , 0 ) ;
if ( V_8 )
F_4 ( V_2 -> V_10 , L_7 ,
V_11 , V_8 ) ;
return V_8 ;
}
static bool F_21 ( struct V_46 * V_10 , unsigned int V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_49 ; ++ V_48 )
if ( V_47 == F_15 ( V_48 ) )
return true ;
for ( V_48 = 0 ; V_48 < V_50 ; ++ V_48 ) {
if ( V_47 == F_22 ( V_48 ) )
return true ;
if ( V_47 == F_23 ( V_48 ) )
return true ;
}
for ( V_48 = 0 ; V_48 < V_51 ; ++ V_48 ) {
if ( V_47 == F_24 ( V_48 ) )
return true ;
if ( V_47 == F_25 ( V_48 ) )
return true ;
if ( V_47 == F_26 ( V_48 ) )
return true ;
if ( V_47 == F_27 ( V_48 ) )
return true ;
}
return false ;
}
static bool F_28 ( struct V_46 * V_10 , unsigned int V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_49 ; ++ V_48 )
if ( V_47 == F_15 ( V_48 ) )
return true ;
for ( V_48 = 0 ; V_48 < V_50 ; ++ V_48 ) {
if ( V_47 == F_22 ( V_48 ) )
return true ;
if ( V_47 == F_29 ( V_48 ) )
return true ;
}
for ( V_48 = 0 ; V_48 < V_51 ; ++ V_48 ) {
if ( V_47 == F_24 ( V_48 ) )
return true ;
if ( V_47 == F_25 ( V_48 ) )
return true ;
if ( V_47 == F_26 ( V_48 ) )
return true ;
if ( V_47 == F_30 ( V_48 ) )
return true ;
if ( V_47 == F_27 ( V_48 ) )
return true ;
}
return false ;
}
static bool F_31 ( struct V_46 * V_10 , unsigned int V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_50 ; ++ V_48 )
if ( V_47 == F_29 ( V_48 ) )
return true ;
for ( V_48 = 0 ; V_48 < V_51 ; ++ V_48 )
if ( V_47 == F_30 ( V_48 ) )
return true ;
return false ;
}
static int F_32 ( struct V_52 * V_53 )
{
struct V_6 * V_7 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
int V_8 ;
V_55 = F_33 ( V_53 -> V_10 . V_58 , L_9 , 0 ) ;
if ( V_55 ) {
F_4 ( & V_53 -> V_10 , L_10 ,
V_11 ) ;
return - V_59 ;
}
V_7 = F_34 ( & V_53 -> V_10 , sizeof( struct V_6 ) ,
V_60 ) ;
if ( ! V_7 )
return - V_61 ;
F_35 ( V_53 , V_7 ) ;
V_57 = F_36 ( V_53 , V_62 , L_11 ) ;
if ( ! V_57 ) {
F_4 ( & V_53 -> V_10 , L_12 , V_11 ) ;
return - V_63 ;
}
V_7 -> V_64 = F_37 ( & V_53 -> V_10 , V_57 ) ;
if ( F_38 ( ( void const V_65 * ) V_7 -> V_64 ) ) {
F_4 ( & V_53 -> V_10 , L_13 ,
V_11 ,
F_39 ( ( void const V_65 * ) V_7 -> V_64 ) ) ;
return F_39 ( ( void const V_65 * ) V_7 -> V_64 ) ;
}
V_7 -> V_34 = F_40 ( & V_53 -> V_10 , V_7 -> V_64 ,
& V_66 ) ;
if ( F_38 ( V_7 -> V_34 ) ) {
F_4 ( & V_53 -> V_10 , L_14 ,
V_11 , F_39 ( V_7 -> V_34 ) ) ;
return F_39 ( V_7 -> V_34 ) ;
}
V_7 -> V_9 = F_41 ( & V_53 -> V_10 , L_15 ) ;
if ( F_38 ( V_7 -> V_9 ) ) {
F_4 ( & V_53 -> V_10 , L_16 ,
V_11 , F_39 ( V_7 -> V_9 ) ) ;
return F_39 ( V_7 -> V_9 ) ;
}
V_7 -> V_14 = F_41 ( & V_53 -> V_10 , L_17 ) ;
if ( F_38 ( V_7 -> V_14 ) ) {
F_4 ( & V_53 -> V_10 , L_18 ,
V_11 , F_39 ( V_7 -> V_14 ) ) ;
return F_39 ( V_7 -> V_14 ) ;
}
V_7 -> V_67 = F_41 ( & V_53 -> V_10 , L_19 ) ;
if ( F_38 ( V_7 -> V_67 ) ) {
F_4 ( & V_53 -> V_10 , L_20 ,
V_11 , F_39 ( V_7 -> V_67 ) ) ;
return F_39 ( V_7 -> V_67 ) ;
}
V_8 = F_3 ( V_7 -> V_67 , V_68 ) ;
if ( V_8 ) {
F_4 ( & V_53 -> V_10 , L_21 ,
V_11 , V_8 ) ;
return V_8 ;
}
F_42 ( & V_53 -> V_10 , L_22 , V_11 ,
F_43 ( V_7 -> V_67 ) ) ;
V_8 = F_6 ( V_7 -> V_67 ) ;
if ( V_8 ) {
F_4 ( & V_53 -> V_10 , L_23 ,
V_11 , V_8 ) ;
return V_8 ;
}
V_8 = F_44 ( & V_53 -> V_10 ,
& V_69 , & V_70 , 1 ) ;
if ( V_8 ) {
F_4 ( & V_53 -> V_10 , L_24 ,
V_11 , V_8 ) ;
goto V_71;
}
V_8 = F_45 ( V_53 ) ;
if ( V_8 ) {
F_4 ( & V_53 -> V_10 , L_25 ,
V_11 , V_8 ) ;
goto V_71;
}
return 0 ;
V_71:
F_7 ( V_7 -> V_67 ) ;
return V_8 ;
}
static int F_46 ( struct V_52 * V_53 )
{
struct V_6 * V_7 = F_47 ( V_53 ) ;
F_7 ( V_7 -> V_67 ) ;
return 0 ;
}
