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
static int F_13 ( struct V_14 * V_15 , T_1 V_16 , T_1 * V_17 ,
int V_18 , int V_25 )
{
struct V_1 * V_2 = V_15 -> V_19 ;
T_2 V_20 ;
int V_4 ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_20 = V_26 |
F_10 ( V_18 ) |
F_11 ( V_16 ) |
V_21 |
V_22 ;
F_5 ( V_20 , V_2 -> V_5 + V_23 ) ;
while ( V_18 -- )
F_14 ( * V_17 ++ , V_2 -> V_5 + V_24 ) ;
return F_1 ( V_2 ) ;
}
static int F_15 ( struct V_14 * V_15 , T_3 V_27 , T_4 V_18 ,
T_4 * V_28 , T_5 * V_17 )
{
struct V_1 * V_2 = V_15 -> V_19 ;
int V_4 ;
V_4 = F_8 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_16 ( V_17 , V_2 -> V_29 + V_27 , V_18 ) ;
* V_28 += V_18 ;
return 0 ;
}
static void F_17 ( struct V_14 * V_15 , T_3 V_30 , T_4 V_18 ,
T_4 * V_28 , const T_5 * V_17 )
{
struct V_1 * V_2 = V_15 -> V_19 ;
T_2 V_20 ;
int V_4 ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 )
return;
F_5 ( V_30 , V_2 -> V_5 + V_31 ) ;
* V_28 += V_18 ;
V_20 = V_26 |
F_10 ( V_18 ) |
V_21 |
F_11 ( V_15 -> V_32 ) |
F_18 ( V_2 -> V_15 . V_33 + 1 ) ;
F_5 ( V_20 , V_2 -> V_5 + V_23 ) ;
while ( V_18 -- )
F_14 ( * V_17 ++ , V_2 -> V_5 + V_24 ) ;
F_1 ( V_2 ) ;
}
static int F_19 ( struct V_14 * V_15 , T_3 V_34 )
{
struct V_1 * V_2 = V_15 -> V_19 ;
T_2 V_20 ;
int V_4 ;
V_4 = F_6 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_5 ( V_34 , V_2 -> V_5 + V_31 ) ;
V_20 = V_21 |
F_11 ( V_15 -> V_35 ) |
F_18 ( V_2 -> V_15 . V_33 + 1 ) ;
F_5 ( V_20 , V_2 -> V_5 + V_23 ) ;
return F_1 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_15 . V_36 ) {
case V_37 :
case V_38 :
V_2 -> V_11 = V_21 ;
break;
case V_39 :
case V_40 :
V_2 -> V_11 = V_41 ;
break;
default:
F_7 ( V_2 -> V_8 , L_5 ) ;
return - V_42 ;
}
if ( V_2 -> V_15 . V_33 < 1 || V_2 -> V_15 . V_33 > 4 )
return - V_42 ;
V_2 -> V_11 |= F_11 ( V_2 -> V_15 . V_43 ) |
F_21 ( V_2 -> V_15 . V_44 / 8 ) |
F_18 ( V_2 -> V_15 . V_33 + 1 ) ;
return 0 ;
}
static void F_22 ( struct V_14 * V_15 )
{
T_1 V_45 [ V_46 ] ;
V_15 -> V_47 ( V_15 , V_48 , V_45 , V_46 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_51 V_52 ;
enum V_53 V_36 ;
T_2 V_54 , V_55 ;
T_6 V_56 = 0 ;
int V_4 ;
if ( ! F_24 ( V_50 , L_6 , & V_55 ) ) {
switch ( V_55 ) {
case 1 :
break;
case 2 :
V_56 |= V_57 ;
break;
case 4 :
V_56 |= V_58 ;
break;
default:
F_7 ( V_2 -> V_8 , L_7 ) ;
return - V_42 ;
}
}
if ( F_25 ( V_50 , L_8 , NULL ) )
V_56 |= V_59 ;
if ( F_25 ( V_50 , L_9 , NULL ) )
V_56 |= V_60 ;
V_54 = F_26 ( 1000 ) |
F_27 ( 15 ) |
V_61 ;
if ( V_56 & V_57 ) {
V_54 |= V_62 ;
V_36 = V_39 ;
} else if ( V_56 & V_58 ) {
V_54 &= ~ V_62 ;
V_36 = V_40 ;
} else {
V_54 |= V_62 ;
V_36 = V_37 ;
}
switch ( V_56 & ( V_59 | V_60 ) ) {
case V_63 :
V_54 &= ~ V_64 ;
break;
case V_65 :
V_54 |= V_64 ;
break;
default:
F_7 ( V_2 -> V_8 , L_10 ) ;
return - V_42 ;
}
F_5 ( V_54 , V_2 -> V_5 + V_66 ) ;
V_2 -> V_67 . V_19 = & V_2 -> V_15 ;
V_2 -> V_15 . V_67 = & V_2 -> V_67 ;
V_2 -> V_15 . V_8 = V_2 -> V_8 ;
V_2 -> V_15 . V_19 = V_2 ;
V_2 -> V_15 . V_68 = F_15 ;
V_2 -> V_15 . V_69 = F_17 ;
V_2 -> V_15 . V_70 = F_19 ;
V_2 -> V_15 . V_47 = F_9 ;
V_2 -> V_15 . V_71 = F_13 ;
F_22 ( & V_2 -> V_15 ) ;
V_4 = F_28 ( & V_2 -> V_15 , NULL , V_36 ) ;
if ( V_4 ) {
F_7 ( V_2 -> V_8 , L_11 ) ;
return V_4 ;
}
V_4 = F_20 ( V_2 ) ;
if ( V_4 ) {
F_7 ( V_2 -> V_8 , L_12 ) ;
return V_4 ;
}
V_52 . V_72 = V_50 ;
V_4 = F_29 ( & V_2 -> V_67 , NULL , & V_52 , NULL , 0 ) ;
if ( V_4 ) {
F_7 ( V_2 -> V_8 , L_13 ) ;
return V_4 ;
}
return 0 ;
}
static int F_30 ( struct V_73 * V_74 )
{
struct V_49 * V_75 ;
struct V_1 * V_2 ;
struct V_76 * V_77 ;
int V_4 ;
V_2 = F_31 ( & V_74 -> V_8 , sizeof( * V_2 ) , V_78 ) ;
if ( ! V_2 )
return - V_79 ;
V_77 = F_32 ( V_74 , V_80 , L_14 ) ;
V_2 -> V_5 = F_33 ( & V_74 -> V_8 , V_77 ) ;
if ( F_34 ( V_2 -> V_5 ) )
return F_35 ( V_2 -> V_5 ) ;
V_77 = F_32 ( V_74 , V_80 , L_15 ) ;
V_2 -> V_29 = F_33 ( & V_74 -> V_8 , V_77 ) ;
if ( F_34 ( V_2 -> V_29 ) )
return F_35 ( V_2 -> V_29 ) ;
V_2 -> V_81 = F_36 ( & V_74 -> V_8 , L_14 ) ;
if ( F_34 ( V_2 -> V_81 ) ) {
F_7 ( & V_74 -> V_8 , L_16 ) ;
return F_35 ( V_2 -> V_81 ) ;
}
V_2 -> V_82 = F_36 ( & V_74 -> V_8 , L_17 ) ;
if ( F_34 ( V_2 -> V_82 ) ) {
F_7 ( & V_74 -> V_8 , L_18 ) ;
return F_35 ( V_2 -> V_82 ) ;
}
V_4 = F_37 ( V_2 -> V_82 ) ;
if ( V_4 ) {
F_7 ( & V_74 -> V_8 , L_19 ) ;
return V_4 ;
}
V_4 = F_37 ( V_2 -> V_81 ) ;
if ( V_4 ) {
F_7 ( & V_74 -> V_8 , L_20 ) ;
goto V_83;
}
V_2 -> V_8 = & V_74 -> V_8 ;
F_38 ( V_74 , V_2 ) ;
F_4 ( V_2 ) ;
F_5 ( 0 , V_2 -> V_5 + V_84 ) ;
F_5 ( 0 , V_2 -> V_5 + V_12 ) ;
F_4 ( V_2 ) ;
V_75 = F_39 ( V_74 -> V_8 . V_72 , NULL ) ;
if ( ! V_75 ) {
F_7 ( & V_74 -> V_8 , L_21 ) ;
V_4 = - V_85 ;
goto V_86;
}
V_4 = F_23 ( V_2 , V_75 ) ;
if ( V_4 ) {
F_7 ( & V_74 -> V_8 , L_22 ) ;
goto V_86;
}
return 0 ;
V_86:
F_40 ( V_2 -> V_81 ) ;
V_83:
F_40 ( V_2 -> V_82 ) ;
return V_4 ;
}
static int F_41 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_42 ( V_74 ) ;
F_43 ( & V_2 -> V_67 ) ;
F_40 ( V_2 -> V_81 ) ;
F_40 ( V_2 -> V_82 ) ;
return 0 ;
}
