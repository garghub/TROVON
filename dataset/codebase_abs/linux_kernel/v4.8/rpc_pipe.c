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
F_29 ( V_41 ) ;
F_14 ( & V_17 -> V_20 ) ;
V_43 = V_17 -> V_22 != 0 || V_17 -> V_44 != 0 ;
V_17 -> V_22 = 0 ;
F_15 ( & V_17 -> V_45 , & V_15 ) ;
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
V_17 -> V_19 = NULL ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( & F_18 ( V_41 ) -> V_4 , & V_15 , V_17 -> V_21 -> F_6 , - V_36 ) ;
V_17 -> V_44 = 0 ;
if ( V_43 && V_17 -> V_21 -> V_46 )
V_17 -> V_21 -> V_46 ( V_41 ) ;
F_30 ( & V_17 -> V_18 ) ;
F_27 ( V_41 , NULL ) ;
F_18 ( V_41 ) -> V_17 = NULL ;
F_31 ( V_41 ) ;
}
static struct V_41 *
F_32 ( struct V_47 * V_48 )
{
struct V_49 * V_50 ;
V_50 = F_33 ( V_51 , V_52 ) ;
if ( ! V_50 )
return NULL ;
return & V_50 -> V_53 ;
}
static void
F_34 ( struct V_54 * V_6 )
{
struct V_41 * V_41 = F_13 ( V_6 , struct V_41 , V_55 ) ;
F_35 ( V_51 , F_18 ( V_41 ) ) ;
}
static void
F_36 ( struct V_41 * V_41 )
{
F_37 ( & V_41 -> V_55 , F_34 ) ;
}
static int
F_38 ( struct V_41 * V_41 , struct V_25 * V_26 )
{
struct V_16 * V_17 ;
int V_56 ;
int V_35 = - V_57 ;
F_29 ( V_41 ) ;
V_17 = F_18 ( V_41 ) -> V_17 ;
if ( V_17 == NULL )
goto V_58;
V_56 = V_17 -> V_22 == 0 && V_17 -> V_44 == 0 ;
if ( V_56 && V_17 -> V_21 -> V_59 ) {
V_35 = V_17 -> V_21 -> V_59 ( V_41 ) ;
if ( V_35 )
goto V_58;
}
if ( V_26 -> V_60 & V_61 )
V_17 -> V_22 ++ ;
if ( V_26 -> V_60 & V_62 )
V_17 -> V_44 ++ ;
V_35 = 0 ;
V_58:
F_31 ( V_41 ) ;
return V_35 ;
}
static int
F_39 ( struct V_41 * V_41 , struct V_25 * V_26 )
{
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_63 ;
F_29 ( V_41 ) ;
V_17 = F_18 ( V_41 ) -> V_17 ;
if ( V_17 == NULL )
goto V_58;
V_9 = V_26 -> V_64 ;
if ( V_9 != NULL ) {
F_14 ( & V_17 -> V_20 ) ;
V_9 -> V_12 = - V_65 ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
if ( V_26 -> V_60 & V_62 )
V_17 -> V_44 -- ;
if ( V_26 -> V_60 & V_61 ) {
V_17 -> V_22 -- ;
if ( V_17 -> V_22 == 0 ) {
F_12 ( V_15 ) ;
F_14 ( & V_17 -> V_20 ) ;
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( & F_18 ( V_41 ) -> V_4 , & V_15 ,
V_17 -> V_21 -> F_6 , - V_65 ) ;
}
}
V_63 = V_17 -> V_44 == 0 && V_17 -> V_22 == 0 ;
if ( V_63 && V_17 -> V_21 -> V_46 )
V_17 -> V_21 -> V_46 ( V_41 ) ;
V_58:
F_31 ( V_41 ) ;
return 0 ;
}
static T_2
F_40 ( struct V_25 * V_26 , char T_3 * V_66 , T_4 V_32 , T_5 * V_67 )
{
struct V_41 * V_41 = F_41 ( V_26 ) ;
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_35 = 0 ;
F_29 ( V_41 ) ;
V_17 = F_18 ( V_41 ) -> V_17 ;
if ( V_17 == NULL ) {
V_35 = - V_36 ;
goto V_68;
}
V_9 = V_26 -> V_64 ;
if ( V_9 == NULL ) {
F_14 ( & V_17 -> V_20 ) ;
if ( ! F_7 ( & V_17 -> V_17 ) ) {
V_9 = F_8 ( V_17 -> V_17 . V_10 ,
struct V_7 ,
V_11 ) ;
F_42 ( & V_9 -> V_11 , & V_17 -> V_45 ) ;
V_17 -> V_23 -= V_9 -> V_32 ;
V_26 -> V_64 = V_9 ;
V_9 -> V_30 = 0 ;
}
F_17 ( & V_17 -> V_20 ) ;
if ( V_9 == NULL )
goto V_68;
}
V_35 = V_17 -> V_21 -> V_69 ( V_26 , V_9 , V_66 , V_32 ) ;
if ( V_35 < 0 || V_9 -> V_32 == V_9 -> V_30 ) {
V_26 -> V_64 = NULL ;
F_14 ( & V_17 -> V_20 ) ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
V_68:
F_31 ( V_41 ) ;
return V_35 ;
}
static T_2
F_43 ( struct V_25 * V_26 , const char T_3 * V_66 , T_4 V_32 , T_5 * V_67 )
{
struct V_41 * V_41 = F_41 ( V_26 ) ;
int V_35 ;
F_29 ( V_41 ) ;
V_35 = - V_36 ;
if ( F_18 ( V_41 ) -> V_17 != NULL )
V_35 = F_18 ( V_41 ) -> V_17 -> V_21 -> V_70 ( V_26 , V_66 , V_32 ) ;
F_31 ( V_41 ) ;
return V_35 ;
}
static unsigned int
F_44 ( struct V_25 * V_26 , struct V_71 * V_72 )
{
struct V_41 * V_41 = F_41 ( V_26 ) ;
struct V_49 * V_50 = F_18 ( V_41 ) ;
unsigned int V_73 = V_74 | V_75 ;
F_45 ( V_26 , & V_50 -> V_4 , V_72 ) ;
F_29 ( V_41 ) ;
if ( V_50 -> V_17 == NULL )
V_73 |= V_76 | V_77 ;
else if ( V_26 -> V_64 || ! F_7 ( & V_50 -> V_17 -> V_17 ) )
V_73 |= V_78 | V_79 ;
F_31 ( V_41 ) ;
return V_73 ;
}
static long
F_46 ( struct V_25 * V_26 , unsigned int V_80 , unsigned long V_81 )
{
struct V_41 * V_41 = F_41 ( V_26 ) ;
struct V_16 * V_17 ;
int V_32 ;
switch ( V_80 ) {
case V_82 :
F_29 ( V_41 ) ;
V_17 = F_18 ( V_41 ) -> V_17 ;
if ( V_17 == NULL ) {
F_31 ( V_41 ) ;
return - V_36 ;
}
F_14 ( & V_17 -> V_20 ) ;
V_32 = V_17 -> V_23 ;
if ( V_26 -> V_64 ) {
struct V_7 * V_9 ;
V_9 = V_26 -> V_64 ;
V_32 += V_9 -> V_32 - V_9 -> V_30 ;
}
F_17 ( & V_17 -> V_20 ) ;
F_31 ( V_41 ) ;
return F_47 ( V_32 , ( int T_3 * ) V_81 ) ;
default:
return - V_83 ;
}
}
static int
F_48 ( struct V_84 * V_85 , void * V_86 )
{
struct V_87 * V_88 = V_85 -> V_42 ;
F_49 () ;
F_50 ( V_85 , L_1 ,
F_51 ( V_88 -> V_89 ) -> V_90 ) ;
F_50 ( V_85 , L_2 , V_88 -> V_91 -> V_92 ,
V_88 -> V_93 , V_88 -> V_94 ) ;
F_50 ( V_85 , L_3 , F_52 ( V_88 , V_95 ) ) ;
F_50 ( V_85 , L_4 , F_52 ( V_88 , V_96 ) ) ;
F_50 ( V_85 , L_5 , F_52 ( V_88 , V_97 ) ) ;
F_53 () ;
return 0 ;
}
static int
F_54 ( struct V_41 * V_41 , struct V_25 * V_25 )
{
struct V_87 * V_88 = NULL ;
int V_98 = F_55 ( V_25 , F_48 , NULL ) ;
if ( ! V_98 ) {
struct V_84 * V_85 = V_25 -> V_64 ;
F_14 ( & V_25 -> V_99 . V_19 -> V_100 ) ;
if ( ! F_56 ( V_25 -> V_99 . V_19 ) )
V_88 = F_18 ( V_41 ) -> V_42 ;
if ( V_88 != NULL && F_57 ( & V_88 -> V_101 ) ) {
F_17 ( & V_25 -> V_99 . V_19 -> V_100 ) ;
V_85 -> V_42 = V_88 ;
} else {
F_17 ( & V_25 -> V_99 . V_19 -> V_100 ) ;
F_58 ( V_41 , V_25 ) ;
V_98 = - V_83 ;
}
}
return V_98 ;
}
static int
F_59 ( struct V_41 * V_41 , struct V_25 * V_25 )
{
struct V_84 * V_85 = V_25 -> V_64 ;
struct V_87 * V_88 = (struct V_87 * ) V_85 -> V_42 ;
if ( V_88 )
F_60 ( V_88 ) ;
return F_58 ( V_41 , V_25 ) ;
}
static struct V_41 *
F_61 ( struct V_47 * V_48 , T_6 V_102 )
{
struct V_41 * V_41 = F_62 ( V_48 ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_103 = F_63 () ;
V_41 -> V_104 = V_102 ;
V_41 -> V_105 = V_41 -> V_106 = V_41 -> V_107 = V_108 ;
switch ( V_102 & V_109 ) {
case V_110 :
V_41 -> V_111 = & V_112 ;
V_41 -> V_113 = & V_114 ;
F_64 ( V_41 ) ;
default:
break;
}
return V_41 ;
}
static int F_65 ( struct V_41 * V_115 , struct V_19 * V_19 ,
T_6 V_102 ,
const struct V_116 * V_111 ,
void * V_42 )
{
struct V_41 * V_41 ;
F_66 ( V_19 ) ;
V_41 = F_61 ( V_115 -> V_117 , V_102 ) ;
if ( ! V_41 )
goto V_118;
V_41 -> V_103 = F_67 ( V_115 -> V_117 , 100 ) ;
if ( V_111 )
V_41 -> V_111 = V_111 ;
if ( V_42 )
F_27 ( V_41 , V_42 ) ;
F_68 ( V_19 , V_41 ) ;
return 0 ;
V_118:
F_69 ( V_119 L_6 ,
__FILE__ , V_120 , V_19 ) ;
F_20 ( V_19 ) ;
return - V_121 ;
}
static int F_70 ( struct V_41 * V_115 , struct V_19 * V_19 ,
T_6 V_102 ,
const struct V_116 * V_111 ,
void * V_42 )
{
int V_8 ;
V_8 = F_65 ( V_115 , V_19 , V_122 | V_102 , V_111 , V_42 ) ;
if ( V_8 )
return V_8 ;
F_71 ( V_115 , V_19 ) ;
return 0 ;
}
static int F_72 ( struct V_41 * V_115 , struct V_19 * V_19 ,
T_6 V_102 ,
const struct V_116 * V_111 ,
void * V_42 )
{
int V_8 ;
V_8 = F_65 ( V_115 , V_19 , V_110 | V_102 , V_111 , V_42 ) ;
if ( V_8 )
return V_8 ;
F_64 ( V_115 ) ;
F_73 ( V_115 , V_19 ) ;
return 0 ;
}
static void
F_74 ( struct V_16 * V_17 )
{
V_17 -> V_22 = 0 ;
V_17 -> V_44 = 0 ;
F_75 ( & V_17 -> V_45 ) ;
F_75 ( & V_17 -> V_123 ) ;
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
struct V_16 * F_80 ( const struct V_124 * V_21 , int V_37 )
{
struct V_16 * V_17 ;
V_17 = F_81 ( sizeof( struct V_16 ) , V_52 ) ;
if ( ! V_17 )
return F_82 ( - V_121 ) ;
F_74 ( V_17 ) ;
V_17 -> V_21 = V_21 ;
V_17 -> V_37 = V_37 ;
return V_17 ;
}
static int F_83 ( struct V_41 * V_115 , struct V_19 * V_19 ,
T_6 V_102 ,
const struct V_116 * V_111 ,
void * V_42 ,
struct V_16 * V_17 )
{
struct V_49 * V_50 ;
int V_8 ;
V_8 = F_65 ( V_115 , V_19 , V_125 | V_102 , V_111 , V_42 ) ;
if ( V_8 )
return V_8 ;
V_50 = F_18 ( F_19 ( V_19 ) ) ;
V_50 -> V_42 = V_42 ;
V_50 -> V_17 = V_17 ;
F_71 ( V_115 , V_19 ) ;
return 0 ;
}
static int F_84 ( struct V_41 * V_115 , struct V_19 * V_19 )
{
int V_98 ;
F_16 ( V_19 ) ;
V_98 = F_85 ( V_115 , V_19 ) ;
F_86 ( V_19 ) ;
F_20 ( V_19 ) ;
return V_98 ;
}
int F_87 ( struct V_19 * V_19 )
{
struct V_19 * V_126 ;
struct V_41 * V_115 ;
int error ;
V_126 = F_88 ( V_19 ) ;
V_115 = F_19 ( V_126 ) ;
F_89 ( V_115 , V_127 ) ;
error = F_84 ( V_115 , V_19 ) ;
F_31 ( V_115 ) ;
F_20 ( V_126 ) ;
return error ;
}
static int F_90 ( struct V_41 * V_115 , struct V_19 * V_19 )
{
int V_98 ;
F_16 ( V_19 ) ;
V_98 = F_91 ( V_115 , V_19 ) ;
F_86 ( V_19 ) ;
F_20 ( V_19 ) ;
return V_98 ;
}
static int F_92 ( struct V_41 * V_115 , struct V_19 * V_19 )
{
struct V_41 * V_41 = F_19 ( V_19 ) ;
F_28 ( V_41 ) ;
return F_90 ( V_115 , V_19 ) ;
}
static struct V_19 * F_93 ( struct V_19 * V_126 ,
const char * V_92 )
{
struct V_128 V_129 = F_94 ( V_92 , strlen ( V_92 ) ) ;
struct V_19 * V_19 = F_95 ( V_126 , & V_129 ) ;
if ( ! V_19 ) {
V_19 = F_96 ( V_126 , & V_129 ) ;
if ( ! V_19 )
return F_82 ( - V_121 ) ;
}
if ( F_97 ( V_19 ) )
return V_19 ;
F_20 ( V_19 ) ;
return F_82 ( - V_130 ) ;
}
static void F_98 ( struct V_19 * V_126 ,
const struct V_131 * V_132 ,
int V_133 , int V_134 )
{
struct V_41 * V_115 = F_19 ( V_126 ) ;
struct V_19 * V_19 ;
struct V_128 V_92 ;
int V_135 ;
for ( V_135 = V_133 ; V_135 < V_134 ; V_135 ++ ) {
V_92 . V_92 = V_132 [ V_135 ] . V_92 ;
V_92 . V_32 = strlen ( V_132 [ V_135 ] . V_92 ) ;
V_19 = F_95 ( V_126 , & V_92 ) ;
if ( V_19 == NULL )
continue;
if ( F_97 ( V_19 ) )
goto V_10;
switch ( F_19 ( V_19 ) -> V_104 & V_109 ) {
default:
F_99 () ;
case V_122 :
F_90 ( V_115 , V_19 ) ;
break;
case V_110 :
F_84 ( V_115 , V_19 ) ;
}
V_10:
F_20 ( V_19 ) ;
}
}
static void F_100 ( struct V_19 * V_126 ,
const struct V_131 * V_132 ,
int V_133 , int V_134 )
{
struct V_41 * V_115 = F_19 ( V_126 ) ;
F_89 ( V_115 , V_136 ) ;
F_98 ( V_126 , V_132 , V_133 , V_134 ) ;
F_31 ( V_115 ) ;
}
static int F_101 ( struct V_19 * V_126 ,
const struct V_131 * V_132 ,
int V_133 , int V_134 ,
void * V_42 )
{
struct V_41 * V_115 = F_19 ( V_126 ) ;
struct V_19 * V_19 ;
int V_135 , V_8 ;
F_29 ( V_115 ) ;
for ( V_135 = V_133 ; V_135 < V_134 ; V_135 ++ ) {
V_19 = F_93 ( V_126 , V_132 [ V_135 ] . V_92 ) ;
V_8 = F_102 ( V_19 ) ;
if ( F_103 ( V_19 ) )
goto V_137;
switch ( V_132 [ V_135 ] . V_102 & V_109 ) {
default:
F_99 () ;
case V_122 :
V_8 = F_70 ( V_115 , V_19 ,
V_132 [ V_135 ] . V_102 ,
V_132 [ V_135 ] . V_111 ,
V_42 ) ;
break;
case V_110 :
V_8 = F_72 ( V_115 , V_19 ,
V_132 [ V_135 ] . V_102 ,
NULL ,
V_42 ) ;
}
if ( V_8 != 0 )
goto V_137;
}
F_31 ( V_115 ) ;
return 0 ;
V_137:
F_98 ( V_126 , V_132 , V_133 , V_134 ) ;
F_31 ( V_115 ) ;
F_69 ( V_119 L_7 ,
__FILE__ , V_120 , V_126 ) ;
return V_8 ;
}
static struct V_19 * F_104 ( struct V_19 * V_126 ,
const char * V_92 , T_6 V_102 , void * V_42 ,
int (* F_105)( struct V_19 * , void * ) , void * V_138 )
{
struct V_19 * V_19 ;
struct V_41 * V_115 = F_19 ( V_126 ) ;
int error ;
F_89 ( V_115 , V_127 ) ;
V_19 = F_93 ( V_126 , V_92 ) ;
if ( F_103 ( V_19 ) )
goto V_58;
error = F_72 ( V_115 , V_19 , V_102 , NULL , V_42 ) ;
if ( error != 0 )
goto V_118;
if ( F_105 != NULL ) {
error = F_105 ( V_19 , V_138 ) ;
if ( error )
goto V_139;
}
V_58:
F_31 ( V_115 ) ;
return V_19 ;
V_139:
F_84 ( V_115 , V_19 ) ;
V_118:
V_19 = F_82 ( error ) ;
goto V_58;
}
static int F_106 ( struct V_19 * V_19 ,
void (* F_107)( struct V_19 * ) )
{
struct V_19 * V_126 ;
struct V_41 * V_115 ;
int error ;
V_126 = F_88 ( V_19 ) ;
V_115 = F_19 ( V_126 ) ;
F_89 ( V_115 , V_127 ) ;
if ( F_107 != NULL )
F_107 ( V_19 ) ;
error = F_84 ( V_115 , V_19 ) ;
F_31 ( V_115 ) ;
F_20 ( V_126 ) ;
return error ;
}
struct V_19 * F_108 ( struct V_19 * V_126 , const char * V_92 ,
void * V_42 , struct V_16 * V_17 )
{
struct V_19 * V_19 ;
struct V_41 * V_115 = F_19 ( V_126 ) ;
T_6 V_140 = V_125 | V_141 | V_142 ;
int V_8 ;
if ( V_17 -> V_21 -> V_69 == NULL )
V_140 &= ~ V_143 ;
if ( V_17 -> V_21 -> V_70 == NULL )
V_140 &= ~ V_144 ;
F_89 ( V_115 , V_127 ) ;
V_19 = F_93 ( V_126 , V_92 ) ;
if ( F_103 ( V_19 ) )
goto V_58;
V_8 = F_83 ( V_115 , V_19 , V_140 , & V_145 ,
V_42 , V_17 ) ;
if ( V_8 )
goto V_118;
V_58:
F_31 ( V_115 ) ;
return V_19 ;
V_118:
V_19 = F_82 ( V_8 ) ;
F_69 ( V_119 L_8 ,
__FILE__ , V_120 , V_126 , V_92 ,
V_8 ) ;
goto V_58;
}
int
F_109 ( struct V_19 * V_19 )
{
struct V_19 * V_126 ;
struct V_41 * V_115 ;
int error = 0 ;
V_126 = F_88 ( V_19 ) ;
V_115 = F_19 ( V_126 ) ;
F_89 ( V_115 , V_127 ) ;
error = F_92 ( V_115 , V_19 ) ;
F_31 ( V_115 ) ;
F_20 ( V_126 ) ;
return error ;
}
void F_110 ( struct V_146 * V_147 )
{
F_75 ( & V_147 -> V_148 ) ;
V_147 -> V_149 = NULL ;
}
void F_111 ( struct V_150 * V_151 ,
const struct V_152 * V_153 ,
void * V_154 )
{
F_75 ( & V_151 -> V_155 ) ;
V_151 -> V_153 = V_153 ;
V_151 -> V_154 = V_154 ;
}
static int
F_112 ( struct V_156 * V_156 ,
struct V_146 * V_147 ,
struct V_150 * V_151 )
{
int V_98 = 0 ;
if ( V_147 -> V_149 )
V_98 = V_151 -> V_153 -> V_157 ( V_147 -> V_149 , V_151 ) ;
if ( V_98 == 0 )
F_25 ( & V_151 -> V_155 , & V_147 -> V_148 ) ;
return V_98 ;
}
static void
F_113 ( struct V_156 * V_156 ,
struct V_146 * V_147 ,
struct V_150 * V_151 )
{
if ( V_147 -> V_149 )
V_151 -> V_153 -> V_158 ( V_147 -> V_149 , V_151 ) ;
F_9 ( & V_151 -> V_155 ) ;
}
int
F_114 ( struct V_156 * V_156 ,
struct V_146 * V_147 ,
struct V_150 * V_151 )
{
int V_98 = 0 ;
if ( F_7 ( & V_151 -> V_155 ) ) {
struct V_159 * V_160 = F_115 ( V_156 , V_161 ) ;
F_116 ( & V_160 -> V_162 ) ;
V_98 = F_112 ( V_156 , V_147 , V_151 ) ;
F_117 ( & V_160 -> V_162 ) ;
}
return V_98 ;
}
void
F_118 ( struct V_156 * V_156 ,
struct V_146 * V_147 ,
struct V_150 * V_151 )
{
if ( ! F_7 ( & V_151 -> V_155 ) ) {
struct V_159 * V_160 = F_115 ( V_156 , V_161 ) ;
F_116 ( & V_160 -> V_162 ) ;
F_113 ( V_156 , V_147 , V_151 ) ;
F_117 ( & V_160 -> V_162 ) ;
}
}
static void
F_119 ( struct V_146 * V_147 )
{
struct V_150 * V_151 ;
struct V_19 * V_115 = V_147 -> V_149 ;
F_120 (pdo, &pdh->pdh_entries, pdo_head)
V_151 -> V_153 -> V_157 ( V_115 , V_151 ) ;
}
static void
F_121 ( struct V_146 * V_147 )
{
struct V_150 * V_151 ;
struct V_19 * V_115 = V_147 -> V_149 ;
F_120 (pdo, &pdh->pdh_entries, pdo_head)
V_151 -> V_153 -> V_158 ( V_115 , V_151 ) ;
}
static int F_122 ( struct V_19 * V_19 , void * V_42 )
{
return F_101 ( V_19 ,
V_163 , V_164 , V_165 ,
V_42 ) ;
}
static void F_123 ( struct V_19 * V_19 )
{
F_100 ( V_19 , V_163 , V_164 , V_165 ) ;
}
struct V_19 * F_124 ( struct V_19 * V_19 ,
const char * V_92 ,
struct V_87 * V_166 )
{
struct V_19 * V_98 ;
V_98 = F_104 ( V_19 , V_92 , V_143 | V_167 , NULL ,
F_122 , V_166 ) ;
if ( ! F_103 ( V_98 ) ) {
V_166 -> V_168 . V_149 = V_98 ;
F_119 ( & V_166 -> V_168 ) ;
}
return V_98 ;
}
int F_125 ( struct V_87 * V_166 )
{
struct V_19 * V_19 = V_166 -> V_168 . V_149 ;
if ( V_19 == NULL )
return 0 ;
F_121 ( & V_166 -> V_168 ) ;
V_166 -> V_168 . V_149 = NULL ;
return F_106 ( V_19 , F_123 ) ;
}
static int F_126 ( struct V_19 * V_19 , void * V_42 )
{
return F_101 ( V_19 ,
V_169 , 0 , 3 ,
V_42 ) ;
}
static void F_127 ( struct V_19 * V_19 )
{
F_100 ( V_19 , V_169 , 0 , 3 ) ;
}
struct V_19 * F_128 ( struct V_19 * V_126 , const char * V_92 ,
T_6 V_140 , struct V_170 * V_171 )
{
return F_104 ( V_126 , V_92 , V_140 , NULL ,
F_126 , V_171 ) ;
}
void F_129 ( struct V_19 * V_19 )
{
F_106 ( V_19 , F_127 ) ;
}
struct V_19 * F_130 ( const struct V_47 * V_48 ,
const unsigned char * V_172 )
{
struct V_128 V_115 = F_94 ( V_172 , strlen ( V_172 ) ) ;
return F_95 ( V_48 -> V_173 , & V_115 ) ;
}
int F_131 ( struct V_156 * V_156 )
{
struct V_159 * V_160 = F_115 ( V_156 , V_161 ) ;
V_160 -> V_174 = F_80 ( & V_175 , 0 ) ;
if ( F_103 ( V_160 -> V_174 ) )
return F_102 ( V_160 -> V_174 ) ;
F_132 ( & V_160 -> V_162 ) ;
V_160 -> V_176 = - 1 ;
return 0 ;
}
void F_133 ( struct V_156 * V_156 )
{
struct V_159 * V_160 = F_115 ( V_156 , V_161 ) ;
F_78 ( V_160 -> V_174 ) ;
}
struct V_47 * F_134 ( const struct V_156 * V_156 )
{
struct V_159 * V_160 = F_115 ( V_156 , V_161 ) ;
F_116 ( & V_160 -> V_162 ) ;
if ( V_160 -> V_177 )
return V_160 -> V_177 ;
F_117 ( & V_160 -> V_162 ) ;
return NULL ;
}
void F_135 ( const struct V_156 * V_156 )
{
struct V_159 * V_160 = F_115 ( V_156 , V_161 ) ;
F_136 ( V_160 -> V_177 == NULL ) ;
F_117 ( & V_160 -> V_162 ) ;
}
static T_2
F_137 ( struct V_25 * V_26 , const char T_3 * V_178 , T_4 V_32 )
{
return - V_83 ;
}
static int
F_138 ( struct V_84 * V_85 , void * V_86 )
{
F_50 ( V_85 , L_1 , F_139 () -> V_179 ) ;
F_50 ( V_85 , L_9 ) ;
F_50 ( V_85 , L_10 ) ;
F_50 ( V_85 , L_11 ) ;
F_50 ( V_85 , L_12 ) ;
return 0 ;
}
static int
F_140 ( struct V_41 * V_41 , struct V_25 * V_25 )
{
return F_55 ( V_25 , F_138 , NULL ) ;
}
static struct V_19 *
F_141 ( struct V_19 * V_180 , struct V_16 * V_181 )
{
int V_98 = 0 ;
struct V_19 * V_182 ;
struct V_19 * V_183 = NULL ;
struct V_19 * V_184 = NULL ;
struct V_128 V_129 = F_94 ( V_132 [ V_185 ] . V_92 ,
strlen ( V_132 [ V_185 ] . V_92 ) ) ;
V_182 = F_95 ( V_180 , & V_129 ) ;
if ( ! V_182 )
return F_82 ( - V_186 ) ;
V_98 = F_101 ( V_182 , V_187 , 0 , 1 , NULL ) ;
if ( V_98 ) {
V_184 = F_82 ( V_98 ) ;
goto V_58;
}
V_129 . V_92 = V_187 [ 0 ] . V_92 ;
V_129 . V_32 = strlen ( V_187 [ 0 ] . V_92 ) ;
V_183 = F_95 ( V_182 , & V_129 ) ;
if ( ! V_183 ) {
V_184 = F_82 ( - V_186 ) ;
goto V_58;
}
V_98 = F_101 ( V_183 , V_188 , 0 , 1 , NULL ) ;
if ( V_98 ) {
F_98 ( V_182 , V_187 , 0 , 1 ) ;
V_184 = F_82 ( V_98 ) ;
goto V_58;
}
V_184 = F_108 ( V_183 , L_13 , NULL , V_181 ) ;
if ( F_103 ( V_184 ) ) {
F_98 ( V_183 , V_188 , 0 , 1 ) ;
F_98 ( V_182 , V_187 , 0 , 1 ) ;
}
V_58:
F_20 ( V_183 ) ;
F_20 ( V_182 ) ;
return V_184 ;
}
static void
F_142 ( struct V_19 * V_184 )
{
struct V_19 * V_189 = V_184 -> V_190 ;
struct V_19 * V_191 = V_189 -> V_190 ;
F_92 ( F_19 ( V_189 ) , V_184 ) ;
F_98 ( V_189 , V_188 , 0 , 1 ) ;
F_98 ( V_191 , V_187 , 0 , 1 ) ;
F_20 ( V_184 ) ;
}
static int
F_143 ( struct V_47 * V_48 , void * V_29 , int V_192 )
{
struct V_41 * V_41 ;
struct V_19 * V_180 , * V_182 ;
struct V_156 * V_156 = F_144 ( V_48 -> V_193 ) ;
struct V_159 * V_160 = F_115 ( V_156 , V_161 ) ;
int V_8 ;
V_48 -> V_194 = V_195 ;
V_48 -> V_196 = V_197 ;
V_48 -> V_198 = V_199 ;
V_48 -> V_200 = & V_201 ;
V_48 -> V_202 = & V_203 ;
V_48 -> V_204 = 1 ;
V_41 = F_61 ( V_48 , V_110 | V_143 | V_167 ) ;
V_48 -> V_173 = V_180 = F_145 ( V_41 ) ;
if ( ! V_180 )
return - V_121 ;
if ( F_101 ( V_180 , V_132 , V_205 , V_206 , NULL ) )
return - V_121 ;
V_182 = F_141 ( V_180 , V_160 -> V_174 ) ;
if ( F_103 ( V_182 ) ) {
F_98 ( V_180 , V_132 , V_205 , V_206 ) ;
return F_102 ( V_182 ) ;
}
F_146 ( L_14 ,
V_156 , F_147 ( V_156 ) ) ;
F_116 ( & V_160 -> V_162 ) ;
V_160 -> V_177 = V_48 ;
V_8 = F_148 ( & V_3 ,
V_207 ,
V_48 ) ;
if ( V_8 )
goto V_208;
F_117 ( & V_160 -> V_162 ) ;
return 0 ;
V_208:
F_142 ( V_182 ) ;
F_148 ( & V_3 ,
V_209 ,
V_48 ) ;
V_160 -> V_177 = NULL ;
F_98 ( V_180 , V_132 , V_205 , V_206 ) ;
F_117 ( & V_160 -> V_162 ) ;
return V_8 ;
}
bool
F_149 ( struct V_156 * V_156 )
{
struct V_159 * V_160 = F_115 ( V_156 , V_161 ) ;
struct V_16 * V_17 = V_160 -> V_174 ;
return V_17 -> V_22 || V_17 -> V_44 ;
}
static struct V_19 *
F_150 ( struct V_210 * V_211 ,
int V_37 , const char * V_212 , void * V_29 )
{
struct V_156 * V_156 = V_213 -> V_214 -> V_215 ;
return F_151 ( V_211 , V_37 , V_29 , V_156 , V_156 -> V_216 , F_143 ) ;
}
static void F_152 ( struct V_47 * V_48 )
{
struct V_156 * V_156 = V_48 -> V_193 ;
struct V_159 * V_160 = F_115 ( V_156 , V_161 ) ;
F_116 ( & V_160 -> V_162 ) ;
if ( V_160 -> V_177 != V_48 ) {
F_117 ( & V_160 -> V_162 ) ;
goto V_58;
}
V_160 -> V_177 = NULL ;
F_146 ( L_15 ,
V_156 , F_147 ( V_156 ) ) ;
F_148 ( & V_3 ,
V_209 ,
V_48 ) ;
F_117 ( & V_160 -> V_162 ) ;
V_58:
F_153 ( V_48 ) ;
F_154 ( V_156 ) ;
}
static void
F_155 ( void * V_217 )
{
struct V_49 * V_50 = (struct V_49 * ) V_217 ;
F_156 ( & V_50 -> V_53 ) ;
V_50 -> V_42 = NULL ;
V_50 -> V_17 = NULL ;
F_157 ( & V_50 -> V_4 ) ;
}
int F_158 ( void )
{
int V_8 ;
V_51 = F_159 ( L_16 ,
sizeof( struct V_49 ) ,
0 , ( V_218 | V_219 |
V_220 | V_221 ) ,
F_155 ) ;
if ( ! V_51 )
return - V_121 ;
V_8 = F_160 () ;
if ( V_8 )
goto V_222;
V_8 = F_161 ( & V_223 ) ;
if ( V_8 )
goto V_224;
return 0 ;
V_224:
F_162 () ;
V_222:
F_163 ( V_51 ) ;
return V_8 ;
}
void F_164 ( void )
{
F_162 () ;
F_163 ( V_51 ) ;
F_165 ( & V_223 ) ;
}
