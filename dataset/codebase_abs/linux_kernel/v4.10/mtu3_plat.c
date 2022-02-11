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
V_8 = F_4 ( V_2 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_13 , L_5 ) ;
goto V_25;
}
V_8 = F_8 ( V_2 ) ;
if ( V_8 ) {
F_3 ( V_2 -> V_13 , L_6 ) ;
goto V_26;
}
return 0 ;
V_26:
F_7 ( V_2 ) ;
V_25:
F_15 ( V_2 -> V_23 ) ;
V_24:
F_16 ( V_2 -> V_21 ) ;
V_22:
return V_8 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_23 ) ;
F_16 ( V_2 -> V_21 ) ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> V_5 , V_27 , V_28 ) ;
F_20 ( 1 ) ;
F_21 ( V_2 -> V_5 , V_27 , V_28 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_31 ;
V_30 -> V_32 = F_23 ( V_2 -> V_13 ) ;
if ( F_24 ( V_30 -> V_32 ) ) {
F_3 ( V_2 -> V_13 , L_7 ) ;
return F_25 ( V_30 -> V_32 ) ;
}
V_30 -> V_33 =
F_26 ( V_30 -> V_32 , L_8 ) ;
if ( F_24 ( V_30 -> V_33 ) ) {
F_3 ( V_2 -> V_13 , L_9 ) ;
return F_25 ( V_30 -> V_33 ) ;
}
V_30 -> V_34 =
F_26 ( V_30 -> V_32 , L_10 ) ;
if ( F_24 ( V_30 -> V_34 ) ) {
F_3 ( V_2 -> V_13 , L_11 ) ;
return F_25 ( V_30 -> V_34 ) ;
}
return 0 ;
}
static int F_27 ( struct V_35 * V_36 , struct V_1 * V_2 )
{
struct V_37 * V_38 = V_36 -> V_13 . V_39 ;
struct V_29 * V_30 = & V_2 -> V_31 ;
struct V_40 * V_13 = & V_36 -> V_13 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
int V_16 ;
int V_8 ;
V_2 -> V_17 = F_28 ( V_38 ,
L_12 , L_13 ) ;
if ( V_2 -> V_17 > 0 ) {
V_2 -> V_18 = F_29 ( V_13 , V_2 -> V_17 ,
sizeof( * V_2 -> V_18 ) , V_45 ) ;
if ( ! V_2 -> V_18 )
return - V_46 ;
} else {
V_2 -> V_17 = 0 ;
}
for ( V_16 = 0 ; V_16 < V_2 -> V_17 ; V_16 ++ ) {
V_2 -> V_18 [ V_16 ] = F_30 ( V_13 , V_38 , V_16 ) ;
if ( F_24 ( V_2 -> V_18 [ V_16 ] ) ) {
F_3 ( V_13 , L_14 , V_16 ) ;
return F_25 ( V_2 -> V_18 [ V_16 ] ) ;
}
}
V_44 = F_31 ( V_36 , V_47 , L_15 ) ;
V_2 -> V_5 = F_32 ( V_13 , V_44 ) ;
if ( F_24 ( V_2 -> V_5 ) ) {
F_3 ( V_13 , L_16 ) ;
return F_25 ( V_2 -> V_5 ) ;
}
V_2 -> V_21 = F_33 ( & V_36 -> V_13 , L_17 ) ;
if ( F_24 ( V_2 -> V_21 ) ) {
F_3 ( V_13 , L_18 ) ;
return F_25 ( V_2 -> V_21 ) ;
}
V_2 -> V_23 = F_34 ( V_13 , L_19 ) ;
if ( F_24 ( V_2 -> V_23 ) ) {
F_3 ( V_13 , L_20 ) ;
return F_25 ( V_2 -> V_23 ) ;
}
V_2 -> V_48 = F_35 ( V_13 ) ;
if ( V_2 -> V_48 == V_49 ) {
F_3 ( V_13 , L_21 ) ;
return - V_50 ;
}
if ( V_2 -> V_48 == V_51 )
return 0 ;
V_8 = F_36 ( V_2 , V_38 ) ;
if ( V_8 )
return V_8 ;
if ( V_2 -> V_48 != V_52 )
return 0 ;
V_42 = F_33 ( & V_36 -> V_13 , L_22 ) ;
if ( F_24 ( V_42 ) ) {
F_3 ( V_13 , L_23 ) ;
return F_25 ( V_42 ) ;
}
V_30 -> V_42 = V_42 ;
V_30 -> V_53 = F_37 ( V_38 , L_24 ) ;
V_30 -> V_54 =
F_37 ( V_38 , L_25 ) ;
if ( F_37 ( V_38 , L_26 ) ) {
V_30 -> V_55 = F_38 ( V_2 -> V_13 , 0 ) ;
if ( F_24 ( V_30 -> V_55 ) ) {
F_3 ( V_2 -> V_13 , L_27 ) ;
return - V_56 ;
}
if ( V_30 -> V_54 ) {
V_8 = F_22 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
}
F_39 ( V_13 , L_28 ,
V_2 -> V_48 , V_30 -> V_53 ) ;
return 0 ;
}
static int F_40 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_13 . V_39 ;
struct V_40 * V_13 = & V_36 -> V_13 ;
struct V_1 * V_2 ;
int V_8 = - V_46 ;
V_2 = F_41 ( V_13 , sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return - V_46 ;
V_8 = F_42 ( V_13 , F_43 ( 32 ) ) ;
if ( V_8 ) {
F_3 ( V_13 , L_29 ) ;
return - V_57 ;
}
F_44 ( V_36 , V_2 ) ;
V_2 -> V_13 = V_13 ;
V_8 = F_27 ( V_36 , V_2 ) ;
if ( V_8 )
return V_8 ;
F_45 ( V_13 ) ;
F_46 ( V_13 ) ;
F_47 ( V_13 ) ;
V_8 = F_12 ( V_2 ) ;
if ( V_8 )
goto V_58;
F_18 ( V_2 ) ;
if ( F_48 ( V_59 ) )
V_2 -> V_48 = V_60 ;
else if ( F_48 ( V_61 ) )
V_2 -> V_48 = V_51 ;
V_2 -> V_62 = ! ( V_2 -> V_48 == V_51 ) ;
switch ( V_2 -> V_48 ) {
case V_51 :
V_8 = F_49 ( V_2 ) ;
if ( V_8 ) {
F_3 ( V_13 , L_30 ) ;
goto V_63;
}
break;
case V_60 :
V_8 = F_50 ( V_2 , V_38 ) ;
if ( V_8 ) {
F_3 ( V_13 , L_31 ) ;
goto V_63;
}
break;
case V_52 :
V_8 = F_49 ( V_2 ) ;
if ( V_8 ) {
F_3 ( V_13 , L_30 ) ;
goto V_63;
}
V_8 = F_50 ( V_2 , V_38 ) ;
if ( V_8 ) {
F_3 ( V_13 , L_31 ) ;
goto V_64;
}
F_51 ( V_2 ) ;
break;
default:
F_3 ( V_13 , L_32 , V_2 -> V_48 ) ;
V_8 = - V_50 ;
goto V_63;
}
return 0 ;
V_64:
F_52 ( V_2 ) ;
V_63:
F_17 ( V_2 ) ;
V_58:
F_53 ( V_13 ) ;
F_54 ( V_13 ) ;
return V_8 ;
}
static int F_55 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_56 ( V_36 ) ;
switch ( V_2 -> V_48 ) {
case V_51 :
F_52 ( V_2 ) ;
break;
case V_60 :
F_57 ( V_2 ) ;
break;
case V_52 :
F_58 ( V_2 ) ;
F_52 ( V_2 ) ;
F_57 ( V_2 ) ;
break;
default:
return - V_50 ;
}
F_17 ( V_2 ) ;
F_53 ( & V_36 -> V_13 ) ;
F_54 ( & V_36 -> V_13 ) ;
return 0 ;
}
static int T_3 F_59 ( struct V_40 * V_13 )
{
struct V_35 * V_36 = F_60 ( V_13 ) ;
struct V_1 * V_2 = F_56 ( V_36 ) ;
F_61 ( V_13 , L_33 , V_65 ) ;
if ( ! V_2 -> V_62 )
return 0 ;
F_62 ( V_2 , true ) ;
F_11 ( V_2 ) ;
F_15 ( V_2 -> V_23 ) ;
F_63 ( V_2 ) ;
return 0 ;
}
static int T_3 F_64 ( struct V_40 * V_13 )
{
struct V_35 * V_36 = F_60 ( V_13 ) ;
struct V_1 * V_2 = F_56 ( V_36 ) ;
F_61 ( V_13 , L_33 , V_65 ) ;
if ( ! V_2 -> V_62 )
return 0 ;
F_65 ( V_2 ) ;
F_14 ( V_2 -> V_23 ) ;
F_8 ( V_2 ) ;
F_66 ( V_2 ) ;
return 0 ;
}
