static T_1 F_1 ( T_1 V_1 )
{
if ( ++ V_2 == 0 )
V_2 = 1 ;
if ( V_2 == V_1 ) {
if ( ++ V_2 == 0 )
V_2 = 1 ;
}
return V_2 ;
}
static void F_2 ( struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_11 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 = sizeof( struct V_11 ) + sizeof( struct V_12 ) +
sizeof( struct V_14 ) ;
V_7 = F_3 ( V_16 + F_4 ( V_9 ) , V_17 ) ;
if ( V_7 == 0 )
return;
F_5 ( V_7 , F_6 ( V_9 ) ) ;
F_7 ( V_7 ) ;
V_11 = (struct V_11 * ) F_8 ( V_7 , V_16 ) ;
V_13 = (struct V_12 * ) ( V_11 + 1 ) ;
V_15 = (struct V_14 * ) ( V_13 + 1 ) ;
V_7 -> V_9 = V_9 ;
V_7 -> V_18 = F_9 ( V_19 ) ;
if ( F_10 ( V_7 , V_9 , V_19 , V_4 -> V_20 ,
V_9 -> V_21 , V_7 -> V_22 ) < 0 ) {
F_11 ( V_7 ) ;
return;
}
V_11 -> V_23 = ( V_24 << V_25 ) ;
V_11 -> V_26 = 0 ;
F_12 ( 0 , & V_11 -> V_27 ) ;
F_13 ( V_28 , 0 , 0 , 0 , 0 ) ;
V_13 -> type = V_29 ;
V_13 -> V_30 = sizeof( struct V_14 ) ;
memset ( V_15 , 0 , sizeof( struct V_14 ) ) ;
V_15 -> V_5 = V_5 ;
if ( V_5 == 0 ) {
V_15 -> V_31 = V_4 -> V_31 ;
V_15 -> V_32 = V_4 -> V_32 ;
F_12 ( F_14 ( V_4 -> V_33 ) , & V_15 -> V_34 ) ;
}
F_15 ( L_1 , V_5 ) ;
F_16 ( V_7 ) ;
return;
}
static void F_17 ( struct V_3 * V_4 , T_1 V_35 )
{
unsigned long V_36 = V_35 & V_37 ;
switch ( V_35 & V_38 ) {
case V_39 :
V_4 -> V_40 =
F_18 ( V_36 * 1000 * 60 * 60 * 24 * 20 ) ;
break;
case V_41 :
V_4 -> V_40 = F_18 ( V_36 * 1000 ) ;
break;
case V_42 :
V_4 -> V_40 = F_18 ( V_36 * 1000 * 60 ) ;
break;
case V_43 :
V_4 -> V_40 = F_18 ( V_36 * 1000 * 60 * 60 ) ;
break;
default:
V_4 -> V_40 = 0 ;
}
F_15 ( L_2 , V_4 -> V_40 ) ;
}
static void F_19 ( struct V_3 * V_4 , T_1 V_44 )
{
if ( V_44 )
V_4 -> V_45 = F_18 ( V_44 * 100 ) ;
else
V_4 -> V_45 = V_46 ;
F_15 ( L_3 , V_4 -> V_45 ) ;
}
static struct V_3 * F_20 ( struct V_3 * V_47 , struct V_12 * V_13 ,
T_1 * V_48 , struct V_8 * V_10 )
{
struct V_3 * V_4 ;
struct V_49 * V_15 =
(struct V_49 * ) ( V_13 + 1 ) ;
T_1 V_50 = V_51 ;
T_1 V_52 = 0 ;
T_2 V_53 = V_54 ;
struct V_8 * V_55 = 0 ;
struct V_3 * V_56 = 0 ;
if ( V_47 ) {
V_4 = V_47 ;
F_21 ( & V_57 ) ;
} else {
struct V_3 * V_58 = 0 ;
struct V_59 * V_60 ;
V_4 = F_22 ( V_48 ) ;
if ( V_4 == 0 )
return 0 ;
V_4 -> V_61 = V_62 ;
F_21 ( & V_57 ) ;
F_23 (e, &g_pd_list) {
V_58 = F_24 ( V_60 , struct V_3 , V_63 ) ;
if ( memcmp ( V_58 -> V_20 , V_48 , V_64 ) == 0 ) {
V_56 = V_4 ;
V_4 = V_58 ;
break;
}
}
if ( V_4 != V_58 )
F_25 ( & V_4 -> V_63 , & V_65 ) ;
}
if ( V_4 == 0 ) {
F_26 ( & V_57 ) ;
return 0 ;
}
if ( V_4 -> V_10 != V_10 ) {
V_55 = V_4 -> V_10 ;
F_27 ( V_10 ) ;
V_4 -> V_10 = V_10 ;
}
F_15 ( L_4 , V_15 -> V_66 ) ;
V_4 -> V_67 = V_68 ;
V_4 -> V_31 = V_15 -> V_31 ;
V_4 -> V_69 = V_15 -> V_69 ;
if ( V_4 -> V_31 & V_70 ) {
V_4 -> V_71 = V_15 -> V_71 ;
if ( ! V_4 -> V_71 )
V_4 -> V_71 = 4 ;
}
if ( V_15 -> V_72 )
V_4 -> V_67 = ( ( T_2 ) V_15 -> V_72 ) << 4 ;
F_15 ( L_5 ,
V_4 -> V_67 , V_4 -> V_71 ) ;
V_4 -> V_73 = 3 * 1024 ;
V_4 -> V_74 = V_62 + V_75 ;
V_4 -> V_76 = V_77 ;
F_19 ( V_4 , V_15 -> V_44 ) ;
F_17 ( V_4 , V_15 -> V_36 ) ;
V_53 &= F_28 ( F_29 ( & V_15 -> V_34 ) ) ;
if ( ( V_53 & 0x1 ) && ( V_15 -> V_32 ) ) {
if ( V_4 -> V_32 ) {
if ( V_4 -> V_32 != V_15 -> V_32 ) {
V_50 = V_78 ;
goto V_79;
}
} else {
V_53 &= ~ 0x1 ;
V_4 -> V_32 =
F_1 ( V_15 -> V_32 ) ;
}
} else {
if ( V_4 -> V_32 && ! V_15 -> V_32 ) {
V_50 = V_80 ;
V_52 = 1 ;
} else {
V_53 &= ~ 0x1 ;
V_4 -> V_32 =
F_1 ( V_15 -> V_32 ) ;
}
}
V_79:
if ( V_50 == V_51 ) {
T_2 V_81 = V_53 & ~ V_4 -> V_33 & ~ 0x1 ;
T_2 V_82 = V_4 -> V_33 & ~ V_53 & ~ 0x1 ;
T_2 V_83 = V_53 & V_4 -> V_84 & ~ 0x1 ;
F_26 ( & V_57 ) ;
F_30 ( V_4 , V_85 ) ;
F_31 ( V_4 , V_86 ) ;
F_15 ( L_6 ,
V_53 , V_4 -> V_33 , V_4 -> V_84 ) ;
if ( V_81 ) {
if ( F_32 ( V_4 , V_81 , 0 ) )
V_50 = V_87 ;
}
if ( V_83 )
if ( F_32 ( V_4 , V_83 , 1 ) )
V_50 = V_87 ;
if ( V_82 )
F_33 ( V_4 , V_82 , 0 ) ;
F_34 ( V_4 ) ;
} else {
F_26 ( & V_57 ) ;
}
F_2 ( V_4 , V_50 ) ;
if ( V_50 != V_51 ) {
if ( V_52 )
F_35 ( V_4 ) ;
F_36 ( V_4 ) ;
V_4 = 0 ;
}
if ( V_55 )
F_37 ( V_55 ) ;
if ( V_56 )
F_38 ( V_56 ) ;
return V_4 ;
}
static void F_39 ( struct V_3 * V_4 , T_1 V_88 , T_1 V_89 ,
T_1 * V_90 , T_1 V_22 )
{
struct V_91 * V_92 ;
struct V_91 * V_93 ;
int V_94 = 0 ;
V_92 = F_40 ( sizeof( struct V_91 ) + V_22 - 1 , V_17 ) ;
if ( ! V_92 )
return;
V_92 -> V_88 = V_88 ;
V_92 -> V_89 = V_89 ;
memcpy ( V_92 -> V_90 , V_90 , V_22 ) ;
F_15 ( L_7 ) ;
F_41 ( & V_57 ) ;
F_42 (f2, &pd->farewell_list, link) {
if ( ( V_93 -> V_88 == V_88 ) && ( V_93 -> V_89 == V_89 ) ) {
V_94 = 1 ;
F_43 ( & V_93 -> V_63 ) ;
break;
}
}
F_25 ( & V_92 -> V_63 , & V_4 -> V_95 ) ;
F_44 ( & V_57 ) ;
if ( V_94 )
F_45 ( V_93 ) ;
}
static void F_46 ( struct V_6 * V_7 )
{
T_1 * V_96 ;
T_1 * V_97 ;
struct V_12 * V_13 ;
int V_30 ;
struct V_3 * V_4 = 0 ;
struct V_11 * V_11 = (struct V_11 * ) F_47 ( V_7 ) ;
int V_98 = 0 ;
T_3 V_27 ;
F_13 ( V_99 , 0 ,
( ( ( T_2 ) V_11 -> V_23 ) << 8 ) | V_11 -> V_26 ,
0 , V_11 -> V_27 ) ;
F_48 ( V_100 ,
L_8 ,
V_11 -> V_27 , V_11 -> V_26 , V_11 -> V_23 ) ;
V_96 = F_49 ( V_7 ) ;
V_97 = & V_96 [ V_64 ] ;
V_30 = V_7 -> V_22 ;
if ( F_50 ( V_11 -> V_23 ) != V_24 ) {
F_15 ( L_9 ,
F_50 ( V_11 -> V_23 ) ) ;
goto V_79;
}
V_27 = F_51 ( F_29 ( & V_11 -> V_27 ) ) ;
V_4 = F_52 ( V_97 ) ;
if ( V_4 ) {
V_4 -> V_61 = V_62 ;
F_53 ( V_4 , V_101 ,
V_4 -> V_61 + V_4 -> V_45 , 1 ) ;
if ( V_27 != V_4 -> V_102 ) {
V_4 -> V_102 = V_27 ;
} else {
V_98 = 1 ;
F_15 ( L_10 ) ;
}
}
if ( V_4 && ! V_98 && ( ( V_4 -> V_31 & V_103 ) == V_104 ) ) {
F_48 ( V_100 , L_11 ) ;
V_4 -> V_105 = & V_4 -> V_106 ;
if ( V_11 -> V_23 & V_107 ) {
F_54 ( V_4 , V_11 -> V_26 ) ;
}
if ( ( V_11 -> V_23 & V_108 ) &&
( V_4 -> V_109 == V_85 ) ) {
int V_110 = V_4 -> V_111 ;
V_4 -> V_112 = V_27 ;
F_55 ( V_4 , V_110 ) ;
}
}
V_30 -= sizeof( struct V_11 ) ;
V_13 = (struct V_12 * ) ( ( T_1 * ) V_11 + sizeof( struct V_11 ) ) ;
while ( V_30 >= sizeof( struct V_12 ) ) {
V_30 -= sizeof( struct V_12 ) + V_13 -> V_30 ;
if ( V_30 < 0 )
break;
switch ( V_13 -> type ) {
case V_113 :
F_13 ( V_114 , 0 , 0 , 0 , 0 ) ;
F_15 ( L_12 ) ;
V_4 = F_20 ( V_4 , V_13 , V_97 , V_7 -> V_9 ) ;
break;
case V_115 :
F_15 ( L_13 ) ;
if ( V_4 )
F_56 ( V_4 ) ;
break;
case V_116 : {
struct V_117 * V_15 =
(struct V_117 * ) ( V_13 + 1 ) ;
F_15 ( L_14 ) ;
if ( V_4 && ( V_4 -> V_109 & V_85 ) ) {
F_41 ( & V_57 ) ;
F_17 ( V_4 , V_15 -> V_118 ) ;
F_19 ( V_4 , V_15 -> V_44 ) ;
F_44 ( & V_57 ) ;
}
}
break;
case V_119 : {
struct V_120 * V_15 =
(struct V_120 * ) ( V_13 + 1 ) ;
F_15 ( L_15 ) ;
F_39 ( V_4 , V_15 -> V_88 ,
V_15 -> V_89 , V_15 -> V_90 ,
V_13 -> V_30 + 1 - sizeof( * V_15 ) ) ;
}
break;
case V_121 :
if ( V_4 && ( V_4 -> V_109 & V_85 ) ) {
struct V_122 * V_123 =
(struct V_122 * ) ( V_13 + 1 ) ;
if ( V_98 )
break;
F_57 ( V_4 , V_123 -> V_124 , V_13 ) ;
}
break;
default:
F_15 ( L_16 , V_13 -> type ) ;
}
V_13 = F_58 ( V_13 ) ;
}
V_79:
if ( V_4 )
F_36 ( V_4 ) ;
F_59 ( V_7 ) ;
}
void F_60 ( void )
{
struct V_59 * V_125 = 0 ;
F_61 ( & V_126 ) ;
F_21 ( & V_127 ) ;
while ( V_128 ) {
struct V_129 * V_130 = V_128 ;
V_128 = V_130 -> V_131 ;
F_26 ( & V_127 ) ;
F_62 ( & V_130 -> V_132 ) ;
if ( V_130 -> V_132 . V_9 )
F_37 ( V_130 -> V_132 . V_9 ) ;
F_45 ( V_130 ) ;
F_21 ( & V_127 ) ;
}
F_26 ( & V_127 ) ;
F_21 ( & V_57 ) ;
while ( ! F_63 ( & V_65 ) ) {
struct V_3 * V_4 =
F_64 ( & V_65 , struct V_3 , V_63 ) ;
F_65 ( V_4 ) ;
F_26 ( & V_57 ) ;
F_35 ( V_4 ) ;
F_36 ( V_4 ) ;
F_21 ( & V_57 ) ;
}
V_125 = V_133 ;
V_133 = 0 ;
F_26 ( & V_57 ) ;
while ( V_125 ) {
struct V_134 * V_135 = F_24 ( V_125 , struct V_134 , V_63 ) ;
V_125 = V_125 -> V_131 ;
F_45 ( V_135 ) ;
}
F_15 ( L_17 ) ;
}
static void F_66 ( struct V_3 * V_4 , int type )
{
switch ( type ) {
case V_101 :
F_56 ( V_4 ) ;
break;
case V_86 :
F_35 ( V_4 ) ;
break;
case V_136 : {
T_2 V_34 = 0 ;
F_21 ( & V_57 ) ;
V_4 -> V_137 = 0 ;
if ( V_4 -> V_109 & V_85 )
V_34 = V_4 -> V_33 ;
F_26 ( & V_57 ) ;
if ( V_34 )
F_67 ( V_4 , V_34 ) ;
}
break;
}
}
static void F_68 ( unsigned long V_138 )
{
struct V_134 * V_135 ;
struct V_134 * V_139 ;
struct V_3 * V_4 ;
F_21 ( & V_57 ) ;
if ( ! V_140 ) {
F_13 ( V_141 , 0 , 0 , 0 , 0 ) ;
F_26 ( & V_57 ) ;
return;
}
V_142 = V_143 ;
V_135 = V_140 ;
V_140 = 0 ;
F_43 ( & V_135 -> V_63 ) ;
F_26 ( & V_57 ) ;
do {
V_4 = V_135 -> V_4 ;
F_13 ( V_141 , 0 , V_135 -> type , 0 , 0 ) ;
F_66 ( V_4 , V_135 -> type ) ;
F_21 ( & V_57 ) ;
if ( V_144 < V_145 ) {
V_135 -> V_63 . V_131 = V_133 ;
V_133 = & V_135 -> V_63 ;
V_144 ++ ;
V_135 = 0 ;
}
if ( ! F_63 ( & V_146 ) ) {
V_139 = F_24 ( V_146 . V_131 ,
struct V_134 , V_63 ) ;
if ( F_69 ( V_139 -> V_147 , V_62 ) )
F_43 ( & V_139 -> V_63 ) ;
else
V_139 = 0 ;
} else {
V_139 = 0 ;
}
F_26 ( & V_57 ) ;
F_36 ( V_4 ) ;
if ( V_135 )
F_45 ( V_135 ) ;
V_135 = V_139 ;
} while ( V_135 );
V_142 = V_148 ;
F_70 () ;
}
static void F_70 ( void )
{
F_21 ( & V_57 ) ;
if ( ! F_63 ( & V_146 ) ) {
V_140 =
F_24 ( V_146 . V_131 , struct V_134 , V_63 ) ;
if ( V_142 == V_149 ) {
F_13 ( V_150 , 3 ,
( T_2 ) V_140 -> type , 0 ,
( unsigned ) V_140 -> V_147 ) ;
F_71 ( & V_126 , V_140 -> V_147 ) ;
} else {
F_13 ( V_150 , 4 ,
( T_2 ) V_140 -> type , 0 ,
( unsigned ) V_140 -> V_147 ) ;
V_126 . V_151 = V_140 -> V_147 ;
V_126 . V_152 = F_68 ;
V_126 . V_153 = 0 ;
F_72 ( & V_126 ) ;
}
V_142 = V_149 ;
} else {
F_15 ( L_18 ) ;
}
F_26 ( & V_57 ) ;
}
void F_53 ( struct V_3 * V_4 , int type , unsigned long V_147 ,
int remove )
{
struct V_59 * V_60 ;
struct V_134 * V_135 = 0 ;
int V_154 = 0 ;
F_13 ( V_150 , 1 , ( T_2 ) type , 0 , ( unsigned ) V_147 ) ;
F_41 ( & V_57 ) ;
if ( remove ) {
F_23 (e, &g_timer_list) {
V_135 = F_24 ( V_60 , struct V_134 , V_63 ) ;
if ( ( V_135 -> V_4 == V_4 ) && ( V_135 -> type == type ) ) {
if ( V_140 == V_135 ) {
V_154 = 1 ;
V_140 = 0 ;
}
F_43 ( V_60 ) ;
break;
}
V_135 = 0 ;
}
}
if ( ! V_135 ) {
if ( V_133 ) {
V_135 = F_24 ( V_133 , struct V_134 , V_63 ) ;
V_133 = V_133 -> V_131 ;
V_144 -- ;
} else {
V_135 = F_40 ( sizeof( struct V_134 ) , V_17 ) ;
}
if ( V_135 ) {
V_135 -> V_4 = V_4 ;
V_135 -> type = type ;
F_65 ( V_4 ) ;
}
}
if ( V_135 ) {
struct V_134 * V_139 ;
V_135 -> V_147 = V_147 ;
F_23 (e, &g_timer_list) {
V_139 = F_24 ( V_60 , struct V_134 , V_63 ) ;
if ( F_73 ( V_147 , V_139 -> V_147 ) ) {
if ( V_139 == V_140 ) {
V_140 = 0 ;
V_154 = 1 ;
}
break;
}
}
F_25 ( & V_135 -> V_63 , V_60 ) ;
}
if ( V_142 == V_148 )
V_154 = 1 ;
else if ( V_142 == V_143 )
V_154 = 0 ;
F_44 ( & V_57 ) ;
if ( V_154 )
F_70 () ;
}
void F_31 ( struct V_3 * V_4 , int type )
{
struct V_59 * V_125 = 0 ;
struct V_134 * V_135 ;
struct V_134 * V_155 ;
int V_154 = 0 ;
int V_156 = 0 ;
F_13 ( V_150 , 2 , ( T_2 ) type , 0 , 0 ) ;
F_41 ( & V_57 ) ;
F_74 (t, n, &g_timer_list, link) {
if ( ( V_135 -> V_4 == V_4 ) && ( ( type == 0 ) || ( V_135 -> type == type ) ) ) {
if ( V_140 == V_135 ) {
V_154 = 1 ;
V_140 = 0 ;
F_75 ( & V_126 ) ;
}
F_43 ( & V_135 -> V_63 ) ;
V_156 ++ ;
if ( V_144 < V_145 ) {
V_135 -> V_63 . V_131 = V_133 ;
V_133 = & V_135 -> V_63 ;
V_144 ++ ;
} else {
V_135 -> V_63 . V_131 = V_125 ;
V_125 = & V_135 -> V_63 ;
}
if ( type )
break;
}
}
if ( V_142 == V_143 )
V_154 = 0 ;
else if ( V_154 )
V_142 = V_148 ;
F_44 ( & V_57 ) ;
if ( V_154 )
F_70 () ;
while ( V_156 -- )
F_36 ( V_4 ) ;
while ( V_125 ) {
V_135 = F_24 ( V_125 , struct V_134 , V_63 ) ;
V_125 = V_125 -> V_131 ;
F_45 ( V_135 ) ;
}
}
void F_34 ( struct V_3 * V_4 )
{
unsigned long V_157 = V_62 ;
unsigned long V_135 ;
F_41 ( & V_57 ) ;
if ( V_4 -> V_137 ) {
F_44 ( & V_57 ) ;
return;
}
if ( V_4 -> V_76 )
V_135 = ( ( V_157 / V_4 -> V_76 ) + 1 ) * V_4 -> V_76 ;
else
V_135 = V_157 + 1 ;
V_4 -> V_137 = 1 ;
F_44 ( & V_57 ) ;
F_53 ( V_4 , V_136 , V_135 , 0 ) ;
}
struct V_3 * F_52 ( T_1 * V_20 )
{
struct V_3 * V_4 ;
struct V_59 * V_60 ;
F_21 ( & V_57 ) ;
F_23 (e, &g_pd_list) {
V_4 = F_24 ( V_60 , struct V_3 , V_63 ) ;
if ( memcmp ( V_4 -> V_20 , V_20 , V_64 ) == 0 ) {
F_76 ( & V_4 -> V_158 ) ;
F_26 ( & V_57 ) ;
return V_4 ;
}
}
F_26 ( & V_57 ) ;
return 0 ;
}
void F_77 ( int V_124 , int V_159 )
{
if ( V_124 <= V_160 ) {
F_21 ( & V_57 ) ;
if ( V_159 )
V_54 |= ( 1 << V_124 ) ;
else
V_54 &= ~ ( 1 << V_124 ) ;
F_26 ( & V_57 ) ;
}
}
static int F_78 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_161 * V_162 , struct V_8 * V_163 )
{
F_13 ( V_164 , 0 , 0 , 0 , 0 ) ;
V_7 = F_79 ( V_7 , V_17 ) ;
if ( V_7 == 0 )
return 0 ;
F_21 ( & V_165 . V_166 ) ;
if ( V_167 ) {
F_80 ( & V_165 , V_7 ) ;
F_26 ( & V_165 . V_166 ) ;
} else {
V_167 = 1 ;
do {
F_26 ( & V_165 . V_166 ) ;
F_46 ( V_7 ) ;
F_21 ( & V_165 . V_166 ) ;
if ( F_81 ( & V_165 ) ) {
V_167 = 0 ;
F_26 ( & V_165 . V_166 ) ;
break;
}
V_7 = F_82 ( & V_165 ) ;
} while ( 1 );
}
return 0 ;
}
void F_83 ( char * V_10 )
{
struct V_129 * V_168 ;
V_168 = F_40 ( sizeof( struct V_129 ) , V_169 ) ;
if ( V_168 ) {
V_168 -> V_132 . type = F_84 ( V_19 ) ;
V_168 -> V_132 . V_170 = F_78 ;
memcpy ( V_168 -> V_171 , V_10 , V_172 ) ;
if ( V_10 && * V_10 ) {
F_15 ( L_19 , V_10 ) ;
V_168 -> V_132 . V_9 =
F_85 ( & V_173 , V_10 ) ;
if ( V_168 -> V_132 . V_9 == 0 ) {
F_15 ( L_20 , V_10 ) ;
F_45 ( V_168 ) ;
V_168 = 0 ;
}
} else {
F_15 ( L_21 ) ;
V_168 -> V_132 . V_9 = 0 ;
}
if ( V_168 ) {
F_86 ( & V_168 -> V_132 ) ;
F_21 ( & V_127 ) ;
V_168 -> V_131 = V_128 ;
V_128 = V_168 ;
F_26 ( & V_127 ) ;
}
}
}
static int F_87 ( char * V_174 , char * V_175 )
{
int V_176 ;
for ( V_176 = 0 ; V_176 < V_172 ; V_176 ++ ) {
if ( * V_174 != * V_175 )
return 0 ;
if ( ! * V_174 ++ )
return 1 ;
V_175 ++ ;
}
return 1 ;
}
static void F_88 ( struct V_8 * V_10 )
{
struct V_59 V_177 ;
struct V_3 * V_4 ;
struct V_3 * V_155 ;
F_89 ( & V_177 ) ;
F_21 ( & V_57 ) ;
F_74 (pd, n, &g_pd_list, link) {
if ( V_4 -> V_10 == V_10 ) {
F_90 ( & V_4 -> V_63 , & V_177 ) ;
F_65 ( V_4 ) ;
}
}
F_26 ( & V_57 ) ;
while ( ! F_63 ( & V_177 ) ) {
V_4 = F_64 ( & V_177 , struct V_3 , V_63 ) ;
F_35 ( V_4 ) ;
F_36 ( V_4 ) ;
}
}
void F_91 ( char * V_10 )
{
struct V_129 * V_168 = 0 ;
struct V_129 * * V_63 ;
F_15 ( L_22 , V_10 ) ;
F_21 ( & V_127 ) ;
V_168 = V_128 ;
V_63 = & V_128 ;
while ( V_168 ) {
if ( F_87 ( V_168 -> V_171 , V_10 ) ) {
F_15 ( L_23 , V_10 ) ;
* V_63 = V_168 -> V_131 ;
break;
} else {
V_63 = & V_168 ;
V_168 = V_168 -> V_131 ;
}
}
F_26 ( & V_127 ) ;
if ( V_168 ) {
F_62 ( & V_168 -> V_132 ) ;
if ( V_168 -> V_132 . V_9 ) {
F_37 ( V_168 -> V_132 . V_9 ) ;
F_88 ( V_168 -> V_132 . V_9 ) ;
}
F_45 ( V_168 ) ;
}
}
static char * F_92 ( char * V_178 , char * V_179 , int V_180 )
{
while ( * V_178 == ',' )
V_178 ++ ;
while ( * V_178 && ( * V_178 != ',' ) && V_180 > 1 ) {
* V_179 ++ = * V_178 ++ ;
V_180 -- ;
}
* V_179 = 0 ;
return V_178 ;
}
int F_93 ( char * V_181 )
{
F_94 ( & V_165 ) ;
if ( V_181 && ( V_181 [ 0 ] == '*' ) ) {
F_83 ( 0 ) ;
} else {
char V_182 [ 32 ] ;
while ( * V_181 ) {
V_181 = F_92 ( V_181 , V_182 , sizeof( V_182 ) ) ;
if ( V_182 [ 0 ] )
F_83 ( V_182 ) ;
}
}
F_95 ( & V_126 ) ;
return 0 ;
}
int F_96 ( struct V_183 * V_184 , int V_185 )
{
struct V_3 * V_4 ;
struct V_59 * V_60 ;
int V_186 = 0 ;
F_21 ( & V_57 ) ;
F_23 (e, &g_pd_list) {
if ( V_186 >= V_185 )
break;
V_4 = F_24 ( V_60 , struct V_3 , V_63 ) ;
memcpy ( & V_184 [ V_186 ++ ] , V_4 -> V_20 , V_64 ) ;
}
F_26 ( & V_57 ) ;
return V_186 ;
}
void F_97 ( void )
{
F_21 ( & V_57 ) ;
}
void F_98 ( void )
{
F_26 ( & V_57 ) ;
}
