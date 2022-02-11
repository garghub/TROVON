static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_6 , V_3 ,
! ( V_3 & V_7 ) , 10 , 30 ) ;
if ( V_4 )
F_3 ( V_2 -> V_8 , L_1 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
F_5 ( V_9 , V_2 -> V_5 + V_6 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_6 , V_3 ,
! ( V_3 & V_9 ) , 10 , 30 ) ;
if ( V_4 )
F_3 ( V_2 -> V_8 , L_2 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_4 ;
if ( ! V_2 -> V_10 )
return 0 ;
V_4 = F_4 ( V_2 ) ;
if ( V_4 )
F_7 ( V_2 -> V_8 , L_3 ) ;
else
V_2 -> V_10 = false ;
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
if ( V_2 -> V_10 )
return 0 ;
F_5 ( V_2 -> V_11 , V_2 -> V_5 + V_12 ) ;
V_4 = F_2 ( V_2 -> V_5 + V_6 , V_3 ,
V_3 & V_13 , 10 , 30 ) ;
if ( V_4 )
F_7 ( V_2 -> V_8 , L_4 ) ;
else
V_2 -> V_10 = true ;
return V_4 ;
}
static int F_9 ( struct V_14 * V_15 , T_1 V_16 , T_1 * V_17 , int V_18 )
{
struct V_1 * V_2 = V_15 -> V_19 ;
T_2 V_20 ;
int V_4 ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_20 = F_10 ( V_18 ) |
F_11 ( V_16 ) |
V_21 |
V_22 ;
F_5 ( V_20 , V_2 -> V_5 + V_23 ) ;
while ( V_18 -- )
* V_17 ++ = F_12 ( V_2 -> V_5 + V_24 ) ;
return F_1 ( V_2 ) ;
}
static int F_13 ( struct V_14 * V_15 , T_1 V_16 , T_1 * V_17 , int V_18 )
{
struct V_1 * V_2 = V_15 -> V_19 ;
T_2 V_20 ;
int V_4 ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_20 = V_25 |
F_10 ( V_18 ) |
F_11 ( V_16 ) |
V_21 |
V_22 ;
F_5 ( V_20 , V_2 -> V_5 + V_23 ) ;
while ( V_18 -- )
F_14 ( * V_17 ++ , V_2 -> V_5 + V_24 ) ;
return F_1 ( V_2 ) ;
}
static T_3 F_15 ( struct V_14 * V_15 , T_4 V_26 , T_5 V_18 ,
T_6 * V_17 )
{
struct V_1 * V_2 = V_15 -> V_19 ;
int V_4 ;
V_4 = F_8 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_16 ( V_17 , V_2 -> V_27 + V_26 , V_18 ) ;
return V_18 ;
}
static T_3 F_17 ( struct V_14 * V_15 , T_4 V_28 , T_5 V_18 ,
const T_6 * V_17 )
{
struct V_1 * V_2 = V_15 -> V_19 ;
T_2 V_20 ;
int V_4 ;
T_5 V_29 ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_5 ( V_28 , V_2 -> V_5 + V_30 ) ;
V_20 = V_25 |
F_10 ( V_18 ) |
V_21 |
F_11 ( V_15 -> V_31 ) |
F_18 ( V_2 -> V_15 . V_32 + 1 ) ;
F_5 ( V_20 , V_2 -> V_5 + V_23 ) ;
for ( V_29 = 0 ; V_29 < V_18 ; V_29 ++ )
F_14 ( V_17 [ V_29 ] , V_2 -> V_5 + V_24 ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
return V_18 ;
}
static int F_19 ( struct V_14 * V_15 , T_4 V_33 )
{
struct V_1 * V_2 = V_15 -> V_19 ;
T_2 V_20 ;
int V_4 ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_5 ( V_33 , V_2 -> V_5 + V_30 ) ;
V_20 = V_21 |
F_11 ( V_15 -> V_34 ) |
F_18 ( V_2 -> V_15 . V_32 + 1 ) ;
F_5 ( V_20 , V_2 -> V_5 + V_23 ) ;
return F_1 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_15 . V_35 ) {
case V_36 :
case V_37 :
V_2 -> V_11 = V_21 ;
break;
case V_38 :
case V_39 :
V_2 -> V_11 = V_40 ;
break;
default:
F_7 ( V_2 -> V_8 , L_5 ) ;
return - V_41 ;
}
if ( V_2 -> V_15 . V_32 < 1 || V_2 -> V_15 . V_32 > 4 )
return - V_41 ;
V_2 -> V_11 |= F_11 ( V_2 -> V_15 . V_42 ) |
F_21 ( V_2 -> V_15 . V_43 / 8 ) |
F_18 ( V_2 -> V_15 . V_32 + 1 ) ;
return 0 ;
}
static void F_22 ( struct V_14 * V_15 )
{
T_1 V_44 [ V_45 ] ;
V_15 -> V_46 ( V_15 , V_47 , V_44 , V_45 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
enum V_50 V_35 ;
T_2 V_51 , V_52 ;
T_7 V_53 = 0 ;
int V_4 ;
if ( ! F_24 ( V_49 , L_6 , & V_52 ) ) {
switch ( V_52 ) {
case 1 :
break;
case 2 :
V_53 |= V_54 ;
break;
case 4 :
V_53 |= V_55 ;
break;
default:
F_7 ( V_2 -> V_8 , L_7 ) ;
return - V_41 ;
}
}
if ( F_25 ( V_49 , L_8 , NULL ) )
V_53 |= V_56 ;
if ( F_25 ( V_49 , L_9 , NULL ) )
V_53 |= V_57 ;
V_51 = F_26 ( 1000 ) |
F_27 ( 15 ) |
V_58 ;
if ( V_53 & V_54 ) {
V_51 |= V_59 ;
V_35 = V_38 ;
} else if ( V_53 & V_55 ) {
V_51 &= ~ V_59 ;
V_35 = V_39 ;
} else {
V_51 |= V_59 ;
V_35 = V_36 ;
}
switch ( V_53 & ( V_56 | V_57 ) ) {
case V_60 :
V_51 &= ~ V_61 ;
break;
case V_62 :
V_51 |= V_61 ;
break;
default:
F_7 ( V_2 -> V_8 , L_10 ) ;
return - V_41 ;
}
F_5 ( V_51 , V_2 -> V_5 + V_63 ) ;
V_2 -> V_15 . V_8 = V_2 -> V_8 ;
F_28 ( & V_2 -> V_15 , V_49 ) ;
V_2 -> V_15 . V_19 = V_2 ;
V_2 -> V_15 . V_64 = F_15 ;
V_2 -> V_15 . V_65 = F_17 ;
V_2 -> V_15 . V_66 = F_19 ;
V_2 -> V_15 . V_46 = F_9 ;
V_2 -> V_15 . V_67 = F_13 ;
F_22 ( & V_2 -> V_15 ) ;
V_4 = F_29 ( & V_2 -> V_15 , NULL , V_35 ) ;
if ( V_4 ) {
F_7 ( V_2 -> V_8 , L_11 ) ;
return V_4 ;
}
V_4 = F_20 ( V_2 ) ;
if ( V_4 ) {
F_7 ( V_2 -> V_8 , L_12 ) ;
return V_4 ;
}
V_4 = F_30 ( & V_2 -> V_15 . V_68 , NULL , 0 ) ;
if ( V_4 ) {
F_7 ( V_2 -> V_8 , L_13 ) ;
return V_4 ;
}
return 0 ;
}
static int F_31 ( struct V_69 * V_70 )
{
struct V_48 * V_71 ;
struct V_1 * V_2 ;
struct V_72 * V_73 ;
int V_4 ;
V_2 = F_32 ( & V_70 -> V_8 , sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 )
return - V_75 ;
V_73 = F_33 ( V_70 , V_76 , L_14 ) ;
V_2 -> V_5 = F_34 ( & V_70 -> V_8 , V_73 ) ;
if ( F_35 ( V_2 -> V_5 ) )
return F_36 ( V_2 -> V_5 ) ;
V_73 = F_33 ( V_70 , V_76 , L_15 ) ;
V_2 -> V_27 = F_34 ( & V_70 -> V_8 , V_73 ) ;
if ( F_35 ( V_2 -> V_27 ) )
return F_36 ( V_2 -> V_27 ) ;
V_2 -> V_77 = F_37 ( & V_70 -> V_8 , L_14 ) ;
if ( F_35 ( V_2 -> V_77 ) ) {
F_7 ( & V_70 -> V_8 , L_16 ) ;
return F_36 ( V_2 -> V_77 ) ;
}
V_2 -> V_78 = F_37 ( & V_70 -> V_8 , L_17 ) ;
if ( F_35 ( V_2 -> V_78 ) ) {
F_7 ( & V_70 -> V_8 , L_18 ) ;
return F_36 ( V_2 -> V_78 ) ;
}
V_4 = F_38 ( V_2 -> V_78 ) ;
if ( V_4 ) {
F_7 ( & V_70 -> V_8 , L_19 ) ;
return V_4 ;
}
V_4 = F_38 ( V_2 -> V_77 ) ;
if ( V_4 ) {
F_7 ( & V_70 -> V_8 , L_20 ) ;
goto V_79;
}
V_2 -> V_8 = & V_70 -> V_8 ;
F_39 ( V_70 , V_2 ) ;
F_4 ( V_2 ) ;
F_5 ( 0 , V_2 -> V_5 + V_80 ) ;
F_5 ( 0 , V_2 -> V_5 + V_12 ) ;
F_4 ( V_2 ) ;
V_71 = F_40 ( V_70 -> V_8 . V_81 , NULL ) ;
if ( ! V_71 ) {
F_7 ( & V_70 -> V_8 , L_21 ) ;
V_4 = - V_82 ;
goto V_83;
}
V_4 = F_23 ( V_2 , V_71 ) ;
if ( V_4 ) {
F_7 ( & V_70 -> V_8 , L_22 ) ;
goto V_83;
}
return 0 ;
V_83:
F_41 ( V_2 -> V_77 ) ;
V_79:
F_41 ( V_2 -> V_78 ) ;
return V_4 ;
}
static int F_42 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_43 ( V_70 ) ;
F_44 ( & V_2 -> V_15 . V_68 ) ;
F_41 ( V_2 -> V_77 ) ;
F_41 ( V_2 -> V_78 ) ;
return 0 ;
}
