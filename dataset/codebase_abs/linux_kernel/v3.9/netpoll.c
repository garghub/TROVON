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
if ( ! F_38 ( & V_44 -> V_45 ) )
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
int F_43 ( struct V_10 * V_11 )
{
struct V_3 * V_44 ;
int V_50 ;
F_44 () ;
V_50 = F_45 ( & V_51 ) ;
V_44 = F_46 ( V_11 -> V_4 , & V_51 ) ;
if ( V_44 )
F_47 ( & V_44 -> V_45 ) ;
F_48 ( & V_51 , V_50 ) ;
return 0 ;
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
V_9 = F_69 ( V_11 , V_7 ) ;
for ( V_73 = F_70 ( 1 ) / V_74 ;
V_73 > 0 ; -- V_73 ) {
if ( F_71 ( V_9 ) ) {
if ( ! F_72 ( V_9 ) ) {
if ( F_73 ( V_7 ) &&
! ( F_74 ( V_7 ) & V_75 ) ) {
V_7 = F_75 ( V_7 , F_76 ( V_7 ) ) ;
if ( F_77 ( ! V_7 ) )
break;
V_7 -> V_76 = 0 ;
}
V_71 = V_13 -> V_16 ( V_7 , V_11 ) ;
if ( V_71 == V_17 )
F_78 ( V_9 ) ;
}
F_14 ( V_9 ) ;
if ( V_71 == V_17 )
break;
}
F_37 ( V_66 -> V_11 ) ;
F_79 ( V_74 ) ;
}
F_80 ( ! F_67 () ,
L_1 ,
V_11 -> V_77 , V_13 -> V_16 ) ;
}
if ( V_71 != V_17 ) {
F_41 ( & V_4 -> V_9 , V_7 ) ;
F_16 ( & V_4 -> V_5 , 0 ) ;
}
}
void F_81 ( struct V_65 * V_66 , const char * V_78 , int V_67 )
{
int V_79 , V_80 , V_81 ;
struct V_6 * V_7 ;
struct V_19 * V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
static T_4 V_87 ;
struct V_88 * V_89 ;
V_81 = V_67 + sizeof( * V_82 ) ;
if ( V_66 -> V_90 )
V_80 = V_81 + sizeof( * V_89 ) ;
else
V_80 = V_81 + sizeof( * V_84 ) ;
V_79 = V_80 + F_82 ( V_66 -> V_11 ) ;
V_7 = F_61 ( V_66 , V_79 + V_66 -> V_11 -> V_91 ,
V_79 - V_67 ) ;
if ( ! V_7 )
return;
F_83 ( V_7 , V_78 , V_67 ) ;
F_84 ( V_7 , V_67 ) ;
F_85 ( V_7 , sizeof( * V_82 ) ) ;
F_86 ( V_7 ) ;
V_82 = F_87 ( V_7 ) ;
V_82 -> V_92 = F_88 ( V_66 -> V_93 ) ;
V_82 -> V_94 = F_88 ( V_66 -> V_95 ) ;
V_82 -> V_67 = F_88 ( V_81 ) ;
if ( V_66 -> V_90 ) {
V_82 -> V_25 = 0 ;
V_82 -> V_25 = F_89 ( & V_66 -> V_96 . V_97 ,
& V_66 -> V_98 . V_97 ,
V_81 , V_26 ,
F_90 ( V_82 , V_81 , 0 ) ) ;
if ( V_82 -> V_25 == 0 )
V_82 -> V_25 = V_99 ;
F_85 ( V_7 , sizeof( * V_89 ) ) ;
F_91 ( V_7 ) ;
V_89 = F_92 ( V_7 ) ;
F_93 ( 0x60 , ( unsigned char * ) V_89 ) ;
V_89 -> V_100 [ 0 ] = 0 ;
V_89 -> V_100 [ 1 ] = 0 ;
V_89 -> V_100 [ 2 ] = 0 ;
V_89 -> V_101 = F_88 ( sizeof( struct V_19 ) + V_67 ) ;
V_89 -> V_102 = V_26 ;
V_89 -> V_103 = 32 ;
V_89 -> V_22 = V_66 -> V_96 . V_97 ;
V_89 -> V_23 = V_66 -> V_98 . V_97 ;
V_86 = (struct V_85 * ) F_85 ( V_7 , V_104 ) ;
F_94 ( V_7 ) ;
V_7 -> V_105 = V_86 -> V_106 = F_88 ( V_107 ) ;
} else {
V_82 -> V_25 = 0 ;
V_82 -> V_25 = F_95 ( V_66 -> V_96 . V_108 ,
V_66 -> V_98 . V_108 ,
V_81 , V_26 ,
F_90 ( V_82 , V_81 , 0 ) ) ;
if ( V_82 -> V_25 == 0 )
V_82 -> V_25 = V_99 ;
F_85 ( V_7 , sizeof( * V_84 ) ) ;
F_91 ( V_7 ) ;
V_84 = F_96 ( V_7 ) ;
F_93 ( 0x45 , ( unsigned char * ) V_84 ) ;
V_84 -> V_109 = 0 ;
F_93 ( F_88 ( V_80 ) , & ( V_84 -> V_110 ) ) ;
V_84 -> V_111 = F_88 ( F_97 ( & V_87 ) ) ;
V_84 -> V_112 = 0 ;
V_84 -> V_113 = 64 ;
V_84 -> V_105 = V_26 ;
V_84 -> V_25 = 0 ;
F_93 ( V_66 -> V_96 . V_108 , & ( V_84 -> V_22 ) ) ;
F_93 ( V_66 -> V_98 . V_108 , & ( V_84 -> V_23 ) ) ;
V_84 -> V_25 = F_98 ( ( unsigned char * ) V_84 , V_84 -> V_114 ) ;
V_86 = (struct V_85 * ) F_85 ( V_7 , V_104 ) ;
F_94 ( V_7 ) ;
V_7 -> V_105 = V_86 -> V_106 = F_88 ( V_115 ) ;
}
memcpy ( V_86 -> V_116 , V_66 -> V_11 -> V_117 , V_118 ) ;
memcpy ( V_86 -> V_119 , V_66 -> V_120 , V_118 ) ;
V_7 -> V_11 = V_66 -> V_11 ;
F_99 ( V_66 , V_7 ) ;
}
static void F_36 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
int V_121 , type = V_122 ;
T_2 V_123 , V_124 ;
unsigned char * V_125 ;
struct V_6 * V_126 ;
struct V_65 * V_66 , * V_127 ;
unsigned long V_8 ;
int V_128 , V_129 ;
int V_130 = 0 , V_131 ;
if ( F_100 ( & V_4 -> V_132 ) )
return;
F_54 ( & V_4 -> V_133 , V_8 ) ;
F_101 (np, tmp, &npinfo->rx_np, rx) {
if ( V_66 -> V_11 == V_7 -> V_11 )
V_130 ++ ;
}
F_57 ( & V_4 -> V_133 , V_8 ) ;
if ( ! V_130 )
return;
V_131 = F_102 ( F_103 ( V_7 ) -> V_106 ) ;
if ( V_131 == V_115 ) {
struct V_134 * V_135 ;
unsigned char * V_136 ;
if ( V_7 -> V_11 -> V_8 & V_137 )
return;
if ( ! F_104 ( V_7 , F_105 ( V_7 -> V_11 ) ) )
return;
F_91 ( V_7 ) ;
F_86 ( V_7 ) ;
V_135 = F_106 ( V_7 ) ;
if ( ( V_135 -> V_138 != F_88 ( V_139 ) &&
V_135 -> V_138 != F_88 ( V_140 ) ) ||
V_135 -> V_141 != F_88 ( V_115 ) ||
V_135 -> V_142 != F_88 ( V_143 ) )
return;
V_136 = ( unsigned char * ) ( V_135 + 1 ) ;
V_125 = V_136 ;
V_136 += V_7 -> V_11 -> V_144 ;
memcpy ( & V_123 , V_136 , 4 ) ;
V_136 += 4 ;
V_136 += V_7 -> V_11 -> V_144 ;
memcpy ( & V_124 , V_136 , 4 ) ;
if ( F_107 ( V_124 ) || F_108 ( V_124 ) )
return;
V_121 = F_105 ( V_7 -> V_11 ) ;
F_54 ( & V_4 -> V_133 , V_8 ) ;
F_101 (np, tmp, &npinfo->rx_np, rx) {
if ( V_124 != V_66 -> V_96 . V_108 )
continue;
V_128 = F_82 ( V_66 -> V_11 ) ;
V_129 = V_66 -> V_11 -> V_91 ;
V_126 = F_61 ( V_66 , V_121 + V_128 + V_129 , V_128 ) ;
if ( ! V_126 )
continue;
F_91 ( V_126 ) ;
V_135 = (struct V_134 * ) F_84 ( V_126 , V_121 ) ;
V_126 -> V_11 = V_7 -> V_11 ;
V_126 -> V_105 = F_88 ( V_145 ) ;
if ( F_109 ( V_126 , V_7 -> V_11 , V_145 ,
V_125 , V_66 -> V_11 -> V_117 ,
V_126 -> V_67 ) < 0 ) {
F_110 ( V_126 ) ;
continue;
}
V_135 -> V_138 = F_88 ( V_66 -> V_11 -> type ) ;
V_135 -> V_141 = F_88 ( V_115 ) ;
V_135 -> V_146 = V_66 -> V_11 -> V_144 ;
V_135 -> V_147 = 4 ;
V_135 -> V_142 = F_88 ( type ) ;
V_136 = ( unsigned char * ) ( V_135 + 1 ) ;
memcpy ( V_136 , V_66 -> V_11 -> V_117 , V_66 -> V_11 -> V_144 ) ;
V_136 += V_66 -> V_11 -> V_144 ;
memcpy ( V_136 , & V_124 , 4 ) ;
V_136 += 4 ;
memcpy ( V_136 , V_125 , V_66 -> V_11 -> V_144 ) ;
V_136 += V_66 -> V_11 -> V_144 ;
memcpy ( V_136 , & V_123 , 4 ) ;
F_99 ( V_66 , V_126 ) ;
break;
}
F_57 ( & V_4 -> V_133 , V_8 ) ;
} else if( V_131 == V_107 ) {
#if F_111 ( V_148 )
struct V_149 * V_78 ;
T_5 * V_150 = NULL ;
struct V_88 * V_151 ;
struct V_152 * V_153 ;
const struct V_154 * V_22 ;
const struct V_154 * V_23 ;
struct V_155 * V_156 = NULL ;
struct V_154 * V_157 ;
V_156 = F_112 ( V_7 -> V_11 ) ;
if ( ! V_156 || ! V_156 -> V_158 . V_159 )
return;
if ( ! F_104 ( V_7 , V_7 -> V_67 ) )
return;
V_78 = (struct V_149 * ) F_113 ( V_7 ) ;
F_114 ( V_7 , V_7 -> V_160 - F_113 ( V_7 ) ) ;
if ( F_92 ( V_7 ) -> V_103 != 255 )
return;
if ( V_78 -> V_161 . V_162 != 0 )
return;
if ( V_78 -> V_161 . V_163 != V_164 )
return;
V_22 = & F_92 ( V_7 ) -> V_22 ;
V_23 = & F_92 ( V_7 ) -> V_23 ;
V_121 = sizeof( struct V_152 ) + sizeof( struct V_154 ) ;
F_54 ( & V_4 -> V_133 , V_8 ) ;
F_101 (np, tmp, &npinfo->rx_np, rx) {
if ( ! F_115 ( V_23 , & V_66 -> V_96 . V_97 ) )
continue;
V_128 = F_82 ( V_66 -> V_11 ) ;
V_129 = V_66 -> V_11 -> V_91 ;
V_126 = F_61 ( V_66 , V_121 + V_128 + V_129 , V_128 ) ;
if ( ! V_126 )
continue;
V_126 -> V_105 = F_88 ( V_107 ) ;
V_126 -> V_11 = V_7 -> V_11 ;
F_91 ( V_126 ) ;
F_84 ( V_126 , sizeof( struct V_88 ) ) ;
V_151 = F_92 ( V_126 ) ;
* ( T_2 * ) V_151 = F_116 ( 0x60000000 ) ;
V_151 -> V_101 = F_88 ( V_121 ) ;
V_151 -> V_102 = V_165 ;
V_151 -> V_103 = 255 ;
V_151 -> V_22 = * V_22 ;
V_151 -> V_23 = * V_23 ;
V_126 -> V_166 = V_126 -> V_167 ;
F_84 ( V_126 , V_121 ) ;
V_153 = (struct V_152 * ) F_113 ( V_7 ) ;
V_153 -> V_163 = V_168 ;
V_153 -> V_169 = 0 ;
V_153 -> V_170 = 1 ;
V_157 = (struct V_154 * ) ( F_113 ( V_126 ) + sizeof( struct V_152 ) ) ;
* V_157 = V_78 -> V_157 ;
V_153 -> V_171 = F_89 ( V_22 , V_23 , V_121 ,
V_165 ,
F_90 ( V_153 ,
V_121 , 0 ) ) ;
if ( F_109 ( V_126 , V_7 -> V_11 , V_107 ,
V_150 , V_66 -> V_11 -> V_117 ,
V_126 -> V_67 ) < 0 ) {
F_110 ( V_126 ) ;
continue;
}
F_99 ( V_66 , V_126 ) ;
break;
}
F_57 ( & V_4 -> V_133 , V_8 ) ;
#endif
}
}
static bool F_117 ( struct V_6 * V_7 )
{
struct V_149 * V_78 ;
struct V_88 * V_151 ;
if ( V_7 -> V_105 != F_88 ( V_145 ) )
return false ;
if ( ! F_104 ( V_7 , sizeof( struct V_88 ) + sizeof( struct V_149 ) ) )
return false ;
V_78 = (struct V_149 * ) F_113 ( V_7 ) ;
F_114 ( V_7 , V_7 -> V_160 - F_113 ( V_7 ) ) ;
V_151 = F_92 ( V_7 ) ;
if ( V_151 -> V_102 != V_165 )
return false ;
if ( V_151 -> V_103 != 255 )
return false ;
if ( V_78 -> V_161 . V_162 != 0 )
return false ;
if ( V_78 -> V_161 . V_163 != V_164 )
return false ;
return true ;
}
int F_118 ( struct V_6 * V_7 , struct V_3 * V_4 )
{
int V_131 , V_67 , V_21 ;
int V_130 = 0 ;
const struct V_83 * V_84 ;
struct V_19 * V_20 ;
struct V_65 * V_66 , * V_127 ;
if ( F_100 ( & V_4 -> V_132 ) )
goto V_172;
if ( V_7 -> V_11 -> type != V_139 )
goto V_172;
if ( V_7 -> V_105 == F_88 ( V_145 ) && F_119 ( & V_37 ) ) {
F_41 ( & V_4 -> V_43 , V_7 ) ;
return 1 ;
} else if ( F_117 ( V_7 ) && F_119 ( & V_37 ) ) {
F_41 ( & V_4 -> V_43 , V_7 ) ;
return 1 ;
}
if ( V_7 -> V_105 == F_120 ( V_173 ) ) {
V_7 = F_121 ( V_7 ) ;
if ( F_77 ( ! V_7 ) )
goto V_172;
}
V_131 = F_102 ( F_103 ( V_7 ) -> V_106 ) ;
if ( V_131 != V_115 && V_131 != V_107 )
goto V_172;
if ( V_7 -> V_174 == V_175 )
goto V_172;
if ( F_122 ( V_7 ) )
goto V_172;
if ( V_131 == V_115 ) {
if ( ! F_104 ( V_7 , sizeof( struct V_83 ) ) )
goto V_172;
V_84 = (struct V_83 * ) V_7 -> V_160 ;
if ( V_84 -> V_114 < 5 || V_84 -> V_176 != 4 )
goto V_172;
if ( ! F_104 ( V_7 , V_84 -> V_114 * 4 ) )
goto V_172;
V_84 = (struct V_83 * ) V_7 -> V_160 ;
if ( F_98 ( ( T_5 * ) V_84 , V_84 -> V_114 ) != 0 )
goto V_172;
V_67 = F_102 ( V_84 -> V_110 ) ;
if ( V_7 -> V_67 < V_67 || V_67 < V_84 -> V_114 * 4 )
goto V_172;
if ( F_123 ( V_7 , V_67 ) )
goto V_172;
V_84 = (struct V_83 * ) V_7 -> V_160 ;
if ( V_84 -> V_105 != V_26 )
goto V_172;
V_67 -= V_84 -> V_114 * 4 ;
V_20 = (struct V_19 * ) ( ( ( char * ) V_84 ) + V_84 -> V_114 * 4 ) ;
V_21 = F_102 ( V_20 -> V_67 ) ;
if ( V_21 != V_67 )
goto V_172;
if ( F_17 ( V_7 , V_20 , V_21 , V_84 -> V_22 , V_84 -> V_23 ) )
goto V_172;
F_101 (np, tmp, &npinfo->rx_np, rx) {
if ( V_66 -> V_96 . V_108 && V_66 -> V_96 . V_108 != V_84 -> V_23 )
continue;
if ( V_66 -> V_98 . V_108 && V_66 -> V_98 . V_108 != V_84 -> V_22 )
continue;
if ( V_66 -> V_93 && V_66 -> V_93 != F_102 ( V_20 -> V_94 ) )
continue;
V_66 -> V_177 ( V_66 , F_102 ( V_20 -> V_92 ) ,
( char * ) ( V_20 + 1 ) ,
V_21 - sizeof( struct V_19 ) ) ;
V_130 ++ ;
}
} else {
#if F_111 ( V_148 )
const struct V_88 * V_89 ;
if ( ! F_104 ( V_7 , sizeof( struct V_88 ) ) )
goto V_172;
V_89 = (struct V_88 * ) V_7 -> V_160 ;
if ( V_89 -> V_176 != 6 )
goto V_172;
V_67 = F_102 ( V_89 -> V_101 ) ;
if ( ! V_67 )
goto V_172;
if ( V_67 + sizeof( struct V_88 ) > V_7 -> V_67 )
goto V_172;
if ( F_123 ( V_7 , V_67 + sizeof( struct V_88 ) ) )
goto V_172;
V_89 = F_92 ( V_7 ) ;
if ( ! F_104 ( V_7 , sizeof( struct V_19 ) ) )
goto V_172;
V_20 = F_87 ( V_7 ) ;
V_21 = F_102 ( V_20 -> V_67 ) ;
if ( V_21 != V_7 -> V_67 )
goto V_172;
if ( F_124 ( V_7 , V_20 , V_26 ) )
goto V_172;
F_101 (np, tmp, &npinfo->rx_np, rx) {
if ( ! F_115 ( & V_66 -> V_96 . V_97 , & V_89 -> V_23 ) )
continue;
if ( ! F_115 ( & V_66 -> V_98 . V_97 , & V_89 -> V_22 ) )
continue;
if ( V_66 -> V_93 && V_66 -> V_93 != F_102 ( V_20 -> V_94 ) )
continue;
V_66 -> V_177 ( V_66 , F_102 ( V_20 -> V_92 ) ,
( char * ) ( V_20 + 1 ) ,
V_21 - sizeof( struct V_19 ) ) ;
V_130 ++ ;
}
#endif
}
if ( ! V_130 )
goto V_172;
F_110 ( V_7 ) ;
return 1 ;
V_172:
if ( F_119 ( & V_37 ) ) {
F_110 ( V_7 ) ;
return 1 ;
}
return 0 ;
}
void F_125 ( struct V_65 * V_66 )
{
F_126 ( V_66 , L_2 , V_66 -> V_93 ) ;
if ( V_66 -> V_90 )
F_126 ( V_66 , L_3 , & V_66 -> V_96 . V_97 ) ;
else
F_126 ( V_66 , L_4 , & V_66 -> V_96 . V_108 ) ;
F_126 ( V_66 , L_5 , V_66 -> V_178 ) ;
F_126 ( V_66 , L_6 , V_66 -> V_95 ) ;
if ( V_66 -> V_90 )
F_126 ( V_66 , L_7 , & V_66 -> V_98 . V_97 ) ;
else
F_126 ( V_66 , L_8 , & V_66 -> V_98 . V_108 ) ;
F_126 ( V_66 , L_9 , V_66 -> V_120 ) ;
}
static int F_127 ( const char * V_179 , union V_180 * V_181 )
{
const char * V_182 ;
if ( ! strchr ( V_179 , ':' ) &&
F_128 ( V_179 , - 1 , ( void * ) V_181 , - 1 , & V_182 ) > 0 ) {
if ( ! * V_182 )
return 0 ;
}
if ( F_129 ( V_179 , - 1 , V_181 -> V_97 . V_183 , - 1 , & V_182 ) > 0 ) {
#if F_111 ( V_148 )
if ( ! * V_182 )
return 1 ;
#else
return - 1 ;
#endif
}
return - 1 ;
}
int F_130 ( struct V_65 * V_66 , char * V_184 )
{
char * V_185 = V_184 , * V_186 ;
int V_90 ;
if ( * V_185 != '@' ) {
if ( ( V_186 = strchr ( V_185 , '@' ) ) == NULL )
goto V_187;
* V_186 = 0 ;
if ( F_131 ( V_185 , 10 , & V_66 -> V_93 ) )
goto V_187;
V_185 = V_186 ;
}
V_185 ++ ;
if ( * V_185 != '/' ) {
if ( ( V_186 = strchr ( V_185 , '/' ) ) == NULL )
goto V_187;
* V_186 = 0 ;
V_90 = F_127 ( V_185 , & V_66 -> V_96 ) ;
if ( V_90 < 0 )
goto V_187;
else
V_66 -> V_90 = ( bool ) V_90 ;
V_185 = V_186 ;
}
V_185 ++ ;
if ( * V_185 != ',' ) {
if ( ( V_186 = strchr ( V_185 , ',' ) ) == NULL )
goto V_187;
* V_186 = 0 ;
F_132 ( V_66 -> V_178 , V_185 , sizeof( V_66 -> V_178 ) ) ;
V_185 = V_186 ;
}
V_185 ++ ;
if ( * V_185 != '@' ) {
if ( ( V_186 = strchr ( V_185 , '@' ) ) == NULL )
goto V_187;
* V_186 = 0 ;
if ( * V_185 == ' ' || * V_185 == '\t' )
F_126 ( V_66 , L_10 ) ;
if ( F_131 ( V_185 , 10 , & V_66 -> V_95 ) )
goto V_187;
V_185 = V_186 ;
}
V_185 ++ ;
if ( ( V_186 = strchr ( V_185 , '/' ) ) == NULL )
goto V_187;
* V_186 = 0 ;
V_90 = F_127 ( V_185 , & V_66 -> V_98 ) ;
if ( V_90 < 0 )
goto V_187;
else if ( V_66 -> V_90 != ( bool ) V_90 )
goto V_187;
else
V_66 -> V_90 = ( bool ) V_90 ;
V_185 = V_186 + 1 ;
if ( * V_185 != 0 ) {
if ( ! F_133 ( V_185 , V_66 -> V_120 ) )
goto V_187;
}
F_125 ( V_66 ) ;
return 0 ;
V_187:
F_126 ( V_66 , L_11 , V_185 ) ;
return - 1 ;
}
int F_134 ( struct V_65 * V_66 , struct V_10 * V_188 , T_6 V_189 )
{
struct V_3 * V_4 ;
const struct V_12 * V_13 ;
unsigned long V_8 ;
int V_190 ;
V_66 -> V_11 = V_188 ;
F_132 ( V_66 -> V_178 , V_188 -> V_77 , V_191 ) ;
F_135 ( & V_66 -> V_192 , V_193 ) ;
if ( ( V_188 -> V_194 & V_195 ) ||
! V_188 -> V_14 -> V_46 ) {
F_136 ( V_66 , L_12 ,
V_66 -> V_178 ) ;
V_190 = - V_196 ;
goto V_172;
}
if ( ! V_188 -> V_4 ) {
V_4 = F_137 ( sizeof( * V_4 ) , V_189 ) ;
if ( ! V_4 ) {
V_190 = - V_197 ;
goto V_172;
}
V_4 -> V_35 = 0 ;
F_138 ( & V_4 -> V_132 ) ;
F_139 ( & V_4 -> V_133 ) ;
F_140 ( & V_4 -> V_45 ) ;
F_141 ( & V_4 -> V_43 ) ;
F_141 ( & V_4 -> V_9 ) ;
F_142 ( & V_4 -> V_5 , F_1 ) ;
F_62 ( & V_4 -> V_198 , 1 ) ;
V_13 = V_66 -> V_11 -> V_14 ;
if ( V_13 -> V_199 ) {
V_190 = V_13 -> V_199 ( V_188 , V_4 , V_189 ) ;
if ( V_190 )
goto V_200;
}
} else {
V_4 = F_143 ( V_188 -> V_4 ) ;
F_25 ( & V_4 -> V_198 ) ;
}
V_4 -> V_65 = V_66 ;
if ( V_66 -> V_177 ) {
F_54 ( & V_4 -> V_133 , V_8 ) ;
V_4 -> V_35 |= V_201 ;
F_144 ( & V_66 -> V_202 , & V_4 -> V_132 ) ;
F_57 ( & V_4 -> V_133 , V_8 ) ;
}
F_145 ( V_188 -> V_4 , V_4 ) ;
return 0 ;
V_200:
F_146 ( V_4 ) ;
V_172:
return V_190 ;
}
int F_147 ( struct V_65 * V_66 )
{
struct V_10 * V_188 = NULL ;
struct V_203 * V_204 ;
int V_190 ;
F_148 () ;
if ( V_66 -> V_178 ) {
struct V_205 * V_205 = V_206 -> V_207 -> V_208 ;
V_188 = F_149 ( V_205 , V_66 -> V_178 ) ;
}
if ( ! V_188 ) {
F_136 ( V_66 , L_13 , V_66 -> V_178 ) ;
V_190 = - V_209 ;
goto V_210;
}
F_150 ( V_188 ) ;
if ( F_151 ( V_188 ) ) {
F_136 ( V_66 , L_14 , V_66 -> V_178 ) ;
V_190 = - V_211 ;
goto V_212;
}
if ( ! F_5 ( V_188 ) ) {
unsigned long V_213 , V_214 ;
F_126 ( V_66 , L_15 , V_66 -> V_178 ) ;
V_190 = F_152 ( V_188 ) ;
if ( V_190 ) {
F_136 ( V_66 , L_16 , V_188 -> V_77 ) ;
goto V_212;
}
F_153 () ;
V_214 = V_215 + V_18 / 10 ;
V_213 = V_215 + V_216 * V_18 ;
while ( ! F_154 ( V_188 ) ) {
if ( F_155 ( V_215 , V_213 ) ) {
F_156 ( V_66 , L_17 ) ;
break;
}
F_157 ( 1 ) ;
}
if ( F_158 ( V_215 , V_214 ) ) {
F_156 ( V_66 , L_18 ) ;
F_157 ( 4000 ) ;
}
F_148 () ;
}
if ( ! V_66 -> V_96 . V_108 ) {
if ( ! V_66 -> V_90 ) {
V_204 = F_159 ( V_188 ) ;
if ( ! V_204 || ! V_204 -> V_217 ) {
F_136 ( V_66 , L_19 ,
V_66 -> V_178 ) ;
V_190 = - V_218 ;
goto V_212;
}
V_66 -> V_96 . V_108 = V_204 -> V_217 -> V_219 ;
F_126 ( V_66 , L_20 , & V_66 -> V_96 . V_108 ) ;
} else {
#if F_111 ( V_148 )
struct V_155 * V_220 ;
V_190 = - V_218 ;
V_220 = F_160 ( V_188 ) ;
if ( V_220 ) {
struct V_221 * V_222 ;
F_161 ( & V_220 -> V_53 ) ;
F_31 (ifp, &idev->addr_list, if_list) {
if ( F_162 ( & V_222 -> V_181 ) & V_223 )
continue;
V_66 -> V_96 . V_97 = V_222 -> V_181 ;
V_190 = 0 ;
break;
}
F_163 ( & V_220 -> V_53 ) ;
}
if ( V_190 ) {
F_136 ( V_66 , L_21 ,
V_66 -> V_178 ) ;
goto V_212;
} else
F_126 ( V_66 , L_22 , & V_66 -> V_96 . V_97 ) ;
#else
F_136 ( V_66 , L_23 ,
V_66 -> V_178 ) ;
V_190 = - V_224 ;
goto V_212;
#endif
}
}
F_53 () ;
V_190 = F_134 ( V_66 , V_188 , V_225 ) ;
if ( V_190 )
goto V_212;
F_153 () ;
return 0 ;
V_212:
F_164 ( V_188 ) ;
V_210:
F_153 () ;
return V_190 ;
}
static int T_7 F_165 ( void )
{
F_141 ( & V_52 ) ;
F_166 ( & V_51 ) ;
return 0 ;
}
static void F_167 ( struct V_226 * V_226 )
{
struct V_3 * V_4 =
F_2 ( V_226 , struct V_3 , V_227 ) ;
F_168 ( & V_4 -> V_43 ) ;
F_168 ( & V_4 -> V_9 ) ;
F_169 ( & V_4 -> V_5 ) ;
F_170 ( & V_4 -> V_9 ) ;
F_169 ( & V_4 -> V_5 ) ;
F_146 ( V_4 ) ;
}
void F_171 ( struct V_65 * V_66 )
{
struct V_3 * V_4 ;
unsigned long V_8 ;
V_4 = F_143 ( V_66 -> V_11 -> V_4 ) ;
if ( ! V_4 )
return;
if ( ! F_100 ( & V_4 -> V_132 ) ) {
F_54 ( & V_4 -> V_133 , V_8 ) ;
F_172 ( & V_66 -> V_202 ) ;
if ( F_100 ( & V_4 -> V_132 ) )
V_4 -> V_35 &= ~ V_201 ;
F_57 ( & V_4 -> V_133 , V_8 ) ;
}
F_173 ( & V_51 ) ;
if ( F_174 ( & V_4 -> V_198 ) ) {
const struct V_12 * V_13 ;
V_13 = V_66 -> V_11 -> V_14 ;
if ( V_13 -> V_228 )
V_13 -> V_228 ( V_66 -> V_11 ) ;
F_145 ( V_66 -> V_11 -> V_4 , NULL ) ;
F_175 ( & V_4 -> V_227 , F_167 ) ;
}
}
static void V_193 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = F_2 ( V_2 , struct V_65 , V_192 ) ;
F_148 () ;
F_171 ( V_66 ) ;
F_153 () ;
F_146 ( V_66 ) ;
}
void F_176 ( struct V_65 * V_66 )
{
F_177 ( & V_66 -> V_192 ) ;
}
void F_178 ( struct V_65 * V_66 )
{
if ( ! V_66 -> V_11 )
return;
F_148 () ;
F_171 ( V_66 ) ;
F_153 () ;
F_164 ( V_66 -> V_11 ) ;
V_66 -> V_11 = NULL ;
}
int F_179 ( void )
{
return F_119 ( & V_37 ) ;
}
void F_180 ( int V_229 )
{
if ( V_229 )
F_25 ( & V_37 ) ;
else
F_29 ( & V_37 ) ;
}
