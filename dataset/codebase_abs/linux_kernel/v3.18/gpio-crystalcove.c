static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline int F_3 ( int V_5 , enum V_6 V_7 )
{
int V_8 ;
if ( V_7 == V_9 ) {
if ( V_5 < 8 )
V_8 = V_10 ;
else
V_8 = V_11 ;
} else {
if ( V_5 < 8 )
V_8 = V_12 ;
else
V_8 = V_13 ;
}
return V_8 + V_5 % 8 ;
}
static void F_4 ( struct V_1 * V_14 ,
int V_5 )
{
T_1 V_15 = V_5 < 8 ? V_16 : V_17 ;
int V_18 = F_5 ( V_5 % 8 ) ;
if ( V_14 -> V_19 )
F_6 ( V_14 -> V_20 , V_15 , V_18 , V_18 ) ;
else
F_6 ( V_14 -> V_20 , V_15 , V_18 , 0 ) ;
}
static void F_7 ( struct V_1 * V_14 , int V_5 )
{
int V_8 = F_3 ( V_5 , V_9 ) ;
F_6 ( V_14 -> V_20 , V_8 , V_21 , V_14 -> V_22 ) ;
}
static int F_8 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
if ( V_5 > V_23 )
return 0 ;
return F_9 ( V_14 -> V_20 , F_3 ( V_5 , V_24 ) ,
V_25 ) ;
}
static int F_10 ( struct V_2 * V_4 , unsigned V_5 ,
int V_26 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
if ( V_5 > V_23 )
return 0 ;
return F_9 ( V_14 -> V_20 , F_3 ( V_5 , V_24 ) ,
V_27 | V_26 ) ;
}
static int F_11 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
int V_28 ;
unsigned int V_29 ;
if ( V_5 > V_23 )
return 0 ;
V_28 = F_12 ( V_14 -> V_20 , F_3 ( V_5 , V_9 ) , & V_29 ) ;
if ( V_28 )
return V_28 ;
return V_29 & 0x1 ;
}
static void F_13 ( struct V_2 * V_4 ,
unsigned V_5 , int V_26 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
if ( V_5 > V_23 )
return;
if ( V_26 )
F_6 ( V_14 -> V_20 , F_3 ( V_5 , V_24 ) , 1 , 1 ) ;
else
F_6 ( V_14 -> V_20 , F_3 ( V_5 , V_24 ) , 1 , 0 ) ;
}
static int F_14 ( struct V_30 * V_31 , unsigned type )
{
struct V_1 * V_14 = F_1 ( F_15 ( V_31 ) ) ;
switch ( type ) {
case V_32 :
V_14 -> V_22 = V_33 ;
break;
case V_34 :
V_14 -> V_22 = V_21 ;
break;
case V_35 :
V_14 -> V_22 = V_36 ;
break;
case V_37 :
V_14 -> V_22 = V_38 ;
break;
default:
return - V_39 ;
}
V_14 -> V_40 |= V_41 ;
return 0 ;
}
static void F_16 ( struct V_30 * V_31 )
{
struct V_1 * V_14 = F_1 ( F_15 ( V_31 ) ) ;
F_17 ( & V_14 -> V_42 ) ;
}
static void F_18 ( struct V_30 * V_31 )
{
struct V_1 * V_14 = F_1 ( F_15 ( V_31 ) ) ;
int V_5 = V_31 -> V_43 ;
if ( V_14 -> V_40 & V_41 )
F_7 ( V_14 , V_5 ) ;
if ( V_14 -> V_40 & V_44 )
F_4 ( V_14 , V_5 ) ;
V_14 -> V_40 = 0 ;
F_19 ( & V_14 -> V_42 ) ;
}
static void F_20 ( struct V_30 * V_31 )
{
struct V_1 * V_14 = F_1 ( F_15 ( V_31 ) ) ;
V_14 -> V_19 = false ;
V_14 -> V_40 |= V_44 ;
}
static void F_21 ( struct V_30 * V_31 )
{
struct V_1 * V_14 = F_1 ( F_15 ( V_31 ) ) ;
V_14 -> V_19 = true ;
V_14 -> V_40 |= V_44 ;
}
static T_2 F_22 ( int V_45 , void * V_31 )
{
struct V_1 * V_14 = V_31 ;
unsigned int V_46 , V_47 ;
int V_48 ;
int V_5 ;
unsigned int V_49 ;
if ( F_12 ( V_14 -> V_20 , V_50 , & V_46 ) ||
F_12 ( V_14 -> V_20 , V_51 , & V_47 ) )
return V_52 ;
F_9 ( V_14 -> V_20 , V_50 , V_46 ) ;
F_9 ( V_14 -> V_20 , V_51 , V_47 ) ;
V_48 = V_46 | V_47 << 8 ;
for ( V_5 = 0 ; V_5 < V_53 ; V_5 ++ ) {
if ( V_48 & F_5 ( V_5 ) ) {
V_49 = F_23 ( V_14 -> V_4 . V_54 , V_5 ) ;
F_24 ( V_49 ) ;
}
}
return V_55 ;
}
static void F_25 ( struct V_56 * V_57 ,
struct V_2 * V_4 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
int V_5 , V_58 ;
unsigned int V_59 , V_60 , V_15 , V_61 , V_45 ;
for ( V_5 = 0 ; V_5 < V_53 ; V_5 ++ ) {
F_12 ( V_14 -> V_20 , F_3 ( V_5 , V_24 ) , & V_59 ) ;
F_12 ( V_14 -> V_20 , F_3 ( V_5 , V_9 ) , & V_60 ) ;
F_12 ( V_14 -> V_20 , V_5 < 8 ? V_16 : V_17 ,
& V_15 ) ;
F_12 ( V_14 -> V_20 , V_5 < 8 ? V_62 : V_63 ,
& V_61 ) ;
F_12 ( V_14 -> V_20 , V_5 < 8 ? V_50 : V_51 ,
& V_45 ) ;
V_58 = V_5 % 8 ;
F_26 ( V_57 , L_1 ,
V_5 , V_59 & V_64 ? L_2 : L_3 ,
V_60 & 0x1 ? L_4 : L_5 ,
V_60 & V_38 ? L_6 : L_7 ,
V_60 & V_36 ? L_8 : L_7 ,
V_59 ,
V_15 & F_5 ( V_58 ) ? L_9 : L_10 ,
V_61 & F_5 ( V_58 ) ? L_11 : L_12 ,
V_45 & F_5 ( V_58 ) ? L_13 : L_14 ) ;
}
}
static int F_27 ( struct V_65 * V_66 )
{
int V_45 = F_28 ( V_66 , 0 ) ;
struct V_1 * V_14 ;
int V_67 ;
struct V_68 * V_69 = V_66 -> V_69 . V_70 ;
struct V_71 * V_72 = F_29 ( V_69 ) ;
if ( V_45 < 0 )
return V_45 ;
V_14 = F_30 ( & V_66 -> V_69 , sizeof( * V_14 ) , V_73 ) ;
if ( ! V_14 )
return - V_74 ;
F_31 ( V_66 , V_14 ) ;
F_32 ( & V_14 -> V_42 ) ;
V_14 -> V_4 . V_75 = V_76 ;
V_14 -> V_4 . V_77 = F_8 ;
V_14 -> V_4 . V_78 = F_10 ;
V_14 -> V_4 . V_79 = F_11 ;
V_14 -> V_4 . V_80 = F_13 ;
V_14 -> V_4 . V_81 = - 1 ;
V_14 -> V_4 . V_82 = V_23 ;
V_14 -> V_4 . V_83 = true ;
V_14 -> V_4 . V_69 = V_69 ;
V_14 -> V_4 . V_84 = F_25 ;
V_14 -> V_20 = V_72 -> V_20 ;
V_67 = F_33 ( & V_14 -> V_4 ) ;
if ( V_67 ) {
F_34 ( & V_66 -> V_69 , L_15 , V_67 ) ;
return V_67 ;
}
F_35 ( & V_14 -> V_4 , & V_85 , 0 ,
V_86 , V_32 ) ;
V_67 = F_36 ( V_45 , NULL , F_22 ,
V_87 , V_76 , V_14 ) ;
if ( V_67 ) {
F_34 ( & V_66 -> V_69 , L_16 , V_67 ) ;
goto V_88;
}
return 0 ;
V_88:
F_37 ( & V_14 -> V_4 ) ;
return V_67 ;
}
static int F_38 ( struct V_65 * V_66 )
{
struct V_1 * V_14 = F_39 ( V_66 ) ;
int V_45 = F_28 ( V_66 , 0 ) ;
F_37 ( & V_14 -> V_4 ) ;
if ( V_45 >= 0 )
F_40 ( V_45 , V_14 ) ;
return 0 ;
}
