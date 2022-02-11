int F_1 ( void T_1 * V_1 , int V_2 , T_2 * V_3 )
{
if ( ( V_4 ) V_1 & ( V_2 - 1 ) ) {
* V_3 = 0 ;
return V_5 ;
}
if ( V_2 == 4 ) {
* V_3 = F_2 ( V_1 ) ;
} else if ( V_2 == 2 ) {
* V_3 = F_3 ( V_1 ) ;
} else if ( V_2 == 1 ) {
* V_3 = F_4 ( V_1 ) ;
} else {
* V_3 = 0 ;
return V_5 ;
}
return V_6 ;
}
int F_5 ( void T_1 * V_1 , int V_2 , T_2 V_3 )
{
if ( ( V_4 ) V_1 & ( V_2 - 1 ) )
return V_5 ;
if ( V_2 == 4 )
F_6 ( V_3 , V_1 ) ;
else if ( V_2 == 2 )
F_7 ( V_3 , V_1 ) ;
else if ( V_2 == 1 )
F_8 ( V_3 , V_1 ) ;
else
return V_5 ;
return V_6 ;
}
T_2 F_9 ( struct V_7 * V_8 , void T_1 * V_9 , T_2 V_10 ,
T_3 V_2 )
{
int V_11 ;
T_2 V_3 ;
if ( V_8 -> V_12 -> V_13 )
return V_8 -> V_12 -> V_13 ( V_8 , V_9 , V_10 , V_2 ) ;
V_11 = F_1 ( V_9 + V_10 , V_2 , & V_3 ) ;
if ( V_11 )
F_10 ( V_8 -> V_14 , L_1 ) ;
return V_3 ;
}
void F_11 ( struct V_7 * V_8 , void T_1 * V_9 , T_2 V_10 ,
T_3 V_2 , T_2 V_3 )
{
int V_11 ;
if ( V_8 -> V_12 -> V_15 ) {
V_8 -> V_12 -> V_15 ( V_8 , V_9 , V_10 , V_2 , V_3 ) ;
return;
}
V_11 = F_5 ( V_9 + V_10 , V_2 , V_3 ) ;
if ( V_11 )
F_10 ( V_8 -> V_14 , L_2 ) ;
}
static T_2 F_12 ( struct V_7 * V_8 , T_2 V_16 , T_2 V_10 )
{
T_2 V_17 = F_13 ( V_16 ) ;
return F_14 ( V_8 , V_17 + V_10 ) ;
}
static void F_15 ( struct V_7 * V_8 , T_2 V_16 , T_2 V_10 ,
T_2 V_3 )
{
T_2 V_17 = F_13 ( V_16 ) ;
F_16 ( V_8 , V_17 + V_10 , V_3 ) ;
}
static void F_17 ( struct V_7 * V_8 , int V_16 ,
int type , T_4 V_18 ,
T_4 V_19 , T_2 V_2 )
{
T_2 V_20 , V_3 ;
F_15 ( V_8 , V_16 , V_21 ,
F_18 ( V_18 ) ) ;
F_15 ( V_8 , V_16 , V_22 ,
F_19 ( V_18 ) ) ;
F_15 ( V_8 , V_16 , V_23 ,
F_18 ( V_18 + V_2 - 1 ) ) ;
F_15 ( V_8 , V_16 , V_24 ,
F_18 ( V_19 ) ) ;
F_15 ( V_8 , V_16 , V_25 ,
F_19 ( V_19 ) ) ;
F_15 ( V_8 , V_16 , V_26 ,
type ) ;
F_15 ( V_8 , V_16 , V_27 ,
V_28 ) ;
for ( V_20 = 0 ; V_20 < V_29 ; V_20 ++ ) {
V_3 = F_12 ( V_8 , V_16 ,
V_27 ) ;
if ( V_3 & V_28 )
return;
F_20 ( V_30 , V_31 ) ;
}
F_10 ( V_8 -> V_14 , L_3 ) ;
}
void F_21 ( struct V_7 * V_8 , int V_16 , int type ,
T_4 V_18 , T_4 V_19 , T_2 V_2 )
{
T_2 V_20 , V_3 ;
if ( V_8 -> V_12 -> V_32 )
V_18 = V_8 -> V_12 -> V_32 ( V_18 ) ;
if ( V_8 -> V_33 ) {
F_17 ( V_8 , V_16 , type , V_18 ,
V_19 , V_2 ) ;
return;
}
F_16 ( V_8 , V_34 ,
V_35 | V_16 ) ;
F_16 ( V_8 , V_36 ,
F_18 ( V_18 ) ) ;
F_16 ( V_8 , V_37 ,
F_19 ( V_18 ) ) ;
F_16 ( V_8 , V_38 ,
F_18 ( V_18 + V_2 - 1 ) ) ;
F_16 ( V_8 , V_39 ,
F_18 ( V_19 ) ) ;
F_16 ( V_8 , V_40 ,
F_19 ( V_19 ) ) ;
F_16 ( V_8 , V_41 , type ) ;
F_16 ( V_8 , V_42 , V_28 ) ;
for ( V_20 = 0 ; V_20 < V_29 ; V_20 ++ ) {
V_3 = F_14 ( V_8 , V_42 ) ;
if ( V_3 & V_28 )
return;
F_20 ( V_30 , V_31 ) ;
}
F_10 ( V_8 -> V_14 , L_3 ) ;
}
static T_2 F_22 ( struct V_7 * V_8 , T_2 V_16 , T_2 V_10 )
{
T_2 V_17 = F_23 ( V_16 ) ;
return F_14 ( V_8 , V_17 + V_10 ) ;
}
static void F_24 ( struct V_7 * V_8 , T_2 V_16 , T_2 V_10 ,
T_2 V_3 )
{
T_2 V_17 = F_23 ( V_16 ) ;
F_16 ( V_8 , V_17 + V_10 , V_3 ) ;
}
static int F_25 ( struct V_7 * V_8 , int V_16 ,
int V_43 , T_4 V_18 ,
enum V_44 V_45 )
{
int type ;
T_2 V_20 , V_3 ;
F_24 ( V_8 , V_16 , V_24 ,
F_18 ( V_18 ) ) ;
F_24 ( V_8 , V_16 , V_25 ,
F_19 ( V_18 ) ) ;
switch ( V_45 ) {
case V_46 :
type = V_47 ;
break;
case V_48 :
type = V_49 ;
break;
default:
return - V_50 ;
}
F_24 ( V_8 , V_16 , V_26 , type ) ;
F_24 ( V_8 , V_16 , V_27 ,
V_28 |
V_51 | ( V_43 << 8 ) ) ;
for ( V_20 = 0 ; V_20 < V_29 ; V_20 ++ ) {
V_3 = F_22 ( V_8 , V_16 ,
V_27 ) ;
if ( V_3 & V_28 )
return 0 ;
F_20 ( V_30 , V_31 ) ;
}
F_10 ( V_8 -> V_14 , L_4 ) ;
return - V_52 ;
}
int F_26 ( struct V_7 * V_8 , int V_16 , int V_43 ,
T_4 V_18 , enum V_44 V_45 )
{
int type ;
T_2 V_20 , V_3 ;
if ( V_8 -> V_33 )
return F_25 ( V_8 , V_16 , V_43 ,
V_18 , V_45 ) ;
F_16 ( V_8 , V_34 , V_53 |
V_16 ) ;
F_16 ( V_8 , V_39 , F_18 ( V_18 ) ) ;
F_16 ( V_8 , V_40 , F_19 ( V_18 ) ) ;
switch ( V_45 ) {
case V_46 :
type = V_47 ;
break;
case V_48 :
type = V_49 ;
break;
default:
return - V_50 ;
}
F_16 ( V_8 , V_41 , type ) ;
F_16 ( V_8 , V_42 , V_28
| V_51 | ( V_43 << 8 ) ) ;
for ( V_20 = 0 ; V_20 < V_29 ; V_20 ++ ) {
V_3 = F_14 ( V_8 , V_42 ) ;
if ( V_3 & V_28 )
return 0 ;
F_20 ( V_30 , V_31 ) ;
}
F_10 ( V_8 -> V_14 , L_4 ) ;
return - V_52 ;
}
void F_27 ( struct V_7 * V_8 , int V_16 ,
enum V_54 type )
{
int V_55 ;
switch ( type ) {
case V_56 :
V_55 = V_53 ;
break;
case V_57 :
V_55 = V_35 ;
break;
default:
return;
}
F_16 ( V_8 , V_34 , V_55 | V_16 ) ;
F_16 ( V_8 , V_42 , ~ V_28 ) ;
}
int F_28 ( struct V_7 * V_8 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_58 ; V_20 ++ ) {
if ( F_29 ( V_8 ) ) {
F_30 ( V_8 -> V_14 , L_5 ) ;
return 0 ;
}
F_20 ( V_59 , V_60 ) ;
}
F_10 ( V_8 -> V_14 , L_6 ) ;
return - V_61 ;
}
int F_29 ( struct V_7 * V_8 )
{
T_2 V_3 ;
if ( V_8 -> V_12 -> V_62 )
return V_8 -> V_12 -> V_62 ( V_8 ) ;
V_3 = F_2 ( V_8 -> V_63 + V_64 ) ;
return ( ( V_3 & V_65 ) &&
( ! ( V_3 & V_66 ) ) ) ;
}
void F_31 ( struct V_7 * V_8 )
{
int V_11 ;
T_2 V_3 ;
T_2 V_67 ;
struct V_68 * V_14 = V_8 -> V_14 ;
struct V_69 * V_70 = V_14 -> V_71 ;
V_11 = F_32 ( V_70 , L_7 , & V_67 ) ;
if ( V_11 )
V_67 = 0 ;
V_3 = F_14 ( V_8 , V_72 ) ;
V_3 &= ~ V_73 ;
switch ( V_67 ) {
case 1 :
V_3 |= V_74 ;
break;
case 2 :
V_3 |= V_75 ;
break;
case 4 :
V_3 |= V_76 ;
break;
case 8 :
V_3 |= V_77 ;
break;
default:
F_10 ( V_8 -> V_14 , L_8 , V_67 ) ;
return;
}
F_16 ( V_8 , V_72 , V_3 ) ;
V_3 = F_14 ( V_8 , V_78 ) ;
V_3 &= ~ V_79 ;
switch ( V_67 ) {
case 1 :
V_3 |= V_80 ;
break;
case 2 :
V_3 |= V_81 ;
break;
case 4 :
V_3 |= V_82 ;
break;
case 8 :
V_3 |= V_83 ;
break;
}
F_16 ( V_8 , V_78 , V_3 ) ;
}
