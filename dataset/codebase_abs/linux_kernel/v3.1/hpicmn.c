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
if ( V_12 . V_17 [ V_10 -> V_13 ] . V_18 ) {
int V_19 ;
for ( V_19 = V_14 - 1 ; V_19 >= 0 ; V_19 -- ) {
if ( ! V_12 . V_17 [ V_19 ] . V_18 ) {
F_2 ( V_20 ,
L_4 ,
V_10 -> V_18 , V_10 -> V_13 , V_19 ) ;
V_10 -> V_13 = V_19 ;
break;
}
}
if ( V_19 < 0 ) {
V_11 = V_21 ;
goto V_16;
}
}
V_12 . V_17 [ V_10 -> V_13 ] = * V_10 ;
F_5 ( & V_12 . V_17 [ V_10 -> V_13 ] ) ;
V_12 . V_22 ++ ;
V_16:
F_6 ( & V_12 ) ;
return V_11 ;
}
void F_7 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_18 ) {
F_2 ( ERROR , L_5 ) ;
return;
}
F_4 ( & V_12 ) ;
if ( V_12 . V_17 [ V_10 -> V_13 ] . V_18 )
V_12 . V_22 -- ;
memset ( & V_12 . V_17 [ V_10 -> V_13 ] , 0 , sizeof( V_12 . V_17 [ 0 ] ) ) ;
F_6 ( & V_12 ) ;
}
struct V_9 * F_8 ( T_1 V_23 )
{
struct V_9 * V_10 = NULL ;
if ( V_23 >= V_14 ) {
F_2 ( V_24 , L_6 ,
V_23 ) ;
return NULL ;
}
V_10 = & V_12 . V_17 [ V_23 ] ;
if ( V_10 -> V_18 != 0 ) {
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
int V_25 = V_2 -> V_26 ;
T_1 V_13 = 0 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
if ( V_12 . V_17 [ V_13 ] . V_18 ) {
if ( ! V_25 )
break;
V_25 -- ;
}
}
if ( V_13 < V_14 ) {
V_4 -> V_27 . V_28 . V_23 = V_12 . V_17 [ V_13 ] . V_13 ;
V_4 -> V_27 . V_28 . V_18 = V_12 . V_17 [ V_13 ] . V_18 ;
} else {
V_4 -> V_27 . V_28 . V_23 = 0 ;
V_4 -> V_27 . V_28 . V_18 = 0 ;
V_4 -> error = V_15 ;
}
}
static unsigned int F_11 ( struct V_29 * V_30 )
{
unsigned int V_31 ;
int V_32 = 0 ;
if ( ! V_30 )
return 0 ;
if ( V_30 -> V_33 )
return V_30 -> V_33 ;
if ( ! V_30 -> V_34 )
return 0 ;
if ( V_30 -> V_35 && V_30 -> V_36 ) {
char * V_37 ;
unsigned int V_38 = 0 ;
V_37 = ( char * ) V_30 -> V_34 ;
F_2 ( V_39 , L_7 ,
V_30 -> V_35 ) ;
for ( V_31 = 0 ; V_31 < V_30 -> V_35 ; V_31 ++ ) {
struct V_40 * V_41 =
(struct V_40 * )
& V_37 [ V_38 ] ;
if ( ! V_41 -> V_42 ) {
if ( ! V_31 ) {
F_2 ( V_43 ,
L_8 ,
V_30 -> V_44 ) ;
return 0 ;
}
F_2 ( ERROR ,
L_9 ,
V_30 -> V_44 , V_31 ) ;
break;
}
if ( V_41 -> V_45 ) {
V_30 -> V_46 [ V_41 -> V_47 ] = V_41 ;
V_32 ++ ;
} else {
V_30 -> V_46 [ V_41 -> V_47 ] = NULL ;
}
V_38 += V_41 -> V_42 * 4 ;
F_2 ( V_24 ,
L_10 ,
V_32 , V_30 -> V_46 [ V_41 -> V_47 ] ,
V_41 -> V_47 , V_41 -> V_45 ,
V_41 -> V_42 ) ;
if ( V_38 >= V_30 -> V_36 )
break;
if ( V_41 -> V_47 == V_30 -> V_35 - 1 )
break;
}
if ( V_38 != V_30 -> V_36 )
F_2 ( V_20 ,
L_11 ,
V_30 -> V_44 , V_38 ,
V_30 -> V_36 ) ;
else
F_2 ( V_39 ,
L_12 ,
V_30 -> V_44 , V_38 ) ;
V_30 -> V_33 = ( T_1 ) V_32 ;
}
return V_30 -> V_33 ;
}
static short F_12 ( T_1 V_47 ,
struct V_29 * V_34 , struct V_40 * * V_48 )
{
if ( ! F_11 ( V_34 ) ) {
F_2 ( V_24 ,
L_13 ,
V_47 ) ;
return 0 ;
}
* V_48 = V_34 -> V_46 [ V_47 ] ;
if ( ! * V_48 ) {
F_2 ( V_24 , L_14 ,
V_47 ) ;
return 0 ;
} else {
F_2 ( V_24 , L_15 ,
( * V_48 ) -> V_45 ) ;
}
return 1 ;
}
short F_13 ( struct V_29 * V_34 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
short V_49 = 1 ;
struct V_40 * V_48 ;
struct V_50 * V_30 ;
T_2 V_51 ;
if ( ! F_12 ( V_2 -> V_26 , V_34 , & V_48 ) ) {
F_2 ( V_24 ,
L_16 ,
V_2 -> V_23 ) ;
return 0 ;
}
V_4 -> error = 0 ;
V_51 =
sizeof( struct V_52 ) +
sizeof( struct V_53 ) ;
V_30 = (struct V_50 * ) V_48 ;
switch ( V_48 -> V_45 ) {
case V_54 :
if ( V_2 -> V_27 . V_55 . V_56 == V_57 ) {
V_4 -> V_27 . V_55 . V_58 [ 0 ] = V_30 -> V_27 . V_59 . V_60 [ 0 ] ;
V_4 -> V_27 . V_55 . V_58 [ 1 ] = V_30 -> V_27 . V_59 . V_60 [ 1 ] ;
} else if ( V_2 -> V_27 . V_55 . V_56 == V_61 ) {
if ( V_30 -> V_27 . V_59 . V_62 [ 0 ] ==
V_63 ) {
V_4 -> error =
V_64 ;
V_4 -> V_27 . V_55 . V_58 [ 0 ] = V_65 ;
V_4 -> V_27 . V_55 . V_58 [ 1 ] = V_65 ;
} else {
V_4 -> V_27 . V_55 . V_58 [ 0 ] =
V_30 -> V_27 . V_59 . V_62 [ 0 ] ;
V_4 -> V_27 . V_55 . V_58 [ 1 ] =
V_30 -> V_27 . V_59 . V_62 [ 1 ] ;
}
} else
V_49 = 0 ;
break;
case V_66 :
if ( V_2 -> V_27 . V_55 . V_56 == V_67 ) {
V_4 -> V_27 . V_55 . V_58 [ 0 ] = V_30 -> V_27 . V_68 . V_69 [ 0 ] ;
V_4 -> V_27 . V_55 . V_58 [ 1 ] = V_30 -> V_27 . V_68 . V_69 [ 1 ] ;
} else if ( V_2 -> V_27 . V_55 . V_56 == V_70 ) {
if ( V_30 -> V_27 . V_68 . V_71 & V_72 ) {
if ( V_30 -> V_27 . V_68 . V_71 & V_73 )
V_4 -> V_27 . V_55 . V_74 =
V_75 ;
else
V_4 -> V_27 . V_55 . V_74 = 0 ;
} else {
V_4 -> error =
V_64 ;
V_4 -> V_27 . V_55 . V_74 = 0 ;
}
} else {
V_49 = 0 ;
}
break;
case V_76 :
if ( V_2 -> V_27 . V_55 . V_56 == V_77 ) {
V_4 -> V_27 . V_55 . V_74 = V_30 -> V_27 . V_78 . V_79 ;
V_4 -> V_27 . V_55 . V_80 = V_30 -> V_27 . V_78 . V_81 ;
} else {
V_49 = 0 ;
}
break;
case V_82 :
if ( V_2 -> V_27 . V_55 . V_56 == V_83 )
V_4 -> V_27 . V_55 . V_74 = V_30 -> V_27 . V_84 . V_84 ;
else
V_49 = 0 ;
break;
case V_85 :
if ( V_2 -> V_27 . V_55 . V_56 == V_86 ) {
V_4 -> V_27 . V_55 . V_58 [ 0 ] = V_30 -> V_27 . V_87 . V_69 [ 0 ] ;
V_4 -> V_27 . V_55 . V_58 [ 1 ] = V_30 -> V_27 . V_87 . V_69 [ 1 ] ;
} else
V_49 = 0 ;
break;
case V_88 :
if ( V_2 -> V_27 . V_55 . V_56 == V_89 )
V_4 -> V_27 . V_55 . V_74 = V_30 -> V_27 . V_90 . V_91 ;
else if ( V_2 -> V_27 . V_55 . V_56 == V_92 )
V_4 -> V_27 . V_55 . V_74 = V_30 -> V_27 . V_90 . V_93 ;
else if ( V_2 -> V_27 . V_55 . V_56 == V_94 )
if ( V_30 -> V_27 . V_90 . V_95 ==
V_63 ) {
V_4 -> V_27 . V_96 . V_90 . V_97 = 0 ;
V_4 -> error =
V_64 ;
} else
V_4 -> V_27 . V_96 . V_90 . V_97 =
V_30 -> V_27 . V_90 . V_95 ;
else
V_49 = 0 ;
break;
case V_98 :
if ( V_2 -> V_27 . V_55 . V_56 == V_99 )
V_4 -> V_27 . V_55 . V_74 = V_30 -> V_27 . V_100 . V_101 ;
else if ( V_2 -> V_27 . V_55 . V_56 == V_102 )
V_4 -> V_27 . V_55 . V_74 = V_30 -> V_27 . V_100 . V_103 ;
else
V_49 = 0 ;
break;
case V_104 :
if ( V_2 -> V_27 . V_55 . V_56 == V_105 )
V_4 -> V_27 . V_55 . V_74 = V_30 -> V_27 . V_106 . V_103 ;
else
V_49 = 0 ;
break;
case V_107 :
if ( V_2 -> V_27 . V_55 . V_56 == V_108 )
V_4 -> V_27 . V_55 . V_74 = V_30 -> V_27 . V_109 . V_110 ;
else
V_49 = 0 ;
break;
case V_111 :
if ( V_2 -> V_27 . V_55 . V_56 == V_112 ) {
V_4 -> V_27 . V_55 . V_74 = V_30 -> V_27 . V_113 . V_110 ;
} else
V_49 = 0 ;
break;
case V_114 :
if ( V_2 -> V_27 . V_55 . V_56 == V_115 )
V_4 -> V_27 . V_55 . V_74 = V_30 -> V_27 . V_116 . V_117 ;
else
V_49 = 0 ;
break;
case V_118 :
if ( V_2 -> V_27 . V_55 . V_56 == V_119 )
V_4 -> V_27 . V_55 . V_74 = V_30 -> V_27 . V_120 . V_121 ;
else if ( V_2 -> V_27 . V_55 . V_56 == V_122 ) {
if ( V_30 -> V_27 . V_120 . V_123 ==
V_124 ) {
V_4 -> V_27 . V_55 . V_74 = 0 ;
V_4 -> error =
V_64 ;
} else
V_4 -> V_27 . V_55 . V_74 = V_30 -> V_27 . V_120 . V_123 ;
} else if ( V_2 -> V_27 . V_55 . V_56 == V_125 )
V_4 -> V_27 . V_55 . V_74 = V_30 -> V_27 . V_120 . V_126 ;
else
V_49 = 0 ;
break;
case V_127 : {
struct V_128 * V_129 ;
V_129 = (struct V_128 * ) V_48 ;
if ( ! ( V_129 -> V_130 & ( 1 <<
F_14 ( V_2 -> V_27 . V_55 .
V_56 ) ) ) ) {
V_4 -> error =
V_64 ;
break;
}
if ( V_2 -> V_27 . V_55 . V_56 == V_131 )
V_4 -> V_27 . V_55 . V_74 = V_129 -> V_48 ;
else if ( V_2 -> V_27 . V_55 . V_56 == V_132 )
V_4 -> V_27 . V_55 . V_74 = V_129 -> V_133 ;
else {
unsigned int V_13 =
F_14 ( V_2 -> V_27 . V_55 .
V_56 ) - 1 ;
unsigned int V_134 = V_2 -> V_27 . V_55 . V_74 ;
unsigned int V_135 , V_136 ;
char * V_137 ;
unsigned int V_138 ;
if ( V_13 > F_15 ( V_139 ) - 1 ) {
V_4 -> error =
V_64 ;
break;
}
V_137 =
( ( char * ) V_129 ) +
V_139 [ V_13 ] . V_134 ;
V_136 = V_139 [ V_13 ] . V_136 ;
V_137 [ V_136 - 1 ] = 0 ;
V_135 = strlen ( V_137 ) + 1 ;
if ( V_134 > V_135 ) {
V_4 -> error =
V_140 ;
break;
}
V_138 = V_135 - V_134 ;
if ( V_138 > sizeof( V_4 -> V_27 . V_96 . V_141 . V_142 ) )
V_138 = sizeof( V_4 -> V_27 . V_96 . V_141 .
V_142 ) ;
memcpy ( V_4 -> V_27 . V_96 . V_141 . V_142 ,
& V_137 [ V_134 ] , V_138 ) ;
V_4 -> V_27 . V_96 . V_141 . V_143 =
V_135 - V_134 - V_138 ;
}
}
break;
default:
V_49 = 0 ;
break;
}
F_2 ( V_24 , L_17 ,
V_49 ? L_18 : L_19 , V_2 -> V_23 ,
V_48 -> V_47 , V_48 -> V_45 , V_2 -> V_27 . V_55 . V_56 ) ;
if ( V_49 )
V_4 -> V_144 = ( T_1 ) V_51 ;
return V_49 ;
}
void F_16 ( struct V_29 * V_34 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_50 * V_30 ;
struct V_40 * V_48 ;
if ( V_4 -> error )
return;
if ( ! F_12 ( V_2 -> V_26 , V_34 , & V_48 ) ) {
F_2 ( V_24 ,
L_16 ,
V_2 -> V_23 ) ;
return;
}
V_30 = (struct V_50 * ) V_48 ;
switch ( V_48 -> V_45 ) {
case V_66 :
if ( V_2 -> V_27 . V_55 . V_56 == V_67 ) {
V_30 -> V_27 . V_68 . V_69 [ 0 ] = V_4 -> V_27 . V_55 . V_58 [ 0 ] ;
V_30 -> V_27 . V_68 . V_69 [ 1 ] = V_4 -> V_27 . V_55 . V_58 [ 1 ] ;
} else if ( V_2 -> V_27 . V_55 . V_56 == V_70 ) {
if ( V_2 -> V_27 . V_55 . V_74 )
V_30 -> V_27 . V_68 . V_71 |= V_73 ;
else
V_30 -> V_27 . V_68 . V_71 &= ~ V_73 ;
}
break;
case V_76 :
if ( V_2 -> V_27 . V_55 . V_56 == V_77 ) {
V_30 -> V_27 . V_78 . V_79 = ( T_1 ) V_2 -> V_27 . V_55 . V_74 ;
V_30 -> V_27 . V_78 . V_81 = ( T_1 ) V_2 -> V_27 . V_55 . V_80 ;
}
break;
case V_82 :
if ( V_2 -> V_27 . V_55 . V_56 == V_83 )
V_30 -> V_27 . V_84 . V_84 = ( T_1 ) V_2 -> V_27 . V_55 . V_74 ;
break;
case V_85 :
if ( V_2 -> V_27 . V_55 . V_56 == V_86 ) {
V_30 -> V_27 . V_68 . V_69 [ 0 ] = V_4 -> V_27 . V_55 . V_58 [ 0 ] ;
V_30 -> V_27 . V_68 . V_69 [ 1 ] = V_4 -> V_27 . V_55 . V_58 [ 1 ] ;
}
break;
case V_114 :
if ( V_2 -> V_27 . V_55 . V_56 == V_115 )
V_30 -> V_27 . V_116 . V_117 = ( T_1 ) V_2 -> V_27 . V_55 . V_74 ;
break;
case V_104 :
if ( V_2 -> V_27 . V_55 . V_56 == V_105 )
V_30 -> V_27 . V_106 . V_103 = V_2 -> V_27 . V_55 . V_74 ;
break;
case V_98 :
if ( V_2 -> V_27 . V_55 . V_56 == V_102 )
V_30 -> V_27 . V_100 . V_103 = V_2 -> V_27 . V_55 . V_74 ;
break;
case V_118 :
if ( V_2 -> V_27 . V_55 . V_56 == V_119 )
V_30 -> V_27 . V_120 . V_121 = ( T_1 ) V_2 -> V_27 . V_55 . V_74 ;
else if ( V_2 -> V_27 . V_55 . V_56 == V_122 )
V_30 -> V_27 . V_120 . V_123 = ( T_1 ) V_2 -> V_27 . V_55 . V_74 ;
else if ( V_2 -> V_27 . V_55 . V_56 == V_125 )
V_30 -> V_27 . V_120 . V_126 = V_2 -> V_27 . V_55 . V_74 ;
break;
default:
break;
}
}
struct V_29 * F_17 ( const T_3 V_35 ,
const T_3 V_145 , T_4 * V_146 )
{
struct V_29 * V_34 =
F_18 ( sizeof( * V_34 ) , V_147 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_46 = F_19 ( sizeof( * V_34 -> V_46 ) * V_35 ,
V_147 ) ;
if ( ! V_34 -> V_46 ) {
F_20 ( V_34 ) ;
return NULL ;
}
V_34 -> V_36 = V_145 ;
V_34 -> V_35 = V_35 ;
V_34 -> V_34 = V_146 ;
V_34 -> V_33 = 0 ;
return V_34 ;
}
void F_21 ( struct V_29 * V_34 )
{
if ( V_34 ) {
F_20 ( V_34 -> V_46 ) ;
F_20 ( V_34 ) ;
}
}
static void F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_23 ( V_4 , V_148 , V_2 -> V_8 , 0 ) ;
switch ( V_2 -> V_8 ) {
case V_149 :
case V_150 :
case V_151 :
break;
case V_152 :
F_9 () ;
F_24 ( & V_12 ) ;
break;
case V_153 :
F_10 ( V_2 , V_4 ) ;
break;
case V_154 :
V_4 -> V_27 . V_28 . V_155 = V_12 . V_22 ;
break;
case V_156 :
break;
default:
V_4 -> error = V_157 ;
break;
}
}
void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( V_2 -> type ) {
case V_158 :
switch ( V_2 -> V_7 ) {
case V_148 :
F_22 ( V_2 , V_4 ) ;
break;
}
break;
default:
V_4 -> error = V_159 ;
break;
}
}
