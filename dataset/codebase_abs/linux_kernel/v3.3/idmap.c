void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * V_5 )
{
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
}
static void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_6 &= ~ V_7 ;
F_3 ( V_2 -> V_4 -> V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_6 &= ~ V_9 ;
F_3 ( V_2 -> V_5 -> V_8 ) ;
}
static bool F_5 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
struct V_3 * V_12 = V_2 -> V_4 ;
T_1 V_13 ;
if ( ! ( V_2 -> V_6 & V_7 ) )
return false ;
if ( F_6 ( V_11 , V_12 -> V_8 , V_12 -> V_14 , & V_13 ) == 0 ) {
V_2 -> V_13 = V_13 ;
V_2 -> V_6 |= V_15 ;
}
return true ;
}
static bool F_7 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
struct V_3 * V_16 = V_2 -> V_5 ;
T_1 V_17 ;
if ( ! ( V_2 -> V_6 & V_9 ) )
return false ;
if ( F_8 ( V_11 , V_16 -> V_8 , V_16 -> V_14 , & V_17 ) == 0 ) {
V_2 -> V_17 = V_17 ;
V_2 -> V_6 |= V_18 ;
}
return true ;
}
void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 & V_7 )
F_2 ( V_2 ) ;
if ( V_2 -> V_6 & V_9 )
F_4 ( V_2 ) ;
}
void F_10 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
if ( F_5 ( V_11 , V_2 ) )
F_2 ( V_2 ) ;
if ( F_7 ( V_11 , V_2 ) )
F_4 ( V_2 ) ;
}
static int F_11 ( const char * V_19 , T_2 V_20 , T_1 * V_21 )
{
unsigned long V_22 ;
char V_23 [ 16 ] ;
if ( memchr ( V_19 , '@' , V_20 ) != NULL || V_20 >= sizeof( V_23 ) )
return 0 ;
memcpy ( V_23 , V_19 , V_20 ) ;
V_23 [ V_20 ] = '\0' ;
if ( F_12 ( V_23 , 0 , & V_22 ) != 0 )
return 0 ;
* V_21 = V_22 ;
return 1 ;
}
static int F_13 ( T_1 V_24 , char * V_23 , T_2 V_25 )
{
return snprintf ( V_23 , V_25 , L_1 , V_24 ) ;
}
int F_14 ( void )
{
struct V_26 * V_26 ;
struct V_27 * V_28 ;
int V_29 = 0 ;
F_15 ( V_30 L_2 , V_31 . V_19 ) ;
V_26 = F_16 ( NULL ) ;
if ( ! V_26 )
return - V_32 ;
V_28 = F_17 ( & V_33 , L_3 , 0 , 0 , V_26 ,
( V_34 & ~ V_35 ) |
V_36 | V_37 ,
V_38 ) ;
if ( F_18 ( V_28 ) ) {
V_29 = F_19 ( V_28 ) ;
goto V_39;
}
V_29 = F_20 ( V_28 , NULL , 0 , NULL , NULL ) ;
if ( V_29 < 0 )
goto V_40;
V_29 = F_21 ( & V_31 ) ;
if ( V_29 < 0 )
goto V_40;
V_26 -> V_41 = V_28 ;
V_26 -> V_42 = V_43 ;
V_44 = V_26 ;
return 0 ;
V_40:
F_22 ( V_28 ) ;
V_39:
F_23 ( V_26 ) ;
return V_29 ;
}
void F_24 ( void )
{
F_25 ( V_44 -> V_41 ) ;
F_26 ( & V_31 ) ;
F_23 ( V_44 ) ;
}
static T_3 F_27 ( const char * V_19 , T_2 V_20 ,
const char * type , T_2 V_45 , char * * V_46 )
{
char * V_47 ;
T_2 V_48 = V_45 + V_20 + 2 ;
* V_46 = F_28 ( V_48 , V_49 ) ;
if ( ! * V_46 )
return - V_32 ;
V_47 = * V_46 ;
memcpy ( V_47 , type , V_45 ) ;
V_47 += V_45 ;
* V_47 ++ = ':' ;
memcpy ( V_47 , V_19 , V_20 ) ;
V_47 += V_20 ;
* V_47 = '\0' ;
return V_48 ;
}
static T_3 F_29 ( const char * V_19 , T_2 V_20 ,
const char * type , void * V_8 , T_2 V_50 )
{
const struct V_26 * V_51 ;
struct V_27 * V_52 ;
char * V_46 ;
struct V_53 * V_54 ;
T_3 V_29 ;
V_29 = F_27 ( V_19 , V_20 , type , strlen ( type ) , & V_46 ) ;
if ( V_29 <= 0 )
goto V_55;
V_51 = F_30 ( V_44 ) ;
V_52 = F_31 ( & V_31 , V_46 , L_4 ) ;
F_32 ( V_51 ) ;
F_3 ( V_46 ) ;
if ( F_18 ( V_52 ) ) {
V_29 = F_19 ( V_52 ) ;
goto V_55;
}
F_33 () ;
V_52 -> V_56 |= V_36 ;
V_29 = F_34 ( V_52 ) ;
if ( V_29 < 0 )
goto V_57;
V_54 = F_35 ( V_52 -> V_54 . V_8 ) ;
if ( F_36 ( V_54 ) ) {
V_29 = F_19 ( V_54 ) ;
goto V_57;
}
V_29 = V_54 -> V_58 ;
if ( V_29 > 0 && V_29 <= V_50 )
memcpy ( V_8 , V_54 -> V_8 , V_29 ) ;
else
V_29 = - V_59 ;
V_57:
F_37 () ;
F_22 ( V_52 ) ;
V_55:
return V_29 ;
}
static T_3 F_38 ( T_1 V_24 , const char * type , char * V_23 , T_2 V_25 )
{
char V_60 [ V_61 ] ;
int V_62 ;
T_3 V_29 ;
V_62 = snprintf ( V_60 , sizeof( V_60 ) , L_1 , V_24 ) ;
V_29 = F_29 ( V_60 , V_62 , type , V_23 , V_25 ) ;
if ( V_29 < 0 )
return - V_59 ;
return V_29 ;
}
static int F_39 ( const char * V_19 , T_2 V_20 ,
const char * type , T_1 * V_24 )
{
char V_60 [ V_61 ] ;
long V_63 ;
T_3 V_50 ;
int V_29 = 0 ;
V_50 = F_29 ( V_19 , V_20 , type , V_60 , V_61 ) ;
if ( V_50 <= 0 ) {
V_29 = - V_59 ;
} else {
V_29 = F_40 ( V_60 , 10 , & V_63 ) ;
* V_24 = ( T_1 ) V_63 ;
}
return V_29 ;
}
int F_6 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_13 )
{
if ( F_11 ( V_19 , V_20 , V_13 ) )
return 0 ;
return F_39 ( V_19 , V_20 , L_5 , V_13 ) ;
}
int F_8 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_17 )
{
if ( F_11 ( V_19 , V_20 , V_17 ) )
return 0 ;
return F_39 ( V_19 , V_20 , L_6 , V_17 ) ;
}
int F_41 ( const struct V_10 * V_11 , T_1 V_13 , char * V_23 , T_2 V_25 )
{
int V_29 = - V_59 ;
if ( ! ( V_11 -> V_64 & V_65 ) )
V_29 = F_38 ( V_13 , L_7 , V_23 , V_25 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_13 , V_23 , V_25 ) ;
return V_29 ;
}
int F_42 ( const struct V_10 * V_11 , T_1 V_17 , char * V_23 , T_2 V_25 )
{
int V_29 = - V_59 ;
if ( ! ( V_11 -> V_64 & V_65 ) )
V_29 = F_38 ( V_17 , L_8 , V_23 , V_25 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_17 , V_23 , V_25 ) ;
return V_29 ;
}
static int F_43 ( const char * V_22 , struct V_66 * V_67 )
{
char * V_68 ;
int V_69 = F_44 ( V_22 , & V_68 , 0 ) ;
int V_70 = V_69 * V_71 ;
if ( V_68 == V_22 || * V_68 || V_69 < 0 || V_70 < V_69 )
return - V_59 ;
* ( ( int * ) V_67 -> V_72 ) = V_70 ;
return 0 ;
}
int
F_45 ( struct V_73 * V_74 )
{
struct V_75 * V_75 ;
int error ;
F_46 ( V_74 -> V_76 != NULL ) ;
V_75 = F_47 ( sizeof( * V_75 ) , V_49 ) ;
if ( V_75 == NULL )
return - V_32 ;
V_75 -> V_77 = F_48 ( V_74 -> V_78 -> V_79 . V_80 ,
L_9 , V_75 , & V_81 , 0 ) ;
if ( F_18 ( V_75 -> V_77 ) ) {
error = F_19 ( V_75 -> V_77 ) ;
F_3 ( V_75 ) ;
return error ;
}
F_49 ( & V_75 -> V_82 ) ;
F_49 ( & V_75 -> V_83 ) ;
F_50 ( & V_75 -> V_84 ) ;
V_75 -> V_85 . V_86 = V_87 ;
V_75 -> V_88 . V_86 = V_89 ;
V_74 -> V_76 = V_75 ;
return 0 ;
}
void
F_51 ( struct V_73 * V_74 )
{
struct V_75 * V_75 = V_74 -> V_76 ;
if ( ! V_75 )
return;
F_52 ( V_75 -> V_77 ) ;
V_74 -> V_76 = NULL ;
F_3 ( V_75 ) ;
}
static inline struct V_90 *
F_53 ( struct V_91 * V_92 , const char * V_19 , T_2 V_14 )
{
return & V_92 -> V_93 [ F_54 ( V_19 , V_14 ) % V_94 ] ;
}
static struct V_90 *
F_55 ( struct V_91 * V_92 , const char * V_19 , T_2 V_14 )
{
struct V_90 * V_95 = F_53 ( V_92 , V_19 , V_14 ) ;
if ( V_95 -> V_96 != V_14 || memcmp ( V_95 -> V_97 , V_19 , V_14 ) != 0 )
return NULL ;
if ( F_56 ( V_98 , V_95 -> V_99 ) )
return NULL ;
return V_95 ;
}
static inline struct V_90 *
F_57 ( struct V_91 * V_92 , T_1 V_24 )
{
return & V_92 -> V_93 [ F_54 ( & V_24 , sizeof( V_24 ) ) % V_94 ] ;
}
static struct V_90 *
F_58 ( struct V_91 * V_92 , T_1 V_24 )
{
struct V_90 * V_95 = F_57 ( V_92 , V_24 ) ;
if ( V_95 -> V_100 != V_24 || V_95 -> V_96 == 0 )
return NULL ;
if ( F_56 ( V_98 , V_95 -> V_99 ) )
return NULL ;
return V_95 ;
}
static inline struct V_90 *
F_59 ( struct V_91 * V_92 , char * V_19 , T_2 V_14 )
{
return F_53 ( V_92 , V_19 , V_14 ) ;
}
static inline struct V_90 *
F_60 ( struct V_91 * V_92 , T_1 V_24 )
{
return F_57 ( V_92 , V_24 ) ;
}
static void
F_61 ( struct V_90 * V_95 , const char * V_19 ,
T_2 V_20 , T_1 V_24 )
{
V_95 -> V_100 = V_24 ;
memcpy ( V_95 -> V_97 , V_19 , V_20 ) ;
V_95 -> V_97 [ V_20 ] = '\0' ;
V_95 -> V_96 = V_20 ;
V_95 -> V_99 = V_98 + V_101 ;
}
static int
F_62 ( struct V_75 * V_75 , struct V_91 * V_92 ,
const char * V_19 , T_2 V_20 , T_1 * V_24 )
{
struct V_102 V_103 ;
struct V_104 * V_105 ;
struct V_90 * V_95 ;
F_63 ( V_106 , V_107 ) ;
int V_29 = - V_108 ;
V_105 = & V_75 -> V_109 ;
for (; ; ) {
if ( V_20 == 0 )
return - V_59 ;
if ( V_19 [ V_20 - 1 ] != '\0' )
break;
V_20 -- ;
}
if ( V_20 >= V_110 )
return - V_59 ;
F_64 ( & V_75 -> V_82 ) ;
F_64 ( & V_75 -> V_83 ) ;
V_95 = F_55 ( V_92 , V_19 , V_20 ) ;
if ( V_95 != NULL ) {
* V_24 = V_95 -> V_100 ;
V_29 = 0 ;
goto V_55;
}
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
memcpy ( V_105 -> V_111 , V_19 , V_20 ) ;
V_105 -> V_112 = V_92 -> V_86 ;
V_105 -> V_113 = V_114 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_8 = V_105 ;
V_103 . V_14 = sizeof( * V_105 ) ;
F_65 ( & V_75 -> V_84 , & V_106 ) ;
if ( F_66 ( V_75 -> V_77 -> V_115 , & V_103 ) < 0 ) {
F_67 ( & V_75 -> V_84 , & V_106 ) ;
goto V_55;
}
F_68 ( V_116 ) ;
F_69 ( & V_75 -> V_83 ) ;
F_70 () ;
F_71 ( V_117 ) ;
F_67 ( & V_75 -> V_84 , & V_106 ) ;
F_64 ( & V_75 -> V_83 ) ;
if ( V_105 -> V_118 & V_119 ) {
* V_24 = V_105 -> V_120 ;
V_29 = 0 ;
}
V_55:
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_69 ( & V_75 -> V_83 ) ;
F_69 ( & V_75 -> V_82 ) ;
return V_29 ;
}
static int
F_72 ( struct V_75 * V_75 , struct V_91 * V_92 ,
T_1 V_24 , char * V_19 )
{
struct V_102 V_103 ;
struct V_104 * V_105 ;
struct V_90 * V_95 ;
F_63 ( V_106 , V_107 ) ;
int V_29 = - V_108 ;
unsigned int V_14 ;
V_105 = & V_75 -> V_109 ;
F_64 ( & V_75 -> V_82 ) ;
F_64 ( & V_75 -> V_83 ) ;
V_95 = F_58 ( V_92 , V_24 ) ;
if ( V_95 ) {
memcpy ( V_19 , V_95 -> V_97 , V_95 -> V_96 ) ;
V_29 = V_95 -> V_96 ;
goto V_55;
}
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_112 = V_92 -> V_86 ;
V_105 -> V_113 = V_121 ;
V_105 -> V_120 = V_24 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_8 = V_105 ;
V_103 . V_14 = sizeof( * V_105 ) ;
F_65 ( & V_75 -> V_84 , & V_106 ) ;
if ( F_66 ( V_75 -> V_77 -> V_115 , & V_103 ) < 0 ) {
F_67 ( & V_75 -> V_84 , & V_106 ) ;
goto V_55;
}
F_68 ( V_116 ) ;
F_69 ( & V_75 -> V_83 ) ;
F_70 () ;
F_71 ( V_117 ) ;
F_67 ( & V_75 -> V_84 , & V_106 ) ;
F_64 ( & V_75 -> V_83 ) ;
if ( V_105 -> V_118 & V_119 ) {
if ( ( V_14 = F_73 ( V_105 -> V_111 , V_110 ) ) == 0 )
goto V_55;
memcpy ( V_19 , V_105 -> V_111 , V_14 ) ;
V_29 = V_14 ;
}
V_55:
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
F_69 ( & V_75 -> V_83 ) ;
F_69 ( & V_75 -> V_82 ) ;
return V_29 ;
}
static T_3
F_74 ( struct V_122 * V_123 , const char T_4 * V_124 , T_2 V_125 )
{
struct V_126 * V_127 = F_75 ( V_123 -> V_128 . V_80 -> V_115 ) ;
struct V_75 * V_75 = (struct V_75 * ) V_127 -> V_129 ;
struct V_104 V_130 , * V_105 = & V_75 -> V_109 ;
struct V_91 * V_92 ;
struct V_90 * V_95 = NULL ;
T_2 V_131 ;
int V_29 ;
if ( V_125 != sizeof( V_130 ) )
return - V_132 ;
if ( F_76 ( & V_130 , V_124 , V_125 ) != 0 )
return - V_133 ;
F_64 ( & V_75 -> V_83 ) ;
V_29 = V_125 ;
V_105 -> V_118 = V_130 . V_118 ;
if ( ! ( V_130 . V_118 & V_119 ) ) {
F_77 ( & V_75 -> V_84 ) ;
goto V_55;
}
V_29 = - V_59 ;
V_131 = F_73 ( V_130 . V_111 , V_110 ) ;
if ( V_131 == 0 || V_131 == V_110 )
goto V_55;
switch ( V_130 . V_112 ) {
case V_87 :
V_92 = & V_75 -> V_85 ;
break;
case V_89 :
V_92 = & V_75 -> V_88 ;
break;
default:
goto V_55;
}
switch ( V_130 . V_113 ) {
case V_121 :
if ( V_105 -> V_113 == V_121
&& V_105 -> V_112 == V_130 . V_112
&& V_105 -> V_120 == V_130 . V_120 ) {
memcpy ( V_105 -> V_111 , V_130 . V_111 , V_131 ) ;
V_105 -> V_111 [ V_131 ] = '\0' ;
F_77 ( & V_75 -> V_84 ) ;
}
V_95 = F_60 ( V_92 , V_130 . V_120 ) ;
break;
case V_114 :
if ( V_105 -> V_113 == V_114
&& V_105 -> V_112 == V_130 . V_112
&& F_73 ( V_105 -> V_111 , V_110 ) == V_131
&& memcmp ( V_105 -> V_111 , V_130 . V_111 , V_131 ) == 0 ) {
V_105 -> V_120 = V_130 . V_120 ;
F_77 ( & V_75 -> V_84 ) ;
}
V_95 = F_59 ( V_92 , V_130 . V_111 , V_131 ) ;
break;
default:
goto V_55;
}
if ( V_95 != NULL )
F_61 ( V_95 , V_130 . V_111 , V_131 , V_130 . V_120 ) ;
V_29 = V_125 ;
V_55:
F_69 ( & V_75 -> V_83 ) ;
return V_29 ;
}
static void
F_78 ( struct V_102 * V_103 )
{
struct V_104 * V_105 = V_103 -> V_8 ;
struct V_75 * V_75 = F_79 ( V_105 , struct V_75 , V_109 ) ;
if ( V_103 -> V_134 >= 0 )
return;
F_64 ( & V_75 -> V_83 ) ;
V_105 -> V_118 = V_135 ;
F_77 ( & V_75 -> V_84 ) ;
F_69 ( & V_75 -> V_83 ) ;
}
static unsigned int F_54 ( const void * V_23 , T_2 V_25 )
{
const unsigned char * V_136 , * V_137 = ( const unsigned char * ) V_23 + V_25 ;
unsigned int V_138 = V_139 ;
for ( V_136 = V_23 ; V_136 < V_137 ; V_136 ++ ) {
V_138 *= V_140 ;
V_138 ^= ( unsigned int ) * V_136 ;
}
return V_138 ;
}
int F_6 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_13 )
{
struct V_75 * V_75 = V_11 -> V_73 -> V_76 ;
if ( F_11 ( V_19 , V_20 , V_13 ) )
return 0 ;
return F_62 ( V_75 , & V_75 -> V_85 , V_19 , V_20 , V_13 ) ;
}
int F_8 ( const struct V_10 * V_11 , const char * V_19 , T_2 V_20 , T_1 * V_13 )
{
struct V_75 * V_75 = V_11 -> V_73 -> V_76 ;
if ( F_11 ( V_19 , V_20 , V_13 ) )
return 0 ;
return F_62 ( V_75 , & V_75 -> V_88 , V_19 , V_20 , V_13 ) ;
}
int F_41 ( const struct V_10 * V_11 , T_1 V_13 , char * V_23 , T_2 V_25 )
{
struct V_75 * V_75 = V_11 -> V_73 -> V_76 ;
int V_29 = - V_59 ;
if ( ! ( V_11 -> V_64 & V_65 ) )
V_29 = F_72 ( V_75 , & V_75 -> V_85 , V_13 , V_23 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_13 , V_23 , V_25 ) ;
return V_29 ;
}
int F_42 ( const struct V_10 * V_11 , T_1 V_13 , char * V_23 , T_2 V_25 )
{
struct V_75 * V_75 = V_11 -> V_73 -> V_76 ;
int V_29 = - V_59 ;
if ( ! ( V_11 -> V_64 & V_65 ) )
V_29 = F_72 ( V_75 , & V_75 -> V_88 , V_13 , V_23 ) ;
if ( V_29 < 0 )
V_29 = F_13 ( V_13 , V_23 , V_25 ) ;
return V_29 ;
}
