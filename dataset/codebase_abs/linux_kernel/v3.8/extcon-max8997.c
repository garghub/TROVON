static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , bool V_5 )
{
int V_6 = 0 ;
if ( V_4 == V_7 ) {
V_6 = F_2 ( V_2 -> V_8 , V_9 ,
V_5 ? V_10 : V_11 ,
V_12 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_13 , L_1 ) ;
goto V_14;
}
}
switch ( V_4 ) {
case V_7 :
F_4 ( V_2 -> V_15 , L_2 , V_5 ) ;
break;
case V_16 :
F_4 ( V_2 -> V_15 , L_3 , V_5 ) ;
break;
default:
V_6 = - V_17 ;
break;
}
V_14:
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 ,
int V_18 , bool V_5 )
{
int V_6 = 0 ;
V_6 = F_2 ( V_2 -> V_8 , V_9 ,
V_5 ? V_19 : V_11 ,
V_12 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_13 , L_1 ) ;
goto V_14;
}
switch ( V_18 ) {
case V_20 :
F_4 ( V_2 -> V_15 , L_4 , V_5 ) ;
break;
case V_21 :
F_4 ( V_2 -> V_15 , L_5 , V_5 ) ;
break;
default:
V_6 = - V_17 ;
break;
}
V_14:
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 ,
bool V_5 )
{
int V_6 = 0 ;
V_6 = F_2 ( V_2 -> V_8 , V_9 ,
V_5 ? V_22 : V_11 ,
V_12 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_13 , L_1 ) ;
goto V_14;
}
F_4 ( V_2 -> V_15 , L_6 , V_5 ) ;
V_14:
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
switch ( V_2 -> V_23 ) {
case V_24 :
V_6 = F_1 ( V_2 , V_7 , false ) ;
break;
case V_25 :
F_4 ( V_2 -> V_15 , L_7 , false ) ;
break;
case V_26 :
case V_27 :
V_6 = F_1 ( V_2 , V_16 , false ) ;
break;
case V_20 :
case V_21 :
V_6 = F_5 ( V_2 , V_2 -> V_23 , false ) ;
break;
case V_28 :
V_6 = F_6 ( V_2 , false ) ;
break;
default:
break;
}
return V_6 ;
}
static int F_8 ( struct V_1 * V_2 , int V_18 )
{
int V_6 = 0 ;
switch ( V_18 ) {
case V_24 :
V_6 = F_1 ( V_2 , V_7 , true ) ;
break;
case V_25 :
F_4 ( V_2 -> V_15 , L_7 , true ) ;
break;
case V_26 :
case V_27 :
V_6 = F_1 ( V_2 , V_16 , true ) ;
break;
case V_20 :
case V_21 :
V_6 = F_5 ( V_2 , V_18 , true ) ;
break;
case V_28 :
V_6 = F_6 ( V_2 , true ) ;
break;
case V_29 :
V_6 = F_7 ( V_2 ) ;
break;
default:
V_6 = - V_17 ;
goto V_14;
}
V_2 -> V_23 = V_18 ;
V_14:
return V_6 ;
}
static int F_9 (
struct V_1 * V_2 )
{
switch ( V_2 -> V_30 ) {
case V_31 :
F_4 ( V_2 -> V_15 , L_3 , false ) ;
break;
case V_32 :
F_4 ( V_2 -> V_15 , L_8 , false ) ;
break;
case V_33 :
F_4 ( V_2 -> V_15 , L_9 , false ) ;
break;
case V_34 :
F_4 ( V_2 -> V_15 , L_10 , false ) ;
break;
case V_35 :
F_4 ( V_2 -> V_15 , L_11 , false ) ;
break;
default:
return - V_17 ;
break;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_36 V_37 )
{
T_1 V_18 ;
int V_6 ;
V_6 = F_11 ( V_2 -> V_8 , V_38 , & V_18 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_13 , L_12 ) ;
goto V_14;
}
switch ( V_37 ) {
case V_39 :
V_6 = F_9 ( V_2 ) ;
break;
case V_31 :
if ( ( V_18 & V_40 ) == V_29 ) {
F_1 ( V_2 ,
V_16 , true ) ;
}
break;
case V_32 :
F_4 ( V_2 -> V_15 , L_8 , true ) ;
break;
case V_33 :
F_4 ( V_2 -> V_15 , L_9 , true ) ;
break;
case V_34 :
F_4 ( V_2 -> V_15 , L_10 , true ) ;
break;
case V_35 :
F_4 ( V_2 -> V_15 , L_11 , true ) ;
break;
default:
V_6 = - V_17 ;
goto V_14;
}
V_2 -> V_30 = V_37 ;
V_14:
return V_6 ;
}
static void F_12 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_13 ( V_42 ,
struct V_1 , V_43 ) ;
T_1 V_44 [ 2 ] ;
T_1 V_18 , V_45 ;
int V_46 = 0 ;
int V_47 , V_6 ;
F_14 ( & V_2 -> V_48 ) ;
V_6 = F_15 ( V_2 -> V_8 , V_38 ,
2 , V_44 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_13 , L_12 ) ;
F_16 ( & V_2 -> V_48 ) ;
return;
}
F_17 ( V_2 -> V_13 , L_13 , V_49 ,
V_44 [ 0 ] , V_44 [ 1 ] ) ;
for ( V_47 = 0 ; V_47 < F_18 ( V_50 ) ; V_47 ++ )
if ( V_2 -> V_51 == V_50 [ V_47 ] . V_52 )
V_46 = V_50 [ V_47 ] . V_51 ;
switch ( V_46 ) {
case V_53 :
V_18 = V_44 [ 0 ] & V_40 ;
V_18 >>= V_54 ;
F_8 ( V_2 , V_18 ) ;
break;
case V_55 :
V_45 = V_44 [ 1 ] & V_56 ;
V_45 >>= V_57 ;
F_10 ( V_2 , V_45 ) ;
break;
default:
F_19 ( V_2 -> V_13 , L_14 ,
V_46 ) ;
break;
}
F_16 ( & V_2 -> V_48 ) ;
return;
}
static T_2 F_20 ( int V_51 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
F_17 ( V_2 -> V_13 , L_15 , V_51 ) ;
V_2 -> V_51 = V_51 ;
F_21 ( & V_2 -> V_43 ) ;
return V_59 ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_6 ;
T_1 V_44 [ 2 ] , V_18 , V_45 ;
V_6 = F_15 ( V_2 -> V_8 , V_38 ,
2 , V_44 ) ;
if ( V_6 ) {
F_3 ( V_2 -> V_13 , L_12 ) ;
return;
}
F_19 ( V_2 -> V_13 , L_16 ,
V_44 [ 0 ] , V_44 [ 1 ] ) ;
V_18 = V_44 [ 0 ] & V_40 ;
V_18 >>= V_54 ;
V_45 = V_44 [ 1 ] & V_56 ;
V_45 >>= V_57 ;
F_8 ( V_2 , V_18 ) ;
F_10 ( V_2 , V_45 ) ;
}
static int F_23 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = F_24 ( V_61 -> V_13 . V_64 ) ;
struct V_65 * V_66 = F_25 ( V_63 -> V_13 ) ;
struct V_1 * V_2 ;
int V_6 , V_47 ;
V_2 = F_26 ( & V_61 -> V_13 , sizeof( struct V_1 ) ,
V_67 ) ;
if ( ! V_2 ) {
F_3 ( & V_61 -> V_13 , L_17 ) ;
return - V_68 ;
}
V_2 -> V_13 = & V_61 -> V_13 ;
V_2 -> V_8 = V_63 -> V_8 ;
F_27 ( V_61 , V_2 ) ;
F_28 ( & V_2 -> V_48 ) ;
F_29 ( & V_2 -> V_43 , F_12 ) ;
for ( V_47 = 0 ; V_47 < F_18 ( V_50 ) ; V_47 ++ ) {
struct V_69 * V_70 = & V_50 [ V_47 ] ;
unsigned int V_52 = 0 ;
V_52 = F_30 ( V_63 -> V_71 , V_70 -> V_51 ) ;
if ( ! V_52 ) {
V_6 = - V_17 ;
goto V_72;
}
V_70 -> V_52 = V_52 ;
V_6 = F_31 ( V_52 , NULL , F_20 ,
0 , V_70 -> V_73 , V_2 ) ;
if ( V_6 ) {
F_3 ( & V_61 -> V_13 ,
L_18
L_19 ,
V_70 -> V_51 , V_6 ) ;
goto V_72;
}
}
V_2 -> V_15 = F_26 ( & V_61 -> V_13 , sizeof( struct V_74 ) ,
V_67 ) ;
if ( ! V_2 -> V_15 ) {
F_3 ( & V_61 -> V_13 , L_20 ) ;
V_6 = - V_68 ;
goto V_72;
}
V_2 -> V_15 -> V_73 = V_75 ;
V_2 -> V_15 -> V_76 = V_77 ;
V_6 = F_32 ( V_2 -> V_15 , NULL ) ;
if ( V_6 ) {
F_3 ( & V_61 -> V_13 , L_21 ) ;
goto V_72;
}
if ( V_66 -> V_78 ) {
struct V_79 * V_80 = V_2 -> V_78 ;
for ( V_47 = 0 ; V_47 < V_80 -> V_81 ; V_47 ++ ) {
F_33 ( V_2 -> V_8 , V_80 -> V_82 [ V_47 ] . V_83 ,
V_80 -> V_82 [ V_47 ] . V_58 ) ;
}
}
F_22 ( V_2 ) ;
return V_6 ;
V_72:
while ( -- V_47 >= 0 )
F_34 ( V_50 [ V_47 ] . V_52 , V_2 ) ;
return V_6 ;
}
static int F_35 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_36 ( V_61 ) ;
int V_47 ;
for ( V_47 = 0 ; V_47 < F_18 ( V_50 ) ; V_47 ++ )
F_34 ( V_50 [ V_47 ] . V_52 , V_2 ) ;
F_37 ( & V_2 -> V_43 ) ;
F_38 ( V_2 -> V_15 ) ;
return 0 ;
}
