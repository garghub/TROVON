static int
F_1 ( void )
{
short V_1 ;
struct V_2 * V_3 ;
for ( V_1 = 0 ; V_1 < V_4 ; V_1 ++ ) {
V_3 = & V_5 [ V_1 ] . V_6 . V_7 ;
F_2 ( & V_3 -> V_8 ) ;
F_3 ( & V_3 -> V_9 ) ;
V_3 -> V_10 = V_11 ;
}
return 0 ;
}
static void
F_4 ( void )
{
short V_1 ;
struct V_2 * V_3 ;
unsigned long V_12 ;
for ( V_1 = 0 ; V_1 < V_4 ; V_1 ++ ) {
V_3 = & V_5 [ V_1 ] . V_6 . V_7 ;
if ( V_3 -> V_13 != NULL ) {
F_5 ( & V_3 -> V_8 ) ;
F_6 ( & V_3 -> V_9 , V_12 ) ;
V_3 -> V_14 &= ~ V_15 ;
F_7 ( & V_3 -> V_9 , V_12 ) ;
F_8 ( V_3 -> V_13 ) ;
V_3 -> V_13 = NULL ;
F_9 ( & V_3 ->
V_8 ) ;
}
}
}
static int
F_10 ( struct V_16 * V_17 , int V_18 , char * V_19 )
{
int V_20 = F_11 ( V_17 -> V_21 ) ;
#if V_22 V_23
V_17 -> V_24 = F_12 ( V_19 , V_18 , V_17 -> V_21 , V_17 -> V_25 ,
V_26 ) ;
if ( V_17 -> V_24 < 0 ) {
F_13 ( V_27 , L_1 ,
- V_17 -> V_24 ) ;
return V_17 -> V_24 ;
}
V_17 -> V_28 = F_14 ( V_20 , V_17 -> V_25 ) ;
#elif V_22 V_29 || V_22 V_30
if ( strcmp ( V_19 , V_31 ) == 0 )
V_17 -> V_24 = V_32 ;
else if ( strcmp ( V_19 , V_33 ) == 0 )
V_17 -> V_24 = V_34 ;
else
return - V_35 ;
V_17 -> V_28 = ( unsigned long ) F_15 ( V_18 ) << 32 | V_17 -> V_24 ;
F_16 ( V_20 , V_17 -> V_25 , V_17 -> V_28 ) ;
#else
#error not a supported configuration
#endif
return 0 ;
}
static void
F_17 ( struct V_16 * V_17 )
{
#if V_22 V_23
F_18 ( V_17 -> V_24 ) ;
#elif V_22 V_29 || V_22 V_30
int V_20 ;
unsigned long V_28 ;
V_20 = F_11 ( V_17 -> V_21 ) ;
V_28 = 1UL << 16 ;
F_16 ( V_20 , V_17 -> V_25 , V_28 ) ;
#else
#error not a supported configuration
#endif
}
static int
F_19 ( struct V_16 * V_17 )
{
int V_36 ;
#if V_22 V_29 || V_22 V_30
int V_20 = F_11 ( V_17 -> V_21 ) ;
V_36 = F_20 ( V_20 , ( void * ) F_21 ( V_17 -> V_37 ) ,
V_17 -> V_38 , & V_17 -> V_25 ) ;
if ( V_36 < 0 ) {
F_13 ( V_27 , L_2 ,
V_36 ) ;
return - V_39 ;
}
#elif V_22 V_23
V_36 = F_22 ( F_21 ( V_17 -> V_37 ) ,
V_17 -> V_38 , & V_17 -> V_25 ) ;
if ( V_36 < 0 ) {
F_13 ( V_27 , L_3
L_4 , V_36 ) ;
return V_36 ;
}
#else
#error not a supported configuration
#endif
V_17 -> V_40 = V_36 ;
return 0 ;
}
static void
F_23 ( struct V_16 * V_17 )
{
int V_36 ;
int V_20 = F_11 ( V_17 -> V_21 ) ;
#if V_22 V_23
V_36 = F_24 ( V_20 , V_17 -> V_40 ) ;
F_25 ( V_36 != V_41 ) ;
#elif V_22 V_29 || V_22 V_30
V_36 = F_26 ( V_20 , V_17 -> V_40 ) ;
F_25 ( V_36 != V_42 ) ;
#else
#error not a supported configuration
#endif
}
static struct V_16 *
F_27 ( unsigned int V_43 , int V_18 , char * V_19 ,
T_1 V_44 )
{
enum V_45 V_46 ;
int V_36 ;
int V_47 ;
int V_48 ;
int V_49 ;
struct V_50 * V_50 ;
struct V_16 * V_17 ;
struct V_51 * V_28 ;
V_17 = F_28 ( sizeof( struct V_16 ) , V_52 ) ;
if ( V_17 == NULL ) {
F_13 ( V_27 , L_5
L_6 ) ;
V_36 = - V_53 ;
goto V_54;
}
V_17 -> V_55 = F_29 ( sizeof( struct V_56 ) ,
V_52 ) ;
if ( V_17 -> V_55 == NULL ) {
F_13 ( V_27 , L_5
L_7 ) ;
V_36 = - V_53 ;
goto V_57;
}
V_49 = F_30 ( V_43 ) ;
V_17 -> V_38 = V_49 + V_58 ;
V_43 = 1UL << V_17 -> V_38 ;
V_17 -> V_21 = F_31 ( V_18 ) ;
V_47 = F_32 ( V_18 ) ;
V_50 = F_33 ( V_47 , V_52 | V_59 | V_60 ,
V_49 ) ;
if ( V_50 == NULL ) {
F_13 ( V_27 , L_8
L_9 , V_43 , V_47 ) ;
V_36 = - V_53 ;
goto V_61;
}
V_17 -> V_37 = F_34 ( V_50 ) ;
V_36 = F_19 ( V_17 ) ;
if ( V_36 != 0 )
goto V_62;
V_36 = F_10 ( V_17 , V_18 , V_19 ) ;
if ( V_36 != 0 )
goto V_63;
V_36 = F_35 ( V_17 -> V_24 , V_44 , 0 , V_19 , NULL ) ;
if ( V_36 != 0 ) {
F_13 ( V_27 , L_10 ,
V_17 -> V_24 , - V_36 ) ;
goto V_64;
}
V_48 = F_36 ( F_37 ( V_18 ) ) ;
V_28 = (struct V_51 * ) & V_17 -> V_28 ;
V_36 = F_38 ( V_17 -> V_55 , V_17 -> V_37 , V_43 ,
V_48 , V_28 -> V_65 , V_28 -> V_66 ) ;
if ( V_36 != 0 ) {
F_13 ( V_27 , L_11
L_12 , V_36 ) ;
V_36 = - V_35 ;
goto V_67;
}
V_46 = F_39 ( F_40 ( V_17 -> V_37 ) , V_43 ) ;
if ( V_46 != V_68 ) {
V_36 = - V_69 ;
goto V_67;
}
return V_17 ;
V_67:
F_41 ( V_17 -> V_24 , NULL ) ;
V_64:
F_17 ( V_17 ) ;
V_63:
F_23 ( V_17 ) ;
V_62:
F_42 ( ( unsigned long ) V_17 -> V_37 , V_49 ) ;
V_61:
F_8 ( V_17 -> V_55 ) ;
V_57:
F_8 ( V_17 ) ;
V_54:
return F_43 ( V_36 ) ;
}
static void
F_44 ( struct V_16 * V_17 )
{
unsigned int V_43 ;
int V_49 ;
int V_36 ;
V_43 = 1UL << V_17 -> V_38 ;
V_36 = F_45 ( F_40 ( V_17 -> V_37 ) , V_43 ) ;
F_25 ( V_36 != V_68 ) ;
F_41 ( V_17 -> V_24 , NULL ) ;
F_17 ( V_17 ) ;
F_23 ( V_17 ) ;
V_49 = V_17 -> V_38 - V_58 ;
F_42 ( ( unsigned long ) V_17 -> V_37 , V_49 ) ;
F_8 ( V_17 ) ;
}
static enum V_45
F_46 ( struct V_56 * V_55 , void * V_70 ,
T_2 V_71 )
{
enum V_45 V_46 ;
int V_36 ;
while ( 1 ) {
V_36 = F_47 ( V_55 , V_70 , V_71 ) ;
if ( V_36 == V_72 ) {
V_46 = V_68 ;
break;
}
if ( V_36 == V_73 ) {
F_48 ( V_74 , L_13
L_14 ) ;
( void ) F_49 ( 10 ) ;
} else if ( V_36 == V_75 ) {
F_48 ( V_74 , L_13
L_15 ) ;
} else {
F_13 ( V_74 , L_13
L_12 , V_36 ) ;
V_46 = V_76 ;
break;
}
}
return V_46 ;
}
static void
F_50 ( void )
{
unsigned long V_12 ;
short V_1 ;
struct V_77 * V_78 ;
T_3 V_79 ;
F_51 ( V_80 == 0 ) ;
F_6 ( & V_81 , V_12 ) ;
for ( V_1 = 0 ; V_1 < V_4 ; V_1 ++ ) {
V_78 = & V_5 [ V_1 ] ;
if ( V_78 -> V_6 . V_7 . V_79 == 0 )
continue;
V_80 -- ;
F_25 ( V_80 < 0 ) ;
V_79 = V_78 -> V_6 . V_7 . V_79 ;
V_78 -> V_6 . V_7 . V_79 = 0 ;
F_7 ( & V_81 , V_12 ) ;
if ( V_79 == V_82 ) {
if ( V_78 -> V_83 == V_11 )
F_52 ( V_78 ) ;
else if ( V_78 -> V_83 == V_84 )
F_53 ( V_78 , V_85 ) ;
} else if ( V_79 == V_86 ) {
if ( V_78 -> V_83 == V_11 )
F_52 ( V_78 ) ;
else
F_53 ( V_78 , V_85 ) ;
} else if ( V_79 == V_87 ) {
F_53 ( V_78 , V_78 -> V_6 . V_7 . V_88 ) ;
} else {
F_54 () ;
}
F_6 ( & V_81 , V_12 ) ;
if ( V_80 == 0 )
break;
}
F_7 ( & V_81 , V_12 ) ;
}
static void
F_55 ( struct V_77 * V_78 ,
struct V_89 * V_90 ,
int V_91 ,
int * V_92 )
{
unsigned long V_12 ;
struct V_2 * V_3 = & V_78 -> V_6 . V_7 ;
struct V_93 * args ;
V_3 -> V_10 = V_90 -> V_83 ;
switch ( V_90 -> type ) {
case V_94 :
break;
case V_95 : {
struct V_96 * V_70 ;
V_70 = F_56 ( V_90 , struct
V_96 , V_97 ) ;
F_6 ( & V_81 , V_12 ) ;
if ( V_3 -> V_79 == 0 )
V_80 ++ ;
V_3 -> V_79 = V_82 ;
V_78 -> V_98 = V_70 -> V_99 ;
V_78 -> V_100 = V_90 -> V_101 ;
V_3 -> V_102 = V_70 -> V_102 ;
if ( V_70 -> V_103 !=
V_3 -> V_103 ) {
F_6 ( & V_3 -> V_9 , V_12 ) ;
V_3 -> V_14 &= ~ V_15 ;
F_7 ( & V_3 -> V_9 , V_12 ) ;
V_3 -> V_103 =
V_70 -> V_103 ;
}
F_7 ( & V_81 , V_12 ) ;
( * V_92 ) ++ ;
break;
}
case V_104 : {
struct V_105 * V_70 ;
V_70 = F_56 ( V_90 , struct
V_105 , V_97 ) ;
F_6 ( & V_81 , V_12 ) ;
if ( V_3 -> V_79 == 0 )
V_80 ++ ;
V_3 -> V_79 = V_87 ;
V_3 -> V_88 = V_70 -> V_88 ;
F_7 ( & V_81 , V_12 ) ;
( * V_92 ) ++ ;
return;
}
case V_106 : {
struct V_107 * V_70 ;
if ( ! V_91 )
break;
V_70 = F_56 ( V_90 , struct
V_107 ,
V_97 ) ;
args = & V_78 -> V_108 [ V_70 -> V_109 ] ;
args -> V_88 = V_70 -> V_88 ;
F_6 ( & V_78 -> V_110 , V_12 ) ;
V_78 -> V_111 . V_14 [ V_70 -> V_109 ] |= V_112 ;
F_7 ( & V_78 -> V_110 , V_12 ) ;
F_57 ( V_78 ) ;
break;
}
case V_113 : {
struct V_114 * V_70 ;
if ( ! V_91 )
break;
V_70 = F_56 ( V_90 , struct
V_114 ,
V_97 ) ;
F_6 ( & V_78 -> V_110 , V_12 ) ;
V_78 -> V_111 . V_14 [ V_70 -> V_109 ] |= V_115 ;
F_7 ( & V_78 -> V_110 , V_12 ) ;
F_57 ( V_78 ) ;
break;
}
case V_116 : {
struct V_117 * V_70 ;
if ( ! V_91 )
break;
V_70 = F_56 ( V_90 , struct
V_117 ,
V_97 ) ;
args = & V_78 -> V_108 [ V_70 -> V_109 ] ;
args -> V_118 = V_70 -> V_118 ;
args -> V_119 = V_70 -> V_119 ;
F_6 ( & V_78 -> V_110 , V_12 ) ;
V_78 -> V_111 . V_14 [ V_70 -> V_109 ] |= V_120 ;
F_7 ( & V_78 -> V_110 , V_12 ) ;
F_57 ( V_78 ) ;
break;
}
case V_121 : {
struct V_122 * V_70 ;
if ( ! V_91 )
break;
V_70 = F_56 ( V_90 , struct
V_122 , V_97 ) ;
args = & V_78 -> V_108 [ V_70 -> V_109 ] ;
args -> V_123 = V_70 -> V_123 ;
args -> V_119 = V_70 -> V_119 ;
args -> V_124 = V_70 -> V_125 ;
F_6 ( & V_78 -> V_110 , V_12 ) ;
V_78 -> V_111 . V_14 [ V_70 -> V_109 ] |= V_126 ;
F_7 ( & V_78 -> V_110 , V_12 ) ;
F_57 ( V_78 ) ;
break;
}
case V_127 : {
struct V_128 * V_70 ;
if ( ! V_91 )
break;
V_70 = F_56 ( V_90 , struct
V_128 , V_97 ) ;
F_6 ( & V_78 -> V_110 , V_12 ) ;
V_78 -> V_111 . V_14 [ V_70 -> V_109 ] |= V_129 ;
F_7 ( & V_78 -> V_110 , V_12 ) ;
F_57 ( V_78 ) ;
}
case V_130 :
F_6 ( & V_3 -> V_9 , V_12 ) ;
V_3 -> V_14 |= V_131 ;
F_7 ( & V_3 -> V_9 , V_12 ) ;
break;
case V_132 :
F_6 ( & V_3 -> V_9 , V_12 ) ;
V_3 -> V_14 &= ~ V_131 ;
F_7 ( & V_3 -> V_9 , V_12 ) ;
break;
default:
F_13 ( V_27 , L_16
L_17 , V_90 -> type , F_58 ( V_78 ) ) ;
F_6 ( & V_81 , V_12 ) ;
if ( V_3 -> V_79 == 0 )
V_80 ++ ;
V_3 -> V_79 = V_87 ;
V_3 -> V_88 = V_133 ;
F_7 ( & V_81 , V_12 ) ;
( * V_92 ) ++ ;
return;
}
if ( V_90 -> V_101 != V_78 -> V_100 &&
V_78 -> V_100 != 0 ) {
F_6 ( & V_81 , V_12 ) ;
if ( V_3 -> V_79 == 0 )
V_80 ++ ;
V_3 -> V_79 = V_86 ;
F_7 ( & V_81 , V_12 ) ;
( * V_92 ) ++ ;
}
}
static T_4
F_59 ( int V_24 , void * V_134 )
{
struct V_89 * V_90 ;
short V_1 ;
struct V_77 * V_78 ;
int V_92 = 0 ;
int V_135 ;
while ( 1 ) {
V_90 = F_60 ( V_136 -> V_55 ) ;
if ( V_90 == NULL )
break;
V_1 = V_90 -> V_1 ;
if ( V_1 < 0 || V_1 >= V_4 ) {
F_13 ( V_27 , L_18
L_19 ,
V_1 ) ;
} else {
V_78 = & V_5 [ V_1 ] ;
V_135 = F_61 ( V_78 ) ;
F_55 ( V_78 , V_90 ,
V_135 ,
& V_92 ) ;
if ( V_135 )
F_62 ( V_78 ) ;
}
F_63 ( V_136 -> V_55 , V_90 ) ;
}
if ( V_92 )
F_64 ( & V_137 ) ;
return V_138 ;
}
static enum V_45
F_65 ( struct V_56 * V_55 ,
unsigned long V_139 )
{
enum V_45 V_36 ;
V_36 = F_66 ( F_21 ( V_55 ) , V_139 ,
sizeof( struct V_56 ) ) ;
if ( V_36 == V_68 )
V_55 -> V_17 = NULL ;
return V_36 ;
}
static enum V_45
F_67 ( struct V_77 * V_78 , void * V_70 , T_2 V_71 ,
int V_140 )
{
struct V_89 * V_90 = V_70 ;
struct V_2 * V_3 = & V_78 -> V_6 . V_7 ;
struct V_56 * V_55 ;
unsigned long V_12 ;
enum V_45 V_36 ;
F_51 ( V_71 > V_141 ) ;
V_90 -> type = V_140 ;
V_90 -> V_1 = V_142 ;
V_90 -> V_83 = V_78 -> V_83 ;
V_90 -> V_101 = V_143 -> V_144 ;
F_5 ( & V_3 -> V_8 ) ;
V_145:
if ( ! ( V_3 -> V_14 & V_15 ) ) {
V_55 = V_3 -> V_13 ;
if ( V_55 == NULL ) {
V_55 = F_28 ( sizeof( struct
V_56 ) ,
V_52 ) ;
if ( V_55 == NULL ) {
V_36 = V_146 ;
goto V_147;
}
V_3 -> V_13 = V_55 ;
}
V_36 = F_65 ( V_55 ,
V_3 ->
V_103 ) ;
if ( V_36 != V_68 )
goto V_147;
F_6 ( & V_3 -> V_9 , V_12 ) ;
V_3 -> V_14 |= V_15 ;
F_7 ( & V_3 -> V_9 , V_12 ) ;
}
V_36 = F_46 ( V_3 -> V_13 , V_70 ,
V_71 ) ;
if ( V_36 != V_68 ) {
F_68 () ;
if ( ! ( V_3 -> V_14 & V_15 ) )
goto V_145;
}
V_147:
F_9 ( & V_3 -> V_8 ) ;
return V_36 ;
}
static void
F_69 ( struct V_77 * V_78 , void * V_70 ,
T_2 V_71 , int V_140 )
{
enum V_45 V_36 ;
V_36 = F_67 ( V_78 , V_70 , V_71 , V_140 ) ;
if ( F_70 ( V_36 != V_68 ) )
F_53 ( V_78 , V_36 ) ;
}
static void
F_71 ( struct V_148 * V_149 , unsigned long * V_12 ,
void * V_70 , T_2 V_71 , int V_140 )
{
struct V_77 * V_78 = & V_5 [ V_149 -> V_1 ] ;
enum V_45 V_36 ;
V_36 = F_67 ( V_78 , V_70 , V_71 , V_140 ) ;
if ( F_70 ( V_36 != V_68 ) ) {
if ( V_12 != NULL )
F_7 ( & V_149 -> V_150 , * V_12 ) ;
F_53 ( V_78 , V_36 ) ;
if ( V_12 != NULL )
F_6 ( & V_149 -> V_150 , * V_12 ) ;
}
}
static void
F_72 ( struct V_77 * V_78 , int V_79 )
{
unsigned long V_12 ;
struct V_2 * V_3 = & V_78 -> V_6 . V_7 ;
F_6 ( & V_81 , V_12 ) ;
if ( V_3 -> V_79 == 0 )
V_80 ++ ;
V_3 -> V_79 = V_79 ;
F_7 ( & V_81 , V_12 ) ;
F_64 ( & V_137 ) ;
}
static enum V_45
F_73 ( void * V_151 , T_5 * V_152 , unsigned long * V_153 ,
T_2 * V_154 )
{
T_6 V_155 ;
enum V_45 V_36 ;
#if V_22 V_23
V_155 = F_74 ( ( T_5 ) V_151 , V_152 , ( T_5 * ) V_153 ,
( T_5 * ) V_154 ) ;
if ( V_155 == V_41 )
V_36 = V_68 ;
else if ( V_155 == V_156 )
V_36 = V_157 ;
else
V_36 = V_158 ;
#elif V_22 V_29 || V_22 V_30
V_155 = F_75 ( ( T_5 ) V_151 , V_152 , V_153 , V_154 ) ;
if ( V_155 == V_42 )
V_36 = V_68 ;
else if ( V_155 == V_159 )
V_36 = V_157 ;
else
V_36 = V_160 ;
#else
#error not a supported configuration
#endif
return V_36 ;
}
static int
F_76 ( struct V_143 * V_161 )
{
V_162 =
& V_5 [ V_163 ] . V_6 . V_7 . V_164 ;
V_161 -> V_6 . V_7 . V_102 = F_21 ( V_162 ) ;
V_161 -> V_6 . V_7 . V_103 =
F_21 ( V_136 -> V_55 ) ;
return 0 ;
}
static void
F_77 ( short V_1 )
{
}
static void
F_78 ( short V_1 )
{
}
static void
F_79 ( void )
{
}
static void
F_80 ( void )
{
V_162 -> V_165 ++ ;
}
static void
F_81 ( void )
{
F_80 () ;
V_162 -> V_166 = 1 ;
}
static void
F_82 ( void )
{
F_80 () ;
V_162 -> V_166 = 0 ;
}
static void
F_83 ( void )
{
V_162 -> V_165 = 1 ;
V_162 -> V_166 = 0 ;
}
static void
F_84 ( void )
{
F_81 () ;
}
static enum V_45
F_85 ( struct V_77 * V_78 )
{
struct V_2 * V_3 = & V_78 -> V_6 . V_7 ;
enum V_45 V_36 ;
V_36 = F_66 ( F_21 ( & V_3 -> V_164 ) ,
V_3 -> V_102 ,
sizeof( struct V_162 ) ) ;
if ( V_36 != V_68 )
return V_36 ;
if ( V_3 -> V_164 . V_165 == V_78 -> V_167 &&
! V_3 -> V_164 . V_166 ) {
V_36 = V_168 ;
} else {
V_78 -> V_167 = V_3 -> V_164 . V_165 ;
}
return V_36 ;
}
static void
F_86 ( struct V_143 * V_169 ,
unsigned long V_170 , int V_48 )
{
short V_1 = V_169 -> V_171 ;
struct V_77 * V_78 = & V_5 [ V_1 ] ;
struct V_96 V_70 ;
V_78 -> V_98 = V_170 ;
V_78 -> V_100 = V_169 -> V_144 ;
V_78 -> V_6 . V_7 . V_102 = V_169 -> V_6 . V_7 . V_102 ;
V_78 -> V_6 . V_7 . V_103 =
V_169 -> V_6 . V_7 . V_103 ;
if ( V_78 -> V_6 . V_7 . V_10 == V_11 ) {
V_70 . V_99 = F_21 ( V_143 ) ;
V_70 . V_102 = V_143 -> V_6 . V_7 . V_102 ;
V_70 . V_103 =
V_143 -> V_6 . V_7 . V_103 ;
F_69 ( V_78 , & V_70 , sizeof( V_70 ) ,
V_95 ) ;
}
if ( V_78 -> V_83 == V_11 )
F_72 ( V_78 , V_82 ) ;
}
static void
F_87 ( struct V_77 * V_78 )
{
F_72 ( V_78 , V_82 ) ;
}
static void
F_88 ( struct V_77 * V_78 )
{
struct V_105 V_70 ;
if ( V_78 -> V_6 . V_7 . V_10 != V_84 &&
V_78 -> V_6 . V_7 . V_10 != V_11 ) {
V_70 . V_88 = V_78 -> V_88 ;
F_69 ( V_78 , & V_70 , sizeof( V_70 ) ,
V_104 ) ;
}
}
static void
F_89 ( struct V_77 * V_78 )
{
return;
}
static void
F_90 ( struct V_172 * V_173 )
{
V_173 -> V_174 = NULL ;
V_173 -> V_175 = NULL ;
F_3 ( & V_173 -> V_150 ) ;
V_173 -> V_176 = 0 ;
}
static void *
F_91 ( struct V_172 * V_173 )
{
unsigned long V_12 ;
struct V_177 * V_174 ;
F_6 ( & V_173 -> V_150 , V_12 ) ;
V_174 = V_173 -> V_174 ;
if ( V_173 -> V_174 != NULL ) {
V_173 -> V_174 = V_174 -> V_178 ;
if ( V_173 -> V_174 == NULL )
V_173 -> V_175 = NULL ;
V_173 -> V_176 -- ;
F_25 ( V_173 -> V_176 < 0 ) ;
V_174 -> V_178 = NULL ;
}
F_7 ( & V_173 -> V_150 , V_12 ) ;
return V_174 ;
}
static void
F_92 ( struct V_172 * V_173 ,
struct V_177 * V_175 )
{
unsigned long V_12 ;
V_175 -> V_178 = NULL ;
F_6 ( & V_173 -> V_150 , V_12 ) ;
if ( V_173 -> V_175 != NULL )
V_173 -> V_175 -> V_178 = V_175 ;
else
V_173 -> V_174 = V_175 ;
V_173 -> V_175 = V_175 ;
V_173 -> V_176 ++ ;
F_7 ( & V_173 -> V_150 , V_12 ) ;
}
static int
F_93 ( struct V_172 * V_173 )
{
return V_173 -> V_176 ;
}
static enum V_45
F_94 ( struct V_77 * V_78 )
{
struct V_179 * V_180 ;
int V_109 ;
for ( V_109 = 0 ; V_109 < V_78 -> V_181 ; V_109 ++ ) {
V_180 = & V_78 -> V_182 [ V_109 ] . V_6 . V_7 ;
F_90 ( & V_180 -> V_183 ) ;
F_90 ( & V_180 -> V_184 ) ;
}
return V_68 ;
}
static void
F_95 ( struct V_77 * V_78 )
{
return;
}
static enum V_45
F_96 ( struct V_77 * V_78 )
{
struct V_185 V_70 ;
F_69 ( V_78 , & V_70 , sizeof( V_70 ) ,
V_94 ) ;
while ( ! ( ( V_78 -> V_6 . V_7 . V_10 == V_186 ) ||
( V_78 -> V_6 . V_7 . V_10 == V_187 ) ) ) {
F_48 ( V_27 , L_20
L_21 , F_58 ( V_78 ) ) ;
( void ) F_49 ( 250 ) ;
if ( V_78 -> V_83 == V_84 )
return V_78 -> V_88 ;
}
return V_68 ;
}
static T_5
F_97 ( struct V_77 * V_78 )
{
unsigned long V_12 ;
union V_188 V_111 ;
F_6 ( & V_78 -> V_110 , V_12 ) ;
V_111 = V_78 -> V_111 ;
if ( V_111 . V_189 != 0 )
V_78 -> V_111 . V_189 = 0 ;
F_7 ( & V_78 -> V_110 , V_12 ) ;
return V_111 . V_189 ;
}
static enum V_45
F_98 ( struct V_148 * V_149 )
{
struct V_179 * V_180 = & V_149 -> V_6 . V_7 ;
struct V_190 * V_191 ;
unsigned long V_12 ;
int V_192 ;
int V_193 ;
T_2 V_194 ;
for ( V_192 = V_149 -> V_119 ; V_192 > 0 ; V_192 -- ) {
V_194 = V_192 * sizeof( struct V_190 ) ;
V_180 -> V_195 = F_29 ( V_194 , V_52 ) ;
if ( V_180 -> V_195 == NULL )
continue;
for ( V_193 = 0 ; V_193 < V_192 ; V_193 ++ ) {
V_191 = & V_180 -> V_195 [ V_193 ] ;
V_191 -> V_196 = V_193 ;
F_92 ( & V_180 -> V_183 ,
& V_191 -> V_178 ) ;
}
F_6 ( & V_149 -> V_150 , V_12 ) ;
if ( V_192 < V_149 -> V_119 )
V_149 -> V_119 = V_192 ;
F_7 ( & V_149 -> V_150 , V_12 ) ;
return V_68 ;
}
return V_146 ;
}
static enum V_45
F_99 ( struct V_148 * V_149 )
{
struct V_179 * V_180 = & V_149 -> V_6 . V_7 ;
struct V_197 * V_191 ;
unsigned long V_12 ;
int V_192 ;
int V_193 ;
T_2 V_194 ;
for ( V_192 = V_149 -> V_123 ; V_192 > 0 ; V_192 -- ) {
V_194 = V_192 * V_149 -> V_118 ;
V_180 -> V_198 = F_29 ( V_194 , V_52 ) ;
if ( V_180 -> V_198 == NULL )
continue;
for ( V_193 = 0 ; V_193 < V_192 ; V_193 ++ ) {
V_191 = V_180 -> V_198 +
V_193 * V_149 -> V_118 ;
V_191 -> V_97 . V_196 = V_193 ;
}
F_6 ( & V_149 -> V_150 , V_12 ) ;
if ( V_192 < V_149 -> V_123 )
V_149 -> V_123 = V_192 ;
F_7 ( & V_149 -> V_150 , V_12 ) ;
return V_68 ;
}
return V_146 ;
}
static enum V_45
F_100 ( struct V_148 * V_149 )
{
static enum V_45 V_36 ;
struct V_179 * V_180 = & V_149 -> V_6 . V_7 ;
F_51 ( V_149 -> V_14 & V_199 ) ;
V_180 -> V_200 = F_28 ( sizeof( struct
V_56 ) ,
V_52 ) ;
if ( V_180 -> V_200 == NULL )
return V_146 ;
V_36 = F_98 ( V_149 ) ;
if ( V_36 == V_68 ) {
V_36 = F_99 ( V_149 ) ;
if ( V_36 != V_68 ) {
F_8 ( V_180 -> V_195 ) ;
F_90 ( & V_180 -> V_183 ) ;
}
}
return V_36 ;
}
static void
F_101 ( struct V_148 * V_149 )
{
struct V_179 * V_180 = & V_149 -> V_6 . V_7 ;
F_51 ( ! F_102 ( & V_149 -> V_150 ) ) ;
F_8 ( V_180 -> V_200 ) ;
V_180 -> V_200 = NULL ;
if ( V_149 -> V_14 & V_199 ) {
F_90 ( & V_180 -> V_183 ) ;
F_8 ( V_180 -> V_195 ) ;
F_90 ( & V_180 -> V_184 ) ;
F_8 ( V_180 -> V_198 ) ;
}
}
static void
F_103 ( struct V_148 * V_149 , unsigned long * V_12 )
{
struct V_107 V_70 ;
V_70 . V_109 = V_149 -> V_201 ;
V_70 . V_88 = V_149 -> V_88 ;
F_71 ( V_149 , V_12 , & V_70 , sizeof( V_70 ) ,
V_106 ) ;
}
static void
F_104 ( struct V_148 * V_149 , unsigned long * V_12 )
{
struct V_114 V_70 ;
V_70 . V_109 = V_149 -> V_201 ;
F_71 ( V_149 , V_12 , & V_70 , sizeof( V_70 ) ,
V_113 ) ;
}
static void
F_105 ( struct V_148 * V_149 , unsigned long * V_12 )
{
struct V_117 V_70 ;
V_70 . V_109 = V_149 -> V_201 ;
V_70 . V_118 = V_149 -> V_118 ;
V_70 . V_119 = V_149 -> V_119 ;
F_71 ( V_149 , V_12 , & V_70 , sizeof( V_70 ) ,
V_116 ) ;
}
static void
F_106 ( struct V_148 * V_149 , unsigned long * V_12 )
{
struct V_122 V_70 ;
V_70 . V_109 = V_149 -> V_201 ;
V_70 . V_119 = V_149 -> V_119 ;
V_70 . V_123 = V_149 -> V_123 ;
V_70 . V_125 = F_21 ( V_202 -> V_55 ) ;
F_71 ( V_149 , V_12 , & V_70 , sizeof( V_70 ) ,
V_121 ) ;
}
static void
F_107 ( struct V_148 * V_149 , unsigned long * V_12 )
{
struct V_128 V_70 ;
V_70 . V_109 = V_149 -> V_201 ;
F_71 ( V_149 , V_12 , & V_70 , sizeof( V_70 ) ,
V_127 ) ;
}
static void
F_108 ( struct V_77 * V_78 , int V_109 )
{
unsigned long V_12 ;
F_6 ( & V_78 -> V_110 , V_12 ) ;
V_78 -> V_111 . V_14 [ V_109 ] |= V_203 ;
F_7 ( & V_78 -> V_110 , V_12 ) ;
F_57 ( V_78 ) ;
}
static enum V_45
F_109 ( struct V_148 * V_149 ,
unsigned long V_139 )
{
struct V_179 * V_180 = & V_149 -> V_6 . V_7 ;
F_51 ( V_180 -> V_200 == NULL ) ;
return F_65 ( V_180 -> V_200 ,
V_139 ) ;
}
static void
F_110 ( struct V_77 * V_78 )
{
struct V_185 V_70 ;
F_69 ( V_78 , & V_70 , sizeof( V_70 ) ,
V_130 ) ;
}
static void
F_111 ( struct V_77 * V_78 )
{
struct V_185 V_70 ;
F_69 ( V_78 , & V_70 , sizeof( V_70 ) ,
V_132 ) ;
}
static void
F_112 ( short V_1 )
{
struct V_2 * V_3 = & V_5 [ V_1 ] . V_6 . V_7 ;
unsigned long V_12 ;
F_6 ( & V_3 -> V_9 , V_12 ) ;
V_3 -> V_14 &= ~ V_131 ;
F_7 ( & V_3 -> V_9 , V_12 ) ;
}
static int
F_113 ( short V_1 )
{
return ( V_5 [ V_1 ] . V_6 . V_7 . V_14 & V_131 ) != 0 ;
}
static int
F_114 ( void )
{
struct V_2 * V_3 ;
short V_1 ;
for ( V_1 = 0 ; V_1 < V_4 ; V_1 ++ ) {
V_3 = & V_5 [ V_1 ] . V_6 . V_7 ;
if ( ( V_3 -> V_14 & V_131 ) != 0 )
return 1 ;
}
return 0 ;
}
static enum V_45
F_115 ( struct V_148 * V_149 , T_7 V_14 ,
struct V_190 * * V_204 )
{
enum V_45 V_36 ;
struct V_190 * V_191 ;
struct V_177 * V_193 ;
while ( 1 ) {
V_193 = F_91 ( & V_149 -> V_6 . V_7 . V_183 ) ;
if ( V_193 != NULL )
break;
if ( V_14 & V_205 )
return V_206 ;
V_36 = F_116 ( V_149 ) ;
if ( V_36 != V_207 && V_36 != V_208 )
return V_36 ;
}
V_191 = F_56 ( V_193 , struct V_190 , V_178 ) ;
* V_204 = V_191 ;
return V_68 ;
}
static void
F_117 ( struct V_148 * V_149 ,
struct V_190 * V_191 )
{
F_92 ( & V_149 -> V_6 . V_7 . V_183 , & V_191 -> V_178 ) ;
if ( F_118 ( & V_149 -> V_209 ) > 0 )
F_119 ( & V_149 -> V_210 ) ;
}
static void
F_120 ( struct V_148 * V_149 ,
struct V_190 * V_191 ,
enum V_45 V_88 )
{
T_8 V_211 = V_191 -> V_211 ;
if ( V_211 != NULL && F_121 ( & V_191 -> V_211 , V_211 , NULL ) == V_211 ) {
F_122 ( & V_149 -> V_212 ) ;
F_48 ( V_74 , L_22
L_23 , V_191 ,
V_191 -> V_196 , V_149 -> V_1 , V_149 -> V_201 ) ;
V_211 ( V_88 , V_149 -> V_1 , V_149 -> V_201 , V_191 -> V_213 ) ;
F_48 ( V_74 , L_24
L_23 , V_191 ,
V_191 -> V_196 , V_149 -> V_1 , V_149 -> V_201 ) ;
}
}
static void
F_123 ( struct V_148 * V_149 ,
struct V_197 * V_70 )
{
struct V_190 * V_191 ;
int V_193 = V_70 -> V_97 . V_196 % V_149 -> V_119 ;
V_191 = & V_149 -> V_6 . V_7 . V_195 [ V_193 ] ;
F_25 ( V_191 -> V_196 != V_70 -> V_97 . V_196 ) ;
V_191 -> V_196 += V_149 -> V_119 ;
if ( V_191 -> V_211 != NULL )
F_120 ( V_149 , V_191 , V_214 ) ;
F_117 ( V_149 , V_191 ) ;
}
static void
F_124 ( struct V_77 * V_78 ,
struct V_197 * V_70 )
{
struct V_2 * V_3 = & V_78 -> V_6 . V_7 ;
struct V_148 * V_149 ;
struct V_179 * V_180 ;
struct V_197 * V_191 ;
unsigned long V_12 ;
int V_109 = V_70 -> V_97 . V_109 ;
if ( F_70 ( V_109 >= V_78 -> V_181 ) ) {
F_13 ( V_27 , L_25
L_26 ,
V_109 , F_58 ( V_78 ) ) ;
F_6 ( & V_81 , V_12 ) ;
if ( V_3 -> V_79 == 0 )
V_80 ++ ;
V_3 -> V_79 = V_87 ;
V_3 -> V_88 = V_215 ;
F_7 ( & V_81 , V_12 ) ;
F_64 ( & V_137 ) ;
return;
}
V_149 = & V_78 -> V_182 [ V_109 ] ;
F_125 ( V_149 ) ;
if ( ! ( V_149 -> V_14 & V_216 ) ) {
F_126 ( V_149 ) ;
return;
}
if ( V_70 -> V_97 . V_217 == 0 ) {
F_123 ( V_149 , V_70 ) ;
F_126 ( V_149 ) ;
return;
}
V_180 = & V_149 -> V_6 . V_7 ;
V_191 = V_180 -> V_198 +
( V_70 -> V_97 . V_196 % V_149 -> V_123 ) * V_149 -> V_118 ;
F_25 ( V_191 -> V_97 . V_217 != 0 ) ;
memcpy ( V_191 , V_70 , V_70 -> V_97 . V_217 ) ;
F_92 ( & V_180 -> V_184 , & V_191 -> V_97 . V_218 . V_178 ) ;
if ( V_149 -> V_14 & V_219 ) {
if ( F_118 ( & V_149 -> V_220 ) > 0 )
F_127 ( & V_149 -> V_221 , 1 ) ;
else
F_108 ( V_78 , V_149 -> V_201 ) ;
}
F_126 ( V_149 ) ;
}
static T_4
F_128 ( int V_24 , void * V_134 )
{
struct V_197 * V_70 ;
short V_1 ;
struct V_77 * V_78 ;
while ( ( V_70 = F_60 ( V_202 -> V_55 ) ) !=
NULL ) {
V_1 = V_70 -> V_97 . V_1 ;
if ( V_1 < 0 || V_1 >= V_4 ) {
F_13 ( V_27 , L_27
L_28 , V_1 ) ;
} else {
V_78 = & V_5 [ V_1 ] ;
if ( F_61 ( V_78 ) ) {
F_124 ( V_78 , V_70 ) ;
F_62 ( V_78 ) ;
}
}
F_63 ( V_202 -> V_55 , V_70 ) ;
}
return V_138 ;
}
static int
F_129 ( struct V_148 * V_149 )
{
return F_93 ( & V_149 -> V_6 . V_7 . V_184 ) ;
}
static void
F_130 ( struct V_77 * V_78 , int V_109 )
{
struct V_148 * V_149 = & V_78 -> V_182 [ V_109 ] ;
int V_222 ;
F_125 ( V_149 ) ;
V_222 = F_129 ( V_149 ) ;
if ( V_222 > 0 &&
( V_149 -> V_14 & V_216 ) &&
( V_149 -> V_14 & V_219 ) ) {
F_131 ( V_149 , V_222 ) ;
}
F_126 ( V_149 ) ;
}
static enum V_45
F_132 ( struct V_148 * V_149 , T_7 V_14 , void * V_223 ,
T_9 V_224 , T_3 V_225 , T_8 V_211 ,
void * V_213 )
{
enum V_45 V_36 = V_68 ;
struct V_190 * V_191 = NULL ;
struct V_197 * V_70 ;
T_3 V_226 [ V_227 ] ;
T_2 V_71 ;
F_51 ( V_225 != V_228 ) ;
V_71 = sizeof( struct V_229 ) + V_224 ;
if ( V_71 > V_149 -> V_118 )
return V_230 ;
F_125 ( V_149 ) ;
if ( V_149 -> V_14 & V_231 ) {
V_36 = V_149 -> V_88 ;
goto V_57;
}
if ( ! ( V_149 -> V_14 & V_216 ) ) {
V_36 = V_232 ;
goto V_57;
}
V_36 = F_115 ( V_149 , V_14 , & V_191 ) ;
if ( V_36 != V_68 )
goto V_57;
if ( V_211 != NULL ) {
F_133 ( & V_149 -> V_212 ) ;
V_191 -> V_213 = V_213 ;
F_134 () ;
V_191 -> V_211 = V_211 ;
if ( V_149 -> V_14 & V_231 ) {
V_36 = V_149 -> V_88 ;
goto V_61;
}
}
V_70 = (struct V_197 * ) & V_226 ;
V_70 -> V_97 . V_1 = V_142 ;
V_70 -> V_97 . V_109 = V_149 -> V_201 ;
V_70 -> V_97 . V_217 = V_71 ;
V_70 -> V_97 . V_196 = V_191 -> V_196 ;
memcpy ( & V_70 -> V_223 , V_223 , V_224 ) ;
V_36 = F_46 ( V_149 -> V_6 . V_7 . V_200 , V_70 ,
V_71 ) ;
if ( V_36 == V_68 )
goto V_57;
F_53 ( & V_5 [ V_149 -> V_1 ] , V_36 ) ;
V_61:
if ( V_211 != NULL ) {
if ( F_121 ( & V_191 -> V_211 , V_211 , NULL ) != V_211 ) {
V_36 = V_68 ;
goto V_57;
}
V_191 -> V_213 = NULL ;
F_122 ( & V_149 -> V_212 ) ;
}
F_117 ( V_149 , V_191 ) ;
V_57:
F_126 ( V_149 ) ;
return V_36 ;
}
static void
F_135 ( struct V_148 * V_149 )
{
struct V_190 * V_191 ;
int V_193 ;
F_51 ( ! ( V_149 -> V_14 & V_231 ) ) ;
for ( V_193 = 0 ; V_193 < V_149 -> V_119 ; V_193 ++ ) {
if ( F_118 ( & V_149 -> V_212 ) == 0 )
break;
V_191 = & V_149 -> V_6 . V_7 . V_195 [ V_193 ] ;
if ( V_191 -> V_211 != NULL )
F_120 ( V_149 , V_191 , V_149 -> V_88 ) ;
}
}
static void *
F_136 ( struct V_148 * V_149 )
{
struct V_177 * V_193 ;
struct V_197 * V_70 ;
void * V_223 = NULL ;
if ( ! ( V_149 -> V_14 & V_231 ) ) {
V_193 = F_91 ( & V_149 -> V_6 . V_7 . V_184 ) ;
if ( V_193 != NULL ) {
V_70 = F_56 ( V_193 , struct V_197 ,
V_97 . V_218 . V_178 ) ;
V_223 = & V_70 -> V_223 ;
}
}
return V_223 ;
}
static void
F_137 ( struct V_148 * V_149 , void * V_223 )
{
struct V_197 * V_70 ;
enum V_45 V_36 ;
V_70 = F_56 ( V_223 , struct V_197 , V_223 ) ;
V_70 -> V_97 . V_1 = V_142 ;
V_70 -> V_97 . V_217 = 0 ;
V_36 = F_46 ( V_149 -> V_6 . V_7 . V_200 , V_70 ,
sizeof( struct V_229 ) ) ;
if ( V_36 != V_68 )
F_53 ( & V_5 [ V_149 -> V_1 ] , V_36 ) ;
}
int
F_138 ( void )
{
V_233 = V_234 ;
if ( sizeof( struct V_229 ) > V_235 ) {
F_13 ( V_27 , L_29 ,
V_235 ) ;
return - V_236 ;
}
V_136 = F_27 ( V_237 , 0 ,
V_31 ,
F_59 ) ;
if ( F_139 ( V_136 ) )
return F_140 ( V_136 ) ;
V_202 = F_27 ( V_238 , 0 ,
V_33 ,
F_128 ) ;
if ( F_139 ( V_202 ) ) {
F_44 ( V_136 ) ;
return F_140 ( V_202 ) ;
}
return 0 ;
}
void
F_141 ( void )
{
F_44 ( V_202 ) ;
F_44 ( V_136 ) ;
}
