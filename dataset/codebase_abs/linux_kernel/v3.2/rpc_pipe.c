static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void (* F_2)( struct V_5 * ) , int V_6 )
{
struct V_5 * V_7 ;
if ( F_3 ( V_4 ) )
return;
do {
V_7 = F_4 ( V_4 -> V_8 , struct V_5 , V_9 ) ;
F_5 ( & V_7 -> V_9 ) ;
V_7 -> V_10 = V_6 ;
F_2 ( V_7 ) ;
} while ( ! F_3 ( V_4 ) );
F_6 ( & V_2 -> V_11 ) ;
}
static void
F_7 ( struct V_12 * V_13 )
{
F_8 ( V_14 ) ;
struct V_1 * V_2 =
F_9 ( V_13 , struct V_1 , V_15 . V_13 ) ;
struct V_16 * V_16 = & V_2 -> V_17 ;
void (* F_2)( struct V_5 * );
F_10 ( & V_16 -> V_18 ) ;
if ( V_2 -> V_19 == NULL ) {
F_11 ( & V_16 -> V_18 ) ;
return;
}
F_2 = V_2 -> V_19 -> F_2 ;
if ( V_2 -> V_20 == 0 ) {
F_12 ( & V_2 -> V_21 , & V_14 ) ;
V_2 -> V_22 = 0 ;
}
F_11 ( & V_16 -> V_18 ) ;
F_1 ( V_2 , & V_14 , F_2 , - V_23 ) ;
}
T_1 F_13 ( struct V_24 * V_25 , struct V_5 * V_7 ,
char T_2 * V_26 , T_3 V_27 )
{
char * V_28 = ( char * ) V_7 -> V_28 + V_7 -> V_29 ;
T_3 V_30 = F_14 ( V_7 -> V_31 - V_7 -> V_29 , V_27 ) ;
unsigned long V_32 ;
V_32 = F_15 ( V_26 , V_28 , V_30 ) ;
if ( V_32 == V_30 ) {
V_7 -> V_10 = - V_33 ;
return - V_33 ;
}
V_30 -= V_32 ;
V_7 -> V_29 += V_30 ;
V_7 -> V_10 = 0 ;
return V_30 ;
}
int
F_16 ( struct V_16 * V_16 , struct V_5 * V_7 )
{
struct V_1 * V_2 = F_17 ( V_16 ) ;
int V_34 = - V_35 ;
F_10 ( & V_16 -> V_18 ) ;
if ( V_2 -> V_19 == NULL )
goto V_36;
if ( V_2 -> V_20 ) {
F_18 ( & V_7 -> V_9 , & V_2 -> V_21 ) ;
V_2 -> V_22 += V_7 -> V_31 ;
V_34 = 0 ;
} else if ( V_2 -> V_37 & V_38 ) {
if ( F_3 ( & V_2 -> V_21 ) )
F_19 ( V_39 ,
& V_2 -> V_15 ,
V_40 ) ;
F_18 ( & V_7 -> V_9 , & V_2 -> V_21 ) ;
V_2 -> V_22 += V_7 -> V_31 ;
V_34 = 0 ;
}
V_36:
F_11 ( & V_16 -> V_18 ) ;
F_6 ( & V_2 -> V_11 ) ;
return V_34 ;
}
static inline void
F_20 ( struct V_16 * V_16 , void * V_41 )
{
F_17 ( V_16 ) -> V_41 = V_41 ;
}
static void
F_21 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_17 ( V_16 ) ;
const struct V_42 * V_19 ;
int V_43 ;
F_22 ( & V_16 -> V_44 ) ;
V_19 = V_2 -> V_19 ;
if ( V_19 != NULL ) {
F_8 ( V_14 ) ;
F_10 ( & V_16 -> V_18 ) ;
V_43 = V_2 -> V_20 != 0 || V_2 -> V_45 != 0 ;
V_2 -> V_20 = 0 ;
F_12 ( & V_2 -> V_46 , & V_14 ) ;
F_12 ( & V_2 -> V_21 , & V_14 ) ;
V_2 -> V_22 = 0 ;
V_2 -> V_19 = NULL ;
F_11 ( & V_16 -> V_18 ) ;
F_1 ( V_2 , & V_14 , V_19 -> F_2 , - V_35 ) ;
V_2 -> V_45 = 0 ;
if ( V_43 && V_19 -> V_47 )
V_19 -> V_47 ( V_16 ) ;
F_23 ( & V_2 -> V_15 ) ;
}
F_20 ( V_16 , NULL ) ;
F_24 ( & V_16 -> V_44 ) ;
}
static struct V_16 *
F_25 ( struct V_48 * V_49 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_26 ( V_50 , V_51 ) ;
if ( ! V_2 )
return NULL ;
return & V_2 -> V_17 ;
}
static void
F_27 ( struct V_52 * V_4 )
{
struct V_16 * V_16 = F_9 ( V_4 , struct V_16 , V_53 ) ;
F_28 ( & V_16 -> V_54 ) ;
F_29 ( V_50 , F_17 ( V_16 ) ) ;
}
static void
F_30 ( struct V_16 * V_16 )
{
F_31 ( & V_16 -> V_53 , F_27 ) ;
}
static int
F_32 ( struct V_16 * V_16 , struct V_24 * V_25 )
{
struct V_1 * V_2 = F_17 ( V_16 ) ;
int V_55 ;
int V_34 = - V_56 ;
F_22 ( & V_16 -> V_44 ) ;
if ( V_2 -> V_19 == NULL )
goto V_36;
V_55 = V_2 -> V_20 == 0 && V_2 -> V_45 == 0 ;
if ( V_55 && V_2 -> V_19 -> V_57 ) {
V_34 = V_2 -> V_19 -> V_57 ( V_16 ) ;
if ( V_34 )
goto V_36;
}
if ( V_25 -> V_58 & V_59 )
V_2 -> V_20 ++ ;
if ( V_25 -> V_58 & V_60 )
V_2 -> V_45 ++ ;
V_34 = 0 ;
V_36:
F_24 ( & V_16 -> V_44 ) ;
return V_34 ;
}
static int
F_33 ( struct V_16 * V_16 , struct V_24 * V_25 )
{
struct V_1 * V_2 = F_17 ( V_16 ) ;
struct V_5 * V_7 ;
int V_61 ;
F_22 ( & V_16 -> V_44 ) ;
if ( V_2 -> V_19 == NULL )
goto V_36;
V_7 = V_25 -> V_62 ;
if ( V_7 != NULL ) {
F_10 ( & V_16 -> V_18 ) ;
V_7 -> V_10 = - V_63 ;
F_5 ( & V_7 -> V_9 ) ;
F_11 ( & V_16 -> V_18 ) ;
V_2 -> V_19 -> F_2 ( V_7 ) ;
}
if ( V_25 -> V_58 & V_60 )
V_2 -> V_45 -- ;
if ( V_25 -> V_58 & V_59 ) {
V_2 -> V_20 -- ;
if ( V_2 -> V_20 == 0 ) {
F_8 ( V_14 ) ;
F_10 ( & V_16 -> V_18 ) ;
F_12 ( & V_2 -> V_21 , & V_14 ) ;
V_2 -> V_22 = 0 ;
F_11 ( & V_16 -> V_18 ) ;
F_1 ( V_2 , & V_14 ,
V_2 -> V_19 -> F_2 , - V_63 ) ;
}
}
V_61 = V_2 -> V_45 == 0 && V_2 -> V_20 == 0 ;
if ( V_61 && V_2 -> V_19 -> V_47 )
V_2 -> V_19 -> V_47 ( V_16 ) ;
V_36:
F_24 ( & V_16 -> V_44 ) ;
return 0 ;
}
static T_1
F_34 ( struct V_24 * V_25 , char T_2 * V_64 , T_3 V_31 , T_4 * V_65 )
{
struct V_16 * V_16 = V_25 -> V_66 . V_67 -> V_68 ;
struct V_1 * V_2 = F_17 ( V_16 ) ;
struct V_5 * V_7 ;
int V_34 = 0 ;
F_22 ( & V_16 -> V_44 ) ;
if ( V_2 -> V_19 == NULL ) {
V_34 = - V_35 ;
goto V_69;
}
V_7 = V_25 -> V_62 ;
if ( V_7 == NULL ) {
F_10 ( & V_16 -> V_18 ) ;
if ( ! F_3 ( & V_2 -> V_21 ) ) {
V_7 = F_4 ( V_2 -> V_21 . V_8 ,
struct V_5 ,
V_9 ) ;
F_35 ( & V_7 -> V_9 , & V_2 -> V_46 ) ;
V_2 -> V_22 -= V_7 -> V_31 ;
V_25 -> V_62 = V_7 ;
V_7 -> V_29 = 0 ;
}
F_11 ( & V_16 -> V_18 ) ;
if ( V_7 == NULL )
goto V_69;
}
V_34 = V_2 -> V_19 -> V_70 ( V_25 , V_7 , V_64 , V_31 ) ;
if ( V_34 < 0 || V_7 -> V_31 == V_7 -> V_29 ) {
V_25 -> V_62 = NULL ;
F_10 ( & V_16 -> V_18 ) ;
F_5 ( & V_7 -> V_9 ) ;
F_11 ( & V_16 -> V_18 ) ;
V_2 -> V_19 -> F_2 ( V_7 ) ;
}
V_69:
F_24 ( & V_16 -> V_44 ) ;
return V_34 ;
}
static T_1
F_36 ( struct V_24 * V_25 , const char T_2 * V_64 , T_3 V_31 , T_4 * V_65 )
{
struct V_16 * V_16 = V_25 -> V_66 . V_67 -> V_68 ;
struct V_1 * V_2 = F_17 ( V_16 ) ;
int V_34 ;
F_22 ( & V_16 -> V_44 ) ;
V_34 = - V_35 ;
if ( V_2 -> V_19 != NULL )
V_34 = V_2 -> V_19 -> V_71 ( V_25 , V_64 , V_31 ) ;
F_24 ( & V_16 -> V_44 ) ;
return V_34 ;
}
static unsigned int
F_37 ( struct V_24 * V_25 , struct V_72 * V_73 )
{
struct V_1 * V_2 ;
unsigned int V_74 = 0 ;
V_2 = F_17 ( V_25 -> V_66 . V_67 -> V_68 ) ;
F_38 ( V_25 , & V_2 -> V_11 , V_73 ) ;
V_74 = V_75 | V_76 ;
if ( V_2 -> V_19 == NULL )
V_74 |= V_77 | V_78 ;
if ( V_25 -> V_62 || ! F_3 ( & V_2 -> V_21 ) )
V_74 |= V_79 | V_80 ;
return V_74 ;
}
static long
F_39 ( struct V_24 * V_25 , unsigned int V_81 , unsigned long V_82 )
{
struct V_16 * V_16 = V_25 -> V_66 . V_67 -> V_68 ;
struct V_1 * V_2 = F_17 ( V_16 ) ;
int V_31 ;
switch ( V_81 ) {
case V_83 :
F_10 ( & V_16 -> V_18 ) ;
if ( V_2 -> V_19 == NULL ) {
F_11 ( & V_16 -> V_18 ) ;
return - V_35 ;
}
V_31 = V_2 -> V_22 ;
if ( V_25 -> V_62 ) {
struct V_5 * V_7 ;
V_7 = V_25 -> V_62 ;
V_31 += V_7 -> V_31 - V_7 -> V_29 ;
}
F_11 ( & V_16 -> V_18 ) ;
return F_40 ( V_31 , ( int T_2 * ) V_82 ) ;
default:
return - V_84 ;
}
}
static int
F_41 ( struct V_85 * V_86 , void * V_87 )
{
struct V_88 * V_89 = V_86 -> V_41 ;
F_42 ( V_86 , L_1 , V_89 -> V_90 ) ;
F_42 ( V_86 , L_2 , V_89 -> V_91 ,
V_89 -> V_92 , V_89 -> V_93 ) ;
F_42 ( V_86 , L_3 , F_43 ( V_89 , V_94 ) ) ;
F_42 ( V_86 , L_4 , F_43 ( V_89 , V_95 ) ) ;
F_42 ( V_86 , L_5 , F_43 ( V_89 , V_96 ) ) ;
return 0 ;
}
static int
F_44 ( struct V_16 * V_16 , struct V_24 * V_24 )
{
struct V_88 * V_89 = NULL ;
int V_97 = F_45 ( V_24 , F_41 , NULL ) ;
if ( ! V_97 ) {
struct V_85 * V_86 = V_24 -> V_62 ;
F_10 ( & V_24 -> V_66 . V_67 -> V_98 ) ;
if ( ! F_46 ( V_24 -> V_66 . V_67 ) )
V_89 = F_17 ( V_16 ) -> V_41 ;
if ( V_89 != NULL && F_47 ( & V_89 -> V_99 ) ) {
F_11 ( & V_24 -> V_66 . V_67 -> V_98 ) ;
V_86 -> V_41 = V_89 ;
} else {
F_11 ( & V_24 -> V_66 . V_67 -> V_98 ) ;
F_48 ( V_16 , V_24 ) ;
V_97 = - V_84 ;
}
}
return V_97 ;
}
static int
F_49 ( struct V_16 * V_16 , struct V_24 * V_24 )
{
struct V_85 * V_86 = V_24 -> V_62 ;
struct V_88 * V_89 = (struct V_88 * ) V_86 -> V_41 ;
if ( V_89 )
F_50 ( V_89 ) ;
return F_48 ( V_16 , V_24 ) ;
}
struct V_100 * F_51 ( void )
{
int V_6 ;
V_6 = F_52 ( & V_101 , & V_102 , & V_103 ) ;
if ( V_6 != 0 )
return F_53 ( V_6 ) ;
return V_102 ;
}
void F_54 ( void )
{
F_55 ( & V_102 , & V_103 ) ;
}
static int F_56 ( const struct V_67 * V_67 )
{
return 1 ;
}
static struct V_16 *
F_57 ( struct V_48 * V_49 , T_5 V_104 )
{
struct V_16 * V_16 = F_58 ( V_49 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_105 = F_59 () ;
V_16 -> V_106 = V_104 ;
V_16 -> V_107 = V_16 -> V_108 = V_16 -> V_109 = V_110 ;
switch ( V_104 & V_111 ) {
case V_112 :
V_16 -> V_113 = & V_114 ;
V_16 -> V_115 = & V_116 ;
F_60 ( V_16 ) ;
default:
break;
}
return V_16 ;
}
static int F_61 ( struct V_16 * V_117 , struct V_67 * V_67 ,
T_5 V_104 ,
const struct V_118 * V_113 ,
void * V_41 )
{
struct V_16 * V_16 ;
F_62 ( V_67 ) ;
V_16 = F_57 ( V_117 -> V_119 , V_104 ) ;
if ( ! V_16 )
goto V_120;
V_16 -> V_105 = F_63 ( V_117 -> V_119 , 100 ) ;
if ( V_113 )
V_16 -> V_113 = V_113 ;
if ( V_41 )
F_20 ( V_16 , V_41 ) ;
F_64 ( V_67 , V_16 ) ;
return 0 ;
V_120:
F_65 ( V_121 L_6 ,
__FILE__ , V_122 , V_67 -> V_123 . V_124 ) ;
F_66 ( V_67 ) ;
return - V_125 ;
}
static int F_67 ( struct V_16 * V_117 , struct V_67 * V_67 ,
T_5 V_104 ,
const struct V_118 * V_113 ,
void * V_41 )
{
int V_6 ;
V_6 = F_61 ( V_117 , V_67 , V_126 | V_104 , V_113 , V_41 ) ;
if ( V_6 )
return V_6 ;
F_68 ( V_117 , V_67 ) ;
return 0 ;
}
static int F_69 ( struct V_16 * V_117 , struct V_67 * V_67 ,
T_5 V_104 ,
const struct V_118 * V_113 ,
void * V_41 )
{
int V_6 ;
V_6 = F_61 ( V_117 , V_67 , V_112 | V_104 , V_113 , V_41 ) ;
if ( V_6 )
return V_6 ;
F_60 ( V_117 ) ;
F_70 ( V_117 , V_67 ) ;
return 0 ;
}
static int F_71 ( struct V_16 * V_117 , struct V_67 * V_67 ,
T_5 V_104 ,
const struct V_118 * V_113 ,
void * V_41 ,
const struct V_42 * V_19 ,
int V_37 )
{
struct V_1 * V_2 ;
int V_6 ;
V_6 = F_61 ( V_117 , V_67 , V_127 | V_104 , V_113 , V_41 ) ;
if ( V_6 )
return V_6 ;
V_2 = F_17 ( V_67 -> V_68 ) ;
V_2 -> V_128 = 1 ;
V_2 -> V_41 = V_41 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_19 = V_19 ;
F_68 ( V_117 , V_67 ) ;
return 0 ;
}
static int F_72 ( struct V_16 * V_117 , struct V_67 * V_67 )
{
int V_97 ;
F_73 ( V_67 ) ;
V_97 = F_74 ( V_117 , V_67 ) ;
F_75 ( V_67 ) ;
F_66 ( V_67 ) ;
return V_97 ;
}
static int F_76 ( struct V_16 * V_117 , struct V_67 * V_67 )
{
int V_97 ;
F_73 ( V_67 ) ;
V_97 = F_77 ( V_117 , V_67 ) ;
F_75 ( V_67 ) ;
F_66 ( V_67 ) ;
return V_97 ;
}
static int F_78 ( struct V_16 * V_117 , struct V_67 * V_67 )
{
struct V_16 * V_16 = V_67 -> V_68 ;
struct V_1 * V_2 = F_17 ( V_16 ) ;
V_2 -> V_128 -- ;
if ( V_2 -> V_128 != 0 )
return 0 ;
F_21 ( V_16 ) ;
return F_76 ( V_117 , V_67 ) ;
}
static struct V_67 * F_79 ( struct V_67 * V_129 ,
struct V_130 * V_124 )
{
struct V_67 * V_67 ;
V_67 = F_80 ( V_129 , V_124 ) ;
if ( ! V_67 ) {
V_67 = F_81 ( V_129 , V_124 ) ;
if ( ! V_67 ) {
V_67 = F_53 ( - V_125 ) ;
goto V_120;
}
}
if ( ! V_67 -> V_68 )
F_82 ( V_67 , & V_131 ) ;
V_120:
return V_67 ;
}
static struct V_67 * F_83 ( struct V_67 * V_129 ,
struct V_130 * V_124 )
{
struct V_67 * V_67 ;
V_67 = F_79 ( V_129 , V_124 ) ;
if ( F_84 ( V_67 ) )
return V_67 ;
if ( V_67 -> V_68 == NULL )
return V_67 ;
F_66 ( V_67 ) ;
return F_53 ( - V_132 ) ;
}
static void F_85 ( struct V_67 * V_129 ,
const struct V_133 * V_134 ,
int V_135 , int V_136 )
{
struct V_16 * V_117 = V_129 -> V_68 ;
struct V_67 * V_67 ;
struct V_130 V_124 ;
int V_137 ;
for ( V_137 = V_135 ; V_137 < V_136 ; V_137 ++ ) {
V_124 . V_124 = V_134 [ V_137 ] . V_124 ;
V_124 . V_31 = strlen ( V_134 [ V_137 ] . V_124 ) ;
V_124 . V_138 = F_86 ( V_124 . V_124 , V_124 . V_31 ) ;
V_67 = F_80 ( V_129 , & V_124 ) ;
if ( V_67 == NULL )
continue;
if ( V_67 -> V_68 == NULL )
goto V_8;
switch ( V_67 -> V_68 -> V_106 & V_111 ) {
default:
F_87 () ;
case V_126 :
F_76 ( V_117 , V_67 ) ;
break;
case V_112 :
F_72 ( V_117 , V_67 ) ;
}
V_8:
F_66 ( V_67 ) ;
}
}
static void F_88 ( struct V_67 * V_129 ,
const struct V_133 * V_134 ,
int V_135 , int V_136 )
{
struct V_16 * V_117 = V_129 -> V_68 ;
F_89 ( & V_117 -> V_44 , V_139 ) ;
F_85 ( V_129 , V_134 , V_135 , V_136 ) ;
F_24 ( & V_117 -> V_44 ) ;
}
static int F_90 ( struct V_67 * V_129 ,
const struct V_133 * V_134 ,
int V_135 , int V_136 ,
void * V_41 )
{
struct V_16 * V_117 = V_129 -> V_68 ;
struct V_67 * V_67 ;
int V_137 , V_6 ;
F_22 ( & V_117 -> V_44 ) ;
for ( V_137 = V_135 ; V_137 < V_136 ; V_137 ++ ) {
struct V_130 V_140 ;
V_140 . V_124 = V_134 [ V_137 ] . V_124 ;
V_140 . V_31 = strlen ( V_134 [ V_137 ] . V_124 ) ;
V_140 . V_138 = F_86 ( V_140 . V_124 , V_140 . V_31 ) ;
V_67 = F_83 ( V_129 , & V_140 ) ;
V_6 = F_91 ( V_67 ) ;
if ( F_84 ( V_67 ) )
goto V_141;
switch ( V_134 [ V_137 ] . V_104 & V_111 ) {
default:
F_87 () ;
case V_126 :
V_6 = F_67 ( V_117 , V_67 ,
V_134 [ V_137 ] . V_104 ,
V_134 [ V_137 ] . V_113 ,
V_41 ) ;
break;
case V_112 :
V_6 = F_69 ( V_117 , V_67 ,
V_134 [ V_137 ] . V_104 ,
NULL ,
V_41 ) ;
}
if ( V_6 != 0 )
goto V_141;
}
F_24 ( & V_117 -> V_44 ) ;
return 0 ;
V_141:
F_85 ( V_129 , V_134 , V_135 , V_136 ) ;
F_24 ( & V_117 -> V_44 ) ;
F_65 ( V_121 L_7 ,
__FILE__ , V_122 , V_129 -> V_123 . V_124 ) ;
return V_6 ;
}
static struct V_67 * F_92 ( struct V_67 * V_129 ,
struct V_130 * V_124 , T_5 V_104 , void * V_41 ,
int (* F_93)( struct V_67 * , void * ) , void * V_142 )
{
struct V_67 * V_67 ;
struct V_16 * V_117 = V_129 -> V_68 ;
int error ;
F_89 ( & V_117 -> V_44 , V_143 ) ;
V_67 = F_83 ( V_129 , V_124 ) ;
if ( F_84 ( V_67 ) )
goto V_36;
error = F_69 ( V_117 , V_67 , V_104 , NULL , V_41 ) ;
if ( error != 0 )
goto V_120;
if ( F_93 != NULL ) {
error = F_93 ( V_67 , V_142 ) ;
if ( error )
goto V_144;
}
V_36:
F_24 ( & V_117 -> V_44 ) ;
return V_67 ;
V_144:
F_72 ( V_117 , V_67 ) ;
V_120:
V_67 = F_53 ( error ) ;
goto V_36;
}
static int F_94 ( struct V_67 * V_67 ,
void (* F_95)( struct V_67 * ) )
{
struct V_67 * V_129 ;
struct V_16 * V_117 ;
int error ;
V_129 = F_96 ( V_67 ) ;
V_117 = V_129 -> V_68 ;
F_89 ( & V_117 -> V_44 , V_143 ) ;
if ( F_95 != NULL )
F_95 ( V_67 ) ;
error = F_72 ( V_117 , V_67 ) ;
F_24 ( & V_117 -> V_44 ) ;
F_66 ( V_129 ) ;
return error ;
}
struct V_67 * F_97 ( struct V_67 * V_129 , const char * V_124 ,
void * V_41 , const struct V_42 * V_19 ,
int V_37 )
{
struct V_67 * V_67 ;
struct V_16 * V_117 = V_129 -> V_68 ;
T_5 V_145 = V_127 | V_146 | V_147 ;
struct V_130 V_140 ;
int V_6 ;
if ( V_19 -> V_70 == NULL )
V_145 &= ~ V_148 ;
if ( V_19 -> V_71 == NULL )
V_145 &= ~ V_149 ;
V_140 . V_124 = V_124 ;
V_140 . V_31 = strlen ( V_124 ) ;
V_140 . V_138 = F_86 ( V_140 . V_124 , V_140 . V_31 ) ,
F_89 ( & V_117 -> V_44 , V_143 ) ;
V_67 = F_79 ( V_129 , & V_140 ) ;
if ( F_84 ( V_67 ) )
goto V_36;
if ( V_67 -> V_68 ) {
struct V_1 * V_2 = F_17 ( V_67 -> V_68 ) ;
if ( V_2 -> V_41 != V_41 ||
V_2 -> V_19 != V_19 ||
V_2 -> V_37 != V_37 ) {
F_66 ( V_67 ) ;
V_6 = - V_150 ;
goto V_120;
}
V_2 -> V_128 ++ ;
goto V_36;
}
V_6 = F_71 ( V_117 , V_67 , V_145 , & V_151 ,
V_41 , V_19 , V_37 ) ;
if ( V_6 )
goto V_120;
V_36:
F_24 ( & V_117 -> V_44 ) ;
return V_67 ;
V_120:
V_67 = F_53 ( V_6 ) ;
F_65 ( V_121 L_8 ,
__FILE__ , V_122 , V_129 -> V_123 . V_124 , V_124 ,
V_6 ) ;
goto V_36;
}
int
F_98 ( struct V_67 * V_67 )
{
struct V_67 * V_129 ;
struct V_16 * V_117 ;
int error = 0 ;
V_129 = F_96 ( V_67 ) ;
V_117 = V_129 -> V_68 ;
F_89 ( & V_117 -> V_44 , V_143 ) ;
error = F_78 ( V_117 , V_67 ) ;
F_24 ( & V_117 -> V_44 ) ;
F_66 ( V_129 ) ;
return error ;
}
static int F_99 ( struct V_67 * V_67 , void * V_41 )
{
return F_90 ( V_67 ,
V_152 , V_153 , V_154 ,
V_41 ) ;
}
static void F_100 ( struct V_67 * V_67 )
{
F_88 ( V_67 , V_152 , V_153 , V_154 ) ;
}
struct V_67 * F_101 ( struct V_67 * V_67 ,
struct V_130 * V_124 ,
struct V_88 * V_155 )
{
return F_92 ( V_67 , V_124 , V_148 | V_156 , NULL ,
F_99 , V_155 ) ;
}
int F_102 ( struct V_67 * V_67 )
{
return F_94 ( V_67 , F_100 ) ;
}
static int F_103 ( struct V_67 * V_67 , void * V_41 )
{
return F_90 ( V_67 ,
V_157 , 0 , 3 ,
V_41 ) ;
}
static void F_104 ( struct V_67 * V_67 )
{
F_88 ( V_67 , V_157 , 0 , 3 ) ;
}
struct V_67 * F_105 ( struct V_67 * V_129 , struct V_130 * V_124 ,
T_6 V_145 , struct V_158 * V_159 )
{
return F_92 ( V_129 , V_124 , V_145 , NULL ,
F_103 , V_159 ) ;
}
void F_106 ( struct V_67 * V_67 )
{
F_94 ( V_67 , F_104 ) ;
}
static int
F_107 ( struct V_48 * V_49 , void * V_28 , int V_160 )
{
struct V_16 * V_16 ;
struct V_67 * V_161 ;
V_49 -> V_162 = V_163 ;
V_49 -> V_164 = V_165 ;
V_49 -> V_166 = V_167 ;
V_49 -> V_168 = & V_169 ;
V_49 -> V_170 = 1 ;
V_16 = F_57 ( V_49 , V_112 | 0755 ) ;
if ( ! V_16 )
return - V_125 ;
V_49 -> V_171 = V_161 = F_108 ( V_16 ) ;
if ( ! V_161 ) {
F_109 ( V_16 ) ;
return - V_125 ;
}
if ( F_90 ( V_161 , V_134 , V_172 , V_173 , NULL ) )
return - V_125 ;
return 0 ;
}
static struct V_67 *
F_110 ( struct V_174 * V_175 ,
int V_37 , const char * V_176 , void * V_28 )
{
return F_111 ( V_175 , V_37 , V_28 , F_107 ) ;
}
static void
F_112 ( void * V_177 )
{
struct V_1 * V_2 = (struct V_1 * ) V_177 ;
F_113 ( & V_2 -> V_17 ) ;
V_2 -> V_41 = NULL ;
V_2 -> V_20 = 0 ;
V_2 -> V_45 = 0 ;
F_28 ( & V_2 -> V_46 ) ;
F_28 ( & V_2 -> V_178 ) ;
F_28 ( & V_2 -> V_21 ) ;
V_2 -> V_22 = 0 ;
F_114 ( & V_2 -> V_11 ) ;
F_115 ( & V_2 -> V_15 ,
F_7 ) ;
V_2 -> V_19 = NULL ;
}
int F_116 ( void )
{
int V_6 ;
V_50 = F_117 ( L_9 ,
sizeof( struct V_1 ) ,
0 , ( V_179 | V_180 |
V_181 ) ,
F_112 ) ;
if ( ! V_50 )
return - V_125 ;
V_6 = F_118 ( & V_101 ) ;
if ( V_6 ) {
F_119 ( V_50 ) ;
return V_6 ;
}
return 0 ;
}
void F_120 ( void )
{
F_119 ( V_50 ) ;
F_121 ( & V_101 ) ;
}
