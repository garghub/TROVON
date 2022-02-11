static struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_1 * V_5 ;
if ( F_2 ( & V_3 -> V_4 ) )
return NULL ;
F_3 (entry, &mci->info, list) {
if ( V_5 -> V_6 == V_4 -> V_6 )
return V_5 ;
}
return NULL ;
}
static bool F_4 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_1 * V_5 ;
if ( ( V_3 -> V_9 == V_10 ) &&
( V_4 -> type == V_11 ) )
return false ;
if ( ( ( F_5 ( V_3 ) - V_3 -> V_9 ) == V_12 ) &&
( V_4 -> type != V_11 ) )
return false ;
V_5 = F_6 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 )
return false ;
memcpy ( V_5 , V_4 , 10 ) ;
F_7 ( V_3 , V_4 ) ;
F_8 ( & V_5 -> V_14 , & V_3 -> V_4 ) ;
return true ;
}
static void F_9 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( ! V_5 )
return;
F_10 ( V_3 , V_5 ) ;
F_11 ( & V_5 -> V_14 ) ;
F_12 ( V_5 ) ;
}
void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_15 ;
V_3 -> V_16 = 0 ;
V_3 -> V_17 = 0 ;
if ( F_2 ( & V_3 -> V_4 ) )
return;
F_14 (info, tinfo, &mci->info, list) {
F_11 ( & V_4 -> V_14 ) ;
F_10 ( V_3 , V_4 ) ;
F_12 ( V_4 ) ;
}
}
static void F_15 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = & V_19 -> V_3 ;
T_1 V_20 = V_19 -> V_21 *
( 100 - V_19 -> V_22 ) / 100 ;
if ( ( V_20 <= 4 ) &&
( ! V_3 -> V_16 || ( V_3 -> V_16 > ( 2 * V_20 ) ) ) )
V_3 -> V_16 = 2 * V_20 ;
}
static void F_16 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = F_17 ( V_24 -> V_25 ) ;
struct V_18 * V_19 = & V_24 -> V_19 ;
struct V_2 * V_3 = & V_19 -> V_3 ;
struct V_26 * V_27 = & V_24 -> V_25 -> V_28 . V_3 ;
struct V_1 * V_4 ;
T_1 V_29 = F_5 ( V_3 ) ;
if ( V_27 -> V_30 & V_31 )
goto V_32;
V_3 -> V_16 = 0 ;
V_19 -> V_22 = V_33 [ V_29 ] ;
V_19 -> V_21 = V_34 ;
if ( F_5 ( V_3 ) )
V_19 -> V_35 = V_36 ;
else
V_19 -> V_35 = V_3 -> V_17 ? V_37 :
V_36 ;
if ( V_29 == 1 ) {
V_4 = F_18 ( & V_3 -> V_4 ,
struct V_1 ,
V_14 ) ;
if ( V_3 -> V_9 ) {
if ( V_4 -> V_38 == 12 )
V_3 -> V_16 = 8 ;
else if ( V_4 -> V_38 == 6 ) {
V_3 -> V_16 = 6 ;
V_19 -> V_22 = 30 ;
} else
V_3 -> V_16 = 6 ;
F_19 ( V_8 , V_39 ,
L_1 ,
V_3 -> V_16 ) ;
} else if ( V_3 -> V_40 || V_3 -> V_41 ) {
V_19 -> V_22 = 35 ;
V_19 -> V_21 = 53 ;
F_19 ( V_8 , V_39 ,
L_2 ,
V_19 -> V_22 , V_19 -> V_21 ) ;
} else if ( V_3 -> V_42 ) {
V_19 -> V_22 = 30 ;
V_3 -> V_16 = 6 ;
F_19 ( V_8 , V_39 ,
L_3
L_4 ) ;
}
} else if ( V_29 == 2 ) {
if ( V_3 -> V_42 == 2 )
V_19 -> V_22 = 30 ;
V_3 -> V_16 = 6 ;
F_19 ( V_8 , V_39 ,
L_5 ,
V_19 -> V_22 ) ;
} else if ( V_29 >= 3 ) {
V_3 -> V_16 = 4 ;
F_19 ( V_8 , V_39 ,
L_6 ) ;
}
V_32:
if ( F_20 ( V_24 -> V_25 -> V_43 ) ) {
if ( F_21 ( V_24 -> V_25 -> V_43 ) )
F_15 ( V_19 ) ;
else
V_19 -> V_21 >>= 1 ;
}
F_22 ( V_24 ) ;
F_23 ( V_24 -> V_25 ) ;
if ( F_24 ( V_24 -> V_25 -> V_43 ) )
return;
V_19 -> V_22 += ( V_3 -> V_44 ? V_45 : 0 ) ;
if ( V_19 -> V_22 > V_46 )
V_19 -> V_22 = V_46 ;
V_19 -> V_47 = V_19 -> V_21 * 1000 *
( 100 - V_19 -> V_22 ) / 100 ;
F_25 ( V_24 -> V_25 ) ;
F_26 ( V_24 ) ;
}
static void F_27 ( struct V_23 * V_24 )
{
struct V_48 * V_49 = V_24 -> V_25 ;
F_28 ( V_24 -> V_50 ) ;
F_29 ( V_24 ) ;
F_30 ( V_24 , false ) ;
F_31 ( V_49 , V_49 -> V_43 ) ;
F_32 ( V_24 ) ;
F_33 ( V_24 -> V_50 ) ;
}
static void F_34 ( struct V_23 * V_24 , T_2 V_51 , T_2 * V_52 )
{
struct V_48 * V_49 = V_24 -> V_25 ;
struct V_7 * V_8 = F_17 ( V_49 ) ;
struct V_26 * V_27 = & V_49 -> V_28 . V_3 ;
T_1 V_53 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_51 ) {
case V_54 :
if ( V_27 -> V_55 == V_56 ) {
V_27 -> V_55 = V_57 ;
F_27 ( V_24 ) ;
}
F_19 ( V_8 , V_39 , L_7 , V_27 -> V_55 ) ;
break;
case V_58 :
F_35 ( V_53 , V_59 ) ;
F_36 ( V_24 -> V_25 , V_60 , 0 , V_53 ,
16 , false , true ) ;
break;
default:
F_19 ( V_8 , V_39 , L_8 ) ;
break;
}
}
static void F_37 ( struct V_61 * V_62 )
{
struct V_23 * V_24 = F_38 ( V_62 , struct V_23 , V_63 ) ;
F_16 ( V_24 ) ;
}
static T_2 F_39 ( struct V_23 * V_24 ,
struct V_1 * V_4 )
{
struct V_7 * V_8 = F_17 ( V_24 -> V_25 ) ;
struct V_18 * V_19 = & V_24 -> V_19 ;
struct V_2 * V_3 = & V_19 -> V_3 ;
struct V_1 * V_5 = NULL ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
if ( V_5 -> type != V_4 -> type ) {
F_10 ( V_3 , V_5 ) ;
F_7 ( V_3 , V_4 ) ;
}
memcpy ( V_5 , V_4 , 10 ) ;
}
if ( V_4 -> V_64 ) {
if ( ! V_5 && ! F_4 ( V_8 , V_3 , V_4 ) )
return 0 ;
} else
F_9 ( V_8 , V_3 , V_5 ) ;
return 1 ;
}
static T_2 F_40 ( struct V_23 * V_24 ,
struct V_65 * V_66 )
{
struct V_18 * V_19 = & V_24 -> V_19 ;
struct V_2 * V_3 = & V_19 -> V_3 ;
struct V_1 V_4 ;
int V_67 = 0 , V_68 = V_3 -> V_17 ;
if ( V_66 -> V_69 )
return 0 ;
V_4 . V_6 = V_66 -> V_6 ;
if ( F_1 ( V_3 , & V_4 ) )
return 0 ;
if ( V_66 -> V_6 >= V_70 )
return 0 ;
if ( V_66 -> V_71 )
F_41 ( V_66 -> V_6 , V_3 -> V_66 ) ;
else
F_42 ( V_66 -> V_6 , V_3 -> V_66 ) ;
V_3 -> V_17 = 0 ;
do {
if ( F_43 ( V_67 , V_3 -> V_66 ) )
V_3 -> V_17 ++ ;
} while ( ++ V_67 < V_70 );
if ( V_68 != V_3 -> V_17 )
return 1 ;
return 0 ;
}
static void F_44 ( struct V_23 * V_24 , T_2 V_51 , T_2 * V_52 )
{
struct V_48 * V_49 = V_24 -> V_25 ;
struct V_1 V_72 ;
struct V_65 V_73 ;
struct V_7 * V_8 = F_17 ( V_24 -> V_25 ) ;
T_2 V_74 , V_75 , V_76 = 0 ;
T_1 V_77 ;
if ( F_45 ( V_49 , V_78 ) &&
F_45 ( V_49 , V_79 ) ) {
F_19 ( V_8 , V_39 , L_9 ) ;
F_13 ( & V_24 -> V_19 . V_3 ) ;
F_45 ( V_49 , V_80 ) ;
}
switch ( V_51 ) {
case V_81 :
F_45 ( V_49 , V_82 ) ;
break;
case V_83 :
V_74 = * ( V_52 + V_84 ) ;
V_75 = * ( V_52 + V_85 ) ;
F_46 ( V_49 , V_74 , V_75 ) ;
break;
case V_86 :
F_47 ( V_49 ) ;
break;
case V_87 :
memcpy ( & V_72 ,
( V_52 + V_88 ) , 10 ) ;
if ( ( V_72 . type == V_89 ) ||
( V_72 . type >= V_90 ) ) {
F_19 ( V_8 , V_39 ,
L_10 ,
V_72 . type ,
V_72 . V_64 ) ;
break;
}
V_76 += F_39 ( V_24 , & V_72 ) ;
break;
case V_91 :
V_73 . V_69 = * ( V_52 +
V_92 ) ;
V_73 . V_6 = * ( V_52 +
V_93 ) ;
V_73 . V_71 = * ( V_52 +
V_94 ) ;
V_77 = * ( ( T_1 * ) ( V_52 + 12 ) ) ;
F_19 ( V_8 , V_39 ,
L_11 ,
V_73 . V_69 , V_73 . V_6 ,
V_73 . V_71 , V_77 ) ;
V_76 += F_40 ( V_24 , & V_73 ) ;
break;
default:
F_19 ( V_8 , V_39 , L_12 , V_51 ) ;
break;
}
if ( V_76 )
F_48 ( V_24 -> V_50 , & V_24 -> V_63 ) ;
}
int F_49 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = F_17 ( V_24 -> V_25 ) ;
struct V_95 * V_3 = & V_24 -> V_96 ;
struct V_97 * V_98 = & V_3 -> V_99 ;
int V_100 ;
V_98 -> V_101 = F_50 ( V_24 -> V_102 ,
V_103 + V_104 ,
& V_98 -> V_105 , V_106 ) ;
if ( V_98 -> V_101 == NULL ) {
F_19 ( V_8 , V_107 , L_13 ) ;
return - V_108 ;
}
memset ( V_98 -> V_101 , V_109 ,
V_103 + V_104 ) ;
V_3 -> V_99 . V_110 = V_103 ;
V_3 -> V_111 . V_110 = V_104 ;
V_3 -> V_111 . V_101 = ( T_2 * ) V_3 -> V_99 . V_101 + V_3 -> V_99 . V_110 ;
V_3 -> V_111 . V_105 = V_3 -> V_99 . V_105 + V_3 -> V_99 . V_110 ;
V_100 = F_51 ( V_24 -> V_25 , V_3 -> V_111 . V_105 ,
V_3 -> V_111 . V_101 , ( V_3 -> V_111 . V_110 >> 4 ) ,
V_3 -> V_99 . V_105 ) ;
if ( V_100 ) {
F_52 ( V_8 , L_14 ) ;
return V_100 ;
}
F_53 ( & V_24 -> V_63 , F_37 ) ;
F_19 ( V_8 , V_39 , L_15 ) ;
return 0 ;
}
void F_54 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = F_17 ( V_24 -> V_25 ) ;
struct V_48 * V_49 = V_24 -> V_25 ;
struct V_95 * V_3 = & V_24 -> V_96 ;
struct V_97 * V_98 = & V_3 -> V_99 ;
if ( V_98 -> V_101 )
F_55 ( V_24 -> V_102 ,
V_103 + V_104 ,
V_98 -> V_101 , V_98 -> V_105 ) ;
F_56 ( V_49 ) ;
F_19 ( V_8 , V_39 , L_16 ) ;
}
void F_57 ( struct V_23 * V_24 )
{
struct V_95 * V_3 = & V_24 -> V_96 ;
struct V_48 * V_49 = V_24 -> V_25 ;
struct V_7 * V_8 = F_17 ( V_49 ) ;
struct V_26 * V_27 = & V_49 -> V_28 . V_3 ;
T_1 V_112 , V_113 ;
T_1 V_114 , V_115 , V_51 ;
T_1 * V_116 ;
T_1 V_117 = V_118 ;
bool V_119 = false ;
F_58 ( V_24 -> V_25 , & V_112 , & V_113 ) ;
if ( F_45 ( V_49 , V_79 ) == 0 ) {
F_59 ( V_49 , true , NULL ) ;
return;
}
if ( V_113 & V_120 ) {
T_1 V_53 [ 4 ] = { 0xffffffff , 0xffffffff ,
0xffffffff , 0xffffff00 } ;
F_36 ( V_49 , V_121 , 0 ,
V_53 , 16 , true , false ) ;
F_36 ( V_49 , V_122 , 0 ,
NULL , 0 , true , false ) ;
V_113 &= ~ V_120 ;
F_45 ( V_49 , V_123 ) ;
F_45 ( V_49 , V_124 ) ;
}
if ( V_113 & V_125 ) {
V_113 &= ~ V_125 ;
if ( ( V_27 -> V_55 == V_126 ) &&
( F_45 ( V_49 , V_127 ) !=
V_126 ) )
F_45 ( V_49 , V_124 ) ;
}
if ( V_113 & V_128 ) {
V_113 &= ~ V_128 ;
if ( ( V_27 -> V_55 == V_56 ) &&
( F_45 ( V_49 , V_127 ) !=
V_56 ) )
V_27 -> V_55 = V_126 ;
}
if ( ( V_112 & V_129 ) ||
( V_112 & V_130 ) ) {
F_45 ( V_49 , V_131 ) ;
V_119 = true ;
}
if ( V_113 & V_132 ) {
V_113 &= ~ V_132 ;
V_114 = F_45 ( V_49 , V_133 ) ;
}
if ( V_113 & V_134 ) {
V_113 &= ~ V_134 ;
while ( V_117 == V_118 ) {
V_116 = V_3 -> V_111 . V_101 ;
V_114 = F_59 ( V_49 , false ,
& V_117 ) ;
if ( V_114 == V_135 )
break;
V_116 += ( V_114 >> 2 ) ;
V_115 = F_60 ( V_116 ) ;
V_51 = F_61 ( V_116 ) ;
if ( V_119 )
goto V_136;
if ( F_62 ( V_115 ) ) {
F_34 ( V_24 , V_115 , ( T_2 * ) V_116 ) ;
} else {
switch ( V_115 ) {
case V_137 :
F_44 ( V_24 , V_51 , ( T_2 * ) V_116 ) ;
break;
default:
break;
}
}
V_136:
F_63 ( V_116 ) ;
}
}
if ( V_113 & V_138 ) {
if ( V_113 & V_139 )
V_113 &= ~ V_139 ;
if ( V_113 & V_140 )
V_113 &= ~ V_140 ;
if ( V_113 & V_141 ) {
int V_142 = F_64 ( V_27 -> V_143 ,
V_144 ) ;
V_113 &= ~ V_141 ;
F_19 ( V_8 , V_39 ,
L_17 ,
F_64 ( V_27 -> V_143 , V_145 ) ?
L_18 : L_19 ,
F_64 ( V_27 -> V_143 , V_146 ) ,
V_142 ) ;
}
if ( V_113 & V_147 )
V_113 &= ~ V_147 ;
if ( V_113 & V_148 )
V_113 &= ~ V_148 ;
}
if ( ( V_112 & V_129 ) ||
( V_112 & V_130 ) ) {
V_112 &= ~ ( V_129 |
V_130 ) ;
F_44 ( V_24 , V_149 , NULL ) ;
}
}
void F_65 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = F_17 ( V_24 -> V_25 ) ;
if ( ! V_8 -> V_150 )
return;
if ( V_24 -> V_25 -> V_151 . V_152 & V_153 )
V_24 -> V_25 -> V_154 |= V_155 ;
}
