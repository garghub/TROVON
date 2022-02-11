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
if ( V_7 == V_2 -> V_3 -> V_4 ) {
unsigned V_9 = F_1 ( V_2 ) ;
if ( V_9 != V_2 -> V_9 ) {
V_2 -> V_9 = V_9 ;
F_5 ( L_1 , V_10 ,
V_9 ? L_2 : L_3 ) ;
F_6 ( & V_2 -> V_11 , V_12 ) ;
}
}
return V_13 ;
}
static int F_7 ( struct V_5 * V_6 , T_2 * V_14 )
{
struct V_1 * V_2 ;
if ( ! V_14 )
return - V_15 ;
V_2 = F_8 ( V_6 , struct V_1 , V_11 ) ;
if ( F_1 ( V_2 ) ) {
int V_16 = V_2 -> V_3 -> V_17 ;
int V_18 = V_2 -> V_3 -> V_19 ;
* V_14 = V_12 | V_20 ;
if ( ! V_16 || F_2 ( V_16 ) )
* V_14 |= V_21 ;
if ( ! V_18 || F_2 ( V_18 ) )
* V_14 |= V_22 ;
} else
* V_14 = 0 ;
return 0 ;
}
static int
F_9 ( struct V_5 * V_23 , struct V_24 * V_6 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( V_23 , struct V_1 , V_11 ) ;
if ( V_2 -> V_3 -> V_19 ) {
switch ( V_6 -> V_25 ) {
case 0 :
F_10 ( V_2 -> V_3 -> V_19 , 0 ) ;
break;
case 33 :
F_10 ( V_2 -> V_3 -> V_19 , 1 ) ;
break;
default:
return - V_15 ;
}
}
F_10 ( V_2 -> V_3 -> V_26 , V_6 -> V_27 & V_28 ) ;
F_5 ( L_4 ,
V_10 , V_6 -> V_25 , V_6 -> V_29 , V_6 -> V_27 , V_6 -> V_30 ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 )
{
return F_9 ( V_6 , & V_31 ) ;
}
static int F_12 ( struct V_5 * V_6 , struct V_32 * V_33 )
{
struct V_1 * V_2 ;
T_3 V_34 ;
V_2 = F_8 ( V_6 , struct V_1 , V_11 ) ;
V_33 -> V_27 &= ( V_35 | V_36 | V_37 ) ;
V_34 = F_13 ( F_14 ( V_2 -> V_3 -> V_38 ) ) & ~ V_39 ;
if ( ! ( V_33 -> V_27 & ( V_36 | V_37 ) ) ) {
V_34 |= V_40 ;
F_5 ( L_5 , V_10 ) ;
} else {
V_34 |= V_41 ;
F_5 ( L_6 , V_10 ) ;
}
F_15 ( F_14 ( V_2 -> V_3 -> V_38 ) , V_34 ) ;
V_33 -> V_42 = V_2 -> V_11 . V_43 ;
V_33 -> V_44 = V_33 -> V_42 + V_45 - 1 ;
return 0 ;
}
static int
F_16 ( struct V_5 * V_6 , struct V_46 * V_47 )
{
struct V_1 * V_2 ;
if ( V_47 -> V_48 )
return - V_15 ;
V_2 = F_8 ( V_6 , struct V_1 , V_11 ) ;
V_47 -> V_27 &= ( V_35 | V_49 | V_36 ) ;
if ( V_47 -> V_27 & V_49 )
V_47 -> V_50 = V_2 -> V_51 + V_52 ;
else
V_47 -> V_50 = V_2 -> V_51 + V_53 ;
return 0 ;
}
static int T_4 F_17 ( struct V_54 * V_55 )
{
struct V_1 * V_2 ;
struct V_56 * V_3 = V_55 -> V_57 . V_58 ;
struct V_59 * V_33 ;
int V_60 ;
if ( ! V_3 || ! V_3 -> V_4 || ! V_3 -> V_26 )
return - V_61 ;
V_33 = F_18 ( V_55 , V_62 , 0 ) ;
if ( ! V_33 )
return - V_61 ;
V_2 = F_19 ( sizeof *V_2 , V_63 ) ;
if ( ! V_2 )
return - V_64 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_55 = V_55 ;
V_2 -> V_51 = V_33 -> V_42 ;
F_20 ( V_55 , V_2 ) ;
V_60 = F_21 ( V_3 -> V_4 , L_7 ) ;
if ( V_60 < 0 )
goto V_65;
V_60 = F_22 ( V_3 -> V_4 , F_4 , 0 , V_10 , V_2 ) ;
if ( V_60 < 0 )
goto V_66;
F_23 ( & V_55 -> V_57 , 1 ) ;
V_60 = F_21 ( V_3 -> V_26 , L_8 ) ;
if ( V_60 < 0 )
goto V_67;
if ( V_3 -> V_19 ) {
V_60 = F_21 ( V_3 -> V_19 , L_9 ) ;
if ( V_60 < 0 )
goto V_68;
}
if ( V_3 -> V_17 ) {
V_60 = F_21 ( V_3 -> V_17 , L_10 ) ;
if ( V_60 < 0 )
goto V_69;
V_60 = F_22 ( V_3 -> V_17 , F_4 ,
V_70 , V_10 , V_2 ) ;
if ( V_60 < 0 )
goto V_71;
V_2 -> V_11 . V_72 = V_3 -> V_17 ;
} else
V_2 -> V_11 . V_72 = V_73 + 1 ;
V_2 -> V_11 . V_43 = ( unsigned long )
F_24 ( V_2 -> V_51 + V_74 , V_45 ) ;
if ( ! V_2 -> V_11 . V_43 ) {
V_60 = - V_75 ;
goto V_76;
}
if ( ! F_25 ( V_33 -> V_42 , F_26 ( V_33 ) , V_10 ) ) {
V_60 = - V_75 ;
goto V_76;
}
F_27 ( L_11 , V_10 ,
V_3 -> V_4 , V_3 -> V_17 ) ;
V_2 -> V_11 . V_77 = V_78 ;
V_2 -> V_11 . V_57 . V_79 = & V_55 -> V_57 ;
V_2 -> V_11 . V_80 = & V_81 ;
V_2 -> V_11 . V_82 = & V_83 ;
V_2 -> V_11 . V_84 = V_85 | V_86
| V_87 ;
V_2 -> V_11 . V_88 = V_45 ;
V_2 -> V_11 . V_33 [ 0 ] . V_89 = V_33 ;
V_60 = F_28 ( & V_2 -> V_11 ) ;
if ( V_60 < 0 )
goto V_90;
return 0 ;
V_90:
F_29 ( V_33 -> V_42 , F_26 ( V_33 ) ) ;
V_76:
if ( V_2 -> V_11 . V_43 )
F_30 ( ( void V_91 * ) V_2 -> V_11 . V_43 ) ;
if ( V_3 -> V_17 ) {
F_31 ( V_3 -> V_17 , V_2 ) ;
V_71:
F_32 ( V_3 -> V_17 ) ;
}
V_69:
if ( V_3 -> V_19 )
F_32 ( V_3 -> V_19 ) ;
V_68:
F_32 ( V_3 -> V_26 ) ;
V_67:
F_23 ( & V_55 -> V_57 , 0 ) ;
F_31 ( V_3 -> V_4 , V_2 ) ;
V_66:
F_32 ( V_3 -> V_4 ) ;
V_65:
F_33 ( V_2 ) ;
return V_60 ;
}
static int T_5 F_34 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_35 ( V_55 ) ;
struct V_56 * V_3 = V_2 -> V_3 ;
struct V_59 * V_33 = V_2 -> V_11 . V_33 [ 0 ] . V_89 ;
F_36 ( & V_2 -> V_11 ) ;
F_29 ( V_33 -> V_42 , F_26 ( V_33 ) ) ;
F_30 ( ( void V_91 * ) V_2 -> V_11 . V_43 ) ;
if ( V_3 -> V_17 ) {
F_31 ( V_3 -> V_17 , V_2 ) ;
F_32 ( V_3 -> V_17 ) ;
}
if ( V_3 -> V_19 )
F_32 ( V_3 -> V_19 ) ;
F_32 ( V_3 -> V_26 ) ;
F_23 ( & V_55 -> V_57 , 0 ) ;
F_31 ( V_3 -> V_4 , V_2 ) ;
F_32 ( V_3 -> V_4 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_54 * V_55 , T_6 V_92 )
{
struct V_1 * V_2 = F_35 ( V_55 ) ;
struct V_56 * V_3 = V_2 -> V_3 ;
if ( F_38 ( & V_55 -> V_57 ) ) {
F_39 ( V_3 -> V_4 ) ;
if ( V_3 -> V_17 )
F_39 ( V_3 -> V_17 ) ;
}
return 0 ;
}
static int F_40 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_35 ( V_55 ) ;
struct V_56 * V_3 = V_2 -> V_3 ;
if ( F_38 ( & V_55 -> V_57 ) ) {
F_41 ( V_3 -> V_4 ) ;
if ( V_3 -> V_17 )
F_41 ( V_3 -> V_17 ) ;
}
return 0 ;
}
static int T_4 F_42 ( void )
{
return F_43 ( & V_93 , F_17 ) ;
}
static void T_5 F_44 ( void )
{
F_45 ( & V_93 ) ;
}
