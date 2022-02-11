static T_1 F_1 ( struct V_1 T_2 * V_2 )
{
return V_3 | V_4 ;
}
static T_1 F_2 ( struct V_1 T_2 * V_2 ,
T_1 V_5 )
{
return ( V_5 != ( V_3 | V_4 ) ) ? 1 : 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_8 = F_4 ( V_2 ) ;
memcpy ( V_7 , V_8 -> V_9 . V_7 , sizeof( * V_7 ) ) ;
return 0 ;
}
static int F_5 ( struct V_8 * V_8 ,
struct V_6 * V_7 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
bool V_10 = false ;
int V_11 , V_12 = 0 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
switch ( V_7 -> V_14 [ V_11 ] ) {
case V_15 :
break;
case V_16 :
V_10 = true ;
V_12 += V_7 -> V_17 [ V_11 ] ;
break;
default:
F_6 ( V_2 , L_1 ) ;
return - V_18 ;
}
if ( V_7 -> V_19 [ V_11 ] >= V_13 ) {
F_6 ( V_2 , L_2 ) ;
return - V_18 ;
}
}
if ( V_10 && V_12 != 100 ) {
F_6 ( V_2 , L_3 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_7 ( struct V_8 * V_8 ,
T_1 * V_19 )
{
char V_20 [ V_21 ] ;
int V_11 ;
F_8 ( V_20 , V_8 -> V_22 ) ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
F_9 ( V_20 , V_11 , V_19 [ V_11 ] ) ;
return F_10 ( V_8 -> V_23 -> V_24 , F_11 ( V_25 ) ,
V_20 ) ;
}
static bool F_12 ( T_1 * V_19 , T_1 V_26 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
if ( V_19 [ V_11 ] == V_26 )
return true ;
return false ;
}
static int F_13 ( struct V_8 * V_8 ,
T_1 * V_27 , T_1 * V_28 )
{
struct V_23 * V_23 = V_8 -> V_23 ;
char V_29 [ V_30 ] ;
int V_31 , V_11 ;
F_14 ( V_29 , V_8 -> V_22 , 0 , 0 ) ;
V_31 = F_15 ( V_23 -> V_24 , F_11 ( V_32 ) , V_29 ) ;
if ( V_31 )
return V_31 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
T_1 V_26 = V_27 [ V_11 ] ;
if ( ! F_12 ( V_28 , V_26 ) )
F_16 ( V_29 , V_26 , 0 ) ;
}
return F_10 ( V_23 -> V_24 , F_11 ( V_32 ) , V_29 ) ;
}
static int F_17 ( struct V_8 * V_8 ,
struct V_6 * V_7 )
{
bool V_33 = F_18 ( V_8 ) ;
struct V_6 * V_34 = V_8 -> V_9 . V_7 ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_31 ;
V_31 = F_19 ( V_8 , V_2 -> V_35 ,
V_7 -> V_19 , V_33 ,
V_8 -> V_9 . V_36 ) ;
if ( V_31 ) {
F_6 ( V_2 , L_4 ) ;
return V_31 ;
}
V_31 = F_7 ( V_8 , V_7 -> V_19 ) ;
if ( V_31 ) {
F_6 ( V_2 , L_5 ) ;
goto V_37;
}
V_31 = F_13 ( V_8 , V_34 -> V_19 ,
V_7 -> V_19 ) ;
if ( V_31 )
F_20 ( V_2 , L_6 ) ;
return 0 ;
V_37:
F_13 ( V_8 , V_7 -> V_19 , V_34 -> V_19 ) ;
return V_31 ;
}
static int F_21 ( struct V_8 * V_8 ,
struct V_6 * V_7 )
{
struct V_6 * V_34 = V_8 -> V_9 . V_7 ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_11 , V_31 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
bool V_38 = V_7 -> V_14 [ V_11 ] == V_16 ;
T_1 V_39 = V_7 -> V_17 [ V_11 ] ;
V_31 = F_22 ( V_8 ,
V_40 , V_11 ,
0 , V_38 , V_39 ) ;
if ( V_31 ) {
F_6 ( V_2 , L_7 ,
V_11 ) ;
goto V_41;
}
}
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
V_31 = F_23 ( V_8 , V_11 ,
V_7 -> V_19 [ V_11 ] ) ;
if ( V_31 ) {
F_6 ( V_2 , L_8 , V_11 ,
V_7 -> V_19 [ V_11 ] ) ;
goto V_42;
}
}
V_31 = F_17 ( V_8 , V_7 ) ;
if ( V_31 )
goto V_43;
return 0 ;
V_43:
V_11 = V_13 ;
V_42:
for ( V_11 -- ; V_11 >= 0 ; V_11 -- )
F_23 ( V_8 , V_11 , V_34 -> V_19 [ V_11 ] ) ;
V_11 = V_13 ;
V_41:
for ( V_11 -- ; V_11 >= 0 ; V_11 -- ) {
bool V_38 = V_34 -> V_14 [ V_11 ] == V_16 ;
T_1 V_39 = V_34 -> V_17 [ V_11 ] ;
V_31 = F_22 ( V_8 ,
V_40 , V_11 ,
0 , V_38 , V_39 ) ;
}
return V_31 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_8 = F_4 ( V_2 ) ;
int V_31 ;
V_31 = F_5 ( V_8 , V_7 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_21 ( V_8 , V_7 ) ;
if ( V_31 )
return V_31 ;
memcpy ( V_8 -> V_9 . V_7 , V_7 , sizeof( * V_7 ) ) ;
V_8 -> V_9 . V_7 -> V_44 = V_13 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_8 * V_8 = F_4 ( V_2 ) ;
memcpy ( V_46 , V_8 -> V_9 . V_46 , sizeof( * V_46 ) ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_8 * V_8 = F_4 ( V_2 ) ;
struct V_45 * V_47 = V_8 -> V_9 . V_46 ;
int V_31 , V_11 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
V_31 = F_27 ( V_8 ,
V_40 ,
V_11 , 0 ,
V_46 -> V_48 [ V_11 ] ) ;
if ( V_31 ) {
F_6 ( V_2 , L_9 , V_11 ) ;
goto V_49;
}
}
memcpy ( V_8 -> V_9 . V_46 , V_46 , sizeof( * V_46 ) ) ;
return 0 ;
V_49:
for ( V_11 -- ; V_11 >= 0 ; V_11 -- )
F_27 ( V_8 ,
V_40 ,
V_11 , 0 , V_47 -> V_48 [ V_11 ] ) ;
return V_31 ;
}
static int F_28 ( struct V_8 * V_8 ,
T_1 V_50 )
{
struct V_23 * V_23 = V_8 -> V_23 ;
struct V_51 * V_52 = V_8 -> V_9 . V_36 ;
char V_53 [ V_54 ] ;
int V_31 ;
F_29 ( V_53 , V_8 -> V_22 ,
V_55 , V_50 ) ;
V_31 = F_15 ( V_23 -> V_24 , F_11 ( V_56 ) , V_53 ) ;
if ( V_31 )
return V_31 ;
V_52 -> V_57 [ V_50 ] = F_30 ( V_53 ) ;
V_52 -> V_58 [ V_50 ] = F_31 ( V_53 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_51 * V_36 )
{
struct V_8 * V_8 = F_4 ( V_2 ) ;
int V_31 , V_11 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
V_31 = F_28 ( V_8 , V_11 ) ;
if ( V_31 ) {
F_6 ( V_2 , L_10 ,
V_11 ) ;
return V_31 ;
}
}
memcpy ( V_36 , V_8 -> V_9 . V_36 , sizeof( * V_36 ) ) ;
return 0 ;
}
static int F_33 ( struct V_8 * V_8 ,
struct V_51 * V_36 )
{
char V_59 [ V_60 ] ;
F_34 ( V_59 , V_8 -> V_22 ) ;
F_35 ( V_59 , V_8 -> V_61 . V_62 ) ;
F_36 ( V_59 , V_8 -> V_61 . V_63 ) ;
F_37 ( V_59 , V_36 -> V_64 ) ;
return F_10 ( V_8 -> V_23 -> V_24 , F_11 ( V_65 ) ,
V_59 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_51 * V_36 )
{
struct V_8 * V_8 = F_4 ( V_2 ) ;
bool V_33 = F_18 ( V_8 ) ;
int V_31 ;
if ( V_33 && V_36 -> V_64 ) {
F_6 ( V_2 , L_11 ) ;
return - V_18 ;
}
V_31 = F_19 ( V_8 , V_2 -> V_35 ,
V_8 -> V_9 . V_7 -> V_19 ,
V_33 , V_36 ) ;
if ( V_31 ) {
F_6 ( V_2 , L_12 ) ;
return V_31 ;
}
V_31 = F_33 ( V_8 , V_36 ) ;
if ( V_31 ) {
F_6 ( V_2 , L_13 ) ;
goto V_66;
}
memcpy ( V_8 -> V_9 . V_36 , V_36 , sizeof( * V_36 ) ) ;
V_8 -> V_9 . V_36 -> V_67 = V_13 ;
return 0 ;
V_66:
F_19 ( V_8 , V_2 -> V_35 ,
V_8 -> V_9 . V_7 -> V_19 , V_33 ,
V_8 -> V_9 . V_36 ) ;
return V_31 ;
}
static int F_39 ( struct V_8 * V_8 )
{
V_8 -> V_9 . V_7 = F_40 ( sizeof( * V_8 -> V_9 . V_7 ) ,
V_68 ) ;
if ( ! V_8 -> V_9 . V_7 )
return - V_69 ;
V_8 -> V_9 . V_7 -> V_44 = V_13 ;
return 0 ;
}
static void F_41 ( struct V_8 * V_8 )
{
F_42 ( V_8 -> V_9 . V_7 ) ;
}
static int F_43 ( struct V_8 * V_8 )
{
int V_11 ;
V_8 -> V_9 . V_46 = F_44 ( sizeof( * V_8 -> V_9 . V_46 ) ,
V_68 ) ;
if ( ! V_8 -> V_9 . V_46 )
return - V_69 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
V_8 -> V_9 . V_46 -> V_48 [ V_11 ] = V_70 ;
return 0 ;
}
static void F_45 ( struct V_8 * V_8 )
{
F_42 ( V_8 -> V_9 . V_46 ) ;
}
static int F_46 ( struct V_8 * V_8 )
{
V_8 -> V_9 . V_36 = F_40 ( sizeof( * V_8 -> V_9 . V_36 ) ,
V_68 ) ;
if ( ! V_8 -> V_9 . V_36 )
return - V_69 ;
V_8 -> V_9 . V_36 -> V_67 = V_13 ;
return 0 ;
}
static void F_47 ( struct V_8 * V_8 )
{
F_42 ( V_8 -> V_9 . V_36 ) ;
}
int F_48 ( struct V_8 * V_8 )
{
int V_31 ;
V_31 = F_39 ( V_8 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_43 ( V_8 ) ;
if ( V_31 )
goto V_71;
V_31 = F_46 ( V_8 ) ;
if ( V_31 )
goto V_72;
V_8 -> V_2 -> V_73 = & V_74 ;
return 0 ;
V_72:
F_45 ( V_8 ) ;
V_71:
F_41 ( V_8 ) ;
return V_31 ;
}
void F_49 ( struct V_8 * V_8 )
{
F_47 ( V_8 ) ;
F_45 ( V_8 ) ;
F_41 ( V_8 ) ;
}
