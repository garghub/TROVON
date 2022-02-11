static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static const char * F_3 ( int V_5 )
{
switch ( V_5 ) {
case V_6 : return L_1 ;
case V_7 : return L_2 ;
case V_8 : return L_3 ;
case V_9 : return L_4 ;
case V_10 : return L_5 ;
}
return L_6 ;
}
static void F_4 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
int error = V_12 -> V_13 ? - V_14 : 0 ;
struct V_15 * V_16 = V_12 -> V_16 ;
unsigned long V_17 ;
F_5 ( F_1 ( V_3 ) , L_7 , V_12 ,
error ? L_8 : L_9 ) ;
F_6 ( V_16 -> V_18 , V_17 ) ;
F_7 ( V_12 , error ) ;
F_8 ( V_16 -> V_18 , V_17 ) ;
}
static void F_9 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_19 )
return;
F_10 ( F_2 ( V_3 -> V_4 ) , L_10 ) ;
F_11 ( V_3 -> V_19 , V_20 ) ;
V_3 -> V_19 = NULL ;
F_12 ( & V_3 -> V_21 ) ;
}
static void F_13 ( unsigned long V_22 )
{
struct V_2 * V_3 = (struct V_2 * ) V_22 ;
unsigned long V_17 ;
if ( F_14 ( & V_3 -> V_23 ) )
return;
V_3 -> V_24 = true ;
F_6 ( & V_3 -> V_25 , V_17 ) ;
if ( V_3 -> V_26 )
F_15 ( V_27 , V_3 -> V_26 ) ;
if ( V_3 -> V_28 )
F_15 ( V_27 , V_3 -> V_28 ) ;
F_8 ( & V_3 -> V_25 , V_17 ) ;
F_16 ( F_1 ( V_3 ) , L_11 ) ;
}
static int F_17 ( struct V_2 * V_3 , int V_29 , void * V_30 , int V_31 ,
int V_32 )
{
struct V_33 * V_19 = V_3 -> V_19 ;
int V_34 ;
struct V_35 V_36 ;
struct V_37 V_38 ;
T_1 V_39 , V_40 ;
unsigned long V_41 = V_42 -> V_17 ;
if ( F_18 ( ! V_19 ) ) {
F_16 ( F_2 ( V_3 -> V_4 ) ,
L_12 ,
( V_29 ? L_13 : L_14 ) ) ;
return - V_43 ;
}
F_19 ( & V_39 , F_20 ( V_27 ) ) ;
F_21 ( V_44 , & V_39 , & V_40 ) ;
V_42 -> V_17 |= V_45 ;
do {
V_19 -> V_46 -> V_47 = V_48 | V_49 ;
V_38 . V_50 = V_30 ;
V_38 . V_51 = V_31 ;
V_36 . V_52 = NULL ;
V_36 . V_53 = 0 ;
V_36 . V_54 = NULL ;
V_36 . V_55 = 0 ;
V_36 . V_32 = V_32 | V_56 ;
if ( V_29 )
V_34 = F_22 ( V_19 , & V_36 , & V_38 , 1 , V_31 ) ;
else
V_34 = F_23 ( V_19 , & V_36 , & V_38 , 1 , V_31 ,
V_36 . V_32 ) ;
if ( V_34 <= 0 ) {
if ( V_34 == 0 )
V_34 = - V_57 ;
break;
}
V_31 -= V_34 ;
V_30 += V_34 ;
} while ( V_31 > 0 );
F_21 ( V_44 , & V_40 , NULL ) ;
F_24 ( V_42 , V_41 , V_45 ) ;
if ( ! V_29 && V_3 -> V_58 )
F_25 ( & V_3 -> V_21 , V_59 + V_3 -> V_58 ) ;
return V_34 ;
}
static inline int F_26 ( struct V_2 * V_3 , struct V_60 * V_61 ,
int V_17 )
{
int V_34 ;
void * V_62 = F_27 ( V_61 -> V_63 ) ;
V_34 = F_17 ( V_3 , 1 , V_62 + V_61 -> V_64 ,
V_61 -> V_65 , V_17 ) ;
F_28 ( V_61 -> V_63 ) ;
return V_34 ;
}
static int F_29 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
int V_34 , V_17 ;
struct V_66 V_11 ;
unsigned long V_31 = F_30 ( V_12 ) ;
T_2 type ;
if ( V_12 -> V_67 == V_68 )
type = V_8 ;
else if ( V_12 -> V_69 & V_70 )
type = V_10 ;
else if ( V_12 -> V_69 & V_71 )
type = V_9 ;
else if ( F_31 ( V_12 ) == V_72 )
type = V_7 ;
else
type = V_6 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_73 = F_32 ( V_74 ) ;
V_11 . type = F_32 ( type ) ;
if ( type != V_9 && type != V_8 ) {
V_11 . V_75 = F_33 ( ( V_76 ) F_34 ( V_12 ) << 9 ) ;
V_11 . V_77 = F_32 ( V_31 ) ;
}
memcpy ( V_11 . V_78 , & V_12 , sizeof( V_12 ) ) ;
F_5 ( F_1 ( V_3 ) , L_15 ,
V_12 , F_3 ( type ) ,
( unsigned long long ) F_34 ( V_12 ) << 9 , F_30 ( V_12 ) ) ;
V_34 = F_17 ( V_3 , 1 , & V_11 , sizeof( V_11 ) ,
( type == V_7 ) ? V_79 : 0 ) ;
if ( V_34 <= 0 ) {
F_16 ( F_2 ( V_3 -> V_4 ) ,
L_16 , V_34 ) ;
return - V_14 ;
}
if ( type == V_7 ) {
struct V_80 V_81 ;
struct V_60 V_61 ;
F_35 (bvec, req, iter) {
V_17 = 0 ;
if ( ! F_36 ( V_61 , V_81 ) )
V_17 = V_79 ;
F_5 ( F_1 ( V_3 ) , L_17 ,
V_12 , V_61 . V_65 ) ;
V_34 = F_26 ( V_3 , & V_61 , V_17 ) ;
if ( V_34 <= 0 ) {
F_16 ( F_2 ( V_3 -> V_4 ) ,
L_18 ,
V_34 ) ;
return - V_14 ;
}
}
}
return 0 ;
}
static struct V_11 * F_37 ( struct V_2 * V_3 ,
struct V_11 * V_82 )
{
struct V_11 * V_12 , * V_83 ;
int V_84 ;
V_84 = F_38 ( V_3 -> V_85 , V_3 -> V_86 != V_82 ) ;
if ( F_18 ( V_84 ) )
return F_39 ( V_84 ) ;
F_40 ( & V_3 -> V_18 ) ;
F_41 (req, tmp, &nbd->queue_head, queuelist) {
if ( V_12 != V_82 )
continue;
F_42 ( & V_12 -> V_87 ) ;
F_43 ( & V_3 -> V_18 ) ;
return V_12 ;
}
F_43 ( & V_3 -> V_18 ) ;
return F_39 ( - V_88 ) ;
}
static inline int F_44 ( struct V_2 * V_3 , struct V_60 * V_61 )
{
int V_34 ;
void * V_62 = F_27 ( V_61 -> V_63 ) ;
V_34 = F_17 ( V_3 , 0 , V_62 + V_61 -> V_64 , V_61 -> V_65 ,
V_89 ) ;
F_28 ( V_61 -> V_63 ) ;
return V_34 ;
}
static struct V_11 * F_45 ( struct V_2 * V_3 )
{
int V_34 ;
struct V_90 V_91 ;
struct V_11 * V_12 ;
V_91 . V_73 = 0 ;
V_34 = F_17 ( V_3 , 0 , & V_91 , sizeof( V_91 ) , V_89 ) ;
if ( V_34 <= 0 ) {
F_16 ( F_2 ( V_3 -> V_4 ) ,
L_19 , V_34 ) ;
return F_39 ( V_34 ) ;
}
if ( F_46 ( V_91 . V_73 ) != V_92 ) {
F_16 ( F_2 ( V_3 -> V_4 ) , L_20 ,
( unsigned long ) F_46 ( V_91 . V_73 ) ) ;
return F_39 ( - V_93 ) ;
}
V_12 = F_37 ( V_3 , * (struct V_11 * * ) V_91 . V_78 ) ;
if ( F_47 ( V_12 ) ) {
V_34 = F_48 ( V_12 ) ;
if ( V_34 != - V_88 )
return F_39 ( V_34 ) ;
F_16 ( F_2 ( V_3 -> V_4 ) , L_21 ,
V_91 . V_78 ) ;
return F_39 ( - V_94 ) ;
}
if ( F_46 ( V_91 . error ) ) {
F_16 ( F_2 ( V_3 -> V_4 ) , L_22 ,
F_46 ( V_91 . error ) ) ;
V_12 -> V_13 ++ ;
return V_12 ;
}
F_5 ( F_1 ( V_3 ) , L_23 , V_12 ) ;
if ( F_31 ( V_12 ) != V_72 ) {
struct V_80 V_81 ;
struct V_60 V_61 ;
F_35 (bvec, req, iter) {
V_34 = F_44 ( V_3 , & V_61 ) ;
if ( V_34 <= 0 ) {
F_16 ( F_2 ( V_3 -> V_4 ) , L_24 ,
V_34 ) ;
V_12 -> V_13 ++ ;
return V_12 ;
}
F_5 ( F_1 ( V_3 ) , L_25 ,
V_12 , V_61 . V_65 ) ;
}
}
return V_12 ;
}
static T_3 F_49 ( struct V_1 * V_95 ,
struct V_96 * V_97 , char * V_30 )
{
struct V_98 * V_4 = F_50 ( V_95 ) ;
struct V_2 * V_3 = (struct V_2 * ) V_4 -> V_99 ;
return sprintf ( V_30 , L_26 , F_51 ( V_3 -> V_26 ) ) ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_11 * V_12 ;
int V_100 ;
unsigned long V_17 ;
F_53 ( V_3 -> V_73 != V_101 ) ;
F_54 ( V_3 -> V_19 -> V_46 ) ;
F_6 ( & V_3 -> V_25 , V_17 ) ;
V_3 -> V_26 = V_42 ;
F_8 ( & V_3 -> V_25 , V_17 ) ;
V_100 = F_55 ( F_2 ( V_3 -> V_4 ) , & V_102 ) ;
if ( V_100 ) {
F_16 ( F_2 ( V_3 -> V_4 ) , L_27 ) ;
F_6 ( & V_3 -> V_25 , V_17 ) ;
V_3 -> V_26 = NULL ;
F_8 ( & V_3 -> V_25 , V_17 ) ;
return V_100 ;
}
while ( 1 ) {
V_12 = F_45 ( V_3 ) ;
if ( F_47 ( V_12 ) ) {
V_100 = F_48 ( V_12 ) ;
break;
}
F_4 ( V_3 , V_12 ) ;
}
F_56 ( F_2 ( V_3 -> V_4 ) , & V_102 ) ;
F_6 ( & V_3 -> V_25 , V_17 ) ;
V_3 -> V_26 = NULL ;
F_8 ( & V_3 -> V_25 , V_17 ) ;
if ( F_57 ( V_42 ) ) {
V_100 = F_58 ( NULL ) ;
F_10 ( F_1 ( V_3 ) , L_28 ,
F_51 ( V_42 ) , V_42 -> V_103 , V_100 ) ;
F_59 ( & V_3 -> V_104 ) ;
F_9 ( V_3 ) ;
F_60 ( & V_3 -> V_104 ) ;
V_100 = - V_105 ;
}
return V_100 ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_11 * V_12 ;
F_53 ( V_3 -> V_73 != V_101 ) ;
F_53 ( V_3 -> V_19 ) ;
F_53 ( V_3 -> V_86 ) ;
while ( ! F_14 ( & V_3 -> V_23 ) ) {
V_12 = F_62 ( V_3 -> V_23 . V_106 , struct V_11 ,
V_87 ) ;
F_42 ( & V_12 -> V_87 ) ;
V_12 -> V_13 ++ ;
F_4 ( V_3 , V_12 ) ;
}
while ( ! F_14 ( & V_3 -> V_107 ) ) {
V_12 = F_62 ( V_3 -> V_107 . V_106 , struct V_11 ,
V_87 ) ;
F_42 ( & V_12 -> V_87 ) ;
V_12 -> V_13 ++ ;
F_4 ( V_3 , V_12 ) ;
}
F_5 ( F_2 ( V_3 -> V_4 ) , L_29 ) ;
}
static void F_63 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
if ( V_12 -> V_67 != V_108 )
goto V_109;
if ( F_31 ( V_12 ) == V_72 &&
( V_3 -> V_17 & V_110 ) ) {
F_16 ( F_2 ( V_3 -> V_4 ) ,
L_30 ) ;
goto V_109;
}
V_12 -> V_13 = 0 ;
F_59 ( & V_3 -> V_104 ) ;
if ( F_18 ( ! V_3 -> V_19 ) ) {
F_60 ( & V_3 -> V_104 ) ;
F_16 ( F_2 ( V_3 -> V_4 ) ,
L_31 ) ;
goto V_109;
}
V_3 -> V_86 = V_12 ;
if ( V_3 -> V_58 && F_64 ( & V_3 -> V_23 ) )
F_25 ( & V_3 -> V_21 , V_59 + V_3 -> V_58 ) ;
if ( F_29 ( V_3 , V_12 ) != 0 ) {
F_16 ( F_2 ( V_3 -> V_4 ) , L_32 ) ;
V_12 -> V_13 ++ ;
F_4 ( V_3 , V_12 ) ;
} else {
F_40 ( & V_3 -> V_18 ) ;
F_65 ( & V_12 -> V_87 , & V_3 -> V_23 ) ;
F_43 ( & V_3 -> V_18 ) ;
}
V_3 -> V_86 = NULL ;
F_60 ( & V_3 -> V_104 ) ;
F_66 ( & V_3 -> V_85 ) ;
return;
V_109:
V_12 -> V_13 ++ ;
F_4 ( V_3 , V_12 ) ;
}
static int F_67 ( void * V_111 )
{
struct V_2 * V_3 = V_111 ;
struct V_11 * V_12 ;
unsigned long V_17 ;
F_6 ( & V_3 -> V_25 , V_17 ) ;
V_3 -> V_28 = V_42 ;
F_8 ( & V_3 -> V_25 , V_17 ) ;
F_68 ( V_42 , V_112 ) ;
while ( ! F_69 () || ! F_14 ( & V_3 -> V_107 ) ) {
F_38 ( V_3 -> V_113 ,
F_69 () ||
! F_14 ( & V_3 -> V_107 ) ) ;
if ( F_57 ( V_42 ) ) {
int V_100 = F_58 ( NULL ) ;
F_10 ( F_1 ( V_3 ) , L_28 ,
F_51 ( V_42 ) , V_42 -> V_103 , V_100 ) ;
F_59 ( & V_3 -> V_104 ) ;
F_9 ( V_3 ) ;
F_60 ( & V_3 -> V_104 ) ;
break;
}
if ( F_14 ( & V_3 -> V_107 ) )
continue;
F_70 ( & V_3 -> V_18 ) ;
V_12 = F_62 ( V_3 -> V_107 . V_106 , struct V_11 ,
V_87 ) ;
F_42 ( & V_12 -> V_87 ) ;
F_71 ( & V_3 -> V_18 ) ;
F_63 ( V_3 , V_12 ) ;
}
F_6 ( & V_3 -> V_25 , V_17 ) ;
V_3 -> V_28 = NULL ;
F_8 ( & V_3 -> V_25 , V_17 ) ;
if ( F_57 ( V_42 ) )
F_58 ( NULL ) ;
return 0 ;
}
static void F_72 ( struct V_15 * V_16 )
__releases( V_16 -> V_18 ) __acquires( V_16 -> V_18 )
{
struct V_11 * V_12 ;
while ( ( V_12 = F_73 ( V_16 ) ) != NULL ) {
struct V_2 * V_3 ;
F_71 ( V_16 -> V_18 ) ;
V_3 = V_12 -> V_114 -> V_99 ;
F_53 ( V_3 -> V_73 != V_101 ) ;
F_5 ( F_1 ( V_3 ) , L_33 ,
V_12 , V_12 -> V_67 ) ;
if ( F_18 ( ! V_3 -> V_19 ) ) {
F_16 ( F_2 ( V_3 -> V_4 ) ,
L_31 ) ;
V_12 -> V_13 ++ ;
F_4 ( V_3 , V_12 ) ;
F_70 ( V_16 -> V_18 ) ;
continue;
}
F_70 ( & V_3 -> V_18 ) ;
F_65 ( & V_12 -> V_87 , & V_3 -> V_107 ) ;
F_71 ( & V_3 -> V_18 ) ;
F_74 ( & V_3 -> V_113 ) ;
F_70 ( V_16 -> V_18 ) ;
}
}
static int F_75 ( struct V_115 * V_116 , struct V_2 * V_3 ,
unsigned int V_5 , unsigned long V_22 )
{
switch ( V_5 ) {
case V_117 : {
struct V_11 V_118 ;
F_76 ( F_2 ( V_3 -> V_4 ) , L_34 ) ;
if ( ! V_3 -> V_19 )
return - V_43 ;
F_60 ( & V_3 -> V_104 ) ;
F_77 ( V_116 ) ;
F_59 ( & V_3 -> V_104 ) ;
F_78 ( NULL , & V_118 ) ;
V_118 . V_67 = V_68 ;
if ( ! V_3 -> V_19 )
return - V_43 ;
V_3 -> V_24 = true ;
F_29 ( V_3 , & V_118 ) ;
return 0 ;
}
case V_119 : {
struct V_33 * V_19 = V_3 -> V_19 ;
V_3 -> V_19 = NULL ;
F_61 ( V_3 ) ;
F_53 ( ! F_14 ( & V_3 -> V_23 ) ) ;
F_53 ( ! F_14 ( & V_3 -> V_107 ) ) ;
F_79 ( V_116 ) ;
if ( V_19 )
F_80 ( V_19 ) ;
return 0 ;
}
case V_120 : {
struct V_33 * V_19 ;
int V_84 ;
if ( V_3 -> V_19 )
return - V_121 ;
V_19 = F_81 ( V_22 , & V_84 ) ;
if ( V_19 ) {
V_3 -> V_19 = V_19 ;
if ( V_122 > 0 )
V_116 -> V_123 = 1 ;
V_3 -> V_24 = false ;
return 0 ;
}
return - V_43 ;
}
case V_124 :
V_3 -> V_125 = V_22 ;
V_3 -> V_126 &= ~ ( V_3 -> V_125 - 1 ) ;
V_116 -> V_127 -> V_128 = V_3 -> V_126 ;
F_82 ( V_116 , V_3 -> V_125 ) ;
F_83 ( V_3 -> V_4 , V_3 -> V_126 >> 9 ) ;
return 0 ;
case V_129 :
V_3 -> V_126 = V_22 & ~ ( V_3 -> V_125 - 1 ) ;
V_116 -> V_127 -> V_128 = V_3 -> V_126 ;
F_82 ( V_116 , V_3 -> V_125 ) ;
F_83 ( V_3 -> V_4 , V_3 -> V_126 >> 9 ) ;
return 0 ;
case V_130 :
V_3 -> V_58 = V_22 * V_131 ;
if ( V_22 )
F_25 ( & V_3 -> V_21 ,
V_59 + V_3 -> V_58 ) ;
else
F_12 ( & V_3 -> V_21 ) ;
return 0 ;
case V_132 :
V_3 -> V_17 = V_22 ;
return 0 ;
case V_133 :
V_3 -> V_126 = ( ( V_76 ) V_22 ) * V_3 -> V_125 ;
V_116 -> V_127 -> V_128 = V_3 -> V_126 ;
F_82 ( V_116 , V_3 -> V_125 ) ;
F_83 ( V_3 -> V_4 , V_3 -> V_126 >> 9 ) ;
return 0 ;
case V_134 : {
struct V_135 * V_136 ;
struct V_33 * V_19 ;
int error ;
if ( V_3 -> V_26 )
return - V_121 ;
if ( ! V_3 -> V_19 )
return - V_43 ;
F_60 ( & V_3 -> V_104 ) ;
if ( V_3 -> V_17 & V_110 )
F_84 ( V_116 , true ) ;
if ( V_3 -> V_17 & V_137 )
F_85 ( V_138 ,
V_3 -> V_4 -> V_139 ) ;
if ( V_3 -> V_17 & V_140 )
F_86 ( V_3 -> V_4 -> V_139 , V_71 ) ;
else
F_86 ( V_3 -> V_4 -> V_139 , 0 ) ;
V_136 = F_87 ( F_67 , V_3 , L_35 ,
F_88 ( V_3 ) ) ;
if ( F_47 ( V_136 ) ) {
F_59 ( & V_3 -> V_104 ) ;
return F_48 ( V_136 ) ;
}
F_89 ( V_3 ) ;
error = F_52 ( V_3 ) ;
F_90 ( V_3 ) ;
F_91 ( V_136 ) ;
F_59 ( & V_3 -> V_104 ) ;
F_9 ( V_3 ) ;
V_19 = V_3 -> V_19 ;
V_3 -> V_19 = NULL ;
F_61 ( V_3 ) ;
F_79 ( V_116 ) ;
F_92 ( V_138 , V_3 -> V_4 -> V_139 ) ;
F_84 ( V_116 , false ) ;
if ( V_19 )
F_80 ( V_19 ) ;
V_3 -> V_17 = 0 ;
V_3 -> V_126 = 0 ;
V_116 -> V_127 -> V_128 = 0 ;
F_83 ( V_3 -> V_4 , 0 ) ;
if ( V_122 > 0 )
F_93 ( V_116 ) ;
if ( V_3 -> V_24 )
return 0 ;
return error ;
}
case V_141 :
return 0 ;
case V_142 :
F_76 ( F_2 ( V_3 -> V_4 ) ,
L_36 ,
V_3 -> V_23 . V_106 , V_3 -> V_23 . V_143 ,
& V_3 -> V_23 ) ;
return 0 ;
}
return - V_144 ;
}
static int F_94 ( struct V_115 * V_116 , T_4 V_145 ,
unsigned int V_5 , unsigned long V_22 )
{
struct V_2 * V_3 = V_116 -> V_146 -> V_99 ;
int error ;
if ( ! F_95 ( V_147 ) )
return - V_148 ;
F_53 ( V_3 -> V_73 != V_101 ) ;
F_59 ( & V_3 -> V_104 ) ;
error = F_75 ( V_116 , V_3 , V_5 , V_22 ) ;
F_60 ( & V_3 -> V_104 ) ;
return error ;
}
static int F_96 ( struct V_149 * V_150 , void * V_151 )
{
struct V_2 * V_3 = V_150 -> V_152 ;
if ( V_3 -> V_26 )
F_97 ( V_150 , L_37 , F_51 ( V_3 -> V_26 ) ) ;
if ( V_3 -> V_28 )
F_97 ( V_150 , L_38 , F_51 ( V_3 -> V_28 ) ) ;
return 0 ;
}
static int F_98 ( struct V_153 * V_153 , struct V_154 * V_154 )
{
return F_99 ( V_154 , F_96 , V_153 -> V_155 ) ;
}
static int F_100 ( struct V_149 * V_150 , void * V_151 )
{
struct V_2 * V_3 = V_150 -> V_152 ;
T_2 V_17 = V_3 -> V_17 ;
F_97 ( V_150 , L_39 , V_17 ) ;
F_101 ( V_150 , L_40 ) ;
if ( V_17 & V_156 )
F_101 ( V_150 , L_41 ) ;
if ( V_17 & V_110 )
F_101 ( V_150 , L_42 ) ;
if ( V_17 & V_140 )
F_101 ( V_150 , L_43 ) ;
if ( V_17 & V_137 )
F_101 ( V_150 , L_44 ) ;
return 0 ;
}
static int F_102 ( struct V_153 * V_153 , struct V_154 * V_154 )
{
return F_99 ( V_154 , F_100 , V_153 -> V_155 ) ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_157 * V_158 ;
struct V_157 * V_159 ;
V_158 = F_103 ( F_88 ( V_3 ) , V_160 ) ;
if ( F_104 ( V_158 ) ) {
F_16 ( F_1 ( V_3 ) , L_45 ,
F_88 ( V_3 ) , F_48 ( V_158 ) ) ;
return F_48 ( V_158 ) ;
}
V_3 -> V_161 = V_158 ;
V_159 = F_105 ( L_46 , 0444 , V_158 , V_3 , & V_162 ) ;
if ( F_104 ( V_159 ) ) {
F_16 ( F_1 ( V_3 ) , L_47 ,
F_48 ( V_159 ) ) ;
return F_48 ( V_159 ) ;
}
V_159 = F_106 ( L_48 , 0444 , V_158 , & V_3 -> V_126 ) ;
if ( F_104 ( V_159 ) ) {
F_16 ( F_1 ( V_3 ) , L_49 ,
F_48 ( V_159 ) ) ;
return F_48 ( V_159 ) ;
}
V_159 = F_107 ( L_50 , 0444 , V_158 , & V_3 -> V_58 ) ;
if ( F_104 ( V_159 ) ) {
F_16 ( F_1 ( V_3 ) , L_51 ,
F_48 ( V_159 ) ) ;
return F_48 ( V_159 ) ;
}
V_159 = F_107 ( L_52 , 0444 , V_158 , & V_3 -> V_125 ) ;
if ( F_104 ( V_159 ) ) {
F_16 ( F_1 ( V_3 ) , L_53 ,
F_48 ( V_159 ) ) ;
return F_48 ( V_159 ) ;
}
V_159 = F_105 ( L_54 , 0444 , V_158 , & V_3 , & V_163 ) ;
if ( F_104 ( V_159 ) ) {
F_16 ( F_1 ( V_3 ) , L_55 ,
F_48 ( V_159 ) ) ;
return F_48 ( V_159 ) ;
}
return 0 ;
}
static void F_90 ( struct V_2 * V_3 )
{
F_108 ( V_3 -> V_161 ) ;
}
static int F_109 ( void )
{
struct V_157 * V_161 ;
V_161 = F_103 ( L_56 , NULL ) ;
if ( F_47 ( V_161 ) )
return F_48 ( V_161 ) ;
V_160 = V_161 ;
return 0 ;
}
static void F_110 ( void )
{
F_108 ( V_160 ) ;
}
static int F_89 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_90 ( struct V_2 * V_3 )
{
}
static int F_109 ( void )
{
return 0 ;
}
static void F_110 ( void )
{
}
static int T_5 F_111 ( void )
{
int V_84 = - V_164 ;
int V_165 ;
int V_166 ;
F_112 ( sizeof( struct V_66 ) != 28 ) ;
if ( V_122 < 0 ) {
F_113 ( V_167 L_57 ) ;
return - V_43 ;
}
V_166 = 0 ;
if ( V_122 > 0 ) {
V_166 = F_114 ( V_122 ) ;
V_122 = ( 1UL << V_166 ) - 1 ;
}
if ( ( 1UL << V_166 ) > V_168 )
return - V_43 ;
if ( V_169 > 1UL << ( V_170 - V_166 ) )
return - V_43 ;
V_171 = F_115 ( V_169 , sizeof( * V_171 ) , V_172 ) ;
if ( ! V_171 )
return - V_164 ;
for ( V_165 = 0 ; V_165 < V_169 ; V_165 ++ ) {
struct V_98 * V_4 = F_116 ( 1 << V_166 ) ;
if ( ! V_4 )
goto V_173;
V_171 [ V_165 ] . V_4 = V_4 ;
V_4 -> V_139 = F_117 ( F_72 , & V_174 ) ;
if ( ! V_4 -> V_139 ) {
F_118 ( V_4 ) ;
goto V_173;
}
F_85 ( V_175 , V_4 -> V_139 ) ;
F_92 ( V_176 , V_4 -> V_139 ) ;
V_4 -> V_139 -> V_177 . V_178 = 512 ;
F_119 ( V_4 -> V_139 , V_179 ) ;
V_4 -> V_139 -> V_177 . V_180 = 0 ;
F_120 ( V_4 -> V_139 , 65536 ) ;
V_4 -> V_139 -> V_177 . V_181 = 256 ;
}
if ( F_121 ( V_182 , L_56 ) ) {
V_84 = - V_14 ;
goto V_173;
}
F_113 ( V_183 L_58 , V_182 ) ;
F_109 () ;
for ( V_165 = 0 ; V_165 < V_169 ; V_165 ++ ) {
struct V_98 * V_4 = V_171 [ V_165 ] . V_4 ;
V_171 [ V_165 ] . V_73 = V_101 ;
F_122 ( & V_171 [ V_165 ] . V_107 ) ;
F_123 ( & V_171 [ V_165 ] . V_18 ) ;
F_123 ( & V_171 [ V_165 ] . V_25 ) ;
F_122 ( & V_171 [ V_165 ] . V_23 ) ;
F_124 ( & V_171 [ V_165 ] . V_104 ) ;
F_125 ( & V_171 [ V_165 ] . V_21 ) ;
V_171 [ V_165 ] . V_21 . V_184 = F_13 ;
V_171 [ V_165 ] . V_21 . V_111 = ( unsigned long ) & V_171 [ V_165 ] ;
F_126 ( & V_171 [ V_165 ] . V_85 ) ;
F_126 ( & V_171 [ V_165 ] . V_113 ) ;
V_171 [ V_165 ] . V_125 = 1024 ;
V_171 [ V_165 ] . V_126 = 0 ;
V_4 -> V_185 = V_182 ;
V_4 -> V_186 = V_165 << V_166 ;
V_4 -> V_187 = & V_188 ;
V_4 -> V_99 = & V_171 [ V_165 ] ;
sprintf ( V_4 -> V_189 , L_59 , V_165 ) ;
F_83 ( V_4 , 0 ) ;
F_127 ( V_4 ) ;
}
return 0 ;
V_173:
while ( V_165 -- ) {
F_128 ( V_171 [ V_165 ] . V_4 -> V_139 ) ;
F_118 ( V_171 [ V_165 ] . V_4 ) ;
}
F_129 ( V_171 ) ;
return V_84 ;
}
static void T_6 F_130 ( void )
{
int V_165 ;
F_110 () ;
for ( V_165 = 0 ; V_165 < V_169 ; V_165 ++ ) {
struct V_98 * V_4 = V_171 [ V_165 ] . V_4 ;
V_171 [ V_165 ] . V_73 = 0 ;
if ( V_4 ) {
F_131 ( V_4 ) ;
F_128 ( V_4 -> V_139 ) ;
F_118 ( V_4 ) ;
}
}
F_132 ( V_182 , L_56 ) ;
F_129 ( V_171 ) ;
F_113 ( V_183 L_60 , V_182 ) ;
}
