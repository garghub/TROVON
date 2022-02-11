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
static int
F_10 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
T_1 V_32 = V_30 -> V_33 + 128 ;
int V_17 ;
V_17 = F_7 ( V_2 , 6 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , F_11 ( 5 ) ) ;
F_8 ( V_2 , V_34 |
V_35 ) ;
F_8 ( V_2 , V_32 | V_36 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
V_17 = F_7 ( V_2 , 6 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , F_11 ( 5 ) ) ;
F_8 ( V_2 , V_37 ) ;
F_8 ( V_2 , V_32 | V_36 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 ,
T_1 V_14 , T_1 V_15 )
{
T_1 V_38 = 0 ;
struct V_29 * V_30 = V_2 -> V_31 ;
T_1 V_32 = V_30 -> V_33 + 128 ;
int V_17 ;
F_10 ( V_2 ) ;
V_38 |= V_39 ;
V_38 |= V_40 ;
V_38 |= V_41 ;
V_38 |= V_42 ;
V_38 |= V_43 ;
V_38 |= V_44 ;
V_38 |= V_45 ;
V_17 = F_7 ( V_2 , 6 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , F_11 ( 5 ) ) ;
F_8 ( V_2 , V_38 ) ;
F_8 ( V_2 , V_32 | V_36 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 ,
T_1 V_46 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
F_14 ( V_2 , V_46 ) ;
}
T_1 F_15 ( struct V_1 * V_2 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
T_1 V_47 = F_4 ( V_2 -> V_9 ) -> V_21 >= 4 ?
F_16 ( V_2 -> V_48 ) : V_49 ;
return F_17 ( V_47 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
struct V_50 * V_51 = V_2 -> V_51 ;
T_1 V_4 ;
F_19 ( V_2 , 0 ) ;
F_20 ( V_2 , 0 ) ;
V_2 -> V_52 ( V_2 , 0 ) ;
F_21 ( V_2 , V_51 -> V_33 ) ;
V_4 = F_22 ( V_2 ) & V_5 ;
if ( V_4 != 0 ) {
F_23 ( L_1
L_2 ,
V_2 -> V_53 ,
F_24 ( V_2 ) ,
F_22 ( V_2 ) ,
F_25 ( V_2 ) ,
F_26 ( V_2 ) ) ;
F_20 ( V_2 , 0 ) ;
if ( F_22 ( V_2 ) & V_5 ) {
F_27 ( L_3
L_2 ,
V_2 -> V_53 ,
F_24 ( V_2 ) ,
F_22 ( V_2 ) ,
F_25 ( V_2 ) ,
F_26 ( V_2 ) ) ;
}
}
F_19 ( V_2 ,
( ( V_2 -> V_7 - V_54 ) & V_55 )
| V_56 | V_57 ) ;
if ( ( F_24 ( V_2 ) & V_57 ) == 0 ||
F_26 ( V_2 ) != V_51 -> V_33 ||
( F_22 ( V_2 ) & V_5 ) != 0 ) {
F_27 ( L_4
L_2 ,
V_2 -> V_53 ,
F_24 ( V_2 ) ,
F_22 ( V_2 ) ,
F_25 ( V_2 ) ,
F_26 ( V_2 ) ) ;
return - V_58 ;
}
if ( ! F_28 ( V_2 -> V_9 , V_59 ) )
F_29 ( V_2 -> V_9 ) ;
else {
V_2 -> V_4 = F_22 ( V_2 ) ;
V_2 -> V_6 = F_25 ( V_2 ) & V_60 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
}
return 0 ;
}
static int
F_30 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
struct V_50 * V_51 ;
int V_17 ;
if ( V_2 -> V_31 )
return 0 ;
V_30 = F_31 ( sizeof( * V_30 ) , V_61 ) ;
if ( ! V_30 )
return - V_62 ;
V_51 = F_32 ( V_2 -> V_9 , 4096 ) ;
if ( V_51 == NULL ) {
F_27 ( L_5 ) ;
V_17 = - V_62 ;
goto V_63;
}
F_33 ( V_51 , V_64 ) ;
V_17 = F_34 ( V_51 , 4096 , true ) ;
if ( V_17 )
goto V_65;
V_30 -> V_33 = V_51 -> V_33 ;
V_30 -> V_66 = F_35 ( V_51 -> V_67 [ 0 ] ) ;
if ( V_30 -> V_66 == NULL )
goto V_68;
V_30 -> V_51 = V_51 ;
V_2 -> V_31 = V_30 ;
return 0 ;
V_68:
F_36 ( V_51 ) ;
V_65:
F_37 ( & V_51 -> V_69 ) ;
V_63:
F_38 ( V_30 ) ;
return V_17 ;
}
static void
F_39 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
struct V_50 * V_51 ;
if ( ! V_2 -> V_31 )
return;
V_51 = V_30 -> V_51 ;
F_40 ( V_51 -> V_67 [ 0 ] ) ;
F_36 ( V_51 ) ;
F_37 ( & V_51 -> V_69 ) ;
F_38 ( V_30 ) ;
V_2 -> V_31 = NULL ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_70 * V_10 = V_9 -> V_11 ;
int V_17 = F_18 ( V_2 ) ;
if ( F_4 ( V_9 ) -> V_21 > 3 ) {
int V_71 = V_72 << 16 | V_72 ;
if ( F_42 ( V_9 ) || F_43 ( V_9 ) )
V_71 |= V_73 << 16 | V_73 ;
F_44 ( V_74 , V_71 ) ;
if ( F_43 ( V_9 ) )
F_44 ( V_75 ,
F_45 ( V_76 ) |
F_46 ( V_77 ) ) ;
}
if ( F_4 ( V_9 ) -> V_21 >= 5 ) {
V_17 = F_30 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
return V_17 ;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_31 )
return;
F_39 ( V_2 ) ;
}
static void
F_48 ( struct V_1 * V_2 ,
T_1 V_12 ,
T_1 V_78 )
{
F_8 ( V_2 , V_79 |
V_80 |
V_81 |
V_82 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_78 ) ;
}
static int
F_49 ( struct V_1 * V_2 ,
T_1 * V_12 )
{
T_1 V_83 ;
T_1 V_84 ;
int V_17 ;
V_17 = F_7 ( V_2 , 10 ) ;
if ( V_17 )
return V_17 ;
V_83 = V_2 -> V_85 [ 0 ] ;
V_84 = V_2 -> V_85 [ 1 ] ;
* V_12 = F_2 ( V_2 -> V_9 ) ;
F_48 ( V_2 , * V_12 , V_83 ) ;
F_48 ( V_2 , * V_12 , V_84 ) ;
F_8 ( V_2 , V_86 ) ;
F_8 ( V_2 , V_87 << V_88 ) ;
F_8 ( V_2 , * V_12 ) ;
F_8 ( V_2 , V_89 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_50 ( struct V_1 * V_90 ,
struct V_1 * V_91 ,
int V_2 ,
T_1 V_12 )
{
int V_17 ;
T_1 V_92 = V_79 |
V_93 |
V_81 ;
V_17 = F_7 ( V_90 , 4 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_90 , V_92 | V_91 -> V_94 [ V_2 ] ) ;
F_8 ( V_90 , V_12 ) ;
F_8 ( V_90 , 0 ) ;
F_8 ( V_90 , V_28 ) ;
F_9 ( V_90 ) ;
return 0 ;
}
int
F_51 ( struct V_1 * V_90 ,
struct V_1 * V_91 ,
T_1 V_12 )
{
F_52 ( V_91 -> V_94 [ V_95 ] == V_96 ) ;
return F_50 ( V_90 ,
V_91 ,
V_95 ,
V_12 ) ;
}
int
F_53 ( struct V_1 * V_90 ,
struct V_1 * V_91 ,
T_1 V_12 )
{
F_52 ( V_91 -> V_94 [ V_97 ] == V_96 ) ;
return F_50 ( V_90 ,
V_91 ,
V_97 ,
V_12 ) ;
}
int
F_54 ( struct V_1 * V_90 ,
struct V_1 * V_91 ,
T_1 V_12 )
{
F_52 ( V_91 -> V_94 [ V_98 ] == V_96 ) ;
return F_50 ( V_90 ,
V_91 ,
V_98 ,
V_12 ) ;
}
static int
F_55 ( struct V_1 * V_2 ,
T_1 * V_99 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_12 = F_2 ( V_9 ) ;
struct V_29 * V_30 = V_2 -> V_31 ;
T_1 V_32 = V_30 -> V_33 + 128 ;
int V_17 ;
V_17 = F_7 ( V_2 , 32 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , F_11 ( 4 ) | V_37 |
V_100 |
V_41 ) ;
F_8 ( V_2 , V_30 -> V_33 | V_36 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , 0 ) ;
F_56 ( V_2 , V_32 ) ;
V_32 += 128 ;
F_56 ( V_2 , V_32 ) ;
V_32 += 128 ;
F_56 ( V_2 , V_32 ) ;
V_32 += 128 ;
F_56 ( V_2 , V_32 ) ;
V_32 += 128 ;
F_56 ( V_2 , V_32 ) ;
V_32 += 128 ;
F_56 ( V_2 , V_32 ) ;
F_8 ( V_2 , F_11 ( 4 ) | V_37 |
V_100 |
V_41 |
V_101 ) ;
F_8 ( V_2 , V_30 -> V_33 | V_36 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , 0 ) ;
F_9 ( V_2 ) ;
* V_99 = V_12 ;
return 0 ;
}
static int
F_57 ( struct V_1 * V_2 ,
T_1 * V_99 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_12 = F_2 ( V_9 ) ;
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_86 ) ;
F_8 ( V_2 , V_87 << V_88 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_89 ) ;
F_9 ( V_2 ) ;
* V_99 = V_12 ;
return 0 ;
}
static T_1
F_58 ( struct V_1 * V_2 )
{
return F_59 ( V_2 , V_87 ) ;
}
static T_1
F_60 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
return V_30 -> V_66 [ 0 ] ;
}
static void
F_61 ( T_2 * V_10 , T_1 V_102 )
{
V_10 -> V_103 &= ~ V_102 ;
F_44 ( V_104 , V_10 -> V_103 ) ;
F_62 ( V_104 ) ;
}
static void
F_63 ( T_2 * V_10 , T_1 V_102 )
{
V_10 -> V_103 |= V_102 ;
F_44 ( V_104 , V_10 -> V_103 ) ;
F_62 ( V_104 ) ;
}
static void
F_64 ( T_2 * V_10 , T_1 V_102 )
{
V_10 -> V_105 &= ~ V_102 ;
F_44 ( V_106 , V_10 -> V_105 ) ;
F_62 ( V_106 ) ;
}
static void
F_65 ( T_2 * V_10 , T_1 V_102 )
{
V_10 -> V_105 |= V_102 ;
F_44 ( V_106 , V_10 -> V_105 ) ;
F_62 ( V_106 ) ;
}
static bool
F_66 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
if ( ! V_9 -> V_107 )
return false ;
F_67 ( & V_2 -> V_108 ) ;
if ( V_2 -> V_109 ++ == 0 ) {
if ( F_68 ( V_9 ) )
F_61 ( V_10 ,
V_110 | V_111 ) ;
else
F_64 ( V_10 , V_112 ) ;
}
F_69 ( & V_2 -> V_108 ) ;
return true ;
}
static void
F_70 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
F_67 ( & V_2 -> V_108 ) ;
if ( -- V_2 -> V_109 == 0 ) {
if ( F_68 ( V_9 ) )
F_63 ( V_10 ,
V_111 |
V_110 ) ;
else
F_65 ( V_10 , V_112 ) ;
}
F_69 ( & V_2 -> V_108 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
T_1 V_113 = 0 ;
if ( F_43 ( V_9 ) ) {
switch ( V_2 -> V_114 ) {
case V_115 :
V_113 = V_116 ;
break;
case V_117 :
V_113 = V_118 ;
break;
case V_119 :
V_113 = V_120 ;
break;
}
} else if ( F_42 ( V_2 -> V_9 ) ) {
V_113 = F_72 ( V_2 -> V_48 ) ;
} else {
V_113 = F_73 ( V_2 -> V_48 ) ;
}
F_44 ( V_113 , ( T_1 ) V_2 -> V_121 . V_122 ) ;
F_62 ( V_113 ) ;
}
static int
F_74 ( struct V_1 * V_2 ,
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
F_75 ( struct V_1 * V_2 ,
T_1 * V_99 )
{
T_1 V_12 ;
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_12 = F_2 ( V_2 -> V_9 ) ;
F_8 ( V_2 , V_86 ) ;
F_8 ( V_2 , V_87 << V_88 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_89 ) ;
F_9 ( V_2 ) ;
* V_99 = V_12 ;
return 0 ;
}
static bool
F_76 ( struct V_1 * V_2 , T_1 V_123 , T_1 V_124 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
if ( ! V_9 -> V_107 )
return false ;
F_67 ( & V_2 -> V_108 ) ;
if ( V_2 -> V_109 ++ == 0 ) {
V_2 -> V_105 &= ~ V_124 ;
F_77 ( V_2 , V_2 -> V_105 ) ;
F_61 ( V_10 , V_123 ) ;
}
F_69 ( & V_2 -> V_108 ) ;
return true ;
}
static void
F_78 ( struct V_1 * V_2 , T_1 V_123 , T_1 V_124 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
F_67 ( & V_2 -> V_108 ) ;
if ( -- V_2 -> V_109 == 0 ) {
V_2 -> V_105 |= V_124 ;
F_77 ( V_2 , V_2 -> V_105 ) ;
F_63 ( V_10 , V_123 ) ;
}
F_69 ( & V_2 -> V_108 ) ;
}
static bool
F_79 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
if ( ! V_9 -> V_107 )
return false ;
F_67 ( & V_2 -> V_108 ) ;
if ( V_2 -> V_109 ++ == 0 ) {
if ( F_5 ( V_9 ) )
F_64 ( V_10 , V_125 ) ;
else
F_61 ( V_10 , V_126 ) ;
}
F_69 ( & V_2 -> V_108 ) ;
return true ;
}
static void
F_80 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
F_67 ( & V_2 -> V_108 ) ;
if ( -- V_2 -> V_109 == 0 ) {
if ( F_5 ( V_9 ) )
F_65 ( V_10 , V_125 ) ;
else
F_63 ( V_10 , V_126 ) ;
}
F_69 ( & V_2 -> V_108 ) ;
}
static int
F_81 ( struct V_1 * V_2 , T_1 V_127 , T_1 V_128 )
{
int V_17 ;
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 ,
V_129 | ( 2 << 6 ) |
V_130 ) ;
F_8 ( V_2 , V_127 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_82 ( struct V_1 * V_2 ,
T_1 V_127 , T_1 V_131 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_17 ;
if ( F_83 ( V_9 ) || F_84 ( V_9 ) ) {
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_132 ) ;
F_8 ( V_2 , V_127 | V_133 ) ;
F_8 ( V_2 , V_127 + V_131 - 8 ) ;
F_8 ( V_2 , 0 ) ;
} else {
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
if ( F_4 ( V_9 ) -> V_21 >= 4 ) {
F_8 ( V_2 ,
V_129 | ( 2 << 6 ) |
V_130 ) ;
F_8 ( V_2 , V_127 ) ;
} else {
F_8 ( V_2 ,
V_129 | ( 2 << 6 ) ) ;
F_8 ( V_2 , V_127 | V_133 ) ;
}
}
F_9 ( V_2 ) ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
struct V_50 * V_51 ;
V_51 = V_2 -> V_121 . V_51 ;
if ( V_51 == NULL )
return;
F_40 ( V_51 -> V_67 [ 0 ] ) ;
F_36 ( V_51 ) ;
F_37 ( & V_51 -> V_69 ) ;
V_2 -> V_121 . V_51 = NULL ;
memset ( & V_10 -> V_134 , 0 , sizeof( V_10 -> V_134 ) ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
struct V_50 * V_51 ;
int V_17 ;
V_51 = F_32 ( V_9 , 4096 ) ;
if ( V_51 == NULL ) {
F_27 ( L_6 ) ;
V_17 = - V_62 ;
goto V_63;
}
F_33 ( V_51 , V_64 ) ;
V_17 = F_34 ( V_51 , 4096 , true ) ;
if ( V_17 != 0 ) {
goto V_65;
}
V_2 -> V_121 . V_122 = V_51 -> V_33 ;
V_2 -> V_121 . V_135 = F_35 ( V_51 -> V_67 [ 0 ] ) ;
if ( V_2 -> V_121 . V_135 == NULL ) {
memset ( & V_10 -> V_134 , 0 , sizeof( V_10 -> V_134 ) ) ;
goto V_68;
}
V_2 -> V_121 . V_51 = V_51 ;
memset ( V_2 -> V_121 . V_135 , 0 , V_54 ) ;
F_71 ( V_2 ) ;
F_87 ( L_7 ,
V_2 -> V_53 , V_2 -> V_121 . V_122 ) ;
return 0 ;
V_68:
F_36 ( V_51 ) ;
V_65:
F_37 ( & V_51 -> V_69 ) ;
V_63:
return V_17 ;
}
int F_88 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 ;
int V_17 ;
V_2 -> V_9 = V_9 ;
F_89 ( & V_2 -> V_136 ) ;
F_89 ( & V_2 -> V_137 ) ;
F_89 ( & V_2 -> V_138 ) ;
F_90 ( & V_2 -> V_139 ) ;
F_91 ( & V_2 -> V_108 ) ;
V_2 -> V_105 = ~ 0 ;
if ( F_92 ( V_9 ) ) {
V_17 = F_86 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
V_51 = F_32 ( V_9 , V_2 -> V_7 ) ;
if ( V_51 == NULL ) {
F_27 ( L_8 ) ;
V_17 = - V_62 ;
goto V_140;
}
V_2 -> V_51 = V_51 ;
V_17 = F_34 ( V_51 , V_54 , true ) ;
if ( V_17 )
goto V_65;
V_2 -> V_141 . V_7 = V_2 -> V_7 ;
V_2 -> V_141 . V_127 = V_9 -> V_142 -> V_69 + V_51 -> V_33 ;
V_2 -> V_141 . type = 0 ;
V_2 -> V_141 . V_38 = 0 ;
V_2 -> V_141 . V_143 = 0 ;
F_93 ( & V_2 -> V_141 , V_9 ) ;
if ( V_2 -> V_141 . V_144 == NULL ) {
F_27 ( L_9 ) ;
V_17 = - V_145 ;
goto V_68;
}
V_2 -> V_146 = V_2 -> V_141 . V_144 ;
V_17 = V_2 -> V_147 ( V_2 ) ;
if ( V_17 )
goto V_148;
V_2 -> V_149 = V_2 -> V_7 ;
if ( F_83 ( V_2 -> V_9 ) )
V_2 -> V_149 -= 128 ;
return 0 ;
V_148:
F_94 ( & V_2 -> V_141 , V_9 ) ;
V_68:
F_36 ( V_51 ) ;
V_65:
F_37 ( & V_51 -> V_69 ) ;
V_2 -> V_51 = NULL ;
V_140:
F_85 ( V_2 ) ;
return V_17 ;
}
void F_95 ( struct V_1 * V_2 )
{
struct V_70 * V_10 ;
int V_17 ;
if ( V_2 -> V_51 == NULL )
return;
V_10 = V_2 -> V_9 -> V_11 ;
V_17 = F_96 ( V_2 ) ;
if ( V_17 )
F_27 ( L_10 ,
V_2 -> V_53 , V_17 ) ;
F_19 ( V_2 , 0 ) ;
F_94 ( & V_2 -> V_141 , V_2 -> V_9 ) ;
F_36 ( V_2 -> V_51 ) ;
F_37 ( & V_2 -> V_51 -> V_69 ) ;
V_2 -> V_51 = NULL ;
if ( V_2 -> V_150 )
V_2 -> V_150 ( V_2 ) ;
F_85 ( V_2 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
unsigned int * V_151 ;
int V_152 = V_2 -> V_7 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_152 ) {
int V_17 = F_98 ( V_2 , V_152 ) ;
if ( V_17 )
return V_17 ;
}
V_151 = ( unsigned int * ) ( V_2 -> V_146 + V_2 -> V_6 ) ;
V_152 /= 8 ;
while ( V_152 -- ) {
* V_151 ++ = V_28 ;
* V_151 ++ = V_28 ;
}
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
int F_98 ( struct V_1 * V_2 , int V_153 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_70 * V_10 = V_9 -> V_11 ;
unsigned long V_154 ;
T_1 V_4 ;
V_4 = F_59 ( V_2 , 4 ) ;
if ( V_4 > V_2 -> V_4 ) {
V_2 -> V_4 = V_4 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_153 )
return 0 ;
}
F_99 ( V_2 ) ;
V_154 = V_155 + 3 * V_156 ;
do {
V_2 -> V_4 = F_22 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_153 ) {
F_100 ( V_2 ) ;
return 0 ;
}
if ( V_9 -> V_157 -> V_158 ) {
struct V_159 * V_160 = V_9 -> V_157 -> V_158 -> V_161 ;
if ( V_160 -> V_162 )
V_160 -> V_162 -> V_163 |= V_164 ;
}
F_101 ( 1 ) ;
if ( F_102 ( & V_10 -> V_165 . V_166 ) )
return - V_167 ;
} while ( ! F_103 ( V_155 , V_154 ) );
F_100 ( V_2 ) ;
return - V_168 ;
}
int F_7 ( struct V_1 * V_2 ,
int V_169 )
{
struct V_70 * V_10 = V_2 -> V_9 -> V_11 ;
int V_153 = 4 * V_169 ;
int V_17 ;
if ( F_104 ( F_102 ( & V_10 -> V_165 . V_166 ) ) )
return - V_58 ;
if ( F_104 ( V_2 -> V_6 + V_153 > V_2 -> V_149 ) ) {
V_17 = F_97 ( V_2 ) ;
if ( F_104 ( V_17 ) )
return V_17 ;
}
if ( F_104 ( V_2 -> V_3 < V_153 ) ) {
V_17 = F_98 ( V_2 , V_153 ) ;
if ( F_104 ( V_17 ) )
return V_17 ;
}
V_2 -> V_3 -= V_153 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_6 &= V_2 -> V_7 - 1 ;
V_2 -> V_52 ( V_2 , V_2 -> V_6 ) ;
}
static void F_105 ( struct V_1 * V_2 ,
T_1 V_46 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
F_44 ( V_170 ,
V_171 |
V_172 ) ;
F_44 ( V_173 , 0x0 ) ;
if ( F_106 ( ( F_17 ( V_170 ) &
V_174 ) == 0 ,
50 ) )
F_27 ( L_11 ) ;
F_14 ( V_2 , V_46 ) ;
F_44 ( V_170 ,
V_171 |
V_175 ) ;
}
static int F_107 ( struct V_1 * V_2 ,
T_1 V_176 , T_1 V_177 )
{
T_3 V_16 ;
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_16 = V_178 ;
if ( V_176 & V_179 )
V_16 |= V_180 | V_181 ;
F_8 ( V_2 , V_16 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_108 ( struct V_1 * V_2 ,
T_1 V_127 , T_1 V_131 )
{
int V_17 ;
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_129 | V_130 ) ;
F_8 ( V_2 , V_127 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static bool
F_109 ( struct V_1 * V_2 )
{
return F_76 ( V_2 ,
V_111 ,
V_182 ) ;
}
static void
F_110 ( struct V_1 * V_2 )
{
return F_78 ( V_2 ,
V_111 ,
V_182 ) ;
}
static bool
F_111 ( struct V_1 * V_2 )
{
return F_76 ( V_2 ,
V_183 ,
V_184 ) ;
}
static void
F_112 ( struct V_1 * V_2 )
{
return F_78 ( V_2 ,
V_183 ,
V_184 ) ;
}
static bool
F_113 ( struct V_1 * V_2 )
{
return F_76 ( V_2 ,
V_185 ,
V_186 ) ;
}
static void
F_114 ( struct V_1 * V_2 )
{
F_78 ( V_2 ,
V_185 ,
V_186 ) ;
}
static inline struct V_50 *
F_115 ( struct V_1 * V_2 )
{
return V_2 -> V_31 ;
}
static int F_116 ( struct V_1 * V_2 )
{
if ( F_117 ( V_2 -> V_9 ) ) {
struct V_50 * V_51 ;
T_1 * V_187 ;
int V_17 ;
V_51 = F_32 ( V_2 -> V_9 , 4096 ) ;
if ( V_51 == NULL )
return - V_62 ;
V_17 = F_34 ( V_51 , 4096 , true ) ;
if ( V_17 ) {
F_37 ( & V_51 -> V_69 ) ;
return V_17 ;
}
V_187 = F_35 ( V_51 -> V_67 [ 0 ] ) ;
* V_187 ++ = V_188 ;
* V_187 ++ = V_28 ;
F_40 ( V_51 -> V_67 [ 0 ] ) ;
V_17 = F_118 ( V_51 , false ) ;
if ( V_17 ) {
F_36 ( V_51 ) ;
F_37 ( & V_51 -> V_69 ) ;
return V_17 ;
}
V_2 -> V_31 = V_51 ;
}
return F_18 ( V_2 ) ;
}
static int F_119 ( struct V_1 * V_2 ,
int V_169 )
{
if ( V_2 -> V_31 ) {
int V_17 = F_7 ( V_2 , V_169 + 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_129 ) ;
F_8 ( V_2 , F_115 ( V_2 ) -> V_33 ) ;
return 0 ;
} else
return F_7 ( V_2 , 4 ) ;
}
static int F_120 ( struct V_1 * V_2 ,
T_1 V_176 , T_1 V_177 )
{
T_3 V_16 ;
int V_17 ;
V_17 = F_119 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_16 = V_178 ;
if ( V_176 & V_20 )
V_16 |= V_180 ;
F_8 ( V_2 , V_16 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static void F_121 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_31 )
return;
F_36 ( V_2 -> V_31 ) ;
F_37 ( V_2 -> V_31 ) ;
V_2 -> V_31 = NULL ;
}
int F_122 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_95 ] ;
* V_2 = V_189 ;
if ( F_4 ( V_9 ) -> V_21 >= 6 ) {
V_2 -> V_190 = F_49 ;
V_2 -> V_177 = F_12 ;
V_2 -> V_191 = F_109 ;
V_2 -> V_192 = F_110 ;
} else if ( F_6 ( V_9 ) ) {
V_2 -> V_190 = F_55 ;
V_2 -> V_193 = F_60 ;
}
if ( ! F_92 ( V_9 ) ) {
V_2 -> V_121 . V_135 = V_10 -> V_194 -> V_195 ;
memset ( V_2 -> V_121 . V_135 , 0 , V_54 ) ;
}
return F_88 ( V_9 , V_2 ) ;
}
int F_123 ( struct V_8 * V_9 , T_4 V_196 , T_1 V_7 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_95 ] ;
* V_2 = V_189 ;
if ( F_4 ( V_9 ) -> V_21 >= 6 ) {
V_2 -> V_190 = F_49 ;
V_2 -> V_191 = F_109 ;
V_2 -> V_192 = F_110 ;
} else if ( F_6 ( V_9 ) ) {
V_2 -> V_190 = F_55 ;
V_2 -> V_193 = F_60 ;
}
if ( ! F_92 ( V_9 ) )
V_2 -> V_121 . V_135 = V_10 -> V_194 -> V_195 ;
V_2 -> V_9 = V_9 ;
F_89 ( & V_2 -> V_136 ) ;
F_89 ( & V_2 -> V_137 ) ;
F_89 ( & V_2 -> V_138 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_149 = V_2 -> V_7 ;
if ( F_83 ( V_2 -> V_9 ) )
V_2 -> V_149 -= 128 ;
V_2 -> V_141 . V_127 = V_196 ;
V_2 -> V_141 . V_7 = V_7 ;
V_2 -> V_141 . type = 0 ;
V_2 -> V_141 . V_38 = 0 ;
V_2 -> V_141 . V_143 = 0 ;
F_93 ( & V_2 -> V_141 , V_9 ) ;
if ( V_2 -> V_141 . V_144 == NULL ) {
F_27 ( L_12
L_13 ) ;
return - V_62 ;
}
V_2 -> V_146 = ( void V_197 V_198 * ) V_2 -> V_141 . V_144 ;
return 0 ;
}
int F_124 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_97 ] ;
if ( F_42 ( V_9 ) || F_43 ( V_9 ) )
* V_2 = V_199 ;
else
* V_2 = V_200 ;
return F_88 ( V_9 , V_2 ) ;
}
int F_125 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_98 ] ;
* V_2 = V_201 ;
return F_88 ( V_9 , V_2 ) ;
}
