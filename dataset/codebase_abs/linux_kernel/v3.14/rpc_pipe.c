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
struct V_16 * V_17 ;
int V_58 ;
int V_36 = - V_59 ;
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL )
goto V_60;
V_58 = V_17 -> V_22 == 0 && V_17 -> V_46 == 0 ;
if ( V_58 && V_17 -> V_21 -> V_61 ) {
V_36 = V_17 -> V_21 -> V_61 ( V_42 ) ;
if ( V_36 )
goto V_60;
}
if ( V_27 -> V_62 & V_63 )
V_17 -> V_22 ++ ;
if ( V_27 -> V_62 & V_64 )
V_17 -> V_46 ++ ;
V_36 = 0 ;
V_60:
F_30 ( & V_42 -> V_45 ) ;
return V_36 ;
}
static int
F_38 ( struct V_42 * V_42 , struct V_26 * V_27 )
{
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_65 ;
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL )
goto V_60;
V_9 = V_27 -> V_66 ;
if ( V_9 != NULL ) {
F_14 ( & V_17 -> V_20 ) ;
V_9 -> V_12 = - V_67 ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
if ( V_27 -> V_62 & V_64 )
V_17 -> V_46 -- ;
if ( V_27 -> V_62 & V_63 ) {
V_17 -> V_22 -- ;
if ( V_17 -> V_22 == 0 ) {
F_12 ( V_15 ) ;
F_14 ( & V_17 -> V_20 ) ;
F_15 ( & V_17 -> V_17 , & V_15 ) ;
V_17 -> V_23 = 0 ;
F_17 ( & V_17 -> V_20 ) ;
F_5 ( & F_18 ( V_42 ) -> V_4 , & V_15 ,
V_17 -> V_21 -> F_6 , - V_67 ) ;
}
}
V_65 = V_17 -> V_46 == 0 && V_17 -> V_22 == 0 ;
if ( V_65 && V_17 -> V_21 -> V_48 )
V_17 -> V_21 -> V_48 ( V_42 ) ;
V_60:
F_30 ( & V_42 -> V_45 ) ;
return 0 ;
}
static T_2
F_39 ( struct V_26 * V_27 , char T_3 * V_68 , T_4 V_33 , T_5 * V_69 )
{
struct V_42 * V_42 = F_40 ( V_27 ) ;
struct V_16 * V_17 ;
struct V_7 * V_9 ;
int V_36 = 0 ;
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL ) {
V_36 = - V_37 ;
goto V_70;
}
V_9 = V_27 -> V_66 ;
if ( V_9 == NULL ) {
F_14 ( & V_17 -> V_20 ) ;
if ( ! F_7 ( & V_17 -> V_17 ) ) {
V_9 = F_8 ( V_17 -> V_17 . V_10 ,
struct V_7 ,
V_11 ) ;
F_41 ( & V_9 -> V_11 , & V_17 -> V_47 ) ;
V_17 -> V_23 -= V_9 -> V_33 ;
V_27 -> V_66 = V_9 ;
V_9 -> V_31 = 0 ;
}
F_17 ( & V_17 -> V_20 ) ;
if ( V_9 == NULL )
goto V_70;
}
V_36 = V_17 -> V_21 -> V_71 ( V_27 , V_9 , V_68 , V_33 ) ;
if ( V_36 < 0 || V_9 -> V_33 == V_9 -> V_31 ) {
V_27 -> V_66 = NULL ;
F_14 ( & V_17 -> V_20 ) ;
F_9 ( & V_9 -> V_11 ) ;
F_17 ( & V_17 -> V_20 ) ;
V_17 -> V_21 -> F_6 ( V_9 ) ;
}
V_70:
F_30 ( & V_42 -> V_45 ) ;
return V_36 ;
}
static T_2
F_42 ( struct V_26 * V_27 , const char T_3 * V_68 , T_4 V_33 , T_5 * V_69 )
{
struct V_42 * V_42 = F_40 ( V_27 ) ;
int V_36 ;
F_28 ( & V_42 -> V_45 ) ;
V_36 = - V_37 ;
if ( F_18 ( V_42 ) -> V_17 != NULL )
V_36 = F_18 ( V_42 ) -> V_17 -> V_21 -> V_72 ( V_27 , V_68 , V_33 ) ;
F_30 ( & V_42 -> V_45 ) ;
return V_36 ;
}
static unsigned int
F_43 ( struct V_26 * V_27 , struct V_73 * V_74 )
{
struct V_42 * V_42 = F_40 ( V_27 ) ;
struct V_51 * V_52 = F_18 ( V_42 ) ;
unsigned int V_75 = V_76 | V_77 ;
F_44 ( V_27 , & V_52 -> V_4 , V_74 ) ;
F_28 ( & V_42 -> V_45 ) ;
if ( V_52 -> V_17 == NULL )
V_75 |= V_78 | V_79 ;
else if ( V_27 -> V_66 || ! F_7 ( & V_52 -> V_17 -> V_17 ) )
V_75 |= V_80 | V_81 ;
F_30 ( & V_42 -> V_45 ) ;
return V_75 ;
}
static long
F_45 ( struct V_26 * V_27 , unsigned int V_82 , unsigned long V_83 )
{
struct V_42 * V_42 = F_40 ( V_27 ) ;
struct V_16 * V_17 ;
int V_33 ;
switch ( V_82 ) {
case V_84 :
F_28 ( & V_42 -> V_45 ) ;
V_17 = F_18 ( V_42 ) -> V_17 ;
if ( V_17 == NULL ) {
F_30 ( & V_42 -> V_45 ) ;
return - V_37 ;
}
F_14 ( & V_17 -> V_20 ) ;
V_33 = V_17 -> V_23 ;
if ( V_27 -> V_66 ) {
struct V_7 * V_9 ;
V_9 = V_27 -> V_66 ;
V_33 += V_9 -> V_33 - V_9 -> V_31 ;
}
F_17 ( & V_17 -> V_20 ) ;
F_30 ( & V_42 -> V_45 ) ;
return F_46 ( V_33 , ( int T_3 * ) V_83 ) ;
default:
return - V_85 ;
}
}
static int
F_47 ( struct V_86 * V_87 , void * V_88 )
{
struct V_89 * V_90 = V_87 -> V_43 ;
F_48 () ;
F_49 ( V_87 , L_1 ,
F_50 ( V_90 -> V_91 ) -> V_92 ) ;
F_49 ( V_87 , L_2 , V_90 -> V_93 -> V_94 ,
V_90 -> V_95 , V_90 -> V_96 ) ;
F_49 ( V_87 , L_3 , F_51 ( V_90 , V_97 ) ) ;
F_49 ( V_87 , L_4 , F_51 ( V_90 , V_98 ) ) ;
F_49 ( V_87 , L_5 , F_51 ( V_90 , V_99 ) ) ;
F_52 () ;
return 0 ;
}
static int
F_53 ( struct V_42 * V_42 , struct V_26 * V_26 )
{
struct V_89 * V_90 = NULL ;
int V_100 = F_54 ( V_26 , F_47 , NULL ) ;
if ( ! V_100 ) {
struct V_86 * V_87 = V_26 -> V_66 ;
F_14 ( & V_26 -> V_101 . V_19 -> V_102 ) ;
if ( ! F_55 ( V_26 -> V_101 . V_19 ) )
V_90 = F_18 ( V_42 ) -> V_43 ;
if ( V_90 != NULL && F_56 ( & V_90 -> V_103 ) ) {
F_17 ( & V_26 -> V_101 . V_19 -> V_102 ) ;
V_87 -> V_43 = V_90 ;
} else {
F_17 ( & V_26 -> V_101 . V_19 -> V_102 ) ;
F_57 ( V_42 , V_26 ) ;
V_100 = - V_85 ;
}
}
return V_100 ;
}
static int
F_58 ( struct V_42 * V_42 , struct V_26 * V_26 )
{
struct V_86 * V_87 = V_26 -> V_66 ;
struct V_89 * V_90 = (struct V_89 * ) V_87 -> V_43 ;
if ( V_90 )
F_59 ( V_90 ) ;
return F_57 ( V_42 , V_26 ) ;
}
static struct V_42 *
F_60 ( struct V_49 * V_50 , T_6 V_104 )
{
struct V_42 * V_42 = F_61 ( V_50 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_105 = F_62 () ;
V_42 -> V_106 = V_104 ;
V_42 -> V_107 = V_42 -> V_108 = V_42 -> V_109 = V_110 ;
switch ( V_104 & V_111 ) {
case V_112 :
V_42 -> V_113 = & V_114 ;
V_42 -> V_115 = & V_116 ;
F_63 ( V_42 ) ;
default:
break;
}
return V_42 ;
}
static int F_64 ( struct V_42 * V_117 , struct V_19 * V_19 ,
T_6 V_104 ,
const struct V_118 * V_113 ,
void * V_43 )
{
struct V_42 * V_42 ;
F_65 ( V_19 ) ;
V_42 = F_60 ( V_117 -> V_119 , V_104 ) ;
if ( ! V_42 )
goto V_120;
V_42 -> V_105 = F_66 ( V_117 -> V_119 , 100 ) ;
if ( V_113 )
V_42 -> V_113 = V_113 ;
if ( V_43 )
F_26 ( V_42 , V_43 ) ;
F_67 ( V_19 , V_42 ) ;
return 0 ;
V_120:
F_68 ( V_121 L_6 ,
__FILE__ , V_122 , V_19 ) ;
F_19 ( V_19 ) ;
return - V_123 ;
}
static int F_69 ( struct V_42 * V_117 , struct V_19 * V_19 ,
T_6 V_104 ,
const struct V_118 * V_113 ,
void * V_43 )
{
int V_8 ;
V_8 = F_64 ( V_117 , V_19 , V_124 | V_104 , V_113 , V_43 ) ;
if ( V_8 )
return V_8 ;
F_70 ( V_117 , V_19 ) ;
return 0 ;
}
static int F_71 ( struct V_42 * V_117 , struct V_19 * V_19 ,
T_6 V_104 ,
const struct V_118 * V_113 ,
void * V_43 )
{
int V_8 ;
V_8 = F_64 ( V_117 , V_19 , V_112 | V_104 , V_113 , V_43 ) ;
if ( V_8 )
return V_8 ;
F_63 ( V_117 ) ;
F_72 ( V_117 , V_19 ) ;
return 0 ;
}
static void
F_73 ( struct V_16 * V_17 )
{
V_17 -> V_22 = 0 ;
V_17 -> V_46 = 0 ;
F_74 ( & V_17 -> V_47 ) ;
F_74 ( & V_17 -> V_125 ) ;
F_74 ( & V_17 -> V_17 ) ;
V_17 -> V_23 = 0 ;
F_75 ( & V_17 -> V_18 ,
F_11 ) ;
V_17 -> V_21 = NULL ;
F_76 ( & V_17 -> V_20 ) ;
V_17 -> V_19 = NULL ;
}
void F_77 ( struct V_16 * V_17 )
{
F_78 ( V_17 ) ;
}
struct V_16 * F_79 ( const struct V_126 * V_21 , int V_38 )
{
struct V_16 * V_17 ;
V_17 = F_80 ( sizeof( struct V_16 ) , V_54 ) ;
if ( ! V_17 )
return F_81 ( - V_123 ) ;
F_73 ( V_17 ) ;
V_17 -> V_21 = V_21 ;
V_17 -> V_38 = V_38 ;
return V_17 ;
}
static int F_82 ( struct V_42 * V_117 , struct V_19 * V_19 ,
T_6 V_104 ,
const struct V_118 * V_113 ,
void * V_43 ,
struct V_16 * V_17 )
{
struct V_51 * V_52 ;
int V_8 ;
V_8 = F_64 ( V_117 , V_19 , V_127 | V_104 , V_113 , V_43 ) ;
if ( V_8 )
return V_8 ;
V_52 = F_18 ( V_19 -> V_24 ) ;
V_52 -> V_43 = V_43 ;
V_52 -> V_17 = V_17 ;
F_70 ( V_117 , V_19 ) ;
return 0 ;
}
static int F_83 ( struct V_42 * V_117 , struct V_19 * V_19 )
{
int V_100 ;
F_16 ( V_19 ) ;
V_100 = F_84 ( V_117 , V_19 ) ;
F_85 ( V_19 ) ;
F_19 ( V_19 ) ;
return V_100 ;
}
int F_86 ( struct V_19 * V_19 )
{
struct V_19 * V_128 ;
struct V_42 * V_117 ;
int error ;
V_128 = F_87 ( V_19 ) ;
V_117 = V_128 -> V_24 ;
F_88 ( & V_117 -> V_45 , V_129 ) ;
error = F_83 ( V_117 , V_19 ) ;
F_30 ( & V_117 -> V_45 ) ;
F_19 ( V_128 ) ;
return error ;
}
static int F_89 ( struct V_42 * V_117 , struct V_19 * V_19 )
{
int V_100 ;
F_16 ( V_19 ) ;
V_100 = F_90 ( V_117 , V_19 ) ;
F_85 ( V_19 ) ;
F_19 ( V_19 ) ;
return V_100 ;
}
static int F_91 ( struct V_42 * V_117 , struct V_19 * V_19 )
{
struct V_42 * V_42 = V_19 -> V_24 ;
F_27 ( V_42 ) ;
return F_89 ( V_117 , V_19 ) ;
}
static struct V_19 * F_92 ( struct V_19 * V_128 ,
const char * V_94 )
{
struct V_130 V_131 = F_93 ( V_94 , strlen ( V_94 ) ) ;
struct V_19 * V_19 = F_94 ( V_128 , & V_131 ) ;
if ( ! V_19 ) {
V_19 = F_95 ( V_128 , & V_131 ) ;
if ( ! V_19 )
return F_81 ( - V_123 ) ;
}
if ( V_19 -> V_24 == NULL )
return V_19 ;
F_19 ( V_19 ) ;
return F_81 ( - V_132 ) ;
}
static void F_96 ( struct V_19 * V_128 ,
const struct V_133 * V_134 ,
int V_135 , int V_136 )
{
struct V_42 * V_117 = V_128 -> V_24 ;
struct V_19 * V_19 ;
struct V_130 V_94 ;
int V_137 ;
for ( V_137 = V_135 ; V_137 < V_136 ; V_137 ++ ) {
V_94 . V_94 = V_134 [ V_137 ] . V_94 ;
V_94 . V_33 = strlen ( V_134 [ V_137 ] . V_94 ) ;
V_19 = F_94 ( V_128 , & V_94 ) ;
if ( V_19 == NULL )
continue;
if ( V_19 -> V_24 == NULL )
goto V_10;
switch ( V_19 -> V_24 -> V_106 & V_111 ) {
default:
F_97 () ;
case V_124 :
F_89 ( V_117 , V_19 ) ;
break;
case V_112 :
F_83 ( V_117 , V_19 ) ;
}
V_10:
F_19 ( V_19 ) ;
}
}
static void F_98 ( struct V_19 * V_128 ,
const struct V_133 * V_134 ,
int V_135 , int V_136 )
{
struct V_42 * V_117 = V_128 -> V_24 ;
F_88 ( & V_117 -> V_45 , V_138 ) ;
F_96 ( V_128 , V_134 , V_135 , V_136 ) ;
F_30 ( & V_117 -> V_45 ) ;
}
static int F_99 ( struct V_19 * V_128 ,
const struct V_133 * V_134 ,
int V_135 , int V_136 ,
void * V_43 )
{
struct V_42 * V_117 = V_128 -> V_24 ;
struct V_19 * V_19 ;
int V_137 , V_8 ;
F_28 ( & V_117 -> V_45 ) ;
for ( V_137 = V_135 ; V_137 < V_136 ; V_137 ++ ) {
V_19 = F_92 ( V_128 , V_134 [ V_137 ] . V_94 ) ;
V_8 = F_100 ( V_19 ) ;
if ( F_101 ( V_19 ) )
goto V_139;
switch ( V_134 [ V_137 ] . V_104 & V_111 ) {
default:
F_97 () ;
case V_124 :
V_8 = F_69 ( V_117 , V_19 ,
V_134 [ V_137 ] . V_104 ,
V_134 [ V_137 ] . V_113 ,
V_43 ) ;
break;
case V_112 :
V_8 = F_71 ( V_117 , V_19 ,
V_134 [ V_137 ] . V_104 ,
NULL ,
V_43 ) ;
}
if ( V_8 != 0 )
goto V_139;
}
F_30 ( & V_117 -> V_45 ) ;
return 0 ;
V_139:
F_96 ( V_128 , V_134 , V_135 , V_136 ) ;
F_30 ( & V_117 -> V_45 ) ;
F_68 ( V_121 L_7 ,
__FILE__ , V_122 , V_128 ) ;
return V_8 ;
}
static struct V_19 * F_102 ( struct V_19 * V_128 ,
const char * V_94 , T_6 V_104 , void * V_43 ,
int (* F_103)( struct V_19 * , void * ) , void * V_140 )
{
struct V_19 * V_19 ;
struct V_42 * V_117 = V_128 -> V_24 ;
int error ;
F_88 ( & V_117 -> V_45 , V_129 ) ;
V_19 = F_92 ( V_128 , V_94 ) ;
if ( F_101 ( V_19 ) )
goto V_60;
error = F_71 ( V_117 , V_19 , V_104 , NULL , V_43 ) ;
if ( error != 0 )
goto V_120;
if ( F_103 != NULL ) {
error = F_103 ( V_19 , V_140 ) ;
if ( error )
goto V_141;
}
V_60:
F_30 ( & V_117 -> V_45 ) ;
return V_19 ;
V_141:
F_83 ( V_117 , V_19 ) ;
V_120:
V_19 = F_81 ( error ) ;
goto V_60;
}
static int F_104 ( struct V_19 * V_19 ,
void (* F_105)( struct V_19 * ) )
{
struct V_19 * V_128 ;
struct V_42 * V_117 ;
int error ;
V_128 = F_87 ( V_19 ) ;
V_117 = V_128 -> V_24 ;
F_88 ( & V_117 -> V_45 , V_129 ) ;
if ( F_105 != NULL )
F_105 ( V_19 ) ;
error = F_83 ( V_117 , V_19 ) ;
F_30 ( & V_117 -> V_45 ) ;
F_19 ( V_128 ) ;
return error ;
}
struct V_19 * F_106 ( struct V_19 * V_128 , const char * V_94 ,
void * V_43 , struct V_16 * V_17 )
{
struct V_19 * V_19 ;
struct V_42 * V_117 = V_128 -> V_24 ;
T_6 V_142 = V_127 | V_143 | V_144 ;
int V_8 ;
if ( V_17 -> V_21 -> V_71 == NULL )
V_142 &= ~ V_145 ;
if ( V_17 -> V_21 -> V_72 == NULL )
V_142 &= ~ V_146 ;
F_88 ( & V_117 -> V_45 , V_129 ) ;
V_19 = F_92 ( V_128 , V_94 ) ;
if ( F_101 ( V_19 ) )
goto V_60;
V_8 = F_82 ( V_117 , V_19 , V_142 , & V_147 ,
V_43 , V_17 ) ;
if ( V_8 )
goto V_120;
V_60:
F_30 ( & V_117 -> V_45 ) ;
return V_19 ;
V_120:
V_19 = F_81 ( V_8 ) ;
F_68 ( V_121 L_8 ,
__FILE__ , V_122 , V_128 , V_94 ,
V_8 ) ;
goto V_60;
}
int
F_107 ( struct V_19 * V_19 )
{
struct V_19 * V_128 ;
struct V_42 * V_117 ;
int error = 0 ;
V_128 = F_87 ( V_19 ) ;
V_117 = V_128 -> V_24 ;
F_88 ( & V_117 -> V_45 , V_129 ) ;
error = F_91 ( V_117 , V_19 ) ;
F_30 ( & V_117 -> V_45 ) ;
F_19 ( V_128 ) ;
return error ;
}
void F_108 ( struct V_148 * V_149 )
{
F_74 ( & V_149 -> V_150 ) ;
V_149 -> V_151 = NULL ;
}
void F_109 ( struct V_152 * V_153 ,
const struct V_154 * V_155 ,
void * V_156 )
{
F_74 ( & V_153 -> V_157 ) ;
V_153 -> V_155 = V_155 ;
V_153 -> V_156 = V_156 ;
}
static int
F_110 ( struct V_158 * V_158 ,
struct V_148 * V_149 ,
struct V_152 * V_153 )
{
int V_100 = 0 ;
if ( V_149 -> V_151 )
V_100 = V_153 -> V_155 -> V_159 ( V_149 -> V_151 , V_153 ) ;
if ( V_100 == 0 )
F_24 ( & V_153 -> V_157 , & V_149 -> V_150 ) ;
return V_100 ;
}
static void
F_111 ( struct V_158 * V_158 ,
struct V_148 * V_149 ,
struct V_152 * V_153 )
{
if ( V_149 -> V_151 )
V_153 -> V_155 -> V_160 ( V_149 -> V_151 , V_153 ) ;
F_9 ( & V_153 -> V_157 ) ;
}
int
F_112 ( struct V_158 * V_158 ,
struct V_148 * V_149 ,
struct V_152 * V_153 )
{
int V_100 = 0 ;
if ( F_7 ( & V_153 -> V_157 ) ) {
struct V_161 * V_162 = F_113 ( V_158 , V_163 ) ;
F_28 ( & V_162 -> V_164 ) ;
V_100 = F_110 ( V_158 , V_149 , V_153 ) ;
F_30 ( & V_162 -> V_164 ) ;
}
return V_100 ;
}
void
F_114 ( struct V_158 * V_158 ,
struct V_148 * V_149 ,
struct V_152 * V_153 )
{
if ( ! F_7 ( & V_153 -> V_157 ) ) {
struct V_161 * V_162 = F_113 ( V_158 , V_163 ) ;
F_28 ( & V_162 -> V_164 ) ;
F_111 ( V_158 , V_149 , V_153 ) ;
F_30 ( & V_162 -> V_164 ) ;
}
}
static void
F_115 ( struct V_148 * V_149 )
{
struct V_152 * V_153 ;
struct V_19 * V_117 = V_149 -> V_151 ;
F_116 (pdo, &pdh->pdh_entries, pdo_head)
V_153 -> V_155 -> V_159 ( V_117 , V_153 ) ;
}
static void
F_117 ( struct V_148 * V_149 )
{
struct V_152 * V_153 ;
struct V_19 * V_117 = V_149 -> V_151 ;
F_116 (pdo, &pdh->pdh_entries, pdo_head)
V_153 -> V_155 -> V_160 ( V_117 , V_153 ) ;
}
static int F_118 ( struct V_19 * V_19 , void * V_43 )
{
return F_99 ( V_19 ,
V_165 , V_166 , V_167 ,
V_43 ) ;
}
static void F_119 ( struct V_19 * V_19 )
{
F_98 ( V_19 , V_165 , V_166 , V_167 ) ;
}
struct V_19 * F_120 ( struct V_19 * V_19 ,
const char * V_94 ,
struct V_89 * V_168 )
{
struct V_19 * V_100 ;
V_100 = F_102 ( V_19 , V_94 , V_145 | V_169 , NULL ,
F_118 , V_168 ) ;
if ( ! F_101 ( V_100 ) ) {
V_168 -> V_170 . V_151 = V_100 ;
F_115 ( & V_168 -> V_170 ) ;
}
return V_100 ;
}
int F_121 ( struct V_89 * V_168 )
{
struct V_19 * V_19 = V_168 -> V_170 . V_151 ;
if ( V_19 == NULL )
return 0 ;
F_117 ( & V_168 -> V_170 ) ;
V_168 -> V_170 . V_151 = NULL ;
return F_104 ( V_19 , F_119 ) ;
}
static int F_122 ( struct V_19 * V_19 , void * V_43 )
{
return F_99 ( V_19 ,
V_171 , 0 , 3 ,
V_43 ) ;
}
static void F_123 ( struct V_19 * V_19 )
{
F_98 ( V_19 , V_171 , 0 , 3 ) ;
}
struct V_19 * F_124 ( struct V_19 * V_128 , const char * V_94 ,
T_6 V_142 , struct V_172 * V_173 )
{
return F_102 ( V_128 , V_94 , V_142 , NULL ,
F_122 , V_173 ) ;
}
void F_125 ( struct V_19 * V_19 )
{
F_104 ( V_19 , F_123 ) ;
}
struct V_19 * F_126 ( const struct V_49 * V_50 ,
const unsigned char * V_174 )
{
struct V_130 V_117 = F_93 ( V_174 , strlen ( V_174 ) ) ;
return F_94 ( V_50 -> V_175 , & V_117 ) ;
}
int F_127 ( struct V_158 * V_158 )
{
struct V_161 * V_162 = F_113 ( V_158 , V_163 ) ;
V_162 -> V_176 = F_79 ( & V_177 , 0 ) ;
if ( F_101 ( V_162 -> V_176 ) )
return F_100 ( V_162 -> V_176 ) ;
F_128 ( & V_162 -> V_164 ) ;
V_162 -> V_178 = - 1 ;
return 0 ;
}
void F_129 ( struct V_158 * V_158 )
{
struct V_161 * V_162 = F_113 ( V_158 , V_163 ) ;
F_77 ( V_162 -> V_176 ) ;
}
struct V_49 * F_130 ( const struct V_158 * V_158 )
{
struct V_161 * V_162 = F_113 ( V_158 , V_163 ) ;
F_28 ( & V_162 -> V_164 ) ;
if ( V_162 -> V_179 )
return V_162 -> V_179 ;
F_30 ( & V_162 -> V_164 ) ;
return NULL ;
}
void F_131 ( const struct V_158 * V_158 )
{
struct V_161 * V_162 = F_113 ( V_158 , V_163 ) ;
F_132 ( V_162 -> V_179 == NULL ) ;
F_30 ( & V_162 -> V_164 ) ;
}
static T_2
F_133 ( struct V_26 * V_27 , const char T_3 * V_180 , T_4 V_33 )
{
return - V_85 ;
}
static int
F_134 ( struct V_86 * V_87 , void * V_88 )
{
F_49 ( V_87 , L_1 , F_135 () -> V_181 ) ;
F_49 ( V_87 , L_9 ) ;
F_49 ( V_87 , L_10 ) ;
F_49 ( V_87 , L_11 ) ;
F_49 ( V_87 , L_12 ) ;
return 0 ;
}
static int
F_136 ( struct V_42 * V_42 , struct V_26 * V_26 )
{
return F_54 ( V_26 , F_134 , NULL ) ;
}
static struct V_19 *
F_137 ( struct V_19 * V_182 , struct V_16 * V_183 )
{
int V_100 = 0 ;
struct V_19 * V_184 ;
struct V_19 * V_185 = NULL ;
struct V_19 * V_186 = NULL ;
struct V_130 V_131 = F_93 ( V_134 [ V_187 ] . V_94 ,
strlen ( V_134 [ V_187 ] . V_94 ) ) ;
V_184 = F_94 ( V_182 , & V_131 ) ;
if ( ! V_184 )
return F_81 ( - V_188 ) ;
V_100 = F_99 ( V_184 , V_189 , 0 , 1 , NULL ) ;
if ( V_100 ) {
V_186 = F_81 ( V_100 ) ;
goto V_60;
}
V_131 . V_94 = V_189 [ 0 ] . V_94 ;
V_131 . V_33 = strlen ( V_189 [ 0 ] . V_94 ) ;
V_185 = F_94 ( V_184 , & V_131 ) ;
if ( ! V_185 ) {
V_186 = F_81 ( - V_188 ) ;
goto V_60;
}
V_100 = F_99 ( V_185 , V_190 , 0 , 1 , NULL ) ;
if ( V_100 ) {
F_96 ( V_184 , V_189 , 0 , 1 ) ;
V_186 = F_81 ( V_100 ) ;
goto V_60;
}
V_186 = F_106 ( V_185 , L_13 , NULL , V_183 ) ;
if ( F_101 ( V_186 ) ) {
F_96 ( V_185 , V_190 , 0 , 1 ) ;
F_96 ( V_184 , V_189 , 0 , 1 ) ;
}
V_60:
F_19 ( V_185 ) ;
F_19 ( V_184 ) ;
return V_186 ;
}
static void
F_138 ( struct V_19 * V_186 )
{
struct V_19 * V_191 = V_186 -> V_192 ;
struct V_19 * V_193 = V_191 -> V_192 ;
F_91 ( V_191 -> V_24 , V_186 ) ;
F_96 ( V_191 , V_190 , 0 , 1 ) ;
F_96 ( V_193 , V_189 , 0 , 1 ) ;
F_19 ( V_186 ) ;
}
static int
F_139 ( struct V_49 * V_50 , void * V_30 , int V_194 )
{
struct V_42 * V_42 ;
struct V_19 * V_182 , * V_184 ;
struct V_158 * V_158 = V_30 ;
struct V_161 * V_162 = F_113 ( V_158 , V_163 ) ;
int V_8 ;
V_50 -> V_195 = V_196 ;
V_50 -> V_197 = V_198 ;
V_50 -> V_199 = V_200 ;
V_50 -> V_201 = & V_202 ;
V_50 -> V_203 = & V_204 ;
V_50 -> V_205 = 1 ;
V_42 = F_60 ( V_50 , V_112 | V_145 | V_169 ) ;
V_50 -> V_175 = V_182 = F_140 ( V_42 ) ;
if ( ! V_182 )
return - V_123 ;
if ( F_99 ( V_182 , V_134 , V_206 , V_207 , NULL ) )
return - V_123 ;
V_184 = F_137 ( V_182 , V_162 -> V_176 ) ;
if ( F_101 ( V_184 ) ) {
F_96 ( V_182 , V_134 , V_206 , V_207 ) ;
return F_100 ( V_184 ) ;
}
F_141 ( L_14 ,
V_158 , F_142 ( V_158 ) ) ;
F_28 ( & V_162 -> V_164 ) ;
V_162 -> V_179 = V_50 ;
V_8 = F_143 ( & V_3 ,
V_208 ,
V_50 ) ;
if ( V_8 )
goto V_209;
V_50 -> V_210 = F_144 ( V_158 ) ;
F_30 ( & V_162 -> V_164 ) ;
return 0 ;
V_209:
F_138 ( V_184 ) ;
F_143 ( & V_3 ,
V_211 ,
V_50 ) ;
V_162 -> V_179 = NULL ;
F_96 ( V_182 , V_134 , V_206 , V_207 ) ;
F_30 ( & V_162 -> V_164 ) ;
return V_8 ;
}
bool
F_145 ( struct V_158 * V_158 )
{
struct V_161 * V_162 = F_113 ( V_158 , V_163 ) ;
struct V_16 * V_17 = V_162 -> V_176 ;
return V_17 -> V_22 || V_17 -> V_46 ;
}
static struct V_19 *
F_146 ( struct V_212 * V_213 ,
int V_38 , const char * V_214 , void * V_30 )
{
return F_147 ( V_213 , V_38 , V_215 -> V_216 -> V_217 , F_139 ) ;
}
static void F_148 ( struct V_49 * V_50 )
{
struct V_158 * V_158 = V_50 -> V_210 ;
struct V_161 * V_162 = F_113 ( V_158 , V_163 ) ;
F_28 ( & V_162 -> V_164 ) ;
if ( V_162 -> V_179 != V_50 ) {
F_30 ( & V_162 -> V_164 ) ;
goto V_60;
}
V_162 -> V_179 = NULL ;
F_141 ( L_15 ,
V_158 , F_142 ( V_158 ) ) ;
F_143 ( & V_3 ,
V_211 ,
V_50 ) ;
F_30 ( & V_162 -> V_164 ) ;
F_149 ( V_158 ) ;
V_60:
F_150 ( V_50 ) ;
}
static void
F_151 ( void * V_218 )
{
struct V_51 * V_52 = (struct V_51 * ) V_218 ;
F_152 ( & V_52 -> V_55 ) ;
V_52 -> V_43 = NULL ;
V_52 -> V_17 = NULL ;
F_153 ( & V_52 -> V_4 ) ;
}
int F_154 ( void )
{
int V_8 ;
V_53 = F_155 ( L_16 ,
sizeof( struct V_51 ) ,
0 , ( V_219 | V_220 |
V_221 ) ,
F_151 ) ;
if ( ! V_53 )
return - V_123 ;
V_8 = F_156 () ;
if ( V_8 )
goto V_222;
V_8 = F_157 ( & V_223 ) ;
if ( V_8 )
goto V_224;
return 0 ;
V_224:
F_158 () ;
V_222:
F_159 ( V_53 ) ;
return V_8 ;
}
void F_160 ( void )
{
F_158 () ;
F_159 ( V_53 ) ;
F_161 ( & V_223 ) ;
}
