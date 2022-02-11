static struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_1 * V_5 ;
F_2 (entry, &mci->info, list) {
if ( V_5 -> V_6 == V_4 -> V_6 )
break;
}
return V_5 ;
}
static bool F_3 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_1 * V_5 ;
if ( ( V_3 -> V_9 == V_10 ) &&
( V_4 -> type == V_11 ) )
return false ;
if ( ( ( F_4 ( V_3 ) - V_3 -> V_9 ) == V_12 ) &&
( V_4 -> type != V_11 ) )
return false ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
memcpy ( V_5 , V_4 , 10 ) ;
} else {
V_5 = F_5 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 )
return false ;
memcpy ( V_5 , V_4 , 10 ) ;
F_6 ( V_3 , V_4 ) ;
F_7 ( & V_4 -> V_14 , & V_3 -> V_4 ) ;
}
return true ;
}
static void F_8 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return;
F_9 ( V_3 , V_5 ) ;
F_10 ( & V_5 -> V_14 ) ;
F_11 ( V_5 ) ;
}
void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_15 ;
F_13 (info, tinfo, &mci->info, list) {
F_10 ( & V_4 -> V_14 ) ;
F_9 ( V_3 , V_4 ) ;
F_11 ( V_4 ) ;
}
V_3 -> V_16 = 0 ;
}
static void F_14 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = & V_18 -> V_3 ;
T_1 V_19 = V_18 -> V_20 *
( 100 - V_18 -> V_21 ) / 100 ;
if ( ( V_19 <= 4 ) &&
( ! V_3 -> V_16 || ( V_3 -> V_16 > ( 2 * V_19 ) ) ) )
V_3 -> V_16 = 2 * V_19 ;
}
static void F_15 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = F_16 ( V_23 -> V_24 ) ;
struct V_17 * V_18 = & V_23 -> V_18 ;
struct V_2 * V_3 = & V_18 -> V_3 ;
struct V_1 * V_4 ;
T_1 V_25 = F_4 ( V_3 ) ;
if ( V_25 == 1 ) {
V_4 = F_17 ( & V_3 -> V_4 ,
struct V_1 ,
V_14 ) ;
if ( V_3 -> V_9 && V_4 -> V_26 == 12 ) {
V_3 -> V_16 = 8 ;
F_18 ( V_8 , V_27 ,
L_1 ) ;
} else if ( ( V_4 -> type == V_28 ) &&
! V_4 -> V_29 ) {
V_18 -> V_20 = 60 ;
F_18 ( V_8 , V_27 ,
L_2 ) ;
} else if ( ( V_4 -> type == V_30 ) &&
( V_4 -> V_26 > 0 && V_4 -> V_26 < 50 ) &&
( V_4 -> V_31 > 1 || V_4 -> V_32 > 1 ) ) {
V_18 -> V_21 = 30 ;
V_3 -> V_16 = 8 ;
F_18 ( V_8 , V_27 ,
L_3
L_4 ) ;
}
} else if ( ( V_25 == 2 ) && ( V_3 -> V_33 == 2 ) ) {
V_18 -> V_21 = 30 ;
V_3 -> V_16 = 8 ;
F_18 ( V_8 , V_27 ,
L_5 ) ;
} else if ( V_25 > 3 ) {
V_3 -> V_16 = 6 ;
F_18 ( V_8 , V_27 ,
L_6 ) ;
}
if ( F_19 ( V_23 -> V_24 -> V_34 ) ) {
if ( F_20 ( V_23 -> V_24 -> V_34 ) )
F_14 ( V_18 ) ;
else
V_18 -> V_20 >>= 1 ;
}
F_21 ( V_23 -> V_24 ) ;
F_22 ( V_23 ) ;
if ( F_23 ( V_23 -> V_24 -> V_34 ) )
return;
V_18 -> V_21 += ( V_3 -> V_35 ? V_36 : 0 ) ;
if ( V_18 -> V_21 > V_36 )
V_18 -> V_21 = V_36 ;
V_18 -> V_20 *= 1000 ;
V_18 -> V_37 = V_18 -> V_20 *
( 100 - V_18 -> V_21 ) / 100 ;
F_24 ( V_23 -> V_24 ) ;
F_25 ( V_23 ) ;
}
static void F_26 ( struct V_22 * V_23 , T_2 V_38 , T_2 * V_39 )
{
struct V_40 * V_41 = V_23 -> V_24 ;
struct V_7 * V_8 = F_16 ( V_41 ) ;
T_1 V_42 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_38 ) {
case V_43 :
if ( F_27 ( V_41 , V_44 , NULL ) == V_45 ) {
F_27 ( V_41 , V_46 , NULL ) ;
F_28 ( V_23 -> V_47 , & V_23 -> V_48 ) ;
} else {
F_18 ( V_8 , V_27 , L_7 ,
F_27 ( V_41 , V_44 , NULL ) ) ;
}
break;
case V_49 :
F_27 ( V_41 , V_44 , NULL ) ;
break;
case V_50 :
F_29 ( V_42 , V_51 ) ;
F_30 ( V_23 -> V_24 , V_52 , 0 , V_42 ,
16 , false , true ) ;
break;
default:
F_18 ( V_8 , V_27 , L_8 ) ;
break;
}
}
static void F_31 ( struct V_22 * V_23 ,
struct V_1 * V_4 )
{
struct V_7 * V_8 = F_16 ( V_23 -> V_24 ) ;
struct V_17 * V_18 = & V_23 -> V_18 ;
struct V_2 * V_3 = & V_18 -> V_3 ;
if ( V_4 -> V_53 ) {
if ( ! F_3 ( V_8 , V_3 , V_4 ) )
return;
} else
F_8 ( V_8 , V_3 , V_4 ) ;
V_18 -> V_20 = V_54 ;
V_3 -> V_16 = V_3 -> V_9 ? 6 : 0 ;
if ( F_4 ( V_3 ) ) {
V_18 -> V_55 = V_56 ;
V_18 -> V_21 = V_57 [ F_4 ( V_3 ) ] ;
} else {
V_18 -> V_55 = V_3 -> V_58 ? V_59 :
V_56 ;
V_18 -> V_21 = V_60 ;
}
F_15 ( V_23 ) ;
}
static void F_32 ( struct V_22 * V_23 ,
struct V_61 * V_62 )
{
struct V_17 * V_18 = & V_23 -> V_18 ;
struct V_2 * V_3 = & V_18 -> V_3 ;
struct V_1 V_4 ;
int V_63 = 0 , V_64 = V_3 -> V_58 ;
if ( V_62 -> V_65 )
return;
memset ( & V_4 , 0 , sizeof( struct V_1 ) ) ;
V_4 . V_6 = V_62 -> V_6 ;
if ( F_1 ( V_3 , & V_4 ) )
return;
if ( V_62 -> V_6 >= V_66 )
return;
if ( V_62 -> V_67 )
F_33 ( V_62 -> V_6 , V_3 -> V_62 ) ;
else
F_34 ( V_62 -> V_6 , V_3 -> V_62 ) ;
V_3 -> V_58 = 0 ;
do {
if ( F_35 ( V_63 , V_3 -> V_62 ) )
V_3 -> V_58 ++ ;
} while ( ++ V_63 < V_66 );
if ( V_64 != V_3 -> V_58 )
F_15 ( V_23 ) ;
}
static void F_36 ( struct V_22 * V_23 , T_2 V_38 , T_2 * V_39 )
{
struct V_40 * V_41 = V_23 -> V_24 ;
struct V_1 V_68 ;
struct V_61 V_69 ;
struct V_7 * V_8 = F_16 ( V_23 -> V_24 ) ;
T_1 V_70 ;
T_2 V_71 ;
T_2 V_72 ;
T_1 V_73 ;
switch ( V_38 ) {
case V_74 :
V_70 = F_27 ( V_41 , V_75 ,
NULL ) ;
break;
case V_76 :
V_71 = * ( V_39 + V_77 ) ;
V_72 = * ( V_39 + V_78 ) ;
V_70 = ( V_71 << 8 ) + V_72 ;
V_70 = F_27 ( V_41 , V_79 ,
& V_70 ) ;
break;
case V_80 :
F_27 ( V_41 , V_81 , NULL ) ;
break;
case V_82 :
memcpy ( & V_68 ,
( V_39 + V_83 ) , 10 ) ;
if ( ( V_68 . type == V_84 ) ||
( V_68 . type >= V_85 ) ) {
F_18 ( V_8 , V_27 ,
L_9 ,
V_68 . type ,
V_68 . V_53 ) ;
break;
}
F_31 ( V_23 , & V_68 ) ;
break;
case V_86 :
V_69 . V_65 = * ( V_39 +
V_87 ) ;
V_69 . V_6 = * ( V_39 +
V_88 ) ;
V_69 . V_67 = * ( V_39 +
V_89 ) ;
V_73 = * ( ( T_1 * ) ( V_39 + 12 ) ) ;
F_18 ( V_8 , V_27 ,
L_10 ,
V_69 . V_65 , V_69 . V_6 ,
V_69 . V_67 , V_73 ) ;
F_32 ( V_23 , & V_69 ) ;
break;
default:
F_18 ( V_8 , V_27 , L_11 , V_38 ) ;
break;
}
}
int F_37 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = F_16 ( V_23 -> V_24 ) ;
struct V_90 * V_3 = & V_23 -> V_91 ;
struct V_92 * V_93 = & V_3 -> V_94 ;
V_93 -> V_95 = F_38 ( V_23 -> V_96 ,
V_97 + V_98 ,
& V_93 -> V_99 , V_13 ) ;
if ( V_93 -> V_95 == NULL ) {
F_18 ( V_8 , V_100 , L_12 ) ;
return - V_101 ;
}
memset ( V_93 -> V_95 , V_102 ,
V_97 + V_98 ) ;
V_3 -> V_94 . V_103 = V_97 ;
V_3 -> V_104 . V_103 = V_98 ;
V_3 -> V_104 . V_95 = ( T_2 * ) V_3 -> V_94 . V_95 + V_3 -> V_94 . V_103 ;
V_3 -> V_104 . V_99 = V_3 -> V_94 . V_99 + V_3 -> V_94 . V_103 ;
F_39 ( V_23 -> V_24 , V_3 -> V_104 . V_99 ,
V_3 -> V_104 . V_95 , ( V_3 -> V_104 . V_103 >> 4 ) ,
V_3 -> V_94 . V_99 ) ;
F_18 ( V_8 , V_27 , L_13 ) ;
return 0 ;
}
void F_40 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = F_16 ( V_23 -> V_24 ) ;
struct V_40 * V_41 = V_23 -> V_24 ;
struct V_90 * V_3 = & V_23 -> V_91 ;
struct V_92 * V_93 = & V_3 -> V_94 ;
if ( V_93 -> V_95 )
F_41 ( V_23 -> V_96 ,
V_97 + V_98 ,
V_93 -> V_95 , V_93 -> V_99 ) ;
F_42 ( V_41 ) ;
F_18 ( V_8 , V_27 , L_14 ) ;
}
void F_43 ( struct V_22 * V_23 )
{
struct V_90 * V_3 = & V_23 -> V_91 ;
struct V_40 * V_41 = V_23 -> V_24 ;
struct V_7 * V_8 = F_16 ( V_41 ) ;
T_1 V_105 , V_106 ;
T_1 V_107 , V_108 , V_38 ;
T_1 * V_109 ;
T_1 V_110 = V_111 ;
bool V_112 = false ;
F_44 ( V_23 -> V_24 , & V_105 , & V_106 ) ;
if ( F_27 ( V_41 , V_113 , NULL ) == 0 ) {
F_27 ( V_41 , V_114 , NULL ) ;
return;
}
if ( V_106 & V_115 ) {
T_1 V_42 [ 4 ] = { 0xffffffff , 0xffffffff ,
0xffffffff , 0xffffff00 } ;
F_30 ( V_41 , V_116 , 0 ,
V_42 , 16 , true , false ) ;
F_30 ( V_41 , V_117 , 0 ,
NULL , 0 , true , false ) ;
V_106 &= ~ V_115 ;
F_27 ( V_41 , V_118 , NULL ) ;
F_27 ( V_41 , V_119 , NULL ) ;
}
if ( V_106 & V_120 ) {
V_106 &= ~ V_120 ;
if ( F_27 ( V_41 , V_44 , NULL ) == V_121 ) {
if ( F_27 ( V_41 , V_122 , NULL ) !=
V_121 )
F_27 ( V_41 , V_119 ,
NULL ) ;
}
}
if ( V_106 & V_123 ) {
V_106 &= ~ V_123 ;
if ( F_27 ( V_41 , V_44 , NULL ) == V_45 ) {
if ( F_27 ( V_41 , V_122 , NULL ) !=
V_45 )
F_27 ( V_41 , V_124 ,
NULL ) ;
}
}
if ( ( V_105 & V_125 ) ||
( V_105 & V_126 ) ) {
F_27 ( V_41 , V_127 , NULL ) ;
V_112 = true ;
}
if ( V_106 & V_128 ) {
V_106 &= ~ V_128 ;
V_107 = F_27 ( V_41 , V_129 ,
NULL ) ;
}
if ( V_106 & V_130 ) {
V_106 &= ~ V_130 ;
while ( V_110 == V_111 ) {
V_109 = V_3 -> V_104 . V_95 ;
V_107 = F_27 ( V_41 , V_131 ,
& V_110 ) ;
if ( V_107 == V_132 )
break;
V_109 += ( V_107 >> 2 ) ;
V_108 = F_45 ( V_109 ) ;
V_38 = F_46 ( V_109 ) ;
if ( V_112 )
goto V_133;
if ( F_47 ( V_108 ) ) {
F_26 ( V_23 , V_108 , ( T_2 * ) V_109 ) ;
} else {
switch ( V_108 ) {
case V_134 :
F_36 ( V_23 , V_38 , ( T_2 * ) V_109 ) ;
break;
default:
break;
}
}
V_133:
F_48 ( V_109 ) ;
}
}
if ( V_106 & V_135 ) {
if ( V_106 & V_136 )
V_106 &= ~ V_136 ;
if ( V_106 & V_137 )
V_106 &= ~ V_137 ;
if ( V_106 & V_138 ) {
int V_139 = F_27 ( V_41 ,
V_140 , NULL ) ;
V_106 &= ~ V_138 ;
if ( F_27 ( V_41 , V_141 , NULL ) )
F_18 ( V_8 , V_27 ,
L_15 ,
F_27 ( V_41 ,
V_142 , NULL ) ,
V_139 ) ;
else
F_18 ( V_8 , V_27 ,
L_16 ,
F_27 ( V_41 ,
V_142 , NULL ) ,
V_139 ) ;
}
if ( V_106 & V_143 )
V_106 &= ~ V_143 ;
if ( V_106 & V_144 )
V_106 &= ~ V_144 ;
}
if ( ( V_105 & V_125 ) ||
( V_105 & V_126 ) )
V_105 &= ~ ( V_125 |
V_126 ) ;
}
