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
struct V_28 * V_29 = F_16 ( V_24 ) ;
if ( V_26 -> V_30 > V_31 ) {
V_29 -> V_32 = F_17 ( V_26 -> V_30 , V_13 ) ;
if ( ! V_29 -> V_32 )
return - V_14 ;
}
if ( F_18 ( V_29 -> V_32 , ( void V_33 * ) ( unsigned long ) V_26 -> V_23 ,
V_26 -> V_30 ) )
return - V_34 ;
if ( V_26 -> V_35 == V_36 ) {
if ( F_19 ( V_29 -> V_32 , V_27 ) )
return - V_37 ;
} else if ( ! F_20 ( V_38 ) )
return - V_37 ;
V_29 -> V_39 = V_26 -> V_30 ;
V_24 -> V_40 = F_21 ( V_26 -> V_40 ) ;
if ( ! V_24 -> V_40 )
V_24 -> V_40 = V_22 -> V_41 ;
if ( ! V_24 -> V_40 )
V_24 -> V_40 = V_42 ;
if ( V_24 -> V_40 < V_43 )
V_24 -> V_40 = V_43 ;
return 0 ;
}
static int
F_22 ( struct V_25 * V_26 , int * V_44 )
{
int V_45 = 0 ;
if ( V_26 -> V_46 != 'Q' )
return - V_10 ;
switch ( V_26 -> V_47 ) {
case V_48 :
switch ( V_26 -> V_35 ) {
case V_36 :
case V_49 :
break;
default:
V_45 = - V_10 ;
}
break;
default:
V_45 = - V_10 ;
}
* V_44 = V_26 -> V_50 ? V_51 : V_52 ;
return V_45 ;
}
static struct V_23 *
F_23 ( struct V_3 * V_4 , struct V_25 * V_26 , T_1 V_27 )
{
struct V_21 * V_22 = V_4 -> V_53 ;
struct V_23 * V_24 , * V_54 = NULL ;
int V_45 ;
unsigned int V_44 , V_55 ;
void V_33 * V_56 = NULL ;
struct V_57 * V_58 = & V_22 -> V_59 ;
if ( ! V_58 -> V_60 )
return F_7 ( - V_61 ) ;
F_13 ( L_2 , ( unsigned long long ) V_26 -> V_62 ,
V_26 -> V_50 , ( unsigned long long ) V_26 -> V_63 ,
V_26 -> V_64 ) ;
V_45 = F_22 ( V_26 , & V_44 ) ;
if ( V_45 )
return F_7 ( V_45 ) ;
V_24 = F_24 ( V_22 , V_44 , V_13 ) ;
if ( F_25 ( V_24 ) )
return V_24 ;
F_26 ( V_24 ) ;
V_45 = F_15 ( V_22 , V_24 , V_26 , V_4 , V_27 ) ;
if ( V_45 )
goto V_12;
if ( V_44 == V_51 && V_26 -> V_64 ) {
if ( ! F_27 ( V_65 , & V_22 -> V_66 ) ) {
V_45 = - V_67 ;
goto V_12;
}
V_54 = F_24 ( V_22 , V_52 , V_13 ) ;
if ( F_25 ( V_54 ) ) {
V_45 = F_28 ( V_54 ) ;
V_54 = NULL ;
goto V_12;
}
V_24 -> V_54 = V_54 ;
V_56 = ( void V_33 * ) ( unsigned long ) V_26 -> V_63 ;
V_45 = F_29 ( V_22 , V_54 , NULL , V_56 ,
V_26 -> V_64 , V_13 ) ;
if ( V_45 )
goto V_12;
}
if ( V_26 -> V_50 ) {
V_55 = V_26 -> V_50 ;
V_56 = ( void V_33 * ) ( unsigned long ) V_26 -> V_62 ;
} else if ( V_26 -> V_64 ) {
V_55 = V_26 -> V_64 ;
V_56 = ( void V_33 * ) ( unsigned long ) V_26 -> V_63 ;
} else
V_55 = 0 ;
if ( V_55 ) {
V_45 = F_29 ( V_22 , V_24 , NULL , V_56 , V_55 ,
V_13 ) ;
if ( V_45 )
goto V_12;
}
return V_24 ;
V_12:
F_30 ( F_16 ( V_24 ) ) ;
F_31 ( V_24 ) ;
if ( V_54 ) {
F_32 ( V_54 -> V_68 ) ;
F_31 ( V_54 ) ;
}
return F_7 ( V_45 ) ;
}
static void F_33 ( struct V_23 * V_24 , int V_69 )
{
struct V_1 * V_2 = V_24 -> V_70 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_5 ;
F_13 ( L_3 ,
V_4 -> V_16 , V_24 , V_2 , V_2 -> V_68 , V_69 ) ;
V_2 -> V_26 . V_71 = F_34 ( V_72 - V_2 -> V_26 . V_71 ) ;
F_3 ( & V_4 -> V_7 , V_5 ) ;
F_35 ( & V_2 -> V_15 , & V_4 -> V_73 ) ;
V_4 -> V_74 ++ ;
F_4 ( & V_4 -> V_7 , V_5 ) ;
F_5 ( & V_4 -> V_75 ) ;
}
static void F_36 ( struct V_3 * V_4 , struct V_21 * V_22 ,
struct V_1 * V_2 , struct V_23 * V_24 )
{
int V_76 = ( 0 == ( V_2 -> V_26 . V_5 & V_77 ) ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_68 = V_24 -> V_68 ;
if ( V_24 -> V_54 )
V_2 -> V_78 = V_24 -> V_54 -> V_68 ;
V_2 -> V_26 . V_71 = V_72 ;
F_8 ( & V_4 -> V_7 ) ;
F_37 ( & V_2 -> V_15 , & V_4 -> V_79 ) ;
F_9 ( & V_4 -> V_7 ) ;
F_13 ( L_4 , V_4 -> V_16 , V_24 , V_2 ) ;
V_24 -> V_70 = V_2 ;
F_38 ( V_22 , NULL , V_24 , V_76 , F_33 ) ;
}
static struct V_1 * F_39 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = NULL ;
F_8 ( & V_4 -> V_7 ) ;
if ( V_4 -> V_74 ) {
V_2 = F_40 ( & V_4 -> V_73 , struct V_1 , V_15 ) ;
F_41 ( & V_2 -> V_15 ) ;
V_4 -> V_74 -- ;
}
F_9 ( & V_4 -> V_7 ) ;
return V_2 ;
}
static struct V_1 * F_42 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_45 ;
do {
V_2 = F_39 ( V_4 ) ;
if ( V_2 )
break;
if ( ! F_27 ( V_80 , & V_4 -> V_5 ) ) {
V_2 = F_7 ( - V_81 ) ;
break;
}
V_45 = F_43 ( V_4 -> V_75 , V_4 -> V_74 ) ;
if ( V_45 ) {
V_2 = F_7 ( - V_82 ) ;
break;
}
} while ( 1 );
F_13 ( L_5 , V_4 -> V_16 , V_2 ) ;
return V_2 ;
}
static int F_44 ( struct V_23 * V_24 , struct V_25 * V_26 ,
struct V_68 * V_68 , struct V_68 * V_78 )
{
struct V_28 * V_29 = F_16 ( V_24 ) ;
int V_45 = 0 ;
F_13 ( L_6 , V_24 , V_68 , V_24 -> V_83 ) ;
V_26 -> V_84 = V_24 -> V_83 & 0xff ;
V_26 -> V_85 = F_45 ( V_24 -> V_83 ) ;
V_26 -> V_86 = F_46 ( V_24 -> V_83 ) ;
V_26 -> V_87 = 0 ;
if ( V_26 -> V_84 || V_26 -> V_85 || V_26 -> V_86 )
V_26 -> V_87 |= V_88 ;
V_26 -> V_89 = 0 ;
if ( V_29 -> V_90 && V_26 -> V_91 ) {
int V_92 = F_47 (unsigned int, hdr->max_response_len,
req->sense_len) ;
V_45 = F_48 ( ( void V_33 * ) ( unsigned long ) V_26 -> V_91 ,
V_29 -> V_93 , V_92 ) ;
if ( ! V_45 )
V_26 -> V_89 = V_92 ;
else
V_45 = - V_34 ;
}
if ( V_24 -> V_54 ) {
V_26 -> V_94 = V_29 -> V_95 ;
V_26 -> V_96 = F_16 ( V_24 -> V_54 ) -> V_95 ;
F_32 ( V_78 ) ;
F_31 ( V_24 -> V_54 ) ;
} else if ( F_49 ( V_24 ) == V_97 )
V_26 -> V_96 = V_29 -> V_95 ;
else
V_26 -> V_94 = V_29 -> V_95 ;
if ( ! V_45 && V_24 -> V_83 < 0 )
V_45 = V_24 -> V_83 ;
F_32 ( V_68 ) ;
F_30 ( V_29 ) ;
F_31 ( V_24 ) ;
return V_45 ;
}
static bool F_50 ( struct V_3 * V_4 )
{
bool V_45 = false ;
bool V_98 ;
do {
F_8 ( & V_4 -> V_7 ) ;
F_51 ( V_4 -> V_74 > V_4 -> V_8 ) ;
if ( V_4 -> V_74 == V_4 -> V_8 )
V_45 = true ;
V_98 = ! F_27 ( V_80 , & V_4 -> V_5 ) ;
F_9 ( & V_4 -> V_7 ) ;
} while ( ! V_45 && V_98 );
return V_45 ;
}
static int F_52 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_45 , V_99 ;
F_13 ( L_7 , V_4 -> V_16 ) ;
F_53 ( V_4 -> V_75 , F_50 ( V_4 ) ) ;
V_45 = 0 ;
do {
F_8 ( & V_4 -> V_7 ) ;
if ( ! V_4 -> V_8 ) {
F_9 ( & V_4 -> V_7 ) ;
break;
}
F_9 ( & V_4 -> V_7 ) ;
V_2 = F_42 ( V_4 ) ;
if ( F_25 ( V_2 ) )
break;
V_99 = F_44 ( V_2 -> V_24 , & V_2 -> V_26 , V_2 -> V_68 ,
V_2 -> V_78 ) ;
if ( ! V_45 )
V_45 = V_99 ;
F_1 ( V_2 ) ;
} while ( 1 );
return V_45 ;
}
static int
F_54 ( char V_33 * V_100 , T_2 V_101 , struct V_3 * V_4 ,
const struct V_102 * V_103 , T_3 * V_104 )
{
struct V_1 * V_2 ;
int V_105 , V_45 ;
if ( V_101 % sizeof( struct V_25 ) )
return - V_10 ;
V_45 = 0 ;
V_105 = V_101 / sizeof( struct V_25 ) ;
while ( V_105 ) {
V_2 = F_42 ( V_4 ) ;
if ( F_25 ( V_2 ) ) {
V_45 = F_28 ( V_2 ) ;
break;
}
V_45 = F_44 ( V_2 -> V_24 , & V_2 -> V_26 , V_2 -> V_68 ,
V_2 -> V_78 ) ;
if ( F_48 ( V_100 , & V_2 -> V_26 , sizeof( V_2 -> V_26 ) ) )
V_45 = - V_34 ;
F_1 ( V_2 ) ;
if ( V_45 )
break;
V_100 += sizeof( struct V_25 ) ;
* V_104 += sizeof( struct V_25 ) ;
V_105 -- ;
}
return V_45 ;
}
static inline void F_55 ( struct V_3 * V_4 , struct V_106 * V_106 )
{
if ( V_106 -> V_107 & V_108 )
F_56 ( V_80 , & V_4 -> V_5 ) ;
else
F_57 ( V_80 , & V_4 -> V_5 ) ;
}
static inline int F_58 ( int V_45 )
{
if ( V_45 && V_45 != - V_109 && V_45 != - V_110 && V_45 != - V_81 )
return 1 ;
return 0 ;
}
static T_3
F_59 ( struct V_106 * V_106 , char V_33 * V_100 , T_2 V_101 , T_4 * V_111 )
{
struct V_3 * V_4 = V_106 -> V_112 ;
int V_45 ;
T_3 V_104 ;
F_13 ( L_8 , V_4 -> V_16 , V_101 ) ;
F_55 ( V_4 , V_106 ) ;
V_104 = 0 ;
V_45 = F_54 ( V_100 , V_101 , V_4 , NULL , & V_104 ) ;
* V_111 = V_104 ;
if ( ! V_104 || F_58 ( V_45 ) )
V_104 = V_45 ;
return V_104 ;
}
static int F_60 ( struct V_3 * V_4 , const char V_33 * V_100 ,
T_2 V_101 , T_3 * V_113 ,
T_1 V_27 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_45 , V_105 ;
if ( V_101 % sizeof( struct V_25 ) )
return - V_10 ;
V_105 = V_101 / sizeof( struct V_25 ) ;
V_24 = NULL ;
V_2 = NULL ;
V_45 = 0 ;
while ( V_105 ) {
struct V_21 * V_22 = V_4 -> V_53 ;
V_2 = F_6 ( V_4 ) ;
if ( F_25 ( V_2 ) ) {
V_45 = F_28 ( V_2 ) ;
V_2 = NULL ;
break;
}
if ( F_18 ( & V_2 -> V_26 , V_100 , sizeof( V_2 -> V_26 ) ) ) {
V_45 = - V_34 ;
break;
}
V_24 = F_23 ( V_4 , & V_2 -> V_26 , V_27 ) ;
if ( F_25 ( V_24 ) ) {
V_45 = F_28 ( V_24 ) ;
V_24 = NULL ;
break;
}
F_36 ( V_4 , V_22 , V_2 , V_24 ) ;
V_2 = NULL ;
V_24 = NULL ;
V_105 -- ;
V_100 += sizeof( struct V_25 ) ;
* V_113 += sizeof( struct V_25 ) ;
}
if ( V_2 )
F_1 ( V_2 ) ;
return V_45 ;
}
static T_3
F_61 ( struct V_106 * V_106 , const char V_33 * V_100 , T_2 V_101 , T_4 * V_111 )
{
struct V_3 * V_4 = V_106 -> V_112 ;
T_3 V_113 ;
int V_45 ;
F_13 ( L_9 , V_4 -> V_16 , V_101 ) ;
if ( F_11 ( F_62 ( F_63 () , V_114 ) ) )
return - V_10 ;
F_55 ( V_4 , V_106 ) ;
V_113 = 0 ;
V_45 = F_60 ( V_4 , V_100 , V_101 , & V_113 ,
V_106 -> V_115 & V_116 ) ;
* V_111 = V_113 ;
if ( ! V_113 || F_58 ( V_45 ) )
V_113 = V_45 ;
F_13 ( L_10 , V_4 -> V_16 , V_113 ) ;
return V_113 ;
}
static struct V_3 * F_64 ( void )
{
struct V_3 * V_4 ;
V_4 = F_17 ( sizeof( struct V_3 ) , V_13 ) ;
if ( F_11 ( ! V_4 ) )
return NULL ;
F_65 ( & V_4 -> V_7 ) ;
V_4 -> V_11 = V_117 ;
F_12 ( & V_4 -> V_79 ) ;
F_12 ( & V_4 -> V_73 ) ;
F_66 ( & V_4 -> V_118 ) ;
F_67 ( & V_4 -> V_9 ) ;
F_67 ( & V_4 -> V_75 ) ;
return V_4 ;
}
static void F_68 ( struct V_119 * V_119 )
{
struct V_57 * V_58 =
F_69 ( V_119 , struct V_57 , V_120 ) ;
struct V_121 * V_122 = V_58 -> V_122 ;
if ( V_58 -> V_123 )
V_58 -> V_123 ( V_58 -> V_122 ) ;
F_70 ( V_122 ) ;
}
static int F_71 ( struct V_3 * V_4 )
{
int V_45 = 0 , V_124 ;
struct V_21 * V_22 = V_4 -> V_53 ;
F_72 ( & V_125 ) ;
V_124 = F_73 ( & V_4 -> V_126 ) ;
if ( ! V_124 ) {
F_74 ( & V_125 ) ;
goto V_12;
}
F_75 ( & V_4 -> V_118 ) ;
F_74 ( & V_125 ) ;
F_13 ( L_11 , V_4 -> V_16 ) ;
F_57 ( V_80 , & V_4 -> V_5 ) ;
V_45 = F_52 ( V_4 ) ;
F_76 ( V_4 ) ;
V_12:
F_77 ( & V_22 -> V_59 . V_120 , F_68 ) ;
if ( V_124 )
F_78 ( V_22 ) ;
return V_45 ;
}
static struct V_3 * F_79 ( struct V_127 * V_127 ,
struct V_21 * V_24 ,
struct V_106 * V_106 )
{
struct V_3 * V_4 ;
#ifdef F_80
unsigned char V_100 [ 32 ] ;
#endif
if ( ! F_81 ( V_24 ) )
return F_7 ( - V_61 ) ;
V_4 = F_64 () ;
if ( ! V_4 ) {
F_78 ( V_24 ) ;
return F_7 ( - V_14 ) ;
}
V_4 -> V_53 = V_24 ;
F_55 ( V_4 , V_106 ) ;
F_82 ( & V_4 -> V_126 , 1 ) ;
F_72 ( & V_125 ) ;
F_83 ( & V_4 -> V_118 , F_14 ( F_84 ( V_127 ) ) ) ;
strncpy ( V_4 -> V_16 , F_85 ( V_24 -> V_59 . V_60 ) , sizeof( V_4 -> V_16 ) - 1 ) ;
F_13 ( L_12 ,
F_86 ( V_100 , V_127 -> V_128 ) , V_4 -> V_11 ) ;
F_74 ( & V_125 ) ;
return V_4 ;
}
static struct V_3 * F_87 ( int V_129 , struct V_21 * V_22 )
{
struct V_3 * V_4 ;
F_72 ( & V_125 ) ;
F_88 (bd, bsg_dev_idx_hash(minor), dev_list) {
if ( V_4 -> V_53 == V_22 ) {
F_89 ( & V_4 -> V_126 ) ;
goto V_130;
}
}
V_4 = NULL ;
V_130:
F_74 ( & V_125 ) ;
return V_4 ;
}
static struct V_3 * F_90 ( struct V_127 * V_127 , struct V_106 * V_106 )
{
struct V_3 * V_4 ;
struct V_57 * V_58 ;
F_72 ( & V_125 ) ;
V_58 = F_91 ( & V_131 , F_84 ( V_127 ) ) ;
if ( V_58 )
F_92 ( & V_58 -> V_120 ) ;
F_74 ( & V_125 ) ;
if ( ! V_58 )
return F_7 ( - V_132 ) ;
V_4 = F_87 ( F_84 ( V_127 ) , V_58 -> V_53 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_79 ( V_127 , V_58 -> V_53 , V_106 ) ;
if ( F_25 ( V_4 ) )
F_77 ( & V_58 -> V_120 , F_68 ) ;
return V_4 ;
}
static int F_93 ( struct V_127 * V_127 , struct V_106 * V_106 )
{
struct V_3 * V_4 ;
V_4 = F_90 ( V_127 , V_106 ) ;
if ( F_25 ( V_4 ) )
return F_28 ( V_4 ) ;
V_106 -> V_112 = V_4 ;
return 0 ;
}
static int F_94 ( struct V_127 * V_127 , struct V_106 * V_106 )
{
struct V_3 * V_4 = V_106 -> V_112 ;
V_106 -> V_112 = NULL ;
return F_71 ( V_4 ) ;
}
static unsigned int F_95 ( struct V_106 * V_106 , T_5 * V_133 )
{
struct V_3 * V_4 = V_106 -> V_112 ;
unsigned int V_134 = 0 ;
F_96 ( V_106 , & V_4 -> V_75 , V_133 ) ;
F_96 ( V_106 , & V_4 -> V_9 , V_133 ) ;
F_8 ( & V_4 -> V_7 ) ;
if ( ! F_97 ( & V_4 -> V_73 ) )
V_134 |= V_135 | V_136 ;
if ( V_4 -> V_8 < V_4 -> V_11 )
V_134 |= V_137 ;
F_9 ( & V_4 -> V_7 ) ;
return V_134 ;
}
static long F_98 ( struct V_106 * V_106 , unsigned int V_32 , unsigned long V_138 )
{
struct V_3 * V_4 = V_106 -> V_112 ;
int V_33 * V_139 = ( int V_33 * ) V_138 ;
int V_45 ;
switch ( V_32 ) {
case V_140 :
return F_99 ( V_4 -> V_11 , V_139 ) ;
case V_141 : {
int V_53 ;
if ( F_100 ( V_53 , V_139 ) )
return - V_34 ;
if ( V_53 < 1 )
return - V_10 ;
F_8 ( & V_4 -> V_7 ) ;
V_4 -> V_11 = V_53 ;
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
void V_33 * V_139 = ( void V_33 * ) V_138 ;
return F_101 ( V_4 -> V_53 , NULL , V_106 -> V_115 , V_32 , V_139 ) ;
}
case V_151 : {
struct V_23 * V_24 ;
struct V_68 * V_68 , * V_78 = NULL ;
struct V_25 V_26 ;
int V_76 ;
if ( F_18 ( & V_26 , V_139 , sizeof( V_26 ) ) )
return - V_34 ;
V_24 = F_23 ( V_4 , & V_26 , V_106 -> V_115 & V_116 ) ;
if ( F_25 ( V_24 ) )
return F_28 ( V_24 ) ;
V_68 = V_24 -> V_68 ;
if ( V_24 -> V_54 )
V_78 = V_24 -> V_54 -> V_68 ;
V_76 = ( 0 == ( V_26 . V_5 & V_77 ) ) ;
F_102 ( V_4 -> V_53 , NULL , V_24 , V_76 ) ;
V_45 = F_44 ( V_24 , & V_26 , V_68 , V_78 ) ;
if ( F_48 ( V_139 , & V_26 , sizeof( V_26 ) ) )
return - V_34 ;
return V_45 ;
}
default:
#if 0
return ioctl_by_bdev(bd->bdev, cmd, arg);
#else
return - V_152 ;
#endif
}
}
void F_103 ( struct V_21 * V_22 )
{
struct V_57 * V_58 = & V_22 -> V_59 ;
if ( ! V_58 -> V_60 )
return;
F_72 ( & V_125 ) ;
F_104 ( & V_131 , V_58 -> V_129 ) ;
if ( V_22 -> V_153 . V_154 )
F_105 ( & V_22 -> V_153 , L_13 ) ;
F_106 ( V_58 -> V_60 ) ;
V_58 -> V_60 = NULL ;
F_77 ( & V_58 -> V_120 , F_68 ) ;
F_74 ( & V_125 ) ;
}
int F_107 ( struct V_21 * V_22 , struct V_121 * V_122 ,
const char * V_16 , void (* V_123)( struct V_121 * ) )
{
struct V_57 * V_58 ;
T_6 V_155 ;
int V_45 ;
struct V_121 * V_60 = NULL ;
const char * V_156 ;
if ( V_16 )
V_156 = V_16 ;
else
V_156 = F_85 ( V_122 ) ;
if ( ! F_108 ( V_22 ) )
return 0 ;
V_58 = & V_22 -> V_59 ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
F_72 ( & V_125 ) ;
V_45 = F_109 ( & V_131 , V_58 , 0 , V_157 , V_13 ) ;
if ( V_45 < 0 ) {
if ( V_45 == - V_109 ) {
F_110 ( V_158 L_14 ) ;
V_45 = - V_10 ;
}
goto V_159;
}
V_58 -> V_129 = V_45 ;
V_58 -> V_53 = V_22 ;
V_58 -> V_122 = F_111 ( V_122 ) ;
V_58 -> V_123 = V_123 ;
F_112 ( & V_58 -> V_120 ) ;
V_155 = F_113 ( V_160 , V_58 -> V_129 ) ;
V_60 = F_114 ( V_161 , V_122 , V_155 , NULL , L_15 , V_156 ) ;
if ( F_25 ( V_60 ) ) {
V_45 = F_28 ( V_60 ) ;
goto V_162;
}
V_58 -> V_60 = V_60 ;
if ( V_22 -> V_153 . V_154 ) {
V_45 = F_115 ( & V_22 -> V_153 , & V_58 -> V_60 -> V_153 , L_13 ) ;
if ( V_45 )
goto V_163;
}
F_74 ( & V_125 ) ;
return 0 ;
V_163:
F_106 ( V_60 ) ;
V_162:
F_70 ( V_122 ) ;
F_104 ( & V_131 , V_58 -> V_129 ) ;
V_159:
F_74 ( & V_125 ) ;
return V_45 ;
}
static char * F_116 ( struct V_121 * V_155 , T_7 * V_164 )
{
return F_117 ( V_13 , L_16 , F_85 ( V_155 ) ) ;
}
static int T_8 F_118 ( void )
{
int V_45 , V_165 ;
T_6 V_166 ;
V_6 = F_119 ( L_17 ,
sizeof( struct V_1 ) , 0 , 0 , NULL ) ;
if ( ! V_6 ) {
F_110 ( V_158 L_18 ) ;
return - V_14 ;
}
for ( V_165 = 0 ; V_165 < V_20 ; V_165 ++ )
F_120 ( & V_19 [ V_165 ] ) ;
V_161 = F_121 ( V_167 , L_13 ) ;
if ( F_25 ( V_161 ) ) {
V_45 = F_28 ( V_161 ) ;
goto V_168;
}
V_161 -> V_169 = F_116 ;
V_45 = F_122 ( & V_166 , 0 , V_157 , L_13 ) ;
if ( V_45 )
goto V_170;
V_160 = F_123 ( V_166 ) ;
F_124 ( & V_171 , & V_172 ) ;
V_45 = F_125 ( & V_171 , F_113 ( V_160 , 0 ) , V_157 ) ;
if ( V_45 )
goto V_173;
F_110 (KERN_INFO BSG_DESCRIPTION L_19 BSG_VERSION
L_20 , bsg_major) ;
return 0 ;
V_173:
F_126 ( F_113 ( V_160 , 0 ) , V_157 ) ;
V_170:
F_127 ( V_161 ) ;
V_168:
F_128 ( V_6 ) ;
return V_45 ;
}
