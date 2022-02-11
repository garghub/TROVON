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
void F_7 ( struct V_5 * V_6 )
{
struct V_31 * V_26 = V_6 -> V_32 . V_25 -> V_26 ;
F_8 ( V_26 ) ;
}
static int
F_9 ( struct V_18 * V_19 , unsigned V_33 )
{
struct V_5 * V_6 = F_4 ( V_19 ) ;
F_5 ( V_19 -> V_25 -> V_26 , L_2 , V_33 ) ;
if ( V_33 == V_6 -> V_34 )
return 0 ;
else if ( V_33 != V_6 -> V_35 )
return - V_27 ;
else
return V_6 -> V_36 == V_37 ? 1 : 0 ;
}
static int
F_10 ( struct V_18 * V_19 , unsigned V_33 , unsigned V_38 )
{
struct V_5 * V_6 = F_4 ( V_19 ) ;
struct V_8 V_8 ;
struct V_9 * V_9 = ( void * ) & V_8 . V_10 . V_11 ;
int V_39 ;
F_5 ( V_19 -> V_25 -> V_26 , L_3 , V_33 , V_38 ) ;
if ( V_33 == V_6 -> V_34 ) {
if ( V_38 )
return - V_27 ;
if ( V_6 -> V_36 == V_40 ) {
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_41 ;
V_9 -> V_42 = V_19 -> V_25 -> V_26 -> V_43 -> V_42 ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
V_6 -> V_36 = V_44 ;
}
return 0 ;
}
if ( V_33 != V_6 -> V_35 )
return - V_27 ;
switch ( V_38 ) {
case 0 :
if ( V_6 -> V_36 != V_37 )
return 0 ;
if ( V_6 -> V_45 . V_2 )
F_11 ( V_6 -> V_45 . V_2 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_46 ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
V_6 -> V_36 = V_44 ;
return 0 ;
case 1 :
if ( V_6 -> V_36 != V_44 )
return 0 ;
if ( V_6 -> V_45 . V_2 ) {
V_39 = F_12 ( V_19 -> V_25 -> V_26 -> V_43 ,
& ( V_6 -> V_32 ) , V_6 -> V_45 . V_2 ) ;
if ( V_39 )
return V_39 ;
F_13 ( V_6 -> V_45 . V_2 ) ;
}
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_47 ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
return V_48 ;
default:
return - V_27 ;
}
}
static void
F_14 ( struct V_18 * V_19 )
{
struct V_5 * V_6 = F_4 ( V_19 ) ;
struct V_8 V_8 ;
F_5 ( V_19 -> V_25 -> V_26 , L_4 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . type = V_49 ;
F_2 ( V_6 -> V_17 , & V_8 ) ;
V_6 -> V_36 = V_40 ;
}
void
F_15 ( struct V_5 * V_6 )
{
struct V_31 * V_26 = V_6 -> V_32 . V_25 -> V_26 ;
int V_39 ;
if ( ( V_39 = F_16 ( & V_6 -> V_32 ) ) < 0 )
F_5 ( V_26 , L_5 , V_39 ) ;
}
void
F_17 ( struct V_5 * V_6 )
{
struct V_31 * V_26 = V_6 -> V_32 . V_25 -> V_26 ;
int V_39 ;
if ( ( V_39 = F_18 ( & V_6 -> V_32 ) ) < 0 )
F_5 ( V_26 , L_6 , V_39 ) ;
}
static int
F_19 ( struct V_5 * V_6 )
{
struct V_31 * V_26 = V_6 -> V_32 . V_25 -> V_26 ;
struct V_50 * V_45 ;
V_45 = F_20 () ;
if ( V_45 == NULL )
return - V_51 ;
V_45 -> V_52 = & V_6 -> V_52 ;
V_45 -> V_53 = & V_54 ;
V_45 -> V_55 = V_56 ;
F_21 ( V_45 -> V_57 , V_26 -> V_43 -> V_57 , sizeof( V_45 -> V_57 ) ) ;
V_6 -> V_17 = V_45 ;
F_22 ( V_45 , V_6 ) ;
return F_23 ( V_45 , V_58 , - 1 ) ;
}
static struct V_59 * * T_1
F_24 ( struct V_5 * V_6 , enum V_60 V_42 )
{
struct V_61 * V_62 ;
struct V_63 * V_64 ;
const struct V_65 * const * V_66 ;
const struct V_65 * const * V_67 ;
const struct V_59 * const * V_68 ;
const struct V_59 * const * V_69 ;
struct V_59 * * V_70 ;
struct V_59 * * V_71 ;
unsigned int V_72 ;
unsigned int V_73 ;
unsigned int V_74 ;
unsigned int V_75 ;
void * V_76 ;
switch ( V_42 ) {
case V_77 :
V_66 = V_6 -> V_78 . V_79 ;
V_67 = V_6 -> V_78 . V_80 ;
V_68 = V_81 ;
break;
case V_82 :
V_66 = V_6 -> V_78 . V_83 ;
V_67 = V_6 -> V_78 . V_84 ;
V_68 = V_85 ;
break;
case V_86 :
default:
V_66 = V_6 -> V_78 . V_83 ;
V_67 = V_6 -> V_78 . V_87 ;
V_68 = V_88 ;
break;
}
V_72 = 0 ;
V_73 = 0 ;
V_75 = V_89 . V_90 + V_91 . V_90
+ V_92 . V_90 + V_93 . V_90
+ V_94 . V_90 ;
if ( V_42 == V_77 ) {
V_75 += V_95 . V_90 ;
V_74 = 6 ;
} else {
V_74 = 5 ;
}
for ( V_69 = ( const struct V_59 * * ) V_66 ;
* V_69 ; ++ V_69 ) {
V_72 += ( * V_69 ) -> V_90 ;
V_75 += ( * V_69 ) -> V_90 ;
V_74 ++ ;
}
for ( V_69 = ( const struct V_59 * * ) V_67 ;
* V_69 ; ++ V_69 ) {
V_73 += ( * V_69 ) -> V_90 ;
V_75 += ( * V_69 ) -> V_90 ;
V_74 ++ ;
}
for ( V_69 = V_68 ; * V_69 ; ++ V_69 ) {
V_75 += ( * V_69 ) -> V_90 ;
V_74 ++ ;
}
V_76 = F_25 ( ( V_74 + 1 ) * sizeof( * V_69 ) + V_75 , V_96 ) ;
if ( V_76 == NULL )
return NULL ;
V_71 = V_76 ;
V_70 = V_76 ;
V_76 += ( V_74 + 1 ) * sizeof( * V_69 ) ;
F_26 ( V_76 , V_70 , & V_89 ) ;
F_26 ( V_76 , V_70 , & V_91 ) ;
V_64 = V_76 ;
F_27 ( V_76 , V_70 ,
( const struct V_59 * * ) V_66 ) ;
V_64 -> V_97 = F_28 ( V_72 ) ;
V_64 -> V_98 = 1 ;
V_64 -> V_99 [ 0 ] = V_6 -> V_35 ;
F_26 ( V_76 , V_70 , & V_92 ) ;
if ( V_42 == V_77 )
F_26 ( V_76 , V_70 , & V_95 ) ;
F_26 ( V_76 , V_70 , & V_93 ) ;
F_26 ( V_76 , V_70 , & V_94 ) ;
V_62 = V_76 ;
F_27 ( V_76 , V_70 ,
( const struct V_59 * * ) V_67 ) ;
V_62 -> V_97 = F_28 ( V_73 ) ;
V_62 -> V_100 = V_6 -> V_45 . V_2 -> V_101 ;
F_27 ( V_76 , V_70 , V_68 ) ;
* V_70 = NULL ;
return V_71 ;
}
static void
F_29 ( struct V_102 * V_103 , struct V_18 * V_19 )
{
struct V_31 * V_26 = V_103 -> V_26 ;
struct V_5 * V_6 = F_4 ( V_19 ) ;
F_5 ( V_26 , L_7 ) ;
F_30 ( V_6 -> V_17 ) ;
F_31 ( & V_6 -> V_52 ) ;
V_6 -> V_104 -> V_105 = NULL ;
V_6 -> V_45 . V_2 -> V_105 = NULL ;
V_106 [ V_107 ] . V_108 = 0 ;
F_32 ( V_26 -> V_43 -> V_109 , V_6 -> V_110 ) ;
F_33 ( V_6 -> V_111 ) ;
F_34 ( V_19 ) ;
F_33 ( V_6 ) ;
}
static int T_1
F_35 ( struct V_102 * V_103 , struct V_18 * V_19 )
{
struct V_31 * V_26 = V_103 -> V_26 ;
struct V_5 * V_6 = F_4 ( V_19 ) ;
unsigned int V_112 ;
unsigned int V_113 ;
struct V_1 * V_2 ;
int V_39 = - V_27 ;
F_5 ( V_26 , L_8 ) ;
V_114 = F_36 ( V_114 , 1U , 16U ) ;
V_115 = F_36 ( V_115 , 1U , 3072U ) ;
V_116 = F_37 ( V_116 , 15U ) ;
if ( V_115 <= 1024 ) {
V_112 = 1 ;
V_113 = V_115 ;
} else if ( V_115 <= 2048 ) {
V_112 = 2 ;
V_113 = V_115 / 2 ;
} else {
V_112 = 3 ;
V_113 = V_115 / 3 ;
}
V_117 . V_118 = F_37 ( V_115 , 1023U ) ;
V_117 . V_119 = V_114 ;
V_120 . V_118 = V_113 ;
V_120 . V_118 |= ( ( V_112 - 1 ) << 11 ) ;
V_120 . V_119 = V_114 ;
V_121 . V_118 = V_113 ;
V_121 . V_119 = V_114 ;
V_122 . V_123 = V_112 - 1 ;
V_122 . V_124 = V_116 ;
V_122 . V_125 =
V_113 * V_112 * V_116 ;
V_2 = F_38 ( V_26 -> V_43 , & V_92 ) ;
if ( ! V_2 ) {
F_5 ( V_26 , L_9 ) ;
goto error;
}
V_6 -> V_104 = V_2 ;
V_2 -> V_105 = V_6 ;
if ( F_39 ( V_103 -> V_26 -> V_43 ) )
V_2 = F_40 ( V_26 -> V_43 , & V_121 ,
& V_122 ) ;
else if ( F_41 ( V_26 -> V_43 ) )
V_2 = F_38 ( V_26 -> V_43 , & V_120 ) ;
else
V_2 = F_38 ( V_26 -> V_43 , & V_117 ) ;
if ( ! V_2 ) {
F_5 ( V_26 , L_10 ) ;
goto error;
}
V_6 -> V_45 . V_2 = V_2 ;
V_2 -> V_105 = V_6 ;
V_117 . V_100 = V_6 -> V_45 . V_2 -> V_101 ;
V_120 . V_100 = V_6 -> V_45 . V_2 -> V_101 ;
V_121 . V_100 = V_6 -> V_45 . V_2 -> V_101 ;
if ( ( V_39 = F_42 ( V_103 , V_19 ) ) < 0 )
goto error;
V_89 . V_126 = V_39 ;
V_91 . V_127 = V_39 ;
V_6 -> V_34 = V_39 ;
if ( ( V_39 = F_42 ( V_103 , V_19 ) ) < 0 )
goto error;
V_94 . V_127 = V_39 ;
V_128 . V_127 = V_39 ;
V_6 -> V_35 = V_39 ;
V_19 -> V_129 = F_24 ( V_6 , V_86 ) ;
if ( F_41 ( V_26 -> V_43 ) )
V_19 -> V_130 = F_24 ( V_6 , V_82 ) ;
if ( F_39 ( V_103 -> V_26 -> V_43 ) )
V_19 -> V_131 = F_24 ( V_6 , V_77 ) ;
V_6 -> V_110 = F_43 ( V_26 -> V_43 -> V_109 , V_96 ) ;
V_6 -> V_111 = F_25 ( V_29 , V_96 ) ;
if ( V_6 -> V_110 == NULL || V_6 -> V_111 == NULL ) {
V_39 = - V_51 ;
goto error;
}
V_6 -> V_110 -> V_16 = V_6 -> V_111 ;
V_6 -> V_110 -> V_132 = F_1 ;
V_6 -> V_110 -> V_7 = V_6 ;
if ( ( V_39 = F_18 ( V_19 ) ) < 0 )
goto error;
if ( F_44 ( & V_26 -> V_43 -> V_133 , & V_6 -> V_52 ) ) {
F_45 ( V_134 L_11 ) ;
goto error;
}
V_39 = F_46 ( & V_6 -> V_45 ) ;
if ( V_39 < 0 )
goto error;
V_39 = F_19 ( V_6 ) ;
if ( V_39 < 0 ) {
F_45 ( V_134 L_12 ) ;
goto error;
}
return 0 ;
error:
F_31 ( & V_6 -> V_52 ) ;
if ( V_6 -> V_17 )
V_56 ( V_6 -> V_17 ) ;
if ( V_6 -> V_104 )
V_6 -> V_104 -> V_105 = NULL ;
if ( V_6 -> V_45 . V_2 )
V_6 -> V_45 . V_2 -> V_105 = NULL ;
if ( V_6 -> V_110 ) {
F_32 ( V_26 -> V_43 -> V_109 , V_6 -> V_110 ) ;
F_33 ( V_6 -> V_111 ) ;
}
F_34 ( V_19 ) ;
return V_39 ;
}
int T_1
F_47 ( struct V_102 * V_103 ,
const struct V_65 * const * V_83 ,
const struct V_65 * const * V_79 ,
const struct V_65 * const * V_87 ,
const struct V_65 * const * V_84 ,
const struct V_65 * const * V_80 )
{
struct V_5 * V_6 ;
int V_39 = 0 ;
if ( ! F_41 ( V_103 -> V_26 -> V_43 ) )
return - V_27 ;
V_6 = F_48 ( sizeof( * V_6 ) , V_96 ) ;
if ( V_6 == NULL )
return - V_51 ;
V_6 -> V_36 = V_40 ;
if ( V_83 == NULL || V_83 [ 0 ] == NULL ||
V_83 [ 0 ] -> V_135 != V_136 )
goto error;
if ( V_79 == NULL || V_79 [ 0 ] == NULL ||
V_79 [ 0 ] -> V_135 != V_136 )
goto error;
if ( V_87 == NULL || V_87 [ 0 ] == NULL ||
V_87 [ 0 ] -> V_135 != V_137 )
goto error;
if ( V_84 == NULL || V_84 [ 0 ] == NULL ||
V_84 [ 0 ] -> V_135 != V_137 )
goto error;
if ( V_80 == NULL || V_80 [ 0 ] == NULL ||
V_80 [ 0 ] -> V_135 != V_137 )
goto error;
V_6 -> V_78 . V_83 = V_83 ;
V_6 -> V_78 . V_79 = V_79 ;
V_6 -> V_78 . V_87 = V_87 ;
V_6 -> V_78 . V_84 = V_84 ;
V_6 -> V_78 . V_80 = V_80 ;
if ( V_106 [ V_107 ] . V_108 == 0 ) {
V_39 = F_49 ( V_103 -> V_26 , V_106 ) ;
if ( V_39 )
goto error;
V_89 . V_138 =
V_106 [ V_107 ] . V_108 ;
V_91 . V_139 =
V_106 [ V_107 ] . V_108 ;
V_39 = V_106 [ V_140 ] . V_108 ;
V_94 . V_139 = V_39 ;
V_128 . V_139 = V_39 ;
}
V_6 -> V_32 . V_57 = L_13 ;
V_6 -> V_32 . V_141 = V_142 ;
V_6 -> V_32 . V_143 = F_35 ;
V_6 -> V_32 . V_144 = F_29 ;
V_6 -> V_32 . V_145 = F_9 ;
V_6 -> V_32 . V_146 = F_10 ;
V_6 -> V_32 . V_147 = F_14 ;
V_6 -> V_32 . V_148 = F_3 ;
V_39 = F_50 ( V_103 , & V_6 -> V_32 ) ;
if ( V_39 )
F_33 ( V_6 ) ;
return V_39 ;
error:
F_33 ( V_6 ) ;
return V_39 ;
}
