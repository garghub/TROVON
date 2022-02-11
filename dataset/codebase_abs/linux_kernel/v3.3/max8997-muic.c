static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , bool V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 = 0 ;
if ( V_4 == V_10 ) {
V_9 = F_2 ( V_2 -> V_11 , V_12 ,
V_5 ? V_13 : V_14 ,
V_15 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_16 , L_1 ) ;
goto V_17;
}
}
if ( V_7 -> V_18 )
V_7 -> V_18 ( V_4 , V_5 ) ;
V_17:
return V_9 ;
}
static void F_4 ( struct V_1 * V_2 ,
bool V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_7 -> V_19 )
V_7 -> V_19 ( V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
int V_20 , bool V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 = 0 ;
V_9 = F_2 ( V_2 -> V_11 , V_12 ,
V_5 ? V_21 : V_14 ,
V_15 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_16 , L_1 ) ;
goto V_17;
}
switch ( V_20 ) {
case V_22 :
if ( V_7 -> V_23 )
V_7 -> V_23 ( V_5 ) ;
break;
case V_24 :
if ( V_7 -> V_25 )
V_7 -> V_25 ( V_5 ) ;
break;
default:
break;
}
V_17:
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 ,
bool V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_9 = 0 ;
V_9 = F_2 ( V_2 -> V_11 , V_12 ,
V_5 ? V_26 : V_14 ,
V_15 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_16 , L_1 ) ;
goto V_17;
}
if ( V_7 -> V_27 )
V_7 -> V_27 ( V_5 ) ;
V_17:
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
switch ( V_2 -> V_28 ) {
case V_29 :
V_9 = F_1 ( V_2 , V_10 , false ) ;
break;
case V_30 :
F_4 ( V_2 , false ) ;
break;
case V_31 :
case V_32 :
V_9 = F_1 ( V_2 , V_33 , false ) ;
break;
case V_22 :
case V_24 :
V_9 = F_5 ( V_2 , V_2 -> V_28 , false ) ;
break;
case V_34 :
V_9 = F_6 ( V_2 , false ) ;
break;
default:
break;
}
return V_9 ;
}
static int F_8 ( struct V_1 * V_2 , int V_20 )
{
int V_9 = 0 ;
switch ( V_20 ) {
case V_29 :
V_9 = F_1 ( V_2 , V_10 , true ) ;
break;
case V_30 :
F_4 ( V_2 , true ) ;
break;
case V_31 :
case V_32 :
V_9 = F_1 ( V_2 , V_33 , true ) ;
break;
case V_22 :
case V_24 :
V_9 = F_5 ( V_2 , V_20 , true ) ;
break;
case V_34 :
V_9 = F_6 ( V_2 , true ) ;
break;
case V_35 :
V_9 = F_7 ( V_2 ) ;
break;
default:
break;
}
V_2 -> V_28 = V_20 ;
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 ,
enum V_36 V_37 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_1 V_20 ;
int V_9 ;
V_9 = F_10 ( V_2 -> V_11 , V_38 , & V_20 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_16 , L_2 ) ;
goto V_17;
}
switch ( V_37 ) {
case V_39 :
if ( V_7 -> V_40 )
V_7 -> V_40 ( false , V_37 ) ;
if ( V_2 -> V_41 == V_42 ) {
F_1 ( V_2 ,
V_33 , false ) ;
}
break;
case V_42 :
if ( ( V_20 & V_43 ) == V_35 ) {
F_1 ( V_2 ,
V_33 , true ) ;
}
if ( V_7 -> V_40 )
V_7 -> V_40 ( true , V_37 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
if ( V_7 -> V_40 )
V_7 -> V_40 ( true , V_37 ) ;
break;
default:
break;
}
V_2 -> V_41 = V_37 ;
V_17:
return V_9 ;
}
static void F_11 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_12 ( V_49 ,
struct V_1 , V_50 ) ;
struct V_51 * V_52 =
F_13 ( V_2 -> V_53 -> V_16 ) ;
T_1 V_54 [ 3 ] ;
T_1 V_20 , V_55 ;
int V_56 = V_2 -> V_57 - V_52 -> V_58 ;
int V_9 ;
F_14 ( & V_2 -> V_59 ) ;
V_9 = F_15 ( V_2 -> V_11 , V_38 ,
3 , V_54 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_16 , L_2 ) ;
F_16 ( & V_2 -> V_59 ) ;
return;
}
F_17 ( V_2 -> V_16 , L_3 , V_60 ,
V_54 [ 0 ] , V_54 [ 1 ] ) ;
switch ( V_56 ) {
case V_61 :
V_20 = V_54 [ 0 ] & V_43 ;
V_20 >>= V_62 ;
F_8 ( V_2 , V_20 ) ;
break;
case V_63 :
V_55 = V_54 [ 1 ] & V_64 ;
V_55 >>= V_65 ;
F_9 ( V_2 , V_55 ) ;
break;
default:
F_18 ( V_2 -> V_16 , L_4 ,
V_66 [ V_56 ] . V_67 ) ;
break;
}
F_16 ( & V_2 -> V_59 ) ;
return;
}
static T_2 F_19 ( int V_57 , void * V_68 )
{
struct V_1 * V_2 = V_68 ;
F_17 ( V_2 -> V_16 , L_5 , V_57 ) ;
V_2 -> V_57 = V_57 ;
F_20 ( & V_2 -> V_50 ) ;
return V_69 ;
}
static void F_21 ( struct V_1 * V_2 )
{
int V_9 ;
T_1 V_54 [ 2 ] , V_20 , V_55 ;
V_9 = F_15 ( V_2 -> V_11 , V_38 ,
2 , V_54 ) ;
if ( V_9 ) {
F_3 ( V_2 -> V_16 , L_2 ) ;
return;
}
F_18 ( V_2 -> V_16 , L_6 ,
V_54 [ 0 ] , V_54 [ 1 ] ) ;
V_20 = V_54 [ 0 ] & V_43 ;
V_20 >>= V_62 ;
V_55 = V_54 [ 1 ] & V_64 ;
V_55 >>= V_65 ;
F_8 ( V_2 , V_20 ) ;
F_9 ( V_2 , V_55 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_7 -> V_71 ; V_70 ++ ) {
F_23 ( V_2 -> V_11 , V_7 -> V_72 [ V_70 ] . V_73 ,
V_7 -> V_72 [ V_70 ] . V_68 ) ;
}
}
static int T_3 F_24 ( struct V_74 * V_75 )
{
struct V_76 * V_53 = F_25 ( V_75 -> V_16 . V_77 ) ;
struct V_51 * V_52 = F_13 ( V_53 -> V_16 ) ;
struct V_1 * V_2 ;
int V_9 , V_70 ;
V_2 = F_26 ( sizeof( struct V_1 ) , V_78 ) ;
if ( ! V_2 ) {
F_3 ( & V_75 -> V_16 , L_7 ) ;
V_9 = - V_79 ;
goto V_80;
}
if ( ! V_52 -> V_8 ) {
F_3 ( & V_75 -> V_16 , L_8 ) ;
V_9 = - V_81 ;
goto V_82;
}
V_2 -> V_8 = V_52 -> V_8 ;
V_2 -> V_16 = & V_75 -> V_16 ;
V_2 -> V_53 = V_53 ;
V_2 -> V_11 = V_53 -> V_11 ;
F_27 ( V_75 , V_2 ) ;
F_28 ( & V_2 -> V_59 ) ;
F_29 ( & V_2 -> V_50 , F_11 ) ;
for ( V_70 = 0 ; V_70 < F_30 ( V_66 ) ; V_70 ++ ) {
struct V_83 * V_84 = & V_66 [ V_70 ] ;
V_9 = F_31 ( V_52 -> V_58 + V_84 -> V_57 ,
NULL , F_19 ,
0 , V_84 -> V_67 ,
V_2 ) ;
if ( V_9 ) {
F_3 ( & V_75 -> V_16 ,
L_9
L_10 ,
V_84 -> V_57 , V_9 ) ;
for ( V_70 = V_70 - 1 ; V_70 >= 0 ; V_70 -- )
F_32 ( V_84 -> V_57 , V_2 ) ;
goto V_85;
}
}
F_22 ( V_2 ) ;
F_21 ( V_2 ) ;
return V_9 ;
V_85:
V_82:
F_33 ( V_2 ) ;
V_80:
return V_9 ;
}
static int T_4 F_34 ( struct V_74 * V_75 )
{
struct V_1 * V_2 = F_35 ( V_75 ) ;
struct V_51 * V_52 =
F_13 ( V_2 -> V_53 -> V_16 ) ;
int V_70 ;
for ( V_70 = 0 ; V_70 < F_30 ( V_66 ) ; V_70 ++ )
F_32 ( V_52 -> V_58 + V_66 [ V_70 ] . V_57 , V_2 ) ;
F_36 ( & V_2 -> V_50 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int T_5 F_37 ( void )
{
return F_38 ( & V_86 ) ;
}
static void T_6 F_39 ( void )
{
F_40 ( & V_86 ) ;
}
