static void T_1 * F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_4 ;
}
static void T_1 * F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_5 ;
}
static void T_1 * F_3 ( struct V_1
* V_2 )
{
return V_2 -> V_3 + V_6 ;
}
static void T_1 * F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_7 ;
}
static void T_1 * F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_8 ;
}
static void T_1 * F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_3 + V_9 ;
}
static void T_1 * F_7 ( struct V_1 * V_2 )
{
int V_10 ;
switch ( V_2 -> V_11 ) {
case V_12 :
case V_13 :
return V_2 -> V_3 + V_14 ;
case V_15 :
V_10 = F_8 () ;
return V_2 -> V_16 +
F_9 ( V_10 ) ;
default:
F_10 () ;
}
}
static void T_1 * F_11 ( struct V_1 * V_2 )
{
int V_10 ;
switch ( V_2 -> V_11 ) {
case V_12 :
return V_2 -> V_3 + V_17 ;
case V_13 :
V_10 = F_8 () ;
return V_2 -> V_3 + F_12 ( V_10 ) ;
case V_15 :
V_10 = F_8 () ;
return V_2 -> V_16 +
F_13 ( V_10 ) ;
default:
F_10 () ;
}
}
static void T_1 * F_14 ( struct V_1 * V_2 )
{
int V_10 ;
switch ( V_2 -> V_11 ) {
case V_12 :
return V_2 -> V_3 + V_18 ;
case V_13 :
V_10 = F_8 () ;
return V_2 -> V_3 + F_15 ( V_10 ) ;
case V_15 :
V_10 = F_8 () ;
return V_2 -> V_16 +
F_16 ( V_10 ) ;
default:
F_10 () ;
}
}
static void T_1 * F_17 ( struct V_19 * V_20 )
{
return V_20 -> V_3 + V_21 ;
}
static void T_1 * F_18 ( struct V_19 * V_20 )
{
return V_20 -> V_3 + V_22 ;
}
static void F_19 ( struct V_23 * V_24 , unsigned int V_25 , int V_26 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
unsigned long V_27 ;
T_2 V_28 ;
F_21 ( & V_2 -> V_29 , V_27 ) ;
V_28 = F_22 ( F_1 ( V_2 ) ) ;
if ( V_26 )
V_28 |= F_23 ( V_25 ) ;
else
V_28 &= ~ F_23 ( V_25 ) ;
F_24 ( V_28 , F_1 ( V_2 ) ) ;
F_25 ( & V_2 -> V_29 , V_27 ) ;
}
static int F_26 ( struct V_23 * V_24 , unsigned int V_25 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
T_2 V_28 ;
if ( F_22 ( F_4 ( V_2 ) ) & F_23 ( V_25 ) ) {
V_28 = F_22 ( F_6 ( V_2 ) ) ^
F_22 ( F_5 ( V_2 ) ) ;
} else {
V_28 = F_22 ( F_1 ( V_2 ) ) ;
}
return ( V_28 >> V_25 ) & 1 ;
}
static void F_27 ( struct V_23 * V_24 , unsigned int V_25 ,
int V_26 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
unsigned long V_27 ;
T_2 V_28 ;
F_21 ( & V_2 -> V_29 , V_27 ) ;
V_28 = F_22 ( F_2 ( V_2 ) ) ;
if ( V_26 )
V_28 |= F_23 ( V_25 ) ;
else
V_28 &= ~ F_23 ( V_25 ) ;
F_24 ( V_28 , F_2 ( V_2 ) ) ;
F_25 ( & V_2 -> V_29 , V_27 ) ;
}
static int F_28 ( struct V_23 * V_24 , unsigned int V_25 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
unsigned long V_27 ;
int V_30 ;
T_2 V_28 ;
V_30 = F_29 ( V_24 -> V_31 + V_25 ) ;
if ( V_30 )
return V_30 ;
F_21 ( & V_2 -> V_29 , V_27 ) ;
V_28 = F_22 ( F_4 ( V_2 ) ) ;
V_28 |= F_23 ( V_25 ) ;
F_24 ( V_28 , F_4 ( V_2 ) ) ;
F_25 ( & V_2 -> V_29 , V_27 ) ;
return 0 ;
}
static int F_30 ( struct V_23 * V_24 , unsigned int V_25 ,
int V_26 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
unsigned long V_27 ;
int V_30 ;
T_2 V_28 ;
V_30 = F_31 ( V_24 -> V_31 + V_25 ) ;
if ( V_30 )
return V_30 ;
F_27 ( V_24 , V_25 , 0 ) ;
F_19 ( V_24 , V_25 , V_26 ) ;
F_21 ( & V_2 -> V_29 , V_27 ) ;
V_28 = F_22 ( F_4 ( V_2 ) ) ;
V_28 &= ~ F_23 ( V_25 ) ;
F_24 ( V_28 , F_4 ( V_2 ) ) ;
F_25 ( & V_2 -> V_29 , V_27 ) ;
return 0 ;
}
static int F_32 ( struct V_23 * V_24 , unsigned int V_25 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
return F_33 ( V_2 -> V_32 , V_25 ) ;
}
static void F_34 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_35 ( V_34 ) ;
struct V_1 * V_2 = V_36 -> V_37 ;
T_2 V_38 = V_34 -> V_38 ;
F_36 ( V_36 ) ;
F_24 ( ~ V_38 , F_7 ( V_2 ) ) ;
F_37 ( V_36 ) ;
}
static void F_38 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_35 ( V_34 ) ;
struct V_1 * V_2 = V_36 -> V_37 ;
struct V_39 * V_40 = F_39 ( V_34 ) ;
T_2 V_38 = V_34 -> V_38 ;
F_36 ( V_36 ) ;
V_40 -> V_41 &= ~ V_38 ;
F_24 ( V_40 -> V_41 , F_11 ( V_2 ) ) ;
F_37 ( V_36 ) ;
}
static void F_40 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_35 ( V_34 ) ;
struct V_1 * V_2 = V_36 -> V_37 ;
struct V_39 * V_40 = F_39 ( V_34 ) ;
T_2 V_38 = V_34 -> V_38 ;
F_36 ( V_36 ) ;
V_40 -> V_41 |= V_38 ;
F_24 ( V_40 -> V_41 , F_11 ( V_2 ) ) ;
F_37 ( V_36 ) ;
}
static void F_41 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_35 ( V_34 ) ;
struct V_1 * V_2 = V_36 -> V_37 ;
struct V_39 * V_40 = F_39 ( V_34 ) ;
T_2 V_38 = V_34 -> V_38 ;
F_36 ( V_36 ) ;
V_40 -> V_41 &= ~ V_38 ;
F_24 ( V_40 -> V_41 , F_14 ( V_2 ) ) ;
F_37 ( V_36 ) ;
}
static void F_42 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_35 ( V_34 ) ;
struct V_1 * V_2 = V_36 -> V_37 ;
struct V_39 * V_40 = F_39 ( V_34 ) ;
T_2 V_38 = V_34 -> V_38 ;
F_36 ( V_36 ) ;
V_40 -> V_41 |= V_38 ;
F_24 ( V_40 -> V_41 , F_14 ( V_2 ) ) ;
F_37 ( V_36 ) ;
}
static int F_43 ( struct V_33 * V_34 , unsigned int type )
{
struct V_35 * V_36 = F_35 ( V_34 ) ;
struct V_39 * V_40 = F_39 ( V_34 ) ;
struct V_1 * V_2 = V_36 -> V_37 ;
int V_25 ;
T_2 V_28 ;
V_25 = V_34 -> V_42 ;
V_28 = F_22 ( F_4 ( V_2 ) ) & F_23 ( V_25 ) ;
if ( ! V_28 )
return - V_43 ;
type &= V_44 ;
if ( type == V_45 )
return - V_43 ;
if ( ! ( V_40 -> type & type ) )
if ( F_44 ( V_34 , type ) )
return - V_43 ;
switch ( type ) {
case V_46 :
case V_47 :
V_28 = F_22 ( F_5 ( V_2 ) ) ;
V_28 &= ~ F_23 ( V_25 ) ;
F_24 ( V_28 , F_5 ( V_2 ) ) ;
break;
case V_48 :
case V_49 :
V_28 = F_22 ( F_5 ( V_2 ) ) ;
V_28 |= F_23 ( V_25 ) ;
F_24 ( V_28 , F_5 ( V_2 ) ) ;
break;
case V_50 : {
T_2 V_51 ;
V_51 = F_22 ( F_5 ( V_2 ) ) ^
F_22 ( F_6 ( V_2 ) ) ;
V_28 = F_22 ( F_5 ( V_2 ) ) ;
if ( V_51 & F_23 ( V_25 ) )
V_28 |= F_23 ( V_25 ) ;
else
V_28 &= ~ F_23 ( V_25 ) ;
F_24 ( V_28 , F_5 ( V_2 ) ) ;
break;
}
}
return 0 ;
}
static void F_45 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_46 ( V_53 ) ;
struct V_54 * V_24 = F_47 ( V_53 ) ;
T_2 V_55 , type ;
int V_56 ;
if ( V_2 == NULL )
return;
F_48 ( V_24 , V_53 ) ;
V_55 = F_22 ( F_6 ( V_2 ) ) &
F_22 ( F_14 ( V_2 ) ) ;
V_55 |= F_22 ( F_7 ( V_2 ) ) &
F_22 ( F_11 ( V_2 ) ) ;
for ( V_56 = 0 ; V_56 < V_2 -> V_24 . V_57 ; V_56 ++ ) {
int V_58 ;
V_58 = F_49 ( V_2 -> V_32 , V_56 ) ;
if ( ! ( V_55 & F_23 ( V_56 ) ) )
continue;
type = F_50 ( V_58 ) ;
if ( ( type & V_44 ) == V_50 ) {
T_2 V_59 ;
V_59 = F_22 ( F_5 ( V_2 ) ) ;
V_59 ^= F_23 ( V_56 ) ;
F_24 ( V_59 , F_5 ( V_2 ) ) ;
}
F_51 ( V_58 ) ;
}
F_52 ( V_24 , V_53 ) ;
}
static struct V_19 * F_53 ( struct V_60 * V_24 )
{
return F_54 ( V_24 , struct V_19 , V_24 ) ;
}
static int F_55 ( struct V_60 * V_24 , struct V_61 * V_62 )
{
struct V_19 * V_20 = F_53 ( V_24 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
struct V_63 * V_53 ;
unsigned long V_27 ;
int V_30 = 0 ;
F_21 ( & V_20 -> V_29 , V_27 ) ;
if ( V_20 -> V_64 ) {
V_30 = - V_65 ;
} else {
V_53 = F_56 ( V_2 -> V_24 . V_31 + V_62 -> V_66 ) ;
if ( ! V_53 ) {
V_30 = - V_67 ;
goto V_68;
}
V_30 = F_57 ( V_53 , L_1 ) ;
if ( V_30 )
goto V_68;
V_30 = F_58 ( V_53 , 0 ) ;
if ( V_30 ) {
F_59 ( V_53 ) ;
goto V_68;
}
V_20 -> V_64 = V_53 ;
}
V_68:
F_25 ( & V_20 -> V_29 , V_27 ) ;
return V_30 ;
}
static void F_60 ( struct V_60 * V_24 , struct V_61 * V_62 )
{
struct V_19 * V_20 = F_53 ( V_24 ) ;
unsigned long V_27 ;
F_21 ( & V_20 -> V_29 , V_27 ) ;
F_59 ( V_20 -> V_64 ) ;
V_20 -> V_64 = NULL ;
F_25 ( & V_20 -> V_29 , V_27 ) ;
}
static void F_61 ( struct V_60 * V_24 ,
struct V_61 * V_62 ,
struct V_69 * V_70 ) {
struct V_19 * V_20 = F_53 ( V_24 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
unsigned long long V_71 ;
unsigned long V_27 ;
T_2 V_28 ;
F_21 ( & V_20 -> V_29 , V_27 ) ;
V_71 = ( unsigned long long )
F_22 ( F_17 ( V_20 ) ) ;
V_71 *= V_72 ;
F_62 ( V_71 , V_20 -> V_73 ) ;
if ( V_71 > V_74 )
V_70 -> V_75 = V_74 ;
else if ( V_71 )
V_70 -> V_75 = V_71 ;
else
V_70 -> V_75 = 1 ;
V_71 = ( unsigned long long )
F_22 ( F_18 ( V_20 ) ) ;
V_71 *= V_72 ;
F_62 ( V_71 , V_20 -> V_73 ) ;
if ( V_71 < V_70 -> V_75 ) {
V_70 -> V_76 = 1 ;
} else {
V_71 -= V_70 -> V_75 ;
if ( V_71 > V_74 )
V_70 -> V_76 = V_74 ;
else if ( V_71 )
V_70 -> V_76 = V_71 ;
else
V_70 -> V_76 = 1 ;
}
V_28 = F_22 ( F_2 ( V_2 ) ) ;
if ( V_28 )
V_70 -> V_77 = true ;
else
V_70 -> V_77 = false ;
F_25 ( & V_20 -> V_29 , V_27 ) ;
}
static int F_63 ( struct V_60 * V_24 , struct V_61 * V_62 ,
struct V_69 * V_70 )
{
struct V_19 * V_20 = F_53 ( V_24 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
unsigned long long V_71 ;
unsigned long V_27 ;
unsigned int V_78 , V_79 ;
V_71 = ( unsigned long long ) V_20 -> V_73 * V_70 -> V_75 ;
F_62 ( V_71 , V_72 ) ;
if ( V_71 > V_74 )
return - V_43 ;
if ( V_71 )
V_78 = V_71 ;
else
V_78 = 1 ;
V_71 = ( unsigned long long ) V_20 -> V_73 *
( V_70 -> V_76 - V_70 -> V_75 ) ;
F_62 ( V_71 , V_72 ) ;
if ( V_71 > V_74 )
return - V_43 ;
if ( V_71 )
V_79 = V_71 ;
else
V_79 = 1 ;
F_21 ( & V_20 -> V_29 , V_27 ) ;
F_24 ( V_78 , F_17 ( V_20 ) ) ;
F_24 ( V_79 , F_18 ( V_20 ) ) ;
if ( V_70 -> V_77 )
F_27 ( & V_2 -> V_24 , V_62 -> V_66 , 1 ) ;
else
F_27 ( & V_2 -> V_24 , V_62 -> V_66 , 0 ) ;
F_25 ( & V_20 -> V_29 , V_27 ) ;
return 0 ;
}
static void T_3 F_64 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
V_20 -> V_80 =
F_22 ( F_3 ( V_2 ) ) ;
V_20 -> V_81 =
F_22 ( F_17 ( V_20 ) ) ;
V_20 -> V_82 =
F_22 ( F_18 ( V_20 ) ) ;
}
static void T_3 F_65 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
F_24 ( V_20 -> V_80 ,
F_3 ( V_2 ) ) ;
F_24 ( V_20 -> V_81 ,
F_17 ( V_20 ) ) ;
F_24 ( V_20 -> V_82 ,
F_18 ( V_20 ) ) ;
}
static int F_66 ( struct V_83 * V_84 ,
struct V_1 * V_2 ,
int V_85 )
{
struct V_86 * V_87 = & V_84 -> V_87 ;
struct V_19 * V_20 ;
struct V_88 * V_89 ;
T_2 V_90 ;
if ( ! F_67 ( V_2 -> V_24 . V_91 ,
L_2 ) )
return 0 ;
if ( F_68 ( V_2 -> V_92 ) )
return F_69 ( V_2 -> V_92 ) ;
V_89 = F_70 ( V_84 , V_93 , L_3 ) ;
if ( ! V_89 )
return 0 ;
if ( V_85 == 0 )
V_90 = 0 ;
else if ( V_85 == 1 )
V_90 = V_94 ;
else
return - V_43 ;
F_24 ( V_90 , F_3 ( V_2 ) ) ;
V_20 = F_71 ( V_87 , sizeof( struct V_19 ) , V_95 ) ;
if ( ! V_20 )
return - V_96 ;
V_2 -> V_20 = V_20 ;
V_20 -> V_2 = V_2 ;
V_20 -> V_3 = F_72 ( V_87 , V_89 ) ;
if ( F_68 ( V_20 -> V_3 ) )
return F_69 ( V_20 -> V_3 ) ;
V_20 -> V_73 = F_73 ( V_2 -> V_92 ) ;
if ( ! V_20 -> V_73 ) {
F_74 ( V_87 , L_4 ) ;
return - V_43 ;
}
V_20 -> V_24 . V_87 = V_87 ;
V_20 -> V_24 . V_97 = & V_98 ;
V_20 -> V_24 . V_99 = V_2 -> V_24 . V_57 ;
V_20 -> V_24 . V_31 = - 1 ;
F_75 ( & V_20 -> V_29 ) ;
return F_76 ( & V_20 -> V_24 ) ;
}
static void F_77 ( struct V_100 * V_101 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_20 ( V_24 ) ;
T_2 V_68 , V_102 , V_103 , V_104 , V_105 , V_55 , V_106 , V_107 ;
int V_56 ;
V_68 = F_22 ( F_1 ( V_2 ) ) ;
V_102 = F_22 ( F_4 ( V_2 ) ) ;
V_103 = F_22 ( F_2 ( V_2 ) ) ;
V_104 = F_22 ( F_5 ( V_2 ) ) ;
V_105 = F_22 ( F_6 ( V_2 ) ) ;
V_55 = F_22 ( F_7 ( V_2 ) ) ;
V_106 = F_22 ( F_11 ( V_2 ) ) ;
V_107 = F_22 ( F_14 ( V_2 ) ) ;
for ( V_56 = 0 ; V_56 < V_24 -> V_57 ; V_56 ++ ) {
const char * V_108 ;
T_2 V_109 ;
bool V_110 ;
V_108 = F_78 ( V_24 , V_56 ) ;
if ( ! V_108 )
continue;
V_109 = F_23 ( V_56 ) ;
V_110 = ! ( V_102 & V_109 ) ;
F_79 ( V_101 , L_5 , V_24 -> V_31 + V_56 , V_108 ) ;
if ( V_110 ) {
F_79 ( V_101 , L_6 ,
V_68 & V_109 ? L_7 : L_8 ,
V_103 & V_109 ? L_9 : L_10 ) ;
continue;
}
F_79 ( V_101 , L_11 ,
( V_105 ^ V_104 ) & V_109 ? L_7 : L_8 ,
V_104 & V_109 ? L_8 : L_7 ) ;
if ( ! ( ( V_106 | V_107 ) & V_109 ) ) {
F_80 ( V_101 , L_12 ) ;
continue;
}
if ( V_106 & V_109 )
F_80 ( V_101 , L_13 ) ;
if ( V_107 & V_109 )
F_80 ( V_101 , L_14 ) ;
F_79 ( V_101 , L_15 , V_55 & V_109 ? L_16 : L_17 ) ;
}
}
static int F_81 ( struct V_83 * V_84 , T_4 V_70 )
{
struct V_1 * V_2 = F_82 ( V_84 ) ;
int V_56 ;
V_2 -> V_111 = F_83 ( F_1 ( V_2 ) ) ;
V_2 -> V_112 = F_83 ( F_4 ( V_2 ) ) ;
V_2 -> V_113 = F_83 ( F_2 ( V_2 ) ) ;
V_2 -> V_114 = F_83 ( F_5 ( V_2 ) ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
V_2 -> V_115 [ 0 ] =
F_83 ( V_2 -> V_3 + V_17 ) ;
V_2 -> V_116 [ 0 ] =
F_83 ( V_2 -> V_3 + V_18 ) ;
break;
case V_13 :
for ( V_56 = 0 ; V_56 < 2 ; V_56 ++ ) {
V_2 -> V_115 [ V_56 ] =
F_83 ( V_2 -> V_3 +
F_12 ( V_56 ) ) ;
V_2 -> V_116 [ V_56 ] =
F_83 ( V_2 -> V_3 +
F_15 ( V_56 ) ) ;
}
break;
case V_15 :
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
V_2 -> V_115 [ V_56 ] =
F_83 ( V_2 -> V_3 +
F_13 ( V_56 ) ) ;
V_2 -> V_116 [ V_56 ] =
F_83 ( V_2 -> V_3 +
F_16 ( V_56 ) ) ;
}
break;
default:
F_10 () ;
}
if ( F_84 ( V_117 ) )
F_64 ( V_2 ) ;
return 0 ;
}
static int F_85 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_82 ( V_84 ) ;
int V_56 ;
F_86 ( V_2 -> V_111 , F_1 ( V_2 ) ) ;
F_86 ( V_2 -> V_112 , F_4 ( V_2 ) ) ;
F_86 ( V_2 -> V_113 , F_2 ( V_2 ) ) ;
F_86 ( V_2 -> V_114 , F_5 ( V_2 ) ) ;
switch ( V_2 -> V_11 ) {
case V_12 :
F_86 ( V_2 -> V_115 [ 0 ] ,
V_2 -> V_3 + V_17 ) ;
F_86 ( V_2 -> V_116 [ 0 ] ,
V_2 -> V_3 + V_18 ) ;
break;
case V_13 :
for ( V_56 = 0 ; V_56 < 2 ; V_56 ++ ) {
F_86 ( V_2 -> V_115 [ V_56 ] ,
V_2 -> V_3 + F_12 ( V_56 ) ) ;
F_86 ( V_2 -> V_116 [ V_56 ] ,
V_2 -> V_3 +
F_15 ( V_56 ) ) ;
}
break;
case V_15 :
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
F_86 ( V_2 -> V_115 [ V_56 ] ,
V_2 -> V_3 +
F_13 ( V_56 ) ) ;
F_86 ( V_2 -> V_116 [ V_56 ] ,
V_2 -> V_3 +
F_16 ( V_56 ) ) ;
}
break;
default:
F_10 () ;
}
if ( F_84 ( V_117 ) )
F_65 ( V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_83 * V_84 )
{
struct V_1 * V_2 ;
const struct V_118 * V_119 ;
struct V_120 * V_121 = V_84 -> V_87 . V_91 ;
struct V_88 * V_89 ;
struct V_35 * V_36 ;
struct V_39 * V_40 ;
unsigned int V_122 ;
bool V_123 ;
int V_11 ;
int V_56 , V_10 , V_85 ;
int V_124 ;
V_119 = F_88 ( V_125 , & V_84 -> V_87 ) ;
if ( V_119 )
V_11 = ( unsigned long ) V_119 -> V_126 ;
else
V_11 = V_12 ;
V_123 = F_89 ( V_121 ) != 0 ;
V_2 = F_71 ( & V_84 -> V_87 , sizeof( struct V_1 ) ,
V_95 ) ;
if ( ! V_2 )
return - V_96 ;
F_90 ( V_84 , V_2 ) ;
if ( F_91 ( V_84 -> V_87 . V_91 , L_18 , & V_122 ) ) {
F_74 ( & V_84 -> V_87 , L_19 ) ;
return - V_67 ;
}
V_85 = F_92 ( V_84 -> V_87 . V_91 , L_20 ) ;
if ( V_85 < 0 ) {
F_74 ( & V_84 -> V_87 , L_21 ) ;
return V_85 ;
}
V_2 -> V_92 = F_93 ( & V_84 -> V_87 , NULL ) ;
if ( ! F_68 ( V_2 -> V_92 ) )
F_94 ( V_2 -> V_92 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_24 . V_108 = F_95 ( & V_84 -> V_87 ) ;
V_2 -> V_24 . V_127 = & V_84 -> V_87 ;
V_2 -> V_24 . V_128 = V_129 ;
V_2 -> V_24 . free = V_130 ;
V_2 -> V_24 . V_131 = F_28 ;
V_2 -> V_24 . V_132 = F_26 ;
V_2 -> V_24 . V_133 = F_30 ;
V_2 -> V_24 . V_90 = F_19 ;
if ( V_123 )
V_2 -> V_24 . V_134 = F_32 ;
V_2 -> V_24 . V_31 = V_85 * V_135 ;
V_2 -> V_24 . V_57 = V_122 ;
V_2 -> V_24 . V_136 = false ;
V_2 -> V_24 . V_91 = V_121 ;
V_2 -> V_24 . V_137 = F_77 ;
F_75 ( & V_2 -> V_29 ) ;
V_89 = F_96 ( V_84 , V_93 , 0 ) ;
V_2 -> V_3 = F_72 ( & V_84 -> V_87 , V_89 ) ;
if ( F_68 ( V_2 -> V_3 ) )
return F_69 ( V_2 -> V_3 ) ;
if ( V_11 == V_15 ) {
V_89 = F_96 ( V_84 , V_93 , 1 ) ;
V_2 -> V_16 = F_72 ( & V_84 -> V_87 ,
V_89 ) ;
if ( F_68 ( V_2 -> V_16 ) )
return F_69 ( V_2 -> V_16 ) ;
}
switch ( V_11 ) {
case V_12 :
F_24 ( 0 , V_2 -> V_3 + V_14 ) ;
F_24 ( 0 , V_2 -> V_3 + V_17 ) ;
F_24 ( 0 , V_2 -> V_3 + V_18 ) ;
break;
case V_13 :
F_24 ( 0 , V_2 -> V_3 + V_14 ) ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
F_24 ( 0 , V_2 -> V_3 +
F_12 ( V_10 ) ) ;
F_24 ( 0 , V_2 -> V_3 +
F_15 ( V_10 ) ) ;
}
break;
case V_15 :
F_24 ( 0 , V_2 -> V_3 + V_14 ) ;
F_24 ( 0 , V_2 -> V_3 + V_17 ) ;
F_24 ( 0 , V_2 -> V_3 + V_18 ) ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
F_24 ( 0 , V_2 -> V_16 +
F_9 ( V_10 ) ) ;
F_24 ( 0 , V_2 -> V_16 +
F_13 ( V_10 ) ) ;
F_24 ( 0 , V_2 -> V_16 +
F_16 ( V_10 ) ) ;
}
break;
default:
F_10 () ;
}
F_97 ( & V_84 -> V_87 , & V_2 -> V_24 , V_2 ) ;
if ( ! V_123 )
return 0 ;
V_2 -> V_32 =
F_98 ( V_121 , V_122 , & V_138 , NULL ) ;
if ( ! V_2 -> V_32 ) {
F_74 ( & V_84 -> V_87 , L_22 ,
V_2 -> V_24 . V_108 ) ;
return - V_67 ;
}
V_124 = F_99 (
V_2 -> V_32 , V_122 , 2 , V_121 -> V_139 , V_140 ,
V_141 | V_142 | V_143 , 0 , 0 ) ;
if ( V_124 ) {
F_74 ( & V_84 -> V_87 , L_23 ,
V_2 -> V_24 . V_108 ) ;
goto V_144;
}
V_36 = F_100 ( V_2 -> V_32 , 0 ) ;
V_36 -> V_37 = V_2 ;
V_40 = & V_36 -> V_145 [ 0 ] ;
V_40 -> type = V_47 | V_49 ;
V_40 -> V_24 . V_146 = F_41 ;
V_40 -> V_24 . V_147 = F_42 ;
V_40 -> V_24 . V_148 = F_43 ;
V_40 -> V_24 . V_139 = V_2 -> V_24 . V_108 ;
V_40 = & V_36 -> V_145 [ 1 ] ;
V_40 -> type = V_46 | V_48 ;
V_40 -> V_24 . V_149 = F_34 ;
V_40 -> V_24 . V_146 = F_38 ;
V_40 -> V_24 . V_147 = F_40 ;
V_40 -> V_24 . V_148 = F_43 ;
V_40 -> V_150 = V_151 ;
V_40 -> V_24 . V_139 = V_2 -> V_24 . V_108 ;
for ( V_56 = 0 ; V_56 < 4 ; V_56 ++ ) {
int V_58 = F_101 ( V_84 , V_56 ) ;
if ( V_58 < 0 )
continue;
F_102 ( V_58 , F_45 ,
V_2 ) ;
}
if ( F_84 ( V_117 ) )
return F_66 ( V_84 , V_2 , V_85 ) ;
return 0 ;
V_144:
F_103 ( V_2 -> V_32 ) ;
return V_124 ;
}
