static const char * F_1 ( unsigned V_1 )
{
switch ( V_1 ) {
#define F_2 ( T_1 , T_2 , T_3 , T_4 ) \
case HV_PERF_DOMAIN_##n: \
return "__" #n;
#include "hv-24x7-domains.h"
#undef F_2
default:
F_3 ( 1 , L_1 , V_1 ) ;
return L_2 ;
}
}
static bool F_4 ( unsigned V_1 )
{
switch ( V_1 ) {
#define F_2 ( T_1 , T_2 , T_3 , T_4 ) \
case HV_PERF_DOMAIN_##n: \
#include "hv-24x7-domains.h"
#undef F_2
return true ;
default:
return false ;
}
}
static bool F_5 ( unsigned V_1 )
{
switch ( V_1 ) {
#define F_2 ( T_1 , T_2 , T_3 , T_4 ) \
case HV_PERF_DOMAIN_##n: \
return c;
#include "hv-24x7-domains.h"
#undef F_2
default:
return false ;
}
}
static bool F_6 ( unsigned V_1 )
{
return F_5 ( V_1 ) ;
}
static char * F_7 ( struct V_2 * V_3 , int * V_4 )
{
* V_4 = F_8 ( V_3 -> V_5 ) - 2 ;
return ( char * ) V_3 -> V_6 ;
}
static char * F_9 ( struct V_2 * V_3 , int * V_4 )
{
unsigned V_7 = F_8 ( V_3 -> V_5 ) ;
T_5 * V_8 = ( T_5 * ) ( V_3 -> V_6 + V_7 - 2 ) ;
* V_4 = F_8 ( * V_8 ) - 2 ;
return ( char * ) V_3 -> V_6 + V_7 ;
}
static char * F_10 ( struct V_2 * V_3 , int * V_4 )
{
unsigned V_7 = F_8 ( V_3 -> V_5 ) ;
T_5 * V_9 = ( T_5 * ) ( V_3 -> V_6 + V_7 - 2 ) ;
unsigned V_8 = F_8 ( * V_9 ) ;
T_5 * V_10 = ( T_5 * ) ( V_3 -> V_6 + V_7 + V_8 - 2 ) ;
* V_4 = F_8 ( * V_10 ) - 2 ;
return ( char * ) V_3 -> V_6 + V_7 + V_8 ;
}
static bool F_11 ( struct V_2 * V_3 ,
void * V_11 )
{
void * V_12 = V_3 ;
return ( V_12 + F_12 ( struct V_2 , V_6 ) ) < V_11 ;
}
static void * F_13 ( struct V_2 * V_3 , void * V_11 )
{
void * V_12 = V_3 ;
T_5 * V_13 , * V_14 ;
unsigned V_15 , V_16 ;
unsigned V_7 = F_8 ( V_3 -> V_5 ) ;
if ( V_7 < 2 ) {
F_14 ( L_3 , V_17 , V_7 ) ;
return NULL ;
}
if ( V_12 + V_7 > V_11 ) {
F_14 ( L_4 ,
V_17 , V_12 , V_7 , V_11 ) ;
return NULL ;
}
V_13 = ( T_5 * ) ( V_3 -> V_6 + V_7 - 2 ) ;
if ( ! F_15 ( ( V_18 ) V_13 , 2 ) )
F_16 ( L_5 , V_13 ) ;
V_15 = F_8 ( * V_13 ) ;
if ( V_15 < 2 ) {
F_14 ( L_6 , V_17 , V_15 ) ;
return NULL ;
}
if ( V_12 + V_7 + V_15 > V_11 ) {
F_14 ( L_7 ,
V_17 , V_12 , V_7 , V_15 , V_12 + V_7 + V_15 , V_11 ) ;
return NULL ;
}
V_14 = ( T_5 * ) ( V_3 -> V_6 + V_7 + V_15 - 2 ) ;
if ( ! F_15 ( ( V_18 ) V_14 , 2 ) )
F_16 ( L_8 , V_14 ) ;
V_16 = F_8 ( * V_14 ) ;
if ( V_16 < 2 ) {
F_14 ( L_9 ,
V_17 , V_16 ) ;
return NULL ;
}
if ( V_12 + V_7 + V_15 + V_16 > V_11 ) {
F_14 ( L_10 ,
V_17 , V_12 , V_7 , V_15 , V_16 , V_11 ) ;
return NULL ;
}
return V_12 + V_7 + V_15 + V_16 ;
}
static unsigned long F_17 ( unsigned long V_19 ,
unsigned long V_20 ,
unsigned long V_21 )
{
F_18 ( L_11 ,
V_19 , V_20 , V_21 ) ;
F_19 ( ! F_15 ( V_19 , 4096 ) ) ;
return F_20 ( V_22 ,
V_19 , V_20 , V_21 ) ;
}
static unsigned long F_21 ( char V_23 [] ,
T_6 V_20 , T_7 V_21 )
{
return F_17 ( F_22 ( V_23 ) ,
V_20 , V_21 ) ;
}
static char * F_23 ( struct V_2 * V_24 , unsigned V_1 )
{
const char * V_25 ;
const char * V_26 ;
if ( F_5 ( V_1 ) ) {
V_26 = L_12 ;
V_25 = L_13 ;
} else {
V_26 = L_14 ;
V_25 = L_15 ;
}
return F_24 ( V_27 ,
L_16 ,
V_1 ,
F_8 ( V_24 -> V_28 ) +
F_8 ( V_24 -> V_29 ) ,
V_25 ,
V_26 ) ;
}
static char * F_25 ( char * V_30 , int V_31 , T_8 V_32 )
{
return F_24 ( V_32 , L_17 , V_31 , V_30 ) ;
}
static T_9 F_26 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_38 * V_39 ;
V_39 = F_27 ( V_36 , struct V_38 , V_36 ) ;
return sprintf ( V_37 , L_18 , ( char * ) V_39 -> V_40 ) ;
}
static struct V_41 * F_28 ( char * V_42 , char * V_43 )
{
struct V_38 * V_36 = F_29 ( sizeof( * V_36 ) , V_27 ) ;
if ( ! V_36 )
return NULL ;
F_30 ( & V_36 -> V_36 . V_36 ) ;
V_36 -> V_40 = V_43 ;
V_36 -> V_36 . V_36 . V_42 = V_42 ;
V_36 -> V_36 . V_36 . V_44 = 0444 ;
V_36 -> V_36 . V_45 = F_26 ;
return & V_36 -> V_36 . V_36 ;
}
static struct V_41 * F_31 ( char * V_42 , int V_46 ,
int V_47 ,
char * V_43 , T_10 V_48 )
{
char * T_1 ;
char * V_49 = F_25 ( V_43 , V_48 , V_27 ) ;
struct V_41 * V_50 ;
if ( ! V_49 )
return NULL ;
if ( ! V_47 )
T_1 = F_24 ( V_27 , L_17 , V_46 , V_42 ) ;
else
T_1 = F_24 ( V_27 , L_19 , V_46 , V_42 ,
V_47 ) ;
if ( ! T_1 )
goto V_51;
V_50 = F_28 ( T_1 , V_49 ) ;
if ( ! V_50 )
goto V_52;
return V_50 ;
V_52:
F_32 ( T_1 ) ;
V_51:
F_32 ( V_49 ) ;
return NULL ;
}
static void F_33 ( struct V_41 * V_36 )
{
struct V_38 * V_39 ;
V_39 = F_27 ( V_36 , struct V_38 , V_36 . V_36 ) ;
F_32 ( V_39 -> V_40 ) ;
F_32 ( V_39 -> V_36 . V_36 . V_42 ) ;
F_32 ( V_39 ) ;
}
static struct V_41 * F_34 ( unsigned V_53 ,
struct V_2 * V_24 ,
unsigned V_1 ,
int V_54 )
{
int V_5 ;
char * V_55 , * V_56 , * V_57 ;
const char * V_58 ;
struct V_41 * V_36 ;
if ( ! F_4 ( V_1 ) ) {
F_16 ( L_20 ,
V_53 , V_1 ) ;
return NULL ;
}
V_57 = F_23 ( V_24 , V_1 ) ;
if ( ! V_57 )
return NULL ;
V_58 = F_1 ( V_1 ) ;
V_55 = F_7 ( V_24 , & V_5 ) ;
if ( ! V_54 )
V_56 = F_24 ( V_27 , L_21 ,
( int ) V_5 , V_55 , V_58 ) ;
else
V_56 = F_24 ( V_27 , L_22 ,
( int ) V_5 , V_55 , V_58 , V_54 ) ;
if ( ! V_56 )
goto V_59;
V_36 = F_28 ( V_56 , V_57 ) ;
if ( ! V_36 )
goto V_60;
return V_36 ;
V_60:
F_32 ( V_56 ) ;
V_59:
F_32 ( V_57 ) ;
return NULL ;
}
static struct V_41 * F_35 ( struct V_2 * V_24 ,
int V_54 )
{
int V_7 , V_15 ;
char * V_42 = F_7 ( V_24 , & V_7 ) ;
char * V_61 = F_9 ( V_24 , & V_15 ) ;
if ( ! V_15 )
return NULL ;
return F_31 ( V_42 , V_7 , V_54 , V_61 , V_15 ) ;
}
static struct V_41 *
F_36 ( struct V_2 * V_24 , int V_54 )
{
int V_7 , V_15 ;
char * V_42 = F_7 ( V_24 , & V_7 ) ;
char * V_61 = F_10 ( V_24 , & V_15 ) ;
if ( ! V_15 )
return NULL ;
return F_31 ( V_42 , V_7 , V_54 , V_61 , V_15 ) ;
}
static T_9 F_37 ( unsigned V_53 , struct V_41 * * V_62 ,
struct V_2 * V_24 , int V_54 )
{
unsigned V_63 ;
switch ( V_24 -> V_1 ) {
case V_64 :
* V_62 = F_34 ( V_53 , V_24 , V_24 -> V_1 , V_54 ) ;
return 1 ;
case V_65 :
for ( V_63 = 0 ; V_63 < F_38 ( V_66 ) ; V_63 ++ ) {
V_62 [ V_63 ] = F_34 ( V_53 , V_24 , V_66 [ V_63 ] ,
V_54 ) ;
if ( ! V_62 [ V_63 ] ) {
F_16 ( L_23
L_24 , V_53 , V_63 ) ;
for (; V_63 ; V_63 -- )
F_33 ( V_62 [ V_63 - 1 ] ) ;
return - 1 ;
}
}
return V_63 ;
default:
F_16 ( L_25
L_26 , V_53 , V_24 -> V_1 ) ;
return - 1 ;
}
}
static T_10 F_39 ( struct V_2 * V_24 )
{
switch ( V_24 -> V_1 ) {
case V_64 :
return 1 ;
case V_65 :
return F_38 ( V_66 ) ;
default:
return 0 ;
}
}
static unsigned long F_40 ( void * T_2 )
{
struct V_23 * V_67 = F_41 ( T_2 ) ;
F_42 ( ! V_67 ) ;
return F_43 ( V_67 ) + F_44 ( T_2 ) ;
}
static int F_45 ( const void * V_68 , T_10 V_69 , const void * V_70 , T_10 V_71 )
{
if ( V_69 < V_71 )
return 1 ;
if ( V_71 > V_69 )
return - 1 ;
return memcmp ( V_68 , V_70 , V_69 ) ;
}
static int F_46 ( const void * V_72 , T_10 V_69 , unsigned V_68 , const void * V_73 ,
T_10 V_71 , unsigned V_70 )
{
int V_74 = F_45 ( V_72 , V_69 , V_73 , V_71 ) ;
if ( V_74 )
return V_74 ;
if ( V_68 > V_70 )
return 1 ;
if ( V_70 > V_68 )
return - 1 ;
return 0 ;
}
static int F_47 ( struct V_75 * V_76 , const char * V_42 , int V_7 ,
unsigned V_1 )
{
struct V_77 * * V_78 = & ( V_76 -> V_77 ) , * V_79 = NULL ;
struct V_80 * V_81 ;
while ( * V_78 ) {
struct V_80 * V_82 ;
int V_83 ;
V_82 = F_27 ( * V_78 , struct V_80 , V_84 ) ;
V_83 = F_46 ( V_42 , V_7 , V_1 , V_82 -> V_42 , V_82 -> V_7 ,
V_82 -> V_1 ) ;
V_79 = * V_78 ;
if ( V_83 < 0 )
V_78 = & ( ( * V_78 ) -> V_85 ) ;
else if ( V_83 > 0 )
V_78 = & ( ( * V_78 ) -> V_86 ) ;
else {
V_82 -> V_87 ++ ;
F_48 ( L_27 , V_7 ,
V_42 , V_82 -> V_87 ) ;
return V_82 -> V_87 ;
}
}
V_81 = F_49 ( sizeof( * V_81 ) , V_27 ) ;
if ( ! V_81 )
return - V_88 ;
* V_81 = (struct V_80 ) {
. V_42 = V_42 ,
. V_7 = V_7 ,
. V_87 = 0 ,
. V_1 = V_1 ,
} ;
F_50 ( & V_81 -> V_84 , V_79 , V_78 ) ;
F_51 ( & V_81 -> V_84 , V_76 ) ;
return 0 ;
}
static void F_52 ( struct V_75 * V_76 )
{
struct V_80 * V_89 , * T_1 ;
F_53 (pos, n, root, node)
F_32 ( V_89 ) ;
}
static T_9 F_54 ( struct V_2 * V_24 ,
T_10 V_90 ,
T_10 V_91 ,
T_10 V_92 ,
T_10 V_93 , void * V_11 )
{
T_9 V_94 ;
void * V_95 , * V_96 ;
if ( V_93 >= V_91 )
return - 1 ;
if ( V_90 >= V_92 ) {
F_18 ( L_28 ,
V_91 - V_93 ) ;
return - 1 ;
}
if ( ! F_11 ( V_24 , V_11 ) ) {
F_16 ( L_29 ,
V_90 ) ;
return - 1 ;
}
V_94 = F_8 ( V_24 -> V_97 ) ;
if ( V_94 % 16 )
F_48 ( L_30 ,
V_90 , V_94 , V_24 ) ;
V_95 = ( V_98 * ) V_24 + V_94 ;
if ( V_95 > V_11 ) {
F_16 ( L_31 ,
V_90 , V_94 , V_95 , V_11 ,
V_93 ) ;
return - 1 ;
}
V_96 = F_13 ( V_24 , V_11 ) ;
if ( ! V_96 ) {
F_16 ( L_32 ,
V_90 , V_91 , V_24 , V_11 ,
V_93 ) ;
return - 1 ;
}
if ( V_96 > V_95 ) {
F_16 ( L_33 ,
V_90 , V_24 , V_95 , V_93 , V_96 ) ;
return - 1 ;
}
return V_94 ;
}
static int F_55 ( struct V_41 * * * V_99 ,
struct V_41 * * * V_100 ,
struct V_41 * * * V_101 )
{
unsigned long V_102 ;
T_10 V_103 , V_104 , V_92 ,
V_105 , V_106 ,
V_91 , V_107 , V_90 , V_108 , V_63 ,
V_109 , V_110 , V_111 , V_112 ;
T_9 V_87 , V_94 ;
T_11 V_113 ;
struct V_41 * * V_114 , * * V_115 , * * V_116 ;
struct V_117 * V_118 =
F_56 ( V_119 , V_27 ) ;
void * V_23 = V_118 ;
void * V_120 , * V_11 ;
struct V_2 * V_24 ;
struct V_75 V_121 = V_122 ;
int V_123 = 0 ;
if ( ! V_23 ) {
V_123 = - V_88 ;
goto V_124;
}
V_102 = F_21 ( V_23 , 0 , 0 ) ;
if ( V_102 ) {
V_123 = - V_125 ;
goto V_126;
}
V_113 = F_57 ( V_118 -> V_20 ) ;
V_104 = F_58 ( V_118 -> V_97 ) ;
if ( V_127 < V_104 ) {
F_59 ( L_34 , V_104 ) ;
V_123 = - V_125 ;
goto V_126;
}
V_103 = V_104 * 4096 ;
V_92 = F_8 ( V_118 -> V_92 ) ;
V_106 = F_8 ( V_118 -> V_106 ) ;
V_105 = F_8 ( V_118 -> V_105 ) ;
F_18 ( L_35 ,
( T_10 ) V_113 , V_103 ,
V_92 , V_106 , V_105 ) ;
if ( ( V_127 < V_105 )
|| ( V_127 < V_106 )
|| ( V_127 - V_106 < V_105 ) ) {
F_59 ( L_36 ,
V_106 , V_105 ) ;
V_123 = - V_125 ;
goto V_126;
}
if ( ( V_106 + V_105 ) > V_104 ) {
F_59 ( L_37 ,
V_106 ,
V_106 + V_105 ,
V_104 ) ;
V_123 = - V_125 ;
goto V_126;
}
if ( V_128 / V_129 - 1 < V_92 ) {
F_59 ( L_38 ,
V_92 ) ;
V_123 = - V_125 ;
goto V_126;
}
V_91 = V_105 * 4096 ;
V_120 = F_60 ( V_91 ) ;
if ( ! V_120 ) {
F_59 ( L_39 ) ;
V_123 = - V_88 ;
goto V_126;
}
V_11 = V_120 + V_91 ;
F_61 ( V_130 % 4096 ) ;
for ( V_63 = 0 ; V_63 < V_105 ; V_63 ++ ) {
V_102 = F_17 (
F_40 ( V_120 + V_63 * 4096 ) ,
V_113 ,
V_63 + V_106 ) ;
if ( V_102 ) {
F_59 ( L_40 ,
V_63 + V_106 ) ;
V_123 = - V_125 ;
goto V_131;
}
}
for ( V_107 = 0 , V_24 = V_120 , V_90 = 0 , V_109 = 0 ;
;
V_90 ++ , V_24 = ( void * ) V_24 + V_94 ) {
T_10 V_93 = ( void * ) V_24 - ( void * ) V_120 ;
char * V_42 ;
int V_7 ;
V_94 = F_54 ( V_24 , V_90 ,
V_91 ,
V_92 ,
V_93 , V_11 ) ;
if ( V_94 < 0 )
break;
V_42 = F_7 ( V_24 , & V_7 ) ;
if ( V_24 -> V_132 == 0 ) {
F_18 ( L_41 ,
V_90 , V_7 , V_42 ) ;
V_107 ++ ;
continue;
}
if ( ! F_6 ( V_24 -> V_1 ) ) {
F_48 ( L_42 ,
V_90 , V_7 , V_42 , V_24 -> V_1 ) ;
V_107 ++ ;
continue;
}
V_109 += F_39 ( V_24 ) ;
}
V_110 = V_90 ;
if ( V_110 != V_92 )
F_16 ( L_43 ,
V_110 , V_92 , V_107 ) ;
V_114 = F_62 ( V_109 + 1 , sizeof( * V_114 ) , V_27 ) ;
if ( ! V_114 ) {
V_123 = - V_88 ;
goto V_131;
}
V_115 = F_62 ( V_90 + 1 , sizeof( * V_115 ) ,
V_27 ) ;
if ( ! V_115 ) {
V_123 = - V_88 ;
goto V_133;
}
V_116 = F_62 ( V_90 + 1 ,
sizeof( * V_116 ) , V_27 ) ;
if ( ! V_116 ) {
V_123 = - V_88 ;
goto V_134;
}
for ( V_107 = 0 , V_108 = 0 , V_111 = 0 , V_112 = 0 ,
V_24 = V_120 , V_90 = 0 ;
V_90 < V_110 ;
V_90 ++ , V_94 = F_8 ( V_24 -> V_97 ) ,
V_24 = ( void * ) V_24 + V_94 ) {
char * V_42 ;
int V_7 ;
int V_54 ;
if ( V_24 -> V_132 == 0 )
continue;
if ( ! F_6 ( V_24 -> V_1 ) )
continue;
V_42 = F_7 ( V_24 , & V_7 ) ;
V_54 = F_47 ( & V_121 , V_42 , V_7 , V_24 -> V_1 ) ;
V_87 = F_37 ( V_90 , V_114 + V_108 ,
V_24 , V_54 ) ;
if ( V_87 <= 0 ) {
F_16 ( L_44 ,
V_90 , V_7 , V_42 ) ;
V_107 ++ ;
} else {
V_108 += V_87 ;
V_115 [ V_111 ] = F_35 ( V_24 , V_54 ) ;
if ( V_115 [ V_111 ] )
V_111 ++ ;
V_116 [ V_112 ] =
F_36 ( V_24 , V_54 ) ;
if ( V_116 [ V_112 ] )
V_112 ++ ;
}
}
F_48 ( L_45 ,
V_90 , V_108 , V_107 , V_111 ) ;
V_114 [ V_108 ] = NULL ;
V_115 [ V_111 ] = NULL ;
V_116 [ V_112 ] = NULL ;
F_52 ( & V_121 ) ;
F_63 ( V_120 ) ;
F_64 ( V_119 , V_23 ) ;
* V_99 = V_114 ;
* V_100 = V_115 ;
* V_101 = V_116 ;
return 0 ;
V_134:
F_32 ( V_115 ) ;
V_133:
F_32 ( V_114 ) ;
V_131:
F_63 ( V_120 ) ;
V_126:
F_64 ( V_119 , V_23 ) ;
V_124:
* V_99 = NULL ;
* V_100 = NULL ;
* V_101 = NULL ;
return V_123 ;
}
static T_9 F_65 ( struct V_135 * V_136 , struct V_137 * V_138 ,
struct V_139 * V_140 , char * V_37 ,
T_12 V_93 , T_10 V_141 )
{
unsigned long V_102 ;
T_9 V_123 = 0 ;
T_10 V_103 = 0 , V_104 = 0 ;
T_12 V_142 = 0 ;
T_12 F_44 ;
T_10 V_143 ;
T_13 V_113 = 0 ;
void * V_23 = F_56 ( V_119 , V_144 ) ;
struct V_117 * V_118 = V_23 ;
if ( ! V_23 )
return - V_88 ;
V_102 = F_21 ( V_23 , 0 , 0 ) ;
if ( V_102 ) {
V_123 = - V_125 ;
goto V_126;
}
V_113 = F_57 ( V_118 -> V_20 ) ;
V_104 = F_58 ( V_118 -> V_97 ) ;
V_103 = V_104 * 4096 ;
V_142 = V_93 / 4096 ;
F_44 = V_93 % 4096 ;
if ( V_142 >= V_104 )
goto V_126;
if ( V_142 != 0 ) {
V_102 = F_21 ( V_23 , V_113 ,
V_142 ) ;
if ( V_102 ) {
V_123 = - V_125 ;
goto V_126;
}
}
V_143 = 4096 - F_44 ;
if ( V_143 > V_141 )
V_143 = V_141 ;
memcpy ( V_37 , V_23 + F_44 , V_143 ) ;
V_123 = V_143 ;
V_126:
if ( V_102 )
F_59 ( L_46
L_47 ,
V_113 , V_142 , V_102 ) ;
F_64 ( V_119 , V_23 ) ;
F_18 ( L_48
L_49 , V_93 , V_142 ,
V_141 , V_103 , V_104 , V_123 ) ;
return V_123 ;
}
static void F_66 ( struct V_145 * V_146 ,
struct V_147 * V_148 ,
unsigned long V_123 )
{
struct V_149 * V_150 ;
V_150 = & V_146 -> V_151 [ 0 ] ;
F_67 ( L_50
L_51 ,
V_150 -> V_152 , V_150 -> V_153 ,
V_150 -> V_154 , V_150 -> V_155 , V_123 , V_123 ,
V_148 -> V_156 ,
V_148 -> V_157 ) ;
}
static void F_68 ( struct V_145 * V_146 ,
struct V_147 * V_148 )
{
memset ( V_146 , 0 , 4096 ) ;
memset ( V_148 , 0 , 4096 ) ;
V_146 -> V_158 = V_159 ;
}
static int F_69 ( struct V_145 * V_146 ,
struct V_147 * V_148 )
{
unsigned long V_123 ;
V_123 = F_20 ( V_160 ,
F_22 ( V_146 ) , V_161 ,
F_22 ( V_148 ) , V_161 ) ;
if ( V_123 )
F_66 ( V_146 , V_148 , V_123 ) ;
return V_123 ;
}
static int F_70 ( struct V_162 * V_24 ,
struct V_145 * V_146 )
{
T_14 V_163 ;
int V_63 ;
struct V_149 * V_150 ;
if ( V_146 -> V_164 > 254 ) {
F_18 ( L_52 ,
V_146 -> V_164 ) ;
return - V_165 ;
}
if ( F_5 ( F_71 ( V_24 ) ) )
V_163 = F_72 ( V_24 ) ;
else
V_163 = F_73 ( V_24 ) ;
V_63 = V_146 -> V_164 ++ ;
V_150 = & V_146 -> V_151 [ V_63 ] ;
V_150 -> V_152 = F_71 ( V_24 ) ;
V_150 -> V_166 = F_74 ( 8 ) ;
V_150 -> V_153 = F_75 ( F_76 ( V_24 ) ) ;
V_150 -> V_155 = F_74 ( F_77 ( V_24 ) ) ,
V_150 -> V_167 = F_74 ( 1 ) ;
V_150 -> V_154 = F_74 ( V_163 ) ;
V_150 -> V_168 = F_74 ( 1 ) ;
return 0 ;
}
static unsigned long F_78 ( struct V_162 * V_24 , T_6 * V_141 )
{
unsigned long V_123 ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
F_61 ( sizeof( * V_146 ) > 4096 ) ;
F_61 ( sizeof( * V_148 ) > 4096 ) ;
V_146 = ( void * ) F_79 ( V_169 ) ;
V_148 = ( void * ) F_79 ( V_170 ) ;
F_68 ( V_146 , V_148 ) ;
V_123 = F_70 ( V_24 , V_146 ) ;
if ( V_123 )
goto V_171;
V_123 = F_69 ( V_146 , V_148 ) ;
if ( V_123 ) {
F_66 ( V_146 , V_148 , V_123 ) ;
goto V_171;
}
* V_141 = F_57 ( V_148 -> V_172 [ 0 ] . V_173 [ 0 ] . V_174 [ 0 ] ) ;
V_171:
F_80 ( V_169 ) ;
F_80 ( V_170 ) ;
return V_123 ;
}
static int F_81 ( struct V_162 * V_24 )
{
struct V_175 V_176 ;
unsigned V_1 ;
unsigned long V_102 ;
T_6 V_87 ;
if ( V_24 -> V_36 . type != V_24 -> V_177 -> type )
return - V_178 ;
if ( F_82 ( V_24 ) ||
F_83 ( V_24 ) ||
F_84 ( V_24 ) ) {
F_18 ( L_53 ,
V_24 -> V_36 . V_179 ,
F_82 ( V_24 ) ,
V_24 -> V_36 . V_180 ,
F_83 ( V_24 ) ,
V_24 -> V_36 . V_181 ,
F_84 ( V_24 ) ) ;
return - V_165 ;
}
if ( V_24 -> V_36 . V_182 ||
V_24 -> V_36 . V_183 ||
V_24 -> V_36 . V_184 ||
V_24 -> V_36 . V_185 ||
V_24 -> V_36 . V_186 ||
V_24 -> V_36 . V_187 )
return - V_165 ;
if ( F_85 ( V_24 ) )
return - V_188 ;
if ( F_76 ( V_24 ) % 8 ) {
F_18 ( L_54 ) ;
return - V_165 ;
}
V_1 = F_71 ( V_24 ) ;
if ( V_1 > 6 ) {
F_18 ( L_55 , V_1 ) ;
return - V_165 ;
}
V_102 = F_86 ( & V_176 ) ;
if ( V_102 ) {
F_18 ( L_56 , V_102 ) ;
return - V_125 ;
}
if ( ! V_176 . V_189 && ( F_5 ( V_1 ) ||
( F_77 ( V_24 ) != F_87 () ) ) ) {
F_18 ( L_57 ,
F_5 ( V_1 ) ,
F_77 ( V_24 ) ) ;
return - V_190 ;
}
if ( F_78 ( V_24 , & V_87 ) ) {
F_18 ( L_58 ) ;
return - V_125 ;
}
return 0 ;
}
static T_6 F_88 ( struct V_162 * V_24 )
{
unsigned long V_123 ;
T_6 V_87 ;
V_123 = F_78 ( V_24 , & V_87 ) ;
if ( V_123 )
return 0 ;
return V_87 ;
}
static void F_89 ( struct V_162 * V_24 , T_6 V_191 )
{
T_15 V_192 ;
V_192 = F_90 ( & V_24 -> V_193 . V_194 , V_191 ) ;
F_91 ( V_191 - V_192 , & V_24 -> V_141 ) ;
}
static void F_92 ( struct V_162 * V_24 )
{
T_6 V_191 ;
struct V_145 * V_146 ;
struct V_195 * V_196 ;
int V_197 ;
V_197 = F_93 ( V_198 ) ;
if ( V_197 & V_199 ) {
int V_63 ;
int V_123 ;
if ( F_93 ( V_200 ) )
return;
V_146 = ( void * ) F_79 ( V_169 ) ;
V_123 = F_70 ( V_24 , V_146 ) ;
if ( V_123 ) {
F_94 ( V_200 , V_123 ) ;
} else {
V_63 = V_146 -> V_164 - 1 ;
V_196 = & F_79 ( V_195 ) ;
V_196 -> V_114 [ V_63 ] = V_24 ;
F_80 ( V_196 ) ;
}
F_80 ( V_169 ) ;
} else {
V_191 = F_88 ( V_24 ) ;
F_89 ( V_24 , V_191 ) ;
}
}
static void F_95 ( struct V_162 * V_24 , int V_201 )
{
if ( V_201 & V_202 )
F_96 ( & V_24 -> V_193 . V_194 , F_88 ( V_24 ) ) ;
}
static void F_97 ( struct V_162 * V_24 , int V_201 )
{
F_92 ( V_24 ) ;
}
static int F_98 ( struct V_162 * V_24 , int V_201 )
{
if ( V_201 & V_203 )
F_95 ( V_24 , V_201 ) ;
return 0 ;
}
static void F_99 ( struct V_177 * V_177 , unsigned int V_201 )
{
struct V_145 * V_146 ;
struct V_147 * V_148 ;
F_100 ( F_93 ( V_198 ) ) ;
F_94 ( V_198 , V_201 ) ;
if ( V_201 & ~ V_199 )
return;
V_146 = ( void * ) F_79 ( V_169 ) ;
V_148 = ( void * ) F_79 ( V_170 ) ;
F_68 ( V_146 , V_148 ) ;
F_80 ( V_170 ) ;
F_80 ( V_169 ) ;
}
static void F_101 ( void )
{
F_94 ( V_198 , 0 ) ;
F_94 ( V_200 , 0 ) ;
}
static int F_102 ( struct V_177 * V_177 )
{
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_204 * V_205 ;
struct V_162 * V_24 ;
T_6 V_141 ;
int V_63 , V_123 , V_197 ;
struct V_195 * V_196 ;
V_197 = F_93 ( V_198 ) ;
F_100 ( ! V_197 ) ;
V_123 = 0 ;
if ( V_197 & ~ V_199 )
goto V_171;
V_123 = F_93 ( V_200 ) ;
if ( V_123 )
goto V_171;
V_146 = ( void * ) F_79 ( V_169 ) ;
V_148 = ( void * ) F_79 ( V_170 ) ;
V_123 = F_69 ( V_146 , V_148 ) ;
if ( V_123 ) {
F_66 ( V_146 , V_148 , V_123 ) ;
goto V_206;
}
V_196 = & F_79 ( V_195 ) ;
for ( V_63 = 0 ; V_63 < V_146 -> V_164 ; V_63 ++ ) {
V_205 = & V_148 -> V_172 [ V_63 ] ;
V_141 = F_57 ( V_205 -> V_173 [ 0 ] . V_174 [ 0 ] ) ;
V_24 = V_196 -> V_114 [ V_63 ] ;
V_196 -> V_114 [ V_63 ] = NULL ;
F_89 ( V_24 , V_141 ) ;
}
F_80 ( V_195 ) ;
V_206:
F_80 ( V_170 ) ;
F_80 ( V_169 ) ;
V_171:
F_101 () ;
return V_123 ;
}
static void F_103 ( struct V_177 * V_177 )
{
F_100 ( ! F_93 ( V_198 ) ) ;
F_101 () ;
}
static int F_104 ( void )
{
int V_74 ;
unsigned long V_102 ;
struct V_175 V_176 ;
if ( ! F_105 ( V_207 ) ) {
F_14 ( L_59 ) ;
return - V_208 ;
}
V_102 = F_86 ( & V_176 ) ;
if ( V_102 ) {
F_14 ( L_60 ,
V_102 ) ;
return - V_208 ;
}
V_119 = F_106 ( L_61 , 4096 , 4096 , 0 , NULL ) ;
if ( ! V_119 )
return - V_88 ;
V_209 . V_210 |= V_211 ;
V_74 = F_55 ( & V_212 . V_62 ,
& V_213 . V_62 ,
& V_214 . V_62 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_107 ( & V_209 , V_209 . V_42 , - 1 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
