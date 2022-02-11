static inline int F_1 ( struct V_1 * V_2 )
{
int V_3 = ( V_2 -> V_4 & V_5 ) - ( V_2 -> V_6 + 8 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_7 ;
return V_3 ;
}
static T_1 F_2 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
T_1 V_12 ;
V_12 = V_10 -> V_13 ;
if ( ++ V_10 -> V_13 == 0 )
V_10 -> V_13 = 1 ;
return V_12 ;
}
static int
F_3 ( struct V_1 * V_2 ,
T_1 V_14 ,
T_1 V_15 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_16 ;
int V_17 ;
V_16 = V_18 | V_19 ;
if ( ( V_14 | V_15 ) &
V_20 )
V_16 &= ~ V_19 ;
if ( F_4 ( V_9 ) -> V_21 < 4 ) {
if ( V_14 & V_22 )
V_16 |= V_23 ;
}
if ( V_14 & V_24 )
V_16 |= V_25 ;
if ( V_14 & V_26 &&
( F_5 ( V_9 ) || F_6 ( V_9 ) ) )
V_16 |= V_27 ;
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_16 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 V_29 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
F_11 ( V_2 , V_29 ) ;
}
T_1 F_12 ( struct V_1 * V_2 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
T_1 V_30 = F_4 ( V_2 -> V_9 ) -> V_21 >= 4 ?
F_13 ( V_2 -> V_31 ) : V_32 ;
return F_14 ( V_30 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
struct V_33 * V_34 = V_2 -> V_34 ;
T_1 V_4 ;
F_16 ( V_2 , 0 ) ;
F_17 ( V_2 , 0 ) ;
V_2 -> V_35 ( V_2 , 0 ) ;
F_18 ( V_2 , V_34 -> V_36 ) ;
V_4 = F_19 ( V_2 ) & V_5 ;
if ( V_4 != 0 ) {
F_20 ( L_1
L_2 ,
V_2 -> V_37 ,
F_21 ( V_2 ) ,
F_19 ( V_2 ) ,
F_22 ( V_2 ) ,
F_23 ( V_2 ) ) ;
F_17 ( V_2 , 0 ) ;
if ( F_19 ( V_2 ) & V_5 ) {
F_24 ( L_3
L_2 ,
V_2 -> V_37 ,
F_21 ( V_2 ) ,
F_19 ( V_2 ) ,
F_22 ( V_2 ) ,
F_23 ( V_2 ) ) ;
}
}
F_16 ( V_2 ,
( ( V_2 -> V_7 - V_38 ) & V_39 )
| V_40 | V_41 ) ;
if ( ( F_21 ( V_2 ) & V_41 ) == 0 ||
F_23 ( V_2 ) != V_34 -> V_36 ||
( F_19 ( V_2 ) & V_5 ) != 0 ) {
F_24 ( L_4
L_2 ,
V_2 -> V_37 ,
F_21 ( V_2 ) ,
F_19 ( V_2 ) ,
F_22 ( V_2 ) ,
F_23 ( V_2 ) ) ;
return - V_42 ;
}
if ( ! F_25 ( V_2 -> V_9 , V_43 ) )
F_26 ( V_2 -> V_9 ) ;
else {
V_2 -> V_4 = F_19 ( V_2 ) ;
V_2 -> V_6 = F_22 ( V_2 ) & V_44 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
}
return 0 ;
}
static int
F_27 ( struct V_1 * V_2 )
{
struct V_45 * V_46 ;
struct V_33 * V_34 ;
int V_17 ;
if ( V_2 -> V_47 )
return 0 ;
V_46 = F_28 ( sizeof( * V_46 ) , V_48 ) ;
if ( ! V_46 )
return - V_49 ;
V_34 = F_29 ( V_2 -> V_9 , 4096 ) ;
if ( V_34 == NULL ) {
F_24 ( L_5 ) ;
V_17 = - V_49 ;
goto V_50;
}
V_34 -> V_51 = V_52 ;
V_17 = F_30 ( V_34 , 4096 , true ) ;
if ( V_17 )
goto V_53;
V_46 -> V_36 = V_34 -> V_36 ;
V_46 -> V_54 = F_31 ( V_34 -> V_55 [ 0 ] ) ;
if ( V_46 -> V_54 == NULL )
goto V_56;
V_46 -> V_34 = V_34 ;
V_2 -> V_47 = V_46 ;
return 0 ;
V_56:
F_32 ( V_34 ) ;
V_53:
F_33 ( & V_34 -> V_57 ) ;
V_50:
F_34 ( V_46 ) ;
return V_17 ;
}
static void
F_35 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_47 ;
struct V_33 * V_34 ;
if ( ! V_2 -> V_47 )
return;
V_34 = V_46 -> V_34 ;
F_36 ( V_34 -> V_55 [ 0 ] ) ;
F_32 ( V_34 ) ;
F_33 ( & V_34 -> V_57 ) ;
F_34 ( V_46 ) ;
V_2 -> V_47 = NULL ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_58 * V_10 = V_9 -> V_11 ;
int V_17 = F_15 ( V_2 ) ;
if ( F_4 ( V_9 ) -> V_21 > 3 ) {
int V_59 = V_60 << 16 | V_60 ;
if ( F_38 ( V_9 ) || F_39 ( V_9 ) )
V_59 |= V_61 << 16 | V_61 ;
F_40 ( V_62 , V_59 ) ;
}
if ( F_4 ( V_9 ) -> V_21 >= 6 ) {
} else if ( F_6 ( V_9 ) ) {
V_17 = F_27 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
return V_17 ;
}
static void F_41 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_47 )
return;
F_35 ( V_2 ) ;
}
static void
F_42 ( struct V_1 * V_2 , int V_63 , T_1 V_12 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_58 * V_10 = V_9 -> V_11 ;
int V_64 ;
V_64 = V_2 - V_10 -> V_2 ;
V_64 += 2 - V_63 ;
V_64 %= 3 ;
F_8 ( V_2 ,
V_65 |
V_66 |
V_67 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 ,
F_43 ( V_10 -> V_2 [ V_64 ] . V_31 ) + 4 * V_63 ) ;
}
static int
F_44 ( struct V_1 * V_2 ,
T_1 * V_68 )
{
T_1 V_12 ;
int V_17 ;
V_17 = F_7 ( V_2 , 10 ) ;
if ( V_17 )
return V_17 ;
V_12 = F_2 ( V_2 -> V_9 ) ;
F_42 ( V_2 , 0 , V_12 ) ;
F_42 ( V_2 , 1 , V_12 ) ;
F_8 ( V_2 , V_69 ) ;
F_8 ( V_2 , V_70 << V_71 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_72 ) ;
F_9 ( V_2 ) ;
* V_68 = V_12 ;
return 0 ;
}
int
F_45 ( struct V_1 * V_2 ,
struct V_1 * V_73 ,
T_1 V_12 )
{
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 ,
V_65 |
V_66 |
F_46 ( V_2 , V_73 ) << 17 |
V_74 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_47 ( struct V_1 * V_2 ,
T_1 * V_68 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_12 = F_2 ( V_9 ) ;
struct V_45 * V_46 = V_2 -> V_47 ;
T_1 V_75 = V_46 -> V_36 + 128 ;
int V_17 ;
V_17 = F_7 ( V_2 , 32 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_76 | V_77 |
V_78 | V_79 ) ;
F_8 ( V_2 , V_46 -> V_36 | V_80 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , 0 ) ;
F_48 ( V_2 , V_75 ) ;
V_75 += 128 ;
F_48 ( V_2 , V_75 ) ;
V_75 += 128 ;
F_48 ( V_2 , V_75 ) ;
V_75 += 128 ;
F_48 ( V_2 , V_75 ) ;
V_75 += 128 ;
F_48 ( V_2 , V_75 ) ;
V_75 += 128 ;
F_48 ( V_2 , V_75 ) ;
F_8 ( V_2 , V_76 | V_77 |
V_78 | V_79 |
V_81 ) ;
F_8 ( V_2 , V_46 -> V_36 | V_80 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , 0 ) ;
F_9 ( V_2 ) ;
* V_68 = V_12 ;
return 0 ;
}
static int
F_49 ( struct V_1 * V_2 ,
T_1 * V_68 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_12 = F_2 ( V_9 ) ;
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_69 ) ;
F_8 ( V_2 , V_70 << V_71 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_72 ) ;
F_9 ( V_2 ) ;
* V_68 = V_12 ;
return 0 ;
}
static T_1
F_50 ( struct V_1 * V_2 )
{
return F_51 ( V_2 , V_70 ) ;
}
static T_1
F_52 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_47 ;
return V_46 -> V_54 [ 0 ] ;
}
static void
F_53 ( T_2 * V_10 , T_1 V_82 )
{
V_10 -> V_83 &= ~ V_82 ;
F_40 ( V_84 , V_10 -> V_83 ) ;
F_54 ( V_84 ) ;
}
static void
F_55 ( T_2 * V_10 , T_1 V_82 )
{
V_10 -> V_83 |= V_82 ;
F_40 ( V_84 , V_10 -> V_83 ) ;
F_54 ( V_84 ) ;
}
static void
F_56 ( T_2 * V_10 , T_1 V_82 )
{
V_10 -> V_85 &= ~ V_82 ;
F_40 ( V_86 , V_10 -> V_85 ) ;
F_54 ( V_86 ) ;
}
static void
F_57 ( T_2 * V_10 , T_1 V_82 )
{
V_10 -> V_85 |= V_82 ;
F_40 ( V_86 , V_10 -> V_85 ) ;
F_54 ( V_86 ) ;
}
static bool
F_58 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
if ( ! V_9 -> V_87 )
return false ;
F_59 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_89 ++ == 0 ) {
if ( F_60 ( V_9 ) )
F_53 ( V_10 ,
V_90 | V_91 ) ;
else
F_56 ( V_10 , V_92 ) ;
}
F_61 ( & V_2 -> V_88 ) ;
return true ;
}
static void
F_62 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
F_59 ( & V_2 -> V_88 ) ;
if ( -- V_2 -> V_89 == 0 ) {
if ( F_60 ( V_9 ) )
F_55 ( V_10 ,
V_91 |
V_90 ) ;
else
F_57 ( V_10 , V_92 ) ;
}
F_61 ( & V_2 -> V_88 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
T_1 V_93 = 0 ;
if ( F_39 ( V_9 ) ) {
switch ( V_2 -> V_64 ) {
case V_94 :
V_93 = V_95 ;
break;
case V_96 :
V_93 = V_97 ;
break;
case V_98 :
V_93 = V_99 ;
break;
}
} else if ( F_38 ( V_2 -> V_9 ) ) {
V_93 = F_64 ( V_2 -> V_31 ) ;
} else {
V_93 = F_65 ( V_2 -> V_31 ) ;
}
F_40 ( V_93 , ( T_1 ) V_2 -> V_100 . V_101 ) ;
F_54 ( V_93 ) ;
}
static int
F_66 ( struct V_1 * V_2 ,
T_1 V_14 ,
T_1 V_15 )
{
int V_17 ;
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_18 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_67 ( struct V_1 * V_2 ,
T_1 * V_68 )
{
T_1 V_12 ;
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_12 = F_2 ( V_2 -> V_9 ) ;
F_8 ( V_2 , V_69 ) ;
F_8 ( V_2 , V_70 << V_71 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_72 ) ;
F_9 ( V_2 ) ;
* V_68 = V_12 ;
return 0 ;
}
static bool
F_68 ( struct V_1 * V_2 , T_1 V_102 , T_1 V_103 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
if ( ! V_9 -> V_87 )
return false ;
F_59 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_89 ++ == 0 ) {
V_2 -> V_85 &= ~ V_103 ;
F_69 ( V_2 , V_2 -> V_85 ) ;
F_53 ( V_10 , V_102 ) ;
}
F_61 ( & V_2 -> V_88 ) ;
return true ;
}
static void
F_70 ( struct V_1 * V_2 , T_1 V_102 , T_1 V_103 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
F_59 ( & V_2 -> V_88 ) ;
if ( -- V_2 -> V_89 == 0 ) {
V_2 -> V_85 |= V_103 ;
F_69 ( V_2 , V_2 -> V_85 ) ;
F_55 ( V_10 , V_102 ) ;
}
F_61 ( & V_2 -> V_88 ) ;
}
static bool
F_71 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
if ( ! V_9 -> V_87 )
return false ;
F_59 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_89 ++ == 0 ) {
if ( F_5 ( V_9 ) )
F_56 ( V_10 , V_104 ) ;
else
F_53 ( V_10 , V_105 ) ;
}
F_61 ( & V_2 -> V_88 ) ;
return true ;
}
static void
F_72 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
F_59 ( & V_2 -> V_88 ) ;
if ( -- V_2 -> V_89 == 0 ) {
if ( F_5 ( V_9 ) )
F_57 ( V_10 , V_104 ) ;
else
F_55 ( V_10 , V_105 ) ;
}
F_61 ( & V_2 -> V_88 ) ;
}
static int
F_73 ( struct V_1 * V_2 , T_1 V_106 , T_1 V_107 )
{
int V_17 ;
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 ,
V_108 | ( 2 << 6 ) |
V_109 ) ;
F_8 ( V_2 , V_106 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_74 ( struct V_1 * V_2 ,
T_1 V_106 , T_1 V_110 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_17 ;
if ( F_75 ( V_9 ) || F_76 ( V_9 ) ) {
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_111 ) ;
F_8 ( V_2 , V_106 | V_112 ) ;
F_8 ( V_2 , V_106 + V_110 - 8 ) ;
F_8 ( V_2 , 0 ) ;
} else {
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
if ( F_4 ( V_9 ) -> V_21 >= 4 ) {
F_8 ( V_2 ,
V_108 | ( 2 << 6 ) |
V_109 ) ;
F_8 ( V_2 , V_106 ) ;
} else {
F_8 ( V_2 ,
V_108 | ( 2 << 6 ) ) ;
F_8 ( V_2 , V_106 | V_112 ) ;
}
}
F_9 ( V_2 ) ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
struct V_33 * V_34 ;
V_34 = V_2 -> V_100 . V_34 ;
if ( V_34 == NULL )
return;
F_36 ( V_34 -> V_55 [ 0 ] ) ;
F_32 ( V_34 ) ;
F_33 ( & V_34 -> V_57 ) ;
V_2 -> V_100 . V_34 = NULL ;
memset ( & V_10 -> V_113 , 0 , sizeof( V_10 -> V_113 ) ) ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
struct V_33 * V_34 ;
int V_17 ;
V_34 = F_29 ( V_9 , 4096 ) ;
if ( V_34 == NULL ) {
F_24 ( L_6 ) ;
V_17 = - V_49 ;
goto V_50;
}
V_34 -> V_51 = V_52 ;
V_17 = F_30 ( V_34 , 4096 , true ) ;
if ( V_17 != 0 ) {
goto V_53;
}
V_2 -> V_100 . V_101 = V_34 -> V_36 ;
V_2 -> V_100 . V_114 = F_31 ( V_34 -> V_55 [ 0 ] ) ;
if ( V_2 -> V_100 . V_114 == NULL ) {
memset ( & V_10 -> V_113 , 0 , sizeof( V_10 -> V_113 ) ) ;
goto V_56;
}
V_2 -> V_100 . V_34 = V_34 ;
memset ( V_2 -> V_100 . V_114 , 0 , V_38 ) ;
F_63 ( V_2 ) ;
F_79 ( L_7 ,
V_2 -> V_37 , V_2 -> V_100 . V_101 ) ;
return 0 ;
V_56:
F_32 ( V_34 ) ;
V_53:
F_33 ( & V_34 -> V_57 ) ;
V_50:
return V_17 ;
}
int F_80 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_33 * V_34 ;
int V_17 ;
V_2 -> V_9 = V_9 ;
F_81 ( & V_2 -> V_115 ) ;
F_81 ( & V_2 -> V_116 ) ;
F_81 ( & V_2 -> V_117 ) ;
F_82 ( & V_2 -> V_118 ) ;
F_83 ( & V_2 -> V_88 ) ;
V_2 -> V_85 = ~ 0 ;
if ( F_84 ( V_9 ) ) {
V_17 = F_78 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
V_34 = F_29 ( V_9 , V_2 -> V_7 ) ;
if ( V_34 == NULL ) {
F_24 ( L_8 ) ;
V_17 = - V_49 ;
goto V_119;
}
V_2 -> V_34 = V_34 ;
V_17 = F_30 ( V_34 , V_38 , true ) ;
if ( V_17 )
goto V_53;
V_2 -> V_120 . V_7 = V_2 -> V_7 ;
V_2 -> V_120 . V_106 = V_9 -> V_121 -> V_57 + V_34 -> V_36 ;
V_2 -> V_120 . type = 0 ;
V_2 -> V_120 . V_122 = 0 ;
V_2 -> V_120 . V_123 = 0 ;
F_85 ( & V_2 -> V_120 , V_9 ) ;
if ( V_2 -> V_120 . V_124 == NULL ) {
F_24 ( L_9 ) ;
V_17 = - V_125 ;
goto V_56;
}
V_2 -> V_126 = V_2 -> V_120 . V_124 ;
V_17 = V_2 -> V_127 ( V_2 ) ;
if ( V_17 )
goto V_128;
V_2 -> V_129 = V_2 -> V_7 ;
if ( F_75 ( V_2 -> V_9 ) )
V_2 -> V_129 -= 128 ;
return 0 ;
V_128:
F_86 ( & V_2 -> V_120 , V_9 ) ;
V_56:
F_32 ( V_34 ) ;
V_53:
F_33 ( & V_34 -> V_57 ) ;
V_2 -> V_34 = NULL ;
V_119:
F_77 ( V_2 ) ;
return V_17 ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_58 * V_10 ;
int V_17 ;
if ( V_2 -> V_34 == NULL )
return;
V_10 = V_2 -> V_9 -> V_11 ;
V_17 = F_88 ( V_2 ) ;
if ( V_17 )
F_24 ( L_10 ,
V_2 -> V_37 , V_17 ) ;
F_16 ( V_2 , 0 ) ;
F_86 ( & V_2 -> V_120 , V_2 -> V_9 ) ;
F_32 ( V_2 -> V_34 ) ;
F_33 ( & V_2 -> V_34 -> V_57 ) ;
V_2 -> V_34 = NULL ;
if ( V_2 -> V_130 )
V_2 -> V_130 ( V_2 ) ;
F_77 ( V_2 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
unsigned int * V_131 ;
int V_132 = V_2 -> V_7 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_132 ) {
int V_17 = F_90 ( V_2 , V_132 ) ;
if ( V_17 )
return V_17 ;
}
V_131 = ( unsigned int * ) ( V_2 -> V_126 + V_2 -> V_6 ) ;
V_132 /= 8 ;
while ( V_132 -- ) {
* V_131 ++ = V_28 ;
* V_131 ++ = V_28 ;
}
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 , int V_133 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_58 * V_10 = V_9 -> V_11 ;
unsigned long V_134 ;
T_1 V_4 ;
V_4 = F_51 ( V_2 , 4 ) ;
if ( V_4 > V_2 -> V_4 ) {
V_2 -> V_4 = V_4 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_133 )
return 0 ;
}
F_91 ( V_2 ) ;
V_134 = V_135 + 3 * V_136 ;
do {
V_2 -> V_4 = F_19 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_133 ) {
F_92 ( V_2 ) ;
return 0 ;
}
if ( V_9 -> V_137 -> V_138 ) {
struct V_139 * V_140 = V_9 -> V_137 -> V_138 -> V_141 ;
if ( V_140 -> V_142 )
V_140 -> V_142 -> V_143 |= V_144 ;
}
F_93 ( 1 ) ;
if ( F_94 ( & V_10 -> V_145 . V_146 ) )
return - V_147 ;
} while ( ! F_95 ( V_135 , V_134 ) );
F_92 ( V_2 ) ;
return - V_148 ;
}
int F_7 ( struct V_1 * V_2 ,
int V_149 )
{
struct V_58 * V_10 = V_2 -> V_9 -> V_11 ;
int V_133 = 4 * V_149 ;
int V_17 ;
if ( F_96 ( F_94 ( & V_10 -> V_145 . V_146 ) ) )
return - V_42 ;
if ( F_96 ( V_2 -> V_6 + V_133 > V_2 -> V_129 ) ) {
V_17 = F_89 ( V_2 ) ;
if ( F_96 ( V_17 ) )
return V_17 ;
}
if ( F_96 ( V_2 -> V_3 < V_133 ) ) {
V_17 = F_90 ( V_2 , V_133 ) ;
if ( F_96 ( V_17 ) )
return V_17 ;
}
V_2 -> V_3 -= V_133 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_6 &= V_2 -> V_7 - 1 ;
V_2 -> V_35 ( V_2 , V_2 -> V_6 ) ;
}
static void F_97 ( struct V_1 * V_2 ,
T_1 V_29 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
F_40 ( V_150 ,
V_151 |
V_152 ) ;
F_40 ( V_153 , 0x0 ) ;
if ( F_98 ( ( F_14 ( V_150 ) &
V_154 ) == 0 ,
50 ) )
F_24 ( L_11 ) ;
F_11 ( V_2 , V_29 ) ;
F_40 ( V_150 ,
V_151 |
V_155 ) ;
}
static int F_99 ( struct V_1 * V_2 ,
T_1 V_156 , T_1 V_157 )
{
T_3 V_16 ;
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_16 = V_158 ;
if ( V_156 & V_159 )
V_16 |= V_160 | V_161 ;
F_8 ( V_2 , V_16 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_100 ( struct V_1 * V_2 ,
T_1 V_106 , T_1 V_110 )
{
int V_17 ;
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_108 | V_109 ) ;
F_8 ( V_2 , V_106 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static bool
F_101 ( struct V_1 * V_2 )
{
return F_68 ( V_2 ,
V_91 ,
V_162 ) ;
}
static void
F_102 ( struct V_1 * V_2 )
{
return F_70 ( V_2 ,
V_91 ,
V_162 ) ;
}
static bool
F_103 ( struct V_1 * V_2 )
{
return F_68 ( V_2 ,
V_163 ,
V_164 ) ;
}
static void
F_104 ( struct V_1 * V_2 )
{
return F_70 ( V_2 ,
V_163 ,
V_164 ) ;
}
static bool
F_105 ( struct V_1 * V_2 )
{
return F_68 ( V_2 ,
V_165 ,
V_166 ) ;
}
static void
F_106 ( struct V_1 * V_2 )
{
F_70 ( V_2 ,
V_165 ,
V_166 ) ;
}
static inline struct V_33 *
F_107 ( struct V_1 * V_2 )
{
return V_2 -> V_47 ;
}
static int F_108 ( struct V_1 * V_2 )
{
if ( F_109 ( V_2 -> V_9 ) ) {
struct V_33 * V_34 ;
T_1 * V_167 ;
int V_17 ;
V_34 = F_29 ( V_2 -> V_9 , 4096 ) ;
if ( V_34 == NULL )
return - V_49 ;
V_17 = F_30 ( V_34 , 4096 , true ) ;
if ( V_17 ) {
F_33 ( & V_34 -> V_57 ) ;
return V_17 ;
}
V_167 = F_31 ( V_34 -> V_55 [ 0 ] ) ;
* V_167 ++ = V_168 ;
* V_167 ++ = V_28 ;
F_36 ( V_34 -> V_55 [ 0 ] ) ;
V_17 = F_110 ( V_34 , false ) ;
if ( V_17 ) {
F_32 ( V_34 ) ;
F_33 ( & V_34 -> V_57 ) ;
return V_17 ;
}
V_2 -> V_47 = V_34 ;
}
return F_15 ( V_2 ) ;
}
static int F_111 ( struct V_1 * V_2 ,
int V_149 )
{
if ( V_2 -> V_47 ) {
int V_17 = F_7 ( V_2 , V_149 + 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_108 ) ;
F_8 ( V_2 , F_107 ( V_2 ) -> V_36 ) ;
return 0 ;
} else
return F_7 ( V_2 , 4 ) ;
}
static int F_112 ( struct V_1 * V_2 ,
T_1 V_156 , T_1 V_157 )
{
T_3 V_16 ;
int V_17 ;
V_17 = F_111 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_16 = V_158 ;
if ( V_156 & V_20 )
V_16 |= V_160 ;
F_8 ( V_2 , V_16 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static void F_113 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_47 )
return;
F_32 ( V_2 -> V_47 ) ;
F_33 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
}
int F_114 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_169 ] ;
* V_2 = V_170 ;
if ( F_4 ( V_9 ) -> V_21 >= 6 ) {
V_2 -> V_171 = F_44 ;
V_2 -> V_172 = F_101 ;
V_2 -> V_173 = F_102 ;
} else if ( F_6 ( V_9 ) ) {
V_2 -> V_171 = F_47 ;
V_2 -> V_174 = F_52 ;
}
if ( ! F_84 ( V_9 ) ) {
V_2 -> V_100 . V_114 = V_10 -> V_175 -> V_176 ;
memset ( V_2 -> V_100 . V_114 , 0 , V_38 ) ;
}
return F_80 ( V_9 , V_2 ) ;
}
int F_115 ( struct V_8 * V_9 , T_4 V_177 , T_1 V_7 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_169 ] ;
* V_2 = V_170 ;
if ( F_4 ( V_9 ) -> V_21 >= 6 ) {
V_2 -> V_171 = F_44 ;
V_2 -> V_172 = F_101 ;
V_2 -> V_173 = F_102 ;
} else if ( F_6 ( V_9 ) ) {
V_2 -> V_171 = F_47 ;
V_2 -> V_174 = F_52 ;
}
V_2 -> V_9 = V_9 ;
F_81 ( & V_2 -> V_115 ) ;
F_81 ( & V_2 -> V_116 ) ;
F_81 ( & V_2 -> V_117 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_129 = V_2 -> V_7 ;
if ( F_75 ( V_2 -> V_9 ) )
V_2 -> V_129 -= 128 ;
V_2 -> V_120 . V_106 = V_177 ;
V_2 -> V_120 . V_7 = V_7 ;
V_2 -> V_120 . type = 0 ;
V_2 -> V_120 . V_122 = 0 ;
V_2 -> V_120 . V_123 = 0 ;
F_85 ( & V_2 -> V_120 , V_9 ) ;
if ( V_2 -> V_120 . V_124 == NULL ) {
F_24 ( L_12
L_13 ) ;
return - V_49 ;
}
V_2 -> V_126 = ( void V_178 V_179 * ) V_2 -> V_120 . V_124 ;
return 0 ;
}
int F_116 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_180 ] ;
if ( F_38 ( V_9 ) || F_39 ( V_9 ) )
* V_2 = V_181 ;
else
* V_2 = V_182 ;
return F_80 ( V_9 , V_2 ) ;
}
int F_117 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_183 ] ;
* V_2 = V_184 ;
return F_80 ( V_9 , V_2 ) ;
}
