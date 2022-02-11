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
F_2 ( ERROR , L_1 ,
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
L_3 ,
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
F_2 ( ERROR , L_4 ) ;
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
F_2 ( V_24 , L_5 ,
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
F_2 ( V_39 , L_6 ,
V_30 -> V_35 ) ;
for ( V_31 = 0 ; V_31 < V_30 -> V_35 ; V_31 ++ ) {
struct V_40 * V_41 =
(struct V_40 * )
& V_37 [ V_38 ] ;
if ( ! V_41 -> V_42 ) {
if ( ! V_31 ) {
F_2 ( V_43 ,
L_7 ,
V_30 -> V_44 ) ;
return 0 ;
}
F_2 ( ERROR ,
L_8 ,
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
L_9 ,
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
L_10 ,
V_30 -> V_44 , V_38 ,
V_30 -> V_36 ) ;
else
F_2 ( V_39 ,
L_11 ,
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
L_12 ,
V_47 ) ;
return 0 ;
}
* V_48 = V_34 -> V_46 [ V_47 ] ;
if ( ! * V_48 ) {
F_2 ( V_24 , L_13 ,
V_47 ) ;
return 0 ;
} else {
F_2 ( V_24 , L_14 ,
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
struct V_51 * V_52 ;
if ( ! F_12 ( V_2 -> V_26 , V_34 , & V_48 ) ) {
F_2 ( V_24 ,
L_15 ,
V_2 -> V_23 ) ;
return 0 ;
}
V_4 -> error = 0 ;
V_30 = (struct V_50 * ) V_48 ;
V_52 = (struct V_51 * ) V_48 ;
switch ( V_48 -> V_45 ) {
case V_53 :
if ( V_2 -> V_27 . V_54 . V_55 == V_56 ) {
V_4 -> V_27 . V_54 . V_57 [ 0 ] = V_30 -> V_27 . V_58 . V_59 [ 0 ] ;
V_4 -> V_27 . V_54 . V_57 [ 1 ] = V_30 -> V_27 . V_58 . V_59 [ 1 ] ;
} else if ( V_2 -> V_27 . V_54 . V_55 == V_60 ) {
if ( V_30 -> V_27 . V_58 . V_61 [ 0 ] ==
V_62 ) {
V_4 -> error =
V_63 ;
V_4 -> V_27 . V_54 . V_57 [ 0 ] = V_64 ;
V_4 -> V_27 . V_54 . V_57 [ 1 ] = V_64 ;
} else {
V_4 -> V_27 . V_54 . V_57 [ 0 ] =
V_30 -> V_27 . V_58 . V_61 [ 0 ] ;
V_4 -> V_27 . V_54 . V_57 [ 1 ] =
V_30 -> V_27 . V_58 . V_61 [ 1 ] ;
}
} else
V_49 = 0 ;
break;
case V_65 :
if ( V_2 -> V_27 . V_54 . V_55 == V_66 ) {
V_4 -> V_27 . V_54 . V_57 [ 0 ] = V_30 -> V_27 . V_67 . V_68 [ 0 ] ;
V_4 -> V_27 . V_54 . V_57 [ 1 ] = V_30 -> V_27 . V_67 . V_68 [ 1 ] ;
} else if ( V_2 -> V_27 . V_54 . V_55 == V_69 ) {
if ( V_30 -> V_27 . V_67 . V_70 & V_71 ) {
if ( V_30 -> V_27 . V_67 . V_70 & V_72 )
V_4 -> V_27 . V_54 . V_73 =
V_74 ;
else
V_4 -> V_27 . V_54 . V_73 = 0 ;
} else {
V_4 -> error =
V_63 ;
V_4 -> V_27 . V_54 . V_73 = 0 ;
}
} else {
V_49 = 0 ;
}
break;
case V_75 :
if ( V_2 -> V_27 . V_54 . V_55 == V_76 ) {
V_4 -> V_27 . V_54 . V_73 = V_30 -> V_27 . V_77 . V_78 ;
V_4 -> V_27 . V_54 . V_79 = V_30 -> V_27 . V_77 . V_80 ;
} else {
V_49 = 0 ;
}
break;
case V_81 :
if ( V_2 -> V_27 . V_54 . V_55 == V_82 )
V_4 -> V_27 . V_54 . V_73 = V_30 -> V_27 . V_83 . V_83 ;
else
V_49 = 0 ;
break;
case V_84 :
if ( V_2 -> V_27 . V_54 . V_55 == V_85 ) {
V_4 -> V_27 . V_54 . V_57 [ 0 ] = V_30 -> V_27 . V_86 . V_68 [ 0 ] ;
V_4 -> V_27 . V_54 . V_57 [ 1 ] = V_30 -> V_27 . V_86 . V_68 [ 1 ] ;
} else
V_49 = 0 ;
break;
case V_87 :
if ( V_2 -> V_27 . V_54 . V_55 == V_88 )
V_4 -> V_27 . V_54 . V_73 = V_30 -> V_27 . V_89 . V_90 ;
else if ( V_2 -> V_27 . V_54 . V_55 == V_91 )
V_4 -> V_27 . V_54 . V_73 = V_30 -> V_27 . V_89 . V_92 ;
else if ( V_2 -> V_27 . V_54 . V_55 == V_93 )
if ( V_30 -> V_27 . V_89 . V_94 ==
V_62 ) {
V_4 -> V_27 . V_95 . V_89 . V_96 = 0 ;
V_4 -> error =
V_63 ;
} else
V_4 -> V_27 . V_95 . V_89 . V_96 =
V_30 -> V_27 . V_89 . V_94 ;
else
V_49 = 0 ;
break;
case V_97 :
if ( V_2 -> V_27 . V_54 . V_55 == V_98 )
V_4 -> V_27 . V_54 . V_73 = V_30 -> V_27 . V_99 . V_100 ;
else if ( V_2 -> V_27 . V_54 . V_55 == V_101 )
V_4 -> V_27 . V_54 . V_73 = V_30 -> V_27 . V_99 . V_102 ;
else
V_49 = 0 ;
break;
case V_103 :
if ( V_2 -> V_27 . V_54 . V_55 == V_104 )
V_4 -> V_27 . V_54 . V_73 = V_30 -> V_27 . V_105 . V_102 ;
else
V_49 = 0 ;
break;
case V_106 :
if ( V_2 -> V_27 . V_54 . V_55 == V_107 )
V_4 -> V_27 . V_54 . V_73 = V_30 -> V_27 . V_108 . V_109 ;
else
V_49 = 0 ;
break;
case V_110 :
if ( V_2 -> V_27 . V_54 . V_55 == V_111 ) {
V_4 -> V_27 . V_54 . V_73 = V_30 -> V_27 . V_112 . V_109 ;
} else
V_49 = 0 ;
break;
case V_113 :
if ( V_2 -> V_27 . V_54 . V_55 == V_114 )
V_4 -> V_27 . V_54 . V_73 = V_30 -> V_27 . V_115 . V_116 ;
else
V_49 = 0 ;
break;
case V_117 :
if ( V_2 -> V_27 . V_54 . V_55 == V_118 )
V_4 -> V_27 . V_54 . V_73 = V_30 -> V_27 . V_119 . V_120 ;
else if ( V_2 -> V_27 . V_54 . V_55 == V_121 ) {
if ( V_30 -> V_27 . V_119 . V_122 ==
V_123 ) {
V_4 -> V_27 . V_54 . V_73 = 0 ;
V_4 -> error =
V_63 ;
} else
V_4 -> V_27 . V_54 . V_73 = V_30 -> V_27 . V_119 . V_122 ;
} else if ( V_2 -> V_27 . V_54 . V_55 == V_124 )
V_4 -> V_27 . V_54 . V_73 = V_30 -> V_27 . V_119 . V_125 ;
else
V_49 = 0 ;
break;
case V_126 : {
struct V_51 * V_52 ;
V_52 = (struct V_51 * ) V_48 ;
if ( ! ( V_52 -> V_127 & ( 1 <<
F_14 ( V_2 -> V_27 . V_54 .
V_55 ) ) ) ) {
V_4 -> error =
V_63 ;
break;
}
if ( V_2 -> V_27 . V_54 . V_55 == V_128 )
V_4 -> V_27 . V_54 . V_73 = V_52 -> V_48 ;
else if ( V_2 -> V_27 . V_54 . V_55 == V_129 )
V_4 -> V_27 . V_54 . V_73 = V_52 -> V_130 ;
else {
unsigned int V_13 =
F_14 ( V_2 -> V_27 . V_54 .
V_55 ) - 1 ;
unsigned int V_131 = V_2 -> V_27 . V_54 . V_73 ;
unsigned int V_132 , V_133 ;
char * V_134 ;
unsigned int V_135 ;
if ( V_13 > F_15 ( V_136 ) - 1 ) {
V_4 -> error =
V_63 ;
break;
}
V_134 =
( ( char * ) V_52 ) +
V_136 [ V_13 ] . V_131 ;
V_133 = V_136 [ V_13 ] . V_133 ;
V_134 [ V_133 - 1 ] = 0 ;
V_132 = strlen ( V_134 ) + 1 ;
if ( V_131 > V_132 ) {
V_4 -> error =
V_137 ;
break;
}
V_135 = V_132 - V_131 ;
if ( V_135 > sizeof( V_4 -> V_27 . V_95 . V_138 . V_139 ) )
V_135 = sizeof( V_4 -> V_27 . V_95 . V_138 .
V_139 ) ;
memcpy ( V_4 -> V_27 . V_95 . V_138 . V_139 ,
& V_134 [ V_131 ] , V_135 ) ;
V_4 -> V_27 . V_95 . V_138 . V_140 =
V_132 - V_131 - V_135 ;
}
}
break;
default:
V_49 = 0 ;
break;
}
F_2 ( V_24 , L_16 ,
V_49 ? L_17 : L_18 , V_2 -> V_23 ,
V_48 -> V_47 , V_48 -> V_45 , V_2 -> V_27 . V_54 . V_55 ) ;
if ( V_49 )
V_4 -> V_141 =
sizeof( struct V_142 ) +
sizeof( struct V_143 ) ;
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
L_15 ,
V_2 -> V_23 ) ;
return;
}
V_30 = (struct V_50 * ) V_48 ;
switch ( V_48 -> V_45 ) {
case V_65 :
if ( V_2 -> V_27 . V_54 . V_55 == V_66 ) {
V_30 -> V_27 . V_67 . V_68 [ 0 ] = V_4 -> V_27 . V_54 . V_57 [ 0 ] ;
V_30 -> V_27 . V_67 . V_68 [ 1 ] = V_4 -> V_27 . V_54 . V_57 [ 1 ] ;
} else if ( V_2 -> V_27 . V_54 . V_55 == V_69 ) {
if ( V_2 -> V_27 . V_54 . V_73 )
V_30 -> V_27 . V_67 . V_70 |= V_72 ;
else
V_30 -> V_27 . V_67 . V_70 &= ~ V_72 ;
}
break;
case V_75 :
if ( V_2 -> V_27 . V_54 . V_55 == V_76 ) {
V_30 -> V_27 . V_77 . V_78 = ( T_1 ) V_2 -> V_27 . V_54 . V_73 ;
V_30 -> V_27 . V_77 . V_80 = ( T_1 ) V_2 -> V_27 . V_54 . V_79 ;
}
break;
case V_81 :
if ( V_2 -> V_27 . V_54 . V_55 == V_82 )
V_30 -> V_27 . V_83 . V_83 = ( T_1 ) V_2 -> V_27 . V_54 . V_73 ;
break;
case V_84 :
if ( V_2 -> V_27 . V_54 . V_55 == V_85 ) {
V_30 -> V_27 . V_67 . V_68 [ 0 ] = V_4 -> V_27 . V_54 . V_57 [ 0 ] ;
V_30 -> V_27 . V_67 . V_68 [ 1 ] = V_4 -> V_27 . V_54 . V_57 [ 1 ] ;
}
break;
case V_113 :
if ( V_2 -> V_27 . V_54 . V_55 == V_114 )
V_30 -> V_27 . V_115 . V_116 = ( T_1 ) V_2 -> V_27 . V_54 . V_73 ;
break;
case V_103 :
if ( V_2 -> V_27 . V_54 . V_55 == V_104 )
V_30 -> V_27 . V_105 . V_102 = V_2 -> V_27 . V_54 . V_73 ;
break;
case V_97 :
if ( V_2 -> V_27 . V_54 . V_55 == V_101 )
V_30 -> V_27 . V_99 . V_102 = V_2 -> V_27 . V_54 . V_73 ;
break;
case V_117 :
if ( V_2 -> V_27 . V_54 . V_55 == V_118 )
V_30 -> V_27 . V_119 . V_120 = ( T_1 ) V_2 -> V_27 . V_54 . V_73 ;
else if ( V_2 -> V_27 . V_54 . V_55 == V_121 )
V_30 -> V_27 . V_119 . V_122 = ( T_1 ) V_2 -> V_27 . V_54 . V_73 ;
else if ( V_2 -> V_27 . V_54 . V_55 == V_124 )
V_30 -> V_27 . V_119 . V_125 = V_2 -> V_27 . V_54 . V_73 ;
break;
default:
break;
}
}
struct V_29 * F_17 ( const T_2 V_35 ,
const T_2 V_144 , T_3 * V_145 )
{
struct V_29 * V_34 =
F_18 ( sizeof( * V_34 ) , V_146 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_46 =
F_18 ( sizeof( * V_34 -> V_46 ) * V_35 , V_146 ) ;
if ( ! V_34 -> V_46 ) {
F_19 ( V_34 ) ;
return NULL ;
}
memset ( V_34 -> V_46 , 0 , sizeof( * V_34 -> V_46 ) * V_35 ) ;
V_34 -> V_36 = V_144 ;
V_34 -> V_35 = V_35 ;
V_34 -> V_34 = V_145 ;
V_34 -> V_33 = 0 ;
return V_34 ;
}
void F_20 ( struct V_29 * V_34 )
{
if ( V_34 ) {
F_19 ( V_34 -> V_46 ) ;
F_19 ( V_34 ) ;
}
}
static void F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_22 ( V_4 , V_147 , V_2 -> V_8 , 0 ) ;
switch ( V_2 -> V_8 ) {
case V_148 :
case V_149 :
case V_150 :
break;
case V_151 :
F_9 () ;
F_23 ( & V_12 ) ;
break;
case V_152 :
F_10 ( V_2 , V_4 ) ;
break;
case V_153 :
V_4 -> V_27 . V_28 . V_154 = V_12 . V_22 ;
break;
case V_155 :
break;
default:
V_4 -> error = V_156 ;
break;
}
}
void F_24 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( V_2 -> type ) {
case V_157 :
switch ( V_2 -> V_7 ) {
case V_147 :
F_21 ( V_2 , V_4 ) ;
break;
}
break;
default:
V_4 -> error = V_158 ;
break;
}
}
