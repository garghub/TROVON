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
if ( V_16 > V_18 )
return - V_19 ;
V_2 -> V_6 = V_16 ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 ,
unsigned int V_20 , bool V_21 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_1 * V_2 = F_6 ( V_13 ) ;
T_1 V_22 , V_23 , V_24 , V_25 ;
bool V_26 ;
switch ( V_20 & V_27 ) {
case V_28 :
V_22 = V_29 ;
break;
case V_30 :
V_22 = V_31 ;
break;
case V_32 :
V_22 = V_33 ;
break;
case V_34 :
V_22 = V_35 ;
break;
case V_36 :
V_22 = V_37 ;
break;
default:
F_9 ( V_13 -> V_38 , L_1 ) ;
return - V_19 ;
}
switch ( V_20 & V_39 ) {
case V_40 :
V_26 = false ;
break;
case V_41 :
V_26 = true ;
break;
default:
F_9 ( V_13 -> V_38 , L_2 ) ;
return - V_19 ;
}
switch ( V_20 & V_42 ) {
case V_43 :
break;
default:
return - V_19 ;
}
if ( V_21 ) {
V_23 = V_44 ;
V_24 = V_45 ;
V_25 = V_46 ;
V_2 -> V_47 = V_26 ;
V_2 -> V_48 = V_22 ;
} else {
V_23 = V_49 ;
V_24 = V_50 ;
V_25 = V_51 ;
V_2 -> V_52 = V_26 ;
V_2 -> V_53 = V_22 ;
}
F_10 ( V_2 -> V_4 , V_23 , V_24 , V_22 << V_25 ) ;
return 0 ;
}
static int F_11 ( struct V_9 * V_10 ,
unsigned int V_20 )
{
return F_8 ( V_10 , V_20 , true ) ;
}
static int F_12 ( struct V_9 * V_10 ,
unsigned int V_20 )
{
return F_8 ( V_10 , V_20 , false ) ;
}
static int F_13 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_1 * V_2 = F_6 ( V_13 ) ;
bool V_58 , V_26 ;
T_1 V_59 , V_24 , V_25 , V_23 ;
unsigned int V_60 , V_61 , V_22 , V_62 , V_63 ;
int V_64 , V_65 ;
T_2 V_20 ;
V_60 = F_14 ( V_57 ) ;
V_20 = F_15 ( V_57 ) ;
V_61 = F_16 ( V_57 ) ;
V_62 = V_2 -> V_6 / V_60 ;
V_58 = V_55 -> V_66 == V_67 ;
if ( V_58 ) {
V_63 = V_68 ;
V_23 = V_44 ;
V_24 = V_69 ;
V_25 = V_70 ;
V_26 = V_2 -> V_47 ;
V_22 = V_2 -> V_48 ;
} else {
V_63 = V_71 ;
V_23 = V_49 ;
V_24 = V_72 ;
V_25 = V_73 ;
V_26 = V_2 -> V_52 ;
V_22 = V_2 -> V_53 ;
}
for ( V_64 = 0 ; V_64 < V_63 ; V_64 ++ ) {
if ( V_74 [ V_64 ] == V_62 )
break;
}
if ( V_64 == V_63 ) {
F_9 ( V_13 -> V_38 , L_3 ) ;
return - V_19 ;
}
V_65 = F_17 ( V_57 ) * 2 ;
switch ( V_65 ) {
case 32 :
if ( V_26 || ( V_22 != V_33 ) ) {
F_9 ( V_13 -> V_38 , L_4 ) ;
return - V_19 ;
}
V_22 = V_75 ;
break;
case 48 :
if ( V_26 || ( V_22 & V_76 ) ) {
F_9 ( V_13 -> V_38 , L_5 ) ;
return - V_19 ;
}
break;
case 64 :
break;
default:
F_9 ( V_13 -> V_38 , L_6 , V_65 ) ;
return - V_19 ;
}
if ( V_26 )
V_59 = ( ( V_64 + 1 ) << V_25 ) ;
else
V_59 = 0 ;
F_10 ( V_2 -> V_4 , V_23 , V_24 , V_59 ) ;
if ( V_58 ) {
V_24 = V_45 ;
V_25 = V_46 ;
} else {
V_24 = V_50 ;
V_25 = V_51 ;
}
F_10 ( V_2 -> V_4 , V_23 , V_24 , V_22 << V_25 ) ;
return 0 ;
}
static bool F_18 ( struct V_77 * V_38 , unsigned int V_23 )
{
if ( V_23 >= V_5 )
return true ;
else
return false ;
}
static bool F_19 ( struct V_77 * V_38 , unsigned int V_23 )
{
switch ( V_23 ) {
case V_78 :
case V_79 :
return true ;
default:
return false ;
}
}
static bool F_20 ( struct V_77 * V_38 , unsigned int V_23 )
{
if ( V_23 < V_5 )
return false ;
switch ( V_23 ) {
case V_78 :
case V_79 :
return false ;
default:
return true ;
}
}
int F_21 ( struct V_77 * V_38 , struct V_4 * V_4 )
{
struct V_1 * V_2 ;
int V_3 , V_64 ;
V_2 = F_22 ( V_38 , sizeof( * V_2 ) , V_80 ) ;
if ( V_2 == NULL )
return - V_81 ;
F_23 ( V_38 , V_2 ) ;
V_2 -> V_82 = F_24 ( V_38 , L_7 ) ;
if ( F_25 ( V_2 -> V_82 ) ) {
V_3 = F_26 ( V_2 -> V_82 ) ;
if ( V_3 != - V_83 )
F_9 ( V_38 , L_8 , V_3 ) ;
return V_3 ;
}
V_3 = F_27 ( V_2 -> V_82 ) ;
if ( V_3 ) {
F_9 ( V_38 , L_9 , V_3 ) ;
return V_3 ;
}
V_2 -> V_6 = F_28 ( V_2 -> V_82 ) ;
for ( V_64 = 0 ; V_64 < F_29 ( V_2 -> V_84 ) ; V_64 ++ )
V_2 -> V_84 [ V_64 ] . V_85 = V_86 [ V_64 ] ;
V_3 = F_30 ( V_38 ,
F_29 ( V_2 -> V_84 ) , V_2 -> V_84 ) ;
if ( V_3 ) {
if ( V_3 != - V_83 )
F_9 ( V_38 , L_10 , V_3 ) ;
goto V_87;
}
V_3 = F_31 ( F_29 ( V_2 -> V_84 ) ,
V_2 -> V_84 ) ;
if ( V_3 ) {
F_9 ( V_38 , L_11 , V_3 ) ;
goto V_87;
}
V_2 -> V_4 = V_4 ;
if ( F_25 ( V_2 -> V_4 ) ) {
V_3 = F_26 ( V_2 -> V_4 ) ;
F_9 ( V_38 , L_12 , V_3 ) ;
goto V_88;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_9 ( V_38 , L_13 , V_3 ) ;
goto V_88;
}
F_32 ( V_38 ) ;
F_33 ( V_38 ) ;
F_34 ( V_38 ) ;
V_3 = F_35 ( V_38 , & V_89 , V_90 ,
F_29 ( V_90 ) ) ;
if ( V_3 ) {
F_9 ( V_38 , L_14 , V_3 ) ;
goto V_88;
}
return 0 ;
V_88:
F_36 ( F_29 ( V_2 -> V_84 ) ,
V_2 -> V_84 ) ;
V_87:
F_37 ( V_2 -> V_82 ) ;
return V_3 ;
}
void F_38 ( struct V_77 * V_38 )
{
struct V_1 * V_2 = F_39 ( V_38 ) ;
F_40 ( V_38 ) ;
F_41 ( V_38 ) ;
F_36 ( F_29 ( V_2 -> V_84 ) ,
V_2 -> V_84 ) ;
F_37 ( V_2 -> V_82 ) ;
}
static int F_42 ( struct V_77 * V_38 )
{
struct V_1 * V_2 = F_39 ( V_38 ) ;
int V_3 ;
V_3 = F_27 ( V_2 -> V_82 ) ;
if ( V_3 ) {
F_9 ( V_38 , L_9 , V_3 ) ;
return V_3 ;
}
V_3 = F_31 ( F_29 ( V_2 -> V_84 ) ,
V_2 -> V_84 ) ;
if ( V_3 ) {
F_9 ( V_38 , L_15 , V_3 ) ;
goto V_87;
}
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_9 ( V_38 , L_13 , V_3 ) ;
goto V_88;
}
F_43 ( V_2 -> V_4 , false ) ;
F_44 ( V_2 -> V_4 ) ;
V_3 = F_45 ( V_2 -> V_4 ) ;
if ( V_3 ) {
F_9 ( V_38 , L_16 , V_3 ) ;
goto V_88;
}
return 0 ;
V_88:
F_36 ( F_29 ( V_2 -> V_84 ) ,
V_2 -> V_84 ) ;
V_87:
F_37 ( V_2 -> V_82 ) ;
return V_3 ;
}
static int F_46 ( struct V_77 * V_38 )
{
struct V_1 * V_2 = F_39 ( V_38 ) ;
F_43 ( V_2 -> V_4 , true ) ;
F_36 ( F_29 ( V_2 -> V_84 ) ,
V_2 -> V_84 ) ;
F_37 ( V_2 -> V_82 ) ;
return 0 ;
}
