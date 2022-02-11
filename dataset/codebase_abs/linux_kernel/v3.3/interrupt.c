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
if ( F_17 ( & V_4 -> V_63 . V_34 . V_32 ) )
goto V_64;
F_18 (cb_pos, cb_next,
&dev->read_list.mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * ) V_13 -> V_54 ;
if ( V_11 && F_15 ( V_11 , V_43 ) ) {
V_11 -> V_21 = V_20 ;
V_45 = ( unsigned char * )
( V_13 -> V_28 . V_29 +
V_13 -> V_55 ) ;
if ( V_13 -> V_28 . V_65 <
V_43 -> V_50 + V_13 -> V_55 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_9 ) ;
F_19 ( & V_13 -> V_32 ) ;
return - V_66 ;
}
if ( V_45 )
F_14 ( V_4 , V_45 , V_43 -> V_50 ) ;
V_13 -> V_55 += V_43 -> V_50 ;
if ( V_43 -> V_51 ) {
V_11 -> V_67 = 0 ;
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
V_64:
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
V_11 -> V_67 = 0 ;
V_13 -> V_55 = 0 ;
F_24 ( & V_13 -> V_32 ,
& V_76 -> V_34 . V_32 ) ;
return - V_75 ;
} else {
V_11 -> V_60 = V_78 ;
V_11 -> V_67 = 0 ;
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
if ( ! V_84 -> V_67 ) {
V_11 -> V_60 = V_61 ;
V_11 -> V_67 = 0 ;
} else {
V_11 -> V_60 = V_85 ;
V_11 -> V_67 = - V_53 ;
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
V_84 -> V_67 ) ;
if ( F_25 ( & ( V_4 -> V_86 ) , V_84 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_22 ) ;
F_27 ( V_4 ) ;
F_28 ( V_4 ) ;
return;
}
if ( F_25 ( & ( V_4 -> V_38 ) , V_84 ) ) {
V_4 -> V_25 = V_87 ;
return;
}
F_18 (cb_pos, cb_next,
&dev->ctrl_rd_list.mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * ) V_13 -> V_54 ;
if ( ! V_11 ) {
F_19 ( & V_13 -> V_32 ) ;
return;
}
if ( V_88 == V_13 -> V_14 ) {
if ( F_25 ( V_11 , V_84 ) ) {
F_19 ( & V_13 -> V_32 ) ;
V_11 -> V_67 = 0 ;
V_11 -> V_80 = 0 ;
break;
}
}
}
}
static void F_29 ( struct V_3 * V_4 ,
struct V_83 * V_84 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 = NULL , * V_62 = NULL ;
F_10 ( & V_4 -> V_35 -> V_4 ,
L_23
L_19
L_20
L_21 ,
V_84 -> V_46 ,
V_84 -> V_59 ,
V_84 -> V_67 ) ;
F_18 (cb_pos, cb_next,
&dev->ctrl_rd_list.mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * ) V_13 -> V_54 ;
if ( ! V_11 ) {
F_19 ( & V_13 -> V_32 ) ;
return;
}
F_10 ( & V_4 -> V_35 -> V_4 , L_24 ) ;
if ( V_11 -> V_58 == V_84 -> V_59 &&
V_11 -> V_47 == V_84 -> V_46 ) {
F_19 ( & V_13 -> V_32 ) ;
if ( ! V_84 -> V_67 )
V_11 -> V_60 = V_85 ;
V_11 -> V_67 = 0 ;
V_11 -> V_80 = 0 ;
break;
}
}
}
static int F_30 ( struct V_10 * V_11 , struct V_70 * V_89 )
{
return ( V_11 -> V_58 == V_89 -> V_59 &&
V_11 -> V_47 == V_89 -> V_46 ) ;
}
static void F_31 ( struct V_3 * V_4 ,
struct V_70 * V_89 )
{
struct V_90 * V_91 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_4 -> V_93 ; V_92 ++ ) {
V_91 = & V_4 -> V_94 [ V_92 ] ;
if ( V_91 && V_89 -> V_46 == V_91 -> V_95 ) {
if ( V_91 -> V_96 . V_97 ) {
V_91 -> V_98 ++ ;
F_10 ( & V_4 -> V_35 -> V_4 , L_25 ,
V_89 -> V_46 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_26 ,
V_91 -> V_98 ) ;
} else {
F_32 () ;
}
}
}
}
static void F_33 ( struct V_3 * V_4 ,
struct V_70 * V_99 )
{
struct V_10 * V_100 = NULL ;
struct V_10 * V_101 = NULL ;
if ( ! V_99 -> V_59 ) {
F_31 ( V_4 , V_99 ) ;
} else {
F_18 (cl_pos, cl_next,
&dev->file_list, link) {
F_10 ( & V_4 -> V_35 -> V_4 , L_27 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_28 ,
V_100 -> V_58 ,
V_100 -> V_47 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_29 ,
V_99 -> V_59 ,
V_99 -> V_46 ) ;
if ( F_30 ( V_100 , V_99 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_30 ,
V_99 -> V_59 ,
V_99 -> V_46 ) ;
V_100 -> V_98 ++ ;
F_10 ( & V_4 -> V_35 -> V_4 , L_31 ,
V_100 -> V_98 ) ;
break;
}
}
}
}
static int F_34 ( struct V_10 * V_11 ,
struct V_77 * V_102 )
{
return ( V_11 -> V_58 == V_102 -> V_59 &&
V_11 -> V_47 == V_102 -> V_46 ) ;
}
static void F_35 ( struct V_3 * V_4 ,
struct V_77 * V_103 )
{
struct V_42 * V_43 ;
struct V_83 * V_104 ;
struct V_10 * V_100 = NULL ;
struct V_10 * V_101 = NULL ;
F_18 (cl_pos, cl_next, &dev->file_list, link) {
if ( F_34 ( V_100 , V_103 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_32 ,
V_103 -> V_59 ,
V_103 -> V_46 ) ;
V_100 -> V_60 = V_85 ;
V_100 -> V_80 = 0 ;
if ( V_100 == & V_4 -> V_86 ) {
V_4 -> V_105 = 0 ;
V_4 -> V_106 = false ;
} else if ( V_100 == & V_4 -> V_38 )
V_4 -> V_36 = 0 ;
V_43 =
(struct V_42 * ) & V_4 -> V_107 [ 0 ] ;
V_43 -> V_59 = 0 ;
V_43 -> V_46 = 0 ;
V_43 -> V_50 =
sizeof( struct V_83 ) ;
V_43 -> V_51 = 1 ;
V_43 -> V_108 = 0 ;
V_104 =
(struct V_83 * )
& V_4 -> V_107 [ 1 ] ;
V_104 -> V_59 = V_100 -> V_58 ;
V_104 -> V_46 = V_100 -> V_47 ;
* ( V_109 * ) ( & V_104 -> V_110 ) =
V_111 ;
V_104 -> V_67 = 0 ;
V_4 -> V_112 = 2 ;
break;
}
}
}
static void F_36 ( struct V_3 * V_4 ,
struct V_42 * V_43 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 ;
struct V_83 * V_117 ;
struct V_83 * V_104 ;
struct V_70 * V_99 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
struct V_77 * V_103 ;
struct V_122 * V_123 ;
int V_124 ;
unsigned char * V_45 ;
V_45 = ( unsigned char * ) V_4 -> V_68 ;
F_13 ( V_43 -> V_50 >= sizeof( V_4 -> V_68 ) ) ;
F_14 ( V_4 , V_45 , V_43 -> V_50 ) ;
V_114 = (struct V_113 * ) V_45 ;
switch ( * ( V_109 * ) V_114 ) {
case V_125 :
V_116 = (struct V_115 * ) V_114 ;
if ( V_116 -> V_126 ) {
V_4 -> V_127 . V_128 = V_129 ;
V_4 -> V_127 . V_130 = V_131 ;
if ( V_4 -> V_132 == V_133 &&
V_4 -> V_134 == V_135 ) {
V_4 -> V_136 = 0 ;
F_37 ( V_4 ) ;
} else {
V_4 -> V_137 = false ;
F_10 ( & V_4 -> V_35 -> V_4 , L_33 ) ;
F_38 ( V_4 , 1 ) ;
return;
}
} else {
V_4 -> V_127 = V_116 -> V_138 ;
V_43 -> V_59 = 0 ;
V_43 -> V_46 = 0 ;
V_43 -> V_50 = sizeof( struct V_122 ) ;
V_43 -> V_51 = 1 ;
V_43 -> V_108 = 0 ;
V_123 = (struct V_122 * )
& V_4 -> V_139 [ 1 ] ;
memset ( V_123 ,
0 ,
sizeof( struct V_122 ) ) ;
V_123 -> V_110 . V_110 = V_140 ;
V_123 -> V_141 = V_142 ;
F_39 ( V_4 , V_43 ,
( unsigned char * ) ( V_123 ) ,
V_43 -> V_50 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_34 ) ;
return;
}
V_4 -> V_137 = true ;
F_10 ( & V_4 -> V_35 -> V_4 , L_35 ) ;
break;
case V_143 :
V_117 =
(struct V_83 * ) V_114 ;
F_26 ( V_4 , V_117 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_36 ) ;
F_40 ( & V_4 -> V_144 ) ;
break;
case V_111 :
V_104 =
(struct V_83 * ) V_114 ;
F_29 ( V_4 , V_104 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_37 ) ;
F_40 ( & V_4 -> V_144 ) ;
break;
case V_145 :
V_99 = (struct V_70 * ) V_114 ;
F_33 ( V_4 , V_99 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_38 ) ;
break;
case V_146 :
V_119 = (struct V_118 * ) V_114 ;
if ( V_119 -> V_67 || ! V_4 -> V_94 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_39 ) ;
F_38 ( V_4 , 1 ) ;
return;
}
if ( V_4 -> V_94 [ V_4 -> V_147 ]
. V_95 == V_119 -> V_148 ) {
V_4 -> V_94 [ V_4 -> V_147 ] . V_96
= V_119 -> V_149 ;
if ( V_4 -> V_132 == V_133 &&
V_4 -> V_134 ==
V_150 ) {
V_4 -> V_151 ++ ;
V_4 -> V_147 ++ ;
V_124 = F_41 ( V_4 ) ;
if ( V_124 < 0 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_40 ) ;
return;
} else if ( ! V_124 ) {
F_42 ( V_4 -> V_152 , V_153 ) ;
V_4 -> V_154 = 0 ;
F_43 ( V_4 -> V_152 , 0 , 3 ) ;
V_4 -> V_132 = V_155 ;
if ( F_44 ( V_4 ) )
F_28 ( V_4 ) ;
}
} else {
F_10 ( & V_4 -> V_35 -> V_4 , L_41 ) ;
F_38 ( V_4 , 1 ) ;
return;
}
} else {
F_10 ( & V_4 -> V_35 -> V_4 , L_42 ) ;
F_38 ( V_4 , 1 ) ;
return;
}
break;
case V_156 :
V_121 = (struct V_120 * ) V_114 ;
memcpy ( V_4 -> V_157 , V_121 -> V_158 , 32 ) ;
if ( V_4 -> V_132 == V_133 &&
V_4 -> V_134 == V_159 ) {
V_4 -> V_136 = 0 ;
V_4 -> V_147 = 0 ;
V_4 -> V_151 = 0 ;
F_45 ( V_4 ) ;
V_4 -> V_134 =
V_150 ;
F_41 ( V_4 ) ;
} else {
F_10 ( & V_4 -> V_35 -> V_4 , L_43 ) ;
F_38 ( V_4 , 1 ) ;
return;
}
break;
case V_160 :
V_4 -> V_132 = V_161 ;
F_10 ( & V_4 -> V_35 -> V_4 , L_44 ) ;
F_38 ( V_4 , 1 ) ;
break;
case V_162 :
V_103 =
(struct V_77 * ) V_114 ;
F_35 ( V_4 , V_103 ) ;
break;
case V_163 :
V_43 = (struct V_42 * ) & V_4 -> V_107 [ 0 ] ;
V_43 -> V_59 = 0 ;
V_43 -> V_46 = 0 ;
V_43 -> V_50 = sizeof( struct V_122 ) ;
V_43 -> V_51 = 1 ;
V_43 -> V_108 = 0 ;
V_123 =
(struct V_122 * ) & V_4 -> V_107 [ 1 ] ;
memset ( V_123 , 0 , sizeof( struct V_122 ) ) ;
V_123 -> V_110 . V_110 = V_140 ;
V_123 -> V_141 = V_142 ;
V_123 -> V_108 [ 0 ] = 0 ;
V_123 -> V_108 [ 1 ] = 0 ;
V_4 -> V_112 = 2 ;
break;
default:
F_32 () ;
break;
}
}
static int F_46 ( struct V_3 * V_4 , T_3 * V_69 ,
struct V_12 * V_13 ,
struct V_10 * V_11 ,
struct V_40 * V_76 )
{
if ( ( * V_69 * sizeof( T_2 ) ) >= ( sizeof( struct V_42 ) +
sizeof( struct V_70 ) ) ) {
* V_69 -= ( sizeof( struct V_42 ) +
sizeof( struct V_70 ) + 3 ) / 4 ;
if ( ! F_21 ( V_4 , V_11 ) ) {
V_11 -> V_67 = - V_53 ;
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
static int F_47 ( struct V_3 * V_4 , T_3 * V_69 ,
struct V_12 * V_13 ,
struct V_10 * V_11 ,
struct V_40 * V_76 )
{
if ( ( * V_69 * sizeof( T_2 ) ) >= ( sizeof( struct V_42 ) +
sizeof( struct V_164 ) ) ) {
V_11 -> V_60 = V_165 ;
* V_69 -= ( sizeof( struct V_42 ) +
sizeof( struct V_164 ) + 3 ) / 4 ;
if ( ! F_48 ( V_4 , V_11 ) ) {
V_11 -> V_67 = - V_53 ;
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
static int F_49 ( struct V_3 * V_4 , T_3 * V_69 ,
struct V_12 * V_13 ,
struct V_10 * V_11 ,
struct V_40 * V_76 )
{
struct V_42 * V_43 ;
if ( ( * V_69 * sizeof( T_2 ) ) >= ( sizeof( struct V_42 ) +
( V_13 -> V_166 . V_65 -
V_13 -> V_55 ) ) ) {
V_43 = (struct V_42 * ) & V_4 -> V_139 [ 0 ] ;
V_43 -> V_59 = V_11 -> V_58 ;
V_43 -> V_46 = V_11 -> V_47 ;
V_43 -> V_50 = V_13 -> V_166 . V_65 -
V_13 -> V_55 ;
V_43 -> V_51 = 1 ;
V_43 -> V_108 = 0 ;
F_10 ( & V_4 -> V_35 -> V_4 , L_45
L_46 ,
V_13 -> V_166 . V_65 ,
V_43 -> V_51 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_47 ,
V_13 -> V_55 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_48 ,
V_43 -> V_50 ) ;
* V_69 -= ( sizeof( struct V_42 ) +
V_43 -> V_50 + 3 ) / 4 ;
if ( ! F_39 ( V_4 , V_43 ,
( unsigned char * )
( V_13 -> V_166 . V_29 +
V_13 -> V_55 ) ,
V_43 -> V_50 ) ) {
V_11 -> V_67 = - V_53 ;
F_24 ( & V_13 -> V_32 ,
& V_76 -> V_34 . V_32 ) ;
return - V_53 ;
} else {
if ( F_50 ( V_4 , V_11 ) )
return - V_53 ;
V_11 -> V_67 = 0 ;
V_13 -> V_55 += V_43 -> V_50 ;
F_24 ( & V_13 -> V_32 ,
& V_4 -> V_167 . V_34 . V_32 ) ;
}
} else if ( * V_69 == ( ( V_4 -> V_168 & V_169 ) >> 24 ) ) {
V_43 = (struct V_42 * ) & V_4 -> V_139 [ 0 ] ;
V_43 -> V_59 = V_11 -> V_58 ;
V_43 -> V_46 = V_11 -> V_47 ;
V_43 -> V_50 =
( * V_69 * sizeof( T_2 ) ) - sizeof( struct V_42 ) ;
V_43 -> V_51 = 0 ;
V_43 -> V_108 = 0 ;
( * V_69 ) -= ( sizeof( struct V_42 ) +
V_43 -> V_50 + 3 ) / 4 ;
if ( ! F_39 ( V_4 , V_43 ,
( unsigned char * )
( V_13 -> V_166 . V_29 +
V_13 -> V_55 ) ,
V_43 -> V_50 ) ) {
V_11 -> V_67 = - V_53 ;
F_24 ( & V_13 -> V_32 ,
& V_76 -> V_34 . V_32 ) ;
return - V_53 ;
} else {
V_13 -> V_55 += V_43 -> V_50 ;
F_10 ( & V_4 -> V_35 -> V_4 ,
L_45
L_49 ,
V_13 -> V_166 . V_65 ,
V_43 -> V_51 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_47 ,
V_13 -> V_55 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_48 ,
V_43 -> V_50 ) ;
}
return - V_75 ;
} else {
return - V_82 ;
}
return 0 ;
}
static int F_51 ( struct V_3 * V_4 , T_3 * V_69 ,
struct V_12 * V_13 ,
struct V_10 * V_11 ,
struct V_40 * V_76 )
{
struct V_42 * V_43 ;
if ( ( * V_69 * sizeof( T_2 ) ) >= ( sizeof( struct V_42 ) +
V_4 -> V_72 -
V_4 -> V_31 ) ) {
V_43 = (struct V_42 * ) & V_4 -> V_139 [ 0 ] ;
V_43 -> V_59 = V_11 -> V_58 ;
V_43 -> V_46 = V_11 -> V_47 ;
V_43 -> V_50 = V_4 -> V_72 -
V_4 -> V_31 ;
V_43 -> V_51 = 1 ;
V_43 -> V_108 = 0 ;
* V_69 -= ( sizeof( struct V_42 ) +
V_43 -> V_50 + 3 ) / 4 ;
if ( ! F_39 ( V_4 , V_43 ,
( V_4 -> V_30 +
V_4 -> V_31 ) ,
V_43 -> V_50 ) ) {
V_4 -> V_25 = V_87 ;
V_11 -> V_67 = - V_53 ;
F_19 ( & V_13 -> V_32 ) ;
return - V_53 ;
} else {
if ( F_50 ( V_4 , V_11 ) )
return - V_53 ;
V_4 -> V_31 += V_43 -> V_50 ;
V_13 -> V_55 = V_4 -> V_31 ;
V_11 -> V_67 = 0 ;
V_4 -> V_25 = V_170 ;
V_4 -> V_71 = true ;
V_4 -> V_52 = V_13 ;
F_24 ( & V_13 -> V_32 ,
& V_4 -> V_167 . V_34 . V_32 ) ;
}
} else if ( * V_69 == ( ( V_4 -> V_168 & V_169 ) >> 24 ) ) {
V_43 = (struct V_42 * ) & V_4 -> V_139 [ 0 ] ;
V_43 -> V_59 = V_11 -> V_58 ;
V_43 -> V_46 = V_11 -> V_47 ;
V_43 -> V_50 =
( * V_69 * sizeof( T_2 ) ) - sizeof( struct V_42 ) ;
V_43 -> V_51 = 0 ;
V_43 -> V_108 = 0 ;
* V_69 -= ( sizeof( struct V_42 ) +
V_43 -> V_50 + 3 ) / 4 ;
if ( ! F_39 ( V_4 , V_43 ,
( V_4 -> V_30 +
V_4 -> V_31 ) ,
V_43 -> V_50 ) ) {
V_11 -> V_67 = - V_53 ;
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
static int F_52 ( struct V_40 * V_76 ,
struct V_3 * V_4 ,
T_3 * V_69 )
{
struct V_42 * V_43 ;
struct V_10 * V_100 = NULL ;
struct V_10 * V_101 = NULL ;
int V_171 = 0 ;
if ( ! V_4 -> V_172 ) {
V_4 -> V_172 = F_53 ( V_4 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_50 , * V_69 ) ;
( * V_69 ) -- ;
F_10 ( & V_4 -> V_35 -> V_4 , L_50 , * V_69 ) ;
}
V_43 = (struct V_42 * ) & V_4 -> V_172 ;
F_10 ( & V_4 -> V_35 -> V_4 , L_51 , V_43 -> V_50 ) ;
if ( V_43 -> V_108 || ! V_4 -> V_172 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_52 ) ;
V_171 = - V_82 ;
goto V_173;
}
if ( V_43 -> V_59 || V_43 -> V_46 ) {
F_18 (cl_pos, cl_next,
&dev->file_list, link) {
F_10 ( & V_4 -> V_35 -> V_4 ,
L_53
L_54 ,
V_100 -> V_58 ,
V_100 -> V_47 ) ;
if ( V_100 -> V_58 == V_43 -> V_59 &&
V_100 -> V_47 == V_43 -> V_46 )
break;
}
if ( & V_100 -> V_174 == & V_4 -> V_175 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_55 ) ;
V_171 = - V_82 ;
goto V_173;
}
}
if ( ( ( * V_69 ) * sizeof( T_2 ) ) < V_43 -> V_50 ) {
F_10 ( & V_4 -> V_35 -> V_4 ,
L_56 ,
* V_69 ) ;
V_171 = - V_176 ;
goto V_173;
}
if ( ! V_43 -> V_59 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_57 ) ;
F_36 ( V_4 , V_43 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_58 ) ;
} else if ( V_43 -> V_59 == V_4 -> V_38 . V_58 &&
( V_61 == V_4 -> V_38 . V_60 ) &&
( V_4 -> V_25 == V_48 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_59 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_51 ,
V_43 -> V_50 ) ;
V_171 = F_12 ( V_76 ,
V_4 , V_43 ) ;
if ( V_171 )
goto V_173;
} else {
F_10 ( & V_4 -> V_35 -> V_4 , L_60 ) ;
V_171 = F_16 ( V_76 ,
V_4 , V_43 ) ;
if ( V_171 )
goto V_173;
}
* V_69 = F_54 ( V_4 ) ;
V_4 -> V_172 = 0 ;
if ( * V_69 == - V_177 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_61 ) ;
V_171 = - V_176 ;
goto V_173;
}
V_173:
return V_171 ;
}
static int F_55 ( struct V_40 * V_76 ,
struct V_3 * V_4 ,
T_3 * V_69 )
{
struct V_10 * V_11 ;
struct V_12 * V_178 = NULL , * V_179 = NULL ;
struct V_40 * V_180 ;
int V_171 ;
if ( ! V_74 ( V_4 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_62 ) ;
return 0 ;
}
* V_69 = F_56 ( V_4 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_63 ) ;
V_180 = & V_4 -> V_167 ;
F_18 (pos, next,
&list->mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * ) V_178 -> V_54 ;
if ( V_11 == NULL )
continue;
V_11 -> V_67 = 0 ;
F_19 ( & V_178 -> V_32 ) ;
if ( V_181 == V_11 -> V_16 &&
( V_178 -> V_14 == V_15 ) &&
( V_11 != & V_4 -> V_38 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 ,
L_64 ) ;
V_11 -> V_16 = V_17 ;
F_9 ( & V_178 -> V_32 ,
& V_76 -> V_34 . V_32 ) ;
}
if ( V_11 == & V_4 -> V_38 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_65 ) ;
if ( V_4 -> V_71 ) {
V_171 = F_20 (
V_4 , V_69 ) ;
if ( V_171 )
return V_171 ;
}
}
}
if ( V_4 -> V_182 && ! V_4 -> V_106 ) {
V_4 -> V_183 = true ;
F_7 ( & V_4 -> V_184 ) ;
return 0 ;
}
if ( V_4 -> V_112 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_66 ,
V_4 -> V_112 ) ;
F_39 ( V_4 ,
(struct V_42 * ) & V_4 -> V_107 [ 0 ] ,
( unsigned char * ) & V_4 -> V_107 [ 1 ] ,
( V_4 -> V_112 - 1 ) * sizeof( T_2 ) ) ;
* V_69 -= V_4 -> V_112 ;
V_4 -> V_112 = 0 ;
}
if ( V_4 -> V_132 == V_155 ) {
if ( V_4 -> V_106 &&
V_98 ( V_4 , & V_4 -> V_86 ) > 0 ) {
if ( F_57 ( V_4 ) )
F_10 ( & V_4 -> V_35 -> V_4 , L_67 ) ;
else
if ( F_50 ( V_4 , & V_4 -> V_86 ) )
return - V_53 ;
V_4 -> V_106 = false ;
if ( V_4 -> V_185 ) {
* V_69 -= ( sizeof( struct V_42 ) +
V_186 + 3 ) / 4 ;
V_4 -> V_105 = 2 ;
} else {
* V_69 -= ( sizeof( struct V_42 ) +
V_187 + 3 ) / 4 ;
V_4 -> V_105 = 0 ;
}
}
}
if ( V_4 -> V_182 )
return ~ V_53 ;
F_10 ( & V_4 -> V_35 -> V_4 , L_68 ) ;
F_18 (pos, next,
&dev->ctrl_wr_list.mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * ) V_178 -> V_54 ;
if ( ! V_11 ) {
F_19 ( & V_178 -> V_32 ) ;
return - V_53 ;
}
switch ( V_178 -> V_14 ) {
case V_188 :
V_171 = F_22 ( V_4 , V_69 , V_178 , V_11 , V_76 ) ;
if ( V_171 )
return V_171 ;
break;
case V_19 :
V_171 = F_46 ( V_4 , V_69 , V_178 , V_11 , V_76 ) ;
if ( V_171 )
return V_171 ;
break;
case V_88 :
if ( F_58 ( V_4 , V_11 ) )
continue;
V_171 = F_47 ( V_4 , V_69 , V_178 , V_11 , V_76 ) ;
if ( V_171 )
return V_171 ;
break;
default:
F_32 () ;
}
}
F_10 ( & V_4 -> V_35 -> V_4 , L_69 ) ;
F_18 (pos, next,
&dev->write_list.mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * ) V_178 -> V_54 ;
if ( V_11 == NULL )
continue;
if ( V_11 != & V_4 -> V_38 ) {
if ( ! V_98 ( V_4 , V_11 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 ,
L_70
L_71
L_72 ,
V_11 -> V_58 ) ;
continue;
}
V_171 = F_49 ( V_4 , V_69 ,
V_178 ,
V_11 , V_76 ) ;
if ( V_171 )
return V_171 ;
} else if ( V_11 == & V_4 -> V_38 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_73 ) ;
if ( ! V_98 ( V_4 , V_11 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 ,
L_70
L_74
L_75 ,
V_11 -> V_58 ) ;
continue;
}
V_171 = F_51 ( V_4 ,
V_69 ,
V_178 ,
V_11 ,
V_76 ) ;
if ( V_171 )
return V_171 ;
}
}
return 0 ;
}
void F_59 ( struct V_189 * V_190 )
{
unsigned long V_191 ;
struct V_10 * V_100 = NULL ;
struct V_10 * V_101 = NULL ;
struct V_192 * V_193 = NULL ;
struct V_12 * V_13 = NULL ;
struct V_12 * V_62 = NULL ;
struct V_3 * V_4 = F_60 ( V_190 ,
struct V_3 , V_194 . V_190 ) ;
F_61 ( & V_4 -> V_195 ) ;
if ( V_4 -> V_132 != V_155 ) {
if ( V_4 -> V_132 == V_133 ) {
if ( V_4 -> V_136 ) {
if ( -- V_4 -> V_136 == 0 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_76 ,
V_4 -> V_134 ) ;
F_38 ( V_4 , 1 ) ;
}
}
}
goto V_196;
}
F_18 (cl_pos, cl_next, &dev->file_list, link) {
if ( V_100 -> V_80 ) {
if ( -- V_100 -> V_80 == 0 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_77 ) ;
F_38 ( V_4 , 1 ) ;
goto V_196;
}
}
}
if ( V_4 -> V_27 ) {
if ( -- V_4 -> V_27 == 0 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_78 ) ;
F_38 ( V_4 , 1 ) ;
V_4 -> V_72 = 0 ;
V_4 -> V_31 = 0 ;
V_4 -> V_24 = false ;
V_4 -> V_57 = true ;
V_4 -> V_25 = V_87 ;
V_4 -> V_36 = 0 ;
if ( V_4 -> V_52 )
F_5 ( V_4 -> V_52 ) ;
V_4 -> V_197 = NULL ;
V_4 -> V_52 = NULL ;
F_11 ( V_4 ) ;
}
}
if ( V_4 -> V_36 ) {
V_191 = V_4 -> V_36 +
F_62 ( V_198 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_2 ,
V_4 -> V_36 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_79 , V_191 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_80 , V_37 ) ;
if ( F_63 ( V_37 , V_191 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_81 ) ;
V_193 = & V_4 -> V_33 .
V_34 . V_32 ;
F_18 (cb_pos, cb_next, amthi_complete_list, cb_list) {
V_100 = V_13 -> V_199 -> V_200 ;
if ( V_100 == & V_4 -> V_38 )
F_19 ( & V_13 -> V_32 ) ;
}
if ( V_4 -> V_52 )
F_5 ( V_4 -> V_52 ) ;
V_4 -> V_197 -> V_200 = NULL ;
V_4 -> V_197 = NULL ;
V_4 -> V_52 = NULL ;
V_4 -> V_36 = 0 ;
F_11 ( V_4 ) ;
}
}
V_196:
F_64 ( & V_4 -> V_194 , 2 * V_201 ) ;
F_65 ( & V_4 -> V_195 ) ;
}
T_1 F_66 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_40 V_41 ;
struct V_12 * V_13 = NULL , * V_62 = NULL ;
struct V_10 * V_11 ;
T_3 V_69 ;
int V_202 ;
bool V_203 ;
F_10 ( & V_4 -> V_35 -> V_4 , L_82 ) ;
F_61 ( & V_4 -> V_195 ) ;
F_67 ( & V_41 ) ;
V_4 -> V_168 = F_2 ( V_4 ) ;
if ( F_68 ( V_4 -> V_35 ) )
F_3 ( V_4 , V_8 , V_4 -> V_168 ) ;
V_4 -> V_204 = F_69 ( V_4 ) ;
if ( ( V_4 -> V_204 & V_205 ) == 0 &&
V_4 -> V_132 != V_206 &&
V_4 -> V_132 != V_207 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_83 ) ;
F_38 ( V_4 , 1 ) ;
F_65 ( & V_4 -> V_195 ) ;
return V_208 ;
}
if ( ( V_4 -> V_168 & V_209 ) == 0 ) {
if ( ( V_4 -> V_204 & V_205 ) == V_205 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_84 ) ;
V_4 -> V_168 |= ( V_210 | V_211 | V_209 ) ;
F_70 ( V_4 ) ;
V_4 -> V_132 = V_133 ;
F_10 ( & V_4 -> V_35 -> V_4 , L_85 ) ;
F_71 ( V_4 ) ;
F_65 ( & V_4 -> V_195 ) ;
return V_208 ;
} else {
F_10 ( & V_4 -> V_35 -> V_4 , L_83 ) ;
F_65 ( & V_4 -> V_195 ) ;
return V_208 ;
}
}
V_69 = F_54 ( V_4 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_86 ,
V_69 , V_4 -> V_112 ) ;
while ( V_69 > 0 && ! V_4 -> V_112 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_86 ,
V_69 , V_4 -> V_112 ) ;
F_10 ( & V_4 -> V_35 -> V_4 , L_87 ) ;
V_202 = F_52 ( & V_41 , V_4 , & V_69 ) ;
if ( V_202 )
goto V_173;
}
V_202 = F_55 ( & V_41 , V_4 , & V_69 ) ;
V_173:
F_10 ( & V_4 -> V_35 -> V_4 , L_88 ) ;
V_4 -> V_168 = F_2 ( V_4 ) ;
V_4 -> V_74 = V_74 ( V_4 ) ;
V_203 = false ;
if ( V_4 -> V_137 && F_6 ( & V_4 -> V_144 ) ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_89 ) ;
V_203 = true ;
}
F_65 ( & V_4 -> V_195 ) ;
if ( V_203 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_90 ) ;
F_7 ( & V_4 -> V_144 ) ;
V_203 = false ;
}
if ( F_17 ( & V_41 . V_34 . V_32 ) )
return V_208 ;
F_18 (cb_pos, cb_next,
&complete_list.mei_cb.cb_list, cb_list) {
V_11 = (struct V_10 * ) V_13 -> V_54 ;
F_19 ( & V_13 -> V_32 ) ;
if ( V_11 ) {
if ( V_11 != & V_4 -> V_38 ) {
F_10 ( & V_4 -> V_35 -> V_4 , L_91 ) ;
F_4 ( V_11 , V_13 ) ;
V_13 = NULL ;
} else if ( V_11 == & V_4 -> V_38 ) {
F_8 ( V_4 , V_13 ) ;
}
}
}
return V_208 ;
}
