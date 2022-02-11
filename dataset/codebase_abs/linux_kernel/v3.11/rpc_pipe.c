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
F_50 ( V_94 , L_2 , V_97 -> V_100 ,
V_97 -> V_101 , V_97 -> V_102 ) ;
F_50 ( V_94 , L_3 , F_52 ( V_97 , V_103 ) ) ;
F_50 ( V_94 , L_4 , F_52 ( V_97 , V_104 ) ) ;
F_50 ( V_94 , L_5 , F_52 ( V_97 , V_105 ) ) ;
F_53 () ;
return 0 ;
}
static int
F_54 ( struct V_42 * V_42 , struct V_26 * V_26 )
{
struct V_96 * V_97 = NULL ;
int V_106 = F_55 ( V_26 , F_48 , NULL ) ;
if ( ! V_106 ) {
struct V_93 * V_94 = V_26 -> V_73 ;
F_14 ( & V_26 -> V_107 . V_19 -> V_108 ) ;
if ( ! F_56 ( V_26 -> V_107 . V_19 ) )
V_97 = F_18 ( V_42 ) -> V_43 ;
if ( V_97 != NULL && F_57 ( & V_97 -> V_109 ) ) {
F_17 ( & V_26 -> V_107 . V_19 -> V_108 ) ;
V_94 -> V_43 = V_97 ;
} else {
F_17 ( & V_26 -> V_107 . V_19 -> V_108 ) ;
F_58 ( V_42 , V_26 ) ;
V_106 = - V_92 ;
}
}
return V_106 ;
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
static int F_61 ( const struct V_19 * V_19 )
{
return 1 ;
}
static struct V_19 *
F_62 ( struct V_42 * V_110 , struct V_19 * V_19 , unsigned int V_38 )
{
if ( V_19 -> V_111 . V_33 > V_112 )
return F_63 ( - V_113 ) ;
F_64 ( V_19 , NULL ) ;
return NULL ;
}
static struct V_42 *
F_65 ( struct V_49 * V_50 , T_6 V_114 )
{
struct V_42 * V_42 = F_66 ( V_50 ) ;
if ( ! V_42 )
return NULL ;
V_42 -> V_115 = F_67 () ;
V_42 -> V_116 = V_114 ;
V_42 -> V_117 = V_42 -> V_118 = V_42 -> V_119 = V_120 ;
switch ( V_114 & V_121 ) {
case V_122 :
V_42 -> V_123 = & V_124 ;
V_42 -> V_125 = & V_126 ;
F_68 ( V_42 ) ;
default:
break;
}
return V_42 ;
}
static int F_69 ( struct V_42 * V_110 , struct V_19 * V_19 ,
T_6 V_114 ,
const struct V_127 * V_123 ,
void * V_43 )
{
struct V_42 * V_42 ;
F_70 ( V_19 ) ;
V_42 = F_65 ( V_110 -> V_59 , V_114 ) ;
if ( ! V_42 )
goto V_128;
V_42 -> V_115 = F_71 ( V_110 -> V_59 , 100 ) ;
if ( V_123 )
V_42 -> V_123 = V_123 ;
if ( V_43 )
F_26 ( V_42 , V_43 ) ;
F_64 ( V_19 , V_42 ) ;
return 0 ;
V_128:
F_72 ( V_129 L_6 ,
__FILE__ , V_130 , V_19 -> V_111 . V_131 ) ;
F_19 ( V_19 ) ;
return - V_132 ;
}
static int F_73 ( struct V_42 * V_110 , struct V_19 * V_19 ,
T_6 V_114 ,
const struct V_127 * V_123 ,
void * V_43 )
{
int V_8 ;
V_8 = F_69 ( V_110 , V_19 , V_133 | V_114 , V_123 , V_43 ) ;
if ( V_8 )
return V_8 ;
F_74 ( V_110 , V_19 ) ;
return 0 ;
}
static int F_75 ( struct V_42 * V_110 , struct V_19 * V_19 ,
T_6 V_114 ,
const struct V_127 * V_123 ,
void * V_43 )
{
int V_8 ;
V_8 = F_69 ( V_110 , V_19 , V_122 | V_114 , V_123 , V_43 ) ;
if ( V_8 )
return V_8 ;
F_68 ( V_110 ) ;
F_76 ( V_110 , V_19 ) ;
return 0 ;
}
static void
F_77 ( struct V_16 * V_17 )
{
V_17 -> V_22 = 0 ;
V_17 -> V_46 = 0 ;
F_78 ( & V_17 -> V_47 ) ;
F_78 ( & V_17 -> V_134 ) ;
F_78 ( & V_17 -> V_17 ) ;
V_17 -> V_23 = 0 ;
F_79 ( & V_17 -> V_18 ,
F_11 ) ;
V_17 -> V_21 = NULL ;
F_80 ( & V_17 -> V_20 ) ;
V_17 -> V_19 = NULL ;
}
void F_81 ( struct V_16 * V_17 )
{
F_82 ( V_17 ) ;
}
struct V_16 * F_83 ( const struct V_135 * V_21 , int V_38 )
{
struct V_16 * V_17 ;
V_17 = F_84 ( sizeof( struct V_16 ) , V_54 ) ;
if ( ! V_17 )
return F_63 ( - V_132 ) ;
F_77 ( V_17 ) ;
V_17 -> V_21 = V_21 ;
V_17 -> V_38 = V_38 ;
return V_17 ;
}
static int F_85 ( struct V_42 * V_110 , struct V_19 * V_19 ,
T_6 V_114 ,
const struct V_127 * V_123 ,
void * V_43 ,
struct V_16 * V_17 )
{
struct V_51 * V_52 ;
int V_8 ;
V_8 = F_69 ( V_110 , V_19 , V_136 | V_114 , V_123 , V_43 ) ;
if ( V_8 )
return V_8 ;
V_52 = F_18 ( V_19 -> V_24 ) ;
V_52 -> V_43 = V_43 ;
V_52 -> V_17 = V_17 ;
F_74 ( V_110 , V_19 ) ;
return 0 ;
}
static int F_86 ( struct V_42 * V_110 , struct V_19 * V_19 )
{
int V_106 ;
F_16 ( V_19 ) ;
V_106 = F_87 ( V_110 , V_19 ) ;
F_88 ( V_19 ) ;
F_19 ( V_19 ) ;
return V_106 ;
}
int F_89 ( struct V_19 * V_19 )
{
struct V_19 * V_137 ;
struct V_42 * V_110 ;
int error ;
V_137 = F_90 ( V_19 ) ;
V_110 = V_137 -> V_24 ;
F_91 ( & V_110 -> V_45 , V_138 ) ;
error = F_86 ( V_110 , V_19 ) ;
F_30 ( & V_110 -> V_45 ) ;
F_19 ( V_137 ) ;
return error ;
}
static int F_92 ( struct V_42 * V_110 , struct V_19 * V_19 )
{
int V_106 ;
F_16 ( V_19 ) ;
V_106 = F_93 ( V_110 , V_19 ) ;
F_88 ( V_19 ) ;
F_19 ( V_19 ) ;
return V_106 ;
}
static int F_94 ( struct V_42 * V_110 , struct V_19 * V_19 )
{
struct V_42 * V_42 = V_19 -> V_24 ;
F_27 ( V_42 ) ;
return F_92 ( V_110 , V_19 ) ;
}
static struct V_19 * F_95 ( struct V_19 * V_137 ,
const char * V_131 )
{
struct V_139 V_140 = F_96 ( V_131 , strlen ( V_131 ) ) ;
struct V_19 * V_19 = F_97 ( V_137 , & V_140 ) ;
if ( ! V_19 ) {
V_19 = F_98 ( V_137 , & V_140 ) ;
if ( ! V_19 )
return F_63 ( - V_132 ) ;
}
if ( V_19 -> V_24 == NULL )
return V_19 ;
F_19 ( V_19 ) ;
return F_63 ( - V_141 ) ;
}
static void F_99 ( struct V_19 * V_137 ,
const struct V_142 * V_143 ,
int V_144 , int V_145 )
{
struct V_42 * V_110 = V_137 -> V_24 ;
struct V_19 * V_19 ;
struct V_139 V_131 ;
int V_146 ;
for ( V_146 = V_144 ; V_146 < V_145 ; V_146 ++ ) {
V_131 . V_131 = V_143 [ V_146 ] . V_131 ;
V_131 . V_33 = strlen ( V_143 [ V_146 ] . V_131 ) ;
V_19 = F_97 ( V_137 , & V_131 ) ;
if ( V_19 == NULL )
continue;
if ( V_19 -> V_24 == NULL )
goto V_10;
switch ( V_19 -> V_24 -> V_116 & V_121 ) {
default:
F_100 () ;
case V_133 :
F_92 ( V_110 , V_19 ) ;
break;
case V_122 :
F_86 ( V_110 , V_19 ) ;
}
V_10:
F_19 ( V_19 ) ;
}
}
static void F_101 ( struct V_19 * V_137 ,
const struct V_142 * V_143 ,
int V_144 , int V_145 )
{
struct V_42 * V_110 = V_137 -> V_24 ;
F_91 ( & V_110 -> V_45 , V_147 ) ;
F_99 ( V_137 , V_143 , V_144 , V_145 ) ;
F_30 ( & V_110 -> V_45 ) ;
}
static int F_102 ( struct V_19 * V_137 ,
const struct V_142 * V_143 ,
int V_144 , int V_145 ,
void * V_43 )
{
struct V_42 * V_110 = V_137 -> V_24 ;
struct V_19 * V_19 ;
int V_146 , V_8 ;
F_28 ( & V_110 -> V_45 ) ;
for ( V_146 = V_144 ; V_146 < V_145 ; V_146 ++ ) {
V_19 = F_95 ( V_137 , V_143 [ V_146 ] . V_131 ) ;
V_8 = F_103 ( V_19 ) ;
if ( F_104 ( V_19 ) )
goto V_148;
switch ( V_143 [ V_146 ] . V_114 & V_121 ) {
default:
F_100 () ;
case V_133 :
V_8 = F_73 ( V_110 , V_19 ,
V_143 [ V_146 ] . V_114 ,
V_143 [ V_146 ] . V_123 ,
V_43 ) ;
break;
case V_122 :
V_8 = F_75 ( V_110 , V_19 ,
V_143 [ V_146 ] . V_114 ,
NULL ,
V_43 ) ;
}
if ( V_8 != 0 )
goto V_148;
}
F_30 ( & V_110 -> V_45 ) ;
return 0 ;
V_148:
F_99 ( V_137 , V_143 , V_144 , V_145 ) ;
F_30 ( & V_110 -> V_45 ) ;
F_72 ( V_129 L_7 ,
__FILE__ , V_130 , V_137 -> V_111 . V_131 ) ;
return V_8 ;
}
static struct V_19 * F_105 ( struct V_19 * V_137 ,
const char * V_131 , T_6 V_114 , void * V_43 ,
int (* F_106)( struct V_19 * , void * ) , void * V_149 )
{
struct V_19 * V_19 ;
struct V_42 * V_110 = V_137 -> V_24 ;
int error ;
F_91 ( & V_110 -> V_45 , V_138 ) ;
V_19 = F_95 ( V_137 , V_131 ) ;
if ( F_104 ( V_19 ) )
goto V_67;
error = F_75 ( V_110 , V_19 , V_114 , NULL , V_43 ) ;
if ( error != 0 )
goto V_128;
if ( F_106 != NULL ) {
error = F_106 ( V_19 , V_149 ) ;
if ( error )
goto V_150;
}
V_67:
F_30 ( & V_110 -> V_45 ) ;
return V_19 ;
V_150:
F_86 ( V_110 , V_19 ) ;
V_128:
V_19 = F_63 ( error ) ;
goto V_67;
}
static int F_107 ( struct V_19 * V_19 ,
void (* F_108)( struct V_19 * ) )
{
struct V_19 * V_137 ;
struct V_42 * V_110 ;
int error ;
V_137 = F_90 ( V_19 ) ;
V_110 = V_137 -> V_24 ;
F_91 ( & V_110 -> V_45 , V_138 ) ;
if ( F_108 != NULL )
F_108 ( V_19 ) ;
error = F_86 ( V_110 , V_19 ) ;
F_30 ( & V_110 -> V_45 ) ;
F_19 ( V_137 ) ;
return error ;
}
struct V_19 * F_109 ( struct V_19 * V_137 , const char * V_131 ,
void * V_43 , struct V_16 * V_17 )
{
struct V_19 * V_19 ;
struct V_42 * V_110 = V_137 -> V_24 ;
T_6 V_151 = V_136 | V_152 | V_153 ;
int V_8 ;
if ( V_17 -> V_21 -> V_78 == NULL )
V_151 &= ~ V_154 ;
if ( V_17 -> V_21 -> V_79 == NULL )
V_151 &= ~ V_155 ;
F_91 ( & V_110 -> V_45 , V_138 ) ;
V_19 = F_95 ( V_137 , V_131 ) ;
if ( F_104 ( V_19 ) )
goto V_67;
V_8 = F_85 ( V_110 , V_19 , V_151 , & V_156 ,
V_43 , V_17 ) ;
if ( V_8 )
goto V_128;
V_67:
F_30 ( & V_110 -> V_45 ) ;
return V_19 ;
V_128:
V_19 = F_63 ( V_8 ) ;
F_72 ( V_129 L_8 ,
__FILE__ , V_130 , V_137 -> V_111 . V_131 , V_131 ,
V_8 ) ;
goto V_67;
}
int
F_110 ( struct V_19 * V_19 )
{
struct V_19 * V_137 ;
struct V_42 * V_110 ;
int error = 0 ;
V_137 = F_90 ( V_19 ) ;
V_110 = V_137 -> V_24 ;
F_91 ( & V_110 -> V_45 , V_138 ) ;
error = F_94 ( V_110 , V_19 ) ;
F_30 ( & V_110 -> V_45 ) ;
F_19 ( V_137 ) ;
return error ;
}
static int F_111 ( struct V_19 * V_19 , void * V_43 )
{
return F_102 ( V_19 ,
V_157 , V_158 , V_159 ,
V_43 ) ;
}
static void F_112 ( struct V_19 * V_19 )
{
F_101 ( V_19 , V_157 , V_158 , V_159 ) ;
}
struct V_19 * F_113 ( struct V_19 * V_19 ,
const char * V_131 ,
struct V_96 * V_160 )
{
return F_105 ( V_19 , V_131 , V_154 | V_161 , NULL ,
F_111 , V_160 ) ;
}
int F_114 ( struct V_19 * V_19 )
{
return F_107 ( V_19 , F_112 ) ;
}
static int F_115 ( struct V_19 * V_19 , void * V_43 )
{
return F_102 ( V_19 ,
V_162 , 0 , 3 ,
V_43 ) ;
}
static void F_116 ( struct V_19 * V_19 )
{
F_101 ( V_19 , V_162 , 0 , 3 ) ;
}
struct V_19 * F_117 ( struct V_19 * V_137 , const char * V_131 ,
T_6 V_151 , struct V_163 * V_164 )
{
return F_105 ( V_137 , V_131 , V_151 , NULL ,
F_115 , V_164 ) ;
}
void F_118 ( struct V_19 * V_19 )
{
F_107 ( V_19 , F_116 ) ;
}
struct V_19 * F_119 ( const struct V_49 * V_50 ,
const unsigned char * V_165 )
{
struct V_139 V_110 = F_96 ( V_165 , strlen ( V_165 ) ) ;
return F_97 ( V_50 -> V_166 , & V_110 ) ;
}
void F_120 ( struct V_58 * V_58 )
{
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_121 ( & V_62 -> V_167 ) ;
V_62 -> V_66 = 1 ;
V_62 -> V_168 = - 1 ;
}
struct V_49 * F_122 ( const struct V_58 * V_58 )
{
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_28 ( & V_62 -> V_167 ) ;
if ( V_62 -> V_169 )
return V_62 -> V_169 ;
F_30 ( & V_62 -> V_167 ) ;
return NULL ;
}
void F_123 ( const struct V_58 * V_58 )
{
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_124 ( V_62 -> V_169 == NULL ) ;
F_30 ( & V_62 -> V_167 ) ;
}
static int
F_125 ( struct V_49 * V_50 , void * V_30 , int V_170 )
{
struct V_42 * V_42 ;
struct V_19 * V_171 ;
struct V_58 * V_58 = V_30 ;
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
int V_8 ;
V_50 -> V_172 = V_173 ;
V_50 -> V_174 = V_175 ;
V_50 -> V_176 = V_177 ;
V_50 -> V_178 = & V_179 ;
V_50 -> V_180 = & V_181 ;
V_50 -> V_182 = 1 ;
V_42 = F_65 ( V_50 , V_122 | V_154 | V_161 ) ;
V_50 -> V_166 = V_171 = F_126 ( V_42 ) ;
if ( ! V_171 )
return - V_132 ;
if ( F_102 ( V_171 , V_143 , V_183 , V_184 , NULL ) )
return - V_132 ;
F_127 ( L_9 ,
V_58 , F_128 ( V_58 ) ) ;
F_28 ( & V_62 -> V_167 ) ;
V_62 -> V_169 = V_50 ;
V_8 = F_129 ( & V_3 ,
V_185 ,
V_50 ) ;
if ( V_8 )
goto V_186;
V_50 -> V_60 = F_130 ( V_58 ) ;
F_30 ( & V_62 -> V_167 ) ;
return 0 ;
V_186:
F_129 ( & V_3 ,
V_187 ,
V_50 ) ;
V_62 -> V_169 = NULL ;
F_99 ( V_171 , V_143 , V_183 , V_184 ) ;
F_30 ( & V_62 -> V_167 ) ;
return V_8 ;
}
static struct V_19 *
F_131 ( struct V_188 * V_189 ,
int V_38 , const char * V_190 , void * V_30 )
{
return F_132 ( V_189 , V_38 , V_191 -> V_192 -> V_193 , F_125 ) ;
}
static void F_133 ( struct V_49 * V_50 )
{
struct V_58 * V_58 = V_50 -> V_60 ;
struct V_61 * V_62 = F_38 ( V_58 , V_63 ) ;
F_28 ( & V_62 -> V_167 ) ;
if ( V_62 -> V_169 != V_50 ) {
F_30 ( & V_62 -> V_167 ) ;
goto V_67;
}
V_62 -> V_169 = NULL ;
F_127 ( L_10 ,
V_58 , F_128 ( V_58 ) ) ;
F_129 ( & V_3 ,
V_187 ,
V_50 ) ;
F_30 ( & V_62 -> V_167 ) ;
F_134 ( V_58 ) ;
V_67:
F_135 ( V_50 ) ;
}
static void
F_136 ( void * V_194 )
{
struct V_51 * V_52 = (struct V_51 * ) V_194 ;
F_137 ( & V_52 -> V_55 ) ;
V_52 -> V_43 = NULL ;
V_52 -> V_17 = NULL ;
F_138 ( & V_52 -> V_4 ) ;
}
int F_139 ( void )
{
int V_8 ;
V_53 = F_140 ( L_11 ,
sizeof( struct V_51 ) ,
0 , ( V_195 | V_196 |
V_197 ) ,
F_136 ) ;
if ( ! V_53 )
return - V_132 ;
V_8 = F_141 () ;
if ( V_8 )
goto V_198;
V_8 = F_142 ( & V_199 ) ;
if ( V_8 )
goto V_200;
return 0 ;
V_200:
F_143 () ;
V_198:
F_144 ( V_53 ) ;
return V_8 ;
}
void F_145 ( void )
{
F_143 () ;
F_144 ( V_53 ) ;
F_146 ( & V_199 ) ;
}
