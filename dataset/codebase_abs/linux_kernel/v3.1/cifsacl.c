static void
F_1 ( struct V_1 * V_2 , int V_3 , int * V_4 ,
int * V_5 )
{
struct V_6 * V_7 ;
struct V_6 * V_8 ;
struct V_9 * V_10 ;
V_7 = F_2 ( V_2 ) ;
while ( V_7 ) {
V_8 = V_7 ;
V_7 = F_3 ( V_8 ) ;
V_10 = F_4 ( V_8 , struct V_9 , V_11 ) ;
if ( V_3 == 0 || * V_5 == V_3 )
++ ( * V_4 ) ;
else {
if ( F_5 ( V_12 , V_10 -> time + V_13 )
&& V_10 -> V_14 == 0 ) {
F_6 ( V_8 , V_2 ) ;
++ ( * V_5 ) ;
} else
++ ( * V_4 ) ;
}
}
}
static int
F_7 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
int V_3 = V_18 -> V_3 ;
int V_5 = 0 ;
int V_4 = 0 ;
struct V_1 * V_2 ;
V_2 = & V_19 ;
F_8 ( & V_20 ) ;
F_1 ( V_2 , V_3 , & V_4 , & V_5 ) ;
F_9 ( & V_20 ) ;
V_2 = & V_21 ;
F_8 ( & V_22 ) ;
F_1 ( V_2 , V_3 , & V_4 , & V_5 ) ;
F_9 ( & V_22 ) ;
return V_4 ;
}
static int
F_10 ( struct V_23 * V_23 , const void * V_24 , T_1 V_25 )
{
char * V_26 ;
V_26 = F_11 ( V_25 , V_27 ) ;
if ( ! V_26 )
return - V_28 ;
memcpy ( V_26 , V_24 , V_25 ) ;
V_23 -> V_26 . V_24 = V_26 ;
return 0 ;
}
static inline void
F_12 ( struct V_23 * V_23 )
{
F_13 ( V_23 -> V_26 . V_24 ) ;
}
static void
F_14 ( struct V_29 * V_30 , char * V_31 )
{
int V_32 ;
unsigned long V_33 ;
char * V_34 ;
V_34 = V_31 ;
sprintf ( V_34 , L_1 , L_2 ) ;
V_34 = V_31 + strlen ( V_31 ) ;
sprintf ( V_34 , L_3 , V_30 -> V_35 ) ;
V_34 = V_31 + strlen ( V_31 ) ;
for ( V_32 = 0 ; V_32 < 6 ; ++ V_32 ) {
if ( V_30 -> V_36 [ V_32 ] ) {
sprintf ( V_34 , L_3 , V_30 -> V_36 [ V_32 ] ) ;
V_34 = V_31 + strlen ( V_31 ) ;
}
}
for ( V_32 = 0 ; V_32 < V_30 -> V_37 ; ++ V_32 ) {
V_33 = F_15 ( V_30 -> V_38 [ V_32 ] ) ;
sprintf ( V_34 , L_4 , V_33 ) ;
V_34 = V_31 + strlen ( V_31 ) ;
}
}
static void
F_16 ( struct V_1 * V_2 , struct V_29 * V_30 ,
struct V_9 * * V_10 , char * V_39 )
{
int V_40 ;
char * V_34 ;
struct V_6 * V_7 = V_2 -> V_6 ;
struct V_6 * V_41 = NULL ;
struct V_6 * * V_42 = & ( V_2 -> V_6 ) ;
struct V_9 * V_43 ;
while ( V_7 ) {
V_43 = F_4 ( V_7 , struct V_9 , V_11 ) ;
V_41 = V_7 ;
V_40 = F_17 ( V_30 , & ( ( V_43 ) -> V_44 ) ) ;
if ( V_40 > 0 ) {
V_42 = & ( V_7 -> V_45 ) ;
V_7 = V_7 -> V_45 ;
} else if ( V_40 < 0 ) {
V_42 = & ( V_7 -> V_46 ) ;
V_7 = V_7 -> V_46 ;
}
}
memcpy ( & ( * V_10 ) -> V_44 , V_30 , sizeof( struct V_29 ) ) ;
( * V_10 ) -> time = V_12 - ( V_47 + 1 ) ;
( * V_10 ) -> V_14 = 0 ;
sprintf ( ( * V_10 ) -> V_31 , L_1 , V_39 ) ;
V_34 = ( * V_10 ) -> V_31 + strlen ( ( * V_10 ) -> V_31 ) ;
F_14 ( & ( * V_10 ) -> V_44 , V_34 ) ;
F_18 ( V_48 , & ( * V_10 ) -> V_49 ) ;
F_18 ( V_50 , & ( * V_10 ) -> V_49 ) ;
F_19 ( & ( * V_10 ) -> V_11 , V_41 , V_42 ) ;
F_20 ( & ( * V_10 ) -> V_11 , V_2 ) ;
}
static struct V_9 *
F_21 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
int V_40 ;
struct V_6 * V_7 = V_2 -> V_6 ;
struct V_9 * V_43 ;
while ( V_7 ) {
V_43 = F_4 ( V_7 , struct V_9 , V_11 ) ;
V_40 = F_17 ( V_30 , & ( ( V_43 ) -> V_44 ) ) ;
if ( V_40 > 0 ) {
V_7 = V_7 -> V_45 ;
} else if ( V_40 < 0 ) {
V_7 = V_7 -> V_46 ;
} else
return V_43 ;
}
return NULL ;
}
static int
F_22 ( void * V_51 )
{
F_23 () ;
return F_24 ( V_52 ) ? - V_53 : 0 ;
}
static int
F_25 ( struct V_54 * V_55 , struct V_29 * V_56 ,
struct V_57 * V_58 , T_2 V_59 )
{
int V_40 ;
unsigned long V_60 ;
struct V_23 * V_61 ;
const struct V_62 * V_63 ;
struct V_9 * V_10 , * V_64 ;
struct V_1 * V_65 ;
T_3 * V_66 ;
if ( V_59 == V_67 ) {
V_60 = V_55 -> V_68 ;
V_66 = & V_20 ;
V_65 = & V_19 ;
} else if ( V_59 == V_69 ) {
V_60 = V_55 -> V_70 ;
V_66 = & V_22 ;
V_65 = & V_21 ;
} else
return - V_71 ;
F_8 ( V_66 ) ;
V_10 = F_21 ( V_65 , V_56 ) ;
if ( ! V_10 ) {
F_9 ( V_66 ) ;
V_64 = F_26 ( sizeof( struct V_9 ) , V_27 ) ;
if ( ! V_64 )
return - V_28 ;
V_64 -> V_31 = F_11 ( V_72 , V_27 ) ;
if ( ! V_64 -> V_31 ) {
F_13 ( V_64 ) ;
return - V_28 ;
}
F_8 ( V_66 ) ;
V_10 = F_21 ( V_65 , V_56 ) ;
if ( V_10 ) {
++ V_10 -> V_14 ;
F_9 ( V_66 ) ;
F_13 ( V_64 -> V_31 ) ;
F_13 ( V_64 ) ;
} else {
V_10 = V_64 ;
F_16 ( V_65 , V_56 , & V_10 ,
V_59 == V_67 ? L_5 : L_6 ) ;
++ V_10 -> V_14 ;
F_9 ( V_66 ) ;
}
} else {
++ V_10 -> V_14 ;
F_9 ( V_66 ) ;
}
if ( F_27 ( V_50 , & V_10 -> V_49 ) ) {
V_60 = V_10 -> V_73 ;
V_10 -> time = V_12 ;
goto V_74;
}
if ( F_5 ( V_10 -> time + V_47 , V_12 ) )
goto V_74;
if ( ! F_28 ( V_48 , & V_10 -> V_49 ) ) {
V_63 = F_29 ( V_75 ) ;
V_61 = F_30 ( & V_76 , V_10 -> V_31 , L_7 ) ;
if ( F_31 ( V_61 ) )
F_32 ( 1 , L_8 , V_77 ) ;
else {
V_60 = * ( unsigned long * ) V_61 -> V_26 . V_78 ;
V_10 -> V_73 = V_60 ;
F_33 ( V_50 , & V_10 -> V_49 ) ;
F_34 ( V_61 ) ;
F_13 ( V_10 -> V_31 ) ;
}
F_35 ( V_63 ) ;
V_10 -> time = V_12 ;
F_18 ( V_48 , & V_10 -> V_49 ) ;
F_36 ( & V_10 -> V_49 , V_48 ) ;
} else {
V_40 = F_37 ( & V_10 -> V_49 , V_48 ,
F_22 , V_79 ) ;
if ( V_40 ) {
F_32 ( 1 , L_9 ,
V_77 , V_40 ) ;
-- V_10 -> V_14 ;
return V_40 ;
}
if ( F_27 ( V_50 , & V_10 -> V_49 ) )
V_60 = V_10 -> V_73 ;
}
V_74:
-- V_10 -> V_14 ;
if ( V_59 == V_67 )
V_58 -> V_80 = V_60 ;
else
V_58 -> V_81 = V_60 ;
return 0 ;
}
int
F_38 ( void )
{
struct V_62 * V_62 ;
struct V_23 * V_82 ;
int V_83 ;
F_32 ( 1 , L_10 , V_76 . V_84 ) ;
V_62 = F_39 ( NULL ) ;
if ( ! V_62 )
return - V_28 ;
V_82 = F_40 ( & V_85 , L_11 , 0 , 0 , V_62 ,
( V_86 & ~ V_87 ) |
V_88 | V_89 ,
V_90 ) ;
if ( F_31 ( V_82 ) ) {
V_83 = F_41 ( V_82 ) ;
goto V_91;
}
V_83 = F_42 ( V_82 , NULL , 0 , NULL , NULL ) ;
if ( V_83 < 0 )
goto V_92;
V_83 = F_43 ( & V_76 ) ;
if ( V_83 < 0 )
goto V_92;
V_62 -> V_93 = V_82 ;
V_62 -> V_94 = V_95 ;
V_75 = V_62 ;
F_44 ( & V_20 ) ;
V_19 = V_96 ;
F_44 ( & V_22 ) ;
V_21 = V_96 ;
F_45 ( & V_97 ) ;
F_32 ( 1 , L_12 , F_46 ( V_82 ) ) ;
return 0 ;
V_92:
F_34 ( V_82 ) ;
V_91:
F_47 ( V_62 ) ;
return V_83 ;
}
void
F_48 ( void )
{
F_49 ( V_75 -> V_93 ) ;
F_50 ( & V_76 ) ;
F_47 ( V_75 ) ;
F_51 ( & V_97 ) ;
F_32 ( 1 , L_13 , V_76 . V_84 ) ;
}
void
F_52 ( void )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
V_2 = & V_19 ;
F_8 ( & V_20 ) ;
while ( ( V_7 = F_2 ( V_2 ) ) )
F_6 ( V_7 , V_2 ) ;
F_9 ( & V_20 ) ;
V_2 = & V_21 ;
F_8 ( & V_22 ) ;
while ( ( V_7 = F_2 ( V_2 ) ) )
F_6 ( V_7 , V_2 ) ;
F_9 ( & V_22 ) ;
}
int F_17 ( const struct V_29 * V_98 , const struct V_29 * V_99 )
{
int V_32 ;
int V_37 , V_100 , V_101 ;
if ( ( ! V_98 ) || ( ! V_99 ) )
return 1 ;
if ( V_98 -> V_35 != V_99 -> V_35 ) {
if ( V_98 -> V_35 > V_99 -> V_35 )
return 1 ;
else
return - 1 ;
}
for ( V_32 = 0 ; V_32 < 6 ; ++ V_32 ) {
if ( V_98 -> V_36 [ V_32 ] != V_99 -> V_36 [ V_32 ] ) {
if ( V_98 -> V_36 [ V_32 ] > V_99 -> V_36 [ V_32 ] )
return 1 ;
else
return - 1 ;
}
}
V_100 = V_98 -> V_37 ;
V_101 = V_99 -> V_37 ;
V_37 = V_100 < V_101 ? V_100 : V_101 ;
if ( V_37 ) {
for ( V_32 = 0 ; V_32 < V_37 ; ++ V_32 ) {
if ( V_98 -> V_38 [ V_32 ] != V_99 -> V_38 [ V_32 ] ) {
if ( F_15 ( V_98 -> V_38 [ V_32 ] ) >
F_15 ( V_99 -> V_38 [ V_32 ] ) )
return 1 ;
else
return - 1 ;
}
}
}
return 0 ;
}
static void F_53 ( const struct V_102 * V_103 ,
struct V_102 * V_104 , T_4 V_105 )
{
int V_32 ;
struct V_29 * V_106 , * V_107 ;
struct V_29 * V_108 , * V_109 ;
V_104 -> V_35 = V_103 -> V_35 ;
V_104 -> type = V_103 -> type ;
V_104 -> V_110 = F_54 ( sizeof( struct V_102 ) ) ;
V_104 -> V_111 = 0 ;
V_104 -> V_112 = F_54 ( V_105 ) ;
V_104 -> V_113 = F_54 ( V_105 + sizeof( struct V_29 ) ) ;
V_106 = (struct V_29 * ) ( ( char * ) V_103 +
F_15 ( V_103 -> V_112 ) ) ;
V_108 = (struct V_29 * ) ( ( char * ) V_104 + V_105 ) ;
V_108 -> V_35 = V_106 -> V_35 ;
V_108 -> V_37 = V_106 -> V_37 ;
for ( V_32 = 0 ; V_32 < 6 ; V_32 ++ )
V_108 -> V_36 [ V_32 ] = V_106 -> V_36 [ V_32 ] ;
for ( V_32 = 0 ; V_32 < 5 ; V_32 ++ )
V_108 -> V_38 [ V_32 ] = V_106 -> V_38 [ V_32 ] ;
V_107 = (struct V_29 * ) ( ( char * ) V_103 +
F_15 ( V_103 -> V_113 ) ) ;
V_109 = (struct V_29 * ) ( ( char * ) V_104 + V_105 +
sizeof( struct V_29 ) ) ;
V_109 -> V_35 = V_107 -> V_35 ;
V_109 -> V_37 = V_107 -> V_37 ;
for ( V_32 = 0 ; V_32 < 6 ; V_32 ++ )
V_109 -> V_36 [ V_32 ] = V_107 -> V_36 [ V_32 ] ;
for ( V_32 = 0 ; V_32 < 5 ; V_32 ++ )
V_109 -> V_38 [ V_32 ] = V_107 -> V_38 [ V_32 ] ;
return;
}
static void F_55 ( T_5 V_114 , int type , T_6 * V_115 ,
T_6 * V_116 )
{
T_4 V_117 = F_15 ( V_114 ) ;
if ( type == V_118 ) {
if ( V_117 & V_119 )
* V_116 &= ~ V_120 ;
if ( ( V_117 & V_121 ) ||
( ( V_117 & V_122 ) == V_122 ) )
* V_116 &= ~ V_123 ;
if ( ( V_117 & V_124 ) ||
( ( V_117 & V_125 ) == V_125 ) )
* V_116 &= ~ V_126 ;
if ( ( V_117 & V_127 ) ||
( ( V_117 & V_128 ) == V_128 ) )
* V_116 &= ~ V_129 ;
return;
} else if ( type != V_130 ) {
F_56 ( 1 , L_14 , type ) ;
return;
}
if ( V_117 & V_119 ) {
* V_115 |= ( V_120 & ( * V_116 ) ) ;
F_32 ( V_131 , L_15 ) ;
return;
}
if ( ( V_117 & V_121 ) ||
( ( V_117 & V_122 ) == V_122 ) )
* V_115 |= ( V_123 & ( * V_116 ) ) ;
if ( ( V_117 & V_124 ) ||
( ( V_117 & V_125 ) == V_125 ) )
* V_115 |= ( V_126 & ( * V_116 ) ) ;
if ( ( V_117 & V_127 ) ||
( ( V_117 & V_128 ) == V_128 ) )
* V_115 |= ( V_129 & ( * V_116 ) ) ;
F_32 ( V_131 , L_16 , V_117 , * V_115 ) ;
return;
}
static void F_57 ( T_6 V_132 , T_6 V_133 ,
T_4 * V_134 )
{
* V_134 = 0x0 ;
V_132 &= V_133 ;
if ( V_132 & V_126 )
* V_134 |= V_135 ;
if ( V_132 & V_123 )
* V_134 |= V_136 ;
if ( V_132 & V_129 )
* V_134 |= V_137 ;
F_32 ( V_131 , L_17 , V_132 , * V_134 ) ;
return;
}
static T_7 F_58 ( struct V_138 * V_139 ,
const struct V_29 * V_56 , T_8 V_140 , T_6 V_141 )
{
int V_32 ;
T_7 V_142 = 0 ;
T_4 V_143 = 0 ;
V_139 -> type = V_130 ;
V_139 -> V_117 = 0x0 ;
F_57 ( V_140 , V_141 , & V_143 ) ;
if ( ! V_143 )
V_143 = V_144 ;
V_139 -> V_143 = F_54 ( V_143 ) ;
V_139 -> V_44 . V_35 = V_56 -> V_35 ;
V_139 -> V_44 . V_37 = V_56 -> V_37 ;
for ( V_32 = 0 ; V_32 < 6 ; V_32 ++ )
V_139 -> V_44 . V_36 [ V_32 ] = V_56 -> V_36 [ V_32 ] ;
for ( V_32 = 0 ; V_32 < V_56 -> V_37 ; V_32 ++ )
V_139 -> V_44 . V_38 [ V_32 ] = V_56 -> V_38 [ V_32 ] ;
V_142 = 1 + 1 + 2 + 4 + 1 + 1 + 6 + ( V_56 -> V_37 * 4 ) ;
V_139 -> V_142 = F_59 ( V_142 ) ;
return V_142 ;
}
static void F_60 ( struct V_138 * V_145 , char * V_146 )
{
int V_37 ;
if ( F_61 ( V_145 -> V_142 ) < 16 ) {
F_56 ( 1 , L_18 , F_61 ( V_145 -> V_142 ) ) ;
return;
}
if ( V_146 < ( char * ) V_145 + F_61 ( V_145 -> V_142 ) ) {
F_56 ( 1 , L_19 ) ;
return;
}
V_37 = V_145 -> V_44 . V_37 ;
if ( V_37 ) {
int V_32 ;
F_32 ( 1 , L_20 ,
V_145 -> V_44 . V_35 , V_145 -> V_44 . V_37 , V_145 -> type ,
V_145 -> V_117 , F_61 ( V_145 -> V_142 ) ) ;
for ( V_32 = 0 ; V_32 < V_37 ; ++ V_32 ) {
F_32 ( 1 , L_21 , V_32 ,
F_15 ( V_145 -> V_44 . V_38 [ V_32 ] ) ) ;
}
}
return;
}
static void F_62 ( struct V_147 * V_148 , char * V_146 ,
struct V_29 * V_149 , struct V_29 * V_150 ,
struct V_57 * V_58 )
{
int V_32 ;
int V_151 = 0 ;
int V_152 ;
char * V_153 ;
struct V_138 * * V_154 ;
if ( ! V_148 ) {
V_58 -> V_155 |= V_120 ;
return;
}
if ( V_146 < ( char * ) V_148 + F_61 ( V_148 -> V_142 ) ) {
F_56 ( 1 , L_22 ) ;
return;
}
F_32 ( V_131 , L_23 ,
F_61 ( V_148 -> V_35 ) , F_61 ( V_148 -> V_142 ) ,
F_15 ( V_148 -> V_151 ) ) ;
V_58 -> V_155 &= ~ ( V_120 ) ;
V_153 = ( char * ) V_148 ;
V_152 = sizeof( struct V_147 ) ;
V_151 = F_15 ( V_148 -> V_151 ) ;
if ( V_151 > 0 ) {
T_6 V_156 = V_157 ;
T_6 V_158 = V_159 ;
T_6 V_160 = V_157 | V_159 | V_161 ;
V_154 = F_11 ( V_151 * sizeof( struct V_138 * ) ,
V_27 ) ;
if ( ! V_154 ) {
F_56 ( 1 , L_24 ) ;
return;
}
for ( V_32 = 0 ; V_32 < V_151 ; ++ V_32 ) {
V_154 [ V_32 ] = (struct V_138 * ) ( V_153 + V_152 ) ;
#ifdef F_63
F_60 ( V_154 [ V_32 ] , V_146 ) ;
#endif
if ( F_17 ( & ( V_154 [ V_32 ] -> V_44 ) , V_149 ) == 0 )
F_55 ( V_154 [ V_32 ] -> V_143 ,
V_154 [ V_32 ] -> type ,
& V_58 -> V_155 ,
& V_156 ) ;
if ( F_17 ( & ( V_154 [ V_32 ] -> V_44 ) , V_150 ) == 0 )
F_55 ( V_154 [ V_32 ] -> V_143 ,
V_154 [ V_32 ] -> type ,
& V_58 -> V_155 ,
& V_158 ) ;
if ( F_17 ( & ( V_154 [ V_32 ] -> V_44 ) , & V_162 ) == 0 )
F_55 ( V_154 [ V_32 ] -> V_143 ,
V_154 [ V_32 ] -> type ,
& V_58 -> V_155 ,
& V_160 ) ;
if ( F_17 ( & ( V_154 [ V_32 ] -> V_44 ) , & V_163 ) == 0 )
F_55 ( V_154 [ V_32 ] -> V_143 ,
V_154 [ V_32 ] -> type ,
& V_58 -> V_155 ,
& V_160 ) ;
V_153 = ( char * ) V_154 [ V_32 ] ;
V_152 = F_61 ( V_154 [ V_32 ] -> V_142 ) ;
}
F_13 ( V_154 ) ;
}
return;
}
static int F_64 ( struct V_147 * V_164 , struct V_29 * V_149 ,
struct V_29 * V_150 , T_8 V_140 )
{
T_9 V_142 = 0 ;
struct V_147 * V_165 ;
V_165 = (struct V_147 * ) ( ( char * ) V_164 + sizeof( struct V_147 ) ) ;
V_142 += F_58 ( (struct V_138 * ) ( ( char * ) V_165 + V_142 ) ,
V_149 , V_140 , V_157 ) ;
V_142 += F_58 ( (struct V_138 * ) ( ( char * ) V_165 + V_142 ) ,
V_150 , V_140 , V_159 ) ;
V_142 += F_58 ( (struct V_138 * ) ( ( char * ) V_165 + V_142 ) ,
& V_162 , V_140 , V_161 ) ;
V_164 -> V_142 = F_59 ( V_142 + sizeof( struct V_147 ) ) ;
V_164 -> V_151 = F_54 ( 3 ) ;
return 0 ;
}
static int F_65 ( struct V_29 * V_56 , char * V_146 )
{
if ( V_146 < ( char * ) V_56 + 8 ) {
F_56 ( 1 , L_25 , V_56 ) ;
return - V_166 ;
}
if ( V_56 -> V_37 ) {
#ifdef F_63
int V_32 ;
F_32 ( 1 , L_26 ,
V_56 -> V_35 , V_56 -> V_37 ) ;
for ( V_32 = 0 ; V_32 < V_56 -> V_37 ; V_32 ++ ) {
F_32 ( 1 , L_27 , V_32 ,
F_15 ( V_56 -> V_38 [ V_32 ] ) ) ;
}
F_32 ( 1 , L_28 ,
F_15 ( V_56 -> V_38 [ V_56 -> V_37 - 1 ] ) ) ;
#endif
}
return 0 ;
}
static int F_66 ( struct V_54 * V_55 ,
struct V_102 * V_103 , int V_167 , struct V_57 * V_58 )
{
int V_40 = 0 ;
struct V_29 * V_106 , * V_107 ;
struct V_147 * V_168 ;
char * V_146 = ( ( char * ) V_103 ) + V_167 ;
T_4 V_110 ;
if ( V_103 == NULL )
return - V_169 ;
V_106 = (struct V_29 * ) ( ( char * ) V_103 +
F_15 ( V_103 -> V_112 ) ) ;
V_107 = (struct V_29 * ) ( ( char * ) V_103 +
F_15 ( V_103 -> V_113 ) ) ;
V_110 = F_15 ( V_103 -> V_110 ) ;
V_168 = (struct V_147 * ) ( ( char * ) V_103 + V_110 ) ;
F_32 ( V_131 , L_29
L_30 ,
V_103 -> V_35 , V_103 -> type , F_15 ( V_103 -> V_112 ) ,
F_15 ( V_103 -> V_113 ) ,
F_15 ( V_103 -> V_111 ) , V_110 ) ;
V_40 = F_65 ( V_106 , V_146 ) ;
if ( V_40 ) {
F_32 ( 1 , L_31 , V_77 , V_40 ) ;
return V_40 ;
}
V_40 = F_25 ( V_55 , V_106 , V_58 , V_67 ) ;
if ( V_40 ) {
F_32 ( 1 , L_32 , V_77 , V_40 ) ;
return V_40 ;
}
V_40 = F_65 ( V_107 , V_146 ) ;
if ( V_40 ) {
F_32 ( 1 , L_33 , V_77 , V_40 ) ;
return V_40 ;
}
V_40 = F_25 ( V_55 , V_107 , V_58 , V_69 ) ;
if ( V_40 ) {
F_32 ( 1 , L_34 , V_77 , V_40 ) ;
return V_40 ;
}
if ( V_110 )
F_62 ( V_168 , V_146 , V_106 ,
V_107 , V_58 ) ;
else
F_32 ( 1 , L_35 ) ;
return V_40 ;
}
static int F_67 ( struct V_102 * V_103 , struct V_102 * V_104 ,
struct V_170 * V_170 , T_8 V_140 )
{
int V_40 = 0 ;
T_4 V_110 ;
T_4 V_171 ;
T_4 V_105 ;
struct V_29 * V_106 , * V_107 ;
struct V_147 * V_168 = NULL ;
struct V_147 * V_172 = NULL ;
if ( ( V_170 == NULL ) || ( V_103 == NULL ) || ( V_104 == NULL ) )
return - V_169 ;
V_106 = (struct V_29 * ) ( ( char * ) V_103 +
F_15 ( V_103 -> V_112 ) ) ;
V_107 = (struct V_29 * ) ( ( char * ) V_103 +
F_15 ( V_103 -> V_113 ) ) ;
V_110 = F_15 ( V_103 -> V_110 ) ;
V_168 = (struct V_147 * ) ( ( char * ) V_103 + V_110 ) ;
V_171 = sizeof( struct V_102 ) ;
V_172 = (struct V_147 * ) ( ( char * ) V_104 + V_171 ) ;
V_172 -> V_35 = V_168 -> V_35 ;
V_172 -> V_142 = 0 ;
V_172 -> V_151 = 0 ;
V_40 = F_64 ( V_172 , V_106 , V_107 , V_140 ) ;
V_105 = V_171 + F_61 ( V_172 -> V_142 ) ;
F_53 ( V_103 , V_104 , V_105 ) ;
return V_40 ;
}
static struct V_102 * F_68 ( struct V_54 * V_55 ,
T_7 V_173 , T_10 * V_174 )
{
struct V_102 * V_103 = NULL ;
int V_175 , V_40 ;
struct V_176 * V_177 = F_69 ( V_55 ) ;
if ( F_31 ( V_177 ) )
return F_70 ( V_177 ) ;
V_175 = F_71 () ;
V_40 = F_72 ( V_175 , F_73 ( V_177 ) , V_173 , & V_103 , V_174 ) ;
F_74 ( V_175 ) ;
F_75 ( V_177 ) ;
F_32 ( 1 , L_36 , V_77 , V_40 , * V_174 ) ;
if ( V_40 )
return F_76 ( V_40 ) ;
return V_103 ;
}
static struct V_102 * F_77 ( struct V_54 * V_55 ,
const char * V_178 , T_10 * V_174 )
{
struct V_102 * V_103 = NULL ;
int V_179 = 0 ;
int V_175 , V_40 ;
T_7 V_173 ;
struct V_180 * V_181 ;
struct V_176 * V_177 = F_69 ( V_55 ) ;
if ( F_31 ( V_177 ) )
return F_70 ( V_177 ) ;
V_181 = F_73 ( V_177 ) ;
V_175 = F_71 () ;
V_40 = F_78 ( V_175 , V_181 , V_178 , V_182 , V_183 , 0 ,
& V_173 , & V_179 , NULL , V_55 -> V_184 ,
V_55 -> V_185 & V_186 ) ;
if ( ! V_40 ) {
V_40 = F_72 ( V_175 , V_181 , V_173 , & V_103 , V_174 ) ;
F_79 ( V_175 , V_181 , V_173 ) ;
}
F_75 ( V_177 ) ;
F_74 ( V_175 ) ;
F_32 ( 1 , L_36 , V_77 , V_40 , * V_174 ) ;
if ( V_40 )
return F_76 ( V_40 ) ;
return V_103 ;
}
struct V_102 * F_80 ( struct V_54 * V_55 ,
struct V_170 * V_170 , const char * V_178 ,
T_10 * V_174 )
{
struct V_102 * V_103 = NULL ;
struct V_187 * V_188 = NULL ;
if ( V_170 )
V_188 = F_81 ( F_82 ( V_170 ) , true ) ;
if ( ! V_188 )
return F_77 ( V_55 , V_178 , V_174 ) ;
V_103 = F_68 ( V_55 , V_188 -> V_189 , V_174 ) ;
F_83 ( V_188 ) ;
return V_103 ;
}
static int F_84 ( struct V_54 * V_55 , const char * V_178 ,
struct V_102 * V_104 , T_10 V_190 )
{
int V_179 = 0 ;
int V_175 , V_40 ;
T_7 V_173 ;
struct V_180 * V_181 ;
struct V_176 * V_177 = F_69 ( V_55 ) ;
if ( F_31 ( V_177 ) )
return F_41 ( V_177 ) ;
V_181 = F_73 ( V_177 ) ;
V_175 = F_71 () ;
V_40 = F_78 ( V_175 , V_181 , V_178 , V_182 , V_191 , 0 ,
& V_173 , & V_179 , NULL , V_55 -> V_184 ,
V_55 -> V_185 & V_186 ) ;
if ( V_40 ) {
F_56 ( 1 , L_37 ) ;
goto V_192;
}
V_40 = F_85 ( V_175 , V_181 , V_173 , V_104 , V_190 ) ;
F_32 ( V_131 , L_38 , V_40 ) ;
F_79 ( V_175 , V_181 , V_173 ) ;
V_192:
F_74 ( V_175 ) ;
F_75 ( V_177 ) ;
return V_40 ;
}
int F_86 ( struct V_102 * V_104 , T_4 V_190 ,
struct V_170 * V_170 , const char * V_178 )
{
struct V_54 * V_55 = F_87 ( V_170 -> V_193 ) ;
F_32 ( V_131 , L_39 , V_178 , V_170 -> V_194 ) ;
return F_84 ( V_55 , V_178 , V_104 , V_190 ) ;
}
int
F_88 ( struct V_54 * V_55 , struct V_57 * V_58 ,
struct V_170 * V_170 , const char * V_178 , const T_7 * V_195 )
{
struct V_102 * V_103 = NULL ;
T_10 V_190 = 0 ;
int V_40 = 0 ;
F_32 ( V_131 , L_40 , V_178 ) ;
if ( V_195 )
V_103 = F_68 ( V_55 , * V_195 , & V_190 ) ;
else
V_103 = F_80 ( V_55 , V_170 , V_178 , & V_190 ) ;
if ( F_31 ( V_103 ) ) {
V_40 = F_41 ( V_103 ) ;
F_56 ( 1 , L_41 , V_77 , V_40 ) ;
} else {
V_40 = F_66 ( V_55 , V_103 , V_190 , V_58 ) ;
F_13 ( V_103 ) ;
if ( V_40 )
F_56 ( 1 , L_42 , V_40 ) ;
}
return V_40 ;
}
int F_89 ( struct V_170 * V_170 , const char * V_178 , T_8 V_140 )
{
int V_40 = 0 ;
T_4 V_196 = 0 ;
struct V_102 * V_103 = NULL ;
struct V_102 * V_104 = NULL ;
F_32 ( V_131 , L_43 , V_178 ) ;
V_103 = F_80 ( F_87 ( V_170 -> V_193 ) , V_170 , V_178 , & V_196 ) ;
if ( F_31 ( V_103 ) ) {
V_40 = F_41 ( V_103 ) ;
F_56 ( 1 , L_41 , V_77 , V_40 ) ;
} else {
V_196 = V_196 < V_197 ?
V_197 : V_196 ;
V_104 = F_11 ( V_196 , V_27 ) ;
if ( ! V_104 ) {
F_56 ( 1 , L_44 ) ;
F_13 ( V_103 ) ;
return - V_28 ;
}
V_40 = F_67 ( V_103 , V_104 , V_170 , V_140 ) ;
F_32 ( V_131 , L_45 , V_40 ) ;
if ( ! V_40 ) {
V_40 = F_86 ( V_104 , V_196 , V_170 , V_178 ) ;
F_32 ( V_131 , L_46 , V_40 ) ;
}
F_13 ( V_104 ) ;
F_13 ( V_103 ) ;
}
return V_40 ;
}
