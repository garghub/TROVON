static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 )
V_6 -> V_9 = V_4 ;
V_3 <<= V_2 -> V_10 ;
F_2 ( V_4 , V_2 -> V_11 + V_3 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= V_2 -> V_10 ;
return F_4 ( V_2 -> V_11 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 )
V_6 -> V_9 = V_4 ;
V_3 <<= V_2 -> V_10 ;
F_6 ( V_4 , V_2 -> V_11 + V_3 ) ;
}
static unsigned int F_7 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= V_2 -> V_10 ;
return F_8 ( V_2 -> V_11 + V_3 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_12 = V_2 -> V_13 ( V_2 , V_14 ) ;
if ( F_10 ( V_2 , V_12 ) ) {
return 1 ;
} else if ( ( V_12 & V_15 ) == V_15 ) {
( void ) V_2 -> V_13 ( V_2 , V_16 ) ;
V_2 -> V_17 ( V_2 , V_8 , V_6 -> V_9 ) ;
return 1 ;
}
return 0 ;
}
static void
F_11 ( struct V_1 * V_18 , unsigned int V_19 , unsigned int V_20 )
{
if ( ! V_19 )
F_12 ( V_18 -> V_21 ) ;
F_13 ( V_18 , V_19 , V_20 ) ;
if ( V_19 )
F_14 ( V_18 -> V_21 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_21 -> V_24 ;
T_1 V_25 ;
if ( ! F_16 ( V_23 , L_1 , & V_25 ) ) {
switch ( V_25 ) {
case 1 :
break;
case 4 :
V_2 -> V_26 = V_27 ;
V_2 -> V_13 = F_7 ;
V_2 -> V_17 = F_5 ;
break;
default:
F_17 ( V_2 -> V_21 , L_2 , V_25 ) ;
return - V_28 ;
}
}
if ( ! F_16 ( V_23 , L_3 , & V_25 ) )
V_2 -> V_10 = V_25 ;
if ( V_2 -> V_29 )
return 0 ;
if ( F_16 ( V_23 , L_4 , & V_25 ) ) {
F_17 ( V_2 -> V_21 , L_5 ) ;
return - V_28 ;
}
V_2 -> V_29 = V_25 ;
return 0 ;
}
static int F_18 ( struct V_30 * V_31 )
{
const struct V_32 * V_33 ;
struct V_1 * V_2 = & V_31 -> V_18 ;
V_33 = F_19 ( V_2 -> V_21 -> V_34 -> V_35 , V_2 -> V_21 ) ;
if ( ! V_33 )
return - V_36 ;
V_2 -> V_26 = V_27 ;
V_2 -> V_13 = F_7 ;
V_2 -> V_17 = F_5 ;
V_2 -> V_10 = 2 ;
if ( ! V_2 -> V_29 )
V_2 -> V_29 = ( unsigned int ) V_33 -> V_37 ;
V_31 -> V_38 = F_20 ( V_2 -> V_21 , sizeof( * V_31 -> V_38 ) , V_39 ) ;
if ( ! V_31 -> V_38 )
return - V_40 ;
V_31 -> V_38 -> V_41 . V_42 = V_2 -> V_43 / 4 ;
V_31 -> V_38 -> V_44 . V_45 = V_2 -> V_43 / 4 ;
return 0 ;
}
static inline int F_18 ( struct V_30 * V_31 )
{
return - V_36 ;
}
static void F_21 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = & V_31 -> V_18 ;
T_1 V_46 = F_8 ( V_2 -> V_11 + V_47 ) ;
if ( ! V_46 )
return;
F_22 ( V_2 -> V_21 , L_6 ,
( V_46 >> 24 ) & 0xff , ( V_46 >> 16 ) & 0xff , ( V_46 >> 8 ) & 0xff ) ;
V_46 = F_8 ( V_2 -> V_11 + V_48 ) ;
if ( ! V_46 )
return;
if ( V_46 & V_49 ) {
V_2 -> type = V_50 ;
V_2 -> V_51 |= V_52 ;
V_2 -> V_43 = F_23 ( V_46 ) ;
V_31 -> V_53 = V_2 -> V_43 ;
V_31 -> V_54 = V_55 ;
}
if ( V_46 & V_56 )
V_31 -> V_54 |= V_57 ;
}
static int F_24 ( struct V_58 * V_59 )
{
struct V_30 V_60 = {} ;
struct V_61 * V_62 = F_25 ( V_59 , V_63 , 0 ) ;
struct V_61 * V_64 = F_25 ( V_59 , V_65 , 0 ) ;
struct V_5 * V_66 ;
int V_67 ;
if ( ! V_62 || ! V_64 ) {
F_17 ( & V_59 -> V_21 , L_7 ) ;
return - V_28 ;
}
F_26 ( & V_60 . V_18 . V_68 ) ;
V_60 . V_18 . V_69 = V_62 -> V_70 ;
V_60 . V_18 . V_64 = V_64 -> V_70 ;
V_60 . V_18 . V_71 = F_9 ;
V_60 . V_18 . V_72 = F_11 ;
V_60 . V_18 . type = V_73 ;
V_60 . V_18 . V_51 = V_74 | V_75 | V_76 ;
V_60 . V_18 . V_21 = & V_59 -> V_21 ;
V_60 . V_18 . V_11 = F_27 ( & V_59 -> V_21 , V_62 -> V_70 ,
F_28 ( V_62 ) ) ;
if ( ! V_60 . V_18 . V_11 )
return - V_40 ;
V_66 = F_20 ( & V_59 -> V_21 , sizeof( * V_66 ) , V_39 ) ;
if ( ! V_66 )
return - V_40 ;
V_66 -> V_77 = F_29 ( & V_59 -> V_21 , NULL ) ;
if ( ! F_30 ( V_66 -> V_77 ) ) {
F_31 ( V_66 -> V_77 ) ;
V_60 . V_18 . V_29 = F_32 ( V_66 -> V_77 ) ;
}
V_60 . V_18 . V_26 = V_78 ;
V_60 . V_18 . V_13 = F_3 ;
V_60 . V_18 . V_17 = F_1 ;
V_60 . V_18 . V_7 = V_66 ;
F_21 ( & V_60 ) ;
if ( V_59 -> V_21 . V_24 ) {
V_67 = F_15 ( & V_60 . V_18 ) ;
if ( V_67 )
return V_67 ;
} else if ( F_33 ( & V_59 -> V_21 ) ) {
V_67 = F_18 ( & V_60 ) ;
if ( V_67 )
return V_67 ;
} else {
return - V_36 ;
}
V_66 -> line = F_34 ( & V_60 ) ;
if ( V_66 -> line < 0 )
return V_66 -> line ;
F_35 ( V_59 , V_66 ) ;
F_36 ( & V_59 -> V_21 ) ;
F_37 ( & V_59 -> V_21 ) ;
return 0 ;
}
static int F_38 ( struct V_58 * V_59 )
{
struct V_5 * V_66 = F_39 ( V_59 ) ;
F_12 ( & V_59 -> V_21 ) ;
F_40 ( V_66 -> line ) ;
if ( ! F_30 ( V_66 -> V_77 ) )
F_41 ( V_66 -> V_77 ) ;
F_42 ( & V_59 -> V_21 ) ;
F_43 ( & V_59 -> V_21 ) ;
return 0 ;
}
static int F_44 ( struct V_79 * V_21 )
{
struct V_5 * V_66 = F_45 ( V_21 ) ;
F_46 ( V_66 -> line ) ;
return 0 ;
}
static int F_47 ( struct V_79 * V_21 )
{
struct V_5 * V_66 = F_45 ( V_21 ) ;
F_48 ( V_66 -> line ) ;
return 0 ;
}
static int F_49 ( struct V_79 * V_21 )
{
struct V_5 * V_66 = F_45 ( V_21 ) ;
if ( ! F_30 ( V_66 -> V_77 ) )
F_41 ( V_66 -> V_77 ) ;
return 0 ;
}
static int F_50 ( struct V_79 * V_21 )
{
struct V_5 * V_66 = F_45 ( V_21 ) ;
if ( ! F_30 ( V_66 -> V_77 ) )
F_31 ( V_66 -> V_77 ) ;
return 0 ;
}
