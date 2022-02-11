static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
int V_4 = V_5 ;
if ( V_3 )
V_4 -- ;
while ( V_2 -> V_6 ) {
if ( V_4 -- <= 0 )
break;
F_2 ( & V_2 -> V_7 . V_8 , L_1 , * V_2 -> V_9 ) ;
F_3 ( * V_2 -> V_9 ++ , V_2 -> V_10 + V_11 ) ;
V_2 -> V_6 -- ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
int V_12 = V_2 -> V_13 & V_14 ?
1 : V_5 ;
while ( V_2 -> V_6 ) {
if ( V_12 -- <= 0 )
break;
* V_2 -> V_9 ++ = F_5 ( V_2 -> V_10 + V_15 ) ;
F_2 ( & V_2 -> V_7 . V_8 , L_2 , V_2 -> V_9 [ - 1 ] ) ;
V_2 -> V_6 -- ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_16 , V_2 -> V_10 + V_17 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_3 ( - 1 , V_2 -> V_10 + V_18 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_7 . V_8 , L_3 ) ;
V_2 -> V_16 |= V_19 ;
F_6 ( V_2 ) ;
F_3 ( V_20 | V_21 ,
V_2 -> V_10 + V_22 ) ;
}
static T_1 F_9 ( int V_23 , void * V_24 )
{
struct V_1 * V_2 = V_24 ;
T_2 V_25 ;
V_25 = F_5 ( V_2 -> V_10 + V_26 ) ;
F_2 ( & V_2 -> V_7 . V_8 ,
L_4 ,
V_2 -> V_16 , V_25 ) ;
if ( V_25 & V_19 )
goto V_27;
if ( F_10 ( V_25 & V_28 ) ) {
F_2 ( & V_2 -> V_7 . V_8 , L_5 ) ;
V_2 -> error = - V_29 ;
goto V_27;
}
if ( F_10 ( V_25 & V_30 ) ) {
F_2 ( & V_2 -> V_7 . V_8 , L_6 ) ;
V_2 -> error = - V_31 ;
if ( V_2 -> V_13 & V_32 ) {
F_8 ( V_2 ) ;
V_2 -> V_13 |= V_33 ;
goto V_27;
}
goto V_34;
}
if ( V_25 & V_35 ) {
if ( ! V_2 -> V_6 )
goto V_36;
F_1 ( V_2 , false ) ;
goto V_37;
}
if ( V_25 & ( V_38 | V_39 ) ) {
F_4 ( V_2 ) ;
if ( ! V_2 -> V_6 )
goto V_36;
if ( F_10 ( V_2 -> V_13 & V_40 ) ) {
if ( V_2 -> V_6 <= V_5 &&
! ( V_2 -> V_13 & V_14 ) ) {
F_2 ( & V_2 -> V_7 . V_8 ,
L_7 ) ;
V_2 -> V_16 |= V_39 ;
F_6 ( V_2 ) ;
V_2 -> V_13 |= V_14 ;
}
if ( V_2 -> V_6 <= 1 ) {
F_2 ( & V_2 -> V_7 . V_8 , L_8 ) ;
F_3 ( V_20 |
V_41 ,
V_2 -> V_10 + V_22 ) ;
}
}
goto V_37;
}
return V_42 ;
V_36:
if ( V_2 -> V_13 & V_43 ) {
V_34:
F_8 ( V_2 ) ;
} else {
V_27:
V_2 -> V_16 = 0 ;
F_6 ( V_2 ) ;
V_27 ( & V_2 -> V_44 ) ;
}
V_37:
F_7 ( V_2 ) ;
return V_45 ;
}
static void F_11 ( struct V_1 * V_2 , T_3 V_46 )
{
V_2 -> V_16 |= V_35 ;
F_3 ( 0 , V_2 -> V_10 + V_47 ) ;
F_3 ( V_48 | V_46 << 1 ,
V_2 -> V_10 + V_11 ) ;
F_1 ( V_2 , true ) ;
}
static void F_12 ( struct V_1 * V_2 , T_3 V_46 )
{
V_2 -> V_13 |= V_32 ;
if ( F_13 ( V_2 -> V_6 < 256 ) ) {
F_3 ( V_2 -> V_6 , V_2 -> V_10 + V_49 ) ;
V_2 -> V_16 |= V_38 |
V_39 ;
} else {
F_3 ( 0 , V_2 -> V_10 + V_49 ) ;
V_2 -> V_13 |= V_40 ;
V_2 -> V_16 |= V_38 ;
}
F_3 ( V_48 | V_50 | V_46 << 1 ,
V_2 -> V_10 + V_11 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_3 ( V_51 , V_2 -> V_10 + V_52 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_3 ( V_53 | V_54 ,
V_2 -> V_10 + V_55 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_17 ( & V_2 -> V_7 ) ;
}
static int F_18 ( struct V_56 * V_7 ,
struct V_57 * V_58 , bool V_34 )
{
struct V_1 * V_2 = F_19 ( V_7 ) ;
bool V_59 = V_58 -> V_13 & V_60 ;
unsigned long V_61 ;
F_2 ( & V_7 -> V_8 , L_9 ,
V_59 ? L_10 : L_11 , V_58 -> V_46 , V_58 -> V_6 , V_34 ) ;
V_2 -> V_6 = V_58 -> V_6 ;
V_2 -> V_9 = V_58 -> V_9 ;
V_2 -> V_16 = V_62 ;
V_2 -> error = 0 ;
V_2 -> V_13 = 0 ;
if ( V_34 )
V_2 -> V_13 |= V_43 ;
F_20 ( & V_2 -> V_44 ) ;
F_7 ( V_2 ) ;
F_3 ( V_63 | V_64 ,
V_2 -> V_10 + V_52 ) ;
if ( V_59 )
F_12 ( V_2 , V_58 -> V_46 ) ;
else
F_11 ( V_2 , V_58 -> V_46 ) ;
F_6 ( V_2 ) ;
F_2 ( & V_7 -> V_8 , L_12 ) ;
F_3 ( V_20 | V_65 ,
V_2 -> V_10 + V_22 ) ;
V_61 = F_21 ( & V_2 -> V_44 , V_7 -> V_66 ) ;
if ( ! V_61 ) {
F_22 ( & V_7 -> V_8 , L_13 ) ;
F_16 ( V_2 ) ;
return - V_67 ;
}
F_2 ( & V_7 -> V_8 , L_14 ) ;
if ( F_10 ( V_2 -> V_13 & V_33 ) ) {
T_2 V_68 = F_5 ( V_2 -> V_10 + V_69 ) ;
if ( ! ( V_68 & V_70 ) ||
V_68 & V_71 ) {
F_22 ( & V_7 -> V_8 ,
L_15 ) ;
F_16 ( V_2 ) ;
return - V_72 ;
}
}
return V_2 -> error ;
}
static int F_23 ( struct V_56 * V_7 )
{
struct V_1 * V_2 = F_19 ( V_7 ) ;
if ( F_5 ( V_2 -> V_10 + V_69 ) & V_73 ) {
if ( V_2 -> V_74 ++ > 3 ) {
F_16 ( V_2 ) ;
V_2 -> V_74 = 0 ;
}
return - V_29 ;
}
V_2 -> V_74 = 0 ;
return 0 ;
}
static int F_24 ( struct V_56 * V_7 ,
struct V_57 * V_75 , int V_76 )
{
struct V_57 * V_58 , * V_77 = V_75 + V_76 ;
int V_78 ;
V_78 = F_23 ( V_7 ) ;
if ( V_78 )
return V_78 ;
for ( V_58 = V_75 ; V_58 < V_77 ; V_58 ++ ) {
bool V_34 = ! ( V_58 + 1 < V_77 && V_58 [ 1 ] . V_13 & V_60 ) ;
if ( V_58 -> V_13 & V_79 )
V_34 = true ;
V_78 = F_18 ( V_7 , V_58 , V_34 ) ;
if ( V_78 )
return V_78 ;
}
return V_76 ;
}
static T_2 F_25 ( struct V_56 * V_7 )
{
return V_80 | V_81 ;
}
static int F_26 ( struct V_56 * V_7 )
{
struct V_1 * V_2 = F_19 ( V_7 ) ;
return ! ! ( F_5 ( V_2 -> V_10 + V_82 ) &
V_83 ) ;
}
static void F_27 ( struct V_56 * V_7 , int V_84 )
{
struct V_1 * V_2 = F_19 ( V_7 ) ;
F_3 ( V_84 ? V_54 : 0 ,
V_2 -> V_10 + V_55 ) ;
}
static int F_28 ( struct V_56 * V_7 )
{
struct V_1 * V_2 = F_19 ( V_7 ) ;
return ! ! ( F_5 ( V_2 -> V_10 + V_82 ) &
V_85 ) ;
}
static void F_29 ( struct V_56 * V_7 )
{
F_15 ( F_19 ( V_7 ) ) ;
}
static int F_30 ( struct V_86 * V_8 ,
struct V_1 * V_2 )
{
struct V_87 * V_88 = V_8 -> V_89 ;
unsigned long V_90 ;
T_2 V_91 , V_92 ;
int V_78 ;
if ( F_31 ( V_88 , L_16 , & V_91 ) )
V_91 = V_93 ;
if ( V_91 > V_94 )
V_91 = V_94 ;
V_2 -> V_95 = F_32 ( V_8 , NULL ) ;
if ( F_33 ( V_2 -> V_95 ) ) {
F_22 ( V_8 , L_17 ) ;
return F_34 ( V_2 -> V_95 ) ;
}
V_78 = F_35 ( V_2 -> V_95 ) ;
if ( V_78 )
return V_78 ;
V_90 = F_36 ( V_2 -> V_95 ) ;
F_14 ( V_2 ) ;
V_92 = V_90 / V_91 ;
F_3 ( V_92 , V_2 -> V_10 + V_96 ) ;
F_3 ( V_92 / 2 , V_2 -> V_10 + V_97 ) ;
F_3 ( V_92 / 2 , V_2 -> V_10 + V_98 ) ;
F_3 ( V_92 / 16 , V_2 -> V_10 + V_99 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_100 * V_101 )
{
struct V_86 * V_8 = & V_101 -> V_8 ;
struct V_1 * V_2 ;
struct V_102 * V_103 ;
int V_23 ;
int V_78 ;
V_2 = F_38 ( V_8 , sizeof( * V_2 ) , V_104 ) ;
if ( ! V_2 )
return - V_105 ;
V_103 = F_39 ( V_101 , V_106 , 0 ) ;
V_2 -> V_10 = F_40 ( V_8 , V_103 ) ;
if ( F_33 ( V_2 -> V_10 ) )
return F_34 ( V_2 -> V_10 ) ;
V_23 = F_41 ( V_101 , 0 ) ;
if ( V_23 < 0 ) {
F_22 ( V_8 , L_18 ) ;
return V_23 ;
}
F_42 ( & V_2 -> V_44 ) ;
V_2 -> V_7 . V_107 = V_108 ;
V_2 -> V_7 . V_109 = & V_110 ;
V_2 -> V_7 . V_8 . V_111 = V_8 ;
V_2 -> V_7 . V_8 . V_89 = V_8 -> V_89 ;
F_43 ( V_2 -> V_7 . V_112 , L_19 , sizeof( V_2 -> V_7 . V_112 ) ) ;
V_2 -> V_7 . V_113 = & V_114 ;
F_44 ( & V_2 -> V_7 , V_2 ) ;
F_45 ( V_101 , V_2 ) ;
V_78 = F_30 ( V_8 , V_2 ) ;
if ( V_78 )
return V_78 ;
V_78 = F_46 ( V_8 , V_23 , F_9 , 0 ,
V_101 -> V_112 , V_2 ) ;
if ( V_78 ) {
F_22 ( V_8 , L_20 , V_23 ) ;
goto V_115;
}
V_78 = F_47 ( & V_2 -> V_7 ) ;
if ( V_78 ) {
F_22 ( V_8 , L_21 ) ;
goto V_115;
}
V_115:
if ( V_78 )
F_48 ( V_2 -> V_95 ) ;
return V_78 ;
}
static int F_49 ( struct V_100 * V_101 )
{
struct V_1 * V_2 = F_50 ( V_101 ) ;
F_51 ( & V_2 -> V_7 ) ;
F_48 ( V_2 -> V_95 ) ;
return 0 ;
}
