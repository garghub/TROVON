int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
void T_2 * V_4 = V_2 -> V_5 ;
T_1 V_6 , V_7 ;
int V_8 ;
V_7 = V_3 | V_9 | V_10 |
V_11 ;
V_8 = F_2 ( V_4 + V_12 , V_6 ,
( V_7 == ( V_6 & V_7 ) ) , 100 , 20000 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_13 , L_1 ) ;
return V_8 ;
}
V_8 = F_2 ( V_4 + V_14 , V_6 ,
( V_6 & V_15 ) , 100 , 10000 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_13 , L_2 ) ;
return V_8 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_16 ;
int V_8 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_17 ; V_16 ++ ) {
V_8 = F_5 ( V_2 -> V_18 [ V_16 ] ) ;
if ( V_8 )
goto V_19;
}
return 0 ;
V_19:
for (; V_16 > 0 ; V_16 -- )
F_6 ( V_2 -> V_18 [ V_16 - 1 ] ) ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_17 ; V_16 ++ )
F_6 ( V_2 -> V_18 [ V_16 ] ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_16 ;
int V_8 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_17 ; V_16 ++ ) {
V_8 = F_9 ( V_2 -> V_18 [ V_16 ] ) ;
if ( V_8 )
goto V_20;
}
return 0 ;
V_20:
for (; V_16 > 0 ; V_16 -- )
F_10 ( V_2 -> V_18 [ V_16 - 1 ] ) ;
return V_8 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_17 ; V_16 ++ )
F_10 ( V_2 -> V_18 [ V_16 ] ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_8 = 0 ;
V_8 = F_13 ( V_2 -> V_21 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_13 , L_3 ) ;
goto V_22;
}
V_8 = F_14 ( V_2 -> V_23 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_13 , L_4 ) ;
goto V_24;
}
V_8 = F_14 ( V_2 -> V_25 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_13 , L_5 ) ;
goto V_26;
}
V_8 = F_4 ( V_2 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_13 , L_6 ) ;
goto V_27;
}
V_8 = F_8 ( V_2 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_13 , L_7 ) ;
goto V_28;
}
return 0 ;
V_28:
F_7 ( V_2 ) ;
V_27:
F_15 ( V_2 -> V_25 ) ;
V_26:
F_15 ( V_2 -> V_23 ) ;
V_24:
F_16 ( V_2 -> V_21 ) ;
V_22:
return V_8 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_23 ) ;
F_15 ( V_2 -> V_25 ) ;
F_16 ( V_2 -> V_21 ) ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> V_5 , V_29 , V_30 ) ;
F_20 ( 1 ) ;
F_21 ( V_2 -> V_5 , V_29 , V_30 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_33 ;
V_32 -> V_34 = F_23 ( V_2 -> V_13 ) ;
if ( F_24 ( V_32 -> V_34 ) ) {
F_3 ( V_2 -> V_13 , L_8 ) ;
return F_25 ( V_32 -> V_34 ) ;
}
V_32 -> V_35 =
F_26 ( V_32 -> V_34 , L_9 ) ;
if ( F_24 ( V_32 -> V_35 ) ) {
F_3 ( V_2 -> V_13 , L_10 ) ;
return F_25 ( V_32 -> V_35 ) ;
}
V_32 -> V_36 =
F_26 ( V_32 -> V_34 , L_11 ) ;
if ( F_24 ( V_32 -> V_36 ) ) {
F_3 ( V_2 -> V_13 , L_12 ) ;
return F_25 ( V_32 -> V_36 ) ;
}
return 0 ;
}
static int F_27 ( struct V_37 * V_38 , struct V_1 * V_2 )
{
struct V_39 * V_40 = V_38 -> V_13 . V_41 ;
struct V_31 * V_32 = & V_2 -> V_33 ;
struct V_42 * V_13 = & V_38 -> V_13 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
int V_16 ;
int V_8 ;
V_2 -> V_21 = F_28 ( & V_38 -> V_13 , L_13 ) ;
if ( F_24 ( V_2 -> V_21 ) ) {
F_3 ( V_13 , L_14 ) ;
return F_25 ( V_2 -> V_21 ) ;
}
V_2 -> V_23 = F_29 ( V_13 , L_15 ) ;
if ( F_24 ( V_2 -> V_23 ) ) {
F_3 ( V_13 , L_16 ) ;
return F_25 ( V_2 -> V_23 ) ;
}
V_2 -> V_25 = F_29 ( V_13 , L_17 ) ;
if ( F_24 ( V_2 -> V_25 ) ) {
if ( F_25 ( V_2 -> V_25 ) == - V_47 )
return - V_47 ;
V_2 -> V_25 = NULL ;
}
V_2 -> V_17 = F_30 ( V_40 ,
L_18 , L_19 ) ;
if ( V_2 -> V_17 > 0 ) {
V_2 -> V_18 = F_31 ( V_13 , V_2 -> V_17 ,
sizeof( * V_2 -> V_18 ) , V_48 ) ;
if ( ! V_2 -> V_18 )
return - V_49 ;
} else {
V_2 -> V_17 = 0 ;
}
for ( V_16 = 0 ; V_16 < V_2 -> V_17 ; V_16 ++ ) {
V_2 -> V_18 [ V_16 ] = F_32 ( V_13 , V_40 , V_16 ) ;
if ( F_24 ( V_2 -> V_18 [ V_16 ] ) ) {
F_3 ( V_13 , L_20 , V_16 ) ;
return F_25 ( V_2 -> V_18 [ V_16 ] ) ;
}
}
V_46 = F_33 ( V_38 , V_50 , L_21 ) ;
V_2 -> V_5 = F_34 ( V_13 , V_46 ) ;
if ( F_24 ( V_2 -> V_5 ) )
return F_25 ( V_2 -> V_5 ) ;
V_2 -> V_51 = F_35 ( V_13 ) ;
if ( V_2 -> V_51 == V_52 ) {
F_3 ( V_13 , L_22 ) ;
return - V_53 ;
}
if ( V_2 -> V_51 == V_54 )
return 0 ;
V_8 = F_36 ( V_2 , V_40 ) ;
if ( V_8 )
return V_8 ;
if ( V_2 -> V_51 != V_55 )
return 0 ;
V_44 = F_28 ( & V_38 -> V_13 , L_23 ) ;
if ( F_24 ( V_44 ) ) {
F_3 ( V_13 , L_24 ) ;
return F_25 ( V_44 ) ;
}
V_32 -> V_44 = V_44 ;
V_32 -> V_56 = F_37 ( V_40 , L_25 ) ;
V_32 -> V_57 =
F_37 ( V_40 , L_26 ) ;
if ( F_37 ( V_40 , L_27 ) ) {
V_32 -> V_58 = F_38 ( V_2 -> V_13 , 0 ) ;
if ( F_24 ( V_32 -> V_58 ) ) {
F_3 ( V_2 -> V_13 , L_28 ) ;
return - V_47 ;
}
if ( V_32 -> V_57 ) {
V_8 = F_22 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
}
F_39 ( V_13 , L_29 ,
V_2 -> V_51 , V_32 -> V_56 ) ;
return 0 ;
}
static int F_40 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_13 . V_41 ;
struct V_42 * V_13 = & V_38 -> V_13 ;
struct V_1 * V_2 ;
int V_8 = - V_49 ;
V_2 = F_41 ( V_13 , sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return - V_49 ;
V_8 = F_42 ( V_13 , F_43 ( 32 ) ) ;
if ( V_8 ) {
F_3 ( V_13 , L_30 ) ;
return - V_59 ;
}
F_44 ( V_38 , V_2 ) ;
V_2 -> V_13 = V_13 ;
V_8 = F_27 ( V_38 , V_2 ) ;
if ( V_8 )
return V_8 ;
F_45 ( V_13 ) ;
F_46 ( V_13 ) ;
F_47 ( V_13 ) ;
V_8 = F_12 ( V_2 ) ;
if ( V_8 )
goto V_60;
F_18 ( V_2 ) ;
if ( F_48 ( V_61 ) )
V_2 -> V_51 = V_62 ;
else if ( F_48 ( V_63 ) )
V_2 -> V_51 = V_54 ;
V_2 -> V_64 = ! ( V_2 -> V_51 == V_54 ) ;
switch ( V_2 -> V_51 ) {
case V_54 :
V_8 = F_49 ( V_2 ) ;
if ( V_8 ) {
F_3 ( V_13 , L_31 ) ;
goto V_65;
}
break;
case V_62 :
V_8 = F_50 ( V_2 , V_40 ) ;
if ( V_8 ) {
F_3 ( V_13 , L_32 ) ;
goto V_65;
}
break;
case V_55 :
V_8 = F_49 ( V_2 ) ;
if ( V_8 ) {
F_3 ( V_13 , L_31 ) ;
goto V_65;
}
V_8 = F_50 ( V_2 , V_40 ) ;
if ( V_8 ) {
F_3 ( V_13 , L_32 ) ;
goto V_66;
}
F_51 ( V_2 ) ;
break;
default:
F_3 ( V_13 , L_33 , V_2 -> V_51 ) ;
V_8 = - V_53 ;
goto V_65;
}
return 0 ;
V_66:
F_52 ( V_2 ) ;
V_65:
F_17 ( V_2 ) ;
V_60:
F_53 ( V_13 ) ;
F_54 ( V_13 ) ;
return V_8 ;
}
static int F_55 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_56 ( V_38 ) ;
switch ( V_2 -> V_51 ) {
case V_54 :
F_52 ( V_2 ) ;
break;
case V_62 :
F_57 ( V_2 ) ;
break;
case V_55 :
F_58 ( V_2 ) ;
F_52 ( V_2 ) ;
F_57 ( V_2 ) ;
break;
default:
return - V_53 ;
}
F_17 ( V_2 ) ;
F_53 ( & V_38 -> V_13 ) ;
F_54 ( & V_38 -> V_13 ) ;
return 0 ;
}
static int T_3 F_59 ( struct V_42 * V_13 )
{
struct V_37 * V_38 = F_60 ( V_13 ) ;
struct V_1 * V_2 = F_56 ( V_38 ) ;
F_61 ( V_13 , L_34 , V_67 ) ;
if ( ! V_2 -> V_64 )
return 0 ;
F_62 ( V_2 , true ) ;
F_11 ( V_2 ) ;
F_15 ( V_2 -> V_23 ) ;
F_15 ( V_2 -> V_25 ) ;
F_63 ( V_2 ) ;
return 0 ;
}
static int T_3 F_64 ( struct V_42 * V_13 )
{
struct V_37 * V_38 = F_60 ( V_13 ) ;
struct V_1 * V_2 = F_56 ( V_38 ) ;
F_61 ( V_13 , L_34 , V_67 ) ;
if ( ! V_2 -> V_64 )
return 0 ;
F_65 ( V_2 ) ;
F_14 ( V_2 -> V_23 ) ;
F_14 ( V_2 -> V_25 ) ;
F_8 ( V_2 ) ;
F_66 ( V_2 ) ;
return 0 ;
}
