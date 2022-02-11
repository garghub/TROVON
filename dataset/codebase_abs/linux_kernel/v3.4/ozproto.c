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
V_4 -> V_31 |= V_71 ;
V_4 -> V_72 = V_15 -> V_72 ;
if ( ! V_4 -> V_72 )
V_4 -> V_72 = 4 ;
}
if ( V_15 -> V_73 )
V_4 -> V_67 = ( ( T_2 ) V_15 -> V_73 ) << 4 ;
F_15 ( L_5 ,
V_4 -> V_67 , V_4 -> V_72 ) ;
V_4 -> V_74 = 3 * 1024 ;
V_4 -> V_75 = V_62 + V_76 ;
V_4 -> V_77 = V_78 ;
F_19 ( V_4 , V_15 -> V_44 ) ;
F_17 ( V_4 , V_15 -> V_36 ) ;
V_53 &= F_28 ( F_29 ( & V_15 -> V_34 ) ) ;
if ( ( V_53 & 0x1 ) && ( V_15 -> V_32 ) ) {
if ( V_4 -> V_32 ) {
if ( V_4 -> V_32 != V_15 -> V_32 ) {
V_50 = V_79 ;
goto V_80;
}
} else {
V_53 &= ~ 0x1 ;
V_4 -> V_32 =
F_1 ( V_15 -> V_32 ) ;
}
} else {
if ( V_4 -> V_32 && ! V_15 -> V_32 ) {
V_50 = V_81 ;
V_52 = 1 ;
} else {
V_53 &= ~ 0x1 ;
V_4 -> V_32 =
F_1 ( V_15 -> V_32 ) ;
}
}
V_80:
if ( V_50 == V_51 ) {
T_2 V_82 = V_53 & ~ V_4 -> V_33 & ~ 0x1 ;
T_2 V_83 = V_4 -> V_33 & ~ V_53 & ~ 0x1 ;
T_2 V_84 = V_53 & V_4 -> V_85 & ~ 0x1 ;
F_26 ( & V_57 ) ;
F_30 ( V_4 , V_86 ) ;
F_31 ( V_4 , V_87 ) ;
F_15 ( L_6 ,
V_53 , V_4 -> V_33 , V_4 -> V_85 ) ;
if ( V_82 ) {
if ( F_32 ( V_4 , V_82 , 0 ) )
V_50 = V_88 ;
}
if ( V_84 )
if ( F_32 ( V_4 , V_84 , 1 ) )
V_50 = V_88 ;
if ( V_83 )
F_33 ( V_4 , V_83 , 0 ) ;
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
static void F_39 ( struct V_3 * V_4 , T_1 V_89 , T_1 V_90 ,
T_1 * V_91 , T_1 V_22 )
{
struct V_92 * V_93 ;
struct V_92 * V_94 ;
int V_95 = 0 ;
V_93 = F_40 ( sizeof( struct V_92 ) + V_22 - 1 , V_17 ) ;
if ( ! V_93 )
return;
V_93 -> V_89 = V_89 ;
V_93 -> V_90 = V_90 ;
memcpy ( V_93 -> V_91 , V_91 , V_22 ) ;
F_15 ( L_7 ) ;
F_41 ( & V_57 ) ;
F_42 (f2, &pd->farewell_list, link) {
if ( ( V_94 -> V_89 == V_89 ) && ( V_94 -> V_90 == V_90 ) ) {
V_95 = 1 ;
F_43 ( & V_94 -> V_63 ) ;
break;
}
}
F_25 ( & V_93 -> V_63 , & V_4 -> V_96 ) ;
F_44 ( & V_57 ) ;
if ( V_95 )
F_45 ( V_94 ) ;
}
static void F_46 ( struct V_6 * V_7 )
{
T_1 * V_97 ;
T_1 * V_98 ;
struct V_12 * V_13 ;
int V_30 ;
struct V_3 * V_4 = 0 ;
struct V_11 * V_11 = (struct V_11 * ) F_47 ( V_7 ) ;
int V_99 = 0 ;
T_3 V_27 ;
F_13 ( V_100 , 0 ,
( ( ( T_2 ) V_11 -> V_23 ) << 8 ) | V_11 -> V_26 ,
0 , V_11 -> V_27 ) ;
F_48 ( V_101 ,
L_8 ,
V_11 -> V_27 , V_11 -> V_26 , V_11 -> V_23 ) ;
V_97 = F_49 ( V_7 ) ;
V_98 = & V_97 [ V_64 ] ;
V_30 = V_7 -> V_22 ;
if ( F_50 ( V_11 -> V_23 ) != V_24 ) {
F_15 ( L_9 ,
F_50 ( V_11 -> V_23 ) ) ;
goto V_80;
}
V_27 = F_51 ( F_29 ( & V_11 -> V_27 ) ) ;
V_4 = F_52 ( V_98 ) ;
if ( V_4 ) {
V_4 -> V_61 = V_62 ;
F_53 ( V_4 , V_102 ,
V_4 -> V_61 + V_4 -> V_45 , 1 ) ;
if ( V_27 != V_4 -> V_103 ) {
V_4 -> V_103 = V_27 ;
} else {
V_99 = 1 ;
F_15 ( L_10 ) ;
}
}
if ( V_4 && ! V_99 && ( ( V_4 -> V_31 & V_104 ) == V_105 ) ) {
V_4 -> V_106 = & V_4 -> V_107 ;
if ( V_11 -> V_23 & V_108 ) {
F_54 ( V_4 , V_11 -> V_26 ) ;
}
if ( ( V_11 -> V_23 & V_109 ) &&
( V_4 -> V_110 == V_86 ) ) {
int V_111 = V_4 -> V_112 ;
V_4 -> V_113 = V_27 ;
while ( F_55 ( V_4 , 0 ) >= 0 )
;
F_56 ( V_4 , V_111 ) ;
}
}
V_30 -= sizeof( struct V_11 ) ;
V_13 = (struct V_12 * ) ( ( T_1 * ) V_11 + sizeof( struct V_11 ) ) ;
while ( V_30 >= sizeof( struct V_12 ) ) {
V_30 -= sizeof( struct V_12 ) + V_13 -> V_30 ;
if ( V_30 < 0 )
break;
switch ( V_13 -> type ) {
case V_114 :
F_13 ( V_115 , 0 , 0 , 0 , 0 ) ;
F_15 ( L_11 ) ;
V_4 = F_20 ( V_4 , V_13 , V_98 , V_7 -> V_9 ) ;
break;
case V_116 :
F_15 ( L_12 ) ;
if ( V_4 )
F_57 ( V_4 ) ;
break;
case V_117 : {
struct V_118 * V_15 =
(struct V_118 * ) ( V_13 + 1 ) ;
F_15 ( L_13 ) ;
if ( V_4 && ( V_4 -> V_110 & V_86 ) ) {
F_41 ( & V_57 ) ;
F_17 ( V_4 , V_15 -> V_119 ) ;
F_19 ( V_4 , V_15 -> V_44 ) ;
F_44 ( & V_57 ) ;
}
}
break;
case V_120 : {
struct V_121 * V_15 =
(struct V_121 * ) ( V_13 + 1 ) ;
F_15 ( L_14 ) ;
F_39 ( V_4 , V_15 -> V_89 ,
V_15 -> V_90 , V_15 -> V_91 ,
V_13 -> V_30 + 1 - sizeof( * V_15 ) ) ;
}
break;
case V_122 :
if ( V_4 && ( V_4 -> V_110 & V_86 ) ) {
struct V_123 * V_124 =
(struct V_123 * ) ( V_13 + 1 ) ;
if ( V_99 )
break;
F_58 ( V_4 , V_124 -> V_125 , V_13 ) ;
}
break;
default:
F_15 ( L_15 , V_13 -> type ) ;
}
V_13 = F_59 ( V_13 ) ;
}
V_80:
if ( V_4 )
F_36 ( V_4 ) ;
F_60 ( V_7 ) ;
}
void F_61 ( void )
{
struct V_59 * V_126 = 0 ;
F_62 ( & V_127 ) ;
F_21 ( & V_128 ) ;
while ( V_129 ) {
struct V_130 * V_131 = V_129 ;
V_129 = V_131 -> V_132 ;
F_26 ( & V_128 ) ;
F_63 ( & V_131 -> V_133 ) ;
if ( V_131 -> V_133 . V_9 )
F_37 ( V_131 -> V_133 . V_9 ) ;
F_45 ( V_131 ) ;
F_21 ( & V_128 ) ;
}
F_26 ( & V_128 ) ;
F_21 ( & V_57 ) ;
while ( ! F_64 ( & V_65 ) ) {
struct V_3 * V_4 =
F_65 ( & V_65 , struct V_3 , V_63 ) ;
F_66 ( V_4 ) ;
F_26 ( & V_57 ) ;
F_35 ( V_4 ) ;
F_36 ( V_4 ) ;
F_21 ( & V_57 ) ;
}
V_126 = V_134 ;
V_134 = 0 ;
F_26 ( & V_57 ) ;
while ( V_126 ) {
struct V_135 * V_136 = F_24 ( V_126 , struct V_135 , V_63 ) ;
V_126 = V_126 -> V_132 ;
F_45 ( V_136 ) ;
}
F_15 ( L_16 ) ;
}
static void F_67 ( struct V_3 * V_4 , int type )
{
switch ( type ) {
case V_102 :
F_57 ( V_4 ) ;
break;
case V_87 :
F_35 ( V_4 ) ;
break;
case V_137 : {
T_2 V_34 = 0 ;
F_21 ( & V_57 ) ;
V_4 -> V_138 = 0 ;
if ( V_4 -> V_110 & V_86 )
V_34 = V_4 -> V_33 ;
F_26 ( & V_57 ) ;
if ( V_34 )
F_68 ( V_4 , V_34 ) ;
}
break;
}
}
static void F_69 ( unsigned long V_139 )
{
struct V_135 * V_136 ;
struct V_135 * V_140 ;
struct V_3 * V_4 ;
F_21 ( & V_57 ) ;
if ( ! V_141 ) {
F_13 ( V_142 , 0 , 0 , 0 , 0 ) ;
F_26 ( & V_57 ) ;
return;
}
V_143 = V_144 ;
V_136 = V_141 ;
V_141 = 0 ;
F_43 ( & V_136 -> V_63 ) ;
F_26 ( & V_57 ) ;
do {
V_4 = V_136 -> V_4 ;
F_13 ( V_142 , 0 , V_136 -> type , 0 , 0 ) ;
F_67 ( V_4 , V_136 -> type ) ;
F_21 ( & V_57 ) ;
if ( V_145 < V_146 ) {
V_136 -> V_63 . V_132 = V_134 ;
V_134 = & V_136 -> V_63 ;
V_145 ++ ;
V_136 = 0 ;
}
if ( ! F_64 ( & V_147 ) ) {
V_140 = F_24 ( V_147 . V_132 ,
struct V_135 , V_63 ) ;
if ( F_70 ( V_140 -> V_148 , V_62 ) )
F_43 ( & V_140 -> V_63 ) ;
else
V_140 = 0 ;
} else {
V_140 = 0 ;
}
F_26 ( & V_57 ) ;
F_36 ( V_4 ) ;
if ( V_136 )
F_45 ( V_136 ) ;
V_136 = V_140 ;
} while ( V_136 );
V_143 = V_149 ;
F_71 () ;
}
static void F_71 ( void )
{
F_21 ( & V_57 ) ;
if ( ! F_64 ( & V_147 ) ) {
V_141 =
F_24 ( V_147 . V_132 , struct V_135 , V_63 ) ;
if ( V_143 == V_150 ) {
F_13 ( V_151 , 3 ,
( T_2 ) V_141 -> type , 0 ,
( unsigned ) V_141 -> V_148 ) ;
F_72 ( & V_127 , V_141 -> V_148 ) ;
} else {
F_13 ( V_151 , 4 ,
( T_2 ) V_141 -> type , 0 ,
( unsigned ) V_141 -> V_148 ) ;
V_127 . V_152 = V_141 -> V_148 ;
V_127 . V_153 = F_69 ;
V_127 . V_154 = 0 ;
F_73 ( & V_127 ) ;
}
V_143 = V_150 ;
} else {
F_15 ( L_17 ) ;
}
F_26 ( & V_57 ) ;
}
void F_53 ( struct V_3 * V_4 , int type , unsigned long V_148 ,
int remove )
{
struct V_59 * V_60 ;
struct V_135 * V_136 = 0 ;
int V_155 = 0 ;
F_13 ( V_151 , 1 , ( T_2 ) type , 0 , ( unsigned ) V_148 ) ;
F_41 ( & V_57 ) ;
if ( remove ) {
F_23 (e, &g_timer_list) {
V_136 = F_24 ( V_60 , struct V_135 , V_63 ) ;
if ( ( V_136 -> V_4 == V_4 ) && ( V_136 -> type == type ) ) {
if ( V_141 == V_136 ) {
V_155 = 1 ;
V_141 = 0 ;
}
F_43 ( V_60 ) ;
break;
}
V_136 = 0 ;
}
}
if ( ! V_136 ) {
if ( V_134 ) {
V_136 = F_24 ( V_134 , struct V_135 , V_63 ) ;
V_134 = V_134 -> V_132 ;
V_145 -- ;
} else {
V_136 = F_40 ( sizeof( struct V_135 ) , V_17 ) ;
}
if ( V_136 ) {
V_136 -> V_4 = V_4 ;
V_136 -> type = type ;
F_66 ( V_4 ) ;
}
}
if ( V_136 ) {
struct V_135 * V_140 ;
V_136 -> V_148 = V_148 ;
F_23 (e, &g_timer_list) {
V_140 = F_24 ( V_60 , struct V_135 , V_63 ) ;
if ( F_74 ( V_148 , V_140 -> V_148 ) ) {
if ( V_140 == V_141 ) {
V_141 = 0 ;
V_155 = 1 ;
}
break;
}
}
F_25 ( & V_136 -> V_63 , V_60 ) ;
}
if ( V_143 == V_149 )
V_155 = 1 ;
else if ( V_143 == V_144 )
V_155 = 0 ;
F_44 ( & V_57 ) ;
if ( V_155 )
F_71 () ;
}
void F_31 ( struct V_3 * V_4 , int type )
{
struct V_59 * V_126 = 0 ;
struct V_135 * V_136 ;
struct V_135 * V_156 ;
int V_155 = 0 ;
int V_157 = 0 ;
F_13 ( V_151 , 2 , ( T_2 ) type , 0 , 0 ) ;
F_41 ( & V_57 ) ;
F_75 (t, n, &g_timer_list, link) {
if ( ( V_136 -> V_4 == V_4 ) && ( ( type == 0 ) || ( V_136 -> type == type ) ) ) {
if ( V_141 == V_136 ) {
V_155 = 1 ;
V_141 = 0 ;
F_76 ( & V_127 ) ;
}
F_43 ( & V_136 -> V_63 ) ;
V_157 ++ ;
if ( V_145 < V_146 ) {
V_136 -> V_63 . V_132 = V_134 ;
V_134 = & V_136 -> V_63 ;
V_145 ++ ;
} else {
V_136 -> V_63 . V_132 = V_126 ;
V_126 = & V_136 -> V_63 ;
}
if ( type )
break;
}
}
if ( V_143 == V_144 )
V_155 = 0 ;
else if ( V_155 )
V_143 = V_149 ;
F_44 ( & V_57 ) ;
if ( V_155 )
F_71 () ;
while ( V_157 -- )
F_36 ( V_4 ) ;
while ( V_126 ) {
V_136 = F_24 ( V_126 , struct V_135 , V_63 ) ;
V_126 = V_126 -> V_132 ;
F_45 ( V_136 ) ;
}
}
void F_34 ( struct V_3 * V_4 )
{
unsigned long V_158 = V_62 ;
unsigned long V_136 ;
F_41 ( & V_57 ) ;
if ( V_4 -> V_138 ) {
F_44 ( & V_57 ) ;
return;
}
if ( V_4 -> V_77 )
V_136 = ( ( V_158 / V_4 -> V_77 ) + 1 ) * V_4 -> V_77 ;
else
V_136 = V_158 + 1 ;
V_4 -> V_138 = 1 ;
F_44 ( & V_57 ) ;
F_53 ( V_4 , V_137 , V_136 , 0 ) ;
}
struct V_3 * F_52 ( T_1 * V_20 )
{
struct V_3 * V_4 ;
struct V_59 * V_60 ;
F_21 ( & V_57 ) ;
F_23 (e, &g_pd_list) {
V_4 = F_24 ( V_60 , struct V_3 , V_63 ) ;
if ( memcmp ( V_4 -> V_20 , V_20 , V_64 ) == 0 ) {
F_77 ( & V_4 -> V_159 ) ;
F_26 ( & V_57 ) ;
return V_4 ;
}
}
F_26 ( & V_57 ) ;
return 0 ;
}
void F_78 ( int V_125 , int V_160 )
{
if ( V_125 <= V_161 ) {
F_21 ( & V_57 ) ;
if ( V_160 )
V_54 |= ( 1 << V_125 ) ;
else
V_54 &= ~ ( 1 << V_125 ) ;
F_26 ( & V_57 ) ;
}
}
static int F_79 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_162 * V_163 , struct V_8 * V_164 )
{
F_13 ( V_165 , 0 , 0 , 0 , 0 ) ;
V_7 = F_80 ( V_7 , V_17 ) ;
if ( V_7 == 0 )
return 0 ;
F_21 ( & V_166 . V_167 ) ;
if ( V_168 ) {
F_81 ( & V_166 , V_7 ) ;
F_26 ( & V_166 . V_167 ) ;
} else {
V_168 = 1 ;
do {
F_26 ( & V_166 . V_167 ) ;
F_46 ( V_7 ) ;
F_21 ( & V_166 . V_167 ) ;
if ( F_82 ( & V_166 ) ) {
V_168 = 0 ;
F_26 ( & V_166 . V_167 ) ;
break;
}
V_7 = F_83 ( & V_166 ) ;
} while ( 1 );
}
return 0 ;
}
void F_84 ( char * V_10 )
{
struct V_130 * V_169 ;
V_169 = F_40 ( sizeof( struct V_130 ) , V_17 ) ;
if ( V_169 ) {
V_169 -> V_133 . type = F_85 ( V_19 ) ;
V_169 -> V_133 . V_170 = F_79 ;
memcpy ( V_169 -> V_171 , V_10 , V_172 ) ;
if ( V_10 && * V_10 ) {
F_15 ( L_18 , V_10 ) ;
V_169 -> V_133 . V_9 =
F_86 ( & V_173 , V_10 ) ;
if ( V_169 -> V_133 . V_9 == 0 ) {
F_15 ( L_19 , V_10 ) ;
F_45 ( V_169 ) ;
V_169 = 0 ;
}
} else {
F_15 ( L_20 ) ;
V_169 -> V_133 . V_9 = 0 ;
}
if ( V_169 ) {
F_87 ( & V_169 -> V_133 ) ;
F_21 ( & V_128 ) ;
V_169 -> V_132 = V_129 ;
V_129 = V_169 ;
F_26 ( & V_128 ) ;
}
}
}
static int F_88 ( char * V_174 , char * V_175 )
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
static void F_89 ( struct V_8 * V_10 )
{
struct V_59 V_177 ;
struct V_3 * V_4 ;
struct V_3 * V_156 ;
F_90 ( & V_177 ) ;
F_21 ( & V_57 ) ;
F_75 (pd, n, &g_pd_list, link) {
if ( V_4 -> V_10 == V_10 ) {
F_91 ( & V_4 -> V_63 , & V_177 ) ;
F_66 ( V_4 ) ;
}
}
F_26 ( & V_57 ) ;
while ( ! F_64 ( & V_177 ) ) {
V_4 = F_65 ( & V_177 , struct V_3 , V_63 ) ;
F_35 ( V_4 ) ;
F_36 ( V_4 ) ;
}
}
void F_92 ( char * V_10 )
{
struct V_130 * V_169 = 0 ;
struct V_130 * * V_63 ;
F_15 ( L_21 , V_10 ) ;
F_21 ( & V_128 ) ;
V_169 = V_129 ;
V_63 = & V_129 ;
while ( V_169 ) {
if ( F_88 ( V_169 -> V_171 , V_10 ) ) {
F_15 ( L_22 , V_10 ) ;
* V_63 = V_169 -> V_132 ;
break;
} else {
V_63 = & V_169 ;
V_169 = V_169 -> V_132 ;
}
}
F_26 ( & V_128 ) ;
if ( V_169 ) {
F_63 ( & V_169 -> V_133 ) ;
if ( V_169 -> V_133 . V_9 ) {
F_37 ( V_169 -> V_133 . V_9 ) ;
F_89 ( V_169 -> V_133 . V_9 ) ;
}
F_45 ( V_169 ) ;
}
}
static char * F_93 ( char * V_178 , char * V_179 , int V_180 )
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
int F_94 ( char * V_181 )
{
F_95 ( & V_166 ) ;
if ( V_181 && ( V_181 [ 0 ] == '*' ) ) {
F_84 ( 0 ) ;
} else {
char V_182 [ 32 ] ;
while ( * V_181 ) {
V_181 = F_93 ( V_181 , V_182 , sizeof( V_182 ) ) ;
if ( V_182 [ 0 ] )
F_84 ( V_182 ) ;
}
}
F_96 ( & V_127 ) ;
return 0 ;
}
int F_97 ( struct V_183 * V_184 , int V_185 )
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
void F_98 ( void )
{
F_21 ( & V_57 ) ;
}
void F_99 ( void )
{
F_26 ( & V_57 ) ;
}
