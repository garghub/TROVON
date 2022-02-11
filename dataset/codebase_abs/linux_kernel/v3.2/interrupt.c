T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
T_2 V_5 = F_2 ( V_4 ) ;
if ( ( V_5 & V_6 ) != V_6 )
return V_7 ;
F_3 ( V_4 , V_8 , V_5 ) ;
return V_9 ;
}
static void F_4 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
if ( V_13 -> V_14 == V_15 ) {
F_5 ( V_13 ) ;
V_13 = NULL ;
V_11 -> V_16 = V_17 ;
if ( F_6 ( & V_11 -> V_18 ) )
F_7 ( & V_11 -> V_18 ) ;
} else if ( V_13 -> V_14 == V_19 &&
V_20 == V_11 -> V_21 ) {
V_11 -> V_21 = V_22 ;
if ( F_6 ( & V_11 -> V_23 ) )
F_7 ( & V_11 -> V_23 ) ;
}
}
static void F_8 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
if ( V_4 -> V_24 != 1 ) {
V_4 -> V_25 = V_26 ;
V_4 -> V_27 = 0 ;
memcpy ( V_13 -> V_28 . V_29 ,
V_4 -> V_30 ,
V_4 -> V_31 ) ;
F_9 ( & V_13 -> V_32 ,
& V_4 -> V_33 . V_34 . V_32 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_1 ) ;
V_4 -> V_36 = V_37 ;
F_10 ( & V_4 -> V_35 -> V_4 , L_2 ,
V_4 -> V_36 ) ;
} else {
F_11 ( V_4 ) ;
}
F_10 ( & V_4 -> V_35 -> V_4 , L_3 ) ;
F_7 ( & V_4 -> V_38 . V_39 ) ;
}
static int F_12 ( struct V_40 * V_41 ,
struct V_3 * V_4 ,
struct V_42 * V_43 )
{
struct V_10 * V_11 ;
struct V_12 * V_44 ;
unsigned char * V_45 ;
F_13 ( V_43 -> V_46 != V_4 -> V_38 . V_47 ) ;
F_13 ( V_4 -> V_25 != V_48 ) ;
V_45 = ( unsigned char * ) ( V_4 -> V_30 +
V_4 -> V_31 ) ;
F_13 ( V_4 -> V_49 < V_4 -> V_31 + V_43 -> V_50 ) ;
F_14 ( V_4 , V_45 , V_43 -> V_50 ) ;
V_4 -> V_31 += V_43 -> V_50 ;
if ( ! V_43 -> V_51 )
return 0 ;
F_10 ( & V_4 -> V_35 -> V_4 ,
L_4 ,
V_43 -> V_50 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_5 ) ;
if ( ! V_4 -> V_52 )
return - V_53 ;
V_44 = V_4 -> V_52 ;
V_4 -> V_52 = NULL ;
V_11 = (struct V_10 * ) V_44 -> V_54 ;
if ( ! V_11 )
return - V_53 ;
V_4 -> V_27 = 0 ;
V_44 -> V_55 = V_4 -> V_31 ;
V_44 -> V_56 = V_37 ;
if ( V_4 -> V_57 && V_11 == & V_4 -> V_38 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_6 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_7 ) ;
F_9 ( & V_44 -> V_32 ,
& V_41 -> V_34 . V_32 ) ;
}
return 0 ;
}
static int F_15 ( struct V_10 * V_11 ,
struct V_42 * V_43 )
{
return ( V_11 -> V_58 == V_43 -> V_59 &&
V_11 -> V_47 == V_43 -> V_46 &&
V_11 -> V_60 == V_61 &&
V_22 != V_11 -> V_21 ) ;
}
static int F_16 ( struct V_40 * V_41 ,
struct V_3 * V_4 ,
struct V_42 * V_43 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = NULL , * V_62 = NULL ;
unsigned char * V_45 = NULL ;
F_10 ( & V_4 -> V_35 -> V_4 , L_8 ) ;
if ( ! ( V_4 -> V_63 . V_64 == 0 &&
! F_17 ( & V_4 -> V_63 . V_34 . V_32 ) ) )
goto V_65;
F_18 (cb_pos, cb_next,
&dev->read_list.mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * ) V_13 -> V_54 ;
if ( V_11 && F_15 ( V_11 , V_43 ) ) {
V_11 -> V_21 = V_20 ;
V_45 = ( unsigned char * )
( V_13 -> V_28 . V_29 +
V_13 -> V_55 ) ;
F_13 ( V_13 -> V_28 . V_66 <
V_43 -> V_50 +
V_13 -> V_55 ) ;
if ( V_13 -> V_28 . V_66 <
V_43 -> V_50 + V_13 -> V_55 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_9 ) ;
F_19 ( & V_13 -> V_32 ) ;
return - V_67 ;
}
if ( V_45 )
F_14 ( V_4 , V_45 , V_43 -> V_50 ) ;
V_13 -> V_55 += V_43 -> V_50 ;
if ( V_43 -> V_51 ) {
V_11 -> V_64 = 0 ;
F_19 ( & V_13 -> V_32 ) ;
F_10 ( & V_4 -> V_35 -> V_4 ,
L_10
L_11
L_12 ,
V_11 -> V_58 ,
V_11 -> V_47 ,
V_13 -> V_55 ) ;
* ( V_13 -> V_28 . V_29 +
V_13 -> V_55 ) = '\0' ;
F_10 ( & V_4 -> V_35 -> V_4 , L_13 ,
V_13 -> V_28 . V_29 ) ;
F_9 ( & V_13 -> V_32 ,
& V_41 -> V_34 . V_32 ) ;
}
break;
}
}
V_65:
F_10 ( & V_4 -> V_35 -> V_4 , L_14 ) ;
if ( ! V_45 ) {
F_14 ( V_4 , ( unsigned char * ) V_4 -> V_68 ,
V_43 -> V_50 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_15 ,
* ( T_2 * ) V_4 -> V_68 ) ;
}
return 0 ;
}
static int F_20 ( struct V_3 * V_4 , T_3 * V_69 )
{
if ( ( ( * V_69 ) * sizeof( T_2 ) ) >= ( sizeof( struct V_42 )
+ sizeof( struct V_70 ) ) ) {
* V_69 -= ( sizeof( struct V_42 ) +
sizeof( struct V_70 ) + 3 ) / 4 ;
if ( ! F_21 ( V_4 , & V_4 -> V_38 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_16 ) ;
} else {
F_10 ( & V_4 -> V_35 -> V_4 , L_17 ) ;
V_4 -> V_25 = V_48 ;
V_4 -> V_71 = false ;
V_4 -> V_31 = 0 ;
V_4 -> V_72 = 0 ;
V_4 -> V_27 = V_73 ;
V_4 -> V_74 =
V_74 ( V_4 ) ;
}
return 0 ;
} else {
return - V_75 ;
}
}
static int F_22 ( struct V_3 * V_4 , T_3 * V_69 ,
struct V_12 * V_13 ,
struct V_10 * V_11 ,
struct V_40 * V_76 )
{
if ( ( * V_69 * sizeof( T_2 ) ) >= ( sizeof( struct V_42 ) +
sizeof( struct V_77 ) ) ) {
* V_69 -= ( sizeof( struct V_42 ) +
sizeof( struct V_77 ) + 3 ) / 4 ;
if ( ! F_23 ( V_4 , V_11 ) ) {
V_11 -> V_64 = 0 ;
V_13 -> V_55 = 0 ;
F_24 ( & V_13 -> V_32 ,
& V_76 -> V_34 . V_32 ) ;
return - V_75 ;
} else {
V_11 -> V_60 = V_78 ;
V_11 -> V_64 = 0 ;
V_13 -> V_55 = 0 ;
F_24 ( & V_13 -> V_32 ,
& V_4 -> V_79 . V_34 . V_32 ) ;
V_11 -> V_80 = V_81 ;
}
} else {
return - V_82 ;
}
return 0 ;
}
static bool F_25 ( struct V_10 * V_11 ,
struct V_83 * V_84 )
{
if ( V_11 -> V_58 == V_84 -> V_59 &&
V_11 -> V_47 == V_84 -> V_46 ) {
if ( ! V_84 -> V_64 ) {
V_11 -> V_60 = V_61 ;
V_11 -> V_64 = 0 ;
} else {
V_11 -> V_60 = V_85 ;
V_11 -> V_64 = - V_53 ;
}
V_11 -> V_80 = 0 ;
return true ;
}
return false ;
}
static void F_26 ( struct V_3 * V_4 ,
struct V_83 * V_84 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = NULL , * V_62 = NULL ;
F_10 ( & V_4 -> V_35 -> V_4 ,
L_18
L_19
L_20
L_21 ,
V_84 -> V_46 ,
V_84 -> V_59 ,
V_84 -> V_64 ) ;
if ( F_25 ( & ( V_4 -> V_86 ) , V_84 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_22 ,
V_4 -> V_87 ) ;
V_4 -> V_88 = ( V_4 -> V_87 ) ? 1 : 0 ;
F_10 ( & V_4 -> V_35 -> V_4 , L_23 ) ;
if ( F_27 ( & V_89 ) ) {
F_28 ( V_90 L_24 ) ;
V_4 -> V_91 = false ;
} else {
F_10 ( & V_4 -> V_35 -> V_4 , L_25 ) ;
V_4 -> V_91 = true ;
}
F_29 ( V_4 ) ;
return;
}
if ( F_25 ( & ( V_4 -> V_38 ) , V_84 ) ) {
V_4 -> V_25 = V_92 ;
return;
}
if ( ! V_4 -> V_79 . V_64 &&
! F_17 ( & V_4 -> V_79 . V_34 . V_32 ) ) {
F_18 (cb_pos, cb_next,
&dev->ctrl_rd_list.mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * ) V_13 -> V_54 ;
if ( ! V_11 ) {
F_19 ( & V_13 -> V_32 ) ;
return;
}
if ( V_93 == V_13 -> V_14 ) {
if ( F_25 ( V_11 , V_84 ) ) {
F_19 ( & V_13 -> V_32 ) ;
V_11 -> V_64 = 0 ;
V_11 -> V_80 = 0 ;
break;
}
}
}
}
}
static void F_30 ( struct V_3 * V_4 ,
struct V_83 * V_84 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = NULL , * V_62 = NULL ;
F_10 ( & V_4 -> V_35 -> V_4 ,
L_26
L_19
L_20
L_21 ,
V_84 -> V_46 ,
V_84 -> V_59 ,
V_84 -> V_64 ) ;
if ( ! V_4 -> V_79 . V_64 &&
! F_17 ( & V_4 -> V_79 . V_34 . V_32 ) ) {
F_18 (cb_pos, cb_next,
&dev->ctrl_rd_list.mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * ) V_13 -> V_54 ;
if ( ! V_11 ) {
F_19 ( & V_13 -> V_32 ) ;
return;
}
F_10 ( & V_4 -> V_35 -> V_4 , L_27 ) ;
if ( V_11 -> V_58 == V_84 -> V_59 &&
V_11 -> V_47 == V_84 -> V_46 ) {
F_19 ( & V_13 -> V_32 ) ;
if ( ! V_84 -> V_64 )
V_11 -> V_60 = V_85 ;
V_11 -> V_64 = 0 ;
V_11 -> V_80 = 0 ;
break;
}
}
}
}
static int F_31 ( struct V_10 * V_11 , struct V_70 * V_94 )
{
return ( V_11 -> V_58 == V_94 -> V_59 &&
V_11 -> V_47 == V_94 -> V_46 ) ;
}
static void F_32 ( struct V_3 * V_4 ,
struct V_70 * V_94 )
{
struct V_95 * V_96 ;
int V_97 ;
for ( V_97 = 0 ; V_97 < V_4 -> V_98 ; V_97 ++ ) {
V_96 = & V_4 -> V_99 [ V_97 ] ;
if ( V_96 && V_94 -> V_46 == V_96 -> V_100 ) {
if ( V_96 -> V_101 . V_102 ) {
V_96 -> V_103 ++ ;
F_10 ( & V_4 -> V_35 -> V_4 , L_28 ,
V_94 -> V_46 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_29 ,
V_96 -> V_103 ) ;
} else {
F_33 () ;
}
}
}
}
static void F_34 ( struct V_3 * V_4 ,
struct V_70 * V_104 )
{
struct V_10 * V_105 = NULL ;
struct V_10 * V_106 = NULL ;
if ( ! V_104 -> V_59 ) {
F_32 ( V_4 , V_104 ) ;
} else {
F_18 (cl_pos, cl_next,
&dev->file_list, link) {
F_10 ( & V_4 -> V_35 -> V_4 , L_30 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_31 ,
V_105 -> V_58 ,
V_105 -> V_47 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_32 ,
V_104 -> V_59 ,
V_104 -> V_46 ) ;
if ( F_31 ( V_105 , V_104 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_33 ,
V_104 -> V_59 ,
V_104 -> V_46 ) ;
V_105 -> V_103 ++ ;
F_10 ( & V_4 -> V_35 -> V_4 , L_34 ,
V_105 -> V_103 ) ;
break;
}
}
}
}
static int F_35 ( struct V_10 * V_11 ,
struct V_77 * V_107 )
{
return ( V_11 -> V_58 == V_107 -> V_59 &&
V_11 -> V_47 == V_107 -> V_46 ) ;
}
static void F_36 ( struct V_3 * V_4 ,
struct V_77 * V_108 )
{
struct V_42 * V_43 ;
struct V_83 * V_109 ;
struct V_10 * V_105 = NULL ;
struct V_10 * V_106 = NULL ;
F_18 (cl_pos, cl_next, &dev->file_list, link) {
if ( F_35 ( V_105 , V_108 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_35 ,
V_108 -> V_59 ,
V_108 -> V_46 ) ;
V_105 -> V_60 = V_85 ;
V_105 -> V_80 = 0 ;
if ( V_105 == & V_4 -> V_86 ) {
V_4 -> V_88 = 0 ;
V_4 -> V_110 = false ;
} else if ( V_105 == & V_4 -> V_38 )
V_4 -> V_36 = 0 ;
V_43 =
(struct V_42 * ) & V_4 -> V_111 [ 0 ] ;
V_43 -> V_59 = 0 ;
V_43 -> V_46 = 0 ;
V_43 -> V_50 =
sizeof( struct V_83 ) ;
V_43 -> V_51 = 1 ;
V_43 -> V_112 = 0 ;
V_109 =
(struct V_83 * )
& V_4 -> V_111 [ 1 ] ;
V_109 -> V_59 = V_105 -> V_58 ;
V_109 -> V_46 = V_105 -> V_47 ;
* ( V_113 * ) ( & V_109 -> V_114 ) =
V_115 ;
V_109 -> V_64 = 0 ;
V_4 -> V_116 = 2 ;
break;
}
}
}
static void F_37 ( struct V_3 * V_4 ,
struct V_42 * V_43 )
{
struct V_117 * V_118 ;
struct V_119 * V_120 ;
struct V_83 * V_121 ;
struct V_83 * V_109 ;
struct V_70 * V_104 ;
struct V_122 * V_123 ;
struct V_124 * V_125 ;
struct V_77 * V_108 ;
struct V_126 * V_127 ;
int V_128 ;
unsigned char * V_45 ;
V_45 = ( unsigned char * ) V_4 -> V_68 ;
F_13 ( V_43 -> V_50 >= sizeof( V_4 -> V_68 ) ) ;
F_14 ( V_4 , V_45 , V_43 -> V_50 ) ;
V_118 = (struct V_117 * ) V_45 ;
switch ( * ( V_113 * ) V_118 ) {
case V_129 :
V_120 = (struct V_119 * ) V_118 ;
if ( V_120 -> V_130 ) {
V_4 -> V_131 . V_132 = V_133 ;
V_4 -> V_131 . V_134 = V_135 ;
if ( V_4 -> V_136 == V_137 &&
V_4 -> V_138 == V_139 ) {
V_4 -> V_140 = 0 ;
F_38 ( V_4 ) ;
} else {
V_4 -> V_141 = false ;
F_10 ( & V_4 -> V_35 -> V_4 , L_36 ) ;
F_39 ( V_4 , 1 ) ;
return;
}
} else {
V_4 -> V_131 = V_120 -> V_142 ;
V_43 -> V_59 = 0 ;
V_43 -> V_46 = 0 ;
V_43 -> V_50 = sizeof( struct V_126 ) ;
V_43 -> V_51 = 1 ;
V_43 -> V_112 = 0 ;
V_127 = (struct V_126 * )
& V_4 -> V_143 [ 1 ] ;
memset ( V_127 ,
0 ,
sizeof( struct V_126 ) ) ;
V_127 -> V_114 . V_114 = V_144 ;
V_127 -> V_145 = V_146 ;
F_40 ( V_4 , V_43 ,
( unsigned char * ) ( V_127 ) ,
V_43 -> V_50 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_37 ) ;
return;
}
V_4 -> V_141 = true ;
F_10 ( & V_4 -> V_35 -> V_4 , L_38 ) ;
break;
case V_147 :
V_121 =
(struct V_83 * ) V_118 ;
F_26 ( V_4 , V_121 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_39 ) ;
F_41 ( & V_4 -> V_148 ) ;
break;
case V_115 :
V_109 =
(struct V_83 * ) V_118 ;
F_30 ( V_4 , V_109 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_40 ) ;
F_41 ( & V_4 -> V_148 ) ;
break;
case V_149 :
V_104 = (struct V_70 * ) V_118 ;
F_34 ( V_4 , V_104 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_41 ) ;
break;
case V_150 :
V_123 = (struct V_122 * ) V_118 ;
if ( V_123 -> V_64 || ! V_4 -> V_99 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_42 ) ;
F_39 ( V_4 , 1 ) ;
return;
}
if ( V_4 -> V_99 [ V_4 -> V_151 ]
. V_100 == V_123 -> V_152 ) {
V_4 -> V_99 [ V_4 -> V_151 ] . V_101
= V_123 -> V_153 ;
if ( V_4 -> V_136 == V_137 &&
V_4 -> V_138 ==
V_154 ) {
V_4 -> V_155 ++ ;
V_4 -> V_151 ++ ;
V_128 = F_42 ( V_4 ) ;
if ( V_128 < 0 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_43 ) ;
return;
} else if ( ! V_128 ) {
F_43 ( V_4 -> V_156 , V_157 ) ;
V_4 -> V_158 = 0 ;
F_44 ( V_4 -> V_156 , 0 , 3 ) ;
V_4 -> V_136 = V_159 ;
if ( F_45 ( V_4 ) )
F_29 ( V_4 ) ;
}
} else {
F_10 ( & V_4 -> V_35 -> V_4 , L_44 ) ;
F_39 ( V_4 , 1 ) ;
return;
}
} else {
F_10 ( & V_4 -> V_35 -> V_4 , L_45 ) ;
F_39 ( V_4 , 1 ) ;
return;
}
break;
case V_160 :
V_125 = (struct V_124 * ) V_118 ;
memcpy ( V_4 -> V_161 , V_125 -> V_162 , 32 ) ;
if ( V_4 -> V_136 == V_137 &&
V_4 -> V_138 == V_163 ) {
V_4 -> V_140 = 0 ;
V_4 -> V_151 = 0 ;
V_4 -> V_155 = 0 ;
F_46 ( V_4 ) ;
V_4 -> V_138 =
V_154 ;
F_42 ( V_4 ) ;
} else {
F_10 ( & V_4 -> V_35 -> V_4 , L_46 ) ;
F_39 ( V_4 , 1 ) ;
return;
}
break;
case V_164 :
V_4 -> V_136 = V_165 ;
F_10 ( & V_4 -> V_35 -> V_4 , L_47 ) ;
F_39 ( V_4 , 1 ) ;
break;
case V_166 :
V_108 =
(struct V_77 * ) V_118 ;
F_36 ( V_4 , V_108 ) ;
break;
case V_167 :
V_43 = (struct V_42 * ) & V_4 -> V_111 [ 0 ] ;
V_43 -> V_59 = 0 ;
V_43 -> V_46 = 0 ;
V_43 -> V_50 = sizeof( struct V_126 ) ;
V_43 -> V_51 = 1 ;
V_43 -> V_112 = 0 ;
V_127 =
(struct V_126 * ) & V_4 -> V_111 [ 1 ] ;
memset ( V_127 , 0 , sizeof( struct V_126 ) ) ;
V_127 -> V_114 . V_114 = V_144 ;
V_127 -> V_145 = V_146 ;
V_127 -> V_112 [ 0 ] = 0 ;
V_127 -> V_112 [ 1 ] = 0 ;
V_4 -> V_116 = 2 ;
break;
default:
F_33 () ;
break;
}
}
static int F_47 ( struct V_3 * V_4 , T_3 * V_69 ,
struct V_12 * V_13 ,
struct V_10 * V_11 ,
struct V_40 * V_76 )
{
if ( ( * V_69 * sizeof( T_2 ) ) >= ( sizeof( struct V_42 ) +
sizeof( struct V_70 ) ) ) {
* V_69 -= ( sizeof( struct V_42 ) +
sizeof( struct V_70 ) + 3 ) / 4 ;
if ( ! F_21 ( V_4 , V_11 ) ) {
V_11 -> V_64 = - V_53 ;
V_13 -> V_55 = 0 ;
F_24 ( & V_13 -> V_32 ,
& V_76 -> V_34 . V_32 ) ;
return - V_53 ;
} else {
F_24 ( & V_13 -> V_32 ,
& V_4 -> V_63 . V_34 . V_32 ) ;
}
} else {
F_19 ( & V_13 -> V_32 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_48 ( struct V_3 * V_4 , T_3 * V_69 ,
struct V_12 * V_13 ,
struct V_10 * V_11 ,
struct V_40 * V_76 )
{
if ( ( * V_69 * sizeof( T_2 ) ) >= ( sizeof( struct V_42 ) +
sizeof( struct V_168 ) ) ) {
V_11 -> V_60 = V_169 ;
* V_69 -= ( sizeof( struct V_42 ) +
sizeof( struct V_168 ) + 3 ) / 4 ;
if ( ! F_49 ( V_4 , V_11 ) ) {
V_11 -> V_64 = - V_53 ;
V_13 -> V_55 = 0 ;
F_19 ( & V_13 -> V_32 ) ;
return - V_53 ;
} else {
F_24 ( & V_13 -> V_32 ,
& V_4 -> V_79 . V_34 . V_32 ) ;
V_11 -> V_80 = V_81 ;
}
} else {
F_19 ( & V_13 -> V_32 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_50 ( struct V_3 * V_4 , T_3 * V_69 ,
struct V_12 * V_13 ,
struct V_10 * V_11 ,
struct V_40 * V_76 )
{
struct V_42 * V_43 ;
if ( ( * V_69 * sizeof( T_2 ) ) >= ( sizeof( struct V_42 ) +
( V_13 -> V_170 . V_66 -
V_13 -> V_55 ) ) ) {
V_43 = (struct V_42 * ) & V_4 -> V_143 [ 0 ] ;
V_43 -> V_59 = V_11 -> V_58 ;
V_43 -> V_46 = V_11 -> V_47 ;
V_43 -> V_50 = V_13 -> V_170 . V_66 -
V_13 -> V_55 ;
V_43 -> V_51 = 1 ;
V_43 -> V_112 = 0 ;
F_10 ( & V_4 -> V_35 -> V_4 , L_48
L_49 ,
V_13 -> V_170 . V_66 ,
V_43 -> V_51 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_50 ,
V_13 -> V_55 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_51 ,
V_43 -> V_50 ) ;
* V_69 -= ( sizeof( struct V_42 ) +
V_43 -> V_50 + 3 ) / 4 ;
if ( ! F_40 ( V_4 , V_43 ,
( unsigned char * )
( V_13 -> V_170 . V_29 +
V_13 -> V_55 ) ,
V_43 -> V_50 ) ) {
V_11 -> V_64 = - V_53 ;
F_24 ( & V_13 -> V_32 ,
& V_76 -> V_34 . V_32 ) ;
return - V_53 ;
} else {
if ( F_51 ( V_4 , V_11 ) )
return - V_53 ;
V_11 -> V_64 = 0 ;
V_13 -> V_55 += V_43 -> V_50 ;
F_24 ( & V_13 -> V_32 ,
& V_4 -> V_171 . V_34 . V_32 ) ;
}
} else if ( * V_69 == ( ( V_4 -> V_172 & V_173 ) >> 24 ) ) {
V_43 = (struct V_42 * ) & V_4 -> V_143 [ 0 ] ;
V_43 -> V_59 = V_11 -> V_58 ;
V_43 -> V_46 = V_11 -> V_47 ;
V_43 -> V_50 =
( * V_69 * sizeof( T_2 ) ) - sizeof( struct V_42 ) ;
V_43 -> V_51 = 0 ;
V_43 -> V_112 = 0 ;
( * V_69 ) -= ( sizeof( struct V_42 ) +
V_43 -> V_50 + 3 ) / 4 ;
if ( ! F_40 ( V_4 , V_43 ,
( unsigned char * )
( V_13 -> V_170 . V_29 +
V_13 -> V_55 ) ,
V_43 -> V_50 ) ) {
V_11 -> V_64 = - V_53 ;
F_24 ( & V_13 -> V_32 ,
& V_76 -> V_34 . V_32 ) ;
return - V_53 ;
} else {
V_13 -> V_55 += V_43 -> V_50 ;
F_10 ( & V_4 -> V_35 -> V_4 ,
L_48
L_52 ,
V_13 -> V_170 . V_66 ,
V_43 -> V_51 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_50 ,
V_13 -> V_55 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_51 ,
V_43 -> V_50 ) ;
}
return - V_75 ;
} else {
return - V_82 ;
}
return 0 ;
}
static int F_52 ( struct V_3 * V_4 , T_3 * V_69 ,
struct V_12 * V_13 ,
struct V_10 * V_11 ,
struct V_40 * V_76 )
{
struct V_42 * V_43 ;
if ( ( * V_69 * sizeof( T_2 ) ) >= ( sizeof( struct V_42 ) +
V_4 -> V_72 -
V_4 -> V_31 ) ) {
V_43 = (struct V_42 * ) & V_4 -> V_143 [ 0 ] ;
V_43 -> V_59 = V_11 -> V_58 ;
V_43 -> V_46 = V_11 -> V_47 ;
V_43 -> V_50 = V_4 -> V_72 -
V_4 -> V_31 ;
V_43 -> V_51 = 1 ;
V_43 -> V_112 = 0 ;
* V_69 -= ( sizeof( struct V_42 ) +
V_43 -> V_50 + 3 ) / 4 ;
if ( ! F_40 ( V_4 , V_43 ,
( V_4 -> V_30 +
V_4 -> V_31 ) ,
V_43 -> V_50 ) ) {
V_4 -> V_25 = V_92 ;
V_11 -> V_64 = - V_53 ;
F_19 ( & V_13 -> V_32 ) ;
return - V_53 ;
} else {
if ( F_51 ( V_4 , V_11 ) )
return - V_53 ;
V_4 -> V_31 += V_43 -> V_50 ;
V_13 -> V_55 = V_4 -> V_31 ;
V_11 -> V_64 = 0 ;
V_4 -> V_25 = V_174 ;
V_4 -> V_71 = true ;
V_4 -> V_52 = V_13 ;
F_24 ( & V_13 -> V_32 ,
& V_4 -> V_171 . V_34 . V_32 ) ;
}
} else if ( * V_69 == ( ( V_4 -> V_172 & V_173 ) >> 24 ) ) {
V_43 = (struct V_42 * ) & V_4 -> V_143 [ 0 ] ;
V_43 -> V_59 = V_11 -> V_58 ;
V_43 -> V_46 = V_11 -> V_47 ;
V_43 -> V_50 =
( * V_69 * sizeof( T_2 ) ) - sizeof( struct V_42 ) ;
V_43 -> V_51 = 0 ;
V_43 -> V_112 = 0 ;
* V_69 -= ( sizeof( struct V_42 ) +
V_43 -> V_50 + 3 ) / 4 ;
if ( ! F_40 ( V_4 , V_43 ,
( V_4 -> V_30 +
V_4 -> V_31 ) ,
V_43 -> V_50 ) ) {
V_11 -> V_64 = - V_53 ;
F_19 ( & V_13 -> V_32 ) ;
} else {
V_4 -> V_31 += V_43 -> V_50 ;
}
return - V_75 ;
} else {
return - V_82 ;
}
return 0 ;
}
static int F_53 ( struct V_40 * V_76 ,
struct V_3 * V_4 ,
T_3 * V_69 )
{
struct V_42 * V_43 ;
struct V_10 * V_105 = NULL ;
struct V_10 * V_106 = NULL ;
int V_175 = 0 ;
if ( ! V_4 -> V_176 ) {
V_4 -> V_176 = F_54 ( V_4 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_53 , * V_69 ) ;
( * V_69 ) -- ;
F_10 ( & V_4 -> V_35 -> V_4 , L_53 , * V_69 ) ;
}
V_43 = (struct V_42 * ) & V_4 -> V_176 ;
F_10 ( & V_4 -> V_35 -> V_4 , L_54 , V_43 -> V_50 ) ;
if ( V_43 -> V_112 || ! V_4 -> V_176 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_55 ) ;
V_175 = - V_82 ;
goto V_177;
}
if ( V_43 -> V_59 || V_43 -> V_46 ) {
F_18 (cl_pos, cl_next,
&dev->file_list, link) {
F_10 ( & V_4 -> V_35 -> V_4 ,
L_56
L_57 ,
V_105 -> V_58 ,
V_105 -> V_47 ) ;
if ( V_105 -> V_58 == V_43 -> V_59 &&
V_105 -> V_47 == V_43 -> V_46 )
break;
}
if ( & V_105 -> V_178 == & V_4 -> V_179 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_58 ) ;
V_175 = - V_82 ;
goto V_177;
}
}
if ( ( ( * V_69 ) * sizeof( T_2 ) ) < V_43 -> V_50 ) {
F_10 ( & V_4 -> V_35 -> V_4 ,
L_59 ,
* V_69 ) ;
V_175 = - V_180 ;
goto V_177;
}
if ( ! V_43 -> V_59 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_60 ) ;
F_37 ( V_4 , V_43 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_61 ) ;
} else if ( V_43 -> V_59 == V_4 -> V_38 . V_58 &&
( V_61 == V_4 -> V_38 . V_60 ) &&
( V_4 -> V_25 == V_48 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_62 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_54 ,
V_43 -> V_50 ) ;
V_175 = F_12 ( V_76 ,
V_4 , V_43 ) ;
if ( V_175 )
goto V_177;
} else {
F_10 ( & V_4 -> V_35 -> V_4 , L_63 ) ;
V_175 = F_16 ( V_76 ,
V_4 , V_43 ) ;
if ( V_175 )
goto V_177;
}
* V_69 = F_55 ( V_4 ) ;
V_4 -> V_176 = 0 ;
if ( * V_69 == - V_181 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_64 ) ;
V_175 = - V_180 ;
goto V_177;
}
V_177:
return V_175 ;
}
static int F_56 ( struct V_40 * V_76 ,
struct V_3 * V_4 ,
T_3 * V_69 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = NULL , * V_62 = NULL ;
struct V_40 * V_182 ;
int V_175 ;
if ( ! V_74 ( V_4 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_65 ) ;
return 0 ;
}
* V_69 = F_57 ( V_4 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_66 ) ;
V_182 = & V_4 -> V_171 ;
if ( ! V_182 -> V_64 && ! F_17 ( & V_182 -> V_34 . V_32 ) ) {
F_18 (cb_pos, cb_next,
&list->mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * ) V_13 -> V_54 ;
if ( V_11 ) {
V_11 -> V_64 = 0 ;
F_19 ( & V_13 -> V_32 ) ;
if ( V_183 == V_11 -> V_16 &&
( V_13 -> V_14 ==
V_15 ) &&
( V_11 != & V_4 -> V_38 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 ,
L_67 ) ;
V_11 -> V_16 =
V_17 ;
F_9 ( & V_13 -> V_32 ,
& V_76 -> V_34 . V_32 ) ;
}
if ( V_11 == & V_4 -> V_38 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_68 ) ;
if ( V_4 -> V_71 ) {
V_175 =
F_20 (
V_4 , V_69 ) ;
if ( V_175 )
return V_175 ;
}
}
}
}
}
if ( V_4 -> V_184 && ! V_4 -> V_110 ) {
V_4 -> V_185 = true ;
F_7 ( & V_4 -> V_186 ) ;
return 0 ;
}
if ( V_4 -> V_116 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_69 ,
V_4 -> V_116 ) ;
F_40 ( V_4 ,
(struct V_42 * ) & V_4 -> V_111 [ 0 ] ,
( unsigned char * ) & V_4 -> V_111 [ 1 ] ,
( V_4 -> V_116 - 1 ) * sizeof( T_2 ) ) ;
* V_69 -= V_4 -> V_116 ;
V_4 -> V_116 = 0 ;
}
if ( V_4 -> V_136 == V_159 ) {
if ( V_4 -> V_110 &&
V_103 ( V_4 , & V_4 -> V_86 ) > 0 ) {
if ( F_58 ( V_4 ) )
F_10 ( & V_4 -> V_35 -> V_4 , L_70 ) ;
else
if ( F_51 ( V_4 , & V_4 -> V_86 ) )
return - V_53 ;
V_4 -> V_110 = false ;
if ( V_4 -> V_87 ) {
* V_69 -= ( sizeof( struct V_42 ) +
V_187 + 3 ) / 4 ;
V_4 -> V_88 = 2 ;
} else {
* V_69 -= ( sizeof( struct V_42 ) +
V_188 + 3 ) / 4 ;
V_4 -> V_88 = 0 ;
}
}
}
if ( V_4 -> V_184 )
return ~ V_53 ;
if ( ! V_4 -> V_189 . V_64 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_71 ) ;
F_18 (cb_pos, cb_next,
&dev->ctrl_wr_list.mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * )
V_13 -> V_54 ;
if ( ! V_11 ) {
F_19 ( & V_13 -> V_32 ) ;
return - V_53 ;
}
switch ( V_13 -> V_14 ) {
case V_190 :
V_175 = F_22 ( V_4 , V_69 ,
V_13 , V_11 , V_76 ) ;
if ( V_175 )
return V_175 ;
break;
case V_19 :
V_175 = F_47 ( V_4 , V_69 ,
V_13 , V_11 , V_76 ) ;
if ( V_175 )
return V_175 ;
break;
case V_93 :
if ( ! F_59 ( V_4 ,
V_11 ) )
continue;
V_175 = F_48 ( V_4 , V_69 ,
V_13 , V_11 , V_76 ) ;
if ( V_175 )
return V_175 ;
break;
default:
F_33 () ;
}
}
}
if ( ! V_4 -> V_191 . V_64 &&
! F_17 ( & V_4 -> V_191 . V_34 . V_32 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_72 ) ;
F_18 (cb_pos, cb_next,
&dev->write_list.mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * ) V_13 -> V_54 ;
if ( V_11 ) {
if ( V_11 != & V_4 -> V_38 ) {
if ( ! V_103 ( V_4 ,
V_11 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 ,
L_73
L_74
L_75 ,
V_11 -> V_58 ) ;
continue;
}
V_175 = F_50 ( V_4 , V_69 ,
V_13 ,
V_11 , V_76 ) ;
if ( V_175 )
return V_175 ;
} else if ( V_11 == & V_4 -> V_38 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_76 ) ;
if ( ! V_103 ( V_4 ,
V_11 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 ,
L_73
L_77
L_78 ,
V_11 -> V_58 ) ;
continue;
}
V_175 = F_52 ( V_4 ,
V_69 ,
V_13 ,
V_11 ,
V_76 ) ;
if ( V_175 )
return V_175 ;
}
}
}
}
return 0 ;
}
void F_60 ( struct V_192 * V_193 )
{
unsigned long V_194 ;
struct V_10 * V_105 = NULL ;
struct V_10 * V_106 = NULL ;
struct V_195 * V_196 = NULL ;
struct V_12 * V_13 = NULL ;
struct V_12 * V_62 = NULL ;
struct V_3 * V_4 = F_61 ( V_193 ,
struct V_3 , V_197 . V_193 ) ;
F_62 ( & V_4 -> V_198 ) ;
if ( V_4 -> V_136 != V_159 ) {
if ( V_4 -> V_136 == V_137 ) {
if ( V_4 -> V_140 ) {
if ( -- V_4 -> V_140 == 0 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_79 ,
V_4 -> V_138 ) ;
F_39 ( V_4 , 1 ) ;
}
}
}
goto V_199;
}
F_18 (cl_pos, cl_next, &dev->file_list, link) {
if ( V_105 -> V_80 ) {
if ( -- V_105 -> V_80 == 0 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_80 ) ;
F_39 ( V_4 , 1 ) ;
goto V_199;
}
}
}
if ( V_4 -> V_27 ) {
if ( -- V_4 -> V_27 == 0 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_81 ) ;
F_39 ( V_4 , 1 ) ;
V_4 -> V_72 = 0 ;
V_4 -> V_31 = 0 ;
V_4 -> V_24 = false ;
V_4 -> V_57 = true ;
V_4 -> V_25 = V_92 ;
V_4 -> V_36 = 0 ;
if ( V_4 -> V_52 )
F_5 ( V_4 -> V_52 ) ;
V_4 -> V_200 = NULL ;
V_4 -> V_52 = NULL ;
F_11 ( V_4 ) ;
}
}
if ( V_4 -> V_36 ) {
V_194 = V_4 -> V_36 +
F_63 ( V_201 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_2 ,
V_4 -> V_36 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_82 , V_194 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_83 , V_37 ) ;
if ( F_64 ( V_37 , V_194 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_84 ) ;
V_196 = & V_4 -> V_33 .
V_34 . V_32 ;
if ( ! F_17 ( V_196 ) ) {
F_18 (cb_pos, cb_next,
amthi_complete_list,
cb_list) {
V_105 = V_13 -> V_202 -> V_203 ;
if ( V_105 == & V_4 -> V_38 )
F_19 ( & V_13 -> V_32 ) ;
}
}
if ( V_4 -> V_52 )
F_5 ( V_4 -> V_52 ) ;
V_4 -> V_200 -> V_203 = NULL ;
V_4 -> V_200 = NULL ;
V_4 -> V_52 = NULL ;
V_4 -> V_36 = 0 ;
F_11 ( V_4 ) ;
}
}
V_199:
F_65 ( & V_4 -> V_197 , 2 * V_204 ) ;
F_66 ( & V_4 -> V_198 ) ;
}
T_1 F_67 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_40 V_41 ;
struct V_12 * V_13 = NULL , * V_62 = NULL ;
struct V_10 * V_11 ;
T_3 V_69 ;
int V_205 ;
bool V_206 ;
F_10 ( & V_4 -> V_35 -> V_4 , L_85 ) ;
F_62 ( & V_4 -> V_198 ) ;
F_68 ( & V_41 ) ;
V_4 -> V_172 = F_2 ( V_4 ) ;
if ( F_69 ( V_4 -> V_35 ) )
F_3 ( V_4 , V_8 , V_4 -> V_172 ) ;
V_4 -> V_207 = F_70 ( V_4 ) ;
if ( ( V_4 -> V_207 & V_208 ) == 0 &&
V_4 -> V_136 != V_209 &&
V_4 -> V_136 != V_210 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_86 ) ;
F_39 ( V_4 , 1 ) ;
F_66 ( & V_4 -> V_198 ) ;
return V_211 ;
}
if ( ( V_4 -> V_172 & V_212 ) == 0 ) {
if ( ( V_4 -> V_207 & V_208 ) == V_208 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_87 ) ;
V_4 -> V_172 |= ( V_213 | V_214 | V_212 ) ;
F_71 ( V_4 ) ;
V_4 -> V_136 = V_137 ;
F_10 ( & V_4 -> V_35 -> V_4 , L_88 ) ;
F_72 ( V_4 ) ;
F_66 ( & V_4 -> V_198 ) ;
return V_211 ;
} else {
F_10 ( & V_4 -> V_35 -> V_4 , L_86 ) ;
F_66 ( & V_4 -> V_198 ) ;
return V_211 ;
}
}
V_69 = F_55 ( V_4 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_89 ,
V_69 , V_4 -> V_116 ) ;
while ( V_69 > 0 && ! V_4 -> V_116 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_89 ,
V_69 , V_4 -> V_116 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_90 ) ;
V_205 = F_53 ( & V_41 , V_4 , & V_69 ) ;
if ( V_205 )
goto V_177;
}
V_205 = F_56 ( & V_41 , V_4 , & V_69 ) ;
V_177:
F_10 ( & V_4 -> V_35 -> V_4 , L_91 ) ;
V_4 -> V_172 = F_2 ( V_4 ) ;
V_4 -> V_74 = V_74 ( V_4 ) ;
V_206 = false ;
if ( V_4 -> V_141 && F_6 ( & V_4 -> V_148 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_92 ) ;
V_206 = true ;
}
F_66 ( & V_4 -> V_198 ) ;
if ( V_206 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_93 ) ;
F_7 ( & V_4 -> V_148 ) ;
V_206 = false ;
}
if ( V_41 . V_64 || F_17 ( & V_41 . V_34 . V_32 ) )
return V_211 ;
F_18 (cb_pos, cb_next,
&complete_list.mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * ) V_13 -> V_54 ;
F_19 ( & V_13 -> V_32 ) ;
if ( V_11 ) {
if ( V_11 != & V_4 -> V_38 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_94 ) ;
F_4 ( V_11 , V_13 ) ;
V_13 = NULL ;
} else if ( V_11 == & V_4 -> V_38 ) {
F_8 ( V_4 , V_13 ) ;
}
}
}
return V_211 ;
}
