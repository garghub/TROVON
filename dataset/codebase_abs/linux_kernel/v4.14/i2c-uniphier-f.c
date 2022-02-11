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
T_2 V_68 ;
int V_69 ;
V_69 = F_23 ( V_2 -> V_10 + V_70 ,
V_68 ,
( V_68 & V_71 ) &&
! ( V_68 & V_72 ) ,
1 , 20 ) ;
if ( V_69 ) {
F_22 ( & V_7 -> V_8 ,
L_15 ) ;
F_16 ( V_2 ) ;
return V_69 ;
}
}
return V_2 -> error ;
}
static int F_24 ( struct V_56 * V_7 )
{
struct V_1 * V_2 = F_19 ( V_7 ) ;
if ( F_5 ( V_2 -> V_10 + V_70 ) & V_73 ) {
if ( V_2 -> V_74 ++ > 3 ) {
F_16 ( V_2 ) ;
V_2 -> V_74 = 0 ;
}
return - V_29 ;
}
V_2 -> V_74 = 0 ;
return 0 ;
}
static int F_25 ( struct V_56 * V_7 ,
struct V_57 * V_75 , int V_76 )
{
struct V_57 * V_58 , * V_77 = V_75 + V_76 ;
int V_69 ;
V_69 = F_24 ( V_7 ) ;
if ( V_69 )
return V_69 ;
for ( V_58 = V_75 ; V_58 < V_77 ; V_58 ++ ) {
bool V_34 = ! ( V_58 + 1 < V_77 && V_58 [ 1 ] . V_13 & V_60 ) ;
if ( V_58 -> V_13 & V_78 )
V_34 = true ;
V_69 = F_18 ( V_7 , V_58 , V_34 ) ;
if ( V_69 )
return V_69 ;
}
return V_76 ;
}
static T_2 F_26 ( struct V_56 * V_7 )
{
return V_79 | V_80 ;
}
static int F_27 ( struct V_56 * V_7 )
{
struct V_1 * V_2 = F_19 ( V_7 ) ;
return ! ! ( F_5 ( V_2 -> V_10 + V_81 ) &
V_82 ) ;
}
static void F_28 ( struct V_56 * V_7 , int V_83 )
{
struct V_1 * V_2 = F_19 ( V_7 ) ;
F_3 ( V_83 ? V_54 : 0 ,
V_2 -> V_10 + V_55 ) ;
}
static int F_29 ( struct V_56 * V_7 )
{
struct V_1 * V_2 = F_19 ( V_7 ) ;
return ! ! ( F_5 ( V_2 -> V_10 + V_81 ) &
V_84 ) ;
}
static void F_30 ( struct V_56 * V_7 )
{
F_15 ( F_19 ( V_7 ) ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
unsigned int V_85 = V_2 -> V_86 ;
T_2 V_87 ;
V_87 = F_5 ( V_2 -> V_10 + V_22 ) ;
V_87 |= V_20 ;
F_3 ( V_87 , V_2 -> V_10 + V_22 ) ;
F_14 ( V_2 ) ;
F_3 ( V_85 , V_2 -> V_10 + V_88 ) ;
F_3 ( V_85 / 2 , V_2 -> V_10 + V_89 ) ;
F_3 ( V_85 / 2 , V_2 -> V_10 + V_90 ) ;
F_3 ( V_85 / 16 , V_2 -> V_10 + V_91 ) ;
F_15 ( V_2 ) ;
}
static int F_32 ( struct V_92 * V_93 )
{
struct V_94 * V_8 = & V_93 -> V_8 ;
struct V_1 * V_2 ;
struct V_95 * V_96 ;
T_2 V_97 ;
unsigned long V_98 ;
int V_23 , V_69 ;
V_2 = F_33 ( V_8 , sizeof( * V_2 ) , V_99 ) ;
if ( ! V_2 )
return - V_100 ;
V_96 = F_34 ( V_93 , V_101 , 0 ) ;
V_2 -> V_10 = F_35 ( V_8 , V_96 ) ;
if ( F_36 ( V_2 -> V_10 ) )
return F_37 ( V_2 -> V_10 ) ;
V_23 = F_38 ( V_93 , 0 ) ;
if ( V_23 < 0 ) {
F_22 ( V_8 , L_16 ) ;
return V_23 ;
}
if ( F_39 ( V_8 -> V_102 , L_17 , & V_97 ) )
V_97 = V_103 ;
if ( ! V_97 || V_97 > V_104 ) {
F_22 ( V_8 , L_18 , V_97 ) ;
return - V_105 ;
}
V_2 -> V_106 = F_40 ( V_8 , NULL ) ;
if ( F_36 ( V_2 -> V_106 ) ) {
F_22 ( V_8 , L_19 ) ;
return F_37 ( V_2 -> V_106 ) ;
}
V_69 = F_41 ( V_2 -> V_106 ) ;
if ( V_69 )
return V_69 ;
V_98 = F_42 ( V_2 -> V_106 ) ;
if ( ! V_98 ) {
F_22 ( V_8 , L_20 ) ;
V_69 = - V_105 ;
goto V_107;
}
V_2 -> V_86 = V_98 / V_97 ;
F_43 ( & V_2 -> V_44 ) ;
V_2 -> V_7 . V_108 = V_109 ;
V_2 -> V_7 . V_110 = & V_111 ;
V_2 -> V_7 . V_8 . V_112 = V_8 ;
V_2 -> V_7 . V_8 . V_102 = V_8 -> V_102 ;
F_44 ( V_2 -> V_7 . V_113 , L_21 , sizeof( V_2 -> V_7 . V_113 ) ) ;
V_2 -> V_7 . V_114 = & V_115 ;
F_45 ( & V_2 -> V_7 , V_2 ) ;
F_46 ( V_93 , V_2 ) ;
F_31 ( V_2 ) ;
V_69 = F_47 ( V_8 , V_23 , F_9 , 0 ,
V_93 -> V_113 , V_2 ) ;
if ( V_69 ) {
F_22 ( V_8 , L_22 , V_23 ) ;
goto V_107;
}
V_69 = F_48 ( & V_2 -> V_7 ) ;
V_107:
if ( V_69 )
F_49 ( V_2 -> V_106 ) ;
return V_69 ;
}
static int F_50 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_51 ( V_93 ) ;
F_52 ( & V_2 -> V_7 ) ;
F_49 ( V_2 -> V_106 ) ;
return 0 ;
}
static int T_4 F_53 ( struct V_94 * V_8 )
{
struct V_1 * V_2 = F_54 ( V_8 ) ;
F_49 ( V_2 -> V_106 ) ;
return 0 ;
}
static int T_4 F_55 ( struct V_94 * V_8 )
{
struct V_1 * V_2 = F_54 ( V_8 ) ;
int V_69 ;
V_69 = F_41 ( V_2 -> V_106 ) ;
if ( V_69 )
return V_69 ;
F_31 ( V_2 ) ;
return 0 ;
}
