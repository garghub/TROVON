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
V_45 -> V_52 = & V_26 -> V_43 -> V_53 ;
V_45 -> V_54 = & V_55 ;
V_45 -> V_56 = V_57 ;
F_21 ( V_45 -> V_58 , V_26 -> V_43 -> V_58 , sizeof( V_45 -> V_58 ) ) ;
V_6 -> V_17 = V_45 ;
F_22 ( V_45 , V_6 ) ;
return F_23 ( V_45 , V_59 , - 1 ) ;
}
static struct V_60 * * T_1
F_24 ( struct V_5 * V_6 , enum V_61 V_42 )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
const struct V_66 * const * V_67 ;
const struct V_66 * const * V_68 ;
const struct V_60 * const * V_69 ;
const struct V_60 * const * V_70 ;
struct V_60 * * V_71 ;
struct V_60 * * V_72 ;
unsigned int V_73 ;
unsigned int V_74 ;
unsigned int V_75 ;
unsigned int V_76 ;
void * V_77 ;
switch ( V_42 ) {
case V_78 :
V_67 = V_6 -> V_79 . V_80 ;
V_68 = V_6 -> V_79 . V_81 ;
V_69 = V_82 ;
break;
case V_83 :
V_67 = V_6 -> V_79 . V_84 ;
V_68 = V_6 -> V_79 . V_85 ;
V_69 = V_86 ;
break;
case V_87 :
default:
V_67 = V_6 -> V_79 . V_84 ;
V_68 = V_6 -> V_79 . V_88 ;
V_69 = V_89 ;
break;
}
V_73 = 0 ;
V_74 = 0 ;
V_76 = V_90 . V_91 + V_92 . V_91
+ V_93 . V_91 + V_94 . V_91
+ V_95 . V_91 ;
if ( V_42 == V_78 ) {
V_76 += V_96 . V_91 ;
V_75 = 6 ;
} else {
V_75 = 5 ;
}
for ( V_70 = ( const struct V_60 * * ) V_67 ;
* V_70 ; ++ V_70 ) {
V_73 += ( * V_70 ) -> V_91 ;
V_76 += ( * V_70 ) -> V_91 ;
V_75 ++ ;
}
for ( V_70 = ( const struct V_60 * * ) V_68 ;
* V_70 ; ++ V_70 ) {
V_74 += ( * V_70 ) -> V_91 ;
V_76 += ( * V_70 ) -> V_91 ;
V_75 ++ ;
}
for ( V_70 = V_69 ; * V_70 ; ++ V_70 ) {
V_76 += ( * V_70 ) -> V_91 ;
V_75 ++ ;
}
V_77 = F_25 ( ( V_75 + 1 ) * sizeof( * V_70 ) + V_76 , V_97 ) ;
if ( V_77 == NULL )
return NULL ;
V_72 = V_77 ;
V_71 = V_77 ;
V_77 += ( V_75 + 1 ) * sizeof( * V_70 ) ;
F_26 ( V_77 , V_71 , & V_90 ) ;
F_26 ( V_77 , V_71 , & V_92 ) ;
V_65 = V_77 ;
F_27 ( V_77 , V_71 ,
( const struct V_60 * * ) V_67 ) ;
V_65 -> V_98 = F_28 ( V_73 ) ;
V_65 -> V_99 = 1 ;
V_65 -> V_100 [ 0 ] = V_6 -> V_35 ;
F_26 ( V_77 , V_71 , & V_93 ) ;
if ( V_42 == V_78 )
F_26 ( V_77 , V_71 , & V_96 ) ;
F_26 ( V_77 , V_71 , & V_94 ) ;
F_26 ( V_77 , V_71 , & V_95 ) ;
V_63 = V_77 ;
F_27 ( V_77 , V_71 ,
( const struct V_60 * * ) V_68 ) ;
V_63 -> V_98 = F_28 ( V_74 ) ;
V_63 -> V_101 = V_6 -> V_45 . V_2 -> V_102 ;
F_27 ( V_77 , V_71 , V_69 ) ;
* V_71 = NULL ;
return V_72 ;
}
static void
F_29 ( struct V_103 * V_104 , struct V_18 * V_19 )
{
struct V_31 * V_26 = V_104 -> V_26 ;
struct V_5 * V_6 = F_4 ( V_19 ) ;
F_5 ( V_26 , L_7 ) ;
F_30 ( V_6 -> V_17 ) ;
V_6 -> V_105 -> V_106 = NULL ;
V_6 -> V_45 . V_2 -> V_106 = NULL ;
V_107 [ V_108 ] . V_109 = 0 ;
F_31 ( V_26 -> V_43 -> V_110 , V_6 -> V_111 ) ;
F_32 ( V_6 -> V_112 ) ;
F_33 ( V_19 ) ;
F_32 ( V_6 ) ;
}
static int T_1
F_34 ( struct V_103 * V_104 , struct V_18 * V_19 )
{
struct V_31 * V_26 = V_104 -> V_26 ;
struct V_5 * V_6 = F_4 ( V_19 ) ;
unsigned int V_113 ;
unsigned int V_114 ;
struct V_1 * V_2 ;
int V_39 = - V_27 ;
F_5 ( V_26 , L_8 ) ;
V_115 = F_35 ( V_115 , 1U , 16U ) ;
V_116 = F_35 ( V_116 , 1U , 3072U ) ;
V_117 = F_36 ( V_117 , 15U ) ;
if ( V_116 <= 1024 ) {
V_113 = 1 ;
V_114 = V_116 ;
} else if ( V_116 <= 2048 ) {
V_113 = 2 ;
V_114 = V_116 / 2 ;
} else {
V_113 = 3 ;
V_114 = V_116 / 3 ;
}
V_118 . V_119 = F_36 ( V_116 , 1023U ) ;
V_118 . V_120 = V_115 ;
V_121 . V_119 = V_114 ;
V_121 . V_119 |= ( ( V_113 - 1 ) << 11 ) ;
V_121 . V_120 = V_115 ;
V_122 . V_119 = V_114 ;
V_122 . V_120 = V_115 ;
V_123 . V_124 = V_113 - 1 ;
V_123 . V_125 = V_117 ;
V_123 . V_126 =
V_114 * V_113 * V_117 ;
V_2 = F_37 ( V_26 -> V_43 , & V_93 ) ;
if ( ! V_2 ) {
F_5 ( V_26 , L_9 ) ;
goto error;
}
V_6 -> V_105 = V_2 ;
V_2 -> V_106 = V_6 ;
if ( F_38 ( V_104 -> V_26 -> V_43 ) )
V_2 = F_39 ( V_26 -> V_43 , & V_122 ,
& V_123 ) ;
else if ( F_40 ( V_26 -> V_43 ) )
V_2 = F_37 ( V_26 -> V_43 , & V_121 ) ;
else
V_2 = F_37 ( V_26 -> V_43 , & V_118 ) ;
if ( ! V_2 ) {
F_5 ( V_26 , L_10 ) ;
goto error;
}
V_6 -> V_45 . V_2 = V_2 ;
V_2 -> V_106 = V_6 ;
V_118 . V_101 = V_6 -> V_45 . V_2 -> V_102 ;
V_121 . V_101 = V_6 -> V_45 . V_2 -> V_102 ;
V_122 . V_101 = V_6 -> V_45 . V_2 -> V_102 ;
if ( ( V_39 = F_41 ( V_104 , V_19 ) ) < 0 )
goto error;
V_90 . V_127 = V_39 ;
V_92 . V_128 = V_39 ;
V_6 -> V_34 = V_39 ;
if ( ( V_39 = F_41 ( V_104 , V_19 ) ) < 0 )
goto error;
V_95 . V_128 = V_39 ;
V_129 . V_128 = V_39 ;
V_6 -> V_35 = V_39 ;
V_19 -> V_130 = F_24 ( V_6 , V_87 ) ;
if ( F_40 ( V_26 -> V_43 ) )
V_19 -> V_131 = F_24 ( V_6 , V_83 ) ;
if ( F_38 ( V_104 -> V_26 -> V_43 ) )
V_19 -> V_132 = F_24 ( V_6 , V_78 ) ;
V_6 -> V_111 = F_42 ( V_26 -> V_43 -> V_110 , V_97 ) ;
V_6 -> V_112 = F_25 ( V_29 , V_97 ) ;
if ( V_6 -> V_111 == NULL || V_6 -> V_112 == NULL ) {
V_39 = - V_51 ;
goto error;
}
V_6 -> V_111 -> V_16 = V_6 -> V_112 ;
V_6 -> V_111 -> V_133 = F_1 ;
V_6 -> V_111 -> V_7 = V_6 ;
if ( ( V_39 = F_18 ( V_19 ) ) < 0 )
goto error;
V_39 = F_43 ( & V_6 -> V_45 ) ;
if ( V_39 < 0 )
goto error;
V_39 = F_19 ( V_6 ) ;
if ( V_39 < 0 ) {
F_44 ( V_134 L_11 ) ;
goto error;
}
return 0 ;
error:
if ( V_6 -> V_17 )
V_57 ( V_6 -> V_17 ) ;
if ( V_6 -> V_105 )
V_6 -> V_105 -> V_106 = NULL ;
if ( V_6 -> V_45 . V_2 )
V_6 -> V_45 . V_2 -> V_106 = NULL ;
if ( V_6 -> V_111 ) {
F_31 ( V_26 -> V_43 -> V_110 , V_6 -> V_111 ) ;
F_32 ( V_6 -> V_112 ) ;
}
F_33 ( V_19 ) ;
return V_39 ;
}
int T_1
F_45 ( struct V_103 * V_104 ,
const struct V_66 * const * V_84 ,
const struct V_66 * const * V_80 ,
const struct V_66 * const * V_88 ,
const struct V_66 * const * V_85 ,
const struct V_66 * const * V_81 )
{
struct V_5 * V_6 ;
int V_39 = 0 ;
if ( ! F_40 ( V_104 -> V_26 -> V_43 ) )
return - V_27 ;
V_6 = F_46 ( sizeof( * V_6 ) , V_97 ) ;
if ( V_6 == NULL )
return - V_51 ;
V_6 -> V_36 = V_40 ;
if ( V_84 == NULL || V_84 [ 0 ] == NULL ||
V_84 [ 0 ] -> V_135 != V_136 )
goto error;
if ( V_80 == NULL || V_80 [ 0 ] == NULL ||
V_80 [ 0 ] -> V_135 != V_136 )
goto error;
if ( V_88 == NULL || V_88 [ 0 ] == NULL ||
V_88 [ 0 ] -> V_135 != V_137 )
goto error;
if ( V_85 == NULL || V_85 [ 0 ] == NULL ||
V_85 [ 0 ] -> V_135 != V_137 )
goto error;
if ( V_81 == NULL || V_81 [ 0 ] == NULL ||
V_81 [ 0 ] -> V_135 != V_137 )
goto error;
V_6 -> V_79 . V_84 = V_84 ;
V_6 -> V_79 . V_80 = V_80 ;
V_6 -> V_79 . V_88 = V_88 ;
V_6 -> V_79 . V_85 = V_85 ;
V_6 -> V_79 . V_81 = V_81 ;
if ( V_107 [ V_108 ] . V_109 == 0 ) {
V_39 = F_47 ( V_104 -> V_26 , V_107 ) ;
if ( V_39 )
goto error;
V_90 . V_138 =
V_107 [ V_108 ] . V_109 ;
V_92 . V_139 =
V_107 [ V_108 ] . V_109 ;
V_39 = V_107 [ V_140 ] . V_109 ;
V_95 . V_139 = V_39 ;
V_129 . V_139 = V_39 ;
}
V_6 -> V_32 . V_58 = L_12 ;
V_6 -> V_32 . V_141 = V_142 ;
V_6 -> V_32 . V_143 = F_34 ;
V_6 -> V_32 . V_144 = F_29 ;
V_6 -> V_32 . V_145 = F_9 ;
V_6 -> V_32 . V_146 = F_10 ;
V_6 -> V_32 . V_147 = F_14 ;
V_6 -> V_32 . V_148 = F_3 ;
V_39 = F_48 ( V_104 , & V_6 -> V_32 ) ;
if ( V_39 )
F_32 ( V_6 ) ;
return V_39 ;
error:
F_32 ( V_6 ) ;
return V_39 ;
}
