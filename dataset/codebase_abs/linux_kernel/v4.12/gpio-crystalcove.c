static inline int F_1 ( int V_1 , enum V_2 V_3 )
{
int V_4 ;
if ( V_1 >= V_5 ) {
switch ( V_1 ) {
case 0x5e :
return V_6 ;
default:
return - V_7 ;
}
}
if ( V_3 == V_8 ) {
if ( V_1 < 8 )
V_4 = V_9 ;
else
V_4 = V_10 ;
} else {
if ( V_1 < 8 )
V_4 = V_11 ;
else
V_4 = V_12 ;
}
return V_4 + V_1 % 8 ;
}
static void F_2 ( struct V_13 * V_14 ,
int V_1 )
{
T_1 V_15 = V_1 < 8 ? V_16 : V_17 ;
int V_18 = F_3 ( V_1 % 8 ) ;
if ( V_14 -> V_19 )
F_4 ( V_14 -> V_20 , V_15 , V_18 , V_18 ) ;
else
F_4 ( V_14 -> V_20 , V_15 , V_18 , 0 ) ;
}
static void F_5 ( struct V_13 * V_14 , int V_1 )
{
int V_4 = F_1 ( V_1 , V_8 ) ;
F_4 ( V_14 -> V_20 , V_4 , V_21 , V_14 -> V_22 ) ;
}
static int F_6 ( struct V_23 * V_24 , unsigned V_1 )
{
struct V_13 * V_14 = F_7 ( V_24 ) ;
int V_4 = F_1 ( V_1 , V_25 ) ;
if ( V_4 < 0 )
return 0 ;
return F_8 ( V_14 -> V_20 , V_4 , V_26 ) ;
}
static int F_9 ( struct V_23 * V_24 , unsigned V_1 ,
int V_27 )
{
struct V_13 * V_14 = F_7 ( V_24 ) ;
int V_4 = F_1 ( V_1 , V_25 ) ;
if ( V_4 < 0 )
return 0 ;
return F_8 ( V_14 -> V_20 , V_4 , V_28 | V_27 ) ;
}
static int F_10 ( struct V_23 * V_24 , unsigned V_1 )
{
struct V_13 * V_14 = F_7 ( V_24 ) ;
unsigned int V_29 ;
int V_30 , V_4 = F_1 ( V_1 , V_8 ) ;
if ( V_4 < 0 )
return 0 ;
V_30 = F_11 ( V_14 -> V_20 , V_4 , & V_29 ) ;
if ( V_30 )
return V_30 ;
return V_29 & 0x1 ;
}
static void F_12 ( struct V_23 * V_24 ,
unsigned V_1 , int V_27 )
{
struct V_13 * V_14 = F_7 ( V_24 ) ;
int V_4 = F_1 ( V_1 , V_25 ) ;
if ( V_4 < 0 )
return;
if ( V_27 )
F_4 ( V_14 -> V_20 , V_4 , 1 , 1 ) ;
else
F_4 ( V_14 -> V_20 , V_4 , 1 , 0 ) ;
}
static int F_13 ( struct V_31 * V_32 , unsigned type )
{
struct V_13 * V_14 =
F_7 ( F_14 ( V_32 ) ) ;
if ( V_32 -> V_33 >= V_5 )
return 0 ;
switch ( type ) {
case V_34 :
V_14 -> V_22 = V_35 ;
break;
case V_36 :
V_14 -> V_22 = V_21 ;
break;
case V_37 :
V_14 -> V_22 = V_38 ;
break;
case V_39 :
V_14 -> V_22 = V_40 ;
break;
default:
return - V_41 ;
}
V_14 -> V_42 |= V_43 ;
return 0 ;
}
static void F_15 ( struct V_31 * V_32 )
{
struct V_13 * V_14 =
F_7 ( F_14 ( V_32 ) ) ;
F_16 ( & V_14 -> V_44 ) ;
}
static void F_17 ( struct V_31 * V_32 )
{
struct V_13 * V_14 =
F_7 ( F_14 ( V_32 ) ) ;
int V_1 = V_32 -> V_33 ;
if ( V_14 -> V_42 & V_43 )
F_5 ( V_14 , V_1 ) ;
if ( V_14 -> V_42 & V_45 )
F_2 ( V_14 , V_1 ) ;
V_14 -> V_42 = 0 ;
F_18 ( & V_14 -> V_44 ) ;
}
static void F_19 ( struct V_31 * V_32 )
{
struct V_13 * V_14 =
F_7 ( F_14 ( V_32 ) ) ;
if ( V_32 -> V_33 < V_5 ) {
V_14 -> V_19 = false ;
V_14 -> V_42 |= V_45 ;
}
}
static void F_20 ( struct V_31 * V_32 )
{
struct V_13 * V_14 =
F_7 ( F_14 ( V_32 ) ) ;
if ( V_32 -> V_33 < V_5 ) {
V_14 -> V_19 = true ;
V_14 -> V_42 |= V_45 ;
}
}
static T_2 F_21 ( int V_46 , void * V_32 )
{
struct V_13 * V_14 = V_32 ;
unsigned int V_47 , V_48 ;
int V_49 ;
int V_1 ;
unsigned int V_50 ;
if ( F_11 ( V_14 -> V_20 , V_51 , & V_47 ) ||
F_11 ( V_14 -> V_20 , V_52 , & V_48 ) )
return V_53 ;
F_8 ( V_14 -> V_20 , V_51 , V_47 ) ;
F_8 ( V_14 -> V_20 , V_52 , V_48 ) ;
V_49 = V_47 | V_48 << 8 ;
for ( V_1 = 0 ; V_1 < V_5 ; V_1 ++ ) {
if ( V_49 & F_3 ( V_1 ) ) {
V_50 = F_22 ( V_14 -> V_24 . V_54 , V_1 ) ;
F_23 ( V_50 ) ;
}
}
return V_55 ;
}
static void F_24 ( struct V_56 * V_57 ,
struct V_23 * V_24 )
{
struct V_13 * V_14 = F_7 ( V_24 ) ;
int V_1 , V_58 ;
unsigned int V_59 , V_60 , V_15 , V_61 , V_46 ;
for ( V_1 = 0 ; V_1 < V_5 ; V_1 ++ ) {
F_11 ( V_14 -> V_20 , F_1 ( V_1 , V_25 ) , & V_59 ) ;
F_11 ( V_14 -> V_20 , F_1 ( V_1 , V_8 ) , & V_60 ) ;
F_11 ( V_14 -> V_20 , V_1 < 8 ? V_16 : V_17 ,
& V_15 ) ;
F_11 ( V_14 -> V_20 , V_1 < 8 ? V_62 : V_63 ,
& V_61 ) ;
F_11 ( V_14 -> V_20 , V_1 < 8 ? V_51 : V_52 ,
& V_46 ) ;
V_58 = V_1 % 8 ;
F_25 ( V_57 , L_1 ,
V_1 , V_59 & V_64 ? L_2 : L_3 ,
V_60 & 0x1 ? L_4 : L_5 ,
V_60 & V_40 ? L_6 : L_7 ,
V_60 & V_38 ? L_8 : L_7 ,
V_59 ,
V_15 & F_3 ( V_58 ) ? L_9 : L_10 ,
V_61 & F_3 ( V_58 ) ? L_11 : L_12 ,
V_46 & F_3 ( V_58 ) ? L_13 : L_14 ) ;
}
}
static int F_26 ( struct V_65 * V_66 )
{
int V_46 = F_27 ( V_66 , 0 ) ;
struct V_13 * V_14 ;
int V_67 ;
struct V_68 * V_69 = V_66 -> V_69 . V_70 ;
struct V_71 * V_72 = F_28 ( V_69 ) ;
if ( V_46 < 0 )
return V_46 ;
V_14 = F_29 ( & V_66 -> V_69 , sizeof( * V_14 ) , V_73 ) ;
if ( ! V_14 )
return - V_74 ;
F_30 ( V_66 , V_14 ) ;
F_31 ( & V_14 -> V_44 ) ;
V_14 -> V_24 . V_75 = V_76 ;
V_14 -> V_24 . V_77 = F_6 ;
V_14 -> V_24 . V_78 = F_9 ;
V_14 -> V_24 . V_79 = F_10 ;
V_14 -> V_24 . V_80 = F_12 ;
V_14 -> V_24 . V_81 = - 1 ;
V_14 -> V_24 . V_82 = V_83 ;
V_14 -> V_24 . V_84 = true ;
V_14 -> V_24 . V_70 = V_69 ;
V_14 -> V_24 . V_85 = F_24 ;
V_14 -> V_20 = V_72 -> V_20 ;
V_67 = F_32 ( & V_66 -> V_69 , & V_14 -> V_24 , V_14 ) ;
if ( V_67 ) {
F_33 ( & V_66 -> V_69 , L_15 , V_67 ) ;
return V_67 ;
}
F_34 ( & V_14 -> V_24 , & V_86 , 0 ,
V_87 , V_34 ) ;
V_67 = F_35 ( V_46 , NULL , F_21 ,
V_88 , V_76 , V_14 ) ;
if ( V_67 ) {
F_33 ( & V_66 -> V_69 , L_16 , V_67 ) ;
return V_67 ;
}
F_36 ( & V_14 -> V_24 , & V_86 , V_46 ) ;
return 0 ;
}
static int F_37 ( struct V_65 * V_66 )
{
struct V_13 * V_14 = F_38 ( V_66 ) ;
int V_46 = F_27 ( V_66 , 0 ) ;
if ( V_46 >= 0 )
F_39 ( V_46 , V_14 ) ;
return 0 ;
}
