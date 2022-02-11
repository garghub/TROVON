static int F_1 ( const char * V_1 , T_1 V_2 , T_2 * V_3 )
{
unsigned long V_4 ;
char V_5 [ 16 ] ;
if ( memchr ( V_1 , '@' , V_2 ) != NULL || V_2 >= sizeof( V_5 ) )
return 0 ;
memcpy ( V_5 , V_1 , V_2 ) ;
V_5 [ V_2 ] = '\0' ;
if ( F_2 ( V_5 , 0 , & V_4 ) != 0 )
return 0 ;
* V_3 = V_4 ;
return 1 ;
}
static int F_3 ( T_2 V_6 , char * V_5 , T_1 V_7 )
{
return snprintf ( V_5 , V_7 , L_1 , V_6 ) ;
}
int F_4 ( void )
{
struct V_8 * V_8 ;
struct V_9 * V_10 ;
int V_11 = 0 ;
F_5 ( V_12 L_2 , V_13 . V_1 ) ;
V_8 = F_6 ( NULL ) ;
if ( ! V_8 )
return - V_14 ;
V_10 = F_7 ( & V_15 , L_3 , 0 , 0 , V_8 ,
( V_16 & ~ V_17 ) |
V_18 | V_19 ,
V_20 ) ;
if ( F_8 ( V_10 ) ) {
V_11 = F_9 ( V_10 ) ;
goto V_21;
}
V_11 = F_10 ( V_10 , NULL , 0 , NULL , NULL ) ;
if ( V_11 < 0 )
goto V_22;
V_11 = F_11 ( & V_13 ) ;
if ( V_11 < 0 )
goto V_22;
V_8 -> V_23 = V_10 ;
V_8 -> V_24 = V_25 ;
V_26 = V_8 ;
return 0 ;
V_22:
F_12 ( V_10 ) ;
V_21:
F_13 ( V_8 ) ;
return V_11 ;
}
void F_14 ( void )
{
F_15 ( V_26 -> V_23 ) ;
F_16 ( & V_13 ) ;
F_13 ( V_26 ) ;
}
static T_3 F_17 ( const char * V_1 , T_1 V_2 ,
const char * type , T_1 V_27 , char * * V_28 )
{
char * V_29 ;
T_1 V_30 = V_27 + V_2 + 2 ;
* V_28 = F_18 ( V_30 , V_31 ) ;
if ( ! * V_28 )
return - V_14 ;
V_29 = * V_28 ;
memcpy ( V_29 , type , V_27 ) ;
V_29 += V_27 ;
* V_29 ++ = ':' ;
memcpy ( V_29 , V_1 , V_2 ) ;
V_29 += V_2 ;
* V_29 = '\0' ;
return V_30 ;
}
static T_3 F_19 ( const char * V_1 , T_1 V_2 ,
const char * type , void * V_32 , T_1 V_33 )
{
const struct V_8 * V_34 ;
struct V_9 * V_35 ;
char * V_28 ;
struct V_36 * V_37 ;
T_3 V_11 ;
V_11 = F_17 ( V_1 , V_2 , type , strlen ( type ) , & V_28 ) ;
if ( V_11 <= 0 )
goto V_38;
V_34 = F_20 ( V_26 ) ;
V_35 = F_21 ( & V_13 , V_28 , L_4 ) ;
F_22 ( V_34 ) ;
F_23 ( V_28 ) ;
if ( F_8 ( V_35 ) ) {
V_11 = F_9 ( V_35 ) ;
goto V_38;
}
F_24 () ;
V_35 -> V_39 |= V_18 ;
V_11 = F_25 ( V_35 ) ;
if ( V_11 < 0 )
goto V_40;
V_37 = F_26 ( V_35 -> V_37 . V_32 ) ;
if ( F_27 ( V_37 ) ) {
V_11 = F_9 ( V_37 ) ;
goto V_40;
}
V_11 = V_37 -> V_41 ;
if ( V_11 > 0 && V_11 <= V_33 )
memcpy ( V_32 , V_37 -> V_32 , V_11 ) ;
else
V_11 = - V_42 ;
V_40:
F_28 () ;
F_12 ( V_35 ) ;
V_38:
return V_11 ;
}
static T_3 F_29 ( T_2 V_6 , const char * type , char * V_5 , T_1 V_7 )
{
char V_43 [ V_44 ] ;
int V_45 ;
T_3 V_11 ;
V_45 = snprintf ( V_43 , sizeof( V_43 ) , L_1 , V_6 ) ;
V_11 = F_19 ( V_43 , V_45 , type , V_5 , V_7 ) ;
if ( V_11 < 0 )
return - V_42 ;
return V_11 ;
}
static int F_30 ( const char * V_1 , T_1 V_2 ,
const char * type , T_2 * V_6 )
{
char V_43 [ V_44 ] ;
long V_46 ;
T_3 V_33 ;
int V_11 = 0 ;
V_33 = F_19 ( V_1 , V_2 , type , V_43 , V_44 ) ;
if ( V_33 <= 0 ) {
V_11 = - V_42 ;
} else {
V_11 = F_31 ( V_43 , 10 , & V_46 ) ;
* V_6 = ( T_2 ) V_46 ;
}
return V_11 ;
}
int F_32 ( const struct V_47 * V_48 , const char * V_1 , T_1 V_2 , T_2 * V_49 )
{
if ( F_1 ( V_1 , V_2 , V_49 ) )
return 0 ;
return F_30 ( V_1 , V_2 , L_5 , V_49 ) ;
}
int F_33 ( const struct V_47 * V_48 , const char * V_1 , T_1 V_2 , T_2 * V_50 )
{
if ( F_1 ( V_1 , V_2 , V_50 ) )
return 0 ;
return F_30 ( V_1 , V_2 , L_6 , V_50 ) ;
}
int F_34 ( const struct V_47 * V_48 , T_2 V_49 , char * V_5 , T_1 V_7 )
{
int V_11 = - V_42 ;
if ( ! ( V_48 -> V_51 & V_52 ) )
V_11 = F_29 ( V_49 , L_7 , V_5 , V_7 ) ;
if ( V_11 < 0 )
V_11 = F_3 ( V_49 , V_5 , V_7 ) ;
return V_11 ;
}
int F_35 ( const struct V_47 * V_48 , T_2 V_50 , char * V_5 , T_1 V_7 )
{
int V_11 = - V_42 ;
if ( ! ( V_48 -> V_51 & V_52 ) )
V_11 = F_29 ( V_50 , L_8 , V_5 , V_7 ) ;
if ( V_11 < 0 )
V_11 = F_3 ( V_50 , V_5 , V_7 ) ;
return V_11 ;
}
static int F_36 ( const char * V_4 , struct V_53 * V_54 )
{
char * V_55 ;
int V_56 = F_37 ( V_4 , & V_55 , 0 ) ;
int V_57 = V_56 * V_58 ;
if ( V_55 == V_4 || * V_55 || V_56 < 0 || V_57 < V_56 )
return - V_42 ;
* ( ( int * ) V_54 -> V_59 ) = V_57 ;
return 0 ;
}
int
F_38 ( struct V_60 * V_61 )
{
struct V_62 * V_62 ;
int error ;
F_39 ( V_61 -> V_63 != NULL ) ;
V_62 = F_40 ( sizeof( * V_62 ) , V_31 ) ;
if ( V_62 == NULL )
return - V_14 ;
V_62 -> V_64 = F_41 ( V_61 -> V_65 -> V_66 . V_67 ,
L_9 , V_62 , & V_68 , 0 ) ;
if ( F_8 ( V_62 -> V_64 ) ) {
error = F_9 ( V_62 -> V_64 ) ;
F_23 ( V_62 ) ;
return error ;
}
F_42 ( & V_62 -> V_69 ) ;
F_42 ( & V_62 -> V_70 ) ;
F_43 ( & V_62 -> V_71 ) ;
V_62 -> V_72 . V_73 = V_74 ;
V_62 -> V_75 . V_73 = V_76 ;
V_61 -> V_63 = V_62 ;
return 0 ;
}
void
F_44 ( struct V_60 * V_61 )
{
struct V_62 * V_62 = V_61 -> V_63 ;
if ( ! V_62 )
return;
F_45 ( V_62 -> V_64 ) ;
V_61 -> V_63 = NULL ;
F_23 ( V_62 ) ;
}
static inline struct V_77 *
F_46 ( struct V_78 * V_79 , const char * V_1 , T_1 V_80 )
{
return & V_79 -> V_81 [ F_47 ( V_1 , V_80 ) % V_82 ] ;
}
static struct V_77 *
F_48 ( struct V_78 * V_79 , const char * V_1 , T_1 V_80 )
{
struct V_77 * V_83 = F_46 ( V_79 , V_1 , V_80 ) ;
if ( V_83 -> V_84 != V_80 || memcmp ( V_83 -> V_85 , V_1 , V_80 ) != 0 )
return NULL ;
if ( F_49 ( V_86 , V_83 -> V_87 ) )
return NULL ;
return V_83 ;
}
static inline struct V_77 *
F_50 ( struct V_78 * V_79 , T_2 V_6 )
{
return & V_79 -> V_81 [ F_47 ( & V_6 , sizeof( V_6 ) ) % V_82 ] ;
}
static struct V_77 *
F_51 ( struct V_78 * V_79 , T_2 V_6 )
{
struct V_77 * V_83 = F_50 ( V_79 , V_6 ) ;
if ( V_83 -> V_88 != V_6 || V_83 -> V_84 == 0 )
return NULL ;
if ( F_49 ( V_86 , V_83 -> V_87 ) )
return NULL ;
return V_83 ;
}
static inline struct V_77 *
F_52 ( struct V_78 * V_79 , char * V_1 , T_1 V_80 )
{
return F_46 ( V_79 , V_1 , V_80 ) ;
}
static inline struct V_77 *
F_53 ( struct V_78 * V_79 , T_2 V_6 )
{
return F_50 ( V_79 , V_6 ) ;
}
static void
F_54 ( struct V_77 * V_83 , const char * V_1 ,
T_1 V_2 , T_2 V_6 )
{
V_83 -> V_88 = V_6 ;
memcpy ( V_83 -> V_85 , V_1 , V_2 ) ;
V_83 -> V_85 [ V_2 ] = '\0' ;
V_83 -> V_84 = V_2 ;
V_83 -> V_87 = V_86 + V_89 ;
}
static int
F_55 ( struct V_62 * V_62 , struct V_78 * V_79 ,
const char * V_1 , T_1 V_2 , T_2 * V_6 )
{
struct V_90 V_91 ;
struct V_92 * V_93 ;
struct V_77 * V_83 ;
F_56 ( V_94 , V_95 ) ;
int V_11 = - V_96 ;
V_93 = & V_62 -> V_97 ;
for (; ; ) {
if ( V_2 == 0 )
return - V_42 ;
if ( V_1 [ V_2 - 1 ] != '\0' )
break;
V_2 -- ;
}
if ( V_2 >= V_98 )
return - V_42 ;
F_57 ( & V_62 -> V_69 ) ;
F_57 ( & V_62 -> V_70 ) ;
V_83 = F_48 ( V_79 , V_1 , V_2 ) ;
if ( V_83 != NULL ) {
* V_6 = V_83 -> V_88 ;
V_11 = 0 ;
goto V_38;
}
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
memcpy ( V_93 -> V_99 , V_1 , V_2 ) ;
V_93 -> V_100 = V_79 -> V_73 ;
V_93 -> V_101 = V_102 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_32 = V_93 ;
V_91 . V_80 = sizeof( * V_93 ) ;
F_58 ( & V_62 -> V_71 , & V_94 ) ;
if ( F_59 ( V_62 -> V_64 -> V_103 , & V_91 ) < 0 ) {
F_60 ( & V_62 -> V_71 , & V_94 ) ;
goto V_38;
}
F_61 ( V_104 ) ;
F_62 ( & V_62 -> V_70 ) ;
F_63 () ;
F_64 ( V_105 ) ;
F_60 ( & V_62 -> V_71 , & V_94 ) ;
F_57 ( & V_62 -> V_70 ) ;
if ( V_93 -> V_106 & V_107 ) {
* V_6 = V_93 -> V_108 ;
V_11 = 0 ;
}
V_38:
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
F_62 ( & V_62 -> V_70 ) ;
F_62 ( & V_62 -> V_69 ) ;
return V_11 ;
}
static int
F_65 ( struct V_62 * V_62 , struct V_78 * V_79 ,
T_2 V_6 , char * V_1 )
{
struct V_90 V_91 ;
struct V_92 * V_93 ;
struct V_77 * V_83 ;
F_56 ( V_94 , V_95 ) ;
int V_11 = - V_96 ;
unsigned int V_80 ;
V_93 = & V_62 -> V_97 ;
F_57 ( & V_62 -> V_69 ) ;
F_57 ( & V_62 -> V_70 ) ;
V_83 = F_51 ( V_79 , V_6 ) ;
if ( V_83 ) {
memcpy ( V_1 , V_83 -> V_85 , V_83 -> V_84 ) ;
V_11 = V_83 -> V_84 ;
goto V_38;
}
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
V_93 -> V_100 = V_79 -> V_73 ;
V_93 -> V_101 = V_109 ;
V_93 -> V_108 = V_6 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_32 = V_93 ;
V_91 . V_80 = sizeof( * V_93 ) ;
F_58 ( & V_62 -> V_71 , & V_94 ) ;
if ( F_59 ( V_62 -> V_64 -> V_103 , & V_91 ) < 0 ) {
F_60 ( & V_62 -> V_71 , & V_94 ) ;
goto V_38;
}
F_61 ( V_104 ) ;
F_62 ( & V_62 -> V_70 ) ;
F_63 () ;
F_64 ( V_105 ) ;
F_60 ( & V_62 -> V_71 , & V_94 ) ;
F_57 ( & V_62 -> V_70 ) ;
if ( V_93 -> V_106 & V_107 ) {
if ( ( V_80 = F_66 ( V_93 -> V_99 , V_98 ) ) == 0 )
goto V_38;
memcpy ( V_1 , V_93 -> V_99 , V_80 ) ;
V_11 = V_80 ;
}
V_38:
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
F_62 ( & V_62 -> V_70 ) ;
F_62 ( & V_62 -> V_69 ) ;
return V_11 ;
}
static T_3
F_67 ( struct V_110 * V_111 , struct V_90 * V_91 ,
char T_4 * V_112 , T_1 V_7 )
{
char * V_32 = ( char * ) V_91 -> V_32 + V_91 -> V_113 ;
T_1 V_114 = F_68 ( V_91 -> V_80 , V_7 ) ;
unsigned long V_115 ;
V_115 = F_69 ( V_112 , V_32 , V_114 ) ;
if ( V_115 == V_114 ) {
V_91 -> V_116 = - V_117 ;
return - V_117 ;
}
V_114 -= V_115 ;
V_91 -> V_113 += V_114 ;
V_91 -> V_116 = 0 ;
return V_114 ;
}
static T_3
F_70 ( struct V_110 * V_111 , const char T_4 * V_118 , T_1 V_114 )
{
struct V_119 * V_120 = F_71 ( V_111 -> V_121 . V_67 -> V_103 ) ;
struct V_62 * V_62 = (struct V_62 * ) V_120 -> V_122 ;
struct V_92 V_123 , * V_93 = & V_62 -> V_97 ;
struct V_78 * V_79 ;
struct V_77 * V_83 = NULL ;
T_1 V_124 ;
int V_11 ;
if ( V_114 != sizeof( V_123 ) )
return - V_125 ;
if ( F_72 ( & V_123 , V_118 , V_114 ) != 0 )
return - V_117 ;
F_57 ( & V_62 -> V_70 ) ;
V_11 = V_114 ;
V_93 -> V_106 = V_123 . V_106 ;
if ( ! ( V_123 . V_106 & V_107 ) ) {
F_73 ( & V_62 -> V_71 ) ;
goto V_38;
}
V_11 = - V_42 ;
V_124 = F_66 ( V_123 . V_99 , V_98 ) ;
if ( V_124 == 0 || V_124 == V_98 )
goto V_38;
switch ( V_123 . V_100 ) {
case V_74 :
V_79 = & V_62 -> V_72 ;
break;
case V_76 :
V_79 = & V_62 -> V_75 ;
break;
default:
goto V_38;
}
switch ( V_123 . V_101 ) {
case V_109 :
if ( V_93 -> V_101 == V_109
&& V_93 -> V_100 == V_123 . V_100
&& V_93 -> V_108 == V_123 . V_108 ) {
memcpy ( V_93 -> V_99 , V_123 . V_99 , V_124 ) ;
V_93 -> V_99 [ V_124 ] = '\0' ;
F_73 ( & V_62 -> V_71 ) ;
}
V_83 = F_53 ( V_79 , V_123 . V_108 ) ;
break;
case V_102 :
if ( V_93 -> V_101 == V_102
&& V_93 -> V_100 == V_123 . V_100
&& F_66 ( V_93 -> V_99 , V_98 ) == V_124
&& memcmp ( V_93 -> V_99 , V_123 . V_99 , V_124 ) == 0 ) {
V_93 -> V_108 = V_123 . V_108 ;
F_73 ( & V_62 -> V_71 ) ;
}
V_83 = F_52 ( V_79 , V_123 . V_99 , V_124 ) ;
break;
default:
goto V_38;
}
if ( V_83 != NULL )
F_54 ( V_83 , V_123 . V_99 , V_124 , V_123 . V_108 ) ;
V_11 = V_114 ;
V_38:
F_62 ( & V_62 -> V_70 ) ;
return V_11 ;
}
static void
F_74 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_32 ;
struct V_62 * V_62 = F_75 ( V_93 , struct V_62 , V_97 ) ;
if ( V_91 -> V_116 >= 0 )
return;
F_57 ( & V_62 -> V_70 ) ;
V_93 -> V_106 = V_126 ;
F_73 ( & V_62 -> V_71 ) ;
F_62 ( & V_62 -> V_70 ) ;
}
static unsigned int F_47 ( const void * V_5 , T_1 V_7 )
{
const unsigned char * V_127 , * V_128 = ( const unsigned char * ) V_5 + V_7 ;
unsigned int V_129 = V_130 ;
for ( V_127 = V_5 ; V_127 < V_128 ; V_127 ++ ) {
V_129 *= V_131 ;
V_129 ^= ( unsigned int ) * V_127 ;
}
return V_129 ;
}
int F_32 ( const struct V_47 * V_48 , const char * V_1 , T_1 V_2 , T_2 * V_49 )
{
struct V_62 * V_62 = V_48 -> V_60 -> V_63 ;
if ( F_1 ( V_1 , V_2 , V_49 ) )
return 0 ;
return F_55 ( V_62 , & V_62 -> V_72 , V_1 , V_2 , V_49 ) ;
}
int F_33 ( const struct V_47 * V_48 , const char * V_1 , T_1 V_2 , T_2 * V_49 )
{
struct V_62 * V_62 = V_48 -> V_60 -> V_63 ;
if ( F_1 ( V_1 , V_2 , V_49 ) )
return 0 ;
return F_55 ( V_62 , & V_62 -> V_75 , V_1 , V_2 , V_49 ) ;
}
int F_34 ( const struct V_47 * V_48 , T_2 V_49 , char * V_5 , T_1 V_7 )
{
struct V_62 * V_62 = V_48 -> V_60 -> V_63 ;
int V_11 = - V_42 ;
if ( ! ( V_48 -> V_51 & V_52 ) )
V_11 = F_65 ( V_62 , & V_62 -> V_72 , V_49 , V_5 ) ;
if ( V_11 < 0 )
V_11 = F_3 ( V_49 , V_5 , V_7 ) ;
return V_11 ;
}
int F_35 ( const struct V_47 * V_48 , T_2 V_49 , char * V_5 , T_1 V_7 )
{
struct V_62 * V_62 = V_48 -> V_60 -> V_63 ;
int V_11 = - V_42 ;
if ( ! ( V_48 -> V_51 & V_52 ) )
V_11 = F_65 ( V_62 , & V_62 -> V_75 , V_49 , V_5 ) ;
if ( V_11 < 0 )
V_11 = F_3 ( V_49 , V_5 , V_7 ) ;
return V_11 ;
}
