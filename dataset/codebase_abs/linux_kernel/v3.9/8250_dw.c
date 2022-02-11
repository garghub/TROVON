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
static int F_11 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_20 -> V_21 ;
T_1 V_22 ;
if ( ! F_12 ( V_19 , L_1 , & V_22 ) ) {
switch ( V_22 ) {
case 1 :
break;
case 4 :
V_2 -> V_23 = V_24 ;
V_2 -> V_13 = F_7 ;
V_2 -> V_17 = F_5 ;
break;
default:
F_13 ( V_2 -> V_20 , L_2 , V_22 ) ;
return - V_25 ;
}
}
if ( ! F_12 ( V_19 , L_3 , & V_22 ) )
V_2 -> V_10 = V_22 ;
if ( F_12 ( V_19 , L_4 , & V_22 ) ) {
F_13 ( V_2 -> V_20 , L_5 ) ;
return - V_25 ;
}
V_2 -> V_26 = V_22 ;
return 0 ;
}
static bool F_14 ( struct V_27 * V_28 , void * V_29 )
{
return V_28 -> V_30 == * ( int * ) V_29 ;
}
static T_2
F_15 ( struct V_31 * V_32 , void * V_33 )
{
struct V_1 * V_2 = V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
V_35 = F_16 ( V_2 , struct V_34 , V_35 ) ;
switch ( V_32 -> type ) {
case V_42 :
V_39 = & V_32 -> V_33 . V_39 ;
if ( ! V_35 -> V_37 ) {
V_37 = F_17 ( V_2 -> V_20 , sizeof( * V_37 ) , V_43 ) ;
if ( ! V_37 )
return V_44 ;
V_35 -> V_37 = V_37 ;
V_41 = & V_37 -> V_45 ;
V_41 -> V_46 = V_47 ;
V_41 -> V_48 = V_49 ;
V_41 -> V_50 = V_39 -> V_51 ;
V_41 -> V_52 = V_35 -> V_53 / 4 ;
V_37 -> V_54 = V_39 -> V_55 ;
V_37 -> V_56 = & V_37 -> V_54 ;
V_37 -> V_57 = F_14 ;
} else {
V_37 = V_35 -> V_37 ;
V_41 = & V_37 -> V_58 ;
V_41 -> V_46 = V_59 ;
V_41 -> V_60 = V_49 ;
V_41 -> V_50 = V_39 -> V_51 ;
V_41 -> V_61 = V_2 -> V_62 / 4 ;
V_37 -> V_63 = V_39 -> V_55 ;
V_37 -> V_64 = & V_37 -> V_63 ;
}
break;
}
return V_65 ;
}
static int F_18 ( struct V_1 * V_2 )
{
const struct V_66 * V_67 ;
T_2 V_68 ;
T_1 V_69 ;
V_67 = F_19 ( V_2 -> V_20 -> V_70 -> V_71 , V_2 -> V_20 ) ;
if ( ! V_67 )
return - V_72 ;
V_2 -> V_23 = V_24 ;
V_2 -> V_13 = F_7 ;
V_2 -> V_17 = F_5 ;
V_2 -> V_10 = 2 ;
V_2 -> V_26 = ( unsigned int ) V_67 -> V_73 ;
V_68 = F_20 ( F_21 ( V_2 -> V_20 ) , V_74 ,
F_15 , V_2 ) ;
if ( F_22 ( V_68 ) ) {
F_23 ( V_2 -> V_20 , L_6 , V_75 ,
F_24 ( V_68 ) ) ;
return - V_72 ;
}
if ( ! strcmp ( V_67 -> V_67 , L_7 ) || ! strcmp ( V_67 -> V_67 , L_8 ) ) {
V_69 = F_8 ( V_2 -> V_11 + V_76 ) ;
F_6 ( V_69 | 1 , V_2 -> V_11 + V_76 ) ;
}
return 0 ;
}
static inline int F_18 ( struct V_1 * V_2 )
{
return - V_72 ;
}
static void F_25 ( struct V_34 * V_77 )
{
struct V_1 * V_2 = & V_77 -> V_35 ;
T_1 V_69 = F_8 ( V_2 -> V_11 + V_78 ) ;
if ( ! V_69 )
return;
F_26 ( V_2 -> V_20 , L_9 ,
( V_69 >> 24 ) & 0xff , ( V_69 >> 16 ) & 0xff , ( V_69 >> 8 ) & 0xff ) ;
V_69 = F_8 ( V_2 -> V_11 + V_79 ) ;
if ( ! V_69 )
return;
if ( V_69 & V_80 ) {
V_2 -> type = V_81 ;
V_2 -> V_82 |= V_83 ;
V_2 -> V_62 = F_27 ( V_69 ) ;
V_77 -> V_53 = V_2 -> V_62 ;
}
}
static int F_28 ( struct V_84 * V_85 )
{
struct V_34 V_86 = {} ;
struct V_87 * V_88 = F_29 ( V_85 , V_89 , 0 ) ;
struct V_87 * V_90 = F_29 ( V_85 , V_91 , 0 ) ;
struct V_5 * V_33 ;
int V_92 ;
if ( ! V_88 || ! V_90 ) {
F_13 ( & V_85 -> V_20 , L_10 ) ;
return - V_25 ;
}
F_30 ( & V_86 . V_35 . V_93 ) ;
V_86 . V_35 . V_94 = V_88 -> V_95 ;
V_86 . V_35 . V_90 = V_90 -> V_95 ;
V_86 . V_35 . V_96 = F_9 ;
V_86 . V_35 . type = V_97 ;
V_86 . V_35 . V_82 = V_98 | V_99 | V_100 ;
V_86 . V_35 . V_20 = & V_85 -> V_20 ;
V_86 . V_35 . V_11 = F_31 ( V_88 -> V_95 , F_32 ( V_88 ) ) ;
if ( ! V_86 . V_35 . V_11 )
return - V_101 ;
V_86 . V_35 . V_23 = V_102 ;
V_86 . V_35 . V_13 = F_3 ;
V_86 . V_35 . V_17 = F_1 ;
F_25 ( & V_86 ) ;
if ( V_85 -> V_20 . V_21 ) {
V_92 = F_11 ( & V_86 . V_35 ) ;
if ( V_92 )
return V_92 ;
} else if ( F_21 ( & V_85 -> V_20 ) ) {
V_92 = F_18 ( & V_86 . V_35 ) ;
if ( V_92 )
return V_92 ;
} else {
return - V_72 ;
}
V_33 = F_17 ( & V_85 -> V_20 , sizeof( * V_33 ) , V_43 ) ;
if ( ! V_33 )
return - V_101 ;
V_86 . V_35 . V_7 = V_33 ;
V_33 -> line = F_33 ( & V_86 ) ;
if ( V_33 -> line < 0 )
return V_33 -> line ;
F_34 ( V_85 , V_33 ) ;
return 0 ;
}
static int F_35 ( struct V_84 * V_85 )
{
struct V_5 * V_33 = F_36 ( V_85 ) ;
F_37 ( V_33 -> line ) ;
return 0 ;
}
static int F_38 ( struct V_84 * V_85 , T_3 V_103 )
{
struct V_5 * V_33 = F_36 ( V_85 ) ;
F_39 ( V_33 -> line ) ;
return 0 ;
}
static int F_40 ( struct V_84 * V_85 )
{
struct V_5 * V_33 = F_36 ( V_85 ) ;
F_41 ( V_33 -> line ) ;
return 0 ;
}
