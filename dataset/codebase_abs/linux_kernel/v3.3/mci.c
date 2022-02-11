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
( V_4 -> type == V_11 ) ) {
F_4 ( V_8 , V_12 ,
L_1 ) ;
return false ;
}
if ( ( ( F_5 ( V_3 ) - V_3 -> V_9 ) == V_13 ) &&
( V_4 -> type != V_11 ) ) {
F_4 ( V_8 , V_12 ,
L_2 ) ;
return false ;
}
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 )
memcpy ( V_5 , V_4 , 10 ) ;
else {
V_5 = F_6 ( sizeof( * V_5 ) , V_14 ) ;
if ( ! V_5 )
return false ;
memcpy ( V_5 , V_4 , 10 ) ;
F_7 ( V_3 , V_4 ) ;
F_8 ( & V_4 -> V_15 , & V_3 -> V_4 ) ;
}
return true ;
}
static void F_9 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_4 ( V_8 , V_12 , L_3 ) ;
return;
}
F_10 ( V_3 , V_5 ) ;
F_11 ( & V_5 -> V_15 ) ;
F_12 ( V_5 ) ;
}
void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_16 ;
F_14 (info, tinfo, &mci->info, list) {
F_11 ( & V_4 -> V_15 ) ;
F_10 ( V_3 , V_4 ) ;
F_12 ( V_4 ) ;
}
V_3 -> V_17 = 0 ;
}
static void F_15 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = & V_19 -> V_3 ;
T_1 V_20 = V_19 -> V_21 *
( 100 - V_19 -> V_22 ) / 100 ;
if ( ( V_20 <= 4 ) &&
( ! V_3 -> V_17 || ( V_3 -> V_17 > ( 2 * V_20 ) ) ) )
V_3 -> V_17 = 2 * V_20 ;
}
static void F_16 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = F_17 ( V_24 -> V_25 ) ;
struct V_18 * V_19 = & V_24 -> V_19 ;
struct V_2 * V_3 = & V_19 -> V_3 ;
struct V_1 * V_4 ;
T_1 V_26 = F_5 ( V_3 ) ;
if ( V_26 == 1 ) {
V_4 = F_18 ( & V_3 -> V_4 ,
struct V_1 ,
V_15 ) ;
if ( V_3 -> V_9 && V_4 -> V_27 == 12 ) {
V_3 -> V_17 = 8 ;
F_4 ( V_8 , V_12 ,
L_4 ) ;
} else if ( ( V_4 -> type == V_28 ) &&
! V_4 -> V_29 ) {
V_19 -> V_21 = 60 ;
F_4 ( V_8 , V_12 ,
L_5 ) ;
} else if ( ( V_4 -> type == V_30 ) &&
( V_4 -> V_27 > 0 && V_4 -> V_27 < 50 ) &&
( V_4 -> V_31 > 1 || V_4 -> V_32 > 1 ) ) {
V_19 -> V_22 = 30 ;
V_3 -> V_17 = 8 ;
F_4 ( V_8 , V_12 ,
L_6
L_7 ) ;
}
} else if ( ( V_26 == 2 ) && ( V_3 -> V_33 == 2 ) ) {
V_19 -> V_22 = 30 ;
V_3 -> V_17 = 8 ;
F_4 ( V_8 , V_12 ,
L_8 ) ;
} else if ( V_26 > 3 ) {
V_3 -> V_17 = 6 ;
F_4 ( V_8 , V_12 ,
L_9 ) ;
}
if ( F_19 ( V_24 -> V_25 -> V_34 ) ) {
if ( F_20 ( V_24 -> V_25 -> V_34 ) )
F_15 ( V_19 ) ;
else
V_19 -> V_21 >>= 1 ;
}
F_21 ( V_24 -> V_25 ) ;
F_22 ( V_24 ) ;
if ( F_23 ( V_24 -> V_25 -> V_34 ) )
return;
V_19 -> V_22 += ( V_3 -> V_35 ? V_36 : 0 ) ;
if ( V_19 -> V_22 > V_36 )
V_19 -> V_22 = V_36 ;
V_19 -> V_21 *= 1000 ;
V_19 -> V_37 = V_19 -> V_21 *
( 100 - V_19 -> V_22 ) / 100 ;
F_24 ( V_24 -> V_25 ) ;
F_25 ( V_24 ) ;
}
static void F_26 ( struct V_23 * V_24 , T_2 V_38 , T_2 * V_39 )
{
struct V_40 * V_41 = V_24 -> V_25 ;
struct V_7 * V_8 = F_17 ( V_41 ) ;
T_1 V_42 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_38 ) {
case V_43 :
F_4 ( V_8 , V_12 , L_10 ) ;
if ( F_27 ( V_41 , V_44 , NULL ) == V_45 ) {
F_27 ( V_41 , V_46 , NULL ) ;
F_28 ( V_24 -> V_47 , & V_24 -> V_48 ) ;
} else
F_4 ( V_8 , V_12 , L_11 ,
F_27 ( V_41 , V_44 , NULL ) ) ;
break;
case V_49 :
F_4 ( V_8 , V_12 , L_12 ) ;
if ( F_27 ( V_41 , V_44 , NULL ) == V_50 )
F_4 ( V_8 , V_12 , L_13 ) ;
else
F_4 ( V_8 , V_12 , L_14 ) ;
break;
case V_51 :
F_4 ( V_8 , V_12 , L_15 ) ;
F_4 ( V_8 , V_12 , L_16 ) ;
F_29 ( V_42 , V_52 ) ;
F_30 ( V_24 -> V_25 , V_53 , 0 , V_42 ,
16 , false , true ) ;
break;
default:
F_4 ( V_8 , V_12 , L_17 ) ;
break;
}
}
static void F_31 ( struct V_23 * V_24 ,
struct V_1 * V_4 )
{
struct V_7 * V_8 = F_17 ( V_24 -> V_25 ) ;
struct V_18 * V_19 = & V_24 -> V_19 ;
struct V_2 * V_3 = & V_19 -> V_3 ;
if ( V_4 -> V_54 ) {
if ( ! F_3 ( V_8 , V_3 , V_4 ) )
return;
} else
F_9 ( V_8 , V_3 , V_4 ) ;
V_19 -> V_21 = V_55 ;
V_3 -> V_17 = V_3 -> V_9 ? 6 : 0 ;
if ( F_5 ( V_3 ) ) {
V_19 -> V_56 = V_57 ;
V_19 -> V_22 = V_58 [ F_5 ( V_3 ) ] ;
} else {
V_19 -> V_56 = V_3 -> V_59 ? V_60 :
V_57 ;
V_19 -> V_22 = V_61 ;
}
F_16 ( V_24 ) ;
}
static void F_32 ( struct V_23 * V_24 ,
struct V_62 * V_63 )
{
struct V_7 * V_8 = F_17 ( V_24 -> V_25 ) ;
struct V_18 * V_19 = & V_24 -> V_19 ;
struct V_2 * V_3 = & V_19 -> V_3 ;
struct V_1 V_4 ;
int V_64 = 0 , V_65 = V_3 -> V_59 ;
if ( V_63 -> V_66 ) {
F_4 ( V_8 , V_12 , L_18 ) ;
return;
}
memset ( & V_4 , 0 , sizeof( struct V_1 ) ) ;
V_4 . V_6 = V_63 -> V_6 ;
if ( F_1 ( V_3 , & V_4 ) ) {
F_4 ( V_8 , V_12 ,
L_19 ,
V_63 -> V_6 ) ;
return;
}
if ( V_63 -> V_6 >= V_67 ) {
F_4 ( V_8 , V_12 , L_20 ) ;
return;
}
if ( V_63 -> V_68 )
F_33 ( V_63 -> V_6 , V_3 -> V_63 ) ;
else
F_34 ( V_63 -> V_6 , V_3 -> V_63 ) ;
V_3 -> V_59 = 0 ;
do {
if ( F_35 ( V_64 , V_3 -> V_63 ) )
V_3 -> V_59 ++ ;
} while ( ++ V_64 < V_67 );
if ( V_65 != V_3 -> V_59 )
F_16 ( V_24 ) ;
}
static void F_36 ( struct V_23 * V_24 , T_2 V_38 , T_2 * V_39 )
{
struct V_40 * V_41 = V_24 -> V_25 ;
struct V_1 V_69 ;
struct V_62 V_70 ;
struct V_7 * V_8 = F_17 ( V_24 -> V_25 ) ;
T_1 V_71 ;
T_2 V_72 ;
T_2 V_73 ;
T_1 V_74 ;
switch ( V_38 ) {
case V_75 :
F_4 ( V_8 , V_12 , L_21 ) ;
V_71 = F_27 ( V_41 ,
V_76 , NULL ) ;
break;
case V_77 :
F_4 ( V_8 , V_12 , L_22 ) ;
V_72 = * ( V_39 + V_78 ) ;
V_73 = * ( V_39 + V_79 ) ;
F_4 ( V_8 , V_12 , L_23 ,
V_72 , V_73 ) ;
V_71 = ( V_72 << 8 ) + V_73 ;
V_71 = F_27 ( V_41 ,
V_80 , & V_71 ) ;
break;
case V_81 :
F_4 ( V_8 , V_12 ,
L_24 ,
* ( V_39 + V_82 ) ) ;
F_27 ( V_41 ,
V_83 , NULL ) ;
break;
case V_84 :
F_4 ( V_8 , V_12 , L_25 ) ;
memcpy ( & V_69 ,
( V_39 + V_85 ) , 10 ) ;
if ( ( V_69 . type == V_86 )
|| ( V_69 . type >=
V_87 ) ) {
F_4 ( V_8 , V_12 ,
L_26 ,
V_69 . type ,
V_69 . V_54 ) ;
break;
}
F_31 ( V_24 , & V_69 ) ;
break;
case V_88 :
V_70 . V_66 = * ( V_39 +
V_89 ) ;
V_70 . V_6 = * ( V_39 +
V_90 ) ;
V_70 . V_68 = * ( V_39 +
V_91 ) ;
V_74 = * ( ( T_1 * ) ( V_39 + 12 ) ) ;
F_4 ( V_8 , V_12 ,
L_27 ,
V_70 . V_66 , V_70 . V_6 ,
V_70 . V_68 , V_74 ) ;
F_32 ( V_24 , & V_70 ) ;
break;
default:
F_4 ( V_8 , V_12 , L_28 ,
V_38 ) ;
break;
}
}
static int F_37 ( struct V_23 * V_24 , struct V_92 * V_93 )
{
int error = 0 ;
V_93 -> V_94 = F_38 ( V_24 -> V_95 , V_93 -> V_96 ,
& V_93 -> V_97 , V_14 ) ;
if ( V_93 -> V_94 == NULL ) {
error = - V_98 ;
goto V_99;
}
return 0 ;
V_99:
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
return error ;
}
static void F_39 ( struct V_23 * V_24 , struct V_92 * V_93 )
{
if ( V_93 -> V_94 ) {
F_40 ( V_24 -> V_95 , V_93 -> V_96 , V_93 -> V_94 ,
V_93 -> V_97 ) ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
}
}
int F_41 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = F_17 ( V_24 -> V_25 ) ;
struct V_100 * V_3 = & V_24 -> V_101 ;
int error = 0 ;
if ( ! V_102 )
return 0 ;
V_3 -> V_103 . V_96 = V_104 + V_105 ;
if ( F_37 ( V_24 , & V_3 -> V_103 ) ) {
F_4 ( V_8 , V_106 , L_29 ) ;
error = - V_98 ;
goto V_99;
}
V_3 -> V_103 . V_96 = V_104 ;
memset ( V_3 -> V_103 . V_94 , V_107 ,
V_3 -> V_103 . V_96 ) ;
V_3 -> V_108 . V_96 = V_105 ;
V_3 -> V_108 . V_94 = ( T_2 * ) V_3 -> V_103 . V_94 +
V_3 -> V_103 . V_96 ;
V_3 -> V_108 . V_97 = V_3 -> V_103 . V_97 + V_3 -> V_103 . V_96 ;
memset ( V_3 -> V_108 . V_94 , V_107 , V_3 -> V_108 . V_96 ) ;
F_42 ( V_24 -> V_25 , V_3 -> V_108 . V_97 ,
V_3 -> V_108 . V_94 , ( V_3 -> V_108 . V_96 >> 4 ) ,
V_3 -> V_103 . V_97 ) ;
V_99:
return error ;
}
void F_43 ( struct V_23 * V_24 )
{
struct V_40 * V_41 = V_24 -> V_25 ;
struct V_100 * V_3 = & V_24 -> V_101 ;
if ( ! V_102 )
return;
F_39 ( V_24 , & V_3 -> V_103 ) ;
F_44 ( V_41 ) ;
}
void F_45 ( struct V_23 * V_24 )
{
struct V_100 * V_3 = & V_24 -> V_101 ;
struct V_40 * V_41 = V_24 -> V_25 ;
struct V_7 * V_8 = F_17 ( V_41 ) ;
T_1 V_109 , V_110 ;
T_1 V_111 , V_112 , V_38 ;
T_1 * V_113 ;
T_1 V_114 = V_115 ;
bool V_116 = false ;
if ( ! V_102 )
return;
F_46 ( V_24 -> V_25 , & V_109 , & V_110 ) ;
if ( F_27 ( V_41 , V_117 , NULL ) == 0 ) {
F_27 ( V_24 -> V_25 , V_118 , NULL ) ;
F_4 ( V_8 , V_12 , L_30 ) ;
F_4 ( V_8 , V_12 ,
L_31 ,
V_109 , V_110 ) ;
return;
}
if ( V_110 & V_119 ) {
T_1 V_42 [ 4 ] = { 0xffffffff , 0xffffffff ,
0xffffffff , 0xffffff00 } ;
F_4 ( V_8 , V_12 , L_32 ) ;
F_30 ( V_41 , V_120 , 0 ,
V_42 , 16 , true , false ) ;
F_4 ( V_8 , V_12 , L_33 ) ;
F_30 ( V_41 , V_121 , 0 ,
NULL , 0 , true , false ) ;
V_110 &= ~ V_119 ;
F_27 ( V_41 , V_122 , NULL ) ;
F_4 ( V_8 , V_12 , L_34 ) ;
F_27 ( V_41 , V_123 , NULL ) ;
}
if ( V_110 & V_124 ) {
V_110 &= ~ V_124 ;
if ( F_27 ( V_41 , V_44 , NULL ) == V_125 ) {
if ( F_27 ( V_41 , V_126 , NULL )
== V_125 )
F_4 ( V_8 , V_12 ,
L_35 ) ;
else {
F_4 ( V_8 , V_12 ,
L_34 ) ;
F_27 ( V_41 ,
V_123 , NULL ) ;
}
} else
F_4 ( V_8 , V_12 , L_36 ) ;
}
if ( V_110 & V_127 ) {
V_110 &= ~ V_127 ;
if ( F_27 ( V_41 , V_44 , NULL ) == V_45 ) {
if ( F_27 ( V_41 , V_126 , NULL )
== V_45 )
F_4 ( V_8 , V_12 ,
L_36 ) ;
else {
F_4 ( V_8 , V_12 ,
L_37 ) ;
F_27 ( V_41 , V_128 ,
NULL ) ;
}
} else
F_4 ( V_8 , V_12 , L_38 ) ;
}
if ( ( V_109 & V_129 ) ||
( V_109 & V_130 ) ) {
F_4 ( V_8 , V_12 , L_39 ) ;
F_27 ( V_41 , V_131 , NULL ) ;
V_116 = true ;
}
if ( V_110 & V_132 ) {
V_110 &= ~ V_132 ;
V_111 = F_27 ( V_41 , V_133 ,
NULL ) ;
}
if ( V_110 & V_134 ) {
V_110 &= ~ V_134 ;
while ( V_114 == V_115 ) {
V_113 = V_3 -> V_108 . V_94 ;
V_111 = F_27 ( V_41 ,
V_135 , & V_114 ) ;
if ( V_111 == V_136 )
break;
V_113 += ( V_111 >> 2 ) ;
V_112 = F_47 ( V_113 ) ;
V_38 = F_48 ( V_113 ) ;
if ( ! V_116 ) {
if ( F_49 ( V_112 ) )
F_26 ( V_24 , V_112 ,
( T_2 * ) V_113 ) ;
else {
switch ( V_112 ) {
case V_137 :
F_36 ( V_24 , V_38 ,
( T_2 * ) V_113 ) ;
break;
default:
break;
}
}
}
F_50 ( V_113 ) ;
}
}
if ( V_110 & V_138 ) {
if ( V_110 & V_139 )
V_110 &= ~ V_139 ;
if ( V_110 & V_140 ) {
V_110 &= ~ V_140 ;
F_4 ( V_8 , V_12 , L_40 ) ;
}
if ( V_110 & V_141 ) {
int V_142 = F_27 ( V_41 ,
V_143 , NULL ) ;
V_110 &= ~ V_141 ;
if ( F_27 ( V_41 , V_144 , NULL ) )
F_4 ( V_8 , V_12 ,
L_41 ,
F_27 ( V_41 ,
V_145 , NULL ) ,
V_142 ) ;
else
F_4 ( V_8 , V_12 ,
L_42 ,
F_27 ( V_41 ,
V_145 , NULL ) ,
V_142 ) ;
}
if ( V_110 & V_146 ) {
V_110 &= ~ V_146 ;
F_4 ( V_8 , V_12 , L_43 ) ;
}
if ( V_110 & V_147 ) {
V_110 &= ~ V_147 ;
F_4 ( V_8 , V_12 , L_44 ) ;
}
}
if ( ( V_109 & V_129 ) ||
( V_109 & V_130 ) )
V_109 &= ~ ( V_129 |
V_130 ) ;
if ( V_110 & 0xfffffffe )
F_4 ( V_8 , V_12 , L_45 ,
V_110 ) ;
}
