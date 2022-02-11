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
F_5 ( V_19 ? & F_18 ( F_19 ( V_19 ) ) -> V_4 : NULL ,
& V_15 , F_6 , - V_24 ) ;
F_20 ( V_19 ) ;
}
T_2 F_21 ( struct V_25 * V_26 , struct V_7 * V_9 ,
char T_3 * V_27 , T_4 V_28 )
{
char * V_29 = ( char * ) V_9 -> V_29 + V_9 -> V_30 ;
T_4 V_31 = F_22 ( V_9 -> V_32 - V_9 -> V_30 , V_28 ) ;
unsigned long V_33 ;
V_33 = F_23 ( V_27 , V_29 , V_31 ) ;
if ( V_33 == V_31 ) {
V_9 -> V_12 = - V_34 ;
return - V_34 ;
}
V_31 -= V_33 ;
V_9 -> V_30 += V_31 ;
V_9 -> V_12 = 0 ;
return V_31 ;
}
int
F_24 ( struct V_16 * V_17 , struct V_7 * V_9 )
{
int V_35 = - V_36 ;
struct V_19 * V_19 ;
F_14 ( & V_17 -> V_20 ) ;
if ( V_17 -> V_22 ) {
F_25 ( & V_9 -> V_11 , & V_17 -> V_17 ) ;
V_17 -> V_23 += V_9 -> V_32 ;
V_35 = 0 ;
} else if ( V_17 -> V_37 & V_38 ) {
if ( F_7 ( & V_17 -> V_17 ) )
F_26 ( V_39 ,
& V_17 -> V_18 ,
V_40 ) ;
F_25 ( & V_9 -> V_11 , & V_17 -> V_17 ) ;
V_17 -> V_23 += V_9 -> V_32 ;
V_35 = 0 ;
}
V_19 = F_16 ( V_17 -> V_19 ) ;
F_17 ( & V_17 -> V_20 ) ;
if ( V_19 ) {
F_10 ( & F_18 ( F_19 ( V_19 ) ) -> V_4 ) ;
F_20 ( V_19 ) ;
}
return V_35 ;
}
static inline void
F_27 ( struct V_41 * V_41 , void * V_42 )
{
F_18 ( V_41 ) -> V_42 = V_42 ;
}
static void
F_28 ( struct V_41 * V_41 )
{
struct V_16 * V_17 = F_18 ( V_41 ) -> V_17 ;
int V_43 ;
F_12 ( V_15 ) ;
F_29 ( & V_41 -> V_44 ) ;
F_14 ( & V_17 -> V_20 ) ;
V_43 = V_17 -> V_22 != 0 || V_17 -> V_45 != 0 ;
V_17 -> V_22 = 0 ;
F_15 ( & V_17 -> V_46 , & V_15 ) ;
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
V_17 -> V_19 = NULL ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( & F_18 ( V_41 ) -> V_4 , & V_15 , V_17 -> V_21 -> F_6 , - V_36 ) ;
V_17 -> V_45 = 0 ;
if ( V_43 && V_17 -> V_21 -> V_47 )
V_17 -> V_21 -> V_47 ( V_41 ) ;
F_30 ( & V_17 -> V_18 ) ;
F_27 ( V_41 , NULL ) ;
F_18 ( V_41 ) -> V_17 = NULL ;
F_31 ( & V_41 -> V_44 ) ;
}
static struct V_41 *
F_32 ( struct V_48 * V_49 )
{
struct V_50 * V_51 ;
V_51 = F_33 ( V_52 , V_53 ) ;
if ( ! V_51 )
return NULL ;
return & V_51 -> V_54 ;
}
static void
F_34 ( struct V_55 * V_6 )
{
struct V_41 * V_41 = F_13 ( V_6 , struct V_41 , V_56 ) ;
F_35 ( V_52 , F_18 ( V_41 ) ) ;
}
static void
F_36 ( struct V_41 * V_41 )
{
F_37 ( & V_41 -> V_56 , F_34 ) ;
}
static int
F_38 ( struct V_41 * V_41 , struct V_25 * V_26 )
{
struct V_16 * V_17 ;
int V_57 ;
int V_35 = - V_58 ;
F_29 ( & V_41 -> V_44 ) ;
V_17 = F_18 ( V_41 ) -> V_17 ;
if ( V_17 == NULL )
goto V_59;
V_57 = V_17 -> V_22 == 0 && V_17 -> V_45 == 0 ;
if ( V_57 && V_17 -> V_21 -> V_60 ) {
V_35 = V_17 -> V_21 -> V_60 ( V_41 ) ;
if ( V_35 )
goto V_59;
}
if ( V_26 -> V_61 & V_62 )
V_17 -> V_22 ++ ;
if ( V_26 -> V_61 & V_63 )
V_17 -> V_45 ++ ;
V_35 = 0 ;
V_59:
F_31 ( & V_41 -> V_44 ) ;
return V_35 ;
}
static int
F_39 ( struct V_41 * V_41 , struct V_25 * V_26 )
{
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_64 ;
F_29 ( & V_41 -> V_44 ) ;
V_17 = F_18 ( V_41 ) -> V_17 ;
if ( V_17 == NULL )
goto V_59;
V_9 = V_26 -> V_65 ;
if ( V_9 != NULL ) {
F_14 ( & V_17 -> V_20 ) ;
V_9 -> V_12 = - V_66 ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
if ( V_26 -> V_61 & V_63 )
V_17 -> V_45 -- ;
if ( V_26 -> V_61 & V_62 ) {
V_17 -> V_22 -- ;
if ( V_17 -> V_22 == 0 ) {
F_12 ( V_15 ) ;
F_14 ( & V_17 -> V_20 ) ;
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( & F_18 ( V_41 ) -> V_4 , & V_15 ,
V_17 -> V_21 -> F_6 , - V_66 ) ;
}
}
V_64 = V_17 -> V_45 == 0 && V_17 -> V_22 == 0 ;
if ( V_64 && V_17 -> V_21 -> V_47 )
V_17 -> V_21 -> V_47 ( V_41 ) ;
V_59:
F_31 ( & V_41 -> V_44 ) ;
return 0 ;
}
static T_2
F_40 ( struct V_25 * V_26 , char T_3 * V_67 , T_4 V_32 , T_5 * V_68 )
{
struct V_41 * V_41 = F_41 ( V_26 ) ;
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_35 = 0 ;
F_29 ( & V_41 -> V_44 ) ;
V_17 = F_18 ( V_41 ) -> V_17 ;
if ( V_17 == NULL ) {
V_35 = - V_36 ;
goto V_69;
}
V_9 = V_26 -> V_65 ;
if ( V_9 == NULL ) {
F_14 ( & V_17 -> V_20 ) ;
if ( ! F_7 ( & V_17 -> V_17 ) ) {
V_9 = F_8 ( V_17 -> V_17 . V_10 ,
struct V_7 ,
V_11 ) ;
F_42 ( & V_9 -> V_11 , & V_17 -> V_46 ) ;
V_17 -> V_23 -= V_9 -> V_32 ;
V_26 -> V_65 = V_9 ;
V_9 -> V_30 = 0 ;
}
F_17 ( & V_17 -> V_20 ) ;
if ( V_9 == NULL )
goto V_69;
}
V_35 = V_17 -> V_21 -> V_70 ( V_26 , V_9 , V_67 , V_32 ) ;
if ( V_35 < 0 || V_9 -> V_32 == V_9 -> V_30 ) {
V_26 -> V_65 = NULL ;
F_14 ( & V_17 -> V_20 ) ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
V_69:
F_31 ( & V_41 -> V_44 ) ;
return V_35 ;
}
static T_2
F_43 ( struct V_25 * V_26 , const char T_3 * V_67 , T_4 V_32 , T_5 * V_68 )
{
struct V_41 * V_41 = F_41 ( V_26 ) ;
int V_35 ;
F_29 ( & V_41 -> V_44 ) ;
V_35 = - V_36 ;
if ( F_18 ( V_41 ) -> V_17 != NULL )
V_35 = F_18 ( V_41 ) -> V_17 -> V_21 -> V_71 ( V_26 , V_67 , V_32 ) ;
F_31 ( & V_41 -> V_44 ) ;
return V_35 ;
}
static unsigned int
F_44 ( struct V_25 * V_26 , struct V_72 * V_73 )
{
struct V_41 * V_41 = F_41 ( V_26 ) ;
struct V_50 * V_51 = F_18 ( V_41 ) ;
unsigned int V_74 = V_75 | V_76 ;
F_45 ( V_26 , & V_51 -> V_4 , V_73 ) ;
F_29 ( & V_41 -> V_44 ) ;
if ( V_51 -> V_17 == NULL )
V_74 |= V_77 | V_78 ;
else if ( V_26 -> V_65 || ! F_7 ( & V_51 -> V_17 -> V_17 ) )
V_74 |= V_79 | V_80 ;
F_31 ( & V_41 -> V_44 ) ;
return V_74 ;
}
static long
F_46 ( struct V_25 * V_26 , unsigned int V_81 , unsigned long V_82 )
{
struct V_41 * V_41 = F_41 ( V_26 ) ;
struct V_16 * V_17 ;
int V_32 ;
switch ( V_81 ) {
case V_83 :
F_29 ( & V_41 -> V_44 ) ;
V_17 = F_18 ( V_41 ) -> V_17 ;
if ( V_17 == NULL ) {
F_31 ( & V_41 -> V_44 ) ;
return - V_36 ;
}
F_14 ( & V_17 -> V_20 ) ;
V_32 = V_17 -> V_23 ;
if ( V_26 -> V_65 ) {
struct V_7 * V_9 ;
V_9 = V_26 -> V_65 ;
V_32 += V_9 -> V_32 - V_9 -> V_30 ;
}
F_17 ( & V_17 -> V_20 ) ;
F_31 ( & V_41 -> V_44 ) ;
return F_47 ( V_32 , ( int T_3 * ) V_82 ) ;
default:
return - V_84 ;
}
}
static int
F_48 ( struct V_85 * V_86 , void * V_87 )
{
struct V_88 * V_89 = V_86 -> V_42 ;
F_49 () ;
F_50 ( V_86 , L_1 ,
F_51 ( V_89 -> V_90 ) -> V_91 ) ;
F_50 ( V_86 , L_2 , V_89 -> V_92 -> V_93 ,
V_89 -> V_94 , V_89 -> V_95 ) ;
F_50 ( V_86 , L_3 , F_52 ( V_89 , V_96 ) ) ;
F_50 ( V_86 , L_4 , F_52 ( V_89 , V_97 ) ) ;
F_50 ( V_86 , L_5 , F_52 ( V_89 , V_98 ) ) ;
F_53 () ;
return 0 ;
}
static int
F_54 ( struct V_41 * V_41 , struct V_25 * V_25 )
{
struct V_88 * V_89 = NULL ;
int V_99 = F_55 ( V_25 , F_48 , NULL ) ;
if ( ! V_99 ) {
struct V_85 * V_86 = V_25 -> V_65 ;
F_14 ( & V_25 -> V_100 . V_19 -> V_101 ) ;
if ( ! F_56 ( V_25 -> V_100 . V_19 ) )
V_89 = F_18 ( V_41 ) -> V_42 ;
if ( V_89 != NULL && F_57 ( & V_89 -> V_102 ) ) {
F_17 ( & V_25 -> V_100 . V_19 -> V_101 ) ;
V_86 -> V_42 = V_89 ;
} else {
F_17 ( & V_25 -> V_100 . V_19 -> V_101 ) ;
F_58 ( V_41 , V_25 ) ;
V_99 = - V_84 ;
}
}
return V_99 ;
}
static int
F_59 ( struct V_41 * V_41 , struct V_25 * V_25 )
{
struct V_85 * V_86 = V_25 -> V_65 ;
struct V_88 * V_89 = (struct V_88 * ) V_86 -> V_42 ;
if ( V_89 )
F_60 ( V_89 ) ;
return F_58 ( V_41 , V_25 ) ;
}
static struct V_41 *
F_61 ( struct V_48 * V_49 , T_6 V_103 )
{
struct V_41 * V_41 = F_62 ( V_49 ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_104 = F_63 () ;
V_41 -> V_105 = V_103 ;
V_41 -> V_106 = V_41 -> V_107 = V_41 -> V_108 = V_109 ;
switch ( V_103 & V_110 ) {
case V_111 :
V_41 -> V_112 = & V_113 ;
V_41 -> V_114 = & V_115 ;
F_64 ( V_41 ) ;
default:
break;
}
return V_41 ;
}
static int F_65 ( struct V_41 * V_116 , struct V_19 * V_19 ,
T_6 V_103 ,
const struct V_117 * V_112 ,
void * V_42 )
{
struct V_41 * V_41 ;
F_66 ( V_19 ) ;
V_41 = F_61 ( V_116 -> V_118 , V_103 ) ;
if ( ! V_41 )
goto V_119;
V_41 -> V_104 = F_67 ( V_116 -> V_118 , 100 ) ;
if ( V_112 )
V_41 -> V_112 = V_112 ;
if ( V_42 )
F_27 ( V_41 , V_42 ) ;
F_68 ( V_19 , V_41 ) ;
return 0 ;
V_119:
F_69 ( V_120 L_6 ,
__FILE__ , V_121 , V_19 ) ;
F_20 ( V_19 ) ;
return - V_122 ;
}
static int F_70 ( struct V_41 * V_116 , struct V_19 * V_19 ,
T_6 V_103 ,
const struct V_117 * V_112 ,
void * V_42 )
{
int V_8 ;
V_8 = F_65 ( V_116 , V_19 , V_123 | V_103 , V_112 , V_42 ) ;
if ( V_8 )
return V_8 ;
F_71 ( V_116 , V_19 ) ;
return 0 ;
}
static int F_72 ( struct V_41 * V_116 , struct V_19 * V_19 ,
T_6 V_103 ,
const struct V_117 * V_112 ,
void * V_42 )
{
int V_8 ;
V_8 = F_65 ( V_116 , V_19 , V_111 | V_103 , V_112 , V_42 ) ;
if ( V_8 )
return V_8 ;
F_64 ( V_116 ) ;
F_73 ( V_116 , V_19 ) ;
return 0 ;
}
static void
F_74 ( struct V_16 * V_17 )
{
V_17 -> V_22 = 0 ;
V_17 -> V_45 = 0 ;
F_75 ( & V_17 -> V_46 ) ;
F_75 ( & V_17 -> V_124 ) ;
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
struct V_16 * F_80 ( const struct V_125 * V_21 , int V_37 )
{
struct V_16 * V_17 ;
V_17 = F_81 ( sizeof( struct V_16 ) , V_53 ) ;
if ( ! V_17 )
return F_82 ( - V_122 ) ;
F_74 ( V_17 ) ;
V_17 -> V_21 = V_21 ;
V_17 -> V_37 = V_37 ;
return V_17 ;
}
static int F_83 ( struct V_41 * V_116 , struct V_19 * V_19 ,
T_6 V_103 ,
const struct V_117 * V_112 ,
void * V_42 ,
struct V_16 * V_17 )
{
struct V_50 * V_51 ;
int V_8 ;
V_8 = F_65 ( V_116 , V_19 , V_126 | V_103 , V_112 , V_42 ) ;
if ( V_8 )
return V_8 ;
V_51 = F_18 ( F_19 ( V_19 ) ) ;
V_51 -> V_42 = V_42 ;
V_51 -> V_17 = V_17 ;
F_71 ( V_116 , V_19 ) ;
return 0 ;
}
static int F_84 ( struct V_41 * V_116 , struct V_19 * V_19 )
{
int V_99 ;
F_16 ( V_19 ) ;
V_99 = F_85 ( V_116 , V_19 ) ;
F_86 ( V_19 ) ;
F_20 ( V_19 ) ;
return V_99 ;
}
int F_87 ( struct V_19 * V_19 )
{
struct V_19 * V_127 ;
struct V_41 * V_116 ;
int error ;
V_127 = F_88 ( V_19 ) ;
V_116 = F_19 ( V_127 ) ;
F_89 ( & V_116 -> V_44 , V_128 ) ;
error = F_84 ( V_116 , V_19 ) ;
F_31 ( & V_116 -> V_44 ) ;
F_20 ( V_127 ) ;
return error ;
}
static int F_90 ( struct V_41 * V_116 , struct V_19 * V_19 )
{
int V_99 ;
F_16 ( V_19 ) ;
V_99 = F_91 ( V_116 , V_19 ) ;
F_86 ( V_19 ) ;
F_20 ( V_19 ) ;
return V_99 ;
}
static int F_92 ( struct V_41 * V_116 , struct V_19 * V_19 )
{
struct V_41 * V_41 = F_19 ( V_19 ) ;
F_28 ( V_41 ) ;
return F_90 ( V_116 , V_19 ) ;
}
static struct V_19 * F_93 ( struct V_19 * V_127 ,
const char * V_93 )
{
struct V_129 V_130 = F_94 ( V_93 , strlen ( V_93 ) ) ;
struct V_19 * V_19 = F_95 ( V_127 , & V_130 ) ;
if ( ! V_19 ) {
V_19 = F_96 ( V_127 , & V_130 ) ;
if ( ! V_19 )
return F_82 ( - V_122 ) ;
}
if ( F_97 ( V_19 ) )
return V_19 ;
F_20 ( V_19 ) ;
return F_82 ( - V_131 ) ;
}
static void F_98 ( struct V_19 * V_127 ,
const struct V_132 * V_133 ,
int V_134 , int V_135 )
{
struct V_41 * V_116 = F_19 ( V_127 ) ;
struct V_19 * V_19 ;
struct V_129 V_93 ;
int V_136 ;
for ( V_136 = V_134 ; V_136 < V_135 ; V_136 ++ ) {
V_93 . V_93 = V_133 [ V_136 ] . V_93 ;
V_93 . V_32 = strlen ( V_133 [ V_136 ] . V_93 ) ;
V_19 = F_95 ( V_127 , & V_93 ) ;
if ( V_19 == NULL )
continue;
if ( F_97 ( V_19 ) )
goto V_10;
switch ( F_19 ( V_19 ) -> V_105 & V_110 ) {
default:
F_99 () ;
case V_123 :
F_90 ( V_116 , V_19 ) ;
break;
case V_111 :
F_84 ( V_116 , V_19 ) ;
}
V_10:
F_20 ( V_19 ) ;
}
}
static void F_100 ( struct V_19 * V_127 ,
const struct V_132 * V_133 ,
int V_134 , int V_135 )
{
struct V_41 * V_116 = F_19 ( V_127 ) ;
F_89 ( & V_116 -> V_44 , V_137 ) ;
F_98 ( V_127 , V_133 , V_134 , V_135 ) ;
F_31 ( & V_116 -> V_44 ) ;
}
static int F_101 ( struct V_19 * V_127 ,
const struct V_132 * V_133 ,
int V_134 , int V_135 ,
void * V_42 )
{
struct V_41 * V_116 = F_19 ( V_127 ) ;
struct V_19 * V_19 ;
int V_136 , V_8 ;
F_29 ( & V_116 -> V_44 ) ;
for ( V_136 = V_134 ; V_136 < V_135 ; V_136 ++ ) {
V_19 = F_93 ( V_127 , V_133 [ V_136 ] . V_93 ) ;
V_8 = F_102 ( V_19 ) ;
if ( F_103 ( V_19 ) )
goto V_138;
switch ( V_133 [ V_136 ] . V_103 & V_110 ) {
default:
F_99 () ;
case V_123 :
V_8 = F_70 ( V_116 , V_19 ,
V_133 [ V_136 ] . V_103 ,
V_133 [ V_136 ] . V_112 ,
V_42 ) ;
break;
case V_111 :
V_8 = F_72 ( V_116 , V_19 ,
V_133 [ V_136 ] . V_103 ,
NULL ,
V_42 ) ;
}
if ( V_8 != 0 )
goto V_138;
}
F_31 ( & V_116 -> V_44 ) ;
return 0 ;
V_138:
F_98 ( V_127 , V_133 , V_134 , V_135 ) ;
F_31 ( & V_116 -> V_44 ) ;
F_69 ( V_120 L_7 ,
__FILE__ , V_121 , V_127 ) ;
return V_8 ;
}
static struct V_19 * F_104 ( struct V_19 * V_127 ,
const char * V_93 , T_6 V_103 , void * V_42 ,
int (* F_105)( struct V_19 * , void * ) , void * V_139 )
{
struct V_19 * V_19 ;
struct V_41 * V_116 = F_19 ( V_127 ) ;
int error ;
F_89 ( & V_116 -> V_44 , V_128 ) ;
V_19 = F_93 ( V_127 , V_93 ) ;
if ( F_103 ( V_19 ) )
goto V_59;
error = F_72 ( V_116 , V_19 , V_103 , NULL , V_42 ) ;
if ( error != 0 )
goto V_119;
if ( F_105 != NULL ) {
error = F_105 ( V_19 , V_139 ) ;
if ( error )
goto V_140;
}
V_59:
F_31 ( & V_116 -> V_44 ) ;
return V_19 ;
V_140:
F_84 ( V_116 , V_19 ) ;
V_119:
V_19 = F_82 ( error ) ;
goto V_59;
}
static int F_106 ( struct V_19 * V_19 ,
void (* F_107)( struct V_19 * ) )
{
struct V_19 * V_127 ;
struct V_41 * V_116 ;
int error ;
V_127 = F_88 ( V_19 ) ;
V_116 = F_19 ( V_127 ) ;
F_89 ( & V_116 -> V_44 , V_128 ) ;
if ( F_107 != NULL )
F_107 ( V_19 ) ;
error = F_84 ( V_116 , V_19 ) ;
F_31 ( & V_116 -> V_44 ) ;
F_20 ( V_127 ) ;
return error ;
}
struct V_19 * F_108 ( struct V_19 * V_127 , const char * V_93 ,
void * V_42 , struct V_16 * V_17 )
{
struct V_19 * V_19 ;
struct V_41 * V_116 = F_19 ( V_127 ) ;
T_6 V_141 = V_126 | V_142 | V_143 ;
int V_8 ;
if ( V_17 -> V_21 -> V_70 == NULL )
V_141 &= ~ V_144 ;
if ( V_17 -> V_21 -> V_71 == NULL )
V_141 &= ~ V_145 ;
F_89 ( & V_116 -> V_44 , V_128 ) ;
V_19 = F_93 ( V_127 , V_93 ) ;
if ( F_103 ( V_19 ) )
goto V_59;
V_8 = F_83 ( V_116 , V_19 , V_141 , & V_146 ,
V_42 , V_17 ) ;
if ( V_8 )
goto V_119;
V_59:
F_31 ( & V_116 -> V_44 ) ;
return V_19 ;
V_119:
V_19 = F_82 ( V_8 ) ;
F_69 ( V_120 L_8 ,
__FILE__ , V_121 , V_127 , V_93 ,
V_8 ) ;
goto V_59;
}
int
F_109 ( struct V_19 * V_19 )
{
struct V_19 * V_127 ;
struct V_41 * V_116 ;
int error = 0 ;
V_127 = F_88 ( V_19 ) ;
V_116 = F_19 ( V_127 ) ;
F_89 ( & V_116 -> V_44 , V_128 ) ;
error = F_92 ( V_116 , V_19 ) ;
F_31 ( & V_116 -> V_44 ) ;
F_20 ( V_127 ) ;
return error ;
}
void F_110 ( struct V_147 * V_148 )
{
F_75 ( & V_148 -> V_149 ) ;
V_148 -> V_150 = NULL ;
}
void F_111 ( struct V_151 * V_152 ,
const struct V_153 * V_154 ,
void * V_155 )
{
F_75 ( & V_152 -> V_156 ) ;
V_152 -> V_154 = V_154 ;
V_152 -> V_155 = V_155 ;
}
static int
F_112 ( struct V_157 * V_157 ,
struct V_147 * V_148 ,
struct V_151 * V_152 )
{
int V_99 = 0 ;
if ( V_148 -> V_150 )
V_99 = V_152 -> V_154 -> V_158 ( V_148 -> V_150 , V_152 ) ;
if ( V_99 == 0 )
F_25 ( & V_152 -> V_156 , & V_148 -> V_149 ) ;
return V_99 ;
}
static void
F_113 ( struct V_157 * V_157 ,
struct V_147 * V_148 ,
struct V_151 * V_152 )
{
if ( V_148 -> V_150 )
V_152 -> V_154 -> V_159 ( V_148 -> V_150 , V_152 ) ;
F_9 ( & V_152 -> V_156 ) ;
}
int
F_114 ( struct V_157 * V_157 ,
struct V_147 * V_148 ,
struct V_151 * V_152 )
{
int V_99 = 0 ;
if ( F_7 ( & V_152 -> V_156 ) ) {
struct V_160 * V_161 = F_115 ( V_157 , V_162 ) ;
F_29 ( & V_161 -> V_163 ) ;
V_99 = F_112 ( V_157 , V_148 , V_152 ) ;
F_31 ( & V_161 -> V_163 ) ;
}
return V_99 ;
}
void
F_116 ( struct V_157 * V_157 ,
struct V_147 * V_148 ,
struct V_151 * V_152 )
{
if ( ! F_7 ( & V_152 -> V_156 ) ) {
struct V_160 * V_161 = F_115 ( V_157 , V_162 ) ;
F_29 ( & V_161 -> V_163 ) ;
F_113 ( V_157 , V_148 , V_152 ) ;
F_31 ( & V_161 -> V_163 ) ;
}
}
static void
F_117 ( struct V_147 * V_148 )
{
struct V_151 * V_152 ;
struct V_19 * V_116 = V_148 -> V_150 ;
F_118 (pdo, &pdh->pdh_entries, pdo_head)
V_152 -> V_154 -> V_158 ( V_116 , V_152 ) ;
}
static void
F_119 ( struct V_147 * V_148 )
{
struct V_151 * V_152 ;
struct V_19 * V_116 = V_148 -> V_150 ;
F_118 (pdo, &pdh->pdh_entries, pdo_head)
V_152 -> V_154 -> V_159 ( V_116 , V_152 ) ;
}
static int F_120 ( struct V_19 * V_19 , void * V_42 )
{
return F_101 ( V_19 ,
V_164 , V_165 , V_166 ,
V_42 ) ;
}
static void F_121 ( struct V_19 * V_19 )
{
F_100 ( V_19 , V_164 , V_165 , V_166 ) ;
}
struct V_19 * F_122 ( struct V_19 * V_19 ,
const char * V_93 ,
struct V_88 * V_167 )
{
struct V_19 * V_99 ;
V_99 = F_104 ( V_19 , V_93 , V_144 | V_168 , NULL ,
F_120 , V_167 ) ;
if ( ! F_103 ( V_99 ) ) {
V_167 -> V_169 . V_150 = V_99 ;
F_117 ( & V_167 -> V_169 ) ;
}
return V_99 ;
}
int F_123 ( struct V_88 * V_167 )
{
struct V_19 * V_19 = V_167 -> V_169 . V_150 ;
if ( V_19 == NULL )
return 0 ;
F_119 ( & V_167 -> V_169 ) ;
V_167 -> V_169 . V_150 = NULL ;
return F_106 ( V_19 , F_121 ) ;
}
static int F_124 ( struct V_19 * V_19 , void * V_42 )
{
return F_101 ( V_19 ,
V_170 , 0 , 3 ,
V_42 ) ;
}
static void F_125 ( struct V_19 * V_19 )
{
F_100 ( V_19 , V_170 , 0 , 3 ) ;
}
struct V_19 * F_126 ( struct V_19 * V_127 , const char * V_93 ,
T_6 V_141 , struct V_171 * V_172 )
{
return F_104 ( V_127 , V_93 , V_141 , NULL ,
F_124 , V_172 ) ;
}
void F_127 ( struct V_19 * V_19 )
{
F_106 ( V_19 , F_125 ) ;
}
struct V_19 * F_128 ( const struct V_48 * V_49 ,
const unsigned char * V_173 )
{
struct V_129 V_116 = F_94 ( V_173 , strlen ( V_173 ) ) ;
return F_95 ( V_49 -> V_174 , & V_116 ) ;
}
int F_129 ( struct V_157 * V_157 )
{
struct V_160 * V_161 = F_115 ( V_157 , V_162 ) ;
V_161 -> V_175 = F_80 ( & V_176 , 0 ) ;
if ( F_103 ( V_161 -> V_175 ) )
return F_102 ( V_161 -> V_175 ) ;
F_130 ( & V_161 -> V_163 ) ;
V_161 -> V_177 = - 1 ;
return 0 ;
}
void F_131 ( struct V_157 * V_157 )
{
struct V_160 * V_161 = F_115 ( V_157 , V_162 ) ;
F_78 ( V_161 -> V_175 ) ;
}
struct V_48 * F_132 ( const struct V_157 * V_157 )
{
struct V_160 * V_161 = F_115 ( V_157 , V_162 ) ;
F_29 ( & V_161 -> V_163 ) ;
if ( V_161 -> V_178 )
return V_161 -> V_178 ;
F_31 ( & V_161 -> V_163 ) ;
return NULL ;
}
void F_133 ( const struct V_157 * V_157 )
{
struct V_160 * V_161 = F_115 ( V_157 , V_162 ) ;
F_134 ( V_161 -> V_178 == NULL ) ;
F_31 ( & V_161 -> V_163 ) ;
}
static T_2
F_135 ( struct V_25 * V_26 , const char T_3 * V_179 , T_4 V_32 )
{
return - V_84 ;
}
static int
F_136 ( struct V_85 * V_86 , void * V_87 )
{
F_50 ( V_86 , L_1 , F_137 () -> V_180 ) ;
F_50 ( V_86 , L_9 ) ;
F_50 ( V_86 , L_10 ) ;
F_50 ( V_86 , L_11 ) ;
F_50 ( V_86 , L_12 ) ;
return 0 ;
}
static int
F_138 ( struct V_41 * V_41 , struct V_25 * V_25 )
{
return F_55 ( V_25 , F_136 , NULL ) ;
}
static struct V_19 *
F_139 ( struct V_19 * V_181 , struct V_16 * V_182 )
{
int V_99 = 0 ;
struct V_19 * V_183 ;
struct V_19 * V_184 = NULL ;
struct V_19 * V_185 = NULL ;
struct V_129 V_130 = F_94 ( V_133 [ V_186 ] . V_93 ,
strlen ( V_133 [ V_186 ] . V_93 ) ) ;
V_183 = F_95 ( V_181 , & V_130 ) ;
if ( ! V_183 )
return F_82 ( - V_187 ) ;
V_99 = F_101 ( V_183 , V_188 , 0 , 1 , NULL ) ;
if ( V_99 ) {
V_185 = F_82 ( V_99 ) ;
goto V_59;
}
V_130 . V_93 = V_188 [ 0 ] . V_93 ;
V_130 . V_32 = strlen ( V_188 [ 0 ] . V_93 ) ;
V_184 = F_95 ( V_183 , & V_130 ) ;
if ( ! V_184 ) {
V_185 = F_82 ( - V_187 ) ;
goto V_59;
}
V_99 = F_101 ( V_184 , V_189 , 0 , 1 , NULL ) ;
if ( V_99 ) {
F_98 ( V_183 , V_188 , 0 , 1 ) ;
V_185 = F_82 ( V_99 ) ;
goto V_59;
}
V_185 = F_108 ( V_184 , L_13 , NULL , V_182 ) ;
if ( F_103 ( V_185 ) ) {
F_98 ( V_184 , V_189 , 0 , 1 ) ;
F_98 ( V_183 , V_188 , 0 , 1 ) ;
}
V_59:
F_20 ( V_184 ) ;
F_20 ( V_183 ) ;
return V_185 ;
}
static void
F_140 ( struct V_19 * V_185 )
{
struct V_19 * V_190 = V_185 -> V_191 ;
struct V_19 * V_192 = V_190 -> V_191 ;
F_92 ( F_19 ( V_190 ) , V_185 ) ;
F_98 ( V_190 , V_189 , 0 , 1 ) ;
F_98 ( V_192 , V_188 , 0 , 1 ) ;
F_20 ( V_185 ) ;
}
static int
F_141 ( struct V_48 * V_49 , void * V_29 , int V_193 )
{
struct V_41 * V_41 ;
struct V_19 * V_181 , * V_183 ;
struct V_157 * V_157 = V_29 ;
struct V_160 * V_161 = F_115 ( V_157 , V_162 ) ;
int V_8 ;
V_49 -> V_194 = V_195 ;
V_49 -> V_196 = V_197 ;
V_49 -> V_198 = V_199 ;
V_49 -> V_200 = & V_201 ;
V_49 -> V_202 = & V_203 ;
V_49 -> V_204 = 1 ;
V_41 = F_61 ( V_49 , V_111 | V_144 | V_168 ) ;
V_49 -> V_174 = V_181 = F_142 ( V_41 ) ;
if ( ! V_181 )
return - V_122 ;
if ( F_101 ( V_181 , V_133 , V_205 , V_206 , NULL ) )
return - V_122 ;
V_183 = F_139 ( V_181 , V_161 -> V_175 ) ;
if ( F_103 ( V_183 ) ) {
F_98 ( V_181 , V_133 , V_205 , V_206 ) ;
return F_102 ( V_183 ) ;
}
F_143 ( L_14 ,
V_157 , F_144 ( V_157 ) ) ;
F_29 ( & V_161 -> V_163 ) ;
V_161 -> V_178 = V_49 ;
V_8 = F_145 ( & V_3 ,
V_207 ,
V_49 ) ;
if ( V_8 )
goto V_208;
V_49 -> V_209 = F_146 ( V_157 ) ;
F_31 ( & V_161 -> V_163 ) ;
return 0 ;
V_208:
F_140 ( V_183 ) ;
F_145 ( & V_3 ,
V_210 ,
V_49 ) ;
V_161 -> V_178 = NULL ;
F_98 ( V_181 , V_133 , V_205 , V_206 ) ;
F_31 ( & V_161 -> V_163 ) ;
return V_8 ;
}
bool
F_147 ( struct V_157 * V_157 )
{
struct V_160 * V_161 = F_115 ( V_157 , V_162 ) ;
struct V_16 * V_17 = V_161 -> V_175 ;
return V_17 -> V_22 || V_17 -> V_45 ;
}
static struct V_19 *
F_148 ( struct V_211 * V_212 ,
int V_37 , const char * V_213 , void * V_29 )
{
return F_149 ( V_212 , V_37 , V_214 -> V_215 -> V_216 , F_141 ) ;
}
static void F_150 ( struct V_48 * V_49 )
{
struct V_157 * V_157 = V_49 -> V_209 ;
struct V_160 * V_161 = F_115 ( V_157 , V_162 ) ;
F_29 ( & V_161 -> V_163 ) ;
if ( V_161 -> V_178 != V_49 ) {
F_31 ( & V_161 -> V_163 ) ;
goto V_59;
}
V_161 -> V_178 = NULL ;
F_143 ( L_15 ,
V_157 , F_144 ( V_157 ) ) ;
F_145 ( & V_3 ,
V_210 ,
V_49 ) ;
F_31 ( & V_161 -> V_163 ) ;
F_151 ( V_157 ) ;
V_59:
F_152 ( V_49 ) ;
}
static void
F_153 ( void * V_217 )
{
struct V_50 * V_51 = (struct V_50 * ) V_217 ;
F_154 ( & V_51 -> V_54 ) ;
V_51 -> V_42 = NULL ;
V_51 -> V_17 = NULL ;
F_155 ( & V_51 -> V_4 ) ;
}
int F_156 ( void )
{
int V_8 ;
V_52 = F_157 ( L_16 ,
sizeof( struct V_50 ) ,
0 , ( V_218 | V_219 |
V_220 ) ,
F_153 ) ;
if ( ! V_52 )
return - V_122 ;
V_8 = F_158 () ;
if ( V_8 )
goto V_221;
V_8 = F_159 ( & V_222 ) ;
if ( V_8 )
goto V_223;
return 0 ;
V_223:
F_160 () ;
V_221:
F_161 ( V_52 ) ;
return V_8 ;
}
void F_162 ( void )
{
F_160 () ;
F_161 ( V_52 ) ;
F_163 ( & V_222 ) ;
}
