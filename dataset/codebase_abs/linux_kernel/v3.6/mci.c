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
if ( F_2 ( & V_3 -> V_4 ) )
return;
F_14 (info, tinfo, &mci->info, list) {
F_11 ( & V_4 -> V_14 ) ;
F_10 ( V_3 , V_4 ) ;
F_12 ( V_4 ) ;
}
}
static void F_15 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = & V_18 -> V_3 ;
T_1 V_19 = V_18 -> V_20 *
( 100 - V_18 -> V_21 ) / 100 ;
if ( ( V_19 <= 4 ) &&
( ! V_3 -> V_16 || ( V_3 -> V_16 > ( 2 * V_19 ) ) ) )
V_3 -> V_16 = 2 * V_19 ;
}
static void F_16 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = F_17 ( V_23 -> V_24 ) ;
struct V_17 * V_18 = & V_23 -> V_18 ;
struct V_2 * V_3 = & V_18 -> V_3 ;
struct V_25 * V_26 = & V_23 -> V_24 -> V_27 . V_3 ;
struct V_1 * V_4 ;
T_1 V_28 = F_5 ( V_3 ) ;
if ( V_26 -> V_29 & V_30 )
goto V_31;
V_18 -> V_21 = V_32 [ V_28 ] ;
if ( V_28 == 1 ) {
V_4 = F_18 ( & V_3 -> V_4 ,
struct V_1 ,
V_14 ) ;
if ( V_3 -> V_9 ) {
if ( V_4 -> V_33 == 12 )
V_3 -> V_16 = 8 ;
else if ( V_4 -> V_33 == 6 ) {
V_3 -> V_16 = 6 ;
V_18 -> V_21 = 30 ;
}
F_19 ( V_8 , V_34 ,
L_1 ,
V_3 -> V_16 ) ;
} else if ( V_3 -> V_35 || V_3 -> V_36 ) {
V_18 -> V_21 = 35 ;
V_18 -> V_20 = 53 ;
F_19 ( V_8 , V_34 ,
L_2 ,
V_18 -> V_21 , V_18 -> V_20 ) ;
} else if ( V_3 -> V_37 ) {
V_18 -> V_21 = 30 ;
V_3 -> V_16 = 6 ;
F_19 ( V_8 , V_34 ,
L_3
L_4 ) ;
}
} else if ( V_28 == 2 ) {
if ( V_3 -> V_37 == 2 )
V_18 -> V_21 = 30 ;
V_3 -> V_16 = 6 ;
F_19 ( V_8 , V_34 ,
L_5 ,
V_18 -> V_21 ) ;
} else if ( V_28 >= 3 ) {
V_3 -> V_16 = 4 ;
F_19 ( V_8 , V_34 ,
L_6 ) ;
}
V_31:
if ( F_20 ( V_23 -> V_24 -> V_38 ) ) {
if ( F_21 ( V_23 -> V_24 -> V_38 ) )
F_15 ( V_18 ) ;
else
V_18 -> V_20 >>= 1 ;
}
F_22 ( V_23 ) ;
F_23 ( V_23 -> V_24 ) ;
if ( F_24 ( V_23 -> V_24 -> V_38 ) )
return;
V_18 -> V_21 += ( V_3 -> V_39 ? V_40 : 0 ) ;
if ( V_18 -> V_21 > V_41 )
V_18 -> V_21 = V_41 ;
V_18 -> V_42 = V_18 -> V_20 * 1000 *
( 100 - V_18 -> V_21 ) / 100 ;
F_25 ( V_23 -> V_24 ) ;
F_26 ( V_23 ) ;
}
static void F_27 ( struct V_22 * V_23 , T_2 V_43 , T_2 * V_44 )
{
struct V_45 * V_46 = V_23 -> V_24 ;
struct V_7 * V_8 = F_17 ( V_46 ) ;
struct V_25 * V_26 = & V_46 -> V_27 . V_3 ;
T_1 V_47 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_43 ) {
case V_48 :
if ( V_26 -> V_49 == V_50 ) {
F_28 ( V_46 , V_51 ) ;
F_29 ( V_23 , V_52 ) ;
}
F_19 ( V_8 , V_34 , L_7 , V_26 -> V_49 ) ;
break;
case V_53 :
F_30 ( V_47 , V_54 ) ;
F_31 ( V_23 -> V_24 , V_55 , 0 , V_47 ,
16 , false , true ) ;
break;
default:
F_19 ( V_8 , V_34 , L_8 ) ;
break;
}
}
static void F_32 ( struct V_56 * V_57 )
{
struct V_22 * V_23 = F_33 ( V_57 , struct V_22 , V_58 ) ;
F_16 ( V_23 ) ;
}
static void F_34 ( struct V_22 * V_23 ,
struct V_1 * V_4 )
{
struct V_7 * V_8 = F_17 ( V_23 -> V_24 ) ;
struct V_17 * V_18 = & V_23 -> V_18 ;
struct V_2 * V_3 = & V_18 -> V_3 ;
struct V_1 * V_5 = NULL ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
if ( V_5 -> type != V_4 -> type ) {
F_10 ( V_3 , V_5 ) ;
F_7 ( V_3 , V_4 ) ;
}
memcpy ( V_5 , V_4 , 10 ) ;
}
if ( V_4 -> V_59 ) {
if ( ! V_5 && ! F_4 ( V_8 , V_3 , V_4 ) )
return;
} else
F_9 ( V_8 , V_3 , V_5 ) ;
V_18 -> V_20 = V_60 ;
V_3 -> V_16 = V_3 -> V_9 ? 6 : 0 ;
V_18 -> V_21 = V_32 [ F_5 ( V_3 ) ] ;
if ( F_5 ( V_3 ) )
V_18 -> V_61 = V_62 ;
else
V_18 -> V_61 = V_3 -> V_63 ? V_64 :
V_62 ;
F_35 ( V_23 -> V_65 , & V_23 -> V_58 ) ;
}
static void F_36 ( struct V_22 * V_23 ,
struct V_66 * V_67 )
{
struct V_17 * V_18 = & V_23 -> V_18 ;
struct V_2 * V_3 = & V_18 -> V_3 ;
struct V_1 V_4 ;
int V_68 = 0 , V_69 = V_3 -> V_63 ;
if ( V_67 -> V_70 )
return;
V_4 . V_6 = V_67 -> V_6 ;
if ( F_1 ( V_3 , & V_4 ) )
return;
if ( V_67 -> V_6 >= V_71 )
return;
if ( V_67 -> V_72 )
F_37 ( V_67 -> V_6 , V_3 -> V_67 ) ;
else
F_38 ( V_67 -> V_6 , V_3 -> V_67 ) ;
V_3 -> V_63 = 0 ;
do {
if ( F_39 ( V_68 , V_3 -> V_67 ) )
V_3 -> V_63 ++ ;
} while ( ++ V_68 < V_71 );
if ( V_69 != V_3 -> V_63 )
F_35 ( V_23 -> V_65 , & V_23 -> V_58 ) ;
}
static void F_40 ( struct V_22 * V_23 , T_2 V_43 , T_2 * V_44 )
{
struct V_45 * V_46 = V_23 -> V_24 ;
struct V_1 V_73 ;
struct V_66 V_74 ;
struct V_7 * V_8 = F_17 ( V_23 -> V_24 ) ;
T_2 V_75 , V_76 ;
T_1 V_77 ;
switch ( V_43 ) {
case V_78 :
F_28 ( V_46 , V_79 ) ;
break;
case V_80 :
V_75 = * ( V_44 + V_81 ) ;
V_76 = * ( V_44 + V_82 ) ;
F_41 ( V_46 , V_75 , V_76 ) ;
break;
case V_83 :
F_42 ( V_46 ) ;
break;
case V_84 :
memcpy ( & V_73 ,
( V_44 + V_85 ) , 10 ) ;
if ( ( V_73 . type == V_86 ) ||
( V_73 . type >= V_87 ) ) {
F_19 ( V_8 , V_34 ,
L_9 ,
V_73 . type ,
V_73 . V_59 ) ;
break;
}
F_34 ( V_23 , & V_73 ) ;
break;
case V_88 :
V_74 . V_70 = * ( V_44 +
V_89 ) ;
V_74 . V_6 = * ( V_44 +
V_90 ) ;
V_74 . V_72 = * ( V_44 +
V_91 ) ;
V_77 = * ( ( T_1 * ) ( V_44 + 12 ) ) ;
F_19 ( V_8 , V_34 ,
L_10 ,
V_74 . V_70 , V_74 . V_6 ,
V_74 . V_72 , V_77 ) ;
F_36 ( V_23 , & V_74 ) ;
break;
default:
F_19 ( V_8 , V_34 , L_11 , V_43 ) ;
break;
}
}
int F_43 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = F_17 ( V_23 -> V_24 ) ;
struct V_92 * V_3 = & V_23 -> V_93 ;
struct V_94 * V_95 = & V_3 -> V_96 ;
V_95 -> V_97 = F_44 ( V_23 -> V_98 ,
V_99 + V_100 ,
& V_95 -> V_101 , V_102 ) ;
if ( V_95 -> V_97 == NULL ) {
F_19 ( V_8 , V_103 , L_12 ) ;
return - V_104 ;
}
memset ( V_95 -> V_97 , V_105 ,
V_99 + V_100 ) ;
V_3 -> V_96 . V_106 = V_99 ;
V_3 -> V_107 . V_106 = V_100 ;
V_3 -> V_107 . V_97 = ( T_2 * ) V_3 -> V_96 . V_97 + V_3 -> V_96 . V_106 ;
V_3 -> V_107 . V_101 = V_3 -> V_96 . V_101 + V_3 -> V_96 . V_106 ;
F_45 ( V_23 -> V_24 , V_3 -> V_107 . V_101 ,
V_3 -> V_107 . V_97 , ( V_3 -> V_107 . V_106 >> 4 ) ,
V_3 -> V_96 . V_101 ) ;
F_46 ( & V_23 -> V_58 , F_32 ) ;
F_19 ( V_8 , V_34 , L_13 ) ;
return 0 ;
}
void F_47 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = F_17 ( V_23 -> V_24 ) ;
struct V_45 * V_46 = V_23 -> V_24 ;
struct V_92 * V_3 = & V_23 -> V_93 ;
struct V_94 * V_95 = & V_3 -> V_96 ;
if ( V_95 -> V_97 )
F_48 ( V_23 -> V_98 ,
V_99 + V_100 ,
V_95 -> V_97 , V_95 -> V_101 ) ;
F_49 ( V_46 ) ;
F_19 ( V_8 , V_34 , L_14 ) ;
}
void F_50 ( struct V_22 * V_23 )
{
struct V_92 * V_3 = & V_23 -> V_93 ;
struct V_45 * V_46 = V_23 -> V_24 ;
struct V_7 * V_8 = F_17 ( V_46 ) ;
struct V_25 * V_26 = & V_46 -> V_27 . V_3 ;
T_1 V_108 , V_109 ;
T_1 V_110 , V_111 , V_43 ;
T_1 * V_112 ;
T_1 V_113 = V_114 ;
bool V_115 = false ;
F_51 ( V_23 -> V_24 , & V_108 , & V_109 ) ;
if ( F_28 ( V_46 , V_116 ) == 0 ) {
F_52 ( V_46 , true , NULL ) ;
return;
}
if ( V_109 & V_117 ) {
T_1 V_47 [ 4 ] = { 0xffffffff , 0xffffffff ,
0xffffffff , 0xffffff00 } ;
F_31 ( V_46 , V_118 , 0 ,
V_47 , 16 , true , false ) ;
F_31 ( V_46 , V_119 , 0 ,
NULL , 0 , true , false ) ;
V_109 &= ~ V_117 ;
F_28 ( V_46 , V_120 ) ;
F_28 ( V_46 , V_121 ) ;
}
if ( V_109 & V_122 ) {
V_109 &= ~ V_122 ;
if ( ( V_26 -> V_49 == V_123 ) &&
( F_28 ( V_46 , V_124 ) !=
V_123 ) )
F_28 ( V_46 , V_121 ) ;
}
if ( V_109 & V_125 ) {
V_109 &= ~ V_125 ;
if ( ( V_26 -> V_49 == V_50 ) &&
( F_28 ( V_46 , V_124 ) !=
V_50 ) )
V_26 -> V_49 = V_123 ;
}
if ( ( V_108 & V_126 ) ||
( V_108 & V_127 ) ) {
F_28 ( V_46 , V_128 ) ;
V_115 = true ;
}
if ( V_109 & V_129 ) {
V_109 &= ~ V_129 ;
V_110 = F_28 ( V_46 , V_130 ) ;
}
if ( V_109 & V_131 ) {
V_109 &= ~ V_131 ;
while ( V_113 == V_114 ) {
V_112 = V_3 -> V_107 . V_97 ;
V_110 = F_52 ( V_46 , false ,
& V_113 ) ;
if ( V_110 == V_132 )
break;
V_112 += ( V_110 >> 2 ) ;
V_111 = F_53 ( V_112 ) ;
V_43 = F_54 ( V_112 ) ;
if ( V_115 )
goto V_133;
if ( F_55 ( V_111 ) ) {
F_27 ( V_23 , V_111 , ( T_2 * ) V_112 ) ;
} else {
switch ( V_111 ) {
case V_134 :
F_40 ( V_23 , V_43 , ( T_2 * ) V_112 ) ;
break;
default:
break;
}
}
V_133:
F_56 ( V_112 ) ;
}
}
if ( V_109 & V_135 ) {
if ( V_109 & V_136 )
V_109 &= ~ V_136 ;
if ( V_109 & V_137 )
V_109 &= ~ V_137 ;
if ( V_109 & V_138 ) {
int V_139 = F_57 ( V_26 -> V_140 ,
V_141 ) ;
V_109 &= ~ V_138 ;
F_19 ( V_8 , V_34 ,
L_15 ,
F_57 ( V_26 -> V_140 , V_142 ) ?
L_16 : L_17 ,
F_57 ( V_26 -> V_140 , V_143 ) ,
V_139 ) ;
}
if ( V_109 & V_144 )
V_109 &= ~ V_144 ;
if ( V_109 & V_145 )
V_109 &= ~ V_145 ;
}
if ( ( V_108 & V_126 ) ||
( V_108 & V_127 ) )
V_108 &= ~ ( V_126 |
V_127 ) ;
}
void F_58 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = F_17 ( V_23 -> V_24 ) ;
if ( ! V_8 -> V_146 )
return;
if ( V_23 -> V_24 -> V_147 . V_148 & V_149 )
V_23 -> V_24 -> V_150 |= V_151 ;
}
