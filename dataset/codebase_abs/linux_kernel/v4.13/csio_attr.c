void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_7 V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_8 . V_13 = F_4 ( F_5 ( V_2 ) ) ;
V_8 . V_14 = F_4 ( F_6 ( V_2 ) ) ;
V_8 . V_15 = V_2 -> V_16 ;
V_8 . V_17 = V_18 ;
if ( V_2 -> V_19 & V_20 || V_2 -> V_19 & V_21 ) {
V_10 = V_2 -> V_10 ;
F_7 ( V_10 != NULL ) ;
goto V_22;
}
V_2 -> V_10 = F_8 ( V_6 , 0 , & V_8 ) ;
if ( ! V_2 -> V_10 ) {
F_9 ( V_4 , L_1 ,
V_2 -> V_16 ) ;
return;
}
V_4 -> V_23 ++ ;
V_10 = V_2 -> V_10 ;
F_10 ( V_6 -> V_24 ) ;
* ( (struct V_1 * * ) V_10 -> V_25 ) = V_2 ;
F_11 ( V_6 -> V_24 ) ;
V_12 = & V_2 -> V_26 ;
V_10 -> V_27 = F_12 ( V_12 -> V_28 . V_29 ) ;
if ( F_12 ( V_12 -> V_30 [ 2 ] . V_31 ) & V_32 )
V_10 -> V_33 = V_34 ;
else
V_10 -> V_33 = V_35 ;
V_22:
if ( V_2 -> V_19 & V_20 )
V_8 . V_17 |= V_36 ;
if ( V_2 -> V_19 & V_21 )
V_8 . V_17 |= V_37 ;
if ( V_8 . V_17 != V_18 )
F_13 ( V_10 , V_8 . V_17 ) ;
V_2 -> V_38 = V_10 -> V_39 ;
F_14 ( V_4 , L_2 ,
V_2 -> V_16 , V_8 . V_17 ) ;
}
void
F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
V_2 -> V_19 &= ~ ( V_20 | V_21 ) ;
F_16 ( V_10 ) ;
V_4 -> V_23 -- ;
F_14 ( V_4 , L_3 , V_2 -> V_16 ) ;
}
void
F_17 ( struct V_3 * V_4 , enum V_40 V_41 )
{
switch ( V_41 ) {
case V_42 :
break;
case V_43 :
if ( F_18 ( V_4 ) )
F_19 ( V_4 ) ;
break;
case V_44 :
if ( F_18 ( V_4 ) )
F_19 ( V_4 ) ;
break;
case V_45 :
F_20 ( V_4 ) ;
break;
default:
break;
}
}
void
F_20 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_21 ( V_6 ) = F_4 ( F_22 ( V_4 ) ) ;
F_23 ( V_6 ) = F_4 ( F_24 ( V_4 ) ) ;
F_25 ( V_6 ) = V_34 ;
F_26 ( V_6 ) =
( F_27 ( V_4 ) ) -> V_46 . V_47 ;
F_28 ( V_6 ) = V_48 |
V_49 ;
F_29 ( V_6 ) = F_12 ( V_4 -> V_50 . V_28 . V_29 ) ;
memset ( F_30 ( V_6 ) , 0 ,
sizeof( F_30 ( V_6 ) ) ) ;
F_30 ( V_6 ) [ 7 ] = 1 ;
memset ( F_31 ( V_6 ) , 0 ,
sizeof( F_31 ( V_6 ) ) ) ;
F_31 ( V_6 ) [ 7 ] = 1 ;
}
static void
F_32 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_33 ( V_6 ) ;
struct V_51 * V_52 = F_27 ( V_4 ) ;
F_10 ( & V_52 -> V_53 ) ;
F_34 ( V_6 ) = V_4 -> V_16 ;
F_11 ( & V_52 -> V_53 ) ;
}
static void
F_35 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_33 ( V_6 ) ;
struct V_51 * V_52 = F_27 ( V_4 ) ;
F_10 ( & V_52 -> V_53 ) ;
if ( F_18 ( V_4 ) )
F_36 ( V_6 ) = V_54 ;
else
F_36 ( V_6 ) = V_55 ;
F_11 ( & V_52 -> V_53 ) ;
}
static void
F_37 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_33 ( V_6 ) ;
struct V_51 * V_52 = F_27 ( V_4 ) ;
char V_56 [ 16 ] ;
F_10 ( & V_52 -> V_53 ) ;
F_38 ( V_4 , V_56 ) ;
if ( ! strcmp ( V_56 , L_4 ) )
F_39 ( V_6 ) = V_57 ;
else if ( ! strcmp ( V_56 , L_5 ) )
F_39 ( V_6 ) = V_58 ;
else
F_39 ( V_6 ) = V_59 ;
F_11 ( & V_52 -> V_53 ) ;
}
static void
F_40 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_33 ( V_6 ) ;
struct V_51 * V_52 = F_27 ( V_4 ) ;
F_10 ( & V_52 -> V_53 ) ;
switch ( V_52 -> V_60 [ V_4 -> V_61 ] . V_62 ) {
case V_63 :
F_41 ( V_6 ) = V_49 ;
break;
case V_64 :
F_41 ( V_6 ) = V_48 ;
break;
default:
F_41 ( V_6 ) = V_65 ;
break;
}
F_11 ( & V_52 -> V_53 ) ;
}
static void
F_42 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_33 ( V_6 ) ;
struct V_1 * V_2 = NULL ;
struct V_51 * V_52 = F_27 ( V_4 ) ;
F_10 ( & V_52 -> V_53 ) ;
V_2 = F_43 ( V_4 , V_66 ) ;
if ( V_2 )
F_44 ( V_6 ) = F_4 ( F_5 ( V_2 ) ) ;
else
F_44 ( V_6 ) = 0 ;
F_11 ( & V_52 -> V_53 ) ;
}
static struct V_67 *
F_45 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_33 ( V_6 ) ;
struct V_51 * V_52 = F_27 ( V_4 ) ;
struct V_67 * V_68 = & V_4 -> V_69 ;
struct V_70 V_71 ;
T_1 V_72 ;
memset ( & V_71 , 0 , sizeof( struct V_70 ) ) ;
F_46 ( V_52 , V_4 -> V_61 , & V_71 ) ;
V_68 -> V_73 += ( F_47 ( V_71 . V_74 ) +
F_47 ( V_71 . V_75 ) +
F_47 ( V_71 . V_76 ) +
F_47 ( V_71 . V_77 ) ) ;
V_68 -> V_78 += ( F_47 ( V_71 . V_79 ) +
F_47 ( V_71 . V_80 ) +
F_47 ( V_71 . V_81 ) +
F_47 ( V_71 . V_82 ) ) /
V_83 ;
V_68 -> V_84 += ( F_47 ( V_71 . V_85 ) +
F_47 ( V_71 . V_86 ) +
F_47 ( V_71 . V_87 ) ) ;
V_68 -> V_88 += ( F_47 ( V_71 . V_89 ) +
F_47 ( V_71 . V_90 ) +
F_47 ( V_71 . V_91 ) ) /
V_83 ;
V_68 -> V_92 += F_47 ( V_71 . V_93 ) ;
V_68 -> V_94 += V_4 -> V_95 . V_96 ;
V_68 -> V_97 += V_4 -> V_95 . V_98 ;
V_68 -> V_99 += V_4 -> V_95 . V_100 ;
V_68 -> V_101 += V_4 -> V_95 . V_102 >> 20 ;
V_68 -> V_103 += V_4 -> V_95 . V_104 >> 20 ;
V_68 -> V_105 = V_4 -> V_95 . V_106 ;
V_72 = F_48 ( V_107 ) - V_52 -> V_95 . V_108 ;
F_49 ( V_72 , 1000 ) ;
V_68 -> V_109 = V_72 ;
return V_68 ;
}
static void
F_50 ( struct V_9 * V_10 , T_2 V_110 )
{
if ( V_110 )
V_10 -> V_111 = V_110 ;
else
V_10 -> V_111 = 1 ;
}
static void
F_19 ( struct V_3 * V_4 )
{
struct V_112 * V_112 = V_4 -> V_112 ;
struct V_3 * V_113 = V_4 -> V_113 ;
char V_56 [ 16 ] ;
F_38 ( V_113 , V_56 ) ;
if ( strcmp ( V_56 , L_4 ) ) {
F_51 ( V_112 , V_114 ) ;
return;
}
if ( ! ( V_113 -> V_115 & V_116 ) ) {
F_51 ( V_112 , V_117 ) ;
return;
}
F_38 ( V_4 , V_56 ) ;
if ( strcmp ( V_56 , L_4 ) ) {
F_51 ( V_112 , V_114 ) ;
return;
}
F_51 ( V_112 , V_118 ) ;
}
static int
F_52 ( struct V_51 * V_52 , struct V_3 * V_4 )
{
struct V_3 * V_113 ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
int V_123 = 0 ;
int V_124 = 0 ;
F_10 ( & V_52 -> V_53 ) ;
V_120 = F_53 ( V_52 -> V_125 , V_126 ) ;
if ( ! V_120 ) {
F_54 ( V_52 , V_127 ) ;
V_123 = - V_128 ;
goto V_129;
}
V_113 = V_4 -> V_113 ;
V_4 -> V_130 = V_113 -> V_130 ;
V_4 -> V_61 = V_113 -> V_61 ;
F_55 ( V_4 , V_120 , V_131 ,
V_113 -> V_130 , V_113 -> V_132 , 0 ,
F_22 ( V_4 ) , F_24 ( V_4 ) , NULL ) ;
for ( V_124 = 0 ; V_124 < 3 ; V_124 ++ ) {
V_123 = F_56 ( V_52 , V_120 ) ;
if ( V_123 != - V_133 )
break;
F_11 ( & V_52 -> V_53 ) ;
F_57 ( 2000 ) ;
F_10 ( & V_52 -> V_53 ) ;
}
if ( V_123 ) {
F_9 ( V_4 , L_6 ) ;
goto V_134;
}
V_122 = (struct V_121 * ) ( V_120 -> V_135 ) ;
if ( F_58 ( F_59 ( V_122 -> V_136 ) ) != V_137 ) {
F_9 ( V_4 , L_7 ,
F_58 ( F_59 ( V_122 -> V_136 ) ) ) ;
V_123 = - V_138 ;
goto V_134;
}
V_4 -> V_132 = F_60 (
F_59 ( V_122 -> V_139 ) ) ;
memcpy ( F_22 ( V_4 ) , V_122 -> V_140 , 8 ) ;
memcpy ( F_24 ( V_4 ) , V_122 -> V_141 , 8 ) ;
F_14 ( V_4 , L_8 , V_4 -> V_132 ) ;
F_14 ( V_4 , L_9 ,
V_4 -> V_50 . V_142 [ 0 ] , V_4 -> V_50 . V_142 [ 1 ] ,
V_4 -> V_50 . V_142 [ 2 ] , V_4 -> V_50 . V_142 [ 3 ] ,
V_4 -> V_50 . V_142 [ 4 ] , V_4 -> V_50 . V_142 [ 5 ] ,
V_4 -> V_50 . V_142 [ 6 ] , V_4 -> V_50 . V_142 [ 7 ] ) ;
F_14 ( V_4 , L_10 ,
V_4 -> V_50 . V_143 [ 0 ] , V_4 -> V_50 . V_143 [ 1 ] ,
V_4 -> V_50 . V_143 [ 2 ] , V_4 -> V_50 . V_143 [ 3 ] ,
V_4 -> V_50 . V_143 [ 4 ] , V_4 -> V_50 . V_143 [ 5 ] ,
V_4 -> V_50 . V_143 [ 6 ] , V_4 -> V_50 . V_143 [ 7 ] ) ;
V_134:
F_61 ( V_120 , V_52 -> V_125 ) ;
V_129:
F_11 ( & V_52 -> V_53 ) ;
return V_123 ;
}
static int
F_62 ( struct V_51 * V_52 , struct V_3 * V_4 )
{
struct V_3 * V_113 ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
int V_123 = 0 ;
int V_124 = 0 ;
F_10 ( & V_52 -> V_53 ) ;
V_120 = F_53 ( V_52 -> V_125 , V_126 ) ;
if ( ! V_120 ) {
F_54 ( V_52 , V_127 ) ;
V_123 = - V_128 ;
goto V_129;
}
V_113 = V_4 -> V_113 ;
F_63 ( V_4 , V_120 , V_131 ,
V_4 -> V_130 , V_4 -> V_132 ,
NULL ) ;
for ( V_124 = 0 ; V_124 < 3 ; V_124 ++ ) {
V_123 = F_56 ( V_52 , V_120 ) ;
if ( V_123 != - V_133 )
break;
F_11 ( & V_52 -> V_53 ) ;
F_57 ( 2000 ) ;
F_10 ( & V_52 -> V_53 ) ;
}
if ( V_123 ) {
F_9 ( V_4 , L_6 ) ;
goto V_134;
}
V_122 = (struct V_121 * ) ( V_120 -> V_135 ) ;
if ( F_58 ( F_59 ( V_122 -> V_136 ) ) != V_137 ) {
F_9 ( V_4 , L_11 ,
F_58 ( F_59 ( V_122 -> V_136 ) ) ) ;
V_123 = - V_138 ;
}
V_134:
F_61 ( V_120 , V_52 -> V_125 ) ;
V_129:
F_11 ( & V_52 -> V_53 ) ;
return V_123 ;
}
static int
F_64 ( struct V_112 * V_112 , bool V_144 )
{
struct V_5 * V_6 = V_112 -> V_6 ;
struct V_3 * V_113 = F_33 ( V_6 ) ;
struct V_3 * V_4 = NULL ;
struct V_51 * V_52 = F_27 ( V_113 ) ;
T_3 V_145 [ 8 ] ;
int V_123 = - 1 ;
V_4 = F_65 ( V_52 , & V_112 -> V_146 , false , V_113 ) ;
if ( ! V_4 )
goto error;
if ( V_112 -> V_13 != 0 ) {
F_66 ( V_112 -> V_13 , V_145 ) ;
if ( ! F_67 ( V_145 ) ) {
F_9 ( V_4 ,
L_12 ) ;
goto error;
}
memcpy ( F_22 ( V_4 ) , V_145 , 8 ) ;
}
if ( V_112 -> V_14 != 0 ) {
F_66 ( V_112 -> V_14 , V_145 ) ;
if ( ! F_67 ( V_145 ) ) {
F_9 ( V_4 ,
L_13 ) ;
goto error;
}
if ( F_68 ( V_52 , V_145 ) ) {
F_9 ( V_4 ,
L_14 ) ;
goto error;
}
memcpy ( F_24 ( V_4 ) , V_145 , 8 ) ;
}
F_51 ( V_112 , V_147 ) ;
if ( F_52 ( V_52 , V_4 ) )
goto error;
* (struct V_3 * * ) V_112 -> V_25 = V_4 ;
V_4 -> V_112 = V_112 ;
if ( ! V_112 -> V_13 )
V_112 -> V_13 = F_4 ( F_22 ( V_4 ) ) ;
if ( ! V_112 -> V_14 )
V_112 -> V_14 = F_4 ( F_24 ( V_4 ) ) ;
F_20 ( V_4 ) ;
return 0 ;
error:
if ( V_4 )
F_69 ( V_4 ) ;
return V_123 ;
}
static int
F_70 ( struct V_112 * V_112 )
{
struct V_3 * V_4 = * (struct V_3 * * ) V_112 -> V_25 ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_51 * V_52 = F_27 ( V_4 ) ;
int V_148 ;
F_10 ( & V_52 -> V_53 ) ;
V_148 = F_71 ( V_52 ) ;
F_11 ( & V_52 -> V_53 ) ;
if ( V_148 ) {
F_69 ( V_4 ) ;
return 0 ;
}
F_72 ( V_6 ) ;
F_10 ( & V_52 -> V_53 ) ;
F_73 ( F_74 ( V_52 ) , V_4 ) ;
F_75 ( V_4 ) ;
F_11 ( & V_52 -> V_53 ) ;
F_76 ( V_6 ) ;
if ( V_112 -> V_149 != V_150 )
F_62 ( V_52 , V_4 ) ;
F_69 ( V_4 ) ;
return 0 ;
}
static int
F_77 ( struct V_112 * V_112 , bool V_144 )
{
struct V_3 * V_4 = * (struct V_3 * * ) V_112 -> V_25 ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_51 * V_52 = F_27 ( V_4 ) ;
if ( V_144 ) {
F_72 ( V_6 ) ;
F_10 ( & V_52 -> V_53 ) ;
F_73 ( F_74 ( V_52 ) , V_4 ) ;
F_78 ( V_4 ) ;
F_11 ( & V_52 -> V_53 ) ;
F_76 ( V_6 ) ;
F_62 ( V_52 , V_4 ) ;
F_51 ( V_112 , V_150 ) ;
F_9 ( V_4 , L_15 ) ;
return 0 ;
} else {
F_51 ( V_112 , V_147 ) ;
if ( F_52 ( V_52 , V_4 ) ) {
F_9 ( V_4 , L_16 ) ;
return - 1 ;
}
F_9 ( V_4 , L_17 ) ;
return 0 ;
}
}
static void
F_79 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
struct V_51 * V_52 ;
struct V_3 * V_4 ;
V_2 = * ( (struct V_1 * * ) V_10 -> V_25 ) ;
V_4 = F_2 ( V_2 ) ;
V_52 = F_27 ( V_4 ) ;
F_10 ( & V_52 -> V_53 ) ;
if ( F_71 ( V_52 ) || F_80 ( V_2 ) )
goto V_129;
F_14 ( V_4 , L_18 ,
V_2 , V_2 -> V_16 , F_81 ( V_2 ) ) ;
F_54 ( V_4 , V_151 ) ;
if ( F_82 ( V_52 , V_152 , & V_2 , sizeof( V_2 ) ) ) {
F_54 ( V_52 , V_153 ) ;
goto V_129;
}
if ( ! ( V_52 -> V_115 & V_154 ) ) {
V_52 -> V_115 |= V_154 ;
F_11 ( & V_52 -> V_53 ) ;
F_83 ( & V_52 -> V_155 ) ;
return;
}
V_129:
F_11 ( & V_52 -> V_53 ) ;
}
