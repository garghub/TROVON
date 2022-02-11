static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static T_1 F_3 ( int V_5 , void * V_6 )
{
struct V_1 * V_4 = V_6 ;
F_4 ( & V_4 -> V_7 ) ;
return V_8 ;
}
static long F_5 ( struct V_1 * V_4 )
{
long V_9 ;
unsigned long V_10 ;
long V_11 ;
F_6 ( & V_4 -> V_12 ) ;
F_7 ( V_4 -> V_7 ) ;
F_8 ( V_4 -> V_5 ) ;
V_4 -> V_13 -> V_14 ( V_4 -> V_15 ) ;
V_9 = F_9 ( & V_4 -> V_7 ,
V_16 ) ;
if ( V_9 > 0 ) {
V_10 = F_10 ( V_4 -> V_17 ) & 0xfff ;
if ( V_4 -> V_18 -> V_19 . V_20 <= 2500000 )
V_10 = ( V_10 * 78125UL ) >> 7UL ;
else
V_10 = ( ( V_10 * 924375UL ) >> 9UL ) + 33000 ;
V_11 = ( long ) V_10 ;
} else {
V_11 = V_9 ? V_9 : - V_21 ;
}
V_4 -> V_13 -> V_22 ( V_4 -> V_15 ) ;
F_11 ( V_4 -> V_5 ) ;
F_12 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_23 * V_19 = & V_1 -> V_18 -> V_19 ;
long V_11 ;
int V_24 ;
int V_25 ;
V_11 = F_5 ( V_1 ) ;
if ( V_11 < 0 )
return V_11 ;
V_25 = V_19 -> V_20 - V_19 -> V_26 ;
V_24 = ( ( V_11 - V_19 -> V_26 ) * 100 ) / V_25 ;
if ( V_24 > 100 )
V_24 = 100 ;
else if ( V_24 < 0 )
V_24 = 0 ;
return V_24 ;
}
static int F_14 ( struct V_2 * V_3 ,
enum V_27 V_28 , union V_29 * V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_23 * V_19 = & V_1 -> V_18 -> V_19 ;
long V_11 ;
switch ( V_28 ) {
case V_30 :
V_10 -> V_31 = V_1 -> V_32 ;
break;
case V_33 :
V_10 -> V_31 = V_1 -> V_18 -> V_19 . V_34 ;
break;
case V_35 :
V_11 = F_5 ( V_1 ) ;
if ( V_11 < V_19 -> V_26 )
V_10 -> V_31 = V_36 ;
else
V_10 -> V_31 = V_37 ;
break;
case V_38 :
V_10 -> V_31 = F_13 ( V_3 ) ;
break;
case V_39 :
V_10 -> V_31 = F_5 ( V_1 ) ;
if ( V_10 -> V_31 < 0 )
return V_10 -> V_31 ;
break;
case V_40 :
V_10 -> V_31 = V_19 -> V_20 ;
break;
case V_41 :
V_10 -> V_31 = V_19 -> V_26 ;
break;
case V_42 :
V_10 -> V_31 = 1 ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_16 ( V_44 , & V_1 -> V_45 , 0 ) ;
}
static T_1 F_17 ( int V_5 , void * V_46 )
{
struct V_1 * V_1 = V_46 ;
F_16 ( V_44 , & V_1 -> V_45 , 0 ) ;
return V_8 ;
}
static void F_18 ( struct V_1 * V_1 )
{
int V_32 ;
long V_11 ;
bool V_47 = false ;
int V_48 ;
if ( F_19 ( V_1 -> V_18 -> V_49 ) ) {
V_48 = F_20 ( V_1 -> V_18 -> V_49 ) ;
V_48 ^= V_1 -> V_18 -> V_50 ;
if ( V_48 )
V_32 = V_51 ;
else
V_32 = V_52 ;
if ( V_32 != V_1 -> V_32 ) {
V_1 -> V_32 = V_32 ;
V_47 = true ;
}
}
V_11 = F_5 ( V_1 ) ;
if ( abs ( V_11 - V_1 -> V_11 ) < 50000 ) {
V_1 -> V_11 = V_11 ;
V_47 = true ;
}
if ( V_47 )
F_21 ( & V_1 -> V_4 ) ;
}
static void F_22 ( struct V_53 * V_45 )
{
const int V_54 = V_16 * 30 ;
struct V_1 * V_1 = F_2 ( V_45 , struct V_1 ,
V_45 . V_45 ) ;
F_18 ( V_1 ) ;
F_23 ( & V_1 -> V_45 , V_54 ) ;
}
static int F_24 ( struct V_55 * V_15 )
{
int V_24 = 0 ;
struct V_56 * V_18 = V_15 -> V_57 . V_58 -> V_59 ;
struct V_1 * V_1 ;
struct V_2 * V_4 ;
struct V_60 * V_61 ;
if ( ! V_18 ) {
F_25 ( & V_15 -> V_57 , L_1 ) ;
return - V_62 ;
}
V_1 = F_26 ( & V_15 -> V_57 , sizeof( * V_1 ) , V_63 ) ;
if ( ! V_1 ) {
F_25 ( & V_15 -> V_57 , L_2 ) ;
return - V_64 ;
}
V_1 -> V_13 = F_27 ( V_15 ) ;
V_1 -> V_5 = F_28 ( V_15 , 0 ) ;
if ( V_1 -> V_5 < 0 ) {
F_25 ( & V_15 -> V_57 , L_3 , V_24 ) ;
return V_1 -> V_5 ;
}
V_61 = F_29 ( V_15 , V_65 , 0 ) ;
V_1 -> V_17 = F_30 ( & V_15 -> V_57 , V_61 ) ;
if ( F_31 ( V_1 -> V_17 ) )
return F_32 ( V_1 -> V_17 ) ;
V_4 = & V_1 -> V_4 ;
V_4 -> V_66 = V_18 -> V_19 . V_66 ;
V_4 -> type = V_67 ;
V_4 -> V_68 = V_69 ;
V_4 -> V_70 = F_33 ( V_69 ) ;
V_4 -> V_71 = F_14 ;
V_4 -> V_72 = F_15 ;
V_4 -> V_73 = 1 ;
V_1 -> V_18 = V_18 ;
V_1 -> V_15 = V_15 ;
F_34 ( & V_1 -> V_7 ) ;
F_35 ( & V_1 -> V_12 ) ;
F_36 ( & V_1 -> V_45 , F_22 ) ;
V_24 = F_37 ( V_1 -> V_5 , F_3 , 0 , V_15 -> V_66 ,
V_1 ) ;
if ( V_24 ) {
F_25 ( & V_15 -> V_57 , L_4 , V_24 ) ;
goto V_74;
}
F_11 ( V_1 -> V_5 ) ;
if ( F_19 ( V_18 -> V_49 ) ) {
V_24 = F_38 ( V_18 -> V_49 , F_39 ( & V_15 -> V_57 ) ) ;
if ( V_24 ) {
F_25 ( & V_15 -> V_57 , L_5 ) ;
goto V_75;
}
V_24 = F_40 ( V_18 -> V_49 ) ;
if ( V_24 ) {
F_25 ( & V_15 -> V_57 , L_6 ) ;
goto V_76;
}
V_1 -> V_77 = F_41 ( V_18 -> V_49 ) ;
if ( V_1 -> V_77 >= 0 ) {
V_24 = F_37 ( V_1 -> V_77 ,
F_17 ,
V_78 | V_79 ,
F_39 ( & V_15 -> V_57 ) , V_1 ) ;
if ( V_24 ) {
F_25 ( & V_15 -> V_57 , L_7 , V_24 ) ;
goto V_76;
}
}
} else {
V_1 -> V_77 = - 1 ;
}
if ( V_1 -> V_18 -> V_19 . V_20 <= 2500000 )
F_42 ( V_15 -> V_57 . V_58 , V_80 ,
V_80 ) ;
else
F_42 ( V_15 -> V_57 . V_58 , V_80 , 0 ) ;
V_24 = F_43 ( & V_15 -> V_57 , & V_1 -> V_4 ) ;
if ( V_24 ) {
F_25 ( & V_15 -> V_57 , L_8 ) ;
goto V_81;
}
F_44 ( V_15 , V_1 ) ;
F_23 ( & V_1 -> V_45 , 0 ) ;
return 0 ;
V_81:
if ( V_1 -> V_77 >= 0 )
F_45 ( V_1 -> V_77 , V_1 ) ;
V_76:
if ( F_19 ( V_18 -> V_49 ) )
F_46 ( V_1 -> V_18 -> V_49 ) ;
V_75:
F_45 ( V_1 -> V_5 , V_1 ) ;
V_74:
F_44 ( V_15 , NULL ) ;
return V_24 ;
}
static int F_47 ( struct V_55 * V_15 )
{
struct V_1 * V_1 = F_48 ( V_15 ) ;
F_49 ( & V_1 -> V_45 ) ;
if ( F_19 ( V_1 -> V_18 -> V_49 ) ) {
if ( V_1 -> V_77 >= 0 )
F_45 ( V_1 -> V_77 , V_1 ) ;
F_46 ( V_1 -> V_18 -> V_49 ) ;
}
F_50 ( & V_1 -> V_4 ) ;
F_45 ( V_1 -> V_5 , V_1 ) ;
return 0 ;
}
static int F_51 ( struct V_82 * V_57 )
{
struct V_1 * V_1 = F_52 ( V_57 ) ;
F_49 ( & V_1 -> V_45 ) ;
V_1 -> V_32 = V_83 ;
return 0 ;
}
static int F_53 ( struct V_82 * V_57 )
{
struct V_1 * V_1 = F_52 ( V_57 ) ;
F_23 ( & V_1 -> V_45 , 0 ) ;
return 0 ;
}
