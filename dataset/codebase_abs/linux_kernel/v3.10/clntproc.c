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
memcpy ( & V_29 -> V_30 , F_22 ( F_23 ( V_24 -> V_31 ) ) , sizeof( struct V_32 ) ) ;
V_29 -> V_33 = F_24 () -> V_34 ;
V_29 -> V_35 . V_4 = V_22 -> V_36 ;
V_29 -> V_35 . V_5 = snprintf ( V_22 -> V_36 , sizeof( V_22 -> V_36 ) , L_1 ,
( unsigned int ) V_24 -> V_37 . V_38 . V_17 -> V_13 ,
F_24 () -> V_34 ) ;
V_29 -> V_39 = V_24 -> V_37 . V_38 . V_17 -> V_13 ;
V_29 -> V_24 . V_40 = V_24 -> V_40 ;
V_29 -> V_24 . V_41 = V_24 -> V_41 ;
V_29 -> V_24 . V_42 = V_24 -> V_42 ;
}
static void F_25 ( struct V_21 * V_22 )
{
F_26 ( V_22 -> V_27 . V_29 . V_24 . V_43 != NULL ) ;
}
int F_27 ( struct V_12 * V_9 , int V_44 , struct V_23 * V_24 )
{
struct V_21 * V_45 ;
int V_46 ;
V_45 = F_28 ( V_9 ) ;
if ( V_45 == NULL )
return - V_47 ;
F_29 ( V_24 , V_9 ) ;
if ( ! V_24 -> V_37 . V_38 . V_17 ) {
F_30 ( V_45 ) ;
return - V_47 ;
}
F_21 ( V_45 , V_24 ) ;
if ( F_31 ( V_44 ) || F_32 ( V_44 ) ) {
if ( V_24 -> V_42 != V_48 ) {
V_45 -> V_27 . V_49 = F_32 ( V_44 ) ? 1 : 0 ;
V_46 = F_33 ( V_45 , V_24 ) ;
} else
V_46 = F_34 ( V_45 , V_24 ) ;
} else if ( F_35 ( V_44 ) )
V_46 = F_36 ( V_45 , V_24 ) ;
else
V_46 = - V_50 ;
V_24 -> V_43 -> V_51 ( V_24 ) ;
V_24 -> V_43 = NULL ;
F_37 ( L_2 , V_46 ) ;
return V_46 ;
}
struct V_21 * F_28 ( struct V_12 * V_9 )
{
struct V_21 * V_45 ;
for(; ; ) {
V_45 = F_38 ( sizeof( * V_45 ) , V_19 ) ;
if ( V_45 != NULL ) {
F_18 ( & V_45 -> V_52 , 1 ) ;
F_39 ( & V_45 -> V_27 . V_29 . V_24 ) ;
F_39 ( & V_45 -> V_53 . V_29 . V_24 ) ;
V_45 -> V_54 = F_19 ( V_9 ) ;
return V_45 ;
}
if ( F_40 () )
break;
F_41 ( L_3 ) ;
F_42 ( 5 * V_55 ) ;
}
return NULL ;
}
void F_30 ( struct V_21 * V_45 )
{
if ( ! F_43 ( & V_45 -> V_52 ) )
return;
F_9 ( V_45 -> V_54 ) ;
F_25 ( V_45 ) ;
F_10 ( V_45 ) ;
}
static void F_44 ( void * V_4 )
{
F_30 ( V_4 ) ;
}
static int F_45 ( T_4 * V_56 )
{
F_46 ( V_57 ) ;
int V_46 = - V_58 ;
F_47 ( V_56 , & V_57 , V_59 ) ;
if ( ! F_40 () ) {
F_48 ( V_60 ) ;
F_49 () ;
if ( ! F_40 () )
V_46 = 0 ;
}
F_50 ( V_56 , & V_57 ) ;
return V_46 ;
}
static int
F_51 ( struct V_61 * V_62 , struct V_21 * V_22 , T_1 V_63 )
{
struct V_12 * V_9 = V_22 -> V_54 ;
struct V_64 * V_65 ;
struct V_25 * V_26 = & V_22 -> V_27 ;
struct V_66 * V_67 = & V_22 -> V_53 ;
struct V_68 V_69 = {
. V_70 = V_26 ,
. V_71 = V_67 ,
. V_61 = V_62 ,
} ;
int V_46 ;
F_37 ( L_4 ,
( int ) V_63 , V_9 -> V_72 ) ;
do {
if ( V_9 -> V_73 && ! V_26 -> V_74 )
goto V_75;
if ( ( V_65 = F_52 ( V_9 ) ) == NULL )
return - V_76 ;
V_69 . V_77 = & V_65 -> V_78 [ V_63 ] ;
if ( ( V_46 = F_53 ( V_65 , & V_69 , 0 ) ) < 0 ) {
F_37 ( L_5 , - V_46 ) ;
switch ( V_46 ) {
case - V_79 :
V_46 = - V_50 ;
break;
case - V_80 :
case - V_81 :
case - V_82 :
F_54 ( V_9 ) ;
V_46 = - V_83 ;
break;
case - V_84 :
return F_40 () ? - V_58 : V_46 ;
default:
break;
}
break;
} else
if ( V_67 -> V_46 == V_85 ) {
F_37 ( L_6 ) ;
if ( V_26 -> V_74 ) {
F_41 ( V_86
L_7 ) ;
return - V_76 ;
}
} else {
if ( ! V_26 -> V_74 ) {
F_55 ( & V_9 -> V_87 ) ;
}
F_37 ( L_8 ,
F_56 ( V_67 -> V_46 ) ) ;
return 0 ;
}
V_75:
V_46 = F_45 ( & V_9 -> V_87 ) ;
} while ( V_46 == 0 );
return V_46 ;
}
static struct V_88 * F_57 ( struct V_21 * V_22 , T_1 V_63 , struct V_68 * V_69 , const struct V_89 * V_90 )
{
struct V_12 * V_9 = V_22 -> V_54 ;
struct V_64 * V_65 ;
struct V_91 V_92 = {
. V_68 = V_69 ,
. V_93 = V_90 ,
. V_94 = V_22 ,
. V_95 = V_96 ,
} ;
F_37 ( L_9 ,
( int ) V_63 , V_9 -> V_72 ) ;
V_65 = F_52 ( V_9 ) ;
if ( V_65 == NULL )
goto V_97;
V_69 -> V_77 = & V_65 -> V_78 [ V_63 ] ;
V_92 . V_98 = V_65 ;
return F_58 ( & V_92 ) ;
V_97:
V_90 -> V_99 ( V_22 ) ;
return F_59 ( - V_76 ) ;
}
static int F_60 ( struct V_21 * V_22 , T_1 V_63 , struct V_68 * V_69 , const struct V_89 * V_90 )
{
struct V_88 * V_100 ;
V_100 = F_57 ( V_22 , V_63 , V_69 , V_90 ) ;
if ( F_61 ( V_100 ) )
return F_62 ( V_100 ) ;
F_63 ( V_100 ) ;
return 0 ;
}
int F_64 ( struct V_21 * V_22 , T_1 V_63 , const struct V_89 * V_90 )
{
struct V_68 V_69 = {
. V_70 = & V_22 -> V_27 ,
. V_71 = & V_22 -> V_53 ,
} ;
return F_60 ( V_22 , V_63 , & V_69 , V_90 ) ;
}
int F_65 ( struct V_21 * V_22 , T_1 V_63 , const struct V_89 * V_90 )
{
struct V_68 V_69 = {
. V_70 = & V_22 -> V_53 ,
} ;
return F_60 ( V_22 , V_63 , & V_69 , V_90 ) ;
}
static int F_66 ( struct V_61 * V_62 , struct V_21 * V_22 , T_1 V_63 , const struct V_89 * V_90 )
{
struct V_68 V_69 = {
. V_70 = & V_22 -> V_27 ,
. V_71 = & V_22 -> V_53 ,
. V_61 = V_62 ,
} ;
struct V_88 * V_100 ;
int V_101 ;
V_100 = F_57 ( V_22 , V_63 , & V_69 , V_90 ) ;
if ( F_61 ( V_100 ) )
return F_62 ( V_100 ) ;
V_101 = F_67 ( V_100 ) ;
F_63 ( V_100 ) ;
return V_101 ;
}
static int
F_36 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
int V_46 ;
V_46 = F_51 ( F_68 ( V_24 -> V_31 ) , V_22 , V_102 ) ;
if ( V_46 < 0 )
goto V_103;
switch ( V_22 -> V_53 . V_46 ) {
case V_104 :
V_24 -> V_42 = V_48 ;
break;
case V_105 :
V_24 -> V_40 = V_22 -> V_53 . V_29 . V_24 . V_40 ;
V_24 -> V_41 = V_22 -> V_53 . V_29 . V_24 . V_41 ;
V_24 -> V_42 = V_22 -> V_53 . V_29 . V_24 . V_42 ;
V_24 -> V_106 = 0 ;
break;
default:
V_46 = F_69 ( V_22 -> V_53 . V_46 ) ;
}
V_103:
F_30 ( V_22 ) ;
return V_46 ;
}
static void F_70 ( struct V_23 * V_18 , struct V_23 * V_24 )
{
F_16 ( & V_24 -> V_37 . V_38 . V_17 -> V_9 -> V_10 ) ;
V_18 -> V_37 . V_38 . V_107 = V_24 -> V_37 . V_38 . V_107 ;
V_18 -> V_37 . V_38 . V_17 = F_3 ( V_24 -> V_37 . V_38 . V_17 ) ;
F_71 ( & V_18 -> V_37 . V_38 . V_11 , & V_24 -> V_37 . V_38 . V_17 -> V_9 -> V_108 ) ;
F_8 ( & V_24 -> V_37 . V_38 . V_17 -> V_9 -> V_10 ) ;
}
static void F_72 ( struct V_23 * V_24 )
{
F_16 ( & V_24 -> V_37 . V_38 . V_17 -> V_9 -> V_10 ) ;
F_7 ( & V_24 -> V_37 . V_38 . V_11 ) ;
F_8 ( & V_24 -> V_37 . V_38 . V_17 -> V_9 -> V_10 ) ;
F_5 ( V_24 -> V_37 . V_38 . V_17 ) ;
}
static void F_29 ( struct V_23 * V_24 , struct V_12 * V_9 )
{
V_24 -> V_37 . V_38 . V_107 = 0 ;
V_24 -> V_37 . V_38 . V_17 = F_15 ( V_9 , V_24 -> V_109 ) ;
F_73 ( & V_24 -> V_37 . V_38 . V_11 ) ;
V_24 -> V_43 = & V_110 ;
}
static int F_74 ( struct V_23 * V_24 )
{
int V_15 = 0 ;
switch ( V_24 -> V_111 & ( V_112 | V_113 ) ) {
case V_112 :
V_15 = F_75 ( V_24 -> V_31 , V_24 ) ;
break;
case V_113 :
V_15 = F_76 ( V_24 -> V_31 , V_24 ) ;
break;
default:
F_77 () ;
}
return V_15 ;
}
static int
F_33 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_61 * V_62 = F_68 ( V_24 -> V_31 ) ;
struct V_12 * V_9 = V_22 -> V_54 ;
struct V_66 * V_67 = & V_22 -> V_53 ;
struct V_114 * V_49 = NULL ;
unsigned char V_111 = V_24 -> V_111 ;
unsigned char V_42 ;
int V_46 = - V_76 ;
if ( F_78 ( V_9 ) < 0 )
goto V_103;
V_22 -> V_27 . V_107 = V_115 ;
V_24 -> V_111 |= V_116 ;
V_46 = F_74 ( V_24 ) ;
V_24 -> V_111 = V_111 ;
if ( V_46 < 0 )
goto V_103;
V_49 = F_79 ( V_9 , V_24 ) ;
V_117:
V_67 -> V_46 = V_118 ;
for(; ; ) {
V_24 -> V_37 . V_38 . V_107 = V_9 -> V_119 ;
V_46 = F_51 ( V_62 , V_22 , V_120 ) ;
if ( V_46 < 0 )
break;
if ( V_67 -> V_46 == V_85 )
continue;
if ( V_67 -> V_46 != V_118 )
break;
V_46 = F_80 ( V_49 , V_22 , V_121 ) ;
if ( V_46 < 0 )
break;
if ( V_67 -> V_46 != V_118 )
break;
}
if ( V_67 -> V_46 == V_118 ) {
if ( ! V_22 -> V_27 . V_49 )
goto V_122;
if ( F_81 ( V_9 , V_22 -> V_27 . V_49 , V_24 ) == 0 )
goto V_123;
}
if ( V_67 -> V_46 == V_104 ) {
F_82 ( & V_9 -> V_124 ) ;
if ( V_24 -> V_37 . V_38 . V_107 != V_9 -> V_119 ) {
F_83 ( & V_9 -> V_124 ) ;
goto V_117;
}
V_24 -> V_111 |= V_125 ;
if ( F_74 ( V_24 ) < 0 )
F_41 ( V_86 L_10 , V_126 ) ;
F_83 ( & V_9 -> V_124 ) ;
V_24 -> V_111 = V_111 ;
V_46 = 0 ;
}
if ( V_46 < 0 )
goto V_122;
if ( V_67 -> V_46 == V_105 && ( V_111 & V_125 ) )
V_46 = - V_76 ;
else
V_46 = F_69 ( V_67 -> V_46 ) ;
V_123:
F_84 ( V_49 ) ;
V_103:
F_30 ( V_22 ) ;
return V_46 ;
V_122:
F_37 ( L_11
L_12 ) ;
F_84 ( V_49 ) ;
V_42 = V_24 -> V_42 ;
V_24 -> V_42 = V_48 ;
F_82 ( & V_9 -> V_124 ) ;
F_74 ( V_24 ) ;
F_83 ( & V_9 -> V_124 ) ;
V_24 -> V_42 = V_42 ;
V_24 -> V_111 = V_111 ;
F_66 ( V_62 , V_22 , V_127 , & V_128 ) ;
return V_46 ;
}
int
F_85 ( struct V_12 * V_9 , struct V_23 * V_24 ,
struct V_21 * V_22 )
{
int V_46 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
F_39 ( & V_22 -> V_27 . V_29 . V_24 ) ;
F_39 ( & V_22 -> V_53 . V_29 . V_24 ) ;
V_22 -> V_54 = V_9 ;
F_21 ( V_22 , V_24 ) ;
V_22 -> V_27 . V_74 = 1 ;
V_46 = F_51 ( F_68 ( V_24 -> V_31 ) , V_22 , V_120 ) ;
if ( V_46 >= 0 && V_22 -> V_53 . V_46 == V_104 )
return 0 ;
F_41 ( V_86 L_13
L_14 , V_24 -> V_106 ,
V_46 , F_56 ( V_22 -> V_53 . V_46 ) ) ;
return - V_76 ;
}
static int
F_34 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_12 * V_9 = V_22 -> V_54 ;
struct V_66 * V_67 = & V_22 -> V_53 ;
int V_46 ;
unsigned char V_111 = V_24 -> V_111 ;
V_24 -> V_111 |= V_129 ;
F_82 ( & V_9 -> V_124 ) ;
V_46 = F_74 ( V_24 ) ;
F_83 ( & V_9 -> V_124 ) ;
V_24 -> V_111 = V_111 ;
if ( V_46 == - V_130 ) {
V_46 = 0 ;
goto V_103;
}
F_4 ( & V_22 -> V_52 ) ;
V_46 = F_66 ( F_68 ( V_24 -> V_31 ) , V_22 ,
V_127 , & V_128 ) ;
if ( V_46 < 0 )
goto V_103;
if ( V_67 -> V_46 == V_104 )
goto V_103;
if ( V_67 -> V_46 != V_131 )
F_41 ( L_15 ,
F_56 ( V_67 -> V_46 ) ) ;
V_46 = - V_76 ;
V_103:
F_30 ( V_22 ) ;
return V_46 ;
}
static void F_86 ( struct V_88 * V_100 , void * V_4 )
{
struct V_21 * V_22 = V_4 ;
T_1 V_46 = F_56 ( V_22 -> V_53 . V_46 ) ;
if ( F_87 ( V_100 ) )
goto V_132;
if ( V_100 -> V_133 < 0 ) {
F_37 ( L_16 , - V_100 -> V_133 ) ;
switch ( V_100 -> V_133 ) {
case - V_134 :
case - V_135 :
goto V_132;
default:
goto V_136;
}
}
if ( V_46 == V_137 ) {
F_88 ( V_100 , V_60 ) ;
goto V_138;
}
if ( V_46 != V_139 )
F_41 ( V_86 L_15 , V_46 ) ;
V_132:
return;
V_136:
F_54 ( V_22 -> V_54 ) ;
V_138:
F_89 ( V_100 ) ;
}
static int F_81 ( struct V_12 * V_9 , int V_49 , struct V_23 * V_24 )
{
struct V_21 * V_22 ;
int V_46 ;
F_37 ( L_17
L_18 ) ;
V_22 = F_28 ( V_9 ) ;
if ( ! V_22 )
return - V_47 ;
V_22 -> V_140 = V_96 ;
F_21 ( V_22 , V_24 ) ;
V_22 -> V_27 . V_49 = V_49 ;
F_4 ( & V_22 -> V_52 ) ;
V_46 = F_66 ( F_68 ( V_24 -> V_31 ) , V_22 ,
V_141 , & V_142 ) ;
if ( V_46 == 0 && V_22 -> V_53 . V_46 == V_105 )
V_46 = - V_76 ;
F_30 ( V_22 ) ;
return V_46 ;
}
static void F_90 ( struct V_88 * V_100 , void * V_4 )
{
struct V_21 * V_22 = V_4 ;
T_1 V_46 = F_56 ( V_22 -> V_53 . V_46 ) ;
if ( F_87 ( V_100 ) )
goto V_132;
if ( V_100 -> V_133 < 0 ) {
F_37 ( L_19 ,
V_100 -> V_133 ) ;
goto V_143;
}
F_37 ( L_20 ,
V_46 , V_100 -> V_144 ) ;
switch ( V_46 ) {
case V_139 :
case V_137 :
case V_145 :
break;
case V_146 :
F_37 ( L_21 ) ;
goto V_143;
default:
F_41 ( V_147 L_22 ,
V_46 ) ;
}
V_132:
return;
V_143:
if ( V_22 -> V_148 ++ >= V_149 )
goto V_132;
F_54 ( V_22 -> V_54 ) ;
F_89 ( V_100 ) ;
F_88 ( V_100 , 30 * V_55 ) ;
}
static int
F_69 ( T_5 V_46 )
{
switch( F_56 ( V_46 ) ) {
case V_139 :
return 0 ;
case V_145 :
return - V_83 ;
case V_146 :
case V_137 :
return - V_76 ;
case V_150 :
F_41 ( V_147 L_23 ) ;
return - V_76 ;
#ifdef F_91
case V_151 :
return - V_152 ;
case V_153 :
return - V_154 ;
case V_155 :
return - V_156 ;
case V_157 :
return - V_158 ;
case V_159 :
return - V_76 ;
#endif
}
F_41 ( V_147 L_24 ,
F_56 ( V_46 ) ) ;
return - V_76 ;
}
