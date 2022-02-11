static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 , V_8 ;
T_2 V_9 ;
V_8 = F_2 ( V_6 , V_10 ) ;
V_7 = F_2 ( V_6 , V_11 ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
* V_4 = F_3 ( V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_9 = F_5 ( V_4 ) ;
F_6 ( V_6 , V_10 , V_9 & 0xFFFFFFFF ) ;
F_6 ( V_6 , V_11 , V_9 >> 32 ) ;
}
static void F_7 ( struct V_12 * V_13 ,
T_2 V_14 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_15 = F_8 ( V_14 ) ;
}
static int F_9 ( struct V_16 * V_17 , T_3 V_18 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_19 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_20 , V_21 , V_22 ;
int V_23 = 0 ;
if ( V_18 < 0 ) {
V_23 = 1 ;
V_18 = - V_18 ;
}
F_11 () ;
V_20 = F_12 ( V_2 -> V_24 ) ;
V_21 = V_20 ;
V_21 *= V_18 ;
V_22 = F_13 ( V_21 , 1000000000ULL ) ;
if ( V_23 )
V_20 -= V_22 ;
else
V_20 += V_22 ;
F_6 ( V_6 , V_25 , V_20 & 0xFFFFFFFF ) ;
F_6 ( V_6 , V_26 , V_20 >> 32 ) ;
return 0 ;
}
static int F_14 ( struct V_16 * V_17 , T_4 V_27 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_19 ) ;
struct V_3 V_28 , V_29 = F_3 ( V_27 ) ;
unsigned long V_30 ;
F_15 ( & V_2 -> V_31 , V_30 ) ;
F_1 ( V_2 , & V_28 ) ;
V_28 = F_16 ( V_28 , V_29 ) ;
F_4 ( V_2 , ( const struct V_3 * ) & V_28 ) ;
F_17 ( & V_2 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_18 ( struct V_16 * V_17 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_19 ) ;
unsigned long V_30 ;
F_15 ( & V_2 -> V_31 , V_30 ) ;
F_1 ( V_2 , V_4 ) ;
F_17 ( & V_2 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_19 ( struct V_16 * V_17 ,
const struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_17 , struct V_1 , V_19 ) ;
unsigned long V_30 ;
F_15 ( & V_2 -> V_31 , V_30 ) ;
F_4 ( V_2 , V_4 ) ;
F_17 ( & V_2 -> V_31 , V_30 ) ;
return 0 ;
}
static int F_20 ( struct V_16 * V_17 ,
struct V_32 * V_33 , int V_34 )
{
return - V_35 ;
}
void F_21 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_38 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_39 * V_40 ;
unsigned long V_41 ;
T_1 V_42 ;
int V_43 ;
if ( V_2 -> V_30 & V_44 )
return;
V_42 = F_2 ( V_6 , V_45 ) ;
if ( ! ( V_42 & ( ( V_46 <<
V_47 ) |
( V_48 <<
V_49 ) |
( V_50 <<
V_51 ) |
( V_52 <<
V_53 ) ) ) ) {
V_2 -> V_54 = V_55 ;
return;
}
V_41 = V_2 -> V_54 ;
for ( V_43 = 0 ; V_43 < V_37 -> V_56 ; V_43 ++ ) {
V_40 = V_37 -> V_57 [ V_43 ] ;
if ( F_22 ( V_40 -> V_58 , V_41 ) )
V_41 = V_40 -> V_58 ;
}
if ( F_23 ( V_41 + 5 * V_59 ) ) {
F_2 ( V_6 , F_24 ( 0 ) ) ;
F_2 ( V_6 , F_24 ( 1 ) ) ;
F_2 ( V_6 , F_24 ( 2 ) ) ;
F_2 ( V_6 , F_24 ( 3 ) ) ;
V_2 -> V_54 = V_55 ;
V_2 -> V_60 ++ ;
F_25 ( & V_37 -> V_38 -> V_61 -> V_62 ,
L_1 ,
V_63 ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
struct V_12 V_64 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_1 V_7 , V_8 ;
T_2 V_9 ;
V_8 = F_2 ( V_6 , V_65 ) ;
V_7 = F_2 ( V_6 , V_66 ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( & V_64 , V_9 ) ;
F_27 ( V_2 -> V_67 , & V_64 ) ;
F_28 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
}
void F_29 ( struct V_1 * V_2 , struct V_68 * V_69 , T_5 V_70 )
{
T_1 V_42 , V_7 , V_8 ;
struct V_5 * V_6 ;
T_2 V_9 ;
if ( ! V_2 -> V_71 )
return;
V_6 = & V_2 -> V_6 ;
V_42 = F_2 ( V_6 , V_45 ) ;
if ( ! ( V_42 & ( 1 << V_70 ) ) )
return;
V_8 = F_2 ( V_6 , F_30 ( V_70 ) ) ;
V_7 = F_2 ( V_6 , F_24 ( V_70 ) ) ;
V_9 = ( ( ( T_2 ) V_7 ) << 32 ) | V_8 ;
F_7 ( F_31 ( V_69 ) , V_9 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_72 * V_73 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
T_2 V_74 ;
V_73 = & V_6 -> V_75 . V_76 ;
F_33 ( & V_2 -> V_6 , true , NULL , NULL ) ;
switch ( V_73 -> V_77 ) {
case V_78 :
V_74 = V_79 ;
break;
case V_80 :
V_74 = V_81 ;
break;
case V_82 :
F_25 ( & V_2 -> V_61 -> V_62 ,
L_2 ,
V_63 ) ;
V_74 = 0 ;
break;
case V_83 :
default:
V_74 = V_84 ;
break;
}
F_6 ( V_6 , V_25 , V_74 & 0xFFFFFFFF ) ;
F_6 ( V_6 , V_26 , V_74 >> 32 ) ;
F_12 ( V_2 -> V_24 ) = V_74 ;
F_11 () ;
}
int F_34 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
struct V_87 * V_88 = & V_2 -> V_89 ;
return F_35 ( V_86 -> V_90 , V_88 , sizeof( * V_88 ) ) ?
- V_91 : 0 ;
}
int F_36 ( struct V_1 * V_2 , struct V_85 * V_86 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_87 * V_88 = & V_2 -> V_89 ;
T_1 V_92 , V_93 , V_94 ;
if ( F_37 ( V_88 , V_86 -> V_90 , sizeof( * V_88 ) ) )
return - V_91 ;
if ( V_88 -> V_30 )
return - V_95 ;
V_92 = ( F_2 ( V_6 , V_96 ) & V_97 ) >>
V_98 ;
if ( V_6 -> V_92 != V_92 )
return - V_95 ;
switch ( V_88 -> V_99 ) {
case V_100 :
V_2 -> V_101 = false ;
break;
case V_102 :
V_2 -> V_101 = true ;
break;
default:
return - V_103 ;
}
switch ( V_88 -> V_104 ) {
case V_105 :
V_2 -> V_71 = false ;
V_93 = 0 ;
break;
case V_106 :
case V_107 :
case V_108 :
V_2 -> V_71 = true ;
V_93 = V_109 |
V_110 |
V_111 ;
V_88 -> V_104 = V_108 ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_2 -> V_71 = true ;
V_93 = V_121 |
V_122 |
V_111 ;
V_88 -> V_104 = V_112 ;
break;
case V_123 :
default:
return - V_103 ;
}
F_2 ( V_6 , V_124 ) ;
F_2 ( V_6 , V_66 ) ;
F_2 ( V_6 , F_24 ( 0 ) ) ;
F_2 ( V_6 , F_24 ( 1 ) ) ;
F_2 ( V_6 , F_24 ( 2 ) ) ;
F_2 ( V_6 , F_24 ( 3 ) ) ;
V_94 = F_2 ( V_6 , V_96 ) ;
if ( V_2 -> V_101 )
V_94 |= V_125 ;
else
V_94 &= ~ V_125 ;
F_6 ( V_6 , V_96 , V_94 ) ;
V_94 = F_2 ( V_6 , V_126 ) ;
if ( V_2 -> V_101 )
V_94 |= V_127 ;
else
V_94 &= ~ V_127 ;
F_6 ( V_6 , V_126 , V_94 ) ;
if ( V_2 -> V_71 ) {
V_94 = F_2 ( V_6 , V_128 ) ;
V_94 &= V_129 ;
V_94 |= V_93 ;
F_6 ( V_6 , V_128 , V_94 ) ;
}
return F_35 ( V_86 -> V_90 , V_88 , sizeof( * V_88 ) ) ?
- V_91 : 0 ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_130 * V_131 = V_2 -> V_37 [ V_2 -> V_132 ] -> V_131 ;
strncpy ( V_2 -> V_19 . V_133 , L_3 , sizeof( V_2 -> V_19 . V_133 ) ) ;
V_2 -> V_19 . V_134 = V_135 ;
V_2 -> V_19 . V_136 = 999999999 ;
V_2 -> V_19 . V_137 = 0 ;
V_2 -> V_19 . V_138 = 0 ;
V_2 -> V_19 . V_139 = F_9 ;
V_2 -> V_19 . V_140 = F_14 ;
V_2 -> V_19 . V_141 = F_18 ;
V_2 -> V_19 . V_142 = F_19 ;
V_2 -> V_19 . V_143 = F_20 ;
V_2 -> V_144 = F_39 ( & V_2 -> V_19 , & V_2 -> V_61 -> V_62 ) ;
if ( F_40 ( V_2 -> V_144 ) ) {
V_2 -> V_144 = NULL ;
F_41 ( & V_2 -> V_61 -> V_62 , L_4 ,
V_63 ) ;
} else {
struct V_3 V_4 ;
T_1 V_94 ;
F_42 ( & V_2 -> V_31 ) ;
F_43 ( & V_2 -> V_61 -> V_62 , L_5 , V_63 ,
V_131 -> V_133 ) ;
V_2 -> V_30 |= V_44 ;
V_94 = F_2 ( V_6 , V_96 ) ;
V_94 |= V_145 ;
F_6 ( V_6 , V_96 , V_94 ) ;
V_94 = F_2 ( V_6 , V_128 ) ;
V_94 |= V_129 ;
F_6 ( V_6 , V_128 , V_94 ) ;
F_32 ( V_2 ) ;
memset ( & V_2 -> V_89 , 0 , sizeof( V_2 -> V_89 ) ) ;
V_4 = F_44 ( F_45 () ) ;
F_19 ( & V_2 -> V_19 , & V_4 ) ;
}
}
void F_46 ( struct V_1 * V_2 )
{
V_2 -> V_30 &= ~ V_44 ;
V_2 -> V_101 = false ;
V_2 -> V_71 = false ;
if ( V_2 -> V_67 ) {
F_28 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
}
if ( V_2 -> V_144 ) {
F_47 ( V_2 -> V_144 ) ;
V_2 -> V_144 = NULL ;
F_43 ( & V_2 -> V_61 -> V_62 , L_6 , V_63 ,
V_2 -> V_37 [ V_2 -> V_132 ] -> V_131 -> V_133 ) ;
}
}
