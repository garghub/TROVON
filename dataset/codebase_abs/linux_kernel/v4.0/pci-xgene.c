static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( V_1 & V_3 ) | V_2 ;
}
static void T_2 * F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_5 -> V_9 >= ( V_5 -> V_10 + 1 ) )
return V_7 -> V_11 + V_12 ;
return V_7 -> V_11 ;
}
static void F_3 ( struct V_4 * V_5 , T_3 V_13 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned int V_14 , V_15 , V_16 ;
T_1 V_17 = 0 ;
V_14 = V_5 -> V_9 ;
V_15 = F_4 ( V_13 ) ;
V_16 = F_5 ( V_13 ) ;
if ( ! F_6 ( V_5 ) )
V_17 = ( V_14 << 8 ) | ( V_15 << 3 ) | V_16 ;
F_7 ( V_17 , V_7 -> V_18 + V_19 ) ;
F_8 ( V_7 -> V_18 + V_19 ) ;
}
static bool F_9 ( struct V_4 * V_5 , int V_20 )
{
if ( F_6 ( V_5 ) && ( ( V_20 == V_21 ) ||
( V_20 == V_22 ) ) )
return true ;
return false ;
}
static void T_2 * F_10 ( struct V_4 * V_5 , unsigned int V_13 ,
int V_20 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
if ( ( F_6 ( V_5 ) && V_13 != 0 ) || ! V_7 -> V_23 ||
F_9 ( V_5 , V_20 ) )
return NULL ;
F_3 ( V_5 , V_13 ) ;
return F_2 ( V_5 ) + V_20 ;
}
static T_4 F_11 ( void T_2 * V_18 , T_1 V_1 ,
T_1 V_2 , T_4 V_24 )
{
T_4 V_25 = ( ~ ( V_24 - 1 ) & V_3 ) | V_2 ;
T_1 V_26 = 0 ;
T_1 V_27 ;
V_26 = F_8 ( V_18 + V_1 ) ;
V_27 = ( V_26 & 0x0000ffff ) | ( F_12 ( V_25 ) << 16 ) ;
F_7 ( V_27 , V_18 + V_1 ) ;
V_26 = F_8 ( V_18 + V_1 + 0x04 ) ;
V_27 = ( V_26 & 0xffff0000 ) | ( F_12 ( V_25 ) >> 16 ) ;
F_7 ( V_27 , V_18 + V_1 + 0x04 ) ;
V_26 = F_8 ( V_18 + V_1 + 0x04 ) ;
V_27 = ( V_26 & 0x0000ffff ) | ( F_13 ( V_25 ) << 16 ) ;
F_7 ( V_27 , V_18 + V_1 + 0x04 ) ;
V_26 = F_8 ( V_18 + V_1 + 0x08 ) ;
V_27 = ( V_26 & 0xffff0000 ) | ( F_13 ( V_25 ) >> 16 ) ;
F_7 ( V_27 , V_18 + V_1 + 0x08 ) ;
return V_25 ;
}
static void F_14 ( struct V_6 * V_7 ,
T_1 * V_28 , T_1 * V_29 )
{
void T_2 * V_18 = V_7 -> V_18 ;
T_1 V_26 ;
V_7 -> V_23 = false ;
V_26 = F_8 ( V_18 + V_30 ) ;
if ( V_26 & V_31 ) {
V_7 -> V_23 = true ;
* V_29 = F_15 ( V_26 ) ;
V_26 = F_8 ( V_18 + V_32 ) ;
* V_28 = V_26 >> 26 ;
}
}
static int F_16 ( struct V_6 * V_7 )
{
int V_33 ;
V_7 -> V_34 = F_17 ( V_7 -> V_35 , NULL ) ;
if ( F_18 ( V_7 -> V_34 ) ) {
F_19 ( V_7 -> V_35 , L_1 ) ;
return - V_36 ;
}
V_33 = F_20 ( V_7 -> V_34 ) ;
if ( V_33 ) {
F_19 ( V_7 -> V_35 , L_2 ) ;
return V_33 ;
}
return 0 ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 ;
V_40 = F_22 ( V_38 , V_41 , L_3 ) ;
V_7 -> V_18 = F_23 ( V_7 -> V_35 , V_40 ) ;
if ( F_18 ( V_7 -> V_18 ) )
return F_24 ( V_7 -> V_18 ) ;
V_40 = F_22 ( V_38 , V_41 , L_4 ) ;
V_7 -> V_11 = F_23 ( V_7 -> V_35 , V_40 ) ;
if ( F_18 ( V_7 -> V_11 ) )
return F_24 ( V_7 -> V_11 ) ;
V_7 -> V_42 = V_40 -> V_43 ;
return 0 ;
}
static void F_25 ( struct V_6 * V_7 ,
struct V_39 * V_40 , T_1 V_20 ,
T_4 V_44 , T_4 V_45 )
{
void T_2 * V_46 = V_7 -> V_18 + V_20 ;
T_5 V_24 = F_26 ( V_40 ) ;
T_4 V_47 = F_27 ( V_40 ) ;
T_4 V_25 = 0 ;
T_1 V_48 ;
T_1 V_49 = V_50 ;
if ( V_47 == V_41 ) {
V_48 = V_51 ;
} else {
V_48 = 128 ;
V_49 |= V_52 ;
}
if ( V_24 >= V_48 )
V_25 = ~ ( V_24 - 1 ) | V_49 ;
else
F_28 ( V_7 -> V_35 , L_5 ,
( T_4 ) V_24 , V_48 ) ;
F_7 ( F_12 ( V_44 ) , V_46 ) ;
F_7 ( F_13 ( V_44 ) , V_46 + 0x04 ) ;
F_7 ( F_12 ( V_25 ) , V_46 + 0x08 ) ;
F_7 ( F_13 ( V_25 ) , V_46 + 0x0c ) ;
F_7 ( F_12 ( V_45 ) , V_46 + 0x10 ) ;
F_7 ( F_13 ( V_45 ) , V_46 + 0x14 ) ;
}
static void F_29 ( void T_2 * V_18 , T_4 V_1 )
{
F_7 ( F_12 ( V_1 ) , V_18 + V_53 ) ;
F_7 ( F_13 ( V_1 ) , V_18 + V_54 ) ;
F_7 ( V_50 , V_18 + V_55 ) ;
}
static int F_30 ( struct V_6 * V_7 ,
struct V_56 * V_40 ,
T_5 V_57 )
{
struct V_58 * V_59 ;
struct V_60 * V_35 = V_7 -> V_35 ;
int V_61 ;
F_31 (window, res) {
struct V_39 * V_40 = V_59 -> V_40 ;
T_4 V_47 = F_27 ( V_40 ) ;
F_32 ( V_7 -> V_35 , L_6 , V_40 ) ;
switch ( V_47 ) {
case V_62 :
F_25 ( V_7 , V_40 , V_63 , V_57 ,
V_40 -> V_43 - V_59 -> V_20 ) ;
V_61 = F_33 ( V_40 , V_57 ) ;
if ( V_61 < 0 )
return V_61 ;
break;
case V_41 :
F_25 ( V_7 , V_40 , V_64 , V_40 -> V_43 ,
V_40 -> V_43 - V_59 -> V_20 ) ;
break;
case V_65 :
break;
default:
F_19 ( V_35 , L_7 , V_40 ) ;
return - V_66 ;
}
}
F_29 ( V_7 -> V_18 , V_7 -> V_42 ) ;
return 0 ;
}
static void F_34 ( void * V_1 , T_4 V_67 , T_4 V_24 )
{
F_7 ( F_12 ( V_67 ) , V_1 ) ;
F_7 ( F_13 ( V_67 ) | V_68 , V_1 + 0x04 ) ;
F_7 ( F_12 ( V_24 ) , V_1 + 0x10 ) ;
F_7 ( F_13 ( V_24 ) , V_1 + 0x14 ) ;
}
static int F_35 ( T_6 * V_69 , T_4 V_24 )
{
if ( ( V_24 > 4 ) && ( V_24 < V_70 ) && ! ( * V_69 & ( 1 << 1 ) ) ) {
* V_69 |= ( 1 << 1 ) ;
return 1 ;
}
if ( ( V_24 > V_71 ) && ( V_24 < V_72 ) && ! ( * V_69 & ( 1 << 0 ) ) ) {
* V_69 |= ( 1 << 0 ) ;
return 0 ;
}
if ( ( V_24 > V_73 ) && ( V_24 < V_72 ) && ! ( * V_69 & ( 1 << 2 ) ) ) {
* V_69 |= ( 1 << 2 ) ;
return 2 ;
}
return - V_66 ;
}
static void F_36 ( struct V_6 * V_7 ,
struct V_74 * V_75 , T_6 * V_69 )
{
void T_2 * V_18 = V_7 -> V_18 ;
void T_2 * V_11 = V_7 -> V_11 ;
void * V_76 ;
void * V_77 ;
T_4 V_44 = V_75 -> V_44 ;
T_4 V_45 = V_75 -> V_45 ;
T_4 V_24 = V_75 -> V_24 ;
T_4 V_25 = ~ ( V_24 - 1 ) | V_50 ;
T_1 V_2 = V_78 ;
T_1 V_79 ;
int V_80 ;
V_80 = F_35 ( V_69 , V_75 -> V_24 ) ;
if ( V_80 < 0 ) {
F_28 ( V_7 -> V_35 , L_8 ) ;
return;
}
if ( V_75 -> V_2 & V_81 )
V_2 |= V_82 ;
V_79 = F_1 ( ( T_1 ) V_44 , V_2 ) ;
switch ( V_80 ) {
case 0 :
F_11 ( V_18 , V_83 , V_2 , V_24 ) ;
V_76 = V_11 + V_21 ;
F_7 ( V_79 , V_76 ) ;
F_7 ( F_13 ( V_44 ) , V_76 + 0x4 ) ;
V_77 = V_18 + V_84 ;
break;
case 1 :
V_76 = V_18 + V_85 ;
F_7 ( V_79 , V_76 ) ;
F_7 ( F_12 ( V_25 ) , V_18 + V_86 ) ;
V_77 = V_18 + V_87 ;
break;
case 2 :
V_76 = V_18 + V_88 ;
F_7 ( V_79 , V_76 ) ;
F_7 ( F_13 ( V_44 ) , V_76 + 0x4 ) ;
F_7 ( F_12 ( V_25 ) , V_18 + V_89 ) ;
F_7 ( F_13 ( V_25 ) , V_18 + V_89 + 0x4 ) ;
V_77 = V_18 + V_90 ;
break;
}
F_34 ( V_77 , V_45 , ~ ( V_24 - 1 ) ) ;
}
static int F_37 ( struct V_91 * V_92 ,
struct V_93 * V_94 )
{
const int V_95 = 3 , V_96 = 2 ;
int V_97 ;
V_92 -> V_94 = V_94 ;
V_92 -> V_98 = F_38 ( V_94 ) ;
V_92 -> V_99 = V_92 -> V_98 + V_95 + V_96 ;
V_92 -> V_75 = F_39 ( V_94 , L_9 , & V_97 ) ;
if ( ! V_92 -> V_75 )
return - V_100 ;
V_92 -> V_101 = V_92 -> V_75 + V_97 / sizeof( V_102 ) ;
return 0 ;
}
static int F_40 ( struct V_6 * V_7 )
{
struct V_93 * V_99 = V_7 -> V_94 ;
struct V_74 V_75 ;
struct V_91 V_92 ;
struct V_60 * V_35 = V_7 -> V_35 ;
T_6 V_69 = 0 ;
if ( F_37 ( & V_92 , V_99 ) ) {
F_19 ( V_35 , L_10 ) ;
return - V_66 ;
}
F_41 (&parser, &range) {
T_4 V_101 = V_75 . V_44 + V_75 . V_24 - 1 ;
F_32 ( V_7 -> V_35 , L_11 ,
V_75 . V_2 , V_75 . V_44 , V_101 , V_75 . V_45 ) ;
F_36 ( V_7 , & V_75 , & V_69 ) ;
}
return 0 ;
}
static void F_42 ( struct V_6 * V_7 )
{
int V_103 ;
for ( V_103 = V_84 ; V_103 <= V_55 ; V_103 += 4 )
F_7 ( 0x0 , V_7 -> V_18 + V_103 ) ;
}
static int F_43 ( struct V_6 * V_7 ,
struct V_56 * V_40 ,
T_5 V_57 )
{
T_1 V_27 , V_28 = 0 , V_29 = 0 ;
int V_61 ;
F_42 ( V_7 ) ;
V_27 = ( V_104 << 16 ) | V_105 ;
F_7 ( V_27 , V_7 -> V_18 + V_106 ) ;
V_61 = F_30 ( V_7 , V_40 , V_57 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_40 ( V_7 ) ;
if ( V_61 )
return V_61 ;
F_14 ( V_7 , & V_28 , & V_29 ) ;
if ( ! V_7 -> V_23 )
F_44 ( V_7 -> V_35 , L_12 ) ;
else
F_44 ( V_7 -> V_35 , L_13 ,
V_28 , V_29 + 1 ) ;
return 0 ;
}
static int F_45 ( struct V_37 * V_38 )
{
struct V_93 * V_107 = V_38 -> V_35 . V_108 ;
struct V_6 * V_7 ;
T_5 V_109 = 0 ;
struct V_4 * V_5 ;
int V_61 ;
F_46 ( V_40 ) ;
V_7 = F_47 ( & V_38 -> V_35 , sizeof( * V_7 ) , V_110 ) ;
if ( ! V_7 )
return - V_111 ;
V_7 -> V_94 = F_48 ( V_38 -> V_35 . V_108 ) ;
V_7 -> V_35 = & V_38 -> V_35 ;
V_61 = F_21 ( V_7 , V_38 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_16 ( V_7 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_49 ( V_107 , 0 , 0xff , & V_40 , & V_109 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_43 ( V_7 , & V_40 , V_109 ) ;
if ( V_61 )
return V_61 ;
V_5 = F_50 ( & V_38 -> V_35 , 0 ,
& V_112 , V_7 , & V_40 ) ;
if ( ! V_5 )
return - V_111 ;
F_51 ( V_5 ) ;
F_52 ( V_5 ) ;
F_53 ( V_5 ) ;
F_54 ( V_38 , V_7 ) ;
return 0 ;
}
