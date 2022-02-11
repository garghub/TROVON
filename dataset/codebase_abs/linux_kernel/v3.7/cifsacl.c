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
V_2 = & V_23 ;
F_8 ( & V_24 ) ;
F_1 ( V_2 , V_3 , & V_4 , & V_5 ) ;
F_9 ( & V_24 ) ;
V_2 = & V_25 ;
F_8 ( & V_26 ) ;
F_1 ( V_2 , V_3 , & V_4 , & V_5 ) ;
F_9 ( & V_26 ) ;
return V_4 ;
}
static void
F_10 ( struct V_1 * V_2 , unsigned long V_27 ,
struct V_9 * * V_10 , char * V_28 )
{
char * V_29 ;
struct V_6 * V_7 = V_2 -> V_6 ;
struct V_6 * V_30 = NULL ;
struct V_6 * * V_31 = & ( V_2 -> V_6 ) ;
struct V_9 * V_32 ;
while ( V_7 ) {
V_32 = F_4 ( V_7 , struct V_9 , V_11 ) ;
V_30 = V_7 ;
if ( V_27 > V_32 -> V_33 ) {
V_31 = & ( V_7 -> V_34 ) ;
V_7 = V_7 -> V_34 ;
}
if ( V_27 < V_32 -> V_33 ) {
V_31 = & ( V_7 -> V_35 ) ;
V_7 = V_7 -> V_35 ;
}
}
( * V_10 ) -> V_33 = V_27 ;
( * V_10 ) -> time = V_12 - ( V_36 + 1 ) ;
( * V_10 ) -> V_14 = 0 ;
sprintf ( ( * V_10 ) -> V_37 , L_1 , V_28 ) ;
V_29 = ( * V_10 ) -> V_37 + strlen ( ( * V_10 ) -> V_37 ) ;
sprintf ( V_29 , L_2 , V_27 ) ;
F_11 ( V_38 , & ( * V_10 ) -> V_39 ) ;
F_11 ( V_40 , & ( * V_10 ) -> V_39 ) ;
F_12 ( & ( * V_10 ) -> V_11 , V_30 , V_31 ) ;
F_13 ( & ( * V_10 ) -> V_11 , V_2 ) ;
}
static struct V_9 *
F_14 ( struct V_1 * V_2 , unsigned long V_27 )
{
struct V_6 * V_7 = V_2 -> V_6 ;
struct V_9 * V_32 ;
while ( V_7 ) {
V_32 = F_4 ( V_7 , struct V_9 , V_11 ) ;
if ( V_27 > V_32 -> V_33 )
V_7 = V_7 -> V_34 ;
else if ( V_27 < V_32 -> V_33 )
V_7 = V_7 -> V_35 ;
else
return V_32 ;
}
return NULL ;
}
static int
F_15 ( struct V_41 * V_41 , struct V_42 * V_43 )
{
char * V_44 ;
V_44 = F_16 ( V_43 -> V_45 , V_46 ) ;
if ( ! V_44 )
return - V_47 ;
memcpy ( V_44 , V_43 -> V_48 , V_43 -> V_45 ) ;
V_41 -> V_44 . V_48 = V_44 ;
V_41 -> V_45 = V_43 -> V_45 ;
return 0 ;
}
static inline void
F_17 ( struct V_41 * V_41 )
{
F_18 ( V_41 -> V_44 . V_48 ) ;
}
static void
F_19 ( struct V_49 * V_50 , char * V_37 )
{
int V_51 ;
unsigned long V_52 ;
char * V_29 ;
V_29 = V_37 ;
sprintf ( V_29 , L_1 , L_3 ) ;
V_29 = V_37 + strlen ( V_37 ) ;
sprintf ( V_29 , L_4 , V_50 -> V_53 ) ;
V_29 = V_37 + strlen ( V_37 ) ;
for ( V_51 = 0 ; V_51 < 6 ; ++ V_51 ) {
if ( V_50 -> V_54 [ V_51 ] ) {
sprintf ( V_29 , L_4 , V_50 -> V_54 [ V_51 ] ) ;
V_29 = V_37 + strlen ( V_37 ) ;
}
}
for ( V_51 = 0 ; V_51 < V_50 -> V_55 ; ++ V_51 ) {
V_52 = F_20 ( V_50 -> V_56 [ V_51 ] ) ;
sprintf ( V_29 , L_5 , V_52 ) ;
V_29 = V_37 + strlen ( V_37 ) ;
}
}
static void
F_21 ( struct V_49 * V_57 , const struct V_49 * V_58 )
{
memcpy ( V_57 , V_58 , sizeof( * V_57 ) ) ;
V_57 -> V_55 = F_22 ( V_59 , V_58 -> V_55 , V_60 ) ;
}
static void
F_23 ( struct V_1 * V_2 , struct V_49 * V_50 ,
struct V_9 * * V_10 , char * V_28 )
{
int V_61 ;
char * V_29 ;
struct V_6 * V_7 = V_2 -> V_6 ;
struct V_6 * V_30 = NULL ;
struct V_6 * * V_31 = & ( V_2 -> V_6 ) ;
struct V_9 * V_32 ;
while ( V_7 ) {
V_32 = F_4 ( V_7 , struct V_9 , V_11 ) ;
V_30 = V_7 ;
V_61 = F_24 ( V_50 , & ( ( V_32 ) -> V_62 ) ) ;
if ( V_61 > 0 ) {
V_31 = & ( V_7 -> V_34 ) ;
V_7 = V_7 -> V_34 ;
} else if ( V_61 < 0 ) {
V_31 = & ( V_7 -> V_35 ) ;
V_7 = V_7 -> V_35 ;
}
}
F_21 ( & ( * V_10 ) -> V_62 , V_50 ) ;
( * V_10 ) -> time = V_12 - ( V_36 + 1 ) ;
( * V_10 ) -> V_14 = 0 ;
sprintf ( ( * V_10 ) -> V_37 , L_1 , V_28 ) ;
V_29 = ( * V_10 ) -> V_37 + strlen ( ( * V_10 ) -> V_37 ) ;
F_19 ( & ( * V_10 ) -> V_62 , V_29 ) ;
F_11 ( V_38 , & ( * V_10 ) -> V_39 ) ;
F_11 ( V_40 , & ( * V_10 ) -> V_39 ) ;
F_12 ( & ( * V_10 ) -> V_11 , V_30 , V_31 ) ;
F_13 ( & ( * V_10 ) -> V_11 , V_2 ) ;
}
static struct V_9 *
F_25 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
int V_61 ;
struct V_6 * V_7 = V_2 -> V_6 ;
struct V_9 * V_32 ;
while ( V_7 ) {
V_32 = F_4 ( V_7 , struct V_9 , V_11 ) ;
V_61 = F_24 ( V_50 , & ( ( V_32 ) -> V_62 ) ) ;
if ( V_61 > 0 ) {
V_7 = V_7 -> V_34 ;
} else if ( V_61 < 0 ) {
V_7 = V_7 -> V_35 ;
} else
return V_32 ;
}
return NULL ;
}
static int
F_26 ( void * V_63 )
{
F_27 () ;
return F_28 ( V_64 ) ? - V_65 : 0 ;
}
static int
F_29 ( unsigned long V_27 , T_1 V_66 , struct V_49 * V_67 )
{
int V_61 = 0 ;
struct V_41 * V_68 ;
const struct V_69 * V_70 ;
struct V_49 * V_71 ;
struct V_9 * V_10 , * V_72 ;
struct V_1 * V_73 ;
T_2 * V_74 ;
if ( V_66 == V_75 ) {
V_74 = & V_20 ;
V_73 = & V_19 ;
} else if ( V_66 == V_76 ) {
V_74 = & V_22 ;
V_73 = & V_21 ;
} else
return - V_77 ;
F_8 ( V_74 ) ;
V_10 = F_14 ( V_73 , V_27 ) ;
if ( ! V_10 ) {
F_9 ( V_74 ) ;
V_72 = F_30 ( sizeof( struct V_9 ) , V_46 ) ;
if ( ! V_72 )
return - V_47 ;
V_72 -> V_37 = F_16 ( V_78 , V_46 ) ;
if ( ! V_72 -> V_37 ) {
F_18 ( V_72 ) ;
return - V_47 ;
}
F_8 ( V_74 ) ;
V_10 = F_14 ( V_73 , V_27 ) ;
if ( V_10 ) {
++ V_10 -> V_14 ;
F_9 ( V_74 ) ;
F_18 ( V_72 -> V_37 ) ;
F_18 ( V_72 ) ;
} else {
V_10 = V_72 ;
F_10 ( V_73 , V_27 , & V_10 ,
V_66 == V_75 ? L_6 : L_7 ) ;
++ V_10 -> V_14 ;
F_9 ( V_74 ) ;
}
} else {
++ V_10 -> V_14 ;
F_9 ( V_74 ) ;
}
if ( F_31 ( V_40 , & V_10 -> V_39 ) ) {
F_21 ( V_67 , & V_10 -> V_62 ) ;
V_10 -> time = V_12 ;
goto V_79;
}
if ( F_5 ( V_10 -> time + V_36 , V_12 ) ) {
V_61 = - V_77 ;
goto V_79;
}
if ( ! F_32 ( V_38 , & V_10 -> V_39 ) ) {
V_70 = F_33 ( V_80 ) ;
V_68 = F_34 ( & V_81 , V_10 -> V_37 , L_8 ) ;
if ( F_35 ( V_68 ) ) {
V_61 = - V_77 ;
F_36 ( 1 , L_9 , V_82 ) ;
} else if ( V_68 -> V_45 < sizeof( struct V_49 ) ) {
V_61 = - V_83 ;
F_36 ( 1 , L_10
L_11 , V_82 , V_68 -> V_45 ) ;
} else {
V_71 = (struct V_49 * ) V_68 -> V_44 . V_48 ;
F_21 ( & V_10 -> V_62 , V_71 ) ;
F_21 ( V_67 , & V_10 -> V_62 ) ;
F_37 ( V_40 , & V_10 -> V_39 ) ;
F_38 ( V_68 ) ;
F_18 ( V_10 -> V_37 ) ;
}
V_10 -> time = V_12 ;
F_39 ( V_70 ) ;
F_11 ( V_38 , & V_10 -> V_39 ) ;
F_40 ( & V_10 -> V_39 , V_38 ) ;
} else {
V_61 = F_41 ( & V_10 -> V_39 , V_38 ,
F_26 , V_84 ) ;
if ( V_61 ) {
F_36 ( 1 , L_12 ,
V_82 , V_61 ) ;
-- V_10 -> V_14 ;
return V_61 ;
}
if ( F_31 ( V_40 , & V_10 -> V_39 ) )
F_21 ( V_67 , & V_10 -> V_62 ) ;
else
V_61 = - V_77 ;
}
V_79:
-- V_10 -> V_14 ;
return V_61 ;
}
static int
F_42 ( struct V_85 * V_86 , struct V_49 * V_87 ,
struct V_88 * V_89 , T_1 V_66 )
{
int V_61 ;
unsigned long V_27 ;
struct V_41 * V_90 ;
const struct V_69 * V_70 ;
struct V_9 * V_10 , * V_72 ;
struct V_1 * V_73 ;
T_2 * V_74 ;
if ( V_66 == V_75 ) {
V_27 = V_86 -> V_91 ;
V_74 = & V_20 ;
V_73 = & V_19 ;
} else if ( V_66 == V_76 ) {
V_27 = V_86 -> V_92 ;
V_74 = & V_22 ;
V_73 = & V_21 ;
} else
return - V_93 ;
F_8 ( V_74 ) ;
V_10 = F_25 ( V_73 , V_87 ) ;
if ( ! V_10 ) {
F_9 ( V_74 ) ;
V_72 = F_30 ( sizeof( struct V_9 ) , V_46 ) ;
if ( ! V_72 )
return - V_47 ;
V_72 -> V_37 = F_16 ( V_78 , V_46 ) ;
if ( ! V_72 -> V_37 ) {
F_18 ( V_72 ) ;
return - V_47 ;
}
F_8 ( V_74 ) ;
V_10 = F_25 ( V_73 , V_87 ) ;
if ( V_10 ) {
++ V_10 -> V_14 ;
F_9 ( V_74 ) ;
F_18 ( V_72 -> V_37 ) ;
F_18 ( V_72 ) ;
} else {
V_10 = V_72 ;
F_23 ( V_73 , V_87 , & V_10 ,
V_66 == V_75 ? L_13 : L_14 ) ;
++ V_10 -> V_14 ;
F_9 ( V_74 ) ;
}
} else {
++ V_10 -> V_14 ;
F_9 ( V_74 ) ;
}
if ( F_31 ( V_40 , & V_10 -> V_39 ) ) {
V_27 = V_10 -> V_33 ;
V_10 -> time = V_12 ;
goto V_94;
}
if ( F_5 ( V_10 -> time + V_36 , V_12 ) )
goto V_94;
if ( ! F_32 ( V_38 , & V_10 -> V_39 ) ) {
V_70 = F_33 ( V_80 ) ;
V_90 = F_34 ( & V_81 , V_10 -> V_37 , L_8 ) ;
if ( F_35 ( V_90 ) )
F_36 ( 1 , L_15 , V_82 ) ;
else {
V_27 = * ( unsigned long * ) V_90 -> V_44 . V_95 ;
V_10 -> V_33 = V_27 ;
F_37 ( V_40 , & V_10 -> V_39 ) ;
F_38 ( V_90 ) ;
F_18 ( V_10 -> V_37 ) ;
}
F_39 ( V_70 ) ;
V_10 -> time = V_12 ;
F_11 ( V_38 , & V_10 -> V_39 ) ;
F_40 ( & V_10 -> V_39 , V_38 ) ;
} else {
V_61 = F_41 ( & V_10 -> V_39 , V_38 ,
F_26 , V_84 ) ;
if ( V_61 ) {
F_36 ( 1 , L_12 ,
V_82 , V_61 ) ;
-- V_10 -> V_14 ;
return V_61 ;
}
if ( F_31 ( V_40 , & V_10 -> V_39 ) )
V_27 = V_10 -> V_33 ;
}
V_94:
-- V_10 -> V_14 ;
if ( V_66 == V_75 )
V_89 -> V_96 = V_27 ;
else
V_89 -> V_97 = V_27 ;
return 0 ;
}
int
F_43 ( void )
{
struct V_69 * V_69 ;
struct V_41 * V_98 ;
int V_99 ;
F_36 ( 1 , L_16 , V_81 . V_100 ) ;
V_69 = F_44 ( NULL ) ;
if ( ! V_69 )
return - V_47 ;
V_98 = F_45 ( & V_101 , L_17 , 0 , 0 , V_69 ,
( V_102 & ~ V_103 ) |
V_104 | V_105 ,
V_106 ) ;
if ( F_35 ( V_98 ) ) {
V_99 = F_46 ( V_98 ) ;
goto V_107;
}
V_99 = F_47 ( V_98 , NULL , 0 , NULL , NULL ) ;
if ( V_99 < 0 )
goto V_108;
V_99 = F_48 ( & V_81 ) ;
if ( V_99 < 0 )
goto V_108;
F_37 ( V_109 , & V_98 -> V_110 ) ;
V_69 -> V_111 = V_98 ;
V_69 -> V_112 = V_113 ;
V_80 = V_69 ;
F_49 ( & V_20 ) ;
V_19 = V_114 ;
F_49 ( & V_22 ) ;
V_21 = V_114 ;
F_49 ( & V_24 ) ;
V_23 = V_114 ;
F_49 ( & V_26 ) ;
V_25 = V_114 ;
F_50 ( & V_115 ) ;
F_36 ( 1 , L_18 , F_51 ( V_98 ) ) ;
return 0 ;
V_108:
F_38 ( V_98 ) ;
V_107:
F_52 ( V_69 ) ;
return V_99 ;
}
void
F_53 ( void )
{
F_54 ( V_80 -> V_111 ) ;
F_55 ( & V_81 ) ;
F_52 ( V_80 ) ;
F_56 ( & V_115 ) ;
F_36 ( 1 , L_19 , V_81 . V_100 ) ;
}
void
F_57 ( void )
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
V_2 = & V_23 ;
F_8 ( & V_24 ) ;
while ( ( V_7 = F_2 ( V_2 ) ) )
F_6 ( V_7 , V_2 ) ;
F_9 ( & V_24 ) ;
V_2 = & V_25 ;
F_8 ( & V_26 ) ;
while ( ( V_7 = F_2 ( V_2 ) ) )
F_6 ( V_7 , V_2 ) ;
F_9 ( & V_26 ) ;
}
int F_24 ( const struct V_49 * V_116 , const struct V_49 * V_117 )
{
int V_51 ;
int V_55 , V_118 , V_119 ;
if ( ( ! V_116 ) || ( ! V_117 ) )
return 1 ;
if ( V_116 -> V_53 != V_117 -> V_53 ) {
if ( V_116 -> V_53 > V_117 -> V_53 )
return 1 ;
else
return - 1 ;
}
for ( V_51 = 0 ; V_51 < 6 ; ++ V_51 ) {
if ( V_116 -> V_54 [ V_51 ] != V_117 -> V_54 [ V_51 ] ) {
if ( V_116 -> V_54 [ V_51 ] > V_117 -> V_54 [ V_51 ] )
return 1 ;
else
return - 1 ;
}
}
V_118 = V_116 -> V_55 ;
V_119 = V_117 -> V_55 ;
V_55 = V_118 < V_119 ? V_118 : V_119 ;
if ( V_55 ) {
for ( V_51 = 0 ; V_51 < V_55 ; ++ V_51 ) {
if ( V_116 -> V_56 [ V_51 ] != V_117 -> V_56 [ V_51 ] ) {
if ( F_20 ( V_116 -> V_56 [ V_51 ] ) >
F_20 ( V_117 -> V_56 [ V_51 ] ) )
return 1 ;
else
return - 1 ;
}
}
}
return 0 ;
}
static void F_58 ( const struct V_120 * V_121 ,
struct V_120 * V_122 , T_3 V_123 )
{
struct V_49 * V_124 , * V_125 ;
struct V_49 * V_126 , * V_127 ;
V_122 -> V_53 = V_121 -> V_53 ;
V_122 -> type = V_121 -> type ;
V_122 -> V_128 = F_59 ( sizeof( struct V_120 ) ) ;
V_122 -> V_129 = 0 ;
V_122 -> V_130 = F_59 ( V_123 ) ;
V_122 -> V_131 = F_59 ( V_123 + sizeof( struct V_49 ) ) ;
V_124 = (struct V_49 * ) ( ( char * ) V_121 +
F_20 ( V_121 -> V_130 ) ) ;
V_126 = (struct V_49 * ) ( ( char * ) V_122 + V_123 ) ;
F_21 ( V_126 , V_124 ) ;
V_125 = (struct V_49 * ) ( ( char * ) V_121 +
F_20 ( V_121 -> V_131 ) ) ;
V_127 = (struct V_49 * ) ( ( char * ) V_122 + V_123 +
sizeof( struct V_49 ) ) ;
F_21 ( V_127 , V_125 ) ;
return;
}
static void F_60 ( T_4 V_132 , int type , T_5 * V_133 ,
T_5 * V_134 )
{
T_3 V_110 = F_20 ( V_132 ) ;
if ( type == V_135 ) {
if ( V_110 & V_136 )
* V_134 &= ~ V_137 ;
if ( ( V_110 & V_138 ) ||
( ( V_110 & V_139 ) == V_139 ) )
* V_134 &= ~ V_140 ;
if ( ( V_110 & V_141 ) ||
( ( V_110 & V_142 ) == V_142 ) )
* V_134 &= ~ V_143 ;
if ( ( V_110 & V_144 ) ||
( ( V_110 & V_145 ) == V_145 ) )
* V_134 &= ~ V_146 ;
return;
} else if ( type != V_147 ) {
F_61 ( 1 , L_20 , type ) ;
return;
}
if ( V_110 & V_136 ) {
* V_133 |= ( V_137 & ( * V_134 ) ) ;
F_36 ( V_148 , L_21 ) ;
return;
}
if ( ( V_110 & V_138 ) ||
( ( V_110 & V_139 ) == V_139 ) )
* V_133 |= ( V_140 & ( * V_134 ) ) ;
if ( ( V_110 & V_141 ) ||
( ( V_110 & V_142 ) == V_142 ) )
* V_133 |= ( V_143 & ( * V_134 ) ) ;
if ( ( V_110 & V_144 ) ||
( ( V_110 & V_145 ) == V_145 ) )
* V_133 |= ( V_146 & ( * V_134 ) ) ;
F_36 ( V_148 , L_22 , V_110 , * V_133 ) ;
return;
}
static void F_62 ( T_5 V_149 , T_5 V_150 ,
T_3 * V_151 )
{
* V_151 = 0x0 ;
V_149 &= V_150 ;
if ( V_149 & V_143 )
* V_151 |= V_152 ;
if ( V_149 & V_140 )
* V_151 |= V_153 ;
if ( V_149 & V_146 )
* V_151 |= V_154 ;
F_36 ( V_148 , L_23 , V_149 , * V_151 ) ;
return;
}
static T_6 F_63 ( struct V_155 * V_156 ,
const struct V_49 * V_87 , T_7 V_157 , T_5 V_158 )
{
int V_51 ;
T_6 V_159 = 0 ;
T_3 V_160 = 0 ;
V_156 -> type = V_147 ;
V_156 -> V_110 = 0x0 ;
F_62 ( V_157 , V_158 , & V_160 ) ;
if ( ! V_160 )
V_160 = V_161 ;
V_156 -> V_160 = F_59 ( V_160 ) ;
V_156 -> V_62 . V_53 = V_87 -> V_53 ;
V_156 -> V_62 . V_55 = V_87 -> V_55 ;
for ( V_51 = 0 ; V_51 < 6 ; V_51 ++ )
V_156 -> V_62 . V_54 [ V_51 ] = V_87 -> V_54 [ V_51 ] ;
for ( V_51 = 0 ; V_51 < V_87 -> V_55 ; V_51 ++ )
V_156 -> V_62 . V_56 [ V_51 ] = V_87 -> V_56 [ V_51 ] ;
V_159 = 1 + 1 + 2 + 4 + 1 + 1 + 6 + ( V_87 -> V_55 * 4 ) ;
V_156 -> V_159 = F_64 ( V_159 ) ;
return V_159 ;
}
static void F_65 ( struct V_155 * V_162 , char * V_163 )
{
int V_55 ;
if ( F_66 ( V_162 -> V_159 ) < 16 ) {
F_61 ( 1 , L_24 , F_66 ( V_162 -> V_159 ) ) ;
return;
}
if ( V_163 < ( char * ) V_162 + F_66 ( V_162 -> V_159 ) ) {
F_61 ( 1 , L_25 ) ;
return;
}
V_55 = V_162 -> V_62 . V_55 ;
if ( V_55 ) {
int V_51 ;
F_36 ( 1 , L_26 ,
V_162 -> V_62 . V_53 , V_162 -> V_62 . V_55 , V_162 -> type ,
V_162 -> V_110 , F_66 ( V_162 -> V_159 ) ) ;
for ( V_51 = 0 ; V_51 < V_55 ; ++ V_51 ) {
F_36 ( 1 , L_27 , V_51 ,
F_20 ( V_162 -> V_62 . V_56 [ V_51 ] ) ) ;
}
}
return;
}
static void F_67 ( struct V_164 * V_165 , char * V_163 ,
struct V_49 * V_166 , struct V_49 * V_167 ,
struct V_88 * V_89 )
{
int V_51 ;
int V_168 = 0 ;
int V_169 ;
char * V_170 ;
struct V_155 * * V_171 ;
if ( ! V_165 ) {
V_89 -> V_172 |= V_137 ;
return;
}
if ( V_163 < ( char * ) V_165 + F_66 ( V_165 -> V_159 ) ) {
F_61 ( 1 , L_28 ) ;
return;
}
F_36 ( V_148 , L_29 ,
F_66 ( V_165 -> V_53 ) , F_66 ( V_165 -> V_159 ) ,
F_20 ( V_165 -> V_168 ) ) ;
V_89 -> V_172 &= ~ ( V_137 ) ;
V_170 = ( char * ) V_165 ;
V_169 = sizeof( struct V_164 ) ;
V_168 = F_20 ( V_165 -> V_168 ) ;
if ( V_168 > 0 ) {
T_5 V_173 = V_174 ;
T_5 V_175 = V_176 ;
T_5 V_177 = V_174 | V_176 | V_178 ;
if ( V_168 > V_179 / sizeof( struct V_155 * ) )
return;
V_171 = F_16 ( V_168 * sizeof( struct V_155 * ) ,
V_46 ) ;
if ( ! V_171 ) {
F_61 ( 1 , L_30 ) ;
return;
}
for ( V_51 = 0 ; V_51 < V_168 ; ++ V_51 ) {
V_171 [ V_51 ] = (struct V_155 * ) ( V_170 + V_169 ) ;
#ifdef F_68
F_65 ( V_171 [ V_51 ] , V_163 ) ;
#endif
if ( F_24 ( & ( V_171 [ V_51 ] -> V_62 ) , V_166 ) == 0 )
F_60 ( V_171 [ V_51 ] -> V_160 ,
V_171 [ V_51 ] -> type ,
& V_89 -> V_172 ,
& V_173 ) ;
if ( F_24 ( & ( V_171 [ V_51 ] -> V_62 ) , V_167 ) == 0 )
F_60 ( V_171 [ V_51 ] -> V_160 ,
V_171 [ V_51 ] -> type ,
& V_89 -> V_172 ,
& V_175 ) ;
if ( F_24 ( & ( V_171 [ V_51 ] -> V_62 ) , & V_180 ) == 0 )
F_60 ( V_171 [ V_51 ] -> V_160 ,
V_171 [ V_51 ] -> type ,
& V_89 -> V_172 ,
& V_177 ) ;
if ( F_24 ( & ( V_171 [ V_51 ] -> V_62 ) , & V_181 ) == 0 )
F_60 ( V_171 [ V_51 ] -> V_160 ,
V_171 [ V_51 ] -> type ,
& V_89 -> V_172 ,
& V_177 ) ;
V_170 = ( char * ) V_171 [ V_51 ] ;
V_169 = F_66 ( V_171 [ V_51 ] -> V_159 ) ;
}
F_18 ( V_171 ) ;
}
return;
}
static int F_69 ( struct V_164 * V_182 , struct V_49 * V_166 ,
struct V_49 * V_167 , T_7 V_157 )
{
T_8 V_159 = 0 ;
struct V_164 * V_183 ;
V_183 = (struct V_164 * ) ( ( char * ) V_182 + sizeof( struct V_164 ) ) ;
V_159 += F_63 ( (struct V_155 * ) ( ( char * ) V_183 + V_159 ) ,
V_166 , V_157 , V_174 ) ;
V_159 += F_63 ( (struct V_155 * ) ( ( char * ) V_183 + V_159 ) ,
V_167 , V_157 , V_176 ) ;
V_159 += F_63 ( (struct V_155 * ) ( ( char * ) V_183 + V_159 ) ,
& V_180 , V_157 , V_178 ) ;
V_182 -> V_159 = F_64 ( V_159 + sizeof( struct V_164 ) ) ;
V_182 -> V_168 = F_59 ( 3 ) ;
return 0 ;
}
static int F_70 ( struct V_49 * V_87 , char * V_163 )
{
if ( V_163 < ( char * ) V_87 + 8 ) {
F_61 ( 1 , L_31 , V_87 ) ;
return - V_77 ;
}
if ( V_87 -> V_55 ) {
#ifdef F_68
int V_51 ;
F_36 ( 1 , L_32 ,
V_87 -> V_53 , V_87 -> V_55 ) ;
for ( V_51 = 0 ; V_51 < V_87 -> V_55 ; V_51 ++ ) {
F_36 ( 1 , L_33 , V_51 ,
F_20 ( V_87 -> V_56 [ V_51 ] ) ) ;
}
F_36 ( 1 , L_34 ,
F_20 ( V_87 -> V_56 [ V_87 -> V_55 - 1 ] ) ) ;
#endif
}
return 0 ;
}
static int F_71 ( struct V_85 * V_86 ,
struct V_120 * V_121 , int V_184 , struct V_88 * V_89 )
{
int V_61 = 0 ;
struct V_49 * V_124 , * V_125 ;
struct V_164 * V_185 ;
char * V_163 = ( ( char * ) V_121 ) + V_184 ;
T_3 V_128 ;
if ( V_121 == NULL )
return - V_83 ;
V_124 = (struct V_49 * ) ( ( char * ) V_121 +
F_20 ( V_121 -> V_130 ) ) ;
V_125 = (struct V_49 * ) ( ( char * ) V_121 +
F_20 ( V_121 -> V_131 ) ) ;
V_128 = F_20 ( V_121 -> V_128 ) ;
V_185 = (struct V_164 * ) ( ( char * ) V_121 + V_128 ) ;
F_36 ( V_148 , L_35
L_36 ,
V_121 -> V_53 , V_121 -> type , F_20 ( V_121 -> V_130 ) ,
F_20 ( V_121 -> V_131 ) ,
F_20 ( V_121 -> V_129 ) , V_128 ) ;
V_61 = F_70 ( V_124 , V_163 ) ;
if ( V_61 ) {
F_36 ( 1 , L_37 , V_82 , V_61 ) ;
return V_61 ;
}
V_61 = F_42 ( V_86 , V_124 , V_89 , V_75 ) ;
if ( V_61 ) {
F_36 ( 1 , L_38 , V_82 , V_61 ) ;
return V_61 ;
}
V_61 = F_70 ( V_125 , V_163 ) ;
if ( V_61 ) {
F_36 ( 1 , L_39 , V_82 , V_61 ) ;
return V_61 ;
}
V_61 = F_42 ( V_86 , V_125 , V_89 , V_76 ) ;
if ( V_61 ) {
F_36 ( 1 , L_40 , V_82 , V_61 ) ;
return V_61 ;
}
if ( V_128 )
F_67 ( V_185 , V_163 , V_124 ,
V_125 , V_89 ) ;
else
F_36 ( 1 , L_41 ) ;
return V_61 ;
}
static int F_72 ( struct V_120 * V_121 , struct V_120 * V_122 ,
T_3 V_186 , T_7 V_157 , T_9 V_187 , T_10 V_188 , int * V_189 )
{
int V_61 = 0 ;
T_3 V_128 ;
T_3 V_190 ;
T_3 V_123 ;
struct V_49 * V_124 , * V_125 ;
struct V_49 * V_126 , * V_127 ;
struct V_164 * V_185 = NULL ;
struct V_164 * V_191 = NULL ;
if ( V_157 != V_192 ) {
V_124 = (struct V_49 * ) ( ( char * ) V_121 +
F_20 ( V_121 -> V_130 ) ) ;
V_125 = (struct V_49 * ) ( ( char * ) V_121 +
F_20 ( V_121 -> V_131 ) ) ;
V_128 = F_20 ( V_121 -> V_128 ) ;
V_185 = (struct V_164 * ) ( ( char * ) V_121 + V_128 ) ;
V_190 = sizeof( struct V_120 ) ;
V_191 = (struct V_164 * ) ( ( char * ) V_122 + V_190 ) ;
V_191 -> V_53 = V_185 -> V_53 ;
V_191 -> V_159 = 0 ;
V_191 -> V_168 = 0 ;
V_61 = F_69 ( V_191 , V_124 , V_125 ,
V_157 ) ;
V_123 = V_190 + F_66 ( V_191 -> V_159 ) ;
F_58 ( V_121 , V_122 , V_123 ) ;
* V_189 = V_193 ;
} else {
memcpy ( V_122 , V_121 , V_186 ) ;
if ( V_187 != V_194 ) {
V_124 = (struct V_49 * ) ( ( char * ) V_122 +
F_20 ( V_122 -> V_130 ) ) ;
V_126 = F_16 ( sizeof( struct V_49 ) ,
V_46 ) ;
if ( ! V_126 )
return - V_47 ;
V_61 = F_29 ( V_187 , V_75 , V_126 ) ;
if ( V_61 ) {
F_36 ( 1 , L_42 ,
V_82 , V_61 , V_187 ) ;
F_18 ( V_126 ) ;
return V_61 ;
}
F_21 ( V_124 , V_126 ) ;
F_18 ( V_126 ) ;
* V_189 = V_195 ;
}
if ( V_188 != V_194 ) {
V_125 = (struct V_49 * ) ( ( char * ) V_122 +
F_20 ( V_122 -> V_131 ) ) ;
V_127 = F_16 ( sizeof( struct V_49 ) ,
V_46 ) ;
if ( ! V_127 )
return - V_47 ;
V_61 = F_29 ( V_188 , V_76 , V_127 ) ;
if ( V_61 ) {
F_36 ( 1 , L_43 ,
V_82 , V_61 , V_188 ) ;
F_18 ( V_127 ) ;
return V_61 ;
}
F_21 ( V_125 , V_127 ) ;
F_18 ( V_127 ) ;
* V_189 = V_196 ;
}
}
return V_61 ;
}
static struct V_120 * F_73 ( struct V_85 * V_86 ,
T_6 V_197 , T_11 * V_198 )
{
struct V_120 * V_121 = NULL ;
unsigned int V_199 ;
int V_61 ;
struct V_200 * V_201 = F_74 ( V_86 ) ;
if ( F_35 ( V_201 ) )
return F_75 ( V_201 ) ;
V_199 = F_76 () ;
V_61 = F_77 ( V_199 , F_78 ( V_201 ) , V_197 , & V_121 , V_198 ) ;
F_79 ( V_199 ) ;
F_80 ( V_201 ) ;
F_36 ( 1 , L_44 , V_82 , V_61 , * V_198 ) ;
if ( V_61 )
return F_81 ( V_61 ) ;
return V_121 ;
}
static struct V_120 * F_82 ( struct V_85 * V_86 ,
const char * V_202 , T_11 * V_198 )
{
struct V_120 * V_121 = NULL ;
int V_203 = 0 ;
unsigned int V_199 ;
int V_61 , V_204 = 0 ;
T_6 V_197 ;
struct V_205 * V_206 ;
struct V_200 * V_201 = F_74 ( V_86 ) ;
if ( F_35 ( V_201 ) )
return F_75 ( V_201 ) ;
V_206 = F_78 ( V_201 ) ;
V_199 = F_76 () ;
if ( F_83 ( V_86 ) )
V_204 |= V_207 ;
V_61 = F_84 ( V_199 , V_206 , V_202 , V_208 , V_209 ,
V_204 , & V_197 , & V_203 , NULL , V_86 -> V_210 ,
V_86 -> V_211 & V_212 ) ;
if ( ! V_61 ) {
V_61 = F_77 ( V_199 , V_206 , V_197 , & V_121 , V_198 ) ;
F_85 ( V_199 , V_206 , V_197 ) ;
}
F_80 ( V_201 ) ;
F_79 ( V_199 ) ;
F_36 ( 1 , L_44 , V_82 , V_61 , * V_198 ) ;
if ( V_61 )
return F_81 ( V_61 ) ;
return V_121 ;
}
struct V_120 * F_86 ( struct V_85 * V_86 ,
struct V_213 * V_213 , const char * V_202 ,
T_11 * V_198 )
{
struct V_120 * V_121 = NULL ;
struct V_214 * V_215 = NULL ;
if ( V_213 )
V_215 = F_87 ( F_88 ( V_213 ) , true ) ;
if ( ! V_215 )
return F_82 ( V_86 , V_202 , V_198 ) ;
V_121 = F_73 ( V_86 , V_215 -> V_197 . V_216 , V_198 ) ;
F_89 ( V_215 ) ;
return V_121 ;
}
int F_90 ( struct V_120 * V_122 , T_3 V_217 ,
struct V_213 * V_213 , const char * V_202 , int V_189 )
{
int V_203 = 0 ;
unsigned int V_199 ;
int V_61 , V_218 , V_204 = 0 ;
T_6 V_197 ;
struct V_205 * V_206 ;
struct V_85 * V_86 = F_91 ( V_213 -> V_219 ) ;
struct V_200 * V_201 = F_74 ( V_86 ) ;
if ( F_35 ( V_201 ) )
return F_46 ( V_201 ) ;
V_206 = F_78 ( V_201 ) ;
V_199 = F_76 () ;
if ( F_83 ( V_86 ) )
V_204 |= V_207 ;
if ( V_189 == V_195 || V_189 == V_196 )
V_218 = V_220 ;
else
V_218 = V_221 ;
V_61 = F_84 ( V_199 , V_206 , V_202 , V_208 , V_218 ,
V_204 , & V_197 , & V_203 , NULL , V_86 -> V_210 ,
V_86 -> V_211 & V_212 ) ;
if ( V_61 ) {
F_61 ( 1 , L_45 ) ;
goto V_222;
}
V_61 = F_92 ( V_199 , V_206 , V_197 , V_122 , V_217 , V_189 ) ;
F_36 ( V_148 , L_46 , V_61 ) ;
F_85 ( V_199 , V_206 , V_197 ) ;
V_222:
F_79 ( V_199 ) ;
F_80 ( V_201 ) ;
return V_61 ;
}
int
F_93 ( struct V_85 * V_86 , struct V_88 * V_89 ,
struct V_213 * V_213 , const char * V_202 , const T_6 * V_223 )
{
struct V_120 * V_121 = NULL ;
T_11 V_217 = 0 ;
int V_61 = 0 ;
F_36 ( V_148 , L_47 , V_202 ) ;
if ( V_223 )
V_121 = F_73 ( V_86 , * V_223 , & V_217 ) ;
else
V_121 = F_86 ( V_86 , V_213 , V_202 , & V_217 ) ;
if ( F_35 ( V_121 ) ) {
V_61 = F_46 ( V_121 ) ;
F_61 ( 1 , L_48 , V_82 , V_61 ) ;
} else {
V_61 = F_71 ( V_86 , V_121 , V_217 , V_89 ) ;
F_18 ( V_121 ) ;
if ( V_61 )
F_61 ( 1 , L_49 , V_61 ) ;
}
return V_61 ;
}
int
F_94 ( struct V_213 * V_213 , const char * V_202 , T_7 V_157 ,
T_9 V_187 , T_10 V_188 )
{
int V_61 = 0 ;
int V_189 = V_193 ;
T_3 V_186 = 0 ;
struct V_120 * V_121 = NULL ;
struct V_120 * V_122 = NULL ;
F_36 ( V_148 , L_50 , V_202 ) ;
V_121 = F_86 ( F_91 ( V_213 -> V_219 ) , V_213 , V_202 , & V_186 ) ;
if ( F_35 ( V_121 ) ) {
V_61 = F_46 ( V_121 ) ;
F_61 ( 1 , L_48 , V_82 , V_61 ) ;
} else {
V_186 = V_186 < V_224 ?
V_224 : V_186 ;
V_122 = F_16 ( V_186 , V_46 ) ;
if ( ! V_122 ) {
F_61 ( 1 , L_51 ) ;
F_18 ( V_121 ) ;
return - V_47 ;
}
V_61 = F_72 ( V_121 , V_122 , V_186 , V_157 , V_187 , V_188 ,
& V_189 ) ;
F_36 ( V_148 , L_52 , V_61 ) ;
if ( ! V_61 ) {
V_61 = F_90 ( V_122 , V_186 , V_213 ,
V_202 , V_189 ) ;
F_36 ( V_148 , L_53 , V_61 ) ;
}
F_18 ( V_122 ) ;
F_18 ( V_121 ) ;
}
return V_61 ;
}
