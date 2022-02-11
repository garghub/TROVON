static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 V_8 ;
struct V_9 * V_9 = ( void * ) & V_8 . V_10 . V_11 ;
if ( V_6 -> V_12 ) {
V_6 -> V_12 = 0 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_13 ;
V_9 -> V_11 . V_14 = V_4 -> V_15 ;
memcpy ( & V_9 -> V_11 . V_11 , V_4 -> V_16 , V_4 -> V_15 ) ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
}
}
static int
F_3 ( struct V_18 * V_19 , const struct V_20 * V_21 )
{
struct V_5 * V_6 = F_4 ( V_19 ) ;
struct V_8 V_8 ;
struct V_9 * V_9 = ( void * ) & V_8 . V_10 . V_11 ;
if ( ( V_21 -> V_22 & V_23 ) != V_24 ) {
F_5 ( V_19 -> V_25 -> V_26 , L_1 ) ;
return - V_27 ;
}
if ( F_6 ( V_21 -> V_28 ) > V_29 )
return - V_27 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_30 ;
memcpy ( & V_9 -> V_4 , V_21 , sizeof( V_9 -> V_4 ) ) ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
return 0 ;
}
static int
F_7 ( struct V_18 * V_19 , unsigned V_31 )
{
struct V_5 * V_6 = F_4 ( V_19 ) ;
F_5 ( V_19 -> V_25 -> V_26 , L_2 , V_31 ) ;
if ( V_31 == V_6 -> V_32 )
return 0 ;
else if ( V_31 != V_6 -> V_33 )
return - V_27 ;
else
return V_6 -> V_34 == V_35 ? 1 : 0 ;
}
static int
F_8 ( struct V_18 * V_19 , unsigned V_31 , unsigned V_36 )
{
struct V_5 * V_6 = F_4 ( V_19 ) ;
struct V_8 V_8 ;
struct V_9 * V_9 = ( void * ) & V_8 . V_10 . V_11 ;
int V_37 ;
F_5 ( V_19 -> V_25 -> V_26 , L_3 , V_31 , V_36 ) ;
if ( V_31 == V_6 -> V_32 ) {
if ( V_36 )
return - V_27 ;
if ( V_6 -> V_34 == V_38 ) {
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_39 ;
V_9 -> V_40 = V_19 -> V_25 -> V_26 -> V_41 -> V_40 ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
V_6 -> V_34 = V_42 ;
}
return 0 ;
}
if ( V_31 != V_6 -> V_33 )
return - V_27 ;
switch ( V_36 ) {
case 0 :
if ( V_6 -> V_34 != V_35 )
return 0 ;
if ( V_6 -> V_43 . V_2 )
F_9 ( V_6 -> V_43 . V_2 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_44 ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
V_6 -> V_34 = V_42 ;
break;
case 1 :
if ( V_6 -> V_34 != V_42 )
return 0 ;
if ( V_6 -> V_43 . V_2 ) {
V_37 = F_10 ( V_19 -> V_25 -> V_26 -> V_41 ,
& ( V_6 -> V_45 ) , V_6 -> V_43 . V_2 ) ;
if ( V_37 )
return V_37 ;
F_11 ( V_6 -> V_43 . V_2 ) ;
}
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_46 ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
V_6 -> V_34 = V_35 ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static void
F_12 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = F_4 ( V_19 ) ;
struct V_8 V_8 ;
F_5 ( V_19 -> V_25 -> V_26 , L_4 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_47 ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
V_6 -> V_34 = V_38 ;
}
void
F_13 ( struct V_5 * V_6 )
{
struct V_48 * V_26 = V_6 -> V_45 . V_25 -> V_26 ;
int V_37 ;
if ( ( V_37 = F_14 ( & V_6 -> V_45 ) ) < 0 )
F_5 ( V_26 , L_5 , V_37 ) ;
}
void
F_15 ( struct V_5 * V_6 )
{
struct V_48 * V_26 = V_6 -> V_45 . V_25 -> V_26 ;
int V_37 ;
if ( ( V_37 = F_16 ( & V_6 -> V_45 ) ) < 0 )
F_5 ( V_26 , L_6 , V_37 ) ;
}
static int
F_17 ( struct V_5 * V_6 )
{
struct V_48 * V_26 = V_6 -> V_45 . V_25 -> V_26 ;
struct V_49 * V_43 ;
V_43 = F_18 () ;
if ( V_43 == NULL )
return - V_50 ;
V_43 -> V_51 = & V_26 -> V_41 -> V_52 ;
V_43 -> V_53 = & V_54 ;
V_43 -> V_55 = V_56 ;
F_19 ( V_43 -> V_57 , V_26 -> V_41 -> V_57 , sizeof( V_43 -> V_57 ) ) ;
V_6 -> V_17 = V_43 ;
F_20 ( V_43 , V_6 ) ;
return F_21 ( V_43 , V_58 , - 1 ) ;
}
static struct V_59 * * T_1
F_22 ( struct V_5 * V_6 , enum V_60 V_40 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
const struct V_65 * const * V_66 ;
const struct V_65 * const * V_67 ;
const struct V_59 * const * V_68 ;
const struct V_59 * const * V_69 ;
static struct V_70 * V_71 ;
struct V_59 * * V_72 ;
struct V_59 * * V_73 ;
unsigned int V_74 ;
unsigned int V_75 ;
unsigned int V_76 ;
unsigned int V_77 ;
void * V_78 ;
switch ( V_40 ) {
case V_79 :
V_66 = V_6 -> V_80 . V_81 ;
V_67 = V_6 -> V_80 . V_82 ;
V_68 = V_83 ;
V_71 = & V_84 ;
break;
case V_85 :
V_66 = V_6 -> V_80 . V_86 ;
V_67 = V_6 -> V_80 . V_87 ;
V_68 = V_88 ;
V_71 = & V_89 ;
break;
case V_90 :
default:
V_66 = V_6 -> V_80 . V_86 ;
V_67 = V_6 -> V_80 . V_91 ;
V_68 = V_92 ;
V_71 = & V_89 ;
break;
}
V_74 = 0 ;
V_75 = 0 ;
V_77 = V_93 . V_94 + V_95 . V_94
+ V_71 -> V_94 + V_96 . V_94
+ V_97 . V_94 ;
if ( V_40 == V_79 ) {
V_77 += V_98 . V_94 ;
V_76 = 6 ;
} else {
V_76 = 5 ;
}
for ( V_69 = ( const struct V_59 * * ) V_66 ;
* V_69 ; ++ V_69 ) {
V_74 += ( * V_69 ) -> V_94 ;
V_77 += ( * V_69 ) -> V_94 ;
V_76 ++ ;
}
for ( V_69 = ( const struct V_59 * * ) V_67 ;
* V_69 ; ++ V_69 ) {
V_75 += ( * V_69 ) -> V_94 ;
V_77 += ( * V_69 ) -> V_94 ;
V_76 ++ ;
}
for ( V_69 = V_68 ; * V_69 ; ++ V_69 ) {
V_77 += ( * V_69 ) -> V_94 ;
V_76 ++ ;
}
V_78 = F_23 ( ( V_76 + 1 ) * sizeof( * V_69 ) + V_77 , V_99 ) ;
if ( V_78 == NULL )
return NULL ;
V_73 = V_78 ;
V_72 = V_78 ;
V_78 += ( V_76 + 1 ) * sizeof( * V_69 ) ;
F_24 ( V_78 , V_72 , & V_93 ) ;
F_24 ( V_78 , V_72 , & V_95 ) ;
V_64 = V_78 ;
F_25 ( V_78 , V_72 ,
( const struct V_59 * * ) V_66 ) ;
V_64 -> V_100 = F_26 ( V_74 ) ;
V_64 -> V_101 = 1 ;
V_64 -> V_102 [ 0 ] = V_6 -> V_33 ;
F_24 ( V_78 , V_72 , V_71 ) ;
if ( V_40 == V_79 )
F_24 ( V_78 , V_72 , & V_98 ) ;
F_24 ( V_78 , V_72 , & V_96 ) ;
F_24 ( V_78 , V_72 , & V_97 ) ;
V_62 = V_78 ;
F_25 ( V_78 , V_72 ,
( const struct V_59 * * ) V_67 ) ;
V_62 -> V_100 = F_26 ( V_75 ) ;
V_62 -> V_103 =
V_104 . V_103 ;
F_25 ( V_78 , V_72 , V_68 ) ;
* V_72 = NULL ;
return V_73 ;
}
static void
F_27 ( struct V_105 * V_106 , struct V_18 * V_19 )
{
struct V_48 * V_26 = V_106 -> V_26 ;
struct V_5 * V_6 = F_4 ( V_19 ) ;
F_5 ( V_26 , L_7 ) ;
F_28 ( V_6 -> V_17 ) ;
V_6 -> V_107 -> V_108 = NULL ;
V_6 -> V_43 . V_2 -> V_108 = NULL ;
V_109 [ V_110 ] . V_111 = 0 ;
F_29 ( V_26 -> V_41 -> V_112 , V_6 -> V_113 ) ;
F_30 ( V_6 -> V_114 ) ;
F_31 ( V_19 ) ;
F_30 ( V_6 ) ;
}
static int T_1
F_32 ( struct V_105 * V_106 , struct V_18 * V_19 )
{
struct V_48 * V_26 = V_106 -> V_26 ;
struct V_5 * V_6 = F_4 ( V_19 ) ;
struct V_1 * V_2 ;
int V_37 = - V_27 ;
F_5 ( V_26 , L_8 ) ;
if ( V_115 < 1 )
V_115 = 1 ;
if ( V_115 > 16 )
V_115 = 16 ;
if ( V_116 > 2 )
V_116 = 2 ;
if ( V_117 > 15 )
V_117 = 15 ;
V_104 . V_118 = V_119 > 1023 ?
1023 : V_119 ;
V_104 . V_120 = V_115 ;
V_2 = F_33 ( V_26 -> V_41 , & V_89 ) ;
if ( ! V_2 ) {
F_5 ( V_26 , L_9 ) ;
goto error;
}
V_6 -> V_107 = V_2 ;
V_2 -> V_108 = V_6 ;
V_2 = F_33 ( V_26 -> V_41 , & V_104 ) ;
if ( ! V_2 ) {
F_5 ( V_26 , L_10 ) ;
goto error;
}
V_6 -> V_43 . V_2 = V_2 ;
V_2 -> V_108 = V_6 ;
if ( ( V_37 = F_34 ( V_106 , V_19 ) ) < 0 )
goto error;
V_93 . V_121 = V_37 ;
V_95 . V_122 = V_37 ;
V_6 -> V_32 = V_37 ;
if ( ( V_37 = F_34 ( V_106 , V_19 ) ) < 0 )
goto error;
V_97 . V_122 = V_37 ;
V_123 . V_122 = V_37 ;
V_6 -> V_33 = V_37 ;
if ( V_119 > 1024 )
V_119 = 1024 ;
V_124 . V_118 = V_119 ;
V_124 . V_118 |= V_116 << 11 ;
V_124 . V_120 = V_115 ;
V_124 . V_103 =
V_104 . V_103 ;
V_125 . V_118 = V_119 ;
V_125 . V_120 = V_115 ;
V_126 . V_127 = V_116 ;
V_126 . V_128 = V_117 ;
V_126 . V_129 =
V_119 * ( V_116 + 1 ) *
( V_117 + 1 ) ;
V_125 . V_103 =
V_104 . V_103 ;
V_19 -> V_130 = F_22 ( V_6 , V_90 ) ;
if ( F_35 ( V_26 -> V_41 ) )
V_19 -> V_131 = F_22 ( V_6 , V_85 ) ;
if ( F_36 ( V_106 -> V_26 -> V_41 ) )
V_19 -> V_132 = F_22 ( V_6 , V_79 ) ;
V_6 -> V_113 = F_37 ( V_26 -> V_41 -> V_112 , V_99 ) ;
V_6 -> V_114 = F_23 ( V_29 , V_99 ) ;
if ( V_6 -> V_113 == NULL || V_6 -> V_114 == NULL ) {
V_37 = - V_50 ;
goto error;
}
V_6 -> V_113 -> V_16 = V_6 -> V_114 ;
V_6 -> V_113 -> V_133 = F_1 ;
V_6 -> V_113 -> V_7 = V_6 ;
if ( ( V_37 = F_16 ( V_19 ) ) < 0 )
goto error;
V_37 = F_38 ( & V_6 -> V_43 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_17 ( V_6 ) ;
if ( V_37 < 0 ) {
F_39 ( V_134 L_11 ) ;
goto error;
}
return 0 ;
error:
if ( V_6 -> V_17 )
V_56 ( V_6 -> V_17 ) ;
if ( V_6 -> V_107 )
V_6 -> V_107 -> V_108 = NULL ;
if ( V_6 -> V_43 . V_2 )
V_6 -> V_43 . V_2 -> V_108 = NULL ;
if ( V_6 -> V_113 ) {
F_29 ( V_26 -> V_41 -> V_112 , V_6 -> V_113 ) ;
F_30 ( V_6 -> V_114 ) ;
}
F_31 ( V_19 ) ;
return V_37 ;
}
int T_1
F_40 ( struct V_105 * V_106 ,
const struct V_65 * const * V_86 ,
const struct V_65 * const * V_81 ,
const struct V_65 * const * V_91 ,
const struct V_65 * const * V_87 ,
const struct V_65 * const * V_82 )
{
struct V_5 * V_6 ;
int V_37 = 0 ;
if ( ! F_35 ( V_106 -> V_26 -> V_41 ) )
return - V_27 ;
V_6 = F_41 ( sizeof( * V_6 ) , V_99 ) ;
if ( V_6 == NULL )
return - V_50 ;
V_6 -> V_34 = V_38 ;
if ( V_86 == NULL || V_86 [ 0 ] == NULL ||
V_86 [ 0 ] -> V_135 != V_136 )
goto error;
if ( V_81 == NULL || V_81 [ 0 ] == NULL ||
V_81 [ 0 ] -> V_135 != V_136 )
goto error;
if ( V_91 == NULL || V_91 [ 0 ] == NULL ||
V_91 [ 0 ] -> V_135 != V_137 )
goto error;
if ( V_87 == NULL || V_87 [ 0 ] == NULL ||
V_87 [ 0 ] -> V_135 != V_137 )
goto error;
if ( V_82 == NULL || V_82 [ 0 ] == NULL ||
V_82 [ 0 ] -> V_135 != V_137 )
goto error;
V_6 -> V_80 . V_86 = V_86 ;
V_6 -> V_80 . V_81 = V_81 ;
V_6 -> V_80 . V_91 = V_91 ;
V_6 -> V_80 . V_87 = V_87 ;
V_6 -> V_80 . V_82 = V_82 ;
if ( V_109 [ V_110 ] . V_111 == 0 ) {
V_37 = F_42 ( V_106 -> V_26 , V_109 ) ;
if ( V_37 )
goto error;
V_93 . V_138 =
V_109 [ V_110 ] . V_111 ;
V_95 . V_139 =
V_109 [ V_140 ] . V_111 ;
V_37 = V_109 [ V_141 ] . V_111 ;
V_97 . V_139 = V_37 ;
V_123 . V_139 = V_37 ;
}
V_6 -> V_45 . V_57 = L_12 ;
V_6 -> V_45 . V_142 = V_143 ;
V_6 -> V_45 . V_144 = F_32 ;
V_6 -> V_45 . V_145 = F_27 ;
V_6 -> V_45 . V_146 = F_7 ;
V_6 -> V_45 . V_147 = F_8 ;
V_6 -> V_45 . V_148 = F_12 ;
V_6 -> V_45 . V_149 = F_3 ;
V_37 = F_43 ( V_106 , & V_6 -> V_45 ) ;
if ( V_37 )
F_30 ( V_6 ) ;
return V_37 ;
error:
F_30 ( V_6 ) ;
return V_37 ;
}
