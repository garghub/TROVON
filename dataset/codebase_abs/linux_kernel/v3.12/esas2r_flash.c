static T_1 F_1 ( T_1 * V_1 , T_2 V_2 , T_1 V_3 )
{
T_2 V_4 = V_3 ;
T_1 * V_5 = ( T_1 * ) & V_4 ;
while ( V_2 ) {
if ( ( ( V_6 ) V_1 & 3 ) == 0 )
break;
V_4 = V_4 ^ * V_1 ;
V_1 ++ ;
V_2 -- ;
}
while ( V_2 >= sizeof( T_2 ) ) {
V_4 = V_4 ^ * ( T_2 * ) V_1 ;
V_1 += 4 ;
V_2 -= 4 ;
}
while ( V_2 -- ) {
V_4 = V_4 ^ * V_1 ;
V_1 ++ ;
}
return V_5 [ 0 ] ^ V_5 [ 1 ] ^ V_5 [ 2 ] ^ V_5 [ 3 ] ;
}
static T_1 F_2 ( void * V_1 , T_2 V_2 , T_1 V_3 )
{
T_1 * V_5 = ( T_1 * ) V_1 ;
T_1 V_4 = V_3 ;
while ( V_2 -- )
V_4 = V_4 + V_5 [ V_2 ] ;
return V_4 ;
}
static void F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_12 -> V_13 ;
struct V_14 * V_15 =
(struct V_14 * ) V_10 -> V_16 ;
if ( V_10 -> V_17 == V_18 ) {
switch ( V_12 -> V_19 ) {
case V_20 :
if ( V_15 -> V_21 . V_22 == NULL )
goto V_23;
V_12 -> V_19 = V_24 ;
V_10 -> V_17 = V_25 ;
break;
case V_24 :
V_23:
V_12 -> V_19 = V_26 ;
V_10 -> V_17 = V_25 ;
V_10 -> V_27 = V_15 -> V_27 ;
break;
default:
break;
}
}
if ( V_10 -> V_17 != V_25 )
(* V_15 -> V_27 )( V_8 , V_10 ) ;
}
static void F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_10 -> V_16 ;
struct V_28 * V_21 = & V_15 -> V_21 ;
T_1 V_4 = 0 ;
if ( V_15 -> V_29 == V_20 ) {
if ( V_21 -> V_22 )
V_4 = F_1 ( V_21 -> V_22 ,
V_21 -> V_30 ,
0 ) ;
V_10 -> V_27 = F_3 ;
} else {
V_10 -> V_27 = V_15 -> V_27 ;
}
F_5 ( V_8 ,
V_10 ,
V_15 -> V_29 ,
V_4 ,
V_15 -> V_31 ,
V_21 -> V_30 ) ;
F_6 ( V_10 , V_8 ) ;
V_15 -> V_32 = V_15 -> V_21 . V_30 ;
if ( V_21 -> V_22 ) {
F_7 ( V_21 , V_8 , V_10 , & V_10 -> V_12 -> V_13 . V_33 . V_34 [ 0 ] ) ;
if ( ! F_8 ( V_8 , V_10 , V_21 ) ) {
V_10 -> V_17 = V_35 ;
return;
}
} else {
V_15 -> V_21 . V_30 = 0 ;
}
V_15 -> V_31 += V_15 -> V_32 ;
}
static bool F_9 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
V_10 -> V_17 = V_25 ;
if ( V_8 -> V_36 & V_37 )
;
else
F_4 ( V_8 , V_10 ) ;
return V_10 -> V_17 == V_25 ;
}
static void F_10 ( struct V_7 * V_8 , struct V_38 * V_39 )
{
struct V_40 * V_41 = & V_39 -> V_42 [ V_43 ] ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
V_45 = (struct V_44 * ) ( ( T_1 * ) V_39 + V_41 -> V_48 ) ;
V_47 =
(struct V_46 * ) ( ( T_1 * ) V_45 +
F_11 ( V_45 -> V_49 ) ) ;
V_47 -> V_50 = F_12 ( V_8 -> V_51 -> V_52 ) ;
if ( V_45 -> V_53 ) {
T_1 * V_54 =
( ( T_1 * ) V_45 + F_11 ( V_45 -> V_53 ) ) ;
* ( ( T_2 * ) & V_54 [ 10 ] ) =
F_13 ( F_14 ( V_8 -> V_51 -> V_55 ,
V_8 -> V_51 -> V_56 ) ) ;
V_54 [ 9 ] -= F_2 ( V_54 ,
32 , 0 ) ;
}
V_45 -> V_57 = V_45 -> V_57 -
F_2 ( ( T_1 * ) V_45 , V_41 -> V_30 , 0 ) ;
}
static void F_15 ( struct V_7 * V_8 , struct V_38 * V_39 )
{
struct V_40 * V_41 = & V_39 -> V_42 [ V_58 ] ;
T_2 V_2 = V_41 -> V_30 ;
T_2 V_59 = V_41 -> V_48 ;
struct V_60 * V_61 ;
struct V_46 * V_47 ;
while ( V_2 ) {
T_2 V_62 ;
V_61 = (struct V_60 * ) ( ( T_1 * ) V_39 + V_59 ) ;
V_47 = (struct V_46 * ) ( ( T_1 * ) V_61 +
F_11 (
V_61 -> V_49 ) ) ;
V_47 -> V_50 = F_12 ( V_8 -> V_51 -> V_52 ) ;
V_62 = ( T_2 ) F_11 ( V_47 -> V_63 ) * 512 ;
if ( V_62 > V_2 )
break;
V_2 -= V_62 ;
V_59 += V_62 ;
}
}
static bool F_16 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_1 V_64 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_10 -> V_16 ;
struct V_38 * V_39 = V_15 -> V_39 ;
V_39 -> V_65 = V_64 ;
V_39 -> V_66 = V_10 -> V_17 ;
V_10 -> V_27 = NULL ;
V_10 -> V_17 = V_18 ;
if ( V_64 != V_67 )
memset ( V_15 -> V_68 , 0 , V_69 ) ;
F_17 ( V_8 ) ;
F_18 ( & V_8 -> V_36 , V_70 ) ;
return false ;
}
static void F_19 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_14 * V_15 =
(struct V_14 * ) V_10 -> V_16 ;
struct V_38 * V_39 = V_15 -> V_39 ;
struct V_40 * V_41 ;
T_2 V_2 ;
T_1 * V_5 , * V_71 ;
if ( V_10 -> V_17 != V_18 )
goto error;
if ( V_15 -> V_29 == V_72
&& V_15 -> V_73 ) {
V_41 = & V_39 -> V_42 [ V_15 -> V_74 ] ;
V_5 = V_15 -> V_68 ;
V_71 = ( T_1 * ) V_39
+ V_41 -> V_48
+ V_41 -> V_30
- V_15 -> V_73 ;
for ( V_2 = V_15 -> V_32 ; V_2 ; V_2 -- )
if ( * V_5 ++ != * V_71 ++ )
goto error;
V_15 -> V_73 -= V_15 -> V_32 ;
if ( V_15 -> V_73 > V_69 )
V_15 -> V_21 . V_30 = V_69 ;
else
V_15 -> V_21 . V_30 = V_15 -> V_73 ;
V_15 -> V_21 . V_22 = V_15 -> V_75 +
( ( T_1 * ) V_15 -> V_68 - ( T_1 * ) V_39 ) ;
}
while ( V_15 -> V_21 . V_30 == 0 ) {
V_41 = & V_39 -> V_42 [ V_15 -> V_74 ] ;
switch ( V_15 -> V_76 ) {
case V_77 :
V_41 = & V_39 -> V_42 [ V_43 ] ;
if ( V_41 -> V_30 == 0 )
goto V_78;
V_15 -> V_76 = V_79 ;
V_15 -> V_29 = V_20 ;
V_15 -> V_74 = V_43 ;
V_15 -> V_31 = V_80 ;
V_15 -> V_21 . V_30 = V_41 -> V_30 ;
V_15 -> V_21 . V_22 = V_15 -> V_75 +
V_41 -> V_48 ;
break;
case V_79 :
V_15 -> V_76 = V_81 ;
V_15 -> V_29 = V_72 ;
V_15 -> V_31 = V_80 ;
V_15 -> V_73 = V_41 -> V_30 ;
V_15 -> V_21 . V_30 = V_69 ;
V_15 -> V_21 . V_22 = V_15 -> V_75
+ ( ( T_1 * ) V_15 -> V_68 -
( T_1 * ) V_39 ) ;
break;
case V_81 :
V_78:
V_41 -> V_65 = V_82 ;
V_41 = & V_39 -> V_42 [ V_83 ] ;
if ( V_41 -> V_30 == 0 )
goto V_84;
V_15 -> V_76 = V_85 ;
V_15 -> V_29 = V_20 ;
V_15 -> V_74 = V_83 ;
V_15 -> V_31 = V_80
+ V_39 -> V_42 [ V_43 ] . V_30 ;
V_15 -> V_21 . V_30 = V_41 -> V_30 ;
V_15 -> V_21 . V_22 = V_15 -> V_75 +
V_41 -> V_48 ;
break;
case V_85 :
V_15 -> V_76 = V_86 ;
V_15 -> V_29 = V_72 ;
V_15 -> V_31 -= V_41 -> V_30 ;
V_15 -> V_73 = V_41 -> V_30 ;
V_15 -> V_21 . V_30 = V_69 ;
V_15 -> V_21 . V_22 = V_15 -> V_75
+ ( ( T_1 * ) V_15 -> V_68 -
( T_1 * ) V_39 ) ;
break;
case V_86 :
V_84:
V_41 -> V_65 = V_82 ;
V_41 = & V_39 -> V_42 [ V_58 ] ;
if ( V_41 -> V_30 == 0 )
goto V_87;
V_15 -> V_76 = V_88 ;
V_15 -> V_29 = V_20 ;
V_15 -> V_74 = V_58 ;
V_15 -> V_31 = V_80
+ V_39 -> V_42 [ V_43 ] . V_30
+ V_39 -> V_42 [ V_83 ] . V_30 ;
V_15 -> V_21 . V_30 = V_41 -> V_30 ;
V_15 -> V_21 . V_22 = V_15 -> V_75 +
V_41 -> V_48 ;
break;
case V_88 :
V_15 -> V_76 = V_89 ;
V_15 -> V_29 = V_72 ;
V_15 -> V_31 -= V_41 -> V_30 ;
V_15 -> V_73 = V_41 -> V_30 ;
V_15 -> V_21 . V_30 = V_69 ;
V_15 -> V_21 . V_22 = V_15 -> V_75
+ ( ( T_1 * ) V_15 -> V_68 -
( T_1 * ) V_39 ) ;
break;
case V_89 :
V_87:
V_41 -> V_65 = V_82 ;
V_41 = & V_39 -> V_42 [ V_90 ] ;
if ( V_41 -> V_30 == 0 )
goto V_91;
V_15 -> V_76 = V_92 ;
V_15 -> V_29 = V_20 ;
V_15 -> V_74 = V_90 ;
V_15 -> V_31 = V_93 - V_41 -> V_30 ;
V_15 -> V_21 . V_30 = V_41 -> V_30 ;
V_15 -> V_21 . V_22 = V_15 -> V_75 +
V_41 -> V_48 ;
break;
case V_92 :
V_15 -> V_76 = V_94 ;
V_15 -> V_29 = V_72 ;
V_15 -> V_31 = V_93 - V_41 -> V_30 ;
V_15 -> V_73 = V_41 -> V_30 ;
V_15 -> V_21 . V_30 = V_69 ;
V_15 -> V_21 . V_22 = V_15 -> V_75
+ ( ( T_1 * ) V_15 -> V_68 -
( T_1 * ) V_39 ) ;
break;
case V_94 :
V_91:
V_41 -> V_65 = V_82 ;
if ( V_8 -> V_36 & V_37 )
F_20 ( V_8 ) ;
V_8 -> V_95 = V_39 -> V_42 [ V_43 ] . V_96 ;
F_21 ( V_8 ) ;
memcpy ( V_8 -> V_97 , V_39 -> V_98 ,
sizeof( V_39 -> V_98 ) ) ;
F_16 ( V_8 , V_10 , V_99 ) ;
return;
}
if ( V_15 -> V_29 == V_72
&& V_15 -> V_21 . V_30 > V_15 -> V_73 )
V_15 -> V_21 . V_30 = V_15 -> V_73 ;
}
if ( ! F_9 ( V_8 , V_10 ) ) {
error:
if ( V_15 -> V_74 < V_39 -> V_100 ) {
V_41 = & V_39 -> V_42 [ V_15 -> V_74 ] ;
V_41 -> V_65 = V_101 ;
}
F_16 ( V_8 , V_10 , V_102 ) ;
}
}
static T_1 F_22 ( struct V_7 * V_8 )
{
T_1 type ;
switch ( V_8 -> V_51 -> V_52 ) {
case V_103 :
type = V_104 ;
break;
case V_105 :
case V_106 :
case V_107 :
case V_108 :
type = V_109 ;
break;
default:
type = V_110 ;
break;
}
return type ;
}
static T_2 F_23 ( T_1 * V_111 , T_2 V_30 , T_2 * V_95 )
{
T_3 * V_112 = ( T_3 * ) V_111 - 1 ;
T_2 V_113 = 0 ;
T_2 V_2 = V_30 ;
if ( V_2 == 0 )
V_2 = V_69 ;
if ( V_95 )
* V_95 = 0 ;
while ( true ) {
T_3 type ;
T_3 V_114 ;
type = F_11 ( * V_112 -- ) ;
V_114 = F_11 ( * V_112 -- ) ;
if ( type != V_115
&& type != V_116
&& type != V_117 )
break;
if ( type == V_117
&& V_95 )
* V_95 = F_24 ( * ( T_2 * ) ( V_112 - 1 ) ) ;
V_113 += V_114 + ( 2 * sizeof( T_3 ) ) ;
V_112 -= V_114 / sizeof( T_3 ) ;
if ( V_113 > V_2 - ( 2 * sizeof( T_3 ) ) )
break;
}
if ( V_30 && V_113 != V_30 )
return 0 ;
return V_113 ;
}
static T_1 F_25 ( T_1 * V_118 , T_2 V_30 )
{
struct V_119 * V_120 = (struct V_119 * ) V_118 ;
T_3 V_121 = F_11 ( V_120 -> V_49 ) ;
struct V_46 * V_47 ;
if ( V_120 -> V_122 != F_11 ( 0xaa55 )
|| ( long ) V_121 >
( long ) ( 65536L - sizeof( struct V_46 ) )
|| ( V_121 & 3 )
|| ( V_121 < sizeof( struct V_119 ) )
|| ( ( T_2 ) V_121 + sizeof( struct V_46 ) > V_30 ) )
return 0xff ;
V_47 = (struct V_46 * ) ( ( char * ) V_120 + V_121 ) ;
if ( V_47 -> V_122 [ 0 ] != 'P'
|| V_47 -> V_122 [ 1 ] != 'C'
|| V_47 -> V_122 [ 2 ] != 'I'
|| V_47 -> V_122 [ 3 ] != 'R'
|| F_11 ( V_47 -> V_123 ) <
( T_3 ) sizeof( struct V_46 )
|| V_47 -> V_124 [ 2 ] != 0x01
|| V_47 -> V_124 [ 1 ] != 0x04
|| V_47 -> V_124 [ 0 ] != 0x00
|| ( V_47 -> V_125 != V_126
&& V_47 -> V_125 != V_127
&& V_47 -> V_125 != V_128 ) )
return 0xff ;
return V_47 -> V_125 ;
}
static T_3 F_26 ( struct V_14 * V_15 )
{
struct V_38 * V_39 = V_15 -> V_39 ;
T_3 V_4 ;
T_2 V_2 ;
T_3 * V_112 ;
for ( V_2 = ( V_39 -> V_30 - V_15 -> V_129 ) / 2 ,
V_112 = ( T_3 * ) ( ( T_1 * ) V_39 + V_15 -> V_129 ) ,
V_4 = 0 ;
V_2 ;
V_2 -- , V_112 ++ )
V_4 = V_4 + F_11 ( * V_112 ) ;
return V_4 ;
}
static bool F_27 ( struct V_7 * V_8 ,
struct V_14 * V_15 )
{
struct V_38 * V_39 = V_15 -> V_39 ;
T_1 type ;
bool V_130 ;
T_3 V_131 ;
T_2 V_2 ;
struct V_40 * V_41 ;
V_2 = V_39 -> V_30 ;
if ( ( V_2 & 1 )
|| V_2 < V_15 -> V_129 ) {
V_39 -> V_65 = V_132 ;
return false ;
}
type = F_22 ( V_8 ) ;
if ( ( type == V_110 ) || ( V_39 -> V_133 != type ) ) {
V_39 -> V_65 = V_134 ;
return false ;
}
V_130 = false ;
for ( V_131 = 0 , V_2 = 0 , V_41 = V_39 -> V_42 ;
V_131 < V_39 -> V_100 ;
V_131 ++ , V_41 ++ ) {
bool V_135 = false ;
if ( V_131 != V_41 -> V_136 ) {
V_130 = true ;
V_41 -> V_65 = V_137 ;
continue;
}
switch ( V_41 -> V_136 ) {
case V_43 :
type = V_126 ;
break;
case V_83 :
type = V_127 ;
break;
case V_58 :
type = V_128 ;
break;
}
switch ( V_41 -> V_136 ) {
case V_138 :
case V_139 :
break;
case V_43 :
case V_83 :
case V_58 :
if ( V_41 -> V_30 & 0x1ff )
V_135 = true ;
if ( V_41 -> V_30 == 0 )
break;
if ( F_25 ( ( T_1 * ) V_39 + V_41 -> V_48 , V_41 -> V_30 )
!= type )
V_135 = true ;
break;
case V_90 :
if ( V_41 -> V_30 == 0 ) {
V_135 = true ;
break;
}
if ( ! F_23 ( ( T_1 * ) V_39 + V_41 -> V_48 + V_41 -> V_30 ,
V_41 -> V_30 , NULL ) )
V_135 = true ;
break;
default:
V_39 -> V_65 = V_140 ;
return false ;
}
if ( V_135 ) {
V_130 = true ;
V_41 -> V_65 = V_137 ;
} else {
V_41 -> V_65 = V_141 ;
V_2 += V_41 -> V_30 ;
}
}
if ( V_130 ) {
V_39 -> V_65 = V_142 ;
return false ;
}
if ( V_2 != V_39 -> V_30 - V_15 -> V_129 ) {
V_39 -> V_65 = V_132 ;
return false ;
}
if ( V_39 -> V_57 != F_26 ( V_15 ) ) {
V_39 -> V_65 = V_143 ;
return false ;
}
return true ;
}
static void F_28 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_144 * V_145 =
(struct V_144 * ) V_10 -> V_16 ;
if ( V_10 -> V_12 -> V_13 . V_19 == V_26 )
F_17 ( V_8 ) ;
V_145 -> V_66 = V_10 -> V_17 ;
if ( V_145 -> V_66 == V_18 )
V_145 -> V_65 = V_146 ;
else
V_145 -> V_65 = V_147 ;
}
bool F_29 ( struct V_7 * V_8 ,
struct V_144 * V_145 ,
struct V_9 * V_10 ,
struct V_28 * V_21 )
{
T_1 V_148 = ( T_1 ) F_30 ( V_149 ) ;
struct V_150 * V_151 = & V_145 -> V_152 ;
T_1 V_29 = 0 ;
T_2 V_153 ;
V_145 -> V_65 = V_147 ;
V_145 -> V_66 = V_25 ;
if ( V_145 -> V_96 > V_154 ) {
V_145 -> V_65 = V_155 ;
return false ;
}
if ( V_151 -> V_152 >= V_148 ) {
V_145 -> V_65 = V_156 ;
return false ;
}
V_29 = V_149 [ V_151 -> V_152 ] ;
if ( V_29 == 0xFF ) {
V_145 -> V_65 = V_156 ;
return false ;
}
if ( V_151 -> V_152 != V_157 ) {
if ( ( V_8 -> V_51 -> V_52 != V_105
|| V_145 -> V_158 != V_159 )
&& ( V_8 -> V_51 -> V_52 != V_106
|| V_145 -> V_158 != V_160 )
&& ( V_8 -> V_51 -> V_52 != V_107
|| V_145 -> V_158 != V_161 )
&& ( V_8 -> V_51 -> V_52 != V_108
|| V_145 -> V_158 != V_162 ) ) {
V_145 -> V_65 = V_163 ;
return false ;
}
if ( V_145 -> V_164 > V_165 ) {
V_145 -> V_65 = V_166 ;
return false ;
}
}
if ( V_8 -> V_36 & V_37 ) {
V_145 -> V_65 = V_167 ;
return false ;
}
V_10 -> V_27 = F_28 ;
V_10 -> V_16 = V_145 ;
V_153 = F_24 ( V_151 -> V_30 ) ;
F_5 ( V_8 ,
V_10 ,
V_29 ,
V_151 -> V_57 ,
F_24 ( V_151 -> V_168 ) ,
V_153 ) ;
if ( V_29 == V_24
|| V_29 == V_72 ) {
if ( V_153 == 0 ) {
V_145 -> V_65 = V_156 ;
return false ;
}
F_7 ( V_21 , V_8 , V_10 , V_10 -> V_12 -> V_13 . V_33 . V_34 ) ;
V_21 -> V_30 = V_153 ;
if ( ! F_8 ( V_8 , V_10 , V_21 ) ) {
V_145 -> V_65 = V_169 ;
return false ;
}
}
if ( V_29 == V_26 )
F_31 ( V_8 ) ;
F_32 ( V_8 , V_10 ) ;
return true ;
}
static bool F_33 ( struct V_7 * V_8 , T_2 V_170 )
{
T_2 V_171 ;
T_2 V_172 ;
T_2 V_173 ;
T_2 V_174 ;
if ( V_170 == V_175 )
F_34 ( V_8 ) ;
F_35 ( V_8 , V_176 , V_170 ) ;
V_171 = F_36 ( V_177 ) ;
V_172 = V_8 -> V_36 &
( V_178 | V_179 ) ? 40000 : 5000 ;
while ( true ) {
V_173 = F_37 ( V_8 , V_180 ) ;
if ( V_173 & V_181 ) {
V_174 =
F_37 ( V_8 , V_182 ) ;
F_35 ( V_8 , V_182 ,
V_174 ) ;
if ( V_174 & V_170 )
break;
}
F_38 ( F_39 ( 100 ) ) ;
if ( ( F_36 ( V_177 ) - V_171 ) > V_172 ) {
if ( V_170 == V_175 ) {
F_40 ( L_1 ) ;
F_35 ( V_8 , V_176 ,
V_183 ) ;
F_41 ( V_8 ) ;
} else {
F_40 ( L_2 ) ;
}
return false ;
}
}
if ( V_170 == V_183 )
F_41 ( V_8 ) ;
return true ;
}
bool F_42 ( struct V_7 * V_8 ,
void * V_184 ,
T_2 V_185 ,
T_2 V_114 )
{
T_1 * V_186 = ( T_1 * ) V_184 ;
if ( ! F_33 ( V_8 , V_175 ) )
return false ;
while ( V_114 ) {
T_2 V_2 ;
T_2 V_59 ;
T_2 V_187 ;
if ( V_8 -> V_188 & V_189 )
V_187 = V_190 + ( V_185 & - V_191 ) ;
else
V_187 = V_192 + ( V_185 & - V_191 ) ;
F_43 ( V_8 , V_187 ) ;
V_59 = V_185 & ( V_191 - 1 ) ;
V_2 = V_114 ;
if ( V_2 > V_191 - V_59 )
V_2 = V_191 - V_59 ;
V_185 += V_2 ;
V_114 -= V_2 ;
while ( V_2 -- ) {
* V_186 ++ = F_44 ( V_8 , V_59 ) ;
V_59 ++ ;
}
}
F_33 ( V_8 , V_183 ) ;
return true ;
}
bool F_45 ( struct V_7 * V_8 )
{
T_1 V_193 [ 256 ] ;
T_3 * V_112 ;
T_3 * V_194 ;
T_3 type ;
T_3 V_114 ;
T_2 V_113 ;
V_113 = sizeof( V_193 ) ;
V_112 = ( T_3 * ) ( V_193 + V_113 ) ;
V_194 = ( T_3 * ) V_193 + 2 ;
if ( ! F_42 ( V_8 , V_193 , V_93 - V_113 , V_113 ) )
goto V_195;
while ( V_112 >= V_194 ) {
V_112 -- ;
type = F_11 ( * V_112 ) ;
V_112 -- ;
V_114 = F_11 ( * V_112 ) ;
V_112 -= V_114 / 2 ;
if ( type == V_115
|| type == V_116
|| V_112 < V_194 )
continue;
if ( type == V_117 )
V_8 -> V_95 = F_24 ( * ( T_2 * ) V_112 ) ;
break;
}
V_195:
return F_21 ( V_8 ) ;
}
bool F_21 ( struct V_7 * V_8 )
{
T_3 V_196 = F_46 ( V_8 -> V_95 ) ;
T_1 V_197 = F_47 ( F_48 ( V_8 -> V_95 ) ) ;
T_1 V_198 = F_49 ( F_48 ( V_8 -> V_95 ) ) ;
if ( V_197 == 0
|| V_198 == 0
|| V_197 > 31
|| V_198 > 12
|| V_196 < 2006
|| V_196 > 9999 ) {
strcpy ( V_8 -> V_199 , L_3 ) ;
V_8 -> V_95 = 0 ;
return false ;
}
sprintf ( V_8 -> V_199 , L_4 , V_198 , V_197 , V_196 ) ;
F_40 ( L_5 , V_8 -> V_199 ) ;
return true ;
}
bool F_50 ( struct V_7 * V_8 )
{
T_1 V_193 [ 256 ] ;
struct V_119 * V_120 ;
struct V_46 * V_47 ;
T_2 V_113 ;
T_2 V_2 ;
T_2 V_59 ;
V_113 = sizeof( V_193 ) ;
V_2 = V_200 ;
V_59 = 0 ;
while ( true ) {
if ( ! F_42 ( V_8 , V_193 , V_80 +
V_59 ,
V_113 ) )
goto V_195;
V_120 = (struct V_119 * ) V_193 ;
V_47 = (struct V_46 * ) ( ( T_1 * ) V_120 +
F_11 (
V_120 -> V_49 ) ) ;
if ( V_120 -> V_122 != F_12 ( 0xAA55 ) )
goto V_195;
if ( V_47 -> V_125 == V_126 ) {
strcpy ( V_8 -> V_97 , L_6 ) ;
return true ;
} else if ( V_47 -> V_125 == V_128 ) {
struct V_60 * V_61 ;
V_61 = (struct V_60 * ) V_193 ;
switch ( F_11 ( V_61 -> V_201 ) ) {
case V_202 :
strcpy ( V_8 -> V_97 , L_7 ) ;
return true ;
case V_203 :
strcpy ( V_8 -> V_97 , L_8 ) ;
return true ;
case V_204 :
strcpy ( V_8 -> V_97 , L_9 ) ;
return true ;
case V_205 :
strcpy ( V_8 -> V_97 , L_10 ) ;
return true ;
default:
goto V_195;
}
} else {
T_2 V_62 ;
V_62 = ( T_2 ) F_11 ( V_47 -> V_63 ) * 512 ;
if ( V_62 == 0
|| V_62 + V_59 > V_2
|| V_47 -> V_206 == V_207 )
break;
V_59 += V_62 ;
}
}
V_195:
strcpy ( V_8 -> V_97 , L_11 ) ;
return false ;
}
bool F_51 ( struct V_7 * V_8 )
{
bool V_208 ;
if ( F_52 ( & V_8 -> V_209 ) )
return false ;
if ( ! F_42 ( V_8 , V_8 -> V_210 , V_211 ,
sizeof( struct V_212 ) ) ) {
F_40 ( L_12 ) ;
return false ;
}
V_208 = F_53 ( V_8 ) ;
F_54 ( & V_8 -> V_209 ) ;
return V_208 ;
}
static void F_55 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_12 -> V_13 ;
if ( V_10 -> V_17 == V_18 ) {
switch ( V_12 -> V_19 ) {
case V_20 :
V_12 -> V_19 = V_24 ;
V_10 -> V_17 = V_25 ;
break;
case V_24 :
V_12 -> V_19 = V_26 ;
V_10 -> V_17 = V_25 ;
break;
case V_72 :
F_53 ( V_8 ) ;
break;
case V_26 :
default:
break;
}
}
if ( V_10 -> V_17 != V_25 ) {
if ( V_10 -> V_17 == V_18 )
F_56 ( & V_8 -> V_36 , V_213 ) ;
else
F_18 ( & V_8 -> V_36 , V_213 ) ;
F_17 ( V_8 ) ;
F_54 ( & V_8 -> V_209 ) ;
}
}
bool F_57 ( struct V_7 * V_8 , struct V_9 * V_10 ,
struct V_212 * V_210 )
{
struct V_212 * V_214 = V_210 ;
T_1 V_215 [ 8 ] ;
T_2 * V_216 = ( T_2 * ) & V_215 [ 0 ] ;
struct V_11 * V_12 = & V_10 -> V_12 -> V_13 ;
if ( V_8 -> V_36 & V_37 )
return false ;
if ( F_52 ( & V_8 -> V_209 ) )
return false ;
if ( V_214 == NULL )
V_214 = V_8 -> V_210 ;
if ( V_214 -> V_96 > V_217 ) {
F_54 ( & V_8 -> V_209 ) ;
return false ;
}
memcpy ( & V_215 [ 0 ] , V_214 -> V_218 , 8 ) ;
if ( V_215 [ 0 ] != 0x50
|| V_215 [ 1 ] != 0x01
|| V_215 [ 2 ] != 0x08
|| ( V_215 [ 3 ] & 0xF0 ) != 0x60
|| ( ( V_215 [ 3 ] & 0x0F ) | V_216 [ 1 ] ) == 0 ) {
F_54 ( & V_8 -> V_209 ) ;
return false ;
}
if ( V_214 -> V_219 > V_220 )
V_214 -> V_219 = V_220 ;
V_214 -> V_96 = V_217 ;
V_214 -> V_57 = V_214 -> V_57 - F_58 ( V_214 ) ;
memcpy ( V_8 -> V_210 , V_214 , sizeof( struct V_212 ) ) ;
V_214 = V_8 -> V_210 ;
F_31 ( V_8 ) ;
F_5 ( V_8 ,
V_10 ,
V_20 ,
F_59 ( V_214 ) ,
V_211 ,
sizeof( struct V_212 ) ) ;
if ( V_8 -> V_36 & V_221 ) {
V_12 -> V_33 . V_34 [ 0 ] . V_30 =
F_13 ( V_222 |
sizeof( struct V_212 ) ) ;
V_12 -> V_33 . V_34 [ 0 ] . V_223 = F_60 (
V_8 -> V_224 + ( V_225 ) ( ( T_1 * ) V_214 - V_8 -> V_226 ) ) ;
} else {
V_12 -> V_33 . V_227 [ 0 ] . V_228 =
F_13 ( sizeof( struct V_212 ) ) ;
V_12 -> V_33 . V_227 [ 0 ] . V_223 = F_60 (
V_8 -> V_224
+ ( V_225 ) ( ( T_1 * ) V_214 - V_8 -> V_226 ) ) ;
}
V_10 -> V_27 = F_55 ;
F_32 ( V_8 , V_10 ) ;
return true ;
}
bool F_53 ( struct V_7 * V_8 )
{
struct V_212 * V_214 = V_8 -> V_210 ;
bool V_229 = false ;
if ( V_214 -> V_122 [ 0 ] != 'E'
|| V_214 -> V_122 [ 1 ] != 'S'
|| V_214 -> V_122 [ 2 ] != 'A'
|| V_214 -> V_122 [ 3 ] != 'S' ) {
F_40 ( L_13 ) ;
} else if ( F_58 ( V_214 ) ) {
F_40 ( L_14 ) ;
} else if ( V_214 -> V_96 > V_217 ) {
F_40 ( L_15 ) ;
} else {
F_56 ( & V_8 -> V_36 , V_213 ) ;
V_229 = true ;
}
if ( V_229 == false ) {
F_40 ( L_16 ) ;
F_61 ( V_8 ) ;
}
return V_229 ;
}
void F_61 ( struct V_7 * V_8 )
{
struct V_212 * V_214 = V_8 -> V_210 ;
T_2 time = F_36 ( V_177 ) ;
F_18 ( & V_8 -> V_36 , V_213 ) ;
* V_214 = V_230 ;
V_214 -> V_218 [ 3 ] |= 0x0F ;
V_214 -> V_218 [ 4 ] = F_49 ( F_46 ( time ) ) ;
V_214 -> V_218 [ 5 ] = F_47 ( F_46 ( time ) ) ;
V_214 -> V_218 [ 6 ] = V_8 -> V_51 -> V_231 -> V_232 ;
V_214 -> V_218 [ 7 ] = V_8 -> V_51 -> V_233 ;
}
void F_62 ( struct V_7 * V_8 ,
struct V_212 * V_210 )
{
T_1 V_218 [ 8 ] ;
memcpy ( & V_218 [ 0 ] , V_8 -> V_210 -> V_218 , 8 ) ;
* V_210 = V_230 ;
memcpy ( & V_210 -> V_218 [ 0 ] , & V_218 [ 0 ] , 8 ) ;
}
bool F_63 ( struct V_7 * V_8 , struct V_38 * V_39 ,
struct V_9 * V_10 , struct V_28 * V_21 )
{
struct V_14 * V_15 = & V_8 -> V_234 ;
T_1 V_235 ;
struct V_40 * V_41 ;
if ( F_56 ( & V_8 -> V_36 , V_70 ) & V_70 ) {
V_39 -> V_65 = V_236 ;
return false ;
}
memcpy ( & V_15 -> V_21 , V_21 , sizeof( struct V_28 ) ) ;
V_21 = & V_15 -> V_21 ;
V_15 -> V_39 = V_39 ;
V_15 -> V_75 = V_21 -> V_22 ;
V_10 -> V_17 = V_18 ;
V_10 -> V_16 = V_15 ;
switch ( V_39 -> V_237 ) {
case V_238 :
V_15 -> V_68 = ( (struct V_38 * ) V_39 ) -> V_239 ;
V_15 -> V_100 = V_240 ;
V_15 -> V_129 = sizeof( struct V_38 ) ;
break;
default:
return F_16 ( V_8 , V_10 , V_67 ) ;
}
if ( V_8 -> V_36 & V_37 )
return F_16 ( V_8 , V_10 , V_241 ) ;
switch ( V_39 -> V_242 ) {
case V_243 :
if ( ! F_27 ( V_8 , V_15 ) )
return F_16 ( V_8 , V_10 , V_39 -> V_65 ) ;
V_41 = & V_39 -> V_42 [ V_43 ] ;
if ( V_41 -> V_30 )
F_10 ( V_8 , V_39 ) ;
V_41 = & V_39 -> V_42 [ V_58 ] ;
if ( V_41 -> V_30 )
F_15 ( V_8 , V_39 ) ;
V_39 -> V_57 = F_26 ( V_15 ) ;
F_31 ( V_8 ) ;
V_15 -> V_76 = V_77 ;
V_15 -> V_29 = V_20 ;
V_15 -> V_74 = V_90 ;
V_15 -> V_31 = V_80 ;
V_15 -> V_21 . V_30 = V_200 ;
V_15 -> V_21 . V_22 = NULL ;
V_15 -> V_27 = F_19 ;
break;
case V_244 :
V_39 -> V_133 = F_22 ( V_8 ) ;
V_39 -> V_36 = 0 ;
V_39 -> V_100 = V_15 -> V_100 ;
V_39 -> V_30 = V_15 -> V_129 ;
memcpy ( V_39 -> V_98 , V_8 -> V_97 ,
sizeof( V_39 -> V_98 ) ) ;
for ( V_235 = 0 , V_41 = V_39 -> V_42 ;
V_235 < V_39 -> V_100 ;
V_235 ++ , V_41 ++ ) {
V_41 -> V_136 = V_235 ;
V_41 -> V_65 = V_141 ;
V_41 -> V_30 = 0 ;
V_41 -> V_96 = 0xffffffff ;
V_41 -> V_48 = 0 ;
V_41 -> V_245 [ 0 ] = 0 ;
V_41 -> V_245 [ 1 ] = 0 ;
}
if ( V_8 -> V_95 != 0 ) {
V_39 -> V_42 [ V_43 ] . V_96 =
V_39 -> V_42 [ V_83 ] . V_96 =
V_39 -> V_42 [ V_58 ] . V_96 =
V_39 -> V_42 [ V_90 ] . V_96
= V_8 -> V_95 ;
V_39 -> V_42 [ V_43 ] . V_65 =
V_39 -> V_42 [ V_83 ] . V_65 =
V_39 -> V_42 [ V_58 ] . V_65 =
V_39 -> V_42 [ V_90 ] . V_65 =
V_82 ;
return F_16 ( V_8 , V_10 , V_99 ) ;
}
case V_246 :
default:
return F_16 ( V_8 , V_10 , V_247 ) ;
}
if ( ! F_9 ( V_8 , V_10 ) )
return F_16 ( V_8 , V_10 , V_102 ) ;
F_32 ( V_8 , V_10 ) ;
return true ;
}
