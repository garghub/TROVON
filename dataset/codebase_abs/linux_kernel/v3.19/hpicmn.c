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
T_1 V_43 = V_42 -> V_43 ;
if ( V_43 >= V_31 -> V_36 ) {
F_2 ( V_44 ,
L_8 ,
V_31 -> V_45 , V_43 ) ;
return 0 ;
}
if ( ! V_42 -> V_46 ) {
if ( ! V_32 ) {
F_2 ( V_44 ,
L_9 ,
V_31 -> V_45 ) ;
return 0 ;
}
F_2 ( ERROR ,
L_10 ,
V_31 -> V_45 , V_32 ) ;
break;
}
if ( V_42 -> V_47 ) {
V_31 -> V_48 [ V_43 ] = V_42 ;
V_33 ++ ;
} else {
V_31 -> V_48 [ V_43 ] = NULL ;
}
V_39 += V_42 -> V_46 * 4 ;
F_2 ( V_23 ,
L_11 ,
V_33 , V_31 -> V_48 [ V_42 -> V_43 ] ,
V_42 -> V_43 , V_42 -> V_47 ,
V_42 -> V_46 ) ;
if ( V_39 >= V_31 -> V_37 )
break;
if ( V_42 -> V_43 == V_31 -> V_36 - 1 )
break;
}
if ( V_39 != V_31 -> V_37 )
F_2 ( V_19 ,
L_12 ,
V_31 -> V_45 , V_39 ,
V_31 -> V_37 ) ;
else
F_2 ( V_40 ,
L_13 ,
V_31 -> V_45 , V_39 ) ;
V_31 -> V_34 = ( T_1 ) V_33 ;
}
return V_31 -> V_34 ;
}
static short F_12 ( T_1 V_43 ,
struct V_30 * V_35 , struct V_41 * * V_49 )
{
if ( ! F_11 ( V_35 ) ) {
F_2 ( V_23 ,
L_14 ,
V_43 ) ;
return 0 ;
}
* V_49 = V_35 -> V_48 [ V_43 ] ;
if ( ! * V_49 ) {
F_2 ( V_23 , L_15 ,
V_43 ) ;
return 0 ;
} else {
F_2 ( V_23 , L_16 ,
( * V_49 ) -> V_47 ) ;
}
return 1 ;
}
short F_13 ( struct V_50 * V_31 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_51 ;
short V_52 = 1 ;
V_51 =
sizeof( struct V_53 ) +
sizeof( struct V_54 ) ;
switch ( V_31 -> V_26 . V_32 . V_47 ) {
case V_55 :
if ( V_2 -> V_26 . V_56 . V_57 == V_58 ) {
V_4 -> V_26 . V_56 . V_59 [ 0 ] = V_31 -> V_26 . V_60 . V_61 [ 0 ] ;
V_4 -> V_26 . V_56 . V_59 [ 1 ] = V_31 -> V_26 . V_60 . V_61 [ 1 ] ;
} else if ( V_2 -> V_26 . V_56 . V_57 == V_62 ) {
if ( V_31 -> V_26 . V_60 . V_63 [ 0 ] ==
V_64 ) {
V_4 -> error =
V_65 ;
V_4 -> V_26 . V_56 . V_59 [ 0 ] = V_66 ;
V_4 -> V_26 . V_56 . V_59 [ 1 ] = V_66 ;
} else {
V_4 -> V_26 . V_56 . V_59 [ 0 ] =
V_31 -> V_26 . V_60 . V_63 [ 0 ] ;
V_4 -> V_26 . V_56 . V_59 [ 1 ] =
V_31 -> V_26 . V_60 . V_63 [ 1 ] ;
}
} else
V_52 = 0 ;
break;
case V_67 :
if ( V_2 -> V_26 . V_56 . V_57 == V_68 ) {
V_4 -> V_26 . V_56 . V_59 [ 0 ] = V_31 -> V_26 . V_69 . V_70 [ 0 ] ;
V_4 -> V_26 . V_56 . V_59 [ 1 ] = V_31 -> V_26 . V_69 . V_70 [ 1 ] ;
} else if ( V_2 -> V_26 . V_56 . V_57 == V_71 ) {
if ( V_31 -> V_26 . V_69 . V_72 & V_73 ) {
if ( V_31 -> V_26 . V_69 . V_72 & V_74 )
V_4 -> V_26 . V_56 . V_75 =
V_76 ;
else
V_4 -> V_26 . V_56 . V_75 = 0 ;
} else {
V_4 -> error =
V_65 ;
V_4 -> V_26 . V_56 . V_75 = 0 ;
}
} else {
V_52 = 0 ;
}
break;
case V_77 :
if ( V_2 -> V_26 . V_56 . V_57 == V_78 ) {
V_4 -> V_26 . V_56 . V_75 = V_31 -> V_26 . V_79 . V_80 ;
V_4 -> V_26 . V_56 . V_81 = V_31 -> V_26 . V_79 . V_82 ;
} else {
V_52 = 0 ;
}
break;
case V_83 :
if ( V_2 -> V_26 . V_56 . V_57 == V_84 )
V_4 -> V_26 . V_56 . V_75 = V_31 -> V_26 . V_85 . V_85 ;
else
V_52 = 0 ;
break;
case V_86 :
if ( V_2 -> V_26 . V_56 . V_57 == V_87 ) {
V_4 -> V_26 . V_56 . V_59 [ 0 ] = V_31 -> V_26 . V_88 . V_70 [ 0 ] ;
V_4 -> V_26 . V_56 . V_59 [ 1 ] = V_31 -> V_26 . V_88 . V_70 [ 1 ] ;
} else
V_52 = 0 ;
break;
case V_89 :
if ( V_2 -> V_26 . V_56 . V_57 == V_90 )
V_4 -> V_26 . V_56 . V_75 = V_31 -> V_26 . V_91 . V_92 ;
else if ( V_2 -> V_26 . V_56 . V_57 == V_93 )
V_4 -> V_26 . V_56 . V_75 = V_31 -> V_26 . V_91 . V_94 ;
else if ( V_2 -> V_26 . V_56 . V_57 == V_95 )
if ( V_31 -> V_26 . V_91 . V_96 ==
V_64 ) {
V_4 -> V_26 . V_97 . V_91 . V_98 = 0 ;
V_4 -> error =
V_65 ;
} else
V_4 -> V_26 . V_97 . V_91 . V_98 =
V_31 -> V_26 . V_91 . V_96 ;
else
V_52 = 0 ;
break;
case V_99 :
if ( V_2 -> V_26 . V_56 . V_57 == V_100 )
V_4 -> V_26 . V_56 . V_75 = V_31 -> V_26 . V_101 . V_102 ;
else if ( V_2 -> V_26 . V_56 . V_57 == V_103 )
V_4 -> V_26 . V_56 . V_75 = V_31 -> V_26 . V_101 . V_104 ;
else
V_52 = 0 ;
break;
case V_105 :
if ( V_2 -> V_26 . V_56 . V_57 == V_106 )
V_4 -> V_26 . V_56 . V_75 = V_31 -> V_26 . V_107 . V_104 ;
else
V_52 = 0 ;
break;
case V_108 :
if ( V_2 -> V_26 . V_56 . V_57 == V_109 )
V_4 -> V_26 . V_56 . V_75 = V_31 -> V_26 . V_110 . V_111 ;
else
V_52 = 0 ;
break;
case V_112 :
if ( V_2 -> V_26 . V_56 . V_57 == V_113 ) {
V_4 -> V_26 . V_56 . V_75 = V_31 -> V_26 . V_114 . V_111 ;
} else
V_52 = 0 ;
break;
case V_115 :
if ( V_2 -> V_26 . V_56 . V_57 == V_116 )
V_4 -> V_26 . V_56 . V_75 = V_31 -> V_26 . V_117 . V_118 ;
else
V_52 = 0 ;
break;
case V_119 :
if ( V_2 -> V_26 . V_56 . V_57 == V_120 )
V_4 -> V_26 . V_56 . V_75 = V_31 -> V_26 . V_121 . V_122 ;
else if ( V_2 -> V_26 . V_56 . V_57 == V_123 ) {
if ( V_31 -> V_26 . V_121 . V_124 ==
V_125 ) {
V_4 -> V_26 . V_56 . V_75 = 0 ;
V_4 -> error =
V_65 ;
} else
V_4 -> V_26 . V_56 . V_75 = V_31 -> V_26 . V_121 . V_124 ;
} else if ( V_2 -> V_26 . V_56 . V_57 == V_126 )
V_4 -> V_26 . V_56 . V_75 = V_31 -> V_26 . V_121 . V_127 ;
else
V_52 = 0 ;
break;
case V_128 : {
struct V_129 * V_130 ;
V_130 = (struct V_129 * ) V_31 ;
if ( ! ( V_130 -> V_131 & ( 1 <<
F_14 ( V_2 -> V_26 . V_56 .
V_57 ) ) ) ) {
V_4 -> error =
V_65 ;
break;
}
if ( V_2 -> V_26 . V_56 . V_57 == V_132 )
V_4 -> V_26 . V_56 . V_75 = V_130 -> V_49 ;
else if ( V_2 -> V_26 . V_56 . V_57 == V_133 )
V_4 -> V_26 . V_56 . V_75 = V_130 -> V_134 ;
else {
unsigned int V_13 =
F_14 ( V_2 -> V_26 . V_56 .
V_57 ) - 1 ;
unsigned int V_135 = V_2 -> V_26 . V_56 . V_75 ;
unsigned int V_136 , V_137 ;
char * V_138 ;
unsigned int V_139 ;
if ( V_13 > F_15 ( V_140 ) - 1 ) {
V_4 -> error =
V_65 ;
break;
}
V_138 =
( ( char * ) V_130 ) +
V_140 [ V_13 ] . V_135 ;
V_137 = V_140 [ V_13 ] . V_137 ;
V_138 [ V_137 - 1 ] = 0 ;
V_136 = strlen ( V_138 ) + 1 ;
if ( V_135 > V_136 ) {
V_4 -> error =
V_141 ;
break;
}
V_139 = V_136 - V_135 ;
if ( V_139 > sizeof( V_4 -> V_26 . V_97 . V_142 . V_143 ) )
V_139 = sizeof( V_4 -> V_26 . V_97 . V_142 .
V_143 ) ;
memcpy ( V_4 -> V_26 . V_97 . V_142 . V_143 ,
& V_138 [ V_135 ] , V_139 ) ;
V_4 -> V_26 . V_97 . V_142 . V_144 =
V_136 - V_135 - V_139 ;
}
}
break;
default:
V_52 = 0 ;
break;
}
F_2 ( V_23 , L_17 ,
V_52 ? L_18 : L_19 , V_2 -> V_22 ,
V_31 -> V_26 . V_32 . V_43 , V_31 -> V_26 . V_32 . V_47 ,
V_2 -> V_26 . V_56 . V_57 ) ;
if ( V_52 ) {
V_4 -> V_145 = ( T_1 ) V_51 ;
V_4 -> type = V_5 ;
V_4 -> V_7 = V_2 -> V_7 ;
V_4 -> V_8 = V_2 -> V_8 ;
}
return V_52 ;
}
short F_16 ( struct V_30 * V_35 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_41 * V_49 ;
if ( ! F_12 ( V_2 -> V_25 , V_35 , & V_49 ) ) {
F_2 ( V_23 ,
L_20 ,
V_2 -> V_22 ) ;
return 0 ;
}
V_4 -> error = 0 ;
V_4 -> V_146 = 0 ;
V_4 -> V_147 = 0 ;
return F_13 ( (struct V_50
* ) V_49 , V_2 , V_4 ) ;
}
void F_17 ( struct V_50
* V_31 , struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( V_31 -> V_26 . V_32 . V_47 ) {
case V_67 :
if ( V_2 -> V_26 . V_56 . V_57 == V_68 ) {
V_31 -> V_26 . V_69 . V_70 [ 0 ] = V_4 -> V_26 . V_56 . V_59 [ 0 ] ;
V_31 -> V_26 . V_69 . V_70 [ 1 ] = V_4 -> V_26 . V_56 . V_59 [ 1 ] ;
} else if ( V_2 -> V_26 . V_56 . V_57 == V_71 ) {
if ( V_2 -> V_26 . V_56 . V_75 )
V_31 -> V_26 . V_69 . V_72 |= V_74 ;
else
V_31 -> V_26 . V_69 . V_72 &= ~ V_74 ;
}
break;
case V_77 :
if ( V_2 -> V_26 . V_56 . V_57 == V_78 ) {
V_31 -> V_26 . V_79 . V_80 = ( T_1 ) V_2 -> V_26 . V_56 . V_75 ;
V_31 -> V_26 . V_79 . V_82 = ( T_1 ) V_2 -> V_26 . V_56 . V_81 ;
}
break;
case V_83 :
if ( V_2 -> V_26 . V_56 . V_57 == V_84 )
V_31 -> V_26 . V_85 . V_85 = ( T_1 ) V_2 -> V_26 . V_56 . V_75 ;
break;
case V_86 :
if ( V_2 -> V_26 . V_56 . V_57 == V_87 ) {
V_31 -> V_26 . V_69 . V_70 [ 0 ] = V_4 -> V_26 . V_56 . V_59 [ 0 ] ;
V_31 -> V_26 . V_69 . V_70 [ 1 ] = V_4 -> V_26 . V_56 . V_59 [ 1 ] ;
}
break;
case V_115 :
if ( V_2 -> V_26 . V_56 . V_57 == V_116 )
V_31 -> V_26 . V_117 . V_118 = ( T_1 ) V_2 -> V_26 . V_56 . V_75 ;
break;
case V_105 :
if ( V_2 -> V_26 . V_56 . V_57 == V_106 )
V_31 -> V_26 . V_107 . V_104 = V_2 -> V_26 . V_56 . V_75 ;
break;
case V_99 :
if ( V_2 -> V_26 . V_56 . V_57 == V_103 )
V_31 -> V_26 . V_101 . V_104 = V_2 -> V_26 . V_56 . V_75 ;
break;
case V_119 :
if ( V_2 -> V_26 . V_56 . V_57 == V_120 )
V_31 -> V_26 . V_121 . V_122 = ( T_1 ) V_2 -> V_26 . V_56 . V_75 ;
else if ( V_2 -> V_26 . V_56 . V_57 == V_123 )
V_31 -> V_26 . V_121 . V_124 = ( T_1 ) V_2 -> V_26 . V_56 . V_75 ;
else if ( V_2 -> V_26 . V_56 . V_57 == V_126 )
V_31 -> V_26 . V_121 . V_127 = V_2 -> V_26 . V_56 . V_75 ;
break;
default:
break;
}
}
void F_18 ( struct V_30 * V_35 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_50 * V_31 ;
struct V_41 * V_49 ;
if ( V_4 -> error )
return;
if ( ! F_12 ( V_2 -> V_25 , V_35 , & V_49 ) ) {
F_2 ( V_23 ,
L_20 ,
V_2 -> V_22 ) ;
return;
}
V_31 = (struct V_50 * ) V_49 ;
F_17 ( V_31 , V_2 , V_4 ) ;
}
struct V_30 * F_19 ( const T_3 V_36 ,
const T_3 V_148 , T_4 * V_149 )
{
struct V_30 * V_35 =
F_20 ( sizeof( * V_35 ) , V_150 ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_48 =
F_21 ( V_36 , sizeof( * V_35 -> V_48 ) , V_150 ) ;
if ( ! V_35 -> V_48 ) {
F_22 ( V_35 ) ;
return NULL ;
}
V_35 -> V_37 = V_148 ;
V_35 -> V_36 = V_36 ;
V_35 -> V_35 = V_149 ;
V_35 -> V_34 = 0 ;
return V_35 ;
}
void F_23 ( struct V_30 * V_35 )
{
if ( V_35 ) {
F_22 ( V_35 -> V_48 ) ;
F_22 ( V_35 ) ;
}
}
static void F_24 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_25 ( V_4 , V_151 , V_2 -> V_8 , 0 ) ;
switch ( V_2 -> V_8 ) {
case V_152 :
case V_153 :
case V_154 :
break;
case V_155 :
F_9 () ;
F_26 ( & V_12 ) ;
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
void F_27 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( V_2 -> type ) {
case V_161 :
switch ( V_2 -> V_7 ) {
case V_151 :
F_24 ( V_2 , V_4 ) ;
break;
}
break;
default:
V_4 -> error = V_162 ;
break;
}
}
