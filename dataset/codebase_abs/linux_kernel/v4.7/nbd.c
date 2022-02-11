static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static bool F_3 ( struct V_2 * V_3 )
{
return ! ! V_3 -> V_5 ;
}
static const char * F_4 ( int V_6 )
{
switch ( V_6 ) {
case V_7 : return L_1 ;
case V_8 : return L_2 ;
case V_9 : return L_3 ;
case V_10 : return L_4 ;
case V_11 : return L_5 ;
}
return L_6 ;
}
static int F_5 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
V_13 -> V_14 -> V_15 = 0 ;
F_6 ( V_3 -> V_4 , 0 ) ;
F_7 ( & F_1 ( V_3 ) -> V_16 , V_17 ) ;
return 0 ;
}
static void F_8 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
if ( ! F_3 ( V_3 ) )
return;
V_13 -> V_14 -> V_15 = V_3 -> V_18 ;
F_6 ( V_3 -> V_4 , V_3 -> V_18 >> 9 ) ;
F_7 ( & F_1 ( V_3 ) -> V_16 , V_17 ) ;
}
static int F_9 ( struct V_2 * V_3 , struct V_12 * V_13 ,
int V_19 , int V_20 )
{
int V_21 ;
V_21 = F_10 ( V_13 , V_19 ) ;
if ( V_21 )
return V_21 ;
V_3 -> V_22 = V_19 ;
V_3 -> V_18 = ( V_23 ) V_19 * ( V_23 ) V_20 ;
F_8 ( V_3 , V_13 ) ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
int error = V_25 -> V_26 ? - V_27 : 0 ;
struct V_28 * V_29 = V_25 -> V_29 ;
unsigned long V_30 ;
F_12 ( F_1 ( V_3 ) , L_7 , V_25 ,
error ? L_8 : L_9 ) ;
F_13 ( V_29 -> V_31 , V_30 ) ;
F_14 ( V_25 , error ) ;
F_15 ( V_29 -> V_31 , V_30 ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
F_17 ( & V_3 -> V_32 ) ;
if ( ! V_3 -> V_33 ) {
F_18 ( & V_3 -> V_32 ) ;
return;
}
F_19 ( F_2 ( V_3 -> V_4 ) , L_10 ) ;
F_20 ( V_3 -> V_33 , V_34 ) ;
F_21 ( V_3 -> V_33 ) ;
V_3 -> V_33 = NULL ;
F_18 ( & V_3 -> V_32 ) ;
F_22 ( & V_3 -> V_35 ) ;
}
static void F_23 ( unsigned long V_36 )
{
struct V_2 * V_3 = (struct V_2 * ) V_36 ;
unsigned long V_30 ;
if ( F_24 ( & V_3 -> V_37 ) )
return;
F_13 ( & V_3 -> V_32 , V_30 ) ;
V_3 -> V_38 = true ;
if ( V_3 -> V_33 )
F_20 ( V_3 -> V_33 , V_34 ) ;
F_15 ( & V_3 -> V_32 , V_30 ) ;
F_25 ( F_1 ( V_3 ) , L_11 ) ;
}
static int F_26 ( struct V_2 * V_3 , int V_39 , void * V_40 , int V_41 ,
int V_42 )
{
struct V_43 * V_33 = V_3 -> V_33 ;
int V_44 ;
struct V_45 V_46 ;
struct V_47 V_48 ;
unsigned long V_49 = V_50 -> V_30 ;
if ( F_27 ( ! V_33 ) ) {
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_12 ,
( V_39 ? L_13 : L_14 ) ) ;
return - V_51 ;
}
V_50 -> V_30 |= V_52 ;
do {
V_33 -> V_53 -> V_54 = V_55 | V_56 ;
V_48 . V_57 = V_40 ;
V_48 . V_58 = V_41 ;
V_46 . V_59 = NULL ;
V_46 . V_60 = 0 ;
V_46 . V_61 = NULL ;
V_46 . V_62 = 0 ;
V_46 . V_42 = V_42 | V_63 ;
if ( V_39 )
V_44 = F_28 ( V_33 , & V_46 , & V_48 , 1 , V_41 ) ;
else
V_44 = F_29 ( V_33 , & V_46 , & V_48 , 1 , V_41 ,
V_46 . V_42 ) ;
if ( V_44 <= 0 ) {
if ( V_44 == 0 )
V_44 = - V_64 ;
break;
}
V_41 -= V_44 ;
V_40 += V_44 ;
} while ( V_41 > 0 );
F_30 ( V_50 , V_49 , V_52 ) ;
if ( ! V_39 && V_3 -> V_65 )
F_31 ( & V_3 -> V_35 , V_66 + V_3 -> V_65 ) ;
return V_44 ;
}
static inline int F_32 ( struct V_2 * V_3 , struct V_67 * V_68 ,
int V_30 )
{
int V_44 ;
void * V_69 = F_33 ( V_68 -> V_70 ) ;
V_44 = F_26 ( V_3 , 1 , V_69 + V_68 -> V_71 ,
V_68 -> V_72 , V_30 ) ;
F_34 ( V_68 -> V_70 ) ;
return V_44 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
int V_44 , V_30 ;
struct V_73 V_24 ;
unsigned long V_41 = F_36 ( V_25 ) ;
T_1 type ;
if ( V_25 -> V_74 == V_75 )
type = V_9 ;
else if ( V_25 -> V_76 & V_77 )
type = V_11 ;
else if ( V_25 -> V_76 & V_78 )
type = V_10 ;
else if ( F_37 ( V_25 ) == V_79 )
type = V_8 ;
else
type = V_7 ;
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
V_24 . V_80 = F_38 ( V_81 ) ;
V_24 . type = F_38 ( type ) ;
if ( type != V_10 && type != V_9 ) {
V_24 . V_82 = F_39 ( ( V_83 ) F_40 ( V_25 ) << 9 ) ;
V_24 . V_84 = F_38 ( V_41 ) ;
}
memcpy ( V_24 . V_85 , & V_25 , sizeof( V_25 ) ) ;
F_12 ( F_1 ( V_3 ) , L_15 ,
V_25 , F_4 ( type ) ,
( unsigned long long ) F_40 ( V_25 ) << 9 , F_36 ( V_25 ) ) ;
V_44 = F_26 ( V_3 , 1 , & V_24 , sizeof( V_24 ) ,
( type == V_8 ) ? V_86 : 0 ) ;
if ( V_44 <= 0 ) {
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_16 , V_44 ) ;
return - V_27 ;
}
if ( type == V_8 ) {
struct V_87 V_88 ;
struct V_67 V_68 ;
F_41 (bvec, req, iter) {
V_30 = 0 ;
if ( ! F_42 ( V_68 , V_88 ) )
V_30 = V_86 ;
F_12 ( F_1 ( V_3 ) , L_17 ,
V_25 , V_68 . V_72 ) ;
V_44 = F_32 ( V_3 , & V_68 , V_30 ) ;
if ( V_44 <= 0 ) {
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_18 ,
V_44 ) ;
return - V_27 ;
}
}
}
return 0 ;
}
static struct V_24 * F_43 ( struct V_2 * V_3 ,
struct V_24 * V_89 )
{
struct V_24 * V_25 , * V_90 ;
int V_91 ;
V_91 = F_44 ( V_3 -> V_92 , V_3 -> V_93 != V_89 ) ;
if ( F_27 ( V_91 ) )
return F_45 ( V_91 ) ;
F_46 ( & V_3 -> V_31 ) ;
F_47 (req, tmp, &nbd->queue_head, queuelist) {
if ( V_25 != V_89 )
continue;
F_48 ( & V_25 -> V_94 ) ;
F_49 ( & V_3 -> V_31 ) ;
return V_25 ;
}
F_49 ( & V_3 -> V_31 ) ;
return F_45 ( - V_95 ) ;
}
static inline int F_50 ( struct V_2 * V_3 , struct V_67 * V_68 )
{
int V_44 ;
void * V_69 = F_33 ( V_68 -> V_70 ) ;
V_44 = F_26 ( V_3 , 0 , V_69 + V_68 -> V_71 , V_68 -> V_72 ,
V_96 ) ;
F_34 ( V_68 -> V_70 ) ;
return V_44 ;
}
static struct V_24 * F_51 ( struct V_2 * V_3 )
{
int V_44 ;
struct V_97 V_98 ;
struct V_24 * V_25 ;
V_98 . V_80 = 0 ;
V_44 = F_26 ( V_3 , 0 , & V_98 , sizeof( V_98 ) , V_96 ) ;
if ( V_44 <= 0 ) {
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_19 , V_44 ) ;
return F_45 ( V_44 ) ;
}
if ( F_52 ( V_98 . V_80 ) != V_99 ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_20 ,
( unsigned long ) F_52 ( V_98 . V_80 ) ) ;
return F_45 ( - V_100 ) ;
}
V_25 = F_43 ( V_3 , * (struct V_24 * * ) V_98 . V_85 ) ;
if ( F_53 ( V_25 ) ) {
V_44 = F_54 ( V_25 ) ;
if ( V_44 != - V_95 )
return F_45 ( V_44 ) ;
F_25 ( F_2 ( V_3 -> V_4 ) , L_21 ,
V_98 . V_85 ) ;
return F_45 ( - V_101 ) ;
}
if ( F_52 ( V_98 . error ) ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_22 ,
F_52 ( V_98 . error ) ) ;
V_25 -> V_26 ++ ;
return V_25 ;
}
F_12 ( F_1 ( V_3 ) , L_23 , V_25 ) ;
if ( F_37 ( V_25 ) != V_79 ) {
struct V_87 V_88 ;
struct V_67 V_68 ;
F_41 (bvec, req, iter) {
V_44 = F_50 ( V_3 , & V_68 ) ;
if ( V_44 <= 0 ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_24 ,
V_44 ) ;
V_25 -> V_26 ++ ;
return V_25 ;
}
F_12 ( F_1 ( V_3 ) , L_25 ,
V_25 , V_68 . V_72 ) ;
}
}
return V_25 ;
}
static T_2 F_55 ( struct V_1 * V_102 ,
struct V_103 * V_104 , char * V_40 )
{
struct V_105 * V_4 = F_56 ( V_102 ) ;
struct V_2 * V_3 = (struct V_2 * ) V_4 -> V_106 ;
return sprintf ( V_40 , L_26 , F_57 ( V_3 -> V_5 ) ) ;
}
static int F_58 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
struct V_24 * V_25 ;
int V_21 ;
F_59 ( V_3 -> V_80 != V_107 ) ;
F_60 ( V_3 -> V_33 -> V_53 ) ;
V_3 -> V_5 = V_50 ;
V_21 = F_61 ( F_2 ( V_3 -> V_4 ) , & V_108 ) ;
if ( V_21 ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_27 ) ;
V_3 -> V_5 = NULL ;
return V_21 ;
}
F_8 ( V_3 , V_13 ) ;
while ( 1 ) {
V_25 = F_51 ( V_3 ) ;
if ( F_53 ( V_25 ) ) {
V_21 = F_54 ( V_25 ) ;
break;
}
F_11 ( V_3 , V_25 ) ;
}
F_5 ( V_3 , V_13 ) ;
F_62 ( F_2 ( V_3 -> V_4 ) , & V_108 ) ;
V_3 -> V_5 = NULL ;
return V_21 ;
}
static void F_63 ( struct V_2 * V_3 )
{
struct V_24 * V_25 ;
F_59 ( V_3 -> V_80 != V_107 ) ;
F_59 ( V_3 -> V_33 ) ;
F_59 ( V_3 -> V_93 ) ;
while ( ! F_24 ( & V_3 -> V_37 ) ) {
V_25 = F_64 ( V_3 -> V_37 . V_109 , struct V_24 ,
V_94 ) ;
F_48 ( & V_25 -> V_94 ) ;
V_25 -> V_26 ++ ;
F_11 ( V_3 , V_25 ) ;
}
while ( ! F_24 ( & V_3 -> V_110 ) ) {
V_25 = F_64 ( V_3 -> V_110 . V_109 , struct V_24 ,
V_94 ) ;
F_48 ( & V_25 -> V_94 ) ;
V_25 -> V_26 ++ ;
F_11 ( V_3 , V_25 ) ;
}
F_12 ( F_2 ( V_3 -> V_4 ) , L_28 ) ;
}
static void F_65 ( struct V_2 * V_3 , struct V_24 * V_25 )
{
if ( V_25 -> V_74 != V_111 )
goto V_112;
if ( F_37 ( V_25 ) == V_79 &&
( V_3 -> V_30 & V_113 ) ) {
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_29 ) ;
goto V_112;
}
V_25 -> V_26 = 0 ;
F_66 ( & V_3 -> V_114 ) ;
if ( F_27 ( ! V_3 -> V_33 ) ) {
F_67 ( & V_3 -> V_114 ) ;
F_25 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
goto V_112;
}
V_3 -> V_93 = V_25 ;
if ( V_3 -> V_65 && F_68 ( & V_3 -> V_37 ) )
F_31 ( & V_3 -> V_35 , V_66 + V_3 -> V_65 ) ;
if ( F_35 ( V_3 , V_25 ) != 0 ) {
F_25 ( F_2 ( V_3 -> V_4 ) , L_31 ) ;
V_25 -> V_26 ++ ;
F_11 ( V_3 , V_25 ) ;
} else {
F_46 ( & V_3 -> V_31 ) ;
F_69 ( & V_25 -> V_94 , & V_3 -> V_37 ) ;
F_49 ( & V_3 -> V_31 ) ;
}
V_3 -> V_93 = NULL ;
F_67 ( & V_3 -> V_114 ) ;
F_70 ( & V_3 -> V_92 ) ;
return;
V_112:
V_25 -> V_26 ++ ;
F_11 ( V_3 , V_25 ) ;
}
static int F_71 ( void * V_115 )
{
struct V_2 * V_3 = V_115 ;
struct V_24 * V_25 ;
V_3 -> V_116 = V_50 ;
F_72 ( V_50 , V_117 ) ;
while ( ! F_73 () || ! F_24 ( & V_3 -> V_110 ) ) {
F_44 ( V_3 -> V_118 ,
F_73 () ||
! F_24 ( & V_3 -> V_110 ) ) ;
if ( F_24 ( & V_3 -> V_110 ) )
continue;
F_17 ( & V_3 -> V_31 ) ;
V_25 = F_64 ( V_3 -> V_110 . V_109 , struct V_24 ,
V_94 ) ;
F_48 ( & V_25 -> V_94 ) ;
F_18 ( & V_3 -> V_31 ) ;
F_65 ( V_3 , V_25 ) ;
}
V_3 -> V_116 = NULL ;
return 0 ;
}
static void F_74 ( struct V_28 * V_29 )
__releases( V_29 -> V_31 ) __acquires( V_29 -> V_31 )
{
struct V_24 * V_25 ;
while ( ( V_25 = F_75 ( V_29 ) ) != NULL ) {
struct V_2 * V_3 ;
F_18 ( V_29 -> V_31 ) ;
V_3 = V_25 -> V_119 -> V_106 ;
F_59 ( V_3 -> V_80 != V_107 ) ;
F_12 ( F_1 ( V_3 ) , L_32 ,
V_25 , V_25 -> V_74 ) ;
if ( F_27 ( ! V_3 -> V_33 ) ) {
F_76 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
V_25 -> V_26 ++ ;
F_11 ( V_3 , V_25 ) ;
F_17 ( V_29 -> V_31 ) ;
continue;
}
F_17 ( & V_3 -> V_31 ) ;
F_69 ( & V_25 -> V_94 , & V_3 -> V_110 ) ;
F_18 ( & V_3 -> V_31 ) ;
F_77 ( & V_3 -> V_118 ) ;
F_17 ( V_29 -> V_31 ) ;
}
}
static int F_78 ( struct V_2 * V_3 , struct V_43 * V_33 )
{
int V_21 = 0 ;
F_17 ( & V_3 -> V_32 ) ;
if ( V_3 -> V_33 ) {
V_21 = - V_120 ;
goto V_121;
}
V_3 -> V_33 = V_33 ;
V_121:
F_18 ( & V_3 -> V_32 ) ;
return V_21 ;
}
static void F_79 ( struct V_2 * V_3 )
{
V_3 -> V_122 = false ;
V_3 -> V_38 = false ;
V_3 -> V_22 = 1024 ;
V_3 -> V_18 = 0 ;
F_6 ( V_3 -> V_4 , 0 ) ;
V_3 -> V_30 = 0 ;
V_3 -> V_65 = 0 ;
F_80 ( V_123 , V_3 -> V_4 -> V_124 ) ;
F_81 ( & V_3 -> V_35 ) ;
}
static void F_82 ( struct V_12 * V_13 )
{
F_83 ( V_13 , false ) ;
V_13 -> V_14 -> V_15 = 0 ;
if ( V_125 > 0 ) {
F_84 ( V_13 ) ;
V_13 -> V_126 = 1 ;
}
}
static void F_85 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
if ( V_3 -> V_30 & V_113 )
F_83 ( V_13 , true ) ;
if ( V_3 -> V_30 & V_127 )
F_86 ( V_123 , V_3 -> V_4 -> V_124 ) ;
if ( V_3 -> V_30 & V_128 )
F_87 ( V_3 -> V_4 -> V_124 , true , false ) ;
else
F_87 ( V_3 -> V_4 -> V_124 , false , false ) ;
}
static int F_88 ( struct V_12 * V_13 , struct V_2 * V_3 ,
unsigned int V_6 , unsigned long V_36 )
{
switch ( V_6 ) {
case V_129 : {
struct V_24 V_130 ;
F_89 ( F_2 ( V_3 -> V_4 ) , L_33 ) ;
if ( ! V_3 -> V_33 )
return - V_51 ;
F_67 ( & V_3 -> V_114 ) ;
F_90 ( V_13 ) ;
F_66 ( & V_3 -> V_114 ) ;
F_91 ( NULL , & V_130 ) ;
V_130 . V_74 = V_75 ;
if ( ! V_3 -> V_33 )
return - V_51 ;
V_3 -> V_122 = true ;
F_35 ( V_3 , & V_130 ) ;
return 0 ;
}
case V_131 :
F_16 ( V_3 ) ;
F_63 ( V_3 ) ;
F_59 ( ! F_24 ( & V_3 -> V_37 ) ) ;
F_59 ( ! F_24 ( & V_3 -> V_110 ) ) ;
F_92 ( V_13 ) ;
return 0 ;
case V_132 : {
int V_91 ;
struct V_43 * V_33 = F_93 ( V_36 , & V_91 ) ;
if ( ! V_33 )
return V_91 ;
V_91 = F_78 ( V_3 , V_33 ) ;
if ( ! V_91 && V_125 )
V_13 -> V_126 = 1 ;
return V_91 ;
}
case V_133 : {
V_23 V_134 = F_94 ( V_3 -> V_18 , V_36 ) ;
return F_9 ( V_3 , V_13 , V_36 , V_134 ) ;
}
case V_135 :
return F_9 ( V_3 , V_13 , V_3 -> V_22 ,
V_36 / V_3 -> V_22 ) ;
case V_136 :
return F_9 ( V_3 , V_13 , V_3 -> V_22 , V_36 ) ;
case V_137 :
V_3 -> V_65 = V_36 * V_138 ;
if ( V_36 )
F_31 ( & V_3 -> V_35 ,
V_66 + V_3 -> V_65 ) ;
else
F_81 ( & V_3 -> V_35 ) ;
return 0 ;
case V_139 :
V_3 -> V_30 = V_36 ;
return 0 ;
case V_140 : {
struct V_141 * V_142 ;
int error ;
if ( V_3 -> V_5 )
return - V_120 ;
if ( ! V_3 -> V_33 )
return - V_51 ;
F_67 ( & V_3 -> V_114 ) ;
F_85 ( V_3 , V_13 ) ;
V_142 = F_95 ( F_71 , V_3 , L_34 ,
F_96 ( V_3 ) ) ;
if ( F_53 ( V_142 ) ) {
F_66 ( & V_3 -> V_114 ) ;
return F_54 ( V_142 ) ;
}
F_97 ( V_3 ) ;
error = F_58 ( V_3 , V_13 ) ;
F_98 ( V_3 ) ;
F_99 ( V_142 ) ;
F_66 ( & V_3 -> V_114 ) ;
F_16 ( V_3 ) ;
F_63 ( V_3 ) ;
F_92 ( V_13 ) ;
F_82 ( V_13 ) ;
if ( V_3 -> V_122 )
error = 0 ;
if ( V_3 -> V_38 )
error = - V_143 ;
F_79 ( V_3 ) ;
return error ;
}
case V_144 :
return 0 ;
case V_145 :
F_89 ( F_2 ( V_3 -> V_4 ) ,
L_35 ,
V_3 -> V_37 . V_109 , V_3 -> V_37 . V_146 ,
& V_3 -> V_37 ) ;
return 0 ;
}
return - V_147 ;
}
static int F_100 ( struct V_12 * V_13 , T_3 V_148 ,
unsigned int V_6 , unsigned long V_36 )
{
struct V_2 * V_3 = V_13 -> V_149 -> V_106 ;
int error ;
if ( ! F_101 ( V_150 ) )
return - V_151 ;
F_59 ( V_3 -> V_80 != V_107 ) ;
F_66 ( & V_3 -> V_114 ) ;
error = F_88 ( V_13 , V_3 , V_6 , V_36 ) ;
F_67 ( & V_3 -> V_114 ) ;
return error ;
}
static int F_102 ( struct V_152 * V_153 , void * V_154 )
{
struct V_2 * V_3 = V_153 -> V_155 ;
if ( V_3 -> V_5 )
F_103 ( V_153 , L_36 , F_57 ( V_3 -> V_5 ) ) ;
if ( V_3 -> V_116 )
F_103 ( V_153 , L_37 , F_57 ( V_3 -> V_116 ) ) ;
return 0 ;
}
static int F_104 ( struct V_156 * V_156 , struct V_157 * V_157 )
{
return F_105 ( V_157 , F_102 , V_156 -> V_158 ) ;
}
static int F_106 ( struct V_152 * V_153 , void * V_154 )
{
struct V_2 * V_3 = V_153 -> V_155 ;
T_1 V_30 = V_3 -> V_30 ;
F_103 ( V_153 , L_38 , V_30 ) ;
F_107 ( V_153 , L_39 ) ;
if ( V_30 & V_159 )
F_107 ( V_153 , L_40 ) ;
if ( V_30 & V_113 )
F_107 ( V_153 , L_41 ) ;
if ( V_30 & V_128 )
F_107 ( V_153 , L_42 ) ;
if ( V_30 & V_127 )
F_107 ( V_153 , L_43 ) ;
return 0 ;
}
static int F_108 ( struct V_156 * V_156 , struct V_157 * V_157 )
{
return F_105 ( V_157 , F_106 , V_156 -> V_158 ) ;
}
static int F_97 ( struct V_2 * V_3 )
{
struct V_160 * V_161 ;
if ( ! V_162 )
return - V_27 ;
V_161 = F_109 ( F_96 ( V_3 ) , V_162 ) ;
if ( ! V_161 ) {
F_25 ( F_1 ( V_3 ) , L_44 ,
F_96 ( V_3 ) ) ;
return - V_27 ;
}
V_3 -> V_163 = V_161 ;
F_110 ( L_45 , 0444 , V_161 , V_3 , & V_164 ) ;
F_111 ( L_46 , 0444 , V_161 , & V_3 -> V_18 ) ;
F_112 ( L_47 , 0444 , V_161 , & V_3 -> V_65 ) ;
F_112 ( L_48 , 0444 , V_161 , & V_3 -> V_22 ) ;
F_110 ( L_49 , 0444 , V_161 , V_3 , & V_165 ) ;
return 0 ;
}
static void F_98 ( struct V_2 * V_3 )
{
F_113 ( V_3 -> V_163 ) ;
}
static int F_114 ( void )
{
struct V_160 * V_163 ;
V_163 = F_109 ( L_50 , NULL ) ;
if ( ! V_163 )
return - V_27 ;
V_162 = V_163 ;
return 0 ;
}
static void F_115 ( void )
{
F_113 ( V_162 ) ;
}
static int F_97 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_98 ( struct V_2 * V_3 )
{
}
static int F_114 ( void )
{
return 0 ;
}
static void F_115 ( void )
{
}
static int T_4 F_116 ( void )
{
int V_91 = - V_166 ;
int V_167 ;
int V_168 ;
F_117 ( sizeof( struct V_73 ) != 28 ) ;
if ( V_125 < 0 ) {
F_118 ( V_169 L_51 ) ;
return - V_51 ;
}
V_168 = 0 ;
if ( V_125 > 0 ) {
V_168 = F_119 ( V_125 ) ;
V_125 = ( 1UL << V_168 ) - 1 ;
}
if ( ( 1UL << V_168 ) > V_170 )
return - V_51 ;
if ( V_171 > 1UL << ( V_172 - V_168 ) )
return - V_51 ;
V_173 = F_120 ( V_171 , sizeof( * V_173 ) , V_174 ) ;
if ( ! V_173 )
return - V_166 ;
for ( V_167 = 0 ; V_167 < V_171 ; V_167 ++ ) {
struct V_105 * V_4 = F_121 ( 1 << V_168 ) ;
if ( ! V_4 )
goto V_121;
V_173 [ V_167 ] . V_4 = V_4 ;
V_4 -> V_124 = F_122 ( F_74 , & V_175 ) ;
if ( ! V_4 -> V_124 ) {
F_123 ( V_4 ) ;
goto V_121;
}
F_86 ( V_176 , V_4 -> V_124 ) ;
F_80 ( V_177 , V_4 -> V_124 ) ;
V_4 -> V_124 -> V_178 . V_179 = 512 ;
F_124 ( V_4 -> V_124 , V_180 ) ;
V_4 -> V_124 -> V_178 . V_181 = 0 ;
F_125 ( V_4 -> V_124 , 65536 ) ;
V_4 -> V_124 -> V_178 . V_182 = 256 ;
}
if ( F_126 ( V_183 , L_50 ) ) {
V_91 = - V_27 ;
goto V_121;
}
F_118 ( V_184 L_52 , V_183 ) ;
F_114 () ;
for ( V_167 = 0 ; V_167 < V_171 ; V_167 ++ ) {
struct V_105 * V_4 = V_173 [ V_167 ] . V_4 ;
V_173 [ V_167 ] . V_80 = V_107 ;
F_127 ( & V_173 [ V_167 ] . V_110 ) ;
F_128 ( & V_173 [ V_167 ] . V_31 ) ;
F_128 ( & V_173 [ V_167 ] . V_32 ) ;
F_127 ( & V_173 [ V_167 ] . V_37 ) ;
F_129 ( & V_173 [ V_167 ] . V_114 ) ;
F_130 ( & V_173 [ V_167 ] . V_35 ) ;
V_173 [ V_167 ] . V_35 . V_185 = F_23 ;
V_173 [ V_167 ] . V_35 . V_115 = ( unsigned long ) & V_173 [ V_167 ] ;
F_131 ( & V_173 [ V_167 ] . V_92 ) ;
F_131 ( & V_173 [ V_167 ] . V_118 ) ;
V_4 -> V_186 = V_183 ;
V_4 -> V_187 = V_167 << V_168 ;
V_4 -> V_188 = & V_189 ;
V_4 -> V_106 = & V_173 [ V_167 ] ;
sprintf ( V_4 -> V_190 , L_53 , V_167 ) ;
F_79 ( & V_173 [ V_167 ] ) ;
F_132 ( V_4 ) ;
}
return 0 ;
V_121:
while ( V_167 -- ) {
F_133 ( V_173 [ V_167 ] . V_4 -> V_124 ) ;
F_123 ( V_173 [ V_167 ] . V_4 ) ;
}
F_134 ( V_173 ) ;
return V_91 ;
}
static void T_5 F_135 ( void )
{
int V_167 ;
F_115 () ;
for ( V_167 = 0 ; V_167 < V_171 ; V_167 ++ ) {
struct V_105 * V_4 = V_173 [ V_167 ] . V_4 ;
V_173 [ V_167 ] . V_80 = 0 ;
if ( V_4 ) {
F_136 ( V_4 ) ;
F_133 ( V_4 -> V_124 ) ;
F_123 ( V_4 ) ;
}
}
F_137 ( V_183 , L_50 ) ;
F_134 ( V_173 ) ;
F_118 ( V_184 L_54 , V_183 ) ;
}
