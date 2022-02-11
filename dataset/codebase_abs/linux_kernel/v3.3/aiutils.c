static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 =
F_2 ( V_2 -> V_4 , V_5 , NULL ,
NULL ) ;
if ( ! V_3 )
return false ;
return true ;
}
static bool F_3 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
F_4 ( & V_2 -> V_6 , V_7 | V_8 , V_9 ) ;
return true ;
}
static bool
F_5 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_10 * V_12 = NULL ;
struct V_10 * V_13 = NULL ;
struct V_10 * V_14 ;
if ( V_11 -> V_15 -> V_16 == 0 )
return false ;
V_2 -> V_6 . V_17 = V_11 -> V_18 . V_19 ;
if ( F_6 ( & V_2 -> V_6 ) >= 11 )
V_2 -> V_20 = F_7 ( V_11 , F_8 ( V_21 ) ) ;
V_2 -> V_6 . V_22 = F_7 ( V_11 , F_8 ( V_23 ) ) ;
if ( F_9 ( & V_2 -> V_6 ) & V_24 ) {
V_2 -> V_6 . V_25 = F_7 ( V_11 ,
F_8 ( V_26 ) ) ;
V_2 -> V_6 . V_27 = V_2 -> V_6 . V_25 & V_28 ;
}
F_10 (core, &cc->bus->cores, list) {
T_2 V_29 , V_30 ;
V_29 = V_14 -> V_18 . V_18 ;
V_30 = V_14 -> V_18 . V_19 ;
if ( V_29 == V_31 ) {
V_12 = V_14 ;
} else if ( V_29 == V_32 ) {
V_13 = V_14 ;
}
}
if ( V_12 && V_13 ) {
if ( F_1 ( V_2 ) )
V_12 = NULL ;
else
V_13 = NULL ;
}
if ( V_12 ) {
V_2 -> V_33 = V_12 ;
} else if ( V_13 ) {
V_2 -> V_33 = V_13 ;
}
if ( ! V_2 -> V_34 ) {
V_2 -> V_34 = F_11 ( & V_2 -> V_6 , V_2 -> V_35 -> V_36 . V_14 ) ;
if ( V_2 -> V_34 == NULL )
return false ;
}
if ( F_12 ( & V_2 -> V_6 ) )
return false ;
return true ;
}
static T_3 void F_13 ( struct V_1 * V_2 )
{
T_2 V_37 = 0 ;
F_14 ( V_2 -> V_4 , V_38 , & V_37 ) ;
V_2 -> V_6 . V_39 = V_37 & 0xffff ;
V_2 -> V_6 . V_40 = ( V_37 >> 16 ) & 0xffff ;
}
static struct V_1 * F_15 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 = & V_2 -> V_6 ;
T_4 V_37 , V_45 ;
struct V_10 * V_11 ;
T_2 V_46 ;
V_45 = 0 ;
V_2 -> V_35 = V_42 ;
V_2 -> V_4 = V_42 -> V_47 ;
V_11 = V_42 -> V_48 . V_14 ;
if ( ! F_3 ( V_2 ) )
return NULL ;
V_37 = F_7 ( V_11 , F_8 ( V_49 ) ) ;
V_46 = ( V_37 & V_50 ) >> V_51 ;
V_44 -> V_52 = V_37 & V_53 ;
V_44 -> V_54 = ( V_37 & V_55 ) >> V_56 ;
V_44 -> V_57 = ( V_37 & V_58 ) >> V_59 ;
if ( V_46 != V_60 )
return NULL ;
F_16 ( L_1 , V_37 ) ;
if ( ! F_5 ( V_2 , V_11 ) )
goto exit;
if ( F_17 ( & V_2 -> V_6 ) )
goto exit;
F_13 ( V_2 ) ;
F_18 ( V_11 , F_8 ( V_61 ) , 0 ) ;
F_18 ( V_11 , F_8 ( V_62 ) , 0 ) ;
if ( F_9 ( V_44 ) & V_24 ) {
F_19 ( V_44 ) ;
( void ) F_20 ( V_44 ) ;
F_21 ( V_44 ) ;
}
V_37 = F_22 ( V_44 , V_63 ) ;
if ( V_37 == 0 )
V_37 = V_64 ;
F_23 ( V_44 , F_24 ( struct V_65 , V_66 ) ,
~ 0 , V_37 ) ;
if ( F_25 ( V_44 ) )
F_26 ( V_2 -> V_34 , V_67 ) ;
if ( F_27 ( V_44 ) == V_68 ) {
if ( F_28 ( V_44 ) == 0 ) {
F_16 ( L_2 ) ;
F_23 ( V_44 , F_24 ( struct V_65 , V_69 ) ,
V_70 ,
V_70 ) ;
F_29 ( V_44 , 0 , V_71 ,
V_71 ) ;
}
if ( F_28 ( V_44 ) >= 1 ) {
F_16 ( L_3 ) ;
F_29 ( V_44 , 0 , V_72 ,
V_72 ) ;
}
}
if ( F_27 ( V_44 ) == V_73 ) {
F_16 ( L_4 ) ;
F_29 ( V_44 , 0 , V_74 ,
V_74 ) ;
}
return V_2 ;
exit:
if ( V_2 -> V_34 )
F_30 ( V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
return NULL ;
}
struct V_43 *
F_31 ( struct V_41 * V_42 )
{
struct V_1 * V_2 ;
V_2 = F_32 ( sizeof( struct V_1 ) , V_75 ) ;
if ( V_2 == NULL )
return NULL ;
if ( F_15 ( V_2 , V_42 ) == NULL ) {
F_33 ( V_2 ) ;
return NULL ;
}
return (struct V_43 * ) V_2 ;
}
void F_34 ( struct V_43 * V_44 )
{
struct V_1 * V_2 ;
struct V_43 * V_76 = NULL ;
memcpy ( & V_76 , & V_44 , sizeof( struct V_43 * * ) ) ;
V_2 = (struct V_1 * ) V_44 ;
if ( V_2 == NULL )
return;
if ( V_2 -> V_34 )
F_30 ( V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
F_35 ( V_44 ) ;
F_33 ( V_2 ) ;
}
struct V_10 * F_36 ( struct V_43 * V_44 , T_5 V_77 , T_5 V_78 )
{
struct V_10 * V_14 ;
struct V_1 * V_2 ;
T_2 V_79 ;
V_2 = (struct V_1 * ) V_44 ;
V_79 = 0 ;
F_10 (core, &sii->icbus->cores, list)
if ( V_14 -> V_18 . V_18 == V_77 ) {
if ( V_79 == V_78 )
return V_14 ;
V_79 ++ ;
}
return NULL ;
}
T_2 F_23 ( struct V_43 * V_44 , T_2 V_80 , T_4 V_81 , T_4 V_82 )
{
struct V_10 * V_11 ;
T_4 V_37 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_44 ;
V_11 = V_2 -> V_35 -> V_48 . V_14 ;
if ( V_81 || V_82 ) {
F_37 ( V_11 , V_80 , ~ V_81 , V_82 ) ;
}
V_37 = F_7 ( V_11 , V_80 ) ;
return V_37 ;
}
static T_2 F_38 ( struct V_43 * V_44 , struct V_10 * V_11 )
{
struct V_1 * V_2 ;
T_4 V_82 ;
V_2 = (struct V_1 * ) V_44 ;
if ( F_6 ( & V_2 -> V_6 ) < 6 ) {
F_14 ( V_2 -> V_4 , V_83 ,
& V_82 ) ;
if ( V_82 & V_84 )
return V_85 ;
return V_86 ;
} else if ( F_6 ( & V_2 -> V_6 ) < 10 ) {
return F_7 ( V_11 , F_8 ( V_87 ) ) &
V_88 ;
} else
return V_86 ;
}
static T_2 F_39 ( struct V_43 * V_44 , bool V_89 ,
struct V_10 * V_11 )
{
T_4 V_90 ;
T_2 div ;
V_90 = F_38 ( V_44 , V_11 ) ;
if ( F_6 ( V_44 ) < 6 ) {
if ( V_90 == V_85 )
return V_89 ? ( V_91 / 64 )
: ( V_92 / 64 ) ;
else
return V_89 ? ( V_93 / 32 )
: ( V_94 / 32 ) ;
} else if ( F_6 ( V_44 ) < 10 ) {
div = 4 *
( ( ( F_7 ( V_11 , F_8 ( V_87 ) ) &
V_95 ) >> V_96 ) + 1 ) ;
if ( V_90 == V_97 )
return V_89 ? V_98 : V_99 ;
else if ( V_90 == V_86 )
return V_89 ? ( V_93 / div )
: ( V_94 / div ) ;
else if ( V_90 == V_85 )
return V_89 ? ( V_91 / div )
: ( V_92 / div ) ;
} else {
div = F_7 ( V_11 , F_8 ( V_100 ) ) ;
div = 4 * ( ( div >> V_101 ) + 1 ) ;
return V_89 ? V_93 : ( V_94 / div ) ;
}
return 0 ;
}
static void
F_40 ( struct V_43 * V_44 , struct V_10 * V_11 )
{
T_2 V_102 , V_103 , V_90 ;
T_2 V_104 , V_105 ;
V_103 = V_106 ;
V_90 = F_38 ( V_44 , V_11 ) ;
if ( V_90 != V_86 )
V_103 += V_107 ;
V_102 =
F_39 ( V_44 ,
( F_6 ( V_44 ) >= 10 ) ? false : true , V_11 ) ;
V_104 = ( ( V_102 * V_103 ) + 999999 ) / 1000000 ;
V_105 = ( ( V_102 * V_108 ) + 999999 ) / 1000000 ;
F_18 ( V_11 , F_8 ( V_104 ) , V_104 ) ;
F_18 ( V_11 , F_8 ( V_105 ) , V_105 ) ;
}
void F_41 ( struct V_43 * V_44 )
{
struct V_10 * V_11 ;
if ( ! ( F_9 ( V_44 ) & V_109 ) )
return;
V_11 = F_36 ( V_44 , V_110 , 0 ) ;
if ( V_11 == NULL )
return;
if ( F_6 ( V_44 ) >= 10 )
F_37 ( V_11 , F_8 ( V_100 ) , V_111 ,
( V_112 << V_101 ) ) ;
F_40 ( V_44 , V_11 ) ;
}
T_5 F_42 ( struct V_43 * V_44 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
T_2 V_113 ;
T_5 V_114 ;
V_2 = (struct V_1 * ) V_44 ;
if ( F_9 ( V_44 ) & V_24 ) {
V_114 = F_43 ( V_44 ) ;
return V_114 ;
}
if ( ! ( F_9 ( V_44 ) & V_109 ) )
return 0 ;
V_114 = 0 ;
V_11 = F_36 ( V_44 , V_115 , 0 ) ;
if ( V_11 ) {
V_113 = F_39 ( V_44 , false , V_11 ) ;
V_114 = ( ( ( F_7 ( V_11 , F_8 ( V_104 ) ) + 2 )
* 1000000 ) + ( V_113 - 1 ) ) / V_113 ;
}
return V_114 ;
}
int F_4 ( struct V_43 * V_44 , T_2 V_116 , bool V_117 )
{
struct V_1 * V_2 ;
T_4 V_118 , V_119 , V_120 ;
V_2 = (struct V_1 * ) V_44 ;
if ( F_25 ( V_44 ) )
return - 1 ;
F_14 ( V_2 -> V_4 , V_121 , & V_118 ) ;
F_14 ( V_2 -> V_4 , V_83 , & V_119 ) ;
F_14 ( V_2 -> V_4 , V_122 , & V_120 ) ;
if ( V_117 && ( V_118 & V_123 ) )
return 0 ;
if ( V_116 & V_7 )
V_120 |= V_123 ;
if ( V_116 & V_8 )
V_120 |= V_124 ;
if ( V_117 ) {
if ( V_116 & V_7 ) {
V_119 |= V_123 ;
if ( V_116 & V_8 )
V_119 |= V_124 ;
F_44 ( V_2 -> V_4 ,
V_83 , V_119 ) ;
F_44 ( V_2 -> V_4 ,
V_122 , V_120 ) ;
F_45 ( V_107 ) ;
}
if ( V_116 & V_8 ) {
V_119 &= ~ V_124 ;
F_44 ( V_2 -> V_4 ,
V_83 , V_119 ) ;
F_46 ( 2 ) ;
}
} else {
if ( V_116 & V_7 )
V_119 &= ~ V_123 ;
if ( V_116 & V_8 )
V_119 |= V_124 ;
F_44 ( V_2 -> V_4 ,
V_83 , V_119 ) ;
F_44 ( V_2 -> V_4 ,
V_122 , V_120 ) ;
}
return 0 ;
}
static bool F_47 ( struct V_1 * V_2 , T_2 V_125 )
{
struct V_10 * V_11 ;
T_4 V_126 ;
if ( F_6 ( & V_2 -> V_6 ) < 6 )
return false ;
V_11 = F_36 ( & V_2 -> V_6 , V_110 , 0 ) ;
if ( ! ( F_9 ( & V_2 -> V_6 ) & V_109 ) &&
( F_6 ( & V_2 -> V_6 ) < 20 ) )
return V_125 == V_127 ;
switch ( V_125 ) {
case V_127 :
if ( F_6 ( & V_2 -> V_6 ) < 10 ) {
F_4 ( & V_2 -> V_6 , V_7 , V_9 ) ;
F_37 ( V_11 , F_8 ( V_87 ) ,
( V_128 | V_129 | V_130 ) , V_130 ) ;
} else if ( F_6 ( & V_2 -> V_6 ) < 20 ) {
F_48 ( V_11 , F_8 ( V_100 ) , V_131 ) ;
} else {
F_48 ( V_11 , F_8 ( V_132 ) , V_133 ) ;
}
if ( F_9 ( & V_2 -> V_6 ) & V_24 ) {
T_4 V_134 = V_135 ;
F_49 ( ( ( F_7 ( V_11 , F_8 ( V_132 ) ) &
V_134 ) == 0 ) , V_136 ) ;
} else {
F_45 ( V_106 ) ;
}
break;
case V_137 :
if ( F_6 ( & V_2 -> V_6 ) < 10 ) {
V_126 = F_7 ( V_11 , F_8 ( V_87 ) ) ;
V_126 &= ~ ( V_129 | V_130 | V_128 ) ;
if ( ( V_126 & V_88 ) != V_86 )
V_126 |= V_128 ;
F_18 ( V_11 , F_8 ( V_87 ) , V_126 ) ;
if ( V_126 & V_128 )
F_4 ( & V_2 -> V_6 , V_7 , V_138 ) ;
} else if ( F_6 ( & V_2 -> V_6 ) < 20 ) {
F_50 ( V_11 , F_8 ( V_100 ) , ~ V_131 ) ;
} else {
F_50 ( V_11 , F_8 ( V_132 ) , ~ V_133 ) ;
}
break;
default:
break;
}
return V_125 == V_127 ;
}
bool F_51 ( struct V_43 * V_44 , T_2 V_125 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_44 ;
if ( F_6 ( V_44 ) < 6 )
return false ;
if ( F_52 ( V_44 ) )
return V_125 == V_127 ;
return F_47 ( V_2 , V_125 ) ;
}
void F_53 ( struct V_43 * V_44 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_44 ;
if ( F_52 ( V_44 ) )
F_47 ( V_2 , V_127 ) ;
if ( F_25 ( V_44 ) )
F_54 ( V_2 -> V_34 , V_139 ) ;
}
void F_55 ( struct V_43 * V_44 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_44 ;
F_56 ( V_2 -> V_34 ) ;
}
void F_57 ( struct V_43 * V_44 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_44 ;
if ( F_52 ( V_44 ) )
F_47 ( V_2 , V_137 ) ;
F_58 ( V_2 -> V_34 , V_140 ) ;
}
void F_59 ( struct V_43 * V_44 , T_2 V_141 )
{
struct V_1 * V_2 ;
T_4 V_37 ;
V_2 = (struct V_1 * ) V_44 ;
if ( F_25 ( V_44 ) || ( F_60 ( V_44 ) && ( F_61 ( V_44 ) >= 6 ) ) ) {
F_14 ( V_2 -> V_4 , V_142 , & V_37 ) ;
V_37 |= ( V_141 << V_143 ) ;
F_44 ( V_2 -> V_4 , V_142 , V_37 ) ;
}
if ( F_60 ( V_44 ) ) {
F_62 ( V_2 -> V_34 ) ;
}
}
int F_12 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 ;
F_63 ( V_2 -> V_34 ) ;
F_64 ( V_2 -> V_34 ) ;
return 0 ;
}
T_4 F_65 ( struct V_43 * V_44 , T_4 V_81 , T_4 V_82 , T_1 V_144 )
{
T_2 V_80 ;
V_80 = F_24 ( struct V_65 , V_145 ) ;
return F_23 ( V_44 , V_80 , V_81 , V_82 ) ;
}
void F_66 ( struct V_43 * V_44 , bool V_117 )
{
struct V_10 * V_11 ;
T_4 V_82 ;
V_11 = F_36 ( V_44 , V_115 , 0 ) ;
if ( V_117 ) {
if ( F_67 ( V_44 ) == 9 || F_67 ( V_44 ) == 0xb )
F_48 ( V_11 , F_8 ( V_69 ) ,
V_146 |
V_147 ) ;
else
F_48 ( V_11 , F_8 ( V_69 ) ,
V_146 ) ;
} else {
V_82 &= ~ ( V_146 | V_147 ) ;
F_50 ( V_11 , F_8 ( V_69 ) ,
~ ( V_146 | V_147 ) ) ;
}
}
void F_68 ( struct V_43 * V_44 )
{
struct V_10 * V_11 ;
V_11 = F_36 ( V_44 , V_115 , 0 ) ;
F_48 ( V_11 , F_8 ( V_145 ) , V_148 ) ;
}
bool F_69 ( struct V_43 * V_44 )
{
T_4 V_37 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_44 ;
F_14 ( V_2 -> V_4 , V_149 , & V_37 ) ;
if ( ( V_37 & 0xFFFF ) != V_150 )
return true ;
return false ;
}
bool F_70 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 ;
if ( F_6 ( V_44 ) >= 31 ) {
struct V_10 * V_11 ;
T_4 V_151 ;
if ( ( F_9 ( V_44 ) & V_152 ) == 0 )
return false ;
V_11 = F_36 ( V_44 , V_110 , 0 ) ;
V_151 = F_7 ( V_11 , F_8 ( V_153 ) ) ;
return V_151 & V_154 ;
}
switch ( F_27 ( V_44 ) ) {
case V_73 :
return ( V_2 -> V_20 & V_155 ) != 0 ;
default:
return true ;
}
}
bool F_71 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 ;
switch ( F_27 ( V_44 ) ) {
case V_73 :
return ( V_2 -> V_20 & V_156 ) == 0 ;
case V_68 :
case V_157 :
default:
return false ;
}
}
T_2 F_72 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 ;
return V_2 -> V_33 -> V_18 . V_18 ;
}
T_2 F_61 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 ;
return V_2 -> V_33 -> V_18 . V_19 ;
}
