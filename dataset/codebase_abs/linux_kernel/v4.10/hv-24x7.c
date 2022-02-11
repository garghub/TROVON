static bool F_1 ( unsigned V_1 )
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
static bool F_3 ( unsigned V_1 )
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
static const char * F_4 ( unsigned V_1 )
{
if ( ! F_1 ( V_1 ) )
return NULL ;
switch ( V_1 ) {
case V_2 : return L_1 ;
case V_3 : return L_2 ;
case V_4 : return L_3 ;
case V_5 : return L_4 ;
case V_6 : return L_5 ;
case V_7 : return L_6 ;
}
F_5 ( V_1 ) ;
return NULL ;
}
static bool F_6 ( unsigned V_1 )
{
return F_3 ( V_1 ) ;
}
static char * F_7 ( struct V_8 * V_9 , int * V_10 )
{
* V_10 = F_8 ( V_9 -> V_11 ) - 2 ;
return ( char * ) V_9 -> V_12 ;
}
static char * F_9 ( struct V_8 * V_9 , int * V_10 )
{
unsigned V_13 = F_8 ( V_9 -> V_11 ) ;
T_5 * V_14 = ( T_5 * ) ( V_9 -> V_12 + V_13 - 2 ) ;
* V_10 = F_8 ( * V_14 ) - 2 ;
return ( char * ) V_9 -> V_12 + V_13 ;
}
static char * F_10 ( struct V_8 * V_9 , int * V_10 )
{
unsigned V_13 = F_8 ( V_9 -> V_11 ) ;
T_5 * V_15 = ( T_5 * ) ( V_9 -> V_12 + V_13 - 2 ) ;
unsigned V_14 = F_8 ( * V_15 ) ;
T_5 * V_16 = ( T_5 * ) ( V_9 -> V_12 + V_13 + V_14 - 2 ) ;
* V_10 = F_8 ( * V_16 ) - 2 ;
return ( char * ) V_9 -> V_12 + V_13 + V_14 ;
}
static bool F_11 ( struct V_8 * V_9 ,
void * V_17 )
{
void * V_18 = V_9 ;
return ( V_18 + F_12 ( struct V_8 , V_12 ) ) < V_17 ;
}
static void * F_13 ( struct V_8 * V_9 , void * V_17 )
{
void * V_18 = V_9 ;
T_5 * V_19 , * V_20 ;
unsigned V_21 , V_22 ;
unsigned V_13 = F_8 ( V_9 -> V_11 ) ;
if ( V_13 < 2 ) {
F_14 ( L_7 , V_23 , V_13 ) ;
return NULL ;
}
if ( V_18 + V_13 > V_17 ) {
F_14 ( L_8 ,
V_23 , V_18 , V_13 , V_17 ) ;
return NULL ;
}
V_19 = ( T_5 * ) ( V_9 -> V_12 + V_13 - 2 ) ;
if ( ! F_15 ( ( V_24 ) V_19 , 2 ) )
F_16 ( L_9 , V_19 ) ;
V_21 = F_8 ( * V_19 ) ;
if ( V_21 < 2 ) {
F_14 ( L_10 , V_23 , V_21 ) ;
return NULL ;
}
if ( V_18 + V_13 + V_21 > V_17 ) {
F_14 ( L_11 ,
V_23 , V_18 , V_13 , V_21 , V_18 + V_13 + V_21 , V_17 ) ;
return NULL ;
}
V_20 = ( T_5 * ) ( V_9 -> V_12 + V_13 + V_21 - 2 ) ;
if ( ! F_15 ( ( V_24 ) V_20 , 2 ) )
F_16 ( L_12 , V_20 ) ;
V_22 = F_8 ( * V_20 ) ;
if ( V_22 < 2 ) {
F_14 ( L_13 ,
V_23 , V_22 ) ;
return NULL ;
}
if ( V_18 + V_13 + V_21 + V_22 > V_17 ) {
F_14 ( L_14 ,
V_23 , V_18 , V_13 , V_21 , V_22 , V_17 ) ;
return NULL ;
}
return V_18 + V_13 + V_21 + V_22 ;
}
static unsigned long F_17 ( unsigned long V_25 ,
unsigned long V_26 ,
unsigned long V_27 )
{
F_18 ( L_15 ,
V_25 , V_26 , V_27 ) ;
F_19 ( ! F_15 ( V_25 , 4096 ) ) ;
return F_20 ( V_28 ,
V_25 , V_26 , V_27 ) ;
}
static unsigned long F_21 ( char V_29 [] ,
T_6 V_26 , T_7 V_27 )
{
return F_17 ( F_22 ( V_29 ) ,
V_26 , V_27 ) ;
}
static char * F_23 ( struct V_8 * V_30 , unsigned V_1 )
{
const char * V_31 ;
const char * V_32 ;
const char * V_33 ;
char V_34 [ 8 ] ;
switch ( V_1 ) {
case V_2 :
snprintf ( V_34 , sizeof( V_34 ) , L_16 , V_1 ) ;
V_33 = V_34 ;
V_32 = L_17 ;
V_31 = L_18 ;
break;
case V_3 :
V_33 = L_19 ;
V_32 = L_17 ;
V_31 = L_20 ;
break;
default:
V_33 = L_19 ;
V_32 = L_19 ;
V_31 = L_21 ;
}
return F_24 ( V_35 ,
L_22 ,
V_33 ,
F_8 ( V_30 -> V_36 ) +
F_8 ( V_30 -> V_37 ) ,
V_31 ,
V_32 ) ;
}
static char * F_25 ( char * V_38 , int V_39 , T_8 V_40 )
{
return F_24 ( V_40 , L_23 , V_39 , V_38 ) ;
}
static T_9 F_26 ( struct V_41 * V_42 ,
struct V_43 * V_44 , char * V_34 )
{
struct V_45 * V_46 ;
V_46 = F_27 ( V_44 , struct V_45 , V_44 ) ;
return sprintf ( V_34 , L_24 , ( char * ) V_46 -> V_47 ) ;
}
static struct V_48 * F_28 ( char * V_49 , char * V_50 )
{
struct V_45 * V_44 = F_29 ( sizeof( * V_44 ) , V_35 ) ;
if ( ! V_44 )
return NULL ;
F_30 ( & V_44 -> V_44 . V_44 ) ;
V_44 -> V_47 = V_50 ;
V_44 -> V_44 . V_44 . V_49 = V_49 ;
V_44 -> V_44 . V_44 . V_51 = 0444 ;
V_44 -> V_44 . V_52 = F_26 ;
return & V_44 -> V_44 . V_44 ;
}
static struct V_48 * F_31 ( char * V_49 , int V_53 ,
int V_54 ,
char * V_50 , T_10 V_55 )
{
char * T_1 ;
char * V_56 = F_25 ( V_50 , V_55 , V_35 ) ;
struct V_48 * V_57 ;
if ( ! V_56 )
return NULL ;
if ( ! V_54 )
T_1 = F_24 ( V_35 , L_23 , V_53 , V_49 ) ;
else
T_1 = F_24 ( V_35 , L_25 , V_53 , V_49 ,
V_54 ) ;
if ( ! T_1 )
goto V_58;
V_57 = F_28 ( T_1 , V_56 ) ;
if ( ! V_57 )
goto V_59;
return V_57 ;
V_59:
F_32 ( T_1 ) ;
V_58:
F_32 ( V_56 ) ;
return NULL ;
}
static struct V_48 * F_33 ( unsigned V_60 ,
struct V_8 * V_30 ,
unsigned V_1 ,
int V_61 )
{
int V_11 ;
char * V_62 , * V_63 , * V_64 ;
struct V_48 * V_44 ;
if ( ! F_1 ( V_1 ) ) {
F_16 ( L_26 ,
V_60 , V_1 ) ;
return NULL ;
}
V_64 = F_23 ( V_30 , V_1 ) ;
if ( ! V_64 )
return NULL ;
V_62 = F_7 ( V_30 , & V_11 ) ;
if ( ! V_61 )
V_63 = F_24 ( V_35 , L_23 ,
( int ) V_11 , V_62 ) ;
else
V_63 = F_24 ( V_35 , L_25 ,
( int ) V_11 , V_62 , V_61 ) ;
if ( ! V_63 )
goto V_65;
V_44 = F_28 ( V_63 , V_64 ) ;
if ( ! V_44 )
goto V_66;
return V_44 ;
V_66:
F_32 ( V_63 ) ;
V_65:
F_32 ( V_64 ) ;
return NULL ;
}
static struct V_48 * F_34 ( struct V_8 * V_30 ,
int V_61 )
{
int V_13 , V_21 ;
char * V_49 = F_7 ( V_30 , & V_13 ) ;
char * V_67 = F_9 ( V_30 , & V_21 ) ;
if ( ! V_21 )
return NULL ;
return F_31 ( V_49 , V_13 , V_61 , V_67 , V_21 ) ;
}
static struct V_48 *
F_35 ( struct V_8 * V_30 , int V_61 )
{
int V_13 , V_21 ;
char * V_49 = F_7 ( V_30 , & V_13 ) ;
char * V_67 = F_10 ( V_30 , & V_21 ) ;
if ( ! V_21 )
return NULL ;
return F_31 ( V_49 , V_13 , V_61 , V_67 , V_21 ) ;
}
static int F_36 ( unsigned V_60 , struct V_48 * * V_68 ,
struct V_8 * V_30 , int V_61 )
{
* V_68 = F_33 ( V_60 , V_30 , V_30 -> V_1 , V_61 ) ;
if ( ! * V_68 )
return - 1 ;
return 0 ;
}
static int F_37 ( const void * V_69 , T_10 V_70 , const void * V_71 , T_10 V_72 )
{
if ( V_70 < V_72 )
return 1 ;
if ( V_72 > V_70 )
return - 1 ;
return memcmp ( V_69 , V_71 , V_70 ) ;
}
static int F_38 ( const void * V_73 , T_10 V_70 , unsigned V_69 , const void * V_74 ,
T_10 V_72 , unsigned V_71 )
{
int V_75 = F_37 ( V_73 , V_70 , V_74 , V_72 ) ;
if ( V_75 )
return V_75 ;
if ( V_69 > V_71 )
return 1 ;
if ( V_71 > V_69 )
return - 1 ;
return 0 ;
}
static int F_39 ( struct V_76 * V_77 , const char * V_49 , int V_13 ,
unsigned V_1 )
{
struct V_78 * * V_79 = & ( V_77 -> V_78 ) , * V_80 = NULL ;
struct V_81 * V_82 ;
while ( * V_79 ) {
struct V_81 * V_83 ;
int V_84 ;
V_83 = F_27 ( * V_79 , struct V_81 , V_85 ) ;
V_84 = F_38 ( V_49 , V_13 , V_1 , V_83 -> V_49 , V_83 -> V_13 ,
V_83 -> V_1 ) ;
V_80 = * V_79 ;
if ( V_84 < 0 )
V_79 = & ( ( * V_79 ) -> V_86 ) ;
else if ( V_84 > 0 )
V_79 = & ( ( * V_79 ) -> V_87 ) ;
else {
V_83 -> V_88 ++ ;
F_40 ( L_27 , V_13 ,
V_49 , V_83 -> V_88 ) ;
return V_83 -> V_88 ;
}
}
V_82 = F_41 ( sizeof( * V_82 ) , V_35 ) ;
if ( ! V_82 )
return - V_89 ;
* V_82 = (struct V_81 ) {
. V_49 = V_49 ,
. V_13 = V_13 ,
. V_88 = 0 ,
. V_1 = V_1 ,
} ;
F_42 ( & V_82 -> V_85 , V_80 , V_79 ) ;
F_43 ( & V_82 -> V_85 , V_77 ) ;
return 0 ;
}
static void F_44 ( struct V_76 * V_77 )
{
struct V_81 * V_90 , * T_1 ;
F_45 (pos, n, root, node)
F_32 ( V_90 ) ;
}
static T_9 F_46 ( struct V_8 * V_30 ,
T_10 V_91 ,
T_10 V_92 ,
T_10 V_93 ,
T_10 V_94 , void * V_17 )
{
T_9 V_95 ;
void * V_96 , * V_97 ;
if ( V_94 >= V_92 )
return - 1 ;
if ( V_91 >= V_93 ) {
F_18 ( L_28 ,
V_92 - V_94 ) ;
return - 1 ;
}
if ( ! F_11 ( V_30 , V_17 ) ) {
F_16 ( L_29 ,
V_91 ) ;
return - 1 ;
}
V_95 = F_8 ( V_30 -> V_98 ) ;
if ( V_95 % 16 )
F_40 ( L_30 ,
V_91 , V_95 , V_30 ) ;
V_96 = ( V_99 * ) V_30 + V_95 ;
if ( V_96 > V_17 ) {
F_16 ( L_31 ,
V_91 , V_95 , V_96 , V_17 ,
V_94 ) ;
return - 1 ;
}
V_97 = F_13 ( V_30 , V_17 ) ;
if ( ! V_97 ) {
F_16 ( L_32 ,
V_91 , V_92 , V_30 , V_17 ,
V_94 ) ;
return - 1 ;
}
if ( V_97 > V_96 ) {
F_16 ( L_33 ,
V_91 , V_30 , V_96 , V_94 , V_97 ) ;
return - 1 ;
}
return V_95 ;
}
static int F_47 ( struct V_48 * * * V_100 ,
struct V_48 * * * V_101 ,
struct V_48 * * * V_102 )
{
unsigned long V_103 ;
T_10 V_104 , V_105 , V_93 ,
V_106 , V_107 ,
V_92 , V_108 , V_91 , V_109 , V_110 ,
V_111 , V_112 , V_113 , V_114 ;
T_9 V_88 , V_95 ;
T_11 V_115 ;
struct V_48 * * V_116 , * * V_117 , * * V_118 ;
struct V_119 * V_120 =
F_48 ( V_121 , V_35 ) ;
void * V_29 = V_120 ;
void * V_122 , * V_17 ;
struct V_8 * V_30 ;
struct V_76 V_123 = V_124 ;
int V_125 = 0 ;
if ( ! V_29 ) {
V_125 = - V_89 ;
goto V_126;
}
V_103 = F_21 ( V_29 , 0 , 0 ) ;
if ( V_103 ) {
V_125 = - V_127 ;
goto V_128;
}
V_115 = F_49 ( V_120 -> V_26 ) ;
V_105 = F_50 ( V_120 -> V_98 ) ;
if ( V_129 < V_105 ) {
F_51 ( L_34 , V_105 ) ;
V_125 = - V_127 ;
goto V_128;
}
V_104 = V_105 * 4096 ;
V_93 = F_8 ( V_120 -> V_93 ) ;
V_107 = F_8 ( V_120 -> V_107 ) ;
V_106 = F_8 ( V_120 -> V_106 ) ;
F_18 ( L_35 ,
( T_10 ) V_115 , V_104 ,
V_93 , V_107 , V_106 ) ;
if ( ( V_129 < V_106 )
|| ( V_129 < V_107 )
|| ( V_129 - V_107 < V_106 ) ) {
F_51 ( L_36 ,
V_107 , V_106 ) ;
V_125 = - V_127 ;
goto V_128;
}
if ( ( V_107 + V_106 ) > V_105 ) {
F_51 ( L_37 ,
V_107 ,
V_107 + V_106 ,
V_105 ) ;
V_125 = - V_127 ;
goto V_128;
}
if ( V_130 - 1 < V_93 ) {
F_51 ( L_38 , V_93 ) ;
V_125 = - V_127 ;
goto V_128;
}
V_92 = V_106 * 4096 ;
V_122 = F_52 ( V_92 ) ;
if ( ! V_122 ) {
F_51 ( L_39 ) ;
V_125 = - V_89 ;
goto V_128;
}
V_17 = V_122 + V_92 ;
F_53 ( V_131 % 4096 ) ;
for ( V_110 = 0 ; V_110 < V_106 ; V_110 ++ ) {
V_103 = F_17 (
F_54 ( V_122 + V_110 * 4096 ) ,
V_115 ,
V_110 + V_107 ) ;
if ( V_103 ) {
F_51 ( L_40 ,
V_110 + V_107 ) ;
V_125 = - V_127 ;
goto V_132;
}
}
for ( V_108 = 0 , V_30 = V_122 , V_91 = 0 , V_111 = 0 ;
;
V_91 ++ , V_30 = ( void * ) V_30 + V_95 ) {
T_10 V_94 = ( void * ) V_30 - ( void * ) V_122 ;
char * V_49 ;
int V_13 ;
V_95 = F_46 ( V_30 , V_91 ,
V_92 ,
V_93 ,
V_94 , V_17 ) ;
if ( V_95 < 0 )
break;
V_49 = F_7 ( V_30 , & V_13 ) ;
if ( V_30 -> V_133 == 0 ) {
F_18 ( L_41 ,
V_91 , V_13 , V_49 ) ;
V_108 ++ ;
continue;
}
if ( ! F_6 ( V_30 -> V_1 ) ) {
F_40 ( L_42 ,
V_91 , V_13 , V_49 , V_30 -> V_1 ) ;
V_108 ++ ;
continue;
}
V_111 ++ ;
}
V_112 = V_91 ;
if ( V_112 != V_93 )
F_16 ( L_43 ,
V_112 , V_93 , V_108 ) ;
V_116 = F_55 ( V_111 + 1 , sizeof( * V_116 ) , V_35 ) ;
if ( ! V_116 ) {
V_125 = - V_89 ;
goto V_132;
}
V_117 = F_55 ( V_91 + 1 , sizeof( * V_117 ) ,
V_35 ) ;
if ( ! V_117 ) {
V_125 = - V_89 ;
goto V_134;
}
V_118 = F_55 ( V_91 + 1 ,
sizeof( * V_118 ) , V_35 ) ;
if ( ! V_118 ) {
V_125 = - V_89 ;
goto V_135;
}
for ( V_108 = 0 , V_109 = 0 , V_113 = 0 , V_114 = 0 ,
V_30 = V_122 , V_91 = 0 ;
V_91 < V_112 ;
V_91 ++ , V_95 = F_8 ( V_30 -> V_98 ) ,
V_30 = ( void * ) V_30 + V_95 ) {
char * V_49 ;
int V_13 ;
int V_61 ;
if ( V_30 -> V_133 == 0 )
continue;
if ( ! F_6 ( V_30 -> V_1 ) )
continue;
V_49 = F_7 ( V_30 , & V_13 ) ;
V_61 = F_39 ( & V_123 , V_49 , V_13 , V_30 -> V_1 ) ;
V_88 = F_36 ( V_91 , V_116 + V_109 ,
V_30 , V_61 ) ;
if ( V_88 < 0 ) {
F_16 ( L_44 ,
V_91 , V_13 , V_49 ) ;
V_108 ++ ;
} else {
V_109 ++ ;
V_117 [ V_113 ] = F_34 ( V_30 , V_61 ) ;
if ( V_117 [ V_113 ] )
V_113 ++ ;
V_118 [ V_114 ] =
F_35 ( V_30 , V_61 ) ;
if ( V_118 [ V_114 ] )
V_114 ++ ;
}
}
F_40 ( L_45 ,
V_91 , V_109 , V_108 , V_113 ) ;
V_116 [ V_109 ] = NULL ;
V_117 [ V_113 ] = NULL ;
V_118 [ V_114 ] = NULL ;
F_44 ( & V_123 ) ;
F_56 ( V_122 ) ;
F_57 ( V_121 , V_29 ) ;
* V_100 = V_116 ;
* V_101 = V_117 ;
* V_102 = V_118 ;
return 0 ;
V_135:
F_32 ( V_117 ) ;
V_134:
F_32 ( V_116 ) ;
V_132:
F_56 ( V_122 ) ;
V_128:
F_57 ( V_121 , V_29 ) ;
V_126:
* V_100 = NULL ;
* V_101 = NULL ;
* V_102 = NULL ;
return V_125 ;
}
static T_9 F_58 ( struct V_136 * V_137 , struct V_138 * V_139 ,
struct V_140 * V_141 , char * V_34 ,
T_12 V_94 , T_10 V_142 )
{
unsigned long V_103 ;
T_9 V_125 = 0 ;
T_10 V_104 = 0 , V_105 = 0 ;
T_12 V_143 = 0 ;
T_12 V_144 ;
T_10 V_145 ;
T_13 V_115 = 0 ;
void * V_29 = F_48 ( V_121 , V_146 ) ;
struct V_119 * V_120 = V_29 ;
if ( ! V_29 )
return - V_89 ;
V_103 = F_21 ( V_29 , 0 , 0 ) ;
if ( V_103 ) {
V_125 = - V_127 ;
goto V_128;
}
V_115 = F_49 ( V_120 -> V_26 ) ;
V_105 = F_50 ( V_120 -> V_98 ) ;
V_104 = V_105 * 4096 ;
V_143 = V_94 / 4096 ;
V_144 = V_94 % 4096 ;
if ( V_143 >= V_105 )
goto V_128;
if ( V_143 != 0 ) {
V_103 = F_21 ( V_29 , V_115 ,
V_143 ) ;
if ( V_103 ) {
V_125 = - V_127 ;
goto V_128;
}
}
V_145 = 4096 - V_144 ;
if ( V_145 > V_142 )
V_145 = V_142 ;
memcpy ( V_34 , V_29 + V_144 , V_145 ) ;
V_125 = V_145 ;
V_128:
if ( V_103 )
F_51 ( L_46
L_47 ,
V_115 , V_143 , V_103 ) ;
F_57 ( V_121 , V_29 ) ;
F_18 ( L_48
L_49 , V_94 , V_143 ,
V_142 , V_104 , V_105 , V_125 ) ;
return V_125 ;
}
static T_9 F_59 ( struct V_41 * V_42 , struct V_43 * V_44 ,
char * V_29 )
{
int V_46 , T_1 , V_142 = 0 ;
const char * V_50 ;
for ( V_46 = 0 ; V_46 < V_147 ; V_46 ++ ) {
V_50 = F_4 ( V_46 ) ;
if ( ! V_50 )
continue;
T_1 = sprintf ( V_29 , L_50 , V_46 , V_50 ) ;
if ( T_1 < 0 )
break;
V_142 += T_1 ;
V_29 += T_1 ;
}
return V_142 ;
}
static void F_60 ( struct V_148 * V_149 ,
struct V_150 * V_151 ,
unsigned long V_125 )
{
struct V_152 * V_153 ;
V_153 = & V_149 -> V_154 [ 0 ] ;
F_61 ( L_51
L_52 ,
V_153 -> V_155 , V_153 -> V_156 ,
V_153 -> V_157 , V_153 -> V_158 , V_125 , V_125 ,
V_151 -> V_159 ,
V_151 -> V_160 ) ;
}
static void F_62 ( struct V_148 * V_149 ,
struct V_150 * V_151 )
{
memset ( V_149 , 0 , 4096 ) ;
memset ( V_151 , 0 , 4096 ) ;
V_149 -> V_161 = V_162 ;
}
static int F_63 ( struct V_148 * V_149 ,
struct V_150 * V_151 )
{
unsigned long V_125 ;
V_125 = F_20 ( V_163 ,
F_22 ( V_149 ) , V_164 ,
F_22 ( V_151 ) , V_164 ) ;
if ( V_125 )
F_60 ( V_149 , V_151 , V_125 ) ;
return V_125 ;
}
static int F_64 ( struct V_165 * V_30 ,
struct V_148 * V_149 )
{
T_14 V_166 ;
int V_110 ;
struct V_152 * V_153 ;
if ( V_149 -> V_167 > 254 ) {
F_18 ( L_53 ,
V_149 -> V_167 ) ;
return - V_168 ;
}
switch ( F_65 ( V_30 ) ) {
case V_2 :
V_166 = F_66 ( V_30 ) ;
break;
case V_3 :
V_166 = F_67 ( V_30 ) ;
break;
default:
V_166 = F_68 ( V_30 ) ;
}
V_110 = V_149 -> V_167 ++ ;
V_153 = & V_149 -> V_154 [ V_110 ] ;
V_153 -> V_155 = F_65 ( V_30 ) ;
V_153 -> V_169 = F_69 ( 8 ) ;
V_153 -> V_156 = F_70 ( F_71 ( V_30 ) ) ;
V_153 -> V_158 = F_69 ( F_72 ( V_30 ) ) ,
V_153 -> V_170 = F_69 ( 1 ) ;
V_153 -> V_157 = F_69 ( V_166 ) ;
V_153 -> V_171 = F_69 ( 1 ) ;
return 0 ;
}
static unsigned long F_73 ( struct V_165 * V_30 , T_6 * V_142 )
{
unsigned long V_125 ;
struct V_148 * V_149 ;
struct V_150 * V_151 ;
F_53 ( sizeof( * V_149 ) > 4096 ) ;
F_53 ( sizeof( * V_151 ) > 4096 ) ;
V_149 = ( void * ) F_74 ( V_172 ) ;
V_151 = ( void * ) F_74 ( V_173 ) ;
F_62 ( V_149 , V_151 ) ;
V_125 = F_64 ( V_30 , V_149 ) ;
if ( V_125 )
goto V_174;
V_125 = F_63 ( V_149 , V_151 ) ;
if ( V_125 ) {
F_60 ( V_149 , V_151 , V_125 ) ;
goto V_174;
}
* V_142 = F_49 ( V_151 -> V_175 [ 0 ] . V_176 [ 0 ] . V_177 [ 0 ] ) ;
V_174:
F_75 ( V_172 ) ;
F_75 ( V_173 ) ;
return V_125 ;
}
static int F_76 ( struct V_165 * V_30 )
{
struct V_178 V_179 ;
unsigned V_1 ;
unsigned long V_103 ;
T_6 V_88 ;
if ( V_30 -> V_44 . type != V_30 -> V_180 -> type )
return - V_181 ;
if ( F_77 ( V_30 ) ||
F_78 ( V_30 ) ||
F_79 ( V_30 ) ) {
F_18 ( L_54 ,
V_30 -> V_44 . V_182 ,
F_77 ( V_30 ) ,
V_30 -> V_44 . V_183 ,
F_78 ( V_30 ) ,
V_30 -> V_44 . V_184 ,
F_79 ( V_30 ) ) ;
return - V_168 ;
}
if ( V_30 -> V_44 . V_185 ||
V_30 -> V_44 . V_186 ||
V_30 -> V_44 . V_187 ||
V_30 -> V_44 . V_188 ||
V_30 -> V_44 . V_189 ||
V_30 -> V_44 . V_190 )
return - V_168 ;
if ( F_80 ( V_30 ) )
return - V_191 ;
if ( F_71 ( V_30 ) % 8 ) {
F_18 ( L_55 ) ;
return - V_168 ;
}
V_1 = F_65 ( V_30 ) ;
if ( V_1 > 6 ) {
F_18 ( L_56 , V_1 ) ;
return - V_168 ;
}
V_103 = F_81 ( & V_179 ) ;
if ( V_103 ) {
F_18 ( L_57 , V_103 ) ;
return - V_127 ;
}
if ( ! V_179 . V_192 && ( F_3 ( V_1 ) ||
( F_72 ( V_30 ) != F_82 () ) ) ) {
F_18 ( L_58 ,
F_3 ( V_1 ) ,
F_72 ( V_30 ) ) ;
return - V_193 ;
}
if ( F_73 ( V_30 , & V_88 ) ) {
F_18 ( L_59 ) ;
return - V_127 ;
}
( void ) F_83 ( & V_30 -> V_194 . V_195 , V_88 ) ;
return 0 ;
}
static T_6 F_84 ( struct V_165 * V_30 )
{
unsigned long V_125 ;
T_6 V_88 ;
V_125 = F_73 ( V_30 , & V_88 ) ;
if ( V_125 )
return 0 ;
return V_88 ;
}
static void F_85 ( struct V_165 * V_30 , T_6 V_196 )
{
T_15 V_197 ;
V_197 = F_83 ( & V_30 -> V_194 . V_195 , V_196 ) ;
F_86 ( V_196 - V_197 , & V_30 -> V_142 ) ;
}
static void F_87 ( struct V_165 * V_30 )
{
T_6 V_196 ;
struct V_148 * V_149 ;
struct V_198 * V_199 ;
int V_200 ;
V_200 = F_88 ( V_201 ) ;
if ( V_200 & V_202 ) {
int V_110 ;
int V_125 ;
if ( F_88 ( V_203 ) )
return;
V_149 = ( void * ) F_74 ( V_172 ) ;
V_125 = F_64 ( V_30 , V_149 ) ;
if ( V_125 ) {
F_89 ( V_203 , V_125 ) ;
} else {
V_110 = V_149 -> V_167 - 1 ;
V_199 = & F_74 ( V_198 ) ;
V_199 -> V_116 [ V_110 ] = V_30 ;
F_75 ( V_199 ) ;
F_90 ( & V_30 -> V_142 , 0 ) ;
}
F_75 ( V_172 ) ;
} else {
V_196 = F_84 ( V_30 ) ;
F_85 ( V_30 , V_196 ) ;
}
}
static void F_91 ( struct V_165 * V_30 , int V_204 )
{
if ( V_204 & V_205 )
F_90 ( & V_30 -> V_194 . V_195 , F_84 ( V_30 ) ) ;
}
static void F_92 ( struct V_165 * V_30 , int V_204 )
{
F_87 ( V_30 ) ;
}
static int F_93 ( struct V_165 * V_30 , int V_204 )
{
if ( V_204 & V_206 )
F_91 ( V_30 , V_204 ) ;
return 0 ;
}
static void F_94 ( struct V_180 * V_180 , unsigned int V_204 )
{
struct V_148 * V_149 ;
struct V_150 * V_151 ;
F_5 ( F_88 ( V_201 ) ) ;
F_89 ( V_201 , V_204 ) ;
if ( V_204 & ~ V_202 )
return;
V_149 = ( void * ) F_74 ( V_172 ) ;
V_151 = ( void * ) F_74 ( V_173 ) ;
F_62 ( V_149 , V_151 ) ;
F_75 ( V_173 ) ;
F_75 ( V_172 ) ;
}
static void F_95 ( void )
{
F_89 ( V_201 , 0 ) ;
F_89 ( V_203 , 0 ) ;
}
static int F_96 ( struct V_180 * V_180 )
{
struct V_148 * V_149 ;
struct V_150 * V_151 ;
struct V_207 * V_208 ;
struct V_165 * V_30 ;
T_6 V_142 ;
int V_110 , V_125 , V_200 ;
struct V_198 * V_199 ;
V_200 = F_88 ( V_201 ) ;
F_5 ( ! V_200 ) ;
V_125 = 0 ;
if ( V_200 & ~ V_202 )
goto V_174;
V_125 = F_88 ( V_203 ) ;
if ( V_125 )
goto V_174;
V_149 = ( void * ) F_74 ( V_172 ) ;
V_151 = ( void * ) F_74 ( V_173 ) ;
V_125 = F_63 ( V_149 , V_151 ) ;
if ( V_125 ) {
F_60 ( V_149 , V_151 , V_125 ) ;
goto V_209;
}
V_199 = & F_74 ( V_198 ) ;
for ( V_110 = 0 ; V_110 < V_149 -> V_167 ; V_110 ++ ) {
V_208 = & V_151 -> V_175 [ V_110 ] ;
V_142 = F_49 ( V_208 -> V_176 [ 0 ] . V_177 [ 0 ] ) ;
V_30 = V_199 -> V_116 [ V_110 ] ;
V_199 -> V_116 [ V_110 ] = NULL ;
F_85 ( V_30 , V_142 ) ;
}
F_75 ( V_198 ) ;
V_209:
F_75 ( V_173 ) ;
F_75 ( V_172 ) ;
V_174:
F_95 () ;
return V_125 ;
}
static void F_97 ( struct V_180 * V_180 )
{
F_5 ( ! F_88 ( V_201 ) ) ;
F_95 () ;
}
static int F_98 ( void )
{
int V_75 ;
unsigned long V_103 ;
struct V_178 V_179 ;
if ( ! F_99 ( V_210 ) ) {
F_14 ( L_60 ) ;
return - V_211 ;
}
V_103 = F_81 ( & V_179 ) ;
if ( V_103 ) {
F_14 ( L_61 ,
V_103 ) ;
return - V_211 ;
}
V_121 = F_100 ( L_62 , 4096 , 4096 , 0 , NULL ) ;
if ( ! V_121 )
return - V_89 ;
V_212 . V_213 |= V_214 ;
V_75 = F_47 ( & V_215 . V_68 ,
& V_216 . V_68 ,
& V_217 . V_68 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_101 ( & V_212 , V_212 . V_49 , - 1 ) ;
if ( V_75 )
return V_75 ;
return 0 ;
}
