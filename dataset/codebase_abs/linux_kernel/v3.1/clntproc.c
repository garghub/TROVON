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
F_1 ( & V_26 -> V_3 ) ;
memcpy ( & V_29 -> V_30 , F_22 ( V_24 -> V_31 -> V_32 . V_33 -> V_34 ) , sizeof( struct V_35 ) ) ;
V_29 -> V_36 = F_23 () -> V_37 ;
V_29 -> V_38 . V_4 = V_22 -> V_39 ;
V_29 -> V_38 . V_5 = snprintf ( V_22 -> V_39 , sizeof( V_22 -> V_39 ) , L_1 ,
( unsigned int ) V_24 -> V_40 . V_41 . V_17 -> V_13 ,
F_23 () -> V_37 ) ;
V_29 -> V_42 = V_24 -> V_40 . V_41 . V_17 -> V_13 ;
V_29 -> V_24 . V_43 = V_24 -> V_43 ;
V_29 -> V_24 . V_44 = V_24 -> V_44 ;
V_29 -> V_24 . V_45 = V_24 -> V_45 ;
}
static void F_24 ( struct V_21 * V_22 )
{
F_25 ( V_22 -> V_27 . V_29 . V_24 . V_46 != NULL ) ;
}
int F_26 ( struct V_12 * V_9 , int V_47 , struct V_23 * V_24 )
{
struct V_21 * V_48 ;
int V_49 ;
F_19 ( V_9 ) ;
V_48 = F_27 ( V_9 ) ;
if ( V_48 == NULL )
return - V_50 ;
F_28 ( V_24 , V_9 ) ;
F_21 ( V_48 , V_24 ) ;
if ( F_29 ( V_47 ) || F_30 ( V_47 ) ) {
if ( V_24 -> V_45 != V_51 ) {
V_48 -> V_27 . V_52 = F_30 ( V_47 ) ? 1 : 0 ;
V_49 = F_31 ( V_48 , V_24 ) ;
} else
V_49 = F_32 ( V_48 , V_24 ) ;
} else if ( F_33 ( V_47 ) )
V_49 = F_34 ( V_48 , V_24 ) ;
else
V_49 = - V_53 ;
V_24 -> V_46 -> V_54 ( V_24 ) ;
V_24 -> V_46 = NULL ;
F_35 ( L_2 , V_49 ) ;
return V_49 ;
}
struct V_21 * F_27 ( struct V_12 * V_9 )
{
struct V_21 * V_48 ;
for(; ; ) {
V_48 = F_36 ( sizeof( * V_48 ) , V_19 ) ;
if ( V_48 != NULL ) {
F_18 ( & V_48 -> V_55 , 1 ) ;
F_37 ( & V_48 -> V_27 . V_29 . V_24 ) ;
F_37 ( & V_48 -> V_56 . V_29 . V_24 ) ;
V_48 -> V_57 = V_9 ;
return V_48 ;
}
if ( F_38 () )
break;
F_39 ( L_3 ) ;
F_40 ( 5 * V_58 ) ;
}
F_9 ( V_9 ) ;
return NULL ;
}
void F_41 ( struct V_21 * V_48 )
{
if ( ! F_42 ( & V_48 -> V_55 ) )
return;
F_9 ( V_48 -> V_57 ) ;
F_24 ( V_48 ) ;
F_10 ( V_48 ) ;
}
static void F_43 ( void * V_4 )
{
F_41 ( V_4 ) ;
}
static int F_44 ( T_4 * V_59 )
{
F_45 ( V_60 ) ;
int V_49 = - V_61 ;
F_46 ( V_59 , & V_60 , V_62 ) ;
if ( ! F_38 () ) {
F_47 ( V_63 ) ;
F_48 () ;
if ( ! F_38 () )
V_49 = 0 ;
}
F_49 ( V_59 , & V_60 ) ;
return V_49 ;
}
static int
F_50 ( struct V_64 * V_65 , struct V_21 * V_22 , T_1 V_66 )
{
struct V_12 * V_9 = V_22 -> V_57 ;
struct V_67 * V_68 ;
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_69 * V_70 = & V_22 -> V_56 ;
struct V_71 V_72 = {
. V_73 = V_26 ,
. V_74 = V_70 ,
. V_64 = V_65 ,
} ;
int V_49 ;
F_35 ( L_4 ,
( int ) V_66 , V_9 -> V_75 ) ;
do {
if ( V_9 -> V_76 && ! V_26 -> V_77 )
goto V_78;
if ( ( V_68 = F_51 ( V_9 ) ) == NULL )
return - V_79 ;
V_72 . V_80 = & V_68 -> V_81 [ V_66 ] ;
if ( ( V_49 = F_52 ( V_68 , & V_72 , 0 ) ) < 0 ) {
F_35 ( L_5 , - V_49 ) ;
switch ( V_49 ) {
case - V_82 :
V_49 = - V_53 ;
break;
case - V_83 :
case - V_84 :
case - V_85 :
F_53 ( V_9 ) ;
V_49 = - V_86 ;
break;
case - V_87 :
return F_38 () ? - V_61 : V_49 ;
default:
break;
}
break;
} else
if ( V_70 -> V_49 == V_88 ) {
F_35 ( L_6 ) ;
if ( V_26 -> V_77 ) {
F_39 ( V_89
L_7 ) ;
return - V_79 ;
}
} else {
if ( ! V_26 -> V_77 ) {
F_54 ( & V_9 -> V_90 ) ;
}
F_35 ( L_8 ,
F_55 ( V_70 -> V_49 ) ) ;
return 0 ;
}
V_78:
V_49 = F_44 ( & V_9 -> V_90 ) ;
} while ( V_49 == 0 );
return V_49 ;
}
static struct V_91 * F_56 ( struct V_21 * V_22 , T_1 V_66 , struct V_71 * V_72 , const struct V_92 * V_93 )
{
struct V_12 * V_9 = V_22 -> V_57 ;
struct V_67 * V_68 ;
struct V_94 V_95 = {
. V_71 = V_72 ,
. V_96 = V_93 ,
. V_97 = V_22 ,
. V_98 = V_99 ,
} ;
F_35 ( L_9 ,
( int ) V_66 , V_9 -> V_75 ) ;
V_68 = F_51 ( V_9 ) ;
if ( V_68 == NULL )
goto V_100;
V_72 -> V_80 = & V_68 -> V_81 [ V_66 ] ;
V_95 . V_101 = V_68 ;
return F_57 ( & V_95 ) ;
V_100:
V_93 -> V_102 ( V_22 ) ;
return F_58 ( - V_79 ) ;
}
static int F_59 ( struct V_21 * V_22 , T_1 V_66 , struct V_71 * V_72 , const struct V_92 * V_93 )
{
struct V_91 * V_103 ;
V_103 = F_56 ( V_22 , V_66 , V_72 , V_93 ) ;
if ( F_60 ( V_103 ) )
return F_61 ( V_103 ) ;
F_62 ( V_103 ) ;
return 0 ;
}
int F_63 ( struct V_21 * V_22 , T_1 V_66 , const struct V_92 * V_93 )
{
struct V_71 V_72 = {
. V_73 = & V_22 -> V_27 ,
. V_74 = & V_22 -> V_56 ,
} ;
return F_59 ( V_22 , V_66 , & V_72 , V_93 ) ;
}
int F_64 ( struct V_21 * V_22 , T_1 V_66 , const struct V_92 * V_93 )
{
struct V_71 V_72 = {
. V_73 = & V_22 -> V_56 ,
} ;
return F_59 ( V_22 , V_66 , & V_72 , V_93 ) ;
}
static int F_65 ( struct V_64 * V_65 , struct V_21 * V_22 , T_1 V_66 , const struct V_92 * V_93 )
{
struct V_71 V_72 = {
. V_73 = & V_22 -> V_27 ,
. V_74 = & V_22 -> V_56 ,
. V_64 = V_65 ,
} ;
struct V_91 * V_103 ;
int V_104 ;
V_103 = F_56 ( V_22 , V_66 , & V_72 , V_93 ) ;
if ( F_60 ( V_103 ) )
return F_61 ( V_103 ) ;
V_104 = F_66 ( V_103 ) ;
F_62 ( V_103 ) ;
return V_104 ;
}
static int
F_34 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
int V_49 ;
V_49 = F_50 ( F_67 ( V_24 -> V_31 ) , V_22 , V_105 ) ;
if ( V_49 < 0 )
goto V_106;
switch ( V_22 -> V_56 . V_49 ) {
case V_107 :
V_24 -> V_45 = V_51 ;
break;
case V_108 :
V_24 -> V_43 = V_22 -> V_56 . V_29 . V_24 . V_43 ;
V_24 -> V_44 = V_22 -> V_56 . V_29 . V_24 . V_44 ;
V_24 -> V_45 = V_22 -> V_56 . V_29 . V_24 . V_45 ;
V_24 -> V_109 = 0 ;
break;
default:
V_49 = F_68 ( V_22 -> V_56 . V_49 ) ;
}
V_106:
F_41 ( V_22 ) ;
return V_49 ;
}
static void F_69 ( struct V_23 * V_18 , struct V_23 * V_24 )
{
F_16 ( & V_24 -> V_40 . V_41 . V_17 -> V_9 -> V_10 ) ;
V_18 -> V_40 . V_41 . V_110 = V_24 -> V_40 . V_41 . V_110 ;
V_18 -> V_40 . V_41 . V_17 = F_3 ( V_24 -> V_40 . V_41 . V_17 ) ;
F_70 ( & V_18 -> V_40 . V_41 . V_11 , & V_24 -> V_40 . V_41 . V_17 -> V_9 -> V_111 ) ;
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
F_25 ( V_24 -> V_46 != NULL ) ;
V_24 -> V_40 . V_41 . V_110 = 0 ;
V_24 -> V_40 . V_41 . V_17 = F_15 ( V_9 , V_24 -> V_112 ) ;
F_72 ( & V_24 -> V_40 . V_41 . V_11 ) ;
V_24 -> V_46 = & V_113 ;
}
static int F_73 ( struct V_23 * V_24 )
{
int V_15 = 0 ;
switch ( V_24 -> V_114 & ( V_115 | V_116 ) ) {
case V_115 :
V_15 = F_74 ( V_24 -> V_31 , V_24 ) ;
break;
case V_116 :
V_15 = F_75 ( V_24 -> V_31 , V_24 ) ;
break;
default:
F_76 () ;
}
return V_15 ;
}
static int
F_31 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_64 * V_65 = F_67 ( V_24 -> V_31 ) ;
struct V_12 * V_9 = V_22 -> V_57 ;
struct V_69 * V_70 = & V_22 -> V_56 ;
struct V_117 * V_52 = NULL ;
unsigned char V_114 = V_24 -> V_114 ;
unsigned char V_45 ;
int V_49 = - V_79 ;
if ( F_77 ( V_9 ) < 0 )
goto V_106;
V_22 -> V_27 . V_110 = V_118 ;
V_24 -> V_114 |= V_119 ;
V_49 = F_73 ( V_24 ) ;
V_24 -> V_114 = V_114 ;
if ( V_49 < 0 )
goto V_106;
V_52 = F_78 ( V_9 , V_24 ) ;
V_120:
V_70 -> V_49 = V_121 ;
for(; ; ) {
V_24 -> V_40 . V_41 . V_110 = V_9 -> V_122 ;
V_49 = F_50 ( V_65 , V_22 , V_123 ) ;
if ( V_49 < 0 )
break;
if ( V_70 -> V_49 == V_88 )
continue;
if ( V_70 -> V_49 != V_121 )
break;
V_49 = F_79 ( V_52 , V_22 , V_124 ) ;
if ( V_49 < 0 )
break;
if ( V_70 -> V_49 != V_121 )
break;
}
if ( V_70 -> V_49 == V_121 ) {
if ( ! V_22 -> V_27 . V_52 )
goto V_125;
if ( F_80 ( V_9 , V_22 -> V_27 . V_52 , V_24 ) == 0 )
goto V_126;
}
if ( V_70 -> V_49 == V_107 ) {
F_81 ( & V_9 -> V_127 ) ;
if ( V_24 -> V_40 . V_41 . V_110 != V_9 -> V_122 ) {
F_82 ( & V_9 -> V_127 ) ;
goto V_120;
}
V_24 -> V_114 |= V_128 ;
if ( F_73 ( V_24 ) < 0 )
F_39 ( V_89 L_10 , V_129 ) ;
F_82 ( & V_9 -> V_127 ) ;
V_24 -> V_114 = V_114 ;
V_49 = 0 ;
}
if ( V_49 < 0 )
goto V_125;
if ( V_70 -> V_49 == V_108 && ( V_114 & V_128 ) )
V_49 = - V_79 ;
else
V_49 = F_68 ( V_70 -> V_49 ) ;
V_126:
F_83 ( V_52 ) ;
V_106:
F_41 ( V_22 ) ;
return V_49 ;
V_125:
F_35 ( L_11
L_12 ) ;
F_83 ( V_52 ) ;
V_45 = V_24 -> V_45 ;
V_24 -> V_45 = V_51 ;
F_81 ( & V_9 -> V_127 ) ;
F_73 ( V_24 ) ;
F_82 ( & V_9 -> V_127 ) ;
V_24 -> V_45 = V_45 ;
V_24 -> V_114 = V_114 ;
F_65 ( V_65 , V_22 , V_130 , & V_131 ) ;
return V_49 ;
}
int
F_84 ( struct V_12 * V_9 , struct V_23 * V_24 )
{
struct V_21 V_132 , * V_22 ;
int V_49 ;
V_22 = & V_132 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
F_37 ( & V_22 -> V_27 . V_29 . V_24 ) ;
F_37 ( & V_22 -> V_56 . V_29 . V_24 ) ;
V_22 -> V_57 = V_9 ;
V_22 -> V_133 = 0 ;
F_21 ( V_22 , V_24 ) ;
V_22 -> V_27 . V_77 = 1 ;
V_49 = F_50 ( F_67 ( V_24 -> V_31 ) , V_22 , V_123 ) ;
if ( V_49 >= 0 && V_22 -> V_56 . V_49 == V_107 )
return 0 ;
F_39 ( V_89 L_13
L_14 , V_24 -> V_109 ,
V_49 , F_55 ( V_22 -> V_56 . V_49 ) ) ;
return - V_79 ;
}
static int
F_32 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_12 * V_9 = V_22 -> V_57 ;
struct V_69 * V_70 = & V_22 -> V_56 ;
int V_49 ;
unsigned char V_114 = V_24 -> V_114 ;
V_24 -> V_114 |= V_134 ;
F_81 ( & V_9 -> V_127 ) ;
V_49 = F_73 ( V_24 ) ;
F_82 ( & V_9 -> V_127 ) ;
V_24 -> V_114 = V_114 ;
if ( V_49 == - V_135 ) {
V_49 = 0 ;
goto V_106;
}
F_4 ( & V_22 -> V_55 ) ;
V_49 = F_65 ( F_67 ( V_24 -> V_31 ) , V_22 ,
V_130 , & V_131 ) ;
if ( V_49 < 0 )
goto V_106;
if ( V_70 -> V_49 == V_107 )
goto V_106;
if ( V_70 -> V_49 != V_136 )
F_39 ( L_15 ,
F_55 ( V_70 -> V_49 ) ) ;
V_49 = - V_79 ;
V_106:
F_41 ( V_22 ) ;
return V_49 ;
}
static void F_85 ( struct V_91 * V_103 , void * V_4 )
{
struct V_21 * V_22 = V_4 ;
T_1 V_49 = F_55 ( V_22 -> V_56 . V_49 ) ;
if ( F_86 ( V_103 ) )
goto V_137;
if ( V_103 -> V_138 < 0 ) {
F_35 ( L_16 , - V_103 -> V_138 ) ;
switch ( V_103 -> V_138 ) {
case - V_139 :
case - V_140 :
goto V_137;
default:
goto V_141;
}
}
if ( V_49 == V_142 ) {
F_87 ( V_103 , V_63 ) ;
goto V_143;
}
if ( V_49 != V_144 )
F_39 ( V_89 L_15 , V_49 ) ;
V_137:
return;
V_141:
F_53 ( V_22 -> V_57 ) ;
V_143:
F_88 ( V_103 ) ;
}
static int F_80 ( struct V_12 * V_9 , int V_52 , struct V_23 * V_24 )
{
struct V_21 * V_22 ;
int V_49 ;
F_35 ( L_17
L_18 ) ;
V_22 = F_27 ( F_19 ( V_9 ) ) ;
if ( ! V_22 )
return - V_50 ;
V_22 -> V_133 = V_99 ;
F_21 ( V_22 , V_24 ) ;
V_22 -> V_27 . V_52 = V_52 ;
F_4 ( & V_22 -> V_55 ) ;
V_49 = F_65 ( F_67 ( V_24 -> V_31 ) , V_22 ,
V_145 , & V_146 ) ;
if ( V_49 == 0 && V_22 -> V_56 . V_49 == V_108 )
V_49 = - V_79 ;
F_41 ( V_22 ) ;
return V_49 ;
}
static void F_89 ( struct V_91 * V_103 , void * V_4 )
{
struct V_21 * V_22 = V_4 ;
T_1 V_49 = F_55 ( V_22 -> V_56 . V_49 ) ;
if ( F_86 ( V_103 ) )
goto V_137;
if ( V_103 -> V_138 < 0 ) {
F_35 ( L_19 ,
V_103 -> V_138 ) ;
goto V_147;
}
F_35 ( L_20 ,
V_49 , V_103 -> V_148 ) ;
switch ( V_49 ) {
case V_144 :
case V_142 :
case V_149 :
break;
case V_150 :
F_35 ( L_21 ) ;
goto V_147;
default:
F_39 ( V_151 L_22 ,
V_49 ) ;
}
V_137:
return;
V_147:
if ( V_22 -> V_152 ++ >= V_153 )
goto V_137;
F_53 ( V_22 -> V_57 ) ;
F_88 ( V_103 ) ;
F_87 ( V_103 , 30 * V_58 ) ;
}
static int
F_68 ( T_5 V_49 )
{
switch( F_55 ( V_49 ) ) {
case V_144 :
return 0 ;
case V_149 :
return - V_86 ;
case V_150 :
case V_142 :
return - V_79 ;
case V_154 :
F_39 ( V_151 L_23 ) ;
return - V_79 ;
#ifdef F_90
case V_155 :
return - V_156 ;
case V_157 :
return - V_158 ;
case V_159 :
return - V_160 ;
case V_161 :
return - V_162 ;
case V_163 :
return - V_79 ;
#endif
}
F_39 ( V_151 L_24 ,
F_55 ( V_49 ) ) ;
return - V_79 ;
}
