static inline void F_1 ( void T_1 * V_1 , T_2 V_2 )
{
F_2 ( F_3 ( V_1 ) | V_2 , V_1 ) ;
}
static inline void F_4 ( void T_1 * V_1 , T_2 V_2 )
{
F_2 ( F_3 ( V_1 ) & ~ V_2 , V_1 ) ;
}
static void F_5 ( struct V_3 * V_4 )
{
void T_1 * V_1 = V_4 -> V_5 + V_6 ;
F_4 ( V_1 , V_7 ) ;
}
static int F_6 ( struct V_3 * V_4 )
{
T_2 V_8 ;
T_2 V_9 = 0 ;
V_4 -> V_10 = F_7 ( V_4 -> V_11 ) ;
V_8 = F_8 ( V_4 -> V_10 , V_12 ) ;
if ( V_4 -> V_13 == V_14 ) {
if ( V_8 < V_15 ||
V_8 > V_16 ) {
F_9 ( V_4 -> V_17 ,
L_1 ) ;
return - V_18 ;
}
} else {
if ( V_8 < V_19 ||
V_8 > V_16 ) {
F_9 ( V_4 -> V_17 ,
L_2 ) ;
return - V_18 ;
}
}
V_9 |= F_10 ( V_8 ) ;
F_2 ( V_9 , V_4 -> V_5 + V_6 ) ;
return 0 ;
}
static void F_11 ( struct V_3 * V_4 )
{
T_2 V_8 = F_8 ( V_4 -> V_10 , V_12 ) ;
T_2 V_20 ;
if ( V_4 -> V_13 == V_14 )
V_20 = V_8 + 1 ;
else
V_20 = V_8 * 3 / 10 + 1 ;
F_2 ( F_12 ( V_20 ) ,
V_4 -> V_5 + V_21 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
T_2 V_22 ;
T_2 V_23 = 0 ;
if ( V_4 -> V_13 == V_14 ) {
V_22 = V_4 -> V_10 / ( 100000 << 1 ) ;
} else {
V_22 = F_8 ( V_4 -> V_10 , 400000 * 3 ) ;
V_23 |= V_24 ;
}
V_23 |= F_14 ( V_22 ) ;
F_2 ( V_23 , V_4 -> V_5 + V_25 ) ;
}
static int F_15 ( struct V_3 * V_4 )
{
int V_26 ;
V_26 = F_6 ( V_4 ) ;
if ( V_26 )
return V_26 ;
F_11 ( V_4 ) ;
F_13 ( V_4 ) ;
F_2 ( V_27 , V_4 -> V_5 + V_28 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 )
{
T_2 V_29 ;
int V_26 ;
V_26 = F_17 ( V_4 -> V_5 + V_30 ,
V_29 ,
! ( V_29 & V_31 ) ,
10 , 1000 ) ;
if ( V_26 ) {
F_18 ( V_4 -> V_17 , L_3 ) ;
V_26 = - V_32 ;
}
return V_26 ;
}
static void F_19 ( struct V_3 * V_4 , T_3 V_33 )
{
F_2 ( V_33 , V_4 -> V_5 + V_34 ) ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = & V_4 -> V_36 ;
F_19 ( V_4 , * V_36 -> V_37 ++ ) ;
V_36 -> V_38 -- ;
}
static void F_21 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = & V_4 -> V_36 ;
T_2 V_39 ;
V_39 = F_3 ( V_4 -> V_5 + V_34 ) ;
* V_36 -> V_37 ++ = V_39 ;
V_36 -> V_38 -- ;
}
static void F_22 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = & V_4 -> V_36 ;
void T_1 * V_1 = V_4 -> V_5 + V_6 ;
F_5 ( V_4 ) ;
V_1 = V_4 -> V_5 + V_28 ;
if ( V_36 -> V_40 )
F_1 ( V_1 , V_41 ) ;
else
F_1 ( V_1 , V_42 ) ;
F_23 ( & V_4 -> F_23 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = & V_4 -> V_36 ;
void T_1 * V_1 = V_4 -> V_5 + V_6 ;
if ( V_36 -> V_38 ) {
F_20 ( V_4 ) ;
if ( ! V_36 -> V_38 ) {
F_4 ( V_1 , V_43 ) ;
}
} else {
F_22 ( V_4 ) ;
}
}
static void F_25 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = & V_4 -> V_36 ;
void T_1 * V_1 = V_4 -> V_5 + V_6 ;
switch ( V_36 -> V_38 ) {
case 1 :
F_5 ( V_4 ) ;
F_21 ( V_4 ) ;
F_23 ( & V_4 -> F_23 ) ;
break;
case 2 :
case 3 :
F_4 ( V_1 , V_43 ) ;
break;
default:
F_21 ( V_4 ) ;
}
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = & V_4 -> V_36 ;
void T_1 * V_1 ;
T_2 V_2 ;
int V_44 ;
switch ( V_36 -> V_38 ) {
case 2 :
V_1 = V_4 -> V_5 + V_28 ;
if ( V_36 -> V_40 )
F_1 ( V_1 , V_41 ) ;
else
F_1 ( V_1 , V_42 ) ;
for ( V_44 = 2 ; V_44 > 0 ; V_44 -- )
F_21 ( V_4 ) ;
V_1 = V_4 -> V_5 + V_6 ;
V_2 = V_45 | V_46 ;
F_4 ( V_1 , V_2 ) ;
F_23 ( & V_4 -> F_23 ) ;
break;
case 3 :
V_1 = V_4 -> V_5 + V_28 ;
F_4 ( V_1 , V_47 ) ;
F_21 ( V_4 ) ;
break;
default:
F_21 ( V_4 ) ;
}
}
static void F_27 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = & V_4 -> V_36 ;
T_2 V_48 ;
switch ( V_36 -> V_38 ) {
case 0 :
F_22 ( V_4 ) ;
F_3 ( V_4 -> V_5 + V_30 ) ;
break;
case 1 :
V_48 = F_3 ( V_4 -> V_5 + V_28 ) ;
V_48 &= ~ ( V_47 | V_49 ) ;
F_2 ( V_48 , V_4 -> V_5 + V_28 ) ;
F_3 ( V_4 -> V_5 + V_30 ) ;
if ( V_36 -> V_40 )
V_48 |= V_41 ;
else
V_48 |= V_42 ;
F_2 ( V_48 , V_4 -> V_5 + V_28 ) ;
break;
case 2 :
V_48 = F_3 ( V_4 -> V_5 + V_28 ) ;
V_48 &= ~ V_47 ;
V_48 |= V_49 ;
F_2 ( V_48 , V_4 -> V_5 + V_28 ) ;
F_3 ( V_4 -> V_5 + V_30 ) ;
break;
default:
V_48 = F_3 ( V_4 -> V_5 + V_28 ) ;
V_48 |= V_47 ;
V_48 &= ~ V_49 ;
F_2 ( V_48 , V_4 -> V_5 + V_28 ) ;
F_3 ( V_4 -> V_5 + V_30 ) ;
break;
}
}
static T_4 F_28 ( int V_50 , void * V_51 )
{
struct V_3 * V_4 = V_51 ;
struct V_35 * V_36 = & V_4 -> V_36 ;
T_2 V_52 = V_53 ;
T_2 V_29 , V_54 , V_55 , V_9 ;
V_9 = F_3 ( V_4 -> V_5 + V_6 ) ;
V_54 = V_9 & V_7 ;
if ( V_54 & V_43 )
V_52 |= V_56 ;
V_29 = F_3 ( V_4 -> V_5 + V_57 ) ;
V_55 = V_29 & V_52 ;
if ( ! V_55 ) {
F_18 ( V_4 -> V_17 ,
L_4 ,
V_29 , V_54 ) ;
return V_58 ;
}
if ( V_55 & V_59 )
F_19 ( V_4 , V_36 -> V_60 ) ;
if ( V_55 & V_61 ) {
if ( V_36 -> V_60 & V_62 )
F_27 ( V_4 ) ;
else
F_3 ( V_4 -> V_5 + V_30 ) ;
V_9 |= V_43 ;
F_2 ( V_9 , V_4 -> V_5 + V_6 ) ;
}
if ( ( V_55 & V_63 ) && ! ( V_36 -> V_60 & V_62 ) )
F_24 ( V_4 ) ;
if ( ( V_55 & V_64 ) && ( V_36 -> V_60 & V_62 ) )
F_25 ( V_4 ) ;
if ( V_55 & V_65 ) {
if ( V_36 -> V_60 & V_62 )
F_26 ( V_4 ) ;
else
F_24 ( V_4 ) ;
}
return V_66 ;
}
static T_4 F_29 ( int V_50 , void * V_51 )
{
struct V_3 * V_4 = V_51 ;
struct V_35 * V_36 = & V_4 -> V_36 ;
void T_1 * V_1 ;
T_2 V_29 ;
V_29 = F_3 ( V_4 -> V_5 + V_57 ) ;
if ( V_29 & V_67 ) {
V_29 &= ~ V_67 ;
F_2 ( V_29 , V_4 -> V_5 + V_57 ) ;
V_36 -> V_68 = - V_69 ;
}
if ( V_29 & V_70 ) {
if ( ! ( V_36 -> V_60 & V_62 ) ) {
V_1 = V_4 -> V_5 + V_28 ;
F_1 ( V_1 , V_41 ) ;
}
V_29 &= ~ V_70 ;
F_2 ( V_29 , V_4 -> V_5 + V_57 ) ;
V_36 -> V_68 = - V_71 ;
}
if ( V_29 & V_72 ) {
V_29 &= ~ V_72 ;
F_2 ( V_29 , V_4 -> V_5 + V_57 ) ;
V_36 -> V_68 = - V_71 ;
}
F_5 ( V_4 ) ;
F_23 ( & V_4 -> F_23 ) ;
return V_66 ;
}
static int F_30 ( struct V_3 * V_4 ,
struct V_73 * V_36 , bool V_74 ,
bool V_75 )
{
struct V_35 * V_76 = & V_4 -> V_36 ;
void T_1 * V_1 = V_4 -> V_5 + V_28 ;
unsigned long V_77 ;
T_2 V_2 ;
int V_26 ;
V_76 -> V_60 = F_31 ( V_36 ) ;
V_76 -> V_37 = V_36 -> V_37 ;
V_76 -> V_38 = V_36 -> V_78 ;
V_76 -> V_68 = 0 ;
V_76 -> V_40 = V_75 ;
F_32 ( & V_4 -> F_23 ) ;
V_2 = V_45 | V_46 ;
F_1 ( V_4 -> V_5 + V_6 , V_2 ) ;
if ( V_74 ) {
V_26 = F_16 ( V_4 ) ;
if ( V_26 )
return V_26 ;
F_1 ( V_1 , V_42 ) ;
}
V_77 = F_33 ( & V_4 -> F_23 ,
V_4 -> V_79 . V_77 ) ;
V_26 = V_76 -> V_68 ;
if ( ! V_77 )
V_26 = - V_80 ;
return V_26 ;
}
static int F_34 ( struct V_81 * V_82 , struct V_73 V_83 [] ,
int V_84 )
{
struct V_3 * V_4 = F_35 ( V_82 ) ;
int V_26 , V_44 ;
V_26 = F_36 ( V_4 -> V_11 ) ;
if ( V_26 ) {
F_9 ( V_4 -> V_17 , L_5 ) ;
return V_26 ;
}
for ( V_44 = 0 ; V_44 < V_84 && ! V_26 ; V_44 ++ )
V_26 = F_30 ( V_4 , & V_83 [ V_44 ] , V_44 == 0 ,
V_44 == V_84 - 1 ) ;
F_37 ( V_4 -> V_11 ) ;
return ( V_26 < 0 ) ? V_26 : V_84 ;
}
static T_2 F_38 ( struct V_81 * V_79 )
{
return V_85 | V_86 ;
}
static int F_39 ( struct V_87 * V_88 )
{
struct V_89 * V_90 = V_88 -> V_17 . V_91 ;
struct V_3 * V_4 ;
struct V_92 * V_93 ;
T_2 V_94 , V_95 , V_96 ;
struct V_81 * V_79 ;
struct V_97 * V_98 ;
int V_26 ;
V_4 = F_40 ( & V_88 -> V_17 , sizeof( * V_4 ) , V_99 ) ;
if ( ! V_4 )
return - V_100 ;
V_93 = F_41 ( V_88 , V_101 , 0 ) ;
V_4 -> V_5 = F_42 ( & V_88 -> V_17 , V_93 ) ;
if ( F_43 ( V_4 -> V_5 ) )
return F_44 ( V_4 -> V_5 ) ;
V_94 = F_45 ( V_90 , 0 ) ;
if ( ! V_94 ) {
F_9 ( & V_88 -> V_17 , L_6 ) ;
return - V_18 ;
}
V_95 = F_45 ( V_90 , 1 ) ;
if ( ! V_95 ) {
F_9 ( & V_88 -> V_17 , L_7 ) ;
return - V_18 ;
}
V_4 -> V_11 = F_46 ( & V_88 -> V_17 , NULL ) ;
if ( F_43 ( V_4 -> V_11 ) ) {
F_9 ( & V_88 -> V_17 , L_8 ) ;
return F_44 ( V_4 -> V_11 ) ;
}
V_26 = F_47 ( V_4 -> V_11 ) ;
if ( V_26 ) {
F_9 ( V_4 -> V_17 , L_9 ) ;
return V_26 ;
}
V_98 = F_48 ( & V_88 -> V_17 , NULL ) ;
if ( F_43 ( V_98 ) ) {
F_9 ( & V_88 -> V_17 , L_10 ) ;
V_26 = F_44 ( V_98 ) ;
goto V_102;
}
F_49 ( V_98 ) ;
F_50 ( 2 ) ;
F_51 ( V_98 ) ;
V_4 -> V_13 = V_14 ;
V_26 = F_52 ( V_90 , L_11 , & V_96 ) ;
if ( ! V_26 && V_96 >= 400000 )
V_4 -> V_13 = V_103 ;
V_4 -> V_17 = & V_88 -> V_17 ;
V_26 = F_53 ( & V_88 -> V_17 , V_94 , F_28 , 0 ,
V_88 -> V_104 , V_4 ) ;
if ( V_26 ) {
F_9 ( & V_88 -> V_17 , L_12 ,
V_94 ) ;
goto V_102;
}
V_26 = F_53 ( & V_88 -> V_17 , V_95 , F_29 , 0 ,
V_88 -> V_104 , V_4 ) ;
if ( V_26 ) {
F_9 ( & V_88 -> V_17 , L_13 ,
V_95 ) ;
goto V_102;
}
V_26 = F_15 ( V_4 ) ;
if ( V_26 )
goto V_102;
V_79 = & V_4 -> V_79 ;
F_54 ( V_79 , V_4 ) ;
snprintf ( V_79 -> V_104 , sizeof( V_79 -> V_104 ) , L_14 , & V_93 -> V_105 ) ;
V_79 -> V_106 = V_107 ;
V_79 -> V_77 = 2 * V_108 ;
V_79 -> V_109 = 0 ;
V_79 -> V_110 = & V_111 ;
V_79 -> V_17 . V_112 = & V_88 -> V_17 ;
V_79 -> V_17 . V_91 = V_88 -> V_17 . V_91 ;
F_55 ( & V_4 -> F_23 ) ;
V_26 = F_56 ( V_79 ) ;
if ( V_26 )
goto V_102;
F_57 ( V_88 , V_4 ) ;
F_37 ( V_4 -> V_11 ) ;
F_58 ( V_4 -> V_17 , L_15 ) ;
return 0 ;
V_102:
F_59 ( V_4 -> V_11 ) ;
return V_26 ;
}
static int F_60 ( struct V_87 * V_88 )
{
struct V_3 * V_4 = F_61 ( V_88 ) ;
F_62 ( & V_4 -> V_79 ) ;
F_63 ( V_4 -> V_11 ) ;
return 0 ;
}
