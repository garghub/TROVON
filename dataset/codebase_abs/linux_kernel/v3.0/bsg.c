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
static int F_15 ( struct V_3 * V_4 )
{
F_16 ( V_21 ) ;
int V_22 = 0 ;
F_8 ( & V_4 -> V_7 ) ;
F_17 ( V_4 -> V_23 > V_4 -> V_8 ) ;
if ( V_4 -> V_23 == V_4 -> V_8 ) {
V_22 = - V_24 ;
goto V_25;
}
if ( ! F_18 ( V_26 , & V_4 -> V_5 ) ) {
V_22 = - V_27 ;
goto V_25;
}
F_19 ( & V_4 -> V_28 , & V_21 , V_29 ) ;
F_9 ( & V_4 -> V_7 ) ;
F_20 () ;
F_21 ( & V_4 -> V_28 , & V_21 ) ;
return V_22 ;
V_25:
F_9 ( & V_4 -> V_7 ) ;
return V_22 ;
}
static int F_22 ( struct V_30 * V_31 , struct V_32 * V_33 ,
struct V_34 * V_35 , struct V_3 * V_4 ,
T_1 V_36 )
{
if ( V_35 -> V_37 > V_38 ) {
V_33 -> V_39 = F_23 ( V_35 -> V_37 , V_13 ) ;
if ( ! V_33 -> V_39 )
return - V_14 ;
}
if ( F_24 ( V_33 -> V_39 , ( void * ) ( unsigned long ) V_35 -> V_32 ,
V_35 -> V_37 ) )
return - V_40 ;
if ( V_35 -> V_41 == V_42 ) {
if ( F_25 ( V_33 -> V_39 , V_36 ) )
return - V_43 ;
} else if ( ! F_26 ( V_44 ) )
return - V_43 ;
V_33 -> V_45 = V_35 -> V_37 ;
V_33 -> V_46 = V_47 ;
V_33 -> V_48 = F_27 ( V_35 -> V_48 ) ;
if ( ! V_33 -> V_48 )
V_33 -> V_48 = V_31 -> V_49 ;
if ( ! V_33 -> V_48 )
V_33 -> V_48 = V_50 ;
if ( V_33 -> V_48 < V_51 )
V_33 -> V_48 = V_51 ;
return 0 ;
}
static int
F_28 ( struct V_30 * V_31 , struct V_34 * V_35 , int * V_52 )
{
int V_22 = 0 ;
if ( V_35 -> V_53 != 'Q' )
return - V_10 ;
switch ( V_35 -> V_54 ) {
case V_55 :
switch ( V_35 -> V_41 ) {
case V_42 :
case V_56 :
break;
default:
V_22 = - V_10 ;
}
break;
default:
V_22 = - V_10 ;
}
* V_52 = V_35 -> V_57 ? V_58 : V_59 ;
return V_22 ;
}
static struct V_32 *
F_29 ( struct V_3 * V_4 , struct V_34 * V_35 , T_1 V_36 ,
T_2 * V_60 )
{
struct V_30 * V_31 = V_4 -> V_61 ;
struct V_32 * V_33 , * V_62 = NULL ;
int V_22 , V_52 ;
unsigned int V_63 ;
void * V_64 = NULL ;
struct V_65 * V_66 = & V_31 -> V_67 ;
if ( ! V_66 -> V_68 )
return F_7 ( - V_69 ) ;
F_13 ( L_2 , ( unsigned long long ) V_35 -> V_70 ,
V_35 -> V_57 , ( unsigned long long ) V_35 -> V_71 ,
V_35 -> V_72 ) ;
V_22 = F_28 ( V_31 , V_35 , & V_52 ) ;
if ( V_22 )
return F_7 ( V_22 ) ;
V_33 = F_30 ( V_31 , V_52 , V_13 ) ;
if ( ! V_33 )
return F_7 ( - V_14 ) ;
V_22 = F_22 ( V_31 , V_33 , V_35 , V_4 , V_36 ) ;
if ( V_22 )
goto V_12;
if ( V_52 == V_58 && V_35 -> V_72 ) {
if ( ! F_18 ( V_73 , & V_31 -> V_74 ) ) {
V_22 = - V_75 ;
goto V_12;
}
V_62 = F_30 ( V_31 , V_59 , V_13 ) ;
if ( ! V_62 ) {
V_22 = - V_14 ;
goto V_12;
}
V_33 -> V_62 = V_62 ;
V_62 -> V_46 = V_33 -> V_46 ;
V_64 = ( void * ) ( unsigned long ) V_35 -> V_71 ;
V_22 = F_31 ( V_31 , V_62 , NULL , V_64 ,
V_35 -> V_72 , V_13 ) ;
if ( V_22 )
goto V_12;
}
if ( V_35 -> V_57 ) {
V_63 = V_35 -> V_57 ;
V_64 = ( void * ) ( unsigned long ) V_35 -> V_70 ;
} else if ( V_35 -> V_72 ) {
V_63 = V_35 -> V_72 ;
V_64 = ( void * ) ( unsigned long ) V_35 -> V_71 ;
} else
V_63 = 0 ;
if ( V_63 ) {
V_22 = F_31 ( V_31 , V_33 , NULL , V_64 , V_63 ,
V_13 ) ;
if ( V_22 )
goto V_12;
}
V_33 -> V_60 = V_60 ;
V_33 -> V_76 = 0 ;
return V_33 ;
V_12:
if ( V_33 -> V_39 != V_33 -> V_77 )
F_32 ( V_33 -> V_39 ) ;
F_33 ( V_33 ) ;
if ( V_62 ) {
F_34 ( V_62 -> V_78 ) ;
F_33 ( V_62 ) ;
}
return F_7 ( V_22 ) ;
}
static void F_35 ( struct V_32 * V_33 , int V_79 )
{
struct V_1 * V_2 = V_33 -> V_80 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_5 ;
F_13 ( L_3 ,
V_4 -> V_16 , V_33 , V_2 , V_2 -> V_78 , V_79 ) ;
V_2 -> V_35 . V_81 = F_36 ( V_82 - V_2 -> V_35 . V_81 ) ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
F_37 ( & V_2 -> V_15 , & V_4 -> V_83 ) ;
V_4 -> V_23 ++ ;
F_4 ( & V_4 -> V_7 , V_5 ) ;
F_5 ( & V_4 -> V_28 ) ;
}
static void F_38 ( struct V_3 * V_4 , struct V_30 * V_31 ,
struct V_1 * V_2 , struct V_32 * V_33 )
{
int V_84 = ( 0 == ( V_2 -> V_35 . V_5 & V_85 ) ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_78 = V_33 -> V_78 ;
if ( V_33 -> V_62 )
V_2 -> V_86 = V_33 -> V_62 -> V_78 ;
V_2 -> V_35 . V_81 = V_82 ;
F_8 ( & V_4 -> V_7 ) ;
F_39 ( & V_2 -> V_15 , & V_4 -> V_87 ) ;
F_9 ( & V_4 -> V_7 ) ;
F_13 ( L_4 , V_4 -> V_16 , V_33 , V_2 ) ;
V_33 -> V_80 = V_2 ;
F_40 ( V_31 , NULL , V_33 , V_84 , F_35 ) ;
}
static struct V_1 * F_41 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = NULL ;
F_8 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_23 ) {
V_2 = F_42 ( & V_4 -> V_83 , struct V_1 , V_15 ) ;
F_43 ( & V_2 -> V_15 ) ;
V_4 -> V_23 -- ;
}
F_9 ( & V_4 -> V_7 ) ;
return V_2 ;
}
static struct V_1 * F_44 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_22 ;
do {
V_2 = F_41 ( V_4 ) ;
if ( V_2 )
break;
if ( ! F_18 ( V_26 , & V_4 -> V_5 ) ) {
V_2 = F_7 ( - V_27 ) ;
break;
}
V_22 = F_45 ( V_4 -> V_28 , V_4 -> V_23 ) ;
if ( V_22 ) {
V_2 = F_7 ( - V_88 ) ;
break;
}
} while ( 1 );
F_13 ( L_5 , V_4 -> V_16 , V_2 ) ;
return V_2 ;
}
static int F_46 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_78 * V_78 , struct V_78 * V_86 )
{
int V_22 = 0 ;
F_13 ( L_6 , V_33 , V_78 , V_33 -> V_89 ) ;
V_35 -> V_90 = V_33 -> V_89 & 0xff ;
V_35 -> V_91 = F_47 ( V_33 -> V_89 ) ;
V_35 -> V_92 = F_48 ( V_33 -> V_89 ) ;
V_35 -> V_93 = 0 ;
if ( V_35 -> V_90 || V_35 -> V_91 || V_35 -> V_92 )
V_35 -> V_93 |= V_94 ;
V_35 -> V_95 = 0 ;
if ( V_33 -> V_76 && V_35 -> V_96 ) {
int V_97 = F_49 (unsigned int, hdr->max_response_len,
rq->sense_len) ;
V_22 = F_50 ( ( void * ) ( unsigned long ) V_35 -> V_96 ,
V_33 -> V_60 , V_97 ) ;
if ( ! V_22 )
V_35 -> V_95 = V_97 ;
else
V_22 = - V_40 ;
}
if ( V_33 -> V_62 ) {
V_35 -> V_98 = V_33 -> V_99 ;
V_35 -> V_100 = V_33 -> V_62 -> V_99 ;
F_34 ( V_86 ) ;
F_33 ( V_33 -> V_62 ) ;
} else if ( F_51 ( V_33 ) == V_59 )
V_35 -> V_100 = V_33 -> V_99 ;
else
V_35 -> V_98 = V_33 -> V_99 ;
if ( ! V_22 && V_33 -> V_89 < 0 )
V_22 = V_33 -> V_89 ;
F_34 ( V_78 ) ;
if ( V_33 -> V_39 != V_33 -> V_77 )
F_32 ( V_33 -> V_39 ) ;
F_33 ( V_33 ) ;
return V_22 ;
}
static int F_52 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_22 , V_101 ;
F_13 ( L_7 , V_4 -> V_16 ) ;
V_22 = 0 ;
do {
V_22 = F_15 ( V_4 ) ;
} while ( V_22 != - V_24 );
V_22 = 0 ;
do {
F_8 ( & V_4 -> V_7 ) ;
if ( ! V_4 -> V_8 ) {
F_9 ( & V_4 -> V_7 ) ;
break;
}
F_9 ( & V_4 -> V_7 ) ;
V_2 = F_44 ( V_4 ) ;
if ( F_53 ( V_2 ) )
break;
V_101 = F_46 ( V_2 -> V_33 , & V_2 -> V_35 , V_2 -> V_78 ,
V_2 -> V_86 ) ;
if ( ! V_22 )
V_22 = V_101 ;
F_1 ( V_2 ) ;
} while ( 1 );
return V_22 ;
}
static int
F_54 ( char T_3 * V_102 , T_4 V_103 , struct V_3 * V_4 ,
const struct V_104 * V_105 , T_5 * V_106 )
{
struct V_1 * V_2 ;
int V_107 , V_22 ;
if ( V_103 % sizeof( struct V_34 ) )
return - V_10 ;
V_22 = 0 ;
V_107 = V_103 / sizeof( struct V_34 ) ;
while ( V_107 ) {
V_2 = F_44 ( V_4 ) ;
if ( F_53 ( V_2 ) ) {
V_22 = F_55 ( V_2 ) ;
break;
}
V_22 = F_46 ( V_2 -> V_33 , & V_2 -> V_35 , V_2 -> V_78 ,
V_2 -> V_86 ) ;
if ( F_50 ( V_102 , & V_2 -> V_35 , sizeof( V_2 -> V_35 ) ) )
V_22 = - V_40 ;
F_1 ( V_2 ) ;
if ( V_22 )
break;
V_102 += sizeof( struct V_34 ) ;
* V_106 += sizeof( struct V_34 ) ;
V_107 -- ;
}
return V_22 ;
}
static inline void F_56 ( struct V_3 * V_4 , struct V_108 * V_108 )
{
if ( V_108 -> V_109 & V_110 )
F_57 ( V_26 , & V_4 -> V_5 ) ;
else
F_58 ( V_26 , & V_4 -> V_5 ) ;
}
static inline int F_59 ( int V_22 )
{
if ( V_22 && V_22 != - V_111 && V_22 != - V_24 && V_22 != - V_27 )
return 1 ;
return 0 ;
}
static T_5
F_60 ( struct V_108 * V_108 , char T_3 * V_102 , T_4 V_103 , T_6 * V_112 )
{
struct V_3 * V_4 = V_108 -> V_113 ;
int V_22 ;
T_5 V_106 ;
F_13 ( L_8 , V_4 -> V_16 , V_103 ) ;
F_56 ( V_4 , V_108 ) ;
V_106 = 0 ;
V_22 = F_54 ( V_102 , V_103 , V_4 , NULL , & V_106 ) ;
* V_112 = V_106 ;
if ( ! V_106 || ( V_106 && F_59 ( V_22 ) ) )
V_106 = V_22 ;
return V_106 ;
}
static int F_61 ( struct V_3 * V_4 , const char T_3 * V_102 ,
T_4 V_103 , T_5 * V_114 ,
T_1 V_36 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
int V_22 , V_107 ;
if ( V_103 % sizeof( struct V_34 ) )
return - V_10 ;
V_107 = V_103 / sizeof( struct V_34 ) ;
V_33 = NULL ;
V_2 = NULL ;
V_22 = 0 ;
while ( V_107 ) {
struct V_30 * V_31 = V_4 -> V_61 ;
V_2 = F_6 ( V_4 ) ;
if ( F_53 ( V_2 ) ) {
V_22 = F_55 ( V_2 ) ;
V_2 = NULL ;
break;
}
if ( F_24 ( & V_2 -> V_35 , V_102 , sizeof( V_2 -> V_35 ) ) ) {
V_22 = - V_40 ;
break;
}
V_33 = F_29 ( V_4 , & V_2 -> V_35 , V_36 , V_2 -> V_60 ) ;
if ( F_53 ( V_33 ) ) {
V_22 = F_55 ( V_33 ) ;
V_33 = NULL ;
break;
}
F_38 ( V_4 , V_31 , V_2 , V_33 ) ;
V_2 = NULL ;
V_33 = NULL ;
V_107 -- ;
V_102 += sizeof( struct V_34 ) ;
* V_114 += sizeof( struct V_34 ) ;
}
if ( V_2 )
F_1 ( V_2 ) ;
return V_22 ;
}
static T_5
F_62 ( struct V_108 * V_108 , const char T_3 * V_102 , T_4 V_103 , T_6 * V_112 )
{
struct V_3 * V_4 = V_108 -> V_113 ;
T_5 V_114 ;
int V_22 ;
F_13 ( L_9 , V_4 -> V_16 , V_103 ) ;
F_56 ( V_4 , V_108 ) ;
V_114 = 0 ;
V_22 = F_61 ( V_4 , V_102 , V_103 , & V_114 ,
V_108 -> V_115 & V_116 ) ;
* V_112 = V_114 ;
if ( ! V_114 || ( V_114 && F_59 ( V_22 ) ) )
V_114 = V_22 ;
F_13 ( L_10 , V_4 -> V_16 , V_114 ) ;
return V_114 ;
}
static struct V_3 * F_63 ( void )
{
struct V_3 * V_4 ;
V_4 = F_23 ( sizeof( struct V_3 ) , V_13 ) ;
if ( F_11 ( ! V_4 ) )
return NULL ;
F_64 ( & V_4 -> V_7 ) ;
V_4 -> V_11 = V_117 ;
F_12 ( & V_4 -> V_87 ) ;
F_12 ( & V_4 -> V_83 ) ;
F_65 ( & V_4 -> V_118 ) ;
F_66 ( & V_4 -> V_9 ) ;
F_66 ( & V_4 -> V_28 ) ;
return V_4 ;
}
static void F_67 ( struct V_119 * V_119 )
{
struct V_65 * V_66 =
F_68 ( V_119 , struct V_65 , V_120 ) ;
struct V_121 * V_122 = V_66 -> V_122 ;
if ( V_66 -> V_123 )
V_66 -> V_123 ( V_66 -> V_122 ) ;
F_69 ( V_122 ) ;
}
static int F_70 ( struct V_3 * V_4 )
{
int V_22 = 0 , V_124 ;
struct V_30 * V_31 = V_4 -> V_61 ;
F_71 ( & V_125 ) ;
V_124 = F_72 ( & V_4 -> V_126 ) ;
if ( ! V_124 ) {
F_73 ( & V_125 ) ;
goto V_12;
}
F_74 ( & V_4 -> V_118 ) ;
F_73 ( & V_125 ) ;
F_13 ( L_11 , V_4 -> V_16 ) ;
F_58 ( V_26 , & V_4 -> V_5 ) ;
V_22 = F_52 ( V_4 ) ;
F_32 ( V_4 ) ;
V_12:
F_75 ( & V_31 -> V_67 . V_120 , F_67 ) ;
if ( V_124 )
F_76 ( V_31 ) ;
return V_22 ;
}
static struct V_3 * F_77 ( struct V_127 * V_127 ,
struct V_30 * V_33 ,
struct V_108 * V_108 )
{
struct V_3 * V_4 ;
int V_22 ;
#ifdef F_78
unsigned char V_102 [ 32 ] ;
#endif
V_22 = F_79 ( V_33 ) ;
if ( V_22 )
return F_7 ( - V_69 ) ;
V_4 = F_63 () ;
if ( ! V_4 ) {
F_76 ( V_33 ) ;
return F_7 ( - V_14 ) ;
}
V_4 -> V_61 = V_33 ;
F_56 ( V_4 , V_108 ) ;
F_80 ( & V_4 -> V_126 , 1 ) ;
F_71 ( & V_125 ) ;
F_81 ( & V_4 -> V_118 , F_14 ( F_82 ( V_127 ) ) ) ;
strncpy ( V_4 -> V_16 , F_83 ( V_33 -> V_67 . V_68 ) , sizeof( V_4 -> V_16 ) - 1 ) ;
F_13 ( L_12 ,
F_84 ( V_102 , V_127 -> V_128 ) , V_4 -> V_11 ) ;
F_73 ( & V_125 ) ;
return V_4 ;
}
static struct V_3 * F_85 ( int V_129 , struct V_30 * V_31 )
{
struct V_3 * V_4 ;
struct V_130 * V_131 ;
F_71 ( & V_125 ) ;
F_86 (bd, entry, bsg_dev_idx_hash(minor), dev_list) {
if ( V_4 -> V_61 == V_31 ) {
F_87 ( & V_4 -> V_126 ) ;
goto V_132;
}
}
V_4 = NULL ;
V_132:
F_73 ( & V_125 ) ;
return V_4 ;
}
static struct V_3 * F_88 ( struct V_127 * V_127 , struct V_108 * V_108 )
{
struct V_3 * V_4 ;
struct V_65 * V_66 ;
F_71 ( & V_125 ) ;
V_66 = F_89 ( & V_133 , F_82 ( V_127 ) ) ;
if ( V_66 )
F_90 ( & V_66 -> V_120 ) ;
F_73 ( & V_125 ) ;
if ( ! V_66 )
return F_7 ( - V_134 ) ;
V_4 = F_85 ( F_82 ( V_127 ) , V_66 -> V_61 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_77 ( V_127 , V_66 -> V_61 , V_108 ) ;
if ( F_53 ( V_4 ) )
F_75 ( & V_66 -> V_120 , F_67 ) ;
return V_4 ;
}
static int F_91 ( struct V_127 * V_127 , struct V_108 * V_108 )
{
struct V_3 * V_4 ;
V_4 = F_88 ( V_127 , V_108 ) ;
if ( F_53 ( V_4 ) )
return F_55 ( V_4 ) ;
V_108 -> V_113 = V_4 ;
return 0 ;
}
static int F_92 ( struct V_127 * V_127 , struct V_108 * V_108 )
{
struct V_3 * V_4 = V_108 -> V_113 ;
V_108 -> V_113 = NULL ;
return F_70 ( V_4 ) ;
}
static unsigned int F_93 ( struct V_108 * V_108 , T_7 * V_21 )
{
struct V_3 * V_4 = V_108 -> V_113 ;
unsigned int V_135 = 0 ;
F_94 ( V_108 , & V_4 -> V_28 , V_21 ) ;
F_94 ( V_108 , & V_4 -> V_9 , V_21 ) ;
F_8 ( & V_4 -> V_7 ) ;
if ( ! F_95 ( & V_4 -> V_83 ) )
V_135 |= V_136 | V_137 ;
if ( V_4 -> V_8 >= V_4 -> V_11 )
V_135 |= V_138 ;
F_9 ( & V_4 -> V_7 ) ;
return V_135 ;
}
static long F_96 ( struct V_108 * V_108 , unsigned int V_39 , unsigned long V_139 )
{
struct V_3 * V_4 = V_108 -> V_113 ;
int T_3 * V_140 = ( int T_3 * ) V_139 ;
int V_22 ;
switch ( V_39 ) {
case V_141 :
return F_97 ( V_4 -> V_11 , V_140 ) ;
case V_142 : {
int V_61 ;
if ( F_98 ( V_61 , V_140 ) )
return - V_40 ;
if ( V_61 < 1 )
return - V_10 ;
F_8 ( & V_4 -> V_7 ) ;
V_4 -> V_11 = V_61 ;
F_9 ( & V_4 -> V_7 ) ;
return 0 ;
}
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 : {
void T_3 * V_140 = ( void T_3 * ) V_139 ;
return F_99 ( V_4 -> V_61 , NULL , V_108 -> V_115 , V_39 , V_140 ) ;
}
case V_152 : {
struct V_32 * V_33 ;
struct V_78 * V_78 , * V_86 = NULL ;
struct V_34 V_35 ;
int V_84 ;
T_2 V_60 [ V_153 ] ;
if ( F_24 ( & V_35 , V_140 , sizeof( V_35 ) ) )
return - V_40 ;
V_33 = F_29 ( V_4 , & V_35 , V_108 -> V_115 & V_116 , V_60 ) ;
if ( F_53 ( V_33 ) )
return F_55 ( V_33 ) ;
V_78 = V_33 -> V_78 ;
if ( V_33 -> V_62 )
V_86 = V_33 -> V_62 -> V_78 ;
V_84 = ( 0 == ( V_35 . V_5 & V_85 ) ) ;
F_100 ( V_4 -> V_61 , NULL , V_33 , V_84 ) ;
V_22 = F_46 ( V_33 , & V_35 , V_78 , V_86 ) ;
if ( F_50 ( V_140 , & V_35 , sizeof( V_35 ) ) )
return - V_40 ;
return V_22 ;
}
default:
#if 0
return ioctl_by_bdev(bd->bdev, cmd, arg);
#else
return - V_154 ;
#endif
}
}
void F_101 ( struct V_30 * V_31 )
{
struct V_65 * V_66 = & V_31 -> V_67 ;
if ( ! V_66 -> V_68 )
return;
F_71 ( & V_125 ) ;
F_102 ( & V_133 , V_66 -> V_129 ) ;
F_103 ( & V_31 -> V_155 , L_13 ) ;
F_104 ( V_66 -> V_68 ) ;
V_66 -> V_68 = NULL ;
F_75 ( & V_66 -> V_120 , F_67 ) ;
F_73 ( & V_125 ) ;
}
int F_105 ( struct V_30 * V_31 , struct V_121 * V_122 ,
const char * V_16 , void (* V_123)( struct V_121 * ) )
{
struct V_65 * V_66 ;
T_8 V_156 ;
int V_22 , V_129 ;
struct V_121 * V_68 = NULL ;
const char * V_157 ;
if ( V_16 )
V_157 = V_16 ;
else
V_157 = F_83 ( V_122 ) ;
if ( ! V_31 -> V_158 )
return 0 ;
V_66 = & V_31 -> V_67 ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
F_71 ( & V_125 ) ;
V_22 = F_106 ( & V_133 , V_13 ) ;
if ( ! V_22 ) {
V_22 = - V_14 ;
goto V_25;
}
V_22 = F_107 ( & V_133 , V_66 , & V_129 ) ;
if ( V_22 < 0 )
goto V_25;
if ( V_129 >= V_159 ) {
F_108 ( V_160 L_14 ) ;
V_22 = - V_10 ;
goto V_161;
}
V_66 -> V_129 = V_129 ;
V_66 -> V_61 = V_31 ;
V_66 -> V_122 = F_109 ( V_122 ) ;
V_66 -> V_123 = V_123 ;
F_110 ( & V_66 -> V_120 ) ;
V_156 = F_111 ( V_162 , V_66 -> V_129 ) ;
V_68 = F_112 ( V_163 , V_122 , V_156 , NULL , L_15 , V_157 ) ;
if ( F_53 ( V_68 ) ) {
V_22 = F_55 ( V_68 ) ;
goto V_164;
}
V_66 -> V_68 = V_68 ;
if ( V_31 -> V_155 . V_165 ) {
V_22 = F_113 ( & V_31 -> V_155 , & V_66 -> V_68 -> V_155 , L_13 ) ;
if ( V_22 )
goto V_166;
}
F_73 ( & V_125 ) ;
return 0 ;
V_166:
F_104 ( V_68 ) ;
V_164:
F_69 ( V_122 ) ;
V_161:
F_102 ( & V_133 , V_129 ) ;
V_25:
F_73 ( & V_125 ) ;
return V_22 ;
}
static char * F_114 ( struct V_121 * V_156 , T_9 * V_167 )
{
return F_115 ( V_13 , L_16 , F_83 ( V_156 ) ) ;
}
static int T_10 F_116 ( void )
{
int V_22 , V_168 ;
T_8 V_169 ;
V_6 = F_117 ( L_17 ,
sizeof( struct V_1 ) , 0 , 0 , NULL ) ;
if ( ! V_6 ) {
F_108 ( V_160 L_18 ) ;
return - V_14 ;
}
for ( V_168 = 0 ; V_168 < V_20 ; V_168 ++ )
F_118 ( & V_19 [ V_168 ] ) ;
V_163 = F_119 ( V_170 , L_13 ) ;
if ( F_53 ( V_163 ) ) {
V_22 = F_55 ( V_163 ) ;
goto V_171;
}
V_163 -> V_172 = F_114 ;
V_22 = F_120 ( & V_169 , 0 , V_159 , L_13 ) ;
if ( V_22 )
goto V_173;
V_162 = F_121 ( V_169 ) ;
F_122 ( & V_174 , & V_175 ) ;
V_22 = F_123 ( & V_174 , F_111 ( V_162 , 0 ) , V_159 ) ;
if ( V_22 )
goto V_176;
F_108 (KERN_INFO BSG_DESCRIPTION L_19 BSG_VERSION
L_20 , bsg_major) ;
return 0 ;
V_176:
F_124 ( F_111 ( V_162 , 0 ) , V_159 ) ;
V_173:
F_125 ( V_163 ) ;
V_171:
F_126 ( V_6 ) ;
return V_22 ;
}
