static inline int F_1 ( int V_1 , enum V_2 V_3 )
{
int V_4 ;
if ( V_1 == 94 )
return V_5 ;
if ( V_3 == V_6 ) {
if ( V_1 < 8 )
V_4 = V_7 ;
else
V_4 = V_8 ;
} else {
if ( V_1 < 8 )
V_4 = V_9 ;
else
V_4 = V_10 ;
}
return V_4 + V_1 % 8 ;
}
static void F_2 ( struct V_11 * V_12 ,
int V_1 )
{
T_1 V_13 = V_1 < 8 ? V_14 : V_15 ;
int V_16 = F_3 ( V_1 % 8 ) ;
if ( V_12 -> V_17 )
F_4 ( V_12 -> V_18 , V_13 , V_16 , V_16 ) ;
else
F_4 ( V_12 -> V_18 , V_13 , V_16 , 0 ) ;
}
static void F_5 ( struct V_11 * V_12 , int V_1 )
{
int V_4 = F_1 ( V_1 , V_6 ) ;
F_4 ( V_12 -> V_18 , V_4 , V_19 , V_12 -> V_20 ) ;
}
static int F_6 ( struct V_21 * V_22 , unsigned V_1 )
{
struct V_11 * V_12 = F_7 ( V_22 ) ;
if ( V_1 > V_23 )
return 0 ;
return F_8 ( V_12 -> V_18 , F_1 ( V_1 , V_24 ) ,
V_25 ) ;
}
static int F_9 ( struct V_21 * V_22 , unsigned V_1 ,
int V_26 )
{
struct V_11 * V_12 = F_7 ( V_22 ) ;
if ( V_1 > V_23 )
return 0 ;
return F_8 ( V_12 -> V_18 , F_1 ( V_1 , V_24 ) ,
V_27 | V_26 ) ;
}
static int F_10 ( struct V_21 * V_22 , unsigned V_1 )
{
struct V_11 * V_12 = F_7 ( V_22 ) ;
int V_28 ;
unsigned int V_29 ;
if ( V_1 > V_23 )
return 0 ;
V_28 = F_11 ( V_12 -> V_18 , F_1 ( V_1 , V_6 ) , & V_29 ) ;
if ( V_28 )
return V_28 ;
return V_29 & 0x1 ;
}
static void F_12 ( struct V_21 * V_22 ,
unsigned V_1 , int V_26 )
{
struct V_11 * V_12 = F_7 ( V_22 ) ;
if ( V_1 > V_23 )
return;
if ( V_26 )
F_4 ( V_12 -> V_18 , F_1 ( V_1 , V_24 ) , 1 , 1 ) ;
else
F_4 ( V_12 -> V_18 , F_1 ( V_1 , V_24 ) , 1 , 0 ) ;
}
static int F_13 ( struct V_30 * V_31 , unsigned type )
{
struct V_11 * V_12 =
F_7 ( F_14 ( V_31 ) ) ;
switch ( type ) {
case V_32 :
V_12 -> V_20 = V_33 ;
break;
case V_34 :
V_12 -> V_20 = V_19 ;
break;
case V_35 :
V_12 -> V_20 = V_36 ;
break;
case V_37 :
V_12 -> V_20 = V_38 ;
break;
default:
return - V_39 ;
}
V_12 -> V_40 |= V_41 ;
return 0 ;
}
static void F_15 ( struct V_30 * V_31 )
{
struct V_11 * V_12 =
F_7 ( F_14 ( V_31 ) ) ;
F_16 ( & V_12 -> V_42 ) ;
}
static void F_17 ( struct V_30 * V_31 )
{
struct V_11 * V_12 =
F_7 ( F_14 ( V_31 ) ) ;
int V_1 = V_31 -> V_43 ;
if ( V_12 -> V_40 & V_41 )
F_5 ( V_12 , V_1 ) ;
if ( V_12 -> V_40 & V_44 )
F_2 ( V_12 , V_1 ) ;
V_12 -> V_40 = 0 ;
F_18 ( & V_12 -> V_42 ) ;
}
static void F_19 ( struct V_30 * V_31 )
{
struct V_11 * V_12 =
F_7 ( F_14 ( V_31 ) ) ;
V_12 -> V_17 = false ;
V_12 -> V_40 |= V_44 ;
}
static void F_20 ( struct V_30 * V_31 )
{
struct V_11 * V_12 =
F_7 ( F_14 ( V_31 ) ) ;
V_12 -> V_17 = true ;
V_12 -> V_40 |= V_44 ;
}
static T_2 F_21 ( int V_45 , void * V_31 )
{
struct V_11 * V_12 = V_31 ;
unsigned int V_46 , V_47 ;
int V_48 ;
int V_1 ;
unsigned int V_49 ;
if ( F_11 ( V_12 -> V_18 , V_50 , & V_46 ) ||
F_11 ( V_12 -> V_18 , V_51 , & V_47 ) )
return V_52 ;
F_8 ( V_12 -> V_18 , V_50 , V_46 ) ;
F_8 ( V_12 -> V_18 , V_51 , V_47 ) ;
V_48 = V_46 | V_47 << 8 ;
for ( V_1 = 0 ; V_1 < V_53 ; V_1 ++ ) {
if ( V_48 & F_3 ( V_1 ) ) {
V_49 = F_22 ( V_12 -> V_22 . V_54 , V_1 ) ;
F_23 ( V_49 ) ;
}
}
return V_55 ;
}
static void F_24 ( struct V_56 * V_57 ,
struct V_21 * V_22 )
{
struct V_11 * V_12 = F_7 ( V_22 ) ;
int V_1 , V_58 ;
unsigned int V_59 , V_60 , V_13 , V_61 , V_45 ;
for ( V_1 = 0 ; V_1 < V_53 ; V_1 ++ ) {
F_11 ( V_12 -> V_18 , F_1 ( V_1 , V_24 ) , & V_59 ) ;
F_11 ( V_12 -> V_18 , F_1 ( V_1 , V_6 ) , & V_60 ) ;
F_11 ( V_12 -> V_18 , V_1 < 8 ? V_14 : V_15 ,
& V_13 ) ;
F_11 ( V_12 -> V_18 , V_1 < 8 ? V_62 : V_63 ,
& V_61 ) ;
F_11 ( V_12 -> V_18 , V_1 < 8 ? V_50 : V_51 ,
& V_45 ) ;
V_58 = V_1 % 8 ;
F_25 ( V_57 , L_1 ,
V_1 , V_59 & V_64 ? L_2 : L_3 ,
V_60 & 0x1 ? L_4 : L_5 ,
V_60 & V_38 ? L_6 : L_7 ,
V_60 & V_36 ? L_8 : L_7 ,
V_59 ,
V_13 & F_3 ( V_58 ) ? L_9 : L_10 ,
V_61 & F_3 ( V_58 ) ? L_11 : L_12 ,
V_45 & F_3 ( V_58 ) ? L_13 : L_14 ) ;
}
}
static int F_26 ( struct V_65 * V_66 )
{
int V_45 = F_27 ( V_66 , 0 ) ;
struct V_11 * V_12 ;
int V_67 ;
struct V_68 * V_69 = V_66 -> V_69 . V_70 ;
struct V_71 * V_72 = F_28 ( V_69 ) ;
if ( V_45 < 0 )
return V_45 ;
V_12 = F_29 ( & V_66 -> V_69 , sizeof( * V_12 ) , V_73 ) ;
if ( ! V_12 )
return - V_74 ;
F_30 ( V_66 , V_12 ) ;
F_31 ( & V_12 -> V_42 ) ;
V_12 -> V_22 . V_75 = V_76 ;
V_12 -> V_22 . V_77 = F_6 ;
V_12 -> V_22 . V_78 = F_9 ;
V_12 -> V_22 . V_79 = F_10 ;
V_12 -> V_22 . V_80 = F_12 ;
V_12 -> V_22 . V_81 = - 1 ;
V_12 -> V_22 . V_82 = V_23 ;
V_12 -> V_22 . V_83 = true ;
V_12 -> V_22 . V_70 = V_69 ;
V_12 -> V_22 . V_84 = F_24 ;
V_12 -> V_18 = V_72 -> V_18 ;
V_67 = F_32 ( & V_12 -> V_22 , V_12 ) ;
if ( V_67 ) {
F_33 ( & V_66 -> V_69 , L_15 , V_67 ) ;
return V_67 ;
}
F_34 ( & V_12 -> V_22 , & V_85 , 0 ,
V_86 , V_32 ) ;
V_67 = F_35 ( V_45 , NULL , F_21 ,
V_87 , V_76 , V_12 ) ;
if ( V_67 ) {
F_33 ( & V_66 -> V_69 , L_16 , V_67 ) ;
goto V_88;
}
return 0 ;
V_88:
F_36 ( & V_12 -> V_22 ) ;
return V_67 ;
}
static int F_37 ( struct V_65 * V_66 )
{
struct V_11 * V_12 = F_38 ( V_66 ) ;
int V_45 = F_27 ( V_66 , 0 ) ;
F_36 ( & V_12 -> V_22 ) ;
if ( V_45 >= 0 )
F_39 ( V_45 , V_12 ) ;
return 0 ;
}
