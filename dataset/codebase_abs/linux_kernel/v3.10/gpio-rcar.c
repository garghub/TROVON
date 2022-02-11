static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 ,
int V_6 , bool V_5 )
{
T_1 V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_5 )
V_7 |= F_6 ( V_6 ) ;
else
V_7 &= ~ F_6 ( V_6 ) ;
F_3 ( V_2 , V_3 , V_7 ) ;
}
static void F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
F_3 ( V_2 , V_10 , ~ F_6 ( F_9 ( V_9 ) ) ) ;
}
static void F_10 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
F_3 ( V_2 , V_11 , F_6 ( F_9 ( V_9 ) ) ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned int V_12 ,
bool V_13 ,
bool V_14 )
{
unsigned long V_15 ;
F_12 ( & V_2 -> V_16 , V_15 ) ;
F_5 ( V_2 , V_17 , V_12 , ! V_13 ) ;
F_5 ( V_2 , V_18 , V_12 , ! V_14 ) ;
F_5 ( V_2 , V_19 , V_12 , true ) ;
if ( ! V_14 )
F_3 ( V_2 , V_20 , F_6 ( V_12 ) ) ;
F_13 ( & V_2 -> V_16 , V_15 ) ;
}
static int F_14 ( struct V_8 * V_9 , unsigned int type )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
unsigned int V_12 = F_9 ( V_9 ) ;
F_15 ( & V_2 -> V_21 -> V_22 , L_1 , V_12 , type ) ;
switch ( type & V_23 ) {
case V_24 :
F_11 ( V_2 , V_12 , true , true ) ;
break;
case V_25 :
F_11 ( V_2 , V_12 , false , true ) ;
break;
case V_26 :
F_11 ( V_2 , V_12 , true , false ) ;
break;
case V_27 :
F_11 ( V_2 , V_12 , false , false ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static T_2 F_16 ( int V_29 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
T_1 V_31 ;
unsigned int V_32 , V_33 = 0 ;
while ( ( V_31 = F_1 ( V_2 , V_34 ) ) ) {
V_32 = F_17 ( V_31 ) ;
F_3 ( V_2 , V_20 , F_6 ( V_32 ) ) ;
F_18 ( F_19 ( V_2 -> V_35 , V_32 ) ) ;
V_33 ++ ;
}
return V_33 ? V_36 : V_37 ;
}
static inline struct V_1 * F_20 ( struct V_38 * V_39 )
{
return F_21 ( V_39 , struct V_1 , V_38 ) ;
}
static void F_22 ( struct V_38 * V_39 ,
unsigned int V_40 ,
bool V_41 )
{
struct V_1 * V_2 = F_20 ( V_39 ) ;
unsigned long V_15 ;
F_12 ( & V_2 -> V_16 , V_15 ) ;
F_5 ( V_2 , V_17 , V_40 , false ) ;
F_5 ( V_2 , V_19 , V_40 , false ) ;
F_5 ( V_2 , V_42 , V_40 , V_41 ) ;
F_13 ( & V_2 -> V_16 , V_15 ) ;
}
static int F_23 ( struct V_38 * V_39 , unsigned V_32 )
{
return F_24 ( V_39 -> V_4 + V_32 ) ;
}
static void F_25 ( struct V_38 * V_39 , unsigned V_32 )
{
F_26 ( V_39 -> V_4 + V_32 ) ;
F_22 ( V_39 , V_32 , false ) ;
}
static int F_27 ( struct V_38 * V_39 , unsigned V_32 )
{
F_22 ( V_39 , V_32 , false ) ;
return 0 ;
}
static int F_28 ( struct V_38 * V_39 , unsigned V_32 )
{
return ( int ) ( F_1 ( F_20 ( V_39 ) , V_43 ) & F_6 ( V_32 ) ) ;
}
static void F_29 ( struct V_38 * V_39 , unsigned V_32 , int V_5 )
{
struct V_1 * V_2 = F_20 ( V_39 ) ;
unsigned long V_15 ;
F_12 ( & V_2 -> V_16 , V_15 ) ;
F_5 ( V_2 , V_44 , V_32 , V_5 ) ;
F_13 ( & V_2 -> V_16 , V_15 ) ;
}
static int F_30 ( struct V_38 * V_39 , unsigned V_32 ,
int V_5 )
{
F_29 ( V_39 , V_32 , V_5 ) ;
F_22 ( V_39 , V_32 , true ) ;
return 0 ;
}
static int F_31 ( struct V_38 * V_39 , unsigned V_32 )
{
return F_32 ( F_20 ( V_39 ) -> V_35 , V_32 ) ;
}
static int F_33 ( struct V_35 * V_45 , unsigned int V_46 ,
T_3 V_47 )
{
struct V_1 * V_2 = V_45 -> V_48 ;
F_15 ( & V_2 -> V_21 -> V_22 , L_2 , ( int ) V_47 , V_46 ) ;
F_34 ( V_46 , V_45 -> V_48 ) ;
F_35 ( V_46 , & V_2 -> V_49 , V_50 ) ;
F_36 ( V_46 , V_51 ) ;
return 0 ;
}
static int F_37 ( struct V_52 * V_21 )
{
struct V_53 * V_54 = V_21 -> V_22 . V_55 ;
struct V_1 * V_2 ;
struct V_56 * V_57 , * V_29 ;
struct V_38 * V_38 ;
struct V_49 * V_49 ;
const char * V_58 = F_38 ( & V_21 -> V_22 ) ;
int V_59 ;
V_2 = F_39 ( & V_21 -> V_22 , sizeof( * V_2 ) , V_60 ) ;
if ( ! V_2 ) {
F_40 ( & V_21 -> V_22 , L_3 ) ;
V_59 = - V_61 ;
goto V_62;
}
if ( V_54 )
V_2 -> V_63 = * V_54 ;
V_2 -> V_21 = V_21 ;
F_41 ( V_21 , V_2 ) ;
F_42 ( & V_2 -> V_16 ) ;
V_57 = F_43 ( V_21 , V_64 , 0 ) ;
V_29 = F_43 ( V_21 , V_65 , 0 ) ;
if ( ! V_57 || ! V_29 ) {
F_40 ( & V_21 -> V_22 , L_4 ) ;
V_59 = - V_28 ;
goto V_62;
}
V_2 -> V_4 = F_44 ( & V_21 -> V_22 , V_57 -> V_66 ,
F_45 ( V_57 ) ) ;
if ( ! V_2 -> V_4 ) {
F_40 ( & V_21 -> V_22 , L_5 ) ;
V_59 = - V_67 ;
goto V_62;
}
V_38 = & V_2 -> V_38 ;
V_38 -> V_68 = F_23 ;
V_38 -> free = F_25 ;
V_38 -> V_69 = F_27 ;
V_38 -> V_70 = F_28 ;
V_38 -> V_71 = F_30 ;
V_38 -> V_72 = F_29 ;
V_38 -> V_73 = F_31 ;
V_38 -> V_74 = V_58 ;
V_38 -> V_75 = V_76 ;
V_38 -> V_4 = V_2 -> V_63 . V_77 ;
V_38 -> V_78 = V_2 -> V_63 . V_79 ;
V_49 = & V_2 -> V_49 ;
V_49 -> V_58 = V_58 ;
V_49 -> V_80 = F_7 ;
V_49 -> V_81 = F_10 ;
V_49 -> V_82 = F_10 ;
V_49 -> V_83 = F_7 ;
V_49 -> V_84 = F_14 ;
V_49 -> V_15 = V_85 | V_86 ;
V_2 -> V_35 = F_46 ( V_21 -> V_22 . V_87 ,
V_2 -> V_63 . V_79 ,
V_2 -> V_63 . V_88 ,
& V_89 , V_2 ) ;
if ( ! V_2 -> V_35 ) {
V_59 = - V_67 ;
F_40 ( & V_21 -> V_22 , L_6 ) ;
goto V_90;
}
if ( F_47 ( & V_21 -> V_22 , V_29 -> V_66 ,
F_16 , 0 , V_58 , V_2 ) ) {
F_40 ( & V_21 -> V_22 , L_7 ) ;
V_59 = - V_91 ;
goto V_90;
}
V_59 = F_48 ( V_38 ) ;
if ( V_59 ) {
F_40 ( & V_21 -> V_22 , L_8 ) ;
goto V_90;
}
F_49 ( & V_21 -> V_22 , L_9 , V_2 -> V_63 . V_79 ) ;
if ( V_2 -> V_63 . V_88 ) {
V_59 = F_19 ( V_2 -> V_35 , 0 ) ;
if ( V_2 -> V_63 . V_88 != V_59 )
F_50 ( & V_21 -> V_22 , L_10 ,
V_2 -> V_63 . V_88 , V_59 ) ;
}
V_59 = F_51 ( V_38 , V_2 -> V_63 . V_92 , 0 ,
V_38 -> V_4 , V_38 -> V_78 ) ;
if ( V_59 < 0 )
F_50 ( & V_21 -> V_22 , L_11 ) ;
return 0 ;
V_90:
F_52 ( V_2 -> V_35 ) ;
V_62:
return V_59 ;
}
static int F_53 ( struct V_52 * V_21 )
{
struct V_1 * V_2 = F_54 ( V_21 ) ;
int V_59 ;
V_59 = F_55 ( & V_2 -> V_38 ) ;
if ( V_59 )
return V_59 ;
F_52 ( V_2 -> V_35 ) ;
return 0 ;
}
