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
if ( F_24 ( V_33 -> V_39 , ( void V_40 * ) ( unsigned long ) V_35 -> V_32 ,
V_35 -> V_37 ) )
return - V_41 ;
if ( V_35 -> V_42 == V_43 ) {
if ( F_25 ( V_33 -> V_39 , V_36 ) )
return - V_44 ;
} else if ( ! F_26 ( V_45 ) )
return - V_44 ;
V_33 -> V_46 = V_35 -> V_37 ;
V_33 -> V_47 = V_48 ;
V_33 -> V_49 = F_27 ( V_35 -> V_49 ) ;
if ( ! V_33 -> V_49 )
V_33 -> V_49 = V_31 -> V_50 ;
if ( ! V_33 -> V_49 )
V_33 -> V_49 = V_51 ;
if ( V_33 -> V_49 < V_52 )
V_33 -> V_49 = V_52 ;
return 0 ;
}
static int
F_28 ( struct V_30 * V_31 , struct V_34 * V_35 , int * V_53 )
{
int V_22 = 0 ;
if ( V_35 -> V_54 != 'Q' )
return - V_10 ;
switch ( V_35 -> V_55 ) {
case V_56 :
switch ( V_35 -> V_42 ) {
case V_43 :
case V_57 :
break;
default:
V_22 = - V_10 ;
}
break;
default:
V_22 = - V_10 ;
}
* V_53 = V_35 -> V_58 ? V_59 : V_60 ;
return V_22 ;
}
static struct V_32 *
F_29 ( struct V_3 * V_4 , struct V_34 * V_35 , T_1 V_36 ,
T_2 * V_61 )
{
struct V_30 * V_31 = V_4 -> V_62 ;
struct V_32 * V_33 , * V_63 = NULL ;
int V_22 , V_53 ;
unsigned int V_64 ;
void V_40 * V_65 = NULL ;
struct V_66 * V_67 = & V_31 -> V_68 ;
if ( ! V_67 -> V_69 )
return F_7 ( - V_70 ) ;
F_13 ( L_2 , ( unsigned long long ) V_35 -> V_71 ,
V_35 -> V_58 , ( unsigned long long ) V_35 -> V_72 ,
V_35 -> V_73 ) ;
V_22 = F_28 ( V_31 , V_35 , & V_53 ) ;
if ( V_22 )
return F_7 ( V_22 ) ;
V_33 = F_30 ( V_31 , V_53 , V_13 ) ;
if ( ! V_33 )
return F_7 ( - V_14 ) ;
V_22 = F_22 ( V_31 , V_33 , V_35 , V_4 , V_36 ) ;
if ( V_22 )
goto V_12;
if ( V_53 == V_59 && V_35 -> V_73 ) {
if ( ! F_18 ( V_74 , & V_31 -> V_75 ) ) {
V_22 = - V_76 ;
goto V_12;
}
V_63 = F_30 ( V_31 , V_60 , V_13 ) ;
if ( ! V_63 ) {
V_22 = - V_14 ;
goto V_12;
}
V_33 -> V_63 = V_63 ;
V_63 -> V_47 = V_33 -> V_47 ;
V_65 = ( void V_40 * ) ( unsigned long ) V_35 -> V_72 ;
V_22 = F_31 ( V_31 , V_63 , NULL , V_65 ,
V_35 -> V_73 , V_13 ) ;
if ( V_22 )
goto V_12;
}
if ( V_35 -> V_58 ) {
V_64 = V_35 -> V_58 ;
V_65 = ( void V_40 * ) ( unsigned long ) V_35 -> V_71 ;
} else if ( V_35 -> V_73 ) {
V_64 = V_35 -> V_73 ;
V_65 = ( void V_40 * ) ( unsigned long ) V_35 -> V_72 ;
} else
V_64 = 0 ;
if ( V_64 ) {
V_22 = F_31 ( V_31 , V_33 , NULL , V_65 , V_64 ,
V_13 ) ;
if ( V_22 )
goto V_12;
}
V_33 -> V_61 = V_61 ;
V_33 -> V_77 = 0 ;
return V_33 ;
V_12:
if ( V_33 -> V_39 != V_33 -> V_78 )
F_32 ( V_33 -> V_39 ) ;
F_33 ( V_33 ) ;
if ( V_63 ) {
F_34 ( V_63 -> V_79 ) ;
F_33 ( V_63 ) ;
}
return F_7 ( V_22 ) ;
}
static void F_35 ( struct V_32 * V_33 , int V_80 )
{
struct V_1 * V_2 = V_33 -> V_81 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_5 ;
F_13 ( L_3 ,
V_4 -> V_16 , V_33 , V_2 , V_2 -> V_79 , V_80 ) ;
V_2 -> V_35 . V_82 = F_36 ( V_83 - V_2 -> V_35 . V_82 ) ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
F_37 ( & V_2 -> V_15 , & V_4 -> V_84 ) ;
V_4 -> V_23 ++ ;
F_4 ( & V_4 -> V_7 , V_5 ) ;
F_5 ( & V_4 -> V_28 ) ;
}
static void F_38 ( struct V_3 * V_4 , struct V_30 * V_31 ,
struct V_1 * V_2 , struct V_32 * V_33 )
{
int V_85 = ( 0 == ( V_2 -> V_35 . V_5 & V_86 ) ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_79 = V_33 -> V_79 ;
if ( V_33 -> V_63 )
V_2 -> V_87 = V_33 -> V_63 -> V_79 ;
V_2 -> V_35 . V_82 = V_83 ;
F_8 ( & V_4 -> V_7 ) ;
F_39 ( & V_2 -> V_15 , & V_4 -> V_88 ) ;
F_9 ( & V_4 -> V_7 ) ;
F_13 ( L_4 , V_4 -> V_16 , V_33 , V_2 ) ;
V_33 -> V_81 = V_2 ;
F_40 ( V_31 , NULL , V_33 , V_85 , F_35 ) ;
}
static struct V_1 * F_41 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = NULL ;
F_8 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_23 ) {
V_2 = F_42 ( & V_4 -> V_84 , struct V_1 , V_15 ) ;
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
V_2 = F_7 ( - V_89 ) ;
break;
}
} while ( 1 );
F_13 ( L_5 , V_4 -> V_16 , V_2 ) ;
return V_2 ;
}
static int F_46 ( struct V_32 * V_33 , struct V_34 * V_35 ,
struct V_79 * V_79 , struct V_79 * V_87 )
{
int V_22 = 0 ;
F_13 ( L_6 , V_33 , V_79 , V_33 -> V_90 ) ;
V_35 -> V_91 = V_33 -> V_90 & 0xff ;
V_35 -> V_92 = F_47 ( V_33 -> V_90 ) ;
V_35 -> V_93 = F_48 ( V_33 -> V_90 ) ;
V_35 -> V_94 = 0 ;
if ( V_35 -> V_91 || V_35 -> V_92 || V_35 -> V_93 )
V_35 -> V_94 |= V_95 ;
V_35 -> V_96 = 0 ;
if ( V_33 -> V_77 && V_35 -> V_97 ) {
int V_98 = F_49 (unsigned int, hdr->max_response_len,
rq->sense_len) ;
V_22 = F_50 ( ( void V_40 * ) ( unsigned long ) V_35 -> V_97 ,
V_33 -> V_61 , V_98 ) ;
if ( ! V_22 )
V_35 -> V_96 = V_98 ;
else
V_22 = - V_41 ;
}
if ( V_33 -> V_63 ) {
V_35 -> V_99 = V_33 -> V_100 ;
V_35 -> V_101 = V_33 -> V_63 -> V_100 ;
F_34 ( V_87 ) ;
F_33 ( V_33 -> V_63 ) ;
} else if ( F_51 ( V_33 ) == V_60 )
V_35 -> V_101 = V_33 -> V_100 ;
else
V_35 -> V_99 = V_33 -> V_100 ;
if ( ! V_22 && V_33 -> V_90 < 0 )
V_22 = V_33 -> V_90 ;
F_34 ( V_79 ) ;
if ( V_33 -> V_39 != V_33 -> V_78 )
F_32 ( V_33 -> V_39 ) ;
F_33 ( V_33 ) ;
return V_22 ;
}
static int F_52 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_22 , V_102 ;
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
V_102 = F_46 ( V_2 -> V_33 , & V_2 -> V_35 , V_2 -> V_79 ,
V_2 -> V_87 ) ;
if ( ! V_22 )
V_22 = V_102 ;
F_1 ( V_2 ) ;
} while ( 1 );
return V_22 ;
}
static int
F_54 ( char V_40 * V_103 , T_3 V_104 , struct V_3 * V_4 ,
const struct V_105 * V_106 , T_4 * V_107 )
{
struct V_1 * V_2 ;
int V_108 , V_22 ;
if ( V_104 % sizeof( struct V_34 ) )
return - V_10 ;
V_22 = 0 ;
V_108 = V_104 / sizeof( struct V_34 ) ;
while ( V_108 ) {
V_2 = F_44 ( V_4 ) ;
if ( F_53 ( V_2 ) ) {
V_22 = F_55 ( V_2 ) ;
break;
}
V_22 = F_46 ( V_2 -> V_33 , & V_2 -> V_35 , V_2 -> V_79 ,
V_2 -> V_87 ) ;
if ( F_50 ( V_103 , & V_2 -> V_35 , sizeof( V_2 -> V_35 ) ) )
V_22 = - V_41 ;
F_1 ( V_2 ) ;
if ( V_22 )
break;
V_103 += sizeof( struct V_34 ) ;
* V_107 += sizeof( struct V_34 ) ;
V_108 -- ;
}
return V_22 ;
}
static inline void F_56 ( struct V_3 * V_4 , struct V_109 * V_109 )
{
if ( V_109 -> V_110 & V_111 )
F_57 ( V_26 , & V_4 -> V_5 ) ;
else
F_58 ( V_26 , & V_4 -> V_5 ) ;
}
static inline int F_59 ( int V_22 )
{
if ( V_22 && V_22 != - V_112 && V_22 != - V_24 && V_22 != - V_27 )
return 1 ;
return 0 ;
}
static T_4
F_60 ( struct V_109 * V_109 , char V_40 * V_103 , T_3 V_104 , T_5 * V_113 )
{
struct V_3 * V_4 = V_109 -> V_114 ;
int V_22 ;
T_4 V_107 ;
F_13 ( L_8 , V_4 -> V_16 , V_104 ) ;
F_56 ( V_4 , V_109 ) ;
V_107 = 0 ;
V_22 = F_54 ( V_103 , V_104 , V_4 , NULL , & V_107 ) ;
* V_113 = V_107 ;
if ( ! V_107 || F_59 ( V_22 ) )
V_107 = V_22 ;
return V_107 ;
}
static int F_61 ( struct V_3 * V_4 , const char V_40 * V_103 ,
T_3 V_104 , T_4 * V_115 ,
T_1 V_36 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
int V_22 , V_108 ;
if ( V_104 % sizeof( struct V_34 ) )
return - V_10 ;
V_108 = V_104 / sizeof( struct V_34 ) ;
V_33 = NULL ;
V_2 = NULL ;
V_22 = 0 ;
while ( V_108 ) {
struct V_30 * V_31 = V_4 -> V_62 ;
V_2 = F_6 ( V_4 ) ;
if ( F_53 ( V_2 ) ) {
V_22 = F_55 ( V_2 ) ;
V_2 = NULL ;
break;
}
if ( F_24 ( & V_2 -> V_35 , V_103 , sizeof( V_2 -> V_35 ) ) ) {
V_22 = - V_41 ;
break;
}
V_33 = F_29 ( V_4 , & V_2 -> V_35 , V_36 , V_2 -> V_61 ) ;
if ( F_53 ( V_33 ) ) {
V_22 = F_55 ( V_33 ) ;
V_33 = NULL ;
break;
}
F_38 ( V_4 , V_31 , V_2 , V_33 ) ;
V_2 = NULL ;
V_33 = NULL ;
V_108 -- ;
V_103 += sizeof( struct V_34 ) ;
* V_115 += sizeof( struct V_34 ) ;
}
if ( V_2 )
F_1 ( V_2 ) ;
return V_22 ;
}
static T_4
F_62 ( struct V_109 * V_109 , const char V_40 * V_103 , T_3 V_104 , T_5 * V_113 )
{
struct V_3 * V_4 = V_109 -> V_114 ;
T_4 V_115 ;
int V_22 ;
F_13 ( L_9 , V_4 -> V_16 , V_104 ) ;
F_56 ( V_4 , V_109 ) ;
V_115 = 0 ;
V_22 = F_61 ( V_4 , V_103 , V_104 , & V_115 ,
V_109 -> V_116 & V_117 ) ;
* V_113 = V_115 ;
if ( ! V_115 || F_59 ( V_22 ) )
V_115 = V_22 ;
F_13 ( L_10 , V_4 -> V_16 , V_115 ) ;
return V_115 ;
}
static struct V_3 * F_63 ( void )
{
struct V_3 * V_4 ;
V_4 = F_23 ( sizeof( struct V_3 ) , V_13 ) ;
if ( F_11 ( ! V_4 ) )
return NULL ;
F_64 ( & V_4 -> V_7 ) ;
V_4 -> V_11 = V_118 ;
F_12 ( & V_4 -> V_88 ) ;
F_12 ( & V_4 -> V_84 ) ;
F_65 ( & V_4 -> V_119 ) ;
F_66 ( & V_4 -> V_9 ) ;
F_66 ( & V_4 -> V_28 ) ;
return V_4 ;
}
static void F_67 ( struct V_120 * V_120 )
{
struct V_66 * V_67 =
F_68 ( V_120 , struct V_66 , V_121 ) ;
struct V_122 * V_123 = V_67 -> V_123 ;
if ( V_67 -> V_124 )
V_67 -> V_124 ( V_67 -> V_123 ) ;
F_69 ( V_123 ) ;
}
static int F_70 ( struct V_3 * V_4 )
{
int V_22 = 0 , V_125 ;
struct V_30 * V_31 = V_4 -> V_62 ;
F_71 ( & V_126 ) ;
V_125 = F_72 ( & V_4 -> V_127 ) ;
if ( ! V_125 ) {
F_73 ( & V_126 ) ;
goto V_12;
}
F_74 ( & V_4 -> V_119 ) ;
F_73 ( & V_126 ) ;
F_13 ( L_11 , V_4 -> V_16 ) ;
F_58 ( V_26 , & V_4 -> V_5 ) ;
V_22 = F_52 ( V_4 ) ;
F_32 ( V_4 ) ;
V_12:
F_75 ( & V_31 -> V_68 . V_121 , F_67 ) ;
if ( V_125 )
F_76 ( V_31 ) ;
return V_22 ;
}
static struct V_3 * F_77 ( struct V_128 * V_128 ,
struct V_30 * V_33 ,
struct V_109 * V_109 )
{
struct V_3 * V_4 ;
#ifdef F_78
unsigned char V_103 [ 32 ] ;
#endif
if ( ! F_79 ( V_33 ) )
return F_7 ( - V_70 ) ;
V_4 = F_63 () ;
if ( ! V_4 ) {
F_76 ( V_33 ) ;
return F_7 ( - V_14 ) ;
}
V_4 -> V_62 = V_33 ;
F_56 ( V_4 , V_109 ) ;
F_80 ( & V_4 -> V_127 , 1 ) ;
F_71 ( & V_126 ) ;
F_81 ( & V_4 -> V_119 , F_14 ( F_82 ( V_128 ) ) ) ;
strncpy ( V_4 -> V_16 , F_83 ( V_33 -> V_68 . V_69 ) , sizeof( V_4 -> V_16 ) - 1 ) ;
F_13 ( L_12 ,
F_84 ( V_103 , V_128 -> V_129 ) , V_4 -> V_11 ) ;
F_73 ( & V_126 ) ;
return V_4 ;
}
static struct V_3 * F_85 ( int V_130 , struct V_30 * V_31 )
{
struct V_3 * V_4 ;
F_71 ( & V_126 ) ;
F_86 (bd, bsg_dev_idx_hash(minor), dev_list) {
if ( V_4 -> V_62 == V_31 ) {
F_87 ( & V_4 -> V_127 ) ;
goto V_131;
}
}
V_4 = NULL ;
V_131:
F_73 ( & V_126 ) ;
return V_4 ;
}
static struct V_3 * F_88 ( struct V_128 * V_128 , struct V_109 * V_109 )
{
struct V_3 * V_4 ;
struct V_66 * V_67 ;
F_71 ( & V_126 ) ;
V_67 = F_89 ( & V_132 , F_82 ( V_128 ) ) ;
if ( V_67 )
F_90 ( & V_67 -> V_121 ) ;
F_73 ( & V_126 ) ;
if ( ! V_67 )
return F_7 ( - V_133 ) ;
V_4 = F_85 ( F_82 ( V_128 ) , V_67 -> V_62 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_77 ( V_128 , V_67 -> V_62 , V_109 ) ;
if ( F_53 ( V_4 ) )
F_75 ( & V_67 -> V_121 , F_67 ) ;
return V_4 ;
}
static int F_91 ( struct V_128 * V_128 , struct V_109 * V_109 )
{
struct V_3 * V_4 ;
V_4 = F_88 ( V_128 , V_109 ) ;
if ( F_53 ( V_4 ) )
return F_55 ( V_4 ) ;
V_109 -> V_114 = V_4 ;
return 0 ;
}
static int F_92 ( struct V_128 * V_128 , struct V_109 * V_109 )
{
struct V_3 * V_4 = V_109 -> V_114 ;
V_109 -> V_114 = NULL ;
return F_70 ( V_4 ) ;
}
static unsigned int F_93 ( struct V_109 * V_109 , T_6 * V_21 )
{
struct V_3 * V_4 = V_109 -> V_114 ;
unsigned int V_134 = 0 ;
F_94 ( V_109 , & V_4 -> V_28 , V_21 ) ;
F_94 ( V_109 , & V_4 -> V_9 , V_21 ) ;
F_8 ( & V_4 -> V_7 ) ;
if ( ! F_95 ( & V_4 -> V_84 ) )
V_134 |= V_135 | V_136 ;
if ( V_4 -> V_8 < V_4 -> V_11 )
V_134 |= V_137 ;
F_9 ( & V_4 -> V_7 ) ;
return V_134 ;
}
static long F_96 ( struct V_109 * V_109 , unsigned int V_39 , unsigned long V_138 )
{
struct V_3 * V_4 = V_109 -> V_114 ;
int V_40 * V_139 = ( int V_40 * ) V_138 ;
int V_22 ;
switch ( V_39 ) {
case V_140 :
return F_97 ( V_4 -> V_11 , V_139 ) ;
case V_141 : {
int V_62 ;
if ( F_98 ( V_62 , V_139 ) )
return - V_41 ;
if ( V_62 < 1 )
return - V_10 ;
F_8 ( & V_4 -> V_7 ) ;
V_4 -> V_11 = V_62 ;
F_9 ( & V_4 -> V_7 ) ;
return 0 ;
}
case V_142 :
case V_143 :
case V_144 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 : {
void V_40 * V_139 = ( void V_40 * ) V_138 ;
return F_99 ( V_4 -> V_62 , NULL , V_109 -> V_116 , V_39 , V_139 ) ;
}
case V_151 : {
struct V_32 * V_33 ;
struct V_79 * V_79 , * V_87 = NULL ;
struct V_34 V_35 ;
int V_85 ;
T_2 V_61 [ V_152 ] ;
if ( F_24 ( & V_35 , V_139 , sizeof( V_35 ) ) )
return - V_41 ;
V_33 = F_29 ( V_4 , & V_35 , V_109 -> V_116 & V_117 , V_61 ) ;
if ( F_53 ( V_33 ) )
return F_55 ( V_33 ) ;
V_79 = V_33 -> V_79 ;
if ( V_33 -> V_63 )
V_87 = V_33 -> V_63 -> V_79 ;
V_85 = ( 0 == ( V_35 . V_5 & V_86 ) ) ;
F_100 ( V_4 -> V_62 , NULL , V_33 , V_85 ) ;
V_22 = F_46 ( V_33 , & V_35 , V_79 , V_87 ) ;
if ( F_50 ( V_139 , & V_35 , sizeof( V_35 ) ) )
return - V_41 ;
return V_22 ;
}
default:
#if 0
return ioctl_by_bdev(bd->bdev, cmd, arg);
#else
return - V_153 ;
#endif
}
}
void F_101 ( struct V_30 * V_31 )
{
struct V_66 * V_67 = & V_31 -> V_68 ;
if ( ! V_67 -> V_69 )
return;
F_71 ( & V_126 ) ;
F_102 ( & V_132 , V_67 -> V_130 ) ;
if ( V_31 -> V_154 . V_155 )
F_103 ( & V_31 -> V_154 , L_13 ) ;
F_104 ( V_67 -> V_69 ) ;
V_67 -> V_69 = NULL ;
F_75 ( & V_67 -> V_121 , F_67 ) ;
F_73 ( & V_126 ) ;
}
int F_105 ( struct V_30 * V_31 , struct V_122 * V_123 ,
const char * V_16 , void (* V_124)( struct V_122 * ) )
{
struct V_66 * V_67 ;
T_7 V_156 ;
int V_22 ;
struct V_122 * V_69 = NULL ;
const char * V_157 ;
if ( V_16 )
V_157 = V_16 ;
else
V_157 = F_83 ( V_123 ) ;
if ( ! V_31 -> V_158 )
return 0 ;
V_67 = & V_31 -> V_68 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
F_71 ( & V_126 ) ;
V_22 = F_106 ( & V_132 , V_67 , 0 , V_159 , V_13 ) ;
if ( V_22 < 0 ) {
if ( V_22 == - V_112 ) {
F_107 ( V_160 L_14 ) ;
V_22 = - V_10 ;
}
goto V_25;
}
V_67 -> V_130 = V_22 ;
V_67 -> V_62 = V_31 ;
V_67 -> V_123 = F_108 ( V_123 ) ;
V_67 -> V_124 = V_124 ;
F_109 ( & V_67 -> V_121 ) ;
V_156 = F_110 ( V_161 , V_67 -> V_130 ) ;
V_69 = F_111 ( V_162 , V_123 , V_156 , NULL , L_15 , V_157 ) ;
if ( F_53 ( V_69 ) ) {
V_22 = F_55 ( V_69 ) ;
goto V_163;
}
V_67 -> V_69 = V_69 ;
if ( V_31 -> V_154 . V_155 ) {
V_22 = F_112 ( & V_31 -> V_154 , & V_67 -> V_69 -> V_154 , L_13 ) ;
if ( V_22 )
goto V_164;
}
F_73 ( & V_126 ) ;
return 0 ;
V_164:
F_104 ( V_69 ) ;
V_163:
F_69 ( V_123 ) ;
F_102 ( & V_132 , V_67 -> V_130 ) ;
V_25:
F_73 ( & V_126 ) ;
return V_22 ;
}
static char * F_113 ( struct V_122 * V_156 , T_8 * V_165 )
{
return F_114 ( V_13 , L_16 , F_83 ( V_156 ) ) ;
}
static int T_9 F_115 ( void )
{
int V_22 , V_166 ;
T_7 V_167 ;
V_6 = F_116 ( L_17 ,
sizeof( struct V_1 ) , 0 , 0 , NULL ) ;
if ( ! V_6 ) {
F_107 ( V_160 L_18 ) ;
return - V_14 ;
}
for ( V_166 = 0 ; V_166 < V_20 ; V_166 ++ )
F_117 ( & V_19 [ V_166 ] ) ;
V_162 = F_118 ( V_168 , L_13 ) ;
if ( F_53 ( V_162 ) ) {
V_22 = F_55 ( V_162 ) ;
goto V_169;
}
V_162 -> V_170 = F_113 ;
V_22 = F_119 ( & V_167 , 0 , V_159 , L_13 ) ;
if ( V_22 )
goto V_171;
V_161 = F_120 ( V_167 ) ;
F_121 ( & V_172 , & V_173 ) ;
V_22 = F_122 ( & V_172 , F_110 ( V_161 , 0 ) , V_159 ) ;
if ( V_22 )
goto V_174;
F_107 (KERN_INFO BSG_DESCRIPTION L_19 BSG_VERSION
L_20 , bsg_major) ;
return 0 ;
V_174:
F_123 ( F_110 ( V_161 , 0 ) , V_159 ) ;
V_171:
F_124 ( V_162 ) ;
V_169:
F_125 ( V_6 ) ;
return V_22 ;
}
