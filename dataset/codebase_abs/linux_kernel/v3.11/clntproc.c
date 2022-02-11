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
int F_26 ( struct V_12 * V_9 , int V_47 , struct V_23 * V_24 )
{
struct V_21 * V_48 ;
int V_49 ;
V_48 = F_27 ( V_9 ) ;
if ( V_48 == NULL )
return - V_50 ;
F_28 ( V_24 , V_9 ) ;
if ( ! V_24 -> V_40 . V_41 . V_17 ) {
F_29 ( V_48 ) ;
return - V_50 ;
}
F_21 ( V_48 , V_24 ) ;
if ( F_30 ( V_47 ) || F_31 ( V_47 ) ) {
if ( V_24 -> V_45 != V_51 ) {
V_48 -> V_27 . V_52 = F_31 ( V_47 ) ? 1 : 0 ;
V_49 = F_32 ( V_48 , V_24 ) ;
} else
V_49 = F_33 ( V_48 , V_24 ) ;
} else if ( F_34 ( V_47 ) )
V_49 = F_35 ( V_48 , V_24 ) ;
else
V_49 = - V_53 ;
V_24 -> V_46 -> V_54 ( V_24 ) ;
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
F_18 ( & V_48 -> V_55 , 1 ) ;
F_38 ( & V_48 -> V_27 . V_29 . V_24 ) ;
F_38 ( & V_48 -> V_56 . V_29 . V_24 ) ;
V_48 -> V_31 = F_19 ( V_9 ) ;
return V_48 ;
}
if ( F_39 () )
break;
F_40 ( L_3 ) ;
F_41 ( 5 * V_57 ) ;
}
return NULL ;
}
void F_29 ( struct V_21 * V_48 )
{
if ( ! F_42 ( & V_48 -> V_55 ) )
return;
F_9 ( V_48 -> V_31 ) ;
F_24 ( V_48 ) ;
F_10 ( V_48 ) ;
}
static void F_43 ( void * V_4 )
{
F_29 ( V_4 ) ;
}
static int F_44 ( T_4 * V_58 )
{
F_45 ( V_59 ) ;
int V_49 = - V_60 ;
F_46 ( V_58 , & V_59 , V_61 ) ;
if ( ! F_39 () ) {
F_47 ( V_62 ) ;
F_48 () ;
if ( ! F_39 () )
V_49 = 0 ;
}
F_49 ( V_58 , & V_59 ) ;
return V_49 ;
}
static int
F_50 ( struct V_63 * V_64 , struct V_21 * V_22 , T_1 V_65 )
{
struct V_12 * V_9 = V_22 -> V_31 ;
struct V_66 * V_67 ;
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_68 * V_69 = & V_22 -> V_56 ;
struct V_70 V_71 = {
. V_72 = V_26 ,
. V_73 = V_69 ,
. V_63 = V_64 ,
} ;
int V_49 ;
F_36 ( L_4 ,
( int ) V_65 , V_9 -> V_74 ) ;
do {
if ( V_9 -> V_75 && ! V_26 -> V_76 )
goto V_77;
if ( ( V_67 = F_51 ( V_9 ) ) == NULL )
return - V_78 ;
V_71 . V_79 = & V_67 -> V_80 [ V_65 ] ;
if ( ( V_49 = F_52 ( V_67 , & V_71 , 0 ) ) < 0 ) {
F_36 ( L_5 , - V_49 ) ;
switch ( V_49 ) {
case - V_81 :
V_49 = - V_53 ;
break;
case - V_82 :
case - V_83 :
case - V_84 :
F_53 ( V_9 ) ;
V_49 = - V_85 ;
break;
case - V_86 :
return F_39 () ? - V_60 : V_49 ;
default:
break;
}
break;
} else
if ( V_69 -> V_49 == V_87 ) {
F_36 ( L_6 ) ;
if ( V_26 -> V_76 ) {
F_40 ( V_88
L_7 ) ;
return - V_78 ;
}
} else {
if ( ! V_26 -> V_76 ) {
F_54 ( & V_9 -> V_89 ) ;
}
F_36 ( L_8 ,
F_55 ( V_69 -> V_49 ) ) ;
return 0 ;
}
V_77:
V_49 = F_44 ( & V_9 -> V_89 ) ;
} while ( V_49 == 0 );
return V_49 ;
}
static struct V_90 * F_56 ( struct V_21 * V_22 , T_1 V_65 , struct V_70 * V_71 , const struct V_91 * V_92 )
{
struct V_12 * V_9 = V_22 -> V_31 ;
struct V_66 * V_67 ;
struct V_93 V_94 = {
. V_70 = V_71 ,
. V_95 = V_92 ,
. V_96 = V_22 ,
. V_97 = V_98 ,
} ;
F_36 ( L_9 ,
( int ) V_65 , V_9 -> V_74 ) ;
V_67 = F_51 ( V_9 ) ;
if ( V_67 == NULL )
goto V_99;
V_71 -> V_79 = & V_67 -> V_80 [ V_65 ] ;
V_94 . V_100 = V_67 ;
return F_57 ( & V_94 ) ;
V_99:
V_92 -> V_101 ( V_22 ) ;
return F_58 ( - V_78 ) ;
}
static int F_59 ( struct V_21 * V_22 , T_1 V_65 , struct V_70 * V_71 , const struct V_91 * V_92 )
{
struct V_90 * V_102 ;
V_102 = F_56 ( V_22 , V_65 , V_71 , V_92 ) ;
if ( F_60 ( V_102 ) )
return F_61 ( V_102 ) ;
F_62 ( V_102 ) ;
return 0 ;
}
int F_63 ( struct V_21 * V_22 , T_1 V_65 , const struct V_91 * V_92 )
{
struct V_70 V_71 = {
. V_72 = & V_22 -> V_27 ,
. V_73 = & V_22 -> V_56 ,
} ;
return F_59 ( V_22 , V_65 , & V_71 , V_92 ) ;
}
int F_64 ( struct V_21 * V_22 , T_1 V_65 , const struct V_91 * V_92 )
{
struct V_70 V_71 = {
. V_72 = & V_22 -> V_56 ,
} ;
return F_59 ( V_22 , V_65 , & V_71 , V_92 ) ;
}
static int F_65 ( struct V_63 * V_64 , struct V_21 * V_22 , T_1 V_65 , const struct V_91 * V_92 )
{
struct V_70 V_71 = {
. V_72 = & V_22 -> V_27 ,
. V_73 = & V_22 -> V_56 ,
. V_63 = V_64 ,
} ;
struct V_90 * V_102 ;
int V_103 ;
V_102 = F_56 ( V_22 , V_65 , & V_71 , V_92 ) ;
if ( F_60 ( V_102 ) )
return F_61 ( V_102 ) ;
V_103 = F_66 ( V_102 ) ;
F_62 ( V_102 ) ;
return V_103 ;
}
static int
F_35 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
int V_49 ;
V_49 = F_50 ( F_67 ( V_24 -> V_35 ) , V_22 , V_104 ) ;
if ( V_49 < 0 )
goto V_105;
switch ( V_22 -> V_56 . V_49 ) {
case V_106 :
V_24 -> V_45 = V_51 ;
break;
case V_107 :
V_24 -> V_43 = V_22 -> V_56 . V_29 . V_24 . V_43 ;
V_24 -> V_44 = V_22 -> V_56 . V_29 . V_24 . V_44 ;
V_24 -> V_45 = V_22 -> V_56 . V_29 . V_24 . V_45 ;
V_24 -> V_108 = 0 ;
break;
default:
V_49 = F_68 ( V_22 -> V_56 . V_49 ) ;
}
V_105:
F_29 ( V_22 ) ;
return V_49 ;
}
static void F_69 ( struct V_23 * V_18 , struct V_23 * V_24 )
{
F_16 ( & V_24 -> V_40 . V_41 . V_17 -> V_9 -> V_10 ) ;
V_18 -> V_40 . V_41 . V_109 = V_24 -> V_40 . V_41 . V_109 ;
V_18 -> V_40 . V_41 . V_17 = F_3 ( V_24 -> V_40 . V_41 . V_17 ) ;
F_70 ( & V_18 -> V_40 . V_41 . V_11 , & V_24 -> V_40 . V_41 . V_17 -> V_9 -> V_110 ) ;
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
V_24 -> V_40 . V_41 . V_109 = 0 ;
V_24 -> V_40 . V_41 . V_17 = F_15 ( V_9 , V_24 -> V_111 ) ;
F_72 ( & V_24 -> V_40 . V_41 . V_11 ) ;
V_24 -> V_46 = & V_112 ;
}
static int F_73 ( struct V_23 * V_24 )
{
int V_15 = 0 ;
switch ( V_24 -> V_113 & ( V_114 | V_115 ) ) {
case V_114 :
V_15 = F_74 ( V_24 -> V_35 , V_24 ) ;
break;
case V_115 :
V_15 = F_75 ( V_24 -> V_35 , V_24 ) ;
break;
default:
F_76 () ;
}
return V_15 ;
}
static int
F_32 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_63 * V_64 = F_67 ( V_24 -> V_35 ) ;
struct V_12 * V_9 = V_22 -> V_31 ;
struct V_68 * V_69 = & V_22 -> V_56 ;
struct V_116 * V_52 = NULL ;
unsigned char V_113 = V_24 -> V_113 ;
unsigned char V_45 ;
int V_49 = - V_78 ;
if ( F_77 ( V_9 ) < 0 )
goto V_105;
V_22 -> V_27 . V_109 = V_117 ;
V_24 -> V_113 |= V_118 ;
V_49 = F_73 ( V_24 ) ;
V_24 -> V_113 = V_113 ;
if ( V_49 < 0 )
goto V_105;
V_52 = F_78 ( V_9 , V_24 ) ;
V_119:
V_69 -> V_49 = V_120 ;
for(; ; ) {
V_24 -> V_40 . V_41 . V_109 = V_9 -> V_121 ;
V_49 = F_50 ( V_64 , V_22 , V_122 ) ;
if ( V_49 < 0 )
break;
if ( V_69 -> V_49 == V_87 )
continue;
if ( V_69 -> V_49 != V_120 )
break;
V_49 = F_79 ( V_52 , V_22 , V_123 ) ;
if ( V_49 < 0 )
break;
if ( V_69 -> V_49 != V_120 )
break;
}
if ( V_69 -> V_49 == V_120 ) {
if ( ! V_22 -> V_27 . V_52 )
goto V_124;
if ( F_80 ( V_9 , V_22 -> V_27 . V_52 , V_24 ) == 0 )
goto V_125;
}
if ( V_69 -> V_49 == V_106 ) {
F_81 ( & V_9 -> V_126 ) ;
if ( V_24 -> V_40 . V_41 . V_109 != V_9 -> V_121 ) {
F_82 ( & V_9 -> V_126 ) ;
goto V_119;
}
V_24 -> V_113 |= V_127 ;
if ( F_73 ( V_24 ) < 0 )
F_40 ( V_88 L_10 , V_128 ) ;
F_82 ( & V_9 -> V_126 ) ;
V_24 -> V_113 = V_113 ;
V_49 = 0 ;
}
if ( V_49 < 0 )
goto V_124;
if ( V_69 -> V_49 == V_107 && ( V_113 & V_127 ) )
V_49 = - V_78 ;
else
V_49 = F_68 ( V_69 -> V_49 ) ;
V_125:
F_83 ( V_52 ) ;
V_105:
F_29 ( V_22 ) ;
return V_49 ;
V_124:
F_36 ( L_11
L_12 ) ;
F_83 ( V_52 ) ;
V_45 = V_24 -> V_45 ;
V_24 -> V_45 = V_51 ;
F_81 ( & V_9 -> V_126 ) ;
F_73 ( V_24 ) ;
F_82 ( & V_9 -> V_126 ) ;
V_24 -> V_45 = V_45 ;
V_24 -> V_113 = V_113 ;
F_65 ( V_64 , V_22 , V_129 , & V_130 ) ;
return V_49 ;
}
int
F_84 ( struct V_12 * V_9 , struct V_23 * V_24 ,
struct V_21 * V_22 )
{
int V_49 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
F_38 ( & V_22 -> V_27 . V_29 . V_24 ) ;
F_38 ( & V_22 -> V_56 . V_29 . V_24 ) ;
V_22 -> V_31 = V_9 ;
F_21 ( V_22 , V_24 ) ;
V_22 -> V_27 . V_76 = 1 ;
V_49 = F_50 ( F_67 ( V_24 -> V_35 ) , V_22 , V_122 ) ;
if ( V_49 >= 0 && V_22 -> V_56 . V_49 == V_106 )
return 0 ;
F_40 ( V_88 L_13
L_14 , V_24 -> V_108 ,
V_49 , F_55 ( V_22 -> V_56 . V_49 ) ) ;
return - V_78 ;
}
static int
F_33 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_12 * V_9 = V_22 -> V_31 ;
struct V_68 * V_69 = & V_22 -> V_56 ;
int V_49 ;
unsigned char V_113 = V_24 -> V_113 ;
V_24 -> V_113 |= V_131 ;
F_81 ( & V_9 -> V_126 ) ;
V_49 = F_73 ( V_24 ) ;
F_82 ( & V_9 -> V_126 ) ;
V_24 -> V_113 = V_113 ;
if ( V_49 == - V_132 ) {
V_49 = 0 ;
goto V_105;
}
F_4 ( & V_22 -> V_55 ) ;
V_49 = F_65 ( F_67 ( V_24 -> V_35 ) , V_22 ,
V_129 , & V_130 ) ;
if ( V_49 < 0 )
goto V_105;
if ( V_69 -> V_49 == V_106 )
goto V_105;
if ( V_69 -> V_49 != V_133 )
F_40 ( L_15 ,
F_55 ( V_69 -> V_49 ) ) ;
V_49 = - V_78 ;
V_105:
F_29 ( V_22 ) ;
return V_49 ;
}
static void F_85 ( struct V_90 * V_102 , void * V_4 )
{
struct V_21 * V_22 = V_4 ;
T_1 V_49 = F_55 ( V_22 -> V_56 . V_49 ) ;
if ( F_86 ( V_102 ) )
goto V_134;
if ( V_102 -> V_135 < 0 ) {
F_36 ( L_16 , - V_102 -> V_135 ) ;
switch ( V_102 -> V_135 ) {
case - V_136 :
case - V_137 :
goto V_134;
default:
goto V_138;
}
}
if ( V_49 == V_139 ) {
F_87 ( V_102 , V_62 ) ;
goto V_140;
}
if ( V_49 != V_141 )
F_40 ( V_88 L_15 , V_49 ) ;
V_134:
return;
V_138:
F_53 ( V_22 -> V_31 ) ;
V_140:
F_88 ( V_102 ) ;
}
static int F_80 ( struct V_12 * V_9 , int V_52 , struct V_23 * V_24 )
{
struct V_21 * V_22 ;
int V_49 ;
F_36 ( L_17
L_18 ) ;
V_22 = F_27 ( V_9 ) ;
if ( ! V_22 )
return - V_50 ;
V_22 -> V_142 = V_98 ;
F_21 ( V_22 , V_24 ) ;
V_22 -> V_27 . V_52 = V_52 ;
F_4 ( & V_22 -> V_55 ) ;
V_49 = F_65 ( F_67 ( V_24 -> V_35 ) , V_22 ,
V_143 , & V_144 ) ;
if ( V_49 == 0 && V_22 -> V_56 . V_49 == V_107 )
V_49 = - V_78 ;
F_29 ( V_22 ) ;
return V_49 ;
}
static void F_89 ( struct V_90 * V_102 , void * V_4 )
{
struct V_21 * V_22 = V_4 ;
T_1 V_49 = F_55 ( V_22 -> V_56 . V_49 ) ;
if ( F_86 ( V_102 ) )
goto V_134;
if ( V_102 -> V_135 < 0 ) {
F_36 ( L_19 ,
V_102 -> V_135 ) ;
goto V_145;
}
F_36 ( L_20 ,
V_49 , V_102 -> V_146 ) ;
switch ( V_49 ) {
case V_141 :
case V_139 :
case V_147 :
break;
case V_148 :
F_36 ( L_21 ) ;
goto V_145;
default:
F_40 ( V_149 L_22 ,
V_49 ) ;
}
V_134:
return;
V_145:
if ( V_22 -> V_150 ++ >= V_151 )
goto V_134;
F_53 ( V_22 -> V_31 ) ;
F_88 ( V_102 ) ;
F_87 ( V_102 , 30 * V_57 ) ;
}
static int
F_68 ( T_5 V_49 )
{
switch( F_55 ( V_49 ) ) {
case V_141 :
return 0 ;
case V_147 :
return - V_85 ;
case V_148 :
case V_139 :
return - V_78 ;
case V_152 :
F_40 ( V_149 L_23 ) ;
return - V_78 ;
#ifdef F_90
case V_153 :
return - V_154 ;
case V_155 :
return - V_156 ;
case V_157 :
return - V_158 ;
case V_159 :
return - V_160 ;
case V_161 :
return - V_78 ;
#endif
}
F_40 ( V_149 L_24 ,
F_55 ( V_49 ) ) ;
return - V_78 ;
}
