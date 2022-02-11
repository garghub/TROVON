static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
F_2 ( & V_2 -> V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
F_4 ( & V_2 -> V_4 , V_5 ) ;
V_2 -> V_3 ++ ;
F_5 ( & V_2 -> V_4 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
unsigned long V_5 ;
int V_6 ;
F_4 ( & V_2 -> V_4 , V_5 ) ;
V_6 = V_2 -> V_3 ;
F_5 ( & V_2 -> V_4 , V_5 ) ;
return V_6 ;
}
static int F_7 ( void )
{
unsigned long V_5 ;
int V_7 ;
F_4 ( & V_8 , V_5 ) ;
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
if ( V_10 [ V_7 ] == 0 ) {
V_10 [ V_7 ] = 1 ;
F_5 ( & V_8 , V_5 ) ;
return V_7 ;
}
}
F_5 ( & V_8 , V_5 ) ;
return - 1 ;
}
static void F_8 ( int V_11 )
{
unsigned long V_5 ;
if ( V_11 < 0 || V_11 >= V_9 ) {
F_9 (KERN_ERR DRV_NAME L_1 , id) ;
return;
}
F_4 ( & V_8 , V_5 ) ;
if ( V_10 [ V_11 ] == 0 ) {
F_5 ( & V_8 , V_5 ) ;
F_9 (KERN_ERR DRV_NAME L_2 , id) ;
return;
}
V_10 [ V_11 ] = 0 ;
F_5 ( & V_8 , V_5 ) ;
}
static T_1 * F_10 ( void )
{
unsigned long V_5 ;
T_1 * V_6 ;
F_4 ( & V_8 , V_5 ) ;
V_6 = & V_12 [ V_13 ] ;
V_13 = ( V_13 + 1 ) % V_14 ;
F_5 ( & V_8 , V_5 ) ;
return V_6 ;
}
static void F_11 ( struct V_15 * V_16 )
{
unsigned long V_5 ;
F_4 ( & V_8 , V_5 ) ;
-- V_16 -> V_17 ;
if ( V_16 -> V_17 == 0 && F_12 ( & V_16 -> V_18 ) ) {
F_5 ( & V_8 , V_5 ) ;
F_13 ( V_16 ) ;
} else {
F_5 ( & V_8 , V_5 ) ;
}
}
static void F_13 ( struct V_15 * V_16 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
while ( ! F_14 ( & V_16 -> V_25 ) ) {
V_20 = V_16 -> V_25 . V_26 ;
V_22 = F_15 ( V_20 , struct V_21 , V_27 ) ;
F_16 ( V_20 ) ;
if ( ( V_24 = V_22 -> V_28 -> V_29 ) != NULL )
F_17 ( V_24 ) ;
F_18 ( V_22 -> V_28 ) ;
V_22 -> V_28 = NULL ;
F_8 ( V_22 -> V_11 ) ;
F_19 ( V_22 ) ;
}
F_20 ( V_16 -> V_30 , NULL ) ;
F_21 ( V_16 -> V_30 ) ;
F_22 ( V_16 -> V_31 ) ;
F_19 ( V_16 ) ;
}
static struct V_32 * F_23 ( struct V_21 * V_22 )
{
struct V_32 * V_6 ;
if ( V_22 -> V_33 [ 0 ] )
return NULL ;
V_6 = & V_22 -> V_34 [ 0 ] ;
V_22 -> V_33 [ 0 ] = 1 ;
return V_6 ;
}
static void F_24 ( struct V_21 * V_22 , struct V_32 * V_35 )
{
if ( V_35 != & V_22 -> V_34 [ 0 ] ) {
F_9 ( V_36 L_3 ,
V_22 -> V_37 , V_35 ) ;
return;
}
if ( ! V_22 -> V_33 [ 0 ] ) {
F_9 ( V_36 L_4 , V_22 -> V_37 ) ;
return;
}
V_22 -> V_33 [ 0 ] = 0 ;
}
static void F_25 ( struct V_15 * V_16 , struct V_32 * V_35 )
{
struct V_38 * V_39 = & V_16 -> V_40 ;
if ( V_39 -> V_41 ++ == 0 ) {
V_39 -> V_42 = V_35 ;
V_39 -> V_43 = V_35 ;
} else {
V_39 -> V_43 -> V_26 = V_35 ;
V_39 -> V_43 = V_35 ;
}
if ( V_39 -> V_41 > V_39 -> V_44 )
V_39 -> V_44 = V_39 -> V_41 ;
}
static void F_26 ( struct V_15 * V_16 , struct V_32 * V_35 )
{
struct V_38 * V_39 = & V_16 -> V_40 ;
if ( V_39 -> V_41 ++ == 0 ) {
V_39 -> V_42 = V_35 ;
V_39 -> V_43 = V_35 ;
} else {
V_35 -> V_26 = V_39 -> V_42 ;
V_39 -> V_42 = V_35 ;
}
if ( V_39 -> V_41 > V_39 -> V_44 )
V_39 -> V_44 = V_39 -> V_41 ;
}
static struct V_32 * F_27 ( struct V_15 * V_16 )
{
struct V_38 * V_39 = & V_16 -> V_40 ;
struct V_32 * V_35 ;
if ( V_39 -> V_41 == 0 )
return NULL ;
if ( -- V_39 -> V_41 == 0 )
V_39 -> V_43 = NULL ;
V_35 = V_39 -> V_42 ;
V_39 -> V_42 = V_35 -> V_26 ;
V_35 -> V_26 = NULL ;
return V_35 ;
}
static void F_28 ( struct V_23 * V_24 )
{
struct V_21 * V_22 = V_24 -> V_45 ;
struct V_46 * V_47 ;
while ( ( V_47 = F_29 ( V_24 ) ) != NULL ) {
if ( F_30 ( V_22 , V_47 ) != 0 ) {
F_31 ( V_24 ) ;
break;
}
}
}
static int F_30 ( struct V_21 * V_22 , struct V_46 * V_47 )
{
struct V_15 * V_16 = V_22 -> V_48 ;
struct V_32 * V_35 ;
struct V_49 * V_50 ;
int V_51 ;
if ( F_12 ( & V_16 -> V_18 ) ) {
F_32 ( V_47 ) ;
F_33 ( V_47 , V_52 << 16 ) ;
return 0 ;
}
if ( V_22 -> V_53 && V_47 -> V_54 != V_55 ) {
F_32 ( V_47 ) ;
F_33 ( V_47 , V_56 ) ;
return 0 ;
}
if ( V_22 -> V_50 . V_47 != NULL )
return - 1 ;
if ( ( V_35 = F_23 ( V_22 ) ) == NULL )
return - 1 ;
memset ( V_35 , 0 , sizeof( struct V_32 ) ) ;
F_32 ( V_47 ) ;
V_50 = & V_22 -> V_50 ;
memset ( V_50 , 0 , sizeof( struct V_49 ) ) ;
V_50 -> V_47 = V_47 ;
F_34 ( & V_50 -> V_57 [ 0 ] , V_58 ) ;
V_51 = F_35 ( V_22 -> V_28 -> V_29 , V_47 , & V_50 -> V_57 [ 0 ] ) ;
if ( V_51 < 0 ) {
F_9 ( V_59 L_5 ,
V_22 -> V_37 , V_51 ) ;
goto V_60;
}
if ( V_51 > V_58 ) {
F_9 ( V_36 L_6 ,
V_22 -> V_37 , V_51 ) ;
goto V_60;
}
V_50 -> V_61 = V_51 ;
if ( V_47 -> V_54 == V_55 ) {
F_36 ( V_16 , V_22 , V_35 , V_50 ) ;
} else {
F_37 ( V_16 , V_22 , V_35 , V_50 ) ;
}
V_35 -> V_62 = V_63 ;
V_35 -> V_22 = V_22 ;
V_35 -> V_3 = V_64 ;
V_35 -> V_65 = V_50 ;
V_35 -> V_66 = V_16 -> V_67 ++ ;
if ( F_38 ( V_16 , V_35 ) != 0 )
goto V_60;
return 0 ;
V_60:
F_24 ( V_22 , V_35 ) ;
F_33 ( V_47 , V_68 << 16 ) ;
return 0 ;
}
static void F_37 ( struct V_15 * V_16 , struct V_21 * V_22 ,
struct V_32 * V_35 , struct V_49 * V_50 )
{
struct V_46 * V_47 = V_50 -> V_47 ;
unsigned int V_69 , V_70 ;
if ( F_39 ( V_47 ) == V_71 )
V_35 -> V_72 = V_73 ;
else
V_35 -> V_72 = V_74 ;
V_35 -> V_61 = V_50 -> V_61 ;
memcpy ( V_35 -> V_57 , V_50 -> V_57 , sizeof( struct V_75 ) * V_35 -> V_61 ) ;
V_69 = F_40 ( V_47 ) >> V_22 -> V_76 . V_77 ;
V_70 = F_41 ( V_47 ) >> V_22 -> V_76 . V_77 ;
V_35 -> V_78 [ 0 ] = ( V_35 -> V_72 == V_74 ) ? V_79 : V_80 ;
V_35 -> V_78 [ 2 ] = V_69 >> 24 ;
V_35 -> V_78 [ 3 ] = V_69 >> 16 ;
V_35 -> V_78 [ 4 ] = V_69 >> 8 ;
V_35 -> V_78 [ 5 ] = V_69 ;
V_35 -> V_78 [ 7 ] = V_70 >> 8 ;
V_35 -> V_78 [ 8 ] = V_70 ;
V_35 -> V_81 = 10 ;
V_35 -> V_82 = F_42 ( V_47 ) ;
}
static void F_36 ( struct V_15 * V_16 , struct V_21 * V_22 ,
struct V_32 * V_35 , struct V_49 * V_50 )
{
struct V_46 * V_47 = V_50 -> V_47 ;
if ( F_42 ( V_47 ) == 0 ) {
V_35 -> V_72 = V_83 ;
} else {
if ( F_39 ( V_47 ) == V_71 )
V_35 -> V_72 = V_73 ;
else
V_35 -> V_72 = V_74 ;
}
V_35 -> V_61 = V_50 -> V_61 ;
memcpy ( V_35 -> V_57 , V_50 -> V_57 , sizeof( struct V_75 ) * V_35 -> V_61 ) ;
memcpy ( & V_35 -> V_78 , V_47 -> V_35 , V_47 -> V_84 ) ;
V_35 -> V_81 = V_47 -> V_84 ;
V_35 -> V_82 = F_42 ( V_47 ) ;
V_35 -> V_85 = V_47 -> V_86 ;
}
static void V_64 ( struct V_15 * V_16 , struct V_32 * V_35 )
{
struct V_21 * V_22 = V_35 -> V_22 ;
struct V_49 * V_50 = V_35 -> V_65 ;
struct V_46 * V_47 ;
unsigned int V_87 ;
V_47 = V_50 -> V_47 ;
if ( V_35 -> error == 0 ) {
if ( V_47 -> V_54 == V_55 ) {
if ( V_35 -> V_88 >= V_47 -> V_89 )
V_47 -> V_89 = 0 ;
else
V_47 -> V_89 -= V_35 -> V_88 ;
V_87 = 0 ;
} else {
if ( V_35 -> V_88 != V_35 -> V_82 ) {
V_87 = V_56 ;
} else {
V_87 = 0 ;
}
}
} else {
if ( V_47 -> V_54 == V_55 ) {
memcpy ( V_47 -> V_90 , V_16 -> V_91 , V_92 ) ;
V_47 -> V_93 = V_92 ;
if ( V_16 -> V_91 [ 0 ] != 0 )
V_87 = V_56 ;
else
V_87 = V_68 << 16 ;
} else {
if ( V_35 -> error == - V_94 &&
( V_35 -> V_95 == 0 ||
V_35 -> V_95 == V_96 ||
V_35 -> V_95 == V_97 ) ) {
if ( F_43 ( V_16 , V_22 , V_50 , V_35 ) == 0 )
return;
}
V_87 = V_56 ;
}
}
V_50 -> V_47 = NULL ;
F_24 ( V_22 , V_35 ) ;
F_33 ( V_47 , V_87 ) ;
F_44 ( V_22 -> V_28 -> V_29 ) ;
}
static void F_33 ( struct V_46 * V_47 , unsigned int V_87 )
{
int error ;
if ( V_87 == 0 ) {
error = 0 ;
} else {
error = - V_94 ;
V_47 -> V_98 = V_87 ;
}
F_45 ( V_47 , error ) ;
}
static int F_43 ( struct V_15 * V_16 , struct V_21 * V_22 ,
struct V_49 * V_50 , struct V_32 * V_35 )
{
if ( F_12 ( & V_16 -> V_18 ) )
return - V_99 ;
F_46 ( V_16 , V_50 -> V_100 ) ;
if ( V_50 -> V_100 >= 3 )
return - V_94 ;
V_50 -> V_100 ++ ;
F_9 ( V_101 L_7
L_8 ,
V_16 -> V_37 , F_47 ( V_35 -> V_72 ) , V_35 -> V_82 , V_35 -> V_88 ,
V_35 -> V_95 , V_35 -> V_102 , V_35 -> V_103 , V_50 -> V_100 ) ;
memset ( V_35 , 0 , sizeof( struct V_32 ) ) ;
F_37 ( V_16 , V_22 , V_35 , V_50 ) ;
V_35 -> V_62 = V_63 ;
V_35 -> V_22 = V_22 ;
V_35 -> V_3 = V_64 ;
V_35 -> V_65 = V_50 ;
V_35 -> V_66 = V_16 -> V_67 ++ ;
#if 0
return ub_submit_scsi(sc, cmd);
#else
F_25 ( V_16 , V_35 ) ;
return 0 ;
#endif
}
static int F_38 ( struct V_15 * V_16 , struct V_32 * V_35 )
{
if ( V_35 -> V_62 != V_63 ||
( V_35 -> V_72 != V_83 && V_35 -> V_82 == 0 ) ) {
return - V_104 ;
}
F_25 ( V_16 , V_35 ) ;
F_48 ( & V_16 -> V_105 ) ;
return 0 ;
}
static int F_49 ( struct V_15 * V_16 , struct V_32 * V_35 )
{
struct V_106 * V_107 ;
int V_108 ;
V_107 = & V_16 -> V_109 ;
memset ( & V_16 -> V_91 , 0 , V_92 ) ;
V_107 -> V_110 = F_50 ( V_111 ) ;
V_107 -> V_112 = V_35 -> V_66 ;
V_107 -> V_113 = F_50 ( V_35 -> V_82 ) ;
V_107 -> V_114 = ( V_35 -> V_72 == V_74 ) ? 0x80 : 0 ;
V_107 -> V_115 = ( V_35 -> V_22 != NULL ) ? V_35 -> V_22 -> V_116 : 0 ;
V_107 -> V_117 = V_35 -> V_81 ;
memcpy ( V_107 -> V_118 , V_35 -> V_78 , V_119 ) ;
F_51 ( V_16 -> V_120 ) ;
V_16 -> V_121 = V_16 -> V_122 ;
F_52 ( & V_16 -> V_123 , V_16 -> V_31 , V_16 -> V_122 ,
V_107 , V_124 , V_125 , V_16 ) ;
if ( ( V_108 = F_53 ( & V_16 -> V_123 , V_126 ) ) != 0 ) {
F_3 ( & V_16 -> V_120 ) ;
return V_108 ;
}
V_16 -> V_127 . V_128 = V_129 + V_130 ;
F_54 ( & V_16 -> V_127 ) ;
V_35 -> V_62 = V_131 ;
return 0 ;
}
static void F_55 ( unsigned long V_132 )
{
struct V_15 * V_16 = (struct V_15 * ) V_132 ;
unsigned long V_5 ;
F_4 ( V_16 -> V_4 , V_5 ) ;
if ( ! F_6 ( & V_16 -> V_120 ) )
F_56 ( & V_16 -> V_123 ) ;
F_5 ( V_16 -> V_4 , V_5 ) ;
}
static void V_125 ( struct V_133 * V_133 )
{
struct V_15 * V_16 = V_133 -> V_134 ;
F_3 ( & V_16 -> V_120 ) ;
F_48 ( & V_16 -> V_105 ) ;
}
static void F_57 ( unsigned long V_135 )
{
struct V_15 * V_16 = (struct V_15 * ) V_135 ;
unsigned long V_5 ;
F_4 ( V_16 -> V_4 , V_5 ) ;
F_58 ( V_16 ) ;
F_5 ( V_16 -> V_4 , V_5 ) ;
}
static void F_58 ( struct V_15 * V_16 )
{
struct V_32 * V_35 ;
int V_108 ;
while ( ! V_16 -> V_136 && ( V_35 = F_59 ( V_16 ) ) != NULL ) {
if ( V_35 -> V_62 == V_137 ) {
F_27 ( V_16 ) ;
(* V_35 -> V_3 )( V_16 , V_35 ) ;
} else if ( V_35 -> V_62 == V_63 ) {
if ( ( V_108 = F_49 ( V_16 , V_35 ) ) == 0 )
break;
V_35 -> error = V_108 ;
V_35 -> V_62 = V_137 ;
} else {
if ( ! F_6 ( & V_16 -> V_120 ) )
break;
F_60 ( & V_16 -> V_127 ) ;
F_61 ( V_16 , V_35 ) ;
}
}
}
static void F_61 ( struct V_15 * V_16 , struct V_32 * V_35 )
{
struct V_133 * V_133 = & V_16 -> V_123 ;
struct V_138 * V_139 ;
int V_140 ;
int V_82 ;
int V_108 ;
if ( F_12 ( & V_16 -> V_18 ) ) {
F_62 ( V_16 , V_35 , - V_141 ) ;
return;
}
V_140 = F_63 ( V_16 -> V_121 ) ;
if ( F_64 ( V_16 -> V_121 ) )
V_140 |= V_142 ;
if ( V_35 -> V_62 == V_143 ) {
if ( V_133 -> V_144 == - V_145 ) {
F_9 ( V_146 L_9 ,
V_16 -> V_37 ) ;
goto V_147;
}
F_65 ( V_16 -> V_31 , V_140 ) ;
F_66 ( V_16 , V_35 ) ;
} else if ( V_35 -> V_62 == V_148 ) {
if ( V_133 -> V_144 == - V_145 ) {
F_9 ( V_146 L_9 ,
V_16 -> V_37 ) ;
goto V_147;
}
F_65 ( V_16 -> V_31 , V_140 ) ;
F_67 ( V_16 , V_35 ) ;
} else if ( V_35 -> V_62 == V_149 ) {
if ( V_133 -> V_144 == - V_145 ) {
F_9 ( V_146 L_9 ,
V_16 -> V_37 ) ;
goto V_147;
}
F_65 ( V_16 -> V_31 , V_140 ) ;
F_68 ( V_16 , V_35 ) ;
} else if ( V_35 -> V_62 == V_131 ) {
switch ( V_133 -> V_144 ) {
case 0 :
break;
case - V_150 :
goto V_147;
case - V_145 :
V_108 = F_69 ( V_16 , V_35 , V_16 -> V_121 ) ;
if ( V_108 != 0 ) {
F_9 ( V_146 L_10
L_11 ,
V_16 -> V_37 , V_108 ) ;
F_62 ( V_16 , V_35 , V_108 ) ;
return;
}
V_35 -> V_62 = V_143 ;
return;
case - V_151 :
case - V_152 :
F_62 ( V_16 , V_35 , - V_141 ) ;
return;
default:
goto V_147;
}
if ( V_133 -> V_153 != V_124 ) {
goto V_147;
}
if ( V_35 -> V_72 == V_83 || V_35 -> V_61 < 1 ) {
F_67 ( V_16 , V_35 ) ;
return;
}
F_70 ( V_16 , V_35 ) ;
} else if ( V_35 -> V_62 == V_154 ) {
if ( V_133 -> V_144 == - V_145 ) {
V_108 = F_69 ( V_16 , V_35 , V_16 -> V_121 ) ;
if ( V_108 != 0 ) {
F_9 ( V_146 L_10
L_11 ,
V_16 -> V_37 , V_108 ) ;
F_62 ( V_16 , V_35 , V_108 ) ;
return;
}
V_35 -> V_62 = V_148 ;
return;
}
if ( V_133 -> V_144 == - V_150 ) {
V_35 -> error = - V_150 ;
F_67 ( V_16 , V_35 ) ;
return;
}
if ( V_35 -> V_72 == V_73 ) {
V_82 = V_133 -> V_153 ;
if ( V_133 -> V_144 != 0 ||
V_82 != V_35 -> V_57 [ V_35 -> V_155 ] . V_156 ) {
V_35 -> V_88 += V_82 ;
V_35 -> error = - V_94 ;
F_67 ( V_16 , V_35 ) ;
return;
}
} else {
if ( V_133 -> V_144 != 0 )
V_35 -> error = - V_94 ;
V_82 = V_133 -> V_153 ;
if ( V_133 -> V_144 != 0 ||
V_82 != V_35 -> V_57 [ V_35 -> V_155 ] . V_156 ) {
if ( ( V_82 & 0x1FF ) == V_157 )
goto V_147;
}
}
V_35 -> V_88 += V_133 -> V_153 ;
if ( ++ V_35 -> V_155 < V_35 -> V_61 ) {
F_70 ( V_16 , V_35 ) ;
return;
}
F_67 ( V_16 , V_35 ) ;
} else if ( V_35 -> V_62 == V_158 ) {
if ( V_133 -> V_144 == - V_145 ) {
V_108 = F_69 ( V_16 , V_35 , V_16 -> V_121 ) ;
if ( V_108 != 0 ) {
F_9 ( V_146 L_10
L_11 ,
V_16 -> V_37 , V_108 ) ;
F_62 ( V_16 , V_35 , V_108 ) ;
return;
}
V_35 -> error = - V_94 ;
V_35 -> V_62 = V_149 ;
return;
}
if ( V_133 -> V_144 != 0 )
goto V_147;
if ( V_133 -> V_153 == 0 ) {
F_68 ( V_16 , V_35 ) ;
return;
}
V_139 = & V_16 -> V_159 ;
if ( V_16 -> V_160 == F_50 ( 0 ) ) {
V_16 -> V_160 = V_139 -> V_110 ;
if ( V_16 -> V_160 == F_50 ( 0 ) ) {
F_68 ( V_16 , V_35 ) ;
return;
}
} else {
if ( V_139 -> V_110 != V_16 -> V_160 ) {
F_68 ( V_16 , V_35 ) ;
return;
}
}
if ( V_139 -> V_112 != V_35 -> V_66 ) {
F_68 ( V_16 , V_35 ) ;
return;
}
if ( ! V_16 -> V_161 ) {
V_82 = F_71 ( V_139 -> V_162 ) ;
if ( V_82 != V_35 -> V_82 - V_35 -> V_88 ) {
if ( V_35 -> V_82 == V_35 -> V_88 ) {
F_9 ( V_146 L_10
L_12 ,
V_16 -> V_37 , V_82 , V_35 -> V_82 ) ;
V_16 -> V_161 = 1 ;
}
}
}
switch ( V_139 -> V_163 ) {
case V_164 :
break;
case V_165 :
F_66 ( V_16 , V_35 ) ;
return;
case V_166 :
goto V_147;
default:
F_9 ( V_59 L_13 ,
V_16 -> V_37 , V_139 -> V_163 ) ;
F_62 ( V_16 , V_35 , - V_104 ) ;
return;
}
if ( V_35 -> error != 0 ) {
F_66 ( V_16 , V_35 ) ;
return;
}
V_35 -> V_62 = V_137 ;
F_27 ( V_16 ) ;
(* V_35 -> V_3 )( V_16 , V_35 ) ;
} else if ( V_35 -> V_62 == V_167 ) {
F_62 ( V_16 , V_35 , - V_94 ) ;
} else {
F_9 ( V_36 L_14 ,
V_16 -> V_37 , V_35 -> V_62 ) ;
F_62 ( V_16 , V_35 , - V_104 ) ;
return;
}
return;
V_147:
F_62 ( V_16 , V_35 , - V_94 ) ;
}
static void F_70 ( struct V_15 * V_16 , struct V_32 * V_35 )
{
struct V_75 * V_168 = & V_35 -> V_57 [ V_35 -> V_155 ] ;
int V_169 ;
int V_108 ;
F_51 ( V_16 -> V_120 ) ;
if ( V_35 -> V_72 == V_74 )
V_169 = V_16 -> V_170 ;
else
V_169 = V_16 -> V_122 ;
V_16 -> V_121 = V_169 ;
F_52 ( & V_16 -> V_123 , V_16 -> V_31 , V_169 , F_72 ( V_168 ) ,
V_168 -> V_156 , V_125 , V_16 ) ;
if ( ( V_108 = F_53 ( & V_16 -> V_123 , V_126 ) ) != 0 ) {
F_3 ( & V_16 -> V_120 ) ;
F_62 ( V_16 , V_35 , V_108 ) ;
return;
}
if ( V_35 -> V_85 )
V_16 -> V_127 . V_128 = V_129 + V_35 -> V_85 ;
else
V_16 -> V_127 . V_128 = V_129 + V_171 ;
F_54 ( & V_16 -> V_127 ) ;
V_35 -> V_62 = V_154 ;
}
static void F_62 ( struct V_15 * V_16 , struct V_32 * V_35 , int V_108 )
{
V_35 -> error = V_108 ;
V_35 -> V_62 = V_137 ;
F_27 ( V_16 ) ;
(* V_35 -> V_3 )( V_16 , V_35 ) ;
}
static int F_73 ( struct V_15 * V_16 , struct V_32 * V_35 )
{
int V_108 ;
F_51 ( V_16 -> V_120 ) ;
V_16 -> V_121 = V_16 -> V_170 ;
F_52 ( & V_16 -> V_123 , V_16 -> V_31 , V_16 -> V_170 ,
& V_16 -> V_159 , V_157 , V_125 , V_16 ) ;
if ( ( V_108 = F_53 ( & V_16 -> V_123 , V_126 ) ) != 0 ) {
F_3 ( & V_16 -> V_120 ) ;
F_62 ( V_16 , V_35 , V_108 ) ;
return - 1 ;
}
if ( V_35 -> V_85 )
V_16 -> V_127 . V_128 = V_129 + V_35 -> V_85 ;
else
V_16 -> V_127 . V_128 = V_129 + V_172 ;
F_54 ( & V_16 -> V_127 ) ;
return 0 ;
}
static void F_67 ( struct V_15 * V_16 , struct V_32 * V_35 )
{
if ( F_73 ( V_16 , V_35 ) != 0 )
return;
V_35 -> V_173 = 0 ;
V_35 -> V_62 = V_158 ;
}
static void F_68 ( struct V_15 * V_16 , struct V_32 * V_35 )
{
if ( ++ V_35 -> V_173 >= 4 ) {
F_66 ( V_16 , V_35 ) ;
return;
}
if ( F_73 ( V_16 , V_35 ) != 0 )
return;
V_35 -> V_62 = V_158 ;
}
static void F_66 ( struct V_15 * V_16 , struct V_32 * V_35 )
{
struct V_32 * V_174 ;
struct V_75 * V_168 ;
int V_108 ;
if ( V_35 -> V_78 [ 0 ] == V_175 ) {
V_108 = - V_145 ;
goto error;
}
V_174 = & V_16 -> V_176 ;
memset ( V_174 , 0 , sizeof( struct V_32 ) ) ;
V_174 -> V_78 [ 0 ] = V_175 ;
V_174 -> V_78 [ 4 ] = V_92 ;
V_174 -> V_81 = 6 ;
V_174 -> V_72 = V_74 ;
V_174 -> V_62 = V_63 ;
V_174 -> V_61 = 1 ;
V_168 = & V_174 -> V_57 [ 0 ] ;
F_34 ( V_168 , V_58 ) ;
F_74 ( V_168 , F_75 ( V_16 -> V_91 ) , V_92 ,
( unsigned long ) V_16 -> V_91 & ( V_177 - 1 ) ) ;
V_174 -> V_82 = V_92 ;
V_174 -> V_22 = V_35 -> V_22 ;
V_174 -> V_3 = V_178 ;
V_174 -> V_65 = V_35 ;
V_174 -> V_66 = V_16 -> V_67 ++ ;
V_35 -> V_62 = V_167 ;
F_26 ( V_16 , V_174 ) ;
return;
error:
F_62 ( V_16 , V_35 , V_108 ) ;
}
static int F_69 ( struct V_15 * V_16 , struct V_32 * V_35 ,
int V_179 )
{
int V_140 ;
struct V_180 * V_181 ;
int V_108 ;
V_140 = F_63 ( V_179 ) ;
if ( F_64 ( V_179 ) )
V_140 |= V_142 ;
V_181 = & V_16 -> V_182 ;
V_181 -> V_183 = V_184 ;
V_181 -> V_185 = V_186 ;
V_181 -> V_187 = F_76 ( V_188 ) ;
V_181 -> V_189 = F_76 ( V_140 ) ;
V_181 -> V_190 = F_76 ( 0 ) ;
F_51 ( V_16 -> V_120 ) ;
F_77 ( & V_16 -> V_123 , V_16 -> V_31 , V_16 -> V_191 ,
( unsigned char * ) V_181 , NULL , 0 , V_125 , V_16 ) ;
if ( ( V_108 = F_53 ( & V_16 -> V_123 , V_126 ) ) != 0 ) {
F_3 ( & V_16 -> V_120 ) ;
return V_108 ;
}
V_16 -> V_127 . V_128 = V_129 + V_192 ;
F_54 ( & V_16 -> V_127 ) ;
return 0 ;
}
static void V_178 ( struct V_15 * V_16 , struct V_32 * V_174 )
{
unsigned char * V_90 = V_16 -> V_91 ;
struct V_32 * V_35 ;
if ( ( V_35 = F_59 ( V_16 ) ) == NULL ) {
F_9 ( V_36 L_15 , V_16 -> V_37 ) ;
return;
}
if ( V_35 != V_174 -> V_65 ) {
F_9 ( V_36 L_10
L_16 ,
V_16 -> V_37 , V_35 -> V_66 ) ;
return;
}
if ( V_35 -> V_62 != V_167 ) {
F_9 ( V_36 L_17 ,
V_16 -> V_37 , V_35 -> V_62 ) ;
return;
}
V_35 -> V_95 = V_90 [ 2 ] & 0x0F ;
V_35 -> V_102 = V_90 [ 12 ] ;
V_35 -> V_103 = V_90 [ 13 ] ;
F_61 ( V_16 , V_35 ) ;
}
static void F_46 ( struct V_15 * V_16 , int V_193 )
{
if ( V_16 -> V_136 ) {
return;
}
V_16 -> V_136 = V_193 + 1 ;
#if 0
unsigned long flags;
spin_lock_irqsave(&ub_lock, flags);
sc->openc++;
spin_unlock_irqrestore(&ub_lock, flags);
#endif
#if 0
struct ub_lun *lun;
list_for_each_entry(lun, &sc->luns, link) {
blk_stop_queue(lun->disk->queue);
}
#endif
F_78 ( & V_16 -> V_194 ) ;
}
static void F_79 ( struct V_195 * V_196 )
{
struct V_15 * V_16 = F_80 ( V_196 , struct V_15 , V_194 ) ;
unsigned long V_5 ;
struct V_21 * V_22 ;
int V_108 ;
if ( ! V_16 -> V_136 ) {
F_9 ( V_36 L_18 ,
V_16 -> V_37 ) ;
return;
}
if ( F_12 ( & V_16 -> V_18 ) ) {
;
} else if ( ( V_16 -> V_136 & 1 ) == 0 ) {
F_81 ( V_16 ) ;
F_82 ( 700 ) ;
F_83 ( V_16 , V_16 -> V_170 ) ;
F_83 ( V_16 , V_16 -> V_122 ) ;
} else if ( V_16 -> V_31 -> V_197 -> V_198 . V_199 != 1 ) {
;
} else {
V_108 = F_84 ( V_16 -> V_31 , V_16 -> V_30 ) ;
if ( V_108 < 0 ) {
F_9 ( V_146
L_19 ,
V_16 -> V_37 , V_108 ) ;
} else {
V_108 = F_85 ( V_16 -> V_31 ) ;
if ( V_108 < 0 ) {
F_9 ( V_146 L_10
L_20 ,
V_16 -> V_37 , V_108 ) ;
}
F_86 ( V_16 -> V_31 ) ;
}
}
F_4 ( V_16 -> V_4 , V_5 ) ;
V_16 -> V_136 = 0 ;
F_48 ( & V_16 -> V_105 ) ;
F_87 (lun, &sc->luns, link) {
F_44 ( V_22 -> V_28 -> V_29 ) ;
}
F_88 ( & V_16 -> V_200 ) ;
F_5 ( V_16 -> V_4 , V_5 ) ;
}
static int F_89 ( struct V_201 * V_202 ) {
return 0 ;
}
static int F_90 ( struct V_201 * V_202 ) {
return 0 ;
}
static void F_91 ( struct V_15 * V_16 , struct V_21 * V_22 )
{
V_22 -> V_203 = 0 ;
V_22 -> V_76 . V_204 = 0 ;
V_22 -> V_76 . V_205 = 512 ;
V_22 -> V_76 . V_77 = 0 ;
if ( F_92 ( V_16 , V_22 ) != 0 )
return;
V_22 -> V_53 = 0 ;
if ( F_93 ( V_16 , V_22 , & V_22 -> V_76 ) != 0 ) {
if ( F_93 ( V_16 , V_22 , & V_22 -> V_76 ) != 0 ) {
V_22 -> V_76 . V_204 = 0 ;
V_22 -> V_76 . V_205 = 512 ;
V_22 -> V_76 . V_77 = 0 ;
}
}
}
static int F_94 ( struct V_206 * V_207 , T_2 V_208 )
{
struct V_21 * V_22 = V_207 -> V_209 -> V_210 ;
struct V_15 * V_16 = V_22 -> V_48 ;
unsigned long V_5 ;
int V_108 ;
F_4 ( & V_8 , V_5 ) ;
if ( F_12 ( & V_16 -> V_18 ) ) {
F_5 ( & V_8 , V_5 ) ;
return - V_99 ;
}
V_16 -> V_17 ++ ;
F_5 ( & V_8 , V_5 ) ;
if ( V_22 -> V_211 || V_22 -> V_203 )
F_95 ( V_207 ) ;
if ( V_22 -> V_211 && V_22 -> V_53 && ! ( V_208 & V_212 ) ) {
V_108 = - V_213 ;
goto V_214;
}
if ( V_22 -> V_203 && ( V_208 & V_215 ) ) {
V_108 = - V_216 ;
goto V_214;
}
return 0 ;
V_214:
F_11 ( V_16 ) ;
return V_108 ;
}
static int F_96 ( struct V_206 * V_207 , T_2 V_208 )
{
int V_6 ;
F_97 ( & V_217 ) ;
V_6 = F_94 ( V_207 , V_208 ) ;
F_98 ( & V_217 ) ;
return V_6 ;
}
static int F_99 ( struct V_218 * V_28 , T_2 V_208 )
{
struct V_21 * V_22 = V_28 -> V_210 ;
struct V_15 * V_16 = V_22 -> V_48 ;
F_97 ( & V_217 ) ;
F_11 ( V_16 ) ;
F_98 ( & V_217 ) ;
return 0 ;
}
static int F_100 ( struct V_206 * V_207 , T_2 V_208 ,
unsigned int V_35 , unsigned long V_132 )
{
struct V_218 * V_28 = V_207 -> V_209 ;
void T_3 * V_219 = ( void T_3 * ) V_132 ;
int V_6 ;
F_97 ( & V_217 ) ;
V_6 = F_101 ( V_28 -> V_29 , V_28 , V_208 , V_35 , V_219 ) ;
F_98 ( & V_217 ) ;
return V_6 ;
}
static int F_102 ( struct V_218 * V_28 )
{
struct V_21 * V_22 = V_28 -> V_210 ;
F_91 ( V_22 -> V_48 , V_22 ) ;
F_103 ( V_28 -> V_29 , V_22 -> V_76 . V_205 ) ;
F_104 ( V_28 , V_22 -> V_76 . V_204 ) ;
return 0 ;
}
static unsigned int F_105 ( struct V_218 * V_28 ,
unsigned int V_220 )
{
struct V_21 * V_22 = V_28 -> V_210 ;
if ( ! V_22 -> V_211 )
return 0 ;
if ( F_92 ( V_22 -> V_48 , V_22 ) != 0 ) {
V_22 -> V_53 = 1 ;
return V_221 ;
}
return V_22 -> V_53 ? V_221 : 0 ;
}
static void F_106 ( struct V_15 * V_16 , struct V_32 * V_35 )
{
struct V_222 * V_223 = V_35 -> V_65 ;
F_107 ( V_223 ) ;
}
static int F_92 ( struct V_15 * V_16 , struct V_21 * V_22 )
{
struct V_32 * V_35 ;
enum { V_224 = sizeof(struct V_32 ) };
unsigned long V_5 ;
struct V_222 V_225 ;
int V_108 ;
F_108 ( & V_225 ) ;
V_108 = - V_226 ;
if ( ( V_35 = F_109 ( V_224 , V_227 ) ) == NULL )
goto V_228;
V_35 -> V_78 [ 0 ] = V_229 ;
V_35 -> V_81 = 6 ;
V_35 -> V_72 = V_83 ;
V_35 -> V_62 = V_63 ;
V_35 -> V_22 = V_22 ;
V_35 -> V_3 = F_106 ;
V_35 -> V_65 = & V_225 ;
F_4 ( V_16 -> V_4 , V_5 ) ;
V_35 -> V_66 = V_16 -> V_67 ++ ;
V_108 = F_38 ( V_16 , V_35 ) ;
F_5 ( V_16 -> V_4 , V_5 ) ;
if ( V_108 != 0 )
goto V_230;
F_110 ( & V_225 ) ;
V_108 = V_35 -> error ;
if ( V_108 == - V_94 && V_35 -> V_95 != 0 )
V_108 = V_35 -> V_95 ;
V_230:
F_19 ( V_35 ) ;
V_228:
return V_108 ;
}
static int F_93 ( struct V_15 * V_16 , struct V_21 * V_22 ,
struct V_231 * V_6 )
{
struct V_32 * V_35 ;
struct V_75 * V_168 ;
char * V_20 ;
enum { V_224 = sizeof( struct V_32 ) + 8 };
unsigned long V_5 ;
unsigned int V_205 , V_232 ;
unsigned long V_204 ;
struct V_222 V_225 ;
int V_108 ;
F_108 ( & V_225 ) ;
V_108 = - V_226 ;
if ( ( V_35 = F_109 ( V_224 , V_227 ) ) == NULL )
goto V_228;
V_20 = ( char * ) V_35 + sizeof( struct V_32 ) ;
V_35 -> V_78 [ 0 ] = 0x25 ;
V_35 -> V_81 = 10 ;
V_35 -> V_72 = V_74 ;
V_35 -> V_62 = V_63 ;
V_35 -> V_61 = 1 ;
V_168 = & V_35 -> V_57 [ 0 ] ;
F_34 ( V_168 , V_58 ) ;
F_74 ( V_168 , F_75 ( V_20 ) , 8 , ( unsigned long ) V_20 & ( V_177 - 1 ) ) ;
V_35 -> V_82 = 8 ;
V_35 -> V_22 = V_22 ;
V_35 -> V_3 = F_106 ;
V_35 -> V_65 = & V_225 ;
F_4 ( V_16 -> V_4 , V_5 ) ;
V_35 -> V_66 = V_16 -> V_67 ++ ;
V_108 = F_38 ( V_16 , V_35 ) ;
F_5 ( V_16 -> V_4 , V_5 ) ;
if ( V_108 != 0 )
goto V_230;
F_110 ( & V_225 ) ;
if ( V_35 -> error != 0 ) {
V_108 = - V_94 ;
goto V_233;
}
if ( V_35 -> V_88 != 8 ) {
V_108 = - V_94 ;
goto V_233;
}
V_204 = F_111 ( * ( V_234 * ) V_20 ) + 1 ;
V_205 = F_111 ( * ( V_234 * ) ( V_20 + 4 ) ) ;
switch ( V_205 ) {
case 512 : V_232 = 0 ; break;
case 1024 : V_232 = 1 ; break;
case 2048 : V_232 = 2 ; break;
case 4096 : V_232 = 3 ; break;
default:
V_108 = - V_235 ;
goto V_236;
}
V_6 -> V_205 = V_205 ;
V_6 -> V_77 = V_232 ;
V_6 -> V_204 = V_204 << V_232 ;
V_108 = 0 ;
V_236:
V_233:
V_230:
F_19 ( V_35 ) ;
V_228:
return V_108 ;
}
static void F_112 ( struct V_133 * V_133 )
{
struct V_222 * V_223 = V_133 -> V_134 ;
F_107 ( V_223 ) ;
}
static void F_113 ( unsigned long V_132 )
{
struct V_222 * V_223 = (struct V_222 * ) V_132 ;
F_107 ( V_223 ) ;
}
static int F_81 ( struct V_15 * V_16 )
{
int V_237 = V_16 -> V_30 -> V_238 -> V_198 . V_239 ;
struct V_180 * V_181 ;
struct V_222 V_225 ;
struct V_240 V_241 ;
int V_108 ;
F_108 ( & V_225 ) ;
V_181 = & V_16 -> V_182 ;
V_181 -> V_183 = V_242 | V_243 ;
V_181 -> V_185 = V_244 ;
V_181 -> V_187 = F_76 ( 0 ) ;
V_181 -> V_189 = F_76 ( V_237 ) ;
V_181 -> V_190 = F_76 ( 0 ) ;
F_77 ( & V_16 -> V_123 , V_16 -> V_31 , V_16 -> V_191 ,
( unsigned char * ) V_181 , NULL , 0 , F_112 , & V_225 ) ;
if ( ( V_108 = F_53 ( & V_16 -> V_123 , V_227 ) ) != 0 ) {
F_9 ( V_36
L_21 , V_16 -> V_37 , V_108 ) ;
return V_108 ;
}
F_114 ( & V_241 ) ;
V_241 . V_245 = F_113 ;
V_241 . V_246 = ( unsigned long ) & V_225 ;
V_241 . V_128 = V_129 + V_192 ;
F_54 ( & V_241 ) ;
F_110 ( & V_225 ) ;
F_115 ( & V_241 ) ;
F_116 ( & V_16 -> V_123 ) ;
return V_16 -> V_123 . V_144 ;
}
static int F_117 ( struct V_15 * V_16 )
{
int V_237 = V_16 -> V_30 -> V_238 -> V_198 . V_239 ;
unsigned char * V_20 ;
enum { V_224 = 1 };
struct V_180 * V_181 ;
struct V_222 V_225 ;
struct V_240 V_241 ;
int V_247 ;
int V_108 ;
F_108 ( & V_225 ) ;
V_108 = - V_226 ;
if ( ( V_20 = F_118 ( V_224 , V_227 ) ) == NULL )
goto V_228;
* V_20 = 55 ;
V_181 = & V_16 -> V_182 ;
V_181 -> V_183 = V_142 | V_242 | V_243 ;
V_181 -> V_185 = V_248 ;
V_181 -> V_187 = F_76 ( 0 ) ;
V_181 -> V_189 = F_76 ( V_237 ) ;
V_181 -> V_190 = F_76 ( 1 ) ;
F_77 ( & V_16 -> V_123 , V_16 -> V_31 , V_16 -> V_249 ,
( unsigned char * ) V_181 , V_20 , 1 , F_112 , & V_225 ) ;
if ( ( V_108 = F_53 ( & V_16 -> V_123 , V_227 ) ) != 0 )
goto V_230;
F_114 ( & V_241 ) ;
V_241 . V_245 = F_113 ;
V_241 . V_246 = ( unsigned long ) & V_225 ;
V_241 . V_128 = V_129 + V_192 ;
F_54 ( & V_241 ) ;
F_110 ( & V_225 ) ;
F_115 ( & V_241 ) ;
F_116 ( & V_16 -> V_123 ) ;
if ( ( V_108 = V_16 -> V_123 . V_144 ) < 0 )
goto V_250;
if ( V_16 -> V_123 . V_153 != 1 ) {
V_247 = 0 ;
} else {
if ( ( V_247 = * V_20 ) == 55 ) {
V_247 = 0 ;
} else {
V_247 += 1 ;
if ( V_247 > V_251 )
V_247 = V_251 ;
}
}
F_19 ( V_20 ) ;
return V_247 ;
V_250:
V_230:
F_19 ( V_20 ) ;
V_228:
return V_108 ;
}
static int F_83 ( struct V_15 * V_16 , int V_179 )
{
int V_140 ;
struct V_180 * V_181 ;
struct V_222 V_225 ;
struct V_240 V_241 ;
int V_108 ;
F_108 ( & V_225 ) ;
V_140 = F_63 ( V_179 ) ;
if ( F_64 ( V_179 ) )
V_140 |= V_142 ;
V_181 = & V_16 -> V_182 ;
V_181 -> V_183 = V_184 ;
V_181 -> V_185 = V_186 ;
V_181 -> V_187 = F_76 ( V_188 ) ;
V_181 -> V_189 = F_76 ( V_140 ) ;
V_181 -> V_190 = F_76 ( 0 ) ;
F_77 ( & V_16 -> V_123 , V_16 -> V_31 , V_16 -> V_191 ,
( unsigned char * ) V_181 , NULL , 0 , F_112 , & V_225 ) ;
if ( ( V_108 = F_53 ( & V_16 -> V_123 , V_227 ) ) != 0 ) {
F_9 ( V_36
L_22 , V_16 -> V_37 , V_108 ) ;
return V_108 ;
}
F_114 ( & V_241 ) ;
V_241 . V_245 = F_113 ;
V_241 . V_246 = ( unsigned long ) & V_225 ;
V_241 . V_128 = V_129 + V_192 ;
F_54 ( & V_241 ) ;
F_110 ( & V_225 ) ;
F_115 ( & V_241 ) ;
F_116 ( & V_16 -> V_123 ) ;
F_65 ( V_16 -> V_31 , V_140 ) ;
return 0 ;
}
static int F_119 ( struct V_15 * V_16 , struct V_252 * V_31 ,
struct V_201 * V_30 )
{
struct V_253 * V_254 = V_30 -> V_238 ;
struct V_255 * V_256 = NULL ;
struct V_255 * V_257 = NULL ;
struct V_255 * V_258 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_254 -> V_198 . V_259 ; V_7 ++ ) {
V_258 = & V_254 -> V_260 [ V_7 ] . V_198 ;
if ( F_120 ( V_258 ) ) {
if ( F_121 ( V_258 ) ) {
if ( V_256 == NULL )
V_256 = V_258 ;
} else {
if ( V_257 == NULL )
V_257 = V_258 ;
}
}
}
if ( V_256 == NULL || V_257 == NULL ) {
F_9 ( V_146 L_23 , V_16 -> V_37 ) ;
return - V_141 ;
}
V_16 -> V_191 = F_122 ( V_31 , 0 ) ;
V_16 -> V_249 = F_123 ( V_31 , 0 ) ;
V_16 -> V_122 = F_124 ( V_31 ,
F_125 ( V_257 ) ) ;
V_16 -> V_170 = F_126 ( V_31 ,
F_125 ( V_256 ) ) ;
return 0 ;
}
static int F_127 ( struct V_201 * V_30 ,
const struct V_261 * V_262 )
{
struct V_15 * V_16 ;
int V_247 ;
int V_108 ;
int V_7 ;
if ( F_128 ( V_262 , V_263 ) )
return - V_99 ;
V_108 = - V_226 ;
if ( ( V_16 = F_109 ( sizeof( struct V_15 ) , V_227 ) ) == NULL )
goto V_264;
V_16 -> V_4 = F_10 () ;
F_129 ( & V_16 -> V_25 ) ;
F_130 ( & V_16 -> V_123 ) ;
F_131 ( & V_16 -> V_105 , F_57 , ( unsigned long ) V_16 ) ;
F_132 ( & V_16 -> V_18 , 0 ) ;
F_133 ( & V_16 -> V_194 , F_79 ) ;
F_134 ( & V_16 -> V_200 ) ;
F_114 ( & V_16 -> V_127 ) ;
V_16 -> V_127 . V_246 = ( unsigned long ) V_16 ;
V_16 -> V_127 . V_245 = F_55 ;
F_1 ( & V_16 -> V_120 ) ;
V_16 -> V_120 . V_3 = 1 ;
V_16 -> V_31 = F_135 ( V_30 ) ;
V_16 -> V_30 = V_30 ;
F_20 ( V_30 , V_16 ) ;
F_136 ( V_16 -> V_31 ) ;
F_137 ( V_16 -> V_30 ) ;
snprintf ( V_16 -> V_37 , 12 , V_265 L_24 ,
V_16 -> V_31 -> V_266 -> V_267 , V_16 -> V_31 -> V_268 ) ;
if ( F_119 ( V_16 , V_16 -> V_31 , V_30 ) != 0 )
goto V_269;
#if 0
ub_probe_clear_stall(sc, sc->recv_bulk_pipe);
ub_probe_clear_stall(sc, sc->send_bulk_pipe);
#endif
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
if ( ( V_108 = F_92 ( V_16 , NULL ) ) <= 0 ) break;
if ( V_108 != 0x6 ) break;
F_82 ( 10 ) ;
}
V_247 = 1 ;
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
if ( ( V_108 = F_117 ( V_16 ) ) < 0 )
break;
if ( V_108 != 0 ) {
V_247 = V_108 ;
break;
}
F_82 ( 100 ) ;
}
for ( V_7 = 0 ; V_7 < V_247 ; V_7 ++ ) {
F_138 ( V_16 , V_7 ) ;
}
return 0 ;
V_269:
F_20 ( V_30 , NULL ) ;
F_21 ( V_16 -> V_30 ) ;
F_22 ( V_16 -> V_31 ) ;
F_19 ( V_16 ) ;
V_264:
return V_108 ;
}
static int F_138 ( struct V_15 * V_16 , int V_270 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_218 * V_28 ;
int V_108 ;
V_108 = - V_226 ;
if ( ( V_22 = F_109 ( sizeof( struct V_21 ) , V_227 ) ) == NULL )
goto V_228;
V_22 -> V_116 = V_270 ;
V_108 = - V_271 ;
if ( ( V_22 -> V_11 = F_7 () ) == - 1 )
goto V_272;
V_22 -> V_48 = V_16 ;
snprintf ( V_22 -> V_37 , 16 , V_265 L_25 ,
V_22 -> V_11 + 'a' , V_16 -> V_31 -> V_266 -> V_267 , V_16 -> V_31 -> V_268 , V_22 -> V_116 ) ;
V_22 -> V_211 = 1 ;
V_22 -> V_53 = 1 ;
F_91 ( V_16 , V_22 ) ;
V_108 = - V_226 ;
if ( ( V_28 = F_139 ( V_273 ) ) == NULL )
goto V_274;
sprintf ( V_28 -> V_275 , V_265 L_26 , V_22 -> V_11 + 'a' ) ;
V_28 -> V_276 = V_277 ;
V_28 -> V_278 = V_22 -> V_11 * V_273 ;
V_28 -> V_279 = & V_280 ;
V_28 -> V_210 = V_22 ;
V_28 -> V_281 = & V_16 -> V_30 -> V_31 ;
V_108 = - V_226 ;
if ( ( V_24 = F_140 ( F_28 , V_16 -> V_4 ) ) == NULL )
goto V_282;
V_28 -> V_29 = V_24 ;
F_141 ( V_24 , V_283 ) ;
F_142 ( V_24 , V_58 ) ;
F_143 ( V_24 , 0xffffffff ) ;
F_144 ( V_24 , V_284 ) ;
F_103 ( V_24 , V_22 -> V_76 . V_205 ) ;
V_22 -> V_28 = V_28 ;
V_24 -> V_45 = V_22 ;
F_145 ( & V_22 -> V_27 , & V_16 -> V_25 ) ;
F_104 ( V_28 , V_22 -> V_76 . V_204 ) ;
if ( V_22 -> V_211 )
V_28 -> V_5 |= V_285 ;
F_146 ( V_28 ) ;
return 0 ;
V_282:
F_18 ( V_28 ) ;
V_274:
F_8 ( V_22 -> V_11 ) ;
V_272:
F_19 ( V_22 ) ;
V_228:
return V_108 ;
}
static void F_147 ( struct V_201 * V_30 )
{
struct V_15 * V_16 = F_148 ( V_30 ) ;
struct V_21 * V_22 ;
unsigned long V_5 ;
F_4 ( & V_8 , V_5 ) ;
V_16 -> V_17 ++ ;
F_5 ( & V_8 , V_5 ) ;
F_132 ( & V_16 -> V_18 , 1 ) ;
F_149 ( V_16 -> V_200 , ! V_16 -> V_136 ) ;
F_4 ( V_16 -> V_4 , V_5 ) ;
{
struct V_32 * V_35 ;
int V_286 = 0 ;
while ( ( V_35 = F_59 ( V_16 ) ) != NULL ) {
V_35 -> error = - V_287 ;
V_35 -> V_62 = V_137 ;
F_27 ( V_16 ) ;
(* V_35 -> V_3 )( V_16 , V_35 ) ;
V_286 ++ ;
}
if ( V_286 != 0 ) {
F_9 ( V_36 L_10
L_27 , V_16 -> V_37 , V_286 ) ;
}
}
F_5 ( V_16 -> V_4 , V_5 ) ;
F_87 (lun, &sc->luns, link) {
F_150 ( V_22 -> V_28 ) ;
}
F_4 ( V_16 -> V_4 , V_5 ) ;
if ( V_16 -> V_123 . V_144 == - V_288 ) {
F_9 ( V_36 L_10
L_28 , V_16 -> V_37 ) ;
}
F_5 ( V_16 -> V_4 , V_5 ) ;
F_115 ( & V_16 -> V_127 ) ;
F_11 ( V_16 ) ;
}
static int T_4 F_151 ( void )
{
int V_108 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_14 ; V_7 ++ )
F_2 ( & V_12 [ V_7 ] ) ;
if ( ( V_108 = F_152 ( V_277 , V_265 ) ) != 0 )
goto V_289;
if ( ( V_108 = F_153 ( & V_290 ) ) != 0 )
goto V_291;
F_154 ( V_263 ) ;
return 0 ;
V_291:
F_155 ( V_277 , V_265 ) ;
V_289:
return V_108 ;
}
static void T_5 F_156 ( void )
{
F_157 ( & V_290 ) ;
F_155 ( V_277 , V_265 ) ;
F_158 ( V_263 ) ;
}
