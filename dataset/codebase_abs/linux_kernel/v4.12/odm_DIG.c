void F_1 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
F_2 ( V_2 -> V_3 , V_4 + 2 , 0x2710 ) ;
F_2 ( V_2 -> V_3 , V_5 + 2 , 0xffff ) ;
F_3 ( V_2 -> V_3 , V_6 , 0xffffff52 ) ;
F_3 ( V_2 -> V_3 , V_7 , 0xffffffff ) ;
F_4 ( V_2 -> V_3 , V_8 , V_9 , 0xff ) ;
F_4 ( V_2 -> V_3 , V_5 , V_10 | V_11 | V_12 , 0x7 ) ;
F_4 ( V_2 -> V_3 , V_13 , V_14 , 0x1 ) ;
}
void F_5 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
}
void F_6 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
T_2 V_15 = 0 ;
V_15 = F_8 ( V_2 -> V_3 , V_16 , V_17 ) ;
V_2 -> V_18 = ( V_19 ) ( V_15 & V_9 ) ;
}
void F_7 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
F_4 ( V_2 -> V_3 , V_5 , V_20 , 0 ) ;
F_4 ( V_2 -> V_3 , V_5 , V_20 , 1 ) ;
}
void F_9 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = 3 ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
V_2 -> V_26 = 0 ;
}
void F_10 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
V_2 -> V_25 =
* ( V_2 -> V_27 ) - V_2 -> V_23 ;
V_2 -> V_26 =
* ( V_2 -> V_28 ) - V_2 -> V_24 ;
V_2 -> V_23 =
* ( V_2 -> V_27 ) ;
V_2 -> V_24 =
* ( V_2 -> V_28 ) ;
F_11 (
V_2 ,
V_29 ,
V_30 ,
(
L_1 ,
V_2 -> V_18 ,
V_2 -> V_25 ,
V_2 -> V_26
)
) ;
if ( ( V_2 -> V_25 ) + 1 > ( V_31 ) ( V_2 -> V_26 << 2 ) + 1 ) {
if ( V_2 -> V_18 >= 190 || V_2 -> V_21 == true ) {
V_2 -> V_21 = true ;
V_2 -> V_22 = 0 ;
} else {
if ( V_2 -> V_22 < 3 )
V_2 -> V_22 = V_2 -> V_22 + 1 ;
else
V_2 -> V_22 = 4 ;
if ( V_2 -> V_22 > 3 ) {
V_2 -> V_21 = false ;
}
}
} else {
if ( V_2 -> V_21 == true && V_2 -> V_18 <= 200 ) {
V_2 -> V_22 = 0 ;
} else {
if ( V_2 -> V_22 < 3 )
V_2 -> V_22 = V_2 -> V_22 + 1 ;
else
V_2 -> V_22 = 4 ;
if ( V_2 -> V_22 > 3 ) {
V_2 -> V_21 = false ;
}
}
}
F_11 ( V_2 , V_29 , V_30 , ( L_2 , V_2 -> V_21 ) ) ;
}
void F_12 ( void * V_1 , V_19 V_32 )
{
T_1 V_2 = ( T_1 ) V_1 ;
T_2 V_15 = 0 ;
V_19 V_33 , V_34 ;
bool V_35 = true ;
T_3 V_36 , V_37 ;
T_3 V_38 ;
V_34 = 0x50 ;
F_13 ( V_2 , V_34 ) ;
V_38 = V_32 - ( T_3 ) V_34 ;
V_36 = V_2 -> V_39 + V_38 ;
if ( V_36 > 10 )
V_36 = 10 ;
V_37 = V_36 - V_2 -> V_40 ;
F_4 ( V_2 -> V_3 , V_41 , V_9 , ( V_19 ) V_36 ) ;
F_4 ( V_2 -> V_3 , V_41 , V_42 , ( V_19 ) V_37 ) ;
F_14 ( 5 ) ;
while ( V_35 ) {
for ( V_33 = 0 ; V_33 < 20 ; V_33 ++ ) {
V_15 = F_8 ( V_2 -> V_3 , V_43 , V_17 ) ;
if ( V_15 & V_44 )
V_2 -> V_45 = V_2 -> V_45 + 1 ;
else if ( V_15 & V_46 )
V_2 -> V_45 = V_2 -> V_45 + 1 ;
else
V_2 -> V_47 = V_2 -> V_47 + 1 ;
}
if ( V_2 -> V_45 > 5 ) {
V_34 = V_34 - 1 ;
V_36 = V_36 + 1 ;
if ( V_36 > 10 )
V_36 = 10 ;
V_37 = V_36 - V_2 -> V_40 ;
F_4 ( V_2 -> V_3 , V_41 , V_9 , ( V_19 ) V_36 ) ;
F_4 ( V_2 -> V_3 , V_41 , V_42 , ( V_19 ) V_37 ) ;
V_2 -> V_48 = true ;
V_2 -> V_45 = 0 ;
V_2 -> V_47 = 0 ;
if ( V_36 == 10 ) {
V_35 = false ;
V_2 -> V_48 = false ;
V_2 -> V_45 = 0 ;
V_2 -> V_47 = 0 ;
V_2 -> V_49 = V_37 ;
V_2 -> V_50 = V_36 ;
V_2 -> V_51 = V_34 ;
}
} else {
V_35 = false ;
V_2 -> V_48 = false ;
V_2 -> V_45 = 0 ;
V_2 -> V_47 = 0 ;
V_2 -> V_49 = V_37 ;
V_2 -> V_50 = V_36 ;
V_2 -> V_51 = V_34 ;
}
}
F_11 ( V_2 , V_29 , V_30 , ( L_3 , V_34 , V_2 -> V_49 , V_2 -> V_50 ) ) ;
}
void F_15 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
if ( V_2 -> V_52 == false )
V_2 -> V_39 = 0xf7 ;
else
V_2 -> V_39 = 0xa ;
V_2 -> V_53 = 20 ;
V_2 -> V_40 = 7 ;
V_2 -> V_54 = 0x32 ;
V_2 -> V_32 = 0x1c ;
V_2 -> V_55 = 0 ;
V_2 -> V_56 = false ;
V_2 -> V_48 = true ;
V_2 -> V_47 = 0 ;
V_2 -> V_45 = 0 ;
V_2 -> V_49 = 0 ;
V_2 -> V_50 = 0 ;
V_2 -> V_51 = 0 ;
F_9 ( V_2 ) ;
F_4 ( V_2 -> V_3 , V_57 , V_58 , 1 ) ;
}
void F_16 ( void * V_1 , V_19 V_34 )
{
T_1 V_2 = ( T_1 ) V_1 ;
T_3 V_36 , V_37 ;
T_3 V_38 , V_32 ;
bool V_59 = false ;
if ( ! ( V_2 -> V_60 & V_61 ) ) {
F_11 ( V_2 , V_29 , V_30 , ( L_4 ) ) ;
return;
}
F_11 ( V_2 , V_29 , V_30 , ( L_5 ) ) ;
F_11 ( V_2 , V_29 , V_30 , ( L_6 ,
V_2 -> V_55 , V_2 -> V_54 , V_2 -> V_39 , V_2 -> V_40 , V_2 -> V_53 ) ) ;
if ( * V_2 -> V_62 == V_63 )
V_32 = V_2 -> V_54 ;
else if ( * V_2 -> V_62 == V_64 )
V_32 = V_2 -> V_54 + 2 ;
else if ( * V_2 -> V_62 == V_65 )
V_32 = V_2 -> V_54 + 2 ;
else
V_32 = V_2 -> V_54 ;
V_2 -> V_32 = ( V_19 ) V_32 ;
if ( V_2 -> V_48 == true ) {
F_4 ( V_2 -> V_3 , V_66 , V_17 , 0x208 ) ;
F_12 ( V_2 , V_2 -> V_32 ) ;
}
if ( ( ! V_2 -> V_67 ) || ( * V_2 -> V_68 > 149 ) ) {
F_4 ( V_2 -> V_3 , V_41 , V_9 , 0x7f ) ;
F_4 ( V_2 -> V_3 , V_41 , V_42 , 0x7f ) ;
return;
}
if ( ! V_2 -> V_55 ) {
if ( V_2 -> V_69 > V_2 -> V_53 )
V_59 = 1 ;
else if ( V_2 -> V_69 < ( V_2 -> V_53 - 5 ) )
V_59 = 0 ;
} else
V_59 = 1 ;
if (
V_2 -> V_67 &&
V_2 -> V_52 == false &&
V_2 -> V_56 == false &&
V_2 -> V_48 == false
)
F_10 ( V_2 ) ;
F_11 (
V_2 ,
V_29 ,
V_30 ,
(
L_7 ,
( * V_2 -> V_62 == V_65 ) ? L_8 :
( ( * V_2 -> V_62 == V_64 ) ? L_9 : L_10 ) ,
V_32 ,
V_59
)
) ;
if ( V_59 == 1 ) {
V_38 = V_32 - ( T_3 ) V_34 ;
V_36 = V_2 -> V_39 + V_38 ;
if ( V_36 > 10 )
V_36 = 10 ;
V_37 = V_36 - V_2 -> V_40 ;
if ( V_37 < V_2 -> V_49 )
V_37 = V_2 -> V_49 ;
if ( V_36 < V_2 -> V_50 )
V_36 = V_2 -> V_50 ;
} else {
V_36 = 0x7f ;
V_37 = 0x7f ;
}
F_11 ( V_2 , V_29 , V_30 , ( L_11 ,
V_34 , V_36 , V_37 ) ) ;
F_4 ( V_2 -> V_3 , V_41 , V_9 , ( V_19 ) V_36 ) ;
F_4 ( V_2 -> V_3 , V_41 , V_42 , ( V_19 ) V_37 ) ;
}
void F_13 ( void * V_1 , V_19 V_70 )
{
T_1 V_2 = ( T_1 ) V_1 ;
T_4 V_71 = & V_2 -> V_72 ;
if ( V_71 -> V_73 ) {
F_11 ( V_2 , V_29 , V_30 , ( L_12 ) ) ;
return;
}
F_11 ( V_2 , V_29 , V_74 , ( L_13 ,
F_17 ( V_75 , V_2 ) , F_18 ( V_34 , V_2 ) ) ) ;
if ( V_71 -> V_76 != V_70 ) {
if ( ! V_71 -> V_77 ) {
if ( V_70 > V_71 -> V_78 ) {
F_11 ( V_2 , V_29 , V_74 , ( L_14 , V_71 -> V_78 ) ) ;
V_70 = V_71 -> V_78 ;
}
}
F_4 ( V_2 -> V_3 , F_17 ( V_75 , V_2 ) , F_18 ( V_34 , V_2 ) , V_70 ) ;
if ( V_2 -> V_79 > V_80 )
F_4 ( V_2 -> V_3 , F_17 ( V_81 , V_2 ) , F_18 ( V_34 , V_2 ) , V_70 ) ;
V_71 -> V_76 = V_70 ;
}
F_11 ( V_2 , V_29 , V_74 , ( L_15 , V_70 ) ) ;
}
void F_19 (
void * V_1 ,
T_5 V_82 ,
V_19 V_83
)
{
T_1 V_2 = ( T_1 ) V_1 ;
T_4 V_71 = & V_2 -> V_72 ;
static bool V_84 = false ;
F_11 ( V_2 , V_29 , V_30 , ( L_16 ) ) ;
if (
( V_2 -> V_60 & V_61 ) &&
V_2 -> V_48 == true
) {
F_11 (
V_2 ,
V_29 ,
V_30 ,
( L_17 )
) ;
return;
}
if (
! V_84 && ( ! ( V_2 -> V_60 & V_85 ) ||
! ( V_2 -> V_60 & V_86 ) )
) {
F_11 (
V_2 ,
V_29 ,
V_30 ,
( L_18 )
) ;
return;
}
switch ( V_82 ) {
case V_87 :
F_20 ( V_2 , V_88 , V_2 -> V_60 & ( ~ V_85 ) ) ;
F_11 ( V_2 , V_29 , V_30 , ( L_19 ) ) ;
if ( ! V_84 ) {
V_71 -> V_89 = V_71 -> V_76 ;
V_84 = true ;
}
F_11 ( V_2 , V_29 , V_30 , ( L_20 , V_71 -> V_89 ) ) ;
F_13 ( V_2 , V_83 ) ;
F_11 ( V_2 , V_29 , V_30 , ( L_21 , V_83 ) ) ;
break;
case V_90 :
if ( V_84 ) {
F_13 ( V_2 , V_71 -> V_89 ) ;
V_84 = false ;
F_11 ( V_2 , V_29 , V_30 , ( L_22 , V_71 -> V_89 ) ) ;
F_20 ( V_2 , V_88 , V_2 -> V_60 | V_85 ) ;
F_11 ( V_2 , V_29 , V_30 , ( L_23 ) ) ;
}
break;
default:
F_11 ( V_2 , V_29 , V_30 , ( L_24 ) ) ;
break;
}
}
bool F_21 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
if ( ! ( V_2 -> V_60 & V_86 ) ) {
F_11 ( V_2 , V_29 , V_30 , ( L_25 ) ) ;
return true ;
}
if ( ! ( V_2 -> V_60 & V_85 ) ) {
F_11 ( V_2 , V_29 , V_30 , ( L_26 ) ) ;
return true ;
}
if ( * ( V_2 -> V_91 ) ) {
F_11 ( V_2 , V_29 , V_30 , ( L_27 ) ) ;
return true ;
}
if ( V_2 -> V_92 == false ) {
F_11 ( V_2 , V_29 , V_30 , ( L_28 ) ) ;
return true ;
}
return false ;
}
void F_22 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
T_4 V_71 = & V_2 -> V_72 ;
V_71 -> V_73 = false ;
V_71 -> V_77 = false ;
V_71 -> V_76 = ( V_19 ) F_8 ( V_2 -> V_3 , F_17 ( V_75 , V_2 ) , F_18 ( V_34 , V_2 ) ) ;
V_71 -> V_93 = V_94 ;
V_71 -> V_95 = V_96 ;
V_71 -> V_97 = V_98 ;
V_71 -> V_99 = V_100 ;
V_71 -> V_101 = V_102 ;
V_71 -> V_103 = V_104 ;
V_71 -> V_105 = V_106 ;
V_71 -> V_107 = 0xFF ;
V_71 -> V_108 = 0x83 ;
V_71 -> V_109 = V_110 ;
V_71 -> V_111 = 0 ;
V_71 -> V_112 = 0 ;
V_71 -> V_113 = false ;
V_71 -> V_114 = false ;
V_2 -> V_92 = true ;
V_71 -> V_115 = V_110 ;
V_71 -> V_116 = V_110 ;
V_71 -> V_117 = 0x32 ;
if ( V_2 -> V_118 & ( V_119 | V_120 ) ) {
V_71 -> V_78 = V_121 ;
V_71 -> V_122 = V_110 ;
} else {
V_71 -> V_78 = V_121 ;
V_71 -> V_122 = V_110 ;
}
}
void F_23 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
T_4 V_71 = & V_2 -> V_72 ;
T_6 V_123 = & V_2 -> V_124 ;
bool V_125 , V_126 ;
V_19 V_127 , V_128 ;
V_19 V_129 , V_130 ;
V_19 V_70 = V_71 -> V_76 ;
V_19 V_131 ;
T_2 V_132 [ 3 ] ;
V_19 V_133 = 0 ;
T_2 V_134 = 0 , V_135 = 0 ;
bool V_136 = false ;
bool V_137 = true , V_138 = false , V_139 = false ;
if ( F_21 ( V_2 ) == true )
return;
F_11 ( V_2 , V_29 , V_30 , ( L_29 ) ) ;
if ( V_2 -> V_21 == true )
V_133 = V_2 -> V_51 ;
V_128 = V_71 -> V_115 ;
V_125 = ( V_2 -> V_67 ) && ( V_71 -> V_113 == false ) ;
V_126 = ( ! V_2 -> V_67 ) && ( V_71 -> V_113 == true ) ;
V_129 = 0x5A ;
V_130 = V_110 ;
V_127 = V_140 ;
F_11 ( V_2 , V_29 , V_30 , ( L_30 , V_129 , V_130 ) ) ;
if ( V_2 -> V_67 && V_137 ) {
if ( V_2 -> V_141 == 1 ) {
V_131 = 10 ;
F_11 ( V_2 , V_29 , V_30 , ( L_31 , V_131 ) ) ;
} else
V_131 = 15 ;
if ( ( V_2 -> V_69 + V_131 ) > V_129 )
V_71 -> V_78 = V_129 ;
else if ( ( V_2 -> V_69 + V_131 ) < V_130 )
V_71 -> V_78 = V_130 ;
else
V_71 -> V_78 = V_2 -> V_69 + V_131 ;
{
if ( V_2 -> V_69 < V_130 )
V_128 = V_130 ;
else if ( V_2 -> V_69 > V_127 )
V_128 = V_127 ;
else
V_128 = V_2 -> V_69 ;
}
} else {
V_71 -> V_78 = V_129 ;
V_128 = V_130 ;
}
if ( V_2 -> V_67 && ! V_2 -> V_142 ) {
if ( V_2 -> V_60 & V_143 ) {
if (
V_2 -> V_144 == V_145 ||
V_2 -> V_144 == V_146 ||
V_2 -> V_144 == V_147
) {
if ( V_71 -> V_148 > V_127 )
V_128 = V_127 ;
else
V_128 = ( V_19 ) V_71 -> V_148 ;
F_11 (
V_2 ,
V_149 ,
V_30 ,
(
L_32 ,
V_128
)
) ;
F_11 (
V_2 ,
V_149 ,
V_30 ,
(
L_33 ,
V_71 -> V_148
)
) ;
}
}
}
F_11 (
V_2 ,
V_29 ,
V_30 ,
(
L_34 ,
V_71 -> V_78 ,
V_128
)
) ;
F_11 (
V_2 ,
V_29 ,
V_30 ,
(
L_35 ,
V_2 -> V_67 ,
V_2 -> V_69 ,
V_125 ,
V_126
)
) ;
if ( V_126 ) {
V_71 -> V_122 = V_128 ;
V_71 -> V_109 = V_128 ;
} else
V_71 -> V_122 =
F_24 ( V_2 , V_128 , V_70 ) ;
if ( V_2 -> V_67 && ! V_125 ) {
if (
( V_2 -> V_150 . V_151 < 5 ) &&
V_2 -> V_152
) {
V_71 -> V_122 = V_130 ;
F_11 (
V_2 ,
V_29 ,
V_30 ,
(
L_36 ,
V_2 -> V_150 . V_151 ,
V_71 -> V_122
)
) ;
}
}
if ( V_71 -> V_122 > V_71 -> V_78 ) {
V_71 -> V_122 = V_71 -> V_78 ;
F_11 (
V_2 ,
V_29 ,
V_30 ,
(
L_37 ,
V_71 -> V_122
)
) ;
}
F_25 ( V_2 , V_136 , V_137 , V_135 , V_134 , V_132 ) ;
F_11 ( V_2 , V_29 , V_30 , ( L_38 , V_132 [ 0 ] , V_132 [ 1 ] , V_132 [ 2 ] ) ) ;
if ( V_2 -> V_67 && V_137 ) {
F_11 (
V_2 ,
V_29 ,
V_30 ,
( L_39 )
) ;
if ( V_138 || ( V_125 && V_137 ) ) {
V_71 -> V_111 = 0 ;
if ( V_2 -> V_69 < V_127 ) {
if ( V_70 < V_2 -> V_69 )
V_70 = V_2 -> V_69 ;
} else {
if ( V_70 < V_127 )
V_70 = V_127 ;
}
F_11 (
V_2 ,
V_29 ,
V_30 ,
(
L_40 ,
V_70
)
) ;
} else {
if ( V_123 -> V_153 > V_132 [ 2 ] )
V_70 = V_70 + 4 ;
else if ( V_123 -> V_153 > V_132 [ 1 ] )
V_70 = V_70 + 2 ;
else if ( V_123 -> V_153 < V_132 [ 0 ] )
V_70 = V_70 - 2 ;
if (
( V_2 -> V_150 . V_151 < 5 ) &&
( V_123 -> V_153 < V_154 ) &&
( V_2 -> V_152 )
) {
V_70 = V_71 -> V_122 ;
F_11 (
V_2 ,
V_29 ,
V_30 ,
(
L_41 ,
V_2 -> V_150 . V_151 ,
V_70
)
) ;
}
}
} else {
F_11 (
V_2 ,
V_29 ,
V_30 ,
( L_42 )
) ;
if ( V_126 || V_139 ) {
V_70 = V_130 ;
F_11 (
V_2 ,
V_29 ,
V_30 ,
( L_43 )
) ;
} else {
if ( V_123 -> V_153 > V_132 [ 2 ] )
V_70 = V_70 + 4 ;
else if ( V_123 -> V_153 > V_132 [ 1 ] )
V_70 = V_70 + 2 ;
else if ( V_123 -> V_153 < V_132 [ 0 ] )
V_70 = V_70 - 2 ;
}
}
if ( V_70 < V_71 -> V_122 )
V_70 = V_71 -> V_122 ;
if ( V_70 > V_71 -> V_78 )
V_70 = V_71 -> V_78 ;
F_11 (
V_2 ,
V_29 ,
V_30 ,
(
L_44 ,
V_70 ,
V_123 -> V_153
)
) ;
if (
V_2 -> V_60 & V_61 &&
V_2 -> V_21 == true
) {
if ( V_70 > V_133 )
V_70 = V_133 ;
if ( V_2 -> V_155 != 0 ) {
if ( V_70 < V_2 -> V_155 )
V_70 = V_2 -> V_155 ;
}
F_11 ( V_2 , V_29 , V_30 , ( L_45 , V_133 ) ) ;
F_11 ( V_2 , V_29 , V_30 , ( L_46 , V_2 -> V_155 ) ) ;
}
if ( V_2 -> V_156 ) {
if ( V_2 -> V_67 ) {
if ( V_71 -> V_117 > ( V_70 ) )
F_13 ( V_2 , V_70 ) ;
else
F_13 ( V_2 , V_71 -> V_117 ) ;
V_71 -> V_113 = V_2 -> V_67 ;
V_71 -> V_115 = V_128 ;
} else {
if ( V_2 -> V_157 )
F_13 ( V_2 , 0x1c ) ;
else if ( V_2 -> V_158 )
F_13 ( V_2 , 0x28 ) ;
else
F_13 ( V_2 , V_71 -> V_117 ) ;
}
} else {
F_13 ( V_2 , V_70 ) ;
V_71 -> V_113 = V_2 -> V_67 ;
V_71 -> V_115 = V_128 ;
}
}
void F_26 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
T_6 V_123 = & V_2 -> V_124 ;
V_19 V_159 = V_110 ;
V_19 V_70 = V_2 -> V_69 ;
V_70 = V_70 + V_160 ;
F_11 (
V_2 ,
V_29 ,
V_30 ,
( L_47 )
) ;
if ( V_123 -> V_153 > V_161 )
V_70 = V_70 + 4 ;
else if ( V_123 -> V_153 > V_162 )
V_70 = V_70 + 2 ;
else if ( V_123 -> V_153 < V_163 )
V_70 = V_70 - 2 ;
if ( ( V_2 -> V_69 - 10 ) > V_110 )
V_159 = V_2 -> V_69 - 10 ;
else
V_159 = V_110 ;
if ( V_70 > V_121 )
V_70 = V_121 ;
else if ( V_70 < V_159 )
V_70 = V_159 ;
F_11 (
V_2 ,
V_29 ,
V_30 ,
( L_48 , V_123 -> V_153 )
) ;
F_11 (
V_2 ,
V_29 ,
V_30 ,
( L_49 , V_2 -> V_69 )
) ;
F_11 (
V_2 ,
V_29 ,
V_30 ,
( L_50 , V_70 )
) ;
F_13 ( V_2 , V_70 ) ;
}
void F_27 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
T_6 V_124 = & ( V_2 -> V_124 ) ;
T_2 V_164 ;
if ( ! ( V_2 -> V_60 & V_86 ) )
return;
F_4 ( V_2 -> V_3 , V_165 , V_166 , 1 ) ;
F_4 ( V_2 -> V_3 , V_167 , V_166 , 1 ) ;
V_164 = F_8 (
V_2 -> V_3 , V_168 , V_17
) ;
V_124 -> V_169 = ( V_164 & 0xffff ) ;
V_124 -> V_170 = ( ( V_164 & 0xffff0000 ) >> 16 ) ;
V_164 = F_8 (
V_2 -> V_3 , V_171 , V_17
) ;
V_124 -> V_172 = ( V_164 & 0xffff ) ;
V_124 -> V_173 = ( ( V_164 & 0xffff0000 ) >> 16 ) ;
V_164 = F_8 (
V_2 -> V_3 , V_174 , V_17
) ;
V_124 -> V_175 = ( V_164 & 0xffff ) ;
V_124 -> V_176 = ( ( V_164 & 0xffff0000 ) >> 16 ) ;
V_164 = F_8 (
V_2 -> V_3 , V_177 , V_17
) ;
V_124 -> V_178 = ( V_164 & 0xffff ) ;
V_124 -> V_179 =
V_124 -> V_173 +
V_124 -> V_175 +
V_124 -> V_176 +
V_124 -> V_178 +
V_124 -> V_169 +
V_124 -> V_170 ;
{
F_4 ( V_2 -> V_3 , V_180 , V_181 , 1 ) ;
F_4 ( V_2 -> V_3 , V_180 , V_182 , 1 ) ;
V_164 = F_8 (
V_2 -> V_3 , V_183 , V_9
) ;
V_124 -> V_184 = V_164 ;
V_164 = F_8 (
V_2 -> V_3 , V_185 , V_186
) ;
V_124 -> V_184 += ( V_164 & 0xff ) << 8 ;
V_164 = F_8 (
V_2 -> V_3 , V_187 , V_17
) ;
V_124 -> V_188 =
( ( V_164 & 0xFF ) << 8 ) | ( ( V_164 & 0xFF00 ) >> 8 ) ;
}
V_124 -> V_153 = (
V_124 -> V_169 +
V_124 -> V_170 +
V_124 -> V_173 +
V_124 -> V_175 +
V_124 -> V_176 +
V_124 -> V_178 +
V_124 -> V_184
) ;
V_124 -> V_189 =
V_124 -> V_172 + V_124 -> V_188 ;
F_11 (
V_2 ,
V_190 ,
V_30 ,
( L_51 )
) ;
F_11 (
V_2 ,
V_190 ,
V_30 ,
(
L_52 ,
V_124 -> V_169 ,
V_124 -> V_170
)
) ;
F_11 (
V_2 ,
V_190 ,
V_30 ,
(
L_53 ,
V_124 -> V_173 ,
V_124 -> V_175
)
) ;
F_11 (
V_2 ,
V_190 ,
V_30 ,
(
L_54 ,
V_124 -> V_176 ,
V_124 -> V_178
)
) ;
F_11 (
V_2 ,
V_190 ,
V_30 ,
( L_55 , V_124 -> V_172 )
) ;
F_11 (
V_2 ,
V_190 ,
V_30 ,
( L_56 , V_124 -> V_188 )
) ;
F_11 (
V_2 ,
V_190 ,
V_30 ,
( L_57 , V_124 -> V_189 )
) ;
F_11 (
V_2 ,
V_190 ,
V_30 ,
( L_58 , V_124 -> V_179 )
) ;
F_11 (
V_2 ,
V_190 ,
V_30 ,
( L_59 , V_124 -> V_184 )
) ;
F_11 (
V_2 ,
V_190 ,
V_30 ,
( L_58 , V_124 -> V_179 )
) ;
F_11 (
V_2 ,
V_190 ,
V_30 ,
( L_60 , V_124 -> V_153 )
) ;
}
void F_25 (
void * V_1 ,
bool V_136 ,
bool V_137 ,
T_2 V_135 ,
T_2 V_134 ,
T_2 * V_132
)
{
T_1 V_2 = ( T_1 ) V_1 ;
if ( V_2 -> V_67 && ( V_137 || V_136 ) ) {
V_132 [ 0 ] = V_191 ;
V_132 [ 1 ] = V_154 ;
V_132 [ 2 ] = V_192 ;
} else {
V_132 [ 0 ] = 2000 ;
V_132 [ 1 ] = 4000 ;
V_132 [ 2 ] = 5000 ;
}
return;
}
V_19 F_24 ( void * V_1 , V_19 V_128 , V_19 V_70 )
{
T_1 V_2 = ( T_1 ) V_1 ;
T_4 V_71 = & V_2 -> V_72 ;
T_6 V_123 = & ( V_2 -> V_124 ) ;
V_19 V_122 = V_71 -> V_122 ;
if ( V_123 -> V_153 > 10000 ) {
F_11 ( V_2 , V_29 , V_30 , ( L_61 ) ) ;
if ( V_71 -> V_111 != 3 )
V_71 -> V_111 ++ ;
if ( V_71 -> V_109 < V_70 ) {
V_71 -> V_109 = V_70 ;
V_71 -> V_111 = 1 ;
}
if ( V_71 -> V_111 >= 3 ) {
if ( ( V_71 -> V_109 + 2 ) > V_71 -> V_78 )
V_122 = V_71 -> V_78 ;
else
V_122 = ( V_71 -> V_109 + 2 ) ;
V_71 -> V_112 = 1800 ;
F_11 ( V_2 , V_29 , V_30 , ( L_62 , V_71 -> V_112 ) ) ;
}
} else {
if ( V_71 -> V_112 != 0 ) {
V_71 -> V_112 -- ;
F_11 ( V_2 , V_29 , V_30 , ( L_63 , V_71 -> V_112 ) ) ;
} else {
if ( V_71 -> V_111 < 3 ) {
if ( ( V_71 -> V_109 - 2 ) < V_128 ) {
V_71 -> V_109 = V_128 ;
V_122 = V_128 ;
F_11 ( V_2 , V_29 , V_30 , ( L_64 ) ) ;
} else {
V_71 -> V_109 -= 2 ;
V_122 = ( V_71 -> V_109 + 2 ) ;
F_11 ( V_2 , V_29 , V_30 , ( L_65 ) ) ;
}
} else
V_71 -> V_111 = 0 ;
}
}
return V_122 ;
}
void F_28 ( void * V_1 )
{
T_1 V_2 = ( T_1 ) V_1 ;
T_6 V_124 = & ( V_2 -> V_124 ) ;
V_19 V_108 ;
if (
! ( V_2 -> V_60 & V_193 ) ||
! ( V_2 -> V_60 & V_86 )
) {
F_11 (
V_2 ,
V_194 ,
V_30 ,
( L_66 )
) ;
return;
}
if ( V_2 -> V_195 )
return;
F_11 (
V_2 ,
V_194 ,
V_30 ,
( L_67 )
) ;
if ( V_2 -> V_67 ) {
if ( V_2 -> V_69 > 25 )
V_108 = 0xcd ;
else if ( ( V_2 -> V_69 <= 25 ) && ( V_2 -> V_69 > 10 ) )
V_108 = 0x83 ;
else {
if ( V_124 -> V_184 > 1000 )
V_108 = 0x83 ;
else
V_108 = 0x40 ;
}
} else {
if ( V_124 -> V_184 > 1000 )
V_108 = 0x83 ;
else
V_108 = 0x40 ;
}
F_29 ( V_2 , V_108 ) ;
F_11 (
V_2 ,
V_194 ,
V_30 ,
(
L_68 ,
V_108
)
) ;
}
void F_29 ( void * V_1 , V_19 V_108 )
{
T_1 V_2 = ( T_1 ) V_1 ;
T_4 V_71 = & V_2 -> V_72 ;
if ( V_71 -> V_108 != V_108 )
F_30 ( V_2 -> V_3 , F_17 ( V_196 , V_2 ) , V_108 ) ;
V_71 -> V_107 = V_71 -> V_108 ;
V_71 -> V_108 = V_108 ;
}
