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
return F_9 ( V_14 -> V_20 , F_3 ( V_5 , V_23 ) ,
V_24 ) ;
}
static int F_10 ( struct V_2 * V_4 , unsigned V_5 ,
int V_25 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
return F_9 ( V_14 -> V_20 , F_3 ( V_5 , V_23 ) ,
V_26 | V_25 ) ;
}
static int F_11 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
int V_27 ;
unsigned int V_28 ;
V_27 = F_12 ( V_14 -> V_20 , F_3 ( V_5 , V_9 ) , & V_28 ) ;
if ( V_27 )
return V_27 ;
return V_28 & 0x1 ;
}
static void F_13 ( struct V_2 * V_4 ,
unsigned V_5 , int V_25 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
if ( V_25 )
F_6 ( V_14 -> V_20 , F_3 ( V_5 , V_23 ) , 1 , 1 ) ;
else
F_6 ( V_14 -> V_20 , F_3 ( V_5 , V_23 ) , 1 , 0 ) ;
}
static int F_14 ( struct V_29 * V_30 , unsigned type )
{
struct V_1 * V_14 = F_1 ( F_15 ( V_30 ) ) ;
switch ( type ) {
case V_31 :
V_14 -> V_22 = V_32 ;
break;
case V_33 :
V_14 -> V_22 = V_21 ;
break;
case V_34 :
V_14 -> V_22 = V_35 ;
break;
case V_36 :
V_14 -> V_22 = V_37 ;
break;
default:
return - V_38 ;
}
V_14 -> V_39 |= V_40 ;
return 0 ;
}
static void F_16 ( struct V_29 * V_30 )
{
struct V_1 * V_14 = F_1 ( F_15 ( V_30 ) ) ;
F_17 ( & V_14 -> V_41 ) ;
}
static void F_18 ( struct V_29 * V_30 )
{
struct V_1 * V_14 = F_1 ( F_15 ( V_30 ) ) ;
int V_5 = V_30 -> V_42 ;
if ( V_14 -> V_39 & V_40 )
F_7 ( V_14 , V_5 ) ;
if ( V_14 -> V_39 & V_43 )
F_4 ( V_14 , V_5 ) ;
V_14 -> V_39 = 0 ;
F_19 ( & V_14 -> V_41 ) ;
}
static void F_20 ( struct V_29 * V_30 )
{
struct V_1 * V_14 = F_1 ( F_15 ( V_30 ) ) ;
V_14 -> V_19 = false ;
V_14 -> V_39 |= V_43 ;
}
static void F_21 ( struct V_29 * V_30 )
{
struct V_1 * V_14 = F_1 ( F_15 ( V_30 ) ) ;
V_14 -> V_19 = true ;
V_14 -> V_39 |= V_43 ;
}
static T_2 F_22 ( int V_44 , void * V_30 )
{
struct V_1 * V_14 = V_30 ;
unsigned int V_45 , V_46 ;
int V_47 ;
int V_5 ;
unsigned int V_48 ;
if ( F_12 ( V_14 -> V_20 , V_49 , & V_45 ) ||
F_12 ( V_14 -> V_20 , V_50 , & V_46 ) )
return V_51 ;
F_9 ( V_14 -> V_20 , V_49 , V_45 ) ;
F_9 ( V_14 -> V_20 , V_50 , V_46 ) ;
V_47 = V_45 | V_46 << 8 ;
for ( V_5 = 0 ; V_5 < V_14 -> V_4 . V_52 ; V_5 ++ ) {
if ( V_47 & F_5 ( V_5 ) ) {
V_48 = F_23 ( V_14 -> V_4 . V_53 , V_5 ) ;
F_24 ( V_48 ) ;
}
}
return V_54 ;
}
static void F_25 ( struct V_55 * V_56 ,
struct V_2 * V_4 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
int V_5 , V_57 ;
unsigned int V_58 , V_59 , V_15 , V_60 , V_44 ;
for ( V_5 = 0 ; V_5 < V_14 -> V_4 . V_52 ; V_5 ++ ) {
F_12 ( V_14 -> V_20 , F_3 ( V_5 , V_23 ) , & V_58 ) ;
F_12 ( V_14 -> V_20 , F_3 ( V_5 , V_9 ) , & V_59 ) ;
F_12 ( V_14 -> V_20 , V_5 < 8 ? V_16 : V_17 ,
& V_15 ) ;
F_12 ( V_14 -> V_20 , V_5 < 8 ? V_61 : V_62 ,
& V_60 ) ;
F_12 ( V_14 -> V_20 , V_5 < 8 ? V_49 : V_50 ,
& V_44 ) ;
V_57 = V_5 % 8 ;
F_26 ( V_56 , L_1 ,
V_5 , V_58 & V_63 ? L_2 : L_3 ,
V_59 & 0x1 ? L_4 : L_5 ,
V_59 & V_37 ? L_6 : L_7 ,
V_59 & V_35 ? L_8 : L_7 ,
V_58 ,
V_15 & F_5 ( V_57 ) ? L_9 : L_10 ,
V_60 & F_5 ( V_57 ) ? L_11 : L_12 ,
V_44 & F_5 ( V_57 ) ? L_13 : L_14 ) ;
}
}
static int F_27 ( struct V_64 * V_65 )
{
int V_44 = F_28 ( V_65 , 0 ) ;
struct V_1 * V_14 ;
int V_66 ;
struct V_67 * V_68 = V_65 -> V_68 . V_69 ;
struct V_70 * V_71 = F_29 ( V_68 ) ;
if ( V_44 < 0 )
return V_44 ;
V_14 = F_30 ( & V_65 -> V_68 , sizeof( * V_14 ) , V_72 ) ;
if ( ! V_14 )
return - V_73 ;
F_31 ( V_65 , V_14 ) ;
F_32 ( & V_14 -> V_41 ) ;
V_14 -> V_4 . V_74 = V_75 ;
V_14 -> V_4 . V_76 = F_8 ;
V_14 -> V_4 . V_77 = F_10 ;
V_14 -> V_4 . V_78 = F_11 ;
V_14 -> V_4 . V_79 = F_13 ;
V_14 -> V_4 . V_80 = - 1 ;
V_14 -> V_4 . V_52 = V_81 ;
V_14 -> V_4 . V_82 = true ;
V_14 -> V_4 . V_68 = V_68 ;
V_14 -> V_4 . V_83 = F_25 ;
V_14 -> V_20 = V_71 -> V_20 ;
V_66 = F_33 ( & V_14 -> V_4 ) ;
if ( V_66 ) {
F_34 ( & V_65 -> V_68 , L_15 , V_66 ) ;
return V_66 ;
}
F_35 ( & V_14 -> V_4 , & V_84 , 0 ,
V_85 , V_31 ) ;
V_66 = F_36 ( V_44 , NULL , F_22 ,
V_86 , V_75 , V_14 ) ;
if ( V_66 ) {
F_34 ( & V_65 -> V_68 , L_16 , V_66 ) ;
goto V_87;
}
return 0 ;
V_87:
F_37 ( F_38 ( & V_14 -> V_4 ) ) ;
return V_66 ;
}
static int F_39 ( struct V_64 * V_65 )
{
struct V_1 * V_14 = F_40 ( V_65 ) ;
int V_44 = F_28 ( V_65 , 0 ) ;
int V_88 ;
V_88 = F_38 ( & V_14 -> V_4 ) ;
if ( V_44 >= 0 )
F_41 ( V_44 , V_14 ) ;
return V_88 ;
}
