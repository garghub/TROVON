static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
F_3 ( V_4 ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
return V_6 -> V_7 ? sizeof ( struct V_8 ) :
sizeof ( struct V_9 ) ;
}
static struct V_10 * F_5 ( struct V_5 * V_6 , int V_11 )
{
return V_6 -> V_12 ? NULL : V_6 -> V_13 [ V_11 ] ;
}
static int F_6 ( struct V_5 * V_6 ,
struct V_10 * V_13 ,
struct V_14 * V_15 )
{
int V_16 = 1 ;
F_7 ( & V_6 -> V_17 ) ;
for ( V_15 -> V_18 . V_19 . V_11 = 0 ;
V_15 -> V_18 . V_19 . V_11 < V_20 ;
V_15 -> V_18 . V_19 . V_11 ++ )
if ( V_13 == F_5 ( V_6 , V_15 -> V_18 . V_19 . V_11 ) ) {
F_8 ( & V_15 -> V_21 , & V_6 -> V_22 ) ;
F_9 ( & V_6 -> V_23 ) ;
V_16 = 0 ;
break;
}
F_10 ( & V_6 -> V_17 ) ;
return V_16 ;
}
static void F_11 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
F_12 ( & V_6 -> V_24 ) ;
F_13 ( & V_15 -> V_21 ) ;
F_14 ( & V_6 -> V_24 ) ;
}
static void F_15 ( struct V_10 * V_13 ,
struct V_25 * V_26 )
{
struct V_5 * V_6 = V_13 -> V_27 ;
struct V_14 * V_15 = V_26 -> V_28 -> V_27 [ 0 ] ;
F_11 ( V_6 , V_15 ) ;
F_16 ( V_15 -> V_29 -> V_30 ) ;
F_17 ( V_15 -> V_29 ) ;
if ( V_26 -> V_31 == V_32 ) {
V_15 -> V_33 = V_34 ;
V_15 -> V_18 . V_19 . V_31 = V_35 ;
if ( ! F_6 ( V_6 , V_13 , V_15 ) )
return;
}
F_3 ( V_15 ) ;
}
static void F_18 ( struct V_10 * V_13 ,
struct V_36 * V_28 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = V_13 -> V_27 ;
struct V_14 * V_15 ;
if ( V_38 -> V_39 -> V_31 != V_40 )
goto V_41;
V_15 = F_19 ( sizeof *V_15 , V_42 ) ;
if ( ! V_15 )
goto V_41;
V_15 -> V_33 = V_38 -> V_43 ;
V_15 -> V_44 = V_38 ;
V_15 -> V_18 . V_19 . V_31 = 0 ;
V_15 -> V_18 . V_19 . V_33 = F_4 ( V_6 ) + V_38 -> V_43 ;
V_15 -> V_18 . V_19 . V_45 = F_20 ( V_38 -> V_39 -> V_46 ) ;
V_15 -> V_18 . V_19 . V_47 = F_21 ( V_38 -> V_39 -> V_48 ) ;
V_15 -> V_18 . V_19 . V_49 = V_38 -> V_39 -> V_49 ;
V_15 -> V_18 . V_19 . V_50 = V_38 -> V_39 -> V_51 ;
V_15 -> V_18 . V_19 . V_52 = V_38 -> V_39 -> V_52 ;
V_15 -> V_18 . V_19 . V_53 = ! ! ( V_38 -> V_39 -> V_54 & V_55 ) ;
if ( V_15 -> V_18 . V_19 . V_53 ) {
struct V_56 V_57 ;
const struct V_58 * V_59 ;
F_22 ( V_13 -> V_60 , V_13 -> V_61 ,
V_38 -> V_39 , V_38 -> V_62 . V_59 ,
& V_57 ) ;
V_59 = F_23 ( & V_57 ) ;
V_15 -> V_18 . V_19 . V_63 = V_59 -> V_64 ;
V_15 -> V_18 . V_19 . V_65 = V_59 -> V_65 ;
V_15 -> V_18 . V_19 . V_66 = V_59 -> V_66 ;
memcpy ( V_15 -> V_18 . V_19 . V_67 , & V_59 -> V_68 , 16 ) ;
V_15 -> V_18 . V_19 . V_69 = F_20 ( V_59 -> V_69 ) ;
}
if ( F_6 ( V_6 , V_13 , V_15 ) )
goto V_70;
return;
V_70:
F_3 ( V_15 ) ;
V_41:
F_24 ( V_38 ) ;
}
static T_1 F_25 ( struct V_5 * V_6 , char T_2 * V_71 ,
struct V_14 * V_15 , T_3 V_72 )
{
struct V_73 * V_62 ;
int V_74 , V_75 , V_76 , V_77 ;
T_3 V_78 ;
V_62 = & V_15 -> V_44 -> V_62 ;
V_78 = V_15 -> V_44 -> V_79 ;
if ( ( V_15 -> V_33 <= V_78 &&
V_72 < F_4 ( V_6 ) + V_15 -> V_33 ) ||
( V_15 -> V_33 > V_78 &&
V_72 < F_4 ( V_6 ) + V_78 ) )
return - V_80 ;
if ( F_26 ( V_71 , & V_15 -> V_18 , F_4 ( V_6 ) ) )
return - V_81 ;
V_71 += F_4 ( V_6 ) ;
V_75 = F_27 ( int , V_15 -> V_33 , V_78 ) ;
if ( F_26 ( V_71 , V_62 -> V_18 , V_75 ) )
return - V_81 ;
if ( V_75 < V_15 -> V_33 ) {
if ( V_72 < F_4 ( V_6 ) + V_15 -> V_33 ) {
return - V_82 ;
}
V_76 = F_28 ( V_62 -> V_18 -> V_83 . V_84 ) ;
V_77 = V_78 - V_76 ;
for ( V_74 = V_15 -> V_33 - V_75 , V_71 += V_75 ;
V_74 ; V_74 -= V_75 , V_71 += V_75 ) {
V_62 = F_2 ( V_62 -> V_21 . V_85 ,
struct V_73 , V_21 ) ;
V_75 = F_29 ( V_74 , V_77 ) ;
if ( F_26 ( V_71 , ( ( void * ) V_62 -> V_18 ) + V_76 ,
V_75 ) )
return - V_81 ;
}
}
return F_4 ( V_6 ) + V_15 -> V_33 ;
}
static T_1 F_30 ( struct V_5 * V_6 , char T_2 * V_71 ,
struct V_14 * V_15 , T_3 V_72 )
{
T_1 V_86 = F_4 ( V_6 ) + V_15 -> V_33 ;
if ( V_72 < V_86 )
return - V_80 ;
if ( F_26 ( V_71 , & V_15 -> V_18 , F_4 ( V_6 ) ) )
return - V_81 ;
V_71 += F_4 ( V_6 ) ;
if ( F_26 ( V_71 , V_15 -> V_18 . V_87 , V_15 -> V_33 ) )
return - V_81 ;
return V_86 ;
}
static T_1 F_31 ( struct V_6 * V_88 , char T_2 * V_71 ,
T_3 V_72 , T_4 * V_89 )
{
struct V_5 * V_6 = V_88 -> V_90 ;
struct V_14 * V_15 ;
T_1 V_16 ;
if ( V_72 < F_4 ( V_6 ) )
return - V_80 ;
F_7 ( & V_6 -> V_17 ) ;
while ( F_32 ( & V_6 -> V_22 ) ) {
F_10 ( & V_6 -> V_17 ) ;
if ( V_88 -> V_91 & V_92 )
return - V_93 ;
if ( F_33 ( V_6 -> V_23 ,
! F_32 ( & V_6 -> V_22 ) ) )
return - V_94 ;
F_7 ( & V_6 -> V_17 ) ;
}
V_15 = F_34 ( V_6 -> V_22 . V_85 , struct V_14 , V_21 ) ;
F_13 ( & V_15 -> V_21 ) ;
F_10 ( & V_6 -> V_17 ) ;
if ( V_15 -> V_44 )
V_16 = F_25 ( V_6 , V_71 , V_15 , V_72 ) ;
else
V_16 = F_30 ( V_6 , V_71 , V_15 , V_72 ) ;
if ( V_16 < 0 ) {
F_7 ( & V_6 -> V_17 ) ;
F_35 ( & V_15 -> V_21 , & V_6 -> V_22 ) ;
F_10 ( & V_6 -> V_17 ) ;
} else {
if ( V_15 -> V_44 )
F_24 ( V_15 -> V_44 ) ;
F_3 ( V_15 ) ;
}
return V_16 ;
}
static int F_36 ( struct V_36 * V_29 , const char T_2 * V_71 )
{
int V_74 , V_95 ;
if ( ( V_29 -> V_96 > V_97 ) &&
F_37 ( V_29 -> V_18 + V_97 , V_71 + V_97 ,
V_29 -> V_96 - V_97 ) )
return - V_81 ;
for ( V_95 = 1 , V_74 = V_29 -> V_98 , V_71 += V_29 -> V_96 ; V_74 > 0 ;
V_95 ++ , V_74 -= V_29 -> V_78 , V_71 += V_29 -> V_78 ) {
if ( F_37 ( F_38 ( V_29 , V_95 ) , V_71 ,
F_29 ( V_74 , V_29 -> V_78 ) ) )
return - V_81 ;
}
return 0 ;
}
static int F_39 ( struct V_8 * V_99 ,
struct V_8 * V_100 )
{
if ( ! V_99 -> V_53 && ! V_100 -> V_53 )
return ( V_99 -> V_47 == V_100 -> V_47 ) ;
if ( V_99 -> V_53 && V_100 -> V_53 )
return ! memcmp ( V_99 -> V_67 , V_100 -> V_67 , 16 ) ;
return 0 ;
}
static int F_40 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
struct V_14 * V_101 ;
struct V_102 * V_103 , * V_19 ;
V_19 = (struct V_102 * ) V_15 -> V_18 . V_87 ;
F_41 (sent_packet, &file->send_list, list) {
V_103 = (struct V_102 * ) V_101 -> V_18 . V_87 ;
if ( ( V_19 -> V_104 != V_103 -> V_104 ) ||
( V_19 -> V_84 != V_103 -> V_84 ) )
continue;
if ( ! F_42 ( V_19 ) ) {
if ( ! F_42 ( V_103 ) )
return 1 ;
continue;
} else if ( ! F_42 ( V_103 ) )
continue;
if ( F_39 ( & V_15 -> V_18 . V_19 , & V_101 -> V_18 . V_19 ) )
return 1 ;
}
return 0 ;
}
static T_1 F_43 ( struct V_6 * V_88 , const char T_2 * V_71 ,
T_3 V_72 , T_4 * V_89 )
{
struct V_5 * V_6 = V_88 -> V_90 ;
struct V_14 * V_15 ;
struct V_10 * V_13 ;
struct V_56 V_57 ;
struct V_105 * V_30 ;
struct V_106 * V_107 ;
T_5 * V_104 ;
int V_16 , V_98 , V_96 , V_108 , V_109 ;
T_6 V_110 ;
if ( V_72 < F_4 ( V_6 ) + V_97 )
return - V_80 ;
V_15 = F_19 ( sizeof *V_15 + V_97 , V_42 ) ;
if ( ! V_15 )
return - V_111 ;
if ( F_37 ( & V_15 -> V_18 , V_71 , F_4 ( V_6 ) ) ) {
V_16 = - V_81 ;
goto V_112;
}
if ( V_15 -> V_18 . V_19 . V_11 >= V_20 ) {
V_16 = - V_80 ;
goto V_112;
}
V_71 += F_4 ( V_6 ) ;
if ( F_37 ( V_15 -> V_18 . V_87 , V_71 , V_97 ) ) {
V_16 = - V_81 ;
goto V_112;
}
F_7 ( & V_6 -> V_17 ) ;
V_13 = F_5 ( V_6 , V_15 -> V_18 . V_19 . V_11 ) ;
if ( ! V_13 ) {
V_16 = - V_80 ;
goto V_113;
}
memset ( & V_57 , 0 , sizeof V_57 ) ;
V_57 . type = F_44 ( V_6 -> V_114 -> V_115 ,
V_6 -> V_114 -> V_61 ) ;
F_45 ( & V_57 , F_46 ( V_15 -> V_18 . V_19 . V_47 ) ) ;
F_47 ( & V_57 , V_15 -> V_18 . V_19 . V_49 ) ;
F_48 ( & V_57 , V_15 -> V_18 . V_19 . V_50 ) ;
F_49 ( & V_57 , V_6 -> V_114 -> V_61 ) ;
if ( V_15 -> V_18 . V_19 . V_53 ) {
F_50 ( & V_57 , NULL ,
F_51 ( V_15 -> V_18 . V_19 . V_69 ) ,
V_15 -> V_18 . V_19 . V_63 ,
V_15 -> V_18 . V_19 . V_65 ,
V_15 -> V_18 . V_19 . V_66 ) ;
F_52 ( & V_57 , V_15 -> V_18 . V_19 . V_67 ) ;
}
V_30 = F_53 ( V_13 -> V_116 -> V_117 , & V_57 ) ;
if ( F_54 ( V_30 ) ) {
V_16 = F_55 ( V_30 ) ;
goto V_113;
}
V_107 = (struct V_106 * ) V_15 -> V_18 . V_87 ;
V_96 = F_28 ( V_107 -> V_83 . V_84 ) ;
if ( F_56 ( V_107 -> V_83 . V_84 )
&& F_57 ( V_13 ) ) {
V_108 = V_97 ;
V_109 = F_58 ( & V_107 -> V_118 ) &
V_119 ;
} else {
V_108 = V_34 ;
V_109 = 0 ;
}
V_110 = ( (struct V_102 * ) & V_15 -> V_18 . V_87 ) -> V_110 ;
V_98 = V_72 - F_4 ( V_6 ) - V_96 ;
V_15 -> V_29 = F_59 ( V_13 ,
F_51 ( V_15 -> V_18 . V_19 . V_45 ) ,
V_15 -> V_18 . V_19 . V_52 , V_109 ,
V_96 , V_98 , V_42 ,
V_110 ) ;
if ( F_54 ( V_15 -> V_29 ) ) {
V_16 = F_55 ( V_15 -> V_29 ) ;
goto V_120;
}
V_15 -> V_29 -> V_30 = V_30 ;
V_15 -> V_29 -> V_121 = V_15 -> V_18 . V_19 . V_121 ;
V_15 -> V_29 -> V_122 = V_15 -> V_18 . V_19 . V_122 ;
V_15 -> V_29 -> V_27 [ 0 ] = V_15 ;
memcpy ( V_15 -> V_29 -> V_18 , V_15 -> V_18 . V_87 , V_34 ) ;
if ( ! V_109 ) {
if ( F_37 ( V_15 -> V_29 -> V_18 + V_108 ,
V_71 + V_108 ,
V_96 + V_98 - V_108 ) ) {
V_16 = - V_81 ;
goto V_123;
}
} else {
V_16 = F_36 ( V_15 -> V_29 , V_71 ) ;
if ( V_16 )
goto V_123;
}
if ( ! F_42 ( V_15 -> V_29 -> V_18 ) ) {
V_104 = & ( (struct V_102 * ) V_15 -> V_29 -> V_18 ) -> V_104 ;
* V_104 = F_60 ( ( ( V_124 ) V_13 -> V_125 ) << 32 |
( F_61 ( V_104 ) & 0xffffffff ) ) ;
V_107 -> V_83 . V_104 = * V_104 ;
}
if ( ! F_57 ( V_13 )
&& F_56 ( V_107 -> V_83 . V_84 )
&& ( F_58 ( & V_107 -> V_118 ) & V_119 ) ) {
F_12 ( & V_6 -> V_24 ) ;
F_8 ( & V_15 -> V_21 , & V_6 -> V_126 ) ;
F_14 ( & V_6 -> V_24 ) ;
} else {
F_12 ( & V_6 -> V_24 ) ;
V_16 = F_40 ( V_6 , V_15 ) ;
if ( ! V_16 )
F_8 ( & V_15 -> V_21 , & V_6 -> V_126 ) ;
F_14 ( & V_6 -> V_24 ) ;
if ( V_16 ) {
V_16 = - V_80 ;
goto V_123;
}
}
V_16 = F_62 ( V_15 -> V_29 , NULL ) ;
if ( V_16 )
goto V_127;
F_10 ( & V_6 -> V_17 ) ;
return V_72 ;
V_127:
F_11 ( V_6 , V_15 ) ;
V_123:
F_17 ( V_15 -> V_29 ) ;
V_120:
F_16 ( V_30 ) ;
V_113:
F_10 ( & V_6 -> V_17 ) ;
V_112:
F_3 ( V_15 ) ;
return V_16 ;
}
static unsigned int F_63 ( struct V_6 * V_88 , struct V_128 * V_129 )
{
struct V_5 * V_6 = V_88 -> V_90 ;
unsigned int V_130 = V_131 | V_132 ;
F_64 ( V_88 , & V_6 -> V_23 , V_129 ) ;
if ( ! F_32 ( & V_6 -> V_22 ) )
V_130 |= V_133 | V_134 ;
return V_130 ;
}
static int F_65 ( struct V_5 * V_6 , void T_2 * V_135 ,
int V_136 )
{
struct V_137 V_138 ;
struct V_139 V_140 ;
struct V_10 * V_13 = NULL ;
int V_141 ;
int V_16 ;
F_7 ( & V_6 -> V_114 -> V_142 ) ;
F_7 ( & V_6 -> V_17 ) ;
if ( ! V_6 -> V_114 -> V_115 ) {
F_66 ( V_6 -> V_114 -> V_4 ,
L_1 ) ;
V_16 = - V_143 ;
goto V_144;
}
if ( F_37 ( & V_138 , V_135 , sizeof V_138 ) ) {
V_16 = - V_81 ;
goto V_144;
}
if ( V_138 . V_45 != 0 && V_138 . V_45 != 1 ) {
F_66 ( V_6 -> V_114 -> V_4 ,
L_2 ,
V_138 . V_45 ) ;
V_16 = - V_80 ;
goto V_144;
}
for ( V_141 = 0 ; V_141 < V_20 ; ++ V_141 )
if ( ! F_5 ( V_6 , V_141 ) )
goto V_145;
F_66 ( V_6 -> V_114 -> V_4 ,
L_3 ,
V_20 ) ;
V_16 = - V_111 ;
goto V_144;
V_145:
if ( V_138 . V_84 ) {
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_84 = V_138 . V_84 ;
V_140 . V_146 = V_138 . V_146 ;
memcpy ( V_140 . V_147 , V_138 . V_147 , sizeof V_140 . V_147 ) ;
if ( V_136 ) {
T_7 * V_148 = ( T_7 * ) V_138 . V_149 ;
int V_150 ;
for ( V_150 = 0 ; V_150 < F_67 ( V_151 ) ; ++ V_150 )
V_140 . V_149 [ V_150 ] =
V_148 [ V_150 * 2 ] | ( ( V_124 ) V_148 [ V_150 * 2 + 1 ] << 32 ) ;
} else
memcpy ( V_140 . V_149 , V_138 . V_149 ,
sizeof V_140 . V_149 ) ;
}
V_13 = F_68 ( V_6 -> V_114 -> V_115 , V_6 -> V_114 -> V_61 ,
V_138 . V_45 ? V_152 : V_153 ,
V_138 . V_84 ? & V_140 : NULL ,
V_138 . V_154 ,
F_15 , F_18 , V_6 , 0 ) ;
if ( F_54 ( V_13 ) ) {
V_16 = F_55 ( V_13 ) ;
V_13 = NULL ;
goto V_144;
}
if ( F_69 ( V_141 ,
( T_7 T_2 * ) ( V_135 + F_70 ( struct V_137 , V_11 ) ) ) ) {
V_16 = - V_81 ;
goto V_144;
}
if ( ! V_6 -> V_155 ) {
V_6 -> V_155 = 1 ;
if ( ! V_6 -> V_7 ) {
F_71 ( V_6 -> V_114 -> V_4 ,
L_4 ,
V_156 -> V_157 ) ;
F_71 ( V_6 -> V_114 -> V_4 ,
L_5 ) ;
}
}
V_6 -> V_13 [ V_141 ] = V_13 ;
V_16 = 0 ;
V_144:
F_10 ( & V_6 -> V_17 ) ;
if ( V_16 && V_13 )
F_72 ( V_13 ) ;
F_10 ( & V_6 -> V_114 -> V_142 ) ;
return V_16 ;
}
static int F_73 ( struct V_5 * V_6 , void T_2 * V_135 )
{
struct V_158 V_138 ;
struct V_139 V_140 ;
struct V_10 * V_13 = NULL ;
int V_141 ;
int V_16 ;
F_7 ( & V_6 -> V_114 -> V_142 ) ;
F_7 ( & V_6 -> V_17 ) ;
if ( ! V_6 -> V_114 -> V_115 ) {
F_66 ( V_6 -> V_114 -> V_4 ,
L_6 ) ;
V_16 = - V_143 ;
goto V_144;
}
if ( F_37 ( & V_138 , V_135 , sizeof( V_138 ) ) ) {
V_16 = - V_81 ;
goto V_144;
}
if ( V_138 . V_45 != 0 && V_138 . V_45 != 1 ) {
F_66 ( V_6 -> V_114 -> V_4 ,
L_7 ,
V_138 . V_45 ) ;
V_16 = - V_80 ;
goto V_144;
}
if ( V_138 . V_159 & ~ V_160 ) {
F_66 ( V_6 -> V_114 -> V_4 ,
L_8 ,
V_138 . V_159 , V_160 ) ;
V_16 = - V_80 ;
if ( F_69 ( ( T_7 ) V_160 ,
( T_7 T_2 * ) ( V_135 + F_70 ( struct
V_158 , V_159 ) ) ) )
V_16 = - V_81 ;
goto V_144;
}
for ( V_141 = 0 ; V_141 < V_20 ; ++ V_141 )
if ( ! F_5 ( V_6 , V_141 ) )
goto V_145;
F_66 ( V_6 -> V_114 -> V_4 ,
L_9 ,
V_20 ) ;
V_16 = - V_111 ;
goto V_144;
V_145:
if ( V_138 . V_84 ) {
memset ( & V_140 , 0 , sizeof( V_140 ) ) ;
V_140 . V_84 = V_138 . V_84 ;
V_140 . V_146 = V_138 . V_146 ;
if ( V_138 . V_147 & 0xff000000 ) {
F_66 ( V_6 -> V_114 -> V_4 ,
L_10 ,
V_138 . V_147 ) ;
V_16 = - V_80 ;
goto V_144;
}
V_140 . V_147 [ 2 ] = V_138 . V_147 & 0x0000ff ;
V_140 . V_147 [ 1 ] = ( V_138 . V_147 & 0x00ff00 ) >> 8 ;
V_140 . V_147 [ 0 ] = ( V_138 . V_147 & 0xff0000 ) >> 16 ;
memcpy ( V_140 . V_149 , V_138 . V_149 ,
sizeof( V_140 . V_149 ) ) ;
}
V_13 = F_68 ( V_6 -> V_114 -> V_115 , V_6 -> V_114 -> V_61 ,
V_138 . V_45 ? V_152 : V_153 ,
V_138 . V_84 ? & V_140 : NULL ,
V_138 . V_154 ,
F_15 , F_18 , V_6 ,
V_138 . V_159 ) ;
if ( F_54 ( V_13 ) ) {
V_16 = F_55 ( V_13 ) ;
V_13 = NULL ;
goto V_144;
}
if ( F_69 ( V_141 ,
( T_7 T_2 * ) ( V_135 +
F_70 ( struct V_158 , V_11 ) ) ) ) {
V_16 = - V_81 ;
goto V_144;
}
if ( ! V_6 -> V_155 ) {
V_6 -> V_155 = 1 ;
V_6 -> V_7 = 1 ;
}
V_6 -> V_13 [ V_141 ] = V_13 ;
V_16 = 0 ;
V_144:
F_10 ( & V_6 -> V_17 ) ;
if ( V_16 && V_13 )
F_72 ( V_13 ) ;
F_10 ( & V_6 -> V_114 -> V_142 ) ;
return V_16 ;
}
static int F_74 ( struct V_5 * V_6 , T_7 T_2 * V_135 )
{
struct V_10 * V_13 = NULL ;
T_7 V_11 ;
int V_16 = 0 ;
if ( F_75 ( V_11 , V_135 ) )
return - V_81 ;
F_7 ( & V_6 -> V_114 -> V_142 ) ;
F_7 ( & V_6 -> V_17 ) ;
if ( V_11 >= V_20 || ! F_5 ( V_6 , V_11 ) ) {
V_16 = - V_80 ;
goto V_144;
}
V_13 = V_6 -> V_13 [ V_11 ] ;
V_6 -> V_13 [ V_11 ] = NULL ;
V_144:
F_10 ( & V_6 -> V_17 ) ;
if ( V_13 )
F_72 ( V_13 ) ;
F_10 ( & V_6 -> V_114 -> V_142 ) ;
return V_16 ;
}
static long F_76 ( struct V_5 * V_6 )
{
int V_16 = 0 ;
F_7 ( & V_6 -> V_17 ) ;
if ( V_6 -> V_155 )
V_16 = - V_80 ;
else
V_6 -> V_7 = 1 ;
F_10 ( & V_6 -> V_17 ) ;
return V_16 ;
}
static long F_77 ( struct V_6 * V_88 , unsigned int V_161 ,
unsigned long V_135 )
{
switch ( V_161 ) {
case V_162 :
return F_65 ( V_88 -> V_90 , ( void T_2 * ) V_135 , 0 ) ;
case V_163 :
return F_74 ( V_88 -> V_90 , ( V_164 T_2 * ) V_135 ) ;
case V_165 :
return F_76 ( V_88 -> V_90 ) ;
case V_166 :
return F_73 ( V_88 -> V_90 , ( void T_2 * ) V_135 ) ;
default:
return - V_167 ;
}
}
static long F_78 ( struct V_6 * V_88 , unsigned int V_161 ,
unsigned long V_135 )
{
switch ( V_161 ) {
case V_162 :
return F_65 ( V_88 -> V_90 , F_79 ( V_135 ) , 1 ) ;
case V_163 :
return F_74 ( V_88 -> V_90 , F_79 ( V_135 ) ) ;
case V_165 :
return F_76 ( V_88 -> V_90 ) ;
case V_166 :
return F_73 ( V_88 -> V_90 , F_79 ( V_135 ) ) ;
default:
return - V_167 ;
}
}
static int F_80 ( struct V_168 * V_168 , struct V_6 * V_88 )
{
struct V_169 * V_114 ;
struct V_5 * V_6 ;
int V_16 = - V_170 ;
V_114 = F_2 ( V_168 -> V_171 , struct V_169 , V_172 ) ;
F_7 ( & V_114 -> V_142 ) ;
if ( ! V_114 -> V_115 )
goto V_144;
V_16 = - V_111 ;
V_6 = F_19 ( sizeof *V_6 , V_42 ) ;
if ( ! V_6 )
goto V_144;
F_81 ( & V_6 -> V_17 ) ;
F_82 ( & V_6 -> V_24 ) ;
F_83 ( & V_6 -> V_22 ) ;
F_83 ( & V_6 -> V_126 ) ;
F_84 ( & V_6 -> V_23 ) ;
V_6 -> V_114 = V_114 ;
V_88 -> V_90 = V_6 ;
F_8 ( & V_6 -> V_173 , & V_114 -> V_174 ) ;
V_16 = F_85 ( V_168 , V_88 ) ;
if ( V_16 ) {
F_13 ( & V_6 -> V_173 ) ;
F_3 ( V_6 ) ;
goto V_144;
}
F_86 ( & V_114 -> V_175 -> V_2 ) ;
V_144:
F_10 ( & V_114 -> V_142 ) ;
return V_16 ;
}
static int F_87 ( struct V_168 * V_168 , struct V_6 * V_88 )
{
struct V_5 * V_6 = V_88 -> V_90 ;
struct V_3 * V_4 = V_6 -> V_114 -> V_175 ;
struct V_14 * V_15 , * V_176 ;
int V_177 ;
int V_150 ;
F_7 ( & V_6 -> V_114 -> V_142 ) ;
F_7 ( & V_6 -> V_17 ) ;
V_177 = V_6 -> V_12 ;
V_6 -> V_12 = 1 ;
F_88 (packet, tmp, &file->recv_list, list) {
if ( V_15 -> V_44 )
F_24 ( V_15 -> V_44 ) ;
F_3 ( V_15 ) ;
}
F_13 ( & V_6 -> V_173 ) ;
F_10 ( & V_6 -> V_17 ) ;
if ( ! V_177 )
for ( V_150 = 0 ; V_150 < V_20 ; ++ V_150 )
if ( V_6 -> V_13 [ V_150 ] )
F_72 ( V_6 -> V_13 [ V_150 ] ) ;
F_10 ( & V_6 -> V_114 -> V_142 ) ;
F_3 ( V_6 ) ;
F_89 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_168 * V_168 , struct V_6 * V_88 )
{
struct V_169 * V_114 ;
struct V_178 V_179 = {
. V_180 = V_181
} ;
int V_16 ;
V_114 = F_2 ( V_168 -> V_171 , struct V_169 , V_182 ) ;
if ( V_88 -> V_91 & V_92 ) {
if ( F_91 ( & V_114 -> V_183 ) ) {
V_16 = - V_93 ;
goto V_184;
}
} else {
if ( F_92 ( & V_114 -> V_183 ) ) {
V_16 = - V_94 ;
goto V_184;
}
}
V_16 = F_93 ( V_114 -> V_115 , V_114 -> V_61 , 0 , & V_179 ) ;
if ( V_16 )
goto V_185;
V_88 -> V_90 = V_114 ;
V_16 = F_85 ( V_168 , V_88 ) ;
if ( V_16 )
goto V_186;
F_86 ( & V_114 -> V_175 -> V_2 ) ;
return 0 ;
V_186:
F_94 ( V_179 . V_180 , V_179 . V_187 ) ;
F_93 ( V_114 -> V_115 , V_114 -> V_61 , 0 , & V_179 ) ;
V_185:
F_95 ( & V_114 -> V_183 ) ;
V_184:
return V_16 ;
}
static int F_96 ( struct V_168 * V_168 , struct V_6 * V_88 )
{
struct V_169 * V_114 = V_88 -> V_90 ;
struct V_178 V_179 = {
. V_187 = V_181
} ;
int V_16 = 0 ;
F_7 ( & V_114 -> V_142 ) ;
if ( V_114 -> V_115 )
V_16 = F_93 ( V_114 -> V_115 , V_114 -> V_61 , 0 , & V_179 ) ;
F_10 ( & V_114 -> V_142 ) ;
F_95 ( & V_114 -> V_183 ) ;
F_89 ( & V_114 -> V_175 -> V_2 ) ;
return V_16 ;
}
static T_1 F_97 ( struct V_60 * V_4 , struct V_188 * V_189 ,
char * V_71 )
{
struct V_169 * V_114 = F_98 ( V_4 ) ;
if ( ! V_114 )
return - V_190 ;
return sprintf ( V_71 , L_11 , V_114 -> V_115 -> V_191 ) ;
}
static T_1 F_99 ( struct V_60 * V_4 , struct V_188 * V_189 ,
char * V_71 )
{
struct V_169 * V_114 = F_98 ( V_4 ) ;
if ( ! V_114 )
return - V_190 ;
return sprintf ( V_71 , L_12 , V_114 -> V_61 ) ;
}
static int F_100 ( struct V_192 * V_60 )
{
int V_16 ;
if ( ! V_193 ) {
V_16 = F_101 ( & V_193 , 0 , V_194 * 2 ,
L_13 ) ;
if ( V_16 ) {
F_102 ( & V_60 -> V_4 ,
L_14 ) ;
return V_16 ;
}
}
V_16 = F_103 ( V_195 , V_194 ) ;
if ( V_16 >= V_194 )
return - 1 ;
return V_16 ;
}
static int F_104 ( struct V_192 * V_60 , int V_61 ,
struct V_3 * V_175 ,
struct V_169 * V_114 )
{
int V_196 ;
T_8 V_197 ;
F_105 ( & V_198 ) ;
V_196 = F_103 ( V_199 , V_194 ) ;
if ( V_196 >= V_194 ) {
F_106 ( & V_198 ) ;
V_196 = F_100 ( V_60 ) ;
if ( V_196 < 0 )
return - 1 ;
F_105 ( & V_198 ) ;
V_114 -> V_200 = V_196 + V_194 ;
V_197 = V_196 + V_193 ;
F_107 ( V_196 , V_195 ) ;
} else {
V_114 -> V_200 = V_196 ;
V_197 = V_196 + V_201 ;
F_107 ( V_196 , V_199 ) ;
}
F_106 ( & V_198 ) ;
V_114 -> V_115 = V_60 ;
V_114 -> V_61 = V_61 ;
F_108 ( & V_114 -> V_183 , 1 ) ;
F_81 ( & V_114 -> V_142 ) ;
F_83 ( & V_114 -> V_174 ) ;
F_109 ( & V_114 -> V_172 , & V_202 ) ;
V_114 -> V_172 . V_203 = V_204 ;
F_110 ( & V_114 -> V_172 , & V_175 -> V_2 ) ;
F_111 ( & V_114 -> V_172 . V_2 , L_15 , V_114 -> V_200 ) ;
if ( F_112 ( & V_114 -> V_172 , V_197 , 1 ) )
goto V_205;
V_114 -> V_4 = F_113 ( V_206 , V_60 -> V_4 . V_207 ,
V_114 -> V_172 . V_4 , V_114 ,
L_15 , V_114 -> V_200 ) ;
if ( F_54 ( V_114 -> V_4 ) )
goto V_205;
if ( F_114 ( V_114 -> V_4 , & V_208 ) )
goto V_209;
if ( F_114 ( V_114 -> V_4 , & V_210 ) )
goto V_209;
V_197 += V_194 ;
F_109 ( & V_114 -> V_182 , & V_211 ) ;
V_114 -> V_182 . V_203 = V_204 ;
F_110 ( & V_114 -> V_182 , & V_175 -> V_2 ) ;
F_111 ( & V_114 -> V_182 . V_2 , L_16 , V_114 -> V_200 ) ;
if ( F_112 ( & V_114 -> V_182 , V_197 , 1 ) )
goto V_212;
V_114 -> V_213 = F_113 ( V_206 , V_60 -> V_4 . V_207 ,
V_114 -> V_182 . V_4 , V_114 ,
L_16 , V_114 -> V_200 ) ;
if ( F_54 ( V_114 -> V_213 ) )
goto V_212;
if ( F_114 ( V_114 -> V_213 , & V_208 ) )
goto V_214;
if ( F_114 ( V_114 -> V_213 , & V_210 ) )
goto V_214;
return 0 ;
V_214:
F_115 ( V_206 , V_114 -> V_182 . V_4 ) ;
V_212:
F_116 ( & V_114 -> V_182 ) ;
V_209:
F_115 ( V_206 , V_114 -> V_172 . V_4 ) ;
V_205:
F_116 ( & V_114 -> V_172 ) ;
if ( V_114 -> V_200 < V_194 )
F_117 ( V_196 , V_199 ) ;
else
F_117 ( V_196 , V_195 ) ;
return - 1 ;
}
static void F_118 ( struct V_169 * V_114 )
{
struct V_5 * V_6 ;
int V_11 ;
F_119 ( V_114 -> V_4 , NULL ) ;
F_119 ( V_114 -> V_213 , NULL ) ;
F_115 ( V_206 , V_114 -> V_172 . V_4 ) ;
F_115 ( V_206 , V_114 -> V_182 . V_4 ) ;
F_116 ( & V_114 -> V_172 ) ;
F_116 ( & V_114 -> V_182 ) ;
F_7 ( & V_114 -> V_142 ) ;
V_114 -> V_115 = NULL ;
F_41 (file, &port->file_list, port_list) {
F_7 ( & V_6 -> V_17 ) ;
V_6 -> V_12 = 1 ;
F_10 ( & V_6 -> V_17 ) ;
for ( V_11 = 0 ; V_11 < V_20 ; ++ V_11 )
if ( V_6 -> V_13 [ V_11 ] )
F_72 ( V_6 -> V_13 [ V_11 ] ) ;
}
F_10 ( & V_114 -> V_142 ) ;
if ( V_114 -> V_200 < V_194 )
F_117 ( V_114 -> V_200 , V_199 ) ;
else
F_117 ( V_114 -> V_200 - V_194 , V_195 ) ;
}
static void F_120 ( struct V_192 * V_60 )
{
struct V_3 * V_175 ;
int V_215 , V_216 , V_150 ;
int V_72 = 0 ;
V_215 = F_121 ( V_60 ) ;
V_216 = F_122 ( V_60 ) ;
V_175 = F_19 ( sizeof *V_175 +
( V_216 - V_215 + 1 ) * sizeof ( struct V_169 ) ,
V_42 ) ;
if ( ! V_175 )
return;
F_123 ( & V_175 -> V_2 , & V_217 ) ;
for ( V_150 = V_215 ; V_150 <= V_216 ; ++ V_150 ) {
if ( ! F_124 ( V_60 , V_150 ) )
continue;
V_175 -> V_114 [ V_150 - V_215 ] . V_175 = V_175 ;
if ( F_104 ( V_60 , V_150 , V_175 ,
& V_175 -> V_114 [ V_150 - V_215 ] ) )
goto V_112;
V_72 ++ ;
}
if ( ! V_72 )
goto free;
F_125 ( V_60 , & V_218 , V_175 ) ;
return;
V_112:
while ( -- V_150 >= V_215 ) {
if ( ! F_124 ( V_60 , V_150 ) )
continue;
F_118 ( & V_175 -> V_114 [ V_150 - V_215 ] ) ;
}
free:
F_89 ( & V_175 -> V_2 ) ;
}
static void F_126 ( struct V_192 * V_60 , void * V_219 )
{
struct V_3 * V_175 = V_219 ;
int V_150 ;
if ( ! V_175 )
return;
for ( V_150 = 0 ; V_150 <= F_122 ( V_60 ) - F_121 ( V_60 ) ; ++ V_150 ) {
if ( F_124 ( V_60 , V_150 + F_121 ( V_60 ) ) )
F_118 ( & V_175 -> V_114 [ V_150 ] ) ;
}
F_89 ( & V_175 -> V_2 ) ;
}
static char * F_127 ( struct V_60 * V_4 , T_9 * V_220 )
{
return F_128 ( V_42 , L_17 , F_129 ( V_4 ) ) ;
}
static int T_10 F_130 ( void )
{
int V_16 ;
V_16 = F_131 ( V_201 , V_194 * 2 ,
L_13 ) ;
if ( V_16 ) {
F_132 ( L_18 ) ;
goto V_144;
}
V_206 = F_133 ( V_204 , L_13 ) ;
if ( F_54 ( V_206 ) ) {
V_16 = F_55 ( V_206 ) ;
F_132 ( L_19 ) ;
goto V_221;
}
V_206 -> V_222 = F_127 ;
V_16 = F_134 ( V_206 , & V_223 . V_189 ) ;
if ( V_16 ) {
F_132 ( L_20 ) ;
goto V_224;
}
V_16 = F_135 ( & V_218 ) ;
if ( V_16 ) {
F_132 ( L_21 ) ;
goto V_224;
}
return 0 ;
V_224:
F_136 ( V_206 ) ;
V_221:
F_137 ( V_201 , V_194 * 2 ) ;
V_144:
return V_16 ;
}
static void T_11 F_138 ( void )
{
F_139 ( & V_218 ) ;
F_136 ( V_206 ) ;
F_137 ( V_201 , V_194 * 2 ) ;
if ( V_193 )
F_137 ( V_193 , V_194 * 2 ) ;
}
