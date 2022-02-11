static void F_1 ( T_1 V_1 , struct V_2 * V_3 , int V_4 )
{
F_2 ( 0 , V_3 -> V_5 + V_6 ) ;
F_2 ( 0 , V_3 -> V_5 + V_6 ) ;
F_2 ( V_1 , V_3 -> V_5 + V_4 ) ;
F_3 ( 5 ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
T_1 V_7 ;
V_7 = F_5 ( V_3 -> V_8 + V_9 ) ;
V_7 &= ~ V_10 ;
V_7 |= 0x3FF << V_11 ;
V_7 &= ~ V_12 ;
V_7 |= 0x1F << V_13 ;
F_2 ( V_7 , V_3 -> V_8 + V_9 ) ;
}
static void F_6 ( struct V_2 * V_3 )
{
T_1 V_7 ;
V_7 = F_5 ( V_3 -> V_8 + V_14 ) ;
V_7 &= ~ V_15 ;
V_7 |= 0x3FF << V_16 ;
V_7 &= ~ V_17 ;
V_7 |= 0x29 << V_18 ;
F_2 ( V_7 , V_3 -> V_8 + V_14 ) ;
V_7 = F_5 ( V_3 -> V_8 + V_19 ) ;
V_7 &= ~ V_20 ;
V_7 |= 0x3F << V_21 ;
F_2 ( V_7 , V_3 -> V_8 + V_19 ) ;
}
static T_1 F_7 ( struct V_2 * V_3 , T_2 V_22 )
{
return F_5 ( V_3 -> V_5 + V_22 ) ;
}
static T_1 F_8 ( struct V_2 * V_3 , T_2 V_22 )
{
int V_23 , V_24 = 0 , V_25 = 0 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
V_3 -> V_27 [ V_23 ] . V_28 = F_5 ( V_3 -> V_5 + V_22 ) ;
V_3 -> V_27 [ V_23 ] . V_29 = 0 ;
}
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
int V_30 = 0 ;
T_1 V_28 = V_3 -> V_27 [ V_23 ] . V_28 ;
while ( V_3 -> V_27 [ V_30 ] . V_29 ) {
if ( V_3 -> V_27 [ V_30 ] . V_28 == V_28 ) {
V_3 -> V_27 [ V_30 ] . V_29 ++ ;
break;
}
V_30 ++ ;
}
if ( ! V_3 -> V_27 [ V_30 ] . V_29 ) {
V_3 -> V_27 [ V_30 ] . V_28 = V_28 ;
V_3 -> V_27 [ V_30 ] . V_29 = 1 ;
}
if ( V_3 -> V_27 [ V_30 ] . V_29 > V_25 ) {
V_24 = V_30 ;
V_25 = V_3 -> V_27 [ V_30 ] . V_29 ;
}
if ( V_25 > V_26 / 2 )
break;
}
return V_3 -> V_27 [ V_24 ] . V_28 ;
}
static void F_9 ( struct V_2 * V_3 )
{
T_1 V_1 = F_5 ( V_3 -> V_8 + V_31 ) ;
F_2 ( V_1 & ~ V_32 , V_3 -> V_8 + V_31 ) ;
}
static void F_10 ( struct V_2 * V_3 )
{
T_1 V_1 = F_5 ( V_3 -> V_8 + V_31 ) ;
F_2 ( V_1 | V_33 , V_3 -> V_8 + V_31 ) ;
}
static void F_11 ( struct V_2 * V_3 )
{
F_2 ( V_34 , V_3 -> V_8 + V_35 ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
F_2 ( V_34 , V_3 -> V_8 + V_36 ) ;
}
static int F_13 ( struct V_37 * V_38 , struct V_39 * V_40 )
{
struct V_2 * V_3 = F_14 ( V_38 ) ;
unsigned long time , V_41 ;
F_15 ( & V_3 -> V_42 , V_41 ) ;
time = V_3 -> V_43 -> V_44 ( V_3 , V_45 ) ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
F_17 ( time , V_40 ) ;
return 0 ;
}
static int F_18 ( struct V_37 * V_38 , struct V_39 * V_40 )
{
struct V_2 * V_3 = F_14 ( V_38 ) ;
int V_46 = 0 ;
unsigned long time , V_41 ;
V_46 = F_19 ( V_40 , & time ) ;
if ( V_46 )
goto V_47;
F_15 ( & V_3 -> V_42 , V_41 ) ;
F_1 ( time , V_3 , V_45 ) ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
V_47:
return V_46 ;
}
static int F_20 ( struct V_37 * V_38 , struct V_48 * V_49 )
{
struct V_2 * V_3 = F_14 ( V_38 ) ;
unsigned long time , V_41 ;
T_1 V_7 = F_21 ( V_50 , V_3 -> V_43 -> V_51 ) ;
T_1 V_52 = F_21 ( V_53 , V_3 -> V_43 -> V_51 ) ;
T_1 V_1 ;
F_15 ( & V_3 -> V_42 , V_41 ) ;
time = V_3 -> V_43 -> V_44 ( V_3 , V_7 ) ;
V_1 = V_3 -> V_43 -> V_44 ( V_3 , V_52 ) & V_54 ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
V_49 -> V_55 = V_1 ? 1 : 0 ;
F_17 ( time , & V_49 -> time ) ;
return 0 ;
}
static int F_22 ( struct V_37 * V_38 , struct V_48 * V_49 )
{
struct V_2 * V_3 = F_14 ( V_38 ) ;
T_1 V_7 = F_21 ( V_50 , V_3 -> V_43 -> V_51 ) ;
T_1 V_52 = F_21 ( V_53 , V_3 -> V_43 -> V_51 ) ;
unsigned long time , V_41 ;
int V_46 = 0 ;
V_46 = F_19 ( & V_49 -> time , & time ) ;
if ( V_46 )
goto V_47;
F_15 ( & V_3 -> V_42 , V_41 ) ;
F_1 ( time , V_3 , V_7 ) ;
if ( V_49 -> V_55 ) {
F_1 ( V_54 , V_3 , V_52 ) ;
V_3 -> V_43 -> V_56 ( V_3 ) ;
}
F_16 ( & V_3 -> V_42 , V_41 ) ;
V_47:
return V_46 ;
}
static int F_23 ( struct V_37 * V_38 ,
unsigned int V_55 )
{
struct V_2 * V_3 = F_14 ( V_38 ) ;
T_1 V_52 = F_21 ( V_53 , V_3 -> V_43 -> V_51 ) ;
unsigned long V_41 ;
F_15 ( & V_3 -> V_42 , V_41 ) ;
if ( V_55 )
F_1 ( V_54 , V_3 , V_52 ) ;
else
F_1 ( 0 , V_3 , V_52 ) ;
F_16 ( & V_3 -> V_42 , V_41 ) ;
return 0 ;
}
static T_3 F_24 ( int V_57 , void * V_43 )
{
struct V_2 * V_3 = V_43 ;
T_1 V_1 ;
int V_58 = V_59 | V_60 ;
T_1 V_52 = F_21 ( V_53 , V_3 -> V_43 -> V_51 ) ;
F_25 ( & V_3 -> V_61 -> V_38 , L_1 , V_62 , V_57 ) ;
F_26 ( & V_3 -> V_42 ) ;
V_3 -> V_43 -> V_63 ( V_3 ) ;
V_1 = V_3 -> V_43 -> V_44 ( V_3 , V_52 ) ;
F_1 ( 0 , V_3 , V_52 ) ;
F_1 ( 1 << V_3 -> V_43 -> V_51 , V_3 , V_6 ) ;
F_27 ( & V_3 -> V_42 ) ;
if ( V_1 & V_64 ) {
if ( V_1 & V_65 )
V_58 |= V_66 ;
else
V_58 |= V_67 ;
}
F_28 ( V_3 -> V_61 , 1 , V_58 ) ;
return V_68 ;
}
static T_4 int F_29 ( struct V_69 * V_70 )
{
const struct V_71 * V_72 ;
struct V_73 * V_74 ;
struct V_2 * V_3 ;
const struct V_75 * V_76 ;
int V_46 ;
V_76 = F_30 ( V_77 , & V_70 -> V_38 ) ;
if ( ! V_76 )
return - V_78 ;
V_3 = F_31 ( & V_70 -> V_38 , sizeof( struct V_2 ) ,
V_79 ) ;
if ( ! V_3 )
return - V_80 ;
V_3 -> V_27 = F_32 ( & V_70 -> V_38 , V_26 ,
sizeof( struct V_81 ) , V_79 ) ;
if ( ! V_3 -> V_27 )
return - V_80 ;
F_33 ( & V_3 -> V_42 ) ;
V_74 = F_34 ( V_70 , V_82 , L_2 ) ;
V_3 -> V_5 = F_35 ( & V_70 -> V_38 , V_74 ) ;
if ( F_36 ( V_3 -> V_5 ) )
return F_37 ( V_3 -> V_5 ) ;
V_74 = F_34 ( V_70 , V_82 , L_3 ) ;
V_3 -> V_8 = F_35 ( & V_70 -> V_38 , V_74 ) ;
if ( F_36 ( V_3 -> V_8 ) )
return F_37 ( V_3 -> V_8 ) ;
V_3 -> V_57 = F_38 ( V_70 , 0 ) ;
if ( V_3 -> V_57 < 0 ) {
F_39 ( & V_70 -> V_38 , L_4 ) ;
return V_3 -> V_57 ;
}
if ( F_40 ( & V_70 -> V_38 , V_3 -> V_57 , F_24 ,
0 , V_70 -> V_83 , V_3 ) < 0 ) {
F_41 ( & V_70 -> V_38 , L_5 ) ;
V_3 -> V_57 = - 1 ;
}
F_42 ( V_70 , V_3 ) ;
if ( V_3 -> V_57 != - 1 ) {
F_43 ( & V_70 -> V_38 , 1 ) ;
V_72 = & V_84 ;
} else {
V_72 = & V_85 ;
}
V_3 -> V_43 = (struct V_86 * ) V_76 -> V_43 ;
V_3 -> V_43 -> V_87 ( V_3 ) ;
V_3 -> V_61 = F_44 ( & V_70 -> V_38 , V_70 -> V_83 ,
V_72 , V_88 ) ;
if ( F_36 ( V_3 -> V_61 ) ) {
V_46 = F_37 ( V_3 -> V_61 ) ;
F_39 ( & V_70 -> V_38 , L_6 , V_46 ) ;
return V_46 ;
}
return 0 ;
}
static int F_45 ( struct V_37 * V_38 )
{
if ( F_46 ( V_38 ) ) {
struct V_2 * V_3 = F_14 ( V_38 ) ;
return F_47 ( V_3 -> V_57 ) ;
}
return 0 ;
}
static int F_48 ( struct V_37 * V_38 )
{
if ( F_46 ( V_38 ) ) {
struct V_2 * V_3 = F_14 ( V_38 ) ;
V_3 -> V_43 -> V_87 ( V_3 ) ;
return F_49 ( V_3 -> V_57 ) ;
}
return 0 ;
}
