static inline int F_1 ( struct V_1 * V_2 )
{
return ! F_2 ( V_2 -> V_3 -> V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
return 0 ;
}
static T_1 F_4 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
if ( V_7 == F_5 ( V_2 -> V_3 -> V_4 ) ) {
unsigned V_9 = F_1 ( V_2 ) ;
if ( V_9 != V_2 -> V_9 ) {
V_2 -> V_9 = V_9 ;
F_6 ( & V_2 -> V_10 -> V_11 , L_1 ,
V_9 ? L_2 : L_3 ) ;
F_7 ( & V_2 -> V_12 , V_13 ) ;
}
}
return V_14 ;
}
static int F_8 ( struct V_5 * V_6 , T_2 * V_15 )
{
struct V_1 * V_2 ;
if ( ! V_15 )
return - V_16 ;
V_2 = F_9 ( V_6 , struct V_1 , V_12 ) ;
if ( F_1 ( V_2 ) ) {
int V_17 = F_10 ( V_2 -> V_3 -> V_18 ) ;
int V_19 = F_10 ( V_2 -> V_3 -> V_20 ) ;
* V_15 = V_13 | V_21 ;
if ( ! V_17 || F_2 ( V_2 -> V_3 -> V_18 ) )
* V_15 |= V_22 ;
if ( ! V_19 || F_2 ( V_2 -> V_3 -> V_20 ) )
* V_15 |= V_23 ;
} else
* V_15 = 0 ;
return 0 ;
}
static int
F_11 ( struct V_5 * V_24 , struct V_25 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_9 ( V_24 , struct V_1 , V_12 ) ;
if ( F_10 ( V_2 -> V_3 -> V_20 ) ) {
switch ( V_6 -> V_26 ) {
case 0 :
F_12 ( V_2 -> V_3 -> V_20 , 0 ) ;
break;
case 33 :
F_12 ( V_2 -> V_3 -> V_20 , 1 ) ;
break;
default:
return - V_16 ;
}
}
F_12 ( V_2 -> V_3 -> V_27 , V_6 -> V_28 & V_29 ) ;
F_6 ( & V_2 -> V_10 -> V_11 , L_4 ,
V_6 -> V_26 , V_6 -> V_30 , V_6 -> V_28 , V_6 -> V_31 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 )
{
return F_11 ( V_6 , & V_32 ) ;
}
static int F_14 ( struct V_5 * V_6 , struct V_33 * V_34 )
{
struct V_1 * V_2 ;
T_3 V_35 ;
V_2 = F_9 ( V_6 , struct V_1 , V_12 ) ;
V_34 -> V_28 &= ( V_36 | V_37 | V_38 ) ;
if ( ! ( V_34 -> V_28 & ( V_37 | V_38 ) ) ) {
V_35 = V_39 ;
F_6 ( & V_2 -> V_10 -> V_11 , L_5 ) ;
} else {
V_35 = V_40 ;
F_6 ( & V_2 -> V_10 -> V_11 , L_6 ) ;
}
F_15 ( V_41 , F_16 ( V_2 -> V_3 -> V_42 ) ,
V_43 , V_35 ) ;
V_34 -> V_44 = V_2 -> V_12 . V_45 ;
V_34 -> V_46 = V_34 -> V_44 + V_47 - 1 ;
return 0 ;
}
static int
F_17 ( struct V_5 * V_6 , struct V_48 * V_49 )
{
struct V_1 * V_2 ;
if ( V_49 -> V_50 )
return - V_16 ;
V_2 = F_9 ( V_6 , struct V_1 , V_12 ) ;
V_49 -> V_28 &= ( V_36 | V_51 | V_37 ) ;
if ( V_49 -> V_28 & V_51 )
V_49 -> V_52 = V_2 -> V_53 + V_54 ;
else
V_49 -> V_52 = V_2 -> V_53 + V_55 ;
return 0 ;
}
static int F_18 ( struct V_56 * V_10 )
{
struct V_57 * V_3 ;
V_3 = F_19 ( & V_10 -> V_11 , sizeof( * V_3 ) , V_58 ) ;
if ( ! V_3 )
return - V_59 ;
V_3 -> V_18 = F_20 ( V_10 -> V_11 . V_60 , 0 ) ;
V_3 -> V_4 = F_20 ( V_10 -> V_11 . V_60 , 1 ) ;
V_3 -> V_20 = F_20 ( V_10 -> V_11 . V_60 , 2 ) ;
V_3 -> V_27 = F_20 ( V_10 -> V_11 . V_60 , 3 ) ;
V_10 -> V_11 . V_61 = V_3 ;
V_41 = F_21 ( L_7 ) ;
if ( F_22 ( V_41 ) )
return F_23 ( V_41 ) ;
return 0 ;
}
static int F_18 ( struct V_56 * V_10 )
{
return - V_62 ;
}
static int F_24 ( struct V_56 * V_10 )
{
struct V_1 * V_2 ;
struct V_57 * V_3 = V_10 -> V_11 . V_61 ;
struct V_63 * V_34 ;
int V_64 ;
if ( ! V_3 ) {
V_64 = F_18 ( V_10 ) ;
if ( V_64 )
return V_64 ;
V_3 = V_10 -> V_11 . V_61 ;
}
if ( ! F_10 ( V_3 -> V_4 ) || ! F_10 ( V_3 -> V_27 ) )
return - V_62 ;
V_34 = F_25 ( V_10 , V_65 , 0 ) ;
if ( ! V_34 )
return - V_62 ;
V_2 = F_19 ( & V_10 -> V_11 , sizeof( * V_2 ) , V_58 ) ;
if ( ! V_2 )
return - V_59 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_53 = V_34 -> V_44 ;
F_26 ( V_10 , V_2 ) ;
V_64 = F_27 ( & V_10 -> V_11 , V_3 -> V_4 , L_8 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_28 ( & V_10 -> V_11 , F_5 ( V_3 -> V_4 ) ,
F_4 , 0 , L_9 , V_2 ) ;
if ( V_64 < 0 )
return V_64 ;
F_29 ( & V_10 -> V_11 , 1 ) ;
V_64 = F_27 ( & V_10 -> V_11 , V_3 -> V_27 , L_10 ) ;
if ( V_64 < 0 )
goto V_66;
if ( F_10 ( V_3 -> V_20 ) ) {
V_64 = F_27 ( & V_10 -> V_11 , V_3 -> V_20 , L_11 ) ;
if ( V_64 < 0 )
goto V_66;
}
if ( F_10 ( V_3 -> V_18 ) ) {
V_64 = F_27 ( & V_10 -> V_11 , V_3 -> V_18 , L_12 ) ;
if ( V_64 < 0 )
goto V_66;
V_64 = F_28 ( & V_10 -> V_11 , F_5 ( V_3 -> V_18 ) ,
F_4 , V_67 , L_13 , V_2 ) ;
if ( V_64 < 0 )
goto V_66;
V_2 -> V_12 . V_68 = F_5 ( V_3 -> V_18 ) ;
} else
V_2 -> V_12 . V_68 = V_69 + 1 ;
V_2 -> V_12 . V_45 = 0x10000 ;
V_64 = F_30 ( 0x10000 , V_2 -> V_53 + V_70 ) ;
if ( V_64 )
goto V_66;
if ( ! F_31 ( & V_10 -> V_11 , V_34 -> V_44 , F_32 ( V_34 ) , L_13 ) ) {
V_64 = - V_71 ;
goto V_66;
}
F_33 ( & V_10 -> V_11 , L_14 ,
F_5 ( V_3 -> V_4 ) , F_5 ( V_3 -> V_18 ) ) ;
V_2 -> V_12 . V_72 = V_73 ;
V_2 -> V_12 . V_11 . V_74 = & V_10 -> V_11 ;
V_2 -> V_12 . V_75 = & V_76 ;
V_2 -> V_12 . V_77 = & V_78 ;
V_2 -> V_12 . V_79 = V_80 | V_81
| V_82 ;
V_2 -> V_12 . V_83 = V_47 ;
V_2 -> V_12 . V_34 [ 0 ] . V_84 = V_34 ;
V_64 = F_34 ( & V_2 -> V_12 ) ;
if ( V_64 < 0 )
goto V_66;
return 0 ;
V_66:
F_29 ( & V_10 -> V_11 , 0 ) ;
return V_64 ;
}
static int F_35 ( struct V_56 * V_10 )
{
struct V_1 * V_2 = F_36 ( V_10 ) ;
F_37 ( & V_2 -> V_12 ) ;
F_29 ( & V_10 -> V_11 , 0 ) ;
return 0 ;
}
static int F_38 ( struct V_56 * V_10 , T_4 V_85 )
{
struct V_1 * V_2 = F_36 ( V_10 ) ;
struct V_57 * V_3 = V_2 -> V_3 ;
if ( F_39 ( & V_10 -> V_11 ) ) {
F_40 ( F_5 ( V_3 -> V_4 ) ) ;
if ( F_10 ( V_3 -> V_18 ) )
F_40 ( F_5 ( V_3 -> V_18 ) ) ;
}
return 0 ;
}
static int F_41 ( struct V_56 * V_10 )
{
struct V_1 * V_2 = F_36 ( V_10 ) ;
struct V_57 * V_3 = V_2 -> V_3 ;
if ( F_39 ( & V_10 -> V_11 ) ) {
F_42 ( F_5 ( V_3 -> V_4 ) ) ;
if ( F_10 ( V_3 -> V_18 ) )
F_42 ( F_5 ( V_3 -> V_18 ) ) ;
}
return 0 ;
}
