static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_5 ;
F_2 ( V_6 , V_2 ) ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
V_4 -> V_8 -- ;
F_4 ( & V_4 -> V_7 , V_5 ) ;
F_5 ( & V_4 -> V_9 ) ;
}
static struct V_1 * F_6 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_7 ( - V_10 ) ;
F_8 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_8 >= V_4 -> V_11 )
goto V_12;
V_4 -> V_8 ++ ;
F_9 ( & V_4 -> V_7 ) ;
V_2 = F_10 ( V_6 , V_13 ) ;
if ( F_11 ( ! V_2 ) ) {
F_8 ( & V_4 -> V_7 ) ;
V_4 -> V_8 -- ;
V_2 = F_7 ( - V_14 ) ;
goto V_12;
}
V_2 -> V_4 = V_4 ;
F_12 ( & V_2 -> V_15 ) ;
F_13 ( L_1 , V_4 -> V_16 , V_2 ) ;
return V_2 ;
V_12:
F_9 ( & V_4 -> V_7 ) ;
return V_2 ;
}
static inline struct V_17 * F_14 ( int V_18 )
{
return & V_19 [ V_18 & ( V_20 - 1 ) ] ;
}
static int F_15 ( struct V_21 * V_22 , struct V_23 * V_24 ,
struct V_25 * V_26 , struct V_3 * V_4 ,
T_1 V_27 )
{
if ( V_26 -> V_28 > V_29 ) {
V_24 -> V_30 = F_16 ( V_26 -> V_28 , V_13 ) ;
if ( ! V_24 -> V_30 )
return - V_14 ;
}
if ( F_17 ( V_24 -> V_30 , ( void V_31 * ) ( unsigned long ) V_26 -> V_23 ,
V_26 -> V_28 ) )
return - V_32 ;
if ( V_26 -> V_33 == V_34 ) {
if ( F_18 ( V_24 -> V_30 , V_27 ) )
return - V_35 ;
} else if ( ! F_19 ( V_36 ) )
return - V_35 ;
V_24 -> V_37 = V_26 -> V_28 ;
V_24 -> V_38 = F_20 ( V_26 -> V_38 ) ;
if ( ! V_24 -> V_38 )
V_24 -> V_38 = V_22 -> V_39 ;
if ( ! V_24 -> V_38 )
V_24 -> V_38 = V_40 ;
if ( V_24 -> V_38 < V_41 )
V_24 -> V_38 = V_41 ;
return 0 ;
}
static int
F_21 ( struct V_25 * V_26 , int * V_42 )
{
int V_43 = 0 ;
if ( V_26 -> V_44 != 'Q' )
return - V_10 ;
switch ( V_26 -> V_45 ) {
case V_46 :
switch ( V_26 -> V_33 ) {
case V_34 :
case V_47 :
break;
default:
V_43 = - V_10 ;
}
break;
default:
V_43 = - V_10 ;
}
* V_42 = V_26 -> V_48 ? V_49 : V_50 ;
return V_43 ;
}
static struct V_23 *
F_22 ( struct V_3 * V_4 , struct V_25 * V_26 , T_1 V_27 ,
T_2 * V_51 )
{
struct V_21 * V_22 = V_4 -> V_52 ;
struct V_23 * V_24 , * V_53 = NULL ;
int V_43 , V_42 ;
unsigned int V_54 ;
void V_31 * V_55 = NULL ;
struct V_56 * V_57 = & V_22 -> V_58 ;
if ( ! V_57 -> V_59 )
return F_7 ( - V_60 ) ;
F_13 ( L_2 , ( unsigned long long ) V_26 -> V_61 ,
V_26 -> V_48 , ( unsigned long long ) V_26 -> V_62 ,
V_26 -> V_63 ) ;
V_43 = F_21 ( V_26 , & V_42 ) ;
if ( V_43 )
return F_7 ( V_43 ) ;
V_24 = F_23 ( V_22 , V_42 , V_13 ) ;
if ( F_24 ( V_24 ) )
return V_24 ;
F_25 ( V_24 ) ;
V_43 = F_15 ( V_22 , V_24 , V_26 , V_4 , V_27 ) ;
if ( V_43 )
goto V_12;
if ( V_42 == V_49 && V_26 -> V_63 ) {
if ( ! F_26 ( V_64 , & V_22 -> V_65 ) ) {
V_43 = - V_66 ;
goto V_12;
}
V_53 = F_23 ( V_22 , V_50 , V_13 ) ;
if ( F_24 ( V_53 ) ) {
V_43 = F_27 ( V_53 ) ;
V_53 = NULL ;
goto V_12;
}
V_24 -> V_53 = V_53 ;
V_53 -> V_67 = V_24 -> V_67 ;
V_55 = ( void V_31 * ) ( unsigned long ) V_26 -> V_62 ;
V_43 = F_28 ( V_22 , V_53 , NULL , V_55 ,
V_26 -> V_63 , V_13 ) ;
if ( V_43 )
goto V_12;
}
if ( V_26 -> V_48 ) {
V_54 = V_26 -> V_48 ;
V_55 = ( void V_31 * ) ( unsigned long ) V_26 -> V_61 ;
} else if ( V_26 -> V_63 ) {
V_54 = V_26 -> V_63 ;
V_55 = ( void V_31 * ) ( unsigned long ) V_26 -> V_62 ;
} else
V_54 = 0 ;
if ( V_54 ) {
V_43 = F_28 ( V_22 , V_24 , NULL , V_55 , V_54 ,
V_13 ) ;
if ( V_43 )
goto V_12;
}
V_24 -> V_51 = V_51 ;
V_24 -> V_68 = 0 ;
return V_24 ;
V_12:
if ( V_24 -> V_30 != V_24 -> V_69 )
F_29 ( V_24 -> V_30 ) ;
F_30 ( V_24 ) ;
if ( V_53 ) {
F_31 ( V_53 -> V_70 ) ;
F_30 ( V_53 ) ;
}
return F_7 ( V_43 ) ;
}
static void F_32 ( struct V_23 * V_24 , int V_71 )
{
struct V_1 * V_2 = V_24 -> V_72 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_5 ;
F_13 ( L_3 ,
V_4 -> V_16 , V_24 , V_2 , V_2 -> V_70 , V_71 ) ;
V_2 -> V_26 . V_73 = F_33 ( V_74 - V_2 -> V_26 . V_73 ) ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
F_34 ( & V_2 -> V_15 , & V_4 -> V_75 ) ;
V_4 -> V_76 ++ ;
F_4 ( & V_4 -> V_7 , V_5 ) ;
F_5 ( & V_4 -> V_77 ) ;
}
static void F_35 ( struct V_3 * V_4 , struct V_21 * V_22 ,
struct V_1 * V_2 , struct V_23 * V_24 )
{
int V_78 = ( 0 == ( V_2 -> V_26 . V_5 & V_79 ) ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_70 = V_24 -> V_70 ;
if ( V_24 -> V_53 )
V_2 -> V_80 = V_24 -> V_53 -> V_70 ;
V_2 -> V_26 . V_73 = V_74 ;
F_8 ( & V_4 -> V_7 ) ;
F_36 ( & V_2 -> V_15 , & V_4 -> V_81 ) ;
F_9 ( & V_4 -> V_7 ) ;
F_13 ( L_4 , V_4 -> V_16 , V_24 , V_2 ) ;
V_24 -> V_72 = V_2 ;
F_37 ( V_22 , NULL , V_24 , V_78 , F_32 ) ;
}
static struct V_1 * F_38 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = NULL ;
F_8 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_76 ) {
V_2 = F_39 ( & V_4 -> V_75 , struct V_1 , V_15 ) ;
F_40 ( & V_2 -> V_15 ) ;
V_4 -> V_76 -- ;
}
F_9 ( & V_4 -> V_7 ) ;
return V_2 ;
}
static struct V_1 * F_41 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_43 ;
do {
V_2 = F_38 ( V_4 ) ;
if ( V_2 )
break;
if ( ! F_26 ( V_82 , & V_4 -> V_5 ) ) {
V_2 = F_7 ( - V_83 ) ;
break;
}
V_43 = F_42 ( V_4 -> V_77 , V_4 -> V_76 ) ;
if ( V_43 ) {
V_2 = F_7 ( - V_84 ) ;
break;
}
} while ( 1 );
F_13 ( L_5 , V_4 -> V_16 , V_2 ) ;
return V_2 ;
}
static int F_43 ( struct V_23 * V_24 , struct V_25 * V_26 ,
struct V_70 * V_70 , struct V_70 * V_80 )
{
int V_43 = 0 ;
F_13 ( L_6 , V_24 , V_70 , V_24 -> V_85 ) ;
V_26 -> V_86 = V_24 -> V_85 & 0xff ;
V_26 -> V_87 = F_44 ( V_24 -> V_85 ) ;
V_26 -> V_88 = F_45 ( V_24 -> V_85 ) ;
V_26 -> V_89 = 0 ;
if ( V_26 -> V_86 || V_26 -> V_87 || V_26 -> V_88 )
V_26 -> V_89 |= V_90 ;
V_26 -> V_91 = 0 ;
if ( V_24 -> V_68 && V_26 -> V_92 ) {
int V_93 = F_46 (unsigned int, hdr->max_response_len,
rq->sense_len) ;
V_43 = F_47 ( ( void V_31 * ) ( unsigned long ) V_26 -> V_92 ,
V_24 -> V_51 , V_93 ) ;
if ( ! V_43 )
V_26 -> V_91 = V_93 ;
else
V_43 = - V_32 ;
}
if ( V_24 -> V_53 ) {
V_26 -> V_94 = V_24 -> V_95 ;
V_26 -> V_96 = V_24 -> V_53 -> V_95 ;
F_31 ( V_80 ) ;
F_30 ( V_24 -> V_53 ) ;
} else if ( F_48 ( V_24 ) == V_50 )
V_26 -> V_96 = V_24 -> V_95 ;
else
V_26 -> V_94 = V_24 -> V_95 ;
if ( ! V_43 && V_24 -> V_85 < 0 )
V_43 = V_24 -> V_85 ;
F_31 ( V_70 ) ;
if ( V_24 -> V_30 != V_24 -> V_69 )
F_29 ( V_24 -> V_30 ) ;
F_30 ( V_24 ) ;
return V_43 ;
}
static bool F_49 ( struct V_3 * V_4 )
{
bool V_43 = false ;
bool V_97 ;
do {
F_8 ( & V_4 -> V_7 ) ;
F_50 ( V_4 -> V_76 > V_4 -> V_8 ) ;
if ( V_4 -> V_76 == V_4 -> V_8 )
V_43 = true ;
V_97 = ! F_26 ( V_82 , & V_4 -> V_5 ) ;
F_9 ( & V_4 -> V_7 ) ;
} while ( ! V_43 && V_97 );
return V_43 ;
}
static int F_51 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_43 , V_98 ;
F_13 ( L_7 , V_4 -> V_16 ) ;
F_52 ( V_4 -> V_77 , F_49 ( V_4 ) ) ;
V_43 = 0 ;
do {
F_8 ( & V_4 -> V_7 ) ;
if ( ! V_4 -> V_8 ) {
F_9 ( & V_4 -> V_7 ) ;
break;
}
F_9 ( & V_4 -> V_7 ) ;
V_2 = F_41 ( V_4 ) ;
if ( F_24 ( V_2 ) )
break;
V_98 = F_43 ( V_2 -> V_24 , & V_2 -> V_26 , V_2 -> V_70 ,
V_2 -> V_80 ) ;
if ( ! V_43 )
V_43 = V_98 ;
F_1 ( V_2 ) ;
} while ( 1 );
return V_43 ;
}
static int
F_53 ( char V_31 * V_99 , T_3 V_100 , struct V_3 * V_4 ,
const struct V_101 * V_102 , T_4 * V_103 )
{
struct V_1 * V_2 ;
int V_104 , V_43 ;
if ( V_100 % sizeof( struct V_25 ) )
return - V_10 ;
V_43 = 0 ;
V_104 = V_100 / sizeof( struct V_25 ) ;
while ( V_104 ) {
V_2 = F_41 ( V_4 ) ;
if ( F_24 ( V_2 ) ) {
V_43 = F_27 ( V_2 ) ;
break;
}
V_43 = F_43 ( V_2 -> V_24 , & V_2 -> V_26 , V_2 -> V_70 ,
V_2 -> V_80 ) ;
if ( F_47 ( V_99 , & V_2 -> V_26 , sizeof( V_2 -> V_26 ) ) )
V_43 = - V_32 ;
F_1 ( V_2 ) ;
if ( V_43 )
break;
V_99 += sizeof( struct V_25 ) ;
* V_103 += sizeof( struct V_25 ) ;
V_104 -- ;
}
return V_43 ;
}
static inline void F_54 ( struct V_3 * V_4 , struct V_105 * V_105 )
{
if ( V_105 -> V_106 & V_107 )
F_55 ( V_82 , & V_4 -> V_5 ) ;
else
F_56 ( V_82 , & V_4 -> V_5 ) ;
}
static inline int F_57 ( int V_43 )
{
if ( V_43 && V_43 != - V_108 && V_43 != - V_109 && V_43 != - V_83 )
return 1 ;
return 0 ;
}
static T_4
F_58 ( struct V_105 * V_105 , char V_31 * V_99 , T_3 V_100 , T_5 * V_110 )
{
struct V_3 * V_4 = V_105 -> V_111 ;
int V_43 ;
T_4 V_103 ;
F_13 ( L_8 , V_4 -> V_16 , V_100 ) ;
F_54 ( V_4 , V_105 ) ;
V_103 = 0 ;
V_43 = F_53 ( V_99 , V_100 , V_4 , NULL , & V_103 ) ;
* V_110 = V_103 ;
if ( ! V_103 || F_57 ( V_43 ) )
V_103 = V_43 ;
return V_103 ;
}
static int F_59 ( struct V_3 * V_4 , const char V_31 * V_99 ,
T_3 V_100 , T_4 * V_112 ,
T_1 V_27 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_43 , V_104 ;
if ( V_100 % sizeof( struct V_25 ) )
return - V_10 ;
V_104 = V_100 / sizeof( struct V_25 ) ;
V_24 = NULL ;
V_2 = NULL ;
V_43 = 0 ;
while ( V_104 ) {
struct V_21 * V_22 = V_4 -> V_52 ;
V_2 = F_6 ( V_4 ) ;
if ( F_24 ( V_2 ) ) {
V_43 = F_27 ( V_2 ) ;
V_2 = NULL ;
break;
}
if ( F_17 ( & V_2 -> V_26 , V_99 , sizeof( V_2 -> V_26 ) ) ) {
V_43 = - V_32 ;
break;
}
V_24 = F_22 ( V_4 , & V_2 -> V_26 , V_27 , V_2 -> V_51 ) ;
if ( F_24 ( V_24 ) ) {
V_43 = F_27 ( V_24 ) ;
V_24 = NULL ;
break;
}
F_35 ( V_4 , V_22 , V_2 , V_24 ) ;
V_2 = NULL ;
V_24 = NULL ;
V_104 -- ;
V_99 += sizeof( struct V_25 ) ;
* V_112 += sizeof( struct V_25 ) ;
}
if ( V_2 )
F_1 ( V_2 ) ;
return V_43 ;
}
static T_4
F_60 ( struct V_105 * V_105 , const char V_31 * V_99 , T_3 V_100 , T_5 * V_110 )
{
struct V_3 * V_4 = V_105 -> V_111 ;
T_4 V_112 ;
int V_43 ;
F_13 ( L_9 , V_4 -> V_16 , V_100 ) ;
if ( F_11 ( F_61 ( F_62 () , V_113 ) ) )
return - V_10 ;
F_54 ( V_4 , V_105 ) ;
V_112 = 0 ;
V_43 = F_59 ( V_4 , V_99 , V_100 , & V_112 ,
V_105 -> V_114 & V_115 ) ;
* V_110 = V_112 ;
if ( ! V_112 || F_57 ( V_43 ) )
V_112 = V_43 ;
F_13 ( L_10 , V_4 -> V_16 , V_112 ) ;
return V_112 ;
}
static struct V_3 * F_63 ( void )
{
struct V_3 * V_4 ;
V_4 = F_16 ( sizeof( struct V_3 ) , V_13 ) ;
if ( F_11 ( ! V_4 ) )
return NULL ;
F_64 ( & V_4 -> V_7 ) ;
V_4 -> V_11 = V_116 ;
F_12 ( & V_4 -> V_81 ) ;
F_12 ( & V_4 -> V_75 ) ;
F_65 ( & V_4 -> V_117 ) ;
F_66 ( & V_4 -> V_9 ) ;
F_66 ( & V_4 -> V_77 ) ;
return V_4 ;
}
static void F_67 ( struct V_118 * V_118 )
{
struct V_56 * V_57 =
F_68 ( V_118 , struct V_56 , V_119 ) ;
struct V_120 * V_121 = V_57 -> V_121 ;
if ( V_57 -> V_122 )
V_57 -> V_122 ( V_57 -> V_121 ) ;
F_69 ( V_121 ) ;
}
static int F_70 ( struct V_3 * V_4 )
{
int V_43 = 0 , V_123 ;
struct V_21 * V_22 = V_4 -> V_52 ;
F_71 ( & V_124 ) ;
V_123 = F_72 ( & V_4 -> V_125 ) ;
if ( ! V_123 ) {
F_73 ( & V_124 ) ;
goto V_12;
}
F_74 ( & V_4 -> V_117 ) ;
F_73 ( & V_124 ) ;
F_13 ( L_11 , V_4 -> V_16 ) ;
F_56 ( V_82 , & V_4 -> V_5 ) ;
V_43 = F_51 ( V_4 ) ;
F_29 ( V_4 ) ;
V_12:
F_75 ( & V_22 -> V_58 . V_119 , F_67 ) ;
if ( V_123 )
F_76 ( V_22 ) ;
return V_43 ;
}
static struct V_3 * F_77 ( struct V_126 * V_126 ,
struct V_21 * V_24 ,
struct V_105 * V_105 )
{
struct V_3 * V_4 ;
#ifdef F_78
unsigned char V_99 [ 32 ] ;
#endif
if ( ! F_79 ( V_24 ) )
return F_7 ( - V_60 ) ;
V_4 = F_63 () ;
if ( ! V_4 ) {
F_76 ( V_24 ) ;
return F_7 ( - V_14 ) ;
}
V_4 -> V_52 = V_24 ;
F_54 ( V_4 , V_105 ) ;
F_80 ( & V_4 -> V_125 , 1 ) ;
F_71 ( & V_124 ) ;
F_81 ( & V_4 -> V_117 , F_14 ( F_82 ( V_126 ) ) ) ;
strncpy ( V_4 -> V_16 , F_83 ( V_24 -> V_58 . V_59 ) , sizeof( V_4 -> V_16 ) - 1 ) ;
F_13 ( L_12 ,
F_84 ( V_99 , V_126 -> V_127 ) , V_4 -> V_11 ) ;
F_73 ( & V_124 ) ;
return V_4 ;
}
static struct V_3 * F_85 ( int V_128 , struct V_21 * V_22 )
{
struct V_3 * V_4 ;
F_71 ( & V_124 ) ;
F_86 (bd, bsg_dev_idx_hash(minor), dev_list) {
if ( V_4 -> V_52 == V_22 ) {
F_87 ( & V_4 -> V_125 ) ;
goto V_129;
}
}
V_4 = NULL ;
V_129:
F_73 ( & V_124 ) ;
return V_4 ;
}
static struct V_3 * F_88 ( struct V_126 * V_126 , struct V_105 * V_105 )
{
struct V_3 * V_4 ;
struct V_56 * V_57 ;
F_71 ( & V_124 ) ;
V_57 = F_89 ( & V_130 , F_82 ( V_126 ) ) ;
if ( V_57 )
F_90 ( & V_57 -> V_119 ) ;
F_73 ( & V_124 ) ;
if ( ! V_57 )
return F_7 ( - V_131 ) ;
V_4 = F_85 ( F_82 ( V_126 ) , V_57 -> V_52 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_77 ( V_126 , V_57 -> V_52 , V_105 ) ;
if ( F_24 ( V_4 ) )
F_75 ( & V_57 -> V_119 , F_67 ) ;
return V_4 ;
}
static int F_91 ( struct V_126 * V_126 , struct V_105 * V_105 )
{
struct V_3 * V_4 ;
V_4 = F_88 ( V_126 , V_105 ) ;
if ( F_24 ( V_4 ) )
return F_27 ( V_4 ) ;
V_105 -> V_111 = V_4 ;
return 0 ;
}
static int F_92 ( struct V_126 * V_126 , struct V_105 * V_105 )
{
struct V_3 * V_4 = V_105 -> V_111 ;
V_105 -> V_111 = NULL ;
return F_70 ( V_4 ) ;
}
static unsigned int F_93 ( struct V_105 * V_105 , T_6 * V_132 )
{
struct V_3 * V_4 = V_105 -> V_111 ;
unsigned int V_133 = 0 ;
F_94 ( V_105 , & V_4 -> V_77 , V_132 ) ;
F_94 ( V_105 , & V_4 -> V_9 , V_132 ) ;
F_8 ( & V_4 -> V_7 ) ;
if ( ! F_95 ( & V_4 -> V_75 ) )
V_133 |= V_134 | V_135 ;
if ( V_4 -> V_8 < V_4 -> V_11 )
V_133 |= V_136 ;
F_9 ( & V_4 -> V_7 ) ;
return V_133 ;
}
static long F_96 ( struct V_105 * V_105 , unsigned int V_30 , unsigned long V_137 )
{
struct V_3 * V_4 = V_105 -> V_111 ;
int V_31 * V_138 = ( int V_31 * ) V_137 ;
int V_43 ;
switch ( V_30 ) {
case V_139 :
return F_97 ( V_4 -> V_11 , V_138 ) ;
case V_140 : {
int V_52 ;
if ( F_98 ( V_52 , V_138 ) )
return - V_32 ;
if ( V_52 < 1 )
return - V_10 ;
F_8 ( & V_4 -> V_7 ) ;
V_4 -> V_11 = V_52 ;
F_9 ( & V_4 -> V_7 ) ;
return 0 ;
}
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 : {
void V_31 * V_138 = ( void V_31 * ) V_137 ;
return F_99 ( V_4 -> V_52 , NULL , V_105 -> V_114 , V_30 , V_138 ) ;
}
case V_150 : {
struct V_23 * V_24 ;
struct V_70 * V_70 , * V_80 = NULL ;
struct V_25 V_26 ;
int V_78 ;
T_2 V_51 [ V_151 ] ;
if ( F_17 ( & V_26 , V_138 , sizeof( V_26 ) ) )
return - V_32 ;
V_24 = F_22 ( V_4 , & V_26 , V_105 -> V_114 & V_115 , V_51 ) ;
if ( F_24 ( V_24 ) )
return F_27 ( V_24 ) ;
V_70 = V_24 -> V_70 ;
if ( V_24 -> V_53 )
V_80 = V_24 -> V_53 -> V_70 ;
V_78 = ( 0 == ( V_26 . V_5 & V_79 ) ) ;
F_100 ( V_4 -> V_52 , NULL , V_24 , V_78 ) ;
V_43 = F_43 ( V_24 , & V_26 , V_70 , V_80 ) ;
if ( F_47 ( V_138 , & V_26 , sizeof( V_26 ) ) )
return - V_32 ;
return V_43 ;
}
default:
#if 0
return ioctl_by_bdev(bd->bdev, cmd, arg);
#else
return - V_152 ;
#endif
}
}
void F_101 ( struct V_21 * V_22 )
{
struct V_56 * V_57 = & V_22 -> V_58 ;
if ( ! V_57 -> V_59 )
return;
F_71 ( & V_124 ) ;
F_102 ( & V_130 , V_57 -> V_128 ) ;
if ( V_22 -> V_153 . V_154 )
F_103 ( & V_22 -> V_153 , L_13 ) ;
F_104 ( V_57 -> V_59 ) ;
V_57 -> V_59 = NULL ;
F_75 ( & V_57 -> V_119 , F_67 ) ;
F_73 ( & V_124 ) ;
}
int F_105 ( struct V_21 * V_22 , struct V_120 * V_121 ,
const char * V_16 , void (* V_122)( struct V_120 * ) )
{
struct V_56 * V_57 ;
T_7 V_155 ;
int V_43 ;
struct V_120 * V_59 = NULL ;
const char * V_156 ;
if ( V_16 )
V_156 = V_16 ;
else
V_156 = F_83 ( V_121 ) ;
if ( ! F_106 ( V_22 ) )
return 0 ;
V_57 = & V_22 -> V_58 ;
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
F_71 ( & V_124 ) ;
V_43 = F_107 ( & V_130 , V_57 , 0 , V_157 , V_13 ) ;
if ( V_43 < 0 ) {
if ( V_43 == - V_108 ) {
F_108 ( V_158 L_14 ) ;
V_43 = - V_10 ;
}
goto V_159;
}
V_57 -> V_128 = V_43 ;
V_57 -> V_52 = V_22 ;
V_57 -> V_121 = F_109 ( V_121 ) ;
V_57 -> V_122 = V_122 ;
F_110 ( & V_57 -> V_119 ) ;
V_155 = F_111 ( V_160 , V_57 -> V_128 ) ;
V_59 = F_112 ( V_161 , V_121 , V_155 , NULL , L_15 , V_156 ) ;
if ( F_24 ( V_59 ) ) {
V_43 = F_27 ( V_59 ) ;
goto V_162;
}
V_57 -> V_59 = V_59 ;
if ( V_22 -> V_153 . V_154 ) {
V_43 = F_113 ( & V_22 -> V_153 , & V_57 -> V_59 -> V_153 , L_13 ) ;
if ( V_43 )
goto V_163;
}
F_73 ( & V_124 ) ;
return 0 ;
V_163:
F_104 ( V_59 ) ;
V_162:
F_69 ( V_121 ) ;
F_102 ( & V_130 , V_57 -> V_128 ) ;
V_159:
F_73 ( & V_124 ) ;
return V_43 ;
}
static char * F_114 ( struct V_120 * V_155 , T_8 * V_164 )
{
return F_115 ( V_13 , L_16 , F_83 ( V_155 ) ) ;
}
static int T_9 F_116 ( void )
{
int V_43 , V_165 ;
T_7 V_166 ;
V_6 = F_117 ( L_17 ,
sizeof( struct V_1 ) , 0 , 0 , NULL ) ;
if ( ! V_6 ) {
F_108 ( V_158 L_18 ) ;
return - V_14 ;
}
for ( V_165 = 0 ; V_165 < V_20 ; V_165 ++ )
F_118 ( & V_19 [ V_165 ] ) ;
V_161 = F_119 ( V_167 , L_13 ) ;
if ( F_24 ( V_161 ) ) {
V_43 = F_27 ( V_161 ) ;
goto V_168;
}
V_161 -> V_169 = F_114 ;
V_43 = F_120 ( & V_166 , 0 , V_157 , L_13 ) ;
if ( V_43 )
goto V_170;
V_160 = F_121 ( V_166 ) ;
F_122 ( & V_171 , & V_172 ) ;
V_43 = F_123 ( & V_171 , F_111 ( V_160 , 0 ) , V_157 ) ;
if ( V_43 )
goto V_173;
F_108 (KERN_INFO BSG_DESCRIPTION L_19 BSG_VERSION
L_20 , bsg_major) ;
return 0 ;
V_173:
F_124 ( F_111 ( V_160 , 0 ) , V_157 ) ;
V_170:
F_125 ( V_161 ) ;
V_168:
F_126 ( V_6 ) ;
return V_43 ;
}
