T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> type != V_5 ) {
F_2 ( ERROR , L_1 , V_4 -> type ) ;
return V_6 ;
}
if ( V_4 -> V_7 != V_2 -> V_7 ) {
F_2 ( ERROR , L_2 ,
V_4 -> V_7 ) ;
return V_6 ;
}
if ( V_4 -> V_8 != V_2 -> V_8 ) {
F_2 ( ERROR , L_3 ,
V_4 -> V_8 ) ;
return V_6 ;
}
return 0 ;
}
T_1 F_3 ( struct V_9 * V_10 )
{
T_1 V_11 = 0 ;
F_4 ( & V_12 ) ;
if ( V_10 -> V_13 >= V_14 ) {
V_11 = V_15 ;
goto V_16;
}
if ( V_12 . V_17 [ V_10 -> V_13 ] . type ) {
int V_18 ;
for ( V_18 = V_14 - 1 ; V_18 >= 0 ; V_18 -- ) {
if ( ! V_12 . V_17 [ V_18 ] . type ) {
F_2 ( V_19 ,
L_4 ,
V_10 -> type , V_10 -> V_13 , V_18 ) ;
V_10 -> V_13 = V_18 ;
break;
}
}
if ( V_18 < 0 ) {
V_11 = V_20 ;
goto V_16;
}
}
V_12 . V_17 [ V_10 -> V_13 ] = * V_10 ;
F_5 ( & V_12 . V_17 [ V_10 -> V_13 ] ) ;
V_12 . V_21 ++ ;
V_16:
F_6 ( & V_12 ) ;
return V_11 ;
}
void F_7 ( struct V_9 * V_10 )
{
if ( ! V_10 -> type ) {
F_2 ( ERROR , L_5 ) ;
return;
}
F_4 ( & V_12 ) ;
if ( V_12 . V_17 [ V_10 -> V_13 ] . type )
V_12 . V_21 -- ;
memset ( & V_12 . V_17 [ V_10 -> V_13 ] , 0 , sizeof( V_12 . V_17 [ 0 ] ) ) ;
F_6 ( & V_12 ) ;
}
struct V_9 * F_8 ( T_1 V_22 )
{
struct V_9 * V_10 = NULL ;
if ( V_22 >= V_14 ) {
F_2 ( V_23 , L_6 ,
V_22 ) ;
return NULL ;
}
V_10 = & V_12 . V_17 [ V_22 ] ;
if ( V_10 -> type != 0 ) {
return V_10 ;
} else {
return NULL ;
}
}
static void F_9 ( void )
{
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_24 = V_2 -> V_25 ;
T_1 V_13 = 0 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
if ( V_12 . V_17 [ V_13 ] . type ) {
if ( ! V_24 )
break;
V_24 -- ;
}
}
if ( V_13 < V_14 ) {
V_4 -> V_26 . V_27 . V_22 = V_12 . V_17 [ V_13 ] . V_13 ;
V_4 -> V_26 . V_27 . V_28 = V_12 . V_17 [ V_13 ] . type ;
} else {
V_4 -> V_26 . V_27 . V_22 = 0 ;
V_4 -> V_26 . V_27 . V_28 = 0 ;
V_4 -> error = V_29 ;
}
}
static unsigned int F_11 ( struct V_30 * V_31 )
{
unsigned int V_32 ;
int V_33 = 0 ;
if ( ! V_31 )
return 0 ;
if ( V_31 -> V_34 )
return V_31 -> V_34 ;
if ( ! V_31 -> V_35 )
return 0 ;
if ( V_31 -> V_36 && V_31 -> V_37 ) {
char * V_38 ;
unsigned int V_39 = 0 ;
V_38 = ( char * ) V_31 -> V_35 ;
F_2 ( V_40 , L_7 ,
V_31 -> V_36 ) ;
for ( V_32 = 0 ; V_32 < V_31 -> V_36 ; V_32 ++ ) {
struct V_41 * V_42 =
(struct V_41 * )
& V_38 [ V_39 ] ;
if ( ! V_42 -> V_43 ) {
if ( ! V_32 ) {
F_2 ( V_44 ,
L_8 ,
V_31 -> V_45 ) ;
return 0 ;
}
F_2 ( ERROR ,
L_9 ,
V_31 -> V_45 , V_32 ) ;
break;
}
if ( V_42 -> V_46 ) {
V_31 -> V_47 [ V_42 -> V_48 ] = V_42 ;
V_33 ++ ;
} else {
V_31 -> V_47 [ V_42 -> V_48 ] = NULL ;
}
V_39 += V_42 -> V_43 * 4 ;
F_2 ( V_23 ,
L_10 ,
V_33 , V_31 -> V_47 [ V_42 -> V_48 ] ,
V_42 -> V_48 , V_42 -> V_46 ,
V_42 -> V_43 ) ;
if ( V_39 >= V_31 -> V_37 )
break;
if ( V_42 -> V_48 == V_31 -> V_36 - 1 )
break;
}
if ( V_39 != V_31 -> V_37 )
F_2 ( V_19 ,
L_11 ,
V_31 -> V_45 , V_39 ,
V_31 -> V_37 ) ;
else
F_2 ( V_40 ,
L_12 ,
V_31 -> V_45 , V_39 ) ;
V_31 -> V_34 = ( T_1 ) V_33 ;
}
return V_31 -> V_34 ;
}
static short F_12 ( T_1 V_48 ,
struct V_30 * V_35 , struct V_41 * * V_49 )
{
if ( ! F_11 ( V_35 ) ) {
F_2 ( V_23 ,
L_13 ,
V_48 ) ;
return 0 ;
}
* V_49 = V_35 -> V_47 [ V_48 ] ;
if ( ! * V_49 ) {
F_2 ( V_23 , L_14 ,
V_48 ) ;
return 0 ;
} else {
F_2 ( V_23 , L_15 ,
( * V_49 ) -> V_46 ) ;
}
return 1 ;
}
short F_13 ( struct V_30 * V_35 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
short V_50 = 1 ;
struct V_41 * V_49 ;
struct V_51 * V_31 ;
T_2 V_52 ;
if ( ! F_12 ( V_2 -> V_25 , V_35 , & V_49 ) ) {
F_2 ( V_23 ,
L_16 ,
V_2 -> V_22 ) ;
return 0 ;
}
V_4 -> error = 0 ;
V_4 -> V_53 = 0 ;
V_4 -> V_54 = 0 ;
V_52 =
sizeof( struct V_55 ) +
sizeof( struct V_56 ) ;
V_31 = (struct V_51 * ) V_49 ;
switch ( V_49 -> V_46 ) {
case V_57 :
if ( V_2 -> V_26 . V_58 . V_59 == V_60 ) {
V_4 -> V_26 . V_58 . V_61 [ 0 ] = V_31 -> V_26 . V_62 . V_63 [ 0 ] ;
V_4 -> V_26 . V_58 . V_61 [ 1 ] = V_31 -> V_26 . V_62 . V_63 [ 1 ] ;
} else if ( V_2 -> V_26 . V_58 . V_59 == V_64 ) {
if ( V_31 -> V_26 . V_62 . V_65 [ 0 ] ==
V_66 ) {
V_4 -> error =
V_67 ;
V_4 -> V_26 . V_58 . V_61 [ 0 ] = V_68 ;
V_4 -> V_26 . V_58 . V_61 [ 1 ] = V_68 ;
} else {
V_4 -> V_26 . V_58 . V_61 [ 0 ] =
V_31 -> V_26 . V_62 . V_65 [ 0 ] ;
V_4 -> V_26 . V_58 . V_61 [ 1 ] =
V_31 -> V_26 . V_62 . V_65 [ 1 ] ;
}
} else
V_50 = 0 ;
break;
case V_69 :
if ( V_2 -> V_26 . V_58 . V_59 == V_70 ) {
V_4 -> V_26 . V_58 . V_61 [ 0 ] = V_31 -> V_26 . V_71 . V_72 [ 0 ] ;
V_4 -> V_26 . V_58 . V_61 [ 1 ] = V_31 -> V_26 . V_71 . V_72 [ 1 ] ;
} else if ( V_2 -> V_26 . V_58 . V_59 == V_73 ) {
if ( V_31 -> V_26 . V_71 . V_74 & V_75 ) {
if ( V_31 -> V_26 . V_71 . V_74 & V_76 )
V_4 -> V_26 . V_58 . V_77 =
V_78 ;
else
V_4 -> V_26 . V_58 . V_77 = 0 ;
} else {
V_4 -> error =
V_67 ;
V_4 -> V_26 . V_58 . V_77 = 0 ;
}
} else {
V_50 = 0 ;
}
break;
case V_79 :
if ( V_2 -> V_26 . V_58 . V_59 == V_80 ) {
V_4 -> V_26 . V_58 . V_77 = V_31 -> V_26 . V_81 . V_82 ;
V_4 -> V_26 . V_58 . V_83 = V_31 -> V_26 . V_81 . V_84 ;
} else {
V_50 = 0 ;
}
break;
case V_85 :
if ( V_2 -> V_26 . V_58 . V_59 == V_86 )
V_4 -> V_26 . V_58 . V_77 = V_31 -> V_26 . V_87 . V_87 ;
else
V_50 = 0 ;
break;
case V_88 :
if ( V_2 -> V_26 . V_58 . V_59 == V_89 ) {
V_4 -> V_26 . V_58 . V_61 [ 0 ] = V_31 -> V_26 . V_90 . V_72 [ 0 ] ;
V_4 -> V_26 . V_58 . V_61 [ 1 ] = V_31 -> V_26 . V_90 . V_72 [ 1 ] ;
} else
V_50 = 0 ;
break;
case V_91 :
if ( V_2 -> V_26 . V_58 . V_59 == V_92 )
V_4 -> V_26 . V_58 . V_77 = V_31 -> V_26 . V_93 . V_94 ;
else if ( V_2 -> V_26 . V_58 . V_59 == V_95 )
V_4 -> V_26 . V_58 . V_77 = V_31 -> V_26 . V_93 . V_96 ;
else if ( V_2 -> V_26 . V_58 . V_59 == V_97 )
if ( V_31 -> V_26 . V_93 . V_98 ==
V_66 ) {
V_4 -> V_26 . V_99 . V_93 . V_100 = 0 ;
V_4 -> error =
V_67 ;
} else
V_4 -> V_26 . V_99 . V_93 . V_100 =
V_31 -> V_26 . V_93 . V_98 ;
else
V_50 = 0 ;
break;
case V_101 :
if ( V_2 -> V_26 . V_58 . V_59 == V_102 )
V_4 -> V_26 . V_58 . V_77 = V_31 -> V_26 . V_103 . V_104 ;
else if ( V_2 -> V_26 . V_58 . V_59 == V_105 )
V_4 -> V_26 . V_58 . V_77 = V_31 -> V_26 . V_103 . V_106 ;
else
V_50 = 0 ;
break;
case V_107 :
if ( V_2 -> V_26 . V_58 . V_59 == V_108 )
V_4 -> V_26 . V_58 . V_77 = V_31 -> V_26 . V_109 . V_106 ;
else
V_50 = 0 ;
break;
case V_110 :
if ( V_2 -> V_26 . V_58 . V_59 == V_111 )
V_4 -> V_26 . V_58 . V_77 = V_31 -> V_26 . V_112 . V_113 ;
else
V_50 = 0 ;
break;
case V_114 :
if ( V_2 -> V_26 . V_58 . V_59 == V_115 ) {
V_4 -> V_26 . V_58 . V_77 = V_31 -> V_26 . V_116 . V_113 ;
} else
V_50 = 0 ;
break;
case V_117 :
if ( V_2 -> V_26 . V_58 . V_59 == V_118 )
V_4 -> V_26 . V_58 . V_77 = V_31 -> V_26 . V_119 . V_120 ;
else
V_50 = 0 ;
break;
case V_121 :
if ( V_2 -> V_26 . V_58 . V_59 == V_122 )
V_4 -> V_26 . V_58 . V_77 = V_31 -> V_26 . V_123 . V_124 ;
else if ( V_2 -> V_26 . V_58 . V_59 == V_125 ) {
if ( V_31 -> V_26 . V_123 . V_126 ==
V_127 ) {
V_4 -> V_26 . V_58 . V_77 = 0 ;
V_4 -> error =
V_67 ;
} else
V_4 -> V_26 . V_58 . V_77 = V_31 -> V_26 . V_123 . V_126 ;
} else if ( V_2 -> V_26 . V_58 . V_59 == V_128 )
V_4 -> V_26 . V_58 . V_77 = V_31 -> V_26 . V_123 . V_129 ;
else
V_50 = 0 ;
break;
case V_130 : {
struct V_131 * V_132 ;
V_132 = (struct V_131 * ) V_49 ;
if ( ! ( V_132 -> V_133 & ( 1 <<
F_14 ( V_2 -> V_26 . V_58 .
V_59 ) ) ) ) {
V_4 -> error =
V_67 ;
break;
}
if ( V_2 -> V_26 . V_58 . V_59 == V_134 )
V_4 -> V_26 . V_58 . V_77 = V_132 -> V_49 ;
else if ( V_2 -> V_26 . V_58 . V_59 == V_135 )
V_4 -> V_26 . V_58 . V_77 = V_132 -> V_136 ;
else {
unsigned int V_13 =
F_14 ( V_2 -> V_26 . V_58 .
V_59 ) - 1 ;
unsigned int V_137 = V_2 -> V_26 . V_58 . V_77 ;
unsigned int V_138 , V_139 ;
char * V_140 ;
unsigned int V_141 ;
if ( V_13 > F_15 ( V_142 ) - 1 ) {
V_4 -> error =
V_67 ;
break;
}
V_140 =
( ( char * ) V_132 ) +
V_142 [ V_13 ] . V_137 ;
V_139 = V_142 [ V_13 ] . V_139 ;
V_140 [ V_139 - 1 ] = 0 ;
V_138 = strlen ( V_140 ) + 1 ;
if ( V_137 > V_138 ) {
V_4 -> error =
V_143 ;
break;
}
V_141 = V_138 - V_137 ;
if ( V_141 > sizeof( V_4 -> V_26 . V_99 . V_144 . V_145 ) )
V_141 = sizeof( V_4 -> V_26 . V_99 . V_144 .
V_145 ) ;
memcpy ( V_4 -> V_26 . V_99 . V_144 . V_145 ,
& V_140 [ V_137 ] , V_141 ) ;
V_4 -> V_26 . V_99 . V_144 . V_146 =
V_138 - V_137 - V_141 ;
}
}
break;
default:
V_50 = 0 ;
break;
}
F_2 ( V_23 , L_17 ,
V_50 ? L_18 : L_19 , V_2 -> V_22 ,
V_49 -> V_48 , V_49 -> V_46 , V_2 -> V_26 . V_58 . V_59 ) ;
if ( V_50 ) {
V_4 -> V_147 = ( T_1 ) V_52 ;
V_4 -> type = V_5 ;
V_4 -> V_7 = V_2 -> V_7 ;
V_4 -> V_8 = V_2 -> V_8 ;
}
return V_50 ;
}
void F_16 ( struct V_30 * V_35 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_51 * V_31 ;
struct V_41 * V_49 ;
if ( V_4 -> error )
return;
if ( ! F_12 ( V_2 -> V_25 , V_35 , & V_49 ) ) {
F_2 ( V_23 ,
L_16 ,
V_2 -> V_22 ) ;
return;
}
V_31 = (struct V_51 * ) V_49 ;
switch ( V_49 -> V_46 ) {
case V_69 :
if ( V_2 -> V_26 . V_58 . V_59 == V_70 ) {
V_31 -> V_26 . V_71 . V_72 [ 0 ] = V_4 -> V_26 . V_58 . V_61 [ 0 ] ;
V_31 -> V_26 . V_71 . V_72 [ 1 ] = V_4 -> V_26 . V_58 . V_61 [ 1 ] ;
} else if ( V_2 -> V_26 . V_58 . V_59 == V_73 ) {
if ( V_2 -> V_26 . V_58 . V_77 )
V_31 -> V_26 . V_71 . V_74 |= V_76 ;
else
V_31 -> V_26 . V_71 . V_74 &= ~ V_76 ;
}
break;
case V_79 :
if ( V_2 -> V_26 . V_58 . V_59 == V_80 ) {
V_31 -> V_26 . V_81 . V_82 = ( T_1 ) V_2 -> V_26 . V_58 . V_77 ;
V_31 -> V_26 . V_81 . V_84 = ( T_1 ) V_2 -> V_26 . V_58 . V_83 ;
}
break;
case V_85 :
if ( V_2 -> V_26 . V_58 . V_59 == V_86 )
V_31 -> V_26 . V_87 . V_87 = ( T_1 ) V_2 -> V_26 . V_58 . V_77 ;
break;
case V_88 :
if ( V_2 -> V_26 . V_58 . V_59 == V_89 ) {
V_31 -> V_26 . V_71 . V_72 [ 0 ] = V_4 -> V_26 . V_58 . V_61 [ 0 ] ;
V_31 -> V_26 . V_71 . V_72 [ 1 ] = V_4 -> V_26 . V_58 . V_61 [ 1 ] ;
}
break;
case V_117 :
if ( V_2 -> V_26 . V_58 . V_59 == V_118 )
V_31 -> V_26 . V_119 . V_120 = ( T_1 ) V_2 -> V_26 . V_58 . V_77 ;
break;
case V_107 :
if ( V_2 -> V_26 . V_58 . V_59 == V_108 )
V_31 -> V_26 . V_109 . V_106 = V_2 -> V_26 . V_58 . V_77 ;
break;
case V_101 :
if ( V_2 -> V_26 . V_58 . V_59 == V_105 )
V_31 -> V_26 . V_103 . V_106 = V_2 -> V_26 . V_58 . V_77 ;
break;
case V_121 :
if ( V_2 -> V_26 . V_58 . V_59 == V_122 )
V_31 -> V_26 . V_123 . V_124 = ( T_1 ) V_2 -> V_26 . V_58 . V_77 ;
else if ( V_2 -> V_26 . V_58 . V_59 == V_125 )
V_31 -> V_26 . V_123 . V_126 = ( T_1 ) V_2 -> V_26 . V_58 . V_77 ;
else if ( V_2 -> V_26 . V_58 . V_59 == V_128 )
V_31 -> V_26 . V_123 . V_129 = V_2 -> V_26 . V_58 . V_77 ;
break;
default:
break;
}
}
struct V_30 * F_17 ( const T_3 V_36 ,
const T_3 V_148 , T_4 * V_149 )
{
struct V_30 * V_35 =
F_18 ( sizeof( * V_35 ) , V_150 ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_47 = F_19 ( V_36 , sizeof( * V_35 -> V_47 ) ,
V_150 ) ;
if ( ! V_35 -> V_47 ) {
F_20 ( V_35 ) ;
return NULL ;
}
V_35 -> V_37 = V_148 ;
V_35 -> V_36 = V_36 ;
V_35 -> V_35 = V_149 ;
V_35 -> V_34 = 0 ;
return V_35 ;
}
void F_21 ( struct V_30 * V_35 )
{
if ( V_35 ) {
F_20 ( V_35 -> V_47 ) ;
F_20 ( V_35 ) ;
}
}
static void F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_23 ( V_4 , V_151 , V_2 -> V_8 , 0 ) ;
switch ( V_2 -> V_8 ) {
case V_152 :
case V_153 :
case V_154 :
break;
case V_155 :
F_9 () ;
F_24 ( & V_12 ) ;
break;
case V_156 :
F_10 ( V_2 , V_4 ) ;
break;
case V_157 :
V_4 -> V_26 . V_27 . V_158 = V_12 . V_21 ;
break;
case V_159 :
break;
default:
V_4 -> error = V_160 ;
break;
}
}
void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( V_2 -> type ) {
case V_161 :
switch ( V_2 -> V_7 ) {
case V_151 :
F_22 ( V_2 , V_4 ) ;
break;
}
break;
default:
V_4 -> error = V_162 ;
break;
}
}
