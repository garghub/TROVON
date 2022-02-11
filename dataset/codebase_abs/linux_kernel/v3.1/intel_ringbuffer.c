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
F_30 ( V_34 , V_51 ) ;
V_17 = F_31 ( V_34 , 4096 , true ) ;
if ( V_17 )
goto V_52;
V_46 -> V_36 = V_34 -> V_36 ;
V_46 -> V_53 = F_32 ( V_34 -> V_54 [ 0 ] ) ;
if ( V_46 -> V_53 == NULL )
goto V_55;
V_46 -> V_34 = V_34 ;
V_2 -> V_47 = V_46 ;
return 0 ;
V_55:
F_33 ( V_34 ) ;
V_52:
F_34 ( & V_34 -> V_56 ) ;
V_50:
F_35 ( V_46 ) ;
return V_17 ;
}
static void
F_36 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_47 ;
struct V_33 * V_34 ;
if ( ! V_2 -> V_47 )
return;
V_34 = V_46 -> V_34 ;
F_37 ( V_34 -> V_54 [ 0 ] ) ;
F_33 ( V_34 ) ;
F_34 ( & V_34 -> V_56 ) ;
F_35 ( V_46 ) ;
V_2 -> V_47 = NULL ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_57 * V_10 = V_9 -> V_11 ;
int V_17 = F_15 ( V_2 ) ;
if ( F_4 ( V_9 ) -> V_21 > 3 ) {
int V_58 = V_59 << 16 | V_59 ;
if ( F_39 ( V_9 ) || F_40 ( V_9 ) )
V_58 |= V_60 << 16 | V_60 ;
F_41 ( V_61 , V_58 ) ;
if ( F_40 ( V_9 ) )
F_41 ( V_62 ,
F_42 ( V_63 ) |
F_43 ( V_64 ) ) ;
}
if ( F_4 ( V_9 ) -> V_21 >= 6 ) {
} else if ( F_6 ( V_9 ) ) {
V_17 = F_27 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
return V_17 ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_47 )
return;
F_36 ( V_2 ) ;
}
static void
F_45 ( struct V_1 * V_2 , int V_65 , T_1 V_12 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_57 * V_10 = V_9 -> V_11 ;
int V_66 ;
V_66 = V_2 - V_10 -> V_2 ;
V_66 += 2 - V_65 ;
V_66 %= 3 ;
F_8 ( V_2 ,
V_67 |
V_68 |
V_69 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 ,
F_46 ( V_10 -> V_2 [ V_66 ] . V_31 ) + 4 * V_65 ) ;
}
static int
F_47 ( struct V_1 * V_2 ,
T_1 * V_70 )
{
T_1 V_12 ;
int V_17 ;
V_17 = F_7 ( V_2 , 10 ) ;
if ( V_17 )
return V_17 ;
V_12 = F_2 ( V_2 -> V_9 ) ;
F_45 ( V_2 , 0 , V_12 ) ;
F_45 ( V_2 , 1 , V_12 ) ;
F_8 ( V_2 , V_71 ) ;
F_8 ( V_2 , V_72 << V_73 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_74 ) ;
F_9 ( V_2 ) ;
* V_70 = V_12 ;
return 0 ;
}
int
F_48 ( struct V_1 * V_2 ,
struct V_1 * V_75 ,
T_1 V_12 )
{
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 ,
V_67 |
V_68 |
F_49 ( V_2 , V_75 ) << 17 |
V_76 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_50 ( struct V_1 * V_2 ,
T_1 * V_70 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_12 = F_2 ( V_9 ) ;
struct V_45 * V_46 = V_2 -> V_47 ;
T_1 V_77 = V_46 -> V_36 + 128 ;
int V_17 ;
V_17 = F_7 ( V_2 , 32 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_78 | V_79 |
V_80 | V_81 ) ;
F_8 ( V_2 , V_46 -> V_36 | V_82 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , 0 ) ;
F_51 ( V_2 , V_77 ) ;
V_77 += 128 ;
F_51 ( V_2 , V_77 ) ;
V_77 += 128 ;
F_51 ( V_2 , V_77 ) ;
V_77 += 128 ;
F_51 ( V_2 , V_77 ) ;
V_77 += 128 ;
F_51 ( V_2 , V_77 ) ;
V_77 += 128 ;
F_51 ( V_2 , V_77 ) ;
F_8 ( V_2 , V_78 | V_79 |
V_80 | V_81 |
V_83 ) ;
F_8 ( V_2 , V_46 -> V_36 | V_82 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , 0 ) ;
F_9 ( V_2 ) ;
* V_70 = V_12 ;
return 0 ;
}
static int
F_52 ( struct V_1 * V_2 ,
T_1 * V_70 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_12 = F_2 ( V_9 ) ;
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_71 ) ;
F_8 ( V_2 , V_72 << V_73 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_74 ) ;
F_9 ( V_2 ) ;
* V_70 = V_12 ;
return 0 ;
}
static T_1
F_53 ( struct V_1 * V_2 )
{
return F_54 ( V_2 , V_72 ) ;
}
static T_1
F_55 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = V_2 -> V_47 ;
return V_46 -> V_53 [ 0 ] ;
}
static void
F_56 ( T_2 * V_10 , T_1 V_84 )
{
V_10 -> V_85 &= ~ V_84 ;
F_41 ( V_86 , V_10 -> V_85 ) ;
F_57 ( V_86 ) ;
}
static void
F_58 ( T_2 * V_10 , T_1 V_84 )
{
V_10 -> V_85 |= V_84 ;
F_41 ( V_86 , V_10 -> V_85 ) ;
F_57 ( V_86 ) ;
}
static void
F_59 ( T_2 * V_10 , T_1 V_84 )
{
V_10 -> V_87 &= ~ V_84 ;
F_41 ( V_88 , V_10 -> V_87 ) ;
F_57 ( V_88 ) ;
}
static void
F_60 ( T_2 * V_10 , T_1 V_84 )
{
V_10 -> V_87 |= V_84 ;
F_41 ( V_88 , V_10 -> V_87 ) ;
F_57 ( V_88 ) ;
}
static bool
F_61 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
if ( ! V_9 -> V_89 )
return false ;
F_62 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_91 ++ == 0 ) {
if ( F_63 ( V_9 ) )
F_56 ( V_10 ,
V_92 | V_93 ) ;
else
F_59 ( V_10 , V_94 ) ;
}
F_64 ( & V_2 -> V_90 ) ;
return true ;
}
static void
F_65 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
F_62 ( & V_2 -> V_90 ) ;
if ( -- V_2 -> V_91 == 0 ) {
if ( F_63 ( V_9 ) )
F_58 ( V_10 ,
V_93 |
V_92 ) ;
else
F_60 ( V_10 , V_94 ) ;
}
F_64 ( & V_2 -> V_90 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
T_1 V_95 = 0 ;
if ( F_40 ( V_9 ) ) {
switch ( V_2 -> V_66 ) {
case V_96 :
V_95 = V_97 ;
break;
case V_98 :
V_95 = V_99 ;
break;
case V_100 :
V_95 = V_101 ;
break;
}
} else if ( F_39 ( V_2 -> V_9 ) ) {
V_95 = F_67 ( V_2 -> V_31 ) ;
} else {
V_95 = F_68 ( V_2 -> V_31 ) ;
}
F_41 ( V_95 , ( T_1 ) V_2 -> V_102 . V_103 ) ;
F_57 ( V_95 ) ;
}
static int
F_69 ( struct V_1 * V_2 ,
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
F_70 ( struct V_1 * V_2 ,
T_1 * V_70 )
{
T_1 V_12 ;
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_12 = F_2 ( V_2 -> V_9 ) ;
F_8 ( V_2 , V_71 ) ;
F_8 ( V_2 , V_72 << V_73 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_74 ) ;
F_9 ( V_2 ) ;
* V_70 = V_12 ;
return 0 ;
}
static bool
F_71 ( struct V_1 * V_2 , T_1 V_104 , T_1 V_105 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
if ( ! V_9 -> V_89 )
return false ;
F_62 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_91 ++ == 0 ) {
V_2 -> V_87 &= ~ V_105 ;
F_72 ( V_2 , V_2 -> V_87 ) ;
F_56 ( V_10 , V_104 ) ;
}
F_64 ( & V_2 -> V_90 ) ;
return true ;
}
static void
F_73 ( struct V_1 * V_2 , T_1 V_104 , T_1 V_105 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
F_62 ( & V_2 -> V_90 ) ;
if ( -- V_2 -> V_91 == 0 ) {
V_2 -> V_87 |= V_105 ;
F_72 ( V_2 , V_2 -> V_87 ) ;
F_58 ( V_10 , V_104 ) ;
}
F_64 ( & V_2 -> V_90 ) ;
}
static bool
F_74 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
if ( ! V_9 -> V_89 )
return false ;
F_62 ( & V_2 -> V_90 ) ;
if ( V_2 -> V_91 ++ == 0 ) {
if ( F_5 ( V_9 ) )
F_59 ( V_10 , V_106 ) ;
else
F_56 ( V_10 , V_107 ) ;
}
F_64 ( & V_2 -> V_90 ) ;
return true ;
}
static void
F_75 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
F_62 ( & V_2 -> V_90 ) ;
if ( -- V_2 -> V_91 == 0 ) {
if ( F_5 ( V_9 ) )
F_60 ( V_10 , V_106 ) ;
else
F_58 ( V_10 , V_107 ) ;
}
F_64 ( & V_2 -> V_90 ) ;
}
static int
F_76 ( struct V_1 * V_2 , T_1 V_108 , T_1 V_109 )
{
int V_17 ;
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 ,
V_110 | ( 2 << 6 ) |
V_111 ) ;
F_8 ( V_2 , V_108 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_77 ( struct V_1 * V_2 ,
T_1 V_108 , T_1 V_112 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_17 ;
if ( F_78 ( V_9 ) || F_79 ( V_9 ) ) {
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_113 ) ;
F_8 ( V_2 , V_108 | V_114 ) ;
F_8 ( V_2 , V_108 + V_112 - 8 ) ;
F_8 ( V_2 , 0 ) ;
} else {
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
if ( F_4 ( V_9 ) -> V_21 >= 4 ) {
F_8 ( V_2 ,
V_110 | ( 2 << 6 ) |
V_111 ) ;
F_8 ( V_2 , V_108 ) ;
} else {
F_8 ( V_2 ,
V_110 | ( 2 << 6 ) ) ;
F_8 ( V_2 , V_108 | V_114 ) ;
}
}
F_9 ( V_2 ) ;
return 0 ;
}
static void F_80 ( struct V_1 * V_2 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
struct V_33 * V_34 ;
V_34 = V_2 -> V_102 . V_34 ;
if ( V_34 == NULL )
return;
F_37 ( V_34 -> V_54 [ 0 ] ) ;
F_33 ( V_34 ) ;
F_34 ( & V_34 -> V_56 ) ;
V_2 -> V_102 . V_34 = NULL ;
memset ( & V_10 -> V_115 , 0 , sizeof( V_10 -> V_115 ) ) ;
}
static int F_81 ( struct V_1 * V_2 )
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
F_30 ( V_34 , V_51 ) ;
V_17 = F_31 ( V_34 , 4096 , true ) ;
if ( V_17 != 0 ) {
goto V_52;
}
V_2 -> V_102 . V_103 = V_34 -> V_36 ;
V_2 -> V_102 . V_116 = F_32 ( V_34 -> V_54 [ 0 ] ) ;
if ( V_2 -> V_102 . V_116 == NULL ) {
memset ( & V_10 -> V_115 , 0 , sizeof( V_10 -> V_115 ) ) ;
goto V_55;
}
V_2 -> V_102 . V_34 = V_34 ;
memset ( V_2 -> V_102 . V_116 , 0 , V_38 ) ;
F_66 ( V_2 ) ;
F_82 ( L_7 ,
V_2 -> V_37 , V_2 -> V_102 . V_103 ) ;
return 0 ;
V_55:
F_33 ( V_34 ) ;
V_52:
F_34 ( & V_34 -> V_56 ) ;
V_50:
return V_17 ;
}
int F_83 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_33 * V_34 ;
int V_17 ;
V_2 -> V_9 = V_9 ;
F_84 ( & V_2 -> V_117 ) ;
F_84 ( & V_2 -> V_118 ) ;
F_84 ( & V_2 -> V_119 ) ;
F_85 ( & V_2 -> V_120 ) ;
F_86 ( & V_2 -> V_90 ) ;
V_2 -> V_87 = ~ 0 ;
if ( F_87 ( V_9 ) ) {
V_17 = F_81 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
V_34 = F_29 ( V_9 , V_2 -> V_7 ) ;
if ( V_34 == NULL ) {
F_24 ( L_8 ) ;
V_17 = - V_49 ;
goto V_121;
}
V_2 -> V_34 = V_34 ;
V_17 = F_31 ( V_34 , V_38 , true ) ;
if ( V_17 )
goto V_52;
V_2 -> V_122 . V_7 = V_2 -> V_7 ;
V_2 -> V_122 . V_108 = V_9 -> V_123 -> V_56 + V_34 -> V_36 ;
V_2 -> V_122 . type = 0 ;
V_2 -> V_122 . V_124 = 0 ;
V_2 -> V_122 . V_125 = 0 ;
F_88 ( & V_2 -> V_122 , V_9 ) ;
if ( V_2 -> V_122 . V_126 == NULL ) {
F_24 ( L_9 ) ;
V_17 = - V_127 ;
goto V_55;
}
V_2 -> V_128 = V_2 -> V_122 . V_126 ;
V_17 = V_2 -> V_129 ( V_2 ) ;
if ( V_17 )
goto V_130;
V_2 -> V_131 = V_2 -> V_7 ;
if ( F_78 ( V_2 -> V_9 ) )
V_2 -> V_131 -= 128 ;
return 0 ;
V_130:
F_89 ( & V_2 -> V_122 , V_9 ) ;
V_55:
F_33 ( V_34 ) ;
V_52:
F_34 ( & V_34 -> V_56 ) ;
V_2 -> V_34 = NULL ;
V_121:
F_80 ( V_2 ) ;
return V_17 ;
}
void F_90 ( struct V_1 * V_2 )
{
struct V_57 * V_10 ;
int V_17 ;
if ( V_2 -> V_34 == NULL )
return;
V_10 = V_2 -> V_9 -> V_11 ;
V_17 = F_91 ( V_2 ) ;
if ( V_17 )
F_24 ( L_10 ,
V_2 -> V_37 , V_17 ) ;
F_16 ( V_2 , 0 ) ;
F_89 ( & V_2 -> V_122 , V_2 -> V_9 ) ;
F_33 ( V_2 -> V_34 ) ;
F_34 ( & V_2 -> V_34 -> V_56 ) ;
V_2 -> V_34 = NULL ;
if ( V_2 -> V_132 )
V_2 -> V_132 ( V_2 ) ;
F_80 ( V_2 ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
unsigned int * V_133 ;
int V_134 = V_2 -> V_7 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_134 ) {
int V_17 = F_93 ( V_2 , V_134 ) ;
if ( V_17 )
return V_17 ;
}
V_133 = ( unsigned int * ) ( V_2 -> V_128 + V_2 -> V_6 ) ;
V_134 /= 8 ;
while ( V_134 -- ) {
* V_133 ++ = V_28 ;
* V_133 ++ = V_28 ;
}
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
int F_93 ( struct V_1 * V_2 , int V_135 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_57 * V_10 = V_9 -> V_11 ;
unsigned long V_136 ;
T_1 V_4 ;
V_4 = F_54 ( V_2 , 4 ) ;
if ( V_4 > V_2 -> V_4 ) {
V_2 -> V_4 = V_4 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_135 )
return 0 ;
}
F_94 ( V_2 ) ;
V_136 = V_137 + 3 * V_138 ;
do {
V_2 -> V_4 = F_19 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_135 ) {
F_95 ( V_2 ) ;
return 0 ;
}
if ( V_9 -> V_139 -> V_140 ) {
struct V_141 * V_142 = V_9 -> V_139 -> V_140 -> V_143 ;
if ( V_142 -> V_144 )
V_142 -> V_144 -> V_145 |= V_146 ;
}
F_96 ( 1 ) ;
if ( F_97 ( & V_10 -> V_147 . V_148 ) )
return - V_149 ;
} while ( ! F_98 ( V_137 , V_136 ) );
F_95 ( V_2 ) ;
return - V_150 ;
}
int F_7 ( struct V_1 * V_2 ,
int V_151 )
{
struct V_57 * V_10 = V_2 -> V_9 -> V_11 ;
int V_135 = 4 * V_151 ;
int V_17 ;
if ( F_99 ( F_97 ( & V_10 -> V_147 . V_148 ) ) )
return - V_42 ;
if ( F_99 ( V_2 -> V_6 + V_135 > V_2 -> V_131 ) ) {
V_17 = F_92 ( V_2 ) ;
if ( F_99 ( V_17 ) )
return V_17 ;
}
if ( F_99 ( V_2 -> V_3 < V_135 ) ) {
V_17 = F_93 ( V_2 , V_135 ) ;
if ( F_99 ( V_17 ) )
return V_17 ;
}
V_2 -> V_3 -= V_135 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_6 &= V_2 -> V_7 - 1 ;
V_2 -> V_35 ( V_2 , V_2 -> V_6 ) ;
}
static void F_100 ( struct V_1 * V_2 ,
T_1 V_29 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
F_41 ( V_152 ,
V_153 |
V_154 ) ;
F_41 ( V_155 , 0x0 ) ;
if ( F_101 ( ( F_14 ( V_152 ) &
V_156 ) == 0 ,
50 ) )
F_24 ( L_11 ) ;
F_11 ( V_2 , V_29 ) ;
F_41 ( V_152 ,
V_153 |
V_157 ) ;
}
static int F_102 ( struct V_1 * V_2 ,
T_1 V_158 , T_1 V_159 )
{
T_3 V_16 ;
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_16 = V_160 ;
if ( V_158 & V_161 )
V_16 |= V_162 | V_163 ;
F_8 ( V_2 , V_16 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_103 ( struct V_1 * V_2 ,
T_1 V_108 , T_1 V_112 )
{
int V_17 ;
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_110 | V_111 ) ;
F_8 ( V_2 , V_108 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static bool
F_104 ( struct V_1 * V_2 )
{
return F_71 ( V_2 ,
V_93 ,
V_164 ) ;
}
static void
F_105 ( struct V_1 * V_2 )
{
return F_73 ( V_2 ,
V_93 ,
V_164 ) ;
}
static bool
F_106 ( struct V_1 * V_2 )
{
return F_71 ( V_2 ,
V_165 ,
V_166 ) ;
}
static void
F_107 ( struct V_1 * V_2 )
{
return F_73 ( V_2 ,
V_165 ,
V_166 ) ;
}
static bool
F_108 ( struct V_1 * V_2 )
{
return F_71 ( V_2 ,
V_167 ,
V_168 ) ;
}
static void
F_109 ( struct V_1 * V_2 )
{
F_73 ( V_2 ,
V_167 ,
V_168 ) ;
}
static inline struct V_33 *
F_110 ( struct V_1 * V_2 )
{
return V_2 -> V_47 ;
}
static int F_111 ( struct V_1 * V_2 )
{
if ( F_112 ( V_2 -> V_9 ) ) {
struct V_33 * V_34 ;
T_1 * V_169 ;
int V_17 ;
V_34 = F_29 ( V_2 -> V_9 , 4096 ) ;
if ( V_34 == NULL )
return - V_49 ;
V_17 = F_31 ( V_34 , 4096 , true ) ;
if ( V_17 ) {
F_34 ( & V_34 -> V_56 ) ;
return V_17 ;
}
V_169 = F_32 ( V_34 -> V_54 [ 0 ] ) ;
* V_169 ++ = V_170 ;
* V_169 ++ = V_28 ;
F_37 ( V_34 -> V_54 [ 0 ] ) ;
V_17 = F_113 ( V_34 , false ) ;
if ( V_17 ) {
F_33 ( V_34 ) ;
F_34 ( & V_34 -> V_56 ) ;
return V_17 ;
}
V_2 -> V_47 = V_34 ;
}
return F_15 ( V_2 ) ;
}
static int F_114 ( struct V_1 * V_2 ,
int V_151 )
{
if ( V_2 -> V_47 ) {
int V_17 = F_7 ( V_2 , V_151 + 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_110 ) ;
F_8 ( V_2 , F_110 ( V_2 ) -> V_36 ) ;
return 0 ;
} else
return F_7 ( V_2 , 4 ) ;
}
static int F_115 ( struct V_1 * V_2 ,
T_1 V_158 , T_1 V_159 )
{
T_3 V_16 ;
int V_17 ;
V_17 = F_114 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_16 = V_160 ;
if ( V_158 & V_20 )
V_16 |= V_162 ;
F_8 ( V_2 , V_16 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static void F_116 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_47 )
return;
F_33 ( V_2 -> V_47 ) ;
F_34 ( V_2 -> V_47 ) ;
V_2 -> V_47 = NULL ;
}
int F_117 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_171 ] ;
* V_2 = V_172 ;
if ( F_4 ( V_9 ) -> V_21 >= 6 ) {
V_2 -> V_173 = F_47 ;
V_2 -> V_174 = F_104 ;
V_2 -> V_175 = F_105 ;
} else if ( F_6 ( V_9 ) ) {
V_2 -> V_173 = F_50 ;
V_2 -> V_176 = F_55 ;
}
if ( ! F_87 ( V_9 ) ) {
V_2 -> V_102 . V_116 = V_10 -> V_177 -> V_178 ;
memset ( V_2 -> V_102 . V_116 , 0 , V_38 ) ;
}
return F_83 ( V_9 , V_2 ) ;
}
int F_118 ( struct V_8 * V_9 , T_4 V_179 , T_1 V_7 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_171 ] ;
* V_2 = V_172 ;
if ( F_4 ( V_9 ) -> V_21 >= 6 ) {
V_2 -> V_173 = F_47 ;
V_2 -> V_174 = F_104 ;
V_2 -> V_175 = F_105 ;
} else if ( F_6 ( V_9 ) ) {
V_2 -> V_173 = F_50 ;
V_2 -> V_176 = F_55 ;
}
if ( ! F_87 ( V_9 ) )
V_2 -> V_102 . V_116 = V_10 -> V_177 -> V_178 ;
V_2 -> V_9 = V_9 ;
F_84 ( & V_2 -> V_117 ) ;
F_84 ( & V_2 -> V_118 ) ;
F_84 ( & V_2 -> V_119 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_131 = V_2 -> V_7 ;
if ( F_78 ( V_2 -> V_9 ) )
V_2 -> V_131 -= 128 ;
V_2 -> V_122 . V_108 = V_179 ;
V_2 -> V_122 . V_7 = V_7 ;
V_2 -> V_122 . type = 0 ;
V_2 -> V_122 . V_124 = 0 ;
V_2 -> V_122 . V_125 = 0 ;
F_88 ( & V_2 -> V_122 , V_9 ) ;
if ( V_2 -> V_122 . V_126 == NULL ) {
F_24 ( L_12
L_13 ) ;
return - V_49 ;
}
V_2 -> V_128 = ( void V_180 V_181 * ) V_2 -> V_122 . V_126 ;
return 0 ;
}
int F_119 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_182 ] ;
if ( F_39 ( V_9 ) || F_40 ( V_9 ) )
* V_2 = V_183 ;
else
* V_2 = V_184 ;
return F_83 ( V_9 , V_2 ) ;
}
int F_120 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_185 ] ;
* V_2 = V_186 ;
return F_83 ( V_9 , V_2 ) ;
}
