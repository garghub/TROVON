int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_3 , V_2 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_3 , V_2 ) ;
}
static void F_5 ( T_1 * V_4 , struct V_5 * V_6 ,
void (* F_6)( struct V_7 * ) , int V_8 )
{
struct V_7 * V_9 ;
if ( F_7 ( V_6 ) )
return;
do {
V_9 = F_8 ( V_6 -> V_10 , struct V_7 , V_11 ) ;
F_9 ( & V_9 -> V_11 ) ;
V_9 -> V_12 = V_8 ;
F_6 ( V_9 ) ;
} while ( ! F_7 ( V_6 ) );
if ( V_4 )
F_10 ( V_4 ) ;
}
static void
F_11 ( struct V_13 * V_14 )
{
F_12 ( V_15 ) ;
struct V_16 * V_17 =
F_13 ( V_14 , struct V_16 , V_18 . V_14 ) ;
void (* F_6)( struct V_7 * );
struct V_19 * V_19 ;
F_14 ( & V_17 -> V_20 ) ;
F_6 = V_17 -> V_21 -> F_6 ;
if ( V_17 -> V_22 == 0 ) {
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
}
V_19 = F_16 ( V_17 -> V_19 ) ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( V_19 ? & F_18 ( V_19 -> V_24 ) -> V_4 : NULL ,
& V_15 , F_6 , - V_25 ) ;
F_19 ( V_19 ) ;
}
T_2 F_20 ( struct V_26 * V_27 , struct V_7 * V_9 ,
char T_3 * V_28 , T_4 V_29 )
{
char * V_30 = ( char * ) V_9 -> V_30 + V_9 -> V_31 ;
T_4 V_32 = F_21 ( V_9 -> V_33 - V_9 -> V_31 , V_29 ) ;
unsigned long V_34 ;
V_34 = F_22 ( V_28 , V_30 , V_32 ) ;
if ( V_34 == V_32 ) {
V_9 -> V_12 = - V_35 ;
return - V_35 ;
}
V_32 -= V_34 ;
V_9 -> V_31 += V_32 ;
V_9 -> V_12 = 0 ;
return V_32 ;
}
int
F_23 ( struct V_16 * V_17 , struct V_7 * V_9 )
{
int V_36 = - V_37 ;
struct V_19 * V_19 ;
F_14 ( & V_17 -> V_20 ) ;
if ( V_17 -> V_22 ) {
F_24 ( & V_9 -> V_11 , & V_17 -> V_17 ) ;
V_17 -> V_23 += V_9 -> V_33 ;
V_36 = 0 ;
} else if ( V_17 -> V_38 & V_39 ) {
if ( F_7 ( & V_17 -> V_17 ) )
F_25 ( V_40 ,
& V_17 -> V_18 ,
V_41 ) ;
F_24 ( & V_9 -> V_11 , & V_17 -> V_17 ) ;
V_17 -> V_23 += V_9 -> V_33 ;
V_36 = 0 ;
}
V_19 = F_16 ( V_17 -> V_19 ) ;
F_17 ( & V_17 -> V_20 ) ;
if ( V_19 ) {
F_10 ( & F_18 ( V_19 -> V_24 ) -> V_4 ) ;
F_19 ( V_19 ) ;
}
return V_36 ;
}
static inline void
F_26 ( struct V_42 * V_42 , void * V_43 )
{
F_18 ( V_42 ) -> V_43 = V_43 ;
}
static void
F_27 ( struct V_42 * V_42 )
{
struct V_16 * V_17 = F_18 ( V_42 ) -> V_17 ;
int V_44 ;
F_12 ( V_15 ) ;
F_28 ( & V_42 -> V_45 ) ;
F_14 ( & V_17 -> V_20 ) ;
V_44 = V_17 -> V_22 != 0 || V_17 -> V_46 != 0 ;
V_17 -> V_22 = 0 ;
F_15 ( & V_17 -> V_47 , & V_15 ) ;
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
V_17 -> V_19 = NULL ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( & F_18 ( V_42 ) -> V_4 , & V_15 , V_17 -> V_21 -> F_6 , - V_37 ) ;
V_17 -> V_46 = 0 ;
if ( V_44 && V_17 -> V_21 -> V_48 )
V_17 -> V_21 -> V_48 ( V_42 ) ;
F_29 ( & V_17 -> V_18 ) ;
F_26 ( V_42 , NULL ) ;
F_18 ( V_42 ) -> V_17 = NULL ;
F_30 ( & V_42 -> V_45 ) ;
}
static struct V_42 *
F_31 ( struct V_49 * V_50 )
{
struct V_51 * V_52 ;
V_52 = (struct V_51 * ) F_32 ( V_53 , V_54 ) ;
if ( ! V_52 )
return NULL ;
return & V_52 -> V_55 ;
}
static void
F_33 ( struct V_56 * V_6 )
{
struct V_42 * V_42 = F_13 ( V_6 , struct V_42 , V_57 ) ;
F_34 ( V_53 , F_18 ( V_42 ) ) ;
}
static void
F_35 ( struct V_42 * V_42 )
{
F_36 ( & V_42 -> V_57 , F_33 ) ;
}
static int
F_37 ( struct V_42 * V_42 , struct V_26 * V_27 )
{
struct V_58 * V_58 = V_42 -> V_59 -> V_60 ;
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
struct V_16 * V_17 ;
int V_64 ;
int V_36 = - V_65 ;
F_28 ( & V_42 -> V_45 ) ;
V_62 -> V_66 = 1 ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL )
goto V_67;
V_64 = V_17 -> V_22 == 0 && V_17 -> V_46 == 0 ;
if ( V_64 && V_17 -> V_21 -> V_68 ) {
V_36 = V_17 -> V_21 -> V_68 ( V_42 ) ;
if ( V_36 )
goto V_67;
}
if ( V_27 -> V_69 & V_70 )
V_17 -> V_22 ++ ;
if ( V_27 -> V_69 & V_71 )
V_17 -> V_46 ++ ;
V_36 = 0 ;
V_67:
F_30 ( & V_42 -> V_45 ) ;
return V_36 ;
}
static int
F_39 ( struct V_42 * V_42 , struct V_26 * V_27 )
{
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_72 ;
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL )
goto V_67;
V_9 = V_27 -> V_73 ;
if ( V_9 != NULL ) {
F_14 ( & V_17 -> V_20 ) ;
V_9 -> V_12 = - V_74 ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
if ( V_27 -> V_69 & V_71 )
V_17 -> V_46 -- ;
if ( V_27 -> V_69 & V_70 ) {
V_17 -> V_22 -- ;
if ( V_17 -> V_22 == 0 ) {
F_12 ( V_15 ) ;
F_14 ( & V_17 -> V_20 ) ;
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( & F_18 ( V_42 ) -> V_4 , & V_15 ,
V_17 -> V_21 -> F_6 , - V_74 ) ;
}
}
V_72 = V_17 -> V_46 == 0 && V_17 -> V_22 == 0 ;
if ( V_72 && V_17 -> V_21 -> V_48 )
V_17 -> V_21 -> V_48 ( V_42 ) ;
V_67:
F_30 ( & V_42 -> V_45 ) ;
return 0 ;
}
static T_2
F_40 ( struct V_26 * V_27 , char T_3 * V_75 , T_4 V_33 , T_5 * V_76 )
{
struct V_42 * V_42 = F_41 ( V_27 ) ;
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_36 = 0 ;
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL ) {
V_36 = - V_37 ;
goto V_77;
}
V_9 = V_27 -> V_73 ;
if ( V_9 == NULL ) {
F_14 ( & V_17 -> V_20 ) ;
if ( ! F_7 ( & V_17 -> V_17 ) ) {
V_9 = F_8 ( V_17 -> V_17 . V_10 ,
struct V_7 ,
V_11 ) ;
F_42 ( & V_9 -> V_11 , & V_17 -> V_47 ) ;
V_17 -> V_23 -= V_9 -> V_33 ;
V_27 -> V_73 = V_9 ;
V_9 -> V_31 = 0 ;
}
F_17 ( & V_17 -> V_20 ) ;
if ( V_9 == NULL )
goto V_77;
}
V_36 = V_17 -> V_21 -> V_78 ( V_27 , V_9 , V_75 , V_33 ) ;
if ( V_36 < 0 || V_9 -> V_33 == V_9 -> V_31 ) {
V_27 -> V_73 = NULL ;
F_14 ( & V_17 -> V_20 ) ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
V_77:
F_30 ( & V_42 -> V_45 ) ;
return V_36 ;
}
static T_2
F_43 ( struct V_26 * V_27 , const char T_3 * V_75 , T_4 V_33 , T_5 * V_76 )
{
struct V_42 * V_42 = F_41 ( V_27 ) ;
int V_36 ;
F_28 ( & V_42 -> V_45 ) ;
V_36 = - V_37 ;
if ( F_18 ( V_42 ) -> V_17 != NULL )
V_36 = F_18 ( V_42 ) -> V_17 -> V_21 -> V_79 ( V_27 , V_75 , V_33 ) ;
F_30 ( & V_42 -> V_45 ) ;
return V_36 ;
}
static unsigned int
F_44 ( struct V_26 * V_27 , struct V_80 * V_81 )
{
struct V_42 * V_42 = F_41 ( V_27 ) ;
struct V_51 * V_52 = F_18 ( V_42 ) ;
unsigned int V_82 = V_83 | V_84 ;
F_45 ( V_27 , & V_52 -> V_4 , V_81 ) ;
F_28 ( & V_42 -> V_45 ) ;
if ( V_52 -> V_17 == NULL )
V_82 |= V_85 | V_86 ;
else if ( V_27 -> V_73 || ! F_7 ( & V_52 -> V_17 -> V_17 ) )
V_82 |= V_87 | V_88 ;
F_30 ( & V_42 -> V_45 ) ;
return V_82 ;
}
static long
F_46 ( struct V_26 * V_27 , unsigned int V_89 , unsigned long V_90 )
{
struct V_42 * V_42 = F_41 ( V_27 ) ;
struct V_16 * V_17 ;
int V_33 ;
switch ( V_89 ) {
case V_91 :
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL ) {
F_30 ( & V_42 -> V_45 ) ;
return - V_37 ;
}
F_14 ( & V_17 -> V_20 ) ;
V_33 = V_17 -> V_23 ;
if ( V_27 -> V_73 ) {
struct V_7 * V_9 ;
V_9 = V_27 -> V_73 ;
V_33 += V_9 -> V_33 - V_9 -> V_31 ;
}
F_17 ( & V_17 -> V_20 ) ;
F_30 ( & V_42 -> V_45 ) ;
return F_47 ( V_33 , ( int T_3 * ) V_90 ) ;
default:
return - V_92 ;
}
}
static int
F_48 ( struct V_93 * V_94 , void * V_95 )
{
struct V_96 * V_97 = V_94 -> V_43 ;
F_49 () ;
F_50 ( V_94 , L_1 ,
F_51 ( V_97 -> V_98 ) -> V_99 ) ;
F_50 ( V_94 , L_2 , V_97 -> V_100 -> V_101 ,
V_97 -> V_102 , V_97 -> V_103 ) ;
F_50 ( V_94 , L_3 , F_52 ( V_97 , V_104 ) ) ;
F_50 ( V_94 , L_4 , F_52 ( V_97 , V_105 ) ) ;
F_50 ( V_94 , L_5 , F_52 ( V_97 , V_106 ) ) ;
F_53 () ;
return 0 ;
}
static int
F_54 ( struct V_42 * V_42 , struct V_26 * V_26 )
{
struct V_96 * V_97 = NULL ;
int V_107 = F_55 ( V_26 , F_48 , NULL ) ;
if ( ! V_107 ) {
struct V_93 * V_94 = V_26 -> V_73 ;
F_14 ( & V_26 -> V_108 . V_19 -> V_109 ) ;
if ( ! F_56 ( V_26 -> V_108 . V_19 ) )
V_97 = F_18 ( V_42 ) -> V_43 ;
if ( V_97 != NULL && F_57 ( & V_97 -> V_110 ) ) {
F_17 ( & V_26 -> V_108 . V_19 -> V_109 ) ;
V_94 -> V_43 = V_97 ;
} else {
F_17 ( & V_26 -> V_108 . V_19 -> V_109 ) ;
F_58 ( V_42 , V_26 ) ;
V_107 = - V_92 ;
}
}
return V_107 ;
}
static int
F_59 ( struct V_42 * V_42 , struct V_26 * V_26 )
{
struct V_93 * V_94 = V_26 -> V_73 ;
struct V_96 * V_97 = (struct V_96 * ) V_94 -> V_43 ;
if ( V_97 )
F_60 ( V_97 ) ;
return F_58 ( V_42 , V_26 ) ;
}
static struct V_42 *
F_61 ( struct V_49 * V_50 , T_6 V_111 )
{
struct V_42 * V_42 = F_62 ( V_50 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_112 = F_63 () ;
V_42 -> V_113 = V_111 ;
V_42 -> V_114 = V_42 -> V_115 = V_42 -> V_116 = V_117 ;
switch ( V_111 & V_118 ) {
case V_119 :
V_42 -> V_120 = & V_121 ;
V_42 -> V_122 = & V_123 ;
F_64 ( V_42 ) ;
default:
break;
}
return V_42 ;
}
static int F_65 ( struct V_42 * V_124 , struct V_19 * V_19 ,
T_6 V_111 ,
const struct V_125 * V_120 ,
void * V_43 )
{
struct V_42 * V_42 ;
F_66 ( V_19 ) ;
V_42 = F_61 ( V_124 -> V_59 , V_111 ) ;
if ( ! V_42 )
goto V_126;
V_42 -> V_112 = F_67 ( V_124 -> V_59 , 100 ) ;
if ( V_120 )
V_42 -> V_120 = V_120 ;
if ( V_43 )
F_26 ( V_42 , V_43 ) ;
F_68 ( V_19 , V_42 ) ;
return 0 ;
V_126:
F_69 ( V_127 L_6 ,
__FILE__ , V_128 , V_19 ) ;
F_19 ( V_19 ) ;
return - V_129 ;
}
static int F_70 ( struct V_42 * V_124 , struct V_19 * V_19 ,
T_6 V_111 ,
const struct V_125 * V_120 ,
void * V_43 )
{
int V_8 ;
V_8 = F_65 ( V_124 , V_19 , V_130 | V_111 , V_120 , V_43 ) ;
if ( V_8 )
return V_8 ;
F_71 ( V_124 , V_19 ) ;
return 0 ;
}
static int F_72 ( struct V_42 * V_124 , struct V_19 * V_19 ,
T_6 V_111 ,
const struct V_125 * V_120 ,
void * V_43 )
{
int V_8 ;
V_8 = F_65 ( V_124 , V_19 , V_119 | V_111 , V_120 , V_43 ) ;
if ( V_8 )
return V_8 ;
F_64 ( V_124 ) ;
F_73 ( V_124 , V_19 ) ;
return 0 ;
}
static void
F_74 ( struct V_16 * V_17 )
{
V_17 -> V_22 = 0 ;
V_17 -> V_46 = 0 ;
F_75 ( & V_17 -> V_47 ) ;
F_75 ( & V_17 -> V_131 ) ;
F_75 ( & V_17 -> V_17 ) ;
V_17 -> V_23 = 0 ;
F_76 ( & V_17 -> V_18 ,
F_11 ) ;
V_17 -> V_21 = NULL ;
F_77 ( & V_17 -> V_20 ) ;
V_17 -> V_19 = NULL ;
}
void F_78 ( struct V_16 * V_17 )
{
F_79 ( V_17 ) ;
}
struct V_16 * F_80 ( const struct V_132 * V_21 , int V_38 )
{
struct V_16 * V_17 ;
V_17 = F_81 ( sizeof( struct V_16 ) , V_54 ) ;
if ( ! V_17 )
return F_82 ( - V_129 ) ;
F_74 ( V_17 ) ;
V_17 -> V_21 = V_21 ;
V_17 -> V_38 = V_38 ;
return V_17 ;
}
static int F_83 ( struct V_42 * V_124 , struct V_19 * V_19 ,
T_6 V_111 ,
const struct V_125 * V_120 ,
void * V_43 ,
struct V_16 * V_17 )
{
struct V_51 * V_52 ;
int V_8 ;
V_8 = F_65 ( V_124 , V_19 , V_133 | V_111 , V_120 , V_43 ) ;
if ( V_8 )
return V_8 ;
V_52 = F_18 ( V_19 -> V_24 ) ;
V_52 -> V_43 = V_43 ;
V_52 -> V_17 = V_17 ;
F_71 ( V_124 , V_19 ) ;
return 0 ;
}
static int F_84 ( struct V_42 * V_124 , struct V_19 * V_19 )
{
int V_107 ;
F_16 ( V_19 ) ;
V_107 = F_85 ( V_124 , V_19 ) ;
F_86 ( V_19 ) ;
F_19 ( V_19 ) ;
return V_107 ;
}
int F_87 ( struct V_19 * V_19 )
{
struct V_19 * V_134 ;
struct V_42 * V_124 ;
int error ;
V_134 = F_88 ( V_19 ) ;
V_124 = V_134 -> V_24 ;
F_89 ( & V_124 -> V_45 , V_135 ) ;
error = F_84 ( V_124 , V_19 ) ;
F_30 ( & V_124 -> V_45 ) ;
F_19 ( V_134 ) ;
return error ;
}
static int F_90 ( struct V_42 * V_124 , struct V_19 * V_19 )
{
int V_107 ;
F_16 ( V_19 ) ;
V_107 = F_91 ( V_124 , V_19 ) ;
F_86 ( V_19 ) ;
F_19 ( V_19 ) ;
return V_107 ;
}
static int F_92 ( struct V_42 * V_124 , struct V_19 * V_19 )
{
struct V_42 * V_42 = V_19 -> V_24 ;
F_27 ( V_42 ) ;
return F_90 ( V_124 , V_19 ) ;
}
static struct V_19 * F_93 ( struct V_19 * V_134 ,
const char * V_101 )
{
struct V_136 V_137 = F_94 ( V_101 , strlen ( V_101 ) ) ;
struct V_19 * V_19 = F_95 ( V_134 , & V_137 ) ;
if ( ! V_19 ) {
V_19 = F_96 ( V_134 , & V_137 ) ;
if ( ! V_19 )
return F_82 ( - V_129 ) ;
}
if ( V_19 -> V_24 == NULL )
return V_19 ;
F_19 ( V_19 ) ;
return F_82 ( - V_138 ) ;
}
static void F_97 ( struct V_19 * V_134 ,
const struct V_139 * V_140 ,
int V_141 , int V_142 )
{
struct V_42 * V_124 = V_134 -> V_24 ;
struct V_19 * V_19 ;
struct V_136 V_101 ;
int V_143 ;
for ( V_143 = V_141 ; V_143 < V_142 ; V_143 ++ ) {
V_101 . V_101 = V_140 [ V_143 ] . V_101 ;
V_101 . V_33 = strlen ( V_140 [ V_143 ] . V_101 ) ;
V_19 = F_95 ( V_134 , & V_101 ) ;
if ( V_19 == NULL )
continue;
if ( V_19 -> V_24 == NULL )
goto V_10;
switch ( V_19 -> V_24 -> V_113 & V_118 ) {
default:
F_98 () ;
case V_130 :
F_90 ( V_124 , V_19 ) ;
break;
case V_119 :
F_84 ( V_124 , V_19 ) ;
}
V_10:
F_19 ( V_19 ) ;
}
}
static void F_99 ( struct V_19 * V_134 ,
const struct V_139 * V_140 ,
int V_141 , int V_142 )
{
struct V_42 * V_124 = V_134 -> V_24 ;
F_89 ( & V_124 -> V_45 , V_144 ) ;
F_97 ( V_134 , V_140 , V_141 , V_142 ) ;
F_30 ( & V_124 -> V_45 ) ;
}
static int F_100 ( struct V_19 * V_134 ,
const struct V_139 * V_140 ,
int V_141 , int V_142 ,
void * V_43 )
{
struct V_42 * V_124 = V_134 -> V_24 ;
struct V_19 * V_19 ;
int V_143 , V_8 ;
F_28 ( & V_124 -> V_45 ) ;
for ( V_143 = V_141 ; V_143 < V_142 ; V_143 ++ ) {
V_19 = F_93 ( V_134 , V_140 [ V_143 ] . V_101 ) ;
V_8 = F_101 ( V_19 ) ;
if ( F_102 ( V_19 ) )
goto V_145;
switch ( V_140 [ V_143 ] . V_111 & V_118 ) {
default:
F_98 () ;
case V_130 :
V_8 = F_70 ( V_124 , V_19 ,
V_140 [ V_143 ] . V_111 ,
V_140 [ V_143 ] . V_120 ,
V_43 ) ;
break;
case V_119 :
V_8 = F_72 ( V_124 , V_19 ,
V_140 [ V_143 ] . V_111 ,
NULL ,
V_43 ) ;
}
if ( V_8 != 0 )
goto V_145;
}
F_30 ( & V_124 -> V_45 ) ;
return 0 ;
V_145:
F_97 ( V_134 , V_140 , V_141 , V_142 ) ;
F_30 ( & V_124 -> V_45 ) ;
F_69 ( V_127 L_7 ,
__FILE__ , V_128 , V_134 ) ;
return V_8 ;
}
static struct V_19 * F_103 ( struct V_19 * V_134 ,
const char * V_101 , T_6 V_111 , void * V_43 ,
int (* F_104)( struct V_19 * , void * ) , void * V_146 )
{
struct V_19 * V_19 ;
struct V_42 * V_124 = V_134 -> V_24 ;
int error ;
F_89 ( & V_124 -> V_45 , V_135 ) ;
V_19 = F_93 ( V_134 , V_101 ) ;
if ( F_102 ( V_19 ) )
goto V_67;
error = F_72 ( V_124 , V_19 , V_111 , NULL , V_43 ) ;
if ( error != 0 )
goto V_126;
if ( F_104 != NULL ) {
error = F_104 ( V_19 , V_146 ) ;
if ( error )
goto V_147;
}
V_67:
F_30 ( & V_124 -> V_45 ) ;
return V_19 ;
V_147:
F_84 ( V_124 , V_19 ) ;
V_126:
V_19 = F_82 ( error ) ;
goto V_67;
}
static int F_105 ( struct V_19 * V_19 ,
void (* F_106)( struct V_19 * ) )
{
struct V_19 * V_134 ;
struct V_42 * V_124 ;
int error ;
V_134 = F_88 ( V_19 ) ;
V_124 = V_134 -> V_24 ;
F_89 ( & V_124 -> V_45 , V_135 ) ;
if ( F_106 != NULL )
F_106 ( V_19 ) ;
error = F_84 ( V_124 , V_19 ) ;
F_30 ( & V_124 -> V_45 ) ;
F_19 ( V_134 ) ;
return error ;
}
struct V_19 * F_107 ( struct V_19 * V_134 , const char * V_101 ,
void * V_43 , struct V_16 * V_17 )
{
struct V_19 * V_19 ;
struct V_42 * V_124 = V_134 -> V_24 ;
T_6 V_148 = V_133 | V_149 | V_150 ;
int V_8 ;
if ( V_17 -> V_21 -> V_78 == NULL )
V_148 &= ~ V_151 ;
if ( V_17 -> V_21 -> V_79 == NULL )
V_148 &= ~ V_152 ;
F_89 ( & V_124 -> V_45 , V_135 ) ;
V_19 = F_93 ( V_134 , V_101 ) ;
if ( F_102 ( V_19 ) )
goto V_67;
V_8 = F_83 ( V_124 , V_19 , V_148 , & V_153 ,
V_43 , V_17 ) ;
if ( V_8 )
goto V_126;
V_67:
F_30 ( & V_124 -> V_45 ) ;
return V_19 ;
V_126:
V_19 = F_82 ( V_8 ) ;
F_69 ( V_127 L_8 ,
__FILE__ , V_128 , V_134 , V_101 ,
V_8 ) ;
goto V_67;
}
int
F_108 ( struct V_19 * V_19 )
{
struct V_19 * V_134 ;
struct V_42 * V_124 ;
int error = 0 ;
V_134 = F_88 ( V_19 ) ;
V_124 = V_134 -> V_24 ;
F_89 ( & V_124 -> V_45 , V_135 ) ;
error = F_92 ( V_124 , V_19 ) ;
F_30 ( & V_124 -> V_45 ) ;
F_19 ( V_134 ) ;
return error ;
}
void F_109 ( struct V_154 * V_155 )
{
F_75 ( & V_155 -> V_156 ) ;
V_155 -> V_157 = NULL ;
}
void F_110 ( struct V_158 * V_159 ,
const struct V_160 * V_161 ,
void * V_162 )
{
F_75 ( & V_159 -> V_163 ) ;
V_159 -> V_161 = V_161 ;
V_159 -> V_162 = V_162 ;
}
static int
F_111 ( struct V_58 * V_58 ,
struct V_154 * V_155 ,
struct V_158 * V_159 )
{
int V_107 = 0 ;
if ( V_155 -> V_157 )
V_107 = V_159 -> V_161 -> V_164 ( V_155 -> V_157 , V_159 ) ;
if ( V_107 == 0 )
F_24 ( & V_159 -> V_163 , & V_155 -> V_156 ) ;
return V_107 ;
}
static void
F_112 ( struct V_58 * V_58 ,
struct V_154 * V_155 ,
struct V_158 * V_159 )
{
if ( V_155 -> V_157 )
V_159 -> V_161 -> V_165 ( V_155 -> V_157 , V_159 ) ;
F_9 ( & V_159 -> V_163 ) ;
}
int
F_113 ( struct V_58 * V_58 ,
struct V_154 * V_155 ,
struct V_158 * V_159 )
{
int V_107 = 0 ;
if ( F_7 ( & V_159 -> V_163 ) ) {
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_28 ( & V_62 -> V_166 ) ;
V_107 = F_111 ( V_58 , V_155 , V_159 ) ;
F_30 ( & V_62 -> V_166 ) ;
}
return V_107 ;
}
void
F_114 ( struct V_58 * V_58 ,
struct V_154 * V_155 ,
struct V_158 * V_159 )
{
if ( ! F_7 ( & V_159 -> V_163 ) ) {
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_28 ( & V_62 -> V_166 ) ;
F_112 ( V_58 , V_155 , V_159 ) ;
F_30 ( & V_62 -> V_166 ) ;
}
}
static void
F_115 ( struct V_154 * V_155 )
{
struct V_158 * V_159 ;
struct V_19 * V_124 = V_155 -> V_157 ;
F_116 (pdo, &pdh->pdh_entries, pdo_head)
V_159 -> V_161 -> V_164 ( V_124 , V_159 ) ;
}
static void
F_117 ( struct V_154 * V_155 )
{
struct V_158 * V_159 ;
struct V_19 * V_124 = V_155 -> V_157 ;
F_116 (pdo, &pdh->pdh_entries, pdo_head)
V_159 -> V_161 -> V_165 ( V_124 , V_159 ) ;
}
static int F_118 ( struct V_19 * V_19 , void * V_43 )
{
return F_100 ( V_19 ,
V_167 , V_168 , V_169 ,
V_43 ) ;
}
static void F_119 ( struct V_19 * V_19 )
{
F_99 ( V_19 , V_167 , V_168 , V_169 ) ;
}
struct V_19 * F_120 ( struct V_19 * V_19 ,
const char * V_101 ,
struct V_96 * V_170 )
{
struct V_19 * V_107 ;
V_107 = F_103 ( V_19 , V_101 , V_151 | V_171 , NULL ,
F_118 , V_170 ) ;
if ( ! F_102 ( V_107 ) ) {
V_170 -> V_172 . V_157 = V_107 ;
F_115 ( & V_170 -> V_172 ) ;
}
return V_107 ;
}
int F_121 ( struct V_96 * V_170 )
{
struct V_19 * V_19 = V_170 -> V_172 . V_157 ;
if ( V_19 == NULL )
return 0 ;
F_117 ( & V_170 -> V_172 ) ;
V_170 -> V_172 . V_157 = NULL ;
return F_105 ( V_19 , F_119 ) ;
}
static int F_122 ( struct V_19 * V_19 , void * V_43 )
{
return F_100 ( V_19 ,
V_173 , 0 , 3 ,
V_43 ) ;
}
static void F_123 ( struct V_19 * V_19 )
{
F_99 ( V_19 , V_173 , 0 , 3 ) ;
}
struct V_19 * F_124 ( struct V_19 * V_134 , const char * V_101 ,
T_6 V_148 , struct V_174 * V_175 )
{
return F_103 ( V_134 , V_101 , V_148 , NULL ,
F_122 , V_175 ) ;
}
void F_125 ( struct V_19 * V_19 )
{
F_105 ( V_19 , F_123 ) ;
}
struct V_19 * F_126 ( const struct V_49 * V_50 ,
const unsigned char * V_176 )
{
struct V_136 V_124 = F_94 ( V_176 , strlen ( V_176 ) ) ;
return F_95 ( V_50 -> V_177 , & V_124 ) ;
}
void F_127 ( struct V_58 * V_58 )
{
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_128 ( & V_62 -> V_166 ) ;
V_62 -> V_66 = 1 ;
V_62 -> V_178 = - 1 ;
}
struct V_49 * F_129 ( const struct V_58 * V_58 )
{
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_28 ( & V_62 -> V_166 ) ;
if ( V_62 -> V_179 )
return V_62 -> V_179 ;
F_30 ( & V_62 -> V_166 ) ;
return NULL ;
}
void F_130 ( const struct V_58 * V_58 )
{
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_131 ( V_62 -> V_179 == NULL ) ;
F_30 ( & V_62 -> V_166 ) ;
}
static int
F_132 ( struct V_49 * V_50 , void * V_30 , int V_180 )
{
struct V_42 * V_42 ;
struct V_19 * V_181 ;
struct V_58 * V_58 = V_30 ;
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
int V_8 ;
V_50 -> V_182 = V_183 ;
V_50 -> V_184 = V_185 ;
V_50 -> V_186 = V_187 ;
V_50 -> V_188 = & V_189 ;
V_50 -> V_190 = & V_191 ;
V_50 -> V_192 = 1 ;
V_42 = F_61 ( V_50 , V_119 | V_151 | V_171 ) ;
V_50 -> V_177 = V_181 = F_133 ( V_42 ) ;
if ( ! V_181 )
return - V_129 ;
if ( F_100 ( V_181 , V_140 , V_193 , V_194 , NULL ) )
return - V_129 ;
F_134 ( L_9 ,
V_58 , F_135 ( V_58 ) ) ;
F_28 ( & V_62 -> V_166 ) ;
V_62 -> V_179 = V_50 ;
V_8 = F_136 ( & V_3 ,
V_195 ,
V_50 ) ;
if ( V_8 )
goto V_196;
V_50 -> V_60 = F_137 ( V_58 ) ;
F_30 ( & V_62 -> V_166 ) ;
return 0 ;
V_196:
F_136 ( & V_3 ,
V_197 ,
V_50 ) ;
V_62 -> V_179 = NULL ;
F_97 ( V_181 , V_140 , V_193 , V_194 ) ;
F_30 ( & V_62 -> V_166 ) ;
return V_8 ;
}
static struct V_19 *
F_138 ( struct V_198 * V_199 ,
int V_38 , const char * V_200 , void * V_30 )
{
return F_139 ( V_199 , V_38 , V_201 -> V_202 -> V_203 , F_132 ) ;
}
static void F_140 ( struct V_49 * V_50 )
{
struct V_58 * V_58 = V_50 -> V_60 ;
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_28 ( & V_62 -> V_166 ) ;
if ( V_62 -> V_179 != V_50 ) {
F_30 ( & V_62 -> V_166 ) ;
goto V_67;
}
V_62 -> V_179 = NULL ;
F_134 ( L_10 ,
V_58 , F_135 ( V_58 ) ) ;
F_136 ( & V_3 ,
V_197 ,
V_50 ) ;
F_30 ( & V_62 -> V_166 ) ;
F_141 ( V_58 ) ;
V_67:
F_142 ( V_50 ) ;
}
static void
F_143 ( void * V_204 )
{
struct V_51 * V_52 = (struct V_51 * ) V_204 ;
F_144 ( & V_52 -> V_55 ) ;
V_52 -> V_43 = NULL ;
V_52 -> V_17 = NULL ;
F_145 ( & V_52 -> V_4 ) ;
}
int F_146 ( void )
{
int V_8 ;
V_53 = F_147 ( L_11 ,
sizeof( struct V_51 ) ,
0 , ( V_205 | V_206 |
V_207 ) ,
F_143 ) ;
if ( ! V_53 )
return - V_129 ;
V_8 = F_148 () ;
if ( V_8 )
goto V_208;
V_8 = F_149 ( & V_209 ) ;
if ( V_8 )
goto V_210;
return 0 ;
V_210:
F_150 () ;
V_208:
F_151 ( V_53 ) ;
return V_8 ;
}
void F_152 ( void )
{
F_150 () ;
F_151 ( V_53 ) ;
F_153 ( & V_209 ) ;
}
