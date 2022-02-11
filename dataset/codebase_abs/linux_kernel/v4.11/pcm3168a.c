static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_5 , 0 ) ;
if ( V_3 )
return V_3 ;
F_3 ( F_4 ( 3846 * 1000 , V_2 -> V_6 ) ) ;
return F_2 ( V_2 -> V_4 , V_5 ,
V_7 | V_8 ) ;
}
static int F_5 ( struct V_9 * V_10 , int V_11 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_1 * V_2 = F_6 ( V_13 ) ;
F_2 ( V_2 -> V_4 , V_14 , V_11 ? 0xff : 0 ) ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 ,
int V_15 , unsigned int V_16 , int V_17 )
{
struct V_1 * V_2 = F_6 ( V_10 -> V_13 ) ;
int V_3 ;
if ( V_16 > V_18 )
return - V_19 ;
V_3 = F_8 ( V_2 -> V_20 , V_16 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_6 = V_16 ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 ,
unsigned int V_21 , bool V_22 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_1 * V_2 = F_6 ( V_13 ) ;
T_1 V_23 , V_24 , V_25 , V_26 ;
bool V_27 ;
switch ( V_21 & V_28 ) {
case V_29 :
V_23 = V_30 ;
break;
case V_31 :
V_23 = V_32 ;
break;
case V_33 :
V_23 = V_34 ;
break;
case V_35 :
V_23 = V_36 ;
break;
case V_37 :
V_23 = V_38 ;
break;
default:
F_10 ( V_13 -> V_39 , L_1 ) ;
return - V_19 ;
}
switch ( V_21 & V_40 ) {
case V_41 :
V_27 = false ;
break;
case V_42 :
V_27 = true ;
break;
default:
F_10 ( V_13 -> V_39 , L_2 ) ;
return - V_19 ;
}
switch ( V_21 & V_43 ) {
case V_44 :
break;
default:
return - V_19 ;
}
if ( V_22 ) {
V_24 = V_45 ;
V_25 = V_46 ;
V_26 = V_47 ;
V_2 -> V_48 = V_27 ;
V_2 -> V_49 = V_23 ;
} else {
V_24 = V_50 ;
V_25 = V_51 ;
V_26 = V_52 ;
V_2 -> V_53 = V_27 ;
V_2 -> V_54 = V_23 ;
}
F_11 ( V_2 -> V_4 , V_24 , V_25 , V_23 << V_26 ) ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
unsigned int V_21 )
{
return F_9 ( V_10 , V_21 , true ) ;
}
static int F_13 ( struct V_9 * V_10 ,
unsigned int V_21 )
{
return F_9 ( V_10 , V_21 , false ) ;
}
static int F_14 ( struct V_55 * V_56 ,
struct V_57 * V_58 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_1 * V_2 = F_6 ( V_13 ) ;
bool V_59 , V_27 ;
T_1 V_60 , V_25 , V_26 , V_24 ;
unsigned int V_61 , V_23 , V_62 , V_63 ;
int V_64 , V_65 ;
V_61 = F_15 ( V_58 ) ;
V_62 = V_2 -> V_6 / V_61 ;
V_59 = V_56 -> V_66 == V_67 ;
if ( V_59 ) {
V_63 = V_68 ;
V_24 = V_45 ;
V_25 = V_69 ;
V_26 = V_70 ;
V_27 = V_2 -> V_48 ;
V_23 = V_2 -> V_49 ;
} else {
V_63 = V_71 ;
V_24 = V_50 ;
V_25 = V_72 ;
V_26 = V_73 ;
V_27 = V_2 -> V_53 ;
V_23 = V_2 -> V_54 ;
}
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
if ( V_74 [ V_64 ] == V_62 )
break;
}
if ( V_64 == V_63 ) {
F_10 ( V_13 -> V_39 , L_3 ) ;
return - V_19 ;
}
V_65 = F_16 ( V_58 ) * 2 ;
switch ( V_65 ) {
case 32 :
if ( V_27 || ( V_23 != V_34 ) ) {
F_10 ( V_13 -> V_39 , L_4 ) ;
return - V_19 ;
}
V_23 = V_75 ;
break;
case 48 :
if ( V_27 || ( V_23 & V_76 ) ) {
F_10 ( V_13 -> V_39 , L_5 ) ;
return - V_19 ;
}
break;
case 64 :
break;
default:
F_10 ( V_13 -> V_39 , L_6 , V_65 ) ;
return - V_19 ;
}
if ( V_27 )
V_60 = ( ( V_64 + 1 ) << V_26 ) ;
else
V_60 = 0 ;
F_11 ( V_2 -> V_4 , V_24 , V_25 , V_60 ) ;
if ( V_59 ) {
V_25 = V_46 ;
V_26 = V_47 ;
} else {
V_25 = V_51 ;
V_26 = V_52 ;
}
F_11 ( V_2 -> V_4 , V_24 , V_25 , V_23 << V_26 ) ;
return 0 ;
}
static bool F_17 ( struct V_77 * V_39 , unsigned int V_24 )
{
if ( V_24 >= V_5 )
return true ;
else
return false ;
}
static bool F_18 ( struct V_77 * V_39 , unsigned int V_24 )
{
switch ( V_24 ) {
case V_78 :
case V_79 :
return true ;
default:
return false ;
}
}
static bool F_19 ( struct V_77 * V_39 , unsigned int V_24 )
{
if ( V_24 < V_5 )
return false ;
switch ( V_24 ) {
case V_78 :
case V_79 :
return false ;
default:
return true ;
}
}
int F_20 ( struct V_77 * V_39 , struct V_4 * V_4 )
{
struct V_1 * V_2 ;
int V_3 , V_64 ;
V_2 = F_21 ( V_39 , sizeof( * V_2 ) , V_80 ) ;
if ( V_2 == NULL )
return - V_81 ;
F_22 ( V_39 , V_2 ) ;
V_2 -> V_20 = F_23 ( V_39 , L_7 ) ;
if ( F_24 ( V_2 -> V_20 ) ) {
V_3 = F_25 ( V_2 -> V_20 ) ;
if ( V_3 != - V_82 )
F_10 ( V_39 , L_8 , V_3 ) ;
return V_3 ;
}
V_3 = F_26 ( V_2 -> V_20 ) ;
if ( V_3 ) {
F_10 ( V_39 , L_9 , V_3 ) ;
return V_3 ;
}
V_2 -> V_6 = F_27 ( V_2 -> V_20 ) ;
for ( V_64 = 0 ; V_64 < F_28 ( V_2 -> V_83 ) ; V_64 ++ )
V_2 -> V_83 [ V_64 ] . V_84 = V_85 [ V_64 ] ;
V_3 = F_29 ( V_39 ,
F_28 ( V_2 -> V_83 ) , V_2 -> V_83 ) ;
if ( V_3 ) {
if ( V_3 != - V_82 )
F_10 ( V_39 , L_10 , V_3 ) ;
goto V_86;
}
V_3 = F_30 ( F_28 ( V_2 -> V_83 ) ,
V_2 -> V_83 ) ;
if ( V_3 ) {
F_10 ( V_39 , L_11 , V_3 ) ;
goto V_86;
}
V_2 -> V_4 = V_4 ;
if ( F_24 ( V_2 -> V_4 ) ) {
V_3 = F_25 ( V_2 -> V_4 ) ;
F_10 ( V_39 , L_12 , V_3 ) ;
goto V_87;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_10 ( V_39 , L_13 , V_3 ) ;
goto V_87;
}
F_31 ( V_39 ) ;
F_32 ( V_39 ) ;
F_33 ( V_39 ) ;
V_3 = F_34 ( V_39 , & V_88 , V_89 ,
F_28 ( V_89 ) ) ;
if ( V_3 ) {
F_10 ( V_39 , L_14 , V_3 ) ;
goto V_87;
}
return 0 ;
V_87:
F_35 ( F_28 ( V_2 -> V_83 ) ,
V_2 -> V_83 ) ;
V_86:
F_36 ( V_2 -> V_20 ) ;
return V_3 ;
}
void F_37 ( struct V_77 * V_39 )
{
struct V_1 * V_2 = F_38 ( V_39 ) ;
F_39 ( V_39 ) ;
F_40 ( V_39 ) ;
F_35 ( F_28 ( V_2 -> V_83 ) ,
V_2 -> V_83 ) ;
F_36 ( V_2 -> V_20 ) ;
}
static int F_41 ( struct V_77 * V_39 )
{
struct V_1 * V_2 = F_38 ( V_39 ) ;
int V_3 ;
V_3 = F_26 ( V_2 -> V_20 ) ;
if ( V_3 ) {
F_10 ( V_39 , L_9 , V_3 ) ;
return V_3 ;
}
V_3 = F_30 ( F_28 ( V_2 -> V_83 ) ,
V_2 -> V_83 ) ;
if ( V_3 ) {
F_10 ( V_39 , L_15 , V_3 ) ;
goto V_86;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_10 ( V_39 , L_13 , V_3 ) ;
goto V_87;
}
F_42 ( V_2 -> V_4 , false ) ;
F_43 ( V_2 -> V_4 ) ;
V_3 = F_44 ( V_2 -> V_4 ) ;
if ( V_3 ) {
F_10 ( V_39 , L_16 , V_3 ) ;
goto V_87;
}
return 0 ;
V_87:
F_35 ( F_28 ( V_2 -> V_83 ) ,
V_2 -> V_83 ) ;
V_86:
F_36 ( V_2 -> V_20 ) ;
return V_3 ;
}
static int F_45 ( struct V_77 * V_39 )
{
struct V_1 * V_2 = F_38 ( V_39 ) ;
F_42 ( V_2 -> V_4 , true ) ;
F_35 ( F_28 ( V_2 -> V_83 ) ,
V_2 -> V_83 ) ;
F_36 ( V_2 -> V_20 ) ;
return 0 ;
}
