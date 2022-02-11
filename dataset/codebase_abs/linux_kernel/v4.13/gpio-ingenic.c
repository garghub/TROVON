static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
unsigned int V_4 ;
F_2 ( V_2 -> V_5 , V_2 -> V_6 + V_3 , & V_4 ) ;
return ( T_1 ) V_4 ;
}
static void F_3 ( struct V_1 * V_2 ,
T_2 V_3 , T_2 V_7 , bool V_8 )
{
if ( V_8 )
V_3 = F_4 ( V_3 ) ;
else
V_3 = F_5 ( V_3 ) ;
F_6 ( V_2 -> V_5 , V_2 -> V_6 + V_3 , F_7 ( V_7 ) ) ;
}
static inline bool F_8 ( struct V_1 * V_2 , T_2 V_7 )
{
unsigned int V_4 = F_1 ( V_2 , V_9 ) ;
return ! ! ( V_4 & F_7 ( V_7 ) ) ;
}
static void F_9 ( struct V_1 * V_2 , T_2 V_7 , int V_10 )
{
if ( V_2 -> V_11 >= V_12 )
F_3 ( V_2 , V_13 , V_7 , ! ! V_10 ) ;
else
F_3 ( V_2 , V_14 , V_7 , ! ! V_10 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_2 V_7 , unsigned int type )
{
T_2 V_15 , V_16 ;
if ( V_2 -> V_11 >= V_12 ) {
V_15 = V_17 ;
V_16 = V_13 ;
} else {
V_15 = V_18 ;
V_16 = V_19 ;
}
switch ( type ) {
case V_20 :
F_3 ( V_2 , V_16 , V_7 , true ) ;
F_3 ( V_2 , V_15 , V_7 , true ) ;
break;
case V_21 :
F_3 ( V_2 , V_16 , V_7 , false ) ;
F_3 ( V_2 , V_15 , V_7 , true ) ;
break;
case V_22 :
F_3 ( V_2 , V_16 , V_7 , true ) ;
F_3 ( V_2 , V_15 , V_7 , false ) ;
break;
case V_23 :
default:
F_3 ( V_2 , V_16 , V_7 , false ) ;
F_3 ( V_2 , V_15 , V_7 , false ) ;
break;
}
}
static void F_11 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_12 ( V_25 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
F_3 ( V_2 , V_28 , V_25 -> V_29 , true ) ;
}
static void F_14 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_12 ( V_25 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
F_3 ( V_2 , V_28 , V_25 -> V_29 , false ) ;
}
static void F_15 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_12 ( V_25 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
int V_30 = V_25 -> V_29 ;
if ( V_2 -> V_11 >= V_12 )
F_3 ( V_2 , V_31 , V_30 , true ) ;
else
F_3 ( V_2 , V_32 , V_30 , true ) ;
F_14 ( V_25 ) ;
}
static void F_16 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_12 ( V_25 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
int V_30 = V_25 -> V_29 ;
F_11 ( V_25 ) ;
if ( V_2 -> V_11 >= V_12 )
F_3 ( V_2 , V_31 , V_30 , false ) ;
else
F_3 ( V_2 , V_32 , V_30 , false ) ;
}
static void F_17 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_12 ( V_25 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
int V_30 = V_25 -> V_29 ;
bool V_33 ;
if ( F_18 ( V_25 ) == V_34 ) {
V_33 = F_8 ( V_2 , V_30 ) ;
if ( V_33 )
F_10 ( V_2 , V_30 , V_21 ) ;
else
F_10 ( V_2 , V_30 , V_20 ) ;
}
if ( V_2 -> V_11 >= V_12 )
F_3 ( V_2 , V_35 , V_30 , false ) ;
else
F_3 ( V_2 , V_14 , V_30 , true ) ;
}
static int F_19 ( struct V_24 * V_25 , unsigned int type )
{
struct V_26 * V_27 = F_12 ( V_25 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
switch ( type ) {
case V_34 :
case V_20 :
case V_21 :
F_20 ( V_25 , V_36 ) ;
break;
case V_22 :
case V_23 :
F_20 ( V_25 , V_37 ) ;
break;
default:
F_20 ( V_25 , V_38 ) ;
}
if ( type == V_34 ) {
bool V_33 = F_8 ( V_2 , V_25 -> V_29 ) ;
type = V_33 ? V_21 : V_20 ;
}
F_10 ( V_2 , V_25 -> V_29 , type ) ;
return 0 ;
}
static int F_21 ( struct V_24 * V_25 , unsigned int V_39 )
{
struct V_26 * V_27 = F_12 ( V_25 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
return F_22 ( V_2 -> V_30 , V_39 ) ;
}
static void F_23 ( struct V_40 * V_41 )
{
struct V_26 * V_27 = F_24 ( V_41 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
struct V_42 * V_42 = F_25 ( & V_41 -> V_24 ) ;
unsigned long V_43 , V_44 ;
F_26 ( V_42 , V_41 ) ;
if ( V_2 -> V_11 >= V_12 )
V_43 = F_1 ( V_2 , V_35 ) ;
else
V_43 = F_1 ( V_2 , V_45 ) ;
F_27 (i, &flag, 32 )
F_28 ( F_29 ( V_27 -> V_46 , V_44 ) ) ;
F_30 ( V_42 , V_41 ) ;
}
static void F_31 ( struct V_26 * V_27 ,
unsigned int V_7 , int V_10 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
F_9 ( V_2 , V_7 , V_10 ) ;
}
static int F_32 ( struct V_26 * V_27 , unsigned int V_7 )
{
struct V_1 * V_2 = F_13 ( V_27 ) ;
return ( int ) F_8 ( V_2 , V_7 ) ;
}
static int F_33 ( struct V_26 * V_27 ,
unsigned int V_7 )
{
return F_34 ( V_27 -> V_47 + V_7 ) ;
}
static int F_35 ( struct V_26 * V_27 ,
unsigned int V_7 , int V_10 )
{
F_31 ( V_27 , V_7 , V_10 ) ;
return F_36 ( V_27 -> V_47 + V_7 ) ;
}
static int F_37 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = & V_49 -> V_51 ;
const struct V_52 * V_53 = F_38 (
V_54 , V_51 ) ;
struct V_1 * V_2 ;
T_1 V_55 ;
int V_56 ;
V_2 = F_39 ( V_51 , sizeof( * V_2 ) , V_57 ) ;
if ( ! V_2 )
return - V_58 ;
V_2 -> V_5 = F_40 ( V_51 -> V_59 ) ;
if ( ! V_2 -> V_5 ) {
F_41 ( V_51 , L_1 ) ;
return - V_60 ;
}
V_56 = F_42 ( V_51 -> V_61 , L_2 , & V_55 ) ;
if ( V_56 ) {
F_41 ( V_51 , L_3 , V_56 ) ;
return V_56 ;
}
V_2 -> V_6 = V_55 * 0x100 ;
V_2 -> V_27 . V_62 = F_43 ( V_51 , V_57 , L_4 , 'A' + V_55 ) ;
if ( ! V_2 -> V_27 . V_62 )
return - V_58 ;
V_2 -> V_27 . V_47 = V_55 * 32 ;
V_2 -> V_27 . V_63 = 32 ;
V_2 -> V_27 . V_59 = V_51 ;
V_2 -> V_27 . V_61 = V_51 -> V_61 ;
V_2 -> V_27 . V_64 = V_65 ;
V_2 -> V_11 = (enum V_66 ) V_53 -> V_67 ;
V_2 -> V_27 . V_8 = F_31 ;
V_2 -> V_27 . V_68 = F_32 ;
V_2 -> V_27 . V_69 = F_33 ;
V_2 -> V_27 . V_70 = F_35 ;
if ( F_44 ( V_51 -> V_61 , L_5 ) ) {
V_2 -> V_27 . V_71 = V_72 ;
V_2 -> V_27 . free = V_73 ;
}
V_56 = F_45 ( V_51 , & V_2 -> V_27 , V_2 ) ;
if ( V_56 )
return V_56 ;
V_2 -> V_30 = F_46 ( V_51 -> V_61 , 0 ) ;
if ( ! V_2 -> V_30 )
return - V_74 ;
V_2 -> V_42 . V_75 = V_2 -> V_27 . V_62 ;
V_2 -> V_42 . V_76 = F_15 ;
V_2 -> V_42 . V_77 = F_16 ;
V_2 -> V_42 . V_78 = F_14 ;
V_2 -> V_42 . V_79 = F_11 ;
V_2 -> V_42 . V_80 = F_17 ;
V_2 -> V_42 . F_10 = F_19 ;
V_2 -> V_42 . V_81 = F_21 ;
V_2 -> V_42 . V_82 = V_83 ;
V_56 = F_47 ( & V_2 -> V_27 , & V_2 -> V_42 , 0 ,
V_37 , V_84 ) ;
if ( V_56 )
return V_56 ;
F_48 ( & V_2 -> V_27 , & V_2 -> V_42 ,
V_2 -> V_30 , F_23 ) ;
return 0 ;
}
static int F_49 ( struct V_48 * V_49 )
{
return 0 ;
}
static int T_3 F_50 ( void )
{
return F_51 ( & V_85 ) ;
}
static void T_4 F_52 ( void )
{
F_53 ( & V_85 ) ;
}
