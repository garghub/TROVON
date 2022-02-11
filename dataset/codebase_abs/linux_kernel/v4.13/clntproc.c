void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( & V_1 ) ;
memcpy ( V_2 -> V_4 , & V_3 , 4 ) ;
V_2 -> V_5 = 4 ;
}
static struct V_6 * F_3 ( struct V_6 * V_7 )
{
F_4 ( & V_7 -> V_8 ) ;
return V_7 ;
}
static void F_5 ( struct V_6 * V_7 )
{
if ( ! F_6 ( & V_7 -> V_8 , & V_7 -> V_9 -> V_10 ) )
return;
F_7 ( & V_7 -> V_11 ) ;
F_8 ( & V_7 -> V_9 -> V_10 ) ;
F_9 ( V_7 -> V_9 ) ;
F_10 ( V_7 ) ;
}
static inline int F_11 ( struct V_12 * V_9 , T_2 V_13 )
{
struct V_6 * V_7 ;
F_12 (lockowner, &host->h_lockowners, list) {
if ( V_7 -> V_13 == V_13 )
return - V_14 ;
}
return 0 ;
}
static inline T_2 F_13 ( struct V_12 * V_9 )
{
T_2 V_15 ;
do {
V_15 = V_9 -> V_16 ++ ;
} while ( F_11 ( V_9 , V_15 ) < 0 );
return V_15 ;
}
static struct V_6 * F_14 ( struct V_12 * V_9 , T_3 V_17 )
{
struct V_6 * V_7 ;
F_12 (lockowner, &host->h_lockowners, list) {
if ( V_7 -> V_17 != V_17 )
continue;
return F_3 ( V_7 ) ;
}
return NULL ;
}
static struct V_6 * F_15 ( struct V_12 * V_9 , T_3 V_17 )
{
struct V_6 * V_15 , * V_18 = NULL ;
F_16 ( & V_9 -> V_10 ) ;
V_15 = F_14 ( V_9 , V_17 ) ;
if ( V_15 == NULL ) {
F_8 ( & V_9 -> V_10 ) ;
V_18 = F_17 ( sizeof( * V_18 ) , V_19 ) ;
F_16 ( & V_9 -> V_10 ) ;
V_15 = F_14 ( V_9 , V_17 ) ;
if ( V_15 == NULL && V_18 != NULL ) {
V_15 = V_18 ;
F_18 ( & V_18 -> V_8 , 1 ) ;
V_18 -> V_17 = V_17 ;
V_18 -> V_13 = F_13 ( V_9 ) ;
V_18 -> V_9 = F_19 ( V_9 ) ;
F_20 ( & V_18 -> V_11 , & V_9 -> V_20 ) ;
V_18 = NULL ;
}
}
F_8 ( & V_9 -> V_10 ) ;
F_10 ( V_18 ) ;
return V_15 ;
}
static void F_21 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_28 * V_29 = & V_26 -> V_29 ;
char * V_30 = V_22 -> V_31 -> V_32 -> V_33 ;
F_1 ( & V_26 -> V_3 ) ;
memcpy ( & V_29 -> V_34 , F_22 ( F_23 ( V_24 -> V_35 ) ) , sizeof( struct V_36 ) ) ;
V_29 -> V_37 = V_30 ;
V_29 -> V_38 . V_4 = V_22 -> V_39 ;
V_29 -> V_38 . V_5 = snprintf ( V_22 -> V_39 , sizeof( V_22 -> V_39 ) , L_1 ,
( unsigned int ) V_24 -> V_40 . V_41 . V_17 -> V_13 ,
V_30 ) ;
V_29 -> V_42 = V_24 -> V_40 . V_41 . V_17 -> V_13 ;
V_29 -> V_24 . V_43 = V_24 -> V_43 ;
V_29 -> V_24 . V_44 = V_24 -> V_44 ;
V_29 -> V_24 . V_45 = V_24 -> V_45 ;
}
static void F_24 ( struct V_21 * V_22 )
{
F_25 ( V_22 -> V_27 . V_29 . V_24 . V_46 != NULL ) ;
}
int F_26 ( struct V_12 * V_9 , int V_47 , struct V_23 * V_24 , void * V_4 )
{
struct V_21 * V_48 ;
int V_49 ;
const struct V_50 * V_51 = V_9 -> V_52 ;
V_48 = F_27 ( V_9 ) ;
if ( V_48 == NULL )
return - V_53 ;
if ( V_51 && V_51 -> V_54 )
V_51 -> V_54 ( V_4 ) ;
F_28 ( V_24 , V_9 ) ;
if ( ! V_24 -> V_40 . V_41 . V_17 ) {
F_29 ( V_48 ) ;
return - V_53 ;
}
F_21 ( V_48 , V_24 ) ;
V_48 -> V_55 = V_4 ;
if ( F_30 ( V_47 ) || F_31 ( V_47 ) ) {
if ( V_24 -> V_45 != V_56 ) {
V_48 -> V_27 . V_57 = F_31 ( V_47 ) ? 1 : 0 ;
V_49 = F_32 ( V_48 , V_24 ) ;
} else
V_49 = F_33 ( V_48 , V_24 ) ;
} else if ( F_34 ( V_47 ) )
V_49 = F_35 ( V_48 , V_24 ) ;
else
V_49 = - V_58 ;
V_24 -> V_46 -> V_59 ( V_24 ) ;
V_24 -> V_46 = NULL ;
F_36 ( L_2 , V_49 ) ;
return V_49 ;
}
struct V_21 * F_27 ( struct V_12 * V_9 )
{
struct V_21 * V_48 ;
for(; ; ) {
V_48 = F_37 ( sizeof( * V_48 ) , V_19 ) ;
if ( V_48 != NULL ) {
F_18 ( & V_48 -> V_60 , 1 ) ;
F_38 ( & V_48 -> V_27 . V_29 . V_24 ) ;
F_38 ( & V_48 -> V_61 . V_29 . V_24 ) ;
V_48 -> V_31 = F_19 ( V_9 ) ;
return V_48 ;
}
if ( F_39 () )
break;
F_40 ( L_3 ) ;
F_41 ( 5 * V_62 ) ;
}
return NULL ;
}
void F_29 ( struct V_21 * V_48 )
{
const struct V_50 * V_51 = V_48 -> V_31 -> V_52 ;
if ( ! F_42 ( & V_48 -> V_60 ) )
return;
if ( V_51 && V_51 -> F_29 )
V_51 -> F_29 ( V_48 -> V_55 ) ;
F_9 ( V_48 -> V_31 ) ;
F_24 ( V_48 ) ;
F_10 ( V_48 ) ;
}
static void F_43 ( void * V_4 )
{
F_29 ( V_4 ) ;
}
static int F_44 ( T_4 * V_63 )
{
F_45 ( V_64 ) ;
int V_49 = - V_65 ;
F_46 ( V_63 , & V_64 , V_66 ) ;
if ( ! F_39 () ) {
F_47 ( V_67 ) ;
F_48 () ;
if ( ! F_39 () )
V_49 = 0 ;
}
F_49 ( V_63 , & V_64 ) ;
return V_49 ;
}
static int
F_50 ( struct V_68 * V_69 , struct V_21 * V_22 , T_1 V_70 )
{
struct V_12 * V_9 = V_22 -> V_31 ;
struct V_71 * V_72 ;
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_73 * V_74 = & V_22 -> V_61 ;
struct V_75 V_76 = {
. V_77 = V_26 ,
. V_78 = V_74 ,
. V_68 = V_69 ,
} ;
int V_49 ;
F_36 ( L_4 ,
( int ) V_70 , V_9 -> V_79 ) ;
do {
if ( V_9 -> V_80 && ! V_26 -> V_81 )
goto V_82;
if ( ( V_72 = F_51 ( V_9 ) ) == NULL )
return - V_83 ;
V_76 . V_84 = & V_72 -> V_85 [ V_70 ] ;
if ( ( V_49 = F_52 ( V_72 , & V_76 , 0 ) ) < 0 ) {
F_36 ( L_5 , - V_49 ) ;
switch ( V_49 ) {
case - V_86 :
V_49 = - V_58 ;
break;
case - V_87 :
case - V_88 :
case - V_89 :
F_53 ( V_9 ) ;
V_49 = - V_90 ;
break;
case - V_91 :
return F_39 () ? - V_65 : V_49 ;
default:
break;
}
break;
} else
if ( V_74 -> V_49 == V_92 ) {
F_36 ( L_6 ) ;
if ( V_26 -> V_81 ) {
F_40 ( V_93
L_7 ) ;
return - V_83 ;
}
} else {
if ( ! V_26 -> V_81 ) {
F_54 ( & V_9 -> V_94 ) ;
}
F_36 ( L_8 ,
F_55 ( V_74 -> V_49 ) ) ;
return 0 ;
}
V_82:
V_49 = F_44 ( & V_9 -> V_94 ) ;
} while ( V_49 == 0 );
return V_49 ;
}
static struct V_95 * F_56 ( struct V_21 * V_22 , T_1 V_70 , struct V_75 * V_76 , const struct V_96 * V_97 )
{
struct V_12 * V_9 = V_22 -> V_31 ;
struct V_71 * V_72 ;
struct V_98 V_99 = {
. V_75 = V_76 ,
. V_100 = V_97 ,
. V_101 = V_22 ,
. V_102 = V_103 ,
} ;
F_36 ( L_9 ,
( int ) V_70 , V_9 -> V_79 ) ;
V_72 = F_51 ( V_9 ) ;
if ( V_72 == NULL )
goto V_104;
V_76 -> V_84 = & V_72 -> V_85 [ V_70 ] ;
V_99 . V_105 = V_72 ;
return F_57 ( & V_99 ) ;
V_104:
V_97 -> V_106 ( V_22 ) ;
return F_58 ( - V_83 ) ;
}
static int F_59 ( struct V_21 * V_22 , T_1 V_70 , struct V_75 * V_76 , const struct V_96 * V_97 )
{
struct V_95 * V_107 ;
V_107 = F_56 ( V_22 , V_70 , V_76 , V_97 ) ;
if ( F_60 ( V_107 ) )
return F_61 ( V_107 ) ;
F_62 ( V_107 ) ;
return 0 ;
}
int F_63 ( struct V_21 * V_22 , T_1 V_70 , const struct V_96 * V_97 )
{
struct V_75 V_76 = {
. V_77 = & V_22 -> V_27 ,
. V_78 = & V_22 -> V_61 ,
} ;
return F_59 ( V_22 , V_70 , & V_76 , V_97 ) ;
}
int F_64 ( struct V_21 * V_22 , T_1 V_70 , const struct V_96 * V_97 )
{
struct V_75 V_76 = {
. V_77 = & V_22 -> V_61 ,
} ;
return F_59 ( V_22 , V_70 , & V_76 , V_97 ) ;
}
static int F_65 ( struct V_68 * V_69 , struct V_21 * V_22 , T_1 V_70 , const struct V_96 * V_97 )
{
struct V_75 V_76 = {
. V_77 = & V_22 -> V_27 ,
. V_78 = & V_22 -> V_61 ,
. V_68 = V_69 ,
} ;
struct V_95 * V_107 ;
int V_108 ;
V_107 = F_56 ( V_22 , V_70 , & V_76 , V_97 ) ;
if ( F_60 ( V_107 ) )
return F_61 ( V_107 ) ;
V_108 = F_66 ( V_107 ) ;
F_62 ( V_107 ) ;
return V_108 ;
}
static int
F_35 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
int V_49 ;
V_49 = F_50 ( F_67 ( V_24 -> V_35 ) , V_22 , V_109 ) ;
if ( V_49 < 0 )
goto V_110;
switch ( V_22 -> V_61 . V_49 ) {
case V_111 :
V_24 -> V_45 = V_56 ;
break;
case V_112 :
V_24 -> V_43 = V_22 -> V_61 . V_29 . V_24 . V_43 ;
V_24 -> V_44 = V_22 -> V_61 . V_29 . V_24 . V_44 ;
V_24 -> V_45 = V_22 -> V_61 . V_29 . V_24 . V_45 ;
V_24 -> V_113 = 0 ;
break;
default:
V_49 = F_68 ( V_22 -> V_61 . V_49 ) ;
}
V_110:
F_29 ( V_22 ) ;
return V_49 ;
}
static void F_69 ( struct V_23 * V_18 , struct V_23 * V_24 )
{
F_16 ( & V_24 -> V_40 . V_41 . V_17 -> V_9 -> V_10 ) ;
V_18 -> V_40 . V_41 . V_114 = V_24 -> V_40 . V_41 . V_114 ;
V_18 -> V_40 . V_41 . V_17 = F_3 ( V_24 -> V_40 . V_41 . V_17 ) ;
F_70 ( & V_18 -> V_40 . V_41 . V_11 , & V_24 -> V_40 . V_41 . V_17 -> V_9 -> V_115 ) ;
F_8 ( & V_24 -> V_40 . V_41 . V_17 -> V_9 -> V_10 ) ;
}
static void F_71 ( struct V_23 * V_24 )
{
F_16 ( & V_24 -> V_40 . V_41 . V_17 -> V_9 -> V_10 ) ;
F_7 ( & V_24 -> V_40 . V_41 . V_11 ) ;
F_8 ( & V_24 -> V_40 . V_41 . V_17 -> V_9 -> V_10 ) ;
F_5 ( V_24 -> V_40 . V_41 . V_17 ) ;
}
static void F_28 ( struct V_23 * V_24 , struct V_12 * V_9 )
{
V_24 -> V_40 . V_41 . V_114 = 0 ;
V_24 -> V_40 . V_41 . V_17 = F_15 ( V_9 , V_24 -> V_116 ) ;
F_72 ( & V_24 -> V_40 . V_41 . V_11 ) ;
V_24 -> V_46 = & V_117 ;
}
static int F_73 ( struct V_23 * V_24 )
{
return F_74 ( V_24 -> V_35 , V_24 ) ;
}
static int
F_32 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_68 * V_69 = F_67 ( V_24 -> V_35 ) ;
struct V_12 * V_9 = V_22 -> V_31 ;
struct V_73 * V_74 = & V_22 -> V_61 ;
struct V_118 * V_57 = NULL ;
unsigned char V_119 = V_24 -> V_119 ;
unsigned char V_45 ;
int V_49 = - V_83 ;
if ( F_75 ( V_9 ) < 0 )
goto V_110;
V_22 -> V_27 . V_114 = V_120 ;
V_24 -> V_119 |= V_121 ;
V_49 = F_73 ( V_24 ) ;
V_24 -> V_119 = V_119 ;
if ( V_49 < 0 )
goto V_110;
V_57 = F_76 ( V_9 , V_24 ) ;
V_122:
V_74 -> V_49 = V_123 ;
for(; ; ) {
V_24 -> V_40 . V_41 . V_114 = V_9 -> V_124 ;
V_49 = F_50 ( V_69 , V_22 , V_125 ) ;
if ( V_49 < 0 )
break;
if ( V_74 -> V_49 == V_92 )
continue;
if ( V_74 -> V_49 != V_123 )
break;
V_49 = F_77 ( V_57 , V_22 , V_126 ) ;
if ( V_49 < 0 )
break;
if ( V_74 -> V_49 != V_123 )
break;
}
if ( V_74 -> V_49 == V_123 ) {
if ( ! V_22 -> V_27 . V_57 )
goto V_127;
if ( F_78 ( V_9 , V_22 -> V_27 . V_57 , V_24 ) == 0 )
goto V_128;
}
if ( V_74 -> V_49 == V_111 ) {
F_79 ( & V_9 -> V_129 ) ;
if ( V_24 -> V_40 . V_41 . V_114 != V_9 -> V_124 ) {
F_80 ( & V_9 -> V_129 ) ;
goto V_122;
}
V_24 -> V_119 |= V_130 ;
if ( F_73 ( V_24 ) < 0 )
F_40 ( V_93 L_10 , V_131 ) ;
F_80 ( & V_9 -> V_129 ) ;
V_24 -> V_119 = V_119 ;
V_49 = 0 ;
}
if ( V_49 < 0 )
goto V_127;
if ( V_74 -> V_49 == V_112 && ( V_119 & V_130 ) )
V_49 = - V_83 ;
else
V_49 = F_68 ( V_74 -> V_49 ) ;
V_128:
F_81 ( V_57 ) ;
V_110:
F_29 ( V_22 ) ;
return V_49 ;
V_127:
F_36 ( L_11
L_12 ) ;
F_81 ( V_57 ) ;
V_45 = V_24 -> V_45 ;
V_24 -> V_45 = V_56 ;
F_79 ( & V_9 -> V_129 ) ;
F_73 ( V_24 ) ;
F_80 ( & V_9 -> V_129 ) ;
V_24 -> V_45 = V_45 ;
V_24 -> V_119 = V_119 ;
F_65 ( V_69 , V_22 , V_132 , & V_133 ) ;
return V_49 ;
}
int
F_82 ( struct V_12 * V_9 , struct V_23 * V_24 ,
struct V_21 * V_22 )
{
int V_49 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
F_38 ( & V_22 -> V_27 . V_29 . V_24 ) ;
F_38 ( & V_22 -> V_61 . V_29 . V_24 ) ;
V_22 -> V_31 = V_9 ;
F_21 ( V_22 , V_24 ) ;
V_22 -> V_27 . V_81 = 1 ;
V_49 = F_50 ( F_67 ( V_24 -> V_35 ) , V_22 , V_125 ) ;
if ( V_49 >= 0 && V_22 -> V_61 . V_49 == V_111 )
return 0 ;
F_40 ( V_93 L_13
L_14 , V_24 -> V_113 ,
V_49 , F_55 ( V_22 -> V_61 . V_49 ) ) ;
return - V_83 ;
}
static int
F_33 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_12 * V_9 = V_22 -> V_31 ;
struct V_73 * V_74 = & V_22 -> V_61 ;
int V_49 ;
unsigned char V_119 = V_24 -> V_119 ;
V_24 -> V_119 |= V_134 ;
F_79 ( & V_9 -> V_129 ) ;
V_49 = F_73 ( V_24 ) ;
F_80 ( & V_9 -> V_129 ) ;
V_24 -> V_119 = V_119 ;
if ( V_49 == - V_135 ) {
V_49 = 0 ;
goto V_110;
}
F_4 ( & V_22 -> V_60 ) ;
V_49 = F_65 ( F_67 ( V_24 -> V_35 ) , V_22 ,
V_132 , & V_133 ) ;
if ( V_49 < 0 )
goto V_110;
if ( V_74 -> V_49 == V_111 )
goto V_110;
if ( V_74 -> V_49 != V_136 )
F_40 ( L_15 ,
F_55 ( V_74 -> V_49 ) ) ;
V_49 = - V_83 ;
V_110:
F_29 ( V_22 ) ;
return V_49 ;
}
static void F_83 ( struct V_95 * V_107 , void * V_4 )
{
struct V_21 * V_22 = V_4 ;
const struct V_50 * V_51 = V_22 -> V_31 -> V_52 ;
bool V_137 = false ;
if ( V_51 && V_51 -> F_83 )
V_137 = V_51 -> F_83 ( V_107 , V_22 -> V_55 ) ;
if ( ! V_137 )
F_84 ( V_107 ) ;
}
static void F_85 ( struct V_95 * V_107 , void * V_4 )
{
struct V_21 * V_22 = V_4 ;
T_1 V_49 = F_55 ( V_22 -> V_61 . V_49 ) ;
if ( F_86 ( V_107 ) )
goto V_138;
if ( V_107 -> V_139 < 0 ) {
F_36 ( L_16 , - V_107 -> V_139 ) ;
switch ( V_107 -> V_139 ) {
case - V_140 :
case - V_141 :
goto V_138;
default:
goto V_142;
}
}
if ( V_49 == V_143 ) {
F_87 ( V_107 , V_67 ) ;
goto V_144;
}
if ( V_49 != V_145 )
F_40 ( V_93 L_15 , V_49 ) ;
V_138:
return;
V_142:
F_53 ( V_22 -> V_31 ) ;
V_144:
F_88 ( V_107 ) ;
}
static int F_78 ( struct V_12 * V_9 , int V_57 , struct V_23 * V_24 )
{
struct V_21 * V_22 ;
int V_49 ;
F_36 ( L_17
L_18 ) ;
V_22 = F_27 ( V_9 ) ;
if ( ! V_22 )
return - V_53 ;
V_22 -> V_146 = V_103 ;
F_21 ( V_22 , V_24 ) ;
V_22 -> V_27 . V_57 = V_57 ;
F_4 ( & V_22 -> V_60 ) ;
V_49 = F_65 ( F_67 ( V_24 -> V_35 ) , V_22 ,
V_147 , & V_148 ) ;
if ( V_49 == 0 && V_22 -> V_61 . V_49 == V_112 )
V_49 = - V_83 ;
F_29 ( V_22 ) ;
return V_49 ;
}
static void F_89 ( struct V_95 * V_107 , void * V_4 )
{
struct V_21 * V_22 = V_4 ;
T_1 V_49 = F_55 ( V_22 -> V_61 . V_49 ) ;
if ( F_86 ( V_107 ) )
goto V_138;
if ( V_107 -> V_139 < 0 ) {
F_36 ( L_19 ,
V_107 -> V_139 ) ;
goto V_149;
}
F_36 ( L_20 ,
V_49 , V_107 -> V_150 ) ;
switch ( V_49 ) {
case V_145 :
case V_143 :
case V_151 :
break;
case V_152 :
F_36 ( L_21 ) ;
goto V_149;
default:
F_40 ( V_153 L_22 ,
V_49 ) ;
}
V_138:
return;
V_149:
if ( V_22 -> V_154 ++ >= V_155 )
goto V_138;
F_53 ( V_22 -> V_31 ) ;
F_88 ( V_107 ) ;
F_87 ( V_107 , 30 * V_62 ) ;
}
static int
F_68 ( T_5 V_49 )
{
switch( F_55 ( V_49 ) ) {
case V_145 :
return 0 ;
case V_151 :
return - V_90 ;
case V_152 :
case V_143 :
return - V_83 ;
case V_156 :
F_40 ( V_153 L_23 ) ;
return - V_83 ;
#ifdef F_90
case V_157 :
return - V_158 ;
case V_159 :
return - V_160 ;
case V_161 :
return - V_162 ;
case V_163 :
return - V_164 ;
case V_165 :
return - V_83 ;
#endif
}
F_40 ( V_153 L_24 ,
F_55 ( V_49 ) ) ;
return - V_83 ;
}
