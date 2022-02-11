static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_4 L_1 ,
V_2 -> V_5 , V_2 -> V_6 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 ++ ) {
F_2 ( V_4 L_2 ,
V_3 + 1 , ( ( V_7 * ) V_2 -> V_5 ) [ V_3 ] ) ;
F_2 ( V_4 L_3 ,
V_3 + 1 , ( ( V_7 * ) V_2 -> V_6 ) [ V_3 ] ) ;
}
}
static void F_3 ( V_7 * V_8 , int V_9 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < ( V_9 + 3 ) / 4 ; V_3 ++ ) {
if ( V_3 % 4 == 0 )
F_2 ( V_4 L_4 , V_3 * 4 ) ;
F_2 ( V_4 L_5 , * ( V_8 + V_3 ) ) ;
}
F_2 ( V_4 L_6 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 100 ; V_3 ++ )
if ( F_5 ( & V_2 -> V_5 -> V_10 ) & V_11 )
return 1 ;
else
F_6 () ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( F_5 ( & V_2 -> V_5 -> V_12 ) | V_13 ,
& V_2 -> V_5 -> V_12 ) ;
F_9 ( 5 ) ;
F_8 ( F_5 ( & V_2 -> V_5 -> V_12 ) & ~ V_13 ,
& V_2 -> V_5 -> V_12 ) ;
F_9 ( 5 ) ;
}
static void F_10 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
int V_16 ;
V_7 V_17 ;
F_12 ( ! V_2 ) ;
V_16 = V_15 -> V_18 - V_2 -> V_19 ;
V_17 = F_5 ( & V_2 -> V_6 -> V_20 [ V_16 >> 2 ] ) ;
V_17 |= ( V_21 | V_16 ) << F_13 ( V_16 ) ;
F_8 ( V_17 , & V_2 -> V_6 -> V_20 [ V_16 >> 2 ] ) ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
int V_16 ;
V_7 V_17 ;
F_12 ( ! V_2 ) ;
V_16 = V_15 -> V_18 - V_2 -> V_19 ;
V_17 = F_5 ( & V_2 -> V_6 -> V_20 [ V_16 >> 2 ] ) ;
V_17 &= ~ ( V_21 << F_13 ( V_16 ) ) ;
F_8 ( V_17 , & V_2 -> V_6 -> V_20 [ V_16 >> 2 ] ) ;
}
static int F_15 ( struct V_14 * V_15 , unsigned int V_22 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
int V_16 ;
V_7 V_17 ;
F_12 ( ! V_2 ) ;
V_16 = V_15 -> V_18 - V_2 -> V_19 ;
V_17 = F_5 ( & V_2 -> V_6 -> V_20 [ V_16 >> 2 ] ) ;
switch ( V_22 & V_23 ) {
case V_24 :
case V_25 :
case V_26 :
V_17 |= V_27 << F_13 ( V_16 ) ;
V_17 &= ~ ( V_28 << F_13 ( V_16 ) ) ;
break;
case V_29 :
V_17 &= ~ ( V_27 << F_13 ( V_16 ) ) ;
V_17 &= ~ ( V_28 << F_13 ( V_16 ) ) ;
break;
case V_30 :
V_17 &= ~ ( V_27 << F_13 ( V_16 ) ) ;
V_17 |= V_28 << F_13 ( V_16 ) ;
break;
default:
return - V_31 ;
}
F_8 ( V_17 , & V_2 -> V_6 -> V_20 [ V_16 >> 2 ] ) ;
return 0 ;
}
static void F_16 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
V_7 V_10 = F_5 ( & V_2 -> V_5 -> V_10 ) ;
F_17 ( L_7 ,
F_18 ( & V_2 -> V_2 ) , V_10 ) ;
F_8 ( V_10 , & V_2 -> V_5 -> V_10 ) ;
}
static void F_19 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
V_7 V_10 = F_5 ( & V_2 -> V_6 -> V_10 ) ;
F_17 ( L_8 ,
F_18 ( & V_2 -> V_2 ) , V_10 ) ;
F_8 ( V_10 , & V_2 -> V_6 -> V_10 ) ;
}
static T_1 F_20 ( int V_18 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
V_7 V_10 ;
int V_16 = 0 ;
V_10 = F_5 ( & V_2 -> V_5 -> V_33 ) ;
F_8 ( V_10 , & V_2 -> V_5 -> V_33 ) ;
if ( F_21 ( ! V_10 ) )
F_22 () ;
while ( V_10 ) {
if ( V_10 & 1 )
F_23 ( V_2 -> V_19 + V_16 ) ;
V_10 >>= 1 ;
V_16 ++ ;
}
return V_34 ;
}
static int F_24 ( struct V_1 * V_2 )
{
V_7 V_17 ;
int V_3 , V_16 ;
if ( V_2 -> V_35 == V_2 -> V_36 ) {
F_2 ( V_37
L_9 ,
F_18 ( & V_2 -> V_2 ) ) ;
return - V_31 ;
}
F_8 ( F_5 ( & V_2 -> V_5 -> V_10 ) , & V_2 -> V_5 -> V_10 ) ;
F_8 ( F_5 ( & V_2 -> V_6 -> V_10 ) , & V_2 -> V_6 -> V_10 ) ;
V_17 = F_25 ( V_2 -> V_35 ) ;
V_17 |= V_38 | V_39 |
V_40 ;
V_17 |= F_5 ( & V_2 -> V_5 -> V_12 ) ;
F_8 ( V_41 , & V_2 -> V_5 -> V_42 ) ;
F_8 ( V_17 , & V_2 -> V_5 -> V_12 ) ;
V_17 = F_25 ( V_2 -> V_36 ) ;
V_17 |= V_38 ;
V_17 |= F_5 ( & V_2 -> V_6 -> V_12 ) ;
F_8 ( V_41 , & V_2 -> V_6 -> V_42 ) ;
F_8 ( V_17 , & V_2 -> V_6 -> V_42 ) ;
F_8 ( V_17 , & V_2 -> V_6 -> V_12 ) ;
for ( V_3 = V_2 -> V_19 ; V_3 <= V_2 -> V_43 ; V_3 ++ ) {
V_16 = V_3 - V_2 -> V_19 ;
if ( V_16 == V_2 -> V_35 ) {
F_26 ( V_3 , & V_44 ,
V_45 ) ;
F_27 ( V_3 , V_2 ) ;
} else if ( V_16 == V_2 -> V_36 ) {
F_26 ( V_3 , & V_46 ,
V_45 ) ;
F_27 ( V_3 , V_2 ) ;
} else {
F_26 ( V_3 , & V_47 ,
V_48 ) ;
F_27 ( V_3 , V_2 ) ;
F_8 ( 0 , & V_2 -> V_6 -> V_20 [ V_16 >> 2 ] ) ;
}
}
if ( F_28 ( V_2 -> V_18 , F_20 , V_49 , L_10 , V_2 ) ) {
F_2 ( V_37 L_11 ,
F_18 ( & V_2 -> V_2 ) ) ;
return - V_50 ;
}
return 0 ;
}
static void F_29 ( struct V_51 * V_2 )
{
struct V_1 * V_52 = F_30 ( V_2 ) ;
F_31 ( V_52 ) ;
}
static int F_32 ( struct V_51 * V_2 ,
struct V_53 * V_54 )
{
struct V_1 * V_52 = F_30 ( V_2 ) ;
struct V_55 * V_56 = F_33 ( V_54 ) ;
struct V_57 * V_58 = V_56 -> V_59 ;
while ( V_58 -> V_60 ) {
if ( V_58 -> V_60 == V_52 -> V_32 ) {
V_52 -> V_61 = V_58 -> V_61 ;
F_34 ( V_52 , V_58 ) ;
F_2 ( V_62 L_12
L_13 , V_52 -> V_32 ) ;
return 1 ;
}
F_2 ( V_4 L_14
L_15 , V_58 -> V_60 , V_52 -> V_32 ) ;
V_58 ++ ;
}
return 0 ;
}
static int F_35 ( struct V_51 * V_2 )
{
struct V_1 * V_52 = F_30 ( V_2 ) ;
struct V_55 * V_54 = F_33 ( V_2 -> V_63 ) ;
struct V_57 * V_60 = F_36 ( V_52 ) ;
int V_64 = - V_65 ;
if ( V_54 -> V_66 )
V_64 = V_54 -> V_66 ( V_52 , V_60 ) ;
if ( V_64 )
F_37 ( V_2 ) ;
return V_64 ;
}
static int F_38 ( struct V_51 * V_2 )
{
struct V_55 * V_54 = F_33 ( V_2 -> V_63 ) ;
if ( V_54 -> remove )
V_54 -> remove ( F_30 ( V_2 ) ) ;
return 0 ;
}
int F_39 ( struct V_55 * V_63 , struct V_67 * V_68 )
{
V_63 -> V_63 . V_69 = V_63 -> V_69 ;
V_63 -> V_63 . V_70 = & V_71 ;
return F_40 ( & V_63 -> V_63 ) ;
}
void F_41 ( struct V_55 * V_63 )
{
F_42 ( & V_63 -> V_63 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_3 ;
F_7 ( V_2 ) ;
for ( V_3 = V_2 -> V_32 ? V_72 : V_73 ; V_2 -> V_32 ?
V_3 <= V_73 : V_3 >= V_72 ;
V_2 -> V_32 ? V_3 ++ : V_3 -- ) {
if ( ! F_4 ( V_2 ) )
break;
F_8 ( ( F_5 ( & V_2 -> V_6 -> V_12 ) &
~ V_74 ) |
V_75 |
F_44 ( V_3 - V_76 ) ,
& V_2 -> V_6 -> V_12 ) ;
F_8 ( ( F_5 ( & V_2 -> V_5 -> V_12 )
& ~ ( V_75 |
V_74 ) ) |
F_44 ( V_3 - V_76 ) ,
& V_2 -> V_5 -> V_12 ) ;
if ( F_4 ( V_2 ) ) {
F_2 ( V_4
L_16 ,
F_18 ( & V_2 -> V_2 ) , V_3 - V_76 + 1 ) ;
V_2 -> V_61 = V_3 ;
return 0 ;
} else {
F_7 ( V_2 ) ;
}
}
return - V_65 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_3 ;
F_7 ( V_2 ) ;
for ( V_3 = V_2 -> V_32 ? V_77 : V_78 ; V_2 -> V_32 ?
V_3 <= V_78 : V_3 >= V_77 ;
V_2 -> V_32 ? V_3 ++ : V_3 -- ) {
F_8 ( ( F_5 ( & V_2 -> V_5 -> V_12 ) &
~ V_74 ) |
V_75 |
F_44 ( V_3 - V_79 ) ,
& V_2 -> V_5 -> V_12 ) ;
if ( F_4 ( V_2 ) ) {
F_2 ( V_4
L_17 ,
F_18 ( & V_2 -> V_2 ) , V_3 - V_79 + 1 ) ;
V_2 -> V_61 = V_3 ;
return 0 ;
} else {
F_7 ( V_2 ) ;
}
}
return - V_65 ;
}
static int F_46 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
if ( ! F_4 ( V_2 ) )
return - V_65 ;
F_8 ( ( F_5 ( & V_2 -> V_6 -> V_12 ) &
~ V_75 ) ,
& V_2 -> V_6 -> V_12 ) ;
F_8 ( ( F_5 ( & V_2 -> V_5 -> V_12 ) &
~ V_75 ) ,
& V_2 -> V_5 -> V_12 ) ;
if ( F_4 ( V_2 ) ) {
F_2 ( V_4 L_18 ,
F_18 ( & V_2 -> V_2 ) ) ;
V_2 -> V_61 = V_80 ;
return 0 ;
}
return - V_65 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_64 ;
struct V_81 * V_82 = V_2 -> V_2 . V_83 ;
V_64 = V_82 -> V_84 ( V_2 ) ;
if ( V_64 )
return V_64 ;
switch ( V_2 -> V_61 ) {
case V_80 :
case V_85 :
if ( F_4 ( V_2 ) && F_5 ( & V_2 -> V_6 -> V_12 ) &
V_75 ) {
if ( ! F_43 ( V_2 ) ||
! F_45 ( V_2 ) ||
! F_46 ( V_2 ) )
return 0 ;
} else {
if ( ! F_46 ( V_2 ) ||
! F_45 ( V_2 ) ||
! F_43 ( V_2 ) )
return 0 ;
}
break;
case V_79 :
case V_77 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_78 :
F_8 ( V_75 |
F_44 ( V_2 -> V_61 -
V_79 ) , & V_2 -> V_5 -> V_12 ) ;
F_8 ( 0 , & V_2 -> V_6 -> V_12 ) ;
if ( F_4 ( V_2 ) ) {
F_2 ( V_4
L_17 ,
F_18 ( & V_2 -> V_2 ) ,
V_2 -> V_61 - V_79 + 1 ) ;
return 0 ;
}
break;
case V_76 :
case V_72 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_73 :
F_8 ( 0 , & V_2 -> V_5 -> V_12 ) ;
F_8 ( V_75 |
F_44 ( V_2 -> V_61 -
V_76 ) , & V_2 -> V_6 -> V_12 ) ;
if ( F_4 ( V_2 ) ) {
F_2 ( V_4
L_16 ,
F_18 ( & V_2 -> V_2 ) ,
V_2 -> V_61 - V_76 + 1 ) ;
return 0 ;
}
break;
}
V_82 -> V_96 ( V_2 ) ;
return - V_65 ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = V_2 -> V_2 . V_83 ;
int V_64 = - V_65 ;
V_64 = F_47 ( V_2 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_24 ( V_2 ) ;
if ( V_64 )
V_82 -> V_96 ( V_2 ) ;
V_2 -> V_97 = ! V_64 ;
return V_64 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = V_2 -> V_2 . V_83 ;
V_2 -> V_97 = 0 ;
F_50 ( V_2 -> V_18 , V_2 ) ;
V_82 -> V_96 ( V_2 ) ;
}
int F_51 ( struct V_1 * V_2 , V_7 V_98 ,
struct V_99 * V_100 )
{
int V_3 ;
if ( ! V_2 -> V_97 )
return - V_101 ;
F_8 ( V_98 , & V_2 -> V_5 -> V_98 ) ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
F_8 ( V_100 [ V_3 ] . V_102 , & V_2 -> V_5 -> V_103 [ V_3 ] . V_102 ) ;
F_8 ( V_100 [ V_3 ] . V_104 , & V_2 -> V_5 -> V_103 [ V_3 ] . V_104 ) ;
}
return 0 ;
}
int F_52 ( struct V_1 * V_2 , V_7 V_98 ,
struct V_99 * V_100 )
{
int V_3 ;
if ( ! V_2 -> V_97 )
return - V_101 ;
F_8 ( V_98 , & V_2 -> V_6 -> V_98 ) ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
F_8 ( V_100 [ V_3 ] . V_102 , & V_2 -> V_6 -> V_103 [ V_3 ] . V_102 ) ;
F_8 ( V_100 [ V_3 ] . V_104 , & V_2 -> V_6 -> V_103 [ V_3 ] . V_104 ) ;
}
return 0 ;
}
int F_53 ( struct V_1 * V_2 , int V_16 )
{
int V_18 = V_2 -> V_19 + V_16 ;
if ( V_2 -> V_97 )
return - V_105 ;
if ( ( V_18 < V_2 -> V_19 ) || ( V_18 > V_2 -> V_43 ) )
return - V_31 ;
if ( V_16 == V_2 -> V_36 )
return - V_31 ;
V_2 -> V_35 = V_16 ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , int V_16 )
{
int V_18 = V_2 -> V_19 + V_16 ;
if ( V_2 -> V_97 )
return - V_105 ;
if ( ( V_18 < V_2 -> V_19 ) || ( V_18 > V_2 -> V_43 ) )
return - V_31 ;
if ( V_16 == V_2 -> V_35 )
return - V_31 ;
V_2 -> V_36 = V_16 ;
return 0 ;
}
static int F_55 ( struct V_106 * V_107 )
{
struct V_1 * V_2 ;
struct V_108 * V_109 , * V_110 , * V_111 ;
int V_112 , V_64 ;
V_109 = F_56 ( V_107 , V_113 , L_19 ) ;
if ( ! V_109 )
return - V_65 ;
V_110 = F_56 ( V_107 , V_113 , L_20 ) ;
if ( ! V_110 )
return - V_65 ;
V_111 = F_56 ( V_107 , V_114 , L_21 ) ;
if ( ! V_111 )
return - V_65 ;
V_2 = F_57 ( sizeof( * V_2 ) , V_115 ) ;
if ( ! V_2 ) {
F_2 ( V_37
L_22 ) ;
return - V_116 ;
}
V_2 -> V_60 = V_107 -> V_60 ;
V_2 -> V_2 . V_70 = & V_71 ;
V_2 -> V_2 . V_117 = & V_107 -> V_2 ;
F_58 ( & V_2 -> V_2 , L_23 , V_2 -> V_60 ) ;
V_2 -> V_2 . V_83 = V_107 -> V_2 . V_83 ;
V_2 -> V_2 . V_118 = F_29 ;
V_2 -> V_119 = V_109 -> V_120 ;
V_2 -> V_121 = V_109 -> V_122 ;
V_2 -> V_123 = V_110 -> V_120 ;
V_2 -> V_124 = V_110 -> V_122 ;
V_112 = F_59 ( V_109 ) ;
if ( ! F_60 ( V_109 -> V_120 , V_112 , F_18 ( & V_2 -> V_2 ) ) ) {
F_2 ( V_37 L_24 ,
F_18 ( & V_2 -> V_2 ) ) ;
V_64 = - V_101 ;
goto V_125;
}
V_2 -> V_5 = F_61 ( V_109 -> V_120 , V_112 ) ;
if ( ! V_2 -> V_5 ) {
F_2 ( V_37 L_25 ,
F_18 ( & V_2 -> V_2 ) ) ;
V_64 = - V_101 ;
goto V_126;
}
V_2 -> V_6 = (struct V_127 * ) ( ( void * ) V_2 -> V_5 +
V_128 ) ;
V_2 -> V_18 = F_62 ( V_107 , L_26 ) ;
V_2 -> V_19 = V_111 -> V_120 ;
V_2 -> V_43 = V_111 -> V_122 ;
V_2 -> V_35 = V_2 -> V_43 - V_2 -> V_19 ;
V_2 -> V_36 = V_2 -> V_35 - 1 ;
if ( F_63 ( & V_2 -> V_2 ) )
goto V_129;
F_64 ( V_107 , V_2 ) ;
F_2 ( V_62 L_27 ,
F_18 ( & V_2 -> V_2 ) , ( void * ) V_2 -> V_119 , V_2 -> V_18 ,
( void * ) V_2 -> V_123 ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_61 = V_85 ;
V_64 = F_47 ( V_2 ) ;
if ( V_64 == 0 ) {
V_2 -> V_32 = F_5 ( & V_2 -> V_6 -> V_130 ) ;
( (struct V_81 * ) ( V_2 -> V_2 . V_83 ) ) -> V_96 ( V_2 ) ;
}
if ( V_2 -> V_32 )
F_2 ( V_62 L_28 , V_2 -> V_32 ) ;
return 0 ;
V_129:
F_65 ( V_2 -> V_5 ) ;
V_126:
V_125:
F_66 ( V_109 -> V_120 , V_112 ) ;
F_31 ( V_2 ) ;
return V_64 ;
}
static int F_67 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = F_68 ( V_107 ) ;
F_69 ( & V_2 -> V_2 ) ;
F_65 ( V_2 -> V_5 ) ;
F_66 ( V_2 -> V_119 , V_2 -> V_121 - V_2 -> V_119 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
static int F_70 ( void )
{
int V_131 = 0 ;
V_131 = F_71 ( & V_71 ) ;
if ( V_131 )
goto V_132;
V_131 = F_72 ( & V_133 ) ;
if ( V_131 )
goto V_134;
return 0 ;
V_134:
F_73 ( & V_71 ) ;
V_132:
return V_131 ;
}
static void F_74 ( void )
{
F_75 ( & V_133 ) ;
F_73 ( & V_71 ) ;
}
