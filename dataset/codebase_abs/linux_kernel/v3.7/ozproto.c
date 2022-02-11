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
switch ( V_15 -> V_72 & V_73 ) {
case V_74 :
V_4 -> V_75 = ( V_15 -> V_72 &
~ V_73 ) / V_4 -> V_71 ;
break;
case V_76 :
V_4 -> V_75 = ( ( V_15 -> V_72 &
~ V_73 ) * 10 ) / V_4 -> V_71 ;
break;
default:
V_4 -> V_75 = V_77 ;
}
}
if ( V_15 -> V_78 )
V_4 -> V_67 = ( ( T_2 ) V_15 -> V_78 ) << 4 ;
F_15 ( L_5 ,
V_4 -> V_67 , V_4 -> V_71 ) ;
V_4 -> V_79 = 3 * 1024 ;
V_4 -> V_80 = V_62 + V_81 ;
V_4 -> V_82 = V_83 ;
F_19 ( V_4 , V_15 -> V_44 ) ;
F_17 ( V_4 , V_15 -> V_36 ) ;
V_53 &= F_28 ( F_29 ( & V_15 -> V_34 ) ) ;
if ( ( V_53 & 0x1 ) && ( V_15 -> V_32 ) ) {
if ( V_4 -> V_32 ) {
if ( V_4 -> V_32 != V_15 -> V_32 ) {
V_50 = V_84 ;
goto V_85;
}
} else {
V_53 &= ~ 0x1 ;
V_4 -> V_32 =
F_1 ( V_15 -> V_32 ) ;
}
} else {
if ( V_4 -> V_32 && ! V_15 -> V_32 ) {
V_50 = V_86 ;
V_52 = 1 ;
} else {
V_53 &= ~ 0x1 ;
V_4 -> V_32 =
F_1 ( V_15 -> V_32 ) ;
}
}
V_85:
if ( V_50 == V_51 ) {
T_2 V_87 = V_53 & ~ V_4 -> V_33 & ~ 0x1 ;
T_2 V_88 = V_4 -> V_33 & ~ V_53 & ~ 0x1 ;
T_2 V_89 = V_53 & V_4 -> V_90 & ~ 0x1 ;
F_26 ( & V_57 ) ;
F_30 ( V_4 , V_91 ) ;
F_31 ( V_4 , V_92 ) ;
F_15 ( L_6 ,
V_53 , V_4 -> V_33 , V_4 -> V_90 ) ;
if ( V_87 ) {
if ( F_32 ( V_4 , V_87 , 0 ) )
V_50 = V_93 ;
}
if ( V_89 )
if ( F_32 ( V_4 , V_89 , 1 ) )
V_50 = V_93 ;
if ( V_88 )
F_33 ( V_4 , V_88 , 0 ) ;
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
static void F_39 ( struct V_3 * V_4 , T_1 V_94 , T_1 V_95 ,
T_1 * V_96 , T_1 V_22 )
{
struct V_97 * V_98 ;
struct V_97 * V_99 ;
int V_100 = 0 ;
V_98 = F_40 ( sizeof( struct V_97 ) + V_22 - 1 , V_17 ) ;
if ( ! V_98 )
return;
V_98 -> V_94 = V_94 ;
V_98 -> V_95 = V_95 ;
memcpy ( V_98 -> V_96 , V_96 , V_22 ) ;
F_15 ( L_7 ) ;
F_41 ( & V_57 ) ;
F_42 (f2, &pd->farewell_list, link) {
if ( ( V_99 -> V_94 == V_94 ) && ( V_99 -> V_95 == V_95 ) ) {
V_100 = 1 ;
F_43 ( & V_99 -> V_63 ) ;
break;
}
}
F_25 ( & V_98 -> V_63 , & V_4 -> V_101 ) ;
F_44 ( & V_57 ) ;
if ( V_100 )
F_45 ( V_99 ) ;
}
static void F_46 ( struct V_6 * V_7 )
{
T_1 * V_102 ;
T_1 * V_103 ;
struct V_12 * V_13 ;
int V_30 ;
struct V_3 * V_4 = 0 ;
struct V_11 * V_11 = (struct V_11 * ) F_47 ( V_7 ) ;
int V_104 = 0 ;
T_3 V_27 ;
F_13 ( V_105 , 0 ,
( ( ( T_2 ) V_11 -> V_23 ) << 8 ) | V_11 -> V_26 ,
0 , V_11 -> V_27 ) ;
F_48 ( V_106 ,
L_8 ,
V_11 -> V_27 , V_11 -> V_26 , V_11 -> V_23 ) ;
V_102 = F_49 ( V_7 ) ;
V_103 = & V_102 [ V_64 ] ;
V_30 = V_7 -> V_22 ;
if ( F_50 ( V_11 -> V_23 ) != V_24 ) {
F_15 ( L_9 ,
F_50 ( V_11 -> V_23 ) ) ;
goto V_85;
}
V_27 = F_51 ( F_29 ( & V_11 -> V_27 ) ) ;
V_4 = F_52 ( V_103 ) ;
if ( V_4 ) {
V_4 -> V_61 = V_62 ;
F_53 ( V_4 , V_107 ,
V_4 -> V_61 + V_4 -> V_45 , 1 ) ;
if ( V_27 != V_4 -> V_108 ) {
V_4 -> V_108 = V_27 ;
} else {
V_104 = 1 ;
F_15 ( L_10 ) ;
}
}
if ( V_4 && ! V_104 && ( ( V_4 -> V_31 & V_109 ) == V_110 ) ) {
F_48 ( V_106 , L_11 ) ;
V_4 -> V_111 = & V_4 -> V_112 ;
if ( V_11 -> V_23 & V_113 ) {
F_54 ( V_4 , V_11 -> V_26 ) ;
}
if ( ( V_11 -> V_23 & V_114 ) &&
( V_4 -> V_115 == V_91 ) ) {
int V_116 = V_4 -> V_117 ;
V_4 -> V_118 = V_27 ;
F_55 ( V_4 , V_116 ) ;
}
}
V_30 -= sizeof( struct V_11 ) ;
V_13 = (struct V_12 * ) ( ( T_1 * ) V_11 + sizeof( struct V_11 ) ) ;
while ( V_30 >= sizeof( struct V_12 ) ) {
V_30 -= sizeof( struct V_12 ) + V_13 -> V_30 ;
if ( V_30 < 0 )
break;
switch ( V_13 -> type ) {
case V_119 :
F_13 ( V_120 , 0 , 0 , 0 , 0 ) ;
F_15 ( L_12 ) ;
V_4 = F_20 ( V_4 , V_13 , V_103 , V_7 -> V_9 ) ;
break;
case V_121 :
F_15 ( L_13 ) ;
if ( V_4 )
F_56 ( V_4 ) ;
break;
case V_122 : {
struct V_123 * V_15 =
(struct V_123 * ) ( V_13 + 1 ) ;
F_15 ( L_14 ) ;
if ( V_4 && ( V_4 -> V_115 & V_91 ) ) {
F_41 ( & V_57 ) ;
F_17 ( V_4 , V_15 -> V_124 ) ;
F_19 ( V_4 , V_15 -> V_44 ) ;
F_44 ( & V_57 ) ;
}
}
break;
case V_125 : {
struct V_126 * V_15 =
(struct V_126 * ) ( V_13 + 1 ) ;
F_15 ( L_15 ) ;
F_39 ( V_4 , V_15 -> V_94 ,
V_15 -> V_95 , V_15 -> V_96 ,
V_13 -> V_30 + 1 - sizeof( * V_15 ) ) ;
}
break;
case V_127 :
if ( V_4 && ( V_4 -> V_115 & V_91 ) ) {
struct V_128 * V_129 =
(struct V_128 * ) ( V_13 + 1 ) ;
if ( V_104 )
break;
F_57 ( V_4 , V_129 -> V_130 , V_13 ) ;
}
break;
default:
F_15 ( L_16 , V_13 -> type ) ;
}
V_13 = F_58 ( V_13 ) ;
}
V_85:
if ( V_4 )
F_36 ( V_4 ) ;
F_59 ( V_7 ) ;
}
void F_60 ( void )
{
struct V_59 * V_131 = 0 ;
F_61 ( & V_132 ) ;
F_21 ( & V_133 ) ;
while ( V_134 ) {
struct V_135 * V_136 = V_134 ;
V_134 = V_136 -> V_137 ;
F_26 ( & V_133 ) ;
F_62 ( & V_136 -> V_138 ) ;
if ( V_136 -> V_138 . V_9 )
F_37 ( V_136 -> V_138 . V_9 ) ;
F_45 ( V_136 ) ;
F_21 ( & V_133 ) ;
}
F_26 ( & V_133 ) ;
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
V_131 = V_139 ;
V_139 = 0 ;
F_26 ( & V_57 ) ;
while ( V_131 ) {
struct V_140 * V_141 = F_24 ( V_131 , struct V_140 , V_63 ) ;
V_131 = V_131 -> V_137 ;
F_45 ( V_141 ) ;
}
F_15 ( L_17 ) ;
}
static void F_66 ( struct V_3 * V_4 , int type )
{
switch ( type ) {
case V_107 :
F_56 ( V_4 ) ;
break;
case V_92 :
F_35 ( V_4 ) ;
break;
case V_142 : {
T_2 V_34 = 0 ;
F_21 ( & V_57 ) ;
V_4 -> V_143 = 0 ;
if ( V_4 -> V_115 & V_91 )
V_34 = V_4 -> V_33 ;
F_26 ( & V_57 ) ;
if ( V_34 )
F_67 ( V_4 , V_34 ) ;
}
break;
}
}
static void F_68 ( unsigned long V_144 )
{
struct V_140 * V_141 ;
struct V_140 * V_145 ;
struct V_3 * V_4 ;
F_21 ( & V_57 ) ;
if ( ! V_146 ) {
F_13 ( V_147 , 0 , 0 , 0 , 0 ) ;
F_26 ( & V_57 ) ;
return;
}
V_148 = V_149 ;
V_141 = V_146 ;
V_146 = 0 ;
F_43 ( & V_141 -> V_63 ) ;
F_26 ( & V_57 ) ;
do {
V_4 = V_141 -> V_4 ;
F_13 ( V_147 , 0 , V_141 -> type , 0 , 0 ) ;
F_66 ( V_4 , V_141 -> type ) ;
F_21 ( & V_57 ) ;
if ( V_150 < V_151 ) {
V_141 -> V_63 . V_137 = V_139 ;
V_139 = & V_141 -> V_63 ;
V_150 ++ ;
V_141 = 0 ;
}
if ( ! F_63 ( & V_152 ) ) {
V_145 = F_24 ( V_152 . V_137 ,
struct V_140 , V_63 ) ;
if ( F_69 ( V_145 -> V_153 , V_62 ) )
F_43 ( & V_145 -> V_63 ) ;
else
V_145 = 0 ;
} else {
V_145 = 0 ;
}
F_26 ( & V_57 ) ;
F_36 ( V_4 ) ;
if ( V_141 )
F_45 ( V_141 ) ;
V_141 = V_145 ;
} while ( V_141 );
V_148 = V_154 ;
F_70 () ;
}
static void F_70 ( void )
{
F_21 ( & V_57 ) ;
if ( ! F_63 ( & V_152 ) ) {
V_146 =
F_24 ( V_152 . V_137 , struct V_140 , V_63 ) ;
if ( V_148 == V_155 ) {
F_13 ( V_156 , 3 ,
( T_2 ) V_146 -> type , 0 ,
( unsigned ) V_146 -> V_153 ) ;
F_71 ( & V_132 , V_146 -> V_153 ) ;
} else {
F_13 ( V_156 , 4 ,
( T_2 ) V_146 -> type , 0 ,
( unsigned ) V_146 -> V_153 ) ;
V_132 . V_157 = V_146 -> V_153 ;
V_132 . V_158 = F_68 ;
V_132 . V_159 = 0 ;
F_72 ( & V_132 ) ;
}
V_148 = V_155 ;
} else {
F_15 ( L_18 ) ;
}
F_26 ( & V_57 ) ;
}
void F_53 ( struct V_3 * V_4 , int type , unsigned long V_153 ,
int remove )
{
struct V_59 * V_60 ;
struct V_140 * V_141 = 0 ;
int V_160 = 0 ;
F_13 ( V_156 , 1 , ( T_2 ) type , 0 , ( unsigned ) V_153 ) ;
F_41 ( & V_57 ) ;
if ( remove ) {
F_23 (e, &g_timer_list) {
V_141 = F_24 ( V_60 , struct V_140 , V_63 ) ;
if ( ( V_141 -> V_4 == V_4 ) && ( V_141 -> type == type ) ) {
if ( V_146 == V_141 ) {
V_160 = 1 ;
V_146 = 0 ;
}
F_43 ( V_60 ) ;
break;
}
V_141 = 0 ;
}
}
if ( ! V_141 ) {
if ( V_139 ) {
V_141 = F_24 ( V_139 , struct V_140 , V_63 ) ;
V_139 = V_139 -> V_137 ;
V_150 -- ;
} else {
V_141 = F_40 ( sizeof( struct V_140 ) , V_17 ) ;
}
if ( V_141 ) {
V_141 -> V_4 = V_4 ;
V_141 -> type = type ;
F_65 ( V_4 ) ;
}
}
if ( V_141 ) {
struct V_140 * V_145 ;
V_141 -> V_153 = V_153 ;
F_23 (e, &g_timer_list) {
V_145 = F_24 ( V_60 , struct V_140 , V_63 ) ;
if ( F_73 ( V_153 , V_145 -> V_153 ) ) {
if ( V_145 == V_146 ) {
V_146 = 0 ;
V_160 = 1 ;
}
break;
}
}
F_25 ( & V_141 -> V_63 , V_60 ) ;
}
if ( V_148 == V_154 )
V_160 = 1 ;
else if ( V_148 == V_149 )
V_160 = 0 ;
F_44 ( & V_57 ) ;
if ( V_160 )
F_70 () ;
}
void F_31 ( struct V_3 * V_4 , int type )
{
struct V_59 * V_131 = 0 ;
struct V_140 * V_141 ;
struct V_140 * V_161 ;
int V_160 = 0 ;
int V_162 = 0 ;
F_13 ( V_156 , 2 , ( T_2 ) type , 0 , 0 ) ;
F_41 ( & V_57 ) ;
F_74 (t, n, &g_timer_list, link) {
if ( ( V_141 -> V_4 == V_4 ) && ( ( type == 0 ) || ( V_141 -> type == type ) ) ) {
if ( V_146 == V_141 ) {
V_160 = 1 ;
V_146 = 0 ;
F_75 ( & V_132 ) ;
}
F_43 ( & V_141 -> V_63 ) ;
V_162 ++ ;
if ( V_150 < V_151 ) {
V_141 -> V_63 . V_137 = V_139 ;
V_139 = & V_141 -> V_63 ;
V_150 ++ ;
} else {
V_141 -> V_63 . V_137 = V_131 ;
V_131 = & V_141 -> V_63 ;
}
if ( type )
break;
}
}
if ( V_148 == V_149 )
V_160 = 0 ;
else if ( V_160 )
V_148 = V_154 ;
F_44 ( & V_57 ) ;
if ( V_160 )
F_70 () ;
while ( V_162 -- )
F_36 ( V_4 ) ;
while ( V_131 ) {
V_141 = F_24 ( V_131 , struct V_140 , V_63 ) ;
V_131 = V_131 -> V_137 ;
F_45 ( V_141 ) ;
}
}
void F_34 ( struct V_3 * V_4 )
{
unsigned long V_163 = V_62 ;
unsigned long V_141 ;
F_41 ( & V_57 ) ;
if ( V_4 -> V_143 ) {
F_44 ( & V_57 ) ;
return;
}
if ( V_4 -> V_82 )
V_141 = ( ( V_163 / V_4 -> V_82 ) + 1 ) * V_4 -> V_82 ;
else
V_141 = V_163 + 1 ;
V_4 -> V_143 = 1 ;
F_44 ( & V_57 ) ;
F_53 ( V_4 , V_142 , V_141 , 0 ) ;
}
struct V_3 * F_52 ( T_1 * V_20 )
{
struct V_3 * V_4 ;
struct V_59 * V_60 ;
F_21 ( & V_57 ) ;
F_23 (e, &g_pd_list) {
V_4 = F_24 ( V_60 , struct V_3 , V_63 ) ;
if ( memcmp ( V_4 -> V_20 , V_20 , V_64 ) == 0 ) {
F_76 ( & V_4 -> V_164 ) ;
F_26 ( & V_57 ) ;
return V_4 ;
}
}
F_26 ( & V_57 ) ;
return 0 ;
}
void F_77 ( int V_130 , int V_165 )
{
if ( V_130 <= V_166 ) {
F_21 ( & V_57 ) ;
if ( V_165 )
V_54 |= ( 1 << V_130 ) ;
else
V_54 &= ~ ( 1 << V_130 ) ;
F_26 ( & V_57 ) ;
}
}
static int F_78 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_167 * V_168 , struct V_8 * V_169 )
{
F_13 ( V_170 , 0 , 0 , 0 , 0 ) ;
V_7 = F_79 ( V_7 , V_17 ) ;
if ( V_7 == 0 )
return 0 ;
F_21 ( & V_171 . V_172 ) ;
if ( V_173 ) {
F_80 ( & V_171 , V_7 ) ;
F_26 ( & V_171 . V_172 ) ;
} else {
V_173 = 1 ;
do {
F_26 ( & V_171 . V_172 ) ;
F_46 ( V_7 ) ;
F_21 ( & V_171 . V_172 ) ;
if ( F_81 ( & V_171 ) ) {
V_173 = 0 ;
F_26 ( & V_171 . V_172 ) ;
break;
}
V_7 = F_82 ( & V_171 ) ;
} while ( 1 );
}
return 0 ;
}
void F_83 ( char * V_10 )
{
struct V_135 * V_174 ;
V_174 = F_40 ( sizeof( struct V_135 ) , V_175 ) ;
if ( V_174 ) {
V_174 -> V_138 . type = F_84 ( V_19 ) ;
V_174 -> V_138 . V_176 = F_78 ;
memcpy ( V_174 -> V_177 , V_10 , V_178 ) ;
if ( V_10 && * V_10 ) {
F_15 ( L_19 , V_10 ) ;
V_174 -> V_138 . V_9 =
F_85 ( & V_179 , V_10 ) ;
if ( V_174 -> V_138 . V_9 == 0 ) {
F_15 ( L_20 , V_10 ) ;
F_45 ( V_174 ) ;
V_174 = 0 ;
}
} else {
F_15 ( L_21 ) ;
V_174 -> V_138 . V_9 = 0 ;
}
if ( V_174 ) {
F_86 ( & V_174 -> V_138 ) ;
F_21 ( & V_133 ) ;
V_174 -> V_137 = V_134 ;
V_134 = V_174 ;
F_26 ( & V_133 ) ;
}
}
}
static int F_87 ( char * V_180 , char * V_181 )
{
int V_182 ;
for ( V_182 = 0 ; V_182 < V_178 ; V_182 ++ ) {
if ( * V_180 != * V_181 )
return 0 ;
if ( ! * V_180 ++ )
return 1 ;
V_181 ++ ;
}
return 1 ;
}
static void F_88 ( struct V_8 * V_10 )
{
struct V_59 V_183 ;
struct V_3 * V_4 ;
struct V_3 * V_161 ;
F_89 ( & V_183 ) ;
F_21 ( & V_57 ) ;
F_74 (pd, n, &g_pd_list, link) {
if ( V_4 -> V_10 == V_10 ) {
F_90 ( & V_4 -> V_63 , & V_183 ) ;
F_65 ( V_4 ) ;
}
}
F_26 ( & V_57 ) ;
while ( ! F_63 ( & V_183 ) ) {
V_4 = F_64 ( & V_183 , struct V_3 , V_63 ) ;
F_35 ( V_4 ) ;
F_36 ( V_4 ) ;
}
}
void F_91 ( char * V_10 )
{
struct V_135 * V_174 = 0 ;
struct V_135 * * V_63 ;
F_15 ( L_22 , V_10 ) ;
F_21 ( & V_133 ) ;
V_174 = V_134 ;
V_63 = & V_134 ;
while ( V_174 ) {
if ( F_87 ( V_174 -> V_177 , V_10 ) ) {
F_15 ( L_23 , V_10 ) ;
* V_63 = V_174 -> V_137 ;
break;
} else {
V_63 = & V_174 ;
V_174 = V_174 -> V_137 ;
}
}
F_26 ( & V_133 ) ;
if ( V_174 ) {
F_62 ( & V_174 -> V_138 ) ;
if ( V_174 -> V_138 . V_9 ) {
F_37 ( V_174 -> V_138 . V_9 ) ;
F_88 ( V_174 -> V_138 . V_9 ) ;
}
F_45 ( V_174 ) ;
}
}
static char * F_92 ( char * V_184 , char * V_185 , int V_186 )
{
while ( * V_184 == ',' )
V_184 ++ ;
while ( * V_184 && ( * V_184 != ',' ) && V_186 > 1 ) {
* V_185 ++ = * V_184 ++ ;
V_186 -- ;
}
* V_185 = 0 ;
return V_184 ;
}
int F_93 ( char * V_187 )
{
F_94 ( & V_171 ) ;
if ( V_187 && ( V_187 [ 0 ] == '*' ) ) {
F_83 ( 0 ) ;
} else {
char V_188 [ 32 ] ;
while ( * V_187 ) {
V_187 = F_92 ( V_187 , V_188 , sizeof( V_188 ) ) ;
if ( V_188 [ 0 ] )
F_83 ( V_188 ) ;
}
}
F_95 ( & V_132 ) ;
return 0 ;
}
int F_96 ( struct V_189 * V_190 , int V_191 )
{
struct V_3 * V_4 ;
struct V_59 * V_60 ;
int V_192 = 0 ;
F_21 ( & V_57 ) ;
F_23 (e, &g_pd_list) {
if ( V_192 >= V_191 )
break;
V_4 = F_24 ( V_60 , struct V_3 , V_63 ) ;
memcpy ( & V_190 [ V_192 ++ ] , V_4 -> V_20 , V_64 ) ;
}
F_26 ( & V_57 ) ;
return V_192 ;
}
void F_97 ( void )
{
F_21 ( & V_57 ) ;
}
void F_98 ( void )
{
F_26 ( & V_57 ) ;
}
