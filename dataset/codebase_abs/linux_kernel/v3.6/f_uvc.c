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
V_43 -> V_53 = - 1 ;
V_43 -> V_54 = & V_55 ;
V_43 -> V_56 = V_57 ;
strncpy ( V_43 -> V_58 , V_26 -> V_41 -> V_58 , sizeof( V_43 -> V_58 ) ) ;
V_6 -> V_17 = V_43 ;
F_19 ( V_43 , V_6 ) ;
return F_20 ( V_43 , V_59 , - 1 ) ;
}
static struct V_60 * * T_1
F_21 ( struct V_5 * V_6 , enum V_61 V_40 )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
const struct V_66 * const * V_67 ;
const struct V_66 * const * V_68 ;
const struct V_60 * const * V_69 ;
const struct V_60 * const * V_70 ;
static struct V_71 * V_72 ;
struct V_60 * * V_73 ;
struct V_60 * * V_74 ;
unsigned int V_75 ;
unsigned int V_76 ;
unsigned int V_77 ;
unsigned int V_78 ;
void * V_79 ;
switch ( V_40 ) {
case V_80 :
V_67 = V_6 -> V_81 . V_82 ;
V_68 = V_6 -> V_81 . V_83 ;
V_69 = V_84 ;
V_72 = & V_85 ;
break;
case V_86 :
V_67 = V_6 -> V_81 . V_87 ;
V_68 = V_6 -> V_81 . V_88 ;
V_69 = V_89 ;
V_72 = & V_90 ;
break;
case V_91 :
default:
V_67 = V_6 -> V_81 . V_87 ;
V_68 = V_6 -> V_81 . V_92 ;
V_69 = V_93 ;
V_72 = & V_90 ;
break;
}
V_75 = 0 ;
V_76 = 0 ;
V_78 = V_94 . V_95 + V_96 . V_95
+ V_72 -> V_95 + V_97 . V_95
+ V_98 . V_95 ;
if ( V_40 == V_80 ) {
V_78 += V_99 . V_95 ;
V_77 = 6 ;
} else {
V_77 = 5 ;
}
for ( V_70 = ( const struct V_60 * * ) V_67 ;
* V_70 ; ++ V_70 ) {
V_75 += ( * V_70 ) -> V_95 ;
V_78 += ( * V_70 ) -> V_95 ;
V_77 ++ ;
}
for ( V_70 = ( const struct V_60 * * ) V_68 ;
* V_70 ; ++ V_70 ) {
V_76 += ( * V_70 ) -> V_95 ;
V_78 += ( * V_70 ) -> V_95 ;
V_77 ++ ;
}
for ( V_70 = V_69 ; * V_70 ; ++ V_70 ) {
V_78 += ( * V_70 ) -> V_95 ;
V_77 ++ ;
}
V_79 = F_22 ( ( V_77 + 1 ) * sizeof( * V_70 ) + V_78 , V_100 ) ;
if ( V_79 == NULL )
return NULL ;
V_74 = V_79 ;
V_73 = V_79 ;
V_79 += ( V_77 + 1 ) * sizeof( * V_70 ) ;
F_23 ( V_79 , V_73 , & V_94 ) ;
F_23 ( V_79 , V_73 , & V_96 ) ;
V_65 = V_79 ;
F_24 ( V_79 , V_73 ,
( const struct V_60 * * ) V_67 ) ;
V_65 -> V_101 = F_25 ( V_75 ) ;
V_65 -> V_102 = 1 ;
V_65 -> V_103 [ 0 ] = V_6 -> V_33 ;
F_23 ( V_79 , V_73 , V_72 ) ;
if ( V_40 == V_80 )
F_23 ( V_79 , V_73 , & V_99 ) ;
F_23 ( V_79 , V_73 , & V_97 ) ;
F_23 ( V_79 , V_73 , & V_98 ) ;
V_63 = V_79 ;
F_24 ( V_79 , V_73 ,
( const struct V_60 * * ) V_68 ) ;
V_63 -> V_101 = F_25 ( V_76 ) ;
V_63 -> V_104 =
V_105 . V_104 ;
F_24 ( V_79 , V_73 , V_69 ) ;
* V_73 = NULL ;
return V_74 ;
}
static void
F_26 ( struct V_106 * V_107 , struct V_18 * V_19 )
{
struct V_48 * V_26 = V_107 -> V_26 ;
struct V_5 * V_6 = F_4 ( V_19 ) ;
F_5 ( V_26 , L_7 ) ;
if ( V_6 -> V_17 ) {
if ( V_6 -> V_17 -> V_53 == - 1 )
V_57 ( V_6 -> V_17 ) ;
else
F_27 ( V_6 -> V_17 ) ;
V_6 -> V_17 = NULL ;
}
if ( V_6 -> V_108 )
V_6 -> V_108 -> V_109 = NULL ;
if ( V_6 -> V_43 . V_2 )
V_6 -> V_43 . V_2 -> V_109 = NULL ;
if ( V_6 -> V_110 ) {
F_28 ( V_26 -> V_41 -> V_111 , V_6 -> V_110 ) ;
F_29 ( V_6 -> V_112 ) ;
}
F_29 ( V_19 -> V_113 ) ;
F_29 ( V_19 -> V_114 ) ;
F_29 ( V_19 -> V_115 ) ;
F_29 ( V_6 ) ;
}
static int T_1
F_30 ( struct V_106 * V_107 , struct V_18 * V_19 )
{
struct V_48 * V_26 = V_107 -> V_26 ;
struct V_5 * V_6 = F_4 ( V_19 ) ;
struct V_1 * V_2 ;
int V_37 = - V_27 ;
F_5 ( V_26 , L_8 ) ;
if ( V_116 < 1 )
V_116 = 1 ;
if ( V_116 > 16 )
V_116 = 16 ;
if ( V_117 > 2 )
V_117 = 2 ;
if ( V_118 > 15 )
V_118 = 15 ;
V_105 . V_119 = V_120 > 1023 ?
1023 : V_120 ;
V_105 . V_121 = V_116 ;
V_2 = F_31 ( V_26 -> V_41 , & V_90 ) ;
if ( ! V_2 ) {
F_5 ( V_26 , L_9 ) ;
goto error;
}
V_6 -> V_108 = V_2 ;
V_2 -> V_109 = V_6 ;
V_2 = F_31 ( V_26 -> V_41 , & V_105 ) ;
if ( ! V_2 ) {
F_5 ( V_26 , L_10 ) ;
goto error;
}
V_6 -> V_43 . V_2 = V_2 ;
V_2 -> V_109 = V_6 ;
if ( ( V_37 = F_32 ( V_107 , V_19 ) ) < 0 )
goto error;
V_94 . V_122 = V_37 ;
V_96 . V_123 = V_37 ;
V_6 -> V_32 = V_37 ;
if ( ( V_37 = F_32 ( V_107 , V_19 ) ) < 0 )
goto error;
V_98 . V_123 = V_37 ;
V_124 . V_123 = V_37 ;
V_6 -> V_33 = V_37 ;
if ( V_120 > 1024 )
V_120 = 1024 ;
V_19 -> V_113 = F_21 ( V_6 , V_91 ) ;
if ( F_33 ( V_26 -> V_41 ) ) {
V_125 . V_119 = V_120 ;
V_125 . V_119 |= V_117 << 11 ;
V_125 . V_121 = V_116 ;
V_125 . V_104 =
V_105 . V_104 ;
V_19 -> V_114 = F_21 ( V_6 , V_86 ) ;
}
if ( F_34 ( V_107 -> V_26 -> V_41 ) ) {
V_126 . V_119 = V_120 ;
V_126 . V_121 = V_116 ;
V_127 . V_128 = V_117 ;
V_127 . V_129 = V_118 ;
V_127 . V_130 =
V_120 * ( V_117 + 1 ) *
( V_118 + 1 ) ;
V_126 . V_104 =
V_105 . V_104 ;
V_19 -> V_115 = F_21 ( V_6 , V_80 ) ;
}
V_6 -> V_110 = F_35 ( V_26 -> V_41 -> V_111 , V_100 ) ;
V_6 -> V_112 = F_22 ( V_29 , V_100 ) ;
if ( V_6 -> V_110 == NULL || V_6 -> V_112 == NULL ) {
V_37 = - V_50 ;
goto error;
}
V_6 -> V_110 -> V_16 = V_6 -> V_112 ;
V_6 -> V_110 -> V_131 = F_1 ;
V_6 -> V_110 -> V_7 = V_6 ;
if ( ( V_37 = F_16 ( V_19 ) ) < 0 )
goto error;
V_37 = F_36 ( & V_6 -> V_43 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_17 ( V_6 ) ;
if ( V_37 < 0 ) {
F_37 ( V_132 L_11 ) ;
goto error;
}
return 0 ;
error:
F_26 ( V_107 , V_19 ) ;
return V_37 ;
}
int T_1
F_38 ( struct V_106 * V_107 ,
const struct V_66 * const * V_87 ,
const struct V_66 * const * V_82 ,
const struct V_66 * const * V_92 ,
const struct V_66 * const * V_88 ,
const struct V_66 * const * V_83 )
{
struct V_5 * V_6 ;
int V_37 = 0 ;
if ( ! F_33 ( V_107 -> V_26 -> V_41 ) )
return - V_27 ;
V_6 = F_39 ( sizeof( * V_6 ) , V_100 ) ;
if ( V_6 == NULL )
return - V_50 ;
V_6 -> V_34 = V_38 ;
if ( V_87 == NULL || V_87 [ 0 ] == NULL ||
V_87 [ 0 ] -> V_133 != V_134 )
goto error;
if ( V_82 == NULL || V_82 [ 0 ] == NULL ||
V_82 [ 0 ] -> V_133 != V_134 )
goto error;
if ( V_92 == NULL || V_92 [ 0 ] == NULL ||
V_92 [ 0 ] -> V_133 != V_135 )
goto error;
if ( V_88 == NULL || V_88 [ 0 ] == NULL ||
V_88 [ 0 ] -> V_133 != V_135 )
goto error;
if ( V_83 == NULL || V_83 [ 0 ] == NULL ||
V_83 [ 0 ] -> V_133 != V_135 )
goto error;
V_6 -> V_81 . V_87 = V_87 ;
V_6 -> V_81 . V_82 = V_82 ;
V_6 -> V_81 . V_92 = V_92 ;
V_6 -> V_81 . V_88 = V_88 ;
V_6 -> V_81 . V_83 = V_83 ;
if ( V_136 [ V_137 ] . V_138 == 0 ) {
V_37 = F_40 ( V_107 -> V_26 ) ;
if ( V_37 < 0 )
goto error;
V_136 [ V_137 ] . V_138 = V_37 ;
V_94 . V_139 = V_37 ;
V_37 = F_40 ( V_107 -> V_26 ) ;
if ( V_37 < 0 )
goto error;
V_136 [ V_140 ] . V_138 = V_37 ;
V_96 . V_141 = V_37 ;
V_37 = F_40 ( V_107 -> V_26 ) ;
if ( V_37 < 0 )
goto error;
V_136 [ V_142 ] . V_138 = V_37 ;
V_98 . V_141 = V_37 ;
V_124 . V_141 = V_37 ;
}
V_6 -> V_45 . V_58 = L_12 ;
V_6 -> V_45 . V_143 = V_144 ;
V_6 -> V_45 . V_145 = F_30 ;
V_6 -> V_45 . V_146 = F_26 ;
V_6 -> V_45 . V_147 = F_7 ;
V_6 -> V_45 . V_148 = F_8 ;
V_6 -> V_45 . V_149 = F_12 ;
V_6 -> V_45 . V_150 = F_3 ;
V_37 = F_41 ( V_107 , & V_6 -> V_45 ) ;
if ( V_37 )
F_29 ( V_6 ) ;
return V_37 ;
error:
F_29 ( V_6 ) ;
return V_37 ;
}
