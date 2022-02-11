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
F_1 ( V_2 , V_3 , V_4 ) ;
F_3 ( V_2 , V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 )
V_6 -> V_9 = V_4 ;
V_3 <<= V_2 -> V_10 ;
F_7 ( V_4 , V_2 -> V_11 + V_3 ) ;
}
static unsigned int F_8 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= V_2 -> V_10 ;
return F_9 ( V_2 -> V_11 + V_3 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_12 = V_2 -> V_13 ( V_2 , V_14 ) ;
if ( F_11 ( V_2 , V_12 ) ) {
return 1 ;
} else if ( ( V_12 & V_15 ) == V_15 ) {
( void ) V_2 -> V_13 ( V_2 , V_6 -> V_16 ) ;
V_2 -> V_17 ( V_2 , V_8 , V_6 -> V_9 ) ;
return 1 ;
}
return 0 ;
}
static void
F_12 ( struct V_1 * V_18 , unsigned int V_19 , unsigned int V_20 )
{
if ( ! V_19 )
F_13 ( V_18 -> V_21 ) ;
F_14 ( V_18 , V_19 , V_20 ) ;
if ( V_19 )
F_15 ( V_18 -> V_21 ) ;
}
static void F_16 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = & V_23 -> V_18 ;
T_1 V_24 = F_9 ( V_2 -> V_11 + V_25 ) ;
if ( ! V_24 )
return;
F_17 ( V_2 -> V_21 , L_1 ,
( V_24 >> 24 ) & 0xff , ( V_24 >> 16 ) & 0xff , ( V_24 >> 8 ) & 0xff ) ;
V_24 = F_9 ( V_2 -> V_11 + V_26 ) ;
if ( ! V_24 )
return;
if ( V_24 & V_27 ) {
V_2 -> type = V_28 ;
V_2 -> V_29 |= V_30 ;
V_2 -> V_31 = F_18 ( V_24 ) ;
V_23 -> V_32 = V_2 -> V_31 ;
V_23 -> V_33 = V_34 ;
}
if ( V_24 & V_35 )
V_23 -> V_33 |= V_36 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_5 * V_37 )
{
struct V_38 * V_39 = V_2 -> V_21 -> V_40 ;
T_1 V_41 ;
bool V_42 = true ;
if ( F_20 ( V_39 , L_2 ) ) {
#ifdef F_21
V_2 -> V_11 += 7 ;
#endif
V_2 -> V_17 = F_5 ;
V_2 -> V_29 = V_43 | V_44 | V_30 ;
V_2 -> type = V_45 ;
V_37 -> V_16 = 0x27 ;
V_42 = false ;
} else if ( ! F_22 ( V_39 , L_3 , & V_41 ) ) {
switch ( V_41 ) {
case 1 :
break;
case 4 :
V_2 -> V_46 = V_47 ;
V_2 -> V_13 = F_8 ;
V_2 -> V_17 = F_6 ;
break;
default:
F_23 ( V_2 -> V_21 , L_4 , V_41 ) ;
return - V_48 ;
}
}
if ( V_42 )
F_16 ( F_24 ( V_2 , struct V_22 , V_18 ) ) ;
if ( ! F_22 ( V_39 , L_5 , & V_41 ) )
V_2 -> V_10 = V_41 ;
if ( V_2 -> V_49 )
return 0 ;
if ( F_22 ( V_39 , L_6 , & V_41 ) ) {
F_23 ( V_2 -> V_21 , L_7 ) ;
return - V_48 ;
}
V_2 -> V_49 = V_41 ;
return 0 ;
}
static int F_25 ( struct V_22 * V_23 )
{
const struct V_50 * V_51 ;
struct V_1 * V_2 = & V_23 -> V_18 ;
F_16 ( V_23 ) ;
V_51 = F_26 ( V_2 -> V_21 -> V_52 -> V_53 , V_2 -> V_21 ) ;
if ( ! V_51 )
return - V_54 ;
V_2 -> V_46 = V_47 ;
V_2 -> V_13 = F_8 ;
V_2 -> V_17 = F_6 ;
V_2 -> V_10 = 2 ;
if ( ! V_2 -> V_49 )
V_2 -> V_49 = ( unsigned int ) V_51 -> V_55 ;
V_23 -> V_56 = F_27 ( V_2 -> V_21 , sizeof( * V_23 -> V_56 ) , V_57 ) ;
if ( ! V_23 -> V_56 )
return - V_58 ;
V_23 -> V_56 -> V_59 . V_60 = V_2 -> V_31 / 4 ;
V_23 -> V_56 -> V_61 . V_62 = V_2 -> V_31 / 4 ;
return 0 ;
}
static inline int F_25 ( struct V_22 * V_23 )
{
return - V_54 ;
}
static int F_28 ( struct V_63 * V_64 )
{
struct V_22 V_65 = {} ;
struct V_66 * V_67 = F_29 ( V_64 , V_68 , 0 ) ;
struct V_66 * V_69 = F_29 ( V_64 , V_70 , 0 ) ;
struct V_5 * V_37 ;
int V_71 ;
if ( ! V_67 || ! V_69 ) {
F_23 ( & V_64 -> V_21 , L_8 ) ;
return - V_48 ;
}
F_30 ( & V_65 . V_18 . V_72 ) ;
V_65 . V_18 . V_73 = V_67 -> V_74 ;
V_65 . V_18 . V_69 = V_69 -> V_74 ;
V_65 . V_18 . V_75 = F_10 ;
V_65 . V_18 . V_76 = F_12 ;
V_65 . V_18 . type = V_77 ;
V_65 . V_18 . V_29 = V_44 | V_78 | V_79 ;
V_65 . V_18 . V_21 = & V_64 -> V_21 ;
V_65 . V_18 . V_11 = F_31 ( & V_64 -> V_21 , V_67 -> V_74 ,
F_32 ( V_67 ) ) ;
if ( ! V_65 . V_18 . V_11 )
return - V_58 ;
V_37 = F_27 ( & V_64 -> V_21 , sizeof( * V_37 ) , V_57 ) ;
if ( ! V_37 )
return - V_58 ;
V_37 -> V_16 = V_80 ;
V_37 -> V_81 = F_33 ( & V_64 -> V_21 , NULL ) ;
if ( ! F_34 ( V_37 -> V_81 ) ) {
F_35 ( V_37 -> V_81 ) ;
V_65 . V_18 . V_49 = F_36 ( V_37 -> V_81 ) ;
}
V_65 . V_18 . V_46 = V_82 ;
V_65 . V_18 . V_13 = F_3 ;
V_65 . V_18 . V_17 = F_1 ;
V_65 . V_18 . V_7 = V_37 ;
if ( V_64 -> V_21 . V_40 ) {
V_71 = F_19 ( & V_65 . V_18 , V_37 ) ;
if ( V_71 )
return V_71 ;
} else if ( F_37 ( & V_64 -> V_21 ) ) {
V_71 = F_25 ( & V_65 ) ;
if ( V_71 )
return V_71 ;
} else {
return - V_54 ;
}
V_37 -> line = F_38 ( & V_65 ) ;
if ( V_37 -> line < 0 )
return V_37 -> line ;
F_39 ( V_64 , V_37 ) ;
F_40 ( & V_64 -> V_21 ) ;
F_41 ( & V_64 -> V_21 ) ;
return 0 ;
}
static int F_42 ( struct V_63 * V_64 )
{
struct V_5 * V_37 = F_43 ( V_64 ) ;
F_13 ( & V_64 -> V_21 ) ;
F_44 ( V_37 -> line ) ;
if ( ! F_34 ( V_37 -> V_81 ) )
F_45 ( V_37 -> V_81 ) ;
F_46 ( & V_64 -> V_21 ) ;
F_47 ( & V_64 -> V_21 ) ;
return 0 ;
}
static int F_48 ( struct V_83 * V_21 )
{
struct V_5 * V_37 = F_49 ( V_21 ) ;
F_50 ( V_37 -> line ) ;
return 0 ;
}
static int F_51 ( struct V_83 * V_21 )
{
struct V_5 * V_37 = F_49 ( V_21 ) ;
F_52 ( V_37 -> line ) ;
return 0 ;
}
static int F_53 ( struct V_83 * V_21 )
{
struct V_5 * V_37 = F_49 ( V_21 ) ;
if ( ! F_34 ( V_37 -> V_81 ) )
F_45 ( V_37 -> V_81 ) ;
return 0 ;
}
static int F_54 ( struct V_83 * V_21 )
{
struct V_5 * V_37 = F_49 ( V_21 ) ;
if ( ! F_34 ( V_37 -> V_81 ) )
F_35 ( V_37 -> V_81 ) ;
return 0 ;
}
