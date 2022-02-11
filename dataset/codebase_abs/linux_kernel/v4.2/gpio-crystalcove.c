static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline int F_3 ( int V_5 , enum V_6 V_7 )
{
int V_8 ;
if ( V_5 == 94 )
return V_9 ;
if ( V_7 == V_10 ) {
if ( V_5 < 8 )
V_8 = V_11 ;
else
V_8 = V_12 ;
} else {
if ( V_5 < 8 )
V_8 = V_13 ;
else
V_8 = V_14 ;
}
return V_8 + V_5 % 8 ;
}
static void F_4 ( struct V_1 * V_15 ,
int V_5 )
{
T_1 V_16 = V_5 < 8 ? V_17 : V_18 ;
int V_19 = F_5 ( V_5 % 8 ) ;
if ( V_15 -> V_20 )
F_6 ( V_15 -> V_21 , V_16 , V_19 , V_19 ) ;
else
F_6 ( V_15 -> V_21 , V_16 , V_19 , 0 ) ;
}
static void F_7 ( struct V_1 * V_15 , int V_5 )
{
int V_8 = F_3 ( V_5 , V_10 ) ;
F_6 ( V_15 -> V_21 , V_8 , V_22 , V_15 -> V_23 ) ;
}
static int F_8 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_15 = F_1 ( V_4 ) ;
if ( V_5 > V_24 )
return 0 ;
return F_9 ( V_15 -> V_21 , F_3 ( V_5 , V_25 ) ,
V_26 ) ;
}
static int F_10 ( struct V_2 * V_4 , unsigned V_5 ,
int V_27 )
{
struct V_1 * V_15 = F_1 ( V_4 ) ;
if ( V_5 > V_24 )
return 0 ;
return F_9 ( V_15 -> V_21 , F_3 ( V_5 , V_25 ) ,
V_28 | V_27 ) ;
}
static int F_11 ( struct V_2 * V_4 , unsigned V_5 )
{
struct V_1 * V_15 = F_1 ( V_4 ) ;
int V_29 ;
unsigned int V_30 ;
if ( V_5 > V_24 )
return 0 ;
V_29 = F_12 ( V_15 -> V_21 , F_3 ( V_5 , V_10 ) , & V_30 ) ;
if ( V_29 )
return V_29 ;
return V_30 & 0x1 ;
}
static void F_13 ( struct V_2 * V_4 ,
unsigned V_5 , int V_27 )
{
struct V_1 * V_15 = F_1 ( V_4 ) ;
if ( V_5 > V_24 )
return;
if ( V_27 )
F_6 ( V_15 -> V_21 , F_3 ( V_5 , V_25 ) , 1 , 1 ) ;
else
F_6 ( V_15 -> V_21 , F_3 ( V_5 , V_25 ) , 1 , 0 ) ;
}
static int F_14 ( struct V_31 * V_32 , unsigned type )
{
struct V_1 * V_15 = F_1 ( F_15 ( V_32 ) ) ;
switch ( type ) {
case V_33 :
V_15 -> V_23 = V_34 ;
break;
case V_35 :
V_15 -> V_23 = V_22 ;
break;
case V_36 :
V_15 -> V_23 = V_37 ;
break;
case V_38 :
V_15 -> V_23 = V_39 ;
break;
default:
return - V_40 ;
}
V_15 -> V_41 |= V_42 ;
return 0 ;
}
static void F_16 ( struct V_31 * V_32 )
{
struct V_1 * V_15 = F_1 ( F_15 ( V_32 ) ) ;
F_17 ( & V_15 -> V_43 ) ;
}
static void F_18 ( struct V_31 * V_32 )
{
struct V_1 * V_15 = F_1 ( F_15 ( V_32 ) ) ;
int V_5 = V_32 -> V_44 ;
if ( V_15 -> V_41 & V_42 )
F_7 ( V_15 , V_5 ) ;
if ( V_15 -> V_41 & V_45 )
F_4 ( V_15 , V_5 ) ;
V_15 -> V_41 = 0 ;
F_19 ( & V_15 -> V_43 ) ;
}
static void F_20 ( struct V_31 * V_32 )
{
struct V_1 * V_15 = F_1 ( F_15 ( V_32 ) ) ;
V_15 -> V_20 = false ;
V_15 -> V_41 |= V_45 ;
}
static void F_21 ( struct V_31 * V_32 )
{
struct V_1 * V_15 = F_1 ( F_15 ( V_32 ) ) ;
V_15 -> V_20 = true ;
V_15 -> V_41 |= V_45 ;
}
static T_2 F_22 ( int V_46 , void * V_32 )
{
struct V_1 * V_15 = V_32 ;
unsigned int V_47 , V_48 ;
int V_49 ;
int V_5 ;
unsigned int V_50 ;
if ( F_12 ( V_15 -> V_21 , V_51 , & V_47 ) ||
F_12 ( V_15 -> V_21 , V_52 , & V_48 ) )
return V_53 ;
F_9 ( V_15 -> V_21 , V_51 , V_47 ) ;
F_9 ( V_15 -> V_21 , V_52 , V_48 ) ;
V_49 = V_47 | V_48 << 8 ;
for ( V_5 = 0 ; V_5 < V_54 ; V_5 ++ ) {
if ( V_49 & F_5 ( V_5 ) ) {
V_50 = F_23 ( V_15 -> V_4 . V_55 , V_5 ) ;
F_24 ( V_50 ) ;
}
}
return V_56 ;
}
static void F_25 ( struct V_57 * V_58 ,
struct V_2 * V_4 )
{
struct V_1 * V_15 = F_1 ( V_4 ) ;
int V_5 , V_59 ;
unsigned int V_60 , V_61 , V_16 , V_62 , V_46 ;
for ( V_5 = 0 ; V_5 < V_54 ; V_5 ++ ) {
F_12 ( V_15 -> V_21 , F_3 ( V_5 , V_25 ) , & V_60 ) ;
F_12 ( V_15 -> V_21 , F_3 ( V_5 , V_10 ) , & V_61 ) ;
F_12 ( V_15 -> V_21 , V_5 < 8 ? V_17 : V_18 ,
& V_16 ) ;
F_12 ( V_15 -> V_21 , V_5 < 8 ? V_63 : V_64 ,
& V_62 ) ;
F_12 ( V_15 -> V_21 , V_5 < 8 ? V_51 : V_52 ,
& V_46 ) ;
V_59 = V_5 % 8 ;
F_26 ( V_58 , L_1 ,
V_5 , V_60 & V_65 ? L_2 : L_3 ,
V_61 & 0x1 ? L_4 : L_5 ,
V_61 & V_39 ? L_6 : L_7 ,
V_61 & V_37 ? L_8 : L_7 ,
V_60 ,
V_16 & F_5 ( V_59 ) ? L_9 : L_10 ,
V_62 & F_5 ( V_59 ) ? L_11 : L_12 ,
V_46 & F_5 ( V_59 ) ? L_13 : L_14 ) ;
}
}
static int F_27 ( struct V_66 * V_67 )
{
int V_46 = F_28 ( V_67 , 0 ) ;
struct V_1 * V_15 ;
int V_68 ;
struct V_69 * V_70 = V_67 -> V_70 . V_71 ;
struct V_72 * V_73 = F_29 ( V_70 ) ;
if ( V_46 < 0 )
return V_46 ;
V_15 = F_30 ( & V_67 -> V_70 , sizeof( * V_15 ) , V_74 ) ;
if ( ! V_15 )
return - V_75 ;
F_31 ( V_67 , V_15 ) ;
F_32 ( & V_15 -> V_43 ) ;
V_15 -> V_4 . V_76 = V_77 ;
V_15 -> V_4 . V_78 = F_8 ;
V_15 -> V_4 . V_79 = F_10 ;
V_15 -> V_4 . V_80 = F_11 ;
V_15 -> V_4 . V_81 = F_13 ;
V_15 -> V_4 . V_82 = - 1 ;
V_15 -> V_4 . V_83 = V_24 ;
V_15 -> V_4 . V_84 = true ;
V_15 -> V_4 . V_70 = V_70 ;
V_15 -> V_4 . V_85 = F_25 ;
V_15 -> V_21 = V_73 -> V_21 ;
V_68 = F_33 ( & V_15 -> V_4 ) ;
if ( V_68 ) {
F_34 ( & V_67 -> V_70 , L_15 , V_68 ) ;
return V_68 ;
}
F_35 ( & V_15 -> V_4 , & V_86 , 0 ,
V_87 , V_33 ) ;
V_68 = F_36 ( V_46 , NULL , F_22 ,
V_88 , V_77 , V_15 ) ;
if ( V_68 ) {
F_34 ( & V_67 -> V_70 , L_16 , V_68 ) ;
goto V_89;
}
return 0 ;
V_89:
F_37 ( & V_15 -> V_4 ) ;
return V_68 ;
}
static int F_38 ( struct V_66 * V_67 )
{
struct V_1 * V_15 = F_39 ( V_67 ) ;
int V_46 = F_28 ( V_67 , 0 ) ;
F_37 ( & V_15 -> V_4 ) ;
if ( V_46 >= 0 )
F_40 ( V_46 , V_15 ) ;
return 0 ;
}
