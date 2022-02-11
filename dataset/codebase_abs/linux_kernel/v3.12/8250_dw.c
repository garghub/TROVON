static inline int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 && V_6 -> V_9 & V_10 ) {
V_4 |= V_11 ;
V_4 &= ~ V_12 ;
}
return V_4 ;
}
static void F_2 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_13 )
V_6 -> V_14 = V_4 ;
if ( V_3 == V_15 )
V_6 -> V_9 = V_4 ;
F_3 ( V_4 , V_2 -> V_16 + ( V_3 << V_2 -> V_17 ) ) ;
}
static unsigned int F_4 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_5 ( V_2 -> V_16 + ( V_3 << V_2 -> V_17 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
F_2 ( V_2 , V_3 , V_4 ) ;
F_4 ( V_2 , V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_13 )
V_6 -> V_14 = V_4 ;
if ( V_3 == V_15 )
V_6 -> V_9 = V_4 ;
F_8 ( V_4 , V_2 -> V_16 + ( V_3 << V_2 -> V_17 ) ) ;
}
static unsigned int F_9 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = F_10 ( V_2 -> V_16 + ( V_3 << V_2 -> V_17 ) ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_18 = V_2 -> V_19 ( V_2 , V_20 ) ;
if ( F_12 ( V_2 , V_18 ) ) {
return 1 ;
} else if ( ( V_18 & V_21 ) == V_21 ) {
( void ) V_2 -> V_19 ( V_2 , V_6 -> V_22 ) ;
V_2 -> V_23 ( V_2 , V_13 , V_6 -> V_14 ) ;
return 1 ;
}
return 0 ;
}
static void
F_13 ( struct V_1 * V_24 , unsigned int V_25 , unsigned int V_26 )
{
if ( ! V_25 )
F_14 ( V_24 -> V_27 ) ;
F_15 ( V_24 , V_25 , V_26 ) ;
if ( V_25 )
F_16 ( V_24 -> V_27 ) ;
}
static void F_17 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = & V_29 -> V_24 ;
T_1 V_30 = F_10 ( V_2 -> V_16 + V_31 ) ;
if ( ! V_30 )
return;
F_18 ( V_2 -> V_27 , L_1 ,
( V_30 >> 24 ) & 0xff , ( V_30 >> 16 ) & 0xff , ( V_30 >> 8 ) & 0xff ) ;
V_30 = F_10 ( V_2 -> V_16 + V_32 ) ;
if ( ! V_30 )
return;
if ( V_30 & V_33 ) {
V_2 -> type = V_34 ;
V_2 -> V_35 |= V_36 ;
V_2 -> V_37 = F_19 ( V_30 ) ;
V_29 -> V_38 = V_2 -> V_37 ;
V_29 -> V_39 = V_40 ;
}
if ( V_30 & V_41 )
V_29 -> V_39 |= V_42 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_5 * V_43 )
{
struct V_44 * V_45 = V_2 -> V_27 -> V_46 ;
T_1 V_47 ;
bool V_48 = true ;
if ( F_21 ( V_45 , L_2 ) ) {
#ifdef F_22
V_2 -> V_16 += 7 ;
#endif
V_2 -> V_23 = F_6 ;
V_2 -> V_35 = V_49 | V_50 | V_36 ;
V_2 -> type = V_51 ;
V_43 -> V_22 = 0x27 ;
V_48 = false ;
} else if ( ! F_23 ( V_45 , L_3 , & V_47 ) ) {
switch ( V_47 ) {
case 1 :
break;
case 4 :
V_2 -> V_52 = V_53 ;
V_2 -> V_19 = F_9 ;
V_2 -> V_23 = F_7 ;
break;
default:
F_24 ( V_2 -> V_27 , L_4 , V_47 ) ;
return - V_54 ;
}
}
if ( V_48 )
F_17 ( F_25 ( V_2 , struct V_28 , V_24 ) ) ;
if ( ! F_23 ( V_45 , L_5 , & V_47 ) )
V_2 -> V_17 = V_47 ;
if ( V_2 -> V_55 )
return 0 ;
if ( F_23 ( V_45 , L_6 , & V_47 ) ) {
F_24 ( V_2 -> V_27 , L_7 ) ;
return - V_54 ;
}
V_2 -> V_55 = V_47 ;
return 0 ;
}
static int F_26 ( struct V_28 * V_29 )
{
const struct V_56 * V_57 ;
struct V_1 * V_2 = & V_29 -> V_24 ;
F_17 ( V_29 ) ;
V_57 = F_27 ( V_2 -> V_27 -> V_58 -> V_59 , V_2 -> V_27 ) ;
if ( ! V_57 )
return - V_60 ;
V_2 -> V_52 = V_53 ;
V_2 -> V_19 = F_9 ;
V_2 -> V_23 = F_7 ;
V_2 -> V_17 = 2 ;
if ( ! V_2 -> V_55 )
V_2 -> V_55 = ( unsigned int ) V_57 -> V_61 ;
V_29 -> V_62 = F_28 ( V_2 -> V_27 , sizeof( * V_29 -> V_62 ) , V_63 ) ;
if ( ! V_29 -> V_62 )
return - V_64 ;
V_29 -> V_62 -> V_65 . V_66 = V_2 -> V_37 / 4 ;
V_29 -> V_62 -> V_67 . V_68 = V_2 -> V_37 / 4 ;
return 0 ;
}
static inline int F_26 ( struct V_28 * V_29 )
{
return - V_60 ;
}
static int F_29 ( struct V_69 * V_70 )
{
struct V_28 V_71 = {} ;
struct V_72 * V_73 = F_30 ( V_70 , V_74 , 0 ) ;
struct V_72 * V_75 = F_30 ( V_70 , V_76 , 0 ) ;
struct V_5 * V_43 ;
int V_77 ;
if ( ! V_73 || ! V_75 ) {
F_24 ( & V_70 -> V_27 , L_8 ) ;
return - V_54 ;
}
F_31 ( & V_71 . V_24 . V_78 ) ;
V_71 . V_24 . V_79 = V_73 -> V_80 ;
V_71 . V_24 . V_75 = V_75 -> V_80 ;
V_71 . V_24 . V_81 = F_11 ;
V_71 . V_24 . V_82 = F_13 ;
V_71 . V_24 . type = V_83 ;
V_71 . V_24 . V_35 = V_50 | V_84 | V_85 ;
V_71 . V_24 . V_27 = & V_70 -> V_27 ;
V_71 . V_24 . V_16 = F_32 ( & V_70 -> V_27 , V_73 -> V_80 ,
F_33 ( V_73 ) ) ;
if ( ! V_71 . V_24 . V_16 )
return - V_64 ;
V_43 = F_28 ( & V_70 -> V_27 , sizeof( * V_43 ) , V_63 ) ;
if ( ! V_43 )
return - V_64 ;
V_43 -> V_22 = V_86 ;
V_43 -> V_87 = F_34 ( & V_70 -> V_27 , NULL ) ;
if ( ! F_35 ( V_43 -> V_87 ) ) {
F_36 ( V_43 -> V_87 ) ;
V_71 . V_24 . V_55 = F_37 ( V_43 -> V_87 ) ;
}
V_71 . V_24 . V_52 = V_88 ;
V_71 . V_24 . V_19 = F_4 ;
V_71 . V_24 . V_23 = F_2 ;
V_71 . V_24 . V_7 = V_43 ;
if ( V_70 -> V_27 . V_46 ) {
V_77 = F_20 ( & V_71 . V_24 , V_43 ) ;
if ( V_77 )
return V_77 ;
} else if ( F_38 ( & V_70 -> V_27 ) ) {
V_77 = F_26 ( & V_71 ) ;
if ( V_77 )
return V_77 ;
} else {
return - V_60 ;
}
V_43 -> line = F_39 ( & V_71 ) ;
if ( V_43 -> line < 0 )
return V_43 -> line ;
F_40 ( V_70 , V_43 ) ;
F_41 ( & V_70 -> V_27 ) ;
F_42 ( & V_70 -> V_27 ) ;
return 0 ;
}
static int F_43 ( struct V_69 * V_70 )
{
struct V_5 * V_43 = F_44 ( V_70 ) ;
F_14 ( & V_70 -> V_27 ) ;
F_45 ( V_43 -> line ) ;
if ( ! F_35 ( V_43 -> V_87 ) )
F_46 ( V_43 -> V_87 ) ;
F_47 ( & V_70 -> V_27 ) ;
F_48 ( & V_70 -> V_27 ) ;
return 0 ;
}
static int F_49 ( struct V_89 * V_27 )
{
struct V_5 * V_43 = F_50 ( V_27 ) ;
F_51 ( V_43 -> line ) ;
return 0 ;
}
static int F_52 ( struct V_89 * V_27 )
{
struct V_5 * V_43 = F_50 ( V_27 ) ;
F_53 ( V_43 -> line ) ;
return 0 ;
}
static int F_54 ( struct V_89 * V_27 )
{
struct V_5 * V_43 = F_50 ( V_27 ) ;
if ( ! F_35 ( V_43 -> V_87 ) )
F_46 ( V_43 -> V_87 ) ;
return 0 ;
}
static int F_55 ( struct V_89 * V_27 )
{
struct V_5 * V_43 = F_50 ( V_27 ) ;
if ( ! F_35 ( V_43 -> V_87 ) )
F_36 ( V_43 -> V_87 ) ;
return 0 ;
}
