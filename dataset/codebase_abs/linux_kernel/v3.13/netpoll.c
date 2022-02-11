static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 . V_2 ) ;
struct V_6 * V_7 ;
unsigned long V_8 ;
while ( ( V_7 = F_3 ( & V_4 -> V_9 ) ) ) {
struct V_10 * V_11 = V_7 -> V_11 ;
const struct V_12 * V_13 = V_11 -> V_14 ;
struct V_15 * V_9 ;
if ( ! F_4 ( V_11 ) || ! F_5 ( V_11 ) ) {
F_6 ( V_7 ) ;
continue;
}
V_9 = F_7 ( V_11 , F_8 ( V_7 ) ) ;
F_9 ( V_8 ) ;
F_10 ( V_9 , F_11 () ) ;
if ( F_12 ( V_9 ) ||
V_13 -> V_16 ( V_7 , V_11 ) != V_17 ) {
F_13 ( & V_4 -> V_9 , V_7 ) ;
F_14 ( V_9 ) ;
F_15 ( V_8 ) ;
F_16 ( & V_4 -> V_5 , V_18 / 10 ) ;
return;
}
F_14 ( V_9 ) ;
F_15 ( V_8 ) ;
}
}
static T_1 F_17 ( struct V_6 * V_7 , struct V_19 * V_20 ,
unsigned short V_21 , T_2 V_22 , T_2 V_23 )
{
T_3 V_24 ;
if ( V_20 -> V_25 == 0 || F_18 ( V_7 ) )
return 0 ;
V_24 = F_19 ( V_22 , V_23 , V_21 , V_26 , 0 ) ;
if ( V_7 -> V_27 == V_28 &&
! F_20 ( F_21 ( V_24 , V_7 -> V_29 ) ) )
return 0 ;
V_7 -> V_29 = V_24 ;
return F_22 ( V_7 ) ;
}
static int F_23 ( struct V_3 * V_4 ,
struct V_30 * V_31 , int V_32 )
{
int V_2 ;
if ( ! F_24 ( V_33 , & V_31 -> V_34 ) )
return V_32 ;
V_4 -> V_35 |= V_36 ;
F_25 ( & V_37 ) ;
F_26 ( V_38 , & V_31 -> V_34 ) ;
V_2 = V_31 -> V_39 ( V_31 , V_32 ) ;
F_27 ( V_31 ) ;
F_28 ( V_38 , & V_31 -> V_34 ) ;
F_29 ( & V_37 ) ;
V_4 -> V_35 &= ~ V_36 ;
return V_32 - V_2 ;
}
static void F_30 ( struct V_10 * V_11 )
{
struct V_30 * V_31 ;
int V_32 = 16 ;
F_31 (napi, &dev->napi_list, dev_list) {
if ( V_31 -> V_40 != F_11 () &&
F_32 ( & V_31 -> V_41 ) ) {
V_32 = F_23 ( F_33 ( V_11 -> V_4 ) ,
V_31 , V_32 ) ;
F_34 ( & V_31 -> V_41 ) ;
if ( ! V_32 )
break;
}
}
}
static void F_35 ( struct V_3 * V_42 )
{
if ( V_42 ) {
struct V_6 * V_7 ;
while ( ( V_7 = F_3 ( & V_42 -> V_43 ) ) )
F_36 ( V_7 , V_42 ) ;
}
}
static void F_37 ( struct V_10 * V_11 )
{
const struct V_12 * V_13 ;
struct V_3 * V_44 = F_33 ( V_11 -> V_4 ) ;
if ( F_38 ( & V_44 -> V_45 ) )
return;
if ( ! F_5 ( V_11 ) ) {
F_39 ( & V_44 -> V_45 ) ;
return;
}
V_13 = V_11 -> V_14 ;
if ( ! V_13 -> V_46 ) {
F_39 ( & V_44 -> V_45 ) ;
return;
}
V_13 -> V_46 ( V_11 ) ;
F_30 ( V_11 ) ;
F_39 ( & V_44 -> V_45 ) ;
if ( V_11 -> V_8 & V_47 ) {
if ( V_44 ) {
struct V_10 * V_48 ;
struct V_6 * V_7 ;
struct V_3 * V_49 ;
V_48 = F_40 ( V_11 ) ;
V_49 = F_33 ( V_48 -> V_4 ) ;
while ( ( V_7 = F_3 ( & V_44 -> V_43 ) ) ) {
V_7 -> V_11 = V_48 ;
F_41 ( & V_49 -> V_43 , V_7 ) ;
}
}
}
F_35 ( V_44 ) ;
F_42 () ;
}
void F_43 ( struct V_10 * V_11 )
{
struct V_3 * V_44 ;
int V_50 ;
F_44 () ;
V_50 = F_45 ( & V_51 ) ;
V_44 = F_46 ( V_11 -> V_4 , & V_51 ) ;
if ( V_44 )
F_47 ( & V_44 -> V_45 ) ;
F_48 ( & V_51 , V_50 ) ;
}
void F_49 ( struct V_10 * V_11 )
{
struct V_3 * V_44 ;
F_50 () ;
V_44 = F_51 ( V_11 -> V_4 ) ;
if ( V_44 )
F_39 ( & V_44 -> V_45 ) ;
F_52 () ;
}
static void F_53 ( void )
{
struct V_6 * V_7 ;
unsigned long V_8 ;
F_54 ( & V_52 . V_53 , V_8 ) ;
while ( V_52 . V_54 < V_55 ) {
V_7 = F_55 ( V_56 , V_57 ) ;
if ( ! V_7 )
break;
F_56 ( & V_52 , V_7 ) ;
}
F_57 ( & V_52 . V_53 , V_8 ) ;
}
static void F_42 ( void )
{
unsigned long V_8 ;
struct V_58 * V_59 = & F_58 ( V_58 ) ;
if ( V_59 -> V_60 ) {
struct V_6 * V_61 ;
F_9 ( V_8 ) ;
V_61 = V_59 -> V_60 ;
V_59 -> V_60 = NULL ;
F_15 ( V_8 ) ;
while ( V_61 != NULL ) {
struct V_6 * V_7 = V_61 ;
V_61 = V_61 -> V_62 ;
if ( V_7 -> V_63 ) {
F_25 ( & V_7 -> V_64 ) ;
F_59 ( V_7 ) ;
} else {
F_6 ( V_7 ) ;
}
}
}
F_60 ( V_58 ) ;
}
static struct V_6 * F_61 ( struct V_65 * V_66 , int V_67 , int V_68 )
{
int V_69 = 0 ;
struct V_6 * V_7 ;
F_42 () ;
F_53 () ;
V_70:
V_7 = F_55 ( V_67 , V_57 ) ;
if ( ! V_7 )
V_7 = F_3 ( & V_52 ) ;
if ( ! V_7 ) {
if ( ++ V_69 < 10 ) {
F_37 ( V_66 -> V_11 ) ;
goto V_70;
}
return NULL ;
}
F_62 ( & V_7 -> V_64 , 1 ) ;
F_63 ( V_7 , V_68 ) ;
return V_7 ;
}
static int F_64 ( struct V_10 * V_11 )
{
struct V_30 * V_31 ;
F_31 (napi, &dev->napi_list, dev_list) {
if ( V_31 -> V_40 == F_11 () )
return 1 ;
}
return 0 ;
}
void F_65 ( struct V_65 * V_66 , struct V_6 * V_7 ,
struct V_10 * V_11 )
{
int V_71 = V_72 ;
unsigned long V_73 ;
const struct V_12 * V_13 = V_11 -> V_14 ;
struct V_3 * V_4 ;
F_66 ( ! F_67 () ) ;
V_4 = F_33 ( V_66 -> V_11 -> V_4 ) ;
if ( ! V_4 || ! F_5 ( V_11 ) || ! F_4 ( V_11 ) ) {
F_6 ( V_7 ) ;
return;
}
if ( F_68 ( & V_4 -> V_9 ) == 0 && ! F_64 ( V_11 ) ) {
struct V_15 * V_9 ;
V_9 = F_69 ( V_11 , V_7 , NULL ) ;
for ( V_73 = F_70 ( 1 ) / V_74 ;
V_73 > 0 ; -- V_73 ) {
if ( F_71 ( V_9 ) ) {
if ( ! F_72 ( V_9 ) ) {
if ( F_73 ( V_7 ) &&
! F_74 ( F_75 ( V_7 ) ,
V_7 -> V_75 ) ) {
V_7 = F_76 ( V_7 , V_7 -> V_75 , F_77 ( V_7 ) ) ;
if ( F_78 ( ! V_7 ) ) {
V_71 = V_17 ;
goto V_76;
}
V_7 -> V_77 = 0 ;
}
V_71 = V_13 -> V_16 ( V_7 , V_11 ) ;
if ( V_71 == V_17 )
F_79 ( V_9 ) ;
}
V_76:
F_14 ( V_9 ) ;
if ( V_71 == V_17 )
break;
}
F_37 ( V_66 -> V_11 ) ;
F_80 ( V_74 ) ;
}
F_81 ( ! F_67 () ,
L_1 ,
V_11 -> V_78 , V_13 -> V_16 ) ;
}
if ( V_71 != V_17 ) {
F_41 ( & V_4 -> V_9 , V_7 ) ;
F_16 ( & V_4 -> V_5 , 0 ) ;
}
}
void F_82 ( struct V_65 * V_66 , const char * V_79 , int V_67 )
{
int V_80 , V_81 , V_82 ;
struct V_6 * V_7 ;
struct V_19 * V_83 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
static T_4 V_88 ;
struct V_89 * V_90 ;
V_82 = V_67 + sizeof( * V_83 ) ;
if ( V_66 -> V_91 )
V_81 = V_82 + sizeof( * V_90 ) ;
else
V_81 = V_82 + sizeof( * V_85 ) ;
V_80 = V_81 + F_83 ( V_66 -> V_11 ) ;
V_7 = F_61 ( V_66 , V_80 + V_66 -> V_11 -> V_92 ,
V_80 - V_67 ) ;
if ( ! V_7 )
return;
F_84 ( V_7 , V_79 , V_67 ) ;
F_85 ( V_7 , V_67 ) ;
F_86 ( V_7 , sizeof( * V_83 ) ) ;
F_87 ( V_7 ) ;
V_83 = F_88 ( V_7 ) ;
V_83 -> V_93 = F_89 ( V_66 -> V_94 ) ;
V_83 -> V_95 = F_89 ( V_66 -> V_96 ) ;
V_83 -> V_67 = F_89 ( V_82 ) ;
if ( V_66 -> V_91 ) {
V_83 -> V_25 = 0 ;
V_83 -> V_25 = F_90 ( & V_66 -> V_97 . V_98 ,
& V_66 -> V_99 . V_98 ,
V_82 , V_26 ,
F_91 ( V_83 , V_82 , 0 ) ) ;
if ( V_83 -> V_25 == 0 )
V_83 -> V_25 = V_100 ;
F_86 ( V_7 , sizeof( * V_90 ) ) ;
F_92 ( V_7 ) ;
V_90 = F_93 ( V_7 ) ;
F_94 ( 0x60 , ( unsigned char * ) V_90 ) ;
V_90 -> V_101 [ 0 ] = 0 ;
V_90 -> V_101 [ 1 ] = 0 ;
V_90 -> V_101 [ 2 ] = 0 ;
V_90 -> V_102 = F_89 ( sizeof( struct V_19 ) + V_67 ) ;
V_90 -> V_103 = V_26 ;
V_90 -> V_104 = 32 ;
V_90 -> V_22 = V_66 -> V_97 . V_98 ;
V_90 -> V_23 = V_66 -> V_99 . V_98 ;
V_87 = (struct V_86 * ) F_86 ( V_7 , V_105 ) ;
F_95 ( V_7 ) ;
V_7 -> V_106 = V_87 -> V_107 = F_89 ( V_108 ) ;
} else {
V_83 -> V_25 = 0 ;
V_83 -> V_25 = F_96 ( V_66 -> V_97 . V_109 ,
V_66 -> V_99 . V_109 ,
V_82 , V_26 ,
F_91 ( V_83 , V_82 , 0 ) ) ;
if ( V_83 -> V_25 == 0 )
V_83 -> V_25 = V_100 ;
F_86 ( V_7 , sizeof( * V_85 ) ) ;
F_92 ( V_7 ) ;
V_85 = F_97 ( V_7 ) ;
F_94 ( 0x45 , ( unsigned char * ) V_85 ) ;
V_85 -> V_110 = 0 ;
F_94 ( F_89 ( V_81 ) , & ( V_85 -> V_111 ) ) ;
V_85 -> V_112 = F_89 ( F_98 ( & V_88 ) ) ;
V_85 -> V_113 = 0 ;
V_85 -> V_114 = 64 ;
V_85 -> V_106 = V_26 ;
V_85 -> V_25 = 0 ;
F_94 ( V_66 -> V_97 . V_109 , & ( V_85 -> V_22 ) ) ;
F_94 ( V_66 -> V_99 . V_109 , & ( V_85 -> V_23 ) ) ;
V_85 -> V_25 = F_99 ( ( unsigned char * ) V_85 , V_85 -> V_115 ) ;
V_87 = (struct V_86 * ) F_86 ( V_7 , V_105 ) ;
F_95 ( V_7 ) ;
V_7 -> V_106 = V_87 -> V_107 = F_89 ( V_116 ) ;
}
memcpy ( V_87 -> V_117 , V_66 -> V_11 -> V_118 , V_119 ) ;
memcpy ( V_87 -> V_120 , V_66 -> V_121 , V_119 ) ;
V_7 -> V_11 = V_66 -> V_11 ;
F_100 ( V_66 , V_7 ) ;
}
static void F_36 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
int V_122 , type = V_123 ;
T_2 V_124 , V_125 ;
unsigned char * V_126 ;
struct V_6 * V_127 ;
struct V_65 * V_66 , * V_128 ;
unsigned long V_8 ;
int V_129 , V_130 ;
int V_131 = 0 , V_132 ;
if ( F_101 ( & V_4 -> V_133 ) )
return;
F_54 ( & V_4 -> V_134 , V_8 ) ;
F_102 (np, tmp, &npinfo->rx_np, rx) {
if ( V_66 -> V_11 == V_7 -> V_11 )
V_131 ++ ;
}
F_57 ( & V_4 -> V_134 , V_8 ) ;
if ( ! V_131 )
return;
V_132 = F_103 ( F_104 ( V_7 ) -> V_107 ) ;
if ( V_132 == V_135 ) {
struct V_136 * V_137 ;
unsigned char * V_138 ;
if ( V_7 -> V_11 -> V_8 & V_139 )
return;
if ( ! F_105 ( V_7 , F_106 ( V_7 -> V_11 ) ) )
return;
F_92 ( V_7 ) ;
F_87 ( V_7 ) ;
V_137 = F_107 ( V_7 ) ;
if ( ( V_137 -> V_140 != F_89 ( V_141 ) &&
V_137 -> V_140 != F_89 ( V_142 ) ) ||
V_137 -> V_143 != F_89 ( V_116 ) ||
V_137 -> V_144 != F_89 ( V_145 ) )
return;
V_138 = ( unsigned char * ) ( V_137 + 1 ) ;
V_126 = V_138 ;
V_138 += V_7 -> V_11 -> V_146 ;
memcpy ( & V_124 , V_138 , 4 ) ;
V_138 += 4 ;
V_138 += V_7 -> V_11 -> V_146 ;
memcpy ( & V_125 , V_138 , 4 ) ;
if ( F_108 ( V_125 ) || F_109 ( V_125 ) )
return;
V_122 = F_106 ( V_7 -> V_11 ) ;
F_54 ( & V_4 -> V_134 , V_8 ) ;
F_102 (np, tmp, &npinfo->rx_np, rx) {
if ( V_125 != V_66 -> V_97 . V_109 )
continue;
V_129 = F_83 ( V_66 -> V_11 ) ;
V_130 = V_66 -> V_11 -> V_92 ;
V_127 = F_61 ( V_66 , V_122 + V_129 + V_130 , V_129 ) ;
if ( ! V_127 )
continue;
F_92 ( V_127 ) ;
V_137 = (struct V_136 * ) F_85 ( V_127 , V_122 ) ;
V_127 -> V_11 = V_7 -> V_11 ;
V_127 -> V_106 = F_89 ( V_135 ) ;
if ( F_110 ( V_127 , V_7 -> V_11 , V_135 ,
V_126 , V_66 -> V_11 -> V_118 ,
V_127 -> V_67 ) < 0 ) {
F_111 ( V_127 ) ;
continue;
}
V_137 -> V_140 = F_89 ( V_66 -> V_11 -> type ) ;
V_137 -> V_143 = F_89 ( V_116 ) ;
V_137 -> V_147 = V_66 -> V_11 -> V_146 ;
V_137 -> V_148 = 4 ;
V_137 -> V_144 = F_89 ( type ) ;
V_138 = ( unsigned char * ) ( V_137 + 1 ) ;
memcpy ( V_138 , V_66 -> V_11 -> V_118 , V_66 -> V_11 -> V_146 ) ;
V_138 += V_66 -> V_11 -> V_146 ;
memcpy ( V_138 , & V_125 , 4 ) ;
V_138 += 4 ;
memcpy ( V_138 , V_126 , V_66 -> V_11 -> V_146 ) ;
V_138 += V_66 -> V_11 -> V_146 ;
memcpy ( V_138 , & V_124 , 4 ) ;
F_100 ( V_66 , V_127 ) ;
break;
}
F_57 ( & V_4 -> V_134 , V_8 ) ;
} else if( V_132 == V_108 ) {
#if F_112 ( V_149 )
struct V_150 * V_79 ;
T_5 * V_151 = NULL ;
struct V_89 * V_152 ;
struct V_153 * V_154 ;
const struct V_155 * V_22 ;
const struct V_155 * V_23 ;
struct V_156 * V_157 = NULL ;
struct V_155 * V_158 ;
V_157 = F_113 ( V_7 -> V_11 ) ;
if ( ! V_157 || ! V_157 -> V_159 . V_160 )
return;
if ( ! F_105 ( V_7 , V_7 -> V_67 ) )
return;
V_79 = (struct V_150 * ) F_114 ( V_7 ) ;
F_115 ( V_7 , V_7 -> V_161 - F_114 ( V_7 ) ) ;
if ( F_93 ( V_7 ) -> V_104 != 255 )
return;
if ( V_79 -> V_162 . V_163 != 0 )
return;
if ( V_79 -> V_162 . V_164 != V_165 )
return;
V_22 = & F_93 ( V_7 ) -> V_22 ;
V_23 = & F_93 ( V_7 ) -> V_23 ;
V_122 = sizeof( struct V_153 ) + sizeof( struct V_155 ) ;
F_54 ( & V_4 -> V_134 , V_8 ) ;
F_102 (np, tmp, &npinfo->rx_np, rx) {
if ( ! F_116 ( V_23 , & V_66 -> V_97 . V_98 ) )
continue;
V_129 = F_83 ( V_66 -> V_11 ) ;
V_130 = V_66 -> V_11 -> V_92 ;
V_127 = F_61 ( V_66 , V_122 + V_129 + V_130 , V_129 ) ;
if ( ! V_127 )
continue;
V_127 -> V_106 = F_89 ( V_108 ) ;
V_127 -> V_11 = V_7 -> V_11 ;
F_92 ( V_127 ) ;
V_152 = (struct V_89 * ) F_85 ( V_127 , sizeof( struct V_89 ) ) ;
* ( T_2 * ) V_152 = F_117 ( 0x60000000 ) ;
V_152 -> V_102 = F_89 ( V_122 ) ;
V_152 -> V_103 = V_166 ;
V_152 -> V_104 = 255 ;
V_152 -> V_22 = * V_22 ;
V_152 -> V_23 = * V_23 ;
V_154 = (struct V_153 * ) F_85 ( V_127 , sizeof( struct V_153 ) ) ;
V_154 -> V_164 = V_167 ;
V_154 -> V_168 = 0 ;
V_154 -> V_169 = 1 ;
V_158 = (struct V_155 * ) F_85 ( V_127 , sizeof( struct V_155 ) ) ;
* V_158 = V_79 -> V_158 ;
V_154 -> V_170 = F_90 ( V_22 , V_23 , V_122 ,
V_166 ,
F_91 ( V_154 ,
V_122 , 0 ) ) ;
if ( F_110 ( V_127 , V_7 -> V_11 , V_108 ,
V_151 , V_66 -> V_11 -> V_118 ,
V_127 -> V_67 ) < 0 ) {
F_111 ( V_127 ) ;
continue;
}
F_100 ( V_66 , V_127 ) ;
break;
}
F_57 ( & V_4 -> V_134 , V_8 ) ;
#endif
}
}
static bool F_118 ( struct V_6 * V_7 )
{
struct V_150 * V_79 ;
struct V_89 * V_152 ;
if ( V_7 -> V_106 != F_89 ( V_135 ) )
return false ;
if ( ! F_105 ( V_7 , sizeof( struct V_89 ) + sizeof( struct V_150 ) ) )
return false ;
V_79 = (struct V_150 * ) F_114 ( V_7 ) ;
F_115 ( V_7 , V_7 -> V_161 - F_114 ( V_7 ) ) ;
V_152 = F_93 ( V_7 ) ;
if ( V_152 -> V_103 != V_166 )
return false ;
if ( V_152 -> V_104 != 255 )
return false ;
if ( V_79 -> V_162 . V_163 != 0 )
return false ;
if ( V_79 -> V_162 . V_164 != V_165 )
return false ;
return true ;
}
int F_119 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
int V_132 , V_67 , V_21 , V_171 ;
int V_131 = 0 , V_172 ;
const struct V_84 * V_85 ;
struct V_19 * V_20 ;
struct V_65 * V_66 , * V_128 ;
T_6 V_93 ;
if ( F_101 ( & V_4 -> V_133 ) )
goto V_173;
if ( V_7 -> V_11 -> type != V_141 )
goto V_173;
if ( V_7 -> V_106 == F_89 ( V_135 ) && F_120 ( & V_37 ) ) {
F_41 ( & V_4 -> V_43 , V_7 ) ;
return 1 ;
} else if ( F_118 ( V_7 ) && F_120 ( & V_37 ) ) {
F_41 ( & V_4 -> V_43 , V_7 ) ;
return 1 ;
}
if ( V_7 -> V_106 == F_121 ( V_174 ) ) {
V_7 = F_122 ( V_7 ) ;
if ( F_78 ( ! V_7 ) )
goto V_173;
}
V_132 = F_103 ( F_104 ( V_7 ) -> V_107 ) ;
if ( V_132 != V_116 && V_132 != V_108 )
goto V_173;
if ( V_7 -> V_175 == V_176 )
goto V_173;
if ( F_123 ( V_7 ) )
goto V_173;
if ( V_132 == V_116 ) {
if ( ! F_105 ( V_7 , sizeof( struct V_84 ) ) )
goto V_173;
V_85 = (struct V_84 * ) V_7 -> V_161 ;
if ( V_85 -> V_115 < 5 || V_85 -> V_177 != 4 )
goto V_173;
if ( ! F_105 ( V_7 , V_85 -> V_115 * 4 ) )
goto V_173;
V_85 = (struct V_84 * ) V_7 -> V_161 ;
if ( F_99 ( ( T_5 * ) V_85 , V_85 -> V_115 ) != 0 )
goto V_173;
V_67 = F_103 ( V_85 -> V_111 ) ;
if ( V_7 -> V_67 < V_67 || V_67 < V_85 -> V_115 * 4 )
goto V_173;
if ( F_124 ( V_7 , V_67 ) )
goto V_173;
V_85 = (struct V_84 * ) V_7 -> V_161 ;
if ( V_85 -> V_106 != V_26 )
goto V_173;
V_67 -= V_85 -> V_115 * 4 ;
V_20 = (struct V_19 * ) ( ( ( char * ) V_85 ) + V_85 -> V_115 * 4 ) ;
V_172 = ( unsigned char * ) ( V_20 + 1 ) - V_7 -> V_161 ;
V_21 = F_103 ( V_20 -> V_67 ) ;
V_171 = V_7 -> V_67 - V_172 ;
V_93 = F_103 ( V_20 -> V_93 ) ;
if ( V_21 != V_67 )
goto V_173;
if ( F_17 ( V_7 , V_20 , V_21 , V_85 -> V_22 , V_85 -> V_23 ) )
goto V_173;
F_102 (np, tmp, &npinfo->rx_np, rx) {
if ( V_66 -> V_97 . V_109 && V_66 -> V_97 . V_109 != V_85 -> V_23 )
continue;
if ( V_66 -> V_99 . V_109 && V_66 -> V_99 . V_109 != V_85 -> V_22 )
continue;
if ( V_66 -> V_94 && V_66 -> V_94 != F_103 ( V_20 -> V_95 ) )
continue;
V_66 -> V_178 ( V_66 , V_93 , V_7 , V_172 , V_171 ) ;
V_131 ++ ;
}
} else {
#if F_112 ( V_149 )
const struct V_89 * V_90 ;
if ( ! F_105 ( V_7 , sizeof( struct V_89 ) ) )
goto V_173;
V_90 = (struct V_89 * ) V_7 -> V_161 ;
if ( V_90 -> V_177 != 6 )
goto V_173;
V_67 = F_103 ( V_90 -> V_102 ) ;
if ( ! V_67 )
goto V_173;
if ( V_67 + sizeof( struct V_89 ) > V_7 -> V_67 )
goto V_173;
if ( F_124 ( V_7 , V_67 + sizeof( struct V_89 ) ) )
goto V_173;
V_90 = F_93 ( V_7 ) ;
if ( ! F_105 ( V_7 , sizeof( struct V_19 ) ) )
goto V_173;
V_20 = F_88 ( V_7 ) ;
V_172 = ( unsigned char * ) ( V_20 + 1 ) - V_7 -> V_161 ;
V_21 = F_103 ( V_20 -> V_67 ) ;
V_171 = V_7 -> V_67 - V_172 ;
V_93 = F_103 ( V_20 -> V_93 ) ;
if ( V_21 != V_7 -> V_67 )
goto V_173;
if ( F_125 ( V_7 , V_20 , V_26 ) )
goto V_173;
F_102 (np, tmp, &npinfo->rx_np, rx) {
if ( ! F_116 ( & V_66 -> V_97 . V_98 , & V_90 -> V_23 ) )
continue;
if ( ! F_116 ( & V_66 -> V_99 . V_98 , & V_90 -> V_22 ) )
continue;
if ( V_66 -> V_94 && V_66 -> V_94 != F_103 ( V_20 -> V_95 ) )
continue;
V_66 -> V_178 ( V_66 , V_93 , V_7 , V_172 , V_171 ) ;
V_131 ++ ;
}
#endif
}
if ( ! V_131 )
goto V_173;
F_111 ( V_7 ) ;
return 1 ;
V_173:
if ( F_120 ( & V_37 ) ) {
F_111 ( V_7 ) ;
return 1 ;
}
return 0 ;
}
void F_126 ( struct V_65 * V_66 )
{
F_127 ( V_66 , L_2 , V_66 -> V_94 ) ;
if ( V_66 -> V_91 )
F_127 ( V_66 , L_3 , & V_66 -> V_97 . V_98 ) ;
else
F_127 ( V_66 , L_4 , & V_66 -> V_97 . V_109 ) ;
F_127 ( V_66 , L_5 , V_66 -> V_179 ) ;
F_127 ( V_66 , L_6 , V_66 -> V_96 ) ;
if ( V_66 -> V_91 )
F_127 ( V_66 , L_7 , & V_66 -> V_99 . V_98 ) ;
else
F_127 ( V_66 , L_8 , & V_66 -> V_99 . V_109 ) ;
F_127 ( V_66 , L_9 , V_66 -> V_121 ) ;
}
static int F_128 ( const char * V_180 , union V_181 * V_182 )
{
const char * V_183 ;
if ( ! strchr ( V_180 , ':' ) &&
F_129 ( V_180 , - 1 , ( void * ) V_182 , - 1 , & V_183 ) > 0 ) {
if ( ! * V_183 )
return 0 ;
}
if ( F_130 ( V_180 , - 1 , V_182 -> V_98 . V_184 , - 1 , & V_183 ) > 0 ) {
#if F_112 ( V_149 )
if ( ! * V_183 )
return 1 ;
#else
return - 1 ;
#endif
}
return - 1 ;
}
int F_131 ( struct V_65 * V_66 , char * V_185 )
{
char * V_186 = V_185 , * V_187 ;
int V_91 ;
if ( * V_186 != '@' ) {
if ( ( V_187 = strchr ( V_186 , '@' ) ) == NULL )
goto V_188;
* V_187 = 0 ;
if ( F_132 ( V_186 , 10 , & V_66 -> V_94 ) )
goto V_188;
V_186 = V_187 ;
}
V_186 ++ ;
if ( * V_186 != '/' ) {
if ( ( V_187 = strchr ( V_186 , '/' ) ) == NULL )
goto V_188;
* V_187 = 0 ;
V_91 = F_128 ( V_186 , & V_66 -> V_97 ) ;
if ( V_91 < 0 )
goto V_188;
else
V_66 -> V_91 = ( bool ) V_91 ;
V_186 = V_187 ;
}
V_186 ++ ;
if ( * V_186 != ',' ) {
if ( ( V_187 = strchr ( V_186 , ',' ) ) == NULL )
goto V_188;
* V_187 = 0 ;
F_133 ( V_66 -> V_179 , V_186 , sizeof( V_66 -> V_179 ) ) ;
V_186 = V_187 ;
}
V_186 ++ ;
if ( * V_186 != '@' ) {
if ( ( V_187 = strchr ( V_186 , '@' ) ) == NULL )
goto V_188;
* V_187 = 0 ;
if ( * V_186 == ' ' || * V_186 == '\t' )
F_127 ( V_66 , L_10 ) ;
if ( F_132 ( V_186 , 10 , & V_66 -> V_96 ) )
goto V_188;
V_186 = V_187 ;
}
V_186 ++ ;
if ( ( V_187 = strchr ( V_186 , '/' ) ) == NULL )
goto V_188;
* V_187 = 0 ;
V_91 = F_128 ( V_186 , & V_66 -> V_99 ) ;
if ( V_91 < 0 )
goto V_188;
else if ( V_66 -> V_91 != ( bool ) V_91 )
goto V_188;
else
V_66 -> V_91 = ( bool ) V_91 ;
V_186 = V_187 + 1 ;
if ( * V_186 != 0 ) {
if ( ! F_134 ( V_186 , V_66 -> V_121 ) )
goto V_188;
}
F_126 ( V_66 ) ;
return 0 ;
V_188:
F_127 ( V_66 , L_11 , V_186 ) ;
return - 1 ;
}
int F_135 ( struct V_65 * V_66 , struct V_10 * V_189 , T_7 V_190 )
{
struct V_3 * V_4 ;
const struct V_12 * V_13 ;
unsigned long V_8 ;
int V_191 ;
V_66 -> V_11 = V_189 ;
F_133 ( V_66 -> V_179 , V_189 -> V_78 , V_192 ) ;
F_136 ( & V_66 -> V_193 , V_194 ) ;
if ( ( V_189 -> V_195 & V_196 ) ||
! V_189 -> V_14 -> V_46 ) {
F_137 ( V_66 , L_12 ,
V_66 -> V_179 ) ;
V_191 = - V_197 ;
goto V_173;
}
if ( ! V_189 -> V_4 ) {
V_4 = F_138 ( sizeof( * V_4 ) , V_190 ) ;
if ( ! V_4 ) {
V_191 = - V_198 ;
goto V_173;
}
V_4 -> V_35 = 0 ;
F_139 ( & V_4 -> V_133 ) ;
F_140 ( & V_4 -> V_134 ) ;
F_141 ( & V_4 -> V_45 , 1 ) ;
F_142 ( & V_4 -> V_43 ) ;
F_142 ( & V_4 -> V_9 ) ;
F_143 ( & V_4 -> V_5 , F_1 ) ;
F_62 ( & V_4 -> V_199 , 1 ) ;
V_13 = V_66 -> V_11 -> V_14 ;
if ( V_13 -> V_200 ) {
V_191 = V_13 -> V_200 ( V_189 , V_4 , V_190 ) ;
if ( V_191 )
goto V_201;
}
} else {
V_4 = F_144 ( V_189 -> V_4 ) ;
F_25 ( & V_4 -> V_199 ) ;
}
V_4 -> V_65 = V_66 ;
if ( V_66 -> V_178 ) {
F_54 ( & V_4 -> V_134 , V_8 ) ;
V_4 -> V_35 |= V_202 ;
F_145 ( & V_66 -> V_203 , & V_4 -> V_133 ) ;
F_57 ( & V_4 -> V_134 , V_8 ) ;
}
F_146 ( V_189 -> V_4 , V_4 ) ;
return 0 ;
V_201:
F_147 ( V_4 ) ;
V_173:
return V_191 ;
}
int F_148 ( struct V_65 * V_66 )
{
struct V_10 * V_189 = NULL ;
struct V_204 * V_205 ;
int V_191 ;
F_149 () ;
if ( V_66 -> V_179 ) {
struct V_206 * V_206 = V_207 -> V_208 -> V_209 ;
V_189 = F_150 ( V_206 , V_66 -> V_179 ) ;
}
if ( ! V_189 ) {
F_137 ( V_66 , L_13 , V_66 -> V_179 ) ;
V_191 = - V_210 ;
goto V_211;
}
F_151 ( V_189 ) ;
if ( F_152 ( V_189 ) ) {
F_137 ( V_66 , L_14 , V_66 -> V_179 ) ;
V_191 = - V_212 ;
goto V_213;
}
if ( ! F_5 ( V_189 ) ) {
unsigned long V_214 , V_215 ;
F_127 ( V_66 , L_15 , V_66 -> V_179 ) ;
V_191 = F_153 ( V_189 ) ;
if ( V_191 ) {
F_137 ( V_66 , L_16 , V_189 -> V_78 ) ;
goto V_213;
}
F_154 () ;
V_215 = V_216 + V_18 / 10 ;
V_214 = V_216 + V_217 * V_18 ;
while ( ! F_155 ( V_189 ) ) {
if ( F_156 ( V_216 , V_214 ) ) {
F_157 ( V_66 , L_17 ) ;
break;
}
F_158 ( 1 ) ;
}
if ( F_159 ( V_216 , V_215 ) ) {
F_157 ( V_66 , L_18 ) ;
F_158 ( 4000 ) ;
}
F_149 () ;
}
if ( ! V_66 -> V_97 . V_109 ) {
if ( ! V_66 -> V_91 ) {
V_205 = F_160 ( V_189 ) ;
if ( ! V_205 || ! V_205 -> V_218 ) {
F_137 ( V_66 , L_19 ,
V_66 -> V_179 ) ;
V_191 = - V_219 ;
goto V_213;
}
V_66 -> V_97 . V_109 = V_205 -> V_218 -> V_220 ;
F_127 ( V_66 , L_20 , & V_66 -> V_97 . V_109 ) ;
} else {
#if F_112 ( V_149 )
struct V_156 * V_221 ;
V_191 = - V_219 ;
V_221 = F_161 ( V_189 ) ;
if ( V_221 ) {
struct V_222 * V_223 ;
F_162 ( & V_221 -> V_53 ) ;
F_31 (ifp, &idev->addr_list, if_list) {
if ( F_163 ( & V_223 -> V_182 ) & V_224 )
continue;
V_66 -> V_97 . V_98 = V_223 -> V_182 ;
V_191 = 0 ;
break;
}
F_164 ( & V_221 -> V_53 ) ;
}
if ( V_191 ) {
F_137 ( V_66 , L_21 ,
V_66 -> V_179 ) ;
goto V_213;
} else
F_127 ( V_66 , L_22 , & V_66 -> V_97 . V_98 ) ;
#else
F_137 ( V_66 , L_23 ,
V_66 -> V_179 ) ;
V_191 = - V_225 ;
goto V_213;
#endif
}
}
F_53 () ;
V_191 = F_135 ( V_66 , V_189 , V_226 ) ;
if ( V_191 )
goto V_213;
F_154 () ;
return 0 ;
V_213:
F_165 ( V_189 ) ;
V_211:
F_154 () ;
return V_191 ;
}
static int T_8 F_166 ( void )
{
F_142 ( & V_52 ) ;
return 0 ;
}
static void F_167 ( struct V_227 * V_227 )
{
struct V_3 * V_4 =
F_2 ( V_227 , struct V_3 , V_228 ) ;
F_168 ( & V_4 -> V_43 ) ;
F_168 ( & V_4 -> V_9 ) ;
F_169 ( & V_4 -> V_5 ) ;
F_170 ( & V_4 -> V_9 ) ;
F_169 ( & V_4 -> V_5 ) ;
F_147 ( V_4 ) ;
}
void F_171 ( struct V_65 * V_66 )
{
struct V_3 * V_4 ;
unsigned long V_8 ;
V_4 = F_144 ( V_66 -> V_11 -> V_4 ) ;
if ( ! V_4 )
return;
if ( ! F_101 ( & V_4 -> V_133 ) ) {
F_54 ( & V_4 -> V_134 , V_8 ) ;
F_172 ( & V_66 -> V_203 ) ;
if ( F_101 ( & V_4 -> V_133 ) )
V_4 -> V_35 &= ~ V_202 ;
F_57 ( & V_4 -> V_134 , V_8 ) ;
}
F_173 ( & V_51 ) ;
if ( F_174 ( & V_4 -> V_199 ) ) {
const struct V_12 * V_13 ;
V_13 = V_66 -> V_11 -> V_14 ;
if ( V_13 -> V_229 )
V_13 -> V_229 ( V_66 -> V_11 ) ;
F_146 ( V_66 -> V_11 -> V_4 , NULL ) ;
F_175 ( & V_4 -> V_228 , F_167 ) ;
}
}
static void V_194 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_2 ( V_2 , struct V_65 , V_193 ) ;
F_149 () ;
F_171 ( V_66 ) ;
F_154 () ;
F_147 ( V_66 ) ;
}
void F_176 ( struct V_65 * V_66 )
{
F_177 ( & V_66 -> V_193 ) ;
}
void F_178 ( struct V_65 * V_66 )
{
F_149 () ;
if ( ! V_66 -> V_11 )
goto V_173;
F_171 ( V_66 ) ;
F_165 ( V_66 -> V_11 ) ;
V_66 -> V_11 = NULL ;
V_173:
F_154 () ;
}
int F_179 ( void )
{
return F_120 ( & V_37 ) ;
}
void F_180 ( int V_230 )
{
if ( V_230 )
F_25 ( & V_37 ) ;
else
F_29 ( & V_37 ) ;
}
